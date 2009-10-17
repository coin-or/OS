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
#define YYLAST   1079

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  427
/* YYNRULES -- Number of rules.  */
#define YYNRULES  721
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1149

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
      53,    55,    57,    59,    62,    64,    66,    68,    73,    75,
      77,    80,    82,    86,    88,    91,    95,    97,    99,   100,
     103,   105,   107,   110,   112,   115,   117,   121,   124,   126,
     129,   131,   135,   138,   140,   143,   145,   149,   152,   154,
     157,   159,   163,   166,   168,   171,   173,   177,   180,   182,
     185,   187,   191,   194,   196,   199,   201,   205,   208,   210,
     214,   216,   221,   223,   225,   228,   230,   234,   236,   239,
     243,   245,   247,   248,   251,   253,   255,   257,   261,   265,
     267,   271,   273,   276,   278,   279,   282,   287,   288,   291,
     293,   295,   297,   299,   301,   303,   306,   308,   312,   315,
     317,   323,   325,   327,   328,   331,   333,   335,   339,   343,
     345,   347,   349,   355,   357,   359,   360,   363,   365,   367,
     371,   375,   377,   379,   381,   387,   389,   391,   392,   395,
     397,   399,   403,   407,   409,   411,   413,   419,   421,   422,
     424,   428,   430,   432,   436,   438,   443,   445,   447,   450,
     452,   456,   458,   461,   465,   467,   469,   470,   473,   475,
     477,   479,   483,   487,   489,   493,   495,   498,   500,   501,
     504,   509,   510,   513,   515,   517,   519,   521,   523,   525,
     528,   530,   534,   537,   539,   542,   544,   548,   551,   553,
     556,   558,   562,   565,   567,   570,   572,   576,   579,   581,
     584,   586,   590,   593,   595,   599,   601,   606,   608,   610,
     613,   615,   619,   621,   624,   628,   630,   632,   633,   636,
     638,   640,   642,   646,   650,   652,   656,   658,   661,   663,
     664,   667,   672,   673,   676,   678,   680,   682,   684,   686,
     688,   690,   692,   694,   696,   698,   701,   703,   707,   710,
     712,   715,   717,   721,   724,   726,   729,   731,   735,   738,
     740,   743,   745,   749,   752,   754,   757,   759,   763,   766,
     768,   772,   774,   779,   781,   785,   786,   789,   793,   794,
     797,   799,   801,   803,   805,   809,   811,   815,   817,   821,
     823,   827,   829,   831,   833,   836,   838,   842,   843,   845,
     847,   853,   855,   857,   858,   861,   863,   865,   869,   873,
     875,   877,   879,   885,   887,   889,   890,   893,   895,   897,
     901,   905,   907,   909,   911,   917,   919,   921,   922,   925,
     927,   929,   933,   937,   939,   941,   943,   949,   951,   952,
     954,   958,   960,   962,   966,   968,   973,   975,   977,   980,
     982,   986,   988,   991,   995,   997,   999,  1000,  1003,  1005,
    1007,  1009,  1013,  1017,  1019,  1023,  1025,  1028,  1030,  1031,
    1035,  1037,  1039,  1040,  1043,  1046,  1049,  1052,  1055,  1059,
    1063,  1067,  1071,  1073,  1075,  1078,  1080,  1085,  1087,  1090,
    1094,  1096,  1098,  1099,  1102,  1104,  1106,  1111,  1115,  1124,
    1128,  1130,  1132,  1134,  1137,  1139,  1141,  1143,  1147,  1149,
    1154,  1156,  1158,  1161,  1163,  1167,  1169,  1172,  1176,  1178,
    1180,  1181,  1184,  1186,  1188,  1192,  1196,  1198,  1201,  1203,
    1204,  1209,  1213,  1216,  1217,  1221,  1223,  1224,  1229,  1231,
    1233,  1240,  1241,  1245,  1247,  1252,  1254,  1256,  1259,  1261,
    1265,  1267,  1270,  1276,  1278,  1283,  1285,  1287,  1288,  1292,
    1294,  1299,  1301,  1303,  1306,  1308,  1312,  1314,  1317,  1323,
    1325,  1330,  1331,  1335,  1337,  1342,  1344,  1346,  1349,  1351,
    1355,  1357,  1360,  1366,  1368,  1373,  1374,  1377,  1381,  1383,
    1385,  1386,  1389,  1391,  1393,  1395,  1397,  1402,  1406,  1408,
    1412,  1414,  1418,  1420,  1422,  1426,  1427,  1430,  1434,  1436,
    1441,  1445,  1448,  1450,  1451,  1455,  1456,  1461,  1463,  1465,
    1470,  1471,  1475,  1477,  1482,  1484,  1486,  1489,  1491,  1495,
    1497,  1500,  1506,  1508,  1513,  1515,  1517,  1518,  1521,  1525,
    1527,  1529,  1530,  1533,  1535,  1537,  1539,  1541,  1546,  1550,
    1552,  1556,  1558,  1562,  1564,  1566,  1570,  1571,  1574,  1578,
    1580,  1585,  1589,  1592,  1594,  1595,  1599,  1600,  1605,  1607,
    1609,  1614,  1615,  1619,  1621,  1626,  1628,  1630,  1633,  1635,
    1639,  1641,  1644,  1650,  1652,  1657,  1659,  1661,  1662,  1665,
    1669,  1671,  1673,  1674,  1677,  1679,  1681,  1683,  1685,  1690,
    1694,  1696,  1700,  1702,  1706,  1708,  1710,  1714,  1715,  1718,
    1722,  1724,  1729,  1733,  1736,  1738,  1739,  1745,  1749,  1750,
    1756,  1757,  1760,  1766,  1770,  1771,  1772,  1776,  1778,  1780,
    1782,  1784,  1789,  1791,  1795,  1799,  1801,  1805,  1807,  1808,
    1811,  1813,  1815,  1817,  1819,  1820,  1825,  1827,  1828,  1832,
    1837,  1839,  1843,  1844,  1847,  1853,  1857,  1858,  1859,  1863,
    1865,  1867,  1869,  1871,  1876,  1878,  1882,  1886,  1888,  1892,
    1894,  1895,  1898,  1900,  1902,  1904,  1906,  1907,  1912,  1915,
    1917,  1920,  1922,  1925,  1927,  1930,  1932,  1935,  1937,  1940,
    1942,  1944,  1946,  1949,  1951,  1953,  1955,  1957,  1959,  1961,
    1963,  1964
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   228,   279,   313,   392,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   191,    -1,   194,    -1,   197,    -1,   200,
      -1,   203,    -1,   206,    -1,   209,    -1,   212,    -1,   176,
     177,   181,    -1,    88,    -1,   178,    -1,   179,    -1,   178,
     179,    -1,   588,    -1,   582,    -1,   180,    -1,    24,     8,
       6,     8,    -1,   182,    -1,   183,    -1,    10,    89,    -1,
      11,    -1,    10,   184,    89,    -1,   185,    -1,   184,   185,
      -1,   186,   187,   190,    -1,   134,    -1,   188,    -1,    -1,
     188,   189,    -1,   585,    -1,   582,    -1,    10,   135,    -1,
      11,    -1,   192,   193,    -1,    96,    -1,    10,     4,    97,
      -1,    10,    97,    -1,    11,    -1,   195,   196,    -1,   120,
      -1,    10,     4,   121,    -1,    10,   121,    -1,    11,    -1,
     198,   199,    -1,   118,    -1,    10,     4,   119,    -1,    10,
     119,    -1,    11,    -1,   201,   202,    -1,    92,    -1,    10,
       4,    93,    -1,    10,    93,    -1,    11,    -1,   204,   205,
      -1,    94,    -1,    10,     4,    95,    -1,    10,    95,    -1,
      11,    -1,   207,   208,    -1,   126,    -1,    10,     4,   127,
      -1,    10,   127,    -1,    11,    -1,   210,   211,    -1,   142,
      -1,    10,     4,   143,    -1,    10,   143,    -1,    11,    -1,
     213,   214,   215,    -1,   108,    -1,    19,   592,     6,   592,
      -1,   216,    -1,   217,    -1,    10,   109,    -1,    11,    -1,
      10,   218,   109,    -1,   219,    -1,   218,   219,    -1,   220,
     221,   227,    -1,   106,    -1,   222,    -1,    -1,   222,   223,
      -1,   224,    -1,   225,    -1,   226,    -1,    34,     3,   592,
      -1,    40,     3,   592,    -1,    41,    -1,    32,     3,   592,
      -1,    33,    -1,    10,   107,    -1,    11,    -1,    -1,    50,
      11,    -1,    50,    10,   229,    51,    -1,    -1,   229,   230,
      -1,   231,    -1,   234,    -1,   242,    -1,   250,    -1,   258,
      -1,   263,    -1,   232,   233,    -1,   136,    -1,    10,     4,
     137,    -1,    10,   137,    -1,    11,    -1,   235,   236,    10,
     241,    69,    -1,    68,    -1,   237,    -1,    -1,   237,   238,
      -1,   239,    -1,   240,    -1,    38,     3,   592,    -1,    32,
       3,   592,    -1,    33,    -1,     6,    -1,     7,    -1,   243,
     244,    10,   249,    71,    -1,    70,    -1,   245,    -1,    -1,
     245,   246,    -1,   247,    -1,   248,    -1,    38,     3,   592,
      -1,    32,     3,   592,    -1,    33,    -1,     6,    -1,     7,
      -1,   251,   252,    10,   257,    67,    -1,    66,    -1,   253,
      -1,    -1,   253,   254,    -1,   255,    -1,   256,    -1,    38,
       3,   592,    -1,    32,     3,   592,    -1,    33,    -1,     6,
      -1,     7,    -1,   259,   260,    10,   262,    65,    -1,    64,
      -1,    -1,   261,    -1,    32,     3,   592,    -1,    33,    -1,
       6,    -1,   264,   265,   266,    -1,   108,    -1,    19,   592,
       6,   592,    -1,   267,    -1,   268,    -1,    10,   109,    -1,
      11,    -1,    10,   269,   109,    -1,   270,    -1,   269,   270,
      -1,   271,   272,   278,    -1,   106,    -1,   273,    -1,    -1,
     273,   274,    -1,   275,    -1,   276,    -1,   277,    -1,    34,
       3,   592,    -1,    40,     3,   592,    -1,    41,    -1,    32,
       3,   592,    -1,    33,    -1,    10,   107,    -1,    11,    -1,
      -1,    52,    11,    -1,    52,    10,   280,    53,    -1,    -1,
     280,   281,    -1,   282,    -1,   285,    -1,   288,    -1,   291,
      -1,   294,    -1,   297,    -1,   283,   284,    -1,    82,    -1,
      10,     4,    83,    -1,    10,    83,    -1,    11,    -1,   286,
     287,    -1,    80,    -1,    10,     6,    81,    -1,    10,    81,
      -1,    11,    -1,   289,   290,    -1,   146,    -1,    10,     6,
     147,    -1,    10,   147,    -1,    11,    -1,   292,   293,    -1,
     140,    -1,    10,     4,   141,    -1,    10,   141,    -1,    11,
      -1,   295,   296,    -1,   122,    -1,    10,   591,   123,    -1,
      10,   123,    -1,    11,    -1,   298,   299,   300,    -1,   108,
      -1,    19,   592,     6,   592,    -1,   301,    -1,   302,    -1,
      10,   109,    -1,    11,    -1,    10,   303,   109,    -1,   304,
      -1,   303,   304,    -1,   305,   306,   312,    -1,   106,    -1,
     307,    -1,    -1,   307,   308,    -1,   309,    -1,   310,    -1,
     311,    -1,    34,     3,   592,    -1,    40,     3,   592,    -1,
      41,    -1,    32,     3,   592,    -1,    33,    -1,    10,   107,
      -1,    11,    -1,    -1,    54,    11,    -1,    54,    10,   314,
      55,    -1,    -1,   314,   315,    -1,   316,    -1,   319,    -1,
     322,    -1,   325,    -1,   328,    -1,   331,    -1,   347,    -1,
     355,    -1,   363,    -1,   371,    -1,   376,    -1,   317,   318,
      -1,   130,    -1,    10,     4,   131,    -1,    10,   131,    -1,
      11,    -1,   320,   321,    -1,   132,    -1,    10,     4,   133,
      -1,    10,   133,    -1,    11,    -1,   323,   324,    -1,   116,
      -1,    10,     4,   117,    -1,    10,   117,    -1,    11,    -1,
     326,   327,    -1,    62,    -1,    10,     4,    63,    -1,    10,
      63,    -1,    11,    -1,   329,   330,    -1,    86,    -1,    10,
       4,    87,    -1,    10,    87,    -1,    11,    -1,   332,   333,
     334,    -1,   144,    -1,    25,     8,     6,     8,    -1,    11,
      -1,    10,   335,   145,    -1,    -1,   335,   336,    -1,   138,
     337,   343,    -1,    -1,   337,   338,    -1,   341,    -1,   339,
      -1,   340,    -1,   342,    -1,    36,     3,     8,    -1,    37,
      -1,    30,     3,     8,    -1,    31,    -1,    38,     3,     8,
      -1,    39,    -1,    32,     3,     8,    -1,    33,    -1,   344,
      -1,   345,    -1,    10,   139,    -1,    11,    -1,    10,   346,
     139,    -1,    -1,     7,    -1,     6,    -1,   348,   349,    10,
     354,   153,    -1,   152,    -1,   350,    -1,    -1,   350,   351,
      -1,   352,    -1,   353,    -1,    38,     3,   592,    -1,    32,
       3,   592,    -1,    33,    -1,     6,    -1,     7,    -1,   356,
     357,    10,   362,   155,    -1,   154,    -1,   358,    -1,    -1,
     358,   359,    -1,   360,    -1,   361,    -1,    38,     3,   592,
      -1,    32,     3,   592,    -1,    33,    -1,     6,    -1,     7,
      -1,   364,   365,    10,   370,   151,    -1,   150,    -1,   366,
      -1,    -1,   366,   367,    -1,   368,    -1,   369,    -1,    38,
       3,   592,    -1,    32,     3,   592,    -1,    33,    -1,     6,
      -1,     7,    -1,   372,   373,    10,   375,   149,    -1,   148,
      -1,    -1,   374,    -1,    32,     3,   592,    -1,    33,    -1,
       6,    -1,   377,   378,   379,    -1,   108,    -1,    19,   592,
       6,   592,    -1,   380,    -1,   381,    -1,    10,   109,    -1,
      11,    -1,    10,   382,   109,    -1,   383,    -1,   382,   383,
      -1,   384,   385,   391,    -1,   106,    -1,   386,    -1,    -1,
     386,   387,    -1,   388,    -1,   389,    -1,   390,    -1,    34,
       3,   592,    -1,    40,     3,   592,    -1,    41,    -1,    32,
       3,   592,    -1,    33,    -1,    10,   107,    -1,    11,    -1,
      -1,   393,   394,   401,    -1,    56,    -1,   395,    -1,    -1,
     395,   396,    -1,   397,   592,    -1,   398,   592,    -1,   399,
     592,    -1,   400,   592,    -1,    22,   592,     6,    -1,    27,
     592,     6,    -1,    13,   592,     6,    -1,    16,   592,     6,
      -1,   402,    -1,   403,    -1,    10,    57,    -1,    11,    -1,
      10,   404,   565,    57,    -1,   405,    -1,   404,   405,    -1,
     406,   407,   412,    -1,   124,    -1,   408,    -1,    -1,   408,
     409,    -1,   410,    -1,   411,    -1,    28,   592,     6,   592,
      -1,    42,     3,   592,    -1,    10,   413,   432,   433,   485,
     516,   547,   564,    -1,   414,   415,   420,    -1,   130,    -1,
     416,    -1,   417,    -1,   416,   417,    -1,   588,    -1,   418,
      -1,   419,    -1,    32,     3,   592,    -1,    33,    -1,    24,
       8,     6,     8,    -1,   421,    -1,   422,    -1,    10,   131,
      -1,    11,    -1,    10,   423,   131,    -1,   424,    -1,   423,
     424,    -1,   425,   426,   431,    -1,   134,    -1,   427,    -1,
      -1,   427,   428,    -1,   429,    -1,   430,    -1,    36,     3,
       8,    -1,    32,     3,     8,    -1,    33,    -1,    10,   135,
      -1,    11,    -1,    -1,    96,    10,     4,    97,    -1,    96,
      10,    97,    -1,    96,    11,    -1,    -1,   434,   435,   436,
      -1,   162,    -1,    -1,    21,   592,     6,   592,    -1,    11,
      -1,   437,    -1,    10,   438,   449,   459,   469,   163,    -1,
      -1,   439,   440,   441,    -1,   156,    -1,    26,   592,     6,
     592,    -1,   442,    -1,   443,    -1,    10,   157,    -1,    11,
      -1,    10,   444,   157,    -1,   445,    -1,   444,   445,    -1,
     446,   447,    10,   448,   161,    -1,   160,    -1,    29,   592,
       6,   592,    -1,     6,    -1,     7,    -1,    -1,   450,   451,
     452,    -1,   158,    -1,    26,   592,     6,   592,    -1,   453,
      -1,   454,    -1,    10,   159,    -1,    11,    -1,    10,   455,
     159,    -1,   456,    -1,   455,   456,    -1,   457,   458,    10,
       4,   161,    -1,   160,    -1,    29,   592,     6,   592,    -1,
      -1,   460,   461,   462,    -1,    72,    -1,    26,   592,     6,
     592,    -1,   463,    -1,   464,    -1,    10,    73,    -1,    11,
      -1,    10,   465,    73,    -1,   466,    -1,   465,   466,    -1,
     467,   468,    10,     4,   161,    -1,   160,    -1,    29,   592,
       6,   592,    -1,    -1,   469,   470,    -1,   471,   472,   479,
      -1,   106,    -1,   473,    -1,    -1,   473,   474,    -1,   475,
      -1,   476,    -1,   477,    -1,   478,    -1,    26,   592,     6,
     592,    -1,    40,     3,   592,    -1,    41,    -1,    34,     3,
     592,    -1,    35,    -1,    32,     3,   592,    -1,    33,    -1,
      11,    -1,    10,   480,   107,    -1,    -1,   480,   481,    -1,
     482,   483,   484,    -1,   160,    -1,    29,   592,     6,   592,
      -1,    10,   593,   161,    -1,    10,   161,    -1,    11,    -1,
      -1,   100,   486,   487,    -1,    -1,    18,   592,     6,   592,
      -1,    11,    -1,   488,    -1,    10,   489,   500,   101,    -1,
      -1,   490,   491,   492,    -1,   156,    -1,    15,   592,     6,
     592,    -1,   493,    -1,   494,    -1,    10,   157,    -1,    11,
      -1,    10,   495,   157,    -1,   496,    -1,   495,   496,    -1,
     497,   498,    10,   499,    99,    -1,    98,    -1,    29,   592,
       6,   592,    -1,     6,    -1,     7,    -1,    -1,   500,   501,
      -1,   502,   503,   510,    -1,   106,    -1,   504,    -1,    -1,
     504,   505,    -1,   506,    -1,   507,    -1,   508,    -1,   509,
      -1,    15,   592,     6,   592,    -1,    40,     3,   592,    -1,
      41,    -1,    34,     3,   592,    -1,    35,    -1,    32,     3,
     592,    -1,    33,    -1,    11,    -1,    10,   511,   107,    -1,
      -1,   511,   512,    -1,   513,   514,   515,    -1,    98,    -1,
      29,   592,     6,   592,    -1,    10,   593,    99,    -1,    10,
      99,    -1,    11,    -1,    -1,    78,   517,   518,    -1,    -1,
      17,   592,     6,   592,    -1,    11,    -1,   519,    -1,    10,
     520,   531,    79,    -1,    -1,   521,   522,   523,    -1,    84,
      -1,    12,   592,     6,   592,    -1,   524,    -1,   525,    -1,
      10,   157,    -1,    11,    -1,    10,   526,    85,    -1,   527,
      -1,   526,   527,    -1,   528,   529,    10,   530,    77,    -1,
      76,    -1,    29,   592,     6,   592,    -1,     6,    -1,     7,
      -1,    -1,   531,   532,    -1,   533,   534,   541,    -1,   106,
      -1,   535,    -1,    -1,   535,   536,    -1,   537,    -1,   538,
      -1,   539,    -1,   540,    -1,    12,   592,     6,   592,    -1,
      40,     3,   592,    -1,    41,    -1,    34,     3,   592,    -1,
      35,    -1,    32,     3,   592,    -1,    33,    -1,    11,    -1,
      10,   542,   107,    -1,    -1,   542,   543,    -1,   544,   545,
     546,    -1,    76,    -1,    29,   592,     6,   592,    -1,    10,
     593,   161,    -1,    10,   161,    -1,    11,    -1,    -1,   112,
     548,    10,   550,   113,    -1,   112,   548,    11,    -1,    -1,
      20,     8,     6,   549,     8,    -1,    -1,   550,   551,    -1,
     110,   552,    10,   559,   111,    -1,   110,   552,    11,    -1,
      -1,    -1,   552,   553,   554,    -1,   555,    -1,   556,    -1,
     557,    -1,   558,    -1,    14,     8,     6,     8,    -1,    35,
      -1,    34,     3,   592,    -1,    30,     3,     8,    -1,    31,
      -1,    32,     3,     8,    -1,    33,    -1,    -1,   559,   560,
      -1,   561,    -1,   562,    -1,    60,    -1,    61,    -1,    -1,
      58,     5,   563,    59,    -1,   125,    -1,    -1,   114,   566,
     567,    -1,    23,   592,     6,   592,    -1,    11,    -1,    10,
     568,   115,    -1,    -1,   568,   569,    -1,   128,   570,    10,
     577,   129,    -1,   128,   570,    11,    -1,    -1,    -1,   570,
     571,   572,    -1,   573,    -1,   574,    -1,   575,    -1,   576,
      -1,    14,     8,     6,     8,    -1,    35,    -1,    34,     3,
       8,    -1,    30,     3,     8,    -1,    31,    -1,    32,     3,
       8,    -1,    33,    -1,    -1,   577,   578,    -1,   579,    -1,
     580,    -1,    60,    -1,    61,    -1,    -1,    58,     5,   581,
      59,    -1,   583,   584,    -1,    32,    -1,     3,   592,    -1,
     592,    -1,   586,   587,    -1,    34,    -1,     3,   592,    -1,
     592,    -1,   589,   590,    -1,    36,    -1,     3,   592,    -1,
     592,    -1,     6,    -1,     7,    -1,   595,     8,    -1,     4,
      -1,     6,    -1,     7,    -1,   165,    -1,   166,    -1,   167,
      -1,   168,    -1,    -1,   595,   594,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   162,   162,   164,   165,   167,   167,   168,   170,   170,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   184,
     186,   198,   204,   204,   207,   215,   219,   222,   232,   236,
     241,   241,   243,   245,   245,   247,   251,   258,   263,   263,
     266,   269,   274,   274,   277,   279,   286,   288,   289,   291,
     293,   300,   302,   303,   305,   307,   314,   316,   317,   319,
     321,   328,   330,   331,   333,   335,   342,   344,   345,   347,
     349,   356,   358,   359,   361,   363,   370,   372,   373,   375,
     377,   383,   390,   394,   399,   399,   401,   403,   403,   405,
     409,   417,   425,   425,   428,   434,   440,   448,   451,   452,
     455,   456,   458,   458,   462,   462,   463,   465,   465,   468,
     469,   470,   471,   472,   473,   476,   478,   485,   487,   488,
     490,   493,   499,   504,   504,   507,   514,   522,   532,   533,
     536,   537,   539,   542,   548,   553,   553,   556,   563,   571,
     579,   580,   583,   584,   586,   589,   595,   600,   600,   603,
     610,   618,   630,   631,   634,   635,   638,   641,   647,   648,
     654,   655,   658,   661,   663,   669,   676,   680,   685,   685,
     687,   689,   689,   691,   695,   700,   708,   708,   711,   717,
     723,   731,   734,   735,   738,   739,   741,   741,   745,   745,
     746,   748,   748,   751,   752,   753,   754,   755,   756,   759,
     761,   768,   770,   771,   773,   775,   782,   784,   785,   787,
     789,   796,   798,   799,   801,   803,   810,   812,   813,   815,
     817,   824,   826,   827,   830,   832,   838,   845,   849,   854,
     854,   856,   858,   858,   860,   864,   869,   877,   877,   880,
     886,   892,   900,   903,   904,   907,   908,   910,   910,   913,
     913,   914,   916,   916,   919,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,   932,   934,   941,   943,   944,
     946,   948,   955,   957,   958,   960,   962,   969,   971,   972,
     974,   976,   983,   985,   986,   988,   990,   997,   999,  1000,
    1002,  1004,  1010,  1016,  1016,  1018,  1018,  1020,  1022,  1022,
    1025,  1037,  1038,  1039,  1041,  1042,  1044,  1045,  1047,  1048,
    1050,  1051,  1053,  1053,  1055,  1055,  1057,  1068,  1072,  1073,
    1076,  1079,  1085,  1090,  1090,  1093,  1100,  1108,  1117,  1118,
    1121,  1122,  1124,  1127,  1133,  1138,  1138,  1141,  1148,  1156,
    1164,  1165,  1168,  1169,  1172,  1175,  1181,  1186,  1186,  1189,
    1196,  1204,  1216,  1217,  1220,  1221,  1224,  1227,  1234,  1235,
    1241,  1242,  1245,  1249,  1251,  1257,  1264,  1268,  1273,  1273,
    1275,  1277,  1277,  1279,  1283,  1288,  1296,  1296,  1299,  1305,
    1311,  1319,  1322,  1323,  1326,  1327,  1329,  1329,  1332,  1332,
    1334,  1341,  1351,  1351,  1354,  1355,  1356,  1357,  1360,  1368,
    1376,  1384,  1392,  1392,  1394,  1394,  1396,  1398,  1398,  1400,
    1407,  1413,  1418,  1418,  1420,  1420,  1422,  1430,  1438,  1441,
    1443,  1450,  1459,  1459,  1462,  1476,  1482,  1485,  1486,  1488,
    1498,  1502,  1508,  1508,  1510,  1512,  1512,  1514,  1517,  1522,
    1529,  1529,  1531,  1531,  1538,  1546,  1547,  1549,  1549,  1552,
    1553,  1556,  1557,  1559,  1560,  1562,  1564,  1565,  1571,  1571,
    1573,  1575,  1575,  1577,  1580,  1587,  1591,  1597,  1597,  1599,
    1601,  1601,  1603,  1609,  1615,  1618,  1619,  1622,  1622,  1624,
    1627,  1634,  1638,  1644,  1644,  1646,  1648,  1648,  1650,  1656,
    1662,  1666,  1666,  1668,  1671,  1678,  1682,  1688,  1688,  1690,
    1692,  1692,  1694,  1700,  1706,  1709,  1709,  1711,  1720,  1722,
    1734,  1734,  1737,  1738,  1745,  1752,  1760,  1769,  1770,  1773,
    1774,  1777,  1778,  1780,  1781,  1783,  1783,  1785,  1790,  1792,
    1798,  1802,  1803,  1806,  1807,  1809,  1810,  1816,  1816,  1818,
    1820,  1820,  1822,  1825,  1832,  1836,  1842,  1842,  1844,  1847,
    1847,  1849,  1855,  1861,  1864,  1865,  1869,  1869,  1871,  1880,
    1882,  1895,  1895,  1898,  1899,  1906,  1913,  1921,  1930,  1931,
    1934,  1935,  1938,  1939,  1941,  1942,  1944,  1944,  1946,  1951,
    1953,  1958,  1961,  1962,  1966,  1967,  1969,  1970,  1976,  1976,
    1978,  1980,  1980,  1982,  1985,  1993,  1997,  2003,  2003,  2005,
    2007,  2007,  2009,  2015,  2021,  2024,  2025,  2028,  2028,  2030,
    2039,  2041,  2053,  2053,  2056,  2057,  2064,  2071,  2079,  2088,
    2089,  2092,  2093,  2096,  2097,  2099,  2100,  2103,  2103,  2105,
    2110,  2112,  2118,  2122,  2123,  2127,  2128,  2133,  2140,  2139,
    2155,  2155,  2158,  2165,  2174,  2175,  2175,  2179,  2179,  2179,
    2179,  2181,  2194,  2200,  2208,  2211,  2214,  2217,  2219,  2220,
    2223,  2228,  2235,  2235,  2238,  2237,  2244,  2254,  2254,  2256,
    2258,  2258,  2260,  2260,  2263,  2270,  2272,  2274,  2273,  2278,
    2278,  2278,  2278,  2280,  2295,  2302,  2311,  2317,  2320,  2326,
    2328,  2329,  2331,  2336,  2342,  2342,  2345,  2344,  2360,  2362,
    2369,  2370,  2372,  2374,  2381,  2382,  2384,  2386,  2393,  2394,
    2422,  2423,  2425,  2428,  2429,  2430,  2434,  2435,  2436,  2437,
    2439,  2440
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
  "generalStatusNumberOfATT", "generalStatusContent", "generalStatusEmpty",
  "generalStatusBody", "generalSubstatusArray", "generalSubstatus",
  "generalSubstatusStart", "generalSubstatusAttributes",
  "generalSubstatusAttList", "generalSubstatusATT", "generalSubstatusEnd",
  "generalMessage", "generalMessageStart", "generalMessageContent",
  "serviceURI", "serviceURIStart", "serviceURIContent", "serviceName",
  "serviceNameStart", "serviceNameContent", "instanceName",
  "instanceNameStart", "instanceNameContent", "jobID", "jobIDStart",
  "jobIDContent", "solverInvoked", "solverInvokedStart",
  "solverInvokedContent", "timeStamp", "timeStampStart",
  "timeStampContent", "generalOtherResults", "generalOtherResultsStart",
  "generalOtherResultsAttList", "generalOtherResultsContent",
  "generalOtherResultsEmpty", "generalOtherResultsBody",
  "generalOtherResultArray", "generalOtherResult",
  "generalOtherResultStart", "generalOtherAttributes",
  "generalOtherAttList", "generalOtherAtt", "generalOtherNameATT",
  "generalOtherValueATT", "generalOtherDescriptionATT", "generalOtherEnd",
  "systemElement", "systemContent", "systemChild", "systemInformation",
  "systemInformationStart", "systemInformationContent",
  "availableDiskSpace", "availableDiskSpaceStart",
  "availableDiskSpaceAttributes", "availableDiskSpaceAttList",
  "availableDiskSpaceAtt", "availableDiskSpaceUnitATT",
  "availableDiskSpaceDescriptionATT", "availableDiskSpaceValue",
  "availableMemory", "availableMemoryStart", "availableMemoryAttributes",
  "availableMemoryAttList", "availableMemoryAtt", "availableMemoryUnitATT",
  "availableMemoryDescriptionATT", "availableMemoryValue",
  "availableCPUSpeed", "availableCPUSpeedStart",
  "availableCPUSpeedAttributes", "availableCPUSpeedAttList",
  "availableCPUSpeedAtt", "availableCPUSpeedUnitATT",
  "availableCPUSpeedDescriptionATT", "availableCPUSpeedValue",
  "availableCPUNumber", "availableCPUNumberStart",
  "availableCPUNumberAttList", "availableCPUNumberDescriptionATT",
  "availableCPUNumberValue", "systemOtherResults",
  "systemOtherResultsStart", "systemOtherResultsAttList",
  "systemOtherResultsContent", "systemOtherResultsEmpty",
  "systemOtherResultsBody", "systemOtherResultArray", "systemOtherResult",
  "systemOtherResultStart", "systemOtherAttributes", "systemOtherAttList",
  "systemOtherAtt", "systemOtherNameATT", "systemOtherValueATT",
  "systemOtherDescriptionATT", "systemOtherEnd", "serviceElement",
  "serviceContent", "serviceChild", "currentState", "currentStateStart",
  "currentStateContent", "currentJobCount", "currentJobCountStart",
  "currentJobCountContent", "totalJobsSoFar", "totalJobsSoFarStart",
  "totalJobsSoFarContent", "timeServiceStarted", "timeServiceStartedStart",
  "timeServiceStartedContent", "serviceUtilization",
  "serviceUtilizationStart", "serviceUtilizationContent",
  "serviceOtherResults", "serviceOtherResultsStart",
  "serviceOtherResultsAttList", "serviceOtherResultsContent",
  "serviceOtherResultsEmpty", "serviceOtherResultsBody",
  "serviceOtherResultArray", "serviceOtherResult",
  "serviceOtherResultStart", "serviceOtherAttributes",
  "serviceOtherAttList", "serviceOtherAtt", "serviceOtherNameATT",
  "serviceOtherValueATT", "serviceOtherDescriptionATT", "serviceOtherEnd",
  "jobElement", "jobContent", "jobChild", "jobStatus", "jobStatusStart",
  "jobStatusContent", "submitTime", "submitTimeStart", "submitTimeContent",
  "scheduledStartTime", "scheduledStartTimeStart",
  "scheduledStartTimeContent", "actualStartTime", "actualStartTimeStart",
  "actualStartTimeContent", "endTime", "endTimeStart", "endTimeContent",
  "timingInformation", "timingInformationStart", "numberoftimes",
  "timingContent", "listOfTimes", "time", "timeAttList", "timeAtt",
  "timeType", "timeCategory", "timeUnit", "timeDescription",
  "restOfTimeElement", "timeEmpty", "timeContent", "timeValue",
  "usedDiskSpace", "usedDiskSpaceStart", "usedDiskSpaceAttributes",
  "usedDiskSpaceAttList", "usedDiskSpaceAtt", "usedDiskSpaceUnitATT",
  "usedDiskSpaceDescriptionATT", "usedDiskSpaceValue", "usedMemory",
  "usedMemoryStart", "usedMemoryAttributes", "usedMemoryAttList",
  "usedMemoryAtt", "usedMemoryUnitATT", "usedMemoryDescriptionATT",
  "usedMemoryValue", "usedCPUSpeed", "usedCPUSpeedStart",
  "usedCPUSpeedAttributes", "usedCPUSpeedAttList", "usedCPUSpeedAtt",
  "usedCPUSpeedUnitATT", "usedCPUSpeedDescriptionATT", "usedCPUSpeedValue",
  "usedCPUNumber", "usedCPUNumberStart", "usedCPUNumberAttList",
  "usedCPUNumberDescriptionATT", "usedCPUNumberValue", "jobOtherResults",
  "jobOtherResultsStart", "jobOtherResultsAttList",
  "jobOtherResultsContent", "jobOtherResultsEmpty", "jobOtherResultsBody",
  "jobOtherResultArray", "jobOtherResult", "jobOtherResultStart",
  "jobOtherAttributes", "jobOtherAttList", "jobOtherAtt",
  "jobOtherNameATT", "jobOtherValueATT", "jobOtherDescriptionATT",
  "jobOtherEnd", "optimizationElement", "OptimizationStart",
  "optimizationAttributes", "optimizationAttList", "optimizationATT",
  "optimizationNumberOfSolutionsATT", "optimizationNumberOfVariablesATT",
  "optimizationNumberOfConstraintsATT",
  "optimizationNumberOfObjectivesATT", "optimizationContent",
  "optimizationEmpty", "optimizationBody", "solutionArray", "solution",
  "solutionStart", "solutionAttributes", "solutionAttList", "solutionATT",
  "targetObjectiveIdxATT", "weightedObjectivesATT", "solutionBody",
  "solutionStatus", "solutionStatusStart", "solutionStatusAttributes",
  "solutionStatusAttList", "solutionStatusATT",
  "solutionStatusDescriptionATT", "solutionStatusNumberOfATT",
  "solutionStatusContent", "solutionStatusEmpty", "solutionStatusBody",
  "solutionSubstatusArray", "solutionSubstatus", "solutionSubstatusStart",
  "solutionSubstatusAttributes", "solutionSubstatusAttList",
  "solutionSubstatusATT", "solutionSubstatusTypeATT",
  "solutionSubstatusDescriptionATT", "solutionSubstatusEnd",
  "solutionMessage", "variables", "variablesStart",
  "numberOfOtherVariableResults", "variablesContent", "variablesBody",
  "variableValues", "variableValuesStart", "numberOfVarATT",
  "variableValuesContent", "variableValuesEmpty", "variableValuesBody",
  "varValueArray", "varValue", "varValueStart", "varIdxATT", "varVal",
  "variableValuesString", "variableValuesStringStart",
  "numberOfVarStringATT", "variableValuesStringContent",
  "variableValuesStringEmpty", "variableValuesStringBody",
  "varValueStringArray", "varValueString", "varValueStringStart",
  "varStrIdxATT", "basisStatus", "basisStatusStart", "numberOfBasisVarATT",
  "basisStatusContent", "basisStatusEmpty", "basisStatusBody",
  "basisVarArray", "basisVar", "basisVarStart", "basisVarIdxATT",
  "otherVariableResultsArray", "otherVariableResult",
  "otherVariableResultStart", "otherVariableResultAttributes",
  "otherVariableResultAttList", "otherVariableResultATT",
  "numberOfOtherVariableResultsATT", "otherVariableResultValueATT",
  "otherVariableResultNameATT", "otherVariableResultDescriptionATT",
  "otherVariableResultContent", "otherVarList", "otherVar",
  "otherVarStart", "otherVarIdxATT", "otherVarContent", "objectives",
  "numberOfOtherObjectiveResults", "objectivesContent", "objectivesBody",
  "objectiveValues", "objectiveValuesStart", "numberOfObjATT",
  "objectiveValuesContent", "objectiveValuesEmpty", "objectiveValuesBody",
  "objValueArray", "objValue", "objValueStart", "objIdxATT", "objVal",
  "otherObjectiveResultsArray", "otherObjectiveResult",
  "otherObjectiveResultStart", "otherObjectiveResultAttributes",
  "otherObjectiveResultAttList", "otherObjectiveResultATT",
  "numberOfOtherObjectiveResultsATT", "otherObjectiveResultValueATT",
  "otherObjectiveResultNameATT", "otherObjectiveResultDescriptionATT",
  "otherObjectiveResultContent", "otherObjList", "otherObj",
  "otherObjStart", "otherObjIdxATT", "otherObjContent", "constraints",
  "numberOfOtherConstraintResults", "constraintsContent",
  "constraintsBody", "dualValues", "dualValuesStart", "numberOfConATT",
  "dualValuesContent", "dualValuesEmpty", "dualValuesBody",
  "dualValueArray", "dualValue", "dualValueStart", "conIdxATT", "dualVal",
  "otherConstraintResultsArray", "otherConstraintResult",
  "otherConstraintResultStart", "otherConstraintResultAttributes",
  "otherConstraintResultAttList", "otherConstraintResultATT",
  "numberOfOtherConstraintResultATT", "otherConstraintResultValueATT",
  "otherConstraintResultNameATT", "otherConstraintResultDescriptionATT",
  "otherConstraintResultContent", "otherConList", "otherCon",
  "otherConStart", "otherConIdxATT", "otherConContent",
  "otherSolutionResults", "numberOfOtherSolutionResults", "@1",
  "otherSolutionResultList", "anotherSolutionResult",
  "anotherSolutionResultAttList", "@2", "anotherSolutionResultAtt",
  "numberOfOtherSolutionResultItems", "anotherSolutionResultNameATT",
  "anotherSolutionResultCategoryATT", "anotherSolutionDescriptionATT",
  "anotherSolutionItemList", "anotherSolutionItem",
  "otherSolutionItemEmpty", "otherSolutionItemContent", "@3",
  "solutionEnd", "otherSolverOutput", "numberOfSolverOutputsATT",
  "otherSolverOutputBody", "solverOutputArray", "solverOutput",
  "solverOutputAttList", "@4", "solverOutputAtt",
  "numberOfSolverOutputItems", "solverOutputNameATT",
  "solverOutputCategoryATT", "solverOutputDescriptionATT",
  "solverOutputItemList", "solverOutputItem", "solverOutputItemEmpty",
  "solverOutputItemContent", "@5", "descriptionAttribute",
  "descriptionAttributeIdentifier", "descriptionAttributeValue",
  "nameAttribute", "nameAttributeIdentifier", "nameAttributeValue",
  "typeAttribute", "typeAttributeIdentifier", "typeAttributeValue",
  "aNumber", "quote", "ElementValue", "xmlWhiteSpaceChar", "xmlWhiteSpace", 0
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
     176,   177,   178,   178,   179,   179,   179,   180,   181,   181,
     182,   182,   183,   184,   184,   185,   186,   187,   188,   188,
     189,   189,   190,   190,   191,   192,   193,   193,   193,   194,
     195,   196,   196,   196,   197,   198,   199,   199,   199,   200,
     201,   202,   202,   202,   203,   204,   205,   205,   205,   206,
     207,   208,   208,   208,   209,   210,   211,   211,   211,   212,
     213,   214,   215,   215,   216,   216,   217,   218,   218,   219,
     220,   221,   222,   222,   223,   223,   223,   224,   225,   225,
     226,   226,   227,   227,   228,   228,   228,   229,   229,   230,
     230,   230,   230,   230,   230,   231,   232,   233,   233,   233,
     234,   235,   236,   237,   237,   238,   238,   239,   240,   240,
     241,   241,   242,   243,   244,   245,   245,   246,   246,   247,
     248,   248,   249,   249,   250,   251,   252,   253,   253,   254,
     254,   255,   256,   256,   257,   257,   258,   259,   260,   260,
     261,   261,   262,   263,   264,   265,   266,   266,   267,   267,
     268,   269,   269,   270,   271,   272,   273,   273,   274,   274,
     274,   275,   276,   276,   277,   277,   278,   278,   279,   279,
     279,   280,   280,   281,   281,   281,   281,   281,   281,   282,
     283,   284,   284,   284,   285,   286,   287,   287,   287,   288,
     289,   290,   290,   290,   291,   292,   293,   293,   293,   294,
     295,   296,   296,   296,   297,   298,   299,   300,   300,   301,
     301,   302,   303,   303,   304,   305,   306,   307,   307,   308,
     308,   308,   309,   310,   310,   311,   311,   312,   312,   313,
     313,   313,   314,   314,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   316,   317,   318,   318,   318,
     319,   320,   321,   321,   321,   322,   323,   324,   324,   324,
     325,   326,   327,   327,   327,   328,   329,   330,   330,   330,
     331,   332,   333,   334,   334,   335,   335,   336,   337,   337,
     338,   338,   338,   338,   339,   339,   340,   340,   341,   341,
     342,   342,   343,   343,   344,   344,   345,   345,   346,   346,
     347,   348,   349,   350,   350,   351,   351,   352,   353,   353,
     354,   354,   355,   356,   357,   358,   358,   359,   359,   360,
     361,   361,   362,   362,   363,   364,   365,   366,   366,   367,
     367,   368,   369,   369,   370,   370,   371,   372,   373,   373,
     374,   374,   375,   376,   377,   378,   379,   379,   380,   380,
     381,   382,   382,   383,   384,   385,   386,   386,   387,   387,
     387,   388,   389,   389,   390,   390,   391,   391,   392,   392,
     393,   394,   395,   395,   396,   396,   396,   396,   397,   398,
     399,   400,   401,   401,   402,   402,   403,   404,   404,   405,
     406,   407,   408,   408,   409,   409,   410,   411,   412,   413,
     414,   415,   416,   416,   417,   417,   417,   418,   418,   419,
     420,   420,   421,   421,   422,   423,   423,   424,   425,   426,
     427,   427,   428,   428,   429,   430,   430,   431,   431,   432,
     432,   432,   432,   433,   433,   434,   435,   435,   436,   436,
     437,   438,   438,   439,   440,   441,   441,   442,   442,   443,
     444,   444,   445,   446,   447,   448,   448,   449,   449,   450,
     451,   452,   452,   453,   453,   454,   455,   455,   456,   457,
     458,   459,   459,   460,   461,   462,   462,   463,   463,   464,
     465,   465,   466,   467,   468,   469,   469,   470,   471,   472,
     473,   473,   474,   474,   474,   474,   475,   476,   476,   477,
     477,   478,   478,   479,   479,   480,   480,   481,   482,   483,
     484,   484,   484,   485,   485,   486,   486,   487,   487,   488,
     489,   489,   490,   491,   492,   492,   493,   493,   494,   495,
     495,   496,   497,   498,   499,   499,   500,   500,   501,   502,
     503,   504,   504,   505,   505,   505,   505,   506,   507,   507,
     508,   508,   509,   509,   510,   510,   511,   511,   512,   513,
     514,   515,   515,   515,   516,   516,   517,   517,   518,   518,
     519,   520,   520,   521,   522,   523,   523,   524,   524,   525,
     526,   526,   527,   528,   529,   530,   530,   531,   531,   532,
     533,   534,   535,   535,   536,   536,   536,   536,   537,   538,
     538,   539,   539,   540,   540,   541,   541,   542,   542,   543,
     544,   545,   546,   546,   546,   547,   547,   547,   549,   548,
     550,   550,   551,   551,   552,   553,   552,   554,   554,   554,
     554,   555,   556,   556,   557,   557,   558,   558,   559,   559,
     560,   560,   561,   561,   563,   562,   564,   565,   565,   566,
     567,   567,   568,   568,   569,   569,   570,   571,   570,   572,
     572,   572,   572,   573,   574,   574,   575,   575,   576,   576,
     577,   577,   578,   578,   579,   579,   581,   580,   582,   583,
     584,   584,   585,   586,   587,   587,   588,   589,   590,   590,
     591,   591,   592,   593,   593,   593,   594,   594,   594,   594,
     595,   595
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     3,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     4,     1,     1,
       2,     1,     3,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     2,     1,     2,     1,     3,     2,     1,     2,
       1,     3,     2,     1,     2,     1,     3,     2,     1,     2,
       1,     3,     2,     1,     2,     1,     3,     2,     1,     2,
       1,     3,     2,     1,     2,     1,     3,     2,     1,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     3,     3,     1,
       3,     1,     2,     1,     0,     2,     4,     0,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     2,     1,
       5,     1,     1,     0,     2,     1,     1,     3,     3,     1,
       1,     1,     5,     1,     1,     0,     2,     1,     1,     3,
       3,     1,     1,     1,     5,     1,     1,     0,     2,     1,
       1,     3,     3,     1,     1,     1,     5,     1,     0,     1,
       3,     1,     1,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     3,     3,     1,     3,     1,     2,     1,     0,     2,
       4,     0,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     2,     1,     2,     1,     3,     2,     1,     2,
       1,     3,     2,     1,     2,     1,     3,     2,     1,     2,
       1,     3,     2,     1,     3,     1,     4,     1,     1,     2,
       1,     3,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     3,     3,     1,     3,     1,     2,     1,     0,
       2,     4,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     2,     1,
       2,     1,     3,     2,     1,     2,     1,     3,     2,     1,
       2,     1,     3,     2,     1,     2,     1,     3,     2,     1,
       3,     1,     4,     1,     3,     0,     2,     3,     0,     2,
       1,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     2,     1,     3,     0,     1,     1,
       5,     1,     1,     0,     2,     1,     1,     3,     3,     1,
       1,     1,     5,     1,     1,     0,     2,     1,     1,     3,
       3,     1,     1,     1,     5,     1,     1,     0,     2,     1,
       1,     3,     3,     1,     1,     1,     5,     1,     0,     1,
       3,     1,     1,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     3,     3,     1,     3,     1,     2,     1,     0,     3,
       1,     1,     0,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     1,     1,     2,     1,     4,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     4,     3,     8,     3,
       1,     1,     1,     2,     1,     1,     1,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     3,     3,     1,     2,     1,     0,
       4,     3,     2,     0,     3,     1,     0,     4,     1,     1,
       6,     0,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     5,     1,     4,     1,     1,     0,     3,     1,
       4,     1,     1,     2,     1,     3,     1,     2,     5,     1,
       4,     0,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     5,     1,     4,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     4,     3,     1,     3,
       1,     3,     1,     1,     3,     0,     2,     3,     1,     4,
       3,     2,     1,     0,     3,     0,     4,     1,     1,     4,
       0,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       2,     5,     1,     4,     1,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     4,     3,     1,
       3,     1,     3,     1,     1,     3,     0,     2,     3,     1,
       4,     3,     2,     1,     0,     3,     0,     4,     1,     1,
       4,     0,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     5,     1,     4,     1,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     4,     3,
       1,     3,     1,     3,     1,     1,     3,     0,     2,     3,
       1,     4,     3,     2,     1,     0,     5,     3,     0,     5,
       0,     2,     5,     3,     0,     0,     3,     1,     1,     1,
       1,     4,     1,     3,     3,     1,     3,     1,     0,     2,
       1,     1,     1,     1,     0,     4,     1,     0,     3,     4,
       1,     3,     0,     2,     5,     3,     0,     0,     3,     1,
       1,     1,     1,     4,     1,     3,     3,     1,     3,     1,
       0,     2,     1,     1,     1,     1,     0,     4,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,   104,     4,
       8,     6,     0,   188,     0,   107,   105,     0,   249,     7,
      20,    60,    65,    45,    80,    55,    50,    70,    75,     9,
      10,     0,    11,     0,    12,     0,    13,     0,    14,     0,
      15,     0,    16,     0,    17,     0,    18,     0,     0,   191,
     189,     0,   388,     0,   699,   707,     0,    21,    22,    26,
      25,   720,    24,   720,     0,    48,    44,     0,    53,    49,
       0,    58,    54,     0,    63,    59,     0,    68,    64,     0,
      73,    69,     0,    78,    74,   720,     0,   106,   157,   145,
     121,   133,   164,   116,   108,   109,     0,   110,   123,   111,
     135,   112,   147,   113,   158,   114,     0,     0,   252,   250,
     390,     0,   392,     0,     0,    31,    19,    28,    29,    23,
     720,   698,   701,     0,   720,   706,   709,     0,    47,     0,
      52,     0,    57,     0,    62,     0,    67,     0,    72,     0,
      77,     0,     0,    85,    79,    82,    83,     0,   119,   115,
       0,   122,     0,   134,     0,   146,     0,   161,     0,   159,
     720,     0,   190,   205,   200,   225,   220,   215,   210,   192,
     193,     0,   194,     0,   195,     0,   196,     0,   197,     0,
     198,     0,     0,     2,     0,   391,     0,    30,    36,     0,
      33,    38,   700,   712,   716,   717,   718,   719,   721,   708,
      46,    51,    56,    61,    66,    71,    76,   720,    90,    84,
       0,    87,    92,     0,   118,     0,     0,   129,     0,   124,
     125,   126,     0,     0,   141,     0,   136,   137,   138,     0,
       0,   153,     0,   148,   149,   150,   720,     0,     0,     0,
     169,   163,   166,   167,     0,   203,   199,     0,   208,   204,
       0,   213,   209,     0,   218,   214,     0,   223,   219,   720,
       0,   251,   281,   286,   364,   276,   266,   271,   291,   357,
     345,   321,   333,   253,   254,     0,   255,     0,   256,     0,
     257,     0,   258,     0,   259,     0,   260,   323,   261,   335,
     262,   347,   263,   358,   264,     0,     0,   405,   389,   402,
     403,   720,   720,   720,   720,   393,   720,   720,   720,   720,
      27,    32,    34,     0,    37,    81,    86,    88,     0,    91,
     117,   130,   131,     0,   720,   720,   142,   143,     0,   720,
     720,   154,   155,     0,   720,   720,   160,   162,     0,   720,
     174,   168,     0,   171,   176,     0,   202,     0,   207,     0,
     212,     0,   217,   710,   711,   222,     0,     0,     0,   230,
     224,   227,   228,     0,   269,   265,     0,   274,   270,     0,
     279,   275,     0,   284,   280,     0,   289,   285,     0,     0,
       0,   322,     0,   334,     0,   346,     0,   361,     0,   359,
     720,     0,   404,   410,   667,   407,   412,     0,     0,     0,
       0,   394,   395,   396,   397,     0,    43,    35,   703,    39,
      41,    40,   720,     0,   103,    89,     0,   101,     0,     0,
      99,    93,    94,    95,    96,   120,   128,   127,   132,   140,
     139,   144,   152,   151,   156,   165,   170,   172,     0,   175,
     201,   206,   211,   216,   221,   720,   235,   229,     0,   232,
     237,     0,   268,     0,   273,     0,   278,     0,   283,     0,
     288,     0,   295,   293,   290,     0,     0,   329,     0,   324,
     325,   326,     0,     0,   341,     0,   336,   337,   338,     0,
       0,   353,     0,   348,   349,   350,   720,     0,     0,     0,
     369,   363,   366,   367,     0,   408,     0,     0,   411,   400,
     401,   398,   399,    42,   720,   702,   705,   102,   720,   720,
     720,     0,   187,   173,     0,   185,     0,     0,   183,   177,
     178,   179,   180,   226,   231,   233,     0,   236,   267,   272,
     277,   282,   287,     0,     0,   330,   331,     0,   720,   720,
     342,   343,     0,   720,   720,   354,   355,     0,   720,   720,
     360,   362,     0,   720,   374,   368,     0,   371,   376,   720,
       0,   406,     0,   409,   720,     0,   413,   414,   415,   704,
     100,    97,    98,   186,   720,   720,   720,     0,   248,   234,
       0,   246,     0,     0,   244,   238,   239,   240,   241,   292,
     298,   294,   296,   320,   328,   327,   332,   340,   339,   344,
     352,   351,   356,   365,   370,   372,     0,   375,     0,   672,
     670,   668,   420,   449,     0,     0,   720,   184,   181,   182,
     247,   720,   720,   720,   317,     0,   387,   373,     0,   385,
       0,     0,   383,   377,   378,   379,   380,   720,     0,     0,
     453,     0,     0,   428,     0,   421,   422,   425,   426,   424,
     720,   417,   245,   242,   243,     0,   315,     0,   307,     0,
     311,     0,   305,     0,   309,   299,   301,   302,   300,   303,
     297,   312,   313,   386,   720,   720,   720,   669,   671,   676,
     673,     0,   452,   455,   533,   456,     0,   720,     0,   433,
     419,   430,   431,   423,   416,   319,   318,   314,     0,     0,
       0,     0,     0,   384,   381,   382,   677,     0,   451,   535,
     584,   720,     0,     0,   427,   432,   438,     0,   435,   440,
     316,   306,   310,   304,   308,   690,   675,     0,   450,   720,
       0,   586,   635,     0,   461,   458,   454,   459,   429,   434,
     436,     0,   439,     0,     0,     0,   687,     0,   689,     0,
     684,   678,   679,   680,   681,   682,     0,   540,   537,   534,
     538,   720,     0,     0,     0,   720,   463,   477,     0,     0,
     448,   437,     0,   446,     0,   441,   442,   443,     0,   694,
     695,   674,   691,   692,   693,     0,     0,     0,     0,   720,
     542,   556,     0,     0,   591,   588,   585,   589,     0,     0,
     666,   418,   457,   479,   491,     0,   720,     0,   447,     0,
       0,   696,     0,   686,   688,   685,   536,     0,   720,     0,
     720,   593,   607,     0,     0,   640,   637,   493,   505,     0,
     720,     0,     0,     0,   468,   462,   465,   466,   445,   444,
       0,   683,   539,   559,   557,   561,     0,     0,   547,   541,
     544,   545,   587,     0,   720,     0,   638,     0,     0,   720,
       0,     0,     0,   484,   478,   481,   482,   720,   467,   473,
       0,   470,     0,   697,     0,   560,   720,   552,   546,     0,
     549,     0,   590,   610,   608,   612,     0,     0,   598,   592,
     595,   596,     0,   644,   636,   641,   508,   460,   506,   510,
       0,     0,   498,   492,   495,   496,   720,   483,   489,     0,
     486,     0,   464,   469,   471,   720,     0,   576,   574,   558,
     720,     0,   573,     0,   571,     0,   569,   562,   563,   564,
     565,   566,   543,   548,   550,   720,     0,     0,   611,   720,
     603,   597,     0,   600,     0,   639,   645,     0,   509,   720,
     497,   503,     0,   500,     0,   480,   485,   487,   720,     0,
       0,     0,     0,     0,   720,   720,   720,     0,     0,   627,
     625,   609,   720,     0,   624,     0,   622,     0,   620,   613,
     614,   615,   616,   617,   594,   599,   601,   720,     0,   658,
     643,     0,   525,   523,   507,   720,     0,   522,     0,   520,
       0,   518,   511,   512,   513,   514,   515,   494,   499,   501,
     720,     0,     0,     0,   720,   475,   476,     0,   579,   575,
     577,     0,   720,   572,   570,   568,   720,   554,   555,     0,
       0,     0,   720,   720,   720,     0,     0,     0,     0,     0,
     655,     0,   657,     0,   652,   646,   647,   648,   649,   650,
       0,     0,   720,   720,   720,     0,     0,   720,     0,   474,
     472,   720,     0,   567,   553,   551,   630,   626,   628,     0,
     720,   623,   621,   619,   720,   605,   606,     0,     0,   662,
     663,   642,   659,   660,   661,     0,     0,     0,   720,   524,
     528,   526,     0,   720,   521,   519,   517,   720,     0,   490,
     488,     0,     0,   583,   578,   720,     0,   618,   604,   602,
     664,     0,   654,   656,   653,   720,     0,   516,   504,   502,
     720,   713,   714,   715,   582,     0,     0,     0,   634,   629,
       0,   651,     0,     0,   532,   527,   580,   581,   720,   633,
       0,   665,   720,   531,     0,   631,   632,   529,   530
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    31,    56,    57,
      58,    59,   116,   117,   118,   189,   190,   191,   313,   314,
     409,   407,    32,    33,    66,    34,    35,    69,    36,    37,
      72,    38,    39,    75,    40,    41,    78,    42,    43,    81,
      44,    45,    84,    46,    47,    86,   144,   145,   146,   210,
     211,   212,   318,   319,   421,   422,   423,   424,   415,    13,
      48,    94,    95,    96,   149,    97,    98,   150,   151,   219,
     220,   221,   323,    99,   100,   152,   153,   226,   227,   228,
     328,   101,   102,   154,   155,   233,   234,   235,   333,   103,
     104,   158,   159,   338,   105,   106,   161,   241,   242,   243,
     342,   343,   344,   438,   439,   519,   520,   521,   522,   513,
      18,   107,   169,   170,   171,   246,   172,   173,   249,   174,
     175,   252,   176,   177,   255,   178,   179,   258,   180,   181,
     260,   360,   361,   362,   448,   449,   450,   526,   527,   585,
     586,   587,   588,   579,    52,   182,   273,   274,   275,   365,
     276,   277,   368,   278,   279,   371,   280,   281,   374,   282,
     283,   377,   284,   285,   379,   464,   534,   592,   624,   665,
     666,   667,   668,   669,   670,   671,   672,   698,   286,   287,
     380,   381,   469,   470,   471,   537,   288,   289,   382,   383,
     476,   477,   478,   542,   290,   291,   384,   385,   483,   484,
     485,   547,   292,   293,   388,   389,   552,   294,   295,   391,
     491,   492,   493,   556,   557,   558,   606,   607,   633,   634,
     635,   636,   627,   111,   112,   184,   185,   305,   306,   307,
     308,   309,   298,   299,   300,   394,   395,   396,   497,   498,
     566,   567,   568,   563,   613,   614,   644,   645,   646,   647,
     648,   690,   691,   692,   717,   718,   719,   741,   742,   775,
     776,   777,   771,   640,   684,   685,   712,   736,   737,   767,
     768,   807,   835,   836,   837,   870,   871,   872,   916,  1017,
     804,   805,   831,   864,   865,   866,   909,   910,   911,   959,
     828,   829,   860,   903,   904,   905,   952,   953,   954,  1011,
     858,   898,   899,   947,   948,  1002,  1003,  1004,  1005,  1006,
     994,  1050,  1091,  1092,  1116,  1135,   710,   730,   759,   760,
     791,   792,   819,   849,   850,   851,   879,   880,   881,   936,
    1029,   817,   844,   845,   874,   875,   927,   928,   929,   930,
     931,   919,   962,  1020,  1021,  1062,  1104,   732,   762,   796,
     797,   822,   823,   855,   889,   890,   891,   942,   943,   944,
     988,  1077,   853,   884,   885,   937,   938,   979,   980,   981,
     982,   983,   971,  1030,  1068,  1069,  1106,  1129,   764,   799,
     892,   857,   895,   946,   991,  1045,  1046,  1047,  1048,  1049,
    1037,  1082,  1083,  1084,  1130,   801,   496,   560,   611,   638,
     680,   706,   727,   751,   752,   753,   754,   755,   743,   782,
     783,   784,   840,    60,    61,   121,   411,   412,   505,    62,
      63,   125,   356,   122,  1125,   198,   123
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -934
static const yytype_int16 yypact[] =
{
      35,   103,   222,   104,  -934,   155,  -934,   120,   218,  -934,
    -934,  -934,   168,   254,   -19,  -934,  -934,   201,   216,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,    52,  -934,   298,  -934,   300,  -934,   302,  -934,   304,
    -934,   306,  -934,   308,  -934,   310,  -934,   307,   -17,  -934,
    -934,   312,   276,   361,  -934,  -934,   314,    52,  -934,  -934,
    -934,   419,  -934,   437,    23,  -934,  -934,    14,  -934,  -934,
      21,  -934,  -934,    29,  -934,  -934,    31,  -934,  -934,    11,
    -934,  -934,    -1,  -934,  -934,  -934,   318,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,   320,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,   301,  -934,   425,   -22,  -934,  -934,
    -934,   309,  -934,   383,   -44,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,    -7,  -934,  -934,  -934,   358,  -934,   336,
    -934,   339,  -934,   363,  -934,   359,  -934,   332,  -934,   317,
    -934,   455,    44,  -934,  -934,  -934,  -934,     2,  -934,  -934,
     452,   204,   453,   220,   454,   227,   462,  -934,   456,  -934,
    -934,   325,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,   327,  -934,   329,  -934,   331,  -934,   333,  -934,   335,
    -934,   448,   -38,  -934,   337,    58,   460,  -934,  -934,   -26,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
     145,  -934,  -934,   334,  -934,   344,   466,  -934,   467,  -934,
    -934,  -934,   346,   469,  -934,   470,  -934,  -934,  -934,   348,
     471,  -934,   474,  -934,  -934,  -934,  -934,   472,   473,   178,
    -934,  -934,  -934,  -934,    32,  -934,  -934,    36,  -934,  -934,
      -4,  -934,  -934,     0,  -934,  -934,    13,  -934,  -934,  -934,
     347,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,   349,  -934,   351,  -934,   353,
    -934,   355,  -934,   357,  -934,   457,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,   338,  -934,   464,   -13,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,   362,    34,  -934,  -934,  -934,   364,   157,
    -934,  -934,  -934,   415,  -934,  -934,  -934,  -934,   417,  -934,
    -934,  -934,  -934,   426,  -934,  -934,  -934,  -934,   427,  -934,
    -934,  -934,   180,  -934,  -934,   411,  -934,   414,  -934,   340,
    -934,   350,  -934,  -934,  -934,  -934,   374,   483,   182,  -934,
    -934,  -934,  -934,     6,  -934,  -934,    12,  -934,  -934,    17,
    -934,  -934,    33,  -934,  -934,    42,  -934,  -934,   490,   366,
     489,   231,   492,   241,   493,   245,   497,  -934,   494,  -934,
    -934,   368,  -934,  -934,   -31,  -934,  -934,   499,   500,   501,
     502,  -934,  -934,  -934,  -934,   375,  -934,  -934,  -934,  -934,
    -934,  -934,   506,   407,  -934,  -934,   512,  -934,   513,   514,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,   370,   191,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,   184,  -934,
    -934,   387,  -934,   389,  -934,   403,  -934,   458,  -934,   439,
    -934,   517,  -934,  -934,  -934,   377,   516,  -934,   521,  -934,
    -934,  -934,   379,   522,  -934,   524,  -934,  -934,  -934,   381,
     525,  -934,   526,  -934,  -934,  -934,  -934,   527,   528,   186,
    -934,  -934,  -934,  -934,   507,  -934,   475,   529,    39,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,   428,  -934,  -934,   533,  -934,   534,   535,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,   380,   194,  -934,  -934,
    -934,  -934,  -934,   523,   112,  -934,  -934,   391,  -934,  -934,
    -934,  -934,   385,  -934,  -934,  -934,  -934,   395,  -934,  -934,
    -934,  -934,   393,  -934,  -934,  -934,   188,  -934,  -934,  -934,
     382,  -934,   413,  -934,  -934,   538,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,   441,  -934,  -934,
     542,  -934,   544,   546,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,   384,   215,   545,  -934,
    -934,  -934,  -934,   459,   197,   548,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,   144,   443,  -934,  -934,   549,  -934,
     553,   554,  -934,  -934,  -934,  -934,  -934,  -934,   -56,   386,
     399,   555,   559,  -934,   388,   197,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,     7,  -934,   561,  -934,   562,
    -934,   563,  -934,   564,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,    28,  -934,  -934,   468,   550,   566,  -934,   165,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,   431,   565,
     567,   568,   569,  -934,  -934,  -934,   390,   481,  -934,   551,
     503,  -934,   392,   571,  -934,  -934,  -934,   167,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,   137,  -934,  -934,
     394,   572,   476,   574,   429,  -934,  -934,  -934,  -934,  -934,
    -934,   396,   249,     4,   575,   579,  -934,   581,  -934,   583,
    -934,  -934,  -934,  -934,  -934,  -934,   584,   435,  -934,  -934,
    -934,  -934,   398,   573,   477,  -934,  -934,   434,   570,   463,
    -934,  -934,   591,  -934,   592,  -934,  -934,  -934,   594,  -934,
    -934,  -934,  -934,  -934,  -934,   595,   589,   596,   597,  -934,
    -934,  -934,   585,   600,   519,  -934,  -934,  -934,   599,   400,
    -934,  -934,  -934,  -934,   536,   588,  -934,   402,  -934,   601,
     602,  -934,   607,  -934,  -934,  -934,  -934,   174,  -934,   404,
    -934,  -934,  -934,   604,   611,  -934,  -934,  -934,  -934,   593,
    -934,   406,   612,   143,  -934,  -934,  -934,  -934,  -934,  -934,
     576,  -934,  -934,  -934,  -934,  -934,   614,   -59,  -934,  -934,
    -934,  -934,  -934,     3,  -934,   408,  -934,   192,   -68,  -934,
     410,   615,   265,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
     147,  -934,   598,  -934,   416,   173,  -934,  -934,  -934,   -55,
    -934,   603,  -934,  -934,  -934,  -934,   616,   -53,  -934,  -934,
    -934,  -934,   617,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
     620,   -33,  -934,  -934,  -934,  -934,  -934,  -934,  -934,   269,
    -934,   605,  -934,  -934,  -934,  -934,   613,  -934,  -934,  -934,
    -934,   625,  -934,   626,  -934,   627,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,   621,   420,   152,  -934,
    -934,  -934,    71,  -934,   608,  -934,   422,   424,   169,  -934,
    -934,  -934,   -32,  -934,   609,  -934,  -934,  -934,  -934,   623,
     630,   430,    50,   633,  -934,  -934,  -934,   634,   432,  -934,
    -934,  -934,  -934,   638,  -934,   639,  -934,   640,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,   635,  -934,
    -934,   185,  -934,  -934,  -934,  -934,   641,  -934,   643,  -934,
     644,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,   642,   645,   646,  -934,  -934,  -934,   488,  -934,  -934,
    -934,   624,  -934,  -934,  -934,  -934,  -934,  -934,  -934,   556,
     -20,   648,  -934,  -934,  -934,   650,   436,    -6,   649,   655,
    -934,   656,  -934,   657,  -934,  -934,  -934,  -934,  -934,  -934,
     -57,   658,  -934,  -934,  -934,   659,   663,  -934,   508,  -934,
    -934,  -934,   438,  -934,  -934,  -934,  -934,  -934,  -934,   632,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,   586,   665,  -934,
    -934,  -934,  -934,  -934,  -934,   662,   654,   664,  -934,  -934,
    -934,  -934,   647,  -934,  -934,  -934,  -934,  -934,   510,  -934,
    -934,   667,    22,  -934,  -934,  -934,   440,  -934,  -934,  -934,
    -934,   666,  -934,  -934,  -934,  -934,   442,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,   578,   669,     1,  -934,  -934,
     619,  -934,   673,     5,  -934,  -934,  -934,  -934,  -934,  -934,
     520,  -934,  -934,  -934,   530,  -934,  -934,  -934,  -934
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
     628,  -934,  -934,  -934,  -934,  -934,   491,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
     478,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,   341,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,   234,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,   128,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,   292,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,    45,  -934,
    -934,  -934,  -934,  -934,  -934,   -30,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -181,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -217,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -259,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -185,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -247,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,  -934,
    -934,  -934,  -934,   397,  -934,  -934,  -934,  -934,  -934,  -482,
    -934,  -934,  -934,   -63,  -933,  -934,  -934
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     126,   193,   349,   139,   351,  1121,   213,  1122,  1123,  1121,
     451,  1122,  1123,   695,   696,   137,   453,   261,   129,   353,
     354,   455,   141,   940,   262,   131,  1121,   127,  1122,  1123,
      19,   162,   707,   133,    87,   135,   345,   457,   896,   877,
     950,  1008,   347,   877,   392,   187,   459,    88,   263,    89,
    1089,    90,  1078,    91,  1079,  1080,  1066,   192,   163,   678,
     164,   199,   778,   311,   779,   780,    54,   564,   408,    20,
     264,   301,   679,    21,   302,    22,    53,    23,   265,     1,
     303,   565,   882,   494,    54,   304,   165,  1067,    55,    24,
     188,    92,   266,   393,   267,   897,   458,   238,   878,    25,
     166,    26,   933,  1090,   941,  1081,   268,    27,   188,   883,
     269,   393,   270,     4,   271,   346,   272,   348,   167,    93,
     128,  1124,   134,    28,   168,   708,   136,   951,   951,   460,
      10,    11,   649,   781,   456,   130,   355,   452,   138,   214,
     132,   352,   140,   350,   315,   454,   697,   940,  1018,     5,
     208,   744,     7,   209,   655,   656,   985,  1019,   194,   195,
     196,   197,  1139,   649,   972,     9,  1143,   745,   746,   747,
     748,   749,   750,   336,   657,   658,   659,   660,    15,    16,
     661,   662,   663,   664,   973,   974,   975,   976,   920,   416,
     417,   418,   977,   978,  1140,   995,   357,   419,   420,  1038,
    1144,   996,   997,   998,   999,   921,   922,   923,   924,  1000,
    1001,    49,    50,   925,   926,  1039,  1040,  1041,  1042,  1043,
    1044,   641,     6,   514,   515,   516,   580,   581,   582,   642,
     643,   517,   518,    55,   583,   584,   216,   217,   397,   398,
     399,   400,   218,   401,   402,   403,   404,   628,   629,   630,
     590,   208,   223,   224,   316,   631,   632,   591,   225,   230,
     231,   426,   427,   466,   467,   232,   429,   430,    12,   468,
      51,   432,   433,   473,   474,   842,   435,   480,   481,   475,
     843,   772,   773,   482,   340,   774,   340,   341,   446,   436,
     446,   447,   554,   524,   554,   555,   715,   604,   739,   716,
     868,   716,   893,   869,   913,   894,    17,   869,    64,    65,
      67,    68,    70,    71,    73,    74,    76,    77,    79,    80,
      82,    83,   108,   109,   114,   115,    85,   488,   142,   143,
     147,   148,   110,   156,   157,   239,   240,   244,   245,   247,
     248,   250,   251,   253,   254,   256,   257,   296,   297,   506,
     321,   322,   326,   327,   331,   332,   183,   358,   359,   363,
     364,   366,   367,   369,   370,   372,   373,   375,   376,   113,
     386,   387,   405,   406,   413,   414,   462,   463,   489,   490,
     511,   512,   523,   535,   536,   540,   541,   545,   546,   186,
     577,   578,   609,   610,   625,   626,   681,   682,   688,   689,
     725,   726,   734,   735,   757,   758,   769,   770,   794,   795,
     825,   826,   833,   834,   847,   848,   862,   863,   887,   888,
     901,   902,   120,   550,   907,   908,   917,   918,   956,   908,
     969,   970,   989,   990,   992,   993,  1015,  1016,  1027,  1028,
     124,   569,  1075,  1076,   160,   570,   571,   572,  1102,  1103,
    1127,  1128,  1133,  1134,   204,   200,   203,   201,   202,   205,
     206,   207,   215,   222,   229,   236,   237,   259,   310,   324,
     325,   320,   329,   330,   334,   594,   595,   335,   337,   339,
     597,   598,   378,   390,   425,   600,   601,   442,   428,   445,
     603,   443,   434,   431,   440,   441,   608,   444,   461,   465,
     486,   615,   472,   479,   487,   499,   500,   501,   502,   504,
     503,   617,   618,   619,   507,   508,   509,   510,   528,   538,
     530,   531,   529,   533,   539,   543,   532,   544,   548,   549,
     559,   589,   561,   551,   553,   573,   574,   575,   576,   562,
     596,   616,   602,   612,   593,   621,   599,   622,   620,   623,
     673,   637,   674,   651,   650,   639,   675,   676,   652,   653,
     654,   683,   687,   686,   699,   700,   701,   702,   709,   729,
     720,   711,   713,   721,   677,   722,   723,   724,   728,   738,
     765,   731,   786,   785,   787,   766,   788,   694,   763,   761,
     789,   790,   803,   798,   809,   810,   806,   813,   808,   811,
     818,   812,   800,   821,   814,   815,   820,   824,   827,   838,
     839,   703,   704,   705,   830,   841,   854,   856,   867,   859,
     876,   906,   939,   961,   714,   945,   949,   915,   964,   965,
     966,   968,   935,  1013,   958,   873,  1014,   987,  1010,  1022,
    1026,  1032,  1033,  1034,  1052,  1036,  1053,  1054,   733,  1060,
    1058,  1057,  1056,  1061,  1070,  1065,  1074,  1085,  1086,  1087,
    1088,  1105,  1112,  1109,  1093,  1097,   756,  1098,  1111,  1100,
    1110,  1119,  1113,  1120,  1131,  1138,  1115,  1137,  1141,  1142,
     312,  1146,   525,   437,   605,   119,   495,   740,   317,   914,
     693,  1148,   957,  1009,   934,   986,     0,     0,   793,     0,
       0,     0,   802,     0,     0,     0,     0,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   816,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   832,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   846,     0,   852,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   861,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   886,     0,     0,     0,     0,   900,     0,     0,     0,
       0,     0,     0,     0,   912,     0,     0,     0,     0,     0,
       0,     0,     0,   932,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   955,     0,     0,     0,     0,     0,     0,
       0,     0,   960,     0,     0,     0,     0,   963,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   967,     0,     0,     0,   984,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1007,     0,     0,     0,
       0,     0,     0,     0,     0,  1012,     0,     0,     0,     0,
       0,  1023,  1024,  1025,     0,     0,     0,     0,     0,  1031,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1035,     0,     0,     0,     0,     0,
       0,     0,  1051,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1055,     0,     0,
       0,  1059,     0,     0,     0,     0,     0,     0,     0,  1063,
       0,     0,     0,  1064,     0,     0,     0,     0,     0,  1071,
    1072,  1073,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1094,
    1095,  1096,     0,     0,  1099,     0,     0,     0,  1101,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,     0,     0,
       0,  1108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1114,     0,     0,     0,     0,
    1117,     0,     0,     0,  1118,     0,     0,     0,     0,     0,
       0,     0,  1126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1132,     0,     0,     0,     0,  1136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1145,     0,     0,     0,  1147
};

