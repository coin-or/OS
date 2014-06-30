
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         osolparse
#define yylex           osollex
#define yyerror         osolerror
#define yylval          osollval
#define yychar          osolchar
#define yydebug         osoldebug
#define yynerrs         osolnerrs
#define yylloc          osollloc

/* Copy the first part of user declarations.  */




#include "OSConfig.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include "OSgLParserData.h"
#include "OSBase64.h"

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

//#define DEBUG

#ifdef DEBUG
#define YYDEBUG 1
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osol_scan_string (const char *yy_str , void* yyscanner  );
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* yyscanner );
int osolget_lineno( void* yyscanner);
char *osolget_text (void* yyscanner );
void osolset_lineno (int line_number , void* yyscanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );
void  yygetOSOption(const char *ch, OSOption* m_osoption, OSoLParserData *m_parserData, OSgLParserData *osglData ) throw(ErrorClass);
void osol_empty_vectors( OSoLParserData* parserData);
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
     OSOLSTART = 267,
     OSOLSTARTEMPTY = 268,
     OSOLATTRIBUTETEXT = 269,
     OSOLEND = 270,
     NUMBEROFOTHEROPTIONSATT = 271,
     NUMBEROFENUMERATIONSATT = 272,
     NUMBEROFJOBIDSATT = 273,
     NUMBEROFPATHSATT = 274,
     NUMBEROFPATHPAIRSATT = 275,
     FROMATT = 276,
     TOATT = 277,
     MAKECOPYATT = 278,
     CATEGORYATT = 279,
     TYPEATT = 280,
     GROUPWEIGHTATT = 281,
     NUMBEROFPROCESSESATT = 282,
     NUMBEROFSOLVEROPTIONSATT = 283,
     NUMBEROFSOSATT = 284,
     NUMBEROFVARIABLESATT = 285,
     NUMBEROFOBJECTIVESATT = 286,
     NUMBEROFCONSTRAINTSATT = 287,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 288,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 289,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 290,
     NUMBEROFITEMSATT = 291,
     NUMBEROFVARATT = 292,
     NUMBEROFOBJATT = 293,
     NUMBEROFCONATT = 294,
     NUMBEROFELATT = 295,
     NAMEATT = 296,
     IDXATT = 297,
     SOSIDXATT = 298,
     VALUEATT = 299,
     UNITATT = 300,
     DESCRIPTIONATT = 301,
     CONTYPEATT = 302,
     EMPTYCONTYPEATT = 303,
     ENUMTYPEATT = 304,
     EMPTYENUMTYPEATT = 305,
     OBJTYPEATT = 306,
     EMPTYOBJTYPEATT = 307,
     VARTYPEATT = 308,
     EMPTYVARTYPEATT = 309,
     EMPTYTYPEATT = 310,
     EMPTYNAMEATT = 311,
     EMPTYCATEGORYATT = 312,
     EMPTYDESCRIPTIONATT = 313,
     EMPTYUNITATT = 314,
     EMPTYVALUEATT = 315,
     EMPTYLBVALUEATT = 316,
     EMPTYUBVALUEATT = 317,
     LBVALUEATT = 318,
     UBVALUEATT = 319,
     EMPTYLBDUALVALUEATT = 320,
     EMPTYUBDUALVALUEATT = 321,
     LBDUALVALUEATT = 322,
     UBDUALVALUEATT = 323,
     SOLVERATT = 324,
     EMPTYSOLVERATT = 325,
     WEIGHTATT = 326,
     EMPTYWEIGHTATT = 327,
     TRANSPORTTYPEATT = 328,
     LOCATIONTYPEATT = 329,
     SYMMETRYATT = 330,
     HEADERSTART = 331,
     HEADEREND = 332,
     GENERALSTART = 333,
     GENERALEND = 334,
     SYSTEMSTART = 335,
     SYSTEMEND = 336,
     SERVICESTART = 337,
     SERVICEEND = 338,
     JOBSTART = 339,
     JOBEND = 340,
     OPTIMIZATIONSTART = 341,
     OPTIMIZATIONEND = 342,
     FILENAMESTART = 343,
     FILENAMEEND = 344,
     FILENAMEEMPTY = 345,
     FILENAMESTARTANDEND = 346,
     FILESOURCESTART = 347,
     FILESOURCEEND = 348,
     FILESOURCEEMPTY = 349,
     FILESOURCESTARTANDEND = 350,
     FILEDESCRIPTIONSTART = 351,
     FILEDESCRIPTIONEND = 352,
     FILEDESCRIPTIONEMPTY = 353,
     FILEDESCRIPTIONSTARTANDEND = 354,
     FILECREATORSTART = 355,
     FILECREATOREND = 356,
     FILECREATOREMPTY = 357,
     FILECREATORSTARTANDEND = 358,
     FILELICENCESTART = 359,
     FILELICENCEEND = 360,
     FILELICENCEEMPTY = 361,
     FILELICENCESTARTANDEND = 362,
     SERVICEURISTART = 363,
     SERVICEURIEND = 364,
     SERVICENAMESTART = 365,
     SERVICENAMEEND = 366,
     INSTANCENAMESTART = 367,
     INSTANCENAMEEND = 368,
     INSTANCELOCATIONSTART = 369,
     INSTANCELOCATIONEND = 370,
     JOBIDSTART = 371,
     JOBIDEND = 372,
     SOLVERTOINVOKESTART = 373,
     SOLVERTOINVOKEEND = 374,
     LICENSESTART = 375,
     LICENSEEND = 376,
     USERNAMESTART = 377,
     USERNAMEEND = 378,
     PASSWORDSTART = 379,
     PASSWORDEND = 380,
     CONTACTSTART = 381,
     CONTACTEND = 382,
     OTHEROPTIONSSTART = 383,
     OTHEROPTIONSEND = 384,
     OTHERSTART = 385,
     OTHEREND = 386,
     MINDISKSPACESTART = 387,
     MINDISKSPACEEND = 388,
     MINMEMORYSTART = 389,
     MINMEMORYEND = 390,
     MINCPUSPEEDSTART = 391,
     MINCPUSPEEDEND = 392,
     MINCPUNUMBERSTART = 393,
     MINCPUNUMBEREND = 394,
     SERVICETYPESTART = 395,
     SERVICETYPEEND = 396,
     MAXTIMESTART = 397,
     MAXTIMEEND = 398,
     REQUESTEDSTARTTIMESTART = 399,
     REQUESTEDSTARTTIMEEND = 400,
     DEPENDENCIESSTART = 401,
     DEPENDENCIESEND = 402,
     REQUIREDDIRECTORIESSTART = 403,
     REQUIREDDIRECTORIESEND = 404,
     REQUIREDFILESSTART = 405,
     REQUIREDFILESEND = 406,
     PATHSTART = 407,
     PATHEND = 408,
     PATHPAIRSTART = 409,
     PATHPAIREND = 410,
     DIRECTORIESTOMAKESTART = 411,
     DIRECTORIESTOMAKEEND = 412,
     FILESTOMAKESTART = 413,
     FILESTOMAKEEND = 414,
     DIRECTORIESTODELETESTART = 415,
     DIRECTORIESTODELETEEND = 416,
     FILESTODELETESTART = 417,
     FILESTODELETEEND = 418,
     INPUTDIRECTORIESTOMOVESTART = 419,
     INPUTDIRECTORIESTOMOVEEND = 420,
     INPUTFILESTOMOVESTART = 421,
     INPUTFILESTOMOVEEND = 422,
     OUTPUTDIRECTORIESTOMOVESTART = 423,
     OUTPUTDIRECTORIESTOMOVEEND = 424,
     OUTPUTFILESTOMOVESTART = 425,
     OUTPUTFILESTOMOVEEND = 426,
     PROCESSESTOKILLSTART = 427,
     PROCESSESTOKILLEND = 428,
     PROCESSSTART = 429,
     PROCESSEND = 430,
     VARIABLESSTART = 431,
     VARIABLESEND = 432,
     INITIALVARIABLEVALUESSTART = 433,
     INITIALVARIABLEVALUESEND = 434,
     VARSTART = 435,
     VAREND = 436,
     INITIALVARIABLEVALUESSTRINGSTART = 437,
     INITIALVARIABLEVALUESSTRINGEND = 438,
     INITIALBASISSTATUSSTART = 439,
     INITIALBASISSTATUSEND = 440,
     BASICSTART = 441,
     BASICEND = 442,
     ATUPPERSTART = 443,
     ATUPPEREND = 444,
     ATLOWERSTART = 445,
     ATLOWEREND = 446,
     ATEQUALITYSTART = 447,
     ATEQUALITYEND = 448,
     SUPERBASICSTART = 449,
     SUPERBASICEND = 450,
     ISFREESTART = 451,
     ISFREEEND = 452,
     UNKNOWNSTART = 453,
     UNKNOWNEND = 454,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 455,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 456,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 457,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 458,
     SOSSTART = 459,
     SOSEND = 460,
     OBJECTIVESSTART = 461,
     OBJECTIVESEND = 462,
     INITIALOBJECTIVEVALUESSTART = 463,
     INITIALOBJECTIVEVALUESEND = 464,
     OBJSTART = 465,
     OBJEND = 466,
     INITIALOBJECTIVEBOUNDSSTART = 467,
     INITIALOBJECTIVEBOUNDSEND = 468,
     CONSTRAINTSSTART = 469,
     CONSTRAINTSEND = 470,
     INITIALCONSTRAINTVALUESSTART = 471,
     INITIALCONSTRAINTVALUESEND = 472,
     CONSTART = 473,
     CONEND = 474,
     INITIALDUALVALUESSTART = 475,
     INITIALDUALVALUESEND = 476,
     SOLVEROPTIONSSTART = 477,
     SOLVEROPTIONSEND = 478,
     SOLVEROPTIONSTART = 479,
     SOLVEROPTIONEND = 480,
     ENUMERATIONSTART = 481,
     ENUMERATIONEND = 482,
     ITEMEMPTY = 483,
     ITEMSTART = 484,
     ITEMEND = 485,
     ITEMSTARTANDEND = 486,
     BASE64START = 487,
     BASE64END = 488,
     INCRATT = 489,
     MULTATT = 490,
     SIZEOFATT = 491,
     ELSTART = 492,
     ELEND = 493,
     MATRIXSTART = 494,
     MATRIXEND = 495,
     BASEMATRIXEND = 496,
     BASEMATRIXSTART = 497,
     BLOCKSTART = 498,
     BLOCKEND = 499,
     BLOCKSSTART = 500,
     BLOCKSEND = 501,
     EMPTYSYMMETRYATT = 502,
     NUMBEROFBLOCKSATT = 503,
     DUMMY = 504
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
#define OSOLSTART 267
#define OSOLSTARTEMPTY 268
#define OSOLATTRIBUTETEXT 269
#define OSOLEND 270
#define NUMBEROFOTHEROPTIONSATT 271
#define NUMBEROFENUMERATIONSATT 272
#define NUMBEROFJOBIDSATT 273
#define NUMBEROFPATHSATT 274
#define NUMBEROFPATHPAIRSATT 275
#define FROMATT 276
#define TOATT 277
#define MAKECOPYATT 278
#define CATEGORYATT 279
#define TYPEATT 280
#define GROUPWEIGHTATT 281
#define NUMBEROFPROCESSESATT 282
#define NUMBEROFSOLVEROPTIONSATT 283
#define NUMBEROFSOSATT 284
#define NUMBEROFVARIABLESATT 285
#define NUMBEROFOBJECTIVESATT 286
#define NUMBEROFCONSTRAINTSATT 287
#define NUMBEROFOTHERVARIABLEOPTIONSATT 288
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 289
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 290
#define NUMBEROFITEMSATT 291
#define NUMBEROFVARATT 292
#define NUMBEROFOBJATT 293
#define NUMBEROFCONATT 294
#define NUMBEROFELATT 295
#define NAMEATT 296
#define IDXATT 297
#define SOSIDXATT 298
#define VALUEATT 299
#define UNITATT 300
#define DESCRIPTIONATT 301
#define CONTYPEATT 302
#define EMPTYCONTYPEATT 303
#define ENUMTYPEATT 304
#define EMPTYENUMTYPEATT 305
#define OBJTYPEATT 306
#define EMPTYOBJTYPEATT 307
#define VARTYPEATT 308
#define EMPTYVARTYPEATT 309
#define EMPTYTYPEATT 310
#define EMPTYNAMEATT 311
#define EMPTYCATEGORYATT 312
#define EMPTYDESCRIPTIONATT 313
#define EMPTYUNITATT 314
#define EMPTYVALUEATT 315
#define EMPTYLBVALUEATT 316
#define EMPTYUBVALUEATT 317
#define LBVALUEATT 318
#define UBVALUEATT 319
#define EMPTYLBDUALVALUEATT 320
#define EMPTYUBDUALVALUEATT 321
#define LBDUALVALUEATT 322
#define UBDUALVALUEATT 323
#define SOLVERATT 324
#define EMPTYSOLVERATT 325
#define WEIGHTATT 326
#define EMPTYWEIGHTATT 327
#define TRANSPORTTYPEATT 328
#define LOCATIONTYPEATT 329
#define SYMMETRYATT 330
#define HEADERSTART 331
#define HEADEREND 332
#define GENERALSTART 333
#define GENERALEND 334
#define SYSTEMSTART 335
#define SYSTEMEND 336
#define SERVICESTART 337
#define SERVICEEND 338
#define JOBSTART 339
#define JOBEND 340
#define OPTIMIZATIONSTART 341
#define OPTIMIZATIONEND 342
#define FILENAMESTART 343
#define FILENAMEEND 344
#define FILENAMEEMPTY 345
#define FILENAMESTARTANDEND 346
#define FILESOURCESTART 347
#define FILESOURCEEND 348
#define FILESOURCEEMPTY 349
#define FILESOURCESTARTANDEND 350
#define FILEDESCRIPTIONSTART 351
#define FILEDESCRIPTIONEND 352
#define FILEDESCRIPTIONEMPTY 353
#define FILEDESCRIPTIONSTARTANDEND 354
#define FILECREATORSTART 355
#define FILECREATOREND 356
#define FILECREATOREMPTY 357
#define FILECREATORSTARTANDEND 358
#define FILELICENCESTART 359
#define FILELICENCEEND 360
#define FILELICENCEEMPTY 361
#define FILELICENCESTARTANDEND 362
#define SERVICEURISTART 363
#define SERVICEURIEND 364
#define SERVICENAMESTART 365
#define SERVICENAMEEND 366
#define INSTANCENAMESTART 367
#define INSTANCENAMEEND 368
#define INSTANCELOCATIONSTART 369
#define INSTANCELOCATIONEND 370
#define JOBIDSTART 371
#define JOBIDEND 372
#define SOLVERTOINVOKESTART 373
#define SOLVERTOINVOKEEND 374
#define LICENSESTART 375
#define LICENSEEND 376
#define USERNAMESTART 377
#define USERNAMEEND 378
#define PASSWORDSTART 379
#define PASSWORDEND 380
#define CONTACTSTART 381
#define CONTACTEND 382
#define OTHEROPTIONSSTART 383
#define OTHEROPTIONSEND 384
#define OTHERSTART 385
#define OTHEREND 386
#define MINDISKSPACESTART 387
#define MINDISKSPACEEND 388
#define MINMEMORYSTART 389
#define MINMEMORYEND 390
#define MINCPUSPEEDSTART 391
#define MINCPUSPEEDEND 392
#define MINCPUNUMBERSTART 393
#define MINCPUNUMBEREND 394
#define SERVICETYPESTART 395
#define SERVICETYPEEND 396
#define MAXTIMESTART 397
#define MAXTIMEEND 398
#define REQUESTEDSTARTTIMESTART 399
#define REQUESTEDSTARTTIMEEND 400
#define DEPENDENCIESSTART 401
#define DEPENDENCIESEND 402
#define REQUIREDDIRECTORIESSTART 403
#define REQUIREDDIRECTORIESEND 404
#define REQUIREDFILESSTART 405
#define REQUIREDFILESEND 406
#define PATHSTART 407
#define PATHEND 408
#define PATHPAIRSTART 409
#define PATHPAIREND 410
#define DIRECTORIESTOMAKESTART 411
#define DIRECTORIESTOMAKEEND 412
#define FILESTOMAKESTART 413
#define FILESTOMAKEEND 414
#define DIRECTORIESTODELETESTART 415
#define DIRECTORIESTODELETEEND 416
#define FILESTODELETESTART 417
#define FILESTODELETEEND 418
#define INPUTDIRECTORIESTOMOVESTART 419
#define INPUTDIRECTORIESTOMOVEEND 420
#define INPUTFILESTOMOVESTART 421
#define INPUTFILESTOMOVEEND 422
#define OUTPUTDIRECTORIESTOMOVESTART 423
#define OUTPUTDIRECTORIESTOMOVEEND 424
#define OUTPUTFILESTOMOVESTART 425
#define OUTPUTFILESTOMOVEEND 426
#define PROCESSESTOKILLSTART 427
#define PROCESSESTOKILLEND 428
#define PROCESSSTART 429
#define PROCESSEND 430
#define VARIABLESSTART 431
#define VARIABLESEND 432
#define INITIALVARIABLEVALUESSTART 433
#define INITIALVARIABLEVALUESEND 434
#define VARSTART 435
#define VAREND 436
#define INITIALVARIABLEVALUESSTRINGSTART 437
#define INITIALVARIABLEVALUESSTRINGEND 438
#define INITIALBASISSTATUSSTART 439
#define INITIALBASISSTATUSEND 440
#define BASICSTART 441
#define BASICEND 442
#define ATUPPERSTART 443
#define ATUPPEREND 444
#define ATLOWERSTART 445
#define ATLOWEREND 446
#define ATEQUALITYSTART 447
#define ATEQUALITYEND 448
#define SUPERBASICSTART 449
#define SUPERBASICEND 450
#define ISFREESTART 451
#define ISFREEEND 452
#define UNKNOWNSTART 453
#define UNKNOWNEND 454
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 455
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 456
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 457
#define SOSVARIABLEBRANCHINGWEIGHTSEND 458
#define SOSSTART 459
#define SOSEND 460
#define OBJECTIVESSTART 461
#define OBJECTIVESEND 462
#define INITIALOBJECTIVEVALUESSTART 463
#define INITIALOBJECTIVEVALUESEND 464
#define OBJSTART 465
#define OBJEND 466
#define INITIALOBJECTIVEBOUNDSSTART 467
#define INITIALOBJECTIVEBOUNDSEND 468
#define CONSTRAINTSSTART 469
#define CONSTRAINTSEND 470
#define INITIALCONSTRAINTVALUESSTART 471
#define INITIALCONSTRAINTVALUESEND 472
#define CONSTART 473
#define CONEND 474
#define INITIALDUALVALUESSTART 475
#define INITIALDUALVALUESEND 476
#define SOLVEROPTIONSSTART 477
#define SOLVEROPTIONSEND 478
#define SOLVEROPTIONSTART 479
#define SOLVEROPTIONEND 480
#define ENUMERATIONSTART 481
#define ENUMERATIONEND 482
#define ITEMEMPTY 483
#define ITEMSTART 484
#define ITEMEND 485
#define ITEMSTARTANDEND 486
#define BASE64START 487
#define BASE64END 488
#define INCRATT 489
#define MULTATT 490
#define SIZEOFATT 491
#define ELSTART 492
#define ELEND 493
#define MATRIXSTART 494
#define MATRIXEND 495
#define BASEMATRIXEND 496
#define BASEMATRIXSTART 497
#define BLOCKSTART 498
#define BLOCKEND 499
#define BLOCKSSTART 500
#define BLOCKSEND 501
#define EMPTYSYMMETRYATT 502
#define NUMBEROFBLOCKSATT 503
#define DUMMY 504




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


    double dval;
    int ival;
    char* sval;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
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



