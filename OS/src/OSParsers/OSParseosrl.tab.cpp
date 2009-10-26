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
#define YYLAST   1013

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  542
/* YYNRULES -- Number of rules.  */
#define YYNRULES  814
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1161

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
      72,    74,    76,    79,    81,    83,    85,    90,    92,    94,
      97,    99,   103,   105,   107,   110,   114,   116,   118,   119,
     122,   124,   126,   129,   131,   134,   136,   138,   140,   143,
     145,   149,   151,   154,   156,   158,   160,   163,   165,   169,
     171,   174,   176,   178,   180,   183,   185,   189,   191,   194,
     196,   198,   200,   203,   205,   209,   211,   214,   216,   218,
     220,   223,   225,   229,   231,   234,   236,   238,   240,   243,
     245,   249,   251,   254,   256,   258,   260,   263,   265,   269,
     271,   275,   277,   282,   284,   286,   289,   291,   295,   297,
     299,   302,   306,   308,   310,   311,   314,   316,   318,   320,
     323,   325,   326,   329,   331,   333,   335,   338,   340,   344,
     346,   348,   351,   353,   355,   357,   359,   361,   363,   366,
     368,   370,   372,   375,   377,   381,   383,   387,   389,   391,
     392,   395,   397,   399,   403,   405,   407,   411,   413,   415,
     416,   419,   421,   423,   427,   429,   431,   435,   437,   439,
     440,   443,   445,   447,   451,   453,   455,   459,   461,   462,
     464,   468,   470,   474,   476,   481,   483,   485,   488,   490,
     494,   496,   498,   501,   505,   507,   509,   510,   513,   515,
     517,   519,   522,   524,   525,   528,   533,   534,   537,   539,
     541,   543,   545,   547,   549,   552,   554,   556,   558,   561,
     563,   567,   569,   572,   574,   576,   578,   581,   583,   587,
     589,   592,   594,   596,   598,   601,   603,   607,   609,   612,
     614,   616,   618,   621,   623,   627,   629,   632,   634,   636,
     638,   641,   643,   647,   649,   653,   655,   660,   662,   664,
     667,   669,   673,   675,   677,   680,   684,   686,   688,   689,
     692,   694,   696,   698,   701,   703,   704,   707,   712,   713,
     716,   718,   720,   722,   724,   726,   728,   730,   732,   734,
     736,   738,   741,   743,   745,   747,   750,   752,   756,   758,
     761,   763,   765,   767,   770,   772,   776,   778,   781,   783,
     785,   787,   790,   792,   796,   798,   801,   803,   805,   807,
     810,   812,   816,   818,   821,   823,   825,   827,   830,   832,
     836,   838,   842,   844,   849,   851,   853,   856,   858,   862,
     864,   866,   869,   873,   875,   876,   879,   881,   883,   885,
     887,   889,   891,   894,   896,   900,   902,   904,   906,   910,
     912,   914,   915,   918,   920,   922,   926,   928,   930,   934,
     936,   938,   939,   942,   944,   946,   950,   952,   954,   958,
     960,   962,   963,   966,   968,   970,   974,   976,   978,   982,
     984,   985,   987,   991,   993,   997,   999,  1004,  1006,  1008,
    1011,  1013,  1017,  1019,  1021,  1024,  1028,  1030,  1032,  1033,
    1036,  1038,  1040,  1042,  1045,  1047,  1048,  1052,  1054,  1056,
    1057,  1060,  1062,  1064,  1066,  1068,  1073,  1078,  1083,  1088,
    1090,  1092,  1095,  1097,  1101,  1104,  1106,  1109,  1113,  1115,
    1117,  1118,  1121,  1123,  1125,  1130,  1134,  1143,  1147,  1149,
    1151,  1153,  1156,  1158,  1160,  1162,  1167,  1169,  1171,  1174,
    1176,  1180,  1182,  1184,  1187,  1191,  1193,  1195,  1196,  1199,
    1201,  1203,  1206,  1208,  1209,  1212,  1214,  1216,  1218,  1221,
    1223,  1227,  1229,  1230,  1234,  1236,  1237,  1242,  1244,  1246,
    1248,  1252,  1257,  1258,  1262,  1264,  1269,  1271,  1273,  1276,
    1278,  1282,  1284,  1286,  1289,  1293,  1295,  1300,  1304,  1306,
    1308,  1309,  1313,  1315,  1320,  1322,  1324,  1327,  1329,  1333,
    1335,  1337,  1340,  1344,  1346,  1351,  1353,  1355,  1358,  1360,
    1364,  1366,  1367,  1371,  1373,  1378,  1380,  1382,  1385,  1387,
    1391,  1393,  1395,  1398,  1402,  1404,  1409,  1413,  1414,  1417,
    1421,  1423,  1425,  1426,  1429,  1431,  1433,  1435,  1437,  1442,
    1444,  1446,  1449,  1451,  1455,  1457,  1459,  1462,  1466,  1468,
    1473,  1475,  1477,  1480,  1482,  1486,  1488,  1489,  1493,  1495,
    1496,  1501,  1503,  1505,  1507,  1511,  1514,  1515,  1519,  1521,
    1526,  1528,  1530,  1533,  1535,  1539,  1541,  1543,  1546,  1550,
    1552,  1553,  1558,  1562,  1564,  1566,  1567,  1570,  1574,  1576,
    1578,  1579,  1582,  1584,  1586,  1588,  1590,  1595,  1597,  1599,
    1602,  1604,  1608,  1610,  1612,  1615,  1619,  1621,  1626,  1628,
    1630,  1633,  1635,  1639,  1641,  1642,  1646,  1648,  1649,  1654,
    1656,  1658,  1660,  1664,  1667,  1668,  1672,  1674,  1679,  1681,
    1683,  1686,  1688,  1692,  1694,  1696,  1699,  1705,  1707,  1712,
    1714,  1716,  1717,  1720,  1724,  1726,  1728,  1729,  1732,  1734,
    1736,  1738,  1740,  1745,  1747,  1749,  1752,  1754,  1758,  1760,
    1762,  1765,  1769,  1771,  1776,  1778,  1780,  1783,  1785,  1789,
    1791,  1792,  1796,  1798,  1803,  1805,  1807,  1810,  1812,  1816,
    1818,  1820,  1823,  1827,  1829,  1831,  1832,  1835,  1837,  1839,
    1841,  1843,  1848,  1850,  1852,  1855,  1857,  1861,  1863,  1865,
    1868,  1870,  1872,  1874,  1876,  1878,  1882,  1884,  1885,  1889,
    1891,  1896,  1898,  1900,  1903,  1905,  1909,  1911,  1913,  1916,
    1920,  1922,  1924,  1925,  1928,  1930,  1932,  1934,  1936,  1941,
    1943,  1945,  1948,  1950,  1954,  1956,  1958,  1961,  1963,  1965,
    1967,  1969,  1971,  1975,  1977,  1979,  1981,  1983,  1987,  1989,
    1991,  1993,  1995,  1999,  2001,  2003,  2005,  2007,  2011,  2013,
    2015,  2017,  2019,  2023,  2025,  2027,  2029,  2031,  2035,  2037,
    2039,  2041,  2043,  2047,  2049,  2051,  2053,  2055,  2057,  2060,
    2061,  2064,  2066,  2068,  2070
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   173,    -1,    44,    -1,    -1,
      46,    -1,    10,   174,    47,    -1,   175,   256,   310,   357,
     447,    -1,    -1,   176,   177,    -1,    48,    -1,   178,    -1,
     179,    -1,    10,    49,    -1,    11,    -1,    10,   180,    49,
      -1,   181,    -1,   182,    -1,   181,   182,    -1,   183,    -1,
     200,    -1,   206,    -1,   212,    -1,   218,    -1,   224,    -1,
     230,    -1,   236,    -1,   242,    -1,   184,   185,   189,    -1,
      88,    -1,   186,    -1,   187,    -1,   186,   187,    -1,   694,
      -1,   686,    -1,   188,    -1,    24,   708,     6,   708,    -1,
     190,    -1,   191,    -1,    10,    89,    -1,    11,    -1,    10,
     192,    89,    -1,   193,    -1,   194,    -1,   193,   194,    -1,
     195,   196,   199,    -1,   134,    -1,   197,    -1,    -1,   197,
     198,    -1,   690,    -1,   686,    -1,    10,   135,    -1,    11,
      -1,   201,   202,    -1,    96,    -1,   203,    -1,   204,    -1,
      10,    97,    -1,    11,    -1,    10,   205,    97,    -1,     4,
      -1,   207,   208,    -1,   120,    -1,   209,    -1,   210,    -1,
      10,   121,    -1,    11,    -1,    10,   211,   121,    -1,     4,
      -1,   213,   214,    -1,   118,    -1,   215,    -1,   216,    -1,
      10,   119,    -1,    11,    -1,    10,   217,   119,    -1,     4,
      -1,   219,   220,    -1,    92,    -1,   221,    -1,   222,    -1,
      10,    93,    -1,    11,    -1,    10,   223,    93,    -1,     4,
      -1,   225,   226,    -1,    94,    -1,   227,    -1,   228,    -1,
      10,    95,    -1,    11,    -1,    10,   229,    95,    -1,     4,
      -1,   231,   232,    -1,   126,    -1,   233,    -1,   234,    -1,
      10,   127,    -1,    11,    -1,    10,   235,   127,    -1,     4,
      -1,   237,   238,    -1,   142,    -1,   239,    -1,   240,    -1,
      10,   143,    -1,    11,    -1,    10,   241,   143,    -1,     4,
      -1,   243,   244,   245,    -1,   108,    -1,    19,   708,     6,
     708,    -1,   246,    -1,   247,    -1,    10,   109,    -1,    11,
      -1,    10,   248,   109,    -1,   249,    -1,   250,    -1,   249,
     250,    -1,   251,   252,   255,    -1,   106,    -1,   253,    -1,
      -1,   253,   254,    -1,   690,    -1,   702,    -1,   686,    -1,
      10,   107,    -1,    11,    -1,    -1,   257,   258,    -1,    50,
      -1,   259,    -1,   260,    -1,    10,    51,    -1,    11,    -1,
      10,   261,    51,    -1,   262,    -1,   263,    -1,   262,   263,
      -1,   264,    -1,   270,    -1,   277,    -1,   284,    -1,   291,
      -1,   296,    -1,   265,   266,    -1,   136,    -1,   267,    -1,
     268,    -1,    10,   137,    -1,    11,    -1,    10,   269,   137,
      -1,     4,    -1,   271,   272,   275,    -1,    68,    -1,   273,
      -1,    -1,   273,   274,    -1,   698,    -1,   686,    -1,    10,
     276,    69,    -1,     6,    -1,     7,    -1,   278,   279,   282,
      -1,    70,    -1,   280,    -1,    -1,   280,   281,    -1,   698,
      -1,   686,    -1,    10,   283,    71,    -1,     6,    -1,     7,
      -1,   285,   286,   289,    -1,    66,    -1,   287,    -1,    -1,
     287,   288,    -1,   698,    -1,   686,    -1,    10,   290,    67,
      -1,     6,    -1,     7,    -1,   292,   293,   294,    -1,    64,
      -1,    -1,   686,    -1,    10,   295,    65,    -1,     6,    -1,
     297,   298,   299,    -1,   108,    -1,    19,   708,     6,   708,
      -1,   300,    -1,   301,    -1,    10,   109,    -1,    11,    -1,
      10,   302,   109,    -1,   303,    -1,   304,    -1,   303,   304,
      -1,   305,   306,   309,    -1,   106,    -1,   307,    -1,    -1,
     307,   308,    -1,   690,    -1,   702,    -1,   686,    -1,    10,
     107,    -1,    11,    -1,    -1,    52,    11,    -1,    52,    10,
     311,    53,    -1,    -1,   311,   312,    -1,   313,    -1,   319,
      -1,   325,    -1,   331,    -1,   337,    -1,   343,    -1,   314,
     315,    -1,    82,    -1,   316,    -1,   317,    -1,    10,    83,
      -1,    11,    -1,    10,   318,    83,    -1,     4,    -1,   320,
     321,    -1,    80,    -1,   322,    -1,   323,    -1,    10,    81,
      -1,    11,    -1,    10,   324,    81,    -1,     6,    -1,   326,
     327,    -1,   146,    -1,   328,    -1,   329,    -1,    10,   147,
      -1,    11,    -1,    10,   330,   147,    -1,     6,    -1,   332,
     333,    -1,   140,    -1,   334,    -1,   335,    -1,    10,   141,
      -1,    11,    -1,    10,   336,   141,    -1,     4,    -1,   338,
     339,    -1,   122,    -1,   340,    -1,   341,    -1,    10,   123,
      -1,    11,    -1,    10,   342,   123,    -1,   706,    -1,   344,
     345,   346,    -1,   108,    -1,    19,   708,     6,   708,    -1,
     347,    -1,   348,    -1,    10,   109,    -1,    11,    -1,    10,
     349,   109,    -1,   350,    -1,   351,    -1,   350,   351,    -1,
     352,   353,   356,    -1,   106,    -1,   354,    -1,    -1,   354,
     355,    -1,   690,    -1,   702,    -1,   686,    -1,    10,   107,
      -1,    11,    -1,    -1,    54,    11,    -1,    54,    10,   358,
      55,    -1,    -1,   358,   359,    -1,   360,    -1,   366,    -1,
     372,    -1,   378,    -1,   384,    -1,   390,    -1,   407,    -1,
     414,    -1,   421,    -1,   428,    -1,   433,    -1,   361,   362,
      -1,   130,    -1,   363,    -1,   364,    -1,    10,   131,    -1,
      11,    -1,    10,   365,   131,    -1,     4,    -1,   367,   368,
      -1,   132,    -1,   369,    -1,   370,    -1,    10,   133,    -1,
      11,    -1,    10,   371,   133,    -1,     4,    -1,   373,   374,
      -1,   116,    -1,   375,    -1,   376,    -1,    10,   117,    -1,
      11,    -1,    10,   377,   117,    -1,     4,    -1,   379,   380,
      -1,    62,    -1,   381,    -1,   382,    -1,    10,    63,    -1,
      11,    -1,    10,   383,    63,    -1,     4,    -1,   385,   386,
      -1,    86,    -1,   387,    -1,   388,    -1,    10,    87,    -1,
      11,    -1,    10,   389,    87,    -1,     4,    -1,   391,   392,
     393,    -1,   144,    -1,    25,   708,     6,   708,    -1,   394,
      -1,   395,    -1,    10,   145,    -1,    11,    -1,    10,   396,
     145,    -1,   397,    -1,   398,    -1,   397,   398,    -1,   399,
     400,   402,    -1,   138,    -1,    -1,   400,   401,    -1,   698,
      -1,   694,    -1,   682,    -1,   686,    -1,   403,    -1,   404,
      -1,    10,   139,    -1,    11,    -1,    10,   405,   139,    -1,
     406,    -1,     7,    -1,     6,    -1,   408,   409,   412,    -1,
     152,    -1,   410,    -1,    -1,   410,   411,    -1,   698,    -1,
     686,    -1,    10,   413,   153,    -1,     6,    -1,     7,    -1,
     415,   416,   419,    -1,   154,    -1,   417,    -1,    -1,   417,
     418,    -1,   698,    -1,   686,    -1,    10,   420,   155,    -1,
       6,    -1,     7,    -1,   422,   423,   426,    -1,   150,    -1,
     424,    -1,    -1,   424,   425,    -1,   698,    -1,   686,    -1,
      10,   427,   151,    -1,     6,    -1,     7,    -1,   429,   430,
     431,    -1,   148,    -1,    -1,   686,    -1,    10,   432,   149,
      -1,     6,    -1,   434,   435,   436,    -1,   108,    -1,    19,
     708,     6,   708,    -1,   437,    -1,   438,    -1,    10,   109,
      -1,    11,    -1,    10,   439,   109,    -1,   440,    -1,   441,
      -1,   440,   441,    -1,   442,   443,   446,    -1,   106,    -1,
     444,    -1,    -1,   444,   445,    -1,   690,    -1,   702,    -1,
     686,    -1,    10,   107,    -1,    11,    -1,    -1,   448,   449,
     456,    -1,    56,    -1,   450,    -1,    -1,   450,   451,    -1,
     452,    -1,   453,    -1,   454,    -1,   455,    -1,    22,   708,
       6,   708,    -1,    27,   708,     6,   708,    -1,    13,   708,
       6,   708,    -1,    16,   708,     6,   708,    -1,   457,    -1,
     458,    -1,    10,    57,    -1,    11,    -1,    10,   459,    57,
      -1,   460,   659,    -1,   461,    -1,   460,   461,    -1,   462,
     463,   468,    -1,   124,    -1,   464,    -1,    -1,   464,   465,
      -1,   466,    -1,   467,    -1,    28,   708,     6,   708,    -1,
      42,     3,   708,    -1,    10,   469,   486,   492,   558,   597,
     635,   125,    -1,   470,   471,   475,    -1,   130,    -1,   472,
      -1,   473,    -1,   472,   473,    -1,   694,    -1,   686,    -1,
     474,    -1,    24,   708,     6,   708,    -1,   476,    -1,   477,
      -1,    10,   131,    -1,    11,    -1,    10,   478,   131,    -1,
     479,    -1,   480,    -1,   479,   480,    -1,   481,   482,   485,
      -1,   134,    -1,   483,    -1,    -1,   483,   484,    -1,   694,
      -1,   686,    -1,    10,   135,    -1,    11,    -1,    -1,   487,
     488,    -1,    96,    -1,   489,    -1,   490,    -1,    10,    97,
      -1,    11,    -1,    10,   491,    97,    -1,     4,    -1,    -1,
     493,   494,   495,    -1,   162,    -1,    -1,    21,   708,     6,
     708,    -1,   496,    -1,   497,    -1,    11,    -1,    10,   498,
     163,    -1,   499,   512,   527,   539,    -1,    -1,   500,   501,
     502,    -1,   156,    -1,    26,   708,     6,   708,    -1,   503,
      -1,   504,    -1,    10,   157,    -1,    11,    -1,    10,   505,
     157,    -1,   506,    -1,   507,    -1,   506,   507,    -1,   508,
     509,   510,    -1,   160,    -1,    29,   708,     6,   708,    -1,
      10,   511,   161,    -1,     6,    -1,     7,    -1,    -1,   513,
     514,   515,    -1,   158,    -1,    26,   708,     6,   708,    -1,
     516,    -1,   517,    -1,    10,   159,    -1,    11,    -1,    10,
     518,   159,    -1,   519,    -1,   520,    -1,   519,   520,    -1,
     521,   522,   523,    -1,   160,    -1,    29,   708,     6,   708,
      -1,   524,    -1,   525,    -1,    10,   161,    -1,    11,    -1,
      10,   526,   161,    -1,     4,    -1,    -1,   528,   529,   530,
      -1,    72,    -1,    26,   708,     6,   708,    -1,   531,    -1,
     532,    -1,    10,    73,    -1,    11,    -1,    10,   533,    73,
      -1,   534,    -1,   535,    -1,   534,   535,    -1,   536,   537,
     538,    -1,   160,    -1,    29,   708,     6,   708,    -1,    10,
       4,   161,    -1,    -1,   539,   540,    -1,   541,   542,   546,
      -1,   106,    -1,   543,    -1,    -1,   543,   544,    -1,   545,
      -1,   702,    -1,   690,    -1,   686,    -1,    26,   708,     6,
     708,    -1,   547,    -1,   548,    -1,    10,   107,    -1,    11,
      -1,    10,   549,   107,    -1,   550,    -1,   551,    -1,   550,
     551,    -1,   552,   553,   554,    -1,   160,    -1,    29,   708,
       6,   708,    -1,   555,    -1,   556,    -1,    10,   161,    -1,
      11,    -1,    10,   557,   161,    -1,   707,    -1,    -1,   559,
     560,   561,    -1,   100,    -1,    -1,    18,   708,     6,   708,
      -1,   562,    -1,   563,    -1,    11,    -1,    10,   564,   101,
      -1,   565,   578,    -1,    -1,   566,   567,   568,    -1,   156,
      -1,    15,   708,     6,   708,    -1,   569,    -1,   570,    -1,
      10,   157,    -1,    11,    -1,    10,   571,   157,    -1,   572,
      -1,   573,    -1,   572,   573,    -1,   574,   575,   576,    -1,
      98,    -1,    -1,    29,   708,     6,   708,    -1,    10,   577,
      99,    -1,     6,    -1,     7,    -1,    -1,   578,   579,    -1,
     580,   581,   585,    -1,   106,    -1,   582,    -1,    -1,   582,
     583,    -1,   584,    -1,   702,    -1,   690,    -1,   686,    -1,
      15,   708,     6,   708,    -1,   586,    -1,   587,    -1,    10,
     107,    -1,    11,    -1,    10,   588,   107,    -1,   589,    -1,
     590,    -1,   589,   590,    -1,   591,   592,   593,    -1,    98,
      -1,    29,   708,     6,   708,    -1,   594,    -1,   595,    -1,
      10,    99,    -1,    11,    -1,    10,   596,    99,    -1,   707,
      -1,    -1,   598,   599,   600,    -1,    78,    -1,    -1,    17,
     708,     6,   708,    -1,   601,    -1,   602,    -1,    11,    -1,
      10,   603,    79,    -1,   604,   616,    -1,    -1,   605,   606,
     607,    -1,    84,    -1,    12,   708,     6,   708,    -1,   608,
      -1,   609,    -1,    10,    85,    -1,    11,    -1,    10,   610,
      85,    -1,   611,    -1,   612,    -1,   611,   612,    -1,   613,
     614,    10,   615,    77,    -1,    76,    -1,    29,   708,     6,
     708,    -1,     6,    -1,     7,    -1,    -1,   616,   617,    -1,
     618,   619,   623,    -1,   106,    -1,   620,    -1,    -1,   620,
     621,    -1,   622,    -1,   702,    -1,   690,    -1,   686,    -1,
      12,   708,     6,   708,    -1,   624,    -1,   625,    -1,    10,
     107,    -1,    11,    -1,    10,   626,   107,    -1,   627,    -1,
     628,    -1,   627,   628,    -1,   629,   630,   631,    -1,    76,
      -1,    29,   708,     6,   708,    -1,   632,    -1,   633,    -1,
      10,    77,    -1,    11,    -1,    10,   634,    77,    -1,   707,
      -1,    -1,   636,   637,   638,    -1,   112,    -1,    20,   708,
       6,   708,    -1,   639,    -1,   640,    -1,    10,   113,    -1,
      11,    -1,    10,   641,   113,    -1,   642,    -1,   643,    -1,
     642,   643,    -1,   644,   645,   649,    -1,   110,    -1,   646,
      -1,    -1,   646,   647,    -1,   690,    -1,   682,    -1,   686,
      -1,   648,    -1,    14,   708,     6,   708,    -1,   650,    -1,
     651,    -1,    10,   111,    -1,    11,    -1,    10,   652,   111,
      -1,   653,    -1,   654,    -1,   653,   654,    -1,   655,    -1,
     656,    -1,   657,    -1,    60,    -1,    61,    -1,    58,   658,
      59,    -1,     5,    -1,    -1,   660,   661,   662,    -1,   114,
      -1,    23,   708,     6,   708,    -1,   663,    -1,   664,    -1,
      10,   115,    -1,    11,    -1,    10,   665,   115,    -1,   666,
      -1,   667,    -1,   666,   667,    -1,   668,   669,   673,    -1,
     128,    -1,   670,    -1,    -1,   670,   671,    -1,   672,    -1,
     690,    -1,   682,    -1,   686,    -1,    14,   708,     6,   708,
      -1,   674,    -1,   675,    -1,    10,   129,    -1,    11,    -1,
      10,   676,   129,    -1,   677,    -1,   678,    -1,   677,   678,
      -1,   679,    -1,   680,    -1,   681,    -1,    60,    -1,    61,
      -1,    58,     5,    59,    -1,   683,    -1,   684,    -1,   685,
      -1,    31,    -1,    30,     3,   708,    -1,   687,    -1,   688,
      -1,   689,    -1,    33,    -1,    32,     3,   708,    -1,   691,
      -1,   692,    -1,   693,    -1,    35,    -1,    34,     3,   708,
      -1,   695,    -1,   696,    -1,   697,    -1,    37,    -1,    36,
       3,   708,    -1,   699,    -1,   700,    -1,   701,    -1,    39,
      -1,    38,     3,   708,    -1,   703,    -1,   704,    -1,   705,
      -1,    41,    -1,    40,     3,   708,    -1,     6,    -1,     7,
      -1,     4,    -1,     6,    -1,     7,    -1,   709,     8,    -1,
      -1,   709,   710,    -1,   165,    -1,   166,    -1,   167,    -1,
     168,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   162,   162,   164,   166,   166,   168,   170,   173,   173,
     175,   177,   177,   179,   179,   181,   183,   185,   185,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   199,   201,
     214,   220,   220,   223,   231,   235,   238,   249,   253,   258,
     258,   260,   262,   264,   264,   266,   270,   277,   282,   282,
     285,   289,   294,   294,   297,   299,   305,   305,   307,   307,
     309,   311,   314,   316,   322,   322,   324,   324,   326,   328,
     331,   333,   339,   339,   341,   341,   343,   345,   348,   350,
     356,   356,   358,   358,   360,   362,   365,   367,   373,   373,
     375,   375,   377,   379,   382,   384,   390,   390,   392,   392,
     394,   396,   399,   401,   407,   407,   409,   409,   411,   413,
     416,   418,   424,   433,   437,   442,   442,   444,   446,   448,
     448,   450,   454,   462,   467,   467,   470,   475,   479,   485,
     485,   489,   489,   491,   493,   493,   495,   495,   497,   499,
     501,   501,   504,   505,   506,   507,   508,   509,   512,   514,
     520,   520,   522,   522,   524,   526,   529,   531,   539,   541,
     541,   544,   556,   561,   564,   565,   568,   570,   578,   580,
     580,   583,   595,   600,   603,   604,   607,   609,   617,   619,
     619,   622,   638,   643,   646,   647,   650,   652,   659,   660,
     665,   668,   671,   673,   679,   688,   692,   697,   697,   699,
     701,   703,   703,   705,   709,   717,   722,   722,   725,   730,
     734,   740,   740,   744,   744,   745,   747,   747,   750,   751,
     752,   753,   754,   755,   758,   760,   766,   766,   768,   768,
     770,   772,   784,   786,   792,   792,   794,   794,   796,   798,
     801,   803,   809,   809,   811,   811,   813,   815,   818,   820,
     826,   826,   828,   828,   830,   832,   835,   837,   843,   843,
     845,   845,   847,   849,   852,   854,   860,   869,   873,   878,
     878,   880,   882,   884,   884,   886,   890,   898,   903,   903,
     906,   911,   915,   921,   921,   924,   924,   925,   927,   927,
     930,   931,   932,   933,   934,   935,   936,   937,   938,   939,
     940,   943,   945,   951,   951,   953,   953,   955,   957,   969,
     971,   977,   977,   979,   979,   981,   983,   986,   988,   994,
     994,   996,   996,   998,  1000,  1003,  1005,  1011,  1011,  1013,
    1013,  1015,  1017,  1020,  1022,  1028,  1028,  1030,  1030,  1032,
    1034,  1037,  1039,  1045,  1052,  1056,  1061,  1061,  1063,  1065,
    1067,  1067,  1069,  1071,  1084,  1084,  1087,  1099,  1105,  1115,
    1118,  1118,  1120,  1120,  1122,  1124,  1135,  1136,  1139,  1141,
    1149,  1151,  1151,  1154,  1166,  1171,  1174,  1175,  1178,  1180,
    1188,  1190,  1190,  1193,  1205,  1210,  1213,  1214,  1217,  1219,
    1229,  1231,  1231,  1234,  1250,  1255,  1258,  1259,  1262,  1264,
    1272,  1273,  1278,  1281,  1285,  1287,  1293,  1302,  1306,  1311,
    1311,  1313,  1315,  1317,  1317,  1319,  1323,  1331,  1336,  1336,
    1339,  1344,  1348,  1354,  1354,  1357,  1357,  1359,  1366,  1371,
    1371,  1374,  1375,  1376,  1377,  1380,  1390,  1398,  1406,  1415,
    1419,  1424,  1424,  1426,  1428,  1430,  1430,  1432,  1434,  1442,
    1444,  1444,  1446,  1446,  1448,  1456,  1466,  1472,  1474,  1481,
    1486,  1486,  1489,  1503,  1506,  1508,  1519,  1523,  1529,  1529,
    1531,  1533,  1535,  1535,  1537,  1540,  1547,  1552,  1552,  1555,
    1564,  1570,  1570,  1573,  1573,  1575,  1577,  1577,  1579,  1579,
    1581,  1583,  1588,  1588,  1590,  1593,  1594,  1602,  1602,  1604,
    1606,  1608,  1610,  1610,  1612,  1614,  1623,  1627,  1632,  1632,
    1634,  1636,  1638,  1638,  1640,  1646,  1652,  1654,  1657,  1658,
    1661,  1661,  1663,  1665,  1674,  1678,  1683,  1683,  1685,  1687,
    1689,  1689,  1691,  1698,  1704,  1707,  1708,  1710,  1710,  1712,
    1714,  1717,  1717,  1719,  1721,  1730,  1734,  1739,  1739,  1741,
    1743,  1745,  1745,  1747,  1749,  1755,  1757,  1770,  1770,  1772,
    1777,  1787,  1794,  1794,  1797,  1798,  1803,  1808,  1814,  1824,
    1824,  1826,  1826,  1828,  1830,  1832,  1832,  1834,  1839,  1841,
    1846,  1846,  1848,  1848,  1850,  1852,  1857,  1857,  1859,  1865,
    1866,  1874,  1874,  1876,  1878,  1880,  1882,  1882,  1884,  1886,
    1895,  1899,  1904,  1904,  1906,  1908,  1911,  1911,  1913,  1919,
    1926,  1926,  1928,  1931,  1932,  1936,  1936,  1938,  1944,  1954,
    1962,  1962,  1965,  1966,  1971,  1976,  1982,  1992,  1992,  1994,
    1994,  1996,  1998,  2000,  2000,  2002,  2007,  2009,  2013,  2013,
    2015,  2015,  2017,  2019,  2024,  2024,  2026,  2031,  2032,  2040,
    2040,  2042,  2044,  2046,  2048,  2048,  2050,  2053,  2062,  2066,
    2071,  2071,  2073,  2075,  2077,  2077,  2079,  2085,  2091,  2094,
    2095,  2098,  2098,  2100,  2106,  2116,  2123,  2123,  2126,  2127,
    2132,  2137,  2143,  2153,  2153,  2155,  2155,  2157,  2159,  2161,
    2161,  2163,  2168,  2170,  2175,  2175,  2177,  2177,  2179,  2181,
    2187,  2187,  2189,  2194,  2203,  2207,  2212,  2212,  2214,  2216,
    2218,  2218,  2220,  2224,  2233,  2240,  2240,  2243,  2248,  2253,
    2258,  2260,  2271,  2275,  2280,  2280,  2282,  2284,  2286,  2286,
    2288,  2293,  2297,  2299,  2299,  2301,  2303,  2312,  2312,  2314,
    2319,  2328,  2332,  2337,  2337,  2339,  2341,  2343,  2343,  2345,
    2349,  2358,  2365,  2365,  2368,  2369,  2373,  2377,  2382,  2392,
    2396,  2401,  2401,  2403,  2405,  2407,  2407,  2409,  2414,  2418,
    2420,  2420,  2422,  2431,  2437,  2437,  2439,  2442,  2445,  2451,
    2451,  2453,  2456,  2460,  2466,  2466,  2468,  2471,  2474,  2480,
    2480,  2482,  2485,  2488,  2494,  2494,  2496,  2499,  2502,  2508,
    2508,  2510,  2513,  2518,  2519,  2522,  2523,  2524,  2526,  2528,
    2528,  2530,  2531,  2532,  2533
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
  "generalStatusATT", "generalStatusNumberOfATT", "generalStatusContent",
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
  "optimizationNumberOfSolutionsATT", "optimizationNumberOfVariablesATT",
  "optimizationNumberOfConstraintsATT",
  "optimizationNumberOfObjectivesATT", "optimizationContent",
  "optimizationEmpty", "optimizationLaden", "optimizationBody",
  "solutionArray", "solution", "solutionStart", "solutionAttributes",
  "solutionAttList", "solutionATT", "targetObjectiveIdxATT",
  "weightedObjectivesATT", "solutionContent", "solutionStatus",
  "solutionStatusStart", "solutionStatusAttributes",
  "solutionStatusAttList", "solutionStatusATT",
  "solutionStatusNumberOfATT", "solutionStatusContent",
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
  "numberOfOtherVariableResultsATT", "otherVariableResultContent",
  "otherVariableResultEmpty", "otherVariableResultLaden",
  "otherVariableResultBody", "otherVarList", "otherVar", "otherVarStart",
  "otherVarIdxATT", "otherVarContent", "otherVarEmpty", "otherVarLaden",
  "otherVarBody", "objectives", "objectivesStart",
  "numberOfOtherObjectiveResults", "objectivesContent", "objectivesEmpty",
  "objectivesLaden", "objectivesBody", "objectiveValues",
  "objectiveValuesStart", "numberOfObjATT", "objectiveValuesContent",
  "objectiveValuesEmpty", "objectiveValuesLaden", "objectiveValuesBody",
  "objValueArray", "objValue", "objValueStart", "objIdxATT",
  "objValueContent", "objVal", "otherObjectiveResultsArray",
  "otherObjectiveResult", "otherObjectiveResultStart",
  "otherObjectiveResultAttributes", "otherObjectiveResultAttList",
  "otherObjectiveResultATT", "numberOfOtherObjectiveResultsATT",
  "otherObjectiveResultContent", "otherObjectiveResultEmpty",
  "otherObjectiveResultLaden", "otherObjectiveResultBody", "otherObjList",
  "otherObj", "otherObjStart", "otherObjIdxATT", "otherObjContent",
  "otherObjEmpty", "otherObjLaden", "otherObjBody", "constraints",
  "constraintsStart", "numberOfOtherConstraintResults",
  "constraintsContent", "constraintsEmpty", "constraintsLaden",
  "constraintsBody", "dualValues", "dualValuesStart", "numberOfConATT",
  "dualValuesContent", "dualValuesEmpty", "dualValuesLaden",
  "dualValuesBody", "dualValueArray", "dualValue", "dualValueStart",
  "conIdxATT", "dualVal", "otherConstraintResultsArray",
  "otherConstraintResult", "otherConstraintResultStart",
  "otherConstraintResultAttributes", "otherConstraintResultAttList",
  "otherConstraintResultATT", "numberOfOtherConstraintResultATT",
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
  "otherSolutionResultAtt", "numberOfOtherSolutionResultItems",
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
  "solverOutputAtt", "numberOfSolverOutputItems", "solverOutputContent",
  "solverOutputEmpty", "solverOutputLaden", "solverOutputBody",
  "solverOutputItemArray", "solverOutputItem", "solverOutputItemContent",
  "solverOutputItemEmpty", "solverOutputItemBody", "categoryAttribute",
  "categoryAtt", "categoryAttEmpty", "categoryAttContent",
  "descriptionAttribute", "descriptionAtt", "descriptionAttEmpty",
  "descriptionAttContent", "nameAttribute", "nameAtt", "nameAttEmpty",
  "nameAttContent", "typeAttribute", "typeAtt", "typeAttEmpty",
  "typeAttContent", "unitAttribute", "unitAtt", "unitAttEmpty",
  "unitAttContent", "valueAttribute", "valueAtt", "valueAttEmpty",
  "valueAttContent", "aNumber", "ElementValue", "quote", "xmlWhiteSpace",
  "xmlWhiteSpaceChar", 0
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
     185,   186,   186,   187,   187,   187,   188,   189,   189,   190,
     190,   191,   192,   193,   193,   194,   195,   196,   197,   197,
     198,   198,   199,   199,   200,   201,   202,   202,   203,   203,
     204,   205,   206,   207,   208,   208,   209,   209,   210,   211,
     212,   213,   214,   214,   215,   215,   216,   217,   218,   219,
     220,   220,   221,   221,   222,   223,   224,   225,   226,   226,
     227,   227,   228,   229,   230,   231,   232,   232,   233,   233,
     234,   235,   236,   237,   238,   238,   239,   239,   240,   241,
     242,   243,   244,   245,   245,   246,   246,   247,   248,   249,
     249,   250,   251,   252,   253,   253,   254,   254,   254,   255,
     255,   256,   256,   257,   258,   258,   259,   259,   260,   261,
     262,   262,   263,   263,   263,   263,   263,   263,   264,   265,
     266,   266,   267,   267,   268,   269,   270,   271,   272,   273,
     273,   274,   274,   275,   276,   276,   277,   278,   279,   280,
     280,   281,   281,   282,   283,   283,   284,   285,   286,   287,
     287,   288,   288,   289,   290,   290,   291,   292,   293,   293,
     294,   295,   296,   297,   298,   299,   299,   300,   300,   301,
     302,   303,   303,   304,   305,   306,   307,   307,   308,   308,
     308,   309,   309,   310,   310,   310,   311,   311,   312,   312,
     312,   312,   312,   312,   313,   314,   315,   315,   316,   316,
     317,   318,   319,   320,   321,   321,   322,   322,   323,   324,
     325,   326,   327,   327,   328,   328,   329,   330,   331,   332,
     333,   333,   334,   334,   335,   336,   337,   338,   339,   339,
     340,   340,   341,   342,   343,   344,   345,   346,   346,   347,
     347,   348,   349,   350,   350,   351,   352,   353,   354,   354,
     355,   355,   355,   356,   356,   357,   357,   357,   358,   358,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   360,   361,   362,   362,   363,   363,   364,   365,   366,
     367,   368,   368,   369,   369,   370,   371,   372,   373,   374,
     374,   375,   375,   376,   377,   378,   379,   380,   380,   381,
     381,   382,   383,   384,   385,   386,   386,   387,   387,   388,
     389,   390,   391,   392,   393,   393,   394,   394,   395,   396,
     397,   397,   398,   399,   400,   400,   401,   401,   401,   401,
     402,   402,   403,   403,   404,   405,   406,   406,   407,   408,
     409,   410,   410,   411,   411,   412,   413,   413,   414,   415,
     416,   417,   417,   418,   418,   419,   420,   420,   421,   422,
     423,   424,   424,   425,   425,   426,   427,   427,   428,   429,
     430,   430,   431,   432,   433,   434,   435,   436,   436,   437,
     437,   438,   439,   440,   440,   441,   442,   443,   444,   444,
     445,   445,   445,   446,   446,   447,   447,   448,   449,   450,
     450,   451,   451,   451,   451,   452,   453,   454,   455,   456,
     456,   457,   457,   458,   459,   460,   460,   461,   462,   463,
     464,   464,   465,   465,   466,   467,   468,   469,   470,   471,
     472,   472,   473,   473,   473,   474,   475,   475,   476,   476,
     477,   478,   479,   479,   480,   481,   482,   483,   483,   484,
     484,   485,   485,   486,   486,   487,   488,   488,   489,   489,
     490,   491,   492,   492,   493,   494,   494,   495,   495,   496,
     497,   498,   499,   499,   500,   501,   502,   502,   503,   503,
     504,   505,   506,   506,   507,   508,   509,   510,   511,   511,
     512,   512,   513,   514,   515,   515,   516,   516,   517,   518,
     519,   519,   520,   521,   522,   523,   523,   524,   524,   525,
     526,   527,   527,   528,   529,   530,   530,   531,   531,   532,
     533,   534,   534,   535,   536,   537,   538,   539,   539,   540,
     541,   542,   543,   543,   544,   544,   544,   544,   545,   546,
     546,   547,   547,   548,   549,   550,   550,   551,   552,   553,
     554,   554,   555,   555,   556,   557,   558,   558,   559,   560,
     560,   561,   561,   562,   563,   564,   565,   565,   566,   567,
     568,   568,   569,   569,   570,   571,   572,   572,   573,   574,
     575,   575,   576,   577,   577,   578,   578,   579,   580,   581,
     582,   582,   583,   583,   583,   583,   584,   585,   585,   586,
     586,   587,   588,   589,   589,   590,   591,   592,   593,   593,
     594,   594,   595,   596,   597,   597,   598,   599,   599,   600,
     600,   601,   602,   603,   604,   604,   605,   606,   607,   607,
     608,   608,   609,   610,   611,   611,   612,   613,   614,   615,
     615,   616,   616,   617,   618,   619,   620,   620,   621,   621,
     621,   621,   622,   623,   623,   624,   624,   625,   626,   627,
     627,   628,   629,   630,   631,   631,   632,   632,   633,   634,
     635,   635,   636,   637,   638,   638,   639,   639,   640,   641,
     642,   642,   643,   644,   645,   646,   646,   647,   647,   647,
     647,   648,   649,   649,   650,   650,   651,   652,   653,   653,
     654,   655,   655,   656,   656,   657,   658,   659,   659,   660,
     661,   662,   662,   663,   663,   664,   665,   666,   666,   667,
     668,   669,   670,   670,   671,   671,   671,   671,   672,   673,
     673,   674,   674,   675,   676,   677,   677,   678,   679,   679,
     680,   680,   681,   682,   683,   683,   684,   685,   686,   687,
     687,   688,   689,   690,   691,   691,   692,   693,   694,   695,
     695,   696,   697,   698,   699,   699,   700,   701,   702,   703,
     703,   704,   705,   706,   706,   707,   707,   707,   708,   709,
     709,   710,   710,   710,   710
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     0,     1,     3,     5,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     2,     1,     1,     1,     4,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     2,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     2,
       1,     0,     2,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     0,
       2,     1,     1,     3,     1,     1,     3,     1,     1,     0,
       2,     1,     1,     3,     1,     1,     3,     1,     1,     0,
       2,     1,     1,     3,     1,     1,     3,     1,     0,     1,
       3,     1,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     2,     1,     0,     2,     4,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     4,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     3,     1,
       1,     0,     2,     1,     1,     3,     1,     1,     3,     1,
       1,     0,     2,     1,     1,     3,     1,     1,     3,     1,
       1,     0,     2,     1,     1,     3,     1,     1,     3,     1,
       0,     1,     3,     1,     3,     1,     4,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     4,     4,     4,     4,     1,
       1,     2,     1,     3,     2,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     4,     3,     8,     3,     1,     1,
       1,     2,     1,     1,     1,     4,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     2,     1,     0,     2,     1,     1,     1,     2,     1,
       3,     1,     0,     3,     1,     0,     4,     1,     1,     1,
       3,     4,     0,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     4,     3,     1,     1,
       0,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     0,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     4,     3,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     4,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     0,     3,     1,     0,
       4,     1,     1,     1,     3,     2,     0,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       0,     4,     3,     1,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     4,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     0,     3,     1,     0,     4,     1,
       1,     1,     3,     2,     0,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     1,     2,     5,     1,     4,     1,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     4,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       0,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     4,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       4,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     4,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     2,     0,
       2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     3,     0,     4,     1,     5,     0,     8,     2,    10,
       0,   131,     0,     6,   133,   213,     0,     0,    14,     9,
      11,    12,     0,   285,     0,   137,   132,   134,   135,    13,
      29,    79,    87,    55,   111,    71,    63,    95,   103,     0,
      16,    17,    19,     0,    20,     0,    21,     0,    22,     0,
      23,     0,    24,     0,    25,     0,    26,     0,    27,     0,
     216,   214,     0,   425,   136,   187,   177,   157,   167,   193,
     149,     0,   139,   140,   142,     0,   143,   159,   144,   169,
     145,   179,   146,   188,   147,     0,    15,    18,   809,     0,
     781,     0,   791,     0,    30,    31,    35,    34,   778,   779,
     780,    33,   788,   789,   790,     0,    59,    54,    56,    57,
       0,    67,    62,    64,    65,     0,    75,    70,    72,    73,
       0,    83,    78,    80,    81,     0,    91,    86,    88,    89,
       0,    99,    94,    96,    97,     0,   107,   102,   104,   105,
     809,     0,     0,   288,   286,   427,     7,   429,   138,   141,
       0,   153,   148,   150,   151,     0,   158,     0,   168,     0,
     178,     0,   189,   809,     0,     0,     0,   809,   809,     0,
      40,    28,    37,    38,    32,    61,    58,     0,    69,    66,
       0,    77,    74,     0,    85,    82,     0,    93,    90,     0,
     101,    98,     0,   109,   106,     0,     0,     0,   116,   110,
     113,   114,   215,   233,   225,   265,   257,   249,   241,   217,
     218,     0,   219,     0,   220,     0,   221,     0,   222,     0,
     223,     0,     0,     0,   428,   155,   152,     0,     0,   156,
       0,   796,   160,   162,   161,   793,   794,   795,     0,   166,
     170,   172,   171,     0,   176,   180,   182,   181,     0,   186,
       0,     0,   198,   192,   195,   196,   809,   808,   811,   812,
     813,   814,   810,   782,   792,    39,    46,     0,    42,    43,
      48,    60,    68,    76,    84,    92,   100,   108,   809,   122,
     115,     0,   118,   119,   124,     0,   229,   224,   226,   227,
       0,   237,   232,   234,   235,     0,   245,   240,   242,   243,
       0,   253,   248,   250,   251,     0,   261,   256,   258,   259,
     809,     0,   287,   326,   334,   405,   318,   302,   310,   342,
     399,   389,   369,   379,   289,   290,     0,   291,     0,   292,
       0,   293,     0,   294,     0,   295,     0,   296,   371,   297,
     381,   298,   391,   299,   400,   300,     0,     0,   442,   426,
     439,   440,   809,   809,   809,   809,   430,   431,   432,   433,
     434,   154,   164,   165,     0,   809,   174,   175,     0,   184,
     185,     0,   191,     0,   809,   204,   197,     0,   200,   201,
     206,    36,    41,    44,     0,    47,   112,   117,   120,     0,
     123,   231,   228,     0,   239,   236,     0,   247,   244,     0,
     255,   252,     0,   803,   804,   260,     0,   263,     0,     0,
     270,   264,   267,   268,     0,   306,   301,   303,   304,     0,
     314,   309,   311,   312,     0,   322,   317,   319,   320,     0,
     330,   325,   327,   328,     0,   338,   333,   335,   336,   809,
       0,     0,   370,     0,   380,     0,   390,     0,   401,   809,
       0,   441,   448,     0,   737,   445,   450,     0,     0,     0,
       0,   163,   797,   173,   183,   190,   194,   199,   202,     0,
     205,     0,    53,    45,     0,   786,    49,    51,    50,   783,
     784,   785,     0,   130,   121,     0,   801,   125,   128,   126,
     127,   798,   799,   800,   230,   238,   246,   254,   262,   809,
     276,   269,     0,   272,   273,   278,   308,   305,     0,   316,
     313,     0,   324,   321,     0,   332,   329,     0,   340,   337,
       0,     0,     0,   347,   341,   344,   345,     0,   368,   372,
     374,   373,     0,   378,   382,   384,   383,     0,   388,   392,
     394,   393,     0,   398,     0,     0,   410,   404,   407,   408,
     443,   739,   446,   444,     0,     0,   449,   809,   809,   809,
     809,     0,   212,   203,   207,   210,   208,   209,    52,   809,
     129,   809,   266,   271,   274,     0,   277,   307,   315,   323,
     331,   339,   809,   353,   346,     0,   349,   350,   354,   376,
     377,     0,   386,   387,     0,   396,   397,     0,   403,     0,
     809,   416,   409,     0,   412,   413,   418,   809,     0,     0,
     447,   809,     0,   451,   452,   453,   437,   438,   435,   436,
     211,   787,   802,     0,   284,   275,   279,   282,   280,   281,
     343,   348,   351,     0,   375,   385,   395,   402,   406,   411,
     414,     0,   417,     0,     0,   744,   738,   741,   742,   458,
     483,     0,     0,   809,   283,     0,   363,     0,   776,   355,
     352,   360,   361,   358,   773,   774,   775,   359,   357,   356,
       0,   424,   415,   419,   422,   420,   421,   809,   743,   750,
       0,   746,   747,   752,   485,   492,     0,   809,     0,   459,
     460,   464,   463,   462,   809,   455,   367,   366,   362,     0,
     365,   809,   423,   740,   745,   748,     0,   751,   494,   586,
     495,     0,   489,   484,   486,   487,     0,     0,   469,   457,
     466,   467,   461,   454,   364,   777,     0,   762,   749,   759,
     760,   809,   753,   754,   756,   757,   755,   588,   644,   589,
     809,     0,   491,   488,     0,   809,   468,   475,     0,   471,
     472,   477,     0,   770,   771,   761,     0,   764,   765,   767,
     768,   769,     0,   646,   700,   647,   809,     0,     0,   502,
     499,   493,   497,   498,   490,   465,   470,   473,     0,   476,
       0,   763,   766,   809,   702,     0,     0,   809,     0,     0,
     596,   593,   587,   591,   592,   809,   504,     0,   520,     0,
       0,   482,   474,   478,   480,   479,   772,   758,   456,   809,
       0,     0,   654,   651,   645,   649,   650,   809,   598,     0,
     615,     0,   496,   500,   522,   541,     0,   809,     0,   481,
       0,     0,   707,   701,   704,   705,   809,   656,     0,   671,
       0,   590,   594,   595,   809,     0,   543,   557,     0,   809,
       0,     0,     0,   509,   503,   506,   507,   809,   713,   706,
       0,   709,   710,   715,   648,   652,   653,   809,     0,   618,
     616,   620,     0,     0,   603,   597,   600,   601,   501,   809,
       0,     0,     0,   527,   521,   524,   525,   809,   508,   515,
       0,   511,   512,     0,   703,   708,   711,     0,   714,   674,
     672,   676,     0,     0,   661,   655,   658,   659,     0,   619,
     809,   609,   602,     0,   605,   606,   610,   560,   558,   562,
       0,     0,   548,   542,   545,   546,   809,   526,   533,     0,
     529,   530,     0,   505,   510,   513,   809,     0,     0,   725,
     712,   722,   723,   809,   716,   720,   718,   719,   717,     0,
     675,   809,   667,   660,     0,   663,   664,     0,     0,   630,
     617,   627,   628,   809,   621,   622,   625,   624,   623,   599,
     604,   607,   809,     0,     0,   561,   809,   547,   554,     0,
     550,   551,     0,   523,   528,   531,   809,     0,     0,     0,
     514,     0,   733,   734,   724,     0,   727,   728,   730,   731,
     732,     0,     0,   686,   673,   683,   684,   809,   677,   678,
     681,   680,   679,   657,   662,   665,   809,     0,   636,   629,
       0,   632,   633,     0,     0,     0,     0,   608,     0,   572,
     559,   569,   570,   809,   563,   564,   567,   566,   565,   544,
     549,   552,   809,     0,     0,     0,   538,   532,   535,   536,
     809,   518,   519,     0,   736,     0,   726,   729,   809,   692,
     685,     0,   688,   689,     0,     0,     0,     0,   631,   634,
     809,     0,   809,   809,   613,   614,     0,   571,   578,     0,
     574,   575,     0,     0,     0,     0,   553,   809,   540,   537,
       0,   516,   517,   735,   721,   687,   690,   809,     0,   809,
     809,   669,   670,     0,     0,     0,   641,   635,   638,   639,
     626,   611,   612,   573,   576,   809,     0,   809,   809,     0,
     534,   539,     0,     0,   697,   691,   694,   695,   682,   668,
     666,   809,   805,   806,   807,   640,     0,   643,     0,     0,
     583,   577,   580,   581,   568,   555,   556,   809,   696,     0,
     699,   637,   642,   809,   582,     0,   585,   693,   698,   579,
     584
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,    10,    11,    12,    19,    20,
      21,    39,    40,    41,    42,    43,    93,    94,    95,    96,
     171,   172,   173,   267,   268,   269,   270,   384,   385,   476,
     473,    44,    45,   107,   108,   109,   177,    46,    47,   112,
     113,   114,   180,    48,    49,   117,   118,   119,   183,    50,
      51,   122,   123,   124,   186,    52,    53,   127,   128,   129,
     189,    54,    55,   132,   133,   134,   192,    56,    57,   137,
     138,   139,   195,    58,    59,   141,   199,   200,   201,   281,
     282,   283,   284,   389,   390,   487,   484,    15,    16,    26,
      27,    28,    71,    72,    73,    74,    75,   152,   153,   154,
     227,    76,    77,   155,   156,   232,   229,   364,    78,    79,
     157,   158,   240,   239,   368,    80,    81,   159,   160,   245,
     244,   371,    82,    83,   161,   249,   373,    84,    85,   164,
     253,   254,   255,   377,   378,   379,   380,   469,   470,   564,
     563,    23,   142,   209,   210,   211,   287,   288,   289,   393,
     212,   213,   292,   293,   294,   396,   214,   215,   297,   298,
     299,   399,   216,   217,   302,   303,   304,   402,   218,   219,
     307,   308,   309,   406,   220,   221,   311,   411,   412,   413,
     502,   503,   504,   505,   575,   576,   626,   625,    63,   222,
     324,   325,   326,   416,   417,   418,   508,   327,   328,   421,
     422,   423,   511,   329,   330,   426,   427,   428,   514,   331,
     332,   431,   432,   433,   517,   333,   334,   436,   437,   438,
     520,   335,   336,   440,   524,   525,   526,   585,   586,   587,
     588,   633,   659,   660,   661,   662,   699,   700,   337,   338,
     441,   442,   529,   528,   591,   339,   340,   443,   444,   534,
     533,   594,   341,   342,   445,   446,   539,   538,   597,   343,
     344,   447,   543,   599,   345,   346,   450,   547,   548,   549,
     603,   604,   605,   606,   641,   642,   673,   672,   146,   147,
     223,   224,   356,   357,   358,   359,   360,   349,   350,   351,
     453,   454,   455,   456,   555,   556,   613,   614,   615,   610,
     650,   651,   688,   689,   690,   691,   719,   720,   721,   748,
     749,   750,   751,   778,   779,   803,   802,   685,   686,   713,
     714,   715,   744,   709,   710,   741,   771,   772,   773,   797,
     798,   799,   828,   854,   855,   856,   890,   891,   892,   893,
     937,   990,  1053,   825,   826,   850,   884,   885,   886,   929,
     930,   931,   932,   987,  1047,  1048,  1049,  1090,   847,   848,
     880,   923,   924,   925,   979,   980,   981,   982,  1043,  1086,
     878,   918,   919,   974,   975,  1034,  1035,  1030,  1031,  1032,
    1079,  1080,  1081,  1082,  1116,  1141,  1142,  1143,  1155,   738,
     739,   767,   792,   793,   794,   819,   820,   821,   845,   875,
     876,   877,   913,   914,   915,   916,   973,  1027,  1076,   843,
     870,   871,   908,   909,   964,   965,   960,   961,   962,  1020,
    1021,  1022,  1023,  1071,  1107,  1108,  1109,  1136,   764,   765,
     788,   814,   815,   816,   838,   839,   840,   868,   905,   906,
     907,   954,   955,   956,   957,  1017,  1103,   866,   900,   901,
     949,   950,  1008,  1009,  1004,  1005,  1006,  1061,  1062,  1063,
    1064,  1098,  1125,  1126,  1127,  1149,   785,   786,   810,   833,
     834,   835,   860,   861,   862,   863,   897,   898,   944,   945,
     940,   941,   942,   995,   996,   997,   998,   999,  1000,  1055,
     553,   554,   608,   646,   647,   648,   680,   681,   682,   683,
     706,   707,   732,   733,   728,   729,   730,   756,   757,   758,
     759,   760,   761,   663,   664,   665,   666,    97,    98,    99,
     100,   478,   479,   480,   481,   101,   102,   103,   104,   234,
     235,   236,   237,   490,   491,   492,   493,   407,  1137,   165,
     166,   262
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1075
static const yytype_int16 yypact[] =
{
      24, -1075,    73,    48, -1075, -1075,    76,    53, -1075, -1075,
      41,    55,   208, -1075, -1075,    62,   235,   -33, -1075, -1075,
   -1075, -1075,   275,    67,    49, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,    96,
      90, -1075, -1075,    59, -1075,   296, -1075,   305, -1075,   307,
   -1075,   312, -1075,   314, -1075,   316, -1075,   318, -1075,   130,
   -1075, -1075,   320,   103, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075,   110,    92, -1075, -1075,   322, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,   302, -1075,   156, -1075, -1075, -1075,   180,
   -1075,   198, -1075,   326,    59, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075,    30, -1075, -1075, -1075, -1075,
      20, -1075, -1075, -1075, -1075,    21, -1075, -1075, -1075, -1075,
      40, -1075, -1075, -1075, -1075,    36, -1075, -1075, -1075, -1075,
      17, -1075, -1075, -1075, -1075,    10, -1075, -1075, -1075, -1075,
   -1075,   328,   -11, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
      18, -1075, -1075, -1075, -1075,   199,   191,   201,   191,   217,
     191,   223, -1075, -1075,   330,   231,    -2, -1075, -1075,   -35,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075,   161, -1075, -1075,
     171, -1075, -1075,   181, -1075, -1075,   215, -1075, -1075,   209,
   -1075, -1075,   236, -1075, -1075,   222,   352,    33, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075,   332, -1075,   334, -1075,   336, -1075,   338, -1075,   340,
   -1075,   370,   -26,   342,   204, -1075, -1075,   260,   348, -1075,
     427, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   350, -1075,
   -1075, -1075, -1075,   354, -1075, -1075, -1075, -1075,   410, -1075,
     453,   153, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075,   372,   339, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075,   366,   335, -1075, -1075,    42, -1075, -1075, -1075, -1075,
      56, -1075, -1075, -1075, -1075,     3, -1075, -1075, -1075, -1075,
      11, -1075, -1075, -1075, -1075,    25, -1075, -1075, -1075, -1075,
   -1075,   357, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075,   359, -1075,   361, -1075,
     363, -1075,   365, -1075,   367, -1075,   445, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,   302, -1075,   455,   -16, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,   397, -1075, -1075, -1075,   401, -1075,
   -1075,   409, -1075,   412, -1075, -1075, -1075,   374,   376, -1075,
   -1075, -1075, -1075, -1075,   369,   172, -1075, -1075, -1075,   371,
     279, -1075, -1075,   395, -1075, -1075,   403, -1075, -1075,   341,
   -1075, -1075,   344, -1075, -1075, -1075,   356, -1075,   480,   173,
   -1075, -1075, -1075, -1075,    16, -1075, -1075, -1075, -1075,    13,
   -1075, -1075, -1075, -1075,    26, -1075, -1075, -1075, -1075,    39,
   -1075, -1075, -1075, -1075,    47, -1075, -1075, -1075, -1075, -1075,
     373,   477,   191,   479,   191,   481,   191,   482, -1075, -1075,
     375, -1075, -1075,   433,    75, -1075, -1075,   487,   488,   489,
     491, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   377,
     279,   364, -1075, -1075,   495, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075,   393, -1075, -1075,   498, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075,   399,   405, -1075, -1075, -1075, -1075,   378, -1075,
   -1075,   381, -1075, -1075,   386, -1075, -1075,   442, -1075, -1075,
     420,   496,   -71, -1075, -1075, -1075, -1075,   385, -1075, -1075,
   -1075, -1075,   387, -1075, -1075, -1075, -1075,   389, -1075, -1075,
   -1075, -1075,   504, -1075,   509,   174, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,   493,   494,    28, -1075, -1075, -1075,
   -1075,   414, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075,   388,   279, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075,   379,   380, -1075, -1075, -1075,
   -1075,   382, -1075, -1075,   362, -1075, -1075,   368, -1075,   383,
   -1075, -1075, -1075,   416,   421, -1075, -1075, -1075,   390,   406,
   -1075, -1075,   517, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,   419, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,   211, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075,   392,   279,   516,   -49, -1075, -1075, -1075, -1075, -1075,
     432,   155,   523, -1075, -1075,    12, -1075,   527, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
     431, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
     418,   423, -1075, -1075, -1075,   384,   394, -1075,   396,   155,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   429,
   -1075, -1075, -1075, -1075, -1075, -1075,   398,   237, -1075,   434,
     510,    35, -1075, -1075, -1075, -1075,   533,   150, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075,   111, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   462,   524,
   -1075,   400, -1075, -1075,   444, -1075, -1075, -1075,   425,   436,
   -1075, -1075,   538, -1075, -1075, -1075,   430,   178, -1075, -1075,
   -1075, -1075,   539, -1075,   438,   531, -1075,   402,   543,   407,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   404,   144,
     485, -1075, -1075, -1075, -1075,   440,   532, -1075,   411,   549,
     443, -1075, -1075, -1075, -1075, -1075, -1075,   448,   408,   534,
     446, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
     413,   551,   474, -1075, -1075, -1075, -1075, -1075, -1075,   466,
   -1075,   554, -1075, -1075, -1075,   500,   547, -1075,   415, -1075,
     568,   177, -1075, -1075, -1075, -1075, -1075, -1075,   497, -1075,
     563, -1075, -1075,   471, -1075,   417, -1075, -1075,   552, -1075,
     422,   573,   141, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
     467,   472, -1075, -1075, -1075, -1075,   478, -1075,   424, -1075,
   -1075, -1075,   577,   -21, -1075, -1075, -1075, -1075,   484, -1075,
     426,   579,   284, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
     450,   456, -1075,   557, -1075, -1075, -1075,   428,   243, -1075,
   -1075, -1075,   581,    -4, -1075, -1075, -1075, -1075,   435,   220,
   -1075, -1075, -1075,   457,   490, -1075,   564, -1075, -1075, -1075,
     586,   -40, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   459,
     460, -1075,   565, -1075, -1075, -1075, -1075,   585,   -13, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   437,
     162, -1075, -1075, -1075,   511,   521, -1075,   569,     5, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,   591,   439,   262, -1075, -1075, -1075,   529,
     461, -1075,   574, -1075, -1075, -1075, -1075,   441,   598,   447,
   -1075,   601, -1075, -1075, -1075,   499,   205, -1075, -1075, -1075,
   -1075,   602,   -18, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075,   603, -1075, -1075,
     505,   519, -1075,   590,   609,   616,   449, -1075,   -50, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,   613,   618,     7, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,   464, -1075,   570, -1075, -1075, -1075, -1075,
   -1075,   525,   555, -1075,   599,   624,   627,   451, -1075, -1075,
   -1075,   452, -1075, -1075, -1075, -1075,   535, -1075, -1075,   528,
     476, -1075,   608,   632,   633,   636, -1075, -1075, -1075, -1075,
     483, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   454, -1075,
   -1075, -1075, -1075,   571,   635,    31, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075,   458, -1075, -1075,   492,
   -1075, -1075,   639,    46, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075,   550, -1075,   640,     6,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   575,
   -1075, -1075, -1075, -1075, -1075,   501, -1075, -1075, -1075, -1075,
   -1075
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,   610, -1075, -1075, -1075, -1075,   548, -1075,
   -1075, -1075, -1075, -1075, -1075,   391, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075,   463, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,   582, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075,   273, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075,   154, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,    70,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075,    54, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075,   206, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,   -28, -1075, -1075, -1075, -1075, -1075,
   -1075,   -86, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,  -227, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075,  -265, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075,  -314, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075,  -413, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,  -246, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075,  -351, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075,  -284, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,  -390,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075,  -188, -1075, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075,  -322, -1075, -1075, -1075, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,    -6, -1075,
   -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075, -1075,   -81,
   -1075, -1075, -1075,  -705, -1075, -1075, -1075,   -80, -1075, -1075,
   -1075,  -386, -1075, -1075, -1075,  -625, -1075, -1075, -1075,  -153,
   -1075, -1075, -1075,  -469, -1075, -1075, -1075, -1075, -1074,  -140,
   -1075, -1075
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     196,   567,   734,   162,   489,   242,   257,   247,   668,   397,
    1132,  1088,  1133,  1134,   193,   400,    29,   509,   696,   697,
     506,   190,   225,   250,   178,   181,   693,   263,   264,   312,
     512,   403,   404,   977,   175,  1132,   313,  1133,  1134,   742,
     187,   451,   202,   515,   184,   991,   391,   992,   993,  1150,
    1132,   518,  1133,  1134,   265,    30,   611,  1077,  1059,    31,
     314,    32,   394,    33,   693,  1156,   678,   583,     1,   203,
     612,   204,   952,     4,   584,    34,   233,   911,   241,   679,
     246,   953,   315,    88,   566,    35,     7,    36,    13,  1060,
     316,    89,    90,    37,     5,    91,    92,   205,   994,   266,
      64,     9,   516,  1018,   317,    14,   318,   629,   452,    38,
    1078,   206,  1019,    65,    22,    66,   381,    67,   319,    68,
     978,    62,   320,  1148,   321,   392,   322,   176,   323,   207,
    1135,   188,   743,   185,   519,   208,   912,   395,   386,   279,
     182,   179,   280,   513,   191,    86,   510,   507,   405,   140,
     398,   698,   401,   194,   805,   226,    65,    69,    66,   145,
      67,   148,    68,   258,   259,   260,   261,  1154,  1089,   752,
     408,   753,   754,   676,  1007,   163,    89,    90,    30,   687,
      91,    92,    31,   167,    32,    70,    33,    89,    90,   551,
     628,    91,    92,   946,    89,    90,   474,   475,    34,   452,
      69,   168,   485,   486,    89,    90,   474,   475,    35,   228,
      36,   238,   457,   458,   459,   460,    37,   352,    17,    18,
     353,   655,   656,    89,    90,   462,   354,   243,    70,   230,
     231,   355,    38,   248,   466,   963,   752,   256,   753,   754,
     755,   657,   658,    89,    90,    24,    25,    91,    92,   230,
     231,   731,    89,    90,   474,   475,   675,   943,   271,   375,
     485,   486,   376,   991,   448,   992,   993,   657,   658,    89,
      90,   474,   475,   657,   658,    89,    90,   474,   475,   500,
     601,   746,   501,   602,   747,    60,    61,   858,  1033,   531,
     859,   536,   272,   541,    89,    90,   474,   475,   888,   521,
     273,   889,   485,   486,   275,   477,   105,   106,   274,   544,
     488,    89,    90,   474,   475,   110,   111,   115,   116,   485,
     486,   736,   120,   121,   125,   126,   130,   131,   135,   136,
     143,   144,   150,   151,    89,    90,   169,   170,   197,   198,
     251,   252,   285,   286,   290,   291,   295,   296,   300,   301,
     305,   306,   347,   348,   362,   363,   366,   367,   278,   572,
     369,   370,   530,   276,   535,   277,   540,   409,   410,   414,
     415,   419,   420,   424,   425,   429,   430,   434,   435,   471,
     472,   482,   483,   522,   523,   545,   546,   561,   562,   310,
     565,   589,   590,   592,   593,   595,   596,   361,   623,   624,
     644,   645,   670,   671,   711,   712,   717,   718,   726,   727,
     769,   770,   790,   791,   800,   801,   372,   616,   617,   618,
     619,   812,   813,   831,   832,   852,   853,   873,   874,   621,
     365,   622,   882,   883,   903,   904,   921,   922,   938,   939,
     968,   279,   630,   927,   928,   958,   959,  1002,  1003,  1028,
    1029,  1045,  1046,  1051,  1052,  1074,  1075,  1101,  1102,   374,
     638,   382,  1105,  1106,  1123,  1124,   461,   643,  1139,  1140,
     439,   652,   463,   266,   449,   387,   464,   465,   494,   498,
     669,  1012,   375,   467,   495,   497,   499,   527,   496,   532,
     550,   537,   542,   557,   558,   559,   627,   560,   569,   568,
     570,   571,   582,   579,   609,   580,  1038,   581,   573,   577,
     598,   500,   948,   695,   578,   600,   607,   635,   583,   636,
     653,   620,   677,   967,   631,   639,   654,   601,   684,   694,
     701,   740,   637,   704,   737,   634,   649,   703,   702,   745,
     763,   774,   766,   780,   806,   783,   708,   716,   787,   795,
     784,   679,   809,   667,   723,   817,   776,   836,   837,   781,
     827,   725,   674,   796,  1011,   808,   824,   842,   724,   844,
     747,   692,   846,   849,   857,   867,   865,   869,   879,   887,
     895,   829,   858,   910,   899,   926,   936,   951,   911,  1037,
     917,   762,   976,   972,   986,   989,  1014,   952,  1016,   818,
     768,  1026,  1040,  1042,  1050,   775,  1054,   934,  1058,   692,
    1056,   823,  1068,  1067,   970,  1072,   889,  1018,   984,  1070,
     928,   978,  1073,  1085,  1087,  1092,   789,   735,  1097,  1093,
    1099,  1059,  1095,  1100,  1112,  1113,  1078,  1115,  1117,  1118,
    1119,  1131,   174,   807,  1121,  1147,  1153,   811,  1130,  1152,
      87,   468,  1158,  1146,   149,   822,   632,   574,   640,   383,
     552,   722,  1160,   777,   935,   985,  1041,  1114,   971,   830,
    1069,  1015,  1096,   896,  1057,   705,   782,   841,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   851,     0,     0,
       0,     0,     0,     0,     0,     0,   864,     0,     0,   804,
       0,     0,     0,     0,   872,     0,     0,     0,     0,   881,
       0,     0,     0,     0,     0,     0,     0,   894,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   902,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   920,
       0,     0,     0,     0,     0,   388,     0,   933,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     969,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   983,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   988,     0,     0,     0,
       0,     0,     0,  1001,     0,     0,     0,     0,     0,     0,
       0,  1013,     0,     0,     0,     0,     0,     0,   947,     0,
       0,     0,     0,  1024,     0,     0,     0,     0,     0,   966,
       0,     0,  1025,     0,     0,     0,  1039,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1044,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1065,     0,     0,
    1010,     0,     0,     0,     0,     0,  1066,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1083,     0,  1036,     0,     0,     0,     0,
       0,     0,  1084,     0,     0,     0,     0,     0,     0,     0,
    1091,     0,     0,     0,     0,     0,     0,     0,  1094,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,     0,  1110,  1111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1122,     0,  1128,
    1129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1138,     0,  1144,  1145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1151,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1157,     0,     0,
       0,     0,     0,  1159
};

