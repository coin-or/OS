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
     INTEGER = 260,
     DOUBLE = 261,
     QUOTE = 262,
     TWOQUOTES = 263,
     GREATERTHAN = 264,
     ENDOFELEMENT = 265,
     OSRLSTART = 266,
     OSRLSTARTEMPTY = 267,
     OSRLATTRIBUTETEXT = 268,
     OSRLEND = 269,
     GENERALSTART = 270,
     GENERALEND = 271,
     SYSTEMSTART = 272,
     SYSTEMEND = 273,
     SERVICESTART = 274,
     SERVICEEND = 275,
     JOBSTART = 276,
     JOBEND = 277,
     SERVICEURISTARTANDEND = 278,
     SERVICEURISTART = 279,
     SERVICEURIEND = 280,
     SERVICENAMESTARTANDEND = 281,
     SERVICENAMESTART = 282,
     SERVICENAMEEND = 283,
     INSTANCENAMESTARTANDEND = 284,
     INSTANCENAMESTART = 285,
     INSTANCENAMEEND = 286,
     JOBIDSTARTANDEND = 287,
     JOBIDSTART = 288,
     JOBIDEND = 289,
     TIMINGINFORMATIONSTART = 290,
     TIMINGINFORMATIONEND = 291,
     TIMESTARTANDEND = 292,
     TIMESTART = 293,
     TIMEEND = 294,
     OPTIMIZATIONSTART = 295,
     OPTIMIZATIONEND = 296,
     SOLUTIONSTART = 297,
     SOLUTIONEND = 298,
     VALUESSTART = 299,
     VALUESEND = 300,
     DUALVALUESSTART = 301,
     DUALVALUESEND = 302,
     VARIABLESSTART = 303,
     VARIABLESEND = 304,
     VARSTART = 305,
     VAREND = 306,
     OBJECTIVESSTART = 307,
     OBJECTIVESEND = 308,
     OBJSTART = 309,
     OBJEND = 310,
     CONSTRAINTSSTART = 311,
     CONSTRAINTSEND = 312,
     CONSTART = 313,
     CONEND = 314,
     STATUSSTART = 315,
     STATUSEND = 316,
     GENERALSTATUSSTART = 317,
     GENERALSTATUSEND = 318,
     MESSAGESTART = 319,
     MESSAGEEND = 320,
     MESSAGESTARTANDEND = 321,
     OTHERSTART = 322,
     OTHEREND = 323,
     NUMBEROFTIMESATT = 324,
     NUMBEROFSOLUTIONSATT = 325,
     NUMBEROFVARIABLESATT = 326,
     NUMBEROFCONSTRAINTSATT = 327,
     NUMBEROFOBJECTIVESATT = 328,
     NUMBEROFOTHERVARIABLERESULTSATT = 329,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 330,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 331,
     NUMBEROFOTHERSOLUTIONRESULTSATT = 332,
     NUMBEROFRECORDSATT = 333,
     OTHERSOLUTIONRESULTSSTART = 334,
     OTHERSOLUTIONRESULTSEND = 335,
     OTHERSOLUTIONRESULTSTART = 336,
     OTHERSOLUTIONRESULTEND = 337,
     RECORDSTART = 338,
     RECORDEND = 339,
     NUMBEROFVARATT = 340,
     NUMBEROFOBJATT = 341,
     NUMBEROFCONATT = 342,
     TARGETOBJECTIVEIDXATT = 343,
     IDXATT = 344,
     TYPEATT = 345,
     EMPTYTYPEATT = 346,
     DESCRIPTIONATT = 347,
     EMPTYDESCRIPTIONATT = 348,
     NAMEATT = 349,
     EMPTYNAMEATT = 350,
     CATEGORYATT = 351,
     EMPTYCATEGORYATT = 352,
     UNITATT = 353,
     EMPTYUNITATT = 354,
     VALUEATT = 355,
     EMPTYVALUEATT = 356,
     DUMMY = 357
   };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define INTEGER 260
