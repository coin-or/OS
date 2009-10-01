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
#define YYLAST   913

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  317
/* YYNRULES -- Number of rules.  */
#define YYNRULES  570
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1001

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
      53,    55,    58,    60,    62,    64,    68,    70,    74,    76,
      81,    83,    85,    88,    90,    94,    96,    99,   103,   104,
     107,   109,   111,   115,   119,   121,   123,   126,   128,   132,
     137,   141,   144,   149,   153,   156,   161,   165,   168,   173,
     177,   180,   185,   189,   192,   197,   201,   204,   209,   213,
     216,   220,   225,   227,   229,   232,   234,   238,   240,   243,
     247,   248,   251,   253,   255,   257,   261,   265,   269,   272,
     274,   275,   278,   288,   289,   294,   298,   301,   307,   308,
     311,   313,   315,   319,   323,   325,   327,   333,   334,   337,
     339,   341,   345,   349,   351,   353,   359,   360,   363,   365,
     367,   371,   375,   377,   379,   385,   386,   389,   393,   395,
     397,   398,   402,   407,   409,   411,   414,   416,   420,   422,
     425,   429,   430,   433,   435,   437,   439,   443,   447,   451,
     454,   456,   457,   460,   470,   471,   476,   480,   483,   484,
     489,   493,   496,   497,   502,   506,   509,   510,   515,   519,
     522,   523,   528,   532,   535,   536,   540,   545,   547,   549,
     552,   554,   558,   560,   563,   567,   568,   571,   573,   575,
     577,   581,   585,   589,   592,   594,   595,   598,   603,   604,
     607,   609,   611,   613,   615,   617,   619,   621,   623,   625,
     627,   629,   634,   638,   641,   646,   650,   653,   658,   662,
     665,   670,   674,   677,   682,   686,   689,   693,   698,   700,
     704,   705,   708,   712,   713,   716,   718,   720,   722,   724,
     728,   730,   734,   736,   740,   742,   746,   748,   750,   752,
     755,   757,   761,   762,   764,   766,   772,   773,   776,   778,
     780,   784,   788,   790,   792,   798,   799,   802,   806,   808,
     810,   816,   817,   820,   822,   824,   828,   832,   834,   836,
     842,   843,   846,   848,   850,   854,   858,   860,   862,   866,
     871,   873,   875,   878,   880,   884,   886,   889,   893,   894,
     897,   899,   901,   903,   907,   911,   915,   918,   920,   921,
     925,   926,   929,   932,   935,   938,   941,   945,   949,   953,
     957,   961,   963,   966,   967,   970,   974,   976,   977,   980,
     982,   984,   989,   993,  1002,  1006,  1008,  1011,  1015,  1017,
    1021,  1023,  1028,  1030,  1032,  1035,  1037,  1041,  1043,  1046,
    1050,  1051,  1054,  1056,  1058,  1062,  1066,  1068,  1070,  1073,
    1075,  1079,  1080,  1084,  1087,  1088,  1092,  1093,  1098,  1100,
    1102,  1104,  1111,  1112,  1118,  1123,  1124,  1127,  1133,  1138,
    1140,  1142,  1143,  1149,  1154,  1155,  1158,  1164,  1169,  1170,
    1176,  1181,  1182,  1185,  1191,  1196,  1197,  1200,  1201,  1206,
    1208,  1209,  1212,  1214,  1216,  1218,  1220,  1225,  1227,  1231,
    1233,  1237,  1241,  1243,  1247,  1248,  1251,  1257,  1259,  1264,
    1265,  1269,  1270,  1275,  1277,  1279,  1281,  1286,  1287,  1293,
    1298,  1299,  1302,  1308,  1313,  1315,  1317,  1318,  1321,  1325,
    1327,  1328,  1331,  1333,  1335,  1337,  1339,  1344,  1346,  1350,
    1352,  1356,  1360,  1362,  1366,  1367,  1370,  1376,  1378,  1383,
    1384,  1388,  1389,  1394,  1396,  1398,  1400,  1405,  1406,  1412,
    1417,  1418,  1421,  1427,  1432,  1434,  1436,  1437,  1440,  1444,
    1446,  1447,  1450,  1452,  1454,  1456,  1458,  1463,  1465,  1469,
    1471,  1475,  1479,  1481,  1485,  1486,  1489,  1495,  1497,  1502,
    1503,  1509,  1510,  1516,  1517,  1520,  1526,  1527,  1528,  1532,
    1534,  1536,  1538,  1540,  1545,  1547,  1551,  1555,  1557,  1561,
    1563,  1564,  1567,  1569,  1571,  1573,  1575,  1576,  1581,  1583,
    1584,  1588,  1593,  1595,  1599,  1600,  1603,  1609,  1610,  1611,
    1615,  1617,  1619,  1621,  1623,  1628,  1630,  1634,  1638,  1640,
    1644,  1646,  1647,  1650,  1652,  1654,  1656,  1658,  1659,  1664,
    1666,  1668,  1671,  1673,  1675,  1677,  1679,  1681,  1683,  1685,
    1686
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   213,   250,   269,   327,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   193,    -1,   194,    -1,   195,    -1,   196,
      -1,   197,    -1,   198,    -1,   199,    -1,   200,    -1,    88,
     176,   181,    -1,   177,    -1,   176,   177,    -1,   178,    -1,
     179,    -1,   180,    -1,    36,     3,   482,    -1,    37,    -1,
      32,     3,   482,    -1,    33,    -1,    24,     8,     6,     8,
      -1,   182,    -1,   183,    -1,    10,    89,    -1,    11,    -1,
      10,   184,    89,    -1,   185,    -1,   184,   185,    -1,   134,
     186,   190,    -1,    -1,   186,   187,    -1,   188,    -1,   189,
      -1,    34,     3,     8,    -1,    32,     3,     8,    -1,   191,
      -1,   192,    -1,    10,   135,    -1,    11,    -1,    10,     4,
     135,    -1,    96,    10,     4,    97,    -1,    96,    10,    97,
      -1,    96,    11,    -1,   120,    10,     4,   121,    -1,   120,
      10,   121,    -1,   120,    11,    -1,   118,    10,     4,   119,
      -1,   118,    10,   119,    -1,   118,    11,    -1,    92,    10,
       4,    93,    -1,    92,    10,    93,    -1,    92,    11,    -1,
      94,    10,     4,    95,    -1,    94,    10,    95,    -1,    94,
      11,    -1,   126,    10,     4,   127,    -1,   126,    10,   127,
      -1,   126,    11,    -1,   142,    10,     4,   143,    -1,   142,
      10,   143,    -1,   142,    11,    -1,   108,   201,   202,    -1,
      19,   482,     6,   482,    -1,   203,    -1,   204,    -1,    10,
     109,    -1,    11,    -1,    10,   205,   109,    -1,   206,    -1,
     205,   206,    -1,   106,   207,   212,    -1,    -1,   207,   208,
      -1,   209,    -1,   210,    -1,   211,    -1,    34,     3,   482,
      -1,    40,     3,   482,    -1,    32,     3,   482,    -1,    10,
     107,    -1,    11,    -1,    -1,    50,    11,    -1,    50,    10,
     214,   215,   221,   227,   233,   237,    51,    -1,    -1,   136,
      10,     4,   137,    -1,   136,    10,   137,    -1,   136,    11,
      -1,    68,   216,    10,   220,    69,    -1,    -1,   216,   217,
      -1,   218,    -1,   219,    -1,    38,     3,   482,    -1,    32,
       3,   482,    -1,     6,    -1,     7,    -1,    70,   222,    10,
     226,    71,    -1,    -1,   222,   223,    -1,   224,    -1,   225,
      -1,    38,     3,   482,    -1,    32,     3,   482,    -1,     6,
      -1,     7,    -1,    66,   228,    10,   232,    67,    -1,    -1,
     228,   229,    -1,   230,    -1,   231,    -1,    38,     3,   482,
      -1,    32,     3,   482,    -1,     6,    -1,     7,    -1,    64,
     234,    10,   236,    65,    -1,    -1,   234,   235,    -1,    32,
       3,   482,    -1,     6,    -1,     7,    -1,    -1,   108,   238,
     239,    -1,    19,   482,     6,   482,    -1,   240,    -1,   241,
      -1,    10,   109,    -1,    11,    -1,    10,   242,   109,    -1,
     243,    -1,   242,   243,    -1,   106,   244,   249,    -1,    -1,
     244,   245,    -1,   246,    -1,   247,    -1,   248,    -1,    34,
       3,   482,    -1,    40,     3,   482,    -1,    32,     3,   482,
      -1,    10,   107,    -1,    11,    -1,    -1,    52,    11,    -1,
      52,    10,   251,   252,   253,   254,   255,   256,    53,    -1,
      -1,    82,    10,     4,    83,    -1,    82,    10,    83,    -1,
      82,    11,    -1,    -1,    80,    10,     6,    81,    -1,    80,
      10,    81,    -1,    80,    11,    -1,    -1,   146,    10,     6,
     147,    -1,   146,    10,   147,    -1,   146,    11,    -1,    -1,
     140,    10,     4,   141,    -1,   140,    10,   141,    -1,   140,
      11,    -1,    -1,   122,    10,   481,   123,    -1,   122,    10,
     123,    -1,   122,    11,    -1,    -1,   108,   257,   258,    -1,
      19,   482,     6,   482,    -1,   259,    -1,   260,    -1,    10,
     109,    -1,    11,    -1,    10,   261,   109,    -1,   262,    -1,
     261,   262,    -1,   106,   263,   268,    -1,    -1,   263,   264,
      -1,   265,    -1,   266,    -1,   267,    -1,    34,     3,   482,
      -1,    40,     3,   482,    -1,    32,     3,   482,    -1,    10,
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
      38,     3,   482,    -1,    32,     3,   482,    -1,     6,    -1,
       7,    -1,   148,   299,    10,   301,   149,    -1,    -1,   299,
     300,    -1,    32,     3,   482,    -1,     6,    -1,     7,    -1,
     152,   303,    10,   307,   153,    -1,    -1,   303,   304,    -1,
     305,    -1,   306,    -1,    38,     3,   482,    -1,    32,     3,
     482,    -1,     6,    -1,     7,    -1,   154,   309,    10,   313,
     155,    -1,    -1,   309,   310,    -1,   311,    -1,   312,    -1,
      38,     3,   482,    -1,    32,     3,   482,    -1,     6,    -1,
       7,    -1,   108,   315,   316,    -1,    19,   482,     6,   482,
      -1,   317,    -1,   318,    -1,    10,   109,    -1,    11,    -1,
      10,   319,   109,    -1,   320,    -1,   319,   320,    -1,   106,
     321,   326,    -1,    -1,   321,   322,    -1,   323,    -1,   324,
      -1,   325,    -1,    34,     3,   482,    -1,    40,     3,   482,
      -1,    32,     3,   482,    -1,    10,   107,    -1,    11,    -1,
      -1,    56,   328,   334,    -1,    -1,   328,   329,    -1,   330,
     482,    -1,   331,   482,    -1,   332,   482,    -1,   333,   482,
      -1,    22,   482,     6,    -1,    27,   482,     6,    -1,    13,
     482,     6,    -1,    16,   482,     6,    -1,    10,   335,    57,
      -1,    11,    -1,   336,   464,    -1,    -1,   336,   337,    -1,
     338,   339,   343,    -1,   124,    -1,    -1,   339,   340,    -1,
     341,    -1,   342,    -1,    28,   482,     6,   482,    -1,    42,
       3,   482,    -1,    10,   344,   359,   360,   396,   421,   446,
     463,    -1,   130,   345,   347,    -1,   346,    -1,   345,   346,
      -1,    36,     3,   482,    -1,    37,    -1,    32,     3,   482,
      -1,    33,    -1,    24,     8,     6,     8,    -1,   348,    -1,
     349,    -1,    10,   131,    -1,    11,    -1,    10,   350,   131,
      -1,   351,    -1,   350,   351,    -1,   134,   352,   356,    -1,
      -1,   352,   353,    -1,   354,    -1,   355,    -1,    36,     3,
       8,    -1,    32,     3,     8,    -1,   357,    -1,   358,    -1,
      10,   135,    -1,    11,    -1,    10,     4,   135,    -1,    -1,
      96,     4,    97,    -1,    96,    97,    -1,    -1,   162,   361,
     362,    -1,    -1,    21,   482,     6,   482,    -1,   363,    -1,
     364,    -1,    11,    -1,    10,   365,   371,   376,   381,   163,
      -1,    -1,   156,   366,    10,   367,   157,    -1,    26,   482,
       6,   482,    -1,    -1,   367,   368,    -1,   160,   369,    10,
     370,   161,    -1,    29,   482,     6,   482,    -1,     6,    -1,
       7,    -1,    -1,   158,   372,    10,   373,   159,    -1,    26,
     482,     6,   482,    -1,    -1,   373,   374,    -1,   160,   375,
      10,     4,   161,    -1,    29,   482,     6,   482,    -1,    -1,
      72,   377,    10,   378,    73,    -1,    26,   482,     6,   482,
      -1,    -1,   378,   379,    -1,   160,   380,    10,     4,   161,
      -1,    29,   482,     6,   482,    -1,    -1,   381,   382,    -1,
      -1,   384,   385,   383,   391,    -1,   106,    -1,    -1,   385,
     386,    -1,   387,    -1,   388,    -1,   389,    -1,   390,    -1,
      26,   482,     6,   482,    -1,    41,    -1,    40,     3,   482,
      -1,    35,    -1,    34,     3,   482,    -1,    32,     3,   482,
      -1,    11,    -1,    10,   392,   107,    -1,    -1,   392,   393,
      -1,   394,   395,    10,   483,   161,    -1,   160,    -1,    29,
     482,     6,   482,    -1,    -1,   100,   397,   398,    -1,    -1,
      18,   482,     6,   482,    -1,   399,    -1,   400,    -1,    11,
      -1,    10,   401,   407,   101,    -1,    -1,   156,   402,    10,
     403,   157,    -1,    15,   482,     6,   482,    -1,    -1,   403,
     404,    -1,    98,   405,    10,   406,    99,    -1,    29,   482,
       6,   482,    -1,     6,    -1,     7,    -1,    -1,   407,   408,
      -1,   409,   410,   416,    -1,   106,    -1,    -1,   410,   411,
      -1,   412,    -1,   413,    -1,   414,    -1,   415,    -1,    15,
     482,     6,   482,    -1,    41,    -1,    40,     3,   482,    -1,
      35,    -1,    34,     3,   482,    -1,    32,     3,   482,    -1,
      11,    -1,    10,   417,   107,    -1,    -1,   417,   418,    -1,
     419,   420,    10,   483,    99,    -1,    98,    -1,    29,   482,
       6,   482,    -1,    -1,    78,   422,   423,    -1,    -1,    17,
     482,     6,   482,    -1,   424,    -1,   425,    -1,    11,    -1,
      10,   426,   432,    79,    -1,    -1,    84,   427,    10,   428,
      85,    -1,    12,   482,     6,   482,    -1,    -1,   428,   429,
      -1,    76,   430,    10,   431,    77,    -1,    29,   482,     6,
     482,    -1,     7,    -1,     6,    -1,    -1,   432,   433,    -1,
     434,   435,   441,    -1,   106,    -1,    -1,   435,   436,    -1,
     437,    -1,   438,    -1,   439,    -1,   440,    -1,    12,   482,
       6,   482,    -1,    41,    -1,    40,     3,   482,    -1,    35,
      -1,    34,     3,   482,    -1,    32,     3,   482,    -1,    11,
      -1,    10,   442,   107,    -1,    -1,   442,   443,    -1,   444,
     445,    10,   483,    77,    -1,    76,    -1,    29,   482,     6,
     482,    -1,    -1,   112,   447,    10,   449,   113,    -1,    -1,
      20,     8,     6,   448,     8,    -1,    -1,   449,   450,    -1,
     110,   451,    10,   458,   111,    -1,    -1,    -1,   451,   452,
     453,    -1,   454,    -1,   455,    -1,   456,    -1,   457,    -1,
      14,     8,     6,     8,    -1,    35,    -1,    34,     3,   482,
      -1,    30,     3,     8,    -1,    31,    -1,    32,     3,     8,
      -1,    33,    -1,    -1,   458,   459,    -1,   460,    -1,   461,
      -1,    60,    -1,    61,    -1,    -1,    58,     5,   462,    59,
      -1,   125,    -1,    -1,   114,   465,   466,    -1,    23,   482,
       6,   482,    -1,    11,    -1,    10,   467,   115,    -1,    -1,
     467,   468,    -1,   128,   469,    10,   476,   129,    -1,    -1,
      -1,   469,   470,   471,    -1,   472,    -1,   473,    -1,   474,
      -1,   475,    -1,    14,     8,     6,     8,    -1,    35,    -1,
      34,     3,     8,    -1,    30,     3,     8,    -1,    31,    -1,
      32,     3,     8,    -1,    33,    -1,    -1,   476,   477,    -1,
     478,    -1,   479,    -1,    60,    -1,    61,    -1,    -1,    58,
       5,   480,    59,    -1,     6,    -1,     7,    -1,   485,     8,
      -1,     4,    -1,     6,    -1,     7,    -1,   165,    -1,   166,
      -1,   167,    -1,   168,    -1,    -1,   485,   484,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   166,   167,   169,   169,   170,   172,   172,
     174,   174,   174,   174,   175,   175,   175,   175,   175,   178,
     180,   180,   183,   189,   195,   199,   200,   202,   203,   205,
     217,   217,   219,   219,   221,   225,   225,   227,   229,   229,
     231,   231,   233,   237,   241,   241,   243,   243,   245,   250,
     251,   252,   255,   256,   257,   260,   261,   262,   265,   266,
     267,   270,   271,   272,   275,   276,   277,   280,   281,   282,
     284,   286,   288,   288,   290,   290,   292,   294,   294,   296,
     298,   298,   300,   300,   300,   302,   304,   306,   308,   308,
     312,   312,   313,   316,   317,   318,   319,   321,   324,   324,
     326,   326,   328,   330,   333,   334,   336,   339,   339,   341,
     341,   343,   345,   348,   349,   351,   354,   354,   356,   356,
     358,   360,   363,   364,   367,   370,   370,   372,   375,   376,
     379,   379,   381,   383,   383,   385,   385,   387,   389,   389,
     391,   393,   393,   395,   395,   395,   397,   399,   401,   403,
     403,   407,   407,   408,   411,   412,   413,   414,   416,   417,
     418,   419,   421,   422,   423,   424,   426,   427,   428,   429,
     431,   432,   433,   434,   437,   437,   439,   441,   441,   443,
     443,   445,   447,   447,   449,   451,   451,   453,   453,   453,
     455,   457,   459,   461,   461,   464,   464,   465,   467,   467,
     469,   469,   469,   469,   469,   470,   470,   470,   470,   470,
     470,   473,   474,   475,   478,   479,   480,   483,   484,   485,
     488,   489,   490,   493,   494,   495,   498,   500,   506,   506,
     508,   508,   510,   512,   512,   514,   514,   514,   514,   516,
     517,   519,   520,   522,   523,   525,   526,   528,   528,   530,
     530,   532,   543,   547,   548,   551,   554,   554,   556,   556,
     558,   560,   563,   564,   567,   570,   570,   572,   575,   576,
     579,   582,   582,   584,   584,   586,   588,   591,   592,   594,
     597,   597,   599,   599,   601,   603,   606,   607,   611,   613,
     615,   615,   617,   617,   619,   621,   621,   623,   625,   625,
     627,   627,   627,   629,   631,   633,   635,   635,   639,   639,
     641,   641,   643,   644,   645,   646,   650,   651,   652,   653,
     656,   656,   658,   660,   660,   662,   669,   675,   675,   677,
     677,   679,   686,   689,   692,   694,   695,   697,   698,   699,
     700,   701,   704,   710,   716,   716,   718,   720,   720,   722,
     724,   724,   726,   726,   728,   732,   736,   736,   738,   738,
     740,   746,   747,   751,   757,   758,   760,   761,   771,   771,
     773,   775,   777,   777,   787,   794,   794,   796,   798,   801,
     805,   811,   812,   822,   829,   829,   831,   837,   841,   841,
     851,   858,   858,   860,   862,   867,   867,   870,   869,   876,
     884,   884,   886,   886,   886,   886,   888,   897,   900,   906,
     912,   918,   924,   925,   941,   941,   943,   957,   962,   966,
     967,   969,   970,   980,   980,   982,   984,   986,   986,   996,
    1000,  1000,  1002,  1004,  1007,  1011,  1017,  1017,  1019,  1022,
    1030,  1031,  1033,  1033,  1033,  1033,  1035,  1044,  1047,  1053,
    1059,  1065,  1072,  1073,  1095,  1095,  1097,  1112,  1117,  1120,
    1121,  1123,  1124,  1134,  1134,  1136,  1138,  1141,  1141,  1152,
    1157,  1157,  1159,  1161,  1164,  1168,  1174,  1174,  1176,  1179,
    1181,  1181,  1183,  1183,  1183,  1183,  1185,  1188,  1191,  1197,
    1203,  1209,  1215,  1216,  1219,  1219,  1221,  1237,  1242,  1246,
    1247,  1254,  1253,  1269,  1269,  1271,  1279,  1280,  1280,  1284,
    1284,  1284,  1284,  1286,  1299,  1305,  1313,  1316,  1319,  1322,
    1324,  1325,  1328,  1333,  1340,  1340,  1343,  1342,  1348,  1358,
    1358,  1360,  1362,  1362,  1364,  1364,  1366,  1374,  1376,  1375,
    1380,  1380,  1380,  1380,  1382,  1397,  1404,  1413,  1419,  1422,
    1428,  1430,  1431,  1433,  1438,  1444,  1444,  1447,  1446,  1452,
    1453,  1455,  1458,  1459,  1460,  1464,  1465,  1466,  1467,  1469,
    1470
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
  "solutionStatusAttList", "solutionStatusATT", "solutionStatusContent",
  "solutionStatusEmpty", "solutionStatusBody", "solutionSubstatusSEQ",
  "solutionSubstatus", "solutionSubstatusAttList", "solutionSubstatusATT",
  "solutionSubstatusTypeATT", "solutionSubstatusDescriptionATT",
  "restOfSolutionSubstatus", "solutionSubstatusEmpty",
  "solutionSubstatusContent", "solutionMessage", "variables",
  "numberOfOtherVariableResults", "variablesBody", "variablesEmpty",
  "variablesContent", "variableValues", "numberOfVarATT", "varValueList",
  "varValue", "varIdxATT", "varVal", "variableValuesString",
  "numberOfVarStringATT", "varValueStringList", "varValueString",
  "varStrIdxATT", "basisStatus", "numberOfBasisVarATT", "basisVarList",
  "basisVar", "basisVarIdxATT", "otherVariablesSEQ", "otherVariableResult",
  "@1", "otherVariableStart", "otherVariableAttList", "otherVariableATT",
  "numberOfOtherVarATT", "otherVarValueATT", "otherVarNameATT",
  "otherVarDescriptionATT", "otherVariableResultContent", "otherVarList",
  "otherVar", "otherVarStart", "otherVarIdxATT", "objectives",
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
     340,   341,   342,   343,   344,   345,   345,   346,   346,   346,
     346,   346,   347,   347,   348,   348,   349,   350,   350,   351,
     352,   352,   353,   353,   354,   355,   356,   356,   357,   357,
     358,   359,   359,   359,   360,   360,   361,   361,   362,   362,
     363,   364,   365,   365,   366,   367,   367,   368,   369,   370,
     370,   371,   371,   372,   373,   373,   374,   375,   376,   376,
     377,   378,   378,   379,   380,   381,   381,   383,   382,   384,
     385,   385,   386,   386,   386,   386,   387,   388,   388,   389,
     389,   390,   391,   391,   392,   392,   393,   394,   395,   396,
     396,   397,   397,   398,   398,   399,   400,   401,   401,   402,
     403,   403,   404,   405,   406,   406,   407,   407,   408,   409,
     410,   410,   411,   411,   411,   411,   412,   413,   413,   414,
     414,   415,   416,   416,   417,   417,   418,   419,   420,   421,
     421,   422,   422,   423,   423,   424,   425,   426,   426,   427,
     428,   428,   429,   430,   431,   431,   432,   432,   433,   434,
     435,   435,   436,   436,   436,   436,   437,   438,   438,   439,
     439,   440,   441,   441,   442,   442,   443,   444,   445,   446,
     446,   448,   447,   449,   449,   450,   451,   452,   451,   453,
     453,   453,   453,   454,   455,   455,   456,   456,   457,   457,
     458,   458,   459,   459,   460,   460,   462,   461,   463,   464,
     464,   465,   466,   466,   467,   467,   468,   469,   470,   469,
     471,   471,   471,   471,   472,   473,   473,   474,   474,   475,
     475,   476,   476,   477,   477,   478,   478,   480,   479,   481,
     481,   482,   483,   483,   483,   484,   484,   484,   484,   485,
     485
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     3,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     3,     1,     3,     1,     4,
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
       1,     4,     3,     8,     3,     1,     2,     3,     1,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       0,     2,     1,     1,     3,     3,     1,     1,     2,     1,
       3,     0,     3,     2,     0,     3,     0,     4,     1,     1,
       1,     6,     0,     5,     4,     0,     2,     5,     4,     1,
       1,     0,     5,     4,     0,     2,     5,     4,     0,     5,
       4,     0,     2,     5,     4,     0,     2,     0,     4,     1,
       0,     2,     1,     1,     1,     1,     4,     1,     3,     1,
       3,     3,     1,     3,     0,     2,     5,     1,     4,     0,
       3,     0,     4,     1,     1,     1,     4,     0,     5,     4,
       0,     2,     5,     4,     1,     1,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     4,     1,     3,     1,
       3,     3,     1,     3,     0,     2,     5,     1,     4,     0,
       3,     0,     4,     1,     1,     1,     4,     0,     5,     4,
       0,     2,     5,     4,     1,     1,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     4,     1,     3,     1,
       3,     3,     1,     3,     0,     2,     5,     1,     4,     0,
       5,     0,     5,     0,     2,     5,     0,     0,     3,     1,
       1,     1,     1,     4,     1,     3,     3,     1,     3,     1,
       0,     2,     1,     1,     1,     1,     0,     4,     1,     0,
       3,     4,     1,     3,     0,     2,     5,     0,     0,     3,
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
       0,     0,     0,     5,     3,     0,     1,     0,    90,     4,
       8,     6,     0,   151,     0,    93,    91,     0,   195,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,   154,   152,     0,   308,     0,     0,    28,     0,    26,
       0,    20,    22,    23,    24,     0,    60,     0,    63,     0,
      51,   569,     0,     0,    57,     0,    54,     0,    66,     0,
      69,     0,    96,    98,     0,     0,   158,   198,   196,   310,
       0,     0,   569,   569,     0,    33,    21,    19,    30,    31,
       0,    59,     0,    62,     0,    50,     0,     0,     0,    75,
      70,    72,    73,     0,    56,     0,    53,     0,    65,     0,
      68,     0,    95,     0,   107,     0,     0,   157,     0,   162,
       0,     0,     2,     0,    27,    25,    32,    38,     0,    35,
      58,    61,    49,   569,   561,   565,   566,   567,   568,   570,
      80,    74,     0,    77,    55,    52,    64,    67,    94,     0,
       0,     0,    99,   100,   101,     0,   116,     0,     0,   156,
       0,   161,     0,   166,   197,     0,     0,     0,     0,     0,
       0,     0,   265,   256,   271,   280,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   323,   321,
     569,   569,   569,   569,   311,   569,   569,   569,   569,   309,
      29,     0,    34,    36,    71,     0,    76,    78,   104,   105,
       0,   569,   569,     0,     0,     0,   108,   109,   110,     0,
     125,   130,   155,     0,   160,     0,   165,     0,   170,     0,
     222,     0,   225,   569,     0,     0,   219,     0,   213,     0,
     216,     0,     0,     0,     0,     0,     0,     0,   529,     0,
       0,     0,     0,   312,   313,   314,   315,     0,    47,     0,
       0,    39,    40,    41,    37,    44,    45,     0,    89,     0,
       0,     0,    81,    82,    83,    84,    79,    97,   103,   102,
     113,   114,     0,   569,   569,     0,     0,     0,   117,   118,
     119,     0,     0,     0,   159,     0,   164,     0,   169,     0,
     174,     0,   221,     0,   224,     0,     0,   293,   288,   290,
     291,     0,   218,     0,   212,     0,   215,     0,   230,   228,
     226,     0,     0,   266,     0,     0,     0,   257,   258,   259,
       0,     0,     0,   272,   273,   274,     0,     0,     0,   281,
     282,   283,   320,     0,   326,   324,   327,   322,   318,   319,
     316,   317,     0,    46,     0,     0,    88,   569,   569,   569,
     106,   112,   111,   122,   123,     0,   569,   569,     0,     0,
     126,   569,     0,    92,   163,     0,   168,     0,   173,     0,
       0,   220,   223,   569,   298,   292,     0,   295,   217,   211,
     214,     0,     0,   268,   269,     0,   569,   262,   263,     0,
     569,   569,   277,   278,     0,   569,   569,   286,   287,     0,
     569,   569,   569,     0,     0,    48,    43,    42,    87,    85,
      86,   115,   121,   120,   128,   129,     0,   569,     0,     0,
     136,   131,   133,   134,   167,   559,   560,   172,     0,   569,
       0,   153,   289,     0,   294,   296,   227,   233,   229,   231,
     264,   267,   255,   261,   260,   270,   276,   275,   279,   285,
     284,     0,   534,   532,   530,     0,   569,     0,   328,   329,
     330,   325,   124,   127,   569,   141,   135,     0,   138,   171,
       0,     0,   180,   175,   177,   178,     0,   307,     0,     0,
       0,   299,   300,   301,   302,   297,   252,   569,     0,     0,
     361,     0,   569,   132,     0,   137,   139,   569,   185,   179,
       0,   182,   306,   569,   569,   569,     0,   250,     0,   242,
       0,   246,     0,   240,     0,   244,   234,   235,   236,   237,
     238,   232,   247,   248,   531,   533,   537,   535,     0,     0,
     340,     0,   338,     0,   335,     0,   364,   569,   332,     0,
     150,     0,     0,     0,   142,   143,   144,   145,   140,   176,
       0,   181,   183,   305,   303,   304,   254,   253,   249,     0,
       0,     0,     0,     0,   538,     0,   569,   569,     0,   345,
     336,   334,   342,   343,     0,   363,   366,   419,   331,   149,
     569,   569,   569,     0,   194,     0,     0,     0,   186,   187,
     188,   189,   184,   251,   241,   245,   239,   243,   551,     0,
       0,   339,   337,   344,   350,     0,   347,   362,   569,     0,
     421,   459,   148,   146,   147,   193,   569,   569,   569,     0,
       0,     0,   548,     0,   550,     0,   545,   539,   540,   541,
     542,   543,   341,     0,   346,   348,     0,   372,   370,   365,
     368,   369,   569,     0,   461,   499,   192,   190,   191,     0,
     555,   556,   536,   552,   553,   554,     0,     0,     0,     0,
       0,   359,     0,     0,   351,   352,   353,   349,   356,   357,
     569,     0,   381,     0,   427,   425,   420,   423,   424,   569,
       0,     0,     0,   557,     0,   547,   549,   546,     0,   358,
       0,     0,   367,   569,     0,     0,   388,   569,     0,   436,
       0,   467,   465,   460,   463,   464,     0,     0,   528,   333,
       0,   544,   360,   355,   354,     0,   375,   569,     0,     0,
     395,   422,   569,     0,     0,   569,     0,   476,     0,   503,
     558,   569,     0,     0,   384,   569,     0,     0,     0,   430,
     426,   439,   437,   440,   462,   569,     0,     0,   501,     0,
     374,   373,     0,   376,   569,     0,     0,   391,   399,   371,
     396,   400,   569,     0,     0,     0,   470,   466,   479,   477,
     480,     0,   506,   500,   504,   569,     0,   383,   382,     0,
     385,   569,     0,   397,   429,     0,   428,   431,   454,   452,
     569,     0,     0,   449,     0,   447,   441,   442,   443,   444,
     445,   438,   569,     0,     0,   502,   507,     0,     0,   569,
       0,   390,   389,     0,   392,   569,     0,     0,   409,     0,
     407,     0,   401,   402,   403,   404,   405,   569,     0,     0,
       0,   569,   569,   569,   469,     0,   468,   471,   494,   492,
     569,     0,     0,   489,     0,   487,   481,   482,   483,   484,
     485,   478,   520,     0,   569,   379,   380,     0,     0,     0,
     569,     0,     0,   569,   569,   569,   414,   412,   398,     0,
       0,   457,   453,   455,     0,   569,   451,   450,   448,   569,
       0,     0,     0,   569,   569,   569,     0,     0,     0,   517,
       0,   519,     0,   514,   508,   509,   510,   511,   512,   378,
     377,   569,     0,     0,     0,   569,   411,   410,   408,     0,
     569,   434,   435,     0,   569,     0,   446,     0,     0,   497,
     493,   495,     0,   569,   491,   490,   488,     0,   524,   525,
     505,   521,   522,   523,     0,     0,     0,   569,   387,   386,
     569,     0,   406,   413,   417,   415,     0,   433,   432,     0,
       0,   569,   475,   474,     0,   569,     0,   486,   526,     0,
     516,   518,   515,   394,   393,   569,     0,   569,   562,   563,
     564,     0,   473,   472,     0,     0,     0,   513,     0,     0,
     458,   456,   569,     0,   527,   569,     0,   498,   496,   418,
     416
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    50,    51,    52,
      53,    54,    87,    88,    89,   128,   129,   201,   261,   262,
     263,   264,   265,   266,    31,    32,    33,    34,    35,    36,
      37,    38,    62,   100,   101,   102,   142,   143,   205,   272,
     273,   274,   275,   276,    13,    40,    74,   113,   152,   153,
     154,   210,   115,   155,   216,   217,   218,   282,   157,   219,
     288,   289,   290,   365,   221,   291,   370,   426,   293,   372,
     431,   432,   433,   477,   478,   504,   554,   555,   556,   557,
     558,    18,    76,   119,   163,   228,   300,   380,   440,   483,
     484,   485,   510,   511,   560,   598,   599,   600,   601,   602,
      44,   120,   176,   177,   178,   179,   180,   181,   182,   242,
     320,   392,   449,   496,   526,   527,   528,   529,   530,   531,
     532,   533,   569,   183,   244,   327,   328,   329,   399,   184,
     243,   323,   395,   185,   245,   333,   334,   335,   404,   186,
     246,   339,   340,   341,   409,   187,   234,   308,   309,   310,
     386,   387,   443,   491,   492,   493,   494,   495,    80,   121,
     194,   195,   196,   197,   198,   199,   247,   248,   345,   346,
     414,   468,   469,   470,   471,   500,   543,   544,   581,   582,
     583,   615,   616,   643,   674,   675,   676,   677,   678,   679,
     546,   587,   619,   649,   650,   651,   682,   704,   742,   763,
     786,   867,   706,   728,   765,   790,   820,   730,   746,   792,
     824,   871,   747,   770,   831,   771,   793,   832,   833,   834,
     835,   836,   878,   919,   955,   956,   976,   621,   653,   686,
     687,   688,   709,   733,   773,   797,   838,   923,   734,   752,
     753,   774,   806,   807,   808,   809,   810,   811,   839,   883,
     884,   925,   655,   690,   713,   714,   715,   737,   756,   813,
     847,   890,   964,   757,   779,   780,   814,   856,   857,   858,
     859,   860,   861,   891,   931,   932,   966,   692,   717,   781,
     759,   784,   816,   863,   904,   905,   906,   907,   908,   896,
     941,   942,   943,   986,   719,   347,   413,   464,   498,   537,
     574,   609,   637,   638,   639,   640,   641,   629,   663,   664,
     665,   720,   438,    96,   981,   139,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -908
