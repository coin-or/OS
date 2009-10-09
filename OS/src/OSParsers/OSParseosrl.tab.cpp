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
#define YYLAST   934

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  335
/* YYNRULES -- Number of rules.  */
#define YYNRULES  627
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1053

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
     320,   327,   329,   330,   333,   335,   337,   341,   345,   347,
     349,   351,   357,   359,   360,   363,   365,   367,   371,   375,
     377,   379,   381,   387,   389,   390,   393,   395,   397,   401,
     405,   407,   409,   411,   417,   419,   420,   422,   426,   428,
     430,   434,   436,   441,   443,   445,   448,   450,   454,   456,
     459,   463,   465,   466,   469,   471,   473,   475,   479,   483,
     485,   489,   491,   494,   496,   497,   500,   505,   506,   509,
     511,   513,   515,   517,   519,   521,   526,   530,   533,   538,
     542,   545,   550,   554,   557,   562,   566,   569,   574,   578,
     581,   585,   587,   592,   594,   596,   599,   601,   605,   607,
     610,   614,   616,   617,   620,   622,   624,   626,   630,   634,
     636,   640,   642,   645,   647,   648,   651,   656,   657,   660,
     662,   664,   666,   668,   670,   672,   674,   676,   678,   680,
     682,   687,   691,   694,   699,   703,   706,   711,   715,   718,
     723,   727,   730,   735,   739,   742,   746,   751,   753,   757,
     758,   761,   765,   766,   769,   771,   773,   775,   777,   781,
     783,   787,   789,   793,   795,   799,   801,   803,   805,   808,
     810,   814,   815,   817,   819,   825,   826,   829,   831,   833,
     837,   841,   843,   845,   847,   853,   854,   857,   861,   863,
     865,   867,   873,   874,   877,   879,   881,   885,   889,   891,
     893,   895,   901,   902,   905,   907,   909,   913,   917,   919,
     921,   923,   927,   932,   934,   936,   939,   941,   945,   947,
     950,   954,   955,   958,   960,   962,   964,   968,   972,   974,
     978,   980,   983,   985,   986,   990,   991,   994,   997,  1000,
    1003,  1006,  1010,  1014,  1018,  1022,  1026,  1028,  1031,  1032,
    1035,  1039,  1041,  1042,  1045,  1047,  1049,  1054,  1058,  1067,
    1071,  1073,  1076,  1080,  1082,  1086,  1088,  1093,  1095,  1097,
    1100,  1102,  1106,  1108,  1111,  1115,  1116,  1119,  1121,  1123,
    1127,  1131,  1133,  1136,  1138,  1139,  1144,  1148,  1151,  1152,
    1156,  1157,  1162,  1164,  1166,  1168,  1175,  1176,  1182,  1186,
    1191,  1192,  1195,  1201,  1206,  1208,  1210,  1211,  1217,  1221,
    1226,  1227,  1230,  1236,  1241,  1245,  1250,  1251,  1257,  1261,
    1266,  1267,  1270,  1276,  1281,  1282,  1285,  1286,  1291,  1293,
    1295,  1296,  1299,  1301,  1303,  1305,  1307,  1312,  1314,  1318,
    1320,  1324,  1328,  1330,  1332,  1336,  1337,  1340,  1344,  1346,
    1351,  1355,  1358,  1360,  1361,  1365,  1366,  1371,  1373,  1375,
    1377,  1382,  1383,  1389,  1393,  1398,  1399,  1402,  1408,  1413,
    1415,  1417,  1418,  1421,  1425,  1427,  1428,  1431,  1433,  1435,
    1437,  1439,  1444,  1446,  1450,  1452,  1456,  1460,  1462,  1464,
    1468,  1469,  1472,  1476,  1478,  1483,  1487,  1490,  1492,  1493,
    1497,  1498,  1503,  1505,  1507,  1509,  1514,  1515,  1521,  1525,
    1530,  1531,  1534,  1540,  1545,  1547,  1549,  1550,  1553,  1557,
    1559,  1560,  1563,  1565,  1567,  1569,  1571,  1576,  1578,  1582,
    1584,  1588,  1592,  1594,  1596,  1600,  1601,  1604,  1608,  1610,
    1615,  1619,  1622,  1624,  1625,  1631,  1635,  1636,  1642,  1643,
    1646,  1652,  1656,  1657,  1658,  1662,  1664,  1666,  1668,  1670,
    1675,  1677,  1681,  1685,  1687,  1691,  1693,  1694,  1697,  1699,
    1701,  1703,  1705,  1706,  1711,  1713,  1714,  1718,  1723,  1725,
    1729,  1730,  1733,  1739,  1743,  1744,  1745,  1749,  1751,  1753,
    1755,  1757,  1762,  1764,  1768,  1772,  1774,  1778,  1780,  1781,
    1784,  1786,  1788,  1790,  1792,  1793,  1798,  1800,  1802,  1805,
    1807,  1809,  1811,  1813,  1815,  1817,  1819,  1820
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   216,   262,   285,   343,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   194,    -1,   195,    -1,   196,    -1,   197,
      -1,   198,    -1,   199,    -1,   200,    -1,   201,    -1,   176,
     177,   183,    -1,    88,    -1,   178,    -1,   179,    -1,   178,
     179,    -1,   180,    -1,   181,    -1,   182,    -1,    36,     3,
     500,    -1,    37,    -1,    32,     3,   500,    -1,    33,    -1,
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
     108,    -1,    19,   500,     6,   500,    -1,   205,    -1,   206,
      -1,    10,   109,    -1,    11,    -1,    10,   207,   109,    -1,
     208,    -1,   207,   208,    -1,   209,   210,   215,    -1,   106,
      -1,    -1,   210,   211,    -1,   212,    -1,   213,    -1,   214,
      -1,    34,     3,   500,    -1,    40,     3,   500,    -1,    41,
      -1,    32,     3,   500,    -1,    33,    -1,    10,   107,    -1,
      11,    -1,    -1,    50,    11,    -1,    50,    10,   217,    51,
      -1,    -1,   217,   218,    -1,   219,    -1,   220,    -1,   228,
      -1,   235,    -1,   242,    -1,   247,    -1,   136,    10,     4,
     137,    -1,   136,    10,   137,    -1,   136,    11,    -1,    -1,
     222,   223,    10,   227,   221,    69,    -1,    68,    -1,    -1,
     223,   224,    -1,   225,    -1,   226,    -1,    38,     3,   500,
      -1,    32,     3,   500,    -1,    33,    -1,     6,    -1,     7,
      -1,   229,   230,    10,   234,    71,    -1,    70,    -1,    -1,
     230,   231,    -1,   232,    -1,   233,    -1,    38,     3,   500,
      -1,    32,     3,   500,    -1,    33,    -1,     6,    -1,     7,
      -1,   236,   237,    10,   241,    67,    -1,    66,    -1,    -1,
     237,   238,    -1,   239,    -1,   240,    -1,    38,     3,   500,
      -1,    32,     3,   500,    -1,    33,    -1,     6,    -1,     7,
      -1,   243,   244,    10,   246,    65,    -1,    64,    -1,    -1,
     245,    -1,    32,     3,   500,    -1,    33,    -1,     6,    -1,
     248,   249,   250,    -1,   108,    -1,    19,   500,     6,   500,
      -1,   251,    -1,   252,    -1,    10,   109,    -1,    11,    -1,
      10,   253,   109,    -1,   254,    -1,   253,   254,    -1,   255,
     256,   261,    -1,   106,    -1,    -1,   256,   257,    -1,   258,
      -1,   259,    -1,   260,    -1,    34,     3,   500,    -1,    40,
       3,   500,    -1,    41,    -1,    32,     3,   500,    -1,    33,
      -1,    10,   107,    -1,    11,    -1,    -1,    52,    11,    -1,
      52,    10,   263,    53,    -1,    -1,   263,   264,    -1,   265,
      -1,   266,    -1,   267,    -1,   268,    -1,   269,    -1,   270,
      -1,    82,    10,     4,    83,    -1,    82,    10,    83,    -1,
      82,    11,    -1,    80,    10,     6,    81,    -1,    80,    10,
      81,    -1,    80,    11,    -1,   146,    10,     6,   147,    -1,
     146,    10,   147,    -1,   146,    11,    -1,   140,    10,     4,
     141,    -1,   140,    10,   141,    -1,   140,    11,    -1,   122,
      10,   499,   123,    -1,   122,    10,   123,    -1,   122,    11,
      -1,   271,   272,   273,    -1,   108,    -1,    19,   500,     6,
     500,    -1,   274,    -1,   275,    -1,    10,   109,    -1,    11,
      -1,    10,   276,   109,    -1,   277,    -1,   276,   277,    -1,
     278,   279,   284,    -1,   106,    -1,    -1,   279,   280,    -1,
     281,    -1,   282,    -1,   283,    -1,    34,     3,   500,    -1,
      40,     3,   500,    -1,    41,    -1,    32,     3,   500,    -1,
      33,    -1,    10,   107,    -1,    11,    -1,    -1,    54,    11,
      -1,    54,    10,   286,    55,    -1,    -1,   286,   287,    -1,
     288,    -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,
     293,    -1,   308,    -1,   314,    -1,   318,    -1,   324,    -1,
     330,    -1,   130,    10,     4,   131,    -1,   130,    10,   131,
      -1,   130,    11,    -1,   132,    10,     4,   133,    -1,   132,
      10,   133,    -1,   132,    11,    -1,   116,    10,     4,   117,
      -1,   116,    10,   117,    -1,   116,    11,    -1,    62,    10,
       4,    63,    -1,    62,    10,    63,    -1,    62,    11,    -1,
      86,    10,     4,    87,    -1,    86,    10,    87,    -1,    86,
      11,    -1,   144,   294,   295,    -1,    25,     8,     6,     8,
      -1,    11,    -1,    10,   296,   145,    -1,    -1,   296,   297,
      -1,   138,   298,   304,    -1,    -1,   298,   299,    -1,   300,
      -1,   301,    -1,   302,    -1,   303,    -1,    36,     3,     8,
      -1,    37,    -1,    30,     3,     8,    -1,    31,    -1,    38,
       3,     8,    -1,    39,    -1,    32,     3,     8,    -1,    33,
      -1,   305,    -1,   306,    -1,    10,   139,    -1,    11,    -1,
      10,   307,   139,    -1,    -1,     7,    -1,     6,    -1,   150,
     309,    10,   313,   151,    -1,    -1,   309,   310,    -1,   311,
      -1,   312,    -1,    38,     3,   500,    -1,    32,     3,   500,
      -1,    33,    -1,     6,    -1,     7,    -1,   148,   315,    10,
     317,   149,    -1,    -1,   315,   316,    -1,    32,     3,   500,
      -1,    33,    -1,     6,    -1,     7,    -1,   152,   319,    10,
     323,   153,    -1,    -1,   319,   320,    -1,   321,    -1,   322,
      -1,    38,     3,   500,    -1,    32,     3,   500,    -1,    33,
      -1,     6,    -1,     7,    -1,   154,   325,    10,   329,   155,
      -1,    -1,   325,   326,    -1,   327,    -1,   328,    -1,    38,
       3,   500,    -1,    32,     3,   500,    -1,    33,    -1,     6,
      -1,     7,    -1,   108,   331,   332,    -1,    19,   500,     6,
     500,    -1,   333,    -1,   334,    -1,    10,   109,    -1,    11,
      -1,    10,   335,   109,    -1,   336,    -1,   335,   336,    -1,
     106,   337,   342,    -1,    -1,   337,   338,    -1,   339,    -1,
     340,    -1,   341,    -1,    34,     3,   500,    -1,    40,     3,
     500,    -1,    41,    -1,    32,     3,   500,    -1,    33,    -1,
      10,   107,    -1,    11,    -1,    -1,    56,   344,   350,    -1,
      -1,   344,   345,    -1,   346,   500,    -1,   347,   500,    -1,
     348,   500,    -1,   349,   500,    -1,    22,   500,     6,    -1,
      27,   500,     6,    -1,    13,   500,     6,    -1,    16,   500,
       6,    -1,    10,   351,    57,    -1,    11,    -1,   352,   482,
      -1,    -1,   352,   353,    -1,   354,   355,   359,    -1,   124,
      -1,    -1,   355,   356,    -1,   357,    -1,   358,    -1,    28,
     500,     6,   500,    -1,    42,     3,   500,    -1,    10,   360,
     373,   374,   412,   438,   464,   481,    -1,   130,   361,   363,
      -1,   362,    -1,   361,   362,    -1,    36,     3,   500,    -1,
      37,    -1,    32,     3,   500,    -1,    33,    -1,    24,     8,
       6,     8,    -1,   364,    -1,   365,    -1,    10,   131,    -1,
      11,    -1,    10,   366,   131,    -1,   367,    -1,   366,   367,
      -1,   134,   368,   372,    -1,    -1,   368,   369,    -1,   370,
      -1,   371,    -1,    36,     3,     8,    -1,    32,     3,     8,
      -1,    33,    -1,    10,   135,    -1,    11,    -1,    -1,    96,
      10,     4,    97,    -1,    96,    10,    97,    -1,    96,    11,
      -1,    -1,   162,   375,   376,    -1,    -1,    21,   500,     6,
     500,    -1,   377,    -1,   378,    -1,    11,    -1,    10,   379,
     385,   390,   395,   163,    -1,    -1,   156,   380,    10,   381,
     157,    -1,   156,   380,    11,    -1,    26,   500,     6,   500,
      -1,    -1,   381,   382,    -1,   160,   383,    10,   384,   161,
      -1,    29,   500,     6,   500,    -1,     6,    -1,     7,    -1,
      -1,   158,   386,    10,   387,   159,    -1,   158,   386,    11,
      -1,    26,   500,     6,   500,    -1,    -1,   387,   388,    -1,
     160,   389,    10,     4,   161,    -1,   160,   389,    10,   161,
      -1,   160,   389,    11,    -1,    29,   500,     6,   500,    -1,
      -1,    72,   391,    10,   392,    73,    -1,    72,   391,    11,
      -1,    26,   500,     6,   500,    -1,    -1,   392,   393,    -1,
     160,   394,    10,     4,   161,    -1,    29,   500,     6,   500,
      -1,    -1,   395,   396,    -1,    -1,   398,   399,   397,   406,
      -1,   106,    -1,   400,    -1,    -1,   400,   401,    -1,   402,
      -1,   403,    -1,   404,    -1,   405,    -1,    26,   500,     6,
     500,    -1,    41,    -1,    40,     3,   500,    -1,    35,    -1,
      34,     3,   500,    -1,    32,     3,   500,    -1,    33,    -1,
      11,    -1,    10,   407,   107,    -1,    -1,   407,   408,    -1,
     409,   410,   411,    -1,   160,    -1,    29,   500,     6,   500,
      -1,    10,   501,   161,    -1,    10,   161,    -1,    11,    -1,
      -1,   100,   413,   414,    -1,    -1,    18,   500,     6,   500,
      -1,   415,    -1,   416,    -1,    11,    -1,    10,   417,   423,
     101,    -1,    -1,   156,   418,    10,   419,   157,    -1,   156,
     418,    11,    -1,    15,   500,     6,   500,    -1,    -1,   419,
     420,    -1,    98,   421,    10,   422,    99,    -1,    29,   500,
       6,   500,    -1,     6,    -1,     7,    -1,    -1,   423,   424,
      -1,   425,   426,   432,    -1,   106,    -1,    -1,   426,   427,
      -1,   428,    -1,   429,    -1,   430,    -1,   431,    -1,    15,
     500,     6,   500,    -1,    41,    -1,    40,     3,   500,    -1,
      35,    -1,    34,     3,   500,    -1,    32,     3,   500,    -1,
      33,    -1,    11,    -1,    10,   433,   107,    -1,    -1,   433,
     434,    -1,   435,   436,   437,    -1,    98,    -1,    29,   500,
       6,   500,    -1,    10,   501,    99,    -1,    10,    99,    -1,
      11,    -1,    -1,    78,   439,   440,    -1,    -1,    17,   500,
       6,   500,    -1,   441,    -1,   442,    -1,    11,    -1,    10,
     443,   449,    79,    -1,    -1,    84,   444,    10,   445,    85,
      -1,    84,   444,    11,    -1,    12,   500,     6,   500,    -1,
      -1,   445,   446,    -1,    76,   447,    10,   448,    77,    -1,
      29,   500,     6,   500,    -1,     7,    -1,     6,    -1,    -1,
     449,   450,    -1,   451,   452,   458,    -1,   106,    -1,    -1,
     452,   453,    -1,   454,    -1,   455,    -1,   456,    -1,   457,
      -1,    12,   500,     6,   500,    -1,    41,    -1,    40,     3,
     500,    -1,    35,    -1,    34,     3,   500,    -1,    32,     3,
     500,    -1,    33,    -1,    11,    -1,    10,   459,   107,    -1,
      -1,   459,   460,    -1,   461,   462,   463,    -1,    76,    -1,
      29,   500,     6,   500,    -1,    10,   501,    77,    -1,    10,
      77,    -1,    11,    -1,    -1,   112,   465,    10,   467,   113,
      -1,   112,   465,    11,    -1,    -1,    20,     8,     6,   466,
       8,    -1,    -1,   467,   468,    -1,   110,   469,    10,   476,
     111,    -1,   110,   469,    11,    -1,    -1,    -1,   469,   470,
     471,    -1,   472,    -1,   473,    -1,   474,    -1,   475,    -1,
      14,     8,     6,     8,    -1,    35,    -1,    34,     3,   500,
      -1,    30,     3,     8,    -1,    31,    -1,    32,     3,     8,
      -1,    33,    -1,    -1,   476,   477,    -1,   478,    -1,   479,
      -1,    60,    -1,    61,    -1,    -1,    58,     5,   480,    59,
      -1,   125,    -1,    -1,   114,   483,   484,    -1,    23,   500,
       6,   500,    -1,    11,    -1,    10,   485,   115,    -1,    -1,
     485,   486,    -1,   128,   487,    10,   494,   129,    -1,   128,
     487,    11,    -1,    -1,    -1,   487,   488,   489,    -1,   490,
      -1,   491,    -1,   492,    -1,   493,    -1,    14,     8,     6,
       8,    -1,    35,    -1,    34,     3,     8,    -1,    30,     3,
       8,    -1,    31,    -1,    32,     3,     8,    -1,    33,    -1,
      -1,   494,   495,    -1,   496,    -1,   497,    -1,    60,    -1,
      61,    -1,    -1,    58,     5,   498,    59,    -1,     6,    -1,
       7,    -1,   503,     8,    -1,     4,    -1,     6,    -1,     7,
      -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1,    -1,
     503,   502,    -1
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
     449,   454,   455,   456,   457,   458,   466,   467,   468,   471,
     470,   473,   479,   479,   481,   481,   483,   492,   494,   497,
     498,   500,   503,   509,   509,   511,   511,   513,   521,   523,
     526,   527,   529,   532,   538,   538,   540,   540,   542,   554,
     556,   559,   560,   563,   566,   572,   572,   574,   576,   579,
     582,   587,   589,   595,   595,   597,   597,   599,   601,   601,
     603,   612,   617,   617,   620,   626,   632,   640,   642,   643,
     645,   646,   648,   648,   652,   652,   653,   655,   655,   658,
     663,   668,   673,   678,   683,   691,   692,   693,   696,   697,
     698,   701,   702,   703,   706,   707,   708,   711,   712,   713,
     716,   721,   723,   729,   729,   731,   731,   733,   735,   735,
     737,   746,   751,   751,   754,   760,   766,   775,   777,   778,
     780,   781,   783,   783,   786,   786,   787,   789,   789,   792,
     797,   802,   807,   812,   817,   822,   827,   832,   837,   842,
     849,   850,   851,   854,   855,   856,   859,   860,   861,   864,
     865,   866,   869,   870,   871,   874,   876,   882,   882,   884,
     884,   886,   888,   888,   890,   890,   890,   890,   892,   893,
     895,   896,   898,   899,   901,   902,   904,   904,   906,   906,
     908,   919,   923,   924,   927,   930,   930,   932,   932,   934,
     936,   937,   940,   941,   944,   947,   947,   949,   950,   953,
     954,   957,   960,   960,   962,   962,   964,   966,   967,   970,
     971,   973,   976,   976,   978,   978,   980,   982,   983,   986,
     987,   991,   993,   995,   995,   997,   997,   999,  1001,  1001,
    1003,  1005,  1005,  1007,  1007,  1007,  1009,  1011,  1012,  1014,
    1015,  1017,  1017,  1021,  1021,  1023,  1023,  1025,  1026,  1027,
    1028,  1032,  1033,  1034,  1035,  1038,  1038,  1040,  1042,  1042,
    1044,  1051,  1057,  1057,  1059,  1059,  1061,  1068,  1071,  1074,
    1076,  1077,  1079,  1080,  1081,  1082,  1083,  1086,  1092,  1098,
    1098,  1100,  1102,  1102,  1104,  1106,  1106,  1108,  1108,  1110,
    1114,  1115,  1117,  1117,  1121,  1122,  1126,  1130,  1132,  1133,
    1135,  1136,  1146,  1146,  1148,  1150,  1152,  1153,  1162,  1173,
    1180,  1180,  1182,  1184,  1187,  1191,  1197,  1198,  1207,  1209,
    1216,  1216,  1218,  1223,  1224,  1226,  1230,  1230,  1239,  1241,
    1248,  1248,  1250,  1252,  1257,  1257,  1260,  1259,  1279,  1287,
    1293,  1293,  1295,  1295,  1295,  1295,  1297,  1309,  1312,  1318,
    1324,  1330,  1335,  1337,  1338,  1340,  1340,  1342,  1357,  1362,
    1364,  1364,  1364,  1367,  1368,  1370,  1371,  1381,  1381,  1383,
    1385,  1387,  1388,  1397,  1399,  1403,  1403,  1405,  1407,  1410,
    1414,  1420,  1420,  1422,  1425,  1433,  1434,  1436,  1436,  1436,
    1436,  1438,  1447,  1450,  1456,  1462,  1468,  1473,  1476,  1477,
    1499,  1499,  1501,  1516,  1521,  1523,  1523,  1523,  1527,  1528,
    1530,  1531,  1541,  1541,  1543,  1545,  1548,  1549,  1559,  1561,
    1566,  1566,  1568,  1570,  1573,  1577,  1583,  1583,  1585,  1588,
    1590,  1590,  1592,  1592,  1592,  1592,  1594,  1597,  1600,  1606,
    1612,  1618,  1623,  1625,  1626,  1629,  1629,  1631,  1647,  1652,
    1654,  1654,  1654,  1658,  1659,  1664,  1671,  1670,  1686,  1686,
    1689,  1696,  1705,  1706,  1706,  1710,  1710,  1710,  1710,  1712,
    1725,  1731,  1739,  1742,  1745,  1748,  1750,  1751,  1754,  1759,
    1766,  1766,  1769,  1768,  1774,  1784,  1784,  1786,  1788,  1788,
    1790,  1790,  1793,  1800,  1802,  1804,  1803,  1808,  1808,  1808,
    1808,  1810,  1825,  1832,  1841,  1847,  1850,  1856,  1858,  1859,
    1861,  1866,  1872,  1872,  1875,  1874,  1880,  1881,  1883,  1886,
    1887,  1888,  1892,  1893,  1894,  1895,  1897,  1898
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
  "availableDiskSpace", "@1", "availableDiskSpaceStart",
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
  "@2", "otherVariableStart", "otherVariableAttributes",
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
  "solverOutputItemList", "solverOutputItem", "solverOutputItemEmpty",
  "solverOutputItemContent", "@7", "aNumber", "quote", "ElementValue",
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
     218,   218,   218,   218,   218,   218,   219,   219,   219,   221,
     220,   222,   223,   223,   224,   224,   225,   226,   226,   227,
     227,   228,   229,   230,   230,   231,   231,   232,   233,   233,
     234,   234,   235,   236,   237,   237,   238,   238,   239,   240,
     240,   241,   241,   242,   243,   244,   244,   245,   245,   246,
     247,   248,   249,   250,   250,   251,   251,   252,   253,   253,
     254,   255,   256,   256,   257,   257,   257,   258,   259,   259,
     260,   260,   261,   261,   262,   262,   262,   263,   263,   264,
     264,   264,   264,   264,   264,   265,   265,   265,   266,   266,
     266,   267,   267,   267,   268,   268,   268,   269,   269,   269,
     270,   271,   272,   273,   273,   274,   274,   275,   276,   276,
     277,   278,   279,   279,   280,   280,   280,   281,   282,   282,
     283,   283,   284,   284,   285,   285,   285,   286,   286,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     288,   288,   288,   289,   289,   289,   290,   290,   290,   291,
     291,   291,   292,   292,   292,   293,   294,   295,   295,   296,
     296,   297,   298,   298,   299,   299,   299,   299,   300,   300,
     301,   301,   302,   302,   303,   303,   304,   304,   305,   305,
     306,   306,   307,   307,   308,   309,   309,   310,   310,   311,
     312,   312,   313,   313,   314,   315,   315,   316,   316,   317,
     317,   318,   319,   319,   320,   320,   321,   322,   322,   323,
     323,   324,   325,   325,   326,   326,   327,   328,   328,   329,
     329,   330,   331,   332,   332,   333,   333,   334,   335,   335,
     336,   337,   337,   338,   338,   338,   339,   340,   340,   341,
     341,   342,   342,   343,   343,   344,   344,   345,   345,   345,
     345,   346,   347,   348,   349,   350,   350,   351,   352,   352,
     353,   354,   355,   355,   356,   356,   357,   358,   359,   360,
     361,   361,   362,   362,   362,   362,   362,   363,   363,   364,
     364,   365,   366,   366,   367,   368,   368,   369,   369,   370,
     371,   371,   372,   372,   373,   373,   373,   373,   374,   374,
     375,   375,   376,   376,   377,   378,   379,   379,   379,   380,
     381,   381,   382,   383,   384,   384,   385,   385,   385,   386,
     387,   387,   388,   388,   388,   389,   390,   390,   390,   391,
     392,   392,   393,   394,   395,   395,   397,   396,   398,   399,
     400,   400,   401,   401,   401,   401,   402,   403,   403,   404,
     404,   405,   405,   406,   406,   407,   407,   408,   409,   410,
     411,   411,   411,   412,   412,   413,   413,   414,   414,   415,
     416,   417,   417,   417,   418,   419,   419,   420,   421,   422,
     422,   423,   423,   424,   425,   426,   426,   427,   427,   427,
     427,   428,   429,   429,   430,   430,   431,   431,   432,   432,
     433,   433,   434,   435,   436,   437,   437,   437,   438,   438,
     439,   439,   440,   440,   441,   442,   443,   443,   443,   444,
     445,   445,   446,   447,   448,   448,   449,   449,   450,   451,
     452,   452,   453,   453,   453,   453,   454,   455,   455,   456,
     456,   457,   457,   458,   458,   459,   459,   460,   461,   462,
     463,   463,   463,   464,   464,   464,   466,   465,   467,   467,
     468,   468,   469,   470,   469,   471,   471,   471,   471,   472,
     473,   473,   474,   474,   475,   475,   476,   476,   477,   477,
     478,   478,   480,   479,   481,   482,   482,   483,   484,   484,
     485,   485,   486,   486,   487,   488,   487,   489,   489,   489,
     489,   490,   491,   491,   492,   492,   493,   493,   494,   494,
     495,   495,   496,   496,   498,   497,   499,   499,   500,   501,
     501,   501,   502,   502,   502,   502,   503,   503
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
       1,     1,     1,     1,     1,     1,     4,     3,     2,     0,
       6,     1,     0,     2,     1,     1,     3,     3,     1,     1,
       1,     5,     1,     0,     2,     1,     1,     3,     3,     1,
       1,     1,     5,     1,     0,     2,     1,     1,     3,     3,
       1,     1,     1,     5,     1,     0,     1,     3,     1,     1,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       3,     1,     0,     2,     1,     1,     1,     3,     3,     1,
       3,     1,     2,     1,     0,     2,     4,     0,     2,     1,
       1,     1,     1,     1,     1,     4,     3,     2,     4,     3,
       2,     4,     3,     2,     4,     3,     2,     4,     3,     2,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       3,     1,     0,     2,     1,     1,     1,     3,     3,     1,
       3,     1,     2,     1,     0,     2,     4,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     2,     4,     3,     2,     4,     3,     2,     4,
       3,     2,     4,     3,     2,     3,     4,     1,     3,     0,
       2,     3,     0,     2,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     2,     1,
       3,     0,     1,     1,     5,     0,     2,     1,     1,     3,
       3,     1,     1,     1,     5,     0,     2,     3,     1,     1,
       1,     5,     0,     2,     1,     1,     3,     3,     1,     1,
       1,     5,     0,     2,     1,     1,     3,     3,     1,     1,
       1,     3,     4,     1,     1,     2,     1,     3,     1,     2,
       3,     0,     2,     1,     1,     1,     3,     3,     1,     3,
       1,     2,     1,     0,     3,     0,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     1,     2,     0,     2,
       3,     1,     0,     2,     1,     1,     4,     3,     8,     3,
       1,     2,     3,     1,     3,     1,     4,     1,     1,     2,
       1,     3,     1,     2,     3,     0,     2,     1,     1,     3,
       3,     1,     2,     1,     0,     4,     3,     2,     0,     3,
       0,     4,     1,     1,     1,     6,     0,     5,     3,     4,
       0,     2,     5,     4,     1,     1,     0,     5,     3,     4,
       0,     2,     5,     4,     3,     4,     0,     5,     3,     4,
       0,     2,     5,     4,     0,     2,     0,     4,     1,     1,
       0,     2,     1,     1,     1,     1,     4,     1,     3,     1,
       3,     3,     1,     1,     3,     0,     2,     3,     1,     4,
       3,     2,     1,     0,     3,     0,     4,     1,     1,     1,
       4,     0,     5,     3,     4,     0,     2,     5,     4,     1,
       1,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       1,     4,     1,     3,     1,     3,     3,     1,     1,     3,
       0,     2,     3,     1,     4,     3,     2,     1,     0,     3,
       0,     4,     1,     1,     1,     4,     0,     5,     3,     4,
       0,     2,     5,     4,     1,     1,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     4,     1,     3,     1,
       3,     3,     1,     1,     3,     0,     2,     3,     1,     4,
       3,     2,     1,     0,     5,     3,     0,     5,     0,     2,
       5,     3,     0,     0,     3,     1,     1,     1,     1,     4,
       1,     3,     3,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     0,     4,     1,     0,     3,     4,     1,     3,
       0,     2,     5,     3,     0,     0,     3,     1,     1,     1,
       1,     4,     1,     3,     3,     1,     3,     1,     0,     2,
       1,     1,     1,     1,     0,     4,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    95,     4,
       8,     6,     0,   174,     0,    98,    96,     0,   224,     7,
      20,     0,     0,     0,    72,     0,     0,     0,     0,     9,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,   177,   175,     0,   343,     0,    61,     0,    64,
       0,    52,     0,    58,     0,    55,     0,    67,     0,    70,
       0,     0,    30,     0,    28,     0,    21,    22,    24,    25,
      26,   626,     0,    97,   144,   133,   111,   122,   151,     0,
      99,   100,   101,   112,   102,   123,   103,   134,   104,   145,
     105,     0,     0,   227,   225,   345,     0,     0,    60,     0,
      63,     0,    51,     0,    57,     0,    54,     0,    66,     0,
      69,     0,   626,   626,     0,    35,    19,    32,    33,    23,
       0,     0,     0,    77,    71,    74,    75,     0,   108,     0,
       0,     0,     0,   148,     0,   146,   626,     0,   176,     0,
       0,   201,     0,     0,     0,   178,   179,   180,   181,   182,
     183,   184,     0,     0,     0,     2,    59,    62,    50,    56,
      53,    65,    68,     0,    29,    27,    34,    40,     0,    37,
      41,   626,   618,   622,   623,   624,   625,   627,    82,    76,
       0,    79,    83,     0,   107,     0,     0,   118,     0,   113,
     114,   115,     0,     0,   129,     0,   124,   125,   126,     0,
       0,   140,     0,   135,   136,   137,   626,     0,     0,     0,
     156,   150,   153,   154,     0,   190,     0,   187,     0,   199,
       0,   196,     0,   193,   626,     0,   226,     0,     0,     0,
       0,     0,     0,     0,   295,   285,   302,   312,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     358,   356,   626,   626,   626,   626,   346,   626,   626,   626,
     626,   344,    31,    36,    38,     0,    73,    78,    80,     0,
     106,   119,   120,   109,   626,   626,   130,   131,     0,   626,
     626,   141,   142,     0,   626,   626,   147,   149,     0,   626,
     161,   155,     0,   158,   162,     0,   189,     0,   186,   616,
     617,   198,     0,     0,   195,     0,   192,     0,     0,   206,
     200,   203,   204,     0,   251,     0,   254,   626,     0,     0,
     248,     0,   242,     0,   245,     0,     0,     0,     0,     0,
       0,     0,   585,     0,     0,     0,     0,   347,   348,   349,
     350,     0,    49,     0,    47,     0,    42,    43,    44,    39,
       0,    94,     0,    92,     0,     0,    90,    84,    85,    86,
      87,    81,     0,   117,   116,   121,   128,   127,   132,   139,
     138,   143,   152,   157,   159,     0,   188,   185,   197,   194,
     191,   626,   211,   205,     0,   208,   212,     0,   250,     0,
     253,     0,     0,   326,   321,   323,   324,     0,   247,     0,
     241,     0,   244,     0,   259,   257,   255,     0,     0,   298,
     296,     0,     0,   291,     0,   286,   287,   288,     0,     0,
     308,     0,   303,   304,   305,     0,     0,   318,     0,   313,
     314,   315,   355,     0,   361,   359,   362,   357,   353,   354,
     351,   352,    48,     0,     0,    93,   626,   626,   626,   110,
       0,   173,     0,   171,     0,     0,   169,   163,   164,   165,
     166,   160,   202,   207,   209,     0,   249,   252,   626,   331,
     325,     0,   328,   246,   240,   243,     0,     0,   299,   300,
       0,   626,   292,   293,     0,   626,   626,   309,   310,     0,
     626,   626,   319,   320,     0,   626,   626,   626,     0,     0,
      46,    45,    91,    88,    89,   172,   626,   626,   626,     0,
     223,     0,   221,     0,     0,   219,   213,   214,   215,   216,
     210,   322,     0,   327,   329,   256,   262,   258,   260,   294,
     297,   284,   290,   289,   301,   307,   306,   311,   317,   316,
       0,   590,   588,   586,     0,   626,     0,   363,   364,   365,
     360,   170,   167,   168,   222,   626,   626,   626,     0,   342,
       0,   340,     0,     0,   338,   332,   333,   334,   335,   330,
     281,   626,     0,     0,   394,     0,   626,   220,   217,   218,
     341,   626,   626,   626,     0,   279,     0,   271,     0,   275,
       0,   269,     0,   273,   263,   264,   265,   266,   267,   261,
     276,   277,   587,   589,   594,   591,     0,     0,   375,     0,
     373,     0,   370,     0,   398,   626,   367,   339,   336,   337,
     283,   282,   278,     0,     0,     0,     0,     0,   595,     0,
     626,   626,     0,   380,   371,   369,   377,   378,     0,   397,
     400,   463,   366,   280,   270,   274,   268,   272,   608,   593,
       0,     0,   374,   372,   379,   385,     0,   382,     0,   396,
     626,     0,   465,   508,     0,     0,     0,   605,     0,   607,
       0,   602,   596,   597,   598,   599,   600,   376,     0,   381,
     383,   395,     0,   406,   404,   399,   402,   403,   626,     0,
     510,   553,     0,   612,   613,   592,   609,   610,   611,     0,
       0,     0,     0,     0,   393,     0,   391,     0,   386,   387,
     388,   384,   626,     0,   416,     0,   471,   469,   464,   467,
     468,   626,     0,     0,     0,   614,     0,   604,   606,   603,
     392,     0,     0,   401,   626,     0,     0,   426,   626,     0,
     481,     0,   516,   514,   509,   512,   513,     0,     0,   584,
     368,     0,   601,   390,   389,     0,   410,   408,   626,     0,
       0,   434,   466,   626,     0,     0,   626,     0,   526,     0,
     558,   555,   615,   626,     0,     0,   420,   418,   626,     0,
       0,     0,   475,   473,   470,   484,   482,   485,   511,   626,
       0,     0,   556,     0,   409,   407,     0,   411,   626,     0,
       0,   430,   428,   438,   405,   435,   440,   626,     0,     0,
       0,   520,   518,   515,   529,   527,   530,     0,   562,   554,
     559,   626,     0,   419,   417,     0,   421,   626,     0,   436,
     439,   474,     0,   472,   476,   500,   498,   626,     0,   497,
       0,   494,     0,   492,   486,   487,   488,   489,   490,   483,
     626,     0,     0,   557,   563,     0,     0,   626,     0,   429,
     427,     0,   431,     0,   626,     0,   452,     0,   449,     0,
     447,   441,   442,   443,   444,   445,   626,     0,     0,     0,
     626,   626,   626,   519,     0,   517,   521,   545,   543,   626,
       0,   542,     0,   539,     0,   537,   531,   532,   533,   534,
     535,   528,   576,   561,     0,   626,   414,   415,     0,     0,
       0,   424,   626,     0,   455,   453,   437,     0,   626,   626,
     626,     0,     0,   503,   499,   501,     0,   626,   496,   495,
     493,   626,     0,     0,     0,   626,   626,   626,     0,     0,
       0,   573,     0,   575,     0,   570,   564,   565,   566,   567,
     568,   413,   412,   626,     0,   423,     0,     0,     0,   626,
     451,   450,   448,   626,   479,   480,     0,   626,     0,   491,
       0,     0,   548,   544,   546,     0,   626,   541,   540,   538,
       0,   580,   581,   560,   577,   578,   579,     0,     0,     0,
     626,   425,   422,   626,     0,   454,   458,   456,     0,   446,
     478,   477,     0,     0,   507,   502,   626,   525,   524,     0,
     626,     0,   536,   582,     0,   572,   574,   571,   433,   432,
     626,     0,   626,   619,   620,   621,   506,     0,   523,   522,
       0,     0,   552,   547,     0,   569,     0,     0,   462,   457,
     504,   505,   626,   551,     0,   583,   626,   461,     0,   549,
     550,   459,   460
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    31,    65,    66,
      67,    68,    69,    70,   116,   117,   118,   168,   169,   170,
     265,   346,   347,   348,   349,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    72,   124,   125,   126,   180,   181,
     182,   269,   357,   358,   359,   360,   361,    13,    41,    80,
      81,    82,   362,    83,   129,   189,   190,   191,   273,    84,
      85,   130,   196,   197,   198,   278,    86,    87,   131,   203,
     204,   205,   283,    88,    89,   134,   135,   288,    90,    91,
     137,   211,   212,   213,   292,   293,   294,   375,   457,   458,
     459,   460,   461,    18,    92,   145,   146,   147,   148,   149,
     150,   151,   152,   225,   310,   311,   312,   384,   385,   386,
     465,   516,   517,   518,   519,   520,    45,   153,   238,   239,
     240,   241,   242,   243,   244,   326,   406,   477,   528,   570,
     594,   595,   596,   597,   598,   599,   600,   601,   623,   245,
     328,   415,   416,   417,   484,   246,   327,   410,   480,   247,
     329,   422,   423,   424,   489,   248,   330,   429,   430,   431,
     494,   249,   318,   394,   395,   396,   471,   472,   522,   565,
     566,   567,   568,   569,    96,   154,   256,   257,   258,   259,
     260,   261,   331,   332,   435,   436,   499,   547,   548,   549,
     550,   574,   611,   612,   635,   636,   637,   656,   657,   678,
     708,   709,   710,   711,   614,   641,   661,   685,   686,   687,
     714,   735,   774,   797,   822,   908,   737,   759,   799,   826,
     858,   761,   779,   828,   862,   913,   780,   805,   863,   806,
     829,   830,   871,   872,   873,   874,   875,   916,   958,   997,
     998,  1021,  1039,   663,   689,   718,   719,   720,   740,   764,
     808,   834,   877,   966,   765,   786,   787,   809,   844,   845,
     846,   847,   848,   849,   878,   925,   926,   968,  1005,   691,
     722,   744,   745,   746,   768,   790,   851,   886,   932,  1009,
     791,   815,   816,   852,   896,   897,   898,   899,   900,   901,
     933,   974,   975,  1011,  1033,   724,   748,   817,   793,   820,
     854,   904,   946,   947,   948,   949,   950,   938,   984,   985,
     986,  1034,   750,   437,   498,   543,   572,   605,   628,   650,
     672,   673,   674,   675,   676,   664,   696,   697,   698,   751,
     302,   120,  1027,   177,   121
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -904
static const yytype_int16 yypact[] =
{
      64,    40,    66,    62,  -904,    60,  -904,   147,   116,  -904,
    -904,  -904,   154,   131,   -36,  -904,  -904,   266,   133,  -904,
    -904,   319,   334,   347,  -904,   349,   351,   353,   355,  -904,
    -904,   238,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
     189,   118,  -904,  -904,   357,   129,    29,  -904,    31,  -904,
      27,  -904,    33,  -904,    10,  -904,     8,  -904,     7,  -904,
     209,   239,  -904,   243,  -904,   360,   238,  -904,  -904,  -904,
    -904,  -904,   365,  -904,  -904,  -904,  -904,  -904,  -904,   370,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   191,
    -904,   259,   -17,  -904,  -904,  -904,   284,   205,  -904,   260,
    -904,   241,  -904,   253,  -904,   256,  -904,   255,  -904,   264,
    -904,   426,  -904,  -904,   -49,  -904,  -904,  -904,  -904,  -904,
     428,    13,   109,  -904,  -904,  -904,  -904,    16,  -904,    41,
     123,   164,   455,  -904,   480,  -904,  -904,   376,  -904,   378,
     380,  -904,   382,   387,   389,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,   468,   -33,   310,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,   483,  -904,  -904,  -904,  -904,   -47,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
     132,  -904,  -904,   339,  -904,   395,   489,  -904,   490,  -904,
    -904,  -904,   397,   491,  -904,   492,  -904,  -904,  -904,   399,
     493,  -904,   494,  -904,  -904,  -904,  -904,   495,   496,   157,
    -904,  -904,  -904,  -904,    11,  -904,    30,  -904,     9,  -904,
       3,  -904,     2,  -904,  -904,   398,  -904,   400,   402,   479,
     404,   406,   408,   474,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,   262,  -904,  -904,  -904,   196,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   433,  -904,
    -904,  -904,  -904,   439,  -904,  -904,  -904,  -904,   435,  -904,
    -904,  -904,   193,  -904,  -904,   430,  -904,   432,  -904,  -904,
    -904,  -904,   384,   364,  -904,   361,  -904,   503,   197,  -904,
    -904,  -904,  -904,    26,  -904,    22,  -904,  -904,   410,    19,
    -904,     6,  -904,     5,  -904,   502,   412,   251,   166,   215,
     217,   456,   -53,   506,   508,   510,   511,  -904,  -904,  -904,
    -904,   385,  -904,   518,  -904,   519,  -904,  -904,  -904,  -904,
     416,  -904,   521,  -904,   522,   523,  -904,  -904,  -904,  -904,
    -904,  -904,   458,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,   199,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,   213,  -904,  -904,   465,  -904,   443,
    -904,   525,   218,  -904,  -904,  -904,  -904,   415,  -904,   403,
    -904,   396,  -904,   527,  -904,  -904,  -904,   418,   532,  -904,
    -904,   420,   533,  -904,   534,  -904,  -904,  -904,   422,   535,
    -904,   536,  -904,  -904,  -904,   424,   537,  -904,   538,  -904,
    -904,  -904,  -904,   520,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,   539,   541,  -904,  -904,  -904,  -904,  -904,
     437,  -904,   542,  -904,   543,   547,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,   211,  -904,  -904,  -904,  -904,
    -904,   219,  -904,  -904,  -904,  -904,   544,   -38,  -904,  -904,
     393,  -904,  -904,  -904,   405,  -904,  -904,  -904,  -904,   401,
    -904,  -904,  -904,  -904,   407,  -904,  -904,  -904,   425,    36,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   448,
    -904,   548,  -904,   550,   554,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,   224,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
     552,  -904,  -904,  -904,   434,  -904,   556,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   453,  -904,
     558,  -904,   560,   562,  -904,  -904,  -904,  -904,  -904,  -904,
     249,  -904,    88,   268,   470,   561,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,    12,  -904,   565,  -904,   566,  -904,
     567,  -904,   568,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,   564,   570,  -904,   571,
    -904,    44,  -904,   427,   413,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,   441,   569,   573,   574,   575,   429,   572,
    -904,  -904,   212,  -904,  -904,  -904,  -904,  -904,    28,  -904,
     563,   485,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
     277,   578,  -904,  -904,  -904,  -904,   220,  -904,   482,  -904,
    -904,   431,   576,   509,   -13,   580,   586,  -904,   587,  -904,
     588,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   257,  -904,
    -904,  -904,   589,   445,  -904,  -904,  -904,  -904,  -904,   436,
     579,   481,   592,  -904,  -904,  -904,  -904,  -904,  -904,   593,
     584,   590,   594,   469,  -904,   600,  -904,   602,  -904,  -904,
    -904,  -904,  -904,   581,   454,   604,   459,  -904,  -904,  -904,
    -904,  -904,   438,   591,   488,  -904,   598,  -904,  -904,  -904,
    -904,   606,   608,  -904,  -904,   440,   582,   545,  -904,   603,
    -904,   613,   540,  -904,  -904,  -904,  -904,   612,   442,  -904,
    -904,   577,  -904,  -904,  -904,   615,  -904,  -904,  -904,   444,
     597,  -904,  -904,  -904,   446,   -39,  -904,   616,  -904,   619,
    -904,  -904,  -904,  -904,   192,   621,  -904,  -904,  -904,   450,
     -68,   623,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
     452,   -10,  -904,   240,  -904,  -904,   601,  -904,  -904,   306,
     625,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   -59,   160,
     626,  -904,  -904,  -904,  -904,  -904,  -904,   627,  -904,  -904,
    -904,  -904,   624,  -904,  -904,   609,  -904,  -904,   -67,  -904,
     307,  -904,   610,  -904,  -904,  -904,  -904,  -904,   630,  -904,
     634,  -904,   637,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,    42,   179,  -904,   457,   635,   466,  -904,   464,  -904,
    -904,   614,  -904,   467,  -904,   639,  -904,   641,  -904,   642,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,   638,    32,   643,
    -904,  -904,  -904,  -904,   618,  -904,  -904,  -904,  -904,  -904,
     647,  -904,   649,  -904,   650,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,   283,  -904,  -904,  -904,   497,   651,
      -1,  -904,  -904,   645,  -904,  -904,  -904,   653,  -904,  -904,
    -904,   654,   473,  -904,  -904,  -904,   633,  -904,  -904,  -904,
    -904,  -904,   646,   -19,   657,  -904,  -904,  -904,    43,   656,
     662,  -904,   664,  -904,   665,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,   512,  -904,   663,   666,   -58,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,   583,  -904,   471,  -904,
     668,   477,  -904,  -904,  -904,   652,  -904,  -904,  -904,  -904,
     667,  -904,  -904,  -904,  -904,  -904,  -904,   669,   670,   671,
    -904,  -904,  -904,  -904,   515,  -904,  -904,  -904,   655,  -904,
    -904,  -904,   674,    21,  -904,  -904,  -904,  -904,  -904,   611,
    -904,   475,  -904,  -904,   675,  -904,  -904,  -904,  -904,  -904,
    -904,   478,  -904,  -904,  -904,  -904,  -904,   595,  -904,  -904,
     679,    37,  -904,  -904,   628,  -904,   683,    -2,  -904,  -904,
    -904,  -904,  -904,  -904,   620,  -904,  -904,  -904,   529,  -904,
    -904,  -904,  -904
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
     605,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   524,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   513,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,   409,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,   312,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,   227,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,    80,  -904,  -904,  -904,  -904,    46,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,  -904,
    -904,  -112,  -903,  -904,  -904
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     164,   165,  1023,   954,  1024,  1025,   860,   303,   305,   401,
     399,   109,   107,    19,   105,   299,   300,   295,   620,   621,
     183,   172,   226,   397,   208,  1023,   389,  1024,  1025,   227,
     387,   101,   658,    97,   297,    99,   138,   103,   803,   832,
     166,  1023,   263,  1024,  1025,   692,   544,   693,   694,   995,
       4,   185,    20,   228,   632,   633,    21,   972,    22,   266,
      23,   433,   784,   139,   545,   140,     6,   785,   606,   813,
       9,   434,    24,   186,   187,   229,   607,   608,   546,   188,
     609,   610,    25,   230,    26,   167,     5,   167,   973,   388,
      27,   141,   296,   861,   286,   804,   814,   231,   833,   232,
     526,   980,   996,   981,   982,   142,    28,   527,     1,   390,
       7,   233,   307,   298,  1043,   234,   695,   235,   884,   236,
    1026,   237,    98,   143,   102,   659,   100,   885,  1044,   144,
     923,   106,   301,   192,  1048,   108,   398,   400,   402,   924,
     333,   334,   335,   336,   304,   337,   338,   339,   340,   306,
     110,   622,   104,   184,   983,   193,   194,    10,    11,  1047,
     955,   195,   363,   364,    15,    16,    12,   366,   367,    73,
     835,   836,   369,   370,   199,   837,   411,   372,   173,   174,
     175,   176,    74,    17,    75,    95,    76,    44,    77,   887,
     888,   889,   838,   839,   840,   841,   200,   201,   412,   413,
     842,   843,   202,   603,   414,   391,   350,   351,    71,   450,
     451,   890,   891,   892,   893,   178,   604,   111,   179,   894,
     895,   509,   510,   132,   133,   418,    78,   425,   352,   353,
     354,   452,   453,   454,   558,   559,   355,   356,   178,   455,
     456,   267,   112,   511,   512,   513,   113,   419,   420,   426,
     427,   514,   515,   421,    79,   428,   560,   561,   562,   584,
     585,   407,    60,   290,   563,   564,   291,   703,   704,   462,
      61,    62,   341,   342,    63,    64,    42,    43,   136,   586,
     587,   588,   589,   408,   409,   590,   591,   592,   593,   705,
     706,   665,   606,   707,   343,   344,   345,   939,   156,   290,
     607,   608,   373,   382,   609,   610,   383,   666,   667,   668,
     669,   670,   671,   940,   941,   942,   943,   944,   945,   382,
     250,   251,   463,   252,   469,   469,   253,   470,   523,    46,
      47,   155,   254,   864,   502,   503,   504,   255,   158,   865,
     866,   867,   868,   654,    48,    49,   655,   869,   870,   795,
     818,   679,   796,   819,   655,   157,   521,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    93,    94,   530,
     114,   115,   159,   532,   533,   122,   123,   160,   535,   536,
     127,   128,   161,   538,   539,   540,   209,   210,   214,   215,
     216,   217,   218,   219,   551,   552,   553,   220,   221,   222,
     223,   271,   272,   276,   277,   281,   282,   162,   308,   309,
     313,   314,   315,   316,   319,   320,   321,   322,   323,   324,
     392,   393,   404,   405,   478,   479,   482,   483,   487,   488,
     492,   493,   163,   575,   171,   541,   542,   638,   639,   648,
     649,   683,   684,   577,   578,   579,   716,   717,   742,   743,
     756,   757,   770,   771,   776,   777,   782,   783,   206,   602,
     801,   802,   811,   812,   616,   824,   825,   902,   903,   617,
     618,   619,   906,   907,   910,   911,   270,   914,   915,   964,
     965,  1003,  1004,  1007,  1008,  1031,  1032,   224,  1037,  1038,
     207,   262,   274,   275,   279,   280,   284,   285,   317,   325,
     371,   287,   289,   642,   365,   379,   368,   378,   380,   381,
     403,   376,   438,   432,   439,   377,   440,   441,   652,   653,
     442,   443,   444,   445,   446,   447,   448,   449,   466,   475,
     467,   468,   473,   476,   474,   481,   485,   486,   490,   491,
     495,   496,   529,   497,   505,   506,   507,   500,   682,   501,
     508,   555,   525,   556,   534,   554,   531,   557,   571,   576,
     580,   581,   537,   582,   573,   583,   613,   615,   624,   625,
     626,   627,   629,   630,   631,   640,   715,   644,   651,   681,
     643,   645,   646,   647,   660,   662,   677,   690,   699,   700,
     701,   702,   727,   723,   688,   712,   721,   725,   728,   726,
     733,   713,   729,   731,   730,   732,   752,   734,   758,   741,
     738,   747,   736,   749,   753,   739,   754,   760,   763,   766,
     769,   773,   755,   778,   767,   792,   762,   798,   789,   807,
     821,   827,   850,   880,   856,   853,   772,   881,   857,   876,
     882,   905,   918,   912,   919,   920,   775,   931,   922,   927,
     935,   781,   936,   937,   788,   957,   971,   953,   952,   959,
     963,   794,   967,   976,   987,   988,   800,   989,   990,   993,
     994,   119,  1013,   992,  1006,  1014,  1019,   810,  1015,  1016,
    1022,  1010,  1001,  1035,  1020,  1042,   823,  1045,  1029,  1046,
    1052,   634,   264,   268,  1041,   831,   464,  1050,   524,     0,
       0,   374,   680,     0,     0,     0,     0,     0,     0,   855,
       0,     0,     0,     0,     0,   859,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   879,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   883,     0,
       0,     0,     0,     0,     0,   909,     0,     0,     0,     0,
       0,     0,   917,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   921,     0,     0,     0,   928,   929,
     930,     0,     0,     0,     0,     0,     0,   934,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   951,     0,     0,     0,     0,     0,     0,
     956,     0,     0,     0,     0,     0,   960,   961,   962,     0,
       0,     0,     0,     0,     0,   969,     0,     0,     0,   970,
       0,     0,     0,   977,   978,   979,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   991,     0,     0,     0,     0,     0,   999,     0,     0,
       0,  1000,     0,     0,     0,  1002,     0,     0,     0,     0,
       0,     0,     0,     0,  1012,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1017,     0,
       0,  1018,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1028,     0,     0,     0,  1030,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1036,     0,
    1040,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1049,     0,     0,     0,  1051
};

