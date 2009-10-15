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
#define YYLAST   1030

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  422
/* YYNRULES -- Number of rules.  */
#define YYNRULES  717
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1152

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
    1474,  1476,  1477,  1481,  1482,  1487,  1489,  1491,  1496,  1497,
    1501,  1503,  1508,  1510,  1512,  1515,  1517,  1521,  1523,  1526,
    1532,  1534,  1539,  1541,  1543,  1544,  1547,  1551,  1553,  1555,
    1556,  1559,  1561,  1563,  1565,  1567,  1572,  1576,  1578,  1582,
    1584,  1591,  1593,  1595,  1599,  1600,  1603,  1607,  1609,  1614,
    1618,  1621,  1623,  1624,  1628,  1629,  1634,  1636,  1638,  1643,
    1644,  1648,  1650,  1655,  1657,  1659,  1662,  1664,  1668,  1670,
    1673,  1679,  1681,  1686,  1688,  1690,  1691,  1694,  1698,  1700,
    1702,  1703,  1706,  1708,  1710,  1712,  1714,  1719,  1723,  1725,
    1729,  1731,  1735,  1737,  1739,  1743,  1744,  1747,  1751,  1753,
    1758,  1762,  1765,  1767,  1768,  1774,  1778,  1779,  1785,  1786,
    1789,  1795,  1799,  1800,  1801,  1805,  1807,  1809,  1811,  1813,
    1818,  1820,  1824,  1828,  1830,  1834,  1836,  1837,  1840,  1842,
    1844,  1846,  1848,  1849,  1854,  1856,  1857,  1861,  1866,  1868,
    1872,  1873,  1876,  1882,  1886,  1887,  1888,  1892,  1894,  1896,
    1898,  1900,  1905,  1907,  1911,  1915,  1917,  1921,  1923,  1924,
    1927,  1929,  1931,  1933,  1935,  1936,  1941,  1943,  1945,  1948,
    1950,  1952,  1954,  1956,  1958,  1960,  1962,  1963
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
     587,    -1,    37,    -1,    32,     3,   587,    -1,    33,    -1,
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
      11,    -1,   217,   218,   219,    -1,   108,    -1,    19,   587,
       6,   587,    -1,   220,    -1,   221,    -1,    10,   109,    -1,
      11,    -1,    10,   222,   109,    -1,   223,    -1,   222,   223,
      -1,   224,   225,   231,    -1,   106,    -1,   226,    -1,    -1,
     226,   227,    -1,   228,    -1,   229,    -1,   230,    -1,    34,
       3,   587,    -1,    40,     3,   587,    -1,    41,    -1,    32,
       3,   587,    -1,    33,    -1,    10,   107,    -1,    11,    -1,
      -1,    50,    11,    -1,    50,    10,   233,    51,    -1,    -1,
     233,   234,    -1,   235,    -1,   238,    -1,   246,    -1,   254,
      -1,   262,    -1,   267,    -1,   236,   237,    -1,   136,    -1,
      10,     4,   137,    -1,    10,   137,    -1,    11,    -1,   239,
     240,    10,   245,    69,    -1,    68,    -1,   241,    -1,    -1,
     241,   242,    -1,   243,    -1,   244,    -1,    38,     3,   587,
      -1,    32,     3,   587,    -1,    33,    -1,     6,    -1,     7,
      -1,   247,   248,    10,   253,    71,    -1,    70,    -1,   249,
      -1,    -1,   249,   250,    -1,   251,    -1,   252,    -1,    38,
       3,   587,    -1,    32,     3,   587,    -1,    33,    -1,     6,
      -1,     7,    -1,   255,   256,    10,   261,    67,    -1,    66,
      -1,   257,    -1,    -1,   257,   258,    -1,   259,    -1,   260,
      -1,    38,     3,   587,    -1,    32,     3,   587,    -1,    33,
      -1,     6,    -1,     7,    -1,   263,   264,    10,   266,    65,
      -1,    64,    -1,    -1,   265,    -1,    32,     3,   587,    -1,
      33,    -1,     6,    -1,   268,   269,   270,    -1,   108,    -1,
      19,   587,     6,   587,    -1,   271,    -1,   272,    -1,    10,
     109,    -1,    11,    -1,    10,   273,   109,    -1,   274,    -1,
     273,   274,    -1,   275,   276,   282,    -1,   106,    -1,   277,
      -1,    -1,   277,   278,    -1,   279,    -1,   280,    -1,   281,
      -1,    34,     3,   587,    -1,    40,     3,   587,    -1,    41,
      -1,    32,     3,   587,    -1,    33,    -1,    10,   107,    -1,
      11,    -1,    -1,    52,    11,    -1,    52,    10,   284,    53,
      -1,    -1,   284,   285,    -1,   286,    -1,   289,    -1,   292,
      -1,   295,    -1,   298,    -1,   301,    -1,   287,   288,    -1,
      82,    -1,    10,     4,    83,    -1,    10,    83,    -1,    11,
      -1,   290,   291,    -1,    80,    -1,    10,     6,    81,    -1,
      10,    81,    -1,    11,    -1,   293,   294,    -1,   146,    -1,
      10,     6,   147,    -1,    10,   147,    -1,    11,    -1,   296,
     297,    -1,   140,    -1,    10,     4,   141,    -1,    10,   141,
      -1,    11,    -1,   299,   300,    -1,   122,    -1,    10,   586,
     123,    -1,    10,   123,    -1,    11,    -1,   302,   303,   304,
      -1,   108,    -1,    19,   587,     6,   587,    -1,   305,    -1,
     306,    -1,    10,   109,    -1,    11,    -1,    10,   307,   109,
      -1,   308,    -1,   307,   308,    -1,   309,   310,   316,    -1,
     106,    -1,   311,    -1,    -1,   311,   312,    -1,   313,    -1,
     314,    -1,   315,    -1,    34,     3,   587,    -1,    40,     3,
     587,    -1,    41,    -1,    32,     3,   587,    -1,    33,    -1,
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
     354,   355,    -1,   356,    -1,   357,    -1,    38,     3,   587,
      -1,    32,     3,   587,    -1,    33,    -1,     6,    -1,     7,
      -1,   360,   361,    10,   366,   155,    -1,   154,    -1,   362,
      -1,    -1,   362,   363,    -1,   364,    -1,   365,    -1,    38,
       3,   587,    -1,    32,     3,   587,    -1,    33,    -1,     6,
      -1,     7,    -1,   368,   369,    10,   374,   151,    -1,   150,
      -1,   370,    -1,    -1,   370,   371,    -1,   372,    -1,   373,
      -1,    38,     3,   587,    -1,    32,     3,   587,    -1,    33,
      -1,     6,    -1,     7,    -1,   376,   377,    10,   379,   149,
      -1,   148,    -1,    -1,   378,    -1,    32,     3,   587,    -1,
      33,    -1,     6,    -1,   381,   382,   383,    -1,   108,    -1,
      19,   587,     6,   587,    -1,   384,    -1,   385,    -1,    10,
     109,    -1,    11,    -1,    10,   386,   109,    -1,   387,    -1,
     386,   387,    -1,   388,   389,   395,    -1,   106,    -1,   390,
      -1,    -1,   390,   391,    -1,   392,    -1,   393,    -1,   394,
      -1,    34,     3,   587,    -1,    40,     3,   587,    -1,    41,
      -1,    32,     3,   587,    -1,    33,    -1,    10,   107,    -1,
      11,    -1,    -1,   397,   398,   405,    -1,    56,    -1,   399,
      -1,    -1,   399,   400,    -1,   401,   587,    -1,   402,   587,
      -1,   403,   587,    -1,   404,   587,    -1,    22,   587,     6,
      -1,    27,   587,     6,    -1,    13,   587,     6,    -1,    16,
     587,     6,    -1,   406,    -1,   407,    -1,    10,    57,    -1,
      11,    -1,    10,   408,   569,    57,    -1,   409,    -1,   408,
     409,    -1,   410,   411,   416,    -1,   124,    -1,   412,    -1,
      -1,   412,   413,    -1,   414,    -1,   415,    -1,    28,   587,
       6,   587,    -1,    42,     3,   587,    -1,    10,   417,   437,
     438,   489,   520,   551,   568,    -1,   418,   419,   425,    -1,
     130,    -1,   420,    -1,   421,    -1,   420,   421,    -1,   422,
      -1,   423,    -1,   424,    -1,    36,     3,   587,    -1,    37,
      -1,    32,     3,   587,    -1,    33,    -1,    24,     8,     6,
       8,    -1,   426,    -1,   427,    -1,    10,   131,    -1,    11,
      -1,    10,   428,   131,    -1,   429,    -1,   428,   429,    -1,
     430,   431,   436,    -1,   134,    -1,   432,    -1,    -1,   432,
     433,    -1,   434,    -1,   435,    -1,    36,     3,     8,    -1,
      32,     3,     8,    -1,    33,    -1,    10,   135,    -1,    11,
      -1,    -1,    96,    10,     4,    97,    -1,    96,    10,    97,
      -1,    96,    11,    -1,    -1,   162,   439,   440,    -1,    -1,
      21,   587,     6,   587,    -1,    11,    -1,   441,    -1,    10,
     442,   453,   463,   473,   163,    -1,    -1,   443,   444,   445,
      -1,   156,    -1,    26,   587,     6,   587,    -1,   446,    -1,
     447,    -1,    10,   157,    -1,    11,    -1,    10,   448,   157,
      -1,   449,    -1,   448,   449,    -1,   450,   451,    10,   452,
     161,    -1,   160,    -1,    29,   587,     6,   587,    -1,     6,
      -1,     7,    -1,    -1,   454,   455,   456,    -1,   158,    -1,
      26,   587,     6,   587,    -1,   457,    -1,   458,    -1,    10,
     159,    -1,    11,    -1,    10,   459,   159,    -1,   460,    -1,
     459,   460,    -1,   461,   462,    10,     4,   161,    -1,   160,
      -1,    29,   587,     6,   587,    -1,    -1,   464,   465,   466,
      -1,    72,    -1,    26,   587,     6,   587,    -1,   467,    -1,
     468,    -1,    10,    73,    -1,    11,    -1,    10,   469,    73,
      -1,   470,    -1,   469,   470,    -1,   471,   472,    10,     4,
     161,    -1,   160,    -1,    29,   587,     6,   587,    -1,    -1,
     473,   474,    -1,   475,   476,   483,    -1,   106,    -1,   477,
      -1,    -1,   477,   478,    -1,   479,    -1,   480,    -1,   481,
      -1,   482,    -1,    26,   587,     6,   587,    -1,    40,     3,
     587,    -1,    41,    -1,    34,     3,   587,    -1,    35,    -1,
      32,     3,   587,    -1,    33,    -1,    11,    -1,    10,   484,
     107,    -1,    -1,   484,   485,    -1,   486,   487,   488,    -1,
     160,    -1,    29,   587,     6,   587,    -1,    10,   588,   161,
      -1,    10,   161,    -1,    11,    -1,    -1,   100,   490,   491,
      -1,    -1,    18,   587,     6,   587,    -1,    11,    -1,   492,
      -1,    10,   493,   504,   101,    -1,    -1,   494,   495,   496,
      -1,   156,    -1,    15,   587,     6,   587,    -1,   497,    -1,
     498,    -1,    10,   157,    -1,    11,    -1,    10,   499,   157,
      -1,   500,    -1,   499,   500,    -1,   501,   502,    10,   503,
      99,    -1,    98,    -1,    29,   587,     6,   587,    -1,     6,
      -1,     7,    -1,    -1,   504,   505,    -1,   506,   507,   514,
      -1,   106,    -1,   508,    -1,    -1,   508,   509,    -1,   510,
      -1,   511,    -1,   512,    -1,   513,    -1,    15,   587,     6,
     587,    -1,    40,     3,   587,    -1,    41,    -1,    34,     3,
     587,    -1,    35,    -1,    32,     3,   587,    32,     3,   587,
      -1,    33,    -1,    11,    -1,    10,   515,   107,    -1,    -1,
     515,   516,    -1,   517,   518,   519,    -1,    98,    -1,    29,
     587,     6,   587,    -1,    10,   588,    99,    -1,    10,    99,
      -1,    11,    -1,    -1,    78,   521,   522,    -1,    -1,    17,
     587,     6,   587,    -1,    11,    -1,   523,    -1,    10,   524,
     535,    79,    -1,    -1,   525,   526,   527,    -1,    84,    -1,
      12,   587,     6,   587,    -1,   528,    -1,   529,    -1,    10,
     157,    -1,    11,    -1,    10,   530,    85,    -1,   531,    -1,
     530,   531,    -1,   532,   533,    10,   534,    77,    -1,    76,
      -1,    29,   587,     6,   587,    -1,     6,    -1,     7,    -1,
      -1,   535,   536,    -1,   537,   538,   545,    -1,   106,    -1,
     539,    -1,    -1,   539,   540,    -1,   541,    -1,   542,    -1,
     543,    -1,   544,    -1,    12,   587,     6,   587,    -1,    40,
       3,   587,    -1,    41,    -1,    34,     3,   587,    -1,    35,
      -1,    32,     3,   587,    -1,    33,    -1,    11,    -1,    10,
     546,   107,    -1,    -1,   546,   547,    -1,   548,   549,   550,
      -1,    76,    -1,    29,   587,     6,   587,    -1,    10,   588,
     161,    -1,    10,   161,    -1,    11,    -1,    -1,   112,   552,
      10,   554,   113,    -1,   112,   552,    11,    -1,    -1,    20,
       8,     6,   553,     8,    -1,    -1,   554,   555,    -1,   110,
     556,    10,   563,   111,    -1,   110,   556,    11,    -1,    -1,
      -1,   556,   557,   558,    -1,   559,    -1,   560,    -1,   561,
      -1,   562,    -1,    14,     8,     6,     8,    -1,    35,    -1,
      34,     3,   587,    -1,    30,     3,     8,    -1,    31,    -1,
      32,     3,     8,    -1,    33,    -1,    -1,   563,   564,    -1,
     565,    -1,   566,    -1,    60,    -1,    61,    -1,    -1,    58,
       5,   567,    59,    -1,   125,    -1,    -1,   114,   570,   571,
      -1,    23,   587,     6,   587,    -1,    11,    -1,    10,   572,
     115,    -1,    -1,   572,   573,    -1,   128,   574,    10,   581,
     129,    -1,   128,   574,    11,    -1,    -1,    -1,   574,   575,
     576,    -1,   577,    -1,   578,    -1,   579,    -1,   580,    -1,
      14,     8,     6,     8,    -1,    35,    -1,    34,     3,     8,
      -1,    30,     3,     8,    -1,    31,    -1,    32,     3,     8,
      -1,    33,    -1,    -1,   581,   582,    -1,   583,    -1,   584,
      -1,    60,    -1,    61,    -1,    -1,    58,     5,   585,    59,
      -1,     6,    -1,     7,    -1,   590,     8,    -1,     4,    -1,
       6,    -1,     7,    -1,   165,    -1,   166,    -1,   167,    -1,
     168,    -1,    -1,   590,   589,    -1
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
    1701,  1707,  1713,  1716,  1716,  1718,  1727,  1729,  1741,  1741,
    1744,  1745,  1752,  1759,  1767,  1776,  1777,  1780,  1781,  1784,
    1785,  1787,  1788,  1790,  1790,  1792,  1797,  1799,  1805,  1809,
    1810,  1813,  1814,  1816,  1817,  1823,  1823,  1825,  1827,  1827,
    1829,  1832,  1839,  1843,  1849,  1849,  1851,  1854,  1854,  1856,
    1862,  1868,  1871,  1872,  1876,  1876,  1878,  1887,  1889,  1902,
    1902,  1905,  1906,  1913,  1920,  1928,  1937,  1938,  1941,  1942,
    1944,  1946,  1948,  1949,  1951,  1951,  1953,  1958,  1960,  1966,
    1970,  1971,  1975,  1976,  1978,  1979,  1985,  1985,  1987,  1989,
    1989,  1991,  1994,  2002,  2006,  2012,  2012,  2014,  2016,  2016,
    2018,  2024,  2030,  2033,  2034,  2037,  2037,  2039,  2048,  2050,
    2062,  2062,  2065,  2066,  2073,  2080,  2088,  2097,  2098,  2101,
    2102,  2105,  2106,  2108,  2109,  2112,  2112,  2114,  2119,  2121,
    2127,  2131,  2132,  2136,  2137,  2142,  2149,  2148,  2164,  2164,
    2167,  2174,  2183,  2184,  2184,  2188,  2188,  2188,  2188,  2190,
    2203,  2209,  2217,  2220,  2223,  2226,  2228,  2229,  2232,  2237,
    2244,  2244,  2247,  2246,  2252,  2262,  2262,  2264,  2266,  2266,
    2268,  2268,  2271,  2278,  2280,  2282,  2281,  2286,  2286,  2286,
    2286,  2288,  2303,  2310,  2319,  2325,  2328,  2334,  2336,  2337,
    2339,  2344,  2350,  2350,  2353,  2352,  2358,  2359,  2361,  2364,
    2365,  2366,  2370,  2371,  2372,  2373,  2375,  2376
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
  "numberOfOtherObjectiveResults", "objectivesContent", "objectivesBody",
  "objectiveValues", "objectiveValuesStart", "numberOfObjATT",
  "objectiveValuesContent", "objectiveValuesEmpty", "objectiveValuesBody",
  "objValueSEQ", "objValue", "objValueStart", "objIdxATT", "objVal",
  "otherObjectiveResultsSEQ", "otherObjectiveResult",
  "otherObjectiveResultStart", "otherObjectiveResultAttributes",
  "otherObjectiveResultAttList", "otherObjectiveResultATT",
  "numberOfOtherObjectiveResultsATT", "otherObjectiveResultValueATT",
  "otherObjectiveResultNameATT", "otherObjectiveResultDescriptionATT",
  "otherObjectiveResultContent", "otherObjList", "otherObj",
  "otherObjStart", "otherObjIdxATT", "otherObjContent", "constraints",
  "numberOfOtherConstraintResults", "constraintsContent",
  "constraintsBody", "dualValues", "dualValuesStart", "numberOfConATT",
  "dualValuesContent", "dualValuesEmpty", "dualValuesBody", "dualValueSEQ",
  "dualValue", "dualValueStart", "conIdxATT", "dualVal",
  "otherConstraintResultsSEQ", "otherConstraintResult",
  "otherConstraintResultStart", "otherConstraintResultAttributes",
  "otherConstraintResultAttList", "otherConstraintResultATT",
  "numberOfOtherConstraintResultATT", "otherConstraintResultValueATT",
  "otherConstraintResultNameATT", "otherConstraintResultDescriptionATT",
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
     488,   489,   489,   490,   490,   491,   491,   492,   493,   493,
     494,   495,   496,   496,   497,   497,   498,   499,   499,   500,
     501,   502,   503,   503,   504,   504,   505,   506,   507,   508,
     508,   509,   509,   509,   509,   510,   511,   511,   512,   512,
     513,   513,   514,   514,   515,   515,   516,   517,   518,   519,
     519,   519,   520,   520,   521,   521,   522,   522,   523,   524,
     524,   525,   526,   527,   527,   528,   528,   529,   530,   530,
     531,   532,   533,   534,   534,   535,   535,   536,   537,   538,
     539,   539,   540,   540,   540,   540,   541,   542,   542,   543,
     543,   544,   544,   545,   545,   546,   546,   547,   548,   549,
     550,   550,   550,   551,   551,   551,   553,   552,   554,   554,
     555,   555,   556,   557,   556,   558,   558,   558,   558,   559,
     560,   560,   561,   561,   562,   562,   563,   563,   564,   564,
     565,   565,   567,   566,   568,   569,   569,   570,   571,   571,
     572,   572,   573,   573,   574,   575,   574,   576,   576,   576,
     576,   577,   578,   578,   579,   579,   580,   580,   581,   581,
     582,   582,   583,   583,   585,   584,   586,   586,   587,   588,
     588,   588,   589,   589,   589,   589,   590,   590
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
       1,     0,     3,     0,     4,     1,     1,     4,     0,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     2,     5,
       1,     4,     1,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     4,     3,     1,     3,     1,
       6,     1,     1,     3,     0,     2,     3,     1,     4,     3,
       2,     1,     0,     3,     0,     4,     1,     1,     4,     0,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     2,
       5,     1,     4,     1,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     4,     3,     1,     3,
       1,     3,     1,     1,     3,     0,     2,     3,     1,     4,
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
       0,     0,     0,     5,     3,     0,     1,     0,   111,     4,
       8,     6,     0,   195,     0,   114,   112,     0,   256,     7,
      20,    67,    72,    52,    87,    62,    57,    77,    82,     9,
      10,     0,    11,     0,    12,     0,    13,     0,    14,     0,
      15,     0,    16,     0,    17,     0,    18,     0,     0,   198,
     196,     0,   395,     0,     0,    30,     0,    28,     0,    21,
      22,    24,    25,    26,     0,    55,    51,     0,    60,    56,
       0,    65,    61,     0,    70,    66,     0,    75,    71,     0,
      80,    76,     0,    85,    81,   716,     0,   113,   164,   152,
     128,   140,   171,   123,   115,   116,     0,   117,   130,   118,
     142,   119,   154,   120,   165,   121,     0,     0,   259,   257,
     397,     0,   399,     0,   716,   716,     0,    35,    19,    32,
      33,    23,     0,    54,     0,    59,     0,    64,     0,    69,
       0,    74,     0,    79,     0,    84,     0,     0,     0,    92,
      86,    89,    90,     0,   126,   122,     0,   129,     0,   141,
       0,   153,     0,   168,     0,   166,   716,     0,   197,   212,
     207,   232,   227,   222,   217,   199,   200,     0,   201,     0,
     202,     0,   203,     0,   204,     0,   205,     0,     0,     2,
       0,   398,     0,    29,    27,    34,    40,     0,    37,    42,
      53,    58,    63,    68,    73,    78,    83,   716,   708,   712,
     713,   714,   715,   717,    97,    91,     0,    94,    99,     0,
     125,     0,     0,   136,     0,   131,   132,   133,     0,     0,
     148,     0,   143,   144,   145,     0,     0,   160,     0,   155,
     156,   157,   716,     0,     0,     0,   176,   170,   173,   174,
       0,   210,   206,     0,   215,   211,     0,   220,   216,     0,
     225,   221,     0,   230,   226,   716,     0,   258,   288,   293,
     371,   283,   273,   278,   298,   364,   352,   328,   340,   260,
     261,     0,   262,     0,   263,     0,   264,     0,   265,     0,
     266,     0,   267,   330,   268,   342,   269,   354,   270,   365,
     271,     0,     0,   412,   396,   409,   410,   716,   716,   716,
     716,   400,   716,   716,   716,   716,    31,    36,    38,     0,
      41,    88,    93,    95,     0,    98,   124,   137,   138,     0,
     716,   716,   149,   150,     0,   716,   716,   161,   162,     0,
     716,   716,   167,   169,     0,   716,   181,   175,     0,   178,
     183,     0,   209,     0,   214,     0,   219,     0,   224,   706,
     707,   229,     0,     0,     0,   237,   231,   234,   235,     0,
     276,   272,     0,   281,   277,     0,   286,   282,     0,   291,
     287,     0,   296,   292,     0,     0,     0,   329,     0,   341,
       0,   353,     0,   368,     0,   366,   716,     0,   411,   417,
     675,   414,   419,     0,     0,     0,     0,   401,   402,   403,
     404,     0,    50,    39,     0,    48,     0,    43,    44,    45,
       0,   110,    96,     0,   108,     0,     0,   106,   100,   101,
     102,   103,   127,   135,   134,   139,   147,   146,   151,   159,
     158,   163,   172,   177,   179,     0,   182,   208,   213,   218,
     223,   228,   716,   242,   236,     0,   239,   244,     0,   275,
       0,   280,     0,   285,     0,   290,     0,   295,     0,   302,
     300,   297,     0,     0,   336,     0,   331,   332,   333,     0,
       0,   348,     0,   343,   344,   345,     0,     0,   360,     0,
     355,   356,   357,   716,     0,     0,     0,   376,   370,   373,
     374,     0,   415,     0,     0,   418,   407,   408,   405,   406,
      49,     0,     0,   109,   716,   716,   716,     0,   194,   180,
       0,   192,     0,     0,   190,   184,   185,   186,   187,   233,
     238,   240,     0,   243,   274,   279,   284,   289,   294,     0,
       0,   337,   338,     0,   716,   716,   349,   350,     0,   716,
     716,   361,   362,     0,   716,   716,   367,   369,     0,   716,
     381,   375,     0,   378,   383,   716,     0,   413,     0,   416,
     716,     0,   420,   421,   422,    47,    46,   107,   104,   105,
     193,   716,   716,   716,     0,   255,   241,     0,   253,     0,
       0,   251,   245,   246,   247,   248,   299,   305,   301,   303,
     327,   335,   334,   339,   347,   346,   351,   359,   358,   363,
     372,   377,   379,     0,   382,     0,   680,   678,   676,   427,
     458,     0,     0,   716,   191,   188,   189,   254,   716,   716,
     716,   324,     0,   394,   380,     0,   392,     0,     0,   390,
     384,   385,   386,   387,   716,     0,     0,   462,     0,     0,
     437,     0,   435,     0,   428,   429,   431,   432,   433,   716,
     424,   252,   249,   250,     0,   322,     0,   314,     0,   318,
       0,   312,     0,   316,   306,   308,   309,   307,   310,   304,
     319,   320,   393,   716,   716,   716,   677,   679,   684,   681,
       0,   461,   464,   541,     0,   716,   716,     0,   442,   426,
     439,   440,   430,   423,   326,   325,   321,     0,     0,     0,
       0,     0,   391,   388,   389,   685,     0,   460,   716,     0,
     543,   592,     0,   436,   434,   441,   447,     0,   444,   449,
     323,   313,   317,   311,   315,   698,   683,     0,   459,     0,
     469,   466,   463,   467,   716,     0,   594,   643,   438,   443,
     445,     0,   448,     0,     0,     0,   695,     0,   697,     0,
     692,   686,   687,   688,   689,   690,   716,   471,   485,     0,
       0,   548,   545,   542,   546,   716,     0,     0,     0,     0,
     457,   446,     0,   455,     0,   450,   451,   452,     0,   702,
     703,   682,   699,   700,   701,     0,     0,     0,     0,   465,
     487,   499,     0,   716,     0,   716,   550,   564,     0,     0,
     599,   596,   593,   597,     0,     0,   674,   425,   456,     0,
       0,   704,     0,   694,   696,   693,   501,   513,     0,   716,
       0,     0,     0,   476,   470,   473,   474,   544,     0,   716,
       0,   716,   601,   615,     0,     0,   648,   645,   454,   453,
       0,   691,     0,   716,     0,     0,     0,   492,   486,   489,
     490,   716,   475,   481,     0,   478,     0,   547,   567,   565,
     569,     0,     0,   555,   549,   552,   553,   595,     0,   716,
       0,   646,     0,   705,   516,   468,   514,   518,     0,     0,
     506,   500,   503,   504,   716,   491,   497,     0,   494,     0,
     472,   477,   479,   716,     0,     0,   568,   716,   560,   554,
       0,   557,     0,   598,   618,   616,   620,     0,     0,   606,
     600,   603,   604,     0,   652,   644,   649,     0,   517,   716,
     505,   511,     0,   508,     0,   488,   493,   495,   716,     0,
       0,     0,   584,   582,   566,   716,     0,   581,     0,   579,
       0,   577,   570,   571,   572,   573,   574,   551,   556,   558,
     716,     0,     0,   619,   716,   611,   605,     0,   608,     0,
     647,   653,   533,   531,   515,   716,     0,   530,     0,   528,
       0,   526,   519,   520,   521,   522,   523,   502,   507,   509,
     716,     0,     0,     0,   716,   483,   484,     0,     0,     0,
     716,   716,   716,     0,     0,   635,   633,   617,   716,     0,
     632,     0,   630,     0,   628,   621,   622,   623,   624,   625,
     602,   607,   609,   716,     0,   666,   651,     0,     0,     0,
     716,   716,   716,     0,     0,   716,     0,   482,   480,   587,
     583,   585,     0,   716,     0,   578,   576,   716,   562,   563,
       0,     0,     0,   716,   716,   716,     0,     0,     0,     0,
       0,   663,     0,   665,     0,   660,   654,   655,   656,   657,
     658,   532,   536,   534,     0,   716,   529,   527,   525,   716,
       0,   498,   496,   716,     0,   575,     0,   561,   559,   638,
     634,   636,     0,   716,   631,   629,   627,   716,   613,   614,
       0,     0,   670,   671,   650,   667,   668,   669,     0,     0,
       0,   716,   716,     0,   524,   512,   510,     0,     0,   591,
     586,   716,   716,     0,   626,   612,   610,   672,     0,   662,
     664,   661,     0,     0,   540,   535,   716,   709,   710,   711,
     590,     0,   580,     0,     0,   642,   637,     0,   659,   716,
     539,     0,   588,   589,   716,   641,     0,   673,   537,   538,
     639,   640
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
     718,   719,   741,   742,   775,   776,   777,   771,   637,   683,
     709,   732,   733,   758,   759,   794,   824,   825,   826,   854,
     855,   856,   894,   987,   791,   792,   820,   848,   849,   850,
     887,   888,   889,   929,   817,   818,   844,   881,   882,   883,
     922,   923,   924,   981,   842,   876,   877,   917,   918,   972,
     973,   974,   975,   976,   964,  1018,  1063,  1064,  1103,  1125,
     711,   735,   763,   764,   797,   798,   830,   864,   865,   866,
     900,   901,   902,   951,  1040,   828,   859,   860,   895,   896,
     942,   943,   944,   945,   946,   934,   988,  1031,  1032,  1074,
    1110,   737,   766,   802,   803,   833,   834,   870,   910,   911,
     912,   957,   958,   959,  1014,  1090,   868,   905,   906,   952,
     953,  1005,  1006,  1007,  1008,  1009,   997,  1041,  1081,  1082,
    1113,  1136,   768,   805,   913,   872,   916,   961,  1017,  1056,
    1057,  1058,  1059,  1060,  1048,  1095,  1096,  1097,  1137,   807,
     493,   556,   608,   635,   679,   705,   727,   751,   752,   753,
     754,   755,   743,   782,   783,   784,   840,   352,   136,  1131,
     203,   137
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1065
static const yytype_int16 yypact[] =
{
      17,    43,    71,    36, -1065,    76, -1065,   236,    38, -1065,
   -1065, -1065,   260,   116,   -28, -1065, -1065,   306,    78, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065,   186, -1065,   308, -1065,   310, -1065,   312, -1065,   314,
   -1065,   316, -1065,   319, -1065,   321, -1065,    75,    40, -1065,
   -1065,   323,   143,   197,   212, -1065,   217, -1065,   325,   186,
   -1065, -1065, -1065, -1065,    25, -1065, -1065,    15, -1065, -1065,
      16, -1065, -1065,    33, -1065, -1065,    18, -1065, -1065,    19,
   -1065, -1065,     0, -1065, -1065, -1065,   327, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065,   329, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065,   309, -1065,   220,   -13, -1065, -1065,
   -1065,   166, -1065,   254, -1065, -1065,   -38, -1065, -1065, -1065,
   -1065, -1065,   266, -1065,   161, -1065,   249, -1065,   331, -1065,
     304, -1065,   302, -1065,   291, -1065,   460,    -6,    44, -1065,
   -1065, -1065, -1065,     3, -1065, -1065,   430,   149,   463,   241,
     464,   245,   472, -1065,   466, -1065, -1065,   333, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065,   335, -1065,   337,
   -1065,   339, -1065,   341, -1065,   343, -1065,   462,   -29, -1065,
     345,   142,   469, -1065, -1065, -1065, -1065,   -35, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065,   155, -1065, -1065,   342,
   -1065,   351,   475, -1065,   477, -1065, -1065, -1065,   353,   479,
   -1065,   480, -1065, -1065, -1065,   355,   481, -1065,   482, -1065,
   -1065, -1065, -1065,   483,   484,   183, -1065, -1065, -1065, -1065,
      28, -1065, -1065,    49, -1065, -1065,    -3, -1065, -1065,     1,
   -1065, -1065,    11, -1065, -1065, -1065,   354, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065,   356, -1065,   360, -1065,   362, -1065,   364, -1065,   366,
   -1065,   467, -1065, -1065, -1065, -1065, -1065, -1065, -1065,   346,
   -1065,   468,   -12, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,   370,
     281, -1065, -1065, -1065,   372,   160, -1065, -1065, -1065,   419,
   -1065, -1065, -1065, -1065,   415, -1065, -1065, -1065, -1065,   424,
   -1065, -1065, -1065, -1065,   429, -1065, -1065, -1065,   185, -1065,
   -1065,   410, -1065,   414, -1065,   349, -1065,   357, -1065, -1065,
   -1065, -1065,   377,   491,   189, -1065, -1065, -1065, -1065,     7,
   -1065, -1065,    12, -1065, -1065,    20, -1065, -1065,    30, -1065,
   -1065,    42, -1065, -1065,   493,   374,   492,   248,   497,   252,
     498,   255,   500, -1065,   499, -1065, -1065,   376, -1065, -1065,
     -62, -1065, -1065,   504,   505,   506,   507, -1065, -1065, -1065,
   -1065,   379, -1065, -1065,   512, -1065,   513, -1065, -1065, -1065,
     411, -1065, -1065,   514, -1065,   516,   518, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065,   378,   222, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065,   190, -1065, -1065,   393, -1065,
     395, -1065,   405, -1065,   470, -1065,   436, -1065,   519, -1065,
   -1065, -1065,   387,   523, -1065,   524, -1065, -1065, -1065,   389,
     526, -1065,   527, -1065, -1065, -1065,   391,   528, -1065,   529,
   -1065, -1065, -1065, -1065,   530,   531,   191, -1065, -1065, -1065,
   -1065,   511, -1065,   485,   533,    35, -1065, -1065, -1065, -1065,
   -1065,   532,   536, -1065, -1065, -1065, -1065,   431, -1065, -1065,
     538, -1065,   542,   543, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065,   390,   225, -1065, -1065, -1065, -1065, -1065,   539,
      64, -1065, -1065,   386, -1065, -1065, -1065, -1065,   397, -1065,
   -1065, -1065, -1065,   399, -1065, -1065, -1065, -1065,   407, -1065,
   -1065, -1065,   195, -1065, -1065, -1065,   392, -1065,   418, -1065,
   -1065,   546, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065,   444, -1065, -1065,   550, -1065,   551,
     552, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065,   394,   235,   556, -1065, -1065, -1065, -1065,
     471,   216,   557, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065,   141,   451, -1065, -1065,   554, -1065,   561,   562, -1065,
   -1065, -1065, -1065, -1065, -1065,   -50,   396,   413,   558,   565,
   -1065,   566, -1065,   398,   216, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065,     8, -1065,   567, -1065,   570, -1065,
     571, -1065,   573, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
      27, -1065,   559,   478,   575, -1065, -1065,   171, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065,   438,   574,   576,
     577,   578, -1065, -1065, -1065,   400,   486, -1065, -1065,   402,
     569,   501,   580, -1065, -1065, -1065, -1065,   172, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065,   194, -1065,   583,
     435, -1065, -1065, -1065, -1065,   404,   579,   487, -1065, -1065,
   -1065,   406,   205,   -22,   582,   589, -1065,   590, -1065,   592,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,   440,   581,
     591,   446, -1065, -1065, -1065, -1065,   408,   584,   476,   465,
   -1065, -1065,   600, -1065,   602, -1065, -1065, -1065,   601, -1065,
   -1065, -1065, -1065, -1065, -1065,   603,   604,   605,   606, -1065,
   -1065,   544,   585, -1065,   412, -1065, -1065, -1065,   593,   609,
     534, -1065, -1065, -1065,   611,   417, -1065, -1065, -1065,   613,
     614, -1065,   615, -1065, -1065, -1065, -1065, -1065,   598, -1065,
     422,   619,   150, -1065, -1065, -1065, -1065, -1065,    48, -1065,
     426, -1065, -1065, -1065,   616,   620, -1065, -1065, -1065, -1065,
     568, -1065,   -58, -1065,   428,   623,   283, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065,   151, -1065,   588, -1065, -1065, -1065,
   -1065,   624,   -55, -1065, -1065, -1065, -1065, -1065,   -21, -1065,
     434, -1065,   199, -1065, -1065, -1065, -1065, -1065,   625,   -43,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065,   288, -1065,   607,
   -1065, -1065, -1065, -1065,   622,   439,    41, -1065, -1065, -1065,
     -26, -1065,   608, -1065, -1065, -1065, -1065,   627,   -41, -1065,
   -1065, -1065, -1065,   626, -1065, -1065, -1065,   441,   210, -1065,
   -1065, -1065,   -32, -1065,   610, -1065, -1065, -1065, -1065,   628,
     629,   447, -1065, -1065, -1065, -1065,   637, -1065,   638, -1065,
     640, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065,   634,   445,   163, -1065, -1065, -1065,    80, -1065,   617,
   -1065,   450, -1065, -1065, -1065, -1065,   642, -1065,   644, -1065,
     645, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065,   639,   646,   649, -1065, -1065, -1065,   449,    59,   648,
   -1065, -1065, -1065,   650,   456, -1065, -1065, -1065, -1065,   647,
   -1065,   652, -1065,   654, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065,   651, -1065, -1065,   200,   -63,   653,
   -1065, -1065, -1065,   656,   659, -1065,   503, -1065, -1065, -1065,
   -1065, -1065,   631, -1065,   633, -1065, -1065, -1065, -1065, -1065,
     572,    63,   660, -1065, -1065, -1065,   661,   458,   -11,   662,
     655, -1065,   665, -1065,   666, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065,   643, -1065, -1065, -1065, -1065, -1065,
     515, -1065, -1065, -1065,   457, -1065,   670, -1065, -1065, -1065,
   -1065, -1065,   657, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
     597,   672, -1065, -1065, -1065, -1065, -1065, -1065,   669,   674,
     675, -1065, -1065,   459, -1065, -1065, -1065,   678,    21, -1065,
   -1065, -1065, -1065,   461, -1065, -1065, -1065, -1065,   677, -1065,
   -1065, -1065,   681,     2, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065,   594, -1065,   682,     6, -1065, -1065,   621, -1065, -1065,
   -1065,   517, -1065, -1065, -1065, -1065,   535, -1065, -1065, -1065,
   -1065, -1065
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
     630, -1065, -1065, -1065, -1065, -1065, -1065, -1065,   508, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065,   488, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065,   352, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,   246,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,   140, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
     307, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065,    54, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
     -18, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
    -154, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065,  -186, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065,  -220, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065,  -197, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065,  -253, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,
   -1065, -1065, -1065, -1065, -1065, -1065, -1065, -1065,  -114, -1064,
   -1065, -1065
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     183,   184,   198,   345,   134,   347,  1127,   209,  1128,  1129,
    1127,   448,  1128,  1129,   694,   695,   450,   349,   350,   124,
     126,    19,   130,   132,   452,  1127,   257,  1128,  1129,   122,
     920,   706,   341,   258,   454,   955,   778,   128,   779,   780,
     158,   978,   234,   898,  1061,   388,   456,  1091,   874,  1092,
    1093,   185,   491,     4,   307,   343,   935,   259,   903,  1141,
      20,     1,   389,   560,    21,   677,    22,   159,    23,   160,
    1146,     6,   898,   936,   937,   938,   939,   561,   678,   260,
      24,   940,   941,   311,     7,   904,     9,   261,    12,     5,
      25,    87,    26,   455,    85,   161,   186,  1062,    27,   186,
    1094,   262,   899,   263,    88,   875,    89,   781,    90,   162,
      91,   342,   389,   131,    28,   264,   956,   921,   332,   265,
    1130,   266,   123,   267,   707,   268,   129,   163,   921,   457,
     344,   948,    51,   164,   351,   127,   125,   453,   449,  1079,
     210,   353,   348,   135,   346,   451,   133,   696,    92,   857,
     204,   654,   655,   205,   858,   297,   955,  1029,   298,   199,
     200,   201,   202,  1140,   299,  1011,  1030,  1145,    17,   300,
    1080,   656,   657,   658,   659,   998,    93,   660,   661,   662,
     663,   212,   213,   393,   394,   395,   396,   214,   397,   398,
     399,   400,   413,   414,   415,   999,  1000,  1001,  1002,   110,
     416,   417,   587,  1003,  1004,   113,   423,   424,   744,   588,
      53,   426,   427,   179,  1049,   114,   429,   430,    54,    55,
     115,   432,    56,    57,   745,   746,   747,   748,   749,   750,
    1050,  1051,  1052,  1053,  1054,  1055,   965,   772,   773,   156,
     638,   774,   966,   967,   968,   969,    10,    11,   639,   640,
     970,   971,   641,   642,   510,   511,   512,   577,   578,   579,
     182,   204,   513,   514,   312,   580,   581,   625,   626,   627,
      15,    16,   485,   219,   220,   628,   629,   226,   227,   221,
     463,   464,   191,   228,   470,   471,   465,   477,   478,   336,
     472,   336,   337,   479,   433,   443,   443,   550,   444,   520,
     551,   550,   715,   739,   601,   716,   716,   852,   891,   914,
     853,   853,   915,   404,   405,   406,    49,    50,    64,    65,
      67,    68,    70,    71,    73,    74,    76,    77,   519,    79,
      80,    82,    83,   108,   109,   116,   117,   138,   139,   143,
     144,   152,   153,   235,   236,   240,   241,   243,   244,   246,
     247,   249,   250,   252,   253,   292,   293,   317,   318,   322,
     323,   327,   328,   190,   354,   355,   359,   360,   192,   546,
     362,   363,   365,   366,   368,   369,   371,   372,   382,   383,
     401,   402,   410,   411,   459,   460,   486,   487,   507,   508,
     567,   568,   569,   531,   532,   536,   537,   541,   542,   194,
     574,   575,   606,   607,   622,   623,   680,   681,   687,   688,
     725,   726,   730,   731,   761,   762,   769,   770,   800,   801,
     591,   592,   822,   823,   193,   594,   595,   836,   837,   195,
     597,   598,   846,   847,   196,   600,   862,   863,   879,   880,
     211,   605,   885,   886,   908,   909,   612,   926,   886,   932,
     933,   962,   963,   985,   986,   995,   996,   614,   615,   616,
    1015,  1016,  1038,  1039,  1088,  1089,   197,  1108,  1109,  1123,
    1124,  1134,  1135,   218,   225,   232,   233,   306,   320,   316,
     321,   255,   325,   326,   330,   331,   425,   386,   422,   333,
     335,   428,   374,   437,   431,   438,   439,   442,   440,   650,
     441,   458,   462,   483,   651,   652,   653,   469,   476,   484,
     496,   497,   498,   499,   500,   501,   502,   504,   503,   505,
     676,   506,   526,   528,   524,   529,   534,   535,   525,   539,
     540,   544,   545,   527,   555,   693,   547,   549,   570,   590,
     565,   571,   557,   558,   566,   572,   573,   586,   609,   613,
     596,   617,   593,   618,   619,   620,   599,   673,   672,   702,
     703,   704,   634,   649,   674,   675,   684,   636,   685,   686,
     698,   713,   714,   699,   700,   682,   701,   720,   710,   736,
     708,   712,   721,   728,   722,   723,   724,   734,   738,   756,
     785,   757,   786,   787,   729,   788,   765,   795,   790,   767,
     808,   806,   796,   809,   804,   810,   811,   793,   829,   812,
    1028,   819,   813,   814,   815,   831,   816,   893,   832,   835,
     760,   838,   839,   841,   843,   851,   871,   873,   869,   884,
     897,   919,   931,   954,   960,   984,   928,   950,   983,   980,
     990,   991,   789,   992,   994,  1020,  1013,  1021,  1022,  1024,
    1043,   799,  1025,  1026,  1033,  1044,  1037,  1045,  1099,  1065,
    1073,  1047,  1069,  1070,  1072,  1076,  1083,  1087,  1100,  1101,
    1098,  1078,  1102,  1111,  1116,  1118,  1106,  1117,  1149,   821,
    1147,   827,  1119,  1120,  1126,  1138,  1112,  1139,  1144,   121,
     434,   521,   602,  1143,   313,   308,  1151,   492,   692,   740,
     892,   927,   979,   949,  1012,   845,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   861,     0,   867,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   878,
       0,     0,     0,     0,     0,     0,     0,   890,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   907,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     925,     0,     0,     0,     0,     0,     0,     0,     0,   930,
       0,     0,     0,   947,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   977,     0,     0,     0,     0,
       0,     0,     0,     0,   982,     0,     0,     0,     0,     0,
       0,   989,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   993,     0,     0,     0,
    1010,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1019,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1023,     0,     0,     0,
    1027,     0,     0,     0,     0,     0,  1034,  1035,  1036,     0,
       0,     0,     0,     0,  1042,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1046,
       0,     0,     0,     0,     0,     0,  1066,  1067,  1068,     0,
       0,  1071,     0,     0,     0,     0,     0,     0,     0,  1075,
       0,     0,     0,  1077,     0,     0,     0,     0,     0,  1084,
    1085,  1086,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1104,     0,     0,     0,  1105,     0,     0,     0,  1107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1114,
       0,     0,     0,  1115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1121,  1122,     0,
       0,     0,     0,     0,     0,     0,     0,  1132,  1133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1148,     0,     0,     0,     0,
    1150
};

