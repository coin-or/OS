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
#define YYNNTS  469
/* YYNRULES -- Number of rules.  */
#define YYNRULES  737
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1083

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
     103,   105,   107,   110,   112,   115,   117,   119,   121,   124,
     126,   130,   133,   135,   137,   139,   142,   144,   148,   151,
     153,   155,   157,   160,   162,   166,   169,   171,   173,   175,
     178,   180,   184,   187,   189,   191,   193,   196,   198,   202,
     205,   207,   209,   211,   214,   216,   220,   223,   225,   227,
     229,   232,   234,   238,   242,   244,   249,   251,   253,   256,
     258,   262,   264,   267,   271,   273,   275,   276,   279,   281,
     283,   285,   288,   290,   291,   294,   299,   300,   303,   305,
     307,   309,   311,   313,   315,   318,   320,   322,   324,   327,
     329,   333,   337,   339,   341,   342,   345,   347,   349,   353,
     355,   357,   361,   363,   365,   366,   369,   371,   373,   377,
     379,   381,   385,   387,   389,   390,   393,   395,   397,   401,
     403,   405,   409,   411,   412,   414,   418,   420,   424,   426,
     431,   433,   435,   438,   440,   444,   446,   449,   453,   455,
     457,   458,   461,   463,   465,   467,   470,   472,   473,   476,
     481,   482,   485,   487,   489,   491,   493,   495,   497,   500,
     502,   504,   506,   509,   511,   515,   518,   520,   522,   524,
     527,   529,   533,   536,   538,   540,   542,   545,   547,   551,
     554,   556,   558,   560,   563,   565,   569,   572,   574,   576,
     578,   581,   583,   587,   591,   593,   598,   600,   602,   605,
     607,   611,   613,   616,   620,   622,   624,   625,   628,   630,
     632,   634,   637,   639,   640,   643,   648,   649,   652,   654,
     656,   658,   660,   662,   664,   666,   668,   670,   672,   674,
     677,   679,   681,   683,   686,   688,   692,   695,   697,   699,
     701,   704,   706,   710,   713,   715,   717,   719,   722,   724,
     728,   731,   733,   735,   737,   740,   742,   746,   749,   751,
     753,   755,   758,   760,   764,   768,   770,   775,   777,   779,
     782,   784,   788,   790,   793,   797,   799,   800,   803,   805,
     807,   809,   811,   813,   815,   818,   820,   824,   826,   828,
     832,   834,   836,   837,   840,   842,   844,   848,   850,   852,
     856,   858,   860,   861,   864,   866,   868,   872,   874,   876,
     880,   882,   884,   885,   888,   890,   892,   896,   898,   900,
     904,   906,   907,   909,   913,   915,   919,   921,   926,   928,
     930,   933,   935,   939,   941,   944,   948,   950,   952,   953,
     956,   958,   960,   962,   965,   967,   968,   972,   974,   976,
     977,   980,   982,   984,   986,   988,   993,   998,  1003,  1008,
    1010,  1012,  1015,  1017,  1022,  1024,  1027,  1031,  1033,  1035,
    1036,  1039,  1041,  1043,  1048,  1052,  1061,  1065,  1067,  1069,
    1071,  1074,  1076,  1078,  1080,  1085,  1087,  1089,  1092,  1094,
    1098,  1100,  1103,  1107,  1109,  1111,  1112,  1115,  1117,  1119,
    1122,  1124,  1125,  1128,  1130,  1132,  1134,  1137,  1139,  1143,
    1144,  1148,  1150,  1151,  1156,  1158,  1160,  1162,  1169,  1170,
    1174,  1176,  1181,  1183,  1185,  1188,  1190,  1194,  1196,  1199,
    1205,  1207,  1212,  1214,  1216,  1217,  1221,  1223,  1228,  1230,
    1232,  1235,  1237,  1241,  1243,  1246,  1252,  1254,  1259,  1260,
    1264,  1266,  1271,  1273,  1275,  1278,  1280,  1284,  1286,  1289,
    1295,  1297,  1302,  1303,  1306,  1310,  1312,  1314,  1315,  1318,
    1320,  1322,  1324,  1326,  1331,  1333,  1335,  1338,  1340,  1344,
    1346,  1349,  1353,  1355,  1360,  1362,  1364,  1367,  1369,  1373,
    1374,  1378,  1380,  1381,  1386,  1388,  1390,  1392,  1397,  1398,
    1402,  1404,  1409,  1411,  1413,  1416,  1418,  1422,  1424,  1427,
    1433,  1435,  1436,  1441,  1443,  1445,  1446,  1449,  1453,  1455,
    1457,  1458,  1461,  1463,  1465,  1467,  1469,  1474,  1476,  1478,
    1481,  1483,  1487,  1489,  1492,  1496,  1498,  1503,  1505,  1507,
    1510,  1512,  1516,  1517,  1521,  1523,  1524,  1529,  1531,  1533,
    1535,  1540,  1541,  1545,  1547,  1552,  1554,  1556,  1559,  1561,
    1565,  1567,  1570,  1576,  1578,  1583,  1585,  1587,  1588,  1591,
    1595,  1597,  1599,  1600,  1603,  1605,  1607,  1609,  1611,  1616,
    1618,  1620,  1623,  1625,  1629,  1631,  1634,  1638,  1640,  1645,
    1647,  1649,  1652,  1654,  1658,  1659,  1663,  1665,  1670,  1672,
    1674,  1677,  1679,  1683,  1685,  1688,  1692,  1694,  1696,  1697,
    1700,  1702,  1704,  1706,  1708,  1713,  1715,  1717,  1720,  1722,
    1726,  1728,  1731,  1733,  1735,  1737,  1739,  1741,  1745,  1746,
    1750,  1752,  1757,  1759,  1761,  1764,  1766,  1770,  1772,  1775,
    1779,  1781,  1783,  1784,  1787,  1789,  1791,  1793,  1795,  1800,
    1802,  1804,  1807,  1809,  1813,  1815,  1818,  1820,  1822,  1824,
    1826,  1828,  1832,  1835,  1837,  1840,  1842,  1845,  1847,  1850,
    1852,  1855,  1857,  1860,  1862,  1865,  1867,  1870,  1872,  1875,
    1877,  1880,  1882,  1885,  1887,  1890,  1892,  1894,  1896,  1899,
    1901,  1903,  1905,  1907,  1909,  1911,  1913,  1914
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   239,   286,   327,   409,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   191,    -1,   196,    -1,   201,    -1,   206,
      -1,   211,    -1,   216,    -1,   221,    -1,   226,    -1,   176,
     177,   181,    -1,    88,    -1,   178,    -1,   179,    -1,   178,
     179,    -1,   624,    -1,   618,    -1,   180,    -1,    24,     8,
       6,     8,    -1,   182,    -1,   183,    -1,    10,    89,    -1,
      11,    -1,    10,   184,    89,    -1,   185,    -1,   184,   185,
      -1,   186,   187,   190,    -1,   134,    -1,   188,    -1,    -1,
     188,   189,    -1,   621,    -1,   618,    -1,    10,   135,    -1,
      11,    -1,   192,   193,    -1,    96,    -1,   194,    -1,   195,
      -1,    10,    97,    -1,    11,    -1,    10,     4,    97,    -1,
     197,   198,    -1,   120,    -1,   199,    -1,   200,    -1,    10,
     121,    -1,    11,    -1,    10,     4,   121,    -1,   202,   203,
      -1,   118,    -1,   204,    -1,   205,    -1,    10,   119,    -1,
      11,    -1,    10,     4,   119,    -1,   207,   208,    -1,    92,
      -1,   209,    -1,   210,    -1,    10,    93,    -1,    11,    -1,
      10,     4,    93,    -1,   212,   213,    -1,    94,    -1,   214,
      -1,   215,    -1,    10,    95,    -1,    11,    -1,    10,     4,
      95,    -1,   217,   218,    -1,   126,    -1,   219,    -1,   220,
      -1,    10,   127,    -1,    11,    -1,    10,     4,   127,    -1,
     222,   223,    -1,   142,    -1,   224,    -1,   225,    -1,    10,
     143,    -1,    11,    -1,    10,     4,   143,    -1,   227,   228,
     229,    -1,   108,    -1,    19,   634,     6,   634,    -1,   230,
      -1,   231,    -1,    10,   109,    -1,    11,    -1,    10,   232,
     109,    -1,   233,    -1,   232,   233,    -1,   234,   235,   238,
      -1,   106,    -1,   236,    -1,    -1,   236,   237,    -1,   621,
      -1,   630,    -1,   618,    -1,    10,   107,    -1,    11,    -1,
      -1,    50,    11,    -1,    50,    10,   240,    51,    -1,    -1,
     240,   241,    -1,   242,    -1,   247,    -1,   254,    -1,   261,
      -1,   268,    -1,   273,    -1,   243,   244,    -1,   136,    -1,
     245,    -1,   246,    -1,    10,   137,    -1,    11,    -1,    10,
       4,   137,    -1,   248,   249,   252,    -1,    68,    -1,   250,
      -1,    -1,   250,   251,    -1,   627,    -1,   618,    -1,    10,
     253,    69,    -1,     6,    -1,     7,    -1,   255,   256,   259,
      -1,    70,    -1,   257,    -1,    -1,   257,   258,    -1,   627,
      -1,   618,    -1,    10,   260,    71,    -1,     6,    -1,     7,
      -1,   262,   263,   266,    -1,    66,    -1,   264,    -1,    -1,
     264,   265,    -1,   627,    -1,   618,    -1,    10,   267,    67,
      -1,     6,    -1,     7,    -1,   269,   270,   271,    -1,    64,
      -1,    -1,   618,    -1,    10,   272,    65,    -1,     6,    -1,
     274,   275,   276,    -1,   108,    -1,    19,   634,     6,   634,
      -1,   277,    -1,   278,    -1,    10,   109,    -1,    11,    -1,
      10,   279,   109,    -1,   280,    -1,   279,   280,    -1,   281,
     282,   285,    -1,   106,    -1,   283,    -1,    -1,   283,   284,
      -1,   621,    -1,   630,    -1,   618,    -1,    10,   107,    -1,
      11,    -1,    -1,    52,    11,    -1,    52,    10,   287,    53,
      -1,    -1,   287,   288,    -1,   289,    -1,   294,    -1,   299,
      -1,   304,    -1,   309,    -1,   314,    -1,   290,   291,    -1,
      82,    -1,   292,    -1,   293,    -1,    10,    83,    -1,    11,
      -1,    10,     4,    83,    -1,   295,   296,    -1,    80,    -1,
     297,    -1,   298,    -1,    10,    81,    -1,    11,    -1,    10,
       6,    81,    -1,   300,   301,    -1,   146,    -1,   302,    -1,
     303,    -1,    10,   147,    -1,    11,    -1,    10,     6,   147,
      -1,   305,   306,    -1,   140,    -1,   307,    -1,   308,    -1,
      10,   141,    -1,    11,    -1,    10,     4,   141,    -1,   310,
     311,    -1,   122,    -1,   312,    -1,   313,    -1,    10,   123,
      -1,    11,    -1,    10,   633,   123,    -1,   315,   316,   317,
      -1,   108,    -1,    19,   634,     6,   634,    -1,   318,    -1,
     319,    -1,    10,   109,    -1,    11,    -1,    10,   320,   109,
      -1,   321,    -1,   320,   321,    -1,   322,   323,   326,    -1,
     106,    -1,   324,    -1,    -1,   324,   325,    -1,   621,    -1,
     630,    -1,   618,    -1,    10,   107,    -1,    11,    -1,    -1,
      54,    11,    -1,    54,    10,   328,    55,    -1,    -1,   328,
     329,    -1,   330,    -1,   335,    -1,   340,    -1,   345,    -1,
     350,    -1,   355,    -1,   370,    -1,   377,    -1,   384,    -1,
     391,    -1,   396,    -1,   331,   332,    -1,   130,    -1,   333,
      -1,   334,    -1,    10,   131,    -1,    11,    -1,    10,     4,
     131,    -1,   336,   337,    -1,   132,    -1,   338,    -1,   339,
      -1,    10,   133,    -1,    11,    -1,    10,     4,   133,    -1,
     341,   342,    -1,   116,    -1,   343,    -1,   344,    -1,    10,
     117,    -1,    11,    -1,    10,     4,   117,    -1,   346,   347,
      -1,    62,    -1,   348,    -1,   349,    -1,    10,    63,    -1,
      11,    -1,    10,     4,    63,    -1,   351,   352,    -1,    86,
      -1,   353,    -1,   354,    -1,    10,    87,    -1,    11,    -1,
      10,     4,    87,    -1,   356,   357,   358,    -1,   144,    -1,
      25,     8,     6,     8,    -1,   359,    -1,   360,    -1,    10,
     145,    -1,    11,    -1,    10,   361,   145,    -1,   362,    -1,
     361,   362,    -1,   363,   364,   366,    -1,   138,    -1,    -1,
     364,   365,    -1,   627,    -1,   624,    -1,   615,    -1,   618,
      -1,   367,    -1,   368,    -1,    10,   139,    -1,    11,    -1,
      10,   369,   139,    -1,     7,    -1,     6,    -1,   371,   372,
     375,    -1,   152,    -1,   373,    -1,    -1,   373,   374,    -1,
     627,    -1,   618,    -1,    10,   376,   153,    -1,     6,    -1,
       7,    -1,   378,   379,   382,    -1,   154,    -1,   380,    -1,
      -1,   380,   381,    -1,   627,    -1,   618,    -1,    10,   383,
     155,    -1,     6,    -1,     7,    -1,   385,   386,   389,    -1,
     150,    -1,   387,    -1,    -1,   387,   388,    -1,   627,    -1,
     618,    -1,    10,   390,   151,    -1,     6,    -1,     7,    -1,
     392,   393,   394,    -1,   148,    -1,    -1,   618,    -1,    10,
     395,   149,    -1,     6,    -1,   397,   398,   399,    -1,   108,
      -1,    19,   634,     6,   634,    -1,   400,    -1,   401,    -1,
      10,   109,    -1,    11,    -1,    10,   402,   109,    -1,   403,
      -1,   402,   403,    -1,   404,   405,   408,    -1,   106,    -1,
     406,    -1,    -1,   406,   407,    -1,   621,    -1,   630,    -1,
     618,    -1,    10,   107,    -1,    11,    -1,    -1,   410,   411,
     418,    -1,    56,    -1,   412,    -1,    -1,   412,   413,    -1,
     414,    -1,   415,    -1,   416,    -1,   417,    -1,    22,   634,
       6,   634,    -1,    27,   634,     6,   634,    -1,    13,   634,
       6,   634,    -1,    16,   634,     6,   634,    -1,   419,    -1,
     420,    -1,    10,    57,    -1,    11,    -1,    10,   421,   594,
      57,    -1,   422,    -1,   421,   422,    -1,   423,   424,   429,
      -1,   124,    -1,   425,    -1,    -1,   425,   426,    -1,   427,
      -1,   428,    -1,    28,   634,     6,   634,    -1,    42,     3,
     634,    -1,    10,   430,   446,   451,   505,   539,   573,   125,
      -1,   431,   432,   436,    -1,   130,    -1,   433,    -1,   434,
      -1,   433,   434,    -1,   624,    -1,   618,    -1,   435,    -1,
      24,     8,     6,     8,    -1,   437,    -1,   438,    -1,    10,
     131,    -1,    11,    -1,    10,   439,   131,    -1,   440,    -1,
     439,   440,    -1,   441,   442,   445,    -1,   134,    -1,   443,
      -1,    -1,   443,   444,    -1,   624,    -1,   618,    -1,    10,
     135,    -1,    11,    -1,    -1,   447,   448,    -1,    96,    -1,
     449,    -1,   450,    -1,    10,    97,    -1,    11,    -1,    10,
       4,    97,    -1,    -1,   452,   453,   454,    -1,   162,    -1,
      -1,    21,   634,     6,   634,    -1,   455,    -1,   456,    -1,
      11,    -1,    10,   457,   468,   478,   488,   163,    -1,    -1,
     458,   459,   460,    -1,   156,    -1,    26,   634,     6,   634,
      -1,   461,    -1,   462,    -1,    10,   157,    -1,    11,    -1,
      10,   463,   157,    -1,   464,    -1,   463,   464,    -1,   465,
     466,    10,   467,   161,    -1,   160,    -1,    29,   634,     6,
     634,    -1,     6,    -1,     7,    -1,    -1,   469,   470,   471,
      -1,   158,    -1,    26,   634,     6,   634,    -1,   472,    -1,
     473,    -1,    10,   159,    -1,    11,    -1,    10,   474,   159,
      -1,   475,    -1,   474,   475,    -1,   476,   477,    10,     4,
     161,    -1,   160,    -1,    29,   634,     6,   634,    -1,    -1,
     479,   480,   481,    -1,    72,    -1,    26,   634,     6,   634,
      -1,   482,    -1,   483,    -1,    10,    73,    -1,    11,    -1,
      10,   484,    73,    -1,   485,    -1,   484,   485,    -1,   486,
     487,    10,     4,   161,    -1,   160,    -1,    29,   634,     6,
     634,    -1,    -1,   488,   489,    -1,   490,   491,   495,    -1,
     106,    -1,   492,    -1,    -1,   492,   493,    -1,   494,    -1,
     630,    -1,   621,    -1,   618,    -1,    26,   634,     6,   634,
      -1,   496,    -1,   497,    -1,    10,   107,    -1,    11,    -1,
      10,   498,   107,    -1,   499,    -1,   498,   499,    -1,   500,
     501,   502,    -1,   160,    -1,    29,   634,     6,   634,    -1,
     503,    -1,   504,    -1,    10,   161,    -1,    11,    -1,    10,
     635,   161,    -1,    -1,   506,   507,   508,    -1,   100,    -1,
      -1,    18,   634,     6,   634,    -1,   509,    -1,   510,    -1,
      11,    -1,    10,   511,   522,   101,    -1,    -1,   512,   513,
     514,    -1,   156,    -1,    15,   634,     6,   634,    -1,   515,
      -1,   516,    -1,    10,   157,    -1,    11,    -1,    10,   517,
     157,    -1,   518,    -1,   517,   518,    -1,   519,   520,    10,
     521,    99,    -1,    98,    -1,    -1,    29,   634,     6,   634,
      -1,     6,    -1,     7,    -1,    -1,   522,   523,    -1,   524,
     525,   529,    -1,   106,    -1,   526,    -1,    -1,   526,   527,
      -1,   528,    -1,   630,    -1,   621,    -1,   618,    -1,    15,
     634,     6,   634,    -1,   530,    -1,   531,    -1,    10,   107,
      -1,    11,    -1,    10,   532,   107,    -1,   533,    -1,   532,
     533,    -1,   534,   535,   536,    -1,    98,    -1,    29,   634,
       6,   634,    -1,   537,    -1,   538,    -1,    10,    99,    -1,
      11,    -1,    10,   635,    99,    -1,    -1,   540,   541,   542,
      -1,    78,    -1,    -1,    17,   634,     6,   634,    -1,   543,
      -1,   544,    -1,    11,    -1,    10,   545,   556,    79,    -1,
      -1,   546,   547,   548,    -1,    84,    -1,    12,   634,     6,
     634,    -1,   549,    -1,   550,    -1,    10,   157,    -1,    11,
      -1,    10,   551,    85,    -1,   552,    -1,   551,   552,    -1,
     553,   554,    10,   555,    77,    -1,    76,    -1,    29,   634,
       6,   634,    -1,     6,    -1,     7,    -1,    -1,   556,   557,
      -1,   558,   559,   563,    -1,   106,    -1,   560,    -1,    -1,
     560,   561,    -1,   562,    -1,   630,    -1,   621,    -1,   618,
      -1,    12,   634,     6,   634,    -1,   564,    -1,   565,    -1,
      10,   107,    -1,    11,    -1,    10,   566,   107,    -1,   567,
      -1,   566,   567,    -1,   568,   569,   570,    -1,    76,    -1,
      29,   634,     6,   634,    -1,   571,    -1,   572,    -1,    10,
      77,    -1,    11,    -1,    10,   635,    77,    -1,    -1,   574,
     575,   576,    -1,   112,    -1,    20,   634,     6,   634,    -1,
     577,    -1,   578,    -1,    10,   113,    -1,    11,    -1,    10,
     579,   113,    -1,   580,    -1,   579,   580,    -1,   581,   582,
     586,    -1,   110,    -1,   583,    -1,    -1,   583,   584,    -1,
     621,    -1,   615,    -1,   618,    -1,   585,    -1,    14,     8,
       6,     8,    -1,   587,    -1,   588,    -1,    10,   111,    -1,
      11,    -1,    10,   589,   111,    -1,   590,    -1,   589,   590,
      -1,   591,    -1,   592,    -1,   593,    -1,    60,    -1,    61,
      -1,    58,     5,    59,    -1,    -1,   595,   596,   597,    -1,
     114,    -1,    23,   634,     6,   634,    -1,   598,    -1,   599,
      -1,    10,   115,    -1,    11,    -1,    10,   600,   115,    -1,
     601,    -1,   600,   601,    -1,   602,   603,   607,    -1,   128,
      -1,   604,    -1,    -1,   604,   605,    -1,   606,    -1,   621,
      -1,   615,    -1,   618,    -1,    14,     8,     6,     8,    -1,
     608,    -1,   609,    -1,    10,   129,    -1,    11,    -1,    10,
     610,   129,    -1,   611,    -1,   610,   611,    -1,   612,    -1,
     613,    -1,   614,    -1,    60,    -1,    61,    -1,    58,     5,
      59,    -1,   616,   617,    -1,    30,    -1,     3,   634,    -1,
     634,    -1,   619,   620,    -1,    32,    -1,     3,   634,    -1,
     634,    -1,   622,   623,    -1,    34,    -1,     3,   634,    -1,
     634,    -1,   625,   626,    -1,    36,    -1,     3,   634,    -1,
     634,    -1,   628,   629,    -1,    38,    -1,     3,   634,    -1,
     634,    -1,   631,   632,    -1,    40,    -1,     3,   634,    -1,
     634,    -1,     6,    -1,     7,    -1,   637,     8,    -1,     4,
      -1,     6,    -1,     7,    -1,   165,    -1,   166,    -1,   167,
      -1,   168,    -1,    -1,   637,   636,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   162,   162,   164,   165,   167,   167,   168,   170,   170,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   184,
     186,   199,   205,   205,   208,   216,   220,   223,   234,   238,
     243,   243,   245,   247,   247,   249,   253,   260,   265,   265,
     268,   272,   277,   277,   280,   282,   288,   288,   290,   290,
     292,   295,   297,   303,   303,   305,   305,   307,   310,   312,
     318,   318,   320,   320,   322,   325,   327,   333,   333,   335,
     335,   337,   340,   342,   348,   348,   350,   350,   352,   355,
     357,   363,   363,   365,   365,   367,   370,   372,   378,   378,
     380,   380,   382,   385,   387,   393,   402,   406,   411,   411,
     413,   415,   415,   417,   421,   429,   434,   434,   437,   442,
     446,   452,   452,   456,   456,   457,   459,   459,   462,   463,
     464,   465,   466,   467,   470,   472,   478,   478,   480,   480,
     482,   485,   487,   495,   497,   497,   500,   512,   517,   520,
     521,   524,   526,   534,   536,   536,   539,   551,   556,   559,
     560,   563,   565,   573,   575,   575,   578,   594,   599,   602,
     603,   606,   608,   615,   616,   621,   624,   627,   629,   635,
     644,   648,   653,   653,   655,   657,   657,   659,   663,   671,
     676,   676,   679,   684,   688,   694,   694,   698,   698,   699,
     701,   701,   704,   705,   706,   707,   708,   709,   712,   714,
     720,   720,   722,   722,   724,   736,   738,   744,   744,   746,
     746,   748,   751,   753,   759,   759,   761,   761,   763,   766,
     768,   774,   774,   776,   776,   778,   781,   783,   789,   789,
     791,   791,   793,   796,   798,   804,   813,   817,   822,   822,
     824,   826,   826,   828,   832,   840,   845,   845,   848,   853,
     857,   863,   863,   866,   866,   867,   869,   869,   872,   873,
     874,   875,   876,   877,   878,   879,   880,   881,   882,   885,
     887,   893,   893,   895,   895,   897,   909,   911,   917,   917,
     919,   919,   921,   924,   926,   932,   932,   934,   934,   936,
     939,   941,   947,   947,   949,   949,   951,   954,   956,   962,
     962,   964,   964,   966,   969,   971,   977,   984,   988,   993,
     993,   995,   997,   997,   999,  1001,  1014,  1014,  1017,  1029,
    1035,  1045,  1048,  1048,  1050,  1050,  1052,  1063,  1064,  1067,
    1069,  1077,  1079,  1079,  1082,  1094,  1099,  1102,  1103,  1106,
    1108,  1116,  1118,  1118,  1121,  1133,  1138,  1141,  1142,  1145,
    1147,  1157,  1159,  1159,  1162,  1178,  1183,  1186,  1187,  1190,
    1192,  1200,  1201,  1206,  1209,  1213,  1215,  1221,  1230,  1234,
    1239,  1239,  1241,  1243,  1243,  1245,  1249,  1257,  1262,  1262,
    1265,  1270,  1274,  1280,  1280,  1283,  1283,  1285,  1292,  1297,
    1297,  1300,  1301,  1302,  1303,  1306,  1316,  1324,  1332,  1341,
    1345,  1350,  1350,  1352,  1354,  1354,  1356,  1358,  1366,  1368,
    1368,  1370,  1370,  1372,  1380,  1390,  1396,  1398,  1405,  1410,
    1410,  1413,  1427,  1430,  1432,  1443,  1447,  1453,  1453,  1455,
    1457,  1457,  1459,  1462,  1469,  1474,  1474,  1477,  1486,  1492,
    1492,  1495,  1495,  1497,  1499,  1499,  1501,  1501,  1503,  1508,
    1508,  1510,  1513,  1514,  1522,  1522,  1524,  1526,  1528,  1528,
    1530,  1532,  1541,  1545,  1551,  1551,  1553,  1555,  1555,  1557,
    1563,  1569,  1572,  1573,  1576,  1576,  1578,  1580,  1589,  1593,
    1599,  1599,  1601,  1603,  1603,  1605,  1612,  1618,  1621,  1621,
    1623,  1625,  1634,  1638,  1644,  1644,  1646,  1648,  1648,  1650,
    1663,  1669,  1672,  1672,  1674,  1680,  1688,  1695,  1695,  1698,
    1699,  1704,  1709,  1715,  1725,  1725,  1727,  1727,  1729,  1731,
    1731,  1733,  1738,  1740,  1745,  1745,  1747,  1747,  1749,  1754,
    1754,  1756,  1760,  1761,  1769,  1769,  1771,  1773,  1775,  1775,
    1777,  1779,  1788,  1792,  1798,  1798,  1800,  1803,  1803,  1805,
    1811,  1818,  1818,  1821,  1822,  1826,  1826,  1828,  1834,  1842,
    1850,  1850,  1853,  1854,  1859,  1864,  1870,  1880,  1880,  1882,
    1882,  1884,  1886,  1886,  1888,  1893,  1895,  1899,  1899,  1901,
    1901,  1903,  1908,  1908,  1910,  1913,  1914,  1922,  1922,  1924,
    1926,  1928,  1928,  1930,  1933,  1942,  1946,  1952,  1952,  1954,
    1956,  1956,  1958,  1964,  1970,  1973,  1974,  1977,  1977,  1979,
    1985,  1993,  2000,  2000,  2003,  2004,  2009,  2014,  2020,  2030,
    2030,  2032,  2032,  2034,  2036,  2036,  2038,  2043,  2045,  2050,
    2050,  2052,  2052,  2054,  2060,  2060,  2062,  2067,  2076,  2080,
    2085,  2085,  2087,  2089,  2089,  2091,  2095,  2104,  2111,  2111,
    2114,  2119,  2124,  2129,  2131,  2142,  2146,  2151,  2151,  2153,
    2155,  2155,  2157,  2162,  2166,  2169,  2169,  2171,  2183,  2183,
    2185,  2190,  2199,  2203,  2208,  2208,  2210,  2212,  2212,  2214,
    2218,  2227,  2234,  2234,  2237,  2238,  2242,  2246,  2252,  2262,
    2266,  2271,  2271,  2273,  2275,  2275,  2277,  2282,  2286,  2288,
    2288,  2290,  2299,  2301,  2308,  2309,  2311,  2313,  2320,  2321,
    2323,  2325,  2332,  2333,  2335,  2337,  2344,  2345,  2347,  2349,
    2356,  2357,  2359,  2361,  2368,  2369,  2373,  2374,  2376,  2379,
    2380,  2381,  2385,  2386,  2387,  2388,  2390,  2391
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
  "generalMessageEmpty", "generalMessageBody", "serviceURI",
  "serviceURIStart", "serviceURIContent", "serviceURIEmpty",
  "serviceURIBody", "serviceName", "serviceNameStart",
  "serviceNameContent", "serviceNameEmpty", "serviceNameBody",
  "instanceName", "instanceNameStart", "instanceNameContent",
  "instanceNameEmpty", "instanceNameBody", "jobID", "jobIDStart",
  "jobIDContent", "jobIDEmpty", "jobIDBody", "solverInvoked",
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
       0,   169,   170,   171,   171,   172,   172,   172,   173,   173,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   175,
     176,   177,   178,   178,   179,   179,   179,   180,   181,   181,
     182,   182,   183,   184,   184,   185,   186,   187,   188,   188,
     189,   189,   190,   190,   191,   192,   193,   193,   194,   194,
     195,   196,   197,   198,   198,   199,   199,   200,   201,   202,
     203,   203,   204,   204,   205,   206,   207,   208,   208,   209,
     209,   210,   211,   212,   213,   213,   214,   214,   215,   216,
     217,   218,   218,   219,   219,   220,   221,   222,   223,   223,
     224,   224,   225,   226,   227,   228,   229,   229,   230,   230,
     231,   232,   232,   233,   234,   235,   236,   236,   237,   237,
     237,   238,   238,   239,   239,   239,   240,   240,   241,   241,
     241,   241,   241,   241,   242,   243,   244,   244,   245,   245,
     246,   247,   248,   249,   250,   250,   251,   251,   252,   253,
     253,   254,   255,   256,   257,   257,   258,   258,   259,   260,
     260,   261,   262,   263,   264,   264,   265,   265,   266,   267,
     267,   268,   269,   270,   270,   271,   272,   273,   274,   275,
     276,   276,   277,   277,   278,   279,   279,   280,   281,   282,
     283,   283,   284,   284,   284,   285,   285,   286,   286,   286,
     287,   287,   288,   288,   288,   288,   288,   288,   289,   290,
     291,   291,   292,   292,   293,   294,   295,   296,   296,   297,
     297,   298,   299,   300,   301,   301,   302,   302,   303,   304,
     305,   306,   306,   307,   307,   308,   309,   310,   311,   311,
     312,   312,   313,   314,   315,   316,   317,   317,   318,   318,
     319,   320,   320,   321,   322,   323,   324,   324,   325,   325,
     325,   326,   326,   327,   327,   327,   328,   328,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   330,
     331,   332,   332,   333,   333,   334,   335,   336,   337,   337,
     338,   338,   339,   340,   341,   342,   342,   343,   343,   344,
     345,   346,   347,   347,   348,   348,   349,   350,   351,   352,
     352,   353,   353,   354,   355,   356,   357,   358,   358,   359,
     359,   360,   361,   361,   362,   363,   364,   364,   365,   365,
     365,   365,   366,   366,   367,   367,   368,   369,   369,   370,
     371,   372,   373,   373,   374,   374,   375,   376,   376,   377,
     378,   379,   380,   380,   381,   381,   382,   383,   383,   384,
     385,   386,   387,   387,   388,   388,   389,   390,   390,   391,
     392,   393,   393,   394,   395,   396,   397,   398,   399,   399,
     400,   400,   401,   402,   402,   403,   404,   405,   406,   406,
     407,   407,   407,   408,   408,   409,   409,   410,   411,   412,
     412,   413,   413,   413,   413,   414,   415,   416,   417,   418,
     418,   419,   419,   420,   421,   421,   422,   423,   424,   425,
     425,   426,   426,   427,   428,   429,   430,   431,   432,   433,
     433,   434,   434,   434,   435,   436,   436,   437,   437,   438,
     439,   439,   440,   441,   442,   443,   443,   444,   444,   445,
     445,   446,   446,   447,   448,   448,   449,   449,   450,   451,
     451,   452,   453,   453,   454,   454,   455,   456,   457,   457,
     458,   459,   460,   460,   461,   461,   462,   463,   463,   464,
     465,   466,   467,   467,   468,   468,   469,   470,   471,   471,
     472,   472,   473,   474,   474,   475,   476,   477,   478,   478,
     479,   480,   481,   481,   482,   482,   483,   484,   484,   485,
     486,   487,   488,   488,   489,   490,   491,   492,   492,   493,
     493,   493,   493,   494,   495,   495,   496,   496,   497,   498,
     498,   499,   500,   501,   502,   502,   503,   503,   504,   505,
     505,   506,   507,   507,   508,   508,   509,   510,   511,   511,
     512,   513,   514,   514,   515,   515,   516,   517,   517,   518,
     519,   520,   520,   521,   521,   522,   522,   523,   524,   525,
     526,   526,   527,   527,   527,   527,   528,   529,   529,   530,
     530,   531,   532,   532,   533,   534,   535,   536,   536,   537,
     537,   538,   539,   539,   540,   541,   541,   542,   542,   543,
     544,   545,   545,   546,   547,   548,   548,   549,   549,   550,
     551,   551,   552,   553,   554,   555,   555,   556,   556,   557,
     558,   559,   560,   560,   561,   561,   561,   561,   562,   563,
     563,   564,   564,   565,   566,   566,   567,   568,   569,   570,
     570,   571,   571,   572,   573,   573,   574,   575,   576,   576,
     577,   577,   578,   579,   579,   580,   581,   582,   583,   583,
     584,   584,   584,   584,   585,   586,   586,   587,   587,   588,
     589,   589,   590,   591,   591,   592,   592,   593,   594,   594,
     595,   596,   597,   597,   598,   598,   599,   600,   600,   601,
     602,   603,   604,   604,   605,   605,   605,   605,   606,   607,
     607,   608,   608,   609,   610,   610,   611,   612,   612,   613,
     613,   614,   615,   616,   617,   617,   618,   619,   620,   620,
     621,   622,   623,   623,   624,   625,   626,   626,   627,   628,
     629,   629,   630,   631,   632,   632,   633,   633,   634,   635,
     635,   635,   636,   636,   636,   636,   637,   637
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     3,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     4,     1,     1,
       2,     1,     3,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     2,     1,     2,     1,     1,     1,     2,     1,
       3,     2,     1,     1,     1,     2,     1,     3,     2,     1,
       1,     1,     2,     1,     3,     2,     1,     1,     1,     2,
       1,     3,     2,     1,     1,     1,     2,     1,     3,     2,
       1,     1,     1,     2,     1,     3,     2,     1,     1,     1,
       2,     1,     3,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     2,     1,     0,     2,     4,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     1,
       3,     3,     1,     1,     0,     2,     1,     1,     3,     1,
       1,     3,     1,     1,     0,     2,     1,     1,     3,     1,
       1,     3,     1,     1,     0,     2,     1,     1,     3,     1,
       1,     3,     1,     0,     1,     3,     1,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     4,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     2,     1,     3,     2,     1,     1,     1,     2,
       1,     3,     2,     1,     1,     1,     2,     1,     3,     2,
       1,     1,     1,     2,     1,     3,     2,     1,     1,     1,
       2,     1,     3,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     2,     1,     0,     2,     4,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     2,     1,     3,     2,     1,     1,     1,
       2,     1,     3,     2,     1,     1,     1,     2,     1,     3,
       2,     1,     1,     1,     2,     1,     3,     2,     1,     1,
       1,     2,     1,     3,     3,     1,     4,     1,     1,     2,
       1,     3,     1,     2,     3,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     3,
       1,     1,     0,     2,     1,     1,     3,     1,     1,     3,
       1,     1,     0,     2,     1,     1,     3,     1,     1,     3,
       1,     1,     0,     2,     1,     1,     3,     1,     1,     3,
       1,     0,     1,     3,     1,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     4,     4,     4,     4,     1,
       1,     2,     1,     4,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     4,     3,     8,     3,     1,     1,     1,
       2,     1,     1,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     2,
       1,     0,     2,     1,     1,     1,     2,     1,     3,     0,
       3,     1,     0,     4,     1,     1,     1,     6,     0,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     5,
       1,     4,     1,     1,     0,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     2,     5,     1,     4,     0,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     5,
       1,     4,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     4,     1,     1,     2,     1,     3,     1,
       2,     3,     1,     4,     1,     1,     2,     1,     3,     0,
       3,     1,     0,     4,     1,     1,     1,     4,     0,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     5,
       1,     0,     4,     1,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     4,     1,     1,     2,
       1,     3,     1,     2,     3,     1,     4,     1,     1,     2,
       1,     3,     0,     3,     1,     0,     4,     1,     1,     1,
       4,     0,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     5,     1,     4,     1,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     4,     1,
       1,     2,     1,     3,     1,     2,     3,     1,     4,     1,
       1,     2,     1,     3,     0,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     1,     1,     3,     0,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     4,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     3,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,   113,     4,
       8,     6,     0,   187,     0,   116,   114,     0,   253,     7,
      20,    66,    73,    45,    94,    59,    52,    80,    87,     9,
      10,     0,    11,     0,    12,     0,    13,     0,    14,     0,
      15,     0,    16,     0,    17,     0,    18,     0,     0,   190,
     188,     0,   385,     0,   707,   715,     0,    21,    22,    26,
      25,   736,    24,   736,     0,    49,    44,    46,    47,     0,
      56,    51,    53,    54,     0,    63,    58,    60,    61,     0,
      70,    65,    67,    68,     0,    77,    72,    74,    75,     0,
      84,    79,    81,    82,     0,    91,    86,    88,    89,   736,
       0,   115,   162,   152,   132,   142,   168,   125,   117,   118,
       0,   119,   134,   120,   144,   121,   154,   122,   163,   123,
       0,     0,   256,   254,   387,     0,   389,     0,     0,    31,
      19,    28,    29,    23,   736,   706,   709,     0,   736,   714,
     717,     0,    48,     0,    55,     0,    62,     0,    69,     0,
      76,     0,    83,     0,    90,     0,     0,    99,    93,    96,
      97,     0,   129,   124,   126,   127,     0,   133,     0,   143,
       0,   153,     0,   164,   736,     0,   189,   206,   199,   234,
     227,   220,   213,   191,   192,     0,   193,     0,   194,     0,
     195,     0,   196,     0,   197,     0,     0,     2,     0,   388,
       0,    30,    36,     0,    33,    38,   708,   728,   732,   733,
     734,   735,   737,   716,    50,    57,    64,    71,    78,    85,
      92,   736,   104,    98,     0,   101,   106,     0,   128,     0,
     131,   719,   135,   137,   136,   736,     0,   141,   145,   147,
     146,     0,   151,   155,   157,   156,     0,   161,     0,     0,
     173,   167,   170,   171,     0,   203,   198,   200,   201,     0,
     210,   205,   207,   208,     0,   217,   212,   214,   215,     0,
     224,   219,   221,   222,     0,   231,   226,   228,   229,   736,
       0,   255,   291,   298,   366,   284,   270,   277,   305,   360,
     350,   330,   340,   257,   258,     0,   259,     0,   260,     0,
     261,     0,   262,     0,   263,     0,   264,   332,   265,   342,
     266,   352,   267,   361,   268,     0,     0,   402,   386,   399,
     400,   736,   736,   736,   736,   390,   391,   392,   393,   394,
      27,    32,    34,     0,    37,    95,   100,   102,     0,   105,
     130,   139,   140,     0,   736,   718,   721,   149,   150,     0,
     159,   160,     0,   166,     0,   736,   178,   172,     0,   175,
     180,     0,   202,     0,   209,     0,   216,     0,   223,   726,
     727,   230,     0,     0,     0,   239,   233,   236,   237,     0,
     274,   269,   271,   272,     0,   281,   276,   278,   279,     0,
     288,   283,   285,   286,     0,   295,   290,   292,   293,     0,
     302,   297,   299,   300,     0,     0,     0,   331,     0,   341,
       0,   351,     0,   362,   736,     0,   401,   407,   668,   404,
     409,     0,     0,     0,     0,     0,    43,    35,   711,    39,
      41,    40,   736,     0,   112,   103,   723,   107,   110,   108,
     109,   736,   138,   720,   148,   158,   165,   169,   174,   176,
       0,   179,   204,   211,   218,   225,   232,   736,   244,   238,
       0,   241,   246,     0,   273,     0,   280,     0,   287,     0,
     294,     0,   301,     0,     0,   310,   304,   307,   308,     0,
     329,   333,   335,   334,     0,   339,   343,   345,   344,     0,
     349,   353,   355,   354,     0,   359,     0,     0,   371,   365,
     368,   369,   670,   405,     0,     0,     0,   408,   736,   736,
     736,   736,    42,   736,   710,   713,   111,   736,   722,   725,
       0,   186,   177,   181,   184,   182,   183,   235,   240,   242,
       0,   245,   275,   282,   289,   296,   303,     0,   315,   309,
       0,   312,   316,   337,   338,     0,   347,   348,     0,   357,
     358,     0,   364,     0,   736,   376,   370,     0,   373,   378,
     403,   736,     0,     0,   406,   736,     0,   410,   411,   412,
     397,   398,   395,   396,   712,   724,   185,     0,   252,   243,
     247,   250,   248,   249,   306,   311,   313,     0,   336,   346,
     356,   363,   367,   372,   374,     0,   377,     0,     0,   675,
     669,   672,   673,   417,   441,     0,     0,   736,   251,     0,
     325,   703,   317,   314,   322,   323,   320,   736,   321,   319,
     318,     0,   384,   375,   379,   382,   380,   381,   736,   674,
     680,     0,   677,   682,   443,   449,     0,     0,     0,   418,
     419,   423,   422,   421,   736,   414,   328,   327,   324,     0,
     736,   702,   705,   383,   671,   676,   678,     0,   681,   451,
     529,   452,     0,   447,   442,   444,   445,     0,     0,   428,
     416,   425,   426,   420,   413,   326,   704,     0,   692,   679,
     689,   690,     0,   683,   684,   686,   687,   685,   531,   582,
     532,   736,     0,     0,   446,     0,   427,   433,     0,   430,
     435,     0,   699,   700,   691,     0,   694,   696,   697,   698,
       0,   584,   634,   585,   736,     0,     0,   458,   456,   450,
     454,   455,   448,   424,   429,   431,     0,   434,     0,   693,
     695,     0,   636,     0,     0,   736,     0,     0,   538,   536,
     530,   534,   535,   736,   460,   474,     0,     0,   440,   432,
     436,   438,   437,   701,   688,   415,   736,     0,     0,   591,
     589,   583,   587,   588,   736,   540,   555,     0,   453,   476,
     488,     0,   736,     0,   439,     0,     0,   641,   635,   638,
     639,   736,   593,   607,     0,   533,     0,   736,     0,   490,
     502,     0,   736,     0,     0,     0,   465,   459,   462,   463,
     736,   646,   640,     0,   643,   648,   586,     0,   736,     0,
     537,   558,   556,   560,     0,     0,   545,   539,   542,   543,
       0,   736,     0,     0,     0,   481,   475,   478,   479,   736,
     464,   470,     0,   467,     0,   637,   642,   644,     0,   647,
     590,   610,   608,   612,     0,     0,   598,   592,   595,   596,
       0,   559,   736,   550,   544,     0,   547,   551,   505,   457,
     503,   507,     0,     0,   495,   489,   492,   493,   736,   480,
     486,     0,   483,     0,   461,   466,   468,   736,     0,     0,
     658,   645,   655,   656,     0,   649,   653,   651,   652,   650,
       0,   611,   736,   603,   597,     0,   600,     0,     0,   570,
     557,   567,   568,   736,   561,   562,   565,   564,   563,   541,
     546,   548,   736,     0,     0,   506,   736,   494,   500,     0,
     497,     0,   477,   482,   484,   736,     0,     0,     0,     0,
     665,   666,   657,     0,   660,   662,   663,   664,     0,     0,
     622,   609,   619,   620,   736,   613,   614,   617,   616,   615,
     594,   599,   601,   736,     0,   575,   569,     0,   572,     0,
       0,     0,     0,     0,   517,   504,   514,   515,   736,   508,
     509,   512,   511,   510,   491,   496,   498,   736,     0,     0,
       0,   736,   472,   473,     0,     0,   659,   661,     0,   627,
     621,     0,   624,     0,     0,     0,     0,   571,   573,   736,
       0,   736,   736,   553,   554,     0,   516,   522,     0,   519,
       0,     0,     0,     0,   736,     0,   471,   469,   667,   654,
     623,   625,   736,     0,   736,   736,   605,   606,     0,     0,
       0,   580,   574,   577,   578,   566,   552,   549,   518,   520,
     736,     0,   736,   736,     0,   487,   485,     0,     0,   632,
     626,   629,   630,   618,   604,   602,   736,   729,   730,   731,
     579,     0,     0,     0,   527,   521,   524,   525,   513,   501,
     499,   736,   631,     0,   576,   581,   736,   526,     0,   628,
     633,   523,   528
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    31,    56,    57,
      58,    59,   130,   131,   132,   203,   204,   205,   333,   334,
     429,   427,    32,    33,    66,    67,    68,    34,    35,    71,
      72,    73,    36,    37,    76,    77,    78,    38,    39,    81,
      82,    83,    40,    41,    86,    87,    88,    42,    43,    91,
      92,    93,    44,    45,    96,    97,    98,    46,    47,   100,
     158,   159,   160,   224,   225,   226,   338,   339,   437,   435,
      13,    48,   108,   109,   110,   163,   164,   165,   111,   112,
     166,   167,   232,   230,   343,   113,   114,   168,   169,   238,
     237,   349,   115,   116,   170,   171,   243,   242,   352,   117,
     118,   172,   247,   354,   119,   120,   175,   251,   252,   253,
     358,   359,   360,   450,   451,   523,   522,    18,   121,   183,
     184,   185,   256,   257,   258,   186,   187,   261,   262,   263,
     188,   189,   266,   267,   268,   190,   191,   271,   272,   273,
     192,   193,   276,   277,   278,   194,   195,   280,   376,   377,
     378,   460,   461,   462,   530,   531,   580,   579,    52,   196,
     293,   294,   295,   381,   382,   383,   296,   297,   386,   387,
     388,   298,   299,   391,   392,   393,   300,   301,   396,   397,
     398,   302,   303,   401,   402,   403,   304,   305,   405,   476,
     477,   478,   540,   541,   542,   587,   612,   613,   614,   615,
     649,   306,   307,   406,   407,   481,   480,   545,   308,   309,
     408,   409,   486,   485,   548,   310,   311,   410,   411,   491,
     490,   551,   312,   313,   412,   495,   553,   314,   315,   415,
     499,   500,   501,   557,   558,   559,   595,   596,   624,   623,
     125,   126,   198,   199,   325,   326,   327,   328,   329,   318,
     319,   320,   418,   419,   420,   506,   507,   567,   568,   569,
     564,   604,   605,   638,   639,   640,   641,   670,   671,   672,
     698,   699,   700,   726,   727,   750,   749,   635,   636,   664,
     665,   666,   660,   661,   692,   719,   720,   721,   745,   746,
     773,   797,   798,   799,   832,   833,   834,   878,   984,   770,
     771,   793,   826,   827,   828,   871,   872,   873,   926,   790,
     791,   822,   865,   866,   867,   919,   920,   921,   978,   820,
     860,   861,   914,   915,   969,   970,   965,   966,   967,  1008,
    1009,  1010,  1041,  1065,  1066,  1067,   689,   690,   715,   740,
     741,   742,   766,   767,   788,   817,   818,   819,   855,   856,
     857,   913,  1005,   786,   812,   813,   850,   851,   904,   905,
     900,   901,   902,   957,   958,   959,  1000,  1032,  1033,  1034,
     712,   713,   736,   761,   762,   763,   783,   784,   809,   847,
     848,   849,   895,   896,   897,   954,  1028,   807,   842,   843,
     890,   891,   945,   946,   941,   942,   943,   991,   992,   993,
    1023,  1050,  1051,  1052,   733,   734,   757,   778,   779,   780,
     803,   804,   805,   838,   839,   885,   886,   881,   882,   883,
     933,   934,   935,   936,   937,   504,   505,   562,   600,   601,
     602,   631,   632,   633,   657,   658,   683,   684,   679,   680,
     681,   705,   706,   707,   708,   709,   616,   617,   651,    60,
      61,   135,   431,   432,   514,    62,    63,   139,   234,   235,
     345,   440,   441,   518,   372,   136,  1061,   212,   137
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -990
static const yytype_int16 yypact[] =
{
      41,    62,    70,    46,  -990,   102,  -990,   278,    73,  -990,
    -990,  -990,   286,   142,    -5,  -990,  -990,   288,    77,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   156,  -990,   290,  -990,   292,  -990,   294,  -990,   296,
    -990,   298,  -990,   300,  -990,   302,  -990,   203,   111,  -990,
    -990,   304,   104,   219,  -990,  -990,   306,   156,  -990,  -990,
    -990,   252,  -990,   254,    31,  -990,  -990,  -990,  -990,    19,
    -990,  -990,  -990,  -990,    22,  -990,  -990,  -990,  -990,    21,
    -990,  -990,  -990,  -990,    34,  -990,  -990,  -990,  -990,    16,
    -990,  -990,  -990,  -990,     5,  -990,  -990,  -990,  -990,  -990,
     308,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
     310,  -990,  -990,  -990,  -990,  -990,  -990,  -990,   230,  -990,
     259,   -13,  -990,  -990,  -990,   243,  -990,   340,   -35,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,    -1,  -990,  -990,
    -990,   197,  -990,   213,  -990,   249,  -990,   231,  -990,   319,
    -990,   266,  -990,   277,  -990,   430,   143,  -990,  -990,  -990,
    -990,     8,  -990,  -990,  -990,  -990,   434,   131,   439,   131,
     441,   131,   442,  -990,  -990,   312,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,   316,  -990,   318,  -990,   320,
    -990,   322,  -990,   326,  -990,   436,   -28,  -990,   328,   174,
     445,  -990,  -990,   -33,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,   145,  -990,  -990,   321,  -990,   334,
    -990,  -990,  -990,  -990,  -990,   453,   336,  -990,  -990,  -990,
    -990,   338,  -990,  -990,  -990,  -990,   451,  -990,   454,   147,
    -990,  -990,  -990,  -990,    27,  -990,  -990,  -990,  -990,    36,
    -990,  -990,  -990,  -990,     2,  -990,  -990,  -990,  -990,    11,
    -990,  -990,  -990,  -990,    15,  -990,  -990,  -990,  -990,  -990,
     337,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,   339,  -990,   342,  -990,   344,
    -990,   346,  -990,   348,  -990,   437,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,   230,  -990,   440,   -18,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,   350,   205,  -990,  -990,  -990,   352,   204,
    -990,  -990,  -990,   395,  -990,  -990,  -990,  -990,  -990,   390,
    -990,  -990,   399,  -990,   403,  -990,  -990,  -990,   158,  -990,
    -990,   380,  -990,   386,  -990,   323,  -990,   331,  -990,  -990,
    -990,  -990,   351,   463,   159,  -990,  -990,  -990,  -990,    13,
    -990,  -990,  -990,  -990,    20,  -990,  -990,  -990,  -990,    25,
    -990,  -990,  -990,  -990,    37,  -990,  -990,  -990,  -990,    45,
    -990,  -990,  -990,  -990,   465,   354,   466,   131,   467,   131,
     468,   131,   469,  -990,  -990,   356,  -990,  -990,    81,  -990,
    -990,   475,   476,   477,   478,   353,  -990,  -990,  -990,  -990,
    -990,  -990,   472,   378,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   483,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
     360,   204,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
     160,  -990,  -990,   359,  -990,   361,  -990,   376,  -990,   433,
    -990,   405,  -990,   481,    55,  -990,  -990,  -990,  -990,   366,
    -990,  -990,  -990,  -990,   368,  -990,  -990,  -990,  -990,   370,
    -990,  -990,  -990,  -990,   489,  -990,   491,   164,  -990,  -990,
    -990,  -990,  -990,  -990,   443,   480,   494,    40,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
     401,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
     369,   204,  -990,  -990,  -990,  -990,  -990,   493,  -990,  -990,
      76,  -990,  -990,  -990,  -990,   357,  -990,  -990,   358,  -990,
    -990,   363,  -990,   362,  -990,  -990,  -990,   165,  -990,  -990,
    -990,  -990,   371,   382,  -990,  -990,   496,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,   409,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,   172,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,   373,   204,   499,   -51,  -990,
    -990,  -990,  -990,  -990,   411,   167,   503,  -990,  -990,    12,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,   512,  -990,  -990,
    -990,   410,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   -42,  -990,  -990,  -990,   364,   375,   511,   377,   167,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,   383,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,   379,   198,  -990,
     420,   500,    33,  -990,  -990,  -990,  -990,   518,   141,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,    18,  -990,  -990,
    -990,  -990,   517,  -990,  -990,  -990,  -990,  -990,  -990,   449,
     510,  -990,   381,   435,  -990,   521,  -990,  -990,   146,  -990,
    -990,   525,  -990,  -990,  -990,    32,  -990,  -990,  -990,  -990,
     527,  -990,   419,   519,  -990,   385,   528,   384,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,   387,   214,   479,  -990,
    -990,   529,  -990,   414,   515,  -990,   389,   535,   391,  -990,
    -990,  -990,  -990,  -990,  -990,   388,   522,   415,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,   392,   537,   461,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,   534,  -990,  -990,
     484,   526,  -990,   394,  -990,   545,   166,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,   541,  -990,   119,  -990,   396,  -990,
    -990,   531,  -990,   398,   549,   125,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,   173,  -990,  -990,  -990,   -22,  -990,   400,
    -990,  -990,  -990,  -990,   553,   -52,  -990,  -990,  -990,  -990,
     -56,  -990,   402,   554,   257,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,   127,  -990,   532,  -990,  -990,  -990,   408,   199,
    -990,  -990,  -990,  -990,   556,   -60,  -990,  -990,  -990,  -990,
     412,   144,  -990,  -990,  -990,   -38,  -990,   538,  -990,  -990,
    -990,  -990,   557,   -26,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   265,  -990,   539,  -990,  -990,  -990,  -990,   559,    96,
    -990,  -990,  -990,  -990,   558,  -990,  -990,  -990,  -990,  -990,
     416,   177,  -990,  -990,  -990,   -24,  -990,   542,   108,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,   560,   418,   208,  -990,  -990,  -990,   -25,
    -990,   543,  -990,  -990,  -990,  -990,   563,   568,   424,   570,
    -990,  -990,  -990,   113,  -990,  -990,  -990,  -990,   571,    63,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,   566,  -990,  -990,   128,  -990,   550,
     572,   574,   426,   -64,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,   573,   578,
     581,  -990,  -990,  -990,   425,   505,  -990,  -990,   580,  -990,
    -990,    79,  -990,   561,   583,   585,   428,  -990,  -990,  -990,
     427,  -990,  -990,  -990,  -990,   495,  -990,  -990,   -62,  -990,
     564,   586,   589,   592,  -990,   438,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,   429,  -990,  -990,  -990,  -990,   520,   594,
      26,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   432,  -990,  -990,   444,  -990,  -990,   595,    59,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   504,   596,     7,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,   530,  -990,  -990,  -990,  -990,   447,  -990,
    -990,  -990,  -990
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
     547,  -990,  -990,  -990,  -990,  -990,   406,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,   374,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,   248,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,   150,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,    72,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,    56,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,   196,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,   -23,  -990,  -990,  -990,  -990,
    -990,   -83,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -215,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -253,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -300,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -388,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -234,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -335,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -272,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -367,  -990,
    -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -178,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -307,  -990,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,    -4,  -990,  -990,  -990,  -990,  -990,  -990,  -990,
    -990,  -990,   -76,  -990,  -990,  -990,  -654,  -990,  -990,  -116,
    -990,  -990,  -333,  -990,  -990,  -577,  -990,  -990,  -166,  -990,
    -990,  -450,  -990,  -990,  -990,   -63,  -989,  -990,  -990
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     140,   526,   173,   240,   685,   245,   439,   207,   365,   153,
     619,  1057,   227,  1058,  1059,   367,   893,   463,   646,   647,
     151,   369,   370,   143,   465,   147,   145,   281,   643,   467,
    1057,   361,  1058,  1059,   282,   141,   155,   693,   149,   416,
     176,   469,   363,  1006,    19,  1038,   853,   917,   975,   471,
     858,   233,   893,   239,   201,   244,   331,   840,   283,  1073,
     853,   951,   643,  1057,   629,  1058,  1059,   177,   565,   178,
       6,   206,     4,   655,  1078,   213,   701,   630,   702,   703,
     284,   583,   566,    20,   841,     1,   630,    21,   285,    22,
     701,    23,   702,   703,     7,   179,  1007,   894,  1007,   202,
     470,   202,   286,    24,   287,   854,   417,   859,     5,   180,
     362,   248,     9,    25,   148,    26,   288,   364,   525,   910,
     289,    27,   290,    12,   291,  1060,   292,   181,   142,   150,
     694,    51,   472,   182,   918,   918,  1072,    28,   371,   989,
     144,   146,   468,   152,   464,   228,   627,   704,   154,   366,
     752,   648,   368,   466,   929,   989,   930,   931,   335,   903,
     124,   729,   101,    54,   208,   209,   210,   211,  1077,   231,
     990,   929,   346,   930,   931,   102,    54,   103,   428,   104,
      53,   105,   609,   610,   436,   887,  1020,   321,    54,   944,
     322,   637,    55,   538,    17,   502,   323,   413,   582,    54,
     539,   324,   611,    55,    54,   417,   955,   932,    55,    54,
     231,   428,   682,   884,   538,   956,   373,   436,   430,   106,
     810,   585,    99,   438,   986,   811,   955,   127,   611,   611,
      54,    54,   428,   428,   968,   997,    54,    54,   428,   428,
      54,   483,   428,   488,   436,   493,    54,   107,   436,   222,
      55,   222,   223,   356,   336,   134,   357,   138,   421,   422,
     423,   424,    54,   626,   356,   458,   458,   448,   459,   528,
     555,   555,   696,   556,   593,   697,   801,   724,   174,   802,
     697,   443,   830,   801,   875,   831,   836,   831,    10,    11,
     197,   482,   447,   487,   214,   492,    15,    16,    49,    50,
      64,    65,    69,    70,    74,    75,    79,    80,    84,    85,
      89,    90,    94,    95,   122,   123,   128,   129,   156,   157,
     161,   162,   249,   250,   217,   687,   254,   255,   259,   260,
     264,   265,   269,   270,   215,   524,   274,   275,   316,   317,
     341,   342,   347,   348,   350,   351,   200,   374,   375,   379,
     380,   496,   384,   385,   389,   390,   394,   395,   399,   400,
     425,   426,   433,   434,   474,   475,   497,   498,   216,   515,
     520,   521,   543,   544,   546,   547,   549,   550,   519,   577,
     578,   598,   599,   621,   622,   662,   663,   668,   669,   677,
     678,   717,   718,   219,   527,   738,   739,   747,   748,   759,
     760,   908,   776,   777,   795,   796,   815,   816,   824,   825,
     845,   846,   863,   864,   218,   581,   869,   870,   879,   880,
     220,   620,   898,   899,   923,   870,   939,   940,   963,   964,
     982,   983,  1003,  1004,  1026,  1027,   221,  1030,  1031,  1048,
    1049,   949,  1063,  1064,   229,   570,   571,   572,   573,   236,
     574,   241,   246,   330,   575,   279,   344,   353,   340,   414,
     355,   444,   404,   452,   442,   973,   445,   453,   446,   457,
     454,   618,   455,   473,   456,   513,   479,   484,   489,   494,
     625,   508,   509,   510,   511,   516,   517,   537,   512,   642,
     532,   592,   536,   534,   533,   552,   535,   554,   597,   607,
     560,   584,   606,   561,   563,   628,   889,   634,   576,   644,
     588,   591,   603,   589,   590,   650,   608,   653,   907,   667,
     688,   691,   675,   642,   695,   710,   659,   711,   714,   723,
     728,   732,   722,   731,   743,   756,   735,   754,   753,   755,
     744,   764,   686,   781,   645,   782,   769,   765,   772,   787,
     774,   800,   792,   808,   652,   829,   789,   821,   948,   852,
     868,   877,   892,   916,  1018,   654,   938,   912,   925,   928,
     962,   953,   977,   980,   981,   985,   996,   988,  1001,   999,
    1002,   674,   972,  1013,  1014,  1015,  1017,   676,  1019,  1024,
    1022,  1025,  1042,  1040,  1037,  1043,  1044,  1055,   337,  1046,
    1056,  1071,  1076,  1075,   133,  1070,   449,  1080,  1082,   332,
     529,   751,   586,   594,   503,   725,   673,   876,   924,   976,
    1039,   911,   998,   952,  1021,   837,   987,   656,   716,   730,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   737,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   758,     0,     0,     0,     0,     0,     0,     0,
     768,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   775,     0,     0,     0,     0,     0,     0,
       0,   785,     0,     0,     0,     0,     0,     0,     0,   794,
       0,     0,     0,     0,     0,     0,     0,     0,   806,     0,
       0,     0,     0,   888,   814,     0,     0,     0,     0,   823,
       0,     0,     0,     0,     0,   906,     0,   835,     0,     0,
       0,     0,     0,     0,     0,   844,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   862,     0,
       0,     0,     0,     0,     0,     0,   874,     0,     0,     0,
       0,     0,     0,     0,     0,   947,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   909,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   971,
       0,     0,     0,     0,     0,   922,     0,     0,     0,     0,
       0,     0,     0,     0,   927,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   950,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     960,     0,     0,     0,     0,     0,     0,     0,     0,   961,
       0,     0,     0,   974,     0,     0,     0,     0,     0,     0,
       0,     0,   979,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   994,     0,     0,     0,     0,     0,     0,     0,     0,
     995,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1011,     0,     0,     0,     0,
       0,     0,     0,     0,  1012,     0,     0,     0,  1016,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1029,     0,  1035,  1036,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1045,     0,     0,     0,     0,     0,     0,     0,  1047,
       0,  1053,  1054,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1062,     0,  1068,
    1069,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1074,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1079,     0,
       0,     0,     0,  1081
};

