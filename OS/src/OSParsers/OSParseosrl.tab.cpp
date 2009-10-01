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
#define YYLAST   843

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  306
/* YYNRULES -- Number of rules.  */
#define YYNRULES  553
/* YYNRULES -- Number of states.  */
#define YYNSTATES  973

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
      53,    54,    57,    59,    61,    63,    67,    69,    73,    75,
      80,    82,    84,    87,    89,    93,    95,    98,   102,   103,
     106,   108,   110,   114,   118,   120,   122,   125,   127,   131,
     136,   140,   143,   148,   152,   155,   160,   164,   167,   172,
     176,   179,   184,   188,   191,   196,   200,   203,   208,   212,
     215,   219,   224,   226,   228,   231,   233,   237,   239,   242,
     246,   247,   250,   252,   254,   256,   260,   264,   268,   271,
     273,   274,   277,   287,   288,   293,   297,   300,   306,   307,
     310,   312,   314,   318,   322,   324,   326,   332,   333,   336,
     338,   340,   344,   348,   350,   352,   358,   359,   362,   364,
     366,   370,   374,   376,   378,   384,   385,   388,   392,   394,
     396,   397,   401,   406,   408,   410,   413,   415,   419,   421,
     424,   428,   429,   432,   434,   436,   438,   442,   446,   450,
     453,   455,   456,   459,   469,   470,   475,   479,   482,   483,
     488,   492,   495,   496,   501,   505,   508,   509,   514,   518,
     521,   522,   527,   531,   534,   535,   539,   544,   546,   548,
     551,   553,   557,   559,   562,   566,   567,   570,   572,   574,
     576,   580,   584,   588,   591,   593,   594,   597,   602,   603,
     606,   608,   610,   612,   614,   616,   618,   620,   622,   624,
     626,   628,   633,   637,   640,   645,   649,   652,   657,   661,
     664,   669,   673,   676,   681,   685,   688,   692,   697,   699,
     703,   704,   707,   711,   712,   715,   717,   719,   721,   723,
     727,   729,   733,   735,   739,   741,   745,   747,   749,   751,
     754,   756,   760,   761,   763,   765,   771,   772,   775,   777,
     779,   783,   787,   789,   791,   797,   798,   801,   805,   807,
     809,   815,   816,   819,   821,   823,   827,   831,   833,   835,
     841,   842,   845,   847,   849,   853,   857,   859,   861,   865,
     870,   872,   874,   877,   879,   883,   885,   888,   892,   893,
     896,   898,   900,   902,   906,   910,   914,   917,   919,   920,
     924,   925,   928,   931,   934,   937,   940,   944,   948,   952,
     956,   960,   962,   965,   966,   969,   973,   975,   976,   979,
     981,   983,   988,   993,  1002,  1007,  1011,  1013,  1016,  1020,
    1022,  1026,  1028,  1029,  1033,  1036,  1037,  1041,  1042,  1047,
    1049,  1051,  1053,  1060,  1061,  1067,  1072,  1073,  1076,  1082,
    1087,  1089,  1091,  1092,  1098,  1103,  1104,  1107,  1113,  1118,
    1120,  1122,  1123,  1129,  1134,  1135,  1138,  1144,  1149,  1150,
    1153,  1154,  1159,  1161,  1162,  1165,  1167,  1169,  1171,  1173,
    1178,  1180,  1184,  1186,  1190,  1194,  1196,  1200,  1201,  1204,
    1210,  1212,  1217,  1218,  1222,  1223,  1228,  1230,  1232,  1234,
    1239,  1240,  1246,  1251,  1252,  1255,  1261,  1266,  1268,  1270,
    1271,  1274,  1278,  1280,  1281,  1284,  1286,  1288,  1290,  1292,
    1297,  1299,  1303,  1305,  1309,  1313,  1315,  1319,  1320,  1323,
    1329,  1331,  1336,  1337,  1341,  1342,  1347,  1349,  1351,  1353,
    1358,  1359,  1365,  1370,  1371,  1374,  1380,  1385,  1387,  1389,
    1390,  1393,  1397,  1399,  1400,  1403,  1405,  1407,  1409,  1411,
    1416,  1418,  1422,  1424,  1428,  1432,  1434,  1438,  1439,  1442,
    1448,  1450,  1455,  1456,  1462,  1463,  1469,  1470,  1473,  1479,
    1480,  1481,  1485,  1487,  1489,  1491,  1493,  1498,  1500,  1504,
    1508,  1510,  1514,  1516,  1517,  1520,  1522,  1524,  1526,  1528,
    1529,  1534,  1536,  1537,  1541,  1546,  1548,  1552,  1553,  1556,
    1562,  1563,  1564,  1568,  1570,  1572,  1574,  1576,  1581,  1583,
    1587,  1591,  1593,  1597,  1599,  1600,  1603,  1605,  1607,  1609,
    1611,  1612,  1617,  1619,  1621,  1624,  1626,  1628,  1630,  1632,
    1634,  1636,  1638,  1639
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   213,   250,   269,   327,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   193,    -1,   194,    -1,   195,    -1,   196,
      -1,   197,    -1,   198,    -1,   199,    -1,   200,    -1,    88,
     176,   181,    -1,    -1,   176,   177,    -1,   178,    -1,   179,
      -1,   180,    -1,    36,     3,   471,    -1,    37,    -1,    32,
       3,   471,    -1,    33,    -1,    24,     8,     6,     8,    -1,
     182,    -1,   183,    -1,    10,    89,    -1,    11,    -1,    10,
     184,    89,    -1,   185,    -1,   184,   185,    -1,   134,   186,
     190,    -1,    -1,   186,   187,    -1,   188,    -1,   189,    -1,
      34,     3,     8,    -1,    32,     3,     8,    -1,   191,    -1,
     192,    -1,    10,   135,    -1,    11,    -1,    10,     4,   135,
      -1,    96,    10,     4,    97,    -1,    96,    10,    97,    -1,
      96,    11,    -1,   120,    10,     4,   121,    -1,   120,    10,
     121,    -1,   120,    11,    -1,   118,    10,     4,   119,    -1,
     118,    10,   119,    -1,   118,    11,    -1,    92,    10,     4,
      93,    -1,    92,    10,    93,    -1,    92,    11,    -1,    94,
      10,     4,    95,    -1,    94,    10,    95,    -1,    94,    11,
      -1,   126,    10,     4,   127,    -1,   126,    10,   127,    -1,
     126,    11,    -1,   142,    10,     4,   143,    -1,   142,    10,
     143,    -1,   142,    11,    -1,   108,   201,   202,    -1,    19,
     471,     6,   471,    -1,   203,    -1,   204,    -1,    10,   109,
      -1,    11,    -1,    10,   205,   109,    -1,   206,    -1,   205,
     206,    -1,   106,   207,   212,    -1,    -1,   207,   208,    -1,
     209,    -1,   210,    -1,   211,    -1,    34,     3,   471,    -1,
      40,     3,   471,    -1,    32,     3,   471,    -1,    10,   107,
      -1,    11,    -1,    -1,    50,    11,    -1,    50,    10,   214,
     215,   221,   227,   233,   237,    51,    -1,    -1,   136,    10,
       4,   137,    -1,   136,    10,   137,    -1,   136,    11,    -1,
      68,   216,    10,   220,    69,    -1,    -1,   216,   217,    -1,
     218,    -1,   219,    -1,    38,     3,   471,    -1,    32,     3,
     471,    -1,     6,    -1,     7,    -1,    70,   222,    10,   226,
      71,    -1,    -1,   222,   223,    -1,   224,    -1,   225,    -1,
      38,     3,   471,    -1,    32,     3,   471,    -1,     6,    -1,
       7,    -1,    66,   228,    10,   232,    67,    -1,    -1,   228,
     229,    -1,   230,    -1,   231,    -1,    38,     3,   471,    -1,
      32,     3,   471,    -1,     6,    -1,     7,    -1,    64,   234,
      10,   236,    65,    -1,    -1,   234,   235,    -1,    32,     3,
     471,    -1,     6,    -1,     7,    -1,    -1,   108,   238,   239,
      -1,    19,   471,     6,   471,    -1,   240,    -1,   241,    -1,
      10,   109,    -1,    11,    -1,    10,   242,   109,    -1,   243,
      -1,   242,   243,    -1,   106,   244,   249,    -1,    -1,   244,
     245,    -1,   246,    -1,   247,    -1,   248,    -1,    34,     3,
     471,    -1,    40,     3,   471,    -1,    32,     3,   471,    -1,
      10,   107,    -1,    11,    -1,    -1,    52,    11,    -1,    52,
      10,   251,   252,   253,   254,   255,   256,    53,    -1,    -1,
      82,    10,     4,    83,    -1,    82,    10,    83,    -1,    82,
      11,    -1,    -1,    80,    10,     6,    81,    -1,    80,    10,
      81,    -1,    80,    11,    -1,    -1,   146,    10,     6,   147,
      -1,   146,    10,   147,    -1,   146,    11,    -1,    -1,   140,
      10,     4,   141,    -1,   140,    10,   141,    -1,   140,    11,
      -1,    -1,   122,    10,   470,   123,    -1,   122,    10,   123,
      -1,   122,    11,    -1,    -1,   108,   257,   258,    -1,    19,
     471,     6,   471,    -1,   259,    -1,   260,    -1,    10,   109,
      -1,    11,    -1,    10,   261,   109,    -1,   262,    -1,   261,
     262,    -1,   106,   263,   268,    -1,    -1,   263,   264,    -1,
     265,    -1,   266,    -1,   267,    -1,    34,     3,   471,    -1,
      40,     3,   471,    -1,    32,     3,   471,    -1,    10,   107,
      -1,    11,    -1,    -1,    54,    11,    -1,    54,    10,   270,
      55,    -1,    -1,   270,   271,    -1,   272,    -1,   273,    -1,
     274,    -1,   275,    -1,   276,    -1,   277,    -1,   292,    -1,
     298,    -1,   302,    -1,   308,    -1,   314,    -1,   130,    10,
       4,   131,    -1,   130,    10,   131,    -1,   130,    11,    -1,
     132,    10,     4,   133,    -1,   132,    10,   133,    -1,   132,
      11,    -1,   116,    10,     4,   117,    -1,   116,    10,   117,
      -1,   116,    11,    -1,    62,    10,     4,    63,    -1,    62,
      10,    63,    -1,    62,    11,    -1,    86,    10,     4,    87,
      -1,    86,    10,    87,    -1,    86,    11,    -1,   144,   278,
     279,    -1,    25,     8,     6,     8,    -1,    11,    -1,    10,
     280,   145,    -1,    -1,   280,   281,    -1,   138,   282,   288,
      -1,    -1,   282,   283,    -1,   284,    -1,   285,    -1,   286,
      -1,   287,    -1,    36,     3,     8,    -1,    37,    -1,    30,
       3,     8,    -1,    31,    -1,    38,     3,     8,    -1,    39,
      -1,    32,     3,     8,    -1,    33,    -1,   289,    -1,   290,
      -1,    10,   139,    -1,    11,    -1,    10,   291,   139,    -1,
      -1,     7,    -1,     6,    -1,   150,   293,    10,   297,   151,
      -1,    -1,   293,   294,    -1,   295,    -1,   296,    -1,    38,
       3,   471,    -1,    32,     3,   471,    -1,     6,    -1,     7,
      -1,   148,   299,    10,   301,   149,    -1,    -1,   299,   300,
      -1,    32,     3,   471,    -1,     6,    -1,     7,    -1,   152,
     303,    10,   307,   153,    -1,    -1,   303,   304,    -1,   305,
      -1,   306,    -1,    38,     3,   471,    -1,    32,     3,   471,
      -1,     6,    -1,     7,    -1,   154,   309,    10,   313,   155,
      -1,    -1,   309,   310,    -1,   311,    -1,   312,    -1,    38,
       3,   471,    -1,    32,     3,   471,    -1,     6,    -1,     7,
      -1,   108,   315,   316,    -1,    19,   471,     6,   471,    -1,
     317,    -1,   318,    -1,    10,   109,    -1,    11,    -1,    10,
     319,   109,    -1,   320,    -1,   319,   320,    -1,   106,   321,
     326,    -1,    -1,   321,   322,    -1,   323,    -1,   324,    -1,
     325,    -1,    34,     3,   471,    -1,    40,     3,   471,    -1,
      32,     3,   471,    -1,    10,   107,    -1,    11,    -1,    -1,
      56,   328,   334,    -1,    -1,   328,   329,    -1,   330,   471,
      -1,   331,   471,    -1,   332,   471,    -1,   333,   471,    -1,
      22,   471,     6,    -1,    27,   471,     6,    -1,    13,   471,
       6,    -1,    16,   471,     6,    -1,    10,   335,    57,    -1,
      11,    -1,   336,   453,    -1,    -1,   336,   337,    -1,   338,
     339,   343,    -1,   124,    -1,    -1,   339,   340,    -1,   341,
      -1,   342,    -1,    28,   471,     6,   471,    -1,    42,   471,
       3,   471,    -1,    10,   344,   347,   348,   385,   410,   435,
     452,    -1,   130,   345,    10,   131,    -1,   130,   345,    11,
      -1,   346,    -1,   345,   346,    -1,    36,     3,   471,    -1,
      37,    -1,    32,     3,   471,    -1,    33,    -1,    -1,    96,
       4,    97,    -1,    96,    97,    -1,    -1,   162,   349,   350,
      -1,    -1,    21,   471,     6,   471,    -1,   351,    -1,   352,
      -1,    11,    -1,    10,   353,   359,   365,   370,   163,    -1,
      -1,   156,   354,    10,   355,   157,    -1,    26,   471,     6,
     471,    -1,    -1,   355,   356,    -1,   160,   357,    10,   358,
     161,    -1,    29,   471,     6,   471,    -1,     6,    -1,     7,
      -1,    -1,   158,   360,    10,   361,   159,    -1,    26,   471,
       6,   471,    -1,    -1,   361,   362,    -1,   160,   363,    10,
     364,   161,    -1,    29,   471,     6,   471,    -1,     6,    -1,
       7,    -1,    -1,    72,   366,    10,   367,    73,    -1,    26,
     471,     6,   471,    -1,    -1,   367,   368,    -1,   160,   369,
      10,     4,   161,    -1,    29,   471,     6,   471,    -1,    -1,
     370,   371,    -1,    -1,   373,   374,   372,   380,    -1,   106,
      -1,    -1,   374,   375,    -1,   376,    -1,   377,    -1,   378,
      -1,   379,    -1,    26,   471,     6,   471,    -1,    41,    -1,
      40,     3,   471,    -1,    35,    -1,    34,     3,   471,    -1,
      32,     3,   471,    -1,    11,    -1,    10,   381,   107,    -1,
      -1,   381,   382,    -1,   383,   384,    10,   472,   161,    -1,
     160,    -1,    29,   471,     6,   471,    -1,    -1,   100,   386,
     387,    -1,    -1,    18,   471,     6,   471,    -1,   388,    -1,
     389,    -1,    11,    -1,    10,   390,   396,   101,    -1,    -1,
     156,   391,    10,   392,   157,    -1,    15,   471,     6,   471,
      -1,    -1,   392,   393,    -1,    98,   394,    10,   395,    99,
      -1,    29,   471,     6,   471,    -1,     6,    -1,     7,    -1,
      -1,   396,   397,    -1,   398,   399,   405,    -1,   106,    -1,
      -1,   399,   400,    -1,   401,    -1,   402,    -1,   403,    -1,
     404,    -1,    15,   471,     6,   471,    -1,    41,    -1,    40,
       3,   471,    -1,    35,    -1,    34,     3,   471,    -1,    32,
       3,   471,    -1,    11,    -1,    10,   406,   107,    -1,    -1,
     406,   407,    -1,   408,   409,    10,   472,    99,    -1,    98,
      -1,    29,   471,     6,   471,    -1,    -1,    78,   411,   412,
      -1,    -1,    17,   471,     6,   471,    -1,   413,    -1,   414,
      -1,    11,    -1,    10,   415,   421,    79,    -1,    -1,    84,
     416,    10,   417,    85,    -1,    12,   471,     6,   471,    -1,
      -1,   417,   418,    -1,    76,   419,    10,   420,    77,    -1,
      29,   471,     6,   471,    -1,     7,    -1,     6,    -1,    -1,
     421,   422,    -1,   423,   424,   430,    -1,   106,    -1,    -1,
     424,   425,    -1,   426,    -1,   427,    -1,   428,    -1,   429,
      -1,    12,   471,     6,   471,    -1,    41,    -1,    40,     3,
     471,    -1,    35,    -1,    34,     3,   471,    -1,    32,     3,
     471,    -1,    11,    -1,    10,   431,   107,    -1,    -1,   431,
     432,    -1,   433,   434,    10,   472,    77,    -1,    76,    -1,
      29,   471,     6,   471,    -1,    -1,   112,   436,    10,   438,
     113,    -1,    -1,    20,     8,     6,   437,     8,    -1,    -1,
     438,   439,    -1,   110,   440,    10,   447,   111,    -1,    -1,
      -1,   440,   441,   442,    -1,   443,    -1,   444,    -1,   445,
      -1,   446,    -1,    14,     8,     6,     8,    -1,    35,    -1,
      34,     3,   471,    -1,    30,     3,     8,    -1,    31,    -1,
      32,     3,     8,    -1,    33,    -1,    -1,   447,   448,    -1,
     449,    -1,   450,    -1,    60,    -1,    61,    -1,    -1,    58,
       5,   451,    59,    -1,   125,    -1,    -1,   114,   454,   455,
      -1,    23,   471,     6,   471,    -1,    11,    -1,    10,   456,
     115,    -1,    -1,   456,   457,    -1,   128,   458,    10,   465,
     129,    -1,    -1,    -1,   458,   459,   460,    -1,   461,    -1,
     462,    -1,   463,    -1,   464,    -1,    14,     8,     6,     8,
      -1,    35,    -1,    34,     3,     8,    -1,    30,     3,     8,
      -1,    31,    -1,    32,     3,     8,    -1,    33,    -1,    -1,
     465,   466,    -1,   467,    -1,   468,    -1,    60,    -1,    61,
      -1,    -1,    58,     5,   469,    59,    -1,     6,    -1,     7,
      -1,   474,     8,    -1,     4,    -1,     6,    -1,     7,    -1,
     165,    -1,   166,    -1,   167,    -1,   168,    -1,    -1,   474,
     473,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   166,   167,   169,   169,   170,   172,   172,
     174,   174,   174,   174,   175,   175,   175,   175,   175,   178,
     180,   180,   182,   188,   194,   198,   199,   201,   202,   204,
     216,   216,   218,   218,   220,   224,   224,   226,   228,   228,
     230,   230,   232,   236,   240,   240,   242,   242,   244,   249,
     250,   251,   255,   256,   257,   262,   263,   264,   267,   268,
     269,   272,   273,   274,   277,   278,   279,   282,   283,   284,
     286,   288,   290,   290,   292,   292,   294,   296,   296,   298,
     300,   300,   302,   302,   302,   304,   306,   308,   310,   310,
     314,   314,   315,   318,   319,   320,   321,   323,   326,   326,
     328,   328,   330,   332,   335,   336,   338,   341,   341,   343,
     343,   345,   347,   350,   351,   353,   356,   356,   358,   358,
     360,   362,   365,   366,   369,   372,   372,   374,   377,   378,
     381,   381,   383,   385,   385,   387,   387,   389,   391,   391,
     393,   395,   395,   397,   397,   397,   399,   401,   403,   405,
     405,   409,   409,   410,   413,   414,   415,   416,   418,   419,
     420,   421,   423,   424,   425,   426,   428,   429,   430,   431,
     433,   434,   435,   436,   439,   439,   441,   443,   443,   445,
     445,   447,   449,   449,   451,   453,   453,   455,   455,   455,
     457,   459,   461,   463,   463,   466,   466,   467,   469,   469,
     471,   471,   471,   471,   471,   472,   472,   472,   472,   472,
     472,   475,   476,   477,   480,   481,   482,   485,   486,   487,
     490,   491,   492,   495,   496,   497,   500,   502,   508,   508,
     510,   510,   512,   514,   514,   516,   516,   516,   516,   518,
     519,   521,   522,   524,   525,   527,   528,   530,   530,   532,
     532,   534,   545,   549,   550,   553,   556,   556,   558,   558,
     560,   562,   565,   566,   569,   572,   572,   574,   577,   578,
     581,   584,   584,   586,   586,   588,   590,   593,   594,   596,
     599,   599,   601,   601,   603,   605,   608,   609,   613,   615,
     617,   617,   619,   619,   621,   623,   623,   625,   627,   627,
     629,   629,   629,   631,   633,   635,   637,   637,   641,   641,
     643,   643,   645,   646,   647,   648,   652,   653,   654,   655,
     658,   658,   660,   662,   662,   664,   671,   677,   677,   679,
     679,   681,   688,   691,   694,   695,   698,   699,   701,   702,
     703,   704,   706,   707,   711,   717,   718,   720,   721,   731,
     731,   733,   735,   737,   737,   747,   754,   754,   756,   758,
     761,   765,   771,   772,   782,   789,   789,   791,   793,   796,
     801,   807,   807,   817,   824,   824,   826,   828,   833,   833,
     836,   835,   842,   850,   850,   852,   852,   852,   852,   854,
     863,   866,   872,   878,   884,   890,   891,   907,   907,   909,
     923,   928,   932,   933,   935,   936,   946,   946,   948,   950,
     952,   952,   962,   966,   966,   968,   970,   973,   977,   983,
     983,   985,   988,   996,   997,   999,   999,   999,   999,  1001,
    1010,  1013,  1019,  1025,  1031,  1038,  1039,  1061,  1061,  1063,
    1078,  1083,  1086,  1087,  1089,  1090,  1100,  1100,  1102,  1104,
    1107,  1107,  1118,  1123,  1123,  1125,  1127,  1130,  1134,  1140,
    1140,  1142,  1145,  1147,  1147,  1149,  1149,  1149,  1149,  1151,
    1154,  1157,  1163,  1169,  1175,  1181,  1182,  1185,  1185,  1187,
    1203,  1208,  1212,  1213,  1220,  1219,  1235,  1235,  1237,  1245,
    1246,  1246,  1250,  1250,  1250,  1250,  1252,  1265,  1271,  1279,
    1282,  1285,  1288,  1290,  1291,  1294,  1299,  1306,  1306,  1309,
    1308,  1314,  1324,  1324,  1326,  1328,  1328,  1330,  1330,  1332,
    1340,  1342,  1341,  1346,  1346,  1346,  1346,  1348,  1363,  1370,
    1379,  1385,  1388,  1394,  1396,  1397,  1399,  1404,  1410,  1410,
    1413,  1412,  1418,  1419,  1421,  1424,  1425,  1426,  1430,  1431,
    1432,  1433,  1435,  1436
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
  "generalChild", "generalStatus", "generalStatusAttList",
  "generalStatusATT", "generalStatusTypeATT",
  "generalStatusDescriptionATT", "generalStatusNumberOfATT",
  "generalStatusContent", "generalStatusEmpty", "generalStatusBody",
  "generalSubstatusSEQ", "generalSubstatus", "generalSubstatusAttList",
  "generalSubstatusATT", "generalSubstatusNameATT",
  "generalSubstatusDescriptionATT", "restOfGeneralSubstatus",
  "generalSubstatusEmpty", "generalSubstatusContent", "generalMessage",
  "serviceURI", "serviceName", "instanceName", "jobID", "solverInvoked",
  "timeStamp", "generalOtherResults", "generalOtherResultsAttList",
  "generalOtherResultsBody", "generalOtherResultsEmpty",
  "generalOtherResultsContent", "generalOtherResultList",
  "generalOtherResult", "generalOtherAttList", "generalOtherAtt",
  "generalOtherNameATT", "generalOtherValueATT",
  "generalOtherDescriptionATT", "generalOtherEnd", "systemElement",
  "systemInformation", "availableDiskSpace", "availableDiskSpaceAttList",
  "availableDiskSpaceAtt", "availableDiskSpaceUnitATT",
  "availableDiskSpaceDescriptionATT", "availableDiskSpaceValue",
  "availableMemory", "availableMemoryAttList", "availableMemoryAtt",
  "availableMemoryUnitATT", "availableMemoryDescriptionATT",
  "availableMemoryValue", "availableCPUSpeed", "availableCPUSpeedAttList",
  "availableCPUSpeedAtt", "availableCPUSpeedUnitATT",
  "availableCPUSpeedDescriptionATT", "availableCPUSpeedValue",
  "availableCPUNumber", "availableCPUNumberAttList",
  "availableCPUNumberDescriptionATT", "availableCPUNumberValue",
  "systemOtherResults", "systemOtherResultsAttList",
  "systemOtherResultsBody", "systemOtherResultsEmpty",
  "systemOtherResultsContent", "systemOtherResultList",
  "systemOtherResult", "systemOtherAttList", "systemOtherAtt",
  "systemOtherNameATT", "systemOtherValueATT", "systemOtherDescriptionATT",
  "systemOtherEnd", "serviceElement", "currrentState", "currentJobCount",
  "totalJobsSoFar", "timeServiceStarted", "serviceUtilization",
  "serviceOtherResults", "serviceOtherResultsAttList",
  "serviceOtherResultsBody", "serviceOtherResultsEmpty",
  "serviceOtherResultsContent", "serviceOtherResultList",
  "serviceOtherResult", "serviceOtherAttList", "serviceOtherAtt",
  "serviceOtherNameATT", "serviceOtherValueATT",
  "serviceOtherDescriptionATT", "serviceOtherEnd", "jobElement",
  "jobChildren", "jobChild", "status", "submitTime", "scheduledStartTime",
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
  "anotherSolutionStatusATT", "solutionStatusATT", "solutionMessage",
  "variables", "numberOfOtherVariableResults", "variablesBody",
  "variablesEmpty", "variablesContent", "variableValues", "numberOfVarATT",
  "varValueList", "varValue", "varIdxATT", "varVal",
  "variableValuesString", "numberOfVarStringATT", "varValueStringList",
  "varValueString", "varStrIdxATT", "varStr", "basisStatus",
  "numberOfBasisVarATT", "basisVarList", "basisVar", "basisVarIdxATT",
  "otherVariablesSEQ", "otherVariableResult", "@1", "otherVariableStart",
  "otherVariableAttList", "otherVariableATT", "numberOfOtherVarATT",
  "otherVarValueATT", "otherVarNameATT", "otherVarDescriptionATT",
  "otherVariableResultContent", "otherVarList", "otherVar",
  "otherVarStart", "otherVarIdxATT", "objectives",
  "numberOfOtherObjectiveResults", "objectivesBody", "objectivesEmpty",
  "objectivesContent", "objectiveValues", "numberOfObjATT", "objValueList",
  "objValue", "objIdxATT", "objVal", "otherObjectivesSEQ",
  "otherObjectiveResult", "otherObjectiveStart", "otherObjectiveAttList",
  "otherObjectiveATT", "numberOfOtherObjATT", "otherObjValueATT",
  "otherObjNameATT", "otherObjDescriptionATT",
  "otherObjectiveResultContent", "otherObjList", "otherObj",
  "otherObjStart", "otherObjIdxATT", "constraints",
  "numberOfOtherConstraintResults", "constraintsBody", "constraintsEmpty",
  "constraintsContent", "dualValues", "numberOfConATT", "dualValueList",
  "dualValue", "conIdxATT", "dualVal", "otherConstraintsSEQ",
  "otherConstraintResult", "otherConstraintStart",
  "otherConstraintAttList", "otherConstraintATT", "numberOfOtherConATT",
  "otherConValueATT", "otherConNameATT", "otherConDescriptionATT",
  "otherConstraintResultContent", "otherConList", "otherCon",
  "otherConStart", "otherConIdxATT", "otherSolutionResults",
  "numberOfOtherSolutionResults", "@2", "otherSolutionResultList",
  "anotherSolutionResult", "anotherSolutionResultAttList", "@3",
  "anotherSolutionResultAtt", "numberOfOtherSolutionResultItems",
  "anotherSolutionResultNameATT", "anotherSolutionResultCategoryATT",
  "anotherSolutionDescriptionATT", "anotherSolutionItemList",
  "anotherSolutionItem", "otherSolutionItemEmpty",
  "otherSolutionItemContent", "@4", "solutionEnd", "otherSolverOutput",
  "numberOfSolverOutputsATT", "otherSolverOutputBody", "solverOutputSEQ",
  "solverOutput", "solverOutputAttList", "@5", "solverOutputAtt",
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
     176,   176,   177,   177,   177,   178,   178,   179,   179,   180,
     181,   181,   182,   182,   183,   184,   184,   185,   186,   186,
     187,   187,   188,   189,   190,   190,   191,   191,   192,   193,
     193,   193,   194,   194,   194,   195,   195,   195,   196,   196,
     196,   197,   197,   197,   198,   198,   198,   199,   199,   199,
     200,   201,   202,   202,   203,   203,   204,   205,   205,   206,
     207,   207,   208,   208,   208,   209,   210,   211,   212,   212,
     213,   213,   213,   214,   214,   214,   214,   215,   216,   216,
     217,   217,   218,   219,   220,   220,   221,   222,   222,   223,
     223,   224,   225,   226,   226,   227,   228,   228,   229,   229,
     230,   231,   232,   232,   233,   234,   234,   235,   236,   236,
     237,   237,   238,   239,   239,   240,   240,   241,   242,   242,
     243,   244,   244,   245,   245,   245,   246,   247,   248,   249,
     249,   250,   250,   250,   251,   251,   251,   251,   252,   252,
     252,   252,   253,   253,   253,   253,   254,   254,   254,   254,
     255,   255,   255,   255,   256,   256,   257,   258,   258,   259,
     259,   260,   261,   261,   262,   263,   263,   264,   264,   264,
     265,   266,   267,   268,   268,   269,   269,   269,   270,   270,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   272,   272,   272,   273,   273,   273,   274,   274,   274,
     275,   275,   275,   276,   276,   276,   277,   278,   279,   279,
     280,   280,   281,   282,   282,   283,   283,   283,   283,   284,
     284,   285,   285,   286,   286,   287,   287,   288,   288,   289,
     289,   290,   290,   291,   291,   292,   293,   293,   294,   294,
     295,   296,   297,   297,   298,   299,   299,   300,   301,   301,
     302,   303,   303,   304,   304,   305,   306,   307,   307,   308,
     309,   309,   310,   310,   311,   312,   313,   313,   314,   315,
     316,   316,   317,   317,   318,   319,   319,   320,   321,   321,
     322,   322,   322,   323,   324,   325,   326,   326,   327,   327,
     328,   328,   329,   329,   329,   329,   330,   331,   332,   333,
     334,   334,   335,   336,   336,   337,   338,   339,   339,   340,
     340,   341,   342,   343,   344,   344,   345,   345,   346,   346,
     346,   346,   347,   347,   347,   348,   348,   349,   349,   350,
     350,   351,   352,   353,   353,   354,   355,   355,   356,   357,
     358,   358,   359,   359,   360,   361,   361,   362,   363,   364,
     364,   365,   365,   366,   367,   367,   368,   369,   370,   370,
     372,   371,   373,   374,   374,   375,   375,   375,   375,   376,
     377,   377,   378,   378,   379,   380,   380,   381,   381,   382,
     383,   384,   385,   385,   386,   386,   387,   387,   388,   389,
     390,   390,   391,   392,   392,   393,   394,   395,   395,   396,
     396,   397,   398,   399,   399,   400,   400,   400,   400,   401,
     402,   402,   403,   403,   404,   405,   405,   406,   406,   407,
     408,   409,   410,   410,   411,   411,   412,   412,   413,   414,
     415,   415,   416,   417,   417,   418,   419,   420,   420,   421,
     421,   422,   423,   424,   424,   425,   425,   425,   425,   426,
     427,   427,   428,   428,   429,   430,   430,   431,   431,   432,
     433,   434,   435,   435,   437,   436,   438,   438,   439,   440,
     441,   440,   442,   442,   442,   442,   443,   444,   444,   445,
     445,   446,   446,   447,   447,   448,   448,   449,   449,   451,
     450,   452,   453,   453,   454,   455,   455,   456,   456,   457,
     458,   459,   458,   460,   460,   460,   460,   461,   462,   462,
     463,   463,   464,   464,   465,   465,   466,   466,   467,   467,
     469,   468,   470,   470,   471,   472,   472,   472,   473,   473,
     473,   473,   474,   474
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     3,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     2,     1,     1,     1,     3,     1,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     2,     3,     0,     2,
       1,     1,     3,     3,     1,     1,     2,     1,     3,     4,
       3,     2,     4,     3,     2,     4,     3,     2,     4,     3,
       2,     4,     3,     2,     4,     3,     2,     4,     3,     2,
       3,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       0,     2,     1,     1,     1,     3,     3,     3,     2,     1,
       0,     2,     9,     0,     4,     3,     2,     5,     0,     2,
       1,     1,     3,     3,     1,     1,     5,     0,     2,     1,
       1,     3,     3,     1,     1,     5,     0,     2,     1,     1,
       3,     3,     1,     1,     5,     0,     2,     3,     1,     1,
       0,     3,     4,     1,     1,     2,     1,     3,     1,     2,
       3,     0,     2,     1,     1,     1,     3,     3,     3,     2,
       1,     0,     2,     9,     0,     4,     3,     2,     0,     4,
       3,     2,     0,     4,     3,     2,     0,     4,     3,     2,
       0,     4,     3,     2,     0,     3,     4,     1,     1,     2,
       1,     3,     1,     2,     3,     0,     2,     1,     1,     1,
       3,     3,     3,     2,     1,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     2,     4,     3,     2,     4,     3,     2,
       4,     3,     2,     4,     3,     2,     3,     4,     1,     3,
       0,     2,     3,     0,     2,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     2,
       1,     3,     0,     1,     1,     5,     0,     2,     1,     1,
       3,     3,     1,     1,     5,     0,     2,     3,     1,     1,
       5,     0,     2,     1,     1,     3,     3,     1,     1,     5,
       0,     2,     1,     1,     3,     3,     1,     1,     3,     4,
       1,     1,     2,     1,     3,     1,     2,     3,     0,     2,
       1,     1,     1,     3,     3,     3,     2,     1,     0,     3,
       0,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     1,     2,     0,     2,     3,     1,     0,     2,     1,
       1,     4,     4,     8,     4,     3,     1,     2,     3,     1,
       3,     1,     0,     3,     2,     0,     3,     0,     4,     1,
       1,     1,     6,     0,     5,     4,     0,     2,     5,     4,
       1,     1,     0,     5,     4,     0,     2,     5,     4,     1,
       1,     0,     5,     4,     0,     2,     5,     4,     0,     2,
       0,     4,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     3,     1,     3,     0,     2,     5,
       1,     4,     0,     3,     0,     4,     1,     1,     1,     4,
       0,     5,     4,     0,     2,     5,     4,     1,     1,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     3,     1,     3,     0,     2,     5,
       1,     4,     0,     3,     0,     4,     1,     1,     1,     4,
       0,     5,     4,     0,     2,     5,     4,     1,     1,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     3,     1,     3,     0,     2,     5,
       1,     4,     0,     5,     0,     5,     0,     2,     5,     0,
       0,     3,     1,     1,     1,     1,     4,     1,     3,     3,
       1,     3,     1,     0,     2,     1,     1,     1,     1,     0,
       4,     1,     0,     3,     4,     1,     3,     0,     2,     5,
       0,     0,     3,     1,     1,     1,     1,     4,     1,     3,
       3,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       0,     4,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    90,     4,
       8,     6,     0,   151,     0,    93,    91,     0,   195,     7,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,   154,   152,     0,   308,     0,     0,    60,     0,    63,
       0,    51,   552,     0,     0,    57,     0,    54,     0,    66,
       0,    69,     0,    96,    98,     0,     0,   158,   198,   196,
     310,     0,     0,    33,     0,     0,    28,     0,    26,    21,
      22,    23,    24,    19,    30,    31,     0,    59,     0,    62,
       0,    50,     0,     0,     0,    75,    70,    72,    73,     0,
      56,     0,    53,     0,    65,     0,    68,     0,    95,     0,
     107,     0,     0,   157,     0,   162,     0,     0,     2,    32,
      38,     0,    35,     0,   552,   552,    58,    61,    49,   552,
     544,   548,   549,   550,   551,   553,    80,    74,     0,    77,
      55,    52,    64,    67,    94,     0,     0,     0,    99,   100,
     101,     0,   116,     0,     0,   156,     0,   161,     0,   166,
     197,     0,     0,     0,     0,     0,     0,     0,   265,   256,
     271,   280,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   323,   321,   552,   552,   552,   552,
     311,   552,   552,   552,   552,   309,     0,    34,    36,     0,
      27,    25,    71,     0,    76,    78,   104,   105,     0,   552,
     552,     0,     0,     0,   108,   109,   110,     0,   125,   130,
     155,     0,   160,     0,   165,     0,   170,     0,   222,     0,
     225,   552,     0,     0,   219,     0,   213,     0,   216,     0,
       0,     0,     0,     0,     0,     0,   512,     0,     0,     0,
       0,   312,   313,   314,   315,     0,    47,     0,     0,    39,
      40,    41,    37,    44,    45,    29,     0,    89,     0,     0,
       0,    81,    82,    83,    84,    79,    97,   103,   102,   113,
     114,     0,   552,   552,     0,     0,     0,   117,   118,   119,
       0,     0,     0,   159,     0,   164,     0,   169,     0,   174,
       0,   221,     0,   224,     0,     0,   293,   288,   290,   291,
       0,   218,     0,   212,     0,   215,     0,   230,   228,   226,
       0,     0,   266,     0,     0,     0,   257,   258,   259,     0,
       0,     0,   272,   273,   274,     0,     0,     0,   281,   282,
     283,   320,     0,   326,   324,   327,   322,   318,   319,   316,
     317,     0,    46,     0,     0,    88,   552,   552,   552,   106,
     112,   111,   122,   123,     0,   552,   552,     0,     0,   126,
     552,     0,    92,   163,     0,   168,     0,   173,     0,     0,
     220,   223,   552,   298,   292,     0,   295,   217,   211,   214,
       0,     0,   268,   269,     0,   552,   262,   263,     0,   552,
     552,   277,   278,     0,   552,   552,   286,   287,     0,   552,
     552,   552,     0,     0,    48,    43,    42,    87,    85,    86,
     115,   121,   120,   128,   129,     0,   552,     0,     0,   136,
     131,   133,   134,   167,   542,   543,   172,     0,   552,     0,
     153,   289,     0,   294,   296,   227,   233,   229,   231,   264,
     267,   255,   261,   260,   270,   276,   275,   279,   285,   284,
       0,   517,   515,   513,     0,   552,   552,   328,   329,   330,
     325,   124,   127,   552,   141,   135,     0,   138,   171,     0,
       0,   180,   175,   177,   178,     0,   307,     0,     0,     0,
     299,   300,   301,   302,   297,   252,   552,     0,     0,   342,
       0,     0,   132,     0,   137,   139,   552,   185,   179,     0,
     182,   306,   552,   552,   552,     0,   250,     0,   242,     0,
     246,     0,   240,     0,   244,   234,   235,   236,   237,   238,
     232,   247,   248,   514,   516,   520,   518,     0,   341,     0,
     339,     0,   336,     0,   345,   552,   552,     0,   150,     0,
       0,     0,   142,   143,   144,   145,   140,   176,     0,   181,
     183,   305,   303,   304,   254,   253,   249,     0,     0,     0,
       0,     0,   521,   552,   552,     0,   335,   337,     0,   344,
     347,   402,   331,   332,   149,   552,   552,   552,     0,   194,
       0,     0,     0,   186,   187,   188,   189,   184,   251,   241,
     245,   239,   243,   534,     0,   340,   338,   334,   343,   552,
       0,   404,   442,   148,   146,   147,   193,   552,   552,   552,
       0,     0,     0,   531,     0,   533,     0,   528,   522,   523,
     524,   525,   526,     0,   353,   351,   346,   349,   350,   552,
       0,   444,   482,   192,   190,   191,     0,   538,   539,   519,
     535,   536,   537,     0,     0,     0,     0,   552,     0,   362,
       0,   410,   408,   403,   406,   407,   552,     0,     0,     0,
     540,     0,   530,   532,   529,   348,   552,     0,     0,   371,
     552,     0,   419,     0,   450,   448,   443,   446,   447,     0,
       0,   511,   333,     0,   527,     0,   356,   552,     0,     0,
     378,   405,   552,     0,     0,   552,     0,   459,     0,   486,
     541,   552,     0,     0,   365,   552,     0,     0,     0,   413,
     409,   422,   420,   423,   445,   552,     0,     0,   484,     0,
     355,   354,     0,   357,   552,     0,     0,   374,   382,   352,
     379,   383,   552,     0,     0,     0,   453,   449,   462,   460,
     463,     0,   489,   483,   487,   552,     0,   364,   363,     0,
     366,   552,     0,   380,   412,     0,   411,   414,   437,   435,
     552,     0,     0,   432,     0,   430,   424,   425,   426,   427,
     428,   421,   552,     0,     0,   485,   490,     0,     0,   552,
       0,   373,   372,     0,   375,   552,     0,     0,   392,     0,
     390,     0,   384,   385,   386,   387,   388,   552,     0,     0,
       0,   552,   552,   552,   452,     0,   451,   454,   477,   475,
     552,     0,     0,   472,     0,   470,   464,   465,   466,   467,
     468,   461,   503,     0,   552,   360,   361,     0,     0,     0,
     552,     0,     0,   552,   552,   552,   397,   395,   381,     0,
       0,   440,   436,   438,     0,   552,   434,   433,   431,   552,
       0,     0,     0,   552,   552,   552,     0,     0,     0,   500,
       0,   502,     0,   497,   491,   492,   493,   494,   495,   359,
     358,   552,   369,   370,     0,     0,     0,   552,   394,   393,
     391,     0,   552,   417,   418,     0,   552,     0,   429,     0,
       0,   480,   476,   478,     0,   552,   474,   473,   471,     0,
     507,   508,   488,   504,   505,   506,     0,     0,     0,   552,
     368,   367,   552,     0,   389,   396,   400,   398,     0,   416,
     415,     0,     0,   552,   458,   457,     0,   552,     0,   469,
     509,     0,   499,   501,   498,   377,   376,   552,     0,   552,
     545,   546,   547,     0,   456,   455,     0,     0,     0,   496,
       0,     0,   441,   439,   552,     0,   510,   552,     0,   481,
     479,   401,   399
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    45,    79,    80,
      81,    82,    83,    84,    85,   121,   122,   196,   259,   260,
     261,   262,   263,   264,    31,    32,    33,    34,    35,    36,
      37,    38,    53,    96,    97,    98,   138,   139,   203,   271,
     272,   273,   274,   275,    13,    40,    65,   109,   148,   149,
     150,   208,   111,   151,   214,   215,   216,   281,   153,   217,
     287,   288,   289,   364,   219,   290,   369,   425,   292,   371,
     430,   431,   432,   476,   477,   503,   552,   553,   554,   555,
     556,    18,    67,   115,   159,   226,   299,   379,   439,   482,
     483,   484,   509,   510,   558,   593,   594,   595,   596,   597,
      44,   116,   172,   173,   174,   175,   176,   177,   178,   240,
     319,   391,   448,   495,   525,   526,   527,   528,   529,   530,
     531,   532,   567,   179,   242,   326,   327,   328,   398,   180,
     241,   322,   394,   181,   243,   332,   333,   334,   403,   182,
     244,   338,   339,   340,   408,   183,   232,   307,   308,   309,
     385,   386,   442,   490,   491,   492,   493,   494,    71,   117,
     190,   191,   192,   193,   194,   195,   245,   246,   344,   345,
     413,   467,   468,   469,   470,   499,   541,   542,   544,   581,
     610,   636,   637,   638,   659,   677,   712,   733,   756,   837,
     679,   698,   735,   760,   790,   884,   700,   716,   762,   794,
     841,   717,   740,   801,   741,   763,   802,   803,   804,   805,
     806,   848,   891,   927,   928,   948,   612,   640,   663,   664,
     665,   682,   703,   743,   767,   808,   895,   704,   722,   723,
     744,   776,   777,   778,   779,   780,   781,   809,   853,   854,
     897,   642,   667,   686,   687,   688,   707,   726,   783,   817,
     860,   936,   727,   749,   750,   784,   826,   827,   828,   829,
     830,   831,   861,   903,   904,   938,   669,   690,   751,   729,
     754,   786,   833,   874,   875,   876,   877,   878,   866,   913,
     914,   915,   958,   692,   346,   412,   463,   497,   536,   572,
     604,   628,   629,   630,   631,   632,   620,   650,   651,   652,
     693,   437,    92,   953,   135,    93
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -864
static const yytype_int16 yypact[] =
{
      16,    29,    58,    36,  -864,   102,  -864,   126,    73,  -864,
    -864,  -864,   191,    75,   -16,    42,  -864,   227,    93,  -864,
    -864,   272,   295,   305,   189,   307,   309,   311,   313,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,   315,
     151,   148,  -864,   317,   183,   216,    18,  -864,    25,  -864,
      17,  -864,  -864,   319,    15,  -864,    11,  -864,     8,  -864,
       2,  -864,     5,  -864,  -864,   175,   321,   163,  -864,  -864,
    -864,   200,   -57,  -864,   248,   297,  -864,   310,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,   265,  -864,   203,  -864,
     181,  -864,   365,    -5,   -61,  -864,  -864,  -864,  -864,   260,
    -864,   266,  -864,   280,  -864,   267,  -864,   271,  -864,    90,
    -864,   343,    20,  -864,   323,   268,   -35,   257,  -864,  -864,
    -864,   -55,  -864,   405,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,    12,  -864,
    -864,  -864,  -864,  -864,  -864,   329,   409,   410,  -864,  -864,
    -864,   147,  -864,   352,   332,  -864,    24,  -864,   327,   277,
    -864,   333,   335,   400,   337,   340,   342,   393,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,   225,  -864,  -864,   412,
    -864,  -864,  -864,   154,  -864,  -864,  -864,  -864,   354,  -864,
    -864,   348,   421,   422,  -864,  -864,  -864,   161,  -864,   318,
    -864,   347,  -864,    -4,  -864,   346,   308,    27,  -864,    21,
    -864,  -864,   349,    14,  -864,     7,  -864,     6,  -864,   419,
     351,    34,   172,   182,   193,   372,   -67,   425,   426,   427,
     428,  -864,  -864,  -864,  -864,     9,  -864,   432,   433,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,   330,  -864,   435,   436,
     437,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,   374,  -864,  -864,   357,   438,   439,  -864,  -864,  -864,
      39,   424,   396,  -864,   299,  -864,     0,  -864,   355,   336,
     388,  -864,   366,  -864,   442,    47,  -864,  -864,  -864,  -864,
     338,  -864,   325,  -864,   324,  -864,   446,  -864,  -864,  -864,
     361,   451,  -864,   363,   455,   456,  -864,  -864,  -864,   367,
     457,   461,  -864,  -864,  -864,   369,   462,   463,  -864,  -864,
    -864,  -864,   444,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,   334,  -864,   460,   464,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,   403,  -864,  -864,   371,   468,  -864,
    -864,   370,  -864,  -864,   339,  -864,    10,  -864,   454,   423,
    -864,  -864,  -864,  -864,  -864,    60,  -864,  -864,  -864,  -864,
     466,   -92,  -864,  -864,   326,  -864,  -864,  -864,   328,  -864,
    -864,  -864,  -864,   331,  -864,  -864,  -864,  -864,   322,  -864,
    -864,  -864,   373,    46,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,   413,  -864,   475,    64,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,   359,  -864,   375,
    -864,  -864,   157,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
     477,  -864,  -864,  -864,   356,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,    81,  -864,  -864,   481,
     160,  -864,  -864,  -864,  -864,   382,  -864,   485,   487,   488,
    -864,  -864,  -864,  -864,  -864,   185,  -864,   -74,   275,   401,
     486,   493,  -864,   166,  -864,  -864,  -864,  -864,  -864,   168,
    -864,  -864,  -864,  -864,  -864,     1,  -864,   495,  -864,   496,
    -864,   497,  -864,   498,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,   499,  -864,   500,
    -864,   218,  -864,    19,   344,  -864,  -864,   398,  -864,   501,
     504,   505,  -864,  -864,  -864,  -864,  -864,  -864,   173,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,   377,   502,   503,
     506,   509,   508,  -864,  -864,   378,  -864,  -864,   415,  -864,
     492,   420,  -864,  -864,  -864,  -864,  -864,  -864,   414,  -864,
     516,   519,   520,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,   230,  -864,  -864,  -864,  -864,  -864,
     381,   507,   448,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
     -23,   521,   524,  -864,   525,  -864,   527,  -864,  -864,  -864,
    -864,  -864,  -864,   518,   376,  -864,  -864,  -864,  -864,  -864,
     383,   514,   429,  -864,  -864,  -864,   529,  -864,  -864,  -864,
    -864,  -864,  -864,   530,   531,   532,   535,  -864,   511,   380,
     538,   379,  -864,  -864,  -864,  -864,  -864,   385,   526,   430,
    -864,   537,  -864,  -864,  -864,  -864,  -864,   539,   522,   478,
    -864,   536,  -864,   541,   469,  -864,  -864,  -864,  -864,   546,
     547,  -864,  -864,   510,  -864,   552,  -864,  -864,   549,   534,
    -864,  -864,  -864,   551,   -10,  -864,   550,  -864,   557,  -864,
    -864,  -864,   137,   558,  -864,  -864,   555,   -80,   560,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,   561,   -24,  -864,   186,
    -864,  -864,   543,  -864,  -864,   180,   562,  -864,  -864,  -864,
    -864,  -864,  -864,   -70,   114,   564,  -864,  -864,  -864,  -864,
    -864,   559,  -864,  -864,  -864,  -864,   565,  -864,  -864,   545,
    -864,  -864,   -59,   269,  -864,   548,  -864,  -864,  -864,  -864,
    -864,   573,   576,  -864,   577,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,   -26,   140,  -864,   572,   578,   391,  -864,
     575,  -864,  -864,   554,  -864,  -864,   583,   585,  -864,   586,
    -864,   389,  -864,  -864,  -864,  -864,  -864,  -864,   580,   -46,
     587,  -864,  -864,  -864,  -864,   563,  -864,  -864,  -864,  -864,
    -864,   591,   592,  -864,   593,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,   258,  -864,  -864,  -864,   441,   594,   395,
    -864,   588,   597,  -864,  -864,  -864,  -864,  -864,  -864,   598,
     397,  -864,  -864,  -864,   568,  -864,  -864,  -864,  -864,  -864,
     589,    23,   599,  -864,  -864,  -864,   -18,   600,   603,  -864,
     604,  -864,   606,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,   450,   607,   608,  -864,  -864,  -864,
    -864,   -71,  -864,  -864,  -864,   515,  -864,   605,  -864,   610,
     399,  -864,  -864,  -864,   590,  -864,  -864,  -864,  -864,   612,
    -864,  -864,  -864,  -864,  -864,  -864,   614,   613,   615,  -864,
    -864,  -864,  -864,   465,  -864,  -864,  -864,  -864,   595,  -864,
    -864,   616,   205,  -864,  -864,  -864,   553,  -864,   617,  -864,
    -864,   620,  -864,  -864,  -864,  -864,  -864,  -864,   619,  -864,
    -864,  -864,  -864,   533,  -864,  -864,   627,   205,   566,  -864,
     628,   205,  -864,  -864,  -864,   567,  -864,  -864,   474,  -864,
    -864,  -864,  -864
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,   517,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,   512,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,   164,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,   127,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,   254,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,   100,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,  -864,
    -864,  -864,  -124,  -863,  -864,  -864
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     200,   201,   294,   130,   374,   202,   105,   564,   565,   107,
     314,   312,   103,   351,   792,   101,   434,   435,   310,    99,
     160,    90,    86,   578,   154,   302,   738,   161,   765,    88,
     221,   300,   119,    19,   197,   646,   925,   647,   648,     4,
     909,   534,   910,   911,   320,   136,   446,   342,   137,   367,
     815,   162,   851,   447,   535,   747,   464,   343,     6,   816,
       1,   852,   247,   248,   249,   250,   321,   251,   252,   253,
     254,   368,    20,   163,   465,     5,    21,   120,    22,   120,
      23,   164,   748,   739,     7,   277,   278,   766,   466,   926,
     301,   720,    24,   912,   965,   165,   721,   166,   968,   901,
     145,   793,    25,   155,    26,   222,   649,   304,   303,   167,
      27,    87,     9,   168,    91,   169,   579,   170,   136,   171,
      89,   204,   146,    12,   768,   769,    28,    17,   147,   770,
     902,   311,   102,   436,   100,   104,    10,    11,   313,   315,
     566,   375,   108,   295,   352,   106,   771,    43,   772,   773,
     818,   819,   820,   383,   774,   775,   384,   211,   360,   361,
     131,   132,   133,   134,   266,   267,   383,   485,   486,   443,
     474,   284,   821,   475,   822,   823,   547,   548,    39,   212,
     824,   825,   323,   588,   589,   213,   268,   474,   269,   487,
     504,   488,   329,   285,   270,   515,   516,   489,   549,   286,
     550,    15,    16,   335,   324,   590,   551,   591,    52,   950,
     325,   951,   952,   592,   330,   517,   518,   519,   520,    64,
     331,   521,   522,   523,   524,   336,    72,    73,   575,   576,
      66,   337,   417,   418,   419,   255,   256,    41,    42,    70,
      74,   421,   422,   114,   621,   110,   427,   118,    75,    76,
     537,   538,    77,    78,   539,   540,   123,   257,   441,   258,
     622,   623,   624,   625,   626,   627,   507,   184,   185,   508,
     186,   450,   867,   187,   507,   452,   453,   559,   128,   188,
     455,   456,    46,    47,   189,   458,   459,   460,   868,   869,
     870,   871,   872,   873,   731,   795,   752,   732,   127,   753,
     124,   796,   472,   797,   798,    48,    49,   537,   538,   799,
     800,   539,   540,   125,   479,    50,    51,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    68,    69,    94,
      95,   112,   113,   156,   157,   206,   207,   223,   224,   758,
     759,   500,   501,   227,   228,   229,   230,   233,   234,   502,
     235,   236,   237,   238,   279,   280,   296,   297,   126,   305,
     306,   317,   318,   362,   363,   376,   377,   392,   393,   396,
     397,   129,   533,   401,   402,   406,   407,   423,   424,   140,
     428,   429,   557,   461,   462,   480,   481,   141,   561,   562,
     563,   634,   635,   661,   662,   684,   685,   835,   836,   846,
     847,   882,   883,   893,   894,   934,   935,   142,   144,   152,
     143,   199,   209,   210,   158,   220,   218,   225,   239,   231,
     265,   582,   583,   276,   282,   283,   291,   316,   293,   341,
     298,   347,   348,   349,   350,   353,   354,   355,   356,   357,
     358,   365,   366,   370,   378,   359,   373,   372,   382,   605,
     606,   380,   390,   381,   395,   387,   388,   389,   399,   400,
     404,   613,   614,   615,   405,   409,   410,   411,   415,   414,
     420,   426,   416,   438,   445,   449,   440,   457,   471,   451,
     433,   473,   478,   496,   454,   633,   498,   506,   512,   511,
     513,   514,   545,   643,   644,   645,   546,   543,   568,   569,
     570,   571,   573,   574,   585,   584,   580,   586,   587,   607,
     599,   600,   608,   609,   601,   660,   598,   602,   603,   617,
     611,   616,   618,   619,   657,   639,   641,   654,   655,   653,
     656,   666,   658,   675,   670,   681,   671,   676,   678,   672,
     673,   668,   683,   674,   680,   694,   689,   705,   697,   696,
     699,   702,   695,   706,   708,   691,   701,   709,   711,   714,
     715,   719,   725,   728,   734,   737,   742,   785,   761,   710,
     782,   746,   755,   713,   789,   788,   811,   807,   718,   812,
     813,   724,   832,   840,   834,   839,   843,   730,   844,   845,
     850,   736,   859,   855,   863,   864,   865,   896,   886,   900,
     881,   745,   880,   887,   892,   905,   917,   918,   916,   919,
     757,   921,   923,   922,   930,   932,   933,   940,   764,   937,
     941,   942,   949,   943,   947,   966,   946,   957,   959,   961,
     955,   787,   963,   964,   967,   972,   560,   791,   198,   444,
     505,   577,     0,     0,   970,     0,   810,     0,     0,     0,
     205,     0,     0,     0,     0,     0,     0,     0,   814,     0,
       0,     0,     0,     0,     0,   838,     0,     0,     0,     0,
       0,   842,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   849,     0,     0,     0,   856,   857,   858,
       0,     0,     0,     0,     0,     0,   862,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     879,     0,     0,     0,     0,     0,   885,     0,     0,   888,
     889,   890,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   898,     0,     0,     0,   899,     0,     0,     0,   906,
     907,   908,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   920,     0,     0,
       0,     0,     0,   924,     0,     0,     0,     0,   929,     0,
       0,     0,   931,     0,     0,     0,     0,     0,     0,     0,
       0,   939,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   944,     0,     0,   945,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   954,
       0,     0,     0,   956,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   960,     0,   962,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     969,     0,     0,   971
};

