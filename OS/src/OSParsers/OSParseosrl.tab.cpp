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
#define YYLAST   931

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  326
/* YYNRULES -- Number of rules.  */
#define YYNRULES  619
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1045

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
     325,   326,   329,   331,   333,   337,   341,   343,   345,   347,
     353,   354,   357,   359,   361,   365,   369,   371,   373,   375,
     381,   382,   385,   387,   389,   393,   397,   399,   401,   403,
     409,   410,   413,   417,   419,   421,   423,   427,   432,   434,
     436,   439,   441,   445,   447,   450,   454,   455,   458,   460,
     462,   464,   468,   472,   474,   478,   480,   483,   485,   486,
     489,   494,   495,   498,   500,   502,   504,   506,   508,   510,
     515,   519,   522,   527,   531,   534,   539,   543,   546,   551,
     555,   558,   563,   567,   570,   574,   579,   581,   583,   586,
     588,   592,   594,   597,   601,   602,   605,   607,   609,   611,
     615,   619,   621,   625,   627,   630,   632,   633,   636,   641,
     642,   645,   647,   649,   651,   653,   655,   657,   659,   661,
     663,   665,   667,   672,   676,   679,   684,   688,   691,   696,
     700,   703,   708,   712,   715,   720,   724,   727,   731,   736,
     738,   742,   743,   746,   750,   751,   754,   756,   758,   760,
     762,   766,   768,   772,   774,   778,   780,   784,   786,   788,
     790,   793,   795,   799,   800,   802,   804,   810,   811,   814,
     816,   818,   822,   826,   828,   830,   832,   838,   839,   842,
     846,   848,   850,   852,   858,   859,   862,   864,   866,   870,
     874,   876,   878,   880,   886,   887,   890,   892,   894,   898,
     902,   904,   906,   908,   912,   917,   919,   921,   924,   926,
     930,   932,   935,   939,   940,   943,   945,   947,   949,   953,
     957,   959,   963,   965,   968,   970,   971,   975,   976,   979,
     982,   985,   988,   991,   995,   999,  1003,  1007,  1011,  1013,
    1016,  1017,  1020,  1024,  1026,  1027,  1030,  1032,  1034,  1039,
    1043,  1052,  1056,  1058,  1061,  1065,  1067,  1071,  1073,  1078,
    1080,  1082,  1085,  1087,  1091,  1093,  1096,  1100,  1101,  1104,
    1106,  1108,  1112,  1116,  1118,  1121,  1123,  1124,  1129,  1133,
    1136,  1137,  1141,  1142,  1147,  1149,  1151,  1153,  1160,  1161,
    1167,  1171,  1176,  1177,  1180,  1186,  1191,  1193,  1195,  1196,
    1202,  1206,  1211,  1212,  1215,  1221,  1226,  1230,  1235,  1236,
    1242,  1246,  1251,  1252,  1255,  1261,  1266,  1267,  1270,  1271,
    1276,  1278,  1280,  1281,  1284,  1286,  1288,  1290,  1292,  1297,
    1299,  1303,  1305,  1309,  1313,  1315,  1317,  1321,  1322,  1325,
    1329,  1331,  1336,  1340,  1343,  1345,  1346,  1350,  1351,  1356,
    1358,  1360,  1362,  1367,  1368,  1374,  1378,  1383,  1384,  1387,
    1393,  1398,  1400,  1402,  1403,  1406,  1410,  1412,  1413,  1416,
    1418,  1420,  1422,  1424,  1429,  1431,  1435,  1437,  1441,  1445,
    1447,  1449,  1453,  1454,  1457,  1461,  1463,  1468,  1472,  1475,
    1477,  1478,  1482,  1483,  1488,  1490,  1492,  1494,  1499,  1500,
    1506,  1510,  1515,  1516,  1519,  1525,  1530,  1532,  1534,  1535,
    1538,  1542,  1544,  1545,  1548,  1550,  1552,  1554,  1556,  1561,
    1563,  1567,  1569,  1573,  1577,  1579,  1581,  1585,  1586,  1589,
    1593,  1595,  1600,  1604,  1607,  1609,  1610,  1616,  1620,  1621,
    1627,  1628,  1631,  1637,  1641,  1642,  1643,  1647,  1649,  1651,
    1653,  1655,  1660,  1662,  1666,  1670,  1672,  1676,  1678,  1679,
    1682,  1684,  1686,  1688,  1690,  1691,  1696,  1698,  1699,  1703,
    1708,  1710,  1714,  1715,  1718,  1724,  1728,  1729,  1730,  1734,
    1736,  1738,  1740,  1742,  1747,  1749,  1753,  1757,  1759,  1763,
    1765,  1766,  1769,  1771,  1773,  1775,  1777,  1778,  1783,  1785,
    1787,  1790,  1792,  1794,  1796,  1798,  1800,  1802,  1804,  1805
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   216,   255,   276,   334,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   194,    -1,   195,    -1,   196,    -1,   197,
      -1,   198,    -1,   199,    -1,   200,    -1,   201,    -1,   176,
     177,   183,    -1,    88,    -1,   178,    -1,   179,    -1,   178,
     179,    -1,   180,    -1,   181,    -1,   182,    -1,    36,     3,
     491,    -1,    37,    -1,    32,     3,   491,    -1,    33,    -1,
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
     108,    -1,    19,   491,     6,   491,    -1,   205,    -1,   206,
      -1,    10,   109,    -1,    11,    -1,    10,   207,   109,    -1,
     208,    -1,   207,   208,    -1,   209,   210,   215,    -1,   106,
      -1,    -1,   210,   211,    -1,   212,    -1,   213,    -1,   214,
      -1,    34,     3,   491,    -1,    40,     3,   491,    -1,    41,
      -1,    32,     3,   491,    -1,    33,    -1,    10,   107,    -1,
      11,    -1,    -1,    50,    11,    -1,    50,    10,   217,    51,
      -1,    -1,   217,   218,    -1,   219,    -1,   220,    -1,   226,
      -1,   232,    -1,   238,    -1,   242,    -1,   136,    10,     4,
     137,    -1,   136,    10,   137,    -1,   136,    11,    -1,    68,
     221,    10,   225,    69,    -1,    -1,   221,   222,    -1,   223,
      -1,   224,    -1,    38,     3,   491,    -1,    32,     3,   491,
      -1,    33,    -1,     6,    -1,     7,    -1,    70,   227,    10,
     231,    71,    -1,    -1,   227,   228,    -1,   229,    -1,   230,
      -1,    38,     3,   491,    -1,    32,     3,   491,    -1,    33,
      -1,     6,    -1,     7,    -1,    66,   233,    10,   237,    67,
      -1,    -1,   233,   234,    -1,   235,    -1,   236,    -1,    38,
       3,   491,    -1,    32,     3,   491,    -1,    33,    -1,     6,
      -1,     7,    -1,    64,   239,    10,   241,    65,    -1,    -1,
     239,   240,    -1,    32,     3,   491,    -1,    33,    -1,     6,
      -1,     7,    -1,   108,   243,   244,    -1,    19,   491,     6,
     491,    -1,   245,    -1,   246,    -1,    10,   109,    -1,    11,
      -1,    10,   247,   109,    -1,   248,    -1,   247,   248,    -1,
     106,   249,   254,    -1,    -1,   249,   250,    -1,   251,    -1,
     252,    -1,   253,    -1,    34,     3,   491,    -1,    40,     3,
     491,    -1,    41,    -1,    32,     3,   491,    -1,    33,    -1,
      10,   107,    -1,    11,    -1,    -1,    52,    11,    -1,    52,
      10,   256,    53,    -1,    -1,   256,   257,    -1,   258,    -1,
     259,    -1,   260,    -1,   261,    -1,   262,    -1,   263,    -1,
      82,    10,     4,    83,    -1,    82,    10,    83,    -1,    82,
      11,    -1,    80,    10,     6,    81,    -1,    80,    10,    81,
      -1,    80,    11,    -1,   146,    10,     6,   147,    -1,   146,
      10,   147,    -1,   146,    11,    -1,   140,    10,     4,   141,
      -1,   140,    10,   141,    -1,   140,    11,    -1,   122,    10,
     490,   123,    -1,   122,    10,   123,    -1,   122,    11,    -1,
     108,   264,   265,    -1,    19,   491,     6,   491,    -1,   266,
      -1,   267,    -1,    10,   109,    -1,    11,    -1,    10,   268,
     109,    -1,   269,    -1,   268,   269,    -1,   106,   270,   275,
      -1,    -1,   270,   271,    -1,   272,    -1,   273,    -1,   274,
      -1,    34,     3,   491,    -1,    40,     3,   491,    -1,    41,
      -1,    32,     3,   491,    -1,    33,    -1,    10,   107,    -1,
      11,    -1,    -1,    54,    11,    -1,    54,    10,   277,    55,
      -1,    -1,   277,   278,    -1,   279,    -1,   280,    -1,   281,
      -1,   282,    -1,   283,    -1,   284,    -1,   299,    -1,   305,
      -1,   309,    -1,   315,    -1,   321,    -1,   130,    10,     4,
     131,    -1,   130,    10,   131,    -1,   130,    11,    -1,   132,
      10,     4,   133,    -1,   132,    10,   133,    -1,   132,    11,
      -1,   116,    10,     4,   117,    -1,   116,    10,   117,    -1,
     116,    11,    -1,    62,    10,     4,    63,    -1,    62,    10,
      63,    -1,    62,    11,    -1,    86,    10,     4,    87,    -1,
      86,    10,    87,    -1,    86,    11,    -1,   144,   285,   286,
      -1,    25,     8,     6,     8,    -1,    11,    -1,    10,   287,
     145,    -1,    -1,   287,   288,    -1,   138,   289,   295,    -1,
      -1,   289,   290,    -1,   291,    -1,   292,    -1,   293,    -1,
     294,    -1,    36,     3,     8,    -1,    37,    -1,    30,     3,
       8,    -1,    31,    -1,    38,     3,     8,    -1,    39,    -1,
      32,     3,     8,    -1,    33,    -1,   296,    -1,   297,    -1,
      10,   139,    -1,    11,    -1,    10,   298,   139,    -1,    -1,
       7,    -1,     6,    -1,   150,   300,    10,   304,   151,    -1,
      -1,   300,   301,    -1,   302,    -1,   303,    -1,    38,     3,
     491,    -1,    32,     3,   491,    -1,    33,    -1,     6,    -1,
       7,    -1,   148,   306,    10,   308,   149,    -1,    -1,   306,
     307,    -1,    32,     3,   491,    -1,    33,    -1,     6,    -1,
       7,    -1,   152,   310,    10,   314,   153,    -1,    -1,   310,
     311,    -1,   312,    -1,   313,    -1,    38,     3,   491,    -1,
      32,     3,   491,    -1,    33,    -1,     6,    -1,     7,    -1,
     154,   316,    10,   320,   155,    -1,    -1,   316,   317,    -1,
     318,    -1,   319,    -1,    38,     3,   491,    -1,    32,     3,
     491,    -1,    33,    -1,     6,    -1,     7,    -1,   108,   322,
     323,    -1,    19,   491,     6,   491,    -1,   324,    -1,   325,
      -1,    10,   109,    -1,    11,    -1,    10,   326,   109,    -1,
     327,    -1,   326,   327,    -1,   106,   328,   333,    -1,    -1,
     328,   329,    -1,   330,    -1,   331,    -1,   332,    -1,    34,
       3,   491,    -1,    40,     3,   491,    -1,    41,    -1,    32,
       3,   491,    -1,    33,    -1,    10,   107,    -1,    11,    -1,
      -1,    56,   335,   341,    -1,    -1,   335,   336,    -1,   337,
     491,    -1,   338,   491,    -1,   339,   491,    -1,   340,   491,
      -1,    22,   491,     6,    -1,    27,   491,     6,    -1,    13,
     491,     6,    -1,    16,   491,     6,    -1,    10,   342,    57,
      -1,    11,    -1,   343,   473,    -1,    -1,   343,   344,    -1,
     345,   346,   350,    -1,   124,    -1,    -1,   346,   347,    -1,
     348,    -1,   349,    -1,    28,   491,     6,   491,    -1,    42,
       3,   491,    -1,    10,   351,   364,   365,   403,   429,   455,
     472,    -1,   130,   352,   354,    -1,   353,    -1,   352,   353,
      -1,    36,     3,   491,    -1,    37,    -1,    32,     3,   491,
      -1,    33,    -1,    24,     8,     6,     8,    -1,   355,    -1,
     356,    -1,    10,   131,    -1,    11,    -1,    10,   357,   131,
      -1,   358,    -1,   357,   358,    -1,   134,   359,   363,    -1,
      -1,   359,   360,    -1,   361,    -1,   362,    -1,    36,     3,
       8,    -1,    32,     3,     8,    -1,    33,    -1,    10,   135,
      -1,    11,    -1,    -1,    96,    10,     4,    97,    -1,    96,
      10,    97,    -1,    96,    11,    -1,    -1,   162,   366,   367,
      -1,    -1,    21,   491,     6,   491,    -1,   368,    -1,   369,
      -1,    11,    -1,    10,   370,   376,   381,   386,   163,    -1,
      -1,   156,   371,    10,   372,   157,    -1,   156,   371,    11,
      -1,    26,   491,     6,   491,    -1,    -1,   372,   373,    -1,
     160,   374,    10,   375,   161,    -1,    29,   491,     6,   491,
      -1,     6,    -1,     7,    -1,    -1,   158,   377,    10,   378,
     159,    -1,   158,   377,    11,    -1,    26,   491,     6,   491,
      -1,    -1,   378,   379,    -1,   160,   380,    10,     4,   161,
      -1,   160,   380,    10,   161,    -1,   160,   380,    11,    -1,
      29,   491,     6,   491,    -1,    -1,    72,   382,    10,   383,
      73,    -1,    72,   382,    11,    -1,    26,   491,     6,   491,
      -1,    -1,   383,   384,    -1,   160,   385,    10,     4,   161,
      -1,    29,   491,     6,   491,    -1,    -1,   386,   387,    -1,
      -1,   389,   390,   388,   397,    -1,   106,    -1,   391,    -1,
      -1,   391,   392,    -1,   393,    -1,   394,    -1,   395,    -1,
     396,    -1,    26,   491,     6,   491,    -1,    41,    -1,    40,
       3,   491,    -1,    35,    -1,    34,     3,   491,    -1,    32,
       3,   491,    -1,    33,    -1,    11,    -1,    10,   398,   107,
      -1,    -1,   398,   399,    -1,   400,   401,   402,    -1,   160,
      -1,    29,   491,     6,   491,    -1,    10,   492,   161,    -1,
      10,   161,    -1,    11,    -1,    -1,   100,   404,   405,    -1,
      -1,    18,   491,     6,   491,    -1,   406,    -1,   407,    -1,
      11,    -1,    10,   408,   414,   101,    -1,    -1,   156,   409,
      10,   410,   157,    -1,   156,   409,    11,    -1,    15,   491,
       6,   491,    -1,    -1,   410,   411,    -1,    98,   412,    10,
     413,    99,    -1,    29,   491,     6,   491,    -1,     6,    -1,
       7,    -1,    -1,   414,   415,    -1,   416,   417,   423,    -1,
     106,    -1,    -1,   417,   418,    -1,   419,    -1,   420,    -1,
     421,    -1,   422,    -1,    15,   491,     6,   491,    -1,    41,
      -1,    40,     3,   491,    -1,    35,    -1,    34,     3,   491,
      -1,    32,     3,   491,    -1,    33,    -1,    11,    -1,    10,
     424,   107,    -1,    -1,   424,   425,    -1,   426,   427,   428,
      -1,    98,    -1,    29,   491,     6,   491,    -1,    10,   492,
      99,    -1,    10,    99,    -1,    11,    -1,    -1,    78,   430,
     431,    -1,    -1,    17,   491,     6,   491,    -1,   432,    -1,
     433,    -1,    11,    -1,    10,   434,   440,    79,    -1,    -1,
      84,   435,    10,   436,    85,    -1,    84,   435,    11,    -1,
      12,   491,     6,   491,    -1,    -1,   436,   437,    -1,    76,
     438,    10,   439,    77,    -1,    29,   491,     6,   491,    -1,
       7,    -1,     6,    -1,    -1,   440,   441,    -1,   442,   443,
     449,    -1,   106,    -1,    -1,   443,   444,    -1,   445,    -1,
     446,    -1,   447,    -1,   448,    -1,    12,   491,     6,   491,
      -1,    41,    -1,    40,     3,   491,    -1,    35,    -1,    34,
       3,   491,    -1,    32,     3,   491,    -1,    33,    -1,    11,
      -1,    10,   450,   107,    -1,    -1,   450,   451,    -1,   452,
     453,   454,    -1,    76,    -1,    29,   491,     6,   491,    -1,
      10,   492,    77,    -1,    10,    77,    -1,    11,    -1,    -1,
     112,   456,    10,   458,   113,    -1,   112,   456,    11,    -1,
      -1,    20,     8,     6,   457,     8,    -1,    -1,   458,   459,
      -1,   110,   460,    10,   467,   111,    -1,   110,   460,    11,
      -1,    -1,    -1,   460,   461,   462,    -1,   463,    -1,   464,
      -1,   465,    -1,   466,    -1,    14,     8,     6,     8,    -1,
      35,    -1,    34,     3,   491,    -1,    30,     3,     8,    -1,
      31,    -1,    32,     3,     8,    -1,    33,    -1,    -1,   467,
     468,    -1,   469,    -1,   470,    -1,    60,    -1,    61,    -1,
      -1,    58,     5,   471,    59,    -1,   125,    -1,    -1,   114,
     474,   475,    -1,    23,   491,     6,   491,    -1,    11,    -1,
      10,   476,   115,    -1,    -1,   476,   477,    -1,   128,   478,
      10,   485,   129,    -1,   128,   478,    11,    -1,    -1,    -1,
     478,   479,   480,    -1,   481,    -1,   482,    -1,   483,    -1,
     484,    -1,    14,     8,     6,     8,    -1,    35,    -1,    34,
       3,     8,    -1,    30,     3,     8,    -1,    31,    -1,    32,
       3,     8,    -1,    33,    -1,    -1,   485,   486,    -1,   487,
      -1,   488,    -1,    60,    -1,    61,    -1,    -1,    58,     5,
     489,    59,    -1,     6,    -1,     7,    -1,   494,     8,    -1,
       4,    -1,     6,    -1,     7,    -1,   165,    -1,   166,    -1,
     167,    -1,   168,    -1,    -1,   494,   493,    -1
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
     371,   373,   375,   377,   384,   388,   394,   394,   396,   398,
     398,   400,   409,   414,   414,   417,   423,   429,   437,   439,
     440,   442,   443,   445,   445,   449,   449,   450,   452,   452,
     454,   454,   454,   455,   455,   455,   458,   459,   460,   462,
     465,   465,   467,   467,   469,   471,   472,   475,   476,   478,
     481,   481,   483,   483,   485,   487,   488,   491,   492,   494,
     497,   497,   499,   499,   501,   503,   504,   507,   508,   511,
     514,   514,   516,   517,   520,   521,   524,   526,   528,   528,
     530,   530,   532,   534,   534,   536,   538,   538,   540,   540,
     540,   542,   544,   545,   547,   548,   550,   550,   554,   554,
     555,   557,   557,   559,   559,   559,   560,   560,   560,   563,
     564,   565,   568,   569,   570,   573,   574,   575,   578,   579,
     580,   583,   584,   585,   588,   590,   592,   592,   594,   594,
     596,   598,   598,   600,   602,   602,   604,   604,   604,   606,
     608,   609,   611,   612,   614,   614,   617,   617,   618,   620,
     620,   622,   622,   622,   622,   622,   623,   623,   623,   623,
     623,   623,   626,   627,   628,   631,   632,   633,   636,   637,
     638,   641,   642,   643,   646,   647,   648,   651,   653,   659,
     659,   661,   661,   663,   665,   665,   667,   667,   667,   667,
     669,   670,   672,   673,   675,   676,   678,   679,   681,   681,
     683,   683,   685,   696,   700,   701,   704,   707,   707,   709,
     709,   711,   713,   714,   717,   718,   721,   724,   724,   726,
     727,   730,   731,   734,   737,   737,   739,   739,   741,   743,
     744,   747,   748,   750,   753,   753,   755,   755,   757,   759,
     760,   763,   764,   768,   770,   772,   772,   774,   774,   776,
     778,   778,   780,   782,   782,   784,   784,   784,   786,   788,
     789,   791,   792,   794,   794,   798,   798,   800,   800,   802,
     803,   804,   805,   809,   810,   811,   812,   815,   815,   817,
     819,   819,   821,   828,   834,   834,   836,   836,   838,   845,
     848,   851,   853,   854,   856,   857,   858,   859,   860,   863,
     869,   875,   875,   877,   879,   879,   881,   883,   883,   885,
     885,   887,   891,   892,   894,   894,   898,   899,   903,   907,
     909,   910,   912,   913,   923,   923,   925,   927,   929,   930,
     939,   950,   957,   957,   959,   961,   964,   968,   974,   975,
     984,   986,   993,   993,   995,  1000,  1001,  1003,  1007,  1007,
    1016,  1018,  1025,  1025,  1027,  1029,  1034,  1034,  1037,  1036,
    1056,  1064,  1070,  1070,  1072,  1072,  1072,  1072,  1074,  1086,
    1089,  1095,  1101,  1107,  1112,  1114,  1115,  1117,  1117,  1119,
    1134,  1139,  1141,  1141,  1141,  1144,  1145,  1147,  1148,  1158,
    1158,  1160,  1162,  1164,  1165,  1174,  1176,  1180,  1180,  1182,
    1184,  1187,  1191,  1197,  1197,  1199,  1202,  1210,  1211,  1213,
    1213,  1213,  1213,  1215,  1224,  1227,  1233,  1239,  1245,  1250,
    1253,  1254,  1276,  1276,  1278,  1293,  1298,  1300,  1300,  1300,
    1304,  1305,  1307,  1308,  1318,  1318,  1320,  1322,  1325,  1326,
    1336,  1338,  1343,  1343,  1345,  1347,  1350,  1354,  1360,  1360,
    1362,  1365,  1367,  1367,  1369,  1369,  1369,  1369,  1371,  1374,
    1377,  1383,  1389,  1395,  1400,  1402,  1403,  1406,  1406,  1408,
    1424,  1429,  1431,  1431,  1431,  1435,  1436,  1441,  1448,  1447,
    1463,  1463,  1466,  1473,  1482,  1483,  1483,  1487,  1487,  1487,
    1487,  1489,  1502,  1508,  1516,  1519,  1522,  1525,  1527,  1528,
    1531,  1536,  1543,  1543,  1546,  1545,  1551,  1561,  1561,  1563,
    1565,  1565,  1567,  1567,  1570,  1577,  1579,  1581,  1580,  1585,
    1585,  1585,  1585,  1587,  1602,  1609,  1618,  1624,  1627,  1633,
    1635,  1636,  1638,  1643,  1649,  1649,  1652,  1651,  1657,  1658,
    1660,  1663,  1664,  1665,  1669,  1670,  1671,  1672,  1674,  1675
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
     200,   201,   202,   203,   204,   204,   205,   205,   206,   207,
     207,   208,   209,   210,   210,   211,   211,   211,   212,   213,
     213,   214,   214,   215,   215,   216,   216,   216,   217,   217,
     218,   218,   218,   218,   218,   218,   219,   219,   219,   220,
     221,   221,   222,   222,   223,   224,   224,   225,   225,   226,
     227,   227,   228,   228,   229,   230,   230,   231,   231,   232,
     233,   233,   234,   234,   235,   236,   236,   237,   237,   238,
     239,   239,   240,   240,   241,   241,   242,   243,   244,   244,
     245,   245,   246,   247,   247,   248,   249,   249,   250,   250,
     250,   251,   252,   252,   253,   253,   254,   254,   255,   255,
     255,   256,   256,   257,   257,   257,   257,   257,   257,   258,
     258,   258,   259,   259,   259,   260,   260,   260,   261,   261,
     261,   262,   262,   262,   263,   264,   265,   265,   266,   266,
     267,   268,   268,   269,   270,   270,   271,   271,   271,   272,
     273,   273,   274,   274,   275,   275,   276,   276,   276,   277,
     277,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   279,   279,   279,   280,   280,   280,   281,   281,
     281,   282,   282,   282,   283,   283,   283,   284,   285,   286,
     286,   287,   287,   288,   289,   289,   290,   290,   290,   290,
     291,   291,   292,   292,   293,   293,   294,   294,   295,   295,
     296,   296,   297,   297,   298,   298,   299,   300,   300,   301,
     301,   302,   303,   303,   304,   304,   305,   306,   306,   307,
     307,   308,   308,   309,   310,   310,   311,   311,   312,   313,
     313,   314,   314,   315,   316,   316,   317,   317,   318,   319,
     319,   320,   320,   321,   322,   323,   323,   324,   324,   325,
     326,   326,   327,   328,   328,   329,   329,   329,   330,   331,
     331,   332,   332,   333,   333,   334,   334,   335,   335,   336,
     336,   336,   336,   337,   338,   339,   340,   341,   341,   342,
     343,   343,   344,   345,   346,   346,   347,   347,   348,   349,
     350,   351,   352,   352,   353,   353,   353,   353,   353,   354,
     354,   355,   355,   356,   357,   357,   358,   359,   359,   360,
     360,   361,   362,   362,   363,   363,   364,   364,   364,   364,
     365,   365,   366,   366,   367,   367,   368,   369,   370,   370,
     370,   371,   372,   372,   373,   374,   375,   375,   376,   376,
     376,   377,   378,   378,   379,   379,   379,   380,   381,   381,
     381,   382,   383,   383,   384,   385,   386,   386,   388,   387,
     389,   390,   391,   391,   392,   392,   392,   392,   393,   394,
     394,   395,   395,   396,   396,   397,   397,   398,   398,   399,
     400,   401,   402,   402,   402,   403,   403,   404,   404,   405,
     405,   406,   407,   408,   408,   408,   409,   410,   410,   411,
     412,   413,   413,   414,   414,   415,   416,   417,   417,   418,
     418,   418,   418,   419,   420,   420,   421,   421,   422,   422,
     423,   423,   424,   424,   425,   426,   427,   428,   428,   428,
     429,   429,   430,   430,   431,   431,   432,   433,   434,   434,
     434,   435,   436,   436,   437,   438,   439,   439,   440,   440,
     441,   442,   443,   443,   444,   444,   444,   444,   445,   446,
     446,   447,   447,   448,   448,   449,   449,   450,   450,   451,
     452,   453,   454,   454,   454,   455,   455,   455,   457,   456,
     458,   458,   459,   459,   460,   461,   460,   462,   462,   462,
     462,   463,   464,   464,   465,   465,   466,   466,   467,   467,
     468,   468,   469,   469,   471,   470,   472,   473,   473,   474,
     475,   475,   476,   476,   477,   477,   478,   479,   478,   480,
     480,   480,   480,   481,   482,   482,   483,   483,   484,   484,
     485,   485,   486,   486,   487,   487,   489,   488,   490,   490,
     491,   492,   492,   492,   493,   493,   493,   493,   494,   494
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
       0,     2,     1,     1,     3,     3,     1,     1,     1,     5,
       0,     2,     1,     1,     3,     3,     1,     1,     1,     5,
       0,     2,     1,     1,     3,     3,     1,     1,     1,     5,
       0,     2,     3,     1,     1,     1,     3,     4,     1,     1,
       2,     1,     3,     1,     2,     3,     0,     2,     1,     1,
       1,     3,     3,     1,     3,     1,     2,     1,     0,     2,
       4,     0,     2,     1,     1,     1,     1,     1,     1,     4,
       3,     2,     4,     3,     2,     4,     3,     2,     4,     3,
       2,     4,     3,     2,     3,     4,     1,     1,     2,     1,
       3,     1,     2,     3,     0,     2,     1,     1,     1,     3,
       3,     1,     3,     1,     2,     1,     0,     2,     4,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     2,     4,     3,     2,     4,     3,
       2,     4,     3,     2,     4,     3,     2,     3,     4,     1,
       3,     0,     2,     3,     0,     2,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       2,     1,     3,     0,     1,     1,     5,     0,     2,     1,
       1,     3,     3,     1,     1,     1,     5,     0,     2,     3,
       1,     1,     1,     5,     0,     2,     1,     1,     3,     3,
       1,     1,     1,     5,     0,     2,     1,     1,     3,     3,
       1,     1,     1,     3,     4,     1,     1,     2,     1,     3,
       1,     2,     3,     0,     2,     1,     1,     1,     3,     3,
       1,     3,     1,     2,     1,     0,     3,     0,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     1,     2,
       0,     2,     3,     1,     0,     2,     1,     1,     4,     3,
       8,     3,     1,     2,     3,     1,     3,     1,     4,     1,
       1,     2,     1,     3,     1,     2,     3,     0,     2,     1,
       1,     3,     3,     1,     2,     1,     0,     4,     3,     2,
       0,     3,     0,     4,     1,     1,     1,     6,     0,     5,
       3,     4,     0,     2,     5,     4,     1,     1,     0,     5,
       3,     4,     0,     2,     5,     4,     3,     4,     0,     5,
       3,     4,     0,     2,     5,     4,     0,     2,     0,     4,
       1,     1,     0,     2,     1,     1,     1,     1,     4,     1,
       3,     1,     3,     3,     1,     1,     3,     0,     2,     3,
       1,     4,     3,     2,     1,     0,     3,     0,     4,     1,
       1,     1,     4,     0,     5,     3,     4,     0,     2,     5,
       4,     1,     1,     0,     2,     3,     1,     0,     2,     1,
       1,     1,     1,     4,     1,     3,     1,     3,     3,     1,
       1,     3,     0,     2,     3,     1,     4,     3,     2,     1,
       0,     3,     0,     4,     1,     1,     1,     4,     0,     5,
       3,     4,     0,     2,     5,     4,     1,     1,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     1,     4,     1,
       3,     1,     3,     3,     1,     1,     3,     0,     2,     3,
       1,     4,     3,     2,     1,     0,     5,     3,     0,     5,
       0,     2,     5,     3,     0,     0,     3,     1,     1,     1,
       1,     4,     1,     3,     3,     1,     3,     1,     0,     2,
       1,     1,     1,     1,     0,     4,     1,     0,     3,     4,
       1,     3,     0,     2,     5,     3,     0,     0,     3,     1,
       1,     1,     1,     4,     1,     3,     3,     1,     3,     1,
       0,     2,     1,     1,     1,     1,     0,     4,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    95,     4,
       8,     6,     0,   168,     0,    98,    96,     0,   216,     7,
      20,     0,     0,     0,    72,     0,     0,     0,     0,     9,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,   171,   169,     0,   335,     0,    61,     0,    64,
       0,    52,     0,    58,     0,    55,     0,    67,     0,    70,
       0,     0,    30,     0,    28,     0,    21,    22,    24,    25,
      26,   618,     0,    97,   140,   130,   110,   120,     0,     0,
      99,   100,   101,   102,   103,   104,   105,     0,   219,   217,
     337,     0,     0,    60,     0,    63,     0,    51,     0,    57,
       0,    54,     0,    66,     0,    69,     0,   618,   618,     0,
      35,    19,    32,    33,    23,     0,     0,     0,    77,    71,
      74,    75,     0,     0,     0,     0,   618,     0,     0,   108,
     170,     0,     0,     0,     0,     0,     0,   172,   173,   174,
     175,   176,   177,   178,     0,     0,     2,    59,    62,    50,
      56,    53,    65,    68,     0,    29,    27,    34,    40,     0,
      37,    41,   618,   610,   614,   615,   616,   617,   619,    82,
      76,     0,    79,    83,     0,     0,   143,   141,     0,     0,
     136,     0,   131,   132,   133,     0,     0,   116,     0,   111,
     112,   113,     0,     0,   126,     0,   121,   122,   123,     0,
       0,   151,   146,   148,   149,     0,   107,     0,   184,     0,
     181,   618,     0,     0,   193,     0,   190,     0,   187,   218,
       0,     0,     0,     0,     0,     0,     0,   287,   277,   294,
     304,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   350,   348,   618,   618,   618,   618,   338,
     618,   618,   618,   618,   336,    31,    36,    38,     0,    73,
      78,    80,     0,   144,   145,     0,   618,   137,   138,     0,
     618,   618,   117,   118,     0,   618,   618,   127,   128,     0,
     618,   618,   618,   156,   150,     0,   153,   106,     0,   183,
       0,   180,     0,     0,   199,   194,   196,   197,   608,   609,
     192,     0,     0,   189,     0,   186,     0,   243,     0,   246,
     618,     0,     0,   240,     0,   234,     0,   237,     0,     0,
       0,     0,     0,     0,     0,   577,     0,     0,     0,     0,
     339,   340,   341,   342,     0,    49,     0,    47,     0,    42,
      43,    44,    39,     0,    94,     0,    92,     0,     0,    90,
      84,    85,    86,    87,    81,   139,   142,   129,   135,   134,
     109,   115,   114,   119,   125,   124,   147,     0,   152,   154,
     182,   179,   618,   204,   198,     0,   201,   191,   188,   185,
       0,   242,     0,   245,     0,     0,   318,   313,   315,   316,
       0,   239,     0,   233,     0,   236,     0,   251,   249,   247,
       0,     0,   290,   288,     0,     0,   283,     0,   278,   279,
     280,     0,     0,   300,     0,   295,   296,   297,     0,     0,
     310,     0,   305,   306,   307,   347,     0,   353,   351,   354,
     349,   345,   346,   343,   344,    48,     0,     0,    93,   618,
     618,   618,     0,   167,     0,   165,     0,     0,   163,   157,
     158,   159,   160,   155,   195,     0,   200,   202,   241,   244,
     618,   323,   317,     0,   320,   238,   232,   235,     0,     0,
     291,   292,     0,   618,   284,   285,     0,   618,   618,   301,
     302,     0,   618,   618,   311,   312,     0,   618,   618,   618,
       0,     0,    46,    45,    91,    88,    89,   166,   618,   618,
     618,     0,   215,     0,   213,     0,     0,   211,   205,   206,
     207,   208,   203,   314,     0,   319,   321,   248,   254,   250,
     252,   286,   289,   276,   282,   281,   293,   299,   298,   303,
     309,   308,     0,   582,   580,   578,     0,   618,     0,   355,
     356,   357,   352,   164,   161,   162,   214,   618,   618,   618,
       0,   334,     0,   332,     0,     0,   330,   324,   325,   326,
     327,   322,   273,   618,     0,     0,   386,     0,   618,   212,
     209,   210,   333,   618,   618,   618,     0,   271,     0,   263,
       0,   267,     0,   261,     0,   265,   255,   256,   257,   258,
     259,   253,   268,   269,   579,   581,   586,   583,     0,     0,
     367,     0,   365,     0,   362,     0,   390,   618,   359,   331,
     328,   329,   275,   274,   270,     0,     0,     0,     0,     0,
     587,     0,   618,   618,     0,   372,   363,   361,   369,   370,
       0,   389,   392,   455,   358,   272,   262,   266,   260,   264,
     600,   585,     0,     0,   366,   364,   371,   377,     0,   374,
       0,   388,   618,     0,   457,   500,     0,     0,     0,   597,
       0,   599,     0,   594,   588,   589,   590,   591,   592,   368,
       0,   373,   375,   387,     0,   398,   396,   391,   394,   395,
     618,     0,   502,   545,     0,   604,   605,   584,   601,   602,
     603,     0,     0,     0,     0,     0,   385,     0,   383,     0,
     378,   379,   380,   376,   618,     0,   408,     0,   463,   461,
     456,   459,   460,   618,     0,     0,     0,   606,     0,   596,
     598,   595,   384,     0,     0,   393,   618,     0,     0,   418,
     618,     0,   473,     0,   508,   506,   501,   504,   505,     0,
       0,   576,   360,     0,   593,   382,   381,     0,   402,   400,
     618,     0,     0,   426,   458,   618,     0,     0,   618,     0,
     518,     0,   550,   547,   607,   618,     0,     0,   412,   410,
     618,     0,     0,     0,   467,   465,   462,   476,   474,   477,
     503,   618,     0,     0,   548,     0,   401,   399,     0,   403,
     618,     0,     0,   422,   420,   430,   397,   427,   432,   618,
       0,     0,     0,   512,   510,   507,   521,   519,   522,     0,
     554,   546,   551,   618,     0,   411,   409,     0,   413,   618,
       0,   428,   431,   466,     0,   464,   468,   492,   490,   618,
       0,   489,     0,   486,     0,   484,   478,   479,   480,   481,
     482,   475,   618,     0,     0,   549,   555,     0,     0,   618,
       0,   421,   419,     0,   423,     0,   618,     0,   444,     0,
     441,     0,   439,   433,   434,   435,   436,   437,   618,     0,
       0,     0,   618,   618,   618,   511,     0,   509,   513,   537,
     535,   618,     0,   534,     0,   531,     0,   529,   523,   524,
     525,   526,   527,   520,   568,   553,     0,   618,   406,   407,
       0,     0,     0,   416,   618,     0,   447,   445,   429,     0,
     618,   618,   618,     0,     0,   495,   491,   493,     0,   618,
     488,   487,   485,   618,     0,     0,     0,   618,   618,   618,
       0,     0,     0,   565,     0,   567,     0,   562,   556,   557,
     558,   559,   560,   405,   404,   618,     0,   415,     0,     0,
       0,   618,   443,   442,   440,   618,   471,   472,     0,   618,
       0,   483,     0,     0,   540,   536,   538,     0,   618,   533,
     532,   530,     0,   572,   573,   552,   569,   570,   571,     0,
       0,     0,   618,   417,   414,   618,     0,   446,   450,   448,
       0,   438,   470,   469,     0,     0,   499,   494,   618,   517,
     516,     0,   618,     0,   528,   574,     0,   564,   566,   563,
     425,   424,   618,     0,   618,   611,   612,   613,   498,     0,
     515,   514,     0,     0,   544,   539,     0,   561,     0,     0,
     454,   449,   496,   497,   618,   543,     0,   575,   618,   453,
       0,   541,   542,   451,   452
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    31,    65,    66,
      67,    68,    69,    70,   111,   112,   113,   159,   160,   161,
     258,   339,   340,   341,   342,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    72,   119,   120,   121,   171,   172,
     173,   262,   350,   351,   352,   353,   354,    13,    41,    80,
      81,    82,   124,   189,   190,   191,   274,    83,   125,   196,
     197,   198,   279,    84,   123,   182,   183,   184,   269,    85,
     122,   177,   265,    86,   127,   202,   203,   204,   285,   286,
     367,   449,   450,   451,   452,   453,    18,    87,   137,   138,
     139,   140,   141,   142,   143,   212,   295,   296,   297,   375,
     376,   455,   508,   509,   510,   511,   512,    45,   144,   231,
     232,   233,   234,   235,   236,   237,   319,   399,   469,   520,
     562,   586,   587,   588,   589,   590,   591,   592,   593,   615,
     238,   321,   408,   409,   410,   476,   239,   320,   403,   472,
     240,   322,   415,   416,   417,   481,   241,   323,   422,   423,
     424,   486,   242,   311,   387,   388,   389,   463,   464,   514,
     557,   558,   559,   560,   561,    91,   145,   249,   250,   251,
     252,   253,   254,   324,   325,   428,   429,   491,   539,   540,
     541,   542,   566,   603,   604,   627,   628,   629,   648,   649,
     670,   700,   701,   702,   703,   606,   633,   653,   677,   678,
     679,   706,   727,   766,   789,   814,   900,   729,   751,   791,
     818,   850,   753,   771,   820,   854,   905,   772,   797,   855,
     798,   821,   822,   863,   864,   865,   866,   867,   908,   950,
     989,   990,  1013,  1031,   655,   681,   710,   711,   712,   732,
     756,   800,   826,   869,   958,   757,   778,   779,   801,   836,
     837,   838,   839,   840,   841,   870,   917,   918,   960,   997,
     683,   714,   736,   737,   738,   760,   782,   843,   878,   924,
    1001,   783,   807,   808,   844,   888,   889,   890,   891,   892,
     893,   925,   966,   967,  1003,  1025,   716,   740,   809,   785,
     812,   846,   896,   938,   939,   940,   941,   942,   930,   976,
     977,   978,  1026,   742,   430,   490,   535,   564,   597,   620,
     642,   664,   665,   666,   667,   668,   656,   688,   689,   690,
     743,   301,   115,  1019,   168,   116
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -916
static const yytype_int16 yypact[] =
{
      37,    52,    54,    44,  -916,   106,  -916,   182,    78,  -916,
    -916,  -916,   241,    84,   -36,  -916,  -916,   303,   100,  -916,
    -916,   348,   352,   354,  -916,   357,   362,   367,   373,  -916,
    -916,   318,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
     137,   -23,  -916,  -916,   375,   155,    29,  -916,    30,  -916,
      23,  -916,    14,  -916,    10,  -916,     7,  -916,     4,  -916,
     211,   227,  -916,   235,  -916,   377,   318,  -916,  -916,  -916,
    -916,  -916,   379,  -916,  -916,  -916,  -916,  -916,   224,   384,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,   -17,  -916,  -916,
    -916,   198,   133,  -916,   178,  -916,   192,  -916,   160,  -916,
     180,  -916,   168,  -916,   184,  -916,   335,  -916,  -916,   -57,
    -916,  -916,  -916,  -916,  -916,   341,    12,    49,  -916,  -916,
    -916,  -916,   217,    36,   162,   204,  -916,   386,    -2,  -916,
    -916,   388,   390,   350,   392,   394,   396,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,   -33,   313,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,   366,  -916,  -916,  -916,  -916,   -38,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,    56,  -916,  -916,   402,   376,  -916,  -916,   404,   426,
    -916,   436,  -916,  -916,  -916,   406,   494,  -916,   498,  -916,
    -916,  -916,   408,   499,  -916,   500,  -916,  -916,  -916,   410,
     169,  -916,  -916,  -916,  -916,   310,  -916,    31,  -916,    26,
    -916,  -916,   407,     9,  -916,     8,  -916,     1,  -916,  -916,
     409,   411,   458,   413,   415,   417,   479,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,   271,  -916,
    -916,  -916,   172,  -916,  -916,   441,  -916,  -916,  -916,   419,
    -916,  -916,  -916,  -916,   443,  -916,  -916,  -916,  -916,   434,
    -916,  -916,  -916,  -916,  -916,   174,  -916,  -916,   427,  -916,
     424,  -916,   503,   179,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,   387,   370,  -916,   371,  -916,    38,  -916,    40,  -916,
    -916,   421,    13,  -916,    20,  -916,    17,  -916,   505,   423,
     254,   225,   234,   236,   457,   -53,   511,   513,   514,   515,
    -916,  -916,  -916,  -916,   389,  -916,   519,  -916,   520,  -916,
    -916,  -916,  -916,   418,  -916,   523,  -916,   524,   525,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,   188,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,   185,  -916,  -916,  -916,  -916,
     466,  -916,   445,  -916,   527,   206,  -916,  -916,  -916,  -916,
     414,  -916,   399,  -916,   401,  -916,   529,  -916,  -916,  -916,
     429,   533,  -916,  -916,   431,   534,  -916,   535,  -916,  -916,
    -916,   437,   536,  -916,   537,  -916,  -916,  -916,   439,   538,
    -916,   539,  -916,  -916,  -916,  -916,   521,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,   540,   541,  -916,  -916,
    -916,  -916,   446,  -916,   543,  -916,   544,   547,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,   191,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,   216,  -916,  -916,  -916,  -916,   546,   -65,
    -916,  -916,   403,  -916,  -916,  -916,   400,  -916,  -916,  -916,
    -916,   405,  -916,  -916,  -916,  -916,   412,  -916,  -916,  -916,
     438,   142,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,   448,  -916,   553,  -916,   554,   556,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,   207,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,   555,  -916,  -916,  -916,   430,  -916,   559,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
     456,  -916,   561,  -916,   562,   563,  -916,  -916,  -916,  -916,
    -916,  -916,   223,  -916,   -58,   324,   472,   564,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,     3,  -916,   566,  -916,
     568,  -916,   569,  -916,   571,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,   567,   573,
    -916,   574,  -916,   260,  -916,   440,   381,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,   450,   570,   572,   575,   576,
     442,   579,  -916,  -916,   -24,  -916,  -916,  -916,  -916,  -916,
      27,  -916,   558,   482,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,   276,   578,  -916,  -916,  -916,  -916,   197,  -916,
     484,  -916,  -916,   444,   577,   509,    28,   580,   587,  -916,
     588,  -916,   589,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
     266,  -916,  -916,  -916,   590,   451,  -916,  -916,  -916,  -916,
    -916,   447,   581,   489,   594,  -916,  -916,  -916,  -916,  -916,
    -916,   596,   585,   586,   592,   468,  -916,   601,  -916,   602,
    -916,  -916,  -916,  -916,  -916,   582,   453,   603,   460,  -916,
    -916,  -916,  -916,  -916,   449,   593,   490,  -916,   604,  -916,
    -916,  -916,  -916,   606,   609,  -916,  -916,   452,   584,   548,
    -916,   607,  -916,   612,   542,  -916,  -916,  -916,  -916,   613,
     454,  -916,  -916,   565,  -916,  -916,  -916,   619,  -916,  -916,
    -916,   459,   605,  -916,  -916,  -916,   461,    75,  -916,   615,
    -916,   622,  -916,  -916,  -916,  -916,   186,   623,  -916,  -916,
    -916,   463,   -68,   624,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,   465,   -30,  -916,   239,  -916,  -916,   608,  -916,
    -916,   319,   626,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
     -63,   156,   627,  -916,  -916,  -916,  -916,  -916,  -916,   628,
    -916,  -916,  -916,  -916,   625,  -916,  -916,   610,  -916,  -916,
     -34,  -916,   304,  -916,   611,  -916,  -916,  -916,  -916,  -916,
     631,  -916,   635,  -916,   638,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,   -26,   175,  -916,   470,   636,   476,  -916,
     474,  -916,  -916,   616,  -916,   477,  -916,   641,  -916,   643,
    -916,   644,  -916,  -916,  -916,  -916,  -916,  -916,  -916,   639,
     -20,   646,  -916,  -916,  -916,  -916,   621,  -916,  -916,  -916,
    -916,  -916,   650,  -916,   651,  -916,   652,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,   286,  -916,  -916,  -916,
     495,   653,     0,  -916,  -916,   647,  -916,  -916,  -916,   654,
    -916,  -916,  -916,   655,   483,  -916,  -916,  -916,   633,  -916,
    -916,  -916,  -916,  -916,   656,   -28,   658,  -916,  -916,  -916,
      42,   657,   664,  -916,   665,  -916,   666,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,   510,  -916,   667,   668,
     -67,  -916,  -916,  -916,  -916,  -916,  -916,  -916,   583,  -916,
     481,  -916,   669,   487,  -916,  -916,  -916,   648,  -916,  -916,
    -916,  -916,   671,  -916,  -916,  -916,  -916,  -916,  -916,   672,
     662,   673,  -916,  -916,  -916,  -916,   518,  -916,  -916,  -916,
     659,  -916,  -916,  -916,   674,    19,  -916,  -916,  -916,  -916,
    -916,   614,  -916,   485,  -916,  -916,   676,  -916,  -916,  -916,
    -916,  -916,  -916,   488,  -916,  -916,  -916,  -916,  -916,   591,
    -916,  -916,   679,    60,  -916,  -916,   630,  -916,   680,    -1,
    -916,  -916,  -916,  -916,  -916,  -916,   617,  -916,  -916,  -916,
     526,  -916,  -916,  -916,  -916
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
     629,  -916,  -916,  -916,  -916,  -916,  -916,  -916,   545,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,   522,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,   416,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
     321,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,   237,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,    94,  -916,  -916,  -916,  -916,    50,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,  -916,
    -916,  -916,  -107,  -915,  -916,  -916
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     155,   156,   205,  1015,   946,  1016,  1017,   304,   104,   612,
     613,   102,   302,    19,   100,   298,   299,   390,    98,   199,
     163,   394,   219,  1015,   392,  1016,  1017,    96,    73,   220,
     290,   650,   157,    92,    94,   824,   130,   288,   795,   852,
     987,    74,   380,    75,   382,    76,   178,    77,   964,   805,
     876,   256,    20,   221,     6,   259,    21,   595,    22,   877,
      23,   426,     4,   131,  1015,   132,  1016,  1017,   179,   180,
     596,   427,    24,   518,   181,   222,   806,   158,   915,   965,
     519,     1,    25,   223,    26,    78,   684,   916,   685,   686,
      27,   133,     7,   988,   825,   796,   158,   224,     5,   225,
     972,   381,   973,   974,   292,   134,    28,   646,  1036,   291,
     647,   226,   289,    79,  1040,   227,     9,   228,  1018,   229,
      97,   230,    93,   135,   651,    95,   853,   383,    12,   136,
     391,   101,   300,    99,   103,   206,    17,  1035,   326,   327,
     328,   329,   614,   330,   331,   332,   333,   105,   305,   303,
     395,   393,   536,   975,    44,   169,    71,   687,   170,   356,
    1039,   947,   169,   358,   359,   260,   827,   828,   361,   362,
     537,   829,   185,   364,   365,   366,   776,   164,   165,   166,
     167,   777,   343,   344,   538,   879,   880,   881,   830,   831,
     832,   833,    10,    11,   186,   187,   834,   835,   442,   443,
     188,   501,   502,   384,   345,   346,   347,   882,   883,   884,
     885,    90,   348,   349,   192,   886,   887,   550,   551,   106,
     444,   445,   446,   503,   504,   505,   147,   174,   447,   448,
     107,   506,   507,   576,   577,   404,   193,   194,   108,   552,
     553,   554,   195,   126,   411,   146,   418,   555,   556,   175,
     176,    15,    16,   578,   579,   580,   581,   405,   406,   582,
     583,   584,   585,   407,   400,   454,   412,   413,   419,   420,
     624,   625,   414,   148,   421,   283,   695,   696,   284,   150,
     283,   334,   335,   368,   598,   373,   401,   402,   374,   149,
     657,   373,   599,   600,   456,   152,   601,   602,   697,   698,
     931,   151,   699,   336,   337,   338,   658,   659,   660,   661,
     662,   663,   461,    42,    43,   462,   932,   933,   934,   935,
     936,   937,   461,   243,   244,   515,   245,   153,   671,   246,
     856,   647,   494,   495,   496,   247,   857,   858,   859,   860,
     248,   154,    60,   787,   861,   862,   788,   162,   598,   810,
      61,    62,   811,   513,    63,    64,   599,   600,    46,    47,
     601,   602,    48,    49,    50,    51,   522,    52,    53,   211,
     524,   525,    54,    55,   255,   527,   528,    56,    57,   266,
     530,   531,   532,    58,    59,    88,    89,   109,   110,   117,
     118,   543,   544,   545,   128,   129,   200,   201,   207,   208,
     209,   210,   213,   214,   215,   216,   217,   218,   263,   264,
     267,   268,   272,   273,   277,   278,   282,   293,   294,   306,
     307,   308,   309,   312,   313,   314,   315,   316,   317,   270,
     567,   385,   386,   397,   398,   470,   471,   474,   475,   271,
     569,   570,   571,   479,   480,   484,   485,   287,   533,   534,
     630,   631,   640,   641,   675,   676,   594,   708,   709,   734,
     735,   608,   748,   749,   762,   763,   609,   610,   611,   768,
     769,   774,   775,   793,   794,   803,   804,   310,   816,   817,
     894,   895,   898,   899,   902,   903,   357,   906,   907,   956,
     957,   995,   996,   999,  1000,  1023,  1024,   275,  1029,  1030,
     634,   276,   280,   281,   318,   363,   355,   371,   370,   372,
     377,   378,   360,   396,   425,   644,   645,   431,   379,   432,
     433,   434,   436,   437,   435,   438,   439,   440,   441,   458,
     466,   465,   459,   460,   467,   468,   473,   477,   478,   482,
     483,   487,   488,   632,   489,   674,   498,   499,   492,   493,
     500,   523,   521,   497,   517,   546,   547,   548,   526,   549,
     565,   563,   568,   572,   573,   574,   575,   529,   605,   616,
     607,   617,   618,   707,   619,   621,   622,   623,   636,   652,
     637,   673,   654,   638,   639,   643,   669,   682,   691,   635,
     692,   693,   694,   719,   720,   680,   704,   725,   713,   717,
     721,   715,   718,   722,   723,   724,   733,   705,   726,   730,
     750,   728,   744,   739,   745,   741,   731,   746,   758,   747,
     752,   761,   755,   754,   764,   765,   759,   781,   784,   790,
     799,   770,   819,   842,   872,   848,   845,   813,   873,   849,
     868,   874,   897,   767,   910,   904,   911,   912,   773,   914,
     923,   780,   919,   927,   928,   929,   944,   949,   786,   945,
     951,   955,   959,   792,   968,   979,   963,   980,   981,   982,
    1007,   984,   986,   985,   802,   998,  1005,  1002,  1006,  1011,
    1014,  1008,   993,   815,  1027,  1034,  1038,  1044,  1012,  1037,
    1033,  1021,   823,   261,  1042,   114,   457,   626,   672,     0,
     516,   369,     0,     0,   257,     0,   847,     0,     0,     0,
       0,     0,   851,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   871,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   875,     0,     0,     0,     0,
       0,     0,   901,     0,     0,     0,     0,     0,     0,   909,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   913,     0,     0,     0,   920,   921,   922,     0,     0,
       0,     0,     0,     0,   926,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     943,     0,     0,     0,     0,     0,     0,   948,     0,     0,
       0,     0,     0,   952,   953,   954,     0,     0,     0,     0,
       0,     0,   961,     0,     0,     0,   962,     0,     0,     0,
     969,   970,   971,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   983,     0,
       0,     0,     0,     0,   991,     0,     0,     0,   992,     0,
       0,     0,   994,     0,     0,     0,     0,     0,     0,     0,
       0,  1004,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1009,     0,     0,  1010,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1020,     0,     0,     0,  1022,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1028,     0,  1032,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1041,     0,     0,
       0,  1043
};

