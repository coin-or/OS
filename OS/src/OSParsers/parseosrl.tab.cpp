/* A Bison parser, made by GNU Bison 1.875c.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
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
     RESULTDATASTART = 282,
     RESULTDATAEND = 283,
     RESULTDATASTARTANDEND = 284,
     OPTIMIZATIONSTART = 285,
     OPTIMIZATIONEND = 286,
     SOLUTIONSTART = 287,
     SOLUTIONEND = 288,
     VALUESSTART = 289,
     VALUESEND = 290,
     DUALVALUESSTART = 291,
     DUALVALUESEND = 292,
     VARIABLESSTART = 293,
     VARIABLESEND = 294,
     VARSTART = 295,
     VAREND = 296,
     OBJECTIVESSTART = 297,
     OBJECTIVESEND = 298,
     OBJSTART = 299,
     OBJEND = 300,
     CONSTRAINTSSTART = 301,
     CONSTRAINTSEND = 302,
     CONSTART = 303,
     CONEND = 304,
     STATUSSTART = 305,
     STATUSEND = 306,
     GENERALSTATUSSTART = 307,
     GENERALSTATUSEND = 308,
     MESSAGESTART = 309,
     MESSAGEEND = 310,
     MESSAGESTARTANDEND = 311,
     OTHERSTART = 312,
     OTHEREND = 313,
     NUMBEROFSOLUTIONSATT = 314,
     NUMBEROFVARIABLESATT = 315,
     NUMBEROFCONSTRAINTSATT = 316,
     NUMBEROFOBJECTIVESATT = 317,
     OBJECTIVEIDXATT = 318,
     IDXATT = 319,
     TYPEATT = 320,
     DESCRIPTIONATT = 321,
     NAMEATT = 322,
     DUMMY = 323
   };
#endif
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
#define RESULTDATASTART 282
#define RESULTDATAEND 283
#define RESULTDATASTARTANDEND 284
#define OPTIMIZATIONSTART 285
#define OPTIMIZATIONEND 286
#define SOLUTIONSTART 287
#define SOLUTIONEND 288
#define VALUESSTART 289
#define VALUESEND 290
#define DUALVALUESSTART 291
#define DUALVALUESEND 292
#define VARIABLESSTART 293
#define VARIABLESEND 294
#define VARSTART 295
#define VAREND 296
#define OBJECTIVESSTART 297
#define OBJECTIVESEND 298
#define OBJSTART 299
#define OBJEND 300
#define CONSTRAINTSSTART 301
#define CONSTRAINTSEND 302
#define CONSTART 303
#define CONEND 304
#define STATUSSTART 305
#define STATUSEND 306
#define GENERALSTATUSSTART 307
#define GENERALSTATUSEND 308
#define MESSAGESTART 309
#define MESSAGEEND 310
#define MESSAGESTARTANDEND 311
#define OTHERSTART 312
#define OTHEREND 313
#define NUMBEROFSOLUTIONSATT 314
#define NUMBEROFVARIABLESATT 315
#define NUMBEROFCONSTRAINTSATT 316
#define NUMBEROFOBJECTIVESATT 317
#define OBJECTIVEIDXATT 318
#define IDXATT 319
#define TYPEATT 320
#define DESCRIPTIONATT 321
#define NAMEATT 322
#define DUMMY 323




/* Copy the first part of user declarations.  */



 
  

#include "ErrorClass.h"
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
OSResult *yygetOSResult( std::string parsestring) ;




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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)

typedef union YYSTYPE {
	double dval;
	int ival;
	char* charval;
} YYSTYPE;
/* Line 191 of yacc.c.  */

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
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


/* Line 214 of yacc.c.  */


#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
             && defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  56
