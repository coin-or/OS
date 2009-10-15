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
#define YYLAST   1013

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  412
/* YYNRULES -- Number of rules.  */
#define YYNRULES  705
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1135

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
     107,   109,   111,   112,   115,   117,   119,   123,   127,   129,
     132,   134,   137,   139,   143,   146,   148,   151,   153,   157,
     160,   162,   165,   167,   171,   174,   176,   179,   181,   185,
     188,   190,   193,   195,   199,   202,   204,   207,   209,   213,
     216,   218,   221,   223,   227,   230,   232,   236,   238,   243,
     245,   247,   250,   252,   256,   258,   261,   265,   267,   269,
     270,   273,   275,   277,   279,   283,   287,   289,   293,   295,
     298,   300,   301,   304,   309,   310,   313,   315,   317,   319,
     321,   323,   325,   328,   330,   334,   337,   339,   345,   347,
     349,   350,   353,   355,   357,   361,   365,   367,   369,   371,
     377,   379,   381,   382,   385,   387,   389,   393,   397,   399,
     401,   403,   409,   411,   413,   414,   417,   419,   421,   425,
     429,   431,   433,   435,   441,   443,   444,   446,   450,   452,
     454,   458,   460,   465,   467,   469,   472,   474,   478,   480,
     483,   487,   489,   491,   492,   495,   497,   499,   501,   505,
     509,   511,   515,   517,   520,   522,   523,   526,   531,   532,
     535,   537,   539,   541,   543,   545,   547,   550,   552,   556,
     559,   561,   564,   566,   570,   573,   575,   578,   580,   584,
     587,   589,   592,   594,   598,   601,   603,   606,   608,   612,
     615,   617,   621,   623,   628,   630,   632,   635,   637,   641,
     643,   646,   650,   652,   654,   655,   658,   660,   662,   664,
     668,   672,   674,   678,   680,   683,   685,   686,   689,   694,
     695,   698,   700,   702,   704,   706,   708,   710,   712,   714,
     716,   718,   720,   723,   725,   729,   732,   734,   737,   739,
     743,   746,   748,   751,   753,   757,   760,   762,   765,   767,
     771,   774,   776,   779,   781,   785,   788,   790,   794,   796,
     801,   803,   807,   808,   811,   815,   816,   819,   821,   823,
     825,   827,   831,   833,   837,   839,   843,   845,   849,   851,
     853,   855,   858,   860,   864,   865,   867,   869,   875,   877,
     879,   880,   883,   885,   887,   891,   895,   897,   899,   901,
     907,   909,   911,   912,   915,   917,   919,   923,   927,   929,
     931,   933,   939,   941,   943,   944,   947,   949,   951,   955,
     959,   961,   963,   965,   971,   973,   974,   976,   980,   982,
     984,   988,   990,   995,   997,   999,  1002,  1004,  1008,  1010,
    1013,  1017,  1019,  1021,  1022,  1025,  1027,  1029,  1031,  1035,
    1039,  1041,  1045,  1047,  1050,  1052,  1053,  1057,  1059,  1061,
    1062,  1065,  1068,  1071,  1074,  1077,  1081,  1085,  1089,  1093,
    1095,  1097,  1100,  1102,  1107,  1109,  1112,  1116,  1118,  1120,
    1121,  1124,  1126,  1128,  1133,  1137,  1146,  1150,  1152,  1154,
    1156,  1159,  1161,  1163,  1165,  1169,  1171,  1175,  1177,  1182,
    1184,  1186,  1189,  1191,  1195,  1197,  1200,  1204,  1206,  1208,
    1209,  1212,  1214,  1216,  1220,  1224,  1226,  1229,  1231,  1232,
    1237,  1241,  1244,  1245,  1249,  1250,  1255,  1257,  1259,  1266,
    1267,  1271,  1273,  1278,  1280,  1282,  1285,  1287,  1291,  1293,
    1296,  1302,  1304,  1309,  1311,  1313,  1314,  1318,  1320,  1325,
    1327,  1329,  1332,  1334,  1338,  1340,  1343,  1349,  1351,  1356,
    1357,  1361,  1363,  1368,  1370,  1372,  1375,  1377,  1381,  1383,
    1386,  1392,  1394,  1399,  1400,  1403,  1407,  1409,  1411,  1412,
    1415,  1417,  1419,  1421,  1423,  1428,  1432,  1434,  1438,  1440,
    1444,  1446,  1448,  1452,  1453,  1456,  1460,  1462,  1467,  1471,
    1474,  1476,  1477,  1481,  1482,  1487,  1489,  1491,  1493,  1498,
    1499,  1505,  1509,  1514,  1515,  1518,  1524,  1529,  1531,  1533,
    1534,  1537,  1541,  1543,  1544,  1547,  1549,  1551,  1553,  1555,
    1560,  1562,  1566,  1568,  1572,  1576,  1578,  1580,  1584,  1585,
    1588,  1592,  1594,  1599,  1603,  1606,  1608,  1609,  1613,  1614,
    1619,  1621,  1623,  1625,  1630,  1631,  1637,  1641,  1646,  1647,
    1650,  1656,  1661,  1663,  1665,  1666,  1669,  1673,  1675,  1676,
    1679,  1681,  1683,  1685,  1687,  1692,  1694,  1698,  1700,  1704,
    1708,  1710,  1712,  1716,  1717,  1720,  1724,  1726,  1731,  1735,
    1738,  1740,  1741,  1747,  1751,  1752,  1758,  1759,  1762,  1768,
    1772,  1773,  1774,  1778,  1780,  1782,  1784,  1786,  1791,  1793,
    1797,  1801,  1803,  1807,  1809,  1810,  1813,  1815,  1817,  1819,
    1821,  1822,  1827,  1829,  1830,  1834,  1839,  1841,  1845,  1846,
    1849,  1855,  1859,  1860,  1861,  1865,  1867,  1869,  1871,  1873,
    1878,  1880,  1884,  1888,  1890,  1894,  1896,  1897,  1900,  1902,
    1904,  1906,  1908,  1909,  1914,  1916,  1918,  1921,  1923,  1925,
    1927,  1929,  1931,  1933,  1935,  1936
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   232,   283,   317,   396,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   195,    -1,   198,    -1,   201,    -1,   204,
      -1,   207,    -1,   210,    -1,   213,    -1,   216,    -1,   176,
     177,   183,    -1,    88,    -1,   178,    -1,   179,    -1,   178,
     179,    -1,   180,    -1,   181,    -1,   182,    -1,    36,     3,
     577,    -1,    37,    -1,    32,     3,   577,    -1,    33,    -1,
      24,     8,     6,     8,    -1,   184,    -1,   185,    -1,    10,
      89,    -1,    11,    -1,    10,   186,    89,    -1,   187,    -1,
     186,   187,    -1,   188,   189,   194,    -1,   134,    -1,   190,
      -1,    -1,   190,   191,    -1,   192,    -1,   193,    -1,    34,
       3,     8,    -1,    32,     3,     8,    -1,    33,    -1,    10,
     135,    -1,    11,    -1,   196,   197,    -1,    96,    -1,    10,
       4,    97,    -1,    10,    97,    -1,    11,    -1,   199,   200,
      -1,   120,    -1,    10,     4,   121,    -1,    10,   121,    -1,
      11,    -1,   202,   203,    -1,   118,    -1,    10,     4,   119,
      -1,    10,   119,    -1,    11,    -1,   205,   206,    -1,    92,
      -1,    10,     4,    93,    -1,    10,    93,    -1,    11,    -1,
     208,   209,    -1,    94,    -1,    10,     4,    95,    -1,    10,
      95,    -1,    11,    -1,   211,   212,    -1,   126,    -1,    10,
       4,   127,    -1,    10,   127,    -1,    11,    -1,   214,   215,
      -1,   142,    -1,    10,     4,   143,    -1,    10,   143,    -1,
      11,    -1,   217,   218,   219,    -1,   108,    -1,    19,   577,
       6,   577,    -1,   220,    -1,   221,    -1,    10,   109,    -1,
      11,    -1,    10,   222,   109,    -1,   223,    -1,   222,   223,
      -1,   224,   225,   231,    -1,   106,    -1,   226,    -1,    -1,
     226,   227,    -1,   228,    -1,   229,    -1,   230,    -1,    34,
       3,   577,    -1,    40,     3,   577,    -1,    41,    -1,    32,
       3,   577,    -1,    33,    -1,    10,   107,    -1,    11,    -1,
      -1,    50,    11,    -1,    50,    10,   233,    51,    -1,    -1,
     233,   234,    -1,   235,    -1,   238,    -1,   246,    -1,   254,
      -1,   262,    -1,   267,    -1,   236,   237,    -1,   136,    -1,
      10,     4,   137,    -1,    10,   137,    -1,    11,    -1,   239,
     240,    10,   245,    69,    -1,    68,    -1,   241,    -1,    -1,
     241,   242,    -1,   243,    -1,   244,    -1,    38,     3,   577,
      -1,    32,     3,   577,    -1,    33,    -1,     6,    -1,     7,
      -1,   247,   248,    10,   253,    71,    -1,    70,    -1,   249,
      -1,    -1,   249,   250,    -1,   251,    -1,   252,    -1,    38,
       3,   577,    -1,    32,     3,   577,    -1,    33,    -1,     6,
      -1,     7,    -1,   255,   256,    10,   261,    67,    -1,    66,
      -1,   257,    -1,    -1,   257,   258,    -1,   259,    -1,   260,
      -1,    38,     3,   577,    -1,    32,     3,   577,    -1,    33,
      -1,     6,    -1,     7,    -1,   263,   264,    10,   266,    65,
      -1,    64,    -1,    -1,   265,    -1,    32,     3,   577,    -1,
      33,    -1,     6,    -1,   268,   269,   270,    -1,   108,    -1,
      19,   577,     6,   577,    -1,   271,    -1,   272,    -1,    10,
     109,    -1,    11,    -1,    10,   273,   109,    -1,   274,    -1,
     273,   274,    -1,   275,   276,   282,    -1,   106,    -1,   277,
      -1,    -1,   277,   278,    -1,   279,    -1,   280,    -1,   281,
      -1,    34,     3,   577,    -1,    40,     3,   577,    -1,    41,
      -1,    32,     3,   577,    -1,    33,    -1,    10,   107,    -1,
      11,    -1,    -1,    52,    11,    -1,    52,    10,   284,    53,
      -1,    -1,   284,   285,    -1,   286,    -1,   289,    -1,   292,
      -1,   295,    -1,   298,    -1,   301,    -1,   287,   288,    -1,
      82,    -1,    10,     4,    83,    -1,    10,    83,    -1,    11,
      -1,   290,   291,    -1,    80,    -1,    10,     6,    81,    -1,
      10,    81,    -1,    11,    -1,   293,   294,    -1,   146,    -1,
      10,     6,   147,    -1,    10,   147,    -1,    11,    -1,   296,
     297,    -1,   140,    -1,    10,     4,   141,    -1,    10,   141,
      -1,    11,    -1,   299,   300,    -1,   122,    -1,    10,   576,
     123,    -1,    10,   123,    -1,    11,    -1,   302,   303,   304,
      -1,   108,    -1,    19,   577,     6,   577,    -1,   305,    -1,
     306,    -1,    10,   109,    -1,    11,    -1,    10,   307,   109,
      -1,   308,    -1,   307,   308,    -1,   309,   310,   316,    -1,
     106,    -1,   311,    -1,    -1,   311,   312,    -1,   313,    -1,
     314,    -1,   315,    -1,    34,     3,   577,    -1,    40,     3,
     577,    -1,    41,    -1,    32,     3,   577,    -1,    33,    -1,
      10,   107,    -1,    11,    -1,    -1,    54,    11,    -1,    54,
      10,   318,    55,    -1,    -1,   318,   319,    -1,   320,    -1,
     323,    -1,   326,    -1,   329,    -1,   332,    -1,   335,    -1,
     351,    -1,   359,    -1,   367,    -1,   375,    -1,   380,    -1,
     321,   322,    -1,   130,    -1,    10,     4,   131,    -1,    10,
     131,    -1,    11,    -1,   324,   325,    -1,   132,    -1,    10,
       4,   133,    -1,    10,   133,    -1,    11,    -1,   327,   328,
      -1,   116,    -1,    10,     4,   117,    -1,    10,   117,    -1,
      11,    -1,   330,   331,    -1,    62,    -1,    10,     4,    63,
      -1,    10,    63,    -1,    11,    -1,   333,   334,    -1,    86,
      -1,    10,     4,    87,    -1,    10,    87,    -1,    11,    -1,
     336,   337,   338,    -1,   144,    -1,    25,     8,     6,     8,
      -1,    11,    -1,    10,   339,   145,    -1,    -1,   339,   340,
      -1,   138,   341,   347,    -1,    -1,   341,   342,    -1,   345,
      -1,   343,    -1,   344,    -1,   346,    -1,    36,     3,     8,
      -1,    37,    -1,    30,     3,     8,    -1,    31,    -1,    38,
       3,     8,    -1,    39,    -1,    32,     3,     8,    -1,    33,
      -1,   348,    -1,   349,    -1,    10,   139,    -1,    11,    -1,
      10,   350,   139,    -1,    -1,     7,    -1,     6,    -1,   352,
     353,    10,   358,   153,    -1,   152,    -1,   354,    -1,    -1,
     354,   355,    -1,   356,    -1,   357,    -1,    38,     3,   577,
      -1,    32,     3,   577,    -1,    33,    -1,     6,    -1,     7,
      -1,   360,   361,    10,   366,   155,    -1,   154,    -1,   362,
      -1,    -1,   362,   363,    -1,   364,    -1,   365,    -1,    38,
       3,   577,    -1,    32,     3,   577,    -1,    33,    -1,     6,
      -1,     7,    -1,   368,   369,    10,   374,   151,    -1,   150,
      -1,   370,    -1,    -1,   370,   371,    -1,   372,    -1,   373,
      -1,    38,     3,   577,    -1,    32,     3,   577,    -1,    33,
      -1,     6,    -1,     7,    -1,   376,   377,    10,   379,   149,
      -1,   148,    -1,    -1,   378,    -1,    32,     3,   577,    -1,
      33,    -1,     6,    -1,   381,   382,   383,    -1,   108,    -1,
      19,   577,     6,   577,    -1,   384,    -1,   385,    -1,    10,
     109,    -1,    11,    -1,    10,   386,   109,    -1,   387,    -1,
     386,   387,    -1,   388,   389,   395,    -1,   106,    -1,   390,
      -1,    -1,   390,   391,    -1,   392,    -1,   393,    -1,   394,
      -1,    34,     3,   577,    -1,    40,     3,   577,    -1,    41,
      -1,    32,     3,   577,    -1,    33,    -1,    10,   107,    -1,
      11,    -1,    -1,   397,   398,   405,    -1,    56,    -1,   399,
      -1,    -1,   399,   400,    -1,   401,   577,    -1,   402,   577,
      -1,   403,   577,    -1,   404,   577,    -1,    22,   577,     6,
      -1,    27,   577,     6,    -1,    13,   577,     6,    -1,    16,
     577,     6,    -1,   406,    -1,   407,    -1,    10,    57,    -1,
      11,    -1,    10,   408,   559,    57,    -1,   409,    -1,   408,
     409,    -1,   410,   411,   416,    -1,   124,    -1,   412,    -1,
      -1,   412,   413,    -1,   414,    -1,   415,    -1,    28,   577,
       6,   577,    -1,    42,     3,   577,    -1,    10,   417,   437,
     438,   489,   515,   541,   558,    -1,   418,   419,   425,    -1,
     130,    -1,   420,    -1,   421,    -1,   420,   421,    -1,   422,
      -1,   423,    -1,   424,    -1,    36,     3,   577,    -1,    37,
      -1,    32,     3,   577,    -1,    33,    -1,    24,     8,     6,
       8,    -1,   426,    -1,   427,    -1,    10,   131,    -1,    11,
      -1,    10,   428,   131,    -1,   429,    -1,   428,   429,    -1,
     430,   431,   436,    -1,   134,    -1,   432,    -1,    -1,   432,
     433,    -1,   434,    -1,   435,    -1,    36,     3,     8,    -1,
      32,     3,     8,    -1,    33,    -1,    10,   135,    -1,    11,
      -1,    -1,    96,    10,     4,    97,    -1,    96,    10,    97,
      -1,    96,    11,    -1,    -1,   162,   439,   440,    -1,    -1,
      21,   577,     6,   577,    -1,    11,    -1,   441,    -1,    10,
     442,   453,   463,   473,   163,    -1,    -1,   443,   444,   445,
      -1,   156,    -1,    26,   577,     6,   577,    -1,   446,    -1,
     447,    -1,    10,   157,    -1,    11,    -1,    10,   448,   157,
      -1,   449,    -1,   448,   449,    -1,   450,   451,    10,   452,
     161,    -1,   160,    -1,    29,   577,     6,   577,    -1,     6,
      -1,     7,    -1,    -1,   454,   455,   456,    -1,   158,    -1,
      26,   577,     6,   577,    -1,   457,    -1,   458,    -1,    10,
     159,    -1,    11,    -1,    10,   459,   159,    -1,   460,    -1,
     459,   460,    -1,   461,   462,    10,     4,   161,    -1,   160,
      -1,    29,   577,     6,   577,    -1,    -1,   464,   465,   466,
      -1,    72,    -1,    26,   577,     6,   577,    -1,   467,    -1,
     468,    -1,    10,    73,    -1,    11,    -1,    10,   469,    73,
      -1,   470,    -1,   469,   470,    -1,   471,   472,    10,     4,
     161,    -1,   160,    -1,    29,   577,     6,   577,    -1,    -1,
     473,   474,    -1,   475,   476,   483,    -1,   106,    -1,   477,
      -1,    -1,   477,   478,    -1,   479,    -1,   480,    -1,   481,
      -1,   482,    -1,    26,   577,     6,   577,    -1,    40,     3,
     577,    -1,    41,    -1,    34,     3,   577,    -1,    35,    -1,
      32,     3,   577,    -1,    33,    -1,    11,    -1,    10,   484,
     107,    -1,    -1,   484,   485,    -1,   486,   487,   488,    -1,
     160,    -1,    29,   577,     6,   577,    -1,    10,   578,   161,
      -1,    10,   161,    -1,    11,    -1,    -1,   100,   490,   491,
      -1,    -1,    18,   577,     6,   577,    -1,   492,    -1,   493,
      -1,    11,    -1,    10,   494,   500,   101,    -1,    -1,   156,
     495,    10,   496,   157,    -1,   156,   495,    11,    -1,    15,
     577,     6,   577,    -1,    -1,   496,   497,    -1,    98,   498,
      10,   499,    99,    -1,    29,   577,     6,   577,    -1,     6,
      -1,     7,    -1,    -1,   500,   501,    -1,   502,   503,   509,
      -1,   106,    -1,    -1,   503,   504,    -1,   505,    -1,   506,
      -1,   507,    -1,   508,    -1,    15,   577,     6,   577,    -1,
      41,    -1,    40,     3,   577,    -1,    35,    -1,    34,     3,
     577,    -1,    32,     3,   577,    -1,    33,    -1,    11,    -1,
      10,   510,   107,    -1,    -1,   510,   511,    -1,   512,   513,
     514,    -1,    98,    -1,    29,   577,     6,   577,    -1,    10,
     578,    99,    -1,    10,    99,    -1,    11,    -1,    -1,    78,
     516,   517,    -1,    -1,    17,   577,     6,   577,    -1,   518,
      -1,   519,    -1,    11,    -1,    10,   520,   526,    79,    -1,
      -1,    84,   521,    10,   522,    85,    -1,    84,   521,    11,
      -1,    12,   577,     6,   577,    -1,    -1,   522,   523,    -1,
      76,   524,    10,   525,    77,    -1,    29,   577,     6,   577,
      -1,     7,    -1,     6,    -1,    -1,   526,   527,    -1,   528,
     529,   535,    -1,   106,    -1,    -1,   529,   530,    -1,   531,
      -1,   532,    -1,   533,    -1,   534,    -1,    12,   577,     6,
     577,    -1,    41,    -1,    40,     3,   577,    -1,    35,    -1,
      34,     3,   577,    -1,    32,     3,   577,    -1,    33,    -1,
      11,    -1,    10,   536,   107,    -1,    -1,   536,   537,    -1,
     538,   539,   540,    -1,    76,    -1,    29,   577,     6,   577,
      -1,    10,   578,    77,    -1,    10,    77,    -1,    11,    -1,
      -1,   112,   542,    10,   544,   113,    -1,   112,   542,    11,
      -1,    -1,    20,     8,     6,   543,     8,    -1,    -1,   544,
     545,    -1,   110,   546,    10,   553,   111,    -1,   110,   546,
      11,    -1,    -1,    -1,   546,   547,   548,    -1,   549,    -1,
     550,    -1,   551,    -1,   552,    -1,    14,     8,     6,     8,
      -1,    35,    -1,    34,     3,   577,    -1,    30,     3,     8,
      -1,    31,    -1,    32,     3,     8,    -1,    33,    -1,    -1,
     553,   554,    -1,   555,    -1,   556,    -1,    60,    -1,    61,
      -1,    -1,    58,     5,   557,    59,    -1,   125,    -1,    -1,
     114,   560,   561,    -1,    23,   577,     6,   577,    -1,    11,
      -1,    10,   562,   115,    -1,    -1,   562,   563,    -1,   128,
     564,    10,   571,   129,    -1,   128,   564,    11,    -1,    -1,
      -1,   564,   565,   566,    -1,   567,    -1,   568,    -1,   569,
      -1,   570,    -1,    14,     8,     6,     8,    -1,    35,    -1,
      34,     3,     8,    -1,    30,     3,     8,    -1,    31,    -1,
      32,     3,     8,    -1,    33,    -1,    -1,   571,   572,    -1,
     573,    -1,   574,    -1,    60,    -1,    61,    -1,    -1,    58,
       5,   575,    59,    -1,     6,    -1,     7,    -1,   580,     8,
      -1,     4,    -1,     6,    -1,     7,    -1,   165,    -1,   166,
      -1,   167,    -1,   168,    -1,    -1,   580,   579,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   166,   167,   169,   169,   170,   172,   172,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   186,
     188,   197,   206,   206,   209,   219,   225,   227,   228,   230,
     231,   233,   243,   247,   253,   253,   255,   257,   257,   259,
     263,   268,   275,   275,   277,   277,   284,   292,   293,   295,
     295,   298,   300,   307,   309,   310,   312,   314,   321,   323,
     324,   326,   328,   335,   337,   338,   340,   342,   349,   351,
     352,   354,   356,   363,   365,   366,   368,   370,   377,   379,
     380,   382,   384,   391,   393,   394,   396,   398,   404,   411,
     415,   420,   420,   422,   424,   424,   426,   430,   435,   443,
     443,   446,   452,   458,   466,   469,   470,   473,   474,   476,
     476,   480,   480,   481,   483,   483,   486,   487,   488,   489,
     490,   491,   494,   496,   503,   505,   506,   508,   511,   517,
     522,   522,   525,   532,   540,   550,   551,   554,   555,   557,
     560,   566,   571,   571,   574,   581,   589,   597,   598,   601,
     602,   604,   607,   613,   618,   618,   621,   628,   636,   648,
     649,   652,   653,   656,   659,   665,   666,   672,   673,   676,
     679,   681,   687,   694,   698,   703,   703,   705,   707,   707,
     709,   713,   718,   726,   726,   729,   735,   741,   749,   752,
     753,   756,   757,   759,   759,   763,   763,   764,   766,   766,
     769,   770,   771,   772,   773,   774,   777,   779,   786,   788,
     789,   791,   793,   800,   802,   803,   805,   807,   814,   816,
     817,   819,   821,   828,   830,   831,   833,   835,   842,   844,
     845,   848,   850,   856,   863,   867,   872,   872,   874,   876,
     876,   878,   882,   887,   895,   895,   898,   904,   910,   918,
     921,   922,   925,   926,   928,   928,   931,   931,   932,   934,
     934,   937,   938,   939,   940,   941,   942,   943,   944,   945,
     946,   947,   950,   952,   959,   961,   962,   964,   966,   973,
     975,   976,   978,   980,   987,   989,   990,   992,   994,  1001,
    1003,  1004,  1006,  1008,  1015,  1017,  1018,  1020,  1022,  1028,
    1034,  1034,  1036,  1036,  1038,  1040,  1040,  1043,  1055,  1056,
    1057,  1059,  1060,  1062,  1063,  1065,  1066,  1068,  1069,  1071,
    1071,  1073,  1073,  1075,  1086,  1090,  1091,  1094,  1097,  1103,
    1108,  1108,  1111,  1118,  1126,  1135,  1136,  1139,  1140,  1142,
    1145,  1151,  1156,  1156,  1159,  1166,  1174,  1182,  1183,  1186,
    1187,  1190,  1193,  1199,  1204,  1204,  1207,  1214,  1222,  1234,
    1235,  1238,  1239,  1242,  1245,  1252,  1253,  1259,  1260,  1263,
    1267,  1269,  1275,  1282,  1286,  1291,  1291,  1293,  1295,  1295,
    1297,  1301,  1306,  1314,  1314,  1317,  1323,  1329,  1337,  1340,
    1341,  1344,  1345,  1347,  1347,  1350,  1350,  1352,  1354,  1364,
    1364,  1367,  1368,  1369,  1370,  1373,  1381,  1389,  1397,  1405,
    1405,  1407,  1407,  1409,  1411,  1411,  1413,  1420,  1426,  1431,
    1431,  1433,  1433,  1435,  1443,  1451,  1454,  1456,  1459,  1468,
    1468,  1471,  1483,  1489,  1491,  1492,  1494,  1495,  1497,  1507,
    1511,  1517,  1517,  1519,  1521,  1521,  1523,  1526,  1531,  1538,
    1538,  1540,  1540,  1547,  1555,  1556,  1558,  1558,  1561,  1562,
    1565,  1566,  1568,  1569,  1571,  1572,  1578,  1578,  1580,  1582,
    1582,  1584,  1587,  1594,  1598,  1604,  1604,  1606,  1608,  1608,
    1610,  1616,  1622,  1625,  1626,  1629,  1629,  1631,  1634,  1641,
    1645,  1651,  1651,  1653,  1655,  1655,  1657,  1663,  1669,  1673,
    1673,  1675,  1678,  1685,  1689,  1695,  1695,  1697,  1699,  1699,
    1701,  1707,  1713,  1716,  1716,  1718,  1732,  1739,  1751,  1751,
    1754,  1755,  1761,  1768,  1775,  1784,  1785,  1788,  1789,  1792,
    1793,  1795,  1796,  1798,  1798,  1800,  1805,  1807,  1813,  1817,
    1818,  1821,  1822,  1824,  1825,  1835,  1835,  1837,  1839,  1841,
    1842,  1851,  1853,  1857,  1857,  1859,  1861,  1864,  1868,  1874,
    1874,  1876,  1879,  1887,  1888,  1890,  1890,  1890,  1890,  1892,
    1901,  1904,  1910,  1916,  1922,  1927,  1930,  1931,  1951,  1951,
    1953,  1968,  1973,  1975,  1975,  1975,  1979,  1980,  1982,  1983,
    1993,  1993,  1995,  1997,  2000,  2001,  2011,  2013,  2018,  2018,
    2020,  2022,  2025,  2029,  2035,  2035,  2037,  2040,  2042,  2042,
    2044,  2044,  2044,  2044,  2046,  2049,  2052,  2058,  2064,  2070,
    2075,  2077,  2078,  2081,  2081,  2083,  2099,  2104,  2106,  2106,
    2106,  2110,  2111,  2116,  2123,  2122,  2138,  2138,  2141,  2148,
    2157,  2158,  2158,  2162,  2162,  2162,  2162,  2164,  2177,  2183,
    2191,  2194,  2197,  2200,  2202,  2203,  2206,  2211,  2218,  2218,
    2221,  2220,  2226,  2236,  2236,  2238,  2240,  2240,  2242,  2242,
    2245,  2252,  2254,  2256,  2255,  2260,  2260,  2260,  2260,  2262,
    2277,  2284,  2293,  2299,  2302,  2308,  2310,  2311,  2313,  2318,
    2324,  2324,  2327,  2326,  2332,  2333,  2335,  2338,  2339,  2340,
    2344,  2345,  2346,  2347,  2349,  2350
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
  "generalSubstatusStart", "generalSubstatusAttributes",
  "generalSubstatusAttList", "generalSubstatusATT",
  "generalSubstatusNameATT", "generalSubstatusDescriptionATT",
  "generalSubstatusEnd", "generalMessage", "generalMessageStart",
  "generalMessageContent", "serviceURI", "serviceURIStart",
  "serviceURIContent", "serviceName", "serviceNameStart",
  "serviceNameContent", "instanceName", "instanceNameStart",
  "instanceNameContent", "jobID", "jobIDStart", "jobIDContent",
  "solverInvoked", "solverInvokedStart", "solverInvokedContent",
  "timeStamp", "timeStampStart", "timeStampContent", "generalOtherResults",
  "generalOtherResultsStart", "generalOtherResultsAttList",
  "generalOtherResultsContent", "generalOtherResultsEmpty",
  "generalOtherResultsBody", "generalOtherResultSEQ", "generalOtherResult",
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
  "systemOtherResultsBody", "systemOtherResultSEQ", "systemOtherResult",
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
  "serviceOtherResultSEQ", "serviceOtherResult", "serviceOtherResultStart",
  "serviceOtherAttributes", "serviceOtherAttList", "serviceOtherAtt",
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
  "jobOtherResultSEQ", "jobOtherResult", "jobOtherResultStart",
  "jobOtherAttributes", "jobOtherAttList", "jobOtherAtt",
  "jobOtherNameATT", "jobOtherValueATT", "jobOtherDescriptionATT",
  "jobOtherEnd", "optimizationElement", "OptimizationStart",
  "optimizationAttributes", "optimizationAttList", "optimizationATT",
  "optimizationNumberOfSolutionsATT", "optimizationNumberOfVariablesATT",
  "optimizationNumberOfConstraintsATT",
  "optimizationNumberOfObjectivesATT", "optimizationContent",
  "optimizationEmpty", "optimizationBody", "solutionSEQ", "solution",
  "solutionStart", "solutionAttributes", "solutionAttList", "solutionATT",
  "targetObjectiveIdxATT", "weightedObjectivesATT", "solutionBody",
  "solutionStatus", "solutionStatusStart", "solutionStatusAttributes",
  "solutionStatusAttList", "solutionStatusATT", "solutionStatusTypeATT",
  "solutionStatusDescriptionATT", "solutionStatusNumberOfATT",
  "solutionStatusContent", "solutionStatusEmpty", "solutionStatusBody",
  "solutionSubstatusSEQ", "solutionSubstatus", "solutionSubstatusStart",
  "solutionSubstatusAttributes", "solutionSubstatusAttList",
  "solutionSubstatusATT", "solutionSubstatusTypeATT",
  "solutionSubstatusDescriptionATT", "solutionSubstatusEnd",
  "solutionMessage", "variables", "numberOfOtherVariableResults",
  "variablesContent", "variablesBody", "variableValues",
  "variableValuesStart", "numberOfVarATT", "variableValuesContent",
  "variableValuesEmpty", "variableValuesBody", "varValueSEQ", "varValue",
  "varValueStart", "varIdxATT", "varVal", "variableValuesString",
  "variableValuesStringStart", "numberOfVarStringATT",
  "variableValuesStringContent", "variableValuesStringEmpty",
  "variableValuesStringBody", "varValueStringSEQ", "varValueString",
  "varValueStringStart", "varStrIdxATT", "basisStatus", "basisStatusStart",
  "numberOfBasisVarATT", "basisStatusContent", "basisStatusEmpty",
  "basisStatusBody", "basisVarSEQ", "basisVar", "basisVarStart",
  "basisVarIdxATT", "otherVariableResultsSEQ", "otherVariableResult",
  "otherVariableResultStart", "otherVariableResultAttributes",
  "otherVariableResultAttList", "otherVariableResultATT",
  "numberOfOtherVariableResultsATT", "otherVariableResultValueATT",
  "otherVariableResultNameATT", "otherVariableResultDescriptionATT",
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
  "otherSolutionResults", "numberOfOtherSolutionResults", "@1",
  "otherSolutionResultList", "anotherSolutionResult",
  "anotherSolutionResultAttList", "@2", "anotherSolutionResultAtt",
  "numberOfOtherSolutionResultItems", "anotherSolutionResultNameATT",
  "anotherSolutionResultCategoryATT", "anotherSolutionDescriptionATT",
  "anotherSolutionItemList", "anotherSolutionItem",
  "otherSolutionItemEmpty", "otherSolutionItemContent", "@3",
  "solutionEnd", "otherSolverOutput", "numberOfSolverOutputsATT",
  "otherSolverOutputBody", "solverOutputSEQ", "solverOutput",
  "solverOutputAttList", "@4", "solverOutputAtt",
  "numberOfSolverOutputItems", "solverOutputNameATT",
  "solverOutputCategoryATT", "solverOutputDescriptionATT",
  "solverOutputItemList", "solverOutputItem", "solverOutputItemEmpty",
  "solverOutputItemContent", "@5", "aNumber", "quote", "ElementValue",
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
     188,   189,   190,   190,   191,   191,   192,   193,   193,   194,
     194,   195,   196,   197,   197,   197,   198,   199,   200,   200,
     200,   201,   202,   203,   203,   203,   204,   205,   206,   206,
     206,   207,   208,   209,   209,   209,   210,   211,   212,   212,
     212,   213,   214,   215,   215,   215,   216,   217,   218,   219,
     219,   220,   220,   221,   222,   222,   223,   224,   225,   226,
     226,   227,   227,   227,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   232,   233,   233,   234,   234,   234,   234,
     234,   234,   235,   236,   237,   237,   237,   238,   239,   240,
     241,   241,   242,   242,   243,   244,   244,   245,   245,   246,
     247,   248,   249,   249,   250,   250,   251,   252,   252,   253,
     253,   254,   255,   256,   257,   257,   258,   258,   259,   260,
     260,   261,   261,   262,   263,   264,   264,   265,   265,   266,
     267,   268,   269,   270,   270,   271,   271,   272,   273,   273,
     274,   275,   276,   277,   277,   278,   278,   278,   279,   280,
     280,   281,   281,   282,   282,   283,   283,   283,   284,   284,
     285,   285,   285,   285,   285,   285,   286,   287,   288,   288,
     288,   289,   290,   291,   291,   291,   292,   293,   294,   294,
     294,   295,   296,   297,   297,   297,   298,   299,   300,   300,
     300,   301,   302,   303,   304,   304,   305,   305,   306,   307,
     307,   308,   309,   310,   311,   311,   312,   312,   312,   313,
     314,   314,   315,   315,   316,   316,   317,   317,   317,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   320,   321,   322,   322,   322,   323,   324,   325,
     325,   325,   326,   327,   328,   328,   328,   329,   330,   331,
     331,   331,   332,   333,   334,   334,   334,   335,   336,   337,
     338,   338,   339,   339,   340,   341,   341,   342,   342,   342,
     342,   343,   343,   344,   344,   345,   345,   346,   346,   347,
     347,   348,   348,   349,   349,   350,   350,   351,   352,   353,
     354,   354,   355,   355,   356,   357,   357,   358,   358,   359,
     360,   361,   362,   362,   363,   363,   364,   365,   365,   366,
     366,   367,   368,   369,   370,   370,   371,   371,   372,   373,
     373,   374,   374,   375,   376,   377,   377,   378,   378,   379,
     380,   381,   382,   383,   383,   384,   384,   385,   386,   386,
     387,   388,   389,   390,   390,   391,   391,   391,   392,   393,
     393,   394,   394,   395,   395,   396,   396,   397,   398,   399,
     399,   400,   400,   400,   400,   401,   402,   403,   404,   405,
     405,   406,   406,   407,   408,   408,   409,   410,   411,   412,
     412,   413,   413,   414,   415,   416,   417,   418,   419,   420,
     420,   421,   421,   421,   422,   422,   423,   423,   424,   425,
     425,   426,   426,   427,   428,   428,   429,   430,   431,   432,
     432,   433,   433,   434,   435,   435,   436,   436,   437,   437,
     437,   437,   438,   438,   439,   439,   440,   440,   441,   442,
     442,   443,   444,   445,   445,   446,   446,   447,   448,   448,
     449,   450,   451,   452,   452,   453,   453,   454,   455,   456,
     456,   457,   457,   458,   459,   459,   460,   461,   462,   463,
     463,   464,   465,   466,   466,   467,   467,   468,   469,   469,
     470,   471,   472,   473,   473,   474,   475,   476,   477,   477,
     478,   478,   478,   478,   479,   480,   480,   481,   481,   482,
     482,   483,   483,   484,   484,   485,   486,   487,   488,   488,
     488,   489,   489,   490,   490,   491,   491,   492,   493,   494,
     494,   494,   495,   496,   496,   497,   498,   499,   499,   500,
     500,   501,   502,   503,   503,   504,   504,   504,   504,   505,
     506,   506,   507,   507,   508,   508,   509,   509,   510,   510,
     511,   512,   513,   514,   514,   514,   515,   515,   516,   516,
     517,   517,   518,   519,   520,   520,   520,   521,   522,   522,
     523,   524,   525,   525,   526,   526,   527,   528,   529,   529,
     530,   530,   530,   530,   531,   532,   532,   533,   533,   534,
     534,   535,   535,   536,   536,   537,   538,   539,   540,   540,
     540,   541,   541,   541,   543,   542,   544,   544,   545,   545,
     546,   547,   546,   548,   548,   548,   548,   549,   550,   550,
     551,   551,   552,   552,   553,   553,   554,   554,   555,   555,
     557,   556,   558,   559,   559,   560,   561,   561,   562,   562,
     563,   563,   564,   565,   564,   566,   566,   566,   566,   567,
     568,   568,   569,   569,   570,   570,   571,   571,   572,   572,
     573,   573,   575,   574,   576,   576,   577,   578,   578,   578,
     579,   579,   579,   579,   580,   580
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     3,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     3,     1,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     3,     3,     1,     2,
       1,     2,     1,     3,     2,     1,     2,     1,     3,     2,
       1,     2,     1,     3,     2,     1,     2,     1,     3,     2,
       1,     2,     1,     3,     2,     1,     2,     1,     3,     2,
       1,     2,     1,     3,     2,     1,     3,     1,     4,     1,
       1,     2,     1,     3,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     3,     3,     1,     3,     1,     2,
       1,     0,     2,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     2,     1,     5,     1,     1,
       0,     2,     1,     1,     3,     3,     1,     1,     1,     5,
       1,     1,     0,     2,     1,     1,     3,     3,     1,     1,
       1,     5,     1,     1,     0,     2,     1,     1,     3,     3,
       1,     1,     1,     5,     1,     0,     1,     3,     1,     1,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     3,     3,
       1,     3,     1,     2,     1,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     2,
       1,     2,     1,     3,     2,     1,     2,     1,     3,     2,
       1,     2,     1,     3,     2,     1,     2,     1,     3,     2,
       1,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     3,
       3,     1,     3,     1,     2,     1,     0,     2,     4,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     2,     1,     2,     1,     3,
       2,     1,     2,     1,     3,     2,     1,     2,     1,     3,
       2,     1,     2,     1,     3,     2,     1,     3,     1,     4,
       1,     3,     0,     2,     3,     0,     2,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     2,     1,     3,     0,     1,     1,     5,     1,     1,
       0,     2,     1,     1,     3,     3,     1,     1,     1,     5,
       1,     1,     0,     2,     1,     1,     3,     3,     1,     1,
       1,     5,     1,     1,     0,     2,     1,     1,     3,     3,
       1,     1,     1,     5,     1,     0,     1,     3,     1,     1,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     3,     3,
       1,     3,     1,     2,     1,     0,     3,     1,     1,     0,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     1,
       1,     2,     1,     4,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     4,     3,     8,     3,     1,     1,     1,
       2,     1,     1,     1,     3,     1,     3,     1,     4,     1,
       1,     2,     1,     3,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     3,     3,     1,     2,     1,     0,     4,
       3,     2,     0,     3,     0,     4,     1,     1,     6,     0,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       5,     1,     4,     1,     1,     0,     3,     1,     4,     1,
       1,     2,     1,     3,     1,     2,     5,     1,     4,     0,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       5,     1,     4,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     4,     3,     1,     3,     1,     3,
       1,     1,     3,     0,     2,     3,     1,     4,     3,     2,
       1,     0,     3,     0,     4,     1,     1,     1,     4,     0,
       5,     3,     4,     0,     2,     5,     4,     1,     1,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     3,     1,     1,     3,     0,     2,
       3,     1,     4,     3,     2,     1,     0,     3,     0,     4,
       1,     1,     1,     4,     0,     5,     3,     4,     0,     2,
       5,     4,     1,     1,     0,     2,     3,     1,     0,     2,
       1,     1,     1,     1,     4,     1,     3,     1,     3,     3,
       1,     1,     3,     0,     2,     3,     1,     4,     3,     2,
       1,     0,     5,     3,     0,     5,     0,     2,     5,     3,
       0,     0,     3,     1,     1,     1,     1,     4,     1,     3,
       3,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       0,     4,     1,     0,     3,     4,     1,     3,     0,     2,
       5,     3,     0,     0,     3,     1,     1,     1,     1,     4,
       1,     3,     3,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     0,     4,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,   111,     4,
       8,     6,     0,   195,     0,   114,   112,     0,   256,     7,
      20,    67,    72,    52,    87,    62,    57,    77,    82,     9,
      10,     0,    11,     0,    12,     0,    13,     0,    14,     0,
      15,     0,    16,     0,    17,     0,    18,     0,     0,   198,
     196,     0,   395,     0,     0,    30,     0,    28,     0,    21,
      22,    24,    25,    26,     0,    55,    51,     0,    60,    56,
       0,    65,    61,     0,    70,    66,     0,    75,    71,     0,
      80,    76,     0,    85,    81,   704,     0,   113,   164,   152,
     128,   140,   171,   123,   115,   116,     0,   117,   130,   118,
     142,   119,   154,   120,   165,   121,     0,     0,   259,   257,
     397,     0,   399,     0,   704,   704,     0,    35,    19,    32,
      33,    23,     0,    54,     0,    59,     0,    64,     0,    69,
       0,    74,     0,    79,     0,    84,     0,     0,     0,    92,
      86,    89,    90,     0,   126,   122,     0,   129,     0,   141,
       0,   153,     0,   168,     0,   166,   704,     0,   197,   212,
     207,   232,   227,   222,   217,   199,   200,     0,   201,     0,
     202,     0,   203,     0,   204,     0,   205,     0,     0,     2,
       0,   398,     0,    29,    27,    34,    40,     0,    37,    42,
      53,    58,    63,    68,    73,    78,    83,   704,   696,   700,
     701,   702,   703,   705,    97,    91,     0,    94,    99,     0,
     125,     0,     0,   136,     0,   131,   132,   133,     0,     0,
     148,     0,   143,   144,   145,     0,     0,   160,     0,   155,
     156,   157,   704,     0,     0,     0,   176,   170,   173,   174,
       0,   210,   206,     0,   215,   211,     0,   220,   216,     0,
     225,   221,     0,   230,   226,   704,     0,   258,   288,   293,
     371,   283,   273,   278,   298,   364,   352,   328,   340,   260,
     261,     0,   262,     0,   263,     0,   264,     0,   265,     0,
     266,     0,   267,   330,   268,   342,   269,   354,   270,   365,
     271,     0,     0,   412,   396,   409,   410,   704,   704,   704,
     704,   400,   704,   704,   704,   704,    31,    36,    38,     0,
      41,    88,    93,    95,     0,    98,   124,   137,   138,     0,
     704,   704,   149,   150,     0,   704,   704,   161,   162,     0,
     704,   704,   167,   169,     0,   704,   181,   175,     0,   178,
     183,     0,   209,     0,   214,     0,   219,     0,   224,   694,
     695,   229,     0,     0,     0,   237,   231,   234,   235,     0,
     276,   272,     0,   281,   277,     0,   286,   282,     0,   291,
     287,     0,   296,   292,     0,     0,     0,   329,     0,   341,
       0,   353,     0,   368,     0,   366,   704,     0,   411,   417,
     663,   414,   419,     0,     0,     0,     0,   401,   402,   403,
     404,     0,    50,    39,     0,    48,     0,    43,    44,    45,
       0,   110,    96,     0,   108,     0,     0,   106,   100,   101,
     102,   103,   127,   135,   134,   139,   147,   146,   151,   159,
     158,   163,   172,   177,   179,     0,   182,   208,   213,   218,
     223,   228,   704,   242,   236,     0,   239,   244,     0,   275,
       0,   280,     0,   285,     0,   290,     0,   295,     0,   302,
     300,   297,     0,     0,   336,     0,   331,   332,   333,     0,
       0,   348,     0,   343,   344,   345,     0,     0,   360,     0,
     355,   356,   357,   704,     0,     0,     0,   376,   370,   373,
     374,     0,   415,     0,     0,   418,   407,   408,   405,   406,
      49,     0,     0,   109,   704,   704,   704,     0,   194,   180,
       0,   192,     0,     0,   190,   184,   185,   186,   187,   233,
     238,   240,     0,   243,   274,   279,   284,   289,   294,     0,
       0,   337,   338,     0,   704,   704,   349,   350,     0,   704,
     704,   361,   362,     0,   704,   704,   367,   369,     0,   704,
     381,   375,     0,   378,   383,   704,     0,   413,     0,   416,
     704,     0,   420,   421,   422,    47,    46,   107,   104,   105,
     193,   704,   704,   704,     0,   255,   241,     0,   253,     0,
       0,   251,   245,   246,   247,   248,   299,   305,   301,   303,
     327,   335,   334,   339,   347,   346,   351,   359,   358,   363,
     372,   377,   379,     0,   382,     0,   668,   666,   664,   427,
     458,     0,     0,   704,   191,   188,   189,   254,   704,   704,
     704,   324,     0,   394,   380,     0,   392,     0,     0,   390,
     384,   385,   386,   387,   704,     0,     0,   462,     0,     0,
     437,     0,   435,     0,   428,   429,   431,   432,   433,   704,
     424,   252,   249,   250,     0,   322,     0,   314,     0,   318,
       0,   312,     0,   316,   306,   308,   309,   307,   310,   304,
     319,   320,   393,   704,   704,   704,   665,   667,   672,   669,
       0,   461,   464,   541,     0,   704,   704,     0,   442,   426,
     439,   440,   430,   423,   326,   325,   321,     0,     0,     0,
       0,     0,   391,   388,   389,   673,     0,   460,   704,     0,
     543,   586,     0,   436,   434,   441,   447,     0,   444,   449,
     323,   313,   317,   311,   315,   686,   671,     0,   459,     0,
     469,   466,   463,   467,   704,     0,   588,   631,   438,   443,
     445,     0,   448,     0,     0,     0,   683,     0,   685,     0,
     680,   674,   675,   676,   677,   678,   704,   471,   485,     0,
       0,   549,   547,   542,   545,   546,   704,     0,     0,     0,
       0,   457,   446,     0,   455,     0,   450,   451,   452,     0,
     690,   691,   670,   687,   688,   689,     0,     0,     0,     0,
     465,   487,   499,     0,   704,     0,   704,     0,   559,     0,
     594,   592,   587,   590,   591,     0,     0,   662,   425,   456,
       0,     0,   692,     0,   682,   684,   681,   501,   513,     0,
     704,     0,     0,     0,   476,   470,   473,   474,   544,   704,
       0,     0,   704,     0,   604,     0,   636,   633,   454,   453,
       0,   679,     0,   704,     0,     0,     0,   492,   486,   489,
     490,   704,   475,   481,     0,   478,     0,     0,   553,   551,
     548,   562,   560,   563,   589,   704,     0,     0,   634,     0,
     693,   516,   468,   514,   518,     0,     0,   506,   500,   503,
     504,   704,   491,   497,     0,   494,     0,   472,   477,   479,
     704,     0,   704,     0,     0,     0,   598,   596,   593,   607,
     605,   608,     0,   640,   632,   637,     0,   517,   704,   505,
     511,     0,   508,     0,   488,   493,   495,   704,     0,     0,
       0,   552,     0,   550,   554,   578,   576,   704,     0,   575,
       0,   572,     0,   570,   564,   565,   566,   567,   568,   561,
     704,     0,     0,   635,   641,   533,   531,   515,   704,     0,
     530,     0,   528,     0,   526,   519,   520,   521,   522,   523,
     502,   507,   509,   704,     0,     0,     0,   704,   483,   484,
       0,   704,     0,     0,     0,   704,   704,   704,   597,     0,
     595,   599,   623,   621,   704,     0,   620,     0,   617,     0,
     615,   609,   610,   611,   612,   613,   606,   654,   639,     0,
       0,     0,   704,   704,   704,     0,     0,   704,     0,   482,
     480,     0,     0,   581,   577,   579,     0,   704,   574,   573,
     571,   704,     0,     0,     0,   704,   704,   704,     0,     0,
       0,   651,     0,   653,     0,   648,   642,   643,   644,   645,
     646,   532,   536,   534,     0,   704,   529,   527,   525,   704,
       0,   498,   496,   704,   557,   558,     0,   704,     0,   569,
       0,     0,   626,   622,   624,     0,   704,   619,   618,   616,
       0,   658,   659,   638,   655,   656,   657,     0,     0,     0,
     704,   704,     0,   524,   512,   510,   556,   555,     0,     0,
     585,   580,   704,   603,   602,     0,   704,     0,   614,   660,
       0,   650,   652,   649,     0,     0,   540,   535,   704,   697,
     698,   699,   584,     0,   601,   600,     0,     0,   630,   625,
       0,   647,   704,   539,     0,   582,   583,   704,   629,     0,
     661,   537,   538,   627,   628
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    31,    58,    59,
      60,    61,    62,    63,   118,   119,   120,   187,   188,   189,
     309,   310,   407,   408,   409,   403,    32,    33,    66,    34,
      35,    69,    36,    37,    72,    38,    39,    75,    40,    41,
      78,    42,    43,    81,    44,    45,    84,    46,    47,    86,
     140,   141,   142,   206,   207,   208,   314,   315,   418,   419,
     420,   421,   412,    13,    48,    94,    95,    96,   145,    97,
      98,   146,   147,   215,   216,   217,   319,    99,   100,   148,
     149,   222,   223,   224,   324,   101,   102,   150,   151,   229,
     230,   231,   329,   103,   104,   154,   155,   334,   105,   106,
     157,   237,   238,   239,   338,   339,   340,   435,   436,   515,
     516,   517,   518,   509,    18,   107,   165,   166,   167,   242,
     168,   169,   245,   170,   171,   248,   172,   173,   251,   174,
     175,   254,   176,   177,   256,   356,   357,   358,   445,   446,
     447,   522,   523,   582,   583,   584,   585,   576,    52,   178,
     269,   270,   271,   361,   272,   273,   364,   274,   275,   367,
     276,   277,   370,   278,   279,   373,   280,   281,   375,   461,
     530,   589,   621,   664,   665,   666,   667,   668,   669,   670,
     671,   697,   282,   283,   376,   377,   466,   467,   468,   533,
     284,   285,   378,   379,   473,   474,   475,   538,   286,   287,
     380,   381,   480,   481,   482,   543,   288,   289,   384,   385,
     548,   290,   291,   387,   488,   489,   490,   552,   553,   554,
     603,   604,   630,   631,   632,   633,   624,   111,   112,   180,
     181,   301,   302,   303,   304,   305,   294,   295,   296,   390,
     391,   392,   494,   495,   562,   563,   564,   559,   610,   611,
     643,   644,   645,   646,   647,   648,   689,   690,   691,   717,
     718,   719,   741,   742,   776,   777,   778,   772,   637,   683,
     709,   732,   733,   758,   759,   795,   825,   826,   827,   854,
     855,   856,   891,   970,   792,   793,   821,   848,   849,   850,
     884,   885,   886,   918,   818,   819,   844,   878,   879,   880,
     911,   912,   913,   964,   842,   873,   874,   906,   907,   955,
     956,   957,   958,   959,   947,  1000,  1043,  1044,  1082,  1107,
     711,   735,   763,   764,   765,   798,   830,   893,   924,   972,
    1056,   831,   862,   863,   894,   934,   935,   936,   937,   938,
     939,   973,  1015,  1016,  1058,  1091,   737,   767,   802,   803,
     804,   834,   866,   941,   981,  1022,  1095,   867,   900,   901,
     942,   991,   992,   993,   994,   995,   996,  1023,  1064,  1065,
    1097,  1119,   769,   806,   902,   869,   905,   944,   999,  1036,
    1037,  1038,  1039,  1040,  1028,  1074,  1075,  1076,  1120,   808,
     493,   556,   608,   635,   679,   705,   727,   751,   752,   753,
     754,   755,   743,   783,   784,   785,   840,   352,   136,  1113,
     203,   137
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1032
static const yytype_int16 yypact[] =
{
      27,    36,    73,    48, -1032,    65, -1032,    41,    39, -1032,
   -1032, -1032,   156,    87,   -28, -1032, -1032,   209,   114, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032,   229, -1032,   227, -1032,   263, -1032,   299, -1032,   319,
   -1032,   321, -1032,   323, -1032,   325, -1032,   159,    40, -1032,
   -1032,   327,   136,   191,   207, -1032,   247, -1032,   329,   229,
   -1032, -1032, -1032, -1032,    18, -1032, -1032,    14, -1032, -1032,
      15, -1032, -1032,    32, -1032, -1032,    29, -1032, -1032,    10,
   -1032, -1032,     0, -1032, -1032, -1032,   331, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032,   333, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,   313, -1032,   233,   -43, -1032, -1032,
   -1032,   179, -1032,   281, -1032, -1032,   -32, -1032, -1032, -1032,
   -1032, -1032,   200, -1032,   147, -1032,   246, -1032,   212, -1032,
     273, -1032,   274, -1032,   286, -1032,   418,    -6,   -39, -1032,
   -1032, -1032, -1032,     3, -1032, -1032,   424,    98,   430,   149,
     461,   171,   465, -1032,   462, -1032, -1032,   337, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032,   339, -1032,   341,
   -1032,   343, -1032,   345, -1032,   347, -1032,   455,   -31, -1032,
     349,   142,   467, -1032, -1032, -1032, -1032,    -8, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032,    99, -1032, -1032,   336,
   -1032,   253,   473, -1032,   474, -1032, -1032, -1032,   355,   475,
   -1032,   476, -1032, -1032, -1032,   357,   477, -1032,   478, -1032,
   -1032, -1032, -1032,   479,   480,   109, -1032, -1032, -1032, -1032,
      28, -1032, -1032,    24, -1032, -1032,    -3, -1032, -1032,     1,
   -1032, -1032,     9, -1032, -1032, -1032,   356, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032,   360, -1032,   362, -1032,   364, -1032,   366, -1032,   368,
   -1032,   457, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   348,
   -1032,   464,     4, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   372,
     119, -1032, -1032, -1032,   374,   237, -1032, -1032, -1032,   415,
   -1032, -1032, -1032, -1032,   416, -1032, -1032, -1032, -1032,   421,
   -1032, -1032, -1032, -1032,   425, -1032, -1032, -1032,   145, -1032,
   -1032,   409, -1032,   410, -1032,   342, -1032,   352, -1032, -1032,
   -1032, -1032,   371,   489,   182, -1032, -1032, -1032, -1032,     7,
   -1032, -1032,    13, -1032, -1032,    16, -1032, -1032,    25, -1032,
   -1032,    22, -1032, -1032,   488,   376,   487,   266,   490,   268,
     491,   275,   495, -1032,   492, -1032, -1032,   378, -1032, -1032,
      33, -1032, -1032,   497,   501,   502,   503, -1032, -1032, -1032,
   -1032,   375, -1032, -1032,   508, -1032,   509, -1032, -1032, -1032,
     407, -1032, -1032,   510, -1032,   512,   513, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032,   383,   249, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032,   205, -1032, -1032,   386, -1032,
     385, -1032,   405, -1032,   460, -1032,   434, -1032,   518, -1032,
   -1032, -1032,   389,   516, -1032,   522, -1032, -1032, -1032,   391,
     523, -1032,   524, -1032, -1032, -1032,   393,   525, -1032,   526,
   -1032, -1032, -1032, -1032,   527,   528,   206, -1032, -1032, -1032,
   -1032,   507, -1032,   481,   521,    20, -1032, -1032, -1032, -1032,
   -1032,   529,   531, -1032, -1032, -1032, -1032,   429, -1032, -1032,
     537, -1032,   538,   539, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032,   392,   252, -1032, -1032, -1032, -1032, -1032,   535,
     -51, -1032, -1032,   379, -1032, -1032, -1032, -1032,   390, -1032,
   -1032, -1032, -1032,   395, -1032, -1032, -1032, -1032,   399, -1032,
   -1032, -1032,   210, -1032, -1032, -1032,   394, -1032,   414, -1032,
   -1032,   544, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,   442, -1032, -1032,   547, -1032,   548,
     549, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032,   396,   262,   550, -1032, -1032, -1032, -1032,
     466,   243,   551, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032,   203,   446, -1032, -1032,   552, -1032,   555,   560, -1032,
   -1032, -1032, -1032, -1032, -1032,   -52,   398,   403,   546,   561,
   -1032,   563, -1032,   400,   243, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,     6, -1032,   564, -1032,   565, -1032,
     566, -1032,   567, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
      19, -1032,   553,   482,   569, -1032, -1032,   186, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032,   438,   568,   570,
     571,   572, -1032, -1032, -1032,   402,   484, -1032, -1032,   404,
     573,   505,   576, -1032, -1032, -1032, -1032,   187, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032,   163, -1032,   579,
     431, -1032, -1032, -1032, -1032,   406,   556,   483, -1032, -1032,
   -1032,   408,   196,   -17,   578,   585, -1032,   586, -1032,   587,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   435,   574,
     590,   436, -1032, -1032, -1032, -1032, -1032,   412,   577,   485,
     463, -1032, -1032,   596, -1032,   598, -1032, -1032, -1032,   597,
   -1032, -1032, -1032, -1032, -1032, -1032,   599,   595,   600,   601,
   -1032, -1032,   532,   580, -1032,   417, -1032,   592, -1032,   605,
     530, -1032, -1032, -1032, -1032,   604,   422, -1032, -1032, -1032,
     607,   608, -1032,   609, -1032, -1032, -1032, -1032, -1032,   593,
   -1032,   426,   612,   165, -1032, -1032, -1032, -1032, -1032, -1032,
     428,    69, -1032,   610, -1032,   615, -1032, -1032, -1032, -1032,
     554, -1032,   -68, -1032,   432,   617,   285, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,   166, -1032,   602,   618, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032,   437,   -34, -1032,   214,
   -1032, -1032, -1032, -1032, -1032,   619,   -38, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,   290, -1032,   603, -1032, -1032, -1032,
   -1032,   616, -1032,   -64,   139,   621, -1032, -1032, -1032, -1032,
   -1032, -1032,   620, -1032, -1032, -1032,   441,   223, -1032, -1032,
   -1032,   -33, -1032,   606, -1032, -1032, -1032, -1032,   623,   624,
     447, -1032,   611, -1032, -1032, -1032, -1032, -1032,   626, -1032,
     631, -1032,   633, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032,    -7,   190, -1032,   445, -1032, -1032, -1032, -1032,   634,
   -1032,   635, -1032,   636, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,   637,   638,   639, -1032, -1032, -1032,
     493, -1032,   640,    58,   642, -1032, -1032, -1032, -1032,   622,
   -1032, -1032, -1032, -1032, -1032,   643, -1032,   646, -1032,   650,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   213,
     -53,   649, -1032, -1032, -1032,   651,   641, -1032,   498, -1032,
   -1032,   652,   454, -1032, -1032, -1032,   627, -1032, -1032, -1032,
   -1032, -1032,   653,   -23,   654, -1032, -1032, -1032,   -11,   656,
     658, -1032,   659, -1032,   662, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,   644, -1032, -1032, -1032, -1032, -1032,
     506, -1032, -1032, -1032, -1032, -1032,   542, -1032,   452, -1032,
     660,   458, -1032, -1032, -1032,   645, -1032, -1032, -1032, -1032,
     663, -1032, -1032, -1032, -1032, -1032, -1032,   664,   661,   667,
   -1032, -1032,   456, -1032, -1032, -1032, -1032, -1032,   665,    21,
   -1032, -1032, -1032, -1032, -1032,   613, -1032,   459, -1032, -1032,
     668, -1032, -1032, -1032,   666,     2, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032,   582, -1032, -1032,   671,    52, -1032, -1032,
     625, -1032, -1032, -1032,   517, -1032, -1032, -1032, -1032,   614,
   -1032, -1032, -1032, -1032, -1032
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
     628, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   496, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,   486, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032,   350, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   234,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   133, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
     296, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032,    45, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
     -24, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
    -160, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032,  -189, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032,  -215, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,  -114, -1031,
   -1032, -1032
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     183,   184,   198,   345,   134,   347,  1109,   209,  1110,  1111,
     158,   448,   694,   695,   132,   349,   350,   450,   124,   126,
     452,    19,   122,   706,   257,  1109,   456,  1110,  1111,   454,
     343,   258,   341,   130,   922,   909,   128,   159,   871,   160,
     961,   779,   234,   780,   781,   898,     4,  1070,   560,  1071,
    1072,    10,    11,  1062,  1041,   259,  1109,   185,  1110,  1111,
      20,   388,   561,   677,    21,   161,    22,   204,    23,   979,
     205,     1,   899,     6,  1124,     9,   678,   260,   980,   162,
      24,   307,     5,   311,  1063,   261,  1129,   587,   455,    12,
      25,    87,    26,   923,   588,   872,     7,   163,    27,   262,
    1073,   263,   186,   164,    88,   344,    89,  1042,    90,   457,
      91,   342,   782,   264,    28,   123,   707,   265,   332,   266,
    1112,   267,   910,   268,   131,   129,   186,   910,   389,  1128,
     212,   213,   351,   453,   127,   125,   214,   133,   449,    17,
     210,   353,   348,   135,   346,   696,   451,   491,    92,   925,
     926,   404,   405,   406,   927,   297,  1013,   389,   298,   199,
     200,   201,   202,  1123,   299,  1014,    15,    16,    51,   300,
     860,   928,   929,   930,   931,   861,    93,   744,    85,   932,
     933,   219,   220,   393,   394,   395,   396,   221,   397,   398,
     399,   400,   110,   745,   746,   747,   748,   749,   750,   113,
     982,   983,   984,   226,   227,   204,   423,   424,   312,   228,
     114,   426,   427,   654,   655,   336,   429,   430,   337,    49,
      50,   432,   985,   986,   987,   988,   179,  1029,   773,   774,
     989,   990,   775,   656,   657,   658,   659,    64,    65,   660,
     661,   662,   663,  1030,  1031,  1032,  1033,  1034,  1035,   948,
     115,   336,   156,    53,   433,   949,   950,   951,   952,   317,
     318,    54,    55,   953,   954,    56,    57,   638,   191,   413,
     414,   415,   485,    67,    68,   639,   640,   416,   417,   641,
     642,   510,   511,   512,   577,   578,   579,   182,   443,   513,
     514,   444,   580,   581,   625,   626,   627,   190,   463,   464,
     470,   471,   628,   629,   465,   193,   472,   477,   478,    70,
      71,   443,   550,   479,   520,   551,   550,   715,   739,   601,
     716,   716,   852,   888,   903,   853,   853,   904,   519,    73,
      74,    76,    77,    79,    80,    82,    83,   108,   109,   116,
     117,   138,   139,   143,   144,   152,   153,   235,   236,   240,
     241,   243,   244,   246,   247,   249,   250,   252,   253,   292,
     293,   322,   323,   327,   328,   192,   354,   355,   194,   546,
     359,   360,   362,   363,   365,   366,   368,   369,   371,   372,
     382,   383,   401,   402,   410,   411,   459,   460,   486,   487,
     567,   568,   569,   507,   508,   531,   532,   536,   537,   541,
     542,   195,   574,   575,   606,   607,   622,   623,   680,   681,
     687,   688,   725,   726,   730,   731,   761,   762,   770,   771,
     591,   592,   800,   801,   197,   594,   595,   823,   824,   196,
     597,   598,   836,   837,   211,   600,   846,   847,   858,   859,
     218,   605,   876,   877,   882,   883,   612,   896,   897,   915,
     883,   945,   946,   968,   969,   997,   998,   614,   615,   616,
    1054,  1055,  1089,  1090,  1093,  1094,  1105,  1106,   232,  1117,
    1118,   225,   233,   316,   255,   306,   320,   321,   325,   326,
     330,   331,   374,   386,   422,   333,   335,   425,   428,   439,
     431,   438,   437,   440,   441,   442,   458,   462,   483,   650,
     469,   476,   484,   496,   651,   652,   653,   497,   498,   499,
     500,   501,   502,   504,   503,   505,   506,   524,   525,   534,
     676,   528,   526,   527,   529,   535,   539,   540,   544,   545,
     555,   558,   590,   547,   549,   693,   570,   565,   557,   566,
     571,   572,   573,   586,   609,   593,   596,   613,   599,   617,
     618,   619,   620,   672,   684,   673,   634,   649,   674,   702,
     703,   704,   636,   675,   685,   682,   686,   698,   699,   700,
     701,   713,   714,   766,   708,   712,   721,   720,   722,   723,
     724,   728,   710,   736,   738,   756,   786,   757,   787,   788,
     789,   734,   797,   791,   729,   768,   796,   805,   809,   810,
     794,   811,   812,   814,   817,   813,   820,   829,   815,   816,
     807,   832,   835,   870,   833,   838,   839,   841,   851,   843,
     760,   868,   865,   881,   892,   908,   920,   940,   943,   975,
     967,   890,   917,   966,   976,   963,   977,  1002,  1003,  1004,
     971,  1087,   790,  1008,  1007,  1050,  1025,  1006,  1017,  1026,
    1012,  1021,   799,  1027,  1010,  1045,  1057,  1049,  1053,  1052,
    1066,  1078,  1079,  1061,  1077,  1080,  1092,  1085,  1099,  1101,
    1100,  1108,  1122,  1081,  1096,  1102,  1121,  1127,  1132,   521,
     822,  1126,   828,   308,  1130,   602,   492,   121,   434,   692,
    1115,  1134,   313,   740,   889,   916,   962,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   845,     0,     0,     0,
       0,     0,     0,     0,     0,   857,     0,     0,   864,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   875,
       0,     0,     0,     0,     0,     0,     0,   887,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   895,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   914,     0,     0,
       0,     0,     0,     0,     0,     0,   919,     0,   921,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   960,     0,     0,     0,     0,     0,
       0,     0,     0,   965,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   974,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   978,     0,     0,     0,
       0,     0,     0,     0,  1001,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1005,
       0,     0,     0,  1009,     0,     0,     0,  1011,     0,     0,
       0,  1018,  1019,  1020,     0,     0,     0,     0,     0,     0,
    1024,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1046,  1047,
    1048,     0,     0,  1051,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1059,     0,     0,     0,  1060,     0,     0,
       0,  1067,  1068,  1069,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1083,     0,     0,     0,  1084,     0,     0,     0,  1086,
       0,     0,     0,  1088,     0,     0,     0,     0,     0,     0,
       0,     0,  1098,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1103,  1104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1114,     0,
       0,     0,  1116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1131,     0,
       0,     0,     0,  1133
};

