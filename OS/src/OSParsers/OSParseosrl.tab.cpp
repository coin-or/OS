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
     TIMESTARTANDEND = 282,
     TIMESTART = 283,
     TIMEEND = 284,
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
     MESSAGESTARTANDEND = 314,
     OTHERSTART = 315,
     OTHEREND = 316,
     NUMBEROFSOLUTIONSATT = 317,
     NUMBEROFVARIABLESATT = 318,
     NUMBEROFCONSTRAINTSATT = 319,
     NUMBEROFOBJECTIVESATT = 320,
     OBJECTIVEIDXATT = 321,
     IDXATT = 322,
     TYPEATT = 323,
     DESCRIPTIONATT = 324,
     NAMEATT = 325,
     DUMMY = 326
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
#define TIMESTARTANDEND 282
#define TIMESTART 283
#define TIMEEND 284
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
#define MESSAGESTARTANDEND 314
#define OTHERSTART 315
#define OTHEREND 316
#define NUMBEROFSOLUTIONSATT 317
#define NUMBEROFVARIABLESATT 318
#define NUMBEROFCONSTRAINTSATT 319
#define NUMBEROFOBJECTIVESATT 320
#define OBJECTIVEIDXATT 321
#define IDXATT 322
#define TYPEATT 323
#define DESCRIPTIONATT 324
#define NAMEATT 325
#define DUMMY 326




/* Copy the first part of user declarations.  */



 
  

