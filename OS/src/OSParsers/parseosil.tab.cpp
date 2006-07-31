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
#define yyparse osilparse
#define yylex   osillex
#define yyerror osilerror
#define yylval  osillval
#define yychar  osilchar
#define yydebug osildebug
#define yynerrs osilnerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     QUOTE = 258,
     ATTRIBUTETEXT = 259,
     INTEGER = 260,
     DOUBLE = 261,
     ELEMENTTEXT = 262,
     OSILSTART = 263,
     OSILEND = 264,
     NAMESTART = 265,
     NAMEEND = 266,
     DESCRIPTIONSTART = 267,
     DESCRIPTIONEND = 268,
     SOURCESTART = 269,
     SOURCEEND = 270,
     INSTANCEHEADER = 271,
     INSTANCEHEADERSTART = 272,
     INSTANCEHEADEREND = 273,
     INSTANCEDATASTART = 274,
     INSTANCEDATAEND = 275,
     VALUEATT = 276,
     NUMBEROFNONLINEAREXPRESSIONS = 277,
     IDXONEATT = 278,
     IDXTWOATT = 279,
     COEFATT = 280,
     IDATT = 281,
     TIMESSTART = 282,
     TIMESEND = 283,
     NUMBERSTART = 284,
     NUMBEREND = 285,
     NUMBEROFQTERMSATT = 286,
     IDXATT = 287,
     TYPEATT = 288,
     QTERMSTART = 289,
     QTERMEND = 290,
     QUADRATICCOEFFICIENTSSTART = 291,
     QUADRATICCOEFFICIENTSEND = 292,
     NONLINEAREXPRESSIONSSTART = 293,
     NONLINEAREXPRESSIONSEND = 294,
     NLSTART = 295,
     NLEND = 296,
     POWERSTART = 297,
     POWEREND = 298,
     PLUSSTART = 299,
     PLUSEND = 300,
     MINUSSTART = 301,
     MINUSEND = 302,
     DIVIDESTART = 303,
     DIVIDEEND = 304,
     LNSTART = 305,
     LNEND = 306,
     SUMSTART = 307,
     SUMEND = 308,
     PRODUCTSTART = 309,
     PRODUCTEND = 310,
     ENDOFELEMENT = 311,
     EXPSTART = 312,
     EXPEND = 313,
     NEGATESTART = 314,
     NEGATEEND = 315,
     IFSTART = 316,
     IFEND = 317,
     GREATERTHAN = 318,
     OSILATTRIBUTETEXT = 319,
     NAMESTARTANDEND = 320,
     SOURCESTARTANDEND = 321,
     DESCRIPTIONSTARTANDEND = 322,
     VARIABLESTART = 323,
     VARIABLEEND = 324,
     ABSSTART = 325,
     ABSEND = 326,
     MAXSTART = 327,
     MAXEND = 328
   };
#endif
/* Tokens.  */
#define QUOTE 258
#define ATTRIBUTETEXT 259
#define INTEGER 260
#define DOUBLE 261
#define ELEMENTTEXT 262
#define OSILSTART 263
#define OSILEND 264
#define NAMESTART 265
#define NAMEEND 266
#define DESCRIPTIONSTART 267
#define DESCRIPTIONEND 268
#define SOURCESTART 269
#define SOURCEEND 270
#define INSTANCEHEADER 271
#define INSTANCEHEADERSTART 272
#define INSTANCEHEADEREND 273
#define INSTANCEDATASTART 274
#define INSTANCEDATAEND 275
#define VALUEATT 276
#define NUMBEROFNONLINEAREXPRESSIONS 277
#define IDXONEATT 278
#define IDXTWOATT 279
#define COEFATT 280
#define IDATT 281
#define TIMESSTART 282
#define TIMESEND 283
#define NUMBERSTART 284
#define NUMBEREND 285
#define NUMBEROFQTERMSATT 286
#define IDXATT 287
#define TYPEATT 288
#define QTERMSTART 289
#define QTERMEND 290
#define QUADRATICCOEFFICIENTSSTART 291
#define QUADRATICCOEFFICIENTSEND 292
#define NONLINEAREXPRESSIONSSTART 293
#define NONLINEAREXPRESSIONSEND 294
#define NLSTART 295
#define NLEND 296
#define POWERSTART 297
#define POWEREND 298
#define PLUSSTART 299
#define PLUSEND 300
#define MINUSSTART 301
#define MINUSEND 302
#define DIVIDESTART 303
#define DIVIDEEND 304
#define LNSTART 305
#define LNEND 306
#define SUMSTART 307
#define SUMEND 308
#define PRODUCTSTART 309
#define PRODUCTEND 310
#define ENDOFELEMENT 311
#define EXPSTART 312
#define EXPEND 313
#define NEGATESTART 314
#define NEGATEEND 315
#define IFSTART 316
#define IFEND 317
#define GREATERTHAN 318
#define OSILATTRIBUTETEXT 319
#define NAMESTARTANDEND 320
#define SOURCESTARTANDEND 321
#define DESCRIPTIONSTARTANDEND 322
#define VARIABLESTART 323
#define VARIABLEEND 324
#define ABSSTART 325
#define ABSEND 326
#define MAXSTART 327
#define MAXEND 328




/* Copy the first part of user declarations.  */



 
#include <iostream>
#include <sstream>     
#include "lexyaccparser.h"
#include "externalvars.h"
#include "OSInstance.h" 
#include "OSnLNode.h"
#include "ErrorClass.h"
#include "OSParameters.h"
#include "osilparservariables.h"
#include "Base64.h"



//
//
// the global variables for parsing
clock_t start, finish;
double duration;
double atofmod(char *ch);
int atoimod(char *ch);
// we distinguish a newline from other whitespace
// since we need to know when we hit a new line
bool isnewline(char c);
bool isnull(char c);
char *ch = NULL;
bool parseVariables();
bool parseObjectives();
bool parseObjCoef( int objcount);
bool parseConstraints();
bool parseLinearConstraintCoefficients();
bool parseStart();
bool parseRowIdx();
bool parseColIdx();
bool parseValue();
char *parseBase64(int *dataSize );




#define GAIL printf("GAIL ANN HONDA\n")

#define	ISWHITESPACE( char_) ((char_) == ' ' || \
                     (char_) == '\t' ||  (char_) == '\r')

#define	ISDIGIT(_c) ((_c) >= '0' && (_c) <= '9')

#define GETATTRIBUTETEXT  	\
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ; \
	if( *ch != '=') {osiltext = &ch[0]; osilerror("found an attribute not defined"); return false;}  \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;	\
	if(*ch != '\"'  && *ch != '\"') {osiltext = &ch[0]; osilerror("missing quote on attribute"); return false;} \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ; \
	attText = &*ch; \
	for( ; *ch != '\"' &&  *ch != '\''; ch++); \
	*ch = '\0'; 
	