static const yytype_int16 yypact[] =
{
      33,    21,   149,    -1,  -908,   144,  -908,    51,   133,  -908,
    -908,  -908,    89,   138,   -24,    56,  -908,   198,   162,  -908,
     274,   239,   294,   305,   205,   310,   316,   321,   325,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,   329,
     150,   159,  -908,   331,   187,   253,   266,  -908,   268,  -908,
     220,  -908,  -908,  -908,  -908,    29,  -908,    17,  -908,    22,
    -908,  -908,   333,     9,  -908,    12,  -908,     8,  -908,     0,
    -908,     3,  -908,  -908,   213,   336,   208,  -908,  -908,  -908,
     270,   364,  -908,  -908,   -59,  -908,  -908,  -908,  -908,  -908,
     229,  -908,   259,  -908,   296,  -908,   377,    -6,    28,  -908,
    -908,  -908,  -908,   272,  -908,   293,  -908,   291,  -908,   276,
    -908,   284,  -908,    53,  -908,   356,    18,  -908,   338,   277,
     -27,   286,  -908,   416,  -908,  -908,  -908,  -908,   -46,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,    47,  -908,  -908,  -908,  -908,  -908,  -908,   344,
     423,   424,  -908,  -908,  -908,    94,  -908,   365,   347,  -908,
      26,  -908,   342,   288,  -908,   345,   348,   415,   350,   352,
     354,   411,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,   228,  -908,  -908,  -908,    39,  -908,  -908,  -908,  -908,
     366,  -908,  -908,   360,   434,   435,  -908,  -908,  -908,   148,
    -908,   332,  -908,   362,  -908,    -3,  -908,   358,   317,    20,
    -908,    19,  -908,  -908,   361,    14,  -908,     7,  -908,     6,
    -908,   433,   363,    34,   174,   185,   197,   385,   -78,   438,
     439,   440,   441,  -908,  -908,  -908,  -908,    10,  -908,   445,
     446,  -908,  -908,  -908,  -908,  -908,  -908,   343,  -908,   448,
     449,   450,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,   387,  -908,  -908,   369,   451,   452,  -908,  -908,
    -908,    48,   437,   408,  -908,   313,  -908,     1,  -908,   367,
     349,   398,  -908,   376,  -908,   456,    64,  -908,  -908,  -908,
    -908,   351,  -908,   335,  -908,   334,  -908,   458,  -908,  -908,
    -908,   373,   466,  -908,   375,   467,   468,  -908,  -908,  -908,
     379,   469,   470,  -908,  -908,  -908,   381,   471,   472,  -908,
    -908,  -908,  -908,   453,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,   346,  -908,   474,   475,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,   412,  -908,  -908,   383,   477,
    -908,  -908,   384,  -908,  -908,   337,  -908,    13,  -908,   465,
     432,  -908,  -908,  -908,  -908,  -908,    70,  -908,  -908,  -908,
    -908,   478,   -93,  -908,  -908,   328,  -908,  -908,  -908,   339,
    -908,  -908,  -908,  -908,   340,  -908,  -908,  -908,  -908,   341,
    -908,  -908,  -908,   386,    32,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,   422,  -908,   482,   104,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,   368,  -908,
     388,  -908,  -908,   157,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,   483,  -908,  -908,  -908,   370,  -908,   489,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,   128,  -908,  -908,
     491,   136,  -908,  -908,  -908,  -908,   391,  -908,   496,   498,
     499,  -908,  -908,  -908,  -908,  -908,   189,  -908,   -74,   301,
     407,   500,  -908,  -908,   164,  -908,  -908,  -908,  -908,  -908,
     142,  -908,  -908,  -908,  -908,  -908,     2,  -908,   501,  -908,
     502,  -908,   504,  -908,   508,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,   505,   509,
    -908,   511,  -908,   222,  -908,    23,   353,  -908,  -908,   409,
    -908,   514,   515,   516,  -908,  -908,  -908,  -908,  -908,  -908,
     171,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,   382,
     512,   517,   518,   519,   513,   522,  -908,  -908,   139,  -908,
    -908,  -908,  -908,  -908,   425,  -908,   503,   429,  -908,  -908,
    -908,  -908,  -908,   426,  -908,   527,   528,   529,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,   233,
     526,  -908,  -908,  -908,  -908,   169,  -908,  -908,  -908,   390,
     520,   457,  -908,  -908,  -908,  -908,  -908,  -908,  -908,    -5,
     531,   534,  -908,   537,  -908,   538,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,   204,  -908,  -908,   536,   393,  -908,  -908,
    -908,  -908,  -908,   392,   530,   431,  -908,  -908,  -908,   543,
    -908,  -908,  -908,  -908,  -908,  -908,   544,   545,   546,   547,
      11,  -908,   548,   549,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,   532,   399,   550,   403,  -908,  -908,  -908,  -908,  -908,
     394,   540,   436,  -908,   554,  -908,  -908,  -908,   428,  -908,
     556,   557,  -908,  -908,   558,   541,   494,  -908,   559,  -908,
     563,   487,  -908,  -908,  -908,  -908,   564,   565,  -908,  -908,
     521,  -908,  -908,  -908,  -908,   567,  -908,  -908,   566,   551,
    -908,  -908,  -908,   568,    49,  -908,   569,  -908,   573,  -908,
    -908,  -908,   122,   576,  -908,  -908,   574,   -77,   577,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,   575,   -14,  -908,   199,
    -908,  -908,   560,  -908,  -908,   247,   580,  -908,  -908,  -908,
    -908,  -908,  -908,   -81,   137,   581,  -908,  -908,  -908,  -908,
    -908,   582,  -908,  -908,  -908,  -908,   578,  -908,  -908,   562,
    -908,  -908,   -67,   246,  -908,   570,  -908,  -908,  -908,  -908,
    -908,   589,   590,  -908,   591,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,   -28,   153,  -908,   585,   594,   402,  -908,
     586,  -908,  -908,   572,  -908,  -908,   599,   600,  -908,   601,
    -908,   400,  -908,  -908,  -908,  -908,  -908,  -908,   587,    59,
     602,  -908,  -908,  -908,  -908,   583,  -908,  -908,  -908,  -908,
    -908,   603,   606,  -908,   607,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,   260,  -908,  -908,  -908,   444,   605,   609,
    -908,   604,   610,  -908,  -908,  -908,  -908,  -908,  -908,   611,
     406,  -908,  -908,  -908,   593,  -908,  -908,  -908,  -908,  -908,
     608,   -38,   613,  -908,  -908,  -908,   -21,   612,   620,  -908,
     621,  -908,   623,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,   454,   622,   625,  -908,  -908,  -908,  -908,   -73,
    -908,  -908,  -908,   533,  -908,   617,  -908,   624,   410,  -908,
    -908,  -908,   614,  -908,  -908,  -908,  -908,   626,  -908,  -908,
    -908,  -908,  -908,  -908,   627,   628,   629,  -908,  -908,  -908,
    -908,   473,  -908,  -908,  -908,  -908,   615,  -908,  -908,   632,
      91,  -908,  -908,  -908,   571,  -908,   630,  -908,  -908,   631,
    -908,  -908,  -908,  -908,  -908,  -908,   636,  -908,  -908,  -908,
    -908,   542,  -908,  -908,   641,    91,   592,  -908,   643,    91,
    -908,  -908,  -908,   579,  -908,  -908,   481,  -908,  -908,  -908,
    -908
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,   616,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,   507,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,   510,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,   177,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,   145,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,   271,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,   115,  -908,  -908,
    -908,  -908,    45,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,   -82,  -907,  -908,  -908
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     124,   125,   134,   295,   109,   375,   822,   111,   566,   567,
     315,   313,   107,   103,   352,   698,   105,   795,   311,   435,
     436,    92,   158,   303,   301,    19,    94,   584,   164,   768,
     126,     4,   223,    90,   953,   165,   343,   937,   929,   938,
     939,   535,   465,   202,   321,   447,   344,     7,   845,   267,
     268,   204,   448,   659,   536,   660,   661,   846,   368,   166,
     466,    10,    11,   149,    20,   777,   322,     5,    21,   930,
      22,   269,    23,   270,   467,   127,   796,     1,   993,   271,
     369,   167,   996,   302,    24,   150,   769,   954,   127,   168,
     940,   151,   778,   823,    25,   978,    26,   979,   980,    15,
      16,   159,    27,   169,   213,   170,   304,   224,   249,   250,
     251,   252,    93,   253,   254,   255,   256,   171,    28,    95,
     585,   172,    91,   173,   662,   174,   214,   175,   104,   278,
     279,   312,   215,   106,   140,   108,   437,   141,   314,   316,
     112,   568,   376,   110,   296,   353,   699,   798,   799,     6,
     750,   305,   800,   140,     9,   751,   206,   881,   285,   135,
     136,   137,   138,   848,   849,   850,   882,   486,   487,   801,
     384,   802,   803,   385,   549,   550,   384,   804,   805,   444,
     286,   593,   594,    12,   324,   851,   287,   852,   853,   488,
      17,   489,    39,   854,   855,   330,   551,   490,   552,   516,
     517,   361,   362,   595,   553,   596,   325,   336,    41,    42,
     475,   597,   326,   476,   670,   671,    43,   331,    73,   518,
     519,   520,   521,   332,    61,   522,   523,   524,   525,   337,
      84,    85,   578,   579,   475,   338,   672,   505,   257,   258,
     673,    75,   508,    79,    45,   509,   538,   630,   508,    55,
      56,   561,    46,    47,   539,   540,    48,    49,   541,   542,
     259,    81,   260,   631,   632,   633,   634,   635,   636,    82,
     613,    83,   825,   614,   897,   418,   419,   420,   826,   761,
     827,   828,   762,   114,   422,   423,   829,   830,   118,   428,
     898,   899,   900,   901,   902,   903,   188,   189,    45,   190,
     644,   442,   191,   614,    57,    58,    46,    47,   192,   782,
      48,    49,   783,   193,   451,    59,    60,   122,   453,   454,
      63,    64,   130,   456,   457,   538,    65,    66,   459,   460,
     461,    67,    68,   539,   540,    69,    70,   541,   542,    71,
      72,    77,    78,    98,    99,   473,   116,   117,   160,   161,
     208,   209,   225,   226,   131,   229,   230,   480,   231,   232,
     235,   236,   237,   238,   239,   240,   280,   281,   297,   298,
     123,   306,   307,   318,   319,   363,   364,   377,   378,   393,
     394,   397,   398,   133,   501,   402,   403,   407,   408,   424,
     425,   144,   503,   132,   429,   430,   462,   463,   481,   482,
     647,   648,   684,   685,   711,   712,   788,   789,   865,   866,
     876,   877,   921,   922,   145,   534,   962,   963,   146,   147,
     548,   148,   156,   162,   200,   559,   211,   212,   227,   220,
     222,   563,   564,   565,   233,   277,   241,   283,   284,   299,
     292,   317,   342,   294,   348,   349,   350,   351,   354,   355,
     356,   357,   358,   359,   366,   367,   371,   379,   360,   373,
     374,   381,   383,   382,   391,   588,   389,   390,   388,   396,
     400,   401,   405,   406,   410,   411,   412,   450,   434,   421,
     427,   415,   416,   417,   439,   441,   446,   472,   474,   497,
     452,   479,   502,   455,   611,   612,   458,   507,   512,   513,
     499,   514,   515,   545,   570,   571,   547,   572,   622,   623,
     624,   573,   576,   575,   577,   586,   589,   590,   591,   592,
     604,   603,   617,   608,   618,   605,   606,   607,   610,   620,
     626,   627,   628,   625,   642,   654,   646,   667,   652,   666,
     668,   669,   680,   691,   656,   657,   658,   689,   693,   681,
     694,   700,   701,   695,   696,   697,   707,   705,   703,   708,
     716,   718,   721,   722,   723,   724,   729,   727,   726,   735,
     683,   736,   738,   741,   732,   739,   744,   745,   749,   758,
     740,   755,   764,   772,   767,   776,   791,   812,   818,   785,
     815,   819,   841,   842,   843,   862,   869,   880,   702,   837,
     864,   870,   873,   874,   875,   910,   893,   710,   885,   894,
     895,   911,   889,   912,   914,   949,   915,   920,   928,   933,
     944,   725,   924,   945,   946,   731,   947,   960,   950,   951,
     961,   968,   958,   969,   974,   203,   970,   971,   977,   987,
     985,   991,  1000,   965,   975,   743,   989,   992,   983,   995,
     748,   994,   207,   754,   506,   562,   998,   445,   580,   760,
     645,     0,     0,   766,     0,     0,    86,     0,     0,     0,
       0,     0,     0,   775,     0,     0,     0,     0,     0,     0,
       0,     0,   787,     0,     0,     0,     0,     0,     0,     0,
     794,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   817,     0,     0,     0,     0,     0,   821,
       0,     0,     0,     0,     0,     0,     0,     0,   840,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     844,     0,     0,     0,     0,     0,     0,   868,     0,     0,
       0,     0,     0,   872,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   879,     0,     0,     0,   886,
     887,   888,     0,     0,     0,     0,     0,     0,   892,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   909,     0,     0,     0,     0,     0,   913,     0,
       0,   916,   917,   918,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   926,     0,     0,     0,   927,     0,     0,
       0,   934,   935,   936,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   948,
       0,     0,     0,   952,     0,     0,     0,     0,   957,     0,
       0,     0,   959,     0,     0,     0,     0,     0,     0,     0,
       0,   967,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   972,     0,     0,   973,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   982,
       0,     0,     0,   984,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   988,     0,   990,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     997,     0,     0,   999
};

