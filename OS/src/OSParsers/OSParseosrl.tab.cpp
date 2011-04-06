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
#define YYNNTS  766
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1117
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1546

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
    1354,  1358,  1360,  1362,  1365,  1369,  1371,  1376,  1380,  1381,
    1385,  1387,  1389,  1391,  1393,  1396,  1398,  1402,  1404,  1406,
    1409,  1413,  1415,  1420,  1422,  1424,  1427,  1429,  1433,  1435,
    1436,  1439,  1441,  1443,  1445,  1447,  1451,  1458,  1459,  1463,
    1465,  1467,  1469,  1471,  1473,  1477,  1479,  1480,  1484,  1486,
    1488,  1490,  1492,  1494,  1498,  1500,  1501,  1505,  1507,  1509,
    1511,  1513,  1515,  1519,  1521,  1522,  1526,  1528,  1530,  1532,
    1534,  1536,  1540,  1542,  1543,  1547,  1549,  1551,  1553,  1555,
    1557,  1561,  1563,  1564,  1568,  1570,  1572,  1574,  1576,  1578,
    1582,  1584,  1585,  1588,  1592,  1594,  1596,  1597,  1600,  1602,
    1604,  1606,  1608,  1610,  1612,  1614,  1617,  1619,  1623,  1625,
    1627,  1629,  1632,  1636,  1638,  1643,  1645,  1647,  1650,  1652,
    1656,  1658,  1660,  1663,  1667,  1669,  1671,  1672,  1675,  1677,
    1679,  1681,  1683,  1685,  1687,  1691,  1693,  1694,  1698,  1700,
    1701,  1703,  1705,  1707,  1709,  1713,  1717,  1718,  1722,  1724,
    1726,  1728,  1730,  1733,  1735,  1739,  1741,  1743,  1746,  1750,
    1752,  1753,  1758,  1762,  1764,  1766,  1767,  1770,  1772,  1774,
    1776,  1778,  1782,  1789,  1790,  1794,  1796,  1798,  1800,  1802,
    1804,  1808,  1810,  1811,  1815,  1817,  1819,  1821,  1823,  1825,
    1829,  1831,  1832,  1836,  1838,  1840,  1842,  1844,  1846,  1850,
    1852,  1853,  1857,  1859,  1861,  1863,  1865,  1867,  1871,  1873,
    1874,  1878,  1880,  1882,  1884,  1886,  1888,  1892,  1894,  1895,
    1899,  1901,  1903,  1905,  1907,  1909,  1913,  1915,  1916,  1919,
    1923,  1925,  1927,  1928,  1931,  1933,  1935,  1937,  1939,  1941,
    1943,  1945,  1948,  1950,  1954,  1956,  1958,  1960,  1963,  1967,
    1969,  1974,  1976,  1978,  1981,  1983,  1987,  1989,  1991,  1994,
    1998,  2000,  2002,  2003,  2006,  2008,  2010,  2012,  2014,  2016,
    2018,  2022,  2024,  2025,  2029,  2031,  2032,  2034,  2036,  2038,
    2040,  2044,  2048,  2049,  2053,  2055,  2057,  2059,  2061,  2064,
    2066,  2070,  2072,  2074,  2077,  2081,  2083,  2088,  2092,  2093,
    2096,  2098,  2100,  2102,  2104,  2108,  2115,  2116,  2120,  2122,
    2124,  2126,  2128,  2130,  2134,  2136,  2137,  2141,  2143,  2145,
    2147,  2149,  2151,  2155,  2157,  2158,  2162,  2164,  2166,  2168,
    2170,  2172,  2176,  2178,  2179,  2183,  2185,  2187,  2189,  2191,
    2193,  2197,  2199,  2200,  2204,  2206,  2208,  2210,  2212,  2214,
    2218,  2220,  2221,  2225,  2227,  2229,  2231,  2233,  2235,  2239,
    2241,  2242,  2245,  2249,  2251,  2253,  2254,  2257,  2259,  2261,
    2263,  2265,  2267,  2269,  2271,  2274,  2276,  2280,  2282,  2284,
    2286,  2289,  2293,  2295,  2300,  2302,  2304,  2307,  2309,  2313,
    2315,  2317,  2320,  2324,  2326,  2328,  2329,  2332,  2334,  2336,
    2338,  2340,  2342,  2344,  2348,  2350,  2351,  2355,  2357,  2359,
    2361,  2363,  2366,  2368,  2372,  2374,  2376,  2379,  2383,  2385,
    2387,  2388,  2391,  2393,  2395,  2397,  2399,  2401,  2403,  2406,
    2408,  2412,  2414,  2416,  2419,  2421,  2423,  2425,  2427,  2429,
    2433,  2435,  2436,  2440,  2442,  2444,  2446,  2448,  2451,  2453,
    2457,  2459,  2461,  2464,  2468,  2470,  2472,  2473,  2476,  2478,
    2480,  2482,  2484,  2486,  2488,  2491,  2493,  2497,  2499,  2501,
    2504,  2506,  2508,  2510,  2512,  2514,  2518,  2520,  2522,  2524,
    2526,  2528,  2532,  2534,  2536,  2538,  2540,  2544,  2546,  2548,
    2550,  2552,  2556,  2558,  2560,  2562,  2564,  2568,  2570,  2572,
    2574,  2576,  2580,  2582,  2584,  2586,  2588,  2592,  2597,  2602,
    2607,  2612,  2617,  2622,  2627,  2632,  2637,  2642,  2647,  2652,
    2657,  2662,  2667,  2672,  2677,  2682,  2684,  2686,  2687,  2690,
    2694,  2696,  2698,  2699,  2702,  2704,  2706,  2710,  2714,  2719,
    2721,  2723,  2726,  2728,  2732,  2737,  2742,  2744,  2746,  2748,
    2750,  2752,  2755,  2756,  2759,  2761,  2763,  2765
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
     268,    -1,   936,    -1,   928,    -1,   962,    -1,   270,    -1,
     271,    -1,    10,   130,    -1,    11,    -1,    10,   272,   130,
      -1,   273,    -1,   274,    -1,   273,   274,    -1,   275,   276,
     279,    -1,   179,    -1,   277,    -1,    -1,   277,   278,    -1,
     932,    -1,   928,    -1,    10,   180,    -1,    11,    -1,   281,
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
     324,   325,    -1,   153,    -1,   957,    -1,   326,    -1,   327,
      -1,    10,   154,    -1,    11,    -1,    10,   328,   154,    -1,
     329,    -1,   330,    -1,   329,   330,    -1,   331,   332,   335,
      -1,   151,    -1,   333,    -1,    -1,   333,   334,    -1,   932,
      -1,   944,    -1,   928,    -1,    10,   152,    -1,    11,    -1,
      -1,   337,   338,    -1,    59,    -1,   339,    -1,   340,    -1,
      10,    60,    -1,    11,    -1,    10,   341,    60,    -1,   342,
      -1,   343,    -1,   342,   343,    -1,   344,    -1,   350,    -1,
     357,    -1,   364,    -1,   371,    -1,   376,    -1,   345,   346,
      -1,   183,    -1,   347,    -1,   348,    -1,    10,   184,    -1,
      11,    -1,    10,   349,   184,    -1,     4,    -1,   351,   352,
     355,    -1,   101,    -1,   353,    -1,    -1,   353,   354,    -1,
     940,    -1,   928,    -1,    10,   356,   102,    -1,   981,    -1,
     358,   359,   362,    -1,   103,    -1,   360,    -1,    -1,   360,
     361,    -1,   940,    -1,   928,    -1,    10,   363,   104,    -1,
     981,    -1,   365,   366,   369,    -1,    99,    -1,   367,    -1,
      -1,   367,   368,    -1,   940,    -1,   928,    -1,    10,   370,
     100,    -1,   981,    -1,   372,   373,   374,    -1,    97,    -1,
      -1,   928,    -1,    10,   375,    98,    -1,     6,    -1,   377,
     378,   379,    -1,   153,    -1,   957,    -1,   380,    -1,   381,
      -1,    10,   154,    -1,    11,    -1,    10,   382,   154,    -1,
     383,    -1,   384,    -1,   383,   384,    -1,   385,   386,   389,
      -1,   151,    -1,   387,    -1,    -1,   387,   388,    -1,   932,
      -1,   944,    -1,   928,    -1,    10,   152,    -1,    11,    -1,
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
      11,    -1,    10,   427,   168,    -1,   981,    -1,   429,   430,
     431,    -1,   153,    -1,   957,    -1,   432,    -1,   433,    -1,
      10,   154,    -1,    11,    -1,    10,   434,   154,    -1,   435,
      -1,   436,    -1,   435,   436,    -1,   437,   438,   441,    -1,
     151,    -1,   439,    -1,    -1,   439,   440,    -1,   932,    -1,
     944,    -1,   928,    -1,    10,   152,    -1,    11,    -1,    -1,
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
      -1,   191,    -1,   963,    -1,   484,    -1,   485,    -1,    10,
     192,    -1,    11,    -1,    10,   486,   192,    -1,   487,    -1,
     488,    -1,   487,   488,    -1,   489,   490,   492,    -1,   185,
      -1,    -1,   490,   491,    -1,   940,    -1,   936,    -1,   924,
      -1,   928,    -1,   493,    -1,   494,    -1,    10,   186,    -1,
      11,    -1,    10,   495,   186,    -1,   496,    -1,     7,    -1,
       6,    -1,   498,   499,   502,    -1,   201,    -1,   500,    -1,
      -1,   500,   501,    -1,   940,    -1,   928,    -1,    10,   503,
     202,    -1,   981,    -1,   505,   506,   509,    -1,   203,    -1,
     507,    -1,    -1,   507,   508,    -1,   940,    -1,   928,    -1,
      10,   510,   204,    -1,   981,    -1,   512,   513,   516,    -1,
     199,    -1,   514,    -1,    -1,   514,   515,    -1,   940,    -1,
     928,    -1,    10,   517,   200,    -1,   981,    -1,   519,   520,
     521,    -1,   197,    -1,    -1,   928,    -1,    10,   522,   198,
      -1,     6,    -1,   524,   525,   526,    -1,   153,    -1,   957,
      -1,   527,    -1,   528,    -1,    10,   154,    -1,    11,    -1,
      10,   529,   154,    -1,   530,    -1,   531,    -1,   530,   531,
      -1,   532,   533,   536,    -1,   151,    -1,   534,    -1,    -1,
     534,   535,    -1,   932,    -1,   944,    -1,   928,    -1,    10,
     152,    -1,    11,    -1,    -1,   538,   539,   542,    -1,    65,
      -1,   540,    -1,    -1,   540,   541,    -1,   960,    -1,   965,
      -1,   949,    -1,   954,    -1,   543,    -1,   544,    -1,    10,
      66,    -1,    11,    -1,    10,   545,    66,    -1,   546,   901,
      -1,   547,    -1,   546,   547,    -1,   548,   549,   554,    -1,
     169,    -1,   550,    -1,    -1,   550,   551,    -1,   552,    -1,
     553,    -1,    36,   983,     6,   983,    -1,    53,     3,   983,
      -1,    10,   555,   571,   577,   687,   783,   878,   170,    -1,
     556,   557,   560,    -1,   175,    -1,   558,    -1,   559,    -1,
     558,   559,    -1,   936,    -1,   928,    -1,   962,    -1,   561,
      -1,   562,    -1,    10,   176,    -1,    11,    -1,    10,   563,
     176,    -1,   564,    -1,   565,    -1,   564,   565,    -1,   566,
     567,   570,    -1,   179,    -1,   568,    -1,    -1,   568,   569,
      -1,   936,    -1,   928,    -1,    10,   180,    -1,    11,    -1,
      -1,   572,   573,    -1,   141,    -1,   574,    -1,   575,    -1,
      10,   142,    -1,    11,    -1,    10,   576,   142,    -1,     4,
      -1,    -1,   578,   579,   580,    -1,   211,    -1,    -1,   959,
      -1,   581,    -1,   582,    -1,    11,    -1,    10,   583,   212,
      -1,   584,   596,   611,   659,    -1,    -1,   585,   586,   587,
      -1,   205,    -1,   964,    -1,   588,    -1,   589,    -1,    10,
     206,    -1,    11,    -1,    10,   590,   206,    -1,   591,    -1,
     592,    -1,   591,   592,    -1,   593,   594,   595,    -1,   209,
      -1,    37,   983,     6,   983,    -1,    10,   981,   210,    -1,
      -1,   597,   598,   599,    -1,   207,    -1,   964,    -1,   600,
      -1,   601,    -1,    10,   208,    -1,    11,    -1,    10,   602,
     208,    -1,   603,    -1,   604,    -1,   603,   604,    -1,   605,
     606,   607,    -1,   209,    -1,    37,   983,     6,   983,    -1,
     608,    -1,   609,    -1,    10,   210,    -1,    11,    -1,    10,
     610,   210,    -1,     4,    -1,    -1,   612,   613,    -1,   109,
      -1,   614,    -1,   615,    -1,    11,    -1,    10,   616,   110,
      -1,   617,   624,   631,   638,   645,   652,    -1,    -1,   618,
     619,   620,    -1,   107,    -1,   950,    -1,   621,    -1,   622,
      -1,    11,    -1,    10,   623,   108,    -1,   966,    -1,    -1,
     625,   626,   627,    -1,    93,    -1,   950,    -1,   628,    -1,
     629,    -1,    11,    -1,    10,   630,    94,    -1,   966,    -1,
      -1,   632,   633,   634,    -1,    95,    -1,   950,    -1,   635,
      -1,   636,    -1,    11,    -1,    10,   637,    96,    -1,   966,
      -1,    -1,   639,   640,   641,    -1,   137,    -1,   950,    -1,
     642,    -1,   643,    -1,    11,    -1,    10,   644,   138,    -1,
     966,    -1,    -1,   646,   647,   648,    -1,   181,    -1,   950,
      -1,   649,    -1,   650,    -1,    11,    -1,    10,   651,   182,
      -1,   966,    -1,    -1,   653,   654,   655,    -1,   195,    -1,
     950,    -1,   656,    -1,   657,    -1,    11,    -1,    10,   658,
     196,    -1,   966,    -1,    -1,   659,   660,    -1,   661,   662,
     665,    -1,   151,    -1,   663,    -1,    -1,   663,   664,    -1,
     964,    -1,   951,    -1,   944,    -1,   932,    -1,   928,    -1,
     666,    -1,   667,    -1,    10,   152,    -1,    11,    -1,    10,
     668,   152,    -1,   669,    -1,   677,    -1,   670,    -1,   669,
     670,    -1,   671,   672,   673,    -1,   209,    -1,    37,   983,
       6,   983,    -1,   674,    -1,   675,    -1,    10,   210,    -1,
      11,    -1,    10,   676,   210,    -1,   982,    -1,   678,    -1,
     677,   678,    -1,   679,   680,   683,    -1,   125,    -1,   681,
      -1,    -1,   681,   682,    -1,   950,    -1,   944,    -1,   928,
      -1,   684,    -1,   685,    -1,    11,    -1,    10,   686,   126,
      -1,   966,    -1,    -1,   688,   689,   690,    -1,   145,    -1,
      -1,   956,    -1,   691,    -1,   692,    -1,    11,    -1,    10,
     693,   146,    -1,   694,   707,   755,    -1,    -1,   695,   696,
     697,    -1,   205,    -1,   953,    -1,   698,    -1,   699,    -1,
      10,   206,    -1,    11,    -1,    10,   700,   206,    -1,   701,
      -1,   702,    -1,   701,   702,    -1,   703,   704,   705,    -1,
     143,    -1,    -1,    37,   983,     6,   983,    -1,    10,   706,
     144,    -1,     6,    -1,     7,    -1,    -1,   708,   709,    -1,
     109,    -1,   710,    -1,   711,    -1,    11,    -1,    10,   712,
     110,    -1,   713,   720,   727,   734,   741,   748,    -1,    -1,
     714,   715,   716,    -1,   107,    -1,   950,    -1,   717,    -1,
     718,    -1,    11,    -1,    10,   719,   108,    -1,   966,    -1,
      -1,   721,   722,   723,    -1,    93,    -1,   950,    -1,   724,
      -1,   725,    -1,    11,    -1,    10,   726,    94,    -1,   966,
      -1,    -1,   728,   729,   730,    -1,    95,    -1,   950,    -1,
     731,    -1,   732,    -1,    11,    -1,    10,   733,    96,    -1,
     966,    -1,    -1,   735,   736,   737,    -1,   137,    -1,   950,
      -1,   738,    -1,   739,    -1,    11,    -1,    10,   740,   138,
      -1,   966,    -1,    -1,   742,   743,   744,    -1,   181,    -1,
     950,    -1,   745,    -1,   746,    -1,    11,    -1,    10,   747,
     182,    -1,   966,    -1,    -1,   749,   750,   751,    -1,   195,
      -1,   950,    -1,   752,    -1,   753,    -1,    11,    -1,    10,
     754,   196,    -1,   966,    -1,    -1,   755,   756,    -1,   757,
     758,   761,    -1,   151,    -1,   759,    -1,    -1,   759,   760,
      -1,   953,    -1,   951,    -1,   944,    -1,   932,    -1,   928,
      -1,   762,    -1,   763,    -1,    10,   152,    -1,    11,    -1,
      10,   764,   152,    -1,   765,    -1,   773,    -1,   766,    -1,
     765,   766,    -1,   767,   768,   769,    -1,   143,    -1,    37,
     983,     6,   983,    -1,   770,    -1,   771,    -1,    10,   144,
      -1,    11,    -1,    10,   772,   144,    -1,   982,    -1,   774,
      -1,   773,   774,    -1,   775,   776,   779,    -1,   125,    -1,
     777,    -1,    -1,   777,   778,    -1,   950,    -1,   944,    -1,
     928,    -1,   780,    -1,   781,    -1,    11,    -1,    10,   782,
     126,    -1,   966,    -1,    -1,   784,   785,   786,    -1,   115,
      -1,    -1,   955,    -1,   787,    -1,   788,    -1,    11,    -1,
      10,   789,   116,    -1,   790,   802,   850,    -1,    -1,   791,
     792,   793,    -1,   121,    -1,   948,    -1,   794,    -1,   795,
      -1,    10,   122,    -1,    11,    -1,    10,   796,   122,    -1,
     797,    -1,   798,    -1,   797,   798,    -1,   799,   800,   801,
      -1,   113,    -1,    37,   983,     6,   983,    -1,    10,   981,
     114,    -1,    -1,   803,   804,    -1,   109,    -1,   805,    -1,
     806,    -1,    11,    -1,    10,   807,   110,    -1,   808,   815,
     822,   829,   836,   843,    -1,    -1,   809,   810,   811,    -1,
     107,    -1,   950,    -1,   812,    -1,   813,    -1,    11,    -1,
      10,   814,   108,    -1,   966,    -1,    -1,   816,   817,   818,
      -1,    93,    -1,   950,    -1,   819,    -1,   820,    -1,    11,
      -1,    10,   821,    94,    -1,   966,    -1,    -1,   823,   824,
     825,    -1,    95,    -1,   950,    -1,   826,    -1,   827,    -1,
      11,    -1,    10,   828,    96,    -1,   966,    -1,    -1,   830,
     831,   832,    -1,   137,    -1,   950,    -1,   833,    -1,   834,
      -1,    11,    -1,    10,   835,   138,    -1,   966,    -1,    -1,
     837,   838,   839,    -1,   181,    -1,   950,    -1,   840,    -1,
     841,    -1,    11,    -1,    10,   842,   182,    -1,   966,    -1,
      -1,   844,   845,   846,    -1,   195,    -1,   950,    -1,   847,
      -1,   848,    -1,    11,    -1,    10,   849,   196,    -1,   966,
      -1,    -1,   850,   851,    -1,   852,   853,   856,    -1,   151,
      -1,   854,    -1,    -1,   854,   855,    -1,   948,    -1,   951,
      -1,   944,    -1,   932,    -1,   928,    -1,   857,    -1,   858,
      -1,    10,   152,    -1,    11,    -1,    10,   859,   152,    -1,
     860,    -1,   868,    -1,   861,    -1,   860,   861,    -1,   862,
     863,   864,    -1,   113,    -1,    37,   983,     6,   983,    -1,
     865,    -1,   866,    -1,    10,   114,    -1,    11,    -1,    10,
     867,   114,    -1,   982,    -1,   869,    -1,   868,   869,    -1,
     870,   871,   874,    -1,   125,    -1,   872,    -1,    -1,   872,
     873,    -1,   950,    -1,   944,    -1,   928,    -1,   875,    -1,
     876,    -1,    11,    -1,    10,   877,   126,    -1,   966,    -1,
      -1,   879,   880,   881,    -1,   157,    -1,   958,    -1,   882,
      -1,   883,    -1,    10,   158,    -1,    11,    -1,    10,   884,
     158,    -1,   885,    -1,   886,    -1,   885,   886,    -1,   887,
     888,   891,    -1,   155,    -1,   889,    -1,    -1,   889,   890,
      -1,   932,    -1,   924,    -1,   928,    -1,   952,    -1,   892,
      -1,   893,    -1,    10,   156,    -1,    11,    -1,    10,   894,
     156,    -1,   895,    -1,   896,    -1,   895,   896,    -1,   897,
      -1,   898,    -1,   899,    -1,    69,    -1,    70,    -1,    67,
     900,    68,    -1,     5,    -1,    -1,   902,   903,   904,    -1,
     159,    -1,   961,    -1,   905,    -1,   906,    -1,    10,   160,
      -1,    11,    -1,    10,   907,   160,    -1,   908,    -1,   909,
      -1,   908,   909,    -1,   910,   911,   914,    -1,   173,    -1,
     912,    -1,    -1,   912,   913,    -1,   932,    -1,   924,    -1,
     928,    -1,   952,    -1,   915,    -1,   916,    -1,    10,   174,
      -1,    11,    -1,    10,   917,   174,    -1,   918,    -1,   919,
      -1,   918,   919,    -1,   920,    -1,   921,    -1,   922,    -1,
      69,    -1,    70,    -1,    67,   923,    68,    -1,     5,    -1,
     925,    -1,   926,    -1,   927,    -1,    42,    -1,    41,     3,
     983,    -1,   929,    -1,   930,    -1,   931,    -1,    44,    -1,
      43,     3,   983,    -1,   933,    -1,   934,    -1,   935,    -1,
      46,    -1,    45,     3,   983,    -1,   937,    -1,   938,    -1,
     939,    -1,    48,    -1,    47,     3,   983,    -1,   941,    -1,
     942,    -1,   943,    -1,    50,    -1,    49,     3,   983,    -1,
     945,    -1,   946,    -1,   947,    -1,    52,    -1,    51,     3,
     983,    -1,    16,   983,     6,   983,    -1,    17,   983,     6,
     983,    -1,    18,   983,     6,   983,    -1,    19,   983,     6,
     983,    -1,    21,   983,     6,   983,    -1,    22,   983,     6,
     983,    -1,    23,   983,     6,   983,    -1,    24,   983,     6,
     983,    -1,    25,   983,     6,   983,    -1,    26,   983,     6,
     983,    -1,    27,   983,     6,   983,    -1,    28,   983,     6,
     983,    -1,    29,   983,     6,   983,    -1,    30,   983,     6,
     983,    -1,    31,   983,     6,   983,    -1,    32,   983,     6,
     983,    -1,    33,   983,     6,   983,    -1,    34,   983,     6,
     983,    -1,   967,    -1,   974,    -1,    -1,   967,   968,    -1,
     969,   970,   973,    -1,   123,    -1,   971,    -1,    -1,   971,
     972,    -1,   980,    -1,   979,    -1,    10,     6,   124,    -1,
     105,   975,   976,    -1,    40,   983,     6,   983,    -1,   977,
      -1,   978,    -1,    10,   106,    -1,    11,    -1,    10,     4,
     106,    -1,    38,   983,     6,   983,    -1,    39,   983,     6,
     983,    -1,     6,    -1,     7,    -1,     4,    -1,     6,    -1,
       7,    -1,   984,     8,    -1,    -1,   984,   985,    -1,   216,
      -1,   217,    -1,   218,    -1,   219,    -1
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
    1799,  1801,  1803,  1803,  1805,  1812,  1818,  1820,  1823,  1823,
    1825,  1827,  1835,  1839,  1844,  1844,  1846,  1848,  1850,  1850,
    1852,  1860,  1866,  1869,  1870,  1872,  1872,  1874,  1876,  1879,
    1879,  1881,  1886,  1886,  1888,  1890,  1892,  1894,  1894,  1903,
    1905,  1912,  1912,  1914,  1916,  1918,  1921,  1921,  1931,  1933,
    1940,  1940,  1942,  1944,  1946,  1949,  1949,  1958,  1960,  1967,
    1967,  1969,  1971,  1973,  1976,  1976,  1985,  1987,  1994,  1994,
    1996,  1998,  2000,  2003,  2003,  2012,  2014,  2021,  2021,  2023,
    2025,  2027,  2030,  2030,  2039,  2041,  2048,  2048,  2050,  2052,
    2054,  2057,  2057,  2059,  2064,  2077,  2084,  2084,  2087,  2097,
    2107,  2113,  2119,  2126,  2126,  2128,  2128,  2130,  2132,  2132,
    2134,  2134,  2136,  2141,  2143,  2150,  2150,  2152,  2152,  2154,
    2156,  2165,  2165,  2167,  2178,  2187,  2194,  2194,  2197,  2203,
    2209,  2217,  2217,  2219,  2221,  2224,  2228,  2228,  2230,  2238,
    2238,  2246,  2246,  2248,  2250,  2252,  2254,  2254,  2256,  2258,
    2266,  2270,  2275,  2275,  2277,  2279,  2282,  2282,  2284,  2291,
    2298,  2298,  2300,  2303,  2304,  2307,  2307,  2309,  2314,  2314,
    2317,  2319,  2321,  2323,  2323,  2332,  2334,  2341,  2341,  2343,
    2345,  2347,  2349,  2349,  2358,  2360,  2367,  2367,  2369,  2371,
    2373,  2376,  2376,  2385,  2387,  2394,  2394,  2396,  2398,  2400,
    2403,  2403,  2412,  2414,  2421,  2421,  2423,  2425,  2427,  2430,
    2430,  2439,  2441,  2448,  2448,  2450,  2452,  2454,  2457,  2457,
    2466,  2468,  2475,  2475,  2477,  2479,  2481,  2484,  2484,  2486,
    2492,  2505,  2513,  2513,  2516,  2526,  2536,  2542,  2548,  2557,
    2557,  2559,  2559,  2561,  2563,  2563,  2565,  2565,  2567,  2572,
    2574,  2579,  2579,  2581,  2581,  2583,  2585,  2591,  2591,  2593,
    2604,  2613,  2620,  2620,  2623,  2629,  2635,  2643,  2643,  2645,
    2647,  2650,  2653,  2653,  2655,  2662,  2662,  2670,  2670,  2672,
    2674,  2676,  2678,  2678,  2680,  2683,  2691,  2695,  2700,  2700,
    2702,  2704,  2706,  2706,  2708,  2715,  2721,  2723,  2726,  2726,
    2728,  2733,  2733,  2735,  2737,  2739,  2741,  2741,  2750,  2752,
    2759,  2759,  2761,  2763,  2765,  2767,  2767,  2776,  2778,  2785,
    2785,  2787,  2789,  2791,  2794,  2794,  2803,  2805,  2812,  2812,
    2814,  2816,  2818,  2821,  2821,  2830,  2832,  2839,  2839,  2841,
    2843,  2845,  2848,  2848,  2857,  2859,  2866,  2866,  2868,  2870,
    2872,  2875,  2875,  2884,  2886,  2893,  2893,  2895,  2897,  2899,
    2902,  2902,  2904,  2910,  2923,  2930,  2930,  2933,  2943,  2953,
    2959,  2965,  2972,  2972,  2974,  2974,  2976,  2978,  2978,  2980,
    2980,  2982,  2987,  2989,  2995,  2995,  2997,  2997,  2999,  3001,
    3008,  3008,  3010,  3021,  3030,  3037,  3037,  3040,  3046,  3052,
    3060,  3060,  3062,  3064,  3066,  3070,  3070,  3072,  3077,  3086,
    3090,  3095,  3095,  3097,  3099,  3101,  3101,  3103,  3107,  3118,
    3125,  3125,  3128,  3134,  3140,  3148,  3158,  3162,  3167,  3167,
    3169,  3171,  3173,  3173,  3175,  3180,  3184,  3186,  3186,  3188,
    3190,  3201,  3201,  3203,  3208,  3217,  3221,  3226,  3226,  3228,
    3230,  3232,  3232,  3234,  3238,  3249,  3256,  3256,  3259,  3264,
    3270,  3276,  3285,  3289,  3294,  3294,  3296,  3298,  3300,  3300,
    3302,  3307,  3311,  3313,  3313,  3315,  3317,  3327,  3333,  3333,
    3335,  3338,  3341,  3347,  3347,  3349,  3352,  3356,  3362,  3362,
    3364,  3367,  3370,  3376,  3376,  3378,  3381,  3384,  3390,  3390,
    3392,  3395,  3398,  3404,  3404,  3406,  3409,  3432,  3438,  3446,
    3452,  3465,  3474,  3480,  3488,  3494,  3500,  3506,  3512,  3518,
    3526,  3532,  3540,  3545,  3551,  3577,  3582,  3584,  3584,  3586,
    3588,  3597,  3599,  3599,  3601,  3601,  3603,  3611,  3613,  3618,
    3618,  3620,  3620,  3622,  3645,  3653,  3667,  3668,  3672,  3673,
    3674,  3676,  3678,  3678,  3680,  3681,  3682,  3683
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
     589,   590,   591,   591,   592,   593,   594,   595,   596,   596,
     597,   598,   599,   599,   600,   600,   601,   602,   603,   603,
     604,   605,   606,   607,   607,   608,   608,   609,   610,   611,
     611,   612,   613,   613,   614,   615,   616,   617,   617,   618,
     619,   620,   620,   621,   622,   623,   624,   624,   625,   626,
     627,   627,   628,   629,   630,   631,   631,   632,   633,   634,
     634,   635,   636,   637,   638,   638,   639,   640,   641,   641,
     642,   643,   644,   645,   645,   646,   647,   648,   648,   649,
     650,   651,   652,   652,   653,   654,   655,   655,   656,   657,
     658,   659,   659,   660,   661,   662,   663,   663,   664,   664,
     664,   664,   664,   665,   665,   666,   666,   667,   668,   668,
     669,   669,   670,   671,   672,   673,   673,   674,   674,   675,
     676,   677,   677,   678,   679,   680,   681,   681,   682,   682,
     682,   683,   683,   684,   685,   686,   687,   687,   688,   689,
     689,   690,   690,   691,   692,   693,   694,   694,   695,   696,
     697,   697,   698,   698,   699,   700,   701,   701,   702,   703,
     704,   704,   705,   706,   706,   707,   707,   708,   709,   709,
     710,   711,   712,   713,   713,   714,   715,   716,   716,   717,
     718,   719,   720,   720,   721,   722,   723,   723,   724,   725,
     726,   727,   727,   728,   729,   730,   730,   731,   732,   733,
     734,   734,   735,   736,   737,   737,   738,   739,   740,   741,
     741,   742,   743,   744,   744,   745,   746,   747,   748,   748,
     749,   750,   751,   751,   752,   753,   754,   755,   755,   756,
     757,   758,   759,   759,   760,   760,   760,   760,   760,   761,
     761,   762,   762,   763,   764,   764,   765,   765,   766,   767,
     768,   769,   769,   770,   770,   771,   772,   773,   773,   774,
     775,   776,   777,   777,   778,   778,   778,   779,   779,   780,
     781,   782,   783,   783,   784,   785,   785,   786,   786,   787,
     788,   789,   790,   790,   791,   792,   793,   793,   794,   794,
     795,   796,   797,   797,   798,   799,   800,   801,   802,   802,
     803,   804,   804,   805,   806,   807,   808,   808,   809,   810,
     811,   811,   812,   813,   814,   815,   815,   816,   817,   818,
     818,   819,   820,   821,   822,   822,   823,   824,   825,   825,
     826,   827,   828,   829,   829,   830,   831,   832,   832,   833,
     834,   835,   836,   836,   837,   838,   839,   839,   840,   841,
     842,   843,   843,   844,   845,   846,   846,   847,   848,   849,
     850,   850,   851,   852,   853,   854,   854,   855,   855,   855,
     855,   855,   856,   856,   857,   857,   858,   859,   859,   860,
     860,   861,   862,   863,   864,   864,   865,   865,   866,   867,
     868,   868,   869,   870,   871,   872,   872,   873,   873,   873,
     874,   874,   875,   876,   877,   878,   878,   879,   880,   881,
     881,   882,   882,   883,   884,   885,   885,   886,   887,   888,
     889,   889,   890,   890,   890,   890,   891,   891,   892,   892,
     893,   894,   895,   895,   896,   897,   897,   898,   898,   899,
     900,   901,   901,   902,   903,   904,   904,   905,   905,   906,
     907,   908,   908,   909,   910,   911,   912,   912,   913,   913,
     913,   913,   914,   914,   915,   915,   916,   917,   918,   918,
     919,   920,   920,   921,   921,   922,   923,   924,   925,   925,
     926,   927,   928,   929,   929,   930,   931,   932,   933,   933,
     934,   935,   936,   937,   937,   938,   939,   940,   941,   941,
     942,   943,   944,   945,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   966,   966,   967,   967,   968,
     969,   970,   971,   971,   972,   972,   973,   974,   975,   976,
     976,   977,   977,   978,   979,   980,   981,   981,   982,   982,
     982,   983,   984,   984,   985,   985,   985,   985
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
       3,     1,     1,     2,     3,     1,     4,     3,     0,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     4,     1,     1,     2,     1,     3,     1,     0,
       2,     1,     1,     1,     1,     3,     6,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       1,     2,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     0,
       1,     1,     1,     1,     3,     3,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       0,     4,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     3,     6,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     1,     2,     3,     1,
       4,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     0,     1,     1,     1,     1,
       3,     3,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     4,     3,     0,     2,
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
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     1,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     3,     3,     4,     1,
       1,     2,     1,     3,     4,     4,     1,     1,     1,     1,
       1,     2,     0,     2,     1,     1,     1,     1
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
     195,   234,   196,     0,    65,    68,  1112,     0,  1045,     0,
    1055,     0,    80,    81,    84,  1042,  1043,  1044,    83,  1052,
    1053,  1054,    85,     0,   108,   103,   105,   106,     0,   116,
     111,   113,   114,     0,   124,   119,   121,   122,     0,   132,
     127,   129,   130,     0,   140,   135,   137,   138,     0,   148,
     143,   145,   146,     0,   156,   151,   153,   154,  1112,     0,
     161,    29,     0,     0,    42,    41,    44,    38,    39,    40,
     482,    14,   484,     0,   343,   338,   340,   341,   264,   285,
     277,   317,   309,   301,   293,     0,   267,   268,   270,     0,
     271,     0,   272,     0,   273,     0,   274,     0,   275,     0,
     187,   190,     0,   202,   197,   199,   200,     0,   207,     0,
     216,     0,   225,     0,   235,     0,   240,     0,     0,  1112,
    1112,     0,    89,    78,    86,    87,    82,   110,   107,     0,
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
     318,   204,   201,     0,     0,   205,     0,  1060,   209,   211,
     210,  1057,  1058,  1059,     0,   214,   218,   220,   219,     0,
     223,   227,   229,   228,     0,   232,     0,   244,   238,   241,
     242,  1112,  1111,  1114,  1115,  1116,  1117,  1113,  1046,  1056,
      88,    95,     0,    91,    92,    97,   109,   117,   125,   133,
     141,   149,   157,  1112,   171,   164,     0,   167,   168,   173,
      43,     0,     0,    56,    55,    22,    52,    53,    54,     0,
     493,   481,   490,   491,  1112,  1112,  1112,  1112,   485,   488,
     489,   486,   487,   344,   347,     0,   364,   359,   361,   362,
       0,   372,   367,   369,   370,     0,   380,   375,   377,   378,
       0,   388,   383,   385,   386,     0,   396,   391,   393,   394,
    1112,     0,   401,     0,   428,     0,   437,     0,   446,     0,
     456,     0,   461,   283,   280,     0,   291,   288,     0,   299,
     296,     0,   307,   304,     0,  1106,  1107,   312,     0,   315,
       0,   322,   316,   319,   320,   203,     0,   213,  1112,     0,
     222,     0,   231,   237,     0,   250,   243,     0,   246,   247,
     252,  1081,    90,    93,     0,    96,  1076,   166,   169,     0,
     172,    50,     0,   492,   499,     0,  1001,   496,   501,     0,
       0,     0,     0,   366,   363,     0,   374,   371,     0,   382,
     379,     0,   390,   387,     0,   398,   395,     0,     0,     0,
     405,   399,   402,   403,     0,   426,   430,   432,   431,     0,
     435,   439,   441,   440,     0,   444,   448,   450,   449,     0,
     453,     0,   465,   459,   462,   463,   282,   290,   298,   306,
     314,   328,   321,     0,   324,   325,   330,   212,  1061,   221,
     230,   236,   245,   248,     0,   251,     0,   102,    94,     0,
    1050,    98,   100,    99,  1047,  1048,  1049,     0,   179,   170,
       0,  1065,   174,   177,   175,   176,  1062,  1063,  1064,    57,
     494,  1003,   497,   495,     0,     0,   500,  1112,  1112,  1112,
    1112,   365,   373,   381,   389,   397,  1112,   411,   404,     0,
     407,   408,   412,     0,   434,     0,   443,     0,   452,   458,
       0,   471,   464,     0,   467,   468,   473,   323,   326,     0,
     329,     0,   258,   249,   253,   256,   254,   255,   101,  1112,
     178,  1112,  1112,     0,  1004,     0,   498,  1112,     0,   502,
     503,   504,  1068,  1073,  1079,  1084,  1082,   406,   409,     0,
     433,   442,   451,   457,   466,   469,     0,   472,     0,   336,
     327,   331,   334,   332,   333,   257,  1051,  1066,     0,     0,
    1008,  1002,  1005,  1006,   509,   533,     0,     0,  1112,     0,
     421,     0,  1040,   413,   410,   418,   419,   416,  1037,  1038,
    1039,   417,   415,   414,     0,   479,   470,   474,   477,   475,
     476,   335,  1112,  1007,  1014,     0,  1010,  1011,  1016,   535,
     542,     0,     0,   510,   511,   514,   513,   515,  1112,   506,
     425,   424,   420,     0,   423,  1112,   478,  1080,  1009,  1012,
       0,  1015,   544,   696,   545,     0,   539,   534,   536,   537,
       0,   519,   508,   516,   517,   512,   505,   422,  1041,     0,
    1025,  1013,  1022,  1023,  1112,  1017,  1019,  1020,  1018,  1021,
     698,   832,   699,  1112,     0,   546,   541,   538,     0,   518,
     525,     0,   521,   522,   527,     0,  1033,  1034,  1024,     0,
    1027,  1028,  1030,  1031,  1032,     0,   834,   965,   835,  1112,
       0,   700,     0,   552,   549,   543,   547,   548,   540,   520,
     523,     0,   526,  1036,     0,  1026,  1029,  1112,   967,     0,
       0,  1112,     0,   836,     0,   706,   703,   697,   701,   702,
    1112,   554,     0,   568,     0,     0,   532,   524,   528,   530,
     529,  1035,  1071,   507,  1112,     0,   968,     0,   842,   839,
     833,   837,   838,  1112,   708,     0,   725,     0,  1078,   550,
     570,   589,     0,  1112,     0,   555,   531,     0,     0,   972,
     966,   969,   970,  1112,   844,     0,   858,     0,  1075,   704,
     727,   787,     0,  1112,     0,   709,   591,   651,     0,     0,
     571,     0,     0,   559,   553,   556,   557,  1112,   978,   971,
       0,   974,   975,   980,  1074,   840,   860,   920,     0,  1112,
       0,   845,   705,   733,   730,   726,   728,   729,     0,     0,
     713,   707,   710,   711,   551,   597,   594,   590,   592,   593,
       0,   575,   569,   572,   573,  1112,   558,   565,     0,   561,
     562,     0,  1077,   973,   976,     0,   979,   841,   866,   863,
     859,   861,   862,     0,     0,   849,   843,   846,   847,   790,
     788,   792,   735,     0,   742,     0,  1112,   719,   712,     0,
     715,   716,   720,   654,   652,   656,   599,     0,   606,     0,
     574,   581,     0,   577,   578,     0,  1083,   560,   563,  1112,
       0,     0,   989,   977,   986,   987,   981,   983,   984,   982,
     985,   923,   921,   925,   868,     0,   875,     0,  1112,   855,
     848,     0,   851,   852,     0,     0,   791,   731,   744,   751,
       0,  1112,     0,   736,  1072,   714,   717,  1112,     0,     0,
     655,   595,   608,   615,     0,     0,   600,   576,   579,  1112,
       0,     0,     0,   564,     0,   997,   998,   988,     0,   991,
     992,   994,   995,   996,     0,   924,   864,   877,   884,     0,
       0,   869,  1067,   850,   853,  1112,     0,     0,   802,   789,
     799,   800,  1112,   793,   798,   797,   796,   795,   794,   753,
     760,     0,     0,   745,     0,  1087,   739,   734,   737,   738,
       0,     0,   718,     0,   666,   653,   663,   664,   657,   662,
     661,   660,   659,   658,   617,   624,     0,     0,   609,  1087,
     603,   598,   601,   602,     0,     0,   586,   580,   583,   584,
    1112,     0,  1000,     0,   990,   993,     0,   935,   922,   932,
     933,   926,   931,   930,   929,   927,   928,   886,   893,     0,
       0,   878,  1087,   872,   867,   870,   871,     0,     0,   854,
     820,   809,   801,     0,   804,   806,     0,   805,   817,   822,
       0,   762,   769,     0,     0,   754,  1087,   748,   743,   746,
     747,  1112,     0,     0,   741,  1085,  1086,  1112,   723,   724,
       0,   684,   665,   673,     0,   668,   670,     0,   669,   681,
     686,   626,   633,     0,     0,   618,  1087,   612,   607,   610,
     611,     0,   605,  1112,   588,   585,     0,   566,   567,   999,
     942,   953,   934,     0,   937,   939,     0,   938,   950,   955,
     895,   902,     0,     0,   887,  1087,   881,   876,   879,   880,
       0,   874,  1112,     0,   803,   807,  1112,     0,   818,     0,
     821,  1112,   771,   778,     0,     0,   763,  1087,   757,   752,
     755,   756,     0,   750,  1069,  1112,     0,   740,  1090,  1088,
    1092,   721,   722,   667,   671,  1112,     0,   682,     0,   685,
     635,   642,     0,     0,   627,  1087,   621,   616,   619,   620,
       0,   614,   604,   582,   587,   936,   940,  1112,     0,   951,
       0,   954,   904,   911,     0,     0,   896,  1087,   890,   885,
     888,   889,     0,   883,   873,   856,   857,     0,     0,   814,
     808,   811,   812,  1087,   829,   819,   827,   828,   823,   826,
     825,   824,  1070,   780,   732,     0,     0,   772,  1087,   766,
     761,   764,   765,     0,   759,   749,     0,     0,  1102,  1097,
    1099,  1100,     0,  1091,     0,     0,   678,   672,   675,   676,
    1087,   693,   683,   691,   692,   687,   690,   689,   688,   644,
     596,     0,     0,   636,  1087,   630,   625,   628,   629,     0,
     623,   613,     0,     0,   947,   941,   944,   945,  1087,   962,
     952,   960,   961,   956,   959,   958,   957,   913,   865,     0,
       0,   905,  1087,   899,   894,   897,   898,     0,   892,   882,
    1112,  1108,  1109,  1110,   813,     0,   816,     0,   831,     0,
     781,  1087,   775,   770,   773,   774,     0,   768,   758,  1112,
       0,  1101,     0,  1089,  1112,  1112,  1093,  1095,  1094,  1112,
     677,     0,   680,     0,   695,     0,   645,  1087,   639,   634,
     637,   638,     0,   632,   622,  1112,   946,     0,   949,     0,
     964,     0,   914,  1087,   908,   903,   906,   907,     0,   901,
     891,   810,   815,   830,  1087,   784,   779,   782,   783,     0,
     777,   767,  1098,  1103,     0,     0,     0,   674,   679,   694,
    1087,   648,   643,   646,   647,     0,   641,   631,   943,   948,
     963,  1087,   917,   912,   915,   916,     0,   910,   900,     0,
     786,   776,  1096,  1112,  1112,     0,   650,   640,     0,   919,
     909,   785,  1104,  1105,   649,   918
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
     968,   969,   970,   971,  1020,  1073,   891,   892,   919,   962,
     963,   964,  1012,  1013,  1014,  1015,  1070,  1147,  1148,  1149,
    1236,   917,   918,   957,   958,   959,  1007,  1008,  1009,  1065,
    1141,  1142,  1143,  1231,  1063,  1064,  1137,  1228,  1229,  1230,
    1310,  1135,  1136,  1224,  1307,  1308,  1309,  1399,  1222,  1223,
    1303,  1396,  1397,  1398,  1472,  1301,  1302,  1392,  1469,  1470,
    1471,  1515,  1390,  1391,  1465,  1512,  1513,  1514,  1535,   954,
    1004,  1005,  1059,  1060,  1128,  1125,  1126,  1127,  1214,  1215,
    1216,  1217,  1296,  1377,  1378,  1379,  1461,  1218,  1219,  1220,
    1298,  1299,  1385,  1382,  1383,  1384,  1463,   801,   802,   830,
     857,   858,   859,   885,   886,   887,   914,   951,   952,   953,
     999,  1000,  1001,  1002,  1058,  1122,  1210,   911,   912,   945,
     946,   947,   993,   994,   995,  1052,  1117,  1118,  1119,  1203,
    1049,  1050,  1112,  1198,  1199,  1200,  1282,  1110,  1111,  1194,
    1279,  1280,  1281,  1363,  1192,  1193,  1275,  1360,  1361,  1362,
    1446,  1273,  1274,  1356,  1443,  1444,  1445,  1499,  1354,  1355,
    1439,  1496,  1497,  1498,  1529,   942,   990,   991,  1045,  1046,
    1103,  1099,  1100,  1101,  1183,  1184,  1185,  1186,  1267,  1340,
    1341,  1342,  1435,  1187,  1188,  1189,  1269,  1270,  1348,  1345,
    1346,  1347,  1437,   827,   828,   852,   880,   881,   882,   905,
     906,   907,   940,   986,   987,   988,  1041,  1042,  1043,  1044,
    1096,  1179,   937,   938,   980,   981,   982,  1035,  1036,  1037,
    1090,  1174,  1175,  1176,  1260,  1088,  1089,  1170,  1257,  1258,
    1259,  1332,  1168,  1169,  1253,  1329,  1330,  1331,  1427,  1251,
    1252,  1325,  1424,  1425,  1426,  1488,  1323,  1324,  1420,  1485,
    1486,  1487,  1526,  1418,  1419,  1481,  1523,  1524,  1525,  1538,
     977,  1032,  1033,  1084,  1085,  1161,  1158,  1159,  1160,  1243,
    1244,  1245,  1246,  1318,  1405,  1406,  1407,  1477,  1247,  1248,
    1249,  1320,  1321,  1413,  1410,  1411,  1412,  1479,   849,   850,
     875,   900,   901,   902,   930,   931,   932,   933,   975,   976,
    1026,  1023,  1024,  1025,  1078,  1079,  1080,  1081,  1082,  1083,
    1153,   623,   624,   673,   711,   712,   713,   745,   746,   747,
     748,   770,   771,   795,   791,   792,   793,   819,   820,   821,
     822,   823,   824,   844,   727,   728,   729,   730,   134,   135,
     136,   137,   603,   604,   605,   606,   138,   139,   140,   141,
     360,   361,   362,   363,   615,   616,   617,   618,   941,   429,
    1053,  1107,   799,   915,   430,   853,   831,   180,   876,   805,
     431,   674,   142,   462,   895,   432,  1204,  1205,  1289,  1290,
    1372,  1373,  1456,  1453,  1206,  1286,  1369,  1370,  1371,  1457,
    1458,   489,  1436,   237,   238,   387
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1323
static const yytype_int16 yypact[] =
{
     155, -1323, -1323,    63,    39,    91, -1323, -1323,   103,    67,
     361, -1323,   363, -1323, -1323, -1323,    71,   375,    85, -1323,
   -1323, -1323, -1323,    39, -1323, -1323, -1323, -1323, -1323,    81,
     384,    -8, -1323, -1323, -1323, -1323,   143, -1323, -1323,    88,
     145, -1323, -1323, -1323,   103, -1323,    89,   388,   -17, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323,    96,   189, -1323, -1323,   208, -1323,   403,
   -1323,   407, -1323,   415, -1323,   417, -1323,   421, -1323,   423,
   -1323,   425, -1323,   157,    97, -1323,   167, -1323, -1323,   195,
   -1323, -1323, -1323, -1323, -1323,   147,   427,    -3, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   148,
     -30, -1323, -1323,   429, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323,   190, -1323,   157, -1323, -1323, -1323,   224, -1323,   242,
   -1323,   431,   208, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323,    35, -1323, -1323, -1323, -1323,    27, -1323,
   -1323, -1323, -1323,    28, -1323, -1323, -1323, -1323,    40, -1323,
   -1323, -1323, -1323,    31, -1323, -1323, -1323, -1323,    26, -1323,
   -1323, -1323, -1323,     9, -1323, -1323, -1323, -1323, -1323,   433,
   -1323, -1323,   182,   255, -1323, -1323,   231, -1323, -1323, -1323,
   -1323, -1323, -1323,    82, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,   210,   146, -1323, -1323,   435,
   -1323,   437, -1323,   443, -1323,   450, -1323,   454, -1323,   157,
   -1323, -1323,    18, -1323, -1323, -1323, -1323,   260,   187,   270,
     187,   279,   187,   305, -1323,   456, -1323,   285,    -1, -1323,
   -1323,   -62, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   177,
   -1323, -1323,   161, -1323, -1323,   159, -1323, -1323,   185, -1323,
   -1323,   191, -1323, -1323,   163, -1323, -1323,   151,   323,   -13,
   -1323, -1323, -1323, -1323, -1323,   264,   341, -1323, -1323,   268,
   -1323, -1323, -1323,   458,   105, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323,   284,   135, -1323,
   -1323,   461, -1323,   463, -1323,   467, -1323,   469, -1323,   471,
   -1323,   345, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   190,
   -1323,   157, -1323, -1323,    41, -1323, -1323, -1323, -1323,    42,
   -1323, -1323, -1323, -1323,    13, -1323, -1323, -1323, -1323,    16,
   -1323, -1323, -1323, -1323,    21, -1323, -1323, -1323, -1323,   473,
   -1323, -1323, -1323,   218,   479, -1323,   416, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323,   479, -1323, -1323, -1323, -1323,   479,
   -1323, -1323, -1323, -1323,   449, -1323,    78, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323,   327,   283, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,   321,   347, -1323, -1323,
   -1323,   408,   523, -1323, -1323, -1323, -1323, -1323, -1323,   -20,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,    20, -1323, -1323, -1323, -1323,
      17, -1323, -1323, -1323, -1323,    25, -1323, -1323, -1323, -1323,
      43, -1323, -1323, -1323, -1323,    37, -1323, -1323, -1323, -1323,
   -1323,   477, -1323,   532,   187,   557,   187,   559,   187,   569,
   -1323,   486, -1323, -1323, -1323,   455, -1323, -1323,   478, -1323,
   -1323,   432, -1323, -1323,   439, -1323, -1323, -1323,   460, -1323,
      90, -1323, -1323, -1323, -1323, -1323,   527, -1323, -1323,   529,
   -1323,   530, -1323, -1323,   533, -1323, -1323,   481,   485, -1323,
   -1323, -1323, -1323, -1323,   490,   223, -1323, -1323, -1323,   492,
     364, -1323,   549, -1323, -1323,   572,   -82, -1323, -1323,   626,
     633,   634,   635, -1323, -1323,   466, -1323, -1323,   465, -1323,
   -1323,   482, -1323, -1323,   553, -1323, -1323,   518,   641,   -66,
   -1323, -1323, -1323, -1323,   479, -1323, -1323, -1323, -1323,   479,
   -1323, -1323, -1323, -1323,   479, -1323, -1323, -1323, -1323,   642,
   -1323,   139, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323,   495,   499, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323,   494,   364,   474, -1323, -1323,   650,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323,   503, -1323, -1323,
     653, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323,   627,   648,    57, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   468,
     476, -1323, -1323,   457, -1323,   459, -1323,   462, -1323, -1323,
     470, -1323, -1323,   511,   513, -1323, -1323, -1323, -1323,   496,
     364,   515, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323,   498, -1323,   491, -1323, -1323,   667, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   340,
   -1323, -1323, -1323, -1323, -1323, -1323,   500,   364,   519, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   666,   -75,
   -1323, -1323, -1323, -1323, -1323,   535,   208,   668, -1323,    19,
   -1323,   672, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323,   525, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,   521,   505, -1323, -1323, -1323,
     472,   502,   504,   208, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323,   493, -1323, -1323, -1323, -1323, -1323, -1323,
     506,   263, -1323,   539,   657,    36, -1323, -1323, -1323, -1323,
     -87, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,     5,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323,   576,   661, -1323,   508, -1323, -1323, -1323,   545, -1323,
   -1323,   517,   509, -1323, -1323,   684, -1323, -1323, -1323,   537,
     292, -1323, -1323, -1323, -1323,   686, -1323,   541,   670, -1323,
     510, -1323,   689,   497, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323,   512,   254, -1323,   622, -1323, -1323, -1323, -1323,   531,
     673, -1323,   514, -1323,   691,   501, -1323, -1323, -1323, -1323,
   -1323, -1323,   487,   507,   671,   547, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,   516, -1323,   697,   586, -1323,
   -1323, -1323, -1323, -1323, -1323,   562,   601,   690, -1323, -1323,
   -1323,   608,   671, -1323,   520, -1323, -1323,   707,   -26, -1323,
   -1323, -1323, -1323, -1323, -1323,   602,   612,   700, -1323, -1323,
   -1323, -1323,   522, -1323,   524, -1323, -1323, -1323,   526,   528,
   -1323,   714,   -24, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
     564,   577, -1323, -1323, -1323, -1323, -1323, -1323,   534, -1323,
     536, -1323,   579,   617, -1323, -1323, -1323, -1323,   720,   -86,
   -1323, -1323, -1323, -1323,   583,   621, -1323, -1323, -1323, -1323,
     281, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   551,   543,
   -1323,   692, -1323, -1323, -1323,   538,   263,   585,   630, -1323,
   -1323, -1323, -1323,   727,   -22, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323,   628,   646,   722, -1323, -1323, -1323,   554,
     599, -1323,   704, -1323, -1323, -1323, -1323,   636,   651,   722,
   -1323, -1323,   556,   558, -1323,   706, -1323, -1323, -1323, -1323,
     735,    32, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,   637,   655,   722, -1323, -1323,
   -1323,   629,   640, -1323,   713,   540,   378, -1323, -1323,   659,
     722, -1323,   542, -1323, -1323, -1323, -1323, -1323,   745,   544,
     360, -1323, -1323,   663,   722,   546, -1323, -1323, -1323, -1323,
     548,   750,   479, -1323,   754, -1323, -1323, -1323,   606,   296,
   -1323, -1323, -1323, -1323,   550,   324, -1323, -1323,   674,   722,
     552, -1323, -1323, -1323, -1323, -1323,   753,   -37, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
     631,   722,   555, -1323,   759,   665, -1323, -1323, -1323, -1323,
     760,   565, -1323,   -69, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,   638,   722,   563, -1323,   665,
   -1323, -1323, -1323, -1323,   765,     4, -1323, -1323, -1323, -1323,
   -1323,   567, -1323,   705, -1323, -1323,   -49, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   639,   722,
     566, -1323,   665, -1323, -1323, -1323, -1323,   766,   479, -1323,
   -1323, -1323, -1323,   632,   643, -1323,   737,   654, -1323, -1323,
     772, -1323,   610,   722,   571, -1323,   665, -1323, -1323, -1323,
   -1323, -1323,   740,   675, -1323,   658, -1323, -1323, -1323, -1323,
     644, -1323, -1323, -1323,   645,   581, -1323,   748,   664, -1323,
   -1323, -1323,   614,   722,   573, -1323,   665, -1323, -1323, -1323,
   -1323,   685, -1323, -1323, -1323, -1323,   589, -1323, -1323, -1323,
   -1323, -1323, -1323,   649,   669, -1323,   755,   677, -1323, -1323,
   -1323,   615,   722,   575, -1323,   665, -1323, -1323, -1323, -1323,
     695, -1323, -1323,   680, -1323, -1323, -1323,   578, -1323,   580,
     243, -1323, -1323,   603,   722,   582, -1323,   665, -1323, -1323,
   -1323, -1323,   710, -1323, -1323, -1323,   584, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,   588, -1323,   590,   243,
   -1323,   605,   722,   592, -1323,   665, -1323, -1323, -1323, -1323,
     711, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   594, -1323,
     596,   243, -1323,   616,   722,   598, -1323,   665, -1323, -1323,
   -1323, -1323,   712, -1323, -1323, -1323, -1323,   801,    30, -1323,
   -1323, -1323, -1323,   665, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,   722,   600, -1323,   665, -1323,
   -1323, -1323, -1323,   716, -1323, -1323,   802,    45, -1323, -1323,
   -1323, -1323,   799,   574,   804,    11, -1323, -1323, -1323, -1323,
     665, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323,   722,   604, -1323,   665, -1323, -1323, -1323, -1323,   717,
   -1323, -1323,   808,    48, -1323, -1323, -1323, -1323,   665, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   722,
     607, -1323,   665, -1323, -1323, -1323, -1323,   719, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323,   676, -1323,   693, -1323,   609,
   -1323,   665, -1323, -1323, -1323, -1323,   678, -1323, -1323, -1323,
     715, -1323,   811, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323,   618, -1323,   696, -1323,   611, -1323,   665, -1323, -1323,
   -1323, -1323,   688, -1323, -1323, -1323, -1323,   709, -1323,   698,
   -1323,   613, -1323,   665, -1323, -1323, -1323, -1323,   694, -1323,
   -1323, -1323, -1323, -1323,   665, -1323, -1323, -1323, -1323,   647,
   -1323, -1323, -1323, -1323,   703,   824,   825, -1323, -1323, -1323,
     665, -1323, -1323, -1323, -1323,   652, -1323, -1323, -1323, -1323,
   -1323,   665, -1323, -1323, -1323, -1323,   656, -1323, -1323,   660,
   -1323, -1323, -1323, -1323, -1323,   662, -1323, -1323,   679, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   789,   812,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323,   773, -1323, -1323, -1323, -1323,   708, -1323,
   -1323, -1323, -1323, -1323,   446, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
     436, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323,   726, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323,   334, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323,   681, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,   261, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   561,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   204, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323,   192, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323,   322, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,    94,
   -1323, -1323, -1323, -1323, -1323,    38, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323,  -120, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323,  -162, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
    -363, -1323, -1323, -1323, -1323, -1323, -1323, -1323,  -365, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323,  -146, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,  -329, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323,  -326, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,  -180, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323,  -381, -1323, -1323, -1323, -1323, -1323, -1323, -1323,  -383,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,   -65, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323,  -214, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,   121,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,    49,
   -1323, -1323, -1323, -1323,  -757, -1323, -1323, -1323,  -119, -1323,
   -1323, -1323,  -517, -1323, -1323, -1323,  -656, -1323, -1323, -1323,
    -226, -1323, -1323, -1323,  -590, -1323, -1323, -1323,  -217, -1323,
    -999,  -981,  -106,  -175, -1323, -1323, -1323,  -111, -1323, -1323,
   -1323, -1323,  -658, -1323,  -869, -1323, -1130, -1323, -1323, -1323,
   -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323, -1323,
   -1323,  -353, -1322,  -178, -1323, -1323
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     268,   497,   234,   614,   368,   667,   373,   382,  1234,  1232,
    1066,   500,   236,   265,   796,  1431,   502,  1432,  1433,   479,
     482,   536,   351,   920,   533,   760,   761,   485,   486,   539,
     262,   250,   253,   732,  1431,   259,  1432,  1433,  1091,   247,
     806,   545,  1261,   102,   256,   473,   523,   542,   476,  1450,
      53,  1113,  1431,  1462,  1432,  1433,  1211,   997,   757,   198,
     756,   388,   389,     6,  1240,  1138,  1283,   103,   390,   104,
     704,   105,   815,   106,   816,   817,  1241,   621,   666,  1132,
     103,  1478,   104,  1212,   105,   743,   106,   524,  1180,   809,
    1171,  1039,   810,   677,     7,   757,  1311,   756,   744,  1074,
    1040,  1075,  1076,  1242,  1166,    11,  1181,   740,   350,   359,
     678,   367,  1195,   372,   199,  1182,   200,   391,    13,   637,
     998,    54,   424,   107,    15,  1333,   638,    55,   425,   928,
      28,    56,   929,    57,   426,   543,   107,  1225,   404,   427,
    1213,   405,    45,   703,    85,    58,   285,  1364,    84,   524,
     201,  1451,    94,   108,   124,    59,    36,    60,    37,    38,
     477,   474,  1476,    61,   202,   546,   108,     1,     2,   181,
    1254,   260,   182,   286,  1434,  1400,   257,   248,   807,   818,
     739,    62,   966,   178,   203,   967,   870,   540,  1077,   487,
     204,  1133,   254,   251,  1276,   537,   534,  1428,   263,   266,
     470,   644,   352,   511,   483,   762,   646,   480,   220,   287,
     472,   648,   190,  1438,  1235,   383,   384,   385,   386,  1027,
      86,  1460,    87,    88,  1304,   516,   286,   239,  1447,   505,
     127,   128,   506,   127,   128,   288,   356,   357,   558,   126,
     563,   581,   568,   289,   582,   240,   529,   530,   531,   532,
    1464,   127,   128,  1326,   798,   129,   130,   290,   274,   291,
     275,  1051,   287,   199,  1473,   200,   127,   128,   599,   600,
     354,  1351,   322,   292,   183,  1357,   184,   185,  1480,   293,
     364,   294,   548,   295,   794,   296,   127,   128,   288,   369,
     651,   381,  1489,   652,   610,   611,   289,   127,   128,   201,
    1388,   129,   130,  1393,   721,   722,   127,   128,   599,   600,
     290,  1500,   291,   202,   276,   374,   277,   278,    54,   396,
     588,   399,  1416,   398,    55,  1421,   292,   397,    56,   403,
      57,   400,   293,   203,   294,   401,   295,  1516,   296,   204,
     939,   402,    58,  1102,   410,   557,   411,   562,   433,   567,
     719,   720,    59,  1527,    60,   412,  1440,   413,   414,   815,
      61,   816,   817,  1074,  1530,  1075,  1076,   127,   128,   599,
     600,    18,    19,    23,    24,   610,   611,   460,    62,  1102,
    1536,   721,   722,   127,   128,    31,    32,   129,   130,   356,
     357,  1539,  1466,   893,    48,    49,   602,  1102,    97,    98,
     913,   613,   495,   127,   128,   599,   600,   127,   128,   599,
     600,   610,   611,   143,   144,   610,   611,   148,   149,   498,
    1482,   127,   128,   599,   600,   153,   154,   158,   159,   610,
     611,   163,   164,   168,   169,   173,   174,   193,   194,   222,
     223,   241,   242,   269,   270,   324,   325,   329,   330,   682,
     683,   684,   685,   334,   335,   503,  1106,   512,   686,  1029,
     339,   340,   391,   733,   344,   345,   376,   377,   419,   420,
    1131,   435,   436,   440,   441,   517,   665,   445,   446,   450,
     451,   455,   456,   490,   491,   485,   486,   549,   550,  1010,
    1011,   706,   521,   707,   708,  1164,   571,   572,   404,   717,
     596,   597,   607,   608,   661,   662,   698,   699,   709,   710,
     734,   735,   775,   776,   780,   781,   789,   790,   833,   834,
     855,   856,   865,   866,   878,   879,   898,   899,   522,  1105,
     922,   923,   943,   944,   949,   950,   955,   956,   960,   961,
     759,   702,   554,  1130,   978,   979,   984,   985,  1021,  1022,
    1097,  1098,  1115,  1116,  1123,  1124,  1139,  1140,  1145,  1146,
    1156,  1157,  1172,  1173,   767,  1196,  1197,   559,  1163,   564,
     731,  1208,  1209,  1226,  1227,   576,  1255,  1256,   738,   569,
     786,  1277,  1278,  1305,  1306,  1327,  1328,   788,  1338,  1339,
    1343,  1344,  1358,  1359,  1367,  1368,   577,   755,  1375,  1376,
    1380,  1381,  1394,  1395,  1403,  1404,  1408,  1409,  1422,  1423,
    1441,  1442,  1454,  1455,  1467,  1468,   825,  1483,  1484,  1494,
    1495,  1510,  1511,  1521,  1522,   832,   578,   579,   580,   587,
     590,   591,   627,   589,   755,   592,   505,   619,   620,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   649,   657,
     581,   854,   797,   669,   668,   670,   671,   672,   675,   690,
     687,   637,   692,   691,   651,   694,   714,   705,   693,   872,
     718,   741,   742,   877,   758,   765,   749,   766,   744,   787,
    1350,   768,   888,   772,   800,   803,   829,   838,   810,   843,
     871,   826,   847,   839,   851,   860,   897,   883,   848,   889,
     874,   873,   861,   903,   893,   908,   884,   904,   909,  1387,
     910,   845,   913,   927,   890,   921,   939,   916,   935,  1151,
     965,   936,   973,   869,   992,   934,   996,   896,  1006,  1019,
     989,  1415,   928,  1038,  1003,   948,  1031,  1034,  1047,  1048,
    1051,  1057,   997,  1069,  1062,  1072,  1061,  1086,  1087,   972,
    1095,  1093,   967,  1039,  1109,  1121,  1150,  1017,  1134,  1152,
    1055,   983,  1154,  1178,  1067,  1201,  1207,  1011,  1191,  1167,
    1202,  1233,  1262,  1239,  1266,  1221,  1250,  1238,  1271,  1180,
    1285,  1288,  1240,  1287,  1264,  1295,  1181,  1016,  1292,  1211,
    1213,  1272,  1317,  1312,  1336,  1300,  1322,  1293,  1353,  1314,
    1389,  1315,  1241,  1334,  1365,  1401,  1429,  1430,  1449,  1452,
    1459,  1417,  1448,  1474,  1475,  1490,  1501,  1504,  1054,  1493,
    1492,  1503,  1509,  1519,  1520,  1263,  1517,  1532,  1508,  1531,
    1533,  1534,  1528,    93,  1537,    44,   221,   125,  1540,   513,
     246,  1071,   593,   518,   688,   658,   695,   785,   622,  1018,
     840,  1068,  1294,  1297,  1056,  1265,  1541,  1028,  1544,   434,
    1092,  1268,  1094,  1316,  1319,  1155,   974,   769,  1165,   846,
    1030,  1108,     0,  1114,     0,  1545,     0,     0,     0,  1120,
       0,     0,     0,     0,     0,     0,     0,   323,     0,     0,
       0,  1144,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1177,     0,     0,
       0,     0,     0,     0,  1190,     0,     0,  1104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1162,     0,     0,     0,
       0,     0,  1237,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1284,     0,     0,     0,     0,     0,  1291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1313,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1335,     0,     0,     0,  1337,     0,
       0,     0,     0,  1352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1366,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1374,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1402,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1349,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1386,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1414,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1491,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1502,     0,     0,     0,     0,  1505,  1506,     0,     0,
       0,  1507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1518,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1542,  1543
};