#define ECHOCHECK \
	GAIL; \
	printf("%c", ch[-2]); \
	printf("%c", ch[-1]); \
	printf("%c", ch[0]); \
	printf("%c", ch[1]); \
	printf("%c", ch[2]); \
	printf("%c", ch[3]); \
	printf("%c", ch[4]); \
	printf("%c", ch[5]); \
	printf("%c \n", ch[6]); \
	GAIL;



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
#define YYLAST   231

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNRULES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,    75,
      77,     2,     2,    76,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    74,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    11,    15,    21,    23,    24,    26,
      30,    33,    34,    36,    40,    43,    44,    46,    50,    53,
      54,    60,    61,    66,    71,    72,    75,    76,    81,    83,
      86,    87,    90,    93,    96,    99,   102,   105,   108,   110,
     113,   116,   119,   122,   125,   126,   131,   136,   137,   138,
     146,   150,   152,   154,   156,   158,   160,   162,   164,   166,
     168,   170,   172,   174,   176,   178,   180,   181,   187,   188,
     194,   195,   201,   202,   207,   208,   214,   215,   221,   222,
     227,   229,   232,   233,   238,   240,   243,   244,   249,   251,
     254,   255,   260,   261,   266,   267,   272,   273,   280,   281,
     286,   287,   292,   294,   296,   298,   299,   304,   305,   308,
     311,   314,   317,   320,   323,   326,   329,   330,   333,   336,
     339,   342,   345,   348,   350,   352,   354,   356,   357,   360
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      79,     0,    -1,    80,    81,    85,     9,    -1,     8,    63,
      -1,     8,    64,    63,    -1,    17,    82,    83,    84,    18,
      -1,    16,    -1,    -1,    65,    -1,    10,     7,    11,    -1,
      10,    11,    -1,    -1,    66,    -1,    14,     7,    15,    -1,
      14,    15,    -1,    -1,    67,    -1,    12,     7,    13,    -1,
      12,    13,    -1,    -1,    19,    86,    87,   100,    20,    -1,
      -1,    36,    88,    89,    37,    -1,    31,     5,   153,    63,
      -1,    -1,    89,    90,    -1,    -1,    91,    34,    93,    92,
      -1,    56,    -1,    63,    35,    -1,    -1,    93,    94,    -1,
      95,   153,    -1,    96,   153,    -1,    97,   153,    -1,    98,
     153,    -1,    99,   153,    -1,    26,     4,    -1,    26,    -1,
      23,     5,    -1,    24,     5,    -1,    25,     6,    -1,    25,
       5,    -1,    32,     5,    -1,    -1,    38,   101,   102,    39,
      -1,    22,     5,   153,    63,    -1,    -1,    -1,   102,    40,
     104,    63,   105,   103,    41,    -1,    32,     5,   153,    -1,
     135,    -1,   137,    -1,   106,    -1,   108,    -1,   118,    -1,
     110,    -1,   112,    -1,   114,    -1,   116,    -1,   124,    -1,
     127,    -1,   129,    -1,   133,    -1,   131,    -1,   121,    -1,
      -1,    27,   107,   105,   105,    28,    -1,    -1,    44,   109,
     105,   105,    45,    -1,    -1,    46,   111,   105,   105,    47,
      -1,    -1,    59,   113,   105,    60,    -1,    -1,    48,   115,
     105,   105,    49,    -1,    -1,    42,   117,   105,   105,    43,
      -1,    -1,    52,   119,   120,    53,    -1,   105,    -1,   120,
     105,    -1,    -1,    72,   122,   123,    73,    -1,   105,    -1,
     123,   105,    -1,    -1,    54,   125,   126,    55,    -1,   105,
      -1,   126,   105,    -1,    -1,    50,   128,   105,    51,    -1,
      -1,    57,   130,   105,    58,    -1,    -1,    70,   132,   105,
      71,    -1,    -1,    61,   134,   105,   105,   105,    62,    -1,
      -1,    29,   136,   142,   139,    -1,    -1,    68,   138,   147,
     140,    -1,    56,    -1,    30,    -1,    56,    -1,    -1,    63,
     105,   141,    69,    -1,    -1,   142,   143,    -1,   144,   153,
      -1,   146,   153,    -1,   145,   153,    -1,    33,     4,    -1,
      26,     4,    -1,    21,     6,    -1,    21,     5,    -1,    -1,
     147,   148,    -1,   149,   153,    -1,   150,   153,    -1,    25,
       6,    -1,    25,     5,    -1,    32,     5,    -1,    74,    -1,
      75,    -1,    76,    -1,    77,    -1,    -1,   152,   151,    -1,
     152,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   139,   140,   144,   145,   148,   149,   150,
     151,   153,   154,   155,   156,   158,   159,   160,   161,   163,
     163,   176,   177,   181,   186,   187,   189,   189,   200,   201,
     204,   205,   209,   212,   215,   218,   221,   227,   229,   230,
     232,   234,   236,   238,   244,   245,   249,   254,   256,   255,
     265,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   296,   296,   301,   301,
     306,   306,   311,   311,   316,   316,   321,   321,   326,   326,
     336,   337,   340,   340,   350,   351,   354,   354,   364,   365,
     368,   368,   374,   374,   379,   379,   385,   385,   390,   390,
     395,   395,   400,   401,   403,   404,   404,   414,   415,   417,
     419,   421,   425,   429,   435,   438,   442,   443,   445,   447,
     450,   453,   457,   462,   463,   464,   465,   467,   468,   470
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "QUOTE", "ATTRIBUTETEXT", "INTEGER",
  "DOUBLE", "ELEMENTTEXT", "OSILSTART", "OSILEND", "NAMESTART", "NAMEEND",
  "DESCRIPTIONSTART", "DESCRIPTIONEND", "SOURCESTART", "SOURCEEND",
  "INSTANCEHEADER", "INSTANCEHEADERSTART", "INSTANCEHEADEREND",
  "INSTANCEDATASTART", "INSTANCEDATAEND", "VALUEATT",
  "NUMBEROFNONLINEAREXPRESSIONS", "IDXONEATT", "IDXTWOATT", "COEFATT",
  "IDATT", "TIMESSTART", "TIMESEND", "NUMBERSTART", "NUMBEREND",
  "NUMBEROFQTERMSATT", "IDXATT", "TYPEATT", "QTERMSTART", "QTERMEND",
  "QUADRATICCOEFFICIENTSSTART", "QUADRATICCOEFFICIENTSEND",
  "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND", "NLSTART",
  "NLEND", "POWERSTART", "POWEREND", "PLUSSTART", "PLUSEND", "MINUSSTART",
  "MINUSEND", "DIVIDESTART", "DIVIDEEND", "LNSTART", "LNEND", "SUMSTART",
  "SUMEND", "PRODUCTSTART", "PRODUCTEND", "ENDOFELEMENT", "EXPSTART",
  "EXPEND", "NEGATESTART", "NEGATEEND", "IFSTART", "IFEND", "GREATERTHAN",
  "OSILATTRIBUTETEXT", "NAMESTARTANDEND", "SOURCESTARTANDEND",
  "DESCRIPTIONSTARTANDEND", "VARIABLESTART", "VARIABLEEND", "ABSSTART",
  "ABSEND", "MAXSTART", "MAXEND", "' '", "'\\t'", "'\\r'", "'\\n'",
  "$accept", "osildoc", "osilstart", "instanceHeader", "name", "source",
  "description", "instanceData", "@1", "quadraticcoefficients",
  "quadnumberatt", "qTermlist", "qterm", "@2", "qtermend",
  "anotherqTermATT", "qtermatt", "qtermidatt", "qtermidxOneatt",
  "qtermidxTwoatt", "qtermcoefatt", "qtermidxatt", "nonlinearExpressions",
  "nlnumberatt", "nlnodes", "@3", "nlIdxATT", "nlnode", "times", "@4",
  "plus", "@5", "minus", "@6", "negate", "@7", "divide", "@8", "power",
  "@9", "sum", "@10", "anothersumnlnode", "max", "@11", "anothermaxnlnode",
  "product", "@12", "anotherproductnlnode", "ln", "@13", "exp", "@14",
  "abs", "@15", "if", "@16", "number", "@17", "variable", "@18",
  "numberend", "variableend", "@19", "anotherNumberATT", "numberATT",
  "numbertypeATT", "numberidATT", "numbervalueATT", "anotherVariableATT",
  "variableATT", "variablecoefATT", "variableidxATT", "xmlWhiteSpaceChar",
  "xmlWhiteSpace", "quote", 0
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
     325,   326,   327,   328,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    80,    81,    81,    82,    82,    82,
      82,    83,    83,    83,    83,    84,    84,    84,    84,    86,
      85,    87,    87,    88,    89,    89,    91,    90,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    95,    95,    96,
      97,    98,    98,    99,   100,   100,   101,   102,   103,   102,
     104,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   107,   106,   109,   108,
     111,   110,   113,   112,   115,   114,   117,   116,   119,   118,
     120,   120,   122,   121,   123,   123,   125,   124,   126,   126,
     128,   127,   130,   129,   132,   131,   134,   133,   136,   135,
     138,   137,   139,   139,   140,   141,   140,   142,   142,   143,
     143,   143,   144,   145,   146,   146,   147,   147,   148,   148,
     149,   149,   150,   151,   151,   151,   151,   152,   152,   153
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     3,     5,     1,     0,     1,     3,
       2,     0,     1,     3,     2,     0,     1,     3,     2,     0,
       5,     0,     4,     4,     0,     2,     0,     4,     1,     2,
       0,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     0,     4,     4,     0,     0,     7,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     0,     5,
       0,     5,     0,     4,     0,     5,     0,     5,     0,     4,
       1,     2,     0,     4,     1,     2,     0,     4,     1,     2,
       0,     4,     0,     4,     0,     4,     0,     6,     0,     4,
       0,     4,     1,     1,     1,     0,     4,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     0,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     0,     1,     6,     7,     0,
       4,     0,     8,    11,    19,     0,     0,    10,     0,    12,
      15,    21,     2,     9,     0,    14,     0,    16,     0,     0,
      44,    13,     0,    18,     5,     0,    24,     0,     0,    17,
     127,    26,     0,    47,    20,     0,     0,    22,    25,     0,
     127,     0,   129,   123,   124,   125,   126,   128,    23,    30,
       0,    45,     0,     0,    46,     0,     0,     0,     0,     0,
      38,     0,    28,     0,    27,    31,   127,   127,   127,   127,
     127,   127,     0,    39,    40,    42,    41,    37,    43,    29,
      32,    33,    34,    35,    36,    50,    66,    98,    76,    68,
      70,    74,    90,    78,    86,    92,    72,    96,   100,    94,
      82,    48,    53,    54,    56,    57,    58,    59,    55,    65,
      60,    61,    62,    64,    63,    51,    52,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,    88,     0,     0,     0,     0,     0,     0,    84,
       0,    49,     0,     0,     0,   103,     0,   102,    99,   108,
     127,   127,   127,     0,     0,     0,     0,    91,    79,    81,
      87,    89,    93,    73,     0,     0,     0,   104,     0,   101,
     117,   127,   127,    95,    83,    85,    67,   115,   114,   113,
     112,   109,   111,   110,    77,    69,    71,    75,     0,   121,
     120,   122,   105,   118,   119,    97,     0,   106
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    13,    20,    28,    15,    21,    30,
      36,    41,    48,    49,    74,    63,    75,    76,    77,    78,
      79,    80,    38,    43,    51,   142,    66,   111,   112,   127,
     113,   130,   114,   131,   115,   137,   116,   132,   117,   129,
     118,   134,   151,   119,   141,   160,   120,   135,   153,   121,
     133,   122,   136,   123,   140,   124,   138,   125,   128,   126,
     139,   168,   189,   216,   144,   169,   170,   171,   172,   157,
     190,   191,   192,    57,    45,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -96
