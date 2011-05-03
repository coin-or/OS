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
#define YYLAST   1351

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  220
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  773
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1136
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1541

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
      22,    24,    28,    30,    31,    38,    39,    42,    44,    46,
      48,    50,    54,    60,    61,    63,    65,    67,    69,    71,
      75,    76,    78,    80,    82,    84,    86,    90,    91,    93,
      95,    97,    99,   101,   105,   106,   108,   110,   112,   114,
     116,   120,   121,   123,   125,   127,   129,   131,   135,   136,
     139,   141,   143,   145,   148,   150,   154,   156,   158,   161,
     163,   165,   167,   169,   171,   173,   175,   177,   179,   183,
     185,   187,   189,   192,   194,   196,   198,   200,   202,   205,
     207,   211,   213,   215,   218,   222,   224,   226,   227,   230,
     232,   234,   237,   239,   242,   244,   246,   248,   251,   253,
     257,   259,   262,   264,   266,   268,   271,   273,   277,   279,
     282,   284,   286,   288,   291,   293,   297,   299,   302,   304,
     306,   308,   311,   313,   317,   319,   322,   324,   326,   328,
     331,   333,   337,   339,   342,   344,   346,   348,   351,   353,
     357,   359,   362,   364,   366,   368,   371,   373,   377,   379,
     383,   385,   387,   389,   391,   394,   396,   400,   402,   404,
     407,   411,   413,   415,   416,   419,   421,   423,   425,   428,
     430,   431,   434,   436,   438,   440,   443,   445,   449,   451,
     453,   456,   458,   460,   462,   464,   466,   468,   471,   473,
     475,   477,   480,   482,   486,   488,   492,   494,   496,   497,
     500,   502,   504,   508,   510,   514,   516,   518,   519,   522,
     524,   526,   530,   532,   536,   538,   540,   541,   544,   546,
     548,   552,   554,   558,   560,   561,   563,   567,   569,   573,
     575,   577,   579,   581,   584,   586,   590,   592,   594,   597,
     601,   603,   605,   606,   609,   611,   613,   615,   618,   620,
     621,   624,   626,   628,   630,   633,   635,   639,   641,   643,
     646,   648,   650,   652,   654,   656,   658,   661,   663,   665,
     667,   670,   672,   676,   678,   681,   683,   685,   687,   690,
     692,   696,   698,   701,   703,   705,   707,   710,   712,   716,
     718,   721,   723,   725,   727,   730,   732,   736,   738,   741,
     743,   745,   747,   750,   752,   756,   758,   762,   764,   766,
     768,   770,   773,   775,   779,   781,   783,   786,   790,   792,
     794,   795,   798,   800,   802,   804,   807,   809,   810,   813,
     815,   817,   819,   822,   824,   828,   830,   832,   835,   837,
     839,   841,   843,   845,   847,   849,   851,   853,   855,   857,
     860,   862,   864,   866,   869,   871,   875,   877,   880,   882,
     884,   886,   889,   891,   895,   897,   900,   902,   904,   906,
     909,   911,   915,   917,   920,   922,   924,   926,   929,   931,
     935,   937,   940,   942,   944,   946,   949,   951,   955,   957,
     961,   963,   965,   967,   969,   972,   974,   978,   980,   982,
     985,   989,   991,   992,   995,   997,   999,  1001,  1003,  1005,
    1007,  1010,  1012,  1016,  1018,  1020,  1022,  1026,  1028,  1030,
    1031,  1034,  1036,  1038,  1042,  1044,  1048,  1050,  1052,  1053,
    1056,  1058,  1060,  1064,  1066,  1070,  1072,  1074,  1075,  1078,
    1080,  1082,  1086,  1088,  1092,  1094,  1095,  1097,  1101,  1103,
    1107,  1109,  1111,  1113,  1115,  1118,  1120,  1124,  1126,  1128,
    1131,  1135,  1137,  1139,  1140,  1143,  1145,  1147,  1149,  1152,
    1154,  1155,  1159,  1161,  1163,  1164,  1167,  1169,  1171,  1173,
    1175,  1177,  1179,  1182,  1184,  1188,  1191,  1193,  1196,  1200,
    1202,  1204,  1205,  1208,  1210,  1212,  1217,  1221,  1230,  1234,
    1236,  1238,  1240,  1243,  1245,  1247,  1249,  1251,  1253,  1256,
    1258,  1262,  1264,  1266,  1269,  1273,  1275,  1277,  1278,  1281,
    1283,  1285,  1288,  1290,  1291,  1294,  1296,  1298,  1300,  1303,
    1305,  1309,  1311,  1312,  1316,  1318,  1319,  1321,  1323,  1325,
    1327,  1331,  1336,  1337,  1341,  1343,  1345,  1347,  1349,  1352,
    1354,  1358,  1360,  1362,  1365,  1369,  1371,  1372,  1375,  1377,
    1379,  1383,  1384,  1388,  1390,  1392,  1394,  1396,  1399,  1401,
    1405,  1407,  1409,  1412,  1416,  1418,  1419,  1422,  1424,  1426,
    1428,  1430,  1433,  1435,  1439,  1441,  1442,  1445,  1447,  1449,
    1451,  1453,  1457,  1464,  1465,  1469,  1471,  1473,  1475,  1477,
    1479,  1483,  1485,  1486,  1490,  1492,  1494,  1496,  1498,  1500,
    1504,  1506,  1507,  1511,  1513,  1515,  1517,  1519,  1521,  1525,
    1527,  1528,  1532,  1534,  1536,  1538,  1540,  1542,  1546,  1548,
    1549,  1553,  1555,  1557,  1559,  1561,  1563,  1567,  1569,  1570,
    1574,  1576,  1578,  1580,  1582,  1584,  1588,  1590,  1591,  1594,
    1598,  1600,  1602,  1603,  1606,  1608,  1610,  1612,  1614,  1616,
    1618,  1620,  1623,  1625,  1629,  1631,  1633,  1635,  1638,  1642,
    1644,  1645,  1648,  1650,  1652,  1654,  1656,  1659,  1661,  1665,
    1667,  1669,  1672,  1676,  1678,  1680,  1681,  1684,  1686,  1688,
    1690,  1692,  1694,  1696,  1700,  1702,  1703,  1707,  1709,  1710,
    1712,  1714,  1716,  1718,  1722,  1726,  1727,  1731,  1733,  1735,
    1737,  1739,  1742,  1744,  1748,  1750,  1752,  1755,  1759,  1761,
    1762,  1765,  1767,  1769,  1773,  1774,  1777,  1779,  1781,  1783,
    1785,  1789,  1796,  1797,  1801,  1803,  1805,  1807,  1809,  1811,
    1815,  1817,  1818,  1822,  1824,  1826,  1828,  1830,  1832,  1836,
    1838,  1839,  1843,  1845,  1847,  1849,  1851,  1853,  1857,  1859,
    1860,  1864,  1866,  1868,  1870,  1872,  1874,  1878,  1880,  1881,
    1885,  1887,  1889,  1891,  1893,  1895,  1899,  1901,  1902,  1906,
    1908,  1910,  1912,  1914,  1916,  1920,  1922,  1923,  1926,  1930,
    1932,  1934,  1935,  1938,  1940,  1942,  1944,  1946,  1948,  1950,
    1952,  1955,  1957,  1961,  1963,  1965,  1967,  1970,  1974,  1976,
    1977,  1980,  1982,  1984,  1986,  1988,  1991,  1993,  1997,  1999,
    2001,  2004,  2008,  2010,  2012,  2013,  2016,  2018,  2020,  2022,
    2024,  2026,  2028,  2032,  2034,  2035,  2039,  2041,  2042,  2044,
    2046,  2048,  2050,  2054,  2058,  2059,  2063,  2065,  2067,  2069,
    2071,  2074,  2076,  2080,  2082,  2084,  2087,  2091,  2093,  2094,
    2097,  2099,  2101,  2105,  2106,  2109,  2111,  2113,  2115,  2117,
    2121,  2128,  2129,  2133,  2135,  2137,  2139,  2141,  2143,  2147,
    2149,  2150,  2154,  2156,  2158,  2160,  2162,  2164,  2168,  2170,
    2171,  2175,  2177,  2179,  2181,  2183,  2185,  2189,  2191,  2192,
    2196,  2198,  2200,  2202,  2204,  2206,  2210,  2212,  2213,  2217,
    2219,  2221,  2223,  2225,  2227,  2231,  2233,  2234,  2238,  2240,
    2242,  2244,  2246,  2248,  2252,  2254,  2255,  2258,  2262,  2264,
    2266,  2267,  2270,  2272,  2274,  2276,  2278,  2280,  2282,  2284,
    2287,  2289,  2293,  2295,  2297,  2299,  2302,  2306,  2308,  2309,
    2312,  2314,  2316,  2318,  2320,  2323,  2325,  2329,  2331,  2333,
    2336,  2340,  2342,  2344,  2345,  2348,  2350,  2352,  2354,  2356,
    2358,  2360,  2364,  2366,  2367,  2371,  2373,  2375,  2377,  2379,
    2382,  2384,  2388,  2390,  2392,  2395,  2399,  2401,  2403,  2404,
    2407,  2409,  2411,  2413,  2415,  2417,  2419,  2422,  2424,  2428,
    2430,  2432,  2435,  2437,  2439,  2441,  2443,  2445,  2449,  2451,
    2452,  2456,  2458,  2460,  2462,  2464,  2467,  2469,  2473,  2475,
    2477,  2480,  2484,  2486,  2488,  2489,  2492,  2494,  2496,  2498,
    2500,  2502,  2504,  2507,  2509,  2513,  2515,  2517,  2520,  2522,
    2524,  2526,  2528,  2530,  2534,  2536,  2538,  2540,  2542,  2544,
    2548,  2550,  2552,  2554,  2556,  2560,  2565,  2567,  2569,  2571,
    2573,  2577,  2579,  2581,  2583,  2585,  2589,  2591,  2593,  2595,
    2597,  2601,  2603,  2605,  2607,  2609,  2613,  2618,  2623,  2628,
    2633,  2638,  2643,  2648,  2653,  2658,  2663,  2668,  2673,  2678,
    2683,  2688,  2693,  2698,  2703,  2705,  2707,  2708,  2711,  2715,
    2717,  2719,  2720,  2723,  2725,  2727,  2731,  2735,  2740,  2742,
    2744,  2747,  2749,  2753,  2758,  2763,  2765,  2767,  2769,  2771,
    2773,  2776,  2777,  2780,  2782,  2784,  2786
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     221,     0,    -1,   222,   229,   228,    -1,   223,   224,   225,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   226,    -1,
     227,    -1,    11,    -1,    10,   229,   228,    -1,    15,    -1,
      -1,   230,   256,   336,   390,   442,   537,    -1,    -1,   231,
     232,    -1,    55,    -1,   233,    -1,   234,    -1,    11,    -1,
      10,   235,    56,    -1,   236,   240,   244,   248,   252,    -1,
      -1,   237,    -1,   238,    -1,   239,    -1,    74,    -1,    73,
      -1,    71,     5,    72,    -1,    -1,   241,    -1,   242,    -1,
     243,    -1,    78,    -1,    77,    -1,    75,     5,    76,    -1,
      -1,   245,    -1,   246,    -1,   247,    -1,    82,    -1,    81,
      -1,    79,     5,    80,    -1,    -1,   249,    -1,   250,    -1,
     251,    -1,    86,    -1,    85,    -1,    83,     5,    84,    -1,
      -1,   253,    -1,   254,    -1,   255,    -1,    90,    -1,    89,
      -1,    87,     5,    88,    -1,    -1,   257,   258,    -1,    57,
      -1,   259,    -1,   260,    -1,    10,    58,    -1,    11,    -1,
      10,   261,    58,    -1,   262,    -1,   263,    -1,   262,   263,
      -1,   264,    -1,   280,    -1,   286,    -1,   292,    -1,   298,
      -1,   304,    -1,   310,    -1,   316,    -1,   322,    -1,   265,
     266,   269,    -1,   129,    -1,   267,    -1,   268,    -1,   267,
     268,    -1,   943,    -1,   934,    -1,   969,    -1,   270,    -1,
     271,    -1,    10,   130,    -1,    11,    -1,    10,   272,   130,
      -1,   273,    -1,   274,    -1,   273,   274,    -1,   275,   276,
     279,    -1,   179,    -1,   277,    -1,    -1,   277,   278,    -1,
     939,    -1,   934,    -1,    10,   180,    -1,    11,    -1,   281,
     282,    -1,   141,    -1,   283,    -1,   284,    -1,    10,   142,
      -1,    11,    -1,    10,   285,   142,    -1,     4,    -1,   287,
     288,    -1,   165,    -1,   289,    -1,   290,    -1,    10,   166,
      -1,    11,    -1,    10,   291,   166,    -1,     4,    -1,   293,
     294,    -1,   163,    -1,   295,    -1,   296,    -1,    10,   164,
      -1,    11,    -1,    10,   297,   164,    -1,     4,    -1,   299,
     300,    -1,   135,    -1,   301,    -1,   302,    -1,    10,   136,
      -1,    11,    -1,    10,   303,   136,    -1,     4,    -1,   305,
     306,    -1,   139,    -1,   307,    -1,   308,    -1,    10,   140,
      -1,    11,    -1,    10,   309,   140,    -1,     4,    -1,   311,
     312,    -1,   171,    -1,   313,    -1,   314,    -1,    10,   172,
      -1,    11,    -1,    10,   315,   172,    -1,     4,    -1,   317,
     318,    -1,   189,    -1,   319,    -1,   320,    -1,    10,   190,
      -1,    11,    -1,    10,   321,   190,    -1,     4,    -1,   323,
     324,   325,    -1,   153,    -1,   964,    -1,   326,    -1,   327,
      -1,    10,   154,    -1,    11,    -1,    10,   328,   154,    -1,
     329,    -1,   330,    -1,   329,   330,    -1,   331,   332,   335,
      -1,   151,    -1,   333,    -1,    -1,   333,   334,    -1,   939,
      -1,   951,    -1,   934,    -1,    10,   152,    -1,    11,    -1,
      -1,   337,   338,    -1,    59,    -1,   339,    -1,   340,    -1,
      10,    60,    -1,    11,    -1,    10,   341,    60,    -1,   342,
      -1,   343,    -1,   342,   343,    -1,   344,    -1,   350,    -1,
     357,    -1,   364,    -1,   371,    -1,   376,    -1,   345,   346,
      -1,   183,    -1,   347,    -1,   348,    -1,    10,   184,    -1,
      11,    -1,    10,   349,   184,    -1,     4,    -1,   351,   352,
     355,    -1,   101,    -1,   353,    -1,    -1,   353,   354,    -1,
     947,    -1,   934,    -1,    10,   356,   102,    -1,   988,    -1,
     358,   359,   362,    -1,   103,    -1,   360,    -1,    -1,   360,
     361,    -1,   947,    -1,   934,    -1,    10,   363,   104,    -1,
     988,    -1,   365,   366,   369,    -1,    99,    -1,   367,    -1,
      -1,   367,   368,    -1,   947,    -1,   934,    -1,    10,   370,
     100,    -1,   988,    -1,   372,   373,   374,    -1,    97,    -1,
      -1,   934,    -1,    10,   375,    98,    -1,     6,    -1,   377,
     378,   379,    -1,   153,    -1,   964,    -1,   380,    -1,   381,
      -1,    10,   154,    -1,    11,    -1,    10,   382,   154,    -1,
     383,    -1,   384,    -1,   383,   384,    -1,   385,   386,   389,
      -1,   151,    -1,   387,    -1,    -1,   387,   388,    -1,   939,
      -1,   951,    -1,   934,    -1,    10,   152,    -1,    11,    -1,
      -1,   391,   392,    -1,    61,    -1,   393,    -1,   394,    -1,
      10,    62,    -1,    11,    -1,    10,   395,    62,    -1,   396,
      -1,   397,    -1,   396,   397,    -1,   398,    -1,   404,    -1,
     410,    -1,   416,    -1,   422,    -1,   428,    -1,   399,   400,
      -1,   119,    -1,   401,    -1,   402,    -1,    10,   120,    -1,
      11,    -1,    10,   403,   120,    -1,     4,    -1,   405,   406,
      -1,   117,    -1,   407,    -1,   408,    -1,    10,   118,    -1,
      11,    -1,    10,   409,   118,    -1,     6,    -1,   411,   412,
      -1,   193,    -1,   413,    -1,   414,    -1,    10,   194,    -1,
      11,    -1,    10,   415,   194,    -1,     6,    -1,   417,   418,
      -1,   187,    -1,   419,    -1,   420,    -1,    10,   188,    -1,
      11,    -1,    10,   421,   188,    -1,     4,    -1,   423,   424,
      -1,   167,    -1,   425,    -1,   426,    -1,    10,   168,    -1,
      11,    -1,    10,   427,   168,    -1,   988,    -1,   429,   430,
     431,    -1,   153,    -1,   964,    -1,   432,    -1,   433,    -1,
      10,   154,    -1,    11,    -1,    10,   434,   154,    -1,   435,
      -1,   436,    -1,   435,   436,    -1,   437,   438,   441,    -1,
     151,    -1,   439,    -1,    -1,   439,   440,    -1,   939,    -1,
     951,    -1,   934,    -1,    10,   152,    -1,    11,    -1,    -1,
     443,   444,    -1,    63,    -1,   445,    -1,   446,    -1,    10,
      64,    -1,    11,    -1,    10,   447,    64,    -1,   448,    -1,
     449,    -1,   448,   449,    -1,   450,    -1,   456,    -1,   462,
      -1,   468,    -1,   474,    -1,   480,    -1,   497,    -1,   504,
      -1,   511,    -1,   518,    -1,   523,    -1,   451,   452,    -1,
     175,    -1,   453,    -1,   454,    -1,    10,   176,    -1,    11,
      -1,    10,   455,   176,    -1,     4,    -1,   457,   458,    -1,
     177,    -1,   459,    -1,   460,    -1,    10,   178,    -1,    11,
      -1,    10,   461,   178,    -1,     4,    -1,   463,   464,    -1,
     161,    -1,   465,    -1,   466,    -1,    10,   162,    -1,    11,
      -1,    10,   467,   162,    -1,     4,    -1,   469,   470,    -1,
      91,    -1,   471,    -1,   472,    -1,    10,    92,    -1,    11,
      -1,    10,   473,    92,    -1,     4,    -1,   475,   476,    -1,
     127,    -1,   477,    -1,   478,    -1,    10,   128,    -1,    11,
      -1,    10,   479,   128,    -1,     4,    -1,   481,   482,   483,
      -1,   191,    -1,   970,    -1,   484,    -1,   485,    -1,    10,
     192,    -1,    11,    -1,    10,   486,   192,    -1,   487,    -1,
     488,    -1,   487,   488,    -1,   489,   490,   492,    -1,   185,
      -1,    -1,   490,   491,    -1,   947,    -1,   943,    -1,   930,
      -1,   934,    -1,   493,    -1,   494,    -1,    10,   186,    -1,
      11,    -1,    10,   495,   186,    -1,   496,    -1,     7,    -1,
       6,    -1,   498,   499,   502,    -1,   201,    -1,   500,    -1,
      -1,   500,   501,    -1,   947,    -1,   934,    -1,    10,   503,
     202,    -1,   988,    -1,   505,   506,   509,    -1,   203,    -1,
     507,    -1,    -1,   507,   508,    -1,   947,    -1,   934,    -1,
      10,   510,   204,    -1,   988,    -1,   512,   513,   516,    -1,
     199,    -1,   514,    -1,    -1,   514,   515,    -1,   947,    -1,
     934,    -1,    10,   517,   200,    -1,   988,    -1,   519,   520,
     521,    -1,   197,    -1,    -1,   934,    -1,    10,   522,   198,
      -1,     6,    -1,   524,   525,   526,    -1,   153,    -1,   964,
      -1,   527,    -1,   528,    -1,    10,   154,    -1,    11,    -1,
      10,   529,   154,    -1,   530,    -1,   531,    -1,   530,   531,
      -1,   532,   533,   536,    -1,   151,    -1,   534,    -1,    -1,
     534,   535,    -1,   939,    -1,   951,    -1,   934,    -1,    10,
     152,    -1,    11,    -1,    -1,   538,   539,   542,    -1,    65,
      -1,   540,    -1,    -1,   540,   541,    -1,   967,    -1,   972,
      -1,   956,    -1,   961,    -1,   543,    -1,   544,    -1,    10,
      66,    -1,    11,    -1,    10,   545,    66,    -1,   546,   907,
      -1,   547,    -1,   546,   547,    -1,   548,   549,   554,    -1,
     169,    -1,   550,    -1,    -1,   550,   551,    -1,   552,    -1,
     553,    -1,    36,   990,     6,   990,    -1,    53,     3,   990,
      -1,    10,   555,   571,   577,   690,   787,   884,   170,    -1,
     556,   557,   560,    -1,   175,    -1,   558,    -1,   559,    -1,
     558,   559,    -1,   943,    -1,   934,    -1,   969,    -1,   561,
      -1,   562,    -1,    10,   176,    -1,    11,    -1,    10,   563,
     176,    -1,   564,    -1,   565,    -1,   564,   565,    -1,   566,
     567,   570,    -1,   179,    -1,   568,    -1,    -1,   568,   569,
      -1,   943,    -1,   934,    -1,    10,   180,    -1,    11,    -1,
      -1,   572,   573,    -1,   141,    -1,   574,    -1,   575,    -1,
      10,   142,    -1,    11,    -1,    10,   576,   142,    -1,     4,
      -1,    -1,   578,   579,   580,    -1,   211,    -1,    -1,   966,
      -1,   581,    -1,   582,    -1,    11,    -1,    10,   583,   212,
      -1,   584,   597,   613,   661,    -1,    -1,   585,   586,   587,
      -1,   205,    -1,   971,    -1,   588,    -1,   589,    -1,    10,
     206,    -1,    11,    -1,    10,   590,   206,    -1,   591,    -1,
     592,    -1,   591,   592,    -1,   593,   594,   596,    -1,   209,
      -1,    -1,   594,   595,    -1,   938,    -1,   939,    -1,    10,
     988,   210,    -1,    -1,   598,   599,   600,    -1,   207,    -1,
     971,    -1,   601,    -1,   602,    -1,    10,   208,    -1,    11,
      -1,    10,   603,   208,    -1,   604,    -1,   605,    -1,   604,
     605,    -1,   606,   607,   609,    -1,   209,    -1,    -1,   607,
     608,    -1,   938,    -1,   939,    -1,   610,    -1,   611,    -1,
      10,   210,    -1,    11,    -1,    10,   612,   210,    -1,     4,
      -1,    -1,   614,   615,    -1,   109,    -1,   616,    -1,   617,
      -1,    11,    -1,    10,   618,   110,    -1,   619,   626,   633,
     640,   647,   654,    -1,    -1,   620,   621,   622,    -1,   107,
      -1,   957,    -1,   623,    -1,   624,    -1,    11,    -1,    10,
     625,   108,    -1,   973,    -1,    -1,   627,   628,   629,    -1,
      93,    -1,   957,    -1,   630,    -1,   631,    -1,    11,    -1,
      10,   632,    94,    -1,   973,    -1,    -1,   634,   635,   636,
      -1,    95,    -1,   957,    -1,   637,    -1,   638,    -1,    11,
      -1,    10,   639,    96,    -1,   973,    -1,    -1,   641,   642,
     643,    -1,   137,    -1,   957,    -1,   644,    -1,   645,    -1,
      11,    -1,    10,   646,   138,    -1,   973,    -1,    -1,   648,
     649,   650,    -1,   181,    -1,   957,    -1,   651,    -1,   652,
      -1,    11,    -1,    10,   653,   182,    -1,   973,    -1,    -1,
     655,   656,   657,    -1,   195,    -1,   957,    -1,   658,    -1,
     659,    -1,    11,    -1,    10,   660,   196,    -1,   973,    -1,
      -1,   661,   662,    -1,   663,   664,   667,    -1,   151,    -1,
     665,    -1,    -1,   665,   666,    -1,   971,    -1,   958,    -1,
     951,    -1,   939,    -1,   934,    -1,   668,    -1,   669,    -1,
      10,   152,    -1,    11,    -1,    10,   670,   152,    -1,   671,
      -1,   680,    -1,   672,    -1,   671,   672,    -1,   673,   674,
     676,    -1,   209,    -1,    -1,   674,   675,    -1,   938,    -1,
     939,    -1,   677,    -1,   678,    -1,    10,   210,    -1,    11,
      -1,    10,   679,   210,    -1,   989,    -1,   681,    -1,   680,
     681,    -1,   682,   683,   686,    -1,   125,    -1,   684,    -1,
      -1,   684,   685,    -1,   957,    -1,   951,    -1,   934,    -1,
     687,    -1,   688,    -1,    11,    -1,    10,   689,   126,    -1,
     973,    -1,    -1,   691,   692,   693,    -1,   145,    -1,    -1,
     963,    -1,   694,    -1,   695,    -1,    11,    -1,    10,   696,
     146,    -1,   697,   710,   758,    -1,    -1,   698,   699,   700,
      -1,   205,    -1,   960,    -1,   701,    -1,   702,    -1,    10,
     206,    -1,    11,    -1,    10,   703,   206,    -1,   704,    -1,
     705,    -1,   704,   705,    -1,   706,   707,   709,    -1,   143,
      -1,    -1,   707,   708,    -1,   938,    -1,   939,    -1,    10,
     988,   144,    -1,    -1,   711,   712,    -1,   109,    -1,   713,
      -1,   714,    -1,    11,    -1,    10,   715,   110,    -1,   716,
     723,   730,   737,   744,   751,    -1,    -1,   717,   718,   719,
      -1,   107,    -1,   957,    -1,   720,    -1,   721,    -1,    11,
      -1,    10,   722,   108,    -1,   973,    -1,    -1,   724,   725,
     726,    -1,    93,    -1,   957,    -1,   727,    -1,   728,    -1,
      11,    -1,    10,   729,    94,    -1,   973,    -1,    -1,   731,
     732,   733,    -1,    95,    -1,   957,    -1,   734,    -1,   735,
      -1,    11,    -1,    10,   736,    96,    -1,   973,    -1,    -1,
     738,   739,   740,    -1,   137,    -1,   957,    -1,   741,    -1,
     742,    -1,    11,    -1,    10,   743,   138,    -1,   973,    -1,
      -1,   745,   746,   747,    -1,   181,    -1,   957,    -1,   748,
      -1,   749,    -1,    11,    -1,    10,   750,   182,    -1,   973,
      -1,    -1,   752,   753,   754,    -1,   195,    -1,   957,    -1,
     755,    -1,   756,    -1,    11,    -1,    10,   757,   196,    -1,
     973,    -1,    -1,   758,   759,    -1,   760,   761,   764,    -1,
     151,    -1,   762,    -1,    -1,   762,   763,    -1,   960,    -1,
     958,    -1,   951,    -1,   939,    -1,   934,    -1,   765,    -1,
     766,    -1,    10,   152,    -1,    11,    -1,    10,   767,   152,
      -1,   768,    -1,   777,    -1,   769,    -1,   768,   769,    -1,
     770,   771,   773,    -1,   143,    -1,    -1,   771,   772,    -1,
     938,    -1,   939,    -1,   774,    -1,   775,    -1,    10,   144,
      -1,    11,    -1,    10,   776,   144,    -1,   989,    -1,   778,
      -1,   777,   778,    -1,   779,   780,   783,    -1,   125,    -1,
     781,    -1,    -1,   781,   782,    -1,   957,    -1,   951,    -1,
     934,    -1,   784,    -1,   785,    -1,    11,    -1,    10,   786,
     126,    -1,   973,    -1,    -1,   788,   789,   790,    -1,   115,
      -1,    -1,   962,    -1,   791,    -1,   792,    -1,    11,    -1,
      10,   793,   116,    -1,   794,   807,   855,    -1,    -1,   795,
     796,   797,    -1,   121,    -1,   955,    -1,   798,    -1,   799,
      -1,    10,   122,    -1,    11,    -1,    10,   800,   122,    -1,
     801,    -1,   802,    -1,   801,   802,    -1,   803,   804,   806,
      -1,   113,    -1,    -1,   804,   805,    -1,   938,    -1,   939,
      -1,    10,   988,   114,    -1,    -1,   808,   809,    -1,   109,
      -1,   810,    -1,   811,    -1,    11,    -1,    10,   812,   110,
      -1,   813,   820,   827,   834,   841,   848,    -1,    -1,   814,
     815,   816,    -1,   107,    -1,   957,    -1,   817,    -1,   818,
      -1,    11,    -1,    10,   819,   108,    -1,   973,    -1,    -1,
     821,   822,   823,    -1,    93,    -1,   957,    -1,   824,    -1,
     825,    -1,    11,    -1,    10,   826,    94,    -1,   973,    -1,
      -1,   828,   829,   830,    -1,    95,    -1,   957,    -1,   831,
      -1,   832,    -1,    11,    -1,    10,   833,    96,    -1,   973,
      -1,    -1,   835,   836,   837,    -1,   137,    -1,   957,    -1,
     838,    -1,   839,    -1,    11,    -1,    10,   840,   138,    -1,
     973,    -1,    -1,   842,   843,   844,    -1,   181,    -1,   957,
      -1,   845,    -1,   846,    -1,    11,    -1,    10,   847,   182,
      -1,   973,    -1,    -1,   849,   850,   851,    -1,   195,    -1,
     957,    -1,   852,    -1,   853,    -1,    11,    -1,    10,   854,
     196,    -1,   973,    -1,    -1,   855,   856,    -1,   857,   858,
     861,    -1,   151,    -1,   859,    -1,    -1,   859,   860,    -1,
     955,    -1,   958,    -1,   951,    -1,   939,    -1,   934,    -1,
     862,    -1,   863,    -1,    10,   152,    -1,    11,    -1,    10,
     864,   152,    -1,   865,    -1,   874,    -1,   866,    -1,   865,
     866,    -1,   867,   868,   870,    -1,   113,    -1,    -1,   868,
     869,    -1,   938,    -1,   939,    -1,   871,    -1,   872,    -1,
      10,   114,    -1,    11,    -1,    10,   873,   114,    -1,   989,
      -1,   875,    -1,   874,   875,    -1,   876,   877,   880,    -1,
     125,    -1,   878,    -1,    -1,   878,   879,    -1,   957,    -1,
     951,    -1,   934,    -1,   881,    -1,   882,    -1,    11,    -1,
      10,   883,   126,    -1,   973,    -1,    -1,   885,   886,   887,
      -1,   157,    -1,   965,    -1,   888,    -1,   889,    -1,    10,
     158,    -1,    11,    -1,    10,   890,   158,    -1,   891,    -1,
     892,    -1,   891,   892,    -1,   893,   894,   897,    -1,   155,
      -1,   895,    -1,    -1,   895,   896,    -1,   939,    -1,   930,
      -1,   934,    -1,   959,    -1,   898,    -1,   899,    -1,    10,
     156,    -1,    11,    -1,    10,   900,   156,    -1,   901,    -1,
     902,    -1,   901,   902,    -1,   903,    -1,   904,    -1,   905,
      -1,    69,    -1,    70,    -1,    67,   906,    68,    -1,     5,
      -1,    -1,   908,   909,   910,    -1,   159,    -1,   968,    -1,
     911,    -1,   912,    -1,    10,   160,    -1,    11,    -1,    10,
     913,   160,    -1,   914,    -1,   915,    -1,   914,   915,    -1,
     916,   917,   920,    -1,   173,    -1,   918,    -1,    -1,   918,
     919,    -1,   939,    -1,   930,    -1,   934,    -1,   959,    -1,
     921,    -1,   922,    -1,    10,   174,    -1,    11,    -1,    10,
     923,   174,    -1,   924,    -1,   925,    -1,   924,   925,    -1,
     926,    -1,   927,    -1,   928,    -1,    69,    -1,    70,    -1,
      67,   929,    68,    -1,     5,    -1,   931,    -1,   932,    -1,
     933,    -1,    42,    -1,    41,     3,   990,    -1,   935,    -1,
     936,    -1,   937,    -1,    44,    -1,    43,     3,   990,    -1,
      37,   990,     6,   990,    -1,   940,    -1,   941,    -1,   942,
      -1,    46,    -1,    45,     3,   990,    -1,   944,    -1,   945,
      -1,   946,    -1,    48,    -1,    47,     3,   990,    -1,   948,
      -1,   949,    -1,   950,    -1,    50,    -1,    49,     3,   990,
      -1,   952,    -1,   953,    -1,   954,    -1,    52,    -1,    51,
       3,   990,    -1,    16,   990,     6,   990,    -1,    17,   990,
       6,   990,    -1,    18,   990,     6,   990,    -1,    19,   990,
       6,   990,    -1,    21,   990,     6,   990,    -1,    22,   990,
       6,   990,    -1,    23,   990,     6,   990,    -1,    24,   990,
       6,   990,    -1,    25,   990,     6,   990,    -1,    26,   990,
       6,   990,    -1,    27,   990,     6,   990,    -1,    28,   990,
       6,   990,    -1,    29,   990,     6,   990,    -1,    30,   990,
       6,   990,    -1,    31,   990,     6,   990,    -1,    32,   990,
       6,   990,    -1,    33,   990,     6,   990,    -1,    34,   990,
       6,   990,    -1,   974,    -1,   981,    -1,    -1,   974,   975,
      -1,   976,   977,   980,    -1,   123,    -1,   978,    -1,    -1,
     978,   979,    -1,   987,    -1,   986,    -1,    10,     6,   124,
      -1,   105,   982,   983,    -1,    40,   990,     6,   990,    -1,
     984,    -1,   985,    -1,    10,   106,    -1,    11,    -1,    10,
       4,   106,    -1,    38,   990,     6,   990,    -1,    39,   990,
       6,   990,    -1,     6,    -1,     7,    -1,     4,    -1,     6,
      -1,     7,    -1,   991,     8,    -1,    -1,   991,   992,    -1,
     216,    -1,   217,    -1,   218,    -1,   219,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   191,   191,   192,   194,   201,   208,   208,   210,   210,
     212,   214,   216,   217,   220,   229,   229,   236,   245,   245,
     247,   249,   251,   253,   253,   255,   255,   257,   257,   259,
     265,   265,   267,   267,   269,   269,   271,   277,   277,   279,
     279,   281,   281,   283,   289,   289,   291,   291,   293,   293,
     295,   301,   301,   303,   303,   305,   305,   307,   318,   318,
     320,   334,   334,   336,   336,   338,   340,   342,   342,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   356,   358,
     372,   378,   378,   381,   386,   390,   398,   402,   407,   407,
     409,   411,   413,   413,   415,   419,   428,   433,   433,   436,
     441,   447,   447,   450,   452,   458,   458,   460,   460,   462,
     464,   467,   469,   475,   475,   477,   477,   479,   481,   484,
     486,   492,   492,   494,   494,   496,   498,   501,   503,   509,
     509,   511,   511,   513,   515,   518,   520,   526,   526,   528,
     528,   530,   532,   535,   537,   543,   543,   545,   545,   547,
     549,   552,   554,   560,   560,   562,   562,   564,   566,   569,
     571,   577,   587,   591,   596,   596,   598,   600,   602,   602,
     604,   608,   619,   624,   624,   627,   633,   638,   645,   645,
     649,   649,   651,   662,   662,   664,   664,   666,   668,   670,
     670,   673,   674,   675,   676,   677,   678,   681,   683,   689,
     689,   691,   691,   693,   695,   701,   703,   713,   715,   715,
     718,   724,   729,   731,   736,   738,   748,   750,   750,   753,
     759,   764,   766,   772,   774,   784,   786,   786,   789,   795,
     800,   802,   808,   810,   818,   819,   824,   826,   830,   832,
     838,   848,   852,   857,   857,   859,   861,   863,   863,   865,
     869,   880,   885,   885,   888,   894,   899,   906,   906,   910,
     910,   912,   923,   923,   925,   925,   927,   929,   931,   931,
     934,   935,   936,   937,   938,   939,   942,   944,   950,   950,
     952,   952,   954,   956,   963,   965,   971,   971,   973,   973,
     975,   977,   980,   982,   988,   988,   990,   990,   992,   994,
     997,   999,  1005,  1005,  1007,  1007,  1009,  1011,  1014,  1016,
    1022,  1022,  1024,  1024,  1026,  1028,  1034,  1036,  1042,  1052,
    1056,  1061,  1061,  1063,  1065,  1067,  1067,  1069,  1073,  1084,
    1089,  1089,  1092,  1098,  1103,  1110,  1110,  1113,  1113,  1115,
    1131,  1131,  1133,  1133,  1135,  1137,  1139,  1139,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1155,
    1157,  1163,  1163,  1165,  1165,  1167,  1169,  1176,  1178,  1184,
    1184,  1186,  1186,  1188,  1190,  1193,  1195,  1201,  1201,  1203,
    1203,  1205,  1207,  1210,  1212,  1218,  1218,  1220,  1220,  1222,
    1224,  1227,  1229,  1235,  1235,  1237,  1237,  1239,  1241,  1244,
    1246,  1252,  1261,  1265,  1270,  1270,  1272,  1274,  1276,  1276,
    1278,  1280,  1293,  1293,  1296,  1296,  1296,  1296,  1299,  1299,
    1301,  1301,  1303,  1305,  1318,  1319,  1322,  1324,  1334,  1336,
    1336,  1339,  1345,  1350,  1352,  1358,  1360,  1370,  1372,  1372,
    1375,  1381,  1386,  1388,  1394,  1396,  1406,  1408,  1408,  1411,
    1417,  1422,  1424,  1430,  1432,  1441,  1442,  1447,  1449,  1454,
    1456,  1462,  1472,  1476,  1481,  1481,  1483,  1485,  1487,  1487,
    1489,  1493,  1504,  1509,  1509,  1512,  1518,  1523,  1530,  1530,
    1533,  1533,  1535,  1543,  1548,  1548,  1551,  1558,  1564,  1570,
    1578,  1582,  1587,  1587,  1589,  1591,  1593,  1593,  1595,  1597,
    1605,  1607,  1607,  1609,  1609,  1611,  1620,  1637,  1643,  1645,
    1655,  1660,  1660,  1663,  1668,  1672,  1681,  1685,  1691,  1691,
    1693,  1695,  1697,  1697,  1699,  1702,  1711,  1716,  1716,  1719,
    1725,  1732,  1732,  1735,  1735,  1737,  1739,  1739,  1741,  1741,
    1743,  1745,  1752,  1752,  1754,  1760,  1760,  1768,  1768,  1770,
    1772,  1774,  1776,  1776,  1778,  1780,  1788,  1792,  1797,  1797,
    1799,  1801,  1803,  1803,  1805,  1816,  1825,  1825,  1828,  1829,
    1832,  1835,  1835,  1837,  1839,  1847,  1851,  1856,  1856,  1858,
    1860,  1862,  1862,  1864,  1875,  1884,  1884,  1887,  1888,  1892,
    1893,  1895,  1895,  1897,  1899,  1902,  1902,  1904,  1909,  1909,
    1911,  1913,  1915,  1917,  1917,  1926,  1928,  1935,  1935,  1937,
    1939,  1941,  1944,  1944,  1954,  1956,  1963,  1963,  1965,  1967,
    1969,  1972,  1972,  1981,  1983,  1990,  1990,  1992,  1994,  1996,
    1999,  1999,  2008,  2010,  2017,  2017,  2019,  2021,  2023,  2026,
    2026,  2035,  2037,  2044,  2044,  2046,  2048,  2050,  2053,  2053,
    2062,  2064,  2071,  2071,  2073,  2075,  2077,  2080,  2080,  2082,
    2087,  2100,  2107,  2107,  2110,  2120,  2130,  2136,  2142,  2149,
    2149,  2151,  2151,  2153,  2155,  2155,  2157,  2157,  2159,  2166,
    2175,  2175,  2178,  2184,  2192,  2192,  2194,  2194,  2196,  2198,
    2207,  2207,  2209,  2220,  2229,  2236,  2236,  2239,  2245,  2251,
    2259,  2259,  2261,  2263,  2266,  2270,  2270,  2272,  2280,  2280,
    2288,  2288,  2290,  2292,  2294,  2296,  2296,  2298,  2300,  2308,
    2312,  2317,  2317,  2319,  2321,  2324,  2324,  2326,  2334,  2344,
    2344,  2347,  2348,  2351,  2354,  2354,  2356,  2361,  2361,  2364,
    2366,  2368,  2370,  2370,  2379,  2381,  2388,  2388,  2390,  2392,
    2394,  2396,  2396,  2405,  2407,  2414,  2414,  2416,  2418,  2420,
    2423,  2423,  2432,  2434,  2441,  2441,  2443,  2445,  2447,  2450,
    2450,  2459,  2461,  2468,  2468,  2470,  2472,  2474,  2477,  2477,
    2486,  2488,  2495,  2495,  2497,  2499,  2501,  2504,  2504,  2513,
    2515,  2522,  2522,  2524,  2526,  2528,  2531,  2531,  2533,  2539,
    2552,  2560,  2560,  2563,  2573,  2583,  2589,  2595,  2604,  2604,
    2606,  2606,  2608,  2610,  2610,  2612,  2612,  2614,  2619,  2629,
    2629,  2632,  2637,  2645,  2645,  2647,  2647,  2649,  2651,  2657,
    2657,  2659,  2670,  2679,  2686,  2686,  2689,  2695,  2701,  2709,
    2709,  2711,  2713,  2716,  2719,  2719,  2721,  2728,  2728,  2736,
    2736,  2738,  2740,  2742,  2744,  2744,  2746,  2749,  2757,  2761,
    2766,  2766,  2768,  2770,  2772,  2772,  2774,  2782,  2791,  2791,
    2794,  2795,  2798,  2801,  2801,  2803,  2808,  2808,  2810,  2812,
    2814,  2816,  2816,  2825,  2827,  2834,  2834,  2836,  2838,  2840,
    2842,  2842,  2851,  2853,  2860,  2860,  2862,  2864,  2866,  2869,
    2869,  2878,  2880,  2887,  2887,  2889,  2891,  2893,  2896,  2896,
    2905,  2907,  2914,  2914,  2916,  2918,  2920,  2923,  2923,  2932,
    2934,  2941,  2941,  2943,  2945,  2947,  2950,  2950,  2959,  2961,
    2968,  2968,  2970,  2972,  2974,  2977,  2977,  2979,  2985,  2998,
    3005,  3005,  3008,  3018,  3028,  3034,  3040,  3047,  3047,  3049,
    3049,  3051,  3053,  3053,  3055,  3055,  3057,  3064,  3073,  3073,
    3077,  3082,  3090,  3090,  3092,  3092,  3094,  3096,  3103,  3103,
    3105,  3116,  3125,  3132,  3132,  3135,  3141,  3147,  3155,  3155,
    3157,  3159,  3161,  3165,  3165,  3167,  3172,  3181,  3185,  3190,
    3190,  3192,  3194,  3196,  3196,  3198,  3202,  3213,  3220,  3220,
    3223,  3229,  3235,  3243,  3253,  3257,  3262,  3262,  3264,  3266,
    3268,  3268,  3270,  3275,  3279,  3281,  3281,  3283,  3285,  3296,
    3296,  3298,  3303,  3312,  3316,  3321,  3321,  3323,  3325,  3327,
    3327,  3329,  3333,  3344,  3351,  3351,  3354,  3359,  3365,  3371,
    3380,  3384,  3389,  3389,  3391,  3393,  3395,  3395,  3397,  3402,
    3406,  3408,  3408,  3410,  3412,  3422,  3428,  3428,  3430,  3433,
    3436,  3442,  3442,  3444,  3447,  3450,  3458,  3464,  3464,  3466,
    3469,  3472,  3478,  3478,  3480,  3483,  3486,  3492,  3492,  3494,
    3497,  3500,  3506,  3506,  3508,  3511,  3534,  3540,  3548,  3554,
    3567,  3576,  3582,  3590,  3596,  3602,  3608,  3614,  3620,  3628,
    3634,  3642,  3647,  3653,  3679,  3684,  3686,  3686,  3688,  3690,
    3699,  3701,  3701,  3703,  3703,  3705,  3713,  3715,  3720,  3720,
    3722,  3722,  3724,  3747,  3755,  3769,  3770,  3774,  3775,  3776,
    3778,  3780,  3780,  3782,  3783,  3784,  3785
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
  "osrlAttributes", "osrlContent", "osrlEmpty", "osrlLaden", "osrlEnd",
  "osrlBody", "headerElement", "headerElementStart",
  "headerElementContent", "headerElementEmpty", "headerElementLaden",
  "headerElementBody", "fileName", "fileNameContent", "fileNameEmpty",
  "fileNameLaden", "fileSource", "fileSourceContent", "fileSourceEmpty",
  "fileSourceLaden", "fileDescription", "fileDescriptionContent",
  "fileDescriptionEmpty", "fileDescriptionLaden", "fileCreator",
  "fileCreatorContent", "fileCreatorEmpty", "fileCreatorLaden",
  "fileLicence", "fileLicenceContent", "fileLicenceEmpty",
  "fileLicenceLaden", "generalElement", "generalElementStart",
  "generalElementContent", "generalElementEmpty", "generalElementLaden",
  "generalElementBody", "generalElementList", "generalChild",
  "generalStatus", "generalStatusStart", "generalStatusAttributes",
  "generalStatusAttList", "generalStatusATT", "generalStatusContent",
  "generalStatusEmpty", "generalStatusLaden", "generalStatusBody",
  "generalSubstatusArray", "generalSubstatus", "generalSubstatusStart",
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
  "varValueArray", "varValue", "varValueStart", "varValueAttList",
  "varValueAtt", "varValueContent", "variableValuesString",
  "variableValuesStringStart", "numberOfVarStringATT",
  "variableValuesStringContent", "variableValuesStringEmpty",
  "variableValuesStringLaden", "variableValuesStringBody",
  "varValueStringArray", "varValueString", "varValueStringStart",
  "varValueStringAttList", "varValueStringAtt", "varValueStringContent",
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
  "otherVar", "otherVarStart", "otherVarAttList", "otherVarAtt",
  "otherVarContent", "otherVarEmpty", "otherVarLaden", "otherVarBody",
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
  "objValueAttList", "objValueAtt", "objValueContent",
  "objectiveBasisStatus", "objectiveBasisStatusStart",
  "objectiveBasisStatusContent", "objectiveBasisStatusEmpty",
  "objectiveBasisStatusLaden", "objectiveBasisStatusBody",
  "objectivesBasic", "objectivesBasicStart",
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
  "otherObj", "otherObjStart", "otherObjAttList", "otherObjAtt",
  "otherObjContent", "otherObjEmpty", "otherObjLaden", "otherObjBody",
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
  "dualValueAttList", "dualValueAtt", "dualValueContent",
  "slackBasisStatus", "slackBasisStatusStart", "slackBasisStatusContent",
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
  "otherConAttList", "otherConAtt", "otherConContent", "otherConEmpty",
  "otherConLaden", "otherConBody", "otherConEnumerationList",
  "otherConEnumeration", "otherConEnumerationStart",
  "otherConEnumerationAttributes", "otherConEnumerationAttList",
  "otherConEnumerationATT", "otherConEnumerationContent",
  "otherConEnumerationEmpty", "otherConEnumerationLaden",
  "otherConEnumerationBody", "otherSolutionResults",
  "otherSolutionResultsStart", "numberOfOtherSolutionResults",
  "otherSolutionResultsContent", "otherSolutionResultsEmpty",
  "otherSolutionResultsLaden", "otherSolutionResultsBody",
  "otherSolutionResultArray", "otherSolutionResult",
  "otherSolutionResultStart", "otherSolutionResultAttributes",
  "otherSolutionResultAttList", "otherSolutionResultAtt",
  "otherSolutionResultContent", "otherSolutionResultEmpty",
  "otherSolutionResultLaden", "otherSolutionResultBody",
  "otherSolutionResultItemArray", "otherSolutionResultItem",
  "otherSolutionResultItemContent", "otherSolutionResultItemEmpty",
  "otherSolutionResultItemLaden", "otherSolutionResultItemBody",
  "otherSolverOutput", "otherSolverOutputStart",
  "numberOfSolverOutputsATT", "otherSolverOutputContent",
  "otherSolverOutputEmpty", "otherSolverOutputLaden",
  "otherSolverOutputBody", "solverOutputArray", "solverOutput",
  "solverOutputStart", "solverOutputAttributes", "solverOutputAttList",
  "solverOutputAtt", "solverOutputContent", "solverOutputEmpty",
  "solverOutputLaden", "solverOutputBody", "solverOutputItemArray",
  "solverOutputItem", "solverOutputItemContent", "solverOutputItemEmpty",
  "solverOutputItemLaden", "solverOutputItemBody", "categoryAttribute",
  "categoryAtt", "categoryAttEmpty", "categoryAttContent",
  "descriptionAttribute", "descriptionAtt", "descriptionAttEmpty",
  "descriptionAttContent", "idxAttribute", "nameAttribute", "nameAtt",
  "nameAttEmpty", "nameAttContent", "typeAttribute", "typeAtt",
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
     226,   227,   228,   228,   229,   230,   230,   231,   232,   232,
     233,   234,   235,   236,   236,   237,   237,   238,   238,   239,
     240,   240,   241,   241,   242,   242,   243,   244,   244,   245,
     245,   246,   246,   247,   248,   248,   249,   249,   250,   250,
     251,   252,   252,   253,   253,   254,   254,   255,   256,   256,
     257,   258,   258,   259,   259,   260,   261,   262,   262,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   264,   265,
     266,   267,   267,   268,   268,   268,   269,   269,   270,   270,
     271,   272,   273,   273,   274,   275,   276,   277,   277,   278,
     278,   279,   279,   280,   281,   282,   282,   283,   283,   284,
     285,   286,   287,   288,   288,   289,   289,   290,   291,   292,
     293,   294,   294,   295,   295,   296,   297,   298,   299,   300,
     300,   301,   301,   302,   303,   304,   305,   306,   306,   307,
     307,   308,   309,   310,   311,   312,   312,   313,   313,   314,
     315,   316,   317,   318,   318,   319,   319,   320,   321,   322,
     323,   324,   325,   325,   326,   326,   327,   328,   329,   329,
     330,   331,   332,   333,   333,   334,   334,   334,   335,   335,
     336,   336,   337,   338,   338,   339,   339,   340,   341,   342,
     342,   343,   343,   343,   343,   343,   343,   344,   345,   346,
     346,   347,   347,   348,   349,   350,   351,   352,   353,   353,
     354,   354,   355,   356,   357,   358,   359,   360,   360,   361,
     361,   362,   363,   364,   365,   366,   367,   367,   368,   368,
     369,   370,   371,   372,   373,   373,   374,   375,   376,   377,
     378,   379,   379,   380,   380,   381,   382,   383,   383,   384,
     385,   386,   387,   387,   388,   388,   388,   389,   389,   390,
     390,   391,   392,   392,   393,   393,   394,   395,   396,   396,
     397,   397,   397,   397,   397,   397,   398,   399,   400,   400,
     401,   401,   402,   403,   404,   405,   406,   406,   407,   407,
     408,   409,   410,   411,   412,   412,   413,   413,   414,   415,
     416,   417,   418,   418,   419,   419,   420,   421,   422,   423,
     424,   424,   425,   425,   426,   427,   428,   429,   430,   431,
     431,   432,   432,   433,   434,   435,   435,   436,   437,   438,
     439,   439,   440,   440,   440,   441,   441,   442,   442,   443,
     444,   444,   445,   445,   446,   447,   448,   448,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   450,
     451,   452,   452,   453,   453,   454,   455,   456,   457,   458,
     458,   459,   459,   460,   461,   462,   463,   464,   464,   465,
     465,   466,   467,   468,   469,   470,   470,   471,   471,   472,
     473,   474,   475,   476,   476,   477,   477,   478,   479,   480,
     481,   482,   483,   483,   484,   484,   485,   486,   487,   487,
     488,   489,   490,   490,   491,   491,   491,   491,   492,   492,
     493,   493,   494,   495,   496,   496,   497,   498,   499,   500,
     500,   501,   501,   502,   503,   504,   505,   506,   507,   507,
     508,   508,   509,   510,   511,   512,   513,   514,   514,   515,
     515,   516,   517,   518,   519,   520,   520,   521,   522,   523,
     524,   525,   526,   526,   527,   527,   528,   529,   530,   530,
     531,   532,   533,   534,   534,   535,   535,   535,   536,   536,
     537,   537,   538,   539,   540,   540,   541,   541,   541,   541,
     542,   542,   543,   543,   544,   545,   546,   546,   547,   548,
     549,   550,   550,   551,   551,   552,   553,   554,   555,   556,
     557,   558,   558,   559,   559,   559,   560,   560,   561,   561,
     562,   563,   564,   564,   565,   566,   567,   568,   568,   569,
     569,   570,   570,   571,   571,   572,   573,   573,   574,   574,
     575,   576,   577,   577,   578,   579,   579,   580,   580,   581,
     582,   583,   584,   584,   585,   586,   587,   587,   588,   588,
     589,   590,   591,   591,   592,   593,   594,   594,   595,   595,
     596,   597,   597,   598,   599,   600,   600,   601,   601,   602,
     603,   604,   604,   605,   606,   607,   607,   608,   608,   609,
     609,   610,   610,   611,   612,   613,   613,   614,   615,   615,
     616,   617,   618,   619,   619,   620,   621,   622,   622,   623,
     624,   625,   626,   626,   627,   628,   629,   629,   630,   631,
     632,   633,   633,   634,   635,   636,   636,   637,   638,   639,
     640,   640,   641,   642,   643,   643,   644,   645,   646,   647,
     647,   648,   649,   650,   650,   651,   652,   653,   654,   654,
     655,   656,   657,   657,   658,   659,   660,   661,   661,   662,
     663,   664,   665,   665,   666,   666,   666,   666,   666,   667,
     667,   668,   668,   669,   670,   670,   671,   671,   672,   673,
     674,   674,   675,   675,   676,   676,   677,   677,   678,   679,
     680,   680,   681,   682,   683,   684,   684,   685,   685,   685,
     686,   686,   687,   688,   689,   690,   690,   691,   692,   692,
     693,   693,   694,   695,   696,   697,   697,   698,   699,   700,
     700,   701,   701,   702,   703,   704,   704,   705,   706,   707,
     707,   708,   708,   709,   710,   710,   711,   712,   712,   713,
     714,   715,   716,   716,   717,   718,   719,   719,   720,   721,
     722,   723,   723,   724,   725,   726,   726,   727,   728,   729,
     730,   730,   731,   732,   733,   733,   734,   735,   736,   737,
     737,   738,   739,   740,   740,   741,   742,   743,   744,   744,
     745,   746,   747,   747,   748,   749,   750,   751,   751,   752,
     753,   754,   754,   755,   756,   757,   758,   758,   759,   760,
     761,   762,   762,   763,   763,   763,   763,   763,   764,   764,
     765,   765,   766,   767,   767,   768,   768,   769,   770,   771,
     771,   772,   772,   773,   773,   774,   774,   775,   776,   777,
     777,   778,   779,   780,   781,   781,   782,   782,   782,   783,
     783,   784,   785,   786,   787,   787,   788,   789,   789,   790,
     790,   791,   792,   793,   794,   794,   795,   796,   797,   797,
     798,   798,   799,   800,   801,   801,   802,   803,   804,   804,
     805,   805,   806,   807,   807,   808,   809,   809,   810,   811,
     812,   813,   813,   814,   815,   816,   816,   817,   818,   819,
     820,   820,   821,   822,   823,   823,   824,   825,   826,   827,
     827,   828,   829,   830,   830,   831,   832,   833,   834,   834,
     835,   836,   837,   837,   838,   839,   840,   841,   841,   842,
     843,   844,   844,   845,   846,   847,   848,   848,   849,   850,
     851,   851,   852,   853,   854,   855,   855,   856,   857,   858,
     859,   859,   860,   860,   860,   860,   860,   861,   861,   862,
     862,   863,   864,   864,   865,   865,   866,   867,   868,   868,
     869,   869,   870,   870,   871,   871,   872,   873,   874,   874,
     875,   876,   877,   878,   878,   879,   879,   879,   880,   880,
     881,   882,   883,   884,   884,   885,   886,   887,   887,   888,
     888,   889,   890,   891,   891,   892,   893,   894,   895,   895,
     896,   896,   896,   896,   897,   897,   898,   898,   899,   900,
     901,   901,   902,   903,   903,   904,   904,   905,   906,   907,
     907,   908,   909,   910,   910,   911,   911,   912,   913,   914,
     914,   915,   916,   917,   918,   918,   919,   919,   919,   919,
     920,   920,   921,   921,   922,   923,   924,   924,   925,   926,
     926,   927,   927,   928,   929,   930,   931,   931,   932,   933,
     934,   935,   935,   936,   937,   938,   939,   940,   940,   941,
     942,   943,   944,   944,   945,   946,   947,   948,   948,   949,
     950,   951,   952,   952,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   964,   965,   966,   967,   968,
     969,   970,   971,   972,   973,   973,   974,   974,   975,   976,
     977,   978,   978,   979,   979,   980,   981,   982,   983,   983,
     984,   984,   985,   986,   987,   988,   988,   989,   989,   989,
     990,   991,   991,   992,   992,   992,   992
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     0,     6,     0,     2,     1,     1,     1,
       1,     3,     5,     0,     1,     1,     1,     1,     1,     3,
       0,     1,     1,     1,     1,     1,     3,     0,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     1,     1,     1,     3,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       0,     2,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     3,     1,     1,     0,     2,
       1,     1,     3,     1,     3,     1,     1,     0,     2,     1,
       1,     3,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     0,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       2,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     3,     1,     1,     0,
       2,     1,     1,     3,     1,     3,     1,     1,     0,     2,
       1,     1,     3,     1,     3,     1,     1,     0,     2,     1,
       1,     3,     1,     3,     1,     0,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       0,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     2,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     4,     3,     8,     3,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     2,     1,     0,     2,     1,     1,     1,     2,     1,
       3,     1,     0,     3,     1,     0,     1,     1,     1,     1,
       3,     4,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     0,     2,     1,     1,
       3,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     0,     2,     1,     1,     1,
       1,     2,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     3,     6,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     1,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     0,     1,
       1,     1,     1,     3,     3,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     0,
       2,     1,     1,     3,     0,     2,     1,     1,     1,     1,
       3,     6,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     2,     3,     1,     0,
       2,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     0,     1,     1,
       1,     1,     3,     3,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     0,     2,
       1,     1,     3,     0,     2,     1,     1,     1,     1,     3,
       6,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     1,     2,     3,     1,     0,     2,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     4,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     3,     3,     4,     1,     1,
       2,     1,     3,     4,     4,     1,     1,     1,     1,     1,
       2,     0,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    15,     6,     1,    17,    13,    58,
       0,     7,     0,    12,     2,    60,   180,     0,    23,    20,
      16,    18,    19,    15,    10,     3,     8,     9,   182,   259,
       0,     0,    64,    59,    61,    62,     0,    28,    27,     0,
      30,    24,    25,    26,    13,   261,   337,     0,     0,   186,
     181,   183,   184,    63,    79,   128,   136,   104,   160,   120,
     112,   144,   152,     0,    66,    67,    69,     0,    70,     0,
      71,     0,    72,     0,    73,     0,    74,     0,    75,     0,
      76,     0,    77,     0,     0,    21,     0,    35,    34,    37,
      31,    32,    33,    11,   339,   480,     0,     0,   265,   260,
     262,   263,   185,   233,   224,   206,   215,   239,   198,     0,
     188,   189,   191,     0,   192,   208,   193,   217,   194,   226,
     195,   234,   196,     0,    65,    68,  1131,     0,  1063,     0,
    1074,     0,    80,    81,    84,  1060,  1061,  1062,    83,  1071,
    1072,  1073,    85,     0,   108,   103,   105,   106,     0,   116,
     111,   113,   114,     0,   124,   119,   121,   122,     0,   132,
     127,   129,   130,     0,   140,   135,   137,   138,     0,   148,
     143,   145,   146,     0,   156,   151,   153,   154,  1131,     0,
     161,    29,     0,     0,    42,    41,    44,    38,    39,    40,
     482,    14,   484,     0,   343,   338,   340,   341,   264,   285,
     277,   317,   309,   301,   293,     0,   267,   268,   270,     0,
     271,     0,   272,     0,   273,     0,   274,     0,   275,     0,
     187,   190,     0,   202,   197,   199,   200,     0,   207,     0,
     216,     0,   225,     0,   235,     0,   240,     0,     0,  1131,
    1131,     0,    89,    78,    86,    87,    82,   110,   107,     0,
     118,   115,     0,   126,   123,     0,   134,   131,     0,   142,
     139,     0,   150,   147,     0,   158,   155,     0,     0,     0,
     165,   159,   162,   163,    36,     0,     0,    49,    48,    51,
      45,    46,    47,     0,   483,   342,   384,   392,   460,   376,
     360,   368,   400,   454,   445,   427,   436,     0,   345,   346,
     348,     0,   349,     0,   350,     0,   351,     0,   352,     0,
     353,     0,   354,   429,   355,   438,   356,   447,   357,   455,
     358,     0,   266,   269,     0,   281,   276,   278,   279,     0,
     289,   284,   286,   287,     0,   297,   292,   294,   295,     0,
     305,   300,   302,   303,     0,   313,   308,   310,   311,     0,
     318,   204,   201,     0,     0,   205,     0,  1079,   209,   211,
     210,  1076,  1077,  1078,     0,   214,   218,   220,   219,     0,
     223,   227,   229,   228,     0,   232,     0,   244,   238,   241,
     242,  1131,  1130,  1133,  1134,  1135,  1136,  1132,  1064,  1075,
      88,    95,     0,    91,    92,    97,   109,   117,   125,   133,
     141,   149,   157,  1131,   171,   164,     0,   167,   168,   173,
      43,     0,     0,    56,    55,    22,    52,    53,    54,     0,
     493,   481,   490,   491,  1131,  1131,  1131,  1131,   485,   488,
     489,   486,   487,   344,   347,     0,   364,   359,   361,   362,
       0,   372,   367,   369,   370,     0,   380,   375,   377,   378,
       0,   388,   383,   385,   386,     0,   396,   391,   393,   394,
    1131,     0,   401,     0,   428,     0,   437,     0,   446,     0,
     456,     0,   461,   283,   280,     0,   291,   288,     0,   299,
     296,     0,   307,   304,     0,  1125,  1126,   312,     0,   315,
       0,   322,   316,   319,   320,   203,     0,   213,  1131,     0,
     222,     0,   231,   237,     0,   250,   243,     0,   246,   247,
     252,  1100,    90,    93,     0,    96,  1095,   166,   169,     0,
     172,    50,     0,   492,   499,     0,  1019,   496,   501,     0,
       0,     0,     0,   366,   363,     0,   374,   371,     0,   382,
     379,     0,   390,   387,     0,   398,   395,     0,     0,     0,
     405,   399,   402,   403,     0,   426,   430,   432,   431,     0,
     435,   439,   441,   440,     0,   444,   448,   450,   449,     0,
     453,     0,   465,   459,   462,   463,   282,   290,   298,   306,
     314,   328,   321,     0,   324,   325,   330,   212,  1080,   221,
     230,   236,   245,   248,     0,   251,     0,   102,    94,     0,
    1069,    98,   100,    99,  1066,  1067,  1068,     0,   179,   170,
       0,  1084,   174,   177,   175,   176,  1081,  1082,  1083,    57,
     494,  1021,   497,   495,     0,     0,   500,  1131,  1131,  1131,
    1131,   365,   373,   381,   389,   397,  1131,   411,   404,     0,
     407,   408,   412,     0,   434,     0,   443,     0,   452,   458,
       0,   471,   464,     0,   467,   468,   473,   323,   326,     0,
     329,     0,   258,   249,   253,   256,   254,   255,   101,  1131,
     178,  1131,  1131,     0,  1022,     0,   498,  1131,     0,   502,
     503,   504,  1087,  1092,  1098,  1103,  1101,   406,   409,     0,
     433,   442,   451,   457,   466,   469,     0,   472,     0,   336,
     327,   331,   334,   332,   333,   257,  1070,  1085,     0,     0,
    1026,  1020,  1023,  1024,   509,   533,     0,     0,  1131,     0,
     421,     0,  1058,   413,   410,   418,   419,   416,  1055,  1056,
    1057,   417,   415,   414,     0,   479,   470,   474,   477,   475,
     476,   335,  1131,  1025,  1032,     0,  1028,  1029,  1034,   535,
     542,     0,     0,   510,   511,   514,   513,   515,  1131,   506,
     425,   424,   420,     0,   423,  1131,   478,  1099,  1027,  1030,
       0,  1033,   544,   705,   545,     0,   539,   534,   536,   537,
       0,   519,   508,   516,   517,   512,   505,   422,  1059,     0,
    1043,  1031,  1040,  1041,  1131,  1035,  1037,  1038,  1036,  1039,
     707,   844,   708,  1131,     0,   546,   541,   538,     0,   518,
     525,     0,   521,   522,   527,     0,  1051,  1052,  1042,     0,
    1045,  1046,  1048,  1049,  1050,     0,   846,   983,   847,  1131,
       0,   709,     0,   552,   549,   543,   547,   548,   540,   520,
     523,     0,   526,  1054,     0,  1044,  1047,  1131,   985,     0,
       0,  1131,     0,   848,     0,   715,   712,   706,   710,   711,
    1131,   554,     0,   571,     0,     0,   532,   524,   528,   530,
     529,  1053,  1090,   507,  1131,     0,   986,     0,   854,   851,
     845,   849,   850,  1131,   717,     0,   734,     0,  1097,   550,
     573,   595,     0,  1131,     0,   555,   531,     0,     0,   990,
     984,   987,   988,  1131,   856,     0,   873,     0,  1094,   713,
     736,   796,     0,  1131,     0,   718,   597,   657,     0,     0,
     574,     0,     0,   559,   553,   556,   557,  1131,   996,   989,
       0,   992,   993,   998,  1093,   852,   875,   935,     0,  1131,
       0,   857,   714,   742,   739,   735,   737,   738,     0,     0,
     722,   716,   719,   720,   551,   603,   600,   596,   598,   599,
       0,   578,   572,   575,   576,  1131,   558,   565,     0,   561,
     562,   566,  1096,   991,   994,     0,   997,   853,   881,   878,
     874,   876,   877,     0,     0,   861,   855,   858,   859,   799,
     797,   801,   744,     0,   751,     0,  1131,   728,   721,     0,
     724,   725,   729,   660,   658,   662,   605,     0,   612,     0,
     577,   584,     0,   580,   581,   585,  1102,   560,   563,     0,
       0,  1007,   995,  1004,  1005,   999,  1001,  1002,  1000,  1003,
     938,   936,   940,   883,     0,   890,     0,  1131,   867,   860,
       0,   863,   864,   868,     0,   800,   740,   753,   760,     0,
    1131,     0,   745,  1091,   723,   726,     0,     0,   661,   601,
     614,   621,     0,     0,   606,   579,   582,     0,     0,  1131,
     567,   564,   568,   569,     0,  1015,  1016,  1006,     0,  1009,
    1010,  1012,  1013,  1014,     0,   939,   879,   892,   899,     0,
       0,   884,  1086,   862,   865,     0,     0,   811,   798,   808,
     809,  1131,   802,   807,   806,   805,   804,   803,   762,   769,
       0,     0,   754,     0,  1106,   748,   743,   746,   747,     0,
     730,   727,   731,   732,     0,   672,   659,   669,   670,   663,
     668,   667,   666,   665,   664,   623,   630,     0,     0,   615,
    1106,   609,   604,   607,   608,     0,   592,   586,   583,   589,
     590,   587,   588,     0,     0,  1018,     0,  1008,  1011,     0,
     950,   937,   947,   948,   941,   946,   945,   944,   942,   943,
     901,   908,     0,     0,   893,  1106,   887,   882,   885,   886,
       0,   869,   866,   870,   871,   832,   818,   810,     0,   813,
     815,   819,   814,   829,   834,     0,   771,   778,     0,     0,
     763,  1106,   757,   752,   755,   756,  1131,     0,     0,   750,
    1104,  1105,     0,   693,   671,   679,     0,   674,   676,   680,
     675,   690,   695,   632,   639,     0,     0,   624,  1106,   618,
     613,   616,   617,     0,   611,   594,   591,     0,   570,  1131,
    1017,   957,   971,   949,     0,   952,   954,   958,   953,   968,
     973,   910,   917,     0,     0,   902,  1106,   896,   891,   894,
     895,     0,   889,     0,   812,   816,     0,   830,     0,   833,
    1131,   780,   787,     0,     0,   772,  1106,   766,   761,   764,
     765,     0,   759,  1088,  1131,     0,   749,  1109,  1107,  1111,
     733,   673,   677,     0,   691,     0,   694,   641,   648,     0,
       0,   633,  1106,   627,   622,   625,   626,     0,   620,   610,
     593,  1065,   951,   955,     0,   969,     0,   972,   919,   926,
       0,     0,   911,  1106,   905,   900,   903,   904,     0,   898,
     888,   872,     0,   826,   820,   817,   823,   824,   821,   822,
    1106,   841,   831,   839,   840,   835,   838,   837,   836,  1089,
     789,   741,     0,     0,   781,  1106,   775,   770,   773,   774,
       0,   768,   758,     0,     0,  1121,  1116,  1118,  1119,     0,
    1110,     0,   687,   681,   678,   684,   685,   682,   683,  1106,
     702,   692,   700,   701,   696,   699,   698,   697,   650,   602,
       0,     0,   642,  1106,   636,   631,   634,   635,     0,   629,
     619,     0,   965,   959,   956,   962,   963,   960,   961,  1106,
     980,   970,   978,   979,   974,   977,   976,   975,   928,   880,
       0,     0,   920,  1106,   914,   909,   912,   913,     0,   907,
     897,  1127,  1128,  1129,   825,     0,   828,     0,   843,     0,
     790,  1106,   784,   779,   782,   783,     0,   777,   767,  1131,
       0,  1120,     0,  1108,  1131,  1131,  1112,  1114,  1113,   686,
       0,   689,     0,   704,     0,   651,  1106,   645,   640,   643,
     644,     0,   638,   628,   964,     0,   967,     0,   982,     0,
     929,  1106,   923,   918,   921,   922,     0,   916,   906,   827,
     842,  1106,   793,   788,   791,   792,     0,   786,   776,  1117,
    1122,     0,     0,     0,   688,   703,  1106,   654,   649,   652,
     653,     0,   647,   637,   966,   981,  1106,   932,   927,   930,
     931,     0,   925,   915,     0,   795,   785,  1115,  1131,  1131,
       0,   656,   646,     0,   934,   924,   794,  1123,  1124,   655,
     933
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    25,    26,    27,    14,     8,
       9,    10,    20,    21,    22,    39,    40,    41,    42,    43,
      89,    90,    91,    92,   186,   187,   188,   189,   279,   280,
     281,   282,   415,   416,   417,   418,    16,    17,    33,    34,
      35,    63,    64,    65,    66,    67,   131,   132,   133,   243,
     244,   245,   392,   393,   394,   395,   514,   515,   601,   598,
      68,    69,   145,   146,   147,   249,    70,    71,   150,   151,
     152,   252,    72,    73,   155,   156,   157,   255,    74,    75,
     160,   161,   162,   258,    76,    77,   165,   166,   167,   261,
      78,    79,   170,   171,   172,   264,    80,    81,   175,   176,
     177,   267,    82,    83,   179,   271,   272,   273,   406,   407,
     408,   409,   519,   520,   612,   609,    29,    30,    50,    51,
      52,   109,   110,   111,   112,   113,   224,   225,   226,   353,
     114,   115,   227,   228,   358,   355,   496,   116,   117,   229,
     230,   366,   365,   499,   118,   119,   231,   232,   371,   370,
     501,   120,   121,   233,   375,   504,   122,   123,   235,   378,
     379,   380,   507,   508,   509,   510,   594,   595,   664,   663,
      46,    47,    99,   100,   101,   205,   206,   207,   208,   209,
     326,   327,   328,   475,   210,   211,   331,   332,   333,   478,
     212,   213,   336,   337,   338,   481,   214,   215,   341,   342,
     343,   484,   216,   217,   346,   347,   348,   488,   218,   219,
     349,   492,   493,   494,   583,   584,   585,   586,   659,   660,
     701,   700,    95,    96,   195,   196,   197,   297,   298,   299,
     300,   301,   437,   438,   439,   535,   302,   303,   442,   443,
     444,   538,   304,   305,   447,   448,   449,   541,   306,   307,
     452,   453,   454,   544,   308,   309,   457,   458,   459,   547,
     310,   311,   461,   551,   552,   553,   639,   640,   641,   642,
     689,   723,   724,   725,   726,   763,   764,   312,   313,   463,
     464,   556,   555,   643,   314,   315,   465,   466,   561,   560,
     645,   316,   317,   467,   468,   566,   565,   647,   318,   319,
     469,   570,   650,   320,   321,   471,   573,   574,   575,   653,
     654,   655,   656,   696,   697,   737,   736,   191,   192,   283,
     284,   428,   421,   422,   423,   525,   526,   527,   528,   625,
     626,   679,   680,   681,   676,   715,   716,   752,   753,   754,
     782,   783,   784,   811,   812,   813,   814,   841,   842,   868,
     867,   750,   751,   777,   778,   779,   808,   773,   774,   804,
     835,   836,   837,   862,   863,   864,   894,   924,   925,   926,
     968,   969,   970,   971,  1019,  1070,  1071,   891,   892,   919,
     962,   963,   964,  1012,  1013,  1014,  1015,  1067,  1147,  1148,
    1149,  1150,  1237,   917,   918,   957,   958,   959,  1007,  1008,
    1009,  1063,  1142,  1143,  1144,  1233,  1061,  1062,  1138,  1230,
    1231,  1232,  1307,  1136,  1137,  1226,  1304,  1305,  1306,  1398,
    1224,  1225,  1300,  1395,  1396,  1397,  1471,  1298,  1299,  1391,
    1468,  1469,  1470,  1511,  1389,  1390,  1464,  1508,  1509,  1510,
    1530,   954,  1004,  1005,  1057,  1058,  1129,  1126,  1127,  1128,
    1216,  1217,  1218,  1219,  1293,  1373,  1374,  1375,  1376,  1460,
    1220,  1221,  1222,  1295,  1296,  1384,  1381,  1382,  1383,  1462,
     801,   802,   830,   857,   858,   859,   885,   886,   887,   914,
     951,   952,   953,   999,  1000,  1001,  1002,  1056,  1120,  1121,
     911,   912,   945,   946,   947,   993,   994,   995,  1051,  1116,
    1117,  1118,  1208,  1048,  1049,  1111,  1203,  1204,  1205,  1281,
    1109,  1110,  1199,  1278,  1279,  1280,  1360,  1197,  1198,  1274,
    1357,  1358,  1359,  1446,  1272,  1273,  1353,  1443,  1444,  1445,
    1496,  1351,  1352,  1439,  1493,  1494,  1495,  1524,   942,   990,
     991,  1044,  1045,  1102,  1098,  1099,  1100,  1188,  1189,  1190,
    1191,  1266,  1334,  1335,  1336,  1337,  1435,  1192,  1193,  1194,
    1268,  1269,  1345,  1342,  1343,  1344,  1437,   827,   828,   852,
     880,   881,   882,   905,   906,   907,   940,   986,   987,   988,
    1040,  1041,  1042,  1043,  1095,  1181,  1182,   937,   938,   980,
     981,   982,  1034,  1035,  1036,  1090,  1177,  1178,  1179,  1261,
    1088,  1089,  1173,  1258,  1259,  1260,  1328,  1171,  1172,  1254,
    1325,  1326,  1327,  1428,  1252,  1253,  1321,  1425,  1426,  1427,
    1486,  1319,  1320,  1421,  1483,  1484,  1485,  1521,  1419,  1420,
    1479,  1518,  1519,  1520,  1533,   977,  1031,  1032,  1084,  1085,
    1164,  1161,  1162,  1163,  1244,  1245,  1246,  1247,  1314,  1403,
    1404,  1405,  1406,  1475,  1248,  1249,  1250,  1316,  1317,  1414,
    1411,  1412,  1413,  1477,   849,   850,   875,   900,   901,   902,
     930,   931,   932,   933,   975,   976,  1025,  1022,  1023,  1024,
    1078,  1079,  1080,  1081,  1082,  1083,  1156,   623,   624,   673,
     711,   712,   713,   745,   746,   747,   748,   770,   771,   795,
     791,   792,   793,   819,   820,   821,   822,   823,   824,   844,
     727,   728,   729,   730,   134,   135,   136,   137,  1072,   603,
     604,   605,   606,   138,   139,   140,   141,   360,   361,   362,
     363,   615,   616,   617,   618,   941,   429,  1052,  1106,   799,
     915,   430,   853,   831,   180,   876,   805,   431,   674,   142,
     462,   895,   432,  1209,  1210,  1288,  1289,  1369,  1370,  1456,
    1453,  1211,  1285,  1366,  1367,  1368,  1457,  1458,   489,  1436,
     237,   238,   387
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1299
static const yytype_int16 yypact[] =
{
     125, -1299, -1299,    84,    70,    72, -1299, -1299,   132,    95,
     201, -1299,   269, -1299, -1299, -1299,   106,   348,     7, -1299,
   -1299, -1299, -1299,    70, -1299, -1299, -1299, -1299, -1299,   112,
     398,    -5, -1299, -1299, -1299, -1299,   162, -1299, -1299,   136,
     279, -1299, -1299, -1299,   132, -1299,   142,   406,    -9, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299,   149,   146, -1299, -1299,   212, -1299,   471,
   -1299,   473, -1299,   475, -1299,   477, -1299,   479, -1299,   486,
   -1299,   491, -1299,   187,   143, -1299,   223, -1299, -1299,   285,
   -1299, -1299, -1299, -1299, -1299,   167,   493,   -34, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   174,
     130, -1299, -1299,   495, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299,   464, -1299,   187, -1299, -1299, -1299,   233, -1299,   242,
   -1299,   499,   212, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299,    29, -1299, -1299, -1299, -1299,    21, -1299,
   -1299, -1299, -1299,    25, -1299, -1299, -1299, -1299,    45, -1299,
   -1299, -1299, -1299,    37, -1299, -1299, -1299, -1299,    19, -1299,
   -1299, -1299, -1299,    16, -1299, -1299, -1299, -1299, -1299,   501,
   -1299, -1299,   182,   256, -1299, -1299,   300, -1299, -1299, -1299,
   -1299, -1299, -1299,   171, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299,   188,   -24, -1299, -1299,   503,
   -1299,   505, -1299,   507, -1299,   509, -1299,   511, -1299,   187,
   -1299, -1299,    13, -1299, -1299, -1299, -1299,   253,   107,   274,
     107,   276,   107,   283, -1299,   513, -1299,   294,     1, -1299,
   -1299,   -64, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   168,
   -1299, -1299,   148, -1299, -1299,   155, -1299, -1299,   176, -1299,
   -1299,   181, -1299, -1299,   151, -1299, -1299,   137,   328,    28,
   -1299, -1299, -1299, -1299, -1299,   258,   339, -1299, -1299,   336,
   -1299, -1299, -1299,   517,   437, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299,   299,   178, -1299,
   -1299,   519, -1299,   521, -1299,   523, -1299,   525, -1299,   532,
   -1299,   346, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   464,
   -1299,   187, -1299, -1299,    41, -1299, -1299, -1299, -1299,    44,
   -1299, -1299, -1299, -1299,     5, -1299, -1299, -1299, -1299,    14,
   -1299, -1299, -1299, -1299,    30, -1299, -1299, -1299, -1299,   534,
   -1299, -1299, -1299,   198,   540, -1299,   386, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299,   540, -1299, -1299, -1299, -1299,   540,
   -1299, -1299, -1299, -1299,   365, -1299,   222, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299,   265,   225, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299,   248,   259, -1299, -1299,
   -1299,   340,   432, -1299, -1299, -1299, -1299, -1299, -1299,   -20,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299,    18, -1299, -1299, -1299, -1299,
      17, -1299, -1299, -1299, -1299,    31, -1299, -1299, -1299, -1299,
      54, -1299, -1299, -1299, -1299,    40, -1299, -1299, -1299, -1299,
   -1299,   539, -1299,   438,   107,   449,   107,   457,   107,   463,
   -1299,   541, -1299, -1299, -1299,   358, -1299, -1299,   374, -1299,
   -1299,   304, -1299, -1299,   337, -1299, -1299, -1299,   370, -1299,
     287, -1299, -1299, -1299, -1299, -1299,   461, -1299, -1299,   465,
   -1299,   496, -1299, -1299,   467, -1299, -1299,   421,   426, -1299,
   -1299, -1299, -1299, -1299,   543,   245, -1299, -1299, -1299,   545,
     418, -1299,   586, -1299, -1299,   606,   -41, -1299, -1299,   669,
     670,   671,   672, -1299, -1299,   403, -1299, -1299,   502, -1299,
   -1299,   522, -1299, -1299,   589, -1299, -1299,   555,   679,  -113,
   -1299, -1299, -1299, -1299,   540, -1299, -1299, -1299, -1299,   540,
   -1299, -1299, -1299, -1299,   540, -1299, -1299, -1299, -1299,   680,
   -1299,   302, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299,   533,   537, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299,   547,   418,   510, -1299, -1299,   686,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299,   542, -1299, -1299,
     688, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299,   662,   683,    61, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   506,
     512, -1299, -1299,   497, -1299,   498, -1299,   500, -1299, -1299,
     514, -1299, -1299,   550,   544, -1299, -1299, -1299, -1299,   549,
     418,   556, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299,   551, -1299,   526, -1299, -1299,   700, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   350,
   -1299, -1299, -1299, -1299, -1299, -1299,   557,   418,   558, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   701,   -50,
   -1299, -1299, -1299, -1299, -1299,   568,   212,   705, -1299,    24,
   -1299,   710, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299,   562, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299,   559,   548, -1299, -1299, -1299,
     515,   561,   563,   212, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299,   530, -1299, -1299, -1299, -1299, -1299, -1299,
     571,   401, -1299,   572,   692,    34, -1299, -1299, -1299, -1299,
     -59, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,    -2,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299,   614,   697, -1299,   573, -1299, -1299, -1299,   591, -1299,
   -1299,   552,   553, -1299, -1299,   719, -1299, -1299, -1299,   560,
     405, -1299, -1299, -1299, -1299,   724, -1299,   574,   712, -1299,
     575, -1299,   731,   535, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299,   578,   282, -1299,   673, -1299, -1299, -1299, -1299,   569,
     711, -1299,   580, -1299,   736,   538, -1299, -1299, -1299, -1299,
   -1299, -1299,   536,   546,   713,   564, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299,   582, -1299,   739,   630, -1299,
   -1299, -1299, -1299, -1299, -1299,   608,   641,   730, -1299, -1299,
   -1299,   646,   713, -1299,   584, -1299, -1299,   750,   -13, -1299,
   -1299, -1299, -1299, -1299, -1299,   642,   648,   743, -1299, -1299,
   -1299, -1299,   588, -1299,   590, -1299, -1299, -1299,   592,   594,
   -1299,   754,   -23, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
     605,   610, -1299, -1299, -1299, -1299, -1299, -1299,   596, -1299,
     598, -1299,   615,   661, -1299, -1299, -1299, -1299,   756,   -80,
   -1299, -1299, -1299, -1299,   619,   664, -1299, -1299, -1299, -1299,
     402, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   566,   567,
   -1299, -1299, -1299, -1299, -1299,   602,   401,   624,   666, -1299,
   -1299, -1299, -1299,   758,    -1, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299,   667,   674,   760, -1299, -1299, -1299,   576,
     636, -1299, -1299, -1299, -1299, -1299, -1299,   675,   687,   760,
   -1299, -1299,   581,   577, -1299, -1299, -1299, -1299, -1299,   220,
      32, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299,   678,   690,   760, -1299, -1299, -1299,
     659,   677, -1299, -1299,   604,   384, -1299, -1299,   689,   760,
   -1299,   607, -1299, -1299, -1299, -1299,   231,   609,   388, -1299,
   -1299,   696,   760,   611, -1299, -1299, -1299,    94,   540, -1299,
   -1299, -1299, -1299, -1299,   787, -1299, -1299, -1299,   638,   410,
   -1299, -1299, -1299, -1299,   613,   368, -1299, -1299,   698,   760,
     616, -1299, -1299, -1299, -1299,   306,   -61, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   663,
     760,   618, -1299,   790,   693, -1299, -1299, -1299, -1299,   540,
   -1299, -1299, -1299, -1299,   -77, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299,   665,   760,   620, -1299,
     693, -1299, -1299, -1299, -1299,    11, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299,   587,   793, -1299,   733, -1299, -1299,   -36,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299,   668,   760,   622, -1299,   693, -1299, -1299, -1299, -1299,
     540, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   652,   676,
   -1299, -1299,   681, -1299, -1299,   797, -1299,   626,   760,   625,
   -1299,   693, -1299, -1299, -1299, -1299, -1299,   768,   702, -1299,
     691, -1299,   682, -1299, -1299, -1299,   684,   600, -1299, -1299,
     695, -1299, -1299, -1299,   632,   760,   627, -1299,   693, -1299,
   -1299, -1299, -1299,   703, -1299, -1299, -1299,   612, -1299, -1299,
   -1299, -1299, -1299, -1299,   685,   699, -1299, -1299,   704, -1299,
   -1299, -1299,   634,   760,   629, -1299,   693, -1299, -1299, -1299,
   -1299,   708, -1299,   707, -1299, -1299,   227, -1299,   631,   252,
   -1299, -1299,   628,   760,   633, -1299,   693, -1299, -1299, -1299,
   -1299,   723, -1299, -1299, -1299,   635, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299,   291, -1299,   637,   252, -1299,   640,   760,
     639, -1299,   693, -1299, -1299, -1299, -1299,   734, -1299, -1299,
   -1299, -1299, -1299, -1299,   296, -1299,   643,   252, -1299,   644,
     760,   645, -1299,   693, -1299, -1299, -1299, -1299,   737, -1299,
   -1299, -1299,    36, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
     693, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299,   760,   647, -1299,   693, -1299, -1299, -1299, -1299,
     728, -1299, -1299,   819,    48, -1299, -1299, -1299, -1299,   817,
     621,     6, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   693,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
     760,   651, -1299,   693, -1299, -1299, -1299, -1299,   738, -1299,
   -1299,    50, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   693,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
     760,   653, -1299,   693, -1299, -1299, -1299, -1299,   742, -1299,
   -1299, -1299, -1299, -1299, -1299,   706, -1299,   714, -1299,   655,
   -1299,   693, -1299, -1299, -1299, -1299,   694, -1299, -1299, -1299,
     727, -1299,   835, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
     650, -1299,   716, -1299,   657, -1299,   693, -1299, -1299, -1299,
   -1299,   709, -1299, -1299, -1299,   729, -1299,   718, -1299,   660,
   -1299,   693, -1299, -1299, -1299, -1299,   715, -1299, -1299, -1299,
   -1299,   693, -1299, -1299, -1299, -1299,   717, -1299, -1299, -1299,
   -1299,   721,   840,   842, -1299, -1299,   693, -1299, -1299, -1299,
   -1299,   720, -1299, -1299, -1299, -1299,   693, -1299, -1299, -1299,
   -1299,   722, -1299, -1299,   656, -1299, -1299, -1299, -1299, -1299,
     658, -1299, -1299,   725, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   805,   828,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299,   791, -1299, -1299, -1299, -1299,   726, -1299,
   -1299, -1299, -1299, -1299,   468, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
     455, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299,   746, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299,   355, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299,   732, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299,   280, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   570,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   226, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299,   211, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299,   341, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,   116,
   -1299, -1299, -1299, -1299, -1299,    58, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299,   -98, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299,  -140, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299,  -343, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299,  -345, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299,  -124, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,  -312,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,  -314, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299,  -162, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299,  -365, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299,  -367, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299,   -49, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299,  -196, -1299, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299,   138, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299,    65, -1299, -1299, -1299, -1299,
    -768, -1299, -1299, -1299,  -119, -1299, -1299, -1299, -1040,  -519,
   -1299, -1299, -1299,  -657, -1299, -1299, -1299,  -224, -1299, -1299,
   -1299,  -590, -1299, -1299, -1299,  -199, -1299, -1002,  -987,   -89,
    -157, -1299, -1299, -1299,   -97, -1299, -1299, -1299, -1299,  -647,
   -1299,  -868, -1299, -1101, -1299, -1299, -1299, -1299, -1299, -1299,
   -1299, -1299, -1299, -1299, -1299, -1299, -1299, -1299,  -350, -1298,
    -178, -1299, -1299
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     268,   614,   234,   796,   497,   667,   368,  1064,   373,   382,
    1431,   479,  1432,  1433,   500,  1235,  1122,   351,   482,   502,
     265,   536,   533,   262,   920,   250,   236,  1151,   198,   253,
     760,   761,   732,   247,  1091,   539,   485,   486,   806,  1234,
    1431,   259,  1432,  1433,   545,   473,   523,  1112,  1213,   256,
     476,   102,  1450,    53,  1431,  1183,  1432,  1433,   542,   756,
    1139,   388,   389,   997,  1185,   815,   390,   816,   817,   757,
     704,  1133,   637,  1461,  1262,  1214,   666,  1241,    36,   638,
      37,    38,  1186,   199,     6,   200,    11,  1174,   103,  1242,
     104,  1187,   105,   199,   106,   200,   756,   677,  1169,  1074,
    1282,  1075,  1076,  1476,  1145,  1146,   757,   740,  1200,   359,
     743,   367,  1038,   372,   678,   391,  1243,   809,   621,   201,
     810,  1039,   350,   744,    54,     7,   998,  1308,   524,   201,
      55,  1069,  1215,   202,    56,  1227,    57,     1,     2,   599,
     600,   703,   928,   202,   107,   929,   543,    13,    58,   524,
     127,   128,    15,   203,  1451,  1329,   356,   357,    59,   204,
      60,   474,   477,   203,  1474,    28,    61,    84,   546,   204,
    1255,   248,   818,    45,   108,  1361,   807,   260,   739,   404,
    1434,   257,   405,   966,    62,   870,   967,   251,  1077,   254,
    1134,   263,    85,   540,   534,   537,  1275,   352,   487,   480,
     470,  1399,   483,   511,   644,    94,   266,   124,  1026,   646,
     762,    18,    19,   178,   648,   181,  1459,   383,   384,   385,
     386,  1236,  1429,  1301,   472,   516,  1338,   103,   182,   104,
    1068,   105,   190,   106,   220,   285,   239,  1332,  1333,  1438,
     558,  1119,   563,   126,   568,   240,   529,   530,   531,   532,
     322,  1322,   798,  1377,  1447,   127,   128,  1069,   274,   129,
     130,   275,   286,   354,  1069,   599,   600,  1348,  1069,   286,
    1050,  1354,   599,   600,  1407,    54,   599,   600,  1463,    23,
      24,    55,   548,   107,   364,    56,   369,    57,   127,   128,
     599,   600,  1472,   374,  1387,   127,   128,  1392,   287,    58,
     381,  1371,  1372,   610,   611,   287,  1401,  1402,  1478,    59,
     396,    60,   399,   108,   397,  1417,  1180,    61,  1422,   398,
     588,   400,  1487,   401,   288,   127,   128,   402,  1069,   129,
     130,   288,   289,  1069,   403,    62,   599,   600,   410,   289,
    1497,   599,   600,  1069,   411,   557,   290,   562,   291,   567,
    1440,   599,   600,   290,    86,   291,    87,    88,    31,    32,
     719,   720,   292,   433,   183,  1512,   184,   185,   293,   292,
     294,   503,   295,   505,   296,   293,   506,   294,   460,   295,
    1522,   296,   495,   276,   939,   277,   278,  1101,  1465,   498,
    1525,   721,   722,   127,   128,   512,   602,   129,   130,   356,
     357,   613,   517,  1101,   391,  1531,   913,  1101,    48,    49,
     404,   127,   128,   599,   600,  1534,    97,    98,  1480,   610,
     611,   893,   794,   412,   521,   413,   414,   127,   128,   599,
     600,   127,   128,   599,   600,   610,   611,   522,   581,   610,
     611,   582,   721,   722,   127,   128,   599,   600,   554,   682,
     683,   684,   685,   651,   424,  1105,   652,  1028,   686,   559,
     425,   127,   128,   599,   600,   733,   426,   564,  1132,   610,
     611,   427,   815,   569,   816,   817,   665,  1074,   576,  1075,
    1076,   143,   144,   148,   149,   153,   154,   158,   159,   163,
     164,   706,   577,   707,   708,  1167,   168,   169,   578,   717,
    1073,   173,   174,   193,   194,   222,   223,   127,   128,   241,
     242,   269,   270,   324,   325,   329,   330,   334,   335,   339,
     340,   344,   345,   376,   377,   579,  1104,   419,   420,   435,
     436,   440,   441,   445,   446,   450,   451,  1123,   580,  1131,
     759,   702,   455,   456,   490,   491,   485,   486,  1152,   549,
     550,   571,   572,   596,   597,   607,   608,   661,   662,   698,
     699,   709,   710,   587,   767,   591,  1166,   734,   735,   589,
     731,   775,   776,   780,   781,   592,  1184,   505,   738,   631,
     786,   789,   790,   833,   834,   855,   856,   788,   865,   866,
     878,   879,   898,   899,   922,   923,   590,   755,   943,   944,
     949,   950,   955,   956,   960,   961,   978,   979,   984,   985,
    1010,  1011,  1020,  1021,  1096,  1097,   825,  1114,  1115,  1124,
    1125,  1140,  1141,  1159,  1160,   832,  1175,  1176,  1201,  1202,
    1228,  1229,  1256,  1257,   755,  1276,  1277,  1302,  1303,  1323,
    1324,  1340,  1341,  1355,  1356,  1364,  1365,  1379,  1380,  1393,
    1394,   854,   797,  1409,  1410,  1423,  1424,  1441,  1442,  1454,
    1455,  1466,  1467,  1481,  1482,  1491,  1492,  1506,  1507,   872,
    1516,  1517,   620,   877,   619,   627,   628,   629,   630,  1347,
     632,   634,   888,   635,   633,   636,   649,   657,   581,   669,
     668,   671,   672,   675,   670,   651,   897,   637,   687,   690,
     692,   714,   691,   718,   694,   908,  1386,   742,   705,   749,
     741,   758,   693,   765,   766,   921,   787,   800,  1153,   768,
     803,   744,   829,   869,   843,   934,   772,  1416,   839,   826,
     847,   848,   810,   838,   845,   948,   851,   860,   874,   873,
     861,   871,   883,   884,   896,   903,   893,  1339,   889,   972,
     910,   904,   913,   890,   909,   916,   927,   936,   935,   939,
     965,   983,   996,   973,  1037,   928,   989,  1047,   992,  1212,
    1003,  1006,  1017,  1033,  1378,  1030,   967,  1046,  1050,   997,
    1060,  1093,  1054,  1087,  1108,  1059,  1011,  1016,  1086,  1065,
    1038,  1135,  1155,  1170,  1157,  1408,  1206,  1238,  1207,  1239,
    1196,  1240,  1223,  1270,  1264,  1251,  1185,  1271,  1284,  1215,
    1286,  1309,  1241,  1297,  1287,  1318,  1330,  1362,  1053,  1186,
    1213,  1331,  1310,  1350,  1448,  1449,  1290,  1452,  1400,  1242,
    1263,  1430,  1498,  1500,  1473,  1388,  1291,  1312,  1488,  1418,
    1490,  1501,  1505,  1514,  1515,  1527,  1528,  1513,  1529,    93,
    1489,    44,  1536,  1523,  1539,   125,   221,  1027,   246,  1092,
    1504,   513,   518,   593,   658,   695,   688,   622,   434,   785,
     840,  1018,  1113,  1066,  1292,  1294,  1055,  1265,  1267,  1094,
    1313,  1315,   974,  1158,   769,   846,  1168,  1029,  1107,     0,
       0,  1154,     0,     0,     0,     0,     0,     0,     0,  1526,
       0,     0,  1532,     0,  1535,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1540,     0,  1195,     0,     0,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   323,  1130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1283,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1311,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1349,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1363,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1346,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1385,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1415,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1499,     0,     0,     0,     0,  1502,  1503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1537,  1538
};