static const yytype_int16 yycheck[] =
{
     107,   108,     4,     4,     4,     6,     7,     6,     4,     6,
       7,     4,     4,    49,     4,     6,     7,     4,     4,   126,
       8,     4,    55,     4,     4,     6,     7,     4,    51,    62,
       4,     4,    89,     4,     4,    98,    53,     6,   106,    73,
     107,    64,     4,    66,     4,    68,    10,    70,    76,    79,
      76,    89,    88,    86,     0,   162,    92,   115,    94,    85,
      96,   114,    10,    80,     4,    82,     6,     7,    32,    33,
     128,   124,   108,   138,    38,   108,   106,   134,    98,   107,
     145,    44,   118,   116,   120,   108,    58,   107,    60,    61,
     126,   108,    48,   160,   157,   163,   134,   130,    46,   132,
      58,    63,    60,    61,   211,   122,   142,   131,  1023,    83,
     134,   144,    81,   136,  1029,   148,    10,   150,    99,   152,
      97,   154,    93,   140,    97,    95,   160,    87,    50,   146,
     117,   121,   123,   119,   127,   137,    52,    77,   245,   246,
     247,   248,   139,   250,   251,   252,   253,   143,   147,   141,
     133,   131,    10,   111,    54,   106,    19,   129,   109,   266,
     161,   161,   106,   270,   271,   109,    10,    11,   275,   276,
      28,    15,    10,   280,   281,   282,   101,   165,   166,   167,
     168,   106,    10,    11,    42,    10,    11,    12,    32,    33,
      34,    35,    10,    11,    32,    33,    40,    41,    10,    11,
      38,    10,    11,   310,    32,    33,    34,    32,    33,    34,
      35,    56,    40,    41,    10,    40,    41,    10,    11,     8,
      32,    33,    34,    32,    33,    34,    93,    10,    40,    41,
       3,    40,    41,    10,    11,    10,    32,    33,     3,    32,
      33,    34,    38,    19,    10,    47,    10,    40,    41,    32,
      33,    10,    11,    30,    31,    32,    33,    32,    33,    36,
      37,    38,    39,    38,    10,   372,    32,    33,    32,    33,
      10,    11,    38,    95,    38,   106,    10,    11,   109,   119,
     106,    10,    11,   109,    24,   106,    32,    33,   109,    97,
      14,   106,    32,    33,   109,   127,    36,    37,    32,    33,
      14,   121,    36,    32,    33,    34,    30,    31,    32,    33,
      34,    35,   106,    10,    11,   109,    30,    31,    32,    33,
      34,    35,   106,    10,    11,   109,    13,   143,   131,    16,
      26,   134,   439,   440,   441,    22,    32,    33,    34,    35,
      27,     6,    24,   157,    40,    41,   160,     6,    24,   110,
      32,    33,   113,   460,    36,    37,    32,    33,    10,    11,
      36,    37,    10,    11,    10,    11,   473,    10,    11,    19,
     477,   478,    10,    11,     8,   482,   483,    10,    11,     3,
     487,   488,   489,    10,    11,    10,    11,    10,    11,    10,
      11,   498,   499,   500,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,     6,     7,
       6,     7,     6,     7,     6,     7,     6,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,     3,
     537,    10,    11,    10,    11,     6,     7,     6,     7,     3,
     547,   548,   549,     6,     7,     6,     7,   137,    10,    11,
      10,    11,    10,    11,    10,    11,   563,    10,    11,    10,
      11,   568,    10,    11,    10,    11,   573,   574,   575,    10,
      11,    10,    11,    10,    11,    10,    11,    19,   159,   160,
      10,    11,     6,     7,    10,    11,    67,    10,    11,     6,
       7,    10,    11,     6,     7,    10,    11,     3,    10,    11,
     607,     3,     3,     3,    25,    71,    65,    83,    81,     6,
     123,   141,    69,     8,    57,   622,   623,     6,   147,     6,
       6,     6,     3,     3,   135,   107,     3,     3,     3,    63,
     131,   117,    87,     6,   133,     6,     3,     3,     3,     3,
       3,     3,     3,   162,    23,   652,     3,     3,     8,     8,
       3,   151,   149,   107,     8,   107,     3,     3,   153,     3,
     130,     6,     3,   107,     3,     3,     3,   155,    96,     3,
       6,     3,     3,   680,     3,     8,     3,     3,     8,    21,
       8,    97,   100,     8,     8,     6,     8,    78,     8,   139,
       3,     3,     3,     8,     8,    18,     6,   704,    17,     5,
       8,   112,     6,   135,     3,     3,   713,   156,    26,     6,
      26,   158,     8,    20,     8,   125,   156,     8,     6,   726,
      72,     8,    15,   730,    59,     6,    84,    12,     6,     6,
       6,    26,     6,     6,     3,    10,     8,    29,     3,    29,
      29,     3,     6,   750,     3,    29,     3,     3,   755,    10,
      29,   758,     6,     3,     3,     3,   161,    10,   765,     6,
       6,     6,    29,   770,     6,     8,    10,     3,     3,     3,
       8,   161,     4,     6,   781,     6,     5,    29,     6,   161,
       6,     8,    99,   790,     8,     6,     6,   161,    29,    59,
      99,    77,   799,   171,    77,    66,   375,   603,   648,    -1,
     463,   285,    -1,    -1,   159,    -1,   813,    -1,    -1,    -1,
      -1,    -1,   819,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   829,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   842,    -1,    -1,    -1,    -1,
      -1,    -1,   849,    -1,    -1,    -1,    -1,    -1,    -1,   856,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   868,    -1,    -1,    -1,   872,   873,   874,    -1,    -1,
      -1,    -1,    -1,    -1,   881,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     897,    -1,    -1,    -1,    -1,    -1,    -1,   904,    -1,    -1,
      -1,    -1,    -1,   910,   911,   912,    -1,    -1,    -1,    -1,
      -1,    -1,   919,    -1,    -1,    -1,   923,    -1,    -1,    -1,
     927,   928,   929,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   945,    -1,
      -1,    -1,    -1,    -1,   951,    -1,    -1,    -1,   955,    -1,
      -1,    -1,   959,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   968,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   982,    -1,    -1,   985,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   998,    -1,    -1,    -1,  1002,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1012,    -1,  1014,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1034,    -1,    -1,
      -1,  1038
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   216,   173,    10,    11,    52,   255,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   176,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   217,    10,    11,    54,   276,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      24,    32,    33,    36,    37,   177,   178,   179,   180,   181,
     182,    19,   203,    51,    64,    66,    68,    70,   108,   136,
     218,   219,   220,   226,   232,   238,   242,   256,    10,    11,
      56,   334,     4,    93,     4,    95,     4,    97,     4,   119,
       4,   121,     4,   127,     4,   143,     8,     3,     3,    10,
      11,   183,   184,   185,   179,   491,   494,    10,    11,   204,
     205,   206,   239,   233,   221,   227,    19,   243,    10,    11,
      53,    80,    82,   108,   122,   140,   146,   257,   258,   259,
     260,   261,   262,   263,   277,   335,    47,    93,    95,    97,
     119,   121,   127,   143,     6,   491,   491,    89,   134,   186,
     187,   188,     6,     8,   165,   166,   167,   168,   493,   106,
     109,   207,   208,   209,    10,    32,    33,   240,    10,    32,
      33,    38,   234,   235,   236,    10,    32,    33,    38,   222,
     223,   224,    10,    32,    33,    38,   228,   229,   230,   491,
      10,    11,   244,   245,   246,     4,   137,    10,    11,    10,
      11,    19,   264,    10,    11,    10,    11,    10,    11,    55,
      62,    86,   108,   116,   130,   132,   144,   148,   150,   152,
     154,   278,   279,   280,   281,   282,   283,   284,   299,   305,
     309,   315,   321,    10,    11,    13,    16,    22,    27,   336,
     337,   338,   339,   340,   341,     8,    89,   187,   189,   491,
     109,   208,   210,     6,     7,   241,     3,     6,     7,   237,
       3,     3,     6,     7,   225,     3,     3,     6,     7,   231,
       3,     3,     6,   106,   109,   247,   248,   137,     6,    81,
       4,    83,   491,    10,    11,   265,   266,   267,     6,     7,
     123,   490,     4,   141,     6,   147,    10,    11,    10,    11,
      19,   322,    10,    11,    10,    11,    10,    11,    25,   285,
     306,   300,   310,   316,   342,   343,   491,   491,   491,   491,
     491,   491,   491,   491,    10,    11,    32,    33,    34,   190,
     191,   192,   193,    10,    11,    32,    33,    34,    40,    41,
     211,   212,   213,   214,   215,    65,   491,    67,   491,   491,
      69,   491,   491,    71,   491,   491,   491,   249,   109,   248,
      81,    83,     6,   106,   109,   268,   269,   123,   141,   147,
       4,    63,     4,    87,   491,    10,    11,   323,   324,   325,
       4,   117,     4,   131,     4,   133,     8,    10,    11,   286,
      10,    32,    33,   307,    10,    32,    33,    38,   301,   302,
     303,    10,    32,    33,    38,   311,   312,   313,    10,    32,
      33,    38,   317,   318,   319,    57,   114,   124,   344,   345,
     473,     6,     6,     6,     6,   135,     3,     3,   107,     3,
       3,     3,    10,    11,    32,    33,    34,    40,    41,   250,
     251,   252,   253,   254,   491,   270,   109,   269,    63,    87,
       6,   106,   109,   326,   327,   117,   131,   133,     6,   287,
       6,     7,   308,     3,     6,     7,   304,     3,     3,     6,
       7,   314,     3,     3,     6,     7,   320,     3,     3,    23,
     474,   346,     8,     8,   491,   491,   491,   107,     3,     3,
       3,    10,    11,    32,    33,    34,    40,    41,   271,   272,
     273,   274,   275,   491,   328,   109,   327,     8,   138,   145,
     288,   149,   491,   151,   491,   491,   153,   491,   491,   155,
     491,   491,   491,    10,    11,   475,    10,    28,    42,   347,
     348,   349,   350,   491,   491,   491,   107,     3,     3,     3,
      10,    11,    32,    33,    34,    40,    41,   329,   330,   331,
     332,   333,   289,     6,   476,   130,   351,   491,     3,   491,
     491,   491,   107,     3,     3,     3,    10,    11,    30,    31,
      32,    33,    36,    37,    38,    39,   290,   291,   292,   293,
     294,   295,   296,   297,   491,   115,   128,   477,    24,    32,
      33,    36,    37,   352,   353,    96,   364,     6,   491,   491,
     491,   491,     6,     7,   139,   298,     3,     3,     3,     3,
     478,     8,     3,     3,    10,    11,   353,   354,   355,   356,
      10,    11,   162,   365,   491,   139,     8,     8,     8,     8,
      10,    11,   479,     6,   491,   491,   131,   134,   357,   358,
       4,    97,    21,   366,   100,   403,   485,    14,    30,    31,
      32,    33,    34,    35,   480,   481,   482,   483,   484,     8,
     359,   131,   358,    97,   491,    10,    11,   367,   368,   369,
      18,   404,    78,   429,    58,    60,    61,   129,   486,   487,
     488,     8,     3,     3,     3,    10,    11,    32,    33,    36,
     360,   361,   362,   363,     6,   156,   370,   491,    10,    11,
     405,   406,   407,    17,   430,   112,   455,     5,     6,     8,
       8,     8,   135,     3,     3,   491,    26,   371,   158,   376,
       6,   156,   408,   491,    10,    11,   431,   432,   433,    20,
     456,   125,   472,   489,     8,     8,     8,   491,    10,    11,
      26,   377,    72,   381,   491,    15,   409,   414,     6,    84,
     434,     8,    10,    11,    59,     6,   372,   491,    10,    11,
      26,   382,   386,   491,    10,    11,   101,   106,   415,   416,
     491,    12,   435,   440,     6,   458,   491,   157,   160,   373,
       6,   378,   491,    10,    11,   106,   163,   387,   389,     6,
     410,   417,   491,    10,    11,    79,   106,   441,   442,   457,
     110,   113,   459,    29,   374,   491,   159,   160,   379,     6,
     383,   390,   391,   491,    98,   157,   411,    10,    11,    15,
      32,    33,    34,    35,    40,    41,   418,   419,   420,   421,
     422,   423,     6,   436,   443,     8,   460,   491,    10,    29,
     380,   491,    73,   160,   384,   388,    26,    32,    33,    34,
      35,    40,    41,   392,   393,   394,   395,   396,    29,   412,
     424,   491,     3,     3,     3,   491,    76,    85,   437,    10,
      11,    12,    32,    33,    34,    35,    40,    41,   444,   445,
     446,   447,   448,   449,    10,    11,   461,     6,     6,     7,
     375,   491,    10,    11,    29,   385,    10,    11,   397,   491,
       3,     3,     3,   491,    10,    98,   107,   425,   426,     6,
     491,   491,   491,    29,   438,   450,   491,     3,     3,     3,
     467,    14,    30,    31,    32,    33,    34,    35,   462,   463,
     464,   465,   466,   491,   161,     6,     4,   161,   491,    10,
     398,     6,   491,   491,   491,     6,     6,     7,   413,    29,
     427,   491,   491,    10,    76,   107,   451,   452,     6,   491,
     491,   491,    58,    60,    61,   111,   468,   469,   470,     8,
       3,     3,     3,   491,   161,     6,     4,   107,   160,   399,
     400,   491,   491,    99,   491,    10,    11,   428,     6,     6,
       7,   439,    29,   453,   491,     5,     6,     8,     8,   491,
     491,   161,    29,   401,     6,     4,     6,     7,    99,   492,
     491,    77,   491,    10,    11,   454,   471,     8,   491,    10,
      11,   402,   491,    99,     6,    77,   492,    59,     6,   161,
     492,   491,    77,   491,   161
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

    {	if (parserData->generalOtherPresent)
			osrlerror(NULL, NULL, parserData, "only one general other element allowed");
		parserData->generalOtherPresent = true;
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
	osresult->setGeneralSubstatusDescription(parserData->kounter-1,parserData->tempStr);
;}
    break;

  case 45:

    {	if (parserData->generalSubstatusNamePresent)
		osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
	parserData->generalSubstatusNamePresent = true;
	std::cout << "setGeneralSubstatusName" << std::endl; 
	osresult->setGeneralSubstatusName(parserData->kounter-1,(yyvsp[(2) - (3)].sval));
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

  case 73:

    {	osresult->setNumberOfOtherGeneralResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 74:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 75:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
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
		osresult->setGeneralOtherResultName(parserData->kounter-1,parserData->tempStr);
	;}
    break;

  case 86:

    {	if (parserData->generalOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->generalOtherResultValuePresent = true;
		osresult->setGeneralOtherResultValue(parserData->kounter-1,parserData->tempStr);
	;}
    break;

  case 87:

    {	if (parserData->generalOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->generalOtherResultDescriptionPresent = true;
		osresult->setGeneralOtherResultDescription(parserData->kounter-1,parserData->tempStr);
	;}
    break;

  case 106:

    {;}
    break;

  case 114:

    {;}
    break;

  case 115:

    {;}
    break;

  case 124:

    {;}
    break;

  case 125:

    {;}
    break;

  case 134:

    {;}
    break;

  case 135:

    {;}
    break;

  case 142:

    {;}
    break;

  case 147:

    {std::cout << "!!!store numberOfOtherSystemResults" << std::endl;;}
    break;

  case 179:

    {;}
    break;

  case 182:

    {;}
    break;

  case 185:

    {;}
    break;

  case 188:

    {;}
    break;

  case 191:

    {;}
    break;

  case 195:

    {std::cout << "!!!store numberOfOtherserviceResults" << std::endl;;}
    break;

  case 232:

    {;}
    break;

  case 235:

    {;}
    break;

  case 238:

    {;}
    break;

  case 241:

    {;}
    break;

  case 244:

    {;}
    break;

  case 248:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
;}
    break;

  case 260:

    {parserData->timeType = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 262:

    {parserData->timeCategory = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 264:

    {parserData->timeUnit = (yyvsp[(2) - (3)].sval);   free((yyvsp[(2) - (3)].sval));;}
    break;

  case 266:

    {parserData->timeDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 272:

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

  case 274:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 275:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 281:

    {;}
    break;

  case 282:

    {;}
    break;

  case 289:

    {;}
    break;

  case 298:

    {;}
    break;

  case 299:

    {;}
    break;

  case 308:

    {;}
    break;

  case 309:

    {;}
    break;

  case 314:

    {std::cout << "!!!store numberOfOtherjobResults" << std::endl;;}
    break;

  case 343:

    {parserData->numberOfSolutions   = (yyvsp[(3) - (3)].ival); osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 344:

    {parserData->numberOfVariables   = (yyvsp[(3) - (3)].ival); osresult->setVariableNumber((yyvsp[(3) - (3)].ival)); ;}
    break;

  case 345:

    {parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 346:

    {parserData->numberOfObjectives  = (yyvsp[(3) - (3)].ival); osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 352:

    {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   ;}
    break;

  case 353:

    {   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
;}
    break;

  case 358:

    {
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
/*  	osresult->optimization->solution[parserData->solutionIdx]->targetObjectiveIdx = $3;*/
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 359:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 364:

    {parserData->statusType = (yyvsp[(2) - (3)].sval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].sval));;}
    break;

  case 365:

    {parserData->statusType = ""; parserData->statusTypePresent = true;;}
    break;

  case 366:

    {parserData->statusDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 367:

    {parserData->statusDescription = "";;}
    break;

  case 368:

    {;}
    break;

  case 369:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element"); 
		parserData->statusTypePresent = false; 
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	;}
    break;

  case 370:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element");
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	;}
    break;

  case 381:

    { std::cout << "parsed <solutionSubstatus type=" << std::endl;
;}
    break;

  case 387:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = $3; */
		osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
	;}
    break;

  case 388:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = "";*/
		osresult->setSolutionMessage(parserData->solutionIdx, "");
	;}
    break;

  case 393:

    {  
	osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
	;}
    break;

  case 399:

    {
  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  ;}
    break;

  case 400:

    {
  	if(parserData->numberOfVar != 0){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  ;}
    break;

  case 401:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 405:

    { parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 406:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->primalVals.push_back( parserData->primalValPair);  
   ;}
    break;

  case 407:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); 
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->primalVals.push_back( parserData->primalValPair); 
  ;}
    break;

  case 409:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
     }
 */  ;}
    break;

  case 411:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 414:

    {/*parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  */
;}
    break;

  case 417:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 419:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
      }
 */  ;}
    break;

  case 421:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 425:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 428:

    {/*	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	*/;}
    break;

  case 429:

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

  case 430:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	;}
    break;

  case 431:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	;}
    break;

  case 438:

    {	
	parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);