#include "OSErrorClass.h"
#include "OSResult.h"
#include "OSrLParserData.h"
#include <iostream>
#include <sstream> 


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osrl_scan_string (const char *yy_str , void* yyscanner  );
int osrllex_init(void** ptr_yy_globals);
int osrllex_destroy (void* yyscanner );
int osrlget_lineno( void* yyscanner);
char *osrlget_text (void* yyscanner );
void osrlset_lineno (int line_number , void* yyscanner );
void osrlset_extra (OSrLParserData* parserData , void* yyscanner );
void  yygetOSResult(const char *ch, OSResult* m_osresult, OSrLParserData *m_parserData ) throw(ErrorClass);




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
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNRULES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,    73,
      75,     2,     2,    74,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    72,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    10,    13,    17,    27,    32,    36,
      38,    41,    45,    49,    50,    52,    56,    59,    60,    62,
      66,    69,    70,    72,    76,    79,    80,    82,    86,    89,
      90,    92,    96,   100,   103,   104,   106,   110,   113,   115,
     121,   124,   125,   127,   128,   130,   131,   136,   138,   141,
     142,   145,   148,   151,   154,   157,   160,   163,   166,   169,
     171,   174,   178,   188,   189,   193,   198,   202,   204,   207,
     211,   215,   216,   220,   223,   224,   233,   235,   238,   244,
     250,   251,   254,   255,   256,   264,   266,   269,   275,   281,
     287,   289,   292,   296,   300,   301,   310,   312,   315,   321,
     327,   328,   329,   339,   341,   344,   350,   356,   360,   361,
     363,   364,   366,   368,   371,   374,   376,   378,   380,   382,
     383
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      77,     0,    -1,    -1,    79,    80,    90,    78,    12,    -1,
      10,     8,    -1,    10,    11,     8,    -1,    13,    81,    84,
      85,    86,    87,    88,    89,    14,    -1,    55,    82,     8,
      56,    -1,    55,    82,     9,    -1,    83,    -1,    82,    83,
      -1,    68,     3,   131,    -1,    69,     3,   131,    -1,    -1,
      15,    -1,    16,     4,    17,    -1,    16,    17,    -1,    -1,
      18,    -1,    19,     4,    20,    -1,    19,    20,    -1,    -1,
      21,    -1,    22,     4,    23,    -1,    22,    23,    -1,    -1,
      24,    -1,    25,     4,    26,    -1,    25,    26,    -1,    -1,
      27,    -1,    28,     6,    29,    -1,    28,     5,    29,    -1,
      28,    29,    -1,    -1,    59,    -1,    57,     4,    58,    -1,
      57,    58,    -1,    32,    -1,    30,    92,    93,    91,    31,
      -1,    30,    31,    -1,    -1,    71,    -1,    -1,    71,    -1,
      -1,    33,    96,    94,    95,    -1,     9,    -1,     8,   102,
      -1,    -1,    96,    97,    -1,    98,   131,    -1,    99,   131,
      -1,   100,   131,    -1,   101,   131,    -1,    62,     5,    -1,
      63,     5,    -1,    64,     5,    -1,    65,     5,    -1,    34,
      -1,   103,    34,    -1,   102,   103,    34,    -1,    35,   104,
       8,   105,   108,   109,   120,   123,   130,    -1,    -1,    66,
       5,   131,    -1,    53,   106,     8,    54,    -1,    53,   106,
       9,    -1,   107,    -1,   106,   107,    -1,    68,     3,   131,
      -1,    69,     3,   131,    -1,    -1,    57,     4,    58,    -1,
      57,    58,    -1,    -1,    41,     8,    37,     8,   110,    38,
     112,    42,    -1,   111,    -1,   110,   111,    -1,    43,   127,
       8,     6,    44,    -1,    43,   127,     8,     5,    44,    -1,
      -1,   112,   113,    -1,    -1,    -1,    60,   114,   118,     8,
     115,   116,    61,    -1,   117,    -1,   116,   117,    -1,    43,
     127,     8,     4,    44,    -1,    43,   127,     8,     6,    44,
      -1,    43,   127,     8,     5,    44,    -1,   119,    -1,   118,
     119,    -1,    70,     3,   131,    -1,    69,     3,   131,    -1,
      -1,    45,     8,    37,     8,   121,    38,   128,    46,    -1,
     122,    -1,   121,   122,    -1,    47,   127,     8,     6,    48,
      -1,    47,   127,     8,     5,    48,    -1,    -1,    -1,    49,
       8,    39,   124,     8,   125,    40,   129,    50,    -1,   126,
      -1,   125,   126,    -1,    51,   127,     8,     6,    52,    -1,
      51,   127,     8,     5,    52,    -1,    67,     5,   131,    -1,
      -1,    71,    -1,    -1,    71,    -1,    36,    -1,    71,    36,
      -1,   133,     7,    -1,    72,    -1,    73,    -1,    74,    -1,
      75,    -1,    -1,   133,   132,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   106,   124,   125,   129,   131,   132,   134,
     135,   137,   138,   141,   142,   143,   144,   147,   148,   149,
     150,   152,   153,   154,   155,   157,   158,   159,   160,   163,
     164,   165,   166,   167,   169,   170,   171,   172,   174,   175,
     176,   178,   179,   181,   182,   185,   184,   212,   213,   215,
     216,   218,   219,   220,   221,   225,   227,   229,   231,   235,
     236,   237,   240,   246,   247,   250,   251,   254,   255,   257,
     258,   260,   261,   262,   264,   265,   268,   269,   271,   275,
     282,   283,   285,   288,   285,   292,   293,   295,   303,   309,
     317,   318,   320,   321,   324,   325,   327,   328,   330,   332,
     335,   337,   336,   347,   348,   350,   353,   360,   366,   367,
     369,   370,   372,   373,   379,   381,   382,   383,   384,   386,
     387
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
  "JOBIDSTARTANDEND", "JOBIDSTART", "JOBIDEND", "TIMESTARTANDEND",
  "TIMESTART", "TIMEEND", "RESULTDATASTART", "RESULTDATAEND",
  "RESULTDATASTARTANDEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
  "SOLUTIONSTART", "SOLUTIONEND", "VALUESSTART", "VALUESEND",
  "DUALVALUESSTART", "DUALVALUESEND", "VARIABLESSTART", "VARIABLESEND",
  "VARSTART", "VAREND", "OBJECTIVESSTART", "OBJECTIVESEND", "OBJSTART",
  "OBJEND", "CONSTRAINTSSTART", "CONSTRAINTSEND", "CONSTART", "CONEND",
  "STATUSSTART", "STATUSEND", "GENERALSTATUSSTART", "GENERALSTATUSEND",
  "MESSAGESTART", "MESSAGEEND", "MESSAGESTARTANDEND", "OTHERSTART",
  "OTHEREND", "NUMBEROFSOLUTIONSATT", "NUMBEROFVARIABLESATT",
  "NUMBEROFCONSTRAINTSATT", "NUMBEROFOBJECTIVESATT", "OBJECTIVEIDXATT",
  "IDXATT", "TYPEATT", "DESCRIPTIONATT", "NAMEATT", "DUMMY", "' '",
  "'\\t'", "'\\r'", "'\\n'", "$accept", "osrldoc", "@1", "osrlstart",
  "resultHeader", "generalStatus", "anotherGeneralStatusATT",
  "generalstatusatt", "serviceURI", "serviceName", "instanceName", "jobID",
  "time", "headerMessage", "resultData", "otherResultData", "statistics",
  "optimization", "@2", "optend", "anotherOptATT", "optatt",
  "optnumsolatt", "optnumvaratt", "optnumconatt", "optnumobjatt",
  "solution", "anothersolution", "objectiveIDXATT", "status",
  "anotherStatusATT", "statusatt", "message", "variables", "var",
  "anothervar", "otherVariables", "otherVariableResult", "@3", "@4",
  "othervar", "anotherothervar", "anotherotherVarATT", "otheratt",
  "objectives", "obj", "anotherobj", "constraints", "@5", "con",
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
     325,   326,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    78,    77,    79,    79,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    84,    84,    85,    85,    85,
      85,    86,    86,    86,    86,    87,    87,    87,    87,    88,
      88,    88,    88,    88,    89,    89,    89,    89,    90,    90,
      90,    91,    91,    92,    92,    94,    93,    95,    95,    96,
      96,    97,    97,    97,    97,    98,    99,   100,   101,   102,
     102,   102,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     112,   112,   114,   115,   113,   116,   116,   117,   117,   117,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   124,   123,   125,   125,   126,   126,   127,   128,   128,
     129,   129,   130,   130,   131,   132,   132,   132,   132,   133,
     133
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     2,     3,     9,     4,     3,     1,
       2,     3,     3,     0,     1,     3,     2,     0,     1,     3,
       2,     0,     1,     3,     2,     0,     1,     3,     2,     0,
       1,     3,     3,     2,     0,     1,     3,     2,     1,     5,
       2,     0,     1,     0,     1,     0,     4,     1,     2,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     3,     9,     0,     3,     4,     3,     1,     2,     3,
       3,     0,     3,     2,     0,     8,     1,     2,     5,     5,
       0,     2,     0,     0,     7,     1,     2,     5,     5,     5,
       1,     2,     3,     3,     0,     8,     1,     2,     5,     5,
       0,     0,     9,     1,     2,     5,     5,     3,     0,     1,
       0,     1,     1,     2,     2,     1,     1,     1,     1,     0,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,     0,     0,     5,
       0,    13,    43,    38,     2,     0,     0,     0,     9,    14,
       0,    17,    40,    44,     0,     0,   119,   119,     0,     8,
      10,     0,    16,    18,     0,    21,    49,    41,     3,    11,
       0,    12,     7,    15,     0,    20,    22,     0,    25,    45,
      42,     0,   114,   115,   116,   117,   118,   120,    19,     0,
      24,    26,     0,    29,     0,     0,     0,     0,     0,    50,
     119,   119,   119,   119,    39,    23,     0,    28,    30,     0,
      34,    55,    56,    57,    58,     0,    47,    46,    51,    52,
      53,    54,    27,     0,     0,    33,     0,    35,     0,    59,
      63,    48,     0,    32,    31,     0,    37,     6,     0,     0,
       0,    60,    36,   119,     0,    61,    64,     0,    71,     0,
       0,     0,    67,     0,    74,   119,   119,     0,    66,    68,
       0,    73,     0,    94,    69,    70,    65,    72,     0,     0,
     100,     0,     0,     0,     0,     0,     0,     0,   112,     0,
      62,     0,     0,    76,     0,   101,   113,     0,     0,    80,
      77,     0,     0,    96,     0,   119,     0,     0,     0,   108,
      97,     0,   107,     0,     0,    75,    82,    81,     0,   109,
       0,     0,     0,   103,    79,    78,     0,     0,     0,    95,
       0,   110,   104,     0,     0,     0,    90,    99,    98,     0,
     111,     0,   119,   119,    83,    91,     0,     0,   102,    93,
      92,     0,   106,   105,     0,     0,    85,     0,    84,    86,
       0,     0,     0,     0,    87,    89,    88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    25,     3,     8,    11,    17,    18,    21,    35,
      48,    63,    80,    98,    14,    51,    24,    37,    68,    87,
      49,    69,    70,    71,    72,    73,   101,   102,   109,   118,
     121,   122,   124,   133,   152,   153,   167,   177,   186,   211,
     215,   216,   195,   196,   140,   162,   163,   144,   164,   182,
     183,   158,   180,   201,   150,    39,    57,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -156