static const yytype_int16 yycheck[] =
{
     178,   354,   121,   520,   230,   595,   232,     8,     4,  1139,
    1009,   364,   123,     4,   771,     4,   369,     6,     7,     6,
       4,     4,     4,   892,     4,     6,     7,     6,     7,     4,
       4,     4,     4,   689,     4,     4,     6,     7,  1037,     4,
       4,     4,  1172,    60,     4,     4,    66,     4,     6,     4,
      58,  1050,     4,  1375,     6,     7,   125,   143,   716,    62,
     716,   239,   240,     0,   113,  1064,  1196,    97,   130,    99,
     660,   101,    67,   103,    69,    70,   125,   159,   595,  1060,
      97,  1403,    99,   152,   101,   160,   103,   169,   125,   176,
    1089,   113,   179,    36,    55,   753,  1226,   753,   173,    67,
     122,    69,    70,   152,  1085,    14,   143,   697,   219,   228,
      53,   230,  1111,   232,   117,   152,   119,   179,    15,   185,
     206,   129,    17,   153,    57,  1255,   192,   135,    23,   155,
      59,   139,   158,   141,    29,    92,   153,  1136,   151,    34,
     209,   154,    61,   660,    56,   153,    64,  1277,     5,   169,
     153,   106,    63,   183,    58,   163,    71,   165,    73,    74,
     118,   120,   114,   171,   167,   128,   183,    12,    13,    72,
    1169,   140,     5,    91,   144,  1305,   136,   142,   142,   174,
     697,   189,   206,    26,   187,   209,   842,   162,   156,   168,
     193,  1060,   164,   166,  1193,   178,   176,  1327,   172,   190,
     319,   554,   184,   381,   188,   186,   559,   194,    60,   127,
     321,   564,    65,  1343,   210,   216,   217,   218,   219,   976,
      75,   210,    77,    78,  1223,   403,    91,     3,  1358,   151,
      43,    44,   154,    43,    44,   153,    49,    50,   464,    31,
     466,   151,   468,   161,   154,     3,   424,   425,   426,   427,
    1380,    43,    44,  1252,   771,    47,    48,   175,    76,   177,
       5,    18,   127,   117,  1394,   119,    43,    44,    45,    46,
      10,  1270,    62,   191,    79,  1274,    81,    82,  1408,   197,
      10,   199,   460,   201,    21,   203,    43,    44,   153,    10,
     151,     6,  1422,   154,    51,    52,   161,    43,    44,   153,
    1299,    47,    48,  1302,    41,    42,    43,    44,    45,    46,
     175,  1441,   177,   167,    83,    10,    85,    86,   129,   142,
     498,   136,  1321,   164,   135,  1324,   191,   166,   139,     6,
     141,   140,   197,   187,   199,   172,   201,  1467,   203,   193,
      16,   190,   153,    19,    80,   464,     5,   466,    64,   468,
      10,    11,   163,  1483,   165,    87,  1355,    89,    90,    67,
     171,    69,    70,    67,  1494,    69,    70,    43,    44,    45,
      46,    10,    11,    10,    11,    51,    52,    32,   189,    19,
    1510,    41,    42,    43,    44,    10,    11,    47,    48,    49,
      50,  1521,  1391,    33,    10,    11,   515,    19,    10,    11,
      22,   520,   184,    43,    44,    45,    46,    43,    44,    45,
      46,    51,    52,    10,    11,    51,    52,    10,    11,     3,
    1419,    43,    44,    45,    46,    10,    11,    10,    11,    51,
      52,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   627,
     628,   629,   630,    10,    11,     6,  1046,   130,   636,   976,
      10,    11,   179,   689,    10,    11,    10,    11,    10,    11,
    1060,    10,    11,    10,    11,   154,   595,    10,    11,    10,
      11,    10,    11,    10,    11,     6,     7,    10,    11,   208,
     209,   669,    84,   671,   672,  1085,    10,    11,   151,   677,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,     5,  1046,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     718,   660,    10,  1060,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   742,    10,    11,    10,  1085,    10,
     689,     6,     7,    10,    11,   120,    10,    11,   697,    10,
     758,    10,    11,    10,    11,    10,    11,   765,    10,    11,
      10,    11,    10,    11,    10,    11,   118,   716,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    38,    39,    10,    11,   794,    10,    11,    10,
      11,    10,    11,    10,    11,   803,   194,   188,   168,   102,
     100,    98,     6,   104,   753,   154,   151,    88,    66,     6,
       6,     6,   176,   178,   162,    92,   128,     6,     6,   154,
     151,   829,   771,     3,   180,   152,     3,    30,    10,   202,
     192,   185,   200,   204,   151,   154,   175,   152,   198,   847,
       3,   152,     6,   851,     6,     3,   141,   152,   173,   186,
    1270,   160,   860,   211,   145,    28,    25,   142,   179,     5,
      68,   115,     6,   176,    24,     6,   874,     6,   157,   212,
      27,   170,   205,     6,    33,   883,   205,   121,   146,  1299,
     109,   174,    22,     6,   207,   893,    16,   109,   116,  1072,
       6,   109,   158,   842,   107,   903,     6,   180,   107,    37,
     151,  1321,   155,     6,   151,   913,   151,   107,   110,    93,
      18,    37,   143,    37,    93,    10,   110,   110,    93,   927,
      37,   122,   209,   113,    95,    10,     6,   206,    95,     5,
     206,   939,   156,    10,   208,     6,     6,   209,   137,    95,
     105,     6,     6,    68,    37,   137,   137,   210,     6,   125,
      40,   123,   113,   108,   152,    37,   143,   965,   144,   125,
     209,   181,    37,   108,   114,   181,   181,   152,   195,   210,
     195,   152,   125,   108,    94,    94,    94,     6,     6,    10,
       6,   195,    96,    96,     6,    96,   138,     6,   996,   126,
     144,   106,   126,   114,   126,  1178,   138,   124,   210,   182,
       6,     6,   138,    44,   182,    23,   110,    64,   182,   393,
     132,  1019,   508,   407,   640,   584,   654,   753,   526,   969,
     812,  1013,  1215,  1218,  1000,  1184,   196,   976,   196,   298,
    1038,  1187,  1042,  1244,  1247,  1079,   931,   746,  1085,   820,
     976,  1046,    -1,  1051,    -1,   196,    -1,    -1,    -1,  1057,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,  1069,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1095,    -1,    -1,
      -1,    -1,    -1,    -1,  1102,    -1,    -1,  1046,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1060,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1085,    -1,    -1,    -1,
      -1,    -1,  1150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1201,    -1,    -1,    -1,    -1,    -1,  1207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1262,    -1,    -1,    -1,  1266,    -1,
      -1,    -1,    -1,  1271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1285,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1295,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1317,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1449,    -1,    -1,    -1,    -1,  1454,  1455,    -1,    -1,
      -1,  1459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1475,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1533,  1534
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
      48,   266,   267,   268,   928,   929,   930,   931,   936,   937,
     938,   939,   962,    10,    11,   282,   283,   284,    10,    11,
     288,   289,   290,    10,    11,   294,   295,   296,    10,    11,
     300,   301,   302,    10,    11,   306,   307,   308,    10,    11,
     312,   313,   314,    10,    11,   318,   319,   320,    26,   324,
     957,    72,     5,    79,    81,    82,   244,   245,   246,   247,
      65,   537,   538,    10,    11,   444,   445,   446,    62,   117,
     119,   153,   167,   187,   193,   395,   396,   397,   398,   399,
     404,   405,   410,   411,   416,   417,   422,   423,   428,   429,
      60,   343,    10,    11,   346,   347,   348,   352,   353,   359,
     360,   366,   367,   373,   928,   378,   957,   983,   984,     3,
       3,    10,    11,   269,   270,   271,   268,     4,   142,   285,
       4,   166,   291,     4,   164,   297,     4,   136,   303,     4,
     140,   309,     4,   172,   315,     4,   190,   321,   983,    10,
      11,   325,   326,   327,    76,     5,    83,    85,    86,   248,
     249,   250,   251,   539,   540,    64,    91,   127,   153,   161,
     175,   177,   191,   197,   199,   201,   203,   447,   448,   449,
     450,   451,   456,   457,   462,   463,   468,   469,   474,   475,
     480,   481,   497,   498,   504,   505,   511,   512,   518,   519,
     523,   524,    62,   397,    10,    11,   400,   401,   402,    10,
      11,   406,   407,   408,    10,    11,   412,   413,   414,    10,
      11,   418,   419,   420,    10,    11,   424,   425,   426,   430,
     957,     4,   184,   349,    10,   355,    49,    50,   354,   928,
     940,   941,   942,   943,    10,   362,   361,   928,   940,    10,
     369,   368,   928,   940,    10,   374,    10,    11,   379,   380,
     381,     6,     8,   216,   217,   218,   219,   985,   983,   983,
     130,   179,   272,   273,   274,   275,   142,   166,   164,   136,
     140,   172,   190,     6,   151,   154,   328,   329,   330,   331,
      80,     5,    87,    89,    90,   252,   253,   254,   255,    10,
      11,   542,   543,   544,    17,    23,    29,    34,   541,   949,
     954,   960,   965,    64,   449,    10,    11,   452,   453,   454,
      10,    11,   458,   459,   460,    10,    11,   464,   465,   466,
      10,    11,   470,   471,   472,    10,    11,   476,   477,   478,
      32,   482,   963,   499,   500,   506,   507,   513,   514,   520,
     928,   525,   957,     4,   120,   403,     6,   118,   409,     6,
     194,   415,     4,   188,   421,     6,     7,   168,   427,   981,
      10,    11,   431,   432,   433,   184,   356,   981,     3,   363,
     981,   370,   981,     6,   375,   151,   154,   382,   383,   384,
     385,   983,   130,   274,   276,   277,   983,   154,   330,   332,
     333,    84,     5,    66,   169,   545,   546,   547,   548,   983,
     983,   983,   983,     4,   176,   455,     4,   178,   461,     4,
     162,   467,     4,    92,   473,     4,   128,   479,   983,    10,
      11,   483,   484,   485,    10,   502,   501,   928,   940,    10,
     509,   508,   928,   940,    10,   516,   515,   928,   940,    10,
     521,    10,    11,   526,   527,   528,   120,   118,   194,   188,
     168,   151,   154,   434,   435,   436,   437,   102,   983,   104,
     100,    98,   154,   384,   386,   387,    10,    11,   279,    45,
      46,   278,   928,   932,   933,   934,   935,    10,    11,   335,
      51,    52,   334,   928,   932,   944,   945,   946,   947,    88,
      66,   159,   547,   901,   902,   549,   550,     6,     6,     6,
       6,   176,   178,   162,    92,   128,     6,   185,   192,   486,
     487,   488,   489,   503,   981,   510,   981,   517,   981,     6,
     522,   151,   154,   529,   530,   531,   532,   154,   436,   438,
     439,    10,    11,   389,   388,   928,   932,   944,   180,     3,
     152,     3,    30,   903,   961,    10,   554,    36,    53,   551,
     552,   553,   983,   983,   983,   983,   983,   192,   488,   490,
     202,   204,   200,   198,   154,   531,   533,   534,    10,    11,
     441,   440,   928,   932,   944,   152,   983,   983,   983,    10,
      11,   904,   905,   906,   175,   555,   556,   983,     3,    10,
      11,    41,    42,   491,   492,   493,   494,   924,   925,   926,
     927,   928,   936,   940,    10,    11,   536,   535,   928,   932,
     944,   152,     6,   160,   173,   907,   908,   909,   910,   141,
     571,   572,   557,   558,   559,   928,   936,   962,     6,   983,
       6,     7,   186,   495,   496,     3,   152,   983,   160,   909,
     911,   912,   211,   577,   578,    10,    11,   573,   574,   575,
      10,    11,   560,   561,   562,   559,   983,   186,   983,    10,
      11,   914,   915,   916,    21,   913,   924,   928,   932,   952,
     145,   687,   688,    28,   579,   959,     4,   142,   576,   176,
     179,   563,   564,   565,   566,    67,    69,    70,   174,   917,
     918,   919,   920,   921,   922,   983,   115,   783,   784,    25,
     689,   956,   983,    10,    11,   580,   581,   582,   142,   176,
     565,   567,   568,     5,   923,   174,   919,     6,   157,   878,
     879,    24,   785,   955,   983,    10,    11,   690,   691,   692,
       6,   205,   583,   584,   585,    10,    11,   570,   569,   928,
     936,    68,   983,   170,    27,   880,   958,   983,    10,    11,
     786,   787,   788,     6,   205,   693,   694,   695,   983,   212,
     207,   596,   597,    33,   586,   964,   180,   983,    10,    11,
     881,   882,   883,     6,   121,   789,   790,   791,   983,   146,
     109,   707,   708,    22,   696,   953,   109,   611,   612,   598,
     964,   983,    10,    11,   587,   588,   589,     6,   155,   158,
     884,   885,   886,   887,   983,   116,   109,   802,   803,    16,
     792,   948,   755,    10,    11,   709,   710,   711,   983,    10,
      11,   697,   698,   699,   659,    10,    11,   613,   614,   615,
      10,    11,   599,   600,   601,     6,   206,   209,   590,   591,
     592,   593,   983,   158,   886,   888,   889,   850,    10,    11,
     804,   805,   806,   983,    10,    11,   793,   794,   795,   151,
     756,   757,   107,   712,   713,   714,     6,   143,   206,   700,
     701,   702,   703,   151,   660,   661,   107,   616,   617,   618,
     208,   209,   602,   603,   604,   605,   983,   206,   592,    37,
     594,    10,    11,   891,   892,   893,   890,   924,   928,   932,
     952,   151,   851,   852,   107,   807,   808,   809,     6,   113,
     122,   796,   797,   798,   799,   758,   759,   110,    93,   720,
     721,    18,   715,   950,   983,   206,   702,    37,   704,   662,
     663,   110,    93,   624,   625,   619,   950,   208,   604,    37,
     606,   983,    10,   595,    67,    69,    70,   156,   894,   895,
     896,   897,   898,   899,   853,   854,   110,    93,   815,   816,
     810,   950,   983,   122,   798,    37,   800,    10,    11,   761,
     762,   763,    19,   760,   928,   932,   944,   951,   953,    95,
     727,   728,   722,   950,   983,    10,    11,   716,   717,   718,
     983,    10,   705,    10,    11,   665,   666,   667,   664,   928,
     932,   944,   951,   964,    95,   631,   632,   626,   950,    10,
      11,   620,   621,   622,   983,    10,    11,   607,   608,   609,
       6,   981,     5,   900,   156,   896,    10,    11,   856,   857,
     858,   855,   928,   932,   944,   948,   951,    95,   822,   823,
     817,   950,    10,    11,   811,   812,   813,   983,    10,   801,
     125,   143,   152,   764,   765,   766,   767,   773,   774,   775,
     983,   137,   734,   735,   729,   950,    10,    11,   723,   724,
     725,     6,   105,   719,   966,   967,   974,     6,     6,     7,
     706,   125,   152,   209,   668,   669,   670,   671,   677,   678,
     679,   137,   638,   639,   633,   950,    10,    11,   627,   628,
     629,   623,   966,     6,     4,   210,   610,   983,   210,    68,
     113,   125,   152,   859,   860,   861,   862,   868,   869,   870,
     137,   829,   830,   824,   950,    10,    11,   818,   819,   820,
     814,   966,     6,   981,   152,   766,    37,   768,   774,   776,
     777,     6,   181,   741,   742,   736,   950,    10,    11,   730,
     731,   732,   726,   966,   983,    40,   975,   108,   123,   968,
     969,   983,   144,   152,   670,    37,   672,   678,   680,   681,
     181,   645,   646,   640,   950,    10,    11,   634,   635,   636,
     630,   966,   108,   983,   210,   152,   861,    37,   863,   869,
     871,   872,   181,   836,   837,   831,   950,    10,    11,   825,
     826,   827,   821,   966,   108,   983,   114,   983,    10,    11,
     769,   770,   771,    10,    11,   779,   780,   781,   778,   928,
     944,   950,   983,   195,   748,   749,   743,   950,    10,    11,
     737,   738,   739,   733,   966,    94,   983,    10,    11,   976,
     977,   978,   970,   971,   983,    10,    11,   673,   674,   675,
      10,    11,   683,   684,   685,   682,   928,   944,   950,   195,
     652,   653,   647,   950,    10,    11,   641,   642,   643,   637,
     966,    94,   983,    10,    11,   864,   865,   866,    10,    11,
     874,   875,   876,   873,   928,   944,   950,   195,   843,   844,
     838,   950,    10,    11,   832,   833,   834,   828,   966,    94,
       6,     4,     6,     7,   144,   772,   982,   782,   966,   750,
     950,    10,    11,   744,   745,   746,   740,   966,    96,     6,
       4,   106,    10,   973,    38,    39,   972,   979,   980,     6,
     210,   676,   982,   686,   966,   654,   950,    10,    11,   648,
     649,   650,   644,   966,    96,     6,   114,   867,   982,   877,
     966,   845,   950,    10,    11,   839,   840,   841,   835,   966,
      96,   983,   144,   126,    10,    11,   751,   752,   753,   747,
     966,   138,   983,   106,     6,   983,   983,   983,   210,   126,
      10,    11,   655,   656,   657,   651,   966,   138,   983,   114,
     126,    10,    11,   846,   847,   848,   842,   966,   138,   754,
     966,   182,   124,     6,     6,   658,   966,   182,   849,   966,
     182,   196,   983,   983,   196,   196
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

    {	if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValue failed");
	parserData->kounter++;
;}
    break;

  case 565:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
;}
    break;

  case 566:

    {	parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 571:

    {
	if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
	parserData->kounter = 0;
;}
    break;

  case 572:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 573:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 580:

    {
	if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 				parserData->idx,         parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValueString failed");
	parserData->kounter++;
;}
    break;

  case 581:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
;}
    break;

  case 582:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 583:

    {parserData->tempStr = "";;}
    break;

  case 588:

    {parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));;}
    break;

  case 591:

    {
	osresult->optimization->solution[parserData->solutionIdx]->variables->basisStatus = new BasisStatus();
;}
    break;

  case 598:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 600:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 607:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 609:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 616:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 618:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 625:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 627:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 634:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 636:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 643:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 645:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 653:

    { 	 
		parserData->iOther++;
	;}
    break;

  case 654:

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

  case 655:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfVar attribute"); 
	;}
    break;

  case 658:

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

  case 659:

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

  case 660:

    {	
	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 												  parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 661:

    {	
	 	if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    ;}
    break;

  case 662:

    {	
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 672:

    { 	
	parserData->kounter++;
;}
    break;

  case 674:

    {	
 	if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 											   parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
;}
    break;

  case 680:

    {	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
	;}
    break;

  case 683:

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

  case 684:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 685:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfVarIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfVarIdx attribute"); 
	;}
    break;

  case 688:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 689:

    {	
//	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    ;}
    break;

  case 690:

    {	
//	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    ;}
    break;

  case 698:

    {
	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->objectives = new ObjectiveSolution();
;}
    break;

  case 700:

    {
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
	if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
;}
    break;

  case 709:

    {
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
;}
    break;

  case 710:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	;}
    break;

  case 711:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	;}
    break;

  case 718:

    {	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->tempVal) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
	parserData->kounter++;
;}
    break;

  case 719:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idx = -1;
