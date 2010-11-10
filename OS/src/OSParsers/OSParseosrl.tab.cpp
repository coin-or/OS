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
     OSRLSTART = 267,
     OSRLSTARTEMPTY = 268,
     OSRLATTRIBUTETEXT = 269,
     OSRLEND = 270,
     NUMBEROFCONATT = 271,
     NUMBEROFCONSTRAINTSATT = 272,
     NUMBEROFELATT = 273,
     NUMBEROFENUMERATIONSATT = 274,
     NUMBEROFIDXATT = 275,
     NUMBEROFITEMSATT = 276,
     NUMBEROFOBJATT = 277,
     NUMBEROFOBJECTIVESATT = 278,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 279,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 280,
     NUMBEROFOTHERRESULTSATT = 281,
     NUMBEROFOTHERSOLUTIONRESULTSATT = 282,
     NUMBEROFOTHERVARIABLERESULTSATT = 283,
     NUMBEROFSOLUTIONSATT = 284,
     NUMBEROFSOLVEROUTPUTSATT = 285,
     NUMBEROFSUBSTATUSESATT = 286,
     NUMBEROFTIMESATT = 287,
     NUMBEROFVARATT = 288,
     NUMBEROFVARIABLESATT = 289,
     NUMBEROFVARIDXATT = 290,
     TARGETOBJECTIVEIDXATT = 291,
     IDXATT = 292,
     INCRATT = 293,
     MULTATT = 294,
     SIZEOFATT = 295,
     CATEGORYATT = 296,
     EMPTYCATEGORYATT = 297,
     DESCRIPTIONATT = 298,
     EMPTYDESCRIPTIONATT = 299,
     NAMEATT = 300,
     EMPTYNAMEATT = 301,
     TYPEATT = 302,
     EMPTYTYPEATT = 303,
     UNITATT = 304,
     EMPTYUNITATT = 305,
     VALUEATT = 306,
     EMPTYVALUEATT = 307,
     WEIGHTEDOBJECTIVESATT = 308,
     EMPTYWEIGHTEDOBJECTIVESATT = 309,
     GENERALSTART = 310,
     GENERALEND = 311,
     SYSTEMSTART = 312,
     SYSTEMEND = 313,
     SERVICESTART = 314,
     SERVICEEND = 315,
     JOBSTART = 316,
     JOBEND = 317,
     OPTIMIZATIONSTART = 318,
     OPTIMIZATIONEND = 319,
     ITEMSTART = 320,
     ITEMEND = 321,
     ITEMSTARTANDEND = 322,
     ITEMEMPTY = 323,
     ACTUALSTARTTIMESTART = 324,
     ACTUALSTARTTIMEEND = 325,
     ATLOWERSTART = 326,
     ATLOWEREND = 327,
     ATUPPERSTART = 328,
     ATUPPEREND = 329,
     AVAILABLECPUNUMBERSTART = 330,
     AVAILABLECPUNUMBEREND = 331,
     AVAILABLECPUSPEEDSTART = 332,
     AVAILABLECPUSPEEDEND = 333,
     AVAILABLEDISKSPACESTART = 334,
     AVAILABLEDISKSPACEEND = 335,
     AVAILABLEMEMORYSTART = 336,
     AVAILABLEMEMORYEND = 337,
     BASE64START = 338,
     BASE64END = 339,
     BASICSTART = 340,
     BASICEND = 341,
     BASISSTATUSSTART = 342,
     BASISSTATUSEND = 343,
     BASSTATUSSTART = 344,
     BASSTATUSEND = 345,
     CONSTART = 346,
     CONEND = 347,
     CONSTRAINTSSTART = 348,
     CONSTRAINTSEND = 349,
     CURRENTJOBCOUNTSTART = 350,
     CURRENTJOBCOUNTEND = 351,
     CURRENTSTATESTART = 352,
     CURRENTSTATEEND = 353,
     DUALVALUESSTART = 354,
     DUALVALUESEND = 355,
     ELSTART = 356,
     ELEND = 357,
     ENUMERATIONSTART = 358,
     ENUMERATIONEND = 359,
     ENDTIMESTART = 360,
     ENDTIMEEND = 361,
     GENERALSTATUSSTART = 362,
     GENERALSTATUSEND = 363,
     GENERALSUBSTATUSSTART = 364,
     GENERALSUBSTATUSEND = 365,
     IDXSTART = 366,
     IDXEND = 367,
     INSTANCENAMESTART = 368,
     INSTANCENAMEEND = 369,
     ISFREESTART = 370,
     ISFREEEND = 371,
     JOBIDSTART = 372,
     JOBIDEND = 373,
     MESSAGESTART = 374,
     MESSAGEEND = 375,
     OBJSTART = 376,
     OBJEND = 377,
     OBJECTIVESSTART = 378,
     OBJECTIVESEND = 379,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 380,
     OPTIMIZATIONSOLUTIONSTATUSEND = 381,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 382,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 383,
     OTHERSTART = 384,
     OTHEREND = 385,
     OTHERRESULTSSTART = 386,
     OTHERRESULTSEND = 387,
     OTHERSOLUTIONRESULTSTART = 388,
     OTHERSOLUTIONRESULTEND = 389,
     OTHERSOLUTIONRESULTSSTART = 390,
     OTHERSOLUTIONRESULTSEND = 391,
     OTHERSOLVEROUTPUTSTART = 392,
     OTHERSOLVEROUTPUTEND = 393,
     SCHEDULEDSTARTTIMESTART = 394,
     SCHEDULEDSTARTTIMEEND = 395,
     SERVICENAMESTART = 396,
     SERVICENAMEEND = 397,
     SERVICEURISTART = 398,
     SERVICEURIEND = 399,
     SERVICEUTILIZATIONSTART = 400,
     SERVICEUTILIZATIONEND = 401,
     SOLUTIONSTART = 402,
     SOLUTIONEND = 403,
     SOLVERINVOKEDSTART = 404,
     SOLVERINVOKEDEND = 405,
     SOLVEROUTPUTSTART = 406,
     SOLVEROUTPUTEND = 407,
     STATUSSTART = 408,
     STATUSEND = 409,
     SUBMITTIMESTART = 410,
     SUBMITTIMEEND = 411,
     SUBSTATUSSTART = 412,
     SUBSTATUSEND = 413,
     SUPERBASICSTART = 414,
     SUPERBASICEND = 415,
     SYSTEMINFORMATIONSTART = 416,
     SYSTEMINFORMATIONEND = 417,
     TIMESTART = 418,
     TIMEEND = 419,
     TIMESERVICESTARTEDSTART = 420,
     TIMESERVICESTARTEDEND = 421,
     TIMESTAMPSTART = 422,
     TIMESTAMPEND = 423,
     TIMINGINFORMATIONSTART = 424,
     TIMINGINFORMATIONEND = 425,
     TOTALJOBSSOFARSTART = 426,
     TOTALJOBSSOFAREND = 427,
     UNKNOWNSTART = 428,
     UNKNOWNEND = 429,
     USEDCPUNUMBERSTART = 430,
     USEDCPUNUMBEREND = 431,
     USEDCPUSPEEDSTART = 432,
     USEDCPUSPEEDEND = 433,
     USEDDISKSPACESTART = 434,
     USEDDISKSPACEEND = 435,
     USEDMEMORYSTART = 436,
     USEDMEMORYEND = 437,
     VALUESSTART = 438,
     VALUESEND = 439,
     VALUESSTRINGSTART = 440,
     VALUESSTRINGEND = 441,
     VARSTART = 442,
     VAREND = 443,
     VARIABLESSTART = 444,
     VARIABLESEND = 445,
     VARIDXSTART = 446,
     VARIDXEND = 447,
     DUMMY = 448
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
#define OSRLSTART 267
#define OSRLSTARTEMPTY 268
#define OSRLATTRIBUTETEXT 269
#define OSRLEND 270
#define NUMBEROFCONATT 271
#define NUMBEROFCONSTRAINTSATT 272
#define NUMBEROFELATT 273
#define NUMBEROFENUMERATIONSATT 274
#define NUMBEROFIDXATT 275
#define NUMBEROFITEMSATT 276
#define NUMBEROFOBJATT 277
#define NUMBEROFOBJECTIVESATT 278
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 279
#define NUMBEROFOTHEROBJECTIVERESULTSATT 280
#define NUMBEROFOTHERRESULTSATT 281
#define NUMBEROFOTHERSOLUTIONRESULTSATT 282
#define NUMBEROFOTHERVARIABLERESULTSATT 283
#define NUMBEROFSOLUTIONSATT 284
#define NUMBEROFSOLVEROUTPUTSATT 285
#define NUMBEROFSUBSTATUSESATT 286
#define NUMBEROFTIMESATT 287
#define NUMBEROFVARATT 288
#define NUMBEROFVARIABLESATT 289
#define NUMBEROFVARIDXATT 290
#define TARGETOBJECTIVEIDXATT 291
#define IDXATT 292
#define INCRATT 293
#define MULTATT 294
#define SIZEOFATT 295
#define CATEGORYATT 296
#define EMPTYCATEGORYATT 297
#define DESCRIPTIONATT 298
#define EMPTYDESCRIPTIONATT 299
#define NAMEATT 300
#define EMPTYNAMEATT 301
#define TYPEATT 302
#define EMPTYTYPEATT 303
#define UNITATT 304
#define EMPTYUNITATT 305
#define VALUEATT 306
#define EMPTYVALUEATT 307
#define WEIGHTEDOBJECTIVESATT 308
#define EMPTYWEIGHTEDOBJECTIVESATT 309
#define GENERALSTART 310
#define GENERALEND 311
#define SYSTEMSTART 312
#define SYSTEMEND 313
#define SERVICESTART 314
#define SERVICEEND 315
#define JOBSTART 316
#define JOBEND 317
#define OPTIMIZATIONSTART 318
#define OPTIMIZATIONEND 319
#define ITEMSTART 320
#define ITEMEND 321
#define ITEMSTARTANDEND 322
#define ITEMEMPTY 323
#define ACTUALSTARTTIMESTART 324
#define ACTUALSTARTTIMEEND 325
#define ATLOWERSTART 326
#define ATLOWEREND 327
#define ATUPPERSTART 328
#define ATUPPEREND 329
#define AVAILABLECPUNUMBERSTART 330
#define AVAILABLECPUNUMBEREND 331
#define AVAILABLECPUSPEEDSTART 332
#define AVAILABLECPUSPEEDEND 333
#define AVAILABLEDISKSPACESTART 334
#define AVAILABLEDISKSPACEEND 335
#define AVAILABLEMEMORYSTART 336
#define AVAILABLEMEMORYEND 337
#define BASE64START 338
#define BASE64END 339
#define BASICSTART 340
#define BASICEND 341
#define BASISSTATUSSTART 342
#define BASISSTATUSEND 343
#define BASSTATUSSTART 344
#define BASSTATUSEND 345
#define CONSTART 346
#define CONEND 347
#define CONSTRAINTSSTART 348
#define CONSTRAINTSEND 349
#define CURRENTJOBCOUNTSTART 350
#define CURRENTJOBCOUNTEND 351
#define CURRENTSTATESTART 352
#define CURRENTSTATEEND 353
#define DUALVALUESSTART 354
#define DUALVALUESEND 355
#define ELSTART 356
#define ELEND 357
#define ENUMERATIONSTART 358
#define ENUMERATIONEND 359
#define ENDTIMESTART 360
#define ENDTIMEEND 361
#define GENERALSTATUSSTART 362
#define GENERALSTATUSEND 363
#define GENERALSUBSTATUSSTART 364
#define GENERALSUBSTATUSEND 365
#define IDXSTART 366
#define IDXEND 367
#define INSTANCENAMESTART 368
#define INSTANCENAMEEND 369
#define ISFREESTART 370
#define ISFREEEND 371
#define JOBIDSTART 372
#define JOBIDEND 373
#define MESSAGESTART 374
#define MESSAGEEND 375
#define OBJSTART 376
#define OBJEND 377
#define OBJECTIVESSTART 378
#define OBJECTIVESEND 379
#define OPTIMIZATIONSOLUTIONSTATUSSTART 380
#define OPTIMIZATIONSOLUTIONSTATUSEND 381
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 382
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 383
#define OTHERSTART 384
#define OTHEREND 385
#define OTHERRESULTSSTART 386
#define OTHERRESULTSEND 387
#define OTHERSOLUTIONRESULTSTART 388
#define OTHERSOLUTIONRESULTEND 389
#define OTHERSOLUTIONRESULTSSTART 390
#define OTHERSOLUTIONRESULTSEND 391
#define OTHERSOLVEROUTPUTSTART 392
#define OTHERSOLVEROUTPUTEND 393
#define SCHEDULEDSTARTTIMESTART 394
#define SCHEDULEDSTARTTIMEEND 395
#define SERVICENAMESTART 396
#define SERVICENAMEEND 397
#define SERVICEURISTART 398
#define SERVICEURIEND 399
#define SERVICEUTILIZATIONSTART 400
#define SERVICEUTILIZATIONEND 401
#define SOLUTIONSTART 402
#define SOLUTIONEND 403
#define SOLVERINVOKEDSTART 404
#define SOLVERINVOKEDEND 405
#define SOLVEROUTPUTSTART 406
#define SOLVEROUTPUTEND 407
#define STATUSSTART 408
#define STATUSEND 409
#define SUBMITTIMESTART 410
#define SUBMITTIMEEND 411
#define SUBSTATUSSTART 412
#define SUBSTATUSEND 413
#define SUPERBASICSTART 414
#define SUPERBASICEND 415
#define SYSTEMINFORMATIONSTART 416
#define SYSTEMINFORMATIONEND 417
#define TIMESTART 418
#define TIMEEND 419
#define TIMESERVICESTARTEDSTART 420
#define TIMESERVICESTARTEDEND 421
#define TIMESTAMPSTART 422
#define TIMESTAMPEND 423
#define TIMINGINFORMATIONSTART 424
#define TIMINGINFORMATIONEND 425
#define TOTALJOBSSOFARSTART 426
#define TOTALJOBSSOFAREND 427
#define UNKNOWNSTART 428
#define UNKNOWNEND 429
#define USEDCPUNUMBERSTART 430
#define USEDCPUNUMBEREND 431
#define USEDCPUSPEEDSTART 432
#define USEDCPUSPEEDEND 433
#define USEDDISKSPACESTART 434
#define USEDDISKSPACEEND 435
#define USEDMEMORYSTART 436
#define USEDMEMORYEND 437
#define VALUESSTART 438
#define VALUESEND 439
#define VALUESSTRINGSTART 440
#define VALUESSTRINGEND 441
#define VARSTART 442
#define VAREND 443
#define VARIABLESSTART 444
#define VARIABLESEND 445
#define VARIDXSTART 446
#define VARIDXEND 447
#define DUMMY 448




/* Copy the first part of user declarations.  */



 
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSConfig.h"
#include "OSErrorClass.h"
#include "OSResult.h"
#include "OSrLParserData.h"
#include "OSgLParserData.h"
#include "OSBase64.h"
#include "OSMathUtil.h"
#include "OSConfig.h"

#include <iostream>
#include <sstream> 
#include <stdio.h>

//#define DEBUG

#ifdef DEBUG
#define YYDEBUG 1
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osrl_scan_string (const char *yy_str , void* yyscanner  );
int osrllex_init(void** ptr_yy_globals);
int osrllex_destroy (void* yyscanner );
int osrlget_lineno( void* yyscanner);
char *osrlget_text (void* yyscanner );
void osrlset_lineno (int line_number , void* yyscanner );
void osrlset_extra (OSrLParserData* parserData , void* yyscanner );
void  yygetOSResult(const char *ch, OSResult* m_osresult, OSrLParserData *m_parserData, OSgLParserData *osglData ) throw(ErrorClass);
void osrl_empty_vectors( OSrLParserData* parserData);
void osgl_empty_vectors( OSgLParserData* osglData);





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



