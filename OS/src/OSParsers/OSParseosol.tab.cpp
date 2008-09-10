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
#define yyparse osolparse
#define yylex   osollex
#define yyerror osolerror
#define yylval  osollval
#define yychar  osolchar
#define yydebug osoldebug
#define yynerrs osolnerrs
#define yylloc osollloc

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
     OSOLSTART = 265,
     OSOLATTRIBUTETEXT = 266,
     OSOLEND = 267,
     LOCATIONTYPEATT = 268,
     TRANSPORTTYPEATT = 269,
     NUMBEROFJOBIDSATT = 270,
     NUMBEROFPATHSATT = 271,
     NUMBEROFPROCESSESATT = 272,
     NUMBEROFVARIABLESATT = 273,
     NUMBEROFOBJECTIVESATT = 274,
     NUMBEROFCONSTRAINTSATT = 275,
     NUMBEROFOTHEROPTIONSATT = 276,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 277,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 278,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 279,
     NUMBEROFVARATT = 280,
     NUMBEROFOBJATT = 281,
     NUMBEROFCONATT = 282,
     NAMEATT = 283,
     IDXATT = 284,
     VALUEATT = 285,
     DESCRIPTIONATT = 286,
     LBVALUEATT = 287,
     UBVALUEATT = 288,
     GENERALSTART = 289,
     GENERALEND = 290,
     SYSTEMSTART = 291,
     SYSTEMEND = 292,
     SERVICESTART = 293,
     SERVICEEND = 294,
     JOBSTART = 295,
     JOBEND = 296,
     OPTIMIZATIONSTART = 297,
     OPTIMIZATIONEND = 298,
     OTHERSTART = 299,
     OTHEREND = 300,
     SERVICEURISTART = 301,
     SERVICEURIEND = 302,
     SERVICENAMESTART = 303,
     SERVICENAMEEND = 304,
     CONTACTSTART = 305,
     CONTACTEND = 306,
     INSTANCENAMESTART = 307,
     INSTANCENAMEEND = 308,
     INSTANCELOCATIONSTART = 309,
     INSTANCELOCATIONEND = 310,
     JOBIDSTART = 311,
     JOBIDEND = 312,
     LICENSESTART = 313,
     LICENSEEND = 314,
     USERNAMESTART = 315,
     USERNAMEEND = 316,
     PASSWORDSTART = 317,
     PASSWORDEND = 318,
     MINDISKSPACESTART = 319,
     MINDISKSPACEEND = 320,
     MINMEMORYSIZESTART = 321,
     MINMEMORYSIZEEND = 322,
     MINCPUSPEEDSTART = 323,
     MINCPUSPEEDEND = 324,
     SERVICETYPESTART = 325,
     SERVICETYPEEND = 326,
     MAXTIMESTART = 327,
     MAXTIMEEND = 328,
     SCHEDULEDSTARTTIMESTART = 329,
     SCHEDULEDSTARTTIMEEND = 330,
     DEPENDENCIESSTART = 331,
     DEPENDENCIESEND = 332,
     REQDIRSTART = 333,
     REQDIREND = 334,
     PATHSTART = 335,
     PATHEND = 336,
     MAKEDIRSTART = 337,
     MAKEDIREND = 338,
     MAKEFILESTART = 339,
     MAKEFILEEND = 340,
     DELDIRSTART = 341,
     DELDIREND = 342,
     DELFILESTART = 343,
     DELFILEEND = 344,
     INPUTCOPYFROMSTART = 345,
     INPUTCOPYFROMEND = 346,
     INPUTCOPYTOSTART = 347,
     INPUTCOPYTOEND = 348,
     INPUTMOVEFROMSTART = 349,
     INPUTMOVEFROMEND = 350,
     INPUTMOVETOSTART = 351,
     INPUTMOVETOEND = 352,
     OUTPUTCOPYFROMSTART = 353,
     OUTPUTCOPYFROMEND = 354,
     OUTPUTCOPYTOSTART = 355,
     OUTPUTCOPYTOEND = 356,
     OUTPUTMOVEFROMSTART = 357,
     OUTPUTMOVEFROMEND = 358,
     OUTPUTMOVETOSTART = 359,
     OUTPUTMOVETOEND = 360,
     PROCESSESTOKILLSTART = 361,
     PROCESSESTOKILLEND = 362,
     PROCESSSTART = 363,
     PROCESSEND = 364,
     OPTIMIZATIONVARIABLESSTART = 365,
     OPTIMIZATIONVARIABLESEND = 366,
     INITIALVARIABLESSTART = 367,
     INITIALVARIABLESEND = 368,
     INITIALVARSTART = 369,
     INITIALVAREND = 370,
     OPTIMIZATIONOBJECTIVESSTART = 371,
     OPTIMIZATIONOBJECTIVESEND = 372,
     INITIALOBJVALUESSTART = 373,
     INITIALOBJVALUESEND = 374,
     OPTIMIZATIONINITIALOBJSTART = 375,
     OPTIMIZATIONINITIALOBJEND = 376,
     INITIALOBJBOUNDSSTART = 377,
     INITIALOBJBOUNDSEND = 378,
     OPTIMIZATIONCONSTRAINTSSTART = 379,
     OPTIMIZATIONCONSTRAINTSEND = 380,
     INITIALCONSTRAINTSSTART = 381,
     INITIALCONSTRAINTSEND = 382,
     INITIALCONSTART = 383,
     INITIALCONEND = 384,
     INITIALDUALSSTART = 385,
     INITIALDUALSEND = 386,
     DUMMY = 387
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
#define OSOLSTART 265
#define OSOLATTRIBUTETEXT 266
#define OSOLEND 267
#define LOCATIONTYPEATT 268
#define TRANSPORTTYPEATT 269
#define NUMBEROFJOBIDSATT 270
#define NUMBEROFPATHSATT 271
#define NUMBEROFPROCESSESATT 272
#define NUMBEROFVARIABLESATT 273
#define NUMBEROFOBJECTIVESATT 274
#define NUMBEROFCONSTRAINTSATT 275
#define NUMBEROFOTHEROPTIONSATT 276
#define NUMBEROFOTHERVARIABLEOPTIONSATT 277
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 278
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 279
#define NUMBEROFVARATT 280
#define NUMBEROFOBJATT 281
#define NUMBEROFCONATT 282
#define NAMEATT 283
#define IDXATT 284
#define VALUEATT 285
#define DESCRIPTIONATT 286
#define LBVALUEATT 287
#define UBVALUEATT 288
#define GENERALSTART 289
#define GENERALEND 290
#define SYSTEMSTART 291
#define SYSTEMEND 292
#define SERVICESTART 293
#define SERVICEEND 294
#define JOBSTART 295
#define JOBEND 296
#define OPTIMIZATIONSTART 297
#define OPTIMIZATIONEND 298
#define OTHERSTART 299
#define OTHEREND 300
#define SERVICEURISTART 301
#define SERVICEURIEND 302
#define SERVICENAMESTART 303
#define SERVICENAMEEND 304
#define CONTACTSTART 305
#define CONTACTEND 306
#define INSTANCENAMESTART 307
#define INSTANCENAMEEND 308
#define INSTANCELOCATIONSTART 309
#define INSTANCELOCATIONEND 310
#define JOBIDSTART 311
#define JOBIDEND 312
#define LICENSESTART 313
#define LICENSEEND 314
#define USERNAMESTART 315
#define USERNAMEEND 316
#define PASSWORDSTART 317
#define PASSWORDEND 318
#define MINDISKSPACESTART 319
#define MINDISKSPACEEND 320
#define MINMEMORYSIZESTART 321
#define MINMEMORYSIZEEND 322
#define MINCPUSPEEDSTART 323
#define MINCPUSPEEDEND 324
#define SERVICETYPESTART 325
#define SERVICETYPEEND 326
#define MAXTIMESTART 327
#define MAXTIMEEND 328
#define SCHEDULEDSTARTTIMESTART 329
#define SCHEDULEDSTARTTIMEEND 330
#define DEPENDENCIESSTART 331
#define DEPENDENCIESEND 332
#define REQDIRSTART 333
#define REQDIREND 334
#define PATHSTART 335
#define PATHEND 336
#define MAKEDIRSTART 337
#define MAKEDIREND 338
#define MAKEFILESTART 339
#define MAKEFILEEND 340
#define DELDIRSTART 341
#define DELDIREND 342
#define DELFILESTART 343
#define DELFILEEND 344
#define INPUTCOPYFROMSTART 345
#define INPUTCOPYFROMEND 346
#define INPUTCOPYTOSTART 347
#define INPUTCOPYTOEND 348
#define INPUTMOVEFROMSTART 349
#define INPUTMOVEFROMEND 350
#define INPUTMOVETOSTART 351
#define INPUTMOVETOEND 352
#define OUTPUTCOPYFROMSTART 353
#define OUTPUTCOPYFROMEND 354
#define OUTPUTCOPYTOSTART 355
#define OUTPUTCOPYTOEND 356
#define OUTPUTMOVEFROMSTART 357
#define OUTPUTMOVEFROMEND 358
#define OUTPUTMOVETOSTART 359
#define OUTPUTMOVETOEND 360
#define PROCESSESTOKILLSTART 361
#define PROCESSESTOKILLEND 362
#define PROCESSSTART 363
#define PROCESSEND 364
#define OPTIMIZATIONVARIABLESSTART 365
#define OPTIMIZATIONVARIABLESEND 366
#define INITIALVARIABLESSTART 367
#define INITIALVARIABLESEND 368
#define INITIALVARSTART 369
#define INITIALVAREND 370
#define OPTIMIZATIONOBJECTIVESSTART 371
#define OPTIMIZATIONOBJECTIVESEND 372
#define INITIALOBJVALUESSTART 373
#define INITIALOBJVALUESEND 374
#define OPTIMIZATIONINITIALOBJSTART 375
#define OPTIMIZATIONINITIALOBJEND 376
#define INITIALOBJBOUNDSSTART 377
#define INITIALOBJBOUNDSEND 378
#define OPTIMIZATIONCONSTRAINTSSTART 379
#define OPTIMIZATIONCONSTRAINTSEND 380
#define INITIALCONSTRAINTSSTART 381
#define INITIALCONSTRAINTSEND 382
#define INITIALCONSTART 383
#define INITIALCONEND 384
#define INITIALDUALSSTART 385
#define INITIALDUALSEND 386
#define DUMMY 387