static const yytype_int16 yypact[] =
{
      32,    14,    57,    42,  -156,    16,  -156,    45,     1,  -156,
      -8,    47,   -24,  -156,  -156,    94,    98,     2,  -156,  -156,
      12,    56,  -156,  -156,    69,    91,  -156,  -156,    49,  -156,
    -156,    87,  -156,  -156,    17,    55,  -156,    35,  -156,  -156,
      -6,  -156,  -156,  -156,    88,  -156,  -156,    11,    54,   -14,
    -156,    76,  -156,  -156,  -156,  -156,  -156,  -156,  -156,    89,
    -156,  -156,    10,    53,   104,   105,   106,   108,    74,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,    92,  -156,  -156,     3,
     -18,  -156,  -156,  -156,  -156,    50,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,    85,    93,  -156,    -2,  -156,   101,  -156,
      51,    81,    95,  -156,  -156,    61,  -156,  -156,   115,   113,
      96,  -156,  -156,  -156,    70,  -156,  -156,    19,    67,   122,
     123,     4,  -156,     0,    99,  -156,  -156,    73,  -156,  -156,
      75,  -156,   120,    97,  -156,  -156,  -156,  -156,   100,   124,
      82,   126,   102,   127,   -31,   103,   128,   109,  -156,   107,
    -156,    77,   -15,  -156,   110,  -156,  -156,   136,   137,  -156,
    -156,    77,   -20,  -156,   139,  -156,    84,   -25,   141,    79,
    -156,   111,  -156,   112,   114,  -156,  -156,  -156,    86,  -156,
     117,    77,   -21,  -156,  -156,  -156,    24,   116,   118,  -156,
     143,    83,  -156,   149,   150,    -5,  -156,  -156,  -156,    90,
    -156,   119,  -156,  -156,  -156,  -156,   121,   125,  -156,  -156,
    -156,   129,  -156,  -156,    77,   -23,  -156,   147,  -156,  -156,
      48,   130,   134,   135,  -156,  -156,  -156
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,  -156,  -156,  -156,  -156,  -156,   142,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,    59,  -156,  -156,
    -156,    40,  -156,  -156,  -156,    13,  -156,  -156,  -156,  -156,
    -156,   -48,  -156,   -13,  -156,  -156,     6,  -156,  -156,  -156,
     -12,  -155,  -156,  -156,  -156,   -27,  -156,  -156
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      41,    52,   105,   204,   130,   148,   168,    22,    93,    94,
      28,    29,   127,   128,    76,    59,    31,   175,   169,   191,
     214,    44,     4,   159,     9,     5,   190,   161,   151,    32,
     181,    12,    95,    13,    60,   176,    77,    45,   218,    96,
     149,    97,     1,    88,    89,    90,    91,    23,    64,    65,
      66,    67,   221,   222,   223,     7,   106,     6,   131,   217,
      15,    16,    19,    20,   193,   194,    53,    54,    55,    56,
      15,    16,   119,   120,    33,    34,    46,    47,    61,    62,
      78,    79,    85,    86,    99,   100,   116,   119,   120,   173,
     174,   187,   188,   193,   194,   206,   207,    26,   134,   135,
      10,    27,    36,    38,    43,    42,    50,    74,    58,    81,
      82,    83,    75,    84,   103,   107,   100,   108,    92,   112,
     113,   114,   104,   117,   123,   125,   126,   136,   138,   111,
     115,   143,   142,   137,   145,   147,   154,   141,   172,   146,
     132,   165,   139,   156,   157,   166,   151,   171,   155,   178,
     179,   199,   202,   203,   200,   220,   184,   161,   185,    30,
     110,   129,   181,   189,   197,   160,   198,   219,   170,   208,
     192,     0,   214,   212,   224,   209,   210,   213,   225,   226,
       0,     0,   205
};