std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg ) ;
void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, std::string errormsg );
int osollex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
#define scanner parserData->scanner



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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  254
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  831
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1240
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1696

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   504

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   251,
     253,     2,     2,   252,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   250,     2,     2,     2,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    16,    18,    20,
      22,    24,    28,    30,    32,    33,    40,    41,    43,    44,
      47,    49,    51,    53,    56,    58,    62,    64,    66,    69,
      71,    73,    75,    77,    79,    81,    83,    85,    87,    89,
      91,    94,    96,    98,   100,   103,   105,   109,   111,   114,
     116,   118,   120,   123,   125,   129,   131,   134,   136,   138,
     140,   143,   145,   149,   151,   155,   157,   158,   160,   164,
     166,   168,   171,   173,   177,   179,   182,   184,   186,   188,
     191,   193,   197,   199,   202,   204,   206,   208,   211,   213,
     217,   219,   222,   224,   226,   228,   231,   233,   237,   239,
     242,   244,   246,   248,   251,   253,   257,   259,   262,   264,
     266,   268,   271,   273,   277,   279,   283,   285,   286,   288,
     292,   294,   296,   299,   301,   305,   307,   311,   313,   315,
     317,   319,   322,   324,   328,   330,   332,   335,   339,   341,
     343,   344,   347,   349,   351,   353,   356,   358,   359,   362,
     364,   366,   368,   371,   373,   377,   379,   381,   384,   386,
     388,   390,   392,   394,   398,   400,   402,   403,   406,   408,
     410,   414,   416,   420,   422,   424,   425,   428,   430,   432,
     436,   438,   442,   444,   446,   447,   450,   452,   454,   458,
     460,   464,   466,   467,   469,   473,   475,   479,   481,   483,
     485,   487,   490,   492,   496,   498,   500,   503,   507,   509,
     511,   512,   515,   517,   519,   521,   524,   526,   527,   530,
     532,   534,   536,   539,   541,   545,   547,   549,   552,   554,
     556,   559,   561,   563,   565,   568,   570,   574,   576,   580,
     582,   584,   586,   588,   591,   593,   597,   599,   601,   604,
     608,   610,   612,   613,   616,   618,   620,   622,   625,   627,
     628,   631,   633,   635,   637,   640,   642,   646,   648,   650,
     653,   655,   657,   659,   661,   663,   665,   667,   669,   671,
     673,   675,   677,   679,   681,   683,   687,   689,   690,   692,
     694,   696,   699,   701,   705,   707,   709,   712,   714,   716,
     718,   721,   723,   727,   729,   733,   735,   737,   739,   741,
     744,   746,   750,   752,   755,   760,   764,   766,   768,   770,
     773,   775,   779,   783,   785,   787,   789,   792,   794,   798,
     802,   804,   806,   808,   811,   813,   817,   821,   823,   825,
     827,   830,   832,   836,   840,   842,   844,   846,   848,   851,
     853,   857,   859,   862,   864,   868,   870,   872,   874,   876,
     879,   881,   885,   887,   890,   892,   896,   898,   900,   902,
     904,   907,   909,   913,   915,   918,   920,   924,   926,   928,
     930,   932,   935,   937,   941,   943,   946,   948,   952,   954,
     956,   958,   960,   963,   965,   969,   973,   975,   977,   979,
     981,   984,   986,   990,   994,   996,   998,  1000,  1002,  1005,
    1007,  1011,  1013,  1016,  1021,  1025,  1027,  1029,  1031,  1033,
    1036,  1038,  1042,  1044,  1046,  1049,  1053,  1055,  1057,  1058,
    1061,  1063,  1065,  1067,  1070,  1072,  1073,  1077,  1079,  1081,
    1082,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1101,  1106,
    1107,  1111,  1113,  1115,  1116,  1118,  1120,  1122,  1124,  1128,
    1135,  1136,  1140,  1142,  1144,  1146,  1148,  1151,  1153,  1157,
    1159,  1161,  1164,  1168,  1170,  1172,  1173,  1176,  1178,  1180,
    1182,  1185,  1187,  1188,  1192,  1194,  1196,  1198,  1200,  1203,
    1205,  1209,  1211,  1213,  1216,  1220,  1222,  1224,  1225,  1228,
    1230,  1232,  1234,  1237,  1239,  1240,  1243,  1245,  1247,  1249,
    1251,  1255,  1263,  1264,  1268,  1270,  1272,  1274,  1276,  1278,
    1282,  1284,  1285,  1289,  1291,  1293,  1295,  1297,  1299,  1303,
    1305,  1306,  1310,  1312,  1314,  1316,  1318,  1320,  1324,  1326,
    1327,  1331,  1333,  1335,  1337,  1339,  1341,  1345,  1347,  1348,
    1352,  1354,  1356,  1358,  1360,  1362,  1366,  1368,  1369,  1373,
    1375,  1377,  1379,  1381,  1383,  1387,  1389,  1390,  1394,  1396,
    1398,  1400,  1402,  1404,  1408,  1410,  1411,  1415,  1417,  1419,
    1421,  1423,  1426,  1428,  1432,  1434,  1436,  1439,  1443,  1445,
    1447,  1448,  1451,  1453,  1455,  1457,  1460,  1462,  1463,  1467,
    1469,  1474,  1476,  1478,  1481,  1483,  1487,  1489,  1492,  1496,
    1498,  1500,  1501,  1504,  1506,  1508,  1510,  1512,  1514,  1517,
    1519,  1523,  1524,  1527,  1531,  1533,  1535,  1536,  1539,  1541,
    1543,  1545,  1547,  1549,  1551,  1553,  1555,  1557,  1559,  1561,
    1563,  1566,  1568,  1572,  1574,  1576,  1578,  1581,  1585,  1587,
    1589,  1590,  1593,  1595,  1597,  1599,  1601,  1603,  1605,  1608,
    1610,  1611,  1615,  1617,  1619,  1620,  1622,  1624,  1626,  1628,
    1632,  1637,  1638,  1642,  1644,  1646,  1648,  1650,  1653,  1655,
    1659,  1661,  1663,  1666,  1670,  1672,  1674,  1675,  1678,  1680,
    1682,  1684,  1687,  1689,  1690,  1694,  1696,  1698,  1700,  1702,
    1705,  1707,  1711,  1713,  1715,  1718,  1722,  1724,  1726,  1727,
    1730,  1732,  1734,  1736,  1738,  1741,  1743,  1744,  1747,  1749,
    1751,  1753,  1755,  1759,  1767,  1768,  1772,  1774,  1776,  1778,
    1780,  1782,  1786,  1788,  1789,  1793,  1795,  1797,  1799,  1801,
    1803,  1807,  1809,  1810,  1814,  1816,  1818,  1820,  1822,  1824,
    1828,  1830,  1831,  1835,  1837,  1839,  1841,  1843,  1845,  1849,
    1851,  1852,  1856,  1858,  1860,  1862,  1864,  1866,  1870,  1872,
    1873,  1877,  1879,  1881,  1883,  1885,  1887,  1891,  1893,  1894,
    1898,  1900,  1902,  1904,  1906,  1908,  1912,  1914,  1915,  1918,
    1922,  1924,  1926,  1927,  1930,  1932,  1934,  1936,  1938,  1940,
    1942,  1944,  1946,  1948,  1950,  1952,  1954,  1957,  1959,  1963,
    1965,  1967,  1969,  1972,  1976,  1978,  1980,  1981,  1984,  1986,
    1988,  1990,  1992,  1994,  1996,  1999,  2001,  2002,  2006,  2008,
    2010,  2011,  2013,  2015,  2017,  2019,  2023,  2028,  2029,  2033,
    2035,  2037,  2039,  2041,  2044,  2046,  2050,  2052,  2054,  2057,
    2061,  2063,  2065,  2066,  2069,  2071,  2073,  2075,  2078,  2080,
    2081,  2085,  2087,  2089,  2091,  2093,  2096,  2098,  2102,  2104,
    2106,  2109,  2113,  2115,  2117,  2118,  2121,  2123,  2125,  2127,
    2129,  2132,  2134,  2135,  2138,  2140,  2142,  2144,  2146,  2150,
    2158,  2159,  2163,  2165,  2167,  2169,  2171,  2173,  2177,  2179,
    2180,  2184,  2186,  2188,  2190,  2192,  2194,  2198,  2200,  2201,
    2205,  2207,  2209,  2211,  2213,  2215,  2219,  2221,  2222,  2226,
    2228,  2230,  2232,  2234,  2236,  2240,  2242,  2243,  2247,  2249,
    2251,  2253,  2255,  2257,  2261,  2263,  2264,  2268,  2270,  2272,
    2274,  2276,  2278,  2282,  2284,  2285,  2289,  2291,  2293,  2295,
    2297,  2299,  2303,  2305,  2306,  2309,  2313,  2315,  2317,  2318,
    2321,  2323,  2325,  2327,  2329,  2331,  2333,  2335,  2337,  2339,
    2341,  2343,  2345,  2348,  2350,  2354,  2356,  2358,  2360,  2363,
    2367,  2369,  2371,  2372,  2375,  2377,  2379,  2381,  2383,  2385,
    2387,  2390,  2392,  2393,  2397,  2399,  2401,  2403,  2405,  2407,
    2411,  2412,  2415,  2419,  2421,  2423,  2425,  2428,  2430,  2432,
    2434,  2436,  2438,  2440,  2442,  2444,  2446,  2449,  2451,  2455,
    2457,  2459,  2462,  2464,  2466,  2468,  2470,  2472,  2476,  2478,
    2480,  2483,  2488,  2492,  2494,  2496,  2497,  2500,  2502,  2504,
    2506,  2510,  2514,  2518,  2521,  2523,  2525,  2527,  2529,  2531,
    2535,  2537,  2539,  2541,  2543,  2547,  2549,  2551,  2553,  2555,
    2559,  2561,  2563,  2565,  2567,  2571,  2573,  2578,  2580,  2582,
    2587,  2589,  2591,  2593,  2595,  2599,  2601,  2603,  2605,  2607,
    2612,  2614,  2616,  2618,  2620,  2624,  2626,  2628,  2630,  2632,
    2636,  2638,  2640,  2642,  2644,  2648,  2650,  2652,  2657,  2659,
    2661,  2663,  2665,  2669,  2671,  2673,  2675,  2677,  2681,  2683,
    2685,  2687,  2689,  2694,  2696,  2698,  2700,  2702,  2706,  2708,
    2710,  2712,  2714,  2718,  2720,  2722,  2724,  2726,  2730,  2735,
    2740,  2745,  2750,  2755,  2760,  2765,  2770,  2775,  2780,  2785,
    2790,  2795,  2800,  2805,  2810,  2815,  2820,  2822,  2825,  2829,
    2831,  2833,  2834,  2837,  2839,  2841,  2843,  2845,  2847,  2849,
    2853,  2855,  2857,  2859,  2862,  2863,  2866,  2868,  2870,  2872,
    2874,  2877,  2879,  2881,  2883,  2886,  2888,  2892,  2894,  2896,
    2899,  2901,  2903,  2905,  2907,  2909,  2910,  2912,  2914,  2916,
    2918,  2920,  2924,  2925,  2927,  2929,  2931,  2933,  2935,  2939,
    2940,  2942,  2944,  2946,  2948,  2950,  2954,  2955,  2957,  2959,
    2961,  2963,  2965,  2969,  2970,  2972,  2974,  2976,  2978,  2980,
    2984,  2986,  2988,  2989,  2992,  2996,  2998,  3000,  3001,  3004,
    3006,  3008,  3012,  3016,  3021,  3023,  3025,  3028,  3030,  3034,
    3039
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     255,     0,    -1,   256,   264,   262,    -1,   257,   258,   259,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   260,    -1,
     261,    -1,    11,    -1,    10,   264,   262,    -1,   263,    -1,
      15,    -1,    -1,   265,   266,   352,   400,   428,   544,    -1,
      -1,  1042,    -1,    -1,   267,   268,    -1,    78,    -1,   269,
      -1,   270,    -1,    10,    79,    -1,    11,    -1,    10,   271,
      79,    -1,   272,    -1,   273,    -1,   272,   273,    -1,   274,
      -1,   280,    -1,   286,    -1,   292,    -1,   300,    -1,   306,
      -1,   312,    -1,   318,    -1,   324,    -1,   330,    -1,   338,
      -1,   275,   276,    -1,   108,    -1,   277,    -1,   278,    -1,
      10,   109,    -1,    11,    -1,    10,   279,   109,    -1,     4,
      -1,   281,   282,    -1,   110,    -1,   283,    -1,   284,    -1,
      10,   111,    -1,    11,    -1,    10,   285,   111,    -1,     4,
      -1,   287,   288,    -1,   112,    -1,   289,    -1,   290,    -1,
      10,   113,    -1,    11,    -1,    10,   291,   113,    -1,     4,
      -1,   293,   294,   296,    -1,   114,    -1,    -1,   295,    -1,
      74,     3,     8,    -1,   297,    -1,   298,    -1,    10,   115,
      -1,    11,    -1,    10,   299,   115,    -1,     4,    -1,   301,
     302,    -1,   116,    -1,   303,    -1,   304,    -1,    10,   117,
      -1,    11,    -1,    10,   305,   117,    -1,     4,    -1,   307,
     308,    -1,   118,    -1,   309,    -1,   310,    -1,    10,   119,
      -1,    11,    -1,    10,   311,   119,    -1,     4,    -1,   313,
     314,    -1,   120,    -1,   315,    -1,   316,    -1,    10,   121,
      -1,    11,    -1,    10,   317,   121,    -1,     4,    -1,   319,
     320,    -1,   122,    -1,   321,    -1,   322,    -1,    10,   123,
      -1,    11,    -1,    10,   323,   123,    -1,     4,    -1,   325,
     326,    -1,   124,    -1,   327,    -1,   328,    -1,    10,   125,
      -1,    11,    -1,    10,   329,   125,    -1,     4,    -1,   331,
     332,   334,    -1,   126,    -1,    -1,   333,    -1,    73,     3,
       8,    -1,   335,    -1,   336,    -1,    10,   127,    -1,    11,
      -1,    10,   337,   127,    -1,     4,    -1,   339,   340,   341,
      -1,   128,    -1,  1020,    -1,   342,    -1,   343,    -1,    10,
     129,    -1,    11,    -1,    10,   344,   129,    -1,   345,    -1,
     346,    -1,   345,   346,    -1,   347,   348,   351,    -1,   130,
      -1,   349,    -1,    -1,   349,   350,    -1,   971,    -1,  1002,
      -1,   950,    -1,    10,   131,    -1,    11,    -1,    -1,   353,
     354,    -1,    80,    -1,   355,    -1,   356,    -1,    10,    81,
      -1,    11,    -1,    10,   357,    81,    -1,   358,    -1,   359,
      -1,   358,   359,    -1,   360,    -1,   367,    -1,   374,    -1,
     381,    -1,   386,    -1,   361,   362,   365,    -1,   132,    -1,
     363,    -1,    -1,   363,   364,    -1,   998,    -1,   950,    -1,
      10,   366,   133,    -1,  1038,    -1,   368,   369,   372,    -1,
     134,    -1,   370,    -1,    -1,   370,   371,    -1,   998,    -1,
     950,    -1,    10,   373,   135,    -1,  1038,    -1,   375,   376,
     379,    -1,   136,    -1,   377,    -1,    -1,   377,   378,    -1,
     998,    -1,   950,    -1,    10,   380,   137,    -1,  1038,    -1,
     382,   383,   384,    -1,   138,    -1,    -1,   950,    -1,    10,
     385,   139,    -1,     6,    -1,   387,   388,   389,    -1,   128,
      -1,  1020,    -1,   390,    -1,   391,    -1,    10,   129,    -1,
      11,    -1,    10,   392,   129,    -1,   393,    -1,   394,    -1,
     393,   394,    -1,   395,   396,   399,    -1,   130,    -1,   397,
      -1,    -1,   397,   398,    -1,   971,    -1,  1002,    -1,   950,
      -1,    10,   131,    -1,    11,    -1,    -1,   401,   402,    -1,
      82,    -1,   403,    -1,   404,    -1,    10,    83,    -1,    11,
      -1,    10,   405,    83,    -1,   406,    -1,   407,    -1,   406,
     407,    -1,   408,    -1,   414,    -1,   409,   410,    -1,   140,
      -1,   411,    -1,   412,    -1,    10,   141,    -1,    11,    -1,
      10,   413,   141,    -1,     4,    -1,   415,   416,   417,    -1,
     128,    -1,  1020,    -1,   418,    -1,   419,    -1,    10,   129,
      -1,    11,    -1,    10,   420,   129,    -1,   421,    -1,   422,
      -1,   421,   422,    -1,   423,   424,   427,    -1,   130,    -1,
     425,    -1,    -1,   425,   426,    -1,   971,    -1,  1002,    -1,
     950,    -1,    10,   131,    -1,    11,    -1,    -1,   429,   430,
      -1,    84,    -1,   431,    -1,   432,    -1,    10,    85,    -1,
      11,    -1,    10,   433,    85,    -1,   434,    -1,   435,    -1,
     434,   435,    -1,   436,    -1,   444,    -1,   450,    -1,   458,
      -1,   463,    -1,   468,    -1,   473,    -1,   478,    -1,   486,
      -1,   502,    -1,   494,    -1,   510,    -1,   516,    -1,   522,
      -1,   530,    -1,   437,   438,   439,    -1,   142,    -1,    -1,
     998,    -1,   440,    -1,   441,    -1,    10,   143,    -1,    11,
      -1,    10,   442,   143,    -1,   443,    -1,  1038,    -1,   445,
     446,    -1,   144,    -1,   447,    -1,   448,    -1,    10,   145,
      -1,    11,    -1,    10,   449,   145,    -1,     4,    -1,   451,
     452,   453,    -1,   146,    -1,  1015,    -1,   454,    -1,   455,
      -1,    10,   147,    -1,    11,    -1,    10,   456,   147,    -1,
     457,    -1,   456,   457,    -1,   116,    10,     4,   117,    -1,
     459,  1023,   460,    -1,   148,    -1,   461,    -1,   462,    -1,
      10,   149,    -1,    11,    -1,    10,   931,   149,    -1,   464,
    1023,   465,    -1,   150,    -1,   466,    -1,   467,    -1,    10,
     151,    -1,    11,    -1,    10,   931,   151,    -1,   469,  1023,
     470,    -1,   156,    -1,   471,    -1,   472,    -1,    10,   157,
      -1,    11,    -1,    10,   931,   157,    -1,   474,  1023,   475,
      -1,   158,    -1,   476,    -1,   477,    -1,    10,   159,    -1,
      11,    -1,    10,   931,   159,    -1,   479,   480,   481,    -1,
     164,    -1,  1022,    -1,   482,    -1,   483,    -1,    10,   165,
      -1,    11,    -1,    10,   484,   165,    -1,   485,    -1,   484,
     485,    -1,   933,    -1,   487,   488,   489,    -1,   166,    -1,
    1022,    -1,   490,    -1,   491,    -1,    10,   167,    -1,    11,
      -1,    10,   492,   167,    -1,   493,    -1,   492,   493,    -1,
     933,    -1,   495,   496,   497,    -1,   170,    -1,  1022,    -1,
     498,    -1,   499,    -1,    10,   171,    -1,    11,    -1,    10,
     500,   171,    -1,   501,    -1,   500,   501,    -1,   933,    -1,
     503,   504,   505,    -1,   168,    -1,  1022,    -1,   506,    -1,
     507,    -1,    10,   169,    -1,    11,    -1,    10,   508,   169,
      -1,   509,    -1,   508,   509,    -1,   933,    -1,   511,   512,
     513,    -1,   162,    -1,  1023,    -1,   514,    -1,   515,    -1,
      10,   163,    -1,    11,    -1,    10,   931,   163,    -1,   517,
     518,   519,    -1,   160,    -1,  1023,    -1,   520,    -1,   521,
      -1,    10,   161,    -1,    11,    -1,    10,   931,   161,    -1,
     523,   524,   525,    -1,   172,    -1,  1024,    -1,   526,    -1,
     527,    -1,    10,   173,    -1,    11,    -1,    10,   528,   173,
      -1,   529,    -1,   528,   529,    -1,   174,    10,     4,   175,
      -1,   531,   532,   533,    -1,   128,    -1,  1020,    -1,   534,
      -1,   535,    -1,    10,   129,    -1,    11,    -1,    10,   536,
     129,    -1,   537,    -1,   538,    -1,   537,   538,    -1,   539,
     540,   543,    -1,   130,    -1,   541,    -1,    -1,   541,   542,
      -1,   971,    -1,  1002,    -1,   950,    -1,    10,   131,    -1,
      11,    -1,    -1,   545,   546,   549,    -1,    86,    -1,   547,
      -1,    -1,   547,   548,    -1,  1027,    -1,  1011,    -1,  1017,
      -1,   550,    -1,   551,    -1,    11,    -1,    10,   552,    87,
      -1,   553,   691,   800,   909,    -1,    -1,   554,   555,   557,
      -1,   176,    -1,   556,    -1,    -1,  1021,    -1,   558,    -1,
     559,    -1,    11,    -1,    10,   560,   177,    -1,   561,   575,
     589,   644,   658,   673,    -1,    -1,   562,   563,   564,    -1,
     178,    -1,  1026,    -1,   565,    -1,   566,    -1,    10,   179,
      -1,    11,    -1,    10,   567,   179,    -1,   568,    -1,   569,
      -1,   568,   569,    -1,   570,   571,   574,    -1,   180,    -1,
     572,    -1,    -1,   572,   573,    -1,   960,    -1,   971,    -1,
    1002,    -1,    10,   181,    -1,    11,    -1,    -1,   576,   577,
     578,    -1,   182,    -1,  1026,    -1,   579,    -1,   580,    -1,
      10,   183,    -1,    11,    -1,    10,   581,   183,    -1,   582,
      -1,   583,    -1,   582,   583,    -1,   584,   585,   588,    -1,
     180,    -1,   586,    -1,    -1,   586,   587,    -1,   960,    -1,
     971,    -1,  1002,    -1,    10,   181,    -1,    11,    -1,    -1,
     590,   591,    -1,   184,    -1,   592,    -1,   593,    -1,    11,
      -1,    10,   594,   185,    -1,   595,   602,   609,   616,   623,
     630,   637,    -1,    -1,   596,   597,   598,    -1,   186,    -1,
    1012,    -1,   599,    -1,   600,    -1,    11,    -1,    10,   601,
     187,    -1,  1070,    -1,    -1,   603,   604,   605,    -1,   190,
      -1,  1012,    -1,   606,    -1,   607,    -1,    11,    -1,    10,
     608,   191,    -1,  1070,    -1,    -1,   610,   611,   612,    -1,
     188,    -1,  1012,    -1,   613,    -1,   614,    -1,    11,    -1,
      10,   615,   189,    -1,  1070,    -1,    -1,   617,   618,   619,
      -1,   192,    -1,  1012,    -1,   620,    -1,   621,    -1,    11,
      -1,    10,   622,   193,    -1,  1070,    -1,    -1,   624,   625,
     626,    -1,   196,    -1,  1012,    -1,   627,    -1,   628,    -1,
      11,    -1,    10,   629,   197,    -1,  1070,    -1,    -1,   631,
     632,   633,    -1,   194,    -1,  1012,    -1,   634,    -1,   635,
      -1,    11,    -1,    10,   636,   195,    -1,  1070,    -1,    -1,
     638,   639,   640,    -1,   198,    -1,  1012,    -1,   641,    -1,
     642,    -1,    11,    -1,    10,   643,   199,    -1,  1070,    -1,
      -1,   645,   646,   647,    -1,   200,    -1,  1026,    -1,   648,
      -1,   649,    -1,    10,   201,    -1,    11,    -1,    10,   650,
     201,    -1,   651,    -1,   652,    -1,   651,   652,    -1,   653,
     654,   657,    -1,   180,    -1,   655,    -1,    -1,   655,   656,
      -1,   960,    -1,   971,    -1,  1002,    -1,    10,   181,    -1,
      11,    -1,    -1,   659,   660,   661,    -1,   202,    -1,    29,
       8,     6,     8,    -1,   662,    -1,   663,    -1,    10,   203,
      -1,    11,    -1,    10,   664,   203,    -1,   665,    -1,   664,
     665,    -1,   666,   667,   670,    -1,   204,    -1,   668,    -1,
      -1,   668,   669,    -1,   983,    -1,  1026,    -1,   958,    -1,
     671,    -1,   672,    -1,    10,   205,    -1,    11,    -1,    10,
     651,   205,    -1,    -1,   673,   674,    -1,   675,   676,   679,
      -1,   130,    -1,   677,    -1,    -1,   677,   678,    -1,  1026,
      -1,  1013,    -1,   971,    -1,  1002,    -1,   979,    -1,   942,
      -1,   986,    -1,  1006,    -1,   954,    -1,   950,    -1,   680,
      -1,   681,    -1,    10,   131,    -1,    11,    -1,    10,   682,
     131,    -1,   683,    -1,  1028,    -1,   684,    -1,   683,   684,
      -1,   685,   686,   689,    -1,   180,    -1,   687,    -1,    -1,
     687,   688,    -1,   960,    -1,   971,    -1,  1002,    -1,   963,
      -1,   990,    -1,   690,    -1,    10,   181,    -1,    11,    -1,
      -1,   692,   693,   695,    -1,   206,    -1,   694,    -1,    -1,
    1019,    -1,   696,    -1,   697,    -1,    11,    -1,    10,   698,
     207,    -1,   699,   713,   727,   782,    -1,    -1,   700,   701,
     702,    -1,   208,    -1,  1016,    -1,   703,    -1,   704,    -1,
      10,   209,    -1,    11,    -1,    10,   705,   209,    -1,   706,
      -1,   707,    -1,   706,   707,    -1,   708,   709,   712,    -1,
     210,    -1,   710,    -1,    -1,   710,   711,    -1,   960,    -1,
     971,    -1,  1002,    -1,    10,   211,    -1,    11,    -1,    -1,
     714,   715,   716,    -1,   212,    -1,  1016,    -1,   717,    -1,
     718,    -1,    10,   213,    -1,    11,    -1,    10,   719,   213,
      -1,   720,    -1,   721,    -1,   720,   721,    -1,   722,   723,
     726,    -1,   210,    -1,   724,    -1,    -1,   724,   725,    -1,
     960,    -1,   971,    -1,   963,    -1,   990,    -1,    10,   211,
      -1,    11,    -1,    -1,   728,   729,    -1,   184,    -1,   730,
      -1,   731,    -1,    11,    -1,    10,   732,   185,    -1,   733,
     740,   747,   754,   761,   768,   775,    -1,    -1,   734,   735,
     736,    -1,   186,    -1,  1012,    -1,   737,    -1,   738,    -1,
      11,    -1,    10,   739,   187,    -1,  1070,    -1,    -1,   741,
     742,   743,    -1,   190,    -1,  1012,    -1,   744,    -1,   745,
      -1,    11,    -1,    10,   746,   191,    -1,  1070,    -1,    -1,
     748,   749,   750,    -1,   188,    -1,  1012,    -1,   751,    -1,
     752,    -1,    11,    -1,    10,   753,   189,    -1,  1070,    -1,
      -1,   755,   756,   757,    -1,   192,    -1,  1012,    -1,   758,
      -1,   759,    -1,    11,    -1,    10,   760,   193,    -1,  1070,
      -1,    -1,   762,   763,   764,    -1,   196,    -1,  1012,    -1,
     765,    -1,   766,    -1,    11,    -1,    10,   767,   197,    -1,
    1070,    -1,    -1,   769,   770,   771,    -1,   194,    -1,  1012,
      -1,   772,    -1,   773,    -1,    11,    -1,    10,   774,   195,
      -1,  1070,    -1,    -1,   776,   777,   778,    -1,   198,    -1,
    1012,    -1,   779,    -1,   780,    -1,    11,    -1,    10,   781,
     199,    -1,  1070,    -1,    -1,   782,   783,    -1,   784,   785,
     788,    -1,   130,    -1,   786,    -1,    -1,   786,   787,    -1,
    1016,    -1,  1013,    -1,   971,    -1,  1002,    -1,   979,    -1,
     942,    -1,   986,    -1,   975,    -1,   954,    -1,   950,    -1,
     789,    -1,   790,    -1,    10,   131,    -1,    11,    -1,    10,
     791,   131,    -1,   792,    -1,  1028,    -1,   793,    -1,   792,
     793,    -1,   794,   795,   798,    -1,   210,    -1,   796,    -1,
      -1,   796,   797,    -1,   960,    -1,   971,    -1,  1002,    -1,
     963,    -1,   990,    -1,   799,    -1,    10,   211,    -1,    11,
      -1,    -1,   801,   802,   804,    -1,   214,    -1,   803,    -1,
      -1,  1018,    -1,   805,    -1,   806,    -1,    11,    -1,    10,
     807,   215,    -1,   808,   822,   836,   891,    -1,    -1,   809,
     810,   811,    -1,   216,    -1,  1010,    -1,   812,    -1,   813,
      -1,    10,   217,    -1,    11,    -1,    10,   814,   217,    -1,
     815,    -1,   816,    -1,   815,   816,    -1,   817,   818,   821,
      -1,   218,    -1,   819,    -1,    -1,   819,   820,    -1,   960,
      -1,   971,    -1,  1002,    -1,    10,   219,    -1,    11,    -1,
      -1,   823,   824,   825,    -1,   220,    -1,  1010,    -1,   826,
      -1,   827,    -1,    10,   221,    -1,    11,    -1,    10,   828,
     221,    -1,   829,    -1,   830,    -1,   829,   830,    -1,   831,
     832,   835,    -1,   218,    -1,   833,    -1,    -1,   833,   834,
      -1,   960,    -1,   971,    -1,   967,    -1,   994,    -1,    10,
     219,    -1,    11,    -1,    -1,   837,   838,    -1,   184,    -1,
     839,    -1,   840,    -1,    11,    -1,    10,   841,   185,    -1,
     842,   849,   856,   863,   870,   877,   884,    -1,    -1,   843,
     844,   845,    -1,   186,    -1,  1012,    -1,   846,    -1,   847,
      -1,    11,    -1,    10,   848,   187,    -1,  1070,    -1,    -1,
     850,   851,   852,    -1,   190,    -1,  1012,    -1,   853,    -1,
     854,    -1,    11,    -1,    10,   855,   191,    -1,  1070,    -1,
      -1,   857,   858,   859,    -1,   188,    -1,  1012,    -1,   860,
      -1,   861,    -1,    11,    -1,    10,   862,   189,    -1,  1070,
      -1,    -1,   864,   865,   866,    -1,   192,    -1,  1012,    -1,
     867,    -1,   868,    -1,    11,    -1,    10,   869,   193,    -1,
    1070,    -1,    -1,   871,   872,   873,    -1,   196,    -1,  1012,
      -1,   874,    -1,   875,    -1,    11,    -1,    10,   876,   197,
      -1,  1070,    -1,    -1,   878,   879,   880,    -1,   194,    -1,
    1012,    -1,   881,    -1,   882,    -1,    11,    -1,    10,   883,
     195,    -1,  1070,    -1,    -1,   885,   886,   887,    -1,   198,
      -1,  1012,    -1,   888,    -1,   889,    -1,    11,    -1,    10,
     890,   199,    -1,  1070,    -1,    -1,   891,   892,    -1,   893,
     894,   897,    -1,   130,    -1,   895,    -1,    -1,   895,   896,
      -1,  1010,    -1,  1013,    -1,   971,    -1,  1002,    -1,   979,
      -1,   942,    -1,   986,    -1,   946,    -1,   954,    -1,   950,
      -1,   898,    -1,   899,    -1,    10,   131,    -1,    11,    -1,
      10,   900,   131,    -1,   901,    -1,  1028,    -1,   902,    -1,
     901,   902,    -1,   903,   904,   907,    -1,   218,    -1,   905,
      -1,    -1,   905,   906,    -1,   960,    -1,   971,    -1,  1002,
      -1,   963,    -1,   990,    -1,   908,    -1,    10,   219,    -1,
      11,    -1,    -1,   910,   911,   912,    -1,   222,    -1,  1025,
      -1,   913,    -1,   914,    -1,    11,    -1,    10,   915,   223,
      -1,    -1,   915,   916,    -1,   917,   918,   921,    -1,   224,
      -1,   919,    -1,   920,    -1,   919,   920,    -1,   971,    -1,
    1002,    -1,   979,    -1,   942,    -1,   986,    -1,   950,    -1,
    1014,    -1,   922,    -1,   923,    -1,    10,   225,    -1,    11,
      -1,    10,   924,   225,    -1,   925,    -1,   926,    -1,   925,
     926,    -1,   927,    -1,   928,    -1,   929,    -1,   231,    -1,
     228,    -1,   229,   930,   230,    -1,     5,    -1,   932,    -1,
     931,   932,    -1,   152,    10,     4,   153,    -1,   934,   935,
     941,    -1,   154,    -1,   936,    -1,    -1,   936,   937,    -1,
     938,    -1,   939,    -1,   940,    -1,    21,     3,     8,    -1,
      22,     3,     8,    -1,    23,     3,     8,    -1,    10,   155,
      -1,    11,    -1,   943,    -1,   944,    -1,   945,    -1,    57,
      -1,    24,     3,  1039,    -1,   947,    -1,   948,    -1,   949,
      -1,    48,    -1,    47,     3,     8,    -1,   951,    -1,   952,
      -1,   953,    -1,    58,    -1,    46,     3,  1039,    -1,   955,
      -1,   956,    -1,   957,    -1,    50,    -1,    49,     3,     8,
      -1,   959,    -1,    26,     8,  1038,     8,    -1,   961,    -1,
     962,    -1,    42,  1039,     6,  1039,    -1,   964,    -1,   965,
      -1,   966,    -1,    61,    -1,    63,     3,  1039,    -1,   968,
      -1,   969,    -1,   970,    -1,    65,    -1,    67,  1039,  1038,
    1039,    -1,   972,    -1,   973,    -1,   974,    -1,    56,    -1,
      41,     3,  1039,    -1,   976,    -1,   977,    -1,   978,    -1,
      52,    -1,    51,     3,     8,    -1,   980,    -1,   981,    -1,
     982,    -1,    70,    -1,    69,     3,  1039,    -1,   984,    -1,
     985,    -1,    43,  1039,     6,  1039,    -1,   987,    -1,   988,
      -1,   989,    -1,    55,    -1,    25,     3,     8,    -1,   991,
      -1,   992,    -1,   993,    -1,    62,    -1,    64,     3,  1039,
      -1,   995,    -1,   996,    -1,   997,    -1,    66,    -1,    68,
    1039,  1038,  1039,    -1,   999,    -1,  1000,    -1,  1001,    -1,
      59,    -1,    45,     3,     8,    -1,  1003,    -1,  1004,    -1,
    1005,    -1,    60,    -1,    44,     3,     8,    -1,  1007,    -1,
    1008,    -1,  1009,    -1,    54,    -1,    53,     3,     8,    -1,
      39,  1039,     6,  1039,    -1,    32,  1039,     6,  1039,    -1,
      40,  1039,     6,  1039,    -1,    17,  1039,     6,  1039,    -1,
      36,  1039,     6,  1039,    -1,    18,     8,     6,     8,    -1,
      38,  1039,     6,  1039,    -1,    31,  1039,     6,  1039,    -1,
      35,  1039,     6,  1039,    -1,    34,  1039,     6,  1039,    -1,
      16,  1039,     6,  1039,    -1,    33,  1039,     6,  1039,    -1,
      20,     8,     6,     8,    -1,    19,     8,     6,     8,    -1,
      27,     8,     6,     8,    -1,    28,  1039,     6,  1039,    -1,
      37,  1039,     6,  1039,    -1,    30,  1039,     6,  1039,    -1,
    1029,    -1,  1028,  1029,    -1,  1030,  1031,  1034,    -1,   226,
      -1,  1032,    -1,    -1,  1032,  1033,    -1,  1012,    -1,  1002,
      -1,   950,    -1,  1035,    -1,  1036,    -1,    11,    -1,    10,
    1037,   227,    -1,  1070,    -1,     6,    -1,     7,    -1,  1040,
       8,    -1,    -1,  1040,  1041,    -1,   250,    -1,   251,    -1,
     252,    -1,   253,    -1,  1043,  1044,    -1,    76,    -1,  1045,
      -1,  1046,    -1,    10,    77,    -1,    11,    -1,    10,  1047,
      77,    -1,  1048,    -1,  1049,    -1,  1048,  1049,    -1,  1050,
      -1,  1054,    -1,  1058,    -1,  1062,    -1,  1066,    -1,    -1,
    1051,    -1,  1052,    -1,  1053,    -1,    91,    -1,    90,    -1,
      88,     5,    89,    -1,    -1,  1055,    -1,  1056,    -1,  1057,
      -1,    95,    -1,    94,    -1,    92,     5,    93,    -1,    -1,
    1059,    -1,  1060,    -1,  1061,    -1,    99,    -1,    98,    -1,
      96,     5,    97,    -1,    -1,  1063,    -1,  1064,    -1,  1065,
      -1,   103,    -1,   102,    -1,   100,     5,   101,    -1,    -1,
    1067,    -1,  1068,    -1,  1069,    -1,   107,    -1,   106,    -1,
     104,     5,   105,    -1,  1071,    -1,  1078,    -1,    -1,  1071,
    1072,    -1,  1073,  1074,  1077,    -1,   237,    -1,  1075,    -1,
      -1,  1075,  1076,    -1,  1084,    -1,  1083,    -1,    10,     6,
     238,    -1,   232,  1079,  1080,    -1,   236,  1039,     6,  1039,
      -1,  1081,    -1,  1082,    -1,    10,   233,    -1,    11,    -1,
      10,     4,   233,    -1,   234,  1039,     6,  1039,    -1,   235,
    1039,     6,  1039,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   180,   180,   181,   183,   190,   200,   200,   202,   202,
     204,   206,   208,   217,   218,   221,   229,   229,   242,   242,
     244,   260,   260,   262,   262,   264,   266,   268,   268,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     285,   287,   296,   296,   298,   298,   300,   302,   312,   314,
     321,   321,   323,   323,   325,   327,   337,   339,   345,   345,
     347,   347,   349,   351,   361,   368,   376,   377,   384,   390,
     390,   392,   392,   394,   396,   404,   406,   412,   412,   414,
     414,   416,   418,   427,   429,   436,   436,   438,   438,   440,
     442,   452,   454,   461,   461,   463,   463,   465,   467,   477,
     479,   485,   485,   487,   487,   489,   491,   501,   503,   509,
     509,   511,   511,   513,   515,   525,   532,   541,   542,   548,
     555,   555,   557,   557,   559,   561,   569,   575,   585,   593,
     598,   604,   604,   606,   608,   612,   612,   614,   622,   641,
     647,   647,   650,   654,   655,   658,   658,   667,   667,   669,
     679,   679,   681,   681,   683,   685,   687,   687,   690,   691,
     692,   693,   694,   698,   700,   710,   712,   712,   715,   716,
     719,   721,   729,   731,   741,   743,   743,   746,   747,   750,
     752,   761,   763,   773,   775,   775,   778,   779,   782,   784,
     793,   795,   803,   804,   806,   808,   819,   825,   835,   843,
     847,   852,   852,   854,   856,   860,   860,   862,   870,   889,
     894,   894,   897,   902,   903,   906,   906,   915,   915,   917,
     924,   924,   926,   926,   928,   930,   932,   932,   935,   936,
     940,   942,   948,   948,   950,   950,   952,   954,   965,   971,
     981,   989,   993,   998,   998,  1000,  1002,  1006,  1006,  1008,
    1016,  1035,  1040,  1040,  1043,  1048,  1049,  1052,  1052,  1060,
    1060,  1062,  1082,  1082,  1084,  1084,  1086,  1088,  1090,  1090,
    1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1112,  1118,  1128,  1129,  1131,
    1131,  1133,  1133,  1135,  1137,  1139,  1146,  1148,  1154,  1154,
    1156,  1156,  1158,  1160,  1170,  1181,  1191,  1193,  1193,  1195,
    1195,  1197,  1206,  1206,  1208,  1229,  1240,  1250,  1250,  1252,
    1252,  1254,  1265,  1276,  1286,  1286,  1288,  1288,  1290,  1301,
    1312,  1322,  1322,  1324,  1324,  1326,  1337,  1348,  1358,  1358,
    1360,  1360,  1362,  1373,  1389,  1399,  1401,  1401,  1403,  1403,
    1405,  1414,  1414,  1416,  1420,  1436,  1446,  1448,  1448,  1450,
    1450,  1452,  1461,  1461,  1463,  1467,  1483,  1493,  1495,  1495,
    1497,  1497,  1499,  1508,  1508,  1510,  1514,  1530,  1540,  1542,
    1542,  1544,  1544,  1546,  1555,  1555,  1557,  1561,  1572,  1582,
    1584,  1584,  1586,  1586,  1588,  1599,  1610,  1620,  1622,  1622,
    1624,  1624,  1626,  1651,  1662,  1672,  1674,  1674,  1676,  1676,
    1678,  1687,  1687,  1689,  1710,  1716,  1726,  1734,  1738,  1743,
    1743,  1745,  1747,  1751,  1751,  1753,  1761,  1780,  1786,  1786,
    1789,  1794,  1795,  1798,  1798,  1806,  1806,  1808,  1816,  1818,
    1818,  1821,  1827,  1833,  1841,  1841,  1843,  1845,  1847,  1854,
    1854,  1856,  1862,  1869,  1869,  1874,  1874,  1876,  1878,  1880,
    1890,  1890,  1905,  1910,  1921,  1929,  1938,  1938,  1940,  1942,
    1944,  1944,  1947,  1952,  1966,  1972,  1972,  1975,  1987,  1992,
    2000,  2000,  2004,  2004,  2019,  2024,  2035,  2043,  2052,  2052,
    2054,  2056,  2058,  2058,  2061,  2066,  2081,  2087,  2087,  2090,
    2102,  2107,  2113,  2113,  2117,  2117,  2119,  2124,  2124,  2126,
    2128,  2130,  2133,  2133,  2144,  2150,  2157,  2157,  2159,  2161,
    2163,  2167,  2167,  2179,  2185,  2192,  2192,  2194,  2196,  2198,
    2202,  2202,  2213,  2219,  2226,  2226,  2228,  2230,  2232,  2236,
    2236,  2247,  2253,  2260,  2260,  2262,  2264,  2266,  2270,  2270,
    2281,  2287,  2294,  2294,  2296,  2298,  2300,  2304,  2304,  2315,
    2321,  2328,  2328,  2330,  2332,  2334,  2338,  2338,  2349,  2355,
    2362,  2362,  2364,  2366,  2368,  2372,  2372,  2388,  2393,  2404,
    2412,  2421,  2421,  2423,  2425,  2431,  2431,  2433,  2438,  2454,
    2460,  2460,  2463,  2475,  2480,  2488,  2488,  2492,  2492,  2498,
    2504,  2512,  2520,  2528,  2528,  2530,  2532,  2532,  2534,  2553,
    2569,  2577,  2577,  2580,  2581,  2590,  2593,  2593,  2595,  2595,
    2597,  2602,  2602,  2604,  2609,  2640,  2660,  2660,  2663,  2667,
    2671,  2672,  2673,  2674,  2675,  2676,  2677,  2678,  2681,  2681,
    2683,  2683,  2685,  2687,  2687,  2689,  2689,  2692,  2707,  2727,
    2729,  2729,  2732,  2742,  2743,  2744,  2745,  2748,  2750,  2750,
    2758,  2758,  2760,  2766,  2773,  2773,  2778,  2778,  2780,  2782,
    2784,  2793,  2793,  2809,  2815,  2827,  2835,  2844,  2844,  2846,
    2848,  2850,  2850,  2853,  2858,  2873,  2875,  2875,  2878,  2889,
    2893,  2900,  2900,  2903,  2903,  2921,  2926,  2940,  2948,  2957,
    2957,  2959,  2961,  2963,  2963,  2966,  2971,  2989,  2991,  2991,
    2994,  3005,  3009,  3015,  3022,  3022,  3026,  3026,  3028,  3033,
    3033,  3035,  3037,  3039,  3042,  3042,  3053,  3059,  3066,  3066,
    3068,  3070,  3072,  3075,  3075,  3086,  3092,  3099,  3099,  3101,
    3103,  3105,  3108,  3108,  3119,  3125,  3132,  3132,  3134,  3136,
    3138,  3141,  3141,  3152,  3158,  3165,  3165,  3167,  3169,  3171,
    3174,  3174,  3185,  3191,  3198,  3198,  3200,  3202,  3204,  3207,
    3207,  3218,  3225,  3232,  3232,  3234,  3236,  3238,  3242,  3242,
    3253,  3259,  3266,  3266,  3268,  3270,  3272,  3276,  3276,  3278,
    3284,  3315,  3336,  3336,  3339,  3343,  3347,  3348,  3349,  3350,
    3351,  3352,  3353,  3354,  3357,  3357,  3359,  3359,  3361,  3363,
    3363,  3365,  3365,  3368,  3383,  3405,  3407,  3407,  3410,  3420,
    3421,  3422,  3423,  3426,  3428,  3428,  3436,  3436,  3438,  3444,
    3451,  3451,  3456,  3456,  3458,  3460,  3462,  3471,  3471,  3487,
    3492,  3503,  3511,  3520,  3520,  3522,  3524,  3526,  3526,  3529,
    3534,  3549,  3555,  3555,  3558,  3569,  3573,  3580,  3580,  3584,
    3584,  3602,  3607,  3620,  3628,  3637,  3637,  3639,  3641,  3643,
    3643,  3646,  3651,  3669,  3675,  3675,  3678,  3689,  3693,  3697,
    3703,  3703,  3707,  3707,  3709,  3714,  3714,  3716,  3718,  3720,
    3723,  3723,  3734,  3740,  3747,  3747,  3749,  3751,  3753,  3756,
    3756,  3767,  3773,  3780,  3780,  3782,  3784,  3786,  3790,  3790,
    3801,  3807,  3814,  3814,  3816,  3818,  3820,  3824,  3824,  3835,
    3841,  3848,  3848,  3850,  3852,  3854,  3858,  3858,  3869,  3875,
    3882,  3882,  3884,  3886,  3888,  3892,  3892,  3903,  3909,  3916,
    3916,  3918,  3920,  3922,  3926,  3926,  3937,  3943,  3950,  3950,
    3952,  3954,  3956,  3960,  3960,  3962,  3968,  3999,  4019,  4019,
    4022,  4026,  4030,  4031,  4032,  4033,  4034,  4035,  4036,  4037,
    4040,  4040,  4042,  4042,  4044,  4046,  4046,  4048,  4048,  4051,
    4066,  4086,  4088,  4088,  4091,  4101,  4102,  4103,  4104,  4107,
    4109,  4109,  4117,  4117,  4123,  4125,  4133,  4141,  4150,  4152,
    4154,  4154,  4158,  4178,  4196,  4202,  4202,  4205,  4206,  4207,
    4208,  4209,  4210,  4211,  4218,  4226,  4235,  4235,  4237,  4239,
    4241,  4241,  4243,  4250,  4261,  4263,  4263,  4265,  4267,  4284,
    4284,  4286,  4308,  4325,  4337,  4342,  4342,  4345,  4346,  4347,
    4349,  4358,  4367,  4376,  4376,  4382,  4389,  4389,  4391,  4396,
    4403,  4409,  4409,  4411,  4414,  4421,  4428,  4428,  4430,  4433,
    4440,  4446,  4446,  4448,  4451,  4459,  4466,  4473,  4480,  4482,
    4488,  4495,  4495,  4497,  4502,  4509,  4515,  4515,  4517,  4522,
    4528,  4535,  4535,  4537,  4542,  4549,  4555,  4555,  4557,  4560,
    4568,  4574,  4574,  4576,  4579,  4586,  4592,  4594,  4602,  4608,
    4608,  4610,  4613,  4620,  4627,  4627,  4629,  4634,  4641,  4647,
    4647,  4649,  4652,  4659,  4665,  4665,  4667,  4670,  4677,  4683,
    4683,  4685,  4688,  4695,  4701,  4701,  4703,  4706,  4718,  4727,
    4736,  4745,  4754,  4763,  4773,  4782,  4791,  4797,  4803,  4809,
    4815,  4829,  4839,  4850,  4856,  4865,  4886,  4886,  4888,  4906,
    4922,  4930,  4930,  4933,  4940,  4941,  4945,  4945,  4947,  4950,
    4952,  4956,  4957,  4964,  4966,  4966,  4968,  4969,  4970,  4971,
    5003,  5005,  5019,  5019,  5021,  5021,  5023,  5025,  5027,  5027,
    5030,  5031,  5032,  5033,  5034,  5036,  5036,  5044,  5044,  5046,
    5046,  5048,  5054,  5054,  5062,  5062,  5064,  5064,  5066,  5072,
    5072,  5080,  5080,  5082,  5082,  5084,  5090,  5090,  5098,  5098,
    5100,  5100,  5102,  5108,  5108,  5116,  5116,  5118,  5118,  5120,
    5132,  5140,  5142,  5142,  5144,  5146,  5155,  5157,  5157,  5159,
    5159,  5161,  5177,  5179,  5184,  5184,  5186,  5186,  5189,  5215,
    5223
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "GREATERTHAN",
  "ENDOFELEMENT", "OSOLSTART", "OSOLSTARTEMPTY", "OSOLATTRIBUTETEXT",
  "OSOLEND", "NUMBEROFOTHEROPTIONSATT", "NUMBEROFENUMERATIONSATT",
  "NUMBEROFJOBIDSATT", "NUMBEROFPATHSATT", "NUMBEROFPATHPAIRSATT",
  "FROMATT", "TOATT", "MAKECOPYATT", "CATEGORYATT", "TYPEATT",
  "GROUPWEIGHTATT", "NUMBEROFPROCESSESATT", "NUMBEROFSOLVEROPTIONSATT",
  "NUMBEROFSOSATT", "NUMBEROFVARIABLESATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFCONSTRAINTSATT", "NUMBEROFOTHERVARIABLEOPTIONSATT",
  "NUMBEROFOTHEROBJECTIVEOPTIONSATT", "NUMBEROFOTHERCONSTRAINTOPTIONSATT",
  "NUMBEROFITEMSATT", "NUMBEROFVARATT", "NUMBEROFOBJATT", "NUMBEROFCONATT",
  "NUMBEROFELATT", "NAMEATT", "IDXATT", "SOSIDXATT", "VALUEATT", "UNITATT",
  "DESCRIPTIONATT", "CONTYPEATT", "EMPTYCONTYPEATT", "ENUMTYPEATT",
  "EMPTYENUMTYPEATT", "OBJTYPEATT", "EMPTYOBJTYPEATT", "VARTYPEATT",
  "EMPTYVARTYPEATT", "EMPTYTYPEATT", "EMPTYNAMEATT", "EMPTYCATEGORYATT",
  "EMPTYDESCRIPTIONATT", "EMPTYUNITATT", "EMPTYVALUEATT",
  "EMPTYLBVALUEATT", "EMPTYUBVALUEATT", "LBVALUEATT", "UBVALUEATT",
  "EMPTYLBDUALVALUEATT", "EMPTYUBDUALVALUEATT", "LBDUALVALUEATT",
  "UBDUALVALUEATT", "SOLVERATT", "EMPTYSOLVERATT", "WEIGHTATT",
  "EMPTYWEIGHTATT", "TRANSPORTTYPEATT", "LOCATIONTYPEATT", "SYMMETRYATT",
  "HEADERSTART", "HEADEREND", "GENERALSTART", "GENERALEND", "SYSTEMSTART",
  "SYSTEMEND", "SERVICESTART", "SERVICEEND", "JOBSTART", "JOBEND",
  "OPTIMIZATIONSTART", "OPTIMIZATIONEND", "FILENAMESTART", "FILENAMEEND",
  "FILENAMEEMPTY", "FILENAMESTARTANDEND", "FILESOURCESTART",
  "FILESOURCEEND", "FILESOURCEEMPTY", "FILESOURCESTARTANDEND",
  "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
  "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART", "FILECREATOREND",
  "FILECREATOREMPTY", "FILECREATORSTARTANDEND", "FILELICENCESTART",
  "FILELICENCEEND", "FILELICENCEEMPTY", "FILELICENCESTARTANDEND",
  "SERVICEURISTART", "SERVICEURIEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "INSTANCENAMESTART", "INSTANCENAMEEND", "INSTANCELOCATIONSTART",
  "INSTANCELOCATIONEND", "JOBIDSTART", "JOBIDEND", "SOLVERTOINVOKESTART",
  "SOLVERTOINVOKEEND", "LICENSESTART", "LICENSEEND", "USERNAMESTART",
  "USERNAMEEND", "PASSWORDSTART", "PASSWORDEND", "CONTACTSTART",
  "CONTACTEND", "OTHEROPTIONSSTART", "OTHEROPTIONSEND", "OTHERSTART",
  "OTHEREND", "MINDISKSPACESTART", "MINDISKSPACEEND", "MINMEMORYSTART",
  "MINMEMORYEND", "MINCPUSPEEDSTART", "MINCPUSPEEDEND",
  "MINCPUNUMBERSTART", "MINCPUNUMBEREND", "SERVICETYPESTART",
  "SERVICETYPEEND", "MAXTIMESTART", "MAXTIMEEND",
  "REQUESTEDSTARTTIMESTART", "REQUESTEDSTARTTIMEEND", "DEPENDENCIESSTART",
  "DEPENDENCIESEND", "REQUIREDDIRECTORIESSTART", "REQUIREDDIRECTORIESEND",
  "REQUIREDFILESSTART", "REQUIREDFILESEND", "PATHSTART", "PATHEND",
  "PATHPAIRSTART", "PATHPAIREND", "DIRECTORIESTOMAKESTART",
  "DIRECTORIESTOMAKEEND", "FILESTOMAKESTART", "FILESTOMAKEEND",
  "DIRECTORIESTODELETESTART", "DIRECTORIESTODELETEEND",
  "FILESTODELETESTART", "FILESTODELETEEND", "INPUTDIRECTORIESTOMOVESTART",
  "INPUTDIRECTORIESTOMOVEEND", "INPUTFILESTOMOVESTART",
  "INPUTFILESTOMOVEEND", "OUTPUTDIRECTORIESTOMOVESTART",
  "OUTPUTDIRECTORIESTOMOVEEND", "OUTPUTFILESTOMOVESTART",
  "OUTPUTFILESTOMOVEEND", "PROCESSESTOKILLSTART", "PROCESSESTOKILLEND",
  "PROCESSSTART", "PROCESSEND", "VARIABLESSTART", "VARIABLESEND",
  "INITIALVARIABLEVALUESSTART", "INITIALVARIABLEVALUESEND", "VARSTART",
  "VAREND", "INITIALVARIABLEVALUESSTRINGSTART",
  "INITIALVARIABLEVALUESSTRINGEND", "INITIALBASISSTATUSSTART",
  "INITIALBASISSTATUSEND", "BASICSTART", "BASICEND", "ATUPPERSTART",
  "ATUPPEREND", "ATLOWERSTART", "ATLOWEREND", "ATEQUALITYSTART",
  "ATEQUALITYEND", "SUPERBASICSTART", "SUPERBASICEND", "ISFREESTART",
  "ISFREEEND", "UNKNOWNSTART", "UNKNOWNEND",
  "INTEGERVARIABLEBRANCHINGWEIGHTSSTART",
  "INTEGERVARIABLEBRANCHINGWEIGHTSEND", "SOSVARIABLEBRANCHINGWEIGHTSSTART",
  "SOSVARIABLEBRANCHINGWEIGHTSEND", "SOSSTART", "SOSEND",
  "OBJECTIVESSTART", "OBJECTIVESEND", "INITIALOBJECTIVEVALUESSTART",
  "INITIALOBJECTIVEVALUESEND", "OBJSTART", "OBJEND",
  "INITIALOBJECTIVEBOUNDSSTART", "INITIALOBJECTIVEBOUNDSEND",
  "CONSTRAINTSSTART", "CONSTRAINTSEND", "INITIALCONSTRAINTVALUESSTART",
  "INITIALCONSTRAINTVALUESEND", "CONSTART", "CONEND",
  "INITIALDUALVALUESSTART", "INITIALDUALVALUESEND", "SOLVEROPTIONSSTART",
  "SOLVEROPTIONSEND", "SOLVEROPTIONSTART", "SOLVEROPTIONEND",
  "ENUMERATIONSTART", "ENUMERATIONEND", "ITEMEMPTY", "ITEMSTART",
  "ITEMEND", "ITEMSTARTANDEND", "BASE64START", "BASE64END", "INCRATT",
  "MULTATT", "SIZEOFATT", "ELSTART", "ELEND", "MATRIXSTART", "MATRIXEND",
  "BASEMATRIXEND", "BASEMATRIXSTART", "BLOCKSTART", "BLOCKEND",
  "BLOCKSSTART", "BLOCKSEND", "EMPTYSYMMETRYATT", "NUMBEROFBLOCKSATT",
  "DUMMY", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept", "osoldoc",
  "osolStartEmpty", "osolStart", "osolAttributes", "osolContent",
  "osolEmpty", "osolLaden", "osolEnd", "osolEnding", "osolBody",
  "headerElement", "generalElement", "generalElementStart",
  "generalElementContent", "generalElementEmpty", "generalElementLaden",
  "generalElementBody", "generalElementList", "generalChild", "serviceURI",
  "serviceURIStart", "serviceURIContent", "serviceURIEmpty",
  "serviceURILaden", "serviceURIBody", "serviceName", "serviceNameStart",
  "serviceNameContent", "serviceNameEmpty", "serviceNameLaden",
  "serviceNameBody", "instanceName", "instanceNameStart",
  "instanceNameContent", "instanceNameEmpty", "instanceNameLaden",
  "instanceNameBody", "instanceLocation", "instanceLocationStart",
  "instanceLocationAttributes", "locationTypeAttribute",
  "instanceLocationContent", "instanceLocationEmpty",
  "instanceLocationLaden", "instanceLocationBody", "jobID", "jobIDStart",
  "jobIDContent", "jobIDEmpty", "jobIDLaden", "jobIDBody",
  "solverToInvoke", "solverToInvokeStart", "solverToInvokeContent",
  "solverToInvokeEmpty", "solverToInvokeLaden", "solverToInvokeBody",
  "license", "licenseStart", "licenseContent", "licenseEmpty",
  "licenseLaden", "licensebody", "username", "usernameStart",
  "usernameContent", "usernameEmpty", "usernameLaden", "usernamebody",
  "password", "passwordStart", "passwordContent", "passwordEmpty",
  "passwordLaden", "passwordbody", "contact", "contactStart",
  "contactAttributes", "transportTypeAttribute", "contactContent",
  "contactContentEmpty", "contactContentLaden", "contactBody",
  "otherGeneralOptions", "otherGeneralOptionsStart",
  "otherGeneralOptionsAttributes", "otherGeneralOptionsContent",
  "otherGeneralOptionsEmpty", "otherGeneralOptionsLaden",
  "otherGeneralOptionsBody", "otherGeneralOptionArray",
  "otherGeneralOption", "otherGeneralOptionStart",
  "otherGeneralAttributes", "otherGeneralAttList", "otherGeneralAtt",
  "otherGeneralEnd", "systemElement", "systemElementStart",
  "systemElementContent", "systemElementEmpty", "systemElementLaden",
  "systemElementBody", "systemElementList", "systemChild", "minDiskSpace",
  "minDiskSpaceStart", "minDiskSpaceAttributes", "minDiskSpaceAttList",
  "minDiskSpaceAtt", "minDiskSpaceContent", "minDiskSpaceValue",
  "minMemorySize", "minMemoryStart", "minMemoryAttributes",
  "minMemoryAttList", "minMemoryAtt", "minMemoryContent", "minMemoryValue",
  "minCPUSpeed", "minCPUSpeedStart", "minCPUSpeedAttributes",
  "minCPUSpeedAttList", "minCPUSpeedAtt", "minCPUSpeedContent",
  "minCPUSpeedValue", "minCPUNumber", "minCPUNumberStart",
  "minCPUNumberAttributes", "minCPUNumberContent", "minCPUNumberValue",
  "otherSystemOptions", "otherSystemOptionsStart",
  "otherSystemOptionsAttributes", "otherSystemOptionsContent",
  "otherSystemOptionsEmpty", "otherSystemOptionsLaden",
  "otherSystemOptionsBody", "otherSystemOptionArray", "otherSystemOption",
  "otherSystemOptionStart", "otherSystemOptionAttributes",
  "otherSystemOptionAttList", "otherSystemOptionAtt",
  "otherSystemOptionEnd", "serviceElement", "serviceElementStart",
  "serviceElementContent", "serviceElementEmpty", "serviceElementLaden",
  "serviceElementBody", "serviceElementList", "serviceChild",
  "serviceType", "serviceTypeStart", "serviceTypeContent",
  "serviceTypeEmpty", "serviceTypeLaden", "serviceTypeBody",
  "otherServiceOptions", "otherServiceOptionsStart",
  "otherServiceOptionsAttributes", "otherServiceOptionsContent",
  "otherServiceOptionsEmpty", "otherServiceOptionsLaden",
  "otherServiceOptionsBody", "otherServiceOptionArray",
  "otherServiceOption", "otherServiceOptionStart",
  "otherServiceOptionAttributes", "otherServiceOptionAttList",
  "otherServiceOptionAtt", "otherServiceOptionEnd", "jobElement",
  "jobElementStart", "jobElementContent", "jobElementEmpty",
  "jobElementLaden", "jobElementBody", "jobElementList", "jobChild",
  "maxTime", "maxTimeStart", "maxTimeAttributes", "maxTimeContent",
  "maxTimeEmpty", "maxTimeLaden", "maxTimeBody", "maxTimeValue",
  "requestedStartTime", "requestedStartTimeStart",
  "requestedStartTimeContent", "requestedStartTimeEmpty",
  "requestedStartTimeLaden", "requestedStartTimeBody", "dependencies",
  "dependenciesStart", "dependenciesAttributes", "dependenciesContent",
  "dependenciesEmpty", "dependenciesLaden", "dependenciesList",
  "dependencyJobID", "requiredDirectories", "requiredDirectoriesStart",
  "requiredDirectoriesContent", "requiredDirectoriesEmpty",
  "requiredDirectoriesLaden", "requiredFiles", "requiredFilesStart",
  "requiredFilesContent", "requiredFilesEmpty", "requiredFilesLaden",
  "directoriesToMake", "directoriesToMakeStart",
  "directoriesToMakeContent", "directoriesToMakeEmpty",
  "directoriesToMakeLaden", "filesToMake", "filesToMakeStart",
  "filesToMakeContent", "filesToMakeEmpty", "filesToMakeLaden",
  "inputDirectoriesToMove", "inputDirectoriesToMoveStart",
  "inputDirectoriesToMoveAttributes", "inputDirectoriesToMoveContent",
  "inputDirectoriesToMoveEmpty", "inputDirectoriesToMoveLaden",
  "inputDirectoriesToMoveList", "inputDirectoryToMove", "inputFilesToMove",
  "inputFilesToMoveStart", "inputFilesToMoveAttributes",
  "inputFilesToMoveContent", "inputFilesToMoveEmpty",
  "inputFilesToMoveLaden", "inputFilesToMoveList", "inputFileToMove",
  "outputFilesToMove", "outputFilesToMoveStart",
  "outputFilesToMoveAttributes", "outputFilesToMoveContent",
  "outputFilesToMoveEmpty", "outputFilesToMoveLaden",
  "outputFilesToMoveList", "outputFileToMove", "outputDirectoriesToMove",
  "outputDirectoriesToMoveStart", "outputDirectoriesToMoveAttributes",
  "outputDirectoriesToMoveContent", "outputDirectoriesToMoveEmpty",
  "outputDirectoriesToMoveLaden", "outputDirectoriesToMoveList",
  "outputDirectoryToMove", "filesToDelete", "filesToDeleteStart",
  "filesToDeleteAttributes", "filesToDeleteContent", "filesToDeleteEmpty",
  "filesToDeleteLaden", "directoriesToDelete", "directoriesToDeleteStart",
  "directoriesToDeleteAttributes", "directoriesToDeleteContent",
  "directoriesToDeleteEmpty", "directoriesToDeleteLaden",
  "processesToKill", "processesToKillStart", "processesToKillAttributes",
  "processesToKillContent", "processesToKillEmpty", "processesToKillLaden",
  "processesToKillList", "processID", "otherJobOptions",
  "otherJobOptionsStart", "otherJobOptionsAttributes",
  "otherJobOptionsContent", "otherJobOptionsEmpty", "otherJobOptionsLaden",
  "otherJobOptionsBody", "otherJobOptionArray", "otherJobOption",
  "otherJobOptionStart", "otherJobOptionAttributes",
  "otherJobOptionAttList", "otherJobOptionAtt", "otherJobOptionEnd",
  "optimizationElement", "optimizationStart", "optimizationAttributes",
  "optimizationAttList", "optimizationATT", "optimizationContent",
  "optimizationEmpty", "optimizationLaden", "optimizationBody",
  "variables", "variablesStart", "variablesAttributes",
  "numberOfOtherVariableOptions", "variablesContent", "variablesEmpty",
  "variablesLaden", "variablesBody", "initialVariableValues",
  "initialVariableValuesStart", "initialVariableValuesAttributes",
  "initialVariableValuesContent", "initialVariableValuesEmpty",
  "initialVariableValuesLaden", "initialVariableValuesBody",
  "initVarValueArray", "initVarValue", "initVarValueStart",
  "initVarValueAttributes", "initVarValueAttList", "initVarValueAtt",
  "initVarValueContent", "initialVariableValuesString",
  "initialVariableValuesStringStart",
  "initialVariableValuesStringAttributes",
  "initialVariableValuesStringContent", "initialVariableValuesStringEmpty",
  "initialVariableValuesStringLaden", "initialVariableValuesStringBody",
  "initVarValueStringArray", "initVarValueString",
  "initVarValueStringStart", "initVarValueStringAttributes",
  "initVarValueStringAttList", "initVarValueStringAtt",
  "initVarValueStringContent", "variableInitialBasis",
  "variableInitialBasisStart", "variableInitialBasisContent",
  "variableInitialBasisEmpty", "variableInitialBasisLaden",
  "variableInitialBasisBody", "variablesBasic", "variablesBasicStart",
  "variablesBasicNumberOfElATT", "variablesBasicContent",
  "variablesBasicEmpty", "variablesBasicLaden", "variablesBasicBody",
  "variablesAtLower", "variablesAtLowerStart",
  "variablesAtLowerNumberOfElATT", "variablesAtLowerContent",
  "variablesAtLowerEmpty", "variablesAtLowerLaden", "variablesAtLowerBody",
  "variablesAtUpper", "variablesAtUpperStart",
  "variablesAtUpperNumberOfElATT", "variablesAtUpperContent",
  "variablesAtUpperEmpty", "variablesAtUpperLaden", "variablesAtUpperBody",
  "variablesAtEquality", "variablesAtEqualityStart",
  "variablesAtEqualityNumberOfElATT", "variablesAtEqualityContent",
  "variablesAtEqualityEmpty", "variablesAtEqualityLaden",
  "variablesAtEqualityBody", "variablesIsFree", "variablesIsFreeStart",
  "variablesIsFreeNumberOfElATT", "variablesIsFreeContent",
  "variablesIsFreeEmpty", "variablesIsFreeLaden", "variablesIsFreeBody",
  "variablesSuperbasic", "variablesSuperbasicStart",
  "variablesSuperbasicNumberOfElATT", "variablesSuperbasicContent",
  "variablesSuperbasicEmpty", "variablesSuperbasicLaden",
  "variablesSuperbasicBody", "variablesUnknown", "variablesUnknownStart",
  "variablesUnknownNumberOfElATT", "variablesUnknownContent",
  "variablesUnknownEmpty", "variablesUnknownLaden", "variablesUnknownBody",
  "integerVariableBranchingWeights",
  "integerVariableBranchingWeightsStart",
  "integerVariableBranchingWeightsAttributes",
  "integerVariableBranchingWeightsContent",
  "integerVariableBranchingWeightsEmpty",
  "integerVariableBranchingWeightsLaden",
  "integerVariableBranchingWeightsBody", "branchingWeightsArray",
  "branchingWeight", "branchingWeightStart", "branchingWeightAttributes",
  "branchingWeightAttList", "branchingWeightAtt", "branchingWeightContent",
  "sosVariableBranchingWeights", "sosVariableBranchingWeightsStart",
  "sosVariableBranchingWeightsAttributes",
  "sosVariableBranchingWeightsContent", "sosVariableBranchingWeightsEmpty",
  "sosVariableBranchingWeightsLaden", "sosWeightGroupArray",
  "sosWeightGroup", "sosWeightGroupStart", "sosWeightGroupAttributes",
  "sosWeightGroupAttList", "sosWeightGroupAtt", "sosWeightGroupContent",
  "sosWeightGroupEmpty", "sosWeightGroupLaden",
  "otherVariableOptionsArray", "otherVariableOption",
  "otherVariableOptionStart", "otherVariableOptionAttributes",
  "otherVariableOptionAttList", "otherVariableOptionATT",
  "otherVariableOptionContent", "otherVariableOptionEmpty",
  "otherVariableOptionLaden", "otherVariableOptionBody", "otherVarList",
  "otherVar", "otherVarStart", "otherVarAttributes", "otherVarAttList",
  "otherVarAtt", "otherVarContent", "otherVarEmpty", "objectives",
  "objectivesStart", "objectivesAttributes",
  "numberOfOtherObjectiveOptions", "objectivesContent", "objectivesEmpty",
  "objectivesLaden", "objectivesBody", "initialObjectiveValues",
  "initialObjectiveValuesStart", "initialObjectiveValuesAttributes",
  "initialObjectiveValuesContent", "initialObjectiveValuesEmpty",
  "initialObjectiveValuesLaden", "initialObjectiveValuesBody",
  "initObjValueArray", "initObjValue", "initObjValueStart",
  "initObjValueAttributes", "initObjValueAttList", "initObjValueAtt",
  "initObjValueContent", "initialObjectiveBounds",
  "initialObjectiveBoundsStart", "numberOfObjATT",
  "initialObjectiveBoundsContent", "initialObjectiveBoundsEmpty",
  "initialObjectiveBoundsLaden", "initialObjectiveBoundsBody",
  "initObjBoundArray", "initObjBound", "initObjBoundStart",
  "initObjBoundAttributes", "initObjBoundAttList", "initObjBoundAtt",
  "initObjBoundContent", "objectiveInitialBasis",
  "objectiveInitialBasisStart", "objectiveInitialBasisContent",
  "objectiveInitialBasisEmpty", "objectiveInitialBasisLaden",
  "objectiveInitialBasisBody", "objectivesBasic", "objectivesBasicStart",
  "objectivesBasicNumberOfElATT", "objectivesBasicContent",
  "objectivesBasicEmpty", "objectivesBasicLaden", "objectivesBasicBody",
  "objectivesAtLower", "objectivesAtLowerStart",
  "objectivesAtLowerNumberOfElATT", "objectivesAtLowerContent",
  "objectivesAtLowerEmpty", "objectivesAtLowerLaden",
  "objectivesAtLowerBody", "objectivesAtUpper", "objectivesAtUpperStart",
  "objectivesAtUpperNumberOfElATT", "objectivesAtUpperContent",
  "objectivesAtUpperEmpty", "objectivesAtUpperLaden",
  "objectivesAtUpperBody", "objectivesAtEquality",
  "objectivesAtEqualityStart", "objectivesAtEqualityNumberOfElATT",
  "objectivesAtEqualityContent", "objectivesAtEqualityEmpty",
  "objectivesAtEqualityLaden", "objectivesAtEqualityBody",
  "objectivesIsFree", "objectivesIsFreeStart",
  "objectivesIsFreeNumberOfElATT", "objectivesIsFreeContent",
  "objectivesIsFreeEmpty", "objectivesIsFreeLaden", "objectivesIsFreeBody",
  "objectivesSuperbasic", "objectivesSuperbasicStart",
  "objectivesSuperbasicNumberOfElATT", "objectivesSuperbasicContent",
  "objectivesSuperbasicEmpty", "objectivesSuperbasicLaden",
  "objectivesSuperbasicBody", "objectivesUnknown",
  "objectivesUnknownStart", "objectivesUnknownNumberOfElATT",
  "objectivesUnknownContent", "objectivesUnknownEmpty",
  "objectivesUnknownLaden", "objectivesUnknownBody",
  "otherObjectiveOptionsArray", "otherObjectiveOption",
  "otherObjectiveOptionStart", "otherObjectiveOptionAttributes",
  "otherObjectiveOptionAttList", "otherObjectiveOptionATT",
  "otherObjectiveOptionContent", "otherObjectiveOptionEmpty",
  "otherObjectiveOptionLaden", "otherObjectiveOptionBody", "otherObjList",
  "otherObj", "otherObjStart", "otherObjAttributes", "otherObjAttList",
  "otherObjAtt", "otherObjContent", "otherObjEmpty", "constraints",
  "constraintsStart", "constraintsAttributes",
  "numberOfOtherConstraintOptions", "constraintsContent",
  "constraintsEmpty", "constraintsLaden", "constraintsBody",
  "initialConstraintValues", "initialConstraintValuesStart",
  "initialConstraintValuesAttributes", "initialConstraintValuesContent",
  "initialConstraintValuesEmpty", "initialConstraintValuesLaden",
  "initialConstraintValuesBody", "initConValueArray", "initConValue",
  "initConValueStart", "initConValueAttributes", "initConValueAttList",
  "initConValueAtt", "initConValueContent", "initialDualValues",
  "initialDualValuesStart", "initialDualValuesAttributes",
  "initialDualValuesContent", "initialDualValuesEmpty",
  "initialDualValuesLaden", "initialDualValuesBody", "initDualValueArray",
  "initDualValue", "initDualValueStart", "initDualValueAttributes",
  "initDualValueAttList", "initDualValueAtt", "initDualValueContent",
  "slacksInitialBasis", "slacksInitialBasisStart",
  "slacksInitialBasisContent", "slacksInitialBasisEmpty",
  "slacksInitialBasisLaden", "slacksInitialBasisBody", "slacksBasic",
  "slacksBasicStart", "slacksBasicNumberOfElATT", "slacksBasicContent",
  "slacksBasicEmpty", "slacksBasicLaden", "slacksBasicBody",
  "slacksAtLower", "slacksAtLowerStart", "slacksAtLowerNumberOfElATT",
  "slacksAtLowerContent", "slacksAtLowerEmpty", "slacksAtLowerLaden",
  "slacksAtLowerBody", "slacksAtUpper", "slacksAtUpperStart",
  "slacksAtUpperNumberOfElATT", "slacksAtUpperContent",
  "slacksAtUpperEmpty", "slacksAtUpperLaden", "slacksAtUpperBody",
  "slacksAtEquality", "slacksAtEqualityStart",
  "slacksAtEqualityNumberOfElATT", "slacksAtEqualityContent",
  "slacksAtEqualityEmpty", "slacksAtEqualityLaden", "slacksAtEqualityBody",
  "slacksIsFree", "slacksIsFreeStart", "slacksIsFreeNumberOfElATT",
  "slacksIsFreeContent", "slacksIsFreeEmpty", "slacksIsFreeLaden",
  "slacksIsFreeBody", "slacksSuperbasic", "slacksSuperbasicStart",
  "slacksSuperbasicNumberOfElATT", "slacksSuperbasicContent",
  "slacksSuperbasicEmpty", "slacksSuperbasicLaden", "slacksSuperbasicBody",
  "slacksUnknown", "slacksUnknownStart", "slacksUnknownNumberOfElATT",
  "slacksUnknownContent", "slacksUnknownEmpty", "slacksUnknownLaden",
  "slacksUnknownBody", "otherConstraintOptionsArray",
  "otherConstraintOption", "otherConstraintOptionStart",
  "otherConstraintOptionAttributes", "otherConstraintOptionAttList",
  "otherConstraintOptionATT", "otherConstraintOptionContent",
  "otherConstraintOptionEmpty", "otherConstraintOptionLaden",
  "otherConstraintOptionBody", "otherConList", "otherCon", "otherConStart",
  "otherConAttributes", "otherConAttList", "otherConAtt",
  "otherConContent", "otherConEmpty", "solverOptions",
  "solverOptionsStart", "numberOfSolverOptionsATT", "solverOptionsContent",
  "solverOptionsEmpty", "solverOptionsLaden", "solverOptionArray",
  "solverOption", "solverOptionStart", "solverOptionAttributes",
  "solverOptionAttList", "solverOptionATT", "solverOptionContent",
  "solverOptionEmpty", "solverOptionLaden", "solverOptionBody",
  "solverOptionItemArray", "solverOptionItem", "solverOptionItemContent",
  "solverOptionItemEmpty", "solverOptionItemLaden", "solverOptionItemBody",
  "PathList", "Path", "PathPair", "PathPairStart", "PathPairAttributes",
  "PathPairAttList", "PathPairAttribute", "PathPairFromATT",
  "PathPairToATT", "PathPairMakeCopyATT", "PathPairEnd",
  "categoryAttribute", "categoryAtt", "categoryAttEmpty",
  "categoryAttContent", "conTypeAttribute", "conTypeAtt",
  "conTypeAttEmpty", "conTypeAttContent", "descriptionAttribute",
  "descriptionAtt", "descriptionAttEmpty", "descriptionAttContent",
  "enumTypeAttribute", "enumTypeAtt", "enumTypeAttEmpty",
  "enumTypeAttContent", "groupWeightAttribute", "groupWeightAtt",
  "idxAttribute", "idxAtt", "idxAttContent", "lbValueAttribute",
  "lbValueAtt", "lbValueAttEmpty", "lbValueAttContent",
  "lbDualValueAttribute", "lbDualValueAtt", "lbDualValueAttEmpty",
  "lbDualValueAttContent", "nameAttribute", "nameAtt", "nameAttEmpty",
  "nameAttContent", "objTypeAttribute", "objTypeAtt", "objTypeAttEmpty",
  "objTypeAttContent", "solverAttribute", "solverAtt", "solverAttEmpty",
  "solverAttContent", "sosIdxAttribute", "sosIdxAtt", "sosIdxAttContent",
  "typeAttribute", "typeAtt", "typeAttEmpty", "typeAttContent",
  "ubValueAttribute", "ubValueAtt", "ubValueAttEmpty", "ubValueAttContent",
  "ubDualValueAttribute", "ubDualValueAtt", "ubDualValueAttEmpty",
  "ubDualValueAttContent", "unitAttribute", "unitAtt", "unitAttEmpty",
  "unitAttContent", "valueAttribute", "valueAtt", "valueAttEmpty",
  "valueAttContent", "varTypeAttribute", "varTypeAtt", "varTypeAttEmpty",
  "varTypeAttContent", "numberOfConAttribute",
  "numberOfConstraintsAttribute", "numberOfElAttribute",
  "numberOfEnumerationsAttribute", "numberOfItemsAttribute",
  "numberOfJobIDsATT", "numberOfObjAttribute",
  "numberOfObjectivesAttribute", "numberOfOtherConstraintOptionsAttribute",
  "numberOfOtherObjectiveOptionsAttribute",
  "numberOfOtherOptionsAttribute", "numberOfOtherVariableOptionsAttribute",
  "numberOfPathPairsAttribute", "numberOfPathsAttribute",
  "numberOfProcessesATT", "numberOfSolverOptionsAttribute",
  "numberOfVarAttribute", "numberOfVariablesAttribute",
  "otherEnumerationList", "otherEnumeration", "otherEnumerationStart",
  "otherEnumerationAttributes", "otherEnumerationAttList",
  "otherEnumerationATT", "otherEnumerationContent",
  "otherEnumerationEmpty", "otherEnumerationLaden", "otherEnumerationBody",
  "aNumber", "quote", "xmlWhiteSpace", "xmlWhiteSpaceChar",
  "osglFileHeader", "headerElementStart", "headerElementContent",
  "headerElementEmpty", "headerElementLaden", "headerElementBody",
  "headerElementList", "headerChild", "fileName", "fileNameContent",
  "fileNameEmpty", "fileNameLaden", "fileSource", "fileSourceContent",
  "fileSourceEmpty", "fileSourceLaden", "fileDescription",
  "fileDescriptionContent", "fileDescriptionEmpty", "fileDescriptionLaden",
  "fileCreator", "fileCreatorContent", "fileCreatorEmpty",
  "fileCreatorLaden", "fileLicence", "fileLicenceContent",
  "fileLicenceEmpty", "fileLicenceLaden", "osglIntArrayData",
  "osglIntVectorElArray", "osglIntVectorEl", "osglIntVectorElStart",
  "osglIntVectorElAttributes", "osglIntVectorElAttList",
  "osglIntVectorElAtt", "osglIntVectorElContent", "osglIntVectorBase64",
  "Base64SizeAttribute", "Base64Content", "Base64Empty", "Base64Laden",
  "osglIncrAttribute", "osglMultAttribute", 0
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
      32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   254,   255,   255,   256,   257,   258,   258,   259,   259,
     260,   261,   262,   263,   263,   264,   265,   265,   266,   266,
     267,   268,   268,   269,   269,   270,   271,   272,   272,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     274,   275,   276,   276,   277,   277,   278,   279,   280,   281,
     282,   282,   283,   283,   284,   285,   286,   287,   288,   288,
     289,   289,   290,   291,   292,   293,   294,   294,   295,   296,
     296,   297,   297,   298,   299,   300,   301,   302,   302,   303,
     303,   304,   305,   306,   307,   308,   308,   309,   309,   310,
     311,   312,   313,   314,   314,   315,   315,   316,   317,   318,
     319,   320,   320,   321,   321,   322,   323,   324,   325,   326,
     326,   327,   327,   328,   329,   330,   331,   332,   332,   333,
     334,   334,   335,   335,   336,   337,   338,   339,   340,   341,
     341,   342,   342,   343,   344,   345,   345,   346,   347,   348,
     349,   349,   350,   350,   350,   351,   351,   352,   352,   353,
     354,   354,   355,   355,   356,   357,   358,   358,   359,   359,
     359,   359,   359,   360,   361,   362,   363,   363,   364,   364,
     365,   366,   367,   368,   369,   370,   370,   371,   371,   372,
     373,   374,   375,   376,   377,   377,   378,   378,   379,   380,
     381,   382,   383,   383,   384,   385,   386,   387,   388,   389,
     389,   390,   390,   391,   392,   393,   393,   394,   395,   396,
     397,   397,   398,   398,   398,   399,   399,   400,   400,   401,
     402,   402,   403,   403,   404,   405,   406,   406,   407,   407,
     408,   409,   410,   410,   411,   411,   412,   413,   414,   415,
     416,   417,   417,   418,   418,   419,   420,   421,   421,   422,
     423,   424,   425,   425,   426,   426,   426,   427,   427,   428,
     428,   429,   430,   430,   431,   431,   432,   433,   434,   434,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   436,   437,   438,   438,   439,
     439,   440,   440,   441,   442,   443,   444,   445,   446,   446,
     447,   447,   448,   449,   450,   451,   452,   453,   453,   454,
     454,   455,   456,   456,   457,   458,   459,   460,   460,   461,
     461,   462,   463,   464,   465,   465,   466,   466,   467,   468,
     469,   470,   470,   471,   471,   472,   473,   474,   475,   475,
     476,   476,   477,   478,   479,   480,   481,   481,   482,   482,
     483,   484,   484,   485,   486,   487,   488,   489,   489,   490,
     490,   491,   492,   492,   493,   494,   495,   496,   497,   497,
     498,   498,   499,   500,   500,   501,   502,   503,   504,   505,
     505,   506,   506,   507,   508,   508,   509,   510,   511,   512,
     513,   513,   514,   514,   515,   516,   517,   518,   519,   519,
     520,   520,   521,   522,   523,   524,   525,   525,   526,   526,
     527,   528,   528,   529,   530,   531,   532,   533,   533,   534,
     534,   535,   536,   537,   537,   538,   539,   540,   541,   541,
     542,   542,   542,   543,   543,   544,   544,   545,   546,   547,
     547,   548,   548,   548,   549,   549,   550,   551,   552,   553,
     553,   554,   555,   556,   556,   557,   557,   558,   559,   560,
     561,   561,   562,   563,   564,   564,   565,   565,   566,   567,
     568,   568,   569,   570,   571,   572,   572,   573,   573,   573,
     574,   574,   575,   575,   576,   577,   578,   578,   579,   579,
     580,   581,   582,   582,   583,   584,   585,   586,   586,   587,
     587,   587,   588,   588,   589,   589,   590,   591,   591,   592,
     593,   594,   595,   595,   596,   597,   598,   598,   599,   600,
     601,   602,   602,   603,   604,   605,   605,   606,   607,   608,
     609,   609,   610,   611,   612,   612,   613,   614,   615,   616,
     616,   617,   618,   619,   619,   620,   621,   622,   623,   623,
     624,   625,   626,   626,   627,   628,   629,   630,   630,   631,
     632,   633,   633,   634,   635,   636,   637,   637,   638,   639,
     640,   640,   641,   642,   643,   644,   644,   645,   646,   647,
     647,   648,   648,   649,   650,   651,   651,   652,   653,   654,
     655,   655,   656,   656,   656,   657,   657,   658,   658,   659,
     660,   661,   661,   662,   662,   663,   664,   664,   665,   666,
     667,   668,   668,   669,   669,   669,   670,   670,   671,   671,
     672,   673,   673,   674,   675,   676,   677,   677,   678,   678,
     678,   678,   678,   678,   678,   678,   678,   678,   679,   679,
     680,   680,   681,   682,   682,   683,   683,   684,   685,   686,
     687,   687,   688,   688,   688,   688,   688,   689,   690,   690,
     691,   691,   692,   693,   694,   694,   695,   695,   696,   697,
     698,   699,   699,   700,   701,   702,   702,   703,   703,   704,
     705,   706,   706,   707,   708,   709,   710,   710,   711,   711,
     711,   712,   712,   713,   713,   714,   715,   716,   716,   717,
     717,   718,   719,   720,   720,   721,   722,   723,   724,   724,
     725,   725,   725,   725,   726,   726,   727,   727,   728,   729,
     729,   730,   731,   732,   733,   733,   734,   735,   736,   736,
     737,   738,   739,   740,   740,   741,   742,   743,   743,   744,
     745,   746,   747,   747,   748,   749,   750,   750,   751,   752,
     753,   754,   754,   755,   756,   757,   757,   758,   759,   760,
     761,   761,   762,   763,   764,   764,   765,   766,   767,   768,
     768,   769,   770,   771,   771,   772,   773,   774,   775,   775,
     776,   777,   778,   778,   779,   780,   781,   782,   782,   783,
     784,   785,   786,   786,   787,   787,   787,   787,   787,   787,
     787,   787,   787,   787,   788,   788,   789,   789,   790,   791,
     791,   792,   792,   793,   794,   795,   796,   796,   797,   797,
     797,   797,   797,   798,   799,   799,   800,   800,   801,   802,
     803,   803,   804,   804,   805,   806,   807,   808,   808,   809,
     810,   811,   811,   812,   812,   813,   814,   815,   815,   816,
     817,   818,   819,   819,   820,   820,   820,   821,   821,   822,
     822,   823,   824,   825,   825,   826,   826,   827,   828,   829,
     829,   830,   831,   832,   833,   833,   834,   834,   834,   834,
     835,   835,   836,   836,   837,   838,   838,   839,   840,   841,
     842,   842,   843,   844,   845,   845,   846,   847,   848,   849,
     849,   850,   851,   852,   852,   853,   854,   855,   856,   856,
     857,   858,   859,   859,   860,   861,   862,   863,   863,   864,
     865,   866,   866,   867,   868,   869,   870,   870,   871,   872,
     873,   873,   874,   875,   876,   877,   877,   878,   879,   880,
     880,   881,   882,   883,   884,   884,   885,   886,   887,   887,
     888,   889,   890,   891,   891,   892,   893,   894,   895,   895,
     896,   896,   896,   896,   896,   896,   896,   896,   896,   896,
     897,   897,   898,   898,   899,   900,   900,   901,   901,   902,
     903,   904,   905,   905,   906,   906,   906,   906,   906,   907,
     908,   908,   909,   909,   910,   911,   912,   912,   913,   914,
     915,   915,   916,   917,   918,   919,   919,   920,   920,   920,
     920,   920,   920,   920,   921,   921,   922,   922,   923,   924,
     925,   925,   926,   927,   927,   928,   928,   929,   930,   931,
     931,   932,   933,   934,   935,   936,   936,   937,   937,   937,
     938,   939,   940,   941,   941,   942,   943,   943,   944,   945,
     946,   947,   947,   948,   949,   950,   951,   951,   952,   953,
     954,   955,   955,   956,   957,   958,   959,   960,   961,   962,
     963,   964,   964,   965,   966,   967,   968,   968,   969,   970,
     971,   972,   972,   973,   974,   975,   976,   976,   977,   978,
     979,   980,   980,   981,   982,   983,   984,   985,   986,   987,
     987,   988,   989,   990,   991,   991,   992,   993,   994,   995,
     995,   996,   997,   998,   999,   999,  1000,  1001,  1002,  1003,
    1003,  1004,  1005,  1006,  1007,  1007,  1008,  1009,  1010,  1011,
    1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1028,  1029,  1030,
    1031,  1032,  1032,  1033,  1033,  1033,  1034,  1034,  1035,  1036,
    1037,  1038,  1038,  1039,  1040,  1040,  1041,  1041,  1041,  1041,
    1042,  1043,  1044,  1044,  1045,  1045,  1046,  1047,  1048,  1048,
    1049,  1049,  1049,  1049,  1049,  1050,  1050,  1051,  1051,  1052,
    1052,  1053,  1054,  1054,  1055,  1055,  1056,  1056,  1057,  1058,
    1058,  1059,  1059,  1060,  1060,  1061,  1062,  1062,  1063,  1063,
    1064,  1064,  1065,  1066,  1066,  1067,  1067,  1068,  1068,  1069,
    1070,  1070,  1071,  1071,  1072,  1073,  1074,  1075,  1075,  1076,
    1076,  1077,  1078,  1079,  1080,  1080,  1081,  1081,  1082,  1083,
    1084
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     1,     0,     6,     0,     1,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     0,     1,     3,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     3,     1,     0,     1,     3,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     1,     0,     2,     1,     1,     3,
       1,     3,     1,     1,     0,     2,     1,     1,     3,     1,
       3,     1,     0,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       2,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     4,     3,     1,     1,     1,     2,
       1,     3,     3,     1,     1,     1,     2,     1,     3,     3,
       1,     1,     1,     2,     1,     3,     3,     1,     1,     1,
       2,     1,     3,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     3,     1,     1,     1,     1,
       2,     1,     3,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     4,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     0,
       3,     1,     1,     0,     1,     1,     1,     1,     3,     6,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       2,     1,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     0,     2,     1,     1,     1,     1,
       3,     7,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     3,     1,
       4,     1,     1,     2,     1,     3,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     2,     1,
       3,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     3,     1,     1,     0,     1,     1,     1,     1,     3,
       4,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     2,     1,     0,     2,     1,     1,
       1,     1,     3,     7,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     0,     3,     1,     1,
       0,     1,     1,     1,     1,     3,     4,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       2,     1,     0,     2,     1,     1,     1,     1,     3,     7,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       0,     2,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     4,     3,     1,     1,     0,     2,     1,     1,     1,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     4,     1,     1,     4,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     4,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     1,
       1,     1,     3,     0,     1,     1,     1,     1,     1,     3,
       1,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     3,     3,     4,     1,     1,     2,     1,     3,     4,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,  1171,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   147,     0,
       0,  1175,  1170,  1172,  1173,    16,    10,     3,     8,     9,
     149,   217,     0,     0,    24,    19,    21,    22,  1174,     0,
    1190,  1189,     0,  1197,  1196,     0,  1204,  1203,     0,  1211,
    1210,     0,  1218,  1217,     0,  1177,  1178,  1180,  1186,  1187,
    1188,  1181,  1193,  1194,  1195,  1182,  1200,  1201,  1202,  1183,
    1207,  1208,  1209,  1184,  1214,  1215,  1216,    14,   219,   259,
       0,     0,   153,   148,   150,   151,    23,    41,    49,    57,
      65,    76,    84,    92,   100,   108,   116,   127,     0,    26,
      27,    29,     0,    30,     0,    31,     0,    32,    66,    33,
       0,    34,     0,    35,     0,    36,     0,    37,     0,    38,
     117,    39,     0,     0,     0,     0,     0,     0,  1176,  1179,
      11,   261,   435,     0,     0,   223,   218,   220,   221,   152,
     197,   164,   173,   182,   191,     0,   155,   156,   158,   166,
     159,   175,   160,   184,   161,   192,   162,     0,    25,    28,
       0,    45,    40,    42,    43,     0,    53,    48,    50,    51,
       0,    61,    56,    58,    59,     0,     0,    67,     0,    80,
      75,    77,    78,     0,    88,    83,    85,    86,     0,    96,
      91,    93,    94,     0,   104,    99,   101,   102,     0,   112,
     107,   109,   110,     0,     0,   118,  1164,     0,   128,  1191,
    1198,  1205,  1212,  1219,   437,    15,   439,     0,   265,   260,
     262,   263,   222,   239,   231,     0,   225,   226,   228,     0,
     229,     0,   154,   157,     0,   165,     0,   174,     0,   183,
       0,  1058,     0,   193,  1055,  1056,  1057,     0,   198,    47,
      44,     0,    55,    52,     0,    63,    60,     0,     0,     0,
      72,    64,    69,    70,    82,    79,     0,    90,    87,     0,
      98,    95,     0,   106,   103,     0,   114,   111,     0,     0,
       0,   123,   115,   120,   121,     0,     0,     0,   132,   126,
     129,   130,     0,   438,   264,   415,   286,   297,   305,   316,
     323,   330,   337,   396,   388,   344,   355,   377,   366,   404,
       0,   267,   268,   270,   287,   271,     0,   272,     0,   273,
       0,   274,     0,   275,     0,   276,     0,   277,     0,   278,
       0,   280,     0,   279,     0,   281,     0,   282,     0,   283,
       0,   284,     0,   224,   227,     0,   235,   230,   232,   233,
       0,   240,     0,   163,     0,  1116,   167,   169,   168,  1113,
    1114,  1115,     0,   172,   176,   178,   177,     0,   181,   185,
     187,   186,  1164,     0,   190,     0,   202,   196,   199,   200,
      46,    54,    62,    68,    74,    71,     0,    81,    89,    97,
     105,   113,   119,   125,   122,     0,  1164,  1163,  1166,  1167,
    1168,  1169,  1165,   131,   138,     0,   134,   135,   140,   449,
     446,   436,   444,   445,  1164,  1164,  1164,   440,   442,   443,
     441,   266,   269,     0,   288,     0,   301,   296,   298,   299,
       0,     0,   306,     0,     0,     0,     0,     0,     0,     0,
     345,     0,   356,     0,   367,     0,   378,     0,   389,     0,
     397,     0,     0,   405,     0,   416,   237,   234,     0,     0,
     244,   238,   241,   242,  1161,  1162,     0,   171,     0,     0,
     180,     0,   189,  1059,   195,     0,   201,   208,     0,   204,
     205,   210,    73,   124,  1138,   133,   136,     0,   139,   451,
       0,   660,   453,     0,     0,     0,     0,   292,   285,   289,
     290,   303,   300,     0,     0,     0,   310,   304,   307,   308,
       0,     0,   320,   315,   317,   318,     0,   327,   322,   324,
     325,     0,   334,   329,   331,   332,     0,   341,   336,   338,
     339,     0,     0,   349,   343,   346,   347,     0,   360,   354,
     357,   358,     0,   371,   365,   368,   369,     0,   382,   376,
     379,   380,     0,   393,   387,   390,   391,     0,   401,   395,
     398,   399,     0,     0,   409,   403,   406,   407,     0,   420,
     414,   417,   418,   236,   243,   250,     0,   246,   247,   252,
     170,  1117,   179,   188,   194,   203,   206,     0,   209,     0,
     146,   137,     0,     0,  1083,  1121,   141,   144,   142,  1080,
    1081,  1082,   143,  1118,  1119,  1120,   447,   662,   826,   664,
    1164,     0,   452,   454,  1164,  1164,  1164,   291,     0,   294,
     295,   302,     0,     0,   309,     0,   312,     0,   319,     0,
       0,  1029,   326,     0,   333,     0,   340,     0,     0,  1033,
     348,     0,   351,   353,  1035,   359,     0,   362,   364,   370,
       0,   373,   375,   381,     0,   384,   386,   392,     0,   400,
       0,     0,   408,     0,     0,   411,   419,   426,     0,   422,
     423,   428,   245,   248,     0,   251,     0,   216,   207,   211,
     214,   212,   213,   145,  1164,     0,   828,   992,   830,  1164,
       0,   663,   665,     0,   460,   457,   450,   455,   456,  1145,
    1135,  1129,   293,  1133,     0,   311,   313,  1141,     0,   321,
    1030,   328,   335,   342,  1140,   350,   352,     0,  1034,   361,
     363,   372,   374,   383,   385,   394,   402,  1142,     0,   410,
     412,   421,   424,     0,   427,     0,   258,   249,   253,   256,
     254,   255,   215,  1084,  1122,   994,   448,     0,  1164,     0,
     829,   831,     0,   671,   668,   661,   666,   667,  1164,   462,
       0,   482,     0,     0,     0,     0,  1044,  1032,     0,     0,
       0,  1036,  1037,  1038,  1039,     0,     0,   434,   425,   429,
     432,   430,   431,   257,  1164,     0,   995,     0,   837,   834,
     827,   832,   833,  1164,   673,     0,   693,     0,  1139,   458,
     484,   504,     0,  1164,     0,   463,   314,  1031,  1043,     0,
       0,     0,   413,   433,     0,  1000,   998,   993,   996,   997,
    1164,   839,     0,   859,     0,  1137,   669,   695,   716,     0,
    1164,     0,   674,   506,   575,     0,     0,   485,     0,     0,
     467,   461,   464,   465,  1040,  1041,  1042,  1164,     0,  1136,
     835,   861,   882,     0,  1164,     0,   840,   718,   787,     0,
       0,   696,     0,     0,   678,   672,   675,   676,   577,   597,
       0,   512,   509,   505,   507,   508,     0,   489,   483,   486,
     487,  1164,   466,   473,     0,   469,   470,   475,  1143,   999,
    1003,  1001,     0,   884,   953,     0,     0,   862,     0,     0,
     844,   838,   841,   842,   670,   724,   721,   717,   719,   720,
       0,   700,   694,   697,   698,  1164,   677,   684,     0,   680,
     681,   686,   599,   621,     0,     0,   578,   514,     0,   521,
       0,   495,   488,     0,   491,   492,   497,  1144,   468,   471,
       0,   474,     0,     0,  1164,  1101,  1048,     0,  1093,     0,
    1004,  1005,  1010,  1045,  1046,  1047,  1012,  1007,  1009,  1090,
    1091,  1092,  1011,  1098,  1099,  1100,  1008,  1013,   836,   890,
     887,   883,   885,   886,     0,   866,   860,   863,   864,  1164,
     843,   850,     0,   846,   847,   852,   790,   788,   792,   726,
       0,   733,     0,   706,   699,     0,   702,   703,   708,  1134,
     679,   682,     0,   685,   459,     0,     0,     0,   582,   576,
     579,   580,   510,   523,   530,     0,  1164,     0,   515,   490,
     493,     0,   496,     0,   481,   472,  1164,   476,   477,  1067,
    1068,   478,   479,  1164,     0,     0,  1164,     0,  1017,  1002,
    1014,  1015,  1006,   956,   954,   958,   892,     0,   899,     0,
     872,   865,     0,   868,   869,   874,  1128,   845,   848,     0,
     851,     0,   791,   722,   735,   742,     0,     0,   727,   701,
     704,     0,   707,     0,   692,   683,   687,   688,   689,   690,
     624,   622,   626,     0,     0,   604,   598,   601,   602,   588,
     581,     0,   584,   585,   590,   532,   539,     0,     0,   524,
       0,  1222,   518,   513,   516,   517,     0,   503,   494,   498,
     499,   500,   501,   480,     0,  1049,  1102,  1164,  1094,  1016,
    1026,     0,  1025,     0,  1019,  1020,  1022,  1023,  1024,     0,
     957,   888,   901,   908,     0,     0,   893,   867,   870,     0,
     873,     0,   858,   849,   853,   854,   855,   856,     0,   807,
     789,   804,   805,  1164,     0,  1063,     0,  1088,   793,   799,
     803,   802,  1060,  1061,  1062,   796,   801,  1085,  1086,  1087,
     798,   800,   797,   795,   794,   744,   751,     0,     0,   736,
    1222,   730,   725,   728,   729,     0,   715,   705,  1073,  1106,
       0,     0,   709,   710,   712,  1070,  1071,  1072,   711,   713,
    1103,  1104,  1105,   691,     0,   625,     0,   603,   609,     0,
     606,   611,   583,   586,     0,   589,   541,   548,     0,     0,
     533,  1222,   527,   522,   525,   526,  1164,     0,     0,   520,
    1220,  1221,   502,  1164,  1132,  1028,     0,  1018,  1021,     0,
     973,   955,   970,   971,     0,  1053,   959,   965,   967,  1050,
    1051,  1052,   969,   968,   962,   964,   966,   963,   960,   961,
     910,   917,     0,     0,   902,  1222,   896,   891,   894,   895,
       0,   881,   871,  1078,  1111,  1164,  1164,   875,   876,   878,
    1075,  1076,  1077,   877,   879,  1108,  1109,  1110,   857,   806,
     814,  1149,     0,   809,   811,   816,   810,  1146,  1151,     0,
       0,     0,   753,   760,     0,     0,   745,  1222,   739,   734,
     737,   738,     0,   732,   714,  1164,  1164,     0,   641,   623,
     638,   639,     0,  1126,   627,   633,   637,   636,   630,   632,
     634,   631,   635,  1123,  1124,  1125,   629,   628,   600,   605,
     607,     0,   610,     0,   596,   587,   591,   592,   593,   594,
     550,   557,     0,     0,   542,  1222,   536,   531,   534,   535,
       0,   529,  1130,  1164,     0,   519,  1225,  1223,  1227,  1069,
    1027,   972,   980,     0,   975,   977,   982,   976,     0,   919,
     926,     0,     0,   911,  1222,   905,   900,   903,   904,     0,
     898,   880,     0,     0,   808,   812,     0,   815,  1147,     0,
    1150,  1164,  1064,  1089,   762,   769,     0,     0,   754,  1222,
     748,   743,   746,   747,     0,   741,   731,  1074,  1107,   640,
     648,     0,   643,   645,   650,   644,     0,     0,   619,   608,
     616,   617,     0,  1164,   612,   615,  1065,   613,  1095,  1096,
     614,   595,   559,   566,     0,     0,   551,  1222,   545,   540,
     543,   544,     0,   538,   528,     0,     0,  1237,  1232,  1234,
    1235,     0,  1226,   974,   978,     0,   981,  1054,   928,   935,
       0,     0,   920,  1222,   914,   909,   912,   913,     0,   907,
     897,  1164,  1164,     0,   825,   813,   823,   817,   818,   821,
     819,   822,   820,  1222,  1158,  1148,  1156,  1157,  1155,  1154,
    1153,  1152,  1131,   771,   778,     0,     0,   763,  1222,   757,
     752,   755,   756,     0,   750,   740,   642,   646,     0,   649,
    1127,   618,     0,     0,     0,   568,   511,     0,     0,   560,
    1222,   554,   549,   552,   553,     0,   547,   537,  1164,     0,
    1236,     0,  1224,  1164,  1164,  1228,  1230,  1229,     0,   991,
     979,   989,   983,   984,   987,   985,   988,   986,   937,   944,
       0,     0,   929,  1222,   923,   918,   921,   922,     0,   916,
     906,  1079,  1112,   824,     0,  1160,   780,   723,     0,     0,
     772,  1222,   766,   761,   764,   765,     0,   759,   749,     0,
     659,   647,   657,   651,   652,   655,   653,   656,   654,   620,
       0,  1164,     0,   569,  1222,   563,   558,   561,   562,     0,
     556,   546,  1233,  1238,     0,     0,     0,   990,   946,   889,
       0,     0,   938,  1222,   932,   927,   930,   931,     0,   925,
     915,  1159,     0,   781,  1222,   775,   770,   773,   774,     0,
     768,   758,   658,  1066,  1097,  1222,   572,   567,   570,   571,
       0,   565,   555,  1231,  1164,  1164,     0,   947,  1222,   941,
     936,   939,   940,     0,   934,   924,  1222,   784,   779,   782,
     783,     0,   777,   767,     0,   574,   564,  1239,  1240,  1222,
     950,   945,   948,   949,     0,   943,   933,     0,   786,   776,
     573,     0,   952,   942,   785,   951
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    27,    28,    29,    15,    16,
       8,     9,    18,    19,    35,    36,    37,    98,    99,   100,
     101,   102,   162,   163,   164,   251,   103,   104,   167,   168,
     169,   254,   105,   106,   172,   173,   174,   257,   107,   108,
     176,   177,   261,   262,   263,   386,   109,   110,   180,   181,
     182,   266,   111,   112,   185,   186,   187,   269,   113,   114,
     190,   191,   192,   272,   115,   116,   195,   196,   197,   275,
     117,   118,   200,   201,   202,   278,   119,   120,   204,   205,
     282,   283,   284,   395,   121,   122,   207,   289,   290,   291,
     405,   406,   407,   408,   487,   488,   596,   591,    31,    32,
      83,    84,    85,   145,   146,   147,   148,   149,   234,   235,
     356,   353,   466,   150,   151,   236,   237,   364,   363,   469,
     152,   153,   238,   239,   369,   368,   471,   154,   155,   242,
     374,   475,   156,   157,   247,   377,   378,   379,   478,   479,
     480,   481,   587,   588,   679,   678,    79,    80,   136,   137,
     138,   225,   226,   227,   228,   229,   347,   348,   349,   458,
     230,   231,   350,   461,   462,   463,   576,   577,   578,   579,
     674,   675,   738,   737,   132,   133,   219,   220,   221,   310,
     311,   312,   313,   314,   423,   498,   499,   500,   618,   619,
     315,   316,   427,   428,   429,   503,   317,   318,   431,   507,
     508,   509,   625,   626,   319,   320,   513,   514,   515,   321,
     322,   518,   519,   520,   323,   324,   523,   524,   525,   325,
     326,   528,   529,   530,   327,   328,   439,   534,   535,   536,
     641,   642,   329,   330,   441,   539,   540,   541,   646,   647,
     331,   332,   443,   544,   545,   546,   650,   651,   333,   334,
     445,   549,   550,   551,   654,   655,   335,   336,   447,   554,
     555,   556,   337,   338,   449,   559,   560,   561,   339,   340,
     452,   565,   566,   567,   664,   665,   341,   342,   454,   570,
     571,   572,   668,   669,   670,   671,   733,   734,   779,   778,
     215,   216,   292,   293,   417,   411,   412,   413,   490,   491,
     492,   611,   612,   696,   697,   698,   760,   761,   762,   804,
     841,   842,   843,   884,   885,   886,   887,   940,   941,  1027,
    1025,   801,   802,   836,   878,   879,   880,   933,   934,   935,
     936,  1021,  1022,  1109,  1108,   834,   835,   873,   874,   875,
     928,   929,   930,  1017,  1103,  1104,  1105,  1228,  1014,  1015,
    1098,  1223,  1224,  1225,  1360,  1096,  1097,  1219,  1357,  1358,
    1359,  1452,  1217,  1218,  1353,  1449,  1450,  1451,  1535,  1351,
    1352,  1445,  1532,  1533,  1534,  1609,  1443,  1444,  1528,  1606,
    1607,  1608,  1650,  1526,  1527,  1602,  1647,  1648,  1649,  1674,
     869,   870,   925,  1009,  1010,  1011,  1091,  1092,  1093,  1094,
    1214,  1215,  1346,  1345,   923,   924,  1006,  1086,  1087,  1088,
    1209,  1210,  1211,  1341,  1342,  1434,  1429,  1430,  1431,  1004,
    1081,  1082,  1204,  1205,  1324,  1319,  1320,  1321,  1421,  1422,
    1423,  1424,  1518,  1519,  1593,  1591,  1592,   608,   609,   690,
     691,   755,   756,   757,   795,   796,   797,   831,   865,   866,
     867,   918,   919,   920,   921,  1002,  1003,  1076,  1075,   828,
     829,   860,   912,   913,   914,   995,   996,   997,   998,  1071,
    1072,  1192,  1187,   858,   859,   907,   908,   909,   990,   991,
     992,  1067,  1182,  1183,  1184,  1312,  1065,  1066,  1178,  1309,
    1310,  1311,  1414,  1176,  1177,  1305,  1411,  1412,  1413,  1513,
    1303,  1304,  1407,  1510,  1511,  1512,  1586,  1405,  1406,  1506,
    1583,  1584,  1585,  1639,  1504,  1505,  1579,  1636,  1637,  1638,
    1671,  1577,  1578,  1632,  1668,  1669,  1670,  1687,   904,   987,
     988,  1061,  1062,  1158,  1150,  1151,  1152,  1292,  1293,  1294,
    1295,  1396,  1397,  1487,  1485,  1486,   687,   688,   749,   750,
     790,   791,   792,   822,   823,   824,   855,   901,   902,   903,
     982,   983,   984,   985,  1059,  1060,  1144,  1143,   852,   853,
     896,   976,   977,   978,  1052,  1053,  1054,  1055,  1139,  1140,
    1277,  1272,   894,   895,   971,   972,   973,  1047,  1048,  1049,
    1135,  1267,  1268,  1269,  1389,  1133,  1134,  1263,  1386,  1387,
    1388,  1478,  1261,  1262,  1382,  1475,  1476,  1477,  1568,  1380,
    1381,  1471,  1565,  1566,  1567,  1628,  1469,  1470,  1561,  1625,
    1626,  1627,  1663,  1559,  1560,  1621,  1660,  1661,  1662,  1684,
    1619,  1620,  1656,  1681,  1682,  1683,  1691,   968,  1044,  1045,
    1129,  1130,  1246,  1241,  1242,  1243,  1373,  1374,  1375,  1376,
    1465,  1466,  1552,  1550,  1551,   746,   747,   785,   817,   818,
     819,   848,   891,   892,   949,   950,   951,  1039,  1040,  1041,
    1123,  1124,  1125,  1126,  1127,  1128,  1236,   630,   631,   643,
     644,   717,   718,   771,   772,   773,   774,   767,   952,   953,
     954,   955,  1248,  1249,  1250,  1251,   956,   244,   245,   246,
    1161,  1162,  1163,  1164,  1435,  1436,  1028,  1029,  1030,  1194,
    1195,  1196,  1197,  1279,  1280,  1281,  1282,   957,   599,   600,
     601,  1166,  1167,  1168,  1169,   958,   959,   960,   961,  1437,
    1438,  1439,   962,   963,   964,   965,  1199,  1200,  1201,  1202,
    1284,  1285,  1286,  1287,   358,   359,   360,   361,   966,   603,
     604,   605,  1332,  1333,  1334,  1335,   856,   418,  1018,  1173,
     967,   432,   832,   419,   751,   692,   208,   613,   440,   434,
     453,   786,   805,   420,  1296,  1297,  1298,  1399,  1400,  1501,
    1495,  1496,  1497,  1574,   467,   285,   286,   402,    10,    11,
      22,    23,    24,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,  1229,  1230,  1367,  1368,
    1461,  1462,  1545,  1542,  1231,  1364,  1458,  1459,  1460,  1546,
    1547
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1370
static const yytype_int16 yypact[] =
{
     251, -1370, -1370,    76,    -4,    98, -1370, -1370,    41,    32,
   -1370,   333, -1370,   352, -1370, -1370, -1370, -1370,    54,   360,
     575, -1370, -1370, -1370, -1370,    -4, -1370, -1370, -1370, -1370,
   -1370,    92,   362,   371, -1370, -1370, -1370, -1370, -1370,   150,
   -1370, -1370,   180, -1370, -1370,   182, -1370, -1370,   211, -1370,
   -1370,   229, -1370, -1370,   164,   595, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,    41, -1370,   167,
     368,   -14, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   203,   443,
   -1370, -1370,   370, -1370,   373, -1370,   378, -1370,   223, -1370,
     382, -1370,   403, -1370,   405, -1370,   407, -1370,   419, -1370,
     226, -1370,   289,   220,   221,   222,   228,   249, -1370, -1370,
   -1370, -1370,   247,   425,   -29, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   278,   157, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,    12, -1370,   289, -1370, -1370,
      56, -1370, -1370, -1370, -1370,    29, -1370, -1370, -1370, -1370,
      28, -1370, -1370, -1370, -1370,   361,   427, -1370,    31, -1370,
   -1370, -1370, -1370,    27, -1370, -1370, -1370, -1370,    26, -1370,
   -1370, -1370, -1370,    30, -1370, -1370, -1370, -1370,    19, -1370,
   -1370, -1370, -1370,   372,   430, -1370, -1370,   432, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   130, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   307,    53, -1370, -1370,   434,
   -1370,   289, -1370, -1370,   392,   168,   396,   168,   410,   168,
     446, -1370,   423, -1370, -1370, -1370, -1370,   436, -1370, -1370,
   -1370,   356, -1370, -1370,   350, -1370, -1370,   359,   470,    42,
   -1370, -1370, -1370, -1370, -1370, -1370,   357, -1370, -1370,   365,
   -1370, -1370,   367, -1370, -1370,   375, -1370, -1370,   355,   488,
      18, -1370, -1370, -1370, -1370,   484,     3,   227, -1370, -1370,
   -1370, -1370,   442,   148, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
     435,   384, -1370, -1370,    68, -1370,   444, -1370,   499, -1370,
     487, -1370,   487, -1370,   487, -1370,   487, -1370,   509, -1370,
     509, -1370,   509, -1370,   509, -1370,   487, -1370,   487, -1370,
     481, -1370,   289, -1370, -1370,    11, -1370, -1370, -1370, -1370,
     449, -1370,   388, -1370,   522, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   388, -1370, -1370, -1370, -1370,   388, -1370, -1370,
   -1370, -1370, -1370,   527, -1370,   334, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   416, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   412, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   418,   411, -1370, -1370,   386,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   457, -1370,    15, -1370, -1370, -1370, -1370,
     550,   460, -1370,   552,   466,   490,   492,   494,   556,   500,
   -1370,   503, -1370,   505, -1370,   513, -1370,   525, -1370,   563,
   -1370,   558,   573, -1370,   580, -1370, -1370, -1370,   429,   456,
   -1370, -1370, -1370, -1370, -1370, -1370,   471, -1370,   571,   433,
   -1370,   472, -1370, -1370, -1370,   467, -1370, -1370,   512,   493,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   582,   126, -1370,
     566,   437,   618,   654,   656,   662,    20, -1370, -1370, -1370,
   -1370, -1370, -1370,   531,   666,   -55, -1370, -1370, -1370, -1370,
     674,   171, -1370, -1370, -1370, -1370,   445, -1370, -1370, -1370,
   -1370,   -20, -1370, -1370, -1370, -1370,    58, -1370, -1370, -1370,
   -1370,   678,    23, -1370, -1370, -1370, -1370,    69, -1370, -1370,
   -1370, -1370,   -64, -1370, -1370, -1370, -1370,   -75, -1370, -1370,
   -1370, -1370,    70, -1370, -1370, -1370, -1370,   -23, -1370, -1370,
   -1370, -1370,   682,   421, -1370, -1370, -1370, -1370,   469, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   567,   562, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   592,   126,   569,
   -1370, -1370,   716,   719, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   515,   710,
   -1370,   601, -1370, -1370, -1370, -1370, -1370, -1370,   675, -1370,
   -1370, -1370,   811,   770, -1370,   -42, -1370,   812, -1370,   813,
     179, -1370, -1370,   464, -1370,   108, -1370,    73,   814, -1370,
   -1370,   112, -1370, -1370, -1370, -1370,    85, -1370, -1370, -1370,
     -45, -1370, -1370, -1370,   -48, -1370, -1370, -1370,    72, -1370,
     -22,   816, -1370,   815,   452, -1370, -1370, -1370,   692,   696,
   -1370, -1370, -1370, -1370,   617,   126,   698, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   819, -1370,   606,   795, -1370,
     619, -1370, -1370,   825,   655, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   828, -1370, -1370, -1370,   830, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   621,   346, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   831, -1370,
   -1370, -1370, -1370,   625,   126,   706, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   808, -1370,   627,
   -1370, -1370,   832,   631, -1370, -1370, -1370, -1370, -1370, -1370,
     663,   659,   805,   727,   690,   691, -1370, -1370,   842,   844,
     845, -1370, -1370, -1370, -1370,   676,   718, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   629, -1370,   846,   634, -1370,
   -1370, -1370, -1370, -1370, -1370,   649,   641,   817, -1370, -1370,
   -1370,   673,   805, -1370,   637, -1370, -1370, -1370, -1370,   850,
     851,   852, -1370, -1370,   856, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   650,   643,   827, -1370, -1370, -1370,   680,   817,
   -1370,   639, -1370, -1370,   667,   646,   648, -1370,   862,   524,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   482, -1370,
   -1370, -1370,   685,   827, -1370,   697, -1370, -1370, -1370,   699,
     701, -1370,   864,   504, -1370, -1370, -1370, -1370, -1370,   669,
     805,   686, -1370, -1370, -1370, -1370,   162, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   694,   695, -1370, -1370, -1370, -1370,
   -1370, -1370,   341, -1370, -1370,   705,   707, -1370,   868,   506,
   -1370, -1370, -1370, -1370,   747,   693, -1370, -1370, -1370, -1370,
     140, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   671,   668,
   -1370, -1370, -1370, -1370,   847,   715, -1370, -1370,   700,   702,
     841, -1370, -1370,   703,   704, -1370, -1370, -1370, -1370, -1370,
     717,   262,   879,   880, -1370, -1370, -1370,   884, -1370,   722,
     341, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   758,   708,
   -1370, -1370, -1370, -1370,   134, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   672,   677, -1370, -1370, -1370, -1370, -1370, -1370,
     711,   709,   841, -1370, -1370,   684,   681, -1370, -1370, -1370,
   -1370, -1370,   724,   262,   763,   882,   726,  -123, -1370, -1370,
   -1370, -1370, -1370, -1370,   712,   841, -1370,   728, -1370, -1370,
   -1370,   730,   262,   720, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   890,   896, -1370,    82, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   721,   725,   841,
   -1370, -1370,   688,   687, -1370, -1370, -1370, -1370, -1370,   732,
     262,   736,   151, -1370, -1370,   723,   841,   738, -1370, -1370,
   -1370,   740,   206,   713, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   901,   549, -1370, -1370, -1370, -1370, -1370,
   -1370,   729,   734, -1370, -1370, -1370,   731,   841,   744, -1370,
     904,   689, -1370, -1370, -1370, -1370,   737, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   911, -1370, -1370, -1370, -1370, -1370,
   -1370,   914, -1370,   714,    96, -1370, -1370, -1370, -1370,   746,
     291, -1370, -1370,   739,   841,   748, -1370, -1370, -1370,   750,
     163,   733, -1370, -1370, -1370, -1370, -1370, -1370,   -95, -1370,
   -1370, -1370, -1370, -1370,   917, -1370,   919, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   741,   841,   752, -1370,
     689, -1370, -1370, -1370, -1370,   735, -1370, -1370, -1370, -1370,
     922,   923, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   754,   564,   920, -1370, -1370,   565,
   -1370, -1370, -1370, -1370,   756,   262, -1370,   742,   841,   760,
   -1370,   689, -1370, -1370, -1370, -1370, -1370,   743,   745, -1370,
     749, -1370, -1370, -1370, -1370, -1370,   753, -1370, -1370,   -93,
   -1370, -1370, -1370, -1370,   926, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   755,   841,   762, -1370,   689, -1370, -1370, -1370, -1370,
     751, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   803,   757, -1370, -1370,   759, -1370, -1370,   925,
     927,   928, -1370,   761,   841,   764, -1370,   689, -1370, -1370,
   -1370, -1370,   767, -1370, -1370, -1370, -1370,   -84, -1370, -1370,
   -1370, -1370,   934, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   766,    65,   769, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   765,   841,   768, -1370,   689, -1370, -1370, -1370, -1370,
     771, -1370, -1370, -1370,   772, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   809,   775, -1370, -1370,   759,   933, -1370,
     773,   841,   774, -1370,   689, -1370, -1370, -1370, -1370,   777,
   -1370, -1370,   388,   388, -1370, -1370,   776,   363, -1370,   778,
      22, -1370, -1370, -1370, -1370,   779,   841,   780, -1370,   689,
   -1370, -1370, -1370, -1370,   781, -1370, -1370, -1370, -1370, -1370,
   -1370,   818,   783, -1370, -1370,   759,   937,  -140, -1370, -1370,
   -1370, -1370,   940, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   789,   841,   782, -1370,   689, -1370, -1370,
   -1370, -1370,   785, -1370, -1370,   936,    13, -1370, -1370, -1370,
   -1370,   941,   560, -1370, -1370,   786,   363, -1370, -1370,   784,
     841,   788, -1370,   689, -1370, -1370, -1370, -1370,   793, -1370,
   -1370, -1370, -1370,   787, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   689, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   791,   841,   790, -1370,   689, -1370,
   -1370, -1370, -1370,   799, -1370, -1370, -1370, -1370,   792,   363,
   -1370, -1370,  -128,   388,   947, -1370, -1370,   841,   794, -1370,
     689, -1370, -1370, -1370, -1370,   797, -1370, -1370, -1370,   807,
   -1370,   949, -1370, -1370, -1370, -1370, -1370, -1370,   801, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   810,
     841,   796, -1370,   689, -1370, -1370, -1370, -1370,   820, -1370,
   -1370, -1370, -1370, -1370,   821, -1370, -1370, -1370,   841,   798,
   -1370,   689, -1370, -1370, -1370, -1370,   822, -1370, -1370,   823,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
     948, -1370,   800, -1370,   689, -1370, -1370, -1370, -1370,   824,
   -1370, -1370, -1370, -1370,   826,   952,   954, -1370, -1370, -1370,
     841,   802, -1370,   689, -1370, -1370, -1370, -1370,   829, -1370,
   -1370, -1370,   804, -1370,   689, -1370, -1370, -1370, -1370,   833,
   -1370, -1370, -1370, -1370, -1370,   689, -1370, -1370, -1370, -1370,
     836, -1370, -1370, -1370, -1370, -1370,   806, -1370,   689, -1370,
   -1370, -1370, -1370,   839, -1370, -1370,   689, -1370, -1370, -1370,
   -1370,   843, -1370, -1370,   838, -1370, -1370, -1370, -1370,   689,
   -1370, -1370, -1370, -1370,   848, -1370, -1370,   840, -1370, -1370,
   -1370,   853, -1370, -1370, -1370, -1370
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   888, -1370,
     943, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   867,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   555, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   834, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
     496, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   837, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   394, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   683, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   374, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   336, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   349,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   342, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   343, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   332, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   331, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   116, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,    71,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,  -425, -1083, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,  -206, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
    -416, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,    88, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,    14, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,  -282,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,    33, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   -41, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,  -361, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,    64, -1370, -1370, -1370,
   -1370, -1370,  -107, -1370, -1370, -1370, -1370,  -457,  -464,  -492,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1046, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,  -154, -1370, -1370, -1370,
   -1089, -1370, -1370, -1370, -1370, -1370,  -997, -1370, -1370, -1369,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,  -485, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1044, -1370, -1370, -1370, -1370,
   -1370, -1370, -1041, -1370, -1370, -1370, -1368, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,  -186, -1370, -1370, -1370,  -484, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,  -843, -1370,  -978, -1082,
   -1370, -1370,  -817, -1370, -1370, -1370,  -144, -1370,   -51,   -65,
   -1370, -1370,  -797, -1370, -1200, -1276, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,  -360,  -372, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   963, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1172, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     473,   243,   470,   598,   602,   837,  1077,   472,  1313,  1213,
     897,   397,   861,   248,  1068,   456,  1159,  1539,  1170,   501,
    1398,  1171,   393,   276,   484,  1110,   464,   465,  1489,  1491,
     270,   267,   255,   252,   273,   264,  1289,  1099,  1371,  1377,
    1089,  1253,   493,   494,   495,   648,   384,  1419,  1259,  1361,
     652,   366,  1089,   371,   222,   656,    14,  1089,   240,   633,
     249,   623,  1016,  1145,   635,  1521,   593,   139,   240,   637,
     241,  1136,     7,   926,   623,  1193,     6,  1599,  1090,   639,
     241,   357,   595,   365,  1247,   370,  1255,   351,  1179,  1256,
     639,  1432,   624,  1390,   653,   658,  1420,  1554,  1556,   223,
     660,  1398,   803,   681,   682,   705,   639,   649,  1433,   639,
      17,   224,    12,   354,   140,  1290,  1327,  1425,   141,  1220,
     142,   723,   143,  1336,   144,  1372,   721,   355,   424,   629,
     629,  1291,   629,  1291,    30,  1415,   620,   634,   659,   726,
     253,   256,  1291,  1278,   277,   394,   268,   271,   265,  1398,
    1595,  1597,   457,   274,   648,   123,  1264,   385,   652,  1325,
     502,  1329,   656,   617,  1330,   250,   710,   592,  1153,   710,
     593,   710,   240,   710,    78,   942,   943,   639,   414,   415,
     416,   223,   594,  1453,   241,   124,   595,   125,   640,   830,
     740,   741,   592,   224,   710,   593,   710,   240,   455,  1306,
    1154,  1155,  1156,  1157,   592,  1026,   945,   594,   946,   241,
     629,   595,  1479,   354,   240,   294,   126,   636,  1347,   594,
     947,   948,   629,   639,   629,   629,   241,   355,  1273,  1274,
    1275,  1276,   713,   657,   127,   725,   645,  1514,   693,   639,
    1354,   128,   699,   700,   701,  1174,  1540,   592,  1026,   781,
     782,   131,   719,   398,   399,   400,   401,   435,   295,   436,
     629,   437,   594,     1,     2,   712,   639,  1188,  1189,  1190,
    1191,   448,   296,   450,   297,  1536,   298,   715,   299,   442,
     300,   444,   158,   446,  1383,   140,   301,  1258,   302,   141,
     303,   142,   304,   143,   305,   144,   306,   175,   307,   203,
     308,  1569,   309,   592,  1026,   206,   593,  1119,  1153,   209,
    1120,  1121,   743,  1122,   210,   942,   943,   752,   594,   211,
     628,  1575,   595,   629,  1120,  1121,  1408,  1122,   709,   212,
     854,   629,   592,   214,   597,   593,  1587,   240,  1244,  1245,
    1154,  1155,   931,    20,    21,   932,   945,   594,   946,   241,
     993,   595,  1050,   994,   213,  1051,   403,   404,  1610,   232,
     947,   948,    25,    26,   258,   942,   943,   768,   769,   770,
      33,    34,    81,    82,  1446,   279,   787,   944,   134,   135,
     160,   161,   592,   165,   166,   593,   798,   240,   170,   171,
     343,  1629,   178,   179,   464,   465,   945,   594,   946,   241,
    1488,   595,   352,  1472,   592,  1026,   362,   593,  1337,  1640,
     947,   948,   814,   183,   184,   188,   189,   193,   194,   594,
     367,   825,  1500,   595,  1188,  1189,  1190,  1191,  1507,   198,
     199,   838,  1651,   373,   680,   217,   218,   259,   260,  1213,
     280,   281,   287,   288,   345,   346,   375,   376,   849,   372,
      86,  1664,   409,   410,   425,   426,  1031,  1032,   862,   459,
     460,   381,  1672,   476,   477,   380,  1529,   496,   497,  1553,
     505,   506,   382,  1675,   387,   888,   511,   512,   383,    87,
     391,    88,   898,    89,   388,    90,  1685,    91,   389,    92,
     396,    93,  1562,    94,  1688,    95,   392,    96,   390,    97,
     516,   517,   521,   522,   526,   527,   433,  1692,   451,   937,
     532,   533,   295,   537,   538,   542,   543,   430,  1078,  1079,
     421,   739,  1594,   547,   548,   468,   296,  1580,   297,   438,
     298,   482,   299,   474,   300,   552,   553,  1111,  1112,   483,
     301,   404,   302,   999,   303,  1440,   304,   485,   305,  1603,
     306,    87,   307,    88,   308,    89,   309,    90,   504,    91,
     510,    92,   489,    93,   531,    94,   562,    95,   582,    96,
     573,    97,  1035,   557,   558,  1146,  1147,  1165,  1172,   581,
     780,  1153,  1622,   563,   564,   574,   575,  1198,   942,   943,
     568,   569,   589,   590,   662,   663,   632,   629,   666,   667,
    1633,   803,   676,   677,   580,   592,   584,  1056,   593,   583,
     240,   694,   695,  1154,  1155,   711,   629,  1322,  1323,   945,
     594,   946,   241,   477,   595,   729,   663,   735,   736,   753,
     754,   765,   766,   947,   948,   776,   777,   788,   789,   815,
     816,   585,  1657,   607,  1100,  1254,  1257,   839,   840,   863,
     864,   610,    38,   606,  1114,  1283,   871,   872,   876,   877,
     614,  1115,   615,    39,  1118,    40,    41,    42,   616,    43,
      44,    45,   622,    46,    47,    48,   621,    49,    50,    51,
     627,    52,    53,    39,   638,    40,    41,    42,   661,    43,
      44,    45,   575,    46,    47,    48,   672,    49,    50,    51,
     683,    52,    53,   882,   883,   889,   890,   899,   900,   905,
     906,   910,   911,   916,   917,   969,   970,   974,   975,   684,
    1328,  1331,   685,   980,   981,  1007,  1008,  1023,  1024,   686,
    1348,  1349,  1037,  1038,  1073,  1074,  1084,  1085,  1101,  1102,
    1106,  1107,  1141,  1142,   689,  1234,  1148,  1149,  1180,  1181,
    1185,  1186,  1207,  1208,  1221,  1222,  1239,  1240,  1265,  1266,
    1270,  1271,  1307,  1308,  1317,  1318,  1343,  1344,  1339,  1208,
    1355,  1356,  1384,  1385,  1409,  1410,  1427,  1428,  1447,  1448,
     704,  1299,  1456,  1457,  1473,  1474,  1483,  1484,  1493,  1494,
    1508,  1509,  1530,  1531,  1543,  1544,  1548,  1549,  1563,  1564,
    1581,  1582,  1589,  1590,  1604,  1605,  1623,  1624,  1634,  1635,
    1645,  1646,  1658,  1659,  1666,  1667,  1679,  1680,   702,   703,
     707,   731,   714,   708,   727,   728,   667,   744,   745,   742,
     748,   758,   763,   759,   764,   775,   784,   783,   793,   794,
     799,   800,   803,   807,   806,   809,   808,   810,   811,   813,
     821,   812,   820,   827,  1362,   830,   826,   833,   844,   845,
     846,  1369,   847,   851,   857,   850,   854,   868,   881,   893,
     915,   922,   927,   938,   979,   883,  1005,   986,   917,   989,
    1000,  1016,  1033,  1034,   931,  1012,  1019,  1036,  1043,  1057,
    1083,   993,  1013,  1080,  1046,   981,  1063,  1069,  1116,  1064,
    1095,  1113,  1117,  1392,  1393,  1050,  1131,  1206,  1160,  1137,
    1226,  1175,  1490,  1492,  1089,  1132,  1499,  1233,  1232,  1235,
    1300,  1227,  1301,  1216,  1203,  1315,  1316,  1260,  1338,  1378,
    1212,  1401,  1365,  1302,  1394,  1402,  1403,  1426,  1350,  1237,
    1463,  1467,  1538,  1417,  1418,  1520,  1314,  1379,  1523,  1516,
    1441,  1541,  1288,  1601,  1416,  1614,  1643,  1404,  1654,  1442,
    1655,   486,  1454,  1420,  1480,   130,   159,  1290,    77,  1468,
    1391,   673,  1515,  1503,  1537,   586,  1252,   716,  1558,  1363,
     233,  1555,  1557,  1370,  1570,  1291,  1366,  1525,  1588,  1576,
    1611,  1455,   722,  1372,   422,   720,   730,   724,  1573,   706,
     732,   939,  1522,  1340,  1642,  1020,  1517,  1001,  1618,  1630,
    1070,  1395,  1138,  1464,  1042,  1641,  1058,  1238,   129,     0,
    1617,  1652,  1665,     0,     0,     0,     0,     0,     0,  1502,
    1673,  1676,  1481,  1482,  1596,  1598,  1686,  1690,  1689,  1694,
    1613,     0,     0,  1693,     0,     0,     0,     0,  1631,     0,
       0,  1326,  1695,     0,     0,     0,     0,     0,     0,     0,
       0,  1524,     0,   344,  1653,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1571,
    1572,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1600,     0,     0,  1612,     0,     0,     0,
       0,  1615,  1616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1644,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1498,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1677,  1678
};

