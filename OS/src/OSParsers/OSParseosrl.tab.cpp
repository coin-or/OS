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
#define YYLAST   987

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  388
/* YYNRULES -- Number of rules.  */
#define YYNRULES  680
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1107

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
     132,   135,   137,   141,   144,   146,   149,   151,   155,   158,
     160,   163,   165,   169,   172,   174,   177,   179,   183,   186,
     188,   191,   193,   197,   200,   202,   205,   207,   211,   214,
     216,   219,   221,   225,   228,   230,   234,   236,   241,   243,
     245,   248,   250,   254,   256,   259,   263,   265,   266,   269,
     271,   273,   275,   279,   283,   285,   289,   291,   294,   296,
     297,   300,   305,   306,   309,   311,   313,   315,   317,   319,
     321,   324,   326,   330,   333,   335,   341,   343,   344,   347,
     349,   351,   355,   359,   361,   363,   365,   371,   373,   374,
     377,   379,   381,   385,   389,   391,   393,   395,   401,   403,
     404,   407,   409,   411,   415,   419,   421,   423,   425,   431,
     433,   434,   436,   440,   442,   444,   448,   450,   455,   457,
     459,   462,   464,   468,   470,   473,   477,   479,   480,   483,
     485,   487,   489,   493,   497,   499,   503,   505,   508,   510,
     511,   514,   519,   520,   523,   525,   527,   529,   531,   533,
     535,   538,   540,   544,   547,   549,   552,   554,   558,   561,
     563,   566,   568,   572,   575,   577,   580,   582,   586,   589,
     591,   594,   596,   600,   603,   605,   609,   611,   616,   618,
     620,   623,   625,   629,   631,   634,   638,   640,   641,   644,
     646,   648,   650,   654,   658,   660,   664,   666,   669,   671,
     672,   675,   680,   681,   684,   686,   688,   690,   692,   694,
     696,   698,   700,   702,   704,   706,   709,   711,   715,   718,
     720,   723,   725,   729,   732,   734,   737,   739,   743,   746,
     748,   751,   753,   757,   760,   762,   765,   767,   771,   774,
     776,   780,   782,   787,   789,   793,   794,   797,   801,   802,
     805,   807,   809,   811,   813,   817,   819,   823,   825,   829,
     831,   835,   837,   839,   841,   844,   846,   850,   851,   853,
     855,   861,   863,   864,   867,   869,   871,   875,   879,   881,
     883,   885,   891,   893,   894,   897,   899,   901,   905,   909,
     911,   913,   915,   921,   923,   924,   927,   929,   931,   935,
     939,   941,   943,   945,   951,   953,   954,   957,   961,   963,
     965,   969,   971,   976,   978,   980,   983,   985,   989,   991,
     994,   998,  1000,  1001,  1004,  1006,  1008,  1010,  1014,  1018,
    1020,  1024,  1026,  1029,  1031,  1032,  1036,  1037,  1040,  1043,
    1046,  1049,  1052,  1056,  1060,  1064,  1068,  1072,  1074,  1077,
    1078,  1081,  1085,  1087,  1088,  1091,  1093,  1095,  1100,  1104,
    1113,  1117,  1119,  1121,  1123,  1126,  1128,  1130,  1132,  1136,
    1138,  1142,  1144,  1149,  1151,  1153,  1156,  1158,  1162,  1164,
    1167,  1171,  1173,  1174,  1177,  1179,  1181,  1185,  1189,  1191,
    1194,  1196,  1197,  1202,  1206,  1209,  1210,  1214,  1215,  1220,
    1222,  1224,  1226,  1233,  1234,  1238,  1240,  1245,  1247,  1249,
    1252,  1254,  1258,  1260,  1263,  1269,  1271,  1276,  1278,  1280,
    1281,  1287,  1291,  1296,  1297,  1300,  1306,  1311,  1315,  1320,
    1321,  1327,  1331,  1336,  1337,  1340,  1346,  1351,  1352,  1355,
    1356,  1361,  1363,  1365,  1366,  1369,  1371,  1373,  1375,  1377,
    1382,  1384,  1388,  1390,  1394,  1398,  1400,  1402,  1406,  1407,
    1410,  1414,  1416,  1421,  1425,  1428,  1430,  1431,  1435,  1436,
    1441,  1443,  1445,  1447,  1452,  1453,  1459,  1463,  1468,  1469,
    1472,  1478,  1483,  1485,  1487,  1488,  1491,  1495,  1497,  1498,
    1501,  1503,  1505,  1507,  1509,  1514,  1516,  1520,  1522,  1526,
    1530,  1532,  1534,  1538,  1539,  1542,  1546,  1548,  1553,  1557,
    1560,  1562,  1563,  1567,  1568,  1573,  1575,  1577,  1579,  1584,
    1585,  1591,  1595,  1600,  1601,  1604,  1610,  1615,  1617,  1619,
    1620,  1623,  1627,  1629,  1630,  1633,  1635,  1637,  1639,  1641,
    1646,  1648,  1652,  1654,  1658,  1662,  1664,  1666,  1670,  1671,
    1674,  1678,  1680,  1685,  1689,  1692,  1694,  1695,  1701,  1705,
    1706,  1712,  1713,  1716,  1722,  1726,  1727,  1728,  1732,  1734,
    1736,  1738,  1740,  1745,  1747,  1751,  1755,  1757,  1761,  1763,
    1764,  1767,  1769,  1771,  1773,  1775,  1776,  1781,  1783,  1784,
    1788,  1793,  1795,  1799,  1800,  1803,  1809,  1813,  1814,  1815,
    1819,  1821,  1823,  1825,  1827,  1832,  1834,  1838,  1842,  1844,
    1848,  1850,  1851,  1854,  1856,  1858,  1860,  1862,  1863,  1868,
    1870,  1872,  1875,  1877,  1879,  1881,  1883,  1885,  1887,  1889,
    1890
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   230,   277,   310,   385,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   194,    -1,   197,    -1,   200,    -1,   203,
      -1,   206,    -1,   209,    -1,   212,    -1,   215,    -1,   176,
     177,   183,    -1,    88,    -1,   178,    -1,   179,    -1,   178,
     179,    -1,   180,    -1,   181,    -1,   182,    -1,    36,     3,
     553,    -1,    37,    -1,    32,     3,   553,    -1,    33,    -1,
      24,     8,     6,     8,    -1,   184,    -1,   185,    -1,    10,
      89,    -1,    11,    -1,    10,   186,    89,    -1,   187,    -1,
     186,   187,    -1,   188,   189,   193,    -1,   134,    -1,    -1,
     189,   190,    -1,   191,    -1,   192,    -1,    34,     3,     8,
      -1,    32,     3,     8,    -1,    33,    -1,    10,   135,    -1,
      11,    -1,   195,   196,    -1,    96,    -1,    10,     4,    97,
      -1,    10,    97,    -1,    11,    -1,   198,   199,    -1,   120,
      -1,    10,     4,   121,    -1,    10,   121,    -1,    11,    -1,
     201,   202,    -1,   118,    -1,    10,     4,   119,    -1,    10,
     119,    -1,    11,    -1,   204,   205,    -1,    92,    -1,    10,
       4,    93,    -1,    10,    93,    -1,    11,    -1,   207,   208,
      -1,    94,    -1,    10,     4,    95,    -1,    10,    95,    -1,
      11,    -1,   210,   211,    -1,   126,    -1,    10,     4,   127,
      -1,    10,   127,    -1,    11,    -1,   213,   214,    -1,   142,
      -1,    10,     4,   143,    -1,    10,   143,    -1,    11,    -1,
     216,   217,   218,    -1,   108,    -1,    19,   553,     6,   553,
      -1,   219,    -1,   220,    -1,    10,   109,    -1,    11,    -1,
      10,   221,   109,    -1,   222,    -1,   221,   222,    -1,   223,
     224,   229,    -1,   106,    -1,    -1,   224,   225,    -1,   226,
      -1,   227,    -1,   228,    -1,    34,     3,   553,    -1,    40,
       3,   553,    -1,    41,    -1,    32,     3,   553,    -1,    33,
      -1,    10,   107,    -1,    11,    -1,    -1,    50,    11,    -1,
      50,    10,   231,    51,    -1,    -1,   231,   232,    -1,   233,
      -1,   236,    -1,   243,    -1,   250,    -1,   257,    -1,   262,
      -1,   234,   235,    -1,   136,    -1,    10,     4,   137,    -1,
      10,   137,    -1,    11,    -1,   237,   238,    10,   242,    69,
      -1,    68,    -1,    -1,   238,   239,    -1,   240,    -1,   241,
      -1,    38,     3,   553,    -1,    32,     3,   553,    -1,    33,
      -1,     6,    -1,     7,    -1,   244,   245,    10,   249,    71,
      -1,    70,    -1,    -1,   245,   246,    -1,   247,    -1,   248,
      -1,    38,     3,   553,    -1,    32,     3,   553,    -1,    33,
      -1,     6,    -1,     7,    -1,   251,   252,    10,   256,    67,
      -1,    66,    -1,    -1,   252,   253,    -1,   254,    -1,   255,
      -1,    38,     3,   553,    -1,    32,     3,   553,    -1,    33,
      -1,     6,    -1,     7,    -1,   258,   259,    10,   261,    65,
      -1,    64,    -1,    -1,   260,    -1,    32,     3,   553,    -1,
      33,    -1,     6,    -1,   263,   264,   265,    -1,   108,    -1,
      19,   553,     6,   553,    -1,   266,    -1,   267,    -1,    10,
     109,    -1,    11,    -1,    10,   268,   109,    -1,   269,    -1,
     268,   269,    -1,   270,   271,   276,    -1,   106,    -1,    -1,
     271,   272,    -1,   273,    -1,   274,    -1,   275,    -1,    34,
       3,   553,    -1,    40,     3,   553,    -1,    41,    -1,    32,
       3,   553,    -1,    33,    -1,    10,   107,    -1,    11,    -1,
      -1,    52,    11,    -1,    52,    10,   278,    53,    -1,    -1,
     278,   279,    -1,   280,    -1,   283,    -1,   286,    -1,   289,
      -1,   292,    -1,   295,    -1,   281,   282,    -1,    82,    -1,
      10,     4,    83,    -1,    10,    83,    -1,    11,    -1,   284,
     285,    -1,    80,    -1,    10,     6,    81,    -1,    10,    81,
      -1,    11,    -1,   287,   288,    -1,   146,    -1,    10,     6,
     147,    -1,    10,   147,    -1,    11,    -1,   290,   291,    -1,
     140,    -1,    10,     4,   141,    -1,    10,   141,    -1,    11,
      -1,   293,   294,    -1,   122,    -1,    10,   552,   123,    -1,
      10,   123,    -1,    11,    -1,   296,   297,   298,    -1,   108,
      -1,    19,   553,     6,   553,    -1,   299,    -1,   300,    -1,
      10,   109,    -1,    11,    -1,    10,   301,   109,    -1,   302,
      -1,   301,   302,    -1,   303,   304,   309,    -1,   106,    -1,
      -1,   304,   305,    -1,   306,    -1,   307,    -1,   308,    -1,
      34,     3,   553,    -1,    40,     3,   553,    -1,    41,    -1,
      32,     3,   553,    -1,    33,    -1,    10,   107,    -1,    11,
      -1,    -1,    54,    11,    -1,    54,    10,   311,    55,    -1,
      -1,   311,   312,    -1,   313,    -1,   316,    -1,   319,    -1,
     322,    -1,   325,    -1,   328,    -1,   344,    -1,   351,    -1,
     358,    -1,   365,    -1,   370,    -1,   314,   315,    -1,   130,
      -1,    10,     4,   131,    -1,    10,   131,    -1,    11,    -1,
     317,   318,    -1,   132,    -1,    10,     4,   133,    -1,    10,
     133,    -1,    11,    -1,   320,   321,    -1,   116,    -1,    10,
       4,   117,    -1,    10,   117,    -1,    11,    -1,   323,   324,
      -1,    62,    -1,    10,     4,    63,    -1,    10,    63,    -1,
      11,    -1,   326,   327,    -1,    86,    -1,    10,     4,    87,
      -1,    10,    87,    -1,    11,    -1,   329,   330,   331,    -1,
     144,    -1,    25,     8,     6,     8,    -1,    11,    -1,    10,
     332,   145,    -1,    -1,   332,   333,    -1,   138,   334,   340,
      -1,    -1,   334,   335,    -1,   336,    -1,   337,    -1,   338,
      -1,   339,    -1,    36,     3,     8,    -1,    37,    -1,    30,
       3,     8,    -1,    31,    -1,    38,     3,     8,    -1,    39,
      -1,    32,     3,     8,    -1,    33,    -1,   341,    -1,   342,
      -1,    10,   139,    -1,    11,    -1,    10,   343,   139,    -1,
      -1,     7,    -1,     6,    -1,   345,   346,    10,   350,   153,
      -1,   152,    -1,    -1,   346,   347,    -1,   348,    -1,   349,
      -1,    38,     3,   553,    -1,    32,     3,   553,    -1,    33,
      -1,     6,    -1,     7,    -1,   352,   353,    10,   357,   155,
      -1,   154,    -1,    -1,   353,   354,    -1,   355,    -1,   356,
      -1,    38,     3,   553,    -1,    32,     3,   553,    -1,    33,
      -1,     6,    -1,     7,    -1,   359,   360,    10,   364,   151,
      -1,   150,    -1,    -1,   360,   361,    -1,   362,    -1,   363,
      -1,    38,     3,   553,    -1,    32,     3,   553,    -1,    33,
      -1,     6,    -1,     7,    -1,   366,   367,    10,   369,   149,
      -1,   148,    -1,    -1,   367,   368,    -1,    32,     3,   553,
      -1,    33,    -1,     6,    -1,   371,   372,   373,    -1,   108,
      -1,    19,   553,     6,   553,    -1,   374,    -1,   375,    -1,
      10,   109,    -1,    11,    -1,    10,   376,   109,    -1,   377,
      -1,   376,   377,    -1,   378,   379,   384,    -1,   106,    -1,
      -1,   379,   380,    -1,   381,    -1,   382,    -1,   383,    -1,
      34,     3,   553,    -1,    40,     3,   553,    -1,    41,    -1,
      32,     3,   553,    -1,    33,    -1,    10,   107,    -1,    11,
      -1,    -1,    56,   386,   392,    -1,    -1,   386,   387,    -1,
     388,   553,    -1,   389,   553,    -1,   390,   553,    -1,   391,
     553,    -1,    22,   553,     6,    -1,    27,   553,     6,    -1,
      13,   553,     6,    -1,    16,   553,     6,    -1,    10,   393,
      57,    -1,    11,    -1,   394,   535,    -1,    -1,   394,   395,
      -1,   396,   397,   401,    -1,   124,    -1,    -1,   397,   398,
      -1,   399,    -1,   400,    -1,    28,   553,     6,   553,    -1,
      42,     3,   553,    -1,    10,   402,   421,   422,   465,   491,
     517,   534,    -1,   403,   404,   410,    -1,   130,    -1,   405,
      -1,   406,    -1,   405,   406,    -1,   407,    -1,   408,    -1,
     409,    -1,    36,     3,   553,    -1,    37,    -1,    32,     3,
     553,    -1,    33,    -1,    24,     8,     6,     8,    -1,   411,
      -1,   412,    -1,    10,   131,    -1,    11,    -1,    10,   413,
     131,    -1,   414,    -1,   413,   414,    -1,   415,   416,   420,
      -1,   134,    -1,    -1,   416,   417,    -1,   418,    -1,   419,
      -1,    36,     3,     8,    -1,    32,     3,     8,    -1,    33,
      -1,    10,   135,    -1,    11,    -1,    -1,    96,    10,     4,
      97,    -1,    96,    10,    97,    -1,    96,    11,    -1,    -1,
     162,   423,   424,    -1,    -1,    21,   553,     6,   553,    -1,
     425,    -1,   426,    -1,    11,    -1,    10,   427,   438,   443,
     448,   163,    -1,    -1,   428,   429,   430,    -1,   156,    -1,
      26,   553,     6,   553,    -1,   431,    -1,   432,    -1,    10,
     157,    -1,    11,    -1,    10,   433,   157,    -1,   434,    -1,
     433,   434,    -1,   435,   436,    10,   437,   161,    -1,   160,
      -1,    29,   553,     6,   553,    -1,     6,    -1,     7,    -1,
      -1,   158,   439,    10,   440,   159,    -1,   158,   439,    11,
      -1,    26,   553,     6,   553,    -1,    -1,   440,   441,    -1,
     160,   442,    10,     4,   161,    -1,   160,   442,    10,   161,
      -1,   160,   442,    11,    -1,    29,   553,     6,   553,    -1,
      -1,    72,   444,    10,   445,    73,    -1,    72,   444,    11,
      -1,    26,   553,     6,   553,    -1,    -1,   445,   446,    -1,
     160,   447,    10,     4,   161,    -1,    29,   553,     6,   553,
      -1,    -1,   448,   449,    -1,    -1,   451,   452,   450,   459,
      -1,   106,    -1,   453,    -1,    -1,   453,   454,    -1,   455,
      -1,   456,    -1,   457,    -1,   458,    -1,    26,   553,     6,
     553,    -1,    41,    -1,    40,     3,   553,    -1,    35,    -1,
      34,     3,   553,    -1,    32,     3,   553,    -1,    33,    -1,
      11,    -1,    10,   460,   107,    -1,    -1,   460,   461,    -1,
     462,   463,   464,    -1,   160,    -1,    29,   553,     6,   553,
      -1,    10,   554,   161,    -1,    10,   161,    -1,    11,    -1,
      -1,   100,   466,   467,    -1,    -1,    18,   553,     6,   553,
      -1,   468,    -1,   469,    -1,    11,    -1,    10,   470,   476,
     101,    -1,    -1,   156,   471,    10,   472,   157,    -1,   156,
     471,    11,    -1,    15,   553,     6,   553,    -1,    -1,   472,
     473,    -1,    98,   474,    10,   475,    99,    -1,    29,   553,
       6,   553,    -1,     6,    -1,     7,    -1,    -1,   476,   477,
      -1,   478,   479,   485,    -1,   106,    -1,    -1,   479,   480,
      -1,   481,    -1,   482,    -1,   483,    -1,   484,    -1,    15,
     553,     6,   553,    -1,    41,    -1,    40,     3,   553,    -1,
      35,    -1,    34,     3,   553,    -1,    32,     3,   553,    -1,
      33,    -1,    11,    -1,    10,   486,   107,    -1,    -1,   486,
     487,    -1,   488,   489,   490,    -1,    98,    -1,    29,   553,
       6,   553,    -1,    10,   554,    99,    -1,    10,    99,    -1,
      11,    -1,    -1,    78,   492,   493,    -1,    -1,    17,   553,
       6,   553,    -1,   494,    -1,   495,    -1,    11,    -1,    10,
     496,   502,    79,    -1,    -1,    84,   497,    10,   498,    85,
      -1,    84,   497,    11,    -1,    12,   553,     6,   553,    -1,
      -1,   498,   499,    -1,    76,   500,    10,   501,    77,    -1,
      29,   553,     6,   553,    -1,     7,    -1,     6,    -1,    -1,
     502,   503,    -1,   504,   505,   511,    -1,   106,    -1,    -1,
     505,   506,    -1,   507,    -1,   508,    -1,   509,    -1,   510,
      -1,    12,   553,     6,   553,    -1,    41,    -1,    40,     3,
     553,    -1,    35,    -1,    34,     3,   553,    -1,    32,     3,
     553,    -1,    33,    -1,    11,    -1,    10,   512,   107,    -1,
      -1,   512,   513,    -1,   514,   515,   516,    -1,    76,    -1,
      29,   553,     6,   553,    -1,    10,   554,    77,    -1,    10,
      77,    -1,    11,    -1,    -1,   112,   518,    10,   520,   113,
      -1,   112,   518,    11,    -1,    -1,    20,     8,     6,   519,
       8,    -1,    -1,   520,   521,    -1,   110,   522,    10,   529,
     111,    -1,   110,   522,    11,    -1,    -1,    -1,   522,   523,
     524,    -1,   525,    -1,   526,    -1,   527,    -1,   528,    -1,
      14,     8,     6,     8,    -1,    35,    -1,    34,     3,   553,
      -1,    30,     3,     8,    -1,    31,    -1,    32,     3,     8,
      -1,    33,    -1,    -1,   529,   530,    -1,   531,    -1,   532,
      -1,    60,    -1,    61,    -1,    -1,    58,     5,   533,    59,
      -1,   125,    -1,    -1,   114,   536,   537,    -1,    23,   553,
       6,   553,    -1,    11,    -1,    10,   538,   115,    -1,    -1,
     538,   539,    -1,   128,   540,    10,   547,   129,    -1,   128,
     540,    11,    -1,    -1,    -1,   540,   541,   542,    -1,   543,
      -1,   544,    -1,   545,    -1,   546,    -1,    14,     8,     6,
       8,    -1,    35,    -1,    34,     3,     8,    -1,    30,     3,
       8,    -1,    31,    -1,    32,     3,     8,    -1,    33,    -1,
      -1,   547,   548,    -1,   549,    -1,   550,    -1,    60,    -1,
      61,    -1,    -1,    58,     5,   551,    59,    -1,     6,    -1,
       7,    -1,   556,     8,    -1,     4,    -1,     6,    -1,     7,
      -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1,    -1,
     556,   555,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   166,   167,   169,   169,   170,   172,   172,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   186,
     188,   201,   207,   207,   210,   220,   226,   228,   229,   231,
     232,   234,   245,   249,   255,   255,   257,   259,   259,   261,
     269,   274,   274,   276,   276,   283,   291,   294,   299,   299,
     302,   304,   311,   313,   314,   316,   318,   325,   327,   328,
     330,   332,   339,   341,   342,   344,   346,   353,   355,   356,
     358,   360,   367,   369,   370,   372,   374,   381,   383,   384,
     386,   388,   395,   397,   398,   400,   402,   408,   415,   418,
     422,   422,   424,   426,   426,   428,   437,   442,   442,   445,
     451,   457,   465,   467,   468,   470,   471,   473,   473,   477,
     477,   478,   480,   480,   483,   484,   485,   486,   487,   488,
     491,   493,   500,   502,   503,   505,   508,   514,   514,   516,
     516,   518,   527,   529,   532,   533,   535,   538,   544,   544,
     546,   546,   548,   556,   558,   561,   562,   564,   567,   573,
     573,   575,   575,   577,   589,   591,   594,   595,   598,   601,
     607,   607,   609,   611,   614,   617,   619,   625,   632,   636,
     641,   641,   643,   645,   645,   647,   656,   661,   661,   664,
     670,   676,   684,   686,   687,   689,   690,   692,   692,   696,
     696,   697,   699,   699,   702,   703,   704,   705,   706,   707,
     710,   712,   719,   721,   722,   724,   726,   733,   735,   736,
     738,   740,   747,   749,   750,   752,   754,   761,   763,   764,
     766,   768,   775,   777,   778,   781,   783,   789,   796,   800,
     805,   805,   807,   809,   809,   811,   820,   825,   825,   828,
     834,   840,   848,   850,   851,   853,   854,   856,   856,   859,
     859,   860,   862,   862,   865,   866,   867,   868,   869,   870,
     871,   872,   873,   874,   875,   878,   880,   887,   889,   890,
     892,   894,   901,   903,   904,   906,   908,   915,   917,   918,
     920,   922,   929,   931,   932,   934,   936,   943,   945,   946,
     948,   950,   956,   962,   962,   964,   964,   966,   968,   968,
     970,   970,   970,   970,   972,   973,   975,   976,   978,   979,
     981,   982,   984,   984,   986,   986,   988,   999,  1003,  1004,
    1007,  1010,  1016,  1016,  1018,  1018,  1020,  1030,  1032,  1035,
    1036,  1038,  1041,  1047,  1047,  1049,  1049,  1051,  1059,  1061,
    1064,  1065,  1068,  1071,  1078,  1078,  1080,  1080,  1082,  1094,
    1096,  1099,  1100,  1103,  1106,  1113,  1113,  1115,  1117,  1120,
    1124,  1126,  1132,  1139,  1143,  1148,  1148,  1150,  1152,  1152,
    1154,  1163,  1168,  1168,  1171,  1177,  1183,  1191,  1193,  1194,
    1196,  1197,  1199,  1199,  1202,  1202,  1204,  1204,  1207,  1208,
    1209,  1210,  1213,  1221,  1229,  1237,  1245,  1245,  1247,  1249,
    1249,  1251,  1258,  1266,  1266,  1268,  1268,  1270,  1278,  1286,
    1289,  1291,  1298,  1304,  1304,  1307,  1319,  1325,  1327,  1328,
    1330,  1331,  1333,  1343,  1347,  1353,  1353,  1355,  1357,  1357,
    1359,  1368,  1373,  1373,  1375,  1375,  1382,  1390,  1392,  1395,
    1395,  1398,  1399,  1402,  1403,  1405,  1406,  1408,  1409,  1418,
    1418,  1420,  1422,  1424,  1424,  1426,  1429,  1438,  1442,  1448,
    1448,  1450,  1452,  1452,  1454,  1461,  1469,  1472,  1473,  1476,
    1477,  1486,  1488,  1495,  1495,  1497,  1502,  1503,  1505,  1509,
    1509,  1518,  1520,  1527,  1527,  1529,  1531,  1536,  1536,  1539,
    1538,  1558,  1566,  1572,  1572,  1574,  1574,  1574,  1574,  1576,
    1588,  1591,  1597,  1603,  1609,  1614,  1616,  1617,  1619,  1619,
    1621,  1636,  1641,  1643,  1643,  1643,  1646,  1647,  1649,  1650,
    1660,  1660,  1662,  1664,  1666,  1667,  1676,  1678,  1682,  1682,
    1684,  1686,  1689,  1693,  1699,  1699,  1701,  1704,  1712,  1713,
    1715,  1715,  1715,  1715,  1717,  1726,  1729,  1735,  1741,  1747,
    1752,  1755,  1756,  1778,  1778,  1780,  1795,  1800,  1802,  1802,
    1802,  1806,  1807,  1809,  1810,  1820,  1820,  1822,  1824,  1827,
    1828,  1838,  1840,  1845,  1845,  1847,  1849,  1852,  1856,  1862,
    1862,  1864,  1867,  1869,  1869,  1871,  1871,  1871,  1871,  1873,
    1876,  1879,  1885,  1891,  1897,  1902,  1904,  1905,  1908,  1908,
    1910,  1926,  1931,  1933,  1933,  1933,  1937,  1938,  1943,  1950,
    1949,  1965,  1965,  1968,  1975,  1984,  1985,  1985,  1989,  1989,
    1989,  1989,  1991,  2004,  2010,  2018,  2021,  2024,  2027,  2029,
    2030,  2033,  2038,  2045,  2045,  2048,  2047,  2053,  2063,  2063,
    2065,  2067,  2067,  2069,  2069,  2072,  2079,  2081,  2083,  2082,
    2087,  2087,  2087,  2087,  2089,  2104,  2111,  2120,  2126,  2129,
    2135,  2137,  2138,  2140,  2145,  2151,  2151,  2154,  2153,  2159,
    2160,  2162,  2165,  2166,  2167,  2171,  2172,  2173,  2174,  2176,
    2177
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
  "generalMessage", "generalMessageStart", "generalMessageContent",
  "serviceURI", "serviceURIStart", "serviceURIContent", "serviceName",
  "serviceNameStart", "serviceNameContent", "instanceName",
  "instanceNameStart", "instanceNameContent", "jobID", "jobIDStart",
  "jobIDContent", "solverInvoked", "solverInvokedStart",
  "solverInvokedContent", "timeStamp", "timeStampStart",
  "timeStampContent", "generalOtherResults", "generalOtherResultsStart",
  "generalOtherResultsAttList", "generalOtherResultsContent",
  "generalOtherResultsEmpty", "generalOtherResultsBody",
  "generalOtherResultSEQ", "generalOtherResult", "generalOtherResultStart",
  "generalOtherAttList", "generalOtherAtt", "generalOtherNameATT",
  "generalOtherValueATT", "generalOtherDescriptionATT", "generalOtherEnd",
  "systemElement", "systemContent", "systemChild", "systemInformation",
  "systemInformationStart", "systemInformationContent",
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
  "currentStateStart", "currentStateContent", "currentJobCount",
  "currentJobCountStart", "currentJobCountContent", "totalJobsSoFar",
  "totalJobsSoFarStart", "totalJobsSoFarContent", "timeServiceStarted",
  "timeServiceStartedStart", "timeServiceStartedContent",
  "serviceUtilization", "serviceUtilizationStart",
  "serviceUtilizationContent", "serviceOtherResults",
  "serviceOtherResultsStart", "serviceOtherResultsAttList",
  "serviceOtherResultsContent", "serviceOtherResultsEmpty",
  "serviceOtherResultsBody", "serviceOtherResultSEQ", "serviceOtherResult",
  "serviceOtherResultStart", "serviceOtherAttList", "serviceOtherAtt",
  "serviceOtherNameATT", "serviceOtherValueATT",
  "serviceOtherDescriptionATT", "serviceOtherEnd", "jobElement",
  "jobContent", "jobChild", "jobStatus", "jobStatusStart",
  "jobStatusContent", "submitTime", "submitTimeStart", "submitTimeContent",
  "scheduledStartTime", "scheduledStartTimeStart",
  "scheduledStartTimeContent", "actualStartTime", "actualStartTimeStart",
  "actualStartTimeContent", "endTime", "endTimeStart", "endTimeContent",
  "timingInformation", "timingInformationStart", "numberoftimes",
  "timingContent", "listOfTimes", "time", "timeAttList", "timeAtt",
  "timeType", "timeCategory", "timeUnit", "timeDescription",
  "restOfTimeElement", "timeEmpty", "timeContent", "timeValue",
  "usedDiskSpace", "usedDiskSpaceStart", "usedDiskSpaceAttList",
  "usedDiskSpaceAtt", "usedDiskSpaceUnitATT",
  "usedDiskSpaceDescriptionATT", "usedDiskSpaceValue", "usedMemory",
  "usedMemoryStart", "usedMemoryAttList", "usedMemoryAtt",
  "usedMemoryUnitATT", "usedMemoryDescriptionATT", "usedMemoryValue",
  "usedCPUSpeed", "usedCPUSpeedStart", "usedCPUSpeedAttList",
  "usedCPUSpeedAtt", "usedCPUSpeedUnitATT", "usedCPUSpeedDescriptionATT",
  "usedCPUSpeedValue", "usedCPUNumber", "usedCPUNumberStart",
  "usedCPUNumberAttList", "usedCPUNumberDescriptionATT",
  "usedCPUNumberValue", "jobOtherResults", "jobOtherResultsStart",
  "jobOtherResultsAttList", "jobOtherResultsContent",
  "jobOtherResultsEmpty", "jobOtherResultsBody", "jobOtherResultSEQ",
  "jobOtherResult", "jobOtherResultStart", "jobOtherAttList",
  "jobOtherAtt", "jobOtherNameATT", "jobOtherValueATT",
  "jobOtherDescriptionATT", "jobOtherEnd", "optimizationElement",
  "optimizationAttList", "optimizationATT",
  "optimizationNumberOfSolutionsATT", "optimizationNumberOfVariablesATT",
  "optimizationNumberOfConstraintsATT",
  "optimizationNumberOfObjectivesATT", "optimizationBody",
  "optimizationContent", "solutionList", "solution", "solutionStart",
  "solutionAttList", "solutionATT", "targetObjectiveIdxATT",
  "weightedObjectivesATT", "solutionBody", "solutionStatus",
  "solutionStatusStart", "solutionStatusAttributes",
  "solutionStatusAttList", "solutionStatusATT", "solutionStatusTypeATT",
  "solutionStatusDescriptionATT", "solutionStatusNumberOfATT",
  "solutionStatusContent", "solutionStatusEmpty", "solutionStatusBody",
  "solutionSubstatusSEQ", "solutionSubstatus", "solutionSubstatusStart",
  "solutionSubstatusAttList", "solutionSubstatusATT",
  "solutionSubstatusTypeATT", "solutionSubstatusDescriptionATT",
  "solutionSubstatusEnd", "solutionMessage", "variables",
  "numberOfOtherVariableResults", "variablesBody", "variablesEmpty",
  "variablesContent", "variableValues", "variableValuesStart",
  "numberOfVarATT", "variableValuesContent", "variableValuesEmpty",
  "variableValuesBody", "varValueSEQ", "varValue", "varValueStart",
  "varIdxATT", "varVal", "variableValuesString", "numberOfVarStringATT",
  "varValueStringList", "varValueString", "varStrIdxATT", "basisStatus",
  "numberOfBasisVarATT", "basisVarList", "basisVar", "basisVarIdxATT",
  "otherVariablesSEQ", "otherVariableResult", "@1", "otherVariableStart",
  "otherVariableAttributes", "otherVariableAttList", "otherVariableATT",
  "numberOfOtherVarATT", "otherVarValueATT", "otherVarNameATT",
  "otherVarDescriptionATT", "otherVariableResultContent", "otherVarList",
  "otherVar", "otherVarStart", "otherVarIdxATT", "otherVarContent",
  "objectives", "numberOfOtherObjectiveResults", "objectivesBody",
  "objectivesEmpty", "objectivesContent", "objectiveValues",
  "numberOfObjATT", "objValueList", "objValue", "objIdxATT", "objVal",
  "otherObjectivesSEQ", "otherObjectiveResult", "otherObjectiveStart",
  "otherObjectiveAttList", "otherObjectiveATT", "numberOfOtherObjATT",
  "otherObjValueATT", "otherObjNameATT", "otherObjDescriptionATT",
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
     194,   195,   196,   196,   196,   197,   198,   199,   199,   199,
     200,   201,   202,   202,   202,   203,   204,   205,   205,   205,
     206,   207,   208,   208,   208,   209,   210,   211,   211,   211,
     212,   213,   214,   214,   214,   215,   216,   217,   218,   218,
     219,   219,   220,   221,   221,   222,   223,   224,   224,   225,
     225,   225,   226,   227,   227,   228,   228,   229,   229,   230,
     230,   230,   231,   231,   232,   232,   232,   232,   232,   232,
     233,   234,   235,   235,   235,   236,   237,   238,   238,   239,
     239,   240,   241,   241,   242,   242,   243,   244,   245,   245,
     246,   246,   247,   248,   248,   249,   249,   250,   251,   252,
     252,   253,   253,   254,   255,   255,   256,   256,   257,   258,
     259,   259,   260,   260,   261,   262,   263,   264,   265,   265,
     266,   266,   267,   268,   268,   269,   270,   271,   271,   272,
     272,   272,   273,   274,   274,   275,   275,   276,   276,   277,
     277,   277,   278,   278,   279,   279,   279,   279,   279,   279,
     280,   281,   282,   282,   282,   283,   284,   285,   285,   285,
     286,   287,   288,   288,   288,   289,   290,   291,   291,   291,
     292,   293,   294,   294,   294,   295,   296,   297,   298,   298,
     299,   299,   300,   301,   301,   302,   303,   304,   304,   305,
     305,   305,   306,   307,   307,   308,   308,   309,   309,   310,
     310,   310,   311,   311,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   313,   314,   315,   315,   315,
     316,   317,   318,   318,   318,   319,   320,   321,   321,   321,
     322,   323,   324,   324,   324,   325,   326,   327,   327,   327,
     328,   329,   330,   331,   331,   332,   332,   333,   334,   334,
     335,   335,   335,   335,   336,   336,   337,   337,   338,   338,
     339,   339,   340,   340,   341,   341,   342,   342,   343,   343,
     344,   345,   346,   346,   347,   347,   348,   349,   349,   350,
     350,   351,   352,   353,   353,   354,   354,   355,   356,   356,
     357,   357,   358,   359,   360,   360,   361,   361,   362,   363,
     363,   364,   364,   365,   366,   367,   367,   368,   368,   369,
     370,   371,   372,   373,   373,   374,   374,   375,   376,   376,
     377,   378,   379,   379,   380,   380,   380,   381,   382,   382,
     383,   383,   384,   384,   385,   385,   386,   386,   387,   387,
     387,   387,   388,   389,   390,   391,   392,   392,   393,   394,
     394,   395,   396,   397,   397,   398,   398,   399,   400,   401,
     402,   403,   404,   405,   405,   406,   406,   406,   407,   407,
     408,   408,   409,   410,   410,   411,   411,   412,   413,   413,
     414,   415,   416,   416,   417,   417,   418,   419,   419,   420,
     420,   421,   421,   421,   421,   422,   422,   423,   423,   424,
     424,   425,   426,   427,   427,   428,   429,   430,   430,   431,
     431,   432,   433,   433,   434,   435,   436,   437,   437,   438,
     438,   438,   439,   440,   440,   441,   441,   441,   442,   443,
     443,   443,   444,   445,   445,   446,   447,   448,   448,   450,
     449,   451,   452,   453,   453,   454,   454,   454,   454,   455,
     456,   456,   457,   457,   458,   458,   459,   459,   460,   460,
     461,   462,   463,   464,   464,   464,   465,   465,   466,   466,
     467,   467,   468,   469,   470,   470,   470,   471,   472,   472,
     473,   474,   475,   475,   476,   476,   477,   478,   479,   479,
     480,   480,   480,   480,   481,   482,   482,   483,   483,   484,
     484,   485,   485,   486,   486,   487,   488,   489,   490,   490,
     490,   491,   491,   492,   492,   493,   493,   494,   495,   496,
     496,   496,   497,   498,   498,   499,   500,   501,   501,   502,
     502,   503,   504,   505,   505,   506,   506,   506,   506,   507,
     508,   508,   509,   509,   510,   510,   511,   511,   512,   512,
     513,   514,   515,   516,   516,   516,   517,   517,   517,   519,
     518,   520,   520,   521,   521,   522,   523,   522,   524,   524,
     524,   524,   525,   526,   526,   527,   527,   528,   528,   529,
     529,   530,   530,   531,   531,   533,   532,   534,   535,   535,
     536,   537,   537,   538,   538,   539,   539,   540,   541,   540,
     542,   542,   542,   542,   543,   544,   544,   545,   545,   546,
     546,   547,   547,   548,   548,   549,   549,   551,   550,   552,
     552,   553,   554,   554,   554,   555,   555,   555,   555,   556,
     556
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     3,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     3,     1,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       1,     0,     2,     1,     1,     3,     3,     1,     2,     1,
       2,     1,     3,     2,     1,     2,     1,     3,     2,     1,
       2,     1,     3,     2,     1,     2,     1,     3,     2,     1,
       2,     1,     3,     2,     1,     2,     1,     3,     2,     1,
       2,     1,     3,     2,     1,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     2,     3,     1,     0,     2,     1,
       1,     1,     3,     3,     1,     3,     1,     2,     1,     0,
       2,     4,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     2,     1,     5,     1,     0,     2,     1,
       1,     3,     3,     1,     1,     1,     5,     1,     0,     2,
       1,     1,     3,     3,     1,     1,     1,     5,     1,     0,
       2,     1,     1,     3,     3,     1,     1,     1,     5,     1,
       0,     1,     3,     1,     1,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     2,     3,     1,     0,     2,     1,
       1,     1,     3,     3,     1,     3,     1,     2,     1,     0,
       2,     4,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     2,     1,     2,     1,     3,     2,     1,
       2,     1,     3,     2,     1,     2,     1,     3,     2,     1,
       2,     1,     3,     2,     1,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     2,     3,     1,     0,     2,     1,
       1,     1,     3,     3,     1,     3,     1,     2,     1,     0,
       2,     4,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     2,     1,
       2,     1,     3,     2,     1,     2,     1,     3,     2,     1,
       2,     1,     3,     2,     1,     2,     1,     3,     2,     1,
       3,     1,     4,     1,     3,     0,     2,     3,     0,     2,
       1,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     2,     1,     3,     0,     1,     1,
       5,     1,     0,     2,     1,     1,     3,     3,     1,     1,
       1,     5,     1,     0,     2,     1,     1,     3,     3,     1,
       1,     1,     5,     1,     0,     2,     1,     1,     3,     3,
       1,     1,     1,     5,     1,     0,     2,     3,     1,     1,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       3,     1,     0,     2,     1,     1,     1,     3,     3,     1,
       3,     1,     2,     1,     0,     3,     0,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     1,     2,     0,
       2,     3,     1,     0,     2,     1,     1,     4,     3,     8,
       3,     1,     1,     1,     2,     1,     1,     1,     3,     1,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       3,     1,     0,     2,     1,     1,     3,     3,     1,     2,
       1,     0,     4,     3,     2,     0,     3,     0,     4,     1,
       1,     1,     6,     0,     3,     1,     4,     1,     1,     2,
       1,     3,     1,     2,     5,     1,     4,     1,     1,     0,
       5,     3,     4,     0,     2,     5,     4,     3,     4,     0,
       5,     3,     4,     0,     2,     5,     4,     0,     2,     0,
       4,     1,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     3,     1,     1,     3,     0,     2,
       3,     1,     4,     3,     2,     1,     0,     3,     0,     4,
       1,     1,     1,     4,     0,     5,     3,     4,     0,     2,
       5,     4,     1,     1,     0,     2,     3,     1,     0,     2,
       1,     1,     1,     1,     4,     1,     3,     1,     3,     3,
       1,     1,     3,     0,     2,     3,     1,     4,     3,     2,
       1,     0,     3,     0,     4,     1,     1,     1,     4,     0,
       5,     3,     4,     0,     2,     5,     4,     1,     1,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     3,     1,     1,     3,     0,     2,
       3,     1,     4,     3,     2,     1,     0,     5,     3,     0,
       5,     0,     2,     5,     3,     0,     0,     3,     1,     1,
       1,     1,     4,     1,     3,     3,     1,     3,     1,     0,
       2,     1,     1,     1,     1,     0,     4,     1,     0,     3,
       4,     1,     3,     0,     2,     5,     3,     0,     0,     3,
       1,     1,     1,     1,     4,     1,     3,     3,     1,     3,
       1,     0,     2,     1,     1,     1,     1,     0,     4,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,   109,     4,
       8,     6,     0,   189,     0,   112,   110,     0,   249,     7,
      20,    66,    71,    51,    86,    61,    56,    76,    81,     9,
      10,     0,    11,     0,    12,     0,    13,     0,    14,     0,
      15,     0,    16,     0,    17,     0,    18,     0,     0,   192,
     190,     0,   384,     0,     0,    30,     0,    28,     0,    21,
      22,    24,    25,    26,     0,    54,    50,     0,    59,    55,
       0,    64,    60,     0,    69,    65,     0,    74,    70,     0,
      79,    75,     0,    84,    80,   679,     0,   111,   159,   148,
     126,   137,   166,   121,   113,   114,     0,   115,   127,   116,
     138,   117,   149,   118,   160,   119,     0,     0,   252,   250,
     386,     0,     0,   679,   679,     0,    35,    19,    32,    33,
      23,     0,    53,     0,    58,     0,    63,     0,    68,     0,
      73,     0,    78,     0,    83,     0,     0,     0,    91,    85,
      88,    89,     0,   124,   120,     0,     0,     0,     0,   163,
       0,   161,   679,     0,   191,   206,   201,   226,   221,   216,
     211,   193,   194,     0,   195,     0,   196,     0,   197,     0,
     198,     0,   199,     0,     0,     0,     2,     0,    29,    27,
      34,    40,     0,    37,    41,    52,    57,    62,    67,    72,
      77,    82,   679,   671,   675,   676,   677,   678,   680,    96,
      90,     0,    93,    97,     0,   123,     0,     0,   133,     0,
     128,   129,   130,     0,     0,   144,     0,   139,   140,   141,
       0,     0,   155,     0,   150,   151,   152,   679,     0,     0,
       0,   171,   165,   168,   169,     0,   204,   200,     0,   209,
     205,     0,   214,   210,     0,   219,   215,     0,   224,   220,
     679,     0,   251,   281,   286,   361,   276,   266,   271,   291,
     354,   343,   321,   332,   253,   254,     0,   255,     0,   256,
       0,   257,     0,   258,     0,   259,     0,   260,   322,   261,
     333,   262,   344,   263,   355,   264,     0,   399,   397,   679,
     679,   679,   679,   387,   679,   679,   679,   679,   385,    31,
      36,    38,     0,    87,    92,    94,     0,   122,   134,   135,
       0,   679,   679,   145,   146,     0,   679,   679,   156,   157,
       0,   679,   679,   162,   164,     0,   679,   176,   170,     0,
     173,   177,     0,   203,     0,   208,     0,   213,     0,   218,
     669,   670,   223,     0,     0,     0,   231,   225,   228,   229,
       0,   269,   265,     0,   274,   270,     0,   279,   275,     0,
     284,   280,     0,   289,   285,     0,     0,     0,     0,     0,
       0,   679,     0,     0,   638,     0,     0,     0,     0,   388,
     389,   390,   391,     0,    49,     0,    47,     0,    42,    43,
      44,    39,     0,   108,     0,   106,     0,     0,   104,    98,
      99,   100,   101,    95,   125,   132,   131,   136,   143,   142,
     147,   154,   153,   158,   167,   172,   174,     0,   202,   207,
     212,   217,   222,   679,   236,   230,     0,   233,   237,     0,
     268,     0,   273,     0,   278,     0,   283,     0,   288,     0,
     295,   293,   290,     0,     0,   328,     0,   323,   324,   325,
       0,     0,   339,     0,   334,   335,   336,     0,     0,   350,
       0,   345,   346,   347,     0,     0,   358,   356,     0,     0,
     366,   360,   363,   364,   396,     0,   402,   400,   403,   398,
     394,   395,   392,   393,    48,     0,     0,   107,   679,   679,
     679,     0,   188,     0,   186,     0,     0,   184,   178,   179,
     180,   181,   175,   227,   232,   234,     0,   267,   272,   277,
     282,   287,     0,     0,   329,   330,     0,   679,   679,   340,
     341,     0,   679,   679,   351,   352,     0,   679,   679,   359,
       0,   679,   679,   371,   365,     0,   368,   372,   679,     0,
       0,    46,    45,   105,   102,   103,   187,   679,   679,   679,
       0,   248,     0,   246,     0,     0,   244,   238,   239,   240,
     241,   235,   292,   298,   294,   296,   320,   327,   326,   331,
     338,   337,   342,   349,   348,   353,   357,   362,   367,   369,
       0,     0,   643,   641,   639,     0,   679,     0,   404,   405,
     406,   401,   185,   182,   183,   247,   679,   679,   679,   317,
       0,   383,     0,   381,     0,     0,   379,   373,   374,   375,
     376,   370,   679,     0,   411,   441,     0,     0,   679,   245,
     242,   243,     0,   315,     0,   307,     0,   311,     0,   305,
       0,   309,   299,   300,   301,   302,   303,   297,   312,   313,
     382,   679,   679,   679,   640,   642,   647,   644,     0,   445,
       0,     0,   421,     0,   419,     0,   412,   413,   415,   416,
     417,   679,   408,   319,   318,   314,     0,     0,     0,     0,
       0,   380,   377,   378,   648,     0,   444,   447,   516,     0,
     679,   679,     0,   426,   410,   423,   424,   414,   407,   316,
     306,   310,   304,   308,   661,   646,     0,     0,   443,   679,
       0,   518,   561,     0,   420,   418,   425,   431,     0,   428,
     432,     0,     0,     0,   658,     0,   660,     0,   655,   649,
     650,   651,   652,   653,   442,     0,   453,   451,   446,   449,
     450,   679,     0,   563,   606,   422,   427,   429,     0,     0,
     665,   666,   645,   662,   663,   664,     0,     0,     0,     0,
     679,   455,   469,     0,     0,   524,   522,   517,   520,   521,
     679,     0,     0,     0,     0,   440,     0,   438,     0,   433,
     434,   435,   430,   667,     0,   657,   659,   656,   448,     0,
     479,   679,     0,   679,     0,   534,     0,   569,   567,   562,
     565,   566,     0,     0,   637,   409,   439,     0,     0,     0,
     654,   679,     0,     0,   487,     0,     0,   460,   454,   457,
     458,   519,   679,     0,     0,   679,     0,   579,     0,   611,
     608,   437,   436,   668,     0,   473,   471,   679,     0,     0,
     679,   459,   465,     0,   462,     0,     0,   528,   526,   523,
     537,   535,   538,   564,   679,     0,     0,   609,     0,   679,
       0,     0,   483,   481,   491,   452,   488,   493,   456,   461,
     463,   679,     0,   679,     0,     0,     0,   573,   571,   568,
     582,   580,   583,     0,   615,   607,   612,   472,   470,     0,
     474,   679,     0,   489,   492,     0,     0,   527,     0,   525,
     529,   553,   551,   679,     0,   550,     0,   547,     0,   545,
     539,   540,   541,   542,   543,   536,   679,     0,     0,   610,
     616,   679,     0,   482,   480,     0,   484,     0,   679,     0,
     505,     0,   502,     0,   500,   494,   495,   496,   497,   498,
     679,   467,   468,     0,   679,     0,     0,     0,   679,   679,
     679,   572,     0,   570,   574,   598,   596,   679,     0,   595,
       0,   592,     0,   590,   584,   585,   586,   587,   588,   581,
     629,   614,     0,     0,     0,   477,   679,     0,   508,   506,
     490,     0,   679,   679,   679,   466,   464,     0,     0,   556,
     552,   554,     0,   679,   549,   548,   546,   679,     0,     0,
       0,   679,   679,   679,     0,     0,     0,   626,     0,   628,
       0,   623,   617,   618,   619,   620,   621,   679,     0,   476,
       0,     0,     0,   679,   504,   503,   501,   679,   532,   533,
       0,   679,     0,   544,     0,     0,   601,   597,   599,     0,
     679,   594,   593,   591,     0,   633,   634,   613,   630,   631,
     632,     0,     0,     0,   679,   478,   475,   679,     0,   507,
     511,   509,     0,   499,   531,   530,     0,     0,   560,   555,
     679,   578,   577,     0,   679,     0,   589,   635,     0,   625,
     627,   624,   486,   485,   679,     0,   679,   672,   673,   674,
     559,     0,   576,   575,     0,     0,   605,   600,     0,   622,
       0,     0,   515,   510,   557,   558,   679,   604,     0,   636,
     679,   514,     0,   602,   603,   512,   513
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    31,    58,    59,
      60,    61,    62,    63,   117,   118,   119,   182,   183,   184,
     302,   388,   389,   390,   391,    32,    33,    66,    34,    35,
      69,    36,    37,    72,    38,    39,    75,    40,    41,    78,
      42,    43,    81,    44,    45,    84,    46,    47,    86,   139,
     140,   141,   201,   202,   203,   306,   399,   400,   401,   402,
     403,    13,    48,    94,    95,    96,   144,    97,    98,   145,
     210,   211,   212,   310,    99,   100,   146,   217,   218,   219,
     315,   101,   102,   147,   224,   225,   226,   320,   103,   104,
     150,   151,   325,   105,   106,   153,   232,   233,   234,   329,
     330,   331,   417,   498,   499,   500,   501,   502,    18,   107,
     161,   162,   163,   237,   164,   165,   240,   166,   167,   243,
     168,   169,   246,   170,   171,   249,   172,   173,   251,   347,
     348,   349,   426,   427,   428,   506,   557,   558,   559,   560,
     561,    52,   174,   264,   265,   266,   352,   267,   268,   355,
     269,   270,   358,   271,   272,   361,   273,   274,   364,   275,
     276,   366,   442,   513,   565,   599,   632,   633,   634,   635,
     636,   637,   638,   639,   666,   277,   278,   367,   447,   448,
     449,   516,   279,   280,   368,   454,   455,   456,   521,   281,
     282,   369,   461,   462,   463,   526,   283,   284,   370,   467,
     530,   285,   286,   372,   471,   472,   473,   535,   536,   537,
     580,   607,   608,   609,   610,   611,   111,   175,   293,   294,
     295,   296,   297,   298,   373,   374,   477,   478,   540,   588,
     589,   590,   591,   615,   616,   655,   656,   657,   658,   659,
     660,   684,   685,   686,   708,   709,   710,   738,   769,   770,
     771,   772,   649,   678,   700,   728,   729,   730,   752,   753,
     782,   808,   809,   810,   833,   834,   835,   862,   933,   780,
     802,   850,   880,   912,   804,   828,   882,   916,   967,   829,
     856,   917,   857,   883,   884,   925,   926,   927,   928,   929,
     970,  1012,  1051,  1052,  1075,  1093,   702,   732,   757,   758,
     759,   785,   813,   864,   890,   935,  1020,   814,   841,   842,
     865,   900,   901,   902,   903,   904,   905,   936,   981,   982,
    1022,  1059,   734,   761,   789,   790,   791,   817,   845,   907,
     944,   988,  1063,   846,   871,   872,   908,   954,   955,   956,
     957,   958,   959,   989,  1028,  1029,  1065,  1087,   763,   793,
     873,   848,   876,   910,   962,  1002,  1003,  1004,  1005,  1006,
     994,  1038,  1039,  1040,  1088,   795,   479,   539,   584,   613,
     647,   674,   696,   719,   720,   721,   722,   723,   711,   743,
     744,   745,   799,   343,   135,  1081,   198,   136
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1025
static const yytype_int16 yypact[] =
{
      44,    30,    45,     8, -1025,    56, -1025,    67,    49, -1025,
   -1025, -1025,   125,    38,   -24, -1025, -1025,   138,    54, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025,   308, -1025,   144, -1025,   175, -1025,   212, -1025,   222,
   -1025,   279, -1025,   353, -1025,   355, -1025,    91,   -16, -1025,
   -1025,   357,    74,   133,   164, -1025,   177, -1025,   359,   308,
   -1025, -1025, -1025, -1025,    27, -1025, -1025,    12, -1025, -1025,
      13, -1025, -1025,    29, -1025, -1025,    17, -1025, -1025,    11,
   -1025, -1025,     0, -1025, -1025, -1025,   361, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025,   363, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025,   346, -1025,   168,   -17, -1025, -1025,
   -1025,   150,   196, -1025, -1025,   -51, -1025, -1025, -1025, -1025,
   -1025,   127, -1025,   113, -1025,   146, -1025,   179, -1025,   162,
   -1025,   171, -1025,   157, -1025,   296,    -6,    47, -1025, -1025,
   -1025, -1025,    10, -1025, -1025,   158,   221,   242,   318, -1025,
     301, -1025, -1025,   370, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025,   372, -1025,   374, -1025,   376, -1025,   378,
   -1025,   380, -1025,   329,   -35,   320, -1025,   331, -1025, -1025,
   -1025, -1025,   -48, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025,   108, -1025, -1025,   266, -1025,   386,   395, -1025,   405,
   -1025, -1025, -1025,   388,   421, -1025,   466, -1025, -1025, -1025,
     390,   469, -1025,   479, -1025, -1025, -1025, -1025,   354,   407,
     182, -1025, -1025, -1025, -1025,    33, -1025, -1025,     4, -1025,
   -1025,    -3, -1025, -1025,     1, -1025, -1025,    16, -1025, -1025,
   -1025,   389, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025,   391, -1025,   396, -1025,
     401, -1025,   406, -1025,   410, -1025,   465, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025,   472, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025,   140, -1025, -1025, -1025,   178, -1025, -1025, -1025,
     423, -1025, -1025, -1025, -1025,   425, -1025, -1025, -1025, -1025,
     428, -1025, -1025, -1025, -1025,   432, -1025, -1025, -1025,   203,
   -1025, -1025,   411, -1025,   417, -1025,   356, -1025,   352, -1025,
   -1025, -1025, -1025,   377,   495,   213, -1025, -1025, -1025, -1025,
      15, -1025, -1025,     7, -1025, -1025,    14, -1025, -1025,    26,
   -1025, -1025,    39, -1025, -1025,   494,   412,   254,   261,   263,
     273, -1025,   416,   450,   -65,   498,   500,   502,   503, -1025,
   -1025, -1025, -1025,   375, -1025,   508, -1025,   509, -1025, -1025,
   -1025, -1025,   408, -1025,   510, -1025,   511,   513, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025,   205, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025,   214, -1025, -1025,   387,
   -1025,   384, -1025,   402, -1025,   458, -1025,   436, -1025,   514,
   -1025, -1025, -1025,   422,   519, -1025,   521, -1025, -1025, -1025,
     424,   522, -1025,   523, -1025, -1025, -1025,   426,   524, -1025,
     528, -1025, -1025, -1025,   526,   530, -1025, -1025,   529,   228,
   -1025, -1025, -1025, -1025, -1025,   515, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025,   531,   532, -1025, -1025, -1025,
   -1025,   430, -1025,   533, -1025,   538,   539, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025,   210, -1025, -1025, -1025,
   -1025, -1025,   535,    20, -1025, -1025,   381, -1025, -1025, -1025,
   -1025,   392, -1025, -1025, -1025, -1025,   393, -1025, -1025, -1025,
     397, -1025, -1025, -1025, -1025,   229, -1025, -1025, -1025,   427,
     124, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
     438, -1025,   546, -1025,   547,   548, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
     215,   549, -1025, -1025, -1025,   434, -1025,   550, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,   230,
     452, -1025,   551, -1025,   553,   554, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025,   -68, -1025,   456,   319,   552, -1025, -1025,
   -1025, -1025,     6, -1025,   557, -1025,   558, -1025,   559, -1025,
     560, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,   429,   403,
     561,   563, -1025,   567, -1025,   431,   319, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025,   440,   564,   565,   566,
     568, -1025, -1025, -1025,   433,    28, -1025,   556,   471,   569,
   -1025, -1025,   219, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025,   283,   481, -1025, -1025,
     435,   562,   504,   573, -1025, -1025, -1025, -1025,   223, -1025,
   -1025,    40,   575,   581, -1025,   582, -1025,   584, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025,   583,   442, -1025, -1025, -1025,
   -1025, -1025,   437,   571,   480, -1025, -1025, -1025,   271,   585,
   -1025, -1025, -1025, -1025, -1025, -1025,   587,   586,   588,   589,
   -1025, -1025,   444,   574,   593,   448, -1025, -1025, -1025, -1025,
   -1025,   439,   590,   482,   473, -1025,   592, -1025,   598, -1025,
   -1025, -1025, -1025, -1025,   595, -1025, -1025, -1025, -1025,   579,
     534, -1025,   441, -1025,   576, -1025,   603,   527, -1025, -1025,
   -1025, -1025,   604,   443, -1025, -1025, -1025,   605,   606,   570,
   -1025, -1025,   445,   591, -1025,   609,   189, -1025, -1025, -1025,
   -1025, -1025, -1025,   447,   -19, -1025,   607, -1025,   610, -1025,
   -1025, -1025, -1025, -1025,   614, -1025, -1025, -1025,   449,   -60,
   -1025, -1025, -1025,   201, -1025,   594,   615, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025,   451,   -37, -1025,   249, -1025,
     304,   616, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025,   617, -1025,   -64,   160,   618, -1025, -1025, -1025,
   -1025, -1025, -1025,   620, -1025, -1025, -1025, -1025, -1025,   596,
   -1025, -1025,   -49, -1025,   244,   624,   459, -1025,   597, -1025,
   -1025, -1025, -1025, -1025,   628, -1025,   629, -1025,   630, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025,   -23,   195, -1025,
     457, -1025,   460, -1025, -1025,   611, -1025,   464, -1025,   631,
   -1025,   632, -1025,   633, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025,   477, -1025,   634,   -27,   635, -1025, -1025,
   -1025, -1025,   613, -1025, -1025, -1025, -1025, -1025,   636, -1025,
     640, -1025,   642, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025,   294,   643,     3, -1025, -1025,   638, -1025, -1025,
   -1025,   644, -1025, -1025, -1025, -1025, -1025,   645,   470, -1025,
   -1025, -1025,   623, -1025, -1025, -1025, -1025, -1025,   646,   -32,
     647, -1025, -1025, -1025,    46,   649,   651, -1025,   652, -1025,
     655, -1025, -1025, -1025, -1025, -1025, -1025, -1025,   485, -1025,
     653,   656,   -33, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
     572, -1025,   468, -1025,   657,   474, -1025, -1025, -1025,   637,
   -1025, -1025, -1025, -1025,   659, -1025, -1025, -1025, -1025, -1025,
   -1025,   661,   654,   664, -1025, -1025, -1025, -1025,   512, -1025,
   -1025, -1025,   648, -1025, -1025, -1025,   663,    22, -1025, -1025,
   -1025, -1025, -1025,   599, -1025,   476, -1025, -1025,   666, -1025,
   -1025, -1025, -1025, -1025, -1025,   478, -1025, -1025, -1025, -1025,
   -1025,   580, -1025, -1025,   669,    51, -1025, -1025,   602, -1025,
     672,     2, -1025, -1025, -1025, -1025, -1025, -1025,   608, -1025,
   -1025, -1025,   520, -1025, -1025, -1025, -1025
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
     621, -1025, -1025, -1025, -1025, -1025, -1025, -1025,   483, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025,   486, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
     360, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025,   256, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,   148, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025,    34, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025,   -22, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025,  -149, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025, -1025,
   -1025, -1025, -1025, -1025,  -113, -1024, -1025, -1025
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     178,   179,   193,   336,   133,   338,  1077,  1008,  1078,  1079,
     334,   431,   663,   664,   204,   131,   123,   125,   433,   429,
     252,   129,   340,   341,   914,    19,  1077,   253,  1078,  1079,
     435,   121,   697,   127,   888,    87,   154,   332,   180,   229,
       4,   300,   869,   437,  1026,     6,   854,   645,    88,   475,
      89,   254,    90,   942,    91,  1077,     7,  1078,  1079,   476,
     646,  1098,   943,   155,    20,   156,     9,  1102,    21,   870,
      22,   979,    23,   255,  1049,  1027,     5,    10,    11,   303,
     980,   256,   839,   181,    24,   335,   181,   840,     1,   436,
      17,   157,    92,   889,    25,   257,    26,   258,   739,    12,
     740,   741,    27,   855,  1034,   158,  1035,  1036,    51,   259,
      85,   915,   130,   260,   323,   261,   333,   262,    28,   263,
      93,  1080,   128,   159,   122,   698,   438,  1050,  1097,   160,
     110,   434,   126,   124,   585,    15,    16,   344,   132,   342,
     432,   112,   339,   134,   337,   665,   430,   205,    49,    50,
     383,   384,   586,   199,    64,    65,   200,  1037,   563,   194,
     195,   196,   197,  1101,  1009,   564,   587,   113,   206,   742,
     891,   892,   385,   386,   387,   893,   375,   376,   377,   378,
     114,   379,   380,   381,   382,    67,    68,   152,   392,   393,
     207,   208,   894,   895,   896,   897,   209,   176,   405,   406,
     898,   899,   177,   408,   409,   945,   946,   947,   411,   412,
     394,   395,   396,   414,   199,   491,   492,   304,   397,   398,
     550,   551,    70,    71,   185,   600,   601,   948,   949,   950,
     951,   213,    73,    74,   186,   952,   953,   493,   494,   495,
     622,   623,   552,   553,   554,   496,   497,   602,   603,   604,
     555,   556,   220,   214,   215,   605,   606,   189,   468,   216,
     624,   625,   626,   627,   443,   187,   628,   629,   630,   631,
     918,   450,   188,   457,   221,   222,   919,   920,   921,   922,
     223,   764,   765,   464,   923,   924,   444,   445,   327,    76,
      77,   328,   446,   451,   452,   458,   459,   712,   190,   453,
     191,   460,   192,   766,   767,   465,   466,   768,   995,   327,
     503,   228,   415,   713,   714,   715,   716,   717,   718,   424,
     424,   227,   425,   504,   996,   997,   998,   999,  1000,  1001,
     287,   288,    53,   289,   533,   533,   290,   534,   578,   299,
      54,    55,   291,   650,    56,    57,   831,   292,   250,   832,
     706,   651,   652,   707,   736,   653,   654,   707,   859,   874,
     324,   832,   875,    79,    80,    82,    83,   108,   109,   115,
     116,   137,   138,   142,   143,   543,   544,   545,   148,   149,
     230,   231,   235,   236,   238,   239,   241,   242,   244,   245,
     247,   248,   308,   309,   313,   314,   318,   319,   311,   345,
     346,   350,   351,   307,   567,   568,   353,   354,   312,   570,
     571,   356,   357,   326,   573,   574,   359,   360,   576,   577,
     362,   363,   440,   441,   316,   581,   469,   470,   514,   515,
     519,   520,   524,   525,   592,   593,   594,   582,   583,   675,
     676,   682,   683,   694,   695,   726,   727,   755,   756,   787,
     788,   806,   807,   819,   820,   825,   826,   837,   838,   852,
     853,   867,   868,   878,   879,   931,   932,   960,   961,   317,
     964,   965,   321,   617,   968,   969,  1018,  1019,  1057,  1058,
    1061,  1062,   322,   619,   620,   621,  1085,  1086,  1091,  1092,
     365,   371,   404,   421,   418,   410,   407,   413,   419,   644,
     422,   423,   439,   420,   480,   662,   481,   474,   482,   483,
     484,   485,   486,   488,   489,   487,   490,   508,   507,   509,
     512,   510,   517,   511,   518,   522,   523,   527,   671,   672,
     673,   528,   529,   531,   566,   532,   547,   546,   538,   541,
     542,   548,   549,   562,   572,   595,   575,   569,   688,   596,
     597,   598,   648,   618,   641,   612,   642,   643,   661,   640,
     667,   668,   669,   670,   614,   677,   680,   704,   705,   679,
     681,   701,   690,   691,   692,   703,   693,   699,   724,   689,
     731,   735,   733,   746,   747,   748,   725,   749,   760,   750,
     773,   812,   762,   774,   775,   797,   776,   777,   751,   783,
     781,   798,   779,   800,   784,   801,   803,   794,   796,   815,
     792,   816,   818,   821,   822,   830,   847,   827,   754,   844,
     849,   863,   881,   861,   906,   911,   934,   886,   909,   823,
     930,   938,   939,   940,   972,   973,   974,   778,   976,   991,
     966,   983,   987,   992,   978,   993,  1046,   786,  1011,  1007,
    1013,  1017,  1021,  1030,  1042,  1043,  1025,  1041,  1044,  1047,
    1048,  1099,  1069,  1060,  1067,   301,  1064,  1068,   805,  1076,
     811,  1055,  1070,  1073,  1089,  1096,  1083,  1074,  1100,  1095,
     120,  1106,   505,   579,   860,  1104,   737,   305,   824,   416,
     687,     0,     0,     0,     0,     0,     0,     0,     0,   836,
       0,     0,   843,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   851,     0,     0,   858,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   866,     0,     0,     0,     0,   877,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   885,     0,
     887,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   913,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     937,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   941,     0,     0,     0,     0,   963,     0,
       0,     0,     0,     0,     0,   971,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   975,     0,     0,
       0,   977,     0,     0,     0,   984,   985,   986,     0,     0,
       0,     0,     0,     0,   990,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1010,     0,     0,     0,     0,     0,  1014,
    1015,  1016,     0,     0,     0,     0,     0,     0,     0,     0,
    1023,     0,     0,     0,  1024,     0,     0,     0,  1031,  1032,
    1033,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1045,     0,     0,     0,     0,     0,
    1053,     0,     0,     0,  1054,     0,     0,     0,  1056,     0,
       0,     0,     0,     0,     0,     0,     0,  1066,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1071,     0,     0,  1072,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1082,     0,     0,
       0,  1084,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1090,     0,  1094,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1103,     0,     0,     0,  1105
};