#define DOUBLE 261
#define QUOTE 262
#define TWOQUOTES 263
#define GREATERTHAN 264
#define ENDOFELEMENT 265
#define OSRLSTART 266
#define OSRLSTARTEMPTY 267
#define OSRLATTRIBUTETEXT 268
#define OSRLEND 269
#define GENERALSTART 270
#define GENERALEND 271
#define SYSTEMSTART 272
#define SYSTEMEND 273
#define SERVICESTART 274
#define SERVICEEND 275
#define JOBSTART 276
#define JOBEND 277
#define SERVICEURISTARTANDEND 278
#define SERVICEURISTART 279
#define SERVICEURIEND 280
#define SERVICENAMESTARTANDEND 281
#define SERVICENAMESTART 282
#define SERVICENAMEEND 283
#define INSTANCENAMESTARTANDEND 284
#define INSTANCENAMESTART 285
#define INSTANCENAMEEND 286
#define JOBIDSTARTANDEND 287
#define JOBIDSTART 288
#define JOBIDEND 289
#define TIMINGINFORMATIONSTART 290
#define TIMINGINFORMATIONEND 291
#define TIMESTARTANDEND 292
#define TIMESTART 293
#define TIMEEND 294
#define OPTIMIZATIONSTART 295
#define OPTIMIZATIONEND 296
#define SOLUTIONSTART 297
#define SOLUTIONEND 298
#define VALUESSTART 299
#define VALUESEND 300
#define DUALVALUESSTART 301
#define DUALVALUESEND 302
#define VARIABLESSTART 303
#define VARIABLESEND 304
#define VARSTART 305
#define VAREND 306
#define OBJECTIVESSTART 307
#define OBJECTIVESEND 308
#define OBJSTART 309
#define OBJEND 310
#define CONSTRAINTSSTART 311
#define CONSTRAINTSEND 312
#define CONSTART 313
#define CONEND 314
#define STATUSSTART 315
#define STATUSEND 316
#define GENERALSTATUSSTART 317
#define GENERALSTATUSEND 318
#define MESSAGESTART 319
#define MESSAGEEND 320
#define MESSAGESTARTANDEND 321
#define OTHERSTART 322
#define OTHEREND 323
#define NUMBEROFTIMESATT 324
#define NUMBEROFSOLUTIONSATT 325
#define NUMBEROFVARIABLESATT 326
#define NUMBEROFCONSTRAINTSATT 327
#define NUMBEROFOBJECTIVESATT 328
#define NUMBEROFOTHERVARIABLERESULTSATT 329
#define NUMBEROFOTHEROBJECTIVERESULTSATT 330
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 331
#define NUMBEROFOTHERSOLUTIONRESULTSATT 332
#define NUMBEROFRECORDSATT 333
#define OTHERSOLUTIONRESULTSSTART 334
#define OTHERSOLUTIONRESULTSEND 335
#define OTHERSOLUTIONRESULTSTART 336
#define OTHERSOLUTIONRESULTEND 337
#define RECORDSTART 338
#define RECORDEND 339
#define NUMBEROFVARATT 340
#define NUMBEROFOBJATT 341
#define NUMBEROFCONATT 342
#define TARGETOBJECTIVEIDXATT 343
#define IDXATT 344
#define TYPEATT 345
#define EMPTYTYPEATT 346
#define DESCRIPTIONATT 347
#define EMPTYDESCRIPTIONATT 348
#define NAMEATT 349
#define EMPTYNAMEATT 350
#define CATEGORYATT 351
#define EMPTYCATEGORYATT 352
#define UNITATT 353
#define EMPTYUNITATT 354
#define VALUEATT 355
#define EMPTYVALUEATT 356
#define DUMMY 357




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
/* Line 187 of yacc.c.  */

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