;}
    break;

  case 721:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 723:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 724:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval); ;}
    break;

  case 727:

    {
	osresult->optimization->solution[parserData->solutionIdx]->objectives->basisStatus = new BasisStatus();
;}
    break;

  case 734:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 736:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 743:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
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
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
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
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
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
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
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
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
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

  case 789:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 790:

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

  case 791:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfObj attribute"); 
	;}
    break;

  case 794:

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

  case 795:

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

  case 796:

    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 797:

    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    ;}
    break;

  case 798:

    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 808:

    {  
	parserData->kounter++;
;}
    break;

  case 810:

    {	if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
;}
    break;

  case 816:

    {	if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
	;}
    break;

  case 819:

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

  case 820:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 821:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfObjIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfObjIdx attribute"); 
	;}
    break;

  case 824:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 825:

    {	
//	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    ;}
    break;

  case 826:

    {	
//	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    ;}
    break;

  case 834:

    {
	parserData->numberOfOtherConstraintResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->constraints = new ConstraintSolution();
;}
    break;

  case 836:

    {
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
;}
    break;

  case 844:

    {	parserData->numberAttributePresent = false; ;}
    break;

  case 845:

    {
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
;}
    break;

  case 846:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	;}
    break;

  case 847:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	;}
    break;

  case 854:

    {	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
	parserData->kounter++;
;}
    break;

  case 855:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
