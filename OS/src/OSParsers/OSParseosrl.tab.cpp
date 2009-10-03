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
/* Line 187 of yacc.c.  */

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
#define YYLAST   924

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  324
/* YYNRULES -- Number of rules.  */
#define YYNRULES  618
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1044

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
     213,   216,   220,   225,   227,   229,   232,   234,   238,   240,
     243,   247,   248,   251,   253,   255,   257,   261,   263,   267,
     269,   273,   275,   278,   280,   281,   284,   289,   290,   293,
     295,   297,   299,   301,   303,   305,   310,   314,   317,   323,
     324,   327,   329,   331,   335,   339,   341,   343,   345,   351,
     352,   355,   357,   359,   363,   367,   369,   371,   373,   379,
     380,   383,   385,   387,   391,   395,   397,   399,   401,   407,
     408,   411,   415,   417,   419,   421,   425,   430,   432,   434,
     437,   439,   443,   445,   448,   452,   453,   456,   458,   460,
     462,   466,   470,   472,   476,   478,   481,   483,   484,   487,
     492,   493,   496,   498,   500,   502,   504,   506,   508,   513,
     517,   520,   525,   529,   532,   537,   541,   544,   549,   553,
     556,   561,   565,   568,   572,   577,   579,   581,   584,   586,
     590,   592,   595,   599,   600,   603,   605,   607,   609,   613,
     617,   619,   623,   625,   628,   630,   631,   634,   639,   640,
     643,   645,   647,   649,   651,   653,   655,   657,   659,   661,
     663,   665,   670,   674,   677,   682,   686,   689,   694,   698,
     701,   706,   710,   713,   718,   722,   725,   729,   734,   736,
     740,   741,   744,   748,   749,   752,   754,   756,   758,   760,
     764,   766,   770,   772,   776,   778,   782,   784,   786,   788,
     791,   793,   797,   798,   800,   802,   808,   809,   812,   814,
     816,   820,   824,   826,   828,   830,   836,   837,   840,   844,
     846,   848,   850,   856,   857,   860,   862,   864,   868,   872,
     874,   876,   878,   884,   885,   888,   890,   892,   896,   900,
     902,   904,   906,   910,   915,   917,   919,   922,   924,   928,
     930,   933,   937,   938,   941,   943,   945,   947,   951,   955,
     957,   961,   963,   966,   968,   969,   973,   974,   977,   980,
     983,   986,   989,   993,   997,  1001,  1005,  1009,  1011,  1014,
    1015,  1018,  1022,  1024,  1025,  1028,  1030,  1032,  1037,  1041,
    1050,  1054,  1056,  1059,  1063,  1065,  1069,  1071,  1076,  1078,
    1080,  1083,  1085,  1089,  1091,  1094,  1098,  1099,  1102,  1104,
    1106,  1110,  1114,  1116,  1119,  1121,  1122,  1127,  1131,  1134,
    1135,  1139,  1140,  1145,  1147,  1149,  1151,  1158,  1159,  1165,
    1169,  1174,  1175,  1178,  1184,  1189,  1191,  1193,  1194,  1200,
    1204,  1209,  1210,  1213,  1219,  1224,  1228,  1233,  1234,  1240,
    1244,  1249,  1250,  1253,  1259,  1264,  1265,  1268,  1269,  1274,
    1276,  1278,  1279,  1282,  1284,  1286,  1288,  1290,  1295,  1297,
    1301,  1303,  1307,  1311,  1313,  1315,  1319,  1320,  1323,  1327,
    1329,  1334,  1338,  1341,  1343,  1344,  1348,  1349,  1354,  1356,
    1358,  1360,  1365,  1366,  1372,  1376,  1381,  1382,  1385,  1391,
    1396,  1398,  1400,  1401,  1404,  1408,  1410,  1411,  1414,  1416,
    1418,  1420,  1422,  1427,  1429,  1433,  1435,  1439,  1443,  1445,
    1447,  1451,  1452,  1455,  1459,  1461,  1466,  1470,  1473,  1475,
    1476,  1480,  1481,  1486,  1488,  1490,  1492,  1497,  1498,  1504,
    1508,  1513,  1514,  1517,  1523,  1528,  1530,  1532,  1533,  1536,
    1540,  1542,  1543,  1546,  1548,  1550,  1552,  1554,  1559,  1561,
    1565,  1567,  1571,  1575,  1577,  1579,  1583,  1584,  1587,  1591,
    1593,  1598,  1602,  1605,  1607,  1608,  1614,  1618,  1619,  1625,
    1626,  1629,  1635,  1639,  1640,  1641,  1645,  1647,  1649,  1651,
    1653,  1658,  1660,  1664,  1668,  1670,  1674,  1676,  1677,  1680,
    1682,  1684,  1686,  1688,  1689,  1694,  1696,  1697,  1701,  1706,
    1708,  1712,  1713,  1716,  1722,  1726,  1727,  1728,  1732,  1734,
    1736,  1738,  1740,  1745,  1747,  1751,  1755,  1757,  1761,  1763,
    1764,  1767,  1769,  1771,  1773,  1775,  1776,  1781,  1783,  1785,
    1788,  1790,  1792,  1794,  1796,  1798,  1800,  1802,  1803
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   214,   253,   274,   332,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   194,    -1,   195,    -1,   196,    -1,   197,
      -1,   198,    -1,   199,    -1,   200,    -1,   201,    -1,   176,
     177,   183,    -1,    88,    -1,   178,    -1,   179,    -1,   178,
     179,    -1,   180,    -1,   181,    -1,   182,    -1,    36,     3,
     489,    -1,    37,    -1,    32,     3,   489,    -1,    33,    -1,
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
      10,   143,    -1,   142,    11,    -1,   108,   202,   203,    -1,
      19,   489,     6,   489,    -1,   204,    -1,   205,    -1,    10,
     109,    -1,    11,    -1,    10,   206,   109,    -1,   207,    -1,
     206,   207,    -1,   106,   208,   213,    -1,    -1,   208,   209,
      -1,   210,    -1,   211,    -1,   212,    -1,    34,     3,   489,
      -1,    35,    -1,    40,     3,   489,    -1,    41,    -1,    32,
       3,   489,    -1,    33,    -1,    10,   107,    -1,    11,    -1,
      -1,    50,    11,    -1,    50,    10,   215,    51,    -1,    -1,
     215,   216,    -1,   217,    -1,   218,    -1,   224,    -1,   230,
      -1,   236,    -1,   240,    -1,   136,    10,     4,   137,    -1,
     136,    10,   137,    -1,   136,    11,    -1,    68,   219,    10,
     223,    69,    -1,    -1,   219,   220,    -1,   221,    -1,   222,
      -1,    38,     3,   489,    -1,    32,     3,   489,    -1,    33,
      -1,     6,    -1,     7,    -1,    70,   225,    10,   229,    71,
      -1,    -1,   225,   226,    -1,   227,    -1,   228,    -1,    38,
       3,   489,    -1,    32,     3,   489,    -1,    33,    -1,     6,
      -1,     7,    -1,    66,   231,    10,   235,    67,    -1,    -1,
     231,   232,    -1,   233,    -1,   234,    -1,    38,     3,   489,
      -1,    32,     3,   489,    -1,    33,    -1,     6,    -1,     7,
      -1,    64,   237,    10,   239,    65,    -1,    -1,   237,   238,
      -1,    32,     3,   489,    -1,    33,    -1,     6,    -1,     7,
      -1,   108,   241,   242,    -1,    19,   489,     6,   489,    -1,
     243,    -1,   244,    -1,    10,   109,    -1,    11,    -1,    10,
     245,   109,    -1,   246,    -1,   245,   246,    -1,   106,   247,
     252,    -1,    -1,   247,   248,    -1,   249,    -1,   250,    -1,
     251,    -1,    34,     3,   489,    -1,    40,     3,   489,    -1,
      41,    -1,    32,     3,   489,    -1,    33,    -1,    10,   107,
      -1,    11,    -1,    -1,    52,    11,    -1,    52,    10,   254,
      53,    -1,    -1,   254,   255,    -1,   256,    -1,   257,    -1,
     258,    -1,   259,    -1,   260,    -1,   261,    -1,    82,    10,
       4,    83,    -1,    82,    10,    83,    -1,    82,    11,    -1,
      80,    10,     6,    81,    -1,    80,    10,    81,    -1,    80,
      11,    -1,   146,    10,     6,   147,    -1,   146,    10,   147,
      -1,   146,    11,    -1,   140,    10,     4,   141,    -1,   140,
      10,   141,    -1,   140,    11,    -1,   122,    10,   488,   123,
      -1,   122,    10,   123,    -1,   122,    11,    -1,   108,   262,
     263,    -1,    19,   489,     6,   489,    -1,   264,    -1,   265,
      -1,    10,   109,    -1,    11,    -1,    10,   266,   109,    -1,
     267,    -1,   266,   267,    -1,   106,   268,   273,    -1,    -1,
     268,   269,    -1,   270,    -1,   271,    -1,   272,    -1,    34,
       3,   489,    -1,    40,     3,   489,    -1,    41,    -1,    32,
       3,   489,    -1,    33,    -1,    10,   107,    -1,    11,    -1,
      -1,    54,    11,    -1,    54,    10,   275,    55,    -1,    -1,
     275,   276,    -1,   277,    -1,   278,    -1,   279,    -1,   280,
      -1,   281,    -1,   282,    -1,   297,    -1,   303,    -1,   307,
      -1,   313,    -1,   319,    -1,   130,    10,     4,   131,    -1,
     130,    10,   131,    -1,   130,    11,    -1,   132,    10,     4,
     133,    -1,   132,    10,   133,    -1,   132,    11,    -1,   116,
      10,     4,   117,    -1,   116,    10,   117,    -1,   116,    11,
      -1,    62,    10,     4,    63,    -1,    62,    10,    63,    -1,
      62,    11,    -1,    86,    10,     4,    87,    -1,    86,    10,
      87,    -1,    86,    11,    -1,   144,   283,   284,    -1,    25,
       8,     6,     8,    -1,    11,    -1,    10,   285,   145,    -1,
      -1,   285,   286,    -1,   138,   287,   293,    -1,    -1,   287,
     288,    -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,
      36,     3,     8,    -1,    37,    -1,    30,     3,     8,    -1,
      31,    -1,    38,     3,     8,    -1,    39,    -1,    32,     3,
       8,    -1,    33,    -1,   294,    -1,   295,    -1,    10,   139,
      -1,    11,    -1,    10,   296,   139,    -1,    -1,     7,    -1,
       6,    -1,   150,   298,    10,   302,   151,    -1,    -1,   298,
     299,    -1,   300,    -1,   301,    -1,    38,     3,   489,    -1,
      32,     3,   489,    -1,    33,    -1,     6,    -1,     7,    -1,
     148,   304,    10,   306,   149,    -1,    -1,   304,   305,    -1,
      32,     3,   489,    -1,    33,    -1,     6,    -1,     7,    -1,
     152,   308,    10,   312,   153,    -1,    -1,   308,   309,    -1,
     310,    -1,   311,    -1,    38,     3,   489,    -1,    32,     3,
     489,    -1,    33,    -1,     6,    -1,     7,    -1,   154,   314,
      10,   318,   155,    -1,    -1,   314,   315,    -1,   316,    -1,
     317,    -1,    38,     3,   489,    -1,    32,     3,   489,    -1,
      33,    -1,     6,    -1,     7,    -1,   108,   320,   321,    -1,
      19,   489,     6,   489,    -1,   322,    -1,   323,    -1,    10,
     109,    -1,    11,    -1,    10,   324,   109,    -1,   325,    -1,
     324,   325,    -1,   106,   326,   331,    -1,    -1,   326,   327,
      -1,   328,    -1,   329,    -1,   330,    -1,    34,     3,   489,
      -1,    40,     3,   489,    -1,    41,    -1,    32,     3,   489,
      -1,    33,    -1,    10,   107,    -1,    11,    -1,    -1,    56,
     333,   339,    -1,    -1,   333,   334,    -1,   335,   489,    -1,
     336,   489,    -1,   337,   489,    -1,   338,   489,    -1,    22,
     489,     6,    -1,    27,   489,     6,    -1,    13,   489,     6,
      -1,    16,   489,     6,    -1,    10,   340,    57,    -1,    11,
      -1,   341,   471,    -1,    -1,   341,   342,    -1,   343,   344,
     348,    -1,   124,    -1,    -1,   344,   345,    -1,   346,    -1,
     347,    -1,    28,   489,     6,   489,    -1,    42,     3,   489,
      -1,    10,   349,   362,   363,   401,   427,   453,   470,    -1,
     130,   350,   352,    -1,   351,    -1,   350,   351,    -1,    36,
       3,   489,    -1,    37,    -1,    32,     3,   489,    -1,    33,
      -1,    24,     8,     6,     8,    -1,   353,    -1,   354,    -1,
      10,   131,    -1,    11,    -1,    10,   355,   131,    -1,   356,
      -1,   355,   356,    -1,   134,   357,   361,    -1,    -1,   357,
     358,    -1,   359,    -1,   360,    -1,    36,     3,     8,    -1,
      32,     3,     8,    -1,    33,    -1,    10,   135,    -1,    11,
      -1,    -1,    96,    10,     4,    97,    -1,    96,    10,    97,
      -1,    96,    11,    -1,    -1,   162,   364,   365,    -1,    -1,
      21,   489,     6,   489,    -1,   366,    -1,   367,    -1,    11,
      -1,    10,   368,   374,   379,   384,   163,    -1,    -1,   156,
     369,    10,   370,   157,    -1,   156,   369,    11,    -1,    26,
     489,     6,   489,    -1,    -1,   370,   371,    -1,   160,   372,
      10,   373,   161,    -1,    29,   489,     6,   489,    -1,     6,
      -1,     7,    -1,    -1,   158,   375,    10,   376,   159,    -1,
     158,   375,    11,    -1,    26,   489,     6,   489,    -1,    -1,
     376,   377,    -1,   160,   378,    10,     4,   161,    -1,   160,
     378,    10,   161,    -1,   160,   378,    11,    -1,    29,   489,
       6,   489,    -1,    -1,    72,   380,    10,   381,    73,    -1,
      72,   380,    11,    -1,    26,   489,     6,   489,    -1,    -1,
     381,   382,    -1,   160,   383,    10,     4,   161,    -1,    29,
     489,     6,   489,    -1,    -1,   384,   385,    -1,    -1,   387,
     388,   386,   395,    -1,   106,    -1,   389,    -1,    -1,   389,
     390,    -1,   391,    -1,   392,    -1,   393,    -1,   394,    -1,
      26,   489,     6,   489,    -1,    41,    -1,    40,     3,   489,
      -1,    35,    -1,    34,     3,   489,    -1,    32,     3,   489,
      -1,    33,    -1,    11,    -1,    10,   396,   107,    -1,    -1,
     396,   397,    -1,   398,   399,   400,    -1,   160,    -1,    29,
     489,     6,   489,    -1,    10,   490,   161,    -1,    10,   161,
      -1,    11,    -1,    -1,   100,   402,   403,    -1,    -1,    18,
     489,     6,   489,    -1,   404,    -1,   405,    -1,    11,    -1,
      10,   406,   412,   101,    -1,    -1,   156,   407,    10,   408,
     157,    -1,   156,   407,    11,    -1,    15,   489,     6,   489,
      -1,    -1,   408,   409,    -1,    98,   410,    10,   411,    99,
      -1,    29,   489,     6,   489,    -1,     6,    -1,     7,    -1,
      -1,   412,   413,    -1,   414,   415,   421,    -1,   106,    -1,
      -1,   415,   416,    -1,   417,    -1,   418,    -1,   419,    -1,
     420,    -1,    15,   489,     6,   489,    -1,    41,    -1,    40,
       3,   489,    -1,    35,    -1,    34,     3,   489,    -1,    32,
       3,   489,    -1,    33,    -1,    11,    -1,    10,   422,   107,
      -1,    -1,   422,   423,    -1,   424,   425,   426,    -1,    98,
      -1,    29,   489,     6,   489,    -1,    10,   490,    99,    -1,
      10,    99,    -1,    11,    -1,    -1,    78,   428,   429,    -1,
      -1,    17,   489,     6,   489,    -1,   430,    -1,   431,    -1,
      11,    -1,    10,   432,   438,    79,    -1,    -1,    84,   433,
      10,   434,    85,    -1,    84,   433,    11,    -1,    12,   489,
       6,   489,    -1,    -1,   434,   435,    -1,    76,   436,    10,
     437,    77,    -1,    29,   489,     6,   489,    -1,     7,    -1,
       6,    -1,    -1,   438,   439,    -1,   440,   441,   447,    -1,
     106,    -1,    -1,   441,   442,    -1,   443,    -1,   444,    -1,
     445,    -1,   446,    -1,    12,   489,     6,   489,    -1,    41,
      -1,    40,     3,   489,    -1,    35,    -1,    34,     3,   489,
      -1,    32,     3,   489,    -1,    33,    -1,    11,    -1,    10,
     448,   107,    -1,    -1,   448,   449,    -1,   450,   451,   452,
      -1,    76,    -1,    29,   489,     6,   489,    -1,    10,   490,
      77,    -1,    10,    77,    -1,    11,    -1,    -1,   112,   454,
      10,   456,   113,    -1,   112,   454,    11,    -1,    -1,    20,
       8,     6,   455,     8,    -1,    -1,   456,   457,    -1,   110,
     458,    10,   465,   111,    -1,   110,   458,    11,    -1,    -1,
      -1,   458,   459,   460,    -1,   461,    -1,   462,    -1,   463,
      -1,   464,    -1,    14,     8,     6,     8,    -1,    35,    -1,
      34,     3,   489,    -1,    30,     3,     8,    -1,    31,    -1,
      32,     3,     8,    -1,    33,    -1,    -1,   465,   466,    -1,
     467,    -1,   468,    -1,    60,    -1,    61,    -1,    -1,    58,
       5,   469,    59,    -1,   125,    -1,    -1,   114,   472,   473,
      -1,    23,   489,     6,   489,    -1,    11,    -1,    10,   474,
     115,    -1,    -1,   474,   475,    -1,   128,   476,    10,   483,
     129,    -1,   128,   476,    11,    -1,    -1,    -1,   476,   477,
     478,    -1,   479,    -1,   480,    -1,   481,    -1,   482,    -1,
      14,     8,     6,     8,    -1,    35,    -1,    34,     3,     8,
      -1,    30,     3,     8,    -1,    31,    -1,    32,     3,     8,
      -1,    33,    -1,    -1,   483,   484,    -1,   485,    -1,   486,
      -1,    60,    -1,    61,    -1,    -1,    58,     5,   487,    59,
      -1,     6,    -1,     7,    -1,   492,     8,    -1,     4,    -1,
       6,    -1,     7,    -1,   165,    -1,   166,    -1,   167,    -1,
     168,    -1,    -1,   492,   491,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   166,   167,   169,   169,   170,   172,   172,
     175,   180,   185,   190,   195,   200,   205,   210,   215,   223,
     225,   231,   237,   237,   240,   246,   252,   256,   257,   259,
     260,   262,   272,   272,   274,   274,   276,   283,   283,   285,
     293,   300,   300,   302,   302,   309,   320,   323,   328,   328,
     332,   333,   334,   337,   338,   339,   342,   343,   344,   347,
     348,   349,   352,   353,   354,   357,   358,   359,   362,   363,
     364,   366,   368,   370,   370,   372,   372,   374,   376,   376,
     378,   380,   380,   382,   382,   382,   384,   385,   387,   388,
     390,   391,   393,   393,   397,   397,   398,   400,   400,   402,
     402,   402,   403,   403,   403,   406,   407,   408,   410,   413,
     413,   415,   415,   417,   419,   420,   423,   424,   426,   429,
     429,   431,   431,   433,   435,   436,   439,   440,   442,   445,
     445,   447,   447,   449,   451,   452,   455,   456,   459,   462,
     462,   464,   465,   468,   469,   472,   474,   476,   476,   478,
     478,   480,   482,   482,   484,   486,   486,   488,   488,   488,
     490,   492,   493,   495,   496,   498,   498,   502,   502,   503,
     505,   505,   507,   507,   507,   508,   508,   508,   511,   512,
     513,   516,   517,   518,   521,   522,   523,   526,   527,   528,
     531,   532,   533,   536,   538,   540,   540,   542,   542,   544,
     546,   546,   548,   550,   550,   552,   552,   552,   554,   556,
     557,   559,   560,   562,   562,   565,   565,   566,   568,   568,
     570,   570,   570,   570,   570,   571,   571,   571,   571,   571,
     571,   574,   575,   576,   579,   580,   581,   584,   585,   586,
     589,   590,   591,   594,   595,   596,   599,   601,   607,   607,
     609,   609,   611,   613,   613,   615,   615,   615,   615,   617,
     618,   620,   621,   623,   624,   626,   627,   629,   629,   631,
     631,   633,   644,   648,   649,   652,   655,   655,   657,   657,
     659,   661,   662,   665,   666,   669,   672,   672,   674,   675,
     678,   679,   682,   685,   685,   687,   687,   689,   691,   692,
     695,   696,   698,   701,   701,   703,   703,   705,   707,   708,
     711,   712,   716,   718,   720,   720,   722,   722,   724,   726,
     726,   728,   730,   730,   732,   732,   732,   734,   736,   737,
     739,   740,   742,   742,   746,   746,   748,   748,   750,   751,
     752,   753,   757,   758,   759,   760,   763,   763,   765,   767,
     767,   769,   776,   782,   782,   784,   784,   786,   793,   796,
     799,   801,   802,   804,   805,   806,   807,   808,   811,   817,
     823,   823,   825,   827,   827,   829,   831,   831,   833,   833,
     835,   839,   840,   842,   842,   846,   847,   851,   855,   857,
     858,   860,   861,   871,   871,   873,   875,   877,   878,   887,
     898,   905,   905,   907,   909,   912,   916,   922,   923,   932,
     934,   941,   941,   943,   948,   949,   951,   955,   955,   964,
     966,   973,   973,   975,   977,   982,   982,   985,   984,  1004,
    1012,  1018,  1018,  1020,  1020,  1020,  1020,  1022,  1034,  1037,
    1043,  1049,  1055,  1060,  1062,  1063,  1065,  1065,  1067,  1082,
    1087,  1089,  1089,  1089,  1092,  1093,  1095,  1096,  1106,  1106,
    1108,  1110,  1112,  1113,  1122,  1124,  1128,  1128,  1130,  1132,
    1135,  1139,  1145,  1145,  1147,  1150,  1158,  1159,  1161,  1161,
    1161,  1161,  1163,  1172,  1175,  1181,  1187,  1193,  1198,  1201,
    1202,  1224,  1224,  1226,  1241,  1246,  1248,  1248,  1248,  1252,
    1253,  1255,  1256,  1266,  1266,  1268,  1270,  1273,  1274,  1284,
    1286,  1291,  1291,  1293,  1295,  1298,  1302,  1308,  1308,  1310,
    1313,  1315,  1315,  1317,  1317,  1317,  1317,  1319,  1322,  1325,
    1331,  1337,  1343,  1348,  1350,  1351,  1354,  1354,  1356,  1372,
    1377,  1379,  1379,  1379,  1383,  1384,  1389,  1396,  1395,  1411,
    1411,  1414,  1421,  1430,  1431,  1431,  1435,  1435,  1435,  1435,
    1437,  1450,  1456,  1464,  1467,  1470,  1473,  1475,  1476,  1479,
    1484,  1491,  1491,  1494,  1493,  1499,  1509,  1509,  1511,  1513,
    1513,  1515,  1515,  1518,  1525,  1527,  1529,  1528,  1533,  1533,
    1533,  1533,  1535,  1550,  1557,  1566,  1572,  1575,  1581,  1583,
    1584,  1586,  1591,  1597,  1597,  1600,  1599,  1605,  1606,  1608,
    1611,  1612,  1613,  1617,  1618,  1619,  1620,  1622,  1623
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
  "generalOtherResultsAttList", "generalOtherResultsBody",
  "generalOtherResultsEmpty", "generalOtherResultsContent",
  "generalOtherResultList", "generalOtherResult", "generalOtherAttList",
  "generalOtherAtt", "generalOtherNameATT", "generalOtherValueATT",
  "generalOtherDescriptionATT", "generalOtherEnd", "systemElement",
  "systemContent", "systemChild", "systemInformation",
  "availableDiskSpace", "availableDiskSpaceAttList",
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
  "systemOtherEnd", "serviceElement", "serviceContent", "serviceChild",
  "currentState", "currentJobCount", "totalJobsSoFar",
  "timeServiceStarted", "serviceUtilization", "serviceOtherResults",
  "serviceOtherResultsAttList", "serviceOtherResultsBody",
  "serviceOtherResultsEmpty", "serviceOtherResultsContent",
  "serviceOtherResultList", "serviceOtherResult", "serviceOtherAttList",
  "serviceOtherAtt", "serviceOtherNameATT", "serviceOtherValueATT",
  "serviceOtherDescriptionATT", "serviceOtherEnd", "jobElement",
  "jobContent", "jobChild", "status", "submitTime", "scheduledStartTime",
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
     200,   201,   202,   203,   203,   204,   204,   205,   206,   206,
     207,   208,   208,   209,   209,   209,   210,   210,   211,   211,
     212,   212,   213,   213,   214,   214,   214,   215,   215,   216,
     216,   216,   216,   216,   216,   217,   217,   217,   218,   219,
     219,   220,   220,   221,   222,   222,   223,   223,   224,   225,
     225,   226,   226,   227,   228,   228,   229,   229,   230,   231,
     231,   232,   232,   233,   234,   234,   235,   235,   236,   237,
     237,   238,   238,   239,   239,   240,   241,   242,   242,   243,
     243,   244,   245,   245,   246,   247,   247,   248,   248,   248,
     249,   250,   250,   251,   251,   252,   252,   253,   253,   253,
     254,   254,   255,   255,   255,   255,   255,   255,   256,   256,
     256,   257,   257,   257,   258,   258,   258,   259,   259,   259,
     260,   260,   260,   261,   262,   263,   263,   264,   264,   265,
     266,   266,   267,   268,   268,   269,   269,   269,   270,   271,
     271,   272,   272,   273,   273,   274,   274,   274,   275,   275,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   277,   277,   277,   278,   278,   278,   279,   279,   279,
     280,   280,   280,   281,   281,   281,   282,   283,   284,   284,
     285,   285,   286,   287,   287,   288,   288,   288,   288,   289,
     289,   290,   290,   291,   291,   292,   292,   293,   293,   294,
     294,   295,   295,   296,   296,   297,   298,   298,   299,   299,
     300,   301,   301,   302,   302,   303,   304,   304,   305,   305,
     306,   306,   307,   308,   308,   309,   309,   310,   311,   311,
     312,   312,   313,   314,   314,   315,   315,   316,   317,   317,
     318,   318,   319,   320,   321,   321,   322,   322,   323,   324,
     324,   325,   326,   326,   327,   327,   327,   328,   329,   329,
     330,   330,   331,   331,   332,   332,   333,   333,   334,   334,
     334,   334,   335,   336,   337,   338,   339,   339,   340,   341,
     341,   342,   343,   344,   344,   345,   345,   346,   347,   348,
     349,   350,   350,   351,   351,   351,   351,   351,   352,   352,
     353,   353,   354,   355,   355,   356,   357,   357,   358,   358,
     359,   360,   360,   361,   361,   362,   362,   362,   362,   363,
     363,   364,   364,   365,   365,   366,   367,   368,   368,   368,
     369,   370,   370,   371,   372,   373,   373,   374,   374,   374,
     375,   376,   376,   377,   377,   377,   378,   379,   379,   379,
     380,   381,   381,   382,   383,   384,   384,   386,   385,   387,
     388,   389,   389,   390,   390,   390,   390,   391,   392,   392,
     393,   393,   394,   394,   395,   395,   396,   396,   397,   398,
     399,   400,   400,   400,   401,   401,   402,   402,   403,   403,
     404,   405,   406,   406,   406,   407,   408,   408,   409,   410,
     411,   411,   412,   412,   413,   414,   415,   415,   416,   416,
     416,   416,   417,   418,   418,   419,   419,   420,   420,   421,
     421,   422,   422,   423,   424,   425,   426,   426,   426,   427,
     427,   428,   428,   429,   429,   430,   431,   432,   432,   432,
     433,   434,   434,   435,   436,   437,   437,   438,   438,   439,
     440,   441,   441,   442,   442,   442,   442,   443,   444,   444,
     445,   445,   446,   446,   447,   447,   448,   448,   449,   450,
     451,   452,   452,   452,   453,   453,   453,   455,   454,   456,
     456,   457,   457,   458,   459,   458,   460,   460,   460,   460,
     461,   462,   462,   463,   463,   464,   464,   465,   465,   466,
     466,   467,   467,   469,   468,   470,   471,   471,   472,   473,
     473,   474,   474,   475,   475,   476,   477,   476,   478,   478,
     478,   478,   479,   480,   480,   481,   481,   482,   482,   483,
     483,   484,   484,   485,   485,   487,   486,   488,   488,   489,
     490,   490,   490,   491,   491,   491,   491,   492,   492
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
       2,     3,     4,     1,     1,     2,     1,     3,     1,     2,
       3,     0,     2,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     0,     2,     4,     0,     2,     1,
       1,     1,     1,     1,     1,     4,     3,     2,     5,     0,
       2,     1,     1,     3,     3,     1,     1,     1,     5,     0,
       2,     1,     1,     3,     3,     1,     1,     1,     5,     0,
       2,     1,     1,     3,     3,     1,     1,     1,     5,     0,
       2,     3,     1,     1,     1,     3,     4,     1,     1,     2,
       1,     3,     1,     2,     3,     0,     2,     1,     1,     1,
       3,     3,     1,     3,     1,     2,     1,     0,     2,     4,
       0,     2,     1,     1,     1,     1,     1,     1,     4,     3,
       2,     4,     3,     2,     4,     3,     2,     4,     3,     2,
       4,     3,     2,     3,     4,     1,     1,     2,     1,     3,
       1,     2,     3,     0,     2,     1,     1,     1,     3,     3,
       1,     3,     1,     2,     1,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     2,     4,     3,     2,     4,     3,     2,
       4,     3,     2,     4,     3,     2,     3,     4,     1,     3,
       0,     2,     3,     0,     2,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     2,
       1,     3,     0,     1,     1,     5,     0,     2,     1,     1,
       3,     3,     1,     1,     1,     5,     0,     2,     3,     1,
       1,     1,     5,     0,     2,     1,     1,     3,     3,     1,
       1,     1,     5,     0,     2,     1,     1,     3,     3,     1,
       1,     1,     3,     4,     1,     1,     2,     1,     3,     1,
       2,     3,     0,     2,     1,     1,     1,     3,     3,     1,
       3,     1,     2,     1,     0,     3,     0,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     1,     2,     0,
       2,     3,     1,     0,     2,     1,     1,     4,     3,     8,
       3,     1,     2,     3,     1,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     2,     3,     0,     2,     1,     1,
       3,     3,     1,     2,     1,     0,     4,     3,     2,     0,
       3,     0,     4,     1,     1,     1,     6,     0,     5,     3,
       4,     0,     2,     5,     4,     1,     1,     0,     5,     3,
       4,     0,     2,     5,     4,     3,     4,     0,     5,     3,
       4,     0,     2,     5,     4,     0,     2,     0,     4,     1,
       1,     0,     2,     1,     1,     1,     1,     4,     1,     3,
       1,     3,     3,     1,     1,     3,     0,     2,     3,     1,
       4,     3,     2,     1,     0,     3,     0,     4,     1,     1,
       1,     4,     0,     5,     3,     4,     0,     2,     5,     4,
       1,     1,     0,     2,     3,     1,     0,     2,     1,     1,
       1,     1,     4,     1,     3,     1,     3,     3,     1,     1,
       3,     0,     2,     3,     1,     4,     3,     2,     1,     0,
       3,     0,     4,     1,     1,     1,     4,     0,     5,     3,
       4,     0,     2,     5,     4,     1,     1,     0,     2,     3,
       1,     0,     2,     1,     1,     1,     1,     4,     1,     3,
       1,     3,     3,     1,     1,     3,     0,     2,     3,     1,
       4,     3,     2,     1,     0,     5,     3,     0,     5,     0,
       2,     5,     3,     0,     0,     3,     1,     1,     1,     1,
       4,     1,     3,     3,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     0,     4,     1,     0,     3,     4,     1,
       3,     0,     2,     5,     3,     0,     0,     3,     1,     1,
       1,     1,     4,     1,     3,     3,     1,     3,     1,     0,
       2,     1,     1,     1,     1,     0,     4,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    94,     4,
       8,     6,     0,   167,     0,    97,    95,     0,   215,     7,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
       0,   170,   168,     0,   334,     0,    61,     0,    64,     0,
      52,   617,     0,     0,    58,     0,    55,     0,    67,     0,
      70,     0,     0,    30,     0,    28,     0,    21,    22,    24,
      25,    26,    96,   139,   129,   109,   119,     0,     0,    98,
      99,   100,   101,   102,   103,   104,     0,   218,   216,   336,
       0,     0,    60,     0,    63,     0,    51,     0,     0,     0,
      76,    71,    73,    74,     0,    57,     0,    54,     0,    66,
       0,    69,     0,   617,   617,     0,    35,    19,    32,    33,
      23,     0,     0,     0,     0,   617,     0,     0,   107,   169,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
     175,   176,   177,     0,     0,     2,    59,    62,    50,   617,
     609,   613,   614,   615,   616,   618,    81,    75,     0,    78,
      56,    53,    65,    68,     0,    29,    27,    34,    40,     0,
      37,    41,     0,     0,   142,   140,     0,     0,   135,     0,
     130,   131,   132,     0,     0,   115,     0,   110,   111,   112,
       0,     0,   125,     0,   120,   121,   122,     0,     0,   150,
     145,   147,   148,     0,   106,     0,   183,     0,   180,   617,
       0,     0,   192,     0,   189,     0,   186,   217,     0,     0,
       0,     0,     0,     0,     0,   286,   276,   293,   303,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   349,   347,   617,   617,   617,   617,   337,   617,   617,
     617,   617,   335,    72,     0,    77,    79,    31,    36,    38,
       0,   143,   144,     0,   617,   136,   137,     0,   617,   617,
     116,   117,     0,   617,   617,   126,   127,     0,   617,   617,
     617,   155,   149,     0,   152,   105,     0,   182,     0,   179,
       0,     0,   198,   193,   195,   196,   607,   608,   191,     0,
       0,   188,     0,   185,     0,   242,     0,   245,   617,     0,
       0,   239,     0,   233,     0,   236,     0,     0,     0,     0,
       0,     0,     0,   576,     0,     0,     0,     0,   338,   339,
     340,   341,     0,    93,     0,    91,     0,    87,     0,    89,
      82,    83,    84,    85,    80,     0,    49,     0,    47,     0,
      42,    43,    44,    39,   138,   141,   128,   134,   133,   108,
     114,   113,   118,   124,   123,   146,     0,   151,   153,   181,
     178,   617,   203,   197,     0,   200,   190,   187,   184,     0,
     241,     0,   244,     0,     0,   317,   312,   314,   315,     0,
     238,     0,   232,     0,   235,     0,   250,   248,   246,     0,
       0,   289,   287,     0,     0,   282,     0,   277,   278,   279,
       0,     0,   299,     0,   294,   295,   296,     0,     0,   309,
       0,   304,   305,   306,   346,     0,   352,   350,   353,   348,
     344,   345,   342,   343,    92,   617,   617,   617,    48,     0,
       0,     0,   166,     0,   164,     0,     0,   162,   156,   157,
     158,   159,   154,   194,     0,   199,   201,   240,   243,   617,
     322,   316,     0,   319,   237,   231,   234,     0,     0,   290,
     291,     0,   617,   283,   284,     0,   617,   617,   300,   301,
       0,   617,   617,   310,   311,     0,   617,   617,   617,     0,
       0,    90,    86,    88,    46,    45,   165,   617,   617,   617,
       0,   214,     0,   212,     0,     0,   210,   204,   205,   206,
     207,   202,   313,     0,   318,   320,   247,   253,   249,   251,
     285,   288,   275,   281,   280,   292,   298,   297,   302,   308,
     307,     0,   581,   579,   577,     0,   617,     0,   354,   355,
     356,   351,   163,   160,   161,   213,   617,   617,   617,     0,
     333,     0,   331,     0,     0,   329,   323,   324,   325,   326,
     321,   272,   617,     0,     0,   385,     0,   617,   211,   208,
     209,   332,   617,   617,   617,     0,   270,     0,   262,     0,
     266,     0,   260,     0,   264,   254,   255,   256,   257,   258,
     252,   267,   268,   578,   580,   585,   582,     0,     0,   366,
       0,   364,     0,   361,     0,   389,   617,   358,   330,   327,
     328,   274,   273,   269,     0,     0,     0,     0,     0,   586,
       0,   617,   617,     0,   371,   362,   360,   368,   369,     0,
     388,   391,   454,   357,   271,   261,   265,   259,   263,   599,
     584,     0,     0,   365,   363,   370,   376,     0,   373,     0,
     387,   617,     0,   456,   499,     0,     0,     0,   596,     0,
     598,     0,   593,   587,   588,   589,   590,   591,   367,     0,
     372,   374,   386,     0,   397,   395,   390,   393,   394,   617,
       0,   501,   544,     0,   603,   604,   583,   600,   601,   602,
       0,     0,     0,     0,     0,   384,     0,   382,     0,   377,
     378,   379,   375,   617,     0,   407,     0,   462,   460,   455,
     458,   459,   617,     0,     0,     0,   605,     0,   595,   597,
     594,   383,     0,     0,   392,   617,     0,     0,   417,   617,
       0,   472,     0,   507,   505,   500,   503,   504,     0,     0,
     575,   359,     0,   592,   381,   380,     0,   401,   399,   617,
       0,     0,   425,   457,   617,     0,     0,   617,     0,   517,
       0,   549,   546,   606,   617,     0,     0,   411,   409,   617,
       0,     0,     0,   466,   464,   461,   475,   473,   476,   502,
     617,     0,     0,   547,     0,   400,   398,     0,   402,   617,
       0,     0,   421,   419,   429,   396,   426,   431,   617,     0,
       0,     0,   511,   509,   506,   520,   518,   521,     0,   553,
     545,   550,   617,     0,   410,   408,     0,   412,   617,     0,
     427,   430,   465,     0,   463,   467,   491,   489,   617,     0,
     488,     0,   485,     0,   483,   477,   478,   479,   480,   481,
     474,   617,     0,     0,   548,   554,     0,     0,   617,     0,
     420,   418,     0,   422,     0,   617,     0,   443,     0,   440,
       0,   438,   432,   433,   434,   435,   436,   617,     0,     0,
       0,   617,   617,   617,   510,     0,   508,   512,   536,   534,
     617,     0,   533,     0,   530,     0,   528,   522,   523,   524,
     525,   526,   519,   567,   552,     0,   617,   405,   406,     0,
       0,     0,   415,   617,     0,   446,   444,   428,     0,   617,
     617,   617,     0,     0,   494,   490,   492,     0,   617,   487,
     486,   484,   617,     0,     0,     0,   617,   617,   617,     0,
       0,     0,   564,     0,   566,     0,   561,   555,   556,   557,
     558,   559,   404,   403,   617,     0,   414,     0,     0,     0,
     617,   442,   441,   439,   617,   470,   471,     0,   617,     0,
     482,     0,     0,   539,   535,   537,     0,   617,   532,   531,
     529,     0,   571,   572,   551,   568,   569,   570,     0,     0,
       0,   617,   416,   413,   617,     0,   445,   449,   447,     0,
     437,   469,   468,     0,     0,   498,   493,   617,   516,   515,
       0,   617,     0,   527,   573,     0,   563,   565,   562,   424,
     423,   617,     0,   617,   610,   611,   612,   497,     0,   514,
     513,     0,     0,   543,   538,     0,   560,     0,     0,   453,
     448,   495,   496,   617,   542,     0,   574,   617,   452,     0,
     540,   541,   450,   451
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    31,    66,    67,
      68,    69,    70,    71,   117,   118,   119,   169,   170,   171,
     260,   350,   351,   352,   353,    32,    33,    34,    35,    36,
      37,    38,    39,    52,   101,   102,   103,   158,   159,   254,
     340,   341,   342,   343,   344,    13,    40,    79,    80,    81,
     123,   187,   188,   189,   272,    82,   124,   194,   195,   196,
     277,    83,   122,   180,   181,   182,   267,    84,   121,   175,
     263,    85,   126,   200,   201,   202,   283,   284,   366,   448,
     449,   450,   451,   452,    18,    86,   136,   137,   138,   139,
     140,   141,   142,   210,   293,   294,   295,   374,   375,   454,
     507,   508,   509,   510,   511,    44,   143,   229,   230,   231,
     232,   233,   234,   235,   317,   398,   468,   519,   561,   585,
     586,   587,   588,   589,   590,   591,   592,   614,   236,   319,
     407,   408,   409,   475,   237,   318,   402,   471,   238,   320,
     414,   415,   416,   480,   239,   321,   421,   422,   423,   485,
     240,   309,   386,   387,   388,   462,   463,   513,   556,   557,
     558,   559,   560,    90,   144,   247,   248,   249,   250,   251,
     252,   322,   323,   427,   428,   490,   538,   539,   540,   541,
     565,   602,   603,   626,   627,   628,   647,   648,   669,   699,
     700,   701,   702,   605,   632,   652,   676,   677,   678,   705,
     726,   765,   788,   813,   899,   728,   750,   790,   817,   849,
     752,   770,   819,   853,   904,   771,   796,   854,   797,   820,
     821,   862,   863,   864,   865,   866,   907,   949,   988,   989,
    1012,  1030,   654,   680,   709,   710,   711,   731,   755,   799,
     825,   868,   957,   756,   777,   778,   800,   835,   836,   837,
     838,   839,   840,   869,   916,   917,   959,   996,   682,   713,
     735,   736,   737,   759,   781,   842,   877,   923,  1000,   782,
     806,   807,   843,   887,   888,   889,   890,   891,   892,   924,
     965,   966,  1002,  1024,   715,   739,   808,   784,   811,   845,
     895,   937,   938,   939,   940,   941,   929,   975,   976,   977,
    1025,   741,   429,   489,   534,   563,   596,   619,   641,   663,
     664,   665,   666,   667,   655,   687,   688,   689,   742,   299,
      97,  1018,   155,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -950