static const yytype_int16 yycheck[] =
{
     178,   520,   121,   771,   354,   595,   230,  1009,   232,     8,
       4,     6,     6,     7,   364,     4,  1056,     4,     4,   369,
       4,     4,     4,     4,   892,     4,   123,  1067,    62,     4,
       6,     7,   689,     4,  1036,     4,     6,     7,     4,  1140,
       4,     4,     6,     7,     4,     4,    66,  1049,   125,     4,
       6,    60,     4,    58,     4,  1095,     6,     7,     4,   716,
    1062,   239,   240,   143,   125,    67,   130,    69,    70,   716,
     660,  1058,   185,  1371,  1175,   152,   595,   113,    71,   192,
      73,    74,   143,   117,     0,   119,    14,  1089,    97,   125,
      99,   152,   101,   117,   103,   119,   753,    36,  1085,    67,
    1201,    69,    70,  1401,    10,    11,   753,   697,  1110,   228,
     160,   230,   113,   232,    53,   179,   152,   176,   159,   153,
     179,   122,   219,   173,   129,    55,   206,  1228,   169,   153,
     135,    37,   209,   167,   139,  1137,   141,    12,    13,    45,
      46,   660,   155,   167,   153,   158,    92,    15,   153,   169,
      43,    44,    57,   187,   106,  1256,    49,    50,   163,   193,
     165,   120,   118,   187,   114,    59,   171,     5,   128,   193,
    1172,   142,   174,    61,   183,  1276,   142,   140,   697,   151,
     144,   136,   154,   206,   189,   842,   209,   166,   156,   164,
    1058,   172,    56,   162,   176,   178,  1198,   184,   168,   194,
     319,  1302,   188,   381,   554,    63,   190,    58,   976,   559,
     186,    10,    11,    26,   564,    72,   210,   216,   217,   218,
     219,   210,  1323,  1225,   321,   403,  1266,    97,     5,    99,
      10,   101,    65,   103,    60,    64,     3,    10,    11,  1340,
     464,    10,   466,    31,   468,     3,   424,   425,   426,   427,
      62,  1253,   771,  1293,  1355,    43,    44,    37,    76,    47,
      48,     5,    91,    10,    37,    45,    46,  1269,    37,    91,
      18,  1273,    45,    46,  1314,   129,    45,    46,  1379,    10,
      11,   135,   460,   153,    10,   139,    10,   141,    43,    44,
      45,    46,  1393,    10,  1296,    43,    44,  1299,   127,   153,
       6,    10,    11,    51,    52,   127,    10,    11,  1409,   163,
     142,   165,   136,   183,   166,  1317,    10,   171,  1320,   164,
     498,   140,  1423,   172,   153,    43,    44,   190,    37,    47,
      48,   153,   161,    37,     6,   189,    45,    46,    80,   161,
    1441,    45,    46,    37,     5,   464,   175,   466,   177,   468,
    1352,    45,    46,   175,    75,   177,    77,    78,    10,    11,
      10,    11,   191,    64,    79,  1466,    81,    82,   197,   191,
     199,     6,   201,   151,   203,   197,   154,   199,    32,   201,
    1481,   203,   184,    83,    16,    85,    86,    19,  1390,     3,
    1491,    41,    42,    43,    44,   130,   515,    47,    48,    49,
      50,   520,   154,    19,   179,  1506,    22,    19,    10,    11,
     151,    43,    44,    45,    46,  1516,    10,    11,  1420,    51,
      52,    33,    21,    87,    84,    89,    90,    43,    44,    45,
      46,    43,    44,    45,    46,    51,    52,     5,   151,    51,
      52,   154,    41,    42,    43,    44,    45,    46,    10,   627,
     628,   629,   630,   151,    17,  1045,   154,   976,   636,    10,
      23,    43,    44,    45,    46,   689,    29,    10,  1058,    51,
      52,    34,    67,    10,    69,    70,   595,    67,   120,    69,
      70,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,   669,   118,   671,   672,  1085,    10,    11,   194,   677,
    1019,    10,    11,    10,    11,    10,    11,    43,    44,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,   188,  1045,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,  1056,   168,  1058,
     718,   660,    10,    11,    10,    11,     6,     7,  1067,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   102,   742,    98,  1085,    10,    11,   104,
     689,    10,    11,    10,    11,   154,  1095,   151,   697,   176,
     758,    10,    11,    10,    11,    10,    11,   765,    10,    11,
      10,    11,    10,    11,    10,    11,   100,   716,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     208,   209,    10,    11,    10,    11,   794,    10,    11,    10,
      11,    10,    11,    10,    11,   803,    10,    11,    10,    11,
      10,    11,    10,    11,   753,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,   829,   771,    10,    11,    10,    11,    10,    11,    38,
      39,    10,    11,    10,    11,    10,    11,    10,    11,   847,
      10,    11,    66,   851,    88,     6,     6,     6,     6,  1269,
     178,    92,   860,   128,   162,     6,     6,   154,   151,     3,
     180,     3,    30,    10,   152,   151,   874,   185,   192,   202,
     200,   175,   204,     3,   154,   883,  1296,     6,   152,   141,
     152,     6,   198,     3,   152,   893,   186,   145,  1068,   160,
      28,   173,    25,   842,     5,   903,   211,  1317,   176,   115,
       6,   157,   179,   142,   174,   913,    24,     6,    27,   170,
     205,    68,     6,   205,   180,     6,    33,  1266,   212,   927,
     109,   121,    22,   207,   146,   109,     6,   109,   116,    16,
       6,   939,     6,   158,     6,   155,   151,    93,   107,  1119,
     151,   107,   206,   107,  1293,   151,   209,   110,    18,   143,
      93,   122,   206,    93,    95,   110,   209,   965,   110,   208,
     113,    95,     5,    95,   156,  1314,     6,   210,   105,     6,
     137,    68,   137,     6,   152,   137,   125,   181,    40,   209,
     108,   108,   113,   181,   123,   181,   108,    94,   996,   143,
     125,   114,   210,   195,    96,     6,   144,    10,    94,   125,
    1180,    94,   138,   106,    96,   195,   152,   152,    96,   195,
     126,     6,   126,   114,   126,   124,     6,   138,     6,    44,
     144,    23,   196,   138,   196,    64,   110,   976,   132,  1037,
     210,   393,   407,   508,   584,   654,   640,   526,   298,   753,
     812,   969,  1050,  1013,  1217,  1220,  1000,  1189,  1192,  1041,
    1245,  1248,   931,  1079,   746,   820,  1085,   976,  1045,    -1,
      -1,  1069,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
      -1,    -1,   182,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,  1101,    -1,    -1,  1045,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,  1058,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1085,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1284,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1296,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1317,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1449,    -1,    -1,    -1,    -1,  1454,  1455,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1528,  1529
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   221,   222,   223,     0,    55,   229,   230,
     231,    14,   224,    15,   228,    57,   256,   257,    10,    11,
     232,   233,   234,    10,    11,   225,   226,   227,    59,   336,
     337,    10,    11,   258,   259,   260,    71,    73,    74,   235,
     236,   237,   238,   239,   229,    61,   390,   391,    10,    11,
     338,   339,   340,    58,   129,   135,   139,   141,   153,   163,
     165,   171,   189,   261,   262,   263,   264,   265,   280,   281,
     286,   287,   292,   293,   298,   299,   304,   305,   310,   311,
     316,   317,   322,   323,     5,    56,    75,    77,    78,   240,
     241,   242,   243,   228,    63,   442,   443,    10,    11,   392,
     393,   394,    60,    97,    99,   101,   103,   153,   183,   341,
     342,   343,   344,   345,   350,   351,   357,   358,   364,   365,
     371,   372,   376,   377,    58,   263,    31,    43,    44,    47,
      48,   266,   267,   268,   934,   935,   936,   937,   943,   944,
     945,   946,   969,    10,    11,   282,   283,   284,    10,    11,
     288,   289,   290,    10,    11,   294,   295,   296,    10,    11,
     300,   301,   302,    10,    11,   306,   307,   308,    10,    11,
     312,   313,   314,    10,    11,   318,   319,   320,    26,   324,
     964,    72,     5,    79,    81,    82,   244,   245,   246,   247,
      65,   537,   538,    10,    11,   444,   445,   446,    62,   117,
     119,   153,   167,   187,   193,   395,   396,   397,   398,   399,
     404,   405,   410,   411,   416,   417,   422,   423,   428,   429,
      60,   343,    10,    11,   346,   347,   348,   352,   353,   359,
     360,   366,   367,   373,   934,   378,   964,   990,   991,     3,
       3,    10,    11,   269,   270,   271,   268,     4,   142,   285,
       4,   166,   291,     4,   164,   297,     4,   136,   303,     4,
     140,   309,     4,   172,   315,     4,   190,   321,   990,    10,
      11,   325,   326,   327,    76,     5,    83,    85,    86,   248,
     249,   250,   251,   539,   540,    64,    91,   127,   153,   161,
     175,   177,   191,   197,   199,   201,   203,   447,   448,   449,
     450,   451,   456,   457,   462,   463,   468,   469,   474,   475,
     480,   481,   497,   498,   504,   505,   511,   512,   518,   519,
     523,   524,    62,   397,    10,    11,   400,   401,   402,    10,
      11,   406,   407,   408,    10,    11,   412,   413,   414,    10,
      11,   418,   419,   420,    10,    11,   424,   425,   426,   430,
     964,     4,   184,   349,    10,   355,    49,    50,   354,   934,
     947,   948,   949,   950,    10,   362,   361,   934,   947,    10,
     369,   368,   934,   947,    10,   374,    10,    11,   379,   380,
     381,     6,     8,   216,   217,   218,   219,   992,   990,   990,
     130,   179,   272,   273,   274,   275,   142,   166,   164,   136,
     140,   172,   190,     6,   151,   154,   328,   329,   330,   331,
      80,     5,    87,    89,    90,   252,   253,   254,   255,    10,
      11,   542,   543,   544,    17,    23,    29,    34,   541,   956,
     961,   967,   972,    64,   449,    10,    11,   452,   453,   454,
      10,    11,   458,   459,   460,    10,    11,   464,   465,   466,
      10,    11,   470,   471,   472,    10,    11,   476,   477,   478,
      32,   482,   970,   499,   500,   506,   507,   513,   514,   520,
     934,   525,   964,     4,   120,   403,     6,   118,   409,     6,
     194,   415,     4,   188,   421,     6,     7,   168,   427,   988,
      10,    11,   431,   432,   433,   184,   356,   988,     3,   363,
     988,   370,   988,     6,   375,   151,   154,   382,   383,   384,
     385,   990,   130,   274,   276,   277,   990,   154,   330,   332,
     333,    84,     5,    66,   169,   545,   546,   547,   548,   990,
     990,   990,   990,     4,   176,   455,     4,   178,   461,     4,
     162,   467,     4,    92,   473,     4,   128,   479,   990,    10,
      11,   483,   484,   485,    10,   502,   501,   934,   947,    10,
     509,   508,   934,   947,    10,   516,   515,   934,   947,    10,
     521,    10,    11,   526,   527,   528,   120,   118,   194,   188,
     168,   151,   154,   434,   435,   436,   437,   102,   990,   104,
     100,    98,   154,   384,   386,   387,    10,    11,   279,    45,
      46,   278,   934,   939,   940,   941,   942,    10,    11,   335,
      51,    52,   334,   934,   939,   951,   952,   953,   954,    88,
      66,   159,   547,   907,   908,   549,   550,     6,     6,     6,
       6,   176,   178,   162,    92,   128,     6,   185,   192,   486,
     487,   488,   489,   503,   988,   510,   988,   517,   988,     6,
     522,   151,   154,   529,   530,   531,   532,   154,   436,   438,
     439,    10,    11,   389,   388,   934,   939,   951,   180,     3,
     152,     3,    30,   909,   968,    10,   554,    36,    53,   551,
     552,   553,   990,   990,   990,   990,   990,   192,   488,   490,
     202,   204,   200,   198,   154,   531,   533,   534,    10,    11,
     441,   440,   934,   939,   951,   152,   990,   990,   990,    10,
      11,   910,   911,   912,   175,   555,   556,   990,     3,    10,
      11,    41,    42,   491,   492,   493,   494,   930,   931,   932,
     933,   934,   943,   947,    10,    11,   536,   535,   934,   939,
     951,   152,     6,   160,   173,   913,   914,   915,   916,   141,
     571,   572,   557,   558,   559,   934,   943,   969,     6,   990,
       6,     7,   186,   495,   496,     3,   152,   990,   160,   915,
     917,   918,   211,   577,   578,    10,    11,   573,   574,   575,
      10,    11,   560,   561,   562,   559,   990,   186,   990,    10,
      11,   920,   921,   922,    21,   919,   930,   934,   939,   959,
     145,   690,   691,    28,   579,   966,     4,   142,   576,   176,
     179,   563,   564,   565,   566,    67,    69,    70,   174,   923,
     924,   925,   926,   927,   928,   990,   115,   787,   788,    25,
     692,   963,   990,    10,    11,   580,   581,   582,   142,   176,
     565,   567,   568,     5,   929,   174,   925,     6,   157,   884,
     885,    24,   789,   962,   990,    10,    11,   693,   694,   695,
       6,   205,   583,   584,   585,    10,    11,   570,   569,   934,
     943,    68,   990,   170,    27,   886,   965,   990,    10,    11,
     790,   791,   792,     6,   205,   696,   697,   698,   990,   212,
     207,   597,   598,    33,   586,   971,   180,   990,    10,    11,
     887,   888,   889,     6,   121,   793,   794,   795,   990,   146,
     109,   710,   711,    22,   699,   960,   109,   613,   614,   599,
     971,   990,    10,    11,   587,   588,   589,     6,   155,   158,
     890,   891,   892,   893,   990,   116,   109,   807,   808,    16,
     796,   955,   758,    10,    11,   712,   713,   714,   990,    10,
      11,   700,   701,   702,   661,    10,    11,   615,   616,   617,
      10,    11,   600,   601,   602,     6,   206,   209,   590,   591,
     592,   593,   990,   158,   892,   894,   895,   855,    10,    11,
     809,   810,   811,   990,    10,    11,   797,   798,   799,   151,
     759,   760,   107,   715,   716,   717,     6,   143,   206,   703,
     704,   705,   706,   151,   662,   663,   107,   618,   619,   620,
     208,   209,   603,   604,   605,   606,   990,   206,   592,   594,
      10,    11,   897,   898,   899,   896,   930,   934,   939,   959,
     151,   856,   857,   107,   812,   813,   814,     6,   113,   122,
     800,   801,   802,   803,   761,   762,   110,    93,   723,   724,
      18,   718,   957,   990,   206,   705,   707,   664,   665,   110,
      93,   626,   627,   621,   957,   208,   605,   607,    10,    37,
     595,   596,   938,   939,    67,    69,    70,   156,   900,   901,
     902,   903,   904,   905,   858,   859,   110,    93,   820,   821,
     815,   957,   990,   122,   802,   804,    10,    11,   764,   765,
     766,    19,   763,   934,   939,   951,   958,   960,    95,   730,
     731,   725,   957,   990,    10,    11,   719,   720,   721,    10,
     708,   709,   938,   939,    10,    11,   667,   668,   669,   666,
     934,   939,   951,   958,   971,    95,   633,   634,   628,   957,
      10,    11,   622,   623,   624,    10,    11,   608,   609,   610,
     611,   938,   939,   988,   990,     5,   906,   156,   902,    10,
      11,   861,   862,   863,   860,   934,   939,   951,   955,   958,
      95,   827,   828,   822,   957,    10,    11,   816,   817,   818,
      10,   805,   806,   938,   939,   125,   143,   152,   767,   768,
     769,   770,   777,   778,   779,   990,   137,   737,   738,   732,
     957,    10,    11,   726,   727,   728,     6,   105,   722,   973,
     974,   981,   988,   125,   152,   209,   670,   671,   672,   673,
     680,   681,   682,   137,   640,   641,   635,   957,    10,    11,
     629,   630,   631,   625,   973,     4,   210,   612,   210,     6,
      68,   113,   125,   152,   864,   865,   866,   867,   874,   875,
     876,   137,   834,   835,   829,   957,    10,    11,   823,   824,
     825,   819,   973,   988,   152,   769,   771,   778,   780,   781,
       6,   181,   744,   745,   739,   957,    10,    11,   733,   734,
     735,   729,   973,   990,    40,   982,   108,   123,   975,   976,
     144,   152,   672,   674,   681,   683,   684,   181,   647,   648,
     642,   957,    10,    11,   636,   637,   638,   632,   973,   108,
     210,   990,   152,   866,   868,   875,   877,   878,   181,   841,
     842,   836,   957,    10,    11,   830,   831,   832,   826,   973,
     108,   114,    10,    11,   772,   773,   774,   775,   938,   939,
      10,    11,   783,   784,   785,   782,   934,   951,   957,   990,
     195,   751,   752,   746,   957,    10,    11,   740,   741,   742,
     736,   973,    94,   990,    10,    11,   983,   984,   985,   977,
     978,    10,    11,   675,   676,   677,   678,   938,   939,    10,
      11,   686,   687,   688,   685,   934,   951,   957,   195,   654,
     655,   649,   957,    10,    11,   643,   644,   645,   639,   973,
      94,    10,    11,   869,   870,   871,   872,   938,   939,    10,
      11,   880,   881,   882,   879,   934,   951,   957,   195,   848,
     849,   843,   957,    10,    11,   837,   838,   839,   833,   973,
      94,     4,     6,     7,   144,   776,   989,   786,   973,   753,
     957,    10,    11,   747,   748,   749,   743,   973,    96,     6,
       4,   106,    10,   980,    38,    39,   979,   986,   987,   210,
     679,   989,   689,   973,   656,   957,    10,    11,   650,   651,
     652,   646,   973,    96,   114,   873,   989,   883,   973,   850,
     957,    10,    11,   844,   845,   846,   840,   973,    96,   144,
     126,    10,    11,   754,   755,   756,   750,   973,   138,   990,
     106,     6,   990,   990,   210,   126,    10,    11,   657,   658,
     659,   653,   973,   138,   114,   126,    10,    11,   851,   852,
     853,   847,   973,   138,   757,   973,   182,   124,     6,     6,
     660,   973,   182,   854,   973,   182,   196,   990,   990,   196,
     196
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

  case 13:

    {	osrlerror( NULL, osresult, parserData, osglData, "unexpected end of file, expecting </osrl>");;}
    break;

  case 16:

    {
	if (!osresult->setResultHeader(osglData->fileName, osglData->source, 	
			osglData->description, osglData->fileCreator, osglData->licence) )	
		osrlerror( NULL, osresult, parserData, osglData, "setHeader failed");
;}
    break;

  case 17:

    {
	osglData->fileName    = "";
	osglData->source      = "";
	osglData->description = "";
	osglData->fileCreator = "";
	osglData->licence     = "";
;}
    break;

  case 29:

    {
	osglData->fileName = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 36:

    {
	osglData->source = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 43:

    {
	osglData->description = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 50:

    {
	osglData->fileCreator = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 57:

    {
	osglData->licence = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 60:

    {
	parserData->generalStatusPresent = false;	
	parserData->generalMessagePresent = false;
	parserData->generalServiceURIPresent = false;
	parserData->generalServiceNamePresent = false;
	parserData->generalInstanceNamePresent = false;
	parserData->generalJobIDPresent = false;
	parserData->generalSolverInvokedPresent = false;
	parserData->generalTimeStampPresent = false;
	parserData->otherGeneralResultsPresent = false;
	osresult->general = new GeneralResult();
;}
    break;

  case 79:

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

  case 80:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	;}
    break;

  case 83:

    { 
		if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "general status type does not match any legal value");
	;}
    break;

  case 84:

    {   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	;}
    break;

  case 85:

    {   if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate substatus array. Potential loss of data.");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	;}
    break;

  case 86:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	;}
    break;

  case 87:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	;}
    break;

  case 94:

    {	parserData->kounter++;
;}
    break;

  case 95:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 96:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have name attribute");
;}
    break;

  case 99:

    {	
		if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus name");
	;}
    break;

  case 100:

    {	
		if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus description");
	;}
    break;

  case 104:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	;}
    break;

  case 110:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 112:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	;}
    break;

  case 118:

    {osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 120:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	;}
    break;

  case 126:

    {osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 128:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	;}
    break;

  case 134:

    {osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 136:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	;}
    break;

  case 142:

    {osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 144:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	;}
    break;

  case 150:

    {osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 152:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	;}
    break;

  case 158:

    {osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 160:

    {	if (parserData->otherGeneralResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one general other results element allowed");
		parserData->otherGeneralResultsPresent = true;
	;}
    break;

  case 161:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other general results cannot be negative");
	if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate other general results array. Potential loss of data.");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 162:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 163:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 170:

    {	parserData->kounter++;
;}
    break;

  case 171:

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

  case 172:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 175:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultName failed");
	;}
    break;

  case 176:

    {	
		if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultValue failed");
	;}
    break;

  case 177:

    {	
		if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultDescription failed");
	;}
    break;

  case 182:

    {
	parserData->systemInformationPresent = false;	
	parserData->systemAvailableDiskSpacePresent = false;	
	parserData->systemAvailableMemoryPresent = false;
	parserData->systemAvailableCPUSpeedPresent = false;
	parserData->systemAvailableCPUNumberPresent = false;
	parserData->otherSystemResultsPresent = false;
	osresult->system = new SystemResult();
;}
    break;

  case 198:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	;}
    break;

  case 204:

    {	osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	;}
    break;

  case 206:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 210:

    {
		if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 211:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 213:

    {	osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 215:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 219:

    {
		if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 220:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 222:

    {	osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
;}
    break;

  case 224:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 228:

    {
		if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "available CPU Speed could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 229:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 231:

    {	osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
;}
    break;

  case 233:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 235:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 237:

    {	osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; ;}
    break;

  case 239:

    {	if (parserData->otherSystemResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one system other results element allowed");
		parserData->otherSystemResultsPresent = true;
	;}
    break;

  case 240:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other system results cannot be negative");
	if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSystemResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 241:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 242:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 249:

    {	parserData->kounter++;
;}
    break;

  case 250:

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

  case 251:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 254:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultName failed");
	;}
    break;

  case 255:

    {	
		if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultValue failed");
	;}
    break;

  case 256:

    {	
		if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultDescription failed");
	;}
    break;

  case 261:

    {
	parserData->serviceCurrentStatePresent = false;	
	parserData->serviceCurrentJobCountPresent = false;	
	parserData->serviceTotalJobsSoFarPresent = false;	
	parserData->timeServiceStartedPresent = false;	
	parserData->serviceUtilizationPresent = false;	
	parserData->otherServiceResultsPresent = false;
	osresult->service = new ServiceResult();
;}
    break;

  case 277:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	;}
    break;

  case 283:

    {   parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setCurrentState(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setCurrentState failed; current system state not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 285:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	;}
    break;

  case 291:

    { osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 293:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	;}
    break;

  case 299:

    { osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; ;}
    break;

  case 301:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	;}
    break;

  case 307:

    {osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 309:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	;}
    break;

  case 315:

    {	if (osresult->setServiceUtilization( parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setServiceUtilization failed");
	parserData->errorText = NULL;
;}
    break;

  case 317:

    {	if (parserData->otherServiceResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one service other results element allowed");
		parserData->otherServiceResultsPresent = true;
	;}
    break;

  case 318:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other service results cannot be negative");
	if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherServiceResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 319:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 320:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 327:

    {	parserData->kounter++;
;}
    break;

  case 328:

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

  case 329:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 332:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultName failed");
	;}
    break;

  case 333:

    {	
		if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultValue failed");
	;}
    break;

  case 334:

    {	
		if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultDescription failed");
	;}
    break;

  case 339:

    {
	parserData->jobStatusPresent = false;	
	parserData->jobSubmitTimePresent = false;	
	parserData->scheduledStartTimePresent = false;	
	parserData->actualStartTimePresent = false;	
	parserData->jobEndTimePresent = false;	
	parserData->jobTimingInformationPresent = false;	
	parserData->jobUsedDiskSpacePresent = false;	
	parserData->jobUsedMemoryPresent = false;	
	parserData->jobUsedCPUSpeedPresent = false;	
	parserData->jobUsedCPUNumberPresent = false;	
	parserData->otherJobResultsPresent = false;	 
	osresult->job = new JobResult();
;}
    break;

  case 360:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	;}
    break;

  case 366:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setJobStatus(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobStatus failed");
		parserData->errorText = NULL;
	;}
    break;

  case 368:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	;}
    break;

  case 374:

    {osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 376:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	;}
    break;

  case 382:

    {osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;;}
    break;

  case 384:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	;}
    break;

  case 390:

    {osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 392:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	;}
    break;

  case 398:

    {osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;;}
    break;

  case 400:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	;}
    break;

  case 401:

    {	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of time measurements cannot be negative");
	if (osresult->setNumberOfTimes(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfTimes failed");
	parserData->numberOfTimes = parserData->tempInt;
	parserData->ivar = 0;
;}
    break;

  case 402:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <time> element");
	;}
    break;

  case 403:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <time> elements than specified");
	;}
    break;

  case 411:

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

  case 423:

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

  case 424:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 425:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 427:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 431:

    {
		if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 432:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 434:

    {	osresult->setUsedDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 436:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 440:

    {
		if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "usedMemory unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 441:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 443:

    {	osresult->setUsedMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 445:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 449:

    {
		if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableCPUSpeed unit could not be set");
		parserData->errorText = NULL;
	;}
    break;

  case 450:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 452:

    {	osresult->setUsedCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
;}
    break;

  case 454:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 456:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	;}
    break;

  case 458:

    { osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; ;}
    break;

  case 460:

    {	if (parserData->otherJobResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job other results element allowed");
		parserData->otherJobResultsPresent = true;
	;}
    break;

  case 461:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other job results cannot be negative");
	if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherJobResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 462:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 463:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 470:

    {	parserData->kounter++;
;}
    break;

  case 471:

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

  case 472:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 475:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultName failed");
	;}
    break;

  case 476:

    {	
		if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultValue failed");
	;}
    break;

  case 477:

    {	
		if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultDescription failed");
	;}
    break;

  case 482:

    {
	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
;}
    break;

  case 483:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "numberOfSolutions was never set");
;}
    break;

  case 486:

    {
		parserData->numberOfSolutions = parserData->tempInt; 
		if (osresult->setSolutionNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionNumber failed");
		parserData->solutionIdx = 0;
	;}
    break;

  case 487:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osresult->setVariableNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVariableNumber failed");
	;}
    break;

  case 488:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osresult->setConstraintNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setConstraintNumber failed");
	;}
    break;

  case 489:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osresult->setObjectiveNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjectiveNumber failed");
	;}
    break;

  case 490:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solution> element");
	;}
    break;

  case 491:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solution> elements than specified");
	;}
    break;

  case 499:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