/* YYNRULES -- Number of rules. */
#define YYNRULES  114
/* YYNRULES -- Number of states. */
#define YYNSTATES  218

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,    70,
      72,     2,     2,    71,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    69,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     4,    10,    13,    17,    26,    31,    35,
      37,    40,    44,    48,    49,    51,    55,    58,    59,    61,
      65,    68,    69,    71,    75,    78,    79,    81,    85,    88,
      89,    91,    95,    98,   100,   106,   109,   110,   112,   113,
     115,   116,   121,   123,   126,   127,   130,   133,   136,   139,
     142,   145,   148,   151,   154,   156,   159,   163,   173,   174,
     178,   183,   187,   189,   192,   196,   200,   201,   205,   208,
     209,   218,   220,   223,   229,   235,   236,   239,   240,   241,
     249,   251,   254,   260,   266,   272,   274,   277,   281,   285,
     286,   295,   297,   300,   306,   312,   313,   322,   324,   327,
     333,   339,   343,   344,   346,   347,   349,   351,   354,   357,
     359,   361,   363,   365,   366
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
      74,     0,    -1,    -1,    76,    77,    86,    75,    12,    -1,
      10,     8,    -1,    10,    11,     8,    -1,    13,    78,    81,
      82,    83,    84,    85,    14,    -1,    52,    79,     8,    53,
      -1,    52,    79,     9,    -1,    80,    -1,    79,    80,    -1,
      65,     3,   126,    -1,    66,     3,   126,    -1,    -1,    15,
      -1,    16,     4,    17,    -1,    16,    17,    -1,    -1,    18,
      -1,    19,     4,    20,    -1,    19,    20,    -1,    -1,    21,
      -1,    22,     4,    23,    -1,    22,    23,    -1,    -1,    24,
      -1,    25,     4,    26,    -1,    25,    26,    -1,    -1,    56,
      -1,    54,     4,    55,    -1,    54,    55,    -1,    29,    -1,
      27,    88,    89,    87,    28,    -1,    27,    28,    -1,    -1,
      68,    -1,    -1,    68,    -1,    -1,    30,    92,    90,    91,
      -1,     9,    -1,     8,    98,    -1,    -1,    92,    93,    -1,
      94,   126,    -1,    95,   126,    -1,    96,   126,    -1,    97,
     126,    -1,    59,     5,    -1,    60,     5,    -1,    61,     5,
      -1,    62,     5,    -1,    31,    -1,    99,    31,    -1,    98,
      99,    31,    -1,    32,   100,     8,   101,   104,   105,   116,
     119,   125,    -1,    -1,    63,     5,   126,    -1,    50,   102,
       8,    51,    -1,    50,   102,     9,    -1,   103,    -1,   102,
     103,    -1,    65,     3,   126,    -1,    66,     3,   126,    -1,
      -1,    54,     4,    55,    -1,    54,    55,    -1,    -1,    38,
       8,    34,     8,   106,    35,   108,    39,    -1,   107,    -1,
     106,   107,    -1,    40,   122,     8,     6,    41,    -1,    40,
     122,     8,     5,    41,    -1,    -1,   108,   109,    -1,    -1,
      -1,    57,   110,   114,     8,   111,   112,    58,    -1,   113,
      -1,   112,   113,    -1,    40,   122,     8,     4,    41,    -1,
      40,   122,     8,     6,    41,    -1,    40,   122,     8,     5,
      41,    -1,   115,    -1,   114,   115,    -1,    67,     3,   126,
      -1,    66,     3,   126,    -1,    -1,    42,     8,    34,     8,
     117,    35,   123,    43,    -1,   118,    -1,   117,   118,    -1,
      44,   122,     8,     6,    45,    -1,    44,   122,     8,     5,
      45,    -1,    -1,    46,     8,    36,     8,   120,    37,   124,
      47,    -1,   121,    -1,   120,   121,    -1,    48,   122,     8,
       6,    49,    -1,    48,   122,     8,     5,    49,    -1,    64,
       5,   126,    -1,    -1,    68,    -1,    -1,    68,    -1,    33,
      -1,    68,    33,    -1,   128,     7,    -1,    69,    -1,    70,
      -1,    71,    -1,    72,    -1,    -1,   128,   127,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   105,   105,   104,   122,   123,   127,   129,   130,   132,
     133,   135,   136,   139,   140,   141,   142,   145,   146,   147,
     148,   150,   151,   152,   153,   155,   156,   157,   158,   160,
     161,   162,   163,   165,   166,   167,   169,   170,   172,   173,
     176,   175,   203,   204,   206,   207,   209,   210,   211,   212,
     216,   218,   220,   222,   226,   227,   228,   231,   237,   238,
     241,   242,   245,   246,   248,   249,   251,   252,   253,   255,
     256,   259,   260,   262,   266,   273,   274,   276,   279,   276,
     283,   284,   286,   291,   297,   305,   306,   308,   309,   312,
     313,   315,   316,   318,   320,   323,   324,   326,   327,   329,
     332,   339,   345,   346,   348,   349,   351,   352,   358,   360,
     361,   362,   363,   365,   366
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "INTEGER", "DOUBLE", "QUOTE", "GREATERTHAN", "ENDOFELEMENT", "OSRLSTART",
  "OSRLATTRIBUTETEXT", "OSRLEND", "RESULTHEADERSTART", "RESULTHEADEREND",
  "SERVICEURISTARTANDEND", "SERVICEURISTART", "SERVICEURIEND",
  "SERVICENAMESTARTANDEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "INSTANCENAMESTARTANDEND", "INSTANCENAMESTART", "INSTANCENAMEEND",
  "JOBIDSTARTANDEND", "JOBIDSTART", "JOBIDEND", "RESULTDATASTART",
  "RESULTDATAEND", "RESULTDATASTARTANDEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "SOLUTIONSTART", "SOLUTIONEND", "VALUESSTART",
  "VALUESEND", "DUALVALUESSTART", "DUALVALUESEND", "VARIABLESSTART",
  "VARIABLESEND", "VARSTART", "VAREND", "OBJECTIVESSTART", "OBJECTIVESEND",
  "OBJSTART", "OBJEND", "CONSTRAINTSSTART", "CONSTRAINTSEND", "CONSTART",
  "CONEND", "STATUSSTART", "STATUSEND", "GENERALSTATUSSTART",
  "GENERALSTATUSEND", "MESSAGESTART", "MESSAGEEND", "MESSAGESTARTANDEND",
  "OTHERSTART", "OTHEREND", "NUMBEROFSOLUTIONSATT", "NUMBEROFVARIABLESATT",
  "NUMBEROFCONSTRAINTSATT", "NUMBEROFOBJECTIVESATT", "OBJECTIVEIDXATT",
  "IDXATT", "TYPEATT", "DESCRIPTIONATT", "NAMEATT", "DUMMY", "' '",
  "'\\t'", "'\\r'", "'\\n'", "$accept", "osrldoc", "@1", "osrlstart",
  "resultHeader", "generalStatus", "anotherGeneralStatusATT",
  "generalstatusatt", "serviceURI", "serviceName", "instanceName", "jobID",
  "headerMessage", "resultData", "otherResultData", "statistics",
  "optimization", "@2", "optend", "anotherOptATT", "optatt",
  "optnumsolatt", "optnumvaratt", "optnumconatt", "optnumobjatt",
  "solution", "anothersolution", "objectiveIDXATT", "status",
  "anotherStatusATT", "statusatt", "message", "variables", "var",
  "anothervar", "otherVariables", "otherVariableResult", "@3", "@4",
  "othervar", "anotherothervar", "anotherotherVarATT", "otheratt",
  "objectives", "obj", "anotherobj", "constraints", "con", "anothercon",
  "anIDXATT", "otherObjectives", "otherConstraints", "otherSolution",
  "quote", "xmlWhiteSpaceChar", "xmlWhiteSpace", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,    32,
       9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    73,    75,    74,    76,    76,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    81,    81,    82,    82,    82,
      82,    83,    83,    83,    83,    84,    84,    84,    84,    85,
      85,    85,    85,    86,    86,    86,    87,    87,    88,    88,
      90,    89,    91,    91,    92,    92,    93,    93,    93,    93,
      94,    95,    96,    97,    98,    98,    98,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   104,   105,
     105,   106,   106,   107,   107,   108,   108,   110,   111,   109,
     112,   112,   113,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   123,   123,   124,   124,   125,   125,   126,   127,
     127,   127,   127,   128,   128
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     5,     2,     3,     8,     4,     3,     1,
       2,     3,     3,     0,     1,     3,     2,     0,     1,     3,
       2,     0,     1,     3,     2,     0,     1,     3,     2,     0,
       1,     3,     2,     1,     5,     2,     0,     1,     0,     1,
       0,     4,     1,     2,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     3,     9,     0,     3,
       4,     3,     1,     2,     3,     3,     0,     3,     2,     0,
       8,     1,     2,     5,     5,     0,     2,     0,     0,     7,
       1,     2,     5,     5,     5,     1,     2,     3,     3,     0,
       8,     1,     2,     5,     5,     0,     8,     1,     2,     5,
       5,     3,     0,     1,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,     0,     0,     5,
       0,    13,    38,    33,     2,     0,     0,     0,     9,    14,
       0,    17,    35,    39,     0,     0,   113,   113,     0,     8,
      10,     0,    16,    18,     0,    21,    44,    36,     3,    11,
       0,    12,     7,    15,     0,    20,    22,     0,    25,    40,
      37,     0,   108,   109,   110,   111,   112,   114,    19,     0,
      24,    26,     0,    29,     0,     0,     0,     0,     0,    45,
     113,   113,   113,   113,    34,    23,     0,    28,     0,    30,
       0,    50,    51,    52,    53,     0,    42,    41,    46,    47,
      48,    49,    27,     0,    32,     6,    54,    58,    43,     0,
      31,     0,     0,     0,    55,   113,     0,    56,    59,     0,
      66,     0,     0,     0,    62,     0,    69,   113,   113,     0,
      61,    63,     0,    68,     0,    89,    64,    65,    60,    67,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
     106,     0,    57,     0,     0,    71,     0,     0,   107,     0,
       0,    75,    72,     0,     0,    91,     0,   113,     0,     0,
       0,   102,    92,     0,     0,    97,   101,     0,     0,    70,
      77,    76,     0,   103,     0,     0,   104,    98,    74,    73,
       0,     0,     0,    90,     0,   105,     0,     0,     0,     0,
      85,    94,    93,     0,     0,    96,   113,   113,    78,    86,
     100,    99,    88,    87,     0,     0,     0,    80,     0,    79,
      81,     0,     0,     0,     0,    82,    84,    83
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,    25,     3,     8,    11,    17,    18,    21,    35,
      48,    63,    80,    14,    51,    24,    37,    68,    87,    49,
      69,    70,    71,    72,    73,    98,    99,   102,   110,   113,
     114,   116,   125,   144,   145,   159,   171,   180,   204,   206,
     207,   189,   190,   132,   154,   155,   136,   164,   165,   150,
     174,   186,   142,    39,    57,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -150
