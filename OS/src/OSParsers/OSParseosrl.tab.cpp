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
     ITEMSTARTANDEND = 341,
     ITEMEMPTY = 342,
     NUMBEROFVARATT = 343,
     NUMBEROFOBJATT = 344,
     NUMBEROFCONATT = 345,
     TARGETOBJECTIVEIDXATT = 346,
     IDXATT = 347,
     TYPEATT = 348,
     EMPTYTYPEATT = 349,
     DESCRIPTIONATT = 350,
     EMPTYDESCRIPTIONATT = 351,
     NAMEATT = 352,
     EMPTYNAMEATT = 353,
     CATEGORYATT = 354,
     EMPTYCATEGORYATT = 355,
     UNITATT = 356,
     EMPTYUNITATT = 357,
     VALUEATT = 358,
     EMPTYVALUEATT = 359,
     DUMMY = 360
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
#define ITEMSTARTANDEND 341
#define ITEMEMPTY 342
#define NUMBEROFVARATT 343
#define NUMBEROFOBJATT 344
#define NUMBEROFCONATT 345
#define TARGETOBJECTIVEIDXATT 346
#define IDXATT 347
#define TYPEATT 348
#define EMPTYTYPEATT 349
#define DESCRIPTIONATT 350
#define EMPTYDESCRIPTIONATT 351
#define NAMEATT 352
#define EMPTYNAMEATT 353
#define CATEGORYATT 354
#define EMPTYCATEGORYATT 355
#define UNITATT 356
#define EMPTYUNITATT 357
#define VALUEATT 358
#define EMPTYVALUEATT 359
#define DUMMY 360




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
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  110
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  189
/* YYNRULES -- Number of states.  */
#define YYNSTATES  352

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   360

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   107,
     109,     2,     2,   108,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   106,     2,     2,     2,     2,     2,     2,     2,
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
     105
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
     522,   526,   530,   532,   536,   538,   539,   542,   544,   546,
     547,   548,   554,   556,   559,   561,   563,   565,   567,   568
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     111,     0,    -1,   112,   113,   122,   123,   124,   137,    15,
      -1,    12,    10,    -1,    12,    14,    10,    -1,    -1,    16,
     114,   117,   118,   119,   120,   121,    17,    -1,    63,   115,
      10,    64,    -1,    63,   115,    11,    -1,   116,    -1,   115,
     116,    -1,    93,     3,   205,    -1,    94,    -1,    95,     3,
     205,    -1,    96,    -1,    -1,    24,    -1,    25,     4,    26,
      -1,    25,    26,    -1,    -1,    27,    -1,    28,     4,    29,
      -1,    28,    29,    -1,    -1,    30,    -1,    31,     4,    32,
      -1,    31,    32,    -1,    -1,    33,    -1,    34,     4,    35,
      -1,    34,    35,    -1,    -1,    67,    -1,    65,     4,    66,
      -1,    65,    66,    -1,    -1,    18,    19,    -1,    -1,    20,
      21,    -1,    -1,    22,   125,    23,    -1,    -1,    36,   126,
     127,    -1,    70,     8,     6,     8,    -1,    11,    -1,    10,
     128,    37,    -1,    -1,   128,   129,    -1,    38,    -1,    39,
     130,    10,   136,    40,    -1,    -1,   130,   131,    -1,   132,
      -1,   133,    -1,   134,    -1,   135,    -1,    93,     3,     8,
      -1,    94,    -1,    99,     3,     8,    -1,   100,    -1,   101,
       3,     8,    -1,   102,    -1,    95,     3,     8,    -1,    96,
      -1,     7,    -1,     6,    -1,    -1,    41,   138,    42,    -1,
     140,   139,    -1,    11,    -1,    10,   146,    -1,    -1,   140,
     141,    -1,   142,   205,    -1,   143,   205,    -1,   144,   205,
      -1,   145,   205,    -1,    71,   205,     6,    -1,    72,   205,
       6,    -1,    73,   205,     6,    -1,    74,   205,     6,    -1,
      -1,   146,   147,    -1,    -1,    43,   148,   149,    10,   150,
     153,   154,   174,   179,   188,   204,    -1,    -1,    91,   205,
       6,   205,    -1,    61,   151,    10,    62,    -1,    61,   151,
      11,    -1,   152,    -1,   151,   152,    -1,    93,     3,   205,
      -1,    94,    -1,    95,     3,   205,    -1,    96,    -1,    -1,
      65,     4,    66,    -1,    65,    66,    -1,    -1,    49,   155,
      10,    45,   156,    10,   157,    46,   161,    50,    -1,    -1,
      75,   205,     6,   205,    -1,    88,   205,     6,   205,    -1,
     158,    -1,   157,   158,    -1,    51,   160,    10,   159,    52,
      -1,     6,    -1,     7,    -1,    92,     6,   205,    -1,    -1,
     161,   162,    -1,   163,   164,    10,   170,    69,    -1,    68,
      -1,    -1,   165,   164,    -1,   166,    -1,   167,    -1,   168,
      -1,   169,    -1,    88,   205,     6,   205,    -1,   104,    -1,
     103,     3,   205,    -1,    98,    -1,    97,     3,   205,    -1,
      95,     3,   205,    -1,    -1,   171,   170,    -1,   173,   185,
      10,   172,    52,    -1,     4,    -1,     6,    -1,     7,    -1,
      51,    -1,    -1,    53,    10,    45,   175,    10,   176,    46,
     186,    54,    -1,    89,   205,     6,   205,    -1,    -1,   176,
     177,    -1,    55,   178,    10,     7,    56,    -1,    55,   178,
      10,     6,    56,    -1,    92,     6,   205,    -1,    -1,    -1,
      57,    10,    47,   181,   180,    10,   182,    48,   187,    58,
      -1,    90,   205,     6,   205,    -1,   183,    -1,   182,   183,
      -1,    59,   184,    10,     7,    60,    -1,    59,   184,    10,
       6,    60,    -1,    92,     6,   205,    -1,    92,     6,   205,
      -1,    -1,   105,    -1,    -1,   105,    -1,    -1,    80,   189,
      10,   191,    81,    -1,    -1,    78,     8,     6,   190,     8,
      -1,    -1,   191,   192,    -1,    82,   193,    10,   200,    83,
      -1,    -1,    -1,   193,   194,   195,    -1,   196,    -1,   197,
      -1,   198,    -1,   199,    -1,    79,     8,     6,     8,    -1,
      98,    -1,    97,     3,   205,    -1,    99,     3,     8,    -1,
     100,    -1,    95,     3,     8,    -1,    96,    -1,    -1,   200,
     201,    -1,    86,    -1,    87,    -1,    -1,    -1,    84,   202,
       5,   203,    85,    -1,    44,    -1,   207,     8,    -1,   106,
      -1,   107,    -1,   108,    -1,   109,    -1,    -1,   207,   206,
      -1
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
     602,   610,   613,   616,   619,   621,   622,   624,   632,   641,
     648,   640,   651,   659,   661,   662,   663,   664,   666,   667
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
  "ITEMEND", "ITEMSTARTANDEND", "ITEMEMPTY", "NUMBEROFVARATT",
  "NUMBEROFOBJATT", "NUMBEROFCONATT", "TARGETOBJECTIVEIDXATT", "IDXATT",
  "TYPEATT", "EMPTYTYPEATT", "DESCRIPTIONATT", "EMPTYDESCRIPTIONATT",
  "NAMEATT", "EMPTYNAMEATT", "CATEGORYATT", "EMPTYCATEGORYATT", "UNITATT",
  "EMPTYUNITATT", "VALUEATT", "EMPTYVALUEATT", "DUMMY", "' '", "'\\t'",
  "'\\r'", "'\\n'", "$accept", "osrldoc", "osrlstart", "generalElement",
  "generalStatus", "anotherGeneralStatusATT", "generalstatusatt",
  "serviceURI", "serviceName", "instanceName", "jobID", "headerMessage",
  "systemElement", "serviceElement", "jobElement", "timingInformation",
  "numberoftimes", "timingContent", "listOfTimes", "time", "timeAttList",
  "timeAtt", "timeType", "timeCategory", "timeUnit", "timeDescription",
  "timeValue", "optimizationElement", "optimizationContent", "optend",
  "anotherOptATT", "optatt", "optnumsolatt", "optnumvaratt",
  "optnumconatt", "optnumobjatt", "solution", "anothersolution", "@1",
  "targetObjectiveIDXATT", "status", "anotherStatusATT", "statusatt",
  "message", "variables", "numberOfOtherVariableResults", "numberOfVarATT",
  "var", "anothervar", "DoubleOrInt", "aVARIDXATT", "otherVariables",
  "otherVariableResult", "otherVariableStart", "otherVariableATTlist",
  "othervariableATT", "numberOfOtherVarATT", "otherVarValueATT",
  "otherVarNameATT", "otherVarDescriptionATT", "othervarlist", "othervar",
  "ElementValue", "othervarstart", "objectives", "numberOfObjATT", "obj",
  "anotherobj", "anOBJIDXATT", "constraints", "@2", "numberOfConATT",
  "con", "anothercon", "aCONIDXATT", "anIDXATT", "otherObjectives",
  "otherConstraints", "otherSolutionResults",
  "numberOfOtherSolutionResults", "@3", "otherSolutionResultList",
  "anotherSolutionResult", "anotherSolutionResultAttList", "@4",
  "anotherSolutionResultAtt", "numberOfItems",
  "anotherSolutionResultNameATT", "anotherSolutionResultCategoryATT",
  "anotherSolutionDescriptionATT", "itemList", "anotherSolutionItem", "@5",
  "@6", "solutionEnd", "quote", "xmlWhiteSpaceChar", "xmlWhiteSpace", 0
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
     355,   356,   357,   358,   359,   360,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   110,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   116,   116,   117,   117,   117,   117,   118,
     118,   118,   118,   119,   119,   119,   119,   120,   120,   120,
     120,   121,   121,   121,   121,   122,   122,   123,   123,   124,
     124,   125,   125,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   131,   131,   132,   132,   133,   133,
     134,   134,   135,   135,   136,   136,   137,   137,   138,   139,
     139,   140,   140,   141,   141,   141,   141,   142,   143,   144,
     145,   146,   146,   148,   147,   149,   149,   150,   150,   151,
     151,   152,   152,   152,   152,   153,   153,   153,   154,   154,
     155,   155,   156,   157,   157,   158,   159,   159,   160,   161,
     161,   162,   163,   164,   164,   165,   165,   165,   165,   166,
     167,   167,   168,   168,   169,   170,   170,   171,   172,   172,
     172,   173,   174,   174,   175,   176,   176,   177,   177,   178,
     179,   180,   179,   181,   182,   182,   183,   183,   184,   185,
     186,   186,   187,   187,   188,   188,   190,   189,   191,   191,
     192,   193,   194,   193,   195,   195,   195,   195,   196,   197,
     197,   198,   198,   199,   199,   200,   200,   201,   201,   202,
     203,   201,   204,   205,   206,   206,   206,   206,   207,   207
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
       3,     3,     1,     3,     1,     0,     2,     1,     1,     0,
       0,     5,     1,     2,     1,     1,     1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    35,     4,
       0,    15,     0,    37,     0,    12,     0,    14,     0,     9,
      16,     0,    19,    36,     0,    39,   188,   188,     0,     8,
      10,     0,    18,    20,     0,    23,    38,    41,    66,    11,
       0,    13,     7,    17,     0,    22,    24,     0,    27,     0,
       0,    71,     0,   183,   184,   185,   186,   187,   189,    21,
       0,    26,    28,     0,    31,     0,     0,    40,     0,     0,
       2,    25,     0,    30,     0,    32,     0,     0,    46,    44,
      42,    67,    81,    69,   188,   188,   188,   188,    68,    72,
     188,   188,   188,   188,    29,     0,    34,     6,     0,     0,
      70,     0,     0,     0,     0,    73,    74,    75,    76,    33,
      43,    45,    48,    50,    47,    83,    82,    77,    78,    79,
      80,     0,    85,     0,     0,    57,     0,    63,     0,    59,
       0,    61,    51,    52,    53,    54,    55,   188,     0,    65,
      64,     0,     0,     0,     0,     0,     0,     0,    49,    56,
      62,    58,    60,   188,     0,    95,    86,     0,    92,     0,
      94,     0,    89,     0,    98,   188,   188,     0,    88,    90,
       0,    97,   100,   132,    91,    93,    87,    96,   188,     0,
       0,   140,     0,     0,     0,     0,   154,   188,     0,     0,
       0,     0,     0,   101,   188,     0,   188,     0,     0,     0,
       0,   182,    84,     0,     0,     0,   135,   188,   141,     0,
     158,   188,     0,     0,   103,   188,     0,     0,     0,   156,
       0,   102,     0,     0,   109,   104,   134,   150,     0,   136,
     188,     0,     0,   155,   161,   159,   188,     0,     0,   151,
       0,     0,     0,   143,     0,     0,   144,   157,   162,   108,
     106,   107,     0,    99,   112,   110,   113,   133,   188,     0,
       0,     0,   152,   145,   175,     0,   105,   188,     0,     0,
     122,     0,   120,     0,   113,   115,   116,   117,   118,   139,
       0,     0,   188,     0,   153,     0,     0,     0,     0,   174,
       0,   169,     0,   172,   163,   164,   165,   166,   167,     0,
     188,   188,   188,   125,   114,   138,   137,   148,     0,     0,
     142,   160,   179,   177,   178,   176,     0,     0,   188,     0,
     188,   124,   123,   121,   131,     0,   125,     0,   147,   146,
       0,     0,   173,   170,   171,   119,   111,   126,     0,     0,
     180,   168,   188,     0,     0,   149,   128,   129,   130,     0,
     181,   127
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
     325,   326,   349,   327,   181,   197,   216,   229,   242,   186,
     218,   208,   245,   246,   261,   339,   240,   285,   192,   200,
     232,   220,   235,   248,   265,   294,   295,   296,   297,   298,
     286,   315,   330,   344,   202,    39,    58,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int16 yypact[] =
{
      24,    29,    22,    26,   -74,    35,   -74,    15,    64,   -74,
     -43,    37,    65,    89,   122,   -74,   124,   -74,     2,   -74,
     -74,     7,    62,   -74,   107,   108,   -74,   -74,    67,   -74,
     -74,   106,   -74,   -74,     1,    77,   -74,    93,    92,   -74,
      -7,   -74,   -74,   -74,   105,   -74,   -74,     0,    78,    66,
     112,   -74,   125,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     110,   -74,   -74,    -1,    16,   129,   103,   -74,    99,    -4,
     -74,   -74,   111,   -74,     5,   -74,   126,   138,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,    79,   -74,   -74,   139,    17,
     114,   142,   143,   144,   146,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,    -8,    63,   109,   150,   -74,   152,   -74,   153,   -74,
     155,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   149,   -74,
     -74,   121,   154,   156,   157,   158,   162,   102,   -74,   -74,
     -74,   -74,   -74,   -74,   -20,   116,   -74,   167,   -74,   168,
     -74,    10,   -74,     6,   123,   -74,   -74,   120,   -74,   -74,
     119,   -74,    98,   130,   -74,   -74,   -74,   -74,   -74,   164,
     165,   132,   170,   133,   134,   176,    97,   -74,   104,   101,
     140,   118,   147,   -74,   -74,   183,   -74,   184,   127,   187,
     188,   -74,   -74,   191,   148,   194,   -74,   -74,   -74,   195,
     -74,   -74,   128,    -2,   -74,   -74,   -32,   196,   197,   -74,
      36,   -74,   198,   200,   -74,   -74,   -74,   100,   131,   -74,
     -74,   159,   203,   -74,   -74,   -74,   -74,   113,   -33,   -74,
     160,   202,   205,   -74,   135,   -11,   -74,   -74,   206,   -74,
     -74,   -74,   161,   -74,   -74,   -74,   -57,   -74,   -74,   115,
     213,   211,   136,   -74,   -74,   -71,   -74,   -74,   209,   219,
     -74,   221,   -74,   215,   -57,   -74,   -74,   -74,   -74,   -74,
     172,   173,   -74,   117,   -74,   174,   -68,   218,   227,   -74,
     230,   -74,   231,   -74,   -74,   -74,   -74,   -74,   -74,   229,
     -74,   -74,   -74,   185,   -74,   -74,   -74,   -74,   177,   178,
     -74,   -74,   -74,   -74,   -74,   -74,   233,   234,   -74,   235,
     -74,   -74,   -74,   -74,   -74,   137,   185,   166,   -74,   -74,
     239,   237,   -74,   -74,   -74,   -74,   -74,   -74,   240,   238,
     -74,   -74,   -74,    73,   169,   -74,   -74,   -74,   -74,   199,
     -74,   -74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   -74,   -74,   -74,   232,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,    86,   -74,   -74,   -74,   -74,   -74,    39,   -74,
     -74,   -74,   -74,   -74,   -25,   -74,   -74,   -74,   -74,   -74,
     -73,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,    11,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -27,   -74,   -74
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      41,    53,   123,    72,    60,    44,    82,    83,   287,    95,
     170,    31,    28,    29,   227,   311,   312,   253,   313,   314,
     167,   168,     6,   228,   288,   289,   290,   291,   292,   293,
      45,   267,    61,    32,    73,   254,     1,   262,   268,     4,
     269,   270,     7,     5,   224,     9,   271,   272,   244,   212,
      14,    15,    16,    17,   111,   112,   113,   101,   102,   103,
     104,    20,    21,   105,   106,   107,   108,    84,    85,    86,
      87,    96,   171,   157,   158,   159,   160,   346,    10,   347,
     348,    74,    12,    75,    23,   124,   125,   126,   127,    33,
      34,   128,   129,   130,   131,    14,    15,    16,    17,    54,
      55,    56,    57,   157,   158,   159,   160,    46,    47,    24,
     146,    62,    63,    78,    79,   139,   140,   233,   234,   250,
     251,   280,   281,   308,   309,    26,   156,    27,    36,    49,
      37,    42,    43,    51,    59,    67,    65,    77,   174,   175,
      70,    81,    71,    97,    98,   109,    94,   110,   117,   118,
     119,   182,   120,   142,   137,   143,   144,   115,   145,   147,
     193,   148,   149,   154,   150,   151,   152,   203,   153,   205,
     165,   166,   172,   178,   183,   184,   187,   191,   188,   189,
     217,   163,   176,   180,   221,   177,   190,   198,   226,   185,
     196,   201,   194,   204,   206,   209,   199,   211,   210,   212,
     215,   219,   230,   243,   236,   239,   336,   231,   258,   249,
     237,   247,   300,   266,   257,   259,   264,   207,   244,   282,
     222,   283,   301,   241,   302,   303,   316,   260,   305,   306,
     317,   279,   310,   318,   319,   320,   324,   328,   329,   331,
     299,   284,   332,   334,   340,   341,   342,   169,   343,   304,
      30,   351,   225,   337,   350,   307,   263,     0,   338,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   321,   322,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   333,     0,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   345
};

