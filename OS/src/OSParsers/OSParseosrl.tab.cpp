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
     NUMBEROFVARATT = 332,
     NUMBEROFOBJATT = 333,
     NUMBEROFCONATT = 334,
     TARGETOBJECTIVEIDXATT = 335,
     IDXATT = 336,
     TYPEATT = 337,
     EMPTYTYPEATT = 338,
     DESCRIPTIONATT = 339,
     EMPTYDESCRIPTIONATT = 340,
     NAMEATT = 341,
     EMPTYNAMEATT = 342,
     CATEGORYATT = 343,
     EMPTYCATEGORYATT = 344,
     UNITATT = 345,
     EMPTYUNITATT = 346,
     VALUEATT = 347,
     EMPTYVALUEATT = 348,
     DUMMY = 349
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
#define NUMBEROFVARATT 332
#define NUMBEROFOBJATT 333
#define NUMBEROFCONATT 334
#define TARGETOBJECTIVEIDXATT 335
#define IDXATT 336
#define TYPEATT 337
#define EMPTYTYPEATT 338
#define DESCRIPTIONATT 339
#define EMPTYDESCRIPTIONATT 340
#define NAMEATT 341
#define EMPTYNAMEATT 342
#define CATEGORYATT 343
#define EMPTYCATEGORYATT 344
#define UNITATT 345
#define EMPTYUNITATT 346
#define VALUEATT 347
#define EMPTYVALUEATT 348
#define DUMMY 349




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
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  99
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNRULES -- Number of states.  */
#define YYNSTATES  308

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   349

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,    96,
      98,     2,     2,    97,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    95,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
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
     226,   230,   231,   234,   235,   246,   247,   252,   257,   261,
     263,   266,   270,   272,   276,   278,   279,   283,   286,   287,
     298,   299,   304,   309,   311,   314,   320,   322,   324,   328,
     329,   332,   338,   340,   341,   344,   346,   348,   350,   352,
     357,   359,   363,   365,   369,   373,   374,   377,   383,   385,
     387,   389,   391,   392,   402,   407,   408,   411,   417,   423,
     427,   428,   429,   440,   445,   447,   450,   456,   462,   466,
     470,   471,   473,   474,   476,   478,   481,   483,   486,   488,
     490,   492,   494,   495
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     100,     0,    -1,   101,   102,   111,   112,   113,   126,    14,
      -1,    11,     9,    -1,    11,    13,     9,    -1,    -1,    15,
     103,   106,   107,   108,   109,   110,    16,    -1,    62,   104,
       9,    63,    -1,    62,   104,    10,    -1,   105,    -1,   104,
     105,    -1,    82,     3,   179,    -1,    83,    -1,    84,     3,
     179,    -1,    85,    -1,    -1,    23,    -1,    24,     4,    25,
      -1,    24,    25,    -1,    -1,    26,    -1,    27,     4,    28,
      -1,    27,    28,    -1,    -1,    29,    -1,    30,     4,    31,
      -1,    30,    31,    -1,    -1,    32,    -1,    33,     4,    34,
      -1,    33,    34,    -1,    -1,    66,    -1,    64,     4,    65,
      -1,    64,    65,    -1,    -1,    17,    18,    -1,    -1,    19,
      20,    -1,    -1,    21,   114,    22,    -1,    -1,    35,   115,
     116,    -1,    69,     7,     5,     7,    -1,    10,    -1,     9,
     117,    36,    -1,    -1,   117,   118,    -1,    37,    -1,    38,
     119,     9,   125,    39,    -1,    -1,   119,   120,    -1,   121,
      -1,   122,    -1,   123,    -1,   124,    -1,    82,     3,     7,
      -1,    83,    -1,    88,     3,     7,    -1,    89,    -1,    90,
       3,     7,    -1,    91,    -1,    84,     3,     7,    -1,    85,
      -1,     6,    -1,     5,    -1,    -1,    40,   127,    41,    -1,
     129,   128,    -1,    10,    -1,     9,   135,    -1,    -1,   129,
     130,    -1,   131,   179,    -1,   132,   179,    -1,   133,   179,
      -1,   134,   179,    -1,    70,   179,     5,    -1,    71,   179,
       5,    -1,    72,   179,     5,    -1,    73,   179,     5,    -1,
      -1,   135,   136,    -1,    -1,    42,   137,   138,     9,   139,
     142,   143,   163,   168,   177,    -1,    -1,    80,   179,     5,
     179,    -1,    60,   140,     9,    61,    -1,    60,   140,    10,
      -1,   141,    -1,   140,   141,    -1,    82,     3,   179,    -1,
      83,    -1,    84,     3,   179,    -1,    85,    -1,    -1,    64,
       4,    65,    -1,    64,    65,    -1,    -1,    48,   144,     9,
      44,   145,     9,   146,    45,   150,    49,    -1,    -1,    74,
     179,     5,   179,    -1,    77,   179,     5,   179,    -1,   147,
      -1,   146,   147,    -1,    50,   149,     9,   148,    51,    -1,
       5,    -1,     6,    -1,    81,     5,   179,    -1,    -1,   150,
     151,    -1,   152,   153,     9,   159,    68,    -1,    67,    -1,
      -1,   154,   153,    -1,   155,    -1,   156,    -1,   157,    -1,
     158,    -1,    77,   179,     5,   179,    -1,    93,    -1,    92,
       3,   179,    -1,    87,    -1,    86,     3,   179,    -1,    84,
       3,   179,    -1,    -1,   160,   159,    -1,   162,   174,     9,
     161,    51,    -1,     4,    -1,     5,    -1,     6,    -1,    50,
      -1,    -1,    52,     9,    44,   164,     9,   165,    45,   175,
      53,    -1,    78,   179,     5,   179,    -1,    -1,   165,   166,
      -1,    54,   167,     9,     6,    55,    -1,    54,   167,     9,
       5,    55,    -1,    81,     5,   179,    -1,    -1,    -1,    56,
       9,    46,   170,   169,     9,   171,    47,   176,    57,    -1,
      79,   179,     5,   179,    -1,   172,    -1,   171,   172,    -1,
      58,   173,     9,     6,    59,    -1,    58,   173,     9,     5,
      59,    -1,    81,     5,   179,    -1,    81,     5,   179,    -1,
      -1,    94,    -1,    -1,    94,    -1,   178,    -1,    94,   178,
      -1,    43,    -1,   181,     7,    -1,    95,    -1,    96,    -1,
      97,    -1,    98,    -1,    -1,   181,   180,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   121,   122,   126,   126,   128,   129,   131,
     132,   134,   135,   136,   137,   140,   141,   142,   143,   146,
     147,   148,   149,   151,   152,   153,   154,   156,   157,   158,
     159,   161,   162,   163,   164,   166,   166,   168,   168,   170,
     170,   172,   173,   175,   181,   181,   183,   183,   185,   186,
     198,   198,   200,   200,   200,   200,   202,   203,   205,   206,
     208,   209,   211,   212,   215,   216,   218,   218,   220,   223,
     224,   226,   227,   229,   230,   231,   232,   236,   237,   238,
     239,   242,   243,   246,   246,   256,   257,   263,   264,   267,
     268,   270,   271,   272,   273,   275,   276,   280,   286,   287,
     298,   299,   309,   316,   317,   319,   322,   327,   333,   337,
     338,   340,   359,   368,   371,   373,   373,   373,   373,   375,
     384,   387,   393,   399,   405,   414,   415,   417,   434,   435,
     436,   438,   443,   444,   453,   457,   458,   460,   466,   474,
     477,   479,   478,   496,   502,   503,   505,   512,   520,   522,
     526,   527,   529,   530,   532,   533,   535,   543,   545,   546,
     547,   548,   550,   551
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
  "NUMBEROFVARATT", "NUMBEROFOBJATT", "NUMBEROFCONATT",
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
  "otherConstraints", "otherSolution", "solutionEnd", "quote",
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
     345,   346,   347,   348,   349,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    99,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   105,   105,   106,   106,   106,   106,   107,
     107,   107,   107,   108,   108,   108,   108,   109,   109,   109,
     109,   110,   110,   110,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   120,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   125,   125,   126,   126,   127,   128,
     128,   129,   129,   130,   130,   130,   130,   131,   132,   133,
     134,   135,   135,   137,   136,   138,   138,   139,   139,   140,
     140,   141,   141,   141,   141,   142,   142,   142,   143,   143,
     144,   144,   145,   146,   146,   147,   148,   148,   149,   150,
     150,   151,   152,   153,   153,   154,   154,   154,   154,   155,
     156,   156,   157,   157,   158,   159,   159,   160,   161,   161,
     161,   162,   163,   163,   164,   165,   165,   166,   166,   167,
     168,   169,   168,   170,   171,   171,   172,   172,   173,   174,
     175,   175,   176,   176,   177,   177,   178,   179,   180,   180,
     180,   180,   181,   181
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
       3,     0,     2,     0,    10,     0,     4,     4,     3,     1,
       2,     3,     1,     3,     1,     0,     3,     2,     0,    10,
       0,     4,     4,     1,     2,     5,     1,     1,     3,     0,
       2,     5,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     3,     0,     2,     5,     1,     1,
       1,     1,     0,     9,     4,     0,     2,     5,     5,     3,
       0,     0,    10,     4,     1,     2,     5,     5,     3,     3,
       0,     1,     0,     1,     1,     2,     1,     2,     1,     1,
       1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    35,     4,
       0,    15,     0,    37,     0,    12,     0,    14,     0,     9,
      16,     0,    19,    36,     0,    39,   162,   162,     0,     8,
      10,     0,    18,    20,     0,    23,    38,    41,    66,    11,
       0,    13,     7,    17,     0,    22,    24,     0,    27,     0,
       0,    71,     0,   157,   158,   159,   160,   161,   163,    21,
       0,    26,    28,     0,    31,     0,     0,    40,     0,     0,
       2,    25,     0,    30,     0,    32,     0,     0,    46,    44,
      42,    67,    81,    69,   162,   162,   162,   162,    68,    72,
     162,   162,   162,   162,    29,     0,    34,     6,     0,     0,
      70,     0,     0,     0,     0,    73,    74,    75,    76,    33,
      43,    45,    48,    50,    47,    83,    82,    77,    78,    79,
      80,     0,    85,     0,     0,    57,     0,    63,     0,    59,
       0,    61,    51,    52,    53,    54,    55,   162,     0,    65,
      64,     0,     0,     0,     0,     0,     0,     0,    49,    56,
      62,    58,    60,   162,     0,    95,    86,     0,    92,     0,
      94,     0,    89,     0,    98,   162,   162,     0,    88,    90,
       0,    97,   100,   132,    91,    93,    87,    96,   162,     0,
       0,   140,     0,     0,     0,     0,     0,   162,     0,     0,
       0,   156,     0,    84,   154,   101,   162,     0,   162,     0,
       0,   155,     0,     0,     0,   135,   162,   141,   162,     0,
       0,   103,   162,     0,     0,     0,   102,     0,     0,   109,
     104,   134,   150,     0,   136,   162,     0,   162,     0,     0,
     151,     0,     0,     0,   143,     0,     0,   144,   108,   106,
     107,     0,    99,   112,   110,   113,   133,   162,     0,     0,
       0,   152,   145,   105,   162,     0,     0,   122,     0,   120,
       0,   113,   115,   116,   117,   118,   139,     0,     0,   162,
       0,   153,     0,     0,   162,   162,   162,   125,   114,   138,
     137,   148,     0,     0,   142,   162,   124,   123,   121,   131,
       0,   125,     0,   147,   146,   119,   111,   126,     0,     0,
     162,     0,   149,   128,   129,   130,     0,   127
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    11,    18,    19,    22,    35,    48,
      64,    76,    13,    25,    38,    50,    66,    80,    99,   114,
     121,   132,   133,   134,   135,   136,   141,    52,    68,    88,
      69,    89,    90,    91,    92,    93,   100,   116,   122,   138,
     155,   161,   162,   164,   173,   179,   197,   210,   211,   241,
     218,   229,   244,   245,   260,   261,   262,   263,   264,   265,
     290,   291,   306,   292,   181,   199,   213,   224,   233,   186,
     215,   207,   236,   237,   250,   299,   231,   272,   193,   194,
      39,    58,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
      12,    29,    14,    22,   -70,     9,   -70,   -36,    84,   -70,
     -39,    16,    91,    94,   111,   -70,   112,   -70,     3,   -70,
     -70,     4,    35,   -70,    96,    97,   -70,   -70,    54,   -70,
     -70,    95,   -70,   -70,     5,    26,   -70,    86,    79,   -70,
      -6,   -70,   -70,   -70,    99,   -70,   -70,     1,    41,    53,
     101,   -70,   110,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     103,   -70,   -70,     0,    36,   118,    70,   -70,    87,    -3,
     -70,   -70,   107,   -70,     6,   -70,   113,   125,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,    66,   -70,   -70,   126,    15,
      90,   130,   131,   132,   135,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,    -7,    62,    98,   140,   -70,   141,   -70,   142,   -70,
     143,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   138,   -70,
     -70,   109,   145,   146,   147,   148,   144,   104,   -70,   -70,
     -70,   -70,   -70,   -70,   -35,    92,   -70,   154,   -70,   155,
     -70,    11,   -70,     7,   114,   -70,   -70,    89,   -70,   -70,
     105,   -70,    85,   115,   -70,   -70,   -70,   -70,   -70,   152,
     156,   116,   158,   122,   124,   164,   -40,   -70,   117,   108,
     128,   -70,   133,   -70,   -70,   -70,   -70,   166,   -70,   168,
     120,   -70,   173,   134,   175,   -70,   -70,   -70,   -70,   121,
      -9,   -70,   -70,   -26,   177,   174,   -70,   182,   179,   -70,
     -70,   -70,   119,   123,   -70,   -70,   137,   -70,   100,   -32,
     -70,   136,   185,   183,   -70,   127,   -31,   -70,   -70,   -70,
     -70,   150,   -70,   -70,   -70,   -62,   -70,   -70,   102,   186,
     184,   129,   -70,   -70,   -70,   193,   194,   -70,   200,   -70,
     196,   -62,   -70,   -70,   -70,   -70,   -70,   151,   157,   -70,
     106,   -70,   153,   202,   -70,   -70,   -70,   159,   -70,   -70,
     -70,   -70,   160,   162,   -70,   -70,   -70,   -70,   -70,   -70,
     149,   159,   163,   -70,   -70,   -70,   -70,   -70,   206,   205,
     -70,    93,   -70,   -70,   -70,   -70,   165,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -70,   -70,   -70,   -70,   197,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,    57,   -70,   -70,   -70,   -70,   -70,    18,   -70,
     -70,   -70,   -70,   -70,   -37,   -70,   -70,   -70,   -70,   -70,
     -69,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -11,   -70,   -70,   -70,   -70,   -70,    34,
     -27,   -70,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      41,    53,   123,   191,    72,    60,    82,    83,    31,    44,
      95,   170,    28,    29,     6,   254,   251,   242,     9,   222,
     167,   168,   255,     1,   256,   257,    10,   235,   223,    32,
     258,   259,    61,    45,    73,   243,   219,     7,     4,    20,
      21,   209,     5,    14,    15,    16,    17,   157,   158,   159,
     160,   111,   112,   113,   192,    46,    47,   101,   102,   103,
     104,    33,    34,   105,   106,   107,   108,    84,    85,    86,
      87,    96,   171,    62,    63,   124,   125,   126,   127,    78,
      79,   128,   129,   130,   131,    14,    15,    16,    17,    54,
      55,    56,    57,   157,   158,   159,   160,   303,   304,   305,
      74,    12,    75,   139,   140,   239,   240,   267,   268,    23,
     146,   282,   283,    24,    26,    27,    36,    42,    37,    51,
      43,    49,    65,    67,    70,    77,   156,    59,    81,    97,
      98,   109,   115,   110,    71,   117,   118,   119,   174,   175,
     120,    94,   137,   142,   143,   144,   145,   147,   148,   153,
     176,   182,   149,   150,   151,   152,   163,   165,   166,   178,
     195,   183,   172,   187,   154,   184,   188,   180,   189,   202,
     177,   204,   185,   190,   200,   203,   191,   205,   208,   214,
     212,   216,   225,   226,   209,   221,   198,   227,   228,   246,
     247,   269,   248,   270,   196,   235,   274,   275,   234,   206,
     238,   253,   217,   276,   232,   277,   279,   285,   249,   289,
     284,   300,   280,   230,   301,    30,   307,   296,   169,   293,
     266,   294,   297,   271,   278,   252,   201,   273,   220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,   298,     0,     0,   286,   287,   288,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   302
};

