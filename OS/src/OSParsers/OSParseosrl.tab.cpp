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
     NUMBEROFCONATT = 267,
     NUMBEROFCONSTRAINTSATT = 268,
     NUMBEROFITEMSATT = 269,
     NUMBEROFOBJATT = 270,
     NUMBEROFOBJECTIVESATT = 271,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 272,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 273,
     NUMBEROFOTHERRESULTSATT = 274,
     NUMBEROFOTHERSOLUTIONRESULTSATT = 275,
     NUMBEROFOTHERVARIABLERESULTSATT = 276,
     NUMBEROFSOLUTIONSATT = 277,
     NUMBEROFSOLVEROUTPUTSATT = 278,
     NUMBEROFSUBSTATUSESATT = 279,
     NUMBEROFTIMESATT = 280,
     NUMBEROFVARATT = 281,
     NUMBEROFVARIABLESATT = 282,
     TARGETOBJECTIVEIDXATT = 283,
     IDXATT = 284,
     CATEGORYATT = 285,
     EMPTYCATEGORYATT = 286,
     DESCRIPTIONATT = 287,
     EMPTYDESCRIPTIONATT = 288,
     NAMEATT = 289,
     EMPTYNAMEATT = 290,
     TYPEATT = 291,
     EMPTYTYPEATT = 292,
     UNITATT = 293,
     EMPTYUNITATT = 294,
     VALUEATT = 295,
     EMPTYVALUEATT = 296,
     WEIGHTEDOBJECTIVESATT = 297,
     EMPTYWEIGHTEDOBJECTIVESATT = 298,
     OSRLSTART = 299,
     OSRLSTARTEMPTY = 300,
     OSRLATTRIBUTETEXT = 301,
     OSRLEND = 302,
     GENERALSTART = 303,
     GENERALEND = 304,
     SYSTEMSTART = 305,
     SYSTEMEND = 306,
     SERVICESTART = 307,
     SERVICEEND = 308,
     JOBSTART = 309,
     JOBEND = 310,
     OPTIMIZATIONSTART = 311,
     OPTIMIZATIONEND = 312,
     ITEMSTART = 313,
     ITEMEND = 314,
     ITEMSTARTANDEND = 315,
     ITEMEMPTY = 316,
     ACTUALSTARTTIMESTART = 317,
     ACTUALSTARTTIMEEND = 318,
     AVAILABLECPUNUMBERSTART = 319,
     AVAILABLECPUNUMBEREND = 320,
     AVAILABLECPUSPEEDSTART = 321,
     AVAILABLECPUSPEEDEND = 322,
     AVAILABLEDISKSPACESTART = 323,
     AVAILABLEDISKSPACEEND = 324,
     AVAILABLEMEMORYSTART = 325,
     AVAILABLEMEMORYEND = 326,
     BASISSTATUSSTART = 327,
     BASISSTATUSEND = 328,
     BASSTATUSSTART = 329,
     BASSTATUSEND = 330,
     CONSTART = 331,
     CONEND = 332,
     CONSTRAINTSSTART = 333,
     CONSTRAINTSEND = 334,
     CURRENTJOBCOUNTSTART = 335,
     CURRENTJOBCOUNTEND = 336,
     CURRENTSTATESTART = 337,
     CURRENTSTATEEND = 338,
     DUALVALUESSTART = 339,
     DUALVALUESEND = 340,
     ENDTIMESTART = 341,
     ENDTIMEEND = 342,
     GENERALSTATUSSTART = 343,
     GENERALSTATUSEND = 344,
     GENERALSUBSTATUSSTART = 345,
     GENERALSUBSTATUSEND = 346,
     INSTANCENAMESTART = 347,
     INSTANCENAMEEND = 348,
     JOBIDSTART = 349,
     JOBIDEND = 350,
     MESSAGESTART = 351,
     MESSAGEEND = 352,
     OBJSTART = 353,
     OBJEND = 354,
     OBJECTIVESSTART = 355,
     OBJECTIVESEND = 356,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 357,
     OPTIMIZATIONSOLUTIONSTATUSEND = 358,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 359,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 360,
     OTHERSTART = 361,
     OTHEREND = 362,
     OTHERRESULTSSTART = 363,
     OTHERRESULTSEND = 364,
     OTHERSOLUTIONRESULTSTART = 365,
     OTHERSOLUTIONRESULTEND = 366,
     OTHERSOLUTIONRESULTSSTART = 367,
     OTHERSOLUTIONRESULTSEND = 368,
     OTHERSOLVEROUTPUTSTART = 369,
     OTHERSOLVEROUTPUTEND = 370,
     SCHEDULEDSTARTTIMESTART = 371,
     SCHEDULEDSTARTTIMEEND = 372,
     SERVICENAMESTART = 373,
     SERVICENAMEEND = 374,
     SERVICEURISTART = 375,
     SERVICEURIEND = 376,
     SERVICEUTILIZATIONSTART = 377,
     SERVICEUTILIZATIONEND = 378,
     SOLUTIONSTART = 379,
     SOLUTIONEND = 380,
     SOLVERINVOKEDSTART = 381,
     SOLVERINVOKEDEND = 382,
     SOLVEROUTPUTSTART = 383,
     SOLVEROUTPUTEND = 384,
     STATUSSTART = 385,
     STATUSEND = 386,
     SUBMITTIMESTART = 387,
     SUBMITTIMEEND = 388,
     SUBSTATUSSTART = 389,
     SUBSTATUSEND = 390,
     SYSTEMINFORMATIONSTART = 391,
     SYSTEMINFORMATIONEND = 392,
     TIMESTART = 393,
     TIMEEND = 394,
     TIMESERVICESTARTEDSTART = 395,
     TIMESERVICESTARTEDEND = 396,
     TIMESTAMPSTART = 397,
     TIMESTAMPEND = 398,
     TIMINGINFORMATIONSTART = 399,
     TIMINGINFORMATIONEND = 400,
     TOTALJOBSSOFARSTART = 401,
     TOTALJOBSSOFAREND = 402,
     USEDCPUNUMBERSTART = 403,
     USEDCPUNUMBEREND = 404,
     USEDCPUSPEEDSTART = 405,
     USEDCPUSPEEDEND = 406,
     USEDDISKSPACESTART = 407,
     USEDDISKSPACEEND = 408,
     USEDMEMORYSTART = 409,
     USEDMEMORYEND = 410,
     VALUESSTART = 411,
     VALUESEND = 412,
     VALUESSTRINGSTART = 413,
     VALUESSTRINGEND = 414,
     VARSTART = 415,
     VAREND = 416,
     VARIABLESSTART = 417,
     VARIABLESEND = 418,
     DUMMY = 419
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
#define NUMBEROFCONATT 267
#define NUMBEROFCONSTRAINTSATT 268
#define NUMBEROFITEMSATT 269
#define NUMBEROFOBJATT 270
#define NUMBEROFOBJECTIVESATT 271
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 272
#define NUMBEROFOTHEROBJECTIVERESULTSATT 273
#define NUMBEROFOTHERRESULTSATT 274
#define NUMBEROFOTHERSOLUTIONRESULTSATT 275
#define NUMBEROFOTHERVARIABLERESULTSATT 276
#define NUMBEROFSOLUTIONSATT 277
#define NUMBEROFSOLVEROUTPUTSATT 278
#define NUMBEROFSUBSTATUSESATT 279
#define NUMBEROFTIMESATT 280
#define NUMBEROFVARATT 281
#define NUMBEROFVARIABLESATT 282
#define TARGETOBJECTIVEIDXATT 283
#define IDXATT 284
#define CATEGORYATT 285
#define EMPTYCATEGORYATT 286
#define DESCRIPTIONATT 287
#define EMPTYDESCRIPTIONATT 288
#define NAMEATT 289
#define EMPTYNAMEATT 290
#define TYPEATT 291
#define EMPTYTYPEATT 292
#define UNITATT 293
#define EMPTYUNITATT 294
#define VALUEATT 295
#define EMPTYVALUEATT 296
#define WEIGHTEDOBJECTIVESATT 297
#define EMPTYWEIGHTEDOBJECTIVESATT 298
#define OSRLSTART 299
#define OSRLSTARTEMPTY 300
#define OSRLATTRIBUTETEXT 301
#define OSRLEND 302
#define GENERALSTART 303
#define GENERALEND 304
#define SYSTEMSTART 305
#define SYSTEMEND 306
#define SERVICESTART 307
#define SERVICEEND 308
#define JOBSTART 309
#define JOBEND 310
#define OPTIMIZATIONSTART 311
#define OPTIMIZATIONEND 312
#define ITEMSTART 313
#define ITEMEND 314
#define ITEMSTARTANDEND 315
#define ITEMEMPTY 316
#define ACTUALSTARTTIMESTART 317
#define ACTUALSTARTTIMEEND 318
#define AVAILABLECPUNUMBERSTART 319
#define AVAILABLECPUNUMBEREND 320
#define AVAILABLECPUSPEEDSTART 321
#define AVAILABLECPUSPEEDEND 322
#define AVAILABLEDISKSPACESTART 323
#define AVAILABLEDISKSPACEEND 324
#define AVAILABLEMEMORYSTART 325
#define AVAILABLEMEMORYEND 326
#define BASISSTATUSSTART 327
#define BASISSTATUSEND 328
#define BASSTATUSSTART 329
#define BASSTATUSEND 330
#define CONSTART 331
#define CONEND 332
#define CONSTRAINTSSTART 333
#define CONSTRAINTSEND 334
#define CURRENTJOBCOUNTSTART 335
#define CURRENTJOBCOUNTEND 336
#define CURRENTSTATESTART 337
#define CURRENTSTATEEND 338
#define DUALVALUESSTART 339
#define DUALVALUESEND 340
#define ENDTIMESTART 341
#define ENDTIMEEND 342
#define GENERALSTATUSSTART 343
#define GENERALSTATUSEND 344
#define GENERALSUBSTATUSSTART 345
#define GENERALSUBSTATUSEND 346
#define INSTANCENAMESTART 347
#define INSTANCENAMEEND 348
#define JOBIDSTART 349
#define JOBIDEND 350
#define MESSAGESTART 351
#define MESSAGEEND 352
#define OBJSTART 353
#define OBJEND 354
#define OBJECTIVESSTART 355
#define OBJECTIVESEND 356
#define OPTIMIZATIONSOLUTIONSTATUSSTART 357
#define OPTIMIZATIONSOLUTIONSTATUSEND 358
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 359
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 360
#define OTHERSTART 361
#define OTHEREND 362
#define OTHERRESULTSSTART 363
#define OTHERRESULTSEND 364
#define OTHERSOLUTIONRESULTSTART 365
#define OTHERSOLUTIONRESULTEND 366
#define OTHERSOLUTIONRESULTSSTART 367
#define OTHERSOLUTIONRESULTSEND 368
#define OTHERSOLVEROUTPUTSTART 369
#define OTHERSOLVEROUTPUTEND 370
#define SCHEDULEDSTARTTIMESTART 371
#define SCHEDULEDSTARTTIMEEND 372
#define SERVICENAMESTART 373
#define SERVICENAMEEND 374
#define SERVICEURISTART 375
#define SERVICEURIEND 376
#define SERVICEUTILIZATIONSTART 377
#define SERVICEUTILIZATIONEND 378
#define SOLUTIONSTART 379
#define SOLUTIONEND 380
#define SOLVERINVOKEDSTART 381
#define SOLVERINVOKEDEND 382
#define SOLVEROUTPUTSTART 383
#define SOLVEROUTPUTEND 384
#define STATUSSTART 385
#define STATUSEND 386
#define SUBMITTIMESTART 387
#define SUBMITTIMEEND 388
#define SUBSTATUSSTART 389
#define SUBSTATUSEND 390
#define SYSTEMINFORMATIONSTART 391
#define SYSTEMINFORMATIONEND 392
#define TIMESTART 393
#define TIMEEND 394
#define TIMESERVICESTARTEDSTART 395
#define TIMESERVICESTARTEDEND 396
#define TIMESTAMPSTART 397
#define TIMESTAMPEND 398
#define TIMINGINFORMATIONSTART 399
#define TIMINGINFORMATIONEND 400
#define TOTALJOBSSOFARSTART 401
#define TOTALJOBSSOFAREND 402
#define USEDCPUNUMBERSTART 403
#define USEDCPUNUMBEREND 404
#define USEDCPUSPEEDSTART 405
#define USEDCPUSPEEDEND 406
#define USEDDISKSPACESTART 407
#define USEDDISKSPACEEND 408
#define USEDMEMORYSTART 409
#define USEDMEMORYEND 410
#define VALUESSTART 411
#define VALUESEND 412
#define VALUESSTRINGSTART 413
#define VALUESSTRINGEND 414
#define VARSTART 415
#define VAREND 416
#define VARIABLESSTART 417
#define VARIABLESEND 418
#define DUMMY 419




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
#define YYLAST   931

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  332
/* YYNRULES -- Number of rules.  */
#define YYNRULES  624
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1050

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   419

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   166,
     168,     2,     2,   167,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   165,     2,     2,     2,     2,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    11,    14,    18,    19,    22,    27,    28,
      31,    33,    35,    37,    39,    41,    43,    45,    47,    49,
      53,    55,    57,    59,    62,    64,    66,    68,    72,    74,
      78,    80,    85,    87,    89,    92,    94,    98,   100,   103,
     107,   109,   110,   113,   115,   117,   121,   125,   127,   130,
     132,   137,   141,   144,   149,   153,   156,   161,   165,   168,
     173,   177,   180,   185,   189,   192,   197,   201,   204,   209,
     213,   216,   220,   222,   227,   229,   231,   234,   236,   240,
     242,   245,   249,   251,   252,   255,   257,   259,   261,   265,
     269,   271,   275,   277,   280,   282,   283,   286,   291,   292,
     295,   297,   299,   301,   303,   305,   307,   312,   316,   319,
     325,   327,   328,   331,   333,   335,   339,   343,   345,   347,
     349,   355,   357,   358,   361,   363,   365,   369,   373,   375,
     377,   379,   385,   387,   388,   391,   393,   395,   399,   403,
     405,   407,   409,   415,   417,   418,   420,   424,   426,   428,
     432,   434,   439,   441,   443,   446,   448,   452,   454,   457,
     461,   463,   464,   467,   469,   471,   473,   477,   481,   483,
     487,   489,   492,   494,   495,   498,   503,   504,   507,   509,
     511,   513,   515,   517,   519,   524,   528,   531,   536,   540,
     543,   548,   552,   555,   560,   564,   567,   572,   576,   579,
     583,   588,   590,   592,   595,   597,   601,   603,   606,   610,
     611,   614,   616,   618,   620,   624,   628,   630,   634,   636,
     639,   641,   642,   645,   650,   651,   654,   656,   658,   660,
     662,   664,   666,   668,   670,   672,   674,   676,   681,   685,
     688,   693,   697,   700,   705,   709,   712,   717,   721,   724,
     729,   733,   736,   740,   745,   747,   751,   752,   755,   759,
     760,   763,   765,   767,   769,   771,   775,   777,   781,   783,
     787,   789,   793,   795,   797,   799,   802,   804,   808,   809,
     811,   813,   819,   820,   823,   825,   827,   831,   835,   837,
     839,   841,   847,   848,   851,   855,   857,   859,   861,   867,
     868,   871,   873,   875,   879,   883,   885,   887,   889,   895,
     896,   899,   901,   903,   907,   911,   913,   915,   917,   921,
     926,   928,   930,   933,   935,   939,   941,   944,   948,   949,
     952,   954,   956,   958,   962,   966,   968,   972,   974,   977,
     979,   980,   984,   985,   988,   991,   994,   997,  1000,  1004,
    1008,  1012,  1016,  1020,  1022,  1025,  1026,  1029,  1033,  1035,
    1036,  1039,  1041,  1043,  1048,  1052,  1061,  1065,  1067,  1070,
    1074,  1076,  1080,  1082,  1087,  1089,  1091,  1094,  1096,  1100,
    1102,  1105,  1109,  1110,  1113,  1115,  1117,  1121,  1125,  1127,
    1130,  1132,  1133,  1138,  1142,  1145,  1146,  1150,  1151,  1156,
    1158,  1160,  1162,  1169,  1170,  1176,  1180,  1185,  1186,  1189,
    1195,  1200,  1202,  1204,  1205,  1211,  1215,  1220,  1221,  1224,
    1230,  1235,  1239,  1244,  1245,  1251,  1255,  1260,  1261,  1264,
    1270,  1275,  1276,  1279,  1280,  1285,  1287,  1289,  1290,  1293,
    1295,  1297,  1299,  1301,  1306,  1308,  1312,  1314,  1318,  1322,
    1324,  1326,  1330,  1331,  1334,  1338,  1340,  1345,  1349,  1352,
    1354,  1355,  1359,  1360,  1365,  1367,  1369,  1371,  1376,  1377,
    1383,  1387,  1392,  1393,  1396,  1402,  1407,  1409,  1411,  1412,
    1415,  1419,  1421,  1422,  1425,  1427,  1429,  1431,  1433,  1438,
    1440,  1444,  1446,  1450,  1454,  1456,  1458,  1462,  1463,  1466,
    1470,  1472,  1477,  1481,  1484,  1486,  1487,  1491,  1492,  1497,
    1499,  1501,  1503,  1508,  1509,  1515,  1519,  1524,  1525,  1528,
    1534,  1539,  1541,  1543,  1544,  1547,  1551,  1553,  1554,  1557,
    1559,  1561,  1563,  1565,  1570,  1572,  1576,  1578,  1582,  1586,
    1588,  1590,  1594,  1595,  1598,  1602,  1604,  1609,  1613,  1616,
    1618,  1619,  1625,  1629,  1630,  1636,  1637,  1640,  1646,  1650,
    1651,  1652,  1656,  1658,  1660,  1662,  1664,  1669,  1671,  1675,
    1679,  1681,  1685,  1687,  1688,  1691,  1693,  1695,  1697,  1699,
    1700,  1705,  1707,  1708,  1712,  1717,  1719,  1723,  1724,  1727,
    1733,  1737,  1738,  1739,  1743,  1745,  1747,  1749,  1751,  1756,
    1758,  1762,  1766,  1768,  1772,  1774,  1775,  1778,  1780,  1782,
    1784,  1786,  1787,  1792,  1794,  1796,  1799,  1801,  1803,  1805,
    1807,  1809,  1811,  1813,  1814
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   216,   261,   282,   340,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   194,    -1,   195,    -1,   196,    -1,   197,
      -1,   198,    -1,   199,    -1,   200,    -1,   201,    -1,   176,
     177,   183,    -1,    88,    -1,   178,    -1,   179,    -1,   178,
     179,    -1,   180,    -1,   181,    -1,   182,    -1,    36,     3,
     497,    -1,    37,    -1,    32,     3,   497,    -1,    33,    -1,
      24,     8,     6,     8,    -1,   184,    -1,   185,    -1,    10,
      89,    -1,    11,    -1,    10,   186,    89,    -1,   187,    -1,
     186,   187,    -1,   188,   189,   193,    -1,   134,    -1,    -1,
     189,   190,    -1,   191,    -1,   192,    -1,    34,     3,     8,
      -1,    32,     3,     8,    -1,    33,    -1,    10,   135,    -1,
      11,    -1,    96,    10,     4,    97,    -1,    96,    10,    97,
      -1,    96,    11,    -1,   120,    10,     4,   121,    -1,   120,
      10,   121,    -1,   120,    11,    -1,   118,    10,     4,   119,
      -1,   118,    10,   119,    -1,   118,    11,    -1,    92,    10,
       4,    93,    -1,    92,    10,    93,    -1,    92,    11,    -1,
      94,    10,     4,    95,    -1,    94,    10,    95,    -1,    94,
      11,    -1,   126,    10,     4,   127,    -1,   126,    10,   127,
      -1,   126,    11,    -1,   142,    10,     4,   143,    -1,   142,
      10,   143,    -1,   142,    11,    -1,   202,   203,   204,    -1,
     108,    -1,    19,   497,     6,   497,    -1,   205,    -1,   206,
      -1,    10,   109,    -1,    11,    -1,    10,   207,   109,    -1,
     208,    -1,   207,   208,    -1,   209,   210,   215,    -1,   106,
      -1,    -1,   210,   211,    -1,   212,    -1,   213,    -1,   214,
      -1,    34,     3,   497,    -1,    40,     3,   497,    -1,    41,
      -1,    32,     3,   497,    -1,    33,    -1,    10,   107,    -1,
      11,    -1,    -1,    50,    11,    -1,    50,    10,   217,    51,
      -1,    -1,   217,   218,    -1,   219,    -1,   220,    -1,   227,
      -1,   234,    -1,   241,    -1,   246,    -1,   136,    10,     4,
     137,    -1,   136,    10,   137,    -1,   136,    11,    -1,   221,
     222,    10,   226,    69,    -1,    68,    -1,    -1,   222,   223,
      -1,   224,    -1,   225,    -1,    38,     3,   497,    -1,    32,
       3,   497,    -1,    33,    -1,     6,    -1,     7,    -1,   228,
     229,    10,   233,    71,    -1,    70,    -1,    -1,   229,   230,
      -1,   231,    -1,   232,    -1,    38,     3,   497,    -1,    32,
       3,   497,    -1,    33,    -1,     6,    -1,     7,    -1,   235,
     236,    10,   240,    67,    -1,    66,    -1,    -1,   236,   237,
      -1,   238,    -1,   239,    -1,    38,     3,   497,    -1,    32,
       3,   497,    -1,    33,    -1,     6,    -1,     7,    -1,   242,
     243,    10,   245,    65,    -1,    64,    -1,    -1,   244,    -1,
      32,     3,   497,    -1,    33,    -1,     6,    -1,   247,   248,
     249,    -1,   108,    -1,    19,   497,     6,   497,    -1,   250,
      -1,   251,    -1,    10,   109,    -1,    11,    -1,    10,   252,
     109,    -1,   253,    -1,   252,   253,    -1,   254,   255,   260,
      -1,   106,    -1,    -1,   255,   256,    -1,   257,    -1,   258,
      -1,   259,    -1,    34,     3,   497,    -1,    40,     3,   497,
      -1,    41,    -1,    32,     3,   497,    -1,    33,    -1,    10,
     107,    -1,    11,    -1,    -1,    52,    11,    -1,    52,    10,
     262,    53,    -1,    -1,   262,   263,    -1,   264,    -1,   265,
      -1,   266,    -1,   267,    -1,   268,    -1,   269,    -1,    82,
      10,     4,    83,    -1,    82,    10,    83,    -1,    82,    11,
      -1,    80,    10,     6,    81,    -1,    80,    10,    81,    -1,
      80,    11,    -1,   146,    10,     6,   147,    -1,   146,    10,
     147,    -1,   146,    11,    -1,   140,    10,     4,   141,    -1,
     140,    10,   141,    -1,   140,    11,    -1,   122,    10,   496,
     123,    -1,   122,    10,   123,    -1,   122,    11,    -1,   108,
     270,   271,    -1,    19,   497,     6,   497,    -1,   272,    -1,
     273,    -1,    10,   109,    -1,    11,    -1,    10,   274,   109,
      -1,   275,    -1,   274,   275,    -1,   106,   276,   281,    -1,
      -1,   276,   277,    -1,   278,    -1,   279,    -1,   280,    -1,
      34,     3,   497,    -1,    40,     3,   497,    -1,    41,    -1,
      32,     3,   497,    -1,    33,    -1,    10,   107,    -1,    11,
      -1,    -1,    54,    11,    -1,    54,    10,   283,    55,    -1,
      -1,   283,   284,    -1,   285,    -1,   286,    -1,   287,    -1,
     288,    -1,   289,    -1,   290,    -1,   305,    -1,   311,    -1,
     315,    -1,   321,    -1,   327,    -1,   130,    10,     4,   131,
      -1,   130,    10,   131,    -1,   130,    11,    -1,   132,    10,
       4,   133,    -1,   132,    10,   133,    -1,   132,    11,    -1,
     116,    10,     4,   117,    -1,   116,    10,   117,    -1,   116,
      11,    -1,    62,    10,     4,    63,    -1,    62,    10,    63,
      -1,    62,    11,    -1,    86,    10,     4,    87,    -1,    86,
      10,    87,    -1,    86,    11,    -1,   144,   291,   292,    -1,
      25,     8,     6,     8,    -1,    11,    -1,    10,   293,   145,
      -1,    -1,   293,   294,    -1,   138,   295,   301,    -1,    -1,
     295,   296,    -1,   297,    -1,   298,    -1,   299,    -1,   300,
      -1,    36,     3,     8,    -1,    37,    -1,    30,     3,     8,
      -1,    31,    -1,    38,     3,     8,    -1,    39,    -1,    32,
       3,     8,    -1,    33,    -1,   302,    -1,   303,    -1,    10,
     139,    -1,    11,    -1,    10,   304,   139,    -1,    -1,     7,
      -1,     6,    -1,   150,   306,    10,   310,   151,    -1,    -1,
     306,   307,    -1,   308,    -1,   309,    -1,    38,     3,   497,
      -1,    32,     3,   497,    -1,    33,    -1,     6,    -1,     7,
      -1,   148,   312,    10,   314,   149,    -1,    -1,   312,   313,
      -1,    32,     3,   497,    -1,    33,    -1,     6,    -1,     7,
      -1,   152,   316,    10,   320,   153,    -1,    -1,   316,   317,
      -1,   318,    -1,   319,    -1,    38,     3,   497,    -1,    32,
       3,   497,    -1,    33,    -1,     6,    -1,     7,    -1,   154,
     322,    10,   326,   155,    -1,    -1,   322,   323,    -1,   324,
      -1,   325,    -1,    38,     3,   497,    -1,    32,     3,   497,
      -1,    33,    -1,     6,    -1,     7,    -1,   108,   328,   329,
      -1,    19,   497,     6,   497,    -1,   330,    -1,   331,    -1,
      10,   109,    -1,    11,    -1,    10,   332,   109,    -1,   333,
      -1,   332,   333,    -1,   106,   334,   339,    -1,    -1,   334,
     335,    -1,   336,    -1,   337,    -1,   338,    -1,    34,     3,
     497,    -1,    40,     3,   497,    -1,    41,    -1,    32,     3,
     497,    -1,    33,    -1,    10,   107,    -1,    11,    -1,    -1,
      56,   341,   347,    -1,    -1,   341,   342,    -1,   343,   497,
      -1,   344,   497,    -1,   345,   497,    -1,   346,   497,    -1,
      22,   497,     6,    -1,    27,   497,     6,    -1,    13,   497,
       6,    -1,    16,   497,     6,    -1,    10,   348,    57,    -1,
      11,    -1,   349,   479,    -1,    -1,   349,   350,    -1,   351,
     352,   356,    -1,   124,    -1,    -1,   352,   353,    -1,   354,
      -1,   355,    -1,    28,   497,     6,   497,    -1,    42,     3,
     497,    -1,    10,   357,   370,   371,   409,   435,   461,   478,
      -1,   130,   358,   360,    -1,   359,    -1,   358,   359,    -1,
      36,     3,   497,    -1,    37,    -1,    32,     3,   497,    -1,
      33,    -1,    24,     8,     6,     8,    -1,   361,    -1,   362,
      -1,    10,   131,    -1,    11,    -1,    10,   363,   131,    -1,
     364,    -1,   363,   364,    -1,   134,   365,   369,    -1,    -1,
     365,   366,    -1,   367,    -1,   368,    -1,    36,     3,     8,
      -1,    32,     3,     8,    -1,    33,    -1,    10,   135,    -1,
      11,    -1,    -1,    96,    10,     4,    97,    -1,    96,    10,
      97,    -1,    96,    11,    -1,    -1,   162,   372,   373,    -1,
      -1,    21,   497,     6,   497,    -1,   374,    -1,   375,    -1,
      11,    -1,    10,   376,   382,   387,   392,   163,    -1,    -1,
     156,   377,    10,   378,   157,    -1,   156,   377,    11,    -1,
      26,   497,     6,   497,    -1,    -1,   378,   379,    -1,   160,
     380,    10,   381,   161,    -1,    29,   497,     6,   497,    -1,
       6,    -1,     7,    -1,    -1,   158,   383,    10,   384,   159,
      -1,   158,   383,    11,    -1,    26,   497,     6,   497,    -1,
      -1,   384,   385,    -1,   160,   386,    10,     4,   161,    -1,
     160,   386,    10,   161,    -1,   160,   386,    11,    -1,    29,
     497,     6,   497,    -1,    -1,    72,   388,    10,   389,    73,
      -1,    72,   388,    11,    -1,    26,   497,     6,   497,    -1,
      -1,   389,   390,    -1,   160,   391,    10,     4,   161,    -1,
      29,   497,     6,   497,    -1,    -1,   392,   393,    -1,    -1,
     395,   396,   394,   403,    -1,   106,    -1,   397,    -1,    -1,
     397,   398,    -1,   399,    -1,   400,    -1,   401,    -1,   402,
      -1,    26,   497,     6,   497,    -1,    41,    -1,    40,     3,
     497,    -1,    35,    -1,    34,     3,   497,    -1,    32,     3,
     497,    -1,    33,    -1,    11,    -1,    10,   404,   107,    -1,
      -1,   404,   405,    -1,   406,   407,   408,    -1,   160,    -1,
      29,   497,     6,   497,    -1,    10,   498,   161,    -1,    10,
     161,    -1,    11,    -1,    -1,   100,   410,   411,    -1,    -1,
      18,   497,     6,   497,    -1,   412,    -1,   413,    -1,    11,
      -1,    10,   414,   420,   101,    -1,    -1,   156,   415,    10,
     416,   157,    -1,   156,   415,    11,    -1,    15,   497,     6,
     497,    -1,    -1,   416,   417,    -1,    98,   418,    10,   419,
      99,    -1,    29,   497,     6,   497,    -1,     6,    -1,     7,
      -1,    -1,   420,   421,    -1,   422,   423,   429,    -1,   106,
      -1,    -1,   423,   424,    -1,   425,    -1,   426,    -1,   427,
      -1,   428,    -1,    15,   497,     6,   497,    -1,    41,    -1,
      40,     3,   497,    -1,    35,    -1,    34,     3,   497,    -1,
      32,     3,   497,    -1,    33,    -1,    11,    -1,    10,   430,
     107,    -1,    -1,   430,   431,    -1,   432,   433,   434,    -1,
      98,    -1,    29,   497,     6,   497,    -1,    10,   498,    99,
      -1,    10,    99,    -1,    11,    -1,    -1,    78,   436,   437,
      -1,    -1,    17,   497,     6,   497,    -1,   438,    -1,   439,
      -1,    11,    -1,    10,   440,   446,    79,    -1,    -1,    84,
     441,    10,   442,    85,    -1,    84,   441,    11,    -1,    12,
     497,     6,   497,    -1,    -1,   442,   443,    -1,    76,   444,
      10,   445,    77,    -1,    29,   497,     6,   497,    -1,     7,
      -1,     6,    -1,    -1,   446,   447,    -1,   448,   449,   455,
      -1,   106,    -1,    -1,   449,   450,    -1,   451,    -1,   452,
      -1,   453,    -1,   454,    -1,    12,   497,     6,   497,    -1,
      41,    -1,    40,     3,   497,    -1,    35,    -1,    34,     3,
     497,    -1,    32,     3,   497,    -1,    33,    -1,    11,    -1,
      10,   456,   107,    -1,    -1,   456,   457,    -1,   458,   459,
     460,    -1,    76,    -1,    29,   497,     6,   497,    -1,    10,
     498,    77,    -1,    10,    77,    -1,    11,    -1,    -1,   112,
     462,    10,   464,   113,    -1,   112,   462,    11,    -1,    -1,
      20,     8,     6,   463,     8,    -1,    -1,   464,   465,    -1,
     110,   466,    10,   473,   111,    -1,   110,   466,    11,    -1,
      -1,    -1,   466,   467,   468,    -1,   469,    -1,   470,    -1,
     471,    -1,   472,    -1,    14,     8,     6,     8,    -1,    35,
      -1,    34,     3,   497,    -1,    30,     3,     8,    -1,    31,
      -1,    32,     3,     8,    -1,    33,    -1,    -1,   473,   474,
      -1,   475,    -1,   476,    -1,    60,    -1,    61,    -1,    -1,
      58,     5,   477,    59,    -1,   125,    -1,    -1,   114,   480,
     481,    -1,    23,   497,     6,   497,    -1,    11,    -1,    10,
     482,   115,    -1,    -1,   482,   483,    -1,   128,   484,    10,
     491,   129,    -1,   128,   484,    11,    -1,    -1,    -1,   484,
     485,   486,    -1,   487,    -1,   488,    -1,   489,    -1,   490,
      -1,    14,     8,     6,     8,    -1,    35,    -1,    34,     3,
       8,    -1,    30,     3,     8,    -1,    31,    -1,    32,     3,
       8,    -1,    33,    -1,    -1,   491,   492,    -1,   493,    -1,
     494,    -1,    60,    -1,    61,    -1,    -1,    58,     5,   495,
      59,    -1,     6,    -1,     7,    -1,   500,     8,    -1,     4,
      -1,     6,    -1,     7,    -1,   165,    -1,   166,    -1,   167,
      -1,   168,    -1,    -1,   500,   499,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   166,   167,   169,   169,   170,   172,   172,
     175,   180,   185,   190,   195,   200,   205,   210,   215,   223,
     225,   231,   237,   237,   240,   250,   256,   260,   261,   263,
     264,   266,   277,   281,   287,   287,   289,   291,   291,   293,
     301,   306,   306,   308,   308,   315,   325,   328,   333,   333,
     337,   338,   339,   342,   343,   344,   347,   348,   349,   352,
     353,   354,   357,   358,   359,   362,   364,   365,   368,   370,
     371,   373,   378,   380,   386,   386,   388,   388,   390,   392,
     392,   394,   403,   408,   408,   411,   417,   423,   431,   433,
     434,   436,   437,   439,   439,   443,   443,   444,   446,   446,
     449,   454,   455,   456,   457,   458,   466,   467,   468,   470,
     473,   479,   479,   481,   481,   483,   492,   494,   497,   498,
     500,   503,   509,   509,   511,   511,   513,   521,   523,   526,
     527,   529,   532,   538,   538,   540,   540,   542,   554,   556,
     559,   560,   563,   566,   572,   572,   574,   576,   579,   582,
     587,   589,   595,   595,   597,   597,   599,   601,   601,   603,
     612,   617,   617,   620,   626,   632,   640,   642,   643,   645,
     646,   648,   648,   652,   652,   653,   655,   655,   657,   657,
     657,   658,   658,   658,   661,   662,   663,   666,   667,   668,
     671,   672,   673,   676,   677,   678,   681,   682,   683,   686,
     688,   690,   690,   692,   692,   694,   696,   696,   698,   700,
     700,   702,   702,   702,   704,   706,   707,   709,   710,   712,
     712,   715,   715,   716,   718,   718,   720,   720,   720,   720,
     720,   721,   721,   721,   721,   721,   721,   724,   725,   726,
     729,   730,   731,   734,   735,   736,   739,   740,   741,   744,
     745,   746,   749,   751,   757,   757,   759,   759,   761,   763,
     763,   765,   765,   765,   765,   767,   768,   770,   771,   773,
     774,   776,   777,   779,   779,   781,   781,   783,   794,   798,
     799,   802,   805,   805,   807,   807,   809,   811,   812,   815,
     816,   819,   822,   822,   824,   825,   828,   829,   832,   835,
     835,   837,   837,   839,   841,   842,   845,   846,   848,   851,
     851,   853,   853,   855,   857,   858,   861,   862,   866,   868,
     870,   870,   872,   872,   874,   876,   876,   878,   880,   880,
     882,   882,   882,   884,   886,   887,   889,   890,   892,   892,
     896,   896,   898,   898,   900,   901,   902,   903,   907,   908,
     909,   910,   913,   913,   915,   917,   917,   919,   926,   932,
     932,   934,   934,   936,   943,   946,   949,   951,   952,   954,
     955,   956,   957,   958,   961,   967,   973,   973,   975,   977,
     977,   979,   981,   981,   983,   983,   985,   989,   990,   992,
     992,   996,   997,  1001,  1005,  1007,  1008,  1010,  1011,  1021,
    1021,  1023,  1025,  1027,  1028,  1037,  1048,  1055,  1055,  1057,
    1059,  1062,  1066,  1072,  1073,  1082,  1084,  1091,  1091,  1093,
    1098,  1099,  1101,  1105,  1105,  1114,  1116,  1123,  1123,  1125,
    1127,  1132,  1132,  1135,  1134,  1154,  1162,  1168,  1168,  1170,
    1170,  1170,  1170,  1172,  1184,  1187,  1193,  1199,  1205,  1210,
    1212,  1213,  1215,  1215,  1217,  1232,  1237,  1239,  1239,  1239,
    1242,  1243,  1245,  1246,  1256,  1256,  1258,  1260,  1262,  1263,
    1272,  1274,  1278,  1278,  1280,  1282,  1285,  1289,  1295,  1295,
    1297,  1300,  1308,  1309,  1311,  1311,  1311,  1311,  1313,  1322,
    1325,  1331,  1337,  1343,  1348,  1351,  1352,  1374,  1374,  1376,
    1391,  1396,  1398,  1398,  1398,  1402,  1403,  1405,  1406,  1416,
    1416,  1418,  1420,  1423,  1424,  1434,  1436,  1441,  1441,  1443,
    1445,  1448,  1452,  1458,  1458,  1460,  1463,  1465,  1465,  1467,
    1467,  1467,  1467,  1469,  1472,  1475,  1481,  1487,  1493,  1498,
    1500,  1501,  1504,  1504,  1506,  1522,  1527,  1529,  1529,  1529,
    1533,  1534,  1539,  1546,  1545,  1561,  1561,  1564,  1571,  1580,
    1581,  1581,  1585,  1585,  1585,  1585,  1587,  1600,  1606,  1614,
    1617,  1620,  1623,  1625,  1626,  1629,  1634,  1641,  1641,  1644,
    1643,  1649,  1659,  1659,  1661,  1663,  1663,  1665,  1665,  1668,
    1675,  1677,  1679,  1678,  1683,  1683,  1683,  1683,  1685,  1700,
    1707,  1716,  1722,  1725,  1731,  1733,  1734,  1736,  1741,  1747,
    1747,  1750,  1749,  1755,  1756,  1758,  1761,  1762,  1763,  1767,
    1768,  1769,  1770,  1772,  1773
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "GREATERTHAN",
  "ENDOFELEMENT", "NUMBEROFCONATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFITEMSATT", "NUMBEROFOBJATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFOTHERCONSTRAINTRESULTSATT", "NUMBEROFOTHEROBJECTIVERESULTSATT",
  "NUMBEROFOTHERRESULTSATT", "NUMBEROFOTHERSOLUTIONRESULTSATT",
  "NUMBEROFOTHERVARIABLERESULTSATT", "NUMBEROFSOLUTIONSATT",
  "NUMBEROFSOLVEROUTPUTSATT", "NUMBEROFSUBSTATUSESATT", "NUMBEROFTIMESATT",
  "NUMBEROFVARATT", "NUMBEROFVARIABLESATT", "TARGETOBJECTIVEIDXATT",
  "IDXATT", "CATEGORYATT", "EMPTYCATEGORYATT", "DESCRIPTIONATT",
  "EMPTYDESCRIPTIONATT", "NAMEATT", "EMPTYNAMEATT", "TYPEATT",
  "EMPTYTYPEATT", "UNITATT", "EMPTYUNITATT", "VALUEATT", "EMPTYVALUEATT",
  "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT", "OSRLSTART",
  "OSRLSTARTEMPTY", "OSRLATTRIBUTETEXT", "OSRLEND", "GENERALSTART",
  "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND",
  "JOBSTART", "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
  "ITEMSTART", "ITEMEND", "ITEMSTARTANDEND", "ITEMEMPTY",
  "ACTUALSTARTTIMESTART", "ACTUALSTARTTIMEEND", "AVAILABLECPUNUMBERSTART",
  "AVAILABLECPUNUMBEREND", "AVAILABLECPUSPEEDSTART",
  "AVAILABLECPUSPEEDEND", "AVAILABLEDISKSPACESTART",
  "AVAILABLEDISKSPACEEND", "AVAILABLEMEMORYSTART", "AVAILABLEMEMORYEND",
  "BASISSTATUSSTART", "BASISSTATUSEND", "BASSTATUSSTART", "BASSTATUSEND",
  "CONSTART", "CONEND", "CONSTRAINTSSTART", "CONSTRAINTSEND",
  "CURRENTJOBCOUNTSTART", "CURRENTJOBCOUNTEND", "CURRENTSTATESTART",
  "CURRENTSTATEEND", "DUALVALUESSTART", "DUALVALUESEND", "ENDTIMESTART",
  "ENDTIMEEND", "GENERALSTATUSSTART", "GENERALSTATUSEND",
  "GENERALSUBSTATUSSTART", "GENERALSUBSTATUSEND", "INSTANCENAMESTART",
  "INSTANCENAMEEND", "JOBIDSTART", "JOBIDEND", "MESSAGESTART",
  "MESSAGEEND", "OBJSTART", "OBJEND", "OBJECTIVESSTART", "OBJECTIVESEND",
  "OPTIMIZATIONSOLUTIONSTATUSSTART", "OPTIMIZATIONSOLUTIONSTATUSEND",
  "OPTIMIZATIONSOLUTIONSUBSTATUSSTART", "OPTIMIZATIONSOLUTIONSUBSTATUSEND",
  "OTHERSTART", "OTHEREND", "OTHERRESULTSSTART", "OTHERRESULTSEND",
  "OTHERSOLUTIONRESULTSTART", "OTHERSOLUTIONRESULTEND",
  "OTHERSOLUTIONRESULTSSTART", "OTHERSOLUTIONRESULTSEND",
  "OTHERSOLVEROUTPUTSTART", "OTHERSOLVEROUTPUTEND",
  "SCHEDULEDSTARTTIMESTART", "SCHEDULEDSTARTTIMEEND", "SERVICENAMESTART",
  "SERVICENAMEEND", "SERVICEURISTART", "SERVICEURIEND",
  "SERVICEUTILIZATIONSTART", "SERVICEUTILIZATIONEND", "SOLUTIONSTART",
  "SOLUTIONEND", "SOLVERINVOKEDSTART", "SOLVERINVOKEDEND",
  "SOLVEROUTPUTSTART", "SOLVEROUTPUTEND", "STATUSSTART", "STATUSEND",
  "SUBMITTIMESTART", "SUBMITTIMEEND", "SUBSTATUSSTART", "SUBSTATUSEND",
  "SYSTEMINFORMATIONSTART", "SYSTEMINFORMATIONEND", "TIMESTART", "TIMEEND",
  "TIMESERVICESTARTEDSTART", "TIMESERVICESTARTEDEND", "TIMESTAMPSTART",
  "TIMESTAMPEND", "TIMINGINFORMATIONSTART", "TIMINGINFORMATIONEND",
  "TOTALJOBSSOFARSTART", "TOTALJOBSSOFAREND", "USEDCPUNUMBERSTART",
  "USEDCPUNUMBEREND", "USEDCPUSPEEDSTART", "USEDCPUSPEEDEND",
  "USEDDISKSPACESTART", "USEDDISKSPACEEND", "USEDMEMORYSTART",
  "USEDMEMORYEND", "VALUESSTART", "VALUESEND", "VALUESSTRINGSTART",
  "VALUESSTRINGEND", "VARSTART", "VAREND", "VARIABLESSTART",
  "VARIABLESEND", "DUMMY", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
  "osrldoc", "osrlstart", "generalElement", "generalContent",
  "generalChild", "generalStatus", "generalStatusStart",
  "generalStatusAttributes", "generalStatusAttList", "generalStatusATT",
  "generalStatusTypeATT", "generalStatusDescriptionATT",
  "generalStatusNumberOfATT", "generalStatusContent", "generalStatusEmpty",
  "generalStatusBody", "generalSubstatusSEQ", "generalSubstatus",
  "generalSubstatusStart", "generalSubstatusAttList",
  "generalSubstatusATT", "generalSubstatusNameATT",
  "generalSubstatusDescriptionATT", "generalSubstatusEnd",
  "generalMessage", "serviceURI", "serviceName", "instanceName", "jobID",
  "solverInvoked", "timeStamp", "generalOtherResults",
  "generalOtherResultsStart", "generalOtherResultsAttList",
  "generalOtherResultsContent", "generalOtherResultsEmpty",
  "generalOtherResultsBody", "generalOtherResultSEQ", "generalOtherResult",
  "generalOtherResultStart", "generalOtherAttList", "generalOtherAtt",
  "generalOtherNameATT", "generalOtherValueATT",
  "generalOtherDescriptionATT", "generalOtherEnd", "systemElement",
  "systemContent", "systemChild", "systemInformation",
  "availableDiskSpace", "availableDiskSpaceStart",
  "availableDiskSpaceAttList", "availableDiskSpaceAtt",
  "availableDiskSpaceUnitATT", "availableDiskSpaceDescriptionATT",
  "availableDiskSpaceValue", "availableMemory", "availableMemoryStart",
  "availableMemoryAttList", "availableMemoryAtt", "availableMemoryUnitATT",
  "availableMemoryDescriptionATT", "availableMemoryValue",
  "availableCPUSpeed", "availableCPUSpeedStart",
  "availableCPUSpeedAttList", "availableCPUSpeedAtt",
  "availableCPUSpeedUnitATT", "availableCPUSpeedDescriptionATT",
  "availableCPUSpeedValue", "availableCPUNumber",
  "availableCPUNumberStart", "availableCPUNumberAttList",
  "availableCPUNumberDescriptionATT", "availableCPUNumberValue",
  "systemOtherResults", "systemOtherResultsStart",
  "systemOtherResultsAttList", "systemOtherResultsContent",
  "systemOtherResultsEmpty", "systemOtherResultsBody",
  "systemOtherResultSEQ", "systemOtherResult", "systemOtherResultStart",
  "systemOtherAttList", "systemOtherAtt", "systemOtherNameATT",
  "systemOtherValueATT", "systemOtherDescriptionATT", "systemOtherEnd",
  "serviceElement", "serviceContent", "serviceChild", "currentState",
  "currentJobCount", "totalJobsSoFar", "timeServiceStarted",
  "serviceUtilization", "serviceOtherResults",
  "serviceOtherResultsAttList", "serviceOtherResultsBody",
  "serviceOtherResultsEmpty", "serviceOtherResultsContent",
  "serviceOtherResultList", "serviceOtherResult", "serviceOtherAttList",
  "serviceOtherAtt", "serviceOtherNameATT", "serviceOtherValueATT",
  "serviceOtherDescriptionATT", "serviceOtherEnd", "jobElement",
  "jobContent", "jobChild", "status", "submitTime", "scheduledStartTime",
  "actualStartTime", "endTime", "timingInformation", "numberoftimes",
  "timingContent", "listOfTimes", "time", "timeAttList", "timeAtt",
  "timeType", "timeCategory", "timeUnit", "timeDescription",
  "restOfTimeElement", "timeEmpty", "timeContent", "timeValue",
  "usedCPUSpeed", "usedCPUSpeedAttList", "usedCPUSpeedAtt",
  "usedCPUSpeedUnitATT", "usedCPUSpeedDescriptionATT", "usedCPUSpeedValue",
  "usedCPUNumber", "usedCPUNumberAttList", "usedCPUNumberDescriptionATT",
  "usedCPUNumberValue", "usedDiskSpace", "usedDiskSpaceAttList",
  "usedDiskSpaceAtt", "usedDiskSpaceUnitATT",
  "usedDiskSpaceDescriptionATT", "usedDiskSpaceValue", "usedMemory",
  "usedMemoryAttList", "usedMemoryAtt", "usedMemoryUnitATT",
  "usedMemoryDescriptionATT", "usedMemoryValue", "jobOtherResults",
  "jobOtherResultsAttList", "jobOtherResultsBody", "jobOtherResultsEmpty",
  "jobOtherResultsContent", "jobOtherResultList", "jobOtherResult",
  "jobOtherAttList", "jobOtherAtt", "jobOtherNameATT", "jobOtherValueATT",
  "jobOtherDescriptionATT", "jobOtherEnd", "optimizationElement",
  "optimizationAttList", "optimizationATT",
  "optimizationNumberOfSolutionsATT", "optimizationNumberOfVariablesATT",
  "optimizationNumberOfConstraintsATT",
  "optimizationNumberOfObjectivesATT", "optimizationBody",
  "optimizationContent", "solutionList", "solution", "solutionStart",
  "solutionAttList", "solutionATT", "targetObjectiveIdxATT",
  "weightedObjectivesATT", "solutionBody", "solutionStatus",
  "solutionStatusAttList", "solutionStatusATT", "solutionStatusContent",
  "solutionStatusEmpty", "solutionStatusBody", "solutionSubstatusSEQ",
  "solutionSubstatus", "solutionSubstatusAttList", "solutionSubstatusATT",
  "solutionSubstatusTypeATT", "solutionSubstatusDescriptionATT",
  "solutionSubstatusEnd", "solutionMessage", "variables",
  "numberOfOtherVariableResults", "variablesBody", "variablesEmpty",
  "variablesContent", "variableValues", "numberOfVarATT", "varValueList",
  "varValue", "varIdxATT", "varVal", "variableValuesString",
  "numberOfVarStringATT", "varValueStringList", "varValueString",
  "varStrIdxATT", "basisStatus", "numberOfBasisVarATT", "basisVarList",
  "basisVar", "basisVarIdxATT", "otherVariablesSEQ", "otherVariableResult",
  "@1", "otherVariableStart", "otherVariableAttributes",
  "otherVariableAttList", "otherVariableATT", "numberOfOtherVarATT",
  "otherVarValueATT", "otherVarNameATT", "otherVarDescriptionATT",
  "otherVariableResultContent", "otherVarList", "otherVar",
  "otherVarStart", "otherVarIdxATT", "otherVarContent", "objectives",
  "numberOfOtherObjectiveResults", "objectivesBody", "objectivesEmpty",
  "objectivesContent", "objectiveValues", "numberOfObjATT", "objValueList",
  "objValue", "objIdxATT", "objVal", "otherObjectivesSEQ",
  "otherObjectiveResult", "otherObjectiveStart", "otherObjectiveAttList",
  "otherObjectiveATT", "numberOfOtherObjATT", "otherObjValueATT",
  "otherObjNameATT", "otherObjDescriptionATT",
  "otherObjectiveResultContent", "otherObjList", "otherObj",
  "otherObjStart", "otherObjIdxATT", "otherObjContent", "constraints",
  "numberOfOtherConstraintResults", "constraintsBody", "constraintsEmpty",
  "constraintsContent", "dualValues", "numberOfConATT", "dualValueList",
  "dualValue", "conIdxATT", "dualVal", "otherConstraintsSEQ",
  "otherConstraintResult", "otherConstraintStart",
  "otherConstraintAttList", "otherConstraintATT", "numberOfOtherConATT",
  "otherConValueATT", "otherConNameATT", "otherConDescriptionATT",
  "otherConstraintResultContent", "otherConList", "otherCon",
  "otherConStart", "otherConIdxATT", "otherConContent",
  "otherSolutionResults", "numberOfOtherSolutionResults", "@2",
  "otherSolutionResultList", "anotherSolutionResult",
  "anotherSolutionResultAttList", "@3", "anotherSolutionResultAtt",
  "numberOfOtherSolutionResultItems", "anotherSolutionResultNameATT",
  "anotherSolutionResultCategoryATT", "anotherSolutionDescriptionATT",
  "anotherSolutionItemList", "anotherSolutionItem",
  "otherSolutionItemEmpty", "otherSolutionItemContent", "@4",
  "solutionEnd", "otherSolverOutput", "numberOfSolverOutputsATT",
  "otherSolverOutputBody", "solverOutputSEQ", "solverOutput",
  "solverOutputAttList", "@5", "solverOutputAtt",
  "numberOfSolverOutputItems", "solverOutputNameATT",
  "solverOutputCategoryATT", "solverOutputDescriptionATT",
  "solverOutputItemList", "solverOutputItem", "solverOutputItemEmpty",
  "solverOutputItemContent", "@6", "aNumber", "quote", "ElementValue",
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
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   169,   170,   171,   171,   172,   172,   172,   173,   173,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   175,
     176,   177,   178,   178,   179,   179,   179,   180,   180,   181,
     181,   182,   183,   183,   184,   184,   185,   186,   186,   187,
     188,   189,   189,   190,   190,   191,   192,   192,   193,   193,
     194,   194,   194,   195,   195,   195,   196,   196,   196,   197,
     197,   197,   198,   198,   198,   199,   199,   199,   200,   200,
     200,   201,   202,   203,   204,   204,   205,   205,   206,   207,
     207,   208,   209,   210,   210,   211,   211,   211,   212,   213,
     213,   214,   214,   215,   215,   216,   216,   216,   217,   217,
     218,   218,   218,   218,   218,   218,   219,   219,   219,   220,
     221,   222,   222,   223,   223,   224,   225,   225,   226,   226,
     227,   228,   229,   229,   230,   230,   231,   232,   232,   233,
     233,   234,   235,   236,   236,   237,   237,   238,   239,   239,
     240,   240,   241,   242,   243,   243,   244,   244,   245,   246,
     247,   248,   249,   249,   250,   250,   251,   252,   252,   253,
     254,   255,   255,   256,   256,   256,   257,   258,   258,   259,
     259,   260,   260,   261,   261,   261,   262,   262,   263,   263,
     263,   263,   263,   263,   264,   264,   264,   265,   265,   265,
     266,   266,   266,   267,   267,   267,   268,   268,   268,   269,
     270,   271,   271,   272,   272,   273,   274,   274,   275,   276,
     276,   277,   277,   277,   278,   279,   279,   280,   280,   281,
     281,   282,   282,   282,   283,   283,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   285,   285,   285,
     286,   286,   286,   287,   287,   287,   288,   288,   288,   289,
     289,   289,   290,   291,   292,   292,   293,   293,   294,   295,
     295,   296,   296,   296,   296,   297,   297,   298,   298,   299,
     299,   300,   300,   301,   301,   302,   302,   303,   303,   304,
     304,   305,   306,   306,   307,   307,   308,   309,   309,   310,
     310,   311,   312,   312,   313,   313,   314,   314,   315,   316,
     316,   317,   317,   318,   319,   319,   320,   320,   321,   322,
     322,   323,   323,   324,   325,   325,   326,   326,   327,   328,
     329,   329,   330,   330,   331,   332,   332,   333,   334,   334,
     335,   335,   335,   336,   337,   337,   338,   338,   339,   339,
     340,   340,   341,   341,   342,   342,   342,   342,   343,   344,
     345,   346,   347,   347,   348,   349,   349,   350,   351,   352,
     352,   353,   353,   354,   355,   356,   357,   358,   358,   359,
     359,   359,   359,   359,   360,   360,   361,   361,   362,   363,
     363,   364,   365,   365,   366,   366,   367,   368,   368,   369,
     369,   370,   370,   370,   370,   371,   371,   372,   372,   373,
     373,   374,   375,   376,   376,   376,   377,   378,   378,   379,
     380,   381,   381,   382,   382,   382,   383,   384,   384,   385,
     385,   385,   386,   387,   387,   387,   388,   389,   389,   390,
     391,   392,   392,   394,   393,   395,   396,   397,   397,   398,
     398,   398,   398,   399,   400,   400,   401,   401,   402,   402,
     403,   403,   404,   404,   405,   406,   407,   408,   408,   408,
     409,   409,   410,   410,   411,   411,   412,   413,   414,   414,
     414,   415,   416,   416,   417,   418,   419,   419,   420,   420,
     421,   422,   423,   423,   424,   424,   424,   424,   425,   426,
     426,   427,   427,   428,   428,   429,   429,   430,   430,   431,
     432,   433,   434,   434,   434,   435,   435,   436,   436,   437,
     437,   438,   439,   440,   440,   440,   441,   442,   442,   443,
     444,   445,   445,   446,   446,   447,   448,   449,   449,   450,
     450,   450,   450,   451,   452,   452,   453,   453,   454,   454,
     455,   455,   456,   456,   457,   458,   459,   460,   460,   460,
     461,   461,   461,   463,   462,   464,   464,   465,   465,   466,
     467,   466,   468,   468,   468,   468,   469,   470,   470,   471,
     471,   472,   472,   473,   473,   474,   474,   475,   475,   477,
     476,   478,   479,   479,   480,   481,   481,   482,   482,   483,
     483,   484,   485,   484,   486,   486,   486,   486,   487,   488,
     488,   489,   489,   490,   490,   491,   491,   492,   492,   493,
     493,   495,   494,   496,   496,   497,   498,   498,   498,   499,
     499,   499,   499,   500,   500
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     3,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     3,     1,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       1,     0,     2,     1,     1,     3,     3,     1,     2,     1,
       4,     3,     2,     4,     3,     2,     4,     3,     2,     4,
       3,     2,     4,     3,     2,     4,     3,     2,     4,     3,
       2,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       2,     3,     1,     0,     2,     1,     1,     1,     3,     3,
       1,     3,     1,     2,     1,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     4,     3,     2,     5,
       1,     0,     2,     1,     1,     3,     3,     1,     1,     1,
       5,     1,     0,     2,     1,     1,     3,     3,     1,     1,
       1,     5,     1,     0,     2,     1,     1,     3,     3,     1,
       1,     1,     5,     1,     0,     1,     3,     1,     1,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       1,     0,     2,     1,     1,     1,     3,     3,     1,     3,
       1,     2,     1,     0,     2,     4,     0,     2,     1,     1,
       1,     1,     1,     1,     4,     3,     2,     4,     3,     2,
       4,     3,     2,     4,     3,     2,     4,     3,     2,     3,
       4,     1,     1,     2,     1,     3,     1,     2,     3,     0,
       2,     1,     1,     1,     3,     3,     1,     3,     1,     2,
       1,     0,     2,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     2,
       4,     3,     2,     4,     3,     2,     4,     3,     2,     4,
       3,     2,     3,     4,     1,     3,     0,     2,     3,     0,
       2,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     2,     1,     3,     0,     1,
       1,     5,     0,     2,     1,     1,     3,     3,     1,     1,
       1,     5,     0,     2,     3,     1,     1,     1,     5,     0,
       2,     1,     1,     3,     3,     1,     1,     1,     5,     0,
       2,     1,     1,     3,     3,     1,     1,     1,     3,     4,
       1,     1,     2,     1,     3,     1,     2,     3,     0,     2,
       1,     1,     1,     3,     3,     1,     3,     1,     2,     1,
       0,     3,     0,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     1,     2,     0,     2,     3,     1,     0,
       2,     1,     1,     4,     3,     8,     3,     1,     2,     3,
       1,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       2,     3,     0,     2,     1,     1,     3,     3,     1,     2,
       1,     0,     4,     3,     2,     0,     3,     0,     4,     1,
       1,     1,     6,     0,     5,     3,     4,     0,     2,     5,
       4,     1,     1,     0,     5,     3,     4,     0,     2,     5,
       4,     3,     4,     0,     5,     3,     4,     0,     2,     5,
       4,     0,     2,     0,     4,     1,     1,     0,     2,     1,
       1,     1,     1,     4,     1,     3,     1,     3,     3,     1,
       1,     3,     0,     2,     3,     1,     4,     3,     2,     1,
       0,     3,     0,     4,     1,     1,     1,     4,     0,     5,
       3,     4,     0,     2,     5,     4,     1,     1,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     1,     4,     1,
       3,     1,     3,     3,     1,     1,     3,     0,     2,     3,
       1,     4,     3,     2,     1,     0,     3,     0,     4,     1,
       1,     1,     4,     0,     5,     3,     4,     0,     2,     5,
       4,     1,     1,     0,     2,     3,     1,     0,     2,     1,
       1,     1,     1,     4,     1,     3,     1,     3,     3,     1,
       1,     3,     0,     2,     3,     1,     4,     3,     2,     1,
       0,     5,     3,     0,     5,     0,     2,     5,     3,     0,
       0,     3,     1,     1,     1,     1,     4,     1,     3,     3,
       1,     3,     1,     0,     2,     1,     1,     1,     1,     0,
       4,     1,     0,     3,     4,     1,     3,     0,     2,     5,
       3,     0,     0,     3,     1,     1,     1,     1,     4,     1,
       3,     3,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     0,     4,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    95,     4,
       8,     6,     0,   173,     0,    98,    96,     0,   221,     7,
      20,     0,     0,     0,    72,     0,     0,     0,     0,     9,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,   176,   174,     0,   340,     0,    61,     0,    64,
       0,    52,     0,    58,     0,    55,     0,    67,     0,    70,
       0,     0,    30,     0,    28,     0,    21,    22,    24,    25,
      26,   623,     0,    97,   143,   132,   110,   121,   150,     0,
      99,   100,   101,   111,   102,   122,   103,   133,   104,   144,
     105,     0,     0,   224,   222,   342,     0,     0,    60,     0,
      63,     0,    51,     0,    57,     0,    54,     0,    66,     0,
      69,     0,   623,   623,     0,    35,    19,    32,    33,    23,
       0,     0,     0,    77,    71,    74,    75,     0,   108,     0,
       0,     0,     0,   147,     0,   145,   623,     0,   175,     0,
       0,     0,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,     0,     0,     2,    59,    62,    50,    56,    53,
      65,    68,     0,    29,    27,    34,    40,     0,    37,    41,
     623,   615,   619,   620,   621,   622,   624,    82,    76,     0,
      79,    83,     0,   107,     0,     0,   117,     0,   112,   113,
     114,     0,     0,   128,     0,   123,   124,   125,     0,     0,
     139,     0,   134,   135,   136,   623,     0,     0,     0,   155,
     149,   152,   153,     0,   189,     0,   186,   623,     0,     0,
     198,     0,   195,     0,   192,   223,     0,     0,     0,     0,
       0,     0,     0,   292,   282,   299,   309,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   355,
     353,   623,   623,   623,   623,   343,   623,   623,   623,   623,
     341,    31,    36,    38,     0,    73,    78,    80,     0,   106,
     118,   119,     0,   623,   623,   129,   130,     0,   623,   623,
     140,   141,     0,   623,   623,   146,   148,     0,   623,   160,
     154,     0,   157,   161,     0,   188,     0,   185,     0,     0,
     204,   199,   201,   202,   613,   614,   197,     0,     0,   194,
       0,   191,     0,   248,     0,   251,   623,     0,     0,   245,
       0,   239,     0,   242,     0,     0,     0,     0,     0,     0,
       0,   582,     0,     0,     0,     0,   344,   345,   346,   347,
       0,    49,     0,    47,     0,    42,    43,    44,    39,     0,
      94,     0,    92,     0,     0,    90,    84,    85,    86,    87,
      81,   109,   116,   115,   120,   127,   126,   131,   138,   137,
     142,   151,   156,   158,     0,   187,   184,   623,   209,   203,
       0,   206,   196,   193,   190,     0,   247,     0,   250,     0,
       0,   323,   318,   320,   321,     0,   244,     0,   238,     0,
     241,     0,   256,   254,   252,     0,     0,   295,   293,     0,
       0,   288,     0,   283,   284,   285,     0,     0,   305,     0,
     300,   301,   302,     0,     0,   315,     0,   310,   311,   312,
     352,     0,   358,   356,   359,   354,   350,   351,   348,   349,
      48,     0,     0,    93,   623,   623,   623,     0,   172,     0,
     170,     0,     0,   168,   162,   163,   164,   165,   159,   200,
       0,   205,   207,   246,   249,   623,   328,   322,     0,   325,
     243,   237,   240,     0,     0,   296,   297,     0,   623,   289,
     290,     0,   623,   623,   306,   307,     0,   623,   623,   316,
     317,     0,   623,   623,   623,     0,     0,    46,    45,    91,
      88,    89,   171,   623,   623,   623,     0,   220,     0,   218,
       0,     0,   216,   210,   211,   212,   213,   208,   319,     0,
     324,   326,   253,   259,   255,   257,   291,   294,   281,   287,
     286,   298,   304,   303,   308,   314,   313,     0,   587,   585,
     583,     0,   623,     0,   360,   361,   362,   357,   169,   166,
     167,   219,   623,   623,   623,     0,   339,     0,   337,     0,
       0,   335,   329,   330,   331,   332,   327,   278,   623,     0,
       0,   391,     0,   623,   217,   214,   215,   338,   623,   623,
     623,     0,   276,     0,   268,     0,   272,     0,   266,     0,
     270,   260,   261,   262,   263,   264,   258,   273,   274,   584,
     586,   591,   588,     0,     0,   372,     0,   370,     0,   367,
       0,   395,   623,   364,   336,   333,   334,   280,   279,   275,
       0,     0,     0,     0,     0,   592,     0,   623,   623,     0,
     377,   368,   366,   374,   375,     0,   394,   397,   460,   363,
     277,   267,   271,   265,   269,   605,   590,     0,     0,   371,
     369,   376,   382,     0,   379,     0,   393,   623,     0,   462,
     505,     0,     0,     0,   602,     0,   604,     0,   599,   593,
     594,   595,   596,   597,   373,     0,   378,   380,   392,     0,
     403,   401,   396,   399,   400,   623,     0,   507,   550,     0,
     609,   610,   589,   606,   607,   608,     0,     0,     0,     0,
       0,   390,     0,   388,     0,   383,   384,   385,   381,   623,
       0,   413,     0,   468,   466,   461,   464,   465,   623,     0,
       0,     0,   611,     0,   601,   603,   600,   389,     0,     0,
     398,   623,     0,     0,   423,   623,     0,   478,     0,   513,
     511,   506,   509,   510,     0,     0,   581,   365,     0,   598,
     387,   386,     0,   407,   405,   623,     0,     0,   431,   463,
     623,     0,     0,   623,     0,   523,     0,   555,   552,   612,
     623,     0,     0,   417,   415,   623,     0,     0,     0,   472,
     470,   467,   481,   479,   482,   508,   623,     0,     0,   553,
       0,   406,   404,     0,   408,   623,     0,     0,   427,   425,
     435,   402,   432,   437,   623,     0,     0,     0,   517,   515,
     512,   526,   524,   527,     0,   559,   551,   556,   623,     0,
     416,   414,     0,   418,   623,     0,   433,   436,   471,     0,
     469,   473,   497,   495,   623,     0,   494,     0,   491,     0,
     489,   483,   484,   485,   486,   487,   480,   623,     0,     0,
     554,   560,     0,     0,   623,     0,   426,   424,     0,   428,
       0,   623,     0,   449,     0,   446,     0,   444,   438,   439,
     440,   441,   442,   623,     0,     0,     0,   623,   623,   623,
     516,     0,   514,   518,   542,   540,   623,     0,   539,     0,
     536,     0,   534,   528,   529,   530,   531,   532,   525,   573,
     558,     0,   623,   411,   412,     0,     0,     0,   421,   623,
       0,   452,   450,   434,     0,   623,   623,   623,     0,     0,
     500,   496,   498,     0,   623,   493,   492,   490,   623,     0,
       0,     0,   623,   623,   623,     0,     0,     0,   570,     0,
     572,     0,   567,   561,   562,   563,   564,   565,   410,   409,
     623,     0,   420,     0,     0,     0,   623,   448,   447,   445,
     623,   476,   477,     0,   623,     0,   488,     0,     0,   545,
     541,   543,     0,   623,   538,   537,   535,     0,   577,   578,
     557,   574,   575,   576,     0,     0,     0,   623,   422,   419,
     623,     0,   451,   455,   453,     0,   443,   475,   474,     0,
       0,   504,   499,   623,   522,   521,     0,   623,     0,   533,
     579,     0,   569,   571,   568,   430,   429,   623,     0,   623,
     616,   617,   618,   503,     0,   520,   519,     0,     0,   549,
     544,     0,   566,     0,     0,   459,   454,   501,   502,   623,
     548,     0,   580,   623,   458,     0,   546,   547,   456,   457
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    31,    65,    66,
      67,    68,    69,    70,   116,   117,   118,   167,   168,   169,
     264,   345,   346,   347,   348,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    72,   124,   125,   126,   179,   180,
     181,   268,   356,   357,   358,   359,   360,    13,    41,    80,
      81,    82,    83,   129,   188,   189,   190,   272,    84,    85,
     130,   195,   196,   197,   277,    86,    87,   131,   202,   203,
     204,   282,    88,    89,   134,   135,   287,    90,    91,   137,
     210,   211,   212,   291,   292,   293,   374,   454,   455,   456,
     457,   458,    18,    92,   145,   146,   147,   148,   149,   150,
     151,   218,   301,   302,   303,   380,   381,   460,   513,   514,
     515,   516,   517,    45,   152,   237,   238,   239,   240,   241,
     242,   243,   325,   404,   474,   525,   567,   591,   592,   593,
     594,   595,   596,   597,   598,   620,   244,   327,   413,   414,
     415,   481,   245,   326,   408,   477,   246,   328,   420,   421,
     422,   486,   247,   329,   427,   428,   429,   491,   248,   317,
     392,   393,   394,   468,   469,   519,   562,   563,   564,   565,
     566,    96,   153,   255,   256,   257,   258,   259,   260,   330,
     331,   433,   434,   496,   544,   545,   546,   547,   571,   608,
     609,   632,   633,   634,   653,   654,   675,   705,   706,   707,
     708,   611,   638,   658,   682,   683,   684,   711,   732,   771,
     794,   819,   905,   734,   756,   796,   823,   855,   758,   776,
     825,   859,   910,   777,   802,   860,   803,   826,   827,   868,
     869,   870,   871,   872,   913,   955,   994,   995,  1018,  1036,
     660,   686,   715,   716,   717,   737,   761,   805,   831,   874,
     963,   762,   783,   784,   806,   841,   842,   843,   844,   845,
     846,   875,   922,   923,   965,  1002,   688,   719,   741,   742,
     743,   765,   787,   848,   883,   929,  1006,   788,   812,   813,
     849,   893,   894,   895,   896,   897,   898,   930,   971,   972,
    1008,  1030,   721,   745,   814,   790,   817,   851,   901,   943,
     944,   945,   946,   947,   935,   981,   982,   983,  1031,   747,
     435,   495,   540,   569,   602,   625,   647,   669,   670,   671,
     672,   673,   661,   693,   694,   695,   748,   307,   120,  1024,
     176,   121
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -948
static const yytype_int16 yypact[] =
{
      33,    37,    62,   -11,  -948,    74,  -948,   171,   103,  -948,
    -948,  -948,   207,   118,   -23,  -948,  -948,   224,   101,  -948,
    -948,   232,   274,   317,  -948,   337,   351,   353,   357,  -948,
    -948,    43,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
     156,    -7,  -948,  -948,   362,   136,    30,  -948,    32,  -948,
      27,  -948,    19,  -948,     9,  -948,     7,  -948,     6,  -948,
     200,   233,  -948,   253,  -948,   367,    43,  -948,  -948,  -948,
    -948,  -948,   373,  -948,  -948,  -948,  -948,  -948,  -948,   375,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,   355,
    -948,   260,   -14,  -948,  -948,  -948,   246,   196,  -948,   206,
    -948,   239,  -948,   250,  -948,   222,  -948,   231,  -948,   236,
    -948,   359,  -948,  -948,   -44,  -948,  -948,  -948,  -948,  -948,
     368,    12,    48,  -948,  -948,  -948,  -948,    15,  -948,   163,
     221,   238,   426,  -948,   445,  -948,  -948,   379,  -948,   384,
     386,   391,   388,   390,   392,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,   -34,   308,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,   471,  -948,  -948,  -948,  -948,   -25,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,   138,
    -948,  -948,   300,  -948,   398,   487,  -948,   490,  -948,  -948,
    -948,   400,   491,  -948,   492,  -948,  -948,  -948,   402,   493,
    -948,   494,  -948,  -948,  -948,  -948,   495,   496,   182,  -948,
    -948,  -948,  -948,    10,  -948,    21,  -948,  -948,   401,     8,
    -948,     2,  -948,     1,  -948,  -948,   403,   405,   479,   407,
     409,   411,   482,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,   271,  -948,  -948,  -948,   189,  -948,
    -948,  -948,   430,  -948,  -948,  -948,  -948,   432,  -948,  -948,
    -948,  -948,   438,  -948,  -948,  -948,  -948,   444,  -948,  -948,
    -948,   191,  -948,  -948,   423,  -948,   431,  -948,   500,   193,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,   385,   369,  -948,
     364,  -948,    29,  -948,    34,  -948,  -948,   413,    18,  -948,
       5,  -948,     4,  -948,   504,   415,    79,   242,   245,   254,
     456,   -54,   511,   512,   513,   514,  -948,  -948,  -948,  -948,
     387,  -948,   518,  -948,   520,  -948,  -948,  -948,  -948,   417,
    -948,   522,  -948,   523,   524,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,   192,  -948,  -948,  -948,  -948,  -948,
     214,  -948,  -948,  -948,  -948,   465,  -948,   442,  -948,   525,
     216,  -948,  -948,  -948,  -948,   416,  -948,   399,  -948,   404,
    -948,   526,  -948,  -948,  -948,   421,   531,  -948,  -948,   425,
     532,  -948,   533,  -948,  -948,  -948,   427,   535,  -948,   536,
    -948,  -948,  -948,   429,   537,  -948,   538,  -948,  -948,  -948,
    -948,   519,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,   539,   540,  -948,  -948,  -948,  -948,   436,  -948,   541,
    -948,   543,   546,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
     205,  -948,  -948,  -948,  -948,  -948,  -948,  -948,   220,  -948,
    -948,  -948,  -948,   542,    13,  -948,  -948,   406,  -948,  -948,
    -948,   408,  -948,  -948,  -948,  -948,   410,  -948,  -948,  -948,
    -948,   396,  -948,  -948,  -948,   428,    44,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,   446,  -948,   549,  -948,
     551,   553,  -948,  -948,  -948,  -948,  -948,  -948,  -948,   217,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,   552,  -948,  -948,
    -948,   434,  -948,   554,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,   453,  -948,   558,  -948,   559,
     562,  -948,  -948,  -948,  -948,  -948,  -948,   230,  -948,     0,
     318,   472,   560,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,    11,  -948,   564,  -948,   566,  -948,   567,  -948,   568,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,   569,   571,  -948,   572,  -948,   173,  -948,
     433,   414,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
     440,   570,   573,   574,   575,   435,   578,  -948,  -948,   210,
    -948,  -948,  -948,  -948,  -948,    28,  -948,   565,   485,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,   276,   579,  -948,
    -948,  -948,  -948,   218,  -948,   475,  -948,  -948,   437,   576,
     502,   -12,   580,   586,  -948,   587,  -948,   588,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,   262,  -948,  -948,  -948,   589,
     448,  -948,  -948,  -948,  -948,  -948,   439,   581,   484,   594,
    -948,  -948,  -948,  -948,  -948,  -948,   595,   584,   585,   592,
     468,  -948,   599,  -948,   602,  -948,  -948,  -948,  -948,  -948,
     582,   451,   601,   455,  -948,  -948,  -948,  -948,  -948,   441,
     590,   488,  -948,   604,  -948,  -948,  -948,  -948,   606,   607,
    -948,  -948,   443,   591,   544,  -948,   603,  -948,   614,   545,
    -948,  -948,  -948,  -948,   613,   447,  -948,  -948,   563,  -948,
    -948,  -948,   618,  -948,  -948,  -948,   449,   600,  -948,  -948,
    -948,   452,    68,  -948,   615,  -948,   619,  -948,  -948,  -948,
    -948,   199,   622,  -948,  -948,  -948,   454,   -56,   624,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,   459,   -28,  -948,
     247,  -948,  -948,   605,  -948,  -948,   312,   625,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,   -57,   153,   626,  -948,  -948,
    -948,  -948,  -948,  -948,   627,  -948,  -948,  -948,  -948,   623,
    -948,  -948,   608,  -948,  -948,   -61,  -948,   305,  -948,   609,
    -948,  -948,  -948,  -948,  -948,   633,  -948,   636,  -948,   637,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,    80,   179,
    -948,   463,   635,   469,  -948,   467,  -948,  -948,   616,  -948,
     470,  -948,   639,  -948,   641,  -948,   643,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,   640,   100,   646,  -948,  -948,  -948,
    -948,   620,  -948,  -948,  -948,  -948,  -948,   644,  -948,   650,
    -948,   651,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,   282,  -948,  -948,  -948,   498,   649,    -1,  -948,  -948,
     647,  -948,  -948,  -948,   654,  -948,  -948,  -948,   655,   476,
    -948,  -948,  -948,   638,  -948,  -948,  -948,  -948,  -948,   652,
      26,   658,  -948,  -948,  -948,    -5,   648,   662,  -948,   663,
    -948,   665,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,   508,  -948,   664,   667,   -72,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,   577,  -948,   474,  -948,   666,   480,  -948,
    -948,  -948,   653,  -948,  -948,  -948,  -948,   668,  -948,  -948,
    -948,  -948,  -948,  -948,   669,   670,   671,  -948,  -948,  -948,
    -948,   516,  -948,  -948,  -948,   656,  -948,  -948,  -948,   674,
      23,  -948,  -948,  -948,  -948,  -948,   610,  -948,   478,  -948,
    -948,   673,  -948,  -948,  -948,  -948,  -948,  -948,   481,  -948,
    -948,  -948,  -948,  -948,   596,  -948,  -948,   678,    36,  -948,
    -948,   629,  -948,   680,    -2,  -948,  -948,  -948,  -948,  -948,
    -948,   612,  -948,  -948,  -948,   529,  -948,  -948,  -948,  -948
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
     628,  -948,  -948,  -948,  -948,  -948,  -948,  -948,   530,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,   517,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,   412,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,   311,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,   225,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
      90,  -948,  -948,  -948,  -948,    46,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -112,  -947,
    -948,  -948
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     163,   164,  1020,   951,  1021,  1022,   308,   310,   399,   397,
     109,   107,   857,   105,   304,   305,   294,   617,   618,   182,
     171,   225,   395,   103,   207,   296,    19,  1020,   226,  1021,
    1022,   101,   655,   385,    97,   992,    99,     7,   387,   138,
    1020,   829,  1021,  1022,    73,   165,   689,     4,   690,   691,
     800,   810,   227,   977,   541,   978,   979,    74,   265,    75,
     431,    76,     6,    77,   262,    20,   139,    60,   140,    21,
     432,    22,   542,    23,   228,    61,    62,     1,   811,    63,
      64,  1041,   229,     5,     9,    24,   543,  1045,   993,   405,
     166,   295,   386,   285,   141,    25,   230,    26,   231,   858,
     830,    78,   969,    27,   297,   298,   980,   801,   142,   166,
     232,   406,   407,  1040,   233,   600,   234,   692,   235,    28,
     236,   388,  1023,    98,   102,   656,   143,   100,   601,    79,
     106,   306,   144,   970,   108,   396,   398,   400,   104,   332,
     333,   334,   335,   309,   336,   337,   338,   339,   311,   110,
     619,   523,   183,    12,   177,    44,   881,   178,   524,  1044,
     952,   362,   363,   832,   833,   882,   365,   366,   834,   781,
      17,   368,   369,   184,   782,    71,   371,   172,   173,   174,
     175,    10,    11,   629,   630,   835,   836,   837,   838,   884,
     885,   886,    95,   839,   840,   185,   186,   603,   920,   349,
     350,   187,   447,   448,   389,   604,   605,   921,   111,   606,
     607,   887,   888,   889,   890,   506,   507,    15,    16,   891,
     892,   351,   352,   353,   449,   450,   451,   555,   556,   354,
     355,   191,   452,   453,    42,    43,   112,   508,   509,   510,
     581,   582,    46,    47,   177,   511,   512,   266,   198,   557,
     558,   559,   409,   192,   193,   416,   113,   560,   561,   194,
     583,   584,   585,   586,   423,   459,   587,   588,   589,   590,
     199,   200,   700,   701,   410,   411,   201,   417,   418,   136,
     412,   340,   341,   419,    48,    49,   424,   425,   289,   155,
     662,   290,   426,   154,   702,   703,   936,   289,   704,   378,
     372,   156,   379,   342,   343,   344,   663,   664,   665,   666,
     667,   668,   937,   938,   939,   940,   941,   942,   249,   250,
     378,   251,   466,   461,   252,   467,   466,    50,    51,   520,
     253,   861,   499,   500,   501,   254,   157,   862,   863,   864,
     865,   651,   603,   159,   652,   866,   867,    52,    53,   676,
     604,   605,   652,   518,   606,   607,   792,   815,   160,   793,
     816,    54,    55,    56,    57,   162,   527,    58,    59,   158,
     529,   530,    93,    94,   170,   532,   533,   114,   115,   161,
     535,   536,   537,   122,   123,   127,   128,   132,   133,   208,
     209,   548,   549,   550,   213,   214,   215,   216,   219,   220,
     221,   222,   223,   224,   270,   271,   275,   276,   280,   281,
     217,   299,   300,   312,   313,   314,   315,   318,   319,   320,
     321,   322,   323,   390,   391,   402,   403,   475,   476,   205,
     572,   479,   480,   484,   485,   489,   490,   269,   538,   539,
     574,   575,   576,   635,   636,   645,   646,   680,   681,   713,
     714,   739,   740,   753,   754,   206,   599,   767,   768,   773,
     774,   613,   779,   780,   798,   799,   614,   615,   616,   808,
     809,   821,   822,   899,   900,   903,   904,   907,   908,   261,
     911,   912,   961,   962,  1000,  1001,  1004,  1005,  1028,  1029,
     273,  1034,  1035,   274,   278,   279,   283,   284,   316,   361,
     639,   286,   288,   364,   375,   367,   377,   324,   382,   370,
     383,   384,   401,   430,   376,   649,   650,   436,   437,   438,
     439,   441,   440,   442,   443,   444,   445,   446,   463,   464,
     471,   465,   473,   470,   478,   482,   483,   472,   487,   488,
     492,   493,   494,   502,   503,   679,   504,   497,   498,   505,
     522,   534,   552,   551,   553,   526,   554,   573,   568,   528,
     577,   578,   579,   531,   570,   580,   612,   621,   610,   622,
     623,   624,   678,   712,   627,   628,   637,   626,   641,   640,
     687,   642,   643,   644,   648,   659,   657,   674,   696,   697,
     698,   699,   724,   725,   685,   709,   720,   730,   718,   722,
     726,   723,   728,   727,   710,   729,   738,   735,   731,   733,
     744,   736,   749,   746,   750,   751,   757,   755,   760,   752,
     763,   766,   769,   759,   770,   789,   775,   786,   795,   764,
     804,   824,   847,   853,   818,   850,   877,   854,   873,   878,
     879,   902,   915,   772,   916,   909,   917,   932,   778,   928,
     919,   785,   924,   933,   934,   950,   984,   954,   791,   949,
     956,   960,   968,   797,   973,   985,   986,   964,   987,   989,
     990,   991,  1003,  1010,   807,  1011,   998,  1016,  1012,  1013,
    1019,  1032,  1007,   820,  1039,  1017,  1043,  1026,  1042,  1047,
    1049,   462,   828,   521,   119,  1038,   267,   263,   631,   677,
       0,     0,     0,   373,     0,     0,   852,     0,     0,     0,
       0,     0,   856,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   876,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   880,     0,     0,     0,     0,
       0,     0,   906,     0,     0,     0,     0,     0,     0,   914,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   918,     0,     0,     0,   925,   926,   927,     0,     0,
       0,     0,     0,     0,   931,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     948,     0,     0,     0,     0,     0,     0,   953,     0,     0,
       0,     0,     0,   957,   958,   959,     0,     0,     0,     0,
       0,     0,   966,     0,     0,     0,   967,     0,     0,     0,
     974,   975,   976,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   988,     0,
       0,     0,     0,     0,   996,     0,     0,     0,   997,     0,
       0,     0,   999,     0,     0,     0,     0,     0,     0,     0,
       0,  1009,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1014,     0,     0,  1015,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1025,     0,     0,     0,  1027,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1033,     0,  1037,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1046,     0,     0,
       0,  1048
};