static const yytype_int16 yycheck[] =
{
     140,   470,   707,    83,   390,   158,     8,   160,   633,     6,
       4,     4,     6,     7,     4,     4,    49,     4,     6,     7,
       4,     4,     4,   163,     4,     4,   651,   167,   168,    55,
       4,     6,     7,    73,     4,     4,    62,     6,     7,     4,
       4,    57,    53,     4,     4,    58,     4,    60,    61,  1123,
       4,     4,     6,     7,    89,    88,    28,   107,    76,    92,
      86,    94,     6,    96,   689,  1139,   115,   138,    44,    80,
      42,    82,    76,     0,   145,   108,   156,    98,   158,   128,
     160,    85,   108,    24,   470,   118,    10,   120,    47,   107,
     116,    32,    33,   126,    46,    36,    37,   108,   111,   134,
      51,    48,    63,    98,   130,    50,   132,   576,   124,   142,
     160,   122,   107,    64,    52,    66,   256,    68,   144,    70,
     160,    54,   148,    77,   150,    83,   152,    97,   154,   140,
      99,    95,    97,    93,    87,   146,   157,    81,   278,   106,
     119,   121,   109,   117,   127,    49,   133,   131,   123,    19,
     147,   139,   141,   143,   779,   137,    64,   108,    66,    56,
      68,    51,    70,   165,   166,   167,   168,   161,   161,    58,
     310,    60,    61,   642,    12,    19,    32,    33,    88,    24,
      36,    37,    92,     3,    94,   136,    96,    32,    33,   114,
     576,    36,    37,   898,    32,    33,    34,    35,   108,   124,
     108,     3,    40,    41,    32,    33,    34,    35,   118,    10,
     120,    10,   352,   353,   354,   355,   126,    13,    10,    11,
      16,    10,    11,    32,    33,   365,    22,    10,   136,    38,
      39,    27,   142,    10,   374,    15,    58,     6,    60,    61,
     129,    30,    31,    32,    33,    10,    11,    36,    37,    38,
      39,    14,    32,    33,    34,    35,   642,    14,    97,   106,
      40,    41,   109,    58,   344,    60,    61,    30,    31,    32,
      33,    34,    35,    30,    31,    32,    33,    34,    35,   106,
     106,   131,   109,   109,   134,    10,    11,   110,    26,   442,
     113,   444,   121,   446,    32,    33,    34,    35,   157,   439,
     119,   160,    40,    41,    95,   385,    10,    11,    93,   449,
     390,    32,    33,    34,    35,    10,    11,    10,    11,    40,
      41,   707,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    32,    33,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,     6,     7,     6,     7,     6,   499,
       6,     7,   442,   127,   444,   143,   446,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    19,
     470,     6,     7,     6,     7,     6,     7,   137,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,     6,   557,   558,   559,
     560,    10,    11,    10,    11,    10,    11,    10,    11,   569,
       3,   571,    10,    11,    10,    11,    10,    11,    10,    11,
     909,   106,   582,   159,   160,    10,    11,    10,    11,    10,
      11,    10,    11,     6,     7,     6,     7,     6,     7,     6,
     600,    89,    10,    11,    10,    11,    69,   607,    10,    11,
      25,   611,    71,   134,    19,   109,    67,    65,    83,   123,
     633,   950,   106,   109,    81,   141,     6,    10,   147,    10,
      57,    10,    10,     6,     6,     6,   576,     6,     3,   135,
     107,     3,     6,   117,    10,    63,   975,    87,   109,   131,
       6,   106,   898,   653,   133,     6,    23,   155,   138,   151,
       3,   107,     6,   909,   145,   109,   107,   106,    96,     6,
       3,    21,   149,   115,   100,   153,   130,   677,   107,     6,
      78,    97,    18,     5,    59,     6,   162,   687,    17,     6,
     112,   128,    20,   633,   694,     6,   131,     6,    84,   129,
      26,   701,   642,   156,   950,   125,   158,   101,   139,    15,
     134,   651,    72,    26,     6,    12,    79,   106,    26,     6,
     113,   135,   110,     6,   106,     6,    29,     6,    98,   975,
     106,   731,     6,    29,    29,    10,    85,    76,    29,   156,
     740,    10,    73,    29,     6,   745,     5,   157,     6,   689,
     111,   163,   107,    10,   157,     6,   160,    98,   159,    29,
     160,   160,     6,    10,     6,   161,   766,   707,    29,    59,
       6,    76,   107,     6,    99,   107,   160,    29,     6,     6,
       4,     6,    94,   783,   161,     6,     6,   787,    77,    99,
      40,   378,    77,   161,    72,   795,   586,   503,   604,   268,
     454,   689,   161,   749,   891,   930,   980,  1080,   914,   809,
    1021,   955,  1062,   861,   996,   681,   757,   817,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   827,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   836,    -1,    -1,   779,
      -1,    -1,    -1,    -1,   844,    -1,    -1,    -1,    -1,   849,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   857,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   867,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   879,
      -1,    -1,    -1,    -1,    -1,   282,    -1,   887,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     910,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   926,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   936,    -1,    -1,    -1,
      -1,    -1,    -1,   943,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   951,    -1,    -1,    -1,    -1,    -1,    -1,   898,    -1,
      -1,    -1,    -1,   963,    -1,    -1,    -1,    -1,    -1,   909,
      -1,    -1,   972,    -1,    -1,    -1,   976,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   986,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1007,    -1,    -1,
     950,    -1,    -1,    -1,    -1,    -1,  1016,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1033,    -1,   975,    -1,    -1,    -1,    -1,
      -1,    -1,  1042,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1050,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1058,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1070,    -1,  1072,  1073,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1087,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1097,    -1,  1099,
    1100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1115,    -1,  1117,  1118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1147,    -1,    -1,
      -1,    -1,    -1,  1153
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,     0,    46,   172,    10,   173,    48,
     174,   175,   176,    47,    50,   256,   257,    10,    11,   177,
     178,   179,    52,   310,    10,    11,   258,   259,   260,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   180,
     181,   182,   183,   184,   200,   201,   206,   207,   212,   213,
     218,   219,   224,   225,   230,   231,   236,   237,   242,   243,
      10,    11,    54,   357,    51,    64,    66,    68,    70,   108,
     136,   261,   262,   263,   264,   265,   270,   271,   277,   278,
     284,   285,   291,   292,   296,   297,    49,   182,    24,    32,
      33,    36,    37,   185,   186,   187,   188,   686,   687,   688,
     689,   694,   695,   696,   697,    10,    11,   202,   203,   204,
      10,    11,   208,   209,   210,    10,    11,   214,   215,   216,
      10,    11,   220,   221,   222,    10,    11,   226,   227,   228,
      10,    11,   232,   233,   234,    10,    11,   238,   239,   240,
      19,   244,   311,    10,    11,    56,   447,   448,    51,   263,
      10,    11,   266,   267,   268,   272,   273,   279,   280,   286,
     287,   293,   686,    19,   298,   708,   709,     3,     3,    10,
      11,   189,   190,   191,   187,     4,    97,   205,     4,   121,
     211,     4,   119,   217,     4,    93,   223,     4,    95,   229,
       4,   127,   235,     4,   143,   241,   708,    10,    11,   245,
     246,   247,    53,    80,    82,   108,   122,   140,   146,   312,
     313,   314,   319,   320,   325,   326,   331,   332,   337,   338,
     343,   344,   358,   449,   450,     4,   137,   269,    10,   275,
      38,    39,   274,   686,   698,   699,   700,   701,    10,   282,
     281,   686,   698,    10,   289,   288,   686,   698,    10,   294,
     708,    10,    11,   299,   300,   301,     6,     8,   165,   166,
     167,   168,   710,   708,   708,    89,   134,   192,   193,   194,
     195,    97,   121,   119,    93,    95,   127,   143,     6,   106,
     109,   248,   249,   250,   251,    10,    11,   315,   316,   317,
      10,    11,   321,   322,   323,    10,    11,   327,   328,   329,
      10,    11,   333,   334,   335,    10,    11,   339,   340,   341,
      19,   345,    55,    62,    86,   108,   116,   130,   132,   144,
     148,   150,   152,   154,   359,   360,   361,   366,   367,   372,
     373,   378,   379,   384,   385,   390,   391,   407,   408,   414,
     415,   421,   422,   428,   429,   433,   434,    10,    11,   456,
     457,   458,    13,    16,    22,    27,   451,   452,   453,   454,
     455,   137,     6,     7,   276,     3,     6,     7,   283,     6,
       7,   290,     6,   295,     6,   106,   109,   302,   303,   304,
     305,   708,    89,   194,   196,   197,   708,   109,   250,   252,
     253,     4,    83,   318,     6,    81,   324,     6,   147,   330,
       4,   141,   336,     6,     7,   123,   342,   706,   708,    10,
      11,   346,   347,   348,    10,    11,   362,   363,   364,    10,
      11,   368,   369,   370,    10,    11,   374,   375,   376,    10,
      11,   380,   381,   382,    10,    11,   386,   387,   388,    25,
     392,   409,   410,   416,   417,   423,   424,   430,   686,    19,
     435,    57,   124,   459,   460,   461,   462,   708,   708,   708,
     708,    69,   708,    71,    67,    65,   708,   109,   304,   306,
     307,    10,    11,   199,    34,    35,   198,   686,   690,   691,
     692,   693,    10,    11,   255,    40,    41,   254,   686,   690,
     702,   703,   704,   705,    83,    81,   147,   141,   123,     6,
     106,   109,   349,   350,   351,   352,     4,   131,   365,     4,
     133,   371,     4,   117,   377,     4,    63,   383,     4,    87,
     389,   708,    10,    11,   393,   394,   395,    10,   412,   411,
     686,   698,    10,   419,   418,   686,   698,    10,   426,   425,
     686,   698,    10,   431,   708,    10,    11,   436,   437,   438,
      57,   114,   461,   659,   660,   463,   464,     6,     6,     6,
       6,    10,    11,   309,   308,   686,   690,   702,   135,     3,
     107,     3,   708,   109,   351,   353,   354,   131,   133,   117,
      63,    87,     6,   138,   145,   396,   397,   398,   399,     6,
       7,   413,     6,     7,   420,     6,     7,   427,     6,   432,
       6,   106,   109,   439,   440,   441,   442,    23,   661,    10,
     468,    28,    42,   465,   466,   467,   708,   708,   708,   708,
     107,   708,   708,    10,    11,   356,   355,   686,   690,   702,
     708,   145,   398,   400,   153,   155,   151,   149,   708,   109,
     441,   443,   444,   708,    10,    11,   662,   663,   664,   130,
     469,   470,   708,     3,   107,    10,    11,    30,    31,   401,
     402,   403,   404,   682,   683,   684,   685,   686,   694,   698,
      10,    11,   446,   445,   686,   690,   702,     6,   115,   128,
     665,   666,   667,   668,    96,   486,   487,    24,   471,   472,
     473,   474,   686,   694,     6,   708,     6,     7,   139,   405,
     406,     3,   107,   708,   115,   667,   669,   670,   162,   492,
     493,    10,    11,   488,   489,   490,   708,    10,    11,   475,
     476,   477,   473,   708,   139,   708,    10,    11,   673,   674,
     675,    14,   671,   672,   682,   686,   690,   100,   558,   559,
      21,   494,     4,    97,   491,     6,   131,   134,   478,   479,
     480,   481,    58,    60,    61,   129,   676,   677,   678,   679,
     680,   681,   708,    78,   597,   598,    18,   560,   708,    10,
      11,   495,   496,   497,    97,   708,   131,   480,   482,   483,
       5,   129,   678,     6,   112,   635,   636,    17,   599,   708,
      10,    11,   561,   562,   563,     6,   156,   498,   499,   500,
      10,    11,   485,   484,   686,   694,    59,   708,   125,    20,
     637,   708,    10,    11,   600,   601,   602,     6,   156,   564,
     565,   566,   708,   163,   158,   512,   513,    26,   501,   135,
     708,    10,    11,   638,   639,   640,     6,    84,   603,   604,
     605,   708,   101,   578,    15,   567,    72,   527,   528,    26,
     514,   708,    10,    11,   502,   503,   504,     6,   110,   113,
     641,   642,   643,   644,   708,    79,   616,    12,   606,   106,
     579,   580,   708,    10,    11,   568,   569,   570,   539,    26,
     529,   708,    10,    11,   515,   516,   517,     6,   157,   160,
     505,   506,   507,   508,   708,   113,   643,   645,   646,   106,
     617,   618,   708,    10,    11,   607,   608,   609,   581,   582,
       6,    98,   157,   571,   572,   573,   574,   106,   540,   541,
     708,    10,    11,   530,   531,   532,     6,   159,   160,   518,
     519,   520,   521,   708,   157,   507,    29,   509,    10,    11,
     649,   650,   651,    14,   647,   648,   682,   686,   690,   619,
     620,     6,    76,    85,   610,   611,   612,   613,    10,    11,
     585,   586,   587,    15,   583,   584,   686,   690,   702,   708,
     157,   573,    29,   575,   542,   543,     6,    73,   160,   533,
     534,   535,   536,   708,   159,   520,    29,   522,   708,    10,
     510,    58,    60,    61,   111,   652,   653,   654,   655,   656,
     657,   708,    10,    11,   623,   624,   625,    12,   621,   622,
     686,   690,   702,   708,    85,   612,    29,   614,    98,   107,
     588,   589,   590,   591,   708,   708,    10,   576,    10,    11,
     546,   547,   548,    26,   544,   545,   686,   690,   702,   708,
      73,   535,    29,   537,   708,    10,    11,   523,   524,   525,
       6,     6,     7,   511,     5,   658,   111,   654,     6,    76,
     107,   626,   627,   628,   629,   708,   708,    10,   107,   590,
      29,   592,     6,     6,     6,     7,   577,   107,   160,   549,
     550,   551,   552,   708,   708,    10,   538,     6,     4,   161,
     526,   708,   161,    59,   708,   107,   628,    29,   630,     6,
       6,     6,     7,   615,   708,    10,    11,   593,   594,   595,
     708,   708,    99,   107,   551,    29,   553,     6,     6,     4,
     708,   161,   708,    10,    11,   631,   632,   633,   708,   708,
      77,     6,     4,     6,     7,    99,   596,   707,   708,    10,
      11,   554,   555,   556,   708,   708,   161,     6,    77,   634,
     707,   708,    99,     6,   161,   557,   707,   708,    77,   708,
     161
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
        case 29:

    {	if (parserData->generalStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one generalStatus element allowed");	
		if (osresult->general->generalStatus != NULL) 
			osrlerror(NULL, NULL, parserData, "generalStatus previously allocated");
		osresult->general->generalStatus = new GeneralStatus();
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

  case 36:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for generalStatus element");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of general substatuses cannot be negative");
    osresult->setNumberOfGeneralSubstatuses((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 37:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 38:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 45:

    {	parserData->kounter++;
;}
    break;

  case 46:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 47:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
;}
    break;

  case 50:

    {	
		osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 51:

    {	
		osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 55:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 61:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 63:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 69:

    {osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 71:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 77:

    {osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 79:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 85:

    {osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 87:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 93:

    {osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 95:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 101:

    {osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 103:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 109:

    {osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 111:

    {	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	;}
    break;

  case 112:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other general results cannot be negative");
	osresult->setNumberOfOtherGeneralResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 113:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 114:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 121:

    {	parserData->kounter++;
;}
    break;

  case 122:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 123:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 126:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setGeneralOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 127:

    {	
		osresult->setGeneralOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 128:

    {	
		osresult->setGeneralOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 149:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 155:

    {osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 157:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 161:

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

  case 162:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 164:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 165:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 167:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 171:

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

  case 172:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 174:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 175:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 177:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 181:

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

  case 182:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 184:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 185:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 187:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 189:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 191:

    {osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 193:

    {	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	;}
    break;

  case 194:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other system results cannot be negative");
	osresult->setNumberOfOtherSystemResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 195:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 196:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 203:

    {	parserData->kounter++;
;}
    break;

  case 204:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 205:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 208:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setSystemOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 209:

    {	
		osresult->setSystemOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 210:

    {	
		osresult->setSystemOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 225:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 231:

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

  case 233:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 239:

    { osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 241:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 247:

    { osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 249:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 255:

    {osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 257:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 263:

    {osresult->setServiceUtilization( parserData->tempVal);  parserData->errorText = NULL;;}
    break;

  case 265:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	;}
    break;

  case 266:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other service results cannot be negative");
	osresult->setNumberOfOtherServiceResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 267:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 268:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 275:

    {	parserData->kounter++;
;}
    break;

  case 276:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 277:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 280:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setServiceOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 281:

    {	
		osresult->setServiceOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 282:

    {	
		osresult->setServiceOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 302:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 308:

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

  case 310:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 316:

    {osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 318:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 324:

    {osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 326:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 332:

    {osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 334:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 340:

    {osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 342:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 343:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
;}
    break;

  case 344:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <time> element");
	;}
    break;

  case 345:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, "fewer <time> elements than specified");
	;}
    break;

  case 353:

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

  case 356:

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

  case 357:

    {	if (parserData->typeAttribute != "cpuTime"     &&
			parserData->typeAttribute != "elapsedTime" &&
 			parserData->typeAttribute != "other"   )     
			osrlerror(NULL, NULL, parserData, "time type not recognized");
	;}
    break;

  case 358:

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

  case 365:

    {	osresult->addTimingInformation(parserData->typeAttribute, parserData->categoryAttribute,
		parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue);       
	parserData->ivar++;
	parserData->timeType = "";
	parserData->timeCategory = "";
	parserData->timeUnit = "";
	parserData->timeDescription = "";      
;}
    break;

  case 366:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 367:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 369:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 373:

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

  case 374:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 376:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 377:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 379:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 383:

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

  case 384:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 386:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 387:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 389:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 393:

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

  case 394:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 396:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 397:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 399:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 401:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 403:

    {osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 405:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	;}
    break;

  case 406:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other job results cannot be negative");
	osresult->setNumberOfOtherJobResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 407:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 408:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 415:

    {	parserData->kounter++;
;}
    break;

  case 416:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 417:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 420:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setJobOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 421:

    {	
		osresult->setJobOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 422:

    {	
		osresult->setJobOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 427:

    {	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
;}
    break;

  case 428:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, "numberOfSolutions was never set");
;}
    break;

  case 435:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfSolutions = (yyvsp[(3) - (4)].ival); 
	osresult->setSolutionNumber((yyvsp[(3) - (4)].ival));
	parserData->solutionIdx = 0;
;}
    break;

  case 436:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	parserData->nVarPresent = true;	
	parserData->numberOfVariables = (yyvsp[(3) - (4)].ival); 
	osresult->setVariableNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 437:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	parserData->nConPresent = true;		
	parserData->numberOfConstraints = (yyvsp[(3) - (4)].ival); 
	osresult->setConstraintNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 438:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	parserData->nObjPresent = true;
	parserData->numberOfObjectives = (yyvsp[(3) - (4)].ival); 
	osresult->setObjectiveNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 439:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solution> element");
	;}
    break;

  case 440:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, "fewer <solution> elements than specified");
	;}
    break;

  case 448:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 454:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 455:

    {	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval);
	if (parserData->tempStr != "true" && parserData->tempStr != "false")
		osrlerror(NULL, NULL, parserData, "weightedobjectives must be true or false");
  	osresult->setSolutionWeightedObjectives(parserData->solutionIdx, parserData->tempStr);
;}
    break;

  case 456:

    {
		parserData->solutionIdx++;
	;}
    break;

  case 458:

    {	parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
	;}
    break;

  case 459:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
	;}
    break;

  case 462:

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

  case 463:

    {   osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute);
	;}
    break;

  case 465:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for solution status element");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solution substatuses cannot be negative");
    osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 466:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 467:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 474:

    {	parserData->kounter++; ;}
    break;

  case 475:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 476:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
;}
    break;

  case 479:

    {	
		if (parserData->typeAttribute != "stoppedByLimit"  &&
			parserData->typeAttribute != "stoppedByBounds" &&
			parserData->typeAttribute != "other" )
		osrlerror(NULL, NULL, parserData, "substatus type attribute has bad value");
		osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
										   parserData->typeAttribute);	
	;}
    break;

  case 480:

    {	
		osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
												  parserData->descriptionAttribute);
	;}
    break;

  case 491:

    {	osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));
		parserData->errorText = NULL;
	;}
    break;

  case 494:

    {	parserData->numberOfOtherVariableResults = 0; ;}
    break;

  case 496:

    {	
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other variable results cannot be negative");
		osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->numberOfOtherVariableResults = (yyvsp[(3) - (4)].ival);
		parserData->iOther = 0;
	;}
    break;

  case 505:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
	osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 506:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 507:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 514:

    {	osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 515:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 516:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 518:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 519:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 523:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 524:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 525:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 532:

    {
	osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 			parserData->idx,         parserData->tempStr);
	parserData->kounter++;
;}
    break;

  case 533:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 534:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 535:

    {parserData->tempStr = "";;}
    break;

  case 540:

    {parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));;}
    break;

  case 544:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	osresult->setNumberOfBasisVar(parserData->solutionIdx, parserData->numberOfVar);
;}
    break;

  case 545:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 546:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 554:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 555:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 556:

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

  case 559:

    { 	 
		parserData->iOther++;
	;}
    break;

  case 560:

    {
	if (parserData->iOther >= parserData->numberOfOtherVariableResults)
		osrlerror(NULL, NULL, parserData, "more <otherVariableResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
;}
    break;

  case 561:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfVar attribute"); 
	;}
    break;

  case 565:

    {	
	 	osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 											  parserData->valueAttribute);
  ;}
    break;

  case 566:

    {	
	 	osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 											 parserData->nameAttribute);
  ;}
    break;

  case 567:

    {	
	 	osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 													parserData->descriptionAttribute);
  ;}
    break;

  case 568:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 577:

    { 	
	parserData->kounter++;
;}
    break;

  case 579:

    {	
 	osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 585:

    {	
	 	osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 588:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 590:

    {
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other objective results cannot be negative");
		parserData->numberOfOtherObjectiveResults = (yyvsp[(3) - (4)].ival);
        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 599:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj);
	parserData->kounter = 0;
;}
    break;

  case 600:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <obj> element");
	;}
    break;

  case 601:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, "fewer <obj> elements than specified");
	;}
    break;

  case 608:

    {	osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 609:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, "more <obj> elements than specified");
	parserData->idx = -1;
