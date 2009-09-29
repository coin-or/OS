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
#define YYLAST   835

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  306
/* YYNRULES -- Number of rules.  */
#define YYNRULES  549
/* YYNRULES -- Number of states.  */
#define YYNSTATES  964

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
     215,   219,   223,   225,   227,   230,   232,   234,   236,   239,
     243,   244,   247,   249,   251,   253,   257,   261,   265,   268,
     270,   271,   274,   284,   285,   290,   294,   297,   303,   304,
     307,   309,   311,   315,   319,   321,   323,   329,   330,   333,
     335,   337,   341,   345,   347,   349,   355,   356,   359,   361,
     363,   367,   371,   373,   375,   381,   382,   385,   389,   391,
     393,   394,   398,   402,   404,   406,   409,   411,   413,   415,
     418,   422,   423,   426,   428,   430,   432,   436,   440,   444,
     447,   449,   450,   453,   463,   464,   469,   473,   476,   477,
     482,   486,   489,   490,   495,   499,   502,   503,   508,   512,
     515,   516,   521,   525,   528,   529,   533,   537,   539,   541,
     544,   546,   548,   550,   553,   557,   558,   561,   563,   565,
     567,   571,   575,   579,   582,   584,   585,   588,   593,   594,
     597,   599,   601,   603,   605,   607,   609,   611,   613,   615,
     617,   619,   624,   628,   631,   636,   640,   643,   648,   652,
     655,   660,   664,   667,   672,   676,   679,   683,   688,   690,
     694,   695,   698,   702,   703,   706,   708,   710,   712,   714,
     718,   720,   724,   726,   730,   732,   736,   738,   740,   742,
     745,   747,   751,   752,   754,   756,   762,   763,   766,   768,
     770,   774,   778,   780,   782,   788,   789,   792,   796,   798,
     800,   806,   807,   810,   812,   814,   818,   822,   824,   826,
     832,   833,   836,   838,   840,   844,   848,   850,   852,   856,
     860,   862,   864,   867,   869,   871,   873,   876,   880,   881,
     884,   886,   888,   890,   894,   898,   902,   905,   907,   908,
     912,   913,   916,   919,   922,   925,   928,   932,   936,   940,
     944,   948,   950,   953,   954,   957,   961,   963,   964,   967,
     969,   971,   976,   981,   990,   995,   999,  1001,  1004,  1008,
    1010,  1014,  1016,  1017,  1021,  1024,  1025,  1029,  1030,  1035,
    1037,  1039,  1041,  1048,  1049,  1055,  1060,  1061,  1064,  1070,
    1075,  1077,  1079,  1080,  1086,  1091,  1092,  1095,  1101,  1106,
    1108,  1110,  1111,  1117,  1122,  1123,  1126,  1132,  1137,  1139,
    1141,  1142,  1145,  1146,  1151,  1153,  1157,  1159,  1160,  1163,
    1165,  1167,  1169,  1171,  1176,  1178,  1182,  1184,  1188,  1192,
    1193,  1196,  1202,  1204,  1205,  1211,  1212,  1216,  1217,  1222,
    1224,  1226,  1228,  1233,  1239,  1244,  1245,  1248,  1254,  1259,
    1261,  1263,  1264,  1267,  1273,  1275,  1276,  1279,  1281,  1283,
    1285,  1287,  1292,  1294,  1298,  1300,  1304,  1308,  1309,  1312,
    1318,  1320,  1325,  1326,  1330,  1331,  1336,  1338,  1340,  1342,
    1347,  1353,  1358,  1359,  1362,  1368,  1373,  1375,  1377,  1378,
    1381,  1387,  1389,  1390,  1393,  1395,  1397,  1399,  1401,  1406,
    1408,  1412,  1414,  1418,  1422,  1423,  1426,  1432,  1434,  1439,
    1440,  1446,  1447,  1453,  1454,  1457,  1463,  1464,  1465,  1469,
    1471,  1473,  1475,  1477,  1482,  1484,  1488,  1492,  1494,  1498,
    1500,  1501,  1504,  1506,  1508,  1510,  1512,  1513,  1518,  1520,
    1521,  1525,  1530,  1532,  1536,  1537,  1540,  1546,  1547,  1548,
    1552,  1554,  1556,  1558,  1560,  1565,  1567,  1571,  1575,  1577,
    1581,  1583,  1584,  1587,  1588,  1592,  1594,  1596,  1599,  1601,
    1605,  1608,  1610,  1612,  1614,  1616,  1618,  1620,  1622,  1623
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
     184,    89,    -1,   185,    -1,   184,   185,    -1,    90,   186,
     190,    -1,    -1,   186,   187,    -1,   188,    -1,   189,    -1,
      34,     3,     8,    -1,    32,     3,     8,    -1,   191,    -1,
     192,    -1,    10,    91,    -1,    11,    -1,    10,     4,    91,
      -1,    96,    10,     4,    97,    -1,    96,    10,    97,    -1,
      96,    11,    -1,   120,    10,     4,   121,    -1,   120,    10,
     121,    -1,   120,    11,    -1,   118,    10,     4,   119,    -1,
     118,    10,   119,    -1,   118,    11,    -1,    92,    10,     4,
      93,    -1,    92,    10,    93,    -1,    92,    11,    -1,    94,
      10,     4,    95,    -1,    94,    10,    95,    -1,    94,    11,
      -1,   126,    10,     4,   127,    -1,   126,    10,   127,    -1,
     126,    11,    -1,   142,    10,     4,   143,    -1,   142,    10,
     143,    -1,   142,    11,    -1,   108,   201,   202,    -1,    19,
       6,   471,    -1,   203,    -1,   204,    -1,    10,   109,    -1,
      11,    -1,   205,    -1,   206,    -1,   205,   206,    -1,   106,
     207,   212,    -1,    -1,   207,   208,    -1,   209,    -1,   210,
      -1,   211,    -1,    34,     3,   471,    -1,    40,     3,   471,
      -1,    32,     3,   471,    -1,    10,   107,    -1,    11,    -1,
      -1,    50,    11,    -1,    50,    10,   214,   215,   221,   227,
     233,   237,    51,    -1,    -1,   136,    10,     4,   137,    -1,
     136,    10,   137,    -1,   136,    11,    -1,    68,   216,    10,
     220,    69,    -1,    -1,   216,   217,    -1,   218,    -1,   219,
      -1,    34,     3,   471,    -1,    32,     3,   471,    -1,     6,
      -1,     7,    -1,    70,   222,    10,   226,    71,    -1,    -1,
     222,   223,    -1,   224,    -1,   225,    -1,    34,     3,   471,
      -1,    32,     3,   471,    -1,     6,    -1,     7,    -1,    66,
     228,    10,   232,    67,    -1,    -1,   228,   229,    -1,   230,
      -1,   231,    -1,    34,     3,   471,    -1,    32,     3,   471,
      -1,     6,    -1,     7,    -1,    64,   234,    10,   236,    65,
      -1,    -1,   234,   235,    -1,    32,     3,   471,    -1,     6,
      -1,     7,    -1,    -1,   108,   238,   239,    -1,    19,     6,
     471,    -1,   240,    -1,   241,    -1,    10,   109,    -1,    11,
      -1,   242,    -1,   243,    -1,   242,   243,    -1,   106,   244,
     249,    -1,    -1,   244,   245,    -1,   246,    -1,   247,    -1,
     248,    -1,    34,     3,   471,    -1,    40,     3,   471,    -1,
      32,     3,   471,    -1,    10,   107,    -1,    11,    -1,    -1,
      52,    11,    -1,    52,    10,   251,   252,   253,   254,   255,
     256,    53,    -1,    -1,    82,    10,     4,    83,    -1,    82,
      10,    83,    -1,    82,    11,    -1,    -1,    80,    10,     4,
      81,    -1,    80,    10,    81,    -1,    80,    11,    -1,    -1,
     146,    10,     4,   147,    -1,   146,    10,   147,    -1,   146,
      11,    -1,    -1,   140,    10,     4,   141,    -1,   140,    10,
     141,    -1,   140,    11,    -1,    -1,   122,    10,     4,   123,
      -1,   122,    10,   123,    -1,   122,    11,    -1,    -1,   108,
     257,   258,    -1,    19,     6,   471,    -1,   259,    -1,   260,
      -1,    10,   109,    -1,    11,    -1,   261,    -1,   262,    -1,
     261,   262,    -1,   106,   263,   268,    -1,    -1,   263,   264,
      -1,   265,    -1,   266,    -1,   267,    -1,    34,     3,   471,
      -1,    40,     3,   471,    -1,    32,     3,   471,    -1,    10,
     107,    -1,    11,    -1,    -1,    54,    11,    -1,    54,    10,
     270,    55,    -1,    -1,   270,   271,    -1,   272,    -1,   273,
      -1,   274,    -1,   275,    -1,   276,    -1,   277,    -1,   292,
      -1,   298,    -1,   302,    -1,   308,    -1,   314,    -1,   130,
      10,     4,   131,    -1,   130,    10,   131,    -1,   130,    11,
      -1,   132,    10,     4,   133,    -1,   132,    10,   133,    -1,
     132,    11,    -1,   116,    10,     4,   117,    -1,   116,    10,
     117,    -1,   116,    11,    -1,    62,    10,     4,    63,    -1,
      62,    10,    63,    -1,    62,    11,    -1,    86,    10,     4,
      87,    -1,    86,    10,    87,    -1,    86,    11,    -1,   144,
     278,   279,    -1,    25,     8,     6,     8,    -1,    11,    -1,
      10,   280,   145,    -1,    -1,   280,   281,    -1,   138,   282,
     288,    -1,    -1,   282,   283,    -1,   284,    -1,   285,    -1,
     286,    -1,   287,    -1,    36,     3,     8,    -1,    37,    -1,
      30,     3,     8,    -1,    31,    -1,    38,     3,     8,    -1,
      39,    -1,    32,     3,     8,    -1,    33,    -1,   289,    -1,
     290,    -1,    10,   139,    -1,    11,    -1,    10,   291,   139,
      -1,    -1,     7,    -1,     6,    -1,   150,   293,    10,   297,
     151,    -1,    -1,   293,   294,    -1,   295,    -1,   296,    -1,
      34,     3,   471,    -1,    32,     3,   471,    -1,     6,    -1,
       7,    -1,   148,   299,    10,   301,   149,    -1,    -1,   299,
     300,    -1,    32,     3,   471,    -1,     6,    -1,     7,    -1,
     152,   303,    10,   307,   153,    -1,    -1,   303,   304,    -1,
     305,    -1,   306,    -1,    34,     3,   471,    -1,    32,     3,
     471,    -1,     6,    -1,     7,    -1,   154,   309,    10,   313,
     155,    -1,    -1,   309,   310,    -1,   311,    -1,   312,    -1,
      34,     3,   471,    -1,    32,     3,   471,    -1,     6,    -1,
       7,    -1,   108,   315,   316,    -1,    19,     6,   471,    -1,
     317,    -1,   318,    -1,    10,   109,    -1,    11,    -1,   319,
      -1,   320,    -1,   319,   320,    -1,   106,   321,   326,    -1,
      -1,   321,   322,    -1,   323,    -1,   324,    -1,   325,    -1,
      34,     3,   471,    -1,    40,     3,   471,    -1,    32,     3,
     471,    -1,    10,   107,    -1,    11,    -1,    -1,    56,   328,
     334,    -1,    -1,   328,   329,    -1,   330,   471,    -1,   331,
     471,    -1,   332,   471,    -1,   333,   471,    -1,    22,   471,
       6,    -1,    27,   471,     6,    -1,    13,   471,     6,    -1,
      16,   471,     6,    -1,    10,   335,    57,    -1,    11,    -1,
     336,   453,    -1,    -1,   336,   337,    -1,   338,   339,   343,
      -1,   124,    -1,    -1,   339,   340,    -1,   341,    -1,   342,
      -1,    28,   471,     6,   471,    -1,    42,   471,     3,   471,
      -1,    10,   344,   347,   348,   387,   411,   435,   452,    -1,
     130,   345,    10,   131,    -1,   130,   345,    11,    -1,   346,
      -1,   345,   346,    -1,    36,     3,   471,    -1,    37,    -1,
      32,     3,   471,    -1,    33,    -1,    -1,    96,     4,    97,
      -1,    96,    97,    -1,    -1,   162,   349,   350,    -1,    -1,
      21,   471,     6,   471,    -1,   351,    -1,   352,    -1,    11,
      -1,    10,   353,   359,   365,   371,   163,    -1,    -1,   156,
     354,    10,   355,   157,    -1,    26,   471,     6,   471,    -1,
      -1,   355,   356,    -1,   160,   357,    10,   358,   161,    -1,
      29,   471,     6,   471,    -1,     6,    -1,     7,    -1,    -1,
     158,   360,    10,   361,   159,    -1,    26,   471,     6,   471,
      -1,    -1,   361,   362,    -1,   160,   363,    10,   364,   161,
      -1,    29,   471,     6,   471,    -1,     6,    -1,     7,    -1,
      -1,    72,   366,    10,   367,    73,    -1,    26,   471,     6,
     471,    -1,    -1,   367,   368,    -1,   160,   369,    10,   370,
     161,    -1,    29,   471,     6,   471,    -1,     6,    -1,     7,
      -1,    -1,   371,   372,    -1,    -1,   375,   376,   373,   374,
      -1,    11,    -1,    10,   382,   107,    -1,   106,    -1,    -1,
     376,   377,    -1,   378,    -1,   379,    -1,   380,    -1,   381,
      -1,    26,   471,     6,   471,    -1,    41,    -1,    40,     3,
     471,    -1,    35,    -1,    34,     3,   471,    -1,    32,     3,
     471,    -1,    -1,   382,   383,    -1,   384,   385,    10,   472,
     161,    -1,   160,    -1,    -1,    29,   471,   386,     6,   471,
      -1,    -1,   100,   388,   389,    -1,    -1,    18,   471,     6,
     471,    -1,   390,    -1,   391,    -1,    11,    -1,    10,   392,
     398,   101,    -1,   156,   393,    10,   394,   157,    -1,    15,
     471,     6,   471,    -1,    -1,   394,   395,    -1,    98,   396,
      10,   397,    99,    -1,    29,   471,     6,   471,    -1,     6,
      -1,     7,    -1,    -1,   398,   399,    -1,   400,   401,    10,
     407,   107,    -1,   106,    -1,    -1,   401,   402,    -1,   403,
      -1,   404,    -1,   405,    -1,   406,    -1,    15,   471,     6,
     471,    -1,    41,    -1,    40,     3,   471,    -1,    35,    -1,
      34,     3,   471,    -1,    32,     3,   471,    -1,    -1,   407,
     408,    -1,   409,   410,    10,   472,    99,    -1,    98,    -1,
      29,   471,     6,   471,    -1,    -1,    78,   412,   413,    -1,
      -1,    17,   471,     6,   471,    -1,   414,    -1,   415,    -1,
      11,    -1,    10,   416,   422,    79,    -1,    84,   417,    10,
     418,    85,    -1,    12,   471,     6,   471,    -1,    -1,   418,
     419,    -1,    76,   420,    10,   421,    77,    -1,    29,   471,
       6,   471,    -1,     7,    -1,     6,    -1,    -1,   422,   423,
      -1,   424,   425,    10,   431,   107,    -1,   106,    -1,    -1,
     425,   426,    -1,   427,    -1,   428,    -1,   429,    -1,   430,
      -1,    12,   471,     6,   471,    -1,    41,    -1,    40,     3,
     471,    -1,    35,    -1,    34,     3,   471,    -1,    32,     3,
     471,    -1,    -1,   431,   432,    -1,   433,   434,    10,   472,
      77,    -1,    76,    -1,    29,   471,     6,   471,    -1,    -1,
     112,   436,    10,   438,   113,    -1,    -1,    20,     8,     6,
     437,     8,    -1,    -1,   438,   439,    -1,   110,   440,    10,
     447,   111,    -1,    -1,    -1,   440,   441,   442,    -1,   443,
      -1,   444,    -1,   445,    -1,   446,    -1,    14,     8,     6,
       8,    -1,    35,    -1,    34,     3,   471,    -1,    30,     3,
       8,    -1,    31,    -1,    32,     3,     8,    -1,    33,    -1,
      -1,   447,   448,    -1,   449,    -1,   450,    -1,    60,    -1,
      61,    -1,    -1,    58,     5,   451,    59,    -1,   125,    -1,
      -1,   114,   454,   455,    -1,    23,   471,     6,   471,    -1,
      11,    -1,    10,   456,   115,    -1,    -1,   456,   457,    -1,
     128,   458,    10,   465,   111,    -1,    -1,    -1,   458,   459,
     460,    -1,   461,    -1,   462,    -1,   463,    -1,   464,    -1,
      14,     8,     6,     8,    -1,    35,    -1,    34,     3,   471,
      -1,    30,     3,     8,    -1,    31,    -1,    32,     3,     8,
      -1,    33,    -1,    -1,   465,   466,    -1,    -1,    58,   467,
     468,    -1,   469,    -1,   470,    -1,    10,    59,    -1,    11,
      -1,    10,     5,    59,    -1,   474,     8,    -1,     4,    -1,
       6,    -1,     7,    -1,   165,    -1,   166,    -1,   167,    -1,
     168,    -1,    -1,   474,   473,    -1
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
     761,   766,   772,   773,   783,   790,   790,   792,   794,   797,
     802,   808,   808,   818,   825,   825,   827,   829,   832,   837,
     845,   845,   848,   847,   853,   854,   868,   876,   877,   879,
     879,   879,   879,   881,   890,   893,   899,   905,   911,   920,
     920,   922,   936,   941,   941,   945,   946,   948,   949,   959,
     959,   961,   963,   965,   976,   980,   980,   982,   984,   987,
     992,   998,   998,  1000,  1015,  1024,  1027,  1029,  1029,  1029,
    1029,  1031,  1040,  1043,  1049,  1055,  1061,  1070,  1070,  1072,
    1087,  1092,  1095,  1096,  1098,  1099,  1109,  1109,  1111,  1113,
    1116,  1129,  1135,  1135,  1137,  1139,  1142,  1146,  1152,  1152,
    1154,  1156,  1158,  1158,  1160,  1160,  1160,  1160,  1162,  1165,
    1168,  1174,  1180,  1186,  1195,  1195,  1197,  1213,  1218,  1222,
    1223,  1230,  1229,  1245,  1245,  1247,  1255,  1256,  1256,  1260,
    1260,  1260,  1260,  1262,  1275,  1281,  1289,  1292,  1295,  1298,
    1300,  1301,  1304,  1309,  1316,  1316,  1319,  1318,  1324,  1334,
    1334,  1336,  1338,  1338,  1340,  1340,  1342,  1350,  1351,  1351,
    1355,  1355,  1355,  1355,  1357,  1370,  1376,  1384,  1387,  1390,
    1393,  1395,  1396,  1399,  1398,  1410,  1411,  1413,  1413,  1415,
    1421,  1424,  1425,  1426,  1430,  1431,  1432,  1433,  1435,  1436
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
  "availableDiskSpaceAtt", "availableDiskSpaceNameATT",
  "availableDiskSpaceDescriptionATT", "availableDiskSpaceValue",
  "availableMemory", "availableMemoryAttList", "availableMemoryAtt",
  "availableMemoryNameATT", "availableMemoryDescriptionATT",
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
  "usedDiskSpaceAtt", "usedDiskSpaceNameATT",
  "usedDiskSpaceDescriptionATT", "usedDiskSpaceValue", "usedMemory",
  "usedMemoryAttList", "usedMemoryAtt", "usedMemoryNameATT",
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
  "basVar", "otherVariablesSEQ", "otherVariableResult", "@1",
  "otherVariableResultContent", "otherVariableStart",
  "otherVariableAttList", "otherVariableATT", "numberOfOtherVarATT",
  "otherVarValueATT", "otherVarNameATT", "otherVarDescriptionATT",
  "otherVarList", "otherVar", "otherVarStart", "otherVarIdxATT", "@2",
  "objectives", "numberOfOtherObjectiveResults", "objectivesBody",
  "objectivesEmpty", "objectivesContent", "objectiveValues",
  "numberOfObjATT", "objValueList", "objValue", "objIdxATT", "objVal",
  "otherObjectivesSEQ", "otherObjectiveResult", "otherObjectiveStart",
  "otherObjectiveAttList", "otherObjectiveATT", "numberOfOtherObjATT",
  "otherObjValueATT", "otherObjNameATT", "otherObjDescriptionATT",
  "otherObjList", "otherObj", "otherObjStart", "otherObjIdxATT",
  "constraints", "numberOfOtherConstraintResults", "constraintsBody",
  "constraintsEmpty", "constraintsContent", "dualValues", "numberOfConATT",
  "dualValueList", "dualValue", "conIdxATT", "dualVal",
  "otherConstraintsSEQ", "otherConstraintResult", "otherConstraintStart",
  "otherConstraintAttList", "otherConstraintATT", "numberOfOtherConATT",
  "otherConValueATT", "otherConNameATT", "otherConDescriptionATT",
  "otherConList", "otherCon", "otherConStart", "otherConIdxATT",
  "otherSolutionResults", "numberOfOtherSolutionResults", "@3",
  "otherSolutionResultList", "anotherSolutionResult",
  "anotherSolutionResultAttList", "@4", "anotherSolutionResultAtt",
  "numberOfOtherSolutionResultItems", "anotherSolutionResultNameATT",
  "anotherSolutionResultCategoryATT", "anotherSolutionDescriptionATT",
  "anotherSolutionItemList", "anotherSolutionItem",
  "otherSolutionItemEmpty", "otherSolutionItemContent", "@5",
  "solutionEnd", "otherSolverOutput", "numberOfSolverOutputsATT",
  "otherSolverOutputBody", "solverOutputSEQ", "solverOutput",
  "solverOutputAttList", "@6", "solverOutputAtt",
  "numberOfSolverOutputItems", "solverOutputNameATT",
  "solverOutputCategoryATT", "solverOutputDescriptionATT",
  "solverOutputItemList", "solverOutputItem", "@7", "solverOutputItemBody",
  "solverOutputItemEmpty", "solverOutputItemContent", "quote",
  "ElementValue", "xmlWhiteSpaceChar", "xmlWhiteSpace", 0
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
     371,   371,   373,   372,   374,   374,   375,   376,   376,   377,
     377,   377,   377,   378,   379,   379,   380,   380,   381,   382,
     382,   383,   384,   386,   385,   387,   387,   388,   388,   389,
     389,   390,   391,   392,   393,   394,   394,   395,   396,   397,
     397,   398,   398,   399,   400,   401,   401,   402,   402,   402,
     402,   403,   404,   404,   405,   405,   406,   407,   407,   408,
     409,   410,   411,   411,   412,   412,   413,   413,   414,   415,
     416,   417,   418,   418,   419,   420,   421,   421,   422,   422,
     423,   424,   425,   425,   426,   426,   426,   426,   427,   428,
     428,   429,   429,   430,   431,   431,   432,   433,   434,   435,
     435,   437,   436,   438,   438,   439,   440,   441,   440,   442,
     442,   442,   442,   443,   444,   444,   445,   445,   446,   446,
     447,   447,   448,   448,   449,   449,   451,   450,   452,   453,
     453,   454,   455,   455,   456,   456,   457,   458,   459,   458,
     460,   460,   460,   460,   461,   462,   462,   463,   463,   464,
     464,   465,   465,   467,   466,   468,   468,   469,   469,   470,
     471,   472,   472,   472,   473,   473,   473,   473,   474,   474
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
       3,     3,     1,     1,     2,     1,     1,     1,     2,     3,
       0,     2,     1,     1,     1,     3,     3,     3,     2,     1,
       0,     2,     9,     0,     4,     3,     2,     5,     0,     2,
       1,     1,     3,     3,     1,     1,     5,     0,     2,     1,
       1,     3,     3,     1,     1,     5,     0,     2,     1,     1,
       3,     3,     1,     1,     5,     0,     2,     3,     1,     1,
       0,     3,     3,     1,     1,     2,     1,     1,     1,     2,
       3,     0,     2,     1,     1,     1,     3,     3,     3,     2,
       1,     0,     2,     9,     0,     4,     3,     2,     0,     4,
       3,     2,     0,     4,     3,     2,     0,     4,     3,     2,
       0,     4,     3,     2,     0,     3,     3,     1,     1,     2,
       1,     1,     1,     2,     3,     0,     2,     1,     1,     1,
       3,     3,     3,     2,     1,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     2,     4,     3,     2,     4,     3,     2,
       4,     3,     2,     4,     3,     2,     3,     4,     1,     3,
       0,     2,     3,     0,     2,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     2,
       1,     3,     0,     1,     1,     5,     0,     2,     1,     1,
       3,     3,     1,     1,     5,     0,     2,     3,     1,     1,
       5,     0,     2,     1,     1,     3,     3,     1,     1,     5,
       0,     2,     1,     1,     3,     3,     1,     1,     3,     3,
       1,     1,     2,     1,     1,     1,     2,     3,     0,     2,
       1,     1,     1,     3,     3,     3,     2,     1,     0,     3,
       0,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     1,     2,     0,     2,     3,     1,     0,     2,     1,
       1,     4,     4,     8,     4,     3,     1,     2,     3,     1,
       3,     1,     0,     3,     2,     0,     3,     0,     4,     1,
       1,     1,     6,     0,     5,     4,     0,     2,     5,     4,
       1,     1,     0,     5,     4,     0,     2,     5,     4,     1,
       1,     0,     5,     4,     0,     2,     5,     4,     1,     1,
       0,     2,     0,     4,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     4,     1,     3,     1,     3,     3,     0,
       2,     5,     1,     0,     5,     0,     3,     0,     4,     1,
       1,     1,     4,     5,     4,     0,     2,     5,     4,     1,
       1,     0,     2,     5,     1,     0,     2,     1,     1,     1,
       1,     4,     1,     3,     1,     3,     3,     0,     2,     5,
       1,     4,     0,     3,     0,     4,     1,     1,     1,     4,
       5,     4,     0,     2,     5,     4,     1,     1,     0,     2,
       5,     1,     0,     2,     1,     1,     1,     1,     4,     1,
       3,     1,     3,     3,     0,     2,     5,     1,     4,     0,
       5,     0,     5,     0,     2,     5,     0,     0,     3,     1,
       1,     1,     1,     4,     1,     3,     3,     1,     3,     1,
       0,     2,     1,     1,     1,     1,     0,     4,     1,     0,
       3,     4,     1,     3,     0,     2,     5,     0,     0,     3,
       1,     1,     1,     1,     4,     1,     3,     3,     1,     3,
       1,     0,     2,     0,     3,     1,     1,     2,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     0,     2
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
       0,    51,     0,     0,     0,    57,     0,    54,     0,    66,
       0,    69,     0,    96,    98,     0,     0,   158,   198,   196,
     310,     0,     0,    33,     0,     0,    28,     0,    26,    21,
      22,    23,    24,    19,    30,    31,     0,    59,     0,    62,
       0,    50,   548,     0,    75,    80,    70,    72,    73,    76,
      77,     0,    56,     0,    53,     0,    65,     0,    68,     0,
      95,     0,   107,     0,     0,   157,     0,   162,     0,     0,
       2,    32,    38,     0,    35,     0,   548,   548,    58,    61,
      49,    71,     0,    74,     0,    78,    55,    52,    64,    67,
      94,     0,     0,     0,    99,   100,   101,     0,   116,     0,
       0,   156,     0,   161,     0,   166,   197,     0,     0,     0,
       0,     0,     0,     0,   265,   256,   271,   280,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     323,   321,   548,   548,   548,   548,   311,   548,   548,   548,
     548,   309,     0,    34,    36,     0,    27,    25,   540,   544,
     545,   546,   547,   549,     0,    89,     0,     0,     0,    81,
      82,    83,    84,    79,   104,   105,     0,   548,   548,     0,
       0,     0,   108,   109,   110,     0,   125,   130,   155,     0,
     160,     0,   165,     0,   170,     0,   222,     0,   225,     0,
       0,     0,   219,     0,   213,     0,   216,     0,     0,     0,
       0,     0,     0,     0,   509,     0,     0,     0,     0,   312,
     313,   314,   315,     0,    47,     0,     0,    39,    40,    41,
      37,    44,    45,    29,    88,   548,   548,   548,    97,   103,
     102,   113,   114,     0,   548,   548,     0,     0,     0,   117,
     118,   119,     0,     0,     0,   159,     0,   164,     0,   169,
       0,   174,     0,   221,     0,   224,   548,     0,   293,   298,
     288,   290,   291,   294,   295,     0,   218,     0,   212,     0,
     215,     0,   230,   228,   226,     0,     0,   266,     0,     0,
       0,   257,   258,   259,     0,     0,     0,   272,   273,   274,
       0,     0,     0,   281,   282,   283,   320,     0,   326,   324,
     327,   322,   318,   319,   316,   317,     0,    46,     0,     0,
      87,    85,    86,   106,   112,   111,   122,   123,     0,   548,
     548,     0,     0,   126,     0,     0,    92,   163,     0,   168,
       0,   173,     0,     0,   220,   223,   289,   292,     0,   296,
     217,   211,   214,     0,     0,   268,   269,     0,   548,   262,
     263,     0,   548,   548,   277,   278,     0,   548,   548,   286,
     287,     0,   548,   548,   548,     0,     0,    48,    43,    42,
     115,   121,   120,   128,   129,     0,   548,   548,     0,   136,
     141,   131,   133,   134,   137,   138,   167,     0,   172,     0,
       0,   153,     0,   307,     0,     0,     0,   299,   300,   301,
     302,   297,   227,   233,   229,   231,   264,   267,   255,   261,
     260,   270,   276,   275,   279,   285,   284,     0,   514,   512,
     510,     0,   548,   548,   328,   329,   330,   325,   124,   127,
     132,   135,     0,   139,   171,   548,     0,   180,   185,   175,
     177,   178,   181,   182,   306,   548,   548,   548,   252,   548,
       0,     0,   342,     0,     0,     0,   150,     0,     0,     0,
     142,   143,   144,   145,   140,   176,   179,     0,   183,   305,
     303,   304,     0,   250,     0,   242,     0,   246,     0,   240,
       0,   244,   234,   235,   236,   237,   238,   232,   247,   248,
     511,   513,   517,   515,     0,   341,     0,   339,     0,   336,
       0,   345,   548,   548,   149,   548,   548,   548,     0,   194,
       0,     0,     0,   186,   187,   188,   189,   184,   254,   253,
     249,     0,     0,     0,     0,     0,   518,   548,   548,     0,
     335,   337,     0,   344,   347,   405,   331,   332,   148,   146,
     147,   193,   548,   548,   548,   251,   241,   245,   239,   243,
     531,     0,   340,   338,   334,   343,   548,     0,   407,   442,
     192,   190,   191,     0,     0,     0,   528,     0,   530,     0,
     525,   519,   520,   521,   522,   523,     0,   353,   351,   346,
     349,   350,   548,     0,   444,   479,   533,   516,   532,     0,
       0,     0,   548,   548,     0,   362,     0,     0,   411,   406,
     409,   410,   548,     0,     0,     0,     0,     0,   527,   529,
     526,   348,   548,     0,     0,   371,   548,     0,   421,     0,
       0,   448,   443,   446,   447,     0,     0,   508,   333,     0,
     538,   534,   535,   536,   524,     0,   356,   548,     0,     0,
     380,   408,   548,     0,     0,   548,     0,   458,     0,   483,
       0,   537,   548,     0,     0,   365,   548,     0,     0,     0,
     415,   412,   424,   422,   425,   445,   548,     0,     0,   481,
       0,   539,   355,   354,     0,   357,   548,     0,     0,   374,
     386,   352,   381,   387,   548,     0,     0,     0,   452,   449,
     461,   459,   462,     0,   486,   480,   484,   548,     0,   364,
     363,     0,   366,   548,     0,   382,   414,     0,   413,   416,
     437,   548,     0,     0,   434,     0,   432,   426,   427,   428,
     429,   430,   548,     0,     0,   482,   487,     0,     0,   548,
       0,   373,   372,     0,   375,   548,     0,     0,   396,     0,
     394,     0,   388,   389,   390,   391,   392,   548,     0,     0,
       0,   548,   548,   548,   451,     0,   450,   453,   474,   548,
       0,     0,   471,     0,   469,   463,   464,   465,   466,   467,
     500,     0,   548,   360,   361,     0,     0,     0,   548,     0,
       0,   548,   548,   548,   399,   384,   383,     0,     0,   440,
     423,   438,     0,   548,   436,   435,   433,   548,     0,     0,
       0,   548,   548,   548,     0,     0,     0,   497,     0,   499,
       0,   494,   488,   489,   490,   491,   492,   359,   358,   548,
     369,   370,     0,     0,     0,   548,   398,   397,   395,     0,
     548,   419,   420,     0,   548,     0,   431,     0,     0,   477,
     460,   475,     0,   548,   473,   472,   470,     0,   504,   505,
     485,   501,   502,   503,     0,     0,     0,   548,   368,   367,
     548,   378,   379,     0,   393,   385,   402,   400,     0,   418,
     417,     0,     0,   548,   457,   456,     0,   548,     0,   468,
     506,     0,   496,   498,   495,   377,   376,   548,     0,   548,
     541,   542,   543,     0,   455,   454,     0,     0,     0,   493,
     403,     0,   441,   439,   548,     0,   507,     0,     0,   478,
     476,   548,   401,   404
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    45,    79,    80,
      81,    82,    83,    84,    85,   123,   124,   192,   267,   268,
     269,   270,   271,   272,    31,    32,    33,    34,    35,    36,
      37,    38,    53,    96,    97,    98,    99,   100,   134,   209,
     210,   211,   212,   213,    13,    40,    65,   111,   144,   145,
     146,   216,   113,   147,   222,   223,   224,   283,   149,   225,
     289,   290,   291,   368,   227,   292,   373,   425,   294,   375,
     431,   432,   433,   434,   435,   482,   510,   511,   512,   513,
     514,    18,    67,   117,   155,   234,   301,   383,   440,   489,
     490,   491,   492,   493,   517,   563,   564,   565,   566,   567,
      44,   118,   168,   169,   170,   171,   172,   173,   174,   248,
     324,   394,   455,   498,   532,   533,   534,   535,   536,   537,
     538,   539,   571,   175,   250,   331,   332,   333,   401,   176,
     249,   327,   397,   177,   251,   337,   338,   339,   406,   178,
     252,   343,   344,   345,   411,   179,   240,   310,   311,   312,
     313,   314,   388,   447,   448,   449,   450,   451,    71,   119,
     186,   187,   188,   189,   190,   191,   253,   254,   349,   350,
     416,   474,   475,   476,   477,   502,   548,   549,   551,   585,
     607,   629,   630,   631,   645,   663,   703,   725,   748,   825,
     665,   688,   727,   752,   780,   872,   690,   707,   754,   784,
     829,   913,   708,   732,   791,   836,   733,   755,   792,   793,
     794,   795,   796,   879,   917,   918,   938,   957,   609,   633,
     649,   650,   651,   668,   693,   735,   759,   798,   883,   694,
     713,   714,   736,   767,   768,   769,   770,   771,   799,   841,
     842,   885,   635,   653,   672,   673,   674,   697,   717,   773,
     807,   848,   926,   718,   741,   742,   774,   815,   816,   817,
     818,   819,   849,   891,   892,   928,   655,   676,   743,   720,
     746,   776,   821,   862,   863,   864,   865,   866,   854,   901,
     902,   903,   948,   678,   351,   415,   470,   500,   543,   576,
     601,   621,   622,   623,   624,   625,   613,   638,   656,   681,
     682,   683,   131,   943,   203,   132
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -863
static const yytype_int16 yypact[] =
{
      24,    38,    88,    54,  -863,   117,  -863,    76,    98,  -863,
    -863,  -863,    90,   102,   -14,    51,  -863,   126,   111,  -863,
    -863,   206,   249,   268,   148,   273,   294,   296,   304,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,   309,
     105,    74,  -863,   311,   143,   209,    30,  -863,    15,  -863,
      17,  -863,   187,    13,    11,  -863,    10,  -863,     8,  -863,
       0,  -863,     3,  -863,  -863,   142,   313,   127,  -863,  -863,
    -863,   177,   236,  -863,   210,   237,  -863,   250,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,   162,  -863,   167,  -863,
     160,  -863,  -863,   176,  -863,  -863,  -863,  -863,  -863,   189,
    -863,   161,  -863,   195,  -863,   183,  -863,   155,  -863,   198,
    -863,    71,  -863,   302,    33,  -863,   317,   226,   -37,   286,
    -863,  -863,  -863,   240,  -863,   346,  -863,  -863,  -863,  -863,
    -863,  -863,    -5,  -863,   164,  -863,  -863,  -863,  -863,  -863,
    -863,   325,   398,   399,  -863,  -863,  -863,   136,  -863,   314,
     320,  -863,    37,  -863,   323,   264,  -863,   326,   328,   386,
     330,   332,   334,   382,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,   123,  -863,  -863,   400,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,   299,  -863,   406,   407,   408,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,   344,  -863,  -863,   342,
     409,   411,  -863,  -863,  -863,   215,  -863,   307,  -863,   335,
    -863,    -2,  -863,   340,   295,    35,  -863,    34,  -863,   412,
      16,    12,  -863,     7,  -863,     6,  -863,   413,   343,    40,
     218,   224,   229,   362,   -48,   414,   416,   417,   418,  -863,
    -863,  -863,  -863,    29,  -863,   422,   425,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,   361,  -863,  -863,   349,   430,   431,  -863,
    -863,  -863,    43,   419,   384,  -863,   289,  -863,     1,  -863,
     347,   329,   376,  -863,   353,  -863,  -863,   333,  -863,  -863,
    -863,  -863,  -863,   337,  -863,   324,  -863,   315,  -863,   312,
    -863,   438,  -863,  -863,  -863,   354,   444,  -863,   356,   445,
     446,  -863,  -863,  -863,   358,   447,   450,  -863,  -863,  -863,
     360,   451,   452,  -863,  -863,  -863,  -863,   433,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,   367,  -863,   449,   453,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,   392,  -863,
    -863,   368,   457,  -863,   456,    18,  -863,  -863,   322,  -863,
       9,  -863,   454,   421,  -863,  -863,  -863,  -863,   171,  -863,
    -863,  -863,  -863,   461,    45,  -863,  -863,   316,  -863,  -863,
    -863,   319,  -863,  -863,  -863,  -863,   318,  -863,  -863,  -863,
    -863,   321,  -863,  -863,  -863,   366,    41,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,   410,  -863,  -863,   355,  -863,
    -863,  -863,  -863,  -863,   372,  -863,  -863,   359,  -863,   466,
      20,  -863,   370,  -863,   476,   478,   480,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,   479,  -863,  -863,
    -863,   357,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,   174,  -863,  -863,  -863,   377,  -863,  -863,  -863,
    -863,  -863,   378,  -863,  -863,  -863,  -863,  -863,   199,  -863,
     -68,   238,   394,   482,   486,   385,  -863,   488,   490,   491,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,   181,  -863,  -863,
    -863,  -863,     2,  -863,   492,  -863,   493,  -863,   494,  -863,
     495,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,   496,  -863,   497,  -863,   190,  -863,
      28,   339,  -863,  -863,  -863,  -863,  -863,  -863,   395,  -863,
     500,   501,   502,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,   374,   499,   503,   504,   506,   498,  -863,  -863,   379,
    -863,  -863,   423,  -863,   507,   415,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,   234,  -863,  -863,  -863,  -863,  -863,   369,   505,   440,
    -863,  -863,  -863,   -41,   511,   518,  -863,   519,  -863,   521,
    -863,  -863,  -863,  -863,  -863,  -863,   523,   388,  -863,  -863,
    -863,  -863,  -863,   371,   508,   397,  -863,  -863,  -863,   524,
     525,   526,  -863,  -863,   509,   380,   531,   390,  -863,  -863,
    -863,  -863,  -863,   373,   512,   402,   375,   533,  -863,  -863,
    -863,  -863,  -863,   529,   516,   459,  -863,   528,  -863,   539,
     463,  -863,  -863,  -863,  -863,   540,   541,  -863,  -863,    31,
    -863,  -863,  -863,  -863,  -863,   543,  -863,  -863,   542,   527,
    -863,  -863,  -863,   544,    96,  -863,   538,  -863,   549,  -863,
     513,  -863,  -863,    19,   550,  -863,  -863,   547,   -86,   552,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,   553,   -39,  -863,
     141,  -863,  -863,  -863,   530,  -863,  -863,   228,   554,  -863,
    -863,  -863,  -863,  -863,  -863,   -92,   137,   556,  -863,  -863,
    -863,  -863,  -863,   557,  -863,  -863,  -863,  -863,   558,  -863,
    -863,   535,  -863,  -863,   -51,   277,  -863,   545,  -863,  -863,
    -863,  -863,   564,   567,  -863,   568,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,    23,   154,  -863,   563,   569,   383,  -863,
     571,  -863,  -863,   548,  -863,  -863,   575,   576,  -863,   579,
    -863,   381,  -863,  -863,  -863,  -863,  -863,  -863,   573,    46,
     578,  -863,  -863,  -863,  -863,   559,  -863,  -863,  -863,  -863,
     582,   583,  -863,   584,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,   259,  -863,  -863,  -863,   428,   585,   387,  -863,   586,
     587,  -863,  -863,  -863,  -863,  -863,  -863,   588,   389,  -863,
    -863,  -863,   566,  -863,  -863,  -863,  -863,  -863,   589,   -34,
     591,  -863,  -863,  -863,   -15,   590,   598,  -863,   599,  -863,
     600,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,   443,   601,   391,  -863,  -863,  -863,  -863,   -63,
    -863,  -863,  -863,   510,  -863,   595,  -863,   604,   393,  -863,
    -863,  -863,   577,  -863,  -863,  -863,  -863,   606,  -863,  -863,
    -863,  -863,  -863,  -863,   607,   608,   609,  -863,  -863,  -863,
    -863,  -863,  -863,   458,  -863,  -863,  -863,  -863,   593,  -863,
    -863,   612,    48,  -863,  -863,  -863,   515,  -863,   602,  -863,
    -863,   615,  -863,  -863,  -863,  -863,  -863,  -863,   605,  -863,
    -863,  -863,  -863,   532,  -863,  -863,   614,    48,   555,  -863,
    -863,    48,  -863,  -863,  -863,   551,  -863,   618,   464,  -863,
    -863,  -863,  -863,  -863
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,   514,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,   534,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,   192,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,   138,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,   327,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,    81,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -126,  -862,  -863,  -863
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     196,   197,   296,   198,   107,   378,   757,   109,   568,   569,
     319,   317,   105,   437,   103,   101,   315,   636,   156,    88,
     730,    90,   782,    93,    94,   157,   307,   308,   428,   429,
     486,   487,   582,   356,    86,    19,   700,   150,   304,   302,
     739,   229,   889,   897,   915,   898,   899,   541,     4,   158,
     325,   471,   940,   371,   941,   942,   255,   256,   257,   258,
     542,   259,   260,   261,   262,   758,   347,   740,     1,   472,
     637,   159,   326,   890,    20,   372,   348,   731,    21,   160,
      22,   141,    23,   473,     5,   955,    10,    11,     6,   958,
     701,   279,   280,   161,    24,   162,   900,   916,   303,   805,
      15,    16,     7,   142,    25,   143,    26,   163,   806,   783,
      89,   164,    27,   165,    91,   166,   151,   167,   230,    95,
     357,   305,   309,    87,   430,   583,   488,     9,    28,   316,
     102,   104,   438,   263,   264,   106,    41,    42,   318,   320,
     110,   570,   379,   108,   839,   297,   219,   760,    12,   360,
     361,   362,   761,   840,    17,   265,    66,   266,   364,   365,
     199,   200,   201,   202,   808,    43,   809,    52,   220,   762,
     221,   763,   764,    64,   204,   205,   723,   765,   766,   724,
     386,   442,   443,   453,   505,   506,   810,    39,   811,   812,
     454,   558,   559,    92,   813,   814,   206,   711,   207,    70,
     579,   580,   712,   444,   208,   445,   507,   116,   508,   522,
     523,   446,   112,   560,   509,   561,    46,    47,   125,    72,
      73,   562,   544,   545,   120,   286,   546,   547,   328,   524,
     525,   526,   527,    74,   334,   528,   529,   530,   531,   340,
     126,    75,    76,   421,   422,    77,    78,   287,   614,   288,
     329,   744,   330,   127,   745,   128,   335,   130,   336,    48,
      49,   341,   129,   342,   615,   616,   617,   618,   619,   620,
     544,   545,   457,   855,   546,   547,   459,   460,    50,    51,
     136,   462,   463,    54,    55,   133,   465,   466,   467,   856,
     857,   858,   859,   860,   861,    95,   180,   181,   139,   182,
     479,   480,   183,   785,    56,    57,    58,    59,   184,   786,
     138,   787,   788,   185,    60,    61,   137,   789,   790,    62,
      63,    68,    69,   114,   115,   121,   122,   152,   153,   193,
     122,   214,   215,   231,   232,   140,   235,   236,   237,   238,
     241,   242,   243,   244,   245,   246,   503,   504,   281,   282,
     298,   299,   195,   322,   323,   366,   367,   380,   381,   515,
     395,   396,   399,   400,   404,   405,   409,   410,   148,   519,
     520,   521,   154,   540,   423,   424,   468,   469,   226,   627,
     628,   647,   648,   670,   671,   679,   680,   750,   751,   823,
     824,   834,   835,   870,   871,   881,   882,   911,   912,   924,
     925,   217,   218,   228,   233,   239,   274,   247,   273,   275,
     276,   277,   284,   278,   285,   293,   295,   300,   306,   346,
     352,   321,   353,   354,   355,   358,   586,   587,   359,   588,
     589,   590,   363,   369,   370,   376,   377,   382,   374,   384,
     385,   390,   387,   309,   393,   392,   391,   398,   402,   403,
     407,   602,   603,   408,   412,   413,   414,   418,   417,   420,
     426,   419,   427,   436,   481,   456,   610,   611,   612,   452,
     458,   461,   485,   439,   441,   478,   464,   494,   430,   495,
     626,   496,   484,   497,   488,   499,   516,   501,   552,   553,
     550,   555,   554,   556,   557,   572,   573,   574,   575,   577,
     578,   584,   591,   592,   593,   594,   646,   596,   600,   654,
     604,   597,   598,   595,   599,   608,   660,   661,   634,   639,
     605,   640,   641,   632,   642,   652,   669,   677,   606,   643,
     657,   689,   675,   658,   659,   662,   685,   666,   664,   686,
     691,   684,   687,   692,   644,   695,   667,   696,   698,   702,
     716,   699,   705,   706,   710,   719,   726,   729,   734,   747,
     753,   704,   772,   738,   779,   775,   709,   801,   778,   715,
     802,   803,   721,   820,   797,   822,   722,   828,   831,   832,
     728,   827,   833,   838,   843,   851,   852,   853,   847,   868,
     737,   869,   945,   875,   880,   884,   874,   893,   904,   888,
     749,   905,   906,   907,   909,   922,   927,   910,   756,   920,
     923,   930,   947,   931,   956,   951,   932,   933,   939,   936,
     954,   777,   937,   949,   961,   962,   483,   781,   960,   581,
     518,   953,     0,   135,     0,   800,     0,   194,     0,     0,
     389,     0,     0,     0,     0,     0,   804,     0,     0,     0,
       0,     0,     0,   826,     0,     0,     0,     0,     0,   830,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   837,     0,     0,     0,   844,   845,   846,     0,     0,
       0,     0,     0,   850,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   867,     0,     0,     0,
       0,     0,   873,     0,     0,   876,   877,   878,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   886,     0,     0,
       0,   887,     0,     0,     0,   894,   895,   896,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   908,     0,     0,     0,     0,     0,   914,
       0,     0,     0,     0,   919,     0,     0,     0,   921,     0,
       0,     0,     0,     0,     0,     0,     0,   929,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   934,     0,     0,   935,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   944,     0,     0,
       0,   946,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   950,     0,   952,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   959,     0,
       0,     0,     0,     0,     0,   963
};