;}
    break;

  case 856:

    { parserData->idx = (yyvsp[(3) - (4)].ival); ;}
    break;

  case 860:

    {
	osresult->optimization->solution[parserData->solutionIdx]->constraints->basisStatus = new BasisStatus();
;}
    break;

  case 867:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 869:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 876:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 878:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 885:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 887:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 894:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 896:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 903:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 905:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 912:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
;}
    break;

  case 914:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 922:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 923:

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

  case 924:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfCon attribute"); 
	;}
    break;

  case 927:

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

  case 928:

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

  case 929:

    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 930:

    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    ;}
    break;

  case 931:

    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 941:

    { 	
	parserData->kounter++;
;}
    break;

  case 943:

    {	
 	if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
;}
    break;

  case 949:

    {	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
	;}
    break;

  case 952:

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

  case 953:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 954:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfConIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfConIdx attribute"); 
	;}
    break;

  case 957:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 958:

    {	
//	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    ;}
    break;

  case 959:

    {	
//	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    ;}
    break;

  case 967:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 968:

    {	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 969:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
	;}
    break;

  case 970:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
	;}
    break;

  case 977:

    {	parserData->iOther++;
;}
    break;

  case 978:

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

  case 979:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
;}
    break;

  case 982:

    {	
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
	;}
    break;

  case 983:

    {	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
	;}
    break;

  case 984:

    {	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
	;}
    break;

  case 985:

    {	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 986:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 987:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 994:

    {	parserData->kounter++;
;}
    break;

  case 995:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 1000:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
											 parserData->kounter, parserData->itemContent) 
											     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultItem failed");