;}
    break;

  case 505:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, "target objective index must be negative");
  	if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveIdx failed");
 ;}
    break;

  case 506:

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

  case 507:

    {
		parserData->solutionIdx++;
	;}
    break;

  case 509:

    {
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
		parserData->typeAttribute = "";
		parserData->descriptionAttribute = "";
	;}
    break;

  case 510:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for solution status element");
	;}
    break;

  case 513:

    {   
		if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusType failed");
	;}
    break;

  case 514:

    {   if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusDescription failed");
	;}
    break;

  case 515:

    {	if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolutionSubstatuses failed");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	;}
    break;

  case 516:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	;}
    break;

  case 517:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	;}
    break;

  case 524:

    {	parserData->kounter++; ;}
    break;

  case 525:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->typeAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 526:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have type attribute");
;}
    break;

  case 529:

    {	
		if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
											   parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusType failed");
	;}
    break;

  case 530:

    {	
		if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
													  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusDescription failed");
	;}
    break;

  case 541:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
		osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
		parserData->errorText = NULL;
	;}
    break;

  case 544:

    {
	parserData->numberOfOtherVariableResults = 0;
	osresult->optimization->solution[parserData->solutionIdx]->variables = new VariableSolution();
;}
    break;

  case 546:

    {	
	if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableResults failed");
	parserData->numberOfOtherVariableResults = parserData->tempInt;
	parserData->iOther = 0;
;}
    break;

  case 555:

    {
	if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValues failed");
	parserData->kounter = 0;
;}
    break;

  case 556:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 557:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 564:

    {
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->nameAttribute,
							  parserData->tempVal                           ) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValue failed");
	parserData->kounter++;