static const yytype_int16 yycheck[] =
{
     372,   155,   362,   488,   488,   802,  1003,   367,  1180,  1092,
     853,     8,   829,   157,   992,     4,  1062,     4,  1062,     4,
    1296,  1062,     4,     4,   396,  1022,     6,     7,  1397,  1397,
       4,     4,     4,     4,     4,     4,   131,  1015,   131,  1239,
     180,  1130,   414,   415,   416,   537,     4,   131,  1130,  1221,
     542,   237,   180,   239,    83,   547,    15,   180,    46,   516,
       4,   116,    40,  1060,   521,   205,    44,    81,    46,   526,
      58,  1049,    76,   870,   116,  1072,     0,   205,   201,   154,
      58,   235,    60,   237,  1130,   239,  1130,   231,  1066,  1130,
     154,    26,   147,  1265,   169,   552,   180,  1466,  1466,   128,
     557,  1377,    37,   588,   588,   147,   154,   171,    43,   154,
      78,   140,    14,    45,   128,   210,  1205,  1317,   132,  1097,
     134,   169,   136,  1205,   138,   218,   171,    59,   314,   152,
     152,   226,   152,   226,    80,  1307,   496,   157,   161,   161,
     111,   113,   226,  1140,   125,   127,   119,   121,   117,  1425,
    1519,  1519,   141,   123,   646,     5,  1134,   115,   650,  1205,
     145,  1205,   654,   143,  1205,   109,   630,    41,    17,   633,
      44,   635,    46,   637,    82,    24,    25,   154,    30,    31,
      32,   128,    56,  1355,    58,     5,    60,     5,   165,    38,
     675,   675,    41,   140,   658,    44,   660,    46,   342,  1177,
      49,    50,    51,    52,    41,    42,    55,    56,    57,    58,
     152,    60,  1384,    45,    46,    85,     5,   159,  1215,    56,
      69,    70,   152,   154,   152,   152,    58,    59,    65,    66,
      67,    68,   159,   163,     5,   163,   167,  1409,   610,   154,
    1218,    77,   614,   615,   616,  1062,   233,    41,    42,   734,
     734,    84,   167,   250,   251,   252,   253,   322,   128,   324,
     152,   326,    56,    12,    13,   157,   154,    61,    62,    63,
      64,   336,   142,   338,   144,  1447,   146,   165,   148,   330,
     150,   332,    79,   334,  1262,   128,   156,  1130,   158,   132,
     160,   134,   162,   136,   164,   138,   166,    74,   168,    73,
     170,  1473,   172,    41,    42,    16,    44,   225,    17,    89,
     228,   229,   684,   231,    93,    24,    25,   689,    56,    97,
     149,  1493,    60,   152,   228,   229,  1304,   231,   149,   101,
      39,   152,    41,    86,   488,    44,  1508,    46,    47,    48,
      49,    50,   180,    10,    11,   183,    55,    56,    57,    58,
     210,    60,   218,   213,   105,   221,   129,   130,  1530,    81,
      69,    70,    10,    11,     3,    24,    25,    21,    22,    23,
      10,    11,    10,    11,  1352,     3,   748,    36,    10,    11,
      10,    11,    41,    10,    11,    44,   758,    46,    10,    11,
      83,  1563,    10,    11,     6,     7,    55,    56,    57,    58,
    1397,    60,    10,  1381,    41,    42,    10,    44,  1205,  1581,
      69,    70,   784,    10,    11,    10,    11,    10,    11,    56,
      10,   793,  1400,    60,    61,    62,    63,    64,  1406,    10,
      11,   803,  1604,    10,   588,    10,    11,    10,    11,  1522,
      10,    11,    10,    11,    10,    11,    10,    11,   820,     3,
      79,  1623,    10,    11,    10,    11,   941,   941,   830,    10,
      11,   111,  1634,   129,   130,   109,  1444,    10,    11,  1466,
      10,    11,   113,  1645,   117,   847,    10,    11,     8,   108,
     125,   110,   854,   112,   119,   114,  1658,   116,   121,   118,
       6,   120,  1470,   122,  1666,   124,     8,   126,   123,   128,
      10,    11,    10,    11,    10,    11,    19,  1679,    27,   881,
      10,    11,   128,    10,    11,    10,    11,    18,  1003,  1003,
      85,   675,  1519,    10,    11,     3,   142,  1505,   144,    20,
     146,   115,   148,     6,   150,    10,    11,  1022,  1022,   127,
     156,   130,   158,   915,   160,  1342,   162,   129,   164,  1527,
     166,   108,   168,   110,   170,   112,   172,   114,     8,   116,
       8,   118,   176,   120,     8,   122,     8,   124,   135,   126,
     141,   128,   944,    10,    11,  1060,  1060,  1062,  1062,     8,
     734,    17,  1560,    10,    11,   129,   130,  1072,    24,    25,
      10,    11,    10,    11,   173,   174,   151,   152,   129,   130,
    1578,    37,    10,    11,   133,    41,   139,   979,    44,   137,
      46,    10,    11,    49,    50,   151,   152,    53,    54,    55,
      56,    57,    58,   130,    60,   173,   174,    10,    11,    10,
      11,    10,    11,    69,    70,    10,    11,    10,    11,    10,
      11,   129,  1620,   206,  1016,  1130,  1130,    10,    11,    10,
      11,    33,    77,    87,  1026,  1140,    10,    11,    10,    11,
       6,  1033,     6,    88,  1036,    90,    91,    92,     6,    94,
      95,    96,     6,    98,    99,   100,   145,   102,   103,   104,
       6,   106,   107,    88,     6,    90,    91,    92,     6,    94,
      95,    96,   130,    98,    99,   100,   129,   102,   103,   104,
     131,   106,   107,   179,   180,   223,   224,    10,    11,    10,
      11,    10,    11,   209,   210,    10,    11,    10,    11,     3,
    1205,  1205,     3,   217,   218,    10,    11,    10,    11,   214,
    1215,  1215,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    34,  1117,    10,    11,    10,    11,
      10,    11,   203,   204,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,   203,   204,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,  1153,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   234,   235,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,   143,     8,
       8,   129,     8,    10,     8,    10,   130,     8,   222,   131,
      35,     6,     4,   178,     4,     4,    28,   131,     6,   208,
     177,   182,    37,   153,   117,     3,   155,     3,     3,   131,
     216,   175,     6,   212,  1226,    38,   207,   184,     8,     8,
       8,  1233,     6,   220,   184,   215,    39,   200,     6,   184,
       6,   202,   186,   179,     6,   180,    29,   130,   210,   186,
     209,    40,     3,     3,   180,   185,   183,     3,   130,   217,
       8,   210,   190,   130,   186,   218,   185,   213,     8,   190,
     188,   181,     6,  1275,  1276,   218,   185,     6,  1062,   221,
       6,   188,  1397,  1397,   180,   190,  1400,     6,   181,     5,
       3,   232,     3,   192,   211,     3,     3,   188,     8,     3,
     201,     6,   187,   192,   131,     8,     8,     3,   196,   225,
     131,     8,     6,  1315,  1316,     8,   211,   192,     8,   131,
     181,    10,   219,     6,   187,     6,     8,   196,     6,   194,
       6,   406,   191,   180,   187,    77,    99,   210,    25,   196,
     219,   577,   191,   194,   189,   479,  1130,   641,   194,   236,
     146,  1466,  1466,   230,   191,   226,   237,   198,   189,   198,
     193,  1363,   650,   218,   311,   646,   664,   654,   211,   625,
     669,   885,  1427,  1209,   181,   934,  1422,   919,   198,   189,
     996,  1293,  1053,  1374,   950,   193,   983,  1124,    55,    -1,
     219,   197,   193,    -1,    -1,    -1,    -1,    -1,    -1,  1401,
     197,   195,  1392,  1393,  1519,  1519,   197,   199,   195,   199,
     233,    -1,    -1,   195,    -1,    -1,    -1,    -1,   227,    -1,
      -1,  1205,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1433,    -1,   226,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1481,
    1482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1523,    -1,    -1,  1538,    -1,    -1,    -1,
      -1,  1543,  1544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1601,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1400,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1654,  1655
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   255,   256,   257,     0,    76,   264,   265,
    1042,  1043,    14,   258,    15,   262,   263,    78,   266,   267,
      10,    11,  1044,  1045,  1046,    10,    11,   259,   260,   261,
      80,   352,   353,    10,    11,   268,   269,   270,    77,    88,
      90,    91,    92,    94,    95,    96,    98,    99,   100,   102,
     103,   104,   106,   107,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
    1063,  1064,  1065,  1066,  1067,  1068,  1069,   264,    82,   400,
     401,    10,    11,   354,   355,   356,    79,   108,   110,   112,
     114,   116,   118,   120,   122,   124,   126,   128,   271,   272,
     273,   274,   275,   280,   281,   286,   287,   292,   293,   300,
     301,   306,   307,   312,   313,   318,   319,   324,   325,   330,
     331,   338,   339,     5,     5,     5,     5,     5,    77,  1049,
     262,    84,   428,   429,    10,    11,   402,   403,   404,    81,
     128,   132,   134,   136,   138,   357,   358,   359,   360,   361,
     367,   368,   374,   375,   381,   382,   386,   387,    79,   273,
      10,    11,   276,   277,   278,    10,    11,   282,   283,   284,
      10,    11,   288,   289,   290,    74,   294,   295,    10,    11,
     302,   303,   304,    10,    11,   308,   309,   310,    10,    11,
     314,   315,   316,    10,    11,   320,   321,   322,    10,    11,
     326,   327,   328,    73,   332,   333,    16,   340,  1020,    89,
      93,    97,   101,   105,    86,   544,   545,    10,    11,   430,
     431,   432,    83,   128,   140,   405,   406,   407,   408,   409,
     414,   415,    81,   359,   362,   363,   369,   370,   376,   377,
      46,    58,   383,   950,   951,   952,   953,   388,  1020,     4,
     109,   279,     4,   111,   285,     4,   113,   291,     3,    10,
      11,   296,   297,   298,     4,   117,   305,     4,   119,   311,
       4,   121,   317,     4,   123,   323,     4,   125,   329,     3,
      10,    11,   334,   335,   336,  1039,  1040,    10,    11,   341,
     342,   343,   546,   547,    85,   128,   142,   144,   146,   148,
     150,   156,   158,   160,   162,   164,   166,   168,   170,   172,
     433,   434,   435,   436,   437,   444,   445,   450,   451,   458,
     459,   463,   464,   468,   469,   473,   474,   478,   479,   486,
     487,   494,   495,   502,   503,   510,   511,   516,   517,   522,
     523,   530,   531,    83,   407,    10,    11,   410,   411,   412,
     416,  1020,    10,   365,    45,    59,   364,   950,   998,   999,
    1000,  1001,    10,   372,   371,   950,   998,    10,   379,   378,
     950,   998,     3,    10,   384,    10,    11,   389,   390,   391,
     109,   111,   113,     8,     4,   115,   299,   117,   119,   121,
     123,   125,     8,     4,   127,   337,     6,     8,   250,   251,
     252,   253,  1041,   129,   130,   344,   345,   346,   347,    10,
      11,   549,   550,   551,    30,    31,    32,   548,  1011,  1017,
    1027,    85,   435,   438,   998,    10,    11,   446,   447,   448,
      18,   452,  1015,    19,  1023,  1023,  1023,  1023,    20,   480,
    1022,   488,  1022,   496,  1022,   504,  1022,   512,  1023,   518,
    1023,    27,   524,  1024,   532,  1020,     4,   141,   413,    10,
      11,   417,   418,   419,     6,     7,   366,  1038,     3,   373,
    1038,   380,  1038,  1039,     6,   385,   129,   130,   392,   393,
     394,   395,   115,   127,  1039,   129,   346,   348,   349,   176,
     552,   553,   554,  1039,  1039,  1039,    10,    11,   439,   440,
     441,     4,   145,   449,     8,    10,    11,   453,   454,   455,
       8,    10,    11,   460,   461,   462,    10,    11,   465,   466,
     467,    10,    11,   470,   471,   472,    10,    11,   475,   476,
     477,     8,    10,    11,   481,   482,   483,    10,    11,   489,
     490,   491,    10,    11,   497,   498,   499,    10,    11,   505,
     506,   507,    10,    11,   513,   514,   515,    10,    11,   519,
     520,   521,     8,    10,    11,   525,   526,   527,    10,    11,
     533,   534,   535,   141,   129,   130,   420,   421,   422,   423,
     133,     8,   135,   137,   139,   129,   394,   396,   397,    10,
      11,   351,    41,    44,    56,    60,   350,   950,   971,   972,
     973,   974,  1002,  1003,  1004,  1005,    87,   206,   691,   692,
      33,   555,   556,  1021,     6,     6,     6,   143,   442,   443,
    1038,   145,     6,   116,   147,   456,   457,     6,   149,   152,
     931,   932,   151,   931,   157,   931,   159,   931,     6,   154,
     165,   484,   485,   933,   934,   167,   492,   493,   933,   171,
     500,   501,   933,   169,   508,   509,   933,   163,   931,   161,
     931,     6,   173,   174,   528,   529,   129,   130,   536,   537,
     538,   539,   129,   422,   424,   425,    10,    11,   399,   398,
     950,   971,  1002,   131,     3,     3,   214,   800,   801,    34,
     693,   694,  1019,  1039,    10,    11,   557,   558,   559,  1039,
    1039,  1039,   143,     8,    10,   147,   457,     8,    10,   149,
     932,   151,   157,   159,     8,   165,   485,   935,   936,   167,
     493,   171,   501,   169,   509,   163,   161,     8,    10,   173,
     529,   129,   538,   540,   541,    10,    11,   427,   426,   950,
     971,  1002,   131,  1039,     8,   222,   909,   910,    35,   802,
     803,  1018,  1039,    10,    11,   695,   696,   697,     6,   178,
     560,   561,   562,     4,     4,    10,    11,   941,    21,    22,
      23,   937,   938,   939,   940,     4,    10,    11,   543,   542,
     950,   971,  1002,   131,    28,   911,  1025,  1039,    10,    11,
     804,   805,   806,     6,   208,   698,   699,   700,  1039,   177,
     182,   575,   576,    37,   563,  1026,   117,   153,   155,     3,
       3,     3,   175,   131,  1039,    10,    11,   912,   913,   914,
       6,   216,   807,   808,   809,  1039,   207,   212,   713,   714,
      38,   701,  1016,   184,   589,   590,   577,  1026,  1039,    10,
      11,   564,   565,   566,     8,     8,     8,     6,   915,  1039,
     215,   220,   822,   823,    39,   810,  1010,   184,   727,   728,
     715,  1016,  1039,    10,    11,   702,   703,   704,   200,   644,
     645,    10,    11,   591,   592,   593,    10,    11,   578,   579,
     580,     6,   179,   180,   567,   568,   569,   570,  1039,   223,
     224,   916,   917,   184,   836,   837,   824,  1010,  1039,    10,
      11,   811,   812,   813,   782,    10,    11,   729,   730,   731,
      10,    11,   716,   717,   718,     6,   209,   210,   705,   706,
     707,   708,   202,   658,   659,   646,  1026,   186,   594,   595,
     596,   180,   183,   581,   582,   583,   584,  1039,   179,   569,
     571,   572,    24,    25,    36,    55,    57,    69,    70,   918,
     919,   920,   942,   943,   944,   945,   950,   971,   979,   980,
     981,   982,   986,   987,   988,   989,  1002,  1014,   891,    10,
      11,   838,   839,   840,    10,    11,   825,   826,   827,     6,
     217,   218,   814,   815,   816,   817,   130,   783,   784,   186,
     732,   733,   734,   210,   213,   719,   720,   721,   722,  1039,
     209,   707,   709,   710,   673,    29,   660,    10,    11,   647,
     648,   649,   185,   190,   602,   603,    40,   597,  1012,   183,
     583,   585,   586,    10,    11,   574,    42,   573,   960,   961,
     962,   971,  1002,     3,     3,  1039,     3,    10,    11,   921,
     922,   923,   920,   130,   892,   893,   186,   841,   842,   843,
     218,   221,   828,   829,   830,   831,  1039,   217,   816,   818,
     819,   785,   786,   185,   190,   740,   741,   735,  1012,   213,
     721,   723,   724,    10,    11,   712,   711,   960,   971,  1002,
     130,   674,   675,     8,    10,    11,   661,   662,   663,   180,
     201,   650,   651,   652,   653,   188,   609,   610,   604,  1012,
    1039,    10,    11,   598,   599,   600,    10,    11,   588,   587,
     960,   971,  1002,   181,  1039,  1039,     8,     6,  1039,   225,
     228,   229,   231,   924,   925,   926,   927,   928,   929,   894,
     895,   185,   190,   849,   850,   844,  1012,   221,   830,   832,
     833,    10,    11,   821,   820,   960,   971,  1002,    10,    11,
     788,   789,   790,    17,    49,    50,    51,    52,   787,   942,
     950,   954,   955,   956,   957,   971,   975,   976,   977,   978,
     979,   986,  1002,  1013,  1016,   188,   747,   748,   742,  1012,
      10,    11,   736,   737,   738,    10,    11,   726,    61,    62,
      63,    64,   725,   960,   963,   964,   965,   966,   971,   990,
     991,   992,   993,   211,   676,   677,     6,   203,   204,   664,
     665,   666,   201,   652,   654,   655,   192,   616,   617,   611,
    1012,    10,    11,   605,   606,   607,     6,   232,   601,  1070,
    1071,  1078,   181,     6,  1039,     5,   930,   225,   926,    10,
      11,   897,   898,   899,    47,    48,   896,   942,   946,   947,
     948,   949,   950,   954,   971,   979,   986,  1002,  1010,  1013,
     188,   856,   857,   851,  1012,    10,    11,   845,   846,   847,
      10,    11,   835,    65,    66,    67,    68,   834,   960,   967,
     968,   969,   970,   971,   994,   995,   996,   997,   219,   131,
     210,   226,   791,   792,   793,   794,  1028,  1029,  1030,  1039,
       3,     3,   192,   754,   755,   749,  1012,    10,    11,   743,
     744,   745,   739,  1070,   211,     3,     3,    10,    11,   679,
     680,   681,    53,    54,   678,   942,   950,   954,   971,   979,
     986,  1002,  1006,  1007,  1008,  1009,  1013,  1026,     8,   203,
     665,   667,   668,    10,    11,   657,   656,   960,   971,  1002,
     196,   623,   624,   618,  1012,    10,    11,   612,   613,   614,
     608,  1070,  1039,   236,  1079,   187,   237,  1072,  1073,  1039,
     230,   131,   218,   900,   901,   902,   903,  1028,     3,   192,
     863,   864,   858,  1012,    10,    11,   852,   853,   854,   848,
    1070,   219,  1039,  1039,   131,   793,   795,   796,  1029,  1031,
    1032,     6,     8,     8,   196,   761,   762,   756,  1012,    10,
      11,   750,   751,   752,   746,  1070,   187,  1039,  1039,   131,
     180,   682,   683,   684,   685,  1028,     3,    10,    11,   670,
     671,   672,    26,    43,   669,   958,   959,   983,   984,   985,
    1026,   181,   194,   630,   631,   625,  1012,    10,    11,   619,
     620,   621,   615,  1070,   191,  1039,    10,    11,  1080,  1081,
    1082,  1074,  1075,   131,   902,   904,   905,     8,   196,   870,
     871,   865,  1012,    10,    11,   859,   860,   861,   855,  1070,
     187,  1038,  1038,    10,    11,   798,   799,   797,   960,   963,
     971,   990,  1002,    10,    11,  1034,  1035,  1036,   950,  1002,
    1012,  1033,  1039,   194,   768,   769,   763,  1012,    10,    11,
     757,   758,   759,   753,  1070,   191,   131,   684,   686,   687,
       8,   205,   651,     8,  1039,   198,   637,   638,   632,  1012,
      10,    11,   626,   627,   628,   622,  1070,   189,     6,     4,
     233,    10,  1077,   234,   235,  1076,  1083,  1084,    10,    11,
     907,   908,   906,   960,   963,   971,   990,  1002,   194,   877,
     878,   872,  1012,    10,    11,   866,   867,   868,   862,  1070,
     191,  1039,  1039,   211,  1037,  1070,   198,   775,   776,   770,
    1012,    10,    11,   764,   765,   766,   760,  1070,   189,    10,
      11,   689,   690,   688,   960,   963,   971,   990,  1002,   205,
    1038,     6,   639,  1012,    10,    11,   633,   634,   635,   629,
    1070,   193,  1039,   233,     6,  1039,  1039,   219,   198,   884,
     885,   879,  1012,    10,    11,   873,   874,   875,   869,  1070,
     189,   227,   777,  1012,    10,    11,   771,   772,   773,   767,
    1070,   193,   181,     8,  1039,    10,    11,   640,   641,   642,
     636,  1070,   197,   238,     6,     6,   886,  1012,    10,    11,
     880,   881,   882,   876,  1070,   193,    10,    11,   778,   779,
     780,   774,  1070,   197,   643,  1070,   195,  1039,  1039,    10,
      11,   887,   888,   889,   883,  1070,   197,   781,  1070,   195,
     199,   890,  1070,   195,   199,   199
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
      yyerror (&yylloc, osoption, parserData, osglData, YY_("syntax error: cannot back up")); \
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
		  Type, Value, Location, osoption, parserData, osglData); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osoption);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osoption, parserData, osglData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSOption *osoption;
    OSoLParserData *parserData;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osoption, parserData, osglData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osoption, parserData, osglData); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osoption, parserData, osglData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osoption);
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
int yyparse (OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
yyparse (OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData)
#else
int
yyparse (osoption, parserData, osglData)
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  yylloc.first_column = yylloc.last_column = 1;
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
    parserData->parser_errors = "";
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;
}
    break;

  case 12:

    {
        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSoL input is either not valid or well formed.\n"); 
            osolerror( NULL, osoption, parserData, osglData, parserData->parser_errors);
        }
    }
    break;

  case 14:

    { parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "unexpected end of file, expecting </osol>");}
    break;

  case 17:

    {
    if (!osoption->setHeader(osglData->fileName, osglData->source,
            osglData->description, osglData->fileCreator, osglData->licence) )     
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setHeader failed");
}
    break;

  case 20:

    {
    parserData->serviceURIPresent          = false;    
    parserData->serviceNamePresent         = false;
    parserData->instanceNamePresent        = false;
    parserData->instanceLocationPresent    = false;
    parserData->jobIDPresent               = false;
    parserData->solverToInvokePresent      = false;
    parserData->licensePresent             = false;
    parserData->usernamePresent            = false;
    parserData->passwordPresent            = false;
    parserData->contactPresent             = false;
    parserData->otherGeneralOptionsPresent = false;
    osoption->general = new GeneralOption();
}
    break;

  case 41:

    {
    if (parserData->serviceURIPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <serviceURI>");
    else
        parserData->serviceURIPresent = true;
    
}
    break;

  case 47:

    {
        if (osoption->setServiceURI((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceURI failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 49:

    {
        if (parserData->serviceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <serviceName>");
        parserData->serviceNamePresent = true;
    }
    break;

  case 55:

    {
        if (osoption->setServiceName((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceName failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 57:

    {    if (parserData->instanceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <instanceName>");
        parserData->instanceNamePresent = true;
    }
    break;

  case 63:

    {
        if (osoption->setInstanceName((yyvsp[(1) - (1)].sval)) == false) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setInstanceName failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 64:

    {
    if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setInstanceLocation failed");
    parserData->errorText = NULL;
}
    break;

  case 65:

    {
        if (parserData->instanceLocationPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <instanceLocation>");
        parserData->instanceLocationPresent = true;
        parserData->typeAttribute = "local";
    }
    break;

  case 67:

    {   
        if (verifyLocationType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "instance location type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 68:

    { 
    parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 74:

    {    
        parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval)); 
    }
    break;

  case 76:

    {    if (parserData->jobIDPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <jobID>");
        parserData->jobIDPresent = true;
    }
    break;

  case 82:

    {
        if (osoption->setJobID((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setJobID failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 84:

    {
        if (parserData->solverToInvokePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <solverToInvoke>");
        parserData->solverToInvokePresent = true;
    }
    break;

  case 90:

    {
        if (osoption->setSolverToInvoke((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setSolverToInvoke failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 92:

    {
    if (parserData->licensePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <license>");
    parserData->licensePresent = true;    
}
    break;

  case 98:

    {
        if (osoption->setLicense((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setLicense failed");
        free((yyvsp[(1) - (1)].sval));
        parserData->errorText = NULL;
    }
    break;

  case 100:

    {    if (parserData->usernamePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <username>");
    parserData->usernamePresent = true;    
}
    break;

  case 106:

    {
        if (osoption->setUserName((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setUsername failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 108:

    {    if (parserData->passwordPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <password>");
    parserData->passwordPresent = true;    
}
    break;

  case 114:

    {
        if (osoption->setPassword((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setPassword failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 115:

    {
    if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setContact failed");
    parserData->errorText = NULL;
}
    break;

  case 116:

    {
    if (parserData->contactPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <contact>");
    parserData->contactPresent = true;
    parserData->typeAttribute = "osp";
    parserData->tempStr = "";
}
    break;

  case 118:

    {   
        if (verifyTransportType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "transport type not recognized");
    }
    break;

  case 119:

    { 
        parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
        free((yyvsp[(2) - (3)].sval));
    }
    break;

  case 125:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
    }
    break;

  case 126:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 127:

    {
        if (parserData->otherGeneralOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <general> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
        parserData->otherGeneralOptionsPresent = true;
    }
    break;

  case 128:

    {
        if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other general options cannot be negative");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 129:

    {
        if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 130:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 137:

    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherGeneralOption failed");
    }
    break;

  case 138:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 139:

    {
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 142:

    {    if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
    }
    break;

  case 149:

    {
    parserData->minDiskSpacePresent = false;    
    parserData->minMemoryPresent = false;
    parserData->minCPUSpeedPresent = false;
    parserData->minCPUNumberPresent = false;
    parserData->otherSystemOptionsPresent = false;
    osoption->system = new SystemOption();
}
    break;

  case 164:

    {    if (parserData->minDiskSpacePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one minDiskSpace element allowed");
        parserData->minDiskSpacePresent = true;    
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "byte";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 171:

    {
    if (osoption->setMinDiskSpace(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setMinDiskSpace failed");
    parserData->errorText = NULL;
}
    break;

  case 173:

    {    if (parserData->minMemoryPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one minMemory element allowed");
        parserData->minMemoryPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "byte";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 180:

    {
    if (osoption->setMinMemorySize(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setMinMemorySize failed");
    parserData->errorText = NULL;
}
    break;

  case 182:

    {    if (parserData->minCPUSpeedPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one minCPUSpeed element allowed");
        parserData->minCPUSpeedPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "hertz";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 189:

    {    
    if (osoption->setMinCPUSpeed(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
}
    break;

  case 191:

    {    if (parserData->minCPUNumberPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one minCPUNumber element allowed");
        parserData->minCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 195:

    {
    if (osoption->setMinCPUNumber((yyvsp[(1) - (1)].ival), parserData->descriptionAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setMinCPUNumber failed");
    //free($1); 
    parserData->errorText = NULL; 
}
    break;

  case 196:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 197:

    {
    if (parserData->otherSystemOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <system> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->otherSystemOptionsPresent = true;
}
    break;

  case 198:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other system options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 199:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 200:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 207:

    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherSystemOption failed");
    }
    break;

  case 208:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 209:

    {    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 212:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
    }
    break;

  case 219:

    {
    parserData->serviceTypePresent = false;    
    parserData->otherServiceOptionsPresent = false;
    osoption->service = new ServiceOption();
}
    break;

  case 231:

    {    if (parserData->serviceTypePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one currentState element allowed");
        parserData->serviceTypePresent = true;
    }
    break;

  case 237:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); 
        free((yyvsp[(1) - (1)].sval));
        if (osoption->setServiceType(parserData->tempStr) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceType failed; current system state not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 238:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 239:

    {
    if (parserData->otherServiceOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <service> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherServiceOptionsPresent = true;
}
    break;

  case 240:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other service options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 241:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 242:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 249:

    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherServiceOption failed");
    }
    break;

  case 250:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 251:

    {    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 254:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
    }
    break;

  case 261:

    {
    parserData->maxTimePresent = false;    
    parserData->requestedStartTimePresent = false;    
    parserData->dependenciesPresent = false;    
    parserData->requiredDirectoriesPresent = false;    
    parserData->requiredFilesPresent = false;    
    parserData->directoriesToMakePresent = false;    
    parserData->filesToMakePresent = false;    
    parserData->inputDirectoriesToMovePresent = false;    
    parserData->inputFilesToMovePresent = false;    
    parserData->outputDirectoriesToMovePresent = false;    
    parserData->outputFilesToMovePresent = false;    
    parserData->filesToDeletePresent = false;    
    parserData->directoriesToDeletePresent = false;    
    parserData->processesToKillPresent = false;    
    parserData->otherJobOptionsPresent = false;     
    osoption->job = new JobOption();
 }
    break;

  case 285:

    {    
    if (osoption->setMaxTime(parserData->maxTimeValue, parserData->unitAttribute) == false)       
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "max time request could not be honored");
}
    break;

  case 286:

    {    
    if (parserData->maxTimePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <maxTime> element allowed");
    parserData->maxTimePresent = true;
    parserData->unitAttributePresent = false;    
    parserData->unitAttribute = "second"; 
    parserData->maxTimeValue = OSDBL_MAX;
}
    break;

  case 295:

    {
    parserData->maxTimeValue = parserData->tempVal;
}
    break;

  case 297:

    {    if (parserData->requestedStartTimePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one requestedStartTime element allowed");
        parserData->requestedStartTimePresent = true;
    }
    break;

  case 303:

    {
        if (osoption->setRequestedStartTime((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setRequestedStartTime failed");    
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
        }
    break;

  case 304:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <job> <dependencies> failed");
    delete[] parserData->jobDependencies;
    parserData->jobDependencies = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 305:

    {
    if (parserData->dependenciesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <dependencies> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->dependenciesPresent = true;
}
    break;

  case 311:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few job IDs in <dependencies> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 314:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many job IDs in <dependencies> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->jobDependencies[parserData->kounter] = (yyvsp[(3) - (4)].sval);
        parserData->kounter++;
    }
    free((yyvsp[(3) - (4)].sval)); 
}
    break;

  case 315:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <requiredDirectories> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 316:

    {
    if (parserData->requiredDirectoriesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <requiredDirectories> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredDirectoriesPresent = true;
}
    break;

  case 321:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <requiredDirectories> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 322:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <requiredFiles> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 323:

    {
    if (parserData->requiredFilesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <requiredFiles> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredFilesPresent = true;
}
    break;

  case 328:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <requiredFiles> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 329:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <directoriesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 330:

    {
    if (parserData->directoriesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <directoriesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToMakePresent = true;
}
    break;

  case 335:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <directoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 336:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <filesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 337:

    {
    if (parserData->filesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <filesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToMakePresent = true;
}
    break;

  case 342:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <filesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 343:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;
}
    break;

  case 344:

    {
    if (parserData->inputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <inputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputDirectoriesToMovePresent = true;
}
    break;

  case 350:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <inputDirectoriesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 354:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputFilesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 355:

    {
    if (parserData->inputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <inputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputFilesToMovePresent = true;
}
    break;

  case 361:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <inputFilesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 365:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 366:

    {
    if (parserData->outputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <outputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputFilesToMovePresent = true;
}
    break;

  case 372:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <outputFilesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 376:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 377:

    {
    if (parserData->outputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <outputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputDirectoriesToMovePresent = true;
}
    break;

  case 383:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <outputDirectoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 387:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <filesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 388:

    {
    if (parserData->filesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <filesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToDeletePresent = true;
}
    break;

  case 394:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <filesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 395:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <directoriesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 396:

    {
    if (parserData->directoriesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <directoriesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToDeletePresent = true;
}
    break;

  case 402:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <directoriesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 403:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <processesToKill> failed");
    delete[] parserData->processesToKill;
    parserData->processesToKill = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 404:

    {
    if (parserData->processesToKillPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <processesToKill> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->processesToKillPresent = true;
}
    break;

  case 410:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few process IDs in <processesToKill> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 413:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
    if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many process IDs in <processesToKill> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->processesToKill[parserData->kounter] = (yyvsp[(3) - (4)].sval);
        parserData->kounter++;
    }
    free((yyvsp[(3) - (4)].sval)); 
}
    break;

  case 414:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 415:

    {
    if (parserData->otherJobOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <job> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherJobOptionsPresent = true;
}
    break;

  case 416:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other job options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 417:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 418:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 425:

    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherJobOption failed");
    }
    break;

  case 426:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 427:

    {
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 430:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
    }
    break;

  case 437:

    {
    osoption->optimization = new OptimizationOption();
    parserData->numberOfVariablesPresent = false;
    parserData->numberOfObjectivesPresent = false;
    parserData->numberOfConstraintsPresent = false;
}
    break;

  case 441:

    {    
        parserData->numberOfVariables = parserData->tempInt; 
        if (osoption->setNumberOfVariables(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfVariables failed");
    }
    break;

  case 442:

    {
        parserData->numberOfConstraints = parserData->tempInt; 
        if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfConstraints failed");
    }
    break;

  case 443:

    {    
        parserData->numberOfObjectives = parserData->tempInt; 
        if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfObjectives failed");
    }
    break;

  case 451:

    {
    parserData->numberOfOtherVariableOptions = 0;
    osoption->optimization->variables = new VariableOption();
}
    break;

  case 452:

    {    
    if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
}
    break;

  case 454:

    {    
    parserData->numberOfOtherVariableOptions = parserData->tempInt;
}
    break;

  case 459:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 461:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValues(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 462:

    {
    parserData->numberOfVarAttributePresent = false;
}
    break;

  case 463:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfVar];
    parserData->namArray = new std::string[parserData->numberOfVar];
    parserData->valArray = new      double[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 464:

    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValues>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 465:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValues>: fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 472:

    {
    parserData->kounter++;
}
    break;

  case 473:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
}
    break;

  case 474:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 477:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 478:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 479:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 483:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValuesString> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valueString;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valueString = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 484:

    {
    parserData->numberOfVarAttributePresent = false;
}
    break;

  case 485:

    {
    parserData->kounter = 0;
    parserData->idxArray    = new         int[parserData->numberOfVar];
    parserData->namArray    = new std::string[parserData->numberOfVar];
    parserData->valueString = new std::string[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valueString[i] = "";
}
    break;

  case 486:

    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValuesString>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 487:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few initial values in <initialVariableValuesString> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 494:

    {
    parserData->kounter++;
}
    break;

  case 495:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->valueAttribute = "48r 87e WY EUV e7 df"; //random string...
}
    break;

  case 496:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 499:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 500:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 501:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->valueString[parserData->kounter] = parserData->valueAttribute;
    }
    break;

  case 506:

    {
    osoption->optimization->variables->initialBasisStatus = new BasisStatus();
}
    break;

  case 513:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 514:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 515:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 522:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 523:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 524:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 531:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 532:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 533:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 540:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 541:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 542:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 549:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 550:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 551:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 558:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 559:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 560:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 567:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 568:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 569:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 576:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 577:

    {
    parserData->numberOfVarAttributePresent = false;
}
    break;

  case 578:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfVar];
    parserData->namArray = new std::string[parserData->numberOfVar];
    parserData->valArray = new      double[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 579:

    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 580:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 587:

    {
    parserData->kounter++;
}
    break;

  case 588:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;
    parserData->valueAttribute = "1.0";
}
    break;

  case 589:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 592:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 593:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 594:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 598:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 599:

    {
    parserData->sosIdxAttributePresent = false;    
    parserData->currentSOS = 0;
}
    break;

  case 600:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <sos> elements must be nonnegative");
    parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
}
    break;

  case 601:

    {
        if (parserData->numberOfSOS > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <sos> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 602:

    {    if (parserData->currentSOS != parserData->numberOfSOS)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <sos> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 608:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setAnotherSOSVariableBranchingWeight(parserData->sosIdx, 
                    parserData->numberOfVar, parserData->groupWeight,
                    parserData->idxArray,     parserData->valArray, parserData->namArray) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "error processing SOS branching weights");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->currentSOS++;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 609:

    {
    if (parserData->currentSOS >= parserData->numberOfSOS)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many SOS branching weights");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->sosIdxAttributePresent = false;
    parserData->groupWeightAttributePresent = false;
    parserData->numberOfVarAttributePresent = false;
    parserData->groupWeight = 1.0;
    parserData->numberOfSOSVar = 0;
}
    break;

  case 610:

    {
    if (!parserData->sosIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index required");
    if (!parserData->numberOfVarAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar required");
}
    break;

  case 614:

    {
        parserData->kounter = 0;
        parserData->idxArray = new         int[parserData->numberOfVar];
        parserData->namArray = new std::string[parserData->numberOfVar];
        parserData->valArray = new      double[parserData->numberOfVar];
        for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
        parserData->numberOfVarAttributePresent = true;
    }
    break;

  case 623:

    {      
        parserData->iOther++;
    }
    break;

  case 624:

    {
    if (parserData->iOther >= parserData->numberOfOtherVariableOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherVariableOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfVarAttributePresent = false;
    parserData->numberOfVar = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->varTypeAttributePresent = false;    
    parserData->varTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_variables;
}
    break;

  case 625:

    {
        if (!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherVariableOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfVar,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->varTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
    }
    break;

  case 628:

    {
        parserData->kounter = 0;
    }
    break;

  case 629:

    {
        parserData->kounter = 0;
    }
    break;

  case 647:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherVariableOptionVar(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set other variable option <var> element failed");
    parserData->kounter++;
}
    break;

  case 648:

    {
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 652:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
        };
    }
    break;

  case 662:

    {
    parserData->numberOfOtherObjectiveOptions = 0; 
    osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 663:

    {    
    if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
}
    break;

  case 665:

    {    
    parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
}
    break;

  case 670:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 672:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjValues(parserData->numberOfObj, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialObjectiveValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 673:

    {
    parserData->numberOfObjAttributePresent = false;
}
    break;

  case 674:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfObj];
    parserData->namArray = new std::string[parserData->numberOfObj];
    parserData->valArray = new      double[parserData->numberOfObj];
    for (int i=0; i < parserData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < parserData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfObj; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 675:

    {    
        if (parserData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 676:

    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 683:

    {
    parserData->kounter++;
}
    break;

  case 684:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->idxAttribute = -1;
}
    break;

  case 688:

    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 689:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 690:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 694:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjBounds(parserData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialObjectiveBounds> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 695:

    {
    parserData->numberOfObjAttributePresent = false;
}
    break;

  case 696:

    {
    parserData->kounter = 0;
    parserData->idxArray   = new         int[parserData->numberOfObj];
    parserData->lbValArray = new      double[parserData->numberOfObj];
    parserData->ubValArray = new      double[parserData->numberOfObj];
    parserData->namArray   = new std::string[parserData->numberOfObj];
    for (int i=0; i < parserData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < parserData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfObj; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < parserData->numberOfObj; i++) parserData->ubValArray[i] = OSNaN();
}
    break;

  case 697:

    {
        if (parserData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 698:

    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 705:

    {
    parserData->kounter++;
}
    break;

  case 706:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->idxAttribute = -1;
    parserData->lbValueAttribute = "-INF";
    parserData->ubValueAttribute = "INF";
}
    break;

  case 710:

    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be nonnegative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 711:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 712:

    {
        if (parserData->lbValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
    }
    break;

  case 713:

    {
        if (parserData->ubValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
    }
    break;

  case 718:

    {
    osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
}
    break;

  case 725:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 726:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 727:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 734:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 735:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 736:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 743:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 744:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 745:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 752:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 753:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 754:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 761:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 762:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 763:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 770:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 771:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 772:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 779:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 780:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 781:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 789:

    {      
        parserData->iOther++;  
    }
    break;

  case 790:

    {
    if (parserData->iOther >= parserData->numberOfOtherObjectiveOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherObjectiveOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfObjAttributePresent = false;    
    parserData->numberOfObj = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->objTypeAttributePresent = false;    
    parserData->objTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_objectives;
}
    break;

  case 791:

    {
        if (!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherObjectiveOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfObj,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->objTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
    }
    break;

  case 794:

    {
        parserData->kounter = 0;
    }
    break;

  case 795:

    {
        parserData->kounter = 0;
    }
    break;

  case 813:

    {  
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherObjectiveOptionObj(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set other objective option <obj> element failed");
    parserData->kounter++;
}
    break;

  case 814:

    {

    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->idxAttribute = -1;
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 818:

    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
        };
    }
    break;

  case 828:

    {
    parserData->numberOfOtherConstraintOptions = 0; 
    osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 829:

    {    
    if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherConstraintOptions failed");
    parserData->iOther = 0;
}
    break;

  case 831:

    {    
    parserData->numberOfOtherConstraintOptions = parserData->tempInt;
}
    break;

  case 836:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 838:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitConValues(parserData->numberOfCon, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 839:

    {
    parserData->numberOfConAttributePresent = false;
}
    break;

  case 840:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfCon];
    parserData->namArray = new std::string[parserData->numberOfCon];
    parserData->valArray = new      double[parserData->numberOfCon];
    for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfCon; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 841:

    {
        if (parserData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: expected at least one <con element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 842:

    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 849:

    {
    parserData->kounter++;
}
    break;

  case 850:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
}
    break;

  case 851:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 854:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 855:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 856:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 860:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitDualValues(parserData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 861:

    {
    parserData->numberOfConAttributePresent = false;
}
    break;

  case 862:

    {
    parserData->kounter = 0;
    parserData->idxArray   = new         int[parserData->numberOfCon];
    parserData->namArray   = new std::string[parserData->numberOfCon];
    parserData->lbValArray = new      double[parserData->numberOfCon];
    parserData->ubValArray = new      double[parserData->numberOfCon];
    for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfCon; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < parserData->numberOfCon; i++) parserData->ubValArray[i] = OSNaN();
}
    break;

  case 863:

    {
        if (parserData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: expected at least one <con> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 864:

    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 871:

    {    
    parserData->kounter++;
}
    break;

  case 872:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->lbDualValue = OSNaN();
    parserData->ubDualValue = OSNaN();
}
    break;

  case 873:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 876:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 877:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 878:

    {
        parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
    }
    break;

  case 879:

    {
        parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
    }
    break;

  case 884:

    {
    osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
}
    break;

  case 891:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 892:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 893:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 900:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 901:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 902:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 909:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 910:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 911:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 918:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 919:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 920:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 927:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 928:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 929:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 936:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 937:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 938:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 945:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 946:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 947:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 955:

    {      
        parserData->iOther++;  
    }
    break;

  case 956:

    {
    if (parserData->iOther >= parserData->numberOfOtherConstraintOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherConstraintOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfConAttributePresent = false;    
    parserData->numberOfCon = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->conTypeAttributePresent = false;    
    parserData->conTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_constraints;
}
    break;

  case 957:

    {
        if(!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherConstraintOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfCon,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->conTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
    }
    break;

  case 960:

    {
        parserData->kounter = 0;
    }
    break;

  case 961:

    {
        parserData->kounter = 0;
    }
    break;

  case 979:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherConstraintOptionCon(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set other constraint option <con> element failed");
    parserData->kounter++;
}
    break;

  case 980:

    {
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 984:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
        };
    }
    break;

  case 993:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 995:

    {
    if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfSolverOptions failed");
    parserData->iOption = 0;
}
    break;

  case 996:

    {
        if (parserData->numberOfSolverOptions > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <solverOption> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 997:

    {
        if (parserData->iOption != parserData->numberOfSolverOptions)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <solverOption> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 1002:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setSolverOptionContent(
                    parserData->iOption, 
                    parserData->numberOfItems,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->descriptionAttribute,
                    parserData->itemList) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setSolverOptionContent failed");
    if (parserData->numberOfItems > 0)
        delete[] parserData->itemList;
    parserData->itemList = NULL;
    parserData->iOption++;
}
    break;

  case 1003:

    {
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->solverAttributePresent = false;
    parserData->categoryAttributePresent = false;
    parserData->typeAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->numberOfItemsPresent = false;
    parserData->valueAttribute = "";
    parserData->solverAttribute = "";
    parserData->categoryAttribute = "";
    parserData->typeAttribute = "";
    parserData->descriptionAttribute = "";
    parserData->numberOfItems = 0;
    parserData->kounter = 0;
}
    break;

  case 1004:

    {
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "name attribute must be present");
}
    break;

  case 1013:

    {
            parserData->itemList = new std::string[parserData->numberOfItems];
    }
    break;

  case 1014:

    {
        if (parserData->numberOfItems > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <item> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 1015:

    {
        if (parserData->kounter < parserData->numberOfItems)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <item> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 1022:

    {    
    parserData->itemList[parserData->kounter] = parserData->itemContent;
    parserData->kounter++;
}
    break;

  case 1023:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            if (!parserData->suppressFurtherErrorMessages)
            {
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <item> elements than specified");
                parserData->suppressFurtherErrorMessages = true;
                parserData->ignoreDataAfterErrors = true;
            }
        parserData->itemContent = "";            
    }
    break;

  case 1028:

    {
    if (parserData->kounter >= parserData->numberOf)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <item> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->itemContent = (yyvsp[(1) - (1)].sval); 
    free((yyvsp[(1) - (1)].sval));
}
    break;

  case 1031:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many paths in <requiredDirectories> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
        parserData->kounter++;
    }
    free((yyvsp[(3) - (4)].sval)); 
}
    break;

  case 1032:

    {    
    if (parserData->kounter >= parserData->numberOfPathPairs)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many path pairs");
    else
    {
        if (!parserData->pathPairFromPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "\"from\" attribute must be present");
        if (!parserData->pathPairToPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "\"to\" attribute must be present");
           parserData->fromPaths[parserData->kounter] = parserData->pathPairFrom;
           parserData->toPaths[parserData->kounter] = parserData->pathPairTo;
        parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
         parserData->kounter++;
    }
}
    break;

  case 1033:

    {
//    if (parserData->kounter >= parserData->numberOfPathPairs)
//        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many path pairs");
    parserData->pathPairFrom = "";
    parserData->pathPairTo = "";
    parserData->pathPairFromPresent = false;
    parserData->pathPairToPresent = false;
    parserData->pathPairMakeCopyPresent = false;
    parserData->pathPairMakeCopy = false;
}
    break;

  case 1034:

    {
//    parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 1040:

    {
    if (parserData->pathPairFromPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"from\" attribute allowed");
    parserData->pathPairFromPresent = true;
    parserData->pathPairFrom = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1041:

    {
    if (parserData->pathPairToPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"to\" attribute allowed");
    parserData->pathPairToPresent = true;
    parserData->pathPairTo = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1042:

    {
    if (parserData->pathPairMakeCopyPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"makeCopy\" attribute allowed");
    parserData->pathPairMakeCopyPresent = true;
    parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1045:

    {   
    if (parserData->categoryAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one category attribute allowed for this element");
    parserData->categoryAttributePresent = true;
}
    break;

  case 1048:

    { 
    parserData->categoryAttribute = "";
}
    break;

  case 1049:

    { 
    parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1050:

    {   if (parserData->conTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one conType attribute allowed for this element");
            parserData->conTypeAttributePresent = true;
        }
    break;

  case 1053:

    { parserData->conTypeAttribute = ""; }
    break;

  case 1054:

    { 
    parserData->conTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1055:

    {
    if (parserData->descriptionAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one description attribute allowed for this element");
    parserData->descriptionAttributePresent = true;
}
    break;

  case 1058:

    { parserData->descriptionAttribute = ""; }
    break;

  case 1059:

    { 
    parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1060:

    {   if (parserData->enumTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one enumType attribute allowed for this element");
            parserData->enumTypeAttributePresent = true;
        }
    break;

  case 1063:

    { parserData->enumTypeAttribute = ""; }
    break;

  case 1064:

    { 
    parserData->enumTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1065:

    {
    if (parserData->groupWeightAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one groupWeight attribute allowed for this element");
    parserData->groupWeightAttributePresent = true;
}
    break;

  case 1066:

    {
    parserData->groupWeight = parserData->tempVal;
}
    break;

  case 1067:

    {   
    if (parserData->idxAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one idx attribute allowed for this element");
    parserData->idxAttributePresent = true;
}
    break;

  case 1069:

    { 
    parserData->idxAttribute = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1070:

    {   
    if (parserData->lbValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
    parserData->lbValueAttributePresent = true;
}
    break;

  case 1073:

    { 
    parserData->lbValueAttribute = ""; 
}
    break;

  case 1074:

    { 
    parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1075:

    {   if (parserData->lbValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
            parserData->lbValueAttributePresent = true;
        }
    break;

  case 1078:

    { 
    parserData->lbDualValue = 0.0; 
}
    break;

  case 1079:

    {
    parserData->lbDualValue = parserData->tempVal;
}
    break;

  case 1080:

    {
        if (parserData->nameAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one name attribute allowed for this element");
        parserData->nameAttributePresent = true;
    }
    break;

  case 1083:

    { 
        parserData->nameAttribute = ""; 
    }
    break;

  case 1084:

    { 
        parserData->nameAttribute = (yyvsp[(2) - (3)].sval); 
        free((yyvsp[(2) - (3)].sval));
    }
    break;

  case 1085:

    {   if (parserData->objTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one objType attribute allowed for this element");
            parserData->objTypeAttributePresent = true;
        }
    break;

  case 1088:

    { parserData->objTypeAttribute = ""; }
    break;

  case 1089:

    { 
    parserData->objTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1090:

    {   if (parserData->solverAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one solver attribute allowed for this element");
        parserData->solverAttributePresent = true;
    }
    break;

  case 1093:

    { parserData->solverAttribute = ""; }
    break;

  case 1094:

    { 
    parserData->solverAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1095:

    {   if (parserData->sosIdxAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one sosIdx attribute allowed for this element");
        parserData->sosIdxAttributePresent = true;
    }
    break;

  case 1097:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index must be nonnegative");
    parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1098:

    {   if (parserData->typeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one type attribute allowed for this element");
            parserData->typeAttributePresent = true;
        }
    break;

  case 1101:

    { parserData->typeAttribute = ""; }
    break;

  case 1102:

    { 
    parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1103:

    {
   if (parserData->ubValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
    parserData->ubValueAttributePresent = true;
}
    break;

  case 1106:

    { 
    parserData->ubValueAttribute = ""; 
}
    break;

  case 1107:

    { 
    parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1108:

    {   if (parserData->ubValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
            parserData->ubValueAttributePresent = true;
        }
    break;

  case 1111:

    { parserData->ubDualValue = 0.0; }
    break;

  case 1112:

    { 
    parserData->ubDualValue = parserData->tempVal;
}
    break;

  case 1113:

    {   if (parserData->unitAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one unit attribute allowed for this element");
            parserData->unitAttributePresent = true;
        }
    break;

  case 1116:

    { parserData->unitAttribute = ""; }
    break;

  case 1117:

    { 
    parserData->unitAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1118:

    {   if (parserData->valueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one value attribute allowed for this element");
            parserData->valueAttributePresent = true;
        }
    break;

  case 1121:

    { parserData->valueAttribute = ""; }
    break;

  case 1122:

    {
    parserData->valueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1123:

    {   if (parserData->varTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one varType attribute allowed for this element");
            parserData->varTypeAttributePresent = true;
        }
    break;

  case 1126:

    { parserData->varTypeAttribute = ""; }
    break;

  case 1127:

    { 
    parserData->varTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1128:

    {
    if (parserData->numberOfConAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfCon attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <con> cannot be negative");
    parserData->numberOfConAttributePresent = true;        
    parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1129:

    {
    if (parserData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfConstraints attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of constraints cannot be negative");
    parserData->numberOfConstraintsPresent = true;        
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1130:

    {
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;
    parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1131:

    {
    if (parserData->numberOfEnumerationsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEnumerations attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <enumeration> elements cannot be negative");
    parserData->numberOfEnumerationsAttributePresent = true;        
    parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1132:

    {    
   if (parserData->numberOfItemsPresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one numberOfItems attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1133:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
        parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1134:

    {
    if (parserData->numberOfObjAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObj attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <obj> cannot be negative");
    parserData->numberOfObjAttributePresent = true;        
    parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1135:

    {
    if (parserData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObjectives attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of objectives cannot be negative");
    parserData->numberOfObjectivesPresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1136:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other constraint options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1137:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other objective options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1138:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1139:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other variable options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1140:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Number of path pairs cannot be negative");
    else if ((yyvsp[(3) - (4)].ival) > 0)
    {
        parserData->fromPaths = new std::string[(yyvsp[(3) - (4)].ival)];
        parserData->toPaths   = new std::string[(yyvsp[(3) - (4)].ival)];
        parserData->makeCopy  = new bool[(yyvsp[(3) - (4)].ival)];
    }
    parserData->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1141:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Number of paths cannot be negative");
    else
        parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1142:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
        parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1143:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of solver options cannot be negative");
    parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1144:

    {
    if (parserData->numberOfVarAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <var> cannot be negative");
    parserData->numberOfVarAttributePresent = true;        
    parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1145:

    {    if (parserData->numberOfVariablesPresent)

        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVariables attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of variables cannot be negative");
    parserData->numberOfVariablesPresent = true;    
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1148:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherOptionEnumeration(parserData->otherOptionType, 
                parserData->iOther,
                parserData->kounter,
                osglData->osglNumberOfEl, 
                parserData->valueAttribute, 
                parserData->descriptionAttribute, 
                osglData->osglIntArray) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <other> option enumeration failed");

    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 1149:

    {
    if (parserData->kounter >= parserData->numberOfEnumerations)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <enumeration> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->osglNumberOfElPresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 1150:

    {
        if(!osglData->osglNumberOfElPresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires numberOfEl attribute"); 
        if(!parserData->valueAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires value attribute"); 
    }
    break;

  case 1153:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfElPresent = true;
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 1161:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1162:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 1171:

    {
    osglData->fileName    = "";
    osglData->source      = "";
    osglData->description = "";
    osglData->fileCreator = "";
    osglData->licence     = "";
    osglData->fileNamePresent    = false;
    osglData->sourcePresent      = false;
    osglData->descriptionPresent = false;
    osglData->fileCreatorPresent = false;
    osglData->licencePresent     = false;
}
    break;

  case 1186:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 1191:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1193:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 1198:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1200:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 1205:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1207:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 1212:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1214:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 1219:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1220:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1225:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 1231:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;    
}
    break;

  case 1233:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1238:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 data length does not match numberOfEl"); 
    else
    {
        intvec = (int*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglIntArray[i] = *(intvec++);
        }
    }
    //delete[] b64string;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1239:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1240:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;



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
      yyerror (&yylloc, osoption, parserData, osglData, YY_("syntax error"));
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
	    yyerror (&yylloc, osoption, parserData, osglData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osoption, parserData, osglData, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
		      yytoken, &yylval, &yylloc, osoption, parserData, osglData);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
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
		  yystos[yystate], yyvsp, yylsp, osoption, parserData, osglData);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, osoption, parserData, osglData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osoption, parserData, osglData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osoption, parserData, osglData);
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





#if 0
void addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    std::ostringstream outStr;
    std::string error = errormsg;
    error = "OSoL input is either not valid or well formed: "  + error;
    outStr << error << std::endl;
    outStr << "Error occurred when reading: " << osolget_text ( scanner ) << std::endl; 
    outStr << "See line number: " << osolget_lineno( scanner) << std::endl; 
    error = outStr.str();

} //end addErrorMsg
#endif

std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osolget_lineno( scanner) << ": "; 
    outStr << osolget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg

void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, std::string errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    throw ErrorClass( errormsg);
} //end osolerror

void  yygetOSOption(const char *parsestring, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData) throw(ErrorClass){
    try{
        osol_scan_string( parsestring, scanner);
        osolset_lineno (1 , scanner );
        //
        // call the Bison parser
        //
        if(  osolparse( osoption,  parserData, osglData) != 0) {
            //osollex_destroy(scanner);
              throw ErrorClass(  "Error parsing the OSoL file");
         }
    }
    catch(const ErrorClass& eclass){
        throw ErrorClass(  eclass.errormsg); 
    }
} //end yygetOSOption


void osol_empty_vectors( OSoLParserData* parserData){
/*
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
*/      
}//end osol_empty_vectors


