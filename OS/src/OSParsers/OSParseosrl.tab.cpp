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
     HEADERSTART = 310,
     HEADEREND = 311,
     GENERALSTART = 312,
     GENERALEND = 313,
     SYSTEMSTART = 314,
     SYSTEMEND = 315,
     SERVICESTART = 316,
     SERVICEEND = 317,
     JOBSTART = 318,
     JOBEND = 319,
     OPTIMIZATIONSTART = 320,
     OPTIMIZATIONEND = 321,
     ITEMSTART = 322,
     ITEMEND = 323,
     ITEMSTARTANDEND = 324,
     ITEMEMPTY = 325,
     FILENAMESTART = 326,
     FILENAMEEND = 327,
     FILENAMEEMPTY = 328,
     FILENAMESTARTANDEND = 329,
     FILESOURCESTART = 330,
     FILESOURCEEND = 331,
     FILESOURCEEMPTY = 332,
     FILESOURCESTARTANDEND = 333,
     FILEDESCRIPTIONSTART = 334,
     FILEDESCRIPTIONEND = 335,
     FILEDESCRIPTIONEMPTY = 336,
     FILEDESCRIPTIONSTARTANDEND = 337,
     FILECREATORSTART = 338,
     FILECREATOREND = 339,
     FILECREATOREMPTY = 340,
     FILECREATORSTARTANDEND = 341,
     FILELICENCESTART = 342,
     FILELICENCEEND = 343,
     FILELICENCEEMPTY = 344,
     FILELICENCESTARTANDEND = 345,
     ACTUALSTARTTIMESTART = 346,
     ACTUALSTARTTIMEEND = 347,
     ATLOWERSTART = 348,
     ATLOWEREND = 349,
     ATUPPERSTART = 350,
     ATUPPEREND = 351,
     AVAILABLECPUNUMBERSTART = 352,
     AVAILABLECPUNUMBEREND = 353,
     AVAILABLECPUSPEEDSTART = 354,
     AVAILABLECPUSPEEDEND = 355,
     AVAILABLEDISKSPACESTART = 356,
     AVAILABLEDISKSPACEEND = 357,
     AVAILABLEMEMORYSTART = 358,
     AVAILABLEMEMORYEND = 359,
     BASE64START = 360,
     BASE64END = 361,
     BASICSTART = 362,
     BASICEND = 363,
     BASISSTATUSSTART = 364,
     BASISSTATUSEND = 365,
     BASSTATUSSTART = 366,
     BASSTATUSEND = 367,
     CONSTART = 368,
     CONEND = 369,
     CONSTRAINTSSTART = 370,
     CONSTRAINTSEND = 371,
     CURRENTJOBCOUNTSTART = 372,
     CURRENTJOBCOUNTEND = 373,
     CURRENTSTATESTART = 374,
     CURRENTSTATEEND = 375,
     DUALVALUESSTART = 376,
     DUALVALUESEND = 377,
     ELSTART = 378,
     ELEND = 379,
     ENUMERATIONSTART = 380,
     ENUMERATIONEND = 381,
     ENDTIMESTART = 382,
     ENDTIMEEND = 383,
     GENERALSTATUSSTART = 384,
     GENERALSTATUSEND = 385,
     GENERALSUBSTATUSSTART = 386,
     GENERALSUBSTATUSEND = 387,
     IDXSTART = 388,
     IDXEND = 389,
     INSTANCENAMESTART = 390,
     INSTANCENAMEEND = 391,
     ISFREESTART = 392,
     ISFREEEND = 393,
     JOBIDSTART = 394,
     JOBIDEND = 395,
     MESSAGESTART = 396,
     MESSAGEEND = 397,
     OBJSTART = 398,
     OBJEND = 399,
     OBJECTIVESSTART = 400,
     OBJECTIVESEND = 401,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 402,
     OPTIMIZATIONSOLUTIONSTATUSEND = 403,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 404,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 405,
     OTHERSTART = 406,
     OTHEREND = 407,
     OTHERRESULTSSTART = 408,
     OTHERRESULTSEND = 409,
     OTHERSOLUTIONRESULTSTART = 410,
     OTHERSOLUTIONRESULTEND = 411,
     OTHERSOLUTIONRESULTSSTART = 412,
     OTHERSOLUTIONRESULTSEND = 413,
     OTHERSOLVEROUTPUTSTART = 414,
     OTHERSOLVEROUTPUTEND = 415,
     SCHEDULEDSTARTTIMESTART = 416,
     SCHEDULEDSTARTTIMEEND = 417,
     SERVICENAMESTART = 418,
     SERVICENAMEEND = 419,
     SERVICEURISTART = 420,
     SERVICEURIEND = 421,
     SERVICEUTILIZATIONSTART = 422,
     SERVICEUTILIZATIONEND = 423,
     SOLUTIONSTART = 424,
     SOLUTIONEND = 425,
     SOLVERINVOKEDSTART = 426,
     SOLVERINVOKEDEND = 427,
     SOLVEROUTPUTSTART = 428,
     SOLVEROUTPUTEND = 429,
     STATUSSTART = 430,
     STATUSEND = 431,
     SUBMITTIMESTART = 432,
     SUBMITTIMEEND = 433,
     SUBSTATUSSTART = 434,
     SUBSTATUSEND = 435,
     SUPERBASICSTART = 436,
     SUPERBASICEND = 437,
     SYSTEMINFORMATIONSTART = 438,
     SYSTEMINFORMATIONEND = 439,
     TIMESTART = 440,
     TIMEEND = 441,
     TIMESERVICESTARTEDSTART = 442,
     TIMESERVICESTARTEDEND = 443,
     TIMESTAMPSTART = 444,
     TIMESTAMPEND = 445,
     TIMINGINFORMATIONSTART = 446,
     TIMINGINFORMATIONEND = 447,
     TOTALJOBSSOFARSTART = 448,
     TOTALJOBSSOFAREND = 449,
     UNKNOWNSTART = 450,
     UNKNOWNEND = 451,
     USEDCPUNUMBERSTART = 452,
     USEDCPUNUMBEREND = 453,
     USEDCPUSPEEDSTART = 454,
     USEDCPUSPEEDEND = 455,
     USEDDISKSPACESTART = 456,
     USEDDISKSPACEEND = 457,
     USEDMEMORYSTART = 458,
     USEDMEMORYEND = 459,
     VALUESSTART = 460,
     VALUESEND = 461,
     VALUESSTRINGSTART = 462,
     VALUESSTRINGEND = 463,
     VARSTART = 464,
     VAREND = 465,
     VARIABLESSTART = 466,
     VARIABLESEND = 467,
     VARIDXSTART = 468,
     VARIDXEND = 469,
     DUMMY = 470
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
#define HEADERSTART 310
#define HEADEREND 311
#define GENERALSTART 312
#define GENERALEND 313
#define SYSTEMSTART 314
#define SYSTEMEND 315
#define SERVICESTART 316
#define SERVICEEND 317
#define JOBSTART 318
#define JOBEND 319
#define OPTIMIZATIONSTART 320
#define OPTIMIZATIONEND 321
#define ITEMSTART 322
#define ITEMEND 323
#define ITEMSTARTANDEND 324
#define ITEMEMPTY 325
#define FILENAMESTART 326
#define FILENAMEEND 327
#define FILENAMEEMPTY 328
#define FILENAMESTARTANDEND 329
#define FILESOURCESTART 330
#define FILESOURCEEND 331
#define FILESOURCEEMPTY 332
#define FILESOURCESTARTANDEND 333
#define FILEDESCRIPTIONSTART 334
#define FILEDESCRIPTIONEND 335
#define FILEDESCRIPTIONEMPTY 336
#define FILEDESCRIPTIONSTARTANDEND 337
#define FILECREATORSTART 338
#define FILECREATOREND 339
#define FILECREATOREMPTY 340
#define FILECREATORSTARTANDEND 341
#define FILELICENCESTART 342
#define FILELICENCEEND 343
#define FILELICENCEEMPTY 344
#define FILELICENCESTARTANDEND 345
#define ACTUALSTARTTIMESTART 346
#define ACTUALSTARTTIMEEND 347
#define ATLOWERSTART 348
#define ATLOWEREND 349
#define ATUPPERSTART 350
#define ATUPPEREND 351
#define AVAILABLECPUNUMBERSTART 352
#define AVAILABLECPUNUMBEREND 353
#define AVAILABLECPUSPEEDSTART 354
#define AVAILABLECPUSPEEDEND 355
#define AVAILABLEDISKSPACESTART 356
#define AVAILABLEDISKSPACEEND 357
#define AVAILABLEMEMORYSTART 358
#define AVAILABLEMEMORYEND 359
#define BASE64START 360
#define BASE64END 361
#define BASICSTART 362
#define BASICEND 363
#define BASISSTATUSSTART 364
#define BASISSTATUSEND 365
#define BASSTATUSSTART 366
#define BASSTATUSEND 367
#define CONSTART 368
#define CONEND 369
#define CONSTRAINTSSTART 370
#define CONSTRAINTSEND 371
#define CURRENTJOBCOUNTSTART 372
#define CURRENTJOBCOUNTEND 373
#define CURRENTSTATESTART 374
#define CURRENTSTATEEND 375
#define DUALVALUESSTART 376
#define DUALVALUESEND 377
#define ELSTART 378
#define ELEND 379
#define ENUMERATIONSTART 380
#define ENUMERATIONEND 381
#define ENDTIMESTART 382
#define ENDTIMEEND 383
#define GENERALSTATUSSTART 384
#define GENERALSTATUSEND 385
#define GENERALSUBSTATUSSTART 386
#define GENERALSUBSTATUSEND 387
#define IDXSTART 388
#define IDXEND 389
#define INSTANCENAMESTART 390
#define INSTANCENAMEEND 391
#define ISFREESTART 392
#define ISFREEEND 393
#define JOBIDSTART 394
#define JOBIDEND 395
#define MESSAGESTART 396
#define MESSAGEEND 397
#define OBJSTART 398
#define OBJEND 399
#define OBJECTIVESSTART 400
#define OBJECTIVESEND 401
#define OPTIMIZATIONSOLUTIONSTATUSSTART 402
#define OPTIMIZATIONSOLUTIONSTATUSEND 403
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 404
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 405
#define OTHERSTART 406
#define OTHEREND 407
#define OTHERRESULTSSTART 408
#define OTHERRESULTSEND 409
#define OTHERSOLUTIONRESULTSTART 410
#define OTHERSOLUTIONRESULTEND 411
#define OTHERSOLUTIONRESULTSSTART 412
#define OTHERSOLUTIONRESULTSEND 413
#define OTHERSOLVEROUTPUTSTART 414
#define OTHERSOLVEROUTPUTEND 415
#define SCHEDULEDSTARTTIMESTART 416
#define SCHEDULEDSTARTTIMEEND 417
#define SERVICENAMESTART 418
#define SERVICENAMEEND 419
#define SERVICEURISTART 420
#define SERVICEURIEND 421
#define SERVICEUTILIZATIONSTART 422
#define SERVICEUTILIZATIONEND 423
#define SOLUTIONSTART 424
#define SOLUTIONEND 425
#define SOLVERINVOKEDSTART 426
#define SOLVERINVOKEDEND 427
#define SOLVEROUTPUTSTART 428
#define SOLVEROUTPUTEND 429
#define STATUSSTART 430
#define STATUSEND 431
#define SUBMITTIMESTART 432
#define SUBMITTIMEEND 433
#define SUBSTATUSSTART 434
#define SUBSTATUSEND 435
#define SUPERBASICSTART 436
#define SUPERBASICEND 437
#define SYSTEMINFORMATIONSTART 438
#define SYSTEMINFORMATIONEND 439
#define TIMESTART 440
#define TIMEEND 441
#define TIMESERVICESTARTEDSTART 442
#define TIMESERVICESTARTEDEND 443
#define TIMESTAMPSTART 444
#define TIMESTAMPEND 445
#define TIMINGINFORMATIONSTART 446
#define TIMINGINFORMATIONEND 447
#define TOTALJOBSSOFARSTART 448
#define TOTALJOBSSOFAREND 449
#define UNKNOWNSTART 450
#define UNKNOWNEND 451
#define USEDCPUNUMBERSTART 452
#define USEDCPUNUMBEREND 453
#define USEDCPUSPEEDSTART 454
#define USEDCPUSPEEDEND 455
#define USEDDISKSPACESTART 456
#define USEDDISKSPACEEND 457
#define USEDMEMORYSTART 458
#define USEDMEMORYEND 459
#define VALUESSTART 460
#define VALUESEND 461
#define VALUESSTRINGSTART 462
#define VALUESSTRINGEND 463
#define VARSTART 464
#define VAREND 465
#define VARIABLESSTART 466
#define VARIABLESEND 467
#define VARIDXSTART 468
#define VARIDXEND 469
#define DUMMY 470




