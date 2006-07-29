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
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse osrlparse
#define yylex   osrllex
#define yyerror osrlerror
#define yylval  osrllval
#define yychar  osrlchar
#define yydebug osrldebug
#define yynerrs osrlnerrs


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
     GREATERTHAN = 263,
     ENDOFELEMENT = 264,
     OSRLSTART = 265,
     OSRLATTRIBUTETEXT = 266,
     OSRLEND = 267,
     RESULTHEADERSTART = 268,
     RESULTHEADEREND = 269,
     SERVICEURISTARTANDEND = 270,
     SERVICEURISTART = 271,
     SERVICEURIEND = 272,
     SERVICENAMESTARTANDEND = 273,
     SERVICENAMESTART = 274,
     SERVICENAMEEND = 275,
     INSTANCENAMESTARTANDEND = 276,
     INSTANCENAMESTART = 277,
     INSTANCENAMEEND = 278,
     JOBIDSTARTANDEND = 279,
     JOBIDSTART = 280,
     JOBIDEND = 281,
     HEADERMESSAGESTARTANDEND = 282,
     HEADERMESSAGESTART = 283,
     HEADERMESSAGEEND = 284,
     RESULTDATASTART = 285,
     RESULTDATAEND = 286,
     RESULTDATASTARTANDEND = 287,
     OPTIMIZATIONSTART = 288,
     OPTIMIZATIONEND = 289,
     SOLUTIONSTART = 290,
     SOLUTIONEND = 291,
     VALUESSTART = 292,
     VALUESEND = 293,
     DUALVALUESSTART = 294,
     DUALVALUESEND = 295,
     VARIABLESSTART = 296,
     VARIABLESEND = 297,
     VARSTART = 298,
     VAREND = 299,
     OBJECTIVESSTART = 300,
     OBJECTIVESEND = 301,
     OBJSTART = 302,
     OBJEND = 303,
     CONSTRAINTSSTART = 304,
     CONSTRAINTSEND = 305,
     CONSTART = 306,
     CONEND = 307,
     STATUSSTART = 308,
     STATUSEND = 309,
     GENERALSTATUSSTART = 310,
     GENERALSTATUSEND = 311,
     MESSAGESTART = 312,
     MESSAGEEND = 313,
     OTHERSTART = 314,
     OTHEREND = 315,
     NUMBEROFSOLUTIONSATT = 316,
     NUMBEROFVARIABLESATT = 317,
     NUMBEROFCONSTRAINTSATT = 318,
     NUMBEROFOBJECTIVESATT = 319,
     OBJECTIVEIDXATT = 320,
     IDXATT = 321,
     TYPEATT = 322,
     DESCRIPTIONATT = 323,
     NAMEATT = 324,
     DUMMY = 325
   };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define INTEGER 260
#define DOUBLE 261
#define QUOTE 262
#define GREATERTHAN 263
#define ENDOFELEMENT 264
#define OSRLSTART 265
#define OSRLATTRIBUTETEXT 266
#define OSRLEND 267
#define RESULTHEADERSTART 268
#define RESULTHEADEREND 269
#define SERVICEURISTARTANDEND 270
#define SERVICEURISTART 271
#define SERVICEURIEND 272
#define SERVICENAMESTARTANDEND 273
#define SERVICENAMESTART 274
#define SERVICENAMEEND 275
#define INSTANCENAMESTARTANDEND 276
#define INSTANCENAMESTART 277
#define INSTANCENAMEEND 278
#define JOBIDSTARTANDEND 279
#define JOBIDSTART 280
#define JOBIDEND 281
#define HEADERMESSAGESTARTANDEND 282
#define HEADERMESSAGESTART 283
#define HEADERMESSAGEEND 284
#define RESULTDATASTART 285
#define RESULTDATAEND 286
#define RESULTDATASTARTANDEND 287
#define OPTIMIZATIONSTART 288
#define OPTIMIZATIONEND 289
#define SOLUTIONSTART 290
#define SOLUTIONEND 291
#define VALUESSTART 292
#define VALUESEND 293
#define DUALVALUESSTART 294
#define DUALVALUESEND 295
#define VARIABLESSTART 296
#define VARIABLESEND 297
#define VARSTART 298
#define VAREND 299
#define OBJECTIVESSTART 300
#define OBJECTIVESEND 301
#define OBJSTART 302
#define OBJEND 303
#define CONSTRAINTSSTART 304
#define CONSTRAINTSEND 305
#define CONSTART 306
#define CONEND 307
#define STATUSSTART 308
#define STATUSEND 309
#define GENERALSTATUSSTART 310
#define GENERALSTATUSEND 311
#define MESSAGESTART 312
#define MESSAGEEND 313
#define OTHERSTART 314
#define OTHEREND 315
#define NUMBEROFSOLUTIONSATT 316
#define NUMBEROFVARIABLESATT 317
#define NUMBEROFCONSTRAINTSATT 318
#define NUMBEROFOBJECTIVESATT 319
#define OBJECTIVEIDXATT 320
#define IDXATT 321
#define TYPEATT 322
#define DESCRIPTIONATT 323
#define NAMEATT 324
#define DUMMY 325




