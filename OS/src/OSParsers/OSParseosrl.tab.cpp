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
#define YYLAST   954

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  416
/* YYNRULES -- Number of rules.  */
#define YYNRULES  681
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1024

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
     243,   245,   247,   248,   251,   253,   255,   257,   260,   262,
     263,   266,   271,   272,   275,   277,   279,   281,   283,   285,
     287,   290,   292,   296,   299,   301,   305,   307,   309,   310,
     313,   315,   317,   321,   323,   325,   329,   331,   333,   334,
     337,   339,   341,   345,   347,   349,   353,   355,   357,   358,
     361,   363,   365,   369,   371,   373,   377,   379,   380,   382,
     386,   388,   392,   394,   399,   401,   403,   406,   408,   412,
     414,   417,   421,   423,   425,   426,   429,   431,   433,   435,
     438,   440,   441,   444,   449,   450,   453,   455,   457,   459,
     461,   463,   465,   468,   470,   474,   477,   479,   482,   484,
     488,   491,   493,   496,   498,   502,   505,   507,   510,   512,
     516,   519,   521,   524,   526,   530,   533,   535,   539,   541,
     546,   548,   550,   553,   555,   559,   561,   564,   568,   570,
     572,   573,   576,   578,   580,   582,   585,   587,   588,   591,
     596,   597,   600,   602,   604,   606,   608,   610,   612,   614,
     616,   618,   620,   622,   625,   627,   631,   634,   636,   639,
     641,   645,   648,   650,   653,   655,   659,   662,   664,   667,
     669,   673,   676,   678,   681,   683,   687,   690,   692,   696,
     698,   703,   705,   707,   710,   712,   716,   718,   721,   725,
     727,   728,   731,   733,   735,   737,   739,   741,   743,   746,
     748,   752,   754,   756,   760,   762,   764,   765,   768,   770,
     772,   776,   778,   780,   784,   786,   788,   789,   792,   794,
     796,   800,   802,   804,   808,   810,   812,   813,   816,   818,
     820,   824,   826,   828,   832,   834,   835,   837,   841,   843,
     847,   849,   854,   856,   858,   861,   863,   867,   869,   872,
     876,   878,   880,   881,   884,   886,   888,   890,   893,   895,
     896,   900,   902,   904,   905,   908,   910,   912,   914,   916,
     921,   926,   931,   936,   938,   940,   943,   945,   950,   952,
     955,   959,   961,   963,   964,   967,   969,   971,   976,   980,
     989,   993,   995,   997,   999,  1002,  1004,  1006,  1008,  1013,
    1015,  1017,  1020,  1022,  1026,  1028,  1031,  1035,  1037,  1039,
    1040,  1043,  1045,  1047,  1050,  1052,  1053,  1058,  1062,  1065,
    1066,  1070,  1072,  1073,  1078,  1080,  1082,  1089,  1090,  1094,
    1096,  1101,  1103,  1105,  1108,  1110,  1114,  1116,  1119,  1125,
    1127,  1132,  1134,  1136,  1137,  1141,  1143,  1148,  1150,  1152,
    1155,  1157,  1161,  1163,  1166,  1172,  1174,  1179,  1180,  1184,
    1186,  1191,  1193,  1195,  1198,  1200,  1204,  1206,  1209,  1215,
    1217,  1222,  1223,  1226,  1230,  1232,  1234,  1235,  1238,  1240,
    1242,  1244,  1246,  1251,  1253,  1257,  1258,  1261,  1265,  1267,
    1272,  1276,  1279,  1281,  1282,  1286,  1288,  1289,  1294,  1296,
    1298,  1303,  1304,  1308,  1310,  1315,  1317,  1319,  1322,  1324,
    1328,  1330,  1333,  1339,  1341,  1342,  1347,  1349,  1351,  1352,
    1355,  1359,  1361,  1363,  1364,  1367,  1369,  1371,  1373,  1375,
    1380,  1382,  1386,  1387,  1390,  1394,  1396,  1401,  1405,  1408,
    1410,  1411,  1415,  1417,  1418,  1423,  1425,  1427,  1432,  1433,
    1437,  1439,  1444,  1446,  1448,  1451,  1453,  1457,  1459,  1462,
    1468,  1470,  1475,  1477,  1479,  1480,  1483,  1487,  1489,  1491,
    1492,  1495,  1497,  1499,  1501,  1503,  1508,  1510,  1514,  1515,
    1518,  1522,  1524,  1529,  1533,  1536,  1538,  1539,  1543,  1545,
    1550,  1552,  1554,  1557,  1559,  1563,  1565,  1568,  1572,  1574,
    1576,  1577,  1580,  1582,  1584,  1586,  1588,  1593,  1595,  1597,
    1600,  1602,  1606,  1608,  1611,  1613,  1615,  1617,  1619,  1621,
    1622,  1627,  1628,  1632,  1634,  1639,  1641,  1643,  1646,  1648,
    1652,  1654,  1657,  1661,  1663,  1665,  1666,  1669,  1671,  1673,
    1675,  1677,  1682,  1684,  1686,  1689,  1691,  1695,  1697,  1700,
    1702,  1704,  1706,  1708,  1710,  1711,  1716,  1719,  1721,  1724,
    1726,  1729,  1731,  1734,  1736,  1739,  1741,  1744,  1746,  1749,
    1751,  1754,  1756,  1759,  1761,  1764,  1766,  1769,  1771,  1774,
    1776,  1778,  1780,  1783,  1785,  1787,  1789,  1791,  1793,  1795,
    1797,  1798
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   225,   270,   301,   373,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   191,    -1,   194,    -1,   197,    -1,   200,
      -1,   203,    -1,   206,    -1,   209,    -1,   212,    -1,   176,
     177,   181,    -1,    88,    -1,   178,    -1,   179,    -1,   178,
     179,    -1,   571,    -1,   565,    -1,   180,    -1,    24,     8,
       6,     8,    -1,   182,    -1,   183,    -1,    10,    89,    -1,
      11,    -1,    10,   184,    89,    -1,   185,    -1,   184,   185,
      -1,   186,   187,   190,    -1,   134,    -1,   188,    -1,    -1,
     188,   189,    -1,   568,    -1,   565,    -1,    10,   135,    -1,
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
     213,   214,   215,    -1,   108,    -1,    19,   581,     6,   581,
      -1,   216,    -1,   217,    -1,    10,   109,    -1,    11,    -1,
      10,   218,   109,    -1,   219,    -1,   218,   219,    -1,   220,
     221,   224,    -1,   106,    -1,   222,    -1,    -1,   222,   223,
      -1,   568,    -1,   577,    -1,   565,    -1,    10,   107,    -1,
      11,    -1,    -1,    50,    11,    -1,    50,    10,   226,    51,
      -1,    -1,   226,   227,    -1,   228,    -1,   231,    -1,   238,
      -1,   245,    -1,   252,    -1,   257,    -1,   229,   230,    -1,
     136,    -1,    10,     4,   137,    -1,    10,   137,    -1,    11,
      -1,   232,   233,   236,    -1,    68,    -1,   234,    -1,    -1,
     234,   235,    -1,   574,    -1,   565,    -1,    10,   237,    69,
      -1,     6,    -1,     7,    -1,   239,   240,   243,    -1,    70,
      -1,   241,    -1,    -1,   241,   242,    -1,   574,    -1,   565,
      -1,    10,   244,    71,    -1,     6,    -1,     7,    -1,   246,
     247,   250,    -1,    66,    -1,   248,    -1,    -1,   248,   249,
      -1,   574,    -1,   565,    -1,    10,   251,    67,    -1,     6,
      -1,     7,    -1,   253,   254,   255,    -1,    64,    -1,    -1,
     565,    -1,    10,   256,    65,    -1,     6,    -1,   258,   259,
     260,    -1,   108,    -1,    19,   581,     6,   581,    -1,   261,
      -1,   262,    -1,    10,   109,    -1,    11,    -1,    10,   263,
     109,    -1,   264,    -1,   263,   264,    -1,   265,   266,   269,
      -1,   106,    -1,   267,    -1,    -1,   267,   268,    -1,   568,
      -1,   577,    -1,   565,    -1,    10,   107,    -1,    11,    -1,
      -1,    52,    11,    -1,    52,    10,   271,    53,    -1,    -1,
     271,   272,    -1,   273,    -1,   276,    -1,   279,    -1,   282,
      -1,   285,    -1,   288,    -1,   274,   275,    -1,    82,    -1,
      10,     4,    83,    -1,    10,    83,    -1,    11,    -1,   277,
     278,    -1,    80,    -1,    10,     6,    81,    -1,    10,    81,
      -1,    11,    -1,   280,   281,    -1,   146,    -1,    10,     6,
     147,    -1,    10,   147,    -1,    11,    -1,   283,   284,    -1,
     140,    -1,    10,     4,   141,    -1,    10,   141,    -1,    11,
      -1,   286,   287,    -1,   122,    -1,    10,   580,   123,    -1,
      10,   123,    -1,    11,    -1,   289,   290,   291,    -1,   108,
      -1,    19,   581,     6,   581,    -1,   292,    -1,   293,    -1,
      10,   109,    -1,    11,    -1,    10,   294,   109,    -1,   295,
      -1,   294,   295,    -1,   296,   297,   300,    -1,   106,    -1,
     298,    -1,    -1,   298,   299,    -1,   568,    -1,   577,    -1,
     565,    -1,    10,   107,    -1,    11,    -1,    -1,    54,    11,
      -1,    54,    10,   302,    55,    -1,    -1,   302,   303,    -1,
     304,    -1,   307,    -1,   310,    -1,   313,    -1,   316,    -1,
     319,    -1,   334,    -1,   341,    -1,   348,    -1,   355,    -1,
     360,    -1,   305,   306,    -1,   130,    -1,    10,     4,   131,
      -1,    10,   131,    -1,    11,    -1,   308,   309,    -1,   132,
      -1,    10,     4,   133,    -1,    10,   133,    -1,    11,    -1,
     311,   312,    -1,   116,    -1,    10,     4,   117,    -1,    10,
     117,    -1,    11,    -1,   314,   315,    -1,    62,    -1,    10,
       4,    63,    -1,    10,    63,    -1,    11,    -1,   317,   318,
      -1,    86,    -1,    10,     4,    87,    -1,    10,    87,    -1,
      11,    -1,   320,   321,   322,    -1,   144,    -1,    25,     8,
       6,     8,    -1,   323,    -1,   324,    -1,    10,   145,    -1,
      11,    -1,    10,   325,   145,    -1,   326,    -1,   325,   326,
      -1,   327,   328,   330,    -1,   138,    -1,    -1,   328,   329,
      -1,   574,    -1,   571,    -1,   562,    -1,   565,    -1,   331,
      -1,   332,    -1,    10,   139,    -1,    11,    -1,    10,   333,
     139,    -1,     7,    -1,     6,    -1,   335,   336,   339,    -1,
     152,    -1,   337,    -1,    -1,   337,   338,    -1,   574,    -1,
     565,    -1,    10,   340,   153,    -1,     6,    -1,     7,    -1,
     342,   343,   346,    -1,   154,    -1,   344,    -1,    -1,   344,
     345,    -1,   574,    -1,   565,    -1,    10,   347,   155,    -1,
       6,    -1,     7,    -1,   349,   350,   353,    -1,   150,    -1,
     351,    -1,    -1,   351,   352,    -1,   574,    -1,   565,    -1,
      10,   354,   151,    -1,     6,    -1,     7,    -1,   356,   357,
     358,    -1,   148,    -1,    -1,   565,    -1,    10,   359,   149,
      -1,     6,    -1,   361,   362,   363,    -1,   108,    -1,    19,
     581,     6,   581,    -1,   364,    -1,   365,    -1,    10,   109,
      -1,    11,    -1,    10,   366,   109,    -1,   367,    -1,   366,
     367,    -1,   368,   369,   372,    -1,   106,    -1,   370,    -1,
      -1,   370,   371,    -1,   568,    -1,   577,    -1,   565,    -1,
      10,   107,    -1,    11,    -1,    -1,   374,   375,   382,    -1,
      56,    -1,   376,    -1,    -1,   376,   377,    -1,   378,    -1,
     379,    -1,   380,    -1,   381,    -1,    22,   581,     6,   581,
      -1,    27,   581,     6,   581,    -1,    13,   581,     6,   581,
      -1,    16,   581,     6,   581,    -1,   383,    -1,   384,    -1,
      10,    57,    -1,    11,    -1,    10,   385,   540,    57,    -1,
     386,    -1,   385,   386,    -1,   387,   388,   393,    -1,   124,
      -1,   389,    -1,    -1,   389,   390,    -1,   391,    -1,   392,
      -1,    28,   581,     6,   581,    -1,    42,     3,   581,    -1,
      10,   394,   410,   411,   460,   489,   518,   125,    -1,   395,
     396,   400,    -1,   130,    -1,   397,    -1,   398,    -1,   397,
     398,    -1,   571,    -1,   565,    -1,   399,    -1,    24,     8,
       6,     8,    -1,   401,    -1,   402,    -1,    10,   131,    -1,
      11,    -1,    10,   403,   131,    -1,   404,    -1,   403,   404,
      -1,   405,   406,   409,    -1,   134,    -1,   407,    -1,    -1,
     407,   408,    -1,   571,    -1,   565,    -1,    10,   135,    -1,
      11,    -1,    -1,    96,    10,     4,    97,    -1,    96,    10,
      97,    -1,    96,    11,    -1,    -1,   412,   413,   414,    -1,
     162,    -1,    -1,    21,   581,     6,   581,    -1,    11,    -1,
     415,    -1,    10,   416,   427,   437,   447,   163,    -1,    -1,
     417,   418,   419,    -1,   156,    -1,    26,   581,     6,   581,
      -1,   420,    -1,   421,    -1,    10,   157,    -1,    11,    -1,
      10,   422,   157,    -1,   423,    -1,   422,   423,    -1,   424,
     425,    10,   426,   161,    -1,   160,    -1,    29,   581,     6,
     581,    -1,     6,    -1,     7,    -1,    -1,   428,   429,   430,
      -1,   158,    -1,    26,   581,     6,   581,    -1,   431,    -1,
     432,    -1,    10,   159,    -1,    11,    -1,    10,   433,   159,
      -1,   434,    -1,   433,   434,    -1,   435,   436,    10,     4,
     161,    -1,   160,    -1,    29,   581,     6,   581,    -1,    -1,
     438,   439,   440,    -1,    72,    -1,    26,   581,     6,   581,
      -1,   441,    -1,   442,    -1,    10,    73,    -1,    11,    -1,
      10,   443,    73,    -1,   444,    -1,   443,   444,    -1,   445,
     446,    10,     4,   161,    -1,   160,    -1,    29,   581,     6,
     581,    -1,    -1,   447,   448,    -1,   449,   450,   454,    -1,
     106,    -1,   451,    -1,    -1,   451,   452,    -1,   453,    -1,
     577,    -1,   568,    -1,   565,    -1,    26,   581,     6,   581,
      -1,    11,    -1,    10,   455,   107,    -1,    -1,   455,   456,
      -1,   457,   458,   459,    -1,   160,    -1,    29,   581,     6,
     581,    -1,    10,   582,   161,    -1,    10,   161,    -1,    11,
      -1,    -1,   461,   462,   463,    -1,   100,    -1,    -1,    18,
     581,     6,   581,    -1,    11,    -1,   464,    -1,    10,   465,
     476,   101,    -1,    -1,   466,   467,   468,    -1,   156,    -1,
      15,   581,     6,   581,    -1,   469,    -1,   470,    -1,    10,
     157,    -1,    11,    -1,    10,   471,   157,    -1,   472,    -1,
     471,   472,    -1,   473,   474,    10,   475,    99,    -1,    98,
      -1,    -1,    29,   581,     6,   581,    -1,     6,    -1,     7,
      -1,    -1,   476,   477,    -1,   478,   479,   483,    -1,   106,
      -1,   480,    -1,    -1,   480,   481,    -1,   482,    -1,   577,
      -1,   568,    -1,   565,    -1,    15,   581,     6,   581,    -1,
      11,    -1,    10,   484,   107,    -1,    -1,   484,   485,    -1,
     486,   487,   488,    -1,    98,    -1,    29,   581,     6,   581,
      -1,    10,   582,    99,    -1,    10,    99,    -1,    11,    -1,
      -1,   490,   491,   492,    -1,    78,    -1,    -1,    17,   581,
       6,   581,    -1,    11,    -1,   493,    -1,    10,   494,   505,
      79,    -1,    -1,   495,   496,   497,    -1,    84,    -1,    12,
     581,     6,   581,    -1,   498,    -1,   499,    -1,    10,   157,
      -1,    11,    -1,    10,   500,    85,    -1,   501,    -1,   500,
     501,    -1,   502,   503,    10,   504,    77,    -1,    76,    -1,
      29,   581,     6,   581,    -1,     6,    -1,     7,    -1,    -1,
     505,   506,    -1,   507,   508,   512,    -1,   106,    -1,   509,
      -1,    -1,   509,   510,    -1,   511,    -1,   577,    -1,   568,
      -1,   565,    -1,    12,   581,     6,   581,    -1,    11,    -1,
      10,   513,   107,    -1,    -1,   513,   514,    -1,   515,   516,
     517,    -1,    76,    -1,    29,   581,     6,   581,    -1,    10,
     582,    77,    -1,    10,    77,    -1,    11,    -1,    -1,   519,
     520,   521,    -1,   112,    -1,    20,   581,     6,   581,    -1,
     522,    -1,   523,    -1,    10,   113,    -1,    11,    -1,    10,
     524,   113,    -1,   525,    -1,   524,   525,    -1,   526,   527,
     531,    -1,   110,    -1,   528,    -1,    -1,   528,   529,    -1,
     568,    -1,   562,    -1,   565,    -1,   530,    -1,    14,     8,
       6,     8,    -1,   532,    -1,   533,    -1,    10,   111,    -1,
      11,    -1,    10,   534,   111,    -1,   535,    -1,   534,   535,
      -1,   536,    -1,   537,    -1,   538,    -1,    60,    -1,    61,
      -1,    -1,    58,     5,   539,    59,    -1,    -1,   541,   542,
     543,    -1,   114,    -1,    23,   581,     6,   581,    -1,   544,
      -1,   545,    -1,    10,   115,    -1,    11,    -1,    10,   546,
     115,    -1,   547,    -1,   546,   547,    -1,   548,   549,   553,
      -1,   128,    -1,   550,    -1,    -1,   550,   551,    -1,   552,
      -1,   568,    -1,   562,    -1,   565,    -1,    14,     8,     6,
       8,    -1,   554,    -1,   555,    -1,    10,   129,    -1,    11,
      -1,    10,   556,   129,    -1,   557,    -1,   556,   557,    -1,
     558,    -1,   559,    -1,   560,    -1,    60,    -1,    61,    -1,
      -1,    58,     5,   561,    59,    -1,   563,   564,    -1,    30,
      -1,     3,   581,    -1,   581,    -1,   566,   567,    -1,    32,
      -1,     3,   581,    -1,   581,    -1,   569,   570,    -1,    34,
      -1,     3,   581,    -1,   581,    -1,   572,   573,    -1,    36,
      -1,     3,   581,    -1,   581,    -1,   575,   576,    -1,    38,
      -1,     3,   581,    -1,   581,    -1,   578,   579,    -1,    40,
      -1,     3,   581,    -1,   581,    -1,     6,    -1,     7,    -1,
     584,     8,    -1,     4,    -1,     6,    -1,     7,    -1,   165,
      -1,   166,    -1,   167,    -1,   168,    -1,    -1,   584,   583,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   162,   162,   164,   165,   167,   167,   168,   170,   170,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   184,
     186,   199,   205,   205,   208,   216,   220,   223,   234,   238,
     243,   243,   245,   247,   247,   249,   253,   260,   265,   265,
     268,   272,   277,   277,   280,   282,   289,   291,   292,   294,
     296,   303,   305,   306,   308,   310,   317,   319,   320,   322,
     324,   331,   333,   334,   336,   338,   345,   347,   348,   350,
     352,   359,   361,   362,   364,   366,   373,   375,   376,   378,
     380,   386,   395,   399,   404,   404,   406,   408,   408,   410,
     414,   422,   427,   427,   430,   435,   439,   445,   445,   449,
     449,   450,   452,   452,   455,   456,   457,   458,   459,   460,
     463,   465,   472,   474,   475,   477,   479,   487,   489,   489,
     492,   504,   509,   512,   513,   516,   518,   526,   528,   528,
     531,   543,   548,   551,   552,   555,   557,   565,   567,   567,
     570,   586,   591,   594,   595,   598,   600,   607,   608,   613,
     616,   619,   621,   627,   636,   640,   645,   645,   647,   649,
     649,   651,   655,   663,   668,   668,   671,   676,   680,   686,
     686,   690,   690,   691,   693,   693,   696,   697,   698,   699,
     700,   701,   704,   706,   713,   724,   725,   727,   729,   736,
     738,   739,   741,   743,   750,   752,   753,   755,   757,   764,
     766,   767,   769,   771,   778,   780,   781,   784,   786,   792,
     801,   805,   810,   810,   812,   814,   814,   816,   820,   828,
     833,   833,   836,   841,   845,   851,   851,   854,   854,   855,
     857,   857,   860,   861,   862,   863,   864,   865,   866,   867,
     868,   869,   870,   873,   875,   882,   893,   894,   896,   898,
     905,   907,   908,   910,   912,   919,   921,   922,   924,   926,
     933,   935,   936,   938,   940,   947,   949,   950,   952,   954,
     960,   967,   971,   976,   976,   978,   980,   980,   982,   984,
     997,   997,  1000,  1012,  1018,  1028,  1031,  1031,  1033,  1033,
    1035,  1046,  1047,  1050,  1052,  1060,  1062,  1062,  1065,  1077,
    1082,  1085,  1086,  1089,  1091,  1099,  1101,  1101,  1104,  1116,
    1121,  1124,  1125,  1128,  1130,  1140,  1142,  1142,  1145,  1161,
    1166,  1169,  1170,  1173,  1175,  1183,  1184,  1189,  1192,  1196,
    1198,  1204,  1213,  1217,  1222,  1222,  1224,  1226,  1226,  1228,
    1232,  1240,  1245,  1245,  1248,  1253,  1257,  1263,  1263,  1266,
    1266,  1268,  1275,  1280,  1280,  1283,  1284,  1285,  1286,  1289,
    1299,  1307,  1315,  1324,  1328,  1333,  1333,  1335,  1337,  1337,
    1339,  1341,  1349,  1351,  1351,  1353,  1353,  1355,  1363,  1373,
    1379,  1381,  1388,  1393,  1393,  1396,  1410,  1413,  1415,  1426,
    1430,  1436,  1436,  1438,  1440,  1440,  1442,  1445,  1452,  1457,
    1457,  1460,  1469,  1475,  1475,  1478,  1479,  1482,  1483,  1486,
    1486,  1488,  1491,  1492,  1500,  1500,  1502,  1504,  1504,  1506,
    1508,  1517,  1521,  1527,  1527,  1529,  1531,  1531,  1533,  1539,
    1545,  1548,  1549,  1552,  1552,  1554,  1556,  1565,  1569,  1575,
    1575,  1577,  1579,  1579,  1581,  1588,  1594,  1597,  1597,  1599,
    1601,  1610,  1614,  1620,  1620,  1622,  1624,  1624,  1626,  1639,
    1645,  1648,  1648,  1650,  1656,  1664,  1671,  1671,  1674,  1675,
    1680,  1685,  1691,  1701,  1702,  1704,  1704,  1706,  1711,  1713,
    1719,  1723,  1724,  1727,  1727,  1729,  1733,  1734,  1742,  1742,
    1744,  1746,  1746,  1748,  1750,  1759,  1763,  1769,  1769,  1771,
    1774,  1774,  1776,  1782,  1789,  1789,  1792,  1793,  1797,  1797,
    1799,  1805,  1813,  1821,  1821,  1824,  1825,  1830,  1835,  1841,
    1851,  1852,  1854,  1854,  1856,  1861,  1863,  1868,  1871,  1872,
    1876,  1876,  1878,  1881,  1882,  1890,  1890,  1892,  1894,  1894,
    1896,  1899,  1908,  1912,  1918,  1918,  1920,  1922,  1922,  1924,
    1930,  1936,  1939,  1940,  1943,  1943,  1945,  1951,  1959,  1966,
    1966,  1969,  1970,  1975,  1980,  1986,  1996,  1997,  2000,  2000,
    2002,  2007,  2009,  2015,  2019,  2020,  2024,  2024,  2026,  2031,
    2040,  2044,  2049,  2049,  2051,  2053,  2053,  2055,  2059,  2068,
    2075,  2075,  2078,  2083,  2088,  2093,  2095,  2106,  2110,  2115,
    2115,  2117,  2119,  2119,  2121,  2126,  2130,  2133,  2133,  2136,
    2135,  2147,  2147,  2149,  2154,  2163,  2167,  2172,  2172,  2174,
    2176,  2176,  2178,  2182,  2191,  2198,  2198,  2201,  2202,  2206,
    2210,  2216,  2226,  2230,  2235,  2235,  2237,  2239,  2239,  2241,
    2246,  2250,  2252,  2252,  2255,  2254,  2263,  2265,  2272,  2273,
    2275,  2277,  2284,  2285,  2287,  2289,  2296,  2297,  2299,  2301,
    2308,  2309,  2311,  2313,  2320,  2321,  2323,  2325,  2332,  2333,
    2337,  2338,  2340,  2343,  2344,  2345,  2349,  2350,  2351,  2352,
    2354,  2355
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
  "generalOtherResultsAttributes", "generalOtherResultsContent",
  "generalOtherResultsEmpty", "generalOtherResultsBody",
  "generalOtherResultArray", "generalOtherResult",
  "generalOtherResultStart", "generalOtherAttributes",
  "generalOtherAttList", "generalOtherAtt", "generalOtherEnd",
  "systemElement", "systemContent", "systemChild", "systemInformation",
  "systemInformationStart", "systemInformationContent",
  "availableDiskSpace", "availableDiskSpaceStart",
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
  "currentJobCount", "currentJobCountStart", "currentJobCountContent",
  "totalJobsSoFar", "totalJobsSoFarStart", "totalJobsSoFarContent",
  "timeServiceStarted", "timeServiceStartedStart",
  "timeServiceStartedContent", "serviceUtilization",
  "serviceUtilizationStart", "serviceUtilizationContent",
  "serviceOtherResults", "serviceOtherResultsStart",
  "serviceOtherResultsAttributes", "serviceOtherResultsContent",
  "serviceOtherResultsEmpty", "serviceOtherResultsBody",
  "serviceOtherResultArray", "serviceOtherResult",
  "serviceOtherResultStart", "serviceOtherAttributes",
  "serviceOtherAttList", "serviceOtherAtt", "serviceOtherEnd",
  "jobElement", "jobContent", "jobChild", "jobStatus", "jobStatusStart",
  "jobStatusContent", "submitTime", "submitTimeStart", "submitTimeContent",
  "scheduledStartTime", "scheduledStartTimeStart",
  "scheduledStartTimeContent", "actualStartTime", "actualStartTimeStart",
  "actualStartTimeContent", "endTime", "endTimeStart", "endTimeContent",
  "timingInformation", "timingInformationStart",
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
  "variables", "variablesStart", "numberOfOtherVariableResults",
  "variablesContent", "variablesBody", "variableValues",
  "variableValuesStart", "numberOfVarATT", "variableValuesContent",
  "variableValuesEmpty", "variableValuesBody", "varValueArray", "varValue",
  "varValueStart", "varIdxATT", "varVal", "variableValuesString",
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
  "otherVarList", "otherVar", "otherVarStart", "otherVarIdxATT",
  "otherVarContent", "objectives", "objectivesStart",
  "numberOfOtherObjectiveResults", "objectivesContent", "objectivesBody",
  "objectiveValues", "objectiveValuesStart", "numberOfObjATT",
  "objectiveValuesContent", "objectiveValuesEmpty", "objectiveValuesBody",
  "objValueArray", "objValue", "objValueStart", "objIdxATT", "objVal",
  "otherObjectiveResultsArray", "otherObjectiveResult",
  "otherObjectiveResultStart", "otherObjectiveResultAttributes",
  "otherObjectiveResultAttList", "otherObjectiveResultATT",
  "numberOfOtherObjectiveResultsATT", "otherObjectiveResultContent",
  "otherObjList", "otherObj", "otherObjStart", "otherObjIdxATT",
  "otherObjContent", "constraints", "constraintsStart",
  "numberOfOtherConstraintResults", "constraintsContent",
  "constraintsBody", "dualValues", "dualValuesStart", "numberOfConATT",
  "dualValuesContent", "dualValuesEmpty", "dualValuesBody",
  "dualValueArray", "dualValue", "dualValueStart", "conIdxATT", "dualVal",
  "otherConstraintResultsArray", "otherConstraintResult",
  "otherConstraintResultStart", "otherConstraintResultAttributes",
  "otherConstraintResultAttList", "otherConstraintResultATT",
  "numberOfOtherConstraintResultATT", "otherConstraintResultContent",
  "otherConList", "otherCon", "otherConStart", "otherConIdxATT",
  "otherConContent", "otherSolutionResults", "otherSolutionResultsStart",
  "numberOfOtherSolutionResults", "otherSolutionResultsContent",
  "otherSolutionResultsEmpty", "otherSolutionResultsBody",
  "otherSolutionResultArray", "otherSolutionResult",
  "otherSolutionResultStart", "otherSolutionResultAttributes",
  "otherSolutionResultAttList", "otherSolutionResultAtt",
  "numberOfOtherSolutionResultItems", "otherSolutionResultContent",
  "otherSolutionResultEmpty", "otherSolutionResultBody",
  "otherSolutionResultItemArray", "otherSolutionResultItem",
  "otherSolutionResultItemContent", "otherSolutionResultItemEmpty",
  "otherSolutionResultItemBody", "@1", "otherSolverOutput",
  "otherSolverOutputStart", "numberOfSolverOutputsATT",
  "otherSolverOutputContent", "otherSolverOutputEmpty",
  "otherSolverOutputBody", "solverOutputArray", "solverOutput",
  "solverOutputStart", "solverOutputAttributes", "solverOutputAttList",
  "solverOutputAtt", "numberOfSolverOutputItems", "solverOutputContent",
  "solverOutputEmpty", "solverOutputBody", "solverOutputItemArray",
  "solverOutputItem", "solverOutputItemContent", "solverOutputItemEmpty",
  "solverOutputItemBody", "@2", "categoryAttribute",
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
       0,   169,   170,   171,   171,   172,   172,   172,   173,   173,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   175,
     176,   177,   178,   178,   179,   179,   179,   180,   181,   181,
     182,   182,   183,   184,   184,   185,   186,   187,   188,   188,
     189,   189,   190,   190,   191,   192,   193,   193,   193,   194,
     195,   196,   196,   196,   197,   198,   199,   199,   199,   200,
     201,   202,   202,   202,   203,   204,   205,   205,   205,   206,
     207,   208,   208,   208,   209,   210,   211,   211,   211,   212,
     213,   214,   215,   215,   216,   216,   217,   218,   218,   219,
     220,   221,   222,   222,   223,   223,   223,   224,   224,   225,
     225,   225,   226,   226,   227,   227,   227,   227,   227,   227,
     228,   229,   230,   230,   230,   231,   232,   233,   234,   234,
     235,   235,   236,   237,   237,   238,   239,   240,   241,   241,
     242,   242,   243,   244,   244,   245,   246,   247,   248,   248,
     249,   249,   250,   251,   251,   252,   253,   254,   254,   255,
     256,   257,   258,   259,   260,   260,   261,   261,   262,   263,
     263,   264,   265,   266,   267,   267,   268,   268,   268,   269,
     269,   270,   270,   270,   271,   271,   272,   272,   272,   272,
     272,   272,   273,   274,   275,   275,   275,   276,   277,   278,
     278,   278,   279,   280,   281,   281,   281,   282,   283,   284,
     284,   284,   285,   286,   287,   287,   287,   288,   289,   290,
     291,   291,   292,   292,   293,   294,   294,   295,   296,   297,
     298,   298,   299,   299,   299,   300,   300,   301,   301,   301,
     302,   302,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   304,   305,   306,   306,   306,   307,   308,
     309,   309,   309,   310,   311,   312,   312,   312,   313,   314,
     315,   315,   315,   316,   317,   318,   318,   318,   319,   320,
     321,   322,   322,   323,   323,   324,   325,   325,   326,   327,
     328,   328,   329,   329,   329,   329,   330,   330,   331,   331,
     332,   333,   333,   334,   335,   336,   337,   337,   338,   338,
     339,   340,   340,   341,   342,   343,   344,   344,   345,   345,
     346,   347,   347,   348,   349,   350,   351,   351,   352,   352,
     353,   354,   354,   355,   356,   357,   357,   358,   359,   360,
     361,   362,   363,   363,   364,   364,   365,   366,   366,   367,
     368,   369,   370,   370,   371,   371,   371,   372,   372,   373,
     373,   374,   375,   376,   376,   377,   377,   377,   377,   378,
     379,   380,   381,   382,   382,   383,   383,   384,   385,   385,
     386,   387,   388,   389,   389,   390,   390,   391,   392,   393,
     394,   395,   396,   397,   397,   398,   398,   398,   399,   400,
     400,   401,   401,   402,   403,   403,   404,   405,   406,   407,
     407,   408,   408,   409,   409,   410,   410,   410,   410,   411,
     411,   412,   413,   413,   414,   414,   415,   416,   416,   417,
     418,   419,   419,   420,   420,   421,   422,   422,   423,   424,
     425,   426,   426,   427,   427,   428,   429,   430,   430,   431,
     431,   432,   433,   433,   434,   435,   436,   437,   437,   438,
     439,   440,   440,   441,   441,   442,   443,   443,   444,   445,
     446,   447,   447,   448,   449,   450,   451,   451,   452,   452,
     452,   452,   453,   454,   454,   455,   455,   456,   457,   458,
     459,   459,   459,   460,   460,   461,   462,   462,   463,   463,
     464,   465,   465,   466,   467,   468,   468,   469,   469,   470,
     471,   471,   472,   473,   474,   474,   475,   475,   476,   476,
     477,   478,   479,   480,   480,   481,   481,   481,   481,   482,
     483,   483,   484,   484,   485,   486,   487,   488,   488,   488,
     489,   489,   490,   491,   491,   492,   492,   493,   494,   494,
     495,   496,   497,   497,   498,   498,   499,   500,   500,   501,
     502,   503,   504,   504,   505,   505,   506,   507,   508,   509,
     509,   510,   510,   510,   510,   511,   512,   512,   513,   513,
     514,   515,   516,   517,   517,   517,   518,   518,   519,   520,
     521,   521,   522,   522,   523,   524,   524,   525,   526,   527,
     528,   528,   529,   529,   529,   529,   530,   531,   531,   532,
     532,   533,   534,   534,   535,   536,   536,   537,   537,   539,
     538,   540,   540,   541,   542,   543,   543,   544,   544,   545,
     546,   546,   547,   548,   549,   550,   550,   551,   551,   551,
     551,   552,   553,   553,   554,   554,   555,   556,   556,   557,
     558,   558,   559,   559,   561,   560,   562,   563,   564,   564,
     565,   566,   567,   567,   568,   569,   570,   570,   571,   572,
     573,   573,   574,   575,   576,   576,   577,   578,   579,   579,
     580,   580,   581,   582,   582,   582,   583,   583,   583,   583,
     584,   584
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
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       2,     4,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     2,     1,     3,     1,     1,     0,     2,
       1,     1,     3,     1,     1,     3,     1,     1,     0,     2,
       1,     1,     3,     1,     1,     3,     1,     1,     0,     2,
       1,     1,     3,     1,     1,     3,     1,     0,     1,     3,
       1,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     2,
       1,     0,     2,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     2,     1,     2,     1,     3,
       2,     1,     2,     1,     3,     2,     1,     2,     1,     3,
       2,     1,     2,     1,     3,     2,     1,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     4,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     2,     1,     2,     1,
       3,     2,     1,     2,     1,     3,     2,     1,     2,     1,
       3,     2,     1,     2,     1,     3,     2,     1,     3,     1,
       4,     1,     1,     2,     1,     3,     1,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     1,     3,     1,     0,     1,     3,     1,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     4,
       4,     4,     4,     1,     1,     2,     1,     4,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     4,     3,     8,
       3,     1,     1,     1,     2,     1,     1,     1,     4,     1,
       1,     2,     1,     3,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     2,     1,     0,     4,     3,     2,     0,
       3,     1,     0,     4,     1,     1,     6,     0,     3,     1,
       4,     1,     1,     2,     1,     3,     1,     2,     5,     1,
       4,     1,     1,     0,     3,     1,     4,     1,     1,     2,
       1,     3,     1,     2,     5,     1,     4,     0,     3,     1,
       4,     1,     1,     2,     1,     3,     1,     2,     5,     1,
       4,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     4,     1,     3,     0,     2,     3,     1,     4,
       3,     2,     1,     0,     3,     1,     0,     4,     1,     1,
       4,     0,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     5,     1,     0,     4,     1,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     3,     0,     2,     3,     1,     4,     3,     2,     1,
       0,     3,     1,     0,     4,     1,     1,     4,     0,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     5,
       1,     4,     1,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     4,     1,     3,     0,     2,
       3,     1,     4,     3,     2,     1,     0,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     4,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     0,
       4,     0,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     0,     4,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    99,     4,
       8,     6,     0,   171,     0,   102,   100,     0,   227,     7,
      20,    60,    65,    45,    80,    55,    50,    70,    75,     9,
      10,     0,    11,     0,    12,     0,    13,     0,    14,     0,
      15,     0,    16,     0,    17,     0,    18,     0,     0,   174,
     172,     0,   349,     0,   651,   659,     0,    21,    22,    26,
      25,   680,    24,   680,     0,    48,    44,     0,    53,    49,
       0,    58,    54,     0,    63,    59,     0,    68,    64,     0,
      73,    69,     0,    78,    74,   680,     0,   101,   146,   136,
     116,   126,   152,   111,   103,   104,     0,   105,   118,   106,
     128,   107,   138,   108,   147,   109,     0,     0,   230,   228,
     351,     0,   353,     0,     0,    31,    19,    28,    29,    23,
     680,   650,   653,     0,   680,   658,   661,     0,    47,     0,
      52,     0,    57,     0,    62,     0,    67,     0,    72,     0,
      77,     0,     0,    85,    79,    82,    83,     0,   114,   110,
       0,   117,     0,   127,     0,   137,     0,   148,   680,     0,
     173,   188,   183,   208,   203,   198,   193,   175,   176,     0,
     177,     0,   178,     0,   179,     0,   180,     0,   181,     0,
       0,     2,     0,   352,     0,    30,    36,     0,    33,    38,
     652,   672,   676,   677,   678,   679,   681,   660,    46,    51,
      56,    61,    66,    71,    76,   680,    90,    84,     0,    87,
      92,     0,   113,     0,   115,   663,   119,   121,   120,   680,
       0,   125,   129,   131,   130,     0,   135,   139,   141,   140,
       0,   145,     0,     0,   157,   151,   154,   155,     0,   186,
     182,     0,   191,   187,     0,   196,   192,     0,   201,   197,
       0,   206,   202,   680,     0,   229,   259,   264,   330,   254,
     244,   249,   269,   324,   314,   294,   304,   231,   232,     0,
     233,     0,   234,     0,   235,     0,   236,     0,   237,     0,
     238,   296,   239,   306,   240,   316,   241,   325,   242,     0,
       0,   366,   350,   363,   364,   680,   680,   680,   680,   354,
     355,   356,   357,   358,    27,    32,    34,     0,    37,    81,
      86,    88,     0,    91,   112,   123,   124,     0,   680,   662,
     665,   133,   134,     0,   143,   144,     0,   150,     0,   680,
     162,   156,     0,   159,   164,     0,   185,     0,   190,     0,
     195,     0,   200,   670,   671,   205,     0,     0,     0,   213,
     207,   210,   211,     0,   247,   243,     0,   252,   248,     0,
     257,   253,     0,   262,   258,     0,   267,   263,     0,     0,
       0,   295,     0,   305,     0,   315,     0,   326,   680,     0,
     365,   371,   611,   368,   373,     0,     0,     0,     0,     0,
      43,    35,   655,    39,    41,    40,   680,     0,    98,    89,
     667,    93,    96,    94,    95,   680,   122,   664,   132,   142,
     149,   153,   158,   160,     0,   163,   184,   189,   194,   199,
     204,   680,   218,   212,     0,   215,   220,     0,   246,     0,
     251,     0,   256,     0,   261,     0,   266,     0,     0,   274,
     268,   271,   272,     0,   293,   297,   299,   298,     0,   303,
     307,   309,   308,     0,   313,   317,   319,   318,     0,   323,
       0,     0,   335,   329,   332,   333,   613,   369,     0,     0,
       0,   372,   680,   680,   680,   680,    42,   680,   654,   657,
      97,   680,   666,   669,     0,   170,   161,   165,   168,   166,
     167,   209,   214,   216,     0,   219,   245,   250,   255,   260,
     265,     0,   279,   273,     0,   276,   280,   301,   302,     0,
     311,   312,     0,   321,   322,     0,   328,     0,   680,   340,
     334,     0,   337,   342,   367,   680,     0,     0,   370,   680,
       0,   374,   375,   376,   361,   362,   359,   360,   656,   668,
     169,     0,   226,   217,   221,   224,   222,   223,   270,   275,
     277,     0,   300,   310,   320,   327,   331,   336,   338,     0,
     341,     0,     0,   618,   612,   615,   616,   381,   405,     0,
       0,   680,   225,     0,   289,   647,   281,   278,   286,   287,
     284,   680,   285,   283,   282,     0,   348,   339,   343,   346,
     344,   345,   680,   617,   623,     0,   620,   625,     0,   409,
       0,     0,   382,   383,   387,   386,   385,   680,   378,   292,
     291,   288,     0,   680,   646,   649,   347,   614,   619,   621,
       0,   624,     0,   408,   411,   483,   412,     0,     0,   392,
     380,   389,   390,   384,   377,   290,   648,     0,   635,   622,
     632,   633,     0,   626,   627,   629,   630,   628,     0,   407,
     485,   530,   486,   680,     0,     0,   391,   397,     0,   394,
     399,     0,   642,   643,   634,     0,   637,   639,   640,   641,
       0,   406,   532,   576,   533,   680,     0,     0,   417,   414,
     410,   415,   388,   393,   395,     0,   398,   644,   636,   638,
       0,   578,     0,     0,   680,     0,     0,   491,   488,   484,
     489,   680,   419,   433,     0,     0,   404,   396,   400,   402,
     401,     0,   631,   379,   680,     0,     0,   538,   535,   531,
     536,   680,   493,   508,     0,   413,   435,   447,     0,   680,
       0,   403,   645,     0,     0,   583,   577,   580,   581,   680,
     540,   554,     0,   487,     0,   680,     0,   449,   461,     0,
     680,     0,     0,     0,   424,   418,   421,   422,   680,   588,
     582,     0,   585,   590,   534,     0,   680,     0,   490,   511,
     509,   513,     0,     0,   498,   492,   495,   496,     0,   680,
       0,     0,     0,   440,   434,   437,   438,   680,   423,   429,
       0,   426,     0,   579,   584,   586,     0,   589,   537,   557,
     555,   559,     0,     0,   545,   539,   542,   543,     0,   512,
     680,   503,   497,     0,   500,   504,   464,   416,   462,   466,
       0,     0,   454,   448,   451,   452,   680,   439,   445,     0,
     442,     0,   420,   425,   427,   680,     0,     0,   600,   587,
     597,   598,     0,   591,   595,   593,   594,   592,     0,   558,
     680,   550,   544,     0,   547,     0,   522,   520,   510,   680,
     514,   515,   518,   517,   516,   494,   499,   501,   680,     0,
       0,   465,   680,   453,   459,     0,   456,     0,   436,   441,
     443,   680,     0,     0,     0,     0,   607,   608,   599,     0,
     602,   604,   605,   606,     0,   568,   566,   556,   680,   560,
     561,   564,   563,   562,   541,   546,   548,   680,     0,     0,
       0,     0,     0,   475,   473,   463,   680,   467,   468,   471,
     470,   469,   450,   455,   457,   680,     0,     0,     0,   680,
     431,   432,     0,   609,   601,   603,     0,     0,     0,     0,
       0,   525,   521,   523,     0,   680,   680,   506,   507,     0,
       0,     0,     0,     0,   680,     0,   430,   428,     0,   596,
     571,   567,   569,     0,   680,   680,   552,   553,     0,   680,
       0,   519,   505,   502,   474,   478,   476,     0,   680,   680,
       0,   446,   444,   610,   680,     0,   565,   551,   549,     0,
       0,   529,   524,   680,     0,   472,   460,   458,     0,     0,
     575,   570,   680,   673,   674,   675,   528,     0,     0,     0,
     482,   477,   680,   574,     0,   526,   527,   680,   481,     0,
     572,   573,   479,   480
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    31,    56,    57,
      58,    59,   116,   117,   118,   187,   188,   189,   307,   308,
     393,   391,    32,    33,    66,    34,    35,    69,    36,    37,
      72,    38,    39,    75,    40,    41,    78,    42,    43,    81,
      44,    45,    84,    46,    47,    86,   144,   145,   146,   208,
     209,   210,   312,   313,   401,   399,    13,    48,    94,    95,
      96,   149,    97,    98,   150,   151,   216,   214,   317,    99,
     100,   152,   153,   222,   221,   323,   101,   102,   154,   155,
     227,   226,   326,   103,   104,   156,   231,   328,   105,   106,
     159,   235,   236,   237,   332,   333,   334,   414,   415,   487,
     486,    18,   107,   167,   168,   169,   240,   170,   171,   243,
     172,   173,   246,   174,   175,   249,   176,   177,   252,   178,
     179,   254,   350,   351,   352,   424,   425,   426,   494,   495,
     544,   543,    52,   180,   267,   268,   269,   355,   270,   271,
     358,   272,   273,   361,   274,   275,   364,   276,   277,   367,
     278,   279,   369,   440,   441,   442,   504,   505,   506,   551,
     576,   577,   578,   579,   612,   280,   281,   370,   371,   445,
     444,   509,   282,   283,   372,   373,   450,   449,   512,   284,
     285,   374,   375,   455,   454,   515,   286,   287,   376,   459,
     517,   288,   289,   379,   463,   464,   465,   521,   522,   523,
     559,   560,   588,   587,   111,   112,   182,   183,   299,   300,
     301,   302,   303,   292,   293,   294,   382,   383,   384,   470,
     471,   531,   532,   533,   528,   568,   569,   601,   602,   603,
     604,   630,   631,   632,   658,   659,   660,   685,   686,   708,
     707,   599,   625,   626,   654,   680,   681,   703,   704,   730,
     755,   756,   757,   790,   791,   792,   836,   932,   727,   728,
     751,   784,   785,   786,   829,   830,   831,   882,   748,   749,
     780,   823,   824,   825,   875,   876,   877,   926,   778,   818,
     819,   870,   871,   917,   918,   915,   950,   976,   977,   994,
    1011,   651,   652,   676,   699,   700,   723,   724,   746,   775,
     776,   777,   813,   814,   815,   869,   949,   744,   770,   771,
     808,   809,   860,   861,   858,   909,   943,   944,   970,   992,
     673,   674,   695,   719,   720,   741,   742,   767,   805,   806,
     807,   853,   854,   855,   908,   968,   765,   800,   801,   848,
     849,   899,   900,   897,   937,   962,   963,   985,  1001,   692,
     693,   715,   736,   737,   738,   761,   762,   763,   796,   797,
     843,   844,   839,   840,   841,   889,   890,   891,   892,   893,
     958,   468,   469,   526,   564,   565,   566,   595,   596,   597,
     620,   621,   643,   644,   639,   640,   641,   665,   666,   667,
     668,   669,   711,   580,   581,   614,    60,    61,   121,   395,
     396,   478,    62,    63,   125,   218,   219,   319,   404,   405,
     482,   346,   122,  1007,   196,   123
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -823
static const yytype_int16 yypact[] =
{
      50,    34,   115,   131,  -823,   182,  -823,   273,   113,  -823,
    -823,  -823,   275,   149,    -9,  -823,  -823,   277,   166,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,   185,  -823,   279,  -823,   281,  -823,   283,  -823,   285,
    -823,   287,  -823,   289,  -823,   291,  -823,   223,    46,  -823,
    -823,   293,   198,   255,  -823,  -823,   295,   185,  -823,  -823,
    -823,   278,  -823,   338,    22,  -823,  -823,    24,  -823,  -823,
      20,  -823,  -823,    38,  -823,  -823,    37,  -823,  -823,    19,
    -823,  -823,     5,  -823,  -823,  -823,   297,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,   300,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,   325,  -823,   313,   -17,  -823,  -823,
    -823,   348,  -823,   332,   -56,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,    -1,  -823,  -823,  -823,   272,  -823,   280,
    -823,   294,  -823,   340,  -823,   346,  -823,   290,  -823,   299,
    -823,   437,   -32,  -823,  -823,  -823,  -823,     6,  -823,  -823,
     434,   213,   435,   213,   436,   213,   438,  -823,  -823,   302,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   306,
    -823,   308,  -823,   310,  -823,   312,  -823,   314,  -823,   428,
     -24,  -823,   316,   214,   441,  -823,  -823,   -41,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   119,  -823,
    -823,   315,  -823,   322,  -823,  -823,  -823,  -823,  -823,   448,
     324,  -823,  -823,  -823,  -823,   328,  -823,  -823,  -823,  -823,
     447,  -823,   450,   141,  -823,  -823,  -823,  -823,    54,  -823,
    -823,    69,  -823,  -823,     2,  -823,  -823,    11,  -823,  -823,
      12,  -823,  -823,  -823,   326,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   329,
    -823,   333,  -823,   335,  -823,   337,  -823,   339,  -823,   432,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,   325,  -823,   442,
      33,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,   341,   237,  -823,
    -823,  -823,   343,   206,  -823,  -823,  -823,   385,  -823,  -823,
    -823,  -823,  -823,   392,  -823,  -823,   397,  -823,   400,  -823,
    -823,  -823,   143,  -823,  -823,   377,  -823,   386,  -823,   323,
    -823,   330,  -823,  -823,  -823,  -823,   350,   463,   147,  -823,
    -823,  -823,  -823,    13,  -823,  -823,     8,  -823,  -823,    21,
    -823,  -823,    39,  -823,  -823,    31,  -823,  -823,   464,   345,
     465,   213,   466,   213,   467,   213,   468,  -823,  -823,   349,
    -823,  -823,   -65,  -823,  -823,   473,   474,   475,   476,   352,
    -823,  -823,  -823,  -823,  -823,  -823,   471,   379,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,   480,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,   351,   206,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,   151,  -823,  -823,   353,  -823,   355,
    -823,   373,  -823,   426,  -823,   404,  -823,   486,    17,  -823,
    -823,  -823,  -823,   357,  -823,  -823,  -823,  -823,   359,  -823,
    -823,  -823,  -823,   361,  -823,  -823,  -823,  -823,   487,  -823,
     488,   152,  -823,  -823,  -823,  -823,  -823,  -823,   439,   472,
     489,    27,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,   391,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,   360,   206,  -823,  -823,  -823,  -823,
    -823,   492,  -823,  -823,    99,  -823,  -823,  -823,  -823,   354,
    -823,  -823,   347,  -823,  -823,   358,  -823,   356,  -823,  -823,
    -823,   153,  -823,  -823,  -823,  -823,   362,   381,  -823,  -823,
     500,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,   399,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,   164,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   364,
     206,   498,   -64,  -823,  -823,  -823,  -823,  -823,   414,   207,
     506,  -823,  -823,    14,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,   510,  -823,  -823,  -823,   407,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,   -55,  -823,  -823,   366,   363,
     507,   368,   207,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,   383,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
     370,   174,    28,  -823,  -823,   416,   496,   513,   133,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,    40,  -823,  -823,
    -823,  -823,   515,  -823,  -823,  -823,  -823,  -823,   430,  -823,
    -823,   443,   508,  -823,   372,   516,  -823,  -823,   134,  -823,
    -823,   523,  -823,  -823,  -823,   100,  -823,  -823,  -823,  -823,
     524,  -823,  -823,   419,   517,  -823,   374,   526,   384,  -823,
    -823,  -823,  -823,  -823,  -823,   376,   148,  -823,  -823,  -823,
     525,  -823,   410,   518,  -823,   378,   530,   390,  -823,  -823,
    -823,  -823,  -823,   394,   519,   406,  -823,  -823,  -823,  -823,
    -823,   483,  -823,  -823,  -823,   380,   533,   459,  -823,  -823,
    -823,  -823,  -823,  -823,   532,  -823,  -823,   477,   522,  -823,
     382,  -823,  -823,   545,   165,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,   541,  -823,   109,  -823,   387,  -823,  -823,   528,
    -823,   389,   549,   116,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,   167,  -823,  -823,  -823,   -40,  -823,   393,  -823,  -823,
    -823,  -823,   550,   -61,  -823,  -823,  -823,  -823,   -50,  -823,
     395,   551,   248,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
     122,  -823,   529,  -823,  -823,  -823,   405,   184,  -823,  -823,
    -823,  -823,   554,   -30,  -823,  -823,  -823,  -823,   409,   163,
    -823,  -823,  -823,   -53,  -823,   534,  -823,  -823,  -823,  -823,
     555,   -26,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   262,
    -823,   535,  -823,  -823,  -823,  -823,   552,    10,  -823,  -823,
    -823,  -823,   557,  -823,  -823,  -823,  -823,  -823,   413,   159,
    -823,  -823,  -823,    -4,  -823,   537,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   558,
     415,   179,  -823,  -823,  -823,   -20,  -823,   538,  -823,  -823,
    -823,  -823,   559,   564,   421,   566,  -823,  -823,  -823,   112,
    -823,  -823,  -823,  -823,   567,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   562,    78,
     568,   569,   423,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,   570,   571,   572,  -823,
    -823,  -823,   417,  -823,  -823,  -823,   573,     0,   576,   577,
     425,  -823,  -823,  -823,   560,  -823,  -823,  -823,  -823,   485,
      29,   580,   581,   575,  -823,   431,  -823,  -823,   536,  -823,
    -823,  -823,  -823,   565,  -823,  -823,  -823,  -823,   511,  -823,
     424,  -823,  -823,  -823,  -823,  -823,  -823,   574,  -823,  -823,
     440,  -823,  -823,  -823,  -823,   427,  -823,  -823,  -823,   585,
      23,  -823,  -823,  -823,   429,  -823,  -823,  -823,   587,    82,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,   497,   591,     7,
    -823,  -823,  -823,  -823,   521,  -823,  -823,  -823,  -823,   444,
    -823,  -823,  -823,  -823
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
     542,  -823,  -823,  -823,  -823,  -823,   420,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
     396,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,   268,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,   178,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,   102,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,    87,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,   227,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,     9,
    -823,  -823,  -823,  -823,  -823,   -48,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -177,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -215,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -260,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -197,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -236,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -143,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -270,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,    25,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   -44,  -823,
    -823,  -823,  -823,  -616,  -823,  -823,  -101,  -823,  -823,  -312,
    -823,  -823,  -535,  -823,  -823,  -149,  -823,  -823,  -413,  -823,
    -823,  -823,   -63,  -822,  -823,  -823
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     126,   403,   490,   157,   224,   645,   229,   191,   339,   139,
     211,  1003,   429,  1004,  1005,   341,   583,   427,   343,   344,
     609,   610,   141,   137,   131,   431,   127,  1003,   129,  1004,
    1005,   255,   648,   185,   606,   435,   160,   811,   256,   798,
      19,   135,   133,   433,     4,   811,   851,   873,   305,   466,
     217,   593,   223,   923,   228,   529,   816,   190,   335,   381,
     618,   197,   257,   161,   594,   162,   799,   606,   885,   530,
     886,   887,   851,   594,   206,   337,   960,   207,   186,    20,
       5,   905,   547,    21,   258,    22,  1003,    23,  1004,  1005,
     380,   163,   259,   186,     1,   232,   812,    87,   661,    24,
     662,   663,   434,   489,   866,   164,   260,   961,   261,    25,
      88,    26,    89,   817,    90,     6,    91,    27,   436,   128,
     262,   888,  1006,   165,   263,   649,   264,   852,   265,   166,
     266,   134,   136,    28,   874,   345,   974,   336,   432,   132,
     874,   430,   309,   212,   428,   130,   138,   591,   140,   340,
     338,   710,   342,   611,    92,   502,   320,   381,   661,  1013,
     662,   663,   503,    12,   192,   193,   194,   195,  1018,   664,
     885,   898,   886,   887,   573,   574,   941,  1014,   859,     7,
      54,   845,    93,   546,    55,   942,   377,  1019,   642,   975,
     347,    54,     9,   392,   575,    54,    54,   392,   842,   400,
      55,    17,   215,   400,   575,   916,    54,   394,   392,    53,
     768,    54,   402,   392,   575,   769,    54,    54,   392,   400,
      51,    55,   447,   934,   452,   206,   457,   295,   310,   688,
     296,   600,   385,   386,   387,   388,   297,   502,    54,    54,
     392,   298,    85,    55,   549,    54,   400,   330,   590,   330,
     331,   215,   412,   422,   110,   407,   423,   422,   519,   519,
     492,   520,   557,   113,   656,   683,   411,   657,   657,    54,
     446,   392,   451,   788,   456,   759,   789,   759,   760,   833,
     794,   120,   789,    10,    11,    15,    16,    49,    50,    64,
      65,    67,    68,    70,    71,    73,    74,    76,    77,    79,
      80,    82,    83,   108,   109,   114,   115,   142,   143,   647,
     147,   148,   233,   234,   488,   460,   238,   239,   241,   242,
     244,   245,   247,   248,   250,   251,   290,   291,   315,   316,
     321,   322,   158,   479,   324,   325,   348,   349,   184,   353,
     354,   124,   483,   356,   357,   359,   360,   362,   363,   365,
     366,   389,   390,   397,   398,   438,   439,    54,   491,   461,
     462,   484,   485,   507,   508,   510,   511,   513,   514,   198,
     541,   542,   562,   563,   585,   586,   622,   623,   628,   629,
     637,   638,   678,   679,   697,   698,   705,   706,   717,   718,
     734,   735,   753,   754,   545,   181,   864,   773,   774,   782,
     783,   199,   584,   803,   804,   821,   822,   827,   828,   534,
     535,   536,   537,   200,   538,   837,   838,   203,   539,   856,
     857,   879,   828,   895,   896,   913,   914,   930,   931,   947,
     948,   966,   967,   201,   990,   991,   903,   999,  1000,  1009,
    1010,   202,   204,   205,   213,   220,   225,   253,   230,   304,
     582,   318,   314,   327,   406,   556,   329,   368,   921,   589,
     416,   378,   561,   408,   409,   410,   570,   417,   605,   421,
     418,   419,   437,   420,   477,   443,   448,   453,   458,   472,
     473,   474,   475,   481,   496,   847,   480,   476,   497,   499,
     498,   500,   501,   516,   518,   525,   524,   863,   540,   527,
     548,   605,   553,   571,   592,   555,   572,   552,   608,   554,
     598,   567,   607,   613,   616,   627,   650,   653,   615,   655,
     646,   672,   635,   670,   682,   624,   675,   671,   687,   617,
     690,   691,   701,   712,   694,   713,   721,   902,   714,   739,
     702,   731,   732,   740,   634,   729,   722,   745,   750,   747,
     636,   758,   726,   766,   779,   787,   810,   826,   835,   920,
     850,   872,   884,   868,   881,   894,   907,   925,   912,   928,
     929,   933,   940,   936,   945,   946,   955,   954,   957,   980,
     953,   959,   964,   965,   973,   709,   978,   979,   988,   969,
     677,  1002,   982,  1012,   984,   983,  1016,  1017,  1021,   119,
     413,   997,   493,   993,   311,  1023,   550,   306,   558,   467,
     684,   633,   696,   834,   880,   924,   867,   906,   795,   935,
     619,   689,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   716,     0,     0,     0,     0,     0,     0,   725,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   733,     0,     0,     0,     0,     0,     0,   743,     0,
       0,     0,     0,     0,     0,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   764,     0,     0,     0,
       0,     0,   772,     0,     0,     0,     0,   781,     0,     0,
       0,     0,     0,     0,     0,   793,   846,     0,     0,     0,
       0,     0,     0,   802,     0,     0,     0,     0,   862,     0,
       0,     0,     0,     0,     0,     0,   820,     0,     0,     0,
       0,     0,     0,     0,   832,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   865,   901,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   878,     0,     0,     0,     0,     0,     0,
     919,     0,   883,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   904,     0,     0,
       0,     0,     0,     0,     0,     0,   910,     0,     0,     0,
       0,     0,     0,     0,     0,   911,     0,     0,     0,   922,
       0,     0,     0,     0,     0,     0,     0,     0,   927,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   938,     0,     0,     0,     0,
       0,     0,     0,     0,   939,     0,     0,     0,     0,     0,
       0,     0,     0,   951,     0,     0,     0,     0,     0,     0,
       0,     0,   952,     0,     0,     0,   956,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   971,   972,     0,     0,     0,     0,     0,     0,
       0,   981,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   986,   987,     0,     0,     0,   989,     0,     0,     0,
       0,     0,     0,     0,     0,   995,   996,     0,     0,     0,
       0,   998,     0,     0,     0,     0,     0,     0,     0,     0,
    1008,     0,     0,     0,     0,     0,     0,     0,     0,  1015,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1020,
       0,     0,     0,     0,  1022
};