static const short yypact[] =
{
      13,    14,    27,    17,  -150,    34,  -150,    25,    28,  -150,
       6,    44,   -20,  -150,  -150,    51,    76,     2,  -150,  -150,
      16,    55,  -150,  -150,    64,    35,  -150,  -150,    46,  -150,
    -150,    84,  -150,  -150,    12,    54,  -150,    36,  -150,  -150,
      -6,  -150,  -150,  -150,    80,  -150,  -150,    11,    56,   -10,
    -150,    75,  -150,  -150,  -150,  -150,  -150,  -150,  -150,    79,
    -150,  -150,     5,   -15,   100,   101,   102,   103,    74,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,    85,  -150,    -2,  -150,
      95,  -150,  -150,  -150,  -150,    53,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,    57,  -150,  -150,  -150,    47,    81,    86,
    -150,   109,   107,    88,  -150,  -150,    66,  -150,  -150,    21,
      67,   115,   117,     4,  -150,     3,    89,  -150,  -150,    71,
    -150,  -150,    68,  -150,   116,    90,  -150,  -150,  -150,  -150,
      91,   118,    82,   121,    97,   125,   -28,    94,   127,   104,
    -150,   105,  -150,    72,   -14,  -150,    93,   131,  -150,   136,
     134,  -150,  -150,    72,   -16,  -150,    96,  -150,    83,   -33,
     135,    77,  -150,    72,   -19,  -150,  -150,   106,   108,  -150,
    -150,  -150,    87,  -150,   110,   138,    98,  -150,  -150,  -150,
      29,   111,   112,  -150,    92,  -150,   113,   145,   147,    -5,
    -150,  -150,  -150,   114,   119,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,   122,    72,   -23,  -150,   143,  -150,
    -150,    32,   120,   123,   124,  -150,  -150,  -150
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -150,  -150,  -150,  -150,  -150,  -150,  -150,   137,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,    60,  -150,  -150,  -150,
      39,  -150,  -150,  -150,    15,  -150,  -150,  -150,  -150,  -150,
     -51,  -150,   -22,  -150,  -150,    18,  -150,  -150,     7,  -149,
    -150,  -150,  -150,   -27,  -150,  -150
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      41,    52,    93,   198,   160,   140,   169,   122,    22,    76,
      28,    29,   119,   120,   175,    59,    44,   205,   176,   161,
      31,   151,     4,     1,   170,     5,   143,     6,   153,   163,
       7,    77,    45,    32,    60,   209,   212,   213,   214,    78,
     141,    79,     9,    88,    89,    90,    91,    38,    23,    64,
      65,    66,    67,    94,    26,    12,   208,    13,   123,    19,
      20,   187,   188,    53,    54,    55,    56,    15,    16,   111,
     112,    15,    16,    33,    34,    46,    47,    10,   108,    27,
      61,    62,    85,    86,    96,    97,   111,   112,   167,   168,
     126,   127,   181,   182,    36,   187,   188,   193,   194,    42,
      58,    43,    75,    74,    50,    81,    82,    83,    84,    95,
     101,    92,   100,    97,   105,   106,   109,   104,   117,   107,
     118,   115,   128,   129,   130,   133,   134,   124,   135,   137,
     166,   138,   131,   139,   143,   146,   149,   153,   148,   156,
     147,   157,   158,   172,   163,   173,   184,   178,   196,   179,
     197,   211,   121,   183,    30,   210,   191,   192,   103,   152,
     195,   215,   205,   200,   216,   217,   185,   199,   201,   202,
     203,   177,   162
};