static const yytype_int16 yycheck[] =
{
     126,   127,     4,     8,     4,     4,    98,     4,     6,     7,
       4,     4,     4,     4,     4,     4,     4,    58,    55,     4,
     106,     4,    73,    10,    11,    62,    10,    11,    10,    11,
      10,    11,     4,     4,     4,    49,     5,     4,     4,     4,
      79,     4,    76,    58,   107,    60,    61,   115,    10,    86,
      10,    10,     4,    10,     6,     7,   182,   183,   184,   185,
     128,   187,   188,   189,   190,   157,   114,   106,    44,    28,
     111,   108,    32,   107,    88,    32,   124,   163,    92,   116,
      94,    10,    96,    42,    46,   947,    10,    11,     0,   951,
      59,   217,   218,   130,   108,   132,   111,   160,    63,    76,
      10,    11,    48,    32,   118,    34,   120,   144,    85,   160,
      95,   148,   126,   150,    97,   152,    83,   154,    81,   106,
      91,    87,   106,    93,   106,    97,   106,    10,   142,   117,
     119,   121,   123,    10,    11,   127,    10,    11,   131,   133,
     137,   139,   141,   143,    98,   147,    10,    10,    50,   275,
     276,   277,    15,   107,    52,    32,    82,    34,   284,   285,
     165,   166,   167,   168,    10,    54,    12,    19,    32,    32,
      34,    34,    35,    68,    10,    11,   157,    40,    41,   160,
     306,    10,    11,   138,    10,    11,    32,   136,    34,    35,
     145,    10,    11,     6,    40,    41,    32,   101,    34,    56,
      10,    11,   106,    32,    40,    34,    32,    80,    34,    10,
      11,    40,    70,    32,    40,    34,    10,    11,     8,    10,
      11,    40,    32,    33,    47,    10,    36,    37,    10,    30,
      31,    32,    33,    24,    10,    36,    37,    38,    39,    10,
       3,    32,    33,   369,   370,    36,    37,    32,    14,    34,
      32,   110,    34,     3,   113,    93,    32,    97,    34,    10,
      11,    32,    95,    34,    30,    31,    32,    33,    34,    35,
      32,    33,   398,    14,    36,    37,   402,   403,    10,    11,
     119,   407,   408,    10,    11,   109,   412,   413,   414,    30,
      31,    32,    33,    34,    35,   106,    10,    11,   143,    13,
     426,   427,    16,    26,    10,    11,    10,    11,    22,    32,
     127,    34,    35,    27,    10,    11,   121,    40,    41,    10,
      11,    10,    11,    10,    11,    89,    90,    10,    11,    89,
      90,     6,     7,    10,    11,   137,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,   472,   473,     6,     7,
      10,    11,     6,    10,    11,     6,     7,    10,    11,   485,
       6,     7,     6,     7,     6,     7,     6,     7,    66,   495,
     496,   497,   146,   499,     6,     7,    10,    11,    64,    10,
      11,    10,    11,    10,    11,    10,    11,   159,   160,     6,
       7,    10,    11,     6,     7,     6,     7,     6,     7,     6,
       7,     3,     3,    83,   140,    19,   107,    25,     8,     3,
       3,     3,     3,    69,     3,   108,    81,   122,     6,    57,
       6,     8,     6,     6,     6,     3,   552,   553,     3,   555,
     556,   557,    71,     3,     3,    51,   147,   108,    19,    63,
      87,   117,   109,   106,     6,   133,   131,     3,     3,     3,
       3,   577,   578,     3,     3,     3,    23,     8,    91,    67,
       3,     8,     6,   141,   109,   149,   592,   593,   594,     8,
     151,   153,     6,    19,    53,    65,   155,   107,   106,     3,
     606,     3,   123,     3,   106,     6,   109,   130,     6,     3,
      96,     3,   107,     3,     3,     3,     3,     3,     3,     3,
       3,   162,   107,     3,     3,     3,   632,     8,    10,   112,
     131,     8,     8,   139,     8,   100,   642,   643,    78,     8,
      97,     3,     3,    18,     3,    17,   652,   125,    21,     6,
       6,    72,    20,     8,     8,    26,   662,     6,   158,    10,
     666,     8,    26,    15,   156,     6,   156,    84,     8,     6,
      12,    10,    10,    26,    10,     6,     6,    10,     6,    29,
       6,   687,     6,    10,    29,     8,   692,     3,    10,   695,
       3,     3,    59,    10,    29,     6,   702,    29,     3,     3,
     706,    10,     3,    10,     6,     3,     3,     3,    29,   161,
     716,     6,    77,     6,     6,    29,    10,     6,     8,    10,
     726,     3,     3,     3,   161,    10,    29,     6,   734,    99,
       6,     5,    10,     6,    59,    10,     8,     8,     6,   161,
       6,   747,    29,     8,     6,   161,   434,   753,    77,   548,
     492,    99,    -1,    99,    -1,   761,    -1,   123,    -1,    -1,
     313,    -1,    -1,    -1,    -1,    -1,   772,    -1,    -1,    -1,
      -1,    -1,    -1,   779,    -1,    -1,    -1,    -1,    -1,   785,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   797,    -1,    -1,    -1,   801,   802,   803,    -1,    -1,
      -1,    -1,    -1,   809,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   822,    -1,    -1,    -1,
      -1,    -1,   828,    -1,    -1,   831,   832,   833,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   843,    -1,    -1,
      -1,   847,    -1,    -1,    -1,   851,   852,   853,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   869,    -1,    -1,    -1,    -1,    -1,   875,
      -1,    -1,    -1,    -1,   880,    -1,    -1,    -1,   884,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   893,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   907,    -1,    -1,   910,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   923,    -1,    -1,
      -1,   927,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   937,    -1,   939,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   954,    -1,
      -1,    -1,    -1,    -1,    -1,   961
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
       4,    97,     6,    10,    11,   106,   202,   203,   204,   205,
     206,     4,   119,     4,   121,     4,   127,     4,   143,     4,
     137,   216,    70,   221,    10,    11,    80,   252,   270,   328,
      47,    89,    90,   184,   185,     8,     3,     3,    93,    95,
      97,   471,   474,   109,   207,   206,   119,   121,   127,   143,
     137,    10,    32,    34,   217,   218,   219,   222,    66,   227,
       4,    83,    10,    11,   146,   253,    55,    62,    86,   108,
     116,   130,   132,   144,   148,   150,   152,   154,   271,   272,
     273,   274,   275,   276,   277,   292,   298,   302,   308,   314,
      10,    11,    13,    16,    22,    27,   329,   330,   331,   332,
     333,   334,   186,    89,   185,     6,   471,   471,     8,   165,
     166,   167,   168,   473,    10,    11,    32,    34,    40,   208,
     209,   210,   211,   212,     6,     7,   220,     3,     3,    10,
      32,    34,   223,   224,   225,   228,    64,   233,    83,     4,
      81,    10,    11,   140,   254,    10,    11,    10,    11,    19,
     315,    10,    11,    10,    11,    10,    11,    25,   278,   299,
     293,   303,   309,   335,   336,   471,   471,   471,   471,   471,
     471,   471,   471,    10,    11,    32,    34,   187,   188,   189,
     190,   191,   192,     8,   107,     3,     3,     3,    69,   471,
     471,     6,     7,   226,     3,     3,    10,    32,    34,   229,
     230,   231,   234,   108,   237,    81,     4,   147,    10,    11,
     122,   255,     4,    63,     4,    87,     6,    10,    11,   106,
     316,   317,   318,   319,   320,     4,   117,     4,   131,     4,
     133,     8,    10,    11,   279,    10,    32,   300,    10,    32,
      34,   294,   295,   296,    10,    32,    34,   304,   305,   306,
      10,    32,    34,   310,   311,   312,    57,   114,   124,   337,
     338,   453,     6,     6,     6,     6,     4,    91,     3,     3,
     471,   471,   471,    71,   471,   471,     6,     7,   232,     3,
       3,    10,    32,   235,    19,   238,    51,   147,     4,   141,
      10,    11,   108,   256,    63,    87,   471,   109,   321,   320,
     117,   131,   133,     6,   280,     6,     7,   301,     3,     6,
       7,   297,     3,     3,     6,     7,   307,     3,     3,     6,
       7,   313,     3,     3,    23,   454,   339,    91,     8,     8,
      67,   471,   471,     6,     7,   236,     3,     6,    10,    11,
     106,   239,   240,   241,   242,   243,   141,     4,   123,    19,
     257,    53,    10,    11,    32,    34,    40,   322,   323,   324,
     325,   326,     8,   138,   145,   281,   149,   471,   151,   471,
     471,   153,   471,   471,   155,   471,   471,   471,    10,    11,
     455,    10,    28,    42,   340,   341,   342,   343,    65,   471,
     471,   109,   244,   243,   123,     6,    10,    11,   106,   258,
     259,   260,   261,   262,   107,     3,     3,     3,   282,     6,
     456,   130,   344,   471,   471,    10,    11,    32,    34,    40,
     245,   246,   247,   248,   249,   471,   109,   263,   262,   471,
     471,   471,    10,    11,    30,    31,    32,    33,    36,    37,
      38,    39,   283,   284,   285,   286,   287,   288,   289,   290,
     471,   115,   128,   457,    32,    33,    36,    37,   345,   346,
      96,   347,     6,     3,   107,     3,     3,     3,    10,    11,
      32,    34,    40,   264,   265,   266,   267,   268,     6,     7,
     139,   291,     3,     3,     3,     3,   458,     3,     3,    10,
      11,   346,     4,    97,   162,   348,   471,   471,   471,   471,
     471,   107,     3,     3,     3,   139,     8,     8,     8,     8,
      10,   459,   471,   471,   131,    97,    21,   349,   100,   387,
     471,   471,   471,   465,    14,    30,    31,    32,    33,    34,
      35,   460,   461,   462,   463,   464,   471,    10,    11,   350,
     351,   352,    18,   388,    78,   411,    58,   111,   466,     8,
       3,     3,     3,     6,   156,   353,   471,    10,    11,   389,
     390,   391,    17,   412,   112,   435,   467,     6,     8,     8,
     471,   471,    26,   354,   158,   359,     6,   156,   392,   471,
      10,    11,   413,   414,   415,    20,   436,   125,   452,    10,
      11,   468,   469,   470,     8,   471,    10,    26,   360,    72,
     365,   471,    15,   393,   398,     6,    84,   416,     8,    10,
       5,    59,     6,   355,   471,    10,    26,   366,   371,   471,
      10,   101,   106,   399,   400,   471,    12,   417,   422,     6,
     438,    59,   471,   157,   160,   356,     6,   361,   471,    10,
     106,   163,   372,   375,     6,   394,   401,   471,    10,    79,
     106,   423,   424,   437,   110,   113,   439,    29,   357,   471,
     159,   160,   362,     6,   367,   376,   471,    98,   157,   395,
      10,    15,    32,    34,    35,    40,    41,   402,   403,   404,
     405,   406,     6,   418,   425,     8,   440,   471,    10,    29,
     363,   471,    73,   160,   368,    26,    32,    34,    35,    40,
      41,   373,   377,   378,   379,   380,   381,    29,   396,   407,
     471,     3,     3,     3,   471,    76,    85,   419,    10,    12,
      32,    34,    35,    40,    41,   426,   427,   428,   429,   430,
      10,   441,     6,     6,     7,   358,   471,    10,    29,   369,
     471,     3,     3,     3,    10,    11,   374,   471,    10,    98,
     107,   408,   409,     6,   471,   471,   471,    29,   420,   431,
     471,     3,     3,     3,   447,    14,    30,    31,    32,    33,
      34,    35,   442,   443,   444,   445,   446,   471,   161,     6,
       6,     7,   364,   471,    10,     6,   471,   471,   471,   382,
       6,     6,     7,   397,    29,   410,   471,   471,    10,    76,
     107,   432,   433,     6,   471,   471,   471,    58,    60,    61,
     111,   448,   449,   450,     8,     3,     3,     3,   471,   161,
       6,     6,     7,   370,   471,   107,   160,   383,   384,   471,
      99,   471,    10,     6,     6,     7,   421,    29,   434,   471,
       5,     6,     8,     8,   471,   471,   161,    29,   385,     6,
       4,     6,     7,   472,   471,    77,   471,    10,   451,     8,
     471,    10,   471,    99,     6,   472,    59,   386,   472,   471,
      77,     6,   161,   471
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

  case 378:

    {/*parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  */
   ;}
    break;

  case 379:

    {/*parserData->tempVal = $1; 
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair); */
  ;}
    break;

  case 382:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
	;}
    break;

  case 385:

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

  case 386:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	;}
    break;

  case 393:

    {
	parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	//osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = $3;
;}
    break;

  case 394:

    {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
;}
    break;

  case 395:

    {parserData->tmpOtherValue=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 396:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 397:

    {
parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 398:

    {
parserData->tmpOtherDescription=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 401:

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

  case 402:

    {//	if(parserData->otherVarStruct->numberOfVar <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	;}
    break;

  case 403:

    {std::cout << "matched idx= and the quote; now match INTEGER";;}
    break;

  case 404:

    {;}
    break;

  case 408:

    {  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 413:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
;}
    break;

  case 414:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 418:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(3) - (4)].ival);   ;}
    break;

  case 419:

    {
        parserData->objValPair->value = (yyvsp[(1) - (1)].ival);                  
	parserData->objVals.push_back( parserData->objValPair);

;}
    break;

  case 420:

    {
        parserData->objValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->objVals.push_back( parserData->objValPair);
  ;}
    break;

  case 423:

    { 	 		
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

  case 424:

    {  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	;}
    break;

  case 425:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
	;}
    break;

  case 431:

    {
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
;}
    break;

  case 432:

    {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
;}
    break;

  case 433:

    {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 434:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherObjStruct->name = "";
;}
    break;

  case 435:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 436:

    {
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
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

  case 450:

    {
 
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}
 ;}
    break;

  case 451:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);

;}
    break;

  case 455:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 456:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 		
	;}
    break;

  case 457:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 	
	;}
    break;

  case 469:

    {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
;}
    break;

  case 470:

    {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 471:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherConStruct->name = "";
;}
    break;

  case 472:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 473:

    {
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 476:

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

  case 477:

    {//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	;}
    break;

  case 478:

    {;}
    break;

  case 480:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 481:

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

  case 485:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 487:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 493:

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

  case 494:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 495:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 496:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 498:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 501:

    {parserData->kounter++;;}
    break;

  case 502:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 503:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 506:

    {parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 508:

    {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
;}
    break;

  case 516:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 518:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 524:

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

  case 525:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 526:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 527:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 529:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 533:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 534:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
;}
    break;

  case 535:

    {parserData->itemContent = "";;}
    break;

  case 539:

    {parserData->itemContent = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 541:

    { parserData->outStr << (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 542:

    { parserData->outStr << (yyvsp[(1) - (1)].ival); /*free($1);*/ ;}
    break;

  case 543:

    { parserData->outStr << (yyvsp[(1) - (1)].dval); /*free($1);*/ ;}
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