static const yytype_int16 yypact[] =
{
      37,    29,    59,    51,  -950,    75,  -950,   186,    53,  -950,
    -950,  -950,   224,    55,   -31,  -950,  -950,   239,    67,  -950,
    -950,   262,   305,   339,    90,   350,   366,   368,   372,  -950,
    -950,   152,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
     111,  -950,  -950,   381,    69,    31,  -950,    24,  -950,    17,
    -950,  -950,   383,    15,  -950,    18,  -950,    13,  -950,     4,
    -950,   119,   169,  -950,   171,  -950,   387,   152,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,   161,   389,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,    70,  -950,  -950,  -950,
     139,   108,  -950,   114,  -950,   121,  -950,   205,     3,    48,
    -950,  -950,  -950,  -950,   124,  -950,   138,  -950,   165,  -950,
     123,  -950,   311,  -950,  -950,   -48,  -950,  -950,  -950,  -950,
    -950,    60,   236,   247,   255,  -950,   391,     6,  -950,  -950,
     393,   395,   283,   397,   399,   401,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,   -32,    56,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,    84,  -950,
    -950,  -950,  -950,  -950,   335,  -950,  -950,  -950,  -950,   -33,
    -950,  -950,   407,   348,  -950,  -950,   409,   359,  -950,   362,
    -950,  -950,  -950,   411,   369,  -950,   377,  -950,  -950,  -950,
     413,   429,  -950,   497,  -950,  -950,  -950,   482,    85,  -950,
    -950,  -950,  -950,   367,  -950,     7,  -950,    25,  -950,  -950,
     414,    19,  -950,     5,  -950,    -3,  -950,  -950,   416,   418,
     486,   420,   426,   428,   423,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,   192,  -950,  -950,  -950,  -950,  -950,
     301,  -950,  -950,   441,  -950,  -950,  -950,   436,  -950,  -950,
    -950,  -950,   443,  -950,  -950,  -950,  -950,   439,  -950,  -950,
    -950,  -950,  -950,   133,  -950,  -950,   433,  -950,   424,  -950,
     505,   142,  -950,  -950,  -950,  -950,  -950,  -950,  -950,   390,
     374,  -950,   370,  -950,    34,  -950,    23,  -950,  -950,   430,
      28,  -950,    10,  -950,    16,  -950,   508,   432,    96,   257,
     276,   287,   461,   -50,   513,   514,   515,   516,  -950,  -950,
    -950,  -950,   417,  -950,   520,  -950,   522,  -950,   523,  -950,
    -950,  -950,  -950,  -950,  -950,   392,  -950,   525,  -950,   526,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,   204,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,   185,  -950,  -950,  -950,  -950,   467,
    -950,   446,  -950,   528,   190,  -950,  -950,  -950,  -950,   419,
    -950,   400,  -950,   402,  -950,   531,  -950,  -950,  -950,   415,
     529,  -950,  -950,   438,   536,  -950,   537,  -950,  -950,  -950,
     440,   538,  -950,   539,  -950,  -950,  -950,   444,   540,  -950,
     541,  -950,  -950,  -950,  -950,   524,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,   542,
     543,   448,  -950,   545,  -950,   546,   549,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,   220,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,   194,  -950,  -950,  -950,  -950,   548,   -83,  -950,
    -950,   396,  -950,  -950,  -950,   403,  -950,  -950,  -950,  -950,
     404,  -950,  -950,  -950,  -950,   398,  -950,  -950,  -950,   442,
      40,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
     451,  -950,   556,  -950,   557,   558,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,   230,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,   559,  -950,  -950,  -950,   434,  -950,   560,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,   455,
    -950,   564,  -950,   565,   566,  -950,  -950,  -950,  -950,  -950,
    -950,   245,  -950,   -57,   334,   450,   567,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,     9,  -950,   568,  -950,   569,
    -950,   571,  -950,   572,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,   562,   573,  -950,
     574,  -950,   294,  -950,   445,   421,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,   449,   570,   576,   577,   578,   447,
     575,  -950,  -950,   167,  -950,  -950,  -950,  -950,  -950,    20,
    -950,   561,   480,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,   307,   579,  -950,  -950,  -950,  -950,   179,  -950,   492,
    -950,  -950,   452,   580,   501,   -14,   583,   589,  -950,   590,
    -950,   591,  -950,  -950,  -950,  -950,  -950,  -950,  -950,   296,
    -950,  -950,  -950,   594,   453,  -950,  -950,  -950,  -950,  -950,
     454,   584,   483,   592,  -950,  -950,  -950,  -950,  -950,  -950,
     596,   588,   595,   597,   469,  -950,   603,  -950,   604,  -950,
    -950,  -950,  -950,  -950,   582,   457,   605,   463,  -950,  -950,
    -950,  -950,  -950,   456,   593,   489,  -950,   602,  -950,  -950,
    -950,  -950,   609,   610,  -950,  -950,   458,   598,   550,  -950,
     606,  -950,   614,   544,  -950,  -950,  -950,  -950,   615,   460,
    -950,  -950,   581,  -950,  -950,  -950,   619,  -950,  -950,  -950,
     462,   600,  -950,  -950,  -950,   464,    52,  -950,   617,  -950,
     621,  -950,  -950,  -950,  -950,   187,   624,  -950,  -950,  -950,
     466,   -58,   625,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,   468,   -26,  -950,   235,  -950,  -950,   608,  -950,  -950,
     321,   626,  -950,  -950,  -950,  -950,  -950,  -950,  -950,   -53,
     172,   627,  -950,  -950,  -950,  -950,  -950,  -950,   630,  -950,
    -950,  -950,  -950,   629,  -950,  -950,   613,  -950,  -950,   -66,
    -950,   355,  -950,   616,  -950,  -950,  -950,  -950,  -950,   631,
    -950,   632,  -950,   640,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,    88,   188,  -950,   472,   641,   478,  -950,   476,
    -950,  -950,   620,  -950,   479,  -950,   643,  -950,   645,  -950,
     647,  -950,  -950,  -950,  -950,  -950,  -950,  -950,   642,   110,
     648,  -950,  -950,  -950,  -950,   628,  -950,  -950,  -950,  -950,
    -950,   650,  -950,   652,  -950,   655,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,   322,  -950,  -950,  -950,   498,
     654,     2,  -950,  -950,   651,  -950,  -950,  -950,   656,  -950,
    -950,  -950,   657,   485,  -950,  -950,  -950,   635,  -950,  -950,
    -950,  -950,  -950,   658,   -16,   659,  -950,  -950,  -950,    -9,
     661,   663,  -950,   667,  -950,   668,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,   511,  -950,   669,   670,   -70,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,   585,  -950,   484,
    -950,   671,   490,  -950,  -950,  -950,   644,  -950,  -950,  -950,
    -950,   673,  -950,  -950,  -950,  -950,  -950,  -950,   674,   675,
     678,  -950,  -950,  -950,  -950,   518,  -950,  -950,  -950,   653,
    -950,  -950,  -950,   681,    27,  -950,  -950,  -950,  -950,  -950,
     611,  -950,   488,  -950,  -950,   682,  -950,  -950,  -950,  -950,
    -950,  -950,   491,  -950,  -950,  -950,  -950,  -950,   599,  -950,
    -950,   683,    36,  -950,  -950,   622,  -950,   685,    -2,  -950,
    -950,  -950,  -950,  -950,  -950,   618,  -950,  -950,  -950,   532,
    -950,  -950,  -950,  -950
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
     633,  -950,  -950,  -950,  -950,  -950,  -950,  -950,   527,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,   534,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,   425,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,   320,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,   240,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,    95,  -950,  -950,  -950,  -950,    54,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,  -950,
    -113,  -949,  -950,  -950
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     165,   166,  1014,   302,  1015,  1016,   945,   851,   110,   300,
     203,   150,   197,   286,   391,   611,   612,   108,    19,   104,
     393,    95,   106,   217,   649,   296,   297,   381,    93,   288,
     218,  1014,   389,  1015,  1016,    91,   253,   986,   379,     4,
    1014,   167,  1015,  1016,   683,   823,   684,   685,   794,   971,
     535,   972,   973,   804,   219,   517,   258,    20,   594,     6,
     963,    21,   518,    22,   425,    23,   241,   242,   536,   243,
     172,   595,   244,  1035,   426,     5,   220,    24,   245,  1039,
     805,     1,   537,   246,   221,     9,   168,    25,   287,    26,
     987,   964,   173,   174,   852,    27,   290,   380,   222,     7,
     223,   168,   974,    12,   824,   795,   399,    17,   289,    51,
     382,    28,   224,  1034,    96,   686,   225,   650,   226,    94,
     227,    43,   228,   129,    92,    89,  1017,   112,   400,   401,
     324,   325,   326,   327,   105,   328,   329,   330,   331,   107,
     109,   392,   298,   204,   303,   390,   301,   111,   613,   394,
     130,   355,   131,   775,   156,   357,   358,   157,   776,  1038,
     360,   361,    72,   946,   875,   363,   364,   365,   151,   152,
     153,   154,   113,   876,   114,    73,    61,    74,   132,    75,
     125,    76,   826,   827,    62,    63,   145,   828,    64,    65,
     156,   281,   133,   255,   282,   383,    10,    11,   878,   879,
     880,   146,   332,   333,   829,   830,   831,   832,   914,   147,
     134,   149,   833,   834,   441,   442,   135,   915,   148,    77,
     881,   882,   883,   884,   334,   335,   336,   337,   885,   886,
     500,   501,   338,   339,    15,    16,   443,   444,   445,   281,
     549,   550,   367,   160,   446,   447,   176,    78,   372,    41,
      42,   373,   502,   503,   504,   575,   576,   183,   453,   161,
     505,   506,   551,   552,   553,   190,   163,   403,   177,   178,
     554,   555,    45,    46,   179,   577,   578,   579,   580,   184,
     185,   581,   582,   583,   584,   186,   410,   191,   192,   404,
     405,   372,   162,   193,   455,   406,   460,   417,   645,   461,
     460,   646,   209,   514,   623,   624,   694,   695,   411,   412,
     670,   345,   346,   646,   413,    47,    48,   164,   597,   418,
     419,   656,   491,   492,   493,   420,   598,   599,   696,   697,
     600,   601,   698,   347,   348,   349,   930,   657,   658,   659,
     660,   661,   662,   257,   786,   809,   512,   787,   810,    49,
      50,   264,   931,   932,   933,   934,   935,   936,   597,   521,
      53,    54,   268,   523,   524,   269,   598,   599,   526,   527,
     600,   601,   273,   529,   530,   531,    55,    56,    57,    58,
     274,   855,    59,    60,   542,   543,   544,   856,   857,   858,
     859,    87,    88,    99,   100,   860,   861,   115,   116,   127,
     128,   198,   199,   205,   206,   207,   208,   211,   212,   213,
     214,   215,   216,   261,   262,   265,   266,   270,   271,   275,
     276,   469,   470,   566,   291,   292,   304,   305,   306,   307,
     310,   311,   278,   568,   569,   570,   312,   313,   314,   315,
     384,   385,   396,   397,   473,   474,   478,   479,   316,   593,
     483,   484,   532,   533,   607,   629,   630,   639,   640,   608,
     609,   610,   674,   675,   707,   708,   733,   734,   747,   748,
     761,   762,   767,   768,   773,   774,   792,   793,   802,   803,
     815,   816,   893,   894,   897,   898,   901,   902,   280,   905,
     906,   955,   956,   633,   994,   995,   998,   999,  1022,  1023,
     279,  1028,  1029,   356,   285,   308,   354,   370,   643,   644,
     362,   371,   359,   376,   369,   377,   395,   378,   424,   430,
     431,   432,   433,   435,   434,   436,   437,   438,   439,   440,
     457,   465,   472,   458,   459,   466,   464,   467,   673,   476,
     477,   481,   482,   486,   487,   520,   604,   488,   497,   498,
     494,   495,   499,   528,   522,   496,   516,   525,   545,   546,
     547,   548,   571,   567,   564,   562,   706,   572,   573,   574,
     620,   615,   616,   606,   617,   618,   621,   622,   635,   681,
     653,   642,   651,   631,   636,   637,   638,   668,   634,   672,
     724,   690,   691,   692,   693,   714,   718,   716,   679,   732,
     703,   712,   717,   719,   721,   720,   722,   723,   725,   704,
     743,   729,   746,   738,   740,   727,   753,   744,   745,   730,
     757,   754,   751,   760,   749,   764,   769,   783,   758,   780,
     789,   798,   818,   841,   871,   872,   766,   812,   844,   847,
     763,   772,   848,   873,   779,   867,   909,   896,   910,   903,
     911,   785,   913,   926,   918,   927,   791,   922,   928,   943,
     944,   948,   950,   954,   958,   967,   979,   801,   962,   978,
     980,   981,   983,  1001,   985,   984,   814,   997,  1004,  1010,
    1005,  1036,  1011,  1006,   992,   822,  1007,  1013,  1020,  1033,
    1026,  1037,   256,  1043,   456,  1041,   259,   625,  1032,   846,
     120,   671,   515,     0,     0,   850,     0,     0,   368,     0,
       0,     0,     0,     0,     0,   870,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   874,     0,
       0,     0,     0,     0,     0,   900,     0,     0,     0,     0,
       0,     0,   908,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   912,     0,     0,     0,   919,   920,
     921,     0,     0,     0,     0,     0,     0,   925,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   942,     0,     0,     0,     0,     0,     0,
     947,     0,     0,     0,     0,     0,   951,   952,   953,     0,
       0,     0,     0,     0,     0,   960,     0,     0,     0,   961,
       0,     0,     0,   968,   969,   970,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   982,     0,     0,     0,     0,     0,   990,     0,     0,
       0,   991,     0,     0,     0,   993,     0,     0,     0,     0,
       0,     0,     0,     0,  1003,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1008,     0,
       0,  1009,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1019,     0,     0,     0,  1021,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1027,     0,
    1031,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1040,     0,     0,     0,  1042
};