;}
    break;

  case 611:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 613:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 614:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 617:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 618:

    {
	if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
		osrlerror(NULL, NULL, parserData, "more <otherObjectiveResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
;}
    break;

  case 619:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfObj attribute"); 
	;}
    break;

  case 623:

    {	
	 	osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 											   parserData->valueAttribute);
  ;}
    break;

  case 624:

    {	
	  	osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 											  parserData->nameAttribute);
  ;}
    break;

  case 625:

    {	
	 	osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
 													 parserData->descriptionAttribute);
  ;}
    break;

  case 626:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 635:

    {  
	parserData->kounter++;
;}
    break;

  case 637:

    {	osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 643:

    {	osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 646:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 648:

    {
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other constraint results cannot be negative");
		parserData->numberOfOtherConstraintResults = (yyvsp[(3) - (4)].ival);
		osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 656:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 657:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon);
	parserData->kounter = 0;
;}
    break;

  case 658:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <con> element");
	;}
    break;

  case 659:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, "fewer <con> elements than specified");
	;}
    break;

  case 666:

    {	osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
						   parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 667:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, "more <con> elements than specified");
;}
    break;

  case 668:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 669:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 670:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 673:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 674:

    {
	if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
		osrlerror(NULL, NULL, parserData, "more <otherConstraintResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
;}
    break;

  case 675:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfCon attribute"); 
	;}
    break;

  case 679:

    {	
	 	osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 												parserData->valueAttribute);
  ;}
    break;

  case 680:

    {	
	 	osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 											   parserData->nameAttribute);
  ;}
    break;

  case 681:

    {	
	 	osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 													  parserData->descriptionAttribute);
  ;}
    break;

  case 682:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 691:

    { 	
	parserData->kounter++;
;}
    break;

  case 693:

    {	
 	osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 699:

    {	
	 	osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 702:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 703:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solution results cannot be negative");
    osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->iOther = 0; 
;}
    break;

  case 704:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <otherSolutionResult> element");
	;}
    break;

  case 705:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <otherSolutionResult> elements than specified");
	;}
    break;

  case 712:

    {	parserData->iOther++;
;}
    break;

  case 713:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 714:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have numberOfItems attribute");
