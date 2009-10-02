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
#define YYLAST   944

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  321
/* YYNRULES -- Number of rules.  */
#define YYNRULES  615
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1041

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
     107,   109,   111,   115,   119,   121,   124,   126,   131,   135,
     138,   143,   147,   150,   155,   159,   162,   167,   171,   174,
     179,   183,   186,   191,   195,   198,   203,   207,   210,   214,
     219,   221,   223,   226,   228,   232,   234,   237,   241,   242,
     245,   247,   249,   251,   255,   257,   261,   263,   267,   269,
     272,   274,   275,   278,   283,   284,   287,   289,   291,   293,
     295,   297,   299,   304,   308,   311,   317,   318,   321,   323,
     325,   329,   333,   335,   337,   339,   345,   346,   349,   351,
     353,   357,   361,   363,   365,   367,   373,   374,   377,   379,
     381,   385,   389,   391,   393,   395,   401,   402,   405,   409,
     411,   413,   415,   419,   424,   426,   428,   431,   433,   437,
     439,   442,   446,   447,   450,   452,   454,   456,   460,   464,
     466,   470,   472,   475,   477,   478,   481,   486,   487,   490,
     492,   494,   496,   498,   500,   502,   507,   511,   514,   519,
     523,   526,   531,   535,   538,   543,   547,   550,   555,   559,
     562,   566,   571,   573,   575,   578,   580,   584,   586,   589,
     593,   594,   597,   599,   601,   603,   607,   611,   613,   617,
     619,   622,   624,   625,   628,   633,   634,   637,   639,   641,
     643,   645,   647,   649,   651,   653,   655,   657,   659,   664,
     668,   671,   676,   680,   683,   688,   692,   695,   700,   704,
     707,   712,   716,   719,   723,   728,   730,   734,   735,   738,
     742,   743,   746,   748,   750,   752,   754,   758,   760,   764,
     766,   770,   772,   776,   778,   780,   782,   785,   787,   791,
     792,   794,   796,   802,   803,   806,   808,   810,   814,   818,
     820,   822,   824,   830,   831,   834,   838,   840,   842,   844,
     850,   851,   854,   856,   858,   862,   866,   868,   870,   872,
     878,   879,   882,   884,   886,   890,   894,   896,   898,   900,
     904,   909,   911,   913,   916,   918,   922,   924,   927,   931,
     932,   935,   937,   939,   941,   945,   949,   951,   955,   957,
     960,   962,   963,   967,   968,   971,   974,   977,   980,   983,
     987,   991,   995,   999,  1003,  1005,  1008,  1009,  1012,  1016,
    1018,  1019,  1022,  1024,  1026,  1031,  1035,  1044,  1048,  1050,
    1053,  1057,  1059,  1063,  1065,  1070,  1072,  1074,  1077,  1079,
    1083,  1085,  1088,  1092,  1093,  1096,  1098,  1100,  1104,  1108,
    1110,  1113,  1115,  1116,  1121,  1125,  1128,  1129,  1133,  1134,
    1139,  1141,  1143,  1145,  1152,  1153,  1159,  1163,  1168,  1169,
    1172,  1178,  1183,  1185,  1187,  1188,  1194,  1198,  1203,  1204,
    1207,  1213,  1218,  1222,  1227,  1228,  1234,  1238,  1243,  1244,
    1247,  1253,  1258,  1259,  1262,  1263,  1268,  1270,  1272,  1273,
    1276,  1278,  1280,  1282,  1284,  1289,  1291,  1295,  1297,  1301,
    1305,  1307,  1309,  1313,  1314,  1317,  1321,  1323,  1328,  1332,
    1335,  1337,  1338,  1342,  1343,  1348,  1350,  1352,  1354,  1359,
    1360,  1366,  1370,  1375,  1376,  1379,  1385,  1390,  1392,  1394,
    1395,  1398,  1402,  1404,  1405,  1408,  1410,  1412,  1414,  1416,
    1421,  1423,  1427,  1429,  1433,  1437,  1439,  1441,  1445,  1446,
    1449,  1453,  1455,  1460,  1464,  1467,  1469,  1470,  1474,  1475,
    1480,  1482,  1484,  1486,  1491,  1492,  1498,  1502,  1507,  1508,
    1511,  1517,  1522,  1524,  1526,  1527,  1530,  1534,  1536,  1537,
    1540,  1542,  1544,  1546,  1548,  1553,  1555,  1559,  1561,  1565,
    1569,  1571,  1573,  1577,  1578,  1581,  1585,  1587,  1592,  1596,
    1599,  1601,  1602,  1608,  1612,  1613,  1619,  1620,  1623,  1629,
    1633,  1634,  1635,  1639,  1641,  1643,  1645,  1647,  1652,  1654,
    1658,  1662,  1664,  1668,  1670,  1671,  1674,  1676,  1678,  1680,
    1682,  1683,  1688,  1690,  1691,  1695,  1700,  1702,  1706,  1707,
    1710,  1716,  1720,  1721,  1722,  1726,  1728,  1730,  1732,  1734,
    1739,  1741,  1745,  1749,  1751,  1755,  1757,  1758,  1761,  1763,
    1765,  1767,  1769,  1770,  1775,  1777,  1779,  1782,  1784,  1786,
    1788,  1790,  1792,  1794,  1796,  1797
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   211,   250,   271,   329,    47,
      -1,    44,    10,    -1,    44,    46,    10,    -1,    -1,    48,
      11,    -1,    48,    10,   173,    49,    -1,    -1,   173,   174,
      -1,   175,    -1,   191,    -1,   192,    -1,   193,    -1,   194,
      -1,   195,    -1,   196,    -1,   197,    -1,   198,    -1,    88,
     176,   181,    -1,   177,    -1,   176,   177,    -1,   178,    -1,
     179,    -1,   180,    -1,    36,     3,   486,    -1,    37,    -1,
      32,     3,   486,    -1,    33,    -1,    24,     8,     6,     8,
      -1,   182,    -1,   183,    -1,    10,    89,    -1,    11,    -1,
      10,   184,    89,    -1,   185,    -1,   184,   185,    -1,   134,
     186,   190,    -1,    -1,   186,   187,    -1,   188,    -1,   189,
      -1,    34,     3,     8,    -1,    32,     3,     8,    -1,    33,
      -1,    10,   135,    -1,    11,    -1,    96,    10,     4,    97,
      -1,    96,    10,    97,    -1,    96,    11,    -1,   120,    10,
       4,   121,    -1,   120,    10,   121,    -1,   120,    11,    -1,
     118,    10,     4,   119,    -1,   118,    10,   119,    -1,   118,
      11,    -1,    92,    10,     4,    93,    -1,    92,    10,    93,
      -1,    92,    11,    -1,    94,    10,     4,    95,    -1,    94,
      10,    95,    -1,    94,    11,    -1,   126,    10,     4,   127,
      -1,   126,    10,   127,    -1,   126,    11,    -1,   142,    10,
       4,   143,    -1,   142,    10,   143,    -1,   142,    11,    -1,
     108,   199,   200,    -1,    19,   486,     6,   486,    -1,   201,
      -1,   202,    -1,    10,   109,    -1,    11,    -1,    10,   203,
     109,    -1,   204,    -1,   203,   204,    -1,   106,   205,   210,
      -1,    -1,   205,   206,    -1,   207,    -1,   208,    -1,   209,
      -1,    34,     3,   486,    -1,    35,    -1,    40,     3,   486,
      -1,    41,    -1,    32,     3,   486,    -1,    33,    -1,    10,
     107,    -1,    11,    -1,    -1,    50,    11,    -1,    50,    10,
     212,    51,    -1,    -1,   212,   213,    -1,   214,    -1,   215,
      -1,   221,    -1,   227,    -1,   233,    -1,   237,    -1,   136,
      10,     4,   137,    -1,   136,    10,   137,    -1,   136,    11,
      -1,    68,   216,    10,   220,    69,    -1,    -1,   216,   217,
      -1,   218,    -1,   219,    -1,    38,     3,   486,    -1,    32,
       3,   486,    -1,    33,    -1,     6,    -1,     7,    -1,    70,
     222,    10,   226,    71,    -1,    -1,   222,   223,    -1,   224,
      -1,   225,    -1,    38,     3,   486,    -1,    32,     3,   486,
      -1,    33,    -1,     6,    -1,     7,    -1,    66,   228,    10,
     232,    67,    -1,    -1,   228,   229,    -1,   230,    -1,   231,
      -1,    38,     3,   486,    -1,    32,     3,   486,    -1,    33,
      -1,     6,    -1,     7,    -1,    64,   234,    10,   236,    65,
      -1,    -1,   234,   235,    -1,    32,     3,   486,    -1,    33,
      -1,     6,    -1,     7,    -1,   108,   238,   239,    -1,    19,
     486,     6,   486,    -1,   240,    -1,   241,    -1,    10,   109,
      -1,    11,    -1,    10,   242,   109,    -1,   243,    -1,   242,
     243,    -1,   106,   244,   249,    -1,    -1,   244,   245,    -1,
     246,    -1,   247,    -1,   248,    -1,    34,     3,   486,    -1,
      40,     3,   486,    -1,    41,    -1,    32,     3,   486,    -1,
      33,    -1,    10,   107,    -1,    11,    -1,    -1,    52,    11,
      -1,    52,    10,   251,    53,    -1,    -1,   251,   252,    -1,
     253,    -1,   254,    -1,   255,    -1,   256,    -1,   257,    -1,
     258,    -1,    82,    10,     4,    83,    -1,    82,    10,    83,
      -1,    82,    11,    -1,    80,    10,     6,    81,    -1,    80,
      10,    81,    -1,    80,    11,    -1,   146,    10,     6,   147,
      -1,   146,    10,   147,    -1,   146,    11,    -1,   140,    10,
       4,   141,    -1,   140,    10,   141,    -1,   140,    11,    -1,
     122,    10,   485,   123,    -1,   122,    10,   123,    -1,   122,
      11,    -1,   108,   259,   260,    -1,    19,   486,     6,   486,
      -1,   261,    -1,   262,    -1,    10,   109,    -1,    11,    -1,
      10,   263,   109,    -1,   264,    -1,   263,   264,    -1,   106,
     265,   270,    -1,    -1,   265,   266,    -1,   267,    -1,   268,
      -1,   269,    -1,    34,     3,   486,    -1,    40,     3,   486,
      -1,    41,    -1,    32,     3,   486,    -1,    33,    -1,    10,
     107,    -1,    11,    -1,    -1,    54,    11,    -1,    54,    10,
     272,    55,    -1,    -1,   272,   273,    -1,   274,    -1,   275,
      -1,   276,    -1,   277,    -1,   278,    -1,   279,    -1,   294,
      -1,   300,    -1,   304,    -1,   310,    -1,   316,    -1,   130,
      10,     4,   131,    -1,   130,    10,   131,    -1,   130,    11,
      -1,   132,    10,     4,   133,    -1,   132,    10,   133,    -1,
     132,    11,    -1,   116,    10,     4,   117,    -1,   116,    10,
     117,    -1,   116,    11,    -1,    62,    10,     4,    63,    -1,
      62,    10,    63,    -1,    62,    11,    -1,    86,    10,     4,
      87,    -1,    86,    10,    87,    -1,    86,    11,    -1,   144,
     280,   281,    -1,    25,     8,     6,     8,    -1,    11,    -1,
      10,   282,   145,    -1,    -1,   282,   283,    -1,   138,   284,
     290,    -1,    -1,   284,   285,    -1,   286,    -1,   287,    -1,
     288,    -1,   289,    -1,    36,     3,     8,    -1,    37,    -1,
      30,     3,     8,    -1,    31,    -1,    38,     3,     8,    -1,
      39,    -1,    32,     3,     8,    -1,    33,    -1,   291,    -1,
     292,    -1,    10,   139,    -1,    11,    -1,    10,   293,   139,
      -1,    -1,     7,    -1,     6,    -1,   150,   295,    10,   299,
     151,    -1,    -1,   295,   296,    -1,   297,    -1,   298,    -1,
      38,     3,   486,    -1,    32,     3,   486,    -1,    33,    -1,
       6,    -1,     7,    -1,   148,   301,    10,   303,   149,    -1,
      -1,   301,   302,    -1,    32,     3,   486,    -1,    33,    -1,
       6,    -1,     7,    -1,   152,   305,    10,   309,   153,    -1,
      -1,   305,   306,    -1,   307,    -1,   308,    -1,    38,     3,
     486,    -1,    32,     3,   486,    -1,    33,    -1,     6,    -1,
       7,    -1,   154,   311,    10,   315,   155,    -1,    -1,   311,
     312,    -1,   313,    -1,   314,    -1,    38,     3,   486,    -1,
      32,     3,   486,    -1,    33,    -1,     6,    -1,     7,    -1,
     108,   317,   318,    -1,    19,   486,     6,   486,    -1,   319,
      -1,   320,    -1,    10,   109,    -1,    11,    -1,    10,   321,
     109,    -1,   322,    -1,   321,   322,    -1,   106,   323,   328,
      -1,    -1,   323,   324,    -1,   325,    -1,   326,    -1,   327,
      -1,    34,     3,   486,    -1,    40,     3,   486,    -1,    41,
      -1,    32,     3,   486,    -1,    33,    -1,    10,   107,    -1,
      11,    -1,    -1,    56,   330,   336,    -1,    -1,   330,   331,
      -1,   332,   486,    -1,   333,   486,    -1,   334,   486,    -1,
     335,   486,    -1,    22,   486,     6,    -1,    27,   486,     6,
      -1,    13,   486,     6,    -1,    16,   486,     6,    -1,    10,
     337,    57,    -1,    11,    -1,   338,   468,    -1,    -1,   338,
     339,    -1,   340,   341,   345,    -1,   124,    -1,    -1,   341,
     342,    -1,   343,    -1,   344,    -1,    28,   486,     6,   486,
      -1,    42,     3,   486,    -1,    10,   346,   359,   360,   398,
     424,   450,   467,    -1,   130,   347,   349,    -1,   348,    -1,
     347,   348,    -1,    36,     3,   486,    -1,    37,    -1,    32,
       3,   486,    -1,    33,    -1,    24,     8,     6,     8,    -1,
     350,    -1,   351,    -1,    10,   131,    -1,    11,    -1,    10,
     352,   131,    -1,   353,    -1,   352,   353,    -1,   134,   354,
     358,    -1,    -1,   354,   355,    -1,   356,    -1,   357,    -1,
      36,     3,     8,    -1,    32,     3,     8,    -1,    33,    -1,
      10,   135,    -1,    11,    -1,    -1,    96,    10,     4,    97,
      -1,    96,    10,    97,    -1,    96,    11,    -1,    -1,   162,
     361,   362,    -1,    -1,    21,   486,     6,   486,    -1,   363,
      -1,   364,    -1,    11,    -1,    10,   365,   371,   376,   381,
     163,    -1,    -1,   156,   366,    10,   367,   157,    -1,   156,
     366,    11,    -1,    26,   486,     6,   486,    -1,    -1,   367,
     368,    -1,   160,   369,    10,   370,   161,    -1,    29,   486,
       6,   486,    -1,     6,    -1,     7,    -1,    -1,   158,   372,
      10,   373,   159,    -1,   158,   372,    11,    -1,    26,   486,
       6,   486,    -1,    -1,   373,   374,    -1,   160,   375,    10,
       4,   161,    -1,   160,   375,    10,   161,    -1,   160,   375,
      11,    -1,    29,   486,     6,   486,    -1,    -1,    72,   377,
      10,   378,    73,    -1,    72,   377,    11,    -1,    26,   486,
       6,   486,    -1,    -1,   378,   379,    -1,   160,   380,    10,
       4,   161,    -1,    29,   486,     6,   486,    -1,    -1,   381,
     382,    -1,    -1,   384,   385,   383,   392,    -1,   106,    -1,
     386,    -1,    -1,   386,   387,    -1,   388,    -1,   389,    -1,
     390,    -1,   391,    -1,    26,   486,     6,   486,    -1,    41,
      -1,    40,     3,   486,    -1,    35,    -1,    34,     3,   486,
      -1,    32,     3,   486,    -1,    33,    -1,    11,    -1,    10,
     393,   107,    -1,    -1,   393,   394,    -1,   395,   396,   397,
      -1,   160,    -1,    29,   486,     6,   486,    -1,    10,   487,
     161,    -1,    10,   161,    -1,    11,    -1,    -1,   100,   399,
     400,    -1,    -1,    18,   486,     6,   486,    -1,   401,    -1,
     402,    -1,    11,    -1,    10,   403,   409,   101,    -1,    -1,
     156,   404,    10,   405,   157,    -1,   156,   404,    11,    -1,
      15,   486,     6,   486,    -1,    -1,   405,   406,    -1,    98,
     407,    10,   408,    99,    -1,    29,   486,     6,   486,    -1,
       6,    -1,     7,    -1,    -1,   409,   410,    -1,   411,   412,
     418,    -1,   106,    -1,    -1,   412,   413,    -1,   414,    -1,
     415,    -1,   416,    -1,   417,    -1,    15,   486,     6,   486,
      -1,    41,    -1,    40,     3,   486,    -1,    35,    -1,    34,
       3,   486,    -1,    32,     3,   486,    -1,    33,    -1,    11,
      -1,    10,   419,   107,    -1,    -1,   419,   420,    -1,   421,
     422,   423,    -1,    98,    -1,    29,   486,     6,   486,    -1,
      10,   487,    99,    -1,    10,    99,    -1,    11,    -1,    -1,
      78,   425,   426,    -1,    -1,    17,   486,     6,   486,    -1,
     427,    -1,   428,    -1,    11,    -1,    10,   429,   435,    79,
      -1,    -1,    84,   430,    10,   431,    85,    -1,    84,   430,
      11,    -1,    12,   486,     6,   486,    -1,    -1,   431,   432,
      -1,    76,   433,    10,   434,    77,    -1,    29,   486,     6,
     486,    -1,     7,    -1,     6,    -1,    -1,   435,   436,    -1,
     437,   438,   444,    -1,   106,    -1,    -1,   438,   439,    -1,
     440,    -1,   441,    -1,   442,    -1,   443,    -1,    12,   486,
       6,   486,    -1,    41,    -1,    40,     3,   486,    -1,    35,
      -1,    34,     3,   486,    -1,    32,     3,   486,    -1,    33,
      -1,    11,    -1,    10,   445,   107,    -1,    -1,   445,   446,
      -1,   447,   448,   449,    -1,    76,    -1,    29,   486,     6,
     486,    -1,    10,   487,    77,    -1,    10,    77,    -1,    11,
      -1,    -1,   112,   451,    10,   453,   113,    -1,   112,   451,
      11,    -1,    -1,    20,     8,     6,   452,     8,    -1,    -1,
     453,   454,    -1,   110,   455,    10,   462,   111,    -1,   110,
     455,    11,    -1,    -1,    -1,   455,   456,   457,    -1,   458,
      -1,   459,    -1,   460,    -1,   461,    -1,    14,     8,     6,
       8,    -1,    35,    -1,    34,     3,   486,    -1,    30,     3,
       8,    -1,    31,    -1,    32,     3,     8,    -1,    33,    -1,
      -1,   462,   463,    -1,   464,    -1,   465,    -1,    60,    -1,
      61,    -1,    -1,    58,     5,   466,    59,    -1,   125,    -1,
      -1,   114,   469,   470,    -1,    23,   486,     6,   486,    -1,
      11,    -1,    10,   471,   115,    -1,    -1,   471,   472,    -1,
     128,   473,    10,   480,   129,    -1,   128,   473,    11,    -1,
      -1,    -1,   473,   474,   475,    -1,   476,    -1,   477,    -1,
     478,    -1,   479,    -1,    14,     8,     6,     8,    -1,    35,
      -1,    34,     3,     8,    -1,    30,     3,     8,    -1,    31,
      -1,    32,     3,     8,    -1,    33,    -1,    -1,   480,   481,
      -1,   482,    -1,   483,    -1,    60,    -1,    61,    -1,    -1,
      58,     5,   484,    59,    -1,     6,    -1,     7,    -1,   489,
       8,    -1,     4,    -1,     6,    -1,     7,    -1,   165,    -1,
     166,    -1,   167,    -1,   168,    -1,    -1,   489,   488,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   166,   167,   169,   169,   170,   172,   172,
     174,   174,   174,   174,   175,   175,   175,   175,   175,   178,
     180,   180,   183,   189,   195,   199,   200,   202,   203,   205,
     217,   217,   219,   219,   221,   225,   225,   227,   229,   229,
     231,   231,   233,   237,   240,   245,   245,   249,   250,   251,
     254,   255,   256,   259,   260,   261,   264,   265,   266,   269,
     270,   271,   274,   275,   276,   279,   280,   281,   283,   285,
     287,   287,   289,   289,   291,   293,   293,   295,   297,   297,
     299,   299,   299,   301,   302,   304,   305,   307,   308,   310,
     310,   314,   314,   315,   317,   317,   319,   319,   319,   320,
     320,   320,   323,   324,   325,   327,   330,   330,   332,   332,
     334,   336,   337,   340,   341,   343,   346,   346,   348,   348,
     350,   352,   353,   356,   357,   359,   362,   362,   364,   364,
     366,   368,   369,   372,   373,   376,   379,   379,   381,   382,
     385,   386,   389,   391,   393,   393,   395,   395,   397,   399,
     399,   401,   403,   403,   405,   405,   405,   407,   409,   410,
     412,   413,   415,   415,   419,   419,   420,   422,   422,   424,
     424,   424,   425,   425,   425,   428,   429,   430,   433,   434,
     435,   438,   439,   440,   443,   444,   445,   448,   449,   450,
     453,   455,   457,   457,   459,   459,   461,   463,   463,   465,
     467,   467,   469,   469,   469,   471,   473,   474,   476,   477,
     479,   479,   482,   482,   483,   485,   485,   487,   487,   487,
     487,   487,   488,   488,   488,   488,   488,   488,   491,   492,
     493,   496,   497,   498,   501,   502,   503,   506,   507,   508,
     511,   512,   513,   516,   518,   524,   524,   526,   526,   528,
     530,   530,   532,   532,   532,   532,   534,   535,   537,   538,
     540,   541,   543,   544,   546,   546,   548,   548,   550,   561,
     565,   566,   569,   572,   572,   574,   574,   576,   578,   579,
     582,   583,   586,   589,   589,   591,   592,   595,   596,   599,
     602,   602,   604,   604,   606,   608,   609,   612,   613,   615,
     618,   618,   620,   620,   622,   624,   625,   628,   629,   633,
     635,   637,   637,   639,   639,   641,   643,   643,   645,   647,
     647,   649,   649,   649,   651,   653,   654,   656,   657,   659,
     659,   663,   663,   665,   665,   667,   668,   669,   670,   674,
     675,   676,   677,   680,   680,   682,   684,   684,   686,   693,
     699,   699,   701,   701,   703,   710,   713,   716,   718,   719,
     721,   722,   723,   724,   725,   728,   734,   740,   740,   742,
     744,   744,   746,   748,   748,   750,   750,   752,   756,   757,
     759,   759,   763,   764,   768,   772,   774,   775,   777,   778,
     788,   788,   790,   792,   794,   795,   804,   815,   822,   822,
     824,   826,   829,   833,   839,   840,   849,   851,   858,   858,
     860,   865,   866,   868,   872,   872,   881,   883,   890,   890,
     892,   894,   899,   899,   902,   901,   921,   929,   935,   935,
     937,   937,   937,   937,   939,   949,   952,   958,   964,   970,
     975,   977,   978,   980,   980,   982,   997,  1002,  1004,  1004,
    1004,  1007,  1008,  1010,  1011,  1021,  1021,  1023,  1025,  1027,
    1028,  1037,  1039,  1043,  1043,  1045,  1047,  1050,  1054,  1060,
    1060,  1062,  1065,  1073,  1074,  1076,  1076,  1076,  1076,  1078,
    1087,  1090,  1096,  1102,  1108,  1113,  1116,  1117,  1139,  1139,
    1141,  1156,  1161,  1163,  1163,  1163,  1167,  1168,  1170,  1171,
    1181,  1181,  1183,  1185,  1188,  1189,  1199,  1201,  1206,  1206,
    1208,  1210,  1213,  1217,  1223,  1223,  1225,  1228,  1230,  1230,
    1232,  1232,  1232,  1232,  1234,  1237,  1240,  1246,  1252,  1258,
    1263,  1265,  1266,  1269,  1269,  1271,  1287,  1292,  1294,  1294,
    1294,  1298,  1299,  1304,  1311,  1310,  1326,  1326,  1329,  1336,
    1345,  1346,  1346,  1350,  1350,  1350,  1350,  1352,  1365,  1371,
    1379,  1382,  1385,  1388,  1390,  1391,  1394,  1399,  1406,  1406,
    1409,  1408,  1414,  1424,  1424,  1426,  1428,  1428,  1430,  1430,
    1433,  1440,  1442,  1444,  1443,  1448,  1448,  1448,  1448,  1450,
    1465,  1472,  1481,  1487,  1490,  1496,  1498,  1499,  1501,  1506,
    1512,  1512,  1515,  1514,  1520,  1521,  1523,  1526,  1527,  1528,
    1532,  1533,  1534,  1535,  1537,  1538
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
     176,   176,   177,   177,   177,   178,   178,   179,   179,   180,
     181,   181,   182,   182,   183,   184,   184,   185,   186,   186,
     187,   187,   188,   189,   189,   190,   190,   191,   191,   191,
     192,   192,   192,   193,   193,   193,   194,   194,   194,   195,
     195,   195,   196,   196,   196,   197,   197,   197,   198,   199,
     200,   200,   201,   201,   202,   203,   203,   204,   205,   205,
     206,   206,   206,   207,   207,   208,   208,   209,   209,   210,
     210,   211,   211,   211,   212,   212,   213,   213,   213,   213,
     213,   213,   214,   214,   214,   215,   216,   216,   217,   217,
     218,   219,   219,   220,   220,   221,   222,   222,   223,   223,
     224,   225,   225,   226,   226,   227,   228,   228,   229,   229,
     230,   231,   231,   232,   232,   233,   234,   234,   235,   235,
     236,   236,   237,   238,   239,   239,   240,   240,   241,   242,
     242,   243,   244,   244,   245,   245,   245,   246,   247,   247,
     248,   248,   249,   249,   250,   250,   250,   251,   251,   252,
     252,   252,   252,   252,   252,   253,   253,   253,   254,   254,
     254,   255,   255,   255,   256,   256,   256,   257,   257,   257,
     258,   259,   260,   260,   261,   261,   262,   263,   263,   264,
     265,   265,   266,   266,   266,   267,   268,   268,   269,   269,
     270,   270,   271,   271,   271,   272,   272,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   274,   274,
     274,   275,   275,   275,   276,   276,   276,   277,   277,   277,
     278,   278,   278,   279,   280,   281,   281,   282,   282,   283,
     284,   284,   285,   285,   285,   285,   286,   286,   287,   287,
     288,   288,   289,   289,   290,   290,   291,   291,   292,   292,
     293,   293,   294,   295,   295,   296,   296,   297,   298,   298,
     299,   299,   300,   301,   301,   302,   302,   303,   303,   304,
     305,   305,   306,   306,   307,   308,   308,   309,   309,   310,
     311,   311,   312,   312,   313,   314,   314,   315,   315,   316,
     317,   318,   318,   319,   319,   320,   321,   321,   322,   323,
     323,   324,   324,   324,   325,   326,   326,   327,   327,   328,
     328,   329,   329,   330,   330,   331,   331,   331,   331,   332,
     333,   334,   335,   336,   336,   337,   338,   338,   339,   340,
     341,   341,   342,   342,   343,   344,   345,   346,   347,   347,
     348,   348,   348,   348,   348,   349,   349,   350,   350,   351,
     352,   352,   353,   354,   354,   355,   355,   356,   357,   357,
     358,   358,   359,   359,   359,   359,   360,   360,   361,   361,
     362,   362,   363,   364,   365,   365,   365,   366,   367,   367,
     368,   369,   370,   370,   371,   371,   371,   372,   373,   373,
     374,   374,   374,   375,   376,   376,   376,   377,   378,   378,
     379,   380,   381,   381,   383,   382,   384,   385,   386,   386,
     387,   387,   387,   387,   388,   389,   389,   390,   390,   391,
     391,   392,   392,   393,   393,   394,   395,   396,   397,   397,
     397,   398,   398,   399,   399,   400,   400,   401,   402,   403,
     403,   403,   404,   405,   405,   406,   407,   408,   408,   409,
     409,   410,   411,   412,   412,   413,   413,   413,   413,   414,
     415,   415,   416,   416,   417,   417,   418,   418,   419,   419,
     420,   421,   422,   423,   423,   423,   424,   424,   425,   425,
     426,   426,   427,   428,   429,   429,   429,   430,   431,   431,
     432,   433,   434,   434,   435,   435,   436,   437,   438,   438,
     439,   439,   439,   439,   440,   441,   441,   442,   442,   443,
     443,   444,   444,   445,   445,   446,   447,   448,   449,   449,
     449,   450,   450,   450,   452,   451,   453,   453,   454,   454,
     455,   456,   455,   457,   457,   457,   457,   458,   459,   459,
     460,   460,   461,   461,   462,   462,   463,   463,   464,   464,
     466,   465,   467,   468,   468,   469,   470,   470,   471,   471,
     472,   472,   473,   474,   473,   475,   475,   475,   475,   476,
     477,   477,   478,   478,   479,   479,   480,   480,   481,   481,
     482,   482,   484,   483,   485,   485,   486,   487,   487,   487,
     488,   488,   488,   488,   489,   489
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     3,     0,     2,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     3,     1,     3,     1,     4,
       1,     1,     2,     1,     3,     1,     2,     3,     0,     2,
       1,     1,     3,     3,     1,     2,     1,     4,     3,     2,
       4,     3,     2,     4,     3,     2,     4,     3,     2,     4,
       3,     2,     4,     3,     2,     4,     3,     2,     3,     4,
       1,     1,     2,     1,     3,     1,     2,     3,     0,     2,
       1,     1,     1,     3,     1,     3,     1,     3,     1,     2,
       1,     0,     2,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     4,     3,     2,     5,     0,     2,     1,     1,
       3,     3,     1,     1,     1,     5,     0,     2,     1,     1,
       3,     3,     1,     1,     1,     5,     0,     2,     1,     1,
       3,     3,     1,     1,     1,     5,     0,     2,     3,     1,
       1,     1,     3,     4,     1,     1,     2,     1,     3,     1,
       2,     3,     0,     2,     1,     1,     1,     3,     3,     1,
       3,     1,     2,     1,     0,     2,     4,     0,     2,     1,
       1,     1,     1,     1,     1,     4,     3,     2,     4,     3,
       2,     4,     3,     2,     4,     3,     2,     4,     3,     2,
       3,     4,     1,     1,     2,     1,     3,     1,     2,     3,
       0,     2,     1,     1,     1,     3,     3,     1,     3,     1,
       2,     1,     0,     2,     4,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       2,     4,     3,     2,     4,     3,     2,     4,     3,     2,
       4,     3,     2,     3,     4,     1,     3,     0,     2,     3,
       0,     2,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     2,     1,     3,     0,
       1,     1,     5,     0,     2,     1,     1,     3,     3,     1,
       1,     1,     5,     0,     2,     3,     1,     1,     1,     5,
       0,     2,     1,     1,     3,     3,     1,     1,     1,     5,
       0,     2,     1,     1,     3,     3,     1,     1,     1,     3,
       4,     1,     1,     2,     1,     3,     1,     2,     3,     0,
       2,     1,     1,     1,     3,     3,     1,     3,     1,     2,
       1,     0,     3,     0,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     1,     2,     0,     2,     3,     1,
       0,     2,     1,     1,     4,     3,     8,     3,     1,     2,
       3,     1,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     3,     0,     2,     1,     1,     3,     3,     1,
       2,     1,     0,     4,     3,     2,     0,     3,     0,     4,
       1,     1,     1,     6,     0,     5,     3,     4,     0,     2,
       5,     4,     1,     1,     0,     5,     3,     4,     0,     2,
       5,     4,     3,     4,     0,     5,     3,     4,     0,     2,
       5,     4,     0,     2,     0,     4,     1,     1,     0,     2,
       1,     1,     1,     1,     4,     1,     3,     1,     3,     3,
       1,     1,     3,     0,     2,     3,     1,     4,     3,     2,
       1,     0,     3,     0,     4,     1,     1,     1,     4,     0,
       5,     3,     4,     0,     2,     5,     4,     1,     1,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     3,     1,     1,     3,     0,     2,
       3,     1,     4,     3,     2,     1,     0,     3,     0,     4,
       1,     1,     1,     4,     0,     5,     3,     4,     0,     2,
       5,     4,     1,     1,     0,     2,     3,     1,     0,     2,
       1,     1,     1,     1,     4,     1,     3,     1,     3,     3,
       1,     1,     3,     0,     2,     3,     1,     4,     3,     2,
       1,     0,     5,     3,     0,     5,     0,     2,     5,     3,
       0,     0,     3,     1,     1,     1,     1,     4,     1,     3,
       3,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       0,     4,     1,     0,     3,     4,     1,     3,     0,     2,
       5,     3,     0,     0,     3,     1,     1,     1,     1,     4,
       1,     3,     3,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     0,     4,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     3,     0,     1,     0,    91,     4,
       8,     6,     0,   164,     0,    94,    92,     0,   212,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
     167,   165,     0,   331,     0,     0,    28,     0,    26,     0,
      20,    22,    23,    24,     0,    58,     0,    61,     0,    49,
     614,     0,     0,    55,     0,    52,     0,    64,     0,    67,
      93,   136,   126,   106,   116,     0,     0,    95,    96,    97,
      98,    99,   100,   101,     0,   215,   213,   333,     0,     0,
     614,   614,     0,    33,    21,    19,    30,    31,     0,    57,
       0,    60,     0,    48,     0,     0,     0,    73,    68,    70,
      71,     0,    54,     0,    51,     0,    63,     0,    66,     0,
       0,     0,     0,   614,     0,     0,   104,   166,     0,     0,
       0,     0,     0,     0,   168,   169,   170,   171,   172,   173,
     174,     0,     0,     2,     0,    27,    25,    32,    38,     0,
      35,    56,    59,    47,   614,   606,   610,   611,   612,   613,
     615,    78,    72,     0,    75,    53,    50,    62,    65,     0,
       0,   139,   137,     0,     0,   132,     0,   127,   128,   129,
       0,     0,   112,     0,   107,   108,   109,     0,     0,   122,
       0,   117,   118,   119,     0,     0,   147,   142,   144,   145,
       0,   103,     0,   180,     0,   177,   614,     0,     0,   189,
       0,   186,     0,   183,   214,     0,     0,     0,     0,     0,
       0,     0,   283,   273,   290,   300,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   346,   344,
     614,   614,   614,   614,   334,   614,   614,   614,   614,   332,
      29,     0,    34,    36,    69,     0,    74,    76,   140,   141,
       0,   614,   133,   134,     0,   614,   614,   113,   114,     0,
     614,   614,   123,   124,     0,   614,   614,   614,   152,   146,
       0,   149,   102,     0,   179,     0,   176,     0,     0,   195,
     190,   192,   193,   604,   605,   188,     0,     0,   185,     0,
     182,     0,   239,     0,   242,   614,     0,     0,   236,     0,
     230,     0,   233,     0,     0,     0,     0,     0,     0,     0,
     573,     0,     0,     0,     0,   335,   336,   337,   338,     0,
      46,     0,    44,     0,    39,    40,    41,    37,     0,    90,
       0,    88,     0,    84,     0,    86,    79,    80,    81,    82,
      77,   135,   138,   125,   131,   130,   105,   111,   110,   115,
     121,   120,   143,     0,   148,   150,   178,   175,   614,   200,
     194,     0,   197,   187,   184,   181,     0,   238,     0,   241,
       0,     0,   314,   309,   311,   312,     0,   235,     0,   229,
       0,   232,     0,   247,   245,   243,     0,     0,   286,   284,
       0,     0,   279,     0,   274,   275,   276,     0,     0,   296,
       0,   291,   292,   293,     0,     0,   306,     0,   301,   302,
     303,   343,     0,   349,   347,   350,   345,   341,   342,   339,
     340,    45,     0,     0,    89,   614,   614,   614,     0,   163,
       0,   161,     0,     0,   159,   153,   154,   155,   156,   151,
     191,     0,   196,   198,   237,   240,   614,   319,   313,     0,
     316,   234,   228,   231,     0,     0,   287,   288,     0,   614,
     280,   281,     0,   614,   614,   297,   298,     0,   614,   614,
     307,   308,     0,   614,   614,   614,     0,     0,    43,    42,
      87,    83,    85,   162,   614,   614,   614,     0,   211,     0,
     209,     0,     0,   207,   201,   202,   203,   204,   199,   310,
       0,   315,   317,   244,   250,   246,   248,   282,   285,   272,
     278,   277,   289,   295,   294,   299,   305,   304,     0,   578,
     576,   574,     0,   614,     0,   351,   352,   353,   348,   160,
     157,   158,   210,   614,   614,   614,     0,   330,     0,   328,
       0,     0,   326,   320,   321,   322,   323,   318,   269,   614,
       0,     0,   382,     0,   614,   208,   205,   206,   329,   614,
     614,   614,     0,   267,     0,   259,     0,   263,     0,   257,
       0,   261,   251,   252,   253,   254,   255,   249,   264,   265,
     575,   577,   582,   579,     0,     0,   363,     0,   361,     0,
     358,     0,   386,   614,   355,   327,   324,   325,   271,   270,
     266,     0,     0,     0,     0,     0,   583,     0,   614,   614,
       0,   368,   359,   357,   365,   366,     0,   385,   388,   451,
     354,   268,   258,   262,   256,   260,   596,   581,     0,     0,
     362,   360,   367,   373,     0,   370,     0,   384,   614,     0,
     453,   496,     0,     0,     0,   593,     0,   595,     0,   590,
     584,   585,   586,   587,   588,   364,     0,   369,   371,   383,
       0,   394,   392,   387,   390,   391,   614,     0,   498,   541,
       0,   600,   601,   580,   597,   598,   599,     0,     0,     0,
       0,     0,   381,     0,   379,     0,   374,   375,   376,   372,
     614,     0,   404,     0,   459,   457,   452,   455,   456,   614,
       0,     0,     0,   602,     0,   592,   594,   591,   380,     0,
       0,   389,   614,     0,     0,   414,   614,     0,   469,     0,
     504,   502,   497,   500,   501,     0,     0,   572,   356,     0,
     589,   378,   377,     0,   398,   396,   614,     0,     0,   422,
     454,   614,     0,     0,   614,     0,   514,     0,   546,   543,
     603,   614,     0,     0,   408,   406,   614,     0,     0,     0,
     463,   461,   458,   472,   470,   473,   499,   614,     0,     0,
     544,     0,   397,   395,     0,   399,   614,     0,     0,   418,
     416,   426,   393,   423,   428,   614,     0,     0,     0,   508,
     506,   503,   517,   515,   518,     0,   550,   542,   547,   614,
       0,   407,   405,     0,   409,   614,     0,   424,   427,   462,
       0,   460,   464,   488,   486,   614,     0,   485,     0,   482,
       0,   480,   474,   475,   476,   477,   478,   471,   614,     0,
       0,   545,   551,     0,     0,   614,     0,   417,   415,     0,
     419,     0,   614,     0,   440,     0,   437,     0,   435,   429,
     430,   431,   432,   433,   614,     0,     0,     0,   614,   614,
     614,   507,     0,   505,   509,   533,   531,   614,     0,   530,
       0,   527,     0,   525,   519,   520,   521,   522,   523,   516,
     564,   549,     0,   614,   402,   403,     0,     0,     0,   412,
     614,     0,   443,   441,   425,     0,   614,   614,   614,     0,
       0,   491,   487,   489,     0,   614,   484,   483,   481,   614,
       0,     0,     0,   614,   614,   614,     0,     0,     0,   561,
       0,   563,     0,   558,   552,   553,   554,   555,   556,   401,
     400,   614,     0,   411,     0,     0,     0,   614,   439,   438,
     436,   614,   467,   468,     0,   614,     0,   479,     0,     0,
     536,   532,   534,     0,   614,   529,   528,   526,     0,   568,
     569,   548,   565,   566,   567,     0,     0,     0,   614,   413,
     410,   614,     0,   442,   446,   444,     0,   434,   466,   465,
       0,     0,   495,   490,   614,   513,   512,     0,   614,     0,
     524,   570,     0,   560,   562,   559,   421,   420,   614,     0,
     614,   607,   608,   609,   494,     0,   511,   510,     0,     0,
     540,   535,     0,   557,     0,     0,   450,   445,   492,   493,
     614,   539,     0,   571,   614,   449,     0,   537,   538,   447,
     448
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    29,    30,    49,    50,    51,
      52,    53,    95,    96,    97,   149,   150,   251,   334,   335,
     336,   337,    31,    32,    33,    34,    35,    36,    37,    38,
      61,   108,   109,   110,   163,   164,   255,   346,   347,   348,
     349,   350,    13,    39,    77,    78,    79,   121,   184,   185,
     186,   269,    80,   122,   191,   192,   193,   274,    81,   120,
     177,   178,   179,   264,    82,   119,   172,   260,    83,   124,
     197,   198,   199,   280,   281,   363,   445,   446,   447,   448,
     449,    18,    84,   134,   135,   136,   137,   138,   139,   140,
     207,   290,   291,   292,   371,   372,   451,   504,   505,   506,
     507,   508,    43,   141,   226,   227,   228,   229,   230,   231,
     232,   314,   395,   465,   516,   558,   582,   583,   584,   585,
     586,   587,   588,   589,   611,   233,   316,   404,   405,   406,
     472,   234,   315,   399,   468,   235,   317,   411,   412,   413,
     477,   236,   318,   418,   419,   420,   482,   237,   306,   383,
     384,   385,   459,   460,   510,   553,   554,   555,   556,   557,
      88,   142,   244,   245,   246,   247,   248,   249,   319,   320,
     424,   425,   487,   535,   536,   537,   538,   562,   599,   600,
     623,   624,   625,   644,   645,   666,   696,   697,   698,   699,
     602,   629,   649,   673,   674,   675,   702,   723,   762,   785,
     810,   896,   725,   747,   787,   814,   846,   749,   767,   816,
     850,   901,   768,   793,   851,   794,   817,   818,   859,   860,
     861,   862,   863,   904,   946,   985,   986,  1009,  1027,   651,
     677,   706,   707,   708,   728,   752,   796,   822,   865,   954,
     753,   774,   775,   797,   832,   833,   834,   835,   836,   837,
     866,   913,   914,   956,   993,   679,   710,   732,   733,   734,
     756,   778,   839,   874,   920,   997,   779,   803,   804,   840,
     884,   885,   886,   887,   888,   889,   921,   962,   963,   999,
    1021,   712,   736,   805,   781,   808,   842,   892,   934,   935,
     936,   937,   938,   926,   972,   973,   974,  1022,   738,   426,
     486,   531,   560,   593,   616,   638,   660,   661,   662,   663,
     664,   652,   684,   685,   686,   739,   296,   104,  1015,   160,
     105
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -854
static const yytype_int16 yypact[] =
{
      33,    34,    70,    36,  -854,    84,  -854,   167,    59,  -854,
    -854,  -854,   198,    77,   -20,  -854,  -854,   264,    80,  -854,
     331,   269,   275,   304,   122,   330,   371,   375,   380,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   -16,
    -854,  -854,   386,    93,   171,   200,  -854,   239,  -854,   266,
    -854,  -854,  -854,  -854,    32,  -854,    19,  -854,    26,  -854,
    -854,   388,    13,  -854,    12,  -854,    11,  -854,     0,  -854,
    -854,  -854,  -854,  -854,  -854,   214,   390,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   -19,  -854,  -854,  -854,   143,   244,
    -854,  -854,   -44,  -854,  -854,  -854,  -854,  -854,   177,  -854,
     192,  -854,   196,  -854,   300,    -6,    -4,  -854,  -854,  -854,
    -854,   210,  -854,   221,  -854,   222,  -854,   213,  -854,    49,
      98,   216,   233,  -854,   392,    10,  -854,  -854,   397,   399,
     341,   401,   403,   405,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   -37,   321,  -854,   363,  -854,  -854,  -854,  -854,   -33,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,   128,  -854,  -854,  -854,  -854,  -854,   411,
     373,  -854,  -854,   413,   384,  -854,   389,  -854,  -854,  -854,
     415,   439,  -854,   449,  -854,  -854,  -854,   417,   502,  -854,
     505,  -854,  -854,  -854,   372,   135,  -854,  -854,  -854,  -854,
     288,  -854,    31,  -854,    35,  -854,  -854,   416,    14,  -854,
       1,  -854,    -3,  -854,  -854,   418,   420,   475,   422,   424,
     426,   443,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   278,  -854,  -854,  -854,   187,  -854,  -854,  -854,  -854,
     445,  -854,  -854,  -854,   447,  -854,  -854,  -854,  -854,   451,
    -854,  -854,  -854,  -854,   441,  -854,  -854,  -854,  -854,  -854,
     175,  -854,  -854,   434,  -854,   433,  -854,   503,   207,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   394,   370,  -854,   374,
    -854,    24,  -854,    39,  -854,  -854,   428,    18,  -854,    15,
    -854,     7,  -854,   510,   430,   163,   235,   259,   262,   466,
     -49,   513,   516,   518,   519,  -854,  -854,  -854,  -854,   391,
    -854,   524,  -854,   527,  -854,  -854,  -854,  -854,   425,  -854,
     528,  -854,   530,  -854,   531,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,   191,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   224,  -854,  -854,  -854,  -854,   473,  -854,   453,  -854,
     529,   229,  -854,  -854,  -854,  -854,   421,  -854,   406,  -854,
     408,  -854,   533,  -854,  -854,  -854,   438,   539,  -854,  -854,
     440,   540,  -854,   541,  -854,  -854,  -854,   442,   542,  -854,
     543,  -854,  -854,  -854,   444,   544,  -854,   545,  -854,  -854,
    -854,  -854,   526,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,   546,   547,  -854,  -854,  -854,  -854,   455,  -854,
     548,  -854,   549,   550,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   206,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   230,
    -854,  -854,  -854,  -854,   551,   -72,  -854,  -854,   407,  -854,
    -854,  -854,   409,  -854,  -854,  -854,  -854,   404,  -854,  -854,
    -854,  -854,   395,  -854,  -854,  -854,   446,    68,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,   457,  -854,   558,
    -854,   560,   562,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
     219,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   561,  -854,
    -854,  -854,   436,  -854,   565,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   463,  -854,   566,  -854,
     568,   569,  -854,  -854,  -854,  -854,  -854,  -854,   225,  -854,
     -68,   337,   477,   570,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,     6,  -854,   571,  -854,   572,  -854,   574,  -854,
     575,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   573,   576,  -854,   577,  -854,   272,
    -854,   448,   423,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   458,   579,   580,   581,   582,   450,   578,  -854,  -854,
     223,  -854,  -854,  -854,  -854,  -854,    27,  -854,   583,   483,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   287,   584,
    -854,  -854,  -854,  -854,   231,  -854,   494,  -854,  -854,   452,
     564,   515,    25,   586,   592,  -854,   593,  -854,   595,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   178,  -854,  -854,  -854,
     594,   459,  -854,  -854,  -854,  -854,  -854,   454,   585,   487,
     596,  -854,  -854,  -854,  -854,  -854,  -854,   597,   598,   599,
     600,   470,  -854,   606,  -854,   608,  -854,  -854,  -854,  -854,
    -854,   587,   464,   610,   461,  -854,  -854,  -854,  -854,  -854,
     456,   601,   498,  -854,   604,  -854,  -854,  -854,  -854,   612,
     616,  -854,  -854,   460,   588,   553,  -854,   603,  -854,   620,
     554,  -854,  -854,  -854,  -854,   619,   462,  -854,  -854,   589,
    -854,  -854,  -854,   622,  -854,  -854,  -854,   465,   605,  -854,
    -854,  -854,   467,   -60,  -854,   617,  -854,   624,  -854,  -854,
    -854,  -854,   215,   627,  -854,  -854,  -854,   472,   -64,   628,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   474,   -39,
    -854,   267,  -854,  -854,   611,  -854,  -854,   327,   629,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   -66,   159,   631,  -854,
    -854,  -854,  -854,  -854,  -854,   633,  -854,  -854,  -854,  -854,
     632,  -854,  -854,   614,  -854,  -854,   -63,  -854,   318,  -854,
     615,  -854,  -854,  -854,  -854,  -854,   636,  -854,   642,  -854,
     643,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   -23,
     172,  -854,   478,   641,   484,  -854,   482,  -854,  -854,   621,
    -854,   485,  -854,   646,  -854,   648,  -854,   649,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,   644,    41,   647,  -854,  -854,
    -854,  -854,   626,  -854,  -854,  -854,  -854,  -854,   654,  -854,
     655,  -854,   656,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,   293,  -854,  -854,  -854,   499,   657,     3,  -854,
    -854,   652,  -854,  -854,  -854,   659,  -854,  -854,  -854,   660,
     491,  -854,  -854,  -854,   638,  -854,  -854,  -854,  -854,  -854,
     658,   -38,   663,  -854,  -854,  -854,   107,   662,   669,  -854,
     670,  -854,   671,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,   514,  -854,   672,   673,   -56,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   590,  -854,   489,  -854,   674,   495,
    -854,  -854,  -854,   650,  -854,  -854,  -854,  -854,   676,  -854,
    -854,  -854,  -854,  -854,  -854,   677,   678,   680,  -854,  -854,
    -854,  -854,   521,  -854,  -854,  -854,   661,  -854,  -854,  -854,
     679,    20,  -854,  -854,  -854,  -854,  -854,   607,  -854,   493,
    -854,  -854,   683,  -854,  -854,  -854,  -854,  -854,  -854,   496,
    -854,  -854,  -854,  -854,  -854,   602,  -854,  -854,   686,    51,
    -854,  -854,   634,  -854,   688,     2,  -854,  -854,  -854,  -854,
    -854,  -854,   618,  -854,  -854,  -854,   536,  -854,  -854,  -854,
    -854
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   651,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,   555,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,   535,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   419,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,   332,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,   243,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   108,
    -854,  -854,  -854,  -854,    62,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,   -90,  -853,  -854,
    -854
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     145,   146,   155,   299,   117,   297,  1011,   942,  1012,  1013,
     848,   390,   608,   609,   200,   115,   113,   111,   214,   388,
     293,   294,   386,   100,  1011,   215,  1012,  1013,   376,    19,
     102,   646,   820,   194,   127,    70,    98,   283,   960,   285,
     801,   772,   791,   378,     4,   147,   773,   591,    71,   216,
      72,   983,    73,   872,    74,  1011,   252,  1012,  1013,   169,
     592,   128,   873,   129,   254,   422,   514,   802,    20,   961,
       6,   217,    21,   515,    22,   423,    23,     1,   532,   218,
       5,   170,   171,   680,     7,   681,   682,   377,    24,   130,
     148,   821,    75,   219,     9,   220,   533,   849,    25,   792,
      26,   148,   161,   131,   984,   162,    27,   221,   173,    12,
     534,   222,   284,   223,   101,   224,   287,   225,   286,  1014,
      76,   132,    28,   103,   647,    99,   379,   133,  1031,    17,
     174,   175,   112,   114,    42,   387,   176,   295,   116,   911,
     391,    60,   298,   118,   300,   610,   389,   201,   912,    87,
     321,   322,   323,   324,   683,   325,   326,   327,   328,   156,
     157,   158,   159,  1035,   943,   968,  1032,   969,   970,   823,
     824,   352,  1036,   396,   825,   354,   355,    10,    11,    89,
     357,   358,   875,   876,   877,   360,   361,   362,   691,   692,
     143,   826,   827,   828,   829,   397,   398,   338,   339,   830,
     831,   438,   439,    90,   878,   879,   880,   881,    15,    16,
     693,   694,   882,   883,   695,   380,   497,   498,   971,   340,
     341,   342,   343,   440,   441,   442,   180,   344,   345,   546,
     547,   443,   444,   123,   161,   572,   573,   256,   499,   500,
     501,   278,    91,   187,   279,   400,   502,   503,   181,   182,
     144,   548,   549,   550,   183,   574,   575,   576,   577,   551,
     552,   578,   579,   580,   581,   188,   189,   401,   402,   407,
     151,   190,   414,   403,    40,    41,    92,    93,   450,    54,
      55,   278,   620,   621,   364,    56,    57,   152,   329,   330,
      44,   408,   409,   153,   415,   416,   594,   410,    45,    46,
     417,   653,    47,    48,   595,   596,   154,   927,   597,   598,
     331,   332,   333,   369,    58,    59,   370,   654,   655,   656,
     657,   658,   659,   928,   929,   930,   931,   932,   933,   165,
     369,   238,   239,   452,   240,   457,   457,   241,   458,   511,
      62,    63,   166,   242,   852,   490,   491,   492,   243,   167,
     853,   854,   855,   856,   642,    44,   168,   643,   857,   858,
     206,   594,   667,    45,    46,   643,   509,    47,    48,   595,
     596,   250,   783,   597,   598,   784,   261,   806,   277,   518,
     807,    64,    65,   520,   521,    66,    67,   265,   523,   524,
      68,    69,   266,   526,   527,   528,    85,    86,   106,   107,
     125,   126,   195,   196,   539,   540,   541,   202,   203,   204,
     205,   208,   209,   210,   211,   212,   213,   258,   259,   262,
     263,   267,   268,   272,   273,   282,   288,   289,   301,   302,
     303,   304,   307,   308,   309,   310,   311,   312,   381,   382,
     393,   394,   270,   563,   466,   467,   470,   471,   475,   476,
     480,   481,   271,   565,   566,   567,   529,   530,   626,   627,
     636,   637,   671,   672,   704,   705,   730,   731,   313,   590,
     744,   745,   758,   759,   604,   764,   765,   770,   771,   605,
     606,   607,   789,   790,   799,   800,   812,   813,   890,   891,
     894,   895,   898,   899,   305,   902,   903,   952,   953,   991,
     992,   995,   996,  1019,  1020,   275,  1025,  1026,   276,   368,
     351,   374,   359,   630,   353,   366,   367,   373,   392,   427,
     356,   375,   428,   421,   429,   430,   431,   432,   640,   641,
     433,   435,   434,   436,   437,   456,   454,   462,   461,   464,
     455,   463,   469,   473,   474,   478,   479,   483,   484,   485,
     525,   494,   495,   496,   488,   489,   517,   522,   670,   513,
     519,   543,   493,   544,   542,   545,   561,   559,   564,   569,
     568,   570,   571,   601,   612,   613,   603,   614,   615,   618,
     619,   617,   676,   650,   639,   628,   703,   632,   633,   634,
     635,   669,   665,   678,   687,   688,   689,   631,   690,   711,
     700,   713,   709,   714,   648,   718,   715,   716,   717,   719,
     721,   720,   740,   722,   746,   701,   726,   727,   751,   729,
     741,   735,   724,   737,   742,   748,   754,   757,   761,   777,
     780,   766,   743,   786,   795,   815,   750,   838,   755,   868,
     809,   841,   844,   845,   864,   869,   870,   893,   760,   906,
     900,   907,   908,   915,   910,   919,   763,   923,   924,   925,
     940,   769,   945,   941,   776,   947,   951,   955,   959,   964,
     975,   782,   976,   977,   978,   980,   788,   982,   981,   998,
     994,  1001,  1007,  1002,  1017,  1010,  1003,   798,  1004,   989,
    1008,  1023,  1030,  1033,  1034,  1038,   811,  1040,   257,   365,
      94,  1029,   512,   453,   253,   819,   668,   622,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   843,
       0,     0,     0,     0,     0,   847,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   867,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   871,     0,
       0,     0,     0,     0,     0,   897,     0,     0,     0,     0,
       0,     0,   905,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   909,     0,     0,     0,   916,   917,
     918,     0,     0,     0,     0,     0,     0,   922,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   939,     0,     0,     0,     0,     0,     0,
     944,     0,     0,     0,     0,     0,   948,   949,   950,     0,
       0,     0,     0,     0,     0,   957,     0,     0,     0,   958,
       0,     0,     0,   965,   966,   967,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   979,     0,     0,     0,     0,     0,   987,     0,     0,
       0,   988,     0,     0,     0,   990,     0,     0,     0,     0,
       0,     0,     0,     0,  1000,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1005,     0,
       0,  1006,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1016,     0,     0,     0,  1018,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1024,     0,
    1028,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1037,     0,     0,     0,  1039
};

