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
     GENERALSTART = 268,
     GENERALEND = 269,
     SYSTEMSTART = 270,
     SYSTEMEND = 271,
     SERVICESTART = 272,
     SERVICEEND = 273,
     JOBSTART = 274,
     JOBEND = 275,
     SERVICEURISTARTANDEND = 276,
     SERVICEURISTART = 277,
     SERVICEURIEND = 278,
     SERVICENAMESTARTANDEND = 279,
     SERVICENAMESTART = 280,
     SERVICENAMEEND = 281,
     INSTANCENAMESTARTANDEND = 282,
     INSTANCENAMESTART = 283,
     INSTANCENAMEEND = 284,
     JOBIDSTARTANDEND = 285,
     JOBIDSTART = 286,
     JOBIDEND = 287,
     TIMINGINFORMATIONSTART = 288,
     TIMINGINFORMATIONEND = 289,
     TIMESTARTANDEND = 290,
     TIMESTART = 291,
     TIMEEND = 292,
     OPTIMIZATIONSTART = 293,
     OPTIMIZATIONEND = 294,
     SOLUTIONSTART = 295,
     SOLUTIONEND = 296,
     VALUESSTART = 297,
     VALUESEND = 298,
     DUALVALUESSTART = 299,
     DUALVALUESEND = 300,
     VARIABLESSTART = 301,
     VARIABLESEND = 302,
     VARSTART = 303,
     VAREND = 304,
     OBJECTIVESSTART = 305,
     OBJECTIVESEND = 306,
     OBJSTART = 307,
     OBJEND = 308,
     CONSTRAINTSSTART = 309,
     CONSTRAINTSEND = 310,
     CONSTART = 311,
     CONEND = 312,
     STATUSSTART = 313,
     STATUSEND = 314,
     GENERALSTATUSSTART = 315,
     GENERALSTATUSEND = 316,
     MESSAGESTART = 317,
     MESSAGEEND = 318,
     MESSAGESTARTANDEND = 319,
     OTHERSTART = 320,
     OTHEREND = 321,
     NUMBEROFTIMESATT = 322,
     NUMBEROFSOLUTIONSATT = 323,
     NUMBEROFVARIABLESATT = 324,
     NUMBEROFCONSTRAINTSATT = 325,
     NUMBEROFOBJECTIVESATT = 326,
     NUMBEROFVARATT = 327,
     NUMBEROFOBJATT = 328,
     NUMBEROFCONATT = 329,
     TARGETOBJECTIVEIDXATT = 330,
     IDXATT = 331,
     TYPEATT = 332,
     DESCRIPTIONATT = 333,
     NAMEATT = 334,
     DUMMY = 335
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
#define GENERALSTART 268
#define GENERALEND 269
#define SYSTEMSTART 270
#define SYSTEMEND 271
#define SERVICESTART 272
#define SERVICEEND 273
#define JOBSTART 274
#define JOBEND 275
#define SERVICEURISTARTANDEND 276
#define SERVICEURISTART 277
#define SERVICEURIEND 278
#define SERVICENAMESTARTANDEND 279
#define SERVICENAMESTART 280
#define SERVICENAMEEND 281
#define INSTANCENAMESTARTANDEND 282
#define INSTANCENAMESTART 283
#define INSTANCENAMEEND 284
#define JOBIDSTARTANDEND 285
#define JOBIDSTART 286
#define JOBIDEND 287
#define TIMINGINFORMATIONSTART 288
#define TIMINGINFORMATIONEND 289
#define TIMESTARTANDEND 290
#define TIMESTART 291
#define TIMEEND 292
#define OPTIMIZATIONSTART 293
#define OPTIMIZATIONEND 294
#define SOLUTIONSTART 295
#define SOLUTIONEND 296
#define VALUESSTART 297
#define VALUESEND 298
#define DUALVALUESSTART 299
#define DUALVALUESEND 300
#define VARIABLESSTART 301
#define VARIABLESEND 302
#define VARSTART 303
#define VAREND 304
#define OBJECTIVESSTART 305
#define OBJECTIVESEND 306
#define OBJSTART 307
#define OBJEND 308
#define CONSTRAINTSSTART 309
#define CONSTRAINTSEND 310
#define CONSTART 311
#define CONEND 312
#define STATUSSTART 313
#define STATUSEND 314
#define GENERALSTATUSSTART 315
#define GENERALSTATUSEND 316
#define MESSAGESTART 317
#define MESSAGEEND 318
#define MESSAGESTARTANDEND 319
#define OTHERSTART 320
#define OTHEREND 321
#define NUMBEROFTIMESATT 322
#define NUMBEROFSOLUTIONSATT 323
#define NUMBEROFVARIABLESATT 324
#define NUMBEROFCONSTRAINTSATT 325
#define NUMBEROFOBJECTIVESATT 326
#define NUMBEROFVARATT 327
#define NUMBEROFOBJATT 328
#define NUMBEROFCONATT 329
#define TARGETOBJECTIVEIDXATT 330
#define IDXATT 331
#define TYPEATT 332
#define DESCRIPTIONATT 333
#define NAMEATT 334
#define DUMMY 335




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
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNRULES -- Number of states.  */
#define YYNSTATES  260

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   335

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,    82,
      84,     2,     2,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    81,     2,     2,     2,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    11,    14,    18,    19,    28,    33,    37,
      39,    42,    46,    50,    51,    53,    57,    60,    61,    63,
      67,    70,    71,    73,    77,    80,    81,    83,    87,    90,
      91,    93,    97,   100,   101,   104,   105,   108,   109,   110,
     115,   116,   117,   122,   123,   129,   131,   135,   136,   139,
     141,   142,   146,   147,   151,   153,   156,   157,   160,   163,
     166,   169,   172,   176,   180,   184,   188,   189,   191,   194,
     204,   205,   210,   215,   219,   221,   224,   228,   232,   233,
     237,   240,   241,   251,   256,   258,   261,   267,   273,   274,
     277,   278,   279,   280,   289,   291,   294,   300,   306,   312,
     313,   315,   318,   322,   326,   331,   332,   342,   347,   348,
     350,   353,   359,   365,   366,   367,   378,   383,   385,   388,
     394,   400,   404,   405,   407,   408,   410,   412,   415,   418,
     420,   422,   424,   426,   427
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      86,     0,    -1,    87,    88,    97,    98,    99,   108,    12,
      -1,    10,     8,    -1,    10,    11,     8,    -1,    -1,    13,
      89,    92,    93,    94,    95,    96,    14,    -1,    60,    90,
       8,    61,    -1,    60,    90,     9,    -1,    91,    -1,    90,
      91,    -1,    77,     3,   151,    -1,    78,     3,   151,    -1,
      -1,    21,    -1,    22,     4,    23,    -1,    22,    23,    -1,
      -1,    24,    -1,    25,     4,    26,    -1,    25,    26,    -1,
      -1,    27,    -1,    28,     4,    29,    -1,    28,    29,    -1,
      -1,    30,    -1,    31,     4,    32,    -1,    31,    32,    -1,
      -1,    64,    -1,    62,     4,    63,    -1,    62,    63,    -1,
      -1,    15,    16,    -1,    -1,    17,    18,    -1,    -1,    -1,
      19,   100,   101,    20,    -1,    -1,    -1,    33,   102,   103,
     105,    -1,    -1,   104,    67,     7,     5,     7,    -1,     9,
      -1,     8,   106,    34,    -1,    -1,   107,   106,    -1,    35,
      -1,    -1,    38,   109,    39,    -1,    -1,   112,   110,   111,
      -1,     9,    -1,     8,   118,    -1,    -1,   112,   113,    -1,
     114,   151,    -1,   115,   151,    -1,   116,   151,    -1,   117,
     151,    -1,    68,   151,     5,    -1,    69,   151,     5,    -1,
      70,   151,     5,    -1,    71,   151,     5,    -1,    -1,   119,
      -1,   118,   119,    -1,    40,   120,     8,   121,   124,   125,
     138,   142,   150,    -1,    -1,    75,   151,     5,   151,    -1,
      58,   122,     8,    59,    -1,    58,   122,     9,    -1,   123,
      -1,   122,   123,    -1,    77,     3,   151,    -1,    78,     3,
     151,    -1,    -1,    62,     4,    63,    -1,    62,    63,    -1,
      -1,    46,     8,    42,   126,     8,   127,    43,   129,    47,
      -1,    72,   151,     5,   151,    -1,   128,    -1,   127,   128,
      -1,    48,   147,     8,     6,    49,    -1,    48,   147,     8,
       5,    49,    -1,    -1,   129,   130,    -1,    -1,    -1,    -1,
      65,   131,   136,     8,   132,   134,   133,    66,    -1,   135,
      -1,   134,   135,    -1,    48,   147,     8,     4,    49,    -1,
      48,   147,     8,     6,    49,    -1,    48,   147,     8,     5,
      49,    -1,    -1,   137,    -1,   136,   137,    -1,    79,     3,
     151,    -1,    78,     3,   151,    -1,    72,   151,     5,   151,
      -1,    -1,    50,     8,    42,   139,     8,   140,    43,   148,
      51,    -1,    73,   151,     5,   151,    -1,    -1,   141,    -1,
     140,   141,    -1,    52,   147,     8,     6,    53,    -1,    52,
     147,     8,     5,    53,    -1,    -1,    -1,    54,     8,    44,
     144,   143,     8,   145,    45,   149,    55,    -1,    74,   151,
       5,   151,    -1,   146,    -1,   145,   146,    -1,    56,   147,
       8,     6,    57,    -1,    56,   147,     8,     5,    57,    -1,
      76,     5,   151,    -1,    -1,    80,    -1,    -1,    80,    -1,
      41,    -1,    80,    41,    -1,   153,     7,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    -1,   153,   152,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   116,   117,   121,   121,   123,   124,   126,
     127,   129,   130,   133,   134,   135,   136,   139,   140,   141,
     142,   144,   145,   146,   147,   149,   150,   151,   152,   154,
     155,   156,   157,   159,   159,   161,   161,   163,   163,   163,
     165,   166,   166,   168,   168,   172,   172,   174,   174,   178,
     197,   197,   200,   199,   227,   228,   230,   231,   233,   234,
     235,   236,   240,   242,   244,   246,   250,   251,   252,   255,
     258,   259,   262,   263,   266,   267,   269,   270,   272,   273,
     274,   276,   277,   280,   282,   283,   285,   289,   296,   297,
     299,   302,   304,   299,   306,   307,   309,   317,   323,   331,
     332,   333,   335,   336,   337,   340,   341,   343,   345,   346,
     347,   349,   351,   354,   356,   355,   367,   369,   370,   372,
     375,   382,   388,   389,   391,   392,   394,   395,   401,   403,
     404,   405,   406,   408,   409
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "INTEGER", "DOUBLE", "QUOTE", "GREATERTHAN", "ENDOFELEMENT", "OSRLSTART",
  "OSRLATTRIBUTETEXT", "OSRLEND", "GENERALSTART", "GENERALEND",
  "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND", "JOBSTART",
  "JOBEND", "SERVICEURISTARTANDEND", "SERVICEURISTART", "SERVICEURIEND",
  "SERVICENAMESTARTANDEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "INSTANCENAMESTARTANDEND", "INSTANCENAMESTART", "INSTANCENAMEEND",
  "JOBIDSTARTANDEND", "JOBIDSTART", "JOBIDEND", "TIMINGINFORMATIONSTART",
  "TIMINGINFORMATIONEND", "TIMESTARTANDEND", "TIMESTART", "TIMEEND",
  "OPTIMIZATIONSTART", "OPTIMIZATIONEND", "SOLUTIONSTART", "SOLUTIONEND",
  "VALUESSTART", "VALUESEND", "DUALVALUESSTART", "DUALVALUESEND",
  "VARIABLESSTART", "VARIABLESEND", "VARSTART", "VAREND",
  "OBJECTIVESSTART", "OBJECTIVESEND", "OBJSTART", "OBJEND",
  "CONSTRAINTSSTART", "CONSTRAINTSEND", "CONSTART", "CONEND",
  "STATUSSTART", "STATUSEND", "GENERALSTATUSSTART", "GENERALSTATUSEND",
  "MESSAGESTART", "MESSAGEEND", "MESSAGESTARTANDEND", "OTHERSTART",
  "OTHEREND", "NUMBEROFTIMESATT", "NUMBEROFSOLUTIONSATT",
  "NUMBEROFVARIABLESATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFOBJECTIVESATT", "NUMBEROFVARATT", "NUMBEROFOBJATT",
  "NUMBEROFCONATT", "TARGETOBJECTIVEIDXATT", "IDXATT", "TYPEATT",
  "DESCRIPTIONATT", "NAMEATT", "DUMMY", "' '", "'\\t'", "'\\r'", "'\\n'",
  "$accept", "osrldoc", "osrlstart", "generalElement", "generalStatus",
  "anotherGeneralStatusATT", "generalstatusatt", "serviceURI",
  "serviceName", "instanceName", "jobID", "headerMessage", "systemElement",
  "serviceElement", "jobElement", "@1", "timingInformation", "@2",
  "numberoftimes", "@3", "timingContent", "listOfTimes", "time",
  "optimizationElement", "optimizationContent", "@4", "optend",
  "anotherOptATT", "optatt", "optnumsolatt", "optnumvaratt",
  "optnumconatt", "optnumobjatt", "solution", "anothersolution",
  "targetObjectiveIDXATT", "status", "anotherStatusATT", "statusatt",
  "message", "variables", "numberOfVarATT", "var", "anothervar",
  "otherVariables", "otherVariableResult", "@5", "@6", "@7", "othervar",
  "anotherothervar", "anotherotherVarATT", "otheratt", "objectives",
  "numberOfObjATT", "obj", "anotherobj", "constraints", "@8",
  "numberOfConATT", "con", "anothercon", "anIDXATT", "otherObjectives",
  "otherConstraints", "otherSolution", "quote", "xmlWhiteSpaceChar",
  "xmlWhiteSpace", 0
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
     335,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    91,    92,    92,    92,    92,    93,    93,    93,
      93,    94,    94,    94,    94,    95,    95,    95,    95,    96,
      96,    96,    96,    97,    97,    98,    98,    99,   100,    99,
     101,   102,   101,   104,   103,   105,   105,   106,   106,   107,
     108,   108,   110,   109,   111,   111,   112,   112,   113,   113,
     113,   113,   114,   115,   116,   117,   118,   118,   118,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     124,   125,   125,   126,   127,   127,   128,   128,   129,   129,
     131,   132,   133,   130,   134,   134,   135,   135,   135,   136,
     136,   136,   137,   137,   137,   138,   138,   139,   140,   140,
     140,   141,   141,   142,   143,   142,   144,   145,   145,   146,
     146,   147,   148,   148,   149,   149,   150,   150,   151,   152,
     152,   152,   152,   153,   153
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     3,     0,     8,     4,     3,     1,
       2,     3,     3,     0,     1,     3,     2,     0,     1,     3,
       2,     0,     1,     3,     2,     0,     1,     3,     2,     0,
       1,     3,     2,     0,     2,     0,     2,     0,     0,     4,
       0,     0,     4,     0,     5,     1,     3,     0,     2,     1,
       0,     3,     0,     3,     1,     2,     0,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     0,     1,     2,     9,
       0,     4,     4,     3,     1,     2,     3,     3,     0,     3,
       2,     0,     9,     4,     1,     2,     5,     5,     0,     2,
       0,     0,     0,     8,     1,     2,     5,     5,     5,     0,
       1,     2,     3,     3,     4,     0,     9,     4,     0,     1,
       2,     5,     5,     0,     0,    10,     4,     1,     2,     5,
       5,     3,     0,     1,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    33,     4,
       0,    13,     0,    35,     0,     0,     0,     9,    14,     0,
      17,    34,     0,    37,   133,   133,     0,     8,    10,     0,
      16,    18,     0,    21,    36,    38,    50,    11,     0,    12,
       7,    15,     0,    20,    22,     0,    25,    40,    56,     0,
     128,   129,   130,   131,   132,   134,    19,     0,    24,    26,
       0,    29,    41,     0,     0,    52,     2,    23,     0,    28,
       0,    30,     0,    43,    39,    51,   133,   133,   133,   133,
       0,    57,   133,   133,   133,   133,    27,     0,    32,     6,
       0,     0,     0,     0,     0,     0,    66,    54,    53,    58,
      59,    60,    61,    31,    47,    45,    42,     0,    62,    63,
      64,    65,    70,    55,    67,    49,     0,    47,     0,   133,
       0,    68,    46,    48,     0,     0,     0,    44,   133,     0,
      78,    71,     0,     0,     0,    74,     0,    81,   133,   133,
       0,    73,    75,     0,    80,     0,   105,    76,    77,    72,
      79,     0,     0,   113,     0,     0,     0,     0,   133,     0,
       0,     0,   126,     0,    69,     0,     0,   133,     0,     0,
     127,   133,     0,     0,    84,     0,   108,   133,   114,    83,
       0,     0,    88,    85,   133,     0,     0,   109,     0,     0,
     133,     0,     0,   107,     0,   122,   110,   133,     0,   121,
       0,     0,    82,    90,    89,     0,   123,     0,   116,     0,
       0,   117,    87,    86,    99,     0,     0,   106,     0,   124,
     118,   133,     0,     0,     0,   100,   112,   111,     0,   125,
       0,     0,   133,   133,    91,   101,     0,     0,   115,   133,
     103,   102,     0,   120,   119,   104,     0,    92,    94,     0,
       0,    95,     0,    93,     0,     0,     0,    96,    98,    97
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    11,    16,    17,    20,    33,    46,
      61,    72,    13,    23,    36,    47,    63,    73,    90,    91,
     106,   116,   117,    49,    64,    80,    98,    65,    81,    82,
      83,    84,    85,   113,   114,   120,   130,   134,   135,   137,
     146,   159,   173,   174,   192,   204,   214,   242,   250,   247,
     248,   224,   225,   153,   168,   186,   187,   157,   189,   178,
     210,   211,   181,   207,   230,   164,    37,    55,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -184
