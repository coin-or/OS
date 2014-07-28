
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
void osnl_empty_vectors( OSnLParserData* osnlData);






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
     ACTUALSTARTTIMESTART = 336,
     ACTUALSTARTTIMEEND = 337,
     ATEQUALITYSTART = 338,
     ATEQUALITYEND = 339,
     ATLOWERSTART = 340,
     ATLOWEREND = 341,
     ATUPPERSTART = 342,
     ATUPPEREND = 343,
     AVAILABLECPUNUMBERSTART = 344,
     AVAILABLECPUNUMBEREND = 345,
     AVAILABLECPUSPEEDSTART = 346,
     AVAILABLECPUSPEEDEND = 347,
     AVAILABLEDISKSPACESTART = 348,
     AVAILABLEDISKSPACEEND = 349,
     AVAILABLEMEMORYSTART = 350,
     AVAILABLEMEMORYEND = 351,
     BASE64START = 352,
     BASE64END = 353,
     BASICSTART = 354,
     BASICEND = 355,
     BASISSTATUSSTART = 356,
     BASISSTATUSEND = 357,
     BASSTATUSSTART = 358,
     BASSTATUSEND = 359,
     CONSTART = 360,
     CONEND = 361,
     CONSTRAINTSSTART = 362,
     CONSTRAINTSEND = 363,
     CURRENTJOBCOUNTSTART = 364,
     CURRENTJOBCOUNTEND = 365,
     CURRENTSTATESTART = 366,
     CURRENTSTATEEND = 367,
     DUALVALUESSTART = 368,
     DUALVALUESEND = 369,
     ELSTART = 370,
     ELEND = 371,
     ENUMERATIONSTART = 372,
     ENUMERATIONEND = 373,
     ENDTIMESTART = 374,
     ENDTIMEEND = 375,
     GENERALSTATUSSTART = 376,
     GENERALSTATUSEND = 377,
     GENERALSUBSTATUSSTART = 378,
     GENERALSUBSTATUSEND = 379,
     IDXSTART = 380,
     IDXEND = 381,
     INSTANCENAMESTART = 382,
     INSTANCENAMEEND = 383,
     ISFREESTART = 384,
     ISFREEEND = 385,
     JOBIDSTART = 386,
     JOBIDEND = 387,
     MESSAGESTART = 388,
     MESSAGEEND = 389,
     OBJSTART = 390,
     OBJEND = 391,
     OBJECTIVESSTART = 392,
     OBJECTIVESEND = 393,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 394,
     OPTIMIZATIONSOLUTIONSTATUSEND = 395,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 396,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 397,
     OTHERSTART = 398,
     OTHEREND = 399,
     OTHERRESULTSSTART = 400,
     OTHERRESULTSEND = 401,
     OTHERSOLUTIONRESULTSTART = 402,
     OTHERSOLUTIONRESULTEND = 403,
     OTHERSOLUTIONRESULTSSTART = 404,
     OTHERSOLUTIONRESULTSEND = 405,
     OTHERSOLVEROUTPUTSTART = 406,
     OTHERSOLVEROUTPUTEND = 407,
     SCHEDULEDSTARTTIMESTART = 408,
     SCHEDULEDSTARTTIMEEND = 409,
     SERVICENAMESTART = 410,
     SERVICENAMEEND = 411,
     SERVICEURISTART = 412,
     SERVICEURIEND = 413,
     SERVICEUTILIZATIONSTART = 414,
     SERVICEUTILIZATIONEND = 415,
     SOLUTIONSTART = 416,
     SOLUTIONEND = 417,
     SOLVERINVOKEDSTART = 418,
     SOLVERINVOKEDEND = 419,
     SOLVEROUTPUTSTART = 420,
     SOLVEROUTPUTEND = 421,
     STATUSSTART = 422,
     STATUSEND = 423,
     SUBMITTIMESTART = 424,
     SUBMITTIMEEND = 425,
     SUBSTATUSSTART = 426,
     SUBSTATUSEND = 427,
     SUPERBASICSTART = 428,
     SUPERBASICEND = 429,
     SYSTEMINFORMATIONSTART = 430,
     SYSTEMINFORMATIONEND = 431,
     TIMESTART = 432,
     TIMEEND = 433,
     TIMESERVICESTARTEDSTART = 434,
     TIMESERVICESTARTEDEND = 435,
     TIMESTAMPSTART = 436,
     TIMESTAMPEND = 437,
     TIMINGINFORMATIONSTART = 438,
     TIMINGINFORMATIONEND = 439,
     TOTALJOBSSOFARSTART = 440,
     TOTALJOBSSOFAREND = 441,
     UNKNOWNSTART = 442,
     UNKNOWNEND = 443,
     USEDCPUNUMBERSTART = 444,
     USEDCPUNUMBEREND = 445,
     USEDCPUSPEEDSTART = 446,
     USEDCPUSPEEDEND = 447,
     USEDDISKSPACESTART = 448,
     USEDDISKSPACEEND = 449,
     USEDMEMORYSTART = 450,
     USEDMEMORYEND = 451,
     VALUESSTRINGSTART = 452,
     VALUESSTRINGEND = 453,
     VARSTART = 454,
     VAREND = 455,
     VARIABLESSTART = 456,
     VARIABLESEND = 457,
     VARIDXSTART = 458,
     VARIDXEND = 459,
     FILENAMESTART = 460,
     FILENAMEEND = 461,
     FILENAMEEMPTY = 462,
     FILENAMESTARTANDEND = 463,
     FILESOURCESTART = 464,
     FILESOURCEEND = 465,
     FILESOURCEEMPTY = 466,
     FILESOURCESTARTANDEND = 467,
     FILEDESCRIPTIONSTART = 468,
     FILEDESCRIPTIONEND = 469,
     FILEDESCRIPTIONEMPTY = 470,
     FILEDESCRIPTIONSTARTANDEND = 471,
     FILECREATORSTART = 472,
     FILECREATOREND = 473,
     FILECREATOREMPTY = 474,
     FILECREATORSTARTANDEND = 475,
     FILELICENCESTART = 476,
     FILELICENCEEND = 477,
     FILELICENCEEMPTY = 478,
     FILELICENCESTARTANDEND = 479,
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
     CONSTANTATT = 492,
     NUMBEROFBLOCKSATT = 493,
     NUMBEROFCOLUMNSATT = 494,
     NUMBEROFROWSATT = 495,
     BASEMATRIXIDXATT = 496,
     TARGETMATRIXFIRSTROWATT = 497,
     TARGETMATRIXFIRSTCOLATT = 498,
     BASEMATRIXSTARTROWATT = 499,
     BASEMATRIXSTARTCOLATT = 500,
     BASEMATRIXENDROWATT = 501,
     BASEMATRIXENDCOLATT = 502,
     SCALARMULTIPLIERATT = 503,
     EMPTYBASETRANSPOSEATT = 504,
     BASETRANSPOSEATT = 505,
     ELEMENTSSTART = 506,
     ELEMENTSEND = 507,
     CONSTANTELEMENTSSTART = 508,
     CONSTANTELEMENTSEND = 509,
     STARTVECTORSTART = 510,
     STARTVECTOREND = 511,
     NONZEROSSTART = 512,
     NONZEROSEND = 513,
     INDEXESSTART = 514,
     INDEXESEND = 515,
     VALUESSTART = 516,
     VALUESEND = 517,
     VARREFERENCEELEMENTSSTART = 518,
     VARREFERENCEELEMENTSEND = 519,
     LINEARELEMENTSSTART = 520,
     LINEARELEMENTSEND = 521,
     GENERALELEMENTSSTART = 522,
     GENERALELEMENTSEND = 523,
     CONREFERENCEELEMENTSSTART = 524,
     CONREFERENCEELEMENTSEND = 525,
     OBJREFERENCEELEMENTSSTART = 526,
     OBJREFERENCEELEMENTSEND = 527,
     PATTERNELEMENTSSTART = 528,
     PATTERNELEMENTSEND = 529,
     TRANSFORMATIONSTART = 530,
     TRANSFORMATIONEND = 531,
     COLOFFSETSSTART = 532,
     COLOFFSETSEND = 533,
     ROWOFFSETSSTART = 534,
     ROWOFFSETSEND = 535,
     EMPTYROWMAJORATT = 536,
     ROWMAJORATT = 537,
     BLOCKROWIDXATT = 538,
     BLOCKCOLIDXATT = 539,
     DUMMY = 540,
     NONLINEAREXPRESSIONSSTART = 541,
     NONLINEAREXPRESSIONSEND = 542,
     NUMBEROFNONLINEAREXPRESSIONS = 543,
     NLSTART = 544,
     NLEND = 545,
     POWERSTART = 546,
     POWEREND = 547,
     PLUSSTART = 548,
     PLUSEND = 549,
     MINUSSTART = 550,
     MINUSEND = 551,
     DIVIDESTART = 552,
     DIVIDEEND = 553,
     LNSTART = 554,
     LNEND = 555,
     SQRTSTART = 556,
     SQRTEND = 557,
     SUMSTART = 558,
     SUMEND = 559,
     PRODUCTSTART = 560,
     PRODUCTEND = 561,
     EXPSTART = 562,
     EXPEND = 563,
     NEGATESTART = 564,
     NEGATEEND = 565,
     IFSTART = 566,
     IFEND = 567,
     SQUARESTART = 568,
     SQUAREEND = 569,
     COSSTART = 570,
     COSEND = 571,
     SINSTART = 572,
     SINEND = 573,
     VARIABLESTART = 574,
     VARIABLEEND = 575,
     ABSSTART = 576,
     ABSEND = 577,
     ERFSTART = 578,
     ERFEND = 579,
     MAXSTART = 580,
     MAXEND = 581,
     ALLDIFFSTART = 582,
     ALLDIFFEND = 583,
     MINSTART = 584,
     MINEND = 585,
     ESTART = 586,
     EEND = 587,
     PISTART = 588,
     PIEND = 589,
     TIMESSTART = 590,
     TIMESEND = 591,
     NUMBERSTART = 592,
     NUMBEREND = 593,
     MATRIXTRACESTART = 594,
     MATRIXTRACEEND = 595,
     MATRIXTOSCALARSTART = 596,
     MATRIXTOSCALAREND = 597,
     IDATT = 598,
     COEFATT = 599
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
#define ACTUALSTARTTIMESTART 336
#define ACTUALSTARTTIMEEND 337
#define ATEQUALITYSTART 338
#define ATEQUALITYEND 339
#define ATLOWERSTART 340
#define ATLOWEREND 341
#define ATUPPERSTART 342
#define ATUPPEREND 343
#define AVAILABLECPUNUMBERSTART 344
#define AVAILABLECPUNUMBEREND 345
#define AVAILABLECPUSPEEDSTART 346
#define AVAILABLECPUSPEEDEND 347
#define AVAILABLEDISKSPACESTART 348
#define AVAILABLEDISKSPACEEND 349
#define AVAILABLEMEMORYSTART 350
#define AVAILABLEMEMORYEND 351
#define BASE64START 352
#define BASE64END 353
#define BASICSTART 354
#define BASICEND 355
#define BASISSTATUSSTART 356
#define BASISSTATUSEND 357
#define BASSTATUSSTART 358
#define BASSTATUSEND 359
#define CONSTART 360
#define CONEND 361
#define CONSTRAINTSSTART 362
#define CONSTRAINTSEND 363
#define CURRENTJOBCOUNTSTART 364
#define CURRENTJOBCOUNTEND 365
#define CURRENTSTATESTART 366
#define CURRENTSTATEEND 367
#define DUALVALUESSTART 368
#define DUALVALUESEND 369
#define ELSTART 370
#define ELEND 371
#define ENUMERATIONSTART 372
#define ENUMERATIONEND 373
#define ENDTIMESTART 374
#define ENDTIMEEND 375
#define GENERALSTATUSSTART 376
#define GENERALSTATUSEND 377
#define GENERALSUBSTATUSSTART 378
#define GENERALSUBSTATUSEND 379
#define IDXSTART 380
#define IDXEND 381
#define INSTANCENAMESTART 382
#define INSTANCENAMEEND 383
#define ISFREESTART 384
#define ISFREEEND 385
#define JOBIDSTART 386
#define JOBIDEND 387
#define MESSAGESTART 388
#define MESSAGEEND 389
#define OBJSTART 390
#define OBJEND 391
#define OBJECTIVESSTART 392
#define OBJECTIVESEND 393
#define OPTIMIZATIONSOLUTIONSTATUSSTART 394
#define OPTIMIZATIONSOLUTIONSTATUSEND 395
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 396
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 397
#define OTHERSTART 398
#define OTHEREND 399
#define OTHERRESULTSSTART 400
#define OTHERRESULTSEND 401
#define OTHERSOLUTIONRESULTSTART 402
#define OTHERSOLUTIONRESULTEND 403
#define OTHERSOLUTIONRESULTSSTART 404
#define OTHERSOLUTIONRESULTSEND 405
#define OTHERSOLVEROUTPUTSTART 406
#define OTHERSOLVEROUTPUTEND 407
#define SCHEDULEDSTARTTIMESTART 408
#define SCHEDULEDSTARTTIMEEND 409
#define SERVICENAMESTART 410
#define SERVICENAMEEND 411
#define SERVICEURISTART 412
#define SERVICEURIEND 413
#define SERVICEUTILIZATIONSTART 414
#define SERVICEUTILIZATIONEND 415
#define SOLUTIONSTART 416
#define SOLUTIONEND 417
#define SOLVERINVOKEDSTART 418
#define SOLVERINVOKEDEND 419
#define SOLVEROUTPUTSTART 420
#define SOLVEROUTPUTEND 421
#define STATUSSTART 422
#define STATUSEND 423
#define SUBMITTIMESTART 424
#define SUBMITTIMEEND 425
#define SUBSTATUSSTART 426
#define SUBSTATUSEND 427
#define SUPERBASICSTART 428
#define SUPERBASICEND 429
#define SYSTEMINFORMATIONSTART 430
#define SYSTEMINFORMATIONEND 431
#define TIMESTART 432
#define TIMEEND 433
#define TIMESERVICESTARTEDSTART 434
#define TIMESERVICESTARTEDEND 435
#define TIMESTAMPSTART 436
#define TIMESTAMPEND 437
#define TIMINGINFORMATIONSTART 438
#define TIMINGINFORMATIONEND 439
#define TOTALJOBSSOFARSTART 440
#define TOTALJOBSSOFAREND 441
#define UNKNOWNSTART 442
#define UNKNOWNEND 443
#define USEDCPUNUMBERSTART 444
#define USEDCPUNUMBEREND 445
#define USEDCPUSPEEDSTART 446
#define USEDCPUSPEEDEND 447
#define USEDDISKSPACESTART 448
#define USEDDISKSPACEEND 449
#define USEDMEMORYSTART 450
#define USEDMEMORYEND 451
#define VALUESSTRINGSTART 452
#define VALUESSTRINGEND 453
#define VARSTART 454
#define VAREND 455
#define VARIABLESSTART 456
#define VARIABLESEND 457
#define VARIDXSTART 458
#define VARIDXEND 459
#define FILENAMESTART 460
#define FILENAMEEND 461
#define FILENAMEEMPTY 462
#define FILENAMESTARTANDEND 463
#define FILESOURCESTART 464
#define FILESOURCEEND 465
#define FILESOURCEEMPTY 466
#define FILESOURCESTARTANDEND 467
#define FILEDESCRIPTIONSTART 468
#define FILEDESCRIPTIONEND 469
#define FILEDESCRIPTIONEMPTY 470
#define FILEDESCRIPTIONSTARTANDEND 471
#define FILECREATORSTART 472
#define FILECREATOREND 473
#define FILECREATOREMPTY 474
#define FILECREATORSTARTANDEND 475
#define FILELICENCESTART 476
#define FILELICENCEEND 477
#define FILELICENCEEMPTY 478
#define FILELICENCESTARTANDEND 479
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
#define CONSTANTATT 492
#define NUMBEROFBLOCKSATT 493
#define NUMBEROFCOLUMNSATT 494
#define NUMBEROFROWSATT 495
#define BASEMATRIXIDXATT 496
#define TARGETMATRIXFIRSTROWATT 497
#define TARGETMATRIXFIRSTCOLATT 498
#define BASEMATRIXSTARTROWATT 499
#define BASEMATRIXSTARTCOLATT 500
#define BASEMATRIXENDROWATT 501
#define BASEMATRIXENDCOLATT 502
#define SCALARMULTIPLIERATT 503
#define EMPTYBASETRANSPOSEATT 504
#define BASETRANSPOSEATT 505
#define ELEMENTSSTART 506
#define ELEMENTSEND 507
#define CONSTANTELEMENTSSTART 508
#define CONSTANTELEMENTSEND 509
#define STARTVECTORSTART 510
#define STARTVECTOREND 511
#define NONZEROSSTART 512
#define NONZEROSEND 513
#define INDEXESSTART 514
#define INDEXESEND 515
#define VALUESSTART 516
#define VALUESEND 517
#define VARREFERENCEELEMENTSSTART 518
#define VARREFERENCEELEMENTSEND 519
#define LINEARELEMENTSSTART 520
#define LINEARELEMENTSEND 521
#define GENERALELEMENTSSTART 522
#define GENERALELEMENTSEND 523
#define CONREFERENCEELEMENTSSTART 524
#define CONREFERENCEELEMENTSEND 525
#define OBJREFERENCEELEMENTSSTART 526
#define OBJREFERENCEELEMENTSEND 527
#define PATTERNELEMENTSSTART 528
#define PATTERNELEMENTSEND 529
#define TRANSFORMATIONSTART 530
#define TRANSFORMATIONEND 531
#define COLOFFSETSSTART 532
#define COLOFFSETSEND 533
#define ROWOFFSETSSTART 534
#define ROWOFFSETSEND 535
#define EMPTYROWMAJORATT 536
#define ROWMAJORATT 537
#define BLOCKROWIDXATT 538
#define BLOCKCOLIDXATT 539
#define DUMMY 540
#define NONLINEAREXPRESSIONSSTART 541
#define NONLINEAREXPRESSIONSEND 542
#define NUMBEROFNONLINEAREXPRESSIONS 543
#define NLSTART 544
#define NLEND 545
#define POWERSTART 546
#define POWEREND 547
#define PLUSSTART 548
#define PLUSEND 549
#define MINUSSTART 550
#define MINUSEND 551
#define DIVIDESTART 552
#define DIVIDEEND 553
#define LNSTART 554
#define LNEND 555
#define SQRTSTART 556
#define SQRTEND 557
#define SUMSTART 558
#define SUMEND 559
#define PRODUCTSTART 560
#define PRODUCTEND 561
#define EXPSTART 562
#define EXPEND 563
#define NEGATESTART 564
#define NEGATEEND 565
#define IFSTART 566
#define IFEND 567
#define SQUARESTART 568
#define SQUAREEND 569
#define COSSTART 570
#define COSEND 571
#define SINSTART 572
#define SINEND 573
#define VARIABLESTART 574
#define VARIABLEEND 575
#define ABSSTART 576
#define ABSEND 577
#define ERFSTART 578
#define ERFEND 579
#define MAXSTART 580
#define MAXEND 581
#define ALLDIFFSTART 582
#define ALLDIFFEND 583
#define MINSTART 584
#define MINEND 585
#define ESTART 586
#define EEND 587
#define PISTART 588
#define PIEND 589
#define TIMESSTART 590
#define TIMESEND 591
#define NUMBERSTART 592
#define NUMBEREND 593
#define MATRIXTRACESTART 594
#define MATRIXTRACEEND 595
#define MATRIXTOSCALARSTART 596
#define MATRIXTOSCALAREND 597
#define IDATT 598
#define COEFATT 599




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
#define YYNTOKENS  349
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  815
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1211
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1628

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   599

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   346,
     348,     2,     2,   347,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   345,     2,     2,     2,     2,     2,     2,     2,
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344
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
     350,     0,    -1,   351,   359,   357,    -1,   352,   353,   354,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   355,    -1,
     356,    -1,    11,    -1,    10,   359,   357,    -1,   358,    -1,
      15,    -1,    -1,   360,   361,   441,   495,   547,   642,    -1,
      -1,  1121,    -1,    -1,   362,   363,    -1,    67,    -1,   364,
      -1,   365,    -1,    10,    68,    -1,    11,    -1,    10,   366,
      68,    -1,   367,    -1,   368,    -1,   367,   368,    -1,   369,
      -1,   385,    -1,   391,    -1,   397,    -1,   403,    -1,   409,
      -1,   415,    -1,   421,    -1,   427,    -1,   370,   371,   374,
      -1,   121,    -1,   372,    -1,   373,    -1,   372,   373,    -1,
    1082,    -1,  1065,    -1,  1112,    -1,   375,    -1,   376,    -1,
      10,   122,    -1,    11,    -1,    10,   377,   122,    -1,   378,
      -1,   379,    -1,   378,   379,    -1,   380,   381,   384,    -1,
     171,    -1,   382,    -1,    -1,   382,   383,    -1,  1074,    -1,
    1065,    -1,    10,   172,    -1,    11,    -1,   386,   387,    -1,
     133,    -1,   388,    -1,   389,    -1,    10,   134,    -1,    11,
      -1,    10,   390,   134,    -1,     4,    -1,   392,   393,    -1,
     157,    -1,   394,    -1,   395,    -1,    10,   158,    -1,    11,
      -1,    10,   396,   158,    -1,     4,    -1,   398,   399,    -1,
     155,    -1,   400,    -1,   401,    -1,    10,   156,    -1,    11,
      -1,    10,   402,   156,    -1,     4,    -1,   404,   405,    -1,
     127,    -1,   406,    -1,   407,    -1,    10,   128,    -1,    11,
      -1,    10,   408,   128,    -1,     4,    -1,   410,   411,    -1,
     131,    -1,   412,    -1,   413,    -1,    10,   132,    -1,    11,
      -1,    10,   414,   132,    -1,     4,    -1,   416,   417,    -1,
     163,    -1,   418,    -1,   419,    -1,    10,   164,    -1,    11,
      -1,    10,   420,   164,    -1,     4,    -1,   422,   423,    -1,
     181,    -1,   424,    -1,   425,    -1,    10,   182,    -1,    11,
      -1,    10,   426,   182,    -1,     4,    -1,   428,   429,   430,
      -1,   145,    -1,  1107,    -1,   431,    -1,   432,    -1,    10,
     146,    -1,    11,    -1,    10,   433,   146,    -1,   434,    -1,
     435,    -1,   434,   435,    -1,   436,   437,   440,    -1,   143,
      -1,   438,    -1,    -1,   438,   439,    -1,  1074,    -1,  1090,
      -1,  1065,    -1,    10,   144,    -1,    11,    -1,    -1,   442,
     443,    -1,    69,    -1,   444,    -1,   445,    -1,    10,    70,
      -1,    11,    -1,    10,   446,    70,    -1,   447,    -1,   448,
      -1,   447,   448,    -1,   449,    -1,   455,    -1,   462,    -1,
     469,    -1,   476,    -1,   481,    -1,   450,   451,    -1,   175,
      -1,   452,    -1,   453,    -1,    10,   176,    -1,    11,    -1,
      10,   454,   176,    -1,     4,    -1,   456,   457,   460,    -1,
      93,    -1,   458,    -1,    -1,   458,   459,    -1,  1086,    -1,
    1065,    -1,    10,   461,    94,    -1,  1116,    -1,   463,   464,
     467,    -1,    95,    -1,   465,    -1,    -1,   465,   466,    -1,
    1086,    -1,  1065,    -1,    10,   468,    96,    -1,  1116,    -1,
     470,   471,   474,    -1,    91,    -1,   472,    -1,    -1,   472,
     473,    -1,  1086,    -1,  1065,    -1,    10,   475,    92,    -1,
    1116,    -1,   477,   478,   479,    -1,    89,    -1,    -1,  1065,
      -1,    10,   480,    90,    -1,     6,    -1,   482,   483,   484,
      -1,   145,    -1,  1107,    -1,   485,    -1,   486,    -1,    10,
     146,    -1,    11,    -1,    10,   487,   146,    -1,   488,    -1,
     489,    -1,   488,   489,    -1,   490,   491,   494,    -1,   143,
      -1,   492,    -1,    -1,   492,   493,    -1,  1074,    -1,  1090,
      -1,  1065,    -1,    10,   144,    -1,    11,    -1,    -1,   496,
     497,    -1,    71,    -1,   498,    -1,   499,    -1,    10,    72,
      -1,    11,    -1,    10,   500,    72,    -1,   501,    -1,   502,
      -1,   501,   502,    -1,   503,    -1,   509,    -1,   515,    -1,
     521,    -1,   527,    -1,   533,    -1,   504,   505,    -1,   111,
      -1,   506,    -1,   507,    -1,    10,   112,    -1,    11,    -1,
      10,   508,   112,    -1,     4,    -1,   510,   511,    -1,   109,
      -1,   512,    -1,   513,    -1,    10,   110,    -1,    11,    -1,
      10,   514,   110,    -1,     6,    -1,   516,   517,    -1,   185,
      -1,   518,    -1,   519,    -1,    10,   186,    -1,    11,    -1,
      10,   520,   186,    -1,     6,    -1,   522,   523,    -1,   179,
      -1,   524,    -1,   525,    -1,    10,   180,    -1,    11,    -1,
      10,   526,   180,    -1,     4,    -1,   528,   529,    -1,   159,
      -1,   530,    -1,   531,    -1,    10,   160,    -1,    11,    -1,
      10,   532,   160,    -1,  1116,    -1,   534,   535,   536,    -1,
     145,    -1,  1107,    -1,   537,    -1,   538,    -1,    10,   146,
      -1,    11,    -1,    10,   539,   146,    -1,   540,    -1,   541,
      -1,   540,   541,    -1,   542,   543,   546,    -1,   143,    -1,
     544,    -1,    -1,   544,   545,    -1,  1074,    -1,  1090,    -1,
    1065,    -1,    10,   144,    -1,    11,    -1,    -1,   548,   549,
      -1,    73,    -1,   550,    -1,   551,    -1,    10,    74,    -1,
      11,    -1,    10,   552,    74,    -1,   553,    -1,   554,    -1,
     553,   554,    -1,   555,    -1,   561,    -1,   567,    -1,   573,
      -1,   579,    -1,   585,    -1,   602,    -1,   609,    -1,   616,
      -1,   623,    -1,   628,    -1,   556,   557,    -1,   167,    -1,
     558,    -1,   559,    -1,    10,   168,    -1,    11,    -1,    10,
     560,   168,    -1,     4,    -1,   562,   563,    -1,   169,    -1,
     564,    -1,   565,    -1,    10,   170,    -1,    11,    -1,    10,
     566,   170,    -1,     4,    -1,   568,   569,    -1,   153,    -1,
     570,    -1,   571,    -1,    10,   154,    -1,    11,    -1,    10,
     572,   154,    -1,     4,    -1,   574,   575,    -1,    81,    -1,
     576,    -1,   577,    -1,    10,    82,    -1,    11,    -1,    10,
     578,    82,    -1,     4,    -1,   580,   581,    -1,   119,    -1,
     582,    -1,   583,    -1,    10,   120,    -1,    11,    -1,    10,
     584,   120,    -1,     4,    -1,   586,   587,   588,    -1,   183,
      -1,  1113,    -1,   589,    -1,   590,    -1,    10,   184,    -1,
      11,    -1,    10,   591,   184,    -1,   592,    -1,   593,    -1,
     592,   593,    -1,   594,   595,   597,    -1,   177,    -1,    -1,
     595,   596,    -1,  1086,    -1,  1082,    -1,  1057,    -1,  1065,
      -1,   598,    -1,   599,    -1,    10,   178,    -1,    11,    -1,
      10,   600,   178,    -1,   601,    -1,     7,    -1,     6,    -1,
     603,   604,   607,    -1,   193,    -1,   605,    -1,    -1,   605,
     606,    -1,  1086,    -1,  1065,    -1,    10,   608,   194,    -1,
    1116,    -1,   610,   611,   614,    -1,   195,    -1,   612,    -1,
      -1,   612,   613,    -1,  1086,    -1,  1065,    -1,    10,   615,
     196,    -1,  1116,    -1,   617,   618,   621,    -1,   191,    -1,
     619,    -1,    -1,   619,   620,    -1,  1086,    -1,  1065,    -1,
      10,   622,   192,    -1,  1116,    -1,   624,   625,   626,    -1,
     189,    -1,    -1,  1065,    -1,    10,   627,   190,    -1,     6,
      -1,   629,   630,   631,    -1,   145,    -1,  1107,    -1,   632,
      -1,   633,    -1,    10,   146,    -1,    11,    -1,    10,   634,
     146,    -1,   635,    -1,   636,    -1,   635,   636,    -1,   637,
     638,   641,    -1,   143,    -1,   639,    -1,    -1,   639,   640,
      -1,  1074,    -1,  1090,    -1,  1065,    -1,    10,   144,    -1,
      11,    -1,    -1,   643,   644,   647,    -1,    75,    -1,   645,
      -1,    -1,   645,   646,    -1,  1110,    -1,  1115,    -1,  1099,
      -1,  1104,    -1,   648,    -1,   649,    -1,    10,    76,    -1,
      11,    -1,    10,   650,    76,    -1,   651,  1034,    -1,   652,
      -1,   651,   652,    -1,   653,   654,   660,    -1,   161,    -1,
     655,    -1,    -1,   655,   656,    -1,   657,    -1,   658,    -1,
     659,    -1,    36,  1118,     6,  1118,    -1,    63,     3,  1118,
      -1,    61,     3,  1118,    -1,    10,   661,   677,   683,   803,
     907,  1011,   162,    -1,   662,   663,   666,    -1,   167,    -1,
     664,    -1,   665,    -1,   664,   665,    -1,  1082,    -1,  1065,
      -1,  1112,    -1,   667,    -1,   668,    -1,    10,   168,    -1,
      11,    -1,    10,   669,   168,    -1,   670,    -1,   671,    -1,
     670,   671,    -1,   672,   673,   676,    -1,   171,    -1,   674,
      -1,    -1,   674,   675,    -1,  1082,    -1,  1065,    -1,    10,
     172,    -1,    11,    -1,    -1,   678,   679,    -1,   133,    -1,
     680,    -1,   681,    -1,    10,   134,    -1,    11,    -1,    10,
     682,   134,    -1,     4,    -1,    -1,   684,   685,   686,    -1,
     201,    -1,    -1,  1109,    -1,   687,    -1,   688,    -1,    11,
      -1,    10,   689,   202,    -1,   690,   703,   719,   774,    -1,
      -1,   691,   692,   693,    -1,   261,    -1,  1114,    -1,   694,
      -1,   695,    -1,    10,   262,    -1,    11,    -1,    10,   696,
     262,    -1,   697,    -1,   698,    -1,   697,   698,    -1,   699,
     700,   702,    -1,   199,    -1,    -1,   700,   701,    -1,  1073,
      -1,  1074,    -1,    10,  1116,   200,    -1,    -1,   704,   705,
     706,    -1,   197,    -1,  1114,    -1,   707,    -1,   708,    -1,
      10,   198,    -1,    11,    -1,    10,   709,   198,    -1,   710,
      -1,   711,    -1,   710,   711,    -1,   712,   713,   715,    -1,
     199,    -1,    -1,   713,   714,    -1,  1073,    -1,  1074,    -1,
     716,    -1,   717,    -1,    10,   200,    -1,    11,    -1,    10,
     718,   200,    -1,     4,    -1,    -1,   720,   721,    -1,   101,
      -1,   722,    -1,   723,    -1,    11,    -1,    10,   724,   102,
      -1,   725,   732,   739,   746,   753,   760,   767,    -1,    -1,
     726,   727,   728,    -1,    99,    -1,  1100,    -1,   729,    -1,
     730,    -1,    11,    -1,    10,   731,   100,    -1,  1149,    -1,
      -1,   733,   734,   735,    -1,    85,    -1,  1100,    -1,   736,
      -1,   737,    -1,    11,    -1,    10,   738,    86,    -1,  1149,
      -1,    -1,   740,   741,   742,    -1,    87,    -1,  1100,    -1,
     743,    -1,   744,    -1,    11,    -1,    10,   745,    88,    -1,
    1149,    -1,    -1,   747,   748,   749,    -1,    83,    -1,  1100,
      -1,   750,    -1,   751,    -1,    11,    -1,    10,   752,    84,
      -1,  1149,    -1,    -1,   754,   755,   756,    -1,   129,    -1,
    1100,    -1,   757,    -1,   758,    -1,    11,    -1,    10,   759,
     130,    -1,  1149,    -1,    -1,   761,   762,   763,    -1,   173,
      -1,  1100,    -1,   764,    -1,   765,    -1,    11,    -1,    10,
     766,   174,    -1,  1149,    -1,    -1,   768,   769,   770,    -1,
     187,    -1,  1100,    -1,   771,    -1,   772,    -1,    11,    -1,
      10,   773,   188,    -1,  1149,    -1,    -1,   774,   775,    -1,
     776,   777,   780,    -1,   143,    -1,   778,    -1,    -1,   778,
     779,    -1,  1114,    -1,  1101,    -1,  1090,    -1,  1074,    -1,
    1082,    -1,  1094,    -1,  1069,    -1,  1065,    -1,   781,    -1,
     782,    -1,    10,   144,    -1,    11,    -1,    10,   783,   144,
      -1,   784,    -1,   793,    -1,   785,    -1,   784,   785,    -1,
     786,   787,   789,    -1,   199,    -1,    -1,   787,   788,    -1,
    1073,    -1,  1074,    -1,   790,    -1,   791,    -1,    10,   200,
      -1,    11,    -1,    10,   792,   200,    -1,  1117,    -1,   794,
      -1,   793,   794,    -1,   795,   796,   799,    -1,   117,    -1,
     797,    -1,    -1,   797,   798,    -1,  1100,    -1,  1090,    -1,
    1065,    -1,   800,    -1,   801,    -1,    11,    -1,    10,   802,
     118,    -1,  1149,    -1,    -1,   804,   805,   806,    -1,   137,
      -1,    -1,  1106,    -1,   807,    -1,   808,    -1,    11,    -1,
      10,   809,   138,    -1,   810,   823,   878,    -1,    -1,   811,
     812,   813,    -1,   261,    -1,  1103,    -1,   814,    -1,   815,
      -1,    10,   262,    -1,    11,    -1,    10,   816,   262,    -1,
     817,    -1,   818,    -1,   817,   818,    -1,   819,   820,   822,
      -1,   135,    -1,    -1,   820,   821,    -1,  1073,    -1,  1074,
      -1,    10,  1116,   136,    -1,    -1,   824,   825,    -1,   101,
      -1,   826,    -1,   827,    -1,    11,    -1,    10,   828,   102,
      -1,   829,   836,   843,   850,   857,   864,   871,    -1,    -1,
     830,   831,   832,    -1,    99,    -1,  1100,    -1,   833,    -1,
     834,    -1,    11,    -1,    10,   835,   100,    -1,  1149,    -1,
      -1,   837,   838,   839,    -1,    85,    -1,  1100,    -1,   840,
      -1,   841,    -1,    11,    -1,    10,   842,    86,    -1,  1149,
      -1,    -1,   844,   845,   846,    -1,    87,    -1,  1100,    -1,
     847,    -1,   848,    -1,    11,    -1,    10,   849,    88,    -1,
    1149,    -1,    -1,   851,   852,   853,    -1,    83,    -1,  1100,
      -1,   854,    -1,   855,    -1,    11,    -1,    10,   856,    84,
      -1,  1149,    -1,    -1,   858,   859,   860,    -1,   129,    -1,
    1100,    -1,   861,    -1,   862,    -1,    11,    -1,    10,   863,
     130,    -1,  1149,    -1,    -1,   865,   866,   867,    -1,   173,
      -1,  1100,    -1,   868,    -1,   869,    -1,    11,    -1,    10,
     870,   174,    -1,  1149,    -1,    -1,   872,   873,   874,    -1,
     187,    -1,  1100,    -1,   875,    -1,   876,    -1,    11,    -1,
      10,   877,   188,    -1,  1149,    -1,    -1,   878,   879,    -1,
     880,   881,   884,    -1,   143,    -1,   882,    -1,    -1,   882,
     883,    -1,  1103,    -1,  1101,    -1,  1090,    -1,  1074,    -1,
    1082,    -1,  1078,    -1,  1069,    -1,  1065,    -1,   885,    -1,
     886,    -1,    10,   144,    -1,    11,    -1,    10,   887,   144,
      -1,   888,    -1,   897,    -1,   889,    -1,   888,   889,    -1,
     890,   891,   893,    -1,   135,    -1,    -1,   891,   892,    -1,
    1073,    -1,  1074,    -1,   894,    -1,   895,    -1,    10,   136,
      -1,    11,    -1,    10,   896,   136,    -1,  1117,    -1,   898,
      -1,   897,   898,    -1,   899,   900,   903,    -1,   117,    -1,
     901,    -1,    -1,   901,   902,    -1,  1100,    -1,  1090,    -1,
    1065,    -1,   904,    -1,   905,    -1,    11,    -1,    10,   906,
     118,    -1,  1149,    -1,    -1,   908,   909,   910,    -1,   107,
      -1,    -1,  1105,    -1,   911,    -1,   912,    -1,    11,    -1,
      10,   913,   108,    -1,   914,   927,   982,    -1,    -1,   915,
     916,   917,    -1,   113,    -1,  1098,    -1,   918,    -1,   919,
      -1,    10,   114,    -1,    11,    -1,    10,   920,   114,    -1,
     921,    -1,   922,    -1,   921,   922,    -1,   923,   924,   926,
      -1,   105,    -1,    -1,   924,   925,    -1,  1073,    -1,  1074,
      -1,    10,  1116,   106,    -1,    -1,   928,   929,    -1,   101,
      -1,   930,    -1,   931,    -1,    11,    -1,    10,   932,   102,
      -1,   933,   940,   947,   954,   961,   968,   975,    -1,    -1,
     934,   935,   936,    -1,    99,    -1,  1100,    -1,   937,    -1,
     938,    -1,    11,    -1,    10,   939,   100,    -1,  1149,    -1,
      -1,   941,   942,   943,    -1,    85,    -1,  1100,    -1,   944,
      -1,   945,    -1,    11,    -1,    10,   946,    86,    -1,  1149,
      -1,    -1,   948,   949,   950,    -1,    87,    -1,  1100,    -1,
     951,    -1,   952,    -1,    11,    -1,    10,   953,    88,    -1,
    1149,    -1,    -1,   955,   956,   957,    -1,    83,    -1,  1100,
      -1,   958,    -1,   959,    -1,    11,    -1,    10,   960,    84,
      -1,  1149,    -1,    -1,   962,   963,   964,    -1,   129,    -1,
    1100,    -1,   965,    -1,   966,    -1,    11,    -1,    10,   967,
     130,    -1,  1149,    -1,    -1,   969,   970,   971,    -1,   173,
      -1,  1100,    -1,   972,    -1,   973,    -1,    11,    -1,    10,
     974,   174,    -1,  1149,    -1,    -1,   976,   977,   978,    -1,
     187,    -1,  1100,    -1,   979,    -1,   980,    -1,    11,    -1,
      10,   981,   188,    -1,  1149,    -1,    -1,   982,   983,    -1,
     984,   985,   988,    -1,   143,    -1,   986,    -1,    -1,   986,
     987,    -1,  1098,    -1,  1101,    -1,  1090,    -1,  1074,    -1,
    1082,    -1,  1061,    -1,  1069,    -1,  1065,    -1,   989,    -1,
     990,    -1,    10,   144,    -1,    11,    -1,    10,   991,   144,
      -1,   992,    -1,  1001,    -1,   993,    -1,   992,   993,    -1,
     994,   995,   997,    -1,   105,    -1,    -1,   995,   996,    -1,
    1073,    -1,  1074,    -1,   998,    -1,   999,    -1,    10,   106,
      -1,    11,    -1,    10,  1000,   106,    -1,  1117,    -1,  1002,
      -1,  1001,  1002,    -1,  1003,  1004,  1007,    -1,   117,    -1,
    1005,    -1,    -1,  1005,  1006,    -1,  1100,    -1,  1090,    -1,
    1065,    -1,  1008,    -1,  1009,    -1,    11,    -1,    10,  1010,
     118,    -1,  1149,    -1,    -1,  1012,  1013,  1014,    -1,   149,
      -1,  1108,    -1,  1015,    -1,  1016,    -1,    10,   150,    -1,
      11,    -1,    10,  1017,   150,    -1,  1018,    -1,  1019,    -1,
    1018,  1019,    -1,  1020,  1021,  1024,    -1,   147,    -1,  1022,
      -1,    -1,  1022,  1023,    -1,  1074,    -1,  1090,    -1,  1057,
      -1,  1065,    -1,  1102,    -1,  1025,    -1,  1026,    -1,    10,
     148,    -1,    11,    -1,    10,  1027,   148,    -1,  1028,    -1,
    1029,    -1,  1028,  1029,    -1,  1030,    -1,  1031,    -1,  1032,
      -1,    79,    -1,    80,    -1,    77,  1033,    78,    -1,     5,
      -1,    -1,  1035,  1036,  1037,    -1,   151,    -1,  1111,    -1,
    1038,    -1,  1039,    -1,    10,   152,    -1,    11,    -1,    10,
    1040,   152,    -1,  1041,    -1,  1042,    -1,  1041,  1042,    -1,
    1043,  1044,  1047,    -1,   165,    -1,  1045,    -1,    -1,  1045,
    1046,    -1,  1074,    -1,  1057,    -1,  1065,    -1,  1102,    -1,
    1048,    -1,  1049,    -1,    10,   166,    -1,    11,    -1,    10,
    1050,   166,    -1,  1051,    -1,  1052,    -1,  1051,  1052,    -1,
    1053,    -1,  1054,    -1,  1055,    -1,    79,    -1,    80,    -1,
      77,  1056,    78,    -1,     5,    -1,  1058,    -1,  1059,    -1,
    1060,    -1,    42,    -1,    41,     3,  1118,    -1,  1062,    -1,
    1063,    -1,  1064,    -1,    50,    -1,    49,     3,  1118,    -1,
    1066,    -1,  1067,    -1,  1068,    -1,    44,    -1,    43,     3,
    1118,    -1,  1070,    -1,  1071,    -1,  1072,    -1,    52,    -1,
      51,     3,  1118,    -1,    37,  1118,     6,  1118,    -1,  1075,
      -1,  1076,    -1,  1077,    -1,    46,    -1,    45,     3,  1118,
      -1,  1079,    -1,  1080,    -1,  1081,    -1,    54,    -1,    53,
       3,  1118,    -1,  1083,    -1,  1084,    -1,  1085,    -1,    48,
      -1,    47,     3,  1118,    -1,  1087,    -1,  1088,    -1,  1089,
      -1,    58,    -1,    57,     3,  1118,    -1,  1091,    -1,  1092,
      -1,  1093,    -1,    60,    -1,    59,     3,  1118,    -1,  1095,
      -1,  1096,    -1,  1097,    -1,    56,    -1,    55,     3,  1118,
      -1,    16,  1118,     6,  1118,    -1,    17,  1118,     6,  1118,
      -1,    18,  1118,     6,  1118,    -1,    19,  1118,     6,  1118,
      -1,    21,  1118,     6,  1118,    -1,    22,  1118,     6,  1118,
      -1,    23,  1118,     6,  1118,    -1,    24,  1118,     6,  1118,
      -1,    25,  1118,     6,  1118,    -1,    26,  1118,     6,  1118,
      -1,    27,  1118,     6,  1118,    -1,    28,  1118,     6,  1118,
      -1,    29,  1118,     6,  1118,    -1,    30,  1118,     6,  1118,
      -1,    31,  1118,     6,  1118,    -1,    32,  1118,     6,  1118,
      -1,    33,  1118,     6,  1118,    -1,    34,  1118,     6,  1118,
      -1,     6,    -1,     7,    -1,     4,    -1,     6,    -1,     7,
      -1,  1119,     8,    -1,    -1,  1119,  1120,    -1,   345,    -1,
     346,    -1,   347,    -1,   348,    -1,  1122,  1123,    -1,    65,
      -1,  1124,    -1,  1125,    -1,    10,    66,    -1,    11,    -1,
      10,  1126,    66,    -1,  1127,    -1,  1128,    -1,  1127,  1128,
      -1,  1129,    -1,  1133,    -1,  1137,    -1,  1141,    -1,  1145,
      -1,    -1,  1130,    -1,  1131,    -1,  1132,    -1,   208,    -1,
     207,    -1,   205,     5,   206,    -1,    -1,  1134,    -1,  1135,
      -1,  1136,    -1,   212,    -1,   211,    -1,   209,     5,   210,
      -1,    -1,  1138,    -1,  1139,    -1,  1140,    -1,   216,    -1,
     215,    -1,   213,     5,   214,    -1,    -1,  1142,    -1,  1143,
      -1,  1144,    -1,   220,    -1,   219,    -1,   217,     5,   218,
      -1,    -1,  1146,    -1,  1147,    -1,  1148,    -1,   224,    -1,
     223,    -1,   221,     5,   222,    -1,  1150,    -1,  1157,    -1,
      -1,  1150,  1151,    -1,  1152,  1153,  1156,    -1,   115,    -1,
    1154,    -1,    -1,  1154,  1155,    -1,  1163,    -1,  1162,    -1,
      10,     6,   116,    -1,    97,  1158,  1159,    -1,    40,  1118,
       6,  1118,    -1,  1160,    -1,  1161,    -1,    10,    98,    -1,
      11,    -1,    10,     4,    98,    -1,    38,  1118,     6,  1118,
      -1,    39,  1118,     6,  1118,    -1,    40,  1118,     6,  1118,
      -1,  1160,    -1,  1161,    -1,    10,    98,    -1,    11,    -1,
      10,     4,    98,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   314,   314,   315,   317,   324,   334,   334,   336,   336,
     338,   340,   342,   351,   352,   355,   364,   364,   377,   377,
     379,   393,   393,   395,   395,   397,   399,   401,   401,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   415,   417,
     432,   439,   439,   442,   447,   451,   460,   464,   469,   469,
     471,   473,   475,   475,   477,   482,   492,   498,   498,   501,
     506,   512,   512,   515,   517,   524,   524,   526,   526,   528,
     530,   533,   535,   542,   542,   544,   544,   546,   548,   553,
     555,   562,   562,   564,   564,   566,   568,   573,   575,   582,
     582,   584,   584,   586,   588,   593,   595,   602,   602,   604,
     604,   606,   608,   613,   615,   622,   622,   624,   624,   626,
     628,   633,   635,   642,   642,   644,   644,   646,   648,   653,
     655,   662,   672,   677,   683,   683,   685,   687,   689,   689,
     691,   696,   708,   714,   714,   717,   724,   729,   736,   736,
     740,   740,   742,   753,   753,   755,   755,   757,   759,   761,
     761,   764,   765,   766,   767,   768,   769,   772,   774,   781,
     781,   783,   783,   785,   787,   794,   796,   807,   809,   809,
     812,   818,   824,   826,   832,   834,   845,   847,   847,   850,
     856,   862,   864,   871,   873,   884,   886,   886,   889,   895,
     901,   903,   910,   912,   921,   922,   928,   930,   936,   938,
     945,   955,   960,   966,   966,   968,   970,   972,   972,   974,
     979,   991,   997,   997,  1000,  1007,  1012,  1018,  1018,  1022,
    1022,  1024,  1035,  1035,  1037,  1037,  1039,  1041,  1043,  1043,
    1046,  1047,  1048,  1049,  1050,  1051,  1054,  1056,  1063,  1063,
    1065,  1065,  1067,  1069,  1077,  1079,  1086,  1086,  1088,  1088,
    1090,  1092,  1097,  1099,  1106,  1106,  1108,  1108,  1110,  1112,
    1117,  1119,  1126,  1126,  1128,  1128,  1130,  1132,  1137,  1139,
    1146,  1146,  1148,  1148,  1150,  1152,  1159,  1161,  1168,  1178,
    1183,  1189,  1189,  1191,  1193,  1195,  1195,  1197,  1202,  1214,
    1220,  1220,  1223,  1230,  1235,  1242,  1242,  1245,  1245,  1247,
    1263,  1263,  1265,  1265,  1267,  1269,  1271,  1271,  1274,  1275,
    1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1287,
    1289,  1296,  1296,  1298,  1298,  1300,  1302,  1310,  1312,  1319,
    1319,  1321,  1321,  1323,  1325,  1330,  1332,  1339,  1339,  1341,
    1341,  1343,  1345,  1350,  1352,  1359,  1359,  1361,  1361,  1363,
    1365,  1370,  1372,  1379,  1379,  1381,  1381,  1383,  1385,  1390,
    1392,  1399,  1409,  1414,  1420,  1420,  1422,  1424,  1426,  1426,
    1428,  1430,  1444,  1444,  1447,  1447,  1447,  1447,  1450,  1450,
    1452,  1452,  1454,  1456,  1465,  1466,  1469,  1471,  1482,  1484,
    1484,  1487,  1493,  1499,  1501,  1508,  1510,  1521,  1523,  1523,
    1526,  1532,  1538,  1540,  1547,  1549,  1560,  1562,  1562,  1565,
    1571,  1577,  1579,  1586,  1588,  1598,  1599,  1605,  1607,  1614,
    1616,  1623,  1633,  1638,  1644,  1644,  1646,  1648,  1650,  1650,
    1652,  1657,  1669,  1675,  1675,  1678,  1685,  1690,  1697,  1697,
    1700,  1700,  1702,  1710,  1716,  1716,  1719,  1726,  1732,  1738,
    1746,  1751,  1757,  1757,  1759,  1761,  1763,  1763,  1765,  1767,
    1776,  1778,  1778,  1780,  1780,  1780,  1782,  1792,  1802,  1822,
    1828,  1830,  1840,  1846,  1846,  1849,  1854,  1859,  1869,  1874,
    1880,  1880,  1882,  1884,  1886,  1886,  1888,  1893,  1903,  1909,
    1909,  1912,  1918,  1925,  1925,  1928,  1928,  1930,  1932,  1932,
    1934,  1934,  1936,  1938,  1946,  1946,  1948,  1954,  1954,  1962,
    1962,  1964,  1966,  1968,  1970,  1970,  1972,  1974,  1982,  1987,
    1993,  1993,  1995,  1997,  1999,  1999,  2001,  2012,  2021,  2021,
    2024,  2025,  2028,  2031,  2031,  2033,  2035,  2043,  2048,  2054,
    2054,  2056,  2058,  2060,  2060,  2062,  2073,  2082,  2082,  2085,
    2086,  2090,  2091,  2093,  2093,  2095,  2097,  2102,  2102,  2104,
    2109,  2109,  2111,  2113,  2115,  2117,  2117,  2126,  2128,  2135,
    2135,  2137,  2139,  2141,  2144,  2144,  2154,  2156,  2163,  2163,
    2165,  2167,  2169,  2172,  2172,  2181,  2183,  2190,  2190,  2192,
    2194,  2196,  2199,  2199,  2208,  2210,  2217,  2217,  2219,  2221,
    2223,  2226,  2226,  2235,  2237,  2244,  2244,  2246,  2248,  2250,
    2253,  2253,  2262,  2264,  2271,  2271,  2273,  2275,  2277,  2280,
    2280,  2289,  2291,  2298,  2298,  2300,  2302,  2304,  2307,  2307,
    2309,  2314,  2333,  2339,  2339,  2342,  2353,  2364,  2370,  2376,
    2382,  2388,  2394,  2401,  2401,  2403,  2403,  2405,  2407,  2407,
    2409,  2409,  2411,  2418,  2427,  2427,  2430,  2436,  2443,  2443,
    2445,  2445,  2447,  2449,  2458,  2458,  2460,  2471,  2479,  2485,
    2485,  2488,  2494,  2495,  2499,  2499,  2501,  2503,  2506,  2510,
    2510,  2512,  2520,  2520,  2528,  2528,  2530,  2532,  2534,  2536,
    2536,  2538,  2540,  2548,  2553,  2559,  2559,  2561,  2563,  2566,
    2566,  2568,  2577,  2587,  2587,  2590,  2591,  2594,  2597,  2597,
    2599,  2604,  2604,  2607,  2609,  2611,  2613,  2613,  2622,  2624,
    2631,  2631,  2633,  2635,  2637,  2639,  2639,  2648,  2650,  2657,
    2657,  2659,  2661,  2663,  2666,  2666,  2675,  2677,  2684,  2684,
    2686,  2688,  2690,  2693,  2693,  2702,  2704,  2711,  2711,  2713,
    2715,  2717,  2720,  2720,  2729,  2731,  2738,  2738,  2740,  2742,
    2744,  2747,  2747,  2756,  2758,  2765,  2765,  2767,  2769,  2771,
    2774,  2774,  2783,  2785,  2792,  2792,  2794,  2796,  2798,  2801,
    2801,  2803,  2809,  2828,  2835,  2835,  2838,  2849,  2860,  2866,
    2872,  2878,  2884,  2890,  2899,  2899,  2901,  2901,  2903,  2905,
    2905,  2907,  2907,  2909,  2914,  2924,  2924,  2927,  2932,  2939,
    2939,  2941,  2941,  2943,  2945,  2952,  2952,  2954,  2965,  2973,
    2979,  2979,  2982,  2988,  2989,  2993,  2993,  2995,  2997,  3000,
    3003,  3003,  3005,  3012,  3012,  3020,  3020,  3022,  3024,  3026,
    3028,  3028,  3030,  3033,  3041,  3046,  3052,  3052,  3054,  3056,
    3058,  3058,  3060,  3069,  3078,  3078,  3081,  3082,  3085,  3088,
    3088,  3090,  3095,  3095,  3097,  3099,  3101,  3103,  3103,  3112,
    3114,  3121,  3121,  3123,  3125,  3127,  3129,  3129,  3138,  3140,
    3147,  3147,  3149,  3151,  3153,  3156,  3156,  3165,  3167,  3174,
    3174,  3176,  3178,  3180,  3183,  3183,  3192,  3194,  3201,  3201,
    3203,  3205,  3207,  3210,  3210,  3219,  3221,  3228,  3228,  3230,
    3232,  3234,  3237,  3237,  3246,  3248,  3255,  3255,  3257,  3259,
    3261,  3264,  3264,  3273,  3275,  3282,  3282,  3284,  3286,  3288,
    3291,  3291,  3293,  3299,  3318,  3324,  3324,  3327,  3338,  3349,
    3355,  3361,  3367,  3373,  3379,  3386,  3386,  3388,  3388,  3390,
    3392,  3392,  3394,  3394,  3396,  3403,  3412,  3412,  3416,  3421,
    3429,  3429,  3431,  3431,  3433,  3435,  3442,  3442,  3444,  3455,
    3463,  3469,  3469,  3472,  3478,  3479,  3483,  3483,  3485,  3487,
    3489,  3493,  3493,  3495,  3500,  3509,  3514,  3520,  3520,  3522,
    3524,  3526,  3526,  3528,  3533,  3547,  3555,  3555,  3558,  3564,
    3570,  3576,  3584,  3594,  3599,  3605,  3605,  3607,  3609,  3611,
    3611,  3613,  3619,  3624,  3626,  3626,  3628,  3630,  3642,  3642,
    3644,  3649,  3658,  3663,  3669,  3669,  3671,  3673,  3675,  3675,
    3677,  3682,  3694,  3702,  3702,  3705,  3710,  3716,  3722,  3731,
    3736,  3742,  3742,  3744,  3746,  3748,  3748,  3750,  3756,  3761,
    3763,  3763,  3765,  3767,  3778,  3785,  3785,  3787,  3792,  3797,
    3804,  3804,  3806,  3811,  3816,  3823,  3823,  3825,  3830,  3835,
    3842,  3842,  3844,  3849,  3854,  3862,  3869,  3869,  3871,  3876,
    3881,  3888,  3888,  3890,  3895,  3900,  3907,  3907,  3909,  3914,
    3919,  3926,  3926,  3928,  3933,  3938,  3945,  3945,  3947,  3952,
    3957,  3964,  3964,  3966,  3971,  3977,  3983,  3992,  3998,  4012,
    4021,  4027,  4036,  4042,  4048,  4054,  4060,  4066,  4075,  4081,
    4090,  4095,  4101,  4118,  4119,  4123,  4124,  4125,  4127,  4129,
    4129,  4131,  4132,  4133,  4134,  4171,  4173,  4187,  4187,  4189,
    4189,  4191,  4193,  4195,  4195,  4198,  4199,  4200,  4201,  4202,
    4204,  4204,  4212,  4212,  4214,  4214,  4216,  4222,  4222,  4230,
    4230,  4232,  4232,  4234,  4240,  4240,  4248,  4248,  4250,  4250,
    4252,  4258,  4258,  4266,  4266,  4268,  4268,  4270,  4276,  4276,
    4284,  4284,  4286,  4286,  4288,  4300,  4308,  4310,  4310,  4312,
    4314,  4323,  4325,  4325,  4327,  4327,  4329,  4345,  4347,  4352,
    4352,  4354,  4354,  4357,  4383,  4391,  4448,  4453,  4453,  4455,
    4455,  4457
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
  "ITEMEMPTY", "ACTUALSTARTTIMESTART", "ACTUALSTARTTIMEEND",
  "ATEQUALITYSTART", "ATEQUALITYEND", "ATLOWERSTART", "ATLOWEREND",
  "ATUPPERSTART", "ATUPPEREND", "AVAILABLECPUNUMBERSTART",
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
  "USEDMEMORYEND", "VALUESSTRINGSTART", "VALUESSTRINGEND", "VARSTART",
  "VAREND", "VARIABLESSTART", "VARIABLESEND", "VARIDXSTART", "VARIDXEND",
  "FILENAMESTART", "FILENAMEEND", "FILENAMEEMPTY", "FILENAMESTARTANDEND",
  "FILESOURCESTART", "FILESOURCEEND", "FILESOURCEEMPTY",
  "FILESOURCESTARTANDEND", "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND",
  "FILEDESCRIPTIONEMPTY", "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART",
  "FILECREATOREND", "FILECREATOREMPTY", "FILECREATORSTARTANDEND",
  "FILELICENCESTART", "FILELICENCEEND", "FILELICENCEEMPTY",
  "FILELICENCESTARTANDEND", "MATRIXSTART", "MATRIXEND", "BASEMATRIXEND",
  "BASEMATRIXSTART", "BLOCKSTART", "BLOCKEND", "BLOCKSSTART", "BLOCKSEND",
  "EMPTYSYMMETRYATT", "SYMMETRYATT", "EMPTYEXCLUDEATT", "EXCLUDEATT",
  "CONSTANTATT", "NUMBEROFBLOCKSATT", "NUMBEROFCOLUMNSATT",
  "NUMBEROFROWSATT", "BASEMATRIXIDXATT", "TARGETMATRIXFIRSTROWATT",
  "TARGETMATRIXFIRSTCOLATT", "BASEMATRIXSTARTROWATT",
  "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT", "BASEMATRIXENDCOLATT",
  "SCALARMULTIPLIERATT", "EMPTYBASETRANSPOSEATT", "BASETRANSPOSEATT",
  "ELEMENTSSTART", "ELEMENTSEND", "CONSTANTELEMENTSSTART",
  "CONSTANTELEMENTSEND", "STARTVECTORSTART", "STARTVECTOREND",
  "NONZEROSSTART", "NONZEROSEND", "INDEXESSTART", "INDEXESEND",
  "VALUESSTART", "VALUESEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "GENERALELEMENTSSTART", "GENERALELEMENTSEND",
  "CONREFERENCEELEMENTSSTART", "CONREFERENCEELEMENTSEND",
  "OBJREFERENCEELEMENTSSTART", "OBJREFERENCEELEMENTSEND",
  "PATTERNELEMENTSSTART", "PATTERNELEMENTSEND", "TRANSFORMATIONSTART",
  "TRANSFORMATIONEND", "COLOFFSETSSTART", "COLOFFSETSEND",
  "ROWOFFSETSSTART", "ROWOFFSETSEND", "EMPTYROWMAJORATT", "ROWMAJORATT",
  "BLOCKROWIDXATT", "BLOCKCOLIDXATT", "DUMMY", "NONLINEAREXPRESSIONSSTART",
  "NONLINEAREXPRESSIONSEND", "NUMBEROFNONLINEAREXPRESSIONS", "NLSTART",
  "NLEND", "POWERSTART", "POWEREND", "PLUSSTART", "PLUSEND", "MINUSSTART",
  "MINUSEND", "DIVIDESTART", "DIVIDEEND", "LNSTART", "LNEND", "SQRTSTART",
  "SQRTEND", "SUMSTART", "SUMEND", "PRODUCTSTART", "PRODUCTEND",
  "EXPSTART", "EXPEND", "NEGATESTART", "NEGATEEND", "IFSTART", "IFEND",
  "SQUARESTART", "SQUAREEND", "COSSTART", "COSEND", "SINSTART", "SINEND",
  "VARIABLESTART", "VARIABLEEND", "ABSSTART", "ABSEND", "ERFSTART",
  "ERFEND", "MAXSTART", "MAXEND", "ALLDIFFSTART", "ALLDIFFEND", "MINSTART",
  "MINEND", "ESTART", "EEND", "PISTART", "PIEND", "TIMESSTART", "TIMESEND",
  "NUMBERSTART", "NUMBEREND", "MATRIXTRACESTART", "MATRIXTRACEEND",
  "MATRIXTOSCALARSTART", "MATRIXTOSCALAREND", "IDATT", "COEFATT", "' '",
  "'\\t'", "'\\r'", "'\\n'", "$accept", "osrldoc", "osrlStartEmpty",
  "osrlStart", "osrlAttributes", "osrlContent", "osrlEmpty", "osrlLaden",
  "osrlEnd", "osrlEnding", "osrlBody", "headerElement", "generalElement",
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
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   349,   350,   350,   351,   352,   353,   353,   354,   354,
     355,   356,   357,   358,   358,   359,   360,   360,   361,   361,
     362,   363,   363,   364,   364,   365,   366,   367,   367,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   369,   370,
     371,   372,   372,   373,   373,   373,   374,   374,   375,   375,
     376,   377,   378,   378,   379,   380,   381,   382,   382,   383,
     383,   384,   384,   385,   386,   387,   387,   388,   388,   389,
     390,   391,   392,   393,   393,   394,   394,   395,   396,   397,
     398,   399,   399,   400,   400,   401,   402,   403,   404,   405,
     405,   406,   406,   407,   408,   409,   410,   411,   411,   412,
     412,   413,   414,   415,   416,   417,   417,   418,   418,   419,
     420,   421,   422,   423,   423,   424,   424,   425,   426,   427,
     428,   429,   430,   430,   431,   431,   432,   433,   434,   434,
     435,   436,   437,   438,   438,   439,   439,   439,   440,   440,
     441,   441,   442,   443,   443,   444,   444,   445,   446,   447,
     447,   448,   448,   448,   448,   448,   448,   449,   450,   451,
     451,   452,   452,   453,   454,   455,   456,   457,   458,   458,
     459,   459,   460,   461,   462,   463,   464,   465,   465,   466,
     466,   467,   468,   469,   470,   471,   472,   472,   473,   473,
     474,   475,   476,   477,   478,   478,   479,   480,   481,   482,
     483,   484,   484,   485,   485,   486,   487,   488,   488,   489,
     490,   491,   492,   492,   493,   493,   493,   494,   494,   495,
     495,   496,   497,   497,   498,   498,   499,   500,   501,   501,
     502,   502,   502,   502,   502,   502,   503,   504,   505,   505,
     506,   506,   507,   508,   509,   510,   511,   511,   512,   512,
     513,   514,   515,   516,   517,   517,   518,   518,   519,   520,
     521,   522,   523,   523,   524,   524,   525,   526,   527,   528,
     529,   529,   530,   530,   531,   532,   533,   534,   535,   536,
     536,   537,   537,   538,   539,   540,   540,   541,   542,   543,
     544,   544,   545,   545,   545,   546,   546,   547,   547,   548,
     549,   549,   550,   550,   551,   552,   553,   553,   554,   554,
     554,   554,   554,   554,   554,   554,   554,   554,   554,   555,
     556,   557,   557,   558,   558,   559,   560,   561,   562,   563,
     563,   564,   564,   565,   566,   567,   568,   569,   569,   570,
     570,   571,   572,   573,   574,   575,   575,   576,   576,   577,
     578,   579,   580,   581,   581,   582,   582,   583,   584,   585,
     586,   587,   588,   588,   589,   589,   590,   591,   592,   592,
     593,   594,   595,   595,   596,   596,   596,   596,   597,   597,
     598,   598,   599,   600,   601,   601,   602,   603,   604,   605,
     605,   606,   606,   607,   608,   609,   610,   611,   612,   612,
     613,   613,   614,   615,   616,   617,   618,   619,   619,   620,
     620,   621,   622,   623,   624,   625,   625,   626,   627,   628,
     629,   630,   631,   631,   632,   632,   633,   634,   635,   635,
     636,   637,   638,   639,   639,   640,   640,   640,   641,   641,
     642,   642,   643,   644,   645,   645,   646,   646,   646,   646,
     647,   647,   648,   648,   649,   650,   651,   651,   652,   653,
     654,   655,   655,   656,   656,   656,   657,   658,   659,   660,
     661,   662,   663,   664,   664,   665,   665,   665,   666,   666,
     667,   667,   668,   669,   670,   670,   671,   672,   673,   674,
     674,   675,   675,   676,   676,   677,   677,   678,   679,   679,
     680,   680,   681,   682,   683,   683,   684,   685,   685,   686,
     686,   687,   688,   689,   690,   690,   691,   692,   693,   693,
     694,   694,   695,   696,   697,   697,   698,   699,   700,   700,
     701,   701,   702,   703,   703,   704,   705,   706,   706,   707,
     707,   708,   709,   710,   710,   711,   712,   713,   713,   714,
     714,   715,   715,   716,   716,   717,   718,   719,   719,   720,
     721,   721,   722,   723,   724,   725,   725,   726,   727,   728,
     728,   729,   730,   731,   732,   732,   733,   734,   735,   735,
     736,   737,   738,   739,   739,   740,   741,   742,   742,   743,
     744,   745,   746,   746,   747,   748,   749,   749,   750,   751,
     752,   753,   753,   754,   755,   756,   756,   757,   758,   759,
     760,   760,   761,   762,   763,   763,   764,   765,   766,   767,
     767,   768,   769,   770,   770,   771,   772,   773,   774,   774,
     775,   776,   777,   778,   778,   779,   779,   779,   779,   779,
     779,   779,   779,   780,   780,   781,   781,   782,   783,   783,
     784,   784,   785,   786,   787,   787,   788,   788,   789,   789,
     790,   790,   791,   792,   793,   793,   794,   795,   796,   797,
     797,   798,   798,   798,   799,   799,   800,   801,   802,   803,
     803,   804,   805,   805,   806,   806,   807,   808,   809,   810,
     810,   811,   812,   813,   813,   814,   814,   815,   816,   817,
     817,   818,   819,   820,   820,   821,   821,   822,   823,   823,
     824,   825,   825,   826,   827,   828,   829,   829,   830,   831,
     832,   832,   833,   834,   835,   836,   836,   837,   838,   839,
     839,   840,   841,   842,   843,   843,   844,   845,   846,   846,
     847,   848,   849,   850,   850,   851,   852,   853,   853,   854,
     855,   856,   857,   857,   858,   859,   860,   860,   861,   862,
     863,   864,   864,   865,   866,   867,   867,   868,   869,   870,
     871,   871,   872,   873,   874,   874,   875,   876,   877,   878,
     878,   879,   880,   881,   882,   882,   883,   883,   883,   883,
     883,   883,   883,   883,   884,   884,   885,   885,   886,   887,
     887,   888,   888,   889,   890,   891,   891,   892,   892,   893,
     893,   894,   894,   895,   896,   897,   897,   898,   899,   900,
     901,   901,   902,   902,   902,   903,   903,   904,   905,   906,
     907,   907,   908,   909,   909,   910,   910,   911,   912,   913,
     914,   914,   915,   916,   917,   917,   918,   918,   919,   920,
     921,   921,   922,   923,   924,   924,   925,   925,   926,   927,
     927,   928,   929,   929,   930,   931,   932,   933,   933,   934,
     935,   936,   936,   937,   938,   939,   940,   940,   941,   942,
     943,   943,   944,   945,   946,   947,   947,   948,   949,   950,
     950,   951,   952,   953,   954,   954,   955,   956,   957,   957,
     958,   959,   960,   961,   961,   962,   963,   964,   964,   965,
     966,   967,   968,   968,   969,   970,   971,   971,   972,   973,
     974,   975,   975,   976,   977,   978,   978,   979,   980,   981,
     982,   982,   983,   984,   985,   986,   986,   987,   987,   987,
     987,   987,   987,   987,   987,   988,   988,   989,   989,   990,
     991,   991,   992,   992,   993,   994,   995,   995,   996,   996,
     997,   997,   998,   998,   999,  1000,  1001,  1001,  1002,  1003,
    1004,  1005,  1005,  1006,  1006,  1006,  1007,  1007,  1008,  1009,
    1010,  1011,  1011,  1012,  1013,  1014,  1014,  1015,  1015,  1016,
    1017,  1018,  1018,  1019,  1020,  1021,  1022,  1022,  1023,  1023,
    1023,  1023,  1023,  1024,  1024,  1025,  1025,  1026,  1027,  1028,
    1028,  1029,  1030,  1030,  1031,  1031,  1032,  1033,  1034,  1034,
    1035,  1036,  1037,  1037,  1038,  1038,  1039,  1040,  1041,  1041,
    1042,  1043,  1044,  1045,  1045,  1046,  1046,  1046,  1046,  1047,
    1047,  1048,  1048,  1049,  1050,  1051,  1051,  1052,  1053,  1053,
    1054,  1054,  1055,  1056,  1057,  1058,  1058,  1059,  1060,  1061,
    1062,  1062,  1063,  1064,  1065,  1066,  1066,  1067,  1068,  1069,
    1070,  1070,  1071,  1072,  1073,  1074,  1075,  1075,  1076,  1077,
    1078,  1079,  1079,  1080,  1081,  1082,  1083,  1083,  1084,  1085,
    1086,  1087,  1087,  1088,  1089,  1090,  1091,  1091,  1092,  1093,
    1094,  1095,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1116,  1117,  1117,  1117,  1118,  1119,
    1119,  1120,  1120,  1120,  1120,  1121,  1122,  1123,  1123,  1124,
    1124,  1125,  1126,  1127,  1127,  1128,  1128,  1128,  1128,  1128,
    1129,  1129,  1130,  1130,  1131,  1131,  1132,  1133,  1133,  1134,
    1134,  1135,  1135,  1136,  1137,  1137,  1138,  1138,  1139,  1139,
    1140,  1141,  1141,  1142,  1142,  1143,  1143,  1144,  1145,  1145,
    1146,  1146,  1147,  1147,  1148,  1149,  1149,  1150,  1150,  1151,
    1152,  1153,  1154,  1154,  1155,  1155,  1156,  1157,  1158,  1159,
    1159,  1160,  1160,  1161,  1162,  1163,  1158,  1159,  1159,  1160,
    1160,  1161
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
#define YYPACT_NINF -1353
static const yytype_int16 yypact[] =
{
     106, -1353, -1353,    56,    -5,   118, -1353, -1353,   137,    89,
   -1353,   168, -1353,   200, -1353, -1353, -1353, -1353,   130,   239,
     364, -1353, -1353, -1353, -1353,    -5, -1353, -1353, -1353, -1353,
   -1353,   101,   323,     0, -1353, -1353, -1353, -1353, -1353,   201,
   -1353, -1353,   224, -1353, -1353,   226, -1353, -1353,   231, -1353,
   -1353,   238, -1353, -1353,   138,   510, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353,   137, -1353,   206,
     353,   -11, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353,   216,   174, -1353, -1353,
     310, -1353,   365, -1353,   380, -1353,   390, -1353,   393, -1353,
     400, -1353,   426, -1353,   428, -1353,   278,   100,   114,    96,
      95,    98, -1353, -1353, -1353, -1353,   247,   438,   112, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
     256,   -10, -1353, -1353,   440, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,   413, -1353,   278, -1353, -1353, -1353,   325, -1353,
     327, -1353,   452,   310, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353,    33, -1353, -1353, -1353, -1353,    24,
   -1353, -1353, -1353, -1353,    27, -1353, -1353, -1353, -1353,    38,
   -1353, -1353, -1353, -1353,    37, -1353, -1353, -1353, -1353,    21,
   -1353, -1353, -1353, -1353,    18, -1353, -1353, -1353, -1353, -1353,
     473, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
      99, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,   271,   -39, -1353, -1353,   475, -1353,   482, -1353,
     485, -1353,   487, -1353,   495, -1353,   278, -1353, -1353,    25,
   -1353, -1353, -1353, -1353,   335,    85,   350,    85,   359,    85,
     361, -1353,   497, -1353,   367,     4, -1353, -1353,   -67, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353,   243, -1353, -1353,   229,
   -1353, -1353,   228, -1353, -1353,   269, -1353, -1353,   274, -1353,
   -1353,   270, -1353, -1353,   259,   458,    92, -1353, -1353, -1353,
   -1353,   499,   199, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353,   397,    94, -1353, -1353,   501,
   -1353,   504, -1353,   512, -1353,   514, -1353,   516, -1353,   435,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353,   413, -1353,   278,
   -1353, -1353,    39, -1353, -1353, -1353, -1353,    44, -1353, -1353,
   -1353, -1353,     9, -1353, -1353, -1353, -1353,    13, -1353, -1353,
   -1353, -1353,    28, -1353, -1353, -1353, -1353,   519, -1353, -1353,
   -1353,   297,   525, -1353,   478, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,   525, -1353, -1353, -1353, -1353,   525, -1353, -1353,
   -1353, -1353,   494, -1353,   102, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
     398,   394, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353,   389,   395, -1353, -1353,   -24, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353,    26, -1353, -1353, -1353, -1353,    19,
   -1353, -1353, -1353, -1353,    42, -1353, -1353, -1353, -1353,    62,
   -1353, -1353, -1353, -1353,    40, -1353, -1353, -1353, -1353, -1353,
     523, -1353,   526,    85,   530,    85,   557,    85,   560, -1353,
     533, -1353, -1353, -1353,   470, -1353, -1353,   476, -1353, -1353,
     408, -1353, -1353,   423, -1353, -1353, -1353,   451, -1353,   119,
   -1353, -1353, -1353, -1353, -1353,   545, -1353, -1353,   536, -1353,
     537, -1353, -1353,   561, -1353, -1353,   507,   531, -1353, -1353,
   -1353, -1353, -1353,   535,   337, -1353, -1353, -1353,   538,   444,
   -1353, -1353,   571,   -51, -1353, -1353,   703,   707,   714,   718,
   -1353, -1353,   564, -1353, -1353,   569, -1353, -1353,   539, -1353,
   -1353,   619, -1353, -1353,   583,   752,   -36, -1353, -1353, -1353,
   -1353,   525, -1353, -1353, -1353, -1353,   525, -1353, -1353, -1353,
   -1353,   525, -1353, -1353, -1353, -1353,   753, -1353,   126, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
     614,   618, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353,   541,   444,   590, -1353, -1353,   760, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353,   620, -1353, -1353,   762, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
     739,   758,   113, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353,   586,   594, -1353, -1353,   578,
   -1353,   577, -1353,   584, -1353, -1353,   585, -1353, -1353,   631,
     636, -1353, -1353, -1353, -1353,   543,   444,   634, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   546,
   -1353,   616, -1353, -1353,   777,   778, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353,   351, -1353, -1353,
   -1353, -1353, -1353, -1353,   549,   444,   640, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353,   779,   -64, -1353, -1353,
   -1353, -1353, -1353,   653,   310,   781, -1353, -1353,    20, -1353,
     785, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353,   646, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353,   637,   626, -1353, -1353, -1353,   592,
     551,   553,   310, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353,   617, -1353, -1353, -1353, -1353, -1353, -1353,
     579,   434, -1353,   655,   766,    36, -1353, -1353, -1353, -1353,
     110, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   -16,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353,   691,   771, -1353,   581, -1353, -1353, -1353,   665, -1353,
   -1353,   632,   630, -1353, -1353,   797, -1353, -1353, -1353,   638,
     179, -1353, -1353, -1353, -1353,   799, -1353,   654,   782, -1353,
     587, -1353,   801,   547, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353,   589,   292, -1353,   732, -1353, -1353, -1353, -1353,   650,
     786, -1353,   591, -1353,   803,   554, -1353, -1353, -1353, -1353,
   -1353, -1353,   612,   622,   783,   648, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353,   595, -1353,   811,   705, -1353,
   -1353, -1353, -1353, -1353, -1353,   683,   721,   802, -1353, -1353,
   -1353,   722,   783, -1353,   597, -1353, -1353,   819,   146, -1353,
   -1353, -1353, -1353, -1353, -1353,   719,   727,   810, -1353, -1353,
   -1353, -1353,   599, -1353,   603, -1353, -1353, -1353,   605,   613,
   -1353,   823,  -151, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
     680,   684, -1353, -1353, -1353, -1353, -1353, -1353,   625, -1353,
     627, -1353,   692,   735, -1353, -1353, -1353, -1353,   826,  -103,
   -1353, -1353, -1353, -1353,   694,   741, -1353, -1353, -1353, -1353,
     443, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   576,   642,
   -1353, -1353, -1353, -1353, -1353,   633,   401,   700,   743, -1353,
   -1353, -1353, -1353,   838,   103, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353,   745,   761,   827, -1353, -1353, -1353,   588,
     713, -1353, -1353, -1353, -1353, -1353, -1353,   747,   768,   827,
   -1353, -1353,   656,   657, -1353, -1353, -1353, -1353, -1353,    80,
      14, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353,   755,   770,   827, -1353, -1353,
   -1353,   748,   754, -1353, -1353,   635,   574, -1353, -1353,   773,
     827, -1353,   639, -1353, -1353, -1353, -1353,   322,   645,   621,
   -1353, -1353,   774,   827,   647, -1353, -1353, -1353,   209,   525,
   -1353, -1353, -1353, -1353, -1353,   853, -1353, -1353, -1353,   715,
     237, -1353, -1353, -1353, -1353,   649,   369, -1353, -1353,   780,
     827,   652, -1353, -1353, -1353, -1353,   386,   -22, -1353, -1353,
   -1353, -1353, -1353,   861, -1353,   862, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353,   787,   827,   660, -1353,   860,   772, -1353,
   -1353, -1353, -1353,   525, -1353, -1353, -1353, -1353,   -52, -1353,
   -1353, -1353, -1353,   865, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   789,   827,
     668, -1353,   772, -1353, -1353, -1353, -1353,     7, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353,   673,   868, -1353,   798, -1353,
   -1353,   -28, -1353, -1353, -1353, -1353,   872, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353,   794,   827,   672, -1353,   772, -1353, -1353, -1353, -1353,
     525, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   734,   749,
   -1353, -1353,   763, -1353, -1353,   873, -1353, -1353, -1353,   756,
     827,   675, -1353,   772, -1353, -1353, -1353, -1353, -1353,   841,
     788, -1353,   767, -1353,   750, -1353, -1353, -1353,   751,   688,
   -1353, -1353,   775, -1353, -1353, -1353, -1353,   764,   827,   677,
   -1353,   772, -1353, -1353, -1353, -1353,   790, -1353, -1353, -1353,
     696, -1353, -1353, -1353, -1353, -1353, -1353,   757,   784, -1353,
   -1353,   791, -1353, -1353, -1353, -1353,   765,   827,   679, -1353,
     772, -1353, -1353, -1353, -1353,   800, -1353,   792, -1353, -1353,
     230, -1353,   681,    55, -1353, -1353, -1353, -1353,   710,   827,
     685, -1353,   772, -1353, -1353, -1353, -1353,   805, -1353, -1353,
   -1353,   687, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   263,
   -1353,   689,    55, -1353, -1353,   724,   827,   695, -1353,   772,
   -1353, -1353, -1353, -1353,   813, -1353, -1353, -1353, -1353, -1353,
   -1353,   301, -1353,   697,    55, -1353, -1353,   729,   827,   701,
   -1353,   772, -1353, -1353, -1353, -1353,   818, -1353, -1353, -1353,
      32, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   772, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   720,
     827,   725, -1353,   772, -1353, -1353, -1353, -1353,   817, -1353,
   -1353,   903,    41, -1353, -1353, -1353, -1353,   900,   699,     3,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353,   772, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353,   726,   827,   731,
   -1353,   772, -1353, -1353, -1353, -1353,   824, -1353, -1353,    47,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353,   772, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353,   728,   827,   733,
   -1353,   772, -1353, -1353, -1353, -1353,   828, -1353, -1353, -1353,
   -1353, -1353, -1353,   793, -1353,   796, -1353, -1353, -1353,   827,
     736, -1353,   772, -1353, -1353, -1353, -1353,   833, -1353, -1353,
   -1353,   820, -1353,   905, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353,   723, -1353,   804, -1353, -1353, -1353,   827,   738, -1353,
     772, -1353, -1353, -1353, -1353,   836, -1353, -1353, -1353,   815,
   -1353,   806, -1353, -1353, -1353,   827,   740, -1353,   772, -1353,
   -1353, -1353, -1353,   842, -1353, -1353, -1353, -1353,   742, -1353,
     772, -1353, -1353, -1353, -1353,   795, -1353, -1353, -1353, -1353,
     812,   921,   924, -1353, -1353,   744, -1353,   772, -1353, -1353,
   -1353, -1353,   807, -1353, -1353, -1353, -1353,   746, -1353,   772,
   -1353, -1353, -1353, -1353,   808, -1353, -1353,   772, -1353, -1353,
   -1353, -1353,   759, -1353, -1353, -1353, -1353, -1353,   772, -1353,
   -1353, -1353, -1353,   769, -1353, -1353,   772, -1353, -1353, -1353,
   -1353,   776, -1353, -1353,   809, -1353, -1353, -1353, -1353,   814,
   -1353, -1353,   816, -1353, -1353, -1353, -1353, -1353
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   854, -1353,
     907, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   837,
   -1353, -1353, -1353, -1353,   821, -1353, -1353, -1353, -1353, -1353,
     524, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353,   511, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   822,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
     422, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353,   708, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,   349, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353,   628, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353,   296, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353,   285, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353,   414, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353,   186, -1353, -1353, -1353,
   -1353, -1353,   127, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   -27,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,   -72, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353,  -306, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353,  -308, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   -55,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
    -273, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,  -275,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353,   -94, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353,  -329, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353,  -331, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
      23, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
    -129, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353,   207, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353,   135, -1353, -1353, -1353, -1353,  -777, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353,  -150, -1353, -1353, -1353,
    -993, -1353, -1353, -1353, -1059,  -528, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353,  -691, -1353, -1353, -1353,  -243, -1353, -1353,
   -1353,  -597, -1353, -1353, -1353, -1353, -1353, -1353, -1353,  -130,
   -1353,  -998,  -973,   -19,   -88, -1353, -1353, -1353,  -134, -1353,
   -1353, -1353, -1353,  -638, -1353,  -878, -1353,  -369, -1352,  -209,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,   914,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1085, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     295,   621,   261,   506,   806,   673,   741,  1479,  1146,  1480,
    1481,  1278,   400,   509,   386,   488,   391,   491,   511,  1183,
     263,  1075,   292,   543,   930,   289,   770,   771,   277,   369,
     540,   280,  1007,   765,   494,   495,  1479,   274,  1480,  1481,
     816,   286,   283,   482,   552,  1501,   546,  1223,   976,  1102,
     485,  1479,   530,  1480,  1481,   408,     6,   406,   407,   133,
       7,   825,  1136,   826,   827,  1255,   549,  1512,    86,   712,
     226,   765,   227,  1061,   672,  1171,  1157,  1284,   134,   134,
     135,   135,   136,   136,   137,   137,   766,  1277,   752,  1285,
    1079,  1085,  1256,  1086,  1087,  1225,  1165,  1530,   158,   159,
     627,   753,  1214,  1204,   409,   377,   228,   385,   749,   390,
     531,   977,   368,  1226,   617,   618,  1286,  1080,     1,     2,
     229,    87,  1227,  1209,   766,   606,   607,    88,   158,   159,
    1306,    89,    12,    90,   138,   138,  1242,   531,   711,  1502,
     230,   643,   374,   375,   550,    91,   231,  1257,   644,   683,
     828,   483,    14,  1528,   486,    92,    17,    93,  1328,  1008,
     553,   880,  1088,    94,   139,   139,   284,   275,  1482,   287,
     817,  1270,    78,   303,   684,   304,   685,   748,    20,    21,
     304,    95,   278,   281,   225,   290,  1355,   479,   496,   544,
     520,  1166,   650,   492,   541,   489,   547,   652,   772,    30,
     293,   370,   654,  1510,   122,   481,   117,  1279,  1049,  1036,
      25,    26,   525,   305,  1299,  1377,   433,  1050,   305,  1177,
    1178,   226,   434,   227,   536,   537,   538,   539,   435,   118,
     565,   119,   570,   436,   575,   422,   120,  1409,   423,   306,
    1380,  1381,  1321,   121,   306,   514,  1080,   307,   515,    33,
      34,  1386,   307,   808,   606,   607,   825,   228,   826,   827,
     555,   308,   588,   309,  1447,   589,   308,  1080,   309,   657,
    1348,   229,   658,  1419,  1420,   606,   607,   310,   819,   125,
    1425,   820,   310,   311,   155,   312,  1477,   313,   311,   314,
     312,   230,   313,   938,   314,    87,   939,   231,   595,  1370,
    1080,    88,  1455,  1486,   209,    89,   212,    90,   606,   607,
     214,  1449,  1450,   215,  1085,  1396,  1086,  1087,  1498,    91,
     216,  1402,   217,   564,   213,   569,   247,   574,   266,    92,
     267,    93,  1143,    81,    82,   158,   159,    94,  1080,   160,
     161,   157,  1514,   340,  1435,   372,   606,   607,  1440,   401,
     402,   403,   404,   158,   159,    95,  1526,   160,   161,  1080,
     382,   728,   729,   128,   129,  1128,  1465,   606,   607,   387,
    1470,   392,  1532,   399,   609,   174,   175,   414,  1159,   620,
     158,   159,   606,   607,   416,   949,  1544,   415,  1112,  1039,
     179,   180,   730,   731,   158,   159,  1220,   417,   160,   161,
     184,   185,  1491,   189,   190,  1206,   418,  1556,   374,   375,
     194,   195,   158,   159,   606,   607,   160,   161,  1196,  1197,
    1113,  1114,   804,  1080,   690,   691,   692,   693,   617,   618,
      38,   606,   607,   694,   419,  1573,   199,   200,   204,   205,
    1519,   420,   730,   731,   158,   159,   606,   607,   220,   221,
     249,   250,   671,  1585,   742,   804,   158,   159,  1038,  1129,
     617,   618,   268,   269,   421,  1593,   714,   469,   715,   716,
    1537,   442,  1160,   504,   725,   730,   731,   158,   159,   606,
     607,   507,  1604,   296,   297,   342,   343,   158,   159,   606,
     607,  1549,   347,   348,  1612,   352,   353,   357,   358,  1207,
     512,  1084,  1615,   617,   618,   362,   363,   394,   395,   428,
     429,   444,   445,  1620,   449,   450,   710,   768,   769,  1566,
     521,  1623,   454,   455,   459,   460,   464,   465,  1123,   499,
     500,   494,   495,   556,   557,   526,   561,  1578,   422,  1147,
     566,  1158,   777,   578,   579,   603,   604,   740,   614,   615,
    1184,   667,   668,   706,   707,   747,   717,   718,   796,   743,
     744,   785,   786,   790,   791,   409,   798,   571,  1205,    39,
     576,    40,    41,    42,   764,    43,    44,    45,  1224,    46,
      47,    48,   583,    49,    50,    51,   584,    52,    53,   799,
     800,   843,   844,  1112,   585,   835,   923,   865,   866,   875,
     876,   888,   889,   586,   842,   908,   909,   932,   933,   953,
     954,   587,   764,   959,   960,   965,   966,   158,   159,   606,
     607,   160,   161,   970,   971,  1113,  1114,  1115,  1116,   597,
     864,   807,   596,   617,   618,   988,   989,   994,   995,   594,
    1112,  1020,  1021,  1030,  1031,  1107,  1108,   626,   882,  1138,
    1139,   598,   887,   599,   903,  1148,  1149,  1172,  1173,  1191,
    1192,   898,  1215,  1216,   158,   159,   606,   607,   160,   161,
    1243,  1244,  1113,  1114,   514,   907,  1153,  1154,  1271,  1272,
     617,   618,  1300,  1301,   918,  1322,  1323,  1349,  1350,  1371,
    1372,  1388,  1389,   639,   931,  1403,  1404,  1412,  1413,  1427,
    1428,   640,   879,   641,   944,  1441,  1442,  1457,  1458,   633,
    1185,  1471,  1472,   634,   958,    39,  1395,    40,    41,    42,
     635,    43,    44,    45,   636,    46,    47,    48,   982,    49,
      50,    51,   637,    52,    53,  1492,  1493,  1505,  1506,   638,
     993,  1520,  1521,  1538,  1539,  1434,  1550,  1551,  1567,  1568,
    1579,  1580,  1587,  1588,  1598,  1599,  1606,  1607,   642,   655,
     663,   588,   674,   675,   676,   677,  1026,  1464,   681,   678,
     695,   643,   698,   699,  1254,   701,   700,   702,   713,   657,
     726,   727,  1387,   722,   750,   751,   758,   767,   775,   778,
     776,   753,   810,   782,   813,   797,   839,  1064,   836,   848,
     849,   820,   853,   858,   855,   857,   861,   870,   871,   893,
     881,  1426,   883,   884,   899,   894,   903,   913,   914,   900,
     906,   919,   920,   926,   923,   937,   949,   945,   946,   975,
     983,   938,  1006,  1456,  1002,   999,  1037,  1013,  1027,  1103,
    1016,   976,  1044,  1041,  1048,  1061,  1058,  1057,  1007,  1070,
    1065,  1307,  1137,  1071,  1076,  1098,  1021,  1097,  1187,  1049,
    1132,  1167,  1104,  1189,  1236,  1237,  1248,  1210,  1265,  1249,
    1238,  1186,  1266,  1281,  1282,  1294,  1283,  1295,  1308,  1314,
    1225,  1330,  1333,  1398,  1226,  1317,  1336,  1257,  1332,  1284,
    1356,  1410,  1255,  1344,  1366,  1337,  1357,  1436,  1379,  1448,
    1378,  1359,  1466,  1235,  1478,  1499,  1118,  1487,  1285,  1500,
    1503,  1560,  1527,  1515,  1547,  1533,  1545,  1557,  1559,  1156,
    1574,  1575,  1564,  1563,  1576,  1594,  1586,  1596,  1595,  1546,
    1597,   124,    77,  1616,   156,   522,   527,  1605,  1613,   600,
     664,   341,   696,  1621,   443,   703,  1203,   628,   795,   850,
    1624,  1077,  1028,  1338,  1340,  1066,  1309,  1311,  1105,  1360,
    1362,  1190,   779,   248,   984,   856,  1208,  1040,  1131,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1625,     0,     0,
       0,     0,  1626,     0,  1627,     0,     0,     0,     0,     0,
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
     209,   529,   152,   372,   781,   602,   697,     4,  1067,     6,
       7,     4,     8,   382,   257,     6,   259,     4,   387,  1078,
     154,  1019,     4,     4,   902,     4,     6,     7,     4,     4,
       4,     4,   135,   724,     6,     7,     4,     4,     6,     7,
       4,     4,     4,     4,     4,     4,     4,  1106,   199,  1047,
       6,     4,    76,     6,     7,   122,     0,   266,   267,    70,
      65,    77,  1060,    79,    80,   117,     4,  1419,    68,   666,
     109,   762,   111,    18,   602,  1073,  1069,   105,    89,    89,
      91,    91,    93,    93,    95,    95,   724,  1172,   152,   117,
      10,    77,   144,    79,    80,   117,  1069,  1449,    43,    44,
     151,   165,  1100,  1096,   171,   255,   145,   257,   705,   259,
     161,   262,   246,   135,    59,    60,   144,    37,    12,    13,
     159,   121,   144,  1096,   762,    45,    46,   127,    43,    44,
    1215,   131,    14,   133,   145,   145,  1134,   161,   666,    98,
     179,   177,    57,    58,    82,   145,   185,   199,   184,    36,
     166,   112,    15,   106,   110,   155,    67,   157,  1243,   262,
     120,   852,   148,   163,   175,   175,   128,   134,   136,   132,
     134,  1169,    71,    74,    61,    81,    63,   705,    10,    11,
      81,   181,   158,   156,    72,   164,  1271,   337,   160,   170,
     399,  1069,   561,   180,   168,   186,   154,   566,   178,    69,
     182,   176,   571,   200,    66,   339,     5,   200,   105,   986,
      10,    11,   421,   119,  1212,  1300,    17,   114,   119,    10,
      11,   109,    23,   111,   433,   434,   435,   436,    29,     5,
     473,     5,   475,    34,   477,   143,     5,  1322,   146,   145,
      10,    11,  1240,     5,   145,   143,    37,   153,   146,    10,
      11,  1310,   153,   781,    45,    46,    77,   145,    79,    80,
     469,   167,   143,   169,  1349,   146,   167,    37,   169,   143,
    1268,   159,   146,    10,    11,    45,    46,   183,   168,    73,
    1339,   171,   183,   189,    68,   191,  1371,   193,   189,   195,
     191,   179,   193,   147,   195,   121,   150,   185,   507,  1297,
      37,   127,  1361,  1388,    26,   131,   206,   133,    45,    46,
     214,    10,    11,   218,    77,  1313,    79,    80,  1403,   145,
     222,  1319,    75,   473,   210,   475,    70,   477,     3,   155,
       3,   157,    10,    10,    11,    43,    44,   163,    37,    47,
      48,    31,  1427,    72,  1342,    10,    45,    46,  1346,   345,
     346,   347,   348,    43,    44,   181,  1441,    47,    48,    37,
      10,    10,    11,    10,    11,  1056,  1364,    45,    46,    10,
    1368,    10,  1457,     6,   524,    10,    11,   134,  1069,   529,
      43,    44,    45,    46,   156,    16,  1471,   158,    19,   986,
      10,    11,    41,    42,    43,    44,    10,   128,    47,    48,
      10,    11,  1400,    10,    11,  1096,   132,  1492,    57,    58,
      10,    11,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    21,    37,   633,   634,   635,   636,    59,    60,
      66,    45,    46,   642,   164,  1520,    10,    11,    10,    11,
    1438,   182,    41,    42,    43,    44,    45,    46,    10,    11,
      10,    11,   602,  1538,   697,    21,    43,    44,   986,  1056,
      59,    60,    10,    11,     6,  1550,   675,    32,   677,   678,
    1468,    74,  1069,   176,   683,    41,    42,    43,    44,    45,
      46,     3,  1567,    10,    11,    10,    11,    43,    44,    45,
      46,  1489,    10,    11,  1579,    10,    11,    10,    11,  1096,
       6,  1029,  1587,    59,    60,    10,    11,    10,    11,    10,
      11,    10,    11,  1598,    10,    11,   666,   726,   727,  1517,
     122,  1606,    10,    11,    10,    11,    10,    11,  1056,    10,
      11,     6,     7,    10,    11,   146,    10,  1535,   143,  1067,
      10,  1069,   751,    10,    11,    10,    11,   697,    10,    11,
    1078,    10,    11,    10,    11,   705,    10,    11,   767,    10,
      11,    10,    11,    10,    11,   171,   775,    10,  1096,   205,
      10,   207,   208,   209,   724,   211,   212,   213,  1106,   215,
     216,   217,   112,   219,   220,   221,   110,   223,   224,    10,
      11,    10,    11,    19,   186,   804,    22,    10,    11,    10,
      11,    10,    11,   180,   813,    10,    11,    10,    11,    10,
      11,   160,   762,    10,    11,    10,    11,    43,    44,    45,
      46,    47,    48,    10,    11,    51,    52,    53,    54,    92,
     839,   781,    96,    59,    60,    10,    11,    10,    11,    94,
      19,   198,   199,    10,    11,    10,    11,    76,   857,    10,
      11,    90,   861,   146,    33,    10,    11,    10,    11,    10,
      11,   870,    10,    11,    43,    44,    45,    46,    47,    48,
      10,    11,    51,    52,   143,   884,    55,    56,    10,    11,
      59,    60,    10,    11,   893,    10,    11,    10,    11,    10,
      11,    10,    11,   154,   903,    10,    11,    10,    11,    10,
      11,    82,   852,   120,   913,    10,    11,    10,    11,     6,
    1079,    10,    11,     6,   923,   205,  1313,   207,   208,   209,
       6,   211,   212,   213,     6,   215,   216,   217,   937,   219,
     220,   221,   168,   223,   224,    10,    11,    38,    39,   170,
     949,    10,    11,    10,    11,  1342,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,     6,     6,
     146,   143,   172,     3,   144,     3,   975,  1364,    10,    30,
     184,   177,   194,   196,  1143,   190,   192,   146,   144,   143,
       3,     3,  1310,   167,   144,     6,   133,     6,     3,   152,
     144,   165,   137,   201,    28,   178,    25,  1006,   107,   134,
     168,   171,     5,   149,   166,     6,    24,     6,   261,     6,
      78,  1339,   162,    27,   202,   261,    33,     6,   113,   197,
     172,   138,   101,   101,    22,     6,    16,   108,   101,     6,
     150,   147,     6,  1361,    99,   143,   986,   143,   262,  1048,
      99,   199,    99,   143,     6,    18,    85,   102,   135,   102,
     262,  1220,  1061,    85,   198,    85,   199,   102,     5,   105,
      87,    87,   114,   148,     3,     3,     6,    87,     3,    97,
      83,  1080,    83,   200,     6,     3,    78,    83,   144,     6,
     117,    40,   115,   173,   135,   129,   136,   199,   100,   105,
     100,    86,   117,   129,   129,   144,   200,   173,   106,    86,
     100,   144,   173,  1112,    86,    88,  1056,   187,   117,     6,
      10,     6,    88,   187,   118,   187,    88,    84,    98,  1069,
      84,   106,   118,   200,   118,   130,    84,     6,   116,   136,
       6,    77,    25,   174,    97,   411,   425,   130,   130,   517,
     591,   233,   646,   174,   316,   660,  1096,   533,   762,   822,
     174,  1023,   979,  1259,  1262,  1010,  1229,  1232,  1052,  1288,
    1291,  1090,   755,   141,   941,   830,  1096,   986,  1056,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    -1,   188,    -1,   188,    -1,    -1,    -1,    -1,    -1,
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
       0,    12,    13,   350,   351,   352,     0,    65,   359,   360,
    1121,  1122,    14,   353,    15,   357,   358,    67,   361,   362,
      10,    11,  1123,  1124,  1125,    10,    11,   354,   355,   356,
      69,   441,   442,    10,    11,   363,   364,   365,    66,   205,
     207,   208,   209,   211,   212,   213,   215,   216,   217,   219,
     220,   221,   223,   224,  1126,  1127,  1128,  1129,  1130,  1131,
    1132,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,   359,    71,   495,
     496,    10,    11,   443,   444,   445,    68,   121,   127,   131,
     133,   145,   155,   157,   163,   181,   366,   367,   368,   369,
     370,   385,   386,   391,   392,   397,   398,   403,   404,   409,
     410,   415,   416,   421,   422,   427,   428,     5,     5,     5,
       5,     5,    66,  1128,   357,    73,   547,   548,    10,    11,
     497,   498,   499,    70,    89,    91,    93,    95,   145,   175,
     446,   447,   448,   449,   450,   455,   456,   462,   463,   469,
     470,   476,   477,   481,   482,    68,   368,    31,    43,    44,
      47,    48,   371,   372,   373,  1065,  1066,  1067,  1068,  1082,
    1083,  1084,  1085,  1112,    10,    11,   387,   388,   389,    10,
      11,   393,   394,   395,    10,    11,   399,   400,   401,    10,
      11,   405,   406,   407,    10,    11,   411,   412,   413,    10,
      11,   417,   418,   419,    10,    11,   423,   424,   425,    26,
     429,  1107,   206,   210,   214,   218,   222,    75,   642,   643,
      10,    11,   549,   550,   551,    72,   109,   111,   145,   159,
     179,   185,   500,   501,   502,   503,   504,   509,   510,   515,
     516,   521,   522,   527,   528,   533,   534,    70,   448,    10,
      11,   451,   452,   453,   457,   458,   464,   465,   471,   472,
     478,  1065,   483,  1107,  1118,  1119,     3,     3,    10,    11,
     374,   375,   376,   373,     4,   134,   390,     4,   158,   396,
       4,   156,   402,     4,   128,   408,     4,   132,   414,     4,
     164,   420,     4,   182,   426,  1118,    10,    11,   430,   431,
     432,   644,   645,    74,    81,   119,   145,   153,   167,   169,
     183,   189,   191,   193,   195,   552,   553,   554,   555,   556,
     561,   562,   567,   568,   573,   574,   579,   580,   585,   586,
     602,   603,   609,   610,   616,   617,   623,   624,   628,   629,
      72,   502,    10,    11,   505,   506,   507,    10,    11,   511,
     512,   513,    10,    11,   517,   518,   519,    10,    11,   523,
     524,   525,    10,    11,   529,   530,   531,   535,  1107,     4,
     176,   454,    10,   460,    57,    58,   459,  1065,  1086,  1087,
    1088,  1089,    10,   467,   466,  1065,  1086,    10,   474,   473,
    1065,  1086,    10,   479,    10,    11,   484,   485,   486,     6,
       8,   345,   346,   347,   348,  1120,  1118,  1118,   122,   171,
     377,   378,   379,   380,   134,   158,   156,   128,   132,   164,
     182,     6,   143,   146,   433,   434,   435,   436,    10,    11,
     647,   648,   649,    17,    23,    29,    34,   646,  1099,  1104,
    1110,  1115,    74,   554,    10,    11,   557,   558,   559,    10,
      11,   563,   564,   565,    10,    11,   569,   570,   571,    10,
      11,   575,   576,   577,    10,    11,   581,   582,   583,    32,
     587,  1113,   604,   605,   611,   612,   618,   619,   625,  1065,
     630,  1107,     4,   112,   508,     6,   110,   514,     6,   186,
     520,     4,   180,   526,     6,     7,   160,   532,  1116,    10,
      11,   536,   537,   538,   176,   461,  1116,     3,   468,  1116,
     475,  1116,     6,   480,   143,   146,   487,   488,   489,   490,
    1118,   122,   379,   381,   382,  1118,   146,   435,   437,   438,
      76,   161,   650,   651,   652,   653,  1118,  1118,  1118,  1118,
       4,   168,   560,     4,   170,   566,     4,   154,   572,     4,
      82,   578,     4,   120,   584,  1118,    10,    11,   588,   589,
     590,    10,   607,   606,  1065,  1086,    10,   614,   613,  1065,
    1086,    10,   621,   620,  1065,  1086,    10,   626,    10,    11,
     631,   632,   633,   112,   110,   186,   180,   160,   143,   146,
     539,   540,   541,   542,    94,  1118,    96,    92,    90,   146,
     489,   491,   492,    10,    11,   384,    45,    46,   383,  1065,
    1074,  1075,  1076,  1077,    10,    11,   440,    59,    60,   439,
    1065,  1074,  1090,  1091,  1092,  1093,    76,   151,   652,  1034,
    1035,   654,   655,     6,     6,     6,     6,   168,   170,   154,
      82,   120,     6,   177,   184,   591,   592,   593,   594,   608,
    1116,   615,  1116,   622,  1116,     6,   627,   143,   146,   634,
     635,   636,   637,   146,   541,   543,   544,    10,    11,   494,
     493,  1065,  1074,  1090,   172,     3,   144,     3,    30,  1036,
    1111,    10,   660,    36,    61,    63,   656,   657,   658,   659,
    1118,  1118,  1118,  1118,  1118,   184,   593,   595,   194,   196,
     192,   190,   146,   636,   638,   639,    10,    11,   546,   545,
    1065,  1074,  1090,   144,  1118,  1118,  1118,    10,    11,  1037,
    1038,  1039,   167,   661,   662,  1118,     3,     3,    10,    11,
      41,    42,   596,   597,   598,   599,  1057,  1058,  1059,  1060,
    1065,  1082,  1086,    10,    11,   641,   640,  1065,  1074,  1090,
     144,     6,   152,   165,  1040,  1041,  1042,  1043,   133,   677,
     678,   663,   664,   665,  1065,  1082,  1112,     6,  1118,  1118,
       6,     7,   178,   600,   601,     3,   144,  1118,   152,  1042,
    1044,  1045,   201,   683,   684,    10,    11,   679,   680,   681,
      10,    11,   666,   667,   668,   665,  1118,   178,  1118,    10,
      11,  1047,  1048,  1049,    21,  1046,  1057,  1065,  1074,  1102,
     137,   803,   804,    28,   685,  1109,     4,   134,   682,   168,
     171,   669,   670,   671,   672,    77,    79,    80,   166,  1050,
    1051,  1052,  1053,  1054,  1055,  1118,   107,   907,   908,    25,
     805,  1106,  1118,    10,    11,   686,   687,   688,   134,   168,
     671,   673,   674,     5,  1056,   166,  1052,     6,   149,  1011,
    1012,    24,   909,  1105,  1118,    10,    11,   806,   807,   808,
       6,   261,   689,   690,   691,    10,    11,   676,   675,  1065,
    1082,    78,  1118,   162,    27,  1013,  1108,  1118,    10,    11,
     910,   911,   912,     6,   261,   809,   810,   811,  1118,   202,
     197,   703,   704,    33,   692,  1114,   172,  1118,    10,    11,
    1014,  1015,  1016,     6,   113,   913,   914,   915,  1118,   138,
     101,   823,   824,    22,   812,  1103,   101,   719,   720,   705,
    1114,  1118,    10,    11,   693,   694,   695,     6,   147,   150,
    1017,  1018,  1019,  1020,  1118,   108,   101,   927,   928,    16,
     916,  1098,   878,    10,    11,   825,   826,   827,  1118,    10,
      11,   813,   814,   815,   774,    10,    11,   721,   722,   723,
      10,    11,   706,   707,   708,     6,   199,   262,   696,   697,
     698,   699,  1118,   150,  1019,  1021,  1022,   982,    10,    11,
     929,   930,   931,  1118,    10,    11,   917,   918,   919,   143,
     879,   880,    99,   828,   829,   830,     6,   135,   262,   816,
     817,   818,   819,   143,   775,   776,    99,   724,   725,   726,
     198,   199,   709,   710,   711,   712,  1118,   262,   698,   700,
      10,    11,  1024,  1025,  1026,  1023,  1057,  1065,  1074,  1090,
    1102,   143,   983,   984,    99,   932,   933,   934,     6,   105,
     114,   920,   921,   922,   923,   881,   882,   102,    85,   836,
     837,    18,   831,  1100,  1118,   262,   818,   820,   777,   778,
     102,    85,   732,   733,   727,  1100,   198,   711,   713,    10,
      37,   701,   702,  1073,  1074,    77,    79,    80,   148,  1027,
    1028,  1029,  1030,  1031,  1032,   985,   986,   102,    85,   940,
     941,   935,  1100,  1118,   114,   922,   924,    10,    11,   884,
     885,   886,    19,    51,    52,    53,    54,   883,  1065,  1069,
    1070,  1071,  1072,  1074,  1078,  1079,  1080,  1081,  1082,  1090,
    1101,  1103,    87,   843,   844,   838,  1100,  1118,    10,    11,
     832,   833,   834,    10,   821,   822,  1073,  1074,    10,    11,
     780,   781,   782,    55,    56,   779,  1065,  1069,  1074,  1082,
    1090,  1094,  1095,  1096,  1097,  1101,  1114,    87,   739,   740,
     734,  1100,    10,    11,   728,   729,   730,    10,    11,   714,
     715,   716,   717,  1073,  1074,  1116,  1118,     5,  1033,   148,
    1029,    10,    11,   988,   989,   990,    49,    50,   987,  1061,
    1062,  1063,  1064,  1065,  1069,  1074,  1082,  1090,  1098,  1101,
      87,   947,   948,   942,  1100,    10,    11,   936,   937,   938,
      10,   925,   926,  1073,  1074,   117,   135,   144,   887,   888,
     889,   890,   897,   898,   899,  1118,     3,     3,    83,   850,
     851,   845,  1100,    10,    11,   839,   840,   841,     6,    97,
     835,  1149,  1150,  1157,  1116,   117,   144,   199,   783,   784,
     785,   786,   793,   794,   795,     3,    83,   746,   747,   741,
    1100,    10,    11,   735,   736,   737,   731,  1149,     4,   200,
     718,   200,     6,    78,   105,   117,   144,   991,   992,   993,
     994,  1001,  1002,  1003,     3,    83,   954,   955,   949,  1100,
      10,    11,   943,   944,   945,   939,  1149,  1116,   144,   889,
     891,   898,   900,   901,     6,  1118,  1118,   129,   857,   858,
     852,  1100,    10,    11,   846,   847,   848,   842,  1149,  1118,
      40,  1158,   100,   115,  1151,  1152,   136,   144,   785,   787,
     794,   796,   797,  1118,   129,   753,   754,   748,  1100,    10,
      11,   742,   743,   744,   738,  1149,   100,   200,  1118,   144,
     993,   995,  1002,  1004,  1005,  1118,   129,   961,   962,   956,
    1100,    10,    11,   950,   951,   952,   946,  1149,   100,   106,
      10,    11,   892,   893,   894,   895,  1073,  1074,    10,    11,
     903,   904,   905,   902,  1065,  1090,  1100,  1118,   173,   864,
     865,   859,  1100,    10,    11,   853,   854,   855,   849,  1149,
      86,  1118,    10,    11,  1159,  1160,  1161,  1153,  1154,    10,
      11,   788,   789,   790,   791,  1073,  1074,    10,    11,   799,
     800,   801,   798,  1065,  1090,  1100,   173,   760,   761,   755,
    1100,    10,    11,   749,   750,   751,   745,  1149,    86,    10,
      11,   996,   997,   998,   999,  1073,  1074,    10,    11,  1007,
    1008,  1009,  1006,  1065,  1090,  1100,   173,   968,   969,   963,
    1100,    10,    11,   957,   958,   959,   953,  1149,    86,     4,
       6,     7,   136,   896,  1117,   906,  1149,   187,   871,   872,
     866,  1100,    10,    11,   860,   861,   862,   856,  1149,    88,
       6,     4,    98,    10,  1156,    38,    39,  1155,  1162,  1163,
     200,   792,  1117,   802,  1149,   187,   767,   768,   762,  1100,
      10,    11,   756,   757,   758,   752,  1149,    88,   106,  1000,
    1117,  1010,  1149,   187,   975,   976,   970,  1100,    10,    11,
     964,   965,   966,   960,  1149,    88,   136,   118,   873,  1100,
      10,    11,   867,   868,   869,   863,  1149,    84,  1118,    98,
       6,  1118,  1118,   200,   118,   769,  1100,    10,    11,   763,
     764,   765,   759,  1149,    84,   106,   118,   977,  1100,    10,
      11,   971,   972,   973,   967,  1149,    84,    10,    11,   874,
     875,   876,   870,  1149,   130,   116,     6,     6,    10,    11,
     770,   771,   772,   766,  1149,   130,    10,    11,   978,   979,
     980,   974,  1149,   130,   877,  1149,   174,  1118,  1118,   773,
    1149,   174,   981,  1149,   174,   188,   188,   188
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
    osnl_empty_vectors( osnlData);
    throw ErrorClass( errormsg);
} //end osrlerror



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
#if 0
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
#endif
}//end osrl_empty_vectors