;}
    break;

  case 717:

    {	
		osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
											 parserData->nameAttribute);
	;}
    break;

  case 718:

    {	
		osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
												 parserData->categoryAttribute);
	;}
    break;

  case 719:

    {	
		osresult->setOtherSolutionResultDescription(parserData->solutionIdx, parserData->iOther,
											 parserData->descriptionAttribute);
	;}
    break;

  case 721:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
	osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, parserData->iOther,
												  parserData->numberOfItems);
	parserData->kounter = 0;
;}
    break;

  case 722:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	;}
    break;

  case 723:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	;}
    break;

  case 730:

    {	parserData->kounter++;
;}
    break;

  case 731:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
;}
    break;

  case 736:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
										 parserData->kounter, parserData->itemContent);
;}
    break;

  case 739:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 740:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solver outputs cannot be negative");
    osresult->setNumberOfSolverOutputs((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->iOther = 0; 
;}
    break;

  case 741:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solverOutput> element");
	;}
    break;

  case 742:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <solverOutput> elements than specified");
	;}
    break;

  case 749:

    {	parserData->iOther++;
;}
    break;

  case 750:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <solverOutput> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 751:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have numberOfItems attribute");
;}
    break;

  case 755:

    {	
		osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute);
	;}
    break;

  case 756:

    {	
		osresult->setSolverOutputCategory(parserData->iOther, parserData->categoryAttribute);
	;}
    break;

  case 757:

    {	
		osresult->setSolverOutputDescription(parserData->iOther, parserData->descriptionAttribute);
	;}
    break;

  case 758:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
	osresult->setSolverOutputNumberOfItems(parserData->iOther, parserData->numberOfItems);
	parserData->kounter = 0;
;}
    break;

  case 759:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	;}
    break;

  case 760:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	;}
    break;

  case 767:

    {	parserData->kounter++;
;}
    break;

  case 768:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
;}
    break;

  case 772:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
	osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, parserData->itemContent);
;}
    break;

  case 773:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 776:

    { parserData->categoryAttribute = ""; ;}
    break;

  case 777:

    { parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 778:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 781:

    { parserData->descriptionAttribute = ""; ;}
    break;

  case 782:

    { parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 783:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 786:

    { parserData->nameAttribute = ""; ;}
    break;

  case 787:

    { parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 788:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 791:

    { parserData->typeAttribute = ""; ;}
    break;

  case 792:

    { parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 793:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 796:

    { parserData->unitAttribute = ""; ;}
    break;

  case 797:

    { parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 798:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 801:

    { parserData->valueAttribute = ""; ;}
    break;

  case 802:

    { parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 803:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 804:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 805:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 806:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 807:

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