/* Copy the first part of user declarations.  */



 
#include "OSConfig.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSErrorClass.h"
#include "OSResult.h"
#include "OSrLParserData.h"
#include "OSgLParserData.h"
#include "OSBase64.h"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  220
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  765
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1115
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1545

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   470

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   217,
     219,     2,     2,   218,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   216,     2,     2,     2,     2,     2,     2,     2,
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
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    16,    18,    20,
      22,    24,    28,    35,    36,    39,    41,    43,    45,    47,
      51,    57,    58,    60,    62,    64,    66,    68,    72,    73,
      75,    77,    79,    81,    83,    87,    88,    90,    92,    94,
      96,    98,   102,   103,   105,   107,   109,   111,   113,   117,
     118,   120,   122,   124,   126,   128,   132,   133,   136,   138,
     140,   142,   145,   147,   151,   153,   155,   158,   160,   162,
     164,   166,   168,   170,   172,   174,   176,   180,   182,   184,
     186,   189,   191,   193,   195,   197,   199,   202,   204,   208,
     210,   212,   215,   219,   221,   223,   224,   227,   229,   231,
     234,   236,   239,   241,   243,   245,   248,   250,   254,   256,
     259,   261,   263,   265,   268,   270,   274,   276,   279,   281,
     283,   285,   288,   290,   294,   296,   299,   301,   303,   305,
     308,   310,   314,   316,   319,   321,   323,   325,   328,   330,
     334,   336,   339,   341,   343,   345,   348,   350,   354,   356,
     359,   361,   363,   365,   368,   370,   374,   376,   380,   382,
     384,   386,   388,   391,   393,   397,   399,   401,   404,   408,
     410,   412,   413,   416,   418,   420,   422,   425,   427,   428,
     431,   433,   435,   437,   440,   442,   446,   448,   450,   453,
     455,   457,   459,   461,   463,   465,   468,   470,   472,   474,
     477,   479,   483,   485,   489,   491,   493,   494,   497,   499,
     501,   505,   507,   511,   513,   515,   516,   519,   521,   523,
     527,   529,   533,   535,   537,   538,   541,   543,   545,   549,
     551,   555,   557,   558,   560,   564,   566,   570,   572,   574,
     576,   578,   581,   583,   587,   589,   591,   594,   598,   600,
     602,   603,   606,   608,   610,   612,   615,   617,   618,   621,
     623,   625,   627,   630,   632,   636,   638,   640,   643,   645,
     647,   649,   651,   653,   655,   658,   660,   662,   664,   667,
     669,   673,   675,   678,   680,   682,   684,   687,   689,   693,
     695,   698,   700,   702,   704,   707,   709,   713,   715,   718,
     720,   722,   724,   727,   729,   733,   735,   738,   740,   742,
     744,   747,   749,   753,   755,   759,   761,   763,   765,   767,
     770,   772,   776,   778,   780,   783,   787,   789,   791,   792,
     795,   797,   799,   801,   804,   806,   807,   810,   812,   814,
     816,   819,   821,   825,   827,   829,   832,   834,   836,   838,
     840,   842,   844,   846,   848,   850,   852,   854,   857,   859,
     861,   863,   866,   868,   872,   874,   877,   879,   881,   883,
     886,   888,   892,   894,   897,   899,   901,   903,   906,   908,
     912,   914,   917,   919,   921,   923,   926,   928,   932,   934,
     937,   939,   941,   943,   946,   948,   952,   954,   958,   960,
     962,   964,   966,   969,   971,   975,   977,   979,   982,   986,
     988,   989,   992,   994,   996,   998,  1000,  1002,  1004,  1007,
    1009,  1013,  1015,  1017,  1019,  1023,  1025,  1027,  1028,  1031,
    1033,  1035,  1039,  1041,  1045,  1047,  1049,  1050,  1053,  1055,
    1057,  1061,  1063,  1067,  1069,  1071,  1072,  1075,  1077,  1079,
    1083,  1085,  1089,  1091,  1092,  1094,  1098,  1100,  1104,  1106,
    1108,  1110,  1112,  1115,  1117,  1121,  1123,  1125,  1128,  1132,
    1134,  1136,  1137,  1140,  1142,  1144,  1146,  1149,  1151,  1152,
    1156,  1158,  1160,  1161,  1164,  1166,  1168,  1170,  1172,  1174,
    1176,  1179,  1181,  1185,  1188,  1190,  1193,  1197,  1199,  1201,
    1202,  1205,  1207,  1209,  1214,  1218,  1227,  1231,  1233,  1235,
    1237,  1240,  1242,  1244,  1246,  1248,  1250,  1253,  1255,  1259,
    1261,  1263,  1266,  1270,  1272,  1274,  1275,  1278,  1280,  1282,
    1285,  1287,  1288,  1291,  1293,  1295,  1297,  1300,  1302,  1306,
    1308,  1309,  1313,  1315,  1316,  1318,  1320,  1322,  1324,  1328,
    1333,  1334,  1338,  1340,  1342,  1344,  1346,  1349,  1351,  1355,
    1357,  1359,  1362,  1366,  1368,  1373,  1377,  1378,  1382,  1384,
    1386,  1388,  1390,  1393,  1395,  1399,  1401,  1403,  1406,  1410,
    1412,  1417,  1419,  1421,  1424,  1426,  1430,  1432,  1433,  1436,
    1438,  1440,  1442,  1444,  1448,  1455,  1456,  1460,  1462,  1464,
    1466,  1468,  1470,  1474,  1476,  1477,  1481,  1483,  1485,  1487,
    1489,  1491,  1495,  1497,  1498,  1502,  1504,  1506,  1508,  1510,
    1512,  1516,  1518,  1519,  1523,  1525,  1527,  1529,  1531,  1533,
    1537,  1539,  1540,  1544,  1546,  1548,  1550,  1552,  1554,  1558,
    1560,  1561,  1565,  1567,  1569,  1571,  1573,  1575,  1579,  1581,
    1582,  1585,  1589,  1591,  1593,  1594,  1597,  1599,  1601,  1603,
    1605,  1607,  1609,  1611,  1614,  1616,  1620,  1622,  1624,  1626,
    1629,  1633,  1635,  1640,  1642,  1644,  1647,  1649,  1653,  1655,
    1657,  1660,  1664,  1666,  1668,  1669,  1672,  1674,  1676,  1678,
    1680,  1682,  1684,  1688,  1690,  1691,  1695,  1697,  1698,  1700,
    1702,  1704,  1706,  1710,  1714,  1715,  1719,  1721,  1723,  1725,
    1727,  1730,  1732,  1736,  1738,  1740,  1743,  1747,  1749,  1750,
    1755,  1759,  1761,  1763,  1764,  1767,  1769,  1771,  1773,  1775,
    1779,  1786,  1787,  1791,  1793,  1795,  1797,  1799,  1801,  1805,
    1807,  1808,  1812,  1814,  1816,  1818,  1820,  1822,  1826,  1828,
    1829,  1833,  1835,  1837,  1839,  1841,  1843,  1847,  1849,  1850,
    1854,  1856,  1858,  1860,  1862,  1864,  1868,  1870,  1871,  1875,
    1877,  1879,  1881,  1883,  1885,  1889,  1891,  1892,  1896,  1898,
    1900,  1902,  1904,  1906,  1910,  1912,  1913,  1916,  1920,  1922,
    1924,  1925,  1928,  1930,  1932,  1934,  1936,  1938,  1940,  1942,
    1945,  1947,  1951,  1953,  1955,  1957,  1960,  1964,  1966,  1971,
    1973,  1975,  1978,  1980,  1984,  1986,  1988,  1991,  1995,  1997,
    1999,  2000,  2003,  2005,  2007,  2009,  2011,  2013,  2015,  2019,
    2021,  2022,  2026,  2028,  2029,  2031,  2033,  2035,  2037,  2041,
    2045,  2046,  2050,  2052,  2054,  2056,  2058,  2061,  2063,  2067,
    2069,  2071,  2074,  2078,  2080,  2085,  2089,  2090,  2093,  2095,
    2097,  2099,  2101,  2105,  2112,  2113,  2117,  2119,  2121,  2123,
    2125,  2127,  2131,  2133,  2134,  2138,  2140,  2142,  2144,  2146,
    2148,  2152,  2154,  2155,  2159,  2161,  2163,  2165,  2167,  2169,
    2173,  2175,  2176,  2180,  2182,  2184,  2186,  2188,  2190,  2194,
    2196,  2197,  2201,  2203,  2205,  2207,  2209,  2211,  2215,  2217,
    2218,  2222,  2224,  2226,  2228,  2230,  2232,  2236,  2238,  2239,
    2242,  2246,  2248,  2250,  2251,  2254,  2256,  2258,  2260,  2262,
    2264,  2266,  2268,  2271,  2273,  2277,  2279,  2281,  2283,  2286,
    2290,  2292,  2297,  2299,  2301,  2304,  2306,  2310,  2312,  2314,
    2317,  2321,  2323,  2325,  2326,  2329,  2331,  2333,  2335,  2337,
    2339,  2341,  2345,  2347,  2348,  2352,  2354,  2356,  2358,  2360,
    2363,  2365,  2369,  2371,  2373,  2376,  2380,  2382,  2384,  2385,
    2388,  2390,  2392,  2394,  2396,  2398,  2400,  2403,  2405,  2409,
    2411,  2413,  2416,  2418,  2420,  2422,  2424,  2426,  2430,  2432,
    2433,  2437,  2439,  2441,  2443,  2445,  2448,  2450,  2454,  2456,
    2458,  2461,  2465,  2467,  2469,  2470,  2473,  2475,  2477,  2479,
    2481,  2483,  2485,  2488,  2490,  2494,  2496,  2498,  2501,  2503,
    2505,  2507,  2509,  2511,  2515,  2517,  2519,  2521,  2523,  2525,
    2529,  2531,  2533,  2535,  2537,  2541,  2543,  2545,  2547,  2549,
    2553,  2555,  2557,  2559,  2561,  2565,  2567,  2569,  2571,  2573,
    2577,  2579,  2581,  2583,  2585,  2589,  2594,  2599,  2604,  2609,
    2614,  2619,  2624,  2629,  2634,  2639,  2644,  2649,  2654,  2659,
    2664,  2669,  2674,  2679,  2681,  2683,  2684,  2687,  2691,  2693,
    2695,  2696,  2699,  2701,  2703,  2707,  2711,  2716,  2718,  2720,
    2723,  2725,  2729,  2734,  2739,  2741,  2743,  2745,  2747,  2749,
    2752,  2753,  2756,  2758,  2760,  2762
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     221,     0,    -1,   222,   228,    15,    -1,   223,   224,   225,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   226,    -1,
     227,    -1,    11,    -1,    10,   228,    15,    -1,   229,   255,
     335,   389,   441,   536,    -1,    -1,   230,   231,    -1,    55,
      -1,   232,    -1,   233,    -1,    11,    -1,    10,   234,    56,
      -1,   235,   239,   243,   247,   251,    -1,    -1,   236,    -1,
     237,    -1,   238,    -1,    74,    -1,    73,    -1,    71,     5,
      72,    -1,    -1,   240,    -1,   241,    -1,   242,    -1,    78,
      -1,    77,    -1,    75,     5,    76,    -1,    -1,   244,    -1,
     245,    -1,   246,    -1,    82,    -1,    81,    -1,    79,     5,
      80,    -1,    -1,   248,    -1,   249,    -1,   250,    -1,    86,
      -1,    85,    -1,    83,     5,    84,    -1,    -1,   252,    -1,
     253,    -1,   254,    -1,    90,    -1,    89,    -1,    87,     5,
      88,    -1,    -1,   256,   257,    -1,    57,    -1,   258,    -1,
     259,    -1,    10,    58,    -1,    11,    -1,    10,   260,    58,
      -1,   261,    -1,   262,    -1,   261,   262,    -1,   263,    -1,
     279,    -1,   285,    -1,   291,    -1,   297,    -1,   303,    -1,
     309,    -1,   315,    -1,   321,    -1,   264,   265,   268,    -1,
     129,    -1,   266,    -1,   267,    -1,   266,   267,    -1,   935,
      -1,   927,    -1,   961,    -1,   269,    -1,   270,    -1,    10,
     130,    -1,    11,    -1,    10,   271,   130,    -1,   272,    -1,
     273,    -1,   272,   273,    -1,   274,   275,   278,    -1,   179,
      -1,   276,    -1,    -1,   276,   277,    -1,   931,    -1,   927,
      -1,    10,   180,    -1,    11,    -1,   280,   281,    -1,   141,
      -1,   282,    -1,   283,    -1,    10,   142,    -1,    11,    -1,
      10,   284,   142,    -1,     4,    -1,   286,   287,    -1,   165,
      -1,   288,    -1,   289,    -1,    10,   166,    -1,    11,    -1,
      10,   290,   166,    -1,     4,    -1,   292,   293,    -1,   163,
      -1,   294,    -1,   295,    -1,    10,   164,    -1,    11,    -1,
      10,   296,   164,    -1,     4,    -1,   298,   299,    -1,   135,
      -1,   300,    -1,   301,    -1,    10,   136,    -1,    11,    -1,
      10,   302,   136,    -1,     4,    -1,   304,   305,    -1,   139,
      -1,   306,    -1,   307,    -1,    10,   140,    -1,    11,    -1,
      10,   308,   140,    -1,     4,    -1,   310,   311,    -1,   171,
      -1,   312,    -1,   313,    -1,    10,   172,    -1,    11,    -1,
      10,   314,   172,    -1,     4,    -1,   316,   317,    -1,   189,
      -1,   318,    -1,   319,    -1,    10,   190,    -1,    11,    -1,
      10,   320,   190,    -1,     4,    -1,   322,   323,   324,    -1,
     153,    -1,   956,    -1,   325,    -1,   326,    -1,    10,   154,
      -1,    11,    -1,    10,   327,   154,    -1,   328,    -1,   329,
      -1,   328,   329,    -1,   330,   331,   334,    -1,   151,    -1,
     332,    -1,    -1,   332,   333,    -1,   931,    -1,   943,    -1,
     927,    -1,    10,   152,    -1,    11,    -1,    -1,   336,   337,
      -1,    59,    -1,   338,    -1,   339,    -1,    10,    60,    -1,
      11,    -1,    10,   340,    60,    -1,   341,    -1,   342,    -1,
     341,   342,    -1,   343,    -1,   349,    -1,   356,    -1,   363,
      -1,   370,    -1,   375,    -1,   344,   345,    -1,   183,    -1,
     346,    -1,   347,    -1,    10,   184,    -1,    11,    -1,    10,
     348,   184,    -1,     4,    -1,   350,   351,   354,    -1,   101,
      -1,   352,    -1,    -1,   352,   353,    -1,   939,    -1,   927,
      -1,    10,   355,   102,    -1,   980,    -1,   357,   358,   361,
      -1,   103,    -1,   359,    -1,    -1,   359,   360,    -1,   939,
      -1,   927,    -1,    10,   362,   104,    -1,   980,    -1,   364,
     365,   368,    -1,    99,    -1,   366,    -1,    -1,   366,   367,
      -1,   939,    -1,   927,    -1,    10,   369,   100,    -1,   980,
      -1,   371,   372,   373,    -1,    97,    -1,    -1,   927,    -1,
      10,   374,    98,    -1,     6,    -1,   376,   377,   378,    -1,
     153,    -1,   956,    -1,   379,    -1,   380,    -1,    10,   154,
      -1,    11,    -1,    10,   381,   154,    -1,   382,    -1,   383,
      -1,   382,   383,    -1,   384,   385,   388,    -1,   151,    -1,
     386,    -1,    -1,   386,   387,    -1,   931,    -1,   943,    -1,
     927,    -1,    10,   152,    -1,    11,    -1,    -1,   390,   391,
      -1,    61,    -1,   392,    -1,   393,    -1,    10,    62,    -1,
      11,    -1,    10,   394,    62,    -1,   395,    -1,   396,    -1,
     395,   396,    -1,   397,    -1,   403,    -1,   409,    -1,   415,
      -1,   421,    -1,   427,    -1,   398,   399,    -1,   119,    -1,
     400,    -1,   401,    -1,    10,   120,    -1,    11,    -1,    10,
     402,   120,    -1,     4,    -1,   404,   405,    -1,   117,    -1,
     406,    -1,   407,    -1,    10,   118,    -1,    11,    -1,    10,
     408,   118,    -1,     6,    -1,   410,   411,    -1,   193,    -1,
     412,    -1,   413,    -1,    10,   194,    -1,    11,    -1,    10,
     414,   194,    -1,     6,    -1,   416,   417,    -1,   187,    -1,
     418,    -1,   419,    -1,    10,   188,    -1,    11,    -1,    10,
     420,   188,    -1,     4,    -1,   422,   423,    -1,   167,    -1,
     424,    -1,   425,    -1,    10,   168,    -1,    11,    -1,    10,
     426,   168,    -1,   980,    -1,   428,   429,   430,    -1,   153,
      -1,   956,    -1,   431,    -1,   432,    -1,    10,   154,    -1,
      11,    -1,    10,   433,   154,    -1,   434,    -1,   435,    -1,
     434,   435,    -1,   436,   437,   440,    -1,   151,    -1,   438,
      -1,    -1,   438,   439,    -1,   931,    -1,   943,    -1,   927,
      -1,    10,   152,    -1,    11,    -1,    -1,   442,   443,    -1,
      63,    -1,   444,    -1,   445,    -1,    10,    64,    -1,    11,
      -1,    10,   446,    64,    -1,   447,    -1,   448,    -1,   447,
     448,    -1,   449,    -1,   455,    -1,   461,    -1,   467,    -1,
     473,    -1,   479,    -1,   496,    -1,   503,    -1,   510,    -1,
     517,    -1,   522,    -1,   450,   451,    -1,   175,    -1,   452,
      -1,   453,    -1,    10,   176,    -1,    11,    -1,    10,   454,
     176,    -1,     4,    -1,   456,   457,    -1,   177,    -1,   458,
      -1,   459,    -1,    10,   178,    -1,    11,    -1,    10,   460,
     178,    -1,     4,    -1,   462,   463,    -1,   161,    -1,   464,
      -1,   465,    -1,    10,   162,    -1,    11,    -1,    10,   466,
     162,    -1,     4,    -1,   468,   469,    -1,    91,    -1,   470,
      -1,   471,    -1,    10,    92,    -1,    11,    -1,    10,   472,
      92,    -1,     4,    -1,   474,   475,    -1,   127,    -1,   476,
      -1,   477,    -1,    10,   128,    -1,    11,    -1,    10,   478,
     128,    -1,     4,    -1,   480,   481,   482,    -1,   191,    -1,
     962,    -1,   483,    -1,   484,    -1,    10,   192,    -1,    11,
      -1,    10,   485,   192,    -1,   486,    -1,   487,    -1,   486,
     487,    -1,   488,   489,   491,    -1,   185,    -1,    -1,   489,
     490,    -1,   939,    -1,   935,    -1,   923,    -1,   927,    -1,
     492,    -1,   493,    -1,    10,   186,    -1,    11,    -1,    10,
     494,   186,    -1,   495,    -1,     7,    -1,     6,    -1,   497,
     498,   501,    -1,   201,    -1,   499,    -1,    -1,   499,   500,
      -1,   939,    -1,   927,    -1,    10,   502,   202,    -1,   980,
      -1,   504,   505,   508,    -1,   203,    -1,   506,    -1,    -1,
     506,   507,    -1,   939,    -1,   927,    -1,    10,   509,   204,
      -1,   980,    -1,   511,   512,   515,    -1,   199,    -1,   513,
      -1,    -1,   513,   514,    -1,   939,    -1,   927,    -1,    10,
     516,   200,    -1,   980,    -1,   518,   519,   520,    -1,   197,
      -1,    -1,   927,    -1,    10,   521,   198,    -1,     6,    -1,
     523,   524,   525,    -1,   153,    -1,   956,    -1,   526,    -1,
     527,    -1,    10,   154,    -1,    11,    -1,    10,   528,   154,
      -1,   529,    -1,   530,    -1,   529,   530,    -1,   531,   532,
     535,    -1,   151,    -1,   533,    -1,    -1,   533,   534,    -1,
     931,    -1,   943,    -1,   927,    -1,    10,   152,    -1,    11,
      -1,    -1,   537,   538,   541,    -1,    65,    -1,   539,    -1,
      -1,   539,   540,    -1,   959,    -1,   964,    -1,   948,    -1,
     953,    -1,   542,    -1,   543,    -1,    10,    66,    -1,    11,
      -1,    10,   544,    66,    -1,   545,   900,    -1,   546,    -1,
     545,   546,    -1,   547,   548,   553,    -1,   169,    -1,   549,
      -1,    -1,   549,   550,    -1,   551,    -1,   552,    -1,    36,
     982,     6,   982,    -1,    53,     3,   982,    -1,    10,   554,
     570,   576,   686,   782,   877,   170,    -1,   555,   556,   559,
      -1,   175,    -1,   557,    -1,   558,    -1,   557,   558,    -1,
     935,    -1,   927,    -1,   961,    -1,   560,    -1,   561,    -1,
      10,   176,    -1,    11,    -1,    10,   562,   176,    -1,   563,
      -1,   564,    -1,   563,   564,    -1,   565,   566,   569,    -1,
     179,    -1,   567,    -1,    -1,   567,   568,    -1,   935,    -1,
     927,    -1,    10,   180,    -1,    11,    -1,    -1,   571,   572,
      -1,   141,    -1,   573,    -1,   574,    -1,    10,   142,    -1,
      11,    -1,    10,   575,   142,    -1,     4,    -1,    -1,   577,
     578,   579,    -1,   211,    -1,    -1,   958,    -1,   580,    -1,
     581,    -1,    11,    -1,    10,   582,   212,    -1,   583,   595,
     610,   658,    -1,    -1,   584,   585,   586,    -1,   205,    -1,
     963,    -1,   587,    -1,   588,    -1,    10,   206,    -1,    11,
      -1,    10,   589,   206,    -1,   590,    -1,   591,    -1,   590,
     591,    -1,   592,   593,   594,    -1,   209,    -1,    37,   982,
       6,   982,    -1,    10,   980,   210,    -1,    -1,   596,   597,
     598,    -1,   207,    -1,   963,    -1,   599,    -1,   600,    -1,
      10,   208,    -1,    11,    -1,    10,   601,   208,    -1,   602,
      -1,   603,    -1,   602,   603,    -1,   604,   605,   606,    -1,
     209,    -1,    37,   982,     6,   982,    -1,   607,    -1,   608,
      -1,    10,   210,    -1,    11,    -1,    10,   609,   210,    -1,
       4,    -1,    -1,   611,   612,    -1,   109,    -1,   613,    -1,
     614,    -1,    11,    -1,    10,   615,   110,    -1,   616,   623,
     630,   637,   644,   651,    -1,    -1,   617,   618,   619,    -1,
     107,    -1,   949,    -1,   620,    -1,   621,    -1,    11,    -1,
      10,   622,   108,    -1,   965,    -1,    -1,   624,   625,   626,
      -1,    93,    -1,   949,    -1,   627,    -1,   628,    -1,    11,
      -1,    10,   629,    94,    -1,   965,    -1,    -1,   631,   632,
     633,    -1,    95,    -1,   949,    -1,   634,    -1,   635,    -1,
      11,    -1,    10,   636,    96,    -1,   965,    -1,    -1,   638,
     639,   640,    -1,   137,    -1,   949,    -1,   641,    -1,   642,
      -1,    11,    -1,    10,   643,   138,    -1,   965,    -1,    -1,
     645,   646,   647,    -1,   181,    -1,   949,    -1,   648,    -1,
     649,    -1,    11,    -1,    10,   650,   182,    -1,   965,    -1,
      -1,   652,   653,   654,    -1,   195,    -1,   949,    -1,   655,
      -1,   656,    -1,    11,    -1,    10,   657,   196,    -1,   965,
      -1,    -1,   658,   659,    -1,   660,   661,   664,    -1,   151,
      -1,   662,    -1,    -1,   662,   663,    -1,   963,    -1,   950,
      -1,   943,    -1,   931,    -1,   927,    -1,   665,    -1,   666,
      -1,    10,   152,    -1,    11,    -1,    10,   667,   152,    -1,
     668,    -1,   676,    -1,   669,    -1,   668,   669,    -1,   670,
     671,   672,    -1,   209,    -1,    37,   982,     6,   982,    -1,
     673,    -1,   674,    -1,    10,   210,    -1,    11,    -1,    10,
     675,   210,    -1,   981,    -1,   677,    -1,   676,   677,    -1,
     678,   679,   682,    -1,   125,    -1,   680,    -1,    -1,   680,
     681,    -1,   949,    -1,   943,    -1,   927,    -1,   683,    -1,
     684,    -1,    11,    -1,    10,   685,   126,    -1,   965,    -1,
      -1,   687,   688,   689,    -1,   145,    -1,    -1,   955,    -1,
     690,    -1,   691,    -1,    11,    -1,    10,   692,   146,    -1,
     693,   706,   754,    -1,    -1,   694,   695,   696,    -1,   205,
      -1,   952,    -1,   697,    -1,   698,    -1,    10,   206,    -1,
      11,    -1,    10,   699,   206,    -1,   700,    -1,   701,    -1,
     700,   701,    -1,   702,   703,   704,    -1,   143,    -1,    -1,
      37,   982,     6,   982,    -1,    10,   705,   144,    -1,     6,
      -1,     7,    -1,    -1,   707,   708,    -1,   109,    -1,   709,
      -1,   710,    -1,    11,    -1,    10,   711,   110,    -1,   712,
     719,   726,   733,   740,   747,    -1,    -1,   713,   714,   715,
      -1,   107,    -1,   949,    -1,   716,    -1,   717,    -1,    11,
      -1,    10,   718,   108,    -1,   965,    -1,    -1,   720,   721,
     722,    -1,    93,    -1,   949,    -1,   723,    -1,   724,    -1,
      11,    -1,    10,   725,    94,    -1,   965,    -1,    -1,   727,
     728,   729,    -1,    95,    -1,   949,    -1,   730,    -1,   731,
      -1,    11,    -1,    10,   732,    96,    -1,   965,    -1,    -1,
     734,   735,   736,    -1,   137,    -1,   949,    -1,   737,    -1,
     738,    -1,    11,    -1,    10,   739,   138,    -1,   965,    -1,
      -1,   741,   742,   743,    -1,   181,    -1,   949,    -1,   744,
      -1,   745,    -1,    11,    -1,    10,   746,   182,    -1,   965,
      -1,    -1,   748,   749,   750,    -1,   195,    -1,   949,    -1,
     751,    -1,   752,    -1,    11,    -1,    10,   753,   196,    -1,
     965,    -1,    -1,   754,   755,    -1,   756,   757,   760,    -1,
     151,    -1,   758,    -1,    -1,   758,   759,    -1,   952,    -1,
     950,    -1,   943,    -1,   931,    -1,   927,    -1,   761,    -1,
     762,    -1,    10,   152,    -1,    11,    -1,    10,   763,   152,
      -1,   764,    -1,   772,    -1,   765,    -1,   764,   765,    -1,
     766,   767,   768,    -1,   143,    -1,    37,   982,     6,   982,
      -1,   769,    -1,   770,    -1,    10,   144,    -1,    11,    -1,
      10,   771,   144,    -1,   981,    -1,   773,    -1,   772,   773,
      -1,   774,   775,   778,    -1,   125,    -1,   776,    -1,    -1,
     776,   777,    -1,   949,    -1,   943,    -1,   927,    -1,   779,
      -1,   780,    -1,    11,    -1,    10,   781,   126,    -1,   965,
      -1,    -1,   783,   784,   785,    -1,   115,    -1,    -1,   954,
      -1,   786,    -1,   787,    -1,    11,    -1,    10,   788,   116,
      -1,   789,   801,   849,    -1,    -1,   790,   791,   792,    -1,
     121,    -1,   947,    -1,   793,    -1,   794,    -1,    10,   122,
      -1,    11,    -1,    10,   795,   122,    -1,   796,    -1,   797,
      -1,   796,   797,    -1,   798,   799,   800,    -1,   113,    -1,
      37,   982,     6,   982,    -1,    10,   980,   114,    -1,    -1,
     802,   803,    -1,   109,    -1,   804,    -1,   805,    -1,    11,
      -1,    10,   806,   110,    -1,   807,   814,   821,   828,   835,
     842,    -1,    -1,   808,   809,   810,    -1,   107,    -1,   949,
      -1,   811,    -1,   812,    -1,    11,    -1,    10,   813,   108,
      -1,   965,    -1,    -1,   815,   816,   817,    -1,    93,    -1,
     949,    -1,   818,    -1,   819,    -1,    11,    -1,    10,   820,
      94,    -1,   965,    -1,    -1,   822,   823,   824,    -1,    95,
      -1,   949,    -1,   825,    -1,   826,    -1,    11,    -1,    10,
     827,    96,    -1,   965,    -1,    -1,   829,   830,   831,    -1,
     137,    -1,   949,    -1,   832,    -1,   833,    -1,    11,    -1,
      10,   834,   138,    -1,   965,    -1,    -1,   836,   837,   838,
      -1,   181,    -1,   949,    -1,   839,    -1,   840,    -1,    11,
      -1,    10,   841,   182,    -1,   965,    -1,    -1,   843,   844,
     845,    -1,   195,    -1,   949,    -1,   846,    -1,   847,    -1,
      11,    -1,    10,   848,   196,    -1,   965,    -1,    -1,   849,
     850,    -1,   851,   852,   855,    -1,   151,    -1,   853,    -1,
      -1,   853,   854,    -1,   947,    -1,   950,    -1,   943,    -1,
     931,    -1,   927,    -1,   856,    -1,   857,    -1,    10,   152,
      -1,    11,    -1,    10,   858,   152,    -1,   859,    -1,   867,
      -1,   860,    -1,   859,   860,    -1,   861,   862,   863,    -1,
     113,    -1,    37,   982,     6,   982,    -1,   864,    -1,   865,
      -1,    10,   114,    -1,    11,    -1,    10,   866,   114,    -1,
     981,    -1,   868,    -1,   867,   868,    -1,   869,   870,   873,
      -1,   125,    -1,   871,    -1,    -1,   871,   872,    -1,   949,
      -1,   943,    -1,   927,    -1,   874,    -1,   875,    -1,    11,
      -1,    10,   876,   126,    -1,   965,    -1,    -1,   878,   879,
     880,    -1,   157,    -1,   957,    -1,   881,    -1,   882,    -1,
      10,   158,    -1,    11,    -1,    10,   883,   158,    -1,   884,
      -1,   885,    -1,   884,   885,    -1,   886,   887,   890,    -1,
     155,    -1,   888,    -1,    -1,   888,   889,    -1,   931,    -1,
     923,    -1,   927,    -1,   951,    -1,   891,    -1,   892,    -1,
      10,   156,    -1,    11,    -1,    10,   893,   156,    -1,   894,
      -1,   895,    -1,   894,   895,    -1,   896,    -1,   897,    -1,
     898,    -1,    69,    -1,    70,    -1,    67,   899,    68,    -1,
       5,    -1,    -1,   901,   902,   903,    -1,   159,    -1,   960,
      -1,   904,    -1,   905,    -1,    10,   160,    -1,    11,    -1,
      10,   906,   160,    -1,   907,    -1,   908,    -1,   907,   908,
      -1,   909,   910,   913,    -1,   173,    -1,   911,    -1,    -1,
     911,   912,    -1,   931,    -1,   923,    -1,   927,    -1,   951,
      -1,   914,    -1,   915,    -1,    10,   174,    -1,    11,    -1,
      10,   916,   174,    -1,   917,    -1,   918,    -1,   917,   918,
      -1,   919,    -1,   920,    -1,   921,    -1,    69,    -1,    70,
      -1,    67,   922,    68,    -1,     5,    -1,   924,    -1,   925,
      -1,   926,    -1,    42,    -1,    41,     3,   982,    -1,   928,
      -1,   929,    -1,   930,    -1,    44,    -1,    43,     3,   982,
      -1,   932,    -1,   933,    -1,   934,    -1,    46,    -1,    45,
       3,   982,    -1,   936,    -1,   937,    -1,   938,    -1,    48,
      -1,    47,     3,   982,    -1,   940,    -1,   941,    -1,   942,
      -1,    50,    -1,    49,     3,   982,    -1,   944,    -1,   945,
      -1,   946,    -1,    52,    -1,    51,     3,   982,    -1,    16,
     982,     6,   982,    -1,    17,   982,     6,   982,    -1,    18,
     982,     6,   982,    -1,    19,   982,     6,   982,    -1,    21,
     982,     6,   982,    -1,    22,   982,     6,   982,    -1,    23,
     982,     6,   982,    -1,    24,   982,     6,   982,    -1,    25,
     982,     6,   982,    -1,    26,   982,     6,   982,    -1,    27,
     982,     6,   982,    -1,    28,   982,     6,   982,    -1,    29,
     982,     6,   982,    -1,    30,   982,     6,   982,    -1,    31,
     982,     6,   982,    -1,    32,   982,     6,   982,    -1,    33,
     982,     6,   982,    -1,    34,   982,     6,   982,    -1,   966,
      -1,   973,    -1,    -1,   966,   967,    -1,   968,   969,   972,
      -1,   123,    -1,   970,    -1,    -1,   970,   971,    -1,   979,
      -1,   978,    -1,    10,     6,   124,    -1,   105,   974,   975,
      -1,    40,   982,     6,   982,    -1,   976,    -1,   977,    -1,
      10,   106,    -1,    11,    -1,    10,     4,   106,    -1,    38,
     982,     6,   982,    -1,    39,   982,     6,   982,    -1,     6,
      -1,     7,    -1,     4,    -1,     6,    -1,     7,    -1,   983,
       8,    -1,    -1,   983,   984,    -1,   216,    -1,   217,    -1,
     218,    -1,   219,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   191,   191,   192,   194,   201,   208,   208,   210,   210,
     212,   214,   217,   226,   226,   236,   245,   245,   247,   249,
     251,   253,   253,   255,   255,   257,   257,   259,   264,   264,
     266,   266,   268,   268,   270,   275,   275,   277,   277,   279,
     279,   281,   286,   286,   288,   288,   290,   290,   292,   297,
     297,   299,   299,   301,   301,   303,   313,   313,   315,   317,
     317,   319,   319,   321,   323,   325,   325,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   339,   341,   355,   361,
     361,   364,   369,   373,   381,   385,   390,   390,   392,   394,
     396,   396,   398,   402,   411,   416,   416,   419,   424,   430,
     430,   433,   435,   441,   441,   443,   443,   445,   447,   450,
     452,   458,   458,   460,   460,   462,   464,   467,   469,   475,
     475,   477,   477,   479,   481,   484,   486,   492,   492,   494,
     494,   496,   498,   501,   503,   509,   509,   511,   511,   513,
     515,   518,   520,   526,   526,   528,   528,   530,   532,   535,
     537,   543,   543,   545,   545,   547,   549,   552,   554,   560,
     570,   574,   579,   579,   581,   583,   585,   585,   587,   591,
     602,   607,   607,   610,   616,   621,   628,   628,   632,   632,
     634,   636,   636,   638,   638,   640,   642,   644,   644,   647,
     648,   649,   650,   651,   652,   655,   657,   663,   663,   665,
     665,   667,   669,   675,   677,   687,   689,   689,   692,   698,
     703,   705,   710,   712,   722,   724,   724,   727,   733,   738,
     740,   746,   748,   758,   760,   760,   763,   769,   774,   776,
     782,   784,   792,   793,   798,   800,   804,   806,   812,   822,
     826,   831,   831,   833,   835,   837,   837,   839,   843,   854,
     859,   859,   862,   868,   873,   880,   880,   884,   884,   886,
     888,   888,   890,   890,   892,   894,   896,   896,   899,   900,
     901,   902,   903,   904,   907,   909,   915,   915,   917,   917,
     919,   921,   928,   930,   936,   936,   938,   938,   940,   942,
     945,   947,   953,   953,   955,   955,   957,   959,   962,   964,
     970,   970,   972,   972,   974,   976,   979,   981,   987,   987,
     989,   989,   991,   993,   999,  1001,  1007,  1017,  1021,  1026,
    1026,  1028,  1030,  1032,  1032,  1034,  1038,  1049,  1054,  1054,
    1057,  1063,  1068,  1075,  1075,  1078,  1078,  1080,  1082,  1082,
    1084,  1084,  1086,  1088,  1090,  1090,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1106,  1108,  1114,
    1114,  1116,  1116,  1118,  1120,  1127,  1129,  1135,  1135,  1137,
    1137,  1139,  1141,  1144,  1146,  1152,  1152,  1154,  1154,  1156,
    1158,  1161,  1163,  1169,  1169,  1171,  1171,  1173,  1175,  1178,
    1180,  1186,  1186,  1188,  1188,  1190,  1192,  1195,  1197,  1203,
    1212,  1216,  1221,  1221,  1223,  1225,  1227,  1227,  1229,  1231,
    1244,  1244,  1247,  1247,  1247,  1247,  1250,  1250,  1252,  1252,
    1254,  1256,  1269,  1270,  1273,  1275,  1285,  1287,  1287,  1290,
    1296,  1301,  1303,  1309,  1311,  1321,  1323,  1323,  1326,  1332,
    1337,  1339,  1345,  1347,  1357,  1359,  1359,  1362,  1368,  1373,
    1375,  1381,  1383,  1392,  1393,  1398,  1400,  1405,  1407,  1413,
    1423,  1427,  1432,  1432,  1434,  1436,  1438,  1438,  1440,  1444,
    1455,  1460,  1460,  1463,  1469,  1474,  1481,  1481,  1484,  1484,
    1486,  1494,  1499,  1499,  1502,  1509,  1515,  1521,  1529,  1533,
    1538,  1538,  1540,  1542,  1544,  1544,  1546,  1548,  1556,  1558,
    1558,  1560,  1560,  1562,  1571,  1588,  1594,  1596,  1606,  1611,
    1611,  1614,  1619,  1623,  1632,  1636,  1642,  1642,  1644,  1646,
    1648,  1648,  1650,  1653,  1662,  1667,  1667,  1670,  1676,  1683,
    1683,  1686,  1686,  1688,  1690,  1690,  1692,  1692,  1694,  1696,
    1703,  1703,  1705,  1708,  1708,  1717,  1717,  1719,  1721,  1723,
    1725,  1725,  1727,  1729,  1737,  1741,  1746,  1746,  1748,  1750,
    1752,  1752,  1754,  1761,  1767,  1769,  1772,  1772,  1774,  1776,
    1784,  1788,  1793,  1793,  1795,  1797,  1799,  1799,  1801,  1809,
    1815,  1818,  1819,  1821,  1821,  1823,  1825,  1828,  1828,  1830,
    1832,  1832,  1834,  1836,  1838,  1840,  1840,  1849,  1851,  1858,
    1858,  1860,  1862,  1864,  1867,  1867,  1877,  1879,  1886,  1886,
    1888,  1890,  1892,  1895,  1895,  1904,  1906,  1913,  1913,  1915,
    1917,  1919,  1922,  1922,  1931,  1933,  1940,  1940,  1942,  1944,
    1946,  1949,  1949,  1958,  1960,  1967,  1967,  1969,  1971,  1973,
    1976,  1976,  1985,  1987,  1994,  1994,  1996,  1998,  2000,  2003,
    2003,  2005,  2010,  2023,  2030,  2030,  2033,  2043,  2053,  2059,
    2065,  2072,  2072,  2074,  2074,  2076,  2078,  2078,  2080,  2080,
    2082,  2087,  2089,  2096,  2096,  2098,  2098,  2100,  2102,  2111,
    2111,  2113,  2124,  2133,  2140,  2140,  2143,  2149,  2155,  2163,
    2163,  2165,  2167,  2170,  2174,  2174,  2176,  2182,  2182,  2191,
    2191,  2193,  2195,  2197,  2199,  2199,  2201,  2203,  2211,  2215,
    2220,  2220,  2222,  2224,  2227,  2227,  2229,  2236,  2243,  2243,
    2245,  2248,  2249,  2252,  2252,  2254,  2256,  2256,  2260,  2262,
    2264,  2266,  2266,  2275,  2277,  2284,  2284,  2286,  2288,  2290,
    2292,  2292,  2301,  2303,  2310,  2310,  2312,  2314,  2316,  2319,
    2319,  2328,  2330,  2337,  2337,  2339,  2341,  2343,  2346,  2346,
    2355,  2357,  2364,  2364,  2366,  2368,  2370,  2373,  2373,  2382,
    2384,  2391,  2391,  2393,  2395,  2397,  2400,  2400,  2409,  2411,
    2418,  2418,  2420,  2422,  2424,  2427,  2427,  2429,  2435,  2448,
    2456,  2456,  2459,  2469,  2479,  2485,  2491,  2500,  2500,  2502,
    2502,  2504,  2506,  2506,  2508,  2508,  2510,  2515,  2517,  2522,
    2522,  2524,  2524,  2526,  2528,  2534,  2534,  2536,  2547,  2556,
    2563,  2563,  2566,  2572,  2578,  2586,  2586,  2588,  2590,  2593,
    2596,  2596,  2598,  2603,  2603,  2611,  2611,  2613,  2615,  2617,
    2619,  2619,  2621,  2624,  2632,  2636,  2641,  2641,  2643,  2645,
    2647,  2647,  2649,  2656,  2662,  2664,  2667,  2667,  2669,  2671,
    2671,  2673,  2675,  2677,  2679,  2679,  2688,  2690,  2697,  2697,
    2699,  2701,  2703,  2705,  2705,  2714,  2716,  2723,  2723,  2725,
    2727,  2729,  2732,  2732,  2741,  2743,  2750,  2750,  2752,  2754,
    2756,  2759,  2759,  2768,  2770,  2777,  2777,  2779,  2781,  2783,
    2786,  2786,  2795,  2797,  2804,  2804,  2806,  2808,  2810,  2813,
    2813,  2822,  2824,  2831,  2831,  2833,  2835,  2837,  2840,  2840,
    2842,  2848,  2861,  2868,  2868,  2871,  2881,  2891,  2897,  2903,
    2910,  2910,  2912,  2912,  2914,  2916,  2916,  2918,  2918,  2920,
    2925,  2927,  2933,  2933,  2935,  2935,  2937,  2939,  2946,  2946,
    2948,  2959,  2968,  2975,  2975,  2978,  2984,  2990,  2998,  2998,
    3000,  3002,  3004,  3008,  3008,  3010,  3015,  3024,  3028,  3033,
    3033,  3035,  3037,  3039,  3039,  3041,  3045,  3056,  3063,  3063,
    3066,  3072,  3078,  3086,  3096,  3100,  3105,  3105,  3107,  3109,
    3111,  3111,  3113,  3118,  3122,  3124,  3124,  3126,  3128,  3139,
    3139,  3141,  3146,  3155,  3159,  3164,  3164,  3166,  3168,  3170,
    3170,  3172,  3176,  3187,  3194,  3194,  3197,  3202,  3208,  3214,
    3223,  3227,  3232,  3232,  3234,  3236,  3238,  3238,  3240,  3245,
    3249,  3251,  3251,  3253,  3255,  3265,  3271,  3271,  3273,  3276,
    3279,  3285,  3285,  3287,  3290,  3294,  3300,  3300,  3302,  3305,
    3308,  3314,  3314,  3316,  3319,  3322,  3328,  3328,  3330,  3333,
    3336,  3342,  3342,  3344,  3347,  3370,  3376,  3384,  3390,  3403,
    3412,  3418,  3426,  3432,  3438,  3444,  3450,  3456,  3464,  3470,
    3478,  3483,  3489,  3515,  3520,  3522,  3522,  3524,  3526,  3535,
    3537,  3537,  3539,  3539,  3541,  3549,  3551,  3556,  3556,  3558,
    3558,  3560,  3583,  3591,  3605,  3606,  3609,  3610,  3611,  3613,
    3615,  3615,  3617,  3618,  3619,  3620
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
  "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT", "HEADERSTART",
  "HEADEREND", "GENERALSTART", "GENERALEND", "SYSTEMSTART", "SYSTEMEND",
  "SERVICESTART", "SERVICEEND", "JOBSTART", "JOBEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "ITEMSTART", "ITEMEND", "ITEMSTARTANDEND",
  "ITEMEMPTY", "FILENAMESTART", "FILENAMEEND", "FILENAMEEMPTY",
  "FILENAMESTARTANDEND", "FILESOURCESTART", "FILESOURCEEND",
  "FILESOURCEEMPTY", "FILESOURCESTARTANDEND", "FILEDESCRIPTIONSTART",
  "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
  "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART", "FILECREATOREND",
  "FILECREATOREMPTY", "FILECREATORSTARTANDEND", "FILELICENCESTART",
  "FILELICENCEEND", "FILELICENCEEMPTY", "FILELICENCESTARTANDEND",
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
  "'\\r'", "'\\n'", "$accept", "osrldoc", "osrlStartEmpty", "osrlStart",
  "osrlAttributes", "osrlContent", "osrlEmpty", "osrlLaden", "osrlBody",
  "headerElement", "headerElementStart", "headerElementContent",
  "headerElementEmpty", "headerElementLaden", "headerElementBody",
  "fileName", "fileNameContent", "fileNameEmpty", "fileNameLaden",
  "fileSource", "fileSourceContent", "fileSourceEmpty", "fileSourceLaden",
  "fileDescription", "fileDescriptionContent", "fileDescriptionEmpty",
  "fileDescriptionLaden", "fileCreator", "fileCreatorContent",
  "fileCreatorEmpty", "fileCreatorLaden", "fileLicence",
  "fileLicenceContent", "fileLicenceEmpty", "fileLicenceLaden",
  "generalElement", "generalElementStart", "generalElementContent",
  "generalElementEmpty", "generalElementLaden", "generalElementBody",
  "generalElementList", "generalChild", "generalStatus",
  "generalStatusStart", "generalStatusAttributes", "generalStatusAttList",
  "generalStatusATT", "generalStatusContent", "generalStatusEmpty",
  "generalStatusLaden", "generalStatusBody", "generalSubstatusArray",
  "generalSubstatus", "generalSubstatusStart",
  "generalSubstatusAttributes", "generalSubstatusAttList",
  "generalSubstatusATT", "generalSubstatusEnd", "generalMessage",
  "generalMessageStart", "generalMessageContent", "generalMessageEmpty",
  "generalMessageLaden", "generalMessageBody", "serviceURI",
  "serviceURIStart", "serviceURIContent", "serviceURIEmpty",
  "serviceURILaden", "serviceURIBody", "serviceName", "serviceNameStart",
  "serviceNameContent", "serviceNameEmpty", "serviceNameLaden",
  "serviceNameBody", "instanceName", "instanceNameStart",
  "instanceNameContent", "instanceNameEmpty", "instanceNameLaden",
  "instanceNameBody", "jobID", "jobIDStart", "jobIDContent", "jobIDEmpty",
  "jobIDLaden", "jobIDBody", "solverInvoked", "solverInvokedStart",
  "solverInvokedContent", "solverInvokedEmpty", "solverInvokedLaden",
  "solverInvokedBody", "timeStamp", "timeStampStart", "timeStampContent",
  "timeStampEmpty", "timeStampLaden", "timeStampBody",
  "otherGeneralResults", "otherGeneralResultsStart",
  "otherGeneralResultsAttributes", "otherGeneralResultsContent",
  "otherGeneralResultsEmpty", "otherGeneralResultsLaden",
  "otherGeneralResultsBody", "otherGeneralResultArray",
  "otherGeneralResult", "otherGeneralResultStart",
  "otherGeneralResultAttributes", "otherGeneralResultAttList",
  "otherGeneralResultAtt", "otherGeneralResultEnd", "systemElement",
  "systemElementStart", "systemElementContent", "systemElementEmpty",
  "systemElementLaden", "systemElementBody", "systemElementList",
  "systemChild", "systemInformation", "systemInformationStart",
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
  "otherSystemResults", "otherSystemResultsStart",
  "otherSystemResultsAttributes", "otherSystemResultsContent",
  "otherSystemResultsEmpty", "otherSystemResultsLaden",
  "otherSystemResultsBody", "otherSystemResultArray", "otherSystemResult",
  "otherSystemResultStart", "otherSystemResultAttributes",
  "otherSystemResultAttList", "otherSystemResultAtt",
  "otherSystemResultEnd", "serviceElement", "serviceElementStart",
  "serviceElementContent", "serviceElementEmpty", "serviceElementLaden",
  "serviceElementBody", "serviceElementList", "serviceChild",
  "currentState", "currentStateStart", "currentStateContent",
  "currentStateEmpty", "currentStateLaden", "currentStateBody",
  "currentJobCount", "currentJobCountStart", "currentJobCountContent",
  "currentJobCountEmpty", "currentJobCountLaden", "currentJobCountBody",
  "totalJobsSoFar", "totalJobsSoFarStart", "totalJobsSoFarContent",
  "totalJobsSoFarEmpty", "totalJobsSoFarLaden", "totalJobsSoFarBody",
  "timeServiceStarted", "timeServiceStartedStart",
  "timeServiceStartedContent", "timeServiceStartedEmpty",
  "timeServiceStartedLaden", "timeServiceStartedBody",
  "serviceUtilization", "serviceUtilizationStart",
  "serviceUtilizationContent", "serviceUtilizationEmpty",
  "serviceUtilizationLaden", "serviceUtilizationBody",
  "otherServiceResults", "otherServiceResultsStart",
  "otherServiceResultsAttributes", "otherServiceResultsContent",
  "otherServiceResultsEmpty", "otherServiceResultsLaden",
  "otherServiceResultsBody", "otherServiceResultArray",
  "otherServiceResult", "otherServiceResultStart",
  "otherServiceResultAttributes", "otherServiceResultAttList",
  "otherServiceResultAtt", "otherServiceResultEnd", "jobElement",
  "jobElementStart", "jobElementContent", "jobElementEmpty",
  "jobElementLaden", "jobElementBody", "jobElementList", "jobChild",
  "jobStatus", "jobStatusStart", "jobStatusContent", "jobStatusEmpty",
  "jobStatusLaden", "jobStatusBody", "submitTime", "submitTimeStart",
  "submitTimeContent", "submitTimeEmpty", "submitTimeLaden",
  "submitTimeBody", "scheduledStartTime", "scheduledStartTimeStart",
  "scheduledStartTimeContent", "scheduledStartTimeEmpty",
  "scheduledStartTimeLaden", "scheduledStartTimeBody", "actualStartTime",
  "actualStartTimeStart", "actualStartTimeContent", "actualStartTimeEmpty",
  "actualStartTimeLaden", "actualStartTimeBody", "endTime", "endTimeStart",
  "endTimeContent", "endTimeEmpty", "endTimeLaden", "endTimeBody",
  "timingInformation", "timingInformationStart",
  "timingInformationAttributes", "timingInformationContent",
  "timingInformationEmpty", "timingInformationLaden",
  "timingInformationBody", "timeArray", "time", "timeStart",
  "timeAttributes", "timeAtt", "timeContent", "timeEmpty", "timeLaden",
  "timeBody", "timeValue", "usedDiskSpace", "usedDiskSpaceStart",
  "usedDiskSpaceAttributes", "usedDiskSpaceAttList", "usedDiskSpaceAtt",
  "usedDiskSpaceContent", "usedDiskSpaceValue", "usedMemory",
  "usedMemoryStart", "usedMemoryAttributes", "usedMemoryAttList",
  "usedMemoryAtt", "usedMemoryContent", "usedMemoryValue", "usedCPUSpeed",
  "usedCPUSpeedStart", "usedCPUSpeedAttributes", "usedCPUSpeedAttList",
  "usedCPUSpeedAtt", "usedCPUSpeedContent", "usedCPUSpeedValue",
  "usedCPUNumber", "usedCPUNumberStart", "usedCPUNumberAttributes",
  "usedCPUNumberContent", "usedCPUNumberValue", "otherJobResults",
  "otherJobResultsStart", "otherJobResultsAttributes",
  "otherJobResultsContent", "otherJobResultsEmpty", "otherJobResultsLaden",
  "otherJobResultsBody", "otherJobResultArray", "otherJobResult",
  "otherJobResultStart", "otherJobResultAttributes",
  "otherJobResultAttList", "otherJobResultAtt", "otherJobResultEnd",
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
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   220,   221,   221,   222,   223,   224,   224,   225,   225,
     226,   227,   228,   229,   229,   230,   231,   231,   232,   233,
     234,   235,   235,   236,   236,   237,   237,   238,   239,   239,
     240,   240,   241,   241,   242,   243,   243,   244,   244,   245,
     245,   246,   247,   247,   248,   248,   249,   249,   250,   251,
     251,   252,   252,   253,   253,   254,   255,   255,   256,   257,
     257,   258,   258,   259,   260,   261,   261,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   263,   264,   265,   266,
     266,   267,   267,   267,   268,   268,   269,   269,   270,   271,
     272,   272,   273,   274,   275,   276,   276,   277,   277,   278,
     278,   279,   280,   281,   281,   282,   282,   283,   284,   285,
     286,   287,   287,   288,   288,   289,   290,   291,   292,   293,
     293,   294,   294,   295,   296,   297,   298,   299,   299,   300,
     300,   301,   302,   303,   304,   305,   305,   306,   306,   307,
     308,   309,   310,   311,   311,   312,   312,   313,   314,   315,
     316,   317,   317,   318,   318,   319,   320,   321,   322,   323,
     324,   324,   325,   325,   326,   327,   328,   328,   329,   330,
     331,   332,   332,   333,   333,   333,   334,   334,   335,   335,
     336,   337,   337,   338,   338,   339,   340,   341,   341,   342,
     342,   342,   342,   342,   342,   343,   344,   345,   345,   346,
     346,   347,   348,   349,   350,   351,   352,   352,   353,   353,
     354,   355,   356,   357,   358,   359,   359,   360,   360,   361,
     362,   363,   364,   365,   366,   366,   367,   367,   368,   369,
     370,   371,   372,   372,   373,   374,   375,   376,   377,   378,
     378,   379,   379,   380,   381,   382,   382,   383,   384,   385,
     386,   386,   387,   387,   387,   388,   388,   389,   389,   390,
     391,   391,   392,   392,   393,   394,   395,   395,   396,   396,
     396,   396,   396,   396,   397,   398,   399,   399,   400,   400,
     401,   402,   403,   404,   405,   405,   406,   406,   407,   408,
     409,   410,   411,   411,   412,   412,   413,   414,   415,   416,
     417,   417,   418,   418,   419,   420,   421,   422,   423,   423,
     424,   424,   425,   426,   427,   428,   429,   430,   430,   431,
     431,   432,   433,   434,   434,   435,   436,   437,   438,   438,
     439,   439,   439,   440,   440,   441,   441,   442,   443,   443,
     444,   444,   445,   446,   447,   447,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   449,   450,   451,
     451,   452,   452,   453,   454,   455,   456,   457,   457,   458,
     458,   459,   460,   461,   462,   463,   463,   464,   464,   465,
     466,   467,   468,   469,   469,   470,   470,   471,   472,   473,
     474,   475,   475,   476,   476,   477,   478,   479,   480,   481,
     482,   482,   483,   483,   484,   485,   486,   486,   487,   488,
     489,   489,   490,   490,   490,   490,   491,   491,   492,   492,
     493,   494,   495,   495,   496,   497,   498,   499,   499,   500,
     500,   501,   502,   503,   504,   505,   506,   506,   507,   507,
     508,   509,   510,   511,   512,   513,   513,   514,   514,   515,
     516,   517,   518,   519,   519,   520,   521,   522,   523,   524,
     525,   525,   526,   526,   527,   528,   529,   529,   530,   531,
     532,   533,   533,   534,   534,   534,   535,   535,   536,   536,
     537,   538,   539,   539,   540,   540,   540,   540,   541,   541,
     542,   542,   543,   544,   545,   545,   546,   547,   548,   549,
     549,   550,   550,   551,   552,   553,   554,   555,   556,   557,
     557,   558,   558,   558,   559,   559,   560,   560,   561,   562,
     563,   563,   564,   565,   566,   567,   567,   568,   568,   569,
     569,   570,   570,   571,   572,   572,   573,   573,   574,   575,
     576,   576,   577,   578,   578,   579,   579,   580,   581,   582,
     583,   583,   584,   585,   586,   586,   587,   587,   588,   589,
     590,   590,   591,   592,   593,   594,   595,   595,   596,   597,
     598,   598,   599,   599,   600,   601,   602,   602,   603,   604,
     605,   606,   606,   607,   607,   608,   609,   610,   610,   611,
     612,   612,   613,   614,   615,   616,   616,   617,   618,   619,
     619,   620,   621,   622,   623,   623,   624,   625,   626,   626,
     627,   628,   629,   630,   630,   631,   632,   633,   633,   634,
     635,   636,   637,   637,   638,   639,   640,   640,   641,   642,
     643,   644,   644,   645,   646,   647,   647,   648,   649,   650,
     651,   651,   652,   653,   654,   654,   655,   656,   657,   658,
     658,   659,   660,   661,   662,   662,   663,   663,   663,   663,
     663,   664,   664,   665,   665,   666,   667,   667,   668,   668,
     669,   670,   671,   672,   672,   673,   673,   674,   675,   676,
     676,   677,   678,   679,   680,   680,   681,   681,   681,   682,
     682,   683,   684,   685,   686,   686,   687,   688,   688,   689,
     689,   690,   691,   692,   693,   693,   694,   695,   696,   696,
     697,   697,   698,   699,   700,   700,   701,   702,   703,   703,
     704,   705,   705,   706,   706,   707,   708,   708,   709,   710,
     711,   712,   712,   713,   714,   715,   715,   716,   717,   718,
     719,   719,   720,   721,   722,   722,   723,   724,   725,   726,
     726,   727,   728,   729,   729,   730,   731,   732,   733,   733,
     734,   735,   736,   736,   737,   738,   739,   740,   740,   741,
     742,   743,   743,   744,   745,   746,   747,   747,   748,   749,
     750,   750,   751,   752,   753,   754,   754,   755,   756,   757,
     758,   758,   759,   759,   759,   759,   759,   760,   760,   761,
     761,   762,   763,   763,   764,   764,   765,   766,   767,   768,
     768,   769,   769,   770,   771,   772,   772,   773,   774,   775,
     776,   776,   777,   777,   777,   778,   778,   779,   780,   781,
     782,   782,   783,   784,   784,   785,   785,   786,   787,   788,
     789,   789,   790,   791,   792,   792,   793,   793,   794,   795,
     796,   796,   797,   798,   799,   800,   801,   801,   802,   803,
     803,   804,   805,   806,   807,   807,   808,   809,   810,   810,
     811,   812,   813,   814,   814,   815,   816,   817,   817,   818,
     819,   820,   821,   821,   822,   823,   824,   824,   825,   826,
     827,   828,   828,   829,   830,   831,   831,   832,   833,   834,
     835,   835,   836,   837,   838,   838,   839,   840,   841,   842,
     842,   843,   844,   845,   845,   846,   847,   848,   849,   849,
     850,   851,   852,   853,   853,   854,   854,   854,   854,   854,
     855,   855,   856,   856,   857,   858,   858,   859,   859,   860,
     861,   862,   863,   863,   864,   864,   865,   866,   867,   867,
     868,   869,   870,   871,   871,   872,   872,   872,   873,   873,
     874,   875,   876,   877,   877,   878,   879,   880,   880,   881,
     881,   882,   883,   884,   884,   885,   886,   887,   888,   888,
     889,   889,   889,   889,   890,   890,   891,   891,   892,   893,
     894,   894,   895,   896,   896,   897,   897,   898,   899,   900,
     900,   901,   902,   903,   903,   904,   904,   905,   906,   907,
     907,   908,   909,   910,   911,   911,   912,   912,   912,   912,
     913,   913,   914,   914,   915,   916,   917,   917,   918,   919,
     919,   920,   920,   921,   922,   923,   924,   924,   925,   926,
     927,   928,   928,   929,   930,   931,   932,   932,   933,   934,
     935,   936,   936,   937,   938,   939,   940,   940,   941,   942,
     943,   944,   944,   945,   946,   947,   948,   949,   950,   951,
     952,   953,   954,   955,   956,   957,   958,   959,   960,   961,
     962,   963,   964,   965,   965,   966,   966,   967,   968,   969,
     970,   970,   971,   971,   972,   973,   974,   975,   975,   976,
     976,   977,   978,   979,   980,   980,   981,   981,   981,   982,
     983,   983,   984,   984,   984,   984
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     6,     0,     2,     1,     1,     1,     1,     3,
       5,     0,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     1,     1,     1,     3,     0,     2,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     2,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     2,     1,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     1,     0,     2,     1,     1,     3,
       1,     3,     1,     1,     0,     2,     1,     1,     3,     1,
       3,     1,     0,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     2,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     3,     1,     1,     0,     2,     1,
       1,     3,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     1,     0,     2,     1,     1,     3,
       1,     3,     1,     0,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     2,     1,     0,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     2,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     4,     3,     8,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     2,
       1,     0,     2,     1,     1,     1,     2,     1,     3,     1,
       0,     3,     1,     0,     1,     1,     1,     1,     3,     4,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     4,     3,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       4,     1,     1,     2,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     3,     6,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     2,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     0,     1,     1,
       1,     1,     3,     3,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     0,     4,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     3,
       6,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     1,     2,     3,     1,     4,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     0,     1,     1,     1,     1,     3,     3,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     4,     3,     0,     2,     1,     1,
       1,     1,     3,     6,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     2,     3,
       1,     4,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     3,     3,     4,     1,     1,     2,
       1,     3,     4,     4,     1,     1,     1,     1,     1,     2,
       0,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    13,     6,     1,    15,     0,    56,
       0,     7,     0,     2,    58,   178,     0,    21,    18,    14,
      16,    17,    13,    10,     3,     8,     9,   180,   257,     0,
       0,    62,    57,    59,    60,     0,    26,    25,     0,    28,
      22,    23,    24,     0,   259,   335,     0,     0,   184,   179,
     181,   182,    61,    77,   126,   134,   102,   158,   118,   110,
     142,   150,     0,    64,    65,    67,     0,    68,     0,    69,
       0,    70,     0,    71,     0,    72,     0,    73,     0,    74,
       0,    75,     0,     0,    19,     0,    33,    32,    35,    29,
      30,    31,    11,   337,   478,     0,     0,   263,   258,   260,
     261,   183,   231,   222,   204,   213,   237,   196,     0,   186,
     187,   189,     0,   190,   206,   191,   215,   192,   224,   193,
     232,   194,     0,    63,    66,  1110,     0,  1043,     0,  1053,
       0,    78,    79,    82,  1040,  1041,  1042,    81,  1050,  1051,
    1052,    83,     0,   106,   101,   103,   104,     0,   114,   109,
     111,   112,     0,   122,   117,   119,   120,     0,   130,   125,
     127,   128,     0,   138,   133,   135,   136,     0,   146,   141,
     143,   144,     0,   154,   149,   151,   152,  1110,     0,   159,
      27,     0,     0,    40,    39,    42,    36,    37,    38,   480,
      12,   482,     0,   341,   336,   338,   339,   262,   283,   275,
     315,   307,   299,   291,     0,   265,   266,   268,     0,   269,
       0,   270,     0,   271,     0,   272,     0,   273,     0,   185,
     188,     0,   200,   195,   197,   198,     0,   205,     0,   214,
       0,   223,     0,   233,     0,   238,     0,     0,  1110,  1110,
       0,    87,    76,    84,    85,    80,   108,   105,     0,   116,
     113,     0,   124,   121,     0,   132,   129,     0,   140,   137,
       0,   148,   145,     0,   156,   153,     0,     0,     0,   163,
     157,   160,   161,    34,     0,     0,    47,    46,    49,    43,
      44,    45,     0,   481,   340,   382,   390,   458,   374,   358,
     366,   398,   452,   443,   425,   434,     0,   343,   344,   346,
       0,   347,     0,   348,     0,   349,     0,   350,     0,   351,
       0,   352,   427,   353,   436,   354,   445,   355,   453,   356,
       0,   264,   267,     0,   279,   274,   276,   277,     0,   287,
     282,   284,   285,     0,   295,   290,   292,   293,     0,   303,
     298,   300,   301,     0,   311,   306,   308,   309,     0,   316,
     202,   199,     0,     0,   203,     0,  1058,   207,   209,   208,
    1055,  1056,  1057,     0,   212,   216,   218,   217,     0,   221,
     225,   227,   226,     0,   230,     0,   242,   236,   239,   240,
    1110,  1109,  1112,  1113,  1114,  1115,  1111,  1044,  1054,    86,
      93,     0,    89,    90,    95,   107,   115,   123,   131,   139,
     147,   155,  1110,   169,   162,     0,   165,   166,   171,    41,
       0,     0,    54,    53,    20,    50,    51,    52,     0,   491,
     479,   488,   489,  1110,  1110,  1110,  1110,   483,   486,   487,
     484,   485,   342,   345,     0,   362,   357,   359,   360,     0,
     370,   365,   367,   368,     0,   378,   373,   375,   376,     0,
     386,   381,   383,   384,     0,   394,   389,   391,   392,  1110,
       0,   399,     0,   426,     0,   435,     0,   444,     0,   454,
       0,   459,   281,   278,     0,   289,   286,     0,   297,   294,
       0,   305,   302,     0,  1104,  1105,   310,     0,   313,     0,
     320,   314,   317,   318,   201,     0,   211,  1110,     0,   220,
       0,   229,   235,     0,   248,   241,     0,   244,   245,   250,
    1079,    88,    91,     0,    94,  1074,   164,   167,     0,   170,
      48,     0,   490,   497,     0,   999,   494,   499,     0,     0,
       0,     0,   364,   361,     0,   372,   369,     0,   380,   377,
       0,   388,   385,     0,   396,   393,     0,     0,     0,   403,
     397,   400,   401,     0,   424,   428,   430,   429,     0,   433,
     437,   439,   438,     0,   442,   446,   448,   447,     0,   451,
       0,   463,   457,   460,   461,   280,   288,   296,   304,   312,
     326,   319,     0,   322,   323,   328,   210,  1059,   219,   228,
     234,   243,   246,     0,   249,     0,   100,    92,     0,  1048,
      96,    98,    97,  1045,  1046,  1047,     0,   177,   168,     0,
    1063,   172,   175,   173,   174,  1060,  1061,  1062,    55,   492,
    1001,   495,   493,     0,     0,   498,  1110,  1110,  1110,  1110,
     363,   371,   379,   387,   395,  1110,   409,   402,     0,   405,
     406,   410,     0,   432,     0,   441,     0,   450,   456,     0,
     469,   462,     0,   465,   466,   471,   321,   324,     0,   327,
       0,   256,   247,   251,   254,   252,   253,    99,  1110,   176,
    1110,  1110,     0,  1002,     0,   496,  1110,     0,   500,   501,
     502,  1066,  1071,  1077,  1082,  1080,   404,   407,     0,   431,
     440,   449,   455,   464,   467,     0,   470,     0,   334,   325,
     329,   332,   330,   331,   255,  1049,  1064,     0,     0,  1006,
    1000,  1003,  1004,   507,   531,     0,     0,  1110,     0,   419,
       0,  1038,   411,   408,   416,   417,   414,  1035,  1036,  1037,
     415,   413,   412,     0,   477,   468,   472,   475,   473,   474,
     333,  1110,  1005,  1012,     0,  1008,  1009,  1014,   533,   540,
       0,     0,   508,   509,   512,   511,   513,  1110,   504,   423,
     422,   418,     0,   421,  1110,   476,  1078,  1007,  1010,     0,
    1013,   542,   694,   543,     0,   537,   532,   534,   535,     0,
     517,   506,   514,   515,   510,   503,   420,  1039,     0,  1023,
    1011,  1020,  1021,  1110,  1015,  1017,  1018,  1016,  1019,   696,
     830,   697,  1110,     0,   544,   539,   536,     0,   516,   523,
       0,   519,   520,   525,     0,  1031,  1032,  1022,     0,  1025,
    1026,  1028,  1029,  1030,     0,   832,   963,   833,  1110,     0,
     698,     0,   550,   547,   541,   545,   546,   538,   518,   521,
       0,   524,  1034,     0,  1024,  1027,  1110,   965,     0,     0,
    1110,     0,   834,     0,   704,   701,   695,   699,   700,  1110,
     552,     0,   566,     0,     0,   530,   522,   526,   528,   527,
    1033,  1069,   505,  1110,     0,   966,     0,   840,   837,   831,
     835,   836,  1110,   706,     0,   723,     0,  1076,   548,   568,
     587,     0,  1110,     0,   553,   529,     0,     0,   970,   964,
     967,   968,  1110,   842,     0,   856,     0,  1073,   702,   725,
     785,     0,  1110,     0,   707,   589,   649,     0,     0,   569,
       0,     0,   557,   551,   554,   555,  1110,   976,   969,     0,
     972,   973,   978,  1072,   838,   858,   918,     0,  1110,     0,
     843,   703,   731,   728,   724,   726,   727,     0,     0,   711,
     705,   708,   709,   549,   595,   592,   588,   590,   591,     0,
     573,   567,   570,   571,  1110,   556,   563,     0,   559,   560,
       0,  1075,   971,   974,     0,   977,   839,   864,   861,   857,
     859,   860,     0,     0,   847,   841,   844,   845,   788,   786,
     790,   733,     0,   740,     0,  1110,   717,   710,     0,   713,
     714,   718,   652,   650,   654,   597,     0,   604,     0,   572,
     579,     0,   575,   576,     0,  1081,   558,   561,  1110,     0,
       0,   987,   975,   984,   985,   979,   981,   982,   980,   983,
     921,   919,   923,   866,     0,   873,     0,  1110,   853,   846,
       0,   849,   850,     0,     0,   789,   729,   742,   749,     0,
    1110,     0,   734,  1070,   712,   715,  1110,     0,     0,   653,
     593,   606,   613,     0,     0,   598,   574,   577,  1110,     0,
       0,     0,   562,     0,   995,   996,   986,     0,   989,   990,
     992,   993,   994,     0,   922,   862,   875,   882,     0,     0,
     867,  1065,   848,   851,  1110,     0,     0,   800,   787,   797,
     798,  1110,   791,   796,   795,   794,   793,   792,   751,   758,
       0,     0,   743,     0,  1085,   737,   732,   735,   736,     0,
       0,   716,     0,   664,   651,   661,   662,   655,   660,   659,
     658,   657,   656,   615,   622,     0,     0,   607,  1085,   601,
     596,   599,   600,     0,     0,   584,   578,   581,   582,  1110,
       0,   998,     0,   988,   991,     0,   933,   920,   930,   931,
     924,   929,   928,   927,   925,   926,   884,   891,     0,     0,
     876,  1085,   870,   865,   868,   869,     0,     0,   852,   818,
     807,   799,     0,   802,   804,     0,   803,   815,   820,     0,
     760,   767,     0,     0,   752,  1085,   746,   741,   744,   745,
    1110,     0,     0,   739,  1083,  1084,  1110,   721,   722,     0,
     682,   663,   671,     0,   666,   668,     0,   667,   679,   684,
     624,   631,     0,     0,   616,  1085,   610,   605,   608,   609,
       0,   603,  1110,   586,   583,     0,   564,   565,   997,   940,
     951,   932,     0,   935,   937,     0,   936,   948,   953,   893,
     900,     0,     0,   885,  1085,   879,   874,   877,   878,     0,
     872,  1110,     0,   801,   805,  1110,     0,   816,     0,   819,
    1110,   769,   776,     0,     0,   761,  1085,   755,   750,   753,
     754,     0,   748,  1067,  1110,     0,   738,  1088,  1086,  1090,
     719,   720,   665,   669,  1110,     0,   680,     0,   683,   633,
     640,     0,     0,   625,  1085,   619,   614,   617,   618,     0,
     612,   602,   580,   585,   934,   938,  1110,     0,   949,     0,
     952,   902,   909,     0,     0,   894,  1085,   888,   883,   886,
     887,     0,   881,   871,   854,   855,     0,     0,   812,   806,
     809,   810,  1085,   827,   817,   825,   826,   821,   824,   823,
     822,  1068,   778,   730,     0,     0,   770,  1085,   764,   759,
     762,   763,     0,   757,   747,     0,     0,  1100,  1095,  1097,
    1098,     0,  1089,     0,     0,   676,   670,   673,   674,  1085,
     691,   681,   689,   690,   685,   688,   687,   686,   642,   594,
       0,     0,   634,  1085,   628,   623,   626,   627,     0,   621,
     611,     0,     0,   945,   939,   942,   943,  1085,   960,   950,
     958,   959,   954,   957,   956,   955,   911,   863,     0,     0,
     903,  1085,   897,   892,   895,   896,     0,   890,   880,  1110,
    1106,  1107,  1108,   811,     0,   814,     0,   829,     0,   779,
    1085,   773,   768,   771,   772,     0,   766,   756,  1110,     0,
    1099,     0,  1087,  1110,  1110,  1091,  1093,  1092,  1110,   675,
       0,   678,     0,   693,     0,   643,  1085,   637,   632,   635,
     636,     0,   630,   620,  1110,   944,     0,   947,     0,   962,
       0,   912,  1085,   906,   901,   904,   905,     0,   899,   889,
     808,   813,   828,  1085,   782,   777,   780,   781,     0,   775,
     765,  1096,  1101,     0,     0,     0,   672,   677,   692,  1085,
     646,   641,   644,   645,     0,   639,   629,   941,   946,   961,
    1085,   915,   910,   913,   914,     0,   908,   898,     0,   784,
     774,  1094,  1110,  1110,     0,   648,   638,     0,   917,   907,
     783,  1102,  1103,   647,   916
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    24,    25,    26,     8,     9,
      10,    19,    20,    21,    38,    39,    40,    41,    42,    88,
      89,    90,    91,   185,   186,   187,   188,   278,   279,   280,
     281,   414,   415,   416,   417,    15,    16,    32,    33,    34,
      62,    63,    64,    65,    66,   130,   131,   132,   242,   243,
     244,   391,   392,   393,   394,   513,   514,   600,   597,    67,
      68,   144,   145,   146,   248,    69,    70,   149,   150,   151,
     251,    71,    72,   154,   155,   156,   254,    73,    74,   159,
     160,   161,   257,    75,    76,   164,   165,   166,   260,    77,
      78,   169,   170,   171,   263,    79,    80,   174,   175,   176,
     266,    81,    82,   178,   270,   271,   272,   405,   406,   407,
     408,   518,   519,   611,   608,    28,    29,    49,    50,    51,
     108,   109,   110,   111,   112,   223,   224,   225,   352,   113,
     114,   226,   227,   357,   354,   495,   115,   116,   228,   229,
     365,   364,   498,   117,   118,   230,   231,   370,   369,   500,
     119,   120,   232,   374,   503,   121,   122,   234,   377,   378,
     379,   506,   507,   508,   509,   593,   594,   663,   662,    45,
      46,    98,    99,   100,   204,   205,   206,   207,   208,   325,
     326,   327,   474,   209,   210,   330,   331,   332,   477,   211,
     212,   335,   336,   337,   480,   213,   214,   340,   341,   342,
     483,   215,   216,   345,   346,   347,   487,   217,   218,   348,
     491,   492,   493,   582,   583,   584,   585,   658,   659,   700,
     699,    94,    95,   194,   195,   196,   296,   297,   298,   299,
     300,   436,   437,   438,   534,   301,   302,   441,   442,   443,
     537,   303,   304,   446,   447,   448,   540,   305,   306,   451,
     452,   453,   543,   307,   308,   456,   457,   458,   546,   309,
     310,   460,   550,   551,   552,   638,   639,   640,   641,   688,
     722,   723,   724,   725,   762,   763,   311,   312,   462,   463,
     555,   554,   642,   313,   314,   464,   465,   560,   559,   644,
     315,   316,   466,   467,   565,   564,   646,   317,   318,   468,
     569,   649,   319,   320,   470,   572,   573,   574,   652,   653,
     654,   655,   695,   696,   736,   735,   190,   191,   282,   283,
     427,   420,   421,   422,   524,   525,   526,   527,   624,   625,
     678,   679,   680,   675,   714,   715,   751,   752,   753,   781,
     782,   783,   810,   811,   812,   813,   840,   841,   867,   866,
     749,   750,   776,   777,   778,   807,   772,   773,   803,   834,
     835,   836,   861,   862,   863,   893,   923,   924,   925,   967,
     968,   969,   970,  1019,  1072,   890,   891,   918,   961,   962,
     963,  1011,  1012,  1013,  1014,  1069,  1146,  1147,  1148,  1235,
     916,   917,   956,   957,   958,  1006,  1007,  1008,  1064,  1140,
    1141,  1142,  1230,  1062,  1063,  1136,  1227,  1228,  1229,  1309,
    1134,  1135,  1223,  1306,  1307,  1308,  1398,  1221,  1222,  1302,
    1395,  1396,  1397,  1471,  1300,  1301,  1391,  1468,  1469,  1470,
    1514,  1389,  1390,  1464,  1511,  1512,  1513,  1534,   953,  1003,
    1004,  1058,  1059,  1127,  1124,  1125,  1126,  1213,  1214,  1215,
    1216,  1295,  1376,  1377,  1378,  1460,  1217,  1218,  1219,  1297,
    1298,  1384,  1381,  1382,  1383,  1462,   800,   801,   829,   856,
     857,   858,   884,   885,   886,   913,   950,   951,   952,   998,
     999,  1000,  1001,  1057,  1121,  1209,   910,   911,   944,   945,
     946,   992,   993,   994,  1051,  1116,  1117,  1118,  1202,  1048,
    1049,  1111,  1197,  1198,  1199,  1281,  1109,  1110,  1193,  1278,
    1279,  1280,  1362,  1191,  1192,  1274,  1359,  1360,  1361,  1445,
    1272,  1273,  1355,  1442,  1443,  1444,  1498,  1353,  1354,  1438,
    1495,  1496,  1497,  1528,   941,   989,   990,  1044,  1045,  1102,
    1098,  1099,  1100,  1182,  1183,  1184,  1185,  1266,  1339,  1340,
    1341,  1434,  1186,  1187,  1188,  1268,  1269,  1347,  1344,  1345,
    1346,  1436,   826,   827,   851,   879,   880,   881,   904,   905,
     906,   939,   985,   986,   987,  1040,  1041,  1042,  1043,  1095,
    1178,   936,   937,   979,   980,   981,  1034,  1035,  1036,  1089,
    1173,  1174,  1175,  1259,  1087,  1088,  1169,  1256,  1257,  1258,
    1331,  1167,  1168,  1252,  1328,  1329,  1330,  1426,  1250,  1251,
    1324,  1423,  1424,  1425,  1487,  1322,  1323,  1419,  1484,  1485,
    1486,  1525,  1417,  1418,  1480,  1522,  1523,  1524,  1537,   976,
    1031,  1032,  1083,  1084,  1160,  1157,  1158,  1159,  1242,  1243,
    1244,  1245,  1317,  1404,  1405,  1406,  1476,  1246,  1247,  1248,
    1319,  1320,  1412,  1409,  1410,  1411,  1478,   848,   849,   874,
     899,   900,   901,   929,   930,   931,   932,   974,   975,  1025,
    1022,  1023,  1024,  1077,  1078,  1079,  1080,  1081,  1082,  1152,
     622,   623,   672,   710,   711,   712,   744,   745,   746,   747,
     769,   770,   794,   790,   791,   792,   818,   819,   820,   821,
     822,   823,   843,   726,   727,   728,   729,   133,   134,   135,
     136,   602,   603,   604,   605,   137,   138,   139,   140,   359,
     360,   361,   362,   614,   615,   616,   617,   940,   428,  1052,
    1106,   798,   914,   429,   852,   830,   179,   875,   804,   430,
     673,   141,   461,   894,   431,  1203,  1204,  1288,  1289,  1371,
    1372,  1455,  1452,  1205,  1285,  1368,  1369,  1370,  1456,  1457,
     488,  1435,   236,   237,   386
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1322
static const yytype_int16 yypact[] =
{
     155, -1322, -1322,    63,    39,    91, -1322, -1322,   103,    67,
     361, -1322,   363, -1322, -1322,    71,   375,    85, -1322, -1322,
   -1322, -1322,    39, -1322, -1322, -1322, -1322, -1322,    81,   384,
      -8, -1322, -1322, -1322, -1322,   143, -1322, -1322,    88,   145,
   -1322, -1322, -1322,   137, -1322,   106,   388,   -17, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322,    96,   189, -1322, -1322,   208, -1322,   403, -1322,
     407, -1322,   415, -1322,   417, -1322,   421, -1322,   423, -1322,
     425, -1322,   157,   100, -1322,   203, -1322, -1322,   195, -1322,
   -1322, -1322, -1322, -1322,   147,   427,    -3, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   167,   -30,
   -1322, -1322,   429, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
     190, -1322,   157, -1322, -1322, -1322,   242, -1322,   255, -1322,
     431,   208, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322,    35, -1322, -1322, -1322, -1322,    27, -1322, -1322,
   -1322, -1322,    28, -1322, -1322, -1322, -1322,    40, -1322, -1322,
   -1322, -1322,    31, -1322, -1322, -1322, -1322,    26, -1322, -1322,
   -1322, -1322,     9, -1322, -1322, -1322, -1322, -1322,   433, -1322,
   -1322,   184,   265, -1322, -1322,   231, -1322, -1322, -1322, -1322,
   -1322, -1322,    82, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322,   210,   146, -1322, -1322,   435, -1322,
     437, -1322,   443, -1322,   450, -1322,   454, -1322,   157, -1322,
   -1322,    18, -1322, -1322, -1322, -1322,   270,   187,   279,   187,
     305,   187,   309, -1322,   456, -1322,   285,    -1, -1322, -1322,
     -62, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   179, -1322,
   -1322,   161, -1322, -1322,   159, -1322, -1322,   193, -1322, -1322,
     191, -1322, -1322,   163, -1322, -1322,   151,   338,   -13, -1322,
   -1322, -1322, -1322, -1322,   266,   343, -1322, -1322,   268, -1322,
   -1322, -1322,   458,   105, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322,   313,   135, -1322, -1322,
     461, -1322,   463, -1322,   467, -1322,   469, -1322,   471, -1322,
     370, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   190, -1322,
     157, -1322, -1322,    41, -1322, -1322, -1322, -1322,    42, -1322,
   -1322, -1322, -1322,    13, -1322, -1322, -1322, -1322,    16, -1322,
   -1322, -1322, -1322,    21, -1322, -1322, -1322, -1322,   473, -1322,
   -1322, -1322,   235,   479, -1322,   452, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322,   479, -1322, -1322, -1322, -1322,   479, -1322,
   -1322, -1322, -1322,   451, -1322,    78, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322,   332,   319, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322,   321,   341, -1322, -1322, -1322,
     444,   537, -1322, -1322, -1322, -1322, -1322, -1322,   -20, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322,    20, -1322, -1322, -1322, -1322,    17,
   -1322, -1322, -1322, -1322,    25, -1322, -1322, -1322, -1322,    43,
   -1322, -1322, -1322, -1322,    37, -1322, -1322, -1322, -1322, -1322,
     477, -1322,   557,   187,   559,   187,   569,   187,   586, -1322,
     486, -1322, -1322, -1322,   455, -1322, -1322,   509, -1322, -1322,
     432, -1322, -1322,   440, -1322, -1322, -1322,   462, -1322,    90,
   -1322, -1322, -1322, -1322, -1322,   527, -1322, -1322,   529, -1322,
     531, -1322, -1322,   539, -1322, -1322,   478,   484, -1322, -1322,
   -1322, -1322, -1322,   490,   223, -1322, -1322, -1322,   492,   364,
   -1322,   551, -1322, -1322,   570,   -82, -1322, -1322,   632,   634,
     635,   636, -1322, -1322,   468, -1322, -1322,   465, -1322, -1322,
     483, -1322, -1322,   554, -1322, -1322,   519,   642,   -66, -1322,
   -1322, -1322, -1322,   479, -1322, -1322, -1322, -1322,   479, -1322,
   -1322, -1322, -1322,   479, -1322, -1322, -1322, -1322,   643, -1322,
     139, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322,   499,   503, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322,   494,   364,   470, -1322, -1322,   652, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322,   505, -1322, -1322,   653,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322,   628,   649,    57, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   472,   475,
   -1322, -1322,   459, -1322,   464, -1322,   466, -1322, -1322,   474,
   -1322, -1322,   511,   523, -1322, -1322, -1322, -1322,   496,   364,
     515, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322,   498, -1322,   487, -1322, -1322,   660, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   340, -1322,
   -1322, -1322, -1322, -1322, -1322,   500,   364,   518, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322,   665,   -75, -1322,
   -1322, -1322, -1322, -1322,   535,   208,   669, -1322,    19, -1322,
     674, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322,   532, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322,   521,   513, -1322, -1322, -1322,   476,
     502,   504,   208, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322,   493, -1322, -1322, -1322, -1322, -1322, -1322,   506,
     263, -1322,   533,   655,    36, -1322, -1322, -1322, -1322,   -87,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,     5, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
     576,   663, -1322,   508, -1322, -1322, -1322,   543, -1322, -1322,
     517,   525, -1322, -1322,   684, -1322, -1322, -1322,   547,   292,
   -1322, -1322, -1322, -1322,   686, -1322,   541,   666, -1322,   510,
   -1322,   688,   495, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
     512,   254, -1322,   627, -1322, -1322, -1322, -1322,   556,   670,
   -1322,   514, -1322,   693,   497, -1322, -1322, -1322, -1322, -1322,
   -1322,   489,   501,   673,   530, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322,   516, -1322,   697,   591, -1322, -1322,
   -1322, -1322, -1322, -1322,   561,   602,   691, -1322, -1322, -1322,
     605,   673, -1322,   520, -1322, -1322,   710,   -26, -1322, -1322,
   -1322, -1322, -1322, -1322,   601,   615,   702, -1322, -1322, -1322,
   -1322,   522, -1322,   524, -1322, -1322, -1322,   526,   528, -1322,
     714,   -24, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   564,
     572, -1322, -1322, -1322, -1322, -1322, -1322,   534, -1322,   536,
   -1322,   577,   622, -1322, -1322, -1322, -1322,   724,   -86, -1322,
   -1322, -1322, -1322,   581,   626, -1322, -1322, -1322, -1322,   281,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322,   545,   549, -1322,
     699, -1322, -1322, -1322,   538,   263,   583,   630, -1322, -1322,
   -1322, -1322,   732,   -22, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322,   629,   647,   723, -1322, -1322, -1322,   553,   599,
   -1322,   706, -1322, -1322, -1322, -1322,   637,   651,   723, -1322,
   -1322,   558,   560, -1322,   708, -1322, -1322, -1322, -1322,   736,
      32, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322,   638,   657,   723, -1322, -1322, -1322,
     631,   639, -1322,   717,   540,   378, -1322, -1322,   661,   723,
   -1322,   542, -1322, -1322, -1322, -1322, -1322,   745,   544,   360,
   -1322, -1322,   662,   723,   546, -1322, -1322, -1322, -1322,   548,
     754,   479, -1322,   757, -1322, -1322, -1322,   608,   296, -1322,
   -1322, -1322, -1322,   550,   324, -1322, -1322,   668,   723,   552,
   -1322, -1322, -1322, -1322, -1322,   755,   -37, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   633,
     723,   555, -1322,   761,   667, -1322, -1322, -1322, -1322,   762,
     565, -1322,   -69, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322,   640,   723,   563, -1322,   667, -1322,
   -1322, -1322, -1322,   765,     4, -1322, -1322, -1322, -1322, -1322,
     568, -1322,   705, -1322, -1322,   -49, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322,   644,   723,   566,
   -1322,   667, -1322, -1322, -1322, -1322,   768,   479, -1322, -1322,
   -1322, -1322,   623,   641, -1322,   739,   654, -1322, -1322,   774,
   -1322,   610,   723,   571, -1322,   667, -1322, -1322, -1322, -1322,
   -1322,   742,   675, -1322,   671, -1322, -1322, -1322, -1322,   645,
   -1322, -1322, -1322,   646,   579, -1322,   748,   672, -1322, -1322,
   -1322,   612,   723,   573, -1322,   667, -1322, -1322, -1322, -1322,
     678, -1322, -1322, -1322, -1322,   585, -1322, -1322, -1322, -1322,
   -1322, -1322,   648,   677, -1322,   759,   676, -1322, -1322, -1322,
     618,   723,   575, -1322,   667, -1322, -1322, -1322, -1322,   694,
   -1322, -1322,   689, -1322, -1322, -1322,   578, -1322,   580,   243,
   -1322, -1322,   597,   723,   582, -1322,   667, -1322, -1322, -1322,
   -1322,   711, -1322, -1322, -1322,   584, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322,   588, -1322,   590,   243, -1322,
     614,   723,   592, -1322,   667, -1322, -1322, -1322, -1322,   712,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322,   594, -1322,   596,
     243, -1322,   616,   723,   598, -1322,   667, -1322, -1322, -1322,
   -1322,   713, -1322, -1322, -1322, -1322,   798,    30, -1322, -1322,
   -1322, -1322,   667, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322,   723,   600, -1322,   667, -1322, -1322,
   -1322, -1322,   716, -1322, -1322,   802,    45, -1322, -1322, -1322,
   -1322,   800,   574,   807,    11, -1322, -1322, -1322, -1322,   667,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
     723,   604, -1322,   667, -1322, -1322, -1322, -1322,   718, -1322,
   -1322,   809,    48, -1322, -1322, -1322, -1322,   667, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   723,   607,
   -1322,   667, -1322, -1322, -1322, -1322,   720, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322,   679, -1322,   695, -1322,   609, -1322,
     667, -1322, -1322, -1322, -1322,   681, -1322, -1322, -1322,   721,
   -1322,   811, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
     619, -1322,   696, -1322,   611, -1322,   667, -1322, -1322, -1322,
   -1322,   682, -1322, -1322, -1322, -1322,   719, -1322,   698, -1322,
     613, -1322,   667, -1322, -1322, -1322, -1322,   690, -1322, -1322,
   -1322, -1322, -1322,   667, -1322, -1322, -1322, -1322,   650, -1322,
   -1322, -1322, -1322,   707,   820,   824, -1322, -1322, -1322,   667,
   -1322, -1322, -1322, -1322,   656, -1322, -1322, -1322, -1322, -1322,
     667, -1322, -1322, -1322, -1322,   658, -1322, -1322,   659, -1322,
   -1322, -1322, -1322, -1322,   680, -1322, -1322,   685, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   812, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322,   772, -1322, -1322, -1322, -1322,   715, -1322, -1322,
   -1322, -1322, -1322,   445, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   430,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322,   730, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322,   335, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322,   664, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322,   260, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   562, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322,   205, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
     192, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322,   322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,    97, -1322,
   -1322, -1322, -1322, -1322,    47, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322,  -120, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322,  -162, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,  -363,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322,  -365, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322,  -146, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322,  -329, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322,  -330, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322,  -180, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
    -381, -1322, -1322, -1322, -1322, -1322, -1322, -1322,  -383, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322,   -65, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322,  -214, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,   121, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,    49, -1322,
   -1322, -1322, -1322,  -756, -1322, -1322, -1322,  -118, -1322, -1322,
   -1322,  -516, -1322, -1322, -1322,  -655, -1322, -1322, -1322,  -225,
   -1322, -1322, -1322,  -589, -1322, -1322, -1322,  -217, -1322,  -998,
    -980,  -105,  -174, -1322, -1322, -1322,  -110, -1322, -1322, -1322,
   -1322,  -657, -1322,  -868, -1322, -1129, -1322, -1322, -1322, -1322,
   -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322, -1322,
    -352, -1321,  -177, -1322, -1322
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     267,   496,   233,   613,   367,   666,   372,   381,  1233,  1231,
    1065,   499,   235,   264,   795,  1430,   501,  1431,  1432,   478,
     481,   535,   350,   919,   532,   759,   760,   484,   485,   538,
     261,   249,   252,   731,  1430,   258,  1431,  1432,  1090,   246,
     805,   544,  1260,   101,   255,   472,   522,   541,   475,  1449,
      52,  1112,  1430,  1461,  1431,  1432,  1210,   996,   756,   197,
     755,   387,   388,     6,  1239,  1137,  1282,   102,   389,   103,
     703,   104,   814,   105,   815,   816,  1240,   620,   665,  1131,
     102,  1477,   103,  1211,   104,   742,   105,   523,  1179,   808,
    1170,  1038,   809,   676,     7,   756,  1310,   755,   743,  1073,
    1039,  1074,  1075,  1241,  1165,    11,  1180,   739,   349,   358,
     677,   366,  1194,   371,   198,  1181,   199,   390,    13,   636,
     997,    53,   423,   106,    14,  1332,   637,    54,   424,   927,
      27,    55,   928,    56,   425,   542,   106,  1224,   403,   426,
    1212,   404,    44,   702,    84,    57,   284,  1363,    83,   523,
     200,  1450,    92,   107,   123,    58,    35,    59,    36,    37,
     476,   473,  1475,    60,   201,   545,   107,     1,     2,    93,
    1253,   259,   180,   285,  1433,  1399,   256,   247,   806,   817,
     738,    61,   965,   177,   202,   966,   869,   539,  1076,   486,
     203,  1132,   253,   250,  1275,   536,   533,  1427,   262,   265,
     469,   643,   351,   510,   482,   761,   645,   479,   181,   286,
     471,   647,   189,  1437,  1234,   382,   383,   384,   385,  1026,
      85,  1459,    86,    87,  1303,   515,   285,   219,  1446,   504,
     126,   127,   505,   126,   127,   287,   355,   356,   557,   125,
     562,   580,   567,   288,   581,   238,   528,   529,   530,   531,
    1463,   126,   127,  1325,   797,   128,   129,   289,   239,   290,
     273,  1050,   286,   198,  1472,   199,   126,   127,   598,   599,
     274,  1350,   321,   291,   182,  1356,   183,   184,  1479,   292,
     353,   293,   547,   294,   793,   295,   126,   127,   287,   363,
     650,   380,  1488,   651,   609,   610,   288,   126,   127,   200,
    1387,   128,   129,  1392,   720,   721,   126,   127,   598,   599,
     289,  1499,   290,   201,   275,   368,   276,   277,    53,   373,
     587,   395,  1415,   397,    54,  1420,   291,   396,    55,   398,
      56,   399,   292,   202,   293,   400,   294,  1515,   295,   203,
     938,   401,    57,  1101,   402,   556,   409,   561,   410,   566,
     718,   719,    58,  1526,    59,   411,  1439,   412,   413,   814,
      60,   815,   816,  1073,  1529,  1074,  1075,   126,   127,   598,
     599,    17,    18,    22,    23,   609,   610,   432,    61,  1101,
    1535,   720,   721,   126,   127,    30,    31,   128,   129,   355,
     356,  1538,  1465,   892,    47,    48,   601,  1101,    96,    97,
     912,   612,   459,   126,   127,   598,   599,   126,   127,   598,
     599,   609,   610,   142,   143,   609,   610,   147,   148,   494,
    1481,   126,   127,   598,   599,   152,   153,   157,   158,   609,
     610,   162,   163,   167,   168,   172,   173,   192,   193,   221,
     222,   240,   241,   268,   269,   323,   324,   328,   329,   681,
     682,   683,   684,   333,   334,   497,  1105,   502,   685,  1028,
     338,   339,   511,   732,   343,   344,   375,   376,   418,   419,
    1130,   434,   435,   439,   440,   516,   664,   444,   445,   449,
     450,   454,   455,   489,   490,   484,   485,   548,   549,  1009,
    1010,   705,   403,   706,   707,  1163,   570,   571,   390,   716,
     595,   596,   606,   607,   660,   661,   697,   698,   708,   709,
     733,   734,   774,   775,   779,   780,   788,   789,   832,   833,
     854,   855,   864,   865,   877,   878,   897,   898,   520,  1104,
     921,   922,   942,   943,   948,   949,   954,   955,   959,   960,
     758,   701,   521,  1129,   977,   978,   983,   984,  1020,  1021,
    1096,  1097,  1114,  1115,  1122,  1123,  1138,  1139,  1144,  1145,
    1155,  1156,  1171,  1172,   766,  1195,  1196,   553,  1162,   558,
     730,  1207,  1208,  1225,  1226,   575,  1254,  1255,   737,   563,
     785,  1276,  1277,  1304,  1305,  1326,  1327,   787,  1337,  1338,
    1342,  1343,  1357,  1358,  1366,  1367,   568,   754,  1374,  1375,
    1379,  1380,  1393,  1394,  1402,  1403,  1407,  1408,  1421,  1422,
    1440,  1441,  1453,  1454,  1466,  1467,   824,  1482,  1483,  1493,
    1494,  1509,  1510,  1520,  1521,   831,   577,   576,   578,   586,
     579,   589,   591,   588,   754,   504,   619,   590,   626,   618,
     627,   628,   629,   631,   630,   632,   633,   634,   635,   648,
     667,   853,   796,   656,   580,   668,   670,   669,   671,   674,
     636,   689,   713,   717,   686,   693,   691,   704,   690,   871,
     740,   741,   692,   876,   650,   757,   748,   764,   799,   786,
    1349,   767,   887,   802,   765,   837,   743,   771,   828,   842,
     850,   825,   846,   838,   859,   870,   896,   873,   847,   882,
     860,   888,   883,   902,   809,   907,   892,   908,   889,  1386,
     895,   909,   903,   912,   915,   920,   926,   934,   938,  1150,
     964,   844,   972,   868,   935,   933,   872,   927,   988,   991,
     995,  1414,  1002,  1005,  1030,   947,  1018,  1033,  1037,  1046,
    1047,  1050,   996,  1056,  1061,  1068,  1071,  1060,  1085,   971,
    1086,  1016,  1038,  1092,  1094,  1120,  1108,  1133,   966,  1054,
    1149,   982,  1151,  1166,  1153,  1177,  1066,  1200,  1206,  1010,
    1190,  1232,  1201,  1238,  1261,  1263,  1265,  1220,  1237,  1179,
    1270,  1249,  1284,  1286,  1180,  1294,  1311,  1015,  1212,  1291,
    1239,  1271,  1352,  1299,  1287,  1313,  1316,  1210,  1292,  1321,
    1314,  1240,  1333,  1335,  1429,  1364,  1400,  1428,  1448,  1388,
    1451,  1416,  1447,  1458,  1473,  1474,  1489,  1503,  1053,  1500,
    1516,  1492,  1508,  1491,  1519,  1262,  1532,  1502,  1527,  1507,
    1533,  1531,  1530,  1518,    43,   124,   517,   512,  1536,   220,
    1539,  1070,   592,   657,   687,   694,   245,   621,  1017,   784,
    1067,  1293,  1296,  1055,  1264,  1540,  1267,  1027,   839,   433,
    1091,  1093,  1315,  1318,  1154,   973,   768,  1164,   845,   322,
    1029,  1107,     0,  1113,     0,     0,  1543,     0,     0,  1119,
       0,  1544,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1176,     0,     0,
       0,     0,     0,     0,  1189,     0,     0,  1103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1161,     0,     0,     0,
       0,     0,  1236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1283,     0,     0,     0,     0,     0,  1290,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1334,     0,     0,     0,  1336,     0,
       0,     0,     0,  1351,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1365,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1373,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1348,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1413,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1490,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1501,     0,     0,     0,     0,  1504,  1505,     0,     0,
       0,  1506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1517,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1541,  1542
};

