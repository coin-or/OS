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
     OSRLSTARTEMPTY = 266,
     OSRLATTRIBUTETEXT = 267,
     OSRLEND = 268,
     GENERALSTART = 269,
     GENERALEND = 270,
     SYSTEMSTART = 271,
     SYSTEMEND = 272,
     SERVICESTART = 273,
     SERVICEEND = 274,
     JOBSTART = 275,
     JOBEND = 276,
     SERVICEURISTARTANDEND = 277,
     SERVICEURISTART = 278,
     SERVICEURIEND = 279,
     SERVICENAMESTARTANDEND = 280,
     SERVICENAMESTART = 281,
     SERVICENAMEEND = 282,
     INSTANCENAMESTARTANDEND = 283,
     INSTANCENAMESTART = 284,
     INSTANCENAMEEND = 285,
     JOBIDSTARTANDEND = 286,
     JOBIDSTART = 287,
     JOBIDEND = 288,
     TIMINGINFORMATIONSTART = 289,
     TIMINGINFORMATIONEND = 290,
     TIMESTARTANDEND = 291,
     TIMESTART = 292,
     TIMEEND = 293,
     OPTIMIZATIONSTART = 294,
     OPTIMIZATIONEND = 295,
     SOLUTIONSTART = 296,
     SOLUTIONEND = 297,
     VALUESSTART = 298,
     VALUESEND = 299,
     DUALVALUESSTART = 300,
     DUALVALUESEND = 301,
     VARIABLESSTART = 302,
     VARIABLESEND = 303,
     VARSTART = 304,
     VAREND = 305,
     OBJECTIVESSTART = 306,
     OBJECTIVESEND = 307,
     OBJSTART = 308,
     OBJEND = 309,
     CONSTRAINTSSTART = 310,
     CONSTRAINTSEND = 311,
     CONSTART = 312,
     CONEND = 313,
     STATUSSTART = 314,
     STATUSEND = 315,
     GENERALSTATUSSTART = 316,
     GENERALSTATUSEND = 317,
     MESSAGESTART = 318,
     MESSAGEEND = 319,
     MESSAGESTARTANDEND = 320,
     OTHERSTART = 321,
     OTHEREND = 322,
     NUMBEROFTIMESATT = 323,
     NUMBEROFSOLUTIONSATT = 324,
     NUMBEROFVARIABLESATT = 325,
     NUMBEROFCONSTRAINTSATT = 326,
     NUMBEROFOBJECTIVESATT = 327,
     NUMBEROFOTHERVARIABLERESULTSATT = 328,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 329,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 330,
     NUMBEROFVARATT = 331,
     NUMBEROFOBJATT = 332,
     NUMBEROFCONATT = 333,
     TARGETOBJECTIVEIDXATT = 334,
     IDXATT = 335,
     TYPEATT = 336,
     DESCRIPTIONATT = 337,
     NAMEATT = 338,
     CATEGORYATT = 339,
     UNITATT = 340,
     VALUEATT = 341,
     DUMMY = 342
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
#define OSRLSTARTEMPTY 266
#define OSRLATTRIBUTETEXT 267
#define OSRLEND 268
#define GENERALSTART 269
#define GENERALEND 270
#define SYSTEMSTART 271
#define SYSTEMEND 272
#define SERVICESTART 273
#define SERVICEEND 274
#define JOBSTART 275
#define JOBEND 276
#define SERVICEURISTARTANDEND 277
#define SERVICEURISTART 278
#define SERVICEURIEND 279
#define SERVICENAMESTARTANDEND 280
#define SERVICENAMESTART 281
#define SERVICENAMEEND 282
#define INSTANCENAMESTARTANDEND 283
#define INSTANCENAMESTART 284
#define INSTANCENAMEEND 285
#define JOBIDSTARTANDEND 286
#define JOBIDSTART 287
#define JOBIDEND 288
#define TIMINGINFORMATIONSTART 289
#define TIMINGINFORMATIONEND 290
#define TIMESTARTANDEND 291
#define TIMESTART 292
#define TIMEEND 293
#define OPTIMIZATIONSTART 294
#define OPTIMIZATIONEND 295
#define SOLUTIONSTART 296
#define SOLUTIONEND 297
#define VALUESSTART 298
#define VALUESEND 299
#define DUALVALUESSTART 300
#define DUALVALUESEND 301
#define VARIABLESSTART 302
#define VARIABLESEND 303
#define VARSTART 304
#define VAREND 305
#define OBJECTIVESSTART 306
#define OBJECTIVESEND 307
#define OBJSTART 308
#define OBJEND 309
#define CONSTRAINTSSTART 310
#define CONSTRAINTSEND 311
#define CONSTART 312
#define CONEND 313
#define STATUSSTART 314
#define STATUSEND 315
#define GENERALSTATUSSTART 316
#define GENERALSTATUSEND 317
#define MESSAGESTART 318
#define MESSAGEEND 319
#define MESSAGESTARTANDEND 320
#define OTHERSTART 321
#define OTHEREND 322
#define NUMBEROFTIMESATT 323
#define NUMBEROFSOLUTIONSATT 324
#define NUMBEROFVARIABLESATT 325
#define NUMBEROFCONSTRAINTSATT 326
#define NUMBEROFOBJECTIVESATT 327
#define NUMBEROFOTHERVARIABLERESULTSATT 328
#define NUMBEROFOTHEROBJECTIVERESULTSATT 329
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 330
#define NUMBEROFVARATT 331
#define NUMBEROFOBJATT 332
#define NUMBEROFCONATT 333
#define TARGETOBJECTIVEIDXATT 334
#define IDXATT 335
#define TYPEATT 336
#define DESCRIPTIONATT 337
#define NAMEATT 338
#define CATEGORYATT 339
#define UNITATT 340
#define VALUEATT 341
#define DUMMY 342




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
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNRULES -- Number of states.  */
#define YYNSTATES  294

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,    89,
      91,     2,     2,    90,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    88,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87
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
     141,   147,   148,   151,   153,   155,   157,   159,   163,   167,
     171,   175,   177,   179,   180,   184,   185,   189,   191,   194,
     195,   198,   201,   204,   207,   210,   214,   218,   222,   226,
     227,   230,   240,   241,   246,   251,   255,   257,   260,   264,
     268,   269,   273,   276,   277,   288,   289,   294,   299,   301,
     304,   310,   316,   317,   320,   326,   328,   329,   332,   334,
     336,   338,   340,   345,   349,   353,   357,   358,   361,   367,
     373,   379,   381,   382,   392,   397,   398,   400,   403,   409,
     415,   416,   417,   428,   433,   435,   438,   444,   450,   454,
     455,   457,   458,   460,   462,   465,   468,   470,   472,   474,
     476,   477
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      93,     0,    -1,    94,    95,   104,   105,   106,   122,    13,
      -1,    10,     8,    -1,    10,    12,     8,    -1,    -1,    14,
      96,    99,   100,   101,   102,   103,    15,    -1,    61,    97,
       8,    62,    -1,    61,    97,     9,    -1,    98,    -1,    97,
      98,    -1,    81,     3,   169,    -1,    82,     3,   169,    -1,
      -1,    22,    -1,    23,     4,    24,    -1,    23,    24,    -1,
      -1,    25,    -1,    26,     4,    27,    -1,    26,    27,    -1,
      -1,    28,    -1,    29,     4,    30,    -1,    29,    30,    -1,
      -1,    31,    -1,    32,     4,    33,    -1,    32,    33,    -1,
      -1,    65,    -1,    63,     4,    64,    -1,    63,    64,    -1,
      -1,    16,    17,    -1,    -1,    18,    19,    -1,    -1,    -1,
      20,   107,   108,    21,    -1,    -1,    -1,    34,   109,   110,
     112,    -1,    -1,   111,    68,     7,     5,     7,    -1,     9,
      -1,     8,   113,    35,    -1,    -1,   113,   114,    -1,    36,
      -1,    37,   115,     8,   121,    38,    -1,    -1,   115,   116,
      -1,   117,    -1,   118,    -1,   119,    -1,   120,    -1,    81,
       3,     7,    -1,    84,     3,     7,    -1,    85,     3,     7,
      -1,    82,     3,     7,    -1,     6,    -1,     5,    -1,    -1,
      39,   123,    40,    -1,    -1,   126,   124,   125,    -1,     9,
      -1,     8,   132,    -1,    -1,   126,   127,    -1,   128,   169,
      -1,   129,   169,    -1,   130,   169,    -1,   131,   169,    -1,
      69,   169,     5,    -1,    70,   169,     5,    -1,    71,   169,
       5,    -1,    72,   169,     5,    -1,    -1,   133,   132,    -1,
      41,   134,     8,   135,   138,   139,   156,   160,   168,    -1,
      -1,    79,   169,     5,   169,    -1,    59,   136,     8,    60,
      -1,    59,   136,     9,    -1,   137,    -1,   136,   137,    -1,
      81,     3,   169,    -1,    82,     3,   169,    -1,    -1,    63,
       4,    64,    -1,    63,    64,    -1,    -1,    47,   140,     8,
      43,   141,     8,   142,    44,   144,    48,    -1,    -1,    73,
     169,     5,   169,    -1,    76,   169,     5,   169,    -1,   143,
      -1,   142,   143,    -1,    49,   165,     8,     6,    50,    -1,
      49,   165,     8,     5,    50,    -1,    -1,   144,   145,    -1,
     146,   147,     8,   153,    67,    -1,    66,    -1,    -1,   148,
     147,    -1,   149,    -1,   150,    -1,   151,    -1,   152,    -1,
      76,   169,     5,   169,    -1,    86,     3,   169,    -1,    83,
       3,   169,    -1,    82,     3,   169,    -1,    -1,   154,   153,
      -1,   155,   165,     8,     4,    50,    -1,   155,   165,     8,
       6,    50,    -1,   155,   165,     8,     5,    50,    -1,    49,
      -1,    -1,    51,     8,    43,   157,     8,   158,    44,   166,
      52,    -1,    77,   169,     5,   169,    -1,    -1,   159,    -1,
     158,   159,    -1,    53,   165,     8,     6,    54,    -1,    53,
     165,     8,     5,    54,    -1,    -1,    -1,    55,     8,    45,
     162,   161,     8,   163,    46,   167,    56,    -1,    78,   169,
       5,   169,    -1,   164,    -1,   163,   164,    -1,    57,   165,
       8,     6,    58,    -1,    57,   165,     8,     5,    58,    -1,
      80,     5,   169,    -1,    -1,    87,    -1,    -1,    87,    -1,
      42,    -1,    87,    42,    -1,   171,     7,    -1,    88,    -1,
      89,    -1,    90,    -1,    91,    -1,    -1,   171,   170,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   118,   119,   123,   123,   125,   126,   128,
     129,   131,   132,   135,   136,   137,   138,   141,   142,   143,
     144,   146,   147,   148,   149,   151,   152,   153,   154,   156,
     157,   158,   159,   161,   161,   163,   163,   165,   165,   165,
     167,   168,   168,   170,   170,   174,   174,   176,   176,   180,
     181,   183,   183,   185,   185,   185,   185,   187,   189,   191,
     193,   196,   197,   199,   199,   202,   201,   229,   230,   232,
     233,   235,   236,   237,   238,   242,   244,   246,   248,   252,
     253,   256,   259,   260,   263,   264,   267,   268,   270,   271,
     273,   274,   275,   277,   278,   281,   281,   283,   285,   286,
     288,   292,   299,   300,   302,   308,   315,   318,   320,   320,
     320,   320,   322,   326,   330,   334,   341,   342,   344,   352,
     359,   366,   374,   375,   377,   379,   380,   381,   383,   385,
     388,   390,   389,   401,   403,   404,   406,   409,   416,   422,
     423,   425,   426,   428,   429,   435,   437,   438,   439,   440,
     442,   443
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "INTEGER", "DOUBLE", "QUOTE", "GREATERTHAN", "ENDOFELEMENT", "OSRLSTART",
  "OSRLSTARTEMPTY", "OSRLATTRIBUTETEXT", "OSRLEND", "GENERALSTART",
  "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND",
  "JOBSTART", "JOBEND", "SERVICEURISTARTANDEND", "SERVICEURISTART",
  "SERVICEURIEND", "SERVICENAMESTARTANDEND", "SERVICENAMESTART",
  "SERVICENAMEEND", "INSTANCENAMESTARTANDEND", "INSTANCENAMESTART",
  "INSTANCENAMEEND", "JOBIDSTARTANDEND", "JOBIDSTART", "JOBIDEND",
  "TIMINGINFORMATIONSTART", "TIMINGINFORMATIONEND", "TIMESTARTANDEND",
  "TIMESTART", "TIMEEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
  "SOLUTIONSTART", "SOLUTIONEND", "VALUESSTART", "VALUESEND",
  "DUALVALUESSTART", "DUALVALUESEND", "VARIABLESSTART", "VARIABLESEND",
  "VARSTART", "VAREND", "OBJECTIVESSTART", "OBJECTIVESEND", "OBJSTART",
  "OBJEND", "CONSTRAINTSSTART", "CONSTRAINTSEND", "CONSTART", "CONEND",
  "STATUSSTART", "STATUSEND", "GENERALSTATUSSTART", "GENERALSTATUSEND",
  "MESSAGESTART", "MESSAGEEND", "MESSAGESTARTANDEND", "OTHERSTART",
  "OTHEREND", "NUMBEROFTIMESATT", "NUMBEROFSOLUTIONSATT",
  "NUMBEROFVARIABLESATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFOBJECTIVESATT", "NUMBEROFOTHERVARIABLERESULTSATT",
  "NUMBEROFOTHEROBJECTIVERESULTSATT", "NUMBEROFOTHERCONSTRAINTRESULTSATT",
  "NUMBEROFVARATT", "NUMBEROFOBJATT", "NUMBEROFCONATT",
  "TARGETOBJECTIVEIDXATT", "IDXATT", "TYPEATT", "DESCRIPTIONATT",
  "NAMEATT", "CATEGORYATT", "UNITATT", "VALUEATT", "DUMMY", "' '", "'\\t'",
  "'\\r'", "'\\n'", "$accept", "osrldoc", "osrlstart", "generalElement",
  "generalStatus", "anotherGeneralStatusATT", "generalstatusatt",
  "serviceURI", "serviceName", "instanceName", "jobID", "headerMessage",
  "systemElement", "serviceElement", "jobElement", "@1",
  "timingInformation", "@2", "numberoftimes", "@3", "timingContent",
  "listOfTimes", "time", "timeAttList", "timeAtt", "timeType",
  "timeCategory", "timeUnit", "timeDescription", "timeValue",
  "optimizationElement", "optimizationContent", "@4", "optend",
  "anotherOptATT", "optatt", "optnumsolatt", "optnumvaratt",
  "optnumconatt", "optnumobjatt", "solution", "anothersolution",
  "targetObjectiveIDXATT", "status", "anotherStatusATT", "statusatt",
  "message", "variables", "numberOfOtherVariableResults", "numberOfVarATT",
  "var", "anothervar", "otherVariables", "otherVariableResult",
  "otherVariableStart", "otherVariableATTlist", "othervariableATT",
  "numberOfOtherVarATT", "otherVarValueATT", "otherVarNameATT",
  "otherVarDescriptionATT", "othervarlist", "othervar", "othervarstart",
  "objectives", "numberOfObjATT", "obj", "anotherobj", "constraints", "@5",
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
     335,   336,   337,   338,   339,   340,   341,   342,    32,     9,
      13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    99,    99,    99,    99,   100,   100,   100,
     100,   101,   101,   101,   101,   102,   102,   102,   102,   103,
     103,   103,   103,   104,   104,   105,   105,   106,   107,   106,
     108,   109,   108,   111,   110,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   116,   116,   116,   117,   118,   119,
     120,   121,   121,   122,   122,   124,   123,   125,   125,   126,
     126,   127,   127,   127,   127,   128,   129,   130,   131,   132,
     132,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   138,   139,   139,   140,   140,   141,   142,   142,
     143,   143,   144,   144,   145,   146,   147,   147,   148,   148,
     148,   148,   149,   150,   151,   152,   153,   153,   154,   154,
     154,   155,   156,   156,   157,   158,   158,   158,   159,   159,
     160,   161,   160,   162,   163,   163,   164,   164,   165,   166,
     166,   167,   167,   168,   168,   169,   170,   170,   170,   170,
     171,   171
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     3,     0,     8,     4,     3,     1,
       2,     3,     3,     0,     1,     3,     2,     0,     1,     3,
       2,     0,     1,     3,     2,     0,     1,     3,     2,     0,
       1,     3,     2,     0,     2,     0,     2,     0,     0,     4,
       0,     0,     4,     0,     5,     1,     3,     0,     2,     1,
       5,     0,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     1,     1,     0,     3,     0,     3,     1,     2,     0,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     0,
       2,     9,     0,     4,     4,     3,     1,     2,     3,     3,
       0,     3,     2,     0,    10,     0,     4,     4,     1,     2,
       5,     5,     0,     2,     5,     1,     0,     2,     1,     1,
       1,     1,     4,     3,     3,     3,     0,     2,     5,     5,
       5,     1,     0,     9,     4,     0,     1,     2,     5,     5,
       0,     0,    10,     4,     1,     2,     5,     5,     3,     0,
       1,     0,     1,     1,     2,     2,     1,     1,     1,     1,
       0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    33,     4,
       0,    13,     0,    35,     0,     0,     0,     9,    14,     0,
      17,    34,     0,    37,   150,   150,     0,     8,    10,     0,
      16,    18,     0,    21,    36,    38,    63,    11,     0,    12,
       7,    15,     0,    20,    22,     0,    25,    40,    69,     0,
     145,   146,   147,   148,   149,   151,    19,     0,    24,    26,
       0,    29,    41,     0,     0,    65,     2,    23,     0,    28,
       0,    30,     0,    43,    39,    64,   150,   150,   150,   150,
       0,    70,   150,   150,   150,   150,    27,     0,    32,     6,
       0,     0,     0,     0,     0,     0,    79,    67,    66,    71,
      72,    73,    74,    31,    47,    45,    42,     0,    75,    76,
      77,    78,    82,    68,    79,     0,     0,   150,     0,    80,
      46,    49,    51,    48,     0,     0,     0,     0,    44,   150,
       0,    90,     0,     0,     0,     0,     0,    52,    53,    54,
      55,    56,    83,     0,     0,     0,    86,     0,    93,    62,
      61,     0,     0,     0,     0,     0,   150,   150,     0,    85,
      87,     0,    92,    95,   122,    50,    57,    60,    58,    59,
      88,    89,    84,    91,   150,     0,     0,   130,     0,     0,
       0,     0,     0,   150,     0,     0,     0,   143,     0,    81,
      96,   150,     0,   150,     0,     0,   144,     0,     0,     0,
     125,   150,   131,   150,     0,     0,    98,   150,     0,     0,
     126,     0,     0,    97,     0,     0,   102,    99,   124,     0,
     139,   127,   150,     0,   150,     0,     0,     0,   140,     0,
     133,     0,     0,   134,   138,     0,     0,    94,   105,   103,
     106,     0,     0,   123,     0,   141,   135,   101,   100,   150,
       0,     0,     0,     0,   106,   108,   109,   110,   111,   129,
     128,     0,   142,     0,     0,   150,   150,   150,   116,   107,
       0,     0,   132,   150,   115,   114,   113,   121,     0,   116,
       0,   137,   136,   112,   104,   117,     0,     0,     0,     0,
       0,   118,   120,   119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    11,    16,    17,    20,    33,    46,
      61,    72,    13,    23,    36,    47,    63,    73,    90,    91,
     106,   115,   123,   127,   137,   138,   139,   140,   141,   151,
      49,    64,    80,    98,    65,    81,    82,    83,    84,    85,
     113,   114,   118,   131,   145,   146,   148,   164,   175,   192,
     205,   206,   226,   239,   240,   253,   254,   255,   256,   257,
     258,   278,   279,   280,   177,   194,   209,   210,   182,   212,
     202,   232,   233,   215,   229,   263,   189,    37,    55,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -207