static const yytype_int16 yycheck[] =
{
     112,   113,     4,     4,     6,     7,    73,     4,     6,     4,
       4,     4,     4,    49,     4,     6,     7,     6,     6,     7,
       4,     8,    55,     4,   136,     4,     4,     6,     7,    62,
       4,     4,     4,     4,     4,     4,    53,     4,   106,    98,
      89,     4,    89,     6,     7,    58,    10,    60,    61,   107,
      10,    10,    88,    86,    10,    11,    92,    76,    94,   171,
      96,   114,   101,    80,    28,    82,     0,   106,    24,    79,
      10,   124,   108,    32,    33,   108,    32,    33,    42,    38,
      36,    37,   118,   116,   120,   134,    46,   134,   107,    63,
     126,   108,    81,   160,   206,   163,   106,   130,   157,   132,
     138,    58,   160,    60,    61,   122,   142,   145,    44,    87,
      48,   144,   224,    83,    77,   148,   129,   150,    76,   152,
      99,   154,    93,   140,    97,    97,    95,    85,  1031,   146,
      98,   121,   123,    10,  1037,   127,   117,   131,   133,   107,
     252,   253,   254,   255,   141,   257,   258,   259,   260,   147,
     143,   139,   119,   137,   111,    32,    33,    10,    11,   161,
     161,    38,   274,   275,    10,    11,    50,   279,   280,    51,
      10,    11,   284,   285,    10,    15,    10,   289,   165,   166,
     167,   168,    64,    52,    66,    56,    68,    54,    70,    10,
      11,    12,    32,    33,    34,    35,    32,    33,    32,    33,
      40,    41,    38,   115,    38,   317,    10,    11,    19,    10,
      11,    32,    33,    34,    35,   106,   128,     8,   109,    40,
      41,    10,    11,    32,    33,    10,   108,    10,    32,    33,
      34,    32,    33,    34,    10,    11,    40,    41,   106,    40,
      41,   109,     3,    32,    33,    34,     3,    32,    33,    32,
      33,    40,    41,    38,   136,    38,    32,    33,    34,    10,
      11,    10,    24,   106,    40,    41,   109,    10,    11,   381,
      32,    33,    10,    11,    36,    37,    10,    11,    19,    30,
      31,    32,    33,    32,    33,    36,    37,    38,    39,    32,
      33,    14,    24,    36,    32,    33,    34,    14,    93,   106,
      32,    33,   109,   106,    36,    37,   109,    30,    31,    32,
      33,    34,    35,    30,    31,    32,    33,    34,    35,   106,
      10,    11,   109,    13,   106,   106,    16,   109,   109,    10,
      11,    47,    22,    26,   446,   447,   448,    27,    97,    32,
      33,    34,    35,   131,    10,    11,   134,    40,    41,   157,
     110,   131,   160,   113,   134,    95,   468,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   481,
      10,    11,   119,   485,   486,    10,    11,   121,   490,   491,
      10,    11,   127,   495,   496,   497,    10,    11,    10,    11,
      10,    11,    10,    11,   506,   507,   508,    10,    11,    10,
      11,     6,     7,     6,     7,     6,     7,   143,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,     6,     7,     6,     7,     6,     7,
       6,     7,     6,   545,     6,    10,    11,    10,    11,    10,
      11,    10,    11,   555,   556,   557,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,     3,   571,
      10,    11,    10,    11,   576,   159,   160,    10,    11,   581,
     582,   583,     6,     7,    10,    11,   137,    10,    11,     6,
       7,    10,    11,     6,     7,    10,    11,    19,    10,    11,
      10,     8,     3,     3,     3,     3,     3,     3,    19,    25,
      65,     6,     6,   615,    71,   141,    67,   123,   147,     6,
       8,    81,     6,    57,     6,    83,     6,     6,   630,   631,
     135,     3,     3,   107,     3,     3,     3,    69,    63,   133,
      87,     6,   117,     6,   131,     3,     3,     3,     3,     3,
       3,     3,   149,    23,   107,     3,     3,     8,   660,     8,
       3,     3,     8,     3,   153,   107,   151,     3,     6,     3,
     107,     3,   155,     3,   130,     3,    96,     6,     3,     3,
       3,     3,     8,     3,     3,   162,   688,     8,     6,    97,
     139,     8,     8,     8,    21,   100,     8,    78,     8,     3,
       3,     3,     8,   112,    18,     6,    17,     5,     8,     6,
     712,   156,     8,     3,   135,     3,     8,    26,    26,   721,
       6,    20,   158,   125,     8,   156,     8,    72,    15,     6,
       8,     6,   734,    26,    84,     6,   738,     6,    12,     6,
      29,     6,     6,     3,    10,     8,    59,     3,    29,    29,
       3,     6,     3,    29,     3,     3,   758,    29,    10,     6,
       3,   763,     3,     3,   766,    10,    10,     6,   161,     6,
       6,   773,    29,     6,     8,     3,   778,     3,     3,     6,
       4,    66,     5,   161,     6,     6,   161,   789,     8,     8,
       6,    29,    99,     8,    29,     6,   798,    59,    77,     6,
     161,   611,   168,   180,    99,   807,   384,    77,   471,    -1,
      -1,   292,   656,    -1,    -1,    -1,    -1,    -1,    -1,   821,
      -1,    -1,    -1,    -1,    -1,   827,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   837,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   850,    -1,
      -1,    -1,    -1,    -1,    -1,   857,    -1,    -1,    -1,    -1,
      -1,    -1,   864,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   876,    -1,    -1,    -1,   880,   881,
     882,    -1,    -1,    -1,    -1,    -1,    -1,   889,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   905,    -1,    -1,    -1,    -1,    -1,    -1,
     912,    -1,    -1,    -1,    -1,    -1,   918,   919,   920,    -1,
      -1,    -1,    -1,    -1,    -1,   927,    -1,    -1,    -1,   931,
      -1,    -1,    -1,   935,   936,   937,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   953,    -1,    -1,    -1,    -1,    -1,   959,    -1,    -1,
      -1,   963,    -1,    -1,    -1,   967,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   976,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   990,    -1,
      -1,   993,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1006,    -1,    -1,    -1,  1010,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1020,    -1,
    1022,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1042,    -1,    -1,    -1,  1046
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   216,   173,    10,    11,    52,   262,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   176,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   217,    10,    11,    54,   285,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      24,    32,    33,    36,    37,   177,   178,   179,   180,   181,
     182,    19,   203,    51,    64,    66,    68,    70,   108,   136,
     218,   219,   220,   222,   228,   229,   235,   236,   242,   243,
     247,   248,   263,    10,    11,    56,   343,     4,    93,     4,
      95,     4,    97,     4,   119,     4,   121,     4,   127,     4,
     143,     8,     3,     3,    10,    11,   183,   184,   185,   179,
     500,   503,    10,    11,   204,   205,   206,    10,    11,   223,
     230,   237,    32,    33,   244,   245,    19,   249,    53,    80,
      82,   108,   122,   140,   146,   264,   265,   266,   267,   268,
     269,   270,   271,   286,   344,    47,    93,    95,    97,   119,
     121,   127,   143,     6,   500,   500,    89,   134,   186,   187,
     188,     6,     8,   165,   166,   167,   168,   502,   106,   109,
     207,   208,   209,     4,   137,    10,    32,    33,    38,   224,
     225,   226,    10,    32,    33,    38,   231,   232,   233,    10,
      32,    33,    38,   238,   239,   240,     3,    10,   500,    10,
      11,   250,   251,   252,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    19,   272,    55,    62,    86,   108,
     116,   130,   132,   144,   148,   150,   152,   154,   287,   288,
     289,   290,   291,   292,   293,   308,   314,   318,   324,   330,
      10,    11,    13,    16,    22,    27,   345,   346,   347,   348,
     349,   350,     8,    89,   187,   189,   500,   109,   208,   210,
     137,     6,     7,   227,     3,     3,     6,     7,   234,     3,
       3,     6,     7,   241,     3,     3,   500,     6,   246,     6,
     106,   109,   253,   254,   255,     6,    81,     4,    83,     6,
       7,   123,   499,     4,   141,     6,   147,   500,    10,    11,
     273,   274,   275,    10,    11,    10,    11,    19,   331,    10,
      11,    10,    11,    10,    11,    25,   294,   315,   309,   319,
     325,   351,   352,   500,   500,   500,   500,   500,   500,   500,
     500,    10,    11,    32,    33,    34,   190,   191,   192,   193,
      10,    11,    32,    33,    34,    40,    41,   211,   212,   213,
     214,   215,   221,   500,   500,    71,   500,   500,    67,   500,
     500,    65,   500,   109,   254,   256,    81,    83,   123,   141,
     147,     6,   106,   109,   276,   277,   278,     4,    63,     4,
      87,   500,    10,    11,   332,   333,   334,     4,   117,     4,
     131,     4,   133,     8,    10,    11,   295,    10,    32,    33,
     316,    10,    32,    33,    38,   310,   311,   312,    10,    32,
      33,    38,   320,   321,   322,    10,    32,    33,    38,   326,
     327,   328,    57,   114,   124,   353,   354,   482,     6,     6,
       6,     6,   135,     3,     3,   107,     3,     3,     3,    69,
      10,    11,    32,    33,    34,    40,    41,   257,   258,   259,
     260,   261,   500,   109,   277,   279,    63,    87,     6,   106,
     109,   335,   336,   117,   131,   133,     6,   296,     6,     7,
     317,     3,     6,     7,   313,     3,     3,     6,     7,   323,
       3,     3,     6,     7,   329,     3,     3,    23,   483,   355,
       8,     8,   500,   500,   500,   107,     3,     3,     3,    10,
      11,    32,    33,    34,    40,    41,   280,   281,   282,   283,
     284,   500,   337,   109,   336,     8,   138,   145,   297,   149,
     500,   151,   500,   500,   153,   500,   500,   155,   500,   500,
     500,    10,    11,   484,    10,    28,    42,   356,   357,   358,
     359,   500,   500,   500,   107,     3,     3,     3,    10,    11,
      32,    33,    34,    40,    41,   338,   339,   340,   341,   342,
     298,     6,   485,   130,   360,   500,     3,   500,   500,   500,
     107,     3,     3,     3,    10,    11,    30,    31,    32,    33,
      36,    37,    38,    39,   299,   300,   301,   302,   303,   304,
     305,   306,   500,   115,   128,   486,    24,    32,    33,    36,
      37,   361,   362,    96,   373,     6,   500,   500,   500,   500,
       6,     7,   139,   307,     3,     3,     3,     3,   487,     8,
       3,     3,    10,    11,   362,   363,   364,   365,    10,    11,
     162,   374,   500,   139,     8,     8,     8,     8,    10,    11,
     488,     6,   500,   500,   131,   134,   366,   367,     4,    97,
      21,   375,   100,   412,   494,    14,    30,    31,    32,    33,
      34,    35,   489,   490,   491,   492,   493,     8,   368,   131,
     367,    97,   500,    10,    11,   376,   377,   378,    18,   413,
      78,   438,    58,    60,    61,   129,   495,   496,   497,     8,
       3,     3,     3,    10,    11,    32,    33,    36,   369,   370,
     371,   372,     6,   156,   379,   500,    10,    11,   414,   415,
     416,    17,   439,   112,   464,     5,     6,     8,     8,     8,
     135,     3,     3,   500,    26,   380,   158,   385,     6,   156,
     417,   500,    10,    11,   440,   441,   442,    20,   465,   125,
     481,   498,     8,     8,     8,   500,    10,    11,    26,   386,
      72,   390,   500,    15,   418,   423,     6,    84,   443,     8,
      10,    11,    59,     6,   381,   500,    10,    11,    26,   391,
     395,   500,    10,    11,   101,   106,   424,   425,   500,    12,
     444,   449,     6,   467,   500,   157,   160,   382,     6,   387,
     500,    10,    11,   106,   163,   396,   398,     6,   419,   426,
     500,    10,    11,    79,   106,   450,   451,   466,   110,   113,
     468,    29,   383,   500,   159,   160,   388,     6,   392,   399,
     400,   500,    98,   157,   420,    10,    11,    15,    32,    33,
      34,    35,    40,    41,   427,   428,   429,   430,   431,   432,
       6,   445,   452,     8,   469,   500,    10,    29,   389,   500,
      73,   160,   393,   397,    26,    32,    33,    34,    35,    40,
      41,   401,   402,   403,   404,   405,    29,   421,   433,   500,
       3,     3,     3,   500,    76,    85,   446,    10,    11,    12,
      32,    33,    34,    35,    40,    41,   453,   454,   455,   456,
     457,   458,    10,    11,   470,     6,     6,     7,   384,   500,
      10,    11,    29,   394,    10,    11,   406,   500,     3,     3,
       3,   500,    10,    98,   107,   434,   435,     6,   500,   500,
     500,    29,   447,   459,   500,     3,     3,     3,   476,    14,
      30,    31,    32,    33,    34,    35,   471,   472,   473,   474,
     475,   500,   161,     6,     4,   161,   500,    10,   407,     6,
     500,   500,   500,     6,     6,     7,   422,    29,   436,   500,
     500,    10,    76,   107,   460,   461,     6,   500,   500,   500,
      58,    60,    61,   111,   477,   478,   479,     8,     3,     3,
       3,   500,   161,     6,     4,   107,   160,   408,   409,   500,
     500,    99,   500,    10,    11,   437,     6,     6,     7,   448,
      29,   462,   500,     5,     6,     8,     8,   500,   500,   161,
      29,   410,     6,     4,     6,     7,    99,   501,   500,    77,
     500,    10,    11,   463,   480,     8,   500,    10,    11,   411,
     500,    99,     6,    77,   501,    59,     6,   161,   501,   500,
      77,   500,   161
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

  case 109:

    {std::cout << "Matched availableDiskSpaceValue" << std::endl;;}
    break;

  case 111:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;		
	;}
    break;

  case 116:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "petabyte" && parserData->tempStr != "terabyte" 
	&& parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "availableDiskSpace unit not recognized");
	osresult->setAvailableDiskSpaceUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 117:

    {	osresult->setAvailableDiskSpaceDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 119:

    {std::cout << std::endl << "matched available disk space: INTEGER" << std::endl; osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 120:

    {std::cout << std::endl << "matched available disk space: DOUBLE"  << std::endl; osresult->setAvailableDiskSpaceValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 122:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
	;}
    break;

  case 127:

    {	parserData->tempStr = (yyvsp[(2) - (3)].sval); free ((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr != "terabyte" && parserData->tempStr != "gigabyte" && 
		parserData->tempStr != "megabyte" && parserData->tempStr != "kilobyte" && parserData->tempStr != "byte")
		osrlerror(NULL, NULL, parserData, "availableMemory unit not recognized");
	osresult->setAvailableMemoryUnit( parserData->tempStr);/* free($2); */ parserData->errorText = NULL;
;}
    break;

  case 128:

    {	osresult->setAvailableMemoryDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 130:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 131:

    {osresult->setAvailableMemoryValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 133:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
	;}
    break;

  case 138:

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

  case 139:

    {	osresult->setAvailableCPUSpeedDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 141:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 142:

    {osresult->setAvailableCPUSpeedValue( (yyvsp[(1) - (1)].dval));  parserData->errorText = NULL;;}
    break;

  case 144:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
	;}
    break;

  case 147:

    {	osresult->setAvailableCPUNumberDescription( (yyvsp[(2) - (3)].sval)); free((yyvsp[(2) - (3)].sval));  parserData->errorText = NULL;;}
    break;

  case 149:

    {osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;;}
    break;

  case 150:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 152:

    {	osresult->setNumberOfOtherSystemResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 160:

    {	if (!parserData->systemOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->systemOtherResultNamePresent = false;
	parserData->systemOtherResultValuePresent = false;
	parserData->systemOtherResultDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 161:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 164:

    {	if (parserData->systemOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->systemOtherResultNamePresent = true;
		osresult->setSystemOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 165:

    {	if (parserData->systemOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->systemOtherResultValuePresent = true;
		osresult->setSystemOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 166:

    {	if (parserData->systemOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->systemOtherResultDescriptionPresent = true;
		osresult->setSystemOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 167:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 168:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 169:

    {parserData->tempStr = "";}
    break;

  case 170:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 171:

    {parserData->tempStr = "";}
    break;

  case 179:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 180:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 181:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 182:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 183:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 184:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	;}
    break;

  case 185:

    {osresult->setCurrentState( (yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 188:

    {osresult->setCurrentJobCount( (yyvsp[(3) - (4)].ival)); /* free($3); */  parserData->errorText = NULL;;}
    break;

  case 191:

    {osresult->setTotalJobsSoFar( (yyvsp[(3) - (4)].ival)); /* free($3); */  parserData->errorText = NULL;;}
    break;

  case 194:

    {osresult->setTimeServiceStarted( (yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 197:

    {osresult->setServiceUtilization( parserData->tempVal);  parserData->errorText = NULL;;}
    break;

  case 200:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, "fewer <other> elements than specified");
	;}
    break;

  case 202:

    {	osresult->setNumberOfOtherServiceResults((yyvsp[(3) - (4)].ival));
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
;}
    break;

  case 210:

    {	if (!parserData->serviceOtherResultNamePresent)
		osrlerror (NULL, NULL, parserData, "<other> must have name attribute");
	parserData->serviceOtherResultNamePresent = false;
	parserData->serviceOtherResultValuePresent = false;
	parserData->serviceOtherResultDescriptionPresent = false;
	parserData->kounter++;
;}
    break;

  case 211:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, "more <other> elements than specified");
;}
    break;

  case 214:

    {	if (parserData->serviceOtherResultNamePresent)
			osrlerror(NULL, NULL, parserData, "name attribute multiply specified");
		parserData->serviceOtherResultNamePresent = true;
		osresult->setServiceOtherResultName(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 215:

    {	if (parserData->serviceOtherResultValuePresent)
			osrlerror(NULL, NULL, parserData, "value attribute multiply specified");
		parserData->serviceOtherResultValuePresent = true;
		osresult->setServiceOtherResultValue(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 216:

    {	if (parserData->serviceOtherResultDescriptionPresent)
			osrlerror(NULL, NULL, parserData, "description attribute multiply specified");
		parserData->serviceOtherResultDescriptionPresent = true;
		osresult->setServiceOtherResultDescription(parserData->kounter,parserData->tempStr);
	;}
    break;

  case 217:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 218:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 219:

    {parserData->tempStr = "";}
    break;

  case 220:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 221:

    {parserData->tempStr = "";;}
    break;

  case 229:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 230:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 231:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 232:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 233:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 234:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 235:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
	;}
    break;

  case 236:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
	;}
    break;

  case 237:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;
	;}
    break;

  case 238:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
	;}
    break;

  case 239:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	;}
    break;

  case 240:

    {osresult->setJobStatus( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 243:

    {osresult->setJobSubmitTime( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 246:

    {osresult->setScheduledStartTime( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 249:

    {osresult->setActualStartTime( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 252:

    {osresult->setJobEndTime( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;;}
    break;

  case 256:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
;}
    break;

  case 268:

    {parserData->timeType = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 270:

    {parserData->timeCategory = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 272:

    {parserData->timeUnit = (yyvsp[(2) - (3)].sval);   free((yyvsp[(2) - (3)].sval));;}
    break;

  case 274:

    {parserData->timeDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 280:

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

  case 282:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 283:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 289:

    {;}
    break;

  case 290:

    {;}
    break;

  case 297:

    {;}
    break;

  case 306:

    {;}
    break;

  case 307:

    {;}
    break;

  case 316:

    {;}
    break;

  case 317:

    {;}
    break;

  case 322:

    {std::cout << "!!!store numberOfOtherjobResults" << std::endl;;}
    break;

  case 351:

    {parserData->numberOfSolutions   = (yyvsp[(3) - (3)].ival); osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 352:

    {parserData->numberOfVariables   = (yyvsp[(3) - (3)].ival); osresult->setVariableNumber((yyvsp[(3) - (3)].ival)); ;}
    break;

  case 353:

    {parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 354:

    {parserData->numberOfObjectives  = (yyvsp[(3) - (3)].ival); osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));;}
    break;

  case 360:

    {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   ;}
    break;

  case 361:

    {   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
;}
    break;

  case 366:

    {
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
/*  	osresult->optimization->solution[parserData->solutionIdx]->targetObjectiveIdx = $3;*/
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 ;}
    break;

  case 367:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 372:

    {parserData->statusType = (yyvsp[(2) - (3)].sval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].sval));;}
    break;

  case 373:

    {parserData->statusType = ""; parserData->statusTypePresent = true;;}
    break;

  case 374:

    {parserData->statusDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 375:

    {parserData->statusDescription = "";;}
    break;

  case 376:

    {;}
    break;

  case 377:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element"); 
		parserData->statusTypePresent = false; 
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	;}
    break;

  case 378:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element");
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	;}
    break;

  case 389:

    { std::cout << "parsed <solutionSubstatus type=" << std::endl;
;}
    break;

  case 395:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = $3; */
		osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
	;}
    break;

  case 396:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = "";*/
		osresult->setSolutionMessage(parserData->solutionIdx, "");
	;}
    break;

  case 401:

    {  
	osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
	;}
    break;

  case 407:

    {
  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  ;}
    break;

  case 408:

    {
  	if(parserData->numberOfVar != 0){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  ;}
    break;

  case 409:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 413:

    { parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 414:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->primalVals.push_back( parserData->primalValPair);  
   ;}
    break;

  case 415:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); 
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->primalVals.push_back( parserData->primalValPair); 
  ;}
    break;

  case 417:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
     }
 */  ;}
    break;

  case 419:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 422:

    {/*parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  */
;}
    break;

  case 425:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 427:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
      }
 */  ;}
    break;

  case 429:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	;}
    break;

  case 433:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/;}
    break;

  case 436:

    {/*	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	*/;}
    break;

  case 437:

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

  case 438:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	;}
    break;

  case 439:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	;}
    break;

  case 446:

    {	
	parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);

//std::cout << "This \<other\> element has " << parserData->otherVarStruct->numberOfVar << " \<var\>" << std::endl;

	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 447:

    {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
;}
    break;

  case 448:

    {parserData->tmpOtherValue=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 449:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 450:

    {
parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 451:

    {
parserData->tmpOtherDescription=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 457:

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

  case 458:

    {//	if(parserData->otherVarStruct->numberOfVar <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	;}
    break;

  case 459:

    {;}
    break;

  case 466:

    {  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 472:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
;}
    break;

  case 474:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 478:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(3) - (4)].ival);   ;}
    break;

  case 479:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].ival);                  
	parserData->objVals.push_back( parserData->objValPair);
;}
    break;

  case 480:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->objVals.push_back( parserData->objValPair);
  ;}
    break;

  case 484:

    {  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	;}
    break;

  case 491:

    {
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
;}
    break;

  case 492:

    {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
;}
    break;

  case 493:

    {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 494:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherObjStruct->name = "";
;}
    break;

  case 495:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 496:

    {
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 499:

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

  case 502:

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

  case 503:

    {//	if(parserData->otherObjStruct->numberOfObj <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of objectives") ;
	;}
    break;

  case 504:

    {;}
    break;

  case 511:

    {  
/*        osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      ;}
    break;

  case 517:

    {/*
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}*/
 ;}
    break;

  case 519:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 523:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(3) - (4)].ival);;}
    break;

  case 524:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 		
	;}
    break;

  case 525:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 	
	;}
    break;

  case 537:

    {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
;}
    break;

  case 538:

    {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));;}
    break;

  case 539:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherConStruct->name = "";
;}
    break;

  case 540:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
;}
    break;

  case 541:

    {
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
;}
    break;

  case 547:

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

  case 548:

    {//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	;}
    break;

  case 549:

    {;}
    break;

  case 554:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 555:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 556:

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

  case 560:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 561:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 563:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 569:

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

  case 570:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
;}
    break;

  case 571:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 572:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 574:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 577:

    {parserData->kounter++;;}
    break;

  case 578:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 579:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 582:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 584:

    {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
;}
    break;

  case 592:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
;}
    break;

  case 595:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/;}
    break;

  case 601:

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

  case 602:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
*/
;}
    break;

  case 603:

    {
/*	parserData->tmpOtherName=$2; parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
;}
    break;

  case 604:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
;}
    break;

  case 606:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
;}
    break;

  case 610:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/;}
    break;

  case 611:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/;}
    break;

  case 614:

    {/*parserData->itemContent = $2; free($2);*/;}
    break;

  case 616:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 617:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 619:

    { parserData->outStr << (yyvsp[(1) - (1)].sval);    free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 620:

    { parserData->outStr << (yyvsp[(1) - (1)].ival);  /*free($1);*/ ;}
    break;

  case 621:

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