static const yytype_int16 yycheck[] =
{
      63,   313,   415,   104,   153,   621,   155,     8,     6,     4,
       4,     4,     4,     6,     7,     4,   551,     4,     6,     7,
       6,     7,    85,     4,     4,     4,     4,     4,     4,     6,
       7,    55,     4,    89,   569,     4,    53,    98,    62,    79,
      49,     4,     4,     4,    10,    98,    76,    73,    89,   114,
     151,   115,   153,    73,   155,    28,   106,   120,     4,   124,
     115,   124,    86,    80,   128,    82,   106,   602,    58,    42,
      60,    61,    76,   128,   106,     6,    76,   109,   134,    88,
      46,    85,   495,    92,   108,    94,     4,    96,     6,     7,
      57,   108,   116,   134,    44,   158,   157,    51,    58,   108,
      60,    61,    63,   415,   157,   122,   130,   107,   132,   118,
      64,   120,    66,   163,    68,     0,    70,   126,    87,    97,
     144,   111,    99,   140,   148,    97,   150,   157,   152,   146,
     154,    93,    95,   142,   160,   123,   107,    83,   117,   119,
     160,   133,   205,   137,   131,   121,   127,   560,   143,   147,
      81,   686,   141,   139,   108,   138,   219,   124,    58,    77,
      60,    61,   145,    50,   165,   166,   167,   168,   161,   129,
      58,    12,    60,    61,    10,    11,    98,   999,    15,    48,
      32,   797,   136,   495,    36,   107,   287,  1009,    14,   160,
     253,    32,    10,    34,    30,    32,    32,    34,    14,    40,
      36,    52,    38,    40,    30,    26,    32,   308,    34,    24,
     101,    32,   313,    34,    30,   106,    32,    32,    34,    40,
      54,    36,   371,   111,   373,   106,   375,    13,   109,   129,
      16,    24,   295,   296,   297,   298,    22,   138,    32,    32,
      34,    27,    19,    36,   145,    32,    40,   106,   560,   106,
     109,    38,   109,   106,    56,   318,   109,   106,   106,   106,
     109,   109,   109,     8,   131,   131,   329,   134,   134,    32,
     371,    34,   373,   157,   375,   110,   160,   110,   113,   157,
     113,     3,   160,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   621,
      10,    11,    10,    11,   415,   378,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,     6,     7,
       6,     7,    19,   396,     6,     7,    10,    11,     6,    10,
      11,     3,   405,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    32,   421,    10,
      11,    10,    11,     6,     7,     6,     7,     6,     7,    97,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   495,    47,   809,    10,    11,    10,
      11,   121,   551,    10,    11,    10,    11,   159,   160,   472,
     473,   474,   475,   119,   477,    10,    11,   127,   481,    10,
      11,   159,   160,    10,    11,    10,    11,     6,     7,     6,
       7,     6,     7,    93,    10,    11,   849,    10,    11,    10,
      11,    95,   143,     6,    10,    10,    10,    19,    10,     8,
     551,     3,   137,     6,    69,   518,     6,    25,   871,   560,
      83,    19,   525,    71,    67,    65,   529,    81,   569,     6,
     147,   141,     8,   123,     3,    10,    10,    10,    10,     6,
       6,     6,     6,     3,   131,   797,   107,   135,   133,    63,
     117,    87,     6,     6,     6,    23,    57,   809,   107,    10,
       8,   602,   155,     3,     6,   149,   107,   153,   571,   151,
      96,   130,     6,     3,   107,     8,   100,    21,   581,     6,
     621,    78,   139,     8,     8,   162,    18,    97,     5,   592,
       6,   112,     6,     8,    17,   125,     6,   849,    20,     6,
     156,   135,    59,    84,   607,    26,   156,    15,    26,    72,
     613,     6,   158,    12,    26,     6,     6,     6,    29,   871,
       6,     6,    10,    29,    29,     8,    29,    29,    10,    10,
       6,     5,    10,     6,     6,     6,     4,     6,   161,     4,
      10,     8,     6,     6,    99,   686,     6,     6,    77,    29,
     653,     6,   161,     6,    29,    59,    99,     6,    77,    57,
     332,   161,   424,    29,   208,   161,   504,   187,   521,   382,
     658,   602,   675,   790,   829,   875,   813,   853,   761,   889,
     595,   665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   694,    -1,    -1,    -1,    -1,    -1,    -1,   701,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   714,    -1,    -1,    -1,    -1,    -1,    -1,   721,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   729,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   739,    -1,    -1,    -1,
      -1,    -1,   745,    -1,    -1,    -1,    -1,   750,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   758,   797,    -1,    -1,    -1,
      -1,    -1,    -1,   766,    -1,    -1,    -1,    -1,   809,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   779,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   787,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   810,   849,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   826,    -1,    -1,    -1,    -1,    -1,    -1,
     871,    -1,   835,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   850,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   859,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   868,    -1,    -1,    -1,   872,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   881,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   898,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   907,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   916,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   925,    -1,    -1,    -1,   929,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   945,   946,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   954,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   964,   965,    -1,    -1,    -1,   969,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   978,   979,    -1,    -1,    -1,
      -1,   984,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     993,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1002,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1012,
      -1,    -1,    -1,    -1,  1017
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   225,   173,    10,    11,    52,   270,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   176,   191,   192,   194,   195,   197,   198,   200,   201,
     203,   204,   206,   207,   209,   210,   212,   213,   226,    10,
      11,    54,   301,    24,    32,    36,   177,   178,   179,   180,
     565,   566,   571,   572,    10,    11,   193,    10,    11,   196,
      10,    11,   199,    10,    11,   202,    10,    11,   205,    10,
      11,   208,    10,    11,   211,    19,   214,    51,    64,    66,
      68,    70,   108,   136,   227,   228,   229,   231,   232,   238,
     239,   245,   246,   252,   253,   257,   258,   271,    10,    11,
      56,   373,   374,     8,    10,    11,   181,   182,   183,   179,
       3,   567,   581,   584,     3,   573,   581,     4,    97,     4,
     121,     4,   119,     4,    93,     4,    95,     4,   127,     4,
     143,   581,    10,    11,   215,   216,   217,    10,    11,   230,
     233,   234,   240,   241,   247,   248,   254,   565,    19,   259,
      53,    80,    82,   108,   122,   140,   146,   272,   273,   274,
     276,   277,   279,   280,   282,   283,   285,   286,   288,   289,
     302,    47,   375,   376,     6,    89,   134,   184,   185,   186,
     581,     8,   165,   166,   167,   168,   583,   581,    97,   121,
     119,    93,    95,   127,   143,     6,   106,   109,   218,   219,
     220,     4,   137,    10,   236,    38,   235,   565,   574,   575,
      10,   243,   242,   565,   574,    10,   250,   249,   565,   574,
      10,   255,   581,    10,    11,   260,   261,   262,    10,    11,
     275,    10,    11,   278,    10,    11,   281,    10,    11,   284,
      10,    11,   287,    19,   290,    55,    62,    86,   108,   116,
     130,   132,   144,   148,   150,   152,   154,   303,   304,   305,
     307,   308,   310,   311,   313,   314,   316,   317,   319,   320,
     334,   335,   341,   342,   348,   349,   355,   356,   360,   361,
      10,    11,   382,   383,   384,    13,    16,    22,    27,   377,
     378,   379,   380,   381,     8,    89,   185,   187,   188,   581,
     109,   219,   221,   222,   137,     6,     7,   237,     3,   576,
     581,     6,     7,   244,     6,     7,   251,     6,   256,     6,
     106,   109,   263,   264,   265,     4,    83,     6,    81,     6,
     147,     4,   141,     6,     7,   123,   580,   581,    10,    11,
     291,   292,   293,    10,    11,   306,    10,    11,   309,    10,
      11,   312,    10,    11,   315,    10,    11,   318,    25,   321,
     336,   337,   343,   344,   350,   351,   357,   565,    19,   362,
      57,   124,   385,   386,   387,   581,   581,   581,   581,    10,
      11,   190,    34,   189,   565,   568,   569,    10,    11,   224,
      40,   223,   565,   568,   577,   578,    69,   581,    71,    67,
      65,   581,   109,   264,   266,   267,    83,    81,   147,   141,
     123,     6,   106,   109,   294,   295,   296,     4,   131,     4,
     133,     4,   117,     4,    63,     4,    87,     8,    10,    11,
     322,   323,   324,    10,   339,   338,   565,   574,    10,   346,
     345,   565,   574,    10,   353,   352,   565,   574,    10,   358,
     581,    10,    11,   363,   364,   365,   114,   386,   540,   541,
     388,   389,     6,     6,     6,     6,   135,     3,   570,   581,
     107,     3,   579,   581,    10,    11,   269,   268,   565,   568,
     577,   581,   109,   295,   297,   298,   131,   133,   117,    63,
      87,     6,   138,   145,   325,   326,   327,     6,     7,   340,
       6,     7,   347,     6,     7,   354,     6,   359,     6,   106,
     109,   366,   367,   368,    57,    23,   542,    10,   393,    28,
      42,   390,   391,   392,   581,   581,   581,   581,   581,   581,
     107,    10,    11,   300,   299,   565,   568,   577,     8,   145,
     326,   328,   153,   155,   151,   149,   581,   109,   367,   369,
     370,   581,    10,    11,   543,   544,   545,   130,   394,   395,
     581,     3,   107,    10,    11,    30,   329,   330,   331,   332,
     562,   563,   565,   571,   574,    10,    11,   372,   371,   565,
     568,   577,     6,   115,   128,   546,   547,   548,    96,   410,
      24,   396,   397,   398,   399,   565,   571,     6,   581,     6,
       7,   139,   333,     3,   564,   581,   107,   581,   115,   547,
     549,   550,    10,    11,   162,   411,   412,     8,    10,    11,
     400,   401,   402,   398,   581,   139,   581,    10,    11,   553,
     554,   555,    14,   551,   552,   562,   565,   568,     4,    97,
     100,   460,   461,    21,   413,     6,   131,   134,   403,   404,
     405,    58,    60,    61,   129,   556,   557,   558,   559,   560,
       8,    97,    78,   489,   490,    18,   462,   581,    10,    11,
     414,   415,     8,   131,   404,   406,   407,     5,   129,   557,
       6,   112,   518,   519,    17,   491,   581,    10,    11,   463,
     464,     6,   156,   416,   417,    10,    11,   409,   408,   565,
     571,   561,     8,   125,    20,   520,   581,    10,    11,   492,
     493,     6,   156,   465,   466,   581,   158,   427,   428,    26,
     418,   135,    59,   581,    10,    11,   521,   522,   523,     6,
      84,   494,   495,   581,   476,    15,   467,    72,   437,   438,
      26,   429,   581,    10,    11,   419,   420,   421,     6,   110,
     113,   524,   525,   526,   581,   505,    12,   496,   101,   106,
     477,   478,   581,    10,    11,   468,   469,   470,   447,    26,
     439,   581,    10,    11,   430,   431,   432,     6,   157,   160,
     422,   423,   424,   581,   113,   525,   527,   528,    79,   106,
     506,   507,   581,    10,    11,   497,   498,   499,   479,   480,
       6,    98,   157,   471,   472,   473,   106,   163,   448,   449,
     581,    10,    11,   440,   441,   442,     6,   159,   160,   433,
     434,   435,   581,   157,   423,    29,   425,    10,    11,   531,
     532,   533,    14,   529,   530,   562,   565,   568,   508,   509,
       6,    76,   157,   500,   501,   502,    10,    11,   483,    15,
     481,   482,   565,   568,   577,   581,   157,   472,    29,   474,
     450,   451,     6,    73,   160,   443,   444,   445,   581,   159,
     434,    29,   436,   581,    10,    58,    60,    61,   111,   534,
     535,   536,   537,   538,     8,    10,    11,   512,    12,   510,
     511,   565,   568,   577,   581,    85,   501,    29,   503,   484,
     581,   581,    10,    10,    11,   454,    26,   452,   453,   565,
     568,   577,   581,    73,   444,    29,   446,   581,    10,     6,
       6,     7,   426,     5,   111,   535,     6,   513,   581,   581,
      10,    98,   107,   485,   486,     6,     6,     6,     7,   475,
     455,   581,   581,    10,     6,     4,   581,   161,   539,     8,
      76,   107,   514,   515,     6,     6,     6,     7,   504,    29,
     487,   581,   581,    99,   107,   160,   456,   457,     6,     6,
       4,   581,   161,    59,    29,   516,   581,   581,    77,   581,
      10,    11,   488,    29,   458,   581,   581,   161,   581,    10,
      11,   517,     6,     4,     6,     7,    99,   582,   581,    10,
      11,   459,     6,    77,   582,   581,    99,     6,   161,   582,
     581,    77,   581,   161
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
		parserData->numberOf = 0;
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
	parserData->kounter = 0;
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
		osrlerror( NULL, NULL, parserData, "more <substatus> elements than specified");
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

    {	
		osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute);
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

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other general results cannot be negative");
	osresult->setNumberOfOtherGeneralResults((yyvsp[(3) - (4)].ival));
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
;}
    break;

  case 94:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setGeneralOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 95:

    {	
		osresult->setGeneralOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 96:

    {	
		osresult->setGeneralOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 111:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 112:

    {osresult->setSystemInformation((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 116:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 120:

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

  case 121:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 123:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 124:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 126:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 130:

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

  case 131:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 133:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 134:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 136:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 140:

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

  case 141:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 143:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 144:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 146:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 148:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 150:

    {osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 152:

    {	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	;}
    break;

  case 153:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other system results cannot be negative");
	osresult->setNumberOfOtherSystemResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 154:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 155:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 161:

    {	parserData->kounter++;
;}
    break;

  case 162:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 163:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 166:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setSystemOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 167:

    {	
		osresult->setSystemOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 168:

    {	
		osresult->setSystemOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 183:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 184:

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

  case 188:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 189:

    {osresult->setCurrentJobCount((yyvsp[(2) - (3)].ival)); /* free($2); */  parserData->errorText = NULL;;}
    break;

  case 193:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 194:

    {osresult->setTotalJobsSoFar((yyvsp[(2) - (3)].ival)); /* free($2); */  parserData->errorText = NULL;;}
    break;

  case 198:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 199:

    {osresult->setTimeServiceStarted((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 203:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 204:

    {osresult->setServiceUtilization( parserData->tempVal);  parserData->errorText = NULL;;}
    break;

  case 208:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	;}
    break;

  case 209:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other service results cannot be negative");
	osresult->setNumberOfOtherServiceResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 210:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 211:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 217:

    {	parserData->kounter++;
;}
    break;

  case 218:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 219:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 222:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setServiceOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 223:

    {	
		osresult->setServiceOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 224:

    {	
		osresult->setServiceOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 244:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 245:

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

  case 249:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 250:

    {osresult->setJobSubmitTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 254:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 255:

    {osresult->setScheduledStartTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 259:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 260:

    {osresult->setActualStartTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 264:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 265:

    {osresult->setJobEndTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 269:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 270:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
;}
    break;

  case 271:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <time> element");
	;}
    break;

  case 272:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, "fewer <time> elements than specified");
	;}
    break;

  case 279:

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

  case 282:

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

  case 283:

    {	if (parserData->typeAttribute != "cpuTime"     &&
			parserData->typeAttribute != "elapsedTime" &&
 			parserData->typeAttribute != "other"   )     
			osrlerror(NULL, NULL, parserData, "time type not recognized");
	;}
    break;

  case 284:

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

  case 290:

    {	osresult->addTimingInformation(parserData->typeAttribute, parserData->categoryAttribute,
		parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue);       
	parserData->ivar++;
	parserData->timeType = "";
	parserData->timeCategory = "";
	parserData->timeUnit = "";
	parserData->timeDescription = "";      
;}
    break;

  case 291:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 292:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 294:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 298:

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

  case 299:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 301:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 302:

    {osresult->setUsedDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 304:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 308:

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

  case 309:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 311:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 312:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 314:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 318:

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

  case 319:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 321:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 322:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 324:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 326:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 328:

    {osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 330:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	;}
    break;

  case 331:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other job results cannot be negative");
	osresult->setNumberOfOtherJobResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 332:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 333:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 339:

    {	parserData->kounter++;
;}
    break;

  case 340:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 341:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 344:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setJobOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 345:

    {	
		osresult->setJobOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 346:

    {	
		osresult->setJobOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 351:

    {	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
;}
    break;

  case 352:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, "numberOfSolutions was never set");
;}
    break;

  case 359:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfSolutions = (yyvsp[(3) - (4)].ival); 
	osresult->setSolutionNumber((yyvsp[(3) - (4)].ival));
	parserData->solutionIdx = 0;
;}
    break;

  case 360:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	parserData->nVarPresent = true;	
	parserData->numberOfVariables = (yyvsp[(3) - (4)].ival); 
	osresult->setVariableNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 361:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	parserData->nConPresent = true;		
	parserData->numberOfConstraints = (yyvsp[(3) - (4)].ival); 
	osresult->setConstraintNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 362:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	parserData->nObjPresent = true;
	parserData->numberOfObjectives = (yyvsp[(3) - (4)].ival); 
	osresult->setObjectiveNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 363:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solution> element");
	;}
    break;

  case 364:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, "fewer <solution> elements than specified");
	;}
    break;

  case 371:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 377:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 378:

    {	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval);
	if (parserData->tempStr != "true" && parserData->tempStr != "false")
		osrlerror(NULL, NULL, parserData, "weightedobjectives must be true or false");
  	osresult->setSolutionWeightedObjectives(parserData->solutionIdx, parserData->tempStr);
;}
    break;

  case 379:

    {
		parserData->solutionIdx++;
	;}
    break;

  case 381:

    {	parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
	;}
    break;

  case 382:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
	;}
    break;

  case 385:

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

  case 386:

    {   osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute);
	;}
    break;

  case 388:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for solution status element");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solution substatuses cannot be negative");
    osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 389:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 390:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 396:

    {	parserData->kounter++; ;}
    break;

  case 397:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 398:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
;}
    break;

  case 401:

    {	
		if (parserData->typeAttribute != "stoppedByLimit"  &&
			parserData->typeAttribute != "stoppedByBounds" &&
			parserData->typeAttribute != "other" )
		osrlerror(NULL, NULL, parserData, "substatus type attribute has bad value");
		osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
										   parserData->typeAttribute);	
	;}
    break;

  case 402:

    {	
		osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
												  parserData->descriptionAttribute);
	;}
    break;

  case 406:

    {	osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
	;}
    break;

  case 411:

    {	parserData->numberOfOtherVariableResults = 0; ;}
    break;

  case 413:

    {	
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other variable results cannot be negative");
		osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->numberOfOtherVariableResults = (yyvsp[(3) - (4)].ival);
		parserData->iOther = 0;
	;}
    break;

  case 420:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
	osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 421:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 422:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 428:

    {	osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 429:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 430:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 431:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 432:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 436:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 437:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 438:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 444:

    {
	osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 			parserData->idx,         (yyvsp[(4) - (5)].sval));
	parserData->kounter++;
;}
    break;

  case 445:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 446:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 450:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	osresult->setNumberOfBasisVar(parserData->solutionIdx, parserData->numberOfVar);
;}
    break;

  case 451:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 452:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 458:

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

  case 459:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 460:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 463:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 464:

    {
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
;}
    break;

  case 465:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfVar attribute"); 
	;}
    break;

  case 469:

    {	
	 	osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 											  parserData->valueAttribute);
  ;}
    break;

  case 470:

    {	
	 	osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 											 parserData->nameAttribute);
  ;}
    break;

  case 471:

    {	
	 	osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 													parserData->descriptionAttribute);
  ;}
    break;

  case 472:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 477:

    { 	
	parserData->kounter++;
;}
    break;

  case 479:

    {	
 	osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 480:

    {	
	 	osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 485:

    {	parserData->numberOfOtherObjectiveResults = 0; ;}
    break;

  case 487:

    {
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other objective results cannot be negative");
		parserData->numberOfOtherObjectiveResults = (yyvsp[(3) - (4)].ival);
        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 494:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj);
	parserData->kounter = 0;
;}
    break;

  case 495:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <obj> element");
	;}
    break;

  case 496:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, "fewer <obj> elements than specified");
	;}
    break;

  case 502:

    {	osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 503:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, "more <obj> elements than specified");
	parserData->idx = -1;