static const yytype_int16 yycheck[] =
{
     113,   114,     8,     6,     4,     4,     4,     4,     6,     7,
       6,     4,     6,     7,     4,     4,     4,     4,     4,     4,
      55,     4,     6,     7,    73,    49,     4,    62,     6,     7,
       4,     4,     4,     4,    98,    51,    53,     4,    89,   152,
      10,    89,    79,     4,    76,     0,   106,   115,    64,   114,
      66,    86,    68,    76,    70,     4,    48,     6,     7,   124,
     128,  1085,    85,    80,    88,    82,    10,  1091,    92,   106,
      94,    98,    96,   108,   107,   107,    46,    10,    11,   192,
     107,   116,   101,   134,   108,    81,   134,   106,    44,    63,
      52,   108,   108,   157,   118,   130,   120,   132,    58,    50,
      60,    61,   126,   163,    58,   122,    60,    61,    54,   144,
      19,   160,    95,   148,   227,   150,    83,   152,   142,   154,
     136,    99,    93,   140,    97,    97,    87,   160,    77,   146,
      56,   117,   119,   121,    10,    10,    11,   250,   127,   123,
     133,     8,   141,   143,   147,   139,   131,   137,    10,    11,
      10,    11,    28,   106,    10,    11,   109,   111,   138,   165,
     166,   167,   168,   161,   161,   145,    42,     3,    10,   129,
      10,    11,    32,    33,    34,    15,   289,   290,   291,   292,
       3,   294,   295,   296,   297,    10,    11,    19,    10,    11,
      32,    33,    32,    33,    34,    35,    38,    47,   311,   312,
      40,    41,     6,   316,   317,    10,    11,    12,   321,   322,
      32,    33,    34,   326,   106,    10,    11,   109,    40,    41,
      10,    11,    10,    11,    97,    10,    11,    32,    33,    34,
      35,    10,    10,    11,   121,    40,    41,    32,    33,    34,
      10,    11,    32,    33,    34,    40,    41,    32,    33,    34,
      40,    41,    10,    32,    33,    40,    41,    95,   371,    38,
      30,    31,    32,    33,    10,   119,    36,    37,    38,    39,
      26,    10,    93,    10,    32,    33,    32,    33,    34,    35,
      38,    10,    11,    10,    40,    41,    32,    33,   106,    10,
      11,   109,    38,    32,    33,    32,    33,    14,   127,    38,
     143,    38,     6,    32,    33,    32,    33,    36,    14,   106,
     423,    10,   109,    30,    31,    32,    33,    34,    35,   106,
     106,     3,   109,   109,    30,    31,    32,    33,    34,    35,
      10,    11,    24,    13,   106,   106,    16,   109,   109,     8,
      32,    33,    22,    24,    36,    37,   157,    27,    19,   160,
     131,    32,    33,   134,   131,    36,    37,   134,   157,   110,
       6,   160,   113,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,   488,   489,   490,    32,    33,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,     6,     7,     6,     7,     6,     7,     3,    10,
      11,    10,    11,   137,   517,   518,    10,    11,     3,   522,
     523,    10,    11,     6,   527,   528,    10,    11,   531,   532,
      10,    11,    10,    11,     3,   538,    10,    11,     6,     7,
       6,     7,     6,     7,   547,   548,   549,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   159,   160,     6,     7,    10,    11,     3,
      10,    11,     3,   586,    10,    11,     6,     7,    10,    11,
       6,     7,     3,   596,   597,   598,    10,    11,    10,    11,
      25,    19,    69,   141,    83,    67,    71,    65,    81,   612,
     123,     6,     8,   147,     6,   618,     6,    57,     6,     6,
     135,     3,     3,     3,     3,   107,     3,   133,   131,   117,
       6,    63,     3,    87,     3,     3,     3,     3,   641,   642,
     643,     3,     6,     3,   153,     6,     3,   107,    23,     8,
       8,     3,     3,     8,   151,   107,   149,   155,   661,     3,
       3,     3,    96,     3,     3,     6,     3,     3,     6,   107,
       3,     3,     3,     3,   130,   162,     3,   680,   681,     8,
       3,   100,     8,     8,     8,     6,     8,    21,    97,   139,
      18,     8,    78,     8,     3,     3,   699,     3,    17,     6,
       5,    15,   112,     6,     8,     3,     8,     8,   156,     6,
      26,     3,   158,     8,   156,    26,    72,   125,   135,     6,
      20,    84,     8,     8,     8,     6,     6,    26,   731,    12,
       6,     6,     6,    29,     6,    29,    29,    10,     8,    59,
       6,     3,     3,     3,     3,     3,     3,   750,   161,     3,
      29,     6,    29,     3,    10,     3,   161,   760,    10,     6,
       6,     6,    29,     6,     3,     3,    10,     8,     3,     6,
       4,    59,     8,     6,     5,   182,    29,     6,   781,     6,
     783,    99,     8,   161,     8,     6,    77,    29,     6,    99,
      59,   161,   426,   535,   833,    77,   708,   201,   801,   329,
     656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   812,
      -1,    -1,   815,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   827,    -1,    -1,   830,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   844,    -1,    -1,    -1,    -1,   849,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   861,    -1,
     863,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   881,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     893,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   906,    -1,    -1,    -1,    -1,   911,    -1,
      -1,    -1,    -1,    -1,    -1,   918,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   930,    -1,    -1,
      -1,   934,    -1,    -1,    -1,   938,   939,   940,    -1,    -1,
      -1,    -1,    -1,    -1,   947,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   966,    -1,    -1,    -1,    -1,    -1,   972,
     973,   974,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     983,    -1,    -1,    -1,   987,    -1,    -1,    -1,   991,   992,
     993,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1007,    -1,    -1,    -1,    -1,    -1,
    1013,    -1,    -1,    -1,  1017,    -1,    -1,    -1,  1021,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1030,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1044,    -1,    -1,  1047,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1060,    -1,    -1,
      -1,  1064,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1074,    -1,  1076,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1096,    -1,    -1,    -1,  1100
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   230,   173,    10,    11,    52,   277,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   176,   194,   195,   197,   198,   200,   201,   203,   204,
     206,   207,   209,   210,   212,   213,   215,   216,   231,    10,
      11,    54,   310,    24,    32,    33,    36,    37,   177,   178,
     179,   180,   181,   182,    10,    11,   196,    10,    11,   199,
      10,    11,   202,    10,    11,   205,    10,    11,   208,    10,
      11,   211,    10,    11,   214,    19,   217,    51,    64,    66,
      68,    70,   108,   136,   232,   233,   234,   236,   237,   243,
     244,   250,   251,   257,   258,   262,   263,   278,    10,    11,
      56,   385,     8,     3,     3,    10,    11,   183,   184,   185,
     179,     4,    97,     4,   121,     4,   119,     4,    93,     4,
      95,     4,   127,     4,   143,   553,   556,    10,    11,   218,
     219,   220,    10,    11,   235,   238,   245,   252,    32,    33,
     259,   260,    19,   264,    53,    80,    82,   108,   122,   140,
     146,   279,   280,   281,   283,   284,   286,   287,   289,   290,
     292,   293,   295,   296,   311,   386,    47,     6,   553,   553,
      89,   134,   186,   187,   188,    97,   121,   119,    93,    95,
     127,   143,     6,     8,   165,   166,   167,   168,   555,   106,
     109,   221,   222,   223,     4,   137,    10,    32,    33,    38,
     239,   240,   241,    10,    32,    33,    38,   246,   247,   248,
      10,    32,    33,    38,   253,   254,   255,     3,    10,   553,
      10,    11,   265,   266,   267,    10,    11,   282,    10,    11,
     285,    10,    11,   288,    10,    11,   291,    10,    11,   294,
      19,   297,    55,    62,    86,   108,   116,   130,   132,   144,
     148,   150,   152,   154,   312,   313,   314,   316,   317,   319,
     320,   322,   323,   325,   326,   328,   329,   344,   345,   351,
     352,   358,   359,   365,   366,   370,   371,    10,    11,    13,
      16,    22,    27,   387,   388,   389,   390,   391,   392,     8,
      89,   187,   189,   553,   109,   222,   224,   137,     6,     7,
     242,     3,     3,     6,     7,   249,     3,     3,     6,     7,
     256,     3,     3,   553,     6,   261,     6,   106,   109,   268,
     269,   270,     4,    83,     6,    81,     6,   147,     4,   141,
       6,     7,   123,   552,   553,    10,    11,   298,   299,   300,
      10,    11,   315,    10,    11,   318,    10,    11,   321,    10,
      11,   324,    10,    11,   327,    25,   330,   346,   353,   360,
     367,    19,   372,   393,   394,   553,   553,   553,   553,   553,
     553,   553,   553,    10,    11,    32,    33,    34,   190,   191,
     192,   193,    10,    11,    32,    33,    34,    40,    41,   225,
     226,   227,   228,   229,    69,   553,   553,    71,   553,   553,
      67,   553,   553,    65,   553,   109,   269,   271,    83,    81,
     147,   141,   123,     6,   106,   109,   301,   302,   303,     4,
     131,     4,   133,     4,   117,     4,    63,     4,    87,     8,
      10,    11,   331,    10,    32,    33,    38,   347,   348,   349,
      10,    32,    33,    38,   354,   355,   356,    10,    32,    33,
      38,   361,   362,   363,    10,    32,    33,   368,   553,    10,
      11,   373,   374,   375,    57,   114,   124,   395,   396,   535,
       6,     6,     6,     6,   135,     3,     3,   107,     3,     3,
       3,    10,    11,    32,    33,    34,    40,    41,   272,   273,
     274,   275,   276,   553,   109,   302,   304,   131,   133,   117,
      63,    87,     6,   332,     6,     7,   350,     3,     3,     6,
       7,   357,     3,     3,     6,     7,   364,     3,     3,     6,
     369,     3,     6,   106,   109,   376,   377,   378,    23,   536,
     397,     8,     8,   553,   553,   553,   107,     3,     3,     3,
      10,    11,    32,    33,    34,    40,    41,   305,   306,   307,
     308,   309,     8,   138,   145,   333,   153,   553,   553,   155,
     553,   553,   151,   553,   553,   149,   553,   553,   109,   377,
     379,   553,    10,    11,   537,    10,    28,    42,   398,   399,
     400,   401,   553,   553,   553,   107,     3,     3,     3,   334,
      10,    11,    32,    33,    34,    40,    41,   380,   381,   382,
     383,   384,     6,   538,   130,   402,   403,   553,     3,   553,
     553,   553,    10,    11,    30,    31,    32,    33,    36,    37,
      38,    39,   335,   336,   337,   338,   339,   340,   341,   342,
     107,     3,     3,     3,   553,   115,   128,   539,    96,   421,
      24,    32,    33,    36,    37,   404,   405,   406,   407,   408,
     409,     6,   553,     6,     7,   139,   343,     3,     3,     3,
       3,   553,   553,   553,   540,    10,    11,   162,   422,     8,
       3,     3,    10,    11,   410,   411,   412,   406,   553,   139,
       8,     8,     8,     8,    10,    11,   541,     4,    97,    21,
     423,   100,   465,     6,   553,   553,   131,   134,   413,   414,
     415,   547,    14,    30,    31,    32,    33,    34,    35,   542,
     543,   544,   545,   546,    97,   553,    10,    11,   424,   425,
     426,    18,   466,    78,   491,     8,   131,   414,   416,    58,
      60,    61,   129,   548,   549,   550,     8,     3,     3,     3,
       6,   156,   427,   428,   553,    10,    11,   467,   468,   469,
      17,   492,   112,   517,    10,    11,    32,    33,    36,   417,
     418,   419,   420,     5,     6,     8,     8,     8,   553,   158,
     438,    26,   429,     6,   156,   470,   553,    10,    11,   493,
     494,   495,    20,   518,   125,   534,   135,     3,     3,   551,
       8,    26,   439,    72,   443,   553,    10,    11,   430,   431,
     432,   553,    15,   471,   476,     6,    84,   496,     8,    10,
      11,     8,     8,    59,   553,    10,    11,    26,   444,   448,
       6,   157,   160,   433,   434,   435,   553,    10,    11,   101,
     106,   477,   478,   553,    12,   497,   502,     6,   520,     6,
     440,   553,    10,    11,   106,   163,   449,   451,   553,   157,
     434,    29,   436,     6,   472,   479,   553,    10,    11,    79,
     106,   503,   504,   519,   110,   113,   521,   553,   159,   160,
     441,     6,   445,   452,   453,   553,    10,   553,    98,   157,
     473,    10,    11,    15,    32,    33,    34,    35,    40,    41,
     480,   481,   482,   483,   484,   485,     6,   498,   505,     8,
     522,    29,   442,   553,    73,   160,   446,   450,    26,    32,
      33,    34,    35,    40,    41,   454,   455,   456,   457,   458,
       6,     6,     7,   437,    29,   474,   486,   553,     3,     3,
       3,   553,    76,    85,   499,    10,    11,    12,    32,    33,
      34,    35,    40,    41,   506,   507,   508,   509,   510,   511,
      10,    11,   523,   553,    10,    11,    29,   447,    10,    11,
     459,   553,     3,     3,     3,   553,   161,   553,    10,    98,
     107,   487,   488,     6,   553,   553,   553,    29,   500,   512,
     553,     3,     3,     3,   529,    14,    30,    31,    32,    33,
      34,    35,   524,   525,   526,   527,   528,     6,     4,   161,
     553,    10,   460,     6,   553,   553,   553,     6,     6,     7,
     475,    29,   489,   553,   553,    10,    76,   107,   513,   514,
       6,   553,   553,   553,    58,    60,    61,   111,   530,   531,
     532,     8,     3,     3,     3,   553,   161,     6,     4,   107,
     160,   461,   462,   553,   553,    99,   553,    10,    11,   490,
       6,     6,     7,   501,    29,   515,   553,     5,     6,     8,
       8,   553,   553,   161,    29,   463,     6,     4,     6,     7,
      99,   554,   553,    77,   553,    10,    11,   516,   533,     8,
     553,    10,    11,   464,   553,    99,     6,    77,   554,    59,
       6,   161,   554,   553,    77,   553,   161
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
		std::cout << "allocated generalStatus" << std::endl;
		parserData->generalStatusPresent = true;
		parserData->generalStatusTypePresent = false;
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
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
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
	osresult->setGeneralSubstatusName(parserData->kounter,(yyvsp[(2) - (3)].sval));
	
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

  case 51:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 52:

    {osresult->setGeneralMessage((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 56:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 57:

    {osresult->setServiceURI((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 61:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 62:

    {osresult->setServiceName((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 66:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 67:

    {osresult->setInstanceName((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 71:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 72:

    {osresult->setJobID((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 76:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 77:

    {osresult->setSolverInvoked((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 81:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 82:

    {osresult->setTimeStamp((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 86:

    {	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	;}
    break;

  case 87:

    {	osresult->setNumberOfOtherGeneralResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 88:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 89:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 95:

    {	if (!parserData->generalOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->generalOtherResultNamePresent = false;
	parserData->generalOtherResultValuePresent = false;
	parserData->generalOtherResultDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 96:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 99:

    {	if (parserData->generalOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->generalOtherResultNamePresent = true;
		osresult->setGeneralOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 100:

    {	if (parserData->generalOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->generalOtherResultValuePresent = true;
		osresult->setGeneralOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 101:

    {	if (parserData->generalOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->generalOtherResultDescriptionPresent = true;
		osresult->setGeneralOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 102:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 103:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 104:

    {parserData->tempStr = "";}
    break;

  case 105:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 106:

    {parserData->tempStr = "";}
    break;

  case 121:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 122:

    {osresult->setSystemInformation((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 126:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;		
	;}
    break;

  case 131:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "petabyte" && parserData->tempStr != "terabyte" &&
	    parserData->tempStr != "gigabyte" && parserData->tempStr != "megabyte" && 
	    parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
	osresult->setAvailableDiskSpaceUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 132:

    {	osresult->setAvailableDiskSpaceDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 134:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 135:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 137:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
	;}
    break;

  case 142:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "availableMemory unit not recognized");
	osresult->setAvailableMemoryUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 143:

    {	osresult->setAvailableMemoryDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 145:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 146:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 148:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
	;}
    break;

  case 153:

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

  case 154:

    {	osresult->setAvailableCPUSpeedDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 156:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 157:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 159:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
	;}
    break;

  case 162:

    {	osresult->setAvailableCPUNumberDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 164:

    {osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 166:

    {	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	;}
    break;

  case 167:

    {	osresult->setNumberOfOtherSystemResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 168:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 169:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 175:

    {	if (!parserData->systemOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->systemOtherResultNamePresent = false;
	parserData->systemOtherResultValuePresent = false;
	parserData->systemOtherResultDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 176:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 179:

    {	if (parserData->systemOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->systemOtherResultNamePresent = true;
		osresult->setSystemOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 180:

    {	if (parserData->systemOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->systemOtherResultValuePresent = true;
		osresult->setSystemOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 181:

    {	if (parserData->systemOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->systemOtherResultDescriptionPresent = true;
		osresult->setSystemOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 182:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 183:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 184:

    {parserData->tempStr = "";}
    break;

  case 185:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 186:

    {parserData->tempStr = "";}
    break;

  case 201:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 202:

    {osresult->setCurrentState((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 206:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 207:

    {osresult->setCurrentJobCount((yyvsp[(2) - (3)].ival)); /* free($2); */  parserData->errorText = NULL;;}
    break;

  case 211:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 212:

    {osresult->setTotalJobsSoFar((yyvsp[(2) - (3)].ival)); /* free($2); */  parserData->errorText = NULL;;}
    break;

  case 216:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 217:

    {osresult->setTimeServiceStarted((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 221:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 222:

    {osresult->setServiceUtilization( parserData->tempVal);  parserData->errorText = NULL;;}
    break;

  case 226:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	;}
    break;

  case 227:

    {	osresult->setNumberOfOtherServiceResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 228:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 229:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 235:

    {	if (!parserData->serviceOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->serviceOtherResultNamePresent = false;
	parserData->serviceOtherResultValuePresent = false;
	parserData->serviceOtherResultDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 236:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 239:

    {	if (parserData->serviceOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->serviceOtherResultNamePresent = true;
		osresult->setServiceOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 240:

    {	if (parserData->serviceOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->serviceOtherResultValuePresent = true;
		osresult->setServiceOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 241:

    {	if (parserData->serviceOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->serviceOtherResultDescriptionPresent = true;
		osresult->setServiceOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 242:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 243:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 244:

    {parserData->tempStr = "";}
    break;

  case 245:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 246:

    {parserData->tempStr = "";;}
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

  case 326:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "petabyte" && parserData->tempStr != "terabyte" &&
	    parserData->tempStr != "gigabyte" && parserData->tempStr != "megabyte" && 
	    parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedDiskSpace unit not recognized");
	osresult->setUsedDiskSpaceUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 327:

    {	osresult->setUsedDiskSpaceDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 329:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 330:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 332:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
	;}
    break;

  case 337:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedMemory unit not recognized");
	osresult->setUsedMemoryUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 338:

    {	osresult->setUsedMemoryDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 340:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 341:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 343:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
	;}
    break;

  case 348:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "terahertz" && parserData->tempStr != "gigahertz" && 
		parserData->tempStr != "megahertz" && parserData->tempStr != "kilohertz" && 
		parserData->tempStr != "hertz"     && parserData->tempStr != "petaflops" && 
		parserData->tempStr != "teraflops" && parserData->tempStr != "gigaflops" && 
		parserData->tempStr != "megaflops" && parserData->tempStr != "kiloflops" && 
		parserData->tempStr != "flops" )
		osrlerror(NULL, NULL, parserData, "usedCPUSpeed unit not recognized");
	osresult->setUsedCPUSpeedUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 349:

    {	osresult->setUsedCPUSpeedDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 351:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 352:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 354:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
	;}
    break;

  case 357:

    {	osresult->setUsedCPUNumberDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 359:

    {osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 361:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	;}
    break;

  case 362:

    {	osresult->setNumberOfOtherJobResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 363:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 364:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 370:

    {	if (!parserData->jobOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->jobOtherResultNamePresent = false;
	parserData->jobOtherResultValuePresent = false;
	parserData->jobOtherResultDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 371:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 374:

    {	if (parserData->jobOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->jobOtherResultNamePresent = true;
		osresult->setJobOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 375:

    {	if (parserData->jobOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->jobOtherResultValuePresent = true;
		osresult->setJobOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 376:

    {	if (parserData->jobOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->jobOtherResultDescriptionPresent = true;
		osresult->setJobOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 377:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 378:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 379:

    {parserData->tempStr = "";}
    break;

  case 380:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 381:

    {parserData->tempStr = "";}
    break;

  case 392:

    {	if (parserData->numberOfSolutionsPresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	parserData->numberOfSolutionsPresent = true;
	parserData->numberOfSolutions = (yyvsp[(3) - (3)].ival); 
	osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 393:

    {	if (parserData->numberOfVariablesPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	parserData->numberOfVariablesPresent = true;	
	parserData->numberOfVariables = (yyvsp[(3) - (3)].ival); 
	osresult->setVariableNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 394:

    {	if (parserData->numberOfConstraintsPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	parserData->numberOfConstraintsPresent = true;		
	parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); 
	osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 395:

    {	if (parserData->numberOfObjectivesPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	parserData->numberOfObjectivesPresent = true;
	parserData->numberOfObjectives = (yyvsp[(3) - (3)].ival); 
	osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 401:

    {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   ;}
    break;

  case 402:

    {   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
	parserData->targetObjectiveIdxPresent = false;
	parserData->weightedObjectivesPresent = false;
;}
    break;

  case 407:

    {	if (parserData->targetObjectiveIdxPresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->targetObjectiveIdxPresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 408:

    {	if (parserData->weightedObjectivesPresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjectivesPresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval);
  	osresult->setSolutionWeightedObjectives(parserData->solutionIdx, parserData->tempStr);
;}
    break;

  case 411:

    {	parserData->solutionStatusTypePresent = false;
		parserData->solutionStatusDescriptionPresent = false;
		parserData->solutionStatusNumberOfPresent = false;
		parserData->numberOf = 0;
	;}
    break;

  case 412:

    {	if (!parserData->solutionStatusTypePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
		parserData->kounter = 0;
	;}
    break;

  case 415:

    {   if (parserData->solutionStatusTypePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one type attribute allowed for solution status element");
	    parserData->solutionStatusTypePresent = true;
	    if ((parserData->tempStr != "unbounded"     ) && (parserData->tempStr != "globallyOptimal") && 
	        (parserData->tempStr != "locallyOptimal") && (parserData->tempStr != "optimal") && 
	        (parserData->tempStr != "bestSoFar"     ) && (parserData->tempStr != "feasible") && 
	        (parserData->tempStr != "infeasible"    ) && (parserData->tempStr != "unsure") && 
	        (parserData->tempStr != "error"         ) && (parserData->tempStr != "other"))
			osrlerror(NULL, NULL, parserData, "solution status type does not matched any legal value");
		osresult->setSolutionStatusType(parserData->solutionIdx, parserData->tempStr); 
	;}
    break;

  case 416:

    {   if (parserData->solutionStatusDescriptionPresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for solution status element");
	    parserData->solutionStatusDescriptionPresent = true;
		osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->tempStr);
	;}
    break;

  case 418:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 419:

    { parserData->tempStr = "";          ;}
    break;

  case 420:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 421:

    { parserData->tempStr = "";          ;}
    break;

  case 422:

    {   if (parserData->solutionStatusNumberOfPresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for solution status element");
    parserData->solutionStatusNumberOfPresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solution substatuses cannot be negative");
    osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 423:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 424:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 430:

    {	if (!parserData->solutionSubstatusTypePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
	parserData->generalSubstatusNamePresent = false;
	parserData->generalSubstatusDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 431:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
;}
    break;

  case 435:

    {	if (parserData->solutionSubstatusDescriptionPresent)
		osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
	parserData->solutionSubstatusDescriptionPresent = true;
	osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,parserData->tempStr);
;}
    break;

  case 436:

    {	if (parserData->solutionSubstatusTypePresent)
		osrlerror(NULL, NULL, parserData, "type attribute multiply specified");
	parserData->solutionSubstatusTypePresent = true;
	osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter,(yyvsp[(2) - (3)].sval));	
;}
    break;

  case 437:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 438:

    {	parserData->tempStr = ""; ;}
    break;

  case 442:

    {	osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
	;}
    break;

  case 448:

    {  
		osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
		parserData->tmpOtherValue = "";
		parserData->tmpOtherName = "";
		parserData->tmpOtherDescription = "";
	;}
    break;

  case 455:

    {	parserData->numberOfVarPresent = false; ;}
    break;

  case 456:

    {	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
	parserData->kounter = 0;
	std::cout << "number of var: " << parserData->numberOfVar;
	std::cout << "; kounter = " << parserData->kounter << std::endl;
	osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar);
;}
    break;

  case 457:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 458:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 464:

    {	osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
	std::cout << "; kounter = " << parserData->kounter << std::endl;
;}
    break;

  case 465:

    {	
	std::cout << "number of var: " << parserData->numberOfVar;
	std::cout << "; kounter = " << parserData->kounter << std::endl;
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 466:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 467:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 468:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 470:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
     }
 */  ;}
    break;

  case 472:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 475:

    {/*parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  */
;}
    break;

  case 478:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 480:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
      }
 */  ;}
    break;

  case 482:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 486:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 489:

    {/*	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	*/;}
    break;

  case 490:

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

  case 491:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	;}
    break;

  case 492:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	;}
    break;

  case 499:

    {	
	parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);

//std::cout << "This \<other\> element has " << parserData->otherVarStruct->numberOfVar << " \<var\>" << std::endl;

	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 500:

    {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
;}
    break;

  case 501:

    {parserData->tmpOtherValue=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 502:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 503:

    {
parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 504:

    {
parserData->tmpOtherDescription=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 510:

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

  case 511:

    {//	if(parserData->otherVarStruct->numberOfVar <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	;}
    break;

  case 512:

    {;}
    break;

  case 519:

    {  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 525:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
;}
    break;

  case 527:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 531:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(3) - (4)].ival);   ;}
    break;

  case 532:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].ival);                  
	parserData->objVals.push_back( parserData->objValPair);
;}
    break;

  case 533:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->objVals.push_back( parserData->objValPair);
  ;}
    break;

  case 537:

    {  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	;}
    break;

  case 544:

    {
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
;}
    break;

  case 545:

    {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
;}
    break;

  case 546:

    {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 547:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherObjStruct->name = "";
;}
    break;

  case 548:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 549:

    {
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 552:

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

  case 555:

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

  case 556:

    {//	if(parserData->otherObjStruct->numberOfObj <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of objectives") ;
	;}
    break;

  case 557:

    {;}
    break;

  case 564:

    {  
/*        osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 570:

    {/*
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}*/
 ;}
    break;

  case 572:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 576:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 577:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 		
	;}
    break;

  case 578:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 	
	;}
    break;

  case 590:

    {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
;}
    break;

  case 591:

    {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 592:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherConStruct->name = "";
;}
    break;

  case 593:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 594:

    {
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 600:

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

  case 601:

    {//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	;}
    break;

  case 602:

    {;}
    break;

  case 607:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 608:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 609:

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

  case 613:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 614:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 616:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 622:

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

  case 623:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 624:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 625:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 627:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 630:

    {parserData->kounter++;;}
    break;

  case 631:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 632:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 635:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 637:

    {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
;}
    break;

  case 645:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
;}
    break;

  case 648:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/;}
    break;

  case 654:

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

  case 655:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
*/
;}
    break;

  case 656:

    {
/*	parserData->tmpOtherName=$2; parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
;}
    break;

  case 657:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
;}
    break;

  case 659:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
;}
    break;

  case 663:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/;}
    break;

  case 664:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/;}
    break;

  case 667:

    {/*parserData->itemContent = $2; free($2);*/;}
    break;

  case 669:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 670:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 672:

    { parserData->outStr << (yyvsp[(1) - (1)].sval);    free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 673:

    { parserData->outStr << (yyvsp[(1) - (1)].ival);  /*free($1);*/ ;}
    break;

  case 674:

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


