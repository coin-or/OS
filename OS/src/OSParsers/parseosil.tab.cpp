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
     OSILEND = 262,
     INSTANCEDATAEND = 263,
     VALUEATT = 264,
     NUMBEROFNONLINEAREXPRESSIONS = 265,
     IDXONEATT = 266,
     IDXTWOATT = 267,
     COEFATT = 268,
     IDATT = 269,
     TIMESSTART = 270,
     TIMESEND = 271,
     NUMBERSTART = 272,
     NUMBEREND = 273,
     NUMBEROFQTERMSATT = 274,
     IDXATT = 275,
     TYPEATT = 276,
     QTERMSTART = 277,
     QTERMEND = 278,
     QUADRATICCOEFFICIENTSSTART = 279,
     QUADRATICCOEFFICIENTSEND = 280,
     NONLINEAREXPRESSIONSSTART = 281,
     NONLINEAREXPRESSIONSEND = 282,
     NLSTART = 283,
     NLEND = 284,
     POWERSTART = 285,
     POWEREND = 286,
     PLUSSTART = 287,
     PLUSEND = 288,
     MINUSSTART = 289,
     MINUSEND = 290,
     DIVIDESTART = 291,
     DIVIDEEND = 292,
     LNSTART = 293,
     LNEND = 294,
     SUMSTART = 295,
     SUMEND = 296,
     PRODUCTSTART = 297,
     PRODUCTEND = 298,
     ENDOFELEMENT = 299,
     EXPSTART = 300,
     EXPEND = 301,
     NEGATESTART = 302,
     NEGATEEND = 303,
     IFSTART = 304,
     IFEND = 305,
     GREATERTHAN = 306,
     VARIABLESTART = 307,
     VARIABLEEND = 308,
     ABSSTART = 309,
     ABSEND = 310,
     MAXSTART = 311,
     MAXEND = 312
   };
#endif
/* Tokens.  */
#define QUOTE 258
#define ATTRIBUTETEXT 259
#define INTEGER 260
#define DOUBLE 261
#define OSILEND 262
#define INSTANCEDATAEND 263
#define VALUEATT 264
#define NUMBEROFNONLINEAREXPRESSIONS 265
#define IDXONEATT 266
#define IDXTWOATT 267
#define COEFATT 268
#define IDATT 269
#define TIMESSTART 270
#define TIMESEND 271
#define NUMBERSTART 272
#define NUMBEREND 273
#define NUMBEROFQTERMSATT 274
#define IDXATT 275
#define TYPEATT 276
#define QTERMSTART 277
#define QTERMEND 278
#define QUADRATICCOEFFICIENTSSTART 279
#define QUADRATICCOEFFICIENTSEND 280
#define NONLINEAREXPRESSIONSSTART 281
#define NONLINEAREXPRESSIONSEND 282
#define NLSTART 283
#define NLEND 284
#define POWERSTART 285
#define POWEREND 286
#define PLUSSTART 287
#define PLUSEND 288
#define MINUSSTART 289
#define MINUSEND 290
#define DIVIDESTART 291
#define DIVIDEEND 292
#define LNSTART 293
#define LNEND 294
#define SUMSTART 295
#define SUMEND 296
#define PRODUCTSTART 297
#define PRODUCTEND 298
#define ENDOFELEMENT 299
#define EXPSTART 300
#define EXPEND 301
#define NEGATESTART 302
#define NEGATEEND 303
#define IFSTART 304
#define IFEND 305
#define GREATERTHAN 306
#define VARIABLESTART 307
#define VARIABLEEND 308
#define ABSSTART 309
#define ABSEND 310
#define MAXSTART 311
#define MAXEND 312




/* Copy the first part of user declarations.  */



 
#include <iostream>
#include <sstream>  
#include <time.h>   
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
double atofmod1(const char *ch1, const char *ch2);
int atoimod1(const char *ch1, const char *ch2);
// we distinguish a newline from other whitespace
// since we need to know when we hit a new line
bool isnewline(char c);
bool parseVariables( const char **pchar);
bool parseObjectives( const char **pchar);
bool parseObjCoef( const char **pchar, int objcount);
bool parseConstraints( const char **pchar);
bool parseLinearConstraintCoefficients( const char **pchar);
bool parseStart( const char **pchar);
bool parseRowIdx( const char **pchar);
bool parseColIdx( const char **pchar);
bool parseValue( const char **pchar);
bool parseInstanceHeader(const char **pchar);
bool parseInstanceData(const char **pchar);
char *parseBase64(const char **p, int *dataSize );

const int numErrorChar = 20;
char errorArray[100] = "there was an error";

#define GAIL printf("GAIL ANN HONDA\n")

#define	ISWHITESPACE( char_) ((char_) == ' ' || \
                     (char_) == '\t' ||  (char_) == '\r')

#define	ISDIGIT(_c) ((_c) >= '0' && (_c) <= '9')