void osrlerror(YYLTYPE* type, OSResult *osresult,  OSrLParserData *parserData ,const char* errormsg ) ;
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
#define YYLAST   318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  190
/* YYNRULES -- Number of states.  */
#define YYNSTATES  354

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   357

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   104,
     106,     2,     2,   105,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   103,     2,     2,     2,     2,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101,   102
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    11,    14,    18,    19,    28,    33,    37,
      39,    42,    46,    48,    52,    54,    55,    57,    61,    64,
      65,    67,    71,    74,    75,    77,    81,    84,    85,    87,
      91,    94,    95,    97,   101,   104,   105,   108,   109,   112,
     113,   117,   118,   122,   127,   129,   133,   134,   137,   139,
     145,   146,   149,   151,   153,   155,   157,   161,   163,   167,
     169,   173,   175,   179,   181,   183,   185,   186,   190,   193,
     195,   198,   199,   202,   205,   208,   211,   214,   218,   222,
     226,   230,   231,   234,   235,   247,   248,   253,   258,   262,
     264,   267,   271,   273,   277,   279,   280,   284,   287,   288,
     299,   300,   305,   310,   312,   315,   321,   323,   325,   329,
     330,   333,   339,   341,   342,   345,   347,   349,   351,   353,
     358,   360,   364,   366,   370,   374,   375,   378,   384,   386,
     388,   390,   392,   393,   403,   408,   409,   412,   418,   424,
     428,   429,   430,   441,   446,   448,   451,   457,   463,   467,
     471,   472,   474,   475,   477,   478,   484,   485,   491,   492,
     495,   501,   502,   503,   507,   509,   511,   513,   515,   520,
     522,   526,   530,   532,   536,   538,   539,   542,   545,   547,
     548,   552,   554,   557,   559,   562,   564,   566,   568,   570,
     571
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     108,     0,    -1,   109,   110,   119,   120,   121,   134,    14,
      -1,    11,     9,    -1,    11,    13,     9,    -1,    -1,    15,
     111,   114,   115,   116,   117,   118,    16,    -1,    62,   112,
       9,    63,    -1,    62,   112,    10,    -1,   113,    -1,   112,
     113,    -1,    90,     3,   203,    -1,    91,    -1,    92,     3,
     203,    -1,    93,    -1,    -1,    23,    -1,    24,     4,    25,
      -1,    24,    25,    -1,    -1,    26,    -1,    27,     4,    28,
      -1,    27,    28,    -1,    -1,    29,    -1,    30,     4,    31,
      -1,    30,    31,    -1,    -1,    32,    -1,    33,     4,    34,
      -1,    33,    34,    -1,    -1,    66,    -1,    64,     4,    65,
      -1,    64,    65,    -1,    -1,    17,    18,    -1,    -1,    19,
      20,    -1,    -1,    21,   122,    22,    -1,    -1,    35,   123,
     124,    -1,    69,     7,     5,     7,    -1,    10,    -1,     9,
     125,    36,    -1,    -1,   125,   126,    -1,    37,    -1,    38,
     127,     9,   133,    39,    -1,    -1,   127,   128,    -1,   129,
      -1,   130,    -1,   131,    -1,   132,    -1,    90,     3,     7,
      -1,    91,    -1,    96,     3,     7,    -1,    97,    -1,    98,
       3,     7,    -1,    99,    -1,    92,     3,     7,    -1,    93,
      -1,     6,    -1,     5,    -1,    -1,    40,   135,    41,    -1,
     137,   136,    -1,    10,    -1,     9,   143,    -1,    -1,   137,
     138,    -1,   139,   203,    -1,   140,   203,    -1,   141,   203,
      -1,   142,   203,    -1,    70,   203,     5,    -1,    71,   203,
       5,    -1,    72,   203,     5,    -1,    73,   203,     5,    -1,
      -1,   143,   144,    -1,    -1,    42,   145,   146,     9,   147,
     150,   151,   171,   176,   185,   202,    -1,    -1,    88,   203,
       5,   203,    -1,    60,   148,     9,    61,    -1,    60,   148,
      10,    -1,   149,    -1,   148,   149,    -1,    90,     3,   203,
      -1,    91,    -1,    92,     3,   203,    -1,    93,    -1,    -1,
      64,     4,    65,    -1,    64,    65,    -1,    -1,    48,   152,
       9,    44,   153,     9,   154,    45,   158,    49,    -1,    -1,
      74,   203,     5,   203,    -1,    85,   203,     5,   203,    -1,
     155,    -1,   154,   155,    -1,    50,   157,     9,   156,    51,
      -1,     5,    -1,     6,    -1,    89,     5,   203,    -1,    -1,
     158,   159,    -1,   160,   161,     9,   167,    68,    -1,    67,
      -1,    -1,   162,   161,    -1,   163,    -1,   164,    -1,   165,
      -1,   166,    -1,    85,   203,     5,   203,    -1,   101,    -1,
     100,     3,   203,    -1,    95,    -1,    94,     3,   203,    -1,
      92,     3,   203,    -1,    -1,   168,   167,    -1,   170,   182,
       9,   169,    51,    -1,     4,    -1,     5,    -1,     6,    -1,
      50,    -1,    -1,    52,     9,    44,   172,     9,   173,    45,
     183,    53,    -1,    86,   203,     5,   203,    -1,    -1,   173,
     174,    -1,    54,   175,     9,     6,    55,    -1,    54,   175,
       9,     5,    55,    -1,    89,     5,   203,    -1,    -1,    -1,
      56,     9,    46,   178,   177,     9,   179,    47,   184,    57,
      -1,    87,   203,     5,   203,    -1,   180,    -1,   179,   180,
      -1,    58,   181,     9,     6,    59,    -1,    58,   181,     9,
       5,    59,    -1,    89,     5,   203,    -1,    89,     5,   203,
      -1,    -1,   102,    -1,    -1,   102,    -1,    -1,    79,   186,
       9,   188,    80,    -1,    -1,    77,     7,     5,   187,     7,
      -1,    -1,   188,   189,    -1,    81,   190,     9,   197,    82,
      -1,    -1,    -1,   190,   191,   192,    -1,   193,    -1,   194,
      -1,   195,    -1,   196,    -1,    78,     7,     5,     7,    -1,
      95,    -1,    94,     3,   203,    -1,    96,     3,     7,    -1,
      97,    -1,    92,     3,     7,    -1,    93,    -1,    -1,   197,
     198,    -1,    83,   199,    -1,   201,    -1,    -1,     4,   200,
      84,    -1,    10,    -1,     9,    84,    -1,    43,    -1,   205,
       7,    -1,   103,    -1,   104,    -1,   105,    -1,   106,    -1,
      -1,   205,   204,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   126,   127,   131,   131,   133,   134,   136,
     137,   139,   140,   141,   142,   145,   146,   147,   148,   151,
     152,   153,   154,   156,   157,   158,   159,   161,   162,   163,
     164,   166,   167,   168,   169,   171,   171,   173,   173,   175,
     175,   177,   178,   180,   186,   186,   188,   188,   190,   191,
     203,   203,   205,   205,   205,   205,   207,   208,   210,   211,
     213,   214,   216,   217,   220,   221,   223,   223,   225,   228,
     229,   231,   232,   234,   235,   236,   237,   241,   242,   243,
     244,   247,   248,   251,   251,   258,   259,   265,   266,   269,
     270,   272,   273,   274,   275,   277,   278,   282,   288,   289,
     300,   301,   311,   318,   319,   321,   324,   329,   335,   339,
     340,   342,   361,   370,   373,   375,   375,   375,   375,   377,
     386,   389,   395,   401,   407,   416,   417,   419,   436,   437,
     438,   440,   445,   446,   455,   459,   460,   462,   468,   476,
     479,   481,   480,   498,   504,   505,   507,   514,   522,   524,
     528,   529,   531,   532,   534,   535,   542,   541,   557,   559,
     561,   571,   572,   572,   576,   576,   576,   576,   578,   597,
     603,   611,   614,   617,   620,   622,   623,   625,   635,   636,
     636,   638,   638,   641,   649,   651,   652,   653,   654,   656,
     657
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "GREATERTHAN", "ENDOFELEMENT",
  "OSRLSTART", "OSRLSTARTEMPTY", "OSRLATTRIBUTETEXT", "OSRLEND",
  "GENERALSTART", "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART",
  "SERVICEEND", "JOBSTART", "JOBEND", "SERVICEURISTARTANDEND",
  "SERVICEURISTART", "SERVICEURIEND", "SERVICENAMESTARTANDEND",
  "SERVICENAMESTART", "SERVICENAMEEND", "INSTANCENAMESTARTANDEND",
  "INSTANCENAMESTART", "INSTANCENAMEEND", "JOBIDSTARTANDEND", "JOBIDSTART",
  "JOBIDEND", "TIMINGINFORMATIONSTART", "TIMINGINFORMATIONEND",
  "TIMESTARTANDEND", "TIMESTART", "TIMEEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "SOLUTIONSTART", "SOLUTIONEND", "VALUESSTART",
  "VALUESEND", "DUALVALUESSTART", "DUALVALUESEND", "VARIABLESSTART",
  "VARIABLESEND", "VARSTART", "VAREND", "OBJECTIVESSTART", "OBJECTIVESEND",
  "OBJSTART", "OBJEND", "CONSTRAINTSSTART", "CONSTRAINTSEND", "CONSTART",
  "CONEND", "STATUSSTART", "STATUSEND", "GENERALSTATUSSTART",
  "GENERALSTATUSEND", "MESSAGESTART", "MESSAGEEND", "MESSAGESTARTANDEND",
  "OTHERSTART", "OTHEREND", "NUMBEROFTIMESATT", "NUMBEROFSOLUTIONSATT",
  "NUMBEROFVARIABLESATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFOBJECTIVESATT", "NUMBEROFOTHERVARIABLERESULTSATT",
  "NUMBEROFOTHEROBJECTIVERESULTSATT", "NUMBEROFOTHERCONSTRAINTRESULTSATT",
  "NUMBEROFOTHERSOLUTIONRESULTSATT", "NUMBEROFRECORDSATT",
  "OTHERSOLUTIONRESULTSSTART", "OTHERSOLUTIONRESULTSEND",
  "OTHERSOLUTIONRESULTSTART", "OTHERSOLUTIONRESULTEND", "RECORDSTART",
  "RECORDEND", "NUMBEROFVARATT", "NUMBEROFOBJATT", "NUMBEROFCONATT",
  "TARGETOBJECTIVEIDXATT", "IDXATT", "TYPEATT", "EMPTYTYPEATT",
  "DESCRIPTIONATT", "EMPTYDESCRIPTIONATT", "NAMEATT", "EMPTYNAMEATT",
  "CATEGORYATT", "EMPTYCATEGORYATT", "UNITATT", "EMPTYUNITATT", "VALUEATT",
  "EMPTYVALUEATT", "DUMMY", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
  "osrldoc", "osrlstart", "generalElement", "generalStatus",
  "anotherGeneralStatusATT", "generalstatusatt", "serviceURI",
  "serviceName", "instanceName", "jobID", "headerMessage", "systemElement",
  "serviceElement", "jobElement", "timingInformation", "numberoftimes",
  "timingContent", "listOfTimes", "time", "timeAttList", "timeAtt",
  "timeType", "timeCategory", "timeUnit", "timeDescription", "timeValue",
  "optimizationElement", "optimizationContent", "optend", "anotherOptATT",
  "optatt", "optnumsolatt", "optnumvaratt", "optnumconatt", "optnumobjatt",
  "solution", "anothersolution", "@1", "targetObjectiveIDXATT", "status",
  "anotherStatusATT", "statusatt", "message", "variables",
  "numberOfOtherVariableResults", "numberOfVarATT", "var", "anothervar",
  "DoubleOrInt", "aVARIDXATT", "otherVariables", "otherVariableResult",
  "otherVariableStart", "otherVariableATTlist", "othervariableATT",
  "numberOfOtherVarATT", "otherVarValueATT", "otherVarNameATT",
  "otherVarDescriptionATT", "othervarlist", "othervar", "ElementValue",
  "othervarstart", "objectives", "numberOfObjATT", "obj", "anotherobj",
  "anOBJIDXATT", "constraints", "@2", "numberOfConATT", "con",
  "anothercon", "aCONIDXATT", "anIDXATT", "otherObjectives",
  "otherConstraints", "otherSolutionResults",
  "numberOfOtherSolutionResults", "@3", "otherSolutionResultList",
  "anotherSolutionResult", "anotherSolutionResultAttList", "@4",
  "anotherSolutionResultAtt", "numberOfRecords",
  "anotherSolutionResultNameATT", "anotherSolutionResultCategoryATT",
  "anotherSolutionDescriptionATT", "recordList", "anotherSolutionRecord",
  "recordContent", "@5", "emptyRecord", "solutionEnd", "quote",
  "xmlWhiteSpaceChar", "xmlWhiteSpace", 0
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
     355,   356,   357,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   113,   113,   113,   113,   114,   114,   114,   114,   115,
     115,   115,   115,   116,   116,   116,   116,   117,   117,   117,
     117,   118,   118,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   136,
     136,   137,   137,   138,   138,   138,   138,   139,   140,   141,
     142,   143,   143,   145,   144,   146,   146,   147,   147,   148,
     148,   149,   149,   149,   149,   150,   150,   150,   151,   151,
     152,   152,   153,   154,   154,   155,   156,   156,   157,   158,
     158,   159,   160,   161,   161,   162,   162,   162,   162,   163,
     164,   164,   165,   165,   166,   167,   167,   168,   169,   169,
     169,   170,   171,   171,   172,   173,   173,   174,   174,   175,
     176,   177,   176,   178,   179,   179,   180,   180,   181,   182,
     183,   183,   184,   184,   185,   185,   187,   186,   188,   188,
     189,   190,   191,   190,   192,   192,   192,   192,   193,   194,
     194,   195,   195,   196,   196,   197,   197,   198,   199,   200,
     199,   201,   201,   202,   203,   204,   204,   204,   204,   205,
     205
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     3,     0,     8,     4,     3,     1,
       2,     3,     1,     3,     1,     0,     1,     3,     2,     0,
       1,     3,     2,     0,     1,     3,     2,     0,     1,     3,
       2,     0,     1,     3,     2,     0,     2,     0,     2,     0,
       3,     0,     3,     4,     1,     3,     0,     2,     1,     5,
       0,     2,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     0,     3,     2,     1,
       2,     0,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     0,     2,     0,    11,     0,     4,     4,     3,     1,
       2,     3,     1,     3,     1,     0,     3,     2,     0,    10,
       0,     4,     4,     1,     2,     5,     1,     1,     3,     0,
       2,     5,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     3,     0,     2,     5,     1,     1,
       1,     1,     0,     9,     4,     0,     2,     5,     5,     3,
       0,     0,    10,     4,     1,     2,     5,     5,     3,     3,
       0,     1,     0,     1,     0,     5,     0,     5,     0,     2,
       5,     0,     0,     3,     1,     1,     1,     1,     4,     1,
       3,     3,     1,     3,     1,     0,     2,     2,     1,     0,
       3,     1,     2,     1,     2,     1,     1,     1,     1,     0,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    35,     4,
       0,    15,     0,    37,     0,    12,     0,    14,     0,     9,
      16,     0,    19,    36,     0,    39,   189,   189,     0,     8,
      10,     0,    18,    20,     0,    23,    38,    41,    66,    11,
       0,    13,     7,    17,     0,    22,    24,     0,    27,     0,
       0,    71,     0,   184,   185,   186,   187,   188,   190,    21,
       0,    26,    28,     0,    31,     0,     0,    40,     0,     0,
       2,    25,     0,    30,     0,    32,     0,     0,    46,    44,
      42,    67,    81,    69,   189,   189,   189,   189,    68,    72,
     189,   189,   189,   189,    29,     0,    34,     6,     0,     0,
      70,     0,     0,     0,     0,    73,    74,    75,    76,    33,
      43,    45,    48,    50,    47,    83,    82,    77,    78,    79,
      80,     0,    85,     0,     0,    57,     0,    63,     0,    59,
       0,    61,    51,    52,    53,    54,    55,   189,     0,    65,
      64,     0,     0,     0,     0,     0,     0,     0,    49,    56,
      62,    58,    60,   189,     0,    95,    86,     0,    92,     0,
      94,     0,    89,     0,    98,   189,   189,     0,    88,    90,
       0,    97,   100,   132,    91,    93,    87,    96,   189,     0,
       0,   140,     0,     0,     0,     0,   154,   189,     0,     0,
       0,     0,     0,   101,   189,     0,   189,     0,     0,     0,
       0,   183,    84,     0,     0,     0,   135,   189,   141,     0,
     158,   189,     0,     0,   103,   189,     0,     0,     0,   156,
       0,   102,     0,     0,   109,   104,   134,   150,     0,   136,
     189,     0,     0,   155,   161,   159,   189,     0,     0,   151,
       0,     0,     0,   143,     0,     0,   144,   157,   162,   108,
     106,   107,     0,    99,   112,   110,   113,   133,   189,     0,
       0,     0,   152,   145,   175,     0,   105,   189,     0,     0,
     122,     0,   120,     0,   113,   115,   116,   117,   118,   139,
       0,     0,   189,     0,   153,     0,     0,     0,     0,   174,
       0,   169,     0,   172,   163,   164,   165,   166,   167,     0,
     189,   189,   189,   125,   114,   138,   137,   148,     0,     0,
     142,   160,     0,   176,     0,     0,   189,     0,   189,   124,
     123,   121,   131,     0,   125,     0,   147,   146,   179,     0,
     181,   177,   178,     0,   173,   170,   171,   119,   111,   126,
       0,     0,     0,   182,   168,   189,     0,   180,   149,   128,
     129,   130,     0,   127
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    11,    18,    19,    22,    35,    48,
      64,    76,    13,    25,    38,    50,    66,    80,    99,   114,
     121,   132,   133,   134,   135,   136,   141,    52,    68,    88,
      69,    89,    90,    91,    92,    93,   100,   116,   122,   138,
     155,   161,   162,   164,   173,   179,   195,   213,   214,   252,
     223,   238,   255,   256,   273,   274,   275,   276,   277,   278,
     323,   324,   352,   325,   181,   197,   216,   229,   242,   186,
     218,   208,   245,   246,   261,   341,   240,   285,   192,   200,
     232,   220,   235,   248,   265,   294,   295,   296,   297,   298,
     286,   313,   331,   342,   332,   202,    39,    58,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int16 yypact[] =
{
       8,    37,    39,    33,   -76,    72,   -76,   -11,    56,   -76,
     -75,    64,    91,    96,   124,   -76,   125,   -76,     3,   -76,
     -76,     5,    35,   -76,   109,   110,   -76,   -76,    67,   -76,
     -76,   107,   -76,   -76,     1,    76,   -76,    98,    94,   -76,
      -6,   -76,   -76,   -76,   112,   -76,   -76,     0,    75,    66,
     114,   -76,   123,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     111,   -76,   -76,    -1,    16,   134,   102,   -76,   103,    -3,
     -76,   -76,   116,   -76,     6,   -76,   127,   140,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,    81,   -76,   -76,   141,    38,
     105,   144,   147,   148,   149,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,    -7,    68,   108,   152,   -76,   154,   -76,   155,   -76,
     156,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   153,   -76,
     -76,   122,   157,   158,   159,   161,   165,   118,   -76,   -76,
     -76,   -76,   -76,   -76,   -37,    99,   -76,   168,   -76,   169,
     -76,    11,   -76,     7,   126,   -76,   -76,   120,   -76,   -76,
     121,   -76,   101,   130,   -76,   -76,   -76,   -76,   -76,   164,
     167,   129,   172,   135,   139,   178,   119,   -76,   104,   106,
     145,   128,   150,   -76,   -76,   181,   -76,   185,   131,   188,
     187,   -76,   -76,   192,   151,   194,   -76,   -76,   -76,   195,
     -76,   -76,   132,     2,   -76,   -76,    -5,   197,   198,   -76,
      36,   -76,   199,   201,   -76,   -76,   -76,   133,   136,   -76,
     -76,   162,   204,   -76,   -76,   -76,   -76,   113,   -35,   -76,
     160,   203,   205,   -76,   137,   -13,   -76,   -76,   206,   -76,
     -76,   -76,   166,   -76,   -76,   -76,   -57,   -76,   -76,   115,
     207,   210,   142,   -76,   -76,   -70,   -76,   -76,   213,   219,
     -76,   220,   -76,   215,   -57,   -76,   -76,   -76,   -76,   -76,
     173,   174,   -76,   117,   -76,   170,    42,   223,   229,   -76,
     230,   -76,   231,   -76,   -76,   -76,   -76,   -76,   -76,   232,
     -76,   -76,   -76,   186,   -76,   -76,   -76,   -76,   179,   180,
     -76,   -76,    32,   -76,   236,   235,   -76,   238,   -76,   -76,
     -76,   -76,   -76,   138,   186,   163,   -76,   -76,   -76,   175,
     -76,   -76,   -76,   239,   -76,   -76,   -76,   -76,   -76,   -76,
     242,   234,   176,   -76,   -76,   -76,    73,   -76,   -76,   -76,
     -76,   -76,   200,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   -76,   -76,   -76,   240,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,    87,   -76,   -76,   -76,   -76,   -76,    40,   -76,
     -76,   -76,   -76,   -76,   -25,   -76,   -76,   -76,   -76,   -76,
     -74,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,     9,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -27,   -76,   -76
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      41,    53,   123,    72,    60,    44,    82,    83,   287,    31,
      95,   170,    28,    29,   253,    14,    15,    16,    17,     1,
     167,   168,   288,   289,   290,   291,   292,   293,   267,    45,
      32,    61,   254,    73,   262,   268,   328,   269,   270,     6,
     227,   329,   330,   271,   272,   244,     4,   224,     7,   228,
       5,    10,   212,   157,   158,   159,   160,   101,   102,   103,
     104,    33,    34,   105,   106,   107,   108,    84,    85,    86,
      87,    96,   171,    12,   111,   112,   113,   349,   350,   351,
      74,     9,    75,   124,   125,   126,   127,    20,    21,   128,
     129,   130,   131,    14,    15,    16,    17,    54,    55,    56,
      57,   157,   158,   159,   160,    46,    47,    62,    63,    23,
     146,    78,    79,   139,   140,    24,   233,   234,   250,   251,
     280,   281,   308,   309,   311,   312,   156,    26,    27,    36,
      42,    37,    43,    49,    51,    65,    67,    70,   174,   175,
      59,    77,    71,    97,    81,    98,   109,   115,   110,   117,
      94,   182,   118,   119,   120,   142,   137,   143,   144,   145,
     193,   148,   147,   163,   149,   150,   151,   203,   152,   205,
     153,   165,   166,   183,   172,   178,   184,   187,   154,   188,
     217,   176,   180,   189,   221,   185,   177,   190,   226,   194,
     204,   198,   196,   201,   206,   209,   210,   211,   191,   215,
     219,   212,   230,   243,   236,   199,   338,   231,   258,   249,
     237,   247,   282,   257,   259,   264,   300,   266,   207,   283,
     244,   222,   301,   302,   303,   241,   260,   310,   305,   306,
     314,   279,   315,   316,   317,   239,   322,   318,   326,   327,
     299,   333,   334,   346,   284,   336,   344,   345,   169,   304,
     339,   353,   340,   225,   263,   307,     0,     0,    30,   343,
     347,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,   320,   321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   335,
       0,   337,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   348
};

