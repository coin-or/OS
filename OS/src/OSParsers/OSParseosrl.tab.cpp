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
#define YYNNTS  406
/* YYNRULES -- Number of rules.  */
#define YYNRULES  673
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
    1518,  1522,  1524,  1529,  1533,  1536,  1538,  1539,  1545,  1549,
    1550,  1556,  1557,  1560,  1566,  1570,  1571,  1572,  1576,  1578,
    1580,  1582,  1584,  1589,  1591,  1595,  1599,  1601,  1605,  1607,
    1608,  1611,  1613,  1615,  1617,  1619,  1620,  1625,  1626,  1630,
    1635,  1637,  1641,  1642,  1645,  1651,  1655,  1656,  1657,  1661,
    1663,  1665,  1667,  1669,  1674,  1676,  1680,  1684,  1686,  1690,
    1692,  1693,  1696,  1698,  1700,  1702,  1704,  1705,  1710,  1713,
    1715,  1718,  1720,  1723,  1725,  1728,  1730,  1733,  1735,  1738,
    1740,  1743,  1745,  1748,  1750,  1753,  1755,  1758,  1760,  1763,
    1765,  1768,  1770,  1772,  1774,  1777,  1779,  1781,  1783,  1785,
    1787,  1789,  1791,  1792
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
     179,    -1,   561,    -1,   555,    -1,   180,    -1,    24,     8,
       6,     8,    -1,   182,    -1,   183,    -1,    10,    89,    -1,
      11,    -1,    10,   184,    89,    -1,   185,    -1,   184,   185,
      -1,   186,   187,   190,    -1,   134,    -1,   188,    -1,    -1,
     188,   189,    -1,   558,    -1,   555,    -1,    10,   135,    -1,
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
     213,   214,   215,    -1,   108,    -1,    19,   571,     6,   571,
      -1,   216,    -1,   217,    -1,    10,   109,    -1,    11,    -1,
      10,   218,   109,    -1,   219,    -1,   218,   219,    -1,   220,
     221,   224,    -1,   106,    -1,   222,    -1,    -1,   222,   223,
      -1,   558,    -1,   567,    -1,   555,    -1,    10,   107,    -1,
      11,    -1,    -1,    50,    11,    -1,    50,    10,   226,    51,
      -1,    -1,   226,   227,    -1,   228,    -1,   231,    -1,   238,
      -1,   245,    -1,   252,    -1,   257,    -1,   229,   230,    -1,
     136,    -1,    10,     4,   137,    -1,    10,   137,    -1,    11,
      -1,   232,   233,   236,    -1,    68,    -1,   234,    -1,    -1,
     234,   235,    -1,   564,    -1,   555,    -1,    10,   237,    69,
      -1,     6,    -1,     7,    -1,   239,   240,   243,    -1,    70,
      -1,   241,    -1,    -1,   241,   242,    -1,   564,    -1,   555,
      -1,    10,   244,    71,    -1,     6,    -1,     7,    -1,   246,
     247,   250,    -1,    66,    -1,   248,    -1,    -1,   248,   249,
      -1,   564,    -1,   555,    -1,    10,   251,    67,    -1,     6,
      -1,     7,    -1,   253,   254,   255,    -1,    64,    -1,    -1,
     555,    -1,    10,   256,    65,    -1,     6,    -1,   258,   259,
     260,    -1,   108,    -1,    19,   571,     6,   571,    -1,   261,
      -1,   262,    -1,    10,   109,    -1,    11,    -1,    10,   263,
     109,    -1,   264,    -1,   263,   264,    -1,   265,   266,   269,
      -1,   106,    -1,   267,    -1,    -1,   267,   268,    -1,   558,
      -1,   567,    -1,   555,    -1,    10,   107,    -1,    11,    -1,
      -1,    52,    11,    -1,    52,    10,   271,    53,    -1,    -1,
     271,   272,    -1,   273,    -1,   276,    -1,   279,    -1,   282,
      -1,   285,    -1,   288,    -1,   274,   275,    -1,    82,    -1,
      10,     4,    83,    -1,    10,    83,    -1,    11,    -1,   277,
     278,    -1,    80,    -1,    10,     6,    81,    -1,    10,    81,
      -1,    11,    -1,   280,   281,    -1,   146,    -1,    10,     6,
     147,    -1,    10,   147,    -1,    11,    -1,   283,   284,    -1,
     140,    -1,    10,     4,   141,    -1,    10,   141,    -1,    11,
      -1,   286,   287,    -1,   122,    -1,    10,   570,   123,    -1,
      10,   123,    -1,    11,    -1,   289,   290,   291,    -1,   108,
      -1,    19,   571,     6,   571,    -1,   292,    -1,   293,    -1,
      10,   109,    -1,    11,    -1,    10,   294,   109,    -1,   295,
      -1,   294,   295,    -1,   296,   297,   300,    -1,   106,    -1,
     298,    -1,    -1,   298,   299,    -1,   558,    -1,   567,    -1,
     555,    -1,    10,   107,    -1,    11,    -1,    -1,    54,    11,
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
      -1,   564,    -1,   561,    -1,   552,    -1,   555,    -1,   331,
      -1,   332,    -1,    10,   139,    -1,    11,    -1,    10,   333,
     139,    -1,     7,    -1,     6,    -1,   335,   336,   339,    -1,
     152,    -1,   337,    -1,    -1,   337,   338,    -1,   564,    -1,
     555,    -1,    10,   340,   153,    -1,     6,    -1,     7,    -1,
     342,   343,   346,    -1,   154,    -1,   344,    -1,    -1,   344,
     345,    -1,   564,    -1,   555,    -1,    10,   347,   155,    -1,
       6,    -1,     7,    -1,   349,   350,   353,    -1,   150,    -1,
     351,    -1,    -1,   351,   352,    -1,   564,    -1,   555,    -1,
      10,   354,   151,    -1,     6,    -1,     7,    -1,   356,   357,
     358,    -1,   148,    -1,    -1,   555,    -1,    10,   359,   149,
      -1,     6,    -1,   361,   362,   363,    -1,   108,    -1,    19,
     571,     6,   571,    -1,   364,    -1,   365,    -1,    10,   109,
      -1,    11,    -1,    10,   366,   109,    -1,   367,    -1,   366,
     367,    -1,   368,   369,   372,    -1,   106,    -1,   370,    -1,
      -1,   370,   371,    -1,   558,    -1,   567,    -1,   555,    -1,
      10,   107,    -1,    11,    -1,    -1,   374,   375,   382,    -1,
      56,    -1,   376,    -1,    -1,   376,   377,    -1,   378,    -1,
     379,    -1,   380,    -1,   381,    -1,    22,   571,     6,   571,
      -1,    27,   571,     6,   571,    -1,    13,   571,     6,   571,
      -1,    16,   571,     6,   571,    -1,   383,    -1,   384,    -1,
      10,    57,    -1,    11,    -1,    10,   385,   535,    57,    -1,
     386,    -1,   385,   386,    -1,   387,   388,   393,    -1,   124,
      -1,   389,    -1,    -1,   389,   390,    -1,   391,    -1,   392,
      -1,    28,   571,     6,   571,    -1,    42,     3,   571,    -1,
      10,   394,   410,   411,   460,   489,   518,   125,    -1,   395,
     396,   400,    -1,   130,    -1,   397,    -1,   398,    -1,   397,
     398,    -1,   561,    -1,   555,    -1,   399,    -1,    24,     8,
       6,     8,    -1,   401,    -1,   402,    -1,    10,   131,    -1,
      11,    -1,    10,   403,   131,    -1,   404,    -1,   403,   404,
      -1,   405,   406,   409,    -1,   134,    -1,   407,    -1,    -1,
     407,   408,    -1,   561,    -1,   555,    -1,    10,   135,    -1,
      11,    -1,    -1,    96,    10,     4,    97,    -1,    96,    10,
      97,    -1,    96,    11,    -1,    -1,   412,   413,   414,    -1,
     162,    -1,    -1,    21,   571,     6,   571,    -1,    11,    -1,
     415,    -1,    10,   416,   427,   437,   447,   163,    -1,    -1,
     417,   418,   419,    -1,   156,    -1,    26,   571,     6,   571,
      -1,   420,    -1,   421,    -1,    10,   157,    -1,    11,    -1,
      10,   422,   157,    -1,   423,    -1,   422,   423,    -1,   424,
     425,    10,   426,   161,    -1,   160,    -1,    29,   571,     6,
     571,    -1,     6,    -1,     7,    -1,    -1,   428,   429,   430,
      -1,   158,    -1,    26,   571,     6,   571,    -1,   431,    -1,
     432,    -1,    10,   159,    -1,    11,    -1,    10,   433,   159,
      -1,   434,    -1,   433,   434,    -1,   435,   436,    10,     4,
     161,    -1,   160,    -1,    29,   571,     6,   571,    -1,    -1,
     438,   439,   440,    -1,    72,    -1,    26,   571,     6,   571,
      -1,   441,    -1,   442,    -1,    10,    73,    -1,    11,    -1,
      10,   443,    73,    -1,   444,    -1,   443,   444,    -1,   445,
     446,    10,     4,   161,    -1,   160,    -1,    29,   571,     6,
     571,    -1,    -1,   447,   448,    -1,   449,   450,   454,    -1,
     106,    -1,   451,    -1,    -1,   451,   452,    -1,   453,    -1,
     567,    -1,   558,    -1,   555,    -1,    26,   571,     6,   571,
      -1,    11,    -1,    10,   455,   107,    -1,    -1,   455,   456,
      -1,   457,   458,   459,    -1,   160,    -1,    29,   571,     6,
     571,    -1,    10,   572,   161,    -1,    10,   161,    -1,    11,
      -1,    -1,   461,   462,   463,    -1,   100,    -1,    -1,    18,
     571,     6,   571,    -1,    11,    -1,   464,    -1,    10,   465,
     476,   101,    -1,    -1,   466,   467,   468,    -1,   156,    -1,
      15,   571,     6,   571,    -1,   469,    -1,   470,    -1,    10,
     157,    -1,    11,    -1,    10,   471,   157,    -1,   472,    -1,
     471,   472,    -1,   473,   474,    10,   475,    99,    -1,    98,
      -1,    -1,    29,   571,     6,   571,    -1,     6,    -1,     7,
      -1,    -1,   476,   477,    -1,   478,   479,   483,    -1,   106,
      -1,   480,    -1,    -1,   480,   481,    -1,   482,    -1,   567,
      -1,   558,    -1,   555,    -1,    15,   571,     6,   571,    -1,
      11,    -1,    10,   484,   107,    -1,    -1,   484,   485,    -1,
     486,   487,   488,    -1,    98,    -1,    29,   571,     6,   571,
      -1,    10,   572,    99,    -1,    10,    99,    -1,    11,    -1,
      -1,   490,   491,   492,    -1,    78,    -1,    -1,    17,   571,
       6,   571,    -1,    11,    -1,   493,    -1,    10,   494,   505,
      79,    -1,    -1,   495,   496,   497,    -1,    84,    -1,    12,
     571,     6,   571,    -1,   498,    -1,   499,    -1,    10,   157,
      -1,    11,    -1,    10,   500,    85,    -1,   501,    -1,   500,
     501,    -1,   502,   503,    10,   504,    77,    -1,    76,    -1,
      29,   571,     6,   571,    -1,     6,    -1,     7,    -1,    -1,
     505,   506,    -1,   507,   508,   512,    -1,   106,    -1,   509,
      -1,    -1,   509,   510,    -1,   511,    -1,   567,    -1,   558,
      -1,   555,    -1,    12,   571,     6,   571,    -1,    11,    -1,
      10,   513,   107,    -1,    -1,   513,   514,    -1,   515,   516,
     517,    -1,    76,    -1,    29,   571,     6,   571,    -1,    10,
     572,    77,    -1,    10,    77,    -1,    11,    -1,    -1,   112,
     519,    10,   521,   113,    -1,   112,   519,    11,    -1,    -1,
      20,     8,     6,   520,     8,    -1,    -1,   521,   522,    -1,
     110,   523,    10,   530,   111,    -1,   110,   523,    11,    -1,
      -1,    -1,   523,   524,   525,    -1,   526,    -1,   527,    -1,
     528,    -1,   529,    -1,    14,     8,     6,     8,    -1,    35,
      -1,    34,     3,   571,    -1,    30,     3,     8,    -1,    31,
      -1,    32,     3,     8,    -1,    33,    -1,    -1,   530,   531,
      -1,   532,    -1,   533,    -1,    60,    -1,    61,    -1,    -1,
      58,     5,   534,    59,    -1,    -1,   114,   536,   537,    -1,
      23,   571,     6,   571,    -1,    11,    -1,    10,   538,   115,
      -1,    -1,   538,   539,    -1,   128,   540,    10,   547,   129,
      -1,   128,   540,    11,    -1,    -1,    -1,   540,   541,   542,
      -1,   543,    -1,   544,    -1,   545,    -1,   546,    -1,    14,
       8,     6,     8,    -1,    35,    -1,    34,     3,     8,    -1,
      30,     3,     8,    -1,    31,    -1,    32,     3,     8,    -1,
      33,    -1,    -1,   547,   548,    -1,   549,    -1,   550,    -1,
      60,    -1,    61,    -1,    -1,    58,     5,   551,    59,    -1,
     553,   554,    -1,    30,    -1,     3,   571,    -1,   571,    -1,
     556,   557,    -1,    32,    -1,     3,   571,    -1,   571,    -1,
     559,   560,    -1,    34,    -1,     3,   571,    -1,   571,    -1,
     562,   563,    -1,    36,    -1,     3,   571,    -1,   571,    -1,
     565,   566,    -1,    38,    -1,     3,   571,    -1,   571,    -1,
     568,   569,    -1,    40,    -1,     3,   571,    -1,   571,    -1,
       6,    -1,     7,    -1,   574,     8,    -1,     4,    -1,     6,
      -1,     7,    -1,   165,    -1,   166,    -1,   167,    -1,   168,
      -1,    -1,   574,   573,    -1
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
     993,   993,   996,  1008,  1014,  1024,  1027,  1027,  1029,  1029,
    1031,  1042,  1043,  1046,  1048,  1056,  1058,  1058,  1061,  1073,
    1078,  1081,  1082,  1085,  1087,  1095,  1097,  1097,  1100,  1112,
    1117,  1120,  1121,  1124,  1126,  1136,  1138,  1138,  1141,  1157,
    1162,  1165,  1166,  1169,  1171,  1179,  1180,  1185,  1188,  1192,
    1194,  1200,  1209,  1213,  1218,  1218,  1220,  1222,  1222,  1224,
    1228,  1236,  1241,  1241,  1244,  1249,  1253,  1259,  1259,  1262,
    1262,  1264,  1271,  1276,  1276,  1279,  1280,  1281,  1282,  1285,
    1295,  1303,  1311,  1320,  1324,  1329,  1329,  1331,  1333,  1333,
    1335,  1337,  1345,  1347,  1347,  1349,  1349,  1351,  1359,  1369,
    1375,  1377,  1384,  1389,  1389,  1392,  1406,  1409,  1411,  1422,
    1426,  1432,  1432,  1434,  1436,  1436,  1438,  1441,  1448,  1453,
    1453,  1456,  1465,  1471,  1471,  1474,  1475,  1478,  1479,  1482,
    1482,  1484,  1487,  1488,  1496,  1496,  1498,  1500,  1500,  1502,
    1504,  1513,  1517,  1523,  1523,  1525,  1527,  1527,  1529,  1535,
    1541,  1544,  1545,  1548,  1548,  1550,  1552,  1560,  1564,  1570,
    1570,  1572,  1574,  1574,  1576,  1582,  1588,  1591,  1591,  1593,
    1595,  1604,  1608,  1614,  1614,  1616,  1618,  1618,  1620,  1633,
    1639,  1642,  1642,  1644,  1650,  1658,  1665,  1665,  1668,  1669,
    1674,  1679,  1685,  1695,  1696,  1698,  1698,  1700,  1705,  1707,
    1713,  1717,  1718,  1721,  1721,  1723,  1727,  1728,  1736,  1736,
    1738,  1740,  1740,  1742,  1744,  1753,  1757,  1763,  1763,  1765,
    1768,  1768,  1770,  1776,  1783,  1783,  1786,  1787,  1791,  1791,
    1793,  1799,  1807,  1815,  1815,  1818,  1819,  1824,  1829,  1835,
    1845,  1846,  1848,  1848,  1850,  1855,  1857,  1862,  1865,  1866,
    1870,  1870,  1872,  1875,  1876,  1884,  1884,  1886,  1888,  1888,
    1890,  1893,  1902,  1906,  1912,  1912,  1914,  1916,  1916,  1918,
    1924,  1930,  1933,  1934,  1937,  1937,  1939,  1945,  1953,  1960,
    1960,  1963,  1964,  1969,  1974,  1980,  1990,  1991,  1994,  1994,
    1996,  2001,  2003,  2009,  2013,  2014,  2018,  2019,  2024,  2031,
    2030,  2046,  2046,  2049,  2056,  2065,  2066,  2066,  2070,  2070,
    2070,  2070,  2072,  2085,  2091,  2099,  2102,  2105,  2108,  2110,
    2111,  2114,  2119,  2126,  2126,  2129,  2128,  2135,  2135,  2137,
    2139,  2139,  2141,  2141,  2144,  2151,  2153,  2155,  2154,  2159,
    2159,  2159,  2159,  2161,  2176,  2183,  2192,  2198,  2201,  2207,
    2209,  2210,  2212,  2217,  2223,  2223,  2226,  2225,  2229,  2231,
    2238,  2239,  2241,  2243,  2250,  2251,  2253,  2255,  2262,  2263,
    2265,  2267,  2274,  2275,  2277,  2279,  2286,  2287,  2289,  2291,
    2298,  2299,  2303,  2304,  2306,  2309,  2310,  2311,  2315,  2316,
    2317,  2318,  2320,  2321
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
  "otherConContent", "otherSolutionResults",
  "numberOfOtherSolutionResults", "@1", "otherSolutionResultList",
  "anotherSolutionResult", "anotherSolutionResultAttList", "@2",
  "anotherSolutionResultAtt", "numberOfOtherSolutionResultItems",
  "anotherSolutionResultNameATT", "anotherSolutionResultCategoryATT",
  "anotherSolutionDescriptionATT", "anotherSolutionItemList",
  "anotherSolutionItem", "otherSolutionItemEmpty",
  "otherSolutionItemContent", "@3", "otherSolverOutput",
  "numberOfSolverOutputsATT", "otherSolverOutputBody", "solverOutputArray",
  "solverOutput", "solverOutputAttList", "@4", "solverOutputAtt",
  "numberOfSolverOutputItems", "solverOutputNameATT",
  "solverOutputCategoryATT", "solverOutputDescriptionATT",
  "solverOutputItemList", "solverOutputItem", "solverOutputItemEmpty",
  "solverOutputItemContent", "@5", "categoryAttribute",
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
     514,   515,   516,   517,   517,   517,   518,   518,   518,   520,
     519,   521,   521,   522,   522,   523,   524,   523,   525,   525,
     525,   525,   526,   527,   527,   528,   528,   529,   529,   530,
     530,   531,   531,   532,   532,   534,   533,   535,   535,   536,
     537,   537,   538,   538,   539,   539,   540,   541,   540,   542,
     542,   542,   542,   543,   544,   544,   545,   545,   546,   546,
     547,   547,   548,   548,   549,   549,   551,   550,   552,   553,
     554,   554,   555,   556,   557,   557,   558,   559,   560,   560,
     561,   562,   563,   563,   564,   565,   566,   566,   567,   568,
     569,   569,   570,   570,   571,   572,   572,   572,   573,   573,
     573,   573,   574,   574
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
       3,     1,     4,     3,     2,     1,     0,     5,     3,     0,
       5,     0,     2,     5,     3,     0,     0,     3,     1,     1,
       1,     1,     4,     1,     3,     3,     1,     3,     1,     0,
       2,     1,     1,     1,     1,     0,     4,     0,     3,     4,
       1,     3,     0,     2,     5,     3,     0,     0,     3,     1,
       1,     1,     1,     4,     1,     3,     3,     1,     3,     1,
       0,     2,     1,     1,     1,     1,     0,     4,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     0,     2
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
     172,     0,   349,     0,   643,   651,     0,    21,    22,    26,
      25,   672,    24,   672,     0,    48,    44,     0,    53,    49,
       0,    58,    54,     0,    63,    59,     0,    68,    64,     0,
      73,    69,     0,    78,    74,   672,     0,   101,   146,   136,
     116,   126,   152,   111,   103,   104,     0,   105,   118,   106,
     128,   107,   138,   108,   147,   109,     0,     0,   230,   228,
     351,     0,   353,     0,     0,    31,    19,    28,    29,    23,
     672,   642,   645,     0,   672,   650,   653,     0,    47,     0,
      52,     0,    57,     0,    62,     0,    67,     0,    72,     0,
      77,     0,     0,    85,    79,    82,    83,     0,   114,   110,
       0,   117,     0,   127,     0,   137,     0,   148,   672,     0,
     173,   188,   183,   208,   203,   198,   193,   175,   176,     0,
     177,     0,   178,     0,   179,     0,   180,     0,   181,     0,
       0,     2,     0,   352,     0,    30,    36,     0,    33,    38,
     644,   664,   668,   669,   670,   671,   673,   652,    46,    51,
      56,    61,    66,    71,    76,   672,    90,    84,     0,    87,
      92,     0,   113,     0,   115,   655,   119,   121,   120,   672,
       0,   125,   129,   131,   130,     0,   135,   139,   141,   140,
       0,   145,     0,     0,   157,   151,   154,   155,     0,   186,
     182,     0,   191,   187,     0,   196,   192,     0,   201,   197,
       0,   206,   202,   672,     0,   229,   259,   264,   330,   254,
     244,   249,   269,   324,   314,   294,   304,   231,   232,     0,
     233,     0,   234,     0,   235,     0,   236,     0,   237,     0,
     238,   296,   239,   306,   240,   316,   241,   325,   242,     0,
       0,   366,   350,   363,   364,   672,   672,   672,   672,   354,
     355,   356,   357,   358,    27,    32,    34,     0,    37,    81,
      86,    88,     0,    91,   112,   123,   124,     0,   672,   654,
     657,   133,   134,     0,   143,   144,     0,   150,     0,   672,
     162,   156,     0,   159,   164,     0,   185,     0,   190,     0,
     195,     0,   200,   662,   663,   205,     0,     0,     0,   213,
     207,   210,   211,     0,   247,   243,     0,   252,   248,     0,
     257,   253,     0,   262,   258,     0,   267,   263,     0,     0,
       0,   295,     0,   305,     0,   315,     0,   326,   672,     0,
     365,   371,   607,   368,   373,     0,     0,     0,     0,     0,
      43,    35,   647,    39,    41,    40,   672,     0,    98,    89,
     659,    93,    96,    94,    95,   672,   122,   656,   132,   142,
     149,   153,   158,   160,     0,   163,   184,   189,   194,   199,
     204,   672,   218,   212,     0,   215,   220,     0,   246,     0,
     251,     0,   256,     0,   261,     0,   266,     0,     0,   274,
     268,   271,   272,     0,   293,   297,   299,   298,     0,   303,
     307,   309,   308,     0,   313,   317,   319,   318,     0,   323,
       0,     0,   335,   329,   332,   333,     0,   369,     0,     0,
     372,   672,   672,   672,   672,    42,   672,   646,   649,    97,
     672,   658,   661,     0,   170,   161,   165,   168,   166,   167,
     209,   214,   216,     0,   219,   245,   250,   255,   260,   265,
       0,   279,   273,     0,   276,   280,   301,   302,     0,   311,
     312,     0,   321,   322,     0,   328,     0,   672,   340,   334,
       0,   337,   342,   672,     0,   367,     0,   370,   672,     0,
     374,   375,   376,   361,   362,   359,   360,   648,   660,   169,
       0,   226,   217,   221,   224,   222,   223,   270,   275,   277,
       0,   300,   310,   320,   327,   331,   336,   338,     0,   341,
       0,   612,   610,   608,   381,   405,     0,     0,   672,   225,
       0,   289,   639,   281,   278,   286,   287,   284,   672,   285,
     283,   282,     0,   348,   339,   343,   346,   344,   345,   672,
       0,     0,   409,     0,     0,   382,   383,   387,   386,   385,
     672,   378,   292,   291,   288,     0,   672,   638,   641,   347,
     609,   611,   616,   613,     0,   408,   411,   483,   412,     0,
       0,   392,   380,   389,   390,   384,   377,   290,   640,   617,
       0,   407,   485,   530,   486,   672,     0,     0,   391,   397,
       0,   394,   399,   630,   615,     0,   406,   532,   576,   533,
     672,     0,     0,   417,   414,   410,   415,   388,   393,   395,
       0,   398,     0,     0,     0,   627,     0,   629,     0,   624,
     618,   619,   620,   621,   622,     0,     0,   672,     0,     0,
     491,   488,   484,   489,   672,   419,   433,     0,     0,   404,
     396,   400,   402,   401,     0,   634,   635,   614,   631,   632,
     633,     0,     0,     0,     0,     0,     0,   379,     0,   538,
     535,   531,   536,   672,   493,   508,     0,   413,   435,   447,
       0,   672,     0,   403,   636,     0,   626,   628,   625,     0,
     581,   578,   672,   540,   554,     0,   487,     0,   672,     0,
     449,   461,     0,   672,     0,     0,     0,   424,   418,   421,
     422,     0,   623,   579,     0,   534,     0,   672,     0,   490,
     511,   509,   513,     0,     0,   498,   492,   495,   496,     0,
     672,     0,     0,     0,   440,   434,   437,   438,   672,   423,
     429,     0,   426,     0,   637,     0,   585,   577,   582,   537,
     557,   555,   559,     0,     0,   545,   539,   542,   543,     0,
     512,   672,   503,   497,     0,   500,   504,   464,   416,   462,
     466,     0,     0,   454,   448,   451,   452,   672,   439,   445,
       0,   442,     0,   420,   425,   427,   672,     0,   580,   586,
       0,   558,   672,   550,   544,     0,   547,     0,   522,   520,
     510,   672,   514,   515,   518,   517,   516,   494,   499,   501,
     672,     0,     0,   465,   672,   453,   459,     0,   456,     0,
     436,   441,   443,   672,     0,     0,     0,   599,   584,     0,
     568,   566,   556,   672,   560,   561,   564,   563,   562,   541,
     546,   548,   672,     0,     0,     0,     0,     0,   475,   473,
     463,   672,   467,   468,   471,   470,   469,   450,   455,   457,
     672,     0,     0,     0,   672,   431,   432,     0,     0,     0,
       0,   596,     0,   598,     0,   593,   587,   588,   589,   590,
     591,     0,     0,     0,     0,   525,   521,   523,     0,   672,
     672,   506,   507,     0,     0,     0,     0,     0,   672,     0,
     430,   428,     0,   603,   604,   583,   600,   601,   602,     0,
       0,     0,   672,   571,   567,   569,     0,   672,   672,   552,
     553,     0,   672,     0,   519,   505,   502,   474,   478,   476,
       0,   672,   672,     0,   446,   444,   605,     0,   595,   597,
     594,   672,     0,   565,   551,   549,     0,     0,   529,   524,
     672,     0,   472,   460,   458,     0,   592,     0,     0,   575,
     570,   672,   665,   666,   667,   528,     0,     0,     0,   482,
     477,   606,   672,   574,     0,   526,   527,   672,   481,     0,
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
     159,   235,   236,   237,   332,   333,   334,   414,   415,   486,
     485,    18,   107,   167,   168,   169,   240,   170,   171,   243,
     172,   173,   246,   174,   175,   249,   176,   177,   252,   178,
     179,   254,   350,   351,   352,   424,   425,   426,   493,   494,
     543,   542,    52,   180,   267,   268,   269,   355,   270,   271,
     358,   272,   273,   361,   274,   275,   364,   276,   277,   367,
     278,   279,   369,   440,   441,   442,   503,   504,   505,   550,
     573,   574,   575,   576,   605,   280,   281,   370,   371,   445,
     444,   508,   282,   283,   372,   373,   450,   449,   511,   284,
     285,   374,   375,   455,   454,   514,   286,   287,   376,   459,
     516,   288,   289,   379,   463,   464,   465,   520,   521,   522,
     558,   559,   585,   584,   111,   112,   182,   183,   299,   300,
     301,   302,   303,   292,   293,   294,   382,   383,   384,   469,
     470,   530,   531,   532,   527,   565,   566,   594,   595,   596,
     597,   622,   623,   624,   640,   641,   642,   660,   661,   691,
     690,   592,   617,   618,   636,   655,   656,   686,   687,   722,
     748,   749,   750,   781,   782,   783,   827,   907,   719,   720,
     744,   775,   776,   777,   820,   821,   822,   864,   741,   742,
     771,   814,   815,   816,   857,   858,   859,   901,   769,   809,
     810,   852,   853,   892,   893,   890,   934,   969,   970,   991,
    1010,   633,   634,   651,   682,   683,   715,   716,   739,   766,
     767,   768,   804,   805,   806,   851,   933,   737,   761,   762,
     799,   800,   842,   843,   840,   884,   927,   928,   963,   989,
     648,   649,   678,   711,   712,   734,   735,   758,   796,   797,
     798,   835,   836,   837,   883,   961,   756,   791,   792,   830,
     831,   874,   875,   872,   921,   955,   956,   982,  1000,   676,
     706,   785,   754,   788,   829,   869,   916,   917,   918,   919,
     920,   908,   946,   947,   948,   995,   468,   524,   563,   590,
     613,   629,   645,   670,   671,   672,   673,   674,   662,   698,
     699,   700,   751,   577,   578,   607,    60,    61,   121,   395,
     396,   477,    62,    63,   125,   218,   219,   319,   404,   405,
     481,   346,   122,  1006,   196,   123
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -807
static const yytype_int16 yypact[] =
{
      10,    48,    68,     8,  -807,   108,  -807,   271,   109,  -807,
    -807,  -807,   273,   162,   -18,  -807,  -807,   275,   118,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,   184,  -807,   277,  -807,   279,  -807,   281,  -807,   283,
    -807,   285,  -807,   287,  -807,   289,  -807,   204,    46,  -807,
    -807,   291,   173,   231,  -807,  -807,   293,   184,  -807,  -807,
    -807,   238,  -807,   242,    22,  -807,  -807,    15,  -807,  -807,
      16,  -807,  -807,    35,  -807,  -807,    34,  -807,  -807,    14,
    -807,  -807,     6,  -807,  -807,  -807,   295,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,   297,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,   220,  -807,   240,    -9,  -807,  -807,
    -807,   216,  -807,   263,   -49,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,    -3,  -807,  -807,  -807,   182,  -807,   211,
    -807,   192,  -807,   241,  -807,   246,  -807,   230,  -807,   224,
    -807,   394,   134,  -807,  -807,  -807,  -807,    13,  -807,  -807,
     402,   153,   406,   153,   408,   153,   429,  -807,  -807,   299,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,   303,
    -807,   306,  -807,   308,  -807,   310,  -807,   312,  -807,   413,
     -27,  -807,   314,   190,   432,  -807,  -807,   -43,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,   140,  -807,
    -807,   305,  -807,   320,  -807,  -807,  -807,  -807,  -807,   440,
     322,  -807,  -807,  -807,  -807,   324,  -807,  -807,  -807,  -807,
     438,  -807,   439,   141,  -807,  -807,  -807,  -807,    37,  -807,
    -807,    30,  -807,  -807,     1,  -807,  -807,     4,  -807,  -807,
      17,  -807,  -807,  -807,   325,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,   327,
    -807,   329,  -807,   333,  -807,   335,  -807,   337,  -807,   421,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,   220,  -807,   430,
     -23,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,   339,    75,  -807,
    -807,  -807,   341,   196,  -807,  -807,  -807,   381,  -807,  -807,
    -807,  -807,  -807,   377,  -807,  -807,   385,  -807,   390,  -807,
    -807,  -807,   145,  -807,  -807,   375,  -807,   378,  -807,   304,
    -807,   316,  -807,  -807,  -807,  -807,   330,   455,   147,  -807,
    -807,  -807,  -807,    12,  -807,  -807,    11,  -807,  -807,    21,
    -807,  -807,    76,  -807,  -807,    28,  -807,  -807,   454,   343,
     456,   153,   457,   153,   458,   153,   459,  -807,  -807,   345,
    -807,  -807,    57,  -807,  -807,   464,   465,   466,   467,   340,
    -807,  -807,  -807,  -807,  -807,  -807,   461,   367,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,   473,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,   349,   196,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,   151,  -807,  -807,   346,  -807,   347,
    -807,   361,  -807,   416,  -807,   395,  -807,   475,    80,  -807,
    -807,  -807,  -807,   355,  -807,  -807,  -807,  -807,   357,  -807,
    -807,  -807,  -807,   359,  -807,  -807,  -807,  -807,   477,  -807,
     478,   152,  -807,  -807,  -807,  -807,   462,  -807,   431,   476,
      25,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,   380,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,   358,   196,  -807,  -807,  -807,  -807,  -807,
     482,  -807,  -807,    99,  -807,  -807,  -807,  -807,   338,  -807,
    -807,   342,  -807,  -807,   344,  -807,   350,  -807,  -807,  -807,
     156,  -807,  -807,  -807,   360,  -807,   363,  -807,  -807,   491,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
     389,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
     157,  -807,  -807,  -807,  -807,  -807,  -807,  -807,   362,   196,
     492,  -807,  -807,  -807,  -807,   404,   195,   495,  -807,  -807,
       7,  -807,  -807,  -807,  -807,  -807,  -807,  -807,   499,  -807,
    -807,  -807,   397,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
     -64,   364,   348,   498,   366,   195,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,   369,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,    29,  -807,  -807,   403,   486,   503,
     133,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,   368,
     415,  -807,  -807,   433,   496,  -807,   370,   505,  -807,  -807,
     142,  -807,  -807,  -807,  -807,   143,  -807,  -807,   405,   501,
    -807,   372,   510,   365,  -807,  -807,  -807,  -807,  -807,  -807,
     374,   206,    26,   511,   519,  -807,   520,  -807,   521,  -807,
    -807,  -807,  -807,  -807,  -807,   507,   400,  -807,   376,   522,
     373,  -807,  -807,  -807,  -807,  -807,   383,   504,   398,  -807,
    -807,  -807,  -807,  -807,   526,  -807,  -807,  -807,  -807,  -807,
    -807,   528,   524,   527,   530,   531,   379,  -807,   534,   452,
    -807,  -807,  -807,  -807,  -807,  -807,   529,  -807,  -807,   474,
     523,  -807,   382,  -807,  -807,   537,  -807,  -807,  -807,   541,
    -807,  -807,  -807,  -807,  -807,   536,  -807,   103,  -807,   384,
    -807,  -807,   525,  -807,   386,   544,   114,  -807,  -807,  -807,
    -807,   493,  -807,  -807,   165,  -807,   -37,  -807,   388,  -807,
    -807,  -807,  -807,   547,    -6,  -807,  -807,  -807,  -807,   -57,
    -807,   392,   548,   245,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,   120,  -807,   532,  -807,   549,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,   550,    -4,  -807,  -807,  -807,  -807,   396,
     154,  -807,  -807,  -807,    -5,  -807,   533,  -807,  -807,  -807,
    -807,   553,   -30,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
     255,  -807,   535,  -807,  -807,  -807,  -807,   545,  -807,   410,
     412,    43,  -807,  -807,  -807,     3,  -807,   538,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,   555,   414,   181,  -807,  -807,  -807,   -26,  -807,   539,
    -807,  -807,  -807,  -807,   556,   554,   420,  -807,  -807,   166,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,   559,    72,   557,   564,   422,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,   561,   567,   570,  -807,  -807,  -807,   417,   100,   568,
     572,  -807,   574,  -807,   576,  -807,  -807,  -807,  -807,  -807,
    -807,   -11,   575,   577,   424,  -807,  -807,  -807,   551,  -807,
    -807,  -807,  -807,   483,   -62,   578,   579,   582,  -807,   428,
    -807,  -807,   583,  -807,  -807,  -807,  -807,  -807,  -807,   584,
     585,   586,  -807,  -807,  -807,  -807,   562,  -807,  -807,  -807,
    -807,   515,  -807,   423,  -807,  -807,  -807,  -807,  -807,  -807,
     566,  -807,  -807,   435,  -807,  -807,  -807,   589,  -807,  -807,
    -807,  -807,   425,  -807,  -807,  -807,   592,    23,  -807,  -807,
    -807,   427,  -807,  -807,  -807,   540,  -807,   594,    56,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,   502,   596,     5,  -807,
    -807,  -807,  -807,  -807,   542,  -807,  -807,  -807,  -807,   442,
    -807,  -807,  -807,  -807
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
     552,  -807,  -807,  -807,  -807,  -807,   418,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
     399,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,   272,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,   186,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,   105,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,    86,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,   229,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,    18,
    -807,  -807,  -807,  -807,  -807,   -28,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -166,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -204,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -240,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -186,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -215,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -103,  -807,  -807,  -311,
    -807,  -807,  -529,  -807,  -807,  -149,  -807,  -807,  -412,  -807,
    -807,  -807,   -63,  -806,  -807,  -807
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     126,   157,   403,   489,   224,   191,   229,   339,   341,  1002,
     139,  1003,  1004,   602,   603,   429,   427,   211,   137,   129,
     131,   580,   141,   343,   344,   431,   127,  1002,   255,  1003,
    1004,    19,   435,   630,   380,   256,   337,   599,   135,   133,
     185,   335,   789,   855,   160,   967,   305,   898,   217,   807,
     223,   611,   228,   528,     1,   873,     7,   190,     4,   257,
    1002,   197,  1003,  1004,   612,   953,   599,   529,     6,   790,
      20,   161,   833,   162,    21,    54,    22,   392,    23,   833,
     433,   258,   546,   400,   694,   186,   695,   696,   880,   259,
      24,   186,   802,   802,     5,   232,   954,    87,   968,   163,
      25,   381,    26,   260,   488,   261,   808,    54,    27,   392,
      88,   338,    89,   164,    90,   436,    91,   262,     9,   128,
     336,   263,  1005,   264,    28,   265,   631,   266,   134,   136,
     856,   165,   693,  1013,   856,   132,   130,   166,   432,   434,
     345,   138,   309,   428,   430,   342,   604,   588,   340,   140,
     212,   803,   848,   834,    92,   697,   320,   663,   942,    12,
     943,   944,   192,   193,   194,   195,  1018,   570,   571,   841,
     925,   466,    51,   664,   665,   666,   667,   668,   669,   926,
     909,   381,    93,   545,   377,    54,    54,   572,   392,    54,
     347,   215,  1014,    55,   400,   215,   910,   911,   912,   913,
     914,   915,  1019,   295,   759,   394,   296,   891,    53,   760,
     402,   945,   297,    54,    17,   392,    54,   298,   501,   593,
      55,   400,   447,    85,   452,   502,   457,    54,    54,   110,
     392,    55,   385,   386,   387,   388,   400,   501,    54,   113,
     206,   120,    55,   207,   548,   124,   206,   330,   587,   310,
     331,   330,    54,   422,   412,   407,   423,   422,   518,   158,
     491,   519,   518,   181,   638,   556,   411,   639,   446,   184,
     451,   779,   456,   658,   780,   786,   639,   824,   787,   198,
     780,    10,    11,    15,    16,    49,    50,    64,    65,    67,
      68,    70,    71,    73,    74,    76,    77,    79,    80,    82,
      83,   108,   109,   114,   115,   142,   143,   147,   148,   233,
     234,   200,   487,   238,   239,   460,   241,   242,   244,   245,
     247,   248,   250,   251,   290,   291,   315,   316,   321,   322,
     324,   325,   199,   478,   201,   348,   349,   353,   354,   356,
     357,   202,   482,   359,   360,   362,   363,   365,   366,   389,
     390,   397,   398,   438,   439,   461,   462,   203,   490,   483,
     484,   506,   507,   509,   510,   512,   513,   204,   540,   541,
     561,   562,   582,   583,   614,   615,   620,   621,   643,   644,
     653,   654,   680,   681,   688,   689,   709,   710,   846,   730,
     731,   544,   746,   747,   764,   765,   773,   774,   794,   795,
     205,   581,   812,   813,   818,   819,   838,   839,   533,   534,
     535,   536,   213,   537,   861,   819,   220,   538,   225,   878,
     867,   868,   870,   871,   888,   889,   905,   906,   931,   932,
     959,   960,   253,   987,   988,   998,   999,  1008,  1009,   230,
     304,   896,   314,   318,   327,   329,   368,   579,   408,   378,
     406,   418,   409,   420,   555,   410,   586,   419,   416,   417,
     560,   421,   437,   598,   476,   567,   443,   448,   453,   458,
     471,   472,   473,   474,   479,   475,   480,   495,   497,   498,
     496,   500,   499,   515,   517,   523,   526,   539,   525,   845,
     547,   551,   598,   564,   568,   553,   569,   552,   589,   554,
     591,   600,   606,   632,   609,   601,   619,   635,   627,   637,
     616,   647,   646,   657,   650,   608,   684,   675,   677,   701,
     877,   685,   702,   703,   704,   707,   610,   705,   713,   714,
     721,   724,   726,   723,   725,   727,   733,   626,   728,   729,
     732,   718,   895,   628,   738,   752,   740,   753,   757,   743,
     778,   770,   784,   801,   817,   866,   832,   828,   692,   854,
     904,   826,   850,   929,   863,   887,   903,   882,   900,   924,
     930,   937,   652,   938,   939,   950,   949,   951,   941,   952,
     962,   957,   966,   958,   971,   972,   973,   679,   976,   975,
     977,   981,   985,   978,   979,   990,   994,   996,  1001,  1011,
    1012,  1016,  1017,  1023,   413,   306,   557,   311,   549,   119,
     492,   467,   659,   625,   708,   825,   862,   899,   849,  1021,
     881,   717,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     736,     0,     0,     0,     0,     0,     0,     0,   745,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   755,
       0,     0,     0,     0,     0,   763,     0,     0,     0,     0,
     772,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   793,     0,     0,   844,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   811,     0,     0,
       0,     0,     0,     0,     0,   823,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   876,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   847,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     894,     0,     0,     0,   860,     0,     0,     0,     0,     0,
       0,     0,     0,   865,     0,     0,     0,     0,     0,   879,
       0,     0,     0,     0,     0,     0,     0,     0,   885,     0,
       0,     0,     0,     0,     0,     0,     0,   886,     0,     0,
       0,   897,     0,     0,     0,     0,     0,     0,     0,     0,
     902,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     922,     0,     0,     0,     0,     0,     0,     0,     0,   923,
       0,     0,     0,     0,     0,     0,     0,     0,   935,     0,
       0,     0,     0,     0,     0,     0,     0,   936,     0,     0,
       0,   940,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   964,   965,     0,     0,
       0,     0,     0,     0,     0,   974,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   980,
       0,     0,     0,     0,   983,   984,     0,     0,     0,   986,
       0,     0,     0,     0,     0,     0,     0,     0,   992,   993,
       0,     0,     0,     0,     0,     0,     0,     0,   997,     0,
       0,     0,     0,     0,     0,     0,     0,  1007,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1015,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1020,
       0,     0,     0,     0,  1022
};