static const yytype_int16 yypact[] =
{
      -2,    22,    18,    37,  -184,    15,  -184,    33,    50,  -184,
     -42,    27,    56,    78,    93,    94,     2,  -184,  -184,    11,
      31,  -184,    80,    81,  -184,  -184,    40,  -184,  -184,    76,
    -184,  -184,    12,    34,  -184,  -184,    64,  -184,    -6,  -184,
    -184,  -184,    79,  -184,  -184,    10,    38,    71,  -184,    95,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,    77,  -184,  -184,
       5,   -43,  -184,    88,    70,   -24,  -184,  -184,    83,  -184,
       1,  -184,    96,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
      62,  -184,  -184,  -184,  -184,  -184,  -184,    48,  -184,  -184,
      75,    45,   111,   112,   113,   114,    85,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,    87,  -184,  -184,   116,  -184,  -184,
    -184,  -184,    46,    85,  -184,  -184,    90,    87,   115,  -184,
     118,  -184,  -184,  -184,   120,   123,    72,  -184,  -184,     8,
      67,  -184,   128,   129,     4,  -184,     3,    89,  -184,  -184,
      91,  -184,  -184,    73,  -184,   126,    97,  -184,  -184,  -184,
    -184,    98,   130,    99,    65,   101,   131,   -37,  -184,   133,
     100,   104,  -184,   103,  -184,   140,   106,  -184,   141,    92,
    -184,  -184,   102,   -21,  -184,   146,   105,  -184,  -184,  -184,
     150,   148,  -184,  -184,  -184,   102,   -23,  -184,   153,   152,
    -184,    82,   -41,  -184,   154,   107,  -184,  -184,   108,  -184,
     119,   121,  -184,  -184,  -184,    84,  -184,   110,  -184,   102,
     -28,  -184,  -184,  -184,   -47,   122,   124,  -184,   155,   109,
    -184,  -184,   164,   166,    -5,  -184,  -184,  -184,    86,  -184,
     125,   169,  -184,  -184,  -184,  -184,   127,   134,  -184,  -184,
    -184,  -184,   135,  -184,  -184,  -184,   102,   135,  -184,   163,
     132,  -184,    36,  -184,   136,   137,   139,  -184,  -184,  -184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,  -184,  -184,  -184,  -184,   160,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,   117,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,    66,  -184,  -184,  -184,    47,  -184,
    -184,  -184,  -184,     9,  -184,  -184,  -184,  -184,  -184,  -184,
     -57,  -184,   -32,  -184,  -184,  -184,     7,  -184,  -184,  -184,
    -184,   -16,  -183,  -184,  -184,  -184,   -25,  -184,  -184
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      39,    50,   194,   234,   162,    87,   202,   143,     1,    68,
      26,    27,   140,   141,    57,    29,    42,   219,     6,    70,
     195,    71,   182,     9,   203,   221,   218,   172,   209,   185,
       4,   222,   223,     5,    30,    14,    15,    69,    43,    58,
     254,   255,   256,   163,    76,    77,    78,    79,    18,    19,
       7,    92,    93,    94,    95,    31,    32,    99,   100,   101,
     102,    44,    45,   249,    88,    12,   144,   221,    59,    60,
      96,    97,    21,   222,   223,    51,    52,    53,    54,    14,
      15,   132,   133,   104,   105,   132,   133,   200,   201,   215,
     216,   236,   237,    10,   125,    22,    24,    25,    34,    41,
      35,    40,    48,   131,    62,    56,    67,    66,    74,    75,
      89,   103,   107,   147,   148,    86,   108,   109,   110,   111,
     124,   119,   115,   118,   122,   112,   126,   127,   128,   136,
     129,   138,   139,   165,   151,   145,   150,   158,   155,   161,
     154,   166,   175,   160,   170,   171,   179,   152,   169,   176,
     149,   184,   188,   156,   172,   190,   191,   185,   197,   193,
     198,   217,   205,   228,   209,   199,   177,   232,   212,   233,
     213,   252,   208,   167,   239,   226,    28,   227,   180,   121,
     238,   142,   183,   246,   243,   257,   258,   206,   259,   229,
     251,   244,   235,   196,   220,     0,   231,     0,   253,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,     0,
       0,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123
};