void osrlerror(YYLTYPE* type, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, const char* errormsg);
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
#define YYLAST   1326

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  198
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  738
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1070
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1486

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   448

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   195,
     197,     2,     2,   196,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   194,     2,     2,     2,     2,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    10,    12,    14,    16,    18,
      22,    28,    29,    32,    34,    36,    38,    41,    43,    47,
      49,    51,    54,    56,    58,    60,    62,    64,    66,    68,
      70,    72,    76,    78,    80,    82,    85,    87,    89,    91,
      93,    95,    98,   100,   104,   106,   108,   111,   115,   117,
     119,   120,   123,   125,   127,   130,   132,   135,   137,   139,
     141,   144,   146,   150,   152,   155,   157,   159,   161,   164,
     166,   170,   172,   175,   177,   179,   181,   184,   186,   190,
     192,   195,   197,   199,   201,   204,   206,   210,   212,   215,
     217,   219,   221,   224,   226,   230,   232,   235,   237,   239,
     241,   244,   246,   250,   252,   255,   257,   259,   261,   264,
     266,   270,   272,   276,   278,   280,   282,   284,   287,   289,
     293,   295,   297,   300,   304,   306,   308,   309,   312,   314,
     316,   318,   321,   323,   324,   327,   329,   331,   333,   336,
     338,   342,   344,   346,   349,   351,   353,   355,   357,   359,
     361,   364,   366,   368,   370,   373,   375,   379,   381,   385,
     387,   389,   390,   393,   395,   397,   401,   403,   407,   409,
     411,   412,   415,   417,   419,   423,   425,   429,   431,   433,
     434,   437,   439,   441,   445,   447,   451,   453,   454,   456,
     460,   462,   466,   468,   470,   472,   474,   477,   479,   483,
     485,   487,   490,   494,   496,   498,   499,   502,   504,   506,
     508,   511,   513,   514,   517,   519,   521,   523,   526,   528,
     532,   534,   536,   539,   541,   543,   545,   547,   549,   551,
     554,   556,   558,   560,   563,   565,   569,   571,   574,   576,
     578,   580,   583,   585,   589,   591,   594,   596,   598,   600,
     603,   605,   609,   611,   614,   616,   618,   620,   623,   625,
     629,   631,   634,   636,   638,   640,   643,   645,   649,   651,
     655,   657,   659,   661,   663,   666,   668,   672,   674,   676,
     679,   683,   685,   687,   688,   691,   693,   695,   697,   700,
     702,   703,   706,   708,   710,   712,   715,   717,   721,   723,
     725,   728,   730,   732,   734,   736,   738,   740,   742,   744,
     746,   748,   750,   753,   755,   757,   759,   762,   764,   768,
     770,   773,   775,   777,   779,   782,   784,   788,   790,   793,
     795,   797,   799,   802,   804,   808,   810,   813,   815,   817,
     819,   822,   824,   828,   830,   833,   835,   837,   839,   842,
     844,   848,   850,   854,   856,   858,   860,   862,   865,   867,
     871,   873,   875,   878,   882,   884,   885,   888,   890,   892,
     894,   896,   898,   900,   903,   905,   909,   911,   913,   915,
     919,   921,   923,   924,   927,   929,   931,   935,   937,   941,
     943,   945,   946,   949,   951,   953,   957,   959,   963,   965,
     967,   968,   971,   973,   975,   979,   981,   985,   987,   988,
     990,   994,   996,  1000,  1002,  1004,  1006,  1008,  1011,  1013,
    1017,  1019,  1021,  1024,  1028,  1030,  1032,  1033,  1036,  1038,
    1040,  1042,  1045,  1047,  1048,  1052,  1054,  1056,  1057,  1060,
    1062,  1064,  1066,  1068,  1070,  1072,  1075,  1077,  1081,  1084,
    1086,  1089,  1093,  1095,  1097,  1098,  1101,  1103,  1105,  1110,
    1114,  1123,  1127,  1129,  1131,  1133,  1136,  1138,  1140,  1142,
    1144,  1146,  1149,  1151,  1155,  1157,  1159,  1162,  1166,  1168,
    1170,  1171,  1174,  1176,  1178,  1181,  1183,  1184,  1187,  1189,
    1191,  1193,  1196,  1198,  1202,  1204,  1205,  1209,  1211,  1212,
    1214,  1216,  1218,  1220,  1224,  1229,  1230,  1234,  1236,  1238,
    1240,  1242,  1245,  1247,  1251,  1253,  1255,  1258,  1262,  1264,
    1269,  1273,  1274,  1278,  1280,  1282,  1284,  1286,  1289,  1291,
    1295,  1297,  1299,  1302,  1306,  1308,  1313,  1315,  1317,  1320,
    1322,  1326,  1328,  1329,  1332,  1334,  1336,  1338,  1340,  1344,
    1351,  1352,  1356,  1358,  1360,  1362,  1364,  1366,  1370,  1372,
    1373,  1377,  1379,  1381,  1383,  1385,  1387,  1391,  1393,  1394,
    1398,  1400,  1402,  1404,  1406,  1408,  1412,  1414,  1415,  1419,
    1421,  1423,  1425,  1427,  1429,  1433,  1435,  1436,  1440,  1442,
    1444,  1446,  1448,  1450,  1454,  1456,  1457,  1461,  1463,  1465,
    1467,  1469,  1471,  1475,  1477,  1478,  1481,  1485,  1487,  1489,
    1490,  1493,  1495,  1497,  1499,  1501,  1503,  1505,  1507,  1510,
    1512,  1516,  1518,  1520,  1522,  1525,  1529,  1531,  1536,  1538,
    1540,  1543,  1545,  1549,  1551,  1553,  1556,  1560,  1562,  1564,
    1565,  1568,  1570,  1572,  1574,  1576,  1578,  1580,  1584,  1586,
    1587,  1591,  1593,  1594,  1596,  1598,  1600,  1602,  1606,  1610,
    1611,  1615,  1617,  1619,  1621,  1623,  1626,  1628,  1632,  1634,
    1636,  1639,  1643,  1645,  1646,  1651,  1655,  1657,  1659,  1660,
    1663,  1665,  1667,  1669,  1671,  1675,  1682,  1683,  1687,  1689,
    1691,  1693,  1695,  1697,  1701,  1703,  1704,  1708,  1710,  1712,
    1714,  1716,  1718,  1722,  1724,  1725,  1729,  1731,  1733,  1735,
    1737,  1739,  1743,  1745,  1746,  1750,  1752,  1754,  1756,  1758,
    1760,  1764,  1766,  1767,  1771,  1773,  1775,  1777,  1779,  1781,
    1785,  1787,  1788,  1792,  1794,  1796,  1798,  1800,  1802,  1806,
    1808,  1809,  1812,  1816,  1818,  1820,  1821,  1824,  1826,  1828,
    1830,  1832,  1834,  1836,  1838,  1841,  1843,  1847,  1849,  1851,
    1853,  1856,  1860,  1862,  1867,  1869,  1871,  1874,  1876,  1880,
    1882,  1884,  1887,  1891,  1893,  1895,  1896,  1899,  1901,  1903,
    1905,  1907,  1909,  1911,  1915,  1917,  1918,  1922,  1924,  1925,
    1927,  1929,  1931,  1933,  1937,  1941,  1942,  1946,  1948,  1950,
    1952,  1954,  1957,  1959,  1963,  1965,  1967,  1970,  1974,  1976,
    1981,  1985,  1986,  1989,  1991,  1993,  1995,  1997,  2001,  2008,
    2009,  2013,  2015,  2017,  2019,  2021,  2023,  2027,  2029,  2030,
    2034,  2036,  2038,  2040,  2042,  2044,  2048,  2050,  2051,  2055,
    2057,  2059,  2061,  2063,  2065,  2069,  2071,  2072,  2076,  2078,
    2080,  2082,  2084,  2086,  2090,  2092,  2093,  2097,  2099,  2101,
    2103,  2105,  2107,  2111,  2113,  2114,  2118,  2120,  2122,  2124,
    2126,  2128,  2132,  2134,  2135,  2138,  2142,  2144,  2146,  2147,
    2150,  2152,  2154,  2156,  2158,  2160,  2162,  2164,  2167,  2169,
    2173,  2175,  2177,  2179,  2182,  2186,  2188,  2193,  2195,  2197,
    2200,  2202,  2206,  2208,  2210,  2213,  2217,  2219,  2221,  2222,
    2225,  2227,  2229,  2231,  2233,  2235,  2237,  2241,  2243,  2244,
    2248,  2250,  2252,  2254,  2256,  2259,  2261,  2265,  2267,  2269,
    2272,  2276,  2278,  2280,  2281,  2284,  2286,  2288,  2290,  2292,
    2294,  2296,  2299,  2301,  2305,  2307,  2309,  2312,  2314,  2316,
    2318,  2320,  2322,  2326,  2328,  2329,  2333,  2335,  2337,  2339,
    2341,  2344,  2346,  2350,  2352,  2354,  2357,  2361,  2363,  2365,
    2366,  2369,  2371,  2373,  2375,  2377,  2379,  2381,  2384,  2386,
    2390,  2392,  2394,  2397,  2399,  2401,  2403,  2405,  2407,  2411,
    2413,  2415,  2417,  2419,  2421,  2425,  2427,  2429,  2431,  2433,
    2437,  2439,  2441,  2443,  2445,  2449,  2451,  2453,  2455,  2457,
    2461,  2463,  2465,  2467,  2469,  2473,  2475,  2477,  2479,  2481,
    2485,  2490,  2495,  2500,  2505,  2510,  2515,  2520,  2525,  2530,
    2535,  2540,  2545,  2550,  2555,  2560,  2565,  2570,  2575,  2577,
    2579,  2580,  2583,  2587,  2589,  2591,  2592,  2595,  2597,  2599,
    2603,  2607,  2612,  2614,  2616,  2619,  2621,  2625,  2630,  2635,
    2637,  2639,  2641,  2643,  2645,  2648,  2649,  2652,  2654,  2656,
    2658
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     199,     0,    -1,   200,   201,   202,    -1,    12,    -1,    -1,
      14,    -1,   203,    -1,   204,    -1,    11,    -1,    10,   205,
      15,    -1,   206,   286,   340,   392,   487,    -1,    -1,   207,
     208,    -1,    55,    -1,   209,    -1,   210,    -1,    10,    56,
      -1,    11,    -1,    10,   211,    56,    -1,   212,    -1,   213,
      -1,   212,   213,    -1,   214,    -1,   230,    -1,   236,    -1,
     242,    -1,   248,    -1,   254,    -1,   260,    -1,   266,    -1,
     272,    -1,   215,   216,   219,    -1,   107,    -1,   217,    -1,
     218,    -1,   217,   218,    -1,   886,    -1,   878,    -1,   912,
      -1,   220,    -1,   221,    -1,    10,   108,    -1,    11,    -1,
      10,   222,   108,    -1,   223,    -1,   224,    -1,   223,   224,
      -1,   225,   226,   229,    -1,   157,    -1,   227,    -1,    -1,
     227,   228,    -1,   882,    -1,   878,    -1,    10,   158,    -1,
      11,    -1,   231,   232,    -1,   119,    -1,   233,    -1,   234,
      -1,    10,   120,    -1,    11,    -1,    10,   235,   120,    -1,
       4,    -1,   237,   238,    -1,   143,    -1,   239,    -1,   240,
      -1,    10,   144,    -1,    11,    -1,    10,   241,   144,    -1,
       4,    -1,   243,   244,    -1,   141,    -1,   245,    -1,   246,
      -1,    10,   142,    -1,    11,    -1,    10,   247,   142,    -1,
       4,    -1,   249,   250,    -1,   113,    -1,   251,    -1,   252,
      -1,    10,   114,    -1,    11,    -1,    10,   253,   114,    -1,
       4,    -1,   255,   256,    -1,   117,    -1,   257,    -1,   258,
      -1,    10,   118,    -1,    11,    -1,    10,   259,   118,    -1,
       4,    -1,   261,   262,    -1,   149,    -1,   263,    -1,   264,
      -1,    10,   150,    -1,    11,    -1,    10,   265,   150,    -1,
       4,    -1,   267,   268,    -1,   167,    -1,   269,    -1,   270,
      -1,    10,   168,    -1,    11,    -1,    10,   271,   168,    -1,
       4,    -1,   273,   274,   275,    -1,   131,    -1,   907,    -1,
     276,    -1,   277,    -1,    10,   132,    -1,    11,    -1,    10,
     278,   132,    -1,   279,    -1,   280,    -1,   279,   280,    -1,
     281,   282,   285,    -1,   129,    -1,   283,    -1,    -1,   283,
     284,    -1,   882,    -1,   894,    -1,   878,    -1,    10,   130,
      -1,    11,    -1,    -1,   287,   288,    -1,    57,    -1,   289,
      -1,   290,    -1,    10,    58,    -1,    11,    -1,    10,   291,
      58,    -1,   292,    -1,   293,    -1,   292,   293,    -1,   294,
      -1,   300,    -1,   307,    -1,   314,    -1,   321,    -1,   326,
      -1,   295,   296,    -1,   161,    -1,   297,    -1,   298,    -1,
      10,   162,    -1,    11,    -1,    10,   299,   162,    -1,     4,
      -1,   301,   302,   305,    -1,    79,    -1,   303,    -1,    -1,
     303,   304,    -1,   890,    -1,   878,    -1,    10,   306,    80,
      -1,   931,    -1,   308,   309,   312,    -1,    81,    -1,   310,
      -1,    -1,   310,   311,    -1,   890,    -1,   878,    -1,    10,
     313,    82,    -1,   931,    -1,   315,   316,   319,    -1,    77,
      -1,   317,    -1,    -1,   317,   318,    -1,   890,    -1,   878,
      -1,    10,   320,    78,    -1,   931,    -1,   322,   323,   324,
      -1,    75,    -1,    -1,   878,    -1,    10,   325,    76,    -1,
       6,    -1,   327,   328,   329,    -1,   131,    -1,   907,    -1,
     330,    -1,   331,    -1,    10,   132,    -1,    11,    -1,    10,
     332,   132,    -1,   333,    -1,   334,    -1,   333,   334,    -1,
     335,   336,   339,    -1,   129,    -1,   337,    -1,    -1,   337,
     338,    -1,   882,    -1,   894,    -1,   878,    -1,    10,   130,
      -1,    11,    -1,    -1,   341,   342,    -1,    59,    -1,   343,
      -1,   344,    -1,    10,    60,    -1,    11,    -1,    10,   345,
      60,    -1,   346,    -1,   347,    -1,   346,   347,    -1,   348,
      -1,   354,    -1,   360,    -1,   366,    -1,   372,    -1,   378,
      -1,   349,   350,    -1,    97,    -1,   351,    -1,   352,    -1,
      10,    98,    -1,    11,    -1,    10,   353,    98,    -1,     4,
      -1,   355,   356,    -1,    95,    -1,   357,    -1,   358,    -1,
      10,    96,    -1,    11,    -1,    10,   359,    96,    -1,     6,
      -1,   361,   362,    -1,   171,    -1,   363,    -1,   364,    -1,
      10,   172,    -1,    11,    -1,    10,   365,   172,    -1,     6,
      -1,   367,   368,    -1,   165,    -1,   369,    -1,   370,    -1,
      10,   166,    -1,    11,    -1,    10,   371,   166,    -1,     4,
      -1,   373,   374,    -1,   145,    -1,   375,    -1,   376,    -1,
      10,   146,    -1,    11,    -1,    10,   377,   146,    -1,   931,
      -1,   379,   380,   381,    -1,   131,    -1,   907,    -1,   382,
      -1,   383,    -1,    10,   132,    -1,    11,    -1,    10,   384,
     132,    -1,   385,    -1,   386,    -1,   385,   386,    -1,   387,
     388,   391,    -1,   129,    -1,   389,    -1,    -1,   389,   390,
      -1,   882,    -1,   894,    -1,   878,    -1,    10,   130,    -1,
      11,    -1,    -1,   393,   394,    -1,    61,    -1,   395,    -1,
     396,    -1,    10,    62,    -1,    11,    -1,    10,   397,    62,
      -1,   398,    -1,   399,    -1,   398,   399,    -1,   400,    -1,
     406,    -1,   412,    -1,   418,    -1,   424,    -1,   430,    -1,
     447,    -1,   454,    -1,   461,    -1,   468,    -1,   473,    -1,
     401,   402,    -1,   153,    -1,   403,    -1,   404,    -1,    10,
     154,    -1,    11,    -1,    10,   405,   154,    -1,     4,    -1,
     407,   408,    -1,   155,    -1,   409,    -1,   410,    -1,    10,
     156,    -1,    11,    -1,    10,   411,   156,    -1,     4,    -1,
     413,   414,    -1,   139,    -1,   415,    -1,   416,    -1,    10,
     140,    -1,    11,    -1,    10,   417,   140,    -1,     4,    -1,
     419,   420,    -1,    69,    -1,   421,    -1,   422,    -1,    10,
      70,    -1,    11,    -1,    10,   423,    70,    -1,     4,    -1,
     425,   426,    -1,   105,    -1,   427,    -1,   428,    -1,    10,
     106,    -1,    11,    -1,    10,   429,   106,    -1,     4,    -1,
     431,   432,   433,    -1,   169,    -1,   913,    -1,   434,    -1,
     435,    -1,    10,   170,    -1,    11,    -1,    10,   436,   170,
      -1,   437,    -1,   438,    -1,   437,   438,    -1,   439,   440,
     442,    -1,   163,    -1,    -1,   440,   441,    -1,   890,    -1,
     886,    -1,   874,    -1,   878,    -1,   443,    -1,   444,    -1,
      10,   164,    -1,    11,    -1,    10,   445,   164,    -1,   446,
      -1,     7,    -1,     6,    -1,   448,   449,   452,    -1,   179,
      -1,   450,    -1,    -1,   450,   451,    -1,   890,    -1,   878,
      -1,    10,   453,   180,    -1,   931,    -1,   455,   456,   459,
      -1,   181,    -1,   457,    -1,    -1,   457,   458,    -1,   890,
      -1,   878,    -1,    10,   460,   182,    -1,   931,    -1,   462,
     463,   466,    -1,   177,    -1,   464,    -1,    -1,   464,   465,
      -1,   890,    -1,   878,    -1,    10,   467,   178,    -1,   931,
      -1,   469,   470,   471,    -1,   175,    -1,    -1,   878,    -1,
      10,   472,   176,    -1,     6,    -1,   474,   475,   476,    -1,
     131,    -1,   907,    -1,   477,    -1,   478,    -1,    10,   132,
      -1,    11,    -1,    10,   479,   132,    -1,   480,    -1,   481,
      -1,   480,   481,    -1,   482,   483,   486,    -1,   129,    -1,
     484,    -1,    -1,   484,   485,    -1,   882,    -1,   894,    -1,
     878,    -1,    10,   130,    -1,    11,    -1,    -1,   488,   489,
     492,    -1,    63,    -1,   490,    -1,    -1,   490,   491,    -1,
     910,    -1,   915,    -1,   899,    -1,   904,    -1,   493,    -1,
     494,    -1,    10,    64,    -1,    11,    -1,    10,   495,    64,
      -1,   496,   851,    -1,   497,    -1,   496,   497,    -1,   498,
     499,   504,    -1,   147,    -1,   500,    -1,    -1,   500,   501,
      -1,   502,    -1,   503,    -1,    36,   933,     6,   933,    -1,
      53,     3,   933,    -1,    10,   505,   521,   527,   637,   733,
     828,   148,    -1,   506,   507,   510,    -1,   153,    -1,   508,
      -1,   509,    -1,   508,   509,    -1,   886,    -1,   878,    -1,
     912,    -1,   511,    -1,   512,    -1,    10,   154,    -1,    11,
      -1,    10,   513,   154,    -1,   514,    -1,   515,    -1,   514,
     515,    -1,   516,   517,   520,    -1,   157,    -1,   518,    -1,
      -1,   518,   519,    -1,   886,    -1,   878,    -1,    10,   158,
      -1,    11,    -1,    -1,   522,   523,    -1,   119,    -1,   524,
      -1,   525,    -1,    10,   120,    -1,    11,    -1,    10,   526,
     120,    -1,     4,    -1,    -1,   528,   529,   530,    -1,   189,
      -1,    -1,   909,    -1,   531,    -1,   532,    -1,    11,    -1,
      10,   533,   190,    -1,   534,   546,   561,   609,    -1,    -1,
     535,   536,   537,    -1,   183,    -1,   914,    -1,   538,    -1,
     539,    -1,    10,   184,    -1,    11,    -1,    10,   540,   184,
      -1,   541,    -1,   542,    -1,   541,   542,    -1,   543,   544,
     545,    -1,   187,    -1,    37,   933,     6,   933,    -1,    10,
     931,   188,    -1,    -1,   547,   548,   549,    -1,   185,    -1,
     914,    -1,   550,    -1,   551,    -1,    10,   186,    -1,    11,
      -1,    10,   552,   186,    -1,   553,    -1,   554,    -1,   553,
     554,    -1,   555,   556,   557,    -1,   187,    -1,    37,   933,
       6,   933,    -1,   558,    -1,   559,    -1,    10,   188,    -1,
      11,    -1,    10,   560,   188,    -1,     4,    -1,    -1,   562,
     563,    -1,    87,    -1,   564,    -1,   565,    -1,    11,    -1,
      10,   566,    88,    -1,   567,   574,   581,   588,   595,   602,
      -1,    -1,   568,   569,   570,    -1,    85,    -1,   900,    -1,
     571,    -1,   572,    -1,    11,    -1,    10,   573,    86,    -1,
     916,    -1,    -1,   575,   576,   577,    -1,    71,    -1,   900,
      -1,   578,    -1,   579,    -1,    11,    -1,    10,   580,    72,
      -1,   916,    -1,    -1,   582,   583,   584,    -1,    73,    -1,
     900,    -1,   585,    -1,   586,    -1,    11,    -1,    10,   587,
      74,    -1,   916,    -1,    -1,   589,   590,   591,    -1,   115,
      -1,   900,    -1,   592,    -1,   593,    -1,    11,    -1,    10,
     594,   116,    -1,   916,    -1,    -1,   596,   597,   598,    -1,
     159,    -1,   900,    -1,   599,    -1,   600,    -1,    11,    -1,
      10,   601,   160,    -1,   916,    -1,    -1,   603,   604,   605,
      -1,   173,    -1,   900,    -1,   606,    -1,   607,    -1,    11,
      -1,    10,   608,   174,    -1,   916,    -1,    -1,   609,   610,
      -1,   611,   612,   615,    -1,   129,    -1,   613,    -1,    -1,
     613,   614,    -1,   914,    -1,   901,    -1,   894,    -1,   882,
      -1,   878,    -1,   616,    -1,   617,    -1,    10,   130,    -1,
      11,    -1,    10,   618,   130,    -1,   619,    -1,   627,    -1,
     620,    -1,   619,   620,    -1,   621,   622,   623,    -1,   187,
      -1,    37,   933,     6,   933,    -1,   624,    -1,   625,    -1,
      10,   188,    -1,    11,    -1,    10,   626,   188,    -1,   932,
      -1,   628,    -1,   627,   628,    -1,   629,   630,   633,    -1,
     103,    -1,   631,    -1,    -1,   631,   632,    -1,   900,    -1,
     894,    -1,   878,    -1,   634,    -1,   635,    -1,    11,    -1,
      10,   636,   104,    -1,   916,    -1,    -1,   638,   639,   640,
      -1,   123,    -1,    -1,   906,    -1,   641,    -1,   642,    -1,
      11,    -1,    10,   643,   124,    -1,   644,   657,   705,    -1,
      -1,   645,   646,   647,    -1,   183,    -1,   903,    -1,   648,
      -1,   649,    -1,    10,   184,    -1,    11,    -1,    10,   650,
     184,    -1,   651,    -1,   652,    -1,   651,   652,    -1,   653,
     654,   655,    -1,   121,    -1,    -1,    37,   933,     6,   933,
      -1,    10,   656,   122,    -1,     6,    -1,     7,    -1,    -1,
     658,   659,    -1,    87,    -1,   660,    -1,   661,    -1,    11,
      -1,    10,   662,    88,    -1,   663,   670,   677,   684,   691,
     698,    -1,    -1,   664,   665,   666,    -1,    85,    -1,   900,
      -1,   667,    -1,   668,    -1,    11,    -1,    10,   669,    86,
      -1,   916,    -1,    -1,   671,   672,   673,    -1,    71,    -1,
     900,    -1,   674,    -1,   675,    -1,    11,    -1,    10,   676,
      72,    -1,   916,    -1,    -1,   678,   679,   680,    -1,    73,
      -1,   900,    -1,   681,    -1,   682,    -1,    11,    -1,    10,
     683,    74,    -1,   916,    -1,    -1,   685,   686,   687,    -1,
     115,    -1,   900,    -1,   688,    -1,   689,    -1,    11,    -1,
      10,   690,   116,    -1,   916,    -1,    -1,   692,   693,   694,
      -1,   159,    -1,   900,    -1,   695,    -1,   696,    -1,    11,
      -1,    10,   697,   160,    -1,   916,    -1,    -1,   699,   700,
     701,    -1,   173,    -1,   900,    -1,   702,    -1,   703,    -1,
      11,    -1,    10,   704,   174,    -1,   916,    -1,    -1,   705,
     706,    -1,   707,   708,   711,    -1,   129,    -1,   709,    -1,
      -1,   709,   710,    -1,   903,    -1,   901,    -1,   894,    -1,
     882,    -1,   878,    -1,   712,    -1,   713,    -1,    10,   130,
      -1,    11,    -1,    10,   714,   130,    -1,   715,    -1,   723,
      -1,   716,    -1,   715,   716,    -1,   717,   718,   719,    -1,
     121,    -1,    37,   933,     6,   933,    -1,   720,    -1,   721,
      -1,    10,   122,    -1,    11,    -1,    10,   722,   122,    -1,
     932,    -1,   724,    -1,   723,   724,    -1,   725,   726,   729,
      -1,   103,    -1,   727,    -1,    -1,   727,   728,    -1,   900,
      -1,   894,    -1,   878,    -1,   730,    -1,   731,    -1,    11,
      -1,    10,   732,   104,    -1,   916,    -1,    -1,   734,   735,
     736,    -1,    93,    -1,    -1,   905,    -1,   737,    -1,   738,
      -1,    11,    -1,    10,   739,    94,    -1,   740,   752,   800,
      -1,    -1,   741,   742,   743,    -1,    99,    -1,   898,    -1,
     744,    -1,   745,    -1,    10,   100,    -1,    11,    -1,    10,
     746,   100,    -1,   747,    -1,   748,    -1,   747,   748,    -1,
     749,   750,   751,    -1,    91,    -1,    37,   933,     6,   933,
      -1,    10,   931,    92,    -1,    -1,   753,   754,    -1,    87,
      -1,   755,    -1,   756,    -1,    11,    -1,    10,   757,    88,
      -1,   758,   765,   772,   779,   786,   793,    -1,    -1,   759,
     760,   761,    -1,    85,    -1,   900,    -1,   762,    -1,   763,
      -1,    11,    -1,    10,   764,    86,    -1,   916,    -1,    -1,
     766,   767,   768,    -1,    71,    -1,   900,    -1,   769,    -1,
     770,    -1,    11,    -1,    10,   771,    72,    -1,   916,    -1,
      -1,   773,   774,   775,    -1,    73,    -1,   900,    -1,   776,
      -1,   777,    -1,    11,    -1,    10,   778,    74,    -1,   916,
      -1,    -1,   780,   781,   782,    -1,   115,    -1,   900,    -1,
     783,    -1,   784,    -1,    11,    -1,    10,   785,   116,    -1,
     916,    -1,    -1,   787,   788,   789,    -1,   159,    -1,   900,
      -1,   790,    -1,   791,    -1,    11,    -1,    10,   792,   160,
      -1,   916,    -1,    -1,   794,   795,   796,    -1,   173,    -1,
     900,    -1,   797,    -1,   798,    -1,    11,    -1,    10,   799,
     174,    -1,   916,    -1,    -1,   800,   801,    -1,   802,   803,
     806,    -1,   129,    -1,   804,    -1,    -1,   804,   805,    -1,
     898,    -1,   901,    -1,   894,    -1,   882,    -1,   878,    -1,
     807,    -1,   808,    -1,    10,   130,    -1,    11,    -1,    10,
     809,   130,    -1,   810,    -1,   818,    -1,   811,    -1,   810,
     811,    -1,   812,   813,   814,    -1,    91,    -1,    37,   933,
       6,   933,    -1,   815,    -1,   816,    -1,    10,    92,    -1,
      11,    -1,    10,   817,    92,    -1,   932,    -1,   819,    -1,
     818,   819,    -1,   820,   821,   824,    -1,   103,    -1,   822,
      -1,    -1,   822,   823,    -1,   900,    -1,   894,    -1,   878,
      -1,   825,    -1,   826,    -1,    11,    -1,    10,   827,   104,
      -1,   916,    -1,    -1,   829,   830,   831,    -1,   135,    -1,
     908,    -1,   832,    -1,   833,    -1,    10,   136,    -1,    11,
      -1,    10,   834,   136,    -1,   835,    -1,   836,    -1,   835,
     836,    -1,   837,   838,   841,    -1,   133,    -1,   839,    -1,
      -1,   839,   840,    -1,   882,    -1,   874,    -1,   878,    -1,
     902,    -1,   842,    -1,   843,    -1,    10,   134,    -1,    11,
      -1,    10,   844,   134,    -1,   845,    -1,   846,    -1,   845,
     846,    -1,   847,    -1,   848,    -1,   849,    -1,    67,    -1,
      68,    -1,    65,   850,    66,    -1,     5,    -1,    -1,   852,
     853,   854,    -1,   137,    -1,   911,    -1,   855,    -1,   856,
      -1,    10,   138,    -1,    11,    -1,    10,   857,   138,    -1,
     858,    -1,   859,    -1,   858,   859,    -1,   860,   861,   864,
      -1,   151,    -1,   862,    -1,    -1,   862,   863,    -1,   882,
      -1,   874,    -1,   878,    -1,   902,    -1,   865,    -1,   866,
      -1,    10,   152,    -1,    11,    -1,    10,   867,   152,    -1,
     868,    -1,   869,    -1,   868,   869,    -1,   870,    -1,   871,
      -1,   872,    -1,    67,    -1,    68,    -1,    65,   873,    66,
      -1,     5,    -1,   875,    -1,   876,    -1,   877,    -1,    42,
      -1,    41,     3,   933,    -1,   879,    -1,   880,    -1,   881,
      -1,    44,    -1,    43,     3,   933,    -1,   883,    -1,   884,
      -1,   885,    -1,    46,    -1,    45,     3,   933,    -1,   887,
      -1,   888,    -1,   889,    -1,    48,    -1,    47,     3,   933,
      -1,   891,    -1,   892,    -1,   893,    -1,    50,    -1,    49,
       3,   933,    -1,   895,    -1,   896,    -1,   897,    -1,    52,
      -1,    51,     3,   933,    -1,    16,   933,     6,   933,    -1,
      17,   933,     6,   933,    -1,    18,   933,     6,   933,    -1,
      19,   933,     6,   933,    -1,    21,   933,     6,   933,    -1,
      22,   933,     6,   933,    -1,    23,   933,     6,   933,    -1,
      24,   933,     6,   933,    -1,    25,   933,     6,   933,    -1,
      26,   933,     6,   933,    -1,    27,   933,     6,   933,    -1,
      28,   933,     6,   933,    -1,    29,   933,     6,   933,    -1,
      30,   933,     6,   933,    -1,    31,   933,     6,   933,    -1,
      32,   933,     6,   933,    -1,    33,   933,     6,   933,    -1,
      34,   933,     6,   933,    -1,   917,    -1,   924,    -1,    -1,
     917,   918,    -1,   919,   920,   923,    -1,   101,    -1,   921,
      -1,    -1,   921,   922,    -1,   930,    -1,   929,    -1,    10,
       6,   102,    -1,    83,   925,   926,    -1,    40,   933,     6,
     933,    -1,   927,    -1,   928,    -1,    10,    84,    -1,    11,
      -1,    10,     4,    84,    -1,    38,   933,     6,   933,    -1,
      39,   933,     6,   933,    -1,     6,    -1,     7,    -1,     4,
      -1,     6,    -1,     7,    -1,   934,     8,    -1,    -1,   934,
     935,    -1,   194,    -1,   195,    -1,   196,    -1,   197,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   186,   186,   188,   195,   195,   197,   197,   199,   201,
     203,   206,   206,   208,   210,   210,   212,   212,   214,   216,
     218,   218,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   232,   234,   248,   254,   254,   257,   262,   266,   274,
     278,   283,   283,   285,   287,   289,   289,   291,   295,   304,
     309,   309,   312,   317,   323,   323,   326,   328,   334,   334,
     336,   336,   338,   340,   343,   345,   351,   351,   353,   353,
     355,   357,   360,   362,   368,   368,   370,   370,   372,   374,
     377,   379,   385,   385,   387,   387,   389,   391,   394,   396,
     402,   402,   404,   404,   406,   408,   411,   413,   419,   419,
     421,   421,   423,   425,   428,   430,   436,   436,   438,   438,
     440,   442,   445,   447,   453,   463,   467,   472,   472,   474,
     476,   478,   478,   480,   484,   495,   500,   500,   503,   509,
     514,   521,   521,   525,   525,   527,   529,   529,   531,   531,
     533,   535,   537,   537,   540,   541,   542,   543,   544,   545,
     548,   550,   556,   556,   558,   558,   560,   562,   568,   570,
     580,   582,   582,   585,   591,   596,   598,   603,   605,   615,
     617,   617,   620,   626,   631,   633,   639,   641,   651,   653,
     653,   656,   662,   667,   669,   675,   677,   685,   686,   691,
     693,   697,   699,   705,   715,   719,   724,   724,   726,   728,
     730,   730,   732,   736,   747,   752,   752,   755,   761,   766,
     773,   773,   777,   777,   779,   781,   781,   783,   783,   785,
     787,   789,   789,   792,   793,   794,   795,   796,   797,   800,
     802,   808,   808,   810,   810,   812,   814,   821,   823,   829,
     829,   831,   831,   833,   835,   838,   840,   846,   846,   848,
     848,   850,   852,   855,   857,   863,   863,   865,   865,   867,
     869,   872,   874,   880,   880,   882,   882,   884,   886,   891,
     893,   899,   909,   913,   918,   918,   920,   922,   924,   924,
     926,   930,   941,   946,   946,   949,   955,   960,   967,   967,
     970,   970,   972,   974,   974,   976,   976,   978,   980,   982,
     982,   985,   986,   987,   988,   989,   990,   991,   992,   993,
     994,   995,   998,  1000,  1006,  1006,  1008,  1008,  1010,  1012,
    1019,  1021,  1027,  1027,  1029,  1029,  1031,  1033,  1036,  1038,
    1044,  1044,  1046,  1046,  1048,  1050,  1053,  1055,  1061,  1061,
    1063,  1063,  1065,  1067,  1070,  1072,  1078,  1078,  1080,  1080,
    1082,  1084,  1087,  1089,  1095,  1104,  1108,  1113,  1113,  1115,
    1117,  1119,  1119,  1121,  1123,  1136,  1136,  1139,  1139,  1139,
    1139,  1142,  1142,  1144,  1144,  1146,  1148,  1161,  1162,  1165,
    1167,  1177,  1179,  1179,  1182,  1188,  1193,  1195,  1201,  1203,
    1213,  1215,  1215,  1218,  1224,  1229,  1231,  1237,  1239,  1249,
    1251,  1251,  1254,  1260,  1265,  1267,  1273,  1275,  1284,  1285,
    1290,  1292,  1297,  1299,  1305,  1315,  1319,  1324,  1324,  1326,
    1328,  1330,  1330,  1332,  1336,  1347,  1352,  1352,  1355,  1361,
    1366,  1373,  1373,  1376,  1376,  1378,  1385,  1390,  1390,  1393,
    1400,  1406,  1412,  1420,  1424,  1429,  1429,  1431,  1433,  1435,
    1435,  1437,  1439,  1447,  1449,  1449,  1451,  1451,  1453,  1462,
    1479,  1485,  1487,  1497,  1502,  1502,  1505,  1510,  1514,  1523,
    1527,  1533,  1533,  1535,  1537,  1539,  1539,  1541,  1544,  1553,
    1558,  1558,  1561,  1567,  1574,  1574,  1577,  1577,  1579,  1581,
    1581,  1583,  1583,  1585,  1587,  1594,  1594,  1596,  1599,  1599,
    1608,  1608,  1610,  1612,  1614,  1616,  1616,  1618,  1620,  1628,
    1632,  1637,  1637,  1639,  1641,  1643,  1643,  1645,  1652,  1658,
    1660,  1663,  1663,  1665,  1667,  1675,  1679,  1684,  1684,  1686,
    1688,  1690,  1690,  1692,  1700,  1706,  1709,  1710,  1712,  1712,
    1714,  1716,  1719,  1719,  1721,  1723,  1723,  1725,  1727,  1729,
    1731,  1731,  1740,  1742,  1749,  1749,  1751,  1753,  1755,  1758,
    1758,  1768,  1770,  1777,  1777,  1779,  1781,  1783,  1786,  1786,
    1795,  1797,  1804,  1804,  1806,  1808,  1810,  1813,  1813,  1822,
    1824,  1831,  1831,  1833,  1835,  1837,  1840,  1840,  1849,  1851,
    1858,  1858,  1860,  1862,  1864,  1867,  1867,  1876,  1878,  1885,
    1885,  1887,  1889,  1891,  1894,  1894,  1896,  1901,  1914,  1921,
    1921,  1924,  1934,  1944,  1950,  1956,  1963,  1963,  1965,  1965,
    1967,  1969,  1969,  1971,  1971,  1973,  1978,  1980,  1987,  1987,
    1989,  1989,  1991,  1993,  2002,  2002,  2004,  2015,  2024,  2031,
    2031,  2034,  2040,  2046,  2054,  2054,  2056,  2058,  2061,  2065,
    2065,  2067,  2073,  2073,  2082,  2082,  2084,  2086,  2088,  2090,
    2090,  2092,  2094,  2102,  2106,  2111,  2111,  2113,  2115,  2118,
    2118,  2120,  2127,  2134,  2134,  2136,  2139,  2140,  2143,  2143,
    2145,  2147,  2147,  2151,  2153,  2155,  2157,  2157,  2166,  2168,
    2175,  2175,  2177,  2179,  2181,  2183,  2183,  2192,  2194,  2201,
    2201,  2203,  2205,  2207,  2210,  2210,  2219,  2221,  2228,  2228,
    2230,  2232,  2234,  2237,  2237,  2246,  2248,  2255,  2255,  2257,
    2259,  2261,  2264,  2264,  2273,  2275,  2282,  2282,  2284,  2286,
    2288,  2291,  2291,  2300,  2302,  2309,  2309,  2311,  2313,  2315,
    2318,  2318,  2320,  2326,  2339,  2347,  2347,  2350,  2360,  2370,
    2376,  2382,  2391,  2391,  2393,  2393,  2395,  2397,  2397,  2399,
    2399,  2401,  2406,  2408,  2413,  2413,  2415,  2415,  2417,  2419,
    2425,  2425,  2427,  2438,  2447,  2454,  2454,  2457,  2463,  2469,
    2477,  2477,  2479,  2481,  2484,  2487,  2487,  2489,  2494,  2494,
    2502,  2502,  2504,  2506,  2508,  2510,  2510,  2512,  2515,  2523,
    2527,  2532,  2532,  2534,  2536,  2538,  2538,  2540,  2547,  2553,
    2555,  2558,  2558,  2560,  2562,  2562,  2564,  2566,  2568,  2570,
    2570,  2579,  2581,  2588,  2588,  2590,  2592,  2594,  2596,  2596,
    2605,  2607,  2614,  2614,  2616,  2618,  2620,  2623,  2623,  2632,
    2634,  2641,  2641,  2643,  2645,  2647,  2650,  2650,  2659,  2661,
    2668,  2668,  2670,  2672,  2674,  2677,  2677,  2686,  2688,  2695,
    2695,  2697,  2699,  2701,  2704,  2704,  2713,  2715,  2722,  2722,
    2724,  2726,  2728,  2731,  2731,  2733,  2739,  2752,  2759,  2759,
    2762,  2772,  2782,  2788,  2794,  2801,  2801,  2803,  2803,  2805,
    2807,  2807,  2809,  2809,  2811,  2816,  2818,  2824,  2824,  2826,
    2826,  2828,  2830,  2837,  2837,  2839,  2850,  2859,  2866,  2866,
    2869,  2875,  2881,  2889,  2889,  2891,  2893,  2896,  2898,  2898,
    2900,  2905,  2914,  2918,  2923,  2923,  2925,  2927,  2929,  2929,
    2931,  2935,  2946,  2953,  2953,  2956,  2962,  2968,  2976,  2986,
    2990,  2995,  2995,  2997,  2999,  3001,  3001,  3003,  3008,  3012,
    3014,  3014,  3016,  3018,  3029,  3029,  3031,  3036,  3045,  3049,
    3054,  3054,  3056,  3058,  3060,  3060,  3062,  3066,  3077,  3084,
    3084,  3087,  3092,  3098,  3104,  3113,  3117,  3122,  3122,  3124,
    3126,  3128,  3128,  3130,  3135,  3139,  3141,  3141,  3143,  3145,
    3155,  3161,  3161,  3163,  3166,  3169,  3175,  3175,  3177,  3180,
    3184,  3190,  3190,  3192,  3195,  3198,  3204,  3204,  3206,  3209,
    3212,  3218,  3218,  3220,  3223,  3226,  3232,  3232,  3234,  3237,
    3260,  3266,  3274,  3280,  3293,  3302,  3308,  3316,  3322,  3328,
    3334,  3340,  3346,  3354,  3360,  3368,  3373,  3379,  3405,  3410,
    3412,  3412,  3414,  3416,  3425,  3427,  3427,  3429,  3429,  3431,
    3439,  3441,  3446,  3446,  3448,  3448,  3450,  3471,  3479,  3493,
    3494,  3497,  3498,  3499,  3501,  3503,  3503,  3505,  3506,  3507,
    3508
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "GREATERTHAN",
  "ENDOFELEMENT", "OSRLSTART", "OSRLSTARTEMPTY", "OSRLATTRIBUTETEXT",
  "OSRLEND", "NUMBEROFCONATT", "NUMBEROFCONSTRAINTSATT", "NUMBEROFELATT",
  "NUMBEROFENUMERATIONSATT", "NUMBEROFIDXATT", "NUMBEROFITEMSATT",
  "NUMBEROFOBJATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFOTHERCONSTRAINTRESULTSATT", "NUMBEROFOTHEROBJECTIVERESULTSATT",
  "NUMBEROFOTHERRESULTSATT", "NUMBEROFOTHERSOLUTIONRESULTSATT",
  "NUMBEROFOTHERVARIABLERESULTSATT", "NUMBEROFSOLUTIONSATT",
  "NUMBEROFSOLVEROUTPUTSATT", "NUMBEROFSUBSTATUSESATT", "NUMBEROFTIMESATT",
  "NUMBEROFVARATT", "NUMBEROFVARIABLESATT", "NUMBEROFVARIDXATT",
  "TARGETOBJECTIVEIDXATT", "IDXATT", "INCRATT", "MULTATT", "SIZEOFATT",
  "CATEGORYATT", "EMPTYCATEGORYATT", "DESCRIPTIONATT",
  "EMPTYDESCRIPTIONATT", "NAMEATT", "EMPTYNAMEATT", "TYPEATT",
  "EMPTYTYPEATT", "UNITATT", "EMPTYUNITATT", "VALUEATT", "EMPTYVALUEATT",
  "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT", "GENERALSTART",
  "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND",
  "JOBSTART", "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
  "ITEMSTART", "ITEMEND", "ITEMSTARTANDEND", "ITEMEMPTY",
  "ACTUALSTARTTIMESTART", "ACTUALSTARTTIMEEND", "ATLOWERSTART",
  "ATLOWEREND", "ATUPPERSTART", "ATUPPEREND", "AVAILABLECPUNUMBERSTART",
  "AVAILABLECPUNUMBEREND", "AVAILABLECPUSPEEDSTART",
  "AVAILABLECPUSPEEDEND", "AVAILABLEDISKSPACESTART",
  "AVAILABLEDISKSPACEEND", "AVAILABLEMEMORYSTART", "AVAILABLEMEMORYEND",
  "BASE64START", "BASE64END", "BASICSTART", "BASICEND", "BASISSTATUSSTART",
  "BASISSTATUSEND", "BASSTATUSSTART", "BASSTATUSEND", "CONSTART", "CONEND",
  "CONSTRAINTSSTART", "CONSTRAINTSEND", "CURRENTJOBCOUNTSTART",
  "CURRENTJOBCOUNTEND", "CURRENTSTATESTART", "CURRENTSTATEEND",
  "DUALVALUESSTART", "DUALVALUESEND", "ELSTART", "ELEND",
  "ENUMERATIONSTART", "ENUMERATIONEND", "ENDTIMESTART", "ENDTIMEEND",
  "GENERALSTATUSSTART", "GENERALSTATUSEND", "GENERALSUBSTATUSSTART",
  "GENERALSUBSTATUSEND", "IDXSTART", "IDXEND", "INSTANCENAMESTART",
  "INSTANCENAMEEND", "ISFREESTART", "ISFREEEND", "JOBIDSTART", "JOBIDEND",
  "MESSAGESTART", "MESSAGEEND", "OBJSTART", "OBJEND", "OBJECTIVESSTART",
  "OBJECTIVESEND", "OPTIMIZATIONSOLUTIONSTATUSSTART",
  "OPTIMIZATIONSOLUTIONSTATUSEND", "OPTIMIZATIONSOLUTIONSUBSTATUSSTART",
  "OPTIMIZATIONSOLUTIONSUBSTATUSEND", "OTHERSTART", "OTHEREND",
  "OTHERRESULTSSTART", "OTHERRESULTSEND", "OTHERSOLUTIONRESULTSTART",
  "OTHERSOLUTIONRESULTEND", "OTHERSOLUTIONRESULTSSTART",
  "OTHERSOLUTIONRESULTSEND", "OTHERSOLVEROUTPUTSTART",
  "OTHERSOLVEROUTPUTEND", "SCHEDULEDSTARTTIMESTART",
  "SCHEDULEDSTARTTIMEEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "SERVICEURISTART", "SERVICEURIEND", "SERVICEUTILIZATIONSTART",
  "SERVICEUTILIZATIONEND", "SOLUTIONSTART", "SOLUTIONEND",
  "SOLVERINVOKEDSTART", "SOLVERINVOKEDEND", "SOLVEROUTPUTSTART",
  "SOLVEROUTPUTEND", "STATUSSTART", "STATUSEND", "SUBMITTIMESTART",
  "SUBMITTIMEEND", "SUBSTATUSSTART", "SUBSTATUSEND", "SUPERBASICSTART",
  "SUPERBASICEND", "SYSTEMINFORMATIONSTART", "SYSTEMINFORMATIONEND",
  "TIMESTART", "TIMEEND", "TIMESERVICESTARTEDSTART",
  "TIMESERVICESTARTEDEND", "TIMESTAMPSTART", "TIMESTAMPEND",
  "TIMINGINFORMATIONSTART", "TIMINGINFORMATIONEND", "TOTALJOBSSOFARSTART",
  "TOTALJOBSSOFAREND", "UNKNOWNSTART", "UNKNOWNEND", "USEDCPUNUMBERSTART",
  "USEDCPUNUMBEREND", "USEDCPUSPEEDSTART", "USEDCPUSPEEDEND",
  "USEDDISKSPACESTART", "USEDDISKSPACEEND", "USEDMEMORYSTART",
  "USEDMEMORYEND", "VALUESSTART", "VALUESEND", "VALUESSTRINGSTART",
  "VALUESSTRINGEND", "VARSTART", "VAREND", "VARIABLESSTART",
  "VARIABLESEND", "VARIDXSTART", "VARIDXEND", "DUMMY", "' '", "'\\t'",
  "'\\r'", "'\\n'", "$accept", "osrldoc", "osrlStart", "osrlAttributes",
  "osrlContent", "osrlEmpty", "osrlLaden", "osrlBody", "generalElement",
  "generalElementStart", "generalElementContent", "generalElementEmpty",
  "generalElementLaden", "generalElementBody", "generalElementList",
  "generalChild", "generalStatus", "generalStatusStart",
  "generalStatusAttributes", "generalStatusAttList", "generalStatusATT",
  "generalStatusContent", "generalStatusEmpty", "generalStatusLaden",
  "generalStatusBody", "generalSubstatusArray", "generalSubstatus",
  "generalSubstatusStart", "generalSubstatusAttributes",
  "generalSubstatusAttList", "generalSubstatusATT", "generalSubstatusEnd",
  "generalMessage", "generalMessageStart", "generalMessageContent",
  "generalMessageEmpty", "generalMessageLaden", "generalMessageBody",
  "serviceURI", "serviceURIStart", "serviceURIContent", "serviceURIEmpty",
  "serviceURILaden", "serviceURIBody", "serviceName", "serviceNameStart",
  "serviceNameContent", "serviceNameEmpty", "serviceNameLaden",
  "serviceNameBody", "instanceName", "instanceNameStart",
  "instanceNameContent", "instanceNameEmpty", "instanceNameLaden",
  "instanceNameBody", "jobID", "jobIDStart", "jobIDContent", "jobIDEmpty",
  "jobIDLaden", "jobIDBody", "solverInvoked", "solverInvokedStart",
  "solverInvokedContent", "solverInvokedEmpty", "solverInvokedLaden",
  "solverInvokedBody", "timeStamp", "timeStampStart", "timeStampContent",
  "timeStampEmpty", "timeStampLaden", "timeStampBody",
  "generalOtherResults", "generalOtherResultsStart",
  "generalOtherResultsAttributes", "generalOtherResultsContent",
  "generalOtherResultsEmpty", "generalOtherResultsLaden",
  "generalOtherResultsBody", "generalOtherResultArray",
  "generalOtherResult", "generalOtherResultStart",
  "generalOtherAttributes", "generalOtherAttList", "generalOtherAtt",
  "generalOtherEnd", "systemElement", "systemElementStart",
  "systemElementContent", "systemElementEmpty", "systemElementLaden",
  "systemElementBody", "systemElementList", "systemChild",
  "systemInformation", "systemInformationStart",
  "systemInformationContent", "systemInformationEmpty",
  "systemInformationLaden", "systemInformationBody", "availableDiskSpace",
  "availableDiskSpaceStart", "availableDiskSpaceAttributes",
  "availableDiskSpaceAttList", "availableDiskSpaceAtt",
  "availableDiskSpaceContent", "availableDiskSpaceValue",
  "availableMemory", "availableMemoryStart", "availableMemoryAttributes",
  "availableMemoryAttList", "availableMemoryAtt", "availableMemoryContent",
  "availableMemoryValue", "availableCPUSpeed", "availableCPUSpeedStart",
  "availableCPUSpeedAttributes", "availableCPUSpeedAttList",
  "availableCPUSpeedAtt", "availableCPUSpeedContent",
  "availableCPUSpeedValue", "availableCPUNumber",
  "availableCPUNumberStart", "availableCPUNumberAttributes",
  "availableCPUNumberContent", "availableCPUNumberValue",
  "systemOtherResults", "systemOtherResultsStart",
  "systemOtherResultsAttributes", "systemOtherResultsContent",
  "systemOtherResultsEmpty", "systemOtherResultsLaden",
  "systemOtherResultsBody", "systemOtherResultArray", "systemOtherResult",
  "systemOtherResultStart", "systemOtherAttributes", "systemOtherAttList",
  "systemOtherAtt", "systemOtherEnd", "serviceElement",
  "serviceElementStart", "serviceElementContent", "serviceElementEmpty",
  "serviceElementLaden", "serviceElementBody", "serviceElementList",
  "serviceChild", "currentState", "currentStateStart",
  "currentStateContent", "currentStateEmpty", "currentStateLaden",
  "currentStateBody", "currentJobCount", "currentJobCountStart",
  "currentJobCountContent", "currentJobCountEmpty", "currentJobCountLaden",
  "currentJobCountBody", "totalJobsSoFar", "totalJobsSoFarStart",
  "totalJobsSoFarContent", "totalJobsSoFarEmpty", "totalJobsSoFarLaden",
  "totalJobsSoFarBody", "timeServiceStarted", "timeServiceStartedStart",
  "timeServiceStartedContent", "timeServiceStartedEmpty",
  "timeServiceStartedLaden", "timeServiceStartedBody",
  "serviceUtilization", "serviceUtilizationStart",
  "serviceUtilizationContent", "serviceUtilizationEmpty",
  "serviceUtilizationLaden", "serviceUtilizationBody",
  "serviceOtherResults", "serviceOtherResultsStart",
  "serviceOtherResultsAttributes", "serviceOtherResultsContent",
  "serviceOtherResultsEmpty", "serviceOtherResultsLaden",
  "serviceOtherResultsBody", "serviceOtherResultArray",
  "serviceOtherResult", "serviceOtherResultStart",
  "serviceOtherAttributes", "serviceOtherAttList", "serviceOtherAtt",
  "serviceOtherEnd", "jobElement", "jobElementStart", "jobElementContent",
  "jobElementEmpty", "jobElementLaden", "jobElementBody", "jobElementList",
  "jobChild", "jobStatus", "jobStatusStart", "jobStatusContent",
  "jobStatusEmpty", "jobStatusLaden", "jobStatusBody", "submitTime",
  "submitTimeStart", "submitTimeContent", "submitTimeEmpty",
  "submitTimeLaden", "submitTimeBody", "scheduledStartTime",
  "scheduledStartTimeStart", "scheduledStartTimeContent",
  "scheduledStartTimeEmpty", "scheduledStartTimeLaden",
  "scheduledStartTimeBody", "actualStartTime", "actualStartTimeStart",
  "actualStartTimeContent", "actualStartTimeEmpty", "actualStartTimeLaden",
  "actualStartTimeBody", "endTime", "endTimeStart", "endTimeContent",
  "endTimeEmpty", "endTimeLaden", "endTimeBody", "timingInformation",
  "timingInformationStart", "timingInformationAttributes",
  "timingInformationContent", "timingInformationEmpty",
  "timingInformationLaden", "timingInformationBody", "timeArray", "time",
  "timeStart", "timeAttributes", "timeAtt", "timeContent", "timeEmpty",
  "timeLaden", "timeBody", "timeValue", "usedDiskSpace",
  "usedDiskSpaceStart", "usedDiskSpaceAttributes", "usedDiskSpaceAttList",
  "usedDiskSpaceAtt", "usedDiskSpaceContent", "usedDiskSpaceValue",
  "usedMemory", "usedMemoryStart", "usedMemoryAttributes",
  "usedMemoryAttList", "usedMemoryAtt", "usedMemoryContent",
  "usedMemoryValue", "usedCPUSpeed", "usedCPUSpeedStart",
  "usedCPUSpeedAttributes", "usedCPUSpeedAttList", "usedCPUSpeedAtt",
  "usedCPUSpeedContent", "usedCPUSpeedValue", "usedCPUNumber",
  "usedCPUNumberStart", "usedCPUNumberAttributes", "usedCPUNumberContent",
  "usedCPUNumberValue", "jobOtherResults", "jobOtherResultsStart",
  "jobOtherResultsAttributes", "jobOtherResultsContent",
  "jobOtherResultsEmpty", "jobOtherResultsLaden", "jobOtherResultsBody",
  "jobOtherResultArray", "jobOtherResult", "jobOtherResultStart",
  "jobOtherAttributes", "jobOtherAttList", "jobOtherAtt", "jobOtherEnd",
  "optimizationElement", "optimizationStart", "optimizationAttributes",
  "optimizationAttList", "optimizationATT", "optimizationContent",
  "optimizationEmpty", "optimizationLaden", "optimizationBody",
  "solutionArray", "solution", "solutionStart", "solutionAttributes",
  "solutionAttList", "solutionATT", "targetObjectiveIdxATT",
  "weightedObjectivesATT", "solutionContent", "solutionStatus",
  "solutionStatusStart", "solutionStatusAttributes",
  "solutionStatusAttList", "solutionStatusATT", "solutionStatusContent",
  "solutionStatusEmpty", "solutionStatusLaden", "solutionStatusBody",
  "solutionSubstatusArray", "solutionSubstatus", "solutionSubstatusStart",
  "solutionSubstatusAttributes", "solutionSubstatusAttList",
  "solutionSubstatusATT", "solutionSubstatusEnd", "solutionMessage",
  "solutionMessageStart", "solutionMessageContent", "solutionMessageEmpty",
  "solutionMessageLaden", "solutionMessageBody", "variables",
  "variablesStart", "numberOfOtherVariableResults", "variablesContent",
  "variablesEmpty", "variablesLaden", "variablesBody", "variableValues",
  "variableValuesStart", "numberOfVarATT", "variableValuesContent",
  "variableValuesEmpty", "variableValuesLaden", "variableValuesBody",
  "varValueArray", "varValue", "varValueStart", "varIdxATT",
  "varValueContent", "variableValuesString", "variableValuesStringStart",
  "numberOfVarStringATT", "variableValuesStringContent",
  "variableValuesStringEmpty", "variableValuesStringLaden",
  "variableValuesStringBody", "varValueStringArray", "varValueString",
  "varValueStringStart", "varStrIdxATT", "varValueStringContent",
  "varValueStringEmpty", "varValueStringLaden", "varValueStringBody",
  "variableBasisStatus", "variableBasisStatusStart",
  "variableBasisStatusContent", "variableBasisStatusEmpty",
  "variableBasisStatusLaden", "variableBasisStatusBody", "variablesBasic",
  "variablesBasicStart", "variablesBasicNumberOfElATT",
  "variablesBasicContent", "variablesBasicEmpty", "variablesBasicLaden",
  "variablesBasicBody", "variablesAtLower", "variablesAtLowerStart",
  "variablesAtLowerNumberOfElATT", "variablesAtLowerContent",
  "variablesAtLowerEmpty", "variablesAtLowerLaden", "variablesAtLowerBody",
  "variablesAtUpper", "variablesAtUpperStart",
  "variablesAtUpperNumberOfElATT", "variablesAtUpperContent",
  "variablesAtUpperEmpty", "variablesAtUpperLaden", "variablesAtUpperBody",
  "variablesIsFree", "variablesIsFreeStart",
  "variablesIsFreeNumberOfElATT", "variablesIsFreeContent",
  "variablesIsFreeEmpty", "variablesIsFreeLaden", "variablesIsFreeBody",
  "variablesSuperbasic", "variablesSuperbasicStart",
  "variablesSuperbasicNumberOfElATT", "variablesSuperbasicContent",
  "variablesSuperbasicEmpty", "variablesSuperbasicLaden",
  "variablesSuperbasicBody", "variablesUnknown", "variablesUnknownStart",
  "variablesUnknownNumberOfElATT", "variablesUnknownContent",
  "variablesUnknownEmpty", "variablesUnknownLaden", "variablesUnknownBody",
  "otherVariableResultsArray", "otherVariableResult",
  "otherVariableResultStart", "otherVariableResultAttributes",
  "otherVariableResultAttList", "otherVariableResultATT",
  "otherVariableResultContent", "otherVariableResultEmpty",
  "otherVariableResultLaden", "otherVariableResultBody", "otherVarList",
  "otherVar", "otherVarStart", "otherVarIdxATT", "otherVarContent",
  "otherVarEmpty", "otherVarLaden", "otherVarBody",
  "otherVarEnumerationList", "otherVarEnumeration",
  "otherVarEnumerationStart", "otherVarEnumerationAttributes",
  "otherVarEnumerationAttList", "otherVarEnumerationATT",
  "otherVarEnumerationContent", "otherVarEnumerationEmpty",
  "otherVarEnumerationLaden", "otherVarEnumerationBody", "objectives",
  "objectivesStart", "numberOfOtherObjectiveResults", "objectivesContent",
  "objectivesEmpty", "objectivesLaden", "objectivesBody",
  "objectiveValues", "objectiveValuesStart", "numberOfObjATT",
  "objectiveValuesContent", "objectiveValuesEmpty", "objectiveValuesLaden",
  "objectiveValuesBody", "objValueArray", "objValue", "objValueStart",
  "objIdxATT", "objValueContent", "objVal", "objectiveBasisStatus",
  "objectiveBasisStatusStart", "objectiveBasisStatusContent",
  "objectiveBasisStatusEmpty", "objectiveBasisStatusLaden",
  "objectiveBasisStatusBody", "objectivesBasic", "objectivesBasicStart",
  "objectivesBasicNumberOfElATT", "objectivesBasicContent",
  "objectivesBasicEmpty", "objectivesBasicLaden", "objectivesBasicBody",
  "objectivesAtLower", "objectivesAtLowerStart",
  "objectivesAtLowerNumberOfElATT", "objectivesAtLowerContent",
  "objectivesAtLowerEmpty", "objectivesAtLowerLaden",
  "objectivesAtLowerBody", "objectivesAtUpper", "objectivesAtUpperStart",
  "objectivesAtUpperNumberOfElATT", "objectivesAtUpperContent",
  "objectivesAtUpperEmpty", "objectivesAtUpperLaden",
  "objectivesAtUpperBody", "objectivesIsFree", "objectivesIsFreeStart",
  "objectivesIsFreeNumberOfElATT", "objectivesIsFreeContent",
  "objectivesIsFreeEmpty", "objectivesIsFreeLaden", "objectivesIsFreeBody",
  "objectivesSuperbasic", "objectivesSuperbasicStart",
  "objectivesSuperbasicNumberOfElATT", "objectivesSuperbasicContent",
  "objectivesSuperbasicEmpty", "objectivesSuperbasicLaden",
  "objectivesSuperbasicBody", "objectivesUnknown",
  "objectivesUnknownStart", "objectivesUnknownNumberOfElATT",
  "objectivesUnknownContent", "objectivesUnknownEmpty",
  "objectivesUnknownLaden", "objectivesUnknownBody",
  "otherObjectiveResultsArray", "otherObjectiveResult",
  "otherObjectiveResultStart", "otherObjectiveResultAttributes",
  "otherObjectiveResultAttList", "otherObjectiveResultATT",
  "otherObjectiveResultContent", "otherObjectiveResultEmpty",
  "otherObjectiveResultLaden", "otherObjectiveResultBody", "otherObjList",
  "otherObj", "otherObjStart", "otherObjIdxATT", "otherObjContent",
  "otherObjEmpty", "otherObjLaden", "otherObjBody",
  "otherObjEnumerationList", "otherObjEnumeration",
  "otherObjEnumerationStart", "otherObjEnumerationAttributes",
  "otherObjEnumerationAttList", "otherObjEnumerationATT",
  "otherObjEnumerationContent", "otherObjEnumerationEmpty",
  "otherObjEnumerationLaden", "otherObjEnumerationBody", "constraints",
  "constraintsStart", "numberOfOtherConstraintResults",
  "constraintsContent", "constraintsEmpty", "constraintsLaden",
  "constraintsBody", "dualValues", "dualValuesStart", "numberOfConATT",
  "dualValuesContent", "dualValuesEmpty", "dualValuesLaden",
  "dualValuesBody", "dualValueArray", "dualValue", "dualValueStart",
  "conIdxATT", "dualValueContent", "slackBasisStatus",
  "slackBasisStatusStart", "slackBasisStatusContent",
  "slackBasisStatusEmpty", "slackBasisStatusLaden", "slackBasisStatusBody",
  "slacksBasic", "slacksBasicStart", "slacksBasicNumberOfElATT",
  "slacksBasicContent", "slacksBasicEmpty", "slacksBasicLaden",
  "slacksBasicBody", "slacksAtLower", "slacksAtLowerStart",
  "slacksAtLowerNumberOfElATT", "slacksAtLowerContent",
  "slacksAtLowerEmpty", "slacksAtLowerLaden", "slacksAtLowerBody",
  "slacksAtUpper", "slacksAtUpperStart", "slacksAtUpperNumberOfElATT",
  "slacksAtUpperContent", "slacksAtUpperEmpty", "slacksAtUpperLaden",
  "slacksAtUpperBody", "slacksIsFree", "slacksIsFreeStart",
  "slacksIsFreeNumberOfElATT", "slacksIsFreeContent", "slacksIsFreeEmpty",
  "slacksIsFreeLaden", "slacksIsFreeBody", "slacksSuperbasic",
  "slacksSuperbasicStart", "slacksSuperbasicNumberOfElATT",
  "slacksSuperbasicContent", "slacksSuperbasicEmpty",
  "slacksSuperbasicLaden", "slacksSuperbasicBody", "slacksUnknown",
  "slacksUnknownStart", "slacksUnknownNumberOfElATT",
  "slacksUnknownContent", "slacksUnknownEmpty", "slacksUnknownLaden",
  "slacksUnknownBody", "otherConstraintResultsArray",
  "otherConstraintResult", "otherConstraintResultStart",
  "otherConstraintResultAttributes", "otherConstraintResultAttList",
  "otherConstraintResultATT", "otherConstraintResultContent",
  "otherConstraintResultEmpty", "otherConstraintResultLaden",
  "otherConstraintResultBody", "otherConList", "otherCon", "otherConStart",
  "otherConIdxATT", "otherConContent", "otherConEmpty", "otherConLaden",
  "otherConBody", "otherConEnumerationList", "otherConEnumeration",
  "otherConEnumerationStart", "otherConEnumerationAttributes",
  "otherConEnumerationAttList", "otherConEnumerationATT",
  "otherConEnumerationContent", "otherConEnumerationEmpty",
  "otherConEnumerationLaden", "otherConEnumerationBody",
  "otherSolutionResults", "otherSolutionResultsStart",
  "numberOfOtherSolutionResults", "otherSolutionResultsContent",
  "otherSolutionResultsEmpty", "otherSolutionResultsLaden",
  "otherSolutionResultsBody", "otherSolutionResultArray",
  "otherSolutionResult", "otherSolutionResultStart",
  "otherSolutionResultAttributes", "otherSolutionResultAttList",
  "otherSolutionResultAtt", "otherSolutionResultContent",
  "otherSolutionResultEmpty", "otherSolutionResultLaden",
  "otherSolutionResultBody", "otherSolutionResultItemArray",
  "otherSolutionResultItem", "otherSolutionResultItemContent",
  "otherSolutionResultItemEmpty", "otherSolutionResultItemLaden",
  "otherSolutionResultItemBody", "otherSolverOutput",
  "otherSolverOutputStart", "numberOfSolverOutputsATT",
  "otherSolverOutputContent", "otherSolverOutputEmpty",
  "otherSolverOutputLaden", "otherSolverOutputBody", "solverOutputArray",
  "solverOutput", "solverOutputStart", "solverOutputAttributes",
  "solverOutputAttList", "solverOutputAtt", "solverOutputContent",
  "solverOutputEmpty", "solverOutputLaden", "solverOutputBody",
  "solverOutputItemArray", "solverOutputItem", "solverOutputItemContent",
  "solverOutputItemEmpty", "solverOutputItemLaden", "solverOutputItemBody",
  "categoryAttribute", "categoryAtt", "categoryAttEmpty",
  "categoryAttContent", "descriptionAttribute", "descriptionAtt",
  "descriptionAttEmpty", "descriptionAttContent", "nameAttribute",
  "nameAtt", "nameAttEmpty", "nameAttContent", "typeAttribute", "typeAtt",
  "typeAttEmpty", "typeAttContent", "unitAttribute", "unitAtt",
  "unitAttEmpty", "unitAttContent", "valueAttribute", "valueAtt",
  "valueAttEmpty", "valueAttContent", "numberOfConAttribute",
  "numberOfConstraintsAttribute", "numberOfElAttribute",
  "numberOfEnumerationsAttribute", "numberOfItemsAttribute",
  "numberOfObjAttribute", "numberOfObjectivesAttribute",
  "numberOfOtherConstraintResultsAttribute",
  "numberOfOtherObjectiveResultsAttribute",
  "numberOfOtherResultsAttribute", "numberOfOtherSolutionResultsAttribute",
  "numberOfOtherVariableResultsAttribute", "numberOfSolutionsAttribute",
  "numberOfSolverOutputsAttribute", "numberOfSubstatusesAttribute",
  "numberOfTimesAttribute", "numberOfVarAttribute",
  "numberOfVariablesAttribute", "osglIntArrayData", "osglIntVectorElArray",
  "osglIntVectorEl", "osglIntVectorElStart", "osglIntVectorElAttributes",
  "osglIntVectorElAttList", "osglIntVectorElAtt", "osglIntVectorElContent",
  "osglIntVectorBase64", "Base64SizeAttribute", "Base64Content",
  "Base64Empty", "Base64Laden", "osglIncrAttribute", "osglMultAttribute",
  "aNumber", "ElementValue", "quote", "xmlWhiteSpace", "xmlWhiteSpaceChar", 0
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   198,   199,   200,   201,   201,   202,   202,   203,   204,
     205,   206,   206,   207,   208,   208,   209,   209,   210,   211,
     212,   212,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   214,   215,   216,   217,   217,   218,   218,   218,   219,
     219,   220,   220,   221,   222,   223,   223,   224,   225,   226,
     227,   227,   228,   228,   229,   229,   230,   231,   232,   232,
     233,   233,   234,   235,   236,   237,   238,   238,   239,   239,
     240,   241,   242,   243,   244,   244,   245,   245,   246,   247,
     248,   249,   250,   250,   251,   251,   252,   253,   254,   255,
     256,   256,   257,   257,   258,   259,   260,   261,   262,   262,
     263,   263,   264,   265,   266,   267,   268,   268,   269,   269,
     270,   271,   272,   273,   274,   275,   275,   276,   276,   277,
     278,   279,   279,   280,   281,   282,   283,   283,   284,   284,
     284,   285,   285,   286,   286,   287,   288,   288,   289,   289,
     290,   291,   292,   292,   293,   293,   293,   293,   293,   293,
     294,   295,   296,   296,   297,   297,   298,   299,   300,   301,
     302,   303,   303,   304,   304,   305,   306,   307,   308,   309,
     310,   310,   311,   311,   312,   313,   314,   315,   316,   317,
     317,   318,   318,   319,   320,   321,   322,   323,   323,   324,
     325,   326,   327,   328,   329,   329,   330,   330,   331,   332,
     333,   333,   334,   335,   336,   337,   337,   338,   338,   338,
     339,   339,   340,   340,   341,   342,   342,   343,   343,   344,
     345,   346,   346,   347,   347,   347,   347,   347,   347,   348,
     349,   350,   350,   351,   351,   352,   353,   354,   355,   356,
     356,   357,   357,   358,   359,   360,   361,   362,   362,   363,
     363,   364,   365,   366,   367,   368,   368,   369,   369,   370,
     371,   372,   373,   374,   374,   375,   375,   376,   377,   378,
     379,   380,   381,   381,   382,   382,   383,   384,   385,   385,
     386,   387,   388,   389,   389,   390,   390,   390,   391,   391,
     392,   392,   393,   394,   394,   395,   395,   396,   397,   398,
     398,   399,   399,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   400,   401,   402,   402,   403,   403,   404,   405,
     406,   407,   408,   408,   409,   409,   410,   411,   412,   413,
     414,   414,   415,   415,   416,   417,   418,   419,   420,   420,
     421,   421,   422,   423,   424,   425,   426,   426,   427,   427,
     428,   429,   430,   431,   432,   433,   433,   434,   434,   435,
     436,   437,   437,   438,   439,   440,   440,   441,   441,   441,
     441,   442,   442,   443,   443,   444,   445,   446,   446,   447,
     448,   449,   450,   450,   451,   451,   452,   453,   454,   455,
     456,   457,   457,   458,   458,   459,   460,   461,   462,   463,
     464,   464,   465,   465,   466,   467,   468,   469,   470,   470,
     471,   472,   473,   474,   475,   476,   476,   477,   477,   478,
     479,   480,   480,   481,   482,   483,   484,   484,   485,   485,
     485,   486,   486,   487,   487,   488,   489,   490,   490,   491,
     491,   491,   491,   492,   492,   493,   493,   494,   495,   496,
     496,   497,   498,   499,   500,   500,   501,   501,   502,   503,
     504,   505,   506,   507,   508,   508,   509,   509,   509,   510,
     510,   511,   511,   512,   513,   514,   514,   515,   516,   517,
     518,   518,   519,   519,   520,   520,   521,   521,   522,   523,
     523,   524,   524,   525,   526,   527,   527,   528,   529,   529,
     530,   530,   531,   532,   533,   534,   534,   535,   536,   537,
     537,   538,   538,   539,   540,   541,   541,   542,   543,   544,
     545,   546,   546,   547,   548,   549,   549,   550,   550,   551,
     552,   553,   553,   554,   555,   556,   557,   557,   558,   558,
     559,   560,   561,   561,   562,   563,   563,   564,   565,   566,
     567,   567,   568,   569,   570,   570,   571,   572,   573,   574,
     574,   575,   576,   577,   577,   578,   579,   580,   581,   581,
     582,   583,   584,   584,   585,   586,   587,   588,   588,   589,
     590,   591,   591,   592,   593,   594,   595,   595,   596,   597,
     598,   598,   599,   600,   601,   602,   602,   603,   604,   605,
     605,   606,   607,   608,   609,   609,   610,   611,   612,   613,
     613,   614,   614,   614,   614,   614,   615,   615,   616,   616,
     617,   618,   618,   619,   619,   620,   621,   622,   623,   623,
     624,   624,   625,   626,   627,   627,   628,   629,   630,   631,
     631,   632,   632,   632,   633,   633,   634,   635,   636,   637,
     637,   638,   639,   639,   640,   640,   641,   642,   643,   644,
     644,   645,   646,   647,   647,   648,   648,   649,   650,   651,
     651,   652,   653,   654,   654,   655,   656,   656,   657,   657,
     658,   659,   659,   660,   661,   662,   663,   663,   664,   665,
     666,   666,   667,   668,   669,   670,   670,   671,   672,   673,
     673,   674,   675,   676,   677,   677,   678,   679,   680,   680,
     681,   682,   683,   684,   684,   685,   686,   687,   687,   688,
     689,   690,   691,   691,   692,   693,   694,   694,   695,   696,
     697,   698,   698,   699,   700,   701,   701,   702,   703,   704,
     705,   705,   706,   707,   708,   709,   709,   710,   710,   710,
     710,   710,   711,   711,   712,   712,   713,   714,   714,   715,
     715,   716,   717,   718,   719,   719,   720,   720,   721,   722,
     723,   723,   724,   725,   726,   727,   727,   728,   728,   728,
     729,   729,   730,   731,   732,   733,   733,   734,   735,   735,
     736,   736,   737,   738,   739,   740,   740,   741,   742,   743,
     743,   744,   744,   745,   746,   747,   747,   748,   749,   750,
     751,   752,   752,   753,   754,   754,   755,   756,   757,   758,
     758,   759,   760,   761,   761,   762,   763,   764,   765,   765,
     766,   767,   768,   768,   769,   770,   771,   772,   772,   773,
     774,   775,   775,   776,   777,   778,   779,   779,   780,   781,
     782,   782,   783,   784,   785,   786,   786,   787,   788,   789,
     789,   790,   791,   792,   793,   793,   794,   795,   796,   796,
     797,   798,   799,   800,   800,   801,   802,   803,   804,   804,
     805,   805,   805,   805,   805,   806,   806,   807,   807,   808,
     809,   809,   810,   810,   811,   812,   813,   814,   814,   815,
     815,   816,   817,   818,   818,   819,   820,   821,   822,   822,
     823,   823,   823,   824,   824,   825,   826,   827,   828,   828,
     829,   830,   831,   831,   832,   832,   833,   834,   835,   835,
     836,   837,   838,   839,   839,   840,   840,   840,   840,   841,
     841,   842,   842,   843,   844,   845,   845,   846,   847,   847,
     848,   848,   849,   850,   851,   851,   852,   853,   854,   854,
     855,   855,   856,   857,   858,   858,   859,   860,   861,   862,
     862,   863,   863,   863,   863,   864,   864,   865,   865,   866,
     867,   868,   868,   869,   870,   870,   871,   871,   872,   873,
     874,   875,   875,   876,   877,   878,   879,   879,   880,   881,
     882,   883,   883,   884,   885,   886,   887,   887,   888,   889,
     890,   891,   891,   892,   893,   894,   895,   895,   896,   897,
     898,   899,   900,   901,   902,   903,   904,   905,   906,   907,
     908,   909,   910,   911,   912,   913,   914,   915,   916,   916,
     917,   917,   918,   919,   920,   921,   921,   922,   922,   923,
     924,   925,   926,   926,   927,   927,   928,   929,   930,   931,
     931,   932,   932,   932,   933,   934,   934,   935,   935,   935,
     935
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     0,     1,     1,     1,     1,     3,
       5,     0,     2,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     2,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     2,     1,     0,     2,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     3,     1,
       1,     0,     2,     1,     1,     3,     1,     3,     1,     1,
       0,     2,     1,     1,     3,     1,     3,     1,     1,     0,
       2,     1,     1,     3,     1,     3,     1,     0,     1,     3,
       1,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       2,     1,     0,     2,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       0,     2,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     3,
       1,     1,     0,     2,     1,     1,     3,     1,     3,     1,
       1,     0,     2,     1,     1,     3,     1,     3,     1,     1,
       0,     2,     1,     1,     3,     1,     3,     1,     0,     1,
       3,     1,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     2,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     4,     3,
       8,     3,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     2,     1,     0,     2,     1,     1,
       1,     2,     1,     3,     1,     0,     3,     1,     0,     1,
       1,     1,     1,     3,     4,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     4,
       3,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     3,     6,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     2,     3,     1,     4,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     0,     1,     1,     1,     1,     3,     3,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     0,     4,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     3,     6,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     1,
       2,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     0,     1,
       1,     1,     1,     3,     3,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     4,
       3,     0,     2,     1,     1,     1,     1,     3,     6,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     1,     2,     3,     1,     4,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     1,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     3,
       3,     4,     1,     1,     2,     1,     3,     4,     4,     1,
       1,     1,     1,     1,     2,     0,     2,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     3,     0,     4,     1,     5,     0,    11,     8,     2,
       6,     7,    13,     0,   133,     0,     9,   135,   212,     0,
       0,    17,    12,    14,    15,   214,   290,     0,     0,   139,
     134,   136,   137,    16,    32,    81,    89,    57,   113,    73,
      65,    97,   105,     0,    19,    20,    22,     0,    23,     0,
      24,     0,    25,     0,    26,     0,    27,     0,    28,     0,
      29,     0,    30,     0,   292,   433,     0,     0,   218,   213,
     215,   216,   138,   186,   177,   159,   168,   192,   151,     0,
     141,   142,   144,     0,   145,   161,   146,   170,   147,   179,
     148,   187,   149,     0,    18,    21,  1065,     0,   998,     0,
    1008,     0,    33,    34,    37,   995,   996,   997,    36,  1005,
    1006,  1007,    38,     0,    61,    56,    58,    59,     0,    69,
      64,    66,    67,     0,    77,    72,    74,    75,     0,    85,
      80,    82,    83,     0,    93,    88,    90,    91,     0,   101,
      96,    98,    99,     0,   109,   104,   106,   107,  1065,     0,
     114,   435,    10,   437,     0,   296,   291,   293,   294,   217,
     238,   230,   270,   262,   254,   246,     0,   220,   221,   223,
       0,   224,     0,   225,     0,   226,     0,   227,     0,   228,
       0,   140,   143,     0,   155,   150,   152,   153,     0,   160,
       0,   169,     0,   178,     0,   188,     0,   193,     0,     0,
    1065,  1065,     0,    42,    31,    39,    40,    35,    63,    60,
       0,    71,    68,     0,    79,    76,     0,    87,    84,     0,
      95,    92,     0,   103,   100,     0,   111,   108,     0,     0,
       0,   118,   112,   115,   116,     0,   436,   295,   337,   345,
     413,   329,   313,   321,   353,   407,   398,   380,   389,     0,
     298,   299,   301,     0,   302,     0,   303,     0,   304,     0,
     305,     0,   306,     0,   307,   382,   308,   391,   309,   400,
     310,   408,   311,     0,   219,   222,     0,   234,   229,   231,
     232,     0,   242,   237,   239,   240,     0,   250,   245,   247,
     248,     0,   258,   253,   255,   256,     0,   266,   261,   263,
     264,     0,   271,   157,   154,     0,     0,   158,     0,  1013,
     162,   164,   163,  1010,  1011,  1012,     0,   167,   171,   173,
     172,     0,   176,   180,   182,   181,     0,   185,     0,   197,
     191,   194,   195,  1065,  1064,  1067,  1068,  1069,  1070,  1066,
     999,  1009,    41,    48,     0,    44,    45,    50,    62,    70,
      78,    86,    94,   102,   110,  1065,   124,   117,     0,   120,
     121,   126,     0,   446,   434,   443,   444,  1065,  1065,  1065,
    1065,   438,   441,   442,   439,   440,   297,   300,     0,   317,
     312,   314,   315,     0,   325,   320,   322,   323,     0,   333,
     328,   330,   331,     0,   341,   336,   338,   339,     0,   349,
     344,   346,   347,  1065,     0,   354,     0,   381,     0,   390,
       0,   399,     0,   409,     0,   414,   236,   233,     0,   244,
     241,     0,   252,   249,     0,   260,   257,     0,  1059,  1060,
     265,     0,   268,     0,   275,   269,   272,   273,   156,     0,
     166,  1065,     0,   175,     0,   184,   190,     0,   203,   196,
       0,   199,   200,   205,  1034,    43,    46,     0,    49,  1029,
     119,   122,     0,   125,   445,   452,     0,   954,   449,   454,
       0,     0,     0,     0,   319,   316,     0,   327,   324,     0,
     335,   332,     0,   343,   340,     0,   351,   348,     0,     0,
       0,   358,   352,   355,   356,     0,   379,   383,   385,   384,
       0,   388,   392,   394,   393,     0,   397,   401,   403,   402,
       0,   406,     0,   418,   412,   415,   416,   235,   243,   251,
     259,   267,   281,   274,     0,   277,   278,   283,   165,  1014,
     174,   183,   189,   198,   201,     0,   204,     0,    55,    47,
       0,  1003,    51,    53,    52,  1000,  1001,  1002,     0,   132,
     123,     0,  1018,   127,   130,   128,   129,  1015,  1016,  1017,
     447,   956,   450,   448,     0,     0,   453,  1065,  1065,  1065,
    1065,   318,   326,   334,   342,   350,  1065,   364,   357,     0,
     360,   361,   365,     0,   387,     0,   396,     0,   405,   411,
       0,   424,   417,     0,   420,   421,   426,   276,   279,     0,
     282,     0,   211,   202,   206,   209,   207,   208,    54,  1065,
     131,  1065,  1065,     0,   957,     0,   451,  1065,     0,   455,
     456,   457,  1021,  1026,  1032,  1037,  1035,   359,   362,     0,
     386,   395,   404,   410,   419,   422,     0,   425,     0,   289,
     280,   284,   287,   285,   286,   210,  1004,  1019,     0,     0,
     961,   955,   958,   959,   462,   486,     0,     0,  1065,     0,
     374,     0,   993,   366,   363,   371,   372,   369,   990,   991,
     992,   370,   368,   367,     0,   432,   423,   427,   430,   428,
     429,   288,  1065,   960,   967,     0,   963,   964,   969,   488,
     495,     0,     0,   463,   464,   467,   466,   468,  1065,   459,
     378,   377,   373,     0,   376,  1065,   431,  1033,   962,   965,
       0,   968,   497,   649,   498,     0,   492,   487,   489,   490,
       0,   472,   461,   469,   470,   465,   458,   375,   994,     0,
     978,   966,   975,   976,  1065,   970,   972,   973,   971,   974,
     651,   785,   652,  1065,     0,   499,   494,   491,     0,   471,
     478,     0,   474,   475,   480,     0,   986,   987,   977,     0,
     980,   981,   983,   984,   985,     0,   787,   918,   788,  1065,
       0,   653,     0,   505,   502,   496,   500,   501,   493,   473,
     476,     0,   479,   989,     0,   979,   982,  1065,   920,     0,
       0,  1065,     0,   789,     0,   659,   656,   650,   654,   655,
    1065,   507,     0,   521,     0,     0,   485,   477,   481,   483,
     482,   988,  1024,   460,  1065,     0,   921,     0,   795,   792,
     786,   790,   791,  1065,   661,     0,   678,     0,  1031,   503,
     523,   542,     0,  1065,     0,   508,   484,     0,     0,   925,
     919,   922,   923,  1065,   797,     0,   811,     0,  1028,   657,
     680,   740,     0,  1065,     0,   662,   544,   604,     0,     0,
     524,     0,     0,   512,   506,   509,   510,  1065,   931,   924,
       0,   927,   928,   933,  1027,   793,   813,   873,     0,  1065,
       0,   798,   658,   686,   683,   679,   681,   682,     0,     0,
     666,   660,   663,   664,   504,   550,   547,   543,   545,   546,
       0,   528,   522,   525,   526,  1065,   511,   518,     0,   514,
     515,     0,  1030,   926,   929,     0,   932,   794,   819,   816,
     812,   814,   815,     0,     0,   802,   796,   799,   800,   743,
     741,   745,   688,     0,   695,     0,  1065,   672,   665,     0,
     668,   669,   673,   607,   605,   609,   552,     0,   559,     0,
     527,   534,     0,   530,   531,     0,  1036,   513,   516,  1065,
       0,     0,   942,   930,   939,   940,   934,   936,   937,   935,
     938,   876,   874,   878,   821,     0,   828,     0,  1065,   808,
     801,     0,   804,   805,     0,     0,   744,   684,   697,   704,
       0,  1065,     0,   689,  1025,   667,   670,  1065,     0,     0,
     608,   548,   561,   568,     0,     0,   553,   529,   532,  1065,
       0,     0,     0,   517,     0,   950,   951,   941,     0,   944,
     945,   947,   948,   949,     0,   877,   817,   830,   837,     0,
       0,   822,  1020,   803,   806,  1065,     0,     0,   755,   742,
     752,   753,  1065,   746,   751,   750,   749,   748,   747,   706,
     713,     0,     0,   698,     0,  1040,   692,   687,   690,   691,
       0,     0,   671,     0,   619,   606,   616,   617,   610,   615,
     614,   613,   612,   611,   570,   577,     0,     0,   562,  1040,
     556,   551,   554,   555,     0,     0,   539,   533,   536,   537,
    1065,     0,   953,     0,   943,   946,     0,   888,   875,   885,
     886,   879,   884,   883,   882,   880,   881,   839,   846,     0,
       0,   831,  1040,   825,   820,   823,   824,     0,     0,   807,
     773,   762,   754,     0,   757,   759,     0,   758,   770,   775,
       0,   715,   722,     0,     0,   707,  1040,   701,   696,   699,
     700,  1065,     0,     0,   694,  1038,  1039,  1065,   676,   677,
       0,   637,   618,   626,     0,   621,   623,     0,   622,   634,
     639,   579,   586,     0,     0,   571,  1040,   565,   560,   563,
     564,     0,   558,  1065,   541,   538,     0,   519,   520,   952,
     895,   906,   887,     0,   890,   892,     0,   891,   903,   908,
     848,   855,     0,     0,   840,  1040,   834,   829,   832,   833,
       0,   827,  1065,     0,   756,   760,  1065,     0,   771,     0,
     774,  1065,   724,   731,     0,     0,   716,  1040,   710,   705,
     708,   709,     0,   703,  1022,  1065,     0,   693,  1043,  1041,
    1045,   674,   675,   620,   624,  1065,     0,   635,     0,   638,
     588,   595,     0,     0,   580,  1040,   574,   569,   572,   573,
       0,   567,   557,   535,   540,   889,   893,  1065,     0,   904,
       0,   907,   857,   864,     0,     0,   849,  1040,   843,   838,
     841,   842,     0,   836,   826,   809,   810,     0,     0,   767,
     761,   764,   765,  1040,   782,   772,   780,   781,   776,   779,
     778,   777,  1023,   733,   685,     0,     0,   725,  1040,   719,
     714,   717,   718,     0,   712,   702,     0,     0,  1055,  1050,
    1052,  1053,     0,  1044,     0,     0,   631,   625,   628,   629,
    1040,   646,   636,   644,   645,   640,   643,   642,   641,   597,
     549,     0,     0,   589,  1040,   583,   578,   581,   582,     0,
     576,   566,     0,     0,   900,   894,   897,   898,  1040,   915,
     905,   913,   914,   909,   912,   911,   910,   866,   818,     0,
       0,   858,  1040,   852,   847,   850,   851,     0,   845,   835,
    1065,  1061,  1062,  1063,   766,     0,   769,     0,   784,     0,
     734,  1040,   728,   723,   726,   727,     0,   721,   711,  1065,
       0,  1054,     0,  1042,  1065,  1065,  1046,  1048,  1047,  1065,
     630,     0,   633,     0,   648,     0,   598,  1040,   592,   587,
     590,   591,     0,   585,   575,  1065,   899,     0,   902,     0,
     917,     0,   867,  1040,   861,   856,   859,   860,     0,   854,
     844,   763,   768,   783,  1040,   737,   732,   735,   736,     0,
     730,   720,  1051,  1056,     0,     0,     0,   627,   632,   647,
    1040,   601,   596,   599,   600,     0,   594,   584,   896,   901,
     916,  1040,   870,   865,   868,   869,     0,   863,   853,     0,
     739,   729,  1049,  1065,  1065,     0,   603,   593,     0,   872,
     862,   738,  1057,  1058,   602,   871
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     9,    10,    11,    13,    14,    15,
      22,    23,    24,    43,    44,    45,    46,    47,   101,   102,
     103,   204,   205,   206,   344,   345,   346,   347,   457,   458,
     542,   539,    48,    49,   115,   116,   117,   210,    50,    51,
     120,   121,   122,   213,    52,    53,   125,   126,   127,   216,
      54,    55,   130,   131,   132,   219,    56,    57,   135,   136,
     137,   222,    58,    59,   140,   141,   142,   225,    60,    61,
     145,   146,   147,   228,    62,    63,   149,   232,   233,   234,
     358,   359,   360,   361,   462,   463,   553,   550,    18,    19,
      30,    31,    32,    79,    80,    81,    82,    83,   185,   186,
     187,   305,    84,    85,   188,   189,   310,   307,   439,    86,
      87,   190,   191,   318,   317,   442,    88,    89,   192,   193,
     323,   322,   444,    90,    91,   194,   327,   447,    92,    93,
     196,   330,   331,   332,   450,   451,   452,   453,   535,   536,
     604,   603,    26,    27,    69,    70,    71,   166,   167,   168,
     169,   170,   278,   279,   280,   418,   171,   172,   283,   284,
     285,   421,   173,   174,   288,   289,   290,   424,   175,   176,
     293,   294,   295,   427,   177,   178,   298,   299,   300,   431,
     179,   180,   301,   435,   436,   437,   524,   525,   526,   527,
     599,   600,   641,   640,    65,    66,   156,   157,   158,   249,
     250,   251,   252,   253,   380,   381,   382,   476,   254,   255,
     385,   386,   387,   479,   256,   257,   390,   391,   392,   482,
     258,   259,   395,   396,   397,   485,   260,   261,   400,   401,
     402,   488,   262,   263,   404,   492,   493,   494,   579,   580,
     581,   582,   629,   663,   664,   665,   666,   703,   704,   264,
     265,   406,   407,   497,   496,   583,   266,   267,   408,   409,
     502,   501,   585,   268,   269,   410,   411,   507,   506,   587,
     270,   271,   412,   511,   590,   272,   273,   414,   514,   515,
     516,   593,   594,   595,   596,   636,   637,   677,   676,   152,
     153,   235,   236,   371,   364,   365,   366,   466,   467,   468,
     469,   565,   566,   619,   620,   621,   616,   655,   656,   692,
     693,   694,   722,   723,   724,   751,   752,   753,   754,   781,
     782,   808,   807,   690,   691,   717,   718,   719,   748,   713,
     714,   744,   775,   776,   777,   802,   803,   804,   834,   864,
     865,   866,   908,   909,   910,   911,   960,  1013,   831,   832,
     859,   902,   903,   904,   952,   953,   954,   955,  1010,  1087,
    1088,  1089,  1176,   857,   858,   897,   898,   899,   947,   948,
     949,  1005,  1081,  1082,  1083,  1171,  1003,  1004,  1077,  1168,
    1169,  1170,  1250,  1075,  1076,  1164,  1247,  1248,  1249,  1339,
    1162,  1163,  1243,  1336,  1337,  1338,  1412,  1241,  1242,  1332,
    1409,  1410,  1411,  1455,  1330,  1331,  1405,  1452,  1453,  1454,
    1475,   894,   944,   945,   999,  1000,  1068,  1065,  1066,  1067,
    1154,  1155,  1156,  1157,  1236,  1317,  1318,  1319,  1401,  1158,
    1159,  1160,  1238,  1239,  1325,  1322,  1323,  1324,  1403,   741,
     742,   770,   797,   798,   799,   825,   826,   827,   854,   891,
     892,   893,   939,   940,   941,   942,   998,  1062,  1150,   851,
     852,   885,   886,   887,   933,   934,   935,   992,  1057,  1058,
    1059,  1143,   989,   990,  1052,  1138,  1139,  1140,  1222,  1050,
    1051,  1134,  1219,  1220,  1221,  1303,  1132,  1133,  1215,  1300,
    1301,  1302,  1386,  1213,  1214,  1296,  1383,  1384,  1385,  1439,
    1294,  1295,  1379,  1436,  1437,  1438,  1469,   882,   930,   931,
     985,   986,  1043,  1039,  1040,  1041,  1123,  1124,  1125,  1126,
    1207,  1280,  1281,  1282,  1375,  1127,  1128,  1129,  1209,  1210,
    1288,  1285,  1286,  1287,  1377,   767,   768,   792,   820,   821,
     822,   845,   846,   847,   880,   926,   927,   928,   981,   982,
     983,   984,  1036,  1119,   877,   878,   920,   921,   922,   975,
     976,   977,  1030,  1114,  1115,  1116,  1200,  1028,  1029,  1110,
    1197,  1198,  1199,  1272,  1108,  1109,  1193,  1269,  1270,  1271,
    1367,  1191,  1192,  1265,  1364,  1365,  1366,  1428,  1263,  1264,
    1360,  1425,  1426,  1427,  1466,  1358,  1359,  1421,  1463,  1464,
    1465,  1478,   917,   972,   973,  1024,  1025,  1101,  1098,  1099,
    1100,  1183,  1184,  1185,  1186,  1258,  1345,  1346,  1347,  1417,
    1187,  1188,  1189,  1260,  1261,  1353,  1350,  1351,  1352,  1419,
     789,   790,   815,   840,   841,   842,   870,   871,   872,   873,
     915,   916,   966,   963,   964,   965,  1018,  1019,  1020,  1021,
    1022,  1023,  1093,   563,   564,   613,   651,   652,   653,   685,
     686,   687,   688,   710,   711,   735,   731,   732,   733,   759,
     760,   761,   762,   763,   764,   784,   667,   668,   669,   670,
     104,   105,   106,   107,   544,   545,   546,   547,   108,   109,
     110,   111,   312,   313,   314,   315,   556,   557,   558,   559,
     881,   372,   993,  1047,   739,   855,   373,   793,   771,   150,
     816,   745,   374,   614,   112,   405,   835,   375,  1144,  1145,
    1229,  1230,  1312,  1313,  1396,  1393,  1146,  1226,  1309,  1310,
    1311,  1397,  1398,   432,  1376,   198,   199,   339
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1247
static const yytype_int16 yypact[] =
{
      62, -1247,    88,    81, -1247, -1247,   220,    52, -1247, -1247,
   -1247, -1247, -1247,    99,    66,   257, -1247, -1247,    74,   265,
     -30, -1247, -1247, -1247, -1247, -1247,    64,   279,   -15, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247,    93,   192, -1247, -1247,   295, -1247,   297,
   -1247,   361, -1247,   365, -1247,   374, -1247,   380, -1247,   382,
   -1247,   389, -1247,   132, -1247,   115,   415,    68, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   110,
     171, -1247, -1247,   419, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247,   388, -1247,   132, -1247, -1247, -1247,   159, -1247,   203,
   -1247,   423,   295, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247,    31, -1247, -1247, -1247, -1247,    23, -1247,
   -1247, -1247, -1247,    30, -1247, -1247, -1247, -1247,    38, -1247,
   -1247, -1247, -1247,    37, -1247, -1247, -1247, -1247,    21, -1247,
   -1247, -1247, -1247,    16, -1247, -1247, -1247, -1247, -1247,   425,
   -1247, -1247, -1247, -1247,   104, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247,   156,   106, -1247, -1247,
     427, -1247,   429, -1247,   431, -1247,   433, -1247,   438, -1247,
     132, -1247, -1247,    17, -1247, -1247, -1247, -1247,   215,    77,
     222,    77,   230,    77,   235, -1247,   440, -1247,   243,    -3,
   -1247, -1247,   -45, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
     141, -1247, -1247,   126, -1247, -1247,   130, -1247, -1247,   177,
   -1247, -1247,   180, -1247, -1247,   150, -1247, -1247,   135,   304,
     -33, -1247, -1247, -1247, -1247,   442,   200, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   255,
     105, -1247, -1247,   444, -1247,   455, -1247,   457, -1247,   462,
   -1247,   464, -1247,   308, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247,   388, -1247,   132, -1247, -1247,    40, -1247, -1247, -1247,
   -1247,    44, -1247, -1247, -1247, -1247,    11, -1247, -1247, -1247,
   -1247,    15, -1247, -1247, -1247, -1247,    24, -1247, -1247, -1247,
   -1247,   466, -1247, -1247, -1247,   165,   472, -1247,   331, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247,   472, -1247, -1247, -1247,
   -1247,   472, -1247, -1247, -1247, -1247,   338, -1247,    12, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247,   241,   195, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   223,   231,
   -1247, -1247,   -17, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,    33, -1247,
   -1247, -1247, -1247,    20, -1247, -1247, -1247, -1247,    29, -1247,
   -1247, -1247, -1247,    47, -1247, -1247, -1247, -1247,    42, -1247,
   -1247, -1247, -1247, -1247,   470, -1247,   353,    77,   356,    77,
     358,    77,   363, -1247,   473, -1247, -1247, -1247,   281, -1247,
   -1247,   310, -1247, -1247,   205, -1247, -1247,   247, -1247, -1247,
   -1247,   299, -1247,    18, -1247, -1247, -1247, -1247, -1247,   347,
   -1247, -1247,   376, -1247,   378, -1247, -1247,   384, -1247, -1247,
     330,   341, -1247, -1247, -1247, -1247, -1247,   475,   269, -1247,
   -1247, -1247,   477,   372, -1247, -1247,   418,   -56, -1247, -1247,
     503,   533,   560,   609, -1247, -1247,   395, -1247, -1247,   339,
   -1247, -1247,   445, -1247, -1247,   458, -1247, -1247,   511,   610,
     -41, -1247, -1247, -1247, -1247,   472, -1247, -1247, -1247, -1247,
     472, -1247, -1247, -1247, -1247,   472, -1247, -1247, -1247, -1247,
     612, -1247,    28, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247,   488,   490, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247,   479,   372,   465, -1247, -1247,
     621, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   496, -1247,
   -1247,   622, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247,   598,   617,    82, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   459,
     467, -1247, -1247,   451, -1247,   450, -1247,   456, -1247, -1247,
     460, -1247, -1247,   501,   509, -1247, -1247, -1247, -1247,   481,
     372,   505, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247,   483, -1247,   484, -1247, -1247,   637, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   354,
   -1247, -1247, -1247, -1247, -1247, -1247,   487,   372,   515, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   635,   -66,
   -1247, -1247, -1247, -1247, -1247,   523,   295,   638, -1247,    22,
   -1247,   643, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247,   517, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247,   513,   498, -1247, -1247, -1247,
     461,   489,   491,   295, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247,   492, -1247, -1247, -1247, -1247, -1247, -1247,
     493,   366, -1247,   525,   625,    36, -1247, -1247, -1247, -1247,
      84, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   -10,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247,   562,   629, -1247,   495, -1247, -1247, -1247,   537, -1247,
   -1247,   507,   519, -1247, -1247,   653, -1247, -1247, -1247,   518,
     137, -1247, -1247, -1247, -1247,   654, -1247,   524,   639, -1247,
     497, -1247,   656,   482, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247,   502,   314, -1247,   602, -1247, -1247, -1247, -1247,   521,
     640, -1247,   504, -1247,   658,   494, -1247, -1247, -1247, -1247,
   -1247, -1247,   499,   486,   641,   526, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247,   506, -1247,   666,   574, -1247,
   -1247, -1247, -1247, -1247, -1247,   555,   591,   660, -1247, -1247,
   -1247,   593,   641, -1247,   508, -1247, -1247,   677,   120, -1247,
   -1247, -1247, -1247, -1247, -1247,   592,   600,   672, -1247, -1247,
   -1247, -1247,   510, -1247,   512, -1247, -1247, -1247,   514,   516,
   -1247,   684,    79, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
     558,   566, -1247, -1247, -1247, -1247, -1247, -1247,   520, -1247,
     522, -1247,   568,   606, -1247, -1247, -1247, -1247,   686,   -60,
   -1247, -1247, -1247, -1247,   572,   611, -1247, -1247, -1247, -1247,
     349, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   528,   529,
   -1247,   661, -1247, -1247, -1247,   527,   366,   575,   615, -1247,
   -1247, -1247, -1247,   696,    45, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247,   618,   632,   690, -1247, -1247, -1247,   530,
     594, -1247,   674, -1247, -1247, -1247, -1247,   630,   642,   690,
   -1247, -1247,   535,   538, -1247,   680, -1247, -1247, -1247, -1247,
     699,    25, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247,   634,   649,   690, -1247, -1247,
   -1247,   623,   633, -1247,   689,   531,   302, -1247, -1247,   655,
     690, -1247,   534, -1247, -1247, -1247, -1247, -1247,   717,   536,
     337, -1247, -1247,   657,   690,   541, -1247, -1247, -1247, -1247,
     543,   723,   472, -1247,   728, -1247, -1247, -1247,   604,   147,
   -1247, -1247, -1247, -1247,   545,   285, -1247, -1247,   662,   690,
     548, -1247, -1247, -1247, -1247, -1247,   724,   -27, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
     624,   690,   550, -1247,   730,   659, -1247, -1247, -1247, -1247,
     731,   556, -1247,   -55, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247,   626,   690,   554, -1247,   659,
   -1247, -1247, -1247, -1247,   734,     9, -1247, -1247, -1247, -1247,
   -1247,   557, -1247,   678, -1247, -1247,   -21, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   628,   690,
     559, -1247,   659, -1247, -1247, -1247, -1247,   740,   472, -1247,
   -1247, -1247, -1247,   619,   627, -1247,   710,   647, -1247, -1247,
     745, -1247,   596,   690,   561, -1247,   659, -1247, -1247, -1247,
   -1247, -1247,   712,   667, -1247,   663, -1247, -1247, -1247, -1247,
     636, -1247, -1247, -1247,   631,   576, -1247,   719,   651, -1247,
   -1247, -1247,   607,   690,   563, -1247,   659, -1247, -1247, -1247,
   -1247,   673, -1247, -1247, -1247, -1247,   580, -1247, -1247, -1247,
   -1247, -1247, -1247,   644,   669, -1247,   725,   664, -1247, -1247,
   -1247,   613,   690,   565, -1247,   659, -1247, -1247, -1247, -1247,
     679, -1247, -1247,   681, -1247, -1247, -1247,   567, -1247,   569,
     244, -1247, -1247,   605,   690,   571, -1247,   659, -1247, -1247,
   -1247, -1247,   697, -1247, -1247, -1247,   573, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247,   577, -1247,   579,   244,
   -1247,   608,   690,   581, -1247,   659, -1247, -1247, -1247, -1247,
     698, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   583, -1247,
     586,   244, -1247,   614,   690,   588, -1247,   659, -1247, -1247,
   -1247, -1247,   703, -1247, -1247, -1247, -1247,   765,    32, -1247,
   -1247, -1247, -1247,   659, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247,   690,   590, -1247,   659, -1247,
   -1247, -1247, -1247,   702, -1247, -1247,   771,    50, -1247, -1247,
   -1247, -1247,   769,   564,   774,     8, -1247, -1247, -1247, -1247,
     659, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247,   690,   595, -1247,   659, -1247, -1247, -1247, -1247,   708,
   -1247, -1247,   777,    61, -1247, -1247, -1247, -1247,   659, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   690,
     597, -1247,   659, -1247, -1247, -1247, -1247,   711, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247,   668, -1247,   682, -1247,   599,
   -1247,   659, -1247, -1247, -1247, -1247,   675, -1247, -1247, -1247,
     700, -1247,   783, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247,   616, -1247,   688, -1247,   601, -1247,   659, -1247, -1247,
   -1247, -1247,   683, -1247, -1247, -1247, -1247,   701, -1247,   691,
   -1247,   603, -1247,   659, -1247, -1247, -1247, -1247,   685, -1247,
   -1247, -1247, -1247, -1247,   659, -1247, -1247, -1247, -1247,   645,
   -1247, -1247, -1247, -1247,   692,   790,   791, -1247, -1247, -1247,
     659, -1247, -1247, -1247, -1247,   646, -1247, -1247, -1247, -1247,
   -1247,   659, -1247, -1247, -1247, -1247,   648, -1247, -1247,   650,
   -1247, -1247, -1247, -1247, -1247,   652, -1247, -1247,   665, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247,   754, -1247, -1247, -1247, -1247,
     705, -1247, -1247, -1247, -1247, -1247,   469, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247,   441, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247,   722, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247,   352, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   670,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   284, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247,   570, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
     232, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247,   216, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   348,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247,   123, -1247, -1247, -1247, -1247, -1247,    65, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247,   -91, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247,  -134, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247,  -334, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
    -336, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247,  -117, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,  -299, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247,  -298, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
    -154, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247,  -353, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247,  -355, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,   -38, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,  -185, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247,   149, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247,    76, -1247, -1247, -1247, -1247,  -708, -1247, -1247, -1247,
     -89, -1247, -1247, -1247,  -457, -1247, -1247, -1247,  -607, -1247,
   -1247, -1247,  -183, -1247, -1247, -1247,  -529, -1247, -1247, -1247,
    -187, -1247,  -945,  -927,   -76,  -145, -1247, -1247, -1247,   -75,
   -1247, -1247, -1247, -1247,  -578, -1247,  -823, -1247, -1056, -1247,
   -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247, -1247,
   -1247, -1247, -1247,  -305, -1246,  -148, -1247, -1247
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     229,   440,   195,   736,  1006,   334,   555,   607,   320,   860,
     325,   443,  1371,  1174,  1372,  1373,   445,   422,   197,   425,
     226,   303,   672,  1172,   477,   223,    33,   211,   700,   701,
     428,   429,  1031,   480,   214,   208,  1371,   474,  1372,  1373,
     746,   220,   217,    72,   416,  1053,   486,   464,  1151,   696,
     419,   483,   340,   341,  1390,   755,  1201,   756,   757,  1078,
      73,   937,    74,   342,    75,  1371,    76,  1372,  1373,  1402,
    1180,   644,   683,  1072,     1,  1152,  1120,    34,   697,   606,
    1223,   561,  1181,    35,  1111,   684,   696,    36,     4,    37,
    1014,   465,  1015,  1016,  1121,     5,   356,  1418,  1106,   357,
     311,    38,   319,  1122,   324,   302,  1135,    12,   680,  1182,
    1251,    39,   343,    40,    16,   697,    77,   484,   617,    41,
      97,    98,   577,    17,   938,    64,   308,   309,   159,   578,
     465,  1165,  1153,    25,  1391,   618,   979,    42,   417,  1273,
     420,   448,   758,   643,   449,   980,    78,   522,   487,    94,
     523,   209,   218,  1416,  1374,   221,   747,   591,   148,  1017,
     592,  1304,   200,   160,  1194,   161,   237,   212,   181,   481,
     430,   224,   215,   238,   238,   810,   478,  1073,   151,   304,
     679,   426,   413,   423,   227,   454,   702,   475,  1216,  1340,
     584,   335,   336,   337,   338,   586,  1400,  1175,   415,   162,
     588,   160,   755,   161,   756,   757,   201,   459,   967,   239,
     239,  1368,  1014,   163,  1015,  1016,   274,   367,  1244,   470,
     471,   472,   473,   368,   499,   306,   504,  1378,   509,   369,
       7,     8,   316,   164,   370,   240,   240,   162,   749,   165,
     321,   750,  1387,   241,   241,   326,    73,  1266,    74,   333,
      75,   163,    76,   868,   738,   489,   869,   242,   242,   243,
     243,   348,   991,   906,  1404,  1291,   907,    20,    21,  1297,
     349,   164,   350,   244,   244,    28,    29,   165,  1413,   245,
     245,   246,   246,   247,   247,   248,   248,    97,    98,    67,
      68,   351,  1420,   529,  1328,   551,   552,  1333,   352,    34,
     353,   879,    77,   354,  1042,    35,  1429,   113,   114,    36,
     355,    37,    97,    98,   540,   541,  1356,   376,   498,  1361,
     503,  1042,   508,    38,   853,  1440,    96,   438,    97,    98,
     540,   541,    78,    39,   441,    40,   551,   552,    97,    98,
     403,    41,    99,   100,   446,    97,    98,   540,   541,   455,
    1380,  1456,   343,   551,   552,   460,  1042,    97,    98,    42,
     356,    99,   100,   495,   659,   660,   500,  1467,   505,   543,
     833,   118,   119,   510,   554,   123,   124,   519,  1470,   517,
      97,    98,   540,   541,   128,   129,  1406,   734,   551,   552,
     133,   134,   138,   139,  1476,   661,   662,    97,    98,   143,
     144,    99,   100,   308,   309,  1479,   518,   661,   662,    97,
      98,   540,   541,   520,  1422,    97,    98,   540,   541,   622,
     623,   624,   625,   551,   552,   154,   155,   528,   626,   183,
     184,    97,    98,   202,   203,   230,   231,   276,   277,   281,
     282,   286,   287,   291,   292,   521,   673,   605,   296,   297,
     328,   329,   362,   363,   378,   379,   531,  1046,   530,   969,
     532,   646,   533,   647,   648,   383,   384,   388,   389,   657,
     448,  1071,   393,   394,   398,   399,   433,   434,   428,   429,
     490,   491,   560,   512,   513,   537,   538,   548,   549,   601,
     602,   638,   639,   649,   650,   572,  1104,   674,   675,   715,
     716,   720,   721,   729,   730,   773,   774,   795,   796,   567,
     699,   642,   805,   806,   818,   819,   838,   839,   862,   863,
     883,   884,   889,   890,   895,   896,   900,   901,   574,  1045,
     918,   919,   924,   925,   707,   950,   951,   961,   962,   568,
     671,  1037,  1038,  1070,  1055,  1056,  1063,  1064,   678,   571,
     726,  1079,  1080,  1085,  1086,  1096,  1097,   728,  1112,  1113,
    1136,  1137,  1148,  1149,  1166,  1167,   569,   695,  1103,  1195,
    1196,  1217,  1218,  1245,  1246,  1267,  1268,  1278,  1279,  1283,
    1284,  1298,  1299,  1307,  1308,   573,   765,  1315,  1316,  1320,
    1321,  1334,  1335,  1343,  1344,   772,  1348,  1349,  1362,  1363,
    1381,  1382,  1394,  1395,   695,  1407,  1408,  1423,  1424,  1434,
    1435,  1450,  1451,  1461,  1462,   570,   576,   575,   589,   522,
     597,   794,   737,   608,   609,   611,   610,   615,   612,   627,
     577,   630,   631,   634,   632,   645,   633,   654,   591,   812,
     658,   682,   689,   817,   698,   681,   705,   706,   740,   684,
     712,   708,   828,   743,   769,   766,   727,   778,   783,   788,
     787,   779,   800,   791,   823,   801,   837,   814,   811,   813,
     785,   830,   843,   844,   833,   848,   750,   824,   850,   849,
     856,  1290,   853,   867,   836,   861,   875,   876,   879,   829,
     905,   932,   936,   809,   913,   874,   946,   929,   959,   868,
     974,   943,   978,   988,   971,   888,   987,  1091,   991,  1012,
    1327,   997,   957,  1002,   995,   937,   907,  1009,  1001,   912,
    1027,  1007,  1026,  1033,   979,   951,  1035,  1061,  1049,  1090,
    1074,   923,  1355,  1092,  1118,  1107,  1141,  1147,  1094,  1131,
    1173,  1161,  1142,  1190,  1179,  1178,  1202,  1206,  1121,  1204,
    1120,  1211,  1225,  1227,  1151,  1212,  1235,   956,  1232,  1252,
    1180,  1233,  1257,  1153,  1228,  1274,  1240,  1181,  1254,  1305,
    1341,  1370,  1262,  1276,  1255,  1369,  1388,  1389,  1293,  1392,
    1399,  1329,  1414,  1415,  1443,  1430,  1433,  1357,   994,  1444,
    1432,  1441,  1449,  1459,  1472,  1460,  1473,  1474,    95,  1457,
     461,  1468,   182,   534,  1448,  1471,  1477,   207,  1480,   598,
     635,  1011,   628,  1203,   456,   562,   725,   780,   958,  1008,
     377,  1234,  1237,   996,  1481,  1205,  1484,   968,  1034,  1208,
    1032,  1256,  1259,   914,  1095,   709,   786,   275,  1105,  1485,
     970,  1048,     0,  1054,     0,     0,     0,     0,     0,  1060,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1084,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1117,     0,     0,
       0,     0,     0,     0,  1130,     0,     0,  1044,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1069,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1102,     0,     0,     0,
       0,     0,  1177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1224,     0,     0,     0,     0,     0,  1231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1275,     0,     0,     0,  1277,     0,
       0,     0,     0,  1292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1306,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1314,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1342,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1289,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1326,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1354,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1431,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1442,     0,     0,     0,     0,  1445,  1446,     0,     0,
       0,  1447,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1458,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1482,  1483
};

