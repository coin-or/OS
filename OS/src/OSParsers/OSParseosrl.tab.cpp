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
#define YYLAST   938

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  340
/* YYNRULES -- Number of rules.  */
#define YYNRULES  631
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1057

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
     583,   585,   590,   592,   594,   597,   599,   603,   605,   608,
     612,   614,   615,   618,   620,   622,   624,   628,   632,   634,
     638,   640,   643,   645,   646,   649,   654,   655,   658,   660,
     662,   664,   666,   668,   670,   672,   674,   676,   678,   680,
     685,   689,   692,   697,   701,   704,   709,   713,   716,   721,
     725,   728,   733,   737,   740,   744,   749,   751,   755,   756,
     759,   763,   764,   767,   769,   771,   773,   775,   779,   781,
     785,   787,   791,   793,   797,   799,   801,   803,   806,   808,
     812,   813,   815,   817,   823,   825,   826,   829,   831,   833,
     837,   841,   843,   845,   847,   853,   855,   856,   859,   861,
     863,   867,   871,   873,   875,   877,   883,   885,   886,   889,
     891,   893,   897,   901,   903,   905,   907,   913,   915,   916,
     919,   923,   925,   927,   931,   933,   938,   940,   942,   945,
     947,   951,   953,   956,   960,   962,   963,   966,   968,   970,
     972,   976,   980,   982,   986,   988,   991,   993,   994,   998,
     999,  1002,  1005,  1008,  1011,  1014,  1018,  1022,  1026,  1030,
    1034,  1036,  1039,  1040,  1043,  1047,  1049,  1050,  1053,  1055,
    1057,  1062,  1066,  1075,  1079,  1081,  1084,  1088,  1090,  1094,
    1096,  1101,  1103,  1105,  1108,  1110,  1114,  1116,  1119,  1123,
    1124,  1127,  1129,  1131,  1135,  1139,  1141,  1144,  1146,  1147,
    1152,  1156,  1159,  1160,  1164,  1165,  1170,  1172,  1174,  1176,
    1183,  1184,  1190,  1194,  1199,  1200,  1203,  1209,  1214,  1216,
    1218,  1219,  1225,  1229,  1234,  1235,  1238,  1244,  1249,  1253,
    1258,  1259,  1265,  1269,  1274,  1275,  1278,  1284,  1289,  1290,
    1293,  1294,  1299,  1301,  1303,  1304,  1307,  1309,  1311,  1313,
    1315,  1320,  1322,  1326,  1328,  1332,  1336,  1338,  1340,  1344,
    1345,  1348,  1352,  1354,  1359,  1363,  1366,  1368,  1369,  1373,
    1374,  1379,  1381,  1383,  1385,  1390,  1391,  1397,  1401,  1406,
    1407,  1410,  1416,  1421,  1423,  1425,  1426,  1429,  1433,  1435,
    1436,  1439,  1441,  1443,  1445,  1447,  1452,  1454,  1458,  1460,
    1464,  1468,  1470,  1472,  1476,  1477,  1480,  1484,  1486,  1491,
    1495,  1498,  1500,  1501,  1505,  1506,  1511,  1513,  1515,  1517,
    1522,  1523,  1529,  1533,  1538,  1539,  1542,  1548,  1553,  1555,
    1557,  1558,  1561,  1565,  1567,  1568,  1571,  1573,  1575,  1577,
    1579,  1584,  1586,  1590,  1592,  1596,  1600,  1602,  1604,  1608,
    1609,  1612,  1616,  1618,  1623,  1627,  1630,  1632,  1633,  1639,
    1643,  1644,  1650,  1651,  1654,  1660,  1664,  1665,  1666,  1670,
    1672,  1674,  1676,  1678,  1683,  1685,  1689,  1693,  1695,  1699,
    1701,  1702,  1705,  1707,  1709,  1711,  1713,  1714,  1719,  1721,
    1722,  1726,  1731,  1733,  1737,  1738,  1741,  1747,  1751,  1752,
    1753,  1757,  1759,  1761,  1763,  1765,  1770,  1772,  1776,  1780,
    1782,  1786,  1788,  1789,  1792,  1794,  1796,  1798,  1800,  1801,
    1806,  1808,  1810,  1813,  1815,  1817,  1819,  1821,  1823,  1825,
    1827,  1828
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   216,   261,   284,   348,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   194,    -1,   195,    -1,   196,    -1,   197,
      -1,   198,    -1,   199,    -1,   200,    -1,   201,    -1,   176,
     177,   183,    -1,    88,    -1,   178,    -1,   179,    -1,   178,
     179,    -1,   180,    -1,   181,    -1,   182,    -1,    36,     3,
     505,    -1,    37,    -1,    32,     3,   505,    -1,    33,    -1,
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
     108,    -1,    19,   505,     6,   505,    -1,   205,    -1,   206,
      -1,    10,   109,    -1,    11,    -1,    10,   207,   109,    -1,
     208,    -1,   207,   208,    -1,   209,   210,   215,    -1,   106,
      -1,    -1,   210,   211,    -1,   212,    -1,   213,    -1,   214,
      -1,    34,     3,   505,    -1,    40,     3,   505,    -1,    41,
      -1,    32,     3,   505,    -1,    33,    -1,    10,   107,    -1,
      11,    -1,    -1,    50,    11,    -1,    50,    10,   217,    51,
      -1,    -1,   217,   218,    -1,   219,    -1,   220,    -1,   227,
      -1,   234,    -1,   241,    -1,   246,    -1,   136,    10,     4,
     137,    -1,   136,    10,   137,    -1,   136,    11,    -1,   221,
     222,    10,   226,    69,    -1,    68,    -1,    -1,   222,   223,
      -1,   224,    -1,   225,    -1,    38,     3,   505,    -1,    32,
       3,   505,    -1,    33,    -1,     6,    -1,     7,    -1,   228,
     229,    10,   233,    71,    -1,    70,    -1,    -1,   229,   230,
      -1,   231,    -1,   232,    -1,    38,     3,   505,    -1,    32,
       3,   505,    -1,    33,    -1,     6,    -1,     7,    -1,   235,
     236,    10,   240,    67,    -1,    66,    -1,    -1,   236,   237,
      -1,   238,    -1,   239,    -1,    38,     3,   505,    -1,    32,
       3,   505,    -1,    33,    -1,     6,    -1,     7,    -1,   242,
     243,    10,   245,    65,    -1,    64,    -1,    -1,   244,    -1,
      32,     3,   505,    -1,    33,    -1,     6,    -1,   247,   248,
     249,    -1,   108,    -1,    19,   505,     6,   505,    -1,   250,
      -1,   251,    -1,    10,   109,    -1,    11,    -1,    10,   252,
     109,    -1,   253,    -1,   252,   253,    -1,   254,   255,   260,
      -1,   106,    -1,    -1,   255,   256,    -1,   257,    -1,   258,
      -1,   259,    -1,    34,     3,   505,    -1,    40,     3,   505,
      -1,    41,    -1,    32,     3,   505,    -1,    33,    -1,    10,
     107,    -1,    11,    -1,    -1,    52,    11,    -1,    52,    10,
     262,    53,    -1,    -1,   262,   263,    -1,   264,    -1,   265,
      -1,   266,    -1,   267,    -1,   268,    -1,   269,    -1,    82,
      10,     4,    83,    -1,    82,    10,    83,    -1,    82,    11,
      -1,    80,    10,     6,    81,    -1,    80,    10,    81,    -1,
      80,    11,    -1,   146,    10,     6,   147,    -1,   146,    10,
     147,    -1,   146,    11,    -1,   140,    10,     4,   141,    -1,
     140,    10,   141,    -1,   140,    11,    -1,   122,    10,   504,
     123,    -1,   122,    10,   123,    -1,   122,    11,    -1,   270,
     271,   272,    -1,   108,    -1,    19,   505,     6,   505,    -1,
     273,    -1,   274,    -1,    10,   109,    -1,    11,    -1,    10,
     275,   109,    -1,   276,    -1,   275,   276,    -1,   277,   278,
     283,    -1,   106,    -1,    -1,   278,   279,    -1,   280,    -1,
     281,    -1,   282,    -1,    34,     3,   505,    -1,    40,     3,
     505,    -1,    41,    -1,    32,     3,   505,    -1,    33,    -1,
      10,   107,    -1,    11,    -1,    -1,    54,    11,    -1,    54,
      10,   285,    55,    -1,    -1,   285,   286,    -1,   287,    -1,
     288,    -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,
     307,    -1,   314,    -1,   321,    -1,   328,    -1,   333,    -1,
     130,    10,     4,   131,    -1,   130,    10,   131,    -1,   130,
      11,    -1,   132,    10,     4,   133,    -1,   132,    10,   133,
      -1,   132,    11,    -1,   116,    10,     4,   117,    -1,   116,
      10,   117,    -1,   116,    11,    -1,    62,    10,     4,    63,
      -1,    62,    10,    63,    -1,    62,    11,    -1,    86,    10,
       4,    87,    -1,    86,    10,    87,    -1,    86,    11,    -1,
     144,   293,   294,    -1,    25,     8,     6,     8,    -1,    11,
      -1,    10,   295,   145,    -1,    -1,   295,   296,    -1,   138,
     297,   303,    -1,    -1,   297,   298,    -1,   299,    -1,   300,
      -1,   301,    -1,   302,    -1,    36,     3,     8,    -1,    37,
      -1,    30,     3,     8,    -1,    31,    -1,    38,     3,     8,
      -1,    39,    -1,    32,     3,     8,    -1,    33,    -1,   304,
      -1,   305,    -1,    10,   139,    -1,    11,    -1,    10,   306,
     139,    -1,    -1,     7,    -1,     6,    -1,   308,   309,    10,
     313,   153,    -1,   152,    -1,    -1,   309,   310,    -1,   311,
      -1,   312,    -1,    38,     3,   505,    -1,    32,     3,   505,
      -1,    33,    -1,     6,    -1,     7,    -1,   315,   316,    10,
     320,   155,    -1,   154,    -1,    -1,   316,   317,    -1,   318,
      -1,   319,    -1,    38,     3,   505,    -1,    32,     3,   505,
      -1,    33,    -1,     6,    -1,     7,    -1,   322,   323,    10,
     327,   151,    -1,   150,    -1,    -1,   323,   324,    -1,   325,
      -1,   326,    -1,    38,     3,   505,    -1,    32,     3,   505,
      -1,    33,    -1,     6,    -1,     7,    -1,   329,   330,    10,
     332,   149,    -1,   148,    -1,    -1,   330,   331,    -1,    32,
       3,   505,    -1,    33,    -1,     6,    -1,   334,   335,   336,
      -1,   108,    -1,    19,   505,     6,   505,    -1,   337,    -1,
     338,    -1,    10,   109,    -1,    11,    -1,    10,   339,   109,
      -1,   340,    -1,   339,   340,    -1,   341,   342,   347,    -1,
     106,    -1,    -1,   342,   343,    -1,   344,    -1,   345,    -1,
     346,    -1,    34,     3,   505,    -1,    40,     3,   505,    -1,
      41,    -1,    32,     3,   505,    -1,    33,    -1,    10,   107,
      -1,    11,    -1,    -1,    56,   349,   355,    -1,    -1,   349,
     350,    -1,   351,   505,    -1,   352,   505,    -1,   353,   505,
      -1,   354,   505,    -1,    22,   505,     6,    -1,    27,   505,
       6,    -1,    13,   505,     6,    -1,    16,   505,     6,    -1,
      10,   356,    57,    -1,    11,    -1,   357,   487,    -1,    -1,
     357,   358,    -1,   359,   360,   364,    -1,   124,    -1,    -1,
     360,   361,    -1,   362,    -1,   363,    -1,    28,   505,     6,
     505,    -1,    42,     3,   505,    -1,    10,   365,   378,   379,
     417,   443,   469,   486,    -1,   130,   366,   368,    -1,   367,
      -1,   366,   367,    -1,    36,     3,   505,    -1,    37,    -1,
      32,     3,   505,    -1,    33,    -1,    24,     8,     6,     8,
      -1,   369,    -1,   370,    -1,    10,   131,    -1,    11,    -1,
      10,   371,   131,    -1,   372,    -1,   371,   372,    -1,   134,
     373,   377,    -1,    -1,   373,   374,    -1,   375,    -1,   376,
      -1,    36,     3,     8,    -1,    32,     3,     8,    -1,    33,
      -1,    10,   135,    -1,    11,    -1,    -1,    96,    10,     4,
      97,    -1,    96,    10,    97,    -1,    96,    11,    -1,    -1,
     162,   380,   381,    -1,    -1,    21,   505,     6,   505,    -1,
     382,    -1,   383,    -1,    11,    -1,    10,   384,   390,   395,
     400,   163,    -1,    -1,   156,   385,    10,   386,   157,    -1,
     156,   385,    11,    -1,    26,   505,     6,   505,    -1,    -1,
     386,   387,    -1,   160,   388,    10,   389,   161,    -1,    29,
     505,     6,   505,    -1,     6,    -1,     7,    -1,    -1,   158,
     391,    10,   392,   159,    -1,   158,   391,    11,    -1,    26,
     505,     6,   505,    -1,    -1,   392,   393,    -1,   160,   394,
      10,     4,   161,    -1,   160,   394,    10,   161,    -1,   160,
     394,    11,    -1,    29,   505,     6,   505,    -1,    -1,    72,
     396,    10,   397,    73,    -1,    72,   396,    11,    -1,    26,
     505,     6,   505,    -1,    -1,   397,   398,    -1,   160,   399,
      10,     4,   161,    -1,    29,   505,     6,   505,    -1,    -1,
     400,   401,    -1,    -1,   403,   404,   402,   411,    -1,   106,
      -1,   405,    -1,    -1,   405,   406,    -1,   407,    -1,   408,
      -1,   409,    -1,   410,    -1,    26,   505,     6,   505,    -1,
      41,    -1,    40,     3,   505,    -1,    35,    -1,    34,     3,
     505,    -1,    32,     3,   505,    -1,    33,    -1,    11,    -1,
      10,   412,   107,    -1,    -1,   412,   413,    -1,   414,   415,
     416,    -1,   160,    -1,    29,   505,     6,   505,    -1,    10,
     506,   161,    -1,    10,   161,    -1,    11,    -1,    -1,   100,
     418,   419,    -1,    -1,    18,   505,     6,   505,    -1,   420,
      -1,   421,    -1,    11,    -1,    10,   422,   428,   101,    -1,
      -1,   156,   423,    10,   424,   157,    -1,   156,   423,    11,
      -1,    15,   505,     6,   505,    -1,    -1,   424,   425,    -1,
      98,   426,    10,   427,    99,    -1,    29,   505,     6,   505,
      -1,     6,    -1,     7,    -1,    -1,   428,   429,    -1,   430,
     431,   437,    -1,   106,    -1,    -1,   431,   432,    -1,   433,
      -1,   434,    -1,   435,    -1,   436,    -1,    15,   505,     6,
     505,    -1,    41,    -1,    40,     3,   505,    -1,    35,    -1,
      34,     3,   505,    -1,    32,     3,   505,    -1,    33,    -1,
      11,    -1,    10,   438,   107,    -1,    -1,   438,   439,    -1,
     440,   441,   442,    -1,    98,    -1,    29,   505,     6,   505,
      -1,    10,   506,    99,    -1,    10,    99,    -1,    11,    -1,
      -1,    78,   444,   445,    -1,    -1,    17,   505,     6,   505,
      -1,   446,    -1,   447,    -1,    11,    -1,    10,   448,   454,
      79,    -1,    -1,    84,   449,    10,   450,    85,    -1,    84,
     449,    11,    -1,    12,   505,     6,   505,    -1,    -1,   450,
     451,    -1,    76,   452,    10,   453,    77,    -1,    29,   505,
       6,   505,    -1,     7,    -1,     6,    -1,    -1,   454,   455,
      -1,   456,   457,   463,    -1,   106,    -1,    -1,   457,   458,
      -1,   459,    -1,   460,    -1,   461,    -1,   462,    -1,    12,
     505,     6,   505,    -1,    41,    -1,    40,     3,   505,    -1,
      35,    -1,    34,     3,   505,    -1,    32,     3,   505,    -1,
      33,    -1,    11,    -1,    10,   464,   107,    -1,    -1,   464,
     465,    -1,   466,   467,   468,    -1,    76,    -1,    29,   505,
       6,   505,    -1,    10,   506,    77,    -1,    10,    77,    -1,
      11,    -1,    -1,   112,   470,    10,   472,   113,    -1,   112,
     470,    11,    -1,    -1,    20,     8,     6,   471,     8,    -1,
      -1,   472,   473,    -1,   110,   474,    10,   481,   111,    -1,
     110,   474,    11,    -1,    -1,    -1,   474,   475,   476,    -1,
     477,    -1,   478,    -1,   479,    -1,   480,    -1,    14,     8,
       6,     8,    -1,    35,    -1,    34,     3,   505,    -1,    30,
       3,     8,    -1,    31,    -1,    32,     3,     8,    -1,    33,
      -1,    -1,   481,   482,    -1,   483,    -1,   484,    -1,    60,
      -1,    61,    -1,    -1,    58,     5,   485,    59,    -1,   125,
      -1,    -1,   114,   488,   489,    -1,    23,   505,     6,   505,
      -1,    11,    -1,    10,   490,   115,    -1,    -1,   490,   491,
      -1,   128,   492,    10,   499,   129,    -1,   128,   492,    11,
      -1,    -1,    -1,   492,   493,   494,    -1,   495,    -1,   496,
      -1,   497,    -1,   498,    -1,    14,     8,     6,     8,    -1,
      35,    -1,    34,     3,     8,    -1,    30,     3,     8,    -1,
      31,    -1,    32,     3,     8,    -1,    33,    -1,    -1,   499,
     500,    -1,   501,    -1,   502,    -1,    60,    -1,    61,    -1,
      -1,    58,     5,   503,    59,    -1,     6,    -1,     7,    -1,
     508,     8,    -1,     4,    -1,     6,    -1,     7,    -1,   165,
      -1,   166,    -1,   167,    -1,   168,    -1,    -1,   508,   507,
      -1
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
     646,   648,   648,   652,   652,   653,   655,   655,   658,   663,
     668,   673,   678,   683,   691,   692,   693,   696,   697,   698,
     701,   702,   703,   706,   707,   708,   711,   712,   713,   716,
     721,   723,   729,   729,   731,   731,   733,   735,   735,   737,
     746,   751,   751,   754,   760,   766,   775,   777,   778,   780,
     781,   783,   783,   786,   786,   787,   789,   789,   792,   797,
     802,   807,   812,   817,   822,   823,   824,   825,   826,   833,
     834,   835,   838,   839,   840,   843,   844,   845,   848,   849,
     850,   853,   854,   855,   858,   860,   866,   866,   868,   868,
     870,   872,   872,   874,   874,   874,   874,   876,   877,   879,
     880,   882,   883,   885,   886,   888,   888,   890,   890,   892,
     903,   907,   908,   911,   914,   920,   920,   922,   922,   924,
     934,   936,   939,   940,   942,   945,   951,   951,   953,   953,
     955,   963,   965,   968,   969,   972,   975,   982,   982,   984,
     984,   986,   998,  1000,  1003,  1004,  1007,  1010,  1017,  1017,
    1019,  1021,  1024,  1028,  1033,  1035,  1041,  1041,  1043,  1043,
    1045,  1047,  1047,  1049,  1058,  1063,  1063,  1066,  1072,  1078,
    1086,  1088,  1089,  1091,  1092,  1094,  1094,  1098,  1098,  1100,
    1100,  1102,  1103,  1104,  1105,  1109,  1110,  1111,  1112,  1115,
    1115,  1117,  1119,  1119,  1121,  1128,  1134,  1134,  1136,  1136,
    1138,  1145,  1148,  1151,  1153,  1154,  1156,  1157,  1158,  1159,
    1160,  1163,  1169,  1175,  1175,  1177,  1179,  1179,  1181,  1183,
    1183,  1185,  1185,  1187,  1191,  1192,  1194,  1194,  1198,  1199,
    1203,  1207,  1209,  1210,  1212,  1213,  1223,  1223,  1225,  1227,
    1229,  1230,  1239,  1250,  1257,  1257,  1259,  1261,  1264,  1268,
    1274,  1275,  1284,  1286,  1293,  1293,  1295,  1300,  1301,  1303,
    1307,  1307,  1316,  1318,  1325,  1325,  1327,  1329,  1334,  1334,
    1337,  1336,  1356,  1364,  1370,  1370,  1372,  1372,  1372,  1372,
    1374,  1386,  1389,  1395,  1401,  1407,  1412,  1414,  1415,  1417,
    1417,  1419,  1434,  1439,  1441,  1441,  1441,  1444,  1445,  1447,
    1448,  1458,  1458,  1460,  1462,  1464,  1465,  1474,  1476,  1480,
    1480,  1482,  1484,  1487,  1491,  1497,  1497,  1499,  1502,  1510,
    1511,  1513,  1513,  1513,  1513,  1515,  1524,  1527,  1533,  1539,
    1545,  1550,  1553,  1554,  1576,  1576,  1578,  1593,  1598,  1600,
    1600,  1600,  1604,  1605,  1607,  1608,  1618,  1618,  1620,  1622,
    1625,  1626,  1636,  1638,  1643,  1643,  1645,  1647,  1650,  1654,
    1660,  1660,  1662,  1665,  1667,  1667,  1669,  1669,  1669,  1669,
    1671,  1674,  1677,  1683,  1689,  1695,  1700,  1702,  1703,  1706,
    1706,  1708,  1724,  1729,  1731,  1731,  1731,  1735,  1736,  1741,
    1748,  1747,  1763,  1763,  1766,  1773,  1782,  1783,  1783,  1787,
    1787,  1787,  1787,  1789,  1802,  1808,  1816,  1819,  1822,  1825,
    1827,  1828,  1831,  1836,  1843,  1843,  1846,  1845,  1851,  1861,
    1861,  1863,  1865,  1865,  1867,  1867,  1870,  1877,  1879,  1881,
    1880,  1885,  1885,  1885,  1885,  1887,  1902,  1909,  1918,  1924,
    1927,  1933,  1935,  1936,  1938,  1943,  1949,  1949,  1952,  1951,
    1957,  1958,  1960,  1963,  1964,  1965,  1969,  1970,  1971,  1972,
    1974,  1975
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
  "serviceUtilization", "serviceOtherResults", "serviceOtherResultsStart",
  "serviceOtherResultsAttList", "serviceOtherResultsContent",
  "serviceOtherResultsEmpty", "serviceOtherResultsBody",
  "serviceOtherResultSEQ", "serviceOtherResult", "serviceOtherResultStart",
  "serviceOtherAttList", "serviceOtherAtt", "serviceOtherNameATT",
  "serviceOtherValueATT", "serviceOtherDescriptionATT", "serviceOtherEnd",
  "jobElement", "jobContent", "jobChild", "status", "submitTime",
  "scheduledStartTime", "actualStartTime", "endTime", "timingInformation",
  "numberoftimes", "timingContent", "listOfTimes", "time", "timeAttList",
  "timeAtt", "timeType", "timeCategory", "timeUnit", "timeDescription",
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
     270,   271,   272,   272,   273,   273,   274,   275,   275,   276,
     277,   278,   278,   279,   279,   279,   280,   281,   281,   282,
     282,   283,   283,   284,   284,   284,   285,   285,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   287,
     287,   287,   288,   288,   288,   289,   289,   289,   290,   290,
     290,   291,   291,   291,   292,   293,   294,   294,   295,   295,
     296,   297,   297,   298,   298,   298,   298,   299,   299,   300,
     300,   301,   301,   302,   302,   303,   303,   304,   304,   305,
     305,   306,   306,   307,   308,   309,   309,   310,   310,   311,
     312,   312,   313,   313,   314,   315,   316,   316,   317,   317,
     318,   319,   319,   320,   320,   321,   322,   323,   323,   324,
     324,   325,   326,   326,   327,   327,   328,   329,   330,   330,
     331,   331,   332,   333,   334,   335,   336,   336,   337,   337,
     338,   339,   339,   340,   341,   342,   342,   343,   343,   343,
     344,   345,   345,   346,   346,   347,   347,   348,   348,   349,
     349,   350,   350,   350,   350,   351,   352,   353,   354,   355,
     355,   356,   357,   357,   358,   359,   360,   360,   361,   361,
     362,   363,   364,   365,   366,   366,   367,   367,   367,   367,
     367,   368,   368,   369,   369,   370,   371,   371,   372,   373,
     373,   374,   374,   375,   376,   376,   377,   377,   378,   378,
     378,   378,   379,   379,   380,   380,   381,   381,   382,   383,
     384,   384,   384,   385,   386,   386,   387,   388,   389,   389,
     390,   390,   390,   391,   392,   392,   393,   393,   393,   394,
     395,   395,   395,   396,   397,   397,   398,   399,   400,   400,
     402,   401,   403,   404,   405,   405,   406,   406,   406,   406,
     407,   408,   408,   409,   409,   410,   410,   411,   411,   412,
     412,   413,   414,   415,   416,   416,   416,   417,   417,   418,
     418,   419,   419,   420,   421,   422,   422,   422,   423,   424,
     424,   425,   426,   427,   427,   428,   428,   429,   430,   431,
     431,   432,   432,   432,   432,   433,   434,   434,   435,   435,
     436,   436,   437,   437,   438,   438,   439,   440,   441,   442,
     442,   442,   443,   443,   444,   444,   445,   445,   446,   447,
     448,   448,   448,   449,   450,   450,   451,   452,   453,   453,
     454,   454,   455,   456,   457,   457,   458,   458,   458,   458,
     459,   460,   460,   461,   461,   462,   462,   463,   463,   464,
     464,   465,   466,   467,   468,   468,   468,   469,   469,   469,
     471,   470,   472,   472,   473,   473,   474,   475,   474,   476,
     476,   476,   476,   477,   478,   478,   479,   479,   480,   480,
     481,   481,   482,   482,   483,   483,   485,   484,   486,   487,
     487,   488,   489,   489,   490,   490,   491,   491,   492,   493,
     492,   494,   494,   494,   494,   495,   496,   496,   497,   497,
     498,   498,   499,   499,   500,   500,   501,   501,   503,   502,
     504,   504,   505,   506,   506,   506,   507,   507,   507,   507,
     508,   508
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
       1,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       1,     0,     2,     1,     1,     1,     3,     3,     1,     3,
       1,     2,     1,     0,     2,     4,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     2,     4,     3,     2,     4,     3,     2,     4,     3,
       2,     4,     3,     2,     3,     4,     1,     3,     0,     2,
       3,     0,     2,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     2,     1,     3,
       0,     1,     1,     5,     1,     0,     2,     1,     1,     3,
       3,     1,     1,     1,     5,     1,     0,     2,     1,     1,
       3,     3,     1,     1,     1,     5,     1,     0,     2,     1,
       1,     3,     3,     1,     1,     1,     5,     1,     0,     2,
       3,     1,     1,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     2,     3,     1,     0,     2,     1,     1,     1,
       3,     3,     1,     3,     1,     2,     1,     0,     3,     0,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       1,     2,     0,     2,     3,     1,     0,     2,     1,     1,
       4,     3,     8,     3,     1,     2,     3,     1,     3,     1,
       4,     1,     1,     2,     1,     3,     1,     2,     3,     0,
       2,     1,     1,     3,     3,     1,     2,     1,     0,     4,
       3,     2,     0,     3,     0,     4,     1,     1,     1,     6,
       0,     5,     3,     4,     0,     2,     5,     4,     1,     1,
       0,     5,     3,     4,     0,     2,     5,     4,     3,     4,
       0,     5,     3,     4,     0,     2,     5,     4,     0,     2,
       0,     4,     1,     1,     0,     2,     1,     1,     1,     1,
       4,     1,     3,     1,     3,     3,     1,     1,     3,     0,
       2,     3,     1,     4,     3,     2,     1,     0,     3,     0,
       4,     1,     1,     1,     4,     0,     5,     3,     4,     0,
       2,     5,     4,     1,     1,     0,     2,     3,     1,     0,
       2,     1,     1,     1,     1,     4,     1,     3,     1,     3,
       3,     1,     1,     3,     0,     2,     3,     1,     4,     3,
       2,     1,     0,     3,     0,     4,     1,     1,     1,     4,
       0,     5,     3,     4,     0,     2,     5,     4,     1,     1,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     1,
       4,     1,     3,     1,     3,     3,     1,     1,     3,     0,
       2,     3,     1,     4,     3,     2,     1,     0,     5,     3,
       0,     5,     0,     2,     5,     3,     0,     0,     3,     1,
       1,     1,     1,     4,     1,     3,     3,     1,     3,     1,
       0,     2,     1,     1,     1,     1,     0,     4,     1,     0,
       3,     4,     1,     3,     0,     2,     5,     3,     0,     0,
       3,     1,     1,     1,     1,     4,     1,     3,     3,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     0,     4,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    95,     4,
       8,     6,     0,   173,     0,    98,    96,     0,   223,     7,
      20,     0,     0,     0,    72,     0,     0,     0,     0,     9,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,   176,   174,     0,   347,     0,    61,     0,    64,
       0,    52,     0,    58,     0,    55,     0,    67,     0,    70,
       0,     0,    30,     0,    28,     0,    21,    22,    24,    25,
      26,   630,     0,    97,   143,   132,   110,   121,   150,     0,
      99,   100,   101,   111,   102,   122,   103,   133,   104,   144,
     105,     0,     0,   226,   224,   349,     0,     0,    60,     0,
      63,     0,    51,     0,    57,     0,    54,     0,    66,     0,
      69,     0,   630,   630,     0,    35,    19,    32,    33,    23,
       0,     0,     0,    77,    71,    74,    75,     0,   108,     0,
       0,     0,     0,   147,     0,   145,   630,     0,   175,     0,
       0,   200,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,     0,     0,     0,     2,    59,    62,    50,    56,
      53,    65,    68,     0,    29,    27,    34,    40,     0,    37,
      41,   630,   622,   626,   627,   628,   629,   631,    82,    76,
       0,    79,    83,     0,   107,     0,     0,   117,     0,   112,
     113,   114,     0,     0,   128,     0,   123,   124,   125,     0,
       0,   139,     0,   134,   135,   136,   630,     0,     0,     0,
     155,   149,   152,   153,     0,   189,     0,   186,     0,   198,
       0,   195,     0,   192,   630,     0,   225,     0,     0,   324,
       0,     0,     0,     0,   317,   306,   284,   295,   227,   228,
     229,   230,   231,   232,   233,   234,   285,   235,   296,   236,
     307,   237,   318,   238,     0,   362,   360,   630,   630,   630,
     630,   350,   630,   630,   630,   630,   348,    31,    36,    38,
       0,    73,    78,    80,     0,   106,   118,   119,     0,   630,
     630,   129,   130,     0,   630,   630,   140,   141,     0,   630,
     630,   146,   148,     0,   630,   160,   154,     0,   157,   161,
       0,   188,     0,   185,   620,   621,   197,     0,     0,   194,
       0,   191,     0,     0,   205,   199,   202,   203,     0,   250,
       0,   253,     0,   247,     0,   241,     0,   244,     0,     0,
       0,     0,     0,     0,   630,     0,     0,   589,     0,     0,
       0,     0,   351,   352,   353,   354,     0,    49,     0,    47,
       0,    42,    43,    44,    39,     0,    94,     0,    92,     0,
       0,    90,    84,    85,    86,    87,    81,   109,   116,   115,
     120,   127,   126,   131,   138,   137,   142,   151,   156,   158,
       0,   187,   184,   196,   193,   190,   630,   210,   204,     0,
     207,   211,     0,   249,     0,   252,     0,   246,     0,   240,
       0,   243,     0,   258,   256,   254,     0,     0,   291,     0,
     286,   287,   288,     0,     0,   302,     0,   297,   298,   299,
       0,     0,   313,     0,   308,   309,   310,     0,     0,   321,
     319,     0,     0,   329,   323,   326,   327,   359,     0,   365,
     363,   366,   361,   357,   358,   355,   356,    48,     0,     0,
      93,   630,   630,   630,     0,   172,     0,   170,     0,     0,
     168,   162,   163,   164,   165,   159,   201,   206,   208,     0,
     248,   251,   245,   239,   242,     0,     0,   292,   293,     0,
     630,   630,   303,   304,     0,   630,   630,   314,   315,     0,
     630,   630,   322,     0,   630,   630,   334,   328,     0,   331,
     335,   630,     0,     0,    46,    45,    91,    88,    89,   171,
     630,   630,   630,     0,   222,     0,   220,     0,     0,   218,
     212,   213,   214,   215,   209,   255,   261,   257,   259,   283,
     290,   289,   294,   301,   300,   305,   312,   311,   316,   320,
     325,   330,   332,     0,     0,   594,   592,   590,     0,   630,
       0,   367,   368,   369,   364,   169,   166,   167,   221,   630,
     630,   630,   280,     0,   346,     0,   344,     0,     0,   342,
     336,   337,   338,   339,   333,   630,     0,     0,   398,     0,
     630,   219,   216,   217,     0,   278,     0,   270,     0,   274,
       0,   268,     0,   272,   262,   263,   264,   265,   266,   260,
     275,   276,   345,   630,   630,   630,   591,   593,   598,   595,
       0,     0,   379,     0,   377,     0,   374,     0,   402,   630,
     371,   282,   281,   277,     0,     0,     0,     0,     0,   343,
     340,   341,   599,     0,   630,   630,     0,   384,   375,   373,
     381,   382,     0,   401,   404,   467,   370,   279,   269,   273,
     267,   271,   612,   597,     0,     0,   378,   376,   383,   389,
       0,   386,     0,   400,   630,     0,   469,   512,     0,     0,
       0,   609,     0,   611,     0,   606,   600,   601,   602,   603,
     604,   380,     0,   385,   387,   399,     0,   410,   408,   403,
     406,   407,   630,     0,   514,   557,     0,   616,   617,   596,
     613,   614,   615,     0,     0,     0,     0,     0,   397,     0,
     395,     0,   390,   391,   392,   388,   630,     0,   420,     0,
     475,   473,   468,   471,   472,   630,     0,     0,     0,   618,
       0,   608,   610,   607,   396,     0,     0,   405,   630,     0,
       0,   430,   630,     0,   485,     0,   520,   518,   513,   516,
     517,     0,     0,   588,   372,     0,   605,   394,   393,     0,
     414,   412,   630,     0,     0,   438,   470,   630,     0,     0,
     630,     0,   530,     0,   562,   559,   619,   630,     0,     0,
     424,   422,   630,     0,     0,     0,   479,   477,   474,   488,
     486,   489,   515,   630,     0,     0,   560,     0,   413,   411,
       0,   415,   630,     0,     0,   434,   432,   442,   409,   439,
     444,   630,     0,     0,     0,   524,   522,   519,   533,   531,
     534,     0,   566,   558,   563,   630,     0,   423,   421,     0,
     425,   630,     0,   440,   443,   478,     0,   476,   480,   504,
     502,   630,     0,   501,     0,   498,     0,   496,   490,   491,
     492,   493,   494,   487,   630,     0,     0,   561,   567,     0,
       0,   630,     0,   433,   431,     0,   435,     0,   630,     0,
     456,     0,   453,     0,   451,   445,   446,   447,   448,   449,
     630,     0,     0,     0,   630,   630,   630,   523,     0,   521,
     525,   549,   547,   630,     0,   546,     0,   543,     0,   541,
     535,   536,   537,   538,   539,   532,   580,   565,     0,   630,
     418,   419,     0,     0,     0,   428,   630,     0,   459,   457,
     441,     0,   630,   630,   630,     0,     0,   507,   503,   505,
       0,   630,   500,   499,   497,   630,     0,     0,     0,   630,
     630,   630,     0,     0,     0,   577,     0,   579,     0,   574,
     568,   569,   570,   571,   572,   417,   416,   630,     0,   427,
       0,     0,     0,   630,   455,   454,   452,   630,   483,   484,
       0,   630,     0,   495,     0,     0,   552,   548,   550,     0,
     630,   545,   544,   542,     0,   584,   585,   564,   581,   582,
     583,     0,     0,     0,   630,   429,   426,   630,     0,   458,
     462,   460,     0,   450,   482,   481,     0,     0,   511,   506,
     630,   529,   528,     0,   630,     0,   540,   586,     0,   576,
     578,   575,   437,   436,   630,     0,   630,   623,   624,   625,
     510,     0,   527,   526,     0,     0,   556,   551,     0,   573,
       0,     0,   466,   461,   508,   509,   630,   555,     0,   587,
     630,   465,     0,   553,   554,   463,   464
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    31,    65,    66,
      67,    68,    69,    70,   116,   117,   118,   168,   169,   170,
     270,   351,   352,   353,   354,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    72,   124,   125,   126,   180,   181,
     182,   274,   362,   363,   364,   365,   366,    13,    41,    80,
      81,    82,    83,   129,   189,   190,   191,   278,    84,    85,
     130,   196,   197,   198,   283,    86,    87,   131,   203,   204,
     205,   288,    88,    89,   134,   135,   293,    90,    91,   137,
     211,   212,   213,   297,   298,   299,   380,   461,   462,   463,
     464,   465,    18,    92,   145,   146,   147,   148,   149,   150,
     151,   152,   225,   315,   316,   317,   389,   390,   391,   469,
     520,   521,   522,   523,   524,    45,   153,   238,   239,   240,
     241,   242,   243,   244,   329,   405,   476,   528,   562,   594,
     595,   596,   597,   598,   599,   600,   601,   624,   245,   246,
     330,   410,   411,   412,   479,   247,   248,   331,   417,   418,
     419,   484,   249,   250,   332,   424,   425,   426,   489,   251,
     252,   333,   430,   493,   253,   254,   335,   434,   435,   436,
     498,   499,   500,   543,   570,   571,   572,   573,   574,    96,
     154,   261,   262,   263,   264,   265,   266,   336,   337,   440,
     441,   503,   551,   552,   553,   554,   578,   615,   616,   639,
     640,   641,   660,   661,   682,   712,   713,   714,   715,   618,
     645,   665,   689,   690,   691,   718,   739,   778,   801,   826,
     912,   741,   763,   803,   830,   862,   765,   783,   832,   866,
     917,   784,   809,   867,   810,   833,   834,   875,   876,   877,
     878,   879,   920,   962,  1001,  1002,  1025,  1043,   667,   693,
     722,   723,   724,   744,   768,   812,   838,   881,   970,   769,
     790,   791,   813,   848,   849,   850,   851,   852,   853,   882,
     929,   930,   972,  1009,   695,   726,   748,   749,   750,   772,
     794,   855,   890,   936,  1013,   795,   819,   820,   856,   900,
     901,   902,   903,   904,   905,   937,   978,   979,  1015,  1037,
     728,   752,   821,   797,   824,   858,   908,   950,   951,   952,
     953,   954,   942,   988,   989,   990,  1038,   754,   442,   502,
     547,   576,   609,   632,   654,   676,   677,   678,   679,   680,
     668,   700,   701,   702,   755,   307,   120,  1031,   177,   121
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -902
static const yytype_int16 yypact[] =
{
      25,    46,    51,    58,  -902,    63,  -902,    78,    34,  -902,
    -902,  -902,   146,    56,   -22,  -902,  -902,   174,    83,  -902,
    -902,   265,   339,   352,  -902,   354,   356,   360,   365,  -902,
    -902,   280,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
      91,   -23,  -902,  -902,   370,    85,    29,  -902,    31,  -902,
      27,  -902,    14,  -902,     9,  -902,     8,  -902,     0,  -902,
     161,   189,  -902,   217,  -902,   374,   280,  -902,  -902,  -902,
    -902,  -902,   376,  -902,  -902,  -902,  -902,  -902,  -902,   380,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,   302,
    -902,   167,   -17,  -902,  -902,  -902,   153,   135,  -902,   137,
    -902,   143,  -902,   144,  -902,   156,  -902,   129,  -902,   141,
    -902,   337,  -902,  -902,   -47,  -902,  -902,  -902,  -902,  -902,
     353,    -6,    49,  -902,  -902,  -902,  -902,    17,  -902,   181,
     211,   226,   369,  -902,   367,  -902,  -902,   382,  -902,   384,
     386,  -902,   391,   393,   395,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,   394,   -33,   315,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,   430,  -902,  -902,  -902,  -902,   -18,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
     177,  -902,  -902,   251,  -902,   401,   459,  -902,   485,  -902,
    -902,  -902,   403,   491,  -902,   492,  -902,  -902,  -902,   405,
     493,  -902,   494,  -902,  -902,  -902,  -902,   471,   495,   199,
    -902,  -902,  -902,  -902,    33,  -902,    26,  -902,    13,  -902,
       1,  -902,    -3,  -902,  -902,   404,  -902,   406,   408,  -902,
     410,   412,   414,   411,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,   480,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
     255,  -902,  -902,  -902,   165,  -902,  -902,  -902,   434,  -902,
    -902,  -902,  -902,   427,  -902,  -902,  -902,  -902,   437,  -902,
    -902,  -902,  -902,   441,  -902,  -902,  -902,   200,  -902,  -902,
     419,  -902,   422,  -902,  -902,  -902,  -902,   379,   368,  -902,
     361,  -902,   504,   205,  -902,  -902,  -902,  -902,    30,  -902,
      40,  -902,    11,  -902,     7,  -902,     6,  -902,   503,   416,
     229,   240,   247,    44,  -902,   418,   455,   -62,   507,   508,
     509,   510,  -902,  -902,  -902,  -902,   383,  -902,   514,  -902,
     516,  -902,  -902,  -902,  -902,   413,  -902,   518,  -902,   521,
     522,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
     183,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,   209,
    -902,  -902,   463,  -902,   443,  -902,   415,  -902,   396,  -902,
     398,  -902,   523,  -902,  -902,  -902,   424,   525,  -902,   530,
    -902,  -902,  -902,   426,   531,  -902,   532,  -902,  -902,  -902,
     428,   533,  -902,   534,  -902,  -902,  -902,   535,   536,  -902,
    -902,   537,   221,  -902,  -902,  -902,  -902,  -902,   515,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,   538,   539,
    -902,  -902,  -902,  -902,   438,  -902,   541,  -902,   545,   546,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,   197,
    -902,  -902,  -902,  -902,  -902,   542,   -88,  -902,  -902,   387,
    -902,  -902,  -902,  -902,   399,  -902,  -902,  -902,  -902,   400,
    -902,  -902,  -902,   407,  -902,  -902,  -902,  -902,   223,  -902,
    -902,  -902,   429,    36,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,   451,  -902,   550,  -902,   552,   554,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,   201,   553,  -902,  -902,  -902,   432,  -902,
     557,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,   215,   457,  -902,   558,  -902,   560,   562,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,   -60,   324,   470,   561,
    -902,  -902,  -902,  -902,    10,  -902,   565,  -902,   566,  -902,
     567,  -902,   568,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
     564,   570,  -902,   571,  -902,   258,  -902,   431,   417,  -902,
    -902,  -902,  -902,  -902,   436,   569,   573,   574,   575,  -902,
    -902,  -902,   433,   572,  -902,  -902,   176,  -902,  -902,  -902,
    -902,  -902,    28,  -902,   555,   484,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,   267,   577,  -902,  -902,  -902,  -902,
     202,  -902,   445,  -902,  -902,   435,   576,   511,    42,   578,
     584,  -902,   585,  -902,   587,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,   260,  -902,  -902,  -902,   586,   439,  -902,  -902,
    -902,  -902,  -902,   440,   579,   481,   592,  -902,  -902,  -902,
    -902,  -902,  -902,   593,   583,   590,   594,   466,  -902,   597,
    -902,   600,  -902,  -902,  -902,  -902,  -902,   580,   447,   601,
     452,  -902,  -902,  -902,  -902,  -902,   442,   589,   486,  -902,
     602,  -902,  -902,  -902,  -902,   604,   606,  -902,  -902,   444,
     591,   543,  -902,   603,  -902,   610,   540,  -902,  -902,  -902,
    -902,   611,   446,  -902,  -902,   563,  -902,  -902,  -902,   614,
    -902,  -902,  -902,   448,   595,  -902,  -902,  -902,   450,   154,
    -902,   613,  -902,   617,  -902,  -902,  -902,  -902,   194,   621,
    -902,  -902,  -902,   454,   -68,   622,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,   456,   -39,  -902,   245,  -902,  -902,
     605,  -902,  -902,   310,   623,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,   -50,   155,   625,  -902,  -902,  -902,  -902,  -902,
    -902,   624,  -902,  -902,  -902,  -902,   626,  -902,  -902,   608,
    -902,  -902,   -59,  -902,   312,  -902,   609,  -902,  -902,  -902,
    -902,  -902,   630,  -902,   632,  -902,   636,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,    98,   169,  -902,   461,   634,
     467,  -902,   465,  -902,  -902,   612,  -902,   468,  -902,   639,
    -902,   640,  -902,   641,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,   635,   120,   642,  -902,  -902,  -902,  -902,   618,  -902,
    -902,  -902,  -902,  -902,   643,  -902,   646,  -902,   648,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,   289,  -902,
    -902,  -902,   496,   647,     3,  -902,  -902,   644,  -902,  -902,
    -902,   650,  -902,  -902,  -902,   653,   474,  -902,  -902,  -902,
     631,  -902,  -902,  -902,  -902,  -902,   651,   -27,   656,  -902,
    -902,  -902,    21,   655,   649,  -902,   661,  -902,   663,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,   506,  -902,
     662,   665,   -70,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
     581,  -902,   472,  -902,   666,   478,  -902,  -902,  -902,   645,
    -902,  -902,  -902,  -902,   668,  -902,  -902,  -902,  -902,  -902,
    -902,   669,   670,   671,  -902,  -902,  -902,  -902,   524,  -902,
    -902,  -902,   654,  -902,  -902,  -902,   676,    19,  -902,  -902,
    -902,  -902,  -902,   599,  -902,   476,  -902,  -902,   678,  -902,
    -902,  -902,  -902,  -902,  -902,   479,  -902,  -902,  -902,  -902,
    -902,   588,  -902,  -902,   682,    54,  -902,  -902,   633,  -902,
     683,     2,  -902,  -902,  -902,  -902,  -902,  -902,   607,  -902,
    -902,  -902,   544,  -902,  -902,  -902,  -902
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
     627,  -902,  -902,  -902,  -902,  -902,  -902,  -902,   526,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,   497,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,   409,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,   282,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,   193,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,    80,  -902,
    -902,  -902,  -902,    37,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,  -902,
    -902,  -902,  -902,  -902,  -902,  -902,  -112,  -901,  -902,  -902
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     164,   165,   172,   310,   109,   308,  1027,   958,  1028,  1029,
     400,   398,   107,   105,   864,   396,   621,   622,   103,   304,
     305,   183,   226,  1027,   208,  1028,  1029,    19,    73,   227,
     302,   101,   662,    97,   392,    99,   138,   999,   807,   300,
     817,    74,   166,    75,   394,    76,   548,    77,   836,   976,
     526,     6,   438,   228,   427,   607,     4,   527,  1027,   271,
    1028,  1029,   439,   139,   549,   140,    20,   818,   608,     1,
      21,   268,    22,     9,    23,   229,   428,   429,   550,   984,
     977,   985,   986,   230,    12,    78,    24,   167,    10,    11,
    1000,   141,     5,   393,   291,   808,    25,   231,    26,   232,
     696,   865,   697,   698,    27,   142,     7,   837,    17,   303,
      71,   233,   312,    79,   301,   234,   167,   235,  1030,   236,
      28,   237,    98,   143,   102,   663,   100,   395,   397,   144,
     106,  1047,   987,   104,  1048,   108,   306,    44,   399,   401,
    1052,    95,   309,   110,   311,   338,   339,   340,   341,   623,
     342,   343,   344,   345,   184,   178,    15,    16,   179,   173,
     174,   175,   176,  1051,   959,   839,   840,   368,   369,   111,
     841,   699,   371,   372,   888,   355,   356,   374,   375,   891,
     892,   893,   377,   889,    42,    43,   136,   842,   843,   844,
     845,   185,   112,   454,   455,   846,   847,   357,   358,   359,
     155,   894,   895,   896,   897,   360,   361,   513,   514,   898,
     899,   563,   564,   186,   187,   456,   457,   458,   927,   188,
     113,   192,   431,   459,   460,   584,   585,   928,   156,   515,
     516,   517,   157,   565,   566,   567,   199,   518,   519,   406,
     158,   568,   569,   193,   194,   586,   587,   588,   589,   195,
     413,   590,   591,   592,   593,   788,   161,   420,   200,   201,
     789,   407,   408,   159,   202,   346,   347,   409,   636,   637,
     707,   708,   414,   415,   466,    46,    47,   160,   416,   421,
     422,   669,   610,   178,   162,   423,   272,   348,   349,   350,
     611,   612,   709,   710,   613,   614,   711,   670,   671,   672,
     673,   674,   675,   943,    60,   295,   295,   658,   296,   378,
     659,   387,    61,    62,   388,   387,    63,    64,   467,   944,
     945,   946,   947,   948,   949,   255,   256,   496,   257,   496,
     497,   258,   541,   683,   132,   133,   659,   259,   868,   506,
     507,   508,   260,   163,   869,   870,   871,   872,   610,    48,
      49,   799,   873,   874,   800,   822,   611,   612,   823,   171,
     613,   614,    50,    51,    52,    53,    54,    55,   530,   531,
      56,    57,   206,   533,   534,    58,    59,   207,   536,   537,
      93,    94,   539,   540,   114,   115,   122,   123,   275,   544,
     127,   128,   209,   210,   214,   215,   216,   217,   555,   556,
     557,   218,   219,   220,   221,   222,   223,   276,   277,   281,
     282,   286,   287,   224,   313,   314,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   403,   404,   432,   433,
     477,   478,   482,   483,   487,   488,   328,   579,   267,   545,
     546,   642,   643,   652,   653,   687,   688,   581,   582,   583,
     720,   721,   746,   747,   760,   761,   774,   775,   780,   781,
     786,   787,   279,   606,   805,   806,   815,   816,   620,   828,
     829,   906,   907,   910,   911,   914,   915,   292,   918,   919,
     968,   969,  1007,  1008,  1011,  1012,  1035,  1036,   280,  1041,
    1042,   629,   630,   631,   284,   285,   289,   290,   370,   334,
     381,   294,   383,   367,   373,   382,   376,   646,   385,   384,
     386,   402,   437,   443,   444,   445,   446,   448,   447,   449,
     450,   451,   656,   657,   452,   453,   470,   473,   480,   475,
     471,   474,   472,   481,   485,   486,   490,   491,   501,   494,
     529,   492,   685,   495,   510,   509,   504,   505,   511,   512,
     525,   535,   686,   559,   532,   560,   538,   561,   558,   575,
     580,   603,   577,   604,   602,   605,   617,   619,   625,   626,
     627,   628,   633,   634,   635,   647,   664,   648,   655,   644,
     719,   649,   650,   651,   666,   681,   703,   704,   705,   694,
     706,   731,   716,   727,   692,   717,   725,   729,   732,   730,
     735,   734,   733,   736,   737,   740,   738,   742,   743,   751,
     756,   753,   757,   745,   758,   764,   770,   762,   767,   773,
     777,   782,   776,   796,   771,   793,   759,   802,   811,   831,
     766,   854,   857,   884,   825,   885,   860,   861,   880,   886,
     909,   916,   922,   923,   924,   926,   939,   935,   931,   940,
     779,   941,   992,   957,   961,   785,   963,   956,   792,   967,
     971,   975,   980,   991,   993,   798,   994,   996,   997,   998,
     804,   468,  1010,  1017,  1014,  1018,  1033,   273,  1019,  1020,
    1005,   814,  1026,  1024,  1054,  1023,  1039,  1045,  1046,  1050,
     827,   542,  1049,   119,   269,   638,     0,   684,     0,   835,
       0,     0,     0,     0,     0,  1056,   379,     0,     0,     0,
       0,     0,     0,   859,     0,     0,     0,     0,     0,   863,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   883,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   887,     0,     0,     0,     0,     0,     0,   913,
       0,     0,     0,     0,     0,     0,   921,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   925,     0,
       0,     0,   932,   933,   934,     0,     0,     0,     0,     0,
       0,   938,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   955,     0,     0,
       0,     0,     0,     0,   960,     0,     0,     0,     0,     0,
     964,   965,   966,     0,     0,     0,     0,     0,     0,   973,
       0,     0,     0,   974,     0,     0,     0,   981,   982,   983,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   995,     0,     0,     0,     0,
       0,  1003,     0,     0,     0,  1004,     0,     0,     0,  1006,
       0,     0,     0,     0,     0,     0,     0,     0,  1016,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1021,     0,     0,  1022,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1032,     0,
       0,     0,  1034,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1040,     0,  1044,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1053,     0,     0,     0,  1055
};