static const yytype_int16 yycheck[] =
{
      63,   451,   118,   169,   658,   171,   339,     8,     6,     4,
     587,     4,     4,     6,     7,     4,    76,     4,     6,     7,
       4,     6,     7,     4,     4,     4,     4,    55,   605,     4,
       4,     4,     6,     7,    62,     4,    99,     4,     4,    57,
      53,     4,     6,   107,    49,   107,    98,    73,    73,     4,
     106,   167,    76,   169,    89,   171,    89,    79,    86,  1048,
      98,    85,   639,     4,   115,     6,     7,    80,    28,    82,
       0,   134,    10,   115,  1063,   138,    58,   128,    60,    61,
     108,   531,    42,    88,   106,    44,   128,    92,   116,    94,
      58,    96,    60,    61,    48,   108,   160,   157,   160,   134,
      63,   134,   130,   108,   132,   157,   124,   163,    46,   122,
      83,   174,    10,   118,    93,   120,   144,    81,   451,   157,
     148,   126,   150,    50,   152,    99,   154,   140,    97,    95,
      97,    54,    87,   146,   160,   160,    77,   142,   123,    76,
     121,   119,   117,   127,   131,   137,   596,   129,   143,   147,
     727,   139,   141,   133,    58,    76,    60,    61,   221,    15,
      56,   129,    51,    32,   165,   166,   167,   168,   161,    38,
     107,    58,   235,    60,    61,    64,    32,    66,    34,    68,
      24,    70,    10,    11,    40,   839,   107,    13,    32,    12,
      16,    24,    36,   138,    52,   114,    22,   313,   531,    32,
     145,    27,    30,    36,    32,   124,    98,   111,    36,    32,
      38,    34,    14,    14,   138,   107,   279,    40,   334,   108,
     101,   145,    19,   339,   111,   106,    98,     8,    30,    30,
      32,    32,    34,    34,    26,   107,    32,    32,    34,    34,
      32,   407,    34,   409,    40,   411,    32,   136,    40,   106,
      36,   106,   109,   106,   109,     3,   109,     3,   321,   322,
     323,   324,    32,   596,   106,   106,   106,   109,   109,   109,
     106,   106,   131,   109,   109,   134,   110,   131,    19,   113,
     134,   344,   157,   110,   157,   160,   113,   160,    10,    11,
      47,   407,   355,   409,    97,   411,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    93,   658,    10,    11,    10,    11,
      10,    11,    10,    11,   121,   451,    10,    11,    10,    11,
       6,     7,     6,     7,     6,     7,     6,    10,    11,    10,
      11,   414,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,   119,   432,
      10,    11,     6,     7,     6,     7,     6,     7,   441,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   127,   457,    10,    11,    10,    11,    10,
      11,   851,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    95,   531,   159,   160,    10,    11,
     143,   587,    10,    11,   159,   160,    10,    11,    10,    11,
       6,     7,     6,     7,     6,     7,     6,    10,    11,    10,
      11,   891,    10,    11,    10,   508,   509,   510,   511,    10,
     513,    10,    10,     8,   517,    19,     3,     6,   137,    19,
       6,    71,    25,    83,    69,   915,    67,    81,    65,     6,
     147,   587,   141,     8,   123,     3,    10,    10,    10,    10,
     596,     6,     6,     6,     6,   107,     3,     6,   135,   605,
     131,   554,    87,   117,   133,     6,    63,     6,   561,     3,
      57,     8,   565,    23,    10,     6,   839,    96,   107,     6,
     153,   149,   130,   155,   151,     3,   107,   107,   851,     8,
     100,    21,   139,   639,     6,     8,   162,    78,    18,     8,
       5,   112,    97,     6,     6,    20,    17,     8,    59,   125,
     156,     6,   658,     6,   607,    84,   158,   156,    26,    15,
     135,     6,    26,    12,   617,     6,    72,    26,   891,     6,
       6,    29,     6,     6,    59,   628,     8,    29,    29,    10,
      10,    29,    29,    10,     6,     5,    10,     6,     6,    29,
       6,   644,   915,    10,     6,     4,   161,   650,     8,     6,
      29,     6,     6,    29,    99,     6,     4,    77,   224,   161,
       6,     6,     6,    99,    57,   161,   358,    77,   161,   203,
     460,   727,   540,   557,   418,   698,   639,   832,   871,   919,
    1008,   855,   957,   895,   991,   803,   933,   631,   691,   705,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   714,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   735,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     743,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   756,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   764,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   772,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   781,    -1,
      -1,    -1,    -1,   839,   787,    -1,    -1,    -1,    -1,   792,
      -1,    -1,    -1,    -1,    -1,   851,    -1,   800,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   808,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   821,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   829,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   891,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   852,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   915,
      -1,    -1,    -1,    -1,    -1,   868,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   877,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   892,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     903,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   912,
      -1,    -1,    -1,   916,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   925,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   944,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     953,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   968,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   977,    -1,    -1,    -1,   981,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   999,    -1,  1001,  1002,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1014,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1022,
      -1,  1024,  1025,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1040,    -1,  1042,
    1043,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1056,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1071,    -1,
      -1,    -1,    -1,  1076
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   239,   173,    10,    11,    52,   286,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   176,   191,   192,   196,   197,   201,   202,   206,   207,
     211,   212,   216,   217,   221,   222,   226,   227,   240,    10,
      11,    54,   327,    24,    32,    36,   177,   178,   179,   180,
     618,   619,   624,   625,    10,    11,   193,   194,   195,    10,
      11,   198,   199,   200,    10,    11,   203,   204,   205,    10,
      11,   208,   209,   210,    10,    11,   213,   214,   215,    10,
      11,   218,   219,   220,    10,    11,   223,   224,   225,    19,
     228,    51,    64,    66,    68,    70,   108,   136,   241,   242,
     243,   247,   248,   254,   255,   261,   262,   268,   269,   273,
     274,   287,    10,    11,    56,   409,   410,     8,    10,    11,
     181,   182,   183,   179,     3,   620,   634,   637,     3,   626,
     634,     4,    97,     4,   121,     4,   119,     4,    93,     4,
      95,     4,   127,     4,   143,   634,    10,    11,   229,   230,
     231,    10,    11,   244,   245,   246,   249,   250,   256,   257,
     263,   264,   270,   618,    19,   275,    53,    80,    82,   108,
     122,   140,   146,   288,   289,   290,   294,   295,   299,   300,
     304,   305,   309,   310,   314,   315,   328,    47,   411,   412,
       6,    89,   134,   184,   185,   186,   634,     8,   165,   166,
     167,   168,   636,   634,    97,   121,   119,    93,    95,   127,
     143,     6,   106,   109,   232,   233,   234,     4,   137,    10,
     252,    38,   251,   618,   627,   628,    10,   259,   258,   618,
     627,    10,   266,   265,   618,   627,    10,   271,   634,    10,
      11,   276,   277,   278,    10,    11,   291,   292,   293,    10,
      11,   296,   297,   298,    10,    11,   301,   302,   303,    10,
      11,   306,   307,   308,    10,    11,   311,   312,   313,    19,
     316,    55,    62,    86,   108,   116,   130,   132,   144,   148,
     150,   152,   154,   329,   330,   331,   335,   336,   340,   341,
     345,   346,   350,   351,   355,   356,   370,   371,   377,   378,
     384,   385,   391,   392,   396,   397,    10,    11,   418,   419,
     420,    13,    16,    22,    27,   413,   414,   415,   416,   417,
       8,    89,   185,   187,   188,   634,   109,   233,   235,   236,
     137,     6,     7,   253,     3,   629,   634,     6,     7,   260,
       6,     7,   267,     6,   272,     6,   106,   109,   279,   280,
     281,     4,    83,     6,    81,     6,   147,     4,   141,     6,
       7,   123,   633,   634,    10,    11,   317,   318,   319,    10,
      11,   332,   333,   334,    10,    11,   337,   338,   339,    10,
      11,   342,   343,   344,    10,    11,   347,   348,   349,    10,
      11,   352,   353,   354,    25,   357,   372,   373,   379,   380,
     386,   387,   393,   618,    19,   398,    57,   124,   421,   422,
     423,   634,   634,   634,   634,    10,    11,   190,    34,   189,
     618,   621,   622,    10,    11,   238,    40,   237,   618,   621,
     630,   631,    69,   634,    71,    67,    65,   634,   109,   280,
     282,   283,    83,    81,   147,   141,   123,     6,   106,   109,
     320,   321,   322,     4,   131,     4,   133,     4,   117,     4,
      63,     4,    87,     8,    10,    11,   358,   359,   360,    10,
     375,   374,   618,   627,    10,   382,   381,   618,   627,    10,
     389,   388,   618,   627,    10,   394,   634,    10,    11,   399,
     400,   401,   114,   422,   594,   595,   424,   425,     6,     6,
       6,     6,   135,     3,   623,   634,   107,     3,   632,   634,
      10,    11,   285,   284,   618,   621,   630,   634,   109,   321,
     323,   324,   131,   133,   117,    63,    87,     6,   138,   145,
     361,   362,   363,     6,     7,   376,     6,     7,   383,     6,
       7,   390,     6,   395,     6,   106,   109,   402,   403,   404,
      57,    23,   596,    10,   429,    28,    42,   426,   427,   428,
     634,   634,   634,   634,   634,   634,   107,    10,    11,   326,
     325,   618,   621,   630,     8,   145,   362,   364,   153,   155,
     151,   149,   634,   109,   403,   405,   406,   634,    10,    11,
     597,   598,   599,   130,   430,   431,   634,     3,   107,    10,
      11,    30,   365,   366,   367,   368,   615,   616,   618,   624,
     627,    10,    11,   408,   407,   618,   621,   630,     6,   115,
     128,   600,   601,   602,    96,   446,   447,    24,   432,   433,
     434,   435,   618,   624,     6,   634,     6,     7,   139,   369,
       3,   617,   634,   107,   634,   115,   601,   603,   604,   162,
     451,   452,    10,    11,   448,   449,   450,     8,    10,    11,
     436,   437,   438,   434,   634,   139,   634,    10,    11,   607,
     608,   609,    14,   605,   606,   615,   618,   621,   100,   505,
     506,    21,   453,     4,    97,     6,   131,   134,   439,   440,
     441,    58,    60,    61,   129,   610,   611,   612,   613,   614,
       8,    78,   539,   540,    18,   507,   634,    10,    11,   454,
     455,   456,    97,     8,   131,   440,   442,   443,     5,   129,
     611,     6,   112,   573,   574,    17,   541,   634,    10,    11,
     508,   509,   510,     6,   156,   457,   458,    10,    11,   445,
     444,   618,   624,    59,     8,   125,    20,   575,   634,    10,
      11,   542,   543,   544,     6,   156,   511,   512,   634,   158,
     468,   469,    26,   459,   135,   634,    10,    11,   576,   577,
     578,     6,    84,   545,   546,   634,   522,    15,   513,    72,
     478,   479,    26,   470,   634,    10,    11,   460,   461,   462,
       6,   110,   113,   579,   580,   581,   634,   556,    12,   547,
     101,   106,   523,   524,   634,    10,    11,   514,   515,   516,
     488,    26,   480,   634,    10,    11,   471,   472,   473,     6,
     157,   160,   463,   464,   465,   634,   113,   580,   582,   583,
      79,   106,   557,   558,   634,    10,    11,   548,   549,   550,
     525,   526,     6,    98,   157,   517,   518,   519,   106,   163,
     489,   490,   634,    10,    11,   481,   482,   483,     6,   159,
     160,   474,   475,   476,   634,   157,   464,    29,   466,    10,
      11,   586,   587,   588,    14,   584,   585,   615,   618,   621,
     559,   560,     6,    76,   157,   551,   552,   553,    10,    11,
     529,   530,   531,    15,   527,   528,   618,   621,   630,   634,
     157,   518,    29,   520,   491,   492,     6,    73,   160,   484,
     485,   486,   634,   159,   475,    29,   477,   634,    10,    58,
      60,    61,   111,   589,   590,   591,   592,   593,     8,    10,
      11,   563,   564,   565,    12,   561,   562,   618,   621,   630,
     634,    85,   552,    29,   554,    98,   107,   532,   533,   534,
     634,   634,    10,    10,    11,   495,   496,   497,    26,   493,
     494,   618,   621,   630,   634,    73,   485,    29,   487,   634,
      10,     6,     6,     7,   467,     5,   111,   590,     6,    76,
     107,   566,   567,   568,   634,   634,    10,   107,   533,    29,
     535,     6,     6,     6,     7,   521,   107,   160,   498,   499,
     500,   634,   634,    10,     6,     4,   634,   161,    59,     8,
     107,   567,    29,   569,     6,     6,     6,     7,   555,   634,
      10,    11,   536,   537,   538,   634,   634,    99,   107,   499,
      29,   501,     6,     6,     4,   634,   161,   634,    10,    11,
     570,   571,   572,   634,   634,    77,     6,     4,     6,     7,
      99,   635,   634,    10,    11,   502,   503,   504,   634,   634,
     161,     6,    77,   635,   634,    99,     6,   161,   635,   634,
      77,   634,   161
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

  case 50:

    {osresult->setGeneralMessage((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 52:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 57:

    {osresult->setServiceURI((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 59:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 64:

    {osresult->setServiceName((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 66:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 71:

    {osresult->setInstanceName((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 73:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 78:

    {osresult->setJobID((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 80:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 85:

    {osresult->setSolverInvoked((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 87:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 92:

    {osresult->setTimeStamp((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 94:

    {	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	;}
    break;

  case 95:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other general results cannot be negative");
	osresult->setNumberOfOtherGeneralResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 96:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 97:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 103:

    {	parserData->kounter++;
;}
    break;

  case 104:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 105:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 108:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setGeneralOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 109:

    {	
		osresult->setGeneralOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 110:

    {	
		osresult->setGeneralOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 125:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 130:

    {osresult->setSystemInformation((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 132:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 136:

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

  case 137:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 139:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 140:

    {osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 142:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 146:

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

  case 147:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
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
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 156:

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

  case 157:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 159:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 160:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 162:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 164:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 166:

    {osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 168:

    {	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	;}
    break;

  case 169:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other system results cannot be negative");
	osresult->setNumberOfOtherSystemResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 170:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 171:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 177:

    {	parserData->kounter++;
;}
    break;

  case 178:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 179:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 182:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setSystemOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 183:

    {	
		osresult->setSystemOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 184:

    {	
		osresult->setSystemOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 199:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 204:

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

  case 206:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 211:

    {osresult->setCurrentJobCount((yyvsp[(2) - (3)].ival)); /* free($2); */  parserData->errorText = NULL;;}
    break;

  case 213:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 218:

    {osresult->setTotalJobsSoFar((yyvsp[(2) - (3)].ival)); parserData->errorText = NULL;;}
    break;

  case 220:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 225:

    {osresult->setTimeServiceStarted((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 227:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 232:

    {osresult->setServiceUtilization( parserData->tempVal);  parserData->errorText = NULL;;}
    break;

  case 234:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	;}
    break;

  case 235:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other service results cannot be negative");
	osresult->setNumberOfOtherServiceResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 236:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 237:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 243:

    {	parserData->kounter++;
;}
    break;

  case 244:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 245:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 248:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setServiceOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 249:

    {	
		osresult->setServiceOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 250:

    {	
		osresult->setServiceOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 270:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 275:

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

  case 277:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 282:

    {osresult->setJobSubmitTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 284:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 289:

    {osresult->setScheduledStartTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval)); parserData->errorText = NULL;;}
    break;

  case 291:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 296:

    {osresult->setActualStartTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 298:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 303:

    {osresult->setJobEndTime((yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 305:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 306:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
;}
    break;

  case 307:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <time> element");
	;}
    break;

  case 308:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, "fewer <time> elements than specified");
	;}
    break;

  case 315:

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

  case 318:

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

  case 319:

    {	if (parserData->typeAttribute != "cpuTime"     &&
			parserData->typeAttribute != "elapsedTime" &&
 			parserData->typeAttribute != "other"   )     
			osrlerror(NULL, NULL, parserData, "time type not recognized");
	;}
    break;

  case 320:

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

  case 326:

    {	osresult->addTimingInformation(parserData->typeAttribute, parserData->categoryAttribute,
		parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue);       
	parserData->ivar++;
	parserData->timeType = "";
	parserData->timeCategory = "";
	parserData->timeUnit = "";
	parserData->timeDescription = "";      
;}
    break;

  case 327:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 328:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 330:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
	;}
    break;

  case 334:

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

  case 335:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
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
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 344:

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

  case 345:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 347:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 348:

    {osresult->setUsedMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 350:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 354:

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

  case 355:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 357:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 358:

    {osresult->setUsedCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 360:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 362:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 364:

    {osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 366:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	;}
    break;

  case 367:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other job results cannot be negative");
	osresult->setNumberOfOtherJobResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 368:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <other> element");
	;}
    break;

  case 369:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 375:

    {	parserData->kounter++;
;}
    break;

  case 376:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 377:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
;}
    break;

  case 380:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, "otherResult name cannot be empty");
		osresult->setJobOtherResultName(parserData->kounter, parserData->nameAttribute);
	;}
    break;

  case 381:

    {	
		osresult->setJobOtherResultValue(parserData->kounter, parserData->valueAttribute);
	;}
    break;

  case 382:

    {	
		osresult->setJobOtherResultDescription(parserData->kounter, parserData->descriptionAttribute);
	;}
    break;

  case 387:

    {	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
;}
    break;

  case 388:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, "numberOfSolutions was never set");
;}
    break;

  case 395:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfSolutions = (yyvsp[(3) - (4)].ival); 
	osresult->setSolutionNumber((yyvsp[(3) - (4)].ival));
	parserData->solutionIdx = 0;
;}
    break;

  case 396:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, "numberOfVariables attribute previously set");
	parserData->nVarPresent = true;	
	parserData->numberOfVariables = (yyvsp[(3) - (4)].ival); 
	osresult->setVariableNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 397:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, "numberOfConstraints attribute previously set");
	parserData->nConPresent = true;		
	parserData->numberOfConstraints = (yyvsp[(3) - (4)].ival); 
	osresult->setConstraintNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 398:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, "numberOfObjectives attribute previously set");
	parserData->nObjPresent = true;
	parserData->numberOfObjectives = (yyvsp[(3) - (4)].ival); 
	osresult->setObjectiveNumber((yyvsp[(3) - (4)].ival));
;}
    break;

  case 399:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solution> element");
	;}
    break;

  case 400:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, "fewer <solution> elements than specified");
	;}
    break;

  case 407:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 413:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 414:

    {	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval);
	if (parserData->tempStr != "true" && parserData->tempStr != "false")
		osrlerror(NULL, NULL, parserData, "weightedobjectives must be true or false");
  	osresult->setSolutionWeightedObjectives(parserData->solutionIdx, parserData->tempStr);
;}
    break;

  case 415:

    {
		parserData->solutionIdx++;
	;}
    break;

  case 417:

    {	parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
	;}
    break;

  case 418:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, "type attribute must be present for solution status element");
	;}
    break;

  case 421:

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

  case 422:

    {   osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute);
	;}
    break;

  case 424:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, "only one numberOfSubstatuses attribute allowed for solution status element");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of solution substatuses cannot be negative");
    osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 425:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <substatus> element");
	;}
    break;

  case 426:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <substatus> elements than specified");
	;}
    break;

  case 432:

    {	parserData->kounter++; ;}
    break;

  case 433:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 434:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, "<substatus> must have type attribute");
;}
    break;

  case 437:

    {	
		if (parserData->typeAttribute != "stoppedByLimit"  &&
			parserData->typeAttribute != "stoppedByBounds" &&
			parserData->typeAttribute != "other" )
		osrlerror(NULL, NULL, parserData, "substatus type attribute has bad value");
		osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
										   parserData->typeAttribute);	
	;}
    break;

  case 438:

    {	
		osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
												  parserData->descriptionAttribute);
	;}
    break;

  case 448:

    {	osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));
		parserData->errorText = NULL;
	;}
    break;

  case 451:

    {	parserData->numberOfOtherVariableResults = 0; ;}
    break;

  case 453:

    {	
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other variable results cannot be negative");
		osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->numberOfOtherVariableResults = (yyvsp[(3) - (4)].ival);
		parserData->iOther = 0;
	;}
    break;

  case 461:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
	osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 462:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 463:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 469:

    {	osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 470:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 471:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 472:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 473:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 477:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 478:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 479:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 485:

    {
	osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 			parserData->idx,         (yyvsp[(4) - (5)].sval));
	parserData->kounter++;
;}
    break;

  case 486:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 487:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 491:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	osresult->setNumberOfBasisVar(parserData->solutionIdx, parserData->numberOfVar);
;}
    break;

  case 492:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <var> element");
	;}
    break;

  case 493:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, "fewer <var> elements than specified");
	;}
    break;

  case 499:

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

  case 500:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, "more <var> elements than specified");
;}
    break;

  case 501:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 504:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 505:

    {
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
;}
    break;

  case 506:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfVar attribute"); 
	;}
    break;

  case 510:

    {	
	 	osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 											  parserData->valueAttribute);
  ;}
    break;

  case 511:

    {	
	 	osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 											 parserData->nameAttribute);
  ;}
    break;

  case 512:

    {	
	 	osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 													parserData->descriptionAttribute);
  ;}
    break;

  case 513:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <var> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 521:

    { 	
	parserData->kounter++;
;}
    break;

  case 523:

    {	
 	osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 528:

    {	
	 	osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 531:

    {	parserData->numberOfOtherObjectiveResults = 0; ;}
    break;

  case 533:

    {
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other objective results cannot be negative");
		parserData->numberOfOtherObjectiveResults = (yyvsp[(3) - (4)].ival);
        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 541:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj);
	parserData->kounter = 0;
;}
    break;

  case 542:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <obj> element");
	;}
    break;

  case 543:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, "fewer <obj> elements than specified");
	;}
    break;

  case 549:

    {	osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 550:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, "more <obj> elements than specified");
	parserData->idx = -1;