static const yytype_int16 yycheck[] =
{
     148,   306,    91,   711,   949,     8,   463,   536,   191,   832,
     193,   316,     4,     4,     6,     7,   321,     6,    93,     4,
       4,     4,   629,  1079,     4,     4,    56,     4,     6,     7,
       6,     7,   977,     4,     4,     4,     4,     4,     6,     7,
       4,     4,     4,    58,     4,   990,     4,    64,   103,   656,
       6,     4,   200,   201,     4,    65,  1112,    67,    68,  1004,
      75,   121,    77,   108,    79,     4,    81,     6,     7,  1315,
      91,   600,   138,  1000,    12,   130,   103,   107,   656,   536,
    1136,   137,   103,   113,  1029,   151,   693,   117,     0,   119,
      65,   147,    67,    68,   121,    14,   129,  1343,  1025,   132,
     189,   131,   191,   130,   193,   180,  1051,    55,   637,   130,
    1166,   141,   157,   143,    15,   693,   131,    70,    36,   149,
      43,    44,   163,    57,   184,    61,    49,    50,    60,   170,
     147,  1076,   187,    59,    84,    53,    91,   167,    98,  1195,
      96,   129,   152,   600,   132,   100,   161,   129,   106,    56,
     132,   120,   114,    92,   122,   118,   120,   129,    26,   134,
     132,  1217,     3,    95,  1109,    97,    62,   144,    58,   140,
     146,   150,   142,    69,    69,   782,   156,  1000,    63,   162,
     637,   166,   271,   172,   168,   333,   164,   154,  1133,  1245,
     495,   194,   195,   196,   197,   500,   188,   188,   273,   131,
     505,    95,    65,    97,    67,    68,     3,   355,   916,   105,
     105,  1267,    65,   145,    67,    68,    60,    17,  1163,   367,
     368,   369,   370,    23,   407,    10,   409,  1283,   411,    29,
      10,    11,    10,   165,    34,   131,   131,   131,   154,   171,
      10,   157,  1298,   139,   139,    10,    75,  1192,    77,     6,
      79,   145,    81,   133,   711,   403,   136,   153,   153,   155,
     155,   120,    18,   184,  1320,  1210,   187,    10,    11,  1214,
     144,   165,   142,   169,   169,    10,    11,   171,  1334,   175,
     175,   177,   177,   179,   179,   181,   181,    43,    44,    10,
      11,   114,  1348,   441,  1239,    51,    52,  1242,   118,   107,
     150,    16,   131,   168,    19,   113,  1362,    10,    11,   117,
       6,   119,    43,    44,    45,    46,  1261,    62,   407,  1264,
     409,    19,   411,   131,    22,  1381,    31,   162,    43,    44,
      45,    46,   161,   141,     3,   143,    51,    52,    43,    44,
      32,   149,    47,    48,     6,    43,    44,    45,    46,   108,
    1295,  1407,   157,    51,    52,   132,    19,    43,    44,   167,
     129,    47,    48,    10,    10,    11,    10,  1423,    10,   458,
      33,    10,    11,    10,   463,    10,    11,   172,  1434,    98,
      43,    44,    45,    46,    10,    11,  1331,    21,    51,    52,
      10,    11,    10,    11,  1450,    41,    42,    43,    44,    10,
      11,    47,    48,    49,    50,  1461,    96,    41,    42,    43,
      44,    45,    46,   166,  1359,    43,    44,    45,    46,   567,
     568,   569,   570,    51,    52,    10,    11,    80,   576,    10,
      11,    43,    44,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,   146,   629,   536,    10,    11,
      10,    11,    10,    11,    10,    11,    78,   986,    82,   916,
      76,   609,   132,   611,   612,    10,    11,    10,    11,   617,
     129,  1000,    10,    11,    10,    11,    10,    11,     6,     7,
      10,    11,    64,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,   156,  1025,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,     6,
     658,   600,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    70,   986,
      10,    11,    10,    11,   682,   186,   187,    10,    11,     6,
     629,    10,    11,  1000,    10,    11,    10,    11,   637,   154,
     698,    10,    11,    10,    11,    10,    11,   705,    10,    11,
      10,    11,     6,     7,    10,    11,     6,   656,  1025,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,   140,   734,    10,    11,    10,
      11,    10,    11,    10,    11,   743,    10,    11,    10,    11,
      10,    11,    38,    39,   693,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,     6,     6,   106,     6,   129,
     132,   769,   711,   158,     3,     3,   130,    10,    30,   170,
     163,   180,   182,   132,   178,   130,   176,   153,   129,   787,
       3,     6,   119,   791,     6,   130,     3,   130,   123,   151,
     189,   138,   800,    28,    25,    93,   164,   120,     5,   135,
       6,   154,     6,    24,     6,   183,   814,    27,    66,   148,
     152,   185,     6,    99,    33,   823,   157,   183,    87,   124,
      87,  1210,    22,     6,   158,   833,    94,    87,    16,   190,
       6,    85,     6,   782,   136,   843,    85,   129,    37,   133,
      85,   129,     6,    71,   129,   853,    88,  1012,    18,    10,
    1239,    37,   184,    71,   184,   121,   187,    37,    88,   867,
      71,   186,    88,   100,    91,   187,    37,    10,    73,     6,
      73,   879,  1261,     5,    10,    73,     6,     6,   134,   115,
       6,   115,    83,   115,    66,   188,     6,    37,   121,   130,
     103,     6,    40,    86,   103,   159,    37,   905,   122,    86,
      91,   130,    37,   187,   101,    86,   159,   103,   188,    72,
      72,     6,   159,    92,   130,    72,    74,     6,   173,    10,
       6,   173,    74,     6,    84,    74,   104,   173,   936,     6,
     122,   116,   104,    92,   102,   104,     6,     6,    44,   116,
     359,   116,    80,   451,   188,   160,   160,   102,   160,   525,
     594,   959,   580,  1118,   345,   467,   693,   752,   909,   953,
     250,  1155,  1158,   940,   174,  1124,   174,   916,   982,  1127,
     978,  1184,  1187,   871,  1019,   686,   760,   167,  1025,   174,
     916,   986,    -1,   991,    -1,    -1,    -1,    -1,    -1,   997,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1009,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1035,    -1,    -1,
      -1,    -1,    -1,    -1,  1042,    -1,    -1,   986,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1000,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1025,    -1,    -1,    -1,
      -1,    -1,  1090,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1141,    -1,    -1,    -1,    -1,    -1,  1147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1202,    -1,    -1,    -1,  1206,    -1,
      -1,    -1,    -1,  1211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1389,    -1,    -1,    -1,    -1,  1394,  1395,    -1,    -1,
      -1,  1399,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1415,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1473,  1474
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,   199,   200,     0,    14,   201,    10,    11,   202,
     203,   204,    55,   205,   206,   207,    15,    57,   286,   287,
      10,    11,   208,   209,   210,    59,   340,   341,    10,    11,
     288,   289,   290,    56,   107,   113,   117,   119,   131,   141,
     143,   149,   167,   211,   212,   213,   214,   215,   230,   231,
     236,   237,   242,   243,   248,   249,   254,   255,   260,   261,
     266,   267,   272,   273,    61,   392,   393,    10,    11,   342,
     343,   344,    58,    75,    77,    79,    81,   131,   161,   291,
     292,   293,   294,   295,   300,   301,   307,   308,   314,   315,
     321,   322,   326,   327,    56,   213,    31,    43,    44,    47,
      48,   216,   217,   218,   878,   879,   880,   881,   886,   887,
     888,   889,   912,    10,    11,   232,   233,   234,    10,    11,
     238,   239,   240,    10,    11,   244,   245,   246,    10,    11,
     250,   251,   252,    10,    11,   256,   257,   258,    10,    11,
     262,   263,   264,    10,    11,   268,   269,   270,    26,   274,
     907,    63,   487,   488,    10,    11,   394,   395,   396,    60,
      95,    97,   131,   145,   165,   171,   345,   346,   347,   348,
     349,   354,   355,   360,   361,   366,   367,   372,   373,   378,
     379,    58,   293,    10,    11,   296,   297,   298,   302,   303,
     309,   310,   316,   317,   323,   878,   328,   907,   933,   934,
       3,     3,    10,    11,   219,   220,   221,   218,     4,   120,
     235,     4,   144,   241,     4,   142,   247,     4,   114,   253,
       4,   118,   259,     4,   150,   265,     4,   168,   271,   933,
      10,    11,   275,   276,   277,   489,   490,    62,    69,   105,
     131,   139,   153,   155,   169,   175,   177,   179,   181,   397,
     398,   399,   400,   401,   406,   407,   412,   413,   418,   419,
     424,   425,   430,   431,   447,   448,   454,   455,   461,   462,
     468,   469,   473,   474,    60,   347,    10,    11,   350,   351,
     352,    10,    11,   356,   357,   358,    10,    11,   362,   363,
     364,    10,    11,   368,   369,   370,    10,    11,   374,   375,
     376,   380,   907,     4,   162,   299,    10,   305,    49,    50,
     304,   878,   890,   891,   892,   893,    10,   312,   311,   878,
     890,    10,   319,   318,   878,   890,    10,   324,    10,    11,
     329,   330,   331,     6,     8,   194,   195,   196,   197,   935,
     933,   933,   108,   157,   222,   223,   224,   225,   120,   144,
     142,   114,   118,   150,   168,     6,   129,   132,   278,   279,
     280,   281,    10,    11,   492,   493,   494,    17,    23,    29,
      34,   491,   899,   904,   910,   915,    62,   399,    10,    11,
     402,   403,   404,    10,    11,   408,   409,   410,    10,    11,
     414,   415,   416,    10,    11,   420,   421,   422,    10,    11,
     426,   427,   428,    32,   432,   913,   449,   450,   456,   457,
     463,   464,   470,   878,   475,   907,     4,    98,   353,     6,
      96,   359,     6,   172,   365,     4,   166,   371,     6,     7,
     146,   377,   931,    10,    11,   381,   382,   383,   162,   306,
     931,     3,   313,   931,   320,   931,     6,   325,   129,   132,
     332,   333,   334,   335,   933,   108,   224,   226,   227,   933,
     132,   280,   282,   283,    64,   147,   495,   496,   497,   498,
     933,   933,   933,   933,     4,   154,   405,     4,   156,   411,
       4,   140,   417,     4,    70,   423,     4,   106,   429,   933,
      10,    11,   433,   434,   435,    10,   452,   451,   878,   890,
      10,   459,   458,   878,   890,    10,   466,   465,   878,   890,
      10,   471,    10,    11,   476,   477,   478,    98,    96,   172,
     166,   146,   129,   132,   384,   385,   386,   387,    80,   933,
      82,    78,    76,   132,   334,   336,   337,    10,    11,   229,
      45,    46,   228,   878,   882,   883,   884,   885,    10,    11,
     285,    51,    52,   284,   878,   882,   894,   895,   896,   897,
      64,   137,   497,   851,   852,   499,   500,     6,     6,     6,
       6,   154,   156,   140,    70,   106,     6,   163,   170,   436,
     437,   438,   439,   453,   931,   460,   931,   467,   931,     6,
     472,   129,   132,   479,   480,   481,   482,   132,   386,   388,
     389,    10,    11,   339,   338,   878,   882,   894,   158,     3,
     130,     3,    30,   853,   911,    10,   504,    36,    53,   501,
     502,   503,   933,   933,   933,   933,   933,   170,   438,   440,
     180,   182,   178,   176,   132,   481,   483,   484,    10,    11,
     391,   390,   878,   882,   894,   130,   933,   933,   933,    10,
      11,   854,   855,   856,   153,   505,   506,   933,     3,    10,
      11,    41,    42,   441,   442,   443,   444,   874,   875,   876,
     877,   878,   886,   890,    10,    11,   486,   485,   878,   882,
     894,   130,     6,   138,   151,   857,   858,   859,   860,   119,
     521,   522,   507,   508,   509,   878,   886,   912,     6,   933,
       6,     7,   164,   445,   446,     3,   130,   933,   138,   859,
     861,   862,   189,   527,   528,    10,    11,   523,   524,   525,
      10,    11,   510,   511,   512,   509,   933,   164,   933,    10,
      11,   864,   865,   866,    21,   863,   874,   878,   882,   902,
     123,   637,   638,    28,   529,   909,     4,   120,   526,   154,
     157,   513,   514,   515,   516,    65,    67,    68,   152,   867,
     868,   869,   870,   871,   872,   933,    93,   733,   734,    25,
     639,   906,   933,    10,    11,   530,   531,   532,   120,   154,
     515,   517,   518,     5,   873,   152,   869,     6,   135,   828,
     829,    24,   735,   905,   933,    10,    11,   640,   641,   642,
       6,   183,   533,   534,   535,    10,    11,   520,   519,   878,
     886,    66,   933,   148,    27,   830,   908,   933,    10,    11,
     736,   737,   738,     6,   183,   643,   644,   645,   933,   190,
     185,   546,   547,    33,   536,   914,   158,   933,    10,    11,
     831,   832,   833,     6,    99,   739,   740,   741,   933,   124,
      87,   657,   658,    22,   646,   903,    87,   561,   562,   548,
     914,   933,    10,    11,   537,   538,   539,     6,   133,   136,
     834,   835,   836,   837,   933,    94,    87,   752,   753,    16,
     742,   898,   705,    10,    11,   659,   660,   661,   933,    10,
      11,   647,   648,   649,   609,    10,    11,   563,   564,   565,
      10,    11,   549,   550,   551,     6,   184,   187,   540,   541,
     542,   543,   933,   136,   836,   838,   839,   800,    10,    11,
     754,   755,   756,   933,    10,    11,   743,   744,   745,   129,
     706,   707,    85,   662,   663,   664,     6,   121,   184,   650,
     651,   652,   653,   129,   610,   611,    85,   566,   567,   568,
     186,   187,   552,   553,   554,   555,   933,   184,   542,    37,
     544,    10,    11,   841,   842,   843,   840,   874,   878,   882,
     902,   129,   801,   802,    85,   757,   758,   759,     6,    91,
     100,   746,   747,   748,   749,   708,   709,    88,    71,   670,
     671,    18,   665,   900,   933,   184,   652,    37,   654,   612,
     613,    88,    71,   574,   575,   569,   900,   186,   554,    37,
     556,   933,    10,   545,    65,    67,    68,   134,   844,   845,
     846,   847,   848,   849,   803,   804,    88,    71,   765,   766,
     760,   900,   933,   100,   748,    37,   750,    10,    11,   711,
     712,   713,    19,   710,   878,   882,   894,   901,   903,    73,
     677,   678,   672,   900,   933,    10,    11,   666,   667,   668,
     933,    10,   655,    10,    11,   615,   616,   617,   614,   878,
     882,   894,   901,   914,    73,   581,   582,   576,   900,    10,
      11,   570,   571,   572,   933,    10,    11,   557,   558,   559,
       6,   931,     5,   850,   134,   846,    10,    11,   806,   807,
     808,   805,   878,   882,   894,   898,   901,    73,   772,   773,
     767,   900,    10,    11,   761,   762,   763,   933,    10,   751,
     103,   121,   130,   714,   715,   716,   717,   723,   724,   725,
     933,   115,   684,   685,   679,   900,    10,    11,   673,   674,
     675,     6,    83,   669,   916,   917,   924,     6,     6,     7,
     656,   103,   130,   187,   618,   619,   620,   621,   627,   628,
     629,   115,   588,   589,   583,   900,    10,    11,   577,   578,
     579,   573,   916,     6,     4,   188,   560,   933,   188,    66,
      91,   103,   130,   809,   810,   811,   812,   818,   819,   820,
     115,   779,   780,   774,   900,    10,    11,   768,   769,   770,
     764,   916,     6,   931,   130,   716,    37,   718,   724,   726,
     727,     6,   159,   691,   692,   686,   900,    10,    11,   680,
     681,   682,   676,   916,   933,    40,   925,    86,   101,   918,
     919,   933,   122,   130,   620,    37,   622,   628,   630,   631,
     159,   595,   596,   590,   900,    10,    11,   584,   585,   586,
     580,   916,    86,   933,   188,   130,   811,    37,   813,   819,
     821,   822,   159,   786,   787,   781,   900,    10,    11,   775,
     776,   777,   771,   916,    86,   933,    92,   933,    10,    11,
     719,   720,   721,    10,    11,   729,   730,   731,   728,   878,
     894,   900,   933,   173,   698,   699,   693,   900,    10,    11,
     687,   688,   689,   683,   916,    72,   933,    10,    11,   926,
     927,   928,   920,   921,   933,    10,    11,   623,   624,   625,
      10,    11,   633,   634,   635,   632,   878,   894,   900,   173,
     602,   603,   597,   900,    10,    11,   591,   592,   593,   587,
     916,    72,   933,    10,    11,   814,   815,   816,    10,    11,
     824,   825,   826,   823,   878,   894,   900,   173,   793,   794,
     788,   900,    10,    11,   782,   783,   784,   778,   916,    72,
       6,     4,     6,     7,   122,   722,   932,   732,   916,   700,
     900,    10,    11,   694,   695,   696,   690,   916,    74,     6,
       4,    84,    10,   923,    38,    39,   922,   929,   930,     6,
     188,   626,   932,   636,   916,   604,   900,    10,    11,   598,
     599,   600,   594,   916,    74,     6,    92,   817,   932,   827,
     916,   795,   900,    10,    11,   789,   790,   791,   785,   916,
      74,   933,   122,   104,    10,    11,   701,   702,   703,   697,
     916,   116,   933,    84,     6,   933,   933,   933,   188,   104,
      10,    11,   605,   606,   607,   601,   916,   116,   933,    92,
     104,    10,    11,   796,   797,   798,   792,   916,   116,   704,
     916,   160,   102,     6,     6,   608,   916,   160,   799,   916,
     160,   174,   933,   933,   174,   174
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
      yyerror (&yylloc, osresult, parserData, osglData, YY_("syntax error: cannot back up")); \
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
		  Type, Value, Location, osresult, parserData, osglData); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData, osglData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osresult);
  YYUSE (parserData);
  YYUSE (osglData);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData, osglData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData, osglData);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osresult, parserData, osglData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osresult, parserData, osglData);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osresult, parserData, osglData); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osresult, parserData, osglData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osresult);
  YYUSE (parserData);
  YYUSE (osglData);

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
int yyparse (OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData);
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
yyparse (OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData)
#else
int
yyparse (osresult, parserData, osglData)
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
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
        case 3:

    {
#ifdef DEBUG
yydebug = 1;
#endif
;}
    break;

  case 32:

    {	if (parserData->generalStatusPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one generalStatus element allowed");	
		if (osresult->general->generalStatus != NULL) 
			osrlerror(NULL, NULL, parserData, osglData, "generalStatus previously allocated");
		parserData->generalStatusPresent = true;
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
		parserData->typeAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 33:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	;}
    break;

  case 36:

    { 
		if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "general status type does not match any legal value");
	;}
    break;

  case 37:

    {   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	;}
    break;

  case 38:

    {   if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate substatus array. Potential loss of data.");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	;}
    break;

  case 39:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	;}
    break;

  case 40:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	;}
    break;

  case 47:

    {	parserData->kounter++;
;}
    break;

  case 48:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 49:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have name attribute");