static const yytype_int16 yycheck[] =
{
      63,     8,     6,     4,     4,     4,     4,     6,     7,     4,
       4,     6,     7,     6,     7,     4,     4,    55,     4,     6,
       7,     4,    85,    76,    62,     4,     4,     4,     6,     7,
      49,    53,     4,     4,    51,     4,     4,     4,   106,    98,
      73,    73,     6,    98,    57,    89,     4,    64,    86,    66,
     107,    68,    58,    70,    60,    61,    76,   120,    80,   115,
      82,   124,    58,    89,    60,    61,    32,    28,    34,    88,
     108,    13,   128,    92,    16,    94,    24,    96,   116,    44,
      22,    42,    79,   114,    32,    27,   108,   107,    36,   108,
     134,   108,   130,   124,   132,   163,    63,   160,   157,   118,
     122,   120,   157,   160,   157,   111,   144,   126,   134,   106,
     148,   124,   150,    10,   152,    83,   154,    81,   140,   136,
      97,    99,    93,   142,   146,    97,    95,   160,   160,    87,
      10,    11,   614,   129,   117,   121,   123,   131,   127,   137,
     119,   141,   143,   147,   207,   133,   139,    76,    98,    46,
     106,    14,    48,   109,    10,    11,    85,   107,   165,   166,
     167,   168,   161,   645,    12,    10,   161,    30,    31,    32,
      33,    34,    35,   236,    30,    31,    32,    33,    10,    11,
      36,    37,    38,    39,    32,    33,    34,    35,    15,    32,
      33,    34,    40,    41,  1127,    26,   259,    40,    41,    14,
    1133,    32,    33,    34,    35,    32,    33,    34,    35,    40,
      41,    10,    11,    40,    41,    30,    31,    32,    33,    34,
      35,    24,     0,    32,    33,    34,    32,    33,    34,    32,
      33,    40,    41,    36,    40,    41,    32,    33,   301,   302,
     303,   304,    38,   306,   307,   308,   309,    32,    33,    34,
     138,   106,    32,    33,   109,    40,    41,   145,    38,    32,
      33,   324,   325,    32,    33,    38,   329,   330,    50,    38,
      54,   334,   335,    32,    33,   101,   339,    32,    33,    38,
     106,    32,    33,    38,   106,    36,   106,   109,   106,   109,
     106,   109,   106,   109,   106,   109,   131,   109,   131,   134,
     157,   134,   110,   160,   157,   113,    52,   160,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    19,   390,    10,    11,
      10,    11,    56,    32,    33,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   412,
       6,     7,     6,     7,     6,     7,    47,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,     8,
      32,    33,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,   445,     6,     7,     6,     7,     6,     7,     6,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,     3,   486,   159,   160,    10,    11,   159,   160,
      10,    11,    10,    11,    10,    11,     6,     7,     6,     7,
       3,   504,     6,     7,    19,   508,   509,   510,    10,    11,
      10,    11,    10,    11,    95,    97,    93,   121,   119,   127,
     143,     6,    10,    10,    10,     3,    10,    19,     8,     3,
       3,   137,     3,     3,     3,   538,   539,     3,     6,     6,
     543,   544,    25,    19,    69,   548,   549,   147,    71,     6,
     553,   141,    65,    67,    83,    81,   559,   123,     8,    10,
       3,   564,    10,    10,    10,     6,     6,     6,     6,     3,
     135,   574,   575,   576,   107,     3,     3,     3,   131,     3,
     117,    63,   133,     6,     3,     3,    87,     3,     3,     3,
      23,     8,    57,     6,     6,   107,     3,     3,     3,    10,
     155,     3,   149,   130,   153,     3,   151,     3,   107,     3,
     107,     6,     3,   616,     6,    96,     3,     3,   621,   622,
     623,   162,     3,     8,     3,     3,     3,     3,   100,    18,
     139,    21,     6,     8,   637,     8,     8,     8,    97,     8,
       6,    78,     3,     8,     3,   156,     3,   650,   112,    17,
       6,   156,   158,    20,     3,     3,    26,     8,   135,     5,
      15,     6,   125,    84,     8,     8,     6,     8,    72,     8,
       8,   674,   675,   676,    26,     8,    12,     6,     6,    26,
       6,     6,     6,    10,   687,     8,     6,    29,     3,     3,
       3,    10,    29,    10,    29,    59,     6,    29,    29,     6,
       6,     3,     3,     3,     3,    10,     3,     3,   711,   161,
       4,     6,    10,    29,     6,    99,     6,     8,     3,     3,
       3,    29,     8,    77,     6,     6,   729,     4,     6,   161,
       5,   161,     8,     6,     8,     6,    29,    99,    59,     6,
     189,   161,   448,   342,   556,    57,   394,   717,   210,   870,
     645,   161,   909,   952,   879,   942,    -1,    -1,   761,    -1,
      -1,    -1,   765,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   789,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   806,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   818,    -1,   820,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   830,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   854,    -1,    -1,    -1,    -1,   859,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   867,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   876,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   906,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   915,    -1,    -1,    -1,    -1,   920,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   935,    -1,    -1,    -1,   939,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   949,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   958,    -1,    -1,    -1,    -1,
      -1,   964,   965,   966,    -1,    -1,    -1,    -1,    -1,   972,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   987,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   995,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1010,    -1,    -1,
      -1,  1014,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1022,
      -1,    -1,    -1,  1026,    -1,    -1,    -1,    -1,    -1,  1032,
    1033,  1034,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1052,
    1053,  1054,    -1,    -1,  1057,    -1,    -1,    -1,  1061,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1070,    -1,    -1,
      -1,  1074,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1088,    -1,    -1,    -1,    -1,
    1093,    -1,    -1,    -1,  1097,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1115,    -1,    -1,    -1,    -1,  1120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1138,    -1,    -1,    -1,  1142
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   228,   173,    10,    11,    52,   279,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   176,   191,   192,   194,   195,   197,   198,   200,   201,
     203,   204,   206,   207,   209,   210,   212,   213,   229,    10,
      11,    54,   313,    24,    32,    36,   177,   178,   179,   180,
     582,   583,   588,   589,    10,    11,   193,    10,    11,   196,
      10,    11,   199,    10,    11,   202,    10,    11,   205,    10,
      11,   208,    10,    11,   211,    19,   214,    51,    64,    66,
      68,    70,   108,   136,   230,   231,   232,   234,   235,   242,
     243,   250,   251,   258,   259,   263,   264,   280,    10,    11,
      56,   392,   393,     8,    10,    11,   181,   182,   183,   179,
       3,   584,   592,   595,     3,   590,   592,     4,    97,     4,
     121,     4,   119,     4,    93,     4,    95,     4,   127,     4,
     143,   592,    10,    11,   215,   216,   217,    10,    11,   233,
     236,   237,   244,   245,   252,   253,    32,    33,   260,   261,
      19,   265,    53,    80,    82,   108,   122,   140,   146,   281,
     282,   283,   285,   286,   288,   289,   291,   292,   294,   295,
     297,   298,   314,    47,   394,   395,     6,    89,   134,   184,
     185,   186,   592,     8,   165,   166,   167,   168,   594,   592,
      97,   121,   119,    93,    95,   127,   143,     6,   106,   109,
     218,   219,   220,     4,   137,    10,    32,    33,    38,   238,
     239,   240,    10,    32,    33,    38,   246,   247,   248,    10,
      32,    33,    38,   254,   255,   256,     3,    10,   592,    10,
      11,   266,   267,   268,    10,    11,   284,    10,    11,   287,
      10,    11,   290,    10,    11,   293,    10,    11,   296,    19,
     299,    55,    62,    86,   108,   116,   130,   132,   144,   148,
     150,   152,   154,   315,   316,   317,   319,   320,   322,   323,
     325,   326,   328,   329,   331,   332,   347,   348,   355,   356,
     363,   364,   371,   372,   376,   377,    10,    11,   401,   402,
     403,    13,    16,    22,    27,   396,   397,   398,   399,   400,
       8,    89,   185,   187,   188,   592,   109,   219,   221,   222,
     137,     6,     7,   241,     3,     3,     6,     7,   249,     3,
       3,     6,     7,   257,     3,     3,   592,     6,   262,     6,
     106,   109,   269,   270,   271,     4,    83,     6,    81,     6,
     147,     4,   141,     6,     7,   123,   591,   592,    10,    11,
     300,   301,   302,    10,    11,   318,    10,    11,   321,    10,
      11,   324,    10,    11,   327,    10,    11,   330,    25,   333,
     349,   350,   357,   358,   365,   366,    32,    33,   373,   374,
      19,   378,    57,   124,   404,   405,   406,   592,   592,   592,
     592,   592,   592,   592,   592,    10,    11,   190,    34,   189,
     582,   585,   586,    10,    11,   227,    32,    33,    34,    40,
      41,   223,   224,   225,   226,    69,   592,   592,    71,   592,
     592,    67,   592,   592,    65,   592,   109,   270,   272,   273,
      83,    81,   147,   141,   123,     6,   106,   109,   303,   304,
     305,     4,   131,     4,   133,     4,   117,     4,    63,     4,
      87,     8,    10,    11,   334,    10,    32,    33,    38,   351,
     352,   353,    10,    32,    33,    38,   359,   360,   361,    10,
      32,    33,    38,   367,   368,   369,     3,    10,   592,    10,
      11,   379,   380,   381,   114,   405,   565,   407,   408,     6,
       6,     6,     6,   135,     3,   587,   592,   107,     3,     3,
       3,    10,    11,   278,    32,    33,    34,    40,    41,   274,
     275,   276,   277,   592,   109,   304,   306,   307,   131,   133,
     117,    63,    87,     6,   335,     6,     7,   354,     3,     3,
       6,     7,   362,     3,     3,     6,     7,   370,     3,     3,
     592,     6,   375,     6,   106,   109,   382,   383,   384,    23,
     566,    57,    10,   412,    28,    42,   409,   410,   411,   592,
     592,   592,   592,   107,     3,     3,     3,    10,    11,   312,
      32,    33,    34,    40,    41,   308,   309,   310,   311,     8,
     138,   145,   336,   153,   592,   592,   155,   592,   592,   151,
     592,   592,   149,   592,   109,   383,   385,   386,   592,    10,
      11,   567,   130,   413,   414,   592,     3,   592,   592,   592,
     107,     3,     3,     3,   337,    10,    11,   391,    32,    33,
      34,    40,    41,   387,   388,   389,   390,     6,   568,    96,
     432,    24,    32,    33,   415,   416,   417,   418,   419,   588,
       6,   592,   592,   592,   592,    10,    11,    30,    31,    32,
      33,    36,    37,    38,    39,   338,   339,   340,   341,   342,
     343,   344,   345,   107,     3,     3,     3,   592,   115,   128,
     569,    10,    11,   162,   433,   434,     8,     3,    10,    11,
     420,   421,   422,   417,   592,     6,     7,   139,   346,     3,
       3,     3,     3,   592,   592,   592,   570,     4,    97,   100,
     485,    21,   435,     6,   592,   131,   134,   423,   424,   425,
     139,     8,     8,     8,     8,    10,    11,   571,    97,    18,
     486,    78,   516,   592,    10,    11,   436,   437,     8,   131,
     424,   426,   427,   577,    14,    30,    31,    32,    33,    34,
      35,   572,   573,   574,   575,   576,   592,    10,    11,   487,
     488,    17,   517,   112,   547,     6,   156,   438,   439,    10,
      11,   431,    32,    33,    36,   428,   429,   430,    58,    60,
      61,   129,   578,   579,   580,     8,     3,     3,     3,     6,
     156,   489,   490,   592,    10,    11,   518,   519,    20,   548,
     125,   564,   592,   158,   449,   450,    26,   440,   135,     3,
       3,     5,     6,     8,     8,     8,   592,   500,    15,   491,
       6,    84,   520,   521,     8,    10,    11,    72,   459,   460,
      26,   451,   592,    10,    11,   441,   442,   443,     8,     8,
     581,     8,   101,   106,   501,   502,   592,    10,    11,   492,
     493,   494,   592,   531,    12,   522,     6,   550,   469,    26,
     461,   592,    10,    11,   452,   453,   454,     6,   157,   160,
     444,   445,   446,    59,   503,   504,     6,    98,   157,   495,
     496,   497,    79,   106,   532,   533,   592,    10,    11,   523,
     524,   525,   549,   110,   113,   551,   106,   163,   470,   471,
     592,    10,    11,   462,   463,   464,     6,   159,   160,   455,
     456,   457,   592,   157,   445,    29,   447,    10,    11,   510,
      15,    32,    33,    34,    35,    40,    41,   505,   506,   507,
     508,   509,   592,   157,   496,    29,   498,   534,   535,     6,
      76,   157,   526,   527,   528,     8,   552,   472,   473,     6,
      73,   160,   465,   466,   467,   592,   159,   456,    29,   458,
     592,    10,   511,   592,     3,     3,     3,   592,    10,    10,
      11,   541,    12,    32,    33,    34,    35,    40,    41,   536,
     537,   538,   539,   540,   592,    85,   527,    29,   529,    10,
      11,   553,    10,    11,   479,    26,    32,    33,    34,    35,
      40,    41,   474,   475,   476,   477,   478,   592,    73,   466,
      29,   468,   592,    10,     6,     6,     7,   448,    98,   107,
     512,   513,     6,   592,   592,   592,     6,     6,     7,   499,
     542,   592,     3,     3,     3,   592,    10,   559,    14,    30,
      31,    32,    33,    34,    35,   554,   555,   556,   557,   558,
     480,   592,     3,     3,     3,   592,    10,     6,     4,   592,
     161,    29,   514,   592,   592,    99,    76,   107,   543,   544,
       6,   592,   592,   592,     6,     6,     7,   530,    58,    60,
      61,   111,   560,   561,   562,     8,     3,     3,     3,   107,
     160,   481,   482,     6,   592,   592,   592,     6,     4,   592,
     161,   592,    10,    11,   515,    29,   545,   592,   592,    77,
       5,     6,     8,     8,   592,    29,   483,   592,   592,   161,
       6,     4,     6,     7,    99,   593,   592,    10,    11,   546,
     563,     8,   592,    10,    11,   484,   592,    99,     6,   161,
     593,    59,     6,   161,   593,   592,   161,   592,   161
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
        case 20:

    {	if (parserData->generalStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one generalStatus element allowed");	
		if (osresult->general->generalStatus != NULL) 
			osrlerror(NULL, NULL, parserData, "generalStatus previously allocated");
		osresult->general->generalStatus = new GeneralStatus();
		parserData->generalStatusPresent = true;
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
	;}
    break;

  case 21:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	;}
    break;

  case 24:

    { 
	    if ((parserData->typeAttribute != "error"  ) &&
	        (parserData->typeAttribute != "warning") && 
	        (parserData->typeAttribute != "normal"))
			osrlerror(NULL, NULL, parserData, "general status type does not match any legal value");
		osresult->setGeneralStatusType(parserData->typeAttribute); 
	;}
    break;

  case 25:

    {   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	;}
    break;

  case 27:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for generalStatus element");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of general substatuses cannot be negative");
    osresult->setNumberOfGeneralSubstatuses((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 28:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 29:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 35:

    {	parserData->kounter++;
;}
    break;

  case 36:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 37:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
;}
    break;

  case 40:

    {	osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 41:

    {	
		osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 45:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 46:

    {osresult->setGeneralMessage((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 50:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 51:

    {osresult->setServiceURI((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 55:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 56:

    {osresult->setServiceName((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 60:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 61:

    {osresult->setInstanceName((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 65:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 66:

    {osresult->setJobID((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 70:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 71:

    {osresult->setSolverInvoked((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 75:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 76:

    {osresult->setTimeStamp((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 80:

    {	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	;}
    break;

  case 81:

    {	osresult->setNumberOfOtherGeneralResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 82:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 83:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 89:

    {	parserData->kounter++;
;}
    break;

  case 90:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 91:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 94:

    {	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setGeneralOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 95:

    {	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setGeneralOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 96:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setGeneralOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 97:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 98:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 99:

    { parserData->tempStr = "";          ;}
    break;

  case 100:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 101:

    { parserData->tempStr = "";          ;}
    break;

  case 116:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 117:

    {osresult->setSystemInformation((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 121:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
	;}
    break;

  case 122:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 125:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableDiskSpace>");
		parserData->unitAttributePresent = true;		
		osresult->setAvailableDiskSpaceUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 126:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableDiskSpace>");
		parserData->descriptionAttributePresent = true;		
		osresult->setAvailableDiskSpaceDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 127:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
		if (parserData->tempStr != "exabyte"  && parserData->tempStr != "petabyte" && 
			parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" &&
			parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && 
			parserData->tempStr != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
	;}
    break;

  case 128:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 129:

    { parserData->tempStr = "";          ;}
    break;

  case 130:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 131:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 133:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
	;}
    break;

  case 134:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 137:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableMemory>");
		parserData->unitAttributePresent = true;		
		osresult->setAvailableMemoryUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 138:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableMemory>");
		parserData->descriptionAttributePresent = true;		
		osresult->setAvailableMemoryDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 139:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
		if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
			parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
			osrlerror(NULL, NULL, parserData, "availableMemory unit not recognized");
;}
    break;

  case 140:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 141:

    { parserData->tempStr = "";          ;}
    break;

  case 142:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 143:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 145:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
	;}
    break;

  case 146:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 149:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableCPUSpeed>");
		parserData->unitAttributePresent = true;		
		osresult->setAvailableCPUSpeedUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 150:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableMemory>");
		parserData->descriptionAttributePresent = true;		
		osresult->setAvailableCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 151:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "terahertz" && parserData->tempStr != "gigahertz" && 
		parserData->tempStr != "megahertz" && parserData->tempStr != "kilohertz" && 
		parserData->tempStr != "hertz"     && parserData->tempStr != "petaflops" && 
		parserData->tempStr != "teraflops" && parserData->tempStr != "gigaflops" && 
		parserData->tempStr != "megaflops" && parserData->tempStr != "kiloflops" && 
		parserData->tempStr != "flops" )
		osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
;}
    break;

  case 152:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 153:

    { parserData->tempStr = "";          ;}
    break;

  case 154:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 155:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 157:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
	;}
    break;

  case 159:

    {	osresult->setAvailableCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 160:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 161:

    { parserData->tempStr = "";          ;}
    break;

  case 162:

    {osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 164:

    {	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	;}
    break;

  case 165:

    {	osresult->setNumberOfOtherSystemResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 166:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 167:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 173:

    {	parserData->kounter++;
;}
    break;

  case 174:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 175:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 178:

    {	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setSystemOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 179:

    {	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setSystemOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 180:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setSystemOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 181:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 182:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 183:

    { parserData->tempStr = "";          ;}
    break;

  case 184:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 185:

    { parserData->tempStr = "";          ;}
    break;

  case 200:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 201:

    {osresult->setCurrentState((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 205:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 206:

    {osresult->setCurrentJobCount((yyvsp[(2) - (3)].ival)); /* free($2); */  parserData->errorText = NULL;;}
    break;

  case 210:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 211:

    {osresult->setTotalJobsSoFar((yyvsp[(2) - (3)].ival)); /* free($2); */  parserData->errorText = NULL;;}
    break;

  case 215:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 216:

    {osresult->setTimeServiceStarted((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 220:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 221:

    {osresult->setServiceUtilization( parserData->tempVal);  parserData->errorText = NULL;;}
    break;

  case 225:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	;}
    break;

  case 226:

    {	osresult->setNumberOfOtherServiceResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 227:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 228:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 234:

    {	parserData->kounter++;
;}
    break;

  case 235:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 236:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 239:

    {	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setServiceOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 240:

    {	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setServiceOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 241:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setServiceOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 242:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 243:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 244:

    { parserData->tempStr = "";          ;}
    break;

  case 245:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 246:

    { parserData->tempStr = "";          ;}
    break;

  case 266:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 267:

    {osresult->setJobStatus((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 271:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 272:

    {osresult->setJobSubmitTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 276:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 277:

    {osresult->setScheduledStartTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 281:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 282:

    {osresult->setActualStartTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 286:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 287:

    {osresult->setJobEndTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 291:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 292:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
;}
    break;

  case 300:

    {	if (parserData->timeUnit != "tick"        &&
			parserData->timeUnit != "millisecond" &&
			parserData->timeUnit != "second"      &&
			parserData->timeUnit != "minute"      &&
			parserData->timeUnit != "hour"        &&
			parserData->timeUnit != "day"         &&
			parserData->timeUnit != "week"        &&
			parserData->timeUnit != "month"       &&
			parserData->timeUnit != "year"   )     
			osrlerror(NULL, NULL, parserData, "time unit not recognized");
	;}
    break;

  case 304:

    {parserData->timeType = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 306:

    {parserData->timeCategory = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 308:

    {parserData->timeUnit = (yyvsp[(2) - (3)].sval);   free((yyvsp[(2) - (3)].sval));;}
    break;

  case 310:

    {parserData->timeDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 316:

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

  case 318:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 319:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 321:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
	;}
    break;

  case 322:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 325:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedDiskSpace>");
		parserData->unitAttributePresent = true;		
		osresult->setUsedDiskSpaceUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 326:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedDiskSpace>");
		parserData->descriptionAttributePresent = true;		
		osresult->setUsedDiskSpaceDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 327:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "petabyte" && parserData->tempStr != "terabyte" &&
	    parserData->tempStr != "gigabyte" && parserData->tempStr != "megabyte" && 
	    parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedDiskSpace unit not recognized");
;}
    break;

  case 328:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 329:

    { parserData->tempStr = "";          ;}
    break;

  case 330:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 331:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 333:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
	;}
    break;

  case 334:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 337:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedMemory>");
		parserData->unitAttributePresent = true;		
		osresult->setUsedMemoryUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 338:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedMemory>");
		parserData->descriptionAttributePresent = true;		
		osresult->setUsedMemoryDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 339:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedMemory unit not recognized");
;}
    break;

  case 340:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 341:

    { parserData->tempStr = "";          ;}
    break;

  case 342:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 343:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 345:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
	;}
    break;

  case 346:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 349:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedCPUSpeed>");
		parserData->unitAttributePresent = true;		
		osresult->setUsedCPUSpeedUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 350:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedCPUSpeed>");
		parserData->descriptionAttributePresent = true;		
		osresult->setUsedCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 351:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "terahertz" && parserData->tempStr != "gigahertz" && 
		parserData->tempStr != "megahertz" && parserData->tempStr != "kilohertz" && 
		parserData->tempStr != "hertz"     && parserData->tempStr != "petaflops" && 
		parserData->tempStr != "teraflops" && parserData->tempStr != "gigaflops" && 
		parserData->tempStr != "megaflops" && parserData->tempStr != "kiloflops" && 
		parserData->tempStr != "flops" )
		osrlerror(NULL, NULL, parserData, "usedCPUSpeed unit not recognized");
;}
    break;

  case 352:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 353:

    { parserData->tempStr = "";          ;}
    break;

  case 354:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 355:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 357:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
	;}
    break;

  case 359:

    {	osresult->setUsedCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 360:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 361:

    { parserData->tempStr = "";          ;}
    break;

  case 362:

    {osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 364:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	;}
    break;

  case 365:

    {	osresult->setNumberOfOtherJobResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 366:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 367:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 373:

    {	parserData->kounter++;
;}
    break;

  case 374:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 375:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 378:

    {	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setJobOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 379:

    {	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setJobOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 380:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setJobOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 381:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 382:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 383:

    { parserData->tempStr = "";           ;}
    break;

  case 384:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 385:

    { parserData->tempStr = "";           ;}
    break;

  case 390:

    {	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
;}
    break;

  case 391:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, "numberOfSolutions was never set");
	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
	parserData->solutionIdx = 0;
;}
    break;

  case 398:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfSolutions = (yyvsp[(3) - (3)].ival); 
	osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 399:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	parserData->nVarPresent = true;	
	parserData->numberOfVariables = (yyvsp[(3) - (3)].ival); 
	osresult->setVariableNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 400:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	parserData->nConPresent = true;		
	parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); 
	osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 401:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	parserData->nObjPresent = true;
	parserData->numberOfObjectives = (yyvsp[(3) - (3)].ival); 
	osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 409:

    {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   ;}
    break;

  case 410:

    {   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
;}
    break;

  case 411:

    {	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 416:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 417:

    {	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval);
  	osresult->setSolutionWeightedObjectives(parserData->solutionIdx, parserData->tempStr);
;}
    break;

  case 420:

    {	parserData->numberOf = 0; 
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
	;}
    break;

  case 421:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->kounter = 0;
	;}
    break;

  case 424:

    {   if ((parserData->typeAttribute != "unbounded"      ) && 
			(parserData->typeAttribute != "globallyOptimal") && 
	        (parserData->typeAttribute != "locallyOptimal" ) &&
	        (parserData->typeAttribute != "optimal"        ) && 
	        (parserData->typeAttribute != "bestSoFar"      ) &&
	        (parserData->typeAttribute != "feasible"       ) && 
	        (parserData->typeAttribute != "infeasible"     ) &&
	        (parserData->typeAttribute != "unsure"         ) && 
	        (parserData->typeAttribute != "error"          ) &&
	        (parserData->typeAttribute != "other"          ))
			osrlerror(NULL, NULL, parserData, "solution status type does not matched any legal value");
		osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute); 
	;}
    break;

  case 425:

    {   if (parserData->descriptionAttributePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for solution status element");
	    parserData->descriptionAttributePresent = true;
		osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->tempStr);
	;}
    break;

  case 427:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 428:

    { parserData->tempStr = "";          ;}
    break;

  case 429:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for solution status element");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solution substatuses cannot be negative");
    osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 430:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 431:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 437:

    {	parserData->kounter++; ;}
    break;

  case 438:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
;}
    break;

  case 439:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 443:

    {	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
	parserData->descriptionAttributePresent = true;
	osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,parserData->tempStr);
;}
    break;

  case 444:

    {	if (parserData->typeAttributePresent)
		osrlerror(NULL, NULL, parserData, "type attribute multiply specified");
	parserData->typeAttributePresent = true;
	osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter,(yyvsp[(2) - (3)].sval));	
;}
    break;

  case 445:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 446:

    { parserData->tempStr = ""; ;}
    break;

  case 450:

    {	osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
	;}
    break;

  case 457:

    {	parserData->numberOfOtherVariableResults = (yyvsp[(3) - (4)].ival);
		osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 463:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 464:

    {	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
	osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 465:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 466:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 472:

    {	osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 473:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 474:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 475:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 476:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 479:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 480:

    {	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar);
;}
    break;

  case 481:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 482:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 488:

    {	osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 			parserData->idx,         (yyvsp[(4) - (5)].sval));
	parserData->kounter++;
;}
    break;

  case 489:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 490:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 493:

    {	parserData->nVarPresent = false; ;}
    break;

  case 494:

    {	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	osresult->setNumberOfBasisVar(parserData->solutionIdx, parserData->numberOfVar);
;}
    break;

  case 495:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 496:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 502:

    {	osresult->setBasisVar(parserData->solutionIdx, parserData->kounter, 
					 			parserData->idx,         (yyvsp[(4) - (5)].sval));
	parserData->kounter++;
;}
    break;

  case 503:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 504:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 507:

    { 	 
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
	;}
    break;

  case 509:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfVar attribute"); 
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->kounter = 0;
	;}
    break;

  case 513:

    {	
	if (parserData->valueAttributePresent)
		osrlerror(NULL, NULL, parserData, "value attribute previously set");
	parserData->valueAttributePresent = true; 
 	osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 514:

    {	
	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, "name attribute previously set");
	parserData->nameAttributePresent = true; 
 	osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 515:

    {	
	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute previously set");
	parserData->descriptionAttributePresent = true; 
 	osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 516:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfVar attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 517:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 518:

    {parserData->tempStr = "";          ;}
    break;

  case 519:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 520:

    {parserData->tempStr = "";          ;}
    break;

  case 521:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 522:

    {parserData->tempStr = "";          ;}
    break;

  case 527:

    { 	
	parserData->kounter++;
;}
    break;

  case 529:

    {	
 	osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 530:

    {	
	 	osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 536:

    {	parserData->numberOfOtherObjectiveResults = (yyvsp[(3) - (4)].ival);
        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 542:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 543:

    {	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj);
	parserData->kounter = 0;
;}
    break;

  case 544:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <obj> element");
	;}
    break;

  case 545:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, "fewer <obj> elements than specified");
	;}
    break;

  case 551:

    {	osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 552:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, "more <obj> elements than specified");
;}
    break;

  case 553:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 554:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 555:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 558:

    { 	 
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
	;}
    break;

  case 560:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfObj attribute"); 
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->kounter = 0;
	;}
    break;

  case 564:

    {	
	if (parserData->valueAttributePresent)
		osrlerror(NULL, NULL, parserData, "value attribute previously set");
	parserData->valueAttributePresent = true; 
 	osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 565:

    {	
	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, "name attribute previously set");
	parserData->nameAttributePresent = true; 
 	osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 566:

    {	
	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute previously set");
	parserData->descriptionAttributePresent = true; 
 	osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 567:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfObj attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 568:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 569:

    {parserData->tempStr = "";          ;}
    break;

  case 570:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 571:

    {parserData->tempStr = "";          ;}
    break;

  case 572:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 573:

    {parserData->tempStr = "";          ;}
    break;

  case 578:

    {  
	parserData->kounter++;
;}
    break;

  case 580:

    {	osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 581:

    {	osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 587:

    {	parserData->numberOfOtherConstraintResults = (yyvsp[(3) - (4)].ival);
		osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 593:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 594:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon);
	parserData->kounter = 0;
;}
    break;

  case 595:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <con> element");
	;}
    break;

  case 596:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, "fewer <con> elements than specified");
	;}
    break;

  case 602:

    {	osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
						   parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 603:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, "more <con> elements than specified");
;}
    break;

  case 604:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 605:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 606:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 609:

    { 	 
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
	;}
    break;

  case 611:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfCon attribute"); 
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->kounter = 0;
	;}
    break;

  case 615:

    {	
	if (parserData->valueAttributePresent)
		osrlerror(NULL, NULL, parserData, "value attribute previously set");
	parserData->valueAttributePresent = true; 
 	osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 616:

    {	
	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, "name attribute previously set");
	parserData->nameAttributePresent = true; 
 	osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 617:

    {	
	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute previously set");
	parserData->descriptionAttributePresent = true; 
 	osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 618:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfCon attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 619:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 620:

    {parserData->tempStr = "";          ;}
    break;

  case 621:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 622:

    {parserData->tempStr = "";          ;}
    break;

  case 623:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 624:

    {parserData->tempStr = "";          ;}
    break;

  case 629:

    { 	
	parserData->kounter++;
;}
    break;

  case 631:

    {	
 	osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 632:

    {	
	 	osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 636:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 637:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 638:

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

  case 642:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 643:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 645:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 651:

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

  case 652:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->nameAttributePresent = true;
//	parserData->otherVarStruct->name = "";
;}
    break;

  case 653:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); //parserData->nameAttributePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 654:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 656:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 659:

    {parserData->kounter++;;}
    break;

  case 660:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 661:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 664:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 666:

    {

	//
    //delete the old vectors
//	osrl_empty_vectors( parserData);
    
;}
    break;

  case 674:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
;}
    break;

  case 677:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/;}
    break;

  case 683:

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

  case 684:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->nameAttributePresent = true; 
	parserData->otherVarStruct->name = "";
*/
;}
    break;

  case 685:

    {
/*	parserData->tmpOtherName=$2; parserData->nameAttributePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
;}
    break;

  case 686:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
;}
    break;

  case 688:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
;}
    break;

  case 692:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/;}
    break;

  case 693:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/;}
    break;

  case 696:

    {/*parserData->itemContent = $2; free($2);*/;}
    break;

  case 699:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one description attribute allowed for generalStatus element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 700:

    { parserData->descriptionAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 701:

    { parserData->descriptionAttribute = "";          ;}
    break;

  case 703:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one name attribute allowed for generalStatus element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 704:

    { parserData->nameAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 705:

    { parserData->nameAttribute = "";          ;}
    break;

  case 707:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one type attribute allowed for generalStatus element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 708:

    { parserData->typeAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 709:

    { parserData->typeAttribute = "";          ;}
    break;

  case 710:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 711:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 713:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 714:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 715:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].dval)); ;}
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