static const yytype_int16 yycheck[] =
{
     112,   113,     4,     4,     6,     7,     4,     6,     4,     4,
       4,     4,    73,     4,     6,     7,     6,     6,     7,     4,
       8,    55,     4,     4,   136,     4,    49,     4,    62,     6,
       7,     4,     4,     4,     4,   107,     4,    48,     4,    53,
       4,    98,     6,     7,    51,    89,    58,    10,    60,    61,
     106,    79,    86,    58,    10,    60,    61,    64,   170,    66,
     114,    68,     0,    70,    89,    88,    80,    24,    82,    92,
     124,    94,    28,    96,   108,    32,    33,    44,   106,    36,
      37,  1028,   116,    46,    10,   108,    42,  1034,   160,    10,
     134,    81,    63,   205,   108,   118,   130,   120,   132,   160,
     157,   108,    76,   126,    83,   217,   111,   163,   122,   134,
     144,    32,    33,    77,   148,   115,   150,   129,   152,   142,
     154,    87,    99,    93,    97,    97,   140,    95,   128,   136,
     121,   123,   146,   107,   127,   117,   131,   133,   119,   251,
     252,   253,   254,   141,   256,   257,   258,   259,   147,   143,
     139,   138,   137,    50,   106,    54,    76,   109,   145,   161,
     161,   273,   274,    10,    11,    85,   278,   279,    15,   101,
      52,   283,   284,    10,   106,    19,   288,   165,   166,   167,
     168,    10,    11,    10,    11,    32,    33,    34,    35,    10,
      11,    12,    56,    40,    41,    32,    33,    24,    98,    10,
      11,    38,    10,    11,   316,    32,    33,   107,     8,    36,
      37,    32,    33,    34,    35,    10,    11,    10,    11,    40,
      41,    32,    33,    34,    32,    33,    34,    10,    11,    40,
      41,    10,    40,    41,    10,    11,     3,    32,    33,    34,
      10,    11,    10,    11,   106,    40,    41,   109,    10,    32,
      33,    34,    10,    32,    33,    10,     3,    40,    41,    38,
      30,    31,    32,    33,    10,   377,    36,    37,    38,    39,
      32,    33,    10,    11,    32,    33,    38,    32,    33,    19,
      38,    10,    11,    38,    10,    11,    32,    33,   106,    93,
      14,   109,    38,    47,    32,    33,    14,   106,    36,   106,
     109,    95,   109,    32,    33,    34,    30,    31,    32,    33,
      34,    35,    30,    31,    32,    33,    34,    35,    10,    11,
     106,    13,   106,   109,    16,   109,   106,    10,    11,   109,
      22,    26,   444,   445,   446,    27,    97,    32,    33,    34,
      35,   131,    24,   121,   134,    40,    41,    10,    11,   131,
      32,    33,   134,   465,    36,    37,   157,   110,   127,   160,
     113,    10,    11,    10,    11,     6,   478,    10,    11,   119,
     482,   483,    10,    11,     6,   487,   488,    10,    11,   143,
     492,   493,   494,    10,    11,    10,    11,    32,    33,    10,
      11,   503,   504,   505,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,     6,     7,     6,     7,     6,     7,
      19,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,     6,     7,     3,
     542,     6,     7,     6,     7,     6,     7,   137,    10,    11,
     552,   553,   554,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,   568,    10,    11,    10,
      11,   573,    10,    11,    10,    11,   578,   579,   580,    10,
      11,   159,   160,    10,    11,     6,     7,    10,    11,     8,
      10,    11,     6,     7,    10,    11,     6,     7,    10,    11,
       3,    10,    11,     3,     3,     3,     3,     3,    19,    69,
     612,     6,     6,    71,    81,    67,     6,    25,   123,    65,
     141,   147,     8,    57,    83,   627,   628,     6,     6,     6,
       6,     3,   135,     3,   107,     3,     3,     3,    63,    87,
     131,     6,     6,   117,     3,     3,     3,   133,     3,     3,
       3,     3,    23,   107,     3,   657,     3,     8,     8,     3,
       8,   155,     3,   107,     3,   149,     3,     3,     6,   151,
     107,     3,     3,   153,   130,     3,     6,     3,    96,     3,
       3,     3,    97,   685,     3,     3,   162,     8,     8,   139,
      78,     8,     8,     8,     6,   100,    21,     8,     8,     3,
       3,     3,     8,     8,    18,     6,   112,   709,    17,     5,
       8,     6,     3,   135,   156,     3,   718,     6,    26,   158,
      20,   156,     8,   125,     8,     8,    72,    26,    15,   731,
       6,     8,    59,   735,     6,     6,    26,    12,     6,    84,
       6,     6,     6,    10,    29,     8,     3,    29,    29,     3,
       3,     6,     3,   755,     3,    29,     3,     3,   760,    29,
      10,   763,     6,     3,     3,     6,     8,    10,   770,   161,
       6,     6,    10,   775,     6,     3,     3,    29,     3,   161,
       6,     4,     6,     5,   786,     6,    99,   161,     8,     8,
       6,     8,    29,   795,     6,    29,     6,    77,    59,    77,
     161,   380,   804,   468,    66,    99,   179,   167,   608,   653,
      -1,    -1,    -1,   291,    -1,    -1,   818,    -1,    -1,    -1,
      -1,    -1,   824,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   834,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   847,    -1,    -1,    -1,    -1,
      -1,    -1,   854,    -1,    -1,    -1,    -1,    -1,    -1,   861,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   873,    -1,    -1,    -1,   877,   878,   879,    -1,    -1,
      -1,    -1,    -1,    -1,   886,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     902,    -1,    -1,    -1,    -1,    -1,    -1,   909,    -1,    -1,
      -1,    -1,    -1,   915,   916,   917,    -1,    -1,    -1,    -1,
      -1,    -1,   924,    -1,    -1,    -1,   928,    -1,    -1,    -1,
     932,   933,   934,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   950,    -1,
      -1,    -1,    -1,    -1,   956,    -1,    -1,    -1,   960,    -1,
      -1,    -1,   964,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   973,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   987,    -1,    -1,   990,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1003,    -1,    -1,    -1,  1007,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1017,    -1,  1019,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1039,    -1,    -1,
      -1,  1043
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   216,   173,    10,    11,    52,   261,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   176,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   217,    10,    11,    54,   282,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      24,    32,    33,    36,    37,   177,   178,   179,   180,   181,
     182,    19,   203,    51,    64,    66,    68,    70,   108,   136,
     218,   219,   220,   221,   227,   228,   234,   235,   241,   242,
     246,   247,   262,    10,    11,    56,   340,     4,    93,     4,
      95,     4,    97,     4,   119,     4,   121,     4,   127,     4,
     143,     8,     3,     3,    10,    11,   183,   184,   185,   179,
     497,   500,    10,    11,   204,   205,   206,    10,    11,   222,
     229,   236,    32,    33,   243,   244,    19,   248,    53,    80,
      82,   108,   122,   140,   146,   263,   264,   265,   266,   267,
     268,   269,   283,   341,    47,    93,    95,    97,   119,   121,
     127,   143,     6,   497,   497,    89,   134,   186,   187,   188,
       6,     8,   165,   166,   167,   168,   499,   106,   109,   207,
     208,   209,     4,   137,    10,    32,    33,    38,   223,   224,
     225,    10,    32,    33,    38,   230,   231,   232,    10,    32,
      33,    38,   237,   238,   239,     3,    10,   497,    10,    11,
     249,   250,   251,    10,    11,    10,    11,    19,   270,    10,
      11,    10,    11,    10,    11,    55,    62,    86,   108,   116,
     130,   132,   144,   148,   150,   152,   154,   284,   285,   286,
     287,   288,   289,   290,   305,   311,   315,   321,   327,    10,
      11,    13,    16,    22,    27,   342,   343,   344,   345,   346,
     347,     8,    89,   187,   189,   497,   109,   208,   210,   137,
       6,     7,   226,     3,     3,     6,     7,   233,     3,     3,
       6,     7,   240,     3,     3,   497,     6,   245,     6,   106,
     109,   252,   253,   254,     6,    81,     4,    83,   497,    10,
      11,   271,   272,   273,     6,     7,   123,   496,     4,   141,
       6,   147,    10,    11,    10,    11,    19,   328,    10,    11,
      10,    11,    10,    11,    25,   291,   312,   306,   316,   322,
     348,   349,   497,   497,   497,   497,   497,   497,   497,   497,
      10,    11,    32,    33,    34,   190,   191,   192,   193,    10,
      11,    32,    33,    34,    40,    41,   211,   212,   213,   214,
     215,    69,   497,   497,    71,   497,   497,    67,   497,   497,
      65,   497,   109,   253,   255,    81,    83,     6,   106,   109,
     274,   275,   123,   141,   147,     4,    63,     4,    87,   497,
      10,    11,   329,   330,   331,     4,   117,     4,   131,     4,
     133,     8,    10,    11,   292,    10,    32,    33,   313,    10,
      32,    33,    38,   307,   308,   309,    10,    32,    33,    38,
     317,   318,   319,    10,    32,    33,    38,   323,   324,   325,
      57,   114,   124,   350,   351,   479,     6,     6,     6,     6,
     135,     3,     3,   107,     3,     3,     3,    10,    11,    32,
      33,    34,    40,    41,   256,   257,   258,   259,   260,   497,
     276,   109,   275,    63,    87,     6,   106,   109,   332,   333,
     117,   131,   133,     6,   293,     6,     7,   314,     3,     6,
       7,   310,     3,     3,     6,     7,   320,     3,     3,     6,
       7,   326,     3,     3,    23,   480,   352,     8,     8,   497,
     497,   497,   107,     3,     3,     3,    10,    11,    32,    33,
      34,    40,    41,   277,   278,   279,   280,   281,   497,   334,
     109,   333,     8,   138,   145,   294,   149,   497,   151,   497,
     497,   153,   497,   497,   155,   497,   497,   497,    10,    11,
     481,    10,    28,    42,   353,   354,   355,   356,   497,   497,
     497,   107,     3,     3,     3,    10,    11,    32,    33,    34,
      40,    41,   335,   336,   337,   338,   339,   295,     6,   482,
     130,   357,   497,     3,   497,   497,   497,   107,     3,     3,
       3,    10,    11,    30,    31,    32,    33,    36,    37,    38,
      39,   296,   297,   298,   299,   300,   301,   302,   303,   497,
     115,   128,   483,    24,    32,    33,    36,    37,   358,   359,
      96,   370,     6,   497,   497,   497,   497,     6,     7,   139,
     304,     3,     3,     3,     3,   484,     8,     3,     3,    10,
      11,   359,   360,   361,   362,    10,    11,   162,   371,   497,
     139,     8,     8,     8,     8,    10,    11,   485,     6,   497,
     497,   131,   134,   363,   364,     4,    97,    21,   372,   100,
     409,   491,    14,    30,    31,    32,    33,    34,    35,   486,
     487,   488,   489,   490,     8,   365,   131,   364,    97,   497,
      10,    11,   373,   374,   375,    18,   410,    78,   435,    58,
      60,    61,   129,   492,   493,   494,     8,     3,     3,     3,
      10,    11,    32,    33,    36,   366,   367,   368,   369,     6,
     156,   376,   497,    10,    11,   411,   412,   413,    17,   436,
     112,   461,     5,     6,     8,     8,     8,   135,     3,     3,
     497,    26,   377,   158,   382,     6,   156,   414,   497,    10,
      11,   437,   438,   439,    20,   462,   125,   478,   495,     8,
       8,     8,   497,    10,    11,    26,   383,    72,   387,   497,
      15,   415,   420,     6,    84,   440,     8,    10,    11,    59,
       6,   378,   497,    10,    11,    26,   388,   392,   497,    10,
      11,   101,   106,   421,   422,   497,    12,   441,   446,     6,
     464,   497,   157,   160,   379,     6,   384,   497,    10,    11,
     106,   163,   393,   395,     6,   416,   423,   497,    10,    11,
      79,   106,   447,   448,   463,   110,   113,   465,    29,   380,
     497,   159,   160,   385,     6,   389,   396,   397,   497,    98,
     157,   417,    10,    11,    15,    32,    33,    34,    35,    40,
      41,   424,   425,   426,   427,   428,   429,     6,   442,   449,
       8,   466,   497,    10,    29,   386,   497,    73,   160,   390,
     394,    26,    32,    33,    34,    35,    40,    41,   398,   399,
     400,   401,   402,    29,   418,   430,   497,     3,     3,     3,
     497,    76,    85,   443,    10,    11,    12,    32,    33,    34,
      35,    40,    41,   450,   451,   452,   453,   454,   455,    10,
      11,   467,     6,     6,     7,   381,   497,    10,    11,    29,
     391,    10,    11,   403,   497,     3,     3,     3,   497,    10,
      98,   107,   431,   432,     6,   497,   497,   497,    29,   444,
     456,   497,     3,     3,     3,   473,    14,    30,    31,    32,
      33,    34,    35,   468,   469,   470,   471,   472,   497,   161,
       6,     4,   161,   497,    10,   404,     6,   497,   497,   497,
       6,     6,     7,   419,    29,   433,   497,   497,    10,    76,
     107,   457,   458,     6,   497,   497,   497,    58,    60,    61,
     111,   474,   475,   476,     8,     3,     3,     3,   497,   161,
       6,     4,   107,   160,   405,   406,   497,   497,    99,   497,
      10,    11,   434,     6,     6,     7,   445,    29,   459,   497,
       5,     6,     8,     8,   497,   497,   161,    29,   407,     6,
       4,     6,     7,    99,   498,   497,    77,   497,    10,    11,
     460,   477,     8,   497,    10,    11,   408,   497,    99,     6,
      77,   498,    59,     6,   161,   498,   497,    77,   497,   161
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
        case 10:

    {	if (parserData->generalStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one generalStatus element allowed");
		parserData->generalStatusPresent = true;
	;}
    break;

  case 11:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 12:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 13:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 14:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 15:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 16:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 17:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 18:

    {	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	;}
    break;

  case 20:

    {	parserData->generalStatusTypePresent = false;
		parserData->generalStatusDescriptionPresent = false;
		parserData->generalStatusNumberOfPresent = false;
	;}
    break;

  case 21:

    {	if (!parserData->generalStatusTypePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	;}
    break;

  case 24:

    {   if (parserData->generalStatusTypePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one type attribute allowed for generalStatus element");
	    parserData->generalStatusTypePresent = true;
	    if ((parserData->tempStr != "error"  ) &&
	        (parserData->tempStr != "warning") && 
	        (parserData->tempStr != "normal"))
			osrlerror(NULL, NULL, parserData, "general status type does not matched any legal value");
		osresult->setGeneralStatusType(parserData->tempStr); 
	;}
    break;

  case 25:

    {   if (parserData->generalStatusDescriptionPresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for generalStatus element");
	    parserData->generalStatusDescriptionPresent = true;
		osresult->setGeneralStatusDescription(parserData->tempStr);
	;}
    break;

  case 26:

    { std::cout << "parsed numberOfGeneralSubstatuses" << std::endl;
	;}
    break;

  case 27:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 28:

    { parserData->tempStr = "";          ;}
    break;

  case 29:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 30:

    { parserData->tempStr = "";          ;}
    break;

  case 31:

    {   if (parserData->generalStatusNumberOfPresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for generalStatus element");
    parserData->generalStatusNumberOfPresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of general substatuses cannot be negative");
    osresult->setNumberOfGeneralSubstatuses((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 32:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 33:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 39:

    {	if (!parserData->generalSubstatusNamePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
	parserData->generalSubstatusNamePresent = false;
	parserData->generalSubstatusDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 40:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
;}
    break;

  case 44:

    {	if (parserData->generalSubstatusDescriptionPresent)
		osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
	parserData->generalSubstatusDescriptionPresent = true;
	osresult->setGeneralSubstatusDescription(parserData->kounter,parserData->tempStr);
;}
    break;

  case 45:

    {	if (parserData->generalSubstatusNamePresent)
		osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
	parserData->generalSubstatusNamePresent = true;
	std::cout << "setGeneralSubstatusName" << std::endl; 
	osresult->setGeneralSubstatusName(parserData->kounter,(yyvsp[(2) - (3)].sval));
	std::cout << "Done setGeneralSubstatusName" << std::endl; 
	
;}
    break;

  case 46:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 47:

    {	parserData->tempStr = "";
;}
    break;

  case 50:

    {osresult->setGeneralMessage( (yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 53:

    {osresult->setServiceURI( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval)); parserData->errorText = NULL;;}
    break;

  case 56:

    {osresult->setServiceName((yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));   parserData->errorText = NULL;;}
    break;

  case 59:

    {osresult->setInstanceName( (yyvsp[(3) - (4)].sval)) ;  free((yyvsp[(3) - (4)].sval));   parserData->errorText = NULL;;}
    break;

  case 62:

    {osresult->setJobID( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 65:

    {osresult->setSolverInvoked( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 68:

    {osresult->setTimeStamp( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 71:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 73:

    {	osresult->setNumberOfOtherGeneralResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 81:

    {	if (!parserData->generalOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->generalOtherResultNamePresent = false;
	parserData->generalOtherResultValuePresent = false;
	parserData->generalOtherResultDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 82:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 85:

    {	if (parserData->generalOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->generalOtherResultNamePresent = true;
		osresult->setGeneralOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 86:

    {	if (parserData->generalOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->generalOtherResultValuePresent = true;
		osresult->setGeneralOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 87:

    {	if (parserData->generalOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->generalOtherResultDescriptionPresent = true;
		osresult->setGeneralOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 88:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 89:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 90:

    {parserData->tempStr = "";}
    break;

  case 91:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 92:

    {parserData->tempStr = "";}
    break;

  case 100:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 105:

    {	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	;}
    break;

  case 106:

    {osresult->setSystemInformation( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 110:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;		
	;}
    break;

  case 115:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "petabyte" && parserData->tempStr != "terabyte" 
	&& parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
	osresult->setAvailableDiskSpaceUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 116:

    {	osresult->setAvailableDiskSpaceDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 118:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 119:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 121:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
	;}
    break;

  case 126:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "availableMemory unit not recognized");
	osresult->setAvailableMemoryUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 127:

    {	osresult->setAvailableMemoryDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 129:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 130:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 132:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
	;}
    break;

  case 137:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "terahertz" && parserData->tempStr != "gigahertz" && 
		parserData->tempStr != "megahertz" && parserData->tempStr != "kilohertz" && 
		parserData->tempStr != "hertz"     && parserData->tempStr != "petaflops" && 
		parserData->tempStr != "teraflops" && parserData->tempStr != "gigaflops" && 
		parserData->tempStr != "megaflops" && parserData->tempStr != "kiloflops" && 
		parserData->tempStr != "flops" )
		osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
	osresult->setAvailableCPUSpeedUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 138:

    {	osresult->setAvailableCPUSpeedDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 140:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 141:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 143:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
	;}
    break;

  case 146:

    {	osresult->setAvailableCPUNumberDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 148:

    {osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 149:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 151:

    {	osresult->setNumberOfOtherSystemResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 159:

    {	if (!parserData->systemOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->systemOtherResultNamePresent = false;
	parserData->systemOtherResultValuePresent = false;
	parserData->systemOtherResultDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 160:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 163:

    {	if (parserData->systemOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->systemOtherResultNamePresent = true;
		osresult->setSystemOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 164:

    {	if (parserData->systemOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->systemOtherResultValuePresent = true;
		osresult->setSystemOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 165:

    {	if (parserData->systemOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->systemOtherResultDescriptionPresent = true;
		osresult->setSystemOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 166:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 167:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 168:

    {parserData->tempStr = "";}
    break;

  case 169:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 170:

    {parserData->tempStr = "";}
    break;

  case 184:

    {;}
    break;

  case 187:

    {;}
    break;

  case 190:

    {;}
    break;

  case 193:

    {;}
    break;

  case 196:

    {;}
    break;

  case 200:

    {std::cout << "!!!store numberOfOtherserviceResults" << std::endl;;}
    break;

  case 237:

    {;}
    break;

  case 240:

    {;}
    break;

  case 243:

    {;}
    break;

  case 246:

    {;}
    break;

  case 249:

    {;}
    break;

  case 253:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
;}
    break;

  case 265:

    {parserData->timeType = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 267:

    {parserData->timeCategory = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 269:

    {parserData->timeUnit = (yyvsp[(2) - (3)].sval);   free((yyvsp[(2) - (3)].sval));;}
    break;

  case 271:

    {parserData->timeDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 277:

    {if (parserData->ivar == parserData->numberOfTimes)
           osrlerror(NULL, NULL, parserData, "Too many time measurements");
       osresult->addTimingInformation(parserData->timeType, parserData->timeCategory,
                                      parserData->timeUnit, parserData->timeDescription, parserData->timeValue);       
       parserData->ivar++;
       parserData->timeType = "elapsedTime";
       parserData->timeCategory = "total";
       parserData->timeUnit = "second";
       parserData->timeDescription = "";      
      ;}
    break;

  case 279:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 280:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 286:

    {;}
    break;

  case 287:

    {;}
    break;

  case 294:

    {;}
    break;

  case 303:

    {;}
    break;

  case 304:

    {;}
    break;

  case 313:

    {;}
    break;

  case 314:

    {;}
    break;

  case 319:

    {std::cout << "!!!store numberOfOtherjobResults" << std::endl;;}
    break;

  case 348:

    {parserData->numberOfSolutions   = (yyvsp[(3) - (3)].ival); osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 349:

    {parserData->numberOfVariables   = (yyvsp[(3) - (3)].ival); osresult->setVariableNumber((yyvsp[(3) - (3)].ival)); ;}
    break;

  case 350:

    {parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 351:

    {parserData->numberOfObjectives  = (yyvsp[(3) - (3)].ival); osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 357:

    {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   ;}
    break;

  case 358:

    {   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
;}
    break;

  case 363:

    {
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
/*  	osresult->optimization->solution[parserData->solutionIdx]->targetObjectiveIdx = $3;*/
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 364:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 369:

    {parserData->statusType = (yyvsp[(2) - (3)].sval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].sval));;}
    break;

  case 370:

    {parserData->statusType = ""; parserData->statusTypePresent = true;;}
    break;

  case 371:

    {parserData->statusDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 372:

    {parserData->statusDescription = "";;}
    break;

  case 373:

    {;}
    break;

  case 374:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element"); 
		parserData->statusTypePresent = false; 
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	;}
    break;

  case 375:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element");
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	;}
    break;

  case 386:

    { std::cout << "parsed <solutionSubstatus type=" << std::endl;
;}
    break;

  case 392:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = $3; */
		osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
	;}
    break;

  case 393:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = "";*/
		osresult->setSolutionMessage(parserData->solutionIdx, "");
	;}
    break;

  case 398:

    {  
	osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
	;}
    break;

  case 404:

    {
  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  ;}
    break;

  case 405:

    {
  	if(parserData->numberOfVar != 0){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  ;}
    break;

  case 406:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 410:

    { parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 411:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->primalVals.push_back( parserData->primalValPair);  
   ;}
    break;

  case 412:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); 
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->primalVals.push_back( parserData->primalValPair); 
  ;}
    break;

  case 414:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
     }
 */  ;}
    break;

  case 416:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 419:

    {/*parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  */
;}
    break;

  case 422:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 424:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
      }
 */  ;}
    break;

  case 426:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 430:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 433:

    {/*	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	*/;}
    break;

  case 434:

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
	;}
    break;

  case 435:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	;}
    break;

  case 436:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	;}
    break;

  case 443:

    {	
	parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);

//std::cout << "This \<other\> element has " << parserData->otherVarStruct->numberOfVar << " \<var\>" << std::endl;

	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 444:

    {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
;}
    break;

  case 445:

    {parserData->tmpOtherValue=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 446:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 447:

    {
parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 448:

    {
parserData->tmpOtherDescription=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 454:

    {  
parserData->otherVarStruct->otherVarText[parserData->kounter] =  parserData->outStr.str();
//reset the buffer;
parserData->outStr.str("");
parserData->otherVarStruct->otherVarIndex[parserData->kounter] =  parserData->ivar;
parserData->errorText = NULL;
//if (parserData->kounter == osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar)
std::cout << "parserData->kounter = " << parserData->kounter << std::endl;
if (parserData->kounter == osresult->getAnOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther))
    osrlerror(NULL, NULL, parserData, "too many variables"); 
if (parserData->numberOfVariables > 0 && (parserData->ivar < 0 || parserData->ivar > parserData->numberOfVariables - 1) ) 
	osrlerror(NULL, NULL, parserData, "index must be greater than 0 and less than the number of variables");
//parserData->kounter++;
;}
    break;

  case 455:

    {//	if(parserData->otherVarStruct->numberOfVar <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	;}
    break;

  case 456:

    {;}
    break;

  case 463:

    {  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 469:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
;}
    break;

  case 471:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 475:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(3) - (4)].ival);   ;}
    break;

  case 476:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].ival);                  
	parserData->objVals.push_back( parserData->objValPair);
;}
    break;

  case 477:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->objVals.push_back( parserData->objValPair);
  ;}
    break;

  case 481:

    {  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	;}
    break;

  case 488:

    {
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
;}
    break;

  case 489:

    {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
;}
    break;

  case 490:

    {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 491:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherObjStruct->name = "";
;}
    break;

  case 492:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 493:

    {
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 496:

    { 	 		
/*
	{	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
	}  

*/
/*        parserData->otherObjVec.push_back( parserData->otherObjStruct); 
        parserData->numberOfOtherObjectiveResults++; 
		parserData->otherNamePresent = false;	
        osresult->setAnOtherObjectiveResultSparse(parserData->solutionIdx, parserData->iOther,  parserData->otherObjStruct->name,
		parserData->otherObjStruct->value, parserData->otherObjStruct->description, parserData->otherObjStruct->otherObjIndex,
		parserData->otherObjStruct->otherObjText, parserData->otherObjStruct->numberOfObj );							
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
*/				
	;}
    break;

  case 499:

    {  
//parserData->otherObjStruct->otherObjText[parserData->kounter] =  parserData->outStr.str();
//reset the buffer;
//parserData->outStr.str("");
//parserData->otherObjStruct->otherObjIndex[parserData->kounter] =  parserData->iobj;
//parserData->errorText = NULL;
//if (parserData->kounter == osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj)
/*if (parserData->kounter == osresult->getAnOtherObjectiveResultNumberOfObj(parserData->solutionIdx, parserData->iOther))
    osrlerror(NULL, NULL, parserData, "too many objectives"); 
    osrlerror(NULL, NULL, parserData, "index must be greater than 0 and less than the number of objectives");
*/
parserData->kounter++;
;}
    break;

  case 500:

    {//	if(parserData->otherObjStruct->numberOfObj <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of objectives") ;
	;}
    break;

  case 501:

    {;}
    break;

  case 508:

    {  
/*        osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 514:

    {/*
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}*/
 ;}
    break;

  case 516:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 520:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 521:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 		
	;}
    break;

  case 522:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 	
	;}
    break;

  case 534:

    {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
;}
    break;

  case 535:

    {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 536:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherConStruct->name = "";
;}
    break;

  case 537:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 538:

    {
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 544:

    {  
//parserData->otherConStruct->otherConText[parserData->kounter] =  parserData->outStr.str();
//reset the buffer;
//parserData->outStr.str("");
//parserData->otherConStruct->otherConIndex[parserData->kounter] =  parserData->icon;
//parserData->errorText = NULL;
//if (parserData->kounter == osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->numberOfCon)
/*if (parserData->kounter == osresult->getAnOtherConstraintResultNumberOfCon(parserData->solutionIdx, parserData->iOther))
    osrlerror(NULL, NULL, parserData, "too many constraints"); 
if (parserData->numberOfConstraints > 0 && (parserData->icon < 0 || parserData->icon > parserData->numberOfConstraints - 1) ) 
    osrlerror(NULL, NULL, parserData, "index must be greater than 0 and less than the number of constraints");
*/
parserData->kounter++;
;}
    break;

  case 545:

    {//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	;}
    break;

  case 546:

    {;}
    break;

  case 551:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 552:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 553:

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
;}
    break;

  case 557:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 558:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 560:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 566:

    {	
int temp;
temp = (yyvsp[(3) - (4)].ival);
if (temp < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems = temp;
	if (osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item != NULL)
		osrlerror(NULL, NULL, parserData, "item array was previously allocated");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item = new std::string[temp];
	parserData->kounter = 0; //this will count the number of items in an otherSolutionResult object
;}
    break;

  case 567:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 568:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 569:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 571:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 574:

    {parserData->kounter++;;}
    break;

  case 575:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 576:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 579:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 581:

    {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
;}
    break;

  case 589:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
;}
    break;

  case 592:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/;}
    break;

  case 598:

    {	
/* 
int temp;
temp = $3;
if (temp < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems = temp;
	if (osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item != NULL)
		osrlerror(NULL, NULL, parserData, "item array was previously allocated");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item = new std::string[temp];
	parserData->kounter = 0; //this will count the number of items in an otherSolutionResult object
*/
;}
    break;

  case 599:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
*/
;}
    break;

  case 600:

    {
/*	parserData->tmpOtherName=$2; parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
;}
    break;

  case 601:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
;}
    break;

  case 603:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
;}
    break;

  case 607:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/;}
    break;

  case 608:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/;}
    break;

  case 611:

    {/*parserData->itemContent = $2; free($2);*/;}
    break;

  case 613:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 614:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 616:

    { parserData->outStr << (yyvsp[(1) - (1)].sval);    free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 617:

    { parserData->outStr << (yyvsp[(1) - (1)].ival);  /*free($1);*/ ;}
    break;

  case 618:

    { parserData->outStr << (yyvsp[(1) - (1)].dval);  /*free($1);*/ ;}
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