static const yytype_int16 yycheck[] =
{
      27,     8,    10,     4,     4,     4,    10,    11,    79,     4,
       4,     4,    10,    11,    46,    83,    84,    50,    86,    87,
      10,    11,     0,    55,    95,    96,    97,    98,    99,   100,
      29,    88,    32,    26,    35,    68,    12,    48,    95,    10,
      97,    98,    16,    14,    46,    10,   103,   104,    59,    51,
      93,    94,    95,    96,    37,    38,    39,    84,    85,    86,
      87,    24,    25,    90,    91,    92,    93,    71,    72,    73,
      74,    66,    66,    93,    94,    95,    96,     4,    63,     6,
       7,    65,    18,    67,    19,    93,    94,    95,    96,    27,
      28,    99,   100,   101,   102,    93,    94,    95,    96,   106,
     107,   108,   109,    93,    94,    95,    96,    30,    31,    20,
     137,    33,    34,    10,    11,     6,     7,    81,    82,     6,
       7,     6,     7,     6,     7,     3,   153,     3,    21,    36,
      22,    64,    26,    41,    29,    23,    70,     8,   165,   166,
      15,    42,    32,    17,     6,    66,    35,     8,     6,     6,
       6,   178,     6,     3,    91,     3,     3,    43,     3,    10,
     187,    40,     8,    61,     8,     8,     8,   194,     6,   196,
       3,     3,    49,    75,    10,    10,     6,    80,    45,    45,
     207,    65,    62,    53,   211,    66,    10,    47,   215,    57,
      89,    44,    88,    10,    10,     8,    78,     6,    10,    51,
       6,     6,     6,   230,     6,   105,    69,    10,     6,   236,
      10,     8,     3,    52,    54,    10,    10,    90,    59,     6,
      92,    10,     3,    92,     3,    10,     8,    92,    56,    56,
       3,   258,    58,     3,     3,     6,    51,    60,    60,     6,
     267,   105,     8,     8,     5,     8,     6,   161,    10,   274,
      18,    52,   213,   326,    85,   282,   245,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   300,   301,   302,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   318,    -1,   320,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   342
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,   111,   112,    10,    14,     0,    16,   113,    10,
      63,   114,    18,   122,    93,    94,    95,    96,   115,   116,
      24,    25,   117,    19,    20,   123,     3,     3,    10,    11,
     116,     4,    26,    27,    28,   118,    21,    22,   124,   205,
     207,   205,    64,    26,     4,    29,    30,    31,   119,    36,
     125,    41,   137,     8,   106,   107,   108,   109,   206,    29,
       4,    32,    33,    34,   120,    70,   126,    23,   138,   140,
      15,    32,     4,    35,    65,    67,   121,     8,    10,    11,
     127,    42,    10,    11,    71,    72,    73,    74,   139,   141,
     142,   143,   144,   145,    35,     4,    66,    17,     6,   128,
     146,   205,   205,   205,   205,   205,   205,   205,   205,    66,
       8,    37,    38,    39,   129,    43,   147,     6,     6,     6,
       6,   130,   148,    10,    93,    94,    95,    96,    99,   100,
     101,   102,   131,   132,   133,   134,   135,    91,   149,     6,
       7,   136,     3,     3,     3,     3,   205,    10,    40,     8,
       8,     8,     8,     6,    61,   150,   205,    93,    94,    95,
      96,   151,   152,    65,   153,     3,     3,    10,    11,   152,
       4,    66,    49,   154,   205,   205,    62,    66,    75,   155,
      53,   174,   205,    10,    10,    57,   179,     6,    45,    45,
      10,    80,   188,   205,    88,   156,    89,   175,    47,    78,
     189,    44,   204,   205,    10,   205,    10,    90,   181,     8,
      10,     6,    51,   157,   158,     6,   176,   205,   180,     6,
     191,   205,    92,   160,    46,   158,   205,    46,    55,   177,
       6,    10,   190,    81,    82,   192,     6,    10,   161,   105,
     186,    92,   178,   205,    59,   182,   183,     8,   193,   205,
       6,     7,   159,    50,    68,   162,   163,    54,     6,    10,
      92,   184,    48,   183,    10,   194,    52,    88,    95,    97,
      98,   103,   104,   164,   165,   166,   167,   168,   169,   205,
       6,     7,     6,    10,   105,   187,   200,    79,    95,    96,
      97,    98,    99,   100,   195,   196,   197,   198,   199,   205,
       3,     3,     3,    10,   164,    56,    56,   205,     6,     7,
      58,    83,    84,    86,    87,   201,     8,     3,     3,     3,
       6,   205,   205,   205,    51,   170,   171,   173,    60,    60,
     202,     6,     8,   205,     8,   205,    69,   170,    92,   185,
       5,     8,     6,    10,   203,   205,     4,     6,     7,   172,
      85,    52
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
parserData->itemContent = "";
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
}
    break;

  case 178:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
parserData->itemContent = "";
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
}
    break;

  case 179:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");

osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
}
    break;

  case 180:

    {parserData->itemContent = (yyvsp[(3) - (3)].sval); free((yyvsp[(3) - (3)].sval));}
    break;

  case 182:

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


