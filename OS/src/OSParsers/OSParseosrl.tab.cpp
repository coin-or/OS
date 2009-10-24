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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   986

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  477
/* YYNRULES -- Number of rules.  */
#define YYNRULES  745
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1090

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
      26,    28,    30,    32,    34,    38,    40,    41,    44,    46,
      48,    50,    52,    54,    56,    58,    60,    62,    66,    68,
      70,    72,    75,    77,    79,    81,    86,    88,    90,    93,
      95,    99,   101,   104,   108,   110,   112,   113,   116,   118,
     120,   123,   125,   128,   130,   132,   134,   137,   139,   143,
     146,   148,   150,   152,   155,   157,   161,   164,   166,   168,
     170,   173,   175,   179,   182,   184,   186,   188,   191,   193,
     197,   200,   202,   204,   206,   209,   211,   215,   218,   220,
     222,   224,   227,   229,   233,   236,   238,   240,   242,   245,
     247,   251,   255,   257,   262,   264,   266,   269,   271,   275,
     277,   280,   284,   286,   288,   289,   292,   294,   296,   298,
     301,   303,   304,   307,   312,   313,   316,   318,   320,   322,
     324,   326,   328,   331,   333,   335,   337,   340,   342,   346,
     350,   352,   354,   355,   358,   360,   362,   366,   368,   370,
     374,   376,   378,   379,   382,   384,   386,   390,   392,   394,
     398,   400,   402,   403,   406,   408,   410,   414,   416,   418,
     422,   424,   425,   427,   431,   433,   437,   439,   444,   446,
     448,   451,   453,   457,   459,   462,   466,   468,   470,   471,
     474,   476,   478,   480,   483,   485,   486,   489,   494,   495,
     498,   500,   502,   504,   506,   508,   510,   513,   515,   517,
     519,   522,   524,   528,   531,   533,   535,   537,   540,   542,
     546,   549,   551,   553,   555,   558,   560,   564,   567,   569,
     571,   573,   576,   578,   582,   585,   587,   589,   591,   594,
     596,   600,   604,   606,   611,   613,   615,   618,   620,   624,
     626,   629,   633,   635,   637,   638,   641,   643,   645,   647,
     650,   652,   653,   656,   661,   662,   665,   667,   669,   671,
     673,   675,   677,   679,   681,   683,   685,   687,   690,   692,
     694,   696,   699,   701,   705,   708,   710,   712,   714,   717,
     719,   723,   726,   728,   730,   732,   735,   737,   741,   744,
     746,   748,   750,   753,   755,   759,   762,   764,   766,   768,
     771,   773,   777,   781,   783,   788,   790,   792,   795,   797,
     801,   803,   806,   810,   812,   813,   816,   818,   820,   822,
     824,   826,   828,   831,   833,   837,   839,   841,   845,   847,
     849,   850,   853,   855,   857,   861,   863,   865,   869,   871,
     873,   874,   877,   879,   881,   885,   887,   889,   893,   895,
     897,   898,   901,   903,   905,   909,   911,   913,   917,   919,
     920,   922,   926,   928,   932,   934,   939,   941,   943,   946,
     948,   952,   954,   957,   961,   963,   965,   966,   969,   971,
     973,   975,   978,   980,   981,   985,   987,   989,   990,   993,
     995,   997,   999,  1001,  1006,  1011,  1016,  1021,  1023,  1025,
    1028,  1030,  1035,  1037,  1040,  1044,  1046,  1048,  1049,  1052,
    1054,  1056,  1061,  1065,  1074,  1078,  1080,  1082,  1084,  1087,
    1089,  1091,  1093,  1098,  1100,  1102,  1105,  1107,  1111,  1113,
    1116,  1120,  1122,  1124,  1125,  1128,  1130,  1132,  1135,  1137,
    1138,  1141,  1143,  1145,  1147,  1150,  1152,  1156,  1157,  1161,
    1163,  1164,  1169,  1171,  1173,  1175,  1182,  1183,  1187,  1189,
    1194,  1196,  1198,  1201,  1203,  1207,  1209,  1212,  1218,  1220,
    1225,  1227,  1229,  1230,  1234,  1236,  1241,  1243,  1245,  1248,
    1250,  1254,  1256,  1259,  1265,  1267,  1272,  1273,  1277,  1279,
    1284,  1286,  1288,  1291,  1293,  1297,  1299,  1302,  1308,  1310,
    1315,  1316,  1319,  1323,  1325,  1327,  1328,  1331,  1333,  1335,
    1337,  1339,  1344,  1346,  1348,  1351,  1353,  1357,  1359,  1362,
    1366,  1368,  1373,  1375,  1377,  1380,  1382,  1386,  1387,  1391,
    1393,  1394,  1399,  1401,  1403,  1405,  1410,  1411,  1415,  1417,
    1422,  1424,  1426,  1429,  1431,  1435,  1437,  1440,  1446,  1448,
    1449,  1454,  1456,  1458,  1459,  1462,  1466,  1468,  1470,  1471,
    1474,  1476,  1478,  1480,  1482,  1487,  1489,  1491,  1494,  1496,
    1500,  1502,  1505,  1509,  1511,  1516,  1518,  1520,  1523,  1525,
    1529,  1530,  1534,  1536,  1537,  1542,  1544,  1546,  1548,  1553,
    1554,  1558,  1560,  1565,  1567,  1569,  1572,  1574,  1578,  1580,
    1583,  1589,  1591,  1596,  1598,  1600,  1601,  1604,  1608,  1610,
    1612,  1613,  1616,  1618,  1620,  1622,  1624,  1629,  1631,  1633,
    1636,  1638,  1642,  1644,  1647,  1651,  1653,  1658,  1660,  1662,
    1665,  1667,  1671,  1672,  1676,  1678,  1683,  1685,  1687,  1690,
    1692,  1696,  1698,  1701,  1705,  1707,  1709,  1710,  1713,  1715,
    1717,  1719,  1721,  1726,  1728,  1730,  1733,  1735,  1739,  1741,
    1744,  1746,  1748,  1750,  1752,  1754,  1758,  1759,  1763,  1765,
    1770,  1772,  1774,  1777,  1779,  1783,  1785,  1788,  1792,  1794,
    1796,  1797,  1800,  1802,  1804,  1806,  1808,  1813,  1815,  1817,
    1820,  1822,  1826,  1828,  1831,  1833,  1835,  1837,  1839,  1841,
    1845,  1848,  1850,  1853,  1855,  1858,  1860,  1863,  1865,  1868,
    1870,  1873,  1875,  1878,  1880,  1883,  1885,  1888,  1890,  1893,
    1895,  1898,  1900,  1903,  1905,  1907,  1909,  1912,  1914,  1916,
    1918,  1920,  1922,  1924,  1926,  1927
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   173,    -1,    44,    -1,    -1,
      46,    -1,    10,   174,    47,    -1,   175,   247,   294,   335,
     417,    -1,    -1,   176,   177,    -1,    48,    -1,   178,    -1,
     179,    -1,    11,    -1,    10,   180,    49,    -1,   181,    -1,
      -1,   181,   182,    -1,   183,    -1,   199,    -1,   204,    -1,
     209,    -1,   214,    -1,   219,    -1,   224,    -1,   229,    -1,
     234,    -1,   184,   185,   189,    -1,    88,    -1,   186,    -1,
     187,    -1,   186,   187,    -1,   632,    -1,   626,    -1,   188,
      -1,    24,     8,     6,     8,    -1,   190,    -1,   191,    -1,
      10,    89,    -1,    11,    -1,    10,   192,    89,    -1,   193,
      -1,   192,   193,    -1,   194,   195,   198,    -1,   134,    -1,
     196,    -1,    -1,   196,   197,    -1,   629,    -1,   626,    -1,
      10,   135,    -1,    11,    -1,   200,   201,    -1,    96,    -1,
     202,    -1,   203,    -1,    10,    97,    -1,    11,    -1,    10,
       4,    97,    -1,   205,   206,    -1,   120,    -1,   207,    -1,
     208,    -1,    10,   121,    -1,    11,    -1,    10,     4,   121,
      -1,   210,   211,    -1,   118,    -1,   212,    -1,   213,    -1,
      10,   119,    -1,    11,    -1,    10,     4,   119,    -1,   215,
     216,    -1,    92,    -1,   217,    -1,   218,    -1,    10,    93,
      -1,    11,    -1,    10,     4,    93,    -1,   220,   221,    -1,
      94,    -1,   222,    -1,   223,    -1,    10,    95,    -1,    11,
      -1,    10,     4,    95,    -1,   225,   226,    -1,   126,    -1,
     227,    -1,   228,    -1,    10,   127,    -1,    11,    -1,    10,
       4,   127,    -1,   230,   231,    -1,   142,    -1,   232,    -1,
     233,    -1,    10,   143,    -1,    11,    -1,    10,     4,   143,
      -1,   235,   236,   237,    -1,   108,    -1,    19,   642,     6,
     642,    -1,   238,    -1,   239,    -1,    10,   109,    -1,    11,
      -1,    10,   240,   109,    -1,   241,    -1,   240,   241,    -1,
     242,   243,   246,    -1,   106,    -1,   244,    -1,    -1,   244,
     245,    -1,   629,    -1,   638,    -1,   626,    -1,    10,   107,
      -1,    11,    -1,    -1,    50,    11,    -1,    50,    10,   248,
      51,    -1,    -1,   248,   249,    -1,   250,    -1,   255,    -1,
     262,    -1,   269,    -1,   276,    -1,   281,    -1,   251,   252,
      -1,   136,    -1,   253,    -1,   254,    -1,    10,   137,    -1,
      11,    -1,    10,     4,   137,    -1,   256,   257,   260,    -1,
      68,    -1,   258,    -1,    -1,   258,   259,    -1,   635,    -1,
     626,    -1,    10,   261,    69,    -1,     6,    -1,     7,    -1,
     263,   264,   267,    -1,    70,    -1,   265,    -1,    -1,   265,
     266,    -1,   635,    -1,   626,    -1,    10,   268,    71,    -1,
       6,    -1,     7,    -1,   270,   271,   274,    -1,    66,    -1,
     272,    -1,    -1,   272,   273,    -1,   635,    -1,   626,    -1,
      10,   275,    67,    -1,     6,    -1,     7,    -1,   277,   278,
     279,    -1,    64,    -1,    -1,   626,    -1,    10,   280,    65,
      -1,     6,    -1,   282,   283,   284,    -1,   108,    -1,    19,
     642,     6,   642,    -1,   285,    -1,   286,    -1,    10,   109,
      -1,    11,    -1,    10,   287,   109,    -1,   288,    -1,   287,
     288,    -1,   289,   290,   293,    -1,   106,    -1,   291,    -1,
      -1,   291,   292,    -1,   629,    -1,   638,    -1,   626,    -1,
      10,   107,    -1,    11,    -1,    -1,    52,    11,    -1,    52,
      10,   295,    53,    -1,    -1,   295,   296,    -1,   297,    -1,
     302,    -1,   307,    -1,   312,    -1,   317,    -1,   322,    -1,
     298,   299,    -1,    82,    -1,   300,    -1,   301,    -1,    10,
      83,    -1,    11,    -1,    10,     4,    83,    -1,   303,   304,
      -1,    80,    -1,   305,    -1,   306,    -1,    10,    81,    -1,
      11,    -1,    10,     6,    81,    -1,   308,   309,    -1,   146,
      -1,   310,    -1,   311,    -1,    10,   147,    -1,    11,    -1,
      10,     6,   147,    -1,   313,   314,    -1,   140,    -1,   315,
      -1,   316,    -1,    10,   141,    -1,    11,    -1,    10,     4,
     141,    -1,   318,   319,    -1,   122,    -1,   320,    -1,   321,
      -1,    10,   123,    -1,    11,    -1,    10,   641,   123,    -1,
     323,   324,   325,    -1,   108,    -1,    19,   642,     6,   642,
      -1,   326,    -1,   327,    -1,    10,   109,    -1,    11,    -1,
      10,   328,   109,    -1,   329,    -1,   328,   329,    -1,   330,
     331,   334,    -1,   106,    -1,   332,    -1,    -1,   332,   333,
      -1,   629,    -1,   638,    -1,   626,    -1,    10,   107,    -1,
      11,    -1,    -1,    54,    11,    -1,    54,    10,   336,    55,
      -1,    -1,   336,   337,    -1,   338,    -1,   343,    -1,   348,
      -1,   353,    -1,   358,    -1,   363,    -1,   378,    -1,   385,
      -1,   392,    -1,   399,    -1,   404,    -1,   339,   340,    -1,
     130,    -1,   341,    -1,   342,    -1,    10,   131,    -1,    11,
      -1,    10,     4,   131,    -1,   344,   345,    -1,   132,    -1,
     346,    -1,   347,    -1,    10,   133,    -1,    11,    -1,    10,
       4,   133,    -1,   349,   350,    -1,   116,    -1,   351,    -1,
     352,    -1,    10,   117,    -1,    11,    -1,    10,     4,   117,
      -1,   354,   355,    -1,    62,    -1,   356,    -1,   357,    -1,
      10,    63,    -1,    11,    -1,    10,     4,    63,    -1,   359,
     360,    -1,    86,    -1,   361,    -1,   362,    -1,    10,    87,
      -1,    11,    -1,    10,     4,    87,    -1,   364,   365,   366,
      -1,   144,    -1,    25,     8,     6,     8,    -1,   367,    -1,
     368,    -1,    10,   145,    -1,    11,    -1,    10,   369,   145,
      -1,   370,    -1,   369,   370,    -1,   371,   372,   374,    -1,
     138,    -1,    -1,   372,   373,    -1,   635,    -1,   632,    -1,
     623,    -1,   626,    -1,   375,    -1,   376,    -1,    10,   139,
      -1,    11,    -1,    10,   377,   139,    -1,     7,    -1,     6,
      -1,   379,   380,   383,    -1,   152,    -1,   381,    -1,    -1,
     381,   382,    -1,   635,    -1,   626,    -1,    10,   384,   153,
      -1,     6,    -1,     7,    -1,   386,   387,   390,    -1,   154,
      -1,   388,    -1,    -1,   388,   389,    -1,   635,    -1,   626,
      -1,    10,   391,   155,    -1,     6,    -1,     7,    -1,   393,
     394,   397,    -1,   150,    -1,   395,    -1,    -1,   395,   396,
      -1,   635,    -1,   626,    -1,    10,   398,   151,    -1,     6,
      -1,     7,    -1,   400,   401,   402,    -1,   148,    -1,    -1,
     626,    -1,    10,   403,   149,    -1,     6,    -1,   405,   406,
     407,    -1,   108,    -1,    19,   642,     6,   642,    -1,   408,
      -1,   409,    -1,    10,   109,    -1,    11,    -1,    10,   410,
     109,    -1,   411,    -1,   410,   411,    -1,   412,   413,   416,
      -1,   106,    -1,   414,    -1,    -1,   414,   415,    -1,   629,
      -1,   638,    -1,   626,    -1,    10,   107,    -1,    11,    -1,
      -1,   418,   419,   426,    -1,    56,    -1,   420,    -1,    -1,
     420,   421,    -1,   422,    -1,   423,    -1,   424,    -1,   425,
      -1,    22,   642,     6,   642,    -1,    27,   642,     6,   642,
      -1,    13,   642,     6,   642,    -1,    16,   642,     6,   642,
      -1,   427,    -1,   428,    -1,    10,    57,    -1,    11,    -1,
      10,   429,   602,    57,    -1,   430,    -1,   429,   430,    -1,
     431,   432,   437,    -1,   124,    -1,   433,    -1,    -1,   433,
     434,    -1,   435,    -1,   436,    -1,    28,   642,     6,   642,
      -1,    42,     3,   642,    -1,    10,   438,   454,   459,   513,
     547,   581,   125,    -1,   439,   440,   444,    -1,   130,    -1,
     441,    -1,   442,    -1,   441,   442,    -1,   632,    -1,   626,
      -1,   443,    -1,    24,     8,     6,     8,    -1,   445,    -1,
     446,    -1,    10,   131,    -1,    11,    -1,    10,   447,   131,
      -1,   448,    -1,   447,   448,    -1,   449,   450,   453,    -1,
     134,    -1,   451,    -1,    -1,   451,   452,    -1,   632,    -1,
     626,    -1,    10,   135,    -1,    11,    -1,    -1,   455,   456,
      -1,    96,    -1,   457,    -1,   458,    -1,    10,    97,    -1,
      11,    -1,    10,     4,    97,    -1,    -1,   460,   461,   462,
      -1,   162,    -1,    -1,    21,   642,     6,   642,    -1,   463,
      -1,   464,    -1,    11,    -1,    10,   465,   476,   486,   496,
     163,    -1,    -1,   466,   467,   468,    -1,   156,    -1,    26,
     642,     6,   642,    -1,   469,    -1,   470,    -1,    10,   157,
      -1,    11,    -1,    10,   471,   157,    -1,   472,    -1,   471,
     472,    -1,   473,   474,    10,   475,   161,    -1,   160,    -1,
      29,   642,     6,   642,    -1,     6,    -1,     7,    -1,    -1,
     477,   478,   479,    -1,   158,    -1,    26,   642,     6,   642,
      -1,   480,    -1,   481,    -1,    10,   159,    -1,    11,    -1,
      10,   482,   159,    -1,   483,    -1,   482,   483,    -1,   484,
     485,    10,     4,   161,    -1,   160,    -1,    29,   642,     6,
     642,    -1,    -1,   487,   488,   489,    -1,    72,    -1,    26,
     642,     6,   642,    -1,   490,    -1,   491,    -1,    10,    73,
      -1,    11,    -1,    10,   492,    73,    -1,   493,    -1,   492,
     493,    -1,   494,   495,    10,     4,   161,    -1,   160,    -1,
      29,   642,     6,   642,    -1,    -1,   496,   497,    -1,   498,
     499,   503,    -1,   106,    -1,   500,    -1,    -1,   500,   501,
      -1,   502,    -1,   638,    -1,   629,    -1,   626,    -1,    26,
     642,     6,   642,    -1,   504,    -1,   505,    -1,    10,   107,
      -1,    11,    -1,    10,   506,   107,    -1,   507,    -1,   506,
     507,    -1,   508,   509,   510,    -1,   160,    -1,    29,   642,
       6,   642,    -1,   511,    -1,   512,    -1,    10,   161,    -1,
      11,    -1,    10,   643,   161,    -1,    -1,   514,   515,   516,
      -1,   100,    -1,    -1,    18,   642,     6,   642,    -1,   517,
      -1,   518,    -1,    11,    -1,    10,   519,   530,   101,    -1,
      -1,   520,   521,   522,    -1,   156,    -1,    15,   642,     6,
     642,    -1,   523,    -1,   524,    -1,    10,   157,    -1,    11,
      -1,    10,   525,   157,    -1,   526,    -1,   525,   526,    -1,
     527,   528,    10,   529,    99,    -1,    98,    -1,    -1,    29,
     642,     6,   642,    -1,     6,    -1,     7,    -1,    -1,   530,
     531,    -1,   532,   533,   537,    -1,   106,    -1,   534,    -1,
      -1,   534,   535,    -1,   536,    -1,   638,    -1,   629,    -1,
     626,    -1,    15,   642,     6,   642,    -1,   538,    -1,   539,
      -1,    10,   107,    -1,    11,    -1,    10,   540,   107,    -1,
     541,    -1,   540,   541,    -1,   542,   543,   544,    -1,    98,
      -1,    29,   642,     6,   642,    -1,   545,    -1,   546,    -1,
      10,    99,    -1,    11,    -1,    10,   643,    99,    -1,    -1,
     548,   549,   550,    -1,    78,    -1,    -1,    17,   642,     6,
     642,    -1,   551,    -1,   552,    -1,    11,    -1,    10,   553,
     564,    79,    -1,    -1,   554,   555,   556,    -1,    84,    -1,
      12,   642,     6,   642,    -1,   557,    -1,   558,    -1,    10,
     157,    -1,    11,    -1,    10,   559,    85,    -1,   560,    -1,
     559,   560,    -1,   561,   562,    10,   563,    77,    -1,    76,
      -1,    29,   642,     6,   642,    -1,     6,    -1,     7,    -1,
      -1,   564,   565,    -1,   566,   567,   571,    -1,   106,    -1,
     568,    -1,    -1,   568,   569,    -1,   570,    -1,   638,    -1,
     629,    -1,   626,    -1,    12,   642,     6,   642,    -1,   572,
      -1,   573,    -1,    10,   107,    -1,    11,    -1,    10,   574,
     107,    -1,   575,    -1,   574,   575,    -1,   576,   577,   578,
      -1,    76,    -1,    29,   642,     6,   642,    -1,   579,    -1,
     580,    -1,    10,    77,    -1,    11,    -1,    10,   643,    77,
      -1,    -1,   582,   583,   584,    -1,   112,    -1,    20,   642,
       6,   642,    -1,   585,    -1,   586,    -1,    10,   113,    -1,
      11,    -1,    10,   587,   113,    -1,   588,    -1,   587,   588,
      -1,   589,   590,   594,    -1,   110,    -1,   591,    -1,    -1,
     591,   592,    -1,   629,    -1,   623,    -1,   626,    -1,   593,
      -1,    14,     8,     6,     8,    -1,   595,    -1,   596,    -1,
      10,   111,    -1,    11,    -1,    10,   597,   111,    -1,   598,
      -1,   597,   598,    -1,   599,    -1,   600,    -1,   601,    -1,
      60,    -1,    61,    -1,    58,     5,    59,    -1,    -1,   603,
     604,   605,    -1,   114,    -1,    23,   642,     6,   642,    -1,
     606,    -1,   607,    -1,    10,   115,    -1,    11,    -1,    10,
     608,   115,    -1,   609,    -1,   608,   609,    -1,   610,   611,
     615,    -1,   128,    -1,   612,    -1,    -1,   612,   613,    -1,
     614,    -1,   629,    -1,   623,    -1,   626,    -1,    14,     8,
       6,     8,    -1,   616,    -1,   617,    -1,    10,   129,    -1,
      11,    -1,    10,   618,   129,    -1,   619,    -1,   618,   619,
      -1,   620,    -1,   621,    -1,   622,    -1,    60,    -1,    61,
      -1,    58,     5,    59,    -1,   624,   625,    -1,    30,    -1,
       3,   642,    -1,   642,    -1,   627,   628,    -1,    32,    -1,
       3,   642,    -1,   642,    -1,   630,   631,    -1,    34,    -1,
       3,   642,    -1,   642,    -1,   633,   634,    -1,    36,    -1,
       3,   642,    -1,   642,    -1,   636,   637,    -1,    38,    -1,
       3,   642,    -1,   642,    -1,   639,   640,    -1,    40,    -1,
       3,   642,    -1,   642,    -1,     6,    -1,     7,    -1,   645,
       8,    -1,     4,    -1,     6,    -1,     7,    -1,   165,    -1,
     166,    -1,   167,    -1,   168,    -1,    -1,   645,   644,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   162,   162,   164,   166,   166,   168,   170,   173,   173,
     175,   177,   177,   179,   181,   183,   185,   185,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   199,   201,   214,
     220,   220,   223,   231,   235,   238,   249,   253,   258,   258,
     260,   262,   262,   264,   268,   275,   280,   280,   283,   287,
     292,   292,   295,   297,   303,   303,   305,   305,   307,   310,
     312,   318,   318,   320,   320,   322,   325,   327,   333,   333,
     335,   335,   337,   340,   342,   348,   348,   350,   350,   352,
     355,   357,   363,   363,   365,   365,   367,   370,   372,   378,
     378,   380,   380,   382,   385,   387,   393,   393,   395,   395,
     397,   400,   402,   408,   417,   421,   426,   426,   428,   430,
     430,   432,   436,   444,   449,   449,   452,   457,   461,   467,
     467,   471,   471,   472,   474,   474,   477,   478,   479,   480,
     481,   482,   485,   487,   493,   493,   495,   495,   497,   500,
     502,   510,   512,   512,   515,   527,   532,   535,   536,   539,
     541,   549,   551,   551,   554,   566,   571,   574,   575,   578,
     580,   588,   590,   590,   593,   609,   614,   617,   618,   621,
     623,   630,   631,   636,   639,   642,   644,   650,   659,   663,
     668,   668,   670,   672,   672,   674,   678,   686,   691,   691,
     694,   699,   703,   709,   709,   713,   713,   714,   716,   716,
     719,   720,   721,   722,   723,   724,   727,   729,   735,   735,
     737,   737,   739,   751,   753,   759,   759,   761,   761,   763,
     766,   768,   774,   774,   776,   776,   778,   781,   783,   789,
     789,   791,   791,   793,   796,   798,   804,   804,   806,   806,
     808,   811,   813,   819,   828,   832,   837,   837,   839,   841,
     841,   843,   847,   855,   860,   860,   863,   868,   872,   878,
     878,   881,   881,   882,   884,   884,   887,   888,   889,   890,
     891,   892,   893,   894,   895,   896,   897,   900,   902,   908,
     908,   910,   910,   912,   924,   926,   932,   932,   934,   934,
     936,   939,   941,   947,   947,   949,   949,   951,   954,   956,
     962,   962,   964,   964,   966,   969,   971,   977,   977,   979,
     979,   981,   984,   986,   992,   999,  1003,  1008,  1008,  1010,
    1012,  1012,  1014,  1016,  1029,  1029,  1032,  1044,  1050,  1060,
    1063,  1063,  1065,  1065,  1067,  1078,  1079,  1082,  1084,  1092,
    1094,  1094,  1097,  1109,  1114,  1117,  1118,  1121,  1123,  1131,
    1133,  1133,  1136,  1148,  1153,  1156,  1157,  1160,  1162,  1172,
    1174,  1174,  1177,  1193,  1198,  1201,  1202,  1205,  1207,  1215,
    1216,  1221,  1224,  1228,  1230,  1236,  1245,  1249,  1254,  1254,
    1256,  1258,  1258,  1260,  1264,  1272,  1277,  1277,  1280,  1285,
    1289,  1295,  1295,  1298,  1298,  1300,  1307,  1312,  1312,  1315,
    1316,  1317,  1318,  1321,  1331,  1339,  1347,  1356,  1360,  1365,
    1365,  1367,  1369,  1369,  1371,  1373,  1381,  1383,  1383,  1385,
    1385,  1387,  1395,  1405,  1411,  1413,  1420,  1425,  1425,  1428,
    1442,  1445,  1447,  1458,  1462,  1468,  1468,  1470,  1472,  1472,
    1474,  1477,  1484,  1489,  1489,  1492,  1501,  1507,  1507,  1510,
    1510,  1512,  1514,  1514,  1516,  1516,  1518,  1523,  1523,  1525,
    1528,  1529,  1537,  1537,  1539,  1541,  1543,  1543,  1545,  1547,
    1556,  1560,  1566,  1566,  1568,  1570,  1570,  1572,  1578,  1584,
    1587,  1588,  1591,  1591,  1593,  1595,  1604,  1608,  1614,  1614,
    1616,  1618,  1618,  1620,  1627,  1633,  1636,  1636,  1638,  1640,
    1649,  1653,  1659,  1659,  1661,  1663,  1663,  1665,  1678,  1684,
    1687,  1687,  1689,  1695,  1705,  1712,  1712,  1715,  1716,  1721,
    1726,  1732,  1742,  1742,  1744,  1744,  1746,  1748,  1748,  1750,
    1755,  1757,  1762,  1762,  1764,  1764,  1766,  1771,  1771,  1773,
    1779,  1780,  1788,  1788,  1790,  1792,  1794,  1794,  1796,  1798,
    1807,  1811,  1817,  1817,  1819,  1822,  1822,  1824,  1830,  1837,
    1837,  1840,  1841,  1845,  1845,  1847,  1853,  1863,  1871,  1871,
    1874,  1875,  1880,  1885,  1891,  1901,  1901,  1903,  1903,  1905,
    1907,  1907,  1909,  1914,  1916,  1920,  1920,  1922,  1922,  1924,
    1929,  1929,  1931,  1936,  1937,  1945,  1945,  1947,  1949,  1951,
    1951,  1953,  1956,  1965,  1969,  1975,  1975,  1977,  1979,  1979,
    1981,  1987,  1993,  1996,  1997,  2000,  2000,  2002,  2008,  2018,
    2025,  2025,  2028,  2029,  2034,  2039,  2045,  2055,  2055,  2057,
    2057,  2059,  2061,  2061,  2063,  2068,  2070,  2075,  2075,  2077,
    2077,  2079,  2085,  2085,  2087,  2092,  2101,  2105,  2110,  2110,
    2112,  2114,  2114,  2116,  2120,  2129,  2136,  2136,  2139,  2144,
    2149,  2154,  2156,  2167,  2171,  2176,  2176,  2178,  2180,  2180,
    2182,  2187,  2191,  2194,  2194,  2196,  2208,  2208,  2210,  2215,
    2224,  2228,  2233,  2233,  2235,  2237,  2237,  2239,  2243,  2252,
    2259,  2259,  2262,  2263,  2267,  2271,  2277,  2287,  2291,  2296,
    2296,  2298,  2300,  2300,  2302,  2307,  2311,  2313,  2313,  2315,
    2324,  2326,  2333,  2334,  2336,  2338,  2345,  2346,  2348,  2350,
    2357,  2358,  2360,  2362,  2369,  2370,  2372,  2374,  2381,  2382,
    2384,  2386,  2393,  2394,  2398,  2399,  2401,  2404,  2405,  2406,
    2410,  2411,  2412,  2413,  2415,  2416
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
  "generalElementEmpty", "generalElementFilled", "generalElementBody",
  "generalElementList", "generalChild", "generalStatus",
  "generalStatusStart", "generalStatusAttributes", "generalStatusAttList",
  "generalStatusATT", "generalStatusNumberOfATT", "generalStatusContent",
  "generalStatusEmpty", "generalStatusBody", "generalSubstatusArray",
  "generalSubstatus", "generalSubstatusStart",
  "generalSubstatusAttributes", "generalSubstatusAttList",
  "generalSubstatusATT", "generalSubstatusEnd", "generalMessage",
  "generalMessageStart", "generalMessageContent", "generalMessageEmpty",
  "generalMessageBody", "serviceURI", "serviceURIStart",
  "serviceURIContent", "serviceURIEmpty", "serviceURIBody", "serviceName",
  "serviceNameStart", "serviceNameContent", "serviceNameEmpty",
  "serviceNameBody", "instanceName", "instanceNameStart",
  "instanceNameContent", "instanceNameEmpty", "instanceNameBody", "jobID",
  "jobIDStart", "jobIDContent", "jobIDEmpty", "jobIDBody", "solverInvoked",
  "solverInvokedStart", "solverInvokedContent", "solverInvokedEmpty",
  "solverInvokedBody", "timeStamp", "timeStampStart", "timeStampContent",
  "timeStampEmpty", "timeStampBody", "generalOtherResults",
  "generalOtherResultsStart", "generalOtherResultsAttributes",
  "generalOtherResultsContent", "generalOtherResultsEmpty",
  "generalOtherResultsBody", "generalOtherResultArray",
  "generalOtherResult", "generalOtherResultStart",
  "generalOtherAttributes", "generalOtherAttList", "generalOtherAtt",
  "generalOtherEnd", "systemElement", "systemContent", "systemChild",
  "systemInformation", "systemInformationStart",
  "systemInformationContent", "systemInformationEmpty",
  "systemInformationBody", "availableDiskSpace", "availableDiskSpaceStart",
  "availableDiskSpaceAttributes", "availableDiskSpaceAttList",
  "availableDiskSpaceAtt", "availableDiskSpaceContent",
  "availableDiskSpaceValue", "availableMemory", "availableMemoryStart",
  "availableMemoryAttributes", "availableMemoryAttList",
  "availableMemoryAtt", "availableMemoryContent", "availableMemoryValue",
  "availableCPUSpeed", "availableCPUSpeedStart",
  "availableCPUSpeedAttributes", "availableCPUSpeedAttList",
  "availableCPUSpeedAtt", "availableCPUSpeedContent",
  "availableCPUSpeedValue", "availableCPUNumber",
  "availableCPUNumberStart", "availableCPUNumberAttributes",
  "availableCPUNumberContent", "availableCPUNumberValue",
  "systemOtherResults", "systemOtherResultsStart",
  "systemOtherResultsAttributes", "systemOtherResultsContent",
  "systemOtherResultsEmpty", "systemOtherResultsBody",
  "systemOtherResultArray", "systemOtherResult", "systemOtherResultStart",
  "systemOtherAttributes", "systemOtherAttList", "systemOtherAtt",
  "systemOtherEnd", "serviceElement", "serviceContent", "serviceChild",
  "currentState", "currentStateStart", "currentStateContent",
  "currentStateEmpty", "currentStateBody", "currentJobCount",
  "currentJobCountStart", "currentJobCountContent", "currentJobCountEmpty",
  "currentJobCountBody", "totalJobsSoFar", "totalJobsSoFarStart",
  "totalJobsSoFarContent", "totalJobsSoFarEmpty", "totalJobsSoFarBody",
  "timeServiceStarted", "timeServiceStartedStart",
  "timeServiceStartedContent", "timeServiceStartedEmpty",
  "timeServiceStartedBody", "serviceUtilization",
  "serviceUtilizationStart", "serviceUtilizationContent",
  "serviceUtilizationEmpty", "serviceUtilizationBody",
  "serviceOtherResults", "serviceOtherResultsStart",
  "serviceOtherResultsAttributes", "serviceOtherResultsContent",
  "serviceOtherResultsEmpty", "serviceOtherResultsBody",
  "serviceOtherResultArray", "serviceOtherResult",
  "serviceOtherResultStart", "serviceOtherAttributes",
  "serviceOtherAttList", "serviceOtherAtt", "serviceOtherEnd",
  "jobElement", "jobContent", "jobChild", "jobStatus", "jobStatusStart",
  "jobStatusContent", "jobStatusEmpty", "jobStatusBody", "submitTime",
  "submitTimeStart", "submitTimeContent", "submitTimeEmpty",
  "submitTimeBody", "scheduledStartTime", "scheduledStartTimeStart",
  "scheduledStartTimeContent", "scheduledStartTimeEmpty",
  "scheduledStartTimeBody", "actualStartTime", "actualStartTimeStart",
  "actualStartTimeContent", "actualStartTimeEmpty", "actualStartTimeBody",
  "endTime", "endTimeStart", "endTimeContent", "endTimeEmpty",
  "endTimeBody", "timingInformation", "timingInformationStart",
  "timingInformationAttributes", "timingInformationContent",
  "timingInformationEmpty", "timingInformationBody", "timeArray", "time",
  "timeStart", "timeAttributes", "timeAtt", "timeContent", "timeEmpty",
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
  "jobOtherResultsContent", "jobOtherResultsEmpty", "jobOtherResultsBody",
  "jobOtherResultArray", "jobOtherResult", "jobOtherResultStart",
  "jobOtherAttributes", "jobOtherAttList", "jobOtherAtt", "jobOtherEnd",
  "optimizationElement", "optimizationStart", "optimizationAttributes",
  "optimizationAttList", "optimizationATT",
  "optimizationNumberOfSolutionsATT", "optimizationNumberOfVariablesATT",
  "optimizationNumberOfConstraintsATT",
  "optimizationNumberOfObjectivesATT", "optimizationContent",
  "optimizationEmpty", "optimizationBody", "solutionArray", "solution",
  "solutionStart", "solutionAttributes", "solutionAttList", "solutionATT",
  "targetObjectiveIdxATT", "weightedObjectivesATT", "solutionContent",
  "solutionStatus", "solutionStatusStart", "solutionStatusAttributes",
  "solutionStatusAttList", "solutionStatusATT",
  "solutionStatusNumberOfATT", "solutionStatusContent",
  "solutionStatusEmpty", "solutionStatusBody", "solutionSubstatusArray",
  "solutionSubstatus", "solutionSubstatusStart",
  "solutionSubstatusAttributes", "solutionSubstatusAttList",
  "solutionSubstatusATT", "solutionSubstatusEnd", "solutionMessage",
  "solutionMessageStart", "solutionMessageContent", "solutionMessageEmpty",
  "solutionMessageBody", "variables", "variablesStart",
  "numberOfOtherVariableResults", "variablesContent", "variablesEmpty",
  "variablesBody", "variableValues", "variableValuesStart",
  "numberOfVarATT", "variableValuesContent", "variableValuesEmpty",
  "variableValuesBody", "varValueArray", "varValue", "varValueStart",
  "varIdxATT", "varVal", "variableValuesString",
  "variableValuesStringStart", "numberOfVarStringATT",
  "variableValuesStringContent", "variableValuesStringEmpty",
  "variableValuesStringBody", "varValueStringArray", "varValueString",
  "varValueStringStart", "varStrIdxATT", "basisStatus", "basisStatusStart",
  "numberOfBasisVarATT", "basisStatusContent", "basisStatusEmpty",
  "basisStatusBody", "basisVarArray", "basisVar", "basisVarStart",
  "basisVarIdxATT", "otherVariableResultsArray", "otherVariableResult",
  "otherVariableResultStart", "otherVariableResultAttributes",
  "otherVariableResultAttList", "otherVariableResultATT",
  "numberOfOtherVariableResultsATT", "otherVariableResultContent",
  "otherVariableResultEmpty", "otherVariableResultBody", "otherVarList",
  "otherVar", "otherVarStart", "otherVarIdxATT", "otherVarContent",
  "otherVarEmpty", "otherVarBody", "objectives", "objectivesStart",
  "numberOfOtherObjectiveResults", "objectivesContent", "objectivesEmpty",
  "objectivesBody", "objectiveValues", "objectiveValuesStart",
  "numberOfObjATT", "objectiveValuesContent", "objectiveValuesEmpty",
  "objectiveValuesBody", "objValueArray", "objValue", "objValueStart",
  "objIdxATT", "objVal", "otherObjectiveResultsArray",
  "otherObjectiveResult", "otherObjectiveResultStart",
  "otherObjectiveResultAttributes", "otherObjectiveResultAttList",
  "otherObjectiveResultATT", "numberOfOtherObjectiveResultsATT",
  "otherObjectiveResultContent", "otherObjectiveResultEmpty",
  "otherObjectiveResultBody", "otherObjList", "otherObj", "otherObjStart",
  "otherObjIdxATT", "otherObjContent", "otherObjEmpty", "otherObjBody",
  "constraints", "constraintsStart", "numberOfOtherConstraintResults",
  "constraintsContent", "constraintsEmpty", "constraintsBody",
  "dualValues", "dualValuesStart", "numberOfConATT", "dualValuesContent",
  "dualValuesEmpty", "dualValuesBody", "dualValueArray", "dualValue",
  "dualValueStart", "conIdxATT", "dualVal", "otherConstraintResultsArray",
  "otherConstraintResult", "otherConstraintResultStart",
  "otherConstraintResultAttributes", "otherConstraintResultAttList",
  "otherConstraintResultATT", "numberOfOtherConstraintResultATT",
  "otherConstraintResultContent", "otherConstraintResultEmpty",
  "otherConstraintResultBody", "otherConList", "otherCon", "otherConStart",
  "otherConIdxATT", "otherConContent", "otherConEmpty", "otherConBody",
  "otherSolutionResults", "otherSolutionResultsStart",
  "numberOfOtherSolutionResults", "otherSolutionResultsContent",
  "otherSolutionResultsEmpty", "otherSolutionResultsBody",
  "otherSolutionResultArray", "otherSolutionResult",
  "otherSolutionResultStart", "otherSolutionResultAttributes",
  "otherSolutionResultAttList", "otherSolutionResultAtt",
  "numberOfOtherSolutionResultItems", "otherSolutionResultContent",
  "otherSolutionResultEmpty", "otherSolutionResultBody",
  "otherSolutionResultItemArray", "otherSolutionResultItem",
  "otherSolutionResultItemContent", "otherSolutionResultItemEmpty",
  "otherSolutionResultItemBody", "otherSolverOutput",
  "otherSolverOutputStart", "numberOfSolverOutputsATT",
  "otherSolverOutputContent", "otherSolverOutputEmpty",
  "otherSolverOutputBody", "solverOutputArray", "solverOutput",
  "solverOutputStart", "solverOutputAttributes", "solverOutputAttList",
  "solverOutputAtt", "numberOfSolverOutputItems", "solverOutputContent",
  "solverOutputEmpty", "solverOutputBody", "solverOutputItemArray",
  "solverOutputItem", "solverOutputItemContent", "solverOutputItemEmpty",
  "solverOutputItemBody", "categoryAttribute",
  "categoryAttributeIdentifier", "categoryAttributeValue",
  "descriptionAttribute", "descriptionAttributeIdentifier",
  "descriptionAttributeValue", "nameAttribute", "nameAttributeIdentifier",
  "nameAttributeValue", "typeAttribute", "typeAttributeIdentifier",
  "typeAttributeValue", "unitAttribute", "unitAttributeIdentifier",
  "unitAttributeValue", "valueAttribute", "valueAttributeIdentifier",
  "valueAttributeValue", "aNumber", "quote", "ElementValue",
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
       0,   169,   170,   171,   172,   172,   173,   174,   175,   175,
     176,   177,   177,   178,   179,   180,   181,   181,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   183,   184,   185,
     186,   186,   187,   187,   187,   188,   189,   189,   190,   190,
     191,   192,   192,   193,   194,   195,   196,   196,   197,   197,
     198,   198,   199,   200,   201,   201,   202,   202,   203,   204,
     205,   206,   206,   207,   207,   208,   209,   210,   211,   211,
     212,   212,   213,   214,   215,   216,   216,   217,   217,   218,
     219,   220,   221,   221,   222,   222,   223,   224,   225,   226,
     226,   227,   227,   228,   229,   230,   231,   231,   232,   232,
     233,   234,   235,   236,   237,   237,   238,   238,   239,   240,
     240,   241,   242,   243,   244,   244,   245,   245,   245,   246,
     246,   247,   247,   247,   248,   248,   249,   249,   249,   249,
     249,   249,   250,   251,   252,   252,   253,   253,   254,   255,
     256,   257,   258,   258,   259,   259,   260,   261,   261,   262,
     263,   264,   265,   265,   266,   266,   267,   268,   268,   269,
     270,   271,   272,   272,   273,   273,   274,   275,   275,   276,
     277,   278,   278,   279,   280,   281,   282,   283,   284,   284,
     285,   285,   286,   287,   287,   288,   289,   290,   291,   291,
     292,   292,   292,   293,   293,   294,   294,   294,   295,   295,
     296,   296,   296,   296,   296,   296,   297,   298,   299,   299,
     300,   300,   301,   302,   303,   304,   304,   305,   305,   306,
     307,   308,   309,   309,   310,   310,   311,   312,   313,   314,
     314,   315,   315,   316,   317,   318,   319,   319,   320,   320,
     321,   322,   323,   324,   325,   325,   326,   326,   327,   328,
     328,   329,   330,   331,   332,   332,   333,   333,   333,   334,
     334,   335,   335,   335,   336,   336,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   338,   339,   340,
     340,   341,   341,   342,   343,   344,   345,   345,   346,   346,
     347,   348,   349,   350,   350,   351,   351,   352,   353,   354,
     355,   355,   356,   356,   357,   358,   359,   360,   360,   361,
     361,   362,   363,   364,   365,   366,   366,   367,   367,   368,
     369,   369,   370,   371,   372,   372,   373,   373,   373,   373,
     374,   374,   375,   375,   376,   377,   377,   378,   379,   380,
     381,   381,   382,   382,   383,   384,   384,   385,   386,   387,
     388,   388,   389,   389,   390,   391,   391,   392,   393,   394,
     395,   395,   396,   396,   397,   398,   398,   399,   400,   401,
     401,   402,   403,   404,   405,   406,   407,   407,   408,   408,
     409,   410,   410,   411,   412,   413,   414,   414,   415,   415,
     415,   416,   416,   417,   417,   418,   419,   420,   420,   421,
     421,   421,   421,   422,   423,   424,   425,   426,   426,   427,
     427,   428,   429,   429,   430,   431,   432,   433,   433,   434,
     434,   435,   436,   437,   438,   439,   440,   441,   441,   442,
     442,   442,   443,   444,   444,   445,   445,   446,   447,   447,
     448,   449,   450,   451,   451,   452,   452,   453,   453,   454,
     454,   455,   456,   456,   457,   457,   458,   459,   459,   460,
     461,   461,   462,   462,   463,   464,   465,   465,   466,   467,
     468,   468,   469,   469,   470,   471,   471,   472,   473,   474,
     475,   475,   476,   476,   477,   478,   479,   479,   480,   480,
     481,   482,   482,   483,   484,   485,   486,   486,   487,   488,
     489,   489,   490,   490,   491,   492,   492,   493,   494,   495,
     496,   496,   497,   498,   499,   500,   500,   501,   501,   501,
     501,   502,   503,   503,   504,   504,   505,   506,   506,   507,
     508,   509,   510,   510,   511,   511,   512,   513,   513,   514,
     515,   515,   516,   516,   517,   518,   519,   519,   520,   521,
     522,   522,   523,   523,   524,   525,   525,   526,   527,   528,
     528,   529,   529,   530,   530,   531,   532,   533,   534,   534,
     535,   535,   535,   535,   536,   537,   537,   538,   538,   539,
     540,   540,   541,   542,   543,   544,   544,   545,   545,   546,
     547,   547,   548,   549,   549,   550,   550,   551,   552,   553,
     553,   554,   555,   556,   556,   557,   557,   558,   559,   559,
     560,   561,   562,   563,   563,   564,   564,   565,   566,   567,
     568,   568,   569,   569,   569,   569,   570,   571,   571,   572,
     572,   573,   574,   574,   575,   576,   577,   578,   578,   579,
     579,   580,   581,   581,   582,   583,   584,   584,   585,   585,
     586,   587,   587,   588,   589,   590,   591,   591,   592,   592,
     592,   592,   593,   594,   594,   595,   595,   596,   597,   597,
     598,   599,   599,   600,   600,   601,   602,   602,   603,   604,
     605,   605,   606,   606,   607,   608,   608,   609,   610,   611,
     612,   612,   613,   613,   613,   613,   614,   615,   615,   616,
     616,   617,   618,   618,   619,   620,   620,   621,   621,   622,
     623,   624,   625,   625,   626,   627,   628,   628,   629,   630,
     631,   631,   632,   633,   634,   634,   635,   636,   637,   637,
     638,   639,   640,   640,   641,   641,   642,   643,   643,   643,
     644,   644,   644,   644,   645,   645
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     0,     1,     3,     5,     0,     2,
       1,     1,     1,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     2,     1,     1,     1,     4,     1,     1,     2,     1,
       3,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       2,     1,     2,     1,     1,     1,     2,     1,     3,     2,
       1,     1,     1,     2,     1,     3,     2,     1,     1,     1,
       2,     1,     3,     2,     1,     1,     1,     2,     1,     3,
       2,     1,     1,     1,     2,     1,     3,     2,     1,     1,
       1,     2,     1,     3,     2,     1,     1,     1,     2,     1,
       3,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     2,
       1,     0,     2,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     2,     1,     3,     3,
       1,     1,     0,     2,     1,     1,     3,     1,     1,     3,
       1,     1,     0,     2,     1,     1,     3,     1,     1,     3,
       1,     1,     0,     2,     1,     1,     3,     1,     1,     3,
       1,     0,     1,     3,     1,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     1,     3,     2,     1,     1,     1,     2,     1,     3,
       2,     1,     1,     1,     2,     1,     3,     2,     1,     1,
       1,     2,     1,     3,     2,     1,     1,     1,     2,     1,
       3,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     2,
       1,     0,     2,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     1,     3,     2,     1,     1,     1,     2,     1,
       3,     2,     1,     1,     1,     2,     1,     3,     2,     1,
       1,     1,     2,     1,     3,     2,     1,     1,     1,     2,
       1,     3,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     3,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     3,     1,     1,
       0,     2,     1,     1,     3,     1,     1,     3,     1,     1,
       0,     2,     1,     1,     3,     1,     1,     3,     1,     1,
       0,     2,     1,     1,     3,     1,     1,     3,     1,     0,
       1,     3,     1,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     4,     4,     4,     4,     1,     1,     2,
       1,     4,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     4,     3,     8,     3,     1,     1,     1,     2,     1,
       1,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     2,     1,     0,
       2,     1,     1,     1,     2,     1,     3,     0,     3,     1,
       0,     4,     1,     1,     1,     6,     0,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     2,     5,     1,     4,
       1,     1,     0,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     2,     5,     1,     4,     0,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     2,     5,     1,     4,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       1,     4,     1,     1,     2,     1,     3,     0,     3,     1,
       0,     4,     1,     1,     1,     4,     0,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     2,     5,     1,     0,
       4,     1,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     3,     1,     4,     1,     1,     2,     1,     3,
       0,     3,     1,     0,     4,     1,     1,     1,     4,     0,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       5,     1,     4,     1,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     4,     1,     1,     2,
       1,     3,     1,     2,     3,     1,     4,     1,     1,     2,
       1,     3,     0,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     1,     1,     3,     0,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     4,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     3,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     3,     0,     4,     1,     5,     0,     8,     2,    10,
       0,   121,     0,     6,     0,   195,    16,    13,     9,    11,
      12,   124,   122,     0,   261,     0,    15,     0,   198,   196,
       0,   393,    14,    28,    74,    81,    53,   102,    67,    60,
      88,    95,    17,    18,     0,    19,     0,    20,     0,    21,
       0,    22,     0,    23,     0,    24,     0,    25,     0,    26,
       0,   123,   170,   160,   140,   150,   176,   133,   125,   126,
       0,   127,   142,   128,   152,   129,   162,   130,   171,   131,
       0,     0,   264,   262,   395,     7,   397,     0,   715,   723,
       0,    29,    30,    34,    33,   744,    32,   744,     0,    57,
      52,    54,    55,     0,    64,    59,    61,    62,     0,    71,
      66,    68,    69,     0,    78,    73,    75,    76,     0,    85,
      80,    82,    83,     0,    92,    87,    89,    90,     0,    99,
      94,    96,    97,   744,     0,     0,   137,   132,   134,   135,
       0,   141,     0,   151,     0,   161,     0,   172,   744,     0,
     197,   214,   207,   242,   235,   228,   221,   199,   200,     0,
     201,     0,   202,     0,   203,     0,   204,     0,   205,     0,
       0,     0,   396,     0,     0,    39,    27,    36,    37,    31,
     744,   714,   717,     0,   744,   722,   725,     0,    56,     0,
      63,     0,    70,     0,    77,     0,    84,     0,    91,     0,
      98,     0,     0,   107,   101,   104,   105,     0,   136,     0,
     139,   727,   143,   145,   144,   744,     0,   149,   153,   155,
     154,     0,   159,   163,   165,   164,     0,   169,     0,     0,
     181,   175,   178,   179,     0,   211,   206,   208,   209,     0,
     218,   213,   215,   216,     0,   225,   220,   222,   223,     0,
     232,   227,   229,   230,     0,   239,   234,   236,   237,   744,
       0,   263,   299,   306,   374,   292,   278,   285,   313,   368,
     358,   338,   348,   265,   266,     0,   267,     0,   268,     0,
     269,     0,   270,     0,   271,     0,   272,   340,   273,   350,
     274,   360,   275,   369,   276,     0,     0,   410,   394,   407,
     408,   744,   744,   744,   744,   398,   399,   400,   401,   402,
       0,    38,    44,     0,    41,    46,   716,   736,   740,   741,
     742,   743,   745,   724,    58,    65,    72,    79,    86,    93,
     100,   744,   112,   106,     0,   109,   114,   138,   147,   148,
       0,   744,   726,   729,   157,   158,     0,   167,   168,     0,
     174,     0,   744,   186,   180,     0,   183,   188,     0,   210,
       0,   217,     0,   224,     0,   231,   734,   735,   238,     0,
       0,     0,   247,   241,   244,   245,     0,   282,   277,   279,
     280,     0,   289,   284,   286,   287,     0,   296,   291,   293,
     294,     0,   303,   298,   300,   301,     0,   310,   305,   307,
     308,     0,     0,     0,   339,     0,   349,     0,   359,     0,
     370,   744,     0,   409,   415,   676,   412,   417,     0,     0,
       0,     0,    35,    40,    42,     0,    45,   103,   108,   110,
       0,   113,   146,   728,   156,   166,   173,   177,   182,   184,
       0,   187,   212,   219,   226,   233,   240,   744,   252,   246,
       0,   249,   254,     0,   281,     0,   288,     0,   295,     0,
     302,     0,   309,     0,     0,   318,   312,   315,   316,     0,
     337,   341,   343,   342,     0,   347,   351,   353,   352,     0,
     357,   361,   363,   362,     0,   367,     0,     0,   379,   373,
     376,   377,   678,   413,     0,     0,     0,   416,   744,   744,
     744,   744,     0,    51,    43,   719,    47,    49,    48,   744,
       0,   120,   111,   731,   115,   118,   116,   117,   744,     0,
     194,   185,   189,   192,   190,   191,   243,   248,   250,     0,
     253,   283,   290,   297,   304,   311,     0,   323,   317,     0,
     320,   324,   345,   346,     0,   355,   356,     0,   365,   366,
       0,   372,     0,   744,   384,   378,     0,   381,   386,   411,
     744,     0,     0,   414,   744,     0,   418,   419,   420,   405,
     406,   403,   404,    50,   744,   718,   721,   119,   744,   730,
     733,   193,     0,   260,   251,   255,   258,   256,   257,   314,
     319,   321,     0,   344,   354,   364,   371,   375,   380,   382,
       0,   385,     0,     0,   683,   677,   680,   681,   425,   449,
       0,     0,   744,   720,   732,   259,     0,   333,   711,   325,
     322,   330,   331,   328,   744,   329,   327,   326,     0,   392,
     383,   387,   390,   388,   389,   744,   682,   688,     0,   685,
     690,   451,   457,     0,     0,     0,   426,   427,   431,   430,
     429,   744,   422,   336,   335,   332,     0,   744,   710,   713,
     391,   679,   684,   686,     0,   689,   459,   537,   460,     0,
     455,   450,   452,   453,     0,     0,   436,   424,   433,   434,
     428,   421,   334,   712,     0,   700,   687,   697,   698,     0,
     691,   692,   694,   695,   693,   539,   590,   540,   744,     0,
       0,   454,     0,   435,   441,     0,   438,   443,     0,   707,
     708,   699,     0,   702,   704,   705,   706,     0,   592,   642,
     593,   744,     0,     0,   466,   464,   458,   462,   463,   456,
     432,   437,   439,     0,   442,     0,   701,   703,     0,   644,
       0,     0,   744,     0,     0,   546,   544,   538,   542,   543,
     744,   468,   482,     0,     0,   448,   440,   444,   446,   445,
     709,   696,   423,   744,     0,     0,   599,   597,   591,   595,
     596,   744,   548,   563,     0,   461,   484,   496,     0,   744,
       0,   447,     0,     0,   649,   643,   646,   647,   744,   601,
     615,     0,   541,     0,   744,     0,   498,   510,     0,   744,
       0,     0,     0,   473,   467,   470,   471,   744,   654,   648,
       0,   651,   656,   594,     0,   744,     0,   545,   566,   564,
     568,     0,     0,   553,   547,   550,   551,     0,   744,     0,
       0,     0,   489,   483,   486,   487,   744,   472,   478,     0,
     475,     0,   645,   650,   652,     0,   655,   598,   618,   616,
     620,     0,     0,   606,   600,   603,   604,     0,   567,   744,
     558,   552,     0,   555,   559,   513,   465,   511,   515,     0,
       0,   503,   497,   500,   501,   744,   488,   494,     0,   491,
       0,   469,   474,   476,   744,     0,     0,   666,   653,   663,
     664,     0,   657,   661,   659,   660,   658,     0,   619,   744,
     611,   605,     0,   608,     0,     0,   578,   565,   575,   576,
     744,   569,   570,   573,   572,   571,   549,   554,   556,   744,
       0,     0,   514,   744,   502,   508,     0,   505,     0,   485,
     490,   492,   744,     0,     0,     0,     0,   673,   674,   665,
       0,   668,   670,   671,   672,     0,     0,   630,   617,   627,
     628,   744,   621,   622,   625,   624,   623,   602,   607,   609,
     744,     0,   583,   577,     0,   580,     0,     0,     0,     0,
       0,   525,   512,   522,   523,   744,   516,   517,   520,   519,
     518,   499,   504,   506,   744,     0,     0,     0,   744,   480,
     481,     0,     0,   667,   669,     0,   635,   629,     0,   632,
       0,     0,     0,     0,   579,   581,   744,     0,   744,   744,
     561,   562,     0,   524,   530,     0,   527,     0,     0,     0,
       0,   744,     0,   479,   477,   675,   662,   631,   633,   744,
       0,   744,   744,   613,   614,     0,     0,     0,   588,   582,
     585,   586,   574,   560,   557,   526,   528,   744,     0,   744,
     744,     0,   495,   493,     0,     0,   640,   634,   637,   638,
     626,   612,   610,   744,   737,   738,   739,   587,     0,     0,
       0,   535,   529,   532,   533,   521,   509,   507,   744,   639,
       0,   584,   589,   744,   534,     0,   636,   641,   531,   536
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,    10,    11,    12,    18,    19,
      20,    25,    26,    42,    43,    44,    90,    91,    92,    93,
     176,   177,   178,   313,   314,   315,   425,   426,   506,   504,
      45,    46,   100,   101,   102,    47,    48,   105,   106,   107,
      49,    50,   110,   111,   112,    51,    52,   115,   116,   117,
      53,    54,   120,   121,   122,    55,    56,   125,   126,   127,
      57,    58,   130,   131,   132,    59,    60,   134,   204,   205,
     206,   334,   335,   336,   430,   431,   514,   512,    15,    27,
      68,    69,    70,   137,   138,   139,    71,    72,   140,   141,
     212,   210,   340,    73,    74,   142,   143,   218,   217,   346,
      75,    76,   144,   145,   223,   222,   349,    77,    78,   146,
     227,   351,    79,    80,   149,   231,   232,   233,   355,   356,
     357,   440,   441,   522,   521,    24,    81,   157,   158,   159,
     236,   237,   238,   160,   161,   241,   242,   243,   162,   163,
     246,   247,   248,   164,   165,   251,   252,   253,   166,   167,
     256,   257,   258,   168,   169,   260,   373,   374,   375,   450,
     451,   452,   529,   530,   585,   584,    31,   170,   273,   274,
     275,   378,   379,   380,   276,   277,   383,   384,   385,   278,
     279,   388,   389,   390,   280,   281,   393,   394,   395,   282,
     283,   398,   399,   400,   284,   285,   402,   466,   467,   468,
     539,   540,   541,   592,   619,   620,   621,   622,   656,   286,
     287,   403,   404,   471,   470,   544,   288,   289,   405,   406,
     476,   475,   547,   290,   291,   407,   408,   481,   480,   550,
     292,   293,   409,   485,   552,   294,   295,   412,   489,   490,
     491,   556,   557,   558,   600,   601,   631,   630,    85,    86,
     171,   172,   305,   306,   307,   308,   309,   298,   299,   300,
     415,   416,   417,   496,   497,   566,   567,   568,   563,   609,
     610,   645,   646,   647,   648,   677,   678,   679,   705,   706,
     707,   733,   734,   757,   756,   642,   643,   671,   672,   673,
     667,   668,   699,   726,   727,   728,   752,   753,   780,   804,
     805,   806,   839,   840,   841,   885,   991,   777,   778,   800,
     833,   834,   835,   878,   879,   880,   933,   797,   798,   829,
     872,   873,   874,   926,   927,   928,   985,   827,   867,   868,
     921,   922,   976,   977,   972,   973,   974,  1015,  1016,  1017,
    1048,  1072,  1073,  1074,   696,   697,   722,   747,   748,   749,
     773,   774,   795,   824,   825,   826,   862,   863,   864,   920,
    1012,   793,   819,   820,   857,   858,   911,   912,   907,   908,
     909,   964,   965,   966,  1007,  1039,  1040,  1041,   719,   720,
     743,   768,   769,   770,   790,   791,   816,   854,   855,   856,
     902,   903,   904,   961,  1035,   814,   849,   850,   897,   898,
     952,   953,   948,   949,   950,   998,   999,  1000,  1030,  1057,
    1058,  1059,   740,   741,   764,   785,   786,   787,   810,   811,
     812,   845,   846,   892,   893,   888,   889,   890,   940,   941,
     942,   943,   944,   494,   495,   561,   605,   606,   607,   638,
     639,   640,   664,   665,   690,   691,   686,   687,   688,   712,
     713,   714,   715,   716,   623,   624,   658,    94,    95,   181,
     508,   509,   575,    96,    97,   185,   214,   215,   342,   517,
     518,   579,   369,   182,  1068,   322,   183
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -991
static const yytype_int16 yypact[] =
{
      93,  -991,    77,    36,  -991,  -991,   132,   112,  -991,  -991,
     125,   114,   231,  -991,   277,   128,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,   279,   138,   219,    90,    22,  -991,  -991,
     281,   157,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,   197,  -991,   283,  -991,   285,  -991,
     287,  -991,   289,  -991,   291,  -991,   293,  -991,   295,  -991,
     251,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     297,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   241,  -991,
     265,   -24,  -991,  -991,  -991,  -991,  -991,   322,  -991,  -991,
     299,   197,  -991,  -991,  -991,   310,  -991,   329,    26,  -991,
    -991,  -991,  -991,    27,  -991,  -991,  -991,  -991,    31,  -991,
    -991,  -991,  -991,    39,  -991,  -991,  -991,  -991,    33,  -991,
    -991,  -991,  -991,    17,  -991,  -991,  -991,  -991,    10,  -991,
    -991,  -991,  -991,  -991,   301,     8,  -991,  -991,  -991,  -991,
     339,   221,   355,   221,   390,   221,   401,  -991,  -991,   305,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   307,
    -991,   309,  -991,   311,  -991,   313,  -991,   315,  -991,   321,
     -23,   317,   198,   369,   -37,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,     1,  -991,  -991,  -991,   318,  -991,   306,
    -991,   320,  -991,   354,  -991,   358,  -991,   319,  -991,   314,
    -991,   442,    50,  -991,  -991,  -991,  -991,   312,  -991,   328,
    -991,  -991,  -991,  -991,  -991,   447,   330,  -991,  -991,  -991,
    -991,   332,  -991,  -991,  -991,  -991,   446,  -991,   448,   103,
    -991,  -991,  -991,  -991,    41,  -991,  -991,  -991,  -991,    38,
    -991,  -991,  -991,  -991,     4,  -991,  -991,  -991,  -991,    13,
    -991,  -991,  -991,  -991,    20,  -991,  -991,  -991,  -991,  -991,
     331,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,   333,  -991,   335,  -991,   337,
    -991,   342,  -991,   344,  -991,   433,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,   241,  -991,   440,   -11,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     452,  -991,  -991,    63,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,   117,  -991,  -991,  -991,  -991,  -991,
     392,  -991,  -991,  -991,  -991,  -991,   393,  -991,  -991,   398,
    -991,   404,  -991,  -991,  -991,   118,  -991,  -991,   383,  -991,
     389,  -991,   324,  -991,   334,  -991,  -991,  -991,  -991,   350,
     466,   148,  -991,  -991,  -991,  -991,    15,  -991,  -991,  -991,
    -991,    14,  -991,  -991,  -991,  -991,    24,  -991,  -991,  -991,
    -991,    49,  -991,  -991,  -991,  -991,    30,  -991,  -991,  -991,
    -991,   468,   347,   464,   221,   469,   221,   470,   221,   472,
    -991,  -991,   349,  -991,  -991,   -18,  -991,  -991,   477,   478,
     479,   481,  -991,  -991,  -991,   351,   228,  -991,  -991,  -991,
     353,   216,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     357,   216,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     155,  -991,  -991,   359,  -991,   345,  -991,   371,  -991,   426,
    -991,   406,  -991,   485,   107,  -991,  -991,  -991,  -991,   363,
    -991,  -991,  -991,  -991,   365,  -991,  -991,  -991,  -991,   367,
    -991,  -991,  -991,  -991,   488,  -991,   489,   160,  -991,  -991,
    -991,  -991,  -991,  -991,   439,   474,   490,    47,  -991,  -991,
    -991,  -991,   364,  -991,  -991,  -991,  -991,  -991,  -991,   495,
     394,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   499,   396,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   366,
     216,  -991,  -991,  -991,  -991,  -991,   496,  -991,  -991,   113,
    -991,  -991,  -991,  -991,   352,  -991,  -991,   356,  -991,  -991,
     361,  -991,   360,  -991,  -991,  -991,   165,  -991,  -991,  -991,
    -991,   368,   377,  -991,  -991,   503,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,   407,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,   164,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     370,   216,   502,   -61,  -991,  -991,  -991,  -991,  -991,   414,
     207,   507,  -991,  -991,  -991,  -991,    16,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,   513,  -991,  -991,  -991,   411,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,    75,  -991,
    -991,  -991,   362,   372,   511,   374,   207,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,   381,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,   376,   147,  -991,   422,   500,    29,
    -991,  -991,  -991,  -991,   517,   141,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,    11,  -991,  -991,  -991,  -991,   520,
    -991,  -991,  -991,  -991,  -991,  -991,   451,   512,  -991,   378,
     428,  -991,   523,  -991,  -991,   145,  -991,  -991,   527,  -991,
    -991,  -991,    44,  -991,  -991,  -991,  -991,   528,  -991,   424,
     516,  -991,   380,   531,   385,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,   382,    42,   480,  -991,  -991,   532,  -991,
     417,   524,  -991,   384,   537,   391,  -991,  -991,  -991,  -991,
    -991,  -991,   387,   522,   415,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,   386,   540,   465,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,   536,  -991,  -991,   483,   526,  -991,
     388,  -991,   547,   167,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,   544,  -991,     2,  -991,   395,  -991,  -991,   533,  -991,
     397,   551,   121,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     172,  -991,  -991,  -991,   -15,  -991,   399,  -991,  -991,  -991,
    -991,   552,   -43,  -991,  -991,  -991,  -991,   -64,  -991,   403,
     555,   258,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   126,
    -991,   534,  -991,  -991,  -991,   409,   185,  -991,  -991,  -991,
    -991,   556,   -56,  -991,  -991,  -991,  -991,   413,   161,  -991,
    -991,  -991,   -22,  -991,   535,  -991,  -991,  -991,  -991,   559,
     -65,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   266,  -991,
     538,  -991,  -991,  -991,  -991,   558,    -1,  -991,  -991,  -991,
    -991,   561,  -991,  -991,  -991,  -991,  -991,   419,   151,  -991,
    -991,  -991,   162,  -991,   541,   139,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     562,   421,   196,  -991,  -991,  -991,   -49,  -991,   545,  -991,
    -991,  -991,  -991,   563,   560,   427,   570,  -991,  -991,  -991,
      78,  -991,  -991,  -991,  -991,   571,   -28,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,   566,  -991,  -991,   142,  -991,   549,   573,   574,   429,
     -45,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,   572,   575,   579,  -991,  -991,
    -991,   423,   529,  -991,  -991,   577,  -991,  -991,    81,  -991,
     557,   581,   583,   431,  -991,  -991,  -991,   430,  -991,  -991,
    -991,  -991,   492,  -991,  -991,   -26,  -991,   564,   586,   588,
     591,  -991,   435,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     432,  -991,  -991,  -991,  -991,   521,   593,    34,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   434,  -991,
    -991,   436,  -991,  -991,   594,    43,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   504,   596,
       9,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     530,  -991,  -991,  -991,  -991,   443,  -991,  -991,  -991,  -991
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   514,  -991,
    -991,  -991,  -991,  -991,   296,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,   272,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,   253,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     163,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,    71,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,    55,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,   199,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,   -34,  -991,  -991,  -991,  -991,  -991,   -90,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -223,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -261,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -308,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -396,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -242,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -343,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -280,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -375,  -991,  -991,  -991,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -185,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -314,
    -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     -10,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,  -991,
     -85,  -991,  -991,  -991,  -659,  -991,  -991,   -75,  -991,  -991,
    -430,  -991,  -991,  -585,  -991,  -991,  -141,  -991,  -991,  -436,
    -991,  -991,  -991,   -97,  -990,  -991,  -991
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     186,   516,   220,   147,   225,   525,   692,   626,   924,   317,
     362,   524,   207,  1064,   199,  1065,  1066,   364,   455,   453,
     900,   197,   653,   654,   982,   650,   366,   367,   457,   150,
     187,   189,   261,   700,   461,   191,   201,   195,  1064,   262,
    1065,  1066,   865,   193,   360,   358,   413,  1064,   996,  1065,
    1066,   228,   311,   459,   636,   860,   151,   936,   152,   937,
     938,   650,  1013,   263,   847,  1080,   213,   637,   219,   708,
     224,   709,   710,    61,    88,   564,   860,     4,    89,   997,
    1085,  1045,     5,   316,   153,   264,    62,   323,    63,   565,
      64,   848,    65,   265,   588,   925,   492,   312,   154,   866,
     587,   901,   708,   817,   709,   710,   414,   266,   818,   267,
     939,   925,   460,   414,   861,  1014,   155,   462,   343,   361,
    1079,   268,   156,   188,   359,   269,   701,   270,   196,   271,
      66,   272,   194,  1067,  1014,   917,   936,     1,   937,   938,
     711,   458,     7,   368,   198,   208,   454,   456,   190,   759,
     192,   363,   423,   200,   365,   655,   332,   996,    67,   333,
       9,   689,   370,   951,    14,   634,   318,   319,   320,   321,
    1084,   633,    13,   736,   616,   617,   910,   618,    33,    88,
      23,   505,    34,    88,    35,   505,    36,   894,  1027,   993,
     662,   513,    30,    88,   618,   505,    88,   312,    37,   891,
      89,   513,   211,   637,   418,   419,   420,   421,    38,   353,
      39,   301,   354,    84,   302,   618,    40,    88,   410,   505,
     303,    87,   975,   332,   353,   304,   428,   438,    88,    88,
     505,   644,    41,    89,   427,   694,   513,   962,   900,    88,
     962,    16,    17,    89,   433,   537,   963,   958,    88,  1004,
     505,   537,   538,    88,   448,   437,   513,   449,   590,   211,
      88,   448,   505,   473,   527,   478,   554,   483,    32,   555,
     133,   554,   703,    88,   598,   704,   731,   808,   837,   704,
     809,   838,   808,   882,   148,   843,   838,    21,    22,    28,
      29,    82,    83,    98,    99,   103,   104,   108,   109,   113,
     114,   118,   119,   123,   124,   128,   129,   135,   136,   174,
     175,   202,   203,   180,   486,   229,   230,   234,   235,   239,
     240,   244,   245,   249,   250,   254,   255,   296,   297,   472,
     173,   477,   184,   482,   338,   339,   344,   345,   347,   348,
     259,   371,   372,   376,   377,   381,   382,   386,   387,   209,
     526,   507,   391,   392,   396,   397,   515,   464,   465,   487,
     488,   502,   503,   510,   511,   216,   523,   519,   520,   542,
     543,   545,   546,   548,   549,   310,   582,   583,   603,   604,
     628,   629,   669,   670,   675,   676,   684,   685,   724,   725,
     745,   746,   754,   755,   766,   767,   783,   784,   802,   803,
     221,   569,   570,   571,   572,   822,   823,   831,   832,   852,
     853,   226,   576,   870,   871,   324,   896,   876,   877,   886,
     887,   580,   915,   905,   906,   930,   877,   325,   914,   946,
     947,   970,   971,   989,   990,  1010,  1011,  1033,  1034,   326,
    1037,  1038,  1055,  1056,  1070,  1071,   329,   327,   331,   337,
     341,   627,   350,   328,   352,   586,   597,   330,   401,   411,
     422,   432,   956,   602,   434,   435,   442,   611,   955,   436,
     443,   444,   447,   446,   469,   445,   463,   613,   532,   474,
     479,   614,   484,   498,   499,   500,   980,   501,   533,   534,
     531,   536,   979,   535,   551,   553,   559,   560,   574,   573,
     562,   577,   578,   581,   589,   593,   612,   608,   635,   596,
     641,   594,   595,   651,   615,   652,   657,   625,   660,   674,
     682,   698,   695,   702,   666,   729,   632,   659,   717,   718,
     721,   730,   735,   742,   738,   649,   739,   750,   661,   760,
     761,   751,   762,   771,   763,   776,   788,   772,   779,   789,
     781,   794,   799,   807,   681,   796,   815,   836,   859,   828,
     683,   875,   899,   884,   919,   923,   988,   932,   935,   945,
     960,   649,   969,   987,   984,   992,  1003,   995,  1006,  1008,
    1009,  1021,  1020,  1022,  1024,  1026,  1029,  1031,  1025,  1032,
     693,  1044,  1049,  1047,  1050,  1051,  1053,  1077,  1062,  1063,
    1078,   723,  1083,  1082,  1089,   179,   429,  1087,   439,   424,
     591,   599,   680,   528,   493,   732,   883,   931,   983,  1046,
     918,  1005,   959,  1028,   744,   844,   994,   737,   663,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   765,     0,     0,     0,     0,
       0,     0,     0,   775,     0,     0,     0,     0,     0,   758,
       0,     0,     0,     0,     0,     0,   782,     0,     0,     0,
       0,     0,     0,     0,   792,     0,     0,     0,     0,     0,
       0,     0,   801,     0,     0,     0,     0,     0,     0,     0,
       0,   813,     0,     0,     0,     0,     0,   821,     0,     0,
       0,     0,   830,     0,     0,     0,     0,     0,     0,     0,
     842,     0,     0,     0,     0,     0,     0,     0,   851,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   869,     0,     0,     0,     0,     0,     0,     0,   881,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   916,     0,     0,     0,     0,     0,     0,     0,
       0,   895,     0,     0,     0,     0,     0,     0,   929,     0,
       0,     0,     0,   913,     0,     0,     0,   934,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   957,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   967,     0,     0,     0,     0,     0,     0,
       0,     0,   968,   954,     0,     0,   981,     0,     0,     0,
       0,     0,     0,     0,     0,   986,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   978,     0,     0,
       0,     0,     0,     0,  1001,     0,     0,     0,     0,     0,
       0,     0,     0,  1002,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1018,     0,
       0,     0,     0,     0,     0,     0,     0,  1019,     0,     0,
       0,  1023,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1036,
       0,  1042,  1043,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1052,     0,     0,     0,     0,     0,
       0,     0,  1054,     0,  1060,  1061,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1069,     0,  1075,  1076,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1081,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1086,     0,     0,     0,     0,  1088
};