//std::cout << "This \<other\> element has " << parserData->otherVarStruct->numberOfVar << " \<var\>" << std::endl;

	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 439:

    {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
;}
    break;

  case 440:

    {parserData->tmpOtherValue=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 441:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 442:

    {
parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 443:

    {
parserData->tmpOtherDescription=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 449:

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

  case 450:

    {//	if(parserData->otherVarStruct->numberOfVar <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	;}
    break;

  case 451:

    {;}
    break;

  case 458:

    {  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 464:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
;}
    break;

  case 466:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 470:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(3) - (4)].ival);   ;}
    break;

  case 471:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].ival);                  
	parserData->objVals.push_back( parserData->objValPair);
;}
    break;

  case 472:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->objVals.push_back( parserData->objValPair);
  ;}
    break;

  case 476:

    {  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	;}
    break;

  case 483:

    {
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
;}
    break;

  case 484:

    {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
;}
    break;

  case 485:

    {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 486:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherObjStruct->name = "";
;}
    break;

  case 487:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 488:

    {
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 491:

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

  case 494:

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

  case 495:

    {//	if(parserData->otherObjStruct->numberOfObj <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of objectives") ;
	;}
    break;

  case 496:

    {;}
    break;

  case 503:

    {  
/*        osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 509:

    {/*
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}*/
 ;}
    break;

  case 511:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 515:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 516:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 		
	;}
    break;

  case 517:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 	
	;}
    break;

  case 529:

    {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
;}
    break;

  case 530:

    {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 531:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherConStruct->name = "";
;}
    break;

  case 532:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 533:

    {
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 539:

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

  case 540:

    {//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	;}
    break;

  case 541:

    {;}
    break;

  case 546:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 547:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 548:

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

  case 552:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 553:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 555:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 561:

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

  case 562:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 563:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 564:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 566:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 569:

    {parserData->kounter++;;}
    break;

  case 570:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 571:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 574:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 576:

    {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
;}
    break;

  case 584:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
;}
    break;

  case 587:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/;}
    break;

  case 593:

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

  case 594:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
*/
;}
    break;

  case 595:

    {
/*	parserData->tmpOtherName=$2; parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
;}
    break;

  case 596:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
;}
    break;

  case 598:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
;}
    break;

  case 602:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/;}
    break;

  case 603:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/;}
    break;

  case 606:

    {/*parserData->itemContent = $2; free($2);*/;}
    break;

  case 608:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 609:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 611:

    { parserData->outStr << (yyvsp[(1) - (1)].sval);    free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 612:

    { parserData->outStr << (yyvsp[(1) - (1)].ival);  /*free($1);*/ ;}
    break;

  case 613:

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