/* Copy the first part of user declarations.  */



 
  
#include "lexyaccparser.h"
#include "externalvars.h"
#include "ErrorClass.h"
#include "OSResult.h"
#include "osrlparservariables.h"
#include <iostream>
#include <sstream> 

 






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
	char* charval;
}
/* Line 193 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNRULES -- Number of states.  */
#define YYNSTATES  214

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,    72,
      74,     2,     2,    73,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    71,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    11,    15,    24,    29,    33,    35,
      38,    42,    46,    47,    49,    53,    56,    57,    59,    63,
      66,    67,    69,    73,    76,    77,    79,    83,    86,    87,
      89,    93,    96,   102,   104,   105,   107,   108,   110,   111,
     116,   118,   121,   122,   125,   128,   131,   134,   137,   140,
     143,   146,   149,   151,   154,   158,   168,   169,   173,   178,
     182,   184,   187,   191,   195,   196,   200,   203,   204,   213,
     215,   218,   224,   230,   231,   234,   235,   236,   244,   246,
     249,   250,   251,   259,   261,   264,   268,   272,   273,   282,
     284,   287,   293,   299,   300,   309,   311,   314,   320,   326,
     330,   331,   333,   334,   336,   338,   341,   344,   346,   348,
     350,   352,   353
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      76,     0,    -1,    77,    78,    87,    12,    -1,    10,     8,
      -1,    10,    11,     8,    -1,    13,    79,    82,    83,    84,
      85,    86,    14,    -1,    55,    80,     8,    56,    -1,    55,
      80,     9,    -1,    81,    -1,    80,    81,    -1,    67,     3,
     129,    -1,    68,     3,   129,    -1,    -1,    15,    -1,    16,
       4,    17,    -1,    16,    17,    -1,    -1,    18,    -1,    19,
       4,    20,    -1,    19,    20,    -1,    -1,    21,    -1,    22,
       4,    23,    -1,    22,    23,    -1,    -1,    24,    -1,    25,
       4,    26,    -1,    25,    26,    -1,    -1,    27,    -1,    28,
       4,    29,    -1,    28,    29,    -1,    30,    89,    90,    88,
      31,    -1,    32,    -1,    -1,    70,    -1,    -1,    70,    -1,
      -1,    33,    93,    91,    92,    -1,     9,    -1,     8,    99,
      -1,    -1,    93,    94,    -1,    95,   129,    -1,    96,   129,
      -1,    97,   129,    -1,    98,   129,    -1,    61,     5,    -1,
      62,     5,    -1,    63,     5,    -1,    64,     5,    -1,    34,
      -1,   100,    34,    -1,    99,   100,    34,    -1,    35,   101,
       8,   102,   105,   106,   119,   122,   128,    -1,    -1,    65,
       5,   129,    -1,    53,   103,     8,    54,    -1,    53,   103,
       9,    -1,   104,    -1,   103,   104,    -1,    67,     3,   129,
      -1,    68,     3,   129,    -1,    -1,    57,     4,    58,    -1,
      57,    58,    -1,    -1,    41,     8,    37,     8,   107,    38,
     109,    42,    -1,   108,    -1,   107,   108,    -1,    43,   125,
       8,     6,    44,    -1,    43,   125,     8,     5,    44,    -1,
      -1,   109,   110,    -1,    -1,    -1,    59,   111,   117,     8,
     112,   113,    60,    -1,   114,    -1,   113,   114,    -1,    -1,
      -1,    43,   125,   115,     8,     4,   116,    44,    -1,   118,
      -1,   117,   118,    -1,    69,     3,   129,    -1,    68,     3,
     129,    -1,    -1,    45,     8,    37,     8,   120,    38,   126,
      46,    -1,   121,    -1,   120,   121,    -1,    47,   125,     8,
       6,    48,    -1,    47,   125,     8,     5,    48,    -1,    -1,
      49,     8,    39,     8,   123,    40,   127,    50,    -1,   124,
      -1,   123,   124,    -1,    51,   125,     8,     6,    52,    -1,
      51,   125,     8,     5,    52,    -1,    66,     5,   129,    -1,
      -1,    70,    -1,    -1,    70,    -1,    36,    -1,    70,    36,
      -1,   131,     7,    -1,    71,    -1,    72,    -1,    73,    -1,
      74,    -1,    -1,   131,   130,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    85,    86,    90,    92,    93,    95,    96,
      98,    99,   102,   103,   104,   105,   108,   109,   110,   111,
     113,   114,   115,   116,   118,   119,   120,   121,   123,   124,
     125,   126,   128,   129,   131,   132,   134,   135,   138,   137,
     165,   166,   168,   169,   171,   172,   173,   174,   178,   180,
     182,   185,   189,   190,   191,   193,   199,   200,   203,   204,
     207,   208,   210,   211,   213,   214,   215,   217,   218,   220,
     221,   223,   227,   234,   235,   237,   240,   237,   244,   245,
     247,   247,   247,   253,   254,   256,   257,   260,   261,   263,
     264,   266,   268,   271,   272,   274,   275,   277,   280,   287,
     293,   294,   296,   297,   299,   300,   306,   308,   309,   310,
     311,   313,   314
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "INTEGER", "DOUBLE", "QUOTE", "GREATERTHAN", "ENDOFELEMENT", "OSRLSTART",
  "OSRLATTRIBUTETEXT", "OSRLEND", "RESULTHEADERSTART", "RESULTHEADEREND",
  "SERVICEURISTARTANDEND", "SERVICEURISTART", "SERVICEURIEND",
  "SERVICENAMESTARTANDEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "INSTANCENAMESTARTANDEND", "INSTANCENAMESTART", "INSTANCENAMEEND",
  "JOBIDSTARTANDEND", "JOBIDSTART", "JOBIDEND", "HEADERMESSAGESTARTANDEND",
  "HEADERMESSAGESTART", "HEADERMESSAGEEND", "RESULTDATASTART",
  "RESULTDATAEND", "RESULTDATASTARTANDEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "SOLUTIONSTART", "SOLUTIONEND", "VALUESSTART",
  "VALUESEND", "DUALVALUESSTART", "DUALVALUESEND", "VARIABLESSTART",
  "VARIABLESEND", "VARSTART", "VAREND", "OBJECTIVESSTART", "OBJECTIVESEND",
  "OBJSTART", "OBJEND", "CONSTRAINTSSTART", "CONSTRAINTSEND", "CONSTART",
  "CONEND", "STATUSSTART", "STATUSEND", "GENERALSTATUSSTART",
  "GENERALSTATUSEND", "MESSAGESTART", "MESSAGEEND", "OTHERSTART",
  "OTHEREND", "NUMBEROFSOLUTIONSATT", "NUMBEROFVARIABLESATT",
  "NUMBEROFCONSTRAINTSATT", "NUMBEROFOBJECTIVESATT", "OBJECTIVEIDXATT",
  "IDXATT", "TYPEATT", "DESCRIPTIONATT", "NAMEATT", "DUMMY", "' '",
  "'\\t'", "'\\r'", "'\\n'", "$accept", "osrldoc", "osrlstart",
  "resultHeader", "generalStatus", "anotherGeneralStatusATT",
  "generalstatusatt", "serviceURI", "serviceName", "instanceName", "jobID",
  "headerMessage", "resultData", "otherResultData", "statistics",
  "optimization", "@1", "optend", "anotherOptATT", "optatt",
  "optnumsolatt", "optnumvaratt", "optnumconatt", "optnumobjatt",
  "solution", "anothersolution", "objectiveIDXATT", "status",
  "anotherStatusATT", "statusatt", "message", "variables", "var",
  "anothervar", "otherVariables", "otherVariableResult", "@2", "@3",
  "othervar", "anotherothervar", "@4", "@5", "anotherotherVarATT",
  "otheratt", "objectives", "obj", "anotherobj", "constraints", "con",
  "anothercon", "anIDXATT", "otherObjectives", "otherConstraints",
  "otherSolution", "quote", "xmlWhiteSpaceChar", "xmlWhiteSpace", 0
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
     325,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    77,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    82,    82,    83,    83,    83,    83,
      84,    84,    84,    84,    85,    85,    85,    85,    86,    86,
      86,    86,    87,    87,    88,    88,    89,    89,    91,    90,
      92,    92,    93,    93,    94,    94,    94,    94,    95,    96,
      97,    98,    99,    99,    99,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   109,   111,   112,   110,   113,   113,
     115,   116,   114,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   122,   122,   123,   123,   124,   124,   125,
     126,   126,   127,   127,   128,   128,   129,   130,   130,   130,
     130,   131,   131
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     3,     8,     4,     3,     1,     2,
       3,     3,     0,     1,     3,     2,     0,     1,     3,     2,
       0,     1,     3,     2,     0,     1,     3,     2,     0,     1,
       3,     2,     5,     1,     0,     1,     0,     1,     0,     4,
       1,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     3,     9,     0,     3,     4,     3,
       1,     2,     3,     3,     0,     3,     2,     0,     8,     1,
       2,     5,     5,     0,     2,     0,     0,     7,     1,     2,
       0,     0,     7,     1,     2,     3,     3,     0,     8,     1,
       2,     5,     5,     0,     8,     1,     2,     5,     5,     3,
       0,     1,     0,     1,     1,     2,     2,     1,     1,     1,
       1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     0,     1,     0,     0,     4,
       0,    12,    36,    33,     0,     0,     0,     0,     8,    13,
       0,    16,    37,     0,     2,   111,   111,     0,     7,     9,
       0,    15,    17,     0,    20,    42,    34,    10,     0,    11,
       6,    14,     0,    19,    21,     0,    24,    38,    35,     0,
     106,   107,   108,   109,   110,   112,    18,     0,    23,    25,
       0,    28,     0,     0,     0,     0,     0,    43,   111,   111,
     111,   111,    32,    22,     0,    27,    29,     0,     0,    48,
      49,    50,    51,     0,    40,    39,    44,    45,    46,    47,
      26,     0,    31,     5,    52,    56,    41,     0,    30,     0,
       0,     0,    53,   111,     0,    54,    57,     0,    64,     0,
       0,     0,    60,     0,    67,   111,   111,     0,    59,    61,
       0,    66,     0,    87,    62,    63,    58,    65,     0,     0,
      93,     0,     0,     0,     0,     0,     0,     0,   104,     0,
      55,     0,     0,    69,     0,     0,   105,     0,     0,    73,
      70,     0,     0,    89,     0,   111,     0,     0,     0,   100,
      90,     0,     0,    95,    99,     0,     0,    68,    75,    74,
       0,   101,     0,     0,   102,    96,    72,    71,     0,     0,
       0,    88,     0,   103,     0,     0,     0,     0,    83,    92,
      91,     0,     0,    94,   111,   111,    76,    84,    98,    97,
      86,    85,     0,     0,     0,    78,    80,    77,    79,     0,
       0,    81,     0,    82
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    11,    17,    18,    21,    34,    46,
      61,    78,    14,    49,    23,    36,    66,    85,    47,    67,
      68,    69,    70,    71,    96,    97,   100,   108,   111,   112,
     114,   123,   142,   143,   157,   169,   178,   202,   204,   205,
     209,   212,   187,   188,   130,   152,   153,   134,   162,   163,
     148,   172,   184,   140,    37,    55,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -147