static const yytype_int16 yycheck[] =
{
      82,    83,     8,     6,     4,     4,    73,     4,     6,     7,
       4,     4,     4,     4,     4,     4,     4,    98,     4,     6,
       7,     4,     4,     4,     4,    49,     4,     4,    55,   106,
      89,    10,     6,     4,   107,    62,   114,    58,    76,    60,
      61,   115,    10,    89,    10,   138,   124,    48,    76,    10,
      11,   133,   145,    58,   128,    60,    61,    85,    10,    86,
      28,    10,    11,    10,    88,    79,    32,    46,    92,   107,
      94,    32,    96,    34,    42,   134,   157,    44,   985,    40,
      32,   108,   989,    63,   108,    32,   163,   160,   134,   116,
     111,    38,   106,   160,   118,     4,   120,     6,     7,    10,
      11,    83,   126,   130,    10,   132,    87,    81,   190,   191,
     192,   193,    95,   195,   196,   197,   198,   144,   142,    97,
      97,   148,    93,   150,   129,   152,    32,   154,   119,   211,
     212,   117,    38,   121,   106,   127,   123,   109,   131,   133,
     137,   139,   141,   143,   147,   135,   135,    10,    11,     0,
     101,   233,    15,   106,    10,   106,   109,    98,    10,   165,
     166,   167,   168,    10,    11,    12,   107,    10,    11,    32,
     106,    34,    35,   109,    10,    11,   106,    40,    41,   109,
      32,    10,    11,    50,    10,    32,    38,    34,    35,    32,
      52,    34,   136,    40,    41,    10,    32,    40,    34,    10,
      11,   283,   284,    32,    40,    34,    32,    10,    10,    11,
     106,    40,    38,   109,    10,    11,    54,    32,    68,    30,
      31,    32,    33,    38,    19,    36,    37,    38,    39,    32,
      10,    11,    10,    11,   106,    38,    32,   109,    10,    11,
      36,    82,   106,    56,    24,   109,    24,    14,   106,    10,
      11,   109,    32,    33,    32,    33,    36,    37,    36,    37,
      32,     8,    34,    30,    31,    32,    33,    34,    35,     3,
     131,     3,    26,   134,    14,   357,   358,   359,    32,   157,
      34,    35,   160,    70,   366,   367,    40,    41,    80,   371,
      30,    31,    32,    33,    34,    35,    10,    11,    24,    13,
     131,   383,    16,   134,    10,    11,    32,    33,    22,   110,
      36,    37,   113,    27,   396,    10,    11,    47,   400,   401,
      10,    11,    93,   405,   406,    24,    10,    11,   410,   411,
     412,    10,    11,    32,    33,    10,    11,    36,    37,    10,
      11,    10,    11,    10,    11,   427,    10,    11,    10,    11,
       6,     7,    10,    11,    95,    10,    11,   439,    10,    11,
      10,    11,    10,    11,    10,    11,     6,     7,    10,    11,
       6,    10,    11,    10,    11,     6,     7,    10,    11,     6,
       7,     6,     7,     6,   466,     6,     7,     6,     7,     6,
       7,   119,   474,    97,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,   159,   160,     6,     7,
      10,    11,     6,     7,   121,   497,     6,     7,   127,   143,
     502,   137,    66,   146,     8,   507,     3,     3,   140,    64,
      83,   513,   514,   515,    19,    69,    25,     3,     3,   122,
     108,     8,    57,    81,     6,     6,     6,     6,     3,     3,
     107,     3,     3,     3,     3,     3,    19,   108,    71,    51,
     147,    63,     6,    87,     6,   547,   131,   133,   117,     3,
       3,     3,     3,     3,     3,     3,    23,   149,   141,    67,
       3,   135,     8,     8,    19,    53,     8,    65,     6,     6,
     151,   123,     3,   153,   576,   577,   155,     6,   107,     3,
     130,     3,     3,    96,     3,     3,     6,     3,   590,   591,
     592,     3,     3,     8,     3,   162,   107,     3,     3,     3,
       8,   139,    97,    10,    21,     8,     8,     8,     6,   100,
       3,     3,     3,   107,     8,    78,   618,     3,    18,     8,
       3,     3,     6,   112,   626,   627,   628,    17,     5,   156,
       6,     3,     3,     8,     8,     8,     6,   158,    26,   156,
      20,   125,     8,   135,     8,     8,    72,    26,    10,     6,
     652,    84,     8,     6,    15,    10,    10,    26,    10,     6,
      59,    12,     6,     6,    10,    10,     6,     6,    10,    29,
       8,    29,     3,     3,     3,    10,    10,    10,   680,    29,
       6,    29,     3,     3,     3,   161,     3,   689,     6,     3,
       3,     6,    29,     4,    10,   161,     6,     6,    10,     6,
       8,   703,    29,     3,     3,   707,     3,    10,     6,     4,
       6,     5,    99,     6,   161,   128,     8,     8,     6,     8,
      10,    99,   161,    29,    29,   727,    10,     6,    77,     6,
     732,    59,   142,   735,   477,   510,    77,   386,   543,   741,
     615,    -1,    -1,   745,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,   755,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   764,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     772,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   785,    -1,    -1,    -1,    -1,    -1,   791,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   800,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     812,    -1,    -1,    -1,    -1,    -1,    -1,   819,    -1,    -1,
      -1,    -1,    -1,   825,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   837,    -1,    -1,    -1,   841,
     842,   843,    -1,    -1,    -1,    -1,    -1,    -1,   850,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   864,    -1,    -1,    -1,    -1,    -1,   870,    -1,
      -1,   873,   874,   875,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   885,    -1,    -1,    -1,   889,    -1,    -1,
      -1,   893,   894,   895,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   911,
      -1,    -1,    -1,   915,    -1,    -1,    -1,    -1,   920,    -1,
      -1,    -1,   924,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   933,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   947,    -1,    -1,   950,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   961,
      -1,    -1,    -1,   965,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   975,    -1,   977,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     992,    -1,    -1,   995
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   213,   173,    10,    11,    52,   250,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   193,   194,   195,   196,   197,   198,   199,   200,   136,
     214,    10,    11,    54,   269,    24,    32,    33,    36,    37,
     176,   177,   178,   179,   180,    10,    11,    10,    11,    10,
      11,    19,   201,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    68,   215,    82,   251,    10,    11,    56,
     327,     8,     3,     3,    10,    11,   177,   181,   182,   183,
       4,    93,     4,    95,     4,    97,   482,   485,    10,    11,
     202,   203,   204,     4,   119,     4,   121,     4,   127,     4,
     143,     4,   137,   216,    70,   221,    10,    11,    80,   252,
     270,   328,    47,     6,   482,   482,    89,   134,   184,   185,
      93,    95,    97,     6,     8,   165,   166,   167,   168,   484,
     106,   109,   205,   206,   119,   121,   127,   143,   137,    10,
      32,    38,   217,   218,   219,   222,    66,   227,     4,    83,
      10,    11,   146,   253,    55,    62,    86,   108,   116,   130,
     132,   144,   148,   150,   152,   154,   271,   272,   273,   274,
     275,   276,   277,   292,   298,   302,   308,   314,    10,    11,
      13,    16,    22,    27,   329,   330,   331,   332,   333,   334,
       8,   186,    89,   185,   482,   207,   109,   206,     6,     7,
     220,     3,     3,    10,    32,    38,   223,   224,   225,   228,
      64,   233,    83,     6,    81,    10,    11,   140,   254,    10,
      11,    10,    11,    19,   315,    10,    11,    10,    11,    10,
      11,    25,   278,   299,   293,   303,   309,   335,   336,   482,
     482,   482,   482,   482,   482,   482,   482,    10,    11,    32,
      34,   187,   188,   189,   190,   191,   192,    10,    11,    32,
      34,    40,   208,   209,   210,   211,   212,    69,   482,   482,
       6,     7,   226,     3,     3,    10,    32,    38,   229,   230,
     231,   234,   108,   237,    81,     6,   147,    10,    11,   122,
     255,     4,    63,     4,    87,   482,    10,    11,   316,   317,
     318,     4,   117,     4,   131,     4,   133,     8,    10,    11,
     279,    10,    32,   300,    10,    32,    38,   294,   295,   296,
      10,    32,    38,   304,   305,   306,    10,    32,    38,   310,
     311,   312,    57,   114,   124,   337,   338,   464,     6,     6,
       6,     6,     4,   135,     3,     3,   107,     3,     3,     3,
      71,   482,   482,     6,     7,   232,     3,     3,    10,    32,
     235,    19,   238,    51,   147,     4,   141,    10,    11,   108,
     256,    63,    87,     6,   106,   109,   319,   320,   117,   131,
     133,     6,   280,     6,     7,   301,     3,     6,     7,   297,
       3,     3,     6,     7,   307,     3,     3,     6,     7,   313,
       3,     3,    23,   465,   339,   135,     8,     8,   482,   482,
     482,    67,   482,   482,     6,     7,   236,     3,   482,    10,
      11,   239,   240,   241,   141,     6,     7,   123,   481,    19,
     257,    53,   482,   321,   109,   320,     8,   138,   145,   281,
     149,   482,   151,   482,   482,   153,   482,   482,   155,   482,
     482,   482,    10,    11,   466,    10,    28,    42,   340,   341,
     342,   343,    65,   482,     6,   106,   109,   242,   243,   123,
     482,    10,    11,   258,   259,   260,    10,    11,    32,    34,
      40,   322,   323,   324,   325,   326,   282,     6,   467,   130,
     344,   482,     3,   482,   244,   109,   243,     6,   106,   109,
     261,   262,   107,     3,     3,     3,    10,    11,    30,    31,
      32,    33,    36,    37,    38,    39,   283,   284,   285,   286,
     287,   288,   289,   290,   482,   115,   128,   468,    24,    32,
      33,    36,    37,   345,   346,    96,   359,     6,   482,    10,
      11,    32,    34,    40,   245,   246,   247,   248,   249,   482,
     263,   109,   262,   482,   482,   482,     6,     7,   139,   291,
       3,     3,     3,     3,   469,     8,     3,     3,    10,    11,
     346,   347,   348,   349,     4,    97,   162,   360,   482,   107,
       3,     3,     3,    10,    11,    32,    34,    40,   264,   265,
     266,   267,   268,   139,     8,     8,     8,     8,    10,   470,
       6,   482,   482,   131,   134,   350,   351,    97,    21,   361,
     100,   396,   482,   482,   482,   107,     3,     3,     3,   476,
      14,    30,    31,    32,    33,    34,    35,   471,   472,   473,
     474,   475,     8,   352,   131,   351,   482,    10,    11,   362,
     363,   364,    18,   397,    78,   421,   482,   482,   482,    58,
      60,    61,   129,   477,   478,   479,     8,     3,     3,     3,
      10,    11,    32,    36,   353,   354,   355,   356,   357,   358,
       6,   156,   365,   482,    10,    11,   398,   399,   400,    17,
     422,   112,   446,     5,     6,     8,     8,     8,     4,   135,
       3,     3,   482,    26,   366,   158,   371,     6,   156,   401,
     482,    10,    11,   423,   424,   425,    20,   447,   125,   463,
     480,     8,   135,     8,     8,   482,    10,    26,   372,    72,
     376,   482,    15,   402,   407,     6,    84,   426,     8,    10,
      59,     6,   367,   482,    10,    26,   377,   381,   482,    10,
     101,   106,   408,   409,   482,    12,   427,   432,     6,   449,
     482,   157,   160,   368,     6,   373,   482,    10,   106,   163,
     382,   384,     6,   403,   410,   482,    10,    79,   106,   433,
     434,   448,   110,   113,   450,    29,   369,   482,   159,   160,
     374,     6,   378,   385,   482,    98,   157,   404,    10,    11,
      15,    32,    34,    35,    40,    41,   411,   412,   413,   414,
     415,   416,     6,   428,   435,     8,   451,   482,    10,    29,
     375,   482,    73,   160,   379,    26,    32,    34,    35,    40,
      41,   383,   386,   387,   388,   389,   390,    29,   405,   417,
     482,     3,     3,     3,   482,    76,    85,   429,    10,    11,
      12,    32,    34,    35,    40,    41,   436,   437,   438,   439,
     440,   441,    10,   452,     6,     6,     7,   370,   482,    10,
      29,   380,   482,     3,     3,     3,    10,    11,   391,   482,
      10,    98,   107,   418,   419,     6,   482,   482,   482,    29,
     430,   442,   482,     3,     3,     3,   458,    14,    30,    31,
      32,    33,    34,    35,   453,   454,   455,   456,   457,   482,
     161,     6,     4,   482,    10,     6,   482,   482,   482,   392,
       6,     6,     7,   406,    29,   420,   482,   482,    10,    76,
     107,   443,   444,     6,   482,   482,   482,    58,    60,    61,
     111,   459,   460,   461,     8,     3,     3,     3,   482,   161,
       6,     4,   482,   107,   160,   393,   394,   482,    99,   482,
      10,     6,     6,     7,   431,    29,   445,   482,     5,     6,
       8,     8,   482,   482,   161,    29,   395,     6,     4,     6,
       7,   483,   482,    77,   482,    10,   462,     8,   482,    10,
     482,    99,     6,   483,    59,     6,   483,   482,    77,   482,
     161
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

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 337:

    {parserData->statusType = (yyvsp[(2) - (3)].sval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].sval));;}
    break;

  case 338:

    {parserData->statusType = ""; parserData->statusTypePresent = true;;}
    break;

  case 339:

    {parserData->statusDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 340:

    {parserData->statusDescription = "";;}
    break;

  case 341:

    {;}
    break;

  case 342:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element"); 
		parserData->statusTypePresent = false; 
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	;}
    break;

  case 343:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element");
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	;}
    break;

  case 354:

    { std::cout << "parsed <solutionSubstatus type=" << std::endl;
;}
    break;

  case 355:

    { std::cout << "parsed solutionSubstatus description=" << std::endl;
;}
    break;

  case 360:

    { std::cout << "parsed </solutionSubstatus>" << std::endl;
/* !!!put substatus text */ ;}
    break;

  case 362:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = $2; */
		osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
	;}
    break;

  case 363:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = "";*/
		osresult->setSolutionMessage(parserData->solutionIdx, "");
	;}
    break;

  case 367:

    {  
	osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
	;}
    break;

  case 373:

    {
  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  ;}
    break;

  case 374:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 378:

    { parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 379:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->primalVals.push_back( parserData->primalValPair);  
   ;}
    break;

  case 380:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); 
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->primalVals.push_back( parserData->primalValPair); 
  ;}
    break;

  case 382:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
     }
 */  ;}
    break;

  case 383:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 386:

    {/*parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  */
;}
    break;

  case 387:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 389:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
      }
 */  ;}
    break;

  case 390:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 394:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 397:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	;}
    break;

  case 399:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	;}
    break;

  case 406:

    {
	parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	//osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = $3;
;}
    break;

  case 407:

    {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
;}
    break;

  case 408:

    {parserData->tmpOtherValue=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 409:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 410:

    {
parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 411:

    {
parserData->tmpOtherDescription=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 413:

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

  case 416:

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

  case 417:

    {//	if(parserData->otherVarStruct->numberOfVar <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	;}
    break;

  case 418:

    {;}
    break;

  case 422:

    {  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 428:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
;}
    break;

  case 429:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 433:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(3) - (4)].ival);   ;}
    break;

  case 434:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].ival);                  
	parserData->objVals.push_back( parserData->objValPair);