static const yytype_int16 yycheck[] =
{
     124,   125,     6,     8,     4,   129,     4,     6,     7,     4,
       4,     4,     4,     4,    73,     4,     6,     7,     4,     4,
      55,     4,     4,     4,     4,     4,   106,    62,    98,     4,
       6,     4,    89,    49,    89,    58,   107,    60,    61,    10,
      58,   115,    60,    61,    10,   106,   138,   114,   109,    10,
      76,    86,    98,   145,   128,    79,    10,   124,     0,    85,
      44,   107,   186,   187,   188,   189,    32,   191,   192,   193,
     194,    32,    88,   108,    28,    46,    92,   134,    94,   134,
      96,   116,   106,   163,    48,   209,   210,   157,    42,   160,
      63,   101,   108,   111,   957,   130,   106,   132,   961,    76,
      10,   160,   118,    83,   120,    81,   129,   231,    87,   144,
     126,    93,    10,   148,    97,   150,    97,   152,   106,   154,
      95,   109,    32,    50,    10,    11,   142,    52,    38,    15,
     107,   117,   121,   123,   119,   127,    10,    11,   131,   133,
     139,   141,   137,   147,   135,   143,    32,    54,    34,    35,
      10,    11,    12,   106,    40,    41,   109,    10,   282,   283,
     165,   166,   167,   168,    10,    11,   106,    10,    11,   109,
     106,    10,    32,   109,    34,    35,    10,    11,   136,    32,
      40,    41,    10,    10,    11,    38,    32,   106,    34,    32,
     109,    34,    10,    32,    40,    10,    11,    40,    32,    38,
      34,    10,    11,    10,    32,    32,    40,    34,    19,     4,
      38,     6,     7,    40,    32,    30,    31,    32,    33,    68,
      38,    36,    37,    38,    39,    32,    10,    11,    10,    11,
      82,    38,   356,   357,   358,    10,    11,    10,    11,    56,
      24,   365,   366,    80,    14,    70,   370,    47,    32,    33,
      32,    33,    36,    37,    36,    37,     8,    32,   382,    34,
      30,    31,    32,    33,    34,    35,   106,    10,    11,   109,
      13,   395,    14,    16,   106,   399,   400,   109,    97,    22,
     404,   405,    10,    11,    27,   409,   410,   411,    30,    31,
      32,    33,    34,    35,   157,    26,   110,   160,    95,   113,
       3,    32,   426,    34,    35,    10,    11,    32,    33,    40,
      41,    36,    37,     3,   438,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,     6,     7,    10,    11,   159,
     160,   465,   466,    10,    11,    10,    11,    10,    11,   473,
      10,    11,    10,    11,     6,     7,    10,    11,    93,    10,
      11,    10,    11,     6,     7,    10,    11,     6,     7,     6,
       7,     6,   496,     6,     7,     6,     7,     6,     7,   119,
      10,    11,   506,    10,    11,    10,    11,   121,   512,   513,
     514,    10,    11,    10,    11,    10,    11,     6,     7,    10,
      11,     6,     7,     6,     7,     6,     7,   127,   137,    66,
     143,     6,     3,     3,   146,    83,    64,   140,    25,    19,
       8,   545,   546,    69,     3,     3,   108,     8,    81,    57,
     122,     6,     6,     6,     6,     3,     3,   107,     3,     3,
       3,     3,     3,    19,   108,    71,   147,    51,     6,   573,
     574,    63,     6,    87,     3,   117,   131,   133,     3,     3,
       3,   585,   586,   587,     3,     3,     3,    23,     8,   135,
      67,     3,     8,    19,     8,   149,    53,   155,    65,   151,
     141,     6,   123,     6,   153,   609,   130,     6,     3,   107,
       3,     3,     6,   617,   618,   619,     3,    96,     3,     3,
       3,     3,     3,     3,     3,   107,   162,     3,     3,   131,
       8,     8,    97,    21,     8,   639,   139,     8,    10,     3,
     100,   107,     3,     3,     6,    18,    78,     3,     3,     8,
       3,    17,   156,   657,     5,   156,     6,    26,   158,     8,
       8,   112,   666,     8,     6,     8,    20,     6,    26,    10,
      72,    15,   676,    84,     8,   125,   680,    10,     6,    10,
      26,    10,    12,     6,     6,    10,     6,     8,     6,    59,
       6,    10,    29,   697,    29,    10,     3,    29,   702,     3,
       3,   705,    10,    29,     6,    10,     3,   711,     3,     3,
      10,   715,    29,     6,     3,     3,     3,    29,    10,    10,
       6,   725,   161,     6,     6,     6,     3,     3,     8,     3,
     734,   161,     4,     6,    99,    10,     6,     5,   742,    29,
       6,     8,     6,     8,    29,    59,   161,    10,     8,    10,
      77,   755,    99,     6,     6,   161,   509,   761,   121,   385,
     476,   541,    -1,    -1,    77,    -1,   770,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   782,    -1,
      -1,    -1,    -1,    -1,    -1,   789,    -1,    -1,    -1,    -1,
      -1,   795,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   807,    -1,    -1,    -1,   811,   812,   813,
      -1,    -1,    -1,    -1,    -1,    -1,   820,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     834,    -1,    -1,    -1,    -1,    -1,   840,    -1,    -1,   843,
     844,   845,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   855,    -1,    -1,    -1,   859,    -1,    -1,    -1,   863,
     864,   865,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   881,    -1,    -1,
      -1,    -1,    -1,   887,    -1,    -1,    -1,    -1,   892,    -1,
      -1,    -1,   896,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   905,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   919,    -1,    -1,   922,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   933,
      -1,    -1,    -1,   937,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   947,    -1,   949,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     964,    -1,    -1,   967
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   213,   173,    10,    11,    52,   250,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   193,   194,   195,   196,   197,   198,   199,   200,   136,
     214,    10,    11,    54,   269,   176,    10,    11,    10,    11,
      10,    11,    19,   201,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    68,   215,    82,   251,    10,    11,
      56,   327,    10,    11,    24,    32,    33,    36,    37,   177,
     178,   179,   180,   181,   182,   183,     4,    93,     4,    95,
       4,    97,   471,   474,    10,    11,   202,   203,   204,     4,
     119,     4,   121,     4,   127,     4,   143,     4,   137,   216,
      70,   221,    10,    11,    80,   252,   270,   328,    47,    89,
     134,   184,   185,     8,     3,     3,    93,    95,    97,     6,
       8,   165,   166,   167,   168,   473,   106,   109,   205,   206,
     119,   121,   127,   143,   137,    10,    32,    38,   217,   218,
     219,   222,    66,   227,     4,    83,    10,    11,   146,   253,
      55,    62,    86,   108,   116,   130,   132,   144,   148,   150,
     152,   154,   271,   272,   273,   274,   275,   276,   277,   292,
     298,   302,   308,   314,    10,    11,    13,    16,    22,    27,
     329,   330,   331,   332,   333,   334,   186,    89,   185,     6,
     471,   471,   471,   207,   109,   206,     6,     7,   220,     3,
       3,    10,    32,    38,   223,   224,   225,   228,    64,   233,
      83,     6,    81,    10,    11,   140,   254,    10,    11,    10,
      11,    19,   315,    10,    11,    10,    11,    10,    11,    25,
     278,   299,   293,   303,   309,   335,   336,   471,   471,   471,
     471,   471,   471,   471,   471,    10,    11,    32,    34,   187,
     188,   189,   190,   191,   192,     8,    10,    11,    32,    34,
      40,   208,   209,   210,   211,   212,    69,   471,   471,     6,
       7,   226,     3,     3,    10,    32,    38,   229,   230,   231,
     234,   108,   237,    81,     6,   147,    10,    11,   122,   255,
       4,    63,     4,    87,   471,    10,    11,   316,   317,   318,
       4,   117,     4,   131,     4,   133,     8,    10,    11,   279,
      10,    32,   300,    10,    32,    38,   294,   295,   296,    10,
      32,    38,   304,   305,   306,    10,    32,    38,   310,   311,
     312,    57,   114,   124,   337,   338,   453,     6,     6,     6,
       6,     4,   135,     3,     3,   107,     3,     3,     3,    71,
     471,   471,     6,     7,   232,     3,     3,    10,    32,   235,
      19,   238,    51,   147,     4,   141,    10,    11,   108,   256,
      63,    87,     6,   106,   109,   319,   320,   117,   131,   133,
       6,   280,     6,     7,   301,     3,     6,     7,   297,     3,
       3,     6,     7,   307,     3,     3,     6,     7,   313,     3,
       3,    23,   454,   339,   135,     8,     8,   471,   471,   471,
      67,   471,   471,     6,     7,   236,     3,   471,    10,    11,
     239,   240,   241,   141,     6,     7,   123,   470,    19,   257,
      53,   471,   321,   109,   320,     8,   138,   145,   281,   149,
     471,   151,   471,   471,   153,   471,   471,   155,   471,   471,
     471,    10,    11,   455,    10,    28,    42,   340,   341,   342,
     343,    65,   471,     6,   106,   109,   242,   243,   123,   471,
      10,    11,   258,   259,   260,    10,    11,    32,    34,    40,
     322,   323,   324,   325,   326,   282,     6,   456,   130,   344,
     471,   471,   471,   244,   109,   243,     6,   106,   109,   261,
     262,   107,     3,     3,     3,    10,    11,    30,    31,    32,
      33,    36,    37,    38,    39,   283,   284,   285,   286,   287,
     288,   289,   290,   471,   115,   128,   457,    32,    33,    36,
      37,   345,   346,    96,   347,     6,     3,    10,    11,    32,
      34,    40,   245,   246,   247,   248,   249,   471,   263,   109,
     262,   471,   471,   471,     6,     7,   139,   291,     3,     3,
       3,     3,   458,     3,     3,    10,    11,   346,     4,    97,
     162,   348,   471,   471,   107,     3,     3,     3,    10,    11,
      32,    34,    40,   264,   265,   266,   267,   268,   139,     8,
       8,     8,     8,    10,   459,   471,   471,   131,    97,    21,
     349,   100,   385,   471,   471,   471,   107,     3,     3,     3,
     465,    14,    30,    31,    32,    33,    34,    35,   460,   461,
     462,   463,   464,   471,    10,    11,   350,   351,   352,    18,
     386,    78,   410,   471,   471,   471,    58,    60,    61,   129,
     466,   467,   468,     8,     3,     3,     3,     6,   156,   353,
     471,    10,    11,   387,   388,   389,    17,   411,   112,   435,
       5,     6,     8,     8,     8,   471,    26,   354,   158,   359,
       6,   156,   390,   471,    10,    11,   412,   413,   414,    20,
     436,   125,   452,   469,     8,   471,    10,    26,   360,    72,
     365,   471,    15,   391,   396,     6,    84,   415,     8,    10,
      59,     6,   355,   471,    10,    26,   366,   370,   471,    10,
     101,   106,   397,   398,   471,    12,   416,   421,     6,   438,
     471,   157,   160,   356,     6,   361,   471,    10,   106,   163,
     371,   373,     6,   392,   399,   471,    10,    79,   106,   422,
     423,   437,   110,   113,   439,    29,   357,   471,   159,   160,
     362,     6,   367,   374,   471,    98,   157,   393,    10,    11,
      15,    32,    34,    35,    40,    41,   400,   401,   402,   403,
     404,   405,     6,   417,   424,     8,   440,   471,    10,    29,
     363,   471,    73,   160,   368,    26,    32,    34,    35,    40,
      41,   372,   375,   376,   377,   378,   379,    29,   394,   406,
     471,     3,     3,     3,   471,    76,    85,   418,    10,    11,
      12,    32,    34,    35,    40,    41,   425,   426,   427,   428,
     429,   430,    10,   441,     6,     6,     7,   358,   471,    10,
      29,   369,   471,     3,     3,     3,    10,    11,   380,   471,
      10,    98,   107,   407,   408,     6,   471,   471,   471,    29,
     419,   431,   471,     3,     3,     3,   447,    14,    30,    31,
      32,    33,    34,    35,   442,   443,   444,   445,   446,   471,
     161,     6,     6,     7,   364,   471,    10,     6,   471,   471,
     471,   381,     6,     6,     7,   395,    29,   409,   471,   471,
      10,    76,   107,   432,   433,     6,   471,   471,   471,    58,
      60,    61,   111,   448,   449,   450,     8,     3,     3,     3,
     471,   161,     6,     4,   471,   107,   160,   382,   383,   471,
      99,   471,    10,     6,     6,     7,   420,    29,   434,   471,
       5,     6,     8,     8,   471,   471,   161,    29,   384,     6,
       4,     6,     7,   472,   471,    77,   471,    10,   451,     8,
     471,    10,   471,    99,     6,   472,    59,     6,   472,   471,
      77,   471,   161
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
        case 22:

    {   if (parserData->generalStatusTypePresent ) 
        osrlerror(NULL, NULL, parserData, "only one type attribute allowed for generalStatus element");
    parserData->generalStatusTypePresent = true;
    osresult->setGeneralStatusType(parserData->tempStr); 
;}
    break;

  case 23:

    {   if (parserData->generalStatusDescriptionPresent ) 
        osrlerror(NULL, NULL, parserData, "only one description attribute allowed for generalStatus element");
    parserData->generalStatusDescriptionPresent = true;
    osresult->setGeneralStatusDescription(parserData->tempStr);
;}
    break;

  case 24:

    { std::cout << "parsed numberOfGeneralSubstatuses" << std::endl;
;}
    break;

  case 25:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 26:

    { parserData->tempStr = "";          ;}
    break;

  case 27:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 28:

    { parserData->tempStr = "";          ;}
    break;

  case 29:

    {   if (parserData->generalStatusNumberOfPresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for generalStatus element");
    parserData->generalStatusNumberOfPresent = true;
/*    osresult->setGeneralStatusNumberOf(parserData->tempStr);  */
/* !!!allocate substatus array */
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of general substatuses cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 34:

    { std::cout << "parsed </generalStatus" << std::endl;
;}
    break;

  case 42:

    { std::cout << "parsed <generalSubstatus name=" << std::endl;
;}
    break;

  case 43:

    { std::cout << "parsed generalSubstatus description=" << std::endl;
;}
    break;

  case 48:

    { std::cout << "parsed </generalSubstatus>" << std::endl;
/* !!!put substatus text */ ;}
    break;

  case 49:

    {osresult->setGeneralMessage( (yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 52:

    {osresult->setServiceURI( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval)); parserData->errorText = NULL;;}
    break;

  case 55:

    {osresult->setServiceName((yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));   parserData->errorText = NULL;;}
    break;

  case 58:

    {osresult->setInstanceName( (yyvsp[(3) - (4)].sval)) ;  free((yyvsp[(3) - (4)].sval));   parserData->errorText = NULL;;}
    break;

  case 61:

    {osresult->setJobID( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 64:

    {std::cout << "!!!store solver invoked" << std::endl;;}
    break;

  case 67:

    {std::cout << "!!!store time stamp" << std::endl;;}
    break;

  case 71:

    {std::cout << "!!!store numberOfOtherGeneralResults" << std::endl;;}
    break;

  case 94:

    {;}
    break;

  case 102:

    {;}
    break;

  case 103:

    {;}
    break;

  case 111:

    {;}
    break;

  case 112:

    {;}
    break;

  case 120:

    {;}
    break;

  case 121:

    {;}
    break;

  case 127:

    {;}
    break;

  case 132:

    {std::cout << "!!!store numberOfOtherSystemResults" << std::endl;;}
    break;

  case 155:

    {;}
    break;

  case 159:

    {;}
    break;

  case 163:

    {;}
    break;

  case 167:

    {;}
    break;

  case 171:

    {;}
    break;

  case 176:

    {std::cout << "!!!store numberOfOtherserviceResults" << std::endl;;}
    break;

  case 211:

    {;}
    break;

  case 214:

    {;}
    break;

  case 217:

    {;}
    break;

  case 220:

    {;}
    break;

  case 223:

    {;}
    break;

  case 227:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
;}
    break;

  case 239:

    {parserData->timeType = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 241:

    {parserData->timeCategory = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 243:

    {parserData->timeUnit = (yyvsp[(2) - (3)].sval);   free((yyvsp[(2) - (3)].sval));;}
    break;

  case 245:

    {parserData->timeDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 251:

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

  case 253:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 254:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 260:

    {;}
    break;

  case 261:

    {;}
    break;

  case 267:

    {;}
    break;

  case 275:

    {;}
    break;

  case 276:

    {;}
    break;

  case 284:

    {;}
    break;

  case 285:

    {;}
    break;

  case 289:

    {std::cout << "!!!store numberOfOtherjobResults" << std::endl;;}
    break;

  case 316:

    {parserData->numberOfSolutions   = (yyvsp[(3) - (3)].ival); osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 317:

    {parserData->numberOfVariables   = (yyvsp[(3) - (3)].ival); osresult->setVariableNumber((yyvsp[(3) - (3)].ival)); ;}
    break;

  case 318:

    {parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 319:

    {parserData->numberOfObjectives  = (yyvsp[(3) - (3)].ival); osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 325:

    {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   ;}
    break;

  case 326:

    {   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
;}
    break;

  case 331:

    {
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
/*  	osresult->optimization->solution[parserData->solutionIdx]->targetObjectiveIdx = $3;*/
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 332:

    { parserData->tempStr = (yyvsp[(3) - (4)].sval); ;}
    break;

  case 334:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, parserData, "a type attribute required for status element");  osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);;}
    break;

  case 335:

    {if(parserData->statusTypePresent == false) osrlerror(NULL, NULL, parserData, "a type attribute required for status element"); parserData->statusTypePresent = false; osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);;}
    break;

  case 338:

    {parserData->statusType = (yyvsp[(2) - (3)].sval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].sval));;}
    break;

  case 339:

    {parserData->statusType = ""; parserData->statusTypePresent = true;;}
    break;

  case 340:

    {parserData->statusDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 341:

    {parserData->statusDescription = "";;}
    break;

  case 343:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = $2; */
		osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
	;}
    break;

  case 344:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = "";*/
		osresult->setSolutionMessage(parserData->solutionIdx, "");
	;}
    break;

  case 348:

    {  
	osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
	;}
    break;

  case 354:

    {
  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  ;}
    break;

  case 355:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 359:

    { parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 360:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->primalVals.push_back( parserData->primalValPair);  
   ;}
    break;

  case 361:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); 
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->primalVals.push_back( parserData->primalValPair); 
  ;}
    break;

  case 363:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
     }
 */  ;}
    break;

  case 364:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 368:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 369:

    {/*parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  */
   ;}
    break;

  case 370:

    {/*parserData->tempVal = $1; 
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair); */
  ;}
    break;

  case 372:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
      }
 */  ;}
    break;

  case 373:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 377:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 380:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	;}
    break;

  case 382:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	;}
    break;

  case 389:

    {
	parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	//osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = $3;
;}
    break;

  case 390:

    {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
;}
    break;

  case 391:

    {parserData->tmpOtherValue=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 392:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 393:

    {
parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 394:

    {
parserData->tmpOtherDescription=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 396:

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

  case 399:

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
;}
    break;

  case 400:

    {//	if(parserData->otherVarStruct->numberOfVar <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	;}
    break;

  case 401:

    {;}
    break;

  case 405:

    {  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 411:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
;}
    break;

  case 412:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 416:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(3) - (4)].ival);   ;}
    break;

  case 417:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].ival);                  
	parserData->objVals.push_back( parserData->objValPair);
