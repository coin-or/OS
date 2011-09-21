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
     TARGETOBJECTIVENAMEATT = 310,
     EMPTYTARGETOBJECTIVENAMEATT = 311,
     HEADERSTART = 312,
     HEADEREND = 313,
     GENERALSTART = 314,
     GENERALEND = 315,
     SYSTEMSTART = 316,
     SYSTEMEND = 317,
     SERVICESTART = 318,
     SERVICEEND = 319,
     JOBSTART = 320,
     JOBEND = 321,
     OPTIMIZATIONSTART = 322,
     OPTIMIZATIONEND = 323,
     ITEMSTART = 324,
     ITEMEND = 325,
     ITEMSTARTANDEND = 326,
     ITEMEMPTY = 327,
     FILENAMESTART = 328,
     FILENAMEEND = 329,
     FILENAMEEMPTY = 330,
     FILENAMESTARTANDEND = 331,
     FILESOURCESTART = 332,
     FILESOURCEEND = 333,
     FILESOURCEEMPTY = 334,
     FILESOURCESTARTANDEND = 335,
     FILEDESCRIPTIONSTART = 336,
     FILEDESCRIPTIONEND = 337,
     FILEDESCRIPTIONEMPTY = 338,
     FILEDESCRIPTIONSTARTANDEND = 339,
     FILECREATORSTART = 340,
     FILECREATOREND = 341,
     FILECREATOREMPTY = 342,
     FILECREATORSTARTANDEND = 343,
     FILELICENCESTART = 344,
     FILELICENCEEND = 345,
     FILELICENCEEMPTY = 346,
     FILELICENCESTARTANDEND = 347,
     ACTUALSTARTTIMESTART = 348,
     ACTUALSTARTTIMEEND = 349,
     ATLOWERSTART = 350,
     ATLOWEREND = 351,
     ATUPPERSTART = 352,
     ATUPPEREND = 353,
     AVAILABLECPUNUMBERSTART = 354,
     AVAILABLECPUNUMBEREND = 355,
     AVAILABLECPUSPEEDSTART = 356,
     AVAILABLECPUSPEEDEND = 357,
     AVAILABLEDISKSPACESTART = 358,
     AVAILABLEDISKSPACEEND = 359,
     AVAILABLEMEMORYSTART = 360,
     AVAILABLEMEMORYEND = 361,
     BASE64START = 362,
     BASE64END = 363,
     BASICSTART = 364,
     BASICEND = 365,
     BASISSTATUSSTART = 366,
     BASISSTATUSEND = 367,
     BASSTATUSSTART = 368,
     BASSTATUSEND = 369,
     CONSTART = 370,
     CONEND = 371,
     CONSTRAINTSSTART = 372,
     CONSTRAINTSEND = 373,
     CURRENTJOBCOUNTSTART = 374,
     CURRENTJOBCOUNTEND = 375,
     CURRENTSTATESTART = 376,
     CURRENTSTATEEND = 377,
     DUALVALUESSTART = 378,
     DUALVALUESEND = 379,
     ELSTART = 380,
     ELEND = 381,
     ENUMERATIONSTART = 382,
     ENUMERATIONEND = 383,
     ENDTIMESTART = 384,
     ENDTIMEEND = 385,
     GENERALSTATUSSTART = 386,
     GENERALSTATUSEND = 387,
     GENERALSUBSTATUSSTART = 388,
     GENERALSUBSTATUSEND = 389,
     IDXSTART = 390,
     IDXEND = 391,
     INSTANCENAMESTART = 392,
     INSTANCENAMEEND = 393,
     ISFREESTART = 394,
     ISFREEEND = 395,
     JOBIDSTART = 396,
     JOBIDEND = 397,
     MESSAGESTART = 398,
     MESSAGEEND = 399,
     OBJSTART = 400,
     OBJEND = 401,
     OBJECTIVESSTART = 402,
     OBJECTIVESEND = 403,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 404,
     OPTIMIZATIONSOLUTIONSTATUSEND = 405,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 406,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 407,
     OTHERSTART = 408,
     OTHEREND = 409,
     OTHERRESULTSSTART = 410,
     OTHERRESULTSEND = 411,
     OTHERSOLUTIONRESULTSTART = 412,
     OTHERSOLUTIONRESULTEND = 413,
     OTHERSOLUTIONRESULTSSTART = 414,
     OTHERSOLUTIONRESULTSEND = 415,
     OTHERSOLVEROUTPUTSTART = 416,
     OTHERSOLVEROUTPUTEND = 417,
     SCHEDULEDSTARTTIMESTART = 418,
     SCHEDULEDSTARTTIMEEND = 419,
     SERVICENAMESTART = 420,
     SERVICENAMEEND = 421,
     SERVICEURISTART = 422,
     SERVICEURIEND = 423,
     SERVICEUTILIZATIONSTART = 424,
     SERVICEUTILIZATIONEND = 425,
     SOLUTIONSTART = 426,
     SOLUTIONEND = 427,
     SOLVERINVOKEDSTART = 428,
     SOLVERINVOKEDEND = 429,
     SOLVEROUTPUTSTART = 430,
     SOLVEROUTPUTEND = 431,
     STATUSSTART = 432,
     STATUSEND = 433,
     SUBMITTIMESTART = 434,
     SUBMITTIMEEND = 435,
     SUBSTATUSSTART = 436,
     SUBSTATUSEND = 437,
     SUPERBASICSTART = 438,
     SUPERBASICEND = 439,
     SYSTEMINFORMATIONSTART = 440,
     SYSTEMINFORMATIONEND = 441,
     TIMESTART = 442,
     TIMEEND = 443,
     TIMESERVICESTARTEDSTART = 444,
     TIMESERVICESTARTEDEND = 445,
     TIMESTAMPSTART = 446,
     TIMESTAMPEND = 447,
     TIMINGINFORMATIONSTART = 448,
     TIMINGINFORMATIONEND = 449,
     TOTALJOBSSOFARSTART = 450,
     TOTALJOBSSOFAREND = 451,
     UNKNOWNSTART = 452,
     UNKNOWNEND = 453,
     USEDCPUNUMBERSTART = 454,
     USEDCPUNUMBEREND = 455,
     USEDCPUSPEEDSTART = 456,
     USEDCPUSPEEDEND = 457,
     USEDDISKSPACESTART = 458,
     USEDDISKSPACEEND = 459,
     USEDMEMORYSTART = 460,
     USEDMEMORYEND = 461,
     VALUESSTART = 462,
     VALUESEND = 463,
     VALUESSTRINGSTART = 464,
     VALUESSTRINGEND = 465,
     VARSTART = 466,
     VAREND = 467,
     VARIABLESSTART = 468,
     VARIABLESEND = 469,
     VARIDXSTART = 470,
     VARIDXEND = 471,
     DUMMY = 472
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
#define TARGETOBJECTIVENAMEATT 310
#define EMPTYTARGETOBJECTIVENAMEATT 311
#define HEADERSTART 312
#define HEADEREND 313
#define GENERALSTART 314
#define GENERALEND 315
#define SYSTEMSTART 316
#define SYSTEMEND 317
#define SERVICESTART 318
#define SERVICEEND 319
#define JOBSTART 320
#define JOBEND 321
#define OPTIMIZATIONSTART 322
#define OPTIMIZATIONEND 323
#define ITEMSTART 324
#define ITEMEND 325
#define ITEMSTARTANDEND 326
#define ITEMEMPTY 327
#define FILENAMESTART 328
#define FILENAMEEND 329
#define FILENAMEEMPTY 330
#define FILENAMESTARTANDEND 331
#define FILESOURCESTART 332
#define FILESOURCEEND 333
#define FILESOURCEEMPTY 334
#define FILESOURCESTARTANDEND 335
#define FILEDESCRIPTIONSTART 336
#define FILEDESCRIPTIONEND 337
#define FILEDESCRIPTIONEMPTY 338
#define FILEDESCRIPTIONSTARTANDEND 339
#define FILECREATORSTART 340
#define FILECREATOREND 341
#define FILECREATOREMPTY 342
#define FILECREATORSTARTANDEND 343
#define FILELICENCESTART 344
#define FILELICENCEEND 345
#define FILELICENCEEMPTY 346
#define FILELICENCESTARTANDEND 347
#define ACTUALSTARTTIMESTART 348
#define ACTUALSTARTTIMEEND 349
#define ATLOWERSTART 350
#define ATLOWEREND 351
#define ATUPPERSTART 352
#define ATUPPEREND 353
#define AVAILABLECPUNUMBERSTART 354
#define AVAILABLECPUNUMBEREND 355
#define AVAILABLECPUSPEEDSTART 356
#define AVAILABLECPUSPEEDEND 357
#define AVAILABLEDISKSPACESTART 358
#define AVAILABLEDISKSPACEEND 359
#define AVAILABLEMEMORYSTART 360
#define AVAILABLEMEMORYEND 361
#define BASE64START 362
#define BASE64END 363
#define BASICSTART 364
#define BASICEND 365
#define BASISSTATUSSTART 366
#define BASISSTATUSEND 367
#define BASSTATUSSTART 368
#define BASSTATUSEND 369
#define CONSTART 370
#define CONEND 371
#define CONSTRAINTSSTART 372
#define CONSTRAINTSEND 373
#define CURRENTJOBCOUNTSTART 374
#define CURRENTJOBCOUNTEND 375
#define CURRENTSTATESTART 376
#define CURRENTSTATEEND 377
#define DUALVALUESSTART 378
#define DUALVALUESEND 379
#define ELSTART 380
#define ELEND 381
#define ENUMERATIONSTART 382
#define ENUMERATIONEND 383
#define ENDTIMESTART 384
#define ENDTIMEEND 385
#define GENERALSTATUSSTART 386
#define GENERALSTATUSEND 387
#define GENERALSUBSTATUSSTART 388
#define GENERALSUBSTATUSEND 389
#define IDXSTART 390
#define IDXEND 391
#define INSTANCENAMESTART 392
#define INSTANCENAMEEND 393
#define ISFREESTART 394
#define ISFREEEND 395
#define JOBIDSTART 396
#define JOBIDEND 397
#define MESSAGESTART 398
#define MESSAGEEND 399
#define OBJSTART 400
#define OBJEND 401
#define OBJECTIVESSTART 402
#define OBJECTIVESEND 403
#define OPTIMIZATIONSOLUTIONSTATUSSTART 404
#define OPTIMIZATIONSOLUTIONSTATUSEND 405
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 406
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 407
#define OTHERSTART 408
#define OTHEREND 409
#define OTHERRESULTSSTART 410
#define OTHERRESULTSEND 411
#define OTHERSOLUTIONRESULTSTART 412
#define OTHERSOLUTIONRESULTEND 413
#define OTHERSOLUTIONRESULTSSTART 414
#define OTHERSOLUTIONRESULTSEND 415
#define OTHERSOLVEROUTPUTSTART 416
#define OTHERSOLVEROUTPUTEND 417
#define SCHEDULEDSTARTTIMESTART 418
#define SCHEDULEDSTARTTIMEEND 419
#define SERVICENAMESTART 420
#define SERVICENAMEEND 421
#define SERVICEURISTART 422
#define SERVICEURIEND 423
#define SERVICEUTILIZATIONSTART 424
#define SERVICEUTILIZATIONEND 425
#define SOLUTIONSTART 426
#define SOLUTIONEND 427
#define SOLVERINVOKEDSTART 428
#define SOLVERINVOKEDEND 429
#define SOLVEROUTPUTSTART 430
#define SOLVEROUTPUTEND 431
#define STATUSSTART 432
#define STATUSEND 433
#define SUBMITTIMESTART 434
#define SUBMITTIMEEND 435
#define SUBSTATUSSTART 436
#define SUBSTATUSEND 437
#define SUPERBASICSTART 438
#define SUPERBASICEND 439
#define SYSTEMINFORMATIONSTART 440
#define SYSTEMINFORMATIONEND 441
#define TIMESTART 442
#define TIMEEND 443
#define TIMESERVICESTARTEDSTART 444
#define TIMESERVICESTARTEDEND 445
#define TIMESTAMPSTART 446
#define TIMESTAMPEND 447
#define TIMINGINFORMATIONSTART 448
#define TIMINGINFORMATIONEND 449
#define TOTALJOBSSOFARSTART 450
#define TOTALJOBSSOFAREND 451
#define UNKNOWNSTART 452
#define UNKNOWNEND 453
#define USEDCPUNUMBERSTART 454
#define USEDCPUNUMBEREND 455
#define USEDCPUSPEEDSTART 456
#define USEDCPUSPEEDEND 457
#define USEDDISKSPACESTART 458
#define USEDDISKSPACEEND 459
#define USEDMEMORYSTART 460
#define USEDMEMORYEND 461
#define VALUESSTART 462
#define VALUESEND 463
#define VALUESSTRINGSTART 464
#define VALUESSTRINGEND 465
#define VARSTART 466
#define VAREND 467
#define VARIABLESSTART 468
#define VARIABLESEND 469
#define VARIDXSTART 470
#define VARIDXEND 471
#define DUMMY 472




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
#define YYLAST   1355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  222
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  774
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1138
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1545

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   472

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   219,
     221,     2,     2,   220,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   218,     2,     2,     2,     2,     2,     2,     2,
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
     215,   216,   217
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
    1202,  1204,  1205,  1208,  1210,  1212,  1214,  1219,  1223,  1227,
    1236,  1240,  1242,  1244,  1246,  1249,  1251,  1253,  1255,  1257,
    1259,  1262,  1264,  1268,  1270,  1272,  1275,  1279,  1281,  1283,
    1284,  1287,  1289,  1291,  1294,  1296,  1297,  1300,  1302,  1304,
    1306,  1309,  1311,  1315,  1317,  1318,  1322,  1324,  1325,  1327,
    1329,  1331,  1333,  1337,  1342,  1343,  1347,  1349,  1351,  1353,
    1355,  1358,  1360,  1364,  1366,  1368,  1371,  1375,  1377,  1378,
    1381,  1383,  1385,  1389,  1390,  1394,  1396,  1398,  1400,  1402,
    1405,  1407,  1411,  1413,  1415,  1418,  1422,  1424,  1425,  1428,
    1430,  1432,  1434,  1436,  1439,  1441,  1445,  1447,  1448,  1451,
    1453,  1455,  1457,  1459,  1463,  1470,  1471,  1475,  1477,  1479,
    1481,  1483,  1485,  1489,  1491,  1492,  1496,  1498,  1500,  1502,
    1504,  1506,  1510,  1512,  1513,  1517,  1519,  1521,  1523,  1525,
    1527,  1531,  1533,  1534,  1538,  1540,  1542,  1544,  1546,  1548,
    1552,  1554,  1555,  1559,  1561,  1563,  1565,  1567,  1569,  1573,
    1575,  1576,  1580,  1582,  1584,  1586,  1588,  1590,  1594,  1596,
    1597,  1600,  1604,  1606,  1608,  1609,  1612,  1614,  1616,  1618,
    1620,  1622,  1624,  1626,  1629,  1631,  1635,  1637,  1639,  1641,
    1644,  1648,  1650,  1651,  1654,  1656,  1658,  1660,  1662,  1665,
    1667,  1671,  1673,  1675,  1678,  1682,  1684,  1686,  1687,  1690,
    1692,  1694,  1696,  1698,  1700,  1702,  1706,  1708,  1709,  1713,
    1715,  1716,  1718,  1720,  1722,  1724,  1728,  1732,  1733,  1737,
    1739,  1741,  1743,  1745,  1748,  1750,  1754,  1756,  1758,  1761,
    1765,  1767,  1768,  1771,  1773,  1775,  1779,  1780,  1783,  1785,
    1787,  1789,  1791,  1795,  1802,  1803,  1807,  1809,  1811,  1813,
    1815,  1817,  1821,  1823,  1824,  1828,  1830,  1832,  1834,  1836,
    1838,  1842,  1844,  1845,  1849,  1851,  1853,  1855,  1857,  1859,
    1863,  1865,  1866,  1870,  1872,  1874,  1876,  1878,  1880,  1884,
    1886,  1887,  1891,  1893,  1895,  1897,  1899,  1901,  1905,  1907,
    1908,  1912,  1914,  1916,  1918,  1920,  1922,  1926,  1928,  1929,
    1932,  1936,  1938,  1940,  1941,  1944,  1946,  1948,  1950,  1952,
    1954,  1956,  1958,  1961,  1963,  1967,  1969,  1971,  1973,  1976,
    1980,  1982,  1983,  1986,  1988,  1990,  1992,  1994,  1997,  1999,
    2003,  2005,  2007,  2010,  2014,  2016,  2018,  2019,  2022,  2024,
    2026,  2028,  2030,  2032,  2034,  2038,  2040,  2041,  2045,  2047,
    2048,  2050,  2052,  2054,  2056,  2060,  2064,  2065,  2069,  2071,
    2073,  2075,  2077,  2080,  2082,  2086,  2088,  2090,  2093,  2097,
    2099,  2100,  2103,  2105,  2107,  2111,  2112,  2115,  2117,  2119,
    2121,  2123,  2127,  2134,  2135,  2139,  2141,  2143,  2145,  2147,
    2149,  2153,  2155,  2156,  2160,  2162,  2164,  2166,  2168,  2170,
    2174,  2176,  2177,  2181,  2183,  2185,  2187,  2189,  2191,  2195,
    2197,  2198,  2202,  2204,  2206,  2208,  2210,  2212,  2216,  2218,
    2219,  2223,  2225,  2227,  2229,  2231,  2233,  2237,  2239,  2240,
    2244,  2246,  2248,  2250,  2252,  2254,  2258,  2260,  2261,  2264,
    2268,  2270,  2272,  2273,  2276,  2278,  2280,  2282,  2284,  2286,
    2288,  2290,  2293,  2295,  2299,  2301,  2303,  2305,  2308,  2312,
    2314,  2315,  2318,  2320,  2322,  2324,  2326,  2329,  2331,  2335,
    2337,  2339,  2342,  2346,  2348,  2350,  2351,  2354,  2356,  2358,
    2360,  2362,  2364,  2366,  2370,  2372,  2373,  2377,  2379,  2381,
    2383,  2385,  2388,  2390,  2394,  2396,  2398,  2401,  2405,  2407,
    2409,  2410,  2413,  2415,  2417,  2419,  2421,  2423,  2425,  2428,
    2430,  2434,  2436,  2438,  2441,  2443,  2445,  2447,  2449,  2451,
    2455,  2457,  2458,  2462,  2464,  2466,  2468,  2470,  2473,  2475,
    2479,  2481,  2483,  2486,  2490,  2492,  2494,  2495,  2498,  2500,
    2502,  2504,  2506,  2508,  2510,  2513,  2515,  2519,  2521,  2523,
    2526,  2528,  2530,  2532,  2534,  2536,  2540,  2542,  2544,  2546,
    2548,  2550,  2554,  2556,  2558,  2560,  2562,  2566,  2571,  2573,
    2575,  2577,  2579,  2583,  2585,  2587,  2589,  2591,  2595,  2597,
    2599,  2601,  2603,  2607,  2609,  2611,  2613,  2615,  2619,  2624,
    2629,  2634,  2639,  2644,  2649,  2654,  2659,  2664,  2669,  2674,
    2679,  2684,  2689,  2694,  2699,  2704,  2709,  2711,  2713,  2714,
    2717,  2721,  2723,  2725,  2726,  2729,  2731,  2733,  2737,  2741,
    2746,  2748,  2750,  2753,  2755,  2759,  2764,  2769,  2771,  2773,
    2775,  2777,  2779,  2782,  2783,  2786,  2788,  2790,  2792
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     223,     0,    -1,   224,   231,   230,    -1,   225,   226,   227,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   228,    -1,
     229,    -1,    11,    -1,    10,   231,   230,    -1,    15,    -1,
      -1,   232,   258,   338,   392,   444,   539,    -1,    -1,   233,
     234,    -1,    57,    -1,   235,    -1,   236,    -1,    11,    -1,
      10,   237,    58,    -1,   238,   242,   246,   250,   254,    -1,
      -1,   239,    -1,   240,    -1,   241,    -1,    76,    -1,    75,
      -1,    73,     5,    74,    -1,    -1,   243,    -1,   244,    -1,
     245,    -1,    80,    -1,    79,    -1,    77,     5,    78,    -1,
      -1,   247,    -1,   248,    -1,   249,    -1,    84,    -1,    83,
      -1,    81,     5,    82,    -1,    -1,   251,    -1,   252,    -1,
     253,    -1,    88,    -1,    87,    -1,    85,     5,    86,    -1,
      -1,   255,    -1,   256,    -1,   257,    -1,    92,    -1,    91,
      -1,    89,     5,    90,    -1,    -1,   259,   260,    -1,    59,
      -1,   261,    -1,   262,    -1,    10,    60,    -1,    11,    -1,
      10,   263,    60,    -1,   264,    -1,   265,    -1,   264,   265,
      -1,   266,    -1,   282,    -1,   288,    -1,   294,    -1,   300,
      -1,   306,    -1,   312,    -1,   318,    -1,   324,    -1,   267,
     268,   271,    -1,   131,    -1,   269,    -1,   270,    -1,   269,
     270,    -1,   946,    -1,   937,    -1,   972,    -1,   272,    -1,
     273,    -1,    10,   132,    -1,    11,    -1,    10,   274,   132,
      -1,   275,    -1,   276,    -1,   275,   276,    -1,   277,   278,
     281,    -1,   181,    -1,   279,    -1,    -1,   279,   280,    -1,
     942,    -1,   937,    -1,    10,   182,    -1,    11,    -1,   283,
     284,    -1,   143,    -1,   285,    -1,   286,    -1,    10,   144,
      -1,    11,    -1,    10,   287,   144,    -1,     4,    -1,   289,
     290,    -1,   167,    -1,   291,    -1,   292,    -1,    10,   168,
      -1,    11,    -1,    10,   293,   168,    -1,     4,    -1,   295,
     296,    -1,   165,    -1,   297,    -1,   298,    -1,    10,   166,
      -1,    11,    -1,    10,   299,   166,    -1,     4,    -1,   301,
     302,    -1,   137,    -1,   303,    -1,   304,    -1,    10,   138,
      -1,    11,    -1,    10,   305,   138,    -1,     4,    -1,   307,
     308,    -1,   141,    -1,   309,    -1,   310,    -1,    10,   142,
      -1,    11,    -1,    10,   311,   142,    -1,     4,    -1,   313,
     314,    -1,   173,    -1,   315,    -1,   316,    -1,    10,   174,
      -1,    11,    -1,    10,   317,   174,    -1,     4,    -1,   319,
     320,    -1,   191,    -1,   321,    -1,   322,    -1,    10,   192,
      -1,    11,    -1,    10,   323,   192,    -1,     4,    -1,   325,
     326,   327,    -1,   155,    -1,   967,    -1,   328,    -1,   329,
      -1,    10,   156,    -1,    11,    -1,    10,   330,   156,    -1,
     331,    -1,   332,    -1,   331,   332,    -1,   333,   334,   337,
      -1,   153,    -1,   335,    -1,    -1,   335,   336,    -1,   942,
      -1,   954,    -1,   937,    -1,    10,   154,    -1,    11,    -1,
      -1,   339,   340,    -1,    61,    -1,   341,    -1,   342,    -1,
      10,    62,    -1,    11,    -1,    10,   343,    62,    -1,   344,
      -1,   345,    -1,   344,   345,    -1,   346,    -1,   352,    -1,
     359,    -1,   366,    -1,   373,    -1,   378,    -1,   347,   348,
      -1,   185,    -1,   349,    -1,   350,    -1,    10,   186,    -1,
      11,    -1,    10,   351,   186,    -1,     4,    -1,   353,   354,
     357,    -1,   103,    -1,   355,    -1,    -1,   355,   356,    -1,
     950,    -1,   937,    -1,    10,   358,   104,    -1,   991,    -1,
     360,   361,   364,    -1,   105,    -1,   362,    -1,    -1,   362,
     363,    -1,   950,    -1,   937,    -1,    10,   365,   106,    -1,
     991,    -1,   367,   368,   371,    -1,   101,    -1,   369,    -1,
      -1,   369,   370,    -1,   950,    -1,   937,    -1,    10,   372,
     102,    -1,   991,    -1,   374,   375,   376,    -1,    99,    -1,
      -1,   937,    -1,    10,   377,   100,    -1,     6,    -1,   379,
     380,   381,    -1,   155,    -1,   967,    -1,   382,    -1,   383,
      -1,    10,   156,    -1,    11,    -1,    10,   384,   156,    -1,
     385,    -1,   386,    -1,   385,   386,    -1,   387,   388,   391,
      -1,   153,    -1,   389,    -1,    -1,   389,   390,    -1,   942,
      -1,   954,    -1,   937,    -1,    10,   154,    -1,    11,    -1,
      -1,   393,   394,    -1,    63,    -1,   395,    -1,   396,    -1,
      10,    64,    -1,    11,    -1,    10,   397,    64,    -1,   398,
      -1,   399,    -1,   398,   399,    -1,   400,    -1,   406,    -1,
     412,    -1,   418,    -1,   424,    -1,   430,    -1,   401,   402,
      -1,   121,    -1,   403,    -1,   404,    -1,    10,   122,    -1,
      11,    -1,    10,   405,   122,    -1,     4,    -1,   407,   408,
      -1,   119,    -1,   409,    -1,   410,    -1,    10,   120,    -1,
      11,    -1,    10,   411,   120,    -1,     6,    -1,   413,   414,
      -1,   195,    -1,   415,    -1,   416,    -1,    10,   196,    -1,
      11,    -1,    10,   417,   196,    -1,     6,    -1,   419,   420,
      -1,   189,    -1,   421,    -1,   422,    -1,    10,   190,    -1,
      11,    -1,    10,   423,   190,    -1,     4,    -1,   425,   426,
      -1,   169,    -1,   427,    -1,   428,    -1,    10,   170,    -1,
      11,    -1,    10,   429,   170,    -1,   991,    -1,   431,   432,
     433,    -1,   155,    -1,   967,    -1,   434,    -1,   435,    -1,
      10,   156,    -1,    11,    -1,    10,   436,   156,    -1,   437,
      -1,   438,    -1,   437,   438,    -1,   439,   440,   443,    -1,
     153,    -1,   441,    -1,    -1,   441,   442,    -1,   942,    -1,
     954,    -1,   937,    -1,    10,   154,    -1,    11,    -1,    -1,
     445,   446,    -1,    65,    -1,   447,    -1,   448,    -1,    10,
      66,    -1,    11,    -1,    10,   449,    66,    -1,   450,    -1,
     451,    -1,   450,   451,    -1,   452,    -1,   458,    -1,   464,
      -1,   470,    -1,   476,    -1,   482,    -1,   499,    -1,   506,
      -1,   513,    -1,   520,    -1,   525,    -1,   453,   454,    -1,
     177,    -1,   455,    -1,   456,    -1,    10,   178,    -1,    11,
      -1,    10,   457,   178,    -1,     4,    -1,   459,   460,    -1,
     179,    -1,   461,    -1,   462,    -1,    10,   180,    -1,    11,
      -1,    10,   463,   180,    -1,     4,    -1,   465,   466,    -1,
     163,    -1,   467,    -1,   468,    -1,    10,   164,    -1,    11,
      -1,    10,   469,   164,    -1,     4,    -1,   471,   472,    -1,
      93,    -1,   473,    -1,   474,    -1,    10,    94,    -1,    11,
      -1,    10,   475,    94,    -1,     4,    -1,   477,   478,    -1,
     129,    -1,   479,    -1,   480,    -1,    10,   130,    -1,    11,
      -1,    10,   481,   130,    -1,     4,    -1,   483,   484,   485,
      -1,   193,    -1,   973,    -1,   486,    -1,   487,    -1,    10,
     194,    -1,    11,    -1,    10,   488,   194,    -1,   489,    -1,
     490,    -1,   489,   490,    -1,   491,   492,   494,    -1,   187,
      -1,    -1,   492,   493,    -1,   950,    -1,   946,    -1,   933,
      -1,   937,    -1,   495,    -1,   496,    -1,    10,   188,    -1,
      11,    -1,    10,   497,   188,    -1,   498,    -1,     7,    -1,
       6,    -1,   500,   501,   504,    -1,   203,    -1,   502,    -1,
      -1,   502,   503,    -1,   950,    -1,   937,    -1,    10,   505,
     204,    -1,   991,    -1,   507,   508,   511,    -1,   205,    -1,
     509,    -1,    -1,   509,   510,    -1,   950,    -1,   937,    -1,
      10,   512,   206,    -1,   991,    -1,   514,   515,   518,    -1,
     201,    -1,   516,    -1,    -1,   516,   517,    -1,   950,    -1,
     937,    -1,    10,   519,   202,    -1,   991,    -1,   521,   522,
     523,    -1,   199,    -1,    -1,   937,    -1,    10,   524,   200,
      -1,     6,    -1,   526,   527,   528,    -1,   155,    -1,   967,
      -1,   529,    -1,   530,    -1,    10,   156,    -1,    11,    -1,
      10,   531,   156,    -1,   532,    -1,   533,    -1,   532,   533,
      -1,   534,   535,   538,    -1,   153,    -1,   536,    -1,    -1,
     536,   537,    -1,   942,    -1,   954,    -1,   937,    -1,    10,
     154,    -1,    11,    -1,    -1,   540,   541,   544,    -1,    67,
      -1,   542,    -1,    -1,   542,   543,    -1,   970,    -1,   975,
      -1,   959,    -1,   964,    -1,   545,    -1,   546,    -1,    10,
      68,    -1,    11,    -1,    10,   547,    68,    -1,   548,   910,
      -1,   549,    -1,   548,   549,    -1,   550,   551,   557,    -1,
     171,    -1,   552,    -1,    -1,   552,   553,    -1,   554,    -1,
     555,    -1,   556,    -1,    36,   993,     6,   993,    -1,    55,
       3,   993,    -1,    53,     3,   993,    -1,    10,   558,   574,
     580,   693,   790,   887,   172,    -1,   559,   560,   563,    -1,
     177,    -1,   561,    -1,   562,    -1,   561,   562,    -1,   946,
      -1,   937,    -1,   972,    -1,   564,    -1,   565,    -1,    10,
     178,    -1,    11,    -1,    10,   566,   178,    -1,   567,    -1,
     568,    -1,   567,   568,    -1,   569,   570,   573,    -1,   181,
      -1,   571,    -1,    -1,   571,   572,    -1,   946,    -1,   937,
      -1,    10,   182,    -1,    11,    -1,    -1,   575,   576,    -1,
     143,    -1,   577,    -1,   578,    -1,    10,   144,    -1,    11,
      -1,    10,   579,   144,    -1,     4,    -1,    -1,   581,   582,
     583,    -1,   213,    -1,    -1,   969,    -1,   584,    -1,   585,
      -1,    11,    -1,    10,   586,   214,    -1,   587,   600,   616,
     664,    -1,    -1,   588,   589,   590,    -1,   207,    -1,   974,
      -1,   591,    -1,   592,    -1,    10,   208,    -1,    11,    -1,
      10,   593,   208,    -1,   594,    -1,   595,    -1,   594,   595,
      -1,   596,   597,   599,    -1,   211,    -1,    -1,   597,   598,
      -1,   941,    -1,   942,    -1,    10,   991,   212,    -1,    -1,
     601,   602,   603,    -1,   209,    -1,   974,    -1,   604,    -1,
     605,    -1,    10,   210,    -1,    11,    -1,    10,   606,   210,
      -1,   607,    -1,   608,    -1,   607,   608,    -1,   609,   610,
     612,    -1,   211,    -1,    -1,   610,   611,    -1,   941,    -1,
     942,    -1,   613,    -1,   614,    -1,    10,   212,    -1,    11,
      -1,    10,   615,   212,    -1,     4,    -1,    -1,   617,   618,
      -1,   111,    -1,   619,    -1,   620,    -1,    11,    -1,    10,
     621,   112,    -1,   622,   629,   636,   643,   650,   657,    -1,
      -1,   623,   624,   625,    -1,   109,    -1,   960,    -1,   626,
      -1,   627,    -1,    11,    -1,    10,   628,   110,    -1,   976,
      -1,    -1,   630,   631,   632,    -1,    95,    -1,   960,    -1,
     633,    -1,   634,    -1,    11,    -1,    10,   635,    96,    -1,
     976,    -1,    -1,   637,   638,   639,    -1,    97,    -1,   960,
      -1,   640,    -1,   641,    -1,    11,    -1,    10,   642,    98,
      -1,   976,    -1,    -1,   644,   645,   646,    -1,   139,    -1,
     960,    -1,   647,    -1,   648,    -1,    11,    -1,    10,   649,
     140,    -1,   976,    -1,    -1,   651,   652,   653,    -1,   183,
      -1,   960,    -1,   654,    -1,   655,    -1,    11,    -1,    10,
     656,   184,    -1,   976,    -1,    -1,   658,   659,   660,    -1,
     197,    -1,   960,    -1,   661,    -1,   662,    -1,    11,    -1,
      10,   663,   198,    -1,   976,    -1,    -1,   664,   665,    -1,
     666,   667,   670,    -1,   153,    -1,   668,    -1,    -1,   668,
     669,    -1,   974,    -1,   961,    -1,   954,    -1,   942,    -1,
     937,    -1,   671,    -1,   672,    -1,    10,   154,    -1,    11,
      -1,    10,   673,   154,    -1,   674,    -1,   683,    -1,   675,
      -1,   674,   675,    -1,   676,   677,   679,    -1,   211,    -1,
      -1,   677,   678,    -1,   941,    -1,   942,    -1,   680,    -1,
     681,    -1,    10,   212,    -1,    11,    -1,    10,   682,   212,
      -1,   992,    -1,   684,    -1,   683,   684,    -1,   685,   686,
     689,    -1,   127,    -1,   687,    -1,    -1,   687,   688,    -1,
     960,    -1,   954,    -1,   937,    -1,   690,    -1,   691,    -1,
      11,    -1,    10,   692,   128,    -1,   976,    -1,    -1,   694,
     695,   696,    -1,   147,    -1,    -1,   966,    -1,   697,    -1,
     698,    -1,    11,    -1,    10,   699,   148,    -1,   700,   713,
     761,    -1,    -1,   701,   702,   703,    -1,   207,    -1,   963,
      -1,   704,    -1,   705,    -1,    10,   208,    -1,    11,    -1,
      10,   706,   208,    -1,   707,    -1,   708,    -1,   707,   708,
      -1,   709,   710,   712,    -1,   145,    -1,    -1,   710,   711,
      -1,   941,    -1,   942,    -1,    10,   991,   146,    -1,    -1,
     714,   715,    -1,   111,    -1,   716,    -1,   717,    -1,    11,
      -1,    10,   718,   112,    -1,   719,   726,   733,   740,   747,
     754,    -1,    -1,   720,   721,   722,    -1,   109,    -1,   960,
      -1,   723,    -1,   724,    -1,    11,    -1,    10,   725,   110,
      -1,   976,    -1,    -1,   727,   728,   729,    -1,    95,    -1,
     960,    -1,   730,    -1,   731,    -1,    11,    -1,    10,   732,
      96,    -1,   976,    -1,    -1,   734,   735,   736,    -1,    97,
      -1,   960,    -1,   737,    -1,   738,    -1,    11,    -1,    10,
     739,    98,    -1,   976,    -1,    -1,   741,   742,   743,    -1,
     139,    -1,   960,    -1,   744,    -1,   745,    -1,    11,    -1,
      10,   746,   140,    -1,   976,    -1,    -1,   748,   749,   750,
      -1,   183,    -1,   960,    -1,   751,    -1,   752,    -1,    11,
      -1,    10,   753,   184,    -1,   976,    -1,    -1,   755,   756,
     757,    -1,   197,    -1,   960,    -1,   758,    -1,   759,    -1,
      11,    -1,    10,   760,   198,    -1,   976,    -1,    -1,   761,
     762,    -1,   763,   764,   767,    -1,   153,    -1,   765,    -1,
      -1,   765,   766,    -1,   963,    -1,   961,    -1,   954,    -1,
     942,    -1,   937,    -1,   768,    -1,   769,    -1,    10,   154,
      -1,    11,    -1,    10,   770,   154,    -1,   771,    -1,   780,
      -1,   772,    -1,   771,   772,    -1,   773,   774,   776,    -1,
     145,    -1,    -1,   774,   775,    -1,   941,    -1,   942,    -1,
     777,    -1,   778,    -1,    10,   146,    -1,    11,    -1,    10,
     779,   146,    -1,   992,    -1,   781,    -1,   780,   781,    -1,
     782,   783,   786,    -1,   127,    -1,   784,    -1,    -1,   784,
     785,    -1,   960,    -1,   954,    -1,   937,    -1,   787,    -1,
     788,    -1,    11,    -1,    10,   789,   128,    -1,   976,    -1,
      -1,   791,   792,   793,    -1,   117,    -1,    -1,   965,    -1,
     794,    -1,   795,    -1,    11,    -1,    10,   796,   118,    -1,
     797,   810,   858,    -1,    -1,   798,   799,   800,    -1,   123,
      -1,   958,    -1,   801,    -1,   802,    -1,    10,   124,    -1,
      11,    -1,    10,   803,   124,    -1,   804,    -1,   805,    -1,
     804,   805,    -1,   806,   807,   809,    -1,   115,    -1,    -1,
     807,   808,    -1,   941,    -1,   942,    -1,    10,   991,   116,
      -1,    -1,   811,   812,    -1,   111,    -1,   813,    -1,   814,
      -1,    11,    -1,    10,   815,   112,    -1,   816,   823,   830,
     837,   844,   851,    -1,    -1,   817,   818,   819,    -1,   109,
      -1,   960,    -1,   820,    -1,   821,    -1,    11,    -1,    10,
     822,   110,    -1,   976,    -1,    -1,   824,   825,   826,    -1,
      95,    -1,   960,    -1,   827,    -1,   828,    -1,    11,    -1,
      10,   829,    96,    -1,   976,    -1,    -1,   831,   832,   833,
      -1,    97,    -1,   960,    -1,   834,    -1,   835,    -1,    11,
      -1,    10,   836,    98,    -1,   976,    -1,    -1,   838,   839,
     840,    -1,   139,    -1,   960,    -1,   841,    -1,   842,    -1,
      11,    -1,    10,   843,   140,    -1,   976,    -1,    -1,   845,
     846,   847,    -1,   183,    -1,   960,    -1,   848,    -1,   849,
      -1,    11,    -1,    10,   850,   184,    -1,   976,    -1,    -1,
     852,   853,   854,    -1,   197,    -1,   960,    -1,   855,    -1,
     856,    -1,    11,    -1,    10,   857,   198,    -1,   976,    -1,
      -1,   858,   859,    -1,   860,   861,   864,    -1,   153,    -1,
     862,    -1,    -1,   862,   863,    -1,   958,    -1,   961,    -1,
     954,    -1,   942,    -1,   937,    -1,   865,    -1,   866,    -1,
      10,   154,    -1,    11,    -1,    10,   867,   154,    -1,   868,
      -1,   877,    -1,   869,    -1,   868,   869,    -1,   870,   871,
     873,    -1,   115,    -1,    -1,   871,   872,    -1,   941,    -1,
     942,    -1,   874,    -1,   875,    -1,    10,   116,    -1,    11,
      -1,    10,   876,   116,    -1,   992,    -1,   878,    -1,   877,
     878,    -1,   879,   880,   883,    -1,   127,    -1,   881,    -1,
      -1,   881,   882,    -1,   960,    -1,   954,    -1,   937,    -1,
     884,    -1,   885,    -1,    11,    -1,    10,   886,   128,    -1,
     976,    -1,    -1,   888,   889,   890,    -1,   159,    -1,   968,
      -1,   891,    -1,   892,    -1,    10,   160,    -1,    11,    -1,
      10,   893,   160,    -1,   894,    -1,   895,    -1,   894,   895,
      -1,   896,   897,   900,    -1,   157,    -1,   898,    -1,    -1,
     898,   899,    -1,   942,    -1,   933,    -1,   937,    -1,   962,
      -1,   901,    -1,   902,    -1,    10,   158,    -1,    11,    -1,
      10,   903,   158,    -1,   904,    -1,   905,    -1,   904,   905,
      -1,   906,    -1,   907,    -1,   908,    -1,    71,    -1,    72,
      -1,    69,   909,    70,    -1,     5,    -1,    -1,   911,   912,
     913,    -1,   161,    -1,   971,    -1,   914,    -1,   915,    -1,
      10,   162,    -1,    11,    -1,    10,   916,   162,    -1,   917,
      -1,   918,    -1,   917,   918,    -1,   919,   920,   923,    -1,
     175,    -1,   921,    -1,    -1,   921,   922,    -1,   942,    -1,
     933,    -1,   937,    -1,   962,    -1,   924,    -1,   925,    -1,
      10,   176,    -1,    11,    -1,    10,   926,   176,    -1,   927,
      -1,   928,    -1,   927,   928,    -1,   929,    -1,   930,    -1,
     931,    -1,    71,    -1,    72,    -1,    69,   932,    70,    -1,
       5,    -1,   934,    -1,   935,    -1,   936,    -1,    42,    -1,
      41,     3,   993,    -1,   938,    -1,   939,    -1,   940,    -1,
      44,    -1,    43,     3,   993,    -1,    37,   993,     6,   993,
      -1,   943,    -1,   944,    -1,   945,    -1,    46,    -1,    45,
       3,   993,    -1,   947,    -1,   948,    -1,   949,    -1,    48,
      -1,    47,     3,   993,    -1,   951,    -1,   952,    -1,   953,
      -1,    50,    -1,    49,     3,   993,    -1,   955,    -1,   956,
      -1,   957,    -1,    52,    -1,    51,     3,   993,    -1,    16,
     993,     6,   993,    -1,    17,   993,     6,   993,    -1,    18,
     993,     6,   993,    -1,    19,   993,     6,   993,    -1,    21,
     993,     6,   993,    -1,    22,   993,     6,   993,    -1,    23,
     993,     6,   993,    -1,    24,   993,     6,   993,    -1,    25,
     993,     6,   993,    -1,    26,   993,     6,   993,    -1,    27,
     993,     6,   993,    -1,    28,   993,     6,   993,    -1,    29,
     993,     6,   993,    -1,    30,   993,     6,   993,    -1,    31,
     993,     6,   993,    -1,    32,   993,     6,   993,    -1,    33,
     993,     6,   993,    -1,    34,   993,     6,   993,    -1,   977,
      -1,   984,    -1,    -1,   977,   978,    -1,   979,   980,   983,
      -1,   125,    -1,   981,    -1,    -1,   981,   982,    -1,   990,
      -1,   989,    -1,    10,     6,   126,    -1,   107,   985,   986,
      -1,    40,   993,     6,   993,    -1,   987,    -1,   988,    -1,
      10,   108,    -1,    11,    -1,    10,     4,   108,    -1,    38,
     993,     6,   993,    -1,    39,   993,     6,   993,    -1,     6,
      -1,     7,    -1,     4,    -1,     6,    -1,     7,    -1,   994,
       8,    -1,    -1,   994,   995,    -1,   218,    -1,   219,    -1,
     220,    -1,   221,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   192,   192,   193,   195,   202,   209,   209,   211,   211,
     213,   215,   217,   218,   221,   230,   230,   237,   246,   246,
     248,   250,   252,   254,   254,   256,   256,   258,   258,   260,
     266,   266,   268,   268,   270,   270,   272,   278,   278,   280,
     280,   282,   282,   284,   290,   290,   292,   292,   294,   294,
     296,   302,   302,   304,   304,   306,   306,   308,   319,   319,
     321,   335,   335,   337,   337,   339,   341,   343,   343,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   357,   359,
     373,   379,   379,   382,   387,   391,   399,   403,   408,   408,
     410,   412,   414,   414,   416,   420,   429,   434,   434,   437,
     442,   448,   448,   451,   453,   459,   459,   461,   461,   463,
     465,   468,   470,   476,   476,   478,   478,   480,   482,   485,
     487,   493,   493,   495,   495,   497,   499,   502,   504,   510,
     510,   512,   512,   514,   516,   519,   521,   527,   527,   529,
     529,   531,   533,   536,   538,   544,   544,   546,   546,   548,
     550,   553,   555,   561,   561,   563,   563,   565,   567,   570,
     572,   578,   588,   592,   597,   597,   599,   601,   603,   603,
     605,   609,   620,   625,   625,   628,   634,   639,   646,   646,
     650,   650,   652,   663,   663,   665,   665,   667,   669,   671,
     671,   674,   675,   676,   677,   678,   679,   682,   684,   690,
     690,   692,   692,   694,   696,   702,   704,   714,   716,   716,
     719,   725,   730,   732,   737,   739,   749,   751,   751,   754,
     760,   765,   767,   773,   775,   785,   787,   787,   790,   796,
     801,   803,   809,   811,   819,   820,   825,   827,   831,   833,
     839,   849,   853,   858,   858,   860,   862,   864,   864,   866,
     870,   881,   886,   886,   889,   895,   900,   907,   907,   911,
     911,   913,   924,   924,   926,   926,   928,   930,   932,   932,
     935,   936,   937,   938,   939,   940,   943,   945,   951,   951,
     953,   953,   955,   957,   964,   966,   972,   972,   974,   974,
     976,   978,   981,   983,   989,   989,   991,   991,   993,   995,
     998,  1000,  1006,  1006,  1008,  1008,  1010,  1012,  1015,  1017,
    1023,  1023,  1025,  1025,  1027,  1029,  1035,  1037,  1043,  1053,
    1057,  1062,  1062,  1064,  1066,  1068,  1068,  1070,  1074,  1085,
    1090,  1090,  1093,  1099,  1104,  1111,  1111,  1114,  1114,  1116,
    1132,  1132,  1134,  1134,  1136,  1138,  1140,  1140,  1143,  1144,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1156,
    1158,  1164,  1164,  1166,  1166,  1168,  1170,  1177,  1179,  1185,
    1185,  1187,  1187,  1189,  1191,  1194,  1196,  1202,  1202,  1204,
    1204,  1206,  1208,  1211,  1213,  1219,  1219,  1221,  1221,  1223,
    1225,  1228,  1230,  1236,  1236,  1238,  1238,  1240,  1242,  1245,
    1247,  1253,  1262,  1266,  1271,  1271,  1273,  1275,  1277,  1277,
    1279,  1281,  1294,  1294,  1297,  1297,  1297,  1297,  1300,  1300,
    1302,  1302,  1304,  1306,  1319,  1320,  1323,  1325,  1335,  1337,
    1337,  1340,  1346,  1351,  1353,  1359,  1361,  1371,  1373,  1373,
    1376,  1382,  1387,  1389,  1395,  1397,  1407,  1409,  1409,  1412,
    1418,  1423,  1425,  1431,  1433,  1442,  1443,  1448,  1450,  1455,
    1457,  1463,  1473,  1477,  1482,  1482,  1484,  1486,  1488,  1488,
    1490,  1494,  1505,  1510,  1510,  1513,  1519,  1524,  1531,  1531,
    1534,  1534,  1536,  1544,  1549,  1549,  1552,  1559,  1565,  1571,
    1579,  1583,  1588,  1588,  1590,  1592,  1594,  1594,  1596,  1598,
    1607,  1609,  1609,  1611,  1611,  1611,  1613,  1622,  1631,  1648,
    1654,  1656,  1666,  1671,  1671,  1674,  1679,  1683,  1692,  1696,
    1702,  1702,  1704,  1706,  1708,  1708,  1710,  1713,  1722,  1727,
    1727,  1730,  1736,  1743,  1743,  1746,  1746,  1748,  1750,  1750,
    1752,  1752,  1754,  1756,  1763,  1763,  1765,  1771,  1771,  1779,
    1779,  1781,  1783,  1785,  1787,  1787,  1789,  1791,  1799,  1803,
    1808,  1808,  1810,  1812,  1814,  1814,  1816,  1827,  1836,  1836,
    1839,  1840,  1843,  1846,  1846,  1848,  1850,  1858,  1862,  1867,
    1867,  1869,  1871,  1873,  1873,  1875,  1886,  1895,  1895,  1898,
    1899,  1903,  1904,  1906,  1906,  1908,  1910,  1913,  1913,  1915,
    1920,  1920,  1922,  1924,  1926,  1928,  1928,  1937,  1939,  1946,
    1946,  1948,  1950,  1952,  1955,  1955,  1965,  1967,  1974,  1974,
    1976,  1978,  1980,  1983,  1983,  1992,  1994,  2001,  2001,  2003,
    2005,  2007,  2010,  2010,  2019,  2021,  2028,  2028,  2030,  2032,
    2034,  2037,  2037,  2046,  2048,  2055,  2055,  2057,  2059,  2061,
    2064,  2064,  2073,  2075,  2082,  2082,  2084,  2086,  2088,  2091,
    2091,  2093,  2098,  2111,  2118,  2118,  2121,  2131,  2141,  2147,
    2153,  2160,  2160,  2162,  2162,  2164,  2166,  2166,  2168,  2168,
    2170,  2177,  2186,  2186,  2189,  2195,  2203,  2203,  2205,  2205,
    2207,  2209,  2218,  2218,  2220,  2231,  2240,  2247,  2247,  2250,
    2256,  2262,  2270,  2270,  2272,  2274,  2277,  2281,  2281,  2283,
    2291,  2291,  2299,  2299,  2301,  2303,  2305,  2307,  2307,  2309,
    2311,  2319,  2323,  2328,  2328,  2330,  2332,  2335,  2335,  2337,
    2345,  2355,  2355,  2358,  2359,  2362,  2365,  2365,  2367,  2372,
    2372,  2375,  2377,  2379,  2381,  2381,  2390,  2392,  2399,  2399,
    2401,  2403,  2405,  2407,  2407,  2416,  2418,  2425,  2425,  2427,
    2429,  2431,  2434,  2434,  2443,  2445,  2452,  2452,  2454,  2456,
    2458,  2461,  2461,  2470,  2472,  2479,  2479,  2481,  2483,  2485,
    2488,  2488,  2497,  2499,  2506,  2506,  2508,  2510,  2512,  2515,
    2515,  2524,  2526,  2533,  2533,  2535,  2537,  2539,  2542,  2542,
    2544,  2550,  2563,  2571,  2571,  2574,  2584,  2594,  2600,  2606,
    2615,  2615,  2617,  2617,  2619,  2621,  2621,  2623,  2623,  2625,
    2630,  2640,  2640,  2643,  2648,  2656,  2656,  2658,  2658,  2660,
    2662,  2668,  2668,  2670,  2681,  2690,  2697,  2697,  2700,  2706,
    2712,  2720,  2720,  2722,  2724,  2727,  2730,  2730,  2732,  2739,
    2739,  2747,  2747,  2749,  2751,  2753,  2755,  2755,  2757,  2760,
    2768,  2772,  2777,  2777,  2779,  2781,  2783,  2783,  2785,  2793,
    2802,  2802,  2805,  2806,  2809,  2812,  2812,  2814,  2819,  2819,
    2821,  2823,  2825,  2827,  2827,  2836,  2838,  2845,  2845,  2847,
    2849,  2851,  2853,  2853,  2862,  2864,  2871,  2871,  2873,  2875,
    2877,  2880,  2880,  2889,  2891,  2898,  2898,  2900,  2902,  2904,
    2907,  2907,  2916,  2918,  2925,  2925,  2927,  2929,  2931,  2934,
    2934,  2943,  2945,  2952,  2952,  2954,  2956,  2958,  2961,  2961,
    2970,  2972,  2979,  2979,  2981,  2983,  2985,  2988,  2988,  2990,
    2996,  3009,  3016,  3016,  3019,  3029,  3039,  3045,  3051,  3058,
    3058,  3060,  3060,  3062,  3064,  3064,  3066,  3066,  3068,  3075,
    3084,  3084,  3088,  3093,  3101,  3101,  3103,  3103,  3105,  3107,
    3114,  3114,  3116,  3127,  3136,  3143,  3143,  3146,  3152,  3158,
    3166,  3166,  3168,  3170,  3172,  3176,  3176,  3178,  3183,  3192,
    3196,  3201,  3201,  3203,  3205,  3207,  3207,  3209,  3213,  3224,
    3231,  3231,  3234,  3240,  3246,  3254,  3264,  3268,  3273,  3273,
    3275,  3277,  3279,  3279,  3281,  3286,  3290,  3292,  3292,  3294,
    3296,  3307,  3307,  3309,  3314,  3323,  3327,  3332,  3332,  3334,
    3336,  3338,  3338,  3340,  3344,  3355,  3362,  3362,  3365,  3370,
    3376,  3382,  3391,  3395,  3400,  3400,  3402,  3404,  3406,  3406,
    3408,  3413,  3417,  3419,  3419,  3421,  3423,  3433,  3439,  3439,
    3441,  3444,  3447,  3453,  3453,  3455,  3458,  3461,  3469,  3475,
    3475,  3477,  3480,  3483,  3489,  3489,  3491,  3494,  3497,  3503,
    3503,  3505,  3508,  3511,  3517,  3517,  3519,  3522,  3545,  3551,
    3559,  3565,  3578,  3587,  3593,  3601,  3607,  3613,  3619,  3625,
    3631,  3639,  3645,  3653,  3658,  3664,  3690,  3695,  3697,  3697,
    3699,  3701,  3710,  3712,  3712,  3714,  3714,  3716,  3724,  3726,
    3731,  3731,  3733,  3733,  3735,  3758,  3766,  3780,  3781,  3785,
    3786,  3787,  3789,  3791,  3791,  3793,  3794,  3795,  3796
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
  "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT",
  "TARGETOBJECTIVENAMEATT", "EMPTYTARGETOBJECTIVENAMEATT", "HEADERSTART",
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
  "targetObjectiveNameATT", "weightedObjectivesATT", "solutionContent",
  "solutionStatus", "solutionStatusStart", "solutionStatusAttributes",
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
     465,   466,   467,   468,   469,   470,   471,   472,    32,     9,
      13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   222,   223,   223,   224,   225,   226,   226,   227,   227,
     228,   229,   230,   230,   231,   232,   232,   233,   234,   234,
     235,   236,   237,   238,   238,   239,   239,   240,   240,   241,
     242,   242,   243,   243,   244,   244,   245,   246,   246,   247,
     247,   248,   248,   249,   250,   250,   251,   251,   252,   252,
     253,   254,   254,   255,   255,   256,   256,   257,   258,   258,
     259,   260,   260,   261,   261,   262,   263,   264,   264,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   266,   267,
     268,   269,   269,   270,   270,   270,   271,   271,   272,   272,
     273,   274,   275,   275,   276,   277,   278,   279,   279,   280,
     280,   281,   281,   282,   283,   284,   284,   285,   285,   286,
     287,   288,   289,   290,   290,   291,   291,   292,   293,   294,
     295,   296,   296,   297,   297,   298,   299,   300,   301,   302,
     302,   303,   303,   304,   305,   306,   307,   308,   308,   309,
     309,   310,   311,   312,   313,   314,   314,   315,   315,   316,
     317,   318,   319,   320,   320,   321,   321,   322,   323,   324,
     325,   326,   327,   327,   328,   328,   329,   330,   331,   331,
     332,   333,   334,   335,   335,   336,   336,   336,   337,   337,
     338,   338,   339,   340,   340,   341,   341,   342,   343,   344,
     344,   345,   345,   345,   345,   345,   345,   346,   347,   348,
     348,   349,   349,   350,   351,   352,   353,   354,   355,   355,
     356,   356,   357,   358,   359,   360,   361,   362,   362,   363,
     363,   364,   365,   366,   367,   368,   369,   369,   370,   370,
     371,   372,   373,   374,   375,   375,   376,   377,   378,   379,
     380,   381,   381,   382,   382,   383,   384,   385,   385,   386,
     387,   388,   389,   389,   390,   390,   390,   391,   391,   392,
     392,   393,   394,   394,   395,   395,   396,   397,   398,   398,
     399,   399,   399,   399,   399,   399,   400,   401,   402,   402,
     403,   403,   404,   405,   406,   407,   408,   408,   409,   409,
     410,   411,   412,   413,   414,   414,   415,   415,   416,   417,
     418,   419,   420,   420,   421,   421,   422,   423,   424,   425,
     426,   426,   427,   427,   428,   429,   430,   431,   432,   433,
     433,   434,   434,   435,   436,   437,   437,   438,   439,   440,
     441,   441,   442,   442,   442,   443,   443,   444,   444,   445,
     446,   446,   447,   447,   448,   449,   450,   450,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   452,
     453,   454,   454,   455,   455,   456,   457,   458,   459,   460,
     460,   461,   461,   462,   463,   464,   465,   466,   466,   467,
     467,   468,   469,   470,   471,   472,   472,   473,   473,   474,
     475,   476,   477,   478,   478,   479,   479,   480,   481,   482,
     483,   484,   485,   485,   486,   486,   487,   488,   489,   489,
     490,   491,   492,   492,   493,   493,   493,   493,   494,   494,
     495,   495,   496,   497,   498,   498,   499,   500,   501,   502,
     502,   503,   503,   504,   505,   506,   507,   508,   509,   509,
     510,   510,   511,   512,   513,   514,   515,   516,   516,   517,
     517,   518,   519,   520,   521,   522,   522,   523,   524,   525,
     526,   527,   528,   528,   529,   529,   530,   531,   532,   532,
     533,   534,   535,   536,   536,   537,   537,   537,   538,   538,
     539,   539,   540,   541,   542,   542,   543,   543,   543,   543,
     544,   544,   545,   545,   546,   547,   548,   548,   549,   550,
     551,   552,   552,   553,   553,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   561,   562,   562,   562,   563,   563,
     564,   564,   565,   566,   567,   567,   568,   569,   570,   571,
     571,   572,   572,   573,   573,   574,   574,   575,   576,   576,
     577,   577,   578,   579,   580,   580,   581,   582,   582,   583,
     583,   584,   585,   586,   587,   587,   588,   589,   590,   590,
     591,   591,   592,   593,   594,   594,   595,   596,   597,   597,
     598,   598,   599,   600,   600,   601,   602,   603,   603,   604,
     604,   605,   606,   607,   607,   608,   609,   610,   610,   611,
     611,   612,   612,   613,   613,   614,   615,   616,   616,   617,
     618,   618,   619,   620,   621,   622,   622,   623,   624,   625,
     625,   626,   627,   628,   629,   629,   630,   631,   632,   632,
     633,   634,   635,   636,   636,   637,   638,   639,   639,   640,
     641,   642,   643,   643,   644,   645,   646,   646,   647,   648,
     649,   650,   650,   651,   652,   653,   653,   654,   655,   656,
     657,   657,   658,   659,   660,   660,   661,   662,   663,   664,
     664,   665,   666,   667,   668,   668,   669,   669,   669,   669,
     669,   670,   670,   671,   671,   672,   673,   673,   674,   674,
     675,   676,   677,   677,   678,   678,   679,   679,   680,   680,
     681,   682,   683,   683,   684,   685,   686,   687,   687,   688,
     688,   688,   689,   689,   690,   691,   692,   693,   693,   694,
     695,   695,   696,   696,   697,   698,   699,   700,   700,   701,
     702,   703,   703,   704,   704,   705,   706,   707,   707,   708,
     709,   710,   710,   711,   711,   712,   713,   713,   714,   715,
     715,   716,   717,   718,   719,   719,   720,   721,   722,   722,
     723,   724,   725,   726,   726,   727,   728,   729,   729,   730,
     731,   732,   733,   733,   734,   735,   736,   736,   737,   738,
     739,   740,   740,   741,   742,   743,   743,   744,   745,   746,
     747,   747,   748,   749,   750,   750,   751,   752,   753,   754,
     754,   755,   756,   757,   757,   758,   759,   760,   761,   761,
     762,   763,   764,   765,   765,   766,   766,   766,   766,   766,
     767,   767,   768,   768,   769,   770,   770,   771,   771,   772,
     773,   774,   774,   775,   775,   776,   776,   777,   777,   778,
     779,   780,   780,   781,   782,   783,   784,   784,   785,   785,
     785,   786,   786,   787,   788,   789,   790,   790,   791,   792,
     792,   793,   793,   794,   795,   796,   797,   797,   798,   799,
     800,   800,   801,   801,   802,   803,   804,   804,   805,   806,
     807,   807,   808,   808,   809,   810,   810,   811,   812,   812,
     813,   814,   815,   816,   816,   817,   818,   819,   819,   820,
     821,   822,   823,   823,   824,   825,   826,   826,   827,   828,
     829,   830,   830,   831,   832,   833,   833,   834,   835,   836,
     837,   837,   838,   839,   840,   840,   841,   842,   843,   844,
     844,   845,   846,   847,   847,   848,   849,   850,   851,   851,
     852,   853,   854,   854,   855,   856,   857,   858,   858,   859,
     860,   861,   862,   862,   863,   863,   863,   863,   863,   864,
     864,   865,   865,   866,   867,   867,   868,   868,   869,   870,
     871,   871,   872,   872,   873,   873,   874,   874,   875,   876,
     877,   877,   878,   879,   880,   881,   881,   882,   882,   882,
     883,   883,   884,   885,   886,   887,   887,   888,   889,   890,
     890,   891,   891,   892,   893,   894,   894,   895,   896,   897,
     898,   898,   899,   899,   899,   899,   900,   900,   901,   901,
     902,   903,   904,   904,   905,   906,   906,   907,   907,   908,
     909,   910,   910,   911,   912,   913,   913,   914,   914,   915,
     916,   917,   917,   918,   919,   920,   921,   921,   922,   922,
     922,   922,   923,   923,   924,   924,   925,   926,   927,   927,
     928,   929,   929,   930,   930,   931,   932,   933,   934,   934,
     935,   936,   937,   938,   938,   939,   940,   941,   942,   943,
     943,   944,   945,   946,   947,   947,   948,   949,   950,   951,
     951,   952,   953,   954,   955,   955,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   967,   968,   969,
     970,   971,   972,   973,   974,   975,   976,   976,   977,   977,
     978,   979,   980,   981,   981,   982,   982,   983,   984,   985,
     986,   986,   987,   987,   988,   989,   990,   991,   991,   992,
     992,   992,   993,   994,   994,   995,   995,   995,   995
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
       1,     0,     2,     1,     1,     1,     4,     3,     3,     8,
       3,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     2,     1,     0,     2,     1,     1,     1,
       2,     1,     3,     1,     0,     3,     1,     0,     1,     1,
       1,     1,     3,     4,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     0,     2,
       1,     1,     3,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     0,     2,     1,
       1,     1,     1,     2,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     3,     6,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     2,
       3,     1,     0,     2,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       0,     1,     1,     1,     1,     3,     3,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     0,     2,     1,     1,     3,     0,     2,     1,     1,
       1,     1,     3,     6,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     2,     3,
       1,     0,     2,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     0,
       1,     1,     1,     1,     3,     3,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       0,     2,     1,     1,     3,     0,     2,     1,     1,     1,
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
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     4,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     3,     3,     4,
       1,     1,     2,     1,     3,     4,     4,     1,     1,     1,
       1,     1,     2,     0,     2,     1,     1,     1,     1
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
     195,   234,   196,     0,    65,    68,  1133,     0,  1065,     0,
    1076,     0,    80,    81,    84,  1062,  1063,  1064,    83,  1073,
    1074,  1075,    85,     0,   108,   103,   105,   106,     0,   116,
     111,   113,   114,     0,   124,   119,   121,   122,     0,   132,
     127,   129,   130,     0,   140,   135,   137,   138,     0,   148,
     143,   145,   146,     0,   156,   151,   153,   154,  1133,     0,
     161,    29,     0,     0,    42,    41,    44,    38,    39,    40,
     482,    14,   484,     0,   343,   338,   340,   341,   264,   285,
     277,   317,   309,   301,   293,     0,   267,   268,   270,     0,
     271,     0,   272,     0,   273,     0,   274,     0,   275,     0,
     187,   190,     0,   202,   197,   199,   200,     0,   207,     0,
     216,     0,   225,     0,   235,     0,   240,     0,     0,  1133,
    1133,     0,    89,    78,    86,    87,    82,   110,   107,     0,
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
     318,   204,   201,     0,     0,   205,     0,  1081,   209,   211,
     210,  1078,  1079,  1080,     0,   214,   218,   220,   219,     0,
     223,   227,   229,   228,     0,   232,     0,   244,   238,   241,
     242,  1133,  1132,  1135,  1136,  1137,  1138,  1134,  1066,  1077,
      88,    95,     0,    91,    92,    97,   109,   117,   125,   133,
     141,   149,   157,  1133,   171,   164,     0,   167,   168,   173,
      43,     0,     0,    56,    55,    22,    52,    53,    54,     0,
     493,   481,   490,   491,  1133,  1133,  1133,  1133,   485,   488,
     489,   486,   487,   344,   347,     0,   364,   359,   361,   362,
       0,   372,   367,   369,   370,     0,   380,   375,   377,   378,
       0,   388,   383,   385,   386,     0,   396,   391,   393,   394,
    1133,     0,   401,     0,   428,     0,   437,     0,   446,     0,
     456,     0,   461,   283,   280,     0,   291,   288,     0,   299,
     296,     0,   307,   304,     0,  1127,  1128,   312,     0,   315,
       0,   322,   316,   319,   320,   203,     0,   213,  1133,     0,
     222,     0,   231,   237,     0,   250,   243,     0,   246,   247,
     252,  1102,    90,    93,     0,    96,  1097,   166,   169,     0,
     172,    50,     0,   492,   499,     0,  1021,   496,   501,     0,
       0,     0,     0,   366,   363,     0,   374,   371,     0,   382,
     379,     0,   390,   387,     0,   398,   395,     0,     0,     0,
     405,   399,   402,   403,     0,   426,   430,   432,   431,     0,
     435,   439,   441,   440,     0,   444,   448,   450,   449,     0,
     453,     0,   465,   459,   462,   463,   282,   290,   298,   306,
     314,   328,   321,     0,   324,   325,   330,   212,  1082,   221,
     230,   236,   245,   248,     0,   251,     0,   102,    94,     0,
    1071,    98,   100,    99,  1068,  1069,  1070,     0,   179,   170,
       0,  1086,   174,   177,   175,   176,  1083,  1084,  1085,    57,
     494,  1023,   497,   495,     0,     0,   500,  1133,  1133,  1133,
    1133,   365,   373,   381,   389,   397,  1133,   411,   404,     0,
     407,   408,   412,     0,   434,     0,   443,     0,   452,   458,
       0,   471,   464,     0,   467,   468,   473,   323,   326,     0,
     329,     0,   258,   249,   253,   256,   254,   255,   101,  1133,
     178,  1133,  1133,     0,  1024,     0,   498,  1133,     0,     0,
     502,   503,   504,   505,  1089,  1094,  1100,  1105,  1103,   406,
     409,     0,   433,   442,   451,   457,   466,   469,     0,   472,
       0,   336,   327,   331,   334,   332,   333,   257,  1072,  1087,
       0,     0,  1028,  1022,  1025,  1026,   511,   535,     0,     0,
    1133,  1133,     0,   421,     0,  1060,   413,   410,   418,   419,
     416,  1057,  1058,  1059,   417,   415,   414,     0,   479,   470,
     474,   477,   475,   476,   335,  1133,  1027,  1034,     0,  1030,
    1031,  1036,   537,   544,     0,     0,   512,   513,   516,   515,
     517,  1133,   508,   507,   425,   424,   420,     0,   423,  1133,
     478,  1101,  1029,  1032,     0,  1035,   546,   707,   547,     0,
     541,   536,   538,   539,     0,   521,   510,   518,   519,   514,
     506,   422,  1061,     0,  1045,  1033,  1042,  1043,  1133,  1037,
    1039,  1040,  1038,  1041,   709,   846,   710,  1133,     0,   548,
     543,   540,     0,   520,   527,     0,   523,   524,   529,     0,
    1053,  1054,  1044,     0,  1047,  1048,  1050,  1051,  1052,     0,
     848,   985,   849,  1133,     0,   711,     0,   554,   551,   545,
     549,   550,   542,   522,   525,     0,   528,  1056,     0,  1046,
    1049,  1133,   987,     0,     0,  1133,     0,   850,     0,   717,
     714,   708,   712,   713,  1133,   556,     0,   573,     0,     0,
     534,   526,   530,   532,   531,  1055,  1092,   509,  1133,     0,
     988,     0,   856,   853,   847,   851,   852,  1133,   719,     0,
     736,     0,  1099,   552,   575,   597,     0,  1133,     0,   557,
     533,     0,     0,   992,   986,   989,   990,  1133,   858,     0,
     875,     0,  1096,   715,   738,   798,     0,  1133,     0,   720,
     599,   659,     0,     0,   576,     0,     0,   561,   555,   558,
     559,  1133,   998,   991,     0,   994,   995,  1000,  1095,   854,
     877,   937,     0,  1133,     0,   859,   716,   744,   741,   737,
     739,   740,     0,     0,   724,   718,   721,   722,   553,   605,
     602,   598,   600,   601,     0,   580,   574,   577,   578,  1133,
     560,   567,     0,   563,   564,   568,  1098,   993,   996,     0,
     999,   855,   883,   880,   876,   878,   879,     0,     0,   863,
     857,   860,   861,   801,   799,   803,   746,     0,   753,     0,
    1133,   730,   723,     0,   726,   727,   731,   662,   660,   664,
     607,     0,   614,     0,   579,   586,     0,   582,   583,   587,
    1104,   562,   565,     0,     0,  1009,   997,  1006,  1007,  1001,
    1003,  1004,  1002,  1005,   940,   938,   942,   885,     0,   892,
       0,  1133,   869,   862,     0,   865,   866,   870,     0,   802,
     742,   755,   762,     0,  1133,     0,   747,  1093,   725,   728,
       0,     0,   663,   603,   616,   623,     0,     0,   608,   581,
     584,     0,     0,  1133,   569,   566,   570,   571,     0,  1017,
    1018,  1008,     0,  1011,  1012,  1014,  1015,  1016,     0,   941,
     881,   894,   901,     0,     0,   886,  1088,   864,   867,     0,
       0,   813,   800,   810,   811,  1133,   804,   809,   808,   807,
     806,   805,   764,   771,     0,     0,   756,     0,  1108,   750,
     745,   748,   749,     0,   732,   729,   733,   734,     0,   674,
     661,   671,   672,   665,   670,   669,   668,   667,   666,   625,
     632,     0,     0,   617,  1108,   611,   606,   609,   610,     0,
     594,   588,   585,   591,   592,   589,   590,     0,     0,  1020,
       0,  1010,  1013,     0,   952,   939,   949,   950,   943,   948,
     947,   946,   944,   945,   903,   910,     0,     0,   895,  1108,
     889,   884,   887,   888,     0,   871,   868,   872,   873,   834,
     820,   812,     0,   815,   817,   821,   816,   831,   836,     0,
     773,   780,     0,     0,   765,  1108,   759,   754,   757,   758,
    1133,     0,     0,   752,  1106,  1107,     0,   695,   673,   681,
       0,   676,   678,   682,   677,   692,   697,   634,   641,     0,
       0,   626,  1108,   620,   615,   618,   619,     0,   613,   596,
     593,     0,   572,  1133,  1019,   959,   973,   951,     0,   954,
     956,   960,   955,   970,   975,   912,   919,     0,     0,   904,
    1108,   898,   893,   896,   897,     0,   891,     0,   814,   818,
       0,   832,     0,   835,  1133,   782,   789,     0,     0,   774,
    1108,   768,   763,   766,   767,     0,   761,  1090,  1133,     0,
     751,  1111,  1109,  1113,   735,   675,   679,     0,   693,     0,
     696,   643,   650,     0,     0,   635,  1108,   629,   624,   627,
     628,     0,   622,   612,   595,  1067,   953,   957,     0,   971,
       0,   974,   921,   928,     0,     0,   913,  1108,   907,   902,
     905,   906,     0,   900,   890,   874,     0,   828,   822,   819,
     825,   826,   823,   824,  1108,   843,   833,   841,   842,   837,
     840,   839,   838,  1091,   791,   743,     0,     0,   783,  1108,
     777,   772,   775,   776,     0,   770,   760,     0,     0,  1123,
    1118,  1120,  1121,     0,  1112,     0,   689,   683,   680,   686,
     687,   684,   685,  1108,   704,   694,   702,   703,   698,   701,
     700,   699,   652,   604,     0,     0,   644,  1108,   638,   633,
     636,   637,     0,   631,   621,     0,   967,   961,   958,   964,
     965,   962,   963,  1108,   982,   972,   980,   981,   976,   979,
     978,   977,   930,   882,     0,     0,   922,  1108,   916,   911,
     914,   915,     0,   909,   899,  1129,  1130,  1131,   827,     0,
     830,     0,   845,     0,   792,  1108,   786,   781,   784,   785,
       0,   779,   769,  1133,     0,  1122,     0,  1110,  1133,  1133,
    1114,  1116,  1115,   688,     0,   691,     0,   706,     0,   653,
    1108,   647,   642,   645,   646,     0,   640,   630,   966,     0,
     969,     0,   984,     0,   931,  1108,   925,   920,   923,   924,
       0,   918,   908,   829,   844,  1108,   795,   790,   793,   794,
       0,   788,   778,  1119,  1124,     0,     0,     0,   690,   705,
    1108,   656,   651,   654,   655,     0,   649,   639,   968,   983,
    1108,   934,   929,   932,   933,     0,   927,   917,     0,   797,
     787,  1117,  1133,  1133,     0,   658,   648,     0,   936,   926,
     796,  1125,  1126,   657,   935
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
     703,   702,    95,    96,   195,   196,   197,   297,   298,   299,
     300,   301,   437,   438,   439,   535,   302,   303,   442,   443,
     444,   538,   304,   305,   447,   448,   449,   541,   306,   307,
     452,   453,   454,   544,   308,   309,   457,   458,   459,   547,
     310,   311,   461,   551,   552,   553,   639,   640,   641,   642,
     691,   726,   727,   728,   729,   767,   768,   312,   313,   463,
     464,   556,   555,   643,   314,   315,   465,   466,   561,   560,
     645,   316,   317,   467,   468,   566,   565,   647,   318,   319,
     469,   570,   650,   320,   321,   471,   573,   574,   575,   653,
     654,   655,   656,   698,   699,   740,   739,   191,   192,   283,
     284,   428,   421,   422,   423,   525,   526,   527,   528,   625,
     626,   680,   681,   682,   683,   676,   717,   718,   755,   756,
     757,   786,   787,   788,   815,   816,   817,   818,   845,   846,
     872,   871,   753,   754,   781,   782,   783,   812,   777,   778,
     808,   839,   840,   841,   866,   867,   868,   898,   928,   929,
     930,   972,   973,   974,   975,  1023,  1074,  1075,   895,   896,
     923,   966,   967,   968,  1016,  1017,  1018,  1019,  1071,  1151,
    1152,  1153,  1154,  1241,   921,   922,   961,   962,   963,  1011,
    1012,  1013,  1067,  1146,  1147,  1148,  1237,  1065,  1066,  1142,
    1234,  1235,  1236,  1311,  1140,  1141,  1230,  1308,  1309,  1310,
    1402,  1228,  1229,  1304,  1399,  1400,  1401,  1475,  1302,  1303,
    1395,  1472,  1473,  1474,  1515,  1393,  1394,  1468,  1512,  1513,
    1514,  1534,   958,  1008,  1009,  1061,  1062,  1133,  1130,  1131,
    1132,  1220,  1221,  1222,  1223,  1297,  1377,  1378,  1379,  1380,
    1464,  1224,  1225,  1226,  1299,  1300,  1388,  1385,  1386,  1387,
    1466,   805,   806,   834,   861,   862,   863,   889,   890,   891,
     918,   955,   956,   957,  1003,  1004,  1005,  1006,  1060,  1124,
    1125,   915,   916,   949,   950,   951,   997,   998,   999,  1055,
    1120,  1121,  1122,  1212,  1052,  1053,  1115,  1207,  1208,  1209,
    1285,  1113,  1114,  1203,  1282,  1283,  1284,  1364,  1201,  1202,
    1278,  1361,  1362,  1363,  1450,  1276,  1277,  1357,  1447,  1448,
    1449,  1500,  1355,  1356,  1443,  1497,  1498,  1499,  1528,   946,
     994,   995,  1048,  1049,  1106,  1102,  1103,  1104,  1192,  1193,
    1194,  1195,  1270,  1338,  1339,  1340,  1341,  1439,  1196,  1197,
    1198,  1272,  1273,  1349,  1346,  1347,  1348,  1441,   831,   832,
     856,   884,   885,   886,   909,   910,   911,   944,   990,   991,
     992,  1044,  1045,  1046,  1047,  1099,  1185,  1186,   941,   942,
     984,   985,   986,  1038,  1039,  1040,  1094,  1181,  1182,  1183,
    1265,  1092,  1093,  1177,  1262,  1263,  1264,  1332,  1175,  1176,
    1258,  1329,  1330,  1331,  1432,  1256,  1257,  1325,  1429,  1430,
    1431,  1490,  1323,  1324,  1425,  1487,  1488,  1489,  1525,  1423,
    1424,  1483,  1522,  1523,  1524,  1537,   981,  1035,  1036,  1088,
    1089,  1168,  1165,  1166,  1167,  1248,  1249,  1250,  1251,  1318,
    1407,  1408,  1409,  1410,  1479,  1252,  1253,  1254,  1320,  1321,
    1418,  1415,  1416,  1417,  1481,   853,   854,   879,   904,   905,
     906,   934,   935,   936,   937,   979,   980,  1029,  1026,  1027,
    1028,  1082,  1083,  1084,  1085,  1086,  1087,  1160,   623,   624,
     673,   713,   714,   715,   748,   749,   750,   751,   774,   775,
     799,   795,   796,   797,   823,   824,   825,   826,   827,   828,
     848,   730,   731,   732,   733,   134,   135,   136,   137,  1076,
     603,   604,   605,   606,   138,   139,   140,   141,   360,   361,
     362,   363,   615,   616,   617,   618,   945,   429,  1056,  1110,
     803,   919,   430,   857,   835,   180,   880,   809,   431,   674,
     142,   462,   899,   432,  1213,  1214,  1292,  1293,  1373,  1374,
    1460,  1457,  1215,  1289,  1370,  1371,  1372,  1461,  1462,   489,
    1440,   237,   238,   387
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1311
static const yytype_int16 yypact[] =
{
      81, -1311, -1311,   124,    47,   114, -1311, -1311,   117,    75,
     163, -1311,   319, -1311, -1311, -1311,    82,   376,     2, -1311,
   -1311, -1311, -1311,    47, -1311, -1311, -1311, -1311, -1311,    73,
     401,   146, -1311, -1311, -1311, -1311,   178, -1311, -1311,   102,
      67, -1311, -1311, -1311,   117, -1311,   120,   428,    -3, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,   127,   171, -1311, -1311,   423, -1311,   435,
   -1311,   445, -1311,   458, -1311,   464, -1311,   471, -1311,   473,
   -1311,   477, -1311,   167,   139, -1311,   222, -1311, -1311,    74,
   -1311, -1311, -1311, -1311, -1311,   169,   479,    69, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,   170,
     187, -1311, -1311,   485, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311,   397, -1311,   167, -1311, -1311, -1311,   252, -1311,   256,
   -1311,   487,   423, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,    31, -1311, -1311, -1311, -1311,    29, -1311,
   -1311, -1311, -1311,    33, -1311, -1311, -1311, -1311,    38, -1311,
   -1311, -1311, -1311,    39, -1311, -1311, -1311, -1311,    18, -1311,
   -1311, -1311, -1311,     9, -1311, -1311, -1311, -1311, -1311,   491,
   -1311, -1311,   188,   273, -1311, -1311,   155, -1311, -1311, -1311,
   -1311, -1311, -1311,   -37, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311,   221,   110, -1311, -1311,   493,
   -1311,   495, -1311,   499, -1311,   501, -1311,   503, -1311,   167,
   -1311, -1311,    26, -1311, -1311, -1311, -1311,   281,   213,   285,
     213,   300,   213,   307, -1311,   505, -1311,   329,     0, -1311,
   -1311,   -74, -1311, -1311, -1311, -1311, -1311, -1311, -1311,   181,
   -1311, -1311,   180, -1311, -1311,   191, -1311, -1311,   227, -1311,
   -1311,   237, -1311, -1311,   195, -1311, -1311,   190,   387,    88,
   -1311, -1311, -1311, -1311, -1311,   313,   399, -1311, -1311,   184,
   -1311, -1311, -1311,   507,   430, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311,   367,   -40, -1311,
   -1311,   509, -1311,   511, -1311,   513, -1311,   515, -1311,   517,
   -1311,   412, -1311, -1311, -1311, -1311, -1311, -1311, -1311,   397,
   -1311,   167, -1311, -1311,    45, -1311, -1311, -1311, -1311,    51,
   -1311, -1311, -1311, -1311,    15, -1311, -1311, -1311, -1311,    20,
   -1311, -1311, -1311, -1311,    25, -1311, -1311, -1311, -1311,   519,
   -1311, -1311, -1311,   262,   525, -1311,   454, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311,   525, -1311, -1311, -1311, -1311,   525,
   -1311, -1311, -1311, -1311,   455, -1311,   140, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311,   331,   291, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311,   336,   380, -1311, -1311,
   -1311,   421,   530, -1311, -1311, -1311, -1311, -1311, -1311,   -17,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311,    24, -1311, -1311, -1311, -1311,
      14, -1311, -1311, -1311, -1311,    41, -1311, -1311, -1311, -1311,
      44, -1311, -1311, -1311, -1311,    42, -1311, -1311, -1311, -1311,
   -1311,   526, -1311,   534,   213,   536,   213,   563,   213,   569,
   -1311,   528, -1311, -1311, -1311,   418, -1311, -1311,   478, -1311,
   -1311,   440, -1311, -1311,   475, -1311, -1311, -1311,   484, -1311,
     147, -1311, -1311, -1311, -1311, -1311,   562, -1311, -1311,   561,
   -1311,   566, -1311, -1311,   570, -1311, -1311,   516,   518, -1311,
   -1311, -1311, -1311, -1311,   538,    76, -1311, -1311, -1311,   540,
     434, -1311,   585, -1311, -1311,   601,   -87, -1311, -1311,   668,
     670,   672,   673, -1311, -1311,   502, -1311, -1311,   508, -1311,
   -1311,   521, -1311, -1311,   587, -1311, -1311,   552,   677,  -104,
   -1311, -1311, -1311, -1311,   525, -1311, -1311, -1311, -1311,   525,
   -1311, -1311, -1311, -1311,   525, -1311, -1311, -1311, -1311,   681,
   -1311,   153, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,   533,   537, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311,   542,   434,   510, -1311, -1311,   688,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311,   539, -1311, -1311,
     691, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311,   665,   686,   197, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,   504,
     512, -1311, -1311,   497, -1311,   496, -1311,   506, -1311, -1311,
     514, -1311, -1311,   541,   550, -1311, -1311, -1311, -1311,   544,
     434,   556, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,   547, -1311,   527, -1311, -1311,   702,   703,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311,   311, -1311, -1311, -1311, -1311, -1311, -1311,   549,   434,
     559, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
     701,   -89, -1311, -1311, -1311, -1311, -1311,   572,   423,   706,
   -1311, -1311,    19, -1311,   713, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311,   564, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,   568,   545,
   -1311, -1311, -1311,   520,   551,   553,   423, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311,   529, -1311, -1311,
   -1311, -1311, -1311, -1311,   555,   386, -1311,   574,   695,    35,
   -1311, -1311, -1311, -1311,   165, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,    10, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311,   607,   700, -1311,   558, -1311,
   -1311, -1311,   591, -1311, -1311,   548,   557, -1311, -1311,   723,
   -1311, -1311, -1311,   573,   348, -1311, -1311, -1311, -1311,   725,
   -1311,   578,   710, -1311,   560, -1311,   730,   535, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311,   565,   280, -1311,   671, -1311,
   -1311, -1311, -1311,   576,   716, -1311,   567, -1311,   734,   543,
   -1311, -1311, -1311, -1311, -1311, -1311,   531,   554,   711,   580,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,   571,
   -1311,   740,   629, -1311, -1311, -1311, -1311, -1311, -1311,   599,
     640,   732, -1311, -1311, -1311,   645,   711, -1311,   575, -1311,
   -1311,   751,   218, -1311, -1311, -1311, -1311, -1311, -1311,   641,
     650,   742, -1311, -1311, -1311, -1311,   577, -1311,   579, -1311,
   -1311, -1311,   582,   584, -1311,   754,   172, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311,   609,   610, -1311, -1311, -1311, -1311,
   -1311, -1311,   586, -1311,   590, -1311,   618,   655, -1311, -1311,
   -1311, -1311,   760,   -91, -1311, -1311, -1311, -1311,   619,   659,
   -1311, -1311, -1311, -1311,   392, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311,   581,   583, -1311, -1311, -1311, -1311, -1311,   594,
     386,   621,   661, -1311, -1311, -1311, -1311,   769,     1, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311,   664,   682,   761,
   -1311, -1311, -1311,   588,   633, -1311, -1311, -1311, -1311, -1311,
   -1311,   669,   685,   761, -1311, -1311,   589,   593, -1311, -1311,
   -1311, -1311, -1311,   104,    58, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,   674,   689,
     761, -1311, -1311, -1311,   663,   675, -1311, -1311,   596,   370,
   -1311, -1311,   696,   761, -1311,   598, -1311, -1311, -1311, -1311,
     224,   600,   391, -1311, -1311,   698,   761,   602, -1311, -1311,
   -1311,   353,   525, -1311, -1311, -1311, -1311, -1311,   778, -1311,
   -1311, -1311,   627,   354, -1311, -1311, -1311, -1311,   604,   288,
   -1311, -1311,   704,   761,   606, -1311, -1311, -1311, -1311,   235,
     -57, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,   658,   761,   608, -1311,   782,   693, -1311,
   -1311, -1311, -1311,   525, -1311, -1311, -1311, -1311,   -42, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
     666,   761,   611, -1311,   693, -1311, -1311, -1311, -1311,    16,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311,   595,   786, -1311,
     728, -1311, -1311,   -63, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311,   667,   761,   613, -1311,   693,
   -1311, -1311, -1311, -1311,   525, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311,   648,   676, -1311, -1311,   683, -1311, -1311,   802,
   -1311,   626,   761,   615, -1311,   693, -1311, -1311, -1311, -1311,
   -1311,   771,   705, -1311,   687, -1311,   678, -1311, -1311, -1311,
     660,   605, -1311, -1311,   690, -1311, -1311, -1311,   635,   761,
     617, -1311,   693, -1311, -1311, -1311, -1311,   709, -1311, -1311,
   -1311,   614, -1311, -1311, -1311, -1311, -1311, -1311,   679,   708,
   -1311, -1311,   712, -1311, -1311, -1311,   637,   761,   620, -1311,
     693, -1311, -1311, -1311, -1311,   715, -1311,   697, -1311, -1311,
     357, -1311,   622,   333, -1311, -1311,   631,   761,   624, -1311,
     693, -1311, -1311, -1311, -1311,   731, -1311, -1311, -1311,   628,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311,   360, -1311,   630,
     333, -1311,   639,   761,   632, -1311,   693, -1311, -1311, -1311,
   -1311,   733, -1311, -1311, -1311, -1311, -1311, -1311,   363, -1311,
     634,   333, -1311,   643,   761,   636, -1311,   693, -1311, -1311,
   -1311, -1311,   735, -1311, -1311, -1311,    34, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311,   693, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311,   761,   638, -1311,   693,
   -1311, -1311, -1311, -1311,   737, -1311, -1311,   824,    40, -1311,
   -1311, -1311, -1311,   822,   612,     5, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,   693, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311,   761,   642, -1311,   693, -1311, -1311,
   -1311, -1311,   739, -1311, -1311,    62, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,   693, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311,   761,   647, -1311,   693, -1311, -1311,
   -1311, -1311,   743, -1311, -1311, -1311, -1311, -1311, -1311,   692,
   -1311,   714, -1311,   649, -1311,   693, -1311, -1311, -1311, -1311,
     707, -1311, -1311, -1311,   736, -1311,   837, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311,   644, -1311,   717, -1311,   651, -1311,
     693, -1311, -1311, -1311, -1311,   718, -1311, -1311, -1311,   738,
   -1311,   720, -1311,   653, -1311,   693, -1311, -1311, -1311, -1311,
     719, -1311, -1311, -1311, -1311,   693, -1311, -1311, -1311, -1311,
     662, -1311, -1311, -1311, -1311,   724,   843,   845, -1311, -1311,
     693, -1311, -1311, -1311, -1311,   680, -1311, -1311, -1311, -1311,
     693, -1311, -1311, -1311, -1311,   684, -1311, -1311,   654, -1311,
   -1311, -1311, -1311, -1311,   657, -1311, -1311,   694, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,   809,   834,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,   796, -1311, -1311, -1311, -1311,   741, -1311,
   -1311, -1311, -1311, -1311,   469, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
     459, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,   755, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311,   359, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311,   699, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311,   286, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,   592,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,   229, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311,   217, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311,   346, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
     118, -1311, -1311, -1311, -1311, -1311,    59, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,   -96, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311,  -139, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,  -342, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311,  -344, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311,  -123, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
    -311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,  -313,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,  -161, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311,  -364, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311,  -366, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,   -48, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,  -195, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311,   142, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311,    65, -1311, -1311, -1311,
   -1311,  -758, -1311, -1311, -1311,  -119, -1311, -1311, -1311, -1044,
    -515, -1311, -1311, -1311,  -655, -1311, -1311, -1311,  -229, -1311,
   -1311, -1311,  -589, -1311, -1311, -1311,  -196, -1311, -1006,  -990,
     -86,  -153, -1311, -1311, -1311,  -113, -1311, -1311, -1311, -1311,
    -651, -1311,  -873, -1311, -1129, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,  -350,
   -1310,  -178, -1311, -1311
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     268,   368,   234,   373,   497,   614,   667,  1068,   382,  1435,
     236,  1436,  1437,   265,   500,  1238,  1126,   800,   536,   502,
    1239,   479,   262,   924,   482,   764,   765,  1155,   533,   285,
     351,   485,   486,   250,  1095,   247,   735,   253,  1435,   810,
    1436,  1437,   256,   259,  1454,   539,   545,  1116,   542,   473,
    1266,   523,  1245,   286,  1001,  1187,   286,   476,   390,   102,
    1143,   388,   389,   759,  1246,  1465,  1435,   760,  1436,  1437,
    1189,   706,  1137,   746,   621,    36,  1286,    37,    38,   819,
     666,   820,   821,   637,   524,  1217,   747,  1178,  1190,   287,
     638,  1247,   287,     1,     2,  1480,   103,  1191,   104,  1173,
     105,   759,   106,  1312,     7,   760,   350,   391,  1204,   359,
     743,   367,  1218,   372,  1072,   288,  1042,  1002,   288,   127,
     128,   599,   600,   289,     6,  1043,   289,  1078,    11,  1079,
    1080,  1333,    13,   198,    15,  1231,    45,   290,   543,   291,
     290,  1073,   291,    28,    86,   705,    87,    88,  1455,   599,
     600,  1365,   107,   292,   524,   183,   292,   184,   185,   293,
      85,   294,   293,   295,   294,   296,   295,   474,   296,  1219,
    1259,   477,   546,    18,    19,   248,   257,  1403,  1478,   811,
    1438,   260,   108,    84,   742,    94,   822,   124,   199,  1138,
     200,   874,   263,   178,   537,   487,  1279,   251,  1433,   254,
     470,   266,   534,   511,   644,   540,    53,   766,   472,   646,
     483,   480,   352,   181,   648,  1442,  1081,  1463,   383,   384,
     385,   386,  1030,  1305,   201,   516,  1342,   182,  1240,   199,
    1451,   200,   220,   677,  1123,   558,   190,   563,   202,   568,
     276,   404,   277,   278,   405,  1184,   529,   530,   531,   532,
     678,  1326,   679,  1381,  1467,   239,   127,   128,   203,   240,
     802,  1073,   356,   357,   204,   201,   274,  1352,  1476,   599,
     600,  1358,  1073,   412,  1411,   413,   414,    54,   275,   202,
     599,   600,   548,    55,  1482,   322,   103,    56,   104,    57,
     105,   354,   106,   505,  1391,   364,   506,  1396,  1491,   203,
     581,    58,    54,   582,   943,   204,   651,  1105,    55,   652,
     369,    59,    56,    60,    57,  1421,  1501,   374,  1426,    61,
     588,   722,   723,   127,   128,   396,    58,   129,   130,    23,
      24,   127,   128,   599,   600,   381,    59,    62,    60,   610,
     611,  1516,   107,   813,    61,   557,   814,   562,   397,   567,
    1444,  1054,   724,   725,   127,   128,  1526,   398,   129,   130,
     356,   357,    62,  1149,  1150,   399,  1529,  1336,  1337,   401,
    1375,  1376,   108,  1405,  1406,   932,   127,   128,   933,   400,
     970,  1535,   402,   971,   610,   611,    31,    32,  1469,  1105,
    1073,  1538,   917,   403,  1073,   410,   602,  1073,   599,   600,
    1073,   613,   599,   600,   411,   599,   600,   798,   599,   600,
    1105,    48,    49,   127,   128,   599,   600,   819,  1484,   820,
     821,   610,   611,  1078,   897,  1079,  1080,   724,   725,   127,
     128,   599,   600,   433,   127,   128,   599,   600,    97,    98,
     127,   128,   610,   611,   460,   143,   144,   424,   495,   684,
     685,   686,   687,   425,   126,   148,   149,   498,   688,   426,
    1109,   503,   736,   512,   427,  1032,   127,   128,   153,   154,
     129,   130,   391,  1136,   158,   159,   665,   127,   128,   599,
     600,   163,   164,   168,   169,   610,   611,   173,   174,   193,
     194,   708,   517,   709,   710,   222,   223,   241,   242,   719,
    1171,   269,   270,   324,   325,   329,   330,   521,  1077,   334,
     335,   339,   340,   344,   345,   376,   377,   419,   420,   435,
     436,   440,   441,   445,   446,   450,   451,   455,   456,   490,
     491,   485,   486,   404,  1108,   522,   549,   550,   571,   572,
     576,   704,   762,   763,   554,  1127,   559,  1135,   596,   597,
     607,   608,   661,   662,   700,   701,  1156,   711,   712,   737,
     738,   779,   780,   784,   785,   793,   794,   771,   837,   838,
     859,   860,   734,   564,  1170,   869,   870,   882,   883,   569,
     741,   902,   903,   790,  1188,   926,   927,   947,   948,   953,
     954,   792,   959,   960,   964,   965,   982,   983,   577,   758,
     988,   989,  1014,  1015,  1024,  1025,  1100,  1101,  1118,  1119,
    1128,  1129,  1144,  1145,  1163,  1164,  1179,  1180,  1205,  1206,
     829,  1232,  1233,  1260,  1261,  1280,  1281,  1306,  1307,   836,
    1327,  1328,  1344,  1345,  1359,  1360,   578,   758,  1368,  1369,
    1383,  1384,  1397,  1398,  1413,  1414,  1427,  1428,  1445,  1446,
    1458,  1459,  1470,  1471,   580,   858,   801,  1485,  1486,  1495,
    1496,  1510,  1511,  1520,  1521,   579,   587,   589,   590,   620,
     591,   505,   592,   876,   627,   619,   628,   881,   629,   630,
     631,   634,   635,   636,  1351,   633,   892,   649,   632,   657,
     581,   669,   668,   670,   671,   672,   675,   696,   689,   637,
     901,   692,   693,   651,   716,   720,   721,   745,   694,   912,
     707,  1390,   761,   744,   695,   752,   769,   791,   770,   925,
     747,   804,  1157,   807,   830,   833,   843,   873,   847,   938,
     772,   851,  1420,   776,   855,   842,   864,   852,   814,   952,
     887,   875,   865,   878,   897,   893,   907,   913,   877,   849,
     888,   914,   908,   976,   917,  1343,   920,   931,   943,   939,
     969,   940,   900,   894,   996,   987,  1000,   932,  1010,   977,
    1037,   993,  1007,  1216,  1034,  1041,  1050,  1051,  1001,  1054,
    1064,  1063,  1382,  1159,  1091,  1161,  1090,  1097,  1210,  1021,
    1042,  1020,  1243,  1112,   971,  1139,  1058,  1200,  1244,  1069,
    1211,  1174,  1268,  1412,  1015,  1227,  1255,  1242,  1274,  1275,
    1189,  1288,  1291,  1335,  1295,  1290,  1219,  1217,  1301,  1313,
    1322,  1190,  1057,  1245,  1294,  1334,  1314,  1366,  1354,  1404,
    1453,  1434,  1456,  1316,  1267,  1452,  1392,  1477,  1493,  1246,
    1422,  1492,  1494,  1505,  1504,  1509,  1530,  1502,  1519,  1532,
    1531,  1533,  1540,    93,  1518,  1543,  1508,    44,  1517,  1527,
     125,  1031,   513,  1096,  1536,   221,   518,   593,  1539,   690,
     658,   697,   622,   246,   789,   844,  1117,  1022,  1070,  1296,
    1298,  1059,  1269,  1271,  1098,  1317,  1319,   978,  1162,   850,
     434,   773,  1544,  1172,  1033,  1158,  1111,     0,     0,     0,
       0,     0,     0,     0,     0,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1199,     0,     0,
    1107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1287,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1315,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1353,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1367,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1350,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1389,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1419,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1503,     0,     0,     0,     0,
    1506,  1507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1541,  1542
};