static const yytype_int16 yycheck[] =
{
      27,     7,     9,    43,     4,     4,     9,    10,     4,     4,
       4,     4,     9,    10,     0,    77,    47,    49,     9,    45,
       9,    10,    84,    11,    86,    87,    62,    58,    54,    25,
      92,    93,    31,    28,    34,    67,    45,    15,     9,    23,
      24,    50,    13,    82,    83,    84,    85,    82,    83,    84,
      85,    36,    37,    38,    94,    29,    30,    84,    85,    86,
      87,    26,    27,    90,    91,    92,    93,    70,    71,    72,
      73,    65,    65,    32,    33,    82,    83,    84,    85,     9,
      10,    88,    89,    90,    91,    82,    83,    84,    85,    95,
      96,    97,    98,    82,    83,    84,    85,     4,     5,     6,
      64,    17,    66,     5,     6,     5,     6,     5,     6,    18,
     137,     5,     6,    19,     3,     3,    20,    63,    21,    40,
      25,    35,    69,    22,    14,     7,   153,    28,    41,    16,
       5,    65,    42,     7,    31,     5,     5,     5,   165,   166,
       5,    34,    80,     3,     3,     3,     3,     9,    39,     5,
      61,   178,     7,     7,     7,     7,    64,     3,     3,    74,
     187,     9,    48,     5,    60,     9,    44,    52,    44,   196,
      65,   198,    56,     9,    46,     9,    43,     9,     5,   206,
       5,   208,     5,     9,    50,   212,    78,     5,     9,    53,
       5,     5,     9,     9,    77,    58,     3,     3,   225,    79,
     227,    51,    81,     3,    81,     9,    55,     5,    81,    50,
      57,     5,    55,    94,     9,    18,    51,    68,   161,    59,
     247,    59,   291,    94,   261,   236,   192,   254,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    81,    -1,    -1,   274,   275,   276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   300
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,   100,   101,     9,    13,     0,    15,   102,     9,
      62,   103,    17,   111,    82,    83,    84,    85,   104,   105,
      23,    24,   106,    18,    19,   112,     3,     3,     9,    10,
     105,     4,    25,    26,    27,   107,    20,    21,   113,   179,
     181,   179,    63,    25,     4,    28,    29,    30,   108,    35,
     114,    40,   126,     7,    95,    96,    97,    98,   180,    28,
       4,    31,    32,    33,   109,    69,   115,    22,   127,   129,
      14,    31,     4,    34,    64,    66,   110,     7,     9,    10,
     116,    41,     9,    10,    70,    71,    72,    73,   128,   130,
     131,   132,   133,   134,    34,     4,    65,    16,     5,   117,
     135,   179,   179,   179,   179,   179,   179,   179,   179,    65,
       7,    36,    37,    38,   118,    42,   136,     5,     5,     5,
       5,   119,   137,     9,    82,    83,    84,    85,    88,    89,
      90,    91,   120,   121,   122,   123,   124,    80,   138,     5,
       6,   125,     3,     3,     3,     3,   179,     9,    39,     7,
       7,     7,     7,     5,    60,   139,   179,    82,    83,    84,
      85,   140,   141,    64,   142,     3,     3,     9,    10,   141,
       4,    65,    48,   143,   179,   179,    61,    65,    74,   144,
      52,   163,   179,     9,     9,    56,   168,     5,    44,    44,
       9,    43,    94,   177,   178,   179,    77,   145,    78,   164,
      46,   178,   179,     9,   179,     9,    79,   170,     5,    50,
     146,   147,     5,   165,   179,   169,   179,    81,   149,    45,
     147,   179,    45,    54,   166,     5,     9,     5,     9,   150,
      94,   175,    81,   167,   179,    58,   171,   172,   179,     5,
       6,   148,    49,    67,   151,   152,    53,     5,     9,    81,
     173,    47,   172,    51,    77,    84,    86,    87,    92,    93,
     153,   154,   155,   156,   157,   158,   179,     5,     6,     5,
       9,    94,   176,   179,     3,     3,     3,     9,   153,    55,
      55,   179,     5,     6,    57,     5,   179,   179,   179,    50,
     159,   160,   162,    59,    59,   179,    68,   159,    81,   174,
       5,     9,   179,     4,     5,     6,   161,    51
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

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, NULL, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
}
    break;

  case 49:

    {if (parserData->ivar == parserData->numberOfTimes)
           osrlerror(NULL, NULL, NULL, "Too many time measurements");
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
        osrlerror(NULL, NULL, NULL, "too many solutions"); 
    parserData->solutionIdx++;
    

    
   }
    break;

  case 86:

    {
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, NULL, "target objective index must be negative");
/*  	osresult->optimization->solution[parserData->solutionIdx]->targetObjectiveIdx = $3;*/
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 }
    break;

  case 87:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element");  osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
    break;

  case 88:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element"); parserData->statusTypePresent = false; osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
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

  case 156:

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


