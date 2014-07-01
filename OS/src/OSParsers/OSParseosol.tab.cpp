
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

#define DEBUG

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
     HEADERSTART = 330,
     HEADEREND = 331,
     GENERALSTART = 332,
     GENERALEND = 333,
     SYSTEMSTART = 334,
     SYSTEMEND = 335,
     SERVICESTART = 336,
     SERVICEEND = 337,
     JOBSTART = 338,
     JOBEND = 339,
     OPTIMIZATIONSTART = 340,
     OPTIMIZATIONEND = 341,
     FILENAMESTART = 342,
     FILENAMEEND = 343,
     FILENAMEEMPTY = 344,
     FILENAMESTARTANDEND = 345,
     FILESOURCESTART = 346,
     FILESOURCEEND = 347,
     FILESOURCEEMPTY = 348,
     FILESOURCESTARTANDEND = 349,
     FILEDESCRIPTIONSTART = 350,
     FILEDESCRIPTIONEND = 351,
     FILEDESCRIPTIONEMPTY = 352,
     FILEDESCRIPTIONSTARTANDEND = 353,
     FILECREATORSTART = 354,
     FILECREATOREND = 355,
     FILECREATOREMPTY = 356,
     FILECREATORSTARTANDEND = 357,
     FILELICENCESTART = 358,
     FILELICENCEEND = 359,
     FILELICENCEEMPTY = 360,
     FILELICENCESTARTANDEND = 361,
     SERVICEURISTART = 362,
     SERVICEURIEND = 363,
     SERVICENAMESTART = 364,
     SERVICENAMEEND = 365,
     INSTANCENAMESTART = 366,
     INSTANCENAMEEND = 367,
     INSTANCELOCATIONSTART = 368,
     INSTANCELOCATIONEND = 369,
     JOBIDSTART = 370,
     JOBIDEND = 371,
     SOLVERTOINVOKESTART = 372,
     SOLVERTOINVOKEEND = 373,
     LICENSESTART = 374,
     LICENSEEND = 375,
     USERNAMESTART = 376,
     USERNAMEEND = 377,
     PASSWORDSTART = 378,
     PASSWORDEND = 379,
     CONTACTSTART = 380,
     CONTACTEND = 381,
     OTHEROPTIONSSTART = 382,
     OTHEROPTIONSEND = 383,
     OTHERSTART = 384,
     OTHEREND = 385,
     MINDISKSPACESTART = 386,
     MINDISKSPACEEND = 387,
     MINMEMORYSTART = 388,
     MINMEMORYEND = 389,
     MINCPUSPEEDSTART = 390,
     MINCPUSPEEDEND = 391,
     MINCPUNUMBERSTART = 392,
     MINCPUNUMBEREND = 393,
     SERVICETYPESTART = 394,
     SERVICETYPEEND = 395,
     MAXTIMESTART = 396,
     MAXTIMEEND = 397,
     REQUESTEDSTARTTIMESTART = 398,
     REQUESTEDSTARTTIMEEND = 399,
     DEPENDENCIESSTART = 400,
     DEPENDENCIESEND = 401,
     REQUIREDDIRECTORIESSTART = 402,
     REQUIREDDIRECTORIESEND = 403,
     REQUIREDFILESSTART = 404,
     REQUIREDFILESEND = 405,
     PATHSTART = 406,
     PATHEND = 407,
     PATHPAIRSTART = 408,
     PATHPAIREND = 409,
     DIRECTORIESTOMAKESTART = 410,
     DIRECTORIESTOMAKEEND = 411,
     FILESTOMAKESTART = 412,
     FILESTOMAKEEND = 413,
     DIRECTORIESTODELETESTART = 414,
     DIRECTORIESTODELETEEND = 415,
     FILESTODELETESTART = 416,
     FILESTODELETEEND = 417,
     INPUTDIRECTORIESTOMOVESTART = 418,
     INPUTDIRECTORIESTOMOVEEND = 419,
     INPUTFILESTOMOVESTART = 420,
     INPUTFILESTOMOVEEND = 421,
     OUTPUTDIRECTORIESTOMOVESTART = 422,
     OUTPUTDIRECTORIESTOMOVEEND = 423,
     OUTPUTFILESTOMOVESTART = 424,
     OUTPUTFILESTOMOVEEND = 425,
     PROCESSESTOKILLSTART = 426,
     PROCESSESTOKILLEND = 427,
     PROCESSSTART = 428,
     PROCESSEND = 429,
     VARIABLESSTART = 430,
     VARIABLESEND = 431,
     INITIALVARIABLEVALUESSTART = 432,
     INITIALVARIABLEVALUESEND = 433,
     VARSTART = 434,
     VAREND = 435,
     INITIALVARIABLEVALUESSTRINGSTART = 436,
     INITIALVARIABLEVALUESSTRINGEND = 437,
     INITIALBASISSTATUSSTART = 438,
     INITIALBASISSTATUSEND = 439,
     BASICSTART = 440,
     BASICEND = 441,
     ATUPPERSTART = 442,
     ATUPPEREND = 443,
     ATLOWERSTART = 444,
     ATLOWEREND = 445,
     ATEQUALITYSTART = 446,
     ATEQUALITYEND = 447,
     SUPERBASICSTART = 448,
     SUPERBASICEND = 449,
     ISFREESTART = 450,
     ISFREEEND = 451,
     UNKNOWNSTART = 452,
     UNKNOWNEND = 453,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 454,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 455,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 456,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 457,
     SOSSTART = 458,
     SOSEND = 459,
     OBJECTIVESSTART = 460,
     OBJECTIVESEND = 461,
     INITIALOBJECTIVEVALUESSTART = 462,
     INITIALOBJECTIVEVALUESEND = 463,
     OBJSTART = 464,
     OBJEND = 465,
     INITIALOBJECTIVEBOUNDSSTART = 466,
     INITIALOBJECTIVEBOUNDSEND = 467,
     CONSTRAINTSSTART = 468,
     CONSTRAINTSEND = 469,
     INITIALCONSTRAINTVALUESSTART = 470,
     INITIALCONSTRAINTVALUESEND = 471,
     CONSTART = 472,
     CONEND = 473,
     INITIALDUALVALUESSTART = 474,
     INITIALDUALVALUESEND = 475,
     SOLVEROPTIONSSTART = 476,
     SOLVEROPTIONSEND = 477,
     SOLVEROPTIONSTART = 478,
     SOLVEROPTIONEND = 479,
     ENUMERATIONSTART = 480,
     ENUMERATIONEND = 481,
     ITEMEMPTY = 482,
     ITEMSTART = 483,
     ITEMEND = 484,
     ITEMSTARTANDEND = 485,
     BASE64START = 486,
     BASE64END = 487,
     INCRATT = 488,
     MULTATT = 489,
     SIZEOFATT = 490,
     ELSTART = 491,
     ELEND = 492,
     MATRIXSTART = 493,
     MATRIXEND = 494,
     BASEMATRIXEND = 495,
     BASEMATRIXSTART = 496,
     BLOCKSTART = 497,
     BLOCKEND = 498,
     BLOCKSSTART = 499,
     BLOCKSEND = 500,
     EMPTYSYMMETRYATT = 501,
     SYMMETRYATT = 502,
     NUMBEROFBLOCKSATT = 503,
     NUMBEROFCOLUMNSATT = 504,
     NUMBEROFROWSATT = 505,
     BASEMATRIXIDXATT = 506,
     TARGETMATRIXFIRSTROWATT = 507,
     TARGETMATRIXFIRSTCOLATT = 508,
     BASEMATRIXSTARTROWATT = 509,
     BASEMATRIXSTARTCOLATT = 510,
     BASEMATRIXENDROWATT = 511,
     BASEMATRIXENDCOLATT = 512,
     SCALARMULTIPLIERATT = 513,
     EMPTYBASETRANSPOSEATT = 514,
     BASETRANSPOSEATT = 515,
     ELEMENTSSTART = 516,
     ELEMENTSEND = 517,
     EMPTYROWMAJORATT = 518,
     ROWMAJORATT = 519,
     DUMMY = 520
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
#define HEADERSTART 330
#define HEADEREND 331
#define GENERALSTART 332
#define GENERALEND 333
#define SYSTEMSTART 334
#define SYSTEMEND 335
#define SERVICESTART 336
#define SERVICEEND 337
#define JOBSTART 338
#define JOBEND 339
#define OPTIMIZATIONSTART 340
#define OPTIMIZATIONEND 341
#define FILENAMESTART 342
#define FILENAMEEND 343
#define FILENAMEEMPTY 344
#define FILENAMESTARTANDEND 345
#define FILESOURCESTART 346
#define FILESOURCEEND 347
#define FILESOURCEEMPTY 348
#define FILESOURCESTARTANDEND 349
#define FILEDESCRIPTIONSTART 350
#define FILEDESCRIPTIONEND 351
#define FILEDESCRIPTIONEMPTY 352
#define FILEDESCRIPTIONSTARTANDEND 353
#define FILECREATORSTART 354
#define FILECREATOREND 355
#define FILECREATOREMPTY 356
#define FILECREATORSTARTANDEND 357
#define FILELICENCESTART 358
#define FILELICENCEEND 359
#define FILELICENCEEMPTY 360
#define FILELICENCESTARTANDEND 361
#define SERVICEURISTART 362
#define SERVICEURIEND 363
#define SERVICENAMESTART 364
#define SERVICENAMEEND 365
#define INSTANCENAMESTART 366
#define INSTANCENAMEEND 367
#define INSTANCELOCATIONSTART 368
#define INSTANCELOCATIONEND 369
#define JOBIDSTART 370
#define JOBIDEND 371
#define SOLVERTOINVOKESTART 372
#define SOLVERTOINVOKEEND 373
#define LICENSESTART 374
#define LICENSEEND 375
#define USERNAMESTART 376
#define USERNAMEEND 377
#define PASSWORDSTART 378
#define PASSWORDEND 379
#define CONTACTSTART 380
#define CONTACTEND 381
#define OTHEROPTIONSSTART 382
#define OTHEROPTIONSEND 383
#define OTHERSTART 384
#define OTHEREND 385
#define MINDISKSPACESTART 386
#define MINDISKSPACEEND 387
#define MINMEMORYSTART 388
#define MINMEMORYEND 389
#define MINCPUSPEEDSTART 390
#define MINCPUSPEEDEND 391
#define MINCPUNUMBERSTART 392
#define MINCPUNUMBEREND 393
#define SERVICETYPESTART 394
#define SERVICETYPEEND 395
#define MAXTIMESTART 396
#define MAXTIMEEND 397
#define REQUESTEDSTARTTIMESTART 398
#define REQUESTEDSTARTTIMEEND 399
#define DEPENDENCIESSTART 400
#define DEPENDENCIESEND 401
#define REQUIREDDIRECTORIESSTART 402
#define REQUIREDDIRECTORIESEND 403
#define REQUIREDFILESSTART 404
#define REQUIREDFILESEND 405
#define PATHSTART 406
#define PATHEND 407
#define PATHPAIRSTART 408
#define PATHPAIREND 409
#define DIRECTORIESTOMAKESTART 410
#define DIRECTORIESTOMAKEEND 411
#define FILESTOMAKESTART 412
#define FILESTOMAKEEND 413
#define DIRECTORIESTODELETESTART 414
#define DIRECTORIESTODELETEEND 415
#define FILESTODELETESTART 416
#define FILESTODELETEEND 417
#define INPUTDIRECTORIESTOMOVESTART 418
#define INPUTDIRECTORIESTOMOVEEND 419
#define INPUTFILESTOMOVESTART 420
#define INPUTFILESTOMOVEEND 421
#define OUTPUTDIRECTORIESTOMOVESTART 422
#define OUTPUTDIRECTORIESTOMOVEEND 423
#define OUTPUTFILESTOMOVESTART 424
#define OUTPUTFILESTOMOVEEND 425
#define PROCESSESTOKILLSTART 426
#define PROCESSESTOKILLEND 427
#define PROCESSSTART 428
#define PROCESSEND 429
#define VARIABLESSTART 430
#define VARIABLESEND 431
#define INITIALVARIABLEVALUESSTART 432
#define INITIALVARIABLEVALUESEND 433
#define VARSTART 434
#define VAREND 435
#define INITIALVARIABLEVALUESSTRINGSTART 436
#define INITIALVARIABLEVALUESSTRINGEND 437
#define INITIALBASISSTATUSSTART 438
#define INITIALBASISSTATUSEND 439
#define BASICSTART 440
#define BASICEND 441
#define ATUPPERSTART 442
#define ATUPPEREND 443
#define ATLOWERSTART 444
#define ATLOWEREND 445
#define ATEQUALITYSTART 446
#define ATEQUALITYEND 447
#define SUPERBASICSTART 448
#define SUPERBASICEND 449
#define ISFREESTART 450
#define ISFREEEND 451
#define UNKNOWNSTART 452
#define UNKNOWNEND 453
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 454
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 455
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 456
#define SOSVARIABLEBRANCHINGWEIGHTSEND 457
#define SOSSTART 458
#define SOSEND 459
#define OBJECTIVESSTART 460
#define OBJECTIVESEND 461
#define INITIALOBJECTIVEVALUESSTART 462
#define INITIALOBJECTIVEVALUESEND 463
#define OBJSTART 464
#define OBJEND 465
#define INITIALOBJECTIVEBOUNDSSTART 466
#define INITIALOBJECTIVEBOUNDSEND 467
#define CONSTRAINTSSTART 468
#define CONSTRAINTSEND 469
#define INITIALCONSTRAINTVALUESSTART 470
#define INITIALCONSTRAINTVALUESEND 471
#define CONSTART 472
#define CONEND 473
#define INITIALDUALVALUESSTART 474
#define INITIALDUALVALUESEND 475
#define SOLVEROPTIONSSTART 476
#define SOLVEROPTIONSEND 477
#define SOLVEROPTIONSTART 478
#define SOLVEROPTIONEND 479
#define ENUMERATIONSTART 480
#define ENUMERATIONEND 481
#define ITEMEMPTY 482
#define ITEMSTART 483
#define ITEMEND 484
#define ITEMSTARTANDEND 485
#define BASE64START 486
#define BASE64END 487
#define INCRATT 488
#define MULTATT 489
#define SIZEOFATT 490
#define ELSTART 491
#define ELEND 492
#define MATRIXSTART 493
#define MATRIXEND 494
#define BASEMATRIXEND 495
#define BASEMATRIXSTART 496
#define BLOCKSTART 497
#define BLOCKEND 498
#define BLOCKSSTART 499
#define BLOCKSEND 500
#define EMPTYSYMMETRYATT 501
#define SYMMETRYATT 502
#define NUMBEROFBLOCKSATT 503
#define NUMBEROFCOLUMNSATT 504
#define NUMBEROFROWSATT 505
#define BASEMATRIXIDXATT 506
#define TARGETMATRIXFIRSTROWATT 507
#define TARGETMATRIXFIRSTCOLATT 508
#define BASEMATRIXSTARTROWATT 509
#define BASEMATRIXSTARTCOLATT 510
#define BASEMATRIXENDROWATT 511
#define BASEMATRIXENDCOLATT 512
#define SCALARMULTIPLIERATT 513
#define EMPTYBASETRANSPOSEATT 514
#define BASETRANSPOSEATT 515
#define ELEMENTSSTART 516
#define ELEMENTSEND 517
#define EMPTYROWMAJORATT 518
#define ROWMAJORATT 519
#define DUMMY 520




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
#define YYNTOKENS  270
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  831
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1240
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1696

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   520

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   267,
     269,     2,     2,   268,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   266,     2,     2,     2,     2,     2,     2,     2,
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
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265
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
     271,     0,    -1,   272,   280,   278,    -1,   273,   274,   275,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   276,    -1,
     277,    -1,    11,    -1,    10,   280,   278,    -1,   279,    -1,
      15,    -1,    -1,   281,   282,   368,   416,   444,   560,    -1,
      -1,  1058,    -1,    -1,   283,   284,    -1,    77,    -1,   285,
      -1,   286,    -1,    10,    78,    -1,    11,    -1,    10,   287,
      78,    -1,   288,    -1,   289,    -1,   288,   289,    -1,   290,
      -1,   296,    -1,   302,    -1,   308,    -1,   316,    -1,   322,
      -1,   328,    -1,   334,    -1,   340,    -1,   346,    -1,   354,
      -1,   291,   292,    -1,   107,    -1,   293,    -1,   294,    -1,
      10,   108,    -1,    11,    -1,    10,   295,   108,    -1,     4,
      -1,   297,   298,    -1,   109,    -1,   299,    -1,   300,    -1,
      10,   110,    -1,    11,    -1,    10,   301,   110,    -1,     4,
      -1,   303,   304,    -1,   111,    -1,   305,    -1,   306,    -1,
      10,   112,    -1,    11,    -1,    10,   307,   112,    -1,     4,
      -1,   309,   310,   312,    -1,   113,    -1,    -1,   311,    -1,
      74,     3,     8,    -1,   313,    -1,   314,    -1,    10,   114,
      -1,    11,    -1,    10,   315,   114,    -1,     4,    -1,   317,
     318,    -1,   115,    -1,   319,    -1,   320,    -1,    10,   116,
      -1,    11,    -1,    10,   321,   116,    -1,     4,    -1,   323,
     324,    -1,   117,    -1,   325,    -1,   326,    -1,    10,   118,
      -1,    11,    -1,    10,   327,   118,    -1,     4,    -1,   329,
     330,    -1,   119,    -1,   331,    -1,   332,    -1,    10,   120,
      -1,    11,    -1,    10,   333,   120,    -1,     4,    -1,   335,
     336,    -1,   121,    -1,   337,    -1,   338,    -1,    10,   122,
      -1,    11,    -1,    10,   339,   122,    -1,     4,    -1,   341,
     342,    -1,   123,    -1,   343,    -1,   344,    -1,    10,   124,
      -1,    11,    -1,    10,   345,   124,    -1,     4,    -1,   347,
     348,   350,    -1,   125,    -1,    -1,   349,    -1,    73,     3,
       8,    -1,   351,    -1,   352,    -1,    10,   126,    -1,    11,
      -1,    10,   353,   126,    -1,     4,    -1,   355,   356,   357,
      -1,   127,    -1,  1036,    -1,   358,    -1,   359,    -1,    10,
     128,    -1,    11,    -1,    10,   360,   128,    -1,   361,    -1,
     362,    -1,   361,   362,    -1,   363,   364,   367,    -1,   129,
      -1,   365,    -1,    -1,   365,   366,    -1,   987,    -1,  1018,
      -1,   966,    -1,    10,   130,    -1,    11,    -1,    -1,   369,
     370,    -1,    79,    -1,   371,    -1,   372,    -1,    10,    80,
      -1,    11,    -1,    10,   373,    80,    -1,   374,    -1,   375,
      -1,   374,   375,    -1,   376,    -1,   383,    -1,   390,    -1,
     397,    -1,   402,    -1,   377,   378,   381,    -1,   131,    -1,
     379,    -1,    -1,   379,   380,    -1,  1014,    -1,   966,    -1,
      10,   382,   132,    -1,  1054,    -1,   384,   385,   388,    -1,
     133,    -1,   386,    -1,    -1,   386,   387,    -1,  1014,    -1,
     966,    -1,    10,   389,   134,    -1,  1054,    -1,   391,   392,
     395,    -1,   135,    -1,   393,    -1,    -1,   393,   394,    -1,
    1014,    -1,   966,    -1,    10,   396,   136,    -1,  1054,    -1,
     398,   399,   400,    -1,   137,    -1,    -1,   966,    -1,    10,
     401,   138,    -1,     6,    -1,   403,   404,   405,    -1,   127,
      -1,  1036,    -1,   406,    -1,   407,    -1,    10,   128,    -1,
      11,    -1,    10,   408,   128,    -1,   409,    -1,   410,    -1,
     409,   410,    -1,   411,   412,   415,    -1,   129,    -1,   413,
      -1,    -1,   413,   414,    -1,   987,    -1,  1018,    -1,   966,
      -1,    10,   130,    -1,    11,    -1,    -1,   417,   418,    -1,
      81,    -1,   419,    -1,   420,    -1,    10,    82,    -1,    11,
      -1,    10,   421,    82,    -1,   422,    -1,   423,    -1,   422,
     423,    -1,   424,    -1,   430,    -1,   425,   426,    -1,   139,
      -1,   427,    -1,   428,    -1,    10,   140,    -1,    11,    -1,
      10,   429,   140,    -1,     4,    -1,   431,   432,   433,    -1,
     127,    -1,  1036,    -1,   434,    -1,   435,    -1,    10,   128,
      -1,    11,    -1,    10,   436,   128,    -1,   437,    -1,   438,
      -1,   437,   438,    -1,   439,   440,   443,    -1,   129,    -1,
     441,    -1,    -1,   441,   442,    -1,   987,    -1,  1018,    -1,
     966,    -1,    10,   130,    -1,    11,    -1,    -1,   445,   446,
      -1,    83,    -1,   447,    -1,   448,    -1,    10,    84,    -1,
      11,    -1,    10,   449,    84,    -1,   450,    -1,   451,    -1,
     450,   451,    -1,   452,    -1,   460,    -1,   466,    -1,   474,
      -1,   479,    -1,   484,    -1,   489,    -1,   494,    -1,   502,
      -1,   518,    -1,   510,    -1,   526,    -1,   532,    -1,   538,
      -1,   546,    -1,   453,   454,   455,    -1,   141,    -1,    -1,
    1014,    -1,   456,    -1,   457,    -1,    10,   142,    -1,    11,
      -1,    10,   458,   142,    -1,   459,    -1,  1054,    -1,   461,
     462,    -1,   143,    -1,   463,    -1,   464,    -1,    10,   144,
      -1,    11,    -1,    10,   465,   144,    -1,     4,    -1,   467,
     468,   469,    -1,   145,    -1,  1031,    -1,   470,    -1,   471,
      -1,    10,   146,    -1,    11,    -1,    10,   472,   146,    -1,
     473,    -1,   472,   473,    -1,   115,    10,     4,   116,    -1,
     475,  1039,   476,    -1,   147,    -1,   477,    -1,   478,    -1,
      10,   148,    -1,    11,    -1,    10,   947,   148,    -1,   480,
    1039,   481,    -1,   149,    -1,   482,    -1,   483,    -1,    10,
     150,    -1,    11,    -1,    10,   947,   150,    -1,   485,  1039,
     486,    -1,   155,    -1,   487,    -1,   488,    -1,    10,   156,
      -1,    11,    -1,    10,   947,   156,    -1,   490,  1039,   491,
      -1,   157,    -1,   492,    -1,   493,    -1,    10,   158,    -1,
      11,    -1,    10,   947,   158,    -1,   495,   496,   497,    -1,
     163,    -1,  1038,    -1,   498,    -1,   499,    -1,    10,   164,
      -1,    11,    -1,    10,   500,   164,    -1,   501,    -1,   500,
     501,    -1,   949,    -1,   503,   504,   505,    -1,   165,    -1,
    1038,    -1,   506,    -1,   507,    -1,    10,   166,    -1,    11,
      -1,    10,   508,   166,    -1,   509,    -1,   508,   509,    -1,
     949,    -1,   511,   512,   513,    -1,   169,    -1,  1038,    -1,
     514,    -1,   515,    -1,    10,   170,    -1,    11,    -1,    10,
     516,   170,    -1,   517,    -1,   516,   517,    -1,   949,    -1,
     519,   520,   521,    -1,   167,    -1,  1038,    -1,   522,    -1,
     523,    -1,    10,   168,    -1,    11,    -1,    10,   524,   168,
      -1,   525,    -1,   524,   525,    -1,   949,    -1,   527,   528,
     529,    -1,   161,    -1,  1039,    -1,   530,    -1,   531,    -1,
      10,   162,    -1,    11,    -1,    10,   947,   162,    -1,   533,
     534,   535,    -1,   159,    -1,  1039,    -1,   536,    -1,   537,
      -1,    10,   160,    -1,    11,    -1,    10,   947,   160,    -1,
     539,   540,   541,    -1,   171,    -1,  1040,    -1,   542,    -1,
     543,    -1,    10,   172,    -1,    11,    -1,    10,   544,   172,
      -1,   545,    -1,   544,   545,    -1,   173,    10,     4,   174,
      -1,   547,   548,   549,    -1,   127,    -1,  1036,    -1,   550,
      -1,   551,    -1,    10,   128,    -1,    11,    -1,    10,   552,
     128,    -1,   553,    -1,   554,    -1,   553,   554,    -1,   555,
     556,   559,    -1,   129,    -1,   557,    -1,    -1,   557,   558,
      -1,   987,    -1,  1018,    -1,   966,    -1,    10,   130,    -1,
      11,    -1,    -1,   561,   562,   565,    -1,    85,    -1,   563,
      -1,    -1,   563,   564,    -1,  1043,    -1,  1027,    -1,  1033,
      -1,   566,    -1,   567,    -1,    11,    -1,    10,   568,    86,
      -1,   569,   707,   816,   925,    -1,    -1,   570,   571,   573,
      -1,   175,    -1,   572,    -1,    -1,  1037,    -1,   574,    -1,
     575,    -1,    11,    -1,    10,   576,   176,    -1,   577,   591,
     605,   660,   674,   689,    -1,    -1,   578,   579,   580,    -1,
     177,    -1,  1042,    -1,   581,    -1,   582,    -1,    10,   178,
      -1,    11,    -1,    10,   583,   178,    -1,   584,    -1,   585,
      -1,   584,   585,    -1,   586,   587,   590,    -1,   179,    -1,
     588,    -1,    -1,   588,   589,    -1,   976,    -1,   987,    -1,
    1018,    -1,    10,   180,    -1,    11,    -1,    -1,   592,   593,
     594,    -1,   181,    -1,  1042,    -1,   595,    -1,   596,    -1,
      10,   182,    -1,    11,    -1,    10,   597,   182,    -1,   598,
      -1,   599,    -1,   598,   599,    -1,   600,   601,   604,    -1,
     179,    -1,   602,    -1,    -1,   602,   603,    -1,   976,    -1,
     987,    -1,  1018,    -1,    10,   180,    -1,    11,    -1,    -1,
     606,   607,    -1,   183,    -1,   608,    -1,   609,    -1,    11,
      -1,    10,   610,   184,    -1,   611,   618,   625,   632,   639,
     646,   653,    -1,    -1,   612,   613,   614,    -1,   185,    -1,
    1028,    -1,   615,    -1,   616,    -1,    11,    -1,    10,   617,
     186,    -1,  1086,    -1,    -1,   619,   620,   621,    -1,   189,
      -1,  1028,    -1,   622,    -1,   623,    -1,    11,    -1,    10,
     624,   190,    -1,  1086,    -1,    -1,   626,   627,   628,    -1,
     187,    -1,  1028,    -1,   629,    -1,   630,    -1,    11,    -1,
      10,   631,   188,    -1,  1086,    -1,    -1,   633,   634,   635,
      -1,   191,    -1,  1028,    -1,   636,    -1,   637,    -1,    11,
      -1,    10,   638,   192,    -1,  1086,    -1,    -1,   640,   641,
     642,    -1,   195,    -1,  1028,    -1,   643,    -1,   644,    -1,
      11,    -1,    10,   645,   196,    -1,  1086,    -1,    -1,   647,
     648,   649,    -1,   193,    -1,  1028,    -1,   650,    -1,   651,
      -1,    11,    -1,    10,   652,   194,    -1,  1086,    -1,    -1,
     654,   655,   656,    -1,   197,    -1,  1028,    -1,   657,    -1,
     658,    -1,    11,    -1,    10,   659,   198,    -1,  1086,    -1,
      -1,   661,   662,   663,    -1,   199,    -1,  1042,    -1,   664,
      -1,   665,    -1,    10,   200,    -1,    11,    -1,    10,   666,
     200,    -1,   667,    -1,   668,    -1,   667,   668,    -1,   669,
     670,   673,    -1,   179,    -1,   671,    -1,    -1,   671,   672,
      -1,   976,    -1,   987,    -1,  1018,    -1,    10,   180,    -1,
      11,    -1,    -1,   675,   676,   677,    -1,   201,    -1,    29,
       8,     6,     8,    -1,   678,    -1,   679,    -1,    10,   202,
      -1,    11,    -1,    10,   680,   202,    -1,   681,    -1,   680,
     681,    -1,   682,   683,   686,    -1,   203,    -1,   684,    -1,
      -1,   684,   685,    -1,   999,    -1,  1042,    -1,   974,    -1,
     687,    -1,   688,    -1,    10,   204,    -1,    11,    -1,    10,
     667,   204,    -1,    -1,   689,   690,    -1,   691,   692,   695,
      -1,   129,    -1,   693,    -1,    -1,   693,   694,    -1,  1042,
      -1,  1029,    -1,   987,    -1,  1018,    -1,   995,    -1,   958,
      -1,  1002,    -1,  1022,    -1,   970,    -1,   966,    -1,   696,
      -1,   697,    -1,    10,   130,    -1,    11,    -1,    10,   698,
     130,    -1,   699,    -1,  1044,    -1,   700,    -1,   699,   700,
      -1,   701,   702,   705,    -1,   179,    -1,   703,    -1,    -1,
     703,   704,    -1,   976,    -1,   987,    -1,  1018,    -1,   979,
      -1,  1006,    -1,   706,    -1,    10,   180,    -1,    11,    -1,
      -1,   708,   709,   711,    -1,   205,    -1,   710,    -1,    -1,
    1035,    -1,   712,    -1,   713,    -1,    11,    -1,    10,   714,
     206,    -1,   715,   729,   743,   798,    -1,    -1,   716,   717,
     718,    -1,   207,    -1,  1032,    -1,   719,    -1,   720,    -1,
      10,   208,    -1,    11,    -1,    10,   721,   208,    -1,   722,
      -1,   723,    -1,   722,   723,    -1,   724,   725,   728,    -1,
     209,    -1,   726,    -1,    -1,   726,   727,    -1,   976,    -1,
     987,    -1,  1018,    -1,    10,   210,    -1,    11,    -1,    -1,
     730,   731,   732,    -1,   211,    -1,  1032,    -1,   733,    -1,
     734,    -1,    10,   212,    -1,    11,    -1,    10,   735,   212,
      -1,   736,    -1,   737,    -1,   736,   737,    -1,   738,   739,
     742,    -1,   209,    -1,   740,    -1,    -1,   740,   741,    -1,
     976,    -1,   987,    -1,   979,    -1,  1006,    -1,    10,   210,
      -1,    11,    -1,    -1,   744,   745,    -1,   183,    -1,   746,
      -1,   747,    -1,    11,    -1,    10,   748,   184,    -1,   749,
     756,   763,   770,   777,   784,   791,    -1,    -1,   750,   751,
     752,    -1,   185,    -1,  1028,    -1,   753,    -1,   754,    -1,
      11,    -1,    10,   755,   186,    -1,  1086,    -1,    -1,   757,
     758,   759,    -1,   189,    -1,  1028,    -1,   760,    -1,   761,
      -1,    11,    -1,    10,   762,   190,    -1,  1086,    -1,    -1,
     764,   765,   766,    -1,   187,    -1,  1028,    -1,   767,    -1,
     768,    -1,    11,    -1,    10,   769,   188,    -1,  1086,    -1,
      -1,   771,   772,   773,    -1,   191,    -1,  1028,    -1,   774,
      -1,   775,    -1,    11,    -1,    10,   776,   192,    -1,  1086,
      -1,    -1,   778,   779,   780,    -1,   195,    -1,  1028,    -1,
     781,    -1,   782,    -1,    11,    -1,    10,   783,   196,    -1,
    1086,    -1,    -1,   785,   786,   787,    -1,   193,    -1,  1028,
      -1,   788,    -1,   789,    -1,    11,    -1,    10,   790,   194,
      -1,  1086,    -1,    -1,   792,   793,   794,    -1,   197,    -1,
    1028,    -1,   795,    -1,   796,    -1,    11,    -1,    10,   797,
     198,    -1,  1086,    -1,    -1,   798,   799,    -1,   800,   801,
     804,    -1,   129,    -1,   802,    -1,    -1,   802,   803,    -1,
    1032,    -1,  1029,    -1,   987,    -1,  1018,    -1,   995,    -1,
     958,    -1,  1002,    -1,   991,    -1,   970,    -1,   966,    -1,
     805,    -1,   806,    -1,    10,   130,    -1,    11,    -1,    10,
     807,   130,    -1,   808,    -1,  1044,    -1,   809,    -1,   808,
     809,    -1,   810,   811,   814,    -1,   209,    -1,   812,    -1,
      -1,   812,   813,    -1,   976,    -1,   987,    -1,  1018,    -1,
     979,    -1,  1006,    -1,   815,    -1,    10,   210,    -1,    11,
      -1,    -1,   817,   818,   820,    -1,   213,    -1,   819,    -1,
      -1,  1034,    -1,   821,    -1,   822,    -1,    11,    -1,    10,
     823,   214,    -1,   824,   838,   852,   907,    -1,    -1,   825,
     826,   827,    -1,   215,    -1,  1026,    -1,   828,    -1,   829,
      -1,    10,   216,    -1,    11,    -1,    10,   830,   216,    -1,
     831,    -1,   832,    -1,   831,   832,    -1,   833,   834,   837,
      -1,   217,    -1,   835,    -1,    -1,   835,   836,    -1,   976,
      -1,   987,    -1,  1018,    -1,    10,   218,    -1,    11,    -1,
      -1,   839,   840,   841,    -1,   219,    -1,  1026,    -1,   842,
      -1,   843,    -1,    10,   220,    -1,    11,    -1,    10,   844,
     220,    -1,   845,    -1,   846,    -1,   845,   846,    -1,   847,
     848,   851,    -1,   217,    -1,   849,    -1,    -1,   849,   850,
      -1,   976,    -1,   987,    -1,   983,    -1,  1010,    -1,    10,
     218,    -1,    11,    -1,    -1,   853,   854,    -1,   183,    -1,
     855,    -1,   856,    -1,    11,    -1,    10,   857,   184,    -1,
     858,   865,   872,   879,   886,   893,   900,    -1,    -1,   859,
     860,   861,    -1,   185,    -1,  1028,    -1,   862,    -1,   863,
      -1,    11,    -1,    10,   864,   186,    -1,  1086,    -1,    -1,
     866,   867,   868,    -1,   189,    -1,  1028,    -1,   869,    -1,
     870,    -1,    11,    -1,    10,   871,   190,    -1,  1086,    -1,
      -1,   873,   874,   875,    -1,   187,    -1,  1028,    -1,   876,
      -1,   877,    -1,    11,    -1,    10,   878,   188,    -1,  1086,
      -1,    -1,   880,   881,   882,    -1,   191,    -1,  1028,    -1,
     883,    -1,   884,    -1,    11,    -1,    10,   885,   192,    -1,
    1086,    -1,    -1,   887,   888,   889,    -1,   195,    -1,  1028,
      -1,   890,    -1,   891,    -1,    11,    -1,    10,   892,   196,
      -1,  1086,    -1,    -1,   894,   895,   896,    -1,   193,    -1,
    1028,    -1,   897,    -1,   898,    -1,    11,    -1,    10,   899,
     194,    -1,  1086,    -1,    -1,   901,   902,   903,    -1,   197,
      -1,  1028,    -1,   904,    -1,   905,    -1,    11,    -1,    10,
     906,   198,    -1,  1086,    -1,    -1,   907,   908,    -1,   909,
     910,   913,    -1,   129,    -1,   911,    -1,    -1,   911,   912,
      -1,  1026,    -1,  1029,    -1,   987,    -1,  1018,    -1,   995,
      -1,   958,    -1,  1002,    -1,   962,    -1,   970,    -1,   966,
      -1,   914,    -1,   915,    -1,    10,   130,    -1,    11,    -1,
      10,   916,   130,    -1,   917,    -1,  1044,    -1,   918,    -1,
     917,   918,    -1,   919,   920,   923,    -1,   217,    -1,   921,
      -1,    -1,   921,   922,    -1,   976,    -1,   987,    -1,  1018,
      -1,   979,    -1,  1006,    -1,   924,    -1,    10,   218,    -1,
      11,    -1,    -1,   926,   927,   928,    -1,   221,    -1,  1041,
      -1,   929,    -1,   930,    -1,    11,    -1,    10,   931,   222,
      -1,    -1,   931,   932,    -1,   933,   934,   937,    -1,   223,
      -1,   935,    -1,   936,    -1,   935,   936,    -1,   987,    -1,
    1018,    -1,   995,    -1,   958,    -1,  1002,    -1,   966,    -1,
    1030,    -1,   938,    -1,   939,    -1,    10,   224,    -1,    11,
      -1,    10,   940,   224,    -1,   941,    -1,   942,    -1,   941,
     942,    -1,   943,    -1,   944,    -1,   945,    -1,   230,    -1,
     227,    -1,   228,   946,   229,    -1,     5,    -1,   948,    -1,
     947,   948,    -1,   151,    10,     4,   152,    -1,   950,   951,
     957,    -1,   153,    -1,   952,    -1,    -1,   952,   953,    -1,
     954,    -1,   955,    -1,   956,    -1,    21,     3,     8,    -1,
      22,     3,     8,    -1,    23,     3,     8,    -1,    10,   154,
      -1,    11,    -1,   959,    -1,   960,    -1,   961,    -1,    57,
      -1,    24,     3,  1055,    -1,   963,    -1,   964,    -1,   965,
      -1,    48,    -1,    47,     3,     8,    -1,   967,    -1,   968,
      -1,   969,    -1,    58,    -1,    46,     3,  1055,    -1,   971,
      -1,   972,    -1,   973,    -1,    50,    -1,    49,     3,     8,
      -1,   975,    -1,    26,     8,  1054,     8,    -1,   977,    -1,
     978,    -1,    42,  1055,     6,  1055,    -1,   980,    -1,   981,
      -1,   982,    -1,    61,    -1,    63,     3,  1055,    -1,   984,
      -1,   985,    -1,   986,    -1,    65,    -1,    67,  1055,  1054,
    1055,    -1,   988,    -1,   989,    -1,   990,    -1,    56,    -1,
      41,     3,  1055,    -1,   992,    -1,   993,    -1,   994,    -1,
      52,    -1,    51,     3,     8,    -1,   996,    -1,   997,    -1,
     998,    -1,    70,    -1,    69,     3,  1055,    -1,  1000,    -1,
    1001,    -1,    43,  1055,     6,  1055,    -1,  1003,    -1,  1004,
      -1,  1005,    -1,    55,    -1,    25,     3,     8,    -1,  1007,
      -1,  1008,    -1,  1009,    -1,    62,    -1,    64,     3,  1055,
      -1,  1011,    -1,  1012,    -1,  1013,    -1,    66,    -1,    68,
    1055,  1054,  1055,    -1,  1015,    -1,  1016,    -1,  1017,    -1,
      59,    -1,    45,     3,     8,    -1,  1019,    -1,  1020,    -1,
    1021,    -1,    60,    -1,    44,     3,     8,    -1,  1023,    -1,
    1024,    -1,  1025,    -1,    54,    -1,    53,     3,     8,    -1,
      39,  1055,     6,  1055,    -1,    32,  1055,     6,  1055,    -1,
      40,  1055,     6,  1055,    -1,    17,  1055,     6,  1055,    -1,
      36,  1055,     6,  1055,    -1,    18,     8,     6,     8,    -1,
      38,  1055,     6,  1055,    -1,    31,  1055,     6,  1055,    -1,
      35,  1055,     6,  1055,    -1,    34,  1055,     6,  1055,    -1,
      16,  1055,     6,  1055,    -1,    33,  1055,     6,  1055,    -1,
      20,     8,     6,     8,    -1,    19,     8,     6,     8,    -1,
      27,     8,     6,     8,    -1,    28,  1055,     6,  1055,    -1,
      37,  1055,     6,  1055,    -1,    30,  1055,     6,  1055,    -1,
    1045,    -1,  1044,  1045,    -1,  1046,  1047,  1050,    -1,   225,
      -1,  1048,    -1,    -1,  1048,  1049,    -1,  1028,    -1,  1018,
      -1,   966,    -1,  1051,    -1,  1052,    -1,    11,    -1,    10,
    1053,   226,    -1,  1086,    -1,     6,    -1,     7,    -1,  1056,
       8,    -1,    -1,  1056,  1057,    -1,   266,    -1,   267,    -1,
     268,    -1,   269,    -1,  1059,  1060,    -1,    75,    -1,  1061,
      -1,  1062,    -1,    10,    76,    -1,    11,    -1,    10,  1063,
      76,    -1,  1064,    -1,  1065,    -1,  1064,  1065,    -1,  1066,
      -1,  1070,    -1,  1074,    -1,  1078,    -1,  1082,    -1,    -1,
    1067,    -1,  1068,    -1,  1069,    -1,    90,    -1,    89,    -1,
      87,     5,    88,    -1,    -1,  1071,    -1,  1072,    -1,  1073,
      -1,    94,    -1,    93,    -1,    91,     5,    92,    -1,    -1,
    1075,    -1,  1076,    -1,  1077,    -1,    98,    -1,    97,    -1,
      95,     5,    96,    -1,    -1,  1079,    -1,  1080,    -1,  1081,
      -1,   102,    -1,   101,    -1,    99,     5,   100,    -1,    -1,
    1083,    -1,  1084,    -1,  1085,    -1,   106,    -1,   105,    -1,
     103,     5,   104,    -1,  1087,    -1,  1094,    -1,    -1,  1087,
    1088,    -1,  1089,  1090,  1093,    -1,   236,    -1,  1091,    -1,
      -1,  1091,  1092,    -1,  1100,    -1,  1099,    -1,    10,     6,
     237,    -1,   231,  1095,  1096,    -1,   235,  1055,     6,  1055,
      -1,  1097,    -1,  1098,    -1,    10,   232,    -1,    11,    -1,
      10,     4,   232,    -1,   233,  1055,     6,  1055,    -1,   234,
    1055,     6,  1055,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   188,   188,   189,   191,   198,   208,   208,   210,   210,
     212,   214,   216,   225,   226,   229,   237,   237,   250,   250,
     252,   268,   268,   270,   270,   272,   274,   276,   276,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     293,   295,   304,   304,   306,   306,   308,   310,   320,   322,
     329,   329,   331,   331,   333,   335,   345,   347,   353,   353,
     355,   355,   357,   359,   369,   376,   384,   385,   392,   398,
     398,   400,   400,   402,   404,   412,   414,   420,   420,   422,
     422,   424,   426,   435,   437,   444,   444,   446,   446,   448,
     450,   460,   462,   469,   469,   471,   471,   473,   475,   485,
     487,   493,   493,   495,   495,   497,   499,   509,   511,   517,
     517,   519,   519,   521,   523,   533,   540,   549,   550,   556,
     563,   563,   565,   565,   567,   569,   577,   583,   593,   601,
     606,   612,   612,   614,   616,   620,   620,   622,   630,   649,
     655,   655,   658,   662,   663,   666,   666,   675,   675,   677,
     687,   687,   689,   689,   691,   693,   695,   695,   698,   699,
     700,   701,   702,   706,   708,   718,   720,   720,   723,   724,
     727,   729,   737,   739,   749,   751,   751,   754,   755,   758,
     760,   769,   771,   781,   783,   783,   786,   787,   790,   792,
     801,   803,   811,   812,   814,   816,   827,   833,   843,   851,
     855,   860,   860,   862,   864,   868,   868,   870,   878,   897,
     902,   902,   905,   910,   911,   914,   914,   923,   923,   925,
     932,   932,   934,   934,   936,   938,   940,   940,   943,   944,
     948,   950,   956,   956,   958,   958,   960,   962,   973,   979,
     989,   997,  1001,  1006,  1006,  1008,  1010,  1014,  1014,  1016,
    1024,  1043,  1048,  1048,  1051,  1056,  1057,  1060,  1060,  1068,
    1068,  1070,  1090,  1090,  1092,  1092,  1094,  1096,  1098,  1098,
    1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,  1120,  1126,  1136,  1137,  1139,
    1139,  1141,  1141,  1143,  1145,  1147,  1154,  1156,  1162,  1162,
    1164,  1164,  1166,  1168,  1178,  1189,  1199,  1201,  1201,  1203,
    1203,  1205,  1214,  1214,  1216,  1237,  1248,  1258,  1258,  1260,
    1260,  1262,  1273,  1284,  1294,  1294,  1296,  1296,  1298,  1309,
    1320,  1330,  1330,  1332,  1332,  1334,  1345,  1356,  1366,  1366,
    1368,  1368,  1370,  1381,  1397,  1407,  1409,  1409,  1411,  1411,
    1413,  1422,  1422,  1424,  1428,  1444,  1454,  1456,  1456,  1458,
    1458,  1460,  1469,  1469,  1471,  1475,  1491,  1501,  1503,  1503,
    1505,  1505,  1507,  1516,  1516,  1518,  1522,  1538,  1548,  1550,
    1550,  1552,  1552,  1554,  1563,  1563,  1565,  1569,  1580,  1590,
    1592,  1592,  1594,  1594,  1596,  1607,  1618,  1628,  1630,  1630,
    1632,  1632,  1634,  1659,  1670,  1680,  1682,  1682,  1684,  1684,
    1686,  1695,  1695,  1697,  1718,  1724,  1734,  1742,  1746,  1751,
    1751,  1753,  1755,  1759,  1759,  1761,  1769,  1788,  1794,  1794,
    1797,  1802,  1803,  1806,  1806,  1814,  1814,  1816,  1824,  1826,
    1826,  1829,  1835,  1841,  1849,  1849,  1851,  1853,  1855,  1862,
    1862,  1864,  1870,  1877,  1877,  1882,  1882,  1884,  1886,  1888,
    1898,  1898,  1913,  1918,  1929,  1937,  1946,  1946,  1948,  1950,
    1952,  1952,  1955,  1960,  1974,  1980,  1980,  1983,  1995,  2000,
    2008,  2008,  2012,  2012,  2027,  2032,  2043,  2051,  2060,  2060,
    2062,  2064,  2066,  2066,  2069,  2074,  2089,  2095,  2095,  2098,
    2110,  2115,  2121,  2121,  2125,  2125,  2127,  2132,  2132,  2134,
    2136,  2138,  2141,  2141,  2152,  2158,  2165,  2165,  2167,  2169,
    2171,  2175,  2175,  2187,  2193,  2200,  2200,  2202,  2204,  2206,
    2210,  2210,  2221,  2227,  2234,  2234,  2236,  2238,  2240,  2244,
    2244,  2255,  2261,  2268,  2268,  2270,  2272,  2274,  2278,  2278,
    2289,  2295,  2302,  2302,  2304,  2306,  2308,  2312,  2312,  2323,
    2329,  2336,  2336,  2338,  2340,  2342,  2346,  2346,  2357,  2363,
    2370,  2370,  2372,  2374,  2376,  2380,  2380,  2396,  2401,  2412,
    2420,  2429,  2429,  2431,  2433,  2439,  2439,  2441,  2446,  2462,
    2468,  2468,  2471,  2483,  2488,  2496,  2496,  2500,  2500,  2506,
    2512,  2520,  2528,  2536,  2536,  2538,  2540,  2540,  2542,  2561,
    2577,  2585,  2585,  2588,  2589,  2598,  2601,  2601,  2603,  2603,
    2605,  2610,  2610,  2612,  2617,  2648,  2668,  2668,  2671,  2675,
    2679,  2680,  2681,  2682,  2683,  2684,  2685,  2686,  2689,  2689,
    2691,  2691,  2693,  2695,  2695,  2697,  2697,  2700,  2715,  2735,
    2737,  2737,  2740,  2750,  2751,  2752,  2753,  2756,  2758,  2758,
    2766,  2766,  2768,  2774,  2781,  2781,  2786,  2786,  2788,  2790,
    2792,  2801,  2801,  2817,  2823,  2835,  2843,  2852,  2852,  2854,
    2856,  2858,  2858,  2861,  2866,  2881,  2883,  2883,  2886,  2897,
    2901,  2908,  2908,  2911,  2911,  2929,  2934,  2948,  2956,  2965,
    2965,  2967,  2969,  2971,  2971,  2974,  2979,  2997,  2999,  2999,
    3002,  3013,  3017,  3023,  3030,  3030,  3034,  3034,  3036,  3041,
    3041,  3043,  3045,  3047,  3050,  3050,  3061,  3067,  3074,  3074,
    3076,  3078,  3080,  3083,  3083,  3094,  3100,  3107,  3107,  3109,
    3111,  3113,  3116,  3116,  3127,  3133,  3140,  3140,  3142,  3144,
    3146,  3149,  3149,  3160,  3166,  3173,  3173,  3175,  3177,  3179,
    3182,  3182,  3193,  3199,  3206,  3206,  3208,  3210,  3212,  3215,
    3215,  3226,  3233,  3240,  3240,  3242,  3244,  3246,  3250,  3250,
    3261,  3267,  3274,  3274,  3276,  3278,  3280,  3284,  3284,  3286,
    3292,  3323,  3344,  3344,  3347,  3351,  3355,  3356,  3357,  3358,
    3359,  3360,  3361,  3362,  3365,  3365,  3367,  3367,  3369,  3371,
    3371,  3373,  3373,  3376,  3391,  3413,  3415,  3415,  3418,  3428,
    3429,  3430,  3431,  3434,  3436,  3436,  3444,  3444,  3446,  3452,
    3459,  3459,  3464,  3464,  3466,  3468,  3470,  3479,  3479,  3495,
    3500,  3511,  3519,  3528,  3528,  3530,  3532,  3534,  3534,  3537,
    3542,  3557,  3563,  3563,  3566,  3577,  3581,  3588,  3588,  3592,
    3592,  3610,  3615,  3628,  3636,  3645,  3645,  3647,  3649,  3651,
    3651,  3654,  3659,  3677,  3683,  3683,  3686,  3697,  3701,  3705,
    3711,  3711,  3715,  3715,  3717,  3722,  3722,  3724,  3726,  3728,
    3731,  3731,  3742,  3748,  3755,  3755,  3757,  3759,  3761,  3764,
    3764,  3775,  3781,  3788,  3788,  3790,  3792,  3794,  3798,  3798,
    3809,  3815,  3822,  3822,  3824,  3826,  3828,  3832,  3832,  3843,
    3849,  3856,  3856,  3858,  3860,  3862,  3866,  3866,  3877,  3883,
    3890,  3890,  3892,  3894,  3896,  3900,  3900,  3911,  3917,  3924,
    3924,  3926,  3928,  3930,  3934,  3934,  3945,  3951,  3958,  3958,
    3960,  3962,  3964,  3968,  3968,  3970,  3976,  4007,  4027,  4027,
    4030,  4034,  4038,  4039,  4040,  4041,  4042,  4043,  4044,  4045,
    4048,  4048,  4050,  4050,  4052,  4054,  4054,  4056,  4056,  4059,
    4074,  4094,  4096,  4096,  4099,  4109,  4110,  4111,  4112,  4115,
    4117,  4117,  4125,  4125,  4131,  4133,  4141,  4149,  4158,  4160,
    4162,  4162,  4166,  4186,  4204,  4210,  4210,  4213,  4214,  4215,
    4216,  4217,  4218,  4219,  4226,  4234,  4243,  4243,  4245,  4247,
    4249,  4249,  4251,  4258,  4269,  4271,  4271,  4273,  4275,  4292,
    4292,  4294,  4316,  4333,  4345,  4350,  4350,  4353,  4354,  4355,
    4357,  4366,  4375,  4384,  4384,  4390,  4397,  4397,  4399,  4404,
    4411,  4417,  4417,  4419,  4422,  4429,  4436,  4436,  4438,  4441,
    4448,  4454,  4454,  4456,  4459,  4467,  4474,  4481,  4488,  4490,
    4496,  4503,  4503,  4505,  4510,  4517,  4523,  4523,  4525,  4530,
    4536,  4543,  4543,  4545,  4550,  4557,  4563,  4563,  4565,  4568,
    4576,  4582,  4582,  4584,  4587,  4594,  4600,  4602,  4610,  4616,
    4616,  4618,  4621,  4628,  4635,  4635,  4637,  4642,  4649,  4655,
    4655,  4657,  4660,  4667,  4673,  4673,  4675,  4678,  4685,  4691,
    4691,  4693,  4696,  4703,  4709,  4709,  4711,  4714,  4726,  4735,
    4744,  4753,  4762,  4771,  4781,  4790,  4799,  4805,  4811,  4817,
    4823,  4837,  4847,  4858,  4864,  4873,  4894,  4894,  4896,  4914,
    4930,  4938,  4938,  4941,  4948,  4949,  4953,  4953,  4955,  4958,
    4960,  4964,  4965,  4972,  4974,  4974,  4976,  4977,  4978,  4979,
    5011,  5013,  5027,  5027,  5029,  5029,  5031,  5033,  5035,  5035,
    5038,  5039,  5040,  5041,  5042,  5044,  5044,  5052,  5052,  5054,
    5054,  5056,  5062,  5062,  5070,  5070,  5072,  5072,  5074,  5080,
    5080,  5088,  5088,  5090,  5090,  5092,  5098,  5098,  5106,  5106,
    5108,  5108,  5110,  5116,  5116,  5124,  5124,  5126,  5126,  5128,
    5140,  5148,  5150,  5150,  5152,  5154,  5163,  5165,  5165,  5167,
    5167,  5169,  5185,  5187,  5192,  5192,  5194,  5194,  5197,  5223,
    5231
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
  "EMPTYWEIGHTATT", "TRANSPORTTYPEATT", "LOCATIONTYPEATT", "HEADERSTART",
  "HEADEREND", "GENERALSTART", "GENERALEND", "SYSTEMSTART", "SYSTEMEND",
  "SERVICESTART", "SERVICEEND", "JOBSTART", "JOBEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "FILENAMESTART", "FILENAMEEND", "FILENAMEEMPTY",
  "FILENAMESTARTANDEND", "FILESOURCESTART", "FILESOURCEEND",
  "FILESOURCEEMPTY", "FILESOURCESTARTANDEND", "FILEDESCRIPTIONSTART",
  "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
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
  "BLOCKSSTART", "BLOCKSEND", "EMPTYSYMMETRYATT", "SYMMETRYATT",
  "NUMBEROFBLOCKSATT", "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT",
  "BASEMATRIXIDXATT", "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
  "BASEMATRIXSTARTROWATT", "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT",
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "EMPTYBASETRANSPOSEATT",
  "BASETRANSPOSEATT", "ELEMENTSSTART", "ELEMENTSEND", "EMPTYROWMAJORATT",
  "ROWMAJORATT", "DUMMY", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
  "osoldoc", "osolStartEmpty", "osolStart", "osolAttributes",
  "osolContent", "osolEmpty", "osolLaden", "osolEnd", "osolEnding",
  "osolBody", "headerElement", "generalElement", "generalElementStart",
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
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   270,   271,   271,   272,   273,   274,   274,   275,   275,
     276,   277,   278,   279,   279,   280,   281,   281,   282,   282,
     283,   284,   284,   285,   285,   286,   287,   288,   288,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     290,   291,   292,   292,   293,   293,   294,   295,   296,   297,
     298,   298,   299,   299,   300,   301,   302,   303,   304,   304,
     305,   305,   306,   307,   308,   309,   310,   310,   311,   312,
     312,   313,   313,   314,   315,   316,   317,   318,   318,   319,
     319,   320,   321,   322,   323,   324,   324,   325,   325,   326,
     327,   328,   329,   330,   330,   331,   331,   332,   333,   334,
     335,   336,   336,   337,   337,   338,   339,   340,   341,   342,
     342,   343,   343,   344,   345,   346,   347,   348,   348,   349,
     350,   350,   351,   351,   352,   353,   354,   355,   356,   357,
     357,   358,   358,   359,   360,   361,   361,   362,   363,   364,
     365,   365,   366,   366,   366,   367,   367,   368,   368,   369,
     370,   370,   371,   371,   372,   373,   374,   374,   375,   375,
     375,   375,   375,   376,   377,   378,   379,   379,   380,   380,
     381,   382,   383,   384,   385,   386,   386,   387,   387,   388,
     389,   390,   391,   392,   393,   393,   394,   394,   395,   396,
     397,   398,   399,   399,   400,   401,   402,   403,   404,   405,
     405,   406,   406,   407,   408,   409,   409,   410,   411,   412,
     413,   413,   414,   414,   414,   415,   415,   416,   416,   417,
     418,   418,   419,   419,   420,   421,   422,   422,   423,   423,
     424,   425,   426,   426,   427,   427,   428,   429,   430,   431,
     432,   433,   433,   434,   434,   435,   436,   437,   437,   438,
     439,   440,   441,   441,   442,   442,   442,   443,   443,   444,
     444,   445,   446,   446,   447,   447,   448,   449,   450,   450,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   452,   453,   454,   454,   455,
     455,   456,   456,   457,   458,   459,   460,   461,   462,   462,
     463,   463,   464,   465,   466,   467,   468,   469,   469,   470,
     470,   471,   472,   472,   473,   474,   475,   476,   476,   477,
     477,   478,   479,   480,   481,   481,   482,   482,   483,   484,
     485,   486,   486,   487,   487,   488,   489,   490,   491,   491,
     492,   492,   493,   494,   495,   496,   497,   497,   498,   498,
     499,   500,   500,   501,   502,   503,   504,   505,   505,   506,
     506,   507,   508,   508,   509,   510,   511,   512,   513,   513,
     514,   514,   515,   516,   516,   517,   518,   519,   520,   521,
     521,   522,   522,   523,   524,   524,   525,   526,   527,   528,
     529,   529,   530,   530,   531,   532,   533,   534,   535,   535,
     536,   536,   537,   538,   539,   540,   541,   541,   542,   542,
     543,   544,   544,   545,   546,   547,   548,   549,   549,   550,
     550,   551,   552,   553,   553,   554,   555,   556,   557,   557,
     558,   558,   558,   559,   559,   560,   560,   561,   562,   563,
     563,   564,   564,   564,   565,   565,   566,   567,   568,   569,
     569,   570,   571,   572,   572,   573,   573,   574,   575,   576,
     577,   577,   578,   579,   580,   580,   581,   581,   582,   583,
     584,   584,   585,   586,   587,   588,   588,   589,   589,   589,
     590,   590,   591,   591,   592,   593,   594,   594,   595,   595,
     596,   597,   598,   598,   599,   600,   601,   602,   602,   603,
     603,   603,   604,   604,   605,   605,   606,   607,   607,   608,
     609,   610,   611,   611,   612,   613,   614,   614,   615,   616,
     617,   618,   618,   619,   620,   621,   621,   622,   623,   624,
     625,   625,   626,   627,   628,   628,   629,   630,   631,   632,
     632,   633,   634,   635,   635,   636,   637,   638,   639,   639,
     640,   641,   642,   642,   643,   644,   645,   646,   646,   647,
     648,   649,   649,   650,   651,   652,   653,   653,   654,   655,
     656,   656,   657,   658,   659,   660,   660,   661,   662,   663,
     663,   664,   664,   665,   666,   667,   667,   668,   669,   670,
     671,   671,   672,   672,   672,   673,   673,   674,   674,   675,
     676,   677,   677,   678,   678,   679,   680,   680,   681,   682,
     683,   684,   684,   685,   685,   685,   686,   686,   687,   687,
     688,   689,   689,   690,   691,   692,   693,   693,   694,   694,
     694,   694,   694,   694,   694,   694,   694,   694,   695,   695,
     696,   696,   697,   698,   698,   699,   699,   700,   701,   702,
     703,   703,   704,   704,   704,   704,   704,   705,   706,   706,
     707,   707,   708,   709,   710,   710,   711,   711,   712,   713,
     714,   715,   715,   716,   717,   718,   718,   719,   719,   720,
     721,   722,   722,   723,   724,   725,   726,   726,   727,   727,
     727,   728,   728,   729,   729,   730,   731,   732,   732,   733,
     733,   734,   735,   736,   736,   737,   738,   739,   740,   740,
     741,   741,   741,   741,   742,   742,   743,   743,   744,   745,
     745,   746,   747,   748,   749,   749,   750,   751,   752,   752,
     753,   754,   755,   756,   756,   757,   758,   759,   759,   760,
     761,   762,   763,   763,   764,   765,   766,   766,   767,   768,
     769,   770,   770,   771,   772,   773,   773,   774,   775,   776,
     777,   777,   778,   779,   780,   780,   781,   782,   783,   784,
     784,   785,   786,   787,   787,   788,   789,   790,   791,   791,
     792,   793,   794,   794,   795,   796,   797,   798,   798,   799,
     800,   801,   802,   802,   803,   803,   803,   803,   803,   803,
     803,   803,   803,   803,   804,   804,   805,   805,   806,   807,
     807,   808,   808,   809,   810,   811,   812,   812,   813,   813,
     813,   813,   813,   814,   815,   815,   816,   816,   817,   818,
     819,   819,   820,   820,   821,   822,   823,   824,   824,   825,
     826,   827,   827,   828,   828,   829,   830,   831,   831,   832,
     833,   834,   835,   835,   836,   836,   836,   837,   837,   838,
     838,   839,   840,   841,   841,   842,   842,   843,   844,   845,
     845,   846,   847,   848,   849,   849,   850,   850,   850,   850,
     851,   851,   852,   852,   853,   854,   854,   855,   856,   857,
     858,   858,   859,   860,   861,   861,   862,   863,   864,   865,
     865,   866,   867,   868,   868,   869,   870,   871,   872,   872,
     873,   874,   875,   875,   876,   877,   878,   879,   879,   880,
     881,   882,   882,   883,   884,   885,   886,   886,   887,   888,
     889,   889,   890,   891,   892,   893,   893,   894,   895,   896,
     896,   897,   898,   899,   900,   900,   901,   902,   903,   903,
     904,   905,   906,   907,   907,   908,   909,   910,   911,   911,
     912,   912,   912,   912,   912,   912,   912,   912,   912,   912,
     913,   913,   914,   914,   915,   916,   916,   917,   917,   918,
     919,   920,   921,   921,   922,   922,   922,   922,   922,   923,
     924,   924,   925,   925,   926,   927,   928,   928,   929,   930,
     931,   931,   932,   933,   934,   935,   935,   936,   936,   936,
     936,   936,   936,   936,   937,   937,   938,   938,   939,   940,
     941,   941,   942,   943,   943,   944,   944,   945,   946,   947,
     947,   948,   949,   950,   951,   952,   952,   953,   953,   953,
     954,   955,   956,   957,   957,   958,   959,   959,   960,   961,
     962,   963,   963,   964,   965,   966,   967,   967,   968,   969,
     970,   971,   971,   972,   973,   974,   975,   976,   977,   978,
     979,   980,   980,   981,   982,   983,   984,   984,   985,   986,
     987,   988,   988,   989,   990,   991,   992,   992,   993,   994,
     995,   996,   996,   997,   998,   999,  1000,  1001,  1002,  1003,
    1003,  1004,  1005,  1006,  1007,  1007,  1008,  1009,  1010,  1011,
    1011,  1012,  1013,  1014,  1015,  1015,  1016,  1017,  1018,  1019,
    1019,  1020,  1021,  1022,  1023,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1044,  1045,  1046,
    1047,  1048,  1048,  1049,  1049,  1049,  1050,  1050,  1051,  1052,
    1053,  1054,  1054,  1055,  1056,  1056,  1057,  1057,  1057,  1057,
    1058,  1059,  1060,  1060,  1061,  1061,  1062,  1063,  1064,  1064,
    1065,  1065,  1065,  1065,  1065,  1066,  1066,  1067,  1067,  1068,
    1068,  1069,  1070,  1070,  1071,  1071,  1072,  1072,  1073,  1074,
    1074,  1075,  1075,  1076,  1076,  1077,  1078,  1078,  1079,  1079,
    1080,  1080,  1081,  1082,  1082,  1083,  1083,  1084,  1084,  1085,
    1086,  1086,  1087,  1087,  1088,  1089,  1090,  1091,  1091,  1092,
    1092,  1093,  1094,  1095,  1096,  1096,  1097,  1097,  1098,  1099,
    1100
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
#define YYPACT_NINF -1372
static const yytype_int16 yypact[] =
{
     141, -1372, -1372,    76,    47,   114, -1372, -1372,   163,   124,
   -1372,   318, -1372,   345, -1372, -1372, -1372, -1372,   169,   352,
     576, -1372, -1372, -1372, -1372,    47, -1372, -1372, -1372, -1372,
   -1372,   122,   357,   372, -1372, -1372, -1372, -1372, -1372,   247,
   -1372, -1372,   249, -1372, -1372,   257, -1372, -1372,   259, -1372,
   -1372,   261, -1372, -1372,   192,   596, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   163, -1372,   202,
     359,   -25, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   195,   444,
   -1372, -1372,   361, -1372,   368, -1372,   370, -1372,   215, -1372,
     373, -1372,   378, -1372,   382, -1372,   384, -1372,   403, -1372,
     222, -1372,   281,   211,   217,   218,   203,   227, -1372, -1372,
   -1372, -1372,   248,   407,   -28, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   265,   -65, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,    71, -1372,   281, -1372, -1372,
      32, -1372, -1372, -1372, -1372,    29, -1372, -1372, -1372, -1372,
      35, -1372, -1372, -1372, -1372,   304,   430, -1372,    28, -1372,
   -1372, -1372, -1372,    27, -1372, -1372, -1372, -1372,    26, -1372,
   -1372, -1372, -1372,    30, -1372, -1372, -1372, -1372,    17, -1372,
   -1372, -1372, -1372,   347,   432, -1372, -1372,   434, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   133, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   275,    38, -1372, -1372,   436,
   -1372,   281, -1372, -1372,   349,   260,   354,   260,   365,   260,
     387, -1372,   392, -1372, -1372, -1372, -1372,   442, -1372, -1372,
   -1372,   298, -1372, -1372,   263, -1372, -1372,   308,   421,    41,
   -1372, -1372, -1372, -1372, -1372, -1372,   317, -1372, -1372,   343,
   -1372, -1372,   329, -1372, -1372,   350, -1372, -1372,   356,   466,
      25, -1372, -1372, -1372, -1372,   472,     3,   326, -1372, -1372,
   -1372, -1372,   449,   312, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
     381,   385, -1372, -1372,    75, -1372,   453, -1372,   470, -1372,
     465, -1372,   465, -1372,   465, -1372,   465, -1372,   476, -1372,
     476, -1372,   476, -1372,   476, -1372,   465, -1372,   465, -1372,
     463, -1372,   281, -1372, -1372,    23, -1372, -1372, -1372, -1372,
     457, -1372,   464, -1372,   495, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,   464, -1372, -1372, -1372, -1372,   464, -1372, -1372,
   -1372, -1372, -1372,   502, -1372,   348, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,   406, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   380, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   389,   396, -1372, -1372,   358,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   490, -1372,    13, -1372, -1372, -1372, -1372,
     521,   492, -1372,   523,   494,   500,   503,   505,   533,   513,
   -1372,   525, -1372,   563, -1372,   573, -1372,   575, -1372,   580,
   -1372,   539,   582, -1372,   584, -1372, -1372, -1372,   399,   468,
   -1372, -1372, -1372, -1372, -1372, -1372,   426, -1372,   552,   428,
   -1372,   443, -1372, -1372, -1372,   471, -1372, -1372,   438,   435,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   588,   126, -1372,
     482,   401,   537,   598,   635,   645,    16, -1372, -1372, -1372,
   -1372, -1372, -1372,   499,   647,   -56, -1372, -1372, -1372, -1372,
     654,   135, -1372, -1372, -1372, -1372,   452, -1372, -1372, -1372,
   -1372,    24, -1372, -1372, -1372, -1372,   -20, -1372, -1372, -1372,
   -1372,   656,   -32, -1372, -1372, -1372, -1372,   -40, -1372, -1372,
   -1372, -1372,  -103, -1372, -1372, -1372, -1372,   -88, -1372, -1372,
   -1372, -1372,    36, -1372, -1372, -1372, -1372,    46, -1372, -1372,
   -1372, -1372,   662,   439, -1372, -1372, -1372, -1372,   487, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,   544,   547, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   615,   126,   493,
   -1372, -1372,   677,   681, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   475,   658,
   -1372,   617, -1372, -1372, -1372, -1372, -1372, -1372,   558, -1372,
   -1372, -1372,   688,   709, -1372,   -55, -1372,   814, -1372,   734,
     172, -1372, -1372,   479, -1372,    53, -1372,    77,   815, -1372,
   -1372,    21, -1372, -1372, -1372, -1372,   -29, -1372, -1372, -1372,
     -76, -1372, -1372, -1372,   -61, -1372, -1372, -1372,    74, -1372,
      79,   816, -1372,   770,   459, -1372, -1372, -1372,   698,   696,
   -1372, -1372, -1372, -1372,   625,   126,   699, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   819, -1372,   607,   795, -1372,
     627, -1372, -1372,   825,   655, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   829, -1372, -1372, -1372,   830, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   629,   331, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   831, -1372,
   -1372, -1372, -1372,   637,   126,   706, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   809, -1372,   639,
   -1372, -1372,   832,   632, -1372, -1372, -1372, -1372, -1372, -1372,
     664,   660,   805,   727,   692,   691, -1372, -1372,   843,   844,
     845, -1372, -1372, -1372, -1372,   675,   720, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   646, -1372,   846,   636, -1372,
   -1372, -1372, -1372, -1372, -1372,   649,   642,   818, -1372, -1372,
   -1372,   674,   805, -1372,   648, -1372, -1372, -1372, -1372,   850,
     851,   852, -1372, -1372,   856, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,   650,   644,   826, -1372, -1372, -1372,   683,   818,
   -1372,   693, -1372, -1372,   668,   695,   697, -1372,   862,   531,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   489, -1372,
   -1372, -1372,   686,   826, -1372,   703, -1372, -1372, -1372,   705,
     707, -1372,   864,   514, -1372, -1372, -1372, -1372, -1372,   670,
     805,   687, -1372, -1372, -1372, -1372,    -3, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   700,   694, -1372, -1372, -1372, -1372,
   -1372, -1372,   341, -1372, -1372,   714,   716, -1372,   868,   512,
   -1372, -1372, -1372, -1372,   746,   701, -1372, -1372, -1372, -1372,
     113, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   669,   667,
   -1372, -1372, -1372, -1372,   853,   722, -1372, -1372,   704,   690,
     840, -1372, -1372,   702,   708, -1372, -1372, -1372, -1372, -1372,
     724,   151,   878,   880, -1372, -1372, -1372,   882, -1372,   726,
     341, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   760,   710,
   -1372, -1372, -1372, -1372,   107, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,   676,   673, -1372, -1372, -1372, -1372, -1372, -1372,
     712,   711,   840, -1372, -1372,   679,   684, -1372, -1372, -1372,
   -1372, -1372,   728,   151,   765,   889,   730,  -121, -1372, -1372,
   -1372, -1372, -1372, -1372,   715,   840, -1372,   732, -1372, -1372,
   -1372,   736,   151,   718, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   891,   895, -1372,    -1, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   721,   717,   840,
   -1372, -1372,   689,   713, -1372, -1372, -1372, -1372, -1372,   738,
     151,   740,   164, -1372, -1372,   723,   840,   742, -1372, -1372,
   -1372,   744,   374,   719, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   901,   554, -1372, -1372, -1372, -1372, -1372,
   -1372,   725,   735, -1372, -1372, -1372,   729,   840,   748, -1372,
     905,   731, -1372, -1372, -1372, -1372,   737, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   909, -1372, -1372, -1372, -1372, -1372,
   -1372,   913, -1372,   733,    83, -1372, -1372, -1372, -1372,   750,
     291, -1372, -1372,   739,   840,   752, -1372, -1372, -1372,   754,
     190,   741, -1372, -1372, -1372, -1372, -1372, -1372,   -95, -1372,
   -1372, -1372, -1372, -1372,   916, -1372,   918, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,   743,   840,   756, -1372,
     731, -1372, -1372, -1372, -1372,   745, -1372, -1372, -1372, -1372,
     919,   920, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   758,   564,   923, -1372, -1372,   568,
   -1372, -1372, -1372, -1372,   762,   151, -1372,   747,   840,   764,
   -1372,   731, -1372, -1372, -1372, -1372, -1372,   749,   751, -1372,
     753, -1372, -1372, -1372, -1372, -1372,   757, -1372, -1372,   -92,
   -1372, -1372, -1372, -1372,   921, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,   755,   840,   766, -1372,   731, -1372, -1372, -1372, -1372,
     759, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,   797,   761, -1372, -1372,   763, -1372, -1372,   922,
     924,   925, -1372,   769,   840,   768, -1372,   731, -1372, -1372,
   -1372, -1372,   767, -1372, -1372, -1372, -1372,   -83, -1372, -1372,
   -1372, -1372,   932, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,   772,    72,   771, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,   773,   840,   774, -1372,   731, -1372, -1372, -1372, -1372,
     775, -1372, -1372, -1372,   776, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   811,   777, -1372, -1372,   763,   928, -1372,
     779,   840,   778, -1372,   731, -1372, -1372, -1372, -1372,   781,
   -1372, -1372,   464,   464, -1372, -1372,   780,   363, -1372,   782,
     207, -1372, -1372, -1372, -1372,   785,   840,   784, -1372,   731,
   -1372, -1372, -1372, -1372,   783, -1372, -1372, -1372, -1372, -1372,
   -1372,   817,   789, -1372, -1372,   763,   930,  -126, -1372, -1372,
   -1372, -1372,   931, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   788,   840,   786, -1372,   731, -1372, -1372,
   -1372, -1372,   787, -1372, -1372,   934,     9, -1372, -1372, -1372,
   -1372,   935,   565, -1372, -1372,   790,   363, -1372, -1372,   799,
     840,   792, -1372,   731, -1372, -1372, -1372, -1372,   793, -1372,
   -1372, -1372, -1372,   791, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   731, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   801,   840,   794, -1372,   731, -1372,
   -1372, -1372, -1372,   807, -1372, -1372, -1372, -1372,   796,   363,
   -1372, -1372,  -122,   464,   942, -1372, -1372,   840,   798, -1372,
     731, -1372, -1372, -1372, -1372,   812, -1372, -1372, -1372,   813,
   -1372,   943, -1372, -1372, -1372, -1372, -1372, -1372,   803, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   820,
     840,   800, -1372,   731, -1372, -1372, -1372, -1372,   821, -1372,
   -1372, -1372, -1372, -1372,   822, -1372, -1372, -1372,   840,   802,
   -1372,   731, -1372, -1372, -1372, -1372,   823, -1372, -1372,   827,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
     944, -1372,   804, -1372,   731, -1372, -1372, -1372, -1372,   824,
   -1372, -1372, -1372, -1372,   828,   948,   950, -1372, -1372, -1372,
     840,   806, -1372,   731, -1372, -1372, -1372, -1372,   833, -1372,
   -1372, -1372,   808, -1372,   731, -1372, -1372, -1372, -1372,   834,
   -1372, -1372, -1372, -1372, -1372,   731, -1372, -1372, -1372, -1372,
     837, -1372, -1372, -1372, -1372, -1372,   810, -1372,   731, -1372,
   -1372, -1372, -1372,   841, -1372, -1372,   731, -1372, -1372, -1372,
   -1372,   842, -1372, -1372,   848, -1372, -1372, -1372, -1372,   731,
   -1372, -1372, -1372, -1372,   847, -1372, -1372,   849, -1372, -1372,
   -1372,   854, -1372, -1372, -1372, -1372
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   873, -1372,
     933, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   861,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,   555, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   857, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
     484, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   836, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   394, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,   661, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   344, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,   338, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   334,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   337, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   336, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   332, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   324, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   112, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,    65,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,  -427, -1083, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,  -207, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
    -417, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,    87, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,    12, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,  -283,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,    31, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,   -42, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,  -362, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,    63, -1372, -1372, -1372,
   -1372, -1372,  -108, -1372, -1372, -1372, -1372,  -452,  -464,  -486,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1046, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,  -154, -1372, -1372, -1372,
   -1089, -1372, -1372, -1372, -1372, -1372,  -997, -1372, -1372, -1371,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,  -485, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1044, -1372, -1372, -1372, -1372,
   -1372, -1372, -1043, -1372, -1372, -1372, -1369, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,  -191, -1372, -1372, -1372,  -484, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,  -843, -1372,  -978, -1078,
   -1372, -1372,  -817, -1372, -1372, -1372,  -142, -1372,   -71,   -45,
   -1372, -1372,  -797, -1372, -1199, -1276, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,  -360,  -372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   963, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1172, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     473,   243,   470,   598,   602,   837,  1077,   472,  1313,  1213,
     897,   397,   861,  1539,  1068,   248,  1159,   501,  1170,  1171,
    1398,   276,   464,   465,   484,  1110,  1489,   456,  1491,   393,
     270,   267,   264,   252,   273,  1289,   249,  1099,  1371,   255,
    1377,  1253,   493,   494,   495,   384,   366,  1419,   371,  1361,
     639,   648,  1259,  1089,   222,   139,   652,  1089,  1089,   623,
     623,   656,   140,  1145,   633,   639,   141,   649,   142,   635,
     143,  1136,   144,   926,   637,  1193,     6,   639,  1521,  1090,
     653,   357,  1599,   365,  1247,   370,  1255,  1256,  1179,   351,
     624,   705,   639,  1390,   721,  1554,  1420,  1556,  1432,   223,
     658,  1398,   140,   681,   682,   660,   141,   723,   142,   803,
     143,   224,   144,   639,  1290,  1433,  1327,   240,  1425,  1220,
     354,   639,     7,   424,   639,  1372,   645,  1336,    12,   241,
    1291,   629,   640,  1291,   355,  1415,   620,   719,   636,   253,
     250,   277,  1291,  1278,   265,   268,   271,   256,  1595,  1398,
    1597,   394,   274,     1,     2,   385,  1264,   502,   617,  1325,
     648,  1329,  1330,   457,   652,   223,   710,   592,   656,   710,
     593,   710,   240,   710,   639,   629,   931,   224,    14,   932,
     634,  1153,   594,  1453,   241,   715,   595,   629,   942,   943,
     740,   741,   592,  1026,   710,   593,   710,   629,   657,  1306,
     455,    17,   830,    78,   629,   592,   659,   594,   593,   712,
     240,   595,  1479,  1154,  1155,  1156,  1157,   294,  1347,   945,
     594,   946,   241,  1119,   595,   629,  1120,  1121,   629,  1122,
     629,   592,  1026,   947,   948,   713,   725,  1514,   693,   726,
    1354,  1540,   699,   700,   701,  1174,   594,  1016,    30,   781,
     782,   593,   123,   240,   124,  1273,  1274,  1275,  1276,   442,
     295,   444,   125,   446,   126,   241,   127,   595,   128,   398,
     399,   400,   401,   158,   296,  1536,   297,   435,   298,   436,
     299,   437,   300,   628,  1383,   131,   629,  1258,   301,   175,
     302,   448,   303,   450,   304,   203,   305,   206,   306,   209,
     307,  1569,   308,   212,   309,   354,   240,   258,  1153,   210,
    1120,  1121,   743,  1122,   211,   942,   943,   752,   241,   355,
     709,  1575,   993,   629,  1050,   994,  1408,  1051,    20,    21,
     854,   213,   592,   214,   597,   593,  1587,   240,  1244,  1245,
    1154,  1155,   414,   415,   416,   232,   945,   594,   946,   241,
     279,   595,   768,   769,   770,    25,    26,   343,  1610,   352,
     947,   948,    33,    34,   362,   942,   943,    81,    82,   134,
     135,   160,   161,   381,  1446,   367,   787,   944,   165,   166,
     170,   171,   592,   178,   179,   593,   798,   240,   183,   184,
     372,  1629,   188,   189,   193,   194,   945,   594,   946,   241,
    1488,   595,   373,  1472,   592,  1026,   380,   593,  1337,  1640,
     947,   948,   814,   198,   199,   592,  1026,   217,   218,   594,
     382,   825,  1500,   595,  1188,  1189,  1190,  1191,  1507,   383,
     594,   838,  1651,   387,   680,  1188,  1189,  1190,  1191,  1213,
     259,   260,   280,   281,   287,   288,   345,   346,   849,   389,
      86,  1664,   375,   376,   403,   404,  1031,  1032,   862,   409,
     410,   388,  1672,   425,   426,   421,  1529,   459,   460,  1553,
     464,   465,   390,  1675,   392,   888,   476,   477,   396,    87,
     391,    88,   898,    89,   433,    90,  1685,    91,   430,    92,
     451,    93,  1562,    94,  1688,    95,   438,    96,   468,    97,
     496,   497,   505,   506,   511,   512,   483,  1692,   474,   937,
     516,   517,   295,   521,   522,   526,   527,   485,  1078,  1079,
     482,   739,  1594,   532,   533,   404,   296,  1580,   297,   504,
     298,   510,   299,   489,   300,   537,   538,  1111,  1112,   573,
     301,   531,   302,   999,   303,  1440,   304,   562,   305,  1603,
     306,    87,   307,    88,   308,    89,   309,    90,   580,    91,
     581,    92,   582,    93,   477,    94,   585,    95,   606,    96,
     610,    97,  1035,   542,   543,  1146,  1147,  1165,  1172,   583,
     780,  1153,  1622,   547,   548,   552,   553,  1198,   942,   943,
     557,   558,   563,   564,   568,   569,   574,   575,   589,   590,
    1633,   803,   632,   629,   614,   592,   607,  1056,   593,   584,
     240,   662,   663,  1154,  1155,   666,   667,  1322,  1323,   945,
     594,   946,   241,   683,   595,   676,   677,   694,   695,   711,
     629,   729,   663,   947,   948,   735,   736,   753,   754,   765,
     766,   615,  1657,   621,  1100,  1254,  1257,   776,   777,   788,
     789,   616,    38,   622,  1114,  1283,   815,   816,   839,   840,
     627,  1115,   638,    39,  1118,    40,    41,    42,   661,    43,
      44,    45,   672,    46,    47,    48,   575,    49,    50,    51,
     684,    52,    53,    39,   685,    40,    41,    42,   686,    43,
      44,    45,   689,    46,    47,    48,   703,    49,    50,    51,
     702,    52,    53,   863,   864,   871,   872,   876,   877,   882,
     883,   889,   890,   899,   900,   905,   906,   910,   911,   704,
    1328,  1331,   916,   917,   969,   970,   974,   975,   980,   981,
    1348,  1349,  1007,  1008,  1023,  1024,  1037,  1038,  1073,  1074,
    1084,  1085,  1101,  1102,   708,  1234,  1106,  1107,  1141,  1142,
    1148,  1149,  1180,  1181,  1185,  1186,  1207,  1208,  1221,  1222,
    1239,  1240,  1265,  1266,  1270,  1271,  1307,  1308,  1317,  1318,
    1339,  1208,  1343,  1344,  1355,  1356,  1384,  1385,  1409,  1410,
     728,  1299,  1427,  1428,  1447,  1448,  1456,  1457,  1473,  1474,
    1483,  1484,  1493,  1494,  1508,  1509,  1530,  1531,  1543,  1544,
    1548,  1549,  1563,  1564,  1581,  1582,  1589,  1590,  1604,  1605,
    1623,  1624,  1634,  1635,  1645,  1646,  1658,  1659,  1666,  1667,
    1679,  1680,   707,   714,   727,   667,   731,   744,   745,   742,
     748,   758,   759,   763,   764,   775,   783,   784,   793,   794,
     799,   800,   803,   806,   807,   808,   809,   810,   811,   812,
     813,   821,   820,   827,  1362,   826,   830,   833,   844,   845,
     846,  1369,   847,   851,   850,   854,   857,   868,   881,   893,
     915,   922,   927,   883,   979,   986,   917,  1000,   938,  1013,
    1016,  1033,  1005,  1034,  1019,  1036,   989,   931,  1012,  1043,
     981,  1069,  1057,   993,  1080,  1046,  1063,  1083,  1113,  1116,
    1064,  1117,  1095,  1392,  1393,  1131,  1132,  1206,  1160,  1137,
    1175,  1226,  1490,  1492,  1089,  1233,  1499,  1232,  1235,  1300,
    1216,  1301,  1315,  1316,  1378,  1212,  1260,  1394,  1401,  1203,
    1050,  1338,  1402,  1403,  1302,  1426,  1467,  1365,  1520,  1523,
    1538,  1463,  1350,  1417,  1418,  1541,  1379,  1516,  1601,  1614,
     130,  1441,  1643,  1416,  1654,  1314,  1655,  1237,    77,  1288,
     159,   486,  1227,   586,  1404,  1454,  1442,  1480,  1420,   706,
    1290,   673,   422,  1515,  1468,  1537,  1252,  1391,  1503,   716,
     720,  1555,  1557,  1570,  1363,  1525,  1370,   722,  1291,  1366,
     724,  1455,  1558,   732,  1372,  1588,   730,   939,  1576,  1020,
    1522,  1573,  1340,   233,  1611,  1517,  1001,  1642,  1070,  1630,
    1395,  1138,  1464,  1042,  1058,  1641,  1238,  1618,   129,     0,
    1652,  1617,     0,     0,     0,  1665,     0,     0,     0,  1502,
    1673,  1676,  1481,  1482,  1596,  1598,  1689,  1686,     0,     0,
       0,  1693,     0,     0,     0,  1613,  1690,  1694,  1631,     0,
       0,  1326,  1695,     0,     0,     0,     0,     0,     0,     0,
       0,  1524,   344,     0,     0,  1653,     0,     0,     0,     0,
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
     853,     8,   829,     4,   992,   157,  1062,     4,  1062,  1062,
    1296,     4,     6,     7,   396,  1022,  1397,     4,  1397,     4,
       4,     4,     4,     4,     4,   130,     4,  1015,   130,     4,
    1239,  1130,   414,   415,   416,     4,   237,   130,   239,  1221,
     153,   537,  1130,   179,    82,    80,   542,   179,   179,   115,
     115,   547,   127,  1060,   516,   153,   131,   170,   133,   521,
     135,  1049,   137,   870,   526,  1072,     0,   153,   204,   200,
     168,   235,   204,   237,  1130,   239,  1130,  1130,  1066,   231,
     146,   146,   153,  1265,   170,  1466,   179,  1466,    26,   127,
     552,  1377,   127,   588,   588,   557,   131,   168,   133,    37,
     135,   139,   137,   153,   209,    43,  1205,    46,  1317,  1097,
      45,   153,    75,   314,   153,   217,   166,  1205,    14,    58,
     225,   151,   164,   225,    59,  1307,   496,   166,   158,   110,
     108,   124,   225,  1140,   116,   118,   120,   112,  1519,  1425,
    1519,   126,   122,    12,    13,   114,  1134,   144,   142,  1205,
     646,  1205,  1205,   140,   650,   127,   630,    41,   654,   633,
      44,   635,    46,   637,   153,   151,   179,   139,    15,   182,
     156,    17,    56,  1355,    58,   164,    60,   151,    24,    25,
     675,   675,    41,    42,   658,    44,   660,   151,   162,  1177,
     342,    77,    38,    81,   151,    41,   160,    56,    44,   156,
      46,    60,  1384,    49,    50,    51,    52,    84,  1215,    55,
      56,    57,    58,   224,    60,   151,   227,   228,   151,   230,
     151,    41,    42,    69,    70,   158,   162,  1409,   610,   160,
    1218,   232,   614,   615,   616,  1062,    56,    40,    79,   734,
     734,    44,     5,    46,     5,    65,    66,    67,    68,   330,
     127,   332,     5,   334,     5,    58,     5,    60,    76,   266,
     267,   268,   269,    78,   141,  1447,   143,   322,   145,   324,
     147,   326,   149,   148,  1262,    83,   151,  1130,   155,    74,
     157,   336,   159,   338,   161,    73,   163,    16,   165,    88,
     167,  1473,   169,   100,   171,    45,    46,     3,    17,    92,
     227,   228,   684,   230,    96,    24,    25,   689,    58,    59,
     148,  1493,   209,   151,   217,   212,  1304,   220,    10,    11,
      39,   104,    41,    85,   488,    44,  1508,    46,    47,    48,
      49,    50,    30,    31,    32,    80,    55,    56,    57,    58,
       3,    60,    21,    22,    23,    10,    11,    82,  1530,    10,
      69,    70,    10,    11,    10,    24,    25,    10,    11,    10,
      11,    10,    11,   110,  1352,    10,   748,    36,    10,    11,
      10,    11,    41,    10,    11,    44,   758,    46,    10,    11,
       3,  1563,    10,    11,    10,    11,    55,    56,    57,    58,
    1397,    60,    10,  1381,    41,    42,   108,    44,  1205,  1581,
      69,    70,   784,    10,    11,    41,    42,    10,    11,    56,
     112,   793,  1400,    60,    61,    62,    63,    64,  1406,     8,
      56,   803,  1604,   116,   588,    61,    62,    63,    64,  1522,
      10,    11,    10,    11,    10,    11,    10,    11,   820,   120,
      78,  1623,    10,    11,   128,   129,   941,   941,   830,    10,
      11,   118,  1634,    10,    11,    84,  1444,    10,    11,  1466,
       6,     7,   122,  1645,     8,   847,   128,   129,     6,   107,
     124,   109,   854,   111,    19,   113,  1658,   115,    18,   117,
      27,   119,  1470,   121,  1666,   123,    20,   125,     3,   127,
      10,    11,    10,    11,    10,    11,   126,  1679,     6,   881,
      10,    11,   127,    10,    11,    10,    11,   128,  1003,  1003,
     114,   675,  1519,    10,    11,   129,   141,  1505,   143,     8,
     145,     8,   147,   175,   149,    10,    11,  1022,  1022,   140,
     155,     8,   157,   915,   159,  1342,   161,     8,   163,  1527,
     165,   107,   167,   109,   169,   111,   171,   113,   132,   115,
       8,   117,   134,   119,   129,   121,   128,   123,    86,   125,
      33,   127,   944,    10,    11,  1060,  1060,  1062,  1062,   136,
     734,    17,  1560,    10,    11,    10,    11,  1072,    24,    25,
      10,    11,    10,    11,    10,    11,   128,   129,    10,    11,
    1578,    37,   150,   151,     6,    41,   205,   979,    44,   138,
      46,   172,   173,    49,    50,   128,   129,    53,    54,    55,
      56,    57,    58,   130,    60,    10,    11,    10,    11,   150,
     151,   172,   173,    69,    70,    10,    11,    10,    11,    10,
      11,     6,  1620,   144,  1016,  1130,  1130,    10,    11,    10,
      11,     6,    76,     6,  1026,  1140,    10,    11,    10,    11,
       6,  1033,     6,    87,  1036,    89,    90,    91,     6,    93,
      94,    95,   128,    97,    98,    99,   129,   101,   102,   103,
       3,   105,   106,    87,     3,    89,    90,    91,   213,    93,
      94,    95,    34,    97,    98,    99,     8,   101,   102,   103,
     142,   105,   106,    10,    11,    10,    11,    10,    11,   178,
     179,   222,   223,    10,    11,    10,    11,    10,    11,    10,
    1205,  1205,   208,   209,    10,    11,    10,    11,   216,   217,
    1215,  1215,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,  1117,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,   202,   203,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     202,   203,    10,    11,    10,    11,    10,    11,    10,    11,
      10,  1153,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,   233,   234,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,     8,     8,     8,   129,   128,     8,   221,   130,
      35,     6,   177,     4,     4,     4,   130,    28,     6,   207,
     176,   181,    37,   116,   152,   154,     3,     3,     3,   174,
     130,   215,     6,   211,  1226,   206,    38,   183,     8,     8,
       8,  1233,     6,   219,   214,    39,   183,   199,     6,   183,
       6,   201,   185,   179,     6,   129,   209,   208,   178,   189,
      40,     3,    29,     3,   182,     3,   185,   179,   184,   129,
     217,   212,   216,   209,   129,   185,   184,     8,   180,     8,
     189,     6,   187,  1275,  1276,   184,   189,     6,  1062,   220,
     187,     6,  1397,  1397,   179,     6,  1400,   180,     5,     3,
     191,     3,     3,     3,     3,   200,   187,   130,     6,   210,
     217,     8,     8,     8,   191,     3,     8,   186,     8,     8,
       6,   130,   195,  1315,  1316,    10,   191,   130,     6,     6,
      77,   180,     8,   186,     6,   210,     6,   224,    25,   218,
      99,   406,   231,   479,   195,   190,   193,   186,   179,   625,
     209,   577,   311,   190,   195,   188,  1130,   218,   193,   641,
     646,  1466,  1466,   190,   235,   197,   229,   650,   225,   236,
     654,  1363,   193,   669,   217,   188,   664,   885,   197,   934,
    1427,   210,  1209,   146,   192,  1422,   919,   180,   996,   188,
    1293,  1053,  1374,   950,   983,   192,  1124,   197,    55,    -1,
     196,   218,    -1,    -1,    -1,   192,    -1,    -1,    -1,  1401,
     196,   194,  1392,  1393,  1519,  1519,   194,   196,    -1,    -1,
      -1,   194,    -1,    -1,    -1,   232,   198,   198,   226,    -1,
      -1,  1205,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1433,   226,    -1,    -1,   237,    -1,    -1,    -1,    -1,
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
       0,    12,    13,   271,   272,   273,     0,    75,   280,   281,
    1058,  1059,    14,   274,    15,   278,   279,    77,   282,   283,
      10,    11,  1060,  1061,  1062,    10,    11,   275,   276,   277,
      79,   368,   369,    10,    11,   284,   285,   286,    76,    87,
      89,    90,    91,    93,    94,    95,    97,    98,    99,   101,
     102,   103,   105,   106,  1063,  1064,  1065,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,   280,    81,   416,
     417,    10,    11,   370,   371,   372,    78,   107,   109,   111,
     113,   115,   117,   119,   121,   123,   125,   127,   287,   288,
     289,   290,   291,   296,   297,   302,   303,   308,   309,   316,
     317,   322,   323,   328,   329,   334,   335,   340,   341,   346,
     347,   354,   355,     5,     5,     5,     5,     5,    76,  1065,
     278,    83,   444,   445,    10,    11,   418,   419,   420,    80,
     127,   131,   133,   135,   137,   373,   374,   375,   376,   377,
     383,   384,   390,   391,   397,   398,   402,   403,    78,   289,
      10,    11,   292,   293,   294,    10,    11,   298,   299,   300,
      10,    11,   304,   305,   306,    74,   310,   311,    10,    11,
     318,   319,   320,    10,    11,   324,   325,   326,    10,    11,
     330,   331,   332,    10,    11,   336,   337,   338,    10,    11,
     342,   343,   344,    73,   348,   349,    16,   356,  1036,    88,
      92,    96,   100,   104,    85,   560,   561,    10,    11,   446,
     447,   448,    82,   127,   139,   421,   422,   423,   424,   425,
     430,   431,    80,   375,   378,   379,   385,   386,   392,   393,
      46,    58,   399,   966,   967,   968,   969,   404,  1036,     4,
     108,   295,     4,   110,   301,     4,   112,   307,     3,    10,
      11,   312,   313,   314,     4,   116,   321,     4,   118,   327,
       4,   120,   333,     4,   122,   339,     4,   124,   345,     3,
      10,    11,   350,   351,   352,  1055,  1056,    10,    11,   357,
     358,   359,   562,   563,    84,   127,   141,   143,   145,   147,
     149,   155,   157,   159,   161,   163,   165,   167,   169,   171,
     449,   450,   451,   452,   453,   460,   461,   466,   467,   474,
     475,   479,   480,   484,   485,   489,   490,   494,   495,   502,
     503,   510,   511,   518,   519,   526,   527,   532,   533,   538,
     539,   546,   547,    82,   423,    10,    11,   426,   427,   428,
     432,  1036,    10,   381,    45,    59,   380,   966,  1014,  1015,
    1016,  1017,    10,   388,   387,   966,  1014,    10,   395,   394,
     966,  1014,     3,    10,   400,    10,    11,   405,   406,   407,
     108,   110,   112,     8,     4,   114,   315,   116,   118,   120,
     122,   124,     8,     4,   126,   353,     6,     8,   266,   267,
     268,   269,  1057,   128,   129,   360,   361,   362,   363,    10,
      11,   565,   566,   567,    30,    31,    32,   564,  1027,  1033,
    1043,    84,   451,   454,  1014,    10,    11,   462,   463,   464,
      18,   468,  1031,    19,  1039,  1039,  1039,  1039,    20,   496,
    1038,   504,  1038,   512,  1038,   520,  1038,   528,  1039,   534,
    1039,    27,   540,  1040,   548,  1036,     4,   140,   429,    10,
      11,   433,   434,   435,     6,     7,   382,  1054,     3,   389,
    1054,   396,  1054,  1055,     6,   401,   128,   129,   408,   409,
     410,   411,   114,   126,  1055,   128,   362,   364,   365,   175,
     568,   569,   570,  1055,  1055,  1055,    10,    11,   455,   456,
     457,     4,   144,   465,     8,    10,    11,   469,   470,   471,
       8,    10,    11,   476,   477,   478,    10,    11,   481,   482,
     483,    10,    11,   486,   487,   488,    10,    11,   491,   492,
     493,     8,    10,    11,   497,   498,   499,    10,    11,   505,
     506,   507,    10,    11,   513,   514,   515,    10,    11,   521,
     522,   523,    10,    11,   529,   530,   531,    10,    11,   535,
     536,   537,     8,    10,    11,   541,   542,   543,    10,    11,
     549,   550,   551,   140,   128,   129,   436,   437,   438,   439,
     132,     8,   134,   136,   138,   128,   410,   412,   413,    10,
      11,   367,    41,    44,    56,    60,   366,   966,   987,   988,
     989,   990,  1018,  1019,  1020,  1021,    86,   205,   707,   708,
      33,   571,   572,  1037,     6,     6,     6,   142,   458,   459,
    1054,   144,     6,   115,   146,   472,   473,     6,   148,   151,
     947,   948,   150,   947,   156,   947,   158,   947,     6,   153,
     164,   500,   501,   949,   950,   166,   508,   509,   949,   170,
     516,   517,   949,   168,   524,   525,   949,   162,   947,   160,
     947,     6,   172,   173,   544,   545,   128,   129,   552,   553,
     554,   555,   128,   438,   440,   441,    10,    11,   415,   414,
     966,   987,  1018,   130,     3,     3,   213,   816,   817,    34,
     709,   710,  1035,  1055,    10,    11,   573,   574,   575,  1055,
    1055,  1055,   142,     8,    10,   146,   473,     8,    10,   148,
     948,   150,   156,   158,     8,   164,   501,   951,   952,   166,
     509,   170,   517,   168,   525,   162,   160,     8,    10,   172,
     545,   128,   554,   556,   557,    10,    11,   443,   442,   966,
     987,  1018,   130,  1055,     8,   221,   925,   926,    35,   818,
     819,  1034,  1055,    10,    11,   711,   712,   713,     6,   177,
     576,   577,   578,     4,     4,    10,    11,   957,    21,    22,
      23,   953,   954,   955,   956,     4,    10,    11,   559,   558,
     966,   987,  1018,   130,    28,   927,  1041,  1055,    10,    11,
     820,   821,   822,     6,   207,   714,   715,   716,  1055,   176,
     181,   591,   592,    37,   579,  1042,   116,   152,   154,     3,
       3,     3,   174,   130,  1055,    10,    11,   928,   929,   930,
       6,   215,   823,   824,   825,  1055,   206,   211,   729,   730,
      38,   717,  1032,   183,   605,   606,   593,  1042,  1055,    10,
      11,   580,   581,   582,     8,     8,     8,     6,   931,  1055,
     214,   219,   838,   839,    39,   826,  1026,   183,   743,   744,
     731,  1032,  1055,    10,    11,   718,   719,   720,   199,   660,
     661,    10,    11,   607,   608,   609,    10,    11,   594,   595,
     596,     6,   178,   179,   583,   584,   585,   586,  1055,   222,
     223,   932,   933,   183,   852,   853,   840,  1026,  1055,    10,
      11,   827,   828,   829,   798,    10,    11,   745,   746,   747,
      10,    11,   732,   733,   734,     6,   208,   209,   721,   722,
     723,   724,   201,   674,   675,   662,  1042,   185,   610,   611,
     612,   179,   182,   597,   598,   599,   600,  1055,   178,   585,
     587,   588,    24,    25,    36,    55,    57,    69,    70,   934,
     935,   936,   958,   959,   960,   961,   966,   987,   995,   996,
     997,   998,  1002,  1003,  1004,  1005,  1018,  1030,   907,    10,
      11,   854,   855,   856,    10,    11,   841,   842,   843,     6,
     216,   217,   830,   831,   832,   833,   129,   799,   800,   185,
     748,   749,   750,   209,   212,   735,   736,   737,   738,  1055,
     208,   723,   725,   726,   689,    29,   676,    10,    11,   663,
     664,   665,   184,   189,   618,   619,    40,   613,  1028,   182,
     599,   601,   602,    10,    11,   590,    42,   589,   976,   977,
     978,   987,  1018,     3,     3,  1055,     3,    10,    11,   937,
     938,   939,   936,   129,   908,   909,   185,   857,   858,   859,
     217,   220,   844,   845,   846,   847,  1055,   216,   832,   834,
     835,   801,   802,   184,   189,   756,   757,   751,  1028,   212,
     737,   739,   740,    10,    11,   728,   727,   976,   987,  1018,
     129,   690,   691,     8,    10,    11,   677,   678,   679,   179,
     200,   666,   667,   668,   669,   187,   625,   626,   620,  1028,
    1055,    10,    11,   614,   615,   616,    10,    11,   604,   603,
     976,   987,  1018,   180,  1055,  1055,     8,     6,  1055,   224,
     227,   228,   230,   940,   941,   942,   943,   944,   945,   910,
     911,   184,   189,   865,   866,   860,  1028,   220,   846,   848,
     849,    10,    11,   837,   836,   976,   987,  1018,    10,    11,
     804,   805,   806,    17,    49,    50,    51,    52,   803,   958,
     966,   970,   971,   972,   973,   987,   991,   992,   993,   994,
     995,  1002,  1018,  1029,  1032,   187,   763,   764,   758,  1028,
      10,    11,   752,   753,   754,    10,    11,   742,    61,    62,
      63,    64,   741,   976,   979,   980,   981,   982,   987,  1006,
    1007,  1008,  1009,   210,   692,   693,     6,   202,   203,   680,
     681,   682,   200,   668,   670,   671,   191,   632,   633,   627,
    1028,    10,    11,   621,   622,   623,     6,   231,   617,  1086,
    1087,  1094,   180,     6,  1055,     5,   946,   224,   942,    10,
      11,   913,   914,   915,    47,    48,   912,   958,   962,   963,
     964,   965,   966,   970,   987,   995,  1002,  1018,  1026,  1029,
     187,   872,   873,   867,  1028,    10,    11,   861,   862,   863,
      10,    11,   851,    65,    66,    67,    68,   850,   976,   983,
     984,   985,   986,   987,  1010,  1011,  1012,  1013,   218,   130,
     209,   225,   807,   808,   809,   810,  1044,  1045,  1046,  1055,
       3,     3,   191,   770,   771,   765,  1028,    10,    11,   759,
     760,   761,   755,  1086,   210,     3,     3,    10,    11,   695,
     696,   697,    53,    54,   694,   958,   966,   970,   987,   995,
    1002,  1018,  1022,  1023,  1024,  1025,  1029,  1042,     8,   202,
     681,   683,   684,    10,    11,   673,   672,   976,   987,  1018,
     195,   639,   640,   634,  1028,    10,    11,   628,   629,   630,
     624,  1086,  1055,   235,  1095,   186,   236,  1088,  1089,  1055,
     229,   130,   217,   916,   917,   918,   919,  1044,     3,   191,
     879,   880,   874,  1028,    10,    11,   868,   869,   870,   864,
    1086,   218,  1055,  1055,   130,   809,   811,   812,  1045,  1047,
    1048,     6,     8,     8,   195,   777,   778,   772,  1028,    10,
      11,   766,   767,   768,   762,  1086,   186,  1055,  1055,   130,
     179,   698,   699,   700,   701,  1044,     3,    10,    11,   686,
     687,   688,    26,    43,   685,   974,   975,   999,  1000,  1001,
    1042,   180,   193,   646,   647,   641,  1028,    10,    11,   635,
     636,   637,   631,  1086,   190,  1055,    10,    11,  1096,  1097,
    1098,  1090,  1091,   130,   918,   920,   921,     8,   195,   886,
     887,   881,  1028,    10,    11,   875,   876,   877,   871,  1086,
     186,  1054,  1054,    10,    11,   814,   815,   813,   976,   979,
     987,  1006,  1018,    10,    11,  1050,  1051,  1052,   966,  1018,
    1028,  1049,  1055,   193,   784,   785,   779,  1028,    10,    11,
     773,   774,   775,   769,  1086,   190,   130,   700,   702,   703,
       8,   204,   667,     8,  1055,   197,   653,   654,   648,  1028,
      10,    11,   642,   643,   644,   638,  1086,   188,     6,     4,
     232,    10,  1093,   233,   234,  1092,  1099,  1100,    10,    11,
     923,   924,   922,   976,   979,   987,  1006,  1018,   193,   893,
     894,   888,  1028,    10,    11,   882,   883,   884,   878,  1086,
     190,  1055,  1055,   210,  1053,  1086,   197,   791,   792,   786,
    1028,    10,    11,   780,   781,   782,   776,  1086,   188,    10,
      11,   705,   706,   704,   976,   979,   987,  1006,  1018,   204,
    1054,     6,   655,  1028,    10,    11,   649,   650,   651,   645,
    1086,   192,  1055,   232,     6,  1055,  1055,   218,   197,   900,
     901,   895,  1028,    10,    11,   889,   890,   891,   885,  1086,
     188,   226,   793,  1028,    10,    11,   787,   788,   789,   783,
    1086,   192,   180,     8,  1055,    10,    11,   656,   657,   658,
     652,  1086,   196,   237,     6,     6,   902,  1028,    10,    11,
     896,   897,   898,   892,  1086,   192,    10,    11,   794,   795,
     796,   790,  1086,   196,   659,  1086,   194,  1055,  1055,    10,
      11,   903,   904,   905,   899,  1086,   196,   797,  1086,   194,
     198,   906,  1086,   194,   198,   198
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