#define GETATTRIBUTETEXT  	\
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ; \
	if( *ch != '=') {strncpy(errorArray, ch, numErrorChar); osilerror("found an attribute not defined"); return false;}  \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;	\
	if(*ch != '\"'  && *ch != '\"') {strncpy(errorArray, ch, numErrorChar); osilerror("missing quote on attribute"); return false;} \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ; \
	*p = ch; \
	for( ; *ch != '\"' &&  *ch != '\''; ch++); \
	numChar = ch - *p; \
	attText = new char[numChar + 1]; \
	for(ki = 0; ki < numChar; ki++) attText[ki] = *((*p)++); \
	attText[ki] = '\0'; \
	attTextEnd = &attText[ki]; 
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
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNRULES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,    59,
      61,     2,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    58,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,     9,    14,    19,    20,    23,    24,
      29,    31,    34,    35,    38,    41,    44,    47,    50,    53,
      56,    59,    62,    65,    66,    71,    76,    77,    78,    86,
      90,    92,    94,    96,    98,   100,   102,   104,   106,   108,
     110,   112,   114,   116,   118,   120,   121,   127,   128,   134,
     135,   141,   142,   147,   148,   154,   155,   161,   162,   167,
     169,   172,   173,   178,   180,   183,   184,   189,   191,   194,
     195,   200,   201,   206,   207,   212,   213,   220,   221,   226,
     227,   232,   234,   236,   238,   239,   244,   245,   248,   251,
     254,   257,   260,   263,   266,   269,   270,   273,   276,   279,
     282,   285,   288,   290,   292,   294,   296,   297,   300
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      63,     0,    -1,    64,    76,     8,     7,    -1,    -1,    24,
      65,    66,    25,    -1,    19,     5,   129,    51,    -1,    -1,
      66,    67,    -1,    -1,    68,    22,    70,    69,    -1,    44,
      -1,    51,    23,    -1,    -1,    70,    71,    -1,    72,   129,
      -1,    73,   129,    -1,    74,   129,    -1,    75,   129,    -1,
      11,     5,    -1,    12,     5,    -1,    13,     6,    -1,    13,
       5,    -1,    20,     5,    -1,    -1,    26,    77,    78,    27,
      -1,    10,     5,   129,    51,    -1,    -1,    -1,    78,    28,
      80,    51,    81,    79,    29,    -1,    20,     5,   129,    -1,
     111,    -1,   113,    -1,    82,    -1,    84,    -1,    94,    -1,
      86,    -1,    88,    -1,    90,    -1,    92,    -1,   100,    -1,
     103,    -1,   105,    -1,   109,    -1,   107,    -1,    97,    -1,
      -1,    15,    83,    81,    81,    16,    -1,    -1,    32,    85,
      81,    81,    33,    -1,    -1,    34,    87,    81,    81,    35,
      -1,    -1,    47,    89,    81,    48,    -1,    -1,    36,    91,
      81,    81,    37,    -1,    -1,    30,    93,    81,    81,    31,
      -1,    -1,    40,    95,    96,    41,    -1,    81,    -1,    96,
      81,    -1,    -1,    56,    98,    99,    57,    -1,    81,    -1,
      99,    81,    -1,    -1,    42,   101,   102,    43,    -1,    81,
      -1,   102,    81,    -1,    -1,    38,   104,    81,    39,    -1,
      -1,    45,   106,    81,    46,    -1,    -1,    54,   108,    81,
      55,    -1,    -1,    49,   110,    81,    81,    81,    50,    -1,
      -1,    17,   112,   118,   115,    -1,    -1,    52,   114,   123,
     116,    -1,    44,    -1,    18,    -1,    44,    -1,    -1,    51,
      81,   117,    53,    -1,    -1,   118,   119,    -1,   120,   129,
      -1,   122,   129,    -1,   121,   129,    -1,    21,     4,    -1,
      14,     4,    -1,     9,     6,    -1,     9,     5,    -1,    -1,
     123,   124,    -1,   125,   129,    -1,   126,   129,    -1,    13,
       6,    -1,    13,     5,    -1,    20,     5,    -1,    58,    -1,
      59,    -1,    60,    -1,    61,    -1,    -1,   128,   127,    -1,
     128,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   138,   138,   144,   145,   149,   154,   155,   157,   157,
     168,   169,   172,   173,   177,   180,   183,   186,   192,   194,
     196,   198,   200,   206,   207,   211,   216,   218,   217,   227,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   257,   257,   262,   262,   267,
     267,   272,   272,   277,   277,   282,   282,   287,   287,   297,
     298,   301,   301,   311,   312,   315,   315,   325,   326,   329,
     329,   335,   335,   340,   340,   346,   346,   351,   351,   356,
     356,   361,   362,   364,   365,   365,   375,   376,   378,   380,
     382,   386,   390,   396,   399,   403,   404,   406,   408,   411,
     414,   418,   423,   424,   425,   426,   428,   429,   431
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "QUOTE", "ATTRIBUTETEXT", "INTEGER",
  "DOUBLE", "OSILEND", "INSTANCEDATAEND", "VALUEATT",
  "NUMBEROFNONLINEAREXPRESSIONS", "IDXONEATT", "IDXTWOATT", "COEFATT",
  "IDATT", "TIMESSTART", "TIMESEND", "NUMBERSTART", "NUMBEREND",
  "NUMBEROFQTERMSATT", "IDXATT", "TYPEATT", "QTERMSTART", "QTERMEND",
  "QUADRATICCOEFFICIENTSSTART", "QUADRATICCOEFFICIENTSEND",
  "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND", "NLSTART",
  "NLEND", "POWERSTART", "POWEREND", "PLUSSTART", "PLUSEND", "MINUSSTART",
  "MINUSEND", "DIVIDESTART", "DIVIDEEND", "LNSTART", "LNEND", "SUMSTART",
  "SUMEND", "PRODUCTSTART", "PRODUCTEND", "ENDOFELEMENT", "EXPSTART",
  "EXPEND", "NEGATESTART", "NEGATEEND", "IFSTART", "IFEND", "GREATERTHAN",
  "VARIABLESTART", "VARIABLEEND", "ABSSTART", "ABSEND", "MAXSTART",
  "MAXEND", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept", "osildoc",
  "quadraticcoefficients", "quadnumberatt", "qTermlist", "qterm", "@1",
  "qtermend", "anotherqTermATT", "qtermatt", "qtermidxOneatt",
  "qtermidxTwoatt", "qtermcoefatt", "qtermidxatt", "nonlinearExpressions",
  "nlnumberatt", "nlnodes", "@2", "nlIdxATT", "nlnode", "times", "@3",
  "plus", "@4", "minus", "@5", "negate", "@6", "divide", "@7", "power",
  "@8", "sum", "@9", "anothersumnlnode", "max", "@10", "anothermaxnlnode",
  "product", "@11", "anotherproductnlnode", "ln", "@12", "exp", "@13",
  "abs", "@14", "if", "@15", "number", "@16", "variable", "@17",
  "numberend", "variableend", "@18", "anotherNumberATT", "numberATT",
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
     305,   306,   307,   308,   309,   310,   311,   312,    32,     9,
      13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    66,    66,    68,    67,
      69,    69,    70,    70,    71,    71,    71,    71,    72,    73,
      74,    74,    75,    76,    76,    77,    78,    79,    78,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    83,    82,    85,    84,    87,
      86,    89,    88,    91,    90,    93,    92,    95,    94,    96,
      96,    98,    97,    99,    99,   101,   100,   102,   102,   104,
     103,   106,   105,   108,   107,   110,   109,   112,   111,   114,
     113,   115,   115,   116,   117,   116,   118,   118,   119,   119,
     119,   120,   121,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   127,   127,   127,   127,   128,   128,   129
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     4,     4,     0,     2,     0,     4,
       1,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     0,     4,     4,     0,     0,     7,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     0,     5,     0,
       5,     0,     4,     0,     5,     0,     5,     0,     4,     1,
       2,     0,     4,     1,     2,     0,     4,     1,     2,     0,
       4,     0,     4,     0,     4,     0,     6,     0,     4,     0,
       4,     1,     1,     1,     0,     4,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     0,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     0,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,    23,     0,     6,     1,     0,     0,   106,
       8,     0,    26,     0,     0,     0,     4,     7,     0,   106,
       0,     2,   108,   102,   103,   104,   105,   107,     5,    12,
       0,    24,     0,     0,    25,     0,     0,     0,     0,     0,
       0,    10,     0,     9,    13,   106,   106,   106,   106,   106,
       0,    18,    19,    21,    20,    22,    11,    14,    15,    16,
      17,    29,    45,    77,    55,    47,    49,    53,    69,    57,
      65,    71,    51,    75,    79,    73,    61,    27,    32,    33,
      35,    36,    37,    38,    34,    44,    39,    40,    41,    43,
      42,    30,    31,     0,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,     0,    67,     0,
       0,     0,     0,     0,     0,    63,     0,    28,     0,     0,
       0,    82,     0,    81,    78,    87,   106,   106,   106,     0,
       0,     0,     0,    70,    58,    60,    66,    68,    72,    52,
       0,     0,     0,    83,     0,    80,    96,   106,   106,    74,
      62,    64,    46,    94,    93,    92,    91,    88,    90,    89,
      56,    48,    50,    54,     0,   100,    99,   101,    84,    97,
      98,    76,     0,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,    10,    17,    18,    43,    33,    44,
      45,    46,    47,    48,     8,    12,    20,   108,    36,    77,
      78,    93,    79,    96,    80,    97,    81,   103,    82,    98,
      83,    95,    84,   100,   117,    85,   107,   126,    86,   101,
     119,    87,    99,    88,   102,    89,   106,    90,   104,    91,
      94,    92,   105,   134,   155,   182,   110,   135,   136,   137,
     138,   123,   156,   157,   158,    27,    14,    15
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int16 yypact[] =
{
     -17,    -8,    16,   -14,    13,   -63,   -63,     9,    15,   -63,
      -5,    19,   -63,    10,     7,   -30,   -63,   -63,    21,   -63,
     -26,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
      -3,   -63,    34,     2,   -63,    53,    11,    64,    65,    -2,
      66,   -63,    49,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     155,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   155,   -63,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   -63,   155,   155,    46,   155,
      76,   155,   155,   155,   155,    38,   -63,    95,   -63,   126,
      27,    31,   155,    12,    26,   -63,    44,   -63,    67,     0,
      83,   -63,    91,   -63,   -63,   -63,   -63,   -63,   -63,    68,
      69,    70,    71,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     155,     3,    98,   -63,   155,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,    54,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,    56,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -62,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      30,    31,    32,    53,    54,   163,   164,     1,   175,   176,
      22,     4,     7,    37,    38,    39,     6,    21,     9,    11,
      16,    28,    40,    13,    19,   151,    57,    58,    59,    60,
      61,   109,   152,   111,   112,   113,   114,   115,   116,   118,
     120,   121,   122,    29,   124,   125,    41,   128,    34,   139,
     140,   141,   142,    42,    35,   145,   153,   147,    49,    62,
     150,    63,    50,   154,   161,    23,    24,    25,    26,    51,
      52,    55,    56,   148,    64,   127,    65,   143,    66,   149,
      67,   159,    68,   162,    69,   129,    70,   165,   174,    71,
     130,    72,   178,    73,   131,   166,    74,   132,    75,   170,
      76,   160,   171,   177,   181,   172,     0,     0,   173,   183,
      62,     0,    63,     0,     0,     0,     0,   167,   168,   169,
     133,     0,     0,     0,     0,    64,     0,    65,     0,    66,
       0,    67,     0,    68,     0,    69,   144,    70,   179,   180,
      71,    62,    72,    63,    73,     0,     0,    74,     0,    75,
       0,    76,     0,     0,     0,     0,    64,     0,    65,     0,
      66,     0,    67,     0,    68,     0,    69,     0,    70,   146,
      62,    71,    63,    72,     0,    73,     0,     0,    74,     0,
      75,     0,    76,     0,     0,    64,     0,    65,     0,    66,
       0,    67,     0,    68,     0,    69,     0,    70,     0,     0,
      71,     0,    72,     0,    73,     0,     0,    74,     0,    75,
       0,    76
};

