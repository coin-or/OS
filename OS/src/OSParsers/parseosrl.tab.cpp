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



 
  
//#include "lexyaccparser.h"
//#include "externalvars.h"
#include "ErrorClass.h"
#include "OSResult.h"
#include "osrlparservariables.h"


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
OSResult *yygetOSResult( std::string parsestring) ;
void osrlClearMemory();



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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNRULES -- Number of states.  */
#define YYNSTATES  213

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
      89,    93,    96,    98,   104,   107,   108,   110,   111,   113,
     114,   119,   121,   124,   125,   128,   131,   134,   137,   140,
     143,   146,   149,   152,   154,   157,   161,   171,   172,   176,
     181,   185,   187,   190,   194,   198,   199,   203,   206,   207,
     216,   218,   221,   227,   233,   234,   237,   238,   239,   247,
     249,   252,   258,   260,   263,   267,   271,   272,   281,   283,
     286,   292,   298,   299,   308,   310,   313,   319,   325,   329,
     330,   332,   333,   335,   337,   340,   343,   345,   347,   349,
     351,   352
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      76,     0,    -1,    77,    78,    87,    12,    -1,    10,     8,
      -1,    10,    11,     8,    -1,    13,    79,    82,    83,    84,
      85,    86,    14,    -1,    55,    80,     8,    56,    -1,    55,
      80,     9,    -1,    81,    -1,    80,    81,    -1,    67,     3,
     127,    -1,    68,     3,   127,    -1,    -1,    15,    -1,    16,
       4,    17,    -1,    16,    17,    -1,    -1,    18,    -1,    19,
       4,    20,    -1,    19,    20,    -1,    -1,    21,    -1,    22,
       4,    23,    -1,    22,    23,    -1,    -1,    24,    -1,    25,
       4,    26,    -1,    25,    26,    -1,    -1,    27,    -1,    28,
       4,    29,    -1,    28,    29,    -1,    32,    -1,    30,    89,
      90,    88,    31,    -1,    30,    31,    -1,    -1,    70,    -1,
      -1,    70,    -1,    -1,    33,    93,    91,    92,    -1,     9,
      -1,     8,    99,    -1,    -1,    93,    94,    -1,    95,   127,
      -1,    96,   127,    -1,    97,   127,    -1,    98,   127,    -1,
      61,     5,    -1,    62,     5,    -1,    63,     5,    -1,    64,
       5,    -1,    34,    -1,   100,    34,    -1,    99,   100,    34,
      -1,    35,   101,     8,   102,   105,   106,   117,   120,   126,
      -1,    -1,    65,     5,   127,    -1,    53,   103,     8,    54,
      -1,    53,   103,     9,    -1,   104,    -1,   103,   104,    -1,
      67,     3,   127,    -1,    68,     3,   127,    -1,    -1,    57,
       4,    58,    -1,    57,    58,    -1,    -1,    41,     8,    37,
       8,   107,    38,   109,    42,    -1,   108,    -1,   107,   108,
      -1,    43,   123,     8,     6,    44,    -1,    43,   123,     8,
       5,    44,    -1,    -1,   109,   110,    -1,    -1,    -1,    59,
     111,   115,     8,   112,   113,    60,    -1,   114,    -1,   113,
     114,    -1,    43,   123,     8,     4,    44,    -1,   116,    -1,
     115,   116,    -1,    69,     3,   127,    -1,    68,     3,   127,
      -1,    -1,    45,     8,    37,     8,   118,    38,   124,    46,
      -1,   119,    -1,   118,   119,    -1,    47,   123,     8,     6,
      48,    -1,    47,   123,     8,     5,    48,    -1,    -1,    49,
       8,    39,     8,   121,    40,   125,    50,    -1,   122,    -1,
     121,   122,    -1,    51,   123,     8,     6,    52,    -1,    51,
     123,     8,     5,    52,    -1,    66,     5,   127,    -1,    -1,
      70,    -1,    -1,    70,    -1,    36,    -1,    70,    36,    -1,
     129,     7,    -1,    71,    -1,    72,    -1,    73,    -1,    74,
      -1,    -1,   129,   128,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   109,   110,   114,   116,   117,   119,   120,
     122,   123,   126,   127,   128,   129,   132,   133,   134,   135,
     137,   138,   139,   140,   142,   143,   144,   145,   147,   148,
     149,   150,   152,   153,   154,   156,   157,   159,   160,   163,
     162,   190,   191,   193,   194,   196,   197,   198,   199,   203,
     205,   207,   210,   214,   215,   216,   218,   224,   225,   228,
     229,   232,   233,   235,   236,   238,   239,   240,   242,   243,
     245,   246,   248,   252,   259,   260,   262,   265,   262,   269,
     270,   272,   278,   279,   281,   282,   285,   286,   288,   289,
     291,   293,   296,   297,   299,   300,   302,   305,   312,   318,
     319,   321,   322,   324,   325,   331,   333,   334,   335,   336,
     338,   339
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
  "othervar", "anotherothervar", "anotherotherVarATT", "otheratt",
  "objectives", "obj", "anotherobj", "constraints", "con", "anothercon",
  "anIDXATT", "otherObjectives", "otherConstraints", "otherSolution",
  "quote", "xmlWhiteSpaceChar", "xmlWhiteSpace", 0
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
      86,    86,    87,    87,    87,    88,    88,    89,    89,    91,
      90,    92,    92,    93,    93,    94,    94,    94,    94,    95,
      96,    97,    98,    99,    99,    99,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   111,   112,   110,   113,
     113,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   123,   124,
     124,   125,   125,   126,   126,   127,   128,   128,   128,   128,
     129,   129
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     3,     8,     4,     3,     1,     2,
       3,     3,     0,     1,     3,     2,     0,     1,     3,     2,
       0,     1,     3,     2,     0,     1,     3,     2,     0,     1,
       3,     2,     1,     5,     2,     0,     1,     0,     1,     0,
       4,     1,     2,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     3,     9,     0,     3,     4,
       3,     1,     2,     3,     3,     0,     3,     2,     0,     8,
       1,     2,     5,     5,     0,     2,     0,     0,     7,     1,
       2,     5,     1,     2,     3,     3,     0,     8,     1,     2,
       5,     5,     0,     8,     1,     2,     5,     5,     3,     0,
       1,     0,     1,     1,     2,     2,     1,     1,     1,     1,
       0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     0,     1,     0,     0,     4,
       0,    12,    37,    32,     0,     0,     0,     0,     8,    13,
       0,    16,    34,    38,     0,     2,   110,   110,     0,     7,
       9,     0,    15,    17,     0,    20,    43,    35,    10,     0,
      11,     6,    14,     0,    19,    21,     0,    24,    39,    36,
       0,   105,   106,   107,   108,   109,   111,    18,     0,    23,
      25,     0,    28,     0,     0,     0,     0,     0,    44,   110,
     110,   110,   110,    33,    22,     0,    27,    29,     0,     0,
      49,    50,    51,    52,     0,    41,    40,    45,    46,    47,
      48,    26,     0,    31,     5,    53,    57,    42,     0,    30,
       0,     0,     0,    54,   110,     0,    55,    58,     0,    65,
       0,     0,     0,    61,     0,    68,   110,   110,     0,    60,
      62,     0,    67,     0,    86,    63,    64,    59,    66,     0,
       0,    92,     0,     0,     0,     0,     0,     0,     0,   103,
       0,    56,     0,     0,    70,     0,     0,   104,     0,     0,
      74,    71,     0,     0,    88,     0,   110,     0,     0,     0,
      99,    89,     0,     0,    94,    98,     0,     0,    69,    76,
      75,     0,   100,     0,     0,   101,    95,    73,    72,     0,
       0,     0,    87,     0,   102,     0,     0,     0,     0,    82,
      91,    90,     0,     0,    93,   110,   110,    77,    83,    97,
      96,    85,    84,     0,     0,     0,    79,     0,    78,    80,
       0,     0,    81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    11,    17,    18,    21,    35,    47,
      62,    79,    14,    50,    24,    37,    67,    86,    48,    68,
      69,    70,    71,    72,    97,    98,   101,   109,   112,   113,
     115,   124,   143,   144,   158,   170,   179,   203,   205,   206,
     188,   189,   131,   153,   154,   135,   163,   164,   149,   173,
     185,   141,    38,    56,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -148