static const yytype_int16 yypact[] =
{
       3,   -55,    22,     2,   -96,   -30,   -96,   -96,    -8,    25,
     -96,    -1,   -96,   -11,   -96,    50,    38,   -96,    -3,   -96,
      -7,    30,   -96,   -96,    53,   -96,     0,   -96,    52,    47,
      41,   -96,    67,   -96,   -96,    76,   -96,    61,    65,   -96,
     -96,    68,    82,   -96,   -96,    -2,    35,   -96,   -96,    72,
     -96,   -19,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
      44,   -96,    77,    -9,   -96,    99,    48,   109,   110,    19,
     112,   113,   -96,    84,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   159,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   159,   -96,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   -96,
     159,   159,    83,   159,    70,   159,   159,   159,   159,    66,
     -96,   101,   -96,   130,    69,    63,   159,    39,    54,   -96,
      40,   -96,   103,    57,   125,   -96,   128,   -96,   -96,   -96,
     -96,   -96,   -96,    90,    89,    88,    87,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   159,    71,   132,   -96,   159,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,    78,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,    75,   -96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -95,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,    52,    11,    18,    24,    26,    16,    32,     4,     5,
      17,     1,    25,    33,    67,    68,    69,    70,     7,     8,
      61,    62,     6,    71,    85,    86,    90,    91,    92,    93,
      94,    95,   143,    10,   145,   146,   147,   148,   149,   150,
     152,   154,   155,   156,    14,   158,   159,    72,   162,    23,
     173,   174,   175,   176,    73,    19,   179,    12,   181,    22,
      27,   184,   197,   198,   185,   195,    29,    96,    31,    97,
      34,   186,    53,    54,    55,    56,   209,   210,    35,    37,
      39,    40,    98,    42,    99,    44,   100,    50,   101,   208,
     102,   163,   103,   212,   104,   187,   164,   105,    58,   106,
     165,   107,   188,   166,    81,    47,    59,    64,   108,    65,
     109,    82,   110,   194,    83,    84,    87,   177,    88,    89,
     201,   202,   203,   183,   161,   193,   167,   182,    96,   199,
      97,   196,   200,   204,   205,   206,   207,   211,     0,     0,
     215,   213,   214,    98,   217,    99,     0,   100,     0,   101,
       0,   102,     0,   103,   178,   104,     0,    96,   105,    97,
     106,     0,   107,     0,     0,     0,     0,     0,     0,   108,
       0,   109,    98,   110,    99,     0,   100,     0,   101,     0,
     102,     0,   103,     0,   104,   180,    96,   105,    97,   106,
       0,   107,     0,     0,     0,     0,     0,     0,   108,     0,
     109,    98,   110,    99,     0,   100,     0,   101,     0,   102,
       0,   103,     0,   104,     0,     0,   105,     0,   106,     0,
     107,     0,     0,     0,     0,     0,     0,   108,     0,   109,
       0,   110
};