static const yytype_int16 yycheck[] =
{
      27,     7,     9,     4,     4,     4,     9,    10,    78,     4,
       4,     4,     9,    10,    49,    90,    91,    92,    93,    11,
       9,    10,    92,    93,    94,    95,    96,    97,    85,    28,
      25,    31,    67,    34,    47,    92,     4,    94,    95,     0,
      45,     9,    10,   100,   101,    58,     9,    45,    15,    54,
      13,    62,    50,    90,    91,    92,    93,    84,    85,    86,
      87,    26,    27,    90,    91,    92,    93,    70,    71,    72,
      73,    65,    65,    17,    36,    37,    38,     4,     5,     6,
      64,     9,    66,    90,    91,    92,    93,    23,    24,    96,
      97,    98,    99,    90,    91,    92,    93,   103,   104,   105,
     106,    90,    91,    92,    93,    29,    30,    32,    33,    18,
     137,     9,    10,     5,     6,    19,    80,    81,     5,     6,
       5,     6,     5,     6,    82,    83,   153,     3,     3,    20,
      63,    21,    25,    35,    40,    69,    22,    14,   165,   166,
      28,     7,    31,    16,    41,     5,    65,    42,     7,     5,
      34,   178,     5,     5,     5,     3,    88,     3,     3,     3,
     187,    39,     9,    64,     7,     7,     7,   194,     7,   196,
       5,     3,     3,     9,    48,    74,     9,     5,    60,    44,
     207,    61,    52,    44,   211,    56,    65,     9,   215,    85,
       9,    46,    86,    43,     9,     7,     9,     5,    79,     5,
       5,    50,     5,   230,     5,    77,    68,     9,     5,   236,
       9,     7,     5,    53,     9,     9,     3,    51,    87,     9,
      58,    89,     3,     3,     9,    89,    89,    57,    55,    55,
       7,   258,     3,     3,     3,   102,    50,     5,    59,    59,
     267,     5,     7,     9,   102,     7,     7,     5,   161,   274,
     324,    51,    89,   213,   245,   282,    -1,    -1,    18,    84,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   300,   301,   302,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   316,
      -1,   318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   345
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,   108,   109,     9,    13,     0,    15,   110,     9,
      62,   111,    17,   119,    90,    91,    92,    93,   112,   113,
      23,    24,   114,    18,    19,   120,     3,     3,     9,    10,
     113,     4,    25,    26,    27,   115,    20,    21,   121,   203,
     205,   203,    63,    25,     4,    28,    29,    30,   116,    35,
     122,    40,   134,     7,   103,   104,   105,   106,   204,    28,
       4,    31,    32,    33,   117,    69,   123,    22,   135,   137,
      14,    31,     4,    34,    64,    66,   118,     7,     9,    10,
     124,    41,     9,    10,    70,    71,    72,    73,   136,   138,
     139,   140,   141,   142,    34,     4,    65,    16,     5,   125,
     143,   203,   203,   203,   203,   203,   203,   203,   203,    65,
       7,    36,    37,    38,   126,    42,   144,     5,     5,     5,
       5,   127,   145,     9,    90,    91,    92,    93,    96,    97,
      98,    99,   128,   129,   130,   131,   132,    88,   146,     5,
       6,   133,     3,     3,     3,     3,   203,     9,    39,     7,
       7,     7,     7,     5,    60,   147,   203,    90,    91,    92,
      93,   148,   149,    64,   150,     3,     3,     9,    10,   149,
       4,    65,    48,   151,   203,   203,    61,    65,    74,   152,
      52,   171,   203,     9,     9,    56,   176,     5,    44,    44,
       9,    79,   185,   203,    85,   153,    86,   172,    46,    77,
     186,    43,   202,   203,     9,   203,     9,    87,   178,     7,
       9,     5,    50,   154,   155,     5,   173,   203,   177,     5,
     188,   203,    89,   157,    45,   155,   203,    45,    54,   174,
       5,     9,   187,    80,    81,   189,     5,     9,   158,   102,
     183,    89,   175,   203,    58,   179,   180,     7,   190,   203,
       5,     6,   156,    49,    67,   159,   160,    53,     5,     9,
      89,   181,    47,   180,     9,   191,    51,    85,    92,    94,
      95,   100,   101,   161,   162,   163,   164,   165,   166,   203,
       5,     6,     5,     9,   102,   184,   197,    78,    92,    93,
      94,    95,    96,    97,   192,   193,   194,   195,   196,   203,
       3,     3,     3,     9,   161,    55,    55,   203,     5,     6,
      57,    82,    83,   198,     7,     3,     3,     3,     5,   203,
     203,   203,    50,   167,   168,   170,    59,    59,     4,     9,
      10,   199,   201,     5,     7,   203,     7,   203,    68,   167,
      89,   182,   200,    84,     7,     5,     9,    84,   203,     4,
       5,     6,   169,    51
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
        case 7:

    {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, parserData, "a type attribute required for generalStatus element");}
    break;

  case 8:

    {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, parserData, "a type attribute required for generalStatus element"); parserData->generalStatusTypePresent = false;}
    break;

  case 11:

    { osresult->setGeneralStatusType((yyvsp[(2) - (3)].sval));  free((yyvsp[(2) - (3)].sval));  ; parserData->generalStatusTypePresent = true;}
    break;

  case 12:

    { osresult->setGeneralStatusType("");               parserData->generalStatusTypePresent = true;}
    break;

  case 13:

    { osresult->setGeneralStatusDescription((yyvsp[(2) - (3)].sval));    free((yyvsp[(2) - (3)].sval));}
    break;

  case 14:

    { osresult->setGeneralStatusDescription("");}
    break;

  case 17:

    {osresult->setServiceURI( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;}
    break;

  case 21:

    {osresult->setServiceName( (yyvsp[(2) - (3)].sval));  free((yyvsp[(2) - (3)].sval));   parserData->errorText = NULL;}
    break;

  case 25:

    {osresult->setInstanceName( (yyvsp[(2) - (3)].sval)) ;  free((yyvsp[(2) - (3)].sval));   parserData->errorText = NULL;}
    break;

  case 29:

    {osresult->setJobID( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;}
    break;

  case 33:

    {osresult->setGeneralMessage( (yyvsp[(2) - (3)].sval));  free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;}
    break;

  case 43:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
}
    break;

  case 49:

    {if (parserData->ivar == parserData->numberOfTimes)
           osrlerror(NULL, NULL, parserData, "Too many time measurements");
       osresult->addTimingInformation(parserData->timeType, parserData->timeCategory,
                                      parserData->timeUnit, parserData->timeDescription, parserData->timeValue);       
       parserData->ivar++;
       parserData->timeType = "elapsedTime";
       parserData->timeCategory = "total";
       parserData->timeUnit = "second";
       parserData->timeDescription = "";      
      }
    break;

  case 56:

    {parserData->timeType = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 58:

    {parserData->timeCategory = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 60:

    {parserData->timeUnit = (yyvsp[(2) - (3)].sval);   free((yyvsp[(2) - (3)].sval));}
    break;

  case 62:

    {parserData->timeDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 64:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); }
    break;

  case 65:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); }
    break;

  case 77:

    { parserData->numberOfSolutions = (yyvsp[(3) - (3)].ival); osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 78:

    {parserData->numberOfVariables = (yyvsp[(3) - (3)].ival); osresult->setVariableNumber((yyvsp[(3) - (3)].ival)); }
    break;

  case 79:

    {parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 80:

    {parserData->numberOfObjectives = (yyvsp[(3) - (3)].ival); osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 83:

    {parserData->numberOfVar = 0;  parserData->numberOfCon = 0;  parserData->numberOfObj = 0;}
    break;

  case 84:

    {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   }
    break;

  case 86:

    {
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
/*  	osresult->optimization->solution[parserData->solutionIdx]->targetObjectiveIdx = $3;*/
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 }
    break;

  case 87:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, parserData, "a type attribute required for status element");  osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
    break;

  case 88:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, parserData, "a type attribute required for status element"); parserData->statusTypePresent = false; osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
    break;

  case 91:

    {parserData->statusType = (yyvsp[(2) - (3)].sval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].sval));}
    break;

  case 92:

    {parserData->statusType = ""; parserData->statusTypePresent = true;}
    break;

  case 93:

    {parserData->statusDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 94:

    {parserData->statusDescription = "";}
    break;

  case 96:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = $2; */
		osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
	}
    break;

  case 97:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = "";*/
		osresult->setSolutionMessage(parserData->solutionIdx, "");
	}
    break;

  case 99:

    {
  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  }
    break;

  case 101:

    {  
	osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
	}
    break;

  case 102:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	}
    break;

  case 106:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->primalVals.push_back( parserData->primalValPair);  
   }
    break;

  case 107:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); 
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->primalVals.push_back( parserData->primalValPair); 
  }
    break;

  case 108:

    { parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = (yyvsp[(2) - (3)].ival);}
    break;

  case 111:

    { 	 
		
		parserData->otherVarVec.push_back( parserData->otherVarStruct); 
		parserData->numberOfOtherVariableResults++; 
		parserData->otherNamePresent = false;	
		
	
		osresult->setAnOtherVariableResultSparse(parserData->solutionIdx, parserData->iOther,  parserData->otherVarStruct->name,
			parserData->otherVarStruct->value, parserData->otherVarStruct->description, parserData->otherVarStruct->otherVarIndex,
			parserData->otherVarStruct->otherVarText, parserData->otherVarStruct->numberOfVar );
							
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
				
	}
    break;

  case 112:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	}
    break;

  case 113:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
	}
    break;

  case 119:

    {
	parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	//osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = $3;
}
    break;

  case 120:

    {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
}
    break;

  case 121:

    {parserData->tmpOtherValue=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));}
    break;

  case 122:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
}
    break;

  case 123:

    {
parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
}
    break;

  case 124:

    {
parserData->tmpOtherDescription=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
}
    break;

  case 127:

    {  
parserData->otherVarStruct->otherVarText[parserData->kounter] =  parserData->outStr.str();
//reset the buffer;
parserData->outStr.str("");
parserData->otherVarStruct->otherVarIndex[parserData->kounter] =  parserData->ivar;
parserData->errorText = NULL;
//if (parserData->kounter == osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar)
if (parserData->kounter == osresult->getAnOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther))
    osrlerror(NULL, NULL, parserData, "too many variables"); 