static const yytype_int16 yypact[] =
{
      24,    12,    56,    49,  -207,    67,  -207,    17,    65,  -207,
     -53,    16,    84,    85,    99,   102,     5,  -207,  -207,     8,
      36,  -207,    87,    89,  -207,  -207,    45,  -207,  -207,    86,
    -207,  -207,     4,    38,  -207,  -207,    69,  -207,    -6,  -207,
    -207,  -207,    91,  -207,  -207,     3,    37,    77,  -207,   100,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,    82,  -207,  -207,
       2,   -44,  -207,    93,    75,   -28,  -207,  -207,    83,  -207,
       0,  -207,   104,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
      62,  -207,  -207,  -207,  -207,  -207,  -207,    53,  -207,  -207,
      64,    52,   116,   117,   118,   119,    95,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,   120,  -207,  -207,
    -207,  -207,    46,  -207,    95,    10,   121,  -207,   122,  -207,
    -207,  -207,  -207,  -207,   126,   123,    70,    -5,  -207,  -207,
       9,    71,    88,   132,   134,   135,   136,  -207,  -207,  -207,
    -207,  -207,  -207,   137,   138,     7,  -207,     1,    96,  -207,
    -207,   106,   139,   140,   141,   143,  -207,  -207,    97,  -207,
    -207,    78,  -207,    72,   101,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,   145,   146,   105,   150,   108,
     113,   151,   -32,  -207,    98,   103,   124,  -207,   125,  -207,
    -207,  -207,   153,  -207,   154,   107,  -207,   158,   115,   160,
     128,  -207,  -207,  -207,   109,   -26,  -207,  -207,   109,   -27,
    -207,   165,   163,  -207,   167,   169,  -207,  -207,  -207,   171,
     111,  -207,  -207,   127,  -207,    90,   -39,    92,  -207,   131,
    -207,   109,   -35,  -207,  -207,   142,   144,  -207,  -207,  -207,
     -46,   133,   147,  -207,   178,   129,  -207,  -207,  -207,  -207,
     170,   172,   185,   182,   -46,  -207,  -207,  -207,  -207,  -207,
    -207,    94,  -207,   148,   186,  -207,  -207,  -207,   156,  -207,
     149,   152,  -207,  -207,  -207,  -207,  -207,  -207,   155,   156,
     109,  -207,  -207,  -207,  -207,  -207,   187,    44,   159,   161,
     162,  -207,  -207,  -207
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,  -207,  -207,  -207,  -207,   177,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
     112,  -207,  -207,  -207,  -207,    51,  -207,  -207,  -207,  -207,
    -207,    -3,  -207,  -207,  -207,   -54,  -207,  -207,  -207,  -207,
    -207,   -76,  -207,  -207,  -207,  -207,  -207,    -1,  -207,  -207,
    -207,  -207,   -19,  -206,  -207,  -207,  -207,   -25,  -207,  -207
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      39,    50,   219,   132,    87,   161,    68,    57,    42,   237,
     187,   245,    29,    26,    27,   158,   159,   220,   216,    70,
       4,    71,   231,   204,     5,   244,   208,   238,    14,    15,
     249,    43,    30,    58,     1,    69,   250,   251,    18,    19,
     252,    76,    77,    78,    79,   120,   121,   122,   288,   289,
     290,    92,    93,    94,    95,   188,     6,    99,   100,   101,
     102,    31,    32,     7,    88,   162,    44,    45,    59,    60,
      96,    97,   104,   105,   286,     9,   133,   134,    10,   135,
     136,    12,    51,    52,    53,    54,    14,    15,   143,   144,
     143,   144,   125,   149,   150,   235,   236,   241,   242,   270,
     271,    21,    24,    22,   142,    25,    34,    40,    48,    35,
      41,    62,    67,    66,    74,    75,    86,   103,    56,    89,
     107,   108,   109,   110,   111,   117,   124,   116,   129,   130,
     126,   170,   171,   128,   147,   152,   112,   153,   154,   155,
     156,   157,   173,   163,   165,   174,   166,   167,   168,   178,
     169,   184,   176,   179,   180,   183,   185,   172,   190,   186,
     181,   198,   200,   203,   204,   207,   197,   196,   199,   195,
     222,   223,   224,   265,   191,   266,   211,   225,   213,   227,
     193,   208,   218,   243,   231,   201,   261,   259,   267,   214,
     268,   273,   247,    28,   248,   287,   160,   230,   228,   234,
     269,   260,   217,   285,   272,   277,     0,   281,   221,   291,
     282,   292,   293,   246,     0,     0,   262,     0,     0,     0,
       0,     0,   284,     0,   264,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     274,   275,   276,     0,     0,     0,     0,     0,   283
};

