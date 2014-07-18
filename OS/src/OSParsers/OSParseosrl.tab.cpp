
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
#define yyparse         osrlparse
#define yylex           osrllex
#define yyerror         osrlerror
#define yylval          osrllval
#define yychar          osrlchar
#define yydebug         osrldebug
#define yynerrs         osrlnerrs
#define yylloc          osrllloc

/* Copy the first part of user declarations.  */



 
#include "OSConfig.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSErrorClass.h"
#include "OSResult.h"
#include "OSrLParserData.h"
#include "OSgLParserData.h"
#include "OSnLParserData.h"
#include "OSBase64.h"

#include <iostream>
#include <sstream> 
#include <stdio.h>
#include <cstring>

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
void  yygetOSResult(const char *ch, OSResult* m_osresult, OSrLParserData *m_parserData, OSgLParserData *osglData, OSnLParserData *osnlData ) throw(ErrorClass);
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
     CONTYPEATT = 304,
     EMPTYCONTYPEATT = 305,
     ENUMTYPEATT = 306,
     EMPTYENUMTYPEATT = 307,
     OBJTYPEATT = 308,
     EMPTYOBJTYPEATT = 309,
     VARTYPEATT = 310,
     EMPTYVARTYPEATT = 311,
     UNITATT = 312,
     EMPTYUNITATT = 313,
     VALUEATT = 314,
     EMPTYVALUEATT = 315,
     WEIGHTEDOBJECTIVESATT = 316,
     EMPTYWEIGHTEDOBJECTIVESATT = 317,
     TARGETOBJECTIVENAMEATT = 318,
     EMPTYTARGETOBJECTIVENAMEATT = 319,
     HEADERSTART = 320,
     HEADEREND = 321,
     GENERALSTART = 322,
     GENERALEND = 323,
     SYSTEMSTART = 324,
     SYSTEMEND = 325,
     SERVICESTART = 326,
     SERVICEEND = 327,
     JOBSTART = 328,
     JOBEND = 329,
     OPTIMIZATIONSTART = 330,
     OPTIMIZATIONEND = 331,
     ITEMSTART = 332,
     ITEMEND = 333,
     ITEMSTARTANDEND = 334,
     ITEMEMPTY = 335,
     FILENAMESTART = 336,
     FILENAMEEND = 337,
     FILENAMEEMPTY = 338,
     FILENAMESTARTANDEND = 339,
     FILESOURCESTART = 340,
     FILESOURCEEND = 341,
     FILESOURCEEMPTY = 342,
     FILESOURCESTARTANDEND = 343,
     FILEDESCRIPTIONSTART = 344,
     FILEDESCRIPTIONEND = 345,
     FILEDESCRIPTIONEMPTY = 346,
     FILEDESCRIPTIONSTARTANDEND = 347,
     FILECREATORSTART = 348,
     FILECREATOREND = 349,
     FILECREATOREMPTY = 350,
     FILECREATORSTARTANDEND = 351,
     FILELICENCESTART = 352,
     FILELICENCEEND = 353,
     FILELICENCEEMPTY = 354,
     FILELICENCESTARTANDEND = 355,
     ACTUALSTARTTIMESTART = 356,
     ACTUALSTARTTIMEEND = 357,
     ATEQUALITYSTART = 358,
     ATEQUALITYEND = 359,
     ATLOWERSTART = 360,
     ATLOWEREND = 361,
     ATUPPERSTART = 362,
     ATUPPEREND = 363,
     AVAILABLECPUNUMBERSTART = 364,
     AVAILABLECPUNUMBEREND = 365,
     AVAILABLECPUSPEEDSTART = 366,
     AVAILABLECPUSPEEDEND = 367,
     AVAILABLEDISKSPACESTART = 368,
     AVAILABLEDISKSPACEEND = 369,
     AVAILABLEMEMORYSTART = 370,
     AVAILABLEMEMORYEND = 371,
     BASE64START = 372,
     BASE64END = 373,
     BASICSTART = 374,
     BASICEND = 375,
     BASISSTATUSSTART = 376,
     BASISSTATUSEND = 377,
     BASSTATUSSTART = 378,
     BASSTATUSEND = 379,
     CONSTART = 380,
     CONEND = 381,
     CONSTRAINTSSTART = 382,
     CONSTRAINTSEND = 383,
     CURRENTJOBCOUNTSTART = 384,
     CURRENTJOBCOUNTEND = 385,
     CURRENTSTATESTART = 386,
     CURRENTSTATEEND = 387,
     DUALVALUESSTART = 388,
     DUALVALUESEND = 389,
     ELSTART = 390,
     ELEND = 391,
     ENUMERATIONSTART = 392,
     ENUMERATIONEND = 393,
     ENDTIMESTART = 394,
     ENDTIMEEND = 395,
     GENERALSTATUSSTART = 396,
     GENERALSTATUSEND = 397,
     GENERALSUBSTATUSSTART = 398,
     GENERALSUBSTATUSEND = 399,
     IDXSTART = 400,
     IDXEND = 401,
     INSTANCENAMESTART = 402,
     INSTANCENAMEEND = 403,
     ISFREESTART = 404,
     ISFREEEND = 405,
     JOBIDSTART = 406,
     JOBIDEND = 407,
     MESSAGESTART = 408,
     MESSAGEEND = 409,
     OBJSTART = 410,
     OBJEND = 411,
     OBJECTIVESSTART = 412,
     OBJECTIVESEND = 413,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 414,
     OPTIMIZATIONSOLUTIONSTATUSEND = 415,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 416,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 417,
     OTHERSTART = 418,
     OTHEREND = 419,
     OTHERRESULTSSTART = 420,
     OTHERRESULTSEND = 421,
     OTHERSOLUTIONRESULTSTART = 422,
     OTHERSOLUTIONRESULTEND = 423,
     OTHERSOLUTIONRESULTSSTART = 424,
     OTHERSOLUTIONRESULTSEND = 425,
     OTHERSOLVEROUTPUTSTART = 426,
     OTHERSOLVEROUTPUTEND = 427,
     SCHEDULEDSTARTTIMESTART = 428,
     SCHEDULEDSTARTTIMEEND = 429,
     SERVICENAMESTART = 430,
     SERVICENAMEEND = 431,
     SERVICEURISTART = 432,
     SERVICEURIEND = 433,
     SERVICEUTILIZATIONSTART = 434,
     SERVICEUTILIZATIONEND = 435,
     SOLUTIONSTART = 436,
     SOLUTIONEND = 437,
     SOLVERINVOKEDSTART = 438,
     SOLVERINVOKEDEND = 439,
     SOLVEROUTPUTSTART = 440,
     SOLVEROUTPUTEND = 441,
     STATUSSTART = 442,
     STATUSEND = 443,
     SUBMITTIMESTART = 444,
     SUBMITTIMEEND = 445,
     SUBSTATUSSTART = 446,
     SUBSTATUSEND = 447,
     SUPERBASICSTART = 448,
     SUPERBASICEND = 449,
     SYSTEMINFORMATIONSTART = 450,
     SYSTEMINFORMATIONEND = 451,
     TIMESTART = 452,
     TIMEEND = 453,
     TIMESERVICESTARTEDSTART = 454,
     TIMESERVICESTARTEDEND = 455,
     TIMESTAMPSTART = 456,
     TIMESTAMPEND = 457,
     TIMINGINFORMATIONSTART = 458,
     TIMINGINFORMATIONEND = 459,
     TOTALJOBSSOFARSTART = 460,
     TOTALJOBSSOFAREND = 461,
     UNKNOWNSTART = 462,
     UNKNOWNEND = 463,
     USEDCPUNUMBERSTART = 464,
     USEDCPUNUMBEREND = 465,
     USEDCPUSPEEDSTART = 466,
     USEDCPUSPEEDEND = 467,
     USEDDISKSPACESTART = 468,
     USEDDISKSPACEEND = 469,
     USEDMEMORYSTART = 470,
     USEDMEMORYEND = 471,
     VALUESSTRINGSTART = 472,
     VALUESSTRINGEND = 473,
     VARSTART = 474,
     VAREND = 475,
     VARIABLESSTART = 476,
     VARIABLESEND = 477,
     VARIDXSTART = 478,
     VARIDXEND = 479,
     MATRIXSTART = 480,
     MATRIXEND = 481,
     BASEMATRIXEND = 482,
     BASEMATRIXSTART = 483,
     BLOCKSTART = 484,
     BLOCKEND = 485,
     BLOCKSSTART = 486,
     BLOCKSEND = 487,
     EMPTYSYMMETRYATT = 488,
     SYMMETRYATT = 489,
     EMPTYEXCLUDEATT = 490,
     EXCLUDEATT = 491,
     NUMBEROFBLOCKSATT = 492,
     NUMBEROFCOLUMNSATT = 493,
     NUMBEROFROWSATT = 494,
     BASEMATRIXIDXATT = 495,
     TARGETMATRIXFIRSTROWATT = 496,
     TARGETMATRIXFIRSTCOLATT = 497,
     BASEMATRIXSTARTROWATT = 498,
     BASEMATRIXSTARTCOLATT = 499,
     BASEMATRIXENDROWATT = 500,
     BASEMATRIXENDCOLATT = 501,
     SCALARMULTIPLIERATT = 502,
     EMPTYBASETRANSPOSEATT = 503,
     BASETRANSPOSEATT = 504,
     ELEMENTSSTART = 505,
     ELEMENTSEND = 506,
     CONSTANTELEMENTSSTART = 507,
     CONSTANTELEMENTSEND = 508,
     STARTVECTORSTART = 509,
     STARTVECTOREND = 510,
     NONZEROSSTART = 511,
     NONZEROSEND = 512,
     INDEXESSTART = 513,
     INDEXESEND = 514,
     VALUESSTART = 515,
     VALUESEND = 516,
     VARREFERENCEELEMENTSSTART = 517,
     VARREFERENCEELEMENTSEND = 518,
     LINEARELEMENTSSTART = 519,
     LINEARELEMENTSEND = 520,
     GENERALELEMENTSSTART = 521,
     GENERALELEMENTSEND = 522,
     CONREFERENCEELEMENTSSTART = 523,
     CONREFERENCEELEMENTSEND = 524,
     OBJREFERENCEELEMENTSSTART = 525,
     OBJREFERENCEELEMENTSEND = 526,
     PATTERNELEMENTSSTART = 527,
     PATTERNELEMENTSEND = 528,
     COLOFFSETSSTART = 529,
     COLOFFSETSEND = 530,
     ROWOFFSETSSTART = 531,
     ROWOFFSETSEND = 532,
     EMPTYROWMAJORATT = 533,
     ROWMAJORATT = 534,
     BLOCKROWIDXATT = 535,
     BLOCKCOLIDXATT = 536,
     DUMMY = 537,
     NONLINEAREXPRESSIONSSTART = 538,
     NONLINEAREXPRESSIONSEND = 539,
     NUMBEROFNONLINEAREXPRESSIONS = 540,
     NLSTART = 541,
     NLEND = 542,
     POWERSTART = 543,
     POWEREND = 544,
     PLUSSTART = 545,
     PLUSEND = 546,
     MINUSSTART = 547,
     MINUSEND = 548,
     DIVIDESTART = 549,
     DIVIDEEND = 550,
     LNSTART = 551,
     LNEND = 552,
     SQRTSTART = 553,
     SQRTEND = 554,
     SUMSTART = 555,
     SUMEND = 556,
     PRODUCTSTART = 557,
     PRODUCTEND = 558,
     EXPSTART = 559,
     EXPEND = 560,
     NEGATESTART = 561,
     NEGATEEND = 562,
     IFSTART = 563,
     IFEND = 564,
     SQUARESTART = 565,
     SQUAREEND = 566,
     COSSTART = 567,
     COSEND = 568,
     SINSTART = 569,
     SINEND = 570,
     VARIABLESTART = 571,
     VARIABLEEND = 572,
     ABSSTART = 573,
     ABSEND = 574,
     ERFSTART = 575,
     ERFEND = 576,
     MAXSTART = 577,
     MAXEND = 578,
     ALLDIFFSTART = 579,
     ALLDIFFEND = 580,
     MINSTART = 581,
     MINEND = 582,
     ESTART = 583,
     EEND = 584,
     PISTART = 585,
     PIEND = 586,
     TIMESSTART = 587,
     TIMESEND = 588,
     NUMBERSTART = 589,
     NUMBEREND = 590,
     IDATT = 591,
     COEFATT = 592
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
#define CONTYPEATT 304
#define EMPTYCONTYPEATT 305
#define ENUMTYPEATT 306
#define EMPTYENUMTYPEATT 307
#define OBJTYPEATT 308
#define EMPTYOBJTYPEATT 309
#define VARTYPEATT 310
#define EMPTYVARTYPEATT 311
#define UNITATT 312
#define EMPTYUNITATT 313
#define VALUEATT 314
#define EMPTYVALUEATT 315
#define WEIGHTEDOBJECTIVESATT 316
#define EMPTYWEIGHTEDOBJECTIVESATT 317
#define TARGETOBJECTIVENAMEATT 318
#define EMPTYTARGETOBJECTIVENAMEATT 319
#define HEADERSTART 320
#define HEADEREND 321
#define GENERALSTART 322
#define GENERALEND 323
#define SYSTEMSTART 324
#define SYSTEMEND 325
#define SERVICESTART 326
#define SERVICEEND 327
#define JOBSTART 328
#define JOBEND 329
#define OPTIMIZATIONSTART 330
#define OPTIMIZATIONEND 331
#define ITEMSTART 332
#define ITEMEND 333
#define ITEMSTARTANDEND 334
#define ITEMEMPTY 335
#define FILENAMESTART 336
#define FILENAMEEND 337
#define FILENAMEEMPTY 338
#define FILENAMESTARTANDEND 339
#define FILESOURCESTART 340
#define FILESOURCEEND 341
#define FILESOURCEEMPTY 342
#define FILESOURCESTARTANDEND 343
#define FILEDESCRIPTIONSTART 344
#define FILEDESCRIPTIONEND 345
#define FILEDESCRIPTIONEMPTY 346
#define FILEDESCRIPTIONSTARTANDEND 347
#define FILECREATORSTART 348
#define FILECREATOREND 349
#define FILECREATOREMPTY 350
#define FILECREATORSTARTANDEND 351
#define FILELICENCESTART 352
#define FILELICENCEEND 353
#define FILELICENCEEMPTY 354
#define FILELICENCESTARTANDEND 355
#define ACTUALSTARTTIMESTART 356
#define ACTUALSTARTTIMEEND 357
#define ATEQUALITYSTART 358
#define ATEQUALITYEND 359
#define ATLOWERSTART 360
#define ATLOWEREND 361
#define ATUPPERSTART 362
#define ATUPPEREND 363
#define AVAILABLECPUNUMBERSTART 364
#define AVAILABLECPUNUMBEREND 365
#define AVAILABLECPUSPEEDSTART 366
#define AVAILABLECPUSPEEDEND 367
#define AVAILABLEDISKSPACESTART 368
#define AVAILABLEDISKSPACEEND 369
#define AVAILABLEMEMORYSTART 370
#define AVAILABLEMEMORYEND 371
#define BASE64START 372
#define BASE64END 373
#define BASICSTART 374
#define BASICEND 375
#define BASISSTATUSSTART 376
#define BASISSTATUSEND 377
#define BASSTATUSSTART 378
#define BASSTATUSEND 379
#define CONSTART 380
#define CONEND 381
#define CONSTRAINTSSTART 382
#define CONSTRAINTSEND 383
#define CURRENTJOBCOUNTSTART 384
#define CURRENTJOBCOUNTEND 385
#define CURRENTSTATESTART 386
#define CURRENTSTATEEND 387
#define DUALVALUESSTART 388
#define DUALVALUESEND 389
#define ELSTART 390
#define ELEND 391
#define ENUMERATIONSTART 392
#define ENUMERATIONEND 393
#define ENDTIMESTART 394
#define ENDTIMEEND 395
#define GENERALSTATUSSTART 396
#define GENERALSTATUSEND 397
#define GENERALSUBSTATUSSTART 398
#define GENERALSUBSTATUSEND 399
#define IDXSTART 400
#define IDXEND 401
#define INSTANCENAMESTART 402
#define INSTANCENAMEEND 403
#define ISFREESTART 404
#define ISFREEEND 405
#define JOBIDSTART 406
#define JOBIDEND 407
#define MESSAGESTART 408
#define MESSAGEEND 409
#define OBJSTART 410
#define OBJEND 411
#define OBJECTIVESSTART 412
#define OBJECTIVESEND 413
#define OPTIMIZATIONSOLUTIONSTATUSSTART 414
#define OPTIMIZATIONSOLUTIONSTATUSEND 415
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 416
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 417
#define OTHERSTART 418
#define OTHEREND 419
#define OTHERRESULTSSTART 420
#define OTHERRESULTSEND 421
#define OTHERSOLUTIONRESULTSTART 422
#define OTHERSOLUTIONRESULTEND 423
#define OTHERSOLUTIONRESULTSSTART 424
#define OTHERSOLUTIONRESULTSEND 425
#define OTHERSOLVEROUTPUTSTART 426
#define OTHERSOLVEROUTPUTEND 427
#define SCHEDULEDSTARTTIMESTART 428
#define SCHEDULEDSTARTTIMEEND 429
#define SERVICENAMESTART 430
#define SERVICENAMEEND 431
#define SERVICEURISTART 432
#define SERVICEURIEND 433
#define SERVICEUTILIZATIONSTART 434
#define SERVICEUTILIZATIONEND 435
#define SOLUTIONSTART 436
#define SOLUTIONEND 437
#define SOLVERINVOKEDSTART 438
#define SOLVERINVOKEDEND 439
#define SOLVEROUTPUTSTART 440
#define SOLVEROUTPUTEND 441
#define STATUSSTART 442
#define STATUSEND 443
#define SUBMITTIMESTART 444
#define SUBMITTIMEEND 445
#define SUBSTATUSSTART 446
#define SUBSTATUSEND 447
#define SUPERBASICSTART 448
#define SUPERBASICEND 449
#define SYSTEMINFORMATIONSTART 450
#define SYSTEMINFORMATIONEND 451
#define TIMESTART 452
#define TIMEEND 453
#define TIMESERVICESTARTEDSTART 454
#define TIMESERVICESTARTEDEND 455
#define TIMESTAMPSTART 456
#define TIMESTAMPEND 457
#define TIMINGINFORMATIONSTART 458
#define TIMINGINFORMATIONEND 459
#define TOTALJOBSSOFARSTART 460
#define TOTALJOBSSOFAREND 461
#define UNKNOWNSTART 462
#define UNKNOWNEND 463
#define USEDCPUNUMBERSTART 464
#define USEDCPUNUMBEREND 465
#define USEDCPUSPEEDSTART 466
#define USEDCPUSPEEDEND 467
#define USEDDISKSPACESTART 468
#define USEDDISKSPACEEND 469
#define USEDMEMORYSTART 470
#define USEDMEMORYEND 471
#define VALUESSTRINGSTART 472
#define VALUESSTRINGEND 473
#define VARSTART 474
#define VAREND 475
#define VARIABLESSTART 476
#define VARIABLESEND 477
#define VARIDXSTART 478
#define VARIDXEND 479
#define MATRIXSTART 480
#define MATRIXEND 481
#define BASEMATRIXEND 482
#define BASEMATRIXSTART 483
#define BLOCKSTART 484
#define BLOCKEND 485
#define BLOCKSSTART 486
#define BLOCKSEND 487
#define EMPTYSYMMETRYATT 488
#define SYMMETRYATT 489
#define EMPTYEXCLUDEATT 490
#define EXCLUDEATT 491
#define NUMBEROFBLOCKSATT 492
#define NUMBEROFCOLUMNSATT 493
#define NUMBEROFROWSATT 494
#define BASEMATRIXIDXATT 495
#define TARGETMATRIXFIRSTROWATT 496
#define TARGETMATRIXFIRSTCOLATT 497
#define BASEMATRIXSTARTROWATT 498
#define BASEMATRIXSTARTCOLATT 499
#define BASEMATRIXENDROWATT 500
#define BASEMATRIXENDCOLATT 501
#define SCALARMULTIPLIERATT 502
#define EMPTYBASETRANSPOSEATT 503
#define BASETRANSPOSEATT 504
#define ELEMENTSSTART 505
#define ELEMENTSEND 506
#define CONSTANTELEMENTSSTART 507
#define CONSTANTELEMENTSEND 508
#define STARTVECTORSTART 509
#define STARTVECTOREND 510
#define NONZEROSSTART 511
#define NONZEROSEND 512
#define INDEXESSTART 513
#define INDEXESEND 514
#define VALUESSTART 515
#define VALUESEND 516
#define VARREFERENCEELEMENTSSTART 517
#define VARREFERENCEELEMENTSEND 518
#define LINEARELEMENTSSTART 519
#define LINEARELEMENTSEND 520
#define GENERALELEMENTSSTART 521
#define GENERALELEMENTSEND 522
#define CONREFERENCEELEMENTSSTART 523
#define CONREFERENCEELEMENTSEND 524
#define OBJREFERENCEELEMENTSSTART 525
#define OBJREFERENCEELEMENTSEND 526
#define PATTERNELEMENTSSTART 527
#define PATTERNELEMENTSEND 528
#define COLOFFSETSSTART 529
#define COLOFFSETSEND 530
#define ROWOFFSETSSTART 531
#define ROWOFFSETSEND 532
#define EMPTYROWMAJORATT 533
#define ROWMAJORATT 534
#define BLOCKROWIDXATT 535
#define BLOCKCOLIDXATT 536
#define DUMMY 537
#define NONLINEAREXPRESSIONSSTART 538
#define NONLINEAREXPRESSIONSEND 539
#define NUMBEROFNONLINEAREXPRESSIONS 540
#define NLSTART 541
#define NLEND 542
#define POWERSTART 543
#define POWEREND 544
#define PLUSSTART 545
#define PLUSEND 546
#define MINUSSTART 547
#define MINUSEND 548
#define DIVIDESTART 549
#define DIVIDEEND 550
#define LNSTART 551
#define LNEND 552
#define SQRTSTART 553
#define SQRTEND 554
#define SUMSTART 555
#define SUMEND 556
#define PRODUCTSTART 557
#define PRODUCTEND 558
#define EXPSTART 559
#define EXPEND 560
#define NEGATESTART 561
#define NEGATEEND 562
#define IFSTART 563
#define IFEND 564
#define SQUARESTART 565
#define SQUAREEND 566
#define COSSTART 567
#define COSEND 568
#define SINSTART 569
#define SINEND 570
#define VARIABLESTART 571
#define VARIABLEEND 572
#define ABSSTART 573
#define ABSEND 574
#define ERFSTART 575
#define ERFEND 576
#define MAXSTART 577
#define MAXEND 578
#define ALLDIFFSTART 579
#define ALLDIFFEND 580
#define MINSTART 581
#define MINEND 582
#define ESTART 583
#define EEND 584
#define PISTART 585
#define PIEND 586
#define TIMESSTART 587
#define TIMESEND 588
#define NUMBERSTART 589
#define NUMBEREND 590
#define IDATT 591
#define COEFATT 592




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