;}
    break;

  case 505:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 506:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 507:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 510:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 511:

    {
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 512:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfObj attribute"); 
	;}
    break;

  case 516:

    {	
	 	osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 											   parserData->valueAttribute);
  ;}
    break;

  case 517:

    {	
	  	osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 											  parserData->nameAttribute);
  ;}
    break;

  case 518:

    {	
	 	osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
 													 parserData->descriptionAttribute);
  ;}
    break;

  case 519:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 524:

    {  
	parserData->kounter++;
;}
    break;

  case 526:

    {	osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 527:

    {	osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 532:

    {		parserData->numberOfOtherObjectiveResults = 0; ;}
    break;

  case 534:

    {
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other constraint results cannot be negative");
		parserData->numberOfOtherConstraintResults = (yyvsp[(3) - (4)].ival);
		osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 540:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 541:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon);
	parserData->kounter = 0;
;}
    break;

  case 542:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <con> element");
	;}
    break;

  case 543:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, "fewer <con> elements than specified");
	;}
    break;

  case 549:

    {	osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
						   parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 550:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, "more <con> elements than specified");
;}
    break;

  case 551:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 552:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 553:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 556:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 557:

    {
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
;}
    break;

  case 558:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfCon attribute"); 
	;}
    break;

  case 562:

    {	
	 	osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 												parserData->valueAttribute);
  ;}
    break;

  case 563:

    {	
	 	osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 											   parserData->nameAttribute);
  ;}
    break;

  case 564:

    {	
	 	osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 													  parserData->descriptionAttribute);
  ;}
    break;

  case 565:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 570:

    { 	
	parserData->kounter++;
;}
    break;

  case 572:

    {	
 	osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 573:

    {	
	 	osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 578:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 579:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solution results cannot be negative");
    osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->iOther = 0; 
;}
    break;

  case 580:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <otherSolutionResult> element");
	;}
    break;

  case 581:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <otherSolutionResult> elements than specified");
	;}
    break;

  case 587:

    {	parserData->iOther++;
;}
    break;

  case 588:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 589:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have numberOfItems attribute");