;}
    break;

  case 565:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = ""	
;}
    break;

  case 574:

    {
	if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
	parserData->kounter = 0;
;}
    break;

  case 575:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 576:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 583:

    {
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 				parserData->idx,         parserData->nameAttribute,
									parserData->tempStr                           ) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValueString failed");
	parserData->kounter++;
;}
    break;

  case 584:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
;}
    break;

  case 589:

    {parserData->tempStr = "";;}
    break;

  case 594:

    {parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));;}
    break;

  case 597:

    {
	osresult->optimization->solution[parserData->solutionIdx]->variables->basisStatus = new BasisStatus();
;}
    break;

  case 604:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 606:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 613:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 615:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 622:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 624:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 631:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 633:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 640:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 642:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 649:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 651:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 659:

    { 	 
		parserData->iOther++;
	;}
    break;

  case 660:

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

  case 661:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfVar attribute"); 
	;}
    break;

  case 664:

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

  case 665:

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

  case 666:

    {	
	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 												  parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 667:

    {	
	 	if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    ;}
    break;

  case 668:

    {	
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 678:

    { 	
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	parserData->kounter++;
;}
    break;

  case 679:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = ""	
;}
    break;

  case 682:

    {	
 		if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->idx) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
	;}
    break;

  case 683:

    {	
 		if (osresult->setOtherVariableResultVarName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarName failed");
	;}
    break;

  case 689:

    {	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
	;}
    break;

  case 692:

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

  case 693:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 694:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfVarIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfVarIdx attribute"); 
	;}
    break;

  case 697:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 698:

    {	
//	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 699:

    {	
//	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 707:

    {
	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->objectives = new ObjectiveSolution();
;}
    break;

  case 709:

    {
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
	if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
;}
    break;

  case 718:

    {
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
;}
    break;

  case 719:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	;}
    break;

  case 720:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	;}
    break;

  case 727:

    {	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->nameAttribute,
							  parserData->tempVal                           ) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
	parserData->kounter++;