;}
    break;

  case 552:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 553:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 554:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 557:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 558:

    {
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
	;}
    break;

  case 559:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfObj attribute"); 
	;}
    break;

  case 563:

    {	
	 	osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 											   parserData->valueAttribute);
  ;}
    break;

  case 564:

    {	
	  	osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 											  parserData->nameAttribute);
  ;}
    break;

  case 565:

    {	
	 	osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
 													 parserData->descriptionAttribute);
  ;}
    break;

  case 566:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <obj> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 574:

    {  
	parserData->kounter++;
;}
    break;

  case 576:

    {	osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 581:

    {	osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 584:

    {		parserData->numberOfOtherObjectiveResults = 0; ;}
    break;

  case 586:

    {
		if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other constraint results cannot be negative");
		parserData->numberOfOtherConstraintResults = (yyvsp[(3) - (4)].ival);
		osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 593:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 594:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon);
	parserData->kounter = 0;
;}
    break;

  case 595:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <con> element");
	;}
    break;

  case 596:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, "fewer <con> elements than specified");
	;}
    break;

  case 602:

    {	osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
						   parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 603:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, "more <con> elements than specified");
;}
    break;

  case 604:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 605:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 606:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 609:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 610:

    {
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
;}
    break;

  case 611:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfCon attribute"); 
	;}
    break;

  case 615:

    {	
	 	osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 												parserData->valueAttribute);
  ;}
    break;

  case 616:

    {	
	 	osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 											   parserData->nameAttribute);
  ;}
    break;

  case 617:

    {	
	 	osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 													  parserData->descriptionAttribute);
  ;}
    break;

  case 618:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of <con> cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
	parserData->kounter = 0;