static const yytype_int16 yycheck[] =
{
      25,     7,   185,     8,    41,     4,    47,     4,    10,     4,
       8,     9,     8,     9,     4,     4,     4,    45,     0,    62,
      43,    64,    43,     8,    65,    72,   209,    48,    56,    52,
       8,    78,    79,    11,    23,    77,    78,    32,    26,    29,
       4,     5,     6,    80,    68,    69,    70,    71,    21,    22,
      13,    76,    77,    78,    79,    24,    25,    82,    83,    84,
      85,    27,    28,   246,    63,    15,    63,    72,    30,    31,
       8,     9,    16,    78,    79,    81,    82,    83,    84,    77,
      78,    77,    78,     8,     9,    77,    78,     5,     6,     5,
       6,     5,     6,    60,   119,    17,     3,     3,    18,    23,
      19,    61,    38,   128,    33,    26,    29,    12,    20,    39,
      14,    63,    67,   138,   139,    32,     5,     5,     5,     5,
       5,    75,    35,     7,    34,    40,     8,     7,     5,    62,
      58,     3,     3,   158,     8,    46,    63,    72,     8,     8,
      42,     8,   167,    42,    41,     5,   171,    50,    44,     8,
      59,     5,   177,    54,    48,     5,     8,    52,     5,   184,
       8,    51,     8,     8,    56,   190,    74,     3,    49,     3,
      49,     8,   197,    73,     5,    53,    16,    53,    76,   113,
      55,   134,   173,    48,    57,    49,    49,    80,    49,    80,
     247,    57,   224,   186,   210,    -1,   221,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    86,    87,     8,    11,     0,    13,    88,     8,
      60,    89,    15,    97,    77,    78,    90,    91,    21,    22,
      92,    16,    17,    98,     3,     3,     8,     9,    91,     4,
      23,    24,    25,    93,    18,    19,    99,   151,   153,   151,
      61,    23,     4,    26,    27,    28,    94,   100,    38,   108,
       7,    81,    82,    83,    84,   152,    26,     4,    29,    30,
      31,    95,    33,   101,   109,   112,    12,    29,     4,    32,
      62,    64,    96,   102,    20,    39,    68,    69,    70,    71,
     110,   113,   114,   115,   116,   117,    32,     4,    63,    14,
     103,   104,   151,   151,   151,   151,     8,     9,   111,   151,
     151,   151,   151,    63,     8,     9,   105,    67,     5,     5,
       5,     5,    40,   118,   119,    35,   106,   107,     7,    75,
     120,   119,    34,   106,     5,   151,     8,     7,     5,    58,
     121,   151,    77,    78,   122,   123,    62,   124,     3,     3,
       8,     9,   123,     4,    63,    46,   125,   151,   151,    59,
      63,     8,    50,   138,    42,     8,    54,   142,    72,   126,
      42,     8,    41,    80,   150,   151,     8,    73,   139,    44,
      41,     5,    48,   127,   128,   151,     8,    74,   144,   151,
      76,   147,    43,   128,     5,    52,   140,   141,   151,   143,
       5,     8,   129,   151,   147,    43,   141,     5,     8,   151,
       5,     6,    47,    65,   130,     8,    80,   148,   151,    56,
     145,   146,    49,    49,   131,     5,     6,    51,   147,    45,
     146,    72,    78,    79,   136,   137,    53,    53,     8,    80,
     149,   151,     3,     3,     8,   137,     5,     6,    55,     5,
     151,   151,   132,    57,    57,   151,    48,   134,   135,   147,
     133,   135,     8,    66,     4,     5,     6,    49,    49,    49
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

    {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element");}
    break;

  case 8:

    {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element"); parserData->generalStatusTypePresent = false;}
    break;

  case 11:

    { osresult->setGeneralStatusType((yyvsp[(2) - (3)].sval));  free((yyvsp[(2) - (3)].sval));  ; parserData->generalStatusTypePresent = true;}
    break;

  case 12:

    {  osresult->setGeneralStatusDescription((yyvsp[(2) - (3)].sval));    free((yyvsp[(2) - (3)].sval));}
    break;

  case 15:

    {osresult->setServiceURI( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;}
    break;

  case 19:

    {osresult->setServiceName( (yyvsp[(2) - (3)].sval));  free((yyvsp[(2) - (3)].sval));   parserData->errorText = NULL;}
    break;

  case 23:

    {osresult->setInstanceName( (yyvsp[(2) - (3)].sval)) ;  free((yyvsp[(2) - (3)].sval));   parserData->errorText = NULL;}
    break;

  case 27:

    {osresult->setJobID( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;}
    break;

  case 31:

    {osresult->setGeneralMessage( (yyvsp[(2) - (3)].sval));  free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;}
    break;

  case 34:

    {printf("processed systemElement");}
    break;

  case 36:

    {printf("processed serviceElement");}
    break;

  case 38:

    {printf("processed JOBSTART");}
    break;

  case 41:

    {printf("processed TIMINGINFORMATIONSTART");}
    break;

  case 43:

    {printf("processing numberOfTimes");}
    break;

  case 44:

    {
}
    break;

  case 48:

    {
}
    break;

  case 52:

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

  case 62:

    { parserData->numberOfSolutions = (yyvsp[(3) - (3)].ival); osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 63:

    {parserData->numberOfVariables = (yyvsp[(3) - (3)].ival); osresult->setVariableNumber((yyvsp[(3) - (3)].ival)); }
    break;

  case 64:

    {parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 65:

    {parserData->numberOfObjectives = (yyvsp[(3) - (3)].ival); osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 69:

    {parserData->solutionIdx++;}
    break;

  case 71:

    {if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, NULL, "target objective index must be negative");
*(parserData->objectiveIdx + parserData->solutionIdx) = (yyvsp[(3) - (4)].ival);}
    break;

  case 72:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element");  osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
    break;

  case 73:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element"); parserData->statusTypePresent = false; osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
    break;

  case 76:

    {parserData->statusType = (yyvsp[(2) - (3)].sval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].sval));}
    break;

  case 77:

    {parserData->statusDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 86:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(parserData->primalSolution[parserData->solutionIdx] + parserData->kounter ) = (yyvsp[(4) - (5)].dval);
	}
    break;

  case 87:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(parserData->primalSolution[parserData->solutionIdx] + parserData->kounter) = (yyvsp[(4) - (5)].ival);
}
    break;

  case 90:

    { 
   // parserData->numberOfOtherVariableResults++;
	parserData->otherVarStruct = new OtherVariableResultStruct(); 
	parserData->otherVarStruct->otherVarText = new std::string[parserData->numberOfVariables];}
    break;

  case 91:

    {if(parserData->otherNamePresent == false) osrlerror(NULL, NULL, NULL, "other element requires name attribute"); 
	parserData->otherNamePresent = false;  
	}
    break;

  case 92:

    { if(parserData->otherVarStruct->numberOfVar <= 0) osrlerror(NULL, NULL,  parserData, "must specify the number of varaibles") ;}
    break;

  case 93:

    {parserData->otherVarVec.push_back( parserData->otherVarStruct); parserData->numberOfOtherVariableResults++; }
    break;

  case 96:

    { 
std::ostringstream outStr;
outStr << (yyvsp[(4) - (5)].sval);
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
free((yyvsp[(4) - (5)].sval)); parserData->errorText = NULL;
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
}
    break;

  case 97:

    { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << (yyvsp[(4) - (5)].dval);
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
}
    break;

  case 98:

    { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << (yyvsp[(4) - (5)].ival);
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
}
    break;

  case 102:

    { parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 103:

    {   parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 104:

    {parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);}
    break;

  case 111:

    { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = (yyvsp[(4) - (5)].dval);
}
    break;

  case 112:

    { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = (yyvsp[(4) - (5)].ival);}
    break;

  case 114:

    {
			if( parserData->numberOfConstraints > 0){
				parserData->dualSolution = new double*[ parserData->numberOfSolutions];
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->dualSolution[ i] = new double[ parserData->numberOfConstraints];
				}
			}
}
    break;

  case 119:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(parserData->dualSolution[parserData->solutionIdx] + parserData->kounter) = (yyvsp[(4) - (5)].dval);}
    break;

  case 120:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(parserData->dualSolution[parserData->solutionIdx] + parserData->kounter) = (yyvsp[(4) - (5)].ival);}
    break;

  case 121:

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