static const yytype_int16 yycheck[] =
{
     178,   230,   121,   232,   354,   520,   595,  1013,     8,     4,
     123,     6,     7,     4,   364,  1144,  1060,   775,     4,   369,
       4,     6,     4,   896,     4,     6,     7,  1071,     4,    66,
       4,     6,     7,     4,  1040,     4,   691,     4,     4,     4,
       6,     7,     4,     4,     4,     4,     4,  1053,     4,     4,
    1179,    68,   115,    93,   145,  1099,    93,     6,   132,    62,
    1066,   239,   240,   718,   127,  1375,     4,   718,     6,     7,
     127,   660,  1062,   162,   161,    73,  1205,    75,    76,    69,
     595,    71,    72,   187,   171,   127,   175,  1093,   145,   129,
     194,   154,   129,    12,    13,  1405,    99,   154,   101,  1089,
     103,   756,   105,  1232,    57,   756,   219,   181,  1114,   228,
     699,   230,   154,   232,    10,   155,   115,   208,   155,    43,
      44,    45,    46,   163,     0,   124,   163,    69,    14,    71,
      72,  1260,    15,    64,    59,  1141,    63,   177,    94,   179,
     177,    37,   179,    61,    77,   660,    79,    80,   108,    45,
      46,  1280,   155,   193,   171,    81,   193,    83,    84,   199,
      58,   201,   199,   203,   201,   205,   203,   122,   205,   211,
    1176,   120,   130,    10,    11,   144,   138,  1306,   116,   144,
     146,   142,   185,     5,   699,    65,   176,    60,   119,  1062,
     121,   846,   174,    26,   180,   170,  1202,   168,  1327,   166,
     319,   192,   178,   381,   554,   164,    60,   188,   321,   559,
     190,   196,   186,    74,   564,  1344,   158,   212,   218,   219,
     220,   221,   980,  1229,   155,   403,  1270,     5,   212,   119,
    1359,   121,    62,    36,    10,   464,    67,   466,   169,   468,
      85,   153,    87,    88,   156,    10,   424,   425,   426,   427,
      53,  1257,    55,  1297,  1383,     3,    43,    44,   189,     3,
     775,    37,    49,    50,   195,   155,    78,  1273,  1397,    45,
      46,  1277,    37,    89,  1318,    91,    92,   131,     5,   169,
      45,    46,   460,   137,  1413,    64,    99,   141,   101,   143,
     103,    10,   105,   153,  1300,    10,   156,  1303,  1427,   189,
     153,   155,   131,   156,    16,   195,   153,    19,   137,   156,
      10,   165,   141,   167,   143,  1321,  1445,    10,  1324,   173,
     498,    10,    11,    43,    44,   144,   155,    47,    48,    10,
      11,    43,    44,    45,    46,     6,   165,   191,   167,    51,
      52,  1470,   155,   178,   173,   464,   181,   466,   168,   468,
    1356,    18,    41,    42,    43,    44,  1485,   166,    47,    48,
      49,    50,   191,    10,    11,   138,  1495,    10,    11,   174,
      10,    11,   185,    10,    11,   157,    43,    44,   160,   142,
     208,  1510,   192,   211,    51,    52,    10,    11,  1394,    19,
      37,  1520,    22,     6,    37,    82,   515,    37,    45,    46,
      37,   520,    45,    46,     5,    45,    46,    21,    45,    46,
      19,    10,    11,    43,    44,    45,    46,    69,  1424,    71,
      72,    51,    52,    69,    33,    71,    72,    41,    42,    43,
      44,    45,    46,    66,    43,    44,    45,    46,    10,    11,
      43,    44,    51,    52,    32,    10,    11,    17,   186,   627,
     628,   629,   630,    23,    31,    10,    11,     3,   636,    29,
    1049,     6,   691,   132,    34,   980,    43,    44,    10,    11,
      47,    48,   181,  1062,    10,    11,   595,    43,    44,    45,
      46,    10,    11,    10,    11,    51,    52,    10,    11,    10,
      11,   669,   156,   671,   672,    10,    11,    10,    11,   677,
    1089,    10,    11,    10,    11,    10,    11,    86,  1023,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,     6,     7,   153,  1049,     5,    10,    11,    10,    11,
     122,   660,   720,   721,    10,  1060,    10,  1062,    10,    11,
      10,    11,    10,    11,    10,    11,  1071,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,   745,    10,    11,
      10,    11,   691,    10,  1089,    10,    11,    10,    11,    10,
     699,    10,    11,   761,  1099,    10,    11,    10,    11,    10,
      11,   769,    10,    11,    10,    11,    10,    11,   120,   718,
      10,    11,   210,   211,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     798,    10,    11,    10,    11,    10,    11,    10,    11,   807,
      10,    11,    10,    11,    10,    11,   196,   756,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      38,    39,    10,    11,   170,   833,   775,    10,    11,    10,
      11,    10,    11,    10,    11,   190,   104,   106,   102,    68,
     100,   153,   156,   851,     6,    90,     6,   855,     6,     6,
     178,    94,   130,     6,  1273,   164,   864,     6,   180,   156,
     153,     3,   182,   154,     3,    30,    10,   156,   194,   187,
     878,   204,   206,   153,   177,     3,     3,     6,   202,   887,
     154,  1300,     6,   154,   200,   143,     3,   188,   154,   897,
     175,   147,  1072,    28,   117,    25,   178,   846,     5,   907,
     162,     6,  1321,   213,    24,   144,     6,   159,   181,   917,
       6,    70,   207,    27,    33,   214,     6,   148,   172,   176,
     207,   111,   123,   931,    22,  1270,   111,     6,    16,   118,
       6,   111,   182,   209,   109,   943,     6,   157,   109,   160,
     109,   153,   153,  1123,   153,     6,   112,    95,   145,    18,
      95,   112,  1297,     5,    95,   158,   112,   124,     6,   208,
     115,   969,     6,    97,   211,    97,   208,   139,    70,   210,
     107,    97,   154,  1318,   211,   139,   139,   212,     6,   183,
     127,    40,   125,   116,   154,   110,   211,   127,   183,   110,
     183,   145,  1000,   115,   146,   110,   212,    96,   197,    96,
       6,    96,    10,   154,  1184,    98,   197,    98,   146,   127,
     197,    98,   128,     6,   108,   128,   184,   140,   128,     6,
     126,     6,   198,    44,   116,   198,   212,    23,   140,   140,
      64,   980,   393,  1041,   184,   110,   407,   508,   184,   640,
     584,   654,   526,   132,   756,   816,  1054,   973,  1017,  1221,
    1224,  1004,  1193,  1196,  1045,  1249,  1252,   935,  1083,   824,
     298,   749,   198,  1089,   980,  1073,  1049,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1105,    -1,    -1,
    1049,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1062,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1089,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1453,    -1,    -1,    -1,    -1,
    1458,  1459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1532,  1533
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   223,   224,   225,     0,    57,   231,   232,
     233,    14,   226,    15,   230,    59,   258,   259,    10,    11,
     234,   235,   236,    10,    11,   227,   228,   229,    61,   338,
     339,    10,    11,   260,   261,   262,    73,    75,    76,   237,
     238,   239,   240,   241,   231,    63,   392,   393,    10,    11,
     340,   341,   342,    60,   131,   137,   141,   143,   155,   165,
     167,   173,   191,   263,   264,   265,   266,   267,   282,   283,
     288,   289,   294,   295,   300,   301,   306,   307,   312,   313,
     318,   319,   324,   325,     5,    58,    77,    79,    80,   242,
     243,   244,   245,   230,    65,   444,   445,    10,    11,   394,
     395,   396,    62,    99,   101,   103,   105,   155,   185,   343,
     344,   345,   346,   347,   352,   353,   359,   360,   366,   367,
     373,   374,   378,   379,    60,   265,    31,    43,    44,    47,
      48,   268,   269,   270,   937,   938,   939,   940,   946,   947,
     948,   949,   972,    10,    11,   284,   285,   286,    10,    11,
     290,   291,   292,    10,    11,   296,   297,   298,    10,    11,
     302,   303,   304,    10,    11,   308,   309,   310,    10,    11,
     314,   315,   316,    10,    11,   320,   321,   322,    26,   326,
     967,    74,     5,    81,    83,    84,   246,   247,   248,   249,
      67,   539,   540,    10,    11,   446,   447,   448,    64,   119,
     121,   155,   169,   189,   195,   397,   398,   399,   400,   401,
     406,   407,   412,   413,   418,   419,   424,   425,   430,   431,
      62,   345,    10,    11,   348,   349,   350,   354,   355,   361,
     362,   368,   369,   375,   937,   380,   967,   993,   994,     3,
       3,    10,    11,   271,   272,   273,   270,     4,   144,   287,
       4,   168,   293,     4,   166,   299,     4,   138,   305,     4,
     142,   311,     4,   174,   317,     4,   192,   323,   993,    10,
      11,   327,   328,   329,    78,     5,    85,    87,    88,   250,
     251,   252,   253,   541,   542,    66,    93,   129,   155,   163,
     177,   179,   193,   199,   201,   203,   205,   449,   450,   451,
     452,   453,   458,   459,   464,   465,   470,   471,   476,   477,
     482,   483,   499,   500,   506,   507,   513,   514,   520,   521,
     525,   526,    64,   399,    10,    11,   402,   403,   404,    10,
      11,   408,   409,   410,    10,    11,   414,   415,   416,    10,
      11,   420,   421,   422,    10,    11,   426,   427,   428,   432,
     967,     4,   186,   351,    10,   357,    49,    50,   356,   937,
     950,   951,   952,   953,    10,   364,   363,   937,   950,    10,
     371,   370,   937,   950,    10,   376,    10,    11,   381,   382,
     383,     6,     8,   218,   219,   220,   221,   995,   993,   993,
     132,   181,   274,   275,   276,   277,   144,   168,   166,   138,
     142,   174,   192,     6,   153,   156,   330,   331,   332,   333,
      82,     5,    89,    91,    92,   254,   255,   256,   257,    10,
      11,   544,   545,   546,    17,    23,    29,    34,   543,   959,
     964,   970,   975,    66,   451,    10,    11,   454,   455,   456,
      10,    11,   460,   461,   462,    10,    11,   466,   467,   468,
      10,    11,   472,   473,   474,    10,    11,   478,   479,   480,
      32,   484,   973,   501,   502,   508,   509,   515,   516,   522,
     937,   527,   967,     4,   122,   405,     6,   120,   411,     6,
     196,   417,     4,   190,   423,     6,     7,   170,   429,   991,
      10,    11,   433,   434,   435,   186,   358,   991,     3,   365,
     991,   372,   991,     6,   377,   153,   156,   384,   385,   386,
     387,   993,   132,   276,   278,   279,   993,   156,   332,   334,
     335,    86,     5,    68,   171,   547,   548,   549,   550,   993,
     993,   993,   993,     4,   178,   457,     4,   180,   463,     4,
     164,   469,     4,    94,   475,     4,   130,   481,   993,    10,
      11,   485,   486,   487,    10,   504,   503,   937,   950,    10,
     511,   510,   937,   950,    10,   518,   517,   937,   950,    10,
     523,    10,    11,   528,   529,   530,   122,   120,   196,   190,
     170,   153,   156,   436,   437,   438,   439,   104,   993,   106,
     102,   100,   156,   386,   388,   389,    10,    11,   281,    45,
      46,   280,   937,   942,   943,   944,   945,    10,    11,   337,
      51,    52,   336,   937,   942,   954,   955,   956,   957,    90,
      68,   161,   549,   910,   911,   551,   552,     6,     6,     6,
       6,   178,   180,   164,    94,   130,     6,   187,   194,   488,
     489,   490,   491,   505,   991,   512,   991,   519,   991,     6,
     524,   153,   156,   531,   532,   533,   534,   156,   438,   440,
     441,    10,    11,   391,   390,   937,   942,   954,   182,     3,
     154,     3,    30,   912,   971,    10,   557,    36,    53,    55,
     553,   554,   555,   556,   993,   993,   993,   993,   993,   194,
     490,   492,   204,   206,   202,   200,   156,   533,   535,   536,
      10,    11,   443,   442,   937,   942,   954,   154,   993,   993,
     993,    10,    11,   913,   914,   915,   177,   558,   559,   993,
       3,     3,    10,    11,    41,    42,   493,   494,   495,   496,
     933,   934,   935,   936,   937,   946,   950,    10,    11,   538,
     537,   937,   942,   954,   154,     6,   162,   175,   916,   917,
     918,   919,   143,   574,   575,   560,   561,   562,   937,   946,
     972,     6,   993,   993,     6,     7,   188,   497,   498,     3,
     154,   993,   162,   918,   920,   921,   213,   580,   581,    10,
      11,   576,   577,   578,    10,    11,   563,   564,   565,   562,
     993,   188,   993,    10,    11,   923,   924,   925,    21,   922,
     933,   937,   942,   962,   147,   693,   694,    28,   582,   969,
       4,   144,   579,   178,   181,   566,   567,   568,   569,    69,
      71,    72,   176,   926,   927,   928,   929,   930,   931,   993,
     117,   790,   791,    25,   695,   966,   993,    10,    11,   583,
     584,   585,   144,   178,   568,   570,   571,     5,   932,   176,
     928,     6,   159,   887,   888,    24,   792,   965,   993,    10,
      11,   696,   697,   698,     6,   207,   586,   587,   588,    10,
      11,   573,   572,   937,   946,    70,   993,   172,    27,   889,
     968,   993,    10,    11,   793,   794,   795,     6,   207,   699,
     700,   701,   993,   214,   209,   600,   601,    33,   589,   974,
     182,   993,    10,    11,   890,   891,   892,     6,   123,   796,
     797,   798,   993,   148,   111,   713,   714,    22,   702,   963,
     111,   616,   617,   602,   974,   993,    10,    11,   590,   591,
     592,     6,   157,   160,   893,   894,   895,   896,   993,   118,
     111,   810,   811,    16,   799,   958,   761,    10,    11,   715,
     716,   717,   993,    10,    11,   703,   704,   705,   664,    10,
      11,   618,   619,   620,    10,    11,   603,   604,   605,     6,
     208,   211,   593,   594,   595,   596,   993,   160,   895,   897,
     898,   858,    10,    11,   812,   813,   814,   993,    10,    11,
     800,   801,   802,   153,   762,   763,   109,   718,   719,   720,
       6,   145,   208,   706,   707,   708,   709,   153,   665,   666,
     109,   621,   622,   623,   210,   211,   606,   607,   608,   609,
     993,   208,   595,   597,    10,    11,   900,   901,   902,   899,
     933,   937,   942,   962,   153,   859,   860,   109,   815,   816,
     817,     6,   115,   124,   803,   804,   805,   806,   764,   765,
     112,    95,   726,   727,    18,   721,   960,   993,   208,   708,
     710,   667,   668,   112,    95,   629,   630,   624,   960,   210,
     608,   610,    10,    37,   598,   599,   941,   942,    69,    71,
      72,   158,   903,   904,   905,   906,   907,   908,   861,   862,
     112,    95,   823,   824,   818,   960,   993,   124,   805,   807,
      10,    11,   767,   768,   769,    19,   766,   937,   942,   954,
     961,   963,    97,   733,   734,   728,   960,   993,    10,    11,
     722,   723,   724,    10,   711,   712,   941,   942,    10,    11,
     670,   671,   672,   669,   937,   942,   954,   961,   974,    97,
     636,   637,   631,   960,    10,    11,   625,   626,   627,    10,
      11,   611,   612,   613,   614,   941,   942,   991,   993,     5,
     909,   158,   905,    10,    11,   864,   865,   866,   863,   937,
     942,   954,   958,   961,    97,   830,   831,   825,   960,    10,
      11,   819,   820,   821,    10,   808,   809,   941,   942,   127,
     145,   154,   770,   771,   772,   773,   780,   781,   782,   993,
     139,   740,   741,   735,   960,    10,    11,   729,   730,   731,
       6,   107,   725,   976,   977,   984,   991,   127,   154,   211,
     673,   674,   675,   676,   683,   684,   685,   139,   643,   644,
     638,   960,    10,    11,   632,   633,   634,   628,   976,     4,
     212,   615,   212,     6,    70,   115,   127,   154,   867,   868,
     869,   870,   877,   878,   879,   139,   837,   838,   832,   960,
      10,    11,   826,   827,   828,   822,   976,   991,   154,   772,
     774,   781,   783,   784,     6,   183,   747,   748,   742,   960,
      10,    11,   736,   737,   738,   732,   976,   993,    40,   985,
     110,   125,   978,   979,   146,   154,   675,   677,   684,   686,
     687,   183,   650,   651,   645,   960,    10,    11,   639,   640,
     641,   635,   976,   110,   212,   993,   154,   869,   871,   878,
     880,   881,   183,   844,   845,   839,   960,    10,    11,   833,
     834,   835,   829,   976,   110,   116,    10,    11,   775,   776,
     777,   778,   941,   942,    10,    11,   786,   787,   788,   785,
     937,   954,   960,   993,   197,   754,   755,   749,   960,    10,
      11,   743,   744,   745,   739,   976,    96,   993,    10,    11,
     986,   987,   988,   980,   981,    10,    11,   678,   679,   680,
     681,   941,   942,    10,    11,   689,   690,   691,   688,   937,
     954,   960,   197,   657,   658,   652,   960,    10,    11,   646,
     647,   648,   642,   976,    96,    10,    11,   872,   873,   874,
     875,   941,   942,    10,    11,   883,   884,   885,   882,   937,
     954,   960,   197,   851,   852,   846,   960,    10,    11,   840,
     841,   842,   836,   976,    96,     4,     6,     7,   146,   779,
     992,   789,   976,   756,   960,    10,    11,   750,   751,   752,
     746,   976,    98,     6,     4,   108,    10,   983,    38,    39,
     982,   989,   990,   212,   682,   992,   692,   976,   659,   960,
      10,    11,   653,   654,   655,   649,   976,    98,   116,   876,
     992,   886,   976,   853,   960,    10,    11,   847,   848,   849,
     843,   976,    98,   146,   128,    10,    11,   757,   758,   759,
     753,   976,   140,   993,   108,     6,   993,   993,   212,   128,
      10,    11,   660,   661,   662,   656,   976,   140,   116,   128,
      10,    11,   854,   855,   856,   850,   976,   140,   760,   976,
     184,   126,     6,     6,   663,   976,   184,   857,   976,   184,
     198,   993,   993,   198,   198
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
}
    break;

  case 5:

    {
#ifdef DEBUG
yydebug = 1;
#endif
}
    break;

  case 13:

    {	osrlerror( NULL, osresult, parserData, osglData, "unexpected end of file, expecting </osrl>");}
    break;

  case 16:

    {
	if (!osresult->setResultHeader(osglData->fileName, osglData->source, 	
			osglData->description, osglData->fileCreator, osglData->licence) )	
		osrlerror( NULL, osresult, parserData, osglData, "setHeader failed");
}
    break;

  case 17:

    {
	osglData->fileName    = "";
	osglData->source      = "";
	osglData->description = "";
	osglData->fileCreator = "";
	osglData->licence     = "";
}
    break;

  case 29:

    {
	osglData->fileName = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 36:

    {
	osglData->source = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 43:

    {
	osglData->description = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 50:

    {
	osglData->fileCreator = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 57:

    {
	osglData->licence = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
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
}
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
	}
    break;

  case 80:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for generalStatus element");
		parserData->kounter = 0;
	}
    break;

  case 83:

    { 
		if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "general status type does not match any legal value");
	}
    break;

  case 84:

    {   
		osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
	}
    break;

  case 85:

    {   if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate substatus array. Potential loss of data.");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	}
    break;

  case 86:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	}
    break;

  case 87:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	}
    break;

  case 94:

    {	parserData->kounter++;
}
    break;

  case 95:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror( NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 96:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have name attribute");
}
    break;

  case 99:

    {	
		if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus name");
	}
    break;

  case 100:

    {	
		if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "Error while setting <general> substatus description");
	}
    break;

  case 104:

    {	if (parserData->generalMessagePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one message element allowed");
		parserData->generalMessagePresent = true;
	}
    break;

  case 110:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 112:

    {	if (parserData->generalServiceURIPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceURI element allowed");
		parserData->generalServiceURIPresent = true;
	}
    break;

  case 118:

    {osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 120:

    {	if (parserData->generalServiceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->generalServiceNamePresent = true;
	}
    break;

  case 126:

    {osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 128:

    {	if (parserData->generalInstanceNamePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->generalInstanceNamePresent = true;
	}
    break;

  case 134:

    {osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 136:

    {	if (parserData->generalJobIDPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->generalJobIDPresent = true;
	}
    break;

  case 142:

    {osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 144:

    {	if (parserData->generalSolverInvokedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one solverInvoked element allowed");
		parserData->generalSolverInvokedPresent = true;
	}
    break;

  case 150:

    {osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 152:

    {	if (parserData->generalTimeStampPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeStamp element allowed");
		parserData->generalTimeStampPresent = true;
	}
    break;

  case 158:

    {osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 160:

    {	if (parserData->otherGeneralResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one general other results element allowed");
		parserData->otherGeneralResultsPresent = true;
	}
    break;

  case 161:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other general results cannot be negative");
	if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "Attempting to reallocate other general results array. Potential loss of data.");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 162:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 163:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 170:

    {	parserData->kounter++;
}
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
}
    break;

  case 172:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 175:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultName failed");
	}
    break;

  case 176:

    {	
		if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultValue failed");
	}
    break;

  case 177:

    {	
		if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setGeneralOtherResultDescription failed");
	}
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
}
    break;

  case 198:

    {	if (parserData->systemInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one systemInformation element allowed");
		parserData->systemInformationPresent = true;
	}
    break;

  case 204:

    {	osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 206:

    {	if (parserData->systemAvailableDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableDiskSpace element allowed");
		parserData->systemAvailableDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 210:

    {
		if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 211:

    {	osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 213:

    {	osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 215:

    {	if (parserData->systemAvailableMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableMemory element allowed");
		parserData->systemAvailableMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 219:

    {
		if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 220:

    {	osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 222:

    {	osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 224:

    {	if (parserData->systemAvailableCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUSpeed element allowed");
		parserData->systemAvailableCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 228:

    {
		if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "available CPU Speed could not be set");
		parserData->errorText = NULL;
	}
    break;

  case 229:

    {	osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 231:

    {	osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 233:

    {	if (parserData->systemAvailableCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one availableCPUNumber element allowed");
		parserData->systemAvailableCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	}
    break;

  case 235:

    {	osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 237:

    {	osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; }
    break;

  case 239:

    {	if (parserData->otherSystemResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one system other results element allowed");
		parserData->otherSystemResultsPresent = true;
	}
    break;

  case 240:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other system results cannot be negative");
	if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSystemResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 241:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 242:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 249:

    {	parserData->kounter++;
}
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
}
    break;

  case 251:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 254:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultName failed");
	}
    break;

  case 255:

    {	
		if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultValue failed");
	}
    break;

  case 256:

    {	
		if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSystemOtherResultDescription failed");
	}
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
}
    break;

  case 277:

    {	if (parserData->serviceCurrentStatePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceCurrentStatePresent = true;
	}
    break;

  case 283:

    {   parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setCurrentState(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setCurrentState failed; current system state not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 285:

    {	if (parserData->serviceCurrentJobCountPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one currentJobCount element allowed");
		parserData->serviceCurrentJobCountPresent = true;
	}
    break;

  case 291:

    { osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; }
    break;

  case 293:

    {	if (parserData->serviceTotalJobsSoFarPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one totalJobsSoFar element allowed");
		parserData->serviceTotalJobsSoFarPresent = true;
	}
    break;

  case 299:

    { osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; }
    break;

  case 301:

    {	if (parserData->timeServiceStartedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timeServiceStarted element allowed");
		parserData->timeServiceStartedPresent = true;
	}
    break;

  case 307:

    {osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 309:

    {	if (parserData->serviceUtilizationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one serviceUtilization element allowed");
		parserData->serviceUtilizationPresent = true;
	}
    break;

  case 315:

    {	if (osresult->setServiceUtilization( parserData->tempVal) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setServiceUtilization failed");
	parserData->errorText = NULL;
}
    break;

  case 317:

    {	if (parserData->otherServiceResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one service other results element allowed");
		parserData->otherServiceResultsPresent = true;
	}
    break;

  case 318:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other service results cannot be negative");
	if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherServiceResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 319:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 320:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 327:

    {	parserData->kounter++;
}
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
}
    break;

  case 329:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 332:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultName failed");
	}
    break;

  case 333:

    {	
		if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultValue failed");
	}
    break;

  case 334:

    {	
		if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setServiceOtherResultDescription failed");
	}
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
}
    break;

  case 360:

    {	if (parserData->jobStatusPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job status element allowed");
		parserData->jobStatusPresent = true;
	}
    break;

  case 366:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
		if (osresult->setJobStatus(parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobStatus failed");
		parserData->errorText = NULL;
	}
    break;

  case 368:

    {	if (parserData->jobSubmitTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one submitTime element allowed");
		parserData->jobSubmitTimePresent = true;
	}
    break;

  case 374:

    {osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 376:

    {	if (parserData->scheduledStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one scheduledStartTime element allowed");
		parserData->scheduledStartTimePresent = true;
	}
    break;

  case 382:

    {osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 384:

    {	if (parserData->actualStartTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one actualStartTime element allowed");
		parserData->actualStartTimePresent = true;
	}
    break;

  case 390:

    {osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;}
    break;

  case 392:

    {	if (parserData->jobEndTimePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job endTime element allowed");
		parserData->jobEndTimePresent = true;
	}
    break;

  case 398:

    {osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;}
    break;

  case 400:

    {	if (parserData->jobTimingInformationPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one timingInformation element allowed");
		parserData->jobTimingInformationPresent = true;
	}
    break;

  case 401:

    {	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of time measurements cannot be negative");
	if (osresult->setNumberOfTimes(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfTimes failed");
	parserData->numberOfTimes = parserData->tempInt;
	parserData->ivar = 0;
}
    break;

  case 402:

    {	if (parserData->numberOfTimes > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <time> element");
	}
    break;

  case 403:

    {	if (parserData->ivar != parserData->numberOfTimes)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <time> elements than specified");
	}
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
}
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
}
    break;

  case 424:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); }
    break;

  case 425:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); }
    break;

  case 427:

    {	if (parserData->jobUsedDiskSpacePresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedDiskSpace element allowed");
		parserData->jobUsedDiskSpacePresent = true;		
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	}
    break;

  case 431:

    {
		if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableDiskSpace unit could not be set");
		parserData->errorText = NULL;
	}
    break;

  case 432:

    {	osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 434:

    {	osresult->setUsedDiskSpaceValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 436:

    {	if (parserData->jobUsedMemoryPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedMemory element allowed");
		parserData->jobUsedMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";
		parserData->descriptionAttribute = "";
	}
    break;

  case 440:

    {
		if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "usedMemory unit could not be set");
		parserData->errorText = NULL;
	}
    break;

  case 441:

    {	osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 443:

    {	osresult->setUsedMemoryValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 445:

    {	if (parserData->jobUsedCPUSpeedPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUSpeed element allowed");
		parserData->jobUsedCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "";	
		parserData->descriptionAttribute = "";	
	}
    break;

  case 449:

    {
		if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
			osrlerror(NULL, NULL, parserData, osglData, "availableCPUSpeed unit could not be set");
		parserData->errorText = NULL;
	}
    break;

  case 450:

    {	osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 452:

    {	osresult->setUsedCPUSpeedValue(parserData->tempVal);  
	parserData->errorText = NULL;
}
    break;

  case 454:

    {	if (parserData->jobUsedCPUNumberPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one usedCPUNumber element allowed");
		parserData->jobUsedCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	}
    break;

  case 456:

    {	osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
		parserData->errorText = NULL;
	}
    break;

  case 458:

    { osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; }
    break;

  case 460:

    {	if (parserData->otherJobResultsPresent)
			osrlerror(NULL, NULL, parserData, osglData, "only one job other results element allowed");
		parserData->otherJobResultsPresent = true;
	}
    break;

  case 461:

    {
	if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other job results cannot be negative");
	if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherJobResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 462:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 463:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 470:

    {	parserData->kounter++;
}
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
}
    break;

  case 472:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 475:

    {	if (parserData->nameAttribute.length() == 0)
			osrlerror(NULL, NULL, parserData, osglData, "otherResult name cannot be empty");
		if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultName failed");
	}
    break;

  case 476:

    {	
		if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultValue failed");
	}
    break;

  case 477:

    {	
		if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setJobOtherResultDescription failed");
	}
    break;

  case 482:

    {
	parserData->numberAttributePresent = false;
	parserData->nVarPresent = false;
	parserData->nObjPresent = false;
	parserData->nConPresent = false;
}
    break;

  case 483:

    {	if (!parserData->numberAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "numberOfSolutions was never set");
}
    break;

  case 486:

    {
		parserData->numberOfSolutions = parserData->tempInt; 
		if (osresult->setSolutionNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionNumber failed");
		parserData->solutionIdx = 0;
	}
    break;

  case 487:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osresult->setVariableNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVariableNumber failed");
	}
    break;

  case 488:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osresult->setConstraintNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setConstraintNumber failed");
	}
    break;

  case 489:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osresult->setObjectiveNumber(parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjectiveNumber failed");
	}
    break;

  case 490:

    {	if (parserData->numberOfSolutions > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solution> element");
	}
    break;

  case 491:

    {	if (parserData->solutionIdx != parserData->numberOfSolutions)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solution> elements than specified");
	}
    break;

  case 499:

    {
	if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, "too many solutions"); 
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->weightedObjAttributePresent = false;
}
    break;

  case 506:

    {	if (parserData->idxAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective idx previously set");
	parserData->idxAttributePresent = true;
	if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, "target objective index must be negative");
  	if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveIdx failed");
 }
    break;

  case 507:

    {	if (parserData->nameAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "target objective name previously set");
	parserData->nameAttributePresent = true;
	parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
  	if (osresult->setSolutionTargetObjectiveName(parserData->solutionIdx, parserData->tempStr) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolutionTargetObjectiveName failed");
 }
    break;

  case 508:

    {	if (parserData->weightedObjAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "weighted objective attribute previously set");
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
}
    break;

  case 509:

    {
		parserData->solutionIdx++;
	}
    break;

  case 511:

    {
		parserData->typeAttributePresent = false;
		parserData->descriptionAttributePresent = false;
		parserData->numberAttributePresent = false;
		parserData->numberOf = 0;
		parserData->typeAttribute = "";
		parserData->descriptionAttribute = "";
	}
    break;

  case 512:

    {	if (!parserData->typeAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "type attribute must be present for solution status element");
	}
    break;

  case 515:

    {   
		if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusType failed");
	}
    break;

  case 516:

    {   if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionStatusDescription failed");
	}
    break;

  case 517:

    {	if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolutionSubstatuses failed");
		parserData->numberOf = parserData->tempInt;
		parserData->kounter = 0;
	}
    break;

  case 518:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <substatus> element");
	}
    break;

  case 519:

    {	if (parserData->kounter != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <substatus> elements than specified");
	}
    break;

  case 526:

    {	parserData->kounter++; }
    break;

  case 527:

    {	if (parserData->kounter >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <substatus> elements than specified");
	parserData->typeAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->typeAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 528:

    {	if (!parserData->typeAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<substatus> must have type attribute");
}
    break;

  case 531:

    {	
		if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
											   parserData->typeAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusType failed");
	}
    break;

  case 532:

    {	
		if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
													  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolutionSubstatusDescription failed");
	}
    break;

  case 543:

    {	parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
		osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
		parserData->errorText = NULL;
	}
    break;

  case 546:

    {
	parserData->numberOfOtherVariableResults = 0;
	osresult->optimization->solution[parserData->solutionIdx]->variables = new VariableSolution();
}
    break;

  case 548:

    {	
	if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableResults failed");
	parserData->numberOfOtherVariableResults = parserData->tempInt;
	parserData->iOther = 0;
}
    break;

  case 557:

    {
	if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValues failed");
	parserData->kounter = 0;
}
    break;

  case 558:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	}
    break;

  case 559:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	}
    break;

  case 566:

    {
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->nameAttribute,
							  parserData->tempVal                           ) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValue failed");
	parserData->kounter++;
}
    break;

  case 567:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
}
    break;

  case 576:

    {
	if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfVarValuesString failed");
	parserData->kounter = 0;
}
    break;

  case 577:

    {	if (parserData->numberOfVar > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	}
    break;

  case 578:

    {	if (parserData->kounter != parserData->numberOfVar)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	}
    break;

  case 585:

    {
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
					 				parserData->idx,         parserData->nameAttribute,
									parserData->tempStr                           ) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setVarValueString failed");
	parserData->kounter++;
}
    break;

  case 586:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
}
    break;

  case 591:

    {parserData->tempStr = "";}
    break;

  case 596:

    {parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));}
    break;

  case 599:

    {
	osresult->optimization->solution[parserData->solutionIdx]->variables->basisStatus = new BasisStatus();
}
    break;

  case 606:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 608:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 615:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 617:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 624:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 626:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 633:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 635:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 642:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 644:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 651:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 653:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 661:

    { 	 
		parserData->iOther++;
	}
    break;

  case 662:

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
}
    break;

  case 663:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfVar attribute"); 
	}
    break;

  case 666:

    {	if (parserData->numberOfVarAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfVar attribute previously set");
		parserData->numberOfVarAttributePresent = true;
	 	if (osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfVar) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultNumberOfVar failed");
		parserData->kounter = 0;
	}
    break;

  case 667:

    {	if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherVariableResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	}
    break;

  case 668:

    {	
	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
 												  parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    }
    break;

  case 669:

    {	
	 	if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
 												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultName failed");
    }
    break;

  case 670:

    {	
	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
 														parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    }
    break;

  case 680:

    { 	
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	parserData->kounter++;
}
    break;

  case 681:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osrlerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 684:

    {	
 		if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->idx) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarIdx failed");
	}
    break;

  case 685:

    {	
 		if (osresult->setOtherVariableResultVarName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVarName failed");
	}
    break;

  case 691:

    {	
	 	if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
	 											parserData->kounter,     parserData->tempStr) 
	 											    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultVar failed");
	}
    break;

  case 694:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other variable option failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
}
    break;

  case 695:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 696:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfVarIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfVarIdx attribute"); 
	}
    break;

  case 699:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 700:

    {	
//	 	if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultValue failed");
    }
    break;

  case 701:

    {	
//	 	if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherVariableResultDescription failed");
    }
    break;

  case 709:

    {
	parserData->numberOfOtherObjectiveResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->objectives = new ObjectiveSolution();
}
    break;

  case 711:

    {
	parserData->numberOfOtherObjectiveResults = parserData->tempInt;
	if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherObjectiveResults failed");
	parserData->iOther = 0;
}
    break;

  case 720:

    {
	if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setNumberOfObjValues failed");
	parserData->kounter = 0;
}
    break;

  case 721:

    {	if (parserData->numberOfObj > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	}
    break;

  case 722:

    {	if (parserData->kounter != parserData->numberOfObj)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	}
    break;

  case 729:

    {	if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
							  parserData->idx,         parserData->nameAttribute,
							  parserData->tempVal                           ) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setObjValue failed");
	parserData->kounter++;
}
    break;

  case 730:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->idx = -1;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 738:

    {
	osresult->optimization->solution[parserData->solutionIdx]->objectives->basisStatus = new BasisStatus();
}
    break;

  case 745:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 747:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 754:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 756:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 763:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 765:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 772:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 774:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 781:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 783:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 790:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 792:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 800:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 801:

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
}
    break;

  case 802:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfObj attribute"); 
	}
    break;

  case 805:

    {	if (parserData->numberOfObjAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfObj attribute previously set");
		parserData->numberOfObjAttributePresent = true;
 		if (osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, 
 						                                 parserData->iOther, 
 						                                 parserData->numberOfObj) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultNumberOfObj failed");
		parserData->kounter = 0;
	}
    break;

  case 806:

    {	if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherObjectiveResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	}
    break;

  case 807:

    {	
	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
 												   parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    }
    break;

  case 808:

    {	
	  	if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
 												  parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultName failed");
    }
    break;

  case 809:

    {	
	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
	 													 parserData->iOther, 
 														 parserData->descriptionAttribute) 
 														     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    }
    break;

  case 819:

    {  
	parserData->kounter++;
}
    break;

  case 820:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osrlerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->idx = -1;	
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 823:

    {
		if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjIdx failed");
	}
    break;

  case 824:

    {	
 		if (osresult->setOtherObjectiveResultObjName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObjName failed");
	}
    break;

  case 830:

    {	if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultObj failed");
	}
    break;

  case 833:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_objectives, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other objective option failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
}
    break;

  case 834:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 835:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfObjIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfObjIdx attribute"); 
	}
    break;

  case 838:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 839:

    {	
//	 	if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultValue failed");
    }
    break;

  case 840:

    {	
//	 	if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherObjectiveResultDescription failed");
    }
    break;

  case 848:

    {
	parserData->numberOfOtherConstraintResults = 0; 
	parserData->iOther = 0;
	osresult->optimization->solution[parserData->solutionIdx]->constraints = new ConstraintSolution();
}
    break;

  case 850:

    {
	parserData->numberOfOtherConstraintResults = parserData->tempInt;
	if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintResults failed");
	parserData->iOther = 0;
}
    break;

  case 858:

    {	parserData->numberAttributePresent = false; }
    break;

  case 859:

    {
	if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfDualValues failed");
	parserData->kounter = 0;
}
    break;

  case 860:

    {	if (parserData->numberOfCon > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	}
    break;

  case 861:

    {	if (parserData->kounter != parserData->numberOfCon)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	}
    break;

  case 868:

    {	if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
							   parserData->idx,         parserData->nameAttribute,
							   parserData->tempVal                           ) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setDualValue failed");
	parserData->kounter++;
}
    break;

  case 869:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = "";	
}
    break;

  case 877:

    {
	osresult->optimization->solution[parserData->solutionIdx]->constraints->basisStatus = new BasisStatus();
}
    break;

  case 884:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 886:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 893:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 895:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 902:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 904:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 911:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 913:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 920:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 922:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 929:

    {
	if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
}
    break;

  case 931:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 939:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 940:

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
}
    break;

  case 941:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element requires name attribute"); 
//		if(!parserData->numberAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element requires numberOfCon attribute"); 
	}
    break;

  case 944:

    {	if (parserData->numberOfConAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfCon attribute previously set");
		parserData->numberOfConAttributePresent = true;
 		if (osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, 
 							                              parserData->iOther, 
 							                              parserData->numberOfCon) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultNumberOfCon failed");
		parserData->kounter = 0;
	}
    break;

  case 945:

    {	if (parserData->numberOfEnumerationsAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
		parserData->numberOfEnumerationsAttributePresent = true;
	 	if (osresult->setOtherConstraintResultNumberOfEnumerations(parserData->solutionIdx, 
 														parserData->iOther, 
 														parserData->numberOfEnumerations) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultNumberOfEnumerations failed");
		parserData->kounter = 0;
	}
    break;

  case 946:

    {	
	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
 													parserData->valueAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    }
    break;

  case 947:

    {	
	 	if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultName failed");
    }
    break;

  case 948:

    {	
	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
 														  parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    }
    break;

  case 958:

    { 	
	if (!parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute not set");
	parserData->kounter++;
}
    break;

  case 959:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osrlerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->name = ""	;
}
    break;

  case 962:

    {	
 		if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConIdx failed");
	}
    break;

  case 963:

    {	
 		if (osresult->setOtherConstraintResultConName(parserData->solutionIdx, parserData->iOther, 
 												   parserData->kounter, parserData->nameAttribute) == false)
				osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultConName failed");
	}
    break;

  case 969:

    {	
	 	if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultCon failed");
	}
    break;

  case 972:

    { 	
	if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_constraints, parserData->kounter, parserData->valueAttribute, 
			parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osrlerror(NULL, NULL, parserData, osglData, "set other constraint option failed");
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
}
    break;

  case 973:

    {
//	parserData->numberOfElAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 974:

    {	if(!parserData->nameAttributePresent) 
			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires name attribute"); 
//		if(!parserData->numberOfConIdxAttributePresent) 
//			osrlerror(NULL, NULL, parserData, osglData, "other element enumeration requires numberOfConIdx attribute"); 
	}
    break;

  case 977:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 978:

    {	
//	 	if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
//												  parserData->valueAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultValue failed");
    }
    break;

  case 979:

    {	
//	 	if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
// 														parserData->descriptionAttribute) == false)
//			osrlerror(NULL, NULL, parserData, osglData, "setOtherConstraintResultDescription failed");
    }
    break;

  case 987:

    {
	parserData->numberOf = 0; 
}
    break;

  case 988:

    {	
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfOtherSolutionResults failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
}
    break;

  case 989:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <otherSolutionResult> element");
	}
    break;

  case 990:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <otherSolutionResult> elements than specified");
	}
    break;

  case 997:

    {	parserData->iOther++;
}
    break;

  case 998:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <otherSolutionResult> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 999:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<otherSolutionResult> element must have numberOfItems attribute");
}
    break;

  case 1002:

    {	
		if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
												 parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultName failed");
	}
    break;

  case 1003:

    {	
		if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
													 parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultCategory failed");
	}
    break;

  case 1004:

    {	
		if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
														parserData->iOther,
														parserData->descriptionAttribute) 
														    == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultDescription failed");
	}
    break;

  case 1005:

    {	
		if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
														  parserData->iOther,
														  parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultNumberOfItems failed");
		parserData->kounter = 0;
	}
    break;

  case 1006:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	}
    break;

  case 1007:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	}
    break;

  case 1014:

    {	parserData->kounter++;
}
    break;

  case 1015:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
}
    break;

  case 1020:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
											 parserData->kounter, parserData->itemContent) 
											     == false)
			osrlerror(NULL, NULL, parserData, osglData, "setOtherSolutionResultItem failed");
}
    break;

  case 1023:

    {
	parserData->numberOf = 0; 
}
    break;

  case 1024:

    {	
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setNumberOfSolverOutputs failed");
	parserData->numberOf = parserData->tempInt;
	parserData->iOther = 0; 
}
    break;

  case 1025:

    {	if (parserData->numberOf > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <solverOutput> element");
	}
    break;

  case 1026:

    {	if (parserData->iOther != parserData->numberOf)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <solverOutput> elements than specified");
	}
    break;

  case 1033:

    {	parserData->iOther++;
}
    break;

  case 1034:

    {	if (parserData->iOther >= parserData->numberOf)
		osrlerror(NULL, NULL, parserData, osglData, "more <solverOutput> elements than specified");
	parserData->numberOfItemsPresent = false; 
	parserData->nameAttributePresent = false;
	parserData->categoryAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->categoryAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 1035:

    {	if (!parserData->nameAttributePresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have name attribute");
	if (!parserData->numberOfItemsPresent)
		osrlerror (NULL, NULL, parserData, osglData, "<solverOutput> element must have numberOfItems attribute");
}
    break;

  case 1038:

    {	
		if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputName failed");
	}
    break;

  case 1039:

    {	
		if (osresult->setSolverOutputCategory(parserData->iOther, 
											  parserData->categoryAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputCategory failed");
	}
    break;

  case 1040:

    {	
		if (osresult->setSolverOutputDescription(parserData->iOther, 
												 parserData->descriptionAttribute) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputDescription failed");
	}
    break;

  case 1041:

    {	
		if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
												   parserData->numberOfItems) == false)
			osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputNumberOfItems failed");
		parserData->kounter = 0;
	}
    break;

  case 1042:

    {	if (parserData->numberOfItems > 0)
			osrlerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	}
    break;

  case 1043:

    {	if (parserData->kounter != parserData->numberOfItems)
			osrlerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	}
    break;

  case 1050:

    {	parserData->kounter++;
}
    break;

  case 1051:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
}
    break;

  case 1056:

    {	if (parserData->kounter >= parserData->numberOfItems)
		osrlerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
	if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
									  parserData->itemContent) == false)
		osrlerror(NULL, NULL, parserData, osglData, "setSolverOutputItem failed");
}
    break;

  case 1057:

    {   if (parserData->categoryAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
			parserData->categoryAttributePresent = true;
		}
    break;

  case 1060:

    { parserData->categoryAttribute = ""; }
    break;

  case 1061:

    { parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); }
    break;

  case 1062:

    {   if (parserData->descriptionAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
			parserData->descriptionAttributePresent = true;
		}
    break;

  case 1065:

    { parserData->descriptionAttribute = ""; }
    break;

  case 1066:

    { parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 1067:

    {	
		if (parserData->idxAttributePresent)
			osrlerror(NULL, NULL, parserData, osglData, "idx attribute was previously set");
		parserData->idxAttributePresent = true;
		parserData->idx = (yyvsp[(3) - (4)].ival); 
	}
    break;

  case 1068:

    {   if (parserData->nameAttributePresent ) 
			osrlerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
		parserData->nameAttributePresent = true;
	}
    break;

  case 1071:

    { parserData->nameAttribute = ""; }
    break;

  case 1072:

    { parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 1073:

    {   if (parserData->typeAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		}
    break;

  case 1076:

    { parserData->typeAttribute = ""; }
    break;

  case 1077:

    { parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 1078:

    {   if (parserData->unitAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		}
    break;

  case 1081:

    { parserData->unitAttribute = ""; }
    break;

  case 1082:

    { parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 1083:

    {   if (parserData->valueAttributePresent ) 
				osrlerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		}
    break;

  case 1086:

    { parserData->valueAttribute = ""; }
    break;

  case 1087:

    { parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));}
    break;

  case 1088:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1089:

    {	if (parserData->nConPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->nConPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1090:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1091:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1092:

    {	
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1093:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1094:

    {	if (parserData->nObjPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->nObjPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1095:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other constraint results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1096:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other objective results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1097:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1098:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solution results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1099:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other variable results cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1100:

    {	if (parserData->numberAttributePresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfSolutions attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of solutions cannot be negative");
	parserData->numberAttributePresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1101:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of other solver outputs cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1102:

    {   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <substatus> elements cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1103:

    {
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1104:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1105:

    {	if (parserData->nVarPresent)
		osrlerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->nVarPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1106:

    {
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	}
    break;

  case 1111:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
}
    break;

  case 1117:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
}
    break;

  case 1119:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1124:

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
}
    break;

  case 1125:

    {	
	if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1126:

    {	
	if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osrlerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1127:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1128:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 1129:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); }
    break;

  case 1130:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); }
    break;

  case 1131:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].dval)); }
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