static const yytype_int16 yycheck[] =
{
      63,   104,   313,   415,   153,     8,   155,     6,     4,     4,
       4,     6,     7,     6,     7,     4,     4,     4,     4,     4,
       4,   550,    85,     6,     7,     4,     4,     4,    55,     6,
       7,    49,     4,     4,    57,    62,     6,   566,     4,     4,
      89,     4,    79,    73,    53,   107,    89,    73,   151,   106,
     153,   115,   155,    28,    44,    12,    48,   120,    10,    86,
       4,   124,     6,     7,   128,    76,   595,    42,     0,   106,
      88,    80,    76,    82,    92,    32,    94,    34,    96,    76,
       4,   108,   494,    40,    58,   134,    60,    61,    85,   116,
     108,   134,    98,    98,    46,   158,   107,    51,   160,   108,
     118,   124,   120,   130,   415,   132,   163,    32,   126,    34,
      64,    81,    66,   122,    68,    87,    70,   144,    10,    97,
      83,   148,    99,   150,   142,   152,    97,   154,    93,    95,
     160,   140,   661,    77,   160,   119,   121,   146,   117,    63,
     123,   127,   205,   131,   133,   141,   139,   559,   147,   143,
     137,   157,   157,   157,   108,   129,   219,    14,    58,    50,
      60,    61,   165,   166,   167,   168,   161,    10,    11,    15,
      98,   114,    54,    30,    31,    32,    33,    34,    35,   107,
      14,   124,   136,   494,   287,    32,    32,    30,    34,    32,
     253,    38,   998,    36,    40,    38,    30,    31,    32,    33,
      34,    35,  1008,    13,   101,   308,    16,    26,    24,   106,
     313,   111,    22,    32,    52,    34,    32,    27,   138,    24,
      36,    40,   371,    19,   373,   145,   375,    32,    32,    56,
      34,    36,   295,   296,   297,   298,    40,   138,    32,     8,
     106,     3,    36,   109,   145,     3,   106,   106,   559,   109,
     109,   106,    32,   106,   109,   318,   109,   106,   106,    19,
     109,   109,   106,    47,   131,   109,   329,   134,   371,     6,
     373,   157,   375,   131,   160,   110,   134,   157,   113,    97,
     160,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,   119,   415,    10,    11,   378,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,     6,     7,     6,     7,
       6,     7,   121,   396,    93,    10,    11,    10,    11,    10,
      11,    95,   405,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,   127,   421,    10,
      11,     6,     7,     6,     7,     6,     7,   143,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,   800,    10,
      11,   494,    10,    11,    10,    11,    10,    11,    10,    11,
       6,   550,    10,    11,   159,   160,    10,    11,   471,   472,
     473,   474,    10,   476,   159,   160,    10,   480,    10,   831,
      10,    11,    10,    11,    10,    11,     6,     7,     6,     7,
       6,     7,    19,    10,    11,    10,    11,    10,    11,    10,
       8,   853,   137,     3,     6,     6,    25,   550,    71,    19,
      69,   147,    67,   123,   517,    65,   559,   141,    83,    81,
     523,     6,     8,   566,     3,   528,    10,    10,    10,    10,
       6,     6,     6,     6,   107,   135,     3,   131,   117,    63,
     133,     6,    87,     6,     6,    23,    10,   107,    57,   800,
       8,   153,   595,   130,     3,   151,   107,   155,     6,   149,
      96,     6,     3,   100,   107,   568,     8,    21,   139,     6,
     162,    78,    97,     8,    18,   578,     6,   112,    17,     8,
     831,   156,     3,     3,     3,   125,   589,    20,     6,   156,
      26,     5,     8,   135,     6,     8,    84,   600,     8,     8,
       6,   158,   853,   606,    15,     8,    72,     6,    12,    26,
       6,    26,    59,     6,     6,    10,     6,     8,   661,     6,
       6,    29,    29,     6,    29,    10,    10,    29,    29,    10,
       6,    10,   635,     6,     4,     3,     8,     3,   161,     3,
      29,     6,    99,     6,     6,     6,     4,   650,     5,   161,
       6,    29,    77,     8,     8,    29,   161,     8,     6,    59,
       6,    99,     6,   161,   332,   187,   520,   208,   503,    57,
     424,   382,   640,   595,   677,   781,   820,   857,   804,    77,
     835,   684,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   721,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   732,
      -1,    -1,    -1,    -1,    -1,   738,    -1,    -1,    -1,    -1,
     743,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   757,    -1,    -1,   800,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   770,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   778,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   831,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   801,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     853,    -1,    -1,    -1,   817,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   826,    -1,    -1,    -1,    -1,    -1,   832,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   841,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   850,    -1,    -1,
      -1,   854,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     863,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     873,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   882,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   891,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   900,    -1,    -1,
      -1,   904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   929,   930,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   938,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   952,
      -1,    -1,    -1,    -1,   957,   958,    -1,    -1,    -1,   962,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   971,   972,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   981,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   990,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1001,    -1,
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
     555,   556,   561,   562,    10,    11,   193,    10,    11,   196,
      10,    11,   199,    10,    11,   202,    10,    11,   205,    10,
      11,   208,    10,    11,   211,    19,   214,    51,    64,    66,
      68,    70,   108,   136,   227,   228,   229,   231,   232,   238,
     239,   245,   246,   252,   253,   257,   258,   271,    10,    11,
      56,   373,   374,     8,    10,    11,   181,   182,   183,   179,
       3,   557,   571,   574,     3,   563,   571,     4,    97,     4,
     121,     4,   119,     4,    93,     4,    95,     4,   127,     4,
     143,   571,    10,    11,   215,   216,   217,    10,    11,   230,
     233,   234,   240,   241,   247,   248,   254,   555,    19,   259,
      53,    80,    82,   108,   122,   140,   146,   272,   273,   274,
     276,   277,   279,   280,   282,   283,   285,   286,   288,   289,
     302,    47,   375,   376,     6,    89,   134,   184,   185,   186,
     571,     8,   165,   166,   167,   168,   573,   571,    97,   121,
     119,    93,    95,   127,   143,     6,   106,   109,   218,   219,
     220,     4,   137,    10,   236,    38,   235,   555,   564,   565,
      10,   243,   242,   555,   564,    10,   250,   249,   555,   564,
      10,   255,   571,    10,    11,   260,   261,   262,    10,    11,
     275,    10,    11,   278,    10,    11,   281,    10,    11,   284,
      10,    11,   287,    19,   290,    55,    62,    86,   108,   116,
     130,   132,   144,   148,   150,   152,   154,   303,   304,   305,
     307,   308,   310,   311,   313,   314,   316,   317,   319,   320,
     334,   335,   341,   342,   348,   349,   355,   356,   360,   361,
      10,    11,   382,   383,   384,    13,    16,    22,    27,   377,
     378,   379,   380,   381,     8,    89,   185,   187,   188,   571,
     109,   219,   221,   222,   137,     6,     7,   237,     3,   566,
     571,     6,     7,   244,     6,     7,   251,     6,   256,     6,
     106,   109,   263,   264,   265,     4,    83,     6,    81,     6,
     147,     4,   141,     6,     7,   123,   570,   571,    10,    11,
     291,   292,   293,    10,    11,   306,    10,    11,   309,    10,
      11,   312,    10,    11,   315,    10,    11,   318,    25,   321,
     336,   337,   343,   344,   350,   351,   357,   555,    19,   362,
      57,   124,   385,   386,   387,   571,   571,   571,   571,    10,
      11,   190,    34,   189,   555,   558,   559,    10,    11,   224,
      40,   223,   555,   558,   567,   568,    69,   571,    71,    67,
      65,   571,   109,   264,   266,   267,    83,    81,   147,   141,
     123,     6,   106,   109,   294,   295,   296,     4,   131,     4,
     133,     4,   117,     4,    63,     4,    87,     8,    10,    11,
     322,   323,   324,    10,   339,   338,   555,   564,    10,   346,
     345,   555,   564,    10,   353,   352,   555,   564,    10,   358,
     571,    10,    11,   363,   364,   365,   114,   386,   535,   388,
     389,     6,     6,     6,     6,   135,     3,   560,   571,   107,
       3,   569,   571,    10,    11,   269,   268,   555,   558,   567,
     571,   109,   295,   297,   298,   131,   133,   117,    63,    87,
       6,   138,   145,   325,   326,   327,     6,     7,   340,     6,
       7,   347,     6,     7,   354,     6,   359,     6,   106,   109,
     366,   367,   368,    23,   536,    57,    10,   393,    28,    42,
     390,   391,   392,   571,   571,   571,   571,   571,   571,   107,
      10,    11,   300,   299,   555,   558,   567,     8,   145,   326,
     328,   153,   155,   151,   149,   571,   109,   367,   369,   370,
     571,    10,    11,   537,   130,   394,   395,   571,     3,   107,
      10,    11,    30,   329,   330,   331,   332,   552,   553,   555,
     561,   564,    10,    11,   372,   371,   555,   558,   567,     6,
     538,    96,   410,    24,   396,   397,   398,   399,   555,   561,
       6,   571,     6,     7,   139,   333,     3,   554,   571,   107,
     571,   115,   128,   539,    10,    11,   162,   411,   412,     8,
      10,    11,   400,   401,   402,   398,   571,   139,   571,   540,
       4,    97,   100,   460,   461,    21,   413,     6,   131,   134,
     403,   404,   405,    10,    11,   541,    97,    78,   489,   490,
      18,   462,   571,    10,    11,   414,   415,     8,   131,   404,
     406,   407,   547,    14,    30,    31,    32,    33,    34,    35,
     542,   543,   544,   545,   546,   112,   518,    17,   491,   571,
      10,    11,   463,   464,     6,   156,   416,   417,    10,    11,
     409,   408,   555,   561,    58,    60,    61,   129,   548,   549,
     550,     8,     3,     3,     3,    20,   519,   125,   571,    10,
      11,   492,   493,     6,   156,   465,   466,   571,   158,   427,
     428,    26,   418,   135,     5,     6,     8,     8,     8,     8,
      10,    11,     6,    84,   494,   495,   571,   476,    15,   467,
      72,   437,   438,    26,   429,   571,    10,    11,   419,   420,
     421,   551,     8,     6,   521,   571,   505,    12,   496,   101,
     106,   477,   478,   571,    10,    11,   468,   469,   470,   447,
      26,   439,   571,    10,    11,   430,   431,   432,     6,   157,
     160,   422,   423,   424,    59,   520,   110,   113,   522,    79,
     106,   506,   507,   571,    10,    11,   497,   498,   499,   479,
     480,     6,    98,   157,   471,   472,   473,   106,   163,   448,
     449,   571,    10,    11,   440,   441,   442,     6,   159,   160,
     433,   434,   435,   571,   157,   423,    29,   425,     8,   523,
     508,   509,     6,    76,   157,   500,   501,   502,    10,    11,
     483,    15,   481,   482,   555,   558,   567,   571,   157,   472,
      29,   474,   450,   451,     6,    73,   160,   443,   444,   445,
     571,   159,   434,    29,   436,   571,    10,    10,    11,   524,
      10,    11,   512,    12,   510,   511,   555,   558,   567,   571,
      85,   501,    29,   503,   484,   571,   571,    10,    10,    11,
     454,    26,   452,   453,   555,   558,   567,   571,    73,   444,
      29,   446,   571,    10,     6,     6,     7,   426,   530,    14,
      30,    31,    32,    33,    34,    35,   525,   526,   527,   528,
     529,   513,   571,   571,    10,    98,   107,   485,   486,     6,
       6,     6,     7,   475,   455,   571,   571,    10,     6,     4,
     571,   161,    58,    60,    61,   111,   531,   532,   533,     8,
       3,     3,     3,    76,   107,   514,   515,     6,     6,     6,
       7,   504,    29,   487,   571,   571,    99,   107,   160,   456,
     457,     6,     6,     4,   571,   161,     5,     6,     8,     8,
     571,    29,   516,   571,   571,    77,   571,    10,    11,   488,
      29,   458,   571,   571,   161,   534,     8,   571,    10,    11,
     517,     6,     4,     6,     7,    99,   572,   571,    10,    11,
     459,    59,     6,    77,   572,   571,    99,     6,   161,   572,
     571,    77,   571,   161
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
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
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

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
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
//	parserData->ivar = 0;
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
	parserData->timeType = "elapsedTime";
	parserData->timeCategory = "total";
	parserData->timeUnit = "second";
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

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
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

    {	osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
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

  case 577:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 578:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 579:

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

  case 583:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 584:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 586:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 592:

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

  case 593:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->nameAttributePresent = true;
//	parserData->otherVarStruct->name = "";
;}
    break;

  case 594:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); //parserData->nameAttributePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 595:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 597:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 600:

    {parserData->kounter++;;}
    break;

  case 601:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 602:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 605:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 614:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