std::string addErrorMsg(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg ) ;
void osrlerror(YYLTYPE* type, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData* osnlData, std::string errormsg);
int osrllex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
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
#define YYLAST   1388

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  342
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  815
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1211
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1628

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   592

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   339,
     341,     2,     2,   340,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   338,     2,     2,     2,     2,     2,     2,     2,
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
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    16,    18,    20,
      22,    24,    28,    30,    32,    33,    40,    41,    43,    44,
      47,    49,    51,    53,    56,    58,    62,    64,    66,    69,
      71,    73,    75,    77,    79,    81,    83,    85,    87,    91,
      93,    95,    97,   100,   102,   104,   106,   108,   110,   113,
     115,   119,   121,   123,   126,   130,   132,   134,   135,   138,
     140,   142,   145,   147,   150,   152,   154,   156,   159,   161,
     165,   167,   170,   172,   174,   176,   179,   181,   185,   187,
     190,   192,   194,   196,   199,   201,   205,   207,   210,   212,
     214,   216,   219,   221,   225,   227,   230,   232,   234,   236,
     239,   241,   245,   247,   250,   252,   254,   256,   259,   261,
     265,   267,   270,   272,   274,   276,   279,   281,   285,   287,
     291,   293,   295,   297,   299,   302,   304,   308,   310,   312,
     315,   319,   321,   323,   324,   327,   329,   331,   333,   336,
     338,   339,   342,   344,   346,   348,   351,   353,   357,   359,
     361,   364,   366,   368,   370,   372,   374,   376,   379,   381,
     383,   385,   388,   390,   394,   396,   400,   402,   404,   405,
     408,   410,   412,   416,   418,   422,   424,   426,   427,   430,
     432,   434,   438,   440,   444,   446,   448,   449,   452,   454,
     456,   460,   462,   466,   468,   469,   471,   475,   477,   481,
     483,   485,   487,   489,   492,   494,   498,   500,   502,   505,
     509,   511,   513,   514,   517,   519,   521,   523,   526,   528,
     529,   532,   534,   536,   538,   541,   543,   547,   549,   551,
     554,   556,   558,   560,   562,   564,   566,   569,   571,   573,
     575,   578,   580,   584,   586,   589,   591,   593,   595,   598,
     600,   604,   606,   609,   611,   613,   615,   618,   620,   624,
     626,   629,   631,   633,   635,   638,   640,   644,   646,   649,
     651,   653,   655,   658,   660,   664,   666,   670,   672,   674,
     676,   678,   681,   683,   687,   689,   691,   694,   698,   700,
     702,   703,   706,   708,   710,   712,   715,   717,   718,   721,
     723,   725,   727,   730,   732,   736,   738,   740,   743,   745,
     747,   749,   751,   753,   755,   757,   759,   761,   763,   765,
     768,   770,   772,   774,   777,   779,   783,   785,   788,   790,
     792,   794,   797,   799,   803,   805,   808,   810,   812,   814,
     817,   819,   823,   825,   828,   830,   832,   834,   837,   839,
     843,   845,   848,   850,   852,   854,   857,   859,   863,   865,
     869,   871,   873,   875,   877,   880,   882,   886,   888,   890,
     893,   897,   899,   900,   903,   905,   907,   909,   911,   913,
     915,   918,   920,   924,   926,   928,   930,   934,   936,   938,
     939,   942,   944,   946,   950,   952,   956,   958,   960,   961,
     964,   966,   968,   972,   974,   978,   980,   982,   983,   986,
     988,   990,   994,   996,  1000,  1002,  1003,  1005,  1009,  1011,
    1015,  1017,  1019,  1021,  1023,  1026,  1028,  1032,  1034,  1036,
    1039,  1043,  1045,  1047,  1048,  1051,  1053,  1055,  1057,  1060,
    1062,  1063,  1067,  1069,  1071,  1072,  1075,  1077,  1079,  1081,
    1083,  1085,  1087,  1090,  1092,  1096,  1099,  1101,  1104,  1108,
    1110,  1112,  1113,  1116,  1118,  1120,  1122,  1127,  1131,  1135,
    1144,  1148,  1150,  1152,  1154,  1157,  1159,  1161,  1163,  1165,
    1167,  1170,  1172,  1176,  1178,  1180,  1183,  1187,  1189,  1191,
    1192,  1195,  1197,  1199,  1202,  1204,  1205,  1208,  1210,  1212,
    1214,  1217,  1219,  1223,  1225,  1226,  1230,  1232,  1233,  1235,
    1237,  1239,  1241,  1245,  1250,  1251,  1255,  1257,  1259,  1261,
    1263,  1266,  1268,  1272,  1274,  1276,  1279,  1283,  1285,  1286,
    1289,  1291,  1293,  1297,  1298,  1302,  1304,  1306,  1308,  1310,
    1313,  1315,  1319,  1321,  1323,  1326,  1330,  1332,  1333,  1336,
    1338,  1340,  1342,  1344,  1347,  1349,  1353,  1355,  1356,  1359,
    1361,  1363,  1365,  1367,  1371,  1379,  1380,  1384,  1386,  1388,
    1390,  1392,  1394,  1398,  1400,  1401,  1405,  1407,  1409,  1411,
    1413,  1415,  1419,  1421,  1422,  1426,  1428,  1430,  1432,  1434,
    1436,  1440,  1442,  1443,  1447,  1449,  1451,  1453,  1455,  1457,
    1461,  1463,  1464,  1468,  1470,  1472,  1474,  1476,  1478,  1482,
    1484,  1485,  1489,  1491,  1493,  1495,  1497,  1499,  1503,  1505,
    1506,  1510,  1512,  1514,  1516,  1518,  1520,  1524,  1526,  1527,
    1530,  1534,  1536,  1538,  1539,  1542,  1544,  1546,  1548,  1550,
    1552,  1554,  1556,  1558,  1560,  1562,  1565,  1567,  1571,  1573,
    1575,  1577,  1580,  1584,  1586,  1587,  1590,  1592,  1594,  1596,
    1598,  1601,  1603,  1607,  1609,  1611,  1614,  1618,  1620,  1622,
    1623,  1626,  1628,  1630,  1632,  1634,  1636,  1638,  1642,  1644,
    1645,  1649,  1651,  1652,  1654,  1656,  1658,  1660,  1664,  1668,
    1669,  1673,  1675,  1677,  1679,  1681,  1684,  1686,  1690,  1692,
    1694,  1697,  1701,  1703,  1704,  1707,  1709,  1711,  1715,  1716,
    1719,  1721,  1723,  1725,  1727,  1731,  1739,  1740,  1744,  1746,
    1748,  1750,  1752,  1754,  1758,  1760,  1761,  1765,  1767,  1769,
    1771,  1773,  1775,  1779,  1781,  1782,  1786,  1788,  1790,  1792,
    1794,  1796,  1800,  1802,  1803,  1807,  1809,  1811,  1813,  1815,
    1817,  1821,  1823,  1824,  1828,  1830,  1832,  1834,  1836,  1838,
    1842,  1844,  1845,  1849,  1851,  1853,  1855,  1857,  1859,  1863,
    1865,  1866,  1870,  1872,  1874,  1876,  1878,  1880,  1884,  1886,
    1887,  1890,  1894,  1896,  1898,  1899,  1902,  1904,  1906,  1908,
    1910,  1912,  1914,  1916,  1918,  1920,  1922,  1925,  1927,  1931,
    1933,  1935,  1937,  1940,  1944,  1946,  1947,  1950,  1952,  1954,
    1956,  1958,  1961,  1963,  1967,  1969,  1971,  1974,  1978,  1980,
    1982,  1983,  1986,  1988,  1990,  1992,  1994,  1996,  1998,  2002,
    2004,  2005,  2009,  2011,  2012,  2014,  2016,  2018,  2020,  2024,
    2028,  2029,  2033,  2035,  2037,  2039,  2041,  2044,  2046,  2050,
    2052,  2054,  2057,  2061,  2063,  2064,  2067,  2069,  2071,  2075,
    2076,  2079,  2081,  2083,  2085,  2087,  2091,  2099,  2100,  2104,
    2106,  2108,  2110,  2112,  2114,  2118,  2120,  2121,  2125,  2127,
    2129,  2131,  2133,  2135,  2139,  2141,  2142,  2146,  2148,  2150,
    2152,  2154,  2156,  2160,  2162,  2163,  2167,  2169,  2171,  2173,
    2175,  2177,  2181,  2183,  2184,  2188,  2190,  2192,  2194,  2196,
    2198,  2202,  2204,  2205,  2209,  2211,  2213,  2215,  2217,  2219,
    2223,  2225,  2226,  2230,  2232,  2234,  2236,  2238,  2240,  2244,
    2246,  2247,  2250,  2254,  2256,  2258,  2259,  2262,  2264,  2266,
    2268,  2270,  2272,  2274,  2276,  2278,  2280,  2282,  2285,  2287,
    2291,  2293,  2295,  2297,  2300,  2304,  2306,  2307,  2310,  2312,
    2314,  2316,  2318,  2321,  2323,  2327,  2329,  2331,  2334,  2338,
    2340,  2342,  2343,  2346,  2348,  2350,  2352,  2354,  2356,  2358,
    2362,  2364,  2365,  2369,  2371,  2373,  2375,  2377,  2380,  2382,
    2386,  2388,  2390,  2393,  2397,  2399,  2401,  2402,  2405,  2407,
    2409,  2411,  2413,  2415,  2417,  2419,  2422,  2424,  2428,  2430,
    2432,  2435,  2437,  2439,  2441,  2443,  2445,  2449,  2451,  2452,
    2456,  2458,  2460,  2462,  2464,  2467,  2469,  2473,  2475,  2477,
    2480,  2484,  2486,  2488,  2489,  2492,  2494,  2496,  2498,  2500,
    2502,  2504,  2507,  2509,  2513,  2515,  2517,  2520,  2522,  2524,
    2526,  2528,  2530,  2534,  2536,  2538,  2540,  2542,  2544,  2548,
    2550,  2552,  2554,  2556,  2560,  2562,  2564,  2566,  2568,  2572,
    2574,  2576,  2578,  2580,  2584,  2589,  2591,  2593,  2595,  2597,
    2601,  2603,  2605,  2607,  2609,  2613,  2615,  2617,  2619,  2621,
    2625,  2627,  2629,  2631,  2633,  2637,  2639,  2641,  2643,  2645,
    2649,  2651,  2653,  2655,  2657,  2661,  2666,  2671,  2676,  2681,
    2686,  2691,  2696,  2701,  2706,  2711,  2716,  2721,  2726,  2731,
    2736,  2741,  2746,  2751,  2753,  2755,  2757,  2759,  2761,  2764,
    2765,  2768,  2770,  2772,  2774,  2776,  2779,  2781,  2783,  2785,
    2788,  2790,  2794,  2796,  2798,  2801,  2803,  2805,  2807,  2809,
    2811,  2812,  2814,  2816,  2818,  2820,  2822,  2826,  2827,  2829,
    2831,  2833,  2835,  2837,  2841,  2842,  2844,  2846,  2848,  2850,
    2852,  2856,  2857,  2859,  2861,  2863,  2865,  2867,  2871,  2872,
    2874,  2876,  2878,  2880,  2882,  2886,  2888,  2890,  2891,  2894,
    2898,  2900,  2902,  2903,  2906,  2908,  2910,  2914,  2918,  2923,
    2925,  2927,  2930,  2932,  2936,  2941,  2946,  2951,  2953,  2955,
    2958,  2960
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     343,     0,    -1,   344,   352,   350,    -1,   345,   346,   347,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   348,    -1,
     349,    -1,    11,    -1,    10,   352,   350,    -1,   351,    -1,
      15,    -1,    -1,   353,   354,   434,   488,   540,   635,    -1,
      -1,  1114,    -1,    -1,   355,   356,    -1,    67,    -1,   357,
      -1,   358,    -1,    10,    68,    -1,    11,    -1,    10,   359,
      68,    -1,   360,    -1,   361,    -1,   360,   361,    -1,   362,
      -1,   378,    -1,   384,    -1,   390,    -1,   396,    -1,   402,
      -1,   408,    -1,   414,    -1,   420,    -1,   363,   364,   367,
      -1,   141,    -1,   365,    -1,   366,    -1,   365,   366,    -1,
    1075,    -1,  1058,    -1,  1105,    -1,   368,    -1,   369,    -1,
      10,   142,    -1,    11,    -1,    10,   370,   142,    -1,   371,
      -1,   372,    -1,   371,   372,    -1,   373,   374,   377,    -1,
     191,    -1,   375,    -1,    -1,   375,   376,    -1,  1067,    -1,
    1058,    -1,    10,   192,    -1,    11,    -1,   379,   380,    -1,
     153,    -1,   381,    -1,   382,    -1,    10,   154,    -1,    11,
      -1,    10,   383,   154,    -1,     4,    -1,   385,   386,    -1,
     177,    -1,   387,    -1,   388,    -1,    10,   178,    -1,    11,
      -1,    10,   389,   178,    -1,     4,    -1,   391,   392,    -1,
     175,    -1,   393,    -1,   394,    -1,    10,   176,    -1,    11,
      -1,    10,   395,   176,    -1,     4,    -1,   397,   398,    -1,
     147,    -1,   399,    -1,   400,    -1,    10,   148,    -1,    11,
      -1,    10,   401,   148,    -1,     4,    -1,   403,   404,    -1,
     151,    -1,   405,    -1,   406,    -1,    10,   152,    -1,    11,
      -1,    10,   407,   152,    -1,     4,    -1,   409,   410,    -1,
     183,    -1,   411,    -1,   412,    -1,    10,   184,    -1,    11,
      -1,    10,   413,   184,    -1,     4,    -1,   415,   416,    -1,
     201,    -1,   417,    -1,   418,    -1,    10,   202,    -1,    11,
      -1,    10,   419,   202,    -1,     4,    -1,   421,   422,   423,
      -1,   165,    -1,  1100,    -1,   424,    -1,   425,    -1,    10,
     166,    -1,    11,    -1,    10,   426,   166,    -1,   427,    -1,
     428,    -1,   427,   428,    -1,   429,   430,   433,    -1,   163,
      -1,   431,    -1,    -1,   431,   432,    -1,  1067,    -1,  1083,
      -1,  1058,    -1,    10,   164,    -1,    11,    -1,    -1,   435,
     436,    -1,    69,    -1,   437,    -1,   438,    -1,    10,    70,
      -1,    11,    -1,    10,   439,    70,    -1,   440,    -1,   441,
      -1,   440,   441,    -1,   442,    -1,   448,    -1,   455,    -1,
     462,    -1,   469,    -1,   474,    -1,   443,   444,    -1,   195,
      -1,   445,    -1,   446,    -1,    10,   196,    -1,    11,    -1,
      10,   447,   196,    -1,     4,    -1,   449,   450,   453,    -1,
     113,    -1,   451,    -1,    -1,   451,   452,    -1,  1079,    -1,
    1058,    -1,    10,   454,   114,    -1,  1109,    -1,   456,   457,
     460,    -1,   115,    -1,   458,    -1,    -1,   458,   459,    -1,
    1079,    -1,  1058,    -1,    10,   461,   116,    -1,  1109,    -1,
     463,   464,   467,    -1,   111,    -1,   465,    -1,    -1,   465,
     466,    -1,  1079,    -1,  1058,    -1,    10,   468,   112,    -1,
    1109,    -1,   470,   471,   472,    -1,   109,    -1,    -1,  1058,
      -1,    10,   473,   110,    -1,     6,    -1,   475,   476,   477,
      -1,   165,    -1,  1100,    -1,   478,    -1,   479,    -1,    10,
     166,    -1,    11,    -1,    10,   480,   166,    -1,   481,    -1,
     482,    -1,   481,   482,    -1,   483,   484,   487,    -1,   163,
      -1,   485,    -1,    -1,   485,   486,    -1,  1067,    -1,  1083,
      -1,  1058,    -1,    10,   164,    -1,    11,    -1,    -1,   489,
     490,    -1,    71,    -1,   491,    -1,   492,    -1,    10,    72,
      -1,    11,    -1,    10,   493,    72,    -1,   494,    -1,   495,
      -1,   494,   495,    -1,   496,    -1,   502,    -1,   508,    -1,
     514,    -1,   520,    -1,   526,    -1,   497,   498,    -1,   131,
      -1,   499,    -1,   500,    -1,    10,   132,    -1,    11,    -1,
      10,   501,   132,    -1,     4,    -1,   503,   504,    -1,   129,
      -1,   505,    -1,   506,    -1,    10,   130,    -1,    11,    -1,
      10,   507,   130,    -1,     6,    -1,   509,   510,    -1,   205,
      -1,   511,    -1,   512,    -1,    10,   206,    -1,    11,    -1,
      10,   513,   206,    -1,     6,    -1,   515,   516,    -1,   199,
      -1,   517,    -1,   518,    -1,    10,   200,    -1,    11,    -1,
      10,   519,   200,    -1,     4,    -1,   521,   522,    -1,   179,
      -1,   523,    -1,   524,    -1,    10,   180,    -1,    11,    -1,
      10,   525,   180,    -1,  1109,    -1,   527,   528,   529,    -1,
     165,    -1,  1100,    -1,   530,    -1,   531,    -1,    10,   166,
      -1,    11,    -1,    10,   532,   166,    -1,   533,    -1,   534,
      -1,   533,   534,    -1,   535,   536,   539,    -1,   163,    -1,
     537,    -1,    -1,   537,   538,    -1,  1067,    -1,  1083,    -1,
    1058,    -1,    10,   164,    -1,    11,    -1,    -1,   541,   542,
      -1,    73,    -1,   543,    -1,   544,    -1,    10,    74,    -1,
      11,    -1,    10,   545,    74,    -1,   546,    -1,   547,    -1,
     546,   547,    -1,   548,    -1,   554,    -1,   560,    -1,   566,
      -1,   572,    -1,   578,    -1,   595,    -1,   602,    -1,   609,
      -1,   616,    -1,   621,    -1,   549,   550,    -1,   187,    -1,
     551,    -1,   552,    -1,    10,   188,    -1,    11,    -1,    10,
     553,   188,    -1,     4,    -1,   555,   556,    -1,   189,    -1,
     557,    -1,   558,    -1,    10,   190,    -1,    11,    -1,    10,
     559,   190,    -1,     4,    -1,   561,   562,    -1,   173,    -1,
     563,    -1,   564,    -1,    10,   174,    -1,    11,    -1,    10,
     565,   174,    -1,     4,    -1,   567,   568,    -1,   101,    -1,
     569,    -1,   570,    -1,    10,   102,    -1,    11,    -1,    10,
     571,   102,    -1,     4,    -1,   573,   574,    -1,   139,    -1,
     575,    -1,   576,    -1,    10,   140,    -1,    11,    -1,    10,
     577,   140,    -1,     4,    -1,   579,   580,   581,    -1,   203,
      -1,  1106,    -1,   582,    -1,   583,    -1,    10,   204,    -1,
      11,    -1,    10,   584,   204,    -1,   585,    -1,   586,    -1,
     585,   586,    -1,   587,   588,   590,    -1,   197,    -1,    -1,
     588,   589,    -1,  1079,    -1,  1075,    -1,  1050,    -1,  1058,
      -1,   591,    -1,   592,    -1,    10,   198,    -1,    11,    -1,
      10,   593,   198,    -1,   594,    -1,     7,    -1,     6,    -1,
     596,   597,   600,    -1,   213,    -1,   598,    -1,    -1,   598,
     599,    -1,  1079,    -1,  1058,    -1,    10,   601,   214,    -1,
    1109,    -1,   603,   604,   607,    -1,   215,    -1,   605,    -1,
      -1,   605,   606,    -1,  1079,    -1,  1058,    -1,    10,   608,
     216,    -1,  1109,    -1,   610,   611,   614,    -1,   211,    -1,
     612,    -1,    -1,   612,   613,    -1,  1079,    -1,  1058,    -1,
      10,   615,   212,    -1,  1109,    -1,   617,   618,   619,    -1,
     209,    -1,    -1,  1058,    -1,    10,   620,   210,    -1,     6,
      -1,   622,   623,   624,    -1,   165,    -1,  1100,    -1,   625,
      -1,   626,    -1,    10,   166,    -1,    11,    -1,    10,   627,
     166,    -1,   628,    -1,   629,    -1,   628,   629,    -1,   630,
     631,   634,    -1,   163,    -1,   632,    -1,    -1,   632,   633,
      -1,  1067,    -1,  1083,    -1,  1058,    -1,    10,   164,    -1,
      11,    -1,    -1,   636,   637,   640,    -1,    75,    -1,   638,
      -1,    -1,   638,   639,    -1,  1103,    -1,  1108,    -1,  1092,
      -1,  1097,    -1,   641,    -1,   642,    -1,    10,    76,    -1,
      11,    -1,    10,   643,    76,    -1,   644,  1027,    -1,   645,
      -1,   644,   645,    -1,   646,   647,   653,    -1,   181,    -1,
     648,    -1,    -1,   648,   649,    -1,   650,    -1,   651,    -1,
     652,    -1,    36,  1111,     6,  1111,    -1,    63,     3,  1111,
      -1,    61,     3,  1111,    -1,    10,   654,   670,   676,   796,
     900,  1004,   182,    -1,   655,   656,   659,    -1,   187,    -1,
     657,    -1,   658,    -1,   657,   658,    -1,  1075,    -1,  1058,
      -1,  1105,    -1,   660,    -1,   661,    -1,    10,   188,    -1,
      11,    -1,    10,   662,   188,    -1,   663,    -1,   664,    -1,
     663,   664,    -1,   665,   666,   669,    -1,   191,    -1,   667,
      -1,    -1,   667,   668,    -1,  1075,    -1,  1058,    -1,    10,
     192,    -1,    11,    -1,    -1,   671,   672,    -1,   153,    -1,
     673,    -1,   674,    -1,    10,   154,    -1,    11,    -1,    10,
     675,   154,    -1,     4,    -1,    -1,   677,   678,   679,    -1,
     221,    -1,    -1,  1102,    -1,   680,    -1,   681,    -1,    11,
      -1,    10,   682,   222,    -1,   683,   696,   712,   767,    -1,
      -1,   684,   685,   686,    -1,   260,    -1,  1107,    -1,   687,
      -1,   688,    -1,    10,   261,    -1,    11,    -1,    10,   689,
     261,    -1,   690,    -1,   691,    -1,   690,   691,    -1,   692,
     693,   695,    -1,   219,    -1,    -1,   693,   694,    -1,  1066,
      -1,  1067,    -1,    10,  1109,   220,    -1,    -1,   697,   698,
     699,    -1,   217,    -1,  1107,    -1,   700,    -1,   701,    -1,
      10,   218,    -1,    11,    -1,    10,   702,   218,    -1,   703,
      -1,   704,    -1,   703,   704,    -1,   705,   706,   708,    -1,
     219,    -1,    -1,   706,   707,    -1,  1066,    -1,  1067,    -1,
     709,    -1,   710,    -1,    10,   220,    -1,    11,    -1,    10,
     711,   220,    -1,     4,    -1,    -1,   713,   714,    -1,   121,
      -1,   715,    -1,   716,    -1,    11,    -1,    10,   717,   122,
      -1,   718,   725,   732,   739,   746,   753,   760,    -1,    -1,
     719,   720,   721,    -1,   119,    -1,  1093,    -1,   722,    -1,
     723,    -1,    11,    -1,    10,   724,   120,    -1,  1142,    -1,
      -1,   726,   727,   728,    -1,   105,    -1,  1093,    -1,   729,
      -1,   730,    -1,    11,    -1,    10,   731,   106,    -1,  1142,
      -1,    -1,   733,   734,   735,    -1,   107,    -1,  1093,    -1,
     736,    -1,   737,    -1,    11,    -1,    10,   738,   108,    -1,
    1142,    -1,    -1,   740,   741,   742,    -1,   103,    -1,  1093,
      -1,   743,    -1,   744,    -1,    11,    -1,    10,   745,   104,
      -1,  1142,    -1,    -1,   747,   748,   749,    -1,   149,    -1,
    1093,    -1,   750,    -1,   751,    -1,    11,    -1,    10,   752,
     150,    -1,  1142,    -1,    -1,   754,   755,   756,    -1,   193,
      -1,  1093,    -1,   757,    -1,   758,    -1,    11,    -1,    10,
     759,   194,    -1,  1142,    -1,    -1,   761,   762,   763,    -1,
     207,    -1,  1093,    -1,   764,    -1,   765,    -1,    11,    -1,
      10,   766,   208,    -1,  1142,    -1,    -1,   767,   768,    -1,
     769,   770,   773,    -1,   163,    -1,   771,    -1,    -1,   771,
     772,    -1,  1107,    -1,  1094,    -1,  1083,    -1,  1067,    -1,
    1075,    -1,  1087,    -1,  1062,    -1,  1058,    -1,   774,    -1,
     775,    -1,    10,   164,    -1,    11,    -1,    10,   776,   164,
      -1,   777,    -1,   786,    -1,   778,    -1,   777,   778,    -1,
     779,   780,   782,    -1,   219,    -1,    -1,   780,   781,    -1,
    1066,    -1,  1067,    -1,   783,    -1,   784,    -1,    10,   220,
      -1,    11,    -1,    10,   785,   220,    -1,  1110,    -1,   787,
      -1,   786,   787,    -1,   788,   789,   792,    -1,   137,    -1,
     790,    -1,    -1,   790,   791,    -1,  1093,    -1,  1083,    -1,
    1058,    -1,   793,    -1,   794,    -1,    11,    -1,    10,   795,
     138,    -1,  1142,    -1,    -1,   797,   798,   799,    -1,   157,
      -1,    -1,  1099,    -1,   800,    -1,   801,    -1,    11,    -1,
      10,   802,   158,    -1,   803,   816,   871,    -1,    -1,   804,
     805,   806,    -1,   260,    -1,  1096,    -1,   807,    -1,   808,
      -1,    10,   261,    -1,    11,    -1,    10,   809,   261,    -1,
     810,    -1,   811,    -1,   810,   811,    -1,   812,   813,   815,
      -1,   155,    -1,    -1,   813,   814,    -1,  1066,    -1,  1067,
      -1,    10,  1109,   156,    -1,    -1,   817,   818,    -1,   121,
      -1,   819,    -1,   820,    -1,    11,    -1,    10,   821,   122,
      -1,   822,   829,   836,   843,   850,   857,   864,    -1,    -1,
     823,   824,   825,    -1,   119,    -1,  1093,    -1,   826,    -1,
     827,    -1,    11,    -1,    10,   828,   120,    -1,  1142,    -1,
      -1,   830,   831,   832,    -1,   105,    -1,  1093,    -1,   833,
      -1,   834,    -1,    11,    -1,    10,   835,   106,    -1,  1142,
      -1,    -1,   837,   838,   839,    -1,   107,    -1,  1093,    -1,
     840,    -1,   841,    -1,    11,    -1,    10,   842,   108,    -1,
    1142,    -1,    -1,   844,   845,   846,    -1,   103,    -1,  1093,
      -1,   847,    -1,   848,    -1,    11,    -1,    10,   849,   104,
      -1,  1142,    -1,    -1,   851,   852,   853,    -1,   149,    -1,
    1093,    -1,   854,    -1,   855,    -1,    11,    -1,    10,   856,
     150,    -1,  1142,    -1,    -1,   858,   859,   860,    -1,   193,
      -1,  1093,    -1,   861,    -1,   862,    -1,    11,    -1,    10,
     863,   194,    -1,  1142,    -1,    -1,   865,   866,   867,    -1,
     207,    -1,  1093,    -1,   868,    -1,   869,    -1,    11,    -1,
      10,   870,   208,    -1,  1142,    -1,    -1,   871,   872,    -1,
     873,   874,   877,    -1,   163,    -1,   875,    -1,    -1,   875,
     876,    -1,  1096,    -1,  1094,    -1,  1083,    -1,  1067,    -1,
    1075,    -1,  1071,    -1,  1062,    -1,  1058,    -1,   878,    -1,
     879,    -1,    10,   164,    -1,    11,    -1,    10,   880,   164,
      -1,   881,    -1,   890,    -1,   882,    -1,   881,   882,    -1,
     883,   884,   886,    -1,   155,    -1,    -1,   884,   885,    -1,
    1066,    -1,  1067,    -1,   887,    -1,   888,    -1,    10,   156,
      -1,    11,    -1,    10,   889,   156,    -1,  1110,    -1,   891,
      -1,   890,   891,    -1,   892,   893,   896,    -1,   137,    -1,
     894,    -1,    -1,   894,   895,    -1,  1093,    -1,  1083,    -1,
    1058,    -1,   897,    -1,   898,    -1,    11,    -1,    10,   899,
     138,    -1,  1142,    -1,    -1,   901,   902,   903,    -1,   127,
      -1,    -1,  1098,    -1,   904,    -1,   905,    -1,    11,    -1,
      10,   906,   128,    -1,   907,   920,   975,    -1,    -1,   908,
     909,   910,    -1,   133,    -1,  1091,    -1,   911,    -1,   912,
      -1,    10,   134,    -1,    11,    -1,    10,   913,   134,    -1,
     914,    -1,   915,    -1,   914,   915,    -1,   916,   917,   919,
      -1,   125,    -1,    -1,   917,   918,    -1,  1066,    -1,  1067,
      -1,    10,  1109,   126,    -1,    -1,   921,   922,    -1,   121,
      -1,   923,    -1,   924,    -1,    11,    -1,    10,   925,   122,
      -1,   926,   933,   940,   947,   954,   961,   968,    -1,    -1,
     927,   928,   929,    -1,   119,    -1,  1093,    -1,   930,    -1,
     931,    -1,    11,    -1,    10,   932,   120,    -1,  1142,    -1,
      -1,   934,   935,   936,    -1,   105,    -1,  1093,    -1,   937,
      -1,   938,    -1,    11,    -1,    10,   939,   106,    -1,  1142,
      -1,    -1,   941,   942,   943,    -1,   107,    -1,  1093,    -1,
     944,    -1,   945,    -1,    11,    -1,    10,   946,   108,    -1,
    1142,    -1,    -1,   948,   949,   950,    -1,   103,    -1,  1093,
      -1,   951,    -1,   952,    -1,    11,    -1,    10,   953,   104,
      -1,  1142,    -1,    -1,   955,   956,   957,    -1,   149,    -1,
    1093,    -1,   958,    -1,   959,    -1,    11,    -1,    10,   960,
     150,    -1,  1142,    -1,    -1,   962,   963,   964,    -1,   193,
      -1,  1093,    -1,   965,    -1,   966,    -1,    11,    -1,    10,
     967,   194,    -1,  1142,    -1,    -1,   969,   970,   971,    -1,
     207,    -1,  1093,    -1,   972,    -1,   973,    -1,    11,    -1,
      10,   974,   208,    -1,  1142,    -1,    -1,   975,   976,    -1,
     977,   978,   981,    -1,   163,    -1,   979,    -1,    -1,   979,
     980,    -1,  1091,    -1,  1094,    -1,  1083,    -1,  1067,    -1,
    1075,    -1,  1054,    -1,  1062,    -1,  1058,    -1,   982,    -1,
     983,    -1,    10,   164,    -1,    11,    -1,    10,   984,   164,
      -1,   985,    -1,   994,    -1,   986,    -1,   985,   986,    -1,
     987,   988,   990,    -1,   125,    -1,    -1,   988,   989,    -1,
    1066,    -1,  1067,    -1,   991,    -1,   992,    -1,    10,   126,
      -1,    11,    -1,    10,   993,   126,    -1,  1110,    -1,   995,
      -1,   994,   995,    -1,   996,   997,  1000,    -1,   137,    -1,
     998,    -1,    -1,   998,   999,    -1,  1093,    -1,  1083,    -1,
    1058,    -1,  1001,    -1,  1002,    -1,    11,    -1,    10,  1003,
     138,    -1,  1142,    -1,    -1,  1005,  1006,  1007,    -1,   169,
      -1,  1101,    -1,  1008,    -1,  1009,    -1,    10,   170,    -1,
      11,    -1,    10,  1010,   170,    -1,  1011,    -1,  1012,    -1,
    1011,  1012,    -1,  1013,  1014,  1017,    -1,   167,    -1,  1015,
      -1,    -1,  1015,  1016,    -1,  1067,    -1,  1083,    -1,  1050,
      -1,  1058,    -1,  1095,    -1,  1018,    -1,  1019,    -1,    10,
     168,    -1,    11,    -1,    10,  1020,   168,    -1,  1021,    -1,
    1022,    -1,  1021,  1022,    -1,  1023,    -1,  1024,    -1,  1025,
      -1,    79,    -1,    80,    -1,    77,  1026,    78,    -1,     5,
      -1,    -1,  1028,  1029,  1030,    -1,   171,    -1,  1104,    -1,
    1031,    -1,  1032,    -1,    10,   172,    -1,    11,    -1,    10,
    1033,   172,    -1,  1034,    -1,  1035,    -1,  1034,  1035,    -1,
    1036,  1037,  1040,    -1,   185,    -1,  1038,    -1,    -1,  1038,
    1039,    -1,  1067,    -1,  1050,    -1,  1058,    -1,  1095,    -1,
    1041,    -1,  1042,    -1,    10,   186,    -1,    11,    -1,    10,
    1043,   186,    -1,  1044,    -1,  1045,    -1,  1044,  1045,    -1,
    1046,    -1,  1047,    -1,  1048,    -1,    79,    -1,    80,    -1,
      77,  1049,    78,    -1,     5,    -1,  1051,    -1,  1052,    -1,
    1053,    -1,    42,    -1,    41,     3,  1111,    -1,  1055,    -1,
    1056,    -1,  1057,    -1,    50,    -1,    49,     3,  1111,    -1,
    1059,    -1,  1060,    -1,  1061,    -1,    44,    -1,    43,     3,
    1111,    -1,  1063,    -1,  1064,    -1,  1065,    -1,    52,    -1,
      51,     3,  1111,    -1,    37,  1111,     6,  1111,    -1,  1068,
      -1,  1069,    -1,  1070,    -1,    46,    -1,    45,     3,  1111,
      -1,  1072,    -1,  1073,    -1,  1074,    -1,    54,    -1,    53,
       3,  1111,    -1,  1076,    -1,  1077,    -1,  1078,    -1,    48,
      -1,    47,     3,  1111,    -1,  1080,    -1,  1081,    -1,  1082,
      -1,    58,    -1,    57,     3,  1111,    -1,  1084,    -1,  1085,
      -1,  1086,    -1,    60,    -1,    59,     3,  1111,    -1,  1088,
      -1,  1089,    -1,  1090,    -1,    56,    -1,    55,     3,  1111,
      -1,    16,  1111,     6,  1111,    -1,    17,  1111,     6,  1111,
      -1,    18,  1111,     6,  1111,    -1,    19,  1111,     6,  1111,
      -1,    21,  1111,     6,  1111,    -1,    22,  1111,     6,  1111,
      -1,    23,  1111,     6,  1111,    -1,    24,  1111,     6,  1111,
      -1,    25,  1111,     6,  1111,    -1,    26,  1111,     6,  1111,
      -1,    27,  1111,     6,  1111,    -1,    28,  1111,     6,  1111,
      -1,    29,  1111,     6,  1111,    -1,    30,  1111,     6,  1111,
      -1,    31,  1111,     6,  1111,    -1,    32,  1111,     6,  1111,
      -1,    33,  1111,     6,  1111,    -1,    34,  1111,     6,  1111,
      -1,     6,    -1,     7,    -1,     4,    -1,     6,    -1,     7,
      -1,  1112,     8,    -1,    -1,  1112,  1113,    -1,   338,    -1,
     339,    -1,   340,    -1,   341,    -1,  1115,  1116,    -1,    65,
      -1,  1117,    -1,  1118,    -1,    10,    66,    -1,    11,    -1,
      10,  1119,    66,    -1,  1120,    -1,  1121,    -1,  1120,  1121,
      -1,  1122,    -1,  1126,    -1,  1130,    -1,  1134,    -1,  1138,
      -1,    -1,  1123,    -1,  1124,    -1,  1125,    -1,    84,    -1,
      83,    -1,    81,     5,    82,    -1,    -1,  1127,    -1,  1128,
      -1,  1129,    -1,    88,    -1,    87,    -1,    85,     5,    86,
      -1,    -1,  1131,    -1,  1132,    -1,  1133,    -1,    92,    -1,
      91,    -1,    89,     5,    90,    -1,    -1,  1135,    -1,  1136,
      -1,  1137,    -1,    96,    -1,    95,    -1,    93,     5,    94,
      -1,    -1,  1139,    -1,  1140,    -1,  1141,    -1,   100,    -1,
      99,    -1,    97,     5,    98,    -1,  1143,    -1,  1150,    -1,
      -1,  1143,  1144,    -1,  1145,  1146,  1149,    -1,   135,    -1,
    1147,    -1,    -1,  1147,  1148,    -1,  1156,    -1,  1155,    -1,
      10,     6,   136,    -1,   117,  1151,  1152,    -1,    40,  1111,
       6,  1111,    -1,  1153,    -1,  1154,    -1,    10,   118,    -1,
      11,    -1,    10,     4,   118,    -1,    38,  1111,     6,  1111,
      -1,    39,  1111,     6,  1111,    -1,    40,  1111,     6,  1111,
      -1,  1153,    -1,  1154,    -1,    10,   118,    -1,    11,    -1,
      10,     4,   118,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   302,   302,   303,   305,   312,   322,   322,   324,   324,
     326,   328,   330,   339,   340,   343,   352,   352,   365,   365,
     367,   381,   381,   383,   383,   385,   387,   389,   389,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   403,   405,
     420,   427,   427,   430,   435,   439,   448,   452,   457,   457,
     459,   461,   463,   463,   465,   470,   480,   486,   486,   489,
     494,   500,   500,   503,   505,   512,   512,   514,   514,   516,
     518,   521,   523,   530,   530,   532,   532,   534,   536,   541,
     543,   550,   550,   552,   552,   554,   556,   561,   563,   570,
     570,   572,   572,   574,   576,   581,   583,   590,   590,   592,
     592,   594,   596,   601,   603,   610,   610,   612,   612,   614,
     616,   621,   623,   630,   630,   632,   632,   634,   636,   641,
     643,   650,   660,   665,   671,   671,   673,   675,   677,   677,
     679,   684,   696,   702,   702,   705,   712,   717,   724,   724,
     728,   728,   730,   741,   741,   743,   743,   745,   747,   749,
     749,   752,   753,   754,   755,   756,   757,   760,   762,   769,
     769,   771,   771,   773,   775,   782,   784,   795,   797,   797,
     800,   806,   812,   814,   820,   822,   833,   835,   835,   838,
     844,   850,   852,   859,   861,   872,   874,   874,   877,   883,
     889,   891,   898,   900,   909,   910,   916,   918,   924,   926,
     933,   943,   948,   954,   954,   956,   958,   960,   960,   962,
     967,   979,   985,   985,   988,   995,  1000,  1006,  1006,  1010,
    1010,  1012,  1023,  1023,  1025,  1025,  1027,  1029,  1031,  1031,
    1034,  1035,  1036,  1037,  1038,  1039,  1042,  1044,  1051,  1051,
    1053,  1053,  1055,  1057,  1065,  1067,  1074,  1074,  1076,  1076,
    1078,  1080,  1085,  1087,  1094,  1094,  1096,  1096,  1098,  1100,
    1105,  1107,  1114,  1114,  1116,  1116,  1118,  1120,  1125,  1127,
    1134,  1134,  1136,  1136,  1138,  1140,  1147,  1149,  1156,  1166,
    1171,  1177,  1177,  1179,  1181,  1183,  1183,  1185,  1190,  1202,
    1208,  1208,  1211,  1218,  1223,  1230,  1230,  1233,  1233,  1235,
    1251,  1251,  1253,  1253,  1255,  1257,  1259,  1259,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1275,
    1277,  1284,  1284,  1286,  1286,  1288,  1290,  1298,  1300,  1307,
    1307,  1309,  1309,  1311,  1313,  1318,  1320,  1327,  1327,  1329,
    1329,  1331,  1333,  1338,  1340,  1347,  1347,  1349,  1349,  1351,
    1353,  1358,  1360,  1367,  1367,  1369,  1369,  1371,  1373,  1378,
    1380,  1387,  1397,  1402,  1408,  1408,  1410,  1412,  1414,  1414,
    1416,  1418,  1432,  1432,  1435,  1435,  1435,  1435,  1438,  1438,
    1440,  1440,  1442,  1444,  1453,  1454,  1457,  1459,  1470,  1472,
    1472,  1475,  1481,  1487,  1489,  1496,  1498,  1509,  1511,  1511,
    1514,  1520,  1526,  1528,  1535,  1537,  1548,  1550,  1550,  1553,
    1559,  1565,  1567,  1574,  1576,  1586,  1587,  1593,  1595,  1602,
    1604,  1611,  1621,  1626,  1632,  1632,  1634,  1636,  1638,  1638,
    1640,  1645,  1657,  1663,  1663,  1666,  1673,  1678,  1685,  1685,
    1688,  1688,  1690,  1698,  1704,  1704,  1707,  1714,  1720,  1726,
    1734,  1739,  1745,  1745,  1747,  1749,  1751,  1751,  1753,  1755,
    1764,  1766,  1766,  1768,  1768,  1768,  1770,  1780,  1790,  1810,
    1816,  1818,  1828,  1834,  1834,  1837,  1842,  1847,  1857,  1862,
    1868,  1868,  1870,  1872,  1874,  1874,  1876,  1881,  1891,  1897,
    1897,  1900,  1906,  1913,  1913,  1916,  1916,  1918,  1920,  1920,
    1922,  1922,  1924,  1926,  1934,  1934,  1936,  1942,  1942,  1950,
    1950,  1952,  1954,  1956,  1958,  1958,  1960,  1962,  1970,  1975,
    1981,  1981,  1983,  1985,  1987,  1987,  1989,  2000,  2009,  2009,
    2012,  2013,  2016,  2019,  2019,  2021,  2023,  2031,  2036,  2042,
    2042,  2044,  2046,  2048,  2048,  2050,  2061,  2070,  2070,  2073,
    2074,  2078,  2079,  2081,  2081,  2083,  2085,  2090,  2090,  2092,
    2097,  2097,  2099,  2101,  2103,  2105,  2105,  2114,  2116,  2123,
    2123,  2125,  2127,  2129,  2132,  2132,  2142,  2144,  2151,  2151,
    2153,  2155,  2157,  2160,  2160,  2169,  2171,  2178,  2178,  2180,
    2182,  2184,  2187,  2187,  2196,  2198,  2205,  2205,  2207,  2209,
    2211,  2214,  2214,  2223,  2225,  2232,  2232,  2234,  2236,  2238,
    2241,  2241,  2250,  2252,  2259,  2259,  2261,  2263,  2265,  2268,
    2268,  2277,  2279,  2286,  2286,  2288,  2290,  2292,  2295,  2295,
    2297,  2302,  2321,  2327,  2327,  2330,  2341,  2352,  2358,  2364,
    2370,  2376,  2382,  2389,  2389,  2391,  2391,  2393,  2395,  2395,
    2397,  2397,  2399,  2406,  2415,  2415,  2418,  2424,  2431,  2431,
    2433,  2433,  2435,  2437,  2446,  2446,  2448,  2459,  2467,  2473,
    2473,  2476,  2482,  2483,  2487,  2487,  2489,  2491,  2494,  2498,
    2498,  2500,  2508,  2508,  2516,  2516,  2518,  2520,  2522,  2524,
    2524,  2526,  2528,  2536,  2541,  2547,  2547,  2549,  2551,  2554,
    2554,  2556,  2565,  2575,  2575,  2578,  2579,  2582,  2585,  2585,
    2587,  2592,  2592,  2595,  2597,  2599,  2601,  2601,  2610,  2612,
    2619,  2619,  2621,  2623,  2625,  2627,  2627,  2636,  2638,  2645,
    2645,  2647,  2649,  2651,  2654,  2654,  2663,  2665,  2672,  2672,
    2674,  2676,  2678,  2681,  2681,  2690,  2692,  2699,  2699,  2701,
    2703,  2705,  2708,  2708,  2717,  2719,  2726,  2726,  2728,  2730,
    2732,  2735,  2735,  2744,  2746,  2753,  2753,  2755,  2757,  2759,
    2762,  2762,  2771,  2773,  2780,  2780,  2782,  2784,  2786,  2789,
    2789,  2791,  2797,  2816,  2823,  2823,  2826,  2837,  2848,  2854,
    2860,  2866,  2872,  2878,  2887,  2887,  2889,  2889,  2891,  2893,
    2893,  2895,  2895,  2897,  2902,  2912,  2912,  2915,  2920,  2927,
    2927,  2929,  2929,  2931,  2933,  2940,  2940,  2942,  2953,  2961,
    2967,  2967,  2970,  2976,  2977,  2981,  2981,  2983,  2985,  2988,
    2991,  2991,  2993,  3000,  3000,  3008,  3008,  3010,  3012,  3014,
    3016,  3016,  3018,  3021,  3029,  3034,  3040,  3040,  3042,  3044,
    3046,  3046,  3048,  3057,  3066,  3066,  3069,  3070,  3073,  3076,
    3076,  3078,  3083,  3083,  3085,  3087,  3089,  3091,  3091,  3100,
    3102,  3109,  3109,  3111,  3113,  3115,  3117,  3117,  3126,  3128,
    3135,  3135,  3137,  3139,  3141,  3144,  3144,  3153,  3155,  3162,
    3162,  3164,  3166,  3168,  3171,  3171,  3180,  3182,  3189,  3189,
    3191,  3193,  3195,  3198,  3198,  3207,  3209,  3216,  3216,  3218,
    3220,  3222,  3225,  3225,  3234,  3236,  3243,  3243,  3245,  3247,
    3249,  3252,  3252,  3261,  3263,  3270,  3270,  3272,  3274,  3276,
    3279,  3279,  3281,  3287,  3306,  3312,  3312,  3315,  3326,  3337,
    3343,  3349,  3355,  3361,  3367,  3374,  3374,  3376,  3376,  3378,
    3380,  3380,  3382,  3382,  3384,  3391,  3400,  3400,  3404,  3409,
    3417,  3417,  3419,  3419,  3421,  3423,  3430,  3430,  3432,  3443,
    3451,  3457,  3457,  3460,  3466,  3467,  3471,  3471,  3473,  3475,
    3477,  3481,  3481,  3483,  3488,  3497,  3502,  3508,  3508,  3510,
    3512,  3514,  3514,  3516,  3521,  3535,  3543,  3543,  3546,  3552,
    3558,  3564,  3572,  3582,  3587,  3593,  3593,  3595,  3597,  3599,
    3599,  3601,  3607,  3612,  3614,  3614,  3616,  3618,  3630,  3630,
    3632,  3637,  3646,  3651,  3657,  3657,  3659,  3661,  3663,  3663,
    3665,  3670,  3682,  3690,  3690,  3693,  3698,  3704,  3710,  3719,
    3724,  3730,  3730,  3732,  3734,  3736,  3736,  3738,  3744,  3749,
    3751,  3751,  3753,  3755,  3766,  3773,  3773,  3775,  3780,  3785,
    3792,  3792,  3794,  3799,  3804,  3811,  3811,  3813,  3818,  3823,
    3830,  3830,  3832,  3837,  3842,  3850,  3857,  3857,  3859,  3864,
    3869,  3876,  3876,  3878,  3883,  3888,  3895,  3895,  3897,  3902,
    3907,  3914,  3914,  3916,  3921,  3926,  3933,  3933,  3935,  3940,
    3945,  3952,  3952,  3954,  3959,  3965,  3971,  3980,  3986,  4000,
    4009,  4015,  4024,  4030,  4036,  4042,  4048,  4054,  4063,  4069,
    4078,  4083,  4089,  4106,  4107,  4111,  4112,  4113,  4115,  4117,
    4117,  4119,  4120,  4121,  4122,  4159,  4161,  4175,  4175,  4177,
    4177,  4179,  4181,  4183,  4183,  4186,  4187,  4188,  4189,  4190,
    4192,  4192,  4200,  4200,  4202,  4202,  4204,  4210,  4210,  4218,
    4218,  4220,  4220,  4222,  4228,  4228,  4236,  4236,  4238,  4238,
    4240,  4246,  4246,  4254,  4254,  4256,  4256,  4258,  4264,  4264,
    4272,  4272,  4274,  4274,  4276,  4288,  4296,  4298,  4298,  4300,
    4302,  4311,  4313,  4313,  4315,  4315,  4317,  4333,  4335,  4340,
    4340,  4342,  4342,  4345,  4371,  4379,  4436,  4441,  4441,  4443,
    4443,  4445
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
  "EMPTYTYPEATT", "CONTYPEATT", "EMPTYCONTYPEATT", "ENUMTYPEATT",
  "EMPTYENUMTYPEATT", "OBJTYPEATT", "EMPTYOBJTYPEATT", "VARTYPEATT",
  "EMPTYVARTYPEATT", "UNITATT", "EMPTYUNITATT", "VALUEATT",
  "EMPTYVALUEATT", "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT",
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
  "ACTUALSTARTTIMESTART", "ACTUALSTARTTIMEEND", "ATEQUALITYSTART",
  "ATEQUALITYEND", "ATLOWERSTART", "ATLOWEREND", "ATUPPERSTART",
  "ATUPPEREND", "AVAILABLECPUNUMBERSTART", "AVAILABLECPUNUMBEREND",
  "AVAILABLECPUSPEEDSTART", "AVAILABLECPUSPEEDEND",
  "AVAILABLEDISKSPACESTART", "AVAILABLEDISKSPACEEND",
  "AVAILABLEMEMORYSTART", "AVAILABLEMEMORYEND", "BASE64START", "BASE64END",
  "BASICSTART", "BASICEND", "BASISSTATUSSTART", "BASISSTATUSEND",
  "BASSTATUSSTART", "BASSTATUSEND", "CONSTART", "CONEND",
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
  "USEDMEMORYEND", "VALUESSTRINGSTART", "VALUESSTRINGEND", "VARSTART",
  "VAREND", "VARIABLESSTART", "VARIABLESEND", "VARIDXSTART", "VARIDXEND",
  "MATRIXSTART", "MATRIXEND", "BASEMATRIXEND", "BASEMATRIXSTART",
  "BLOCKSTART", "BLOCKEND", "BLOCKSSTART", "BLOCKSEND", "EMPTYSYMMETRYATT",
  "SYMMETRYATT", "EMPTYEXCLUDEATT", "EXCLUDEATT", "NUMBEROFBLOCKSATT",
  "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT", "BASEMATRIXIDXATT",
  "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
  "BASEMATRIXSTARTROWATT", "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT",
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "EMPTYBASETRANSPOSEATT",
  "BASETRANSPOSEATT", "ELEMENTSSTART", "ELEMENTSEND",
  "CONSTANTELEMENTSSTART", "CONSTANTELEMENTSEND", "STARTVECTORSTART",
  "STARTVECTOREND", "NONZEROSSTART", "NONZEROSEND", "INDEXESSTART",
  "INDEXESEND", "VALUESSTART", "VALUESEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "GENERALELEMENTSSTART", "GENERALELEMENTSEND",
  "CONREFERENCEELEMENTSSTART", "CONREFERENCEELEMENTSEND",
  "OBJREFERENCEELEMENTSSTART", "OBJREFERENCEELEMENTSEND",
  "PATTERNELEMENTSSTART", "PATTERNELEMENTSEND", "COLOFFSETSSTART",
  "COLOFFSETSEND", "ROWOFFSETSSTART", "ROWOFFSETSEND", "EMPTYROWMAJORATT",
  "ROWMAJORATT", "BLOCKROWIDXATT", "BLOCKCOLIDXATT", "DUMMY",
  "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND",
  "NUMBEROFNONLINEAREXPRESSIONS", "NLSTART", "NLEND", "POWERSTART",
  "POWEREND", "PLUSSTART", "PLUSEND", "MINUSSTART", "MINUSEND",
  "DIVIDESTART", "DIVIDEEND", "LNSTART", "LNEND", "SQRTSTART", "SQRTEND",
  "SUMSTART", "SUMEND", "PRODUCTSTART", "PRODUCTEND", "EXPSTART", "EXPEND",
  "NEGATESTART", "NEGATEEND", "IFSTART", "IFEND", "SQUARESTART",
  "SQUAREEND", "COSSTART", "COSEND", "SINSTART", "SINEND", "VARIABLESTART",
  "VARIABLEEND", "ABSSTART", "ABSEND", "ERFSTART", "ERFEND", "MAXSTART",
  "MAXEND", "ALLDIFFSTART", "ALLDIFFEND", "MINSTART", "MINEND", "ESTART",
  "EEND", "PISTART", "PIEND", "TIMESSTART", "TIMESEND", "NUMBERSTART",
  "NUMBEREND", "IDATT", "COEFATT", "' '", "'\\t'", "'\\r'", "'\\n'",
  "$accept", "osrldoc", "osrlStartEmpty", "osrlStart", "osrlAttributes",
  "osrlContent", "osrlEmpty", "osrlLaden", "osrlEnd", "osrlEnding",
  "osrlBody", "headerElement", "generalElement", "generalElementStart",
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
  "slacksAtUpperBody", "slacksAtEquality", "slacksAtEqualityStart",
  "slacksAtEqualityNumberOfElATT", "slacksAtEqualityContent",
  "slacksAtEqualityEmpty", "slacksAtEqualityLaden", "slacksAtEqualityBody",
  "slacksIsFree", "slacksIsFreeStart", "slacksIsFreeNumberOfElATT",
  "slacksIsFreeContent", "slacksIsFreeEmpty", "slacksIsFreeLaden",
  "slacksIsFreeBody", "slacksSuperbasic", "slacksSuperbasicStart",
  "slacksSuperbasicNumberOfElATT", "slacksSuperbasicContent",
  "slacksSuperbasicEmpty", "slacksSuperbasicLaden", "slacksSuperbasicBody",
  "slacksUnknown", "slacksUnknownStart", "slacksUnknownNumberOfElATT",
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
  "conTypeAttribute", "conTypeAtt", "conTypeAttEmpty", "conTypeAttContent",
  "descriptionAttribute", "descriptionAtt", "descriptionAttEmpty",
  "descriptionAttContent", "enumTypeAttribute", "enumTypeAtt",
  "enumTypeAttEmpty", "enumTypeAttContent", "idxAttribute",
  "nameAttribute", "nameAtt", "nameAttEmpty", "nameAttContent",
  "objTypeAttribute", "objTypeAtt", "objTypeAttEmpty", "objTypeAttContent",
  "typeAttribute", "typeAtt", "typeAttEmpty", "typeAttContent",
  "unitAttribute", "unitAtt", "unitAttEmpty", "unitAttContent",
  "valueAttribute", "valueAtt", "valueAttEmpty", "valueAttContent",
  "varTypeAttribute", "varTypeAtt", "varTypeAttEmpty", "varTypeAttContent",
  "numberOfConAttribute", "numberOfConstraintsAttribute",
  "numberOfElAttribute", "numberOfEnumerationsAttribute",
  "numberOfItemsAttribute", "numberOfObjAttribute",
  "numberOfObjectivesAttribute", "numberOfOtherConstraintResultsAttribute",
  "numberOfOtherObjectiveResultsAttribute",
  "numberOfOtherResultsAttribute", "numberOfOtherSolutionResultsAttribute",
  "numberOfOtherVariableResultsAttribute", "numberOfSolutionsAttribute",
  "numberOfSolverOutputsAttribute", "numberOfSubstatusesAttribute",
  "numberOfTimesAttribute", "numberOfVarAttribute",
  "numberOfVariablesAttribute", "aNumber", "ElementValue", "quote",
  "xmlWhiteSpace", "xmlWhiteSpaceChar", "osglFileHeader",
  "headerElementStart", "headerElementContent", "headerElementEmpty",
  "headerElementLaden", "headerElementBody", "headerElementList",
  "headerChild", "fileName", "fileNameContent", "fileNameEmpty",
  "fileNameLaden", "fileSource", "fileSourceContent", "fileSourceEmpty",
  "fileSourceLaden", "fileDescription", "fileDescriptionContent",
  "fileDescriptionEmpty", "fileDescriptionLaden", "fileCreator",
  "fileCreatorContent", "fileCreatorEmpty", "fileCreatorLaden",
  "fileLicence", "fileLicenceContent", "fileLicenceEmpty",
  "fileLicenceLaden", "osglIntArrayData", "osglIntVectorElArray",
  "osglIntVectorEl", "osglIntVectorElStart", "osglIntVectorElAttributes",
  "osglIntVectorElAttList", "osglIntVectorElAtt", "osglIntVectorElContent",
  "osglIntVectorBase64", "Base64SizeAttribute", "Base64Content",
  "Base64Empty", "Base64Laden", "osglIncrAttribute", "osglMultAttribute", 0
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
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,    32,     9,
      13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   342,   343,   343,   344,   345,   346,   346,   347,   347,
     348,   349,   350,   351,   351,   352,   353,   353,   354,   354,
     355,   356,   356,   357,   357,   358,   359,   360,   360,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   362,   363,
     364,   365,   365,   366,   366,   366,   367,   367,   368,   368,
     369,   370,   371,   371,   372,   373,   374,   375,   375,   376,
     376,   377,   377,   378,   379,   380,   380,   381,   381,   382,
     383,   384,   385,   386,   386,   387,   387,   388,   389,   390,
     391,   392,   392,   393,   393,   394,   395,   396,   397,   398,
     398,   399,   399,   400,   401,   402,   403,   404,   404,   405,
     405,   406,   407,   408,   409,   410,   410,   411,   411,   412,
     413,   414,   415,   416,   416,   417,   417,   418,   419,   420,
     421,   422,   423,   423,   424,   424,   425,   426,   427,   427,
     428,   429,   430,   431,   431,   432,   432,   432,   433,   433,
     434,   434,   435,   436,   436,   437,   437,   438,   439,   440,
     440,   441,   441,   441,   441,   441,   441,   442,   443,   444,
     444,   445,   445,   446,   447,   448,   449,   450,   451,   451,
     452,   452,   453,   454,   455,   456,   457,   458,   458,   459,
     459,   460,   461,   462,   463,   464,   465,   465,   466,   466,
     467,   468,   469,   470,   471,   471,   472,   473,   474,   475,
     476,   477,   477,   478,   478,   479,   480,   481,   481,   482,
     483,   484,   485,   485,   486,   486,   486,   487,   487,   488,
     488,   489,   490,   490,   491,   491,   492,   493,   494,   494,
     495,   495,   495,   495,   495,   495,   496,   497,   498,   498,
     499,   499,   500,   501,   502,   503,   504,   504,   505,   505,
     506,   507,   508,   509,   510,   510,   511,   511,   512,   513,
     514,   515,   516,   516,   517,   517,   518,   519,   520,   521,
     522,   522,   523,   523,   524,   525,   526,   527,   528,   529,
     529,   530,   530,   531,   532,   533,   533,   534,   535,   536,
     537,   537,   538,   538,   538,   539,   539,   540,   540,   541,
     542,   542,   543,   543,   544,   545,   546,   546,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   548,
     549,   550,   550,   551,   551,   552,   553,   554,   555,   556,
     556,   557,   557,   558,   559,   560,   561,   562,   562,   563,
     563,   564,   565,   566,   567,   568,   568,   569,   569,   570,
     571,   572,   573,   574,   574,   575,   575,   576,   577,   578,
     579,   580,   581,   581,   582,   582,   583,   584,   585,   585,
     586,   587,   588,   588,   589,   589,   589,   589,   590,   590,
     591,   591,   592,   593,   594,   594,   595,   596,   597,   598,
     598,   599,   599,   600,   601,   602,   603,   604,   605,   605,
     606,   606,   607,   608,   609,   610,   611,   612,   612,   613,
     613,   614,   615,   616,   617,   618,   618,   619,   620,   621,
     622,   623,   624,   624,   625,   625,   626,   627,   628,   628,
     629,   630,   631,   632,   632,   633,   633,   633,   634,   634,
     635,   635,   636,   637,   638,   638,   639,   639,   639,   639,
     640,   640,   641,   641,   642,   643,   644,   644,   645,   646,
     647,   648,   648,   649,   649,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   657,   658,   658,   658,   659,   659,
     660,   660,   661,   662,   663,   663,   664,   665,   666,   667,
     667,   668,   668,   669,   669,   670,   670,   671,   672,   672,
     673,   673,   674,   675,   676,   676,   677,   678,   678,   679,
     679,   680,   681,   682,   683,   683,   684,   685,   686,   686,
     687,   687,   688,   689,   690,   690,   691,   692,   693,   693,
     694,   694,   695,   696,   696,   697,   698,   699,   699,   700,
     700,   701,   702,   703,   703,   704,   705,   706,   706,   707,
     707,   708,   708,   709,   709,   710,   711,   712,   712,   713,
     714,   714,   715,   716,   717,   718,   718,   719,   720,   721,
     721,   722,   723,   724,   725,   725,   726,   727,   728,   728,
     729,   730,   731,   732,   732,   733,   734,   735,   735,   736,
     737,   738,   739,   739,   740,   741,   742,   742,   743,   744,
     745,   746,   746,   747,   748,   749,   749,   750,   751,   752,
     753,   753,   754,   755,   756,   756,   757,   758,   759,   760,
     760,   761,   762,   763,   763,   764,   765,   766,   767,   767,
     768,   769,   770,   771,   771,   772,   772,   772,   772,   772,
     772,   772,   772,   773,   773,   774,   774,   775,   776,   776,
     777,   777,   778,   779,   780,   780,   781,   781,   782,   782,
     783,   783,   784,   785,   786,   786,   787,   788,   789,   790,
     790,   791,   791,   791,   792,   792,   793,   794,   795,   796,
     796,   797,   798,   798,   799,   799,   800,   801,   802,   803,
     803,   804,   805,   806,   806,   807,   807,   808,   809,   810,
     810,   811,   812,   813,   813,   814,   814,   815,   816,   816,
     817,   818,   818,   819,   820,   821,   822,   822,   823,   824,
     825,   825,   826,   827,   828,   829,   829,   830,   831,   832,
     832,   833,   834,   835,   836,   836,   837,   838,   839,   839,
     840,   841,   842,   843,   843,   844,   845,   846,   846,   847,
     848,   849,   850,   850,   851,   852,   853,   853,   854,   855,
     856,   857,   857,   858,   859,   860,   860,   861,   862,   863,
     864,   864,   865,   866,   867,   867,   868,   869,   870,   871,
     871,   872,   873,   874,   875,   875,   876,   876,   876,   876,
     876,   876,   876,   876,   877,   877,   878,   878,   879,   880,
     880,   881,   881,   882,   883,   884,   884,   885,   885,   886,
     886,   887,   887,   888,   889,   890,   890,   891,   892,   893,
     894,   894,   895,   895,   895,   896,   896,   897,   898,   899,
     900,   900,   901,   902,   902,   903,   903,   904,   905,   906,
     907,   907,   908,   909,   910,   910,   911,   911,   912,   913,
     914,   914,   915,   916,   917,   917,   918,   918,   919,   920,
     920,   921,   922,   922,   923,   924,   925,   926,   926,   927,
     928,   929,   929,   930,   931,   932,   933,   933,   934,   935,
     936,   936,   937,   938,   939,   940,   940,   941,   942,   943,
     943,   944,   945,   946,   947,   947,   948,   949,   950,   950,
     951,   952,   953,   954,   954,   955,   956,   957,   957,   958,
     959,   960,   961,   961,   962,   963,   964,   964,   965,   966,
     967,   968,   968,   969,   970,   971,   971,   972,   973,   974,
     975,   975,   976,   977,   978,   979,   979,   980,   980,   980,
     980,   980,   980,   980,   980,   981,   981,   982,   982,   983,
     984,   984,   985,   985,   986,   987,   988,   988,   989,   989,
     990,   990,   991,   991,   992,   993,   994,   994,   995,   996,
     997,   998,   998,   999,   999,   999,  1000,  1000,  1001,  1002,
    1003,  1004,  1004,  1005,  1006,  1007,  1007,  1008,  1008,  1009,
    1010,  1011,  1011,  1012,  1013,  1014,  1015,  1015,  1016,  1016,
    1016,  1016,  1016,  1017,  1017,  1018,  1018,  1019,  1020,  1021,
    1021,  1022,  1023,  1023,  1024,  1024,  1025,  1026,  1027,  1027,
    1028,  1029,  1030,  1030,  1031,  1031,  1032,  1033,  1034,  1034,
    1035,  1036,  1037,  1038,  1038,  1039,  1039,  1039,  1039,  1040,
    1040,  1041,  1041,  1042,  1043,  1044,  1044,  1045,  1046,  1046,
    1047,  1047,  1048,  1049,  1050,  1051,  1051,  1052,  1053,  1054,
    1055,  1055,  1056,  1057,  1058,  1059,  1059,  1060,  1061,  1062,
    1063,  1063,  1064,  1065,  1066,  1067,  1068,  1068,  1069,  1070,
    1071,  1072,  1072,  1073,  1074,  1075,  1076,  1076,  1077,  1078,
    1079,  1080,  1080,  1081,  1082,  1083,  1084,  1084,  1085,  1086,
    1087,  1088,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1109,  1110,  1110,  1110,  1111,  1112,
    1112,  1113,  1113,  1113,  1113,  1114,  1115,  1116,  1116,  1117,
    1117,  1118,  1119,  1120,  1120,  1121,  1121,  1121,  1121,  1121,
    1122,  1122,  1123,  1123,  1124,  1124,  1125,  1126,  1126,  1127,
    1127,  1128,  1128,  1129,  1130,  1130,  1131,  1131,  1132,  1132,
    1133,  1134,  1134,  1135,  1135,  1136,  1136,  1137,  1138,  1138,
    1139,  1139,  1140,  1140,  1141,  1142,  1142,  1143,  1143,  1144,
    1145,  1146,  1147,  1147,  1148,  1148,  1149,  1150,  1151,  1152,
    1152,  1153,  1153,  1154,  1155,  1156,  1151,  1152,  1152,  1153,
    1153,  1154
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     1,     0,     6,     0,     1,     0,     2,
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
       1,     1,     1,     3,     7,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       1,     2,     3,     1,     0,     2,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     0,     1,     1,     1,     1,     3,     3,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     0,     2,     1,     1,     3,     0,     2,
       1,     1,     1,     1,     3,     7,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     2,     3,     1,     0,     2,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     0,     1,     1,     1,     1,     3,     3,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     0,     2,     1,     1,     3,     0,
       2,     1,     1,     1,     1,     3,     7,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     1,     2,     3,     1,     0,     2,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     4,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     2,     0,
       2,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     3,     0,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     3,     1,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     3,     3,     4,     1,
       1,     2,     1,     3,     4,     4,     4,     1,     1,     2,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,  1136,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   140,     0,
       0,  1140,  1135,  1137,  1138,    16,    10,     3,     8,     9,
     142,   219,     0,     0,    24,    19,    21,    22,  1139,     0,
    1155,  1154,     0,  1162,  1161,     0,  1169,  1168,     0,  1176,
    1175,     0,  1183,  1182,     0,  1142,  1143,  1145,  1151,  1152,
    1153,  1146,  1158,  1159,  1160,  1147,  1165,  1166,  1167,  1148,
    1172,  1173,  1174,  1149,  1179,  1180,  1181,    14,   221,   297,
       0,     0,   146,   141,   143,   144,    23,    39,    88,    96,
      64,   120,    80,    72,   104,   112,     0,    26,    27,    29,
       0,    30,     0,    31,     0,    32,     0,    33,     0,    34,
       0,    35,     0,    36,     0,    37,     0,     0,     0,     0,
       0,     0,  1141,  1144,    11,   299,   440,     0,     0,   225,
     220,   222,   223,   145,   193,   184,   166,   175,   199,   158,
       0,   148,   149,   151,     0,   152,   168,   153,   177,   154,
     186,   155,   194,   156,     0,    25,    28,  1129,     0,  1067,
       0,  1088,     0,    40,    41,    44,  1064,  1065,  1066,    43,
    1085,  1086,  1087,    45,     0,    68,    63,    65,    66,     0,
      76,    71,    73,    74,     0,    84,    79,    81,    82,     0,
      92,    87,    89,    90,     0,   100,    95,    97,    98,     0,
     108,   103,   105,   106,     0,   116,   111,   113,   114,  1129,
       0,   121,  1156,  1163,  1170,  1177,  1184,   442,    15,   444,
       0,   303,   298,   300,   301,   224,   245,   237,   277,   269,
     261,   253,     0,   227,   228,   230,     0,   231,     0,   232,
       0,   233,     0,   234,     0,   235,     0,   147,   150,     0,
     162,   157,   159,   160,     0,   167,     0,   176,     0,   185,
       0,   195,     0,   200,     0,     0,  1129,  1129,     0,    49,
      38,    46,    47,    42,    70,    67,     0,    78,    75,     0,
      86,    83,     0,    94,    91,     0,   102,    99,     0,   110,
     107,     0,   118,   115,     0,     0,     0,   125,   119,   122,
     123,     0,   443,   302,   344,   352,   420,   336,   320,   328,
     360,   414,   405,   387,   396,     0,   305,   306,   308,     0,
     309,     0,   310,     0,   311,     0,   312,     0,   313,     0,
     314,   389,   315,   398,   316,   407,   317,   415,   318,     0,
     226,   229,     0,   241,   236,   238,   239,     0,   249,   244,
     246,   247,     0,   257,   252,   254,   255,     0,   265,   260,
     262,   263,     0,   273,   268,   270,   271,     0,   278,   164,
     161,     0,     0,   165,     0,  1093,   169,   171,   170,  1090,
    1091,  1092,     0,   174,   178,   180,   179,     0,   183,   187,
     189,   188,     0,   192,     0,   204,   198,   201,   202,  1129,
    1128,  1131,  1132,  1133,  1134,  1130,  1068,  1089,    48,    55,
       0,    51,    52,    57,    69,    77,    85,    93,   101,   109,
     117,  1129,   131,   124,     0,   127,   128,   133,     0,   453,
     441,   450,   451,  1129,  1129,  1129,  1129,   445,   448,   449,
     446,   447,   304,   307,     0,   324,   319,   321,   322,     0,
     332,   327,   329,   330,     0,   340,   335,   337,   338,     0,
     348,   343,   345,   346,     0,   356,   351,   353,   354,  1129,
       0,   361,     0,   388,     0,   397,     0,   406,     0,   416,
       0,   421,   243,   240,     0,   251,   248,     0,   259,   256,
       0,   267,   264,     0,  1123,  1124,   272,     0,   275,     0,
     282,   276,   279,   280,   163,     0,   173,  1129,     0,   182,
       0,   191,   197,     0,   210,   203,     0,   206,   207,   212,
    1119,    50,    53,     0,    56,  1114,   126,   129,     0,   132,
     452,   459,     0,  1018,   456,   461,     0,     0,     0,     0,
     326,   323,     0,   334,   331,     0,   342,   339,     0,   350,
     347,     0,   358,   355,     0,     0,     0,   365,   359,   362,
     363,     0,   386,   390,   392,   391,     0,   395,   399,   401,
     400,     0,   404,   408,   410,   409,     0,   413,     0,   425,
     419,   422,   423,   242,   250,   258,   266,   274,   288,   281,
       0,   284,   285,   290,   172,  1094,   181,   190,   196,   205,
     208,     0,   211,     0,    62,    54,     0,  1078,    58,    60,
      59,  1075,  1076,  1077,     0,   139,   130,     0,  1098,   134,
     137,   135,   136,  1095,  1096,  1097,   454,  1020,   457,   455,
       0,     0,   460,  1129,  1129,  1129,  1129,   325,   333,   341,
     349,   357,  1129,   371,   364,     0,   367,   368,   372,     0,
     394,     0,   403,     0,   412,   418,     0,   431,   424,     0,
     427,   428,   433,   283,   286,     0,   289,     0,   218,   209,
     213,   216,   214,   215,    61,  1129,   138,  1129,  1129,     0,
    1021,     0,   458,  1129,     0,     0,   462,   463,   464,   465,
    1106,  1111,  1117,  1122,  1120,   366,   369,     0,   393,   402,
     411,   417,   426,   429,     0,   432,     0,   296,   287,   291,
     294,   292,   293,   217,  1079,  1099,     0,     0,  1025,  1019,
    1022,  1023,   471,   495,     0,     0,  1129,  1129,     0,   381,
       0,  1057,   373,   370,   378,   379,   376,  1054,  1055,  1056,
     377,   375,   374,     0,   439,   430,   434,   437,   435,   436,
     295,  1129,  1024,  1031,     0,  1027,  1028,  1033,   497,   504,
       0,     0,   472,   473,   476,   475,   477,  1129,   468,   467,
     385,   384,   380,     0,   383,  1129,   438,  1118,  1026,  1029,
       0,  1032,   506,   679,   507,     0,   501,   496,   498,   499,
       0,   481,   470,   478,   479,   474,   466,   382,  1058,     0,
    1042,  1030,  1039,  1040,  1129,  1034,  1036,  1037,  1035,  1038,
     681,   830,   682,  1129,     0,   508,   503,   500,     0,   480,
     487,     0,   483,   484,   489,     0,  1050,  1051,  1041,     0,
    1044,  1045,  1047,  1048,  1049,     0,   832,   981,   833,  1129,
       0,   683,     0,   514,   511,   505,   509,   510,   502,   482,
     485,     0,   488,  1053,     0,  1043,  1046,  1129,   983,     0,
       0,  1129,     0,   834,     0,   689,   686,   680,   684,   685,
    1129,   516,     0,   533,     0,     0,   494,   486,   490,   492,
     491,  1052,  1109,   469,  1129,     0,   984,     0,   840,   837,
     831,   835,   836,  1129,   691,     0,   708,     0,  1116,   512,
     535,   557,     0,  1129,     0,   517,   493,     0,     0,   988,
     982,   985,   986,  1129,   842,     0,   859,     0,  1113,   687,
     710,   779,     0,  1129,     0,   692,   559,   628,     0,     0,
     536,     0,     0,   521,   515,   518,   519,  1129,   994,   987,
       0,   990,   991,   996,  1112,   838,   861,   930,     0,  1129,
       0,   843,   688,   716,   713,   709,   711,   712,     0,     0,
     696,   690,   693,   694,   513,   565,   562,   558,   560,   561,
       0,   540,   534,   537,   538,  1129,   527,   520,     0,   523,
     524,   528,  1115,   989,   992,     0,   995,   839,   867,   864,
     860,   862,   863,     0,     0,   847,   841,   844,   845,   782,
     780,   784,   718,     0,   725,     0,  1129,   702,   695,     0,
     698,   699,   703,   631,   629,   633,   567,     0,   574,     0,
     539,   546,     0,   542,   543,   547,  1121,   522,   525,     0,
       0,  1006,   993,  1003,  1004,   997,  1000,  1001,   998,   999,
    1002,   933,   931,   935,   869,     0,   876,     0,  1129,   853,
     846,     0,   849,   850,   854,     0,   783,   714,   727,   734,
       0,  1129,     0,   719,  1110,   697,   700,     0,     0,   632,
     563,   576,   583,     0,     0,   568,   541,   544,     0,     0,
    1129,   529,   526,   530,   531,     0,  1014,  1015,  1005,     0,
    1008,  1009,  1011,  1012,  1013,     0,   934,   865,   878,   885,
       0,     0,   870,  1105,   848,   851,     0,     0,   797,   781,
     794,   795,  1129,     0,  1072,     0,  1083,   785,   793,   792,
    1069,  1070,  1071,   789,   791,  1080,  1081,  1082,   790,   788,
     787,   786,   736,   743,     0,     0,   728,     0,  1187,   722,
     717,   720,   721,     0,   704,   701,   705,   706,     0,   646,
     630,   643,   644,     0,  1103,   634,   642,   641,   638,   639,
     637,   640,  1100,  1101,  1102,   636,   635,   585,   592,     0,
       0,   577,  1187,   571,   566,   569,   570,     0,   554,   548,
     545,   551,   552,   549,   550,     0,     0,  1017,     0,  1007,
    1010,     0,   948,   932,   945,   946,     0,  1062,   936,   942,
    1059,  1060,  1061,   944,   943,   940,   941,   939,   937,   938,
     887,   894,     0,     0,   879,  1187,   873,   868,   871,   872,
       0,   855,   852,   856,   857,   818,   804,   796,     0,   799,
     801,   805,   800,   815,   820,     0,  1129,  1129,   745,   752,
       0,     0,   737,  1187,   731,   726,   729,   730,  1129,     0,
       0,   724,  1185,  1186,     0,   667,   645,   653,     0,   648,
     650,   654,   649,   664,   669,  1129,   594,   601,     0,     0,
     586,  1187,   580,   575,   578,   579,     0,   573,   556,   553,
       0,   532,  1129,  1016,   955,   969,   947,     0,   950,   952,
     956,   951,   966,   971,  1129,   896,   903,     0,     0,   888,
    1187,   882,   877,   880,   881,     0,   875,     0,   798,   802,
       0,   816,     0,   819,  1129,  1073,  1084,   754,   761,     0,
       0,   746,  1187,   740,   735,   738,   739,     0,   733,  1107,
    1129,     0,   723,  1190,  1188,  1192,   707,   647,   651,     0,
     665,     0,   668,  1104,   603,   610,     0,     0,   595,  1187,
     589,   584,   587,   588,     0,   582,   572,   555,  1074,   949,
     953,     0,   967,     0,   970,  1063,   905,   912,     0,     0,
     897,  1187,   891,   886,   889,   890,     0,   884,   874,   858,
       0,   812,   806,   803,   809,   810,   807,   808,  1187,   827,
     817,   825,   826,   821,   824,   823,   822,  1108,   763,   770,
       0,     0,   755,  1187,   749,   744,   747,   748,     0,   742,
     732,     0,     0,  1202,  1197,  1199,  1200,     0,  1191,     0,
     661,   655,   652,   658,   659,   656,   657,  1187,   676,   666,
     674,   675,   670,   673,   672,   671,   612,   619,     0,     0,
     604,  1187,   598,   593,   596,   597,     0,   591,   581,     0,
     963,   957,   954,   960,   961,   958,   959,  1187,   978,   968,
     976,   977,   972,   975,   974,   973,   914,   921,     0,     0,
     906,  1187,   900,   895,   898,   899,     0,   893,   883,  1125,
    1126,  1127,   811,     0,   814,     0,   829,   772,   715,     0,
       0,   764,  1187,   758,   753,   756,   757,     0,   751,   741,
    1129,     0,  1201,     0,  1189,  1129,  1129,  1193,  1195,  1194,
     660,     0,   663,     0,   678,   621,   564,     0,     0,   613,
    1187,   607,   602,   605,   606,     0,   600,   590,   962,     0,
     965,     0,   980,   923,   866,     0,     0,   915,  1187,   909,
     904,   907,   908,     0,   902,   892,   813,   828,     0,   773,
    1187,   767,   762,   765,   766,     0,   760,   750,  1198,  1203,
       0,     0,     0,   662,   677,     0,   622,  1187,   616,   611,
     614,   615,     0,   609,   599,   964,   979,     0,   924,  1187,
     918,   913,   916,   917,     0,   911,   901,  1187,   776,   771,
     774,   775,     0,   769,   759,  1196,  1129,  1129,  1187,   625,
     620,   623,   624,     0,   618,   608,  1187,   927,   922,   925,
     926,     0,   920,   910,     0,   778,   768,  1204,  1205,     0,
     627,   617,     0,   929,   919,   777,   626,   928
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    27,    28,    29,    15,    16,
       8,     9,    18,    19,    35,    36,    37,    96,    97,    98,
      99,   100,   162,   163,   164,   270,   271,   272,   410,   411,
     412,   413,   523,   524,   608,   605,   101,   102,   176,   177,
     178,   276,   103,   104,   181,   182,   183,   279,   105,   106,
     186,   187,   188,   282,   107,   108,   191,   192,   193,   285,
     109,   110,   196,   197,   198,   288,   111,   112,   201,   202,
     203,   291,   113,   114,   206,   207,   208,   294,   115,   116,
     210,   298,   299,   300,   424,   425,   426,   427,   528,   529,
     619,   616,    31,    32,    83,    84,    85,   140,   141,   142,
     143,   144,   251,   252,   253,   371,   145,   146,   254,   255,
     376,   373,   505,   147,   148,   256,   257,   384,   383,   508,
     149,   150,   258,   259,   389,   388,   510,   151,   152,   260,
     393,   513,   153,   154,   262,   396,   397,   398,   516,   517,
     518,   519,   601,   602,   670,   669,    79,    80,   130,   131,
     132,   232,   233,   234,   235,   236,   344,   345,   346,   484,
     237,   238,   349,   350,   351,   487,   239,   240,   354,   355,
     356,   490,   241,   242,   359,   360,   361,   493,   243,   244,
     364,   365,   366,   497,   245,   246,   367,   501,   502,   503,
     590,   591,   592,   593,   665,   666,   709,   708,   126,   127,
     222,   223,   224,   315,   316,   317,   318,   319,   446,   447,
     448,   542,   320,   321,   451,   452,   453,   545,   322,   323,
     456,   457,   458,   548,   324,   325,   461,   462,   463,   551,
     326,   327,   466,   467,   468,   554,   328,   329,   470,   558,
     559,   560,   645,   646,   647,   648,   697,   732,   733,   734,
     735,   773,   774,   330,   331,   472,   473,   563,   562,   649,
     332,   333,   474,   475,   568,   567,   651,   334,   335,   476,
     477,   573,   572,   653,   336,   337,   478,   577,   656,   338,
     339,   480,   580,   581,   582,   659,   660,   661,   662,   704,
     705,   746,   745,   218,   219,   301,   302,   437,   430,   431,
     432,   532,   533,   534,   535,   631,   632,   686,   687,   688,
     689,   682,   723,   724,   761,   762,   763,   792,   793,   794,
     821,   822,   823,   824,   851,   852,   878,   877,   759,   760,
     787,   788,   789,   818,   783,   784,   814,   845,   846,   847,
     872,   873,   874,   904,   934,   935,   936,   978,   979,   980,
     981,  1029,  1081,  1082,   901,   902,   929,   972,   973,   974,
    1022,  1023,  1024,  1025,  1078,  1179,  1180,  1181,  1182,  1280,
     927,   928,   967,   968,   969,  1017,  1018,  1019,  1074,  1174,
    1175,  1176,  1276,  1072,  1073,  1170,  1273,  1274,  1275,  1354,
    1168,  1169,  1269,  1351,  1352,  1353,  1446,  1267,  1268,  1347,
    1443,  1444,  1445,  1525,  1345,  1346,  1439,  1522,  1523,  1524,
    1572,  1437,  1438,  1518,  1569,  1570,  1571,  1603,  1516,  1517,
    1565,  1600,  1601,  1602,  1619,   964,  1014,  1015,  1068,  1069,
    1155,  1150,  1151,  1152,  1258,  1259,  1260,  1261,  1339,  1421,
    1422,  1423,  1424,  1511,  1262,  1263,  1264,  1341,  1342,  1432,
    1429,  1430,  1431,  1513,   811,   812,   840,   867,   868,   869,
     895,   896,   897,   924,   961,   962,   963,  1009,  1010,  1011,
    1012,  1067,  1144,  1145,   921,   922,   955,   956,   957,  1003,
    1004,  1005,  1062,  1140,  1141,  1142,  1250,  1059,  1060,  1135,
    1245,  1246,  1247,  1327,  1133,  1134,  1241,  1324,  1325,  1326,
    1408,  1239,  1240,  1320,  1405,  1406,  1407,  1497,  1318,  1319,
    1401,  1494,  1495,  1496,  1555,  1399,  1400,  1490,  1552,  1553,
    1554,  1592,  1488,  1489,  1548,  1589,  1590,  1591,  1614,   952,
    1000,  1001,  1055,  1056,  1117,  1109,  1110,  1111,  1228,  1229,
    1230,  1231,  1310,  1382,  1383,  1384,  1385,  1483,  1232,  1233,
    1234,  1312,  1313,  1393,  1390,  1391,  1392,  1485,   837,   838,
     862,   890,   891,   892,   915,   916,   917,   950,   996,   997,
     998,  1051,  1052,  1053,  1054,  1106,  1221,  1222,   947,   948,
     990,   991,   992,  1045,  1046,  1047,  1101,  1217,  1218,  1219,
    1305,  1099,  1100,  1213,  1302,  1303,  1304,  1376,  1211,  1212,
    1298,  1373,  1374,  1375,  1476,  1296,  1297,  1369,  1473,  1474,
    1475,  1543,  1367,  1368,  1469,  1540,  1541,  1542,  1584,  1467,
    1468,  1536,  1581,  1582,  1583,  1611,  1534,  1535,  1577,  1608,
    1609,  1610,  1622,   987,  1042,  1043,  1095,  1096,  1198,  1193,
    1194,  1195,  1287,  1288,  1289,  1290,  1361,  1451,  1452,  1453,
    1454,  1529,  1291,  1292,  1293,  1363,  1364,  1462,  1459,  1460,
    1461,  1531,   859,   860,   885,   910,   911,   912,   940,   941,
     942,   943,   985,   986,  1035,  1032,  1033,  1034,  1089,  1090,
    1091,  1092,  1093,  1094,  1188,   629,   630,   679,   719,   720,
     721,   754,   755,   756,   757,   780,   781,   805,   801,   802,
     803,   829,   830,   831,   832,   833,   834,   854,   736,   737,
     738,   739,  1199,  1200,  1201,  1202,   165,   166,   167,   168,
    1119,  1120,  1121,  1122,  1083,   610,   611,   612,   613,  1124,
    1125,  1126,  1127,   169,   170,   171,   172,   378,   379,   380,
     381,   622,   623,   624,   625,  1161,  1162,  1163,  1164,   951,
     438,  1063,  1130,   809,   925,   439,   863,   841,   211,   886,
     815,   440,   680,   173,   471,   905,   441,   498,  1484,   264,
     265,   405,    10,    11,    22,    23,    24,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    1251,  1252,  1334,  1335,  1417,  1418,  1507,  1504,  1253,  1331,
    1414,  1415,  1416,  1508,  1509
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1350
static const yytype_int16 yypact[] =
{
     231, -1350, -1350,    66,    63,   129, -1350, -1350,   133,   101,
   -1350,    70, -1350,   279, -1350, -1350, -1350, -1350,   110,   335,
     634, -1350, -1350, -1350, -1350,    63, -1350, -1350, -1350, -1350,
   -1350,   118,   366,   -20, -1350, -1350, -1350, -1350, -1350,   190,
   -1350, -1350,   216, -1350, -1350,   224, -1350, -1350,   226, -1350,
   -1350,   247, -1350, -1350,   188,   663, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350,   133, -1350,   183,
     372,   -19, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350,   195,   131, -1350, -1350,
     269, -1350,   377, -1350,   380, -1350,   388, -1350,   390, -1350,
     393, -1350,   398, -1350,   405, -1350,   271,   213,   215,   221,
     232,   222, -1350, -1350, -1350, -1350,   249,   418,    -5, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
     258,   -12, -1350, -1350,   420, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350,   394, -1350,   271, -1350, -1350, -1350,   340, -1350,
     352, -1350,   431,   269, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350,    31, -1350, -1350, -1350, -1350,    28,
   -1350, -1350, -1350, -1350,    27, -1350, -1350, -1350, -1350,    36,
   -1350, -1350, -1350, -1350,    41, -1350, -1350, -1350, -1350,    21,
   -1350, -1350, -1350, -1350,    16, -1350, -1350, -1350, -1350, -1350,
     438, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
      68, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350,   292,   -40, -1350, -1350,   446, -1350,   452, -1350,
     473, -1350,   475, -1350,   477, -1350,   271, -1350, -1350,    26,
   -1350, -1350, -1350, -1350,   361,   192,   375,   192,   384,   192,
     386, -1350,   479, -1350,   400,    -4, -1350, -1350,   -77, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350,   256, -1350, -1350,   234,
   -1350, -1350,   242, -1350, -1350,   272, -1350, -1350,   270, -1350,
   -1350,   250, -1350, -1350,   237,   426,   -81, -1350, -1350, -1350,
   -1350,   482,   346, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350,   362,   208, -1350, -1350,   485,
   -1350,   487, -1350,   493, -1350,   495, -1350,   497, -1350,   411,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350,   394, -1350,   271,
   -1350, -1350,    46, -1350, -1350, -1350, -1350,    20, -1350, -1350,
   -1350, -1350,    11, -1350, -1350, -1350, -1350,    19, -1350, -1350,
   -1350, -1350,    30, -1350, -1350, -1350, -1350,   499, -1350, -1350,
   -1350,   268,   505, -1350,   464, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350,   505, -1350, -1350, -1350, -1350,   505, -1350, -1350,
   -1350, -1350,   465, -1350,    38, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
     331,   290, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350,   334,   357, -1350, -1350,   -30, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350,    23, -1350, -1350, -1350, -1350,    18,
   -1350, -1350, -1350, -1350,    39, -1350, -1350, -1350, -1350,    50,
   -1350, -1350, -1350, -1350,    40, -1350, -1350, -1350, -1350, -1350,
     504, -1350,   528,   192,   530,   192,   544,   192,   547, -1350,
     512, -1350, -1350, -1350,   433, -1350, -1350,   437, -1350, -1350,
     367, -1350, -1350,   379, -1350, -1350, -1350,   397, -1350,   144,
   -1350, -1350, -1350, -1350, -1350,   480, -1350, -1350,   507, -1350,
     524, -1350, -1350,   501, -1350, -1350,   478,   476, -1350, -1350,
   -1350, -1350, -1350,   514,   316, -1350, -1350, -1350,   516,   202,
   -1350, -1350,   575,   -98, -1350, -1350,   662,   670,   687,   693,
   -1350, -1350,   472, -1350, -1350,   511, -1350, -1350,   509, -1350,
   -1350,   601, -1350, -1350,   569,   707,   -50, -1350, -1350, -1350,
   -1350,   505, -1350, -1350, -1350, -1350,   505, -1350, -1350, -1350,
   -1350,   505, -1350, -1350, -1350, -1350,   714, -1350,   156, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
     558,   576, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350,   519,   202,   540, -1350, -1350,   740, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350,   585, -1350, -1350,   750, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
     741,   747,    59, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350,   557,   573, -1350, -1350,   562,
   -1350,   556, -1350,   563, -1350, -1350,   567, -1350, -1350,   612,
     610, -1350, -1350, -1350, -1350,   521,   202,   615, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   523,
   -1350,   593, -1350, -1350,   778,   780, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350,   403, -1350, -1350,
   -1350, -1350, -1350, -1350,   525,   202,   620, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350,   779,   -23, -1350, -1350,
   -1350, -1350, -1350,   633,   269,   781, -1350, -1350,    22, -1350,
     785, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350,   625, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350,   618,   606, -1350, -1350, -1350,   571,
     533,   535,   269, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350,   596, -1350, -1350, -1350, -1350, -1350, -1350,
     538,   434, -1350,   638,   765,    34, -1350, -1350, -1350, -1350,
     142, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   -16,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350,   671,   771, -1350,   541, -1350, -1350, -1350,   646, -1350,
   -1350,   613,   608, -1350, -1350,   797, -1350, -1350, -1350,   617,
     119, -1350, -1350, -1350, -1350,   798, -1350,   637,   783, -1350,
     549, -1350,   799,   548, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350,   551,   244, -1350,   732, -1350, -1350, -1350, -1350,   630,
     782, -1350,   553, -1350,   807,   554, -1350, -1350, -1350, -1350,
   -1350, -1350,   594,   598,   784,   628, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350,   559, -1350,   812,   686, -1350,
   -1350, -1350, -1350, -1350, -1350,   664,   700,   801, -1350, -1350,
   -1350,   703,   784, -1350,   561, -1350, -1350,   819,   171, -1350,
   -1350, -1350, -1350, -1350, -1350,   698,   706,   813, -1350, -1350,
   -1350, -1350,   565, -1350,   580, -1350, -1350, -1350,   582,   588,
   -1350,   822,  -151, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
     660,   665, -1350, -1350, -1350, -1350, -1350, -1350,   591, -1350,
     595, -1350,   668,   715, -1350, -1350, -1350, -1350,   829,  -121,
   -1350, -1350, -1350, -1350,   674,   719, -1350, -1350, -1350, -1350,
     389, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   579,   622,
   -1350, -1350, -1350, -1350, -1350,   599,   308,   680,   723, -1350,
   -1350, -1350, -1350,   838,    -2, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350,   724,   742,   827, -1350, -1350, -1350,   587,
     694, -1350, -1350, -1350, -1350, -1350, -1350,   728,   748,   827,
   -1350, -1350,   640,   635, -1350, -1350, -1350, -1350, -1350,    67,
      -1, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350,   733,   751,   827, -1350, -1350,
   -1350,   726,   734, -1350, -1350,   603,   581, -1350, -1350,   755,
     827, -1350,   605, -1350, -1350, -1350, -1350,   127,   607,   626,
   -1350, -1350,   756,   827,   609, -1350, -1350, -1350,   228,   505,
   -1350, -1350, -1350, -1350, -1350,   852, -1350, -1350, -1350,   696,
     189, -1350, -1350, -1350, -1350,   611,   537, -1350, -1350,   759,
     827,   627, -1350, -1350, -1350, -1350,   230,   -49, -1350, -1350,
   -1350, -1350, -1350,   858, -1350,   862, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350,   764,   827,   632, -1350,   863,   753, -1350,
   -1350, -1350, -1350,   505, -1350, -1350, -1350, -1350,   -78, -1350,
   -1350, -1350, -1350,   865, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   769,   827,
     636, -1350,   753, -1350, -1350, -1350, -1350,     8, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350,   653,   868, -1350,   800, -1350,
   -1350,   -53, -1350, -1350, -1350, -1350,   872, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350,   773,   827,   639, -1350,   753, -1350, -1350, -1350, -1350,
     505, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   713,   729,
   -1350, -1350,   743, -1350, -1350,   873, -1350, -1350, -1350,   736,
     827,   643, -1350,   753, -1350, -1350, -1350, -1350, -1350,   841,
     762, -1350,   752, -1350,   730, -1350, -1350, -1350,   735,   672,
   -1350, -1350,   746, -1350, -1350, -1350, -1350,   739,   827,   645,
   -1350,   753, -1350, -1350, -1350, -1350,   770, -1350, -1350, -1350,
     673, -1350, -1350, -1350, -1350, -1350, -1350,   737,   767, -1350,
   -1350,   757, -1350, -1350, -1350, -1350,   749,   827,   647, -1350,
     753, -1350, -1350, -1350, -1350,   775, -1350,   763, -1350, -1350,
     248, -1350,   652,    75, -1350, -1350, -1350, -1350,   704,   827,
     654, -1350,   753, -1350, -1350, -1350, -1350,   790, -1350, -1350,
   -1350,   656, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   294,
   -1350,   669,    75, -1350, -1350,   709,   827,   677, -1350,   753,
   -1350, -1350, -1350, -1350,   794, -1350, -1350, -1350, -1350, -1350,
   -1350,   347, -1350,   679,    75, -1350, -1350,   711,   827,   681,
   -1350,   753, -1350, -1350, -1350, -1350,   802, -1350, -1350, -1350,
      35, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   753, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   702,
     827,   685, -1350,   753, -1350, -1350, -1350, -1350,   803, -1350,
   -1350,   899,    48, -1350, -1350, -1350, -1350,   897,   659,     3,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350,   753, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350,   705,   827,   695,
   -1350,   753, -1350, -1350, -1350, -1350,   805, -1350, -1350,    49,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350,   753, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350,   708,   827,   697,
   -1350,   753, -1350, -1350, -1350, -1350,   806, -1350, -1350, -1350,
   -1350, -1350, -1350,   760, -1350,   772, -1350, -1350, -1350,   827,
     701, -1350,   753, -1350, -1350, -1350, -1350,   814, -1350, -1350,
   -1350,   804, -1350,   911, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350,   710, -1350,   786, -1350, -1350, -1350,   827,   725, -1350,
     753, -1350, -1350, -1350, -1350,   816, -1350, -1350, -1350,   795,
   -1350,   787, -1350, -1350, -1350,   827,   727, -1350,   753, -1350,
   -1350, -1350, -1350,   823, -1350, -1350, -1350, -1350,   731, -1350,
     753, -1350, -1350, -1350, -1350,   776, -1350, -1350, -1350, -1350,
     792,   917,   923, -1350, -1350,   754, -1350,   753, -1350, -1350,
   -1350, -1350,   788, -1350, -1350, -1350, -1350,   758, -1350,   753,
   -1350, -1350, -1350, -1350,   789, -1350, -1350,   753, -1350, -1350,
   -1350, -1350,   738, -1350, -1350, -1350, -1350, -1350,   753, -1350,
   -1350, -1350, -1350,   761, -1350, -1350,   753, -1350, -1350, -1350,
   -1350,   766, -1350, -1350,   744, -1350, -1350, -1350, -1350,   745,
   -1350, -1350,   768, -1350, -1350, -1350, -1350, -1350
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   854, -1350,
     908, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   837,
   -1350, -1350, -1350, -1350,   774, -1350, -1350, -1350, -1350, -1350,
     529, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350,   510, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   808,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
     419, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350,   712, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350,   350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350,   631, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350,   296, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350,   283, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350,   415, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350,   182, -1350, -1350, -1350,
   -1350, -1350,   128, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   -28,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350,   -69, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350,  -303, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350,  -305, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   -52,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
    -270, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,  -271,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350,   -90, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350,  -325, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350,  -327, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
      24, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
    -124, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350,   212, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350,   138, -1350, -1350, -1350, -1350,  -770, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350,  -150, -1350, -1350, -1350,
    -952, -1350, -1350, -1350, -1059,  -528, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350,  -691, -1350, -1350, -1350,  -243, -1350, -1350,
   -1350,  -597, -1350, -1350, -1350, -1350, -1350, -1350, -1350,  -127,
   -1350,  -998,  -940,   -15,   -86, -1350, -1350, -1350,  -130, -1350,
   -1350, -1350, -1350,  -664, -1350,  -887, -1350,  -369, -1349,  -209,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,   918,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1085, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350, -1350,
   -1350, -1350, -1350, -1350, -1350
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     295,   621,   261,   506,   400,   673,   741,  1479,  1146,  1480,
    1481,   806,  1278,   509,   386,   930,   391,   488,   511,  1183,
     292,  1075,   543,   491,   263,   289,   485,   540,   770,   771,
     369,   280,   277,   765,  1007,   274,   494,   495,   816,  1479,
     283,  1480,  1481,   546,   552,   286,   530,  1223,    86,  1102,
     482,   133,  1501,  1479,   549,  1480,  1481,   406,   407,  1255,
     766,   825,  1136,   826,   827,   408,     6,   225,   976,   712,
    1512,   765,  1284,   627,   672,  1171,  1085,  1079,  1086,  1087,
      20,    21,   422,   531,  1285,   423,  1256,  1277,  1225,   226,
     134,   227,   135,  1061,   136,   683,   137,   134,   766,   135,
    1530,   136,  1214,   137,  1080,   377,  1226,   385,   749,   390,
     977,  1286,   606,   607,   409,  1227,   368,  1157,   158,   159,
     684,    87,   685,  1049,   226,   228,   227,    88,     7,  1165,
    1306,    89,  1050,    90,   617,   618,  1242,  1143,   711,   229,
    1008,  1257,   303,    12,  1204,    91,   138,   643,    14,   752,
     486,   531,   550,   138,   644,    92,  1209,    93,  1328,   230,
     228,   880,   753,    94,  1080,   231,  1502,  1088,    17,   304,
     828,  1270,   606,   607,   229,  1528,   139,   748,   483,    30,
     553,    95,  1166,   139,   284,   275,  1355,   479,   817,    78,
     520,  1482,   650,   287,   230,   117,   825,   652,   826,   827,
     231,   514,   654,   281,   515,   290,   278,   305,   544,   481,
     496,   541,   525,   547,  1299,  1377,  1036,   489,   293,   492,
     772,   118,   370,  1510,   536,   537,   538,   539,  1279,   119,
     565,   120,   570,   306,   575,   158,   159,  1409,  1177,  1178,
    1220,   307,  1321,     1,     2,   158,   159,   606,   607,   374,
     375,  1386,   121,   808,   122,   308,   125,   309,  1380,  1381,
     555,   617,   618,   155,  1447,  1080,  1085,  1080,  1086,  1087,
    1348,   310,    87,   606,   607,   606,   607,   311,    88,   312,
    1425,   313,    89,   314,    90,  1080,  1477,   158,   159,    25,
      26,   160,   161,   606,   607,   212,    91,   209,   595,  1370,
     157,   213,  1455,  1486,  1419,  1420,    92,   588,    93,   304,
     589,   214,   158,   159,    94,  1396,   160,   161,  1498,   657,
     216,  1402,   658,   564,   217,   569,   215,   574,   247,   804,
     819,  1080,    95,   820,   401,   402,   403,   404,   938,   606,
     607,   939,  1514,   266,  1435,    33,    34,   305,  1440,   730,
     731,   158,   159,   606,   607,   267,  1526,  1449,  1450,   158,
     159,   606,   607,   433,   340,  1128,  1465,   617,   618,   434,
    1470,   372,  1532,   306,   609,   435,    81,    82,  1159,   620,
     436,   307,   128,   129,  1080,   382,  1544,   174,   175,  1039,
     179,   180,   606,   607,   387,   308,   392,   309,   184,   185,
     189,   190,  1491,   194,   195,  1206,   399,  1556,   199,   200,
     414,   310,   415,   728,   729,   204,   205,   311,   416,   312,
     417,   313,   418,   314,   690,   691,   692,   693,   220,   221,
     249,   250,   421,   694,   419,  1573,   442,   158,   159,   420,
    1519,   268,   269,   469,   730,   731,   158,   159,   296,   297,
     160,   161,   671,  1585,   742,   804,   342,   343,  1038,  1129,
     374,   375,   347,   348,   504,  1593,   714,   507,   715,   716,
    1537,   512,  1160,   521,   725,   730,   731,   158,   159,   606,
     607,   409,  1604,   352,   353,   357,   358,   362,   363,   394,
     395,  1549,   428,   429,  1612,   444,   445,   449,   450,  1207,
     526,  1084,  1615,   454,   455,   459,   460,   464,   465,   499,
     500,   494,   495,  1620,   556,   557,   710,   768,   769,  1566,
     422,  1623,   578,   579,   603,   604,   614,   615,  1123,   667,
     668,   706,   707,   717,   718,   743,   744,  1578,   561,  1147,
     566,  1158,   777,   785,   786,   790,   791,   740,   799,   800,
    1184,   843,   844,   949,   571,   747,  1112,   576,   796,   865,
     866,   875,   876,   888,   889,   583,   798,   584,  1205,   908,
     909,   932,   933,   585,   764,   953,   954,   587,  1224,   586,
     158,   159,   606,   607,   160,   161,  1196,  1197,  1113,  1114,
     959,   960,   965,   966,   594,   835,   617,   618,   970,   971,
    1112,   988,   989,   923,   842,   994,   995,  1020,  1021,  1030,
    1031,   598,   764,  1107,  1108,  1138,  1139,  1148,  1149,  1172,
    1173,  1191,  1192,   596,   158,   159,   606,   607,   160,   161,
     864,   807,  1113,  1114,  1115,  1116,   597,  1215,  1216,   514,
     617,   618,  1243,  1244,   599,  1112,  1271,  1272,   882,  1300,
    1301,   626,   887,  1322,  1323,  1349,  1350,  1371,  1372,   903,
     637,   898,  1388,  1389,  1403,  1404,  1412,  1413,   633,   158,
     159,   606,   607,   160,   161,   907,   634,  1113,  1114,  1427,
    1428,  1153,  1154,   639,   918,   617,   618,  1441,  1442,  1457,
    1458,  1471,  1472,   635,   931,  1492,  1493,  1505,  1506,   636,
      38,   638,   879,   640,   944,  1520,  1521,  1538,  1539,   641,
    1185,  1550,  1551,   642,   958,    39,  1395,    40,    41,    42,
     655,    43,    44,    45,   663,    46,    47,    48,   982,    49,
      50,    51,   674,    52,    53,  1567,  1568,  1579,  1580,   588,
     993,  1587,  1588,   675,    39,  1434,    40,    41,    42,   676,
      43,    44,    45,   677,    46,    47,    48,   681,    49,    50,
      51,   695,    52,    53,  1598,  1599,  1026,  1464,  1606,  1607,
     643,   678,   699,   657,  1254,   700,   698,   701,   702,   713,
     722,   726,  1387,   727,   750,   751,   758,   767,   775,   776,
     778,   753,   782,   813,   797,   810,   839,  1064,   836,   820,
     848,   849,   853,   855,   857,   870,   858,   861,   871,   884,
     881,  1426,   883,   893,   894,   900,   899,   903,   913,   914,
     906,   920,   919,   923,   926,   937,   945,   946,   975,   949,
     983,   999,   938,  1456,  1002,  1006,  1037,  1013,  1016,  1103,
    1027,   976,  1044,  1041,  1048,  1061,  1057,  1058,  1065,  1007,
    1070,  1307,  1137,  1071,  1021,  1097,  1098,  1187,  1076,  1049,
    1104,  1236,  1132,  1167,  1189,  1237,  1210,  1238,  1265,  1248,
    1249,  1186,  1266,  1281,  1282,  1294,  1295,  1308,  1283,  1314,
    1225,  1330,  1332,  1255,  1226,  1317,  1336,  1333,  1344,  1379,
    1356,  1257,  1284,  1357,  1285,  1378,  1410,  1398,  1366,  1337,
    1448,  1359,  1436,  1235,  1466,  1500,  1118,  1503,  1478,  1487,
    1547,  1499,  1515,  1527,  1545,  1533,  1546,  1560,  1557,  1156,
    1574,  1575,  1559,  1596,  1564,  1576,  1594,  1586,  1595,  1597,
    1563,   124,  1616,    77,   156,   527,   600,   273,  1605,  1613,
     522,   664,   696,   703,   795,   341,  1203,   443,   628,   248,
     850,  1028,  1625,  1626,  1077,  1621,  1338,  1340,  1066,  1309,
    1624,  1311,  1105,  1360,  1362,   984,  1190,   779,   856,  1208,
    1131,  1040,     0,   123,     0,     0,  1627,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1315,  1316,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1329,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1365,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1397,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1411,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1394,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1433,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1558,     0,     0,     0,     0,  1561,  1562,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1617,  1618
};