static const yytype_int16 yypact[] =
{
      22,    16,    28,     9,  -148,    47,  -148,    33,     7,  -148,
     -16,    25,   -24,  -148,    50,    90,    91,     2,  -148,  -148,
      14,    35,  -148,  -148,    62,  -148,  -148,  -148,    40,  -148,
    -148,    80,  -148,  -148,    13,    37,  -148,    29,  -148,    -6,
    -148,  -148,  -148,    78,  -148,  -148,    12,    36,   -14,  -148,
      69,  -148,  -148,  -148,  -148,  -148,  -148,  -148,    81,  -148,
    -148,    10,    46,    96,    97,    98,   100,    67,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,    82,  -148,  -148,     5,    92,
    -148,  -148,  -148,  -148,    44,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,    83,  -148,  -148,  -148,    42,    74,    76,  -148,
     106,   105,    84,  -148,  -148,    61,  -148,  -148,    15,    58,
     113,   114,     4,  -148,    -2,    85,  -148,  -148,    65,  -148,
    -148,    63,  -148,   112,    77,  -148,  -148,  -148,  -148,    87,
     115,    88,   117,    93,   119,   -32,    89,   120,    94,  -148,
      95,  -148,    68,   -17,  -148,    99,   127,  -148,   131,   130,
    -148,  -148,    68,   -18,  -148,   101,  -148,    75,   -36,   132,
      71,  -148,    68,   -21,  -148,  -148,   103,   104,  -148,  -148,
    -148,    79,  -148,   107,   134,    73,  -148,  -148,  -148,    18,
     102,   108,  -148,    86,  -148,   109,   136,   141,    -5,  -148,
    -148,  -148,   110,   111,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,   118,    68,   -35,  -148,   137,  -148,  -148,
     145,   116,  -148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,  -148,  -148,   138,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,    54,  -148,  -148,  -148,    45,
    -148,  -148,  -148,    11,  -148,  -148,  -148,  -148,  -148,   -47,
    -148,   -23,  -148,  -148,    17,  -148,  -148,     1,  -147,  -148,
    -148,  -148,   -27,  -148,  -148
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      40,    51,   121,   197,   139,   159,   168,    22,   204,    92,
      28,    29,   118,   119,    75,   174,    58,    43,    31,   175,
     160,   150,     7,   169,     4,   208,   142,     5,     6,   152,
     162,    32,     1,    44,    93,    59,    76,    12,   140,    13,
      19,    20,    87,    88,    89,    90,    23,    63,    64,    65,
      66,    15,    16,    33,    34,     9,   122,   207,    45,    46,
      60,    61,    25,   186,   187,    52,    53,    54,    55,    15,
      16,   110,   111,    77,    78,    84,    85,   107,    95,    96,
     166,   167,   110,   111,   180,   181,   186,   187,    10,   125,
     126,   192,   193,    26,    27,    36,    41,    42,    57,    49,
      73,    80,    81,    82,    74,    83,    94,   100,    91,    96,
     103,   104,    99,   105,   108,   114,   116,   117,   106,   127,
     129,   128,   130,   133,   132,   136,   123,   138,   145,   165,
     137,   147,   142,   146,   148,   155,   156,   134,   157,   195,
     171,   172,   183,   184,   196,   210,   152,   177,   178,   211,
     190,   102,   162,   182,   151,    30,   191,   120,   209,   194,
     212,   204,   199,   200,   176,   198,     0,     0,   201,   202,
     161
};