if (parserData->numberOfVariables > 0 && (parserData->ivar < 0 || parserData->ivar > parserData->numberOfVariables - 1) ) 
    osrlerror(NULL, NULL, parserData, "index must be greater than 0 and less than the number of variables");
   

parserData->kounter++;
}
    break;

  case 128:

    { parserData->outStr << (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval)); }
    break;

  case 129:

    { parserData->outStr << (yyvsp[(1) - (1)].ival); /*free($1);*/ }
    break;

  case 130:

    { parserData->outStr << (yyvsp[(1) - (1)].dval); /*free($1);*/ }
    break;

  case 131:

    {	if(parserData->otherVarStruct->numberOfVar <= 0) 
			osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	}
    break;

  case 133:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
}
    break;

  case 134:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 137:

    { 

	parserData->objValPair->value = (yyvsp[(4) - (5)].dval);
	parserData->objVals.push_back( parserData->objValPair);

}
    break;

  case 138:

    {


 	parserData->objValPair->value = (yyvsp[(4) - (5)].ival);
	parserData->objVals.push_back( parserData->objValPair);
  }
    break;

  case 139:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(2) - (3)].ival);   }
    break;

  case 141:

    {

			
			
}
    break;

  case 142:

    {
 
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}
 }
    break;

  case 143:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);

}
    break;

  case 146:

    { 
	
	parserData->dualValPair->value = (yyvsp[(4) - (5)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 
	
	
	}
    break;

  case 147:

    { 
	
	parserData->dualValPair->value = (yyvsp[(4) - (5)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 
	
	}
    break;

  case 148:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(2) - (3)].ival);   }
    break;

  case 149:

    {parserData->ivar = (yyvsp[(2) - (3)].ival);    }
    break;

  case 155:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
}
    break;

  case 156:

    {	
	int temp;
	temp = (yyvsp[(3) - (3)].ival);
	if (temp < 0) osrlerror(NULL, NULL, parserData, "number of other solution results cannot be negative");
	if (osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults != NULL)
		osrlerror(NULL, NULL, parserData, "otherSolutionResults previously allocated");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults = new OtherSolutionResults();	
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults = temp;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult = new OtherSolutionResult*[ temp];
	if (temp > 0)
		for(int i = 0; i < temp; i++) 	
			osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[i] = new OtherSolutionResult();
parserData->iOther = 0; // this will index the number of otherSolutionResult objects
}
    break;

  case 160:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfRecords)
	osrlerror(NULL, NULL, parserData, "fewer record elements present than given in numberOfRecords attribute");

parserData->iOther++;


}
    break;

  case 162:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
}
    break;

  case 168:

    {	

int temp;
temp = (yyvsp[(3) - (4)].ival);
if (temp < 0) osrlerror(NULL, NULL, parserData, "number of records cannot be negative");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfRecords = temp;





	if (osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->record != NULL)
		osrlerror(NULL, NULL, parserData, "record array was previously allocated");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->record = new std::string[temp];
	parserData->kounter = 0; //this will count the number of records in an otherSolutionResult object
}
    break;

  case 169:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
}
    break;

  case 170:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 171:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));}
    break;

  case 173:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));}
    break;

  case 177:

    {

if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfRecords)
	osrlerror(NULL, NULL, parserData, "numberOfRecords attribute less than the number of record elements");

osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->record[parserData->kounter] = parserData->recordContent;
parserData->kounter++;
}
    break;

  case 178:

    {parserData->recordContent = "";}
    break;

  case 179:

    {parserData->recordContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));}
    break;

  case 183:

    {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
}
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