;}
    break;

  case 728:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->idx = -1;
	parserData->nameAttributePresent = false;
	parserData->name = ""	
;}
    break;

  case 736:

    {
	osresult->optimization->solution[parserData->solutionIdx]->objectives->basisStatus = new BasisStatus();
;}
    break;

  case 743:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 745:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 752:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 754:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 761:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 763:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 770:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 772:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 779:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 781:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 788:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 790:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 798:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 799:

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

  case 800:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfObj attribute"); 
	;}
    break;

  case 803:

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

  case 804:

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

  case 805:

    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 806:

    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    ;}
    break;

  case 807:

    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 817:

    {  
	parserData->kounter++;
;}
    break;

  case 818:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->idx = -1;	
	parserData->nameAttributePresent = false;
	parserData->name = ""	
;}
    break;

  case 821:

    {
		if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
	;}
    break;

  case 822:

    {	
 		if (osresult->setOtherObjectiveResultObjName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjName failed");
	;}
    break;

  case 828:

    {	if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
	;}
    break;

  case 831:

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

  case 832:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 833:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfObjIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfObjIdx attribute"); 
	;}
    break;

  case 836:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 837:

    {	
//	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 838:

    {	
//	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 846:

    {
	parserData->numberOfOtherConstraintResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->constraints = new ConstraintSolution();
;}
    break;

  case 848:

    {
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
;}
    break;

  case 856:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 857:

    {
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
;}
    break;

  case 858:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	;}
    break;

  case 859:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	;}
    break;

  case 866:

    {	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->nameAttribute,
							   parserData->tempVal                           ) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
	parserData->kounter++;
