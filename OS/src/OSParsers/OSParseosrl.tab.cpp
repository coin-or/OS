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
     GENERALSTART = 271,
     GENERALEND = 272,
     SYSTEMSTART = 273,
     SYSTEMEND = 274,
     SERVICESTART = 275,
     SERVICEEND = 276,
     JOBSTART = 277,
     JOBEND = 278,
     SERVICEURISTARTANDEND = 279,
     SERVICEURISTART = 280,
     SERVICEURIEND = 281,
     SERVICENAMESTARTANDEND = 282,
     SERVICENAMESTART = 283,
     SERVICENAMEEND = 284,
     INSTANCENAMESTARTANDEND = 285,
     INSTANCENAMESTART = 286,
     INSTANCENAMEEND = 287,
     JOBIDSTARTANDEND = 288,
     JOBIDSTART = 289,
     JOBIDEND = 290,
     TIMINGINFORMATIONSTART = 291,
     TIMINGINFORMATIONEND = 292,
     TIMESTARTANDEND = 293,
     TIMESTART = 294,
     TIMEEND = 295,
     OPTIMIZATIONSTART = 296,
     OPTIMIZATIONEND = 297,
     SOLUTIONSTART = 298,
     SOLUTIONEND = 299,
     VALUESSTART = 300,
     VALUESEND = 301,
     DUALVALUESSTART = 302,
     DUALVALUESEND = 303,
     VARIABLESSTART = 304,
     VARIABLESEND = 305,
     VARSTART = 306,
     VAREND = 307,
     OBJECTIVESSTART = 308,
     OBJECTIVESEND = 309,
     OBJSTART = 310,
     OBJEND = 311,
     CONSTRAINTSSTART = 312,
     CONSTRAINTSEND = 313,
     CONSTART = 314,
     CONEND = 315,
     STATUSSTART = 316,
     STATUSEND = 317,
     GENERALSTATUSSTART = 318,
     GENERALSTATUSEND = 319,
     MESSAGESTART = 320,
     MESSAGEEND = 321,
     MESSAGESTARTANDEND = 322,
     OTHERSTART = 323,
     OTHEREND = 324,
     NUMBEROFTIMESATT = 325,
     NUMBEROFSOLUTIONSATT = 326,
     NUMBEROFVARIABLESATT = 327,
     NUMBEROFCONSTRAINTSATT = 328,
     NUMBEROFOBJECTIVESATT = 329,
     NUMBEROFOTHERVARIABLERESULTSATT = 330,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 331,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 332,
     NUMBEROFOTHERSOLUTIONRESULTSATT = 333,
     NUMBEROFITEMSATT = 334,
     OTHERSOLUTIONRESULTSSTART = 335,
     OTHERSOLUTIONRESULTSEND = 336,
     OTHERSOLUTIONRESULTSTART = 337,
     OTHERSOLUTIONRESULTEND = 338,
     ITEMSTART = 339,
     ITEMEND = 340,
     NUMBEROFVARATT = 341,
     NUMBEROFOBJATT = 342,
     NUMBEROFCONATT = 343,
     TARGETOBJECTIVEIDXATT = 344,
     IDXATT = 345,
     TYPEATT = 346,
     EMPTYTYPEATT = 347,
     DESCRIPTIONATT = 348,
     EMPTYDESCRIPTIONATT = 349,
     NAMEATT = 350,
     EMPTYNAMEATT = 351,
     CATEGORYATT = 352,
     EMPTYCATEGORYATT = 353,
     UNITATT = 354,
     EMPTYUNITATT = 355,
     VALUEATT = 356,
     EMPTYVALUEATT = 357,
     DUMMY = 358
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
#define GENERALSTART 271
#define GENERALEND 272
#define SYSTEMSTART 273
#define SYSTEMEND 274
#define SERVICESTART 275
#define SERVICEEND 276
#define JOBSTART 277
#define JOBEND 278
#define SERVICEURISTARTANDEND 279
#define SERVICEURISTART 280
#define SERVICEURIEND 281
#define SERVICENAMESTARTANDEND 282
#define SERVICENAMESTART 283
#define SERVICENAMEEND 284
#define INSTANCENAMESTARTANDEND 285
#define INSTANCENAMESTART 286
#define INSTANCENAMEEND 287
#define JOBIDSTARTANDEND 288
#define JOBIDSTART 289
#define JOBIDEND 290
#define TIMINGINFORMATIONSTART 291
#define TIMINGINFORMATIONEND 292
#define TIMESTARTANDEND 293
#define TIMESTART 294
#define TIMEEND 295
#define OPTIMIZATIONSTART 296
#define OPTIMIZATIONEND 297
#define SOLUTIONSTART 298
#define SOLUTIONEND 299
#define VALUESSTART 300
#define VALUESEND 301
#define DUALVALUESSTART 302
#define DUALVALUESEND 303
#define VARIABLESSTART 304
#define VARIABLESEND 305
#define VARSTART 306
#define VAREND 307
#define OBJECTIVESSTART 308
#define OBJECTIVESEND 309
#define OBJSTART 310
#define OBJEND 311
#define CONSTRAINTSSTART 312
#define CONSTRAINTSEND 313
#define CONSTART 314
#define CONEND 315
#define STATUSSTART 316
#define STATUSEND 317
#define GENERALSTATUSSTART 318
#define GENERALSTATUSEND 319
#define MESSAGESTART 320
#define MESSAGEEND 321
#define MESSAGESTARTANDEND 322
#define OTHERSTART 323
#define OTHEREND 324
#define NUMBEROFTIMESATT 325
#define NUMBEROFSOLUTIONSATT 326
#define NUMBEROFVARIABLESATT 327
#define NUMBEROFCONSTRAINTSATT 328
#define NUMBEROFOBJECTIVESATT 329
#define NUMBEROFOTHERVARIABLERESULTSATT 330
#define NUMBEROFOTHEROBJECTIVERESULTSATT 331
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 332
#define NUMBEROFOTHERSOLUTIONRESULTSATT 333
#define NUMBEROFITEMSATT 334
#define OTHERSOLUTIONRESULTSSTART 335
#define OTHERSOLUTIONRESULTSEND 336
#define OTHERSOLUTIONRESULTSTART 337
#define OTHERSOLUTIONRESULTEND 338
#define ITEMSTART 339
#define ITEMEND 340
#define NUMBEROFVARATT 341
#define NUMBEROFOBJATT 342
#define NUMBEROFCONATT 343
#define TARGETOBJECTIVEIDXATT 344
#define IDXATT 345
#define TYPEATT 346
#define EMPTYTYPEATT 347
#define DESCRIPTIONATT 348
#define EMPTYDESCRIPTIONATT 349
#define NAMEATT 350
#define EMPTYNAMEATT 351
#define CATEGORYATT 352
#define EMPTYCATEGORYATT 353
#define UNITATT 354
#define EMPTYUNITATT 355
#define VALUEATT 356
#define EMPTYVALUEATT 357
#define DUMMY 358




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
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  190
/* YYNRULES -- Number of states.  */
#define YYNSTATES  354

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   358

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   105,
     107,     2,     2,   106,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   104,     2,     2,     2,     2,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101,   102,   103
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
     109,     0,    -1,   110,   111,   120,   121,   122,   135,    15,
      -1,    12,    10,    -1,    12,    14,    10,    -1,    -1,    16,
     112,   115,   116,   117,   118,   119,    17,    -1,    63,   113,
      10,    64,    -1,    63,   113,    11,    -1,   114,    -1,   113,
     114,    -1,    91,     3,   204,    -1,    92,    -1,    93,     3,
     204,    -1,    94,    -1,    -1,    24,    -1,    25,     4,    26,
      -1,    25,    26,    -1,    -1,    27,    -1,    28,     4,    29,
      -1,    28,    29,    -1,    -1,    30,    -1,    31,     4,    32,
      -1,    31,    32,    -1,    -1,    33,    -1,    34,     4,    35,
      -1,    34,    35,    -1,    -1,    67,    -1,    65,     4,    66,
      -1,    65,    66,    -1,    -1,    18,    19,    -1,    -1,    20,
      21,    -1,    -1,    22,   123,    23,    -1,    -1,    36,   124,
     125,    -1,    70,     8,     6,     8,    -1,    11,    -1,    10,
     126,    37,    -1,    -1,   126,   127,    -1,    38,    -1,    39,
     128,    10,   134,    40,    -1,    -1,   128,   129,    -1,   130,
      -1,   131,    -1,   132,    -1,   133,    -1,    91,     3,     8,
      -1,    92,    -1,    97,     3,     8,    -1,    98,    -1,    99,
       3,     8,    -1,   100,    -1,    93,     3,     8,    -1,    94,
      -1,     7,    -1,     6,    -1,    -1,    41,   136,    42,    -1,
     138,   137,    -1,    11,    -1,    10,   144,    -1,    -1,   138,
     139,    -1,   140,   204,    -1,   141,   204,    -1,   142,   204,
      -1,   143,   204,    -1,    71,   204,     6,    -1,    72,   204,
       6,    -1,    73,   204,     6,    -1,    74,   204,     6,    -1,
      -1,   144,   145,    -1,    -1,    43,   146,   147,    10,   148,
     151,   152,   172,   177,   186,   203,    -1,    -1,    89,   204,
       6,   204,    -1,    61,   149,    10,    62,    -1,    61,   149,
      11,    -1,   150,    -1,   149,   150,    -1,    91,     3,   204,
      -1,    92,    -1,    93,     3,   204,    -1,    94,    -1,    -1,
      65,     4,    66,    -1,    65,    66,    -1,    -1,    49,   153,
      10,    45,   154,    10,   155,    46,   159,    50,    -1,    -1,
      75,   204,     6,   204,    -1,    86,   204,     6,   204,    -1,
     156,    -1,   155,   156,    -1,    51,   158,    10,   157,    52,
      -1,     6,    -1,     7,    -1,    90,     6,   204,    -1,    -1,
     159,   160,    -1,   161,   162,    10,   168,    69,    -1,    68,
      -1,    -1,   163,   162,    -1,   164,    -1,   165,    -1,   166,
      -1,   167,    -1,    86,   204,     6,   204,    -1,   102,    -1,
     101,     3,   204,    -1,    96,    -1,    95,     3,   204,    -1,
      93,     3,   204,    -1,    -1,   169,   168,    -1,   171,   183,
      10,   170,    52,    -1,     4,    -1,     6,    -1,     7,    -1,
      51,    -1,    -1,    53,    10,    45,   173,    10,   174,    46,
     184,    54,    -1,    87,   204,     6,   204,    -1,    -1,   174,
     175,    -1,    55,   176,    10,     7,    56,    -1,    55,   176,
      10,     6,    56,    -1,    90,     6,   204,    -1,    -1,    -1,
      57,    10,    47,   179,   178,    10,   180,    48,   185,    58,
      -1,    88,   204,     6,   204,    -1,   181,    -1,   180,   181,
      -1,    59,   182,    10,     7,    60,    -1,    59,   182,    10,
       6,    60,    -1,    90,     6,   204,    -1,    90,     6,   204,
      -1,    -1,   103,    -1,    -1,   103,    -1,    -1,    80,   187,
      10,   189,    81,    -1,    -1,    78,     8,     6,   188,     8,
      -1,    -1,   189,   190,    -1,    82,   191,    10,   198,    83,
      -1,    -1,    -1,   191,   192,   193,    -1,   194,    -1,   195,
      -1,   196,    -1,   197,    -1,    79,     8,     6,     8,    -1,
      96,    -1,    95,     3,   204,    -1,    97,     3,     8,    -1,
      98,    -1,    93,     3,     8,    -1,    94,    -1,    -1,   198,
     199,    -1,    84,   200,    -1,   202,    -1,    -1,     5,   201,
      85,    -1,    11,    -1,    10,    85,    -1,    44,    -1,   206,
       8,    -1,   104,    -1,   105,    -1,   106,    -1,   107,    -1,
      -1,   206,   205,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   127,   128,   132,   132,   134,   135,   137,
     138,   140,   141,   142,   143,   146,   147,   148,   149,   152,
     153,   154,   155,   157,   158,   159,   160,   162,   163,   164,
     165,   167,   168,   169,   170,   172,   172,   174,   174,   176,
     176,   178,   179,   181,   187,   187,   189,   189,   191,   192,
     204,   204,   206,   206,   206,   206,   208,   209,   211,   212,
     214,   215,   217,   218,   221,   222,   224,   224,   226,   229,
     230,   232,   233,   235,   236,   237,   238,   242,   243,   244,
     245,   248,   249,   252,   252,   259,   260,   266,   267,   270,
     271,   273,   274,   275,   276,   278,   279,   283,   289,   290,
     301,   302,   312,   319,   320,   322,   325,   330,   336,   340,
     341,   343,   362,   371,   374,   376,   376,   376,   376,   378,
     387,   390,   396,   402,   408,   417,   418,   420,   437,   438,
     439,   441,   446,   447,   456,   460,   461,   463,   469,   477,
     480,   482,   481,   499,   505,   506,   508,   515,   523,   525,
     529,   530,   532,   533,   535,   536,   543,   542,   558,   558,
     560,   570,   571,   571,   575,   575,   575,   575,   577,   596,
     602,   610,   613,   616,   619,   621,   622,   624,   634,   635,
     635,   637,   637,   640,   648,   650,   651,   652,   653,   655,
     656
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
  "OSRLEND", "GENERALSTART", "GENERALEND", "SYSTEMSTART", "SYSTEMEND",
  "SERVICESTART", "SERVICEEND", "JOBSTART", "JOBEND",
  "SERVICEURISTARTANDEND", "SERVICEURISTART", "SERVICEURIEND",
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
  "NUMBEROFOBJECTIVESATT", "NUMBEROFOTHERVARIABLERESULTSATT",
  "NUMBEROFOTHEROBJECTIVERESULTSATT", "NUMBEROFOTHERCONSTRAINTRESULTSATT",
  "NUMBEROFOTHERSOLUTIONRESULTSATT", "NUMBEROFITEMSATT",
  "OTHERSOLUTIONRESULTSSTART", "OTHERSOLUTIONRESULTSEND",
  "OTHERSOLUTIONRESULTSTART", "OTHERSOLUTIONRESULTEND", "ITEMSTART",
  "ITEMEND", "NUMBEROFVARATT", "NUMBEROFOBJATT", "NUMBEROFCONATT",
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
  "anotherSolutionResultAtt", "numberOfItems",
  "anotherSolutionResultNameATT", "anotherSolutionResultCategoryATT",
  "anotherSolutionDescriptionATT", "itemList", "anotherSolutionItem",
  "itemContent", "@5", "emptyItem", "solutionEnd", "quote",
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
     355,   356,   357,   358,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   110,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   114,   114,   115,   115,   115,   115,   116,
     116,   116,   116,   117,   117,   117,   117,   118,   118,   118,
     118,   119,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   123,   123,   124,   125,   125,   126,   126,   127,   127,
     128,   128,   129,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   135,   135,   136,   137,
     137,   138,   138,   139,   139,   139,   139,   140,   141,   142,
     143,   144,   144,   146,   145,   147,   147,   148,   148,   149,
     149,   150,   150,   150,   150,   151,   151,   151,   152,   152,
     153,   153,   154,   155,   155,   156,   157,   157,   158,   159,
     159,   160,   161,   162,   162,   163,   163,   163,   163,   164,
     165,   165,   166,   166,   167,   168,   168,   169,   170,   170,
     170,   171,   172,   172,   173,   174,   174,   175,   175,   176,
     177,   178,   177,   179,   180,   180,   181,   181,   182,   183,
     184,   184,   185,   185,   186,   186,   188,   187,   189,   189,
     190,   191,   192,   191,   193,   193,   193,   193,   194,   195,
     195,   196,   196,   197,   197,   198,   198,   199,   200,   201,
     200,   202,   202,   203,   204,   205,   205,   205,   205,   206,
     206
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
#define YYPACT_NINF -72
static const yytype_int16 yypact[] =
{
       3,    38,    40,    27,   -72,    70,   -72,    58,    91,   -72,
     -38,    37,   106,   104,   124,   -72,   125,   -72,     2,   -72,
     -72,     7,    46,   -72,   108,   110,   -72,   -72,    66,   -72,
     -72,   107,   -72,   -72,     1,    57,   -72,    95,    93,   -72,
      -7,   -72,   -72,   -72,   112,   -72,   -72,     0,    72,    65,
     114,   -72,   121,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     115,   -72,   -72,    -1,   -49,   132,    97,   -72,   100,    -4,
     -72,   -72,   117,   -72,     5,   -72,   126,   138,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,    79,   -72,   -72,   140,    12,
     103,   143,   144,   147,   148,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,    -8,    67,   105,   152,   -72,   154,   -72,   155,   -72,
     156,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   151,   -72,
     -72,   122,   157,   158,   160,   162,   165,   102,   -72,   -72,
     -72,   -72,   -72,   -72,   -16,    99,   -72,   169,   -72,   170,
     -72,    10,   -72,     6,   127,   -72,   -72,   116,   -72,   -72,
     119,   -72,   118,   128,   -72,   -72,   -72,   -72,   -72,   164,
     167,   129,   173,   130,   137,   177,   120,   -72,   131,    96,
     142,   123,   146,   -72,   -72,   181,   -72,   182,   133,   186,
     185,   -72,   -72,   190,   153,   191,   -72,   -72,   -72,   192,
     -72,   -72,   134,   -32,   -72,   -72,   -18,   193,   195,   -72,
      32,   -72,   196,   197,   -72,   -72,   -72,   135,   136,   -72,
     -72,   149,   198,   -72,   -72,   -72,   -72,   109,   -33,   -72,
     159,   204,   201,   -72,   139,   -17,   -72,   -72,   202,   -72,
     -72,   -72,   163,   -72,   -72,   -72,   -57,   -72,   -72,   111,
     208,   206,   141,   -72,   -72,   -71,   -72,   -72,   215,   216,
     -72,   217,   -72,   212,   -57,   -72,   -72,   -72,   -72,   -72,
     171,   172,   -72,   113,   -72,   174,    39,   222,   220,   -72,
     230,   -72,   231,   -72,   -72,   -72,   -72,   -72,   -72,   219,
     -72,   -72,   -72,   184,   -72,   -72,   -72,   -72,   176,   179,
     -72,   -72,    36,   -72,   235,   229,   -72,   234,   -72,   -72,
     -72,   -72,   -72,   178,   184,   161,   -72,   -72,   -72,   168,
     -72,   -72,   -72,   237,   -72,   -72,   -72,   -72,   -72,   -72,
     240,   233,   175,   -72,   -72,   -72,    75,   -72,   -72,   -72,
     -72,   -72,   200,   -72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   -72,   -72,   -72,   232,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,    87,   -72,   -72,   -72,   -72,   -72,    41,   -72,
     -72,   -72,   -72,   -72,   -25,   -72,   -72,   -72,   -72,   -72,
     -68,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,    13,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -27,   -72,   -72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      41,    53,   123,    72,    60,    44,    82,    83,   287,    95,
     170,    31,    28,    29,   224,     1,    74,   253,    75,   212,
     167,   168,   288,   289,   290,   291,   292,   293,   227,   267,
      45,   262,    61,    32,    73,   254,   268,   228,   269,   270,
       6,   328,   244,     7,   271,   272,   329,   330,     4,   111,
     112,   113,     5,    14,    15,    16,    17,   101,   102,   103,
     104,    20,    21,   105,   106,   107,   108,    84,    85,    86,
      87,    96,   171,    33,    34,   157,   158,   159,   160,   349,
       9,   350,   351,   124,   125,   126,   127,    46,    47,   128,
     129,   130,   131,    14,    15,    16,    17,    54,    55,    56,
      57,   157,   158,   159,   160,    62,    63,    78,    79,    12,
     146,   139,   140,   233,   234,   250,   251,   280,   281,   308,
     309,    10,   311,   312,    24,    23,   156,    26,    27,    36,
      42,    49,    37,    43,    51,    65,    70,    67,   174,   175,
      77,    59,    81,    97,    98,   109,   115,    71,   110,   117,
     118,   182,    94,   119,   120,   142,   137,   143,   144,   145,
     193,   147,   148,   154,   163,   149,   150,   203,   151,   205,
     152,   153,   165,   166,   183,   188,   172,   184,   176,   187,
     217,   180,   189,   196,   221,   177,   185,   190,   226,   198,
     201,   204,   206,   178,   209,   210,   211,   215,   219,   230,
     191,   199,   236,   243,   212,   231,   247,   237,   244,   249,
     258,   259,   264,   257,   282,   266,   283,   194,   300,   301,
     302,   207,   303,   315,   222,   318,   241,   305,   306,   260,
     314,   279,   310,   316,   317,   322,   326,   334,   239,   327,
     299,   333,   336,   346,   284,   344,   345,   338,   169,   304,
      30,   340,   353,   343,   225,   307,   339,     0,   263,     0,
     347,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,   320,   321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   335,
       0,   337,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   348
};