static const yytype_int16 yycheck[] =
{
      19,    27,    28,     5,     6,     5,     6,    24,     5,     6,
       3,    19,    26,    11,    12,    13,     0,     7,     5,    10,
      25,    51,    20,     8,     5,    13,    45,    46,    47,    48,
      49,    93,    20,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    22,   106,   107,    44,   109,    51,   111,
     112,   113,   114,    51,    20,   117,    44,   119,     5,    15,
     122,    17,    51,    51,   126,    58,    59,    60,    61,     5,
       5,     5,    23,    46,    30,    29,    32,    39,    34,    48,
      36,    55,    38,    16,    40,     9,    42,     4,   150,    45,
      14,    47,   154,    49,    18,     4,    52,    21,    54,    31,
      56,    57,    33,     5,    50,    35,    -1,    -1,    37,    53,
      15,    -1,    17,    -1,    -1,    -1,    -1,   136,   137,   138,
      44,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    34,
      -1,    36,    -1,    38,    -1,    40,    41,    42,   157,   158,
      45,    15,    47,    17,    49,    -1,    -1,    52,    -1,    54,
      -1,    56,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,
      34,    -1,    36,    -1,    38,    -1,    40,    -1,    42,    43,
      15,    45,    17,    47,    -1,    49,    -1,    -1,    52,    -1,
      54,    -1,    56,    -1,    -1,    30,    -1,    32,    -1,    34,
      -1,    36,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,
      45,    -1,    47,    -1,    49,    -1,    -1,    52,    -1,    54,
      -1,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    63,    64,    19,    65,     0,    26,    76,     5,
      66,    10,    77,     8,   128,   129,    25,    67,    68,     5,
      78,     7,     3,    58,    59,    60,    61,   127,    51,    22,
     129,    27,    28,    70,    51,    20,    80,    11,    12,    13,
      20,    44,    51,    69,    71,    72,    73,    74,    75,     5,
      51,     5,     5,     5,     6,     5,    23,   129,   129,   129,
     129,   129,    15,    17,    30,    32,    34,    36,    38,    40,
      42,    45,    47,    49,    52,    54,    56,    81,    82,    84,
      86,    88,    90,    92,    94,    97,   100,   103,   105,   107,
     109,   111,   113,    83,   112,    93,    85,    87,    91,   104,
      95,   101,   106,    89,   110,   114,   108,    98,    79,    81,
     118,    81,    81,    81,    81,    81,    81,    96,    81,   102,
      81,    81,    81,   123,    81,    81,    99,    29,    81,     9,
      14,    18,    21,    44,   115,   119,   120,   121,   122,    81,
      81,    81,    81,    39,    41,    81,    43,    81,    46,    48,
      81,    13,    20,    44,    51,   116,   124,   125,   126,    55,
      57,    81,    16,     5,     6,     4,     4,   129,   129,   129,
      31,    33,    35,    37,    81,     5,     6,     5,    81,   129,
     129,    50,   117,    53
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
        case 4:

    {if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > qtermcount ) osilerror("actual number of qterms less than numberOfQuadraticTerms");}
    break;

  case 5:

    {
osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms = (yyvsp[(2) - (4)].ival);  
if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > 0 ) osinstance->instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[ (yyvsp[(2) - (4)].ival) ];
for(int i = 0; i < (yyvsp[(2) - (4)].ival); i++) osinstance->instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();}
    break;

  case 8:

    {if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms <= qtermcount ) osilerror("too many QuadraticTerms");}
    break;

  case 9:

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

  case 14:

    { if(qtermidxOneattON) osilerror("too many qTerm idxOne attributes"); 
			qtermidxOneattON = true;  }
    break;

  case 15:

    { if(qtermidxTwoattON) osilerror("too many qTerm idxTwo attributes"); 
			qtermidxTwoattON = true;  }
    break;

  case 16:

    { if(qtermcoefattON) osilerror("too many qTerm coef attributes"); 
			qtermcoefattON = true;  }
    break;

  case 17:

    { if(qtermidxattON) osilerror("too many qTerm idx attributes"); 
			qtermidxattON = true;  }
    break;

  case 18:

    {  
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->idxOne = (yyvsp[(2) - (2)].ival);}
    break;

  case 19:

    { 
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->idxTwo = (yyvsp[(2) - (2)].ival);}
    break;

  case 20:

    {
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->coef = (yyvsp[(2) - (2)].dval);}
    break;

  case 21:

    { 
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->coef = (yyvsp[(2) - (2)].ival);}
    break;

  case 22:

    {  
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->idx = (yyvsp[(2) - (2)].ival);}
    break;

  case 24:

    {if(nlnodecount <  tmpnlcount)  osilerror("actual number of nl terms less than number attribute"); }
    break;

  case 25:

    {tmpnlcount = (yyvsp[(2) - (4)].ival);
osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = (yyvsp[(2) - (4)].ival);  
if(osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ (yyvsp[(2) - (4)].ival) ];
}
    break;

  case 27:

    {
	// IMPORTANT -- HERE IS WHERE WE DEFINE THE EXPRESSION TREE
	osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->osExpressionTree->m_treeRoot = 
	//osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->osExpressionTree->createExpressionTreeFromPrefix( nlNodeVec);
	//createExpressionTreeFromPrefix( nlNodeVec);
	nlNodeVec[ 0]->createExpressionTreeFromPrefix( nlNodeVec);
	nlnodecount++;
}
    break;

  case 29:

    {
osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount] = new Nl();
osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->idx = (yyvsp[(2) - (3)].ival);
osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->osExpressionTree = new OSExpressionTree();
if(nlnodecount > tmpnlcount) osilerror("actual number of nl terms greater than number attribute");
// clear the vectors of pointers
nlNodeVec.clear();
sumVec.clear();
maxVec.clear();
productVec.clear();
}
    break;

  case 45:

    {
	nlNodePoint = new OSnLNodeTimes();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 47:

    {
	nlNodePoint = new OSnLNodePlus();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 49:

    {
	nlNodePoint = new OSnLNodeMinus();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 51:

    {
	nlNodePoint = new OSnLNodeNegate();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 53:

    { 
	nlNodePoint = new OSnLNodeDivide();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 55:

    {
	nlNodePoint = new OSnLNodePower();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 57:

    {
	nlNodePoint = new OSnLNodeSum();
	nlNodeVec.push_back( nlNodePoint);
	sumVec.push_back( nlNodePoint);
}
    break;

  case 58:

    {
	sumVec.back()->m_mChildren = new OSnLNode*[ sumVec.back()->inumberOfChildren];
	sumVec.pop_back();
}
    break;

  case 59:

    {	sumVec.back()->inumberOfChildren++; }
    break;

  case 60:

    {	sumVec.back()->inumberOfChildren++; }
    break;

  case 61:

    {
	nlNodePoint = new OSnLNodeMax();
	nlNodeVec.push_back( nlNodePoint);
	maxVec.push_back( nlNodePoint);
}
    break;

  case 62:

    {
	maxVec.back()->m_mChildren = new OSnLNode*[ maxVec.back()->inumberOfChildren];
	maxVec.pop_back();
}
    break;

  case 63:

    {	maxVec.back()->inumberOfChildren++; }
    break;

  case 64:

    {	maxVec.back()->inumberOfChildren++; }
    break;

  case 65:

    {
	nlNodePoint = new OSnLNodeProduct();
	nlNodeVec.push_back( nlNodePoint);
	productVec.push_back( nlNodePoint);
}
    break;

  case 66:

    {
	productVec.back()->m_mChildren = new OSnLNode*[ productVec.back()->inumberOfChildren];
	productVec.pop_back();
}
    break;

  case 67:

    {	productVec.back()->inumberOfChildren++; }
    break;

  case 68:

    {	productVec.back()->inumberOfChildren++; }
    break;

  case 69:

    {
	nlNodePoint = new OSnLNodeLn();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 71:

    {
	nlNodePoint = new OSnLNodeExp();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 73:

    {
	nlNodePoint = new OSnLNodeAbs();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 75:

    {
	nlNodePoint = new OSnLNodeIf();
	nlNodeVec.push_back( nlNodePoint);
}
    break;

  case 77:

    {
	nlNodeNumberPoint = new OSnLNodeNumber();
	nlNodeVec.push_back( nlNodeNumberPoint);
}
    break;

  case 78:

    {numbervalueattON = false; numbertypeattON = false; numberidattON = false;}
    break;

  case 79:

    {
	nlNodeVariablePoint = new OSnLNodeVariable();
	nlNodeVec.push_back( nlNodeVariablePoint);
}
    break;

  case 80:

    {variablecoefattON = false; variableidxattON = false;}
    break;

  case 84:

    {
	//sumVec.back()->inumberOfChildren = 1;
	//sumVec.back()->m_mChildren = new OSnLNode*[ 1];
	// kipp -- fix the above doesnt seem right
	nlNodeVariablePoint->inumberOfChildren = 1;
	nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
}
    break;

  case 88:

    {if(numbertypeattON) osilerror("too many number type attributes"); 
			numbertypeattON = true; }
    break;

  case 89:

    {if(numbervalueattON) osilerror("too many number value attributes"); 
			numbervalueattON = true; }
    break;

  case 90:

    {if(numberidattON) osilerror("too many number id attributes"); 
			numberidattON = true; }
    break;

  case 91:

    {
	nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 92:

    {
	nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
}
    break;

  case 93:

    {
	nlNodeNumberPoint->value = (yyvsp[(2) - (2)].dval);
}
    break;

  case 94:

    {
	nlNodeNumberPoint->value = (yyvsp[(2) - (2)].ival);
}
    break;

  case 97:

    {if(variablecoefattON) osilerror("too many variable coef attributes"); 
			variablecoefattON = true; }
    break;

  case 98:

    {if(variableidxattON) osilerror("too many variable idx attributes"); 
			variableidxattON = true; }
    break;

  case 99:

    {
	nlNodeVariablePoint->coef = (yyvsp[(2) - (2)].dval);
}
    break;

  case 100:

    {
	nlNodeVariablePoint->coef = (yyvsp[(2) - (2)].ival);		
}
    break;

  case 101:

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


void osilerror(const char* errormsg) {
	try{
		std::ostringstream outStr;
		std::string error = errormsg;
		error = "PARSER ERROR:  Input is either not valid or well formed: "  + error;
		outStr << error << endl;
		outStr << "Here are " ;
		outStr << numErrorChar ;
		outStr << " characters currently being pointed to in the input string: ";
		outStr << errorArray;
		outStr << endl;
		outStr << "See line number: " << osillineno << endl;  
		error = outStr.str();
		throw ErrorClass( error);
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
} // end osilerror() 

OSInstance* yygetOSInstance( const char *osil) throw (ErrorClass) {
	try {
		void yyinitialize();
		yyinitialize();
		osinstance = NULL;
		osinstance = new OSInstance();
		parseInstanceHeader( &osil);
		parseInstanceData( &osil);
		// call the flex scanner
		osil_scan_string( osil);
		// call the Bison parser
		if(  osilparse(  ) != 0) throw ErrorClass(  sparseError);
		return osinstance;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
}//end yygetOSInstance

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

bool parseInstanceHeader( const char **p){
	//
	const char *pchar = *p;
	// create a char array that holds the instance header information
	const char *startInstanceHeader = "<instanceHeader";
	const char *endInstanceHeader = "</instanceHeader";
	const char *startName = "<name";
	const char *endName = "</name";
	const char *startSource = "<source";
	const char *endSource = "</source";
	const char *startDescription = "<description";
	const char *endDescription = "</description";
	const char *pinstanceHeadStart = strstr(pchar, startInstanceHeader);
	char *pelementText = NULL;
	char *ptemp = NULL;
	int elementSize;
	if(pinstanceHeadStart == NULL) {strncpy(errorArray, pchar, numErrorChar); osilerror("<instanceHeader> element missing"); return false;}
	// increment the line number counter if there are any newlines between the start of
	// the osil string and pinstanceHeadStart
	int	kount = pinstanceHeadStart - pchar;
	while( kount-- > 0) if(*(pchar++) == '\n') 	osillineno++;
	// important! pchar now points to the '<' in <instanceHeader
	// that is both pinstanceHeadStart and pchar point to the same thing
 	// 
 	// move to the end of <instanceHeader
 	pchar+=15;
	// burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;
	// pchar better be pointing to the '>' in the <instanceHeader> element
	// or to /> if we have <instanceHeader />
	if( *pchar == '/'){
		pchar++;
		// better point to a '>'
		if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <instanceHeader> element"); return false;}
		// there is no instanceHeader data
		pchar++;
		return true;
	}
	else{
		// pchar better be '>' or there is an error
		if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <instanceHeader> element"); return false;}
	}
	pchar++;
	// we are pointing to the character after <instanceHeader>
	//
	//
	//
	// process the <name> element which is optional
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;
	// if, present we should be pointing to <name element if there -- it is not required
	//remember where we are
	*p = pchar;
	while(*startName++  == *pchar) pchar++;
	if( (pchar - *p)  != 5) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a name element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <name> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <name> element"); return false;}
			pchar++;
			// proces <name> element text
			// there better be a </name
			ptemp = strstr( pchar, endName);
			if( ptemp == NULL) {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </name> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->name = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </name
			while(elementSize-- > 0){
				if(*pchar++ == '\n') osillineno++;
			}
			// pchar should now be pointing to the start of </name
			// move to first char after </name
			pchar += 6;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
			// we better have the '>' for the end of name
			if(*pchar++ != '>'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </name> element"); return false;}
		}
	}// end of else after discovering a name element
	//done processing name element
	//
	//
	// process the <source> element which is optional
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;
	// if, present we should be pointing to <source element if there -- it is not required
	*p = pchar;
	while(*startSource++  == *pchar) pchar++;
	if(pchar - *p != 7) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a source element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <source> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <source> element"); return false;}
			pchar++;
			// proces <source> element text
			// there better be a </source
			ptemp = strstr( pchar, endSource);
			if( ptemp == NULL) {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </source> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->source = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </source
			while(elementSize-- > 0){
				if(*pchar++ == '\n') osillineno++;
			}
			// pchar should now be pointing to the start of </source
			// move to first char after </source
			pchar += 8;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
			// we better have the '>' for the end of source
			if(*pchar++ != '>'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </source> element"); return false;}
		}
	}// end of else after discovering a source element
	//done processing <source> element
	//
	//
	//process the <description> element
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;
	// if, present we should be pointing to <description element if there -- it is not required
	*p = pchar;
	while(*startDescription++  == *pchar) pchar++;
	if( (pchar - *p) != 12) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a description element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <description> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <description> element"); return false;}
			pchar++;
			// proces <source> element text
			// there better be a </description
			ptemp = strstr( pchar, endDescription);
			if( ptemp == NULL) {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </description> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->description = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </description
			while(elementSize-- > 0){
				if(*pchar++ == '\n') osillineno++;
			}
			// pchar should now be pointing to the start of </description
			// move to first char after </description
			pchar += 13;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
			// we better have the '>' for the end of </description>
			if(*pchar++ != '>'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </description> element"); return false;}
		}
	}// end of else after discovering a description element
	//done processing <description> element
	//
	// if we are here there must be an </instanceHeader > element
	// burn the whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
	// we should be pointing to </instanceHeader
	*p = pchar;
	while(*endInstanceHeader++  == *pchar) pchar++;
	if( (pchar - *p) != 16) {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </instanceHeader> element"); return false;}	
	// pchar now points to the first character after </instanceHeader
	// get rid of white space
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
	// pchar must point to '>' or there is an error
	if(*pchar != '>'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </instanceHeader> element"); return false;}	
	pchar++;
	*p = pchar;
	return true;
}//end parseInstanceHeader


bool parseInstanceData( const char **p){
	//
	const char *pchar = *p;
	const char *startInstanceData = "<instanceData";
	// at his point *pchar should be pointing to the first char after the > in </instanceHeader>
	// burn the white space
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
	// pchar should be point to a '<', if not there is an error
	if(*pchar != '<'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <instanceData element"); return false;}
	// make sure the element is <instanceData	
	*p = pchar;
	while(*startInstanceData++  == *pchar) pchar++;
	if( (pchar - *p) != 13) {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <instanceData> element"); return false;}	
	// now burn whitespace
	// pchar must point to '>' or there is an error
	if(*pchar != '>'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <instanceData> element"); return false;}	
	pchar++;
	// we are now pointing to the first char after <instanceData>
	// burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
	// we should be pointing to the '<' char in <varaibles>
	*p = pchar;
	if( parseVariables( p) != true) {throw ErrorClass("error in parse variables");}
	if( parseObjectives( p) != true)  throw ErrorClass("error in parse objectives");
	if( parseConstraints( p) != true) throw ErrorClass("error in parse Constraints");
	if( parseLinearConstraintCoefficients( p) != true) throw ErrorClass("error in parse ConstraintCoefficients");	
	//
	return true;
}// end parseInstanceData


bool parseVariables( const char **p){
	const char *ch = *p;
	start = clock(); 
	const char *c_numberOfVariables = "numberOfVariables";
	const char *startVariables = "<variables";
	const char *endVariables = "</variables";
	const char *startVar = "<var";
	const char *endVar = "</var";
	// the attributes
	char *attText = NULL;
	const char *name = "name";
	const char *initString = "initString";
	const char *type = "type";
	const char *mult = "mult";
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
	*p = ch;
	while(*startVariables++  == *ch) ch++;
	if( (ch - *p) != 10) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect <variables tag>"); return false;}
	// find numberOfVariables attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	*p = ch;
	while(*c_numberOfVariables++  == *ch) ch++;
	if( (ch - *p) != 17) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect numberOfVariables attribute in <variables tag>"); return false;}	
	// buf_index should be pointing to the first character after numberOfVariables
	GETATTRIBUTETEXT;
	ch++;
	numberOfVariables = atoimod1( attText, attTextEnd);
	delete [] attText;
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
	if(*ch != '>' ) {strncpy(errorArray, ch, numErrorChar); osilerror("variables element does not have a proper closing >"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the var elements, there must be at least one var element
	*p = ch;                                            
	while(*startVar++  == *ch) ch++;
	if( (ch - *p) ==  4) foundVar = true;
		else {strncpy(errorArray, ch, numErrorChar); osilerror("there must be at least one <var> element"); return false;}
	startVar -= 5;
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
				*p = ch;
				while(*name++  == *ch) ch++;
				if( (ch - *p) != 4 ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables name attribute"); return false;}
				name -= 5;
				if(varnameattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable name attributes"); return false;}
				varnameattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->name=attText;
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'i':
				*p = ch;
				while(*initString++  == *ch) ch++;
				// if i < 4 there is an error
				// if i = 4 we matched init
				// if i = 10 we matched initString
				if( ( (ch - *p) != 4)  && (i != 10)) {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables init or initString attribute"); return false;}
				if((ch - *p) == 4){
					if(varinitattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable init attributes"); return false;}
					varinitattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->init=atofmod1(attText, attTextEnd);
					delete [] attText;
					initString -= 5;
				}
				else{
					if(varinitStringattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable initString attributes"); return false;}
					varinitStringattON = true;
					GETATTRIBUTETEXT;
					delete [] attText;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->initString=attText;
					initString -= 11;
				}
				break;
			case 't':
				*p = ch;
				while(*type++  == *ch) ch++;
				if( (ch - *p) != 4) {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables type attribute"); return false;}
				type -= 5;
				if(vartypeattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable type attributes"); return false;}
				vartypeattON = true;
				GETATTRIBUTETEXT;
				if( strchr("CBIS", attText[0]) == NULL ) {strncpy(errorArray, ch, numErrorChar); osilerror("variable type not C,B,I, or S"); return false;}
				osinstance->instanceData->variables->var[varcount]->type = attText[0];
				delete [] attText;
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables lower bound attribute"); return false;}
				if(varlbattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable lb attributes"); return false;}
				varlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->lb = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables upper bound attribute"); return false;}
				if(varubattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable ub attributes"); return false;}
				varubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->ub = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				*p = ch;
				while(*mult++  == *ch) ch++;
				if( (ch - *p) != 4) {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables mult attribute"); return false;}
				mult -= 5;
				if(varmultattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable mult attributes"); return false;}
				varmultattON = true;
				GETATTRIBUTETEXT;
				delete [] attText;
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
				{strncpy(errorArray, ch, numErrorChar); osilerror("invalid attribute character"); return false;}
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </var whitespace>
		if( *ch != '/' && *ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect end of <var> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect end of <var> element"); return false;}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <var> element or foundVar = false;
			*p = ch;
			while(*startVar++  == *ch) ch++;
			if( (ch - *p) == 4) {
				foundVar = true;
				startVar -= 5;
			}
			else {
				foundVar = false;
				ch = *p;
			}
		}
		else{
			// the buf_index is the > at the end of the var element 
			// double check to make sure it really is a >
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improper ending to a <var> element"); return false;}
			// look for </var
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </var or there is an error
			*p = ch;
			while(*endVar++  == *ch) ch++;
			endVar -= 6;
			if( (ch - *p) != 5) {strncpy(errorArray, ch, numErrorChar); osilerror("</var> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </var
			if(*ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("</var> element missing >"); return false;}
			// look for a new <var> element
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <var> element or foundVar = false;
			*p = ch;
			while(*startVar++  == *ch) ch++;
			if( (ch - *p) == 4) {
				foundVar = true;
				startVar -= 5;
			}
			else {
				foundVar = false;
				ch = *p;
			}
		}
		if( (varcount == numberOfVariables - 1) && (foundVar == true) ) {strncpy(errorArray, ch, numErrorChar);  osilerror("attribute numberOfVariables is less than actual number found");  return false;}
		varcount++;
	}
	if(varcount < numberOfVariables) {strncpy(errorArray, ch, numErrorChar); osilerror("attribute numberOfVariables is greater than actual number found");   return false;}
	// get the </variables> tag
	*p = ch;
	while(*endVariables++  == *ch) ch++;
	if( (ch - *p) != 11) {strncpy(errorArray, ch, numErrorChar);  osilerror("cannot find </varialbes> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar);  osilerror("improperly formed </variables> tag"); return false;}
	ch++;
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE VARIABLES = %f\n", duration);
	*p = ch;
	return true;
}//end parseVariables


bool parseObjectives( const char **p){
	const char *ch = *p;
	start = clock();
	const char *c_numberOfObjectives = "numberOfObjectives";
	const char *startObjectives = "<objectives";
	const char *endObjectives = "</objectives";
	const char *startObj = "<obj";
	const char *endObj = "</obj";
	// attributes
	char *attText = NULL;
	const char *constant = "constant";
	const char *maxOrMin = "maxOrMin";
	const char *numberOfObjCoef = "numberOfObjCoeff";
	const char *weight = "weight";
	const char *name = "name";
	const char *mult = "mult";
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
	*p = ch;
	while( *startObjectives++  == *ch) ch++;
	if( (ch - *p) != 11) {
		//  note if we are here even though ch > *p we want to return *p
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
		*p = ch;
		while( *c_numberOfObjectives++  == *ch) ch++;
		if( (ch - *p) != 18) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect numberOfObjectives attribute in <objectives> tag"); return false;}	
		GETATTRIBUTETEXT;
		numberOfObjectives = atoimod1( attText, attTextEnd);
		delete [] attText;
		ch++;
	}
	if(numberOfObjectives > 0){
		// get rid of white space after the numberOfObjectives attribute
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// we must have an >
		/*if(*ch == '/'){
			ch++;
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("the objectives element does not have a proper closing"); return false; }
			else{
				if(numberOfObjectives > 0){strncpy(errorArray, ch, numErrorChar);  osilerror("numberOfObjectives positive but there are no objectives"); return false;}
				return false;
			}
		}*/
		//  we better have an > 
		if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("the objectives element does not have a proper closing"); return false;} 
		osinstance->instanceData->objectives->numberOfObjectives = numberOfObjectives;
		osinstance->instanceData->objectives->obj = new Objective*[ numberOfObjectives];
		for(i = 0; i < numberOfObjectives; i++){
			osinstance->instanceData->objectives->obj[ i] = new Objective();
		} 	
	// get rid of white space after the <objectives> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the obj elements, there must be at least one obj element
	*p = ch;
	while( *startObj++  == *ch) ch++;
	if( (ch - *p) == 4) foundObj = true;
		else {strncpy(errorArray, ch, numErrorChar); osilerror("there must be at least one <obj> element"); return false;}
	startObj -= 5;
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
					*p = ch;
					while( *numberOfObjCoef++  == *ch) ch++;
					numberOfObjCoef -= 16;
					if( ( (ch - *p) != 15)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective numberOfObjCoef attribute"); return false;}
					else{
						if(objnumberOfObjCoefattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj numberOfObjCoefatt attributes"); return false;}
						objnumberOfObjCoefattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef=atoimod1(attText, attTextEnd);
						osinstance->instanceData->objectives->obj[objcount]->coef = new ObjCoef*[osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef];
						for(int i = 0; i < osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef; i++)osinstance->instanceData->objectives->obj[objcount]->coef[i] = new ObjCoef();
						delete [] attText;
					}
				}
				else{
					*p = ch;
					while( *name++  == *ch) ch++;
					name -= 5;
					if( ( (ch - *p) != 4)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective name attribute"); return false;}
					else{
						if(objnameattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj name attributes"); return false;}
						objnameattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->objectives->obj[objcount]->name=attText;
						delete [] attText;
					}
				}
				break;
			case 'c':
				*p = ch;
				while( *constant++  == *ch) ch++;
				constant -= 9;	
				if( ( (ch - *p) != 8)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective constant attribute"); return false;}
				else{
					if(objconstantattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj constant attributes"); return false;}
					objconstantattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->constant=atofmod1(attText, attTextEnd);
					delete [] attText;
				}
				break;
			case 'w':
				*p = ch;
				while( *weight++  == *ch) ch++;
				weight -= 7;
				if( ( (ch - *p) != 6)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective weight attribute"); return false;}
				else{
					if(objweightattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj weight attributes"); return false;}
					objweightattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->weight=atofmod1(attText, attTextEnd);
					delete [] attText;
				}
				break;
			case 'm':
				if(*(ch+1) == 'a'){
					*p = ch;
					while( *maxOrMin++  == *ch) ch++;
					maxOrMin -= 9;
					if( ( ( ch - *p)  != 8)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective maxOrMin attribute"); return false;}
					else{
						if(objmaxOrMinattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj maxOrMin attributes"); return false;}
						objmaxOrMinattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						if( (strcmp("max", attText) != 0 ) && (strcmp("min", attText) != 0 ) ){osilerror("maxOrMin attribute in objective must be a max or min"); return false;}
						osinstance->instanceData->objectives->obj[objcount]->maxOrMin = attText;
						delete [] attText;
					}
				}
				else{
					*p = ch;
					while( *mult++  == *ch) ch++;
					mult -= 5;
					if( ( (ch - *p) != 4)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective mult attribute"); return false;}
					else{
						if(objmultattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj mult attributes"); return false;}
						objmultattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						//osinstance->instanceData->objectives->obj[objcount]->name=attText;
						delete [] attText;
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
				strncpy(errorArray, ch, numErrorChar);
				osilerror("invalid attribute character");
				return false;
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </obj whitespace>
		if( *ch != '/' && *ch != '>') {strncpy(errorArray, ch, numErrorChar);  osilerror("incorrect end of <obj> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect end of <obj> element"); return false;}
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
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improper ending to a <obj> element"); return false;}
			// look for </obj
			// fist get rid of white space
			ch++;
			// first get the <coef> elements
			parseObjCoef(&ch,  objcount);
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </obj or there is an error
			for(i = 0; endObj[i]  == *ch; i++, ch++);
			if(i != 5) {strncpy(errorArray, ch, numErrorChar); osilerror("</obj> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </obj
			if(*ch++ != '>'){strncpy(errorArray, ch, numErrorChar);  osilerror("</obj> element missing >"); return false;}
			// look for a new <obj> element
			// get rid of whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <obj> element or foundObj = false;
			for(i = 0; startObj[i]  == *ch; i++, ch++);
			if(i == 4) foundObj = true;
				else foundObj = false;
		}
		if( (objcount == numberOfObjectives - 1) && (foundObj == true)) {strncpy(errorArray, ch, numErrorChar); osilerror("attribute numberOfObjectives is less than actual number found"); return false;}
		objcount++;
	}
	if(objcount < numberOfObjectives) {strncpy(errorArray, ch, numErrorChar); osilerror("attribute numberOfObjectives is greater than actual number found"); return false;}
	ch -= i;
	// get the </objectives> tag
	for(i = 0; endObjectives[i]  == *ch; i++, ch++);
	if(i != 12) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </objectives> tag"); return false; }
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </objectives> tag"); return false;}	
	ch++;
	} // finish the (if numberOfObjectives > 0)
	else{
		// error if the number is negative
		if(numberOfObjectives < 0) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot have a negative number of objectives"); return false;}
		// if we are here we have exactly 0 objectives 
		// must close with /> or </objectives>
		// get rid of white space
		for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		if( *ch == '/'){
			// better have a >
			ch++;
			if( *ch  != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly closed objectives tag"); return false;}
			ch++;
		}
		else{
			// if we are here we must have an '>' and then  </objectives> tag
			if( *ch  != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly closed objectives tag"); return false;}
			ch++;
			// burn white space
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			for(i = 0; endObjectives[i]  == *ch; i++, ch++);
			if(i != 12) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </objectives> tag"); return false; }
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
			// better have >
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </objectives> tag"); return false;}	
			ch++;
		}
	}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE OBJECTIVES = %f\n", duration);
	*p = ch;
	return true;
}//end parseObjectives

bool parseConstraints( const char **p){
	const char *ch = *p;
	start = clock();	
	const char *c_numberOfConstraints = "numberOfConstraints";
	const char *startConstraints = "<constraints";
	const char *endConstraints = "</constraints";
	const char *startCon = "<con";
	const char *endCon = "</con";
	// attributes
	char *attText = NULL;
	const char *name = "name";
	const char *constant = "constant";
	const char *mult = "mult";
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
	*p = ch;
	for(i = 0; startConstraints[i]  == *ch; i++, ch++);
	while( *startConstraints++  == *ch) ch++;
	if( (ch - *p) != 12) {
		//  *p is the correct value for the pointer
		return true;
	}
	// find numberOfConstraints attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	*p = ch;
	while( *c_numberOfConstraints++  == *ch) ch++;
	if( (ch - *p) != 19) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect numberOfConstraints attribute in <constraints> tag"); return false;}	
	// ch should be pointing to the first character after numberOfObjectives
	GETATTRIBUTETEXT;
	ch++;
	numberOfConstraints = atoimod1( attText, attTextEnd);
	delete [] attText;
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
	if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar);  osilerror("the constraints element does not have a proper closing"); return false;} 
	// get rid of white space after the <constraints> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the con elements, there must be at least one con element
	*p = ch;
	while( *startCon++  == *ch) ch++;
	if( (ch - *p) == 4) foundCon = true;
		else {strncpy(errorArray, ch, numErrorChar); osilerror("there must be at least one <con> element"); return false;}
	startCon -= 5;
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
				*p = ch;
				while( *name++  == *ch) ch++;
				if( (ch - *p) != 4) {strncpy(errorArray, ch, numErrorChar); osilerror("error in constraints name attribute"); return false;}
				if(connameattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many con name attributes"); return false;}
				name -= 5;
				connameattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->name=attText;
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'c':
				*p = ch;
				while( *constant++  == *ch) ch++;
				if( ((ch - *p)  != 8)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in constraint constant attribute"); return false;}
				if(conconstantattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many con constant attributes"); return false;}
				constant -= 9;
				conconstantattON = true;
				GETATTRIBUTETEXT;
				//printf("ATTRIBUTE = %s\n", attText);
				osinstance->instanceData->constraints->con[concount]->constant=atofmod1(attText, attTextEnd);
				delete [] attText;
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') { strncpy(errorArray, ch, numErrorChar); osilerror("error in constraint lb attribute"); return false;}
				if(conlbattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many con lb attributes"); return false;}
				conlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->lb = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {strncpy(errorArray, ch, numErrorChar); osilerror("error in constraint ub attribute"); return false;}
				if(conubattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many con ub attributes"); return false;}
				conubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->ub = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				*p = ch;
				while( *mult++  == *ch) ch++;
				if( (ch - *p) != 4) {strncpy(errorArray, ch, numErrorChar); osilerror("error in constraints mult attribute"); return false;}
				if(conmultattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many con mult attributes"); return false;}
				mult -= 5;
				conmultattON = true;
				GETATTRIBUTETEXT;
				delete [] attText;
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
				strncpy(errorArray, ch, numErrorChar);
				osilerror("invalid attribute character");
				return false;
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </con whitespace>
		if( *ch != '/' && *ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect end of <con> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect end of <con> element"); return false;}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <con> element or foundCon = false;
			*p = ch;
			while( *startCon++  == *ch) ch++;
			if( (ch - *p) == 4){
			 	foundCon = true;
			 	startCon -= 5;
			}
			else{
				foundCon = false;
				ch = *p;
			}
		}
		else{
			// the ch is the > at the end of the con element 
			// double check to make sure it really is a >
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improper ending to a <obj> element"); return false;}
			// look for </con
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </con or there is an error
			*p = ch;
			while( *endCon++  == *ch) ch++;
			if( (ch - *p) != 5) {strncpy(errorArray, ch, numErrorChar); osilerror("</con> element missing"); return false;}
			endCon -= 6;
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </con
			if(*ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("</con> element missing >"); return false;}
			// look for a new <con> element
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <con> element or foundVar = false;
			*p = ch;
			while( *startCon++  == *ch) ch++;
			if( (ch - *p) == 4){
			 	foundCon = true;
			 	startCon -= 5;
			}
			else{
			 	foundCon = false;
			 	ch = *p;
			}
		}
		if( (concount == numberOfConstraints - 1) && (foundCon == true) ) {strncpy(errorArray, ch, numErrorChar); osilerror("attribute numberOfConstraints is less than actual number found"); return false;}
		concount++;
	}
	if(concount < numberOfConstraints) {strncpy(errorArray, ch, numErrorChar); osilerror("attribute numberOfConstraints is greater than actual number found"); return false;}
	// get the </constraints> tag
	*p = ch;
	while( *endConstraints++  == *ch) ch++;
	if( (ch - *p) != 13) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </constraints> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </constraints> tag");	return false;}
	ch++;
	}// end if(numberOfConstraints > 0)
	else{
		// error if the number is negative
		if(numberOfConstraints < 0) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot have a negative number of constraints"); return false;}
		// if we are here we have numberOfConstraints = 0
		// must close with /> or </constraints>
		// get rid of white space
		for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		if( *ch == '/'){
			// better have a >
			ch++;
			if( *ch  != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly closed constraints tag"); return false;}
			ch++;
		}
		else{
			// if we are here we must have an '>' and then  </constraints> tag
			if( *ch  != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly closed constraints tag"); return false;}
			ch++;
			// burn white space
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			*p = ch;
			while( *endConstraints++  == *ch) ch++;
			if( (ch - *p) != 13) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </constraints> tag"); return false; }
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
			// better have >
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </constraints> tag"); return false;}	
			ch++;
		}
	}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE CONSTRAINTS = %f\n", duration);
	*p = ch;
	return true;
}//end parseConstraints

bool parseLinearConstraintCoefficients( const char **p){
	const char *ch = *p;
	start = clock();	
	const char *c_numberOfValues = "numberOfValues";
	const char *startlinearConstraintCoefficients = "<linearConstraintCoefficients";
	const char *endlinearConstraintCoefficients = "</linearConstraintCoefficients";
	// attributes
	char *attText = NULL;
	// others
	int numberOfValues;
	// start parsing
	// burn white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <linearConstraintCoefficients element if there -- it is not required
	*p = ch;
	while( *startlinearConstraintCoefficients++  == *ch) ch++;
	if( (ch - *p) != 29) {
		//reset ch
		ch = *p;
		return true;
	}
	// find numberOfValues attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	*p = ch;
	while( *c_numberOfValues++  == *ch) ch++;
	if( (ch - *p) != 14) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect numberOfValues attribute in <linearConstraintCoefficients> tag"); return false;}
	// ch should be pointing to the first character after numberOfObjectives
	GETATTRIBUTETEXT;
	ch++;
	numberOfValues = atoimod1( attText, attTextEnd);
	delete [] attText;
	if(numberOfValues <= 0) {strncpy(errorArray, ch, numErrorChar); osilerror("the number of nonlinear nozeros must be positive"); return false;}
	osinstance->instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
	// get rid of white space after the numberOfConstraints element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an />  OR an >
	if(*ch == '/'){
		ch++;
		if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("the linearConstraintCoefficients element does not have a proper closing"); return false;} 
		else{
			if(numberOfValues > 0) {strncpy(errorArray, ch, numErrorChar); osilerror("numberOfValues positive, but there are no objectives"); return false;}
			return false;
		}		
	}
	//  we better have an > 
	if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("the <linearConstraintCoefficients> element does not have a proper closing"); return false;}
	// get rid of white space after the <linearConstraintCoefficients> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	if( parseStart( &ch) != true) return false;
	if( (parseColIdx( &ch) != true) && ( parseRowIdx( &ch) != true)) return false;
	if( (parseColIdx( &ch) != true) && (parseRowIdx( &ch) == true) ){strncpy(errorArray, ch, numErrorChar); osilerror("cannot store by both row and column"); return false;}
	if( parseValue( &ch) != true) return false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// get the </linearConstraintCoefficients> tag
	*p = ch;
	while( *endlinearConstraintCoefficients++  == *ch) ch++;
	if( (ch - *p) != 30) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </linearConstraintCoefficients> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </linearConstraintCoefficients> tag"); return false;}
	ch++;	
	*p = ch;
	return true;
}//end parseLinearConstraintCoefficients

bool parseStart(const char **p){
	const char *ch = *p;
	start = clock(); 
	const char* startStart = "<start";
	const char* endStart = "</start";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <start element 
	*p = ch;
	while( *startStart++  == *ch) ch++;
	if( (ch - *p) != 6) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <start
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <start> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize );
		if( b64string == NULL) {strncpy(errorArray, ch, numErrorChar); osilerror("<start> must have children or base64 data"); return false;}
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		int *intvec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->start->el = new int[(base64decodeddatalength/dataSize) ];
		intvec = (int*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->start->el[ i] = *(intvec++);
		}
		delete [] b64string;
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->start->el = 
		new int[ std::max( osinstance->instanceData->constraints->numberOfConstraints,
		osinstance->instanceData->variables->numberOfVariables) + 1];
		while(foundEl){
			// start eating white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// okay we better have a number, we will check later
			*p = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {strncpy(errorArray, ch, numErrorChar); osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->start->el[ kount++] = 
			atoimod1( *p, ch);
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p) != 4 ) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p)  == 3){
				 foundEl = true;
				 startEl -= 4;
			}
			else{
			 	foundEl = false;
			 	ch = *p;
			}
		}		
	}
	// get the </start> tag
	*p = ch;
	while( *endStart++  == *ch) ch++;
	if( (ch - *p) != 7) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </start> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </start> tag");	return false;}
	ch++;	
	// get the end element
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE STARTS  = %f\n", duration);
	*p = ch;
	return true;
}//end parseSart

bool parseRowIdx( const char **p){
	const char *ch = *p;
	start = clock(); 
	const char* startRowIdx = "<rowIdx";
	const char* endRowIdx = "</rowIdx";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <rowIdx element 
	*p = ch;
	while( *startRowIdx++  == *ch) ch++;
	if( (ch - *p) != 7) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <rowIdx
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <rowIdx> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize );
		if( b64string == NULL)  {strncpy(errorArray, ch, numErrorChar); osilerror("<rowIdx> must have children or base64 data"); return false;}
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
		delete [] b64string;
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
		while(foundEl){
			// start munging white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <el> tag"); return false;}
			// mung white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			// okay we better have a number, we will check later
			*p = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {strncpy(errorArray, ch, numErrorChar);  osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ kount++] = 
			atoimod1( *p, ch);
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p)  != 4 ) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot find an </el>"); return false;}
			// start munging white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p) == 3){
				foundEl = true;
				startEl -= 4;
			}
			else{
				foundEl = false;
				ch = *p;
			}
		}
	}
	// get the </rowIdx> tag
	*p = ch;
	while( *endRowIdx++  == *ch) ch++;
	if( (ch - *p) != 8) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </rowIdx> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </rowIdx> tag");}	
	ch++;	
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror("numberOfLinearCoefficients attribute less than number of row indices found"); return false;}
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror("numberOfLinearCoefficients attribute greater than number of row indices found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE ROW INDEXES = %f\n", duration);
	*p = ch;
 	return true;
}//end parseRowIdx


bool parseColIdx( const char **p){
	const char *ch = *p;
	start = clock(); 
	const char* startColIdx = "<colIdx";
	const char* endColIdx = "</colIdx";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <colIdx element 
	*p = ch;
	while( *startColIdx++  == *ch) ch++;
	if( (ch - *p) != 7) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <colIdx
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <colIdx> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize );
		if( b64string == NULL)  {strncpy(errorArray, ch, numErrorChar); osilerror("<colIdx> must have children or base64 data"); return false;}
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
		delete [] b64string;
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
		while(foundEl){
			// start eating white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			// okay we better have a number, we will check later
			*p = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {strncpy(errorArray, ch, numErrorChar); osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount++] = 
			atoimod1( *p, ch);
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p) != 4 ) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p) == 3){
			 	foundEl = true;
			 	startEl -= 4;
			}
			else{
			 	foundEl = false;
			 	ch = *p;
			}
		}
	}
	// get the </colIdx> tag
	*p = ch;
	while( *endColIdx++  == *ch) ch++;		
	if( (ch - *p) != 8) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </colIdx> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </colIdx> tag"); return false;}	
	ch++;	
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {strncpy(errorArray, ch, numErrorChar); osilerror("numberOfLinearCoefficients attribute less than number of column indices found"); return false;}
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {strncpy(errorArray, ch, numErrorChar); osilerror("numberOfLinearCoefficients attribute greater than number of column indices found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE COLUMN INDEXES = %f\n", duration);
	*p = ch;
 	return true;
}//end parseColIdx


bool parseValue( const char **p){
	const char *ch = *p;
	start = clock(); 
	const char* startValue = "<value";
	const char* endValue = "</value";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
	// if present we should be pointing to <value element 
	*p = ch;
	while( *startValue++  == *ch) ch++;
	if( (ch - *p) != 6) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <value
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
	// we should have either an >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <value> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize );
		if( b64string == NULL)  {strncpy(errorArray, ch, numErrorChar); osilerror("<start> must have children or base64 data"); return false;};
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		double *doublevec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->value->el = new double[(base64decodeddatalength/dataSize) ];
		doublevec = (double*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->value->el[ i] = *(doublevec++);
			kount++;
		}
		delete [] b64string;
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->value->el = 
			new double[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		while( foundEl){
			// start eat white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ );
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
			*p = ch;
			// find the end of the number, it better be an </el>
			// find the < which begins the </el
			while( *ch != '<' && *ch != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {strncpy(errorArray, ch, numErrorChar); osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->value->el[ kount++] = 
			atofmod1( *p, ch);
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p) != 4 ) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ );
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p) == 3){
			 	foundEl = true;
			 	startEl -= 4;
			}
			else{
				foundEl = false;
				ch = *p;
			}
		}	
	}
	// get the </value> tag
	*p = ch;
	while( *endValue++  == *ch) ch++;
	if( (ch - *p) != 7) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </value> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </value> tag");	 return false;}
	ch++;	
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues){strncpy(errorArray, ch, numErrorChar); osilerror("numberOfLinearCoefficients greater than number of values found"); return false;}
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues){strncpy(errorArray, ch, numErrorChar); osilerror("numberOfLinearCoefficients less than the number of values found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE VALUES = %f\n", duration);
	*p = ch;
	return true;
}//end parseValue

bool parseObjCoef( const char **p, int objcount){
	const char *ch = *p;
	const char* startCoef = "<coef";
	const char* endCoef = "</coef";
	const char* c_idx = "idx";
	char *attText = NULL;
	int k;
	int numberOfObjCoef = 0; 
	if( osinstance->instanceData->objectives->numberOfObjectives <= 0)  {strncpy(errorArray, ch, numErrorChar); osilerror("we can't have objective function coefficients without an objective function"); return false;}
	numberOfObjCoef = osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef;
	if(numberOfObjCoef > 0)	{
	for(k = 0; k < numberOfObjCoef; k++){
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if, present we should be pointing to <coef element 
		*p = ch;
		while( *startCoef++  == *ch) ch++;
		if( (ch - *p) != 5) {strncpy(errorArray, ch, numErrorChar); osilerror("improper <coef> element"); return false;}
		startCoef -= 6;
		// get the idx attribute
		// eat the white space after <coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		*p = ch;
		while( *c_idx++  == *ch) ch++;
		if( (ch - *p) != 3) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect idx attribute in objective function <idx> tag"); return false;}	
		c_idx -= 4;
		// ch should be pointing to the first character after idx attribute
		GETATTRIBUTETEXT;
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->idx  = atoimod1( attText, attTextEnd);
		delete [] attText;
		ch++;	
		// eat white space
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect <coef> element")	; return false;}	
		// we should be pointing to first character after <coef>
		*p = ch;
		// eat characters until we find <
		for(; *ch != '<' && *ch != EOF; ch++); 
		// put back here

		// we should be pointing to a < in the </coef> tag	
		if(*ch != '<') {strncpy(errorArray, ch, numErrorChar); osilerror("improper </coef> tag"); return false;}
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->value  = atofmod1( *p, ch);
		*p = ch;
		while( *endCoef++  == *ch) ch++;
		if( (ch - *p) != 6)  {strncpy(errorArray, ch, numErrorChar); osilerror("improper </coef> element"); return false;}
		endCoef -= 7;
		// get rid of white space after </coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect </coef> element")	; return false;}
	}
	}// end if(numberOfObjCoef > 0)
	*p = ch;
	return true;
}//end parseObjCoef

char *parseBase64(const char **p, int *dataSize ){
	const char *ch = *p;
	const char *sizeOf = "sizeOf";
	//char *numericType = "numericType";
	const char *startBase64BinaryData = "<base64BinaryData";
	const char *endBase64BinaryData = "</base64BinaryData";
	char *attText = NULL;
	char *b64string = NULL;
	int i;
	// start parsing
	for(i = 0; startBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 17) {
		ch -= i;
		*p = ch;
		return b64string;
	}
	// find sizeOf attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; sizeOf[i]  == *ch; i++, ch++);
	if(i != 6) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect sizeOf attribute in <base64BinaryData> element"); return false;}	
	// ch should be pointing to the first character after sizeOf
	GETATTRIBUTETEXT;
	ch++;
	*dataSize = atoimod1( attText, attTextEnd);
	delete [] attText;
	// since the element must contain b64 data,  this element must end with > 
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {strncpy(errorArray, ch, numErrorChar); osilerror("<base64BinaryData> element does not have a proper closing >"); return false;}
	ch++;
	// we are now pointing start of the data
	const char *b64textstart = ch;
	// eat characters until we get to the </base64BinaryData element
	for(; *ch != '<' && *ch != EOF; ch++);
	const char *b64textend = ch;
	// we should be pointing to </base64BinaryData>
	for(i = 0; endBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 18) {strncpy(errorArray, ch, numErrorChar);osilerror(" problem with <base64BinaryData> element"); return false;}
	int b64len = b64textend - b64textstart;
	b64string = new char[ b64len + 1]; 
	for(ki = 0; ki < b64len; ki++) b64string[ki] = b64textstart[ ki]; 
	b64string[ki] = '\0';	
	// burn the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {strncpy(errorArray, ch, numErrorChar); osilerror("</base64BinaryData> element does not have a proper closing >"); return false;}
	ch++;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	*p = ch;
	return b64string;
}





double atofmod1(const char *number, const char *numberend){
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
				strncpy(errorArray, number, numErrorChar); 
				osilerror( "error in parsing an XSD:double");
			}
		case 'N':
			i++;
			if(number[ i-2] != '+' &&  number[ i-2] != '-' && number[ i++] == 'a' && number[i++] == 'N'){
				val = OSNAN;
				break;
			}
			else{
				strncpy(errorArray, number, numErrorChar); 
				osilerror( "error in parsing an XSD:double");
				
			}

		default:
			strncpy(errorArray, number, numErrorChar); 
			osilerror( "error in parsing an XSD:double");
			
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
			if(i == exptest) {strncpy(errorArray, number, numErrorChar); osilerror( "error in parsing an XSD:double"); 	}
			val = val*pow(10, expsign*exppower);
			//printf("number = %f\n", val);
		}
	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	if(number[i] == *numberend){
		return sign*val;
	}
	else {strncpy(errorArray, number, numErrorChar); osilerror("error in parsing an XSD:double"); 	return OSNAN;}
}//end atofmod



int atoimod1(const char *number, const char *numberend){
	// modidfied atoi from Kernighan and Ritchie
	int ival;
	int i, sign;
	int endWhiteSpace;
	for(i = 0; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	endWhiteSpace = i;
	sign = (number[ i] == '-') ? -1 : 1;
	if (number[ i] == '+' || number[ i] == '-') i++;
	for(ival = 0; ISDIGIT( number[ i]); i++){
		ival = 10*ival + (number[ i] - '0') ;
	}
	if(i == endWhiteSpace) {strncpy(errorArray, number, numErrorChar); osilerror( "error in parsing an XSD:int" ); 	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	if(number[i] == *numberend){
		return sign*ival;
	}
	else {strncpy(errorArray, number, numErrorChar); osilerror( "error in parsing an XSD:int"); return OSINT_MAX;	}
}//end atoimod1