;}
    break;

  case 867:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
;}
    break;

  case 875:

    {
	osresult->optimization->solution[parserData->solutionIdx]->constraints->basisStatus = new BasisStatus();
;}
    break;

  case 882:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 884:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 891:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 893:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 900:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 902:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 909:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 911:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 918:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 920:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 927:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 929:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 937:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 938:

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

  case 939:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfCon attribute"); 
	;}
    break;

  case 942:

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

  case 943:

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

  case 944:

    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 945:

    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    ;}
    break;

  case 946:

    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 956:

    { 	
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	parserData->kounter++;
;}
    break;

  case 957:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = ""	
;}
    break;

  case 960:

    {	
 		if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
	;}
    break;

  case 961:

    {	
 		if (osresult->setOtherConstraintResultConName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConName failed");
	;}
    break;

  case 967:

    {	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
	;}
    break;

  case 970:

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

  case 971:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 972:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfConIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfConIdx attribute"); 
	;}
    break;

  case 975:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 976:

    {	
//	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 977:

    {	
//	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 985:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 986:

    {	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 987:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
	;}
    break;

  case 988:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
	;}
    break;

  case 995:

    {	parserData->iOther++;
;}
    break;

  case 996:

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

  case 997:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
;}
    break;

  case 1000:

    {	
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
	;}
    break;

  case 1001:

    {	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
	;}
    break;

  case 1002:

    {	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
	;}
    break;

  case 1003:

    {	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 1004:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 1005:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 1012:

    {	parserData->kounter++;
;}
    break;

  case 1013:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 1018:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
											 parserData->kounter, parserData->itemContent) 
											     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultItem failed");