;}
    break;

  case 626:

    { 	
	parserData->kounter++;
;}
    break;

  case 628:

    {	
 	osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 633:

    {	
	 	osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 636:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 637:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solution results cannot be negative");
    osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->iOther = 0; 
;}
    break;

  case 638:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <otherSolutionResult> element");
	;}
    break;

  case 639:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <otherSolutionResult> elements than specified");
	;}
    break;

  case 645:

    {	parserData->iOther++;
;}
    break;

  case 646:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 647:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<otherSolutionResult> element must have numberOfItems attribute");
;}
    break;

  case 650:

    {	
		osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
											 parserData->nameAttribute);
	;}
    break;

  case 651:

    {	
		osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
												 parserData->categoryAttribute);
	;}
    break;

  case 652:

    {	
		osresult->setOtherSolutionResultDescription(parserData->solutionIdx, parserData->iOther,
											 parserData->descriptionAttribute);
	;}
    break;

  case 654:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
	osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, parserData->iOther,
												  parserData->numberOfItems);
	parserData->kounter = 0;
;}
    break;

  case 655:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	;}
    break;

  case 656:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	;}
    break;

  case 662:

    {	parserData->kounter++;
;}
    break;

  case 663:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
;}
    break;

  case 667:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
	osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
										 parserData->kounter, parserData->itemContent);