static const yytype_int16 yycheck[] =
{
      97,   431,   143,    78,   145,   441,   665,   592,    73,     8,
       6,   441,     4,     4,     4,     6,     7,     4,     4,     4,
      76,     4,     6,     7,    73,   610,     6,     7,     4,    53,
       4,     4,    55,     4,     4,     4,   133,     4,     4,    62,
       6,     7,   106,     4,     6,     4,    57,     4,    76,     6,
       7,   148,    89,     4,   115,    98,    80,    58,    82,    60,
      61,   646,   107,    86,    79,  1055,   141,   128,   143,    58,
     145,    60,    61,    51,    32,    28,    98,     0,    36,   107,
    1070,   107,    46,   180,   108,   108,    64,   184,    66,    42,
      68,   106,    70,   116,   530,   160,   114,   134,   122,   163,
     530,   157,    58,   101,    60,    61,   124,   130,   106,   132,
     111,   160,    63,   124,   157,   160,   140,    87,   215,    81,
      77,   144,   146,    97,    83,   148,    97,   150,    95,   152,
     108,   154,    93,    99,   160,   157,    58,    44,    60,    61,
     129,   117,    10,   123,   127,   137,   131,   133,   121,   734,
     119,   147,    89,   143,   141,   139,   106,    76,   136,   109,
      48,    14,   259,    12,    50,   601,   165,   166,   167,   168,
     161,   601,    47,   129,    10,    11,    15,    30,    88,    32,
      52,    34,    92,    32,    94,    34,    96,   846,   107,   111,
     115,    40,    54,    32,    30,    34,    32,   134,   108,    14,
      36,    40,    38,   128,   301,   302,   303,   304,   118,   106,
     120,    13,   109,    56,    16,    30,   126,    32,   293,    34,
      22,    24,    26,   106,   106,    27,   109,   109,    32,    32,
      34,    24,   142,    36,   331,   665,    40,    98,    76,    32,
      98,    10,    11,    36,   341,   138,   107,    85,    32,   107,
      34,   138,   145,    32,   106,   352,    40,   109,   145,    38,
      32,   106,    34,   404,   109,   406,   106,   408,    49,   109,
      19,   106,   131,    32,   109,   134,   131,   110,   157,   134,
     113,   160,   110,   157,    19,   113,   160,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,     3,   411,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   404,
       8,   406,     3,   408,     6,     7,     6,     7,     6,     7,
      19,    10,    11,    10,    11,    10,    11,    10,    11,    10,
     447,   426,    10,    11,    10,    11,   431,    10,    11,    10,
      11,    10,    11,    10,    11,    10,   441,    10,    11,     6,
       7,     6,     7,     6,     7,     6,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,   498,   499,   500,   501,    10,    11,    10,    11,    10,
      11,    10,   509,    10,    11,    97,   846,   159,   160,    10,
      11,   518,   858,    10,    11,   159,   160,   121,   858,    10,
      11,    10,    11,     6,     7,     6,     7,     6,     7,   119,
      10,    11,    10,    11,    10,    11,   127,    93,     6,   137,
       3,   592,     6,    95,     6,   530,   553,   143,    25,    19,
       8,    69,   898,   560,    71,    67,    83,   564,   898,    65,
      81,   147,     6,   123,    10,   141,     8,   574,   133,    10,
      10,   578,    10,     6,     6,     6,   922,     6,   117,    63,
     131,     6,   922,    87,     6,     6,    57,    23,     3,   135,
      10,   107,     3,   107,     8,   153,     3,   130,     6,   149,
      96,   155,   151,     6,   107,   612,     3,   592,   107,     8,
     139,    21,   100,     6,   162,    97,   601,   624,     8,    78,
      18,     8,     5,    17,     6,   610,   112,     6,   635,    59,
       8,   156,   125,     6,    20,   158,     6,   156,    26,    84,
     135,    15,    26,     6,   651,    72,    12,     6,     6,    26,
     657,     6,     6,    29,    29,     6,     6,    29,    10,     8,
      29,   646,    10,    10,    29,     5,    10,     6,    29,     6,
       6,     6,    10,     4,   161,     8,    29,     6,    59,     6,
     665,    99,     6,    29,     6,     4,   161,   161,    77,     6,
       6,   698,     6,    99,   161,    91,   334,    77,   355,   313,
     539,   556,   646,   450,   415,   705,   839,   878,   926,  1015,
     862,   964,   902,   998,   721,   810,   940,   712,   638,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   742,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   750,    -1,    -1,    -1,    -1,    -1,   734,
      -1,    -1,    -1,    -1,    -1,    -1,   763,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   771,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   779,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   788,    -1,    -1,    -1,    -1,    -1,   794,    -1,    -1,
      -1,    -1,   799,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     807,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   815,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   828,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   836,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   859,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   846,    -1,    -1,    -1,    -1,    -1,    -1,   875,    -1,
      -1,    -1,    -1,   858,    -1,    -1,    -1,   884,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   899,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   910,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   919,   898,    -1,    -1,   923,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   932,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   922,    -1,    -1,
      -1,    -1,    -1,    -1,   951,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   960,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   975,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   984,    -1,    -1,
      -1,   988,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1006,
      -1,  1008,  1009,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1021,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1029,    -1,  1031,  1032,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1047,    -1,  1049,  1050,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1063,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1078,    -1,    -1,    -1,    -1,  1083
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,     0,    46,   172,    10,   173,    48,
     174,   175,   176,    47,    50,   247,    10,    11,   177,   178,
     179,    10,    11,    52,   294,   180,   181,   248,    10,    11,
      54,   335,    49,    88,    92,    94,    96,   108,   118,   120,
     126,   142,   182,   183,   184,   199,   200,   204,   205,   209,
     210,   214,   215,   219,   220,   224,   225,   229,   230,   234,
     235,    51,    64,    66,    68,    70,   108,   136,   249,   250,
     251,   255,   256,   262,   263,   269,   270,   276,   277,   281,
     282,   295,    10,    11,    56,   417,   418,    24,    32,    36,
     185,   186,   187,   188,   626,   627,   632,   633,    10,    11,
     201,   202,   203,    10,    11,   206,   207,   208,    10,    11,
     211,   212,   213,    10,    11,   216,   217,   218,    10,    11,
     221,   222,   223,    10,    11,   226,   227,   228,    10,    11,
     231,   232,   233,    19,   236,    10,    11,   252,   253,   254,
     257,   258,   264,   265,   271,   272,   278,   626,    19,   283,
      53,    80,    82,   108,   122,   140,   146,   296,   297,   298,
     302,   303,   307,   308,   312,   313,   317,   318,   322,   323,
     336,   419,   420,     8,    10,    11,   189,   190,   191,   187,
       3,   628,   642,   645,     3,   634,   642,     4,    97,     4,
     121,     4,   119,     4,    93,     4,    95,     4,   127,     4,
     143,   642,    10,    11,   237,   238,   239,     4,   137,    10,
     260,    38,   259,   626,   635,   636,    10,   267,   266,   626,
     635,    10,   274,   273,   626,   635,    10,   279,   642,    10,
      11,   284,   285,   286,    10,    11,   299,   300,   301,    10,
      11,   304,   305,   306,    10,    11,   309,   310,   311,    10,
      11,   314,   315,   316,    10,    11,   319,   320,   321,    19,
     324,    55,    62,    86,   108,   116,   130,   132,   144,   148,
     150,   152,   154,   337,   338,   339,   343,   344,   348,   349,
     353,   354,   358,   359,   363,   364,   378,   379,   385,   386,
     392,   393,   399,   400,   404,   405,    10,    11,   426,   427,
     428,    13,    16,    22,    27,   421,   422,   423,   424,   425,
       6,    89,   134,   192,   193,   194,   642,     8,   165,   166,
     167,   168,   644,   642,    97,   121,   119,    93,    95,   127,
     143,     6,   106,   109,   240,   241,   242,   137,     6,     7,
     261,     3,   637,   642,     6,     7,   268,     6,     7,   275,
       6,   280,     6,   106,   109,   287,   288,   289,     4,    83,
       6,    81,     6,   147,     4,   141,     6,     7,   123,   641,
     642,    10,    11,   325,   326,   327,    10,    11,   340,   341,
     342,    10,    11,   345,   346,   347,    10,    11,   350,   351,
     352,    10,    11,   355,   356,   357,    10,    11,   360,   361,
     362,    25,   365,   380,   381,   387,   388,   394,   395,   401,
     626,    19,   406,    57,   124,   429,   430,   431,   642,   642,
     642,   642,     8,    89,   193,   195,   196,   642,   109,   241,
     243,   244,    69,   642,    71,    67,    65,   642,   109,   288,
     290,   291,    83,    81,   147,   141,   123,     6,   106,   109,
     328,   329,   330,     4,   131,     4,   133,     4,   117,     4,
      63,     4,    87,     8,    10,    11,   366,   367,   368,    10,
     383,   382,   626,   635,    10,   390,   389,   626,   635,    10,
     397,   396,   626,   635,    10,   402,   642,    10,    11,   407,
     408,   409,   114,   430,   602,   603,   432,   433,     6,     6,
       6,     6,    10,    11,   198,    34,   197,   626,   629,   630,
      10,    11,   246,    40,   245,   626,   629,   638,   639,    10,
      11,   293,   292,   626,   629,   638,   642,   109,   329,   331,
     332,   131,   133,   117,    63,    87,     6,   138,   145,   369,
     370,   371,     6,     7,   384,     6,     7,   391,     6,     7,
     398,     6,   403,     6,   106,   109,   410,   411,   412,    57,
      23,   604,    10,   437,    28,    42,   434,   435,   436,   642,
     642,   642,   642,   135,     3,   631,   642,   107,     3,   640,
     642,   107,    10,    11,   334,   333,   626,   629,   638,     8,
     145,   370,   372,   153,   155,   151,   149,   642,   109,   411,
     413,   414,   642,    10,    11,   605,   606,   607,   130,   438,
     439,   642,     3,   642,   642,   107,    10,    11,    30,   373,
     374,   375,   376,   623,   624,   626,   632,   635,    10,    11,
     416,   415,   626,   629,   638,     6,   115,   128,   608,   609,
     610,    96,   454,   455,    24,   440,   441,   442,   443,   626,
     632,     6,   642,     6,     7,   139,   377,     3,   625,   642,
     107,   642,   115,   609,   611,   612,   162,   459,   460,    10,
      11,   456,   457,   458,     8,    10,    11,   444,   445,   446,
     442,   642,   139,   642,    10,    11,   615,   616,   617,    14,
     613,   614,   623,   626,   629,   100,   513,   514,    21,   461,
       4,    97,     6,   131,   134,   447,   448,   449,    58,    60,
      61,   129,   618,   619,   620,   621,   622,     8,    78,   547,
     548,    18,   515,   642,    10,    11,   462,   463,   464,    97,
       8,   131,   448,   450,   451,     5,   129,   619,     6,   112,
     581,   582,    17,   549,   642,    10,    11,   516,   517,   518,
       6,   156,   465,   466,    10,    11,   453,   452,   626,   632,
      59,     8,   125,    20,   583,   642,    10,    11,   550,   551,
     552,     6,   156,   519,   520,   642,   158,   476,   477,    26,
     467,   135,   642,    10,    11,   584,   585,   586,     6,    84,
     553,   554,   642,   530,    15,   521,    72,   486,   487,    26,
     478,   642,    10,    11,   468,   469,   470,     6,   110,   113,
     587,   588,   589,   642,   564,    12,   555,   101,   106,   531,
     532,   642,    10,    11,   522,   523,   524,   496,    26,   488,
     642,    10,    11,   479,   480,   481,     6,   157,   160,   471,
     472,   473,   642,   113,   588,   590,   591,    79,   106,   565,
     566,   642,    10,    11,   556,   557,   558,   533,   534,     6,
      98,   157,   525,   526,   527,   106,   163,   497,   498,   642,
      10,    11,   489,   490,   491,     6,   159,   160,   482,   483,
     484,   642,   157,   472,    29,   474,    10,    11,   594,   595,
     596,    14,   592,   593,   623,   626,   629,   567,   568,     6,
      76,   157,   559,   560,   561,    10,    11,   537,   538,   539,
      15,   535,   536,   626,   629,   638,   642,   157,   526,    29,
     528,   499,   500,     6,    73,   160,   492,   493,   494,   642,
     159,   483,    29,   485,   642,    10,    58,    60,    61,   111,
     597,   598,   599,   600,   601,     8,    10,    11,   571,   572,
     573,    12,   569,   570,   626,   629,   638,   642,    85,   560,
      29,   562,    98,   107,   540,   541,   542,   642,   642,    10,
      10,    11,   503,   504,   505,    26,   501,   502,   626,   629,
     638,   642,    73,   493,    29,   495,   642,    10,     6,     6,
       7,   475,     5,   111,   598,     6,    76,   107,   574,   575,
     576,   642,   642,    10,   107,   541,    29,   543,     6,     6,
       6,     7,   529,   107,   160,   506,   507,   508,   642,   642,
      10,     6,     4,   642,   161,    59,     8,   107,   575,    29,
     577,     6,     6,     6,     7,   563,   642,    10,    11,   544,
     545,   546,   642,   642,    99,   107,   507,    29,   509,     6,
       6,     4,   642,   161,   642,    10,    11,   578,   579,   580,
     642,   642,    77,     6,     4,     6,     7,    99,   643,   642,
      10,    11,   510,   511,   512,   642,   642,   161,     6,    77,
     643,   642,    99,     6,   161,   643,   642,    77,   642,   161
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
        case 28:

    {	if (parserData->generalStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one generalStatus element allowed");	
		if (osresult->general->generalStatus != NULL) 
			osrlerror(NULL, NULL, parserData, "generalStatus previously allocated");
		osresult->general->generalStatus = new GeneralStatus();
		parserData->generalStatusPresent = true;
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
	;}
    break;

  case 29:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	;}
    break;

  case 32:

    { 
	    if ((parserData->typeAttribute != "error"  ) &&
	        (parserData->typeAttribute != "warning") && 
	        (parserData->typeAttribute != "normal"))
			osrlerror(NULL, NULL, parserData, "general status type does not match any legal value");
		osresult->setGeneralStatusType(parserData->typeAttribute); 
	;}
    break;

  case 33:

    {   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	;}
    break;

  case 35:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for generalStatus element");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of general substatuses cannot be negative");
    osresult->setNumberOfGeneralSubstatuses((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 36:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 37:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 43:

    {	parserData->kounter++;
;}
    break;

  case 44:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 45:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
;}
    break;

  case 48:

    {	
		osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 49:

    {	
		osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 53:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 58:

    {osresult->setGeneralMessage((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 60:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 65:

    {osresult->setServiceURI((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 67:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 72:

    {osresult->setServiceName((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 74:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 79:

    {osresult->setInstanceName((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 81:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 86:

    {osresult->setJobID((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 88:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 93:

    {osresult->setSolverInvoked((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 95:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 100:

    {osresult->setTimeStamp((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 102:

    {	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	;}
    break;

  case 103:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other general results cannot be negative");
	osresult->setNumberOfOtherGeneralResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 104:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 105:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 111:

    {	parserData->kounter++;
;}
    break;

  case 112:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 113:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 116:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setGeneralOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 117:

    {	
		osresult->setGeneralOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 118:

    {	
		osresult->setGeneralOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 133:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 138:

    {osresult->setSystemInformation((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 140:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 144:

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
	;}
    break;

  case 145:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 147:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 148:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 150:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 154:

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
	;}
    break;

  case 155:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 157:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 158:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 160:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 164:

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
	;}
    break;

  case 165:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 167:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 168:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 170:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 172:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 174:

    {osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 176:

    {	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	;}
    break;

  case 177:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other system results cannot be negative");
	osresult->setNumberOfOtherSystemResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 178:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 179:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 185:

    {	parserData->kounter++;
;}
    break;

  case 186:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 187:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 190:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setSystemOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 191:

    {	
		osresult->setSystemOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 192:

    {	
		osresult->setSystemOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 207:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 212:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval);
		if (parserData->tempStr != "busy"                &&
			parserData->tempStr != "busyButAccepting"    &&
			parserData->tempStr != "idle"                &&
			parserData->tempStr != "idleButNotAccepting" &&
			parserData->tempStr != "noResponse"             )
			osrlerror(NULL, NULL, parserData, "current system state not recognized");
		osresult->setCurrentState(parserData->tempStr); 
		parserData->errorText = NULL;
	;}
    break;

  case 214:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 219:

    {osresult->setCurrentJobCount((yyvsp[(2) - (3)].ival)); /* free($2); */  parserData->errorText = NULL;;}
    break;

  case 221:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 226:

    {osresult->setTotalJobsSoFar((yyvsp[(2) - (3)].ival)); parserData->errorText = NULL;;}
    break;

  case 228:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 233:

    {osresult->setTimeServiceStarted((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 235:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 240:

    {osresult->setServiceUtilization( parserData->tempVal);  parserData->errorText = NULL;;}
    break;

  case 242:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	;}
    break;

  case 243:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other service results cannot be negative");
	osresult->setNumberOfOtherServiceResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 244:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 245:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 251:

    {	parserData->kounter++;
;}
    break;

  case 252:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 253:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 256:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setServiceOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 257:

    {	
		osresult->setServiceOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 258:

    {	
		osresult->setServiceOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 278:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 283:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
		if (parserData->tempStr != "waiting"  &&
			parserData->tempStr != "running"  &&
			parserData->tempStr != "killed"   &&
			parserData->tempStr != "finished" &&
			parserData->tempStr != "unknown"     )
			osrlerror (NULL, NULL, parserData, "status of this job not recognized");
		osresult->setJobStatus(parserData->tempStr);  
		parserData->errorText = NULL;
	;}
    break;

  case 285:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 290:

    {osresult->setJobSubmitTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 292:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 297:

    {osresult->setScheduledStartTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 299:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 304:

    {osresult->setActualStartTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 306:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 311:

    {osresult->setJobEndTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 313:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 314:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
;}
    break;

  case 315:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <time> element");
	;}
    break;

  case 316:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, "fewer <time> elements than specified");
	;}
    break;

  case 323:

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
;}
    break;

  case 326:

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
	;}
    break;

  case 327:

    {	if (parserData->typeAttribute != "cpuTime"     &&
			parserData->typeAttribute != "elapsedTime" &&
 			parserData->typeAttribute != "other"   )     
			osrlerror(NULL, NULL, parserData, "time type not recognized");
	;}
    break;

  case 328:

    {	if (parserData->categoryAttribute != "total"          &&
			parserData->categoryAttribute != "input"          &&
			parserData->categoryAttribute != "preprocessing"  &&
			parserData->categoryAttribute != "optimization"   &&
			parserData->categoryAttribute != "postprocessing" &&
			parserData->categoryAttribute != "output"         &&
 			parserData->categoryAttribute != "other"   )
			osrlerror(NULL, NULL, parserData, "time category not recognized");
	;}
    break;

  case 334:

    {	osresult->addTimingInformation(parserData->typeAttribute, parserData->categoryAttribute,
		parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue);       
	parserData->ivar++;
	parserData->timeType = "";
	parserData->timeCategory = "";
	parserData->timeUnit = "";
	parserData->timeDescription = "";      
;}
    break;

  case 335:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 336:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 338:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 342:

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
	;}
    break;

  case 343:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 345:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 346:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 348:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 352:

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
	;}
    break;

  case 353:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 355:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 356:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 358:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 362:

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
	;}
    break;

  case 363:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 365:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 366:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 368:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 370:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 372:

    {osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 374:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	;}
    break;

  case 375:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other job results cannot be negative");
	osresult->setNumberOfOtherJobResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 376:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 377:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 383:

    {	parserData->kounter++;
;}
    break;

  case 384:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 385:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 388:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setJobOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 389:

    {	
		osresult->setJobOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 390:

    {	
		osresult->setJobOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 395:

    {	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
;}
    break;

  case 396:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, "numberOfSolutions was never set");
;}
    break;

  case 403:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfSolutions = (yyvsp[(3) - (4)].ival); 
	osresult->setSolutionNumber((yyvsp[(3) - (4)].ival));
	parserData->solutionIdx = 0;
;}
    break;

  case 404:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	parserData->nVarPresent = true;	
	parserData->numberOfVariables = (yyvsp[(3) - (4)].ival); 
	osresult->setVariableNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 405:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	parserData->nConPresent = true;		
	parserData->numberOfConstraints = (yyvsp[(3) - (4)].ival); 
	osresult->setConstraintNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 406:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	parserData->nObjPresent = true;
	parserData->numberOfObjectives = (yyvsp[(3) - (4)].ival); 
	osresult->setObjectiveNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 407:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solution> element");
	;}
    break;

  case 408:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, "fewer <solution> elements than specified");
	;}
    break;

  case 415:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 421:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 422:

    {	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval);
	if (parserData->tempStr != "true" && parserData->tempStr != "false")
		osrlerror(NULL, NULL, parserData, "weightedobjectives must be true or false");
  	osresult->setSolutionWeightedObjectives(parserData->solutionIdx, parserData->tempStr);
;}
    break;

  case 423:

    {
		parserData->solutionIdx++;
	;}
    break;

  case 425:

    {	parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
	;}
    break;

  case 426:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
	;}
    break;

  case 429:

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

  case 430:

    {   osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute);
	;}
    break;

  case 432:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for solution status element");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solution substatuses cannot be negative");
    osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 433:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 434:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 440:

    {	parserData->kounter++; ;}
    break;

  case 441:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 442:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
;}
    break;

  case 445:

    {	
		if (parserData->typeAttribute != "stoppedByLimit"  &&
			parserData->typeAttribute != "stoppedByBounds" &&
			parserData->typeAttribute != "other" )
		osrlerror(NULL, NULL, parserData, "substatus type attribute has bad value");
		osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
										   parserData->typeAttribute);	
	;}
    break;

  case 446:

    {	
		osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
												  parserData->descriptionAttribute);
	;}
    break;

  case 456:

    {	osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
		parserData->errorText = NULL;
	;}
    break;

  case 459:

    {	parserData->numberOfOtherVariableResults = 0; ;}
    break;

  case 461:

    {	
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other variable results cannot be negative");
		osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->numberOfOtherVariableResults = (yyvsp[(3) - (4)].ival);
		parserData->iOther = 0;
	;}
    break;

  case 469:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
	osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 470:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 471:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 477:

    {	osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 478:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 479:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 480:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 481:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 485:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 486:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 487:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 493:

    {
	osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 			parserData->idx,         (yyvsp[(4) - (5)].sval));
	parserData->kounter++;
;}
    break;

  case 494:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 495:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 499:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	osresult->setNumberOfBasisVar(parserData->solutionIdx, parserData->numberOfVar);
;}
    break;

  case 500:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 501:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 507:

    {	parserData->tempStr = (yyvsp[(4) - (5)].sval);
	if (parserData->tempStr != "unknown"  &&
		parserData->tempStr != "basic"    &&
		parserData->tempStr != "atLower"  &&
		parserData->tempStr != "atUpper"  &&
		parserData->tempStr != "superBasic" )
		osrlerror(NULL, NULL, parserData, "unrecognized basis status");
	osresult->setBasisVar(parserData->solutionIdx, parserData->kounter, 
					 	  parserData->idx,         parserData->tempStr);
	parserData->kounter++;
;}
    break;

  case 508:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 509:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 512:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 513:

    {
	if (parserData->iOther >= parserData->numberOfOtherVariableResults)
		osrlerror(NULL, NULL, parserData, "more <otherVariableResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
;}
    break;

  case 514:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfVar attribute"); 
	;}
    break;

  case 518:

    {	
	 	osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 											  parserData->valueAttribute);
  ;}
    break;

  case 519:

    {	
	 	osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 											 parserData->nameAttribute);
  ;}
    break;

  case 520:

    {	
	 	osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 													parserData->descriptionAttribute);
  ;}
    break;

  case 521:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 529:

    { 	
	parserData->kounter++;
;}
    break;

  case 531:

    {	
 	osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 536:

    {	
	 	osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 539:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 541:

    {
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other objective results cannot be negative");
		parserData->numberOfOtherObjectiveResults = (yyvsp[(3) - (4)].ival);
        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 549:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj);
	parserData->kounter = 0;
;}
    break;

  case 550:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <obj> element");
	;}
    break;

  case 551:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, "fewer <obj> elements than specified");
	;}
    break;

  case 557:

    {	osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 558:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, "more <obj> elements than specified");
	parserData->idx = -1;
;}
    break;

  case 560:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 561:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 562:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 565:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 566:

    {
	if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
		osrlerror(NULL, NULL, parserData, "more <otherObjectiveResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
;}
    break;

  case 567:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfObj attribute"); 
	;}
    break;

  case 571:

    {	
	 	osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 											   parserData->valueAttribute);
  ;}
    break;

  case 572:

    {	
	  	osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 											  parserData->nameAttribute);
  ;}
    break;

  case 573:

    {	
	 	osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
 													 parserData->descriptionAttribute);
  ;}
    break;

  case 574:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 582:

    {  
	parserData->kounter++;
;}
    break;

  case 584:

    {	osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 589:

    {	osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 592:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 594:

    {
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other constraint results cannot be negative");
		parserData->numberOfOtherConstraintResults = (yyvsp[(3) - (4)].ival);
		osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 601:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 602:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon);
	parserData->kounter = 0;
;}
    break;

  case 603:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <con> element");
	;}
    break;

  case 604:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, "fewer <con> elements than specified");
	;}
    break;

  case 610:

    {	osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
						   parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 611:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, "more <con> elements than specified");
;}
    break;

  case 612:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 613:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 614:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 617:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 618:

    {
	if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
		osrlerror(NULL, NULL, parserData, "more <otherConstraintResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
;}
    break;

  case 619:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfCon attribute"); 
	;}
    break;

  case 623:

    {	
	 	osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 												parserData->valueAttribute);
  ;}
    break;

  case 624:

    {	
	 	osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 											   parserData->nameAttribute);
  ;}
    break;

  case 625:

    {	
	 	osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 													  parserData->descriptionAttribute);
  ;}
    break;

  case 626:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 634:

    { 	
	parserData->kounter++;
;}
    break;

  case 636:

    {	
 	osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 641:

    {	
	 	osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 644:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 645:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solution results cannot be negative");
    osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->iOther = 0; 
;}
    break;

  case 646:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <otherSolutionResult> element");
	;}
    break;

  case 647:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <otherSolutionResult> elements than specified");
	;}
    break;

  case 653:

    {	parserData->iOther++;
;}
    break;

  case 654:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 655:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have numberOfItems attribute");