;}
    break;

  case 1021:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 1022:

    {	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 1023:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
	;}
    break;

  case 1024:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
	;}
    break;

  case 1031:

    {	parserData->iOther++;
;}
    break;

  case 1032:

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

  case 1033:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
;}
    break;

  case 1036:

    {	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
	;}
    break;

  case 1037:

    {	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
	;}
    break;

  case 1038:

    {	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
	;}
    break;

  case 1039:

    {	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 1040:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 1041:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 1048:

    {	parserData->kounter++;
;}
    break;

  case 1049:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 1054:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
;}
    break;

  case 1055:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 1058:

    { parserData->categoryAttribute = ""; ;}
    break;

  case 1059:

    { parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 1060:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 1063:

    { parserData->descriptionAttribute = ""; ;}
    break;

  case 1064:

    { parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1065:

    {	
		if (parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute was previously set");
		parserData->idxAttributePresent = true;
		parserData->idx = (yyvsp[(3) - (4)].ival); 
	;}
    break;

  case 1066:

    {   if (parserData->nameAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
		parserData->nameAttributePresent = true;
	;}
    break;

  case 1069:

    { parserData->nameAttribute = ""; ;}
    break;

  case 1070:

    { parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1071:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 1074:

    { parserData->typeAttribute = ""; ;}
    break;

  case 1075:

    { parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1076:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 1079:

    { parserData->unitAttribute = ""; ;}
    break;

  case 1080:

    { parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1081:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 1084:

    { parserData->valueAttribute = ""; ;}
    break;

  case 1085:

    { parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1086:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1087:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1088:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1089:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1090:

    {	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1091:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1092:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1093:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1094:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1095:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1096:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1097:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1098:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1099:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1100:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1101:

    {
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1102:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1103:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1104:

    {
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	;}
    break;

  case 1109:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
;}
    break;

  case 1115:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
;}
    break;

  case 1117:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1122:

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

  case 1123:

    {	
	if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1124:

    {	
	if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1125:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 1126:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 1127:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 1128:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 1129:

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