static const yytype_int16 yycheck[] =
{
      50,     3,    10,    14,     7,    12,     7,     7,    63,    64,
      11,     8,    15,    13,    23,    24,    25,    26,    16,    17,
      39,    40,     0,    32,     5,     6,    76,    77,    78,    79,
      80,    81,   127,    63,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,    19,   140,   141,    56,   143,    11,
     145,   146,   147,   148,    63,    66,   151,    65,   153,     9,
      67,   156,     5,     6,    25,   160,    36,    27,    15,    29,
      18,    32,    74,    75,    76,    77,     5,     6,    31,    38,
      13,     5,    42,    22,    44,    20,    46,     5,    48,   184,
      50,    21,    52,   188,    54,    56,    26,    57,    63,    59,
      30,    61,    63,    33,     5,    37,    34,    63,    68,    32,
      70,    63,    72,    73,     5,     5,     4,    51,     5,    35,
     170,   171,   172,    60,    41,    71,    56,    58,    27,     4,
      29,    28,     4,    43,    45,    47,    49,     5,    -1,    -1,
      62,   191,   192,    42,    69,    44,    -1,    46,    -1,    48,
      -1,    50,    -1,    52,    53,    54,    -1,    27,    57,    29,
      59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    42,    72,    44,    -1,    46,    -1,    48,    -1,
      50,    -1,    52,    -1,    54,    55,    27,    57,    29,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    42,    72,    44,    -1,    46,    -1,    48,    -1,    50,
      -1,    52,    -1,    54,    -1,    -1,    57,    -1,    59,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    72
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    79,    80,    63,    64,     0,    16,    17,    81,
      63,    10,    65,    82,    19,    85,     7,    11,    14,    66,
      83,    86,     9,    11,     7,    15,    12,    67,    84,    36,
      87,    15,     7,    13,    18,    31,    88,    38,   100,    13,
       5,    89,    22,   101,    20,   152,   153,    37,    90,    91,
       5,   102,     3,    74,    75,    76,    77,   151,    63,    34,
     153,    39,    40,    93,    63,    32,   104,    23,    24,    25,
      26,    32,    56,    63,    92,    94,    95,    96,    97,    98,
      99,     5,    63,     5,     5,     5,     6,     4,     5,    35,
     153,   153,   153,   153,   153,   153,    27,    29,    42,    44,
      46,    48,    50,    52,    54,    57,    59,    61,    68,    70,
      72,   105,   106,   108,   110,   112,   114,   116,   118,   121,
     124,   127,   129,   131,   133,   135,   137,   107,   136,   117,
     109,   111,   115,   128,   119,   125,   130,   113,   134,   138,
     132,   122,   103,   105,   142,   105,   105,   105,   105,   105,
     105,   120,   105,   126,   105,   105,   105,   147,   105,   105,
     123,    41,   105,    21,    26,    30,    33,    56,   139,   143,
     144,   145,   146,   105,   105,   105,   105,    51,    53,   105,
      55,   105,    58,    60,   105,    25,    32,    56,    63,   140,
     148,   149,   150,    71,    73,   105,    28,     5,     6,     4,
       4,   153,   153,   153,    43,    45,    47,    49,   105,     5,
       6,     5,   105,   153,   153,    62,   141,    69
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
        case 9:

    {osinstance->instanceHeader->name = (yyvsp[(2) - (3)].sval);}
    break;

  case 13:

    {osinstance->instanceHeader->source = (yyvsp[(2) - (3)].sval); }
    break;

  case 17:

    {osinstance->instanceHeader->description = (yyvsp[(2) - (3)].sval);}
    break;

  case 19:

    {

	//osiltext = &ch[ 0];
	if( parseVariables() != true)  YYABORT;
	if( parseObjectives() != true) YYABORT ; 
	if( parseConstraints() != true) YYABORT; 
	if( parseLinearConstraintCoefficients() != true) YYABORT;	
	osil_scan_buffer(ch , strlen(  ch) + 2);

}
    break;

  case 22:

    {if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > qtermcount ) osilerror("actual number of qterms less than numberOfQuadraticTerms");}
    break;

  case 23:

    {
osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms = (yyvsp[(2) - (4)].ival);  
if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > 0 ) osinstance->instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[ (yyvsp[(2) - (4)].ival) ];
for(int i = 0; i < (yyvsp[(2) - (4)].ival); i++) osinstance->instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();}
    break;

  case 26:

    {if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms <= qtermcount ) osilerror("too many QuadraticTerms");}
    break;

  case 27:

    {qtermcount++; 
if(!qtermidxattON)  osilerror("the qTerm attribute idx is required"); 
if(!qtermidxOneattON)  osilerror("the qTerm attribute idxOne is required"); 
if(!qtermidxTwoattON)  osilerror("the qTerm attribute idxTwo is required"); 
qtermidattON = false; 
qtermidxattON = false; 
qtermidxOneattON = false; 
qtermidxTwoattON = false;
qtermcoefattON = false;}
    break;

  case 32:

    { if(qtermidattON) osilerror("too many qTerm id attributes"); 
			qtermidattON = true;  }
    break;

  case 33:

    { if(qtermidxOneattON) osilerror("too many qTerm id attributes"); 
			qtermidxOneattON = true;  }
    break;

  case 34:

    { if(qtermidxTwoattON) osilerror("too many qTerm id attributes"); 
			qtermidxTwoattON = true;  }
    break;

  case 35:

    { if(qtermcoefattON) osilerror("too many qTerm id attributes"); 
			qtermcoefattON = true;  }
    break;

  case 36:

    { if(qtermidxattON) osilerror("too many qTerm id attributes"); 
			qtermidxattON = true;  }
    break;

  case 37:

    {  
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->id = (yyvsp[(2) - (2)].sval);}
    break;

  case 39:

    {  
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->idxOne = (yyvsp[(2) - (2)].ival);}
    break;

  case 40:

    { 
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->idxTwo = (yyvsp[(2) - (2)].ival);}
    break;

  case 41:

    {
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->coef = (yyvsp[(2) - (2)].dval);}
    break;

  case 42:

    { 
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->coef = (yyvsp[(2) - (2)].ival);}
    break;

  case 43:

    {  
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->idx = (yyvsp[(2) - (2)].ival);}
    break;

  case 45:

    {if(nlnodecount <  tmpnlcount)  osilerror("actual number of nl terms less than number attribute"); }
    break;

  case 46:

    {tmpnlcount = (yyvsp[(2) - (4)].ival);
osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = (yyvsp[(2) - (4)].ival);  
if(osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ (yyvsp[(2) - (4)].ival) ];
}
    break;

  case 48:

    {
	// IMPORTANT -- HERE IS WHERE WE DEFINE THE EXPRESSION TREE
	osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->osExpressionTree->m_treeRoot = 
	//osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->osExpressionTree->createExpressionTreeFromPrefix( nlNodeVec);
	//createExpressionTreeFromPrefix( nlNodeVec);
	nlNodeVec[ 0]->createExpressionTreeFromPrefix( nlNodeVec);
	nlnodecount++;
}
    break;

  case 50:

    {
osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount] = new Nl();
osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->idx = (yyvsp[(2) - (3)].ival);
osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->osExpressionTree = new OSExpressionTree();
cout << "NLNODE INDEX =   " << osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->idx << endl;
if(nlnodecount > tmpnlcount) osilerror("actual number of nl terms greater than number attribute");
// clear the vectors of pointers
nlNodeVec.clear();
sumVec.clear();
maxVec.clear();
productVec.clear();
}
    break;

  case 66:

    {
	nlNodePoint = new OSnLNodeTimes();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 68:

    {
	nlNodePoint = new OSnLNodePlus();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 70:

    {
	nlNodePoint = new OSnLNodeMinus();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 72:

    {
	nlNodePoint = new OSnLNodeNegate();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 74:

    { 
	nlNodePoint = new OSnLNodeDivide();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 76:

    {
	nlNodePoint = new OSnLNodePower();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 78:

    {
	nlNodePoint = new OSnLNodeSum();
	nlNodeVec.push_back( nlNodePoint);
	sumVec.push_back( nlNodePoint);
}
    break;

  case 79:

    {
	sumVec.back()->m_mChildren = new OSnLNode*[ sumVec.back()->inumberOfChildren];
	sumVec.pop_back();
}
    break;

  case 80:

    {	sumVec.back()->inumberOfChildren++; }
    break;

  case 81:

    {	sumVec.back()->inumberOfChildren++; }
    break;

  case 82:

    {
	nlNodePoint = new OSnLNodeMax();
	nlNodeVec.push_back( nlNodePoint);
	maxVec.push_back( nlNodePoint);
}
    break;

  case 83:

    {
	maxVec.back()->m_mChildren = new OSnLNode*[ maxVec.back()->inumberOfChildren];
	maxVec.pop_back();
}
    break;

  case 84:

    {	maxVec.back()->inumberOfChildren++; }
    break;

  case 85:

    {	maxVec.back()->inumberOfChildren++; }
    break;

  case 86:

    {
	nlNodePoint = new OSnLNodeProduct();
	nlNodeVec.push_back( nlNodePoint);
	productVec.push_back( nlNodePoint);
}
    break;

  case 87:

    {
	productVec.back()->m_mChildren = new OSnLNode*[ productVec.back()->inumberOfChildren];
	productVec.pop_back();
}
    break;

  case 88:

    {	productVec.back()->inumberOfChildren++; }
    break;

  case 89:

    {	productVec.back()->inumberOfChildren++; }
    break;

  case 90:

    {
	nlNodePoint = new OSnLNodeLn();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 92:

    {
	nlNodePoint = new OSnLNodeExp();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 94:

    {
	nlNodePoint = new OSnLNodeAbs();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 96:

    {
	nlNodePoint = new OSnLNodeIf();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 98:

    {
	nlNodeNumberPoint = new OSnLNodeNumber();
	nlNodeVec.push_back( nlNodeNumberPoint);
}
    break;

  case 99:

    {numbervalueattON = false; numbertypeattON = false; numberidattON = false;}
    break;

  case 100:

    {
	nlNodeVariablePoint = new OSnLNodeVariable();
	nlNodeVec.push_back( nlNodeVariablePoint);
}
    break;

  case 101:

    {variablecoefattON = false; variableidxattON = false;}
    break;

  case 105:

    {
	//sumVec.back()->inumberOfChildren = 1;
	//sumVec.back()->m_mChildren = new OSnLNode*[ 1];
	// kipp -- fix the above doesnt seem right
	nlNodeVariablePoint->inumberOfChildren = 1;
	nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
}
    break;

  case 109:

    {if(numbertypeattON) osilerror("too many number type attributes"); 
			numbertypeattON = true; }
    break;

  case 110:

    {if(numbervalueattON) osilerror("too many number value attributes"); 
			numbervalueattON = true; }
    break;

  case 111:

    {if(numberidattON) osilerror("too many number id attributes"); 
			numberidattON = true; }
    break;

  case 112:

    {
	nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 113:

    {
	nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
}
    break;

  case 114:

    {
	nlNodeNumberPoint->value = (yyvsp[(2) - (2)].dval);
}
    break;

  case 115:

    {
	nlNodeNumberPoint->value = (yyvsp[(2) - (2)].ival);
}
    break;

  case 118:

    {if(variablecoefattON) osilerror("too many variable coef attributes"); 
			variablecoefattON = true; }
    break;

  case 119:

    {if(variableidxattON) osilerror("too many variable idx attributes"); 
			variableidxattON = true; }
    break;

  case 120:

    {
	nlNodeVariablePoint->coef = (yyvsp[(2) - (2)].dval);
}
    break;

  case 121:

    {
	nlNodeVariablePoint->coef = (yyvsp[(2) - (2)].ival);		
}
    break;

  case 122:

    {
	nlNodeVariablePoint->idx = (yyvsp[(2) - (2)].ival);
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








// user defined functions


void osilerror(char* errormsg) {
		ostringstream outStr;
		sparseError = errormsg;
		sparseError = "PARSER ERROR:  Input is either not valid or well formed: "  + sparseError;
		outStr << sparseError << endl;
		outStr << "Here are the last 5 and next 15 characters currently being pointed to in the input string: ";
		for(int i = -5; i < 20; i++){ 
			if(osiltext[ i] != '\0' ) outStr << osiltext[ i];
			if(osiltext[ i] == '\0' ) outStr << "GNUNULL " << endl;
			
		}
		outStr << endl;
		outStr << "See line number: " << osillineno << endl;  
		sparseError = outStr.str();
		//cout << sparseError << endl;
	}//end osilerror() 

OSInstance* yygetOSInstance( std::string osil) throw (ErrorClass)
try {
		void yyinitialize();
		yyinitialize();
		osil = osil+"00";
		ch = &osil[ 0];
		int size = strlen( ch);
		ch[ size - 1] = 0;
		ch[ size - 2] = 0;
		//current_buf is an external variable;
		osil_scan_buffer( ch, size );
		//osil_scan_string( osil.c_str());
		osinstance = NULL;
		osinstance = new OSInstance();
		// get the first occurance of variables
		int kj = osil.find("variables");
		ch = &osil[ kj ];
		if( osilparse() != 0) throw ErrorClass( sparseError);
		//osil_delete_buffer( current_buf);
		return osinstance;
}//end yygetOSInstance
		catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}

void osilClearMemory(){
	delete osinstance;
	osinstance = NULL;
} // end osilClearMemory

void yyinitialize(){
	osillineno = 1; 
	qtermcount = 0;
	nlnodecount = 0;
	// qterm attribute boolean variables
	qtermidxOneattON = false;
	qtermidxTwoattON = false;
	qtermidxattON = false;
	qtermidattON = false;
	qtermcoefattON = false;
	// number attribute boolean variables 
	numbertypeattON = false;
	numbervalueattON = false;
	// variable attribute boolean variables
	variableidxattON = false;
	variablecoefattON = false;
	// kipp -- change later when nonlinear added to OSInstnace
	tmpnlcount = 0;
	sparseError = "";
} // end yyInitialize()


bool isnewline(char c){
	if(c != '\n') return false;
	osillineno++;
	return true;
}//end isnewline()

bool isnull(char c){
	if(c != '\0') return false;
	return true;
}//end isnewline()

bool parseVariables(){
	start = clock(); 
	char *c_numberOfVariables = "numberOfVariables";
	char *startVariables = "variables";
	char *endVariables = "</variables";
	char *startVar = "<var";
	char *endVar = "</var";
	// the attributes
	char *attText = NULL;
	char *name = "name";
	char *initString = "initString";
	char *type = "type";
	char *mult = "mult";
	// others
	int i;
	int varcount = 0;
	int numberOfVariables = 0;
// variable attribute boolean variables
	bool varlbattON  = false;
	bool varubattON = false ;
	bool vartypeattON  = false;
	bool varnameattON = false ;
	bool varinitattON = false ;
	bool varinitStringattON = false ;
	bool varmultattON = false;
	bool foundVar = false;
	//
	// start parsing
	// the way flex works is that the ch should be pointing to variables
	for(i = 0; startVariables[i]  == *ch; i++, ch++);
	if(i != 9) {osiltext = &ch[0]; osilerror("incorrect <variables tag>"); return false;}
	// find numberOfVariables attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; c_numberOfVariables[i]  == *ch; i++, ch++);
	if(i != 17) {osiltext = &ch[0]; osilerror("incorrect numberOfVariables attribute in <variables tag>"); return false;}	
	// buf_index should be pointing to the first character after numberOfVariables
	GETATTRIBUTETEXT;
	ch++;
	numberOfVariables = atoimod( attText);
	if(numberOfVariables <= 0) {
		osilerror("there must be at least one variable"); return false;
	}
	osinstance->instanceData->variables->numberOfVariables = numberOfVariables;
	osinstance->instanceData->variables->var = new Variable*[ numberOfVariables];
	for(i = 0; i < numberOfVariables; i++){
		osinstance->instanceData->variables->var[ i] = new Variable();
	} 
	// get rid of white space after the numberOfVariables element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ )
	// since there must be at least one variable,  this element must end with > 
	// better have an > sign or not valid
	if(*ch != '>' ) {osiltext = &ch[0]; osilerror("variables element does not have a proper closing >"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the var elements, there must be at least one var element
	for(i = 0; startVar[i]  == *ch; i++, ch++);
	if(i ==  4) foundVar = true;
		else {osiltext = &ch[0]; osilerror("there must be at least one <var> element"); return false;}
	while(foundVar){
		varlbattON  = false;
		varubattON = false ;
		vartypeattON  = false;
		varnameattON = false ;
		varinitattON = false ;
		varinitStringattON = false ;
		varmultattON = false;
		foundVar = false;
		// assume we are pointing to the first character after the r in <var
		// it should be whitespace
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		while(*ch != '/' && *ch != '>'){
			switch (*ch) {
			case 'n':
				for(i = 0; name[i]  == *ch; i++, ch++);
				if( i != 4 ) {osiltext = &ch[0]; osilerror("error in variables name attribute"); return false;}
				if(varnameattON == true) {osiltext = &ch[0]; osilerror("error too many variable name attributes"); return false;}
				varnameattON == true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->name=attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'i':
				for(i = 0; initString[i]  == *ch; i++, ch++);
				// if i < 4 there is an error
				// if i = 4 we matched init
				// if i = 10 we matched initString
				if( (i != 4)  && (i != 10)) {osiltext = &ch[0]; osilerror("error in variables init or initString attribute"); return false;}
				if(i == 4){
					if(varinitattON == true) {osiltext = &ch[0]; osilerror("error too many variable init attributes"); return false;}
					varinitattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->init=atofmod(attText);
				}
				else{
					if(varinitStringattON == true) {osiltext = &ch[0]; osilerror("error too many variable initString attributes"); return false;}
					varinitStringattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->initString=attText;
				}
				break;
			case 't':
				for(i = 0; type[i]  == *ch; i++, ch++);
				if(i != 4) {osiltext = &ch[0]; osilerror("error in variables type attribute"); return false;}
				if(vartypeattON == true) {osiltext = &ch[0]; osilerror("error too many variable type attributes"); return false;}
				vartypeattON = true;
				GETATTRIBUTETEXT;
				if( strchr("CBIS", attText[0]) == NULL ) {osiltext = &ch[0]; osilerror("variable type not C,B,I, or S"); return false;}
				osinstance->instanceData->variables->var[varcount]->type = attText[0];
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') {osiltext = &ch[0]; osilerror("error in variables lower bound attribute"); return false;}
				if(varlbattON == true) {osiltext = &ch[0]; osilerror("error too many variable lb attributes"); return false;}
				varlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->lb = atofmod(attText);
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {osiltext = &ch[0]; osilerror("error in variables upper bound attribute"); return false;}
				if(varubattON == true) {osiltext = &ch[0]; osilerror("error too many variable ub attributes"); return false;}
				varubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->ub = atofmod(attText);
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				for(i = 0; mult[i]  == *ch; i++, ch++);
				if(i != 4) {osiltext = &ch[0]; osilerror("error in variables mult attribute"); return false;}
				if(varmultattON == true) {osiltext = &ch[0]; osilerror("error too many variable mult attributes"); return false;}
				varmultattON = true;
				GETATTRIBUTETEXT;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case ' ':
				break;
			case '\n':
				osillineno++;
				break;
			case '\t':
				break;
			case '\r':
				break;
			default:
				{osiltext = &ch[0]; osilerror("invalid attribute character"); return false;}
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </var whitespace>
		if( *ch != '/' && *ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <var> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <var> element"); return false;}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <var> element or foundVar = false;
			for(i = 0; startVar[i]  == *ch; i++, ch++);
			if(i == 4) {
				foundVar = true;
			}
			else {
				foundVar = false;
			}
		}
		else{
			// the buf_index is the > at the end of the var element 
			// double check to make sure it really is a >
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improper ending to a <var> element"); return false;}
			// look for </var
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </var or there is an error
			for(i = 0; endVar[i]  == *ch; i++, ch++);
			if(i != 5) {osiltext = &ch[0]; osilerror("</var> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </var
			if(*ch++ != '>') {osiltext = &ch[0]; osilerror("</var> element missing >"); return false;}
			// look for a new <var> element
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <var> element or foundVar = false;
			for(i = 0; startVar[i]  == *ch; i++, ch++);
			if(i == 4) {
				foundVar = true;
			}
			else {
				foundVar = false;
			}
		}
		if( (varcount == numberOfVariables - 1) && (foundVar == true) ) {osiltext = &ch[0];  osilerror("attribute numberOfVariables is less than actual number found");  return false;}
		varcount++;
	}
	ch -= i;
	if(varcount < numberOfVariables) {osiltext = &ch[0]; osilerror("attribute numberOfVariables is greater than actual number found");   return false;}
	// get the </variables> tag
	for(i = 0; endVariables[i]  == *ch; i++, ch++);
	if(i != 11) {osiltext = &ch[0];  osilerror("cannot find </varialbes> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0];  osilerror("improperly formed </variables> tag"); return false;}
	ch++;
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE VARIABLES = %f\n", duration);
	return true;
}//end parseVariables


bool parseObjectives(){
	start = clock();
	char *c_numberOfObjectives = "numberOfObjectives";
	char *startObjectives = "<objectives";
	char *endObjectives = "</objectives";
	char *startObj = "<obj";
	char *endObj = "</obj";
	// attributes
	char *attText = NULL;
	char *constant = "constant";
	char *maxOrMin = "maxOrMin";
	char *numberOfObjCoef = "numberOfObjCoeff";
	char *weight = "weight";
	char *name = "name";
	char *mult = "mult";
	// others
	int i;
	// objective function attribute boolean variables
	bool objmaxOrMinattON = false;
	bool objnameattON = false;
	bool objconstantattON = false;
	bool objweightattON = false;
	bool objmultattON = false;
	bool objnumberOfObjCoefattON = false;
	int objcount = 0;
	int numberOfObjectives;
	bool foundObj;
	// start parsing
	// burn white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <objectives element if there -- it is not required
	for(i = 0; startObjectives[i]  == *ch; i++, ch++);
	if(i != 11) {
		//reset ch
		ch -= i;
		// we return true because it is okay to not have objectives
		return true;
	}
	// find numberOfObjectives attribute -- it is valid for this attribute to be missing. 
	// However if the  number attribute is missing assume it is	1 
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we just ate the white space. If numberOfObjectives is missing we assume it is 1
	// we therefore must have > char
	if(*ch == '>'){
		numberOfObjectives = 1;
		//ch++;
	}
	else{
		for(i = 0; c_numberOfObjectives[i]  == *ch; i++, ch++);
		if(i != 18) {osiltext = &ch[0]; osilerror("incorrect numberOfObjectives attribute in <objectives> tag"); return false;}	
		GETATTRIBUTETEXT;
		numberOfObjectives = atoimod( attText);
		ch++;
	}
	if(numberOfObjectives > 0){
		// get rid of white space after the numberOfObjectives attribute
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// we must have an >
		/*if(*ch == '/'){
			ch++;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the objectives element does not have a proper closing"); return false; }
			else{
				if(numberOfObjectives > 0){osiltext = &ch[0];  osilerror("numberOfObjectives positive but there are no objectives"); return false;}
				return false;
			}
		}*/
		//  we better have an > 
		if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the objectives element does not have a proper closing"); return false;} 
		osinstance->instanceData->objectives->numberOfObjectives = numberOfObjectives;
		osinstance->instanceData->objectives->obj = new Objective*[ numberOfObjectives];
		for(i = 0; i < numberOfObjectives; i++){
			osinstance->instanceData->objectives->obj[ i] = new Objective();
		} 	
	// get rid of white space after the <objectives> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the obj elements, there must be at least one obj element
	for(i = 0; startObj[ i] == *ch; i++, ch++);
	if( i == 4) foundObj = true;
		else {osiltext = &ch[0]; osilerror("there must be at least one <obj> element"); return false;}
	start = clock();	
	while(foundObj){
		objmaxOrMinattON = false;
		objnameattON = false;
		objconstantattON = false;
		objweightattON = false;
		objmultattON = false;
		objnumberOfObjCoefattON = false;
		// assume we are pointing to the first character after the r in <obj
		// it should be a space so let's increment ch
		ch++;
		while(*ch != '/' && *ch != '>'){
			switch (*ch) {
			case 'n':
				if( *(ch+1) == 'u'){
					for(i = 0; numberOfObjCoef[i]  == *ch; i++, ch++);
					if( (i != 15)  ) {osiltext = &ch[0]; osilerror("error in objective numberOfObjCoef attribute"); return false;}
					else{
						if(objnumberOfObjCoefattON == true) {osiltext = &ch[0]; osilerror("error too many obj numberOfObjCoefatt attributes"); return false;}
						objnumberOfObjCoefattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef=atoimod(attText);
						osinstance->instanceData->objectives->obj[objcount]->coef = new ObjCoef*[osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef];
						for(int i = 0; i < osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef; i++)osinstance->instanceData->objectives->obj[objcount]->coef[i] = new ObjCoef();
					}
				}
				else{
					for(i = 0; name[i]  == *ch; i++, ch++);
					if( (i != 4)  ) {osiltext = &ch[0]; osilerror("error in objective name attribute"); return false;}
					else{
						if(objnameattON == true) {osiltext = &ch[0]; osilerror("error too many obj name attributes"); return false;}
						objnameattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->objectives->obj[objcount]->name=attText;
					}
				}
				break;
			case 'c':
				for(i = 0; constant[i]  == *ch; i++, ch++);
				if( (i != 7)  ) {osiltext = &ch[0]; osilerror("error in objective constant attribute"); return false;}
				else{
					if(objconstantattON == true) {osiltext = &ch[0]; osilerror("error too many obj constant attributes"); return false;}
					objconstantattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->constant=atofmod(attText);
				}
				break;
			case 'w':
				for(i = 0; weight[i]  == *ch; i++, ch++);
				if( (i != 6)  ) {osiltext = &ch[0]; osilerror("error in objective weight attribute"); return false;}
				else{
					if(objweightattON == true) {osiltext = &ch[0]; osilerror("error too many obj weight attributes"); return false;}
					objweightattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->weight=atofmod(attText);
				}
				break;
			case 'm':
				if(*(ch+1) == 'a'){
					for(i = 0; maxOrMin[i]  == *ch; i++, ch++);
					if( (i != 8)  ) {osiltext = &ch[0]; osilerror("error in objective maxOrMin attribute"); return false;}
					else{
						if(objmaxOrMinattON == true) {osiltext = &ch[0]; osilerror("error too many obj maxOrMin attributes"); return false;}
						objmaxOrMinattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						if( (strcmp("max", attText) != 0 ) && (strcmp("min", attText) != 0 ) ){osilerror("maxOrMin attribute in objective must be a max or min"); return false;}
						osinstance->instanceData->objectives->obj[objcount]->maxOrMin = attText;
					}
				}
				else{
					for(i = 0; mult[i]  == *ch; i++, ch++);
					if( (i != 4)  ) {osiltext = &ch[0]; osilerror("error in objective mult attribute"); return false;}
					else{
						if(objmultattON == true) {osiltext = &ch[0]; osilerror("error too many obj mult attributes"); return false;}
						objmultattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						//osinstance->instanceData->objectives->obj[objcount]->name=attText;
					}
				}
				break;
			// come back and do multiplicity
			case ' ':
				break;
			case '\n':
				osillineno++;
				break;
			case '\t':
				break;
			case '\r':
				break;
			default:
				osiltext = &ch[0];
				osilerror("invalid attribute character");
				return false;
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </obj whitespace>
		if( *ch != '/' && *ch != '>') {osiltext = &ch[0];  osilerror("incorrect end of <obj> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <obj> element"); return false;}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <obj> element or foundObj = false;
			for(i = 0; startObj[i]  == *ch; i++, ch++);
			if(i == 4) foundObj = true;
				else foundObj = false;
		}
		else{
			// the ch is the > at the end of the obj element
			// double check to make sure it really is a >
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improper ending to a <obj> element"); return false;}
			// look for </obj
			// fist get rid of white space
			ch++;
			// first get the <coef> elements
			parseObjCoef( objcount);
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </obj or there is an error
			for(i = 0; endObj[i]  == *ch; i++, ch++);
			if(i != 5) {osiltext = &ch[0]; osilerror("</obj> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </obj
			if(*ch++ != '>'){osiltext = &ch[0];  osilerror("</obj> element missing >"); return false;}
			// look for a new <obj> element
			// get rid of whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <obj> element or foundObj = false;
			for(i = 0; startObj[i]  == *ch; i++, ch++);
			if(i == 4) foundObj = true;
				else foundObj = false;
		}
		if( (objcount == numberOfObjectives - 1) && (foundObj == true)) {osiltext = &ch[0]; osilerror("attribute numberOfObjectives is less than actual number found"); return false;}
		objcount++;
	}
	if(objcount < numberOfObjectives) {osiltext = &ch[0]; osilerror("attribute numberOfObjectives is greater than actual number found"); return false;}
	ch -= i;
	// get the </objectives> tag
	for(i = 0; endObjectives[i]  == *ch; i++, ch++);
	if(i != 12) {osiltext = &ch[0]; osilerror( "cannot find </objectives> tag"); return false; }
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </objectives> tag"); return false;}	
	ch++;
	} // finish the (if numberOfObjectives > 0)
	else{
		// error if the number is negative
		if(numberOfObjectives < 0) {osiltext = &ch[0]; osilerror("cannot have a negative number of objectives"); return false;}
		// if we are here we have exactly 0 objectives 
		// must close with /> or </objectives>
		// get rid of white space
		for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		if( *ch == '/'){
			// better have a >
			ch++;
			if( *ch  != '>') {osiltext = &ch[0]; osilerror("improperly closed objectives tag"); return false;}
			ch++;
		}
		else{
			// if we are here we must have an '>' and then  </objectives> tag
			if( *ch  != '>') {osiltext = &ch[0]; osilerror("improperly closed objectives tag"); return false;}
			ch++;
			// burn white space
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			for(i = 0; endObjectives[i]  == *ch; i++, ch++);
			if(i != 12) {osiltext = &ch[0]; osilerror( "cannot find </objectives> tag"); return false; }
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
			// better have >
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </objectives> tag"); return false;}	
			ch++;
		}
	}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE OBJECTIVES = %f\n", duration);
	return true;
}//end parseObjectives

bool parseConstraints(){
	start = clock();	
	char *c_numberOfConstraints = "numberOfConstraints";
	char *startConstraints = "<constraints";
	char *endConstraints = "</constraints";
	char *startCon = "<con";
	char *endCon = "</con";
	// attributes
	char *attText = NULL;
	char *name = "name";
	char *constant = "constant";
	char *mult = "mult";
	// others
	int i;
	int concount = 0;
	int numberOfConstraints = 0;
	// constraint attribute boolean variables
	bool conlbattON = false ;
	bool conubattON  = false;
	bool connameattON = false;
	bool conconstantattON  = false;
	bool conmultattON = false;
	bool foundCon = false;
	// start parsing
	// burn white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <constraints element if there -- it is not required
	for(i = 0; startConstraints[i]  == *ch; i++, ch++);
	if(i != 12) {
		//reset ch
		ch -= i;
		return true;
	}
	// find numberOfConstraints attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; c_numberOfConstraints[i]  == *ch; i++, ch++);
	if(i != 19) {osiltext = &ch[0]; osilerror("incorrect numberOfConstraints attribute in <constraints> tag"); return false;}	
	// ch should be pointing to the first character after numberOfObjectives
	GETATTRIBUTETEXT;
	ch++;
	numberOfConstraints = atoimod( attText);
	// key if
	//
	if(numberOfConstraints > 0){
		osinstance->instanceData->constraints->numberOfConstraints = numberOfConstraints;
		osinstance->instanceData->constraints->con = new Constraint*[ numberOfConstraints];
		for(i = 0; i < numberOfConstraints; i++){
			osinstance->instanceData->constraints->con[ i] = new Constraint();
		} 
	// get rid of white space after the numberOfConstraints element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	//  we better have an > 
	if( *ch++ != '>') {osiltext = &ch[0];  osilerror("the constraints element does not have a proper closing"); return false;} 
	// get rid of white space after the <constraints> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the con elements, there must be at least one con element
	for(i = 0; startCon[i]  == *ch; i++, ch++);
	if( i == 4) foundCon = true;
		else {osiltext = &ch[0]; osilerror("there must be at least one <con> element"); return false;}
	while(foundCon){
		conlbattON = false ;
		conubattON  = false;
		connameattON = false;
		conconstantattON  = false;
		conmultattON = false;
		// assume we are pointing to the first character after the n in <con
		// it should be a space so let's increment ch
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		while(*ch != '/' && *ch != '>'){
			switch (*ch) {
			case 'n':
				for(i = 0; name[i]  == *ch; i++, ch++);
				if(i != 4) {osiltext = &ch[0]; osilerror("error in constraints name attribute"); return false;}
				if(connameattON == true) {osiltext = &ch[0]; osilerror("error too many con name attributes"); return false;}
				connameattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->name=attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'c':
				for(i = 0; constant[i]  == *ch; i++, ch++);
				if( (i != 7)  ) {osiltext = &ch[0]; osilerror("error in constraint constant attribute"); return false;}
				if(conconstantattON == true) {osiltext = &ch[0]; osilerror("error too many con constant attributes"); return false;}
				conconstantattON = true;
				GETATTRIBUTETEXT;
				//printf("ATTRIBUTE = %s\n", attText);
				osinstance->instanceData->constraints->con[concount]->constant=atofmod(attText);
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') { osiltext = &ch[0]; osilerror("error in constraint lb attribute"); return false;}
				if(conlbattON == true) {osiltext = &ch[0]; osilerror("error too many con lb attributes"); return false;}
				conlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->lb = atofmod(attText);
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {osiltext = &ch[0]; osilerror("error in constraint ub attribute"); return false;}
				if(conubattON == true) {osiltext = &ch[0]; osilerror("error too many con ub attributes"); return false;}
				conubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->ub = atofmod(attText);
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				for(i = 0; mult[i]  == *ch; i++, ch++);
				if(i != 4) {osiltext = &ch[0]; osilerror("error in constraints mult attribute"); return false;}
				if(conmultattON == true) {osiltext = &ch[0]; osilerror("error too many con mult attributes"); return false;}
				conmultattON = true;
				GETATTRIBUTETEXT;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case ' ':
				break;
			case '\n':
				osillineno++;
				break;
			case '\t':
				break;
			case '\r':
				break;
			default:
				osiltext = &ch[0];
				osilerror("invalid attribute character");
				return false;
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </con whitespace>
		if( *ch != '/' && *ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <con> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <con> element"); return false;}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <con> element or foundCon = false;
			for( i = 0; startCon[i]  == *ch; i++, ch++);
			if( i == 4) foundCon = true;
				else foundCon = false;
		}
		else{
			// the ch is the > at the end of the con element 
			// double check to make sure it really is a >
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improper ending to a <obj> element"); return false;}
			// look for </con
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </con or there is an error
			for(i = 0; endCon[i]  == *ch; i++, ch++);
			if(i != 5) {osiltext = &ch[0]; osilerror("</con> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </con
			if(*ch++ != '>') {osiltext = &ch[0]; osilerror("</con> element missing >"); return false;}
			// look for a new <con> element
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <con> element or foundVar = false;
			for(i = 0; startCon[i]  == *ch; i++, ch++);
			if(i == 4) foundCon = true;
				else foundCon = false;
		}
		if( (concount == numberOfConstraints - 1) && (foundCon == true) ) {osiltext = &ch[0]; osilerror("attribute numberOfConstraints is less than actual number found"); return false;}
		concount++;
	}
	if(concount < numberOfConstraints) {osiltext = &ch[0]; osilerror("attribute numberOfConstraints is greater than actual number found"); return false;}
	ch -= i;
	// get the </constraints> tag
	for(i = 0; endConstraints[i]  == *ch; i++, ch++);
	if(i != 13) {osiltext = &ch[0]; osilerror( "cannot find </constraints> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </constraints> tag");	return false;}
	ch++;
	}// end if(numberOfConstraints > 0)
	else{
		// error if the number is negative
		if(numberOfConstraints < 0) {osiltext = &ch[0]; osilerror("cannot have a negative number of constraints"); return false;}
		// if we are here we have numberOfConstraints = 0
		// must close with /> or </constraints>
		// get rid of white space
		for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		if( *ch == '/'){
			// better have a >
			ch++;
			if( *ch  != '>') {osiltext = &ch[0]; osilerror("improperly closed constraints tag"); return false;}
			ch++;
		}
		else{
			// if we are here we must have an '>' and then  </constraints> tag
			if( *ch  != '>') {osiltext = &ch[0]; osilerror("improperly closed constraints tag"); return false;}
			ch++;
			// burn white space
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			for(i = 0; endConstraints[i]  == *ch; i++, ch++);
			if(i != 13) {osiltext = &ch[0]; osilerror( "cannot find </constraints> tag"); return false; }
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
			// better have >
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </constraints> tag"); return false;}	
			ch++;
		}
	}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE CONSTRAINTS = %f\n", duration);
	return true;
}//end parseConstraints

bool parseLinearConstraintCoefficients(){
	start = clock();	
	char *c_numberOfValues = "numberOfValues";
	char *startlinearConstraintCoefficients = "<linearConstraintCoefficients";
	char *endlinearConstraintCoefficients = "</linearConstraintCoefficients";
	// attributes
	char *attText = NULL;
	// others
	int i;
	int numberOfValues;
	// start parsing
	// burn white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <linearConstraintCoefficients element if there -- it is not required
	for(i = 0; startlinearConstraintCoefficients[i]  == *ch; i++, ch++);
	if(i != 29) {
		//reset ch
		ch -= i;
		return false;
	}
	// find numberOfValues attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; c_numberOfValues[i]  == *ch; i++, ch++);
	if(i != 14) {osiltext = &ch[0]; osilerror("incorrect numberOfValues attribute in <linearConstraintCoefficients> tag"); return false;}
	// ch should be pointing to the first character after numberOfObjectives
	GETATTRIBUTETEXT;
	ch++;
	numberOfValues = atoimod( attText);
	if(numberOfValues <= 0) {osiltext = &ch[0]; osilerror("the number of nonlinear nozeros must be positive"); return false;}
	osinstance->instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
	// get rid of white space after the numberOfConstraints element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an />  OR an >
	if(*ch == '/'){
		ch++;
		if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the linearConstraintCoefficients element does not have a proper closing"); return false;} 
		else{
			if(numberOfValues > 0) {osiltext = &ch[0]; osilerror("numberOfValues positive, but there are no objectives"); return false;}
			return false;
		}		
	}
	//  we better have an > 
	if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the <linearConstraintCoefficients> element does not have a proper closing"); return false;}
	// get rid of white space after the <linearConstraintCoefficients> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	if( parseStart() != true) return false;
	if( (parseColIdx() != true) && ( parseRowIdx() != true)) return false;
	if( (parseColIdx() != true) && (parseRowIdx() == true) ){osiltext = &ch[0]; osilerror("cannot store by both row and column"); return false;}
	if( parseValue() != true) return false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// get the </linearConstraintCoefficients> tag
	for(i = 0; endlinearConstraintCoefficients[ i]  == *ch; i++, ch++);
	if(i != 30) {osiltext = &ch[0]; osilerror( "cannot find </linearConstraintCoefficients> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </linearConstraintCoefficients> tag"); return false;}
	ch++;	
	return true;
}//end parseLinearConstraintCoefficients

bool parseStart(){
	start = clock(); 
	char* startStart = "<start";
	char* endStart = "</start";
	char* startEl = "<el";
	char* endEl = "</el";
	int kount = 0;
	char* number = NULL;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <start element 
	for(i = 0; startStart[i]  == *ch; i++, ch++);
	if(i != 6) {
		//reset ch
		ch -= i;
		return false;
	}
	// get rid of white space after <start
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch =! '>') {osiltext = &ch[0]; osilerror("improperly formed <start> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	for(i = 0; startEl[i]  == *ch; i++, ch++);
	if(i != 3) {
		//reset ch
		ch -= i;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&dataSize );
		if( b64string == NULL) {osiltext = &ch[0]; osilerror("<start> must have children or base64 data"); return false;}
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		int *intvec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->start->el = new int[(base64decodeddatalength/dataSize) ];
		intvec = (int*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->start->el[ i] = *(intvec++);
		}
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->start->el = 
		new int[ std::max( osinstance->instanceData->constraints->numberOfConstraints,
		osinstance->instanceData->variables->numberOfVariables) + 1];
		while(foundEl){
			// start eating white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// okay we better have a number, we will check later
			number = &*ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0]; osilerror("cannot find an </el>"); return false;}
			// terminate the number string
			*ch++ = '\0';
			osinstance->instanceData->linearConstraintCoefficients->start->el[ kount++] = 
			atoimod( number);
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if(i != 4 ) {osiltext = &ch[0]; osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			for(i = 0; startEl[i]  == *ch; i++, ch++);
			if(i == 3) foundEl = true;
			else foundEl = false;
		}
		ch -= i;			
	}
	// get the </start> tag
	for(i = 0; endStart[i]  == *ch; i++, ch++);
	if(i != 7) {osiltext = &ch[0]; osilerror( "cannot find </start> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </start> tag");	return false;}
	ch++;	
	// get the end element
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE STARTS  = %f\n", duration);
	return true;
}//end parseSart

bool parseRowIdx(){
	start = clock(); 
	char* startRowIdx = "<rowIdx";
	char* endRowIdx = "</rowIdx";
	char* startEl = "<el";
	char* endEl = "</el";
	int kount = 0;
	char* number = NULL;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <rowIdx element 
	for(i = 0; startRowIdx[i]  == *ch; i++, ch++);
	if(i != 7) {
		//reset ch
		ch -= i;
		return false;
	}
	// get rid of white space after <rowIdx
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch =! '>') {osiltext = &ch[0]; osilerror("improperly formed <rowIdx> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	for(i = 0; startEl[i]  == *ch; i++, ch++);
	if(i != 3) {
		//reset ch
		ch -= i;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&dataSize );
		if( b64string == NULL)  {osiltext = &ch[0]; osilerror("<rowIdx> must have children or base64 data"); return false;}
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		int *intvec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[(base64decodeddatalength/dataSize) ];
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
		intvec = (int*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ i] = *(intvec++);
			kount++;
		}
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
		while(foundEl){
			// start munging white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag"); return false;}
			// mung white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			// okay we better have a number, we will check later
			number = &*ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0];  osilerror("cannot find an </el>"); return false;}
			// terminate the number string
			*ch++ = '\0';
			osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ kount++] = 
			atoimod( number);
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if(i != 4 ) {osiltext = &ch[0]; osilerror("cannot find an </el>"); return false;}
			// start munging white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			for(i = 0; startEl[i]  == *ch; i++, ch++);
			if(i == 3) foundEl = true;
			else foundEl = false;
		}
		 
		ch -= i;
	}
	// get the </rowIdx> tag
	for(i = 0; endRowIdx[i]  == *ch; i++, ch++);
	if(i != 8) {osiltext = &ch[0]; osilerror( "cannot find </rowIdx> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </rowIdx> tag");}	
	ch++;	
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror("numberOfLinearCoefficients attribute less than number of row indices found"); return false;}
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror("numberOfLinearCoefficients attribute greater than number of row indices found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE ROW INDEXES = %f\n", duration);
 return true;
}//end parseRowIdx


bool parseColIdx(){
	start = clock(); 
	char* startColIdx = "<colIdx";
	char* endColIdx = "</colIdx";
	char* startEl = "<el";
	char* endEl = "</el";
	int kount = 0;
	char* number = NULL;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <colIdx element 
	for(i = 0; startColIdx[i]  == *ch; i++, ch++);
	if(i != 7) {
		//reset ch
		ch -= i;
		return false;
	}
	// get rid of white space after <colIdx
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch =! '>') {osiltext = &ch[0]; osilerror("improperly formed <colIdx> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	for(i = 0; startEl[i]  == *ch; i++, ch++);
	if(i != 3) {
		//reset ch
		ch -= i;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&dataSize );
		if( b64string == NULL)  {osiltext = &ch[0]; osilerror("<colIdx> must have children or base64 data"); return false;}
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		int *intvec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[(base64decodeddatalength/dataSize) ];
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
		intvec = (int*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ i] = *(intvec++);
			kount++;
		}
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
		while(foundEl){
			// start eating white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			// okay we better have a number, we will check later
			number = &*ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0]; osilerror("cannot find an </el>"); return false;}
			// terminate the number string
			*ch++ = '\0';
			osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount++] = 
			atoimod( number);
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if( i != 4 ) {osiltext = &ch[0]; osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			for(i = 0; startEl[i]  == *ch; i++, ch++);
			if(i == 3) foundEl = true;
			else foundEl = false;
		}
		ch -= i;
	}
	// get the </colIdx> tag
	for(i = 0; endColIdx[i]  == *ch; i++, ch++);
	if(i != 8) {osiltext = &ch[0]; osilerror( "cannot find </rowIdx> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </colIdx> tag"); return false;}	
	//ch++;	
	ch = '\0';
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {osiltext = &ch[0]; osilerror("numberOfLinearCoefficients attribute less than number of column indices found"); return false;}
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {osiltext = &ch[0]; osilerror("numberOfLinearCoefficients attribute greater than number of column indices found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE COLUMN INDEXES = %f\n", duration);
 return true;
}//end parseColIdx


bool parseValue(){
	start = clock(); 
	char* startValue = "<value";
	char* endValue = "</value";
	char* startEl = "<el";
	char* endEl = "</el";
	int kount = 0;
	char* number = NULL;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) || isnull( *ch); ch++ ) ;
	// if, present we should be pointing to <rowIdx element 
	for(i = 0; startValue[i]  == *ch; i++, ch++){
		//cout << ch* ;
	}
	if(i != 6) {
		//reset ch
		ch -= i;
		return false;
	}
	// get rid of white space after <value
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) || isnull( *ch); ch++ ) ;
	// we should have either an >
	if(*ch =! '>') {osiltext = &ch[0]; osilerror("improperly formed <value> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) || isnull( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	for(i = 0; startEl[i]  == *ch; i++, ch++);
	if(i != 3) {
		//reset ch
		ch -= i;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&dataSize );
		if( b64string == NULL)  {osiltext = &ch[0]; osilerror("<start> must have children or base64 data"); return false;};
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		double *doublevec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->value->el = new double[(base64decodeddatalength/dataSize) ];
		doublevec = (double*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->value->el[ i] = *(doublevec++);
			kount++;
		}
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->value->el = 
			new double[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		while( foundEl){
			// start eat white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) || isnull( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) || isnull( *ch); ch++ ) ;
			number = &*ch;
			// find the end of the number, it better be an </el>
			// find the < which begins the </el
			while( *ch != '<' && *ch != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0]; osilerror("cannot find an </el>"); return false;}
			// terminate the number string
			*ch++ = '\0';
			osinstance->instanceData->linearConstraintCoefficients->value->el[ kount++] = 
			atofmod( number);
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if( i != 4 ) {osiltext = &ch[0]; osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) || isnull( *ch) ; ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) || isnull( *ch) ; ch++ );
			// either have another <el> element or foundEl = false;
			for(i = 0; startEl[i]  == *ch; i++, ch++);
			if(i == 3) foundEl = true;
			else foundEl = false;
		}	
		ch -= i;
	}
	// get the </value> tag
	for(i = 0; endValue[i]  == *ch; i++, ch++);
	if(i != 7) {osiltext = &ch[0]; osilerror( "cannot find </value> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch) || isnull( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </value> tag");	 return false;}
	ch++;	
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues){osiltext = &ch[0]; osilerror("numberOfLinearCoefficients greater than number of values found"); return false;}
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues){osiltext = &ch[0]; osilerror("numberOfLinearCoefficients less than the number of values found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE VALUES = %f\n", duration);
	return true;
}//end parseValue

bool parseObjCoef( int objcount){
	char* startCoef = "<coef";
	char* endCoef = "</coef";
	char* c_idx = "idx";
	int kount = 0;
	char* number = NULL;
	char* attText = NULL;
	int i, k;
	int numberOfObjCoef = 0; 
	bool foundCoef = false;
	cout << "NUMBER OF OBJECTIVE FUNCTIONS = " << osinstance->instanceData->objectives->numberOfObjectives << endl;
	if( osinstance->instanceData->objectives->numberOfObjectives <= 0)  {osiltext = &ch[0]; osilerror("we can't have objective function coefficients without an objective function"); return false;}
	numberOfObjCoef = osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef;
	if(numberOfObjCoef > 0)	{
	for(k = 0; k < numberOfObjCoef; k++){
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if, present we should be pointing to <coef element 
		for(i = 0; startCoef[i]  == *ch; i++, ch++);
		if(i != 5) {osiltext = &ch[0]; osilerror("improper <coef> element"); return false;}
		// get the idx attribute
		
		// find numberOfConstraints attribute
		// eat the white space after <coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		for(i = 0; c_idx[i]  == *ch; i++, ch++);
		if(i != 3) {osiltext = &ch[0]; osilerror("incorrect idx attribute in objective function <idx> tag"); return false;}	
		// ch should be pointing to the first character after numberOfObjectives
		GETATTRIBUTETEXT;
		ch++;	
		// eat white space
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {osiltext = &ch[0]; osilerror("incorrect <coef> element")	; return false;}	
		// we should be pointing to first character after <coef>
		number = &*ch;
		// eat characters until we find <
		for(; *ch != '<' && *ch != EOF; ch++); 
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->idx  = atoimod( attText);
		// we should be pointing to a < in the </coef> tag	
		*ch = '\0';
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->value  = atofmod( number);
		*ch = '<';
		for(i = 0; endCoef[i]  == *ch; i++, ch++);	
		if(i != 6)  {osiltext = &ch[0]; osilerror("improper </coef> element"); return false;}
		// get rid of white space after </coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {osiltext = &ch[0]; osilerror("incorrect </coef> element")	; return false;}
	}
	}// end if(numberOfObjCoef > 0)
	return true;
}//end parseObjCoef

char *parseBase64(int *dataSize ){
	char *sizeOf = "sizeOf";
	//char *numericType = "numericType";
	char *startBase64BinaryData = "<base64BinaryData";
	char *endBase64BinaryData = "</base64BinaryData";
	char *attText;
	char *b64string = NULL;
	int i;
	int endpoint;

	//
	// start parsing
	// the way flex works is that the ch should be pointing to variables
	for(i = 0; startBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 17) {
		ch -= i;
		return b64string;
	}
	// find sizeOf attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; sizeOf[i]  == *ch; i++, ch++);
	if(i != 6) {osiltext = &ch[0]; osilerror("incorrect sizeOf attribute in <base64BinaryData> element"); return false;}	
	// ch should be pointing to the first character after sizeOf
	GETATTRIBUTETEXT;
	ch++;
	*dataSize = atoimod( attText);
	// since the element must contain b64 data,  this element must end with > 
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {osiltext = &ch[0]; osilerror("<base64BinaryData> element does not have a proper closing >"); return false;}
	ch++;
	// we are now pointing start of the data
	b64string = &*ch;
	// eat characters until we get to the </base64BinaryData element
	for(; *ch != '<' && *ch != EOF; ch++);
	// we should be pointing to </base64BinaryData>
	for(i = 0; endBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 18) {osiltext = &ch[0];osilerror(" problem with <base64BinaryData> element"); return false;}
	ch[ -18] = '\0';
	// burn the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {osiltext = &ch[0]; osilerror("</base64BinaryData> element does not have a proper closing >"); return false;}
	ch++;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	return b64string;
}


char parseErrorDouble[50]  =  "an invalid value for xsd:double  ";
char parseErrorInteger[50] =  "an invalid value for xsd:int  ";


double atofmod(char *number){
	double val, power;
	int i;
	int sign = 1;
	int expsign, exppower, exptest;
	int endWhiteSpace;
	// modidfied atof from Kernighan and Ritchie
	for(i = 0;  ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	sign = (number[ i] == '-') ? -1 : 1;
	if (number[ i] == '+' || number[ i] == '-') i++;
	endWhiteSpace = i;
	for(val = 0.0; ISDIGIT( number[ i]); i++){
		val = 10.0 *val + (number[ i] - '0') ;
	}
	if (number[ i] == '.') {
		i++;
		for (power = 1.0; ISDIGIT(number[ i]); i++){
			val = 10.0*val + (number[ i] - '0');
			power *= 10.0;
		}
		val = val/power;
	}
	if(i == endWhiteSpace) {
	// we better have INF or NaN
		switch (number[ i]){
		case 'I':
			i++;
			if(number[ i++] == 'N' && number[i++] == 'F'){
				val = OSINFINITY;
				break;
			}
			else{
				osiltext = number; 
				osilerror( strcat(parseErrorDouble, number));
			}
		case 'N':
			i++;
			if(number[ i-2] != '+' &&  number[ i-2] != '-' && number[ i++] == 'a' && number[i++] == 'N'){
				val = OSNAN;
				break;
			}
			else{
				osiltext = number; 
				osilerror( strcat(parseErrorDouble, number));
				
			}

		default:
			osiltext = number; 
			osilerror( strcat(parseErrorDouble, number));
			
			break;
		}
	}
	else{
		if(number[i] == 'e' || number[i] == 'E' ){
			i++;
			// process exponential part of the term
			// we have ([eE][-+]?[0-9]+)?
			// we are not going to process a NAN or INF
			expsign = (number[ i] == '-') ? -1 : 1;
			if (number[ i] == '+' || number[ i] == '-') i++;
			// get the exponent power 
			//
			exptest = i;
			for(exppower = 0 ; ISDIGIT( number[ i]); i++){
				exppower = 10 *exppower + (number[ i] - '0') ;
			}
			if(i == exptest) {osiltext = &number[0]; osilerror( strcat(parseErrorDouble, number)); 	}
			val = val*pow(10, expsign*exppower);
			//printf("number = %f\n", val);
		}
	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	if(number[i] == '\0'){
		return sign*val;
	}
	else {osiltext = &number[0]; osilerror( strcat(parseErrorDouble, number)); 	}
}//end atofmod



int atoimod(char *number){
	// modidfied atoi from Kernighan and Ritchie
	int ival, power;
	int i, sign;
	int endWhiteSpace;
	for(i = 0; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	endWhiteSpace = i;
	sign = (number[ i] == '-') ? -1 : 1;
	if (number[ i] == '+' || number[ i] == '-') i++;
	for(ival = 0; ISDIGIT( number[ i]); i++){
		ival = 10*ival + (number[ i] - '0') ;
	}
	if(i == endWhiteSpace) {osiltext = number; osilerror( strcat(parseErrorInteger, number)); 	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	if(number[i] == '\0'){
		return sign*ival;
	}
	else {osiltext = number; osilerror(strcat(parseErrorInteger, number)); 	}
}//end atoimod