/* Copy the first part of user declarations.  */



 
  

#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include <iostream>
#include <sstream> 


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osol_scan_string (const char *yy_str , void* yyscanner  );
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* yyscanner );
int osolget_lineno( void* yyscanner);
char *osolget_text (void* yyscanner );
void osolset_lineno (int line_number , void* yyscanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );
void  yygetOSOption(const char *ch, OSOption* m_osoption, OSoLParserData *m_parserData ) throw(ErrorClass);




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



void osolerror(YYLTYPE* type, OSOption *osoption,  OSoLParserData *parserData, const char* errormsg ) ;
int osollex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
 
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  137
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   387

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   134,
     136,     2,     2,   135,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   133,     2,     2,     2,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    11,    13,    16,    23,    24,    29,
      32,    33,    36,    38,    40,    42,    44,    46,    48,    50,
      52,    54,    55,    57,    59,    62,    66,    71,    72,    74,
      76,    79,    83,    88,    89,    91,    93,    96,   100,   105,
     106,   108,   110,   113,   118,   124,   125,   129,   130,   132,
     134,   137,   141,   146,   147,   149,   151,   154,   158,   163,
     164,   166,   168,   171,   175,   180,   181,   183,   185,   188,
     192,   197,   198,   200,   202,   205,   210,   216,   217,   221,
     222,   227,   230,   231,   234,   236,   238,   240,   241,   243,
     245,   248,   252,   257,   258,   260,   262,   265,   269,   274,
     275,   277,   279,   282,   286,   291,   292,   297,   300,   301,
     304,   306,   307,   309,   311,   314,   318,   323,   324,   329,
     332,   333,   334,   339,   342,   343,   344,   349,   352
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     138,     0,    -1,   139,     8,   140,    12,    -1,   139,     9,
      -1,    10,    -1,    10,    11,    -1,   141,   173,   185,   191,
     193,   195,    -1,    -1,    34,     8,   142,    35,    -1,    34,
       9,    -1,    -1,   142,   143,    -1,   144,    -1,   147,    -1,
     150,    -1,   153,    -1,   157,    -1,   160,    -1,   163,    -1,
     166,    -1,   169,    -1,    -1,   145,    -1,   146,    -1,    46,
       9,    -1,    46,     8,    47,    -1,    46,     8,     4,    47,
      -1,    -1,   148,    -1,   149,    -1,    48,     9,    -1,    48,
       8,    49,    -1,    48,     8,     4,    49,    -1,    -1,   151,
      -1,   152,    -1,    52,     9,    -1,    52,     8,    53,    -1,
      52,     8,     4,    53,    -1,    -1,   154,    -1,   155,    -1,
      54,     9,    -1,    54,   156,     8,    55,    -1,    54,   156,
       8,     4,    55,    -1,    -1,    13,     3,     7,    -1,    -1,
     158,    -1,   159,    -1,    56,     9,    -1,    56,     8,    57,
      -1,    56,     8,     4,    57,    -1,    -1,   161,    -1,   162,
      -1,    58,     9,    -1,    58,     8,    59,    -1,    58,     8,
       4,    59,    -1,    -1,   164,    -1,   165,    -1,    60,     9,
      -1,    60,     8,    61,    -1,    60,     8,     4,    61,    -1,
      -1,   167,    -1,   168,    -1,    62,     9,    -1,    62,     8,
      63,    -1,    62,     8,     4,    63,    -1,    -1,   170,    -1,
     171,    -1,    50,     9,    -1,    50,   172,     8,    51,    -1,
      50,   172,     8,     4,    51,    -1,    -1,    14,     3,     7,
      -1,    -1,    36,     8,   174,    37,    -1,    36,     9,    -1,
      -1,   174,   175,    -1,   176,    -1,   179,    -1,   182,    -1,
      -1,   177,    -1,   178,    -1,    64,     9,    -1,    64,     8,
      65,    -1,    64,     8,     4,    65,    -1,    -1,   180,    -1,
     181,    -1,    66,     9,    -1,    66,     8,    67,    -1,    66,
       8,     4,    67,    -1,    -1,   183,    -1,   184,    -1,    68,
       9,    -1,    68,     8,    69,    -1,    68,     8,     4,    69,
      -1,    -1,    38,     8,   186,    39,    -1,    38,     9,    -1,
      -1,   186,   187,    -1,   188,    -1,    -1,   189,    -1,   190,
      -1,    70,     9,    -1,    70,     8,    71,    -1,    70,     8,
       4,    71,    -1,    -1,    40,     8,   192,    41,    -1,    40,
       9,    -1,    -1,    -1,    42,     8,   194,    43,    -1,    42,
       9,    -1,    -1,    -1,    44,     8,   196,    45,    -1,    44,
       9,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   118,   120,   121,   123,   125,   126,   127,
     129,   129,   131,   131,   131,   131,   131,   132,   132,   132,
     132,   135,   135,   135,   137,   138,   142,   147,   147,   147,
     149,   150,   154,   159,   159,   159,   161,   162,   166,   171,
     171,   171,   173,   174,   178,   182,   182,   187,   187,   187,
     189,   190,   194,   199,   199,   199,   201,   202,   206,   211,
     211,   211,   213,   214,   218,   223,   223,   223,   225,   226,
     230,   234,   234,   234,   236,   237,   241,   245,   245,   250,
     251,   252,   254,   254,   256,   256,   256,   258,   258,   258,
     260,   261,   265,   270,   270,   270,   272,   273,   277,   282,
     282,   282,   284,   285,   289,   294,   295,   296,   298,   298,
     300,   302,   302,   302,   304,   305,   309,   314,   315,   316,
     318,   321,   322,   323,   325,   328,   329,   330,   332
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "INTEGER", "DOUBLE", "QUOTE", "GREATERTHAN", "ENDOFELEMENT", "OSOLSTART",
  "OSOLATTRIBUTETEXT", "OSOLEND", "LOCATIONTYPEATT", "TRANSPORTTYPEATT",
  "NUMBEROFJOBIDSATT", "NUMBEROFPATHSATT", "NUMBEROFPROCESSESATT",
  "NUMBEROFVARIABLESATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFCONSTRAINTSATT", "NUMBEROFOTHEROPTIONSATT",
  "NUMBEROFOTHERVARIABLEOPTIONSATT", "NUMBEROFOTHEROBJECTIVEOPTIONSATT",
  "NUMBEROFOTHERCONSTRAINTOPTIONSATT", "NUMBEROFVARATT", "NUMBEROFOBJATT",
  "NUMBEROFCONATT", "NAMEATT", "IDXATT", "VALUEATT", "DESCRIPTIONATT",
  "LBVALUEATT", "UBVALUEATT", "GENERALSTART", "GENERALEND", "SYSTEMSTART",
  "SYSTEMEND", "SERVICESTART", "SERVICEEND", "JOBSTART", "JOBEND",
  "OPTIMIZATIONSTART", "OPTIMIZATIONEND", "OTHERSTART", "OTHEREND",
  "SERVICEURISTART", "SERVICEURIEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "CONTACTSTART", "CONTACTEND", "INSTANCENAMESTART", "INSTANCENAMEEND",
  "INSTANCELOCATIONSTART", "INSTANCELOCATIONEND", "JOBIDSTART", "JOBIDEND",
  "LICENSESTART", "LICENSEEND", "USERNAMESTART", "USERNAMEEND",
  "PASSWORDSTART", "PASSWORDEND", "MINDISKSPACESTART", "MINDISKSPACEEND",
  "MINMEMORYSIZESTART", "MINMEMORYSIZEEND", "MINCPUSPEEDSTART",
  "MINCPUSPEEDEND", "SERVICETYPESTART", "SERVICETYPEEND", "MAXTIMESTART",
  "MAXTIMEEND", "SCHEDULEDSTARTTIMESTART", "SCHEDULEDSTARTTIMEEND",
  "DEPENDENCIESSTART", "DEPENDENCIESEND", "REQDIRSTART", "REQDIREND",
  "PATHSTART", "PATHEND", "MAKEDIRSTART", "MAKEDIREND", "MAKEFILESTART",
  "MAKEFILEEND", "DELDIRSTART", "DELDIREND", "DELFILESTART", "DELFILEEND",
  "INPUTCOPYFROMSTART", "INPUTCOPYFROMEND", "INPUTCOPYTOSTART",
  "INPUTCOPYTOEND", "INPUTMOVEFROMSTART", "INPUTMOVEFROMEND",
  "INPUTMOVETOSTART", "INPUTMOVETOEND", "OUTPUTCOPYFROMSTART",
  "OUTPUTCOPYFROMEND", "OUTPUTCOPYTOSTART", "OUTPUTCOPYTOEND",
  "OUTPUTMOVEFROMSTART", "OUTPUTMOVEFROMEND", "OUTPUTMOVETOSTART",
  "OUTPUTMOVETOEND", "PROCESSESTOKILLSTART", "PROCESSESTOKILLEND",
  "PROCESSSTART", "PROCESSEND", "OPTIMIZATIONVARIABLESSTART",
  "OPTIMIZATIONVARIABLESEND", "INITIALVARIABLESSTART",
  "INITIALVARIABLESEND", "INITIALVARSTART", "INITIALVAREND",
  "OPTIMIZATIONOBJECTIVESSTART", "OPTIMIZATIONOBJECTIVESEND",
  "INITIALOBJVALUESSTART", "INITIALOBJVALUESEND",
  "OPTIMIZATIONINITIALOBJSTART", "OPTIMIZATIONINITIALOBJEND",
  "INITIALOBJBOUNDSSTART", "INITIALOBJBOUNDSEND",
  "OPTIMIZATIONCONSTRAINTSSTART", "OPTIMIZATIONCONSTRAINTSEND",
  "INITIALCONSTRAINTSSTART", "INITIALCONSTRAINTSEND", "INITIALCONSTART",
  "INITIALCONEND", "INITIALDUALSSTART", "INITIALDUALSEND", "DUMMY", "' '",
  "'\\t'", "'\\r'", "'\\n'", "$accept", "osoldoc", "osolstart",
  "osolcontent", "osolgeneral", "generalcontent", "generaloption",
  "serviceURI", "emptyURI", "nonemptyURI", "servicename",
  "emptyservicename", "nonemptyservicename", "instancename",
  "emptyinstancename", "nonemptyinstancename", "instancelocation",
  "emptylocation", "nonemptylocation", "locationtypeatt", "jobid",
  "emptyjobid", "nonemptyjobid", "license", "emptylicense",
  "nonemptylicense", "username", "emptyusername", "nonemptyusername",
  "password", "emptypassword", "nonemptypassword", "contact",
  "emptycontact", "nonemptycontact", "transporttypeatt", "osolsystem",
  "systemcontent", "systemoption", "mindiskspace", "emptymindiskspace",
  "nonemptymindiskspace", "minmemorysize", "emptyminmemorysize",
  "nonemptyminmemorysize", "mincpuspeed", "emptymincpuspeed",
  "nonemptymincpuspeed", "osolservice", "servicecontent", "serviceoption",
  "servicetype", "emptyservicetype", "nonemptyservicetype", "osoljob",
  "jobcontent", "osoloptimization", "optimizationcontent", "osolother",
  "othercontent", 0
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
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   137,   138,   138,   139,   139,   140,   141,   141,   141,
     142,   142,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   144,   144,   144,   145,   145,   146,   147,   147,   147,
     148,   148,   149,   150,   150,   150,   151,   151,   152,   153,
     153,   153,   154,   154,   155,   156,   156,   157,   157,   157,
     158,   158,   159,   160,   160,   160,   161,   161,   162,   163,
     163,   163,   164,   164,   165,   166,   166,   166,   167,   167,
     168,   169,   169,   169,   170,   170,   171,   172,   172,   173,
     173,   173,   174,   174,   175,   175,   175,   176,   176,   176,
     177,   177,   178,   179,   179,   179,   180,   180,   181,   182,
     182,   182,   183,   183,   184,   185,   185,   185,   186,   186,
     187,   188,   188,   188,   189,   189,   190,   191,   191,   191,
     192,   193,   193,   193,   194,   195,   195,   195,   196
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     1,     2,     6,     0,     4,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     2,     3,     4,     0,     1,     1,
       2,     3,     4,     0,     1,     1,     2,     3,     4,     0,
       1,     1,     2,     4,     5,     0,     3,     0,     1,     1,
       2,     3,     4,     0,     1,     1,     2,     3,     4,     0,
       1,     1,     2,     3,     4,     0,     1,     1,     2,     3,
       4,     0,     1,     1,     2,     4,     5,     0,     3,     0,
       4,     2,     0,     2,     1,     1,     1,     0,     1,     1,
       2,     3,     4,     0,     1,     1,     2,     3,     4,     0,
       1,     1,     2,     3,     4,     0,     4,     2,     0,     2,
       1,     0,     1,     1,     2,     3,     4,     0,     4,     2,
       0,     0,     4,     2,     0,     0,     4,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     0,     0,
      79,    10,     9,     2,     0,   105,     0,    82,    81,     0,
     117,     8,     0,     0,    77,     0,    45,     0,     0,     0,
       0,    11,    12,    22,    23,    13,    28,    29,    14,    34,
      35,    15,    40,    41,    16,    48,    49,    17,    54,    55,
      18,    60,    61,    19,    66,    67,    20,    72,    73,     0,
     108,   107,     0,   121,     0,    24,     0,    30,    74,     0,
       0,     0,    36,    42,     0,     0,     0,    50,     0,    56,
       0,    62,     0,    68,    80,     0,     0,     0,    83,    84,
      88,    89,    85,    94,    95,    86,   100,   101,     0,   120,
     119,     0,   125,     0,    25,     0,    31,     0,     0,     0,
      37,     0,     0,     0,    51,     0,    57,     0,    63,     0,
      69,     0,    90,     0,    96,     0,   102,   106,     0,   109,
     110,   112,   113,     0,   124,   123,     0,     6,    26,    32,
      78,     0,    75,    38,    46,     0,    43,    52,    58,    64,
      70,     0,    91,     0,    97,     0,   103,     0,   114,   118,
       0,   128,   127,    76,    44,    92,    98,   104,     0,   115,
     122,     0,   116,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    16,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    75,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    70,    15,    59,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    20,    98,
     129,   130,   131,   132,    63,   133,   102,   160,   137,   171
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -26
static const yytype_int8 yypact[] =
{
      18,    19,    15,    13,   -26,   -26,   -17,   -26,    17,    20,
      56,   -26,   -26,   -26,    38,    16,   -19,   -26,   -26,    40,
     -21,   -26,    42,    44,     9,    60,    11,    62,    64,    66,
      68,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -24,
     -26,   -26,    70,    -8,     8,   -26,     7,   -26,   -26,    33,
      30,     5,   -26,   -26,    90,    86,     3,   -26,     2,   -26,
       1,   -26,     0,   -26,   -26,    72,    74,    76,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -25,   -26,
     -26,    78,    51,    49,   -26,    48,   -26,    91,     6,    46,
     -26,    93,     4,    45,   -26,    47,   -26,    43,   -26,    50,
     -26,    -1,   -26,    -2,   -26,    -3,   -26,   -26,    80,   -26,
     -26,   -26,   -26,    67,   -26,   -26,    82,   -26,   -26,   -26,
     -26,    52,   -26,   -26,   -26,    54,   -26,   -26,   -26,   -26,
     -26,    36,   -26,    53,   -26,    41,   -26,    -4,   -26,   -26,
      69,   -26,   -26,   -26,   -26,   -26,   -26,   -26,    34,   -26,
     -26,    71,   -26,   -26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     168,   155,   153,   151,   119,   117,   115,   113,   145,   109,
     141,   105,   103,    84,   127,     5,    21,     8,    68,    62,
      73,     6,     7,    69,    74,    11,    12,    22,     1,    23,
       4,    24,    13,    25,   101,    26,   107,    27,   108,    28,
      85,    29,    86,    30,    87,   128,    17,    18,    60,    61,
      64,    65,    66,    67,    19,   104,   106,   142,   110,   146,
     114,   116,   118,   120,   152,   154,   156,   169,    71,    72,
      76,    77,    78,    79,    80,    81,    82,    83,    99,   100,
     121,   122,   123,   124,   125,   126,   134,   135,   157,   158,
     161,   162,    14,   111,   112,   136,   138,   139,   140,   143,
     144,   165,   147,   163,   149,   172,   148,     0,   159,   164,
     167,     0,   170,   150,     0,     0,   173,     0,     0,     0,
     166
};

