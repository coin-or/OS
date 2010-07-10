
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         osrlparse
#define yylex           osrllex
#define yyerror         osrlerror
#define yylval          osrllval
#define yychar          osrlchar
#define yydebug         osrldebug
#define yynerrs         osrlnerrs
#define yylloc          osrllloc

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

//#define DEBUG

#ifdef DEBUG
#define YYDEBUG 1
#endif

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


	double dval;
	int ival;
	char* sval;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
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



void osrlerror(YYLTYPE* type, OSResult *osresult,  OSrLParserData *parserData ,const char* errormsg );
int osrllex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
 
#define scanner parserData->scanner



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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   982

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  547
/* YYNRULES -- Number of rules.  */
#define YYNRULES  813
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1130

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
       0,     0,     3,     7,     9,    10,    12,    16,    22,    23,
      26,    28,    30,    32,    35,    37,    41,    43,    45,    48,
      50,    52,    54,    56,    58,    60,    62,    64,    66,    70,
      72,    74,    76,    79,    81,    83,    85,    87,    89,    92,
      94,    98,   100,   102,   105,   109,   111,   113,   114,   117,
     119,   121,   124,   126,   129,   131,   133,   135,   138,   140,
     144,   146,   149,   151,   153,   155,   158,   160,   164,   166,
     169,   171,   173,   175,   178,   180,   184,   186,   189,   191,
     193,   195,   198,   200,   204,   206,   209,   211,   213,   215,
     218,   220,   224,   226,   229,   231,   233,   235,   238,   240,
     244,   246,   249,   251,   253,   255,   258,   260,   264,   266,
     270,   272,   274,   276,   278,   281,   283,   287,   289,   291,
     294,   298,   300,   302,   303,   306,   308,   310,   312,   315,
     317,   318,   321,   323,   325,   327,   330,   332,   336,   338,
     340,   343,   345,   347,   349,   351,   353,   355,   358,   360,
     362,   364,   367,   369,   373,   375,   379,   381,   383,   384,
     387,   389,   391,   395,   397,   401,   403,   405,   406,   409,
     411,   413,   417,   419,   423,   425,   427,   428,   431,   433,
     435,   439,   441,   445,   447,   448,   450,   454,   456,   460,
     462,   464,   466,   468,   471,   473,   477,   479,   481,   484,
     488,   490,   492,   493,   496,   498,   500,   502,   505,   507,
     508,   511,   516,   517,   520,   522,   524,   526,   528,   530,
     532,   535,   537,   539,   541,   544,   546,   550,   552,   555,
     557,   559,   561,   564,   566,   570,   572,   575,   577,   579,
     581,   584,   586,   590,   592,   595,   597,   599,   601,   604,
     606,   610,   612,   615,   617,   619,   621,   624,   626,   630,
     632,   636,   638,   640,   642,   644,   647,   649,   653,   655,
     657,   660,   664,   666,   668,   669,   672,   674,   676,   678,
     681,   683,   684,   687,   692,   693,   696,   698,   700,   702,
     704,   706,   708,   710,   712,   714,   716,   718,   721,   723,
     725,   727,   730,   732,   736,   738,   741,   743,   745,   747,
     750,   752,   756,   758,   761,   763,   765,   767,   770,   772,
     776,   778,   781,   783,   785,   787,   790,   792,   796,   798,
     801,   803,   805,   807,   810,   812,   816,   818,   822,   824,
     826,   828,   830,   833,   835,   839,   841,   843,   846,   850,
     852,   853,   856,   858,   860,   862,   864,   866,   868,   871,
     873,   877,   879,   881,   883,   887,   889,   891,   892,   895,
     897,   899,   903,   905,   909,   911,   913,   914,   917,   919,
     921,   925,   927,   931,   933,   935,   936,   939,   941,   943,
     947,   949,   953,   955,   956,   958,   962,   964,   968,   970,
     972,   974,   976,   979,   981,   985,   987,   989,   992,   996,
     998,  1000,  1001,  1004,  1006,  1008,  1010,  1013,  1015,  1016,
    1020,  1022,  1024,  1025,  1028,  1030,  1032,  1034,  1036,  1038,
    1040,  1043,  1045,  1049,  1052,  1054,  1057,  1061,  1063,  1065,
    1066,  1069,  1071,  1073,  1078,  1082,  1091,  1095,  1097,  1099,
    1101,  1104,  1106,  1108,  1110,  1112,  1114,  1117,  1119,  1123,
    1125,  1127,  1130,  1134,  1136,  1138,  1139,  1142,  1144,  1146,
    1149,  1151,  1152,  1155,  1157,  1159,  1161,  1164,  1166,  1170,
    1172,  1173,  1177,  1179,  1180,  1182,  1184,  1186,  1188,  1192,
    1197,  1198,  1202,  1204,  1206,  1208,  1210,  1213,  1215,  1219,
    1221,  1223,  1226,  1230,  1232,  1237,  1241,  1243,  1245,  1246,
    1250,  1252,  1254,  1256,  1258,  1261,  1263,  1267,  1269,  1271,
    1274,  1278,  1280,  1285,  1287,  1289,  1292,  1294,  1298,  1300,
    1301,  1305,  1307,  1309,  1311,  1313,  1316,  1318,  1322,  1324,
    1326,  1329,  1333,  1335,  1340,  1344,  1345,  1348,  1352,  1354,
    1356,  1357,  1360,  1362,  1364,  1366,  1368,  1370,  1372,  1375,
    1377,  1381,  1383,  1385,  1388,  1392,  1394,  1399,  1401,  1403,
    1406,  1408,  1412,  1414,  1415,  1419,  1421,  1422,  1424,  1426,
    1428,  1430,  1434,  1437,  1438,  1442,  1444,  1446,  1448,  1450,
    1453,  1455,  1459,  1461,  1463,  1466,  1470,  1472,  1473,  1478,
    1482,  1484,  1486,  1487,  1490,  1494,  1496,  1498,  1499,  1502,
    1504,  1506,  1508,  1510,  1512,  1514,  1517,  1519,  1523,  1525,
    1527,  1530,  1534,  1536,  1541,  1543,  1545,  1548,  1550,  1554,
    1556,  1557,  1561,  1563,  1564,  1566,  1568,  1570,  1572,  1576,
    1579,  1580,  1584,  1586,  1588,  1590,  1592,  1595,  1597,  1601,
    1603,  1605,  1608,  1614,  1616,  1621,  1623,  1625,  1626,  1629,
    1633,  1635,  1637,  1638,  1641,  1643,  1645,  1647,  1649,  1651,
    1653,  1656,  1658,  1662,  1664,  1666,  1669,  1673,  1675,  1680,
    1682,  1684,  1687,  1689,  1693,  1695,  1696,  1700,  1702,  1704,
    1706,  1708,  1711,  1713,  1717,  1719,  1721,  1724,  1728,  1730,
    1732,  1733,  1736,  1738,  1740,  1742,  1744,  1746,  1748,  1751,
    1753,  1757,  1759,  1761,  1764,  1766,  1768,  1770,  1772,  1774,
    1778,  1780,  1781,  1785,  1787,  1789,  1791,  1793,  1796,  1798,
    1802,  1804,  1806,  1809,  1813,  1815,  1817,  1818,  1821,  1823,
    1825,  1827,  1829,  1831,  1833,  1836,  1838,  1842,  1844,  1846,
    1849,  1851,  1853,  1855,  1857,  1859,  1863,  1865,  1867,  1869,
    1871,  1875,  1877,  1879,  1881,  1883,  1887,  1889,  1891,  1893,
    1895,  1899,  1901,  1903,  1905,  1907,  1911,  1913,  1915,  1917,
    1919,  1923,  1925,  1927,  1929,  1931,  1935,  1940,  1945,  1950,
    1955,  1960,  1965,  1970,  1975,  1980,  1985,  1990,  1995,  2000,
    2005,  2010,  2015,  2017,  2019,  2021,  2023,  2025,  2028,  2029,
    2032,  2034,  2036,  2038
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   173,    -1,    44,    -1,    -1,
      46,    -1,    10,   174,    47,    -1,   175,   255,   309,   356,
     446,    -1,    -1,   176,   177,    -1,    48,    -1,   178,    -1,
     179,    -1,    10,    49,    -1,    11,    -1,    10,   180,    49,
      -1,   181,    -1,   182,    -1,   181,   182,    -1,   183,    -1,
     199,    -1,   205,    -1,   211,    -1,   217,    -1,   223,    -1,
     229,    -1,   235,    -1,   241,    -1,   184,   185,   188,    -1,
      88,    -1,   186,    -1,   187,    -1,   186,   187,    -1,   683,
      -1,   675,    -1,   710,    -1,   189,    -1,   190,    -1,    10,
      89,    -1,    11,    -1,    10,   191,    89,    -1,   192,    -1,
     193,    -1,   192,   193,    -1,   194,   195,   198,    -1,   134,
      -1,   196,    -1,    -1,   196,   197,    -1,   679,    -1,   675,
      -1,    10,   135,    -1,    11,    -1,   200,   201,    -1,    96,
      -1,   202,    -1,   203,    -1,    10,    97,    -1,    11,    -1,
      10,   204,    97,    -1,     4,    -1,   206,   207,    -1,   120,
      -1,   208,    -1,   209,    -1,    10,   121,    -1,    11,    -1,
      10,   210,   121,    -1,     4,    -1,   212,   213,    -1,   118,
      -1,   214,    -1,   215,    -1,    10,   119,    -1,    11,    -1,
      10,   216,   119,    -1,     4,    -1,   218,   219,    -1,    92,
      -1,   220,    -1,   221,    -1,    10,    93,    -1,    11,    -1,
      10,   222,    93,    -1,     4,    -1,   224,   225,    -1,    94,
      -1,   226,    -1,   227,    -1,    10,    95,    -1,    11,    -1,
      10,   228,    95,    -1,     4,    -1,   230,   231,    -1,   126,
      -1,   232,    -1,   233,    -1,    10,   127,    -1,    11,    -1,
      10,   234,   127,    -1,     4,    -1,   236,   237,    -1,   142,
      -1,   238,    -1,   239,    -1,    10,   143,    -1,    11,    -1,
      10,   240,   143,    -1,     4,    -1,   242,   243,   244,    -1,
     108,    -1,   695,    -1,   245,    -1,   246,    -1,    10,   109,
      -1,    11,    -1,    10,   247,   109,    -1,   248,    -1,   249,
      -1,   248,   249,    -1,   250,   251,   254,    -1,   106,    -1,
     252,    -1,    -1,   252,   253,    -1,   679,    -1,   691,    -1,
     675,    -1,    10,   107,    -1,    11,    -1,    -1,   256,   257,
      -1,    50,    -1,   258,    -1,   259,    -1,    10,    51,    -1,
      11,    -1,    10,   260,    51,    -1,   261,    -1,   262,    -1,
     261,   262,    -1,   263,    -1,   269,    -1,   276,    -1,   283,
      -1,   290,    -1,   295,    -1,   264,   265,    -1,   136,    -1,
     266,    -1,   267,    -1,    10,   137,    -1,    11,    -1,    10,
     268,   137,    -1,     4,    -1,   270,   271,   274,    -1,    68,
      -1,   272,    -1,    -1,   272,   273,    -1,   687,    -1,   675,
      -1,    10,   275,    69,    -1,   711,    -1,   277,   278,   281,
      -1,    70,    -1,   279,    -1,    -1,   279,   280,    -1,   687,
      -1,   675,    -1,    10,   282,    71,    -1,   711,    -1,   284,
     285,   288,    -1,    66,    -1,   286,    -1,    -1,   286,   287,
      -1,   687,    -1,   675,    -1,    10,   289,    67,    -1,   711,
      -1,   291,   292,   293,    -1,    64,    -1,    -1,   675,    -1,
      10,   294,    65,    -1,     6,    -1,   296,   297,   298,    -1,
     108,    -1,   695,    -1,   299,    -1,   300,    -1,    10,   109,
      -1,    11,    -1,    10,   301,   109,    -1,   302,    -1,   303,
      -1,   302,   303,    -1,   304,   305,   308,    -1,   106,    -1,
     306,    -1,    -1,   306,   307,    -1,   679,    -1,   691,    -1,
     675,    -1,    10,   107,    -1,    11,    -1,    -1,    52,    11,
      -1,    52,    10,   310,    53,    -1,    -1,   310,   311,    -1,
     312,    -1,   318,    -1,   324,    -1,   330,    -1,   336,    -1,
     342,    -1,   313,   314,    -1,    82,    -1,   315,    -1,   316,
      -1,    10,    83,    -1,    11,    -1,    10,   317,    83,    -1,
       4,    -1,   319,   320,    -1,    80,    -1,   321,    -1,   322,
      -1,    10,    81,    -1,    11,    -1,    10,   323,    81,    -1,
       6,    -1,   325,   326,    -1,   146,    -1,   327,    -1,   328,
      -1,    10,   147,    -1,    11,    -1,    10,   329,   147,    -1,
       6,    -1,   331,   332,    -1,   140,    -1,   333,    -1,   334,
      -1,    10,   141,    -1,    11,    -1,    10,   335,   141,    -1,
       4,    -1,   337,   338,    -1,   122,    -1,   339,    -1,   340,
      -1,    10,   123,    -1,    11,    -1,    10,   341,   123,    -1,
     711,    -1,   343,   344,   345,    -1,   108,    -1,   695,    -1,
     346,    -1,   347,    -1,    10,   109,    -1,    11,    -1,    10,
     348,   109,    -1,   349,    -1,   350,    -1,   349,   350,    -1,
     351,   352,   355,    -1,   106,    -1,   353,    -1,    -1,   353,
     354,    -1,   679,    -1,   691,    -1,   675,    -1,    10,   107,
      -1,    11,    -1,    -1,    54,    11,    -1,    54,    10,   357,
      55,    -1,    -1,   357,   358,    -1,   359,    -1,   365,    -1,
     371,    -1,   377,    -1,   383,    -1,   389,    -1,   406,    -1,
     413,    -1,   420,    -1,   427,    -1,   432,    -1,   360,   361,
      -1,   130,    -1,   362,    -1,   363,    -1,    10,   131,    -1,
      11,    -1,    10,   364,   131,    -1,     4,    -1,   366,   367,
      -1,   132,    -1,   368,    -1,   369,    -1,    10,   133,    -1,
      11,    -1,    10,   370,   133,    -1,     4,    -1,   372,   373,
      -1,   116,    -1,   374,    -1,   375,    -1,    10,   117,    -1,
      11,    -1,    10,   376,   117,    -1,     4,    -1,   378,   379,
      -1,    62,    -1,   380,    -1,   381,    -1,    10,    63,    -1,
      11,    -1,    10,   382,    63,    -1,     4,    -1,   384,   385,
      -1,    86,    -1,   386,    -1,   387,    -1,    10,    87,    -1,
      11,    -1,    10,   388,    87,    -1,     4,    -1,   390,   391,
     392,    -1,   144,    -1,   707,    -1,   393,    -1,   394,    -1,
      10,   145,    -1,    11,    -1,    10,   395,   145,    -1,   396,
      -1,   397,    -1,   396,   397,    -1,   398,   399,   401,    -1,
     138,    -1,    -1,   399,   400,    -1,   687,    -1,   683,    -1,
     671,    -1,   675,    -1,   402,    -1,   403,    -1,    10,   139,
      -1,    11,    -1,    10,   404,   139,    -1,   405,    -1,     7,
      -1,     6,    -1,   407,   408,   411,    -1,   152,    -1,   409,
      -1,    -1,   409,   410,    -1,   687,    -1,   675,    -1,    10,
     412,   153,    -1,   711,    -1,   414,   415,   418,    -1,   154,
      -1,   416,    -1,    -1,   416,   417,    -1,   687,    -1,   675,
      -1,    10,   419,   155,    -1,   711,    -1,   421,   422,   425,
      -1,   150,    -1,   423,    -1,    -1,   423,   424,    -1,   687,
      -1,   675,    -1,    10,   426,   151,    -1,   711,    -1,   428,
     429,   430,    -1,   148,    -1,    -1,   675,    -1,    10,   431,
     149,    -1,     6,    -1,   433,   434,   435,    -1,   108,    -1,
     695,    -1,   436,    -1,   437,    -1,    10,   109,    -1,    11,
      -1,    10,   438,   109,    -1,   439,    -1,   440,    -1,   439,
     440,    -1,   441,   442,   445,    -1,   106,    -1,   443,    -1,
      -1,   443,   444,    -1,   679,    -1,   691,    -1,   675,    -1,
      10,   107,    -1,    11,    -1,    -1,   447,   448,   451,    -1,
      56,    -1,   449,    -1,    -1,   449,   450,    -1,   696,    -1,
     697,    -1,   698,    -1,   699,    -1,   452,    -1,   453,    -1,
      10,    57,    -1,    11,    -1,    10,   454,    57,    -1,   455,
     649,    -1,   456,    -1,   455,   456,    -1,   457,   458,   463,
      -1,   124,    -1,   459,    -1,    -1,   459,   460,    -1,   461,
      -1,   462,    -1,    28,   713,     6,   713,    -1,    42,     3,
     713,    -1,    10,   464,   480,   486,   551,   589,   626,   125,
      -1,   465,   466,   469,    -1,   130,    -1,   467,    -1,   468,
      -1,   467,   468,    -1,   683,    -1,   675,    -1,   710,    -1,
     470,    -1,   471,    -1,    10,   131,    -1,    11,    -1,    10,
     472,   131,    -1,   473,    -1,   474,    -1,   473,   474,    -1,
     475,   476,   479,    -1,   134,    -1,   477,    -1,    -1,   477,
     478,    -1,   683,    -1,   675,    -1,    10,   135,    -1,    11,
      -1,    -1,   481,   482,    -1,    96,    -1,   483,    -1,   484,
      -1,    10,    97,    -1,    11,    -1,    10,   485,    97,    -1,
       4,    -1,    -1,   487,   488,   489,    -1,   162,    -1,    -1,
     700,    -1,   490,    -1,   491,    -1,    11,    -1,    10,   492,
     163,    -1,   493,   506,   521,   533,    -1,    -1,   494,   495,
     496,    -1,   156,    -1,   704,    -1,   497,    -1,   498,    -1,
      10,   157,    -1,    11,    -1,    10,   499,   157,    -1,   500,
      -1,   501,    -1,   500,   501,    -1,   502,   503,   504,    -1,
     160,    -1,    29,   713,     6,   713,    -1,    10,   505,   161,
      -1,     6,    -1,     7,    -1,    -1,   507,   508,   509,    -1,
     158,    -1,   704,    -1,   510,    -1,   511,    -1,    10,   159,
      -1,    11,    -1,    10,   512,   159,    -1,   513,    -1,   514,
      -1,   513,   514,    -1,   515,   516,   517,    -1,   160,    -1,
      29,   713,     6,   713,    -1,   518,    -1,   519,    -1,    10,
     161,    -1,    11,    -1,    10,   520,   161,    -1,     4,    -1,
      -1,   522,   523,   524,    -1,    72,    -1,   704,    -1,   525,
      -1,   526,    -1,    10,    73,    -1,    11,    -1,    10,   527,
      73,    -1,   528,    -1,   529,    -1,   528,   529,    -1,   530,
     531,   532,    -1,   160,    -1,    29,   713,     6,   713,    -1,
      10,     4,   161,    -1,    -1,   533,   534,    -1,   535,   536,
     539,    -1,   106,    -1,   537,    -1,    -1,   537,   538,    -1,
     704,    -1,   691,    -1,   679,    -1,   675,    -1,   540,    -1,
     541,    -1,    10,   107,    -1,    11,    -1,    10,   542,   107,
      -1,   543,    -1,   544,    -1,   543,   544,    -1,   545,   546,
     547,    -1,   160,    -1,    29,   713,     6,   713,    -1,   548,
      -1,   549,    -1,    10,   161,    -1,    11,    -1,    10,   550,
     161,    -1,   712,    -1,    -1,   552,   553,   554,    -1,   100,
      -1,    -1,   701,    -1,   555,    -1,   556,    -1,    11,    -1,
      10,   557,   101,    -1,   558,   571,    -1,    -1,   559,   560,
     561,    -1,   156,    -1,   705,    -1,   562,    -1,   563,    -1,
      10,   157,    -1,    11,    -1,    10,   564,   157,    -1,   565,
      -1,   566,    -1,   565,   566,    -1,   567,   568,   569,    -1,
      98,    -1,    -1,    29,   713,     6,   713,    -1,    10,   570,
      99,    -1,     6,    -1,     7,    -1,    -1,   571,   572,    -1,
     573,   574,   577,    -1,   106,    -1,   575,    -1,    -1,   575,
     576,    -1,   705,    -1,   691,    -1,   679,    -1,   675,    -1,
     578,    -1,   579,    -1,    10,   107,    -1,    11,    -1,    10,
     580,   107,    -1,   581,    -1,   582,    -1,   581,   582,    -1,
     583,   584,   585,    -1,    98,    -1,    29,   713,     6,   713,
      -1,   586,    -1,   587,    -1,    10,    99,    -1,    11,    -1,
      10,   588,    99,    -1,   712,    -1,    -1,   590,   591,   592,
      -1,    78,    -1,    -1,   702,    -1,   593,    -1,   594,    -1,
      11,    -1,    10,   595,    79,    -1,   596,   608,    -1,    -1,
     597,   598,   599,    -1,    84,    -1,   706,    -1,   600,    -1,
     601,    -1,    10,    85,    -1,    11,    -1,    10,   602,    85,
      -1,   603,    -1,   604,    -1,   603,   604,    -1,   605,   606,
      10,   607,    77,    -1,    76,    -1,    29,   713,     6,   713,
      -1,     6,    -1,     7,    -1,    -1,   608,   609,    -1,   610,
     611,   614,    -1,   106,    -1,   612,    -1,    -1,   612,   613,
      -1,   706,    -1,   691,    -1,   679,    -1,   675,    -1,   615,
      -1,   616,    -1,    10,   107,    -1,    11,    -1,    10,   617,
     107,    -1,   618,    -1,   619,    -1,   618,   619,    -1,   620,
     621,   622,    -1,    76,    -1,    29,   713,     6,   713,    -1,
     623,    -1,   624,    -1,    10,    77,    -1,    11,    -1,    10,
     625,    77,    -1,   712,    -1,    -1,   627,   628,   629,    -1,
     112,    -1,   703,    -1,   630,    -1,   631,    -1,    10,   113,
      -1,    11,    -1,    10,   632,   113,    -1,   633,    -1,   634,
      -1,   633,   634,    -1,   635,   636,   639,    -1,   110,    -1,
     637,    -1,    -1,   637,   638,    -1,   679,    -1,   671,    -1,
     675,    -1,   708,    -1,   640,    -1,   641,    -1,    10,   111,
      -1,    11,    -1,    10,   642,   111,    -1,   643,    -1,   644,
      -1,   643,   644,    -1,   645,    -1,   646,    -1,   647,    -1,
      60,    -1,    61,    -1,    58,   648,    59,    -1,     5,    -1,
      -1,   650,   651,   652,    -1,   114,    -1,   709,    -1,   653,
      -1,   654,    -1,    10,   115,    -1,    11,    -1,    10,   655,
     115,    -1,   656,    -1,   657,    -1,   656,   657,    -1,   658,
     659,   662,    -1,   128,    -1,   660,    -1,    -1,   660,   661,
      -1,   679,    -1,   671,    -1,   675,    -1,   708,    -1,   663,
      -1,   664,    -1,    10,   129,    -1,    11,    -1,    10,   665,
     129,    -1,   666,    -1,   667,    -1,   666,   667,    -1,   668,
      -1,   669,    -1,   670,    -1,    60,    -1,    61,    -1,    58,
       5,    59,    -1,   672,    -1,   673,    -1,   674,    -1,    31,
      -1,    30,     3,   713,    -1,   676,    -1,   677,    -1,   678,
      -1,    33,    -1,    32,     3,   713,    -1,   680,    -1,   681,
      -1,   682,    -1,    35,    -1,    34,     3,   713,    -1,   684,
      -1,   685,    -1,   686,    -1,    37,    -1,    36,     3,   713,
      -1,   688,    -1,   689,    -1,   690,    -1,    39,    -1,    38,
       3,   713,    -1,   692,    -1,   693,    -1,   694,    -1,    41,
      -1,    40,     3,   713,    -1,    19,   713,     6,   713,    -1,
      22,   713,     6,   713,    -1,    27,   713,     6,   713,    -1,
      13,   713,     6,   713,    -1,    16,   713,     6,   713,    -1,
      21,   713,     6,   713,    -1,    18,   713,     6,   713,    -1,
      17,   713,     6,   713,    -1,    20,   713,     6,   713,    -1,
      26,   713,     6,   713,    -1,    15,   713,     6,   713,    -1,
      12,   713,     6,   713,    -1,    25,   713,     6,   713,    -1,
      14,   713,     6,   713,    -1,    23,   713,     6,   713,    -1,
      24,   713,     6,   713,    -1,     6,    -1,     7,    -1,     4,
      -1,     6,    -1,     7,    -1,   714,     8,    -1,    -1,   714,
     715,    -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   167,   167,   169,   176,   176,   178,   180,   183,   183,
     185,   187,   187,   189,   189,   191,   193,   195,   195,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   209,   211,
     223,   229,   229,   232,   241,   245,   253,   257,   262,   262,
     264,   266,   268,   268,   270,   274,   281,   286,   286,   289,
     294,   300,   300,   303,   305,   311,   311,   313,   313,   315,
     317,   320,   322,   328,   328,   330,   330,   332,   334,   337,
     339,   345,   345,   347,   347,   349,   351,   354,   356,   362,
     362,   364,   364,   366,   368,   371,   373,   379,   379,   381,
     381,   383,   385,   388,   390,   396,   396,   398,   398,   400,
     402,   405,   407,   413,   413,   415,   415,   417,   419,   422,
     424,   430,   440,   444,   449,   449,   451,   453,   455,   455,
     457,   461,   469,   474,   474,   477,   483,   488,   495,   495,
     499,   499,   501,   503,   503,   505,   505,   507,   509,   511,
     511,   514,   515,   516,   517,   518,   519,   522,   524,   530,
     530,   532,   532,   534,   536,   542,   544,   552,   554,   554,
     557,   569,   574,   576,   581,   583,   591,   593,   593,   596,
     608,   613,   615,   621,   623,   631,   633,   633,   636,   652,
     657,   659,   665,   667,   674,   675,   680,   682,   686,   688,
     694,   704,   708,   713,   713,   715,   717,   719,   719,   721,
     725,   733,   738,   738,   741,   747,   752,   759,   759,   763,
     763,   764,   766,   766,   769,   770,   771,   772,   773,   774,
     777,   779,   785,   785,   787,   787,   789,   791,   804,   806,
     812,   812,   814,   814,   816,   818,   821,   823,   829,   829,
     831,   831,   833,   835,   838,   840,   846,   846,   848,   848,
     850,   852,   855,   857,   863,   863,   865,   865,   867,   869,
     874,   876,   882,   892,   896,   901,   901,   903,   905,   907,
     907,   909,   913,   921,   926,   926,   929,   935,   940,   947,
     947,   950,   950,   951,   953,   953,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   969,   971,   977,
     977,   979,   979,   981,   983,   996,   998,  1004,  1004,  1006,
    1006,  1008,  1010,  1013,  1015,  1021,  1021,  1023,  1023,  1025,
    1027,  1030,  1032,  1038,  1038,  1040,  1040,  1042,  1044,  1047,
    1049,  1055,  1055,  1057,  1057,  1059,  1061,  1064,  1066,  1072,
    1081,  1085,  1090,  1090,  1092,  1094,  1096,  1096,  1098,  1100,
    1113,  1113,  1116,  1128,  1134,  1144,  1147,  1147,  1149,  1149,
    1151,  1153,  1164,  1165,  1168,  1170,  1178,  1180,  1180,  1183,
    1195,  1200,  1202,  1208,  1210,  1218,  1220,  1220,  1223,  1235,
    1240,  1242,  1248,  1250,  1260,  1262,  1262,  1265,  1281,  1286,
    1288,  1294,  1296,  1304,  1305,  1310,  1312,  1317,  1319,  1325,
    1335,  1339,  1344,  1344,  1346,  1348,  1350,  1350,  1352,  1356,
    1364,  1369,  1369,  1372,  1378,  1383,  1390,  1390,  1393,  1393,
    1395,  1402,  1407,  1407,  1410,  1417,  1423,  1429,  1437,  1441,
    1446,  1446,  1448,  1450,  1452,  1452,  1454,  1456,  1464,  1466,
    1466,  1468,  1468,  1470,  1479,  1496,  1502,  1504,  1511,  1516,
    1516,  1519,  1534,  1538,  1547,  1551,  1557,  1557,  1559,  1561,
    1563,  1563,  1565,  1568,  1575,  1580,  1580,  1583,  1593,  1600,
    1600,  1603,  1603,  1605,  1607,  1607,  1609,  1609,  1611,  1613,
    1620,  1620,  1622,  1625,  1625,  1634,  1634,  1636,  1638,  1640,
    1642,  1642,  1644,  1646,  1654,  1658,  1663,  1663,  1665,  1667,
    1669,  1669,  1671,  1678,  1684,  1686,  1689,  1690,  1693,  1693,
    1695,  1697,  1705,  1709,  1714,  1714,  1716,  1718,  1720,  1720,
    1722,  1730,  1736,  1739,  1740,  1742,  1742,  1744,  1746,  1749,
    1749,  1751,  1753,  1761,  1765,  1770,  1770,  1772,  1774,  1776,
    1776,  1778,  1780,  1786,  1788,  1802,  1802,  1804,  1809,  1819,
    1826,  1826,  1829,  1839,  1845,  1851,  1858,  1858,  1860,  1860,
    1862,  1864,  1866,  1866,  1868,  1873,  1875,  1882,  1882,  1884,
    1884,  1886,  1888,  1896,  1896,  1898,  1904,  1904,  1913,  1913,
    1915,  1917,  1919,  1921,  1921,  1923,  1925,  1933,  1937,  1942,
    1942,  1944,  1946,  1949,  1949,  1951,  1958,  1965,  1965,  1967,
    1970,  1971,  1975,  1975,  1977,  1983,  1993,  2001,  2001,  2004,
    2014,  2020,  2026,  2035,  2035,  2037,  2037,  2039,  2041,  2043,
    2043,  2045,  2050,  2052,  2057,  2057,  2059,  2059,  2061,  2063,
    2069,  2069,  2071,  2076,  2076,  2084,  2084,  2086,  2088,  2090,
    2092,  2092,  2094,  2097,  2105,  2109,  2114,  2114,  2116,  2118,
    2120,  2120,  2122,  2129,  2135,  2138,  2139,  2142,  2142,  2144,
    2150,  2160,  2167,  2167,  2170,  2180,  2186,  2192,  2199,  2199,
    2201,  2201,  2203,  2205,  2207,  2207,  2209,  2214,  2216,  2222,
    2222,  2224,  2224,  2226,  2228,  2235,  2235,  2237,  2242,  2251,
    2255,  2260,  2260,  2262,  2264,  2266,  2266,  2268,  2272,  2281,
    2288,  2288,  2291,  2297,  2303,  2311,  2321,  2325,  2330,  2330,
    2332,  2334,  2336,  2336,  2338,  2343,  2347,  2349,  2349,  2351,
    2353,  2364,  2364,  2366,  2371,  2380,  2384,  2389,  2389,  2391,
    2393,  2395,  2395,  2397,  2401,  2410,  2417,  2417,  2420,  2425,
    2431,  2437,  2446,  2450,  2455,  2455,  2457,  2459,  2461,  2461,
    2463,  2468,  2472,  2474,  2474,  2476,  2487,  2493,  2493,  2495,
    2498,  2501,  2507,  2507,  2509,  2512,  2516,  2522,  2522,  2524,
    2527,  2530,  2536,  2536,  2538,  2541,  2544,  2550,  2550,  2552,
    2555,  2558,  2564,  2564,  2566,  2569,  2572,  2577,  2585,  2593,
    2601,  2609,  2615,  2621,  2627,  2633,  2639,  2645,  2651,  2656,
    2665,  2671,  2680,  2681,  2684,  2685,  2686,  2688,  2690,  2690,
    2692,  2693,  2694,  2695
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
  "osrldoc", "osrlStart", "osrlAttributes", "osrlContent", "osrlBody",
  "generalElement", "generalElementStart", "generalElementContent",
  "generalElementEmpty", "generalElementLaden", "generalElementBody",
  "generalElementList", "generalChild", "generalStatus",
  "generalStatusStart", "generalStatusAttributes", "generalStatusAttList",
  "generalStatusATT", "generalStatusContent", "generalStatusEmpty",
  "generalStatusLaden", "generalStatusBody", "generalSubstatusArray",
  "generalSubstatus", "generalSubstatusStart",
  "generalSubstatusAttributes", "generalSubstatusAttList",
  "generalSubstatusATT", "generalSubstatusEnd", "generalMessage",
  "generalMessageStart", "generalMessageContent", "generalMessageEmpty",
  "generalMessageLaden", "generalMessageBody", "serviceURI",
  "serviceURIStart", "serviceURIContent", "serviceURIEmpty",
  "serviceURILaden", "serviceURIBody", "serviceName", "serviceNameStart",
  "serviceNameContent", "serviceNameEmpty", "serviceNameLaden",
  "serviceNameBody", "instanceName", "instanceNameStart",
  "instanceNameContent", "instanceNameEmpty", "instanceNameLaden",
  "instanceNameBody", "jobID", "jobIDStart", "jobIDContent", "jobIDEmpty",
  "jobIDLaden", "jobIDBody", "solverInvoked", "solverInvokedStart",
  "solverInvokedContent", "solverInvokedEmpty", "solverInvokedLaden",
  "solverInvokedBody", "timeStamp", "timeStampStart", "timeStampContent",
  "timeStampEmpty", "timeStampLaden", "timeStampBody",
  "generalOtherResults", "generalOtherResultsStart",
  "generalOtherResultsAttributes", "generalOtherResultsContent",
  "generalOtherResultsEmpty", "generalOtherResultsLaden",
  "generalOtherResultsBody", "generalOtherResultArray",
  "generalOtherResult", "generalOtherResultStart",
  "generalOtherAttributes", "generalOtherAttList", "generalOtherAtt",
  "generalOtherEnd", "systemElement", "systemElementStart",
  "systemElementContent", "systemElementEmpty", "systemElementLaden",
  "systemElementBody", "systemElementList", "systemChild",
  "systemInformation", "systemInformationStart",
  "systemInformationContent", "systemInformationEmpty",
  "systemInformationLaden", "systemInformationBody", "availableDiskSpace",
  "availableDiskSpaceStart", "availableDiskSpaceAttributes",
  "availableDiskSpaceAttList", "availableDiskSpaceAtt",
  "availableDiskSpaceContent", "availableDiskSpaceValue",
  "availableMemory", "availableMemoryStart", "availableMemoryAttributes",
  "availableMemoryAttList", "availableMemoryAtt", "availableMemoryContent",
  "availableMemoryValue", "availableCPUSpeed", "availableCPUSpeedStart",
  "availableCPUSpeedAttributes", "availableCPUSpeedAttList",
  "availableCPUSpeedAtt", "availableCPUSpeedContent",
  "availableCPUSpeedValue", "availableCPUNumber",
  "availableCPUNumberStart", "availableCPUNumberAttributes",
  "availableCPUNumberContent", "availableCPUNumberValue",
  "systemOtherResults", "systemOtherResultsStart",
  "systemOtherResultsAttributes", "systemOtherResultsContent",
  "systemOtherResultsEmpty", "systemOtherResultsLaden",
  "systemOtherResultsBody", "systemOtherResultArray", "systemOtherResult",
  "systemOtherResultStart", "systemOtherAttributes", "systemOtherAttList",
  "systemOtherAtt", "systemOtherEnd", "serviceElement", "serviceContent",
  "serviceChild", "currentState", "currentStateStart",
  "currentStateContent", "currentStateEmpty", "currentStateLaden",
  "currentStateBody", "currentJobCount", "currentJobCountStart",
  "currentJobCountContent", "currentJobCountEmpty", "currentJobCountLaden",
  "currentJobCountBody", "totalJobsSoFar", "totalJobsSoFarStart",
  "totalJobsSoFarContent", "totalJobsSoFarEmpty", "totalJobsSoFarLaden",
  "totalJobsSoFarBody", "timeServiceStarted", "timeServiceStartedStart",
  "timeServiceStartedContent", "timeServiceStartedEmpty",
  "timeServiceStartedLaden", "timeServiceStartedBody",
  "serviceUtilization", "serviceUtilizationStart",
  "serviceUtilizationContent", "serviceUtilizationEmpty",
  "serviceUtilizationLaden", "serviceUtilizationBody",
  "serviceOtherResults", "serviceOtherResultsStart",
  "serviceOtherResultsAttributes", "serviceOtherResultsContent",
  "serviceOtherResultsEmpty", "serviceOtherResultsLaden",
  "serviceOtherResultsBody", "serviceOtherResultArray",
  "serviceOtherResult", "serviceOtherResultStart",
  "serviceOtherAttributes", "serviceOtherAttList", "serviceOtherAtt",
  "serviceOtherEnd", "jobElement", "jobContent", "jobChild", "jobStatus",
  "jobStatusStart", "jobStatusContent", "jobStatusEmpty", "jobStatusLaden",
  "jobStatusBody", "submitTime", "submitTimeStart", "submitTimeContent",
  "submitTimeEmpty", "submitTimeLaden", "submitTimeBody",
  "scheduledStartTime", "scheduledStartTimeStart",
  "scheduledStartTimeContent", "scheduledStartTimeEmpty",
  "scheduledStartTimeLaden", "scheduledStartTimeBody", "actualStartTime",
  "actualStartTimeStart", "actualStartTimeContent", "actualStartTimeEmpty",
  "actualStartTimeLaden", "actualStartTimeBody", "endTime", "endTimeStart",
  "endTimeContent", "endTimeEmpty", "endTimeLaden", "endTimeBody",
  "timingInformation", "timingInformationStart",
  "timingInformationAttributes", "timingInformationContent",
  "timingInformationEmpty", "timingInformationLaden",
  "timingInformationBody", "timeArray", "time", "timeStart",
  "timeAttributes", "timeAtt", "timeContent", "timeEmpty", "timeLaden",
  "timeBody", "timeValue", "usedDiskSpace", "usedDiskSpaceStart",
  "usedDiskSpaceAttributes", "usedDiskSpaceAttList", "usedDiskSpaceAtt",
  "usedDiskSpaceContent", "usedDiskSpaceValue", "usedMemory",
  "usedMemoryStart", "usedMemoryAttributes", "usedMemoryAttList",
  "usedMemoryAtt", "usedMemoryContent", "usedMemoryValue", "usedCPUSpeed",
  "usedCPUSpeedStart", "usedCPUSpeedAttributes", "usedCPUSpeedAttList",
  "usedCPUSpeedAtt", "usedCPUSpeedContent", "usedCPUSpeedValue",
  "usedCPUNumber", "usedCPUNumberStart", "usedCPUNumberAttributes",
  "usedCPUNumberContent", "usedCPUNumberValue", "jobOtherResults",
  "jobOtherResultsStart", "jobOtherResultsAttributes",
  "jobOtherResultsContent", "jobOtherResultsEmpty", "jobOtherResultsLaden",
  "jobOtherResultsBody", "jobOtherResultArray", "jobOtherResult",
  "jobOtherResultStart", "jobOtherAttributes", "jobOtherAttList",
  "jobOtherAtt", "jobOtherEnd", "optimizationElement", "optimizationStart",
  "optimizationAttributes", "optimizationAttList", "optimizationATT",
  "optimizationContent", "optimizationEmpty", "optimizationLaden",
  "optimizationBody", "solutionArray", "solution", "solutionStart",
  "solutionAttributes", "solutionAttList", "solutionATT",
  "targetObjectiveIdxATT", "weightedObjectivesATT", "solutionContent",
  "solutionStatus", "solutionStatusStart", "solutionStatusAttributes",
  "solutionStatusAttList", "solutionStatusATT", "solutionStatusContent",
  "solutionStatusEmpty", "solutionStatusLaden", "solutionStatusBody",
  "solutionSubstatusArray", "solutionSubstatus", "solutionSubstatusStart",
  "solutionSubstatusAttributes", "solutionSubstatusAttList",
  "solutionSubstatusATT", "solutionSubstatusEnd", "solutionMessage",
  "solutionMessageStart", "solutionMessageContent", "solutionMessageEmpty",
  "solutionMessageLaden", "solutionMessageBody", "variables",
  "variablesStart", "numberOfOtherVariableResults", "variablesContent",
  "variablesEmpty", "variablesLaden", "variablesBody", "variableValues",
  "variableValuesStart", "numberOfVarATT", "variableValuesContent",
  "variableValuesEmpty", "variableValuesLaden", "variableValuesBody",
  "varValueArray", "varValue", "varValueStart", "varIdxATT",
  "varValueContent", "varVal", "variableValuesString",
  "variableValuesStringStart", "numberOfVarStringATT",
  "variableValuesStringContent", "variableValuesStringEmpty",
  "variableValuesStringLaden", "variableValuesStringBody",
  "varValueStringArray", "varValueString", "varValueStringStart",
  "varStrIdxATT", "varValueStringContent", "varValueStringEmpty",
  "varValueStringLaden", "varValueStringBody", "basisStatus",
  "basisStatusStart", "numberOfBasisVarATT", "basisStatusContent",
  "basisStatusEmpty", "basisStatusLaden", "basisStatusBody",
  "basisVarArray", "basisVar", "basisVarStart", "basisVarIdxATT",
  "basisVarContent", "otherVariableResultsArray", "otherVariableResult",
  "otherVariableResultStart", "otherVariableResultAttributes",
  "otherVariableResultAttList", "otherVariableResultATT",
  "otherVariableResultContent", "otherVariableResultEmpty",
  "otherVariableResultLaden", "otherVariableResultBody", "otherVarList",
  "otherVar", "otherVarStart", "otherVarIdxATT", "otherVarContent",
  "otherVarEmpty", "otherVarLaden", "otherVarBody", "objectives",
  "objectivesStart", "numberOfOtherObjectiveResults", "objectivesContent",
  "objectivesEmpty", "objectivesLaden", "objectivesBody",
  "objectiveValues", "objectiveValuesStart", "numberOfObjATT",
  "objectiveValuesContent", "objectiveValuesEmpty", "objectiveValuesLaden",
  "objectiveValuesBody", "objValueArray", "objValue", "objValueStart",
  "objIdxATT", "objValueContent", "objVal", "otherObjectiveResultsArray",
  "otherObjectiveResult", "otherObjectiveResultStart",
  "otherObjectiveResultAttributes", "otherObjectiveResultAttList",
  "otherObjectiveResultATT", "otherObjectiveResultContent",
  "otherObjectiveResultEmpty", "otherObjectiveResultLaden",
  "otherObjectiveResultBody", "otherObjList", "otherObj", "otherObjStart",
  "otherObjIdxATT", "otherObjContent", "otherObjEmpty", "otherObjLaden",
  "otherObjBody", "constraints", "constraintsStart",
  "numberOfOtherConstraintResults", "constraintsContent",
  "constraintsEmpty", "constraintsLaden", "constraintsBody", "dualValues",
  "dualValuesStart", "numberOfConATT", "dualValuesContent",
  "dualValuesEmpty", "dualValuesLaden", "dualValuesBody", "dualValueArray",
  "dualValue", "dualValueStart", "conIdxATT", "dualVal",
  "otherConstraintResultsArray", "otherConstraintResult",
  "otherConstraintResultStart", "otherConstraintResultAttributes",
  "otherConstraintResultAttList", "otherConstraintResultATT",
  "otherConstraintResultContent", "otherConstraintResultEmpty",
  "otherConstraintResultLaden", "otherConstraintResultBody",
  "otherConList", "otherCon", "otherConStart", "otherConIdxATT",
  "otherConContent", "otherConEmpty", "otherConLaden", "otherConBody",
  "otherSolutionResults", "otherSolutionResultsStart",
  "numberOfOtherSolutionResults", "otherSolutionResultsContent",
  "otherSolutionResultsEmpty", "otherSolutionResultsLaden",
  "otherSolutionResultsBody", "otherSolutionResultArray",
  "otherSolutionResult", "otherSolutionResultStart",
  "otherSolutionResultAttributes", "otherSolutionResultAttList",
  "otherSolutionResultAtt", "otherSolutionResultContent",
  "otherSolutionResultEmpty", "otherSolutionResultLaden",
  "otherSolutionResultBody", "otherSolutionResultItemArray",
  "otherSolutionResultItem", "otherSolutionResultItemContent",
  "otherSolutionResultItemEmpty", "otherSolutionResultItemLaden",
  "otherSolutionResultItemBody", "otherSolverOutput",
  "otherSolverOutputStart", "numberOfSolverOutputsATT",
  "otherSolverOutputContent", "otherSolverOutputEmpty",
  "otherSolverOutputLaden", "otherSolverOutputBody", "solverOutputArray",
  "solverOutput", "solverOutputStart", "solverOutputAttributes",
  "solverOutputAttList", "solverOutputAtt", "solverOutputContent",
  "solverOutputEmpty", "solverOutputLaden", "solverOutputBody",
  "solverOutputItemArray", "solverOutputItem", "solverOutputItemContent",
  "solverOutputItemEmpty", "solverOutputItemBody", "categoryAttribute",
  "categoryAtt", "categoryAttEmpty", "categoryAttContent",
  "descriptionAttribute", "descriptionAtt", "descriptionAttEmpty",
  "descriptionAttContent", "nameAttribute", "nameAtt", "nameAttEmpty",
  "nameAttContent", "typeAttribute", "typeAtt", "typeAttEmpty",
  "typeAttContent", "unitAttribute", "unitAtt", "unitAttEmpty",
  "unitAttContent", "valueAttribute", "valueAtt", "valueAttEmpty",
  "valueAttContent", "numberOfOtherResultsAttribute",
  "numberOfSolutionsAttribute", "numberOfVariablesAttribute",
  "numberOfConstraintsAttribute", "numberOfObjectivesAttribute",
  "numberOfOtherVariableResultsAttribute",
  "numberOfOtherObjectiveResultsAttribute",
  "numberOfOtherConstraintResultsAttribute",
  "numberOfOtherSolutionResultsAttribute", "numberOfVarAttribute",
  "numberOfObjAttribute", "numberOfConAttribute", "numberOfTimesAttribute",
  "numberOfItemsAttribute", "numberOfSolverOutputsAttribute",
  "numberOfSubstatusesAttribute", "aNumber", "ElementValue", "quote",
  "xmlWhiteSpace", "xmlWhiteSpaceChar", 0
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
       0,   169,   170,   171,   172,   172,   173,   174,   175,   175,
     176,   177,   177,   178,   178,   179,   180,   181,   181,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   183,   184,
     185,   186,   186,   187,   187,   187,   188,   188,   189,   189,
     190,   191,   192,   192,   193,   194,   195,   196,   196,   197,
     197,   198,   198,   199,   200,   201,   201,   202,   202,   203,
     204,   205,   206,   207,   207,   208,   208,   209,   210,   211,
     212,   213,   213,   214,   214,   215,   216,   217,   218,   219,
     219,   220,   220,   221,   222,   223,   224,   225,   225,   226,
     226,   227,   228,   229,   230,   231,   231,   232,   232,   233,
     234,   235,   236,   237,   237,   238,   238,   239,   240,   241,
     242,   243,   244,   244,   245,   245,   246,   247,   248,   248,
     249,   250,   251,   252,   252,   253,   253,   253,   254,   254,
     255,   255,   256,   257,   257,   258,   258,   259,   260,   261,
     261,   262,   262,   262,   262,   262,   262,   263,   264,   265,
     265,   266,   266,   267,   268,   269,   270,   271,   272,   272,
     273,   273,   274,   275,   276,   277,   278,   279,   279,   280,
     280,   281,   282,   283,   284,   285,   286,   286,   287,   287,
     288,   289,   290,   291,   292,   292,   293,   294,   295,   296,
     297,   298,   298,   299,   299,   300,   301,   302,   302,   303,
     304,   305,   306,   306,   307,   307,   307,   308,   308,   309,
     309,   309,   310,   310,   311,   311,   311,   311,   311,   311,
     312,   313,   314,   314,   315,   315,   316,   317,   318,   319,
     320,   320,   321,   321,   322,   323,   324,   325,   326,   326,
     327,   327,   328,   329,   330,   331,   332,   332,   333,   333,
     334,   335,   336,   337,   338,   338,   339,   339,   340,   341,
     342,   343,   344,   345,   345,   346,   346,   347,   348,   349,
     349,   350,   351,   352,   353,   353,   354,   354,   354,   355,
     355,   356,   356,   356,   357,   357,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   359,   360,   361,
     361,   362,   362,   363,   364,   365,   366,   367,   367,   368,
     368,   369,   370,   371,   372,   373,   373,   374,   374,   375,
     376,   377,   378,   379,   379,   380,   380,   381,   382,   383,
     384,   385,   385,   386,   386,   387,   388,   389,   390,   391,
     392,   392,   393,   393,   394,   395,   396,   396,   397,   398,
     399,   399,   400,   400,   400,   400,   401,   401,   402,   402,
     403,   404,   405,   405,   406,   407,   408,   409,   409,   410,
     410,   411,   412,   413,   414,   415,   416,   416,   417,   417,
     418,   419,   420,   421,   422,   423,   423,   424,   424,   425,
     426,   427,   428,   429,   429,   430,   431,   432,   433,   434,
     435,   435,   436,   436,   437,   438,   439,   439,   440,   441,
     442,   443,   443,   444,   444,   444,   445,   445,   446,   446,
     447,   448,   449,   449,   450,   450,   450,   450,   451,   451,
     452,   452,   453,   454,   455,   455,   456,   457,   458,   459,
     459,   460,   460,   461,   462,   463,   464,   465,   466,   467,
     467,   468,   468,   468,   469,   469,   470,   470,   471,   472,
     473,   473,   474,   475,   476,   477,   477,   478,   478,   479,
     479,   480,   480,   481,   482,   482,   483,   483,   484,   485,
     486,   486,   487,   488,   488,   489,   489,   490,   491,   492,
     493,   493,   494,   495,   496,   496,   497,   497,   498,   499,
     500,   500,   501,   502,   503,   504,   505,   505,   506,   506,
     507,   508,   509,   509,   510,   510,   511,   512,   513,   513,
     514,   515,   516,   517,   517,   518,   518,   519,   520,   521,
     521,   522,   523,   524,   524,   525,   525,   526,   527,   528,
     528,   529,   530,   531,   532,   533,   533,   534,   535,   536,
     537,   537,   538,   538,   538,   538,   539,   539,   540,   540,
     541,   542,   543,   543,   544,   545,   546,   547,   547,   548,
     548,   549,   550,   551,   551,   552,   553,   553,   554,   554,
     555,   556,   557,   558,   558,   559,   560,   561,   561,   562,
     562,   563,   564,   565,   565,   566,   567,   568,   568,   569,
     570,   570,   571,   571,   572,   573,   574,   575,   575,   576,
     576,   576,   576,   577,   577,   578,   578,   579,   580,   581,
     581,   582,   583,   584,   585,   585,   586,   586,   587,   588,
     589,   589,   590,   591,   591,   592,   592,   593,   594,   595,
     596,   596,   597,   598,   599,   599,   600,   600,   601,   602,
     603,   603,   604,   605,   606,   607,   607,   608,   608,   609,
     610,   611,   612,   612,   613,   613,   613,   613,   614,   614,
     615,   615,   616,   617,   618,   618,   619,   620,   621,   622,
     622,   623,   623,   624,   625,   626,   626,   627,   628,   629,
     629,   630,   630,   631,   632,   633,   633,   634,   635,   636,
     637,   637,   638,   638,   638,   638,   639,   639,   640,   640,
     641,   642,   643,   643,   644,   645,   645,   646,   646,   647,
     648,   649,   649,   650,   651,   652,   652,   653,   653,   654,
     655,   656,   656,   657,   658,   659,   660,   660,   661,   661,
     661,   661,   662,   662,   663,   663,   664,   665,   666,   666,
     667,   668,   668,   669,   669,   670,   671,   672,   672,   673,
     674,   675,   676,   676,   677,   678,   679,   680,   680,   681,
     682,   683,   684,   684,   685,   686,   687,   688,   688,   689,
     690,   691,   692,   692,   693,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,   706,   707,   708,
     709,   710,   711,   711,   712,   712,   712,   713,   714,   714,
     715,   715,   715,   715
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     0,     1,     3,     5,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       0,     2,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     3,     1,     1,     0,     2,
       1,     1,     3,     1,     3,     1,     1,     0,     2,     1,
       1,     3,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     0,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       2,     4,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     2,
       1,     0,     2,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     3,     1,     1,     0,     2,     1,
       1,     3,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     1,     0,     2,     1,     1,     3,
       1,     3,     1,     0,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     2,     1,     0,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     2,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     4,     3,     8,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     2,
       1,     0,     2,     1,     1,     1,     2,     1,     3,     1,
       0,     3,     1,     0,     1,     1,     1,     1,     3,     4,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     4,     3,     1,     1,     0,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     4,     3,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     4,     1,     1,     2,
       1,     3,     1,     0,     3,     1,     0,     1,     1,     1,
       1,     3,     2,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     0,     4,     3,
       1,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       0,     3,     1,     0,     1,     1,     1,     1,     3,     2,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     5,     1,     4,     1,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     4,     1,
       1,     2,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     1,     1,     1,     1,     1,     2,     0,     2,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     3,     0,     4,     1,     5,     0,     8,     2,    10,
       0,   130,     0,     6,   132,   209,     0,     0,    14,     9,
      11,    12,     0,   281,     0,   136,   131,   133,   134,    13,
      29,    78,    86,    54,   110,    70,    62,    94,   102,     0,
      16,    17,    19,     0,    20,     0,    21,     0,    22,     0,
      23,     0,    24,     0,    25,     0,    26,     0,    27,     0,
     212,   210,     0,   418,   135,   183,   174,   156,   165,   189,
     148,     0,   138,   139,   141,     0,   142,   158,   143,   167,
     144,   176,   145,   184,   146,     0,    15,    18,   808,     0,
     764,     0,   774,     0,    30,    31,    34,   761,   762,   763,
      33,   771,   772,   773,    35,     0,    58,    53,    55,    56,
       0,    66,    61,    63,    64,     0,    74,    69,    71,    72,
       0,    82,    77,    79,    80,     0,    90,    85,    87,    88,
       0,    98,    93,    95,    96,     0,   106,   101,   103,   104,
     808,     0,   111,     0,   284,   282,   420,     7,   422,   137,
     140,     0,   152,   147,   149,   150,     0,   157,     0,   166,
       0,   175,     0,   185,     0,   190,     0,     0,   808,   808,
       0,    39,    28,    36,    37,    32,    60,    57,     0,    68,
      65,     0,    76,    73,     0,    84,    81,     0,    92,    89,
       0,   100,    97,     0,   108,   105,     0,     0,     0,   115,
     109,   112,   113,   211,   229,   221,   261,   253,   245,   237,
     213,   214,     0,   215,     0,   216,     0,   217,     0,   218,
       0,   219,     0,     0,     0,   421,   154,   151,     0,     0,
     155,     0,   779,   159,   161,   160,   776,   777,   778,     0,
     164,   168,   170,   169,     0,   173,   177,   179,   178,     0,
     182,     0,   194,   188,   191,   192,   808,   807,   810,   811,
     812,   813,   809,   765,   775,    38,    45,     0,    41,    42,
      47,    59,    67,    75,    83,    91,    99,   107,   808,   121,
     114,     0,   117,   118,   123,     0,   225,   220,   222,   223,
       0,   233,   228,   230,   231,     0,   241,   236,   238,   239,
       0,   249,   244,   246,   247,     0,   257,   252,   254,   255,
       0,   262,   283,   322,   330,   398,   314,   298,   306,   338,
     392,   383,   365,   374,   285,   286,     0,   287,     0,   288,
       0,   289,     0,   290,     0,   291,     0,   292,   367,   293,
     376,   294,   385,   295,   393,   296,     0,     0,   431,   419,
     428,   429,   808,   808,   808,   808,   423,   424,   425,   426,
     427,   153,   802,   803,     0,   163,   808,     0,   172,     0,
     181,   187,     0,   200,   193,     0,   196,   197,   202,   801,
      40,    43,     0,    46,   786,   116,   119,     0,   122,   227,
     224,     0,   235,   232,     0,   243,   240,     0,   251,   248,
       0,   256,     0,   259,     0,   266,   260,   263,   264,     0,
     302,   297,   299,   300,     0,   310,   305,   307,   308,     0,
     318,   313,   315,   316,     0,   326,   321,   323,   324,     0,
     334,   329,   331,   332,   808,     0,   339,     0,   366,     0,
     375,     0,   384,     0,   394,     0,   399,   430,   437,     0,
     721,   434,   439,     0,     0,     0,     0,   162,   780,   171,
     180,   186,   195,   198,     0,   201,     0,    52,    44,     0,
     769,    48,    50,    49,   766,   767,   768,     0,   129,   120,
       0,   784,   124,   127,   125,   126,   781,   782,   783,   226,
     234,   242,   250,   258,   272,   265,     0,   268,   269,   274,
     304,   301,     0,   312,   309,     0,   320,   317,     0,   328,
     325,     0,   336,   333,     0,     0,     0,   343,   337,   340,
     341,     0,   364,   368,   370,   369,     0,   373,   377,   379,
     378,     0,   382,   386,   388,   387,     0,   391,     0,   403,
     397,   400,   401,   432,   723,   435,   433,     0,     0,   438,
     808,   808,   808,   808,     0,   208,   199,   203,   206,   204,
     205,    51,   808,   128,   808,   267,   270,     0,   273,   303,
     311,   319,   327,   335,   808,   349,   342,     0,   345,   346,
     350,     0,   372,     0,   381,     0,   390,   396,     0,   409,
     402,     0,   405,   406,   411,   808,     0,   724,     0,   436,
     808,     0,   440,   441,   442,   789,   790,   787,   788,   207,
     770,   785,     0,   280,   271,   275,   278,   276,   277,   798,
     344,   347,     0,   371,   380,   389,   395,   404,   407,     0,
     410,     0,     0,   728,   722,   725,   726,   447,   471,     0,
       0,   808,   279,     0,   359,     0,   759,   351,   348,   356,
     357,   354,   756,   757,   758,   355,   353,   352,     0,   417,
     408,   412,   415,   413,   414,   808,   727,   734,     0,   730,
     731,   736,   473,   480,     0,     0,   448,   449,   452,   451,
     453,   808,   444,   363,   362,   358,     0,   361,   808,   416,
     800,   729,   732,     0,   735,   482,   573,   483,     0,   477,
     472,   474,   475,     0,   457,   446,   454,   455,   450,   443,
     360,   760,     0,   745,   733,   742,   743,   808,   737,   739,
     740,   738,   741,   575,   630,   576,   808,     0,   484,   479,
     476,     0,   456,   463,     0,   459,   460,   465,     0,   753,
     754,   744,     0,   747,   748,   750,   751,   752,     0,   632,
     685,   633,   808,     0,   577,     0,   490,   487,   481,   485,
     486,   478,   458,   461,     0,   464,     0,   746,   749,   808,
     687,     0,     0,   808,     0,   634,     0,   583,   580,   574,
     578,   579,   808,   492,     0,   508,     0,     0,   470,   462,
     466,   468,   467,   755,   799,   445,   808,     0,   688,     0,
     640,   637,   631,   635,   636,   808,   585,     0,   602,     0,
     791,   488,   510,   529,     0,   808,     0,   493,   469,     0,
       0,   692,   686,   689,   690,   808,   642,     0,   657,     0,
     792,   581,   582,   808,     0,   586,   531,   545,     0,     0,
     511,     0,     0,   497,   491,   494,   495,   808,   698,   691,
       0,   694,   695,   700,   793,   638,   639,   808,     0,   643,
     605,   603,   607,     0,     0,   590,   584,   587,   588,   489,
       0,   532,     0,   515,   509,   512,   513,   808,   496,   503,
       0,   499,   500,     0,   794,   693,   696,     0,   699,   660,
     658,   662,     0,     0,   647,   641,   644,   645,     0,   606,
     808,   596,   589,     0,   592,   593,   597,   548,   546,   550,
       0,   536,   530,   533,   534,   514,   521,     0,   517,   518,
       0,   795,   498,   501,   808,     0,     0,   709,   697,   706,
     707,   701,   703,   704,   702,   705,     0,   661,   808,   653,
     646,     0,   649,   650,     0,     0,   616,   604,   613,   614,
     608,   612,   611,   610,   609,   796,   591,   594,   808,     0,
       0,   549,   535,   542,     0,   538,   539,     0,   516,   519,
     808,     0,     0,     0,   502,     0,   717,   718,   708,     0,
     711,   712,   714,   715,   716,     0,   671,   659,   668,   669,
     663,   667,   666,   665,   664,   797,   648,   651,   808,     0,
     622,   615,     0,   618,   619,     0,     0,     0,   595,     0,
     559,   547,   556,   557,   551,   555,   554,   553,   552,   537,
     540,   808,     0,     0,     0,   526,   520,   523,   524,   808,
     506,   507,     0,   720,     0,   710,   713,   677,   670,     0,
     673,   674,     0,     0,     0,   617,   620,   808,     0,   808,
     600,   601,     0,   558,   565,     0,   561,   562,     0,     0,
       0,   541,   808,   528,   525,     0,   504,   505,   719,   672,
     675,   808,     0,   808,   655,   656,     0,     0,     0,   627,
     621,   624,   625,   598,   599,   560,   563,   808,     0,   808,
       0,   522,   527,     0,     0,   682,   676,   679,   680,   654,
     652,   808,   804,   805,   806,   626,     0,   629,     0,     0,
     570,   564,   567,   568,   543,   544,   808,   681,     0,   684,
     623,   628,   808,   569,     0,   572,   678,   683,   566,   571
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,    10,    11,    12,    19,    20,
      21,    39,    40,    41,    42,    43,    93,    94,    95,   172,
     173,   174,   267,   268,   269,   270,   382,   383,   471,   468,
      44,    45,   107,   108,   109,   178,    46,    47,   112,   113,
     114,   181,    48,    49,   117,   118,   119,   184,    50,    51,
     122,   123,   124,   187,    52,    53,   127,   128,   129,   190,
      54,    55,   132,   133,   134,   193,    56,    57,   137,   138,
     139,   196,    58,    59,   141,   200,   201,   202,   281,   282,
     283,   284,   387,   388,   482,   479,    15,    16,    26,    27,
      28,    71,    72,    73,    74,    75,   153,   154,   155,   228,
      76,    77,   156,   157,   233,   230,   364,    78,    79,   158,
     159,   241,   240,   367,    80,    81,   160,   161,   246,   245,
     369,    82,    83,   162,   250,   372,    84,    85,   164,   253,
     254,   255,   375,   376,   377,   378,   464,   465,   557,   556,
      23,   143,   210,   211,   212,   287,   288,   289,   391,   213,
     214,   292,   293,   294,   394,   215,   216,   297,   298,   299,
     397,   217,   218,   302,   303,   304,   400,   219,   220,   307,
     308,   309,   402,   221,   222,   310,   406,   407,   408,   496,
     497,   498,   499,   567,   568,   615,   614,    63,   223,   324,
     325,   326,   411,   412,   413,   502,   327,   328,   416,   417,
     418,   505,   329,   330,   421,   422,   423,   508,   331,   332,
     426,   427,   428,   511,   333,   334,   431,   432,   433,   514,
     335,   336,   435,   518,   519,   520,   577,   578,   579,   580,
     622,   647,   648,   649,   650,   686,   687,   337,   338,   437,
     438,   523,   522,   581,   339,   340,   439,   440,   528,   527,
     583,   341,   342,   441,   442,   533,   532,   585,   343,   344,
     443,   537,   588,   345,   346,   445,   540,   541,   542,   591,
     592,   593,   594,   629,   630,   661,   660,   147,   148,   224,
     225,   356,   349,   350,   351,   449,   450,   451,   452,   548,
     549,   602,   603,   604,   599,   638,   639,   675,   676,   677,
     705,   706,   707,   734,   735,   736,   737,   764,   765,   790,
     789,   673,   674,   700,   701,   702,   731,   696,   697,   727,
     758,   759,   760,   784,   785,   786,   816,   844,   845,   846,
     880,   881,   882,   883,   925,   974,  1032,   813,   814,   839,
     874,   875,   876,   917,   918,   919,   920,   971,  1026,  1027,
    1028,  1065,   837,   838,   870,   912,   913,   914,   964,   965,
     966,   967,  1022,  1061,   869,   908,   909,   960,   961,  1014,
    1011,  1012,  1013,  1055,  1056,  1057,  1058,  1088,  1111,  1112,
    1113,  1124,   724,   725,   753,   779,   780,   781,   807,   808,
     809,   834,   866,   867,   868,   903,   904,   905,   906,   959,
    1008,  1052,   832,   861,   862,   898,   899,   950,   947,   948,
     949,  1002,  1003,  1004,  1005,  1048,  1080,  1081,  1082,  1106,
     750,   751,   774,   802,   803,   804,   827,   828,   829,   858,
     895,   896,   897,   941,   942,   943,   944,   999,  1076,   856,
     890,   891,   936,   937,   990,   987,   988,   989,  1039,  1040,
    1041,  1042,  1072,  1096,  1097,  1098,  1118,   771,   772,   797,
     822,   823,   824,   850,   851,   852,   853,   887,   888,   931,
     928,   929,   930,   979,   980,   981,   982,   983,   984,  1034,
     546,   547,   596,   634,   635,   636,   668,   669,   670,   671,
     693,   694,   718,   714,   715,   716,   742,   743,   744,   745,
     746,   747,   651,   652,   653,   654,    96,    97,    98,    99,
     473,   474,   475,   476,   100,   101,   102,   103,   235,   236,
     237,   238,   485,   486,   487,   488,   142,   357,   358,   359,
     360,   728,   754,   775,   798,   817,   835,   859,   436,   722,
     597,   104,   365,  1107,   166,   167,   262
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1035
static const yytype_int16 yypact[] =
{
      48, -1035,    58,    67, -1035, -1035,   108,    76, -1035, -1035,
     111,   114,    59, -1035, -1035,   129,   163,    -6, -1035, -1035,
   -1035, -1035,   186,   135,   -11, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   134,
      90, -1035, -1035,   263, -1035,   214, -1035,   237, -1035,   301,
   -1035,   312, -1035,   314, -1035,   316, -1035,   318, -1035,   190,
   -1035, -1035,   320,   155, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035,   140,    95, -1035, -1035,   322, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035,    68, -1035,   190, -1035, -1035, -1035,   230,
   -1035,   253, -1035,   324,   263, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035,    38, -1035, -1035, -1035, -1035,
      22, -1035, -1035, -1035, -1035,    23, -1035, -1035, -1035, -1035,
      41, -1035, -1035, -1035, -1035,    44, -1035, -1035, -1035, -1035,
      21, -1035, -1035, -1035, -1035,     9, -1035, -1035, -1035, -1035,
   -1035,   326, -1035,   -14, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035,    20, -1035, -1035, -1035, -1035,   219,   203,   255,   203,
     262,   203,   268, -1035,   328, -1035,   217,     2, -1035, -1035,
     -27, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   193, -1035,
   -1035,   176, -1035, -1035,   165, -1035, -1035,   209, -1035, -1035,
     222, -1035, -1035,   229, -1035, -1035,   177,   353,   -13, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035,   330, -1035,   332, -1035,   334, -1035,   336, -1035,
     338, -1035,   190,   -21,   340,   264, -1035, -1035,   224,   346,
   -1035,   360, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   346,
   -1035, -1035, -1035, -1035,   346, -1035, -1035, -1035, -1035,   427,
   -1035,    79, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035,   362,   289, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035,   335,   348, -1035, -1035,    45, -1035, -1035, -1035, -1035,
      65, -1035, -1035, -1035, -1035,     6, -1035, -1035, -1035, -1035,
      14, -1035, -1035, -1035, -1035,    24, -1035, -1035, -1035, -1035,
     344, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035,   347, -1035,   355, -1035,
     357, -1035,   359, -1035,   361, -1035,   428, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,    68, -1035,   190,    -7, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,   383, -1035, -1035,   385, -1035,   391,
   -1035, -1035,   397, -1035, -1035,   350,   351, -1035, -1035, -1035,
   -1035, -1035,   363,   172, -1035, -1035, -1035,   365,   274, -1035,
   -1035,   381, -1035, -1035,   387, -1035, -1035,   319, -1035, -1035,
     329, -1035,   349, -1035,   151, -1035, -1035, -1035, -1035,    19,
   -1035, -1035, -1035, -1035,    16, -1035, -1035, -1035, -1035,    28,
   -1035, -1035, -1035, -1035,    47, -1035, -1035, -1035, -1035,    57,
   -1035, -1035, -1035, -1035, -1035,   367, -1035,   451,   203,   453,
     203,   457,   203,   459, -1035,   369, -1035, -1035, -1035,   414,
     -50, -1035, -1035,   468,   469,   470,   471, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,   371,   274,   343, -1035, -1035,   476,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035,   374, -1035, -1035,
     477, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035,   376,   377, -1035, -1035,
   -1035, -1035,   356, -1035, -1035,   358, -1035, -1035,   372, -1035,
   -1035,   423, -1035, -1035,   395,   478,   -47, -1035, -1035, -1035,
   -1035,   346, -1035, -1035, -1035, -1035,   346, -1035, -1035, -1035,
   -1035,   346, -1035, -1035, -1035, -1035,   482, -1035,   173, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035,   472,   483,    35,
   -1035, -1035, -1035, -1035,   389, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035,   373,   274, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035,   354,   364, -1035,
   -1035,   339, -1035,   345, -1035,   352, -1035, -1035,   366, -1035,
   -1035,   399,   400, -1035, -1035, -1035,   375, -1035,   368, -1035,
   -1035,   491, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035,   402, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035,   207, -1035, -1035, -1035, -1035, -1035, -1035,   378,
     274,   498,   -48, -1035, -1035, -1035, -1035, -1035,   409,   263,
     504, -1035, -1035,    15, -1035,   508, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   405, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   401,   393,
   -1035, -1035, -1035,   370,   380,   382,   263, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035,   403, -1035, -1035, -1035,
   -1035, -1035, -1035,   384,   220, -1035,   413,   493,    40, -1035,
   -1035, -1035, -1035,   158, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035,    61, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,   441,   499, -1035,   386, -1035, -1035,
   -1035,   425, -1035, -1035,   407,   411, -1035, -1035,   515, -1035,
   -1035, -1035,   410,   213, -1035, -1035, -1035, -1035,   517, -1035,
     412,   509, -1035,   388, -1035,   521,   379, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,   390,   226,   474, -1035, -1035, -1035,
   -1035,   418,   510, -1035,   392, -1035,   522,   416, -1035, -1035,
   -1035, -1035, -1035, -1035,   420,   424,   503,   422, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035,   394, -1035,   525,
     450, -1035, -1035, -1035, -1035, -1035, -1035,   445, -1035,   532,
   -1035, -1035, -1035,   464,   503, -1035,   396, -1035, -1035,   531,
     206, -1035, -1035, -1035, -1035, -1035, -1035,   461, -1035,   537,
   -1035, -1035,   444, -1035,   398, -1035, -1035, -1035,   503,   404,
   -1035,   545,   161, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
     440,   448, -1035, -1035, -1035, -1035,   449, -1035,   406, -1035,
   -1035, -1035, -1035,   548,   -42, -1035, -1035, -1035, -1035,   454,
     408, -1035,   261, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
     430,   429, -1035,   530, -1035, -1035, -1035,   415,   220, -1035,
   -1035, -1035,   556,     0, -1035, -1035, -1035, -1035,   417,   160,
   -1035, -1035, -1035,   431,   465, -1035,   535, -1035, -1035, -1035,
     -19, -1035, -1035, -1035, -1035, -1035, -1035,   433,   442, -1035,
     536, -1035, -1035, -1035, -1035,   557,   119, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035,   419,   187, -1035, -1035,
   -1035,   481,   492, -1035,   540,    53, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   560,
     421,   235, -1035, -1035,   500,   443, -1035,   542, -1035, -1035,
   -1035,   426,   568,   432, -1035,   570, -1035, -1035, -1035,   467,
     243, -1035, -1035, -1035, -1035,   -29, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   566,
   -1035, -1035,   484,   486, -1035,   550,   575,   434, -1035,   -61,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035,   580,   579,    11, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035,   438, -1035,   534, -1035, -1035, -1035, -1035,   487,
     519, -1035,   567,   591,   436, -1035, -1035, -1035,   435, -1035,
   -1035, -1035,   501, -1035, -1035,   494,   446, -1035,   576,   598,
     603, -1035, -1035, -1035, -1035,   447, -1035, -1035, -1035, -1035,
   -1035, -1035,   437, -1035, -1035, -1035,   533,   605,    31, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   439, -1035,
     452, -1035, -1035,   608,    99, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035,   516, -1035,   611,    10,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   541, -1035,
   -1035, -1035, -1035, -1035,   458, -1035, -1035, -1035, -1035, -1035
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035,   569, -1035, -1035, -1035, -1035,   526, -1035,
   -1035, -1035, -1035, -1035,   455, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
     341, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035,   549, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035,   246, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035,   127, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,    49, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035,    33, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035,   178, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   -46,
   -1035, -1035, -1035, -1035, -1035,  -109, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035,  -250, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035,  -286, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
    -331, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035,  -421, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035,  -268, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035,  -366, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035,  -304, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
    -401, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035,  -211, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035,  -339, -1035, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   -26, -1035,
   -1035, -1035, -1035, -1035, -1035, -1035, -1035, -1035,   -99, -1035,
   -1035, -1035,  -686, -1035, -1035, -1035,   -78, -1035, -1035, -1035,
    -381, -1035, -1035, -1035,  -603, -1035, -1035, -1035,  -157, -1035,
   -1035, -1035,  -464, -1035, -1035, -1035,   -82, -1035, -1035, -1035,
   -1035, -1035, -1035, -1035, -1035,  -805,  -254,  -291, -1035,  -241,
   -1035,  -587,  -233, -1034,  -140, -1035, -1035
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     197,   560,   243,   165,   248,   163,   368,   484,   719,   840,
     257,   370,   395,   194,  1102,  1063,  1103,  1104,   398,   656,
     503,   683,   684,   500,   226,   191,   179,   182,   263,   264,
     362,   363,   506,   871,   312,  1102,   679,  1103,  1104,   203,
      64,   313,   176,    29,   729,   185,  1053,  1037,   188,   389,
     447,   509,   680,    65,   962,    66,   901,    67,     4,    68,
    1119,   512,   265,   600,   544,   314,   204,   666,   205,    17,
      18,   392,   403,   679,   448,  1125,   939,   601,  1038,   234,
     667,   242,    30,   247,   559,   940,    31,   315,    32,   680,
      33,   575,     1,   279,   206,   316,   280,    69,   576,  1054,
      89,    90,    34,  1102,   618,  1103,  1104,   266,   207,   317,
     510,   318,    35,     5,    36,   902,   379,   448,     7,   738,
      37,   739,   740,   319,     9,    70,   208,   320,   390,   321,
    1105,   322,   209,   323,   186,   177,    38,   730,   384,   189,
     311,   963,   183,   180,   513,   507,   393,   401,   192,   504,
     501,  1000,   195,   396,   685,   399,  1018,   227,    13,    65,
    1001,    66,   792,    67,    14,    68,   664,   258,   259,   260,
     261,  1123,  1064,    24,    25,   833,  1117,   975,    30,   976,
     977,    22,    31,    86,    32,   373,    33,   617,   374,    62,
     741,   149,    89,    90,   469,   470,    60,    61,    34,   857,
     480,   481,   932,    69,    89,    90,   469,   470,    35,   140,
      36,   146,   453,   454,   455,   456,    37,   643,   644,    89,
      90,   469,   470,   256,   105,   106,   458,   480,   481,   229,
     978,    70,    38,   168,   717,    89,    90,   645,   646,    89,
      90,   231,   232,    91,    92,   231,   232,   110,   111,   663,
     645,   646,    89,    90,   469,   470,   169,   494,    89,    90,
     495,   815,    91,    92,   446,   239,   444,    89,    90,   469,
     470,   738,   244,   739,   740,   480,   481,   352,   249,   589,
     353,   525,   590,   530,   273,   535,   354,    88,   582,   732,
     271,   355,   733,   584,   515,    89,    90,   272,   586,    91,
      92,   975,   274,   976,   977,   472,    89,    90,   469,   470,
     483,   115,   116,   721,   480,   481,   848,   275,   878,   849,
     277,   879,   120,   121,   125,   126,   130,   131,   135,   136,
     144,   145,   151,   152,   170,   171,   198,   199,   251,   252,
     285,   286,   290,   291,   295,   296,   300,   301,   305,   306,
     347,   348,   362,   363,   404,   405,   276,   409,   410,   278,
     524,   361,   529,   366,   534,   414,   415,   419,   420,   424,
     425,   429,   430,   466,   467,   477,   478,   516,   517,   538,
     539,   554,   555,   612,   613,   632,   633,   558,   658,   659,
     698,   699,   703,   704,   712,   713,   756,   757,   777,   778,
     787,   788,   800,   801,   820,   821,   842,   843,   864,   865,
     605,   606,   607,   608,   872,   873,   893,   894,   910,   911,
     915,   916,   610,   266,   611,   926,   927,   945,   946,   985,
     986,  1009,  1010,   371,   619,   953,  1024,  1025,  1030,  1031,
    1050,  1051,  1074,  1075,   385,  1078,  1079,  1094,  1095,  1109,
    1110,   380,   457,   434,   279,   631,   459,   373,   460,   462,
     640,   521,   461,   526,   489,   657,   491,   531,   490,   536,
     492,   543,   493,   993,   550,   551,   552,   553,   561,   562,
     564,   563,   573,   494,   574,   565,   572,   569,   587,   571,
     616,   570,   623,   598,   641,   595,   609,  1017,   637,   620,
     624,   682,   575,   625,   665,   672,   589,   934,   627,   642,
     681,   688,   689,   723,   726,   626,   691,   752,   952,   749,
     766,   667,   761,   769,   770,   690,   773,   782,   805,   815,
     796,   825,   695,   793,   826,   783,   836,   847,   762,   767,
     855,   709,   710,   795,   655,   733,   831,   833,   711,   857,
     860,   877,   662,   885,   900,   889,   992,   818,   848,   924,
     907,   678,   938,   901,   958,   970,   996,   973,   939,   998,
    1007,  1021,   806,  1019,  1029,  1033,  1044,   748,  1035,  1047,
    1016,  1049,   812,   811,  1000,  1062,   755,   922,   956,   879,
    1060,  1045,   968,  1068,  1069,  1037,  1071,  1073,   678,  1067,
    1084,  1085,   916,   963,  1089,  1087,  1054,  1090,  1092,    87,
    1100,  1101,   776,  1115,  1116,  1121,   720,  1122,  1127,  1129,
     175,   150,   463,   386,   566,   628,   763,   621,   545,   794,
     708,   923,   969,   799,  1020,  1086,   957,  1046,   997,  1070,
     886,  1036,   810,   692,   768,   954,   994,   935,     0,     0,
       0,     0,     0,     0,     0,     0,   819,     0,     0,     0,
       0,     0,     0,     0,     0,   830,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   841,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   854,     0,   791,     0,     0,
       0,     0,     0,   863,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   884,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   892,     0,     0,
       0,     0,     0,   381,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   921,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     955,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   972,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   995,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     933,     0,     0,     0,     0,     0,     0,     0,  1006,     0,
       0,   951,     0,     0,     0,     0,     0,     0,     0,     0,
    1023,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1043,   991,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1059,     0,  1015,     0,     0,     0,     0,     0,  1066,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1077,     0,  1083,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1091,     0,     0,     0,     0,     0,     0,     0,
       0,  1093,     0,  1099,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1108,     0,  1114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1126,     0,     0,     0,
       0,     0,  1128
};