static const yytype_int16 yycheck[] =
{
      27,     7,     4,     8,     4,    36,   161,    31,     5,     6,
       8,     9,     8,     9,     4,     4,     4,    42,    38,    40,
      43,     4,     8,    38,     8,    11,   181,    47,    43,    17,
      51,    30,    29,    32,    23,    60,    26,    20,    61,    57,
      71,    59,    10,    70,    71,    72,    73,    71,    62,    63,
      64,    65,     4,     5,     6,    13,    58,     0,    58,   214,
      68,    69,    15,    16,    69,    70,    72,    73,    74,    75,
      68,    69,    68,    69,    18,    19,    21,    22,    24,    25,
      27,    28,     8,     9,    34,    35,   113,    68,    69,     5,
       6,     5,     6,    69,    70,     5,     6,     3,   125,   126,
      55,     3,    33,    12,    17,    56,    71,    31,    20,     5,
       5,     5,    23,     5,    29,    14,    35,    66,    26,    58,
       5,     8,    29,    53,    57,     3,     3,    54,     8,    34,
      34,    49,     8,    58,     8,     8,     8,    37,   165,    37,
      41,     5,    45,    36,    67,     8,    43,     8,    39,     8,
      71,     8,     3,     3,    71,     8,    44,    47,    44,    17,
     101,   121,    51,    46,    48,   152,    48,   215,   162,    50,
     182,    -1,    43,    52,    44,   202,   203,    52,    44,    44,
      -1,    -1,   195
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    77,    79,     8,    11,     0,    13,    80,     8,
      55,    81,    30,    32,    90,    68,    69,    82,    83,    15,
      16,    84,    31,    71,    92,    78,     3,     3,     8,     9,
      83,     4,    17,    18,    19,    85,    33,    93,    12,   131,
     133,   131,    56,    17,     4,    20,    21,    22,    86,    96,
      71,    91,     7,    72,    73,    74,    75,   132,    20,     4,
      23,    24,    25,    87,    62,    63,    64,    65,    94,    97,
      98,    99,   100,   101,    31,    23,     4,    26,    27,    28,
      88,     5,     5,     5,     5,     8,     9,    95,   131,   131,
     131,   131,    26,     5,     6,    29,    57,    59,    89,    34,
      35,   102,   103,    29,    29,     4,    58,    14,    66,   104,
     103,    34,    58,     5,     8,    34,   131,    53,   105,    68,
      69,   106,   107,    57,   108,     3,     3,     8,     9,   107,
       4,    58,    41,   109,   131,   131,    54,    58,     8,    45,
     120,    37,     8,    49,   123,     8,    37,     8,    36,    71,
     130,    43,   110,   111,     8,    39,    36,    67,   127,    38,
     111,    47,   121,   122,   124,     5,     8,   112,   127,    38,
     122,     8,   131,     5,     6,    42,    60,   113,     8,    71,
     128,    51,   125,   126,    44,    44,   114,     5,     6,    46,
     127,    40,   126,    69,    70,   118,   119,    48,    48,     8,
      71,   129,     3,     3,     8,   119,     5,     6,    50,   131,
     131,   115,    52,    52,    43,   116,   117,   127,    61,   117,
       8,     4,     5,     6,    44,    44,    44
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
        case 2:

    {
 	if(parserData->numberOfSolutions > 0){
		for(int solIdx = 0; solIdx <  parserData->numberOfSolutions; solIdx++){
			osresult->setSolutionStatus(solIdx, parserData->statusType, parserData->statusDescription);
			osresult->setPrimalVariableValues(solIdx, parserData->primalSolution[ solIdx]);
		    osresult->setNumberOfOtherVariableResults(solIdx, parserData->numberOfOtherVariableResults);
			for(int k = 0; k < parserData->numberOfOtherVariableResults; k++){
				osresult->setAnOtherVariableResult(solIdx, k, parserData->otherVarVec[ k]->name, parserData->otherVarVec[ k]->description, parserData->otherVarVec[ k]->otherVarText);				
			}
			if( (parserData->dualSolution != NULL) &&  (parserData->dualSolution[ solIdx] != NULL) )  osresult->setDualVariableValues(solIdx, parserData->dualSolution[ solIdx]);
			if( (parserData->objectiveValues != NULL) &&  (parserData->objectiveValues[ solIdx] != NULL) ) osresult->setObjectiveValues(solIdx, parserData->objectiveValues[ solIdx]);
		    osresult->setSolutionObjectiveIndex(solIdx,  *(parserData->objectiveIdx + solIdx));
		}
	}
}
    break;

  case 7:

    {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element");}
    break;

  case 8:

    {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element"); parserData->generalStatusTypePresent = false;}
    break;

  case 11:

    { osresult->setGeneralStatusType((yyvsp[(2) - (3)].charval));  free((yyvsp[(2) - (3)].charval));  ; parserData->generalStatusTypePresent = true;}
    break;

  case 12:

    {  osresult->setGeneralStatusDescription((yyvsp[(2) - (3)].charval));    free((yyvsp[(2) - (3)].charval));}
    break;

  case 15:

    {osresult->setServiceURI( (yyvsp[(2) - (3)].charval)); free((yyvsp[(2) - (3)].charval)); parserData->errorText = NULL;}
    break;

  case 19:

    {osresult->setServiceName( (yyvsp[(2) - (3)].charval));  free((yyvsp[(2) - (3)].charval));   parserData->errorText = NULL;}
    break;

  case 23:

    {osresult->setInstanceName( (yyvsp[(2) - (3)].charval)) ;  free((yyvsp[(2) - (3)].charval));   parserData->errorText = NULL;}
    break;

  case 27:

    {osresult->setJobID( (yyvsp[(2) - (3)].charval));  free((yyvsp[(2) - (3)].charval));  parserData->errorText = NULL;}
    break;

  case 31:

    {osresult->setTime( (yyvsp[(2) - (3)].dval));   }
    break;

  case 32:

    {osresult->setTime( (yyvsp[(2) - (3)].ival));    }
    break;

  case 36:

    {osresult->setGeneralMessage( (yyvsp[(2) - (3)].charval));  free((yyvsp[(2) - (3)].charval));  parserData->errorText = NULL;}
    break;

  case 45:

    {
// we now have the basic problem parameters
	if(parserData->numberOfSolutions > 0){
			if( parserData->numberOfVariables > 0){
				parserData->primalSolution = new double* [parserData->numberOfSolutions];
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->primalSolution[ i] = new double[ parserData->numberOfVariables];
				}
			}
			//if( parserData->numberOfConstraints > 0){
			//	parserData->dualSolution = new double*[ parserData->numberOfSolutions];
			//	for(int i = 0; i < parserData->numberOfSolutions; i++){
			//		parserData->dualSolution[ i] = new double[ parserData->numberOfConstraints];
			//	}
			//}
			if( parserData->numberOfObjectives > 0){
				parserData->objectiveValues = new double*[ parserData->numberOfSolutions];
				parserData->objectiveIdx = new int[ parserData->numberOfSolutions];
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->objectiveValues[ i] = new double[ parserData->numberOfObjectives];
				}
			}
	}
}
    break;

  case 55:

    {parserData->numberOfSolutions = (yyvsp[(2) - (2)].ival); osresult->setSolutionNumber((yyvsp[(2) - (2)].ival));}
    break;

  case 56:

    {parserData->numberOfVariables = (yyvsp[(2) - (2)].ival); osresult->setVariableNumber((yyvsp[(2) - (2)].ival)); }
    break;

  case 57:

    {parserData->numberOfConstraints = (yyvsp[(2) - (2)].ival); osresult->setConstraintNumber((yyvsp[(2) - (2)].ival));}
    break;

  case 58:

    {parserData->numberOfObjectives = (yyvsp[(2) - (2)].ival); osresult->setObjectiveNumber((yyvsp[(2) - (2)].ival));}
    break;

  case 62:

    {parserData->solutionIdx++;}
    break;

  case 64:

    {if((yyvsp[(2) - (3)].ival) >= 0) osrlerror(NULL, NULL, NULL, "objective index must be nonpositive");
*(parserData->objectiveIdx + parserData->solutionIdx) = (yyvsp[(2) - (3)].ival);}
    break;

  case 65:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element");  osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
    break;

  case 66:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element"); parserData->statusTypePresent = false; osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
    break;

  case 69:

    {parserData->statusType = (yyvsp[(2) - (3)].charval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].charval));}
    break;

  case 70:

    {parserData->statusDescription = (yyvsp[(2) - (3)].charval);  free((yyvsp[(2) - (3)].charval));}
    break;

  case 78:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(parserData->primalSolution[parserData->solutionIdx] + parserData->kounter ) = (yyvsp[(4) - (5)].dval);
	}
    break;

  case 79:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(parserData->primalSolution[parserData->solutionIdx] + parserData->kounter) = (yyvsp[(4) - (5)].ival);
}
    break;

  case 82:

    {  
   // parserData->numberOfOtherVariableResults++;
	parserData->otherVarStruct = new OtherVariableResultStruct(); 
	parserData->otherVarStruct->otherVarText = new std::string[parserData->numberOfVariables];}
    break;

  case 83:

    {if(parserData->otherNamePresent == false) osrlerror(NULL, NULL, NULL, "other element requires name attribute"); 
	parserData->otherNamePresent = false;  
	}
    break;

  case 84:

    {parserData->otherVarVec.push_back( parserData->otherVarStruct); parserData->numberOfOtherVariableResults++; }
    break;

  case 87:

    { 
std::ostringstream outStr;
outStr << (yyvsp[(4) - (5)].charval);
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
free((yyvsp[(4) - (5)].charval)); parserData->errorText = NULL;
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
}
    break;

  case 88:

    { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << (yyvsp[(4) - (5)].dval);
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
}
    break;

  case 89:

    { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << (yyvsp[(4) - (5)].ival);
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
}
    break;

  case 92:

    { parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].charval);  free((yyvsp[(2) - (3)].charval));}
    break;

  case 93:

    {   parserData->otherVarStruct->description = (yyvsp[(2) - (3)].charval);  free((yyvsp[(2) - (3)].charval));}
    break;

  case 98:

    { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = (yyvsp[(4) - (5)].dval);
}
    break;

  case 99:

    { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = (yyvsp[(4) - (5)].ival);}
    break;

  case 101:

    {
			if( parserData->numberOfConstraints > 0){
				parserData->dualSolution = new double*[ parserData->numberOfSolutions];
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->dualSolution[ i] = new double[ parserData->numberOfConstraints];
				}
			}
}
    break;

  case 105:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(parserData->dualSolution[parserData->solutionIdx] + parserData->kounter) = (yyvsp[(4) - (5)].dval);}
    break;

  case 106:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(parserData->dualSolution[parserData->solutionIdx] + parserData->kounter) = (yyvsp[(4) - (5)].ival);}
    break;

  case 107:

    {parserData->kounter = (yyvsp[(2) - (3)].ival);}
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