static const yytype_int16 yycheck[] =
{
     114,   115,     8,     6,     4,     4,     4,     4,     6,     7,
      53,     4,     6,     7,     4,     6,     7,     4,     4,     4,
       4,    49,     4,     4,    55,     4,     4,     6,     7,     4,
       6,    62,     4,     4,    98,    73,     4,    80,   106,    82,
      73,    58,   156,    60,    61,    79,    10,    58,    28,    60,
      61,    10,    11,    76,   107,    86,     4,    89,     6,     7,
      88,    57,    42,   115,    92,   108,    94,   106,    96,    76,
     109,    44,   106,     0,  1105,    10,   128,   108,    85,   122,
     108,    89,    46,   197,   107,   116,  1117,   138,    63,    50,
     118,    51,   120,   157,   145,   163,    48,   140,   126,   130,
     111,   132,   134,   146,    64,    81,    66,   160,    68,    87,
      70,    83,   129,   144,   142,    97,    97,   148,   232,   150,
      99,   152,   160,   154,    95,    93,   134,   160,   124,    77,
      32,    33,   123,   117,   119,   121,    38,   127,   131,    52,
     137,   255,   141,   143,   147,   139,   133,   114,   108,    10,
      11,    32,    33,    34,    15,    13,    98,   124,    16,   165,
     166,   167,   168,   161,    22,   107,    10,    11,    54,    27,
     101,    32,    33,    34,    35,   106,   136,    14,    19,    40,
      41,    32,    33,   297,   298,   299,   300,    38,   302,   303,
     304,   305,    56,    30,    31,    32,    33,    34,    35,     8,
      10,    11,    12,    32,    33,   106,   320,   321,   109,    38,
       3,   325,   326,    10,    11,   106,   330,   331,   109,    10,
      11,   335,    32,    33,    34,    35,    47,    14,    32,    33,
      40,    41,    36,    30,    31,    32,    33,    10,    11,    36,
      37,    38,    39,    30,    31,    32,    33,    34,    35,    26,
       3,   106,    19,    24,   109,    32,    33,    34,    35,     6,
       7,    32,    33,    40,    41,    36,    37,    24,   121,    32,
      33,    34,   386,    10,    11,    32,    33,    40,    41,    36,
      37,    32,    33,    34,    32,    33,    34,     6,   106,    40,
      41,   109,    40,    41,    32,    33,    34,    97,    32,    33,
      32,    33,    40,    41,    38,    93,    38,    32,    33,    10,
      11,   106,   106,    38,   109,   109,   106,   131,   131,   109,
     134,   134,   157,   157,   110,   160,   160,   113,   442,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    32,    33,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,     6,     7,     6,     7,   119,    10,    11,    95,   483,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      32,    33,    10,    11,    10,    11,    10,    11,    10,    11,
     504,   505,   506,    10,    11,     6,     7,     6,     7,     6,
       7,   127,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     534,   535,    10,    11,     6,   539,   540,    10,    11,   143,
     544,   545,    10,    11,    10,   549,    10,    11,    10,    11,
      10,   555,    10,    11,   159,   160,   560,    10,    11,   159,
     160,    10,    11,     6,     7,    10,    11,   571,   572,   573,
       6,     7,    10,    11,     6,     7,    10,    11,     3,    10,
      11,    10,    10,   137,    19,     8,     3,     3,     3,     3,
       3,     3,    25,    19,    69,     6,     6,    71,    67,   147,
      65,    81,    83,   141,   123,     6,     8,    10,     3,   613,
      10,    10,    10,     6,   618,   619,   620,     6,     6,     6,
     135,     3,     3,     3,   107,     3,     3,   131,   133,     3,
     634,    87,   117,    63,     6,     3,     3,     3,     3,     3,
      23,    10,   153,     6,     6,   649,   107,     8,    57,     8,
       3,     3,     3,     8,   130,   155,   151,     3,   149,   107,
       3,     3,     3,   107,     8,     3,     6,     6,     3,   673,
     674,   675,    96,     3,     3,   162,     3,     3,     3,     3,
       3,   685,   686,    17,    21,     6,     8,   139,     8,     8,
       8,    97,   100,    78,     8,     6,     8,   156,     3,     3,
       3,    18,   156,   158,   708,   112,     6,    20,   135,     3,
      26,     3,     5,     8,    72,     6,    26,    15,     8,     8,
     125,     6,     8,    59,    84,     8,     8,     8,     6,    26,
     734,     6,    12,     6,     6,     6,    10,     6,     8,     3,
       6,    29,    29,    10,     3,    29,     3,     3,     3,     3,
      29,    99,   756,     4,     6,     4,     3,    10,     6,     3,
      10,    29,   766,     3,   161,     6,    29,     6,     6,   161,
       6,     3,     3,    10,     8,     3,     6,   161,     5,     8,
       6,     6,     6,    29,    29,     8,     8,     6,   161,   445,
     794,    99,   796,   187,    59,   552,   390,    59,   338,   644,
      77,    77,   206,   717,   854,   884,   911,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   820,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   829,    -1,    -1,   832,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   843,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   851,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   865,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   881,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   890,    -1,   892,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   908,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   917,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   927,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   940,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   948,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   963,
      -1,    -1,    -1,   967,    -1,    -1,    -1,   971,    -1,    -1,
      -1,   975,   976,   977,    -1,    -1,    -1,    -1,    -1,    -1,
     984,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1002,  1003,
    1004,    -1,    -1,  1007,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1017,    -1,    -1,    -1,  1021,    -1,    -1,
      -1,  1025,  1026,  1027,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1045,    -1,    -1,    -1,  1049,    -1,    -1,    -1,  1053,
      -1,    -1,    -1,  1057,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1066,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1080,  1081,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1092,    -1,
      -1,    -1,  1096,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1122,    -1,
      -1,    -1,    -1,  1127
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   232,   173,    10,    11,    52,   283,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   176,   195,   196,   198,   199,   201,   202,   204,   205,
     207,   208,   210,   211,   213,   214,   216,   217,   233,    10,
      11,    54,   317,    24,    32,    33,    36,    37,   177,   178,
     179,   180,   181,   182,    10,    11,   197,    10,    11,   200,
      10,    11,   203,    10,    11,   206,    10,    11,   209,    10,
      11,   212,    10,    11,   215,    19,   218,    51,    64,    66,
      68,    70,   108,   136,   234,   235,   236,   238,   239,   246,
     247,   254,   255,   262,   263,   267,   268,   284,    10,    11,
      56,   396,   397,     8,     3,     3,    10,    11,   183,   184,
     185,   179,     4,    97,     4,   121,     4,   119,     4,    93,
       4,    95,     4,   127,     4,   143,   577,   580,    10,    11,
     219,   220,   221,    10,    11,   237,   240,   241,   248,   249,
     256,   257,    32,    33,   264,   265,    19,   269,    53,    80,
      82,   108,   122,   140,   146,   285,   286,   287,   289,   290,
     292,   293,   295,   296,   298,   299,   301,   302,   318,    47,
     398,   399,     6,   577,   577,    89,   134,   186,   187,   188,
      97,   121,   119,    93,    95,   127,   143,     6,     8,   165,
     166,   167,   168,   579,   106,   109,   222,   223,   224,     4,
     137,    10,    32,    33,    38,   242,   243,   244,    10,    32,
      33,    38,   250,   251,   252,    10,    32,    33,    38,   258,
     259,   260,     3,    10,   577,    10,    11,   270,   271,   272,
      10,    11,   288,    10,    11,   291,    10,    11,   294,    10,
      11,   297,    10,    11,   300,    19,   303,    55,    62,    86,
     108,   116,   130,   132,   144,   148,   150,   152,   154,   319,
     320,   321,   323,   324,   326,   327,   329,   330,   332,   333,
     335,   336,   351,   352,   359,   360,   367,   368,   375,   376,
     380,   381,    10,    11,   405,   406,   407,    13,    16,    22,
      27,   400,   401,   402,   403,   404,     8,    89,   187,   189,
     190,   577,   109,   223,   225,   226,   137,     6,     7,   245,
       3,     3,     6,     7,   253,     3,     3,     6,     7,   261,
       3,     3,   577,     6,   266,     6,   106,   109,   273,   274,
     275,     4,    83,     6,    81,     6,   147,     4,   141,     6,
       7,   123,   576,   577,    10,    11,   304,   305,   306,    10,
      11,   322,    10,    11,   325,    10,    11,   328,    10,    11,
     331,    10,    11,   334,    25,   337,   353,   354,   361,   362,
     369,   370,    32,    33,   377,   378,    19,   382,    57,   124,
     408,   409,   410,   577,   577,   577,   577,   577,   577,   577,
     577,    10,    11,   194,    32,    33,    34,   191,   192,   193,
      10,    11,   231,    32,    33,    34,    40,    41,   227,   228,
     229,   230,    69,   577,   577,    71,   577,   577,    67,   577,
     577,    65,   577,   109,   274,   276,   277,    83,    81,   147,
     141,   123,     6,   106,   109,   307,   308,   309,     4,   131,
       4,   133,     4,   117,     4,    63,     4,    87,     8,    10,
      11,   338,    10,    32,    33,    38,   355,   356,   357,    10,
      32,    33,    38,   363,   364,   365,    10,    32,    33,    38,
     371,   372,   373,     3,    10,   577,    10,    11,   383,   384,
     385,   114,   409,   559,   411,   412,     6,     6,     6,     6,
     135,     3,     3,   107,     3,     3,     3,    10,    11,   282,
      32,    33,    34,    40,    41,   278,   279,   280,   281,   577,
     109,   308,   310,   311,   131,   133,   117,    63,    87,     6,
     339,     6,     7,   358,     3,     3,     6,     7,   366,     3,
       3,     6,     7,   374,     3,     3,   577,     6,   379,     6,
     106,   109,   386,   387,   388,    23,   560,    57,    10,   416,
      28,    42,   413,   414,   415,     8,     8,   577,   577,   577,
     107,     3,     3,     3,    10,    11,   316,    32,    33,    34,
      40,    41,   312,   313,   314,   315,     8,   138,   145,   340,
     153,   577,   577,   155,   577,   577,   151,   577,   577,   149,
     577,   109,   387,   389,   390,   577,    10,    11,   561,   130,
     417,   418,   577,     3,   577,   577,   577,   107,     3,     3,
       3,   341,    10,    11,   395,    32,    33,    34,    40,    41,
     391,   392,   393,   394,     6,   562,    96,   437,    24,    32,
      33,    36,    37,   419,   420,   421,   422,   423,   424,     6,
     577,   577,   577,   577,    10,    11,    30,    31,    32,    33,
      36,    37,    38,    39,   342,   343,   344,   345,   346,   347,
     348,   349,   107,     3,     3,     3,   577,   115,   128,   563,
      10,    11,   162,   438,     8,     3,     3,    10,    11,   425,
     426,   427,   421,   577,     6,     7,   139,   350,     3,     3,
       3,     3,   577,   577,   577,   564,     4,    97,    21,   439,
     100,   489,     6,   577,   577,   131,   134,   428,   429,   430,
     139,     8,     8,     8,     8,    10,    11,   565,    97,   577,
      10,    11,   440,   441,    18,   490,    78,   515,     8,   131,
     429,   431,   432,   571,    14,    30,    31,    32,    33,    34,
      35,   566,   567,   568,   569,   570,     6,   156,   442,   443,
     577,    10,    11,   491,   492,   493,    17,   516,   112,   541,
      10,    11,   436,    32,    33,    36,   433,   434,   435,    58,
      60,    61,   129,   572,   573,   574,     8,     3,     3,     3,
     577,   158,   453,   454,    26,   444,     6,   156,   494,   577,
      10,    11,   517,   518,   519,    20,   542,   125,   558,   135,
       3,     3,     5,     6,     8,     8,     8,    72,   463,   464,
      26,   455,   577,    10,    11,   445,   446,   447,   577,    15,
     495,   500,     6,    84,   520,     8,    10,    11,     8,     8,
     575,     8,   473,    26,   465,   577,    10,    11,   456,   457,
     458,     6,   157,   160,   448,   449,   450,   577,    10,    11,
     101,   106,   501,   502,   577,    12,   521,   526,     6,   544,
      59,   106,   163,   474,   475,   577,    10,    11,   466,   467,
     468,     6,   159,   160,   459,   460,   461,   577,   157,   449,
      29,   451,     6,   496,   503,   577,    10,    11,    79,   106,
     527,   528,   543,   110,   113,   545,   476,   477,     6,    73,
     160,   469,   470,   471,   577,   159,   460,    29,   462,   577,
      10,   577,    98,   157,   497,    10,    11,    15,    32,    33,
      34,    35,    40,    41,   504,   505,   506,   507,   508,   509,
       6,   522,   529,     8,   546,    10,    11,   483,    26,    32,
      33,    34,    35,    40,    41,   478,   479,   480,   481,   482,
     577,    73,   470,    29,   472,   577,    10,     6,     6,     7,
     452,    29,   498,   510,   577,     3,     3,     3,   577,    76,
      85,   523,    10,    11,    12,    32,    33,    34,    35,    40,
      41,   530,   531,   532,   533,   534,   535,    10,    11,   547,
     484,   577,     3,     3,     3,   577,    10,     6,     4,   577,
     161,   577,    10,    98,   107,   511,   512,     6,   577,   577,
     577,    29,   524,   536,   577,     3,     3,     3,   553,    14,
      30,    31,    32,    33,    34,    35,   548,   549,   550,   551,
     552,   107,   160,   485,   486,     6,   577,   577,   577,     6,
       4,   577,   161,     6,     6,     7,   499,    29,   513,   577,
     577,    10,    76,   107,   537,   538,     6,   577,   577,   577,
      58,    60,    61,   111,   554,   555,   556,     8,     3,     3,
       3,    29,   487,   577,   577,   161,   577,    99,   577,    10,
      11,   514,     6,     6,     7,   525,    29,   539,   577,     5,
       6,     8,     8,   577,   577,    10,    11,   488,     6,     4,
       6,     7,    99,   578,   577,    77,   577,    10,    11,   540,
     557,     8,     6,   161,   578,   577,    99,     6,    77,   578,
      59,   577,   161,   577,    77
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
	;}
    break;

  case 21:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for generalStatus element");
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->kounter = 0;
	;}
    break;

  case 24:

    {   if (parserData->typeAttributePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one type attribute allowed for generalStatus element");
	    parserData->typeAttributePresent = true;
	    if ((parserData->tempStr != "error"  ) &&
	        (parserData->tempStr != "warning") && 
	        (parserData->tempStr != "normal"))
			osrlerror(NULL, NULL, parserData, "general status type does not matched any legal value");
		osresult->setGeneralStatusType(parserData->tempStr); 
	;}
    break;

  case 25:

    {   if (parserData->descriptionAttributePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for generalStatus element");
	    parserData->descriptionAttributePresent = true;
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

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for generalStatus element");
    parserData->numberAttributePresent = true;
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

    {	parserData->kounter++;
;}
    break;

  case 40:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
;}
    break;

  case 41:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 45:

    {	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
	parserData->descriptionAttributePresent = true;
	osresult->setGeneralSubstatusDescription(parserData->kounter,parserData->tempStr);
;}
    break;

  case 46:

    {	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
	parserData->nameAttributePresent = true;
	osresult->setGeneralSubstatusName(parserData->kounter,(yyvsp[(2) - (3)].sval));
;}
    break;

  case 47:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 48:

    { parserData->tempStr = "";          ;}
    break;

  case 52:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 53:

    {osresult->setGeneralMessage((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 57:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 58:

    {osresult->setServiceURI((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 62:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 63:

    {osresult->setServiceName((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 67:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 68:

    {osresult->setInstanceName((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 72:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 73:

    {osresult->setJobID((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 77:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 78:

    {osresult->setSolverInvoked((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 82:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 83:

    {osresult->setTimeStamp((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 87:

    {	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	;}
    break;

  case 88:

    {	osresult->setNumberOfOtherGeneralResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 89:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 90:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 96:

    {	parserData->kounter++;
;}
    break;

  case 97:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 98:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 101:

    {	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setGeneralOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 102:

    {	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setGeneralOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 103:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setGeneralOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 104:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 105:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 106:

    { parserData->tempStr = "";          ;}
    break;

  case 107:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 108:

    { parserData->tempStr = "";          ;}
    break;

  case 123:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 124:

    {osresult->setSystemInformation((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 128:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
	;}
    break;

  case 129:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 132:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableDiskSpace>");
		parserData->unitAttributePresent = true;		
		osresult->setAvailableDiskSpaceUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 133:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableDiskSpace>");
		parserData->descriptionAttributePresent = true;		
		osresult->setAvailableDiskSpaceDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 134:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
		if (parserData->tempStr != "exabyte"  && parserData->tempStr != "petabyte" && 
			parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" &&
			parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && 
			parserData->tempStr != "byte")
			osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
	;}
    break;

  case 135:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 136:

    { parserData->tempStr = "";          ;}
    break;

  case 137:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 138:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 140:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
	;}
    break;

  case 141:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 144:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableMemory>");
		parserData->unitAttributePresent = true;		
		osresult->setAvailableMemoryUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 145:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableMemory>");
		parserData->descriptionAttributePresent = true;		
		osresult->setAvailableMemoryDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 146:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
		if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
			parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
			osrlerror(NULL, NULL, parserData, "availableMemory unit not recognized");
;}
    break;

  case 147:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 148:

    { parserData->tempStr = "";          ;}
    break;

  case 149:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 150:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 152:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
	;}
    break;

  case 153:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 156:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableCPUSpeed>");
		parserData->unitAttributePresent = true;		
		osresult->setAvailableCPUSpeedUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 157:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <availableMemory>");
		parserData->descriptionAttributePresent = true;		
		osresult->setAvailableCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 158:

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

  case 159:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 160:

    { parserData->tempStr = "";          ;}
    break;

  case 161:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 162:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 164:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
	;}
    break;

  case 166:

    {	osresult->setAvailableCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 167:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 168:

    { parserData->tempStr = "";          ;}
    break;

  case 169:

    {osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 171:

    {	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	;}
    break;

  case 172:

    {	osresult->setNumberOfOtherSystemResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 173:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 174:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 180:

    {	parserData->kounter++;
;}
    break;

  case 181:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 182:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 185:

    {	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setSystemOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 186:

    {	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setSystemOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 187:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setSystemOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 188:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 189:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 190:

    { parserData->tempStr = "";          ;}
    break;

  case 191:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 192:

    { parserData->tempStr = "";          ;}
    break;

  case 207:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 208:

    {osresult->setCurrentState((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 212:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 213:

    {osresult->setCurrentJobCount((yyvsp[(2) - (3)].ival)); /* free($2); */  parserData->errorText = NULL;;}
    break;

  case 217:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 218:

    {osresult->setTotalJobsSoFar((yyvsp[(2) - (3)].ival)); /* free($2); */  parserData->errorText = NULL;;}
    break;

  case 222:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 223:

    {osresult->setTimeServiceStarted((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 227:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 228:

    {osresult->setServiceUtilization( parserData->tempVal);  parserData->errorText = NULL;;}
    break;

  case 232:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	;}
    break;

  case 233:

    {	osresult->setNumberOfOtherServiceResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 234:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 235:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 241:

    {	parserData->kounter++;
;}
    break;

  case 242:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 243:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 246:

    {	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setServiceOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 247:

    {	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setServiceOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 248:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setServiceOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 249:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 250:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 251:

    { parserData->tempStr = "";          ;}
    break;

  case 252:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 253:

    { parserData->tempStr = "";          ;}
    break;

  case 273:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 274:

    {osresult->setJobStatus((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 278:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 279:

    {osresult->setJobSubmitTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 283:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 284:

    {osresult->setScheduledStartTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 288:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 289:

    {osresult->setActualStartTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 293:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 294:

    {osresult->setJobEndTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 298:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 299:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
;}
    break;

  case 307:

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

  case 311:

    {parserData->timeType = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 313:

    {parserData->timeCategory = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 315:

    {parserData->timeUnit = (yyvsp[(2) - (3)].sval);   free((yyvsp[(2) - (3)].sval));;}
    break;

  case 317:

    {parserData->timeDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 323:

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

  case 325:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 326:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 328:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
	;}
    break;

  case 329:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 332:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedDiskSpace>");
		parserData->unitAttributePresent = true;		
		osresult->setUsedDiskSpaceUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 333:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedDiskSpace>");
		parserData->descriptionAttributePresent = true;		
		osresult->setUsedDiskSpaceDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 334:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "petabyte" && parserData->tempStr != "terabyte" &&
	    parserData->tempStr != "gigabyte" && parserData->tempStr != "megabyte" && 
	    parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedDiskSpace unit not recognized");
;}
    break;

  case 335:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 336:

    { parserData->tempStr = "";          ;}
    break;

  case 337:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 338:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 340:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
	;}
    break;

  case 341:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 344:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedMemory>");
		parserData->unitAttributePresent = true;		
		osresult->setUsedMemoryUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 345:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedMemory>");
		parserData->descriptionAttributePresent = true;		
		osresult->setUsedMemoryDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 346:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedMemory unit not recognized");
;}
    break;

  case 347:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 348:

    { parserData->tempStr = "";          ;}
    break;

  case 349:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 350:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 352:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
	;}
    break;

  case 353:

    {	parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 356:

    {	if (parserData->unitAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedCPUSpeed>");
		parserData->unitAttributePresent = true;		
		osresult->setUsedCPUSpeedUnit( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 357:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "only one unit attribute allowed in <usedCPUSpeed>");
		parserData->descriptionAttributePresent = true;		
		osresult->setUsedCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 358:

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

  case 359:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 360:

    { parserData->tempStr = "";          ;}
    break;

  case 361:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 362:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 364:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
	;}
    break;

  case 366:

    {	osresult->setUsedCPUSpeedDescription( parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 367:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 368:

    { parserData->tempStr = "";          ;}
    break;

  case 369:

    {osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 371:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	;}
    break;

  case 372:

    {	osresult->setNumberOfOtherJobResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 373:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 374:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 380:

    {	parserData->kounter++;
;}
    break;

  case 381:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 382:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 385:

    {	if (parserData->nameAttributePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->nameAttributePresent = true;
		osresult->setJobOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 386:

    {	if (parserData->valueAttributePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->valueAttributePresent = true;
		osresult->setJobOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 387:

    {	if (parserData->descriptionAttributePresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->descriptionAttributePresent = true;
		osresult->setJobOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 388:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 389:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 390:

    { parserData->tempStr = "";           ;}
    break;

  case 391:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 392:

    { parserData->tempStr = "";           ;}
    break;

  case 398:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, "numberOfSolutions was never set");
	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
	parserData->solutionIdx = 0;
;}
    break;

  case 405:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfSolutions = (yyvsp[(3) - (3)].ival); 
	osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 406:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	parserData->nVarPresent = true;	
	parserData->numberOfVariables = (yyvsp[(3) - (3)].ival); 
	osresult->setVariableNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 407:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	parserData->nConPresent = true;		
	parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); 
	osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 408:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	parserData->nObjPresent = true;
	parserData->numberOfObjectives = (yyvsp[(3) - (3)].ival); 
	osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));
;}
    break;

  case 416:

    {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   ;}
    break;

  case 417:

    {   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
;}
    break;

  case 418:

    {	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 423:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 424:

    {	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval);
  	osresult->setSolutionWeightedObjectives(parserData->solutionIdx, parserData->tempStr);
;}
    break;

  case 427:

    { parserData->numberOf = 0; ;}
    break;

  case 428:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->kounter = 0;
	;}
    break;

  case 431:

    {   if (parserData->typeAttributePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one type attribute allowed for solution status element");
	    parserData->typeAttributePresent = true;
	    if ((parserData->tempStr != "unbounded"     ) && (parserData->tempStr != "globallyOptimal") && 
	        (parserData->tempStr != "locallyOptimal") && (parserData->tempStr != "optimal") && 
	        (parserData->tempStr != "bestSoFar"     ) && (parserData->tempStr != "feasible") && 
	        (parserData->tempStr != "infeasible"    ) && (parserData->tempStr != "unsure") && 
	        (parserData->tempStr != "error"         ) && (parserData->tempStr != "other"))
			osrlerror(NULL, NULL, parserData, "solution status type does not matched any legal value");
		osresult->setSolutionStatusType(parserData->solutionIdx, parserData->tempStr); 
	;}
    break;

  case 432:

    {   if (parserData->descriptionAttributePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for solution status element");
	    parserData->descriptionAttributePresent = true;
		osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->tempStr);
	;}
    break;

  case 434:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 435:

    { parserData->tempStr = "";          ;}
    break;

  case 436:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 437:

    { parserData->tempStr = "";          ;}
    break;

  case 438:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for solution status element");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solution substatuses cannot be negative");
    osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 439:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 440:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 446:

    {	parserData->kounter++; ;}
    break;

  case 447:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
;}
    break;

  case 448:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 452:

    {	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
	parserData->descriptionAttributePresent = true;
	osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,parserData->tempStr);
;}
    break;

  case 453:

    {	if (parserData->typeAttributePresent)
		osrlerror(NULL, NULL, parserData, "type attribute multiply specified");
	parserData->typeAttributePresent = true;
	osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter,(yyvsp[(2) - (3)].sval));	
;}
    break;

  case 454:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 455:

    { parserData->tempStr = ""; ;}
    break;

  case 459:

    {	osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
	;}
    break;

  case 465:

    {	parserData->numberOfOtherVariableResults = (yyvsp[(3) - (4)].ival);
		osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 471:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 472:

    {	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
	osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 473:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 474:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 480:

    {	osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 481:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 482:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 483:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 484:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 487:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 488:

    {	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar);
;}
    break;

  case 489:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 490:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 496:

    {	osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 			parserData->idx,         (yyvsp[(4) - (5)].sval));
	parserData->kounter++;
;}
    break;

  case 497:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 498:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 501:

    {	parserData->nVarPresent = false; ;}
    break;

  case 502:

    {	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	osresult->setNumberOfBasisVar(parserData->solutionIdx, parserData->numberOfVar);
;}
    break;

  case 503:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 504:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 510:

    {	osresult->setBasisVar(parserData->solutionIdx, parserData->kounter, 
					 			parserData->idx,         (yyvsp[(4) - (5)].sval));
	parserData->kounter++;
;}
    break;

  case 511:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 512:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 515:

    { 	 
//		parserData->otherVarVec.push_back( parserData->otherVarStruct); 
//		parserData->numberOfOtherVariableResults++; 
//		osresult->setAnOtherVariableResultSparse(parserData->solutionIdx, parserData->iOther,  parserData->otherVarStruct->name,
//			parserData->otherVarStruct->value, parserData->otherVarStruct->description, parserData->otherVarStruct->otherVarIndex,
//			parserData->otherVarStruct->otherVarText, parserData->otherVarStruct->numberOfVar );
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
	;}
    break;

  case 516:

    {  // parserData->numberOfOtherVariableResults++;
//		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
	;}
    break;

  case 517:

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

  case 521:

    {	if (parserData->valueAttributePresent)
		osrlerror(NULL, NULL, parserData, "value attribute previously set");
	parserData->valueAttributePresent = true; 
 	osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 522:

    {	
	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, "name attribute previously set");
	parserData->nameAttributePresent = true; 
 	osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 523:

    {	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute previously set");
	parserData->descriptionAttributePresent = true; 
 	osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 524:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfVar attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 525:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 526:

    {parserData->tempStr = "";          ;}
    break;

  case 527:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 528:

    {parserData->tempStr = "";          ;}
    break;

  case 529:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 530:

    {parserData->tempStr = "";          ;}
    break;

  case 535:

    { 
	parserData->kounter++;
;}
    break;

  case 537:

    {
 	osresult->setOtherVariableResultsVarIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 538:

    {
	 	osresult->setOtherVariableResultsVar(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 544:

    {  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 550:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
;}
    break;

  case 552:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 556:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(3) - (4)].ival);   ;}
    break;

  case 557:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].ival);                  
	parserData->objVals.push_back( parserData->objValPair);
;}
    break;

  case 558:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->objVals.push_back( parserData->objValPair);
  ;}
    break;

  case 562:

    {  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	;}
    break;

  case 569:

    {
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
;}
    break;

  case 570:

    {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
;}
    break;

  case 571:

    {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 572:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->nameAttributePresent = true; 
//	parserData->otherObjStruct->name = "";
;}
    break;

  case 573:

    {
//parserData->tmpOtherName=$2; parserData->nameAttributePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 574:

    {
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 577:

    { 	 		
/*
		if(parserData->nameAttributePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
	  
        parserData->otherObjVec.push_back( parserData->otherObjStruct); 
        parserData->numberOfOtherObjectiveResults++; 
		parserData->nameAttributePresent = false;	
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

  case 580:

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

  case 581:

    {//	if(parserData->otherObjStruct->numberOfObj <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of objectives") ;
	;}
    break;

  case 582:

    {;}
    break;

  case 589:

    {  
/*        osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 595:

    {/*
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}*/
 ;}
    break;

  case 597:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 601:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 602:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 		
	;}
    break;

  case 603:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 	
	;}
    break;

  case 615:

    {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
;}
    break;

  case 616:

    {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 617:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->nameAttributePresent = true; 
//	parserData->otherConStruct->name = "";
;}
    break;

  case 618:

    {
//parserData->tmpOtherName=$2; parserData->nameAttributePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 619:

    {
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 625:

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

  case 626:

    {//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	;}
    break;

  case 627:

    {;}
    break;

  case 632:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 633:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 634:

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

  case 638:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 639:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 641:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 647:

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

  case 648:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->nameAttributePresent = true;
//	parserData->otherVarStruct->name = "";
;}
    break;

  case 649:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); //parserData->nameAttributePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 650:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 652:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 655:

    {parserData->kounter++;;}
    break;

  case 656:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 657:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 660:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 662:

    {

	//
    //delete the old vectors
//	osrl_empty_vectors( parserData);
    
;}
    break;

  case 670:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
;}
    break;

  case 673:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/;}
    break;

  case 679:

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

  case 680:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->nameAttributePresent = true; 
	parserData->otherVarStruct->name = "";
*/
;}
    break;

  case 681:

    {
/*	parserData->tmpOtherName=$2; parserData->nameAttributePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
;}
    break;

  case 682:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
;}
    break;

  case 684:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
;}
    break;

  case 688:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/;}
    break;

  case 689:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/;}
    break;

  case 692:

    {/*parserData->itemContent = $2; free($2);*/;}
    break;

  case 694:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 695:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 697:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);    free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 698:

    { parserData->tempStr = (yyvsp[(1) - (1)].ival);  /*free($1);*/ ;}
    break;

  case 699:

    { parserData->tempStr = (yyvsp[(1) - (1)].dval);  /*free($1);*/ ;}
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