static const yytype_int16 yycheck[] =
{
      90,    91,     8,     6,     4,     4,     4,     4,     6,     7,
      73,     4,     6,     7,     4,     4,     4,     4,    55,     4,
       6,     7,     4,     4,     4,    62,     6,     7,     4,    49,
       4,     4,    98,   123,    53,    51,     4,     6,    76,     4,
      79,   101,   106,     4,    10,    89,   106,   115,    64,    86,
      66,   107,    68,    76,    70,     4,    89,     6,     7,    10,
     128,    80,    85,    82,   154,   114,   138,   106,    88,   107,
       0,   108,    92,   145,    94,   124,    96,    44,    10,   116,
      46,    32,    33,    58,    48,    60,    61,    63,   108,   108,
     134,   157,   108,   130,    10,   132,    28,   160,   118,   163,
     120,   134,   106,   122,   160,   109,   126,   144,    10,    50,
      42,   148,    81,   150,    95,   152,   206,   154,    83,    99,
     136,   140,   142,    97,    97,    93,    87,   146,    77,    52,
      32,    33,   119,   121,    54,   117,    38,   123,   127,    98,
     133,    19,   141,   143,   147,   139,   131,   137,   107,    56,
     240,   241,   242,   243,   129,   245,   246,   247,   248,   165,
     166,   167,   168,   161,   161,    58,  1019,    60,    61,    10,
      11,   261,  1025,    10,    15,   265,   266,    10,    11,     8,
     270,   271,    10,    11,    12,   275,   276,   277,    10,    11,
      47,    32,    33,    34,    35,    32,    33,    10,    11,    40,
      41,    10,    11,     3,    32,    33,    34,    35,    10,    11,
      32,    33,    40,    41,    36,   305,    10,    11,   111,    32,
      33,    34,    35,    32,    33,    34,    10,    40,    41,    10,
      11,    40,    41,    19,   106,    10,    11,   109,    32,    33,
      34,   106,     3,    10,   109,    10,    40,    41,    32,    33,
       6,    32,    33,    34,    38,    30,    31,    32,    33,    40,
      41,    36,    37,    38,    39,    32,    33,    32,    33,    10,
      93,    38,    10,    38,    10,    11,    10,    11,   368,    10,
      11,   106,    10,    11,   109,    10,    11,    95,    10,    11,
      24,    32,    33,    97,    32,    33,    24,    38,    32,    33,
      38,    14,    36,    37,    32,    33,     6,    14,    36,    37,
      32,    33,    34,   106,    10,    11,   109,    30,    31,    32,
      33,    34,    35,    30,    31,    32,    33,    34,    35,   119,
     106,    10,    11,   109,    13,   106,   106,    16,   109,   109,
      10,    11,   121,    22,    26,   435,   436,   437,    27,   127,
      32,    33,    34,    35,   131,    24,   143,   134,    40,    41,
      19,    24,   131,    32,    33,   134,   456,    36,    37,    32,
      33,     8,   157,    36,    37,   160,     3,   110,     6,   469,
     113,    10,    11,   473,   474,    10,    11,     3,   478,   479,
      10,    11,     3,   483,   484,   485,    10,    11,    10,    11,
      10,    11,    10,    11,   494,   495,   496,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,     6,     7,     6,
       7,     6,     7,     6,     7,   137,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,     3,   533,     6,     7,     6,     7,     6,     7,
       6,     7,     3,   543,   544,   545,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    25,   559,
      10,    11,    10,    11,   564,    10,    11,    10,    11,   569,
     570,   571,    10,    11,    10,    11,   159,   160,    10,    11,
       6,     7,    10,    11,    19,    10,    11,     6,     7,    10,
      11,     6,     7,    10,    11,     3,    10,    11,     3,     6,
      65,   141,    71,   603,    67,    81,    83,   123,     8,     6,
      69,   147,     6,    57,     6,     6,   135,     3,   618,   619,
       3,     3,   107,     3,     3,     6,    63,   131,   117,     6,
      87,   133,     3,     3,     3,     3,     3,     3,     3,    23,
     155,     3,     3,     3,     8,     8,   149,   153,   648,     8,
     151,     3,   107,     3,   107,     3,   130,     6,     3,     3,
     107,     3,     3,    96,     3,     3,     6,     3,     3,     3,
       3,     8,    18,   100,     6,   162,   676,     8,     8,     8,
       8,    97,     8,    78,     8,     3,     3,   139,     3,   112,
       6,     5,    17,     6,    21,   135,     8,     8,     8,     3,
     700,     3,     8,    26,    26,   156,     6,   156,    15,   709,
       8,    20,   158,   125,     8,    72,     6,     8,     6,    12,
       6,    26,   722,     6,     6,     6,   726,     6,    84,     3,
      29,     8,    10,    29,    29,     3,     3,     6,    59,     3,
      29,     3,     3,     6,    10,    29,   746,     3,     3,     3,
     161,   751,    10,     6,   754,     6,     6,    29,    10,     6,
       8,   761,     3,     3,     3,   161,   766,     4,     6,    29,
       6,     5,   161,     6,    77,     6,     8,   777,     8,    99,
      29,     8,     6,    59,     6,    77,   786,   161,   163,   280,
      49,    99,   459,   371,   149,   795,   644,   599,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   809,
      -1,    -1,    -1,    -1,    -1,   815,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   825,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   838,    -1,
      -1,    -1,    -1,    -1,    -1,   845,    -1,    -1,    -1,    -1,
      -1,    -1,   852,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   864,    -1,    -1,    -1,   868,   869,
     870,    -1,    -1,    -1,    -1,    -1,    -1,   877,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   893,    -1,    -1,    -1,    -1,    -1,    -1,
     900,    -1,    -1,    -1,    -1,    -1,   906,   907,   908,    -1,
      -1,    -1,    -1,    -1,    -1,   915,    -1,    -1,    -1,   919,
      -1,    -1,    -1,   923,   924,   925,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   941,    -1,    -1,    -1,    -1,    -1,   947,    -1,    -1,
      -1,   951,    -1,    -1,    -1,   955,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   964,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   978,    -1,
      -1,   981,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   994,    -1,    -1,    -1,   998,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1008,    -1,
    1010,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1030,    -1,    -1,    -1,  1034
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    44,   170,   171,    10,    46,     0,    48,   172,    10,
      10,    11,    50,   211,   173,    10,    11,    52,   250,    49,
      88,    92,    94,    96,   108,   118,   120,   126,   142,   174,
     175,   191,   192,   193,   194,   195,   196,   197,   198,   212,
      10,    11,    54,   271,    24,    32,    33,    36,    37,   176,
     177,   178,   179,   180,    10,    11,    10,    11,    10,    11,
      19,   199,    10,    11,    10,    11,    10,    11,    10,    11,
      51,    64,    66,    68,    70,   108,   136,   213,   214,   215,
     221,   227,   233,   237,   251,    10,    11,    56,   329,     8,
       3,     3,    10,    11,   177,   181,   182,   183,     4,    93,
       4,    95,     4,    97,   486,   489,    10,    11,   200,   201,
     202,     4,   119,     4,   121,     4,   127,     4,   143,   234,
     228,   216,   222,    19,   238,    10,    11,    53,    80,    82,
     108,   122,   140,   146,   252,   253,   254,   255,   256,   257,
     258,   272,   330,    47,     6,   486,   486,    89,   134,   184,
     185,    93,    95,    97,     6,     8,   165,   166,   167,   168,
     488,   106,   109,   203,   204,   119,   121,   127,   143,    10,
      32,    33,   235,    10,    32,    33,    38,   229,   230,   231,
      10,    32,    33,    38,   217,   218,   219,    10,    32,    33,
      38,   223,   224,   225,   486,    10,    11,   239,   240,   241,
       4,   137,    10,    11,    10,    11,    19,   259,    10,    11,
      10,    11,    10,    11,    55,    62,    86,   108,   116,   130,
     132,   144,   148,   150,   152,   154,   273,   274,   275,   276,
     277,   278,   279,   294,   300,   304,   310,   316,    10,    11,
      13,    16,    22,    27,   331,   332,   333,   334,   335,   336,
       8,   186,    89,   185,   486,   205,   109,   204,     6,     7,
     236,     3,     6,     7,   232,     3,     3,     6,     7,   220,
       3,     3,     6,     7,   226,     3,     3,     6,   106,   109,
     242,   243,   137,     6,    81,     4,    83,   486,    10,    11,
     260,   261,   262,     6,     7,   123,   485,     4,   141,     6,
     147,    10,    11,    10,    11,    19,   317,    10,    11,    10,
      11,    10,    11,    25,   280,   301,   295,   305,   311,   337,
     338,   486,   486,   486,   486,   486,   486,   486,   486,    10,
      11,    32,    33,    34,   187,   188,   189,   190,    10,    11,
      32,    33,    34,    35,    40,    41,   206,   207,   208,   209,
     210,    65,   486,    67,   486,   486,    69,   486,   486,    71,
     486,   486,   486,   244,   109,   243,    81,    83,     6,   106,
     109,   263,   264,   123,   141,   147,     4,    63,     4,    87,
     486,    10,    11,   318,   319,   320,     4,   117,     4,   131,
       4,   133,     8,    10,    11,   281,    10,    32,    33,   302,
      10,    32,    33,    38,   296,   297,   298,    10,    32,    33,
      38,   306,   307,   308,    10,    32,    33,    38,   312,   313,
     314,    57,   114,   124,   339,   340,   468,     6,     6,     6,
       6,   135,     3,     3,   107,     3,     3,     3,    10,    11,
      32,    33,    34,    40,    41,   245,   246,   247,   248,   249,
     486,   265,   109,   264,    63,    87,     6,   106,   109,   321,
     322,   117,   131,   133,     6,   282,     6,     7,   303,     3,
       6,     7,   299,     3,     3,     6,     7,   309,     3,     3,
       6,     7,   315,     3,     3,    23,   469,   341,     8,     8,
     486,   486,   486,   107,     3,     3,     3,    10,    11,    32,
      33,    34,    40,    41,   266,   267,   268,   269,   270,   486,
     323,   109,   322,     8,   138,   145,   283,   149,   486,   151,
     486,   486,   153,   486,   486,   155,   486,   486,   486,    10,
      11,   470,    10,    28,    42,   342,   343,   344,   345,   486,
     486,   486,   107,     3,     3,     3,    10,    11,    32,    33,
      34,    40,    41,   324,   325,   326,   327,   328,   284,     6,
     471,   130,   346,   486,     3,   486,   486,   486,   107,     3,
       3,     3,    10,    11,    30,    31,    32,    33,    36,    37,
      38,    39,   285,   286,   287,   288,   289,   290,   291,   292,
     486,   115,   128,   472,    24,    32,    33,    36,    37,   347,
     348,    96,   359,     6,   486,   486,   486,   486,     6,     7,
     139,   293,     3,     3,     3,     3,   473,     8,     3,     3,
      10,    11,   348,   349,   350,   351,    10,    11,   162,   360,
     486,   139,     8,     8,     8,     8,    10,    11,   474,     6,
     486,   486,   131,   134,   352,   353,     4,    97,    21,   361,
     100,   398,   480,    14,    30,    31,    32,    33,    34,    35,
     475,   476,   477,   478,   479,     8,   354,   131,   353,    97,
     486,    10,    11,   362,   363,   364,    18,   399,    78,   424,
      58,    60,    61,   129,   481,   482,   483,     8,     3,     3,
       3,    10,    11,    32,    33,    36,   355,   356,   357,   358,
       6,   156,   365,   486,    10,    11,   400,   401,   402,    17,
     425,   112,   450,     5,     6,     8,     8,     8,   135,     3,
       3,   486,    26,   366,   158,   371,     6,   156,   403,   486,
      10,    11,   426,   427,   428,    20,   451,   125,   467,   484,
       8,     8,     8,   486,    10,    11,    26,   372,    72,   376,
     486,    15,   404,   409,     6,    84,   429,     8,    10,    11,
      59,     6,   367,   486,    10,    11,    26,   377,   381,   486,
      10,    11,   101,   106,   410,   411,   486,    12,   430,   435,
       6,   453,   486,   157,   160,   368,     6,   373,   486,    10,
      11,   106,   163,   382,   384,     6,   405,   412,   486,    10,
      11,    79,   106,   436,   437,   452,   110,   113,   454,    29,
     369,   486,   159,   160,   374,     6,   378,   385,   386,   486,
      98,   157,   406,    10,    11,    15,    32,    33,    34,    35,
      40,    41,   413,   414,   415,   416,   417,   418,     6,   431,
     438,     8,   455,   486,    10,    29,   375,   486,    73,   160,
     379,   383,    26,    32,    33,    34,    35,    40,    41,   387,
     388,   389,   390,   391,    29,   407,   419,   486,     3,     3,
       3,   486,    76,    85,   432,    10,    11,    12,    32,    33,
      34,    35,    40,    41,   439,   440,   441,   442,   443,   444,
      10,    11,   456,     6,     6,     7,   370,   486,    10,    11,
      29,   380,    10,    11,   392,   486,     3,     3,     3,   486,
      10,    98,   107,   420,   421,     6,   486,   486,   486,    29,
     433,   445,   486,     3,     3,     3,   462,    14,    30,    31,
      32,    33,    34,    35,   457,   458,   459,   460,   461,   486,
     161,     6,     4,   161,   486,    10,   393,     6,   486,   486,
     486,     6,     6,     7,   408,    29,   422,   486,   486,    10,
      76,   107,   446,   447,     6,   486,   486,   486,    58,    60,
      61,   111,   463,   464,   465,     8,     3,     3,     3,   486,
     161,     6,     4,   107,   160,   394,   395,   486,   486,    99,
     486,    10,    11,   423,     6,     6,     7,   434,    29,   448,
     486,     5,     6,     8,     8,   486,   486,   161,    29,   396,
       6,     4,     6,     7,    99,   487,   486,    77,   486,    10,
      11,   449,   466,     8,   486,    10,    11,   397,   486,    99,
       6,    77,   487,    59,     6,   161,   487,   486,    77,   486,
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
	}
    break;

  case 23:

    {   if (parserData->generalStatusDescriptionPresent ) 
		    osrlerror(NULL, NULL, parserData, "only one description attribute allowed for generalStatus element");
	    parserData->generalStatusDescriptionPresent = true;
		osresult->setGeneralStatusDescription(parserData->tempStr);
	}
    break;

  case 24:

    { std::cout << "parsed numberOfGeneralSubstatuses" << std::endl;
	}
    break;

  case 25:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 26:

    { parserData->tempStr = "";          }
    break;

  case 27:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 28:

    { parserData->tempStr = "";          }
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
}
    break;

  case 34:

    { std::cout << "parsed </generalStatus" << std::endl;
}
    break;

  case 42:

    { std::cout << "parsed <generalSubstatus name=" << std::endl;
}
    break;

  case 43:

    { std::cout << "parsed generalSubstatus description=" << std::endl;
}
    break;

  case 44:

    { std::cout << "parsed generalSubstatus description=" << std::endl;
}
    break;

  case 47:

    {osresult->setGeneralMessage( (yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;}
    break;

  case 50:

    {osresult->setServiceURI( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval)); parserData->errorText = NULL;}
    break;

  case 53:

    {osresult->setServiceName((yyvsp[(3) - (4)].sval));  free((yyvsp[(3) - (4)].sval));   parserData->errorText = NULL;}
    break;

  case 56:

    {osresult->setInstanceName( (yyvsp[(3) - (4)].sval)) ;  free((yyvsp[(3) - (4)].sval));   parserData->errorText = NULL;}
    break;

  case 59:

    {osresult->setJobID( (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));  parserData->errorText = NULL;}
    break;

  case 62:

    {std::cout << "!!!store solver invoked" << std::endl;}
    break;

  case 65:

    {std::cout << "!!!store time stamp" << std::endl;}
    break;

  case 69:

    {std::cout << "!!!store numberOfOtherGeneralResults" << std::endl;}
    break;

  case 102:

    {}
    break;

  case 110:

    {}
    break;

  case 111:

    {}
    break;

  case 120:

    {}
    break;

  case 121:

    {}
    break;

  case 130:

    {}
    break;

  case 131:

    {}
    break;

  case 138:

    {}
    break;

  case 143:

    {std::cout << "!!!store numberOfOtherSystemResults" << std::endl;}
    break;

  case 175:

    {}
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

  case 191:

    {std::cout << "!!!store numberOfOtherserviceResults" << std::endl;}
    break;

  case 228:

    {}
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

  case 244:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, "number of time measurements cannot be negative");
	parserData->numberOfTimes = (yyvsp[(3) - (4)].ival);
	parserData->ivar = 0;
}
    break;

  case 256:

    {parserData->timeType = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 258:

    {parserData->timeCategory = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 260:

    {parserData->timeUnit = (yyvsp[(2) - (3)].sval);   free((yyvsp[(2) - (3)].sval));}
    break;

  case 262:

    {parserData->timeDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 268:

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

  case 270:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); }
    break;

  case 271:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); }
    break;

  case 277:

    {}
    break;

  case 278:

    {}
    break;

  case 285:

    {}
    break;

  case 294:

    {}
    break;

  case 295:

    {}
    break;

  case 304:

    {}
    break;

  case 305:

    {}
    break;

  case 310:

    {std::cout << "!!!store numberOfOtherjobResults" << std::endl;}
    break;

  case 339:

    {parserData->numberOfSolutions   = (yyvsp[(3) - (3)].ival); osresult->setSolutionNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 340:

    {parserData->numberOfVariables   = (yyvsp[(3) - (3)].ival); osresult->setVariableNumber((yyvsp[(3) - (3)].ival)); }
    break;

  case 341:

    {parserData->numberOfConstraints = (yyvsp[(3) - (3)].ival); osresult->setConstraintNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 342:

    {parserData->numberOfObjectives  = (yyvsp[(3) - (3)].ival); osresult->setObjectiveNumber((yyvsp[(3) - (3)].ival));}
    break;

  case 348:

    {
   if (parserData->solutionIdx == parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, "too many solutions"); 
    parserData->solutionIdx++;
   }
    break;

  case 349:

    {   parserData->numberOfVar = 0;
    parserData->numberOfCon = 0;
    parserData->numberOfObj = 0;
}
    break;

  case 354:

    {
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, "target objective index must be negative");
/*  	osresult->optimization->solution[parserData->solutionIdx]->targetObjectiveIdx = $3;*/
  	osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
 }
    break;

  case 355:

    { parserData->tempStr = (yyvsp[(2) - (3)].sval); }
    break;

  case 360:

    {parserData->statusType = (yyvsp[(2) - (3)].sval); parserData->statusTypePresent = true; free((yyvsp[(2) - (3)].sval));}
    break;

  case 361:

    {parserData->statusType = ""; parserData->statusTypePresent = true;}
    break;

  case 362:

    {parserData->statusDescription = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));}
    break;

  case 363:

    {parserData->statusDescription = "";}
    break;

  case 364:

    {}
    break;

  case 365:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element"); 
		parserData->statusTypePresent = false; 
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	}
    break;

  case 366:

    {	if(parserData->statusTypePresent == false) 
			osrlerror(NULL, NULL, parserData, "a type attribute required for status element");
		osresult->setSolutionStatus(parserData->solutionIdx, parserData->statusType, parserData->statusDescription);
	}
    break;

  case 377:

    { std::cout << "parsed <solutionSubstatus type=" << std::endl;
}
    break;

  case 383:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = $3; */
		osresult->setSolutionMessage(parserData->solutionIdx, (yyvsp[(3) - (4)].sval)); free((yyvsp[(3) - (4)].sval));
	}
    break;

  case 384:

    {/*osresult->optimization->solution[parserData->solutionIdx]->message = "";*/
		osresult->setSolutionMessage(parserData->solutionIdx, "");
	}
    break;

  case 389:

    {  
	osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, (yyvsp[(3) - (4)].ival));
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
	}
    break;

  case 395:

    {
  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  }
    break;

  case 396:

    {
  	if(parserData->numberOfVar != 0){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
  	} else{
 		osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
 	}
  }
    break;

  case 397:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	}
    break;

  case 401:

    { parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = (yyvsp[(3) - (4)].ival);}
    break;

  case 402:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->primalVals.push_back( parserData->primalValPair);  
   }
    break;

  case 403:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); 
 	parserData->primalValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->primalVals.push_back( parserData->primalValPair); 
  }
    break;

  case 405:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
     }
 */  }
    break;

  case 407:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	}
    break;

  case 410:

    {/*parserData->tempVal = $1;  
 	parserData->primalValPair->value = $1;
	parserData->primalVals.push_back( parserData->primalValPair);  */
}
    break;

  case 413:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/}
    break;

  case 415:

    {
/*  	if(parserData->primalVals.size() !=  parserData->numberOfVar){
  		osrlerror(NULL, NULL, parserData, "numberOfVar not consistent with the number of primal values");
      } else{
              osresult->setPrimalVariableValuesSparse(parserData->solutionIdx, parserData->primalVals); 
		osresult->optimization->solution[ parserData->solutionIdx]->variables->values->numberOfVar = parserData->numberOfVar;
      }
 */  }
    break;

  case 417:

    {
	//osresult->setNumberOfPrimalVariableValues(parserData->solutionIdx, $3);
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival);
	}
    break;

  case 421:

    { /*parserData->primalValPair = new IndexValuePair();   parserData->primalValPair->idx = $2;*/}
    break;

  case 424:

    {/*	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	*/}
    break;

  case 425:

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

  case 426:

    {  // parserData->numberOfOtherVariableResults++;
		parserData->otherVarStruct = new OtherVariableResultStruct(); 
		//parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
		//parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	 
		parserData->kounter = 0;
	}
    break;

  case 427:

    {	if(parserData->otherNamePresent == false) 
			osrlerror(NULL, NULL, parserData, "other element requires name attribute"); 
		parserData->ivar = 0;
	}
    break;

  case 434:

    {	
	parserData->otherVarStruct->numberOfVar = (yyvsp[(3) - (4)].ival);
	//std::cout << "This \<other\> element has " << parserData->otherVarStruct->numberOfVar << " \<var\>" << std::endl;
	parserData->otherVarStruct->otherVarText  = new std::string[ parserData->otherVarStruct->numberOfVar];	 
	parserData->otherVarStruct->otherVarIndex = new int[  parserData->otherVarStruct->numberOfVar];	
 	osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->numberOfVar = (yyvsp[(3) - (4)].ival);
}
    break;

  case 435:

    {parserData->tmpOtherValue=""; parserData->otherVarStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = "";*/
}
    break;

  case 436:

    {parserData->tmpOtherValue=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->value = (yyvsp[(2) - (3)].sval);  
/*  osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));}
    break;

  case 437:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
}
    break;

  case 438:

    {
parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true; parserData->otherVarStruct->name = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
 /* osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->name = $2;*/
}
    break;

  case 439:

    {
parserData->tmpOtherDescription=(yyvsp[(2) - (3)].sval); parserData->otherVarStruct->description = (yyvsp[(2) - (3)].sval);  free((yyvsp[(2) - (3)].sval));
  /*osresult->optimization->solution[parserData->solutionIdx]->variables->other[parserData->iOther]->description = $2;*/
}
    break;

  case 445:

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

  case 446:

    {//	if(parserData->otherVarStruct->numberOfVar <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of variables") ;
	}
    break;

  case 447:

    {}
    break;

  case 454:

    {  
/*        osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      }
    break;

  case 460:

    {
	if(parserData->numberOfObj != parserData->objVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfObj not consistent with the number of objective values");	
	}else{

		osresult->setObjectiveValuesSparse(parserData->solutionIdx, parserData->objVals);
	}
}
    break;

  case 462:

    {
			parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 466:

    { parserData->objValPair = new IndexValuePair();   parserData->objValPair->idx = (yyvsp[(3) - (4)].ival);   }
    break;

  case 467:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].ival);                  
	parserData->objVals.push_back( parserData->objValPair);
}
    break;

  case 468:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);  
        parserData->objValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->objVals.push_back( parserData->objValPair);
  }
    break;

  case 472:

    {  // parserData->numberOfOtherObjectiveResults++;
		//parserData->otherObjStruct = new OtherObjectiveResultStruct(); 
		//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
		//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	 
		parserData->kounter = 0;
	}
    break;

  case 479:

    {
	//parserData->otherObjStruct->numberOfObj = $3;
	//parserData->otherObjStruct->otherObjText  = new std::string[ parserData->otherObjStruct->numberOfObj];	 
	//parserData->otherObjStruct->otherObjIndex = new int[  parserData->otherObjStruct->numberOfObj];	
 	//osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->numberOfObj = $3;
}
    break;

  case 480:

    {//parserData->tmpOtherValue=""; parserData->otherObjStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = "";*/
}
    break;

  case 481:

    {//parserData->tmpOtherValue=$2; parserData->otherObjStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));}
    break;

  case 482:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherObjStruct->name = "";
}
    break;

  case 483:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherObjStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->name = $2;*/
}
    break;

  case 484:

    {
//parserData->tmpOtherDescription=$2; parserData->otherObjStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->objectives->other[parserData->iOther]->description = $2;*/
}
    break;

  case 487:

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

  case 490:

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

  case 491:

    {//	if(parserData->otherObjStruct->numberOfObj <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of objectives") ;
	}
    break;

  case 492:

    {}
    break;

  case 499:

    {  
/*        osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, $3);
	 parserData->iOther = 0;
	 parserData->tmpOtherValue = "";
	 parserData->tmpOtherName = "";
	 parserData->tmpOtherDescription = "";
  */      }
    break;

  case 505:

    {/*
	if(parserData->numberOfCon != parserData->dualVals.size()){
		osrlerror(NULL, NULL, parserData, "numberOfCon not consistent with the number of dual values");	
	}else{

		osresult->setDualVariableValuesSparse(parserData->solutionIdx, parserData->dualVals);
		osresult->optimization->solution[ parserData->solutionIdx]->constraints->dualValues->numberOfCon = parserData->numberOfCon;
	}*/
 }
    break;

  case 507:

    {
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 511:

    { parserData->dualValPair = new IndexValuePair();   parserData->dualValPair->idx = (yyvsp[(3) - (4)].ival);}
    break;

  case 512:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].dval);
	parserData->dualVals.push_back( parserData->dualValPair); 		
	}
    break;

  case 513:

    { 	
        parserData->dualValPair->value = (yyvsp[(1) - (1)].ival);
	parserData->dualVals.push_back( parserData->dualValPair); 	
	}
    break;

  case 525:

    {//parserData->tmpOtherValue=""; parserData->otherConStruct->value = "";  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = "";*/
}
    break;

  case 526:

    {//parserData->tmpOtherValue=$2; parserData->otherConStruct->value = $2;  
/*  osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->value = $2; */
  free((yyvsp[(2) - (3)].sval));}
    break;

  case 527:

    { 
//	parserData->tmpOtherName=""; 
//	parserData->otherNamePresent = true; 
//	parserData->otherConStruct->name = "";
}
    break;

  case 528:

    {
//parserData->tmpOtherName=$2; parserData->otherNamePresent = true; parserData->otherConStruct->name = $2;  free($2);
 /* osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->name = $2;*/
}
    break;

  case 529:

    {
//parserData->tmpOtherDescription=$2; parserData->otherConStruct->description = $2;  free($2);
  /*osresult->optimization->solution[parserData->solutionIdx]->constraints->other[parserData->iOther]->description = $2;*/
}
    break;

  case 535:

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

  case 536:

    {//	if(parserData->otherConStruct->numberOfCon <= 0) 
	//		osrlerror(NULL, NULL,  parserData, "must specify the number of constraints") ;
	}
    break;

  case 537:

    {}
    break;

  case 542:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
}
    break;

  case 543:

    {
	if(parserData->iOther < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
		osrlerror(NULL, NULL, parserData, "fewer OtherSolutionResult elements present than stated in  numberOfOtherSolutionResults attribute");
}
    break;

  case 544:

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

  case 548:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
}
    break;

  case 549:

    {
if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");

parserData->iOther++;
}
    break;

  case 551:

    {if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
}
    break;

  case 557:

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

  case 558:

    { 
	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
}
    break;

  case 559:

    {
	parserData->tmpOtherName=(yyvsp[(2) - (3)].sval); parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 560:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));}
    break;

  case 562:

    {
osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = (yyvsp[(2) - (3)].sval);
free((yyvsp[(2) - (3)].sval));}
    break;

  case 565:

    {parserData->kounter++;}
    break;

  case 566:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
}
    break;

  case 567:

    {
if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
}
    break;

  case 570:

    {	parserData->itemContent = (yyvsp[(2) - (2)].sval); free((yyvsp[(2) - (2)].sval));
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
}
    break;

  case 572:

    {

	//
    //delete the old vectors
	osrl_empty_vectors( parserData);
    
}
    break;

  case 580:

    {
/*	if (parserData->kounter < osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "fewer item elements present than given in numberOfItems attribute");
	parserData->iOther++;
*/
}
    break;

  case 583:

    {/*	if(parserData->iOther >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->numberOfOtherSolutionResults)
	osrlerror(NULL, NULL, parserData, "more OtherSolutionResult elements present than in  numberOfOtherSolutionResults attribute");
*/}
    break;

  case 589:

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

  case 590:

    { 
/*	parserData->tmpOtherName=""; 
	parserData->otherNamePresent = true; 
	parserData->otherVarStruct->name = "";
*/
}
    break;

  case 591:

    {
/*	parserData->tmpOtherName=$2; parserData->otherNamePresent = true;
	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->name = $2;
	free($2);
*/
}
    break;

  case 592:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->category = $2;
	free($2);
 */
}
    break;

  case 594:

    {
/*	osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->description = $2;
	free($2);
 */
}
    break;

  case 598:

    {
/* if (parserData->kounter >= osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->numberOfItems)
	osrlerror(NULL, NULL, parserData, "number of <item> elements exceeds numberOfItems specified");
*/}
    break;

  case 599:

    {
/* osresult->optimization->solution[parserData->solutionIdx]->otherSolutionResults->otherSolutionResult[parserData->iOther]->item[parserData->kounter] = parserData->itemContent;
parserData->kounter++;
*/}
    break;

  case 602:

    {/*parserData->itemContent = $2; free($2);*/}
    break;

  case 604:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 605:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 607:

    { parserData->outStr << (yyvsp[(1) - (1)].sval);    free((yyvsp[(1) - (1)].sval)); }
    break;

  case 608:

    { parserData->outStr << (yyvsp[(1) - (1)].ival);  /*free($1);*/ }
    break;

  case 609:

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