;}
    break;

  case 592:

    {	
		osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
											 parserData->nameAttribute);
	;}
    break;

  case 593:

    {	
		osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
												 parserData->categoryAttribute);
	;}
    break;

  case 594:

    {	
		osresult->setOtherSolutionResultDescription(parserData->solutionIdx, parserData->iOther,
											 parserData->descriptionAttribute);
	;}
    break;

  case 596:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
	osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, parserData->iOther,
												  parserData->numberOfItems);
	parserData->kounter = 0;
;}
    break;

  case 597:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	;}
    break;

  case 598:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	;}
    break;

  case 604:

    {	parserData->kounter++;
;}
    break;

  case 605:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
;}
    break;

  case 609:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
										 parserData->kounter, parserData->itemContent);
;}
    break;

  case 613:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 614:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solver outputs cannot be negative");
    osresult->setNumberOfSolverOutputs((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->iOther = 0; 
;}
    break;

  case 615:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solverOutput> element");
	;}
    break;

  case 616:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <solverOutput> elements than specified");
	;}
    break;

  case 622:

    {	parserData->iOther++;
;}
    break;

  case 623:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <solverOutput> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 624:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have numberOfItems attribute");
;}
    break;

  case 628:

    {	
		osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute);
	;}
    break;

  case 629:

    {	
		osresult->setSolverOutputCategory(parserData->iOther, parserData->categoryAttribute);
	;}
    break;

  case 630:

    {	
		osresult->setSolverOutputDescription(parserData->iOther, parserData->descriptionAttribute);
	;}
    break;

  case 631:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
	osresult->setSolverOutputNumberOfItems(parserData->iOther, parserData->numberOfItems);
	parserData->kounter = 0;
;}
    break;

  case 632:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	;}
    break;

  case 633:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	;}
    break;

  case 639:

    {	parserData->kounter++;
;}
    break;

  case 640:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
;}
    break;

  case 644:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, parserData->itemContent);
;}
    break;

  case 647:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 648:

    { parserData->categoryAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 649:

    { parserData->categoryAttribute = "";          ;}
    break;

  case 651:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 652:

    { parserData->descriptionAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 653:

    { parserData->descriptionAttribute = "";          ;}
    break;

  case 655:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 656:

    { parserData->nameAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 657:

    { parserData->nameAttribute = "";          ;}
    break;

  case 659:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 660:

    { parserData->typeAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 661:

    { parserData->typeAttribute = "";          ;}
    break;

  case 663:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 664:

    { parserData->unitAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 665:

    { parserData->unitAttribute = "";          ;}
    break;

  case 667:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 668:

    { parserData->valueAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 669:

    { parserData->valueAttribute = "";          ;}
    break;

  case 670:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 671:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 673:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 674:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 675:

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