static const yytype_int16 yycheck[] =
{
     113,   114,     4,     6,     6,     7,     4,    73,     4,     4,
       4,     8,   125,     6,     4,     6,     7,     4,    49,     4,
       4,     4,     4,    55,     4,     6,     7,     4,     4,     4,
      62,     4,     4,     6,     7,     4,   149,   107,     4,    10,
       4,    89,     6,     7,    58,    98,    60,    61,   106,    58,
      10,    60,    61,    79,    86,   138,    89,    88,   115,     0,
      76,    92,   145,    94,   114,    96,    10,    11,    28,    13,
      10,   128,    16,  1022,   124,    46,   108,   108,    22,  1028,
     106,    44,    42,    27,   116,    10,   134,   118,    81,   120,
     160,   107,    32,    33,   160,   126,   209,    63,   130,    48,
     132,   134,   111,    50,   157,   163,    10,    52,    83,    19,
      87,   142,   144,    77,    97,   129,   148,    97,   150,    95,
     152,    54,   154,    53,    93,    56,    99,     8,    32,    33,
     243,   244,   245,   246,   119,   248,   249,   250,   251,   121,
     127,   131,   123,   137,   147,   117,   141,   143,   139,   133,
      80,   264,    82,   101,   106,   268,   269,   109,   106,   161,
     273,   274,    51,   161,    76,   278,   279,   280,   165,   166,
     167,   168,     3,    85,     3,    64,    24,    66,   108,    68,
      19,    70,    10,    11,    32,    33,    47,    15,    36,    37,
     106,   106,   122,   109,   109,   308,    10,    11,    10,    11,
      12,    93,    10,    11,    32,    33,    34,    35,    98,    95,
     140,     6,    40,    41,    10,    11,   146,   107,    97,   108,
      32,    33,    34,    35,    32,    33,    34,    35,    40,    41,
      10,    11,    40,    41,    10,    11,    32,    33,    34,   106,
      10,    11,   109,   119,    40,    41,    10,   136,   106,    10,
      11,   109,    32,    33,    34,    10,    11,    10,   371,   121,
      40,    41,    32,    33,    34,    10,   143,    10,    32,    33,
      40,    41,    10,    11,    38,    30,    31,    32,    33,    32,
      33,    36,    37,    38,    39,    38,    10,    32,    33,    32,
      33,   106,   127,    38,   109,    38,   106,    10,   131,   109,
     106,   134,    19,   109,    10,    11,    10,    11,    32,    33,
     131,    10,    11,   134,    38,    10,    11,     6,    24,    32,
      33,    14,   435,   436,   437,    38,    32,    33,    32,    33,
      36,    37,    36,    32,    33,    34,    14,    30,    31,    32,
      33,    34,    35,     8,   157,   110,   459,   160,   113,    10,
      11,     3,    30,    31,    32,    33,    34,    35,    24,   472,
      10,    11,     3,   476,   477,     3,    32,    33,   481,   482,
      36,    37,     3,   486,   487,   488,    10,    11,    10,    11,
       3,    26,    10,    11,   497,   498,   499,    32,    33,    34,
      35,    10,    11,    10,    11,    40,    41,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,     6,     7,     6,     7,     6,     7,     6,
       7,     6,     7,   536,    10,    11,    10,    11,    10,    11,
      10,    11,     3,   546,   547,   548,    10,    11,    10,    11,
      10,    11,    10,    11,     6,     7,     6,     7,    25,   562,
       6,     7,    10,    11,   567,    10,    11,    10,    11,   572,
     573,   574,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     159,   160,    10,    11,     6,     7,    10,    11,     6,    10,
      11,     6,     7,   606,    10,    11,     6,     7,    10,    11,
       3,    10,    11,    67,   137,    19,    65,    83,   621,   622,
      71,     6,    69,   123,    81,   141,     8,   147,    57,     6,
       6,     6,     6,     3,   107,     3,     3,   135,     3,     3,
      63,   131,     3,    87,     6,   133,   117,     6,   651,     3,
       3,     3,     3,     3,     3,   149,    96,    23,     3,     3,
       8,     8,     3,   155,   151,   107,     8,   153,   107,     3,
       3,     3,   107,     3,   130,     6,   679,     3,     3,     3,
       8,     3,     3,     6,     3,     3,     3,     3,     8,    78,
     100,     6,    21,   162,     8,     8,     8,     8,   139,    97,
     703,     8,     3,     3,     3,   112,     8,     5,    18,   712,
       6,    17,     6,     8,   135,     8,     3,     3,    26,   156,
       8,     6,   725,    20,   125,   158,   729,     8,     8,   156,
       6,    15,    72,     8,    26,     6,    26,     6,    84,    12,
       6,     6,     6,     6,     3,     3,   749,    29,     8,    10,
      59,   754,    29,     3,   757,    29,     3,     6,     3,    29,
       3,   764,    10,     3,     6,     3,   769,    29,     3,   161,
       6,    10,     6,     6,    29,     6,     3,   780,    10,     8,
       3,     3,   161,    29,     4,     6,   789,     6,     5,   161,
       6,    59,    29,     8,    99,   798,     8,     6,    77,     6,
       8,     6,   158,   161,   374,    77,   169,   602,    99,   812,
      67,   647,   462,    -1,    -1,   818,    -1,    -1,   283,    -1,
      -1,    -1,    -1,    -1,    -1,   828,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   841,    -1,
      -1,    -1,    -1,    -1,    -1,   848,    -1,    -1,    -1,    -1,
      -1,    -1,   855,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   867,    -1,    -1,    -1,   871,   872,
     873,    -1,    -1,    -1,    -1,    -1,    -1,   880,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   896,    -1,    -1,    -1,    -1,    -1,    -1,
     903,    -1,    -1,    -1,    -1,    -1,   909,   910,   911,    -1,
      -1,    -1,    -1,    -1,    -1,   918,    -1,    -1,    -1,   922,
      -1,    -1,    -1,   926,   927,   928,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   944,    -1,    -1,    -1,    -1,    -1,   950,    -1,    -1,
      -1,   954,    -1,    -1,    -1,   958,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   967,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   981,    -1,
      -1,   984,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   997,    -1,    -1,    -1,  1001,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1011,    -1,
    1013,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1033,    -1,    -1,    -1,  1037
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   214,   173,    10,    11,    52,   253,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   176,   194,   195,   196,   197,   198,   199,   200,   201,
     215,    10,    11,    54,   274,    10,    11,    10,    11,    10,
      11,    19,   202,    10,    11,    10,    11,    10,    11,    10,
      11,    24,    32,    33,    36,    37,   177,   178,   179,   180,
     181,   182,    51,    64,    66,    68,    70,   108,   136,   216,
     217,   218,   224,   230,   236,   240,   254,    10,    11,    56,
     332,     4,    93,     4,    95,     4,    97,   489,   492,    10,
      11,   203,   204,   205,     4,   119,     4,   121,     4,   127,
       4,   143,     8,     3,     3,    10,    11,   183,   184,   185,
     179,   237,   231,   219,   225,    19,   241,    10,    11,    53,
      80,    82,   108,   122,   140,   146,   255,   256,   257,   258,
     259,   260,   261,   275,   333,    47,    93,    95,    97,     6,
       8,   165,   166,   167,   168,   491,   106,   109,   206,   207,
     119,   121,   127,   143,     6,   489,   489,    89,   134,   186,
     187,   188,    10,    32,    33,   238,    10,    32,    33,    38,
     232,   233,   234,    10,    32,    33,    38,   220,   221,   222,
      10,    32,    33,    38,   226,   227,   228,   489,    10,    11,
     242,   243,   244,     4,   137,    10,    11,    10,    11,    19,
     262,    10,    11,    10,    11,    10,    11,    55,    62,    86,
     108,   116,   130,   132,   144,   148,   150,   152,   154,   276,
     277,   278,   279,   280,   281,   282,   297,   303,   307,   313,
     319,    10,    11,    13,    16,    22,    27,   334,   335,   336,
     337,   338,   339,   489,   208,   109,   207,     8,    89,   187,
     189,     6,     7,   239,     3,     6,     7,   235,     3,     3,
       6,     7,   223,     3,     3,     6,     7,   229,     3,     3,
       6,   106,   109,   245,   246,   137,     6,    81,     4,    83,
     489,    10,    11,   263,   264,   265,     6,     7,   123,   488,
       4,   141,     6,   147,    10,    11,    10,    11,    19,   320,
      10,    11,    10,    11,    10,    11,    25,   283,   304,   298,
     308,   314,   340,   341,   489,   489,   489,   489,   489,   489,
     489,   489,    10,    11,    32,    33,    34,    35,    40,    41,
     209,   210,   211,   212,   213,    10,    11,    32,    33,    34,
     190,   191,   192,   193,    65,   489,    67,   489,   489,    69,
     489,   489,    71,   489,   489,   489,   247,   109,   246,    81,
      83,     6,   106,   109,   266,   267,   123,   141,   147,     4,
      63,     4,    87,   489,    10,    11,   321,   322,   323,     4,
     117,     4,   131,     4,   133,     8,    10,    11,   284,    10,
      32,    33,   305,    10,    32,    33,    38,   299,   300,   301,
      10,    32,    33,    38,   309,   310,   311,    10,    32,    33,
      38,   315,   316,   317,    57,   114,   124,   342,   343,   471,
       6,     6,     6,     6,   107,     3,     3,     3,   135,     3,
       3,    10,    11,    32,    33,    34,    40,    41,   248,   249,
     250,   251,   252,   489,   268,   109,   267,    63,    87,     6,
     106,   109,   324,   325,   117,   131,   133,     6,   285,     6,
       7,   306,     3,     6,     7,   302,     3,     3,     6,     7,
     312,     3,     3,     6,     7,   318,     3,     3,    23,   472,
     344,   489,   489,   489,     8,     8,   107,     3,     3,     3,
      10,    11,    32,    33,    34,    40,    41,   269,   270,   271,
     272,   273,   489,   326,   109,   325,     8,   138,   145,   286,
     149,   489,   151,   489,   489,   153,   489,   489,   155,   489,
     489,   489,    10,    11,   473,    10,    28,    42,   345,   346,
     347,   348,   489,   489,   489,   107,     3,     3,     3,    10,
      11,    32,    33,    34,    40,    41,   327,   328,   329,   330,
     331,   287,     6,   474,   130,   349,   489,     3,   489,   489,
     489,   107,     3,     3,     3,    10,    11,    30,    31,    32,
      33,    36,    37,    38,    39,   288,   289,   290,   291,   292,
     293,   294,   295,   489,   115,   128,   475,    24,    32,    33,
      36,    37,   350,   351,    96,   362,     6,   489,   489,   489,
     489,     6,     7,   139,   296,     3,     3,     3,     3,   476,
       8,     3,     3,    10,    11,   351,   352,   353,   354,    10,
      11,   162,   363,   489,   139,     8,     8,     8,     8,    10,
      11,   477,     6,   489,   489,   131,   134,   355,   356,     4,
      97,    21,   364,   100,   401,   483,    14,    30,    31,    32,
      33,    34,    35,   478,   479,   480,   481,   482,     8,   357,
     131,   356,    97,   489,    10,    11,   365,   366,   367,    18,
     402,    78,   427,    58,    60,    61,   129,   484,   485,   486,
       8,     3,     3,     3,    10,    11,    32,    33,    36,   358,
     359,   360,   361,     6,   156,   368,   489,    10,    11,   403,
     404,   405,    17,   428,   112,   453,     5,     6,     8,     8,
       8,   135,     3,     3,   489,    26,   369,   158,   374,     6,
     156,   406,   489,    10,    11,   429,   430,   431,    20,   454,
     125,   470,   487,     8,     8,     8,   489,    10,    11,    26,
     375,    72,   379,   489,    15,   407,   412,     6,    84,   432,
       8,    10,    11,    59,     6,   370,   489,    10,    11,    26,
     380,   384,   489,    10,    11,   101,   106,   413,   414,   489,
      12,   433,   438,     6,   456,   489,   157,   160,   371,     6,
     376,   489,    10,    11,   106,   163,   385,   387,     6,   408,
     415,   489,    10,    11,    79,   106,   439,   440,   455,   110,
     113,   457,    29,   372,   489,   159,   160,   377,     6,   381,
     388,   389,   489,    98,   157,   409,    10,    11,    15,    32,
      33,    34,    35,    40,    41,   416,   417,   418,   419,   420,
     421,     6,   434,   441,     8,   458,   489,    10,    29,   378,
     489,    73,   160,   382,   386,    26,    32,    33,    34,    35,
      40,    41,   390,   391,   392,   393,   394,    29,   410,   422,
     489,     3,     3,     3,   489,    76,    85,   435,    10,    11,
      12,    32,    33,    34,    35,    40,    41,   442,   443,   444,
     445,   446,   447,    10,    11,   459,     6,     6,     7,   373,
     489,    10,    11,    29,   383,    10,    11,   395,   489,     3,
       3,     3,   489,    10,    98,   107,   423,   424,     6,   489,
     489,   489,    29,   436,   448,   489,     3,     3,     3,   465,
      14,    30,    31,    32,    33,    34,    35,   460,   461,   462,
     463,   464,   489,   161,     6,     4,   161,   489,    10,   396,
       6,   489,   489,   489,     6,     6,     7,   411,    29,   425,
     489,   489,    10,    76,   107,   449,   450,     6,   489,   489,
     489,    58,    60,    61,   111,   466,   467,   468,     8,     3,
       3,     3,   489,   161,     6,     4,   107,   160,   397,   398,
     489,   489,    99,   489,    10,    11,   426,     6,     6,     7,
     437,    29,   451,   489,     5,     6,     8,     8,   489,   489,
     161,    29,   399,     6,     4,     6,     7,    99,   490,   489,
      77,   489,    10,    11,   452,   469,     8,   489,    10,    11,
     400,   489,    99,     6,    77,   490,    59,     6,   161,   490,
     489,    77,   489,   161
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
	}
    break;

  case 11:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	}
    break;

  case 12:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	}
    break;

  case 13:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	}
    break;

  case 14:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	}
    break;

  case 15:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	}
    break;

  case 16:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	}
    break;

  case 17:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	}
    break;

  case 18:

    {	if (parserData->generalOtherPresent)
			osrlerror(NULL, NULL, parserData, "only one general other element allowed");
		parserData->generalOtherPresent = true;
	}
    break;

  case 20:

    {	parserData->generalStatusTypePresent = false;
		parserData->generalStatusDescriptionPresent = false;
		parserData->generalStatusNumberOfPresent = false;
	}
    break;

  case 21:

    {	if (!parserData->generalStatusTypePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	}
    break;

  case 24:

    {   if (parserData->generalStatusTypePresent ) 
		    osrlerror(NULL, NULL, parserData, "only one type attribute allowed for generalStatus element");
	    parserData->generalStatusTypePresent = true;
		osresult->setGeneralStatusType(parserData->tempStr); 
	}
    break;

  case 25:

    {   if (parserData->generalStatusDescriptionPresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for generalStatus element");
	    parserData->generalStatusDescriptionPresent = true;
		osresult->setGeneralStatusDescription(parserData->tempStr);
	}
    break;

  case 26:

    { std::cout << "parsed numberOfGeneralSubstatuses" << std::endl;
	}
    break;

  case 27:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 28:

    { parserData->tempStr = "";          }
    break;

  case 29:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 30:

    { parserData->tempStr = "";          }
    break;

  case 31:

    {   if (parserData->generalStatusNumberOfPresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for generalStatus element");
    parserData->generalStatusNumberOfPresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of general substatuses cannot be negative");
    osresult->setGeneralStatusNumberOf((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
}
    break;

  case 36:

    {std::cout << "parserData->kounter = " << parserData->kounter << std::endl;
std::cout << "parserData->numberOf = " << parserData->numberOf << std::endl;
	if (parserData->kounter != parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
}
    break;

  case 39:

    {	if (!parserData->generalSubstatusNamePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have name attribute");
	parserData->generalSubstatusNamePresent = false;
	parserData->generalSubstatusDescriptionPresent = false;
	parserData->kounter++;
}
    break;

  case 40:

    {std::cout << "parserData->kounter = " << parserData->kounter << std::endl;
std::cout << "parserData->numberOf = " << parserData->numberOf << std::endl;
	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
}
    break;

  case 44:

    {	if (parserData->generalSubstatusDescriptionPresent)
		osrlerror(NULL, NULL, parserData, "description attribute multiply specified specified");
	parserData->generalSubstatusDescriptionPresent = true;
	osresult->setGeneralSubstatusDescription(parserData->kounter-1,parserData->tempStr);
}
    break;

  case 45:

    {	std::cout << "read \'name=\'" << std::endl;
	if (parserData->generalSubstatusNamePresent)
		osrlerror(NULL, NULL, parserData, "name attribute multiply specified specified");
	parserData->generalSubstatusNamePresent = true;
	std::cout << "setGeneralSubstatusName" << std::endl; 
	osresult->setGeneralSubstatusName(parserData->kounter-1,(yyvsp[(2) - (3)].sval));
	std::cout << "Done setGeneralSubstatusName" << std::endl; 
	
}
    break;

  case 46:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval);
}
    break;

  case 47:

    {	parserData->tempStr = "";
}
    break;

  case 50:

    {osresult->setGeneralMessage( (yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;}
    break;

  case 53:

    {osresult->setServiceURI( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval)); parserData->errorText = NULL;}
    break;

  case 56:

    {osresult->setServiceName((yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));   parserData->errorText = NULL;}
    break;

  case 59:

    {osresult->setInstanceName( (yyvsp[(3) - (4)].sval)) ;  free((yyvsp[(3) - (4)].sval));   parserData->errorText = NULL;}
    break;

  case 62:

    {osresult->setJobID( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;}
    break;

  case 65:

    {std::cout << "!!!store solver invoked" << std::endl;}
    break;

  case 68:

    {std::cout << "!!!store time stamp" << std::endl;}
    break;

  case 72:

    {std::cout << "!!!store numberOfOtherGeneralResults" << std::endl;}
    break;

  case 105:

    {}
    break;

  case 113:

    {}
    break;

  case 114:

    {}
    break;

  case 123:

    {}
    break;

  case 124:

    {}
    break;

  case 133:

    {}
    break;

  case 134:

    {}
    break;

  case 141:

    {}
    break;

  case 146:

    {std::cout << "!!!store numberOfOtherSystemResults" << std::endl;}
    break;

  case 178:

    {}
    break;

  case 181:

    {}
    break;

  case 184:

    {}
    break;

  case 187:

    {}
    break;

  case 190:

    {}
    break;

  case 194:

    {std::cout << "!!!store numberOfOtherserviceResults" << std::endl;}
    break;

  case 231:

    {}
    break;

  case 234:

    {}
    break;

  case 237:

    {}
    break;

  case 240:

    {}
    break;

  case 243:

    {}
    break;

  case 247:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
}
    break;

  case 259:

    {parserData->timeType = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 261:

    {parserData->timeCategory = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 263:

    {parserData->timeUnit = (yyvsp[(2) - (3)].sval);   free((yyvsp[(2) - (3)].sval));}
    break;

  case 265:

    {parserData->timeDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 271:

    {if (parserData->ivar == parserData->numberOfTimes)
           osrlerror(NULL, NULL, parserData, "Too many time measurements");
       osresult->addTimingInformation(parserData->timeType, parserData->timeCategory,
                                      parserData->timeUnit, parserData->timeDescription, parserData->timeValue);       
       parserData->ivar++;
       parserData->timeType = "elapsedTime";
       parserData->timeCategory = "total";
       parserData->timeUnit = "second";
       parserData->timeDescription = "";      
      }
    break;

  case 273:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); }
    break;

  case 274:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); }
    break;

  case 280:

    {}
    break;

  case 281:

    {}
    break;

  case 288:

    {}
    break;

  case 297:

    {}
    break;

  case 298:

    {}
    break;

  case 307:

    {}
    break;

  case 308:

    {}
    break;

  case 313:

    {std::cout << "!!!store numberOfOtherjobResults" << std::endl;}
    break;

  case 342:

    {parserData->numberOfSolutions   = (yyvsp[(3) - (3)].ival); osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 343:

    {parserData->numberOfVariables   = (yyvsp[(3) - (3)].ival); osresult->setVariableNumber((yyvsp[(3) - (3)].ival)); }
    break;

  case 344:

    {parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 345:

    {parserData->numberOfObjectives  = (yyvsp[(3) - (3)].ival); osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 351:

    {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   }
    break;

  case 352:

    {   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
}
    break;

  case 357:

    {
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
/*  	osresult->optimization->solution[parserData->solutionIdx]->targetObjectiveIdx = $3;*/
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 }
    break;

  case 358:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); }
    break;

  case 363:

    {parserData->statusType = (yyvsp[(2) - (3)].sval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].sval));}
    break;

  case 364:

    {parserData->statusType = ""; parserData->statusTypePresent = true;}
    break;

  case 365:

    {parserData->statusDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 366:

    {parserData->statusDescription = "";}
    break;

  case 367:

    {}
    break;

  case 368:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element"); 
		parserData->statusTypePresent = false; 
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	}
    break;

  case 369:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element");
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	}
    break;

  case 380:

    { std::cout << "parsed <solutionSubstatus type=" << std::endl;
}
    break;

  case 386:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = $3; */
		osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
	}
    break;

  case 387:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = "";*/
		osresult->setSolutionMessage(parserData->solutionIdx, "");
	}
    break;

  case 392:

    {  
	osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
	}
    break;

  case 398:

    {
  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  }
    break;

  case 399:

    {
  	if(parserData->numberOfVar != 0){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  }
    break;

  case 400:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	}
    break;

  case 404:

    { parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = (yyvsp[(3) - (4)].ival);}
    break;

  case 405:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->primalVals.push_back( parserData->primalValPair);  
   }
    break;

  case 406:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); 
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->primalVals.push_back( parserData->primalValPair); 
  }
    break;

  case 408:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
     }
 */  }
    break;

  case 410:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	}
    break;

  case 413:

    {/*parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  */
}
    break;

  case 416:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/}
    break;

  case 418:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
      }
 */  }
    break;

  case 420:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	}
    break;

  case 424:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/}
    break;

  case 427:

    {/*	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	*/}
    break;

  case 428:

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
	}
    break;

  case 429:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	}
    break;

  case 430:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	}
    break;

  case 437:

    {	
	parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);