;}
    break;

  case 658:

    {	
		osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
											 parserData->nameAttribute);
	;}
    break;

  case 659:

    {	
		osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
												 parserData->categoryAttribute);
	;}
    break;

  case 660:

    {	
		osresult->setOtherSolutionResultDescription(parserData->solutionIdx, parserData->iOther,
											 parserData->descriptionAttribute);
	;}
    break;

  case 662:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
	osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, parserData->iOther,
												  parserData->numberOfItems);
	parserData->kounter = 0;
;}
    break;

  case 663:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	;}
    break;

  case 664:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	;}
    break;

  case 670:

    {	parserData->kounter++;
;}
    break;

  case 671:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
;}
    break;

  case 675:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
	osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
										 parserData->kounter, parserData->itemContent);
;}
    break;

  case 678:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 679:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solver outputs cannot be negative");
    osresult->setNumberOfSolverOutputs((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->iOther = 0; 
;}
    break;

  case 680:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solverOutput> element");
	;}
    break;

  case 681:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <solverOutput> elements than specified");
	;}
    break;

  case 687:

    {	parserData->iOther++;
;}
    break;

  case 688:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <solverOutput> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 689:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have numberOfItems attribute");
;}
    break;

  case 693:

    {	
		osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute);
	;}
    break;

  case 694:

    {	
		osresult->setSolverOutputCategory(parserData->iOther, parserData->categoryAttribute);
	;}
    break;

  case 695:

    {	
		osresult->setSolverOutputDescription(parserData->iOther, parserData->descriptionAttribute);
	;}
    break;

  case 696:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
	osresult->setSolverOutputNumberOfItems(parserData->iOther, parserData->numberOfItems);
	parserData->kounter = 0;
;}
    break;

  case 697:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	;}
    break;

  case 698:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	;}
    break;

  case 704:

    {	parserData->kounter++;
;}
    break;

  case 705:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
;}
    break;

  case 709:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
	osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, parserData->itemContent);
;}
    break;

  case 711:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 712:

    { parserData->categoryAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 713:

    { parserData->categoryAttribute = "";          ;}
    break;

  case 715:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 716:

    { parserData->descriptionAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 717:

    { parserData->descriptionAttribute = "";          ;}
    break;

  case 719:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 720:

    { parserData->nameAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 721:

    { parserData->nameAttribute = "";          ;}
    break;

  case 723:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 724:

    { parserData->typeAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 725:

    { parserData->typeAttribute = "";          ;}
    break;

  case 727:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 728:

    { parserData->unitAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 729:

    { parserData->unitAttribute = "";          ;}
    break;

  case 731:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 732:

    { parserData->valueAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 733:

    { parserData->valueAttribute = "";          ;}
    break;

  case 734:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 735:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 737:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 738:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 739:

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