static const yytype_int8 yycheck[] =
{
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,    37,    39,     0,    35,    34,     9,    40,
       9,     8,     9,    14,    13,     8,     9,    46,    10,    48,
      11,    50,    12,    52,    42,    54,     3,    56,     8,    58,
      64,    60,    66,    62,    68,    70,     8,     9,     8,     9,
       8,     9,     8,     9,    38,    47,    49,    51,    53,    55,
      57,    59,    61,    63,    65,    67,    69,    71,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,    36,     3,     8,    44,    47,    49,     7,    53,
       7,    65,    57,    51,    61,    71,    59,    -1,    41,    55,
      69,    -1,    43,    63,    -1,    -1,    45,    -1,    -1,    -1,
      67
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,   138,   139,    11,     0,     8,     9,    34,   140,
     141,     8,     9,    12,    36,   173,   142,     8,     9,    38,
     185,    35,    46,    48,    50,    52,    54,    56,    58,    60,
      62,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   174,
       8,     9,    40,   191,     8,     9,     8,     9,     9,    14,
     172,     8,     9,     9,    13,   156,     8,     9,     8,     9,
       8,     9,     8,     9,    37,    64,    66,    68,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   186,     8,
       9,    42,   193,     4,    47,     4,    49,     3,     8,     4,
      53,     3,     8,     4,    57,     4,    59,     4,    61,     4,
      63,     8,     9,     8,     9,     8,     9,    39,    70,   187,
     188,   189,   190,   192,     8,     9,    44,   195,    47,    49,
       7,     4,    51,    53,     7,     4,    55,    57,    59,    61,
      63,     4,    65,     4,    67,     4,    69,     8,     9,    41,
     194,     8,     9,    51,    55,    65,    67,    69,     4,    71,
      43,   196,    71,    45
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
      yyerror (&yylloc, osoption, parserData, YY_("syntax error: cannot back up")); \
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
		  Type, Value, Location, osoption, parserData); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osoption);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osoption, parserData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSOption *osoption;
    OSoLParserData *parserData;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osoption, parserData);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osoption, parserData); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osoption, parserData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osoption);
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
int yyparse (OSOption *osoption, OSoLParserData *parserData);
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
yyparse (OSOption *osoption, OSoLParserData *parserData)
#else
int
yyparse (osoption, parserData)
    OSOption *osoption;
    OSoLParserData *parserData;
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
        case 25:

    {
}
    break;

  case 26:

    {
}
    break;

  case 31:

    {
}
    break;

  case 32:

    {
}
    break;

  case 37:

    {
}
    break;

  case 38:

    {
}
    break;

  case 43:

    {
}
    break;

  case 44:

    {
}
    break;

  case 46:

    {
}
    break;

  case 51:

    {
}
    break;

  case 52:

    {
}
    break;

  case 57:

    {
}
    break;

  case 58:

    {
}
    break;

  case 63:

    {
}
    break;

  case 64:

    {
}
    break;

  case 69:

    {
}
    break;

  case 70:

    {
}
    break;

  case 75:

    {
}
    break;

  case 76:

    {
}
    break;

  case 78:

    {
}
    break;

  case 91:

    {
}
    break;

  case 92:

    {
}
    break;

  case 97:

    {
}
    break;

  case 98:

    {
}
    break;

  case 103:

    {
}
    break;

  case 104:

    {
}
    break;

  case 115:

    {
}
    break;

  case 116:

    {
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
      yyerror (&yylloc, osoption, parserData, YY_("syntax error"));
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
	    yyerror (&yylloc, osoption, parserData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osoption, parserData, YY_("syntax error"));
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
		      yytoken, &yylval, &yylloc, osoption, parserData);
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
		  yystos[yystate], yyvsp, yylsp, osoption, parserData);
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
  yyerror (&yylloc, osoption, parserData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osoption, parserData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osoption, parserData);
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





void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, const char* errormsg )
{
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "Input is either not valid or well formed: "  + error;
	outStr << error << std::endl;
	outStr << "See line number: " << osolget_lineno( scanner) << std::endl; 
	outStr << "The offending text is: " << osolget_text ( scanner ) << std::endl; 
	error = outStr.str();
	//printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
	//if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
	//osollex_destroy( scanner);
	throw ErrorClass( error);
} //end osolerror

void  yygetOSOption(const char *parsestring, OSOption *osoption, OSoLParserData *parserData) throw(ErrorClass){
	try{
		osol_scan_string( parsestring, scanner);
		osolset_lineno (1 , scanner );
		//
		// call the Bison parser
		//
		if(  osolparse( osoption,  parserData) != 0) {
			//osollex_destroy(scanner);
		  	throw ErrorClass(  "Error parsing the OSoL file");
		 }
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
} //end yygetOSOption