static const yytype_int16 yycheck[] =
{
     114,   115,     8,     6,     4,     4,     4,     4,     6,     7,
       4,     4,     6,     7,     6,     7,     4,     6,     7,     4,
       4,    49,     4,     4,     4,     4,    55,     6,     7,     4,
      73,     4,     4,    62,     4,    76,    58,     4,    60,    61,
      53,    73,   156,    98,   107,    57,     4,    58,   106,    60,
      61,    89,   114,    10,    89,     6,    15,    86,    79,  1123,
      88,    44,   124,    28,    92,   115,    94,    80,    96,    82,
    1134,     0,    98,    32,    33,    34,    35,    42,   128,   108,
     108,    40,    41,   197,    48,   106,    10,   116,    50,    46,
     118,    51,   120,    63,    19,   108,   134,   160,   126,   134,
     111,   130,   157,   132,    64,   163,    66,   129,    68,   122,
      70,    83,   124,    95,   142,   144,   157,   160,   232,   148,
      99,   150,    97,   152,    97,   154,    93,   140,   160,    87,
      81,   157,    54,   146,   123,   119,   121,   117,   131,    76,
     137,   255,   141,   143,   147,   133,   127,   139,   108,   101,
     106,    10,    11,   109,   106,    13,    76,    98,    16,   165,
     166,   167,   168,   161,    22,    85,   107,   161,    52,    27,
     107,    30,    31,    32,    33,    12,   136,    36,    37,    38,
      39,    32,    33,   297,   298,   299,   300,    38,   302,   303,
     304,   305,    32,    33,    34,    32,    33,    34,    35,    56,
      40,    41,   138,    40,    41,     8,   320,   321,    14,   145,
      24,   325,   326,    47,    14,     3,   330,   331,    32,    33,
       3,   335,    36,    37,    30,    31,    32,    33,    34,    35,
      30,    31,    32,    33,    34,    35,    26,    32,    33,    19,
      24,    36,    32,    33,    34,    35,    10,    11,    32,    33,
      40,    41,    36,    37,    32,    33,    34,    32,    33,    34,
       6,   106,    40,    41,   109,    40,    41,    32,    33,    34,
      10,    11,   386,    32,    33,    40,    41,    32,    33,    38,
      32,    33,   121,    38,    32,    33,    38,    32,    33,   106,
      38,   106,   109,    38,   109,   106,   106,   106,   109,   109,
     109,   106,   131,   131,   109,   134,   134,   157,   157,   110,
     160,   160,   113,    32,    33,    34,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,   442,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    32,    33,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,     6,     7,     6,
       7,     6,     7,    97,    10,    11,    10,    11,   119,   483,
      10,    11,    10,    11,    10,    11,    10,    11,    32,    33,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     504,   505,   506,     6,     7,     6,     7,     6,     7,    95,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     534,   535,    10,    11,    93,   539,   540,    10,    11,   127,
     544,   545,    10,    11,   143,   549,    10,    11,    10,    11,
      10,   555,   159,   160,    10,    11,   560,   159,   160,    10,
      11,    10,    11,     6,     7,    10,    11,   571,   572,   573,
      10,    11,     6,     7,     6,     7,     6,    10,    11,    10,
      11,    10,    11,    10,    10,     3,    10,     8,     3,   137,
       3,    19,     3,     3,     3,     3,    71,    19,    69,     6,
       6,    67,    25,    83,    65,    81,   147,     6,   141,   613,
     123,     8,    10,     3,   618,   619,   620,    10,    10,    10,
       6,     6,     6,     6,   135,     3,     3,     3,   107,     3,
     634,     3,   117,    87,   131,     6,     3,     3,   133,     3,
       3,     3,     3,    63,    23,   649,     6,     6,   107,   153,
       8,     3,    57,    10,     8,     3,     3,     8,   130,     3,
     151,   107,   155,     3,     3,     3,   149,     3,   107,   673,
     674,   675,     6,     6,     3,     3,     8,    96,     3,     3,
       3,   685,   686,     3,     3,   162,     3,   139,   100,    78,
      21,     6,     8,    97,     8,     8,     8,    18,     8,     6,
       8,   156,     3,     3,   708,     3,    17,     6,   158,   112,
     135,   125,   156,     3,    20,     3,     5,    26,    15,     6,
     161,    26,     8,     8,     8,     6,    72,    29,    84,     8,
     734,     8,     8,     8,    26,     6,     6,    59,    12,     6,
       6,     6,    10,     6,     8,     6,    29,    29,    10,    29,
       3,     3,   756,     3,    10,     3,    29,     3,     3,    10,
       3,   765,     6,     4,     6,     3,     6,     3,     3,     6,
      29,    10,     6,     4,   161,    32,     6,     6,     3,     3,
       8,    99,    29,     3,    77,     6,   161,     5,   161,   793,
      59,   795,     8,     8,     6,     8,    29,     6,     6,    59,
     338,   445,   552,    99,   206,   187,   161,   390,   644,   717,
     854,   887,   922,   900,   957,   819,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   829,    -1,   831,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   843,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   851,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   869,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     884,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   893,
      -1,    -1,    -1,   897,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   919,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   928,    -1,    -1,    -1,    -1,    -1,
      -1,   935,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   950,    -1,    -1,    -1,
     954,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   965,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   980,    -1,    -1,    -1,
     984,    -1,    -1,    -1,    -1,    -1,   990,   991,   992,    -1,
      -1,    -1,    -1,    -1,   998,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1013,
      -1,    -1,    -1,    -1,    -1,    -1,  1020,  1021,  1022,    -1,
      -1,  1025,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1033,
      -1,    -1,    -1,  1037,    -1,    -1,    -1,    -1,    -1,  1043,
    1044,  1045,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1065,    -1,    -1,    -1,  1069,    -1,    -1,    -1,  1073,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1083,
      -1,    -1,    -1,  1087,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1101,  1102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1111,  1112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1139,    -1,    -1,    -1,    -1,
    1144
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
       4,    95,     4,   127,     4,   143,   587,   590,    10,    11,
     219,   220,   221,    10,    11,   237,   240,   241,   248,   249,
     256,   257,    32,    33,   264,   265,    19,   269,    53,    80,
      82,   108,   122,   140,   146,   285,   286,   287,   289,   290,
     292,   293,   295,   296,   298,   299,   301,   302,   318,    47,
     398,   399,     6,   587,   587,    89,   134,   186,   187,   188,
      97,   121,   119,    93,    95,   127,   143,     6,     8,   165,
     166,   167,   168,   589,   106,   109,   222,   223,   224,     4,
     137,    10,    32,    33,    38,   242,   243,   244,    10,    32,
      33,    38,   250,   251,   252,    10,    32,    33,    38,   258,
     259,   260,     3,    10,   587,    10,    11,   270,   271,   272,
      10,    11,   288,    10,    11,   291,    10,    11,   294,    10,
      11,   297,    10,    11,   300,    19,   303,    55,    62,    86,
     108,   116,   130,   132,   144,   148,   150,   152,   154,   319,
     320,   321,   323,   324,   326,   327,   329,   330,   332,   333,
     335,   336,   351,   352,   359,   360,   367,   368,   375,   376,
     380,   381,    10,    11,   405,   406,   407,    13,    16,    22,
      27,   400,   401,   402,   403,   404,     8,    89,   187,   189,
     190,   587,   109,   223,   225,   226,   137,     6,     7,   245,
       3,     3,     6,     7,   253,     3,     3,     6,     7,   261,
       3,     3,   587,     6,   266,     6,   106,   109,   273,   274,
     275,     4,    83,     6,    81,     6,   147,     4,   141,     6,
       7,   123,   586,   587,    10,    11,   304,   305,   306,    10,
      11,   322,    10,    11,   325,    10,    11,   328,    10,    11,
     331,    10,    11,   334,    25,   337,   353,   354,   361,   362,
     369,   370,    32,    33,   377,   378,    19,   382,    57,   124,
     408,   409,   410,   587,   587,   587,   587,   587,   587,   587,
     587,    10,    11,   194,    32,    33,    34,   191,   192,   193,
      10,    11,   231,    32,    33,    34,    40,    41,   227,   228,
     229,   230,    69,   587,   587,    71,   587,   587,    67,   587,
     587,    65,   587,   109,   274,   276,   277,    83,    81,   147,
     141,   123,     6,   106,   109,   307,   308,   309,     4,   131,
       4,   133,     4,   117,     4,    63,     4,    87,     8,    10,
      11,   338,    10,    32,    33,    38,   355,   356,   357,    10,
      32,    33,    38,   363,   364,   365,    10,    32,    33,    38,
     371,   372,   373,     3,    10,   587,    10,    11,   383,   384,
     385,   114,   409,   569,   411,   412,     6,     6,     6,     6,
     135,     3,     3,   107,     3,     3,     3,    10,    11,   282,
      32,    33,    34,    40,    41,   278,   279,   280,   281,   587,
     109,   308,   310,   311,   131,   133,   117,    63,    87,     6,
     339,     6,     7,   358,     3,     3,     6,     7,   366,     3,
       3,     6,     7,   374,     3,     3,   587,     6,   379,     6,
     106,   109,   386,   387,   388,    23,   570,    57,    10,   416,
      28,    42,   413,   414,   415,     8,     8,   587,   587,   587,
     107,     3,     3,     3,    10,    11,   316,    32,    33,    34,
      40,    41,   312,   313,   314,   315,     8,   138,   145,   340,
     153,   587,   587,   155,   587,   587,   151,   587,   587,   149,
     587,   109,   387,   389,   390,   587,    10,    11,   571,   130,
     417,   418,   587,     3,   587,   587,   587,   107,     3,     3,
       3,   341,    10,    11,   395,    32,    33,    34,    40,    41,
     391,   392,   393,   394,     6,   572,    96,   437,    24,    32,
      33,    36,    37,   419,   420,   421,   422,   423,   424,     6,
     587,   587,   587,   587,    10,    11,    30,    31,    32,    33,
      36,    37,    38,    39,   342,   343,   344,   345,   346,   347,
     348,   349,   107,     3,     3,     3,   587,   115,   128,   573,
      10,    11,   162,   438,     8,     3,     3,    10,    11,   425,
     426,   427,   421,   587,     6,     7,   139,   350,     3,     3,
       3,     3,   587,   587,   587,   574,     4,    97,    21,   439,
     100,   489,     6,   587,   587,   131,   134,   428,   429,   430,
     139,     8,     8,     8,     8,    10,    11,   575,    97,   587,
      10,    11,   440,   441,    18,   490,    78,   520,     8,   131,
     429,   431,   432,   581,    14,    30,    31,    32,    33,    34,
      35,   576,   577,   578,   579,   580,     6,   156,   442,   443,
     587,    10,    11,   491,   492,    17,   521,   112,   551,    10,
      11,   436,    32,    33,    36,   433,   434,   435,    58,    60,
      61,   129,   582,   583,   584,     8,     3,     3,     3,   587,
     158,   453,   454,    26,   444,     6,   156,   493,   494,   587,
      10,    11,   522,   523,    20,   552,   125,   568,   135,     3,
       3,     5,     6,     8,     8,     8,    72,   463,   464,    26,
     455,   587,    10,    11,   445,   446,   447,   587,   504,    15,
     495,     6,    84,   524,   525,     8,    10,    11,     8,     8,
     585,     8,   473,    26,   465,   587,    10,    11,   456,   457,
     458,     6,   157,   160,   448,   449,   450,   101,   106,   505,
     506,   587,    10,    11,   496,   497,   498,   587,   535,    12,
     526,     6,   554,    59,   106,   163,   474,   475,   587,    10,
      11,   466,   467,   468,     6,   159,   160,   459,   460,   461,
     587,   157,   449,    29,   451,   507,   508,     6,    98,   157,
     499,   500,   501,    79,   106,   536,   537,   587,    10,    11,
     527,   528,   529,   553,   110,   113,   555,   476,   477,     6,
      73,   160,   469,   470,   471,   587,   159,   460,    29,   462,
     587,    10,    10,    11,   514,    15,    32,    33,    34,    35,
      40,    41,   509,   510,   511,   512,   513,   587,   157,   500,
      29,   502,   538,   539,     6,    76,   157,   530,   531,   532,
       8,   556,    10,    11,   483,    26,    32,    33,    34,    35,
      40,    41,   478,   479,   480,   481,   482,   587,    73,   470,
      29,   472,   587,    10,     6,     6,     7,   452,   515,   587,
       3,     3,     3,   587,    10,    10,    11,   545,    12,    32,
      33,    34,    35,    40,    41,   540,   541,   542,   543,   544,
     587,    85,   531,    29,   533,    10,    11,   557,   484,   587,
       3,     3,     3,   587,    10,     6,     4,   587,   161,    98,
     107,   516,   517,     6,   587,   587,   587,     6,     6,     7,
     503,   546,   587,     3,     3,     3,   587,    10,   563,    14,
      30,    31,    32,    33,    34,    35,   558,   559,   560,   561,
     562,   107,   160,   485,   486,     6,   587,   587,   587,     6,
       4,   587,   161,    29,   518,   587,    32,   587,    99,    76,
     107,   547,   548,     6,   587,   587,   587,     6,     6,     7,
     534,    58,    60,    61,   111,   564,   565,   566,     8,     3,
       3,     3,    29,   487,   587,   587,   161,   587,    10,    11,
     519,     3,    29,   549,   587,   587,    77,     5,     6,     8,
       8,   587,   587,    10,    11,   488,     6,     4,     6,     7,
      99,   588,   587,   587,    10,    11,   550,   567,     8,     6,
     161,   588,   587,    99,     6,   161,   588,    59,   587,   161,
     587,   161
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
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
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

    {	
	if (parserData->valueAttributePresent)
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

    {	
	if (parserData->descriptionAttributePresent)
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
 	osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 538:

    {	
	 	osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 544:

    {	parserData->numberOfOtherObjectiveResults = (yyvsp[(3) - (4)].ival);
        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 550:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 551:

    {	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
	osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfVar);
	parserData->kounter = 0;
;}
    break;

  case 552:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, "expected at least one <obj> element");
	;}
    break;

  case 553:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, "fewer <obj> elements than specified");
	;}
    break;

  case 559:

    {	osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
						  parserData->idx,         parserData->tempVal);
	parserData->kounter++;