static const yytype_int16 yycheck[] =
{
      27,     8,    10,     4,     4,     4,    10,    11,    79,     4,
       4,     4,    10,    11,    46,    12,    65,    50,    67,    51,
      10,    11,    93,    94,    95,    96,    97,    98,    46,    86,
      29,    48,    32,    26,    35,    68,    93,    55,    95,    96,
       0,     5,    59,    16,   101,   102,    10,    11,    10,    37,
      38,    39,    14,    91,    92,    93,    94,    84,    85,    86,
      87,    24,    25,    90,    91,    92,    93,    71,    72,    73,
      74,    66,    66,    27,    28,    91,    92,    93,    94,     4,
      10,     6,     7,    91,    92,    93,    94,    30,    31,    97,
      98,    99,   100,    91,    92,    93,    94,   104,   105,   106,
     107,    91,    92,    93,    94,    33,    34,    10,    11,    18,
     137,     6,     7,    81,    82,     6,     7,     6,     7,     6,
       7,    63,    83,    84,    20,    19,   153,     3,     3,    21,
      64,    36,    22,    26,    41,    70,    15,    23,   165,   166,
       8,    29,    42,    17,     6,    66,    43,    32,     8,     6,
       6,   178,    35,     6,     6,     3,    89,     3,     3,     3,
     187,    10,    40,    61,    65,     8,     8,   194,     8,   196,
       8,     6,     3,     3,    10,    45,    49,    10,    62,     6,
     207,    53,    45,    87,   211,    66,    57,    10,   215,    47,
      44,    10,    10,    75,     8,    10,     6,     6,     6,     6,
      80,    78,     6,   230,    51,    10,     8,    10,    59,   236,
       6,    10,    10,    54,     6,    52,    10,    86,     3,     3,
       3,    88,    10,     3,    90,     6,    90,    56,    56,    90,
       8,   258,    58,     3,     3,    51,    60,     8,   103,    60,
     267,     6,     8,    10,   103,     8,     6,    69,   161,   274,
      18,    90,    52,    85,   213,   282,   324,    -1,   245,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
       0,    12,   109,   110,    10,    14,     0,    16,   111,    10,
      63,   112,    18,   120,    91,    92,    93,    94,   113,   114,
      24,    25,   115,    19,    20,   121,     3,     3,    10,    11,
     114,     4,    26,    27,    28,   116,    21,    22,   122,   204,
     206,   204,    64,    26,     4,    29,    30,    31,   117,    36,
     123,    41,   135,     8,   104,   105,   106,   107,   205,    29,
       4,    32,    33,    34,   118,    70,   124,    23,   136,   138,
      15,    32,     4,    35,    65,    67,   119,     8,    10,    11,
     125,    42,    10,    11,    71,    72,    73,    74,   137,   139,
     140,   141,   142,   143,    35,     4,    66,    17,     6,   126,
     144,   204,   204,   204,   204,   204,   204,   204,   204,    66,
       8,    37,    38,    39,   127,    43,   145,     6,     6,     6,
       6,   128,   146,    10,    91,    92,    93,    94,    97,    98,
      99,   100,   129,   130,   131,   132,   133,    89,   147,     6,
       7,   134,     3,     3,     3,     3,   204,    10,    40,     8,
       8,     8,     8,     6,    61,   148,   204,    91,    92,    93,
      94,   149,   150,    65,   151,     3,     3,    10,    11,   150,
       4,    66,    49,   152,   204,   204,    62,    66,    75,   153,
      53,   172,   204,    10,    10,    57,   177,     6,    45,    45,
      10,    80,   186,   204,    86,   154,    87,   173,    47,    78,
     187,    44,   203,   204,    10,   204,    10,    88,   179,     8,
      10,     6,    51,   155,   156,     6,   174,   204,   178,     6,
     189,   204,    90,   158,    46,   156,   204,    46,    55,   175,
       6,    10,   188,    81,    82,   190,     6,    10,   159,   103,
     184,    90,   176,   204,    59,   180,   181,     8,   191,   204,
       6,     7,   157,    50,    68,   160,   161,    54,     6,    10,
      90,   182,    48,   181,    10,   192,    52,    86,    93,    95,
      96,   101,   102,   162,   163,   164,   165,   166,   167,   204,
       6,     7,     6,    10,   103,   185,   198,    79,    93,    94,
      95,    96,    97,    98,   193,   194,   195,   196,   197,   204,
       3,     3,     3,    10,   162,    56,    56,   204,     6,     7,
      58,    83,    84,   199,     8,     3,     3,     3,     6,   204,
     204,   204,    51,   168,   169,   171,    60,    60,     5,    10,
      11,   200,   202,     6,     8,   204,     8,   204,    69,   168,
      90,   183,   201,    85,     8,     6,    10,    85,   204,     4,
       6,     7,   170,    52
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
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

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
if (temp < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems = temp;





	if (osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item != NULL)
		osrlerror(NULL, NULL, parserData, "item array was previously allocated");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item = new std::string[temp];
	parserData->kounter = 0; //this will count the number of items in an otherSolutionResult object
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

if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");

osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
}
    break;

  case 178:

    {parserData->itemContent = "";}
    break;

  case 179:

    {parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));}
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