;}
    break;

  case 617:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/;}
    break;

  case 623:

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

  case 624:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->nameAttributePresent = true; 
	parserData->otherVarStruct->name = "";
*/
;}
    break;

  case 625:

    {
/*	parserData->tmpOtherName=$2; parserData->nameAttributePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
;}
    break;

  case 626:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
;}
    break;

  case 628:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
;}
    break;

  case 632:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/;}
    break;

  case 633:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/;}
    break;

  case 636:

    {/*parserData->itemContent = $2; free($2);*/;}
    break;

  case 639:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one category attribute allowed for generalStatus element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 640:

    { parserData->categoryAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 641:

    { parserData->categoryAttribute = "";          ;}
    break;

  case 643:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one description attribute allowed for generalStatus element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 644:

    { parserData->descriptionAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 645:

    { parserData->descriptionAttribute = "";          ;}
    break;

  case 647:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one name attribute allowed for generalStatus element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 648:

    { parserData->nameAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 649:

    { parserData->nameAttribute = "";          ;}
    break;

  case 651:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one type attribute allowed for generalStatus element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 652:

    { parserData->typeAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 653:

    { parserData->typeAttribute = "";          ;}
    break;

  case 655:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one unit attribute allowed for generalStatus element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 656:

    { parserData->unitAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 657:

    { parserData->unitAttribute = "";          ;}
    break;

  case 659:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one value attribute allowed for generalStatus element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 660:

    { parserData->valueAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 661:

    { parserData->valueAttribute = "";          ;}
    break;

  case 662:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 663:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 665:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 666:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 667:

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