static const yytype_int16 yypact[] =
{
      27,    28,    35,    49,  -147,    74,  -147,    36,   -10,  -147,
     -41,    25,    17,  -147,    76,    89,    90,     2,  -147,  -147,
      12,    32,  -147,    61,  -147,  -147,  -147,    40,  -147,  -147,
      78,  -147,  -147,    14,    31,  -147,    29,  -147,    -6,  -147,
    -147,  -147,    77,  -147,  -147,    10,    30,   -15,  -147,    67,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,    79,  -147,  -147,
       5,    33,    95,    96,    98,    99,    50,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,    81,  -147,  -147,     3,    91,  -147,
    -147,  -147,  -147,    39,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,    82,  -147,  -147,  -147,    41,    83,    85,  -147,   103,
     101,    86,  -147,  -147,    57,  -147,  -147,     8,    55,   110,
     111,     4,  -147,    -2,    84,  -147,  -147,    62,  -147,  -147,
      59,  -147,   107,    87,  -147,  -147,  -147,  -147,    93,   113,
      88,   114,    94,   115,   -32,    92,   116,    97,  -147,   102,
    -147,    60,   -19,  -147,   100,   119,  -147,   123,   125,  -147,
    -147,    60,   -17,  -147,   104,  -147,    73,   -36,   126,    69,
    -147,    60,   -23,  -147,  -147,   105,   106,  -147,  -147,  -147,
      75,  -147,   108,   132,    71,  -147,  -147,  -147,    15,   109,
     112,  -147,    80,  -147,   117,   139,   140,    -5,  -147,  -147,
    -147,   118,   120,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,   121,    60,   -35,  -147,  -147,  -147,  -147,   136,
     141,  -147,   122,  -147
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,  -147,  -147,  -147,   129,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,    52,  -147,  -147,  -147,    42,
    -147,  -147,  -147,     9,  -147,  -147,  -147,  -147,  -147,   -52,
    -147,  -147,  -147,   -31,  -147,  -147,     6,  -147,  -147,    -3,
    -146,  -147,  -147,  -147,   -26,  -147,  -147
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    50,   120,   196,   138,   158,   167,    91,   203,    74,
      27,    28,   117,   118,    57,   173,    30,   174,    42,   149,
      12,   159,    13,   168,   141,   207,    15,    16,   161,    31,
     151,    75,    92,    58,    43,     6,     4,     1,   139,     5,
      19,    20,    86,    87,    88,    89,    62,    63,    64,    65,
      32,    33,    44,    45,    59,    60,   121,   206,    83,    84,
      76,    77,     7,   185,   186,    51,    52,    53,    54,    15,
      16,   109,   110,    94,    95,   109,   110,   106,   165,   166,
     179,   180,     9,   185,   186,   191,   192,    22,    24,   124,
     125,    10,    25,    26,    35,    41,    40,    56,    72,    48,
      79,    80,    73,    81,    82,    93,    99,    90,   103,   104,
     107,    98,   113,   115,   116,   128,   126,   127,    95,   102,
     105,   132,   135,   137,   144,   122,   147,   154,   155,   164,
     131,   136,   129,   156,   170,   141,   145,   133,   146,   171,
     182,   183,   194,   195,   210,   211,    29,   151,   101,   176,
     177,   150,   208,   119,   181,   161,   197,   189,   160,   175,
     190,     0,     0,     0,   203,     0,   213,   193,   200,   201,
     198,     0,   199
};