;}
    break;

  case 670:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 671:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of other solver outputs cannot be negative");
    osresult->setNumberOfSolverOutputs((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->iOther = 0; 
;}
    break;

  case 672:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <solverOutput> element");
	;}
    break;

  case 673:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, "fewer <solverOutput> elements than specified");
	;}
    break;

  case 679:

    {	parserData->iOther++;
;}
    break;

  case 680:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <solverOutput> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
;}
    break;

  case 681:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, "<solverOutput> element must have numberOfItems attribute");
;}
    break;

  case 685:

    {	
		osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute);
	;}
    break;

  case 686:

    {	
		osresult->setSolverOutputCategory(parserData->iOther, parserData->categoryAttribute);
	;}
    break;

  case 687:

    {	
		osresult->setSolverOutputDescription(parserData->iOther, parserData->descriptionAttribute);
	;}
    break;

  case 688:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
	osresult->setSolverOutputNumberOfItems(parserData->iOther, parserData->numberOfItems);
	parserData->kounter = 0;
;}
    break;

  case 689:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <item> element");
	;}
    break;

  case 690:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, "fewer <item> elements than specified");
	;}
    break;

  case 696:

    {	parserData->kounter++;
;}
    break;

  case 697:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
;}
    break;

  case 701:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
	osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, parserData->itemContent);
;}
    break;

  case 703:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 704:

    { parserData->categoryAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 705:

    { parserData->categoryAttribute = "";          ;}
    break;

  case 707:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 708:

    { parserData->descriptionAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 709:

    { parserData->descriptionAttribute = "";          ;}
    break;

  case 711:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 712:

    { parserData->nameAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 713:

    { parserData->nameAttribute = "";          ;}
    break;

  case 715:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 716:

    { parserData->typeAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 717:

    { parserData->typeAttribute = "";          ;}
    break;

  case 719:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 720:

    { parserData->unitAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 721:

    { parserData->unitAttribute = "";          ;}
    break;

  case 723:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 724:

    { parserData->valueAttribute = (yyvsp[(1) - (2)].sval); free((yyvsp[(1) - (2)].sval));;}
    break;

  case 725:

    { parserData->valueAttribute = "";          ;}
    break;

  case 726:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 727:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 729:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 730:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 731:

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