;}
    break;

  case 435:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->objVals.push_back( parserData->objValPair);
  ;}
    break;

  case 439:

    {  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	;}
    break;

  case 446:

    {
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
;}
    break;

  case 447:

    {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
;}
    break;

  case 448:

    {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 449:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherObjStruct->name = "";
;}
    break;

  case 450:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 451:

    {
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 453:

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

  case 456:

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

  case 457:

    {//	if(parserData->otherObjStruct->numberOfObj <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of objectives") ;
	;}
    break;

  case 458:

    {;}
    break;

  case 462:

    {  
/*        osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 468:

    {
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}
 ;}
    break;

  case 469:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 473:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 474:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 		
	;}
    break;

  case 475:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 	
	;}
    break;

  case 487:

    {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
;}
    break;

  case 488:

    {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 489:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherConStruct->name = "";
;}
    break;

  case 490:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 491:

    {
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 496:

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

  case 497:

    {//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	;}
    break;

  case 498:

    {;}
    break;

  case 500:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 501:

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

  case 505:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 507:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 513:

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

  case 514:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 515:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 516:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 518:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 521:

    {parserData->kounter++;;}
    break;

  case 522:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 523:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 526:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 528:

    {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
;}
    break;

  case 536:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
;}
    break;

  case 538:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/;}
    break;

  case 544:

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

  case 545:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
*/
;}
    break;

  case 546:

    {
/*	parserData->tmpOtherName=$2; parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
;}
    break;

  case 547:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
;}
    break;

  case 549:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
;}
    break;

  case 553:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/;}
    break;

  case 554:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/;}
    break;

  case 557:

    {/*parserData->itemContent = $2; free($2);*/;}
    break;

  case 559:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 560:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 562:

    { parserData->outStr << (yyvsp[(1) - (1)].sval);    free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 563:

    { parserData->outStr << (yyvsp[(1) - (1)].ival);  /*free($1);*/ ;}
    break;

  case 564:

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