static const yytype_int16 yycheck[] =
{
     209,   529,   152,   372,     8,   602,   697,     4,  1067,     6,
       7,   781,     4,   382,   257,   902,   259,     6,   387,  1078,
       4,  1019,     4,     4,   154,     4,     6,     4,     6,     7,
       4,     4,     4,   724,   155,     4,     6,     7,     4,     4,
       4,     6,     7,     4,     4,     4,    76,  1106,    68,  1047,
       4,    70,     4,     4,     4,     6,     7,   266,   267,   137,
     724,    77,  1060,    79,    80,   142,     0,    72,   219,   666,
    1419,   762,   125,   171,   602,  1073,    77,    10,    79,    80,
      10,    11,   163,   181,   137,   166,   164,  1172,   137,   129,
     109,   131,   111,    18,   113,    36,   115,   109,   762,   111,
    1449,   113,  1100,   115,    37,   255,   155,   257,   705,   259,
     261,   164,    45,    46,   191,   164,   246,  1069,    43,    44,
      61,   141,    63,   125,   129,   165,   131,   147,    65,  1069,
    1215,   151,   134,   153,    59,    60,  1134,    10,   666,   179,
     261,   219,    74,    14,  1096,   165,   165,   197,    15,   172,
     130,   181,   102,   165,   204,   175,  1096,   177,  1243,   199,
     165,   852,   185,   183,    37,   205,   118,   168,    67,   101,
     186,  1169,    45,    46,   179,   126,   195,   705,   132,    69,
     140,   201,  1069,   195,   148,   154,  1271,   337,   154,    71,
     399,   156,   561,   152,   199,     5,    77,   566,    79,    80,
     205,   163,   571,   176,   166,   184,   178,   139,   190,   339,
     180,   188,   421,   174,  1212,  1300,   986,   206,   202,   200,
     198,     5,   196,   220,   433,   434,   435,   436,   220,     5,
     473,     5,   475,   165,   477,    43,    44,  1322,    10,    11,
      10,   173,  1240,    12,    13,    43,    44,    45,    46,    57,
      58,  1310,     5,   781,    66,   187,    73,   189,    10,    11,
     469,    59,    60,    68,  1349,    37,    77,    37,    79,    80,
    1268,   203,   141,    45,    46,    45,    46,   209,   147,   211,
    1339,   213,   151,   215,   153,    37,  1371,    43,    44,    10,
      11,    47,    48,    45,    46,    82,   165,    26,   507,  1297,
      31,    86,  1361,  1388,    10,    11,   175,   163,   177,   101,
     166,    90,    43,    44,   183,  1313,    47,    48,  1403,   163,
      98,  1319,   166,   473,    75,   475,    94,   477,    70,    21,
     188,    37,   201,   191,   338,   339,   340,   341,   167,    45,
      46,   170,  1427,     3,  1342,    10,    11,   139,  1346,    41,
      42,    43,    44,    45,    46,     3,  1441,    10,    11,    43,
      44,    45,    46,    17,    72,  1056,  1364,    59,    60,    23,
    1368,    10,  1457,   165,   524,    29,    10,    11,  1069,   529,
      34,   173,    10,    11,    37,    10,  1471,    10,    11,   986,
      10,    11,    45,    46,    10,   187,    10,   189,    10,    11,
      10,    11,  1400,    10,    11,  1096,     6,  1492,    10,    11,
     154,   203,   178,    10,    11,    10,    11,   209,   176,   211,
     148,   213,   152,   215,   633,   634,   635,   636,    10,    11,
      10,    11,     6,   642,   184,  1520,    74,    43,    44,   202,
    1438,    10,    11,    32,    41,    42,    43,    44,    10,    11,
      47,    48,   602,  1538,   697,    21,    10,    11,   986,  1056,
      57,    58,    10,    11,   196,  1550,   675,     3,   677,   678,
    1468,     6,  1069,   142,   683,    41,    42,    43,    44,    45,
      46,   191,  1567,    10,    11,    10,    11,    10,    11,    10,
      11,  1489,    10,    11,  1579,    10,    11,    10,    11,  1096,
     166,  1029,  1587,    10,    11,    10,    11,    10,    11,    10,
      11,     6,     7,  1598,    10,    11,   666,   726,   727,  1517,
     163,  1606,    10,    11,    10,    11,    10,    11,  1056,    10,
      11,    10,    11,    10,    11,    10,    11,  1535,    10,  1067,
      10,  1069,   751,    10,    11,    10,    11,   697,    10,    11,
    1078,    10,    11,    16,    10,   705,    19,    10,   767,    10,
      11,    10,    11,    10,    11,   132,   775,   130,  1096,    10,
      11,    10,    11,   206,   724,    10,    11,   180,  1106,   200,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      10,    11,    10,    11,   114,   804,    59,    60,    10,    11,
      19,    10,    11,    22,   813,    10,    11,   218,   219,    10,
      11,   110,   762,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   116,    43,    44,    45,    46,    47,    48,
     839,   781,    51,    52,    53,    54,   112,    10,    11,   163,
      59,    60,    10,    11,   166,    19,    10,    11,   857,    10,
      11,    76,   861,    10,    11,    10,    11,    10,    11,    33,
     188,   870,    10,    11,    10,    11,    10,    11,     6,    43,
      44,    45,    46,    47,    48,   884,     6,    51,    52,    10,
      11,    55,    56,   174,   893,    59,    60,    10,    11,    10,
      11,    10,    11,     6,   903,    10,    11,    38,    39,     6,
      66,   190,   852,   102,   913,    10,    11,    10,    11,   140,
    1079,    10,    11,     6,   923,    81,  1313,    83,    84,    85,
       6,    87,    88,    89,   166,    91,    92,    93,   937,    95,
      96,    97,   192,    99,   100,    10,    11,    10,    11,   163,
     949,    10,    11,     3,    81,  1342,    83,    84,    85,   164,
      87,    88,    89,     3,    91,    92,    93,    10,    95,    96,
      97,   204,    99,   100,    10,    11,   975,  1364,    10,    11,
     197,    30,   216,   163,  1143,   212,   214,   210,   166,   164,
     187,     3,  1310,     3,   164,     6,   153,     6,     3,   164,
     172,   185,   221,    28,   198,   157,    25,  1006,   127,   191,
     154,   188,     5,   186,     6,     6,   169,    24,   260,    27,
      78,  1339,   182,     6,   260,   217,   222,    33,     6,   133,
     192,   121,   158,    22,   121,     6,   128,   121,     6,    16,
     170,   163,   167,  1361,   119,     6,   986,   163,   119,  1048,
     261,   219,   119,   163,     6,    18,   122,   105,   261,   155,
     122,  1220,  1061,   105,   219,   122,   105,     5,   218,   125,
     134,     3,   107,   107,   168,     3,   107,   103,     3,     6,
     117,  1080,   103,   220,     6,     3,   103,   164,    78,     6,
     137,    40,   120,   137,   155,   149,   156,   135,   149,   126,
     120,   219,   125,   220,   137,   120,   106,   193,   149,   164,
     106,   164,   193,  1112,   193,     6,  1056,    10,   106,   207,
     138,   108,   207,   108,   108,   207,   156,     6,   104,  1069,
     104,   126,   118,     6,   138,   138,   150,   104,   136,     6,
     220,    77,   194,    25,    97,   425,   517,   163,   150,   150,
     411,   591,   646,   660,   762,   233,  1096,   316,   533,   141,
     822,   979,   208,   208,  1023,   194,  1259,  1262,  1010,  1229,
     194,  1232,  1052,  1288,  1291,   941,  1090,   755,   830,  1096,
    1056,   986,    -1,    55,    -1,    -1,   208,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1236,  1237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1282,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1294,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1314,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1313,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1500,    -1,    -1,    -1,    -1,  1505,  1506,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1596,  1597
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   343,   344,   345,     0,    65,   352,   353,
    1114,  1115,    14,   346,    15,   350,   351,    67,   354,   355,
      10,    11,  1116,  1117,  1118,    10,    11,   347,   348,   349,
      69,   434,   435,    10,    11,   356,   357,   358,    66,    81,
      83,    84,    85,    87,    88,    89,    91,    92,    93,    95,
      96,    97,    99,   100,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1139,  1140,  1141,   352,    71,   488,
     489,    10,    11,   436,   437,   438,    68,   141,   147,   151,
     153,   165,   175,   177,   183,   201,   359,   360,   361,   362,
     363,   378,   379,   384,   385,   390,   391,   396,   397,   402,
     403,   408,   409,   414,   415,   420,   421,     5,     5,     5,
       5,     5,    66,  1121,   350,    73,   540,   541,    10,    11,
     490,   491,   492,    70,   109,   111,   113,   115,   165,   195,
     439,   440,   441,   442,   443,   448,   449,   455,   456,   462,
     463,   469,   470,   474,   475,    68,   361,    31,    43,    44,
      47,    48,   364,   365,   366,  1058,  1059,  1060,  1061,  1075,
    1076,  1077,  1078,  1105,    10,    11,   380,   381,   382,    10,
      11,   386,   387,   388,    10,    11,   392,   393,   394,    10,
      11,   398,   399,   400,    10,    11,   404,   405,   406,    10,
      11,   410,   411,   412,    10,    11,   416,   417,   418,    26,
     422,  1100,    82,    86,    90,    94,    98,    75,   635,   636,
      10,    11,   542,   543,   544,    72,   129,   131,   165,   179,
     199,   205,   493,   494,   495,   496,   497,   502,   503,   508,
     509,   514,   515,   520,   521,   526,   527,    70,   441,    10,
      11,   444,   445,   446,   450,   451,   457,   458,   464,   465,
     471,  1058,   476,  1100,  1111,  1112,     3,     3,    10,    11,
     367,   368,   369,   366,     4,   154,   383,     4,   178,   389,
       4,   176,   395,     4,   148,   401,     4,   152,   407,     4,
     184,   413,     4,   202,   419,  1111,    10,    11,   423,   424,
     425,   637,   638,    74,   101,   139,   165,   173,   187,   189,
     203,   209,   211,   213,   215,   545,   546,   547,   548,   549,
     554,   555,   560,   561,   566,   567,   572,   573,   578,   579,
     595,   596,   602,   603,   609,   610,   616,   617,   621,   622,
      72,   495,    10,    11,   498,   499,   500,    10,    11,   504,
     505,   506,    10,    11,   510,   511,   512,    10,    11,   516,
     517,   518,    10,    11,   522,   523,   524,   528,  1100,     4,
     196,   447,    10,   453,    57,    58,   452,  1058,  1079,  1080,
    1081,  1082,    10,   460,   459,  1058,  1079,    10,   467,   466,
    1058,  1079,    10,   472,    10,    11,   477,   478,   479,     6,
       8,   338,   339,   340,   341,  1113,  1111,  1111,   142,   191,
     370,   371,   372,   373,   154,   178,   176,   148,   152,   184,
     202,     6,   163,   166,   426,   427,   428,   429,    10,    11,
     640,   641,   642,    17,    23,    29,    34,   639,  1092,  1097,
    1103,  1108,    74,   547,    10,    11,   550,   551,   552,    10,
      11,   556,   557,   558,    10,    11,   562,   563,   564,    10,
      11,   568,   569,   570,    10,    11,   574,   575,   576,    32,
     580,  1106,   597,   598,   604,   605,   611,   612,   618,  1058,
     623,  1100,     4,   132,   501,     6,   130,   507,     6,   206,
     513,     4,   200,   519,     6,     7,   180,   525,  1109,    10,
      11,   529,   530,   531,   196,   454,  1109,     3,   461,  1109,
     468,  1109,     6,   473,   163,   166,   480,   481,   482,   483,
    1111,   142,   372,   374,   375,  1111,   166,   428,   430,   431,
      76,   181,   643,   644,   645,   646,  1111,  1111,  1111,  1111,
       4,   188,   553,     4,   190,   559,     4,   174,   565,     4,
     102,   571,     4,   140,   577,  1111,    10,    11,   581,   582,
     583,    10,   600,   599,  1058,  1079,    10,   607,   606,  1058,
    1079,    10,   614,   613,  1058,  1079,    10,   619,    10,    11,
     624,   625,   626,   132,   130,   206,   200,   180,   163,   166,
     532,   533,   534,   535,   114,  1111,   116,   112,   110,   166,
     482,   484,   485,    10,    11,   377,    45,    46,   376,  1058,
    1067,  1068,  1069,  1070,    10,    11,   433,    59,    60,   432,
    1058,  1067,  1083,  1084,  1085,  1086,    76,   171,   645,  1027,
    1028,   647,   648,     6,     6,     6,     6,   188,   190,   174,
     102,   140,     6,   197,   204,   584,   585,   586,   587,   601,
    1109,   608,  1109,   615,  1109,     6,   620,   163,   166,   627,
     628,   629,   630,   166,   534,   536,   537,    10,    11,   487,
     486,  1058,  1067,  1083,   192,     3,   164,     3,    30,  1029,
    1104,    10,   653,    36,    61,    63,   649,   650,   651,   652,
    1111,  1111,  1111,  1111,  1111,   204,   586,   588,   214,   216,
     212,   210,   166,   629,   631,   632,    10,    11,   539,   538,
    1058,  1067,  1083,   164,  1111,  1111,  1111,    10,    11,  1030,
    1031,  1032,   187,   654,   655,  1111,     3,     3,    10,    11,
      41,    42,   589,   590,   591,   592,  1050,  1051,  1052,  1053,
    1058,  1075,  1079,    10,    11,   634,   633,  1058,  1067,  1083,
     164,     6,   172,   185,  1033,  1034,  1035,  1036,   153,   670,
     671,   656,   657,   658,  1058,  1075,  1105,     6,  1111,  1111,
       6,     7,   198,   593,   594,     3,   164,  1111,   172,  1035,
    1037,  1038,   221,   676,   677,    10,    11,   672,   673,   674,
      10,    11,   659,   660,   661,   658,  1111,   198,  1111,    10,
      11,  1040,  1041,  1042,    21,  1039,  1050,  1058,  1067,  1095,
     157,   796,   797,    28,   678,  1102,     4,   154,   675,   188,
     191,   662,   663,   664,   665,    77,    79,    80,   186,  1043,
    1044,  1045,  1046,  1047,  1048,  1111,   127,   900,   901,    25,
     798,  1099,  1111,    10,    11,   679,   680,   681,   154,   188,
     664,   666,   667,     5,  1049,   186,  1045,     6,   169,  1004,
    1005,    24,   902,  1098,  1111,    10,    11,   799,   800,   801,
       6,   260,   682,   683,   684,    10,    11,   669,   668,  1058,
    1075,    78,  1111,   182,    27,  1006,  1101,  1111,    10,    11,
     903,   904,   905,     6,   260,   802,   803,   804,  1111,   222,
     217,   696,   697,    33,   685,  1107,   192,  1111,    10,    11,
    1007,  1008,  1009,     6,   133,   906,   907,   908,  1111,   158,
     121,   816,   817,    22,   805,  1096,   121,   712,   713,   698,
    1107,  1111,    10,    11,   686,   687,   688,     6,   167,   170,
    1010,  1011,  1012,  1013,  1111,   128,   121,   920,   921,    16,
     909,  1091,   871,    10,    11,   818,   819,   820,  1111,    10,
      11,   806,   807,   808,   767,    10,    11,   714,   715,   716,
      10,    11,   699,   700,   701,     6,   219,   261,   689,   690,
     691,   692,  1111,   170,  1012,  1014,  1015,   975,    10,    11,
     922,   923,   924,  1111,    10,    11,   910,   911,   912,   163,
     872,   873,   119,   821,   822,   823,     6,   155,   261,   809,
     810,   811,   812,   163,   768,   769,   119,   717,   718,   719,
     218,   219,   702,   703,   704,   705,  1111,   261,   691,   693,
      10,    11,  1017,  1018,  1019,  1016,  1050,  1058,  1067,  1083,
    1095,   163,   976,   977,   119,   925,   926,   927,     6,   125,
     134,   913,   914,   915,   916,   874,   875,   122,   105,   829,
     830,    18,   824,  1093,  1111,   261,   811,   813,   770,   771,
     122,   105,   725,   726,   720,  1093,   218,   704,   706,    10,
      37,   694,   695,  1066,  1067,    77,    79,    80,   168,  1020,
    1021,  1022,  1023,  1024,  1025,   978,   979,   122,   105,   933,
     934,   928,  1093,  1111,   134,   915,   917,    10,    11,   877,
     878,   879,    19,    51,    52,    53,    54,   876,  1058,  1062,
    1063,  1064,  1065,  1067,  1071,  1072,  1073,  1074,  1075,  1083,
    1094,  1096,   107,   836,   837,   831,  1093,  1111,    10,    11,
     825,   826,   827,    10,   814,   815,  1066,  1067,    10,    11,
     773,   774,   775,    55,    56,   772,  1058,  1062,  1067,  1075,
    1083,  1087,  1088,  1089,  1090,  1094,  1107,   107,   732,   733,
     727,  1093,    10,    11,   721,   722,   723,    10,    11,   707,
     708,   709,   710,  1066,  1067,  1109,  1111,     5,  1026,   168,
    1022,    10,    11,   981,   982,   983,    49,    50,   980,  1054,
    1055,  1056,  1057,  1058,  1062,  1067,  1075,  1083,  1091,  1094,
     107,   940,   941,   935,  1093,    10,    11,   929,   930,   931,
      10,   918,   919,  1066,  1067,   137,   155,   164,   880,   881,
     882,   883,   890,   891,   892,  1111,     3,     3,   103,   843,
     844,   838,  1093,    10,    11,   832,   833,   834,     6,   117,
     828,  1142,  1143,  1150,  1109,   137,   164,   219,   776,   777,
     778,   779,   786,   787,   788,     3,   103,   739,   740,   734,
    1093,    10,    11,   728,   729,   730,   724,  1142,     4,   220,
     711,   220,     6,    78,   125,   137,   164,   984,   985,   986,
     987,   994,   995,   996,     3,   103,   947,   948,   942,  1093,
      10,    11,   936,   937,   938,   932,  1142,  1109,   164,   882,
     884,   891,   893,   894,     6,  1111,  1111,   149,   850,   851,
     845,  1093,    10,    11,   839,   840,   841,   835,  1142,  1111,
      40,  1151,   120,   135,  1144,  1145,   156,   164,   778,   780,
     787,   789,   790,  1111,   149,   746,   747,   741,  1093,    10,
      11,   735,   736,   737,   731,  1142,   120,   220,  1111,   164,
     986,   988,   995,   997,   998,  1111,   149,   954,   955,   949,
    1093,    10,    11,   943,   944,   945,   939,  1142,   120,   126,
      10,    11,   885,   886,   887,   888,  1066,  1067,    10,    11,
     896,   897,   898,   895,  1058,  1083,  1093,  1111,   193,   857,
     858,   852,  1093,    10,    11,   846,   847,   848,   842,  1142,
     106,  1111,    10,    11,  1152,  1153,  1154,  1146,  1147,    10,
      11,   781,   782,   783,   784,  1066,  1067,    10,    11,   792,
     793,   794,   791,  1058,  1083,  1093,   193,   753,   754,   748,
    1093,    10,    11,   742,   743,   744,   738,  1142,   106,    10,
      11,   989,   990,   991,   992,  1066,  1067,    10,    11,  1000,
    1001,  1002,   999,  1058,  1083,  1093,   193,   961,   962,   956,
    1093,    10,    11,   950,   951,   952,   946,  1142,   106,     4,
       6,     7,   156,   889,  1110,   899,  1142,   207,   864,   865,
     859,  1093,    10,    11,   853,   854,   855,   849,  1142,   108,
       6,     4,   118,    10,  1149,    38,    39,  1148,  1155,  1156,
     220,   785,  1110,   795,  1142,   207,   760,   761,   755,  1093,
      10,    11,   749,   750,   751,   745,  1142,   108,   126,   993,
    1110,  1003,  1142,   207,   968,   969,   963,  1093,    10,    11,
     957,   958,   959,   953,  1142,   108,   156,   138,   866,  1093,
      10,    11,   860,   861,   862,   856,  1142,   104,  1111,   118,
       6,  1111,  1111,   220,   138,   762,  1093,    10,    11,   756,
     757,   758,   752,  1142,   104,   126,   138,   970,  1093,    10,
      11,   964,   965,   966,   960,  1142,   104,    10,    11,   867,
     868,   869,   863,  1142,   150,   136,     6,     6,    10,    11,
     763,   764,   765,   759,  1142,   150,    10,    11,   971,   972,
     973,   967,  1142,   150,   870,  1142,   194,  1111,  1111,   766,
    1142,   194,   974,  1142,   194,   208,   208,   208
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
      yyerror (&yylloc, osresult, parserData, osglData, osnlData, YY_("syntax error: cannot back up")); \
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
		  Type, Value, Location, osresult, parserData, osglData, osnlData); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData, osglData, osnlData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osresult);
  YYUSE (parserData);
  YYUSE (osglData);
  YYUSE (osnlData);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData, osglData, osnlData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData, osglData, osnlData);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osresult, parserData, osglData, osnlData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osresult, parserData, osglData, osnlData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osresult, parserData, osglData, osnlData); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osresult, parserData, osglData, osnlData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osresult);
  YYUSE (parserData);
  YYUSE (osglData);
  YYUSE (osnlData);

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
int yyparse (OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData);
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
yyparse (OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
int
yyparse (osresult, parserData, osglData, osnlData)
    OSResult *osresult;
    OSrLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
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
            parserData->parser_errors += ("\n\nOSrL input is either not valid or well formed.\n"); 
            osrlerror( NULL, osresult, parserData, osglData, osnlData, parserData->parser_errors);
        }
    }
    break;

  case 14:

    { parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "unexpected end of file, expecting </osol>");}
    break;

  case 17:

    {
    if (!osresult->setHeader(osglData->fileName, osglData->source,     
            osglData->description, osglData->fileCreator, osglData->licence) )    
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "setHeader failed");
}
    break;

  case 20:

    {
    parserData->generalStatusPresent        = false;    
    parserData->generalMessagePresent       = false;
    parserData->generalServiceURIPresent    = false;
    parserData->generalServiceNamePresent   = false;
    parserData->generalInstanceNamePresent  = false;
    parserData->generalJobIDPresent         = false;
    parserData->generalSolverInvokedPresent = false;
    parserData->generalTimeStampPresent     = false;
    parserData->otherGeneralResultsPresent  = false;
    osresult->general = new GeneralResult();
}
    break;

  case 39:

    {
        if (parserData->generalStatusPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one generalStatus element allowed");    
        if (osresult->general->generalStatus != NULL) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "generalStatus previously allocated");
        parserData->generalStatusPresent = true;
        parserData->typeAttributePresent = false;
        parserData->descriptionAttributePresent = false;
        parserData->numberAttributePresent = false;
        parserData->numberOf = 0;
        parserData->typeAttribute = "";
        parserData->descriptionAttribute = "";
    }
    break;

  case 40:

    {
        if (!parserData->typeAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "type attribute must be present for generalStatus element");
        parserData->kounter = 0;
    }
    break;

  case 43:

    { 
        if (osresult->setGeneralStatusType(parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "general status type does not match any legal value");
    }
    break;

  case 44:

    {   
        osresult->setGeneralStatusDescription(parserData->descriptionAttribute);
    }
    break;

  case 45:

    {
       if (osresult->setNumberOfGeneralSubstatuses(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "Attempting to reallocate substatus array. Potential loss of data.");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 46:

    {    if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <substatus> element");
    }
    break;

  case 47:

    {    if (parserData->kounter != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <substatus> elements than specified");
    }
    break;

  case 54:

    {
    parserData->kounter++;
}
    break;

  case 55:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror( NULL, NULL, parserData, osglData, osnlData, "more <substatus> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 56:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<substatus> must have name attribute");
}
    break;

  case 59:

    {    
        if (osresult->setGeneralSubstatusName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "Error while setting <general> substatus name");
    }
    break;

  case 60:

    {    
        if (osresult->setGeneralSubstatusDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "Error while setting <general> substatus description");
    }
    break;

  case 64:

    {
        if (parserData->generalMessagePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one message element allowed");
        parserData->generalMessagePresent = true;
    }
    break;

  case 70:

    {osresult->setGeneralMessage((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;}
    break;

  case 72:

    {
        if (parserData->generalServiceURIPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one serviceURI element allowed");
        parserData->generalServiceURIPresent = true;
    }
    break;

  case 78:

    {
        osresult->setServiceURI((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 80:

    {
        if (parserData->generalServiceNamePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one serviceName element allowed");
        parserData->generalServiceNamePresent = true;
    }
    break;

  case 86:

    {
        osresult->setServiceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 88:

    {
        if (parserData->generalInstanceNamePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one instanceName element allowed");
        parserData->generalInstanceNamePresent = true;
    }
    break;

  case 94:

    {
        osresult->setInstanceName((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 96:

    {
        if (parserData->generalJobIDPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one jobID element allowed");
        parserData->generalJobIDPresent = true;
    }
    break;

  case 102:

    {
        osresult->setJobID((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 104:

    {
        if (parserData->generalSolverInvokedPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one solverInvoked element allowed");
        parserData->generalSolverInvokedPresent = true;
    }
    break;

  case 110:

    {
        osresult->setSolverInvoked((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 112:

    {
        if (parserData->generalTimeStampPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one timeStamp element allowed");
        parserData->generalTimeStampPresent = true;
    }
    break;

  case 118:

    {
        osresult->setTimeStamp((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 120:

    {
        if (parserData->otherGeneralResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one general other results element allowed");
        parserData->otherGeneralResultsPresent = true;
    }
    break;

  case 121:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other general results cannot be negative");
    if (osresult->setNumberOfOtherGeneralResults(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "Attempting to reallocate other general results array. Potential loss of data.");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 122:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 123:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 130:

    {
    parserData->kounter++;
}
    break;

  case 131:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <other> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 132:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 135:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherGeneralResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setGeneralOtherResultName failed");
    }
    break;

  case 136:

    {    
        if (osresult->setOtherGeneralResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setGeneralOtherResultValue failed");
    }
    break;

  case 137:

    {    
        if (osresult->setOtherGeneralResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setGeneralOtherResultDescription failed");
    }
    break;

  case 142:

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

  case 158:

    {
        if (parserData->systemInformationPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one systemInformation element allowed");
        parserData->systemInformationPresent = true;
    }
    break;

  case 164:

    {
        osresult->setSystemInformation((yyvsp[(1) - (1)].sval)); 
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 166:

    {
        if (parserData->systemAvailableDiskSpacePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one availableDiskSpace element allowed");
        parserData->systemAvailableDiskSpacePresent = true;    
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 170:

    {
        if (osresult->setAvailableDiskSpaceUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 171:

    {
        osresult->setAvailableDiskSpaceDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 173:

    {
    osresult->setAvailableDiskSpaceValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 175:

    {
        if (parserData->systemAvailableMemoryPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one availableMemory element allowed");
        parserData->systemAvailableMemoryPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 179:

    {
        if (osresult->setAvailableMemoryUnit( parserData->unitAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 180:

    {
        osresult->setAvailableMemoryDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 182:

    {
    osresult->setAvailableMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 184:

    {
        if (parserData->systemAvailableCPUSpeedPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one availableCPUSpeed element allowed");
        parserData->systemAvailableCPUSpeedPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 188:

    {
        if (osresult->setAvailableCPUSpeedUnit( parserData->unitAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "available CPU Speed could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 189:

    {
        osresult->setAvailableCPUSpeedDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 191:

    {
    osresult->setAvailableCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 193:

    {
        if (parserData->systemAvailableCPUNumberPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one availableCPUNumber element allowed");
        parserData->systemAvailableCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 195:

    {
        osresult->setAvailableCPUNumberDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 197:

    {
    osresult->setAvailableCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL;
}
    break;

  case 199:

    {
        if (parserData->otherSystemResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one system other results element allowed");
        parserData->otherSystemResultsPresent = true;
    }
    break;

  case 200:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other system results cannot be negative");
    if (osresult->setNumberOfOtherSystemResults(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherSystemResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 201:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 202:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 209:

    {
    parserData->kounter++;
}
    break;

  case 210:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <other> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 211:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 214:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherSystemResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSystemOtherResultName failed");
    }
    break;

  case 215:

    {    
        if (osresult->setOtherSystemResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSystemOtherResultValue failed");
    }
    break;

  case 216:

    {    
        if (osresult->setOtherSystemResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSystemOtherResultDescription failed");
    }
    break;

  case 221:

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

  case 237:

    {
        if (parserData->serviceCurrentStatePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one currentState element allowed");
        parserData->serviceCurrentStatePresent = true;
    }
    break;

  case 243:

    {
       parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
        if (osresult->setCurrentState(parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setCurrentState failed; current system state not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 245:

    {
        if (parserData->serviceCurrentJobCountPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one currentJobCount element allowed");
        parserData->serviceCurrentJobCountPresent = true;
    }
    break;

  case 251:

    {
        osresult->setCurrentJobCount((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL;
    }
    break;

  case 253:

    {
        if (parserData->serviceTotalJobsSoFarPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one totalJobsSoFar element allowed");
        parserData->serviceTotalJobsSoFarPresent = true;
    }
    break;

  case 259:

    {
        osresult->setTotalJobsSoFar((yyvsp[(1) - (1)].ival)); parserData->errorText = NULL; 
    }
    break;

  case 261:

    {
        if (parserData->timeServiceStartedPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one timeServiceStarted element allowed");
        parserData->timeServiceStartedPresent = true;
    }
    break;

  case 267:

    {
        osresult->setTimeServiceStarted((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 269:

    {
        if (parserData->serviceUtilizationPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one serviceUtilization element allowed");
        parserData->serviceUtilizationPresent = true;
    }
    break;

  case 275:

    {
    if (osresult->setServiceUtilization( parserData->tempVal) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setServiceUtilization failed");
    parserData->errorText = NULL;
}
    break;

  case 277:

    {
        if (parserData->otherServiceResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one service other results element allowed");
        parserData->otherServiceResultsPresent = true;
    }
    break;

  case 278:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other service results cannot be negative");
    if (osresult->setNumberOfOtherServiceResults(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherServiceResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 279:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 280:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 287:

    {
    parserData->kounter++;
}
    break;

  case 288:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <other> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 289:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 292:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherServiceResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setServiceOtherResultName failed");
    }
    break;

  case 293:

    {    
        if (osresult->setOtherServiceResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setServiceOtherResultValue failed");
    }
    break;

  case 294:

    {    
        if (osresult->setOtherServiceResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setServiceOtherResultDescription failed");
    }
    break;

  case 299:

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

  case 320:

    {
        if (parserData->jobStatusPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one job status element allowed");
        parserData->jobStatusPresent = true;
    }
    break;

  case 326:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
        if (osresult->setJobStatus(parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setJobStatus failed");
        parserData->errorText = NULL;
    }
    break;

  case 328:

    {
        if (parserData->jobSubmitTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one submitTime element allowed");
        parserData->jobSubmitTimePresent = true;
    }
    break;

  case 334:

    {
        osresult->setJobSubmitTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 336:

    {
        if (parserData->scheduledStartTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one scheduledStartTime element allowed");
        parserData->scheduledStartTimePresent = true;
    }
    break;

  case 342:

    {
        osresult->setScheduledStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); parserData->errorText = NULL;
    }
    break;

  case 344:

    {
        if (parserData->actualStartTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one actualStartTime element allowed");
        parserData->actualStartTimePresent = true;
    }
    break;

  case 350:

    {
        osresult->setActualStartTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;
    }
    break;

  case 352:

    {
        if (parserData->jobEndTimePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one job endTime element allowed");
        parserData->jobEndTimePresent = true;
    }
    break;

  case 358:

    {
        osresult->setJobEndTime((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval));  parserData->errorText = NULL;
    }
    break;

  case 360:

    {
        if (parserData->jobTimingInformationPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one timingInformation element allowed");
        parserData->jobTimingInformationPresent = true;
    }
    break;

  case 361:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of time measurements cannot be negative");
    if (osresult->setNumberOfTimes(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfTimes failed");
    parserData->numberOfTimes = parserData->tempInt;
    parserData->ivar = 0;
}
    break;

  case 362:

    {
        if (parserData->numberOfTimes > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <time> element");
    }
    break;

  case 363:

    {
        if (parserData->ivar != parserData->numberOfTimes)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <time> elements than specified");
    }
    break;

  case 371:

    {
    if (parserData->ivar >= parserData->numberOfTimes)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <time> elements than specified");
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

  case 383:

    {    
    if (osresult->setTimingInformation(parserData->ivar, parserData->typeAttribute, parserData->categoryAttribute,
        parserData->unitAttribute, parserData->descriptionAttribute, parserData->timeValue) == false)       
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "timing information could not be stored");
    parserData->ivar++;
}
    break;

  case 384:

    { parserData->timeValue = (yyvsp[(1) - (1)].dval); }
    break;

  case 385:

    { parserData->timeValue = (yyvsp[(1) - (1)].ival); }
    break;

  case 387:

    {
        if (parserData->jobUsedDiskSpacePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one usedDiskSpace element allowed");
        parserData->jobUsedDiskSpacePresent = true;        
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;
        parserData->unitAttribute = "";
        parserData->descriptionAttribute = "";
    }
    break;

  case 391:

    {
        if (osresult->setUsedDiskSpaceUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableDiskSpace unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 392:

    {
        osresult->setUsedDiskSpaceDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 394:

    {
    osresult->setUsedDiskSpaceValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 396:

    {
        if (parserData->jobUsedMemoryPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one usedMemory element allowed");
        parserData->jobUsedMemoryPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "";
        parserData->descriptionAttribute = "";
    }
    break;

  case 400:

    {
        if (osresult->setUsedMemoryUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "usedMemory unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 401:

    {
        osresult->setUsedMemoryDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 403:

    {
    osresult->setUsedMemoryValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 405:

    {
        if (parserData->jobUsedCPUSpeedPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one usedCPUSpeed element allowed");
        parserData->jobUsedCPUSpeedPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "";    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 409:

    {
        if (osresult->setUsedCPUSpeedUnit( parserData->unitAttribute) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableCPUSpeed unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 410:

    {
        osresult->setUsedCPUSpeedDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 412:

    {
    osresult->setUsedCPUSpeedValue(parserData->tempVal);  
    parserData->errorText = NULL;
}
    break;

  case 414:

    {
        if (parserData->jobUsedCPUNumberPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one usedCPUNumber element allowed");
        parserData->jobUsedCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 416:

    {
        osresult->setUsedCPUNumberDescription( parserData->descriptionAttribute); 
        parserData->errorText = NULL;
    }
    break;

  case 418:

    { 
    osresult->setUsedCPUNumberValue( (yyvsp[(1) - (1)].ival));  parserData->errorText = NULL; 
}
    break;

  case 420:

    {
        if (parserData->otherJobResultsPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one job other results element allowed");
        parserData->otherJobResultsPresent = true;
    }
    break;

  case 421:

    {
    if (parserData->tempInt < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other job results cannot be negative");
    if (osresult->setNumberOfOtherJobResults(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherJobResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 422:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 423:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 430:

    {
    parserData->kounter++;
}
    break;

  case 431:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <other> elements than specified");
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 432:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 435:

    {
        if (parserData->nameAttribute.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherJobResultName(parserData->kounter, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setJobOtherResultName failed");
    }
    break;

  case 436:

    {    
        if (osresult->setOtherJobResultValue(parserData->kounter, parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setJobOtherResultValue failed");
    }
    break;

  case 437:

    {    
        if (osresult->setOtherJobResultDescription(parserData->kounter, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setJobOtherResultDescription failed");
    }
    break;

  case 442:

    {
    parserData->numberAttributePresent = false;
    parserData->nVarPresent = false;
    parserData->nObjPresent = false;
    parserData->nConPresent = false;
}
    break;

  case 443:

    {
    if (!parserData->numberAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "numberOfSolutions was never set");
}
    break;

  case 446:

    {
        parserData->numberOfSolutions = parserData->tempInt; 
        if (osresult->setSolutionNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionNumber failed");
        parserData->solutionIdx = 0;
    }
    break;

  case 447:

    {    
        parserData->numberOfVariables = parserData->tempInt; 
        if (osresult->setVariableNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setVariableNumber failed");
    }
    break;

  case 448:

    {
        parserData->numberOfConstraints = parserData->tempInt; 
        if (osresult->setConstraintNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setConstraintNumber failed");
    }
    break;

  case 449:

    {    
        parserData->numberOfObjectives = parserData->tempInt; 
        if (osresult->setObjectiveNumber(parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setObjectiveNumber failed");
    }
    break;

  case 450:

    {
        if (parserData->numberOfSolutions > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <solution> element");
    }
    break;

  case 451:

    {
        if (parserData->solutionIdx != parserData->numberOfSolutions)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <solution> elements than specified");
    }
    break;

  case 459:

    {
    if (parserData->solutionIdx >= parserData->numberOfSolutions) 
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "too many solutions"); 
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->weightedObjAttributePresent = false;
}
    break;

  case 466:

    {
    if (parserData->idxAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "target objective idx previously set");
    parserData->idxAttributePresent = true;
    if((yyvsp[(3) - (4)].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "target objective index must be negative");
      if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[(3) - (4)].ival)) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionTargetObjectiveIdx failed");
 }
    break;

  case 467:

    {
    if (parserData->nameAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "target objective name previously set");
    parserData->nameAttributePresent = true;
    parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
      if (osresult->setSolutionTargetObjectiveName(parserData->solutionIdx, parserData->tempStr) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionTargetObjectiveName failed");
 }
    break;

  case 468:

    {
    if (parserData->weightedObjAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "weighted objective attribute previously set");
    parserData->weightedObjAttributePresent = true;
    parserData->tempStr = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
    if (parserData->tempStr == "true")
    {
          if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, true) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionWeightedObjectives failed");
    }
    else if (parserData->tempStr == "false")
    {
          if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, false) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionWeightedObjectives failed");
    }
    else
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "weightedobjectives must be true or false");
}
    break;

  case 469:

    {
        parserData->solutionIdx++;
    }
    break;

  case 471:

    {
        parserData->typeAttributePresent = false;
        parserData->descriptionAttributePresent = false;
        parserData->numberAttributePresent = false;
        parserData->numberOf = 0;
        parserData->typeAttribute = "";
        parserData->descriptionAttribute = "";
    }
    break;

  case 472:

    {
        if (!parserData->typeAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "type attribute must be present for solution status element");
    }
    break;

  case 475:

    {   
        if (osresult->setSolutionStatusType(parserData->solutionIdx, parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionStatusType failed");
    }
    break;

  case 476:

    {
       if (osresult->setSolutionStatusDescription(parserData->solutionIdx, parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionStatusDescription failed");
    }
    break;

  case 477:

    {
        if (osresult->setNumberOfSolutionSubstatuses(parserData->solutionIdx, parserData->tempInt) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfSolutionSubstatuses failed");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 478:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <substatus> element");
    }
    break;

  case 479:

    {
        if (parserData->kounter != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <substatus> elements than specified");
    }
    break;

  case 486:

    {
    parserData->kounter++; 
}
    break;

  case 487:

    {
    if (parserData->kounter >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <substatus> elements than specified");
    parserData->typeAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->typeAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 488:

    {
    if (!parserData->typeAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<substatus> must have type attribute");
}
    break;

  case 491:

    {    
        if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
                                               parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionSubstatusType failed");
    }
    break;

  case 492:

    {    
        if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
                                                      parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionSubstatusDescription failed");
    }
    break;

  case 503:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
        osresult->setSolutionMessage(parserData->solutionIdx, parserData->tempStr);
        parserData->errorText = NULL;
    }
    break;

  case 506:

    {
    parserData->numberOfOtherVariableResults = 0;
    osresult->optimization->solution[parserData->solutionIdx]->variables = new VariableSolution();
}
    break;

  case 508:

    {    
    if (osresult->setNumberOfOtherVariableResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherVariableResults failed");
    parserData->numberOfOtherVariableResults = parserData->tempInt;
    parserData->iOther = 0;
}
    break;

  case 517:

    {
    if (osresult->setNumberOfVarValues(parserData->solutionIdx, parserData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfVarValues failed");
    parserData->kounter = 0;
}
    break;

  case 518:

    {
        if (parserData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <var> element");
    }
    break;

  case 519:

    {
        if (parserData->kounter != parserData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <var> elements than specified");
    }
    break;

  case 526:

    {
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
                              parserData->idx,         parserData->nameAttribute,
                              parserData->tempVal                           ) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setVarValue failed");
    parserData->kounter++;
}
    break;

  case 527:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 536:

    {
    if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, parserData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfVarValuesString failed");
    parserData->kounter = 0;
}
    break;

  case 537:

    {
        if (parserData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <var> element");
    }
    break;

  case 538:

    {
        if (parserData->kounter != parserData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <var> elements than specified");
    }
    break;

  case 545:

    {
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
                                     parserData->idx,         parserData->nameAttribute,
                                    parserData->tempStr                           ) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setVarValueString failed");
    parserData->kounter++;
}
    break;

  case 546:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 551:

    {parserData->tempStr = "";}
    break;

  case 556:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    }
    break;

  case 559:

    {
    osresult->optimization->solution[parserData->solutionIdx]->variables->basisStatus = new BasisStatus();
}
    break;

  case 566:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 568:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 575:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 577:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 584:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 586:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 593:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 595:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 602:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 604:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 611:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 613:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 620:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 622:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 630:

    {      
        parserData->iOther++;
    }
    break;

  case 631:

    {
    if (parserData->iOther >= parserData->numberOfOtherVariableResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherVariableResults> than specified");
    parserData->nameAttributePresent = false;    
    parserData->numberOfVarAttributePresent = false;    
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->typeAttributePresent = false;
    parserData->varTypeAttributePresent = false;
    parserData->enumTypeAttributePresent = false;
    parserData->descriptionAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->typeAttribute = "";
    parserData->varTypeAttribute = "";
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttribute = "";    
}
    break;

  case 632:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element requires name attribute"); 
    }
    break;

  case 635:

    {
        if (parserData->numberOfVarAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfVar attribute previously set");
        parserData->numberOfVarAttributePresent = true;
         if (osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         parserData->numberOfVar) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultNumberOfVar failed");
        parserData->kounter = 0;
    }
    break;

  case 636:

    {
        if (parserData->numberOfEnumerationsAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
        parserData->numberOfEnumerationsAttributePresent = true;
         if (osresult->setOtherVariableResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         parserData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }
    break;

  case 637:

    {    
         if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
                                                   parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultValue failed");
    }
    break;

  case 638:

    {    
         if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultName failed");
    }
    break;

  case 639:

    {    
         if (osresult->setOtherVariableResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultType failed");
    }
    break;

  case 640:

    {    
         if (osresult->setOtherVariableResultVarType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->varTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVarType failed");
    }
    break;

  case 641:

    {    
         if (osresult->setOtherVariableResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultEnumType failed");
    }
    break;

  case 642:

    {    
         if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                         parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultDescription failed");
    }
    break;

  case 652:

    {     
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    parserData->kounter++;
}
    break;

  case 653:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <var> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 656:

    {    
         if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->idx) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVarIdx failed");
    }
    break;

  case 657:

    {    
         if (osresult->setOtherVariableResultVarName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVarName failed");
    }
    break;

  case 663:

    {    
         if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
                                                 parserData->kounter,     parserData->tempStr) 
                                                     == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVar failed");
    }
    break;

  case 666:

    {     
    if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, parserData->valueAttribute, 
            parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other variable option failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 667:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 668:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    }
    break;

  case 671:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 681:

    {
    parserData->numberOfOtherObjectiveResults = 0; 
    parserData->iOther = 0;
    osresult->optimization->solution[parserData->solutionIdx]->objectives = new ObjectiveSolution();
}
    break;

  case 683:

    {
    parserData->numberOfOtherObjectiveResults = parserData->tempInt;
    if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherObjectiveResults failed");
    parserData->iOther = 0;
}
    break;

  case 692:

    {
    if (osresult->setNumberOfObjValues(parserData->solutionIdx, parserData->numberOfObj) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfObjValues failed");
    parserData->kounter = 0;
}
    break;

  case 693:

    {
        if (parserData->numberOfObj > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <obj> element");
    }
    break;

  case 694:

    {
        if (parserData->kounter != parserData->numberOfObj)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <obj> elements than specified");
    }
    break;

  case 701:

    {
    if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
                              parserData->idx,         parserData->nameAttribute,
                              parserData->tempVal                           ) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setObjValue failed");
    parserData->kounter++;
}
    break;

  case 702:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <obj> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->idx = -1;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 710:

    {
    osresult->optimization->solution[parserData->solutionIdx]->objectives->basisStatus = new BasisStatus();
}
    break;

  case 717:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 719:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 726:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 728:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 735:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 737:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 744:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 746:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 753:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 755:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 762:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 764:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 771:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 773:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 781:

    {      
        parserData->iOther++;  
    }
    break;

  case 782:

    {
    if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherObjectiveResults> than specified");
    parserData->nameAttributePresent = false;    
    parserData->numberOfObjAttributePresent = false;    
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->valueAttributePresent = false;
    parserData->typeAttributePresent = false;
    parserData->objTypeAttributePresent = false;
    parserData->enumTypeAttributePresent = false;
    parserData->descriptionAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->typeAttribute = "";
    parserData->objTypeAttribute = "";
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 783:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element requires name attribute"); 
    }
    break;

  case 786:

    {
        if (parserData->numberOfObjAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfObj attribute previously set");
        parserData->numberOfObjAttributePresent = true;
         if (osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, 
                                                          parserData->iOther, 
                                                          parserData->numberOfObj) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultNumberOfObj failed");
        parserData->kounter = 0;
    }
    break;

  case 787:

    {
        if (parserData->numberOfEnumerationsAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
        parserData->numberOfEnumerationsAttributePresent = true;
         if (osresult->setOtherObjectiveResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         parserData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }
    break;

  case 788:

    {    
         if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultValue failed");
    }
    break;

  case 789:

    {    
          if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
                                                   parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultName failed");
    }
    break;

  case 790:

    {    
         if (osresult->setOtherObjectiveResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultType failed");
    }
    break;

  case 791:

    {    
         if (osresult->setOtherObjectiveResultObjType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->objTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObjType failed");
    }
    break;

  case 792:

    {    
         if (osresult->setOtherObjectiveResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultEnumType failed");
    }
    break;

  case 793:

    {    
         if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
                                                          parserData->iOther, 
                                                          parserData->descriptionAttribute) 
                                                              == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultDescription failed");
    }
    break;

  case 803:

    {  
    parserData->kounter++;
}
    break;

  case 804:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <obj> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->idx = -1;    
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 807:

    {
        if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObjIdx failed");
    }
    break;

  case 808:

    {    
         if (osresult->setOtherObjectiveResultObjName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObjName failed");
    }
    break;

  case 814:

    {
        if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObj failed");
    }
    break;

  case 817:

    {     
    if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_objectives, parserData->kounter, parserData->valueAttribute, 
            parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other objective option failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 818:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 819:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    }
    break;

  case 822:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 832:

    {
    parserData->numberOfOtherConstraintResults = 0; 
    parserData->iOther = 0;
    osresult->optimization->solution[parserData->solutionIdx]->constraints = new ConstraintSolution();
}
    break;

  case 834:

    {
    parserData->numberOfOtherConstraintResults = parserData->tempInt;
    if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherConstraintResults failed");
    parserData->iOther = 0;
}
    break;

  case 842:

    {    parserData->numberAttributePresent = false; }
    break;

  case 843:

    {
    if (osresult->setNumberOfDualValues(parserData->solutionIdx, parserData->numberOfCon) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfDualValues failed");
    parserData->kounter = 0;
}
    break;

  case 844:

    {
        if (parserData->numberOfCon > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <con> element");
    }
    break;

  case 845:

    {
        if (parserData->kounter != parserData->numberOfCon)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <con> elements than specified");
    }
    break;

  case 852:

    {
    if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
                               parserData->idx,         parserData->nameAttribute,
                               parserData->tempVal                           ) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setDualValue failed");
    parserData->kounter++;
}
    break;

  case 853:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <con> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = "";    
}
    break;

  case 861:

    {
    osresult->optimization->solution[parserData->solutionIdx]->constraints->basisStatus = new BasisStatus();
}
    break;

  case 868:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 870:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 877:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 879:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 886:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 888:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 895:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 897:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 904:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 906:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 913:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 915:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 922:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
}
    break;

  case 924:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 932:

    {      
        parserData->iOther++;  
    }
    break;

  case 933:

    {
    if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherConstraintResults> than specified");
    parserData->nameAttributePresent = false;    
    parserData->numberOfConAttributePresent = false;    
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->typeAttributePresent = false;
    parserData->conTypeAttributePresent = false;
    parserData->enumTypeAttributePresent = false;
    parserData->descriptionAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->typeAttribute = "";
    parserData->conTypeAttribute = "";
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 934:

    {
        if (!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element requires name attribute"); 
    }
    break;

  case 937:

    {
        if (parserData->numberOfConAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfCon attribute previously set");
        parserData->numberOfConAttributePresent = true;
         if (osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, 
                                                           parserData->iOther, 
                                                           parserData->numberOfCon) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultNumberOfCon failed");
        parserData->kounter = 0;
    }
    break;

  case 938:

    {
        if (parserData->numberOfEnumerationsAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
        parserData->numberOfEnumerationsAttributePresent = true;
         if (osresult->setOtherConstraintResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         parserData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }
    break;

  case 939:

    {    
         if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
                                                     parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultValue failed");
    }
    break;

  case 940:

    {    
         if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultName failed");
    }
    break;

  case 941:

    {    
         if (osresult->setOtherConstraintResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultType failed");
    }
    break;

  case 942:

    {    
         if (osresult->setOtherConstraintResultConType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->conTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultConType failed");
    }
    break;

  case 943:

    {    
         if (osresult->setOtherConstraintResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultEnumType failed");
    }
    break;

  case 944:

    {    
         if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                           parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultDescription failed");
    }
    break;

  case 954:

    {     
    if (!parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    parserData->kounter++;
}
    break;

  case 955:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <con> elements than specified");
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->name = ""    ;
}
    break;

  case 958:

    {    
         if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultConIdx failed");
    }
    break;

  case 959:

    {    
         if (osresult->setOtherConstraintResultConName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, parserData->nameAttribute) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultConName failed");
    }
    break;

  case 965:

    {    
         if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultCon failed");
    }
    break;

  case 968:

    {     
    if (osresult->setOtherOptionEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_constraints, parserData->kounter, parserData->valueAttribute, 
            parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other constraint option failed");
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 969:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 970:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    }
    break;

  case 973:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 983:

    {
    parserData->numberOf = 0; 
}
    break;

  case 984:

    {    
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherSolutionResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 985:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <otherSolutionResult> element");
    }
    break;

  case 986:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <otherSolutionResult> elements than specified");
    }
    break;

  case 993:

    {
    parserData->iOther++;
}
    break;

  case 994:

    {
    if (parserData->iOther >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherSolutionResult> elements than specified");
    parserData->numberOfItemsPresent = false; 
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->categoryAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->categoryAttribute = "";
    parserData->descriptionAttribute = "";
    parserData->numberOfItems = 0;
}
    break;

  case 995:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<otherSolutionResult> element must have name attribute");
    //if (!parserData->numberOfItemsPresent)
    //    osrlerror (NULL, NULL, parserData, osglData, osnlData, "<otherSolutionResult> element must have numberOfItems attribute");
}
    break;

  case 998:

    {    
        if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
                                                 parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultName failed");
    }
    break;

  case 999:

    {    
        if (osresult->setOtherSolutionResultValue(parserData->solutionIdx, parserData->iOther,
                                                 parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultValuee failed");
    }
    break;

  case 1000:

    {    
        if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
                                                     parserData->categoryAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultCategory failed");
    }
    break;

  case 1001:

    {    
        if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
                                                        parserData->iOther,
                                                        parserData->descriptionAttribute) 
                                                            == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultDescription failed");
    }
    break;

  case 1002:

    {    
        if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
                                                          parserData->iOther,
                                                          parserData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 1003:

    {
        if (parserData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <item> element");
    }
    break;

  case 1004:

    {
        if (parserData->kounter != parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <item> elements than specified");
    }
    break;

  case 1011:

    {
    parserData->kounter++;
}
    break;

  case 1012:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    }
    break;

  case 1017:

    {
    if (parserData->kounter >= parserData->numberOfItems)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
                                             parserData->kounter, parserData->itemContent) 
                                                 == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultItem failed");
}
    break;

  case 1020:

    {
    parserData->numberOf = 0; 
}
    break;

  case 1021:

    {    
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfSolverOutputs failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 1022:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <solverOutput> element");
    }
    break;

  case 1023:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <solverOutput> elements than specified");
    }
    break;

  case 1030:

    {
    parserData->iOther++;
}
    break;

  case 1031:

    {
    if (parserData->iOther >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <solverOutput> elements than specified");
    parserData->numberOfItemsPresent = false; 
    parserData->nameAttributePresent = false;
    parserData->categoryAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->categoryAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 1032:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<solverOutput> element must have name attribute");
    if (!parserData->numberOfItemsPresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<solverOutput> element must have numberOfItems attribute");
}
    break;

  case 1035:

    {    
        if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputName failed");
    }
    break;

  case 1036:

    {    
        if (osresult->setSolverOutputCategory(parserData->iOther, 
                                              parserData->categoryAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputCategory failed");
    }
    break;

  case 1037:

    {    
        if (osresult->setSolverOutputDescription(parserData->iOther, 
                                                 parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputDescription failed");
    }
    break;

  case 1038:

    {    
        if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
                                                   parserData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 1039:

    {
        if (parserData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <item> element");
    }
    break;

  case 1040:

    {
        if (parserData->kounter != parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <item> elements than specified");
    }
    break;

  case 1047:

    {
    parserData->kounter++;
}
    break;

  case 1048:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    }
    break;

  case 1053:

    {
    if (parserData->kounter >= parserData->numberOfItems)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
                                      parserData->itemContent) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputItem failed");
}
    break;

  case 1054:

    {
        if (parserData->categoryAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one category attribute allowed for this element");
        parserData->categoryAttributePresent = true;
    }
    break;

  case 1057:

    { 
    parserData->categoryAttribute = ""; 
}
    break;

  case 1058:

    { 
    parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1059:

    {
        if (parserData->conTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one conType attribute allowed for this element");
        parserData->conTypeAttributePresent = true;
    }
    break;

  case 1062:

    { 
    parserData->conTypeAttribute = ""; 
}
    break;

  case 1063:

    { 
    parserData->conTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1064:

    {
        if (parserData->descriptionAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one description attribute allowed for this element");
        parserData->descriptionAttributePresent = true;
    }
    break;

  case 1067:

    { 
    parserData->descriptionAttribute = ""; 
}
    break;

  case 1068:

    { 
    parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1069:

    {
        if (parserData->enumTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one enumType attribute allowed for this element");
        parserData->enumTypeAttributePresent = true;
    }
    break;

  case 1072:

    { 
    parserData->enumTypeAttribute = ""; 
}
    break;

  case 1073:

    { 
    parserData->enumTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1074:

    {    
        if (parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute was previously set");
        parserData->idxAttributePresent = true;
        parserData->idx = (yyvsp[(3) - (4)].ival); 
    }
    break;

  case 1075:

    {
       if (parserData->nameAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one name attribute allowed for this element");
        parserData->nameAttributePresent = true;
    }
    break;

  case 1078:

    { 
    parserData->nameAttribute = ""; 
}
    break;

  case 1079:

    { 
    parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1080:

    {
        if (parserData->objTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one objType attribute allowed for this element");
        parserData->objTypeAttributePresent = true;
    }
    break;

  case 1083:

    { 
    parserData->objTypeAttribute = ""; 
}
    break;

  case 1084:

    { 
    parserData->objTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1085:

    {
        if (parserData->typeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one type attribute allowed for this element");
        parserData->typeAttributePresent = true;
    }
    break;

  case 1088:

    { 
    parserData->typeAttribute = ""; 
}
    break;

  case 1089:

    { 
    parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1090:

    {
        if (parserData->unitAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one unit attribute allowed for this element");
        parserData->unitAttributePresent = true;
    }
    break;

  case 1093:

    { 
    parserData->unitAttribute = ""; 
}
    break;

  case 1094:

    { 
    parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1095:

    {
        if (parserData->valueAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one value attribute allowed for this element");
        parserData->valueAttributePresent = true;
    }
    break;

  case 1098:

    { 
    parserData->valueAttribute = ""; 
}
    break;

  case 1099:

    { 
    parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1100:

    {
        if (parserData->varTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one varType attribute allowed for this element");
        parserData->varTypeAttributePresent = true;
    }
    break;

  case 1103:

    { 
    parserData->varTypeAttribute = ""; 
}
    break;

  case 1104:

    { 
    parserData->varTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1105:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <con> cannot be negative");
    parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1106:

    {
    if (parserData->nConPresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of constraints cannot be negative");
    parserData->nConPresent = true;        
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1107:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <el> cannot be negative");
    parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1108:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <enumeration> elements cannot be negative");
    parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1109:

    {    
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one numberOfItems attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1110:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1111:

    {
    if (parserData->nObjPresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of objectives cannot be negative");
    parserData->nObjPresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1112:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other constraint results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1113:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other objective results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1114:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1115:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other solution results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1116:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other variable results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1117:

    {
    if (parserData->numberAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfSolutions attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of solutions cannot be negative");
    parserData->numberAttributePresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1118:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other solver outputs cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1119:

    {
   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <substatus> elements cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1120:

    {
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1121:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <var> cannot be negative");
    parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1122:

    {
    if (parserData->nVarPresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of variables cannot be negative");
    parserData->nVarPresent = true;    
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1123:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1124:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 1125:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); }
    break;

  case 1126:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); }
    break;

  case 1127:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].dval)); }
    break;

  case 1136:

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

  case 1151:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 1156:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1158:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 1163:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1165:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 1170:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1172:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 1177:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1179:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 1184:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1185:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1190:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 1196:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;    
}
    break;

  case 1198:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1203:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
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

  case 1204:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1205:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1206:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1211:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    double *dblvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        dblvec = (double*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglDblArray[i] = *(dblvec++);
        }
    }
    //delete[] b64string;
    free((yyvsp[(2) - (3)].sval));
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
      yyerror (&yylloc, osresult, parserData, osglData, osnlData, YY_("syntax error"));
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
	    yyerror (&yylloc, osresult, parserData, osglData, osnlData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osresult, parserData, osglData, osnlData, YY_("syntax error"));
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
		      yytoken, &yylval, &yylloc, osresult, parserData, osglData, osnlData);
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
		  yystos[yystate], yyvsp, yylsp, osresult, parserData, osglData, osnlData);
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
  yyerror (&yylloc, osresult, parserData, osglData, osnlData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osresult, parserData, osglData, osnlData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osresult, parserData, osglData, osnlData);
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
void osrlerror(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    osrl_empty_vectors( parserData );
    osgl_empty_vectors(   osglData );
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
#endif

std::string addErrorMsg(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osrlget_lineno( scanner) << ": "; 
    outStr << osrlget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg

void osrlerror(YYLTYPE* mytype, OSResult *osresult, OSrLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    osrl_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    throw ErrorClass( errormsg);
} //end osolerror



void  yygetOSResult(const char *parsestring, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) throw(ErrorClass)
{
    try
    {
        osrl_scan_string( parsestring, scanner);
        osrlset_lineno (1 , scanner );
        //
        // call the Bison parser
        //
        if(  osrlparse( osresult,  parserData, osglData, osnlData) != 0) {
            //osrllex_destroy(scanner);
              throw ErrorClass(  "Error parsing the OSrL file");
         }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(  eclass.errormsg); 
    }
} //end yygetOSResult


void osrl_empty_vectors( OSrLParserData* parserData)
{
    int k;
    int numOtherVarVec = parserData->otherVarVec.size();
   
    for (k = 0; k < numOtherVarVec; k++)
    {
        if ( (parserData->otherVarVec[k] != NULL) && (parserData->otherVarVec[k]->otherVarText  != NULL) ) 
            delete[] parserData->otherVarVec[k]->otherVarText;
        if ( (parserData->otherVarVec[k] != NULL) && (parserData->otherVarVec[k]->otherVarIndex != NULL) ) 
            delete[] parserData->otherVarVec[k]->otherVarIndex;
            
        if (  parserData->otherVarVec[k] != NULL) delete parserData->otherVarVec[k];
        }
      parserData->otherVarVec.clear(); 
      
      int numDualVals =  parserData->dualVals.size();
      for (k = 0; k < numDualVals; k++)
    {
          if (parserData->dualVals[k]  != NULL  ) 
            delete parserData->dualVals[k];
      }
      parserData->dualVals.clear();
      
      
       int numObjVals =  parserData->objVals.size();
      for (k = 0; k < numObjVals; k++)
    {
          if (parserData->objVals[ k]  != NULL  ) 
            delete parserData->objVals[ k];
      }
      parserData->objVals.clear();
      
      
       int numPrimalVals =  parserData->primalVals.size();
      for (k = 0; k < numPrimalVals; k++)
    {    
          if (parserData->primalVals[ k]  != NULL  ) 
            delete parserData->primalVals[ k];
      }
      parserData->primalVals.clear();
}//end osrl_empty_vectors