;}
    break;

  case 418:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->objVals.push_back( parserData->objValPair);
  ;}
    break;

  case 422:

    {  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	;}
    break;

  case 429:

    {
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
;}
    break;

  case 430:

    {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
;}
    break;

  case 431:

    {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 432:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherObjStruct->name = "";
;}
    break;

  case 433:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 434:

    {
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 436:

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

  case 439:

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

  case 440:

    {//	if(parserData->otherObjStruct->numberOfObj <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of objectives") ;
	;}
    break;

  case 441:

    {;}
    break;

  case 445:

    {  
/*        osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 451:

    {
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}
 ;}
    break;

  case 452:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 456:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 457:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 		
	;}
    break;

  case 458:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 	
	;}
    break;

  case 470:

    {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
;}
    break;

  case 471:

    {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 472:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherConStruct->name = "";
;}
    break;

  case 473:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 474:

    {
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 479:

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

  case 480:

    {//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	;}
    break;

  case 481:

    {;}
    break;

  case 483:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 484:

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

  case 488:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 490:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 496:

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

  case 497:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 498:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 499:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 501:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 504:

    {parserData->kounter++;;}
    break;

  case 505:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 506:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 509:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 511:

    {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
;}
    break;

  case 519:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
;}
    break;

  case 521:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/;}
    break;

  case 527:

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

  case 528:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
*/
;}
    break;

  case 529:

    {
/*	parserData->tmpOtherName=$2; parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
;}
    break;

  case 530:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
;}
    break;

  case 532:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
;}
    break;

  case 536:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/;}
    break;

  case 537:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/;}
    break;

  case 540:

    {/*parserData->itemContent = $2; free($2);*/;}
    break;

  case 542:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 543:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 545:

    { parserData->outStr << (yyvsp[(1) - (1)].sval);    free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 546:

    { parserData->outStr << (yyvsp[(1) - (1)].ival);  /*free($1);*/ ;}
    break;

  case 547:

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