//std::cout << "This \<other\> element has " << parserData->otherVarStruct->numberOfVar << " \<var\>" << std::endl;

	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = (yyvsp[(3) - (4)].ival);
}
    break;

  case 438:

    {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
}
    break;

  case 439:

    {parserData->tmpOtherValue=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));}
    break;

  case 440:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
}
    break;

  case 441:

    {
parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
}
    break;

  case 442:

    {
parserData->tmpOtherDescription=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
}
    break;

  case 448:

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
}
    break;

  case 449:

    {//	if(parserData->otherVarStruct->numberOfVar <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	}
    break;

  case 450:

    {}
    break;

  case 457:

    {  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      }
    break;

  case 463:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
}
    break;

  case 465:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 469:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(3) - (4)].ival);   }
    break;

  case 470:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].ival);                  
	parserData->objVals.push_back( parserData->objValPair);
}
    break;

  case 471:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->objVals.push_back( parserData->objValPair);
  }
    break;

  case 475:

    {  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	}
    break;

  case 482:

    {
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
}
    break;

  case 483:

    {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
}
    break;

  case 484:

    {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));}
    break;

  case 485:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherObjStruct->name = "";
}
    break;

  case 486:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
}
    break;

  case 487:

    {
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
}
    break;

  case 490:

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
	}
    break;

  case 493:

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
}
    break;

  case 494:

    {//	if(parserData->otherObjStruct->numberOfObj <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of objectives") ;
	}
    break;

  case 495:

    {}
    break;

  case 502:

    {  
/*        osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      }
    break;

  case 508:

    {/*
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}*/
 }
    break;

  case 510:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 514:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(3) - (4)].ival);}
    break;

  case 515:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 		
	}
    break;

  case 516:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 	
	}
    break;

  case 528:

    {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
}
    break;

  case 529:

    {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));}
    break;

  case 530:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherConStruct->name = "";
}
    break;

  case 531:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
}
    break;

  case 532:

    {
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
}
    break;

  case 538:

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
}
    break;

  case 539:

    {//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	}
    break;

  case 540:

    {}
    break;

  case 545:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
}
    break;

  case 546:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
}
    break;

  case 547:

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
}
    break;

  case 551:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
}
    break;

  case 552:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
}
    break;

  case 554:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
}
    break;

  case 560:

    {	
int temp;
temp = (yyvsp[(3) - (4)].ival);
if (temp < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems = temp;
	if (osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item != NULL)
		osrlerror(NULL, NULL, parserData, "item array was previously allocated");
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item = new std::string[temp];
	parserData->kounter = 0; //this will count the number of items in an otherSolutionResult object
}
    break;

  case 561:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
}
    break;

  case 562:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 563:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));}
    break;

  case 565:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));}
    break;

  case 568:

    {parserData->kounter++;}
    break;

  case 569:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
}
    break;

  case 570:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
}
    break;

  case 573:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
}
    break;

  case 575:

    {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
}
    break;

  case 583:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
}
    break;

  case 586:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/}
    break;

  case 592:

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
}
    break;

  case 593:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
*/
}
    break;

  case 594:

    {
/*	parserData->tmpOtherName=$2; parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
}
    break;

  case 595:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
}
    break;

  case 597:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
}
    break;

  case 601:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/}
    break;

  case 602:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/}
    break;

  case 605:

    {/*parserData->itemContent = $2; free($2);*/}
    break;

  case 607:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 608:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 610:

    { parserData->outStr << (yyvsp[(1) - (1)].sval);    free((yyvsp[(1) - (1)].sval)); }
    break;

  case 611:

    { parserData->outStr << (yyvsp[(1) - (1)].ival);  /*free($1);*/ }
    break;

  case 612:

    { parserData->outStr << (yyvsp[(1) - (1)].dval);  /*free($1);*/ }
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