static const unsigned char yycheck[] =
{
      27,     7,     4,     8,   153,    33,    39,     4,    28,     4,
       8,     9,     8,     9,   163,     4,     4,    40,    37,    35,
       4,    35,     8,    10,    57,    11,    40,     0,    44,    48,
      13,    26,    20,    17,    23,    58,     4,     5,     6,    54,
      68,    56,     8,    70,    71,    72,    73,    12,    68,    59,
      60,    61,    62,    55,     3,    27,   205,    29,    55,    15,
      16,    66,    67,    69,    70,    71,    72,    65,    66,    65,
      66,    65,    66,    18,    19,    21,    22,    52,   105,     3,
      24,    25,     8,     9,    31,    32,    65,    66,     5,     6,
     117,   118,     5,     6,    30,    66,    67,     5,     6,    53,
      20,    17,    23,    28,    68,     5,     5,     5,     5,    14,
      63,    26,    55,    32,     5,     8,    50,    31,     3,    31,
       3,    54,    51,    55,     8,    34,     8,    38,    46,     8,
     157,    34,    42,     8,    40,     8,    64,    44,    33,     8,
      36,     5,     8,     8,    48,    68,     8,    41,     3,    41,
       3,     8,   113,    43,    17,   206,    45,    45,    98,   144,
      47,    41,    40,    49,    41,    41,    68,   189,    49,   196,
     197,   164,   154
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    10,    74,    76,     8,    11,     0,    13,    77,     8,
      52,    78,    27,    29,    86,    65,    66,    79,    80,    15,
      16,    81,    28,    68,    88,    75,     3,     3,     8,     9,
      80,     4,    17,    18,    19,    82,    30,    89,    12,   126,
     128,   126,    53,    17,     4,    20,    21,    22,    83,    92,
      68,    87,     7,    69,    70,    71,    72,   127,    20,     4,
      23,    24,    25,    84,    59,    60,    61,    62,    90,    93,
      94,    95,    96,    97,    28,    23,     4,    26,    54,    56,
      85,     5,     5,     5,     5,     8,     9,    91,   126,   126,
     126,   126,    26,     4,    55,    14,    31,    32,    98,    99,
      55,    63,   100,    99,    31,     5,     8,    31,   126,    50,
     101,    65,    66,   102,   103,    54,   104,     3,     3,     8,
       9,   103,     4,    55,    38,   105,   126,   126,    51,    55,
       8,    42,   116,    34,     8,    46,   119,     8,    34,     8,
      33,    68,   125,    40,   106,   107,     8,    36,    33,    64,
     122,    35,   107,    44,   117,   118,     8,     5,     8,   108,
     122,    35,   118,    48,   120,   121,   126,     5,     6,    39,
      57,   109,     8,    68,   123,   122,    37,   121,    41,    41,
     110,     5,     6,    43,     8,    68,   124,    66,    67,   114,
     115,    45,    45,     5,     6,    47,     3,     3,     8,   115,
      49,    49,   126,   126,   111,    40,   112,   113,   122,    58,
     113,     8,     4,     5,     6,    41,    41,    41
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror (&yylloc, osresult, parserData, "syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value, Location);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yytype, yyvaluep, yylocationp)
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;
  (void) yylocationp;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (OSResult *osresult, OSrLParserData *parserData);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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
  /* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  YYLTYPE *yylerrsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
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
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
  *++yylsp = yylloc;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    {
 	if(parserData->numberOfSolutions > 0){
		for(int solIdx = 0; solIdx <  parserData->numberOfSolutions; solIdx++){
			osresult->setSolutionStatus(solIdx, parserData->statusType, parserData->statusDescription);
			osresult->setPrimalVariableValues(solIdx, parserData->primalSolution[ solIdx]);
			osresult->setNumberOfOtherVariableResult(solIdx, parserData->numberOfOtherVariableResult);
			for(int k = 0; k < parserData->numberOfOtherVariableResult; k++){
				osresult->setAnOtherVariableResult(solIdx, k, parserData->otherVarVec[ k]->name, parserData->otherVarVec[ k]->description, parserData->otherVarVec[ k]->otherVarText);				
			}
			osresult->setDualVariableValues(solIdx, parserData->dualSolution[ solIdx]);
			osresult->setObjectiveValues(solIdx, parserData->objectiveValues[ solIdx]);
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

    { osresult->setGeneralStatusType(yyvsp[-1].charval);  parserData->generalStatusTypePresent = true;}
    break;

  case 12:

    {  osresult->setGeneralStatusDescription(yyvsp[-1].charval); }
    break;

  case 15:

    {osresult->setServiceURI( yyvsp[-1].charval);}
    break;

  case 19:

    {osresult->setServiceName( yyvsp[-1].charval);}
    break;

  case 23:

    {osresult->setInstanceName( yyvsp[-1].charval) ;}
    break;

  case 27:

    {osresult->setJobID( yyvsp[-1].charval);}
    break;

  case 31:

    {osresult->setGeneralMessage( yyvsp[-1].charval);}
    break;

  case 40:

    {
// we now have the basic problem parameters
	if(parserData->numberOfSolutions > 0){
			parserData->primalSolution = new double* [parserData->numberOfSolutions];
			parserData->dualSolution = new double*[ parserData->numberOfSolutions];
			parserData->objectiveValues = new double*[ parserData->numberOfSolutions];
			parserData->objectiveIdx = new int[ parserData->numberOfSolutions];
			if( parserData->numberOfVariables > 0){
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->primalSolution[ i] = new double[ parserData->numberOfVariables];
				}
			}
			if( parserData->numberOfConstraints > 0){
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->dualSolution[ i] = new double[ parserData->numberOfConstraints];
				}
			}
			if( parserData->numberOfObjectives > 0){
				for(int i = 0; i < parserData->numberOfSolutions; i++){
					parserData->objectiveValues[ i] = new double[ parserData->numberOfObjectives];
				}
			}
	}
}
    break;

  case 50:

    {parserData->numberOfSolutions = yyvsp[0].ival; osresult->setSolutionNumber(yyvsp[0].ival);}
    break;

  case 51:

    {parserData->numberOfVariables = yyvsp[0].ival; osresult->setVariableNumber(yyvsp[0].ival); }
    break;

  case 52:

    {parserData->numberOfConstraints = yyvsp[0].ival; osresult->setConstraintNumber(yyvsp[0].ival);}
    break;

  case 53:

    {parserData->numberOfObjectives = yyvsp[0].ival; osresult->setObjectiveNumber(yyvsp[0].ival);}
    break;

  case 57:

    {parserData->solutionIdx++;}
    break;

  case 59:

    {if(yyvsp[-1].ival >= 0) osrlerror(NULL, NULL, NULL, "objective index must be nonpositive");
*(parserData->objectiveIdx + parserData->solutionIdx) = yyvsp[-1].ival;}
    break;

  case 60:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element");  osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
    break;

  case 61:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, NULL, "a type attribute required for status element"); parserData->statusTypePresent = false; osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);}
    break;

  case 64:

    {parserData->statusType = yyvsp[-1].charval; parserData->statusTypePresent = true;}
    break;

  case 65:

    {parserData->statusDescription = yyvsp[-1].charval;}
    break;

  case 73:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(parserData->primalSolution[parserData->solutionIdx] + parserData->kounter ) = yyvsp[-1].dval;
	}
    break;

  case 74:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
	*(parserData->primalSolution[parserData->solutionIdx] + parserData->kounter) = yyvsp[-1].ival;
}
    break;

  case 77:

    {  
    parserData->numberOfOtherVariableResult++;
	parserData->otherVarStruct = new OtherVariableResultStruct(); 
	parserData->otherVarStruct->otherVarText = new std::string[parserData->numberOfVariables];}
    break;

  case 78:

    {if(parserData->otherNamePresent == false) osrlerror(NULL, NULL, NULL, "other element requires name attribute"); 
	parserData->otherNamePresent = false;  
	}
    break;

  case 79:

    {parserData->otherVarVec.push_back( parserData->otherVarStruct);}
    break;

  case 82:

    { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
parserData->otherVarStruct->otherVarText[parserData->kounter] = yyvsp[-1].charval;
}
    break;

  case 83:

    { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << yyvsp[-1].dval;
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
}
    break;

  case 84:

    { 
if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfVariables - 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of variables");
std::ostringstream outStr;
outStr << yyvsp[-1].ival;
parserData->otherVarStruct->otherVarText[parserData->kounter] =  outStr.str();
}
    break;

  case 87:

    { parserData->otherNamePresent = true; parserData->otherVarStruct->name = yyvsp[-1].charval;}
    break;

  case 88:

    {   parserData->otherVarStruct->description = yyvsp[-1].charval;}
    break;

  case 93:

    { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = yyvsp[-1].dval;
}
    break;

  case 94:

    { *(parserData->objectiveValues[parserData->solutionIdx] + (parserData->kounter + parserData->numberOfObjectives)) = yyvsp[-1].ival;}
    break;

  case 99:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(parserData->dualSolution[parserData->solutionIdx] + parserData->kounter) = yyvsp[-1].dval;}
    break;

  case 100:

    { 
	if(parserData->kounter < 0 || parserData->kounter > parserData->numberOfConstraints- 1) osrlerror(NULL, NULL, NULL, "index must be greater than 0 and less than the number of constraints");
	*(parserData->dualSolution[parserData->solutionIdx] + parserData->kounter) = yyvsp[-1].ival;}
    break;

  case 101:

    {parserData->kounter = yyvsp[-1].ival;}
    break;


    }

/* Line 993 of yacc.c.  */


  yyvsp -= yylen;
  yyssp -= yylen;
  yylsp -= yylen;

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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (&yylloc, osresult, parserData, yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror (&yylloc, osresult, parserData, "syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (&yylloc, osresult, parserData, "syntax error");
    }

  yylerrsp = yylsp;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp, yylsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	  *++yylerrsp = yylloc;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  yylerrsp = yylsp;
  *++yylerrsp = yyloc;
  yylsp -= yylen;
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
  YYLLOC_DEFAULT (yyloc, yylsp, yylerrsp - yylsp);
  *++yylsp = yyloc;

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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror (&yylloc, osresult, parserData, "parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
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
	throw ErrorClass( error);
} //end osrlerror

OSResult *yygetOSResult(std::string parsestring){
	try{
		OSResult* osresult = NULL;
		osresult = new OSResult();
		OSrLParserData *parserData = NULL;
		parserData = new OSrLParserData();
		// call the flex scanner
		osrllex_init( &scanner);
		osrl_scan_string( parsestring.c_str(), scanner);
		osrlset_lineno (1 , scanner );
		//
		// call the Bison parser
		//
		if(  osrlparse( osresult,  parserData) != 0) {
			osrllex_destroy(scanner);
		 	delete parserData;
		  	throw ErrorClass(  "Error parsing the OSiL");
		 }
		osrllex_destroy(scanner);
		delete parserData;
		return osresult;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
} //end yygetOSResult