static const yytype_int16 yycheck[] =
{
     140,   465,   159,    85,   161,    83,   239,   388,   694,   814,
       8,   244,     6,     4,     4,     4,     6,     7,     4,   622,
       4,     6,     7,     4,     4,     4,     4,     4,   168,   169,
       6,     7,     4,   838,    55,     4,   639,     6,     7,    53,
      51,    62,     4,    49,     4,     4,   107,    76,     4,     4,
      57,     4,   639,    64,    73,    66,    98,    68,     0,    70,
    1094,     4,    89,    28,   114,    86,    80,   115,    82,    10,
      11,     6,   305,   676,   124,  1109,    76,    42,   107,   157,
     128,   159,    88,   161,   465,    85,    92,   108,    94,   676,
      96,   138,    44,   106,   108,   116,   109,   108,   145,   160,
      32,    33,   108,     4,   568,     6,     7,   134,   122,   130,
      63,   132,   118,    46,   120,   157,   256,   124,    10,    58,
     126,    60,    61,   144,    48,   136,   140,   148,    83,   150,
      99,   152,   146,   154,    93,    97,   142,    97,   278,    95,
     222,   160,   119,   121,    87,   117,    81,   123,   127,   133,
     131,    98,   143,   147,   139,   141,   961,   137,    47,    64,
     107,    66,   765,    68,    50,    70,   630,   165,   166,   167,
     168,   161,   161,    10,    11,    15,    77,    58,    88,    60,
      61,    52,    92,    49,    94,   106,    96,   568,   109,    54,
     129,    51,    32,    33,    34,    35,    10,    11,   108,    12,
      40,    41,   888,   108,    32,    33,    34,    35,   118,    19,
     120,    56,   352,   353,   354,   355,   126,    10,    11,    32,
      33,    34,    35,     6,    10,    11,   366,    40,    41,    10,
     111,   136,   142,     3,    14,    32,    33,    30,    31,    32,
      33,    38,    39,    36,    37,    38,    39,    10,    11,   630,
      30,    31,    32,    33,    34,    35,     3,   106,    32,    33,
     109,    26,    36,    37,   346,    10,   344,    32,    33,    34,
      35,    58,    10,    60,    61,    40,    41,    13,    10,   106,
      16,   438,   109,   440,   119,   442,    22,    24,   521,   131,
      97,    27,   134,   526,   434,    32,    33,   121,   531,    36,
      37,    58,    93,    60,    61,   383,    32,    33,    34,    35,
     388,    10,    11,   694,    40,    41,   110,    95,   157,   113,
     143,   160,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,     6,     7,    10,    11,   127,    10,    11,     6,
     438,   137,   440,     3,   442,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,   465,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     550,   551,   552,   553,    10,    11,    10,    11,    10,    11,
     159,   160,   562,   134,   564,    10,    11,    10,    11,    10,
      11,    10,    11,     6,   574,   899,    10,    11,     6,     7,
       6,     7,     6,     7,   109,    10,    11,    10,    11,    10,
      11,    89,    69,    25,   106,   595,    71,   106,    67,   109,
     600,    10,    65,    10,    83,   622,   147,    10,    81,    10,
     141,    57,   123,   937,     6,     6,     6,     6,   135,     3,
       3,   107,    87,   106,     6,   109,    63,   131,     6,   117,
     568,   133,   153,    10,     3,    23,   107,   961,   130,   145,
     155,   641,   138,   151,     6,    96,   106,   888,   109,   107,
       6,     3,   107,   100,    21,   149,   115,    18,   899,    78,
       5,   128,    97,     6,   112,   665,    17,     6,     6,    26,
      20,     6,   162,    59,    84,   156,    72,     6,   131,   129,
      79,   681,   139,   125,   622,   134,   101,    15,   688,    12,
     106,     6,   630,   113,     6,   106,   937,   135,   110,    29,
     106,   639,     6,    98,    29,    29,    85,    10,    76,    29,
      10,    29,   156,    73,     6,     5,    10,   717,   111,    29,
     961,     6,   158,   163,    98,     6,   726,   157,   157,   160,
      10,   107,   159,    59,   107,    76,    29,     6,   676,   161,
      99,   107,   160,   160,     6,    29,   160,     4,   161,    40,
      77,     6,   752,   161,     6,    99,   694,     6,    77,   161,
      94,    72,   376,   282,   497,   592,   735,   578,   450,   769,
     676,   881,   918,   773,   965,  1056,   904,  1003,   942,  1040,
     851,   980,   782,   669,   743,   899,   937,   888,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   796,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   805,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   815,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   825,    -1,   765,    -1,    -1,
      -1,    -1,    -1,   833,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   847,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   857,    -1,    -1,
      -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   877,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     900,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   924,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   938,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     888,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   958,    -1,
      -1,   899,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     970,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   998,   937,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1021,    -1,   961,    -1,    -1,    -1,    -1,    -1,  1029,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1047,    -1,  1049,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1062,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1071,    -1,  1073,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1087,    -1,  1089,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1116,    -1,    -1,    -1,
      -1,    -1,  1122
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,     0,    46,   172,    10,   173,    48,
     174,   175,   176,    47,    50,   255,   256,    10,    11,   177,
     178,   179,    52,   309,    10,    11,   257,   258,   259,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   180,
     181,   182,   183,   184,   199,   200,   205,   206,   211,   212,
     217,   218,   223,   224,   229,   230,   235,   236,   241,   242,
      10,    11,    54,   356,    51,    64,    66,    68,    70,   108,
     136,   260,   261,   262,   263,   264,   269,   270,   276,   277,
     283,   284,   290,   291,   295,   296,    49,   182,    24,    32,
      33,    36,    37,   185,   186,   187,   675,   676,   677,   678,
     683,   684,   685,   686,   710,    10,    11,   201,   202,   203,
      10,    11,   207,   208,   209,    10,    11,   213,   214,   215,
      10,    11,   219,   220,   221,    10,    11,   225,   226,   227,
      10,    11,   231,   232,   233,    10,    11,   237,   238,   239,
      19,   243,   695,   310,    10,    11,    56,   446,   447,    51,
     262,    10,    11,   265,   266,   267,   271,   272,   278,   279,
     285,   286,   292,   675,   297,   695,   713,   714,     3,     3,
      10,    11,   188,   189,   190,   187,     4,    97,   204,     4,
     121,   210,     4,   119,   216,     4,    93,   222,     4,    95,
     228,     4,   127,   234,     4,   143,   240,   713,    10,    11,
     244,   245,   246,    53,    80,    82,   108,   122,   140,   146,
     311,   312,   313,   318,   319,   324,   325,   330,   331,   336,
     337,   342,   343,   357,   448,   449,     4,   137,   268,    10,
     274,    38,    39,   273,   675,   687,   688,   689,   690,    10,
     281,   280,   675,   687,    10,   288,   287,   675,   687,    10,
     293,    10,    11,   298,   299,   300,     6,     8,   165,   166,
     167,   168,   715,   713,   713,    89,   134,   191,   192,   193,
     194,    97,   121,   119,    93,    95,   127,   143,     6,   106,
     109,   247,   248,   249,   250,    10,    11,   314,   315,   316,
      10,    11,   320,   321,   322,    10,    11,   326,   327,   328,
      10,    11,   332,   333,   334,    10,    11,   338,   339,   340,
     344,   695,    55,    62,    86,   108,   116,   130,   132,   144,
     148,   150,   152,   154,   358,   359,   360,   365,   366,   371,
     372,   377,   378,   383,   384,   389,   390,   406,   407,   413,
     414,   420,   421,   427,   428,   432,   433,    10,    11,   451,
     452,   453,    13,    16,    22,    27,   450,   696,   697,   698,
     699,   137,     6,     7,   275,   711,     3,   282,   711,   289,
     711,     6,   294,   106,   109,   301,   302,   303,   304,   713,
      89,   193,   195,   196,   713,   109,   249,   251,   252,     4,
      83,   317,     6,    81,   323,     6,   147,   329,     4,   141,
     335,   123,   341,   711,    10,    11,   345,   346,   347,    10,
      11,   361,   362,   363,    10,    11,   367,   368,   369,    10,
      11,   373,   374,   375,    10,    11,   379,   380,   381,    10,
      11,   385,   386,   387,    25,   391,   707,   408,   409,   415,
     416,   422,   423,   429,   675,   434,   695,    57,   124,   454,
     455,   456,   457,   713,   713,   713,   713,    69,   713,    71,
      67,    65,   109,   303,   305,   306,    10,    11,   198,    34,
      35,   197,   675,   679,   680,   681,   682,    10,    11,   254,
      40,    41,   253,   675,   679,   691,   692,   693,   694,    83,
      81,   147,   141,   123,   106,   109,   348,   349,   350,   351,
       4,   131,   364,     4,   133,   370,     4,   117,   376,     4,
      63,   382,     4,    87,   388,   713,    10,    11,   392,   393,
     394,    10,   411,   410,   675,   687,    10,   418,   417,   675,
     687,    10,   425,   424,   675,   687,    10,   430,    10,    11,
     435,   436,   437,    57,   114,   456,   649,   650,   458,   459,
       6,     6,     6,     6,    10,    11,   308,   307,   675,   679,
     691,   135,     3,   107,     3,   109,   350,   352,   353,   131,
     133,   117,    63,    87,     6,   138,   145,   395,   396,   397,
     398,   412,   711,   419,   711,   426,   711,     6,   431,   106,
     109,   438,   439,   440,   441,    23,   651,   709,    10,   463,
      28,    42,   460,   461,   462,   713,   713,   713,   713,   107,
     713,   713,    10,    11,   355,   354,   675,   679,   691,   713,
     145,   397,   399,   153,   155,   151,   149,   109,   440,   442,
     443,   713,    10,    11,   652,   653,   654,   130,   464,   465,
     713,     3,   107,    10,    11,    30,    31,   400,   401,   402,
     403,   671,   672,   673,   674,   675,   683,   687,    10,    11,
     445,   444,   675,   679,   691,     6,   115,   128,   655,   656,
     657,   658,    96,   480,   481,   466,   467,   468,   675,   683,
     710,     6,   713,     6,     7,   139,   404,   405,     3,   107,
     713,   115,   657,   659,   660,   162,   486,   487,    10,    11,
     482,   483,   484,    10,    11,   469,   470,   471,   468,   713,
     139,   713,    10,    11,   662,   663,   664,    14,   661,   671,
     675,   679,   708,   100,   551,   552,    21,   488,   700,     4,
      97,   485,   131,   134,   472,   473,   474,   475,    58,    60,
      61,   129,   665,   666,   667,   668,   669,   670,   713,    78,
     589,   590,    18,   553,   701,   713,    10,    11,   489,   490,
     491,    97,   131,   474,   476,   477,     5,   129,   667,     6,
     112,   626,   627,    17,   591,   702,   713,    10,    11,   554,
     555,   556,     6,   156,   492,   493,   494,    10,    11,   479,
     478,   675,   683,    59,   713,   125,    20,   628,   703,   713,
      10,    11,   592,   593,   594,     6,   156,   557,   558,   559,
     713,   163,   158,   506,   507,    26,   495,   704,   135,   713,
      10,    11,   629,   630,   631,     6,    84,   595,   596,   597,
     713,   101,   571,    15,   560,   705,    72,   521,   522,   508,
     704,   713,    10,    11,   496,   497,   498,     6,   110,   113,
     632,   633,   634,   635,   713,    79,   608,    12,   598,   706,
     106,   572,   573,   713,    10,    11,   561,   562,   563,   533,
     523,   704,    10,    11,   509,   510,   511,     6,   157,   160,
     499,   500,   501,   502,   713,   113,   634,   636,   637,   106,
     609,   610,   713,    10,    11,   599,   600,   601,   574,   575,
       6,    98,   157,   564,   565,   566,   567,   106,   534,   535,
      10,    11,   524,   525,   526,   159,   160,   512,   513,   514,
     515,   713,   157,   501,    29,   503,    10,    11,   639,   640,
     641,   638,   671,   675,   679,   708,   611,   612,     6,    76,
      85,   602,   603,   604,   605,    10,    11,   577,   578,   579,
     576,   675,   679,   691,   705,   713,   157,   566,    29,   568,
     536,   537,    73,   160,   527,   528,   529,   530,   159,   514,
      29,   516,   713,    10,   504,    58,    60,    61,   111,   642,
     643,   644,   645,   646,   647,    10,    11,   614,   615,   616,
     613,   675,   679,   691,   706,   713,    85,   604,    29,   606,
      98,   107,   580,   581,   582,   583,   713,    10,   569,    10,
      11,   539,   540,   541,   538,   675,   679,   691,   704,    73,
     529,    29,   531,   713,    10,    11,   517,   518,   519,     6,
       6,     7,   505,     5,   648,   111,   644,    76,   107,   617,
     618,   619,   620,   713,    10,   107,   582,    29,   584,     6,
       6,     7,   570,   107,   160,   542,   543,   544,   545,   713,
      10,   532,     6,     4,   161,   520,   713,   161,    59,   107,
     619,    29,   621,     6,     6,     7,   607,   713,    10,    11,
     585,   586,   587,   713,    99,   107,   544,    29,   546,     6,
       4,   713,   161,   713,    10,    11,   622,   623,   624,   713,
      77,     6,     4,     6,     7,    99,   588,   712,   713,    10,
      11,   547,   548,   549,   713,   161,     6,    77,   625,   712,
     713,    99,     6,   161,   550,   712,   713,    77,   713,   161
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osresult, parserData);
      YYFPRINTF (stderr, "\n");
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





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  yylloc.first_column = yylloc.last_column = 1;
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 3:

    {
#ifdef DEBUG
yydebug = 1;
#endif
}
    break;

  case 29:

    {	if (parserData->generalStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one generalStatus element allowed");	
		if (osresult->general->generalStatus != NULL) 
			osrlerror(NULL, NULL, parserData, "generalStatus previously allocated");
		parserData->generalStatusPresent = true;
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
	}
    break;

  case 30:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	}
    break;

  case 33:

    { 
	    if ((parserData->typeAttribute != "error"  ) &&
	        (parserData->typeAttribute != "warning") && 
	        (parserData->typeAttribute != "normal"))
			osrlerror(NULL, NULL, parserData, "general status type does not match any legal value");
		if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, "Error while setting general status type");
	}
    break;

  case 34:

    {   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	}
    break;

  case 35:

    {   if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "Attempting to reallocate substatus array. Potential loss of data.");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	}
    break;

  case 36:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	}
    break;

  case 37:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	}
    break;

  case 44:

    {	parserData->kounter++;
}
    break;

  case 45:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
}
    break;

  case 46:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
}
    break;

  case 49:

    {	
		if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "Error while setting <general> substatus name");
	}
    break;

  case 50:

    {	
		if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "Error while setting <general> substatus description");
	}
    break;

  case 54:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	}
    break;

  case 60:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 62:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	}
    break;

  case 68:

    {osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 70:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	}
    break;

  case 76:

    {osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 78:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	}
    break;

  case 84:

    {osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 86:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	}
    break;

  case 92:

    {osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 94:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	}
    break;

  case 100:

    {osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 102:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	}
    break;

  case 108:

    {osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 110:

    {	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	}
    break;

  case 111:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, "number of other general results cannot be negative");
	if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "Attempting to reallocate other general results array. Potential loss of data.");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 112:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}
    break;

  case 113:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	}
    break;

  case 120:

    {	parserData->kounter++;
}
    break;

  case 121:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
}
    break;

  case 122:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
}
    break;

  case 125:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setGeneralOtherResultName failed");
	}
    break;

  case 126:

    {	
		if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setGeneralOtherResultValue failed");
	}
    break;

  case 127:

    {	
		if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setGeneralOtherResultDescription failed");
	}
    break;

  case 148:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	}
    break;

  case 154:

    {	osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 156:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	}
    break;

  case 160:

    {	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 161:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 163:

    {	osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 165:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	}
    break;

  case 169:

    {	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setAvailableMemoryUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 170:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 172:

    {	osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 174:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	}
    break;

  case 178:

    {	if (parserData->unitAttribute != "terahertz" && 
			parserData->unitAttribute != "gigahertz" && 
			parserData->unitAttribute != "megahertz" && 
			parserData->unitAttribute != "kilohertz" && 
			parserData->unitAttribute != "hertz"     && 
			parserData->unitAttribute != "petaflops" && 
			parserData->unitAttribute != "teraflops" && 
			parserData->unitAttribute != "gigaflops" && 
			parserData->unitAttribute != "megaflops" && 
			parserData->unitAttribute != "kiloflops" && 
			parserData->unitAttribute != "flops" )
			osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
		osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 179:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 181:

    {	osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 183:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	}
    break;

  case 185:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 187:

    {	osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; }
    break;

  case 189:

    {	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	}
    break;

  case 190:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, "number of other system results cannot be negative");
	if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setNumberOfOtherSystemResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 191:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}
    break;

  case 192:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	}
    break;

  case 199:

    {	parserData->kounter++;
}
    break;

  case 200:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
}
    break;

  case 201:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
}
    break;

  case 204:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSystemOtherResultName failed");
	}
    break;

  case 205:

    {	
		if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSystemOtherResultValue failed");
	}
    break;

  case 206:

    {	
		if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSystemOtherResultDescription failed");
	}
    break;

  case 221:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	}
    break;

  case 227:

    {   parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (parserData->tempStr != "busy"                &&
			parserData->tempStr != "busyButAccepting"    &&
			parserData->tempStr != "idle"                &&
			parserData->tempStr != "idleButNotAccepting" &&
			parserData->tempStr != "noResponse"             )
			osrlerror(NULL, NULL, parserData, "current system state not recognized");
		if (osresult->setCurrentState(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setCurrentState failed");
		parserData->errorText = NULL;
	}
    break;

  case 229:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	}
    break;

  case 235:

    { osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; }
    break;

  case 237:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	}
    break;

  case 243:

    { osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; }
    break;

  case 245:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	}
    break;

  case 251:

    {osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 253:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	}
    break;

  case 259:

    {	if (osresult->setServiceUtilization( parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, "setServiceUtilization failed");
	parserData->errorText = NULL;
}
    break;

  case 261:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	}
    break;

  case 262:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, "number of other service results cannot be negative");
	if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfOtherServiceResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 263:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}
    break;

  case 264:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	}
    break;

  case 271:

    {	parserData->kounter++;
}
    break;

  case 272:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
}
    break;

  case 273:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
}
    break;

  case 276:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setServiceOtherResultName failed");
	}
    break;

  case 277:

    {	
		if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setServiceOtherResultValue failed");
	}
    break;

  case 278:

    {	
		if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setServiceOtherResultDescription failed");
	}
    break;

  case 298:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	}
    break;

  case 304:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (parserData->tempStr != "waiting"  &&
			parserData->tempStr != "running"  &&
			parserData->tempStr != "killed"   &&
			parserData->tempStr != "finished" &&
			parserData->tempStr != "unknown"     )
			osrlerror (NULL, NULL, parserData, "status of this job not recognized");
		if (osresult->setJobStatus(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setJobStatus failed");
		parserData->errorText = NULL;
	}
    break;

  case 306:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	}
    break;

  case 312:

    {osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 314:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	}
    break;

  case 320:

    {osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 322:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	}
    break;

  case 328:

    {osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;}
    break;

  case 330:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	}
    break;

  case 336:

    {osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;}
    break;

  case 338:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	}
    break;

  case 339:

    {	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	if (osresult->setNumberOfTimes(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setNumberOfTimes failed");
	parserData->numberOfTimes = parserData->tempInt;
	parserData->ivar = 0;
}
    break;

  case 340:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <time> element");
	}
    break;

  case 341:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, "fewer <time> elements than specified");
	}
    break;

  case 349:

    {	if (parserData->ivar >= parserData->numberOfTimes)
		osrlerror(NULL, NULL, parserData, "more <time> elements than specified");
	parserData->unitAttributePresent = false;
	parserData->typeAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->unitAttribute = "";
	parserData->typeAttribute = "";
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 352:

    {	if (parserData->unitAttribute != "tick"        &&
			parserData->unitAttribute != "millisecond" &&
			parserData->unitAttribute != "second"      &&
			parserData->unitAttribute != "minute"      &&
			parserData->unitAttribute != "hour"        &&
			parserData->unitAttribute != "day"         &&
			parserData->unitAttribute != "week"        &&
			parserData->unitAttribute != "month"       &&
			parserData->unitAttribute != "year"   )     
			osrlerror(NULL, NULL, parserData, "time unit not recognized");
	}
    break;

  case 353:

    {	if (parserData->typeAttribute != "cpuTime"     &&
			parserData->typeAttribute != "elapsedTime" &&
 			parserData->typeAttribute != "other"   )     
			osrlerror(NULL, NULL, parserData, "time type not recognized");
	}
    break;

  case 354:

    {	if (parserData->categoryAttribute != "total"          &&
			parserData->categoryAttribute != "input"          &&
			parserData->categoryAttribute != "preprocessing"  &&
			parserData->categoryAttribute != "optimization"   &&
			parserData->categoryAttribute != "postprocessing" &&
			parserData->categoryAttribute != "output"         &&
 			parserData->categoryAttribute != "other"   )
			osrlerror(NULL, NULL, parserData, "time category not recognized");
	}
    break;

  case 361:

    {	osresult->setTimingInformation(parserData->ivar, parserData->typeAttribute, parserData->categoryAttribute,
		parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue);       
	parserData->ivar++;
	parserData->timeType = "";
	parserData->timeCategory = "";
	parserData->timeUnit = "";
	parserData->timeDescription = "";      
}
    break;

  case 362:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); }
    break;

  case 363:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); }
    break;

  case 365:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	}
    break;

  case 369:

    {	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
		osresult->setUsedDiskSpaceUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 370:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 372:

    {	osresult->setUsedDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 374:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	}
    break;

  case 378:

    {	if (parserData->unitAttribute != "exabyte"  && 
			parserData->unitAttribute != "petabyte" && 
			parserData->unitAttribute != "terabyte" && 
			parserData->unitAttribute != "gigabyte" &&
			parserData->unitAttribute != "megabyte" && 
			parserData->unitAttribute != "kilobyte" && 
			parserData->unitAttribute != "byte")
			osrlerror(NULL, NULL, parserData, "usedDiskSpace unit not recognized");
		osresult->setUsedMemoryUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 379:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 381:

    {	osresult->setUsedMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 383:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	}
    break;

  case 387:

    {	if (parserData->unitAttribute != "terahertz" && 
			parserData->unitAttribute != "gigahertz" && 
			parserData->unitAttribute != "megahertz" && 
			parserData->unitAttribute != "kilohertz" && 
			parserData->unitAttribute != "hertz"     && 
			parserData->unitAttribute != "petaflops" && 
			parserData->unitAttribute != "teraflops" && 
			parserData->unitAttribute != "gigaflops" && 
			parserData->unitAttribute != "megaflops" && 
			parserData->unitAttribute != "kiloflops" && 
			parserData->unitAttribute != "flops" )
			osrlerror(NULL, NULL, parserData, "availableCPUSpeed unit not recognized");
		osresult->setUsedCPUSpeedUnit( parserData->unitAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 388:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 390:

    {	osresult->setUsedCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 392:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	}
    break;

  case 394:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 396:

    { osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; }
    break;

  case 398:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	}
    break;

  case 399:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, "number of other job results cannot be negative");
	if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setNumberOfOtherJobResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 400:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	}
    break;

  case 401:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	}
    break;

  case 408:

    {	parserData->kounter++;
}
    break;

  case 409:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
}
    break;

  case 410:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
}
    break;

  case 413:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setJobOtherResultName failed");
	}
    break;

  case 414:

    {	
		if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setJobOtherResultValue failed");
	}
    break;

  case 415:

    {	
		if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setJobOtherResultDescription failed");
	}
    break;

  case 420:

    {	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
}
    break;

  case 421:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, "numberOfSolutions was never set");
}
    break;

  case 424:

    {
		parserData->numberOfSolutions = parserData->tempInt; 
		if (osresult->setSolutionNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionNumber failed");
		parserData->solutionIdx = 0;
	}
    break;

  case 425:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osresult->setVariableNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setVariableNumber failed");
	}
    break;

  case 426:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osresult->setConstraintNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setConstraintNumber failed");
	}
    break;

  case 427:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osresult->setObjectiveNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setObjectiveNumber failed");
	}
    break;

  case 428:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solution> element");
	}
    break;

  case 429:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, "fewer <solution> elements than specified");
	}
    break;

  case 437:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
}
    break;

  case 443:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
  	if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, "setSolutionTargetObjectiveIdx failed");
 }
    break;

  case 444:

    {	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr == "true")
	{  	if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, true) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionWeightedObjectives failed");
	}
	else if (parserData->tempStr == "false")
	{  	if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, false) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionWeightedObjectives failed");
	}
	else
		osrlerror(NULL, NULL, parserData, "weightedobjectives must be true or false");
}
    break;

  case 445:

    {
		parserData->solutionIdx++;
	}
    break;

  case 447:

    {	parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
	}
    break;

  case 448:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
	}
    break;

  case 451:

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
		if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionStatusType failed");
	}
    break;

  case 452:

    {   if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionStatusDescription failed");
	}
    break;

  case 453:

    {	if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, "setNumberOfSolutionSubstatuses failed");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	}
    break;

  case 454:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	}
    break;

  case 455:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	}
    break;

  case 462:

    {	parserData->kounter++; }
    break;

  case 463:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
}
    break;

  case 464:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
}
    break;

  case 467:

    {	
		if (parserData->typeAttribute != "stoppedByLimit"  &&
			parserData->typeAttribute != "stoppedByBounds" &&
			parserData->typeAttribute != "other" )
		osrlerror(NULL, NULL, parserData, "substatus type attribute has bad value");
		if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
											   parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionSubstatusType failed");
	}
    break;

  case 468:

    {	
		if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
													  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolutionSubstatusDescription failed");
	}
    break;

  case 479:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
		osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
		parserData->errorText = NULL;
	}
    break;

  case 482:

    {	parserData->numberOfOtherVariableResults = 0; }
    break;

  case 484:

    {	
	if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, 
												  parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfOtherVariableResults failed");
	parserData->numberOfOtherVariableResults = parserData->tempInt;
	parserData->iOther = 0;
}
    break;

  case 493:

    {
	if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfVarValues failed");
	parserData->kounter = 0;
}
    break;

  case 494:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	}
    break;

  case 495:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	}
    break;

  case 502:

    {	if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, "setVarValue failed");
	parserData->kounter++;
}
    break;

  case 503:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
}
    break;

  case 504:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); }
    break;

  case 506:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); }
    break;

  case 507:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); }
    break;

  case 511:

    {
	if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfVarValuesString failed");
	parserData->kounter = 0;
}
    break;

  case 512:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	}
    break;

  case 513:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	}
    break;

  case 520:

    {
	if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 				parserData->idx,         parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setVarValueString failed");
	parserData->kounter++;
}
    break;

  case 521:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
}
    break;

  case 522:

    { parserData->idx = (yyvsp[(3) - (4)].ival); }
    break;

  case 523:

    {parserData->tempStr = "";}
    break;

  case 528:

    {parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));}
    break;

  case 532:

    {
	if (osresult->setNumberOfBasisVar(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfBasisVar failed");
	parserData->kounter = 0;
}
    break;

  case 533:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	}
    break;

  case 534:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	}
    break;

  case 542:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
}
    break;

  case 543:

    { parserData->idx = (yyvsp[(3) - (4)].ival); }
    break;

  case 544:

    {   parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "unknown"  &&
		parserData->tempStr != "basic"    &&
		parserData->tempStr != "atLower"  &&
		parserData->tempStr != "atUpper"  &&
		parserData->tempStr != "superBasic" )
		osrlerror(NULL, NULL, parserData, "unrecognized basis status");
	if (osresult->setBasisVar(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setBasisVar failed");
	parserData->kounter++;
}
    break;

  case 547:

    { 	 
		parserData->iOther++;
	}
    break;

  case 548:

    {
	if (parserData->iOther >= parserData->numberOfOtherVariableResults)
		osrlerror(NULL, NULL, parserData, "more <otherVariableResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
}
    break;

  case 549:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfVar attribute"); 
	}
    break;

  case 552:

    {	if (parserData->numberAttributePresent)
			osrlerror(NULL, NULL, parserData, "numberOfVar attribute previously set");
		parserData->numberAttributePresent = true;
	 	if (osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfVar) == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultNumberOfVar failed");
		parserData->kounter = 0;
	}
    break;

  case 553:

    {	
	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 												  parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultValue failed");
    }
    break;

  case 554:

    {	
	 	if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultName failed");
    }
    break;

  case 555:

    {	
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultDescription failed");
    }
    break;

  case 564:

    { 	
	parserData->kounter++;
}
    break;

  case 566:

    {	
 	if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 											   parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultVarIdx failed");
}
    break;

  case 572:

    {	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, "setOtherVariableResultVar failed");
	}
    break;

  case 575:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
}
    break;

  case 577:

    {
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
    if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, 
												   parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
}
    break;

  case 586:

    {
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
}
    break;

  case 587:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <obj> element");
	}
    break;

  case 588:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, "fewer <obj> elements than specified");
	}
    break;

  case 595:

    {	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, "setObjValue failed");
	parserData->kounter++;
}
    break;

  case 596:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, "more <obj> elements than specified");
	parserData->idx = -1;
}
    break;

  case 598:

    { parserData->idx = (yyvsp[(3) - (4)].ival); }
    break;

  case 600:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); }
    break;

  case 601:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); }
    break;

  case 604:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 605:

    {
	if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
		osrlerror(NULL, NULL, parserData, "more <otherObjectiveResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
}
    break;

  case 606:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfObj attribute"); 
	}
    break;

  case 609:

    {	if (parserData->numberAttributePresent)
			osrlerror(NULL, NULL, parserData, "numberOfObj attribute previously set");
		parserData->numberAttributePresent = true;
 		if (osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, 
 						                                 parserData->iOther, 
 						                                 parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultNumberOfObj failed");
		parserData->kounter = 0;
	}
    break;

  case 610:

    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultValue failed");
    }
    break;

  case 611:

    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultName failed");
    }
    break;

  case 612:

    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultDescription failed");
    }
    break;

  case 621:

    {  
	parserData->kounter++;
}
    break;

  case 623:

    {	if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultObjIdx failed");
}
    break;

  case 629:

    {	if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setOtherObjectiveResultObj failed");
	}
    break;

  case 632:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
}
    break;

  case 634:

    {
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
}
    break;

  case 642:

    {	parserData->numberAttributePresent = false; }
    break;

  case 643:

    {
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
}
    break;

  case 644:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <con> element");
	}
    break;

  case 645:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, "fewer <con> elements than specified");
	}
    break;

  case 652:

    {	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, "setDualValue failed");
	parserData->kounter++;
}
    break;

  case 653:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, "more <con> elements than specified");
}
    break;

  case 654:

    { parserData->idx = (yyvsp[(3) - (4)].ival); }
    break;

  case 655:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); }
    break;

  case 656:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); }
    break;

  case 659:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 660:

    {
	if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
		osrlerror(NULL, NULL, parserData, "more <otherConstraintResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
}
    break;

  case 661:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfCon attribute"); 
	}
    break;

  case 664:

    {	if (parserData->numberAttributePresent)
			osrlerror(NULL, NULL, parserData, "numberOfCon attribute previously set");
		parserData->numberAttributePresent = true;
 		if (osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, 
 							                              parserData->iOther, 
 							                              parserData->numberOfCon) == false)
			osrlerror(NULL, NULL, parserData, "setOtherConstraintResultNumberOfCon failed");
		parserData->kounter = 0;
	}
    break;

  case 665:

    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherConstraintResultValue failed");
    }
    break;

  case 666:

    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherConstraintResultName failed");
    }
    break;

  case 667:

    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherConstraintResultDescription failed");
    }
    break;

  case 676:

    { 	
	parserData->kounter++;
}
    break;

  case 678:

    {	
 	if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, "setOtherConstraintResultConIdx failed");
}
    break;

  case 684:

    {	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, "setOtherConstraintResultCon failed");
	}
    break;

  case 687:

    {
	parserData->numberOf = 0; 
}
    break;

  case 688:

    {	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
}
    break;

  case 689:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <otherSolutionResult> element");
	}
    break;

  case 690:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <otherSolutionResult> elements than specified");
	}
    break;

  case 697:

    {	parserData->iOther++;
}
    break;

  case 698:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
}
    break;

  case 699:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have numberOfItems attribute");
}
    break;

  case 702:

    {	
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherSolutionResultName failed");
	}
    break;

  case 703:

    {	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setOtherSolutionResultCategory failed");
	}
    break;

  case 704:

    {	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, "setOtherSolutionResultDescription failed");
	}
    break;

  case 705:

    {	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	}
    break;

  case 706:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	}
    break;

  case 707:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	}
    break;

  case 714:

    {	parserData->kounter++;
}
    break;

  case 715:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
}
    break;

  case 720:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
											 parserData->kounter, parserData->itemContent) 
											     == false)
			osrlerror(NULL, NULL, parserData, "setOtherSolutionResultItem failed");
}
    break;

  case 723:

    {
	parserData->numberOf = 0; 
}
    break;

  case 724:

    {	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
}
    break;

  case 725:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solverOutput> element");
	}
    break;

  case 726:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <solverOutput> elements than specified");
	}
    break;

  case 733:

    {	parserData->iOther++;
}
    break;

  case 734:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <solverOutput> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
}
    break;

  case 735:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have numberOfItems attribute");
}
    break;

  case 738:

    {	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolverOutputName failed");
	}
    break;

  case 739:

    {	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolverOutputCategory failed");
	}
    break;

  case 740:

    {	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, "setSolverOutputDescription failed");
	}
    break;

  case 741:

    {	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	}
    break;

  case 742:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	}
    break;

  case 743:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	}
    break;

  case 750:

    {	parserData->kounter++;
}
    break;

  case 751:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
}
    break;

  case 755:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, "setSolverOutputItem failed");
}
    break;

  case 756:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		}
    break;

  case 759:

    { parserData->categoryAttribute = ""; }
    break;

  case 760:

    { parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); }
    break;

  case 761:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		}
    break;

  case 764:

    { parserData->descriptionAttribute = ""; }
    break;

  case 765:

    { parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 766:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		}
    break;

  case 769:

    { parserData->nameAttribute = ""; }
    break;

  case 770:

    { parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 771:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		}
    break;

  case 774:

    { parserData->typeAttribute = ""; }
    break;

  case 775:

    { parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 776:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		}
    break;

  case 779:

    { parserData->unitAttribute = ""; }
    break;

  case 780:

    { parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 781:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		}
    break;

  case 784:

    { parserData->valueAttribute = ""; }
    break;

  case 785:

    { parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 786:

    {
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 787:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 788:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 789:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 790:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 791:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other variable results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 792:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other objective results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 793:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other constraint results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 794:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solution results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 795:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 796:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 797:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 798:

    {
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 799:

    {	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 800:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solver outputs cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 801:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 802:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 803:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 804:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); }
    break;

  case 805:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); }
    break;

  case 806:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].dval)); }
    break;



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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, osresult, parserData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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