static const yytype_int16 yycheck[] =
{
     177,   353,   120,   519,   229,   594,   231,     8,     4,  1138,
    1008,   363,   122,     4,   770,     4,   368,     6,     7,     6,
       4,     4,     4,   891,     4,     6,     7,     6,     7,     4,
       4,     4,     4,   688,     4,     4,     6,     7,  1036,     4,
       4,     4,  1171,    60,     4,     4,    66,     4,     6,     4,
      58,  1049,     4,  1374,     6,     7,   125,   143,   715,    62,
     715,   238,   239,     0,   113,  1063,  1195,    97,   130,    99,
     659,   101,    67,   103,    69,    70,   125,   159,   594,  1059,
      97,  1402,    99,   152,   101,   160,   103,   169,   125,   176,
    1088,   113,   179,    36,    55,   752,  1225,   752,   173,    67,
     122,    69,    70,   152,  1084,    14,   143,   696,   218,   227,
      53,   229,  1110,   231,   117,   152,   119,   179,    15,   185,
     206,   129,    17,   153,    57,  1254,   192,   135,    23,   155,
      59,   139,   158,   141,    29,    92,   153,  1135,   151,    34,
     209,   154,    61,   659,    56,   153,    64,  1276,     5,   169,
     153,   106,    15,   183,    58,   163,    71,   165,    73,    74,
     118,   120,   114,   171,   167,   128,   183,    12,    13,    63,
    1168,   140,    72,    91,   144,  1304,   136,   142,   142,   174,
     696,   189,   206,    26,   187,   209,   841,   162,   156,   168,
     193,  1059,   164,   166,  1192,   178,   176,  1326,   172,   190,
     318,   553,   184,   380,   188,   186,   558,   194,     5,   127,
     320,   563,    65,  1342,   210,   216,   217,   218,   219,   975,
      75,   210,    77,    78,  1222,   402,    91,    60,  1357,   151,
      43,    44,   154,    43,    44,   153,    49,    50,   463,    31,
     465,   151,   467,   161,   154,     3,   423,   424,   425,   426,
    1379,    43,    44,  1251,   770,    47,    48,   175,     3,   177,
      76,    18,   127,   117,  1393,   119,    43,    44,    45,    46,
       5,  1269,    62,   191,    79,  1273,    81,    82,  1407,   197,
      10,   199,   459,   201,    21,   203,    43,    44,   153,    10,
     151,     6,  1421,   154,    51,    52,   161,    43,    44,   153,
    1298,    47,    48,  1301,    41,    42,    43,    44,    45,    46,
     175,  1440,   177,   167,    83,    10,    85,    86,   129,    10,
     497,   142,  1320,   164,   135,  1323,   191,   166,   139,   136,
     141,   140,   197,   187,   199,   172,   201,  1466,   203,   193,
      16,   190,   153,    19,     6,   463,    80,   465,     5,   467,
      10,    11,   163,  1482,   165,    87,  1354,    89,    90,    67,
     171,    69,    70,    67,  1493,    69,    70,    43,    44,    45,
      46,    10,    11,    10,    11,    51,    52,    64,   189,    19,
    1509,    41,    42,    43,    44,    10,    11,    47,    48,    49,
      50,  1520,  1390,    33,    10,    11,   514,    19,    10,    11,
      22,   519,    32,    43,    44,    45,    46,    43,    44,    45,
      46,    51,    52,    10,    11,    51,    52,    10,    11,   184,
    1418,    43,    44,    45,    46,    10,    11,    10,    11,    51,
      52,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   626,
     627,   628,   629,    10,    11,     3,  1045,     6,   635,   975,
      10,    11,   130,   688,    10,    11,    10,    11,    10,    11,
    1059,    10,    11,    10,    11,   154,   594,    10,    11,    10,
      11,    10,    11,    10,    11,     6,     7,    10,    11,   208,
     209,   668,   151,   670,   671,  1084,    10,    11,   179,   676,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    84,  1045,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     717,   659,     5,  1059,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   741,    10,    11,    10,  1084,    10,
     688,     6,     7,    10,    11,   120,    10,    11,   696,    10,
     757,    10,    11,    10,    11,    10,    11,   764,    10,    11,
      10,    11,    10,    11,    10,    11,    10,   715,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    38,    39,    10,    11,   793,    10,    11,    10,
      11,    10,    11,    10,    11,   802,   194,   118,   188,   102,
     168,   100,   154,   104,   752,   151,    66,    98,     6,    88,
       6,     6,     6,   178,   176,   162,    92,   128,     6,     6,
     180,   828,   770,   154,   151,     3,     3,   152,    30,    10,
     185,   202,   175,     3,   192,   154,   200,   152,   204,   846,
     152,     6,   198,   850,   151,     6,   141,     3,   145,   186,
    1269,   160,   859,    28,   152,   142,   173,   211,    25,     5,
      24,   115,     6,   176,     6,    68,   873,    27,   157,     6,
     205,   212,   205,     6,   179,   882,    33,   146,   207,  1298,
     180,   109,   121,    22,   109,   892,     6,   116,    16,  1071,
       6,   174,   158,   841,   109,   902,   170,   155,   151,   107,
       6,  1320,   151,   107,   151,   912,    37,   107,     6,   110,
      93,    18,   143,    37,    93,    37,    10,   110,   110,   926,
      93,   206,   113,   122,    37,    10,    95,    95,   209,   206,
       6,   938,     5,    95,   156,    10,   208,     6,     6,   209,
     137,     6,   105,    68,     6,   152,    37,   137,   210,   125,
       6,   137,    40,   108,   143,    37,   108,   964,   209,   144,
     113,   181,   195,   181,   123,   210,    37,   125,   152,   181,
     152,   125,   108,   114,     6,    94,    94,    94,     6,   195,
      10,   195,    96,     6,    96,     6,    96,     6,   995,   138,
     138,   126,   126,   144,   126,  1177,     6,   106,   138,   210,
       6,   124,   182,   114,    22,    63,   406,   392,   182,   109,
     182,  1018,   507,   583,   639,   653,   131,   525,   968,   752,
    1012,  1214,  1217,   999,  1183,   196,  1186,   975,   811,   297,
    1037,  1041,  1243,  1246,  1078,   930,   745,  1084,   819,   205,
     975,  1045,    -1,  1050,    -1,    -1,   196,    -1,    -1,  1056,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1068,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1094,    -1,    -1,
      -1,    -1,    -1,    -1,  1101,    -1,    -1,  1045,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1059,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1084,    -1,    -1,    -1,
      -1,    -1,  1149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1200,    -1,    -1,    -1,    -1,    -1,  1206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1261,    -1,    -1,    -1,  1265,    -1,
      -1,    -1,    -1,  1270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1284,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1294,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1316,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1448,    -1,    -1,    -1,    -1,  1453,  1454,    -1,    -1,
      -1,  1458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1532,  1533
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   221,   222,   223,     0,    55,   228,   229,
     230,    14,   224,    15,    57,   255,   256,    10,    11,   231,
     232,   233,    10,    11,   225,   226,   227,    59,   335,   336,
      10,    11,   257,   258,   259,    71,    73,    74,   234,   235,
     236,   237,   238,   228,    61,   389,   390,    10,    11,   337,
     338,   339,    58,   129,   135,   139,   141,   153,   163,   165,
     171,   189,   260,   261,   262,   263,   264,   279,   280,   285,
     286,   291,   292,   297,   298,   303,   304,   309,   310,   315,
     316,   321,   322,     5,    56,    75,    77,    78,   239,   240,
     241,   242,    15,    63,   441,   442,    10,    11,   391,   392,
     393,    60,    97,    99,   101,   103,   153,   183,   340,   341,
     342,   343,   344,   349,   350,   356,   357,   363,   364,   370,
     371,   375,   376,    58,   262,    31,    43,    44,    47,    48,
     265,   266,   267,   927,   928,   929,   930,   935,   936,   937,
     938,   961,    10,    11,   281,   282,   283,    10,    11,   287,
     288,   289,    10,    11,   293,   294,   295,    10,    11,   299,
     300,   301,    10,    11,   305,   306,   307,    10,    11,   311,
     312,   313,    10,    11,   317,   318,   319,    26,   323,   956,
      72,     5,    79,    81,    82,   243,   244,   245,   246,    65,
     536,   537,    10,    11,   443,   444,   445,    62,   117,   119,
     153,   167,   187,   193,   394,   395,   396,   397,   398,   403,
     404,   409,   410,   415,   416,   421,   422,   427,   428,    60,
     342,    10,    11,   345,   346,   347,   351,   352,   358,   359,
     365,   366,   372,   927,   377,   956,   982,   983,     3,     3,
      10,    11,   268,   269,   270,   267,     4,   142,   284,     4,
     166,   290,     4,   164,   296,     4,   136,   302,     4,   140,
     308,     4,   172,   314,     4,   190,   320,   982,    10,    11,
     324,   325,   326,    76,     5,    83,    85,    86,   247,   248,
     249,   250,   538,   539,    64,    91,   127,   153,   161,   175,
     177,   191,   197,   199,   201,   203,   446,   447,   448,   449,
     450,   455,   456,   461,   462,   467,   468,   473,   474,   479,
     480,   496,   497,   503,   504,   510,   511,   517,   518,   522,
     523,    62,   396,    10,    11,   399,   400,   401,    10,    11,
     405,   406,   407,    10,    11,   411,   412,   413,    10,    11,
     417,   418,   419,    10,    11,   423,   424,   425,   429,   956,
       4,   184,   348,    10,   354,    49,    50,   353,   927,   939,
     940,   941,   942,    10,   361,   360,   927,   939,    10,   368,
     367,   927,   939,    10,   373,    10,    11,   378,   379,   380,
       6,     8,   216,   217,   218,   219,   984,   982,   982,   130,
     179,   271,   272,   273,   274,   142,   166,   164,   136,   140,
     172,   190,     6,   151,   154,   327,   328,   329,   330,    80,
       5,    87,    89,    90,   251,   252,   253,   254,    10,    11,
     541,   542,   543,    17,    23,    29,    34,   540,   948,   953,
     959,   964,    64,   448,    10,    11,   451,   452,   453,    10,
      11,   457,   458,   459,    10,    11,   463,   464,   465,    10,
      11,   469,   470,   471,    10,    11,   475,   476,   477,    32,
     481,   962,   498,   499,   505,   506,   512,   513,   519,   927,
     524,   956,     4,   120,   402,     6,   118,   408,     6,   194,
     414,     4,   188,   420,     6,     7,   168,   426,   980,    10,
      11,   430,   431,   432,   184,   355,   980,     3,   362,   980,
     369,   980,     6,   374,   151,   154,   381,   382,   383,   384,
     982,   130,   273,   275,   276,   982,   154,   329,   331,   332,
      84,     5,    66,   169,   544,   545,   546,   547,   982,   982,
     982,   982,     4,   176,   454,     4,   178,   460,     4,   162,
     466,     4,    92,   472,     4,   128,   478,   982,    10,    11,
     482,   483,   484,    10,   501,   500,   927,   939,    10,   508,
     507,   927,   939,    10,   515,   514,   927,   939,    10,   520,
      10,    11,   525,   526,   527,   120,   118,   194,   188,   168,
     151,   154,   433,   434,   435,   436,   102,   982,   104,   100,
      98,   154,   383,   385,   386,    10,    11,   278,    45,    46,
     277,   927,   931,   932,   933,   934,    10,    11,   334,    51,
      52,   333,   927,   931,   943,   944,   945,   946,    88,    66,
     159,   546,   900,   901,   548,   549,     6,     6,     6,     6,
     176,   178,   162,    92,   128,     6,   185,   192,   485,   486,
     487,   488,   502,   980,   509,   980,   516,   980,     6,   521,
     151,   154,   528,   529,   530,   531,   154,   435,   437,   438,
      10,    11,   388,   387,   927,   931,   943,   180,     3,   152,
       3,    30,   902,   960,    10,   553,    36,    53,   550,   551,
     552,   982,   982,   982,   982,   982,   192,   487,   489,   202,
     204,   200,   198,   154,   530,   532,   533,    10,    11,   440,
     439,   927,   931,   943,   152,   982,   982,   982,    10,    11,
     903,   904,   905,   175,   554,   555,   982,     3,    10,    11,
      41,    42,   490,   491,   492,   493,   923,   924,   925,   926,
     927,   935,   939,    10,    11,   535,   534,   927,   931,   943,
     152,     6,   160,   173,   906,   907,   908,   909,   141,   570,
     571,   556,   557,   558,   927,   935,   961,     6,   982,     6,
       7,   186,   494,   495,     3,   152,   982,   160,   908,   910,
     911,   211,   576,   577,    10,    11,   572,   573,   574,    10,
      11,   559,   560,   561,   558,   982,   186,   982,    10,    11,
     913,   914,   915,    21,   912,   923,   927,   931,   951,   145,
     686,   687,    28,   578,   958,     4,   142,   575,   176,   179,
     562,   563,   564,   565,    67,    69,    70,   174,   916,   917,
     918,   919,   920,   921,   982,   115,   782,   783,    25,   688,
     955,   982,    10,    11,   579,   580,   581,   142,   176,   564,
     566,   567,     5,   922,   174,   918,     6,   157,   877,   878,
      24,   784,   954,   982,    10,    11,   689,   690,   691,     6,
     205,   582,   583,   584,    10,    11,   569,   568,   927,   935,
      68,   982,   170,    27,   879,   957,   982,    10,    11,   785,
     786,   787,     6,   205,   692,   693,   694,   982,   212,   207,
     595,   596,    33,   585,   963,   180,   982,    10,    11,   880,
     881,   882,     6,   121,   788,   789,   790,   982,   146,   109,
     706,   707,    22,   695,   952,   109,   610,   611,   597,   963,
     982,    10,    11,   586,   587,   588,     6,   155,   158,   883,
     884,   885,   886,   982,   116,   109,   801,   802,    16,   791,
     947,   754,    10,    11,   708,   709,   710,   982,    10,    11,
     696,   697,   698,   658,    10,    11,   612,   613,   614,    10,
      11,   598,   599,   600,     6,   206,   209,   589,   590,   591,
     592,   982,   158,   885,   887,   888,   849,    10,    11,   803,
     804,   805,   982,    10,    11,   792,   793,   794,   151,   755,
     756,   107,   711,   712,   713,     6,   143,   206,   699,   700,
     701,   702,   151,   659,   660,   107,   615,   616,   617,   208,
     209,   601,   602,   603,   604,   982,   206,   591,    37,   593,
      10,    11,   890,   891,   892,   889,   923,   927,   931,   951,
     151,   850,   851,   107,   806,   807,   808,     6,   113,   122,
     795,   796,   797,   798,   757,   758,   110,    93,   719,   720,
      18,   714,   949,   982,   206,   701,    37,   703,   661,   662,
     110,    93,   623,   624,   618,   949,   208,   603,    37,   605,
     982,    10,   594,    67,    69,    70,   156,   893,   894,   895,
     896,   897,   898,   852,   853,   110,    93,   814,   815,   809,
     949,   982,   122,   797,    37,   799,    10,    11,   760,   761,
     762,    19,   759,   927,   931,   943,   950,   952,    95,   726,
     727,   721,   949,   982,    10,    11,   715,   716,   717,   982,
      10,   704,    10,    11,   664,   665,   666,   663,   927,   931,
     943,   950,   963,    95,   630,   631,   625,   949,    10,    11,
     619,   620,   621,   982,    10,    11,   606,   607,   608,     6,
     980,     5,   899,   156,   895,    10,    11,   855,   856,   857,
     854,   927,   931,   943,   947,   950,    95,   821,   822,   816,
     949,    10,    11,   810,   811,   812,   982,    10,   800,   125,
     143,   152,   763,   764,   765,   766,   772,   773,   774,   982,
     137,   733,   734,   728,   949,    10,    11,   722,   723,   724,
       6,   105,   718,   965,   966,   973,     6,     6,     7,   705,
     125,   152,   209,   667,   668,   669,   670,   676,   677,   678,
     137,   637,   638,   632,   949,    10,    11,   626,   627,   628,
     622,   965,     6,     4,   210,   609,   982,   210,    68,   113,
     125,   152,   858,   859,   860,   861,   867,   868,   869,   137,
     828,   829,   823,   949,    10,    11,   817,   818,   819,   813,
     965,     6,   980,   152,   765,    37,   767,   773,   775,   776,
       6,   181,   740,   741,   735,   949,    10,    11,   729,   730,
     731,   725,   965,   982,    40,   974,   108,   123,   967,   968,
     982,   144,   152,   669,    37,   671,   677,   679,   680,   181,
     644,   645,   639,   949,    10,    11,   633,   634,   635,   629,
     965,   108,   982,   210,   152,   860,    37,   862,   868,   870,
     871,   181,   835,   836,   830,   949,    10,    11,   824,   825,
     826,   820,   965,   108,   982,   114,   982,    10,    11,   768,
     769,   770,    10,    11,   778,   779,   780,   777,   927,   943,
     949,   982,   195,   747,   748,   742,   949,    10,    11,   736,
     737,   738,   732,   965,    94,   982,    10,    11,   975,   976,
     977,   969,   970,   982,    10,    11,   672,   673,   674,    10,
      11,   682,   683,   684,   681,   927,   943,   949,   195,   651,
     652,   646,   949,    10,    11,   640,   641,   642,   636,   965,
      94,   982,    10,    11,   863,   864,   865,    10,    11,   873,
     874,   875,   872,   927,   943,   949,   195,   842,   843,   837,
     949,    10,    11,   831,   832,   833,   827,   965,    94,     6,
       4,     6,     7,   144,   771,   981,   781,   965,   749,   949,
      10,    11,   743,   744,   745,   739,   965,    96,     6,     4,
     106,    10,   972,    38,    39,   971,   978,   979,     6,   210,
     675,   981,   685,   965,   653,   949,    10,    11,   647,   648,
     649,   643,   965,    96,     6,   114,   866,   981,   876,   965,
     844,   949,    10,    11,   838,   839,   840,   834,   965,    96,
     982,   144,   126,    10,    11,   750,   751,   752,   746,   965,
     138,   982,   106,     6,   982,   982,   982,   210,   126,    10,
      11,   654,   655,   656,   650,   965,   138,   982,   114,   126,
      10,    11,   845,   846,   847,   841,   965,   138,   753,   965,
     182,   124,     6,     6,   657,   965,   182,   848,   965,   182,
     196,   982,   982,   196,   196
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
        case 4:

    {
#ifdef DEBUG
yydebug = 1;
#endif
;}
    break;

  case 5:

    {
#ifdef DEBUG
yydebug = 1;
#endif
;}
    break;

  case 14:

    {
	if (osglData->fileName    != "" || osglData->source      != "" ||
		osglData->fileCreator != "" || osglData->description != "" ||
		osglData->licence     != "")
		if(!osresult->setResultHeader(osglData->fileName, osglData->source, 	
				osglData->description, osglData->fileCreator, osglData->licence) )	
			osrlerror( NULL, osresult, parserData, osglData, "setHeader failed");
;}
    break;

  case 15:

    {
	osglData->fileName    = "";
	osglData->source      = "";
	osglData->description = "";
	osglData->fileCreator = "";
	osglData->licence     = "";
;}
    break;

  case 27:

    {
	osglData->fileName = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 34:

    {
	osglData->source = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 41:

    {
	osglData->description = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 48:

    {
	osglData->fileCreator = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 55:

    {
	osglData->licence = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 77:

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

  case 78:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	;}
    break;

  case 81:

    { 
		if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "general status type does not match any legal value");
	;}
    break;

  case 82:

    {   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	;}
    break;

  case 83:

    {   if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate substatus array. Potential loss of data.");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	;}
    break;

  case 84:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	;}
    break;

  case 85:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	;}
    break;

  case 92:

    {	parserData->kounter++;
;}
    break;

  case 93:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 94:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have name attribute");
;}
    break;

  case 97:

    {	
		if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus name");
	;}
    break;

  case 98:

    {	
		if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus description");
	;}
    break;

  case 102:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 108:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 110:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 116:

    {osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 118:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 124:

    {osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 126:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 132:

    {osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 134:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 140:

    {osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 142:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 148:

    {osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 150:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 156:

    {osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 158:

    {	if (parserData->otherGeneralResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one general other results element allowed");
		parserData->otherGeneralResultsPresent = true;
	;}
    break;

  case 159:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other general results cannot be negative");
	if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate other general results array. Potential loss of data.");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 160:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 161:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 168:

    {	parserData->kounter++;
;}
    break;

  case 169:

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

  case 170:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 173:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultName failed");
	;}
    break;

  case 174:

    {	
		if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultValue failed");
	;}
    break;

  case 175:

    {	
		if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultDescription failed");
	;}
    break;

  case 196:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 202:

    {	osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	;}
    break;

  case 204:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 208:

    {
		if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 209:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 211:

    {	osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 213:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 217:

    {
		if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 218:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 220:

    {	osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
;}
    break;

  case 222:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 226:

    {
		if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "available CPU Speed could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 227:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 229:

    {	osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
;}
    break;

  case 231:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 233:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 235:

    {	osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; ;}
    break;

  case 237:

    {	if (parserData->otherSystemResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one system other results element allowed");
		parserData->otherSystemResultsPresent = true;
	;}
    break;

  case 238:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other system results cannot be negative");
	if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSystemResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 239:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 240:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 247:

    {	parserData->kounter++;
;}
    break;

  case 248:

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

  case 249:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 252:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultName failed");
	;}
    break;

  case 253:

    {	
		if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultValue failed");
	;}
    break;

  case 254:

    {	
		if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultDescription failed");
	;}
    break;

  case 275:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 281:

    {   parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setCurrentState(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setCurrentState failed; current system state not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 283:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 289:

    { osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 291:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 297:

    { osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 299:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 305:

    {osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 307:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 313:

    {	if (osresult->setServiceUtilization( parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setServiceUtilization failed");
	parserData->errorText = NULL;
;}
    break;

  case 315:

    {	if (parserData->otherServiceResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one service other results element allowed");
		parserData->otherServiceResultsPresent = true;
	;}
    break;

  case 316:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other service results cannot be negative");
	if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherServiceResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 317:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 318:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 325:

    {	parserData->kounter++;
;}
    break;

  case 326:

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

  case 327:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 330:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultName failed");
	;}
    break;

  case 331:

    {	
		if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultValue failed");
	;}
    break;

  case 332:

    {	
		if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultDescription failed");
	;}
    break;

  case 358:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 364:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setJobStatus(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobStatus failed");
		parserData->errorText = NULL;
	;}
    break;

  case 366:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 372:

    {osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 374:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 380:

    {osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 382:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 388:

    {osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 390:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 396:

    {osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 398:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 399:

    {	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of time measurements cannot be negative");
	if (osresult->setNumberOfTimes(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfTimes failed");
	parserData->numberOfTimes = parserData->tempInt;
	parserData->ivar = 0;
;}
    break;

  case 400:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <time> element");
	;}
    break;

  case 401:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <time> elements than specified");
	;}
    break;

  case 409:

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

  case 421:

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

  case 422:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 423:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 425:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 429:

    {
		if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 430:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 432:

    {	osresult->setUsedDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 434:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 438:

    {
		if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "usedMemory unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 439:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 441:

    {	osresult->setUsedMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 443:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 447:

    {
		if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableCPUSpeed unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 448:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 450:

    {	osresult->setUsedCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 452:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 454:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 456:

    { osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; ;}
    break;

  case 458:

    {	if (parserData->otherJobResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job other results element allowed");
		parserData->otherJobResultsPresent = true;
	;}
    break;

  case 459:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other job results cannot be negative");
	if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherJobResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 460:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 461:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 468:

    {	parserData->kounter++;
;}
    break;

  case 469:

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

  case 470:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 473:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultName failed");
	;}
    break;

  case 474:

    {	
		if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultValue failed");
	;}
    break;

  case 475:

    {	
		if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultDescription failed");
	;}
    break;

  case 480:

    {
	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
;}
    break;

  case 481:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "numberOfSolutions was never set");
;}
    break;

  case 484:

    {
		parserData->numberOfSolutions = parserData->tempInt; 
		if (osresult->setSolutionNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionNumber failed");
		parserData->solutionIdx = 0;
	;}
    break;

  case 485:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osresult->setVariableNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVariableNumber failed");
	;}
    break;

  case 486:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osresult->setConstraintNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setConstraintNumber failed");
	;}
    break;

  case 487:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osresult->setObjectiveNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjectiveNumber failed");
	;}
    break;

  case 488:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solution> element");
	;}
    break;

  case 489:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solution> elements than specified");
	;}
    break;

  case 497:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 503:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, "target objective index must be negative");
  	if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveIdx failed");
 ;}
    break;

  case 504:

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

  case 505:

    {
		parserData->solutionIdx++;
	;}
    break;

  case 507:

    {
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
		parserData->typeAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 508:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for solution status element");
	;}
    break;

  case 511:

    {   
		if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusType failed");
	;}
    break;

  case 512:

    {   if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusDescription failed");
	;}
    break;

  case 513:

    {	if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolutionSubstatuses failed");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	;}
    break;

  case 514:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	;}
    break;

  case 515:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	;}
    break;

  case 522:

    {	parserData->kounter++; ;}
    break;

  case 523:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->typeAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 524:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have type attribute");
;}
    break;

  case 527:

    {	
		if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
											   parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusType failed");
	;}
    break;

  case 528:

    {	
		if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
													  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusDescription failed");
	;}
    break;

  case 539:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
		osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
		parserData->errorText = NULL;
	;}
    break;

  case 542:

    {	parserData->numberOfOtherVariableResults = 0; ;}
    break;

  case 544:

    {	
	if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, 
												  parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableResults failed");
	parserData->numberOfOtherVariableResults = parserData->tempInt;
	parserData->iOther = 0;
;}
    break;

  case 553:

    {
	if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValues failed");
	parserData->kounter = 0;
;}
    break;

  case 554:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 555:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 562:

    {	if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValue failed");
	parserData->kounter++;
;}
    break;

  case 563:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
;}
    break;

  case 564:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 569:

    {
	if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
	parserData->kounter = 0;
;}
    break;

  case 570:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 571:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 578:

    {
	if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 				parserData->idx,         parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValueString failed");
	parserData->kounter++;
;}
    break;

  case 579:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
;}
    break;

  case 580:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 581:

    {parserData->tempStr = "";;}
    break;

  case 586:

    {parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));;}
    break;

  case 596:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
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

  case 605:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 607:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 614:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 616:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 623:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 625:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 632:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 634:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 641:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 643:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 651:

    { 	 
		parserData->iOther++;
	;}
    break;

  case 652:

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

  case 653:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfVar attribute"); 
	;}
    break;

  case 656:

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

  case 657:

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

  case 658:

    {	
	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 												  parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 659:

    {	
	 	if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    ;}
    break;

  case 660:

    {	
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 670:

    { 	
	parserData->kounter++;
;}
    break;

  case 672:

    {	
 	if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 											   parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
;}
    break;

  case 678:

    {	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
	;}
    break;

  case 681:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other variable option failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
;}
    break;

  case 682:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 683:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfVarIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfVarIdx attribute"); 
	;}
    break;

  case 686:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 687:

    {	
//	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 688:

    {	
//	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 696:

    {	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 698:

    {
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
    if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, 
												   parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
;}
    break;

  case 707:

    {
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
;}
    break;

  case 708:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	;}
    break;

  case 709:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	;}
    break;

  case 716:

    {	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
	parserData->kounter++;
;}
    break;

  case 717:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idx = -1;
;}
    break;

  case 719:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 721:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 722:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 732:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
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

  case 741:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 743:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 750:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 752:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 759:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 761:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 768:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 770:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 777:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 779:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 787:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 788:

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

  case 789:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfObj attribute"); 
	;}
    break;

  case 792:

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

  case 793:

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

  case 794:

    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 795:

    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    ;}
    break;

  case 796:

    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 806:

    {  
	parserData->kounter++;
;}
    break;

  case 808:

    {	if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
;}
    break;

  case 814:

    {	if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
	;}
    break;

  case 817:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_objectives, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other objective option failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
;}
    break;

  case 818:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 819:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfObjIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfObjIdx attribute"); 
	;}
    break;

  case 822:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 823:

    {	
//	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 824:

    {	
//	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 832:

    {	parserData->numberOfOtherConstraintResults = 0; 
	parserData->iOther = 0;
;}
    break;

  case 834:

    {
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
;}
    break;

  case 842:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 843:

    {
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
;}
    break;

  case 844:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	;}
    break;

  case 845:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	;}
    break;

  case 852:

    {	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
	parserData->kounter++;
;}
    break;

  case 853:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
;}
    break;

  case 854:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 865:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
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

  case 874:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 876:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 883:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 885:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 892:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 894:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 901:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 903:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 910:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 912:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 920:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 921:

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

  case 922:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfCon attribute"); 
	;}
    break;

  case 925:

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

  case 926:

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

  case 927:

    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 928:

    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    ;}
    break;

  case 929:

    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 939:

    { 	
	parserData->kounter++;
;}
    break;

  case 941:

    {	
 	if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
;}
    break;

  case 947:

    {	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
	;}
    break;

  case 950:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_constraints, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other constraint option failed");
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
;}
    break;

  case 951:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 952:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfConIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfConIdx attribute"); 
	;}
    break;

  case 955:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 956:

    {	
//	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 957:

    {	
//	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 965:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 966:

    {	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 967:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
	;}
    break;

  case 968:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
	;}
    break;

  case 975:

    {	parserData->iOther++;
;}
    break;

  case 976:

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

  case 977:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
;}
    break;

  case 980:

    {	
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
	;}
    break;

  case 981:

    {	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
	;}
    break;

  case 982:

    {	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
	;}
    break;

  case 983:

    {	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 984:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 985:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 992:

    {	parserData->kounter++;
;}
    break;

  case 993:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 998:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
											 parserData->kounter, parserData->itemContent) 
											     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultItem failed");
;}
    break;

  case 1001:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 1002:

    {	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 1003:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
	;}
    break;

  case 1004:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
	;}
    break;

  case 1011:

    {	parserData->iOther++;
;}
    break;

  case 1012:

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

  case 1013:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
;}
    break;

  case 1016:

    {	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
	;}
    break;

  case 1017:

    {	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
	;}
    break;

  case 1018:

    {	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
	;}
    break;

  case 1019:

    {	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 1020:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 1021:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 1028:

    {	parserData->kounter++;
;}
    break;

  case 1029:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 1034:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
;}
    break;

  case 1035:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 1038:

    { parserData->categoryAttribute = ""; ;}
    break;

  case 1039:

    { parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 1040:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 1043:

    { parserData->descriptionAttribute = ""; ;}
    break;

  case 1044:

    { parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1045:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 1048:

    { parserData->nameAttribute = ""; ;}
    break;

  case 1049:

    { parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1050:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 1053:

    { parserData->typeAttribute = ""; ;}
    break;

  case 1054:

    { parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1055:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 1058:

    { parserData->unitAttribute = ""; ;}
    break;

  case 1059:

    { parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1060:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 1063:

    { parserData->valueAttribute = ""; ;}
    break;

  case 1064:

    { parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1065:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1066:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1067:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1068:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1069:

    {	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1070:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1071:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1072:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1073:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1074:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1075:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1076:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1077:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1078:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1079:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1080:

    {
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1081:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1082:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1083:

    {
	 	if (osglData->osglCounter + osglData->osglMult < osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	;}
    break;

  case 1088:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
;}
    break;

  case 1094:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
;}
    break;

  case 1096:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1101:

    {
	char* b64string = (yyvsp[(2) - (3)].sval);
	if( b64string == NULL) 
		osrlerror(NULL, NULL, parserData, osglData, "base 64 data expected"); 
	if (osglData->osglSize != sizeof(int))
		osrlerror(NULL, NULL, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

	std::string base64decodeddata = Base64::decodeb64( b64string );
	int base64decodeddatalength = base64decodeddata.length();
	int *intvec = NULL;
	if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
		osrlerror(NULL, NULL, parserData, osglData, "base 64 data length does not match numberOfEl"); 
	intvec = (int*)&base64decodeddata[0];
	for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
	{
		osglData->osglIntArray[i] = *(intvec++);
	}
	//delete [] b64string;
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1102:

    {	
	if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1103:

    {	
	if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1104:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 1105:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 1106:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 1107:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 1108:

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
	osgl_empty_vectors(	osglData);
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "OSrL input is either not valid or well formed: "  + error;
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
		  	throw ErrorClass(  "Error parsing the OSrL file");
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

//void osgl_empty_vectors( OSgLParserData* osglData){
//	if (osglData->osglIntArray != NULL)
//		delete[] osglData->osglIntArray;
//}//end osgl_empty_vectors