;}
    break;

  case 1003:

    {
	parserData->numberOf = 0; 
;}
    break;

  case 1004:

    {	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
;}
    break;

  case 1005:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
	;}
    break;

  case 1006:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
	;}
    break;

  case 1013:

    {	parserData->iOther++;
;}
    break;

  case 1014:

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

  case 1015:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
;}
    break;

  case 1018:

    {	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
	;}
    break;

  case 1019:

    {	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
	;}
    break;

  case 1020:

    {	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
	;}
    break;

  case 1021:

    {	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	;}
    break;

  case 1022:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 1023:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 1030:

    {	parserData->kounter++;
;}
    break;

  case 1031:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
;}
    break;

  case 1036:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
;}
    break;

  case 1037:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		;}
    break;

  case 1040:

    { parserData->categoryAttribute = ""; ;}
    break;

  case 1041:

    { parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); ;}
    break;

  case 1042:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		;}
    break;

  case 1045:

    { parserData->descriptionAttribute = ""; ;}
    break;

  case 1046:

    { parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1047:

    {   if (parserData->nameAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 1050:

    { parserData->nameAttribute = ""; ;}
    break;

  case 1051:

    { parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1052:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 1055:

    { parserData->typeAttribute = ""; ;}
    break;

  case 1056:

    { parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1057:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 1060:

    { parserData->unitAttribute = ""; ;}
    break;

  case 1061:

    { parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1062:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 1065:

    { parserData->valueAttribute = ""; ;}
    break;

  case 1066:

    { parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));;}
    break;

  case 1067:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1068:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1069:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1070:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1071:

    {	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1072:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1073:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1074:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1075:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1076:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1077:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1078:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1079:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1080:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1081:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1082:

    {
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1083:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1084:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1085:

    {
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	;}
    break;

  case 1090:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
;}
    break;

  case 1096:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
;}
    break;

  case 1098:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1103:

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

  case 1104:

    {	
	if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1105:

    {	
	if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1106:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 1107:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
    break;

  case 1108:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 1109:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 1110:

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