static const yytype_int16 yycheck[] =
{
      27,     7,     4,     8,    36,   152,    42,    31,    43,     4,
       8,     9,     8,     9,     4,   162,     4,     4,     4,    40,
      38,    38,    13,    59,     8,    60,    43,    11,     0,    47,
      51,    17,    10,    20,    29,    23,    26,    30,    70,    32,
      15,    16,    69,    70,    71,    72,    70,    61,    62,    63,
      64,    67,    68,    18,    19,     8,    58,   204,    21,    22,
      24,    25,    12,    68,    69,    71,    72,    73,    74,    67,
      68,    67,    68,    27,    28,     8,     9,   104,    34,    35,
       5,     6,    67,    68,     5,     6,    68,    69,    55,   116,
     117,     5,     6,     3,     3,    33,    56,    17,    20,    70,
      31,     5,     5,     5,    23,     5,    14,    65,    26,    35,
      34,     5,    29,     8,    53,    57,     3,     3,    34,    54,
       8,    58,    45,     8,    37,     8,    41,     8,     8,   156,
      37,    36,    43,    39,    66,     8,     5,    49,     8,     3,
       8,    70,     8,    70,     3,     8,    47,    44,    44,     4,
      48,    97,    51,    46,   143,    17,    48,   112,   205,    50,
      44,    43,    52,    52,   163,   188,    -1,    -1,   195,   196,
     153
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    76,    77,     8,    11,     0,    13,    78,     8,
      55,    79,    30,    32,    87,    67,    68,    80,    81,    15,
      16,    82,    31,    70,    89,    12,     3,     3,     8,     9,
      81,     4,    17,    18,    19,    83,    33,    90,   127,   129,
     127,    56,    17,     4,    20,    21,    22,    84,    93,    70,
      88,     7,    71,    72,    73,    74,   128,    20,     4,    23,
      24,    25,    85,    61,    62,    63,    64,    91,    94,    95,
      96,    97,    98,    31,    23,     4,    26,    27,    28,    86,
       5,     5,     5,     5,     8,     9,    92,   127,   127,   127,
     127,    26,     4,    29,    14,    34,    35,    99,   100,    29,
      65,   101,   100,    34,     5,     8,    34,   127,    53,   102,
      67,    68,   103,   104,    57,   105,     3,     3,     8,     9,
     104,     4,    58,    41,   106,   127,   127,    54,    58,     8,
      45,   117,    37,     8,    49,   120,     8,    37,     8,    36,
      70,   126,    43,   107,   108,     8,    39,    36,    66,   123,
      38,   108,    47,   118,   119,     8,     5,     8,   109,   123,
      38,   119,    51,   121,   122,   127,     5,     6,    42,    59,
     110,     8,    70,   124,   123,    40,   122,    44,    44,   111,
       5,     6,    46,     8,    70,   125,    68,    69,   115,   116,
      48,    48,     5,     6,    50,     3,     3,     8,   116,    52,
      52,   127,   127,   112,    43,   113,   114,   123,    60,   114,
       8,     4,    44
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
        case 6:

    {if(generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element");}
    break;

  case 7:

    {if(generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element"); generalStatusTypePresent = false;}
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

  case 39:

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

  case 49:

    {numberOfSolutions = (yyvsp[(2) - (2)].ival);}
    break;

  case 50:

    {numberOfVariables = (yyvsp[(2) - (2)].ival);}
    break;

  case 51:

    {numberOfConstraints = (yyvsp[(2) - (2)].ival);}
    break;

  case 52:

    {numberOfObjectives = (yyvsp[(2) - (2)].ival);}
    break;

  case 56:

    {solutionIdx++;}
    break;

  case 58:

    {if((yyvsp[(2) - (3)].ival) >= 0) osrlerror(NULL, NULL, NULL, "objective index must be nonpositive");
*(objectiveIdx + solutionIdx) = (yyvsp[(2) - (3)].ival);}
    break;

  case 59:

    {if(statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element");}
    break;

  case 60:

    {if(statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element"); statusTypePresent = false;}
    break;

  case 63:

    {statusType = (yyvsp[(2) - (3)].charval); statusTypePresent = true;}
    break;

  case 64:

    {statusDescription = (yyvsp[(2) - (3)].charval);}
    break;

  case 72:

    { 
	if(kounter < 0 || kounter > numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(primalSolution[solutionIdx] + kounter ) = (yyvsp[(4) - (5)].dval);
	}
    break;

  case 73:

    { 
	if(kounter < 0 || kounter > numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(primalSolution[solutionIdx] + kounter) = (yyvsp[(4) - (5)].ival);
}
    break;

  case 76:

    {  
    numberOfOtherVariableResult++;
	otherVarStruct = new OtherVariableResultStruct(); 
	otherVarStruct->rcost = new std::string[numberOfVariables];}
    break;

  case 77:

    {if(otherNamePresent == false) osrlerror(NULL, NULL, NULL, "other element requires name attribute"); 
	otherNamePresent = false;  
	}
    break;

  case 78:

    {otherVarVec.push_back( otherVarStruct);}
    break;

  case 81:

    { 
if(kounter < 0 || kounter > numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
otherVarStruct->rcost[kounter] = (yyvsp[(4) - (5)].charval);
}
    break;

  case 84:

    { otherNamePresent = true; otherVarStruct->name = (yyvsp[(2) - (3)].charval);}
    break;

  case 85:

    {   otherVarStruct->description = (yyvsp[(2) - (3)].charval);}
    break;

  case 90:

    { *(objectiveValues[solutionIdx] + (kounter + numberOfObjectives)) = (yyvsp[(4) - (5)].dval);
}
    break;

  case 91:

    { *(objectiveValues[solutionIdx] + (kounter + numberOfObjectives)) = (yyvsp[(4) - (5)].ival);}
    break;

  case 96:

    { 
	if(kounter < 0 || kounter > numberOfConstraints - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(dualSolution[solutionIdx] + kounter) = (yyvsp[(4) - (5)].dval);}
    break;

  case 97:

    { 
	if(kounter < 0 || kounter > numberOfConstraints - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(dualSolution[solutionIdx] + kounter) = (yyvsp[(4) - (5)].ival);}
    break;

  case 98:

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
	try{
		std::ostringstream outStr;
		std::string error = errormsg;
		error = "Input is either not valid or well formed: "  + error;
		outStr << error << std::endl;
		//outStr << "Here is the last token read: " << osrltext << endl;
		//outStr << "See line number: " << osrllineno << endl;
		error = outStr.str();
		throw ErrorClass( error);
		throw error;
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg);
	}
} //end osrlerror

OSResult *yygetOSResult(std::string parsestring){
	void osrlinitialize();
	bool createOSResult(OSResult* osresult);
	osrlinitialize();
	OSResult* osresult = NULL;
	OSrLParserData *parserData = NULL;
	osresult = new OSResult();
	parserData = new OSrLParserData();
	// call the flex scanner
    osrllex_init( &scanner);
	osrl_scan_string( parsestring.c_str(), scanner);
	std::cout << std::endl << std::endl;
	//std::cout << "start parsing now" << std::endl;
	osrlparse( osresult,  parserData);
	//if( createOSResult( osresult) == false) osrlerror(NULL, NULL, NULL, "Could not create OSResult");
	//std::cout << "Parse a success" << std::endl;
	return osresult;
} //end yygetOSResult

void osrlClearMemory(){
	//delete osresult;
	//osresult = NULL;
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
			if( numberOfConstraints > 0){
				delete[] dualSolution[ i];
				dualSolution[ i] = NULL;
			}
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
	//beginElementText = false;
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

bool createOSResult(OSResult* osresult){
	//osresult = new OSResult();
	// set resultHeader parameters
	if(generalStatusType != "") osresult->setGeneralStatusType( generalStatusType);
	if(generalStatusDescription != "") osresult->setGeneralStatusType( generalStatusDescription);
	if(serviceName != "") osresult->setServiceName( serviceName);
	if(serviceURI != "") osresult->setServiceURI( serviceURI);
	if(instanceName != "") osresult->setInstanceName( instanceName);
	if(jobID != "") osresult->setJobID( jobID);
	if(headerMessage != "") osresult->setGeneralMessage( headerMessage);
	// set basic problem parameters
	/*
	if(osresult->setVariableNumber( numberOfVariables) != true)
		osrlerror(NULL, NULL, NULL, "OSResult error: setVariableNumber");
	if(osresult->setObjectiveNumber( numberOfObjectives) != true)
		osrlerror(NULL, NULL, NULL, "OSResult error: setObjectiveNumber");
	if(osresult->setConstraintNumber( numberOfConstraints) != true)
		osrlerror(NULL, NULL, NULL, "OSResult error: setConstraintNumber");
	if(osresult->setSolutionNumber( numberOfSolutions) != true)
		osrlerror(NULL, NULL, NULL, "OSResult error: setSolutionNumer");
		*/
	if( numberOfVariables > 0 ) osresult->setVariableNumber( numberOfVariables);
	if( numberOfObjectives > 0) osresult->setObjectiveNumber( numberOfObjectives);
	if( numberOfConstraints > 0 ) osresult->setConstraintNumber( numberOfConstraints);
	if( numberOfSolutions > 0 ) osresult->setSolutionNumber( numberOfSolutions);
	//
	// now loop over the solutions
	//std::cout << "Number of Soutions = " << numberOfSolutions << std::endl;
	//std::cout << "Number of Variables = " << numberOfVariables << std::endl;
	//std::cout << "Number of Constraints = " << numberOfConstraints << std::endl;
	//std::cout << "Number of Objectives = " << numberOfObjectives << std::endl;
	//std::cout << "Status Type = " <<  statusType << std::endl;
	//std::cout << std::endl << std::endl;
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