static const yytype_int16 yycheck[] =
{
      25,     7,   208,     8,     4,     4,     4,     4,     4,    48,
      42,    46,     4,     8,     9,     8,     9,    44,    44,    63,
       8,    65,    57,    49,    12,   231,    53,    66,    81,    82,
      76,    27,    24,    30,    10,    33,    82,    83,    22,    23,
      86,    69,    70,    71,    72,    35,    36,    37,     4,     5,
       6,    76,    77,    78,    79,    87,     0,    82,    83,    84,
      85,    25,    26,    14,    64,    64,    28,    29,    31,    32,
       8,     9,     8,     9,   280,     8,    81,    82,    61,    84,
      85,    16,    88,    89,    90,    91,    81,    82,    81,    82,
      81,    82,   117,     5,     6,     5,     6,     5,     6,     5,
       6,    17,     3,    18,   129,     3,    19,    62,    39,    20,
      24,    34,    30,    13,    21,    40,    33,    64,    27,    15,
      68,     5,     5,     5,     5,    79,     5,     7,     5,    59,
       8,   156,   157,     7,    63,     3,    41,     3,     3,     3,
       3,     3,    64,    47,    38,    73,     7,     7,     7,   174,
       7,    43,    51,     8,     8,     5,    43,    60,   183,     8,
      55,     8,     8,     5,    49,     5,   191,    42,   193,    45,
       5,     8,     5,     3,    76,     3,   201,     8,   203,     8,
      77,    53,   207,    52,    57,    78,     8,    54,     3,    80,
       8,     5,    50,    16,    50,     8,   145,   222,    87,   224,
     254,    54,   205,   279,    56,    49,    -1,    58,   209,    50,
      58,    50,    50,   232,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    67,    -1,   249,    -1,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     265,   266,   267,    -1,    -1,    -1,    -1,    -1,   273
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    93,    94,     8,    12,     0,    14,    95,     8,
      61,    96,    16,   104,    81,    82,    97,    98,    22,    23,
      99,    17,    18,   105,     3,     3,     8,     9,    98,     4,
      24,    25,    26,   100,    19,    20,   106,   169,   171,   169,
      62,    24,     4,    27,    28,    29,   101,   107,    39,   122,
       7,    88,    89,    90,    91,   170,    27,     4,    30,    31,
      32,   102,    34,   108,   123,   126,    13,    30,     4,    33,
      63,    65,   103,   109,    21,    40,    69,    70,    71,    72,
     124,   127,   128,   129,   130,   131,    33,     4,    64,    15,
     110,   111,   169,   169,   169,   169,     8,     9,   125,   169,
     169,   169,   169,    64,     8,     9,   112,    68,     5,     5,
       5,     5,    41,   132,   133,   113,     7,    79,   134,   132,
      35,    36,    37,   114,     5,   169,     8,   115,     7,     5,
      59,   135,     8,    81,    82,    84,    85,   116,   117,   118,
     119,   120,   169,    81,    82,   136,   137,    63,   138,     5,
       6,   121,     3,     3,     3,     3,     3,     3,     8,     9,
     137,     4,    64,    47,   139,    38,     7,     7,     7,     7,
     169,   169,    60,    64,    73,   140,    51,   156,   169,     8,
       8,    55,   160,     5,    43,    43,     8,    42,    87,   168,
     169,    76,   141,    77,   157,    45,    42,   169,     8,   169,
       8,    78,   162,     5,    49,   142,   143,     5,    53,   158,
     159,   169,   161,   169,    80,   165,    44,   143,   169,   165,
      44,   159,     5,     8,     5,     8,   144,     8,    87,   166,
     169,    57,   163,   164,   169,     5,     6,    48,    66,   145,
     146,     5,     6,    52,   165,    46,   164,    50,    50,    76,
      82,    83,    86,   147,   148,   149,   150,   151,   152,    54,
      54,     8,    87,   167,   169,     3,     3,     3,     8,   147,
       5,     6,    56,     5,   169,   169,   169,    49,   153,   154,
     155,    58,    58,   169,    67,   153,   165,     8,     4,     5,
       6,    50,    50,    50
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

    {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element");;}
    break;

  case 8:

    {if(parserData->generalStatusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for generalStatus element"); parserData->generalStatusTypePresent = false;;}
    break;

  case 11:

    { osresult->setGeneralStatusType((yyvsp[(2) - (3)].sval));  free((yyvsp[(2) - (3)].sval));  ; parserData->generalStatusTypePresent = true;;}
    break;

  case 12:

    {  osresult->setGeneralStatusDescription((yyvsp[(2) - (3)].sval));    free((yyvsp[(2) - (3)].sval));;}
    break;

  case 15:

    {osresult->setServiceURI( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 19:

    {osresult->setServiceName( (yyvsp[(2) - (3)].sval));  free((yyvsp[(2) - (3)].sval));   parserData->errorText = NULL;;}
    break;

  case 23:

    {osresult->setInstanceName( (yyvsp[(2) - (3)].sval)) ;  free((yyvsp[(2) - (3)].sval));   parserData->errorText = NULL;;}
    break;

  case 27:

    {osresult->setJobID( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 31:

    {osresult->setGeneralMessage( (yyvsp[(2) - (3)].sval));  free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 34:

    {printf("processed systemElement");;}
    break;

  case 36:

    {printf("processed serviceElement");;}
    break;

  case 38:

    {printf("processed JOBSTART");;}
    break;

  case 41:

    {printf("processed TIMINGINFORMATIONSTART");;}
    break;

  case 43:

    {printf("processing numberOfTimes");;}
    break;

  case 44:

    {
;}
    break;

  case 48:

    {
;}
    break;

  case 61:

    {/*osresult->setTime( $2)*/; ;}
    break;

  case 62:

    {/*osresult->setTime( $2)*/; ;}
    break;

  case 65:

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
;}
    break;

  case 75:

    { parserData->numberOfSolutions = (yyvsp[(3) - (3)].ival); osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 76:

    {parserData->numberOfVariables = (yyvsp[(3) - (3)].ival); osresult->setVariableNumber((yyvsp[(3) - (3)].ival)); ;}
    break;

  case 77:

    {parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 78:

    {parserData->numberOfObjectives = (yyvsp[(3) - (3)].ival); osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 81:

    {parserData->solutionIdx++;;}
    break;

  case 83:

    {if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, NULL, "target objective index must be negative");
*(parserData->objectiveIdx + parserData->solutionIdx) = (yyvsp[(3) - (4)].ival);;}
    break;

  case 84:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element");  osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);;}
    break;

  case 85:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element"); parserData->statusTypePresent = false; osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);;}
    break;

  case 88:

    {parserData->statusType = (yyvsp[(2) - (3)].sval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].sval));;}
    break;

  case 89:

    {parserData->statusDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 100:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(parserData->primalSolution[parserData->solutionIdx] + parserData->kounter ) = (yyvsp[(4) - (5)].dval);
	;}
    break;

  case 101:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(parserData->primalSolution[parserData->solutionIdx] + parserData->kounter) = (yyvsp[(4) - (5)].ival);
;}
    break;

  case 104:

    {	parserData->otherVarVec.push_back( parserData->otherVarStruct); 
		parserData->numberOfOtherVariableResults++; 
		parserData->otherNamePresent = false;  
	;}
    break;

  case 105:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		parserData->otherVarStruct->otherVarText = new std::string[parserData->numberOfVariables];
	;}
    break;

  case 106:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, NULL, "other element requires name attribute"); 
	;}
    break;

  case 112:

    {parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 113:

    {   parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 114:

    { parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 115:

    {   parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 118:

    { 
std::ostringstream outStr;
outStr << (yyvsp[(4) - (5)].sval);
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
free((yyvsp[(4) - (5)].sval)); parserData->errorText = NULL;
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
;}
    break;

  case 119:

    { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << (yyvsp[(4) - (5)].dval);
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
;}
    break;

  case 120:

    { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << (yyvsp[(4) - (5)].ival);
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
;}
    break;

  case 121:

    {	if(parserData->otherVarStruct->numberOfVar <= 0) 
			osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	;}
    break;

  case 128:

    { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = (yyvsp[(4) - (5)].dval);
;}
    break;

  case 129:

    { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = (yyvsp[(4) - (5)].ival);;}
    break;

  case 131:

    {
			if( parserData->numberOfConstraints > 0){
				parserData->dualSolution = new double*[ parserData->numberOfSolutions];
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->dualSolution[ i] = new double[ parserData->numberOfConstraints];
				}
			}
;}
    break;

  case 136:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(parserData->dualSolution[parserData->solutionIdx] + parserData->kounter) = (yyvsp[(4) - (5)].dval);;}
    break;

  case 137:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(parserData->dualSolution[parserData->solutionIdx] + parserData->kounter) = (yyvsp[(4) - (5)].ival);;}
    break;

  case 138:

    {parserData->kounter = (yyvsp[(2) - (3)].ival);;}
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