static const yytype_int16 yycheck[] =
{
      26,     7,     4,     8,    36,   151,    42,     4,    43,     4,
       8,     9,     8,     9,     4,   161,     4,    40,     4,    38,
      30,    38,    32,    59,    43,    60,    67,    68,    51,    17,
      47,    26,    29,    23,    20,     0,     8,    10,    70,    11,
      15,    16,    68,    69,    70,    71,    61,    62,    63,    64,
      18,    19,    21,    22,    24,    25,    58,   203,     8,     9,
      27,    28,    13,    68,    69,    71,    72,    73,    74,    67,
      68,    67,    68,    34,    35,    67,    68,   103,     5,     6,
       5,     6,     8,    68,    69,     5,     6,    70,    12,   115,
     116,    55,     3,     3,    33,    17,    56,    20,    31,    70,
       5,     5,    23,     5,     5,    14,    65,    26,     5,     8,
      53,    29,    57,     3,     3,     8,    54,    58,    35,    34,
      34,     8,     8,     8,     8,    41,    66,     8,     5,   155,
      37,    37,    45,     8,     8,    43,    39,    49,    36,    70,
       8,    70,     3,     3,     8,     4,    17,    47,    96,    44,
      44,   142,   204,   111,    46,    51,   187,    48,   152,   162,
      48,    -1,    -1,    -1,    43,    -1,    44,    50,   194,   195,
      52,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    76,    77,     8,    11,     0,    13,    78,     8,
      55,    79,    30,    32,    87,    67,    68,    80,    81,    15,
      16,    82,    70,    89,    12,     3,     3,     8,     9,    81,
       4,    17,    18,    19,    83,    33,    90,   129,   131,   129,
      56,    17,     4,    20,    21,    22,    84,    93,    70,    88,
       7,    71,    72,    73,    74,   130,    20,     4,    23,    24,
      25,    85,    61,    62,    63,    64,    91,    94,    95,    96,
      97,    98,    31,    23,     4,    26,    27,    28,    86,     5,
       5,     5,     5,     8,     9,    92,   129,   129,   129,   129,
      26,     4,    29,    14,    34,    35,    99,   100,    29,    65,
     101,   100,    34,     5,     8,    34,   129,    53,   102,    67,
      68,   103,   104,    57,   105,     3,     3,     8,     9,   104,
       4,    58,    41,   106,   129,   129,    54,    58,     8,    45,
     119,    37,     8,    49,   122,     8,    37,     8,    36,    70,
     128,    43,   107,   108,     8,    39,    36,    66,   125,    38,
     108,    47,   120,   121,     8,     5,     8,   109,   125,    38,
     121,    51,   123,   124,   129,     5,     6,    42,    59,   110,
       8,    70,   126,   125,    40,   124,    44,    44,   111,     5,
       6,    46,     8,    70,   127,    68,    69,   117,   118,    48,
      48,     5,     6,    50,     3,     3,     8,   118,    52,    52,
     129,   129,   112,    43,   113,   114,   125,    60,   114,   115,
       8,     4,   116,    44
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
      yyerror (YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

    {if(generalStatusTypePresent == false) osrlerror("a type attribute required for generalStatus element");}
    break;

  case 7:

    {if(generalStatusTypePresent == false) osrlerror("a type attribute required for generalStatus element"); generalStatusTypePresent = false;}
    break;

  case 10:

    {generalStatusType = (yyvsp[(2) - (3)].charval); generalStatusTypePresent = true;}
    break;

  case 11:

    {generalStatusDescription = (yyvsp[(2) - (3)].charval);}
    break;

  case 14:

    {serviceURI = (yyvsp[(2) - (3)].charval);}
    break;

  case 18:

    {serviceName = (yyvsp[(2) - (3)].charval);}
    break;

  case 22:

    {instanceName = (yyvsp[(2) - (3)].charval);}
    break;

  case 26:

    {jobID = (yyvsp[(2) - (3)].charval);}
    break;

  case 30:

    {headerMessage = (yyvsp[(2) - (3)].charval);}
    break;

  case 38:

    {
// we now have the basic problem parameters
	if( numberOfSolutions > 0){
			primalSolution = new double*[numberOfSolutions];
			dualSolution = new double*[numberOfSolutions];
			objectiveValues = new double*[numberOfSolutions];
			objectiveIdx = new int[ numberOfSolutions];
			if( numberOfVariables > 0){
				for(int i = 0; i < numberOfSolutions; i++){
					primalSolution[ i] = new double[ numberOfVariables];
				}
			}
			if( numberOfConstraints > 0){
				for(int i = 0; i < numberOfSolutions; i++){
					dualSolution[ i] = new double[ numberOfConstraints];
				}
			}
			if( numberOfObjectives > 0){
				for(int i = 0; i < numberOfSolutions; i++){
					objectiveValues[ i] = new double[ numberOfObjectives];
				}
			}
	}
}
    break;

  case 48:

    {numberOfSolutions = (yyvsp[(2) - (2)].ival);}
    break;

  case 49:

    {numberOfVariables = (yyvsp[(2) - (2)].ival);}
    break;

  case 50:

    {numberOfConstraints = (yyvsp[(2) - (2)].ival);}
    break;

  case 51:

    {numberOfObjectives = (yyvsp[(2) - (2)].ival);}
    break;

  case 55:

    {solutionIdx++;}
    break;

  case 57:

    {if((yyvsp[(2) - (3)].ival) >= 0) osrlerror("objective index must be nonpositive");
*(objectiveIdx + solutionIdx) = (yyvsp[(2) - (3)].ival);}
    break;

  case 58:

    {if(statusTypePresent == false) osrlerror("a type attribute required for status element");}
    break;

  case 59:

    {if(statusTypePresent == false) osrlerror("a type attribute required for status element"); statusTypePresent = false;}
    break;

  case 62:

    {statusType = (yyvsp[(2) - (3)].charval); statusTypePresent = true;}
    break;

  case 63:

    {statusDescription = (yyvsp[(2) - (3)].charval);}
    break;

  case 71:

    { 
	if(kounter < 0 || kounter > numberOfVariables - 1) osrlerror("index must be greater than 0 and less than the number of variables");
	*(primalSolution[solutionIdx] + kounter ) = (yyvsp[(4) - (5)].dval);
	}
    break;

  case 72:

    { 
	if(kounter < 0 || kounter > numberOfVariables - 1) osrlerror("index must be greater than 0 and less than the number of variables");
	*(primalSolution[solutionIdx] + kounter) = (yyvsp[(4) - (5)].ival);
}
    break;

  case 75:

    {  
    numberOfOtherVariableResult++;
	otherVarStruct = new OtherVariableResultStruct(); 
	otherVarStruct->rcost = new std::string[numberOfVariables];}
    break;

  case 76:

    {if(otherNamePresent == false) osrlerror("other element requires name attribute"); 
	otherNamePresent = false;  
	}
    break;

  case 77:

    {otherVarVec.push_back( otherVarStruct);}
    break;

  case 80:

    {beginElementText = true;  }
    break;

  case 81:

    {beginElementText = false; }
    break;

  case 82:

    { 
if(kounter < 0 || kounter > numberOfVariables - 1) osrlerror("index must be greater than 0 and less than the number of variables");
otherVarStruct->rcost[kounter] = (yyvsp[(5) - (7)].charval);
}
    break;

  case 85:

    { otherNamePresent = true; otherVarStruct->name = (yyvsp[(2) - (3)].charval);}
    break;

  case 86:

    {   otherVarStruct->description = (yyvsp[(2) - (3)].charval);}
    break;

  case 91:

    { *(objectiveValues[solutionIdx] + (kounter + numberOfObjectives)) = (yyvsp[(4) - (5)].dval);
}
    break;

  case 92:

    { *(objectiveValues[solutionIdx] + (kounter + numberOfObjectives)) = (yyvsp[(4) - (5)].ival);}
    break;

  case 97:

    { 
	if(kounter < 0 || kounter > numberOfConstraints - 1) osrlerror("index must be greater than 0 and less than the number of constraints");
	*(dualSolution[solutionIdx] + kounter) = (yyvsp[(4) - (5)].dval);}
    break;

  case 98:

    { 
	if(kounter < 0 || kounter > numberOfConstraints - 1) osrlerror("index must be greater than 0 and less than the number of constraints");
	*(dualSolution[solutionIdx] + kounter) = (yyvsp[(4) - (5)].ival);}
    break;

  case 99:

    {kounter = (yyvsp[(2) - (3)].ival);}
    break;


/* Line 1267 of yacc.c.  */

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
      yyerror (YY_("syntax error"));
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
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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





void osrlerror(char* errormsg)
{
	try{
		ostringstream outStr;
		std::string error = errormsg;
		error = "Input is either not valid or well formed: "  + error;
		outStr << error << endl;
		outStr << "Here is the last token read: " << osrltext << endl;
		outStr << "See line number: " << osrllineno << endl;
		error = outStr.str();
		throw ErrorClass( error);
		throw error;
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg);
	}
} // end osrlerror

OSResult *yygetOSResult(std::string parsestring){
	void osrlinitialize();
	bool createOSResult();
	osrlinitialize();
	osrl_scan_string( parsestring.c_str());
	std::cout << std::endl << std::endl;
	std::cout << "start parising now" << std::endl;
	osrlparse();
	std::cout << "Parse a success" << std::endl;
	if( createOSResult() == false) osrlerror("Could not create OSResult");
	return osresult;
} // end yygetOSResult

void osrlClearMemory(){
	delete osresult;
	osresult = NULL;
	if(numberOfSolutions > 0){
		delete[] objectiveIdx;
		objectiveIdx = NULL;
		for(int i = 0; i < numberOfSolutions; i++){
			delete[] primalSolution[ i];
			primalSolution[ i] = NULL;
			// now delete other var
			for(int k = 0; k < numberOfOtherVariableResult; k++){
				delete[] otherVarVec[ k]->rcost;
				otherVarVec[ k] = NULL;				
			}
			otherVarVec.clear();
			delete[] dualSolution[ i];
			dualSolution[ i] = NULL;
			delete[] objectiveValues[i];
			objectiveValues = NULL;
		}
	}
	delete primalSolution;
	primalSolution = NULL;
	delete dualSolution;
	dualSolution = NULL;
} // end osrlClearMemory

void osrlinitialize(){
	numberOfSolutions = 0;
	numberOfVariables = 0;
	numberOfConstraints = 0;
	numberOfObjectives = 0;
	statusType = "";
	statusDescription = "";
	generalStatusType = "";
	generalStatusDescription = "";
	beginElementText = false;
	statusTypePresent = false;
	generalStatusTypePresent = false;
	otherNamePresent = false;
	solutionIdx = 0;
	objectiveValues = NULL;
	primalSolution = NULL;
	dualSolution = NULL;
	objectiveIdx = NULL;
	kounter = 0;
	serviceURI = "";
	serviceName = "";
	instanceName = "";
	jobID = "";
	headerMessage = "";
	otherVarVec.reserve(20);
}// end osrlinitialize

bool createOSResult(){
	osresult = new OSResult();
	// set resultHeader parameters
	if(generalStatusType != "") osresult->setGeneralStatusType( generalStatusType);
	if(generalStatusDescription != "") osresult->setGeneralStatusType( generalStatusDescription);
	if(serviceName != "") osresult->setServiceName( serviceName);
	if(serviceURI != "") osresult->setServiceURI( serviceURI);
	if(instanceName != "") osresult->setInstanceName( instanceName);
	if(jobID != "") osresult->setJobID( jobID);
	if(headerMessage != "") osresult->setGeneralMessage( headerMessage);
	// set basic problem parameters
	if(osresult->setVariableNumber( numberOfVariables) != true)
		osrlerror("OSResult error: setVariableNumber");
	if(osresult->setObjectiveNumber( numberOfObjectives) != true)
		osrlerror("OSResult error: setObjectiveNumber");
	if(osresult->setConstraintNumber( numberOfConstraints) != true)
		osrlerror("OSResult error: setConstraintNumber");
	if(osresult->setSolutionNumber( numberOfSolutions) != true)
		osrlerror("OSResult error: setSolutionNumer");
	//
	// now loop over the solutions
	std::cout << "Number of Soutions = " << numberOfSolutions << std::endl;
	std::cout << "Number of Variables = " << numberOfVariables << std::endl;
	std::cout << "Number of Constraints = " << numberOfConstraints << std::endl;
	std::cout << "Number of Objectives = " << numberOfObjectives << std::endl;
	std::cout << "Status Type = " <<  statusType << std::endl;
	std::cout << std::endl << std::endl;
	//

	if(numberOfSolutions > 0){
		for(int solIdx = 0; solIdx < numberOfSolutions; solIdx++){
			osresult->setSolutionStatus(solIdx, statusType, statusDescription);
			osresult->setPrimalVariableValues(solIdx, primalSolution[ solIdx]);
			osresult->setNumberOfOtherVariableResult(solIdx, numberOfOtherVariableResult);
			for(int k = 0; k < numberOfOtherVariableResult; k++){
				osresult->setAnOtherVariableResult(solIdx, k, otherVarVec[ k]->name, otherVarVec[ k]->description, otherVarVec[ k]->rcost);				
			}
			osresult->setDualVariableValues(solIdx, dualSolution[ solIdx]);
			osresult->setObjectiveValues(solIdx, objectiveValues[ solIdx]);
			osresult->setSolutionObjectiveIndex(solIdx,  *(objectiveIdx + solIdx));
		}
		
	}
	return true;
}