;}
    break;

  case 52:

    {	
		if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus name");
	;}
    break;

  case 53:

    {	
		if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus description");
	;}
    break;

  case 57:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 63:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 65:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 71:

    {osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 73:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 79:

    {osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 81:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 87:

    {osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 89:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 95:

    {osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 97:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 103:

    {osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 105:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 111:

    {osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 113:

    {	if (parserData->generalOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one general other results element allowed");
		parserData->generalOtherResultsPresent = true;
	;}
    break;

  case 114:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other general results cannot be negative");
	if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate other general results array. Potential loss of data.");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 115:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 116:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 123:

    {	parserData->kounter++;
;}
    break;

  case 124:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 125:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 128:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultName failed");
	;}
    break;

  case 129:

    {	
		if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultValue failed");
	;}
    break;

  case 130:

    {	
		if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultDescription failed");
	;}
    break;

  case 151:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 157:

    {	osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	;}
    break;

  case 159:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 163:

    {
		if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 164:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 166:

    {	osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 168:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 172:

    {
		if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 173:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 175:

    {	osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
;}
    break;

  case 177:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 181:

    {
		if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "available CPU Speed could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 182:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 184:

    {	osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
;}
    break;

  case 186:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 188:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 190:

    {	osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; ;}
    break;

  case 192:

    {	if (parserData->systemOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one system other results element allowed");
		parserData->systemOtherResultsPresent = true;
	;}
    break;

  case 193:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other system results cannot be negative");
	if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSystemResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 194:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 195:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 202:

    {	parserData->kounter++;
;}
    break;

  case 203:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 204:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 207:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultName failed");
	;}
    break;

  case 208:

    {	
		if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultValue failed");
	;}
    break;

  case 209:

    {	
		if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultDescription failed");
	;}
    break;

  case 230:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 236:

    {   parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setCurrentState(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setCurrentState failed; current system state not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 238:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 244:

    { osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 246:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 252:

    { osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 254:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 260:

    {osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 262:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 268:

    {	if (osresult->setServiceUtilization( parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setServiceUtilization failed");
	parserData->errorText = NULL;
;}
    break;

  case 270:

    {	if (parserData->serviceOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one service other results element allowed");
		parserData->serviceOtherResultsPresent = true;
	;}
    break;

  case 271:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other service results cannot be negative");
	if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherServiceResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 272:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 273:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 280:

    {	parserData->kounter++;
;}
    break;

  case 281:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 282:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 285:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultName failed");
	;}
    break;

  case 286:

    {	
		if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultValue failed");
	;}
    break;

  case 287:

    {	
		if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultDescription failed");
	;}
    break;

  case 313:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 319:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setJobStatus(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobStatus failed");
		parserData->errorText = NULL;
	;}
    break;

  case 321:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 327:

    {osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 329:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 335:

    {osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 337:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 343:

    {osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 345:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 351:

    {osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 353:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 354:

    {	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of time measurements cannot be negative");
	if (osresult->setNumberOfTimes(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfTimes failed");
	parserData->numberOfTimes = parserData->tempInt;
	parserData->ivar = 0;
;}
    break;

  case 355:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <time> element");
	;}
    break;

  case 356:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <time> elements than specified");
	;}
    break;

  case 364:

    {	if (parserData->ivar >= parserData->numberOfTimes)
		osrlerror(NULL, NULL, parserData, osglData, "more <time> elements than specified");
	parserData->unitAttributePresent = false;
	parserData->typeAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->unitAttribute = "second";
	parserData->typeAttribute = "elapsedTime";
	parserData->categoryAttribute = "total";
	parserData->descriptionAttribute = "";
;}
    break;

  case 376:

    {	
	if (osresult->setTimingInformation(parserData->ivar, parserData->typeAttribute, parserData->categoryAttribute,
		parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue) == false)       
			osrlerror(NULL, NULL, parserData, osglData, "timing information could not be stored");
	parserData->ivar++;
//	parserData->timeType = "elapsedTime";
//	parserData->timeCategory = "total";
//	parserData->timeUnit = "unit";
//	parserData->timeDescription = "";      
;}
    break;

  case 377:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 378:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 380:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 384:

    {
		if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 385:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 387:

    {	osresult->setUsedDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 389:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 393:

    {
		if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "usedMemory unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 394:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 396:

    {	osresult->setUsedMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 398:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 402:

    {
		if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableCPUSpeed unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 403:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 405:

    {	osresult->setUsedCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 407:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 409:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 411:

    { osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; ;}
    break;

  case 413:

    {	if (parserData->jobOtherResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job other results element allowed");
		parserData->jobOtherResultsPresent = true;
	;}
    break;

  case 414:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other job results cannot be negative");
	if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherJobResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 415:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 416:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 423:

    {	parserData->kounter++;
;}
    break;

  case 424:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 425:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 428:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultName failed");
	;}
    break;

  case 429:

    {	
		if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultValue failed");
	;}
    break;

  case 430:

    {	
		if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultDescription failed");
	;}
    break;

  case 435:

    {	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
;}
    break;

  case 436:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "numberOfSolutions was never set");
;}
    break;

  case 439:

    {
		parserData->numberOfSolutions = parserData->tempInt; 
		if (osresult->setSolutionNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionNumber failed");
		parserData->solutionIdx = 0;
	;}
    break;

  case 440:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osresult->setVariableNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVariableNumber failed");
	;}
    break;

  case 441:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osresult->setConstraintNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setConstraintNumber failed");
	;}
    break;

  case 442:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osresult->setObjectiveNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjectiveNumber failed");
	;}
    break;

  case 443:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solution> element");
	;}
    break;

  case 444:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solution> elements than specified");
	;}
    break;

  case 452:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 458:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, "target objective index must be negative");
  	if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveIdx failed");
 ;}
    break;

  case 459:

    {	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
	parserData->weightedObjAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
	if (parserData->tempStr == "true")
	{  	if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, true) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionWeightedObjectives failed");
	}
	else if (parserData->tempStr == "false")
	{  	if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, false) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionWeightedObjectives failed");
	}
	else
		osrlerror(NULL, NULL, parserData, osglData, "weightedobjectives must be true or false");
;}
    break;

  case 460:

    {
		parserData->solutionIdx++;
	;}
    break;

  case 462:

    {
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
		parserData->typeAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 463:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for solution status element");
	;}
    break;

  case 466:

    {   
		if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusType failed");
	;}
    break;

  case 467:

    {   if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusDescription failed");
	;}
    break;

  case 468:

    {	if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolutionSubstatuses failed");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	;}
    break;

  case 469:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	;}
    break;

  case 470:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	;}
    break;

  case 477:

    {	parserData->kounter++; ;}
    break;

  case 478:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->typeAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 479:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have type attribute");
;}
    break;

  case 482:

    {	
		if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
											   parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusType failed");
	;}
    break;

  case 483:

    {	
		if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
													  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusDescription failed");
	;}
    break;

  case 494:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
		osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
		parserData->errorText = NULL;
	;}
    break;

  case 497:

    {	parserData->numberOfOtherVariableResults = 0; ;}
    break;

  case 499:

    {	
	if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, 
												  parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableResults failed");
	parserData->numberOfOtherVariableResults = parserData->tempInt;
	parserData->iOther = 0;
;}
    break;

  case 508:

    {
	if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValues failed");
	parserData->kounter = 0;
;}
    break;

  case 509:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 510:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 517:

    {	if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValue failed");
	parserData->kounter++;
;}
    break;

  case 518:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
;}
    break;

  case 519:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 524:

    {
	if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
	parserData->kounter = 0;
;}
    break;

  case 525:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 526:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 533:

    {
	if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 				parserData->idx,         parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValueString failed");
	parserData->kounter++;
;}
    break;

  case 534:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
;}
    break;

  case 535:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 536:

    {parserData->tempStr = "";;}
    break;

  case 541:

    {parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));;}
    break;

  case 551:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'v', ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 553:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 560:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'v', ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 562:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 569:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'v', ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 571:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 578:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'v', ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 580:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 587:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'v', ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 589:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 596:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'v', ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 598:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 606:

    { 	 
		parserData->iOther++;
	;}
    break;

  case 607:

    {
	if (parserData->iOther >= parserData->numberOfOtherVariableResults)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherVariableResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberOfVarAttributePresent = false;	
	parserData->numberOfEnumerationsAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";	
;}
    break;

  case 608:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfVar attribute"); 
	;}
    break;

  case 611:

    {	if (parserData->numberOfVarAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfVar attribute previously set");
		parserData->numberOfVarAttributePresent = true;
	 	if (osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfVar) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultNumberOfVar failed");
		parserData->kounter = 0;
	;}
    break;

  case 612:

    {	if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherVariableResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	;}
    break;

  case 613:

    {	
	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 												  parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 614:

    {	
	 	if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    ;}
    break;

  case 615:

    {	
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 625:

    { 	
	parserData->kounter++;
;}
    break;

  case 627:

    {	
 	if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 											   parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
;}
    break;

  case 633:

    {	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
	;}
    break;

  case 636:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, 'v', parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other variable option failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
;}
    break;

  case 637:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 638:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfVarIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfVarIdx attribute"); 
	;}
    break;

  case 641:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 642:

    {	
//	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 643:

    {	
//	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 651:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 653:

    {
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
    if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, 
												   parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
;}
    break;

  case 662:

    {
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
;}
    break;

  case 663:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	;}
    break;

  case 664:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	;}
    break;

  case 671:

    {	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
	parserData->kounter++;
;}
    break;

  case 672:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idx = -1;
;}
    break;

  case 674:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 676:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 677:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 687:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'o', ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 689:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 696:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'o', ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 698:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 705:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'o', ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 707:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 714:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'o', ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 716:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 723:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'o', ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 725:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 732:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'o', ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 734:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 742:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 743:

    {
	if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherObjectiveResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberOfObjAttributePresent = false;	
	parserData->numberOfEnumerationsAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 744:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfObj attribute"); 
	;}
    break;

  case 747:

    {	if (parserData->numberOfObjAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfObj attribute previously set");
		parserData->numberOfObjAttributePresent = true;
 		if (osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, 
 						                                 parserData->iOther, 
 						                                 parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultNumberOfObj failed");
		parserData->kounter = 0;
	;}
    break;

  case 748:

    {	if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherObjectiveResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	;}
    break;

  case 749:

    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 750:

    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    ;}
    break;

  case 751:

    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 761:

    {  
	parserData->kounter++;
;}
    break;

  case 763:

    {	if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
;}
    break;

  case 769:

    {	if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
	;}
    break;

  case 772:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, 'o', parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other objective option failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
;}
    break;

  case 773:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 774:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfObjIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfObjIdx attribute"); 
	;}
    break;

  case 777:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 778:

    {	
//	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 779:

    {	
//	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 787:

    {	parserData->numberOfOtherConstraintResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 789:

    {
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
;}
    break;

  case 797:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 798:

    {
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
;}
    break;

  case 799:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	;}
    break;

  case 800:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	;}
    break;

  case 807:

    {	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
	parserData->kounter++;
;}
    break;

  case 808:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
;}
    break;

  case 809:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 820:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'c', ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 822:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 829:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'c', ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 831:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 838:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'c', ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 840:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 847:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'c', ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 849:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 856:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'c', ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 858:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 865:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, 'c', ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 867:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 875:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 876:

    {
	if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherConstraintResults> than specified");
	parserData->nameAttributePresent = false;	
	parserData->numberOfConAttributePresent = false;	
	parserData->numberOfEnumerationsAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->descriptionAttributePresent = false;	
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 877:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfCon attribute"); 
	;}
    break;

  case 880:

    {	if (parserData->numberOfConAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfCon attribute previously set");
		parserData->numberOfConAttributePresent = true;
 		if (osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, 
 							                              parserData->iOther, 
 							                              parserData->numberOfCon) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultNumberOfCon failed");
		parserData->kounter = 0;
	;}
    break;

  case 881:

    {	if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherConstraintResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	;}
    break;

  case 882:

    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 883:

    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    ;}
    break;

  case 884:

    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 894:

    { 	
	parserData->kounter++;
;}
    break;

  case 896:

    {	
 	if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
;}
    break;

  case 902:

    {	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
	;}
    break;

  case 905:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, 'c', parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other constraint option failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
;}
    break;

  case 906:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 907:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfConIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfConIdx attribute"); 
	;}
    break;

  case 910:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 911:

    {	
//	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 912:

    {	
//	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 920:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 921:

    {	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 922:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
	;}
    break;

  case 923:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
	;}
    break;

  case 930:

    {	parserData->iOther++;
;}
    break;

  case 931:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 932:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
;}
    break;

  case 935:

    {	
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
	;}
    break;

  case 936:

    {	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
	;}
    break;

  case 937:

    {	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
	;}
    break;

  case 938:

    {	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 939:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 940:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 947:

    {	parserData->kounter++;
;}
    break;

  case 948:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 953:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
											 parserData->kounter, parserData->itemContent) 
											     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultItem failed");
;}
    break;

  case 956:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 957:

    {	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 958:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
	;}
    break;

  case 959:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
	;}
    break;

  case 966:

    {	parserData->iOther++;
;}
    break;

  case 967:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <solverOutput> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 968:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
;}
    break;

  case 971:

    {	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
	;}
    break;

  case 972:

    {	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
	;}
    break;

  case 973:

    {	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
	;}
    break;

  case 974:

    {	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 975:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 976:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 983:

    {	parserData->kounter++;
;}
    break;

  case 984:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 989:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
;}
    break;

  case 990:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 993:

    { parserData->categoryAttribute = ""; ;}
    break;

  case 994:

    { parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 995:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 998:

    { parserData->descriptionAttribute = ""; ;}
    break;

  case 999:

    { parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1000:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 1003:

    { parserData->nameAttribute = ""; ;}
    break;

  case 1004:

    { parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1005:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 1008:

    { parserData->typeAttribute = ""; ;}
    break;

  case 1009:

    { parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1010:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 1013:

    { parserData->unitAttribute = ""; ;}
    break;

  case 1014:

    { parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1015:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 1018:

    { parserData->valueAttribute = ""; ;}
    break;

  case 1019:

    { parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1020:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1021:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1022:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1023:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1024:

    {	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1025:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1026:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1027:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1028:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1029:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1030:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1031:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1032:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1033:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1034:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1035:

    {
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1036:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1037:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1038:

    {
	 	if (osglData->osglCounter + osglData->osglMult < osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	;}
    break;

  case 1043:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
;}
    break;

  case 1049:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
;}
    break;

  case 1051:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1056:

    {
	char* b64string = (yyvsp[(2) - (3)].sval);
	if( b64string == NULL) 
		osrlerror(NULL, NULL, parserData, osglData, "base 64 data expected"); 
	if (osglData->osglSize != sizeof(int))
		osrlerror(NULL, NULL, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

	std::string base64decodeddata = Base64::decodeb64( b64string );
	int base64decodeddatalength = base64decodeddata.length();
	int *intvec = NULL;
	osglData->osglIntArray = new int[(base64decodeddatalength/osglData->osglSize) ];
	intvec = (int*)&base64decodeddata[0];
	for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
	{
		osglData->osglIntArray[i] = *(intvec++);
	}
	delete [] b64string;
;}
    break;

  case 1057:

    {	
	if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1058:

    {	
	if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1059:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 1060:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 1061:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 1062:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 1063:

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
      yyerror (&yylloc, osresult, parserData, osglData, YY_("syntax error"));
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
	    yyerror (&yylloc, osresult, parserData, osglData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osresult, parserData, osglData, YY_("syntax error"));
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
		      yytoken, &yylval, &yylloc, osresult, parserData, osglData);
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
		  yystos[yystate], yyvsp, yylsp, osresult, parserData, osglData);
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
  yyerror (&yylloc, osresult, parserData, osglData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osresult, parserData, osglData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osresult, parserData, osglData);
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





void osrlerror(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
	osrl_empty_vectors( parserData);
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "Input is either not valid or well formed: "  + error;
	outStr << error << std::endl;
	outStr << "Error occurred when reading: " << osrlget_text ( scanner ) << std::endl; 
	outStr << "See line number: " << osrlget_lineno( scanner) << std::endl; 
	error = outStr.str();
	//printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
	//if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
	//osrllex_destroy( scanner);
	throw ErrorClass( error);
} //end osrlerror

void  yygetOSResult(const char *parsestring, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData) throw(ErrorClass){
	try{
		osrl_scan_string( parsestring, scanner);
		osrlset_lineno (1 , scanner );
		//
		// call the Bison parser
		//
		if(  osrlparse( osresult,  parserData, osglData) != 0) {
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

void osgl_empty_vectors( OSgLParserData* osglData){
	if (osglData->osglIntArray != NULL)
		delete[] osglData->osglIntArray;
}//end osgl_empty_vectors