static const yytype_int16 yycheck[] =
{
     112,   113,     8,     6,     4,     4,     4,     4,     6,     7,
       4,     4,     4,     4,    73,     4,     6,     7,     4,     6,
       7,     4,    55,     4,   136,     6,     7,    49,    51,    62,
       4,     4,     4,     4,     4,     4,    53,   107,   106,     6,
      79,    64,    89,    66,     4,    68,    10,    70,    98,    76,
     138,     0,   114,    86,    10,   115,    10,   145,     4,   171,
       6,     7,   124,    80,    28,    82,    88,   106,   128,    44,
      92,    89,    94,    10,    96,   108,    32,    33,    42,    58,
     107,    60,    61,   116,    50,   108,   108,   134,    10,    11,
     160,   108,    46,    63,   206,   163,   118,   130,   120,   132,
      58,   160,    60,    61,   126,   122,    48,   157,    52,    83,
      19,   144,   224,   136,    81,   148,   134,   150,    99,   152,
     142,   154,    93,   140,    97,    97,    95,    87,   117,   146,
     121,    77,   111,   119,  1035,   127,   123,    54,   131,   133,
    1041,    56,   141,   143,   147,   257,   258,   259,   260,   139,
     262,   263,   264,   265,   137,   106,    10,    11,   109,   165,
     166,   167,   168,   161,   161,    10,    11,   279,   280,     8,
      15,   129,   284,   285,    76,    10,    11,   289,   290,    10,
      11,    12,   294,    85,    10,    11,    19,    32,    33,    34,
      35,    10,     3,    10,    11,    40,    41,    32,    33,    34,
      47,    32,    33,    34,    35,    40,    41,    10,    11,    40,
      41,    10,    11,    32,    33,    32,    33,    34,    98,    38,
       3,    10,   334,    40,    41,    10,    11,   107,    93,    32,
      33,    34,    95,    32,    33,    34,    10,    40,    41,    10,
      97,    40,    41,    32,    33,    30,    31,    32,    33,    38,
      10,    36,    37,    38,    39,   101,   127,    10,    32,    33,
     106,    32,    33,   119,    38,    10,    11,    38,    10,    11,
      10,    11,    32,    33,   386,    10,    11,   121,    38,    32,
      33,    14,    24,   106,   143,    38,   109,    32,    33,    34,
      32,    33,    32,    33,    36,    37,    36,    30,    31,    32,
      33,    34,    35,    14,    24,   106,   106,   131,   109,   109,
     134,   106,    32,    33,   109,   106,    36,    37,   109,    30,
      31,    32,    33,    34,    35,    10,    11,   106,    13,   106,
     109,    16,   109,   131,    32,    33,   134,    22,    26,   451,
     452,   453,    27,     6,    32,    33,    34,    35,    24,    10,
      11,   157,    40,    41,   160,   110,    32,    33,   113,     6,
      36,    37,    10,    11,    10,    11,    10,    11,   480,   481,
      10,    11,     3,   485,   486,    10,    11,    10,   490,   491,
      10,    11,   494,   495,    10,    11,    10,    11,   137,   501,
      10,    11,    10,    11,    10,    11,    10,    11,   510,   511,
     512,    10,    11,    10,    11,    10,    11,     6,     7,     6,
       7,     6,     7,    19,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
       6,     7,     6,     7,     6,     7,    25,   549,     8,    10,
      11,    10,    11,    10,    11,    10,    11,   559,   560,   561,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,     3,   575,    10,    11,    10,    11,   580,   159,
     160,    10,    11,     6,     7,    10,    11,     6,    10,    11,
       6,     7,    10,    11,     6,     7,    10,    11,     3,    10,
      11,   603,   604,   605,     3,     3,     3,     3,    71,    19,
      81,     6,   123,    69,    67,    83,    65,   619,   147,   141,
       6,     8,    57,     6,     6,     6,     6,     3,   135,     3,
     107,     3,   634,   635,     3,     3,    63,   131,     3,     6,
      87,   133,   117,     3,     3,     3,     3,     3,    23,     3,
     153,     6,    97,     6,     3,   107,     8,     8,     3,     3,
       8,   151,   664,     3,   155,     3,   149,     3,   107,     6,
       3,     3,   130,     3,   107,     3,    96,     6,     3,     3,
       3,     3,     8,     3,     3,   139,    21,     8,     6,   162,
     692,     8,     8,     8,   100,     8,     8,     3,     3,    78,
       3,     8,     6,   112,    18,   156,    17,     5,     8,     6,
       3,   135,     8,     3,   716,   158,    26,     6,   156,    20,
       8,   125,     8,   725,     8,    72,     6,    26,    15,     8,
       6,    26,    59,     6,    84,    12,   738,     6,     6,     6,
     742,     6,     8,     3,    29,     3,    10,    29,    29,     3,
       6,    29,     3,     3,     3,    10,     3,    29,     6,     3,
     762,     3,     3,     6,    10,   767,     6,   161,   770,     6,
      29,    10,     6,     8,     3,   777,     3,   161,     6,     4,
     782,   389,     6,     5,    29,     6,    77,   180,     8,     8,
      99,   793,     6,    29,    77,   161,     8,    99,     6,     6,
     802,   498,    59,    66,   168,   615,    -1,   660,    -1,   811,
      -1,    -1,    -1,    -1,    -1,   161,   297,    -1,    -1,    -1,
      -1,    -1,    -1,   825,    -1,    -1,    -1,    -1,    -1,   831,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   841,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   854,    -1,    -1,    -1,    -1,    -1,    -1,   861,
      -1,    -1,    -1,    -1,    -1,    -1,   868,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   880,    -1,
      -1,    -1,   884,   885,   886,    -1,    -1,    -1,    -1,    -1,
      -1,   893,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   909,    -1,    -1,
      -1,    -1,    -1,    -1,   916,    -1,    -1,    -1,    -1,    -1,
     922,   923,   924,    -1,    -1,    -1,    -1,    -1,    -1,   931,
      -1,    -1,    -1,   935,    -1,    -1,    -1,   939,   940,   941,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   957,    -1,    -1,    -1,    -1,
      -1,   963,    -1,    -1,    -1,   967,    -1,    -1,    -1,   971,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   980,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   994,    -1,    -1,   997,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1010,    -1,
      -1,    -1,  1014,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1024,    -1,  1026,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1046,    -1,    -1,    -1,  1050
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   216,   173,    10,    11,    52,   261,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   176,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   217,    10,    11,    54,   284,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      24,    32,    33,    36,    37,   177,   178,   179,   180,   181,
     182,    19,   203,    51,    64,    66,    68,    70,   108,   136,
     218,   219,   220,   221,   227,   228,   234,   235,   241,   242,
     246,   247,   262,    10,    11,    56,   348,     4,    93,     4,
      95,     4,    97,     4,   119,     4,   121,     4,   127,     4,
     143,     8,     3,     3,    10,    11,   183,   184,   185,   179,
     505,   508,    10,    11,   204,   205,   206,    10,    11,   222,
     229,   236,    32,    33,   243,   244,    19,   248,    53,    80,
      82,   108,   122,   140,   146,   263,   264,   265,   266,   267,
     268,   269,   270,   285,   349,    47,    93,    95,    97,   119,
     121,   127,   143,     6,   505,   505,    89,   134,   186,   187,
     188,     6,     8,   165,   166,   167,   168,   507,   106,   109,
     207,   208,   209,     4,   137,    10,    32,    33,    38,   223,
     224,   225,    10,    32,    33,    38,   230,   231,   232,    10,
      32,    33,    38,   237,   238,   239,     3,    10,   505,    10,
      11,   249,   250,   251,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    19,   271,    55,    62,    86,   108,
     116,   130,   132,   144,   148,   150,   152,   154,   286,   287,
     288,   289,   290,   291,   292,   307,   308,   314,   315,   321,
     322,   328,   329,   333,   334,    10,    11,    13,    16,    22,
      27,   350,   351,   352,   353,   354,   355,     8,    89,   187,
     189,   505,   109,   208,   210,   137,     6,     7,   226,     3,
       3,     6,     7,   233,     3,     3,     6,     7,   240,     3,
       3,   505,     6,   245,     6,   106,   109,   252,   253,   254,
       6,    81,     4,    83,     6,     7,   123,   504,     4,   141,
       6,   147,   505,    10,    11,   272,   273,   274,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    25,   293,
     309,   316,   323,   330,    19,   335,   356,   357,   505,   505,
     505,   505,   505,   505,   505,   505,    10,    11,    32,    33,
      34,   190,   191,   192,   193,    10,    11,    32,    33,    34,
      40,    41,   211,   212,   213,   214,   215,    69,   505,   505,
      71,   505,   505,    67,   505,   505,    65,   505,   109,   253,
     255,    81,    83,   123,   141,   147,     6,   106,   109,   275,
     276,   277,     4,    63,     4,    87,     4,   117,     4,   131,
       4,   133,     8,    10,    11,   294,    10,    32,    33,    38,
     310,   311,   312,    10,    32,    33,    38,   317,   318,   319,
      10,    32,    33,    38,   324,   325,   326,    10,    32,    33,
     331,   505,    10,    11,   336,   337,   338,    57,   114,   124,
     358,   359,   487,     6,     6,     6,     6,   135,     3,     3,
     107,     3,     3,     3,    10,    11,    32,    33,    34,    40,
      41,   256,   257,   258,   259,   260,   505,   109,   276,   278,
      63,    87,   117,   131,   133,     6,   295,     6,     7,   313,
       3,     3,     6,     7,   320,     3,     3,     6,     7,   327,
       3,     3,     6,   332,     3,     6,   106,   109,   339,   340,
     341,    23,   488,   360,     8,     8,   505,   505,   505,   107,
       3,     3,     3,    10,    11,    32,    33,    34,    40,    41,
     279,   280,   281,   282,   283,     8,   138,   145,   296,   153,
     505,   505,   155,   505,   505,   151,   505,   505,   149,   505,
     505,   109,   340,   342,   505,    10,    11,   489,    10,    28,
      42,   361,   362,   363,   364,   505,   505,   505,   107,     3,
       3,     3,   297,    10,    11,    32,    33,    34,    40,    41,
     343,   344,   345,   346,   347,     6,   490,   130,   365,   505,
       3,   505,   505,   505,    10,    11,    30,    31,    32,    33,
      36,    37,    38,    39,   298,   299,   300,   301,   302,   303,
     304,   305,   107,     3,     3,     3,   505,   115,   128,   491,
      24,    32,    33,    36,    37,   366,   367,    96,   378,     6,
     505,     6,     7,   139,   306,     3,     3,     3,     3,   505,
     505,   505,   492,     8,     3,     3,    10,    11,   367,   368,
     369,   370,    10,    11,   162,   379,   505,   139,     8,     8,
       8,     8,    10,    11,   493,     6,   505,   505,   131,   134,
     371,   372,     4,    97,    21,   380,   100,   417,   499,    14,
      30,    31,    32,    33,    34,    35,   494,   495,   496,   497,
     498,     8,   373,   131,   372,    97,   505,    10,    11,   381,
     382,   383,    18,   418,    78,   443,    58,    60,    61,   129,
     500,   501,   502,     8,     3,     3,     3,    10,    11,    32,
      33,    36,   374,   375,   376,   377,     6,   156,   384,   505,
      10,    11,   419,   420,   421,    17,   444,   112,   469,     5,
       6,     8,     8,     8,   135,     3,     3,   505,    26,   385,
     158,   390,     6,   156,   422,   505,    10,    11,   445,   446,
     447,    20,   470,   125,   486,   503,     8,     8,     8,   505,
      10,    11,    26,   391,    72,   395,   505,    15,   423,   428,
       6,    84,   448,     8,    10,    11,    59,     6,   386,   505,
      10,    11,    26,   396,   400,   505,    10,    11,   101,   106,
     429,   430,   505,    12,   449,   454,     6,   472,   505,   157,
     160,   387,     6,   392,   505,    10,    11,   106,   163,   401,
     403,     6,   424,   431,   505,    10,    11,    79,   106,   455,
     456,   471,   110,   113,   473,    29,   388,   505,   159,   160,
     393,     6,   397,   404,   405,   505,    98,   157,   425,    10,
      11,    15,    32,    33,    34,    35,    40,    41,   432,   433,
     434,   435,   436,   437,     6,   450,   457,     8,   474,   505,
      10,    29,   394,   505,    73,   160,   398,   402,    26,    32,
      33,    34,    35,    40,    41,   406,   407,   408,   409,   410,
      29,   426,   438,   505,     3,     3,     3,   505,    76,    85,
     451,    10,    11,    12,    32,    33,    34,    35,    40,    41,
     458,   459,   460,   461,   462,   463,    10,    11,   475,     6,
       6,     7,   389,   505,    10,    11,    29,   399,    10,    11,
     411,   505,     3,     3,     3,   505,    10,    98,   107,   439,
     440,     6,   505,   505,   505,    29,   452,   464,   505,     3,
       3,     3,   481,    14,    30,    31,    32,    33,    34,    35,
     476,   477,   478,   479,   480,   505,   161,     6,     4,   161,
     505,    10,   412,     6,   505,   505,   505,     6,     6,     7,
     427,    29,   441,   505,   505,    10,    76,   107,   465,   466,
       6,   505,   505,   505,    58,    60,    61,   111,   482,   483,
     484,     8,     3,     3,     3,   505,   161,     6,     4,   107,
     160,   413,   414,   505,   505,    99,   505,    10,    11,   442,
       6,     6,     7,   453,    29,   467,   505,     5,     6,     8,
       8,   505,   505,   161,    29,   415,     6,     4,     6,     7,
      99,   506,   505,    77,   505,    10,    11,   468,   485,     8,
     505,    10,    11,   416,   505,    99,     6,    77,   506,    59,
       6,   161,   506,   505,    77,   505,   161
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
	if (parserData->tempStr != "petabyte" && parserData->tempStr != "terabyte" &&
	    parserData->tempStr != "gigabyte" && parserData->tempStr != "megabyte" && 
	    parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
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

  case 178:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 179:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 180:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 181:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 182:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 183:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	;}
    break;

  case 184:

    {osresult->setCurrentState( (yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 187:

    {osresult->setCurrentJobCount( (yyvsp[(3) - (4)].ival)); /* free($3); */  parserData->errorText = NULL;;}
    break;

  case 190:

    {osresult->setTotalJobsSoFar( (yyvsp[(3) - (4)].ival)); /* free($3); */  parserData->errorText = NULL;;}
    break;

  case 193:

    {osresult->setTimeServiceStarted( (yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 196:

    {osresult->setServiceUtilization( parserData->tempVal);  parserData->errorText = NULL;;}
    break;

  case 199:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 201:

    {	osresult->setNumberOfOtherServiceResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 209:

    {	if (!parserData->serviceOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->serviceOtherResultNamePresent = false;
	parserData->serviceOtherResultValuePresent = false;
	parserData->serviceOtherResultDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 210:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 213:

    {	if (parserData->serviceOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->serviceOtherResultNamePresent = true;
		osresult->setServiceOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 214:

    {	if (parserData->serviceOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->serviceOtherResultValuePresent = true;
		osresult->setServiceOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 215:

    {	if (parserData->serviceOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->serviceOtherResultDescriptionPresent = true;
		osresult->setServiceOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 216:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 217:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 218:

    {parserData->tempStr = "";}
    break;

  case 219:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 220:

    {parserData->tempStr = "";;}
    break;

  case 228:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 229:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 230:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 231:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 232:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 233:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 238:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	;}
    break;

  case 239:

    {osresult->setJobStatus( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 242:

    {osresult->setJobSubmitTime( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 245:

    {osresult->setScheduledStartTime( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 248:

    {osresult->setActualStartTime( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 251:

    {osresult->setJobEndTime( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 255:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
;}
    break;

  case 267:

    {parserData->timeType = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 269:

    {parserData->timeCategory = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 271:

    {parserData->timeUnit = (yyvsp[(2) - (3)].sval);   free((yyvsp[(2) - (3)].sval));;}
    break;

  case 273:

    {parserData->timeDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 279:

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

  case 281:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 282:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 284:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
	;}
    break;

  case 289:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "petabyte" && parserData->tempStr != "terabyte" &&
	    parserData->tempStr != "gigabyte" && parserData->tempStr != "megabyte" && 
	    parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedDiskSpace unit not recognized");
	osresult->setUsedDiskSpaceUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 290:

    {	osresult->setUsedDiskSpaceDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 292:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 293:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 295:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
	;}
    break;

  case 300:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "usedMemory unit not recognized");
	osresult->setUsedMemoryUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 301:

    {	osresult->setUsedMemoryDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 303:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 304:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 306:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
	;}
    break;

  case 311:

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

  case 312:

    {	osresult->setUsedCPUSpeedDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 314:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 315:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 317:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
	;}
    break;

  case 320:

    {	osresult->setUsedCPUNumberDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 322:

    {osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 323:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 325:

    {	osresult->setNumberOfOtherJobResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 333:

    {	if (!parserData->jobOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->jobOtherResultNamePresent = false;
	parserData->jobOtherResultValuePresent = false;
	parserData->jobOtherResultDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 334:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 337:

    {	if (parserData->jobOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->jobOtherResultNamePresent = true;
		osresult->setJobOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 338:

    {	if (parserData->jobOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->jobOtherResultValuePresent = true;
		osresult->setJobOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 339:

    {	if (parserData->jobOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->jobOtherResultDescriptionPresent = true;
		osresult->setJobOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 340:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 341:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 342:

    {parserData->tempStr = "";}
    break;

  case 343:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 344:

    {parserData->tempStr = "";}
    break;

  case 355:

    {parserData->numberOfSolutions   = (yyvsp[(3) - (3)].ival); osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 356:

    {parserData->numberOfVariables   = (yyvsp[(3) - (3)].ival); osresult->setVariableNumber((yyvsp[(3) - (3)].ival)); ;}
    break;

  case 357:

    {parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 358:

    {parserData->numberOfObjectives  = (yyvsp[(3) - (3)].ival); osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 364:

    {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   ;}
    break;

  case 365:

    {   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
;}
    break;

  case 370:

    {
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
/*  	osresult->optimization->solution[parserData->solutionIdx]->targetObjectiveIdx = $3;*/
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 371:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 376:

    {parserData->statusType = (yyvsp[(2) - (3)].sval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].sval));;}
    break;

  case 377:

    {parserData->statusType = ""; parserData->statusTypePresent = true;;}
    break;

  case 378:

    {parserData->statusDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 379:

    {parserData->statusDescription = "";;}
    break;

  case 380:

    {;}
    break;

  case 381:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element"); 
		parserData->statusTypePresent = false; 
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	;}
    break;

  case 382:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element");
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	;}
    break;

  case 393:

    { std::cout << "parsed <solutionSubstatus type=" << std::endl;
;}
    break;

  case 399:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = $3; */
		osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
	;}
    break;

  case 400:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = "";*/
		osresult->setSolutionMessage(parserData->solutionIdx, "");
	;}
    break;

  case 405:

    {  
	osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
	;}
    break;

  case 411:

    {
  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  ;}
    break;

  case 412:

    {
  	if(parserData->numberOfVar != 0){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  ;}
    break;

  case 413:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 417:

    { parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 418:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->primalVals.push_back( parserData->primalValPair);  
   ;}
    break;

  case 419:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); 
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->primalVals.push_back( parserData->primalValPair); 
  ;}
    break;

  case 421:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
     }
 */  ;}
    break;

  case 423:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 426:

    {/*parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  */
;}
    break;

  case 429:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 431:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
      }
 */  ;}
    break;

  case 433:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 437:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 440:

    {/*	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	*/;}
    break;

  case 441:

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

  case 442:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	;}
    break;

  case 443:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	;}
    break;

  case 450:

    {	
	parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);

//std::cout << "This \<other\> element has " << parserData->otherVarStruct->numberOfVar << " \<var\>" << std::endl;

	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 451:

    {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
;}
    break;

  case 452:

    {parserData->tmpOtherValue=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 453:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 454:

    {
parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 455:

    {
parserData->tmpOtherDescription=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 461:

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

  case 462:

    {//	if(parserData->otherVarStruct->numberOfVar <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	;}
    break;

  case 463:

    {;}
    break;

  case 470:

    {  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 476:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
;}
    break;

  case 478:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 482:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(3) - (4)].ival);   ;}
    break;

  case 483:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].ival);                  
	parserData->objVals.push_back( parserData->objValPair);
;}
    break;

  case 484:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->objVals.push_back( parserData->objValPair);
  ;}
    break;

  case 488:

    {  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	;}
    break;

  case 495:

    {
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
;}
    break;

  case 496:

    {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
;}
    break;

  case 497:

    {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 498:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherObjStruct->name = "";
;}
    break;

  case 499:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 500:

    {
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 503:

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

  case 506:

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

  case 507:

    {//	if(parserData->otherObjStruct->numberOfObj <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of objectives") ;
	;}
    break;

  case 508:

    {;}
    break;

  case 515:

    {  
/*        osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 521:

    {/*
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}*/
 ;}
    break;

  case 523:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 527:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 528:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 		
	;}
    break;

  case 529:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 	
	;}
    break;

  case 541:

    {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
;}
    break;

  case 542:

    {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 543:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherConStruct->name = "";
;}
    break;

  case 544:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 545:

    {
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 551:

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

  case 552:

    {//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	;}
    break;

  case 553:

    {;}
    break;

  case 558:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 559:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 560:

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

  case 564:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 565:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 567:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 573:

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

  case 574:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 575:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 576:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 578:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 581:

    {parserData->kounter++;;}
    break;

  case 582:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 583:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 586:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 588:

    {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
;}
    break;

  case 596:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
;}
    break;

  case 599:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/;}
    break;

  case 605:

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

  case 606:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
*/
;}
    break;

  case 607:

    {
/*	parserData->tmpOtherName=$2; parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
;}
    break;

  case 608:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
;}
    break;

  case 610:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
;}
    break;

  case 614:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/;}
    break;

  case 615:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/;}
    break;

  case 618:

    {/*parserData->itemContent = $2; free($2);*/;}
    break;

  case 620:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 621:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 623:

    { parserData->outStr << (yyvsp[(1) - (1)].sval);    free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 624:

    { parserData->outStr << (yyvsp[(1) - (1)].ival);  /*free($1);*/ ;}
    break;

  case 625:

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