;}
    break;

  case 560:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, "more <obj> elements than specified");
;}
    break;

  case 561:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 562:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 563:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 566:

    { 	 
		parserData->iOther++;  
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
	;}
    break;

  case 568:

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

  case 572:

    {	
	if (parserData->valueAttributePresent)
		osrlerror(NULL, NULL, parserData, "value attribute previously set");
	parserData->valueAttributePresent = true; 
 	osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 573:

    {	
	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, "name attribute previously set");
	parserData->nameAttributePresent = true; 
 	osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 574:

    {	
	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute previously set");
	parserData->descriptionAttributePresent = true; 
 	osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 575:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfObj attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 576:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 577:

    {parserData->tempStr = "";          ;}
    break;

  case 578:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 579:

    {parserData->tempStr = "";          ;}
    break;

  case 580:

    {parserData->tempStr = (yyvsp[(2) - (6)].sval); free((yyvsp[(2) - (6)].sval));;}
    break;

  case 581:

    {parserData->tempStr = "";          ;}
    break;

  case 586:

    {  
	parserData->kounter++;
;}
    break;

  case 588:

    {	
 	osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 589:

    {	
	 	osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 595:

    {	parserData->numberOfOtherConstraintResults = (yyvsp[(3) - (4)].ival);
		osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
		parserData->iOther = 0;
	;}
    break;

  case 601:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 602:

    {
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
		parserData->tmpOtherName = "";
		parserData->tmpOtherValue = "";
		parserData->tmpOtherDescription = "";			
	;}
    break;

  case 619:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		if(!parserData->numberAttributePresent) 
			osrlerror(NULL, NULL, parserData, "other element requires numberOfCon attribute"); 
		parserData->nameAttributePresent = false;	
		parserData->numberAttributePresent = false;	
		parserData->valueAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->kounter = 0;
	;}
    break;

  case 623:

    {	
	if (parserData->valueAttributePresent)
		osrlerror(NULL, NULL, parserData, "value attribute previously set");
	parserData->valueAttributePresent = true; 
 	osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 624:

    {	
	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, "name attribute previously set");
	parserData->nameAttributePresent = true; 
 	osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 625:

    {	
	if (parserData->descriptionAttributePresent)
		osrlerror(NULL, NULL, parserData, "description attribute previously set");
	parserData->descriptionAttributePresent = true; 
 	osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, parserData->tempStr);
  ;}
    break;

  case 626:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, "numberOfCon attribute previously set");
	parserData->numberAttributePresent = true;
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
 	osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, parserData->iOther, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 627:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 628:

    {parserData->tempStr = "";          ;}
    break;

  case 629:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 630:

    {parserData->tempStr = "";          ;}
    break;

  case 631:

    {parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 632:

    {parserData->tempStr = "";          ;}
    break;

  case 637:

    { 	
	parserData->kounter++;
;}
    break;

  case 639:

    {	
 	osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival));
;}
    break;

  case 640:

    {	
	 	osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr);
	;}
    break;

  case 644:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 645:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 646:

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

  case 650:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 651:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
;}
    break;

  case 653:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
;}
    break;

  case 659:

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

  case 660:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->nameAttributePresent = true;
//	parserData->otherVarStruct->name = "";
;}
    break;

  case 661:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); //parserData->nameAttributePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 662:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 664:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));;}
    break;

  case 667:

    {parserData->kounter++;;}
    break;

  case 668:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 669:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
;}
    break;

  case 672:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
;}
    break;

  case 674:

    {

	//
    //delete the old vectors
//	osrl_empty_vectors( parserData);
    
;}
    break;

  case 682:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
;}
    break;

  case 685:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/;}
    break;

  case 691:

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

  case 692:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->nameAttributePresent = true; 
	parserData->otherVarStruct->name = "";
*/
;}
    break;

  case 693:

    {
/*	parserData->tmpOtherName=$2; parserData->nameAttributePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
;}
    break;

  case 694:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
;}
    break;

  case 696:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
;}
    break;

  case 700:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/;}
    break;

  case 701:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/;}
    break;

  case 704:

    {/*parserData->itemContent = $2; free($2);*/;}
    break;

  case 706:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 707:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 709:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 710:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 711:

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


