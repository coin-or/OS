
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
     MATRIXDIAGONALSTART = 598,
     MATRIXDIAGONALEND = 599,
     MATRIXDOTTIMESSTART = 600,
     MATRIXDOTTIMESEND = 601,
     MATRIXIDENTITYSTART = 602,
     MATRIXIDENTITYEND = 603,
     MATRIXINVERSESTART = 604,
     MATRIXINVERSEEND = 605,
     MATRIXLOWERTRIANGLESTART = 606,
     MATRIXLOWERTRIANGLEEND = 607,
     MATRIXUPPERTRIANGLESTART = 608,
     MATRIXUPPERTRIANGLEEND = 609,
     MATRIXMERGESTART = 610,
     MATRIXMERGEEND = 611,
     MATRIXMINUSSTART = 612,
     MATRIXMINUSEND = 613,
     MATRIXPLUSSTART = 614,
     MATRIXPLUSEND = 615,
     MATRIXTIMESSTART = 616,
     MATRIXTIMESEND = 617,
     MATRIXSCALARTIMESSTART = 618,
     MATRIXSCALARTIMESEND = 619,
     MATRIXSUBMATRIXATSTART = 620,
     MATRIXSUBMATRIXATEND = 621,
     MATRIXTRANSPOSESTART = 622,
     MATRIXTRANSPOSEEND = 623,
     EMPTYINCLUDEDIAGONALATT = 624,
     INCLUDEDIAGONALATT = 625,
     IDATT = 626,
     COEFATT = 627
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
#define MATRIXDIAGONALSTART 598
#define MATRIXDIAGONALEND 599
#define MATRIXDOTTIMESSTART 600
#define MATRIXDOTTIMESEND 601
#define MATRIXIDENTITYSTART 602
#define MATRIXIDENTITYEND 603
#define MATRIXINVERSESTART 604
#define MATRIXINVERSEEND 605
#define MATRIXLOWERTRIANGLESTART 606
#define MATRIXLOWERTRIANGLEEND 607
#define MATRIXUPPERTRIANGLESTART 608
#define MATRIXUPPERTRIANGLEEND 609
#define MATRIXMERGESTART 610
#define MATRIXMERGEEND 611
#define MATRIXMINUSSTART 612
#define MATRIXMINUSEND 613
#define MATRIXPLUSSTART 614
#define MATRIXPLUSEND 615
#define MATRIXTIMESSTART 616
#define MATRIXTIMESEND 617
#define MATRIXSCALARTIMESSTART 618
#define MATRIXSCALARTIMESEND 619
#define MATRIXSUBMATRIXATSTART 620
#define MATRIXSUBMATRIXATEND 621
#define MATRIXTRANSPOSESTART 622
#define MATRIXTRANSPOSEEND 623
#define EMPTYINCLUDEDIAGONALATT 624
#define INCLUDEDIAGONALATT 625
#define IDATT 626
#define COEFATT 627




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
#define YYLAST   1217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  377
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  815
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1199
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1626

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   627

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   374,
     376,     2,     2,   375,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   373,     2,     2,     2,     2,     2,     2,     2,
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372
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
    2787,  2791,  2793,  2794,  2797,  2799,  2801,  2803,  2805,  2807,
    2809,  2811,  2813,  2815,  2817,  2821,  2823,  2825,  2827,  2829,
    2831,  2835,  2837,  2839,  2841,  2843,  2845,  2849,  2851,  2853,
    2855,  2857,  2859,  2863,  2865,  2867,  2869,  2871,  2873,  2877,
    2879,  2881,  2882,  2885,  2889,  2891,  2893,  2894,  2897,  2899,
    2901,  2905,  2909,  2911,  2913,  2916,  2918,  2922,  2927,  2932
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     378,     0,    -1,   379,   387,   385,    -1,   380,   381,   382,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   383,    -1,
     384,    -1,    11,    -1,    10,   387,   385,    -1,   386,    -1,
      15,    -1,    -1,   388,   389,   469,   523,   575,   670,    -1,
      -1,  1149,    -1,    -1,   390,   391,    -1,    67,    -1,   392,
      -1,   393,    -1,    10,    68,    -1,    11,    -1,    10,   394,
      68,    -1,   395,    -1,   396,    -1,   395,   396,    -1,   397,
      -1,   413,    -1,   419,    -1,   425,    -1,   431,    -1,   437,
      -1,   443,    -1,   449,    -1,   455,    -1,   398,   399,   402,
      -1,   121,    -1,   400,    -1,   401,    -1,   400,   401,    -1,
    1110,    -1,  1093,    -1,  1140,    -1,   403,    -1,   404,    -1,
      10,   122,    -1,    11,    -1,    10,   405,   122,    -1,   406,
      -1,   407,    -1,   406,   407,    -1,   408,   409,   412,    -1,
     171,    -1,   410,    -1,    -1,   410,   411,    -1,  1102,    -1,
    1093,    -1,    10,   172,    -1,    11,    -1,   414,   415,    -1,
     133,    -1,   416,    -1,   417,    -1,    10,   134,    -1,    11,
      -1,    10,   418,   134,    -1,     4,    -1,   420,   421,    -1,
     157,    -1,   422,    -1,   423,    -1,    10,   158,    -1,    11,
      -1,    10,   424,   158,    -1,     4,    -1,   426,   427,    -1,
     155,    -1,   428,    -1,   429,    -1,    10,   156,    -1,    11,
      -1,    10,   430,   156,    -1,     4,    -1,   432,   433,    -1,
     127,    -1,   434,    -1,   435,    -1,    10,   128,    -1,    11,
      -1,    10,   436,   128,    -1,     4,    -1,   438,   439,    -1,
     131,    -1,   440,    -1,   441,    -1,    10,   132,    -1,    11,
      -1,    10,   442,   132,    -1,     4,    -1,   444,   445,    -1,
     163,    -1,   446,    -1,   447,    -1,    10,   164,    -1,    11,
      -1,    10,   448,   164,    -1,     4,    -1,   450,   451,    -1,
     181,    -1,   452,    -1,   453,    -1,    10,   182,    -1,    11,
      -1,    10,   454,   182,    -1,     4,    -1,   456,   457,   458,
      -1,   145,    -1,  1135,    -1,   459,    -1,   460,    -1,    10,
     146,    -1,    11,    -1,    10,   461,   146,    -1,   462,    -1,
     463,    -1,   462,   463,    -1,   464,   465,   468,    -1,   143,
      -1,   466,    -1,    -1,   466,   467,    -1,  1102,    -1,  1118,
      -1,  1093,    -1,    10,   144,    -1,    11,    -1,    -1,   470,
     471,    -1,    69,    -1,   472,    -1,   473,    -1,    10,    70,
      -1,    11,    -1,    10,   474,    70,    -1,   475,    -1,   476,
      -1,   475,   476,    -1,   477,    -1,   483,    -1,   490,    -1,
     497,    -1,   504,    -1,   509,    -1,   478,   479,    -1,   175,
      -1,   480,    -1,   481,    -1,    10,   176,    -1,    11,    -1,
      10,   482,   176,    -1,     4,    -1,   484,   485,   488,    -1,
      93,    -1,   486,    -1,    -1,   486,   487,    -1,  1114,    -1,
    1093,    -1,    10,   489,    94,    -1,  1144,    -1,   491,   492,
     495,    -1,    95,    -1,   493,    -1,    -1,   493,   494,    -1,
    1114,    -1,  1093,    -1,    10,   496,    96,    -1,  1144,    -1,
     498,   499,   502,    -1,    91,    -1,   500,    -1,    -1,   500,
     501,    -1,  1114,    -1,  1093,    -1,    10,   503,    92,    -1,
    1144,    -1,   505,   506,   507,    -1,    89,    -1,    -1,  1093,
      -1,    10,   508,    90,    -1,     6,    -1,   510,   511,   512,
      -1,   145,    -1,  1135,    -1,   513,    -1,   514,    -1,    10,
     146,    -1,    11,    -1,    10,   515,   146,    -1,   516,    -1,
     517,    -1,   516,   517,    -1,   518,   519,   522,    -1,   143,
      -1,   520,    -1,    -1,   520,   521,    -1,  1102,    -1,  1118,
      -1,  1093,    -1,    10,   144,    -1,    11,    -1,    -1,   524,
     525,    -1,    71,    -1,   526,    -1,   527,    -1,    10,    72,
      -1,    11,    -1,    10,   528,    72,    -1,   529,    -1,   530,
      -1,   529,   530,    -1,   531,    -1,   537,    -1,   543,    -1,
     549,    -1,   555,    -1,   561,    -1,   532,   533,    -1,   111,
      -1,   534,    -1,   535,    -1,    10,   112,    -1,    11,    -1,
      10,   536,   112,    -1,     4,    -1,   538,   539,    -1,   109,
      -1,   540,    -1,   541,    -1,    10,   110,    -1,    11,    -1,
      10,   542,   110,    -1,     6,    -1,   544,   545,    -1,   185,
      -1,   546,    -1,   547,    -1,    10,   186,    -1,    11,    -1,
      10,   548,   186,    -1,     6,    -1,   550,   551,    -1,   179,
      -1,   552,    -1,   553,    -1,    10,   180,    -1,    11,    -1,
      10,   554,   180,    -1,     4,    -1,   556,   557,    -1,   159,
      -1,   558,    -1,   559,    -1,    10,   160,    -1,    11,    -1,
      10,   560,   160,    -1,  1144,    -1,   562,   563,   564,    -1,
     145,    -1,  1135,    -1,   565,    -1,   566,    -1,    10,   146,
      -1,    11,    -1,    10,   567,   146,    -1,   568,    -1,   569,
      -1,   568,   569,    -1,   570,   571,   574,    -1,   143,    -1,
     572,    -1,    -1,   572,   573,    -1,  1102,    -1,  1118,    -1,
    1093,    -1,    10,   144,    -1,    11,    -1,    -1,   576,   577,
      -1,    73,    -1,   578,    -1,   579,    -1,    10,    74,    -1,
      11,    -1,    10,   580,    74,    -1,   581,    -1,   582,    -1,
     581,   582,    -1,   583,    -1,   589,    -1,   595,    -1,   601,
      -1,   607,    -1,   613,    -1,   630,    -1,   637,    -1,   644,
      -1,   651,    -1,   656,    -1,   584,   585,    -1,   167,    -1,
     586,    -1,   587,    -1,    10,   168,    -1,    11,    -1,    10,
     588,   168,    -1,     4,    -1,   590,   591,    -1,   169,    -1,
     592,    -1,   593,    -1,    10,   170,    -1,    11,    -1,    10,
     594,   170,    -1,     4,    -1,   596,   597,    -1,   153,    -1,
     598,    -1,   599,    -1,    10,   154,    -1,    11,    -1,    10,
     600,   154,    -1,     4,    -1,   602,   603,    -1,    81,    -1,
     604,    -1,   605,    -1,    10,    82,    -1,    11,    -1,    10,
     606,    82,    -1,     4,    -1,   608,   609,    -1,   119,    -1,
     610,    -1,   611,    -1,    10,   120,    -1,    11,    -1,    10,
     612,   120,    -1,     4,    -1,   614,   615,   616,    -1,   183,
      -1,  1141,    -1,   617,    -1,   618,    -1,    10,   184,    -1,
      11,    -1,    10,   619,   184,    -1,   620,    -1,   621,    -1,
     620,   621,    -1,   622,   623,   625,    -1,   177,    -1,    -1,
     623,   624,    -1,  1114,    -1,  1110,    -1,  1085,    -1,  1093,
      -1,   626,    -1,   627,    -1,    10,   178,    -1,    11,    -1,
      10,   628,   178,    -1,   629,    -1,     7,    -1,     6,    -1,
     631,   632,   635,    -1,   193,    -1,   633,    -1,    -1,   633,
     634,    -1,  1114,    -1,  1093,    -1,    10,   636,   194,    -1,
    1144,    -1,   638,   639,   642,    -1,   195,    -1,   640,    -1,
      -1,   640,   641,    -1,  1114,    -1,  1093,    -1,    10,   643,
     196,    -1,  1144,    -1,   645,   646,   649,    -1,   191,    -1,
     647,    -1,    -1,   647,   648,    -1,  1114,    -1,  1093,    -1,
      10,   650,   192,    -1,  1144,    -1,   652,   653,   654,    -1,
     189,    -1,    -1,  1093,    -1,    10,   655,   190,    -1,     6,
      -1,   657,   658,   659,    -1,   145,    -1,  1135,    -1,   660,
      -1,   661,    -1,    10,   146,    -1,    11,    -1,    10,   662,
     146,    -1,   663,    -1,   664,    -1,   663,   664,    -1,   665,
     666,   669,    -1,   143,    -1,   667,    -1,    -1,   667,   668,
      -1,  1102,    -1,  1118,    -1,  1093,    -1,    10,   144,    -1,
      11,    -1,    -1,   671,   672,   675,    -1,    75,    -1,   673,
      -1,    -1,   673,   674,    -1,  1138,    -1,  1143,    -1,  1127,
      -1,  1132,    -1,   676,    -1,   677,    -1,    10,    76,    -1,
      11,    -1,    10,   678,    76,    -1,   679,  1062,    -1,   680,
      -1,   679,   680,    -1,   681,   682,   688,    -1,   161,    -1,
     683,    -1,    -1,   683,   684,    -1,   685,    -1,   686,    -1,
     687,    -1,    36,  1146,     6,  1146,    -1,    63,     3,  1146,
      -1,    61,     3,  1146,    -1,    10,   689,   705,   711,   831,
     935,  1039,   162,    -1,   690,   691,   694,    -1,   167,    -1,
     692,    -1,   693,    -1,   692,   693,    -1,  1110,    -1,  1093,
      -1,  1140,    -1,   695,    -1,   696,    -1,    10,   168,    -1,
      11,    -1,    10,   697,   168,    -1,   698,    -1,   699,    -1,
     698,   699,    -1,   700,   701,   704,    -1,   171,    -1,   702,
      -1,    -1,   702,   703,    -1,  1110,    -1,  1093,    -1,    10,
     172,    -1,    11,    -1,    -1,   706,   707,    -1,   133,    -1,
     708,    -1,   709,    -1,    10,   134,    -1,    11,    -1,    10,
     710,   134,    -1,     4,    -1,    -1,   712,   713,   714,    -1,
     201,    -1,    -1,  1137,    -1,   715,    -1,   716,    -1,    11,
      -1,    10,   717,   202,    -1,   718,   731,   747,   802,    -1,
      -1,   719,   720,   721,    -1,   261,    -1,  1142,    -1,   722,
      -1,   723,    -1,    10,   262,    -1,    11,    -1,    10,   724,
     262,    -1,   725,    -1,   726,    -1,   725,   726,    -1,   727,
     728,   730,    -1,   199,    -1,    -1,   728,   729,    -1,  1101,
      -1,  1102,    -1,    10,  1144,   200,    -1,    -1,   732,   733,
     734,    -1,   197,    -1,  1142,    -1,   735,    -1,   736,    -1,
      10,   198,    -1,    11,    -1,    10,   737,   198,    -1,   738,
      -1,   739,    -1,   738,   739,    -1,   740,   741,   743,    -1,
     199,    -1,    -1,   741,   742,    -1,  1101,    -1,  1102,    -1,
     744,    -1,   745,    -1,    10,   200,    -1,    11,    -1,    10,
     746,   200,    -1,     4,    -1,    -1,   748,   749,    -1,   101,
      -1,   750,    -1,   751,    -1,    11,    -1,    10,   752,   102,
      -1,   753,   760,   767,   774,   781,   788,   795,    -1,    -1,
     754,   755,   756,    -1,    99,    -1,  1128,    -1,   757,    -1,
     758,    -1,    11,    -1,    10,   759,   100,    -1,  1177,    -1,
      -1,   761,   762,   763,    -1,    85,    -1,  1128,    -1,   764,
      -1,   765,    -1,    11,    -1,    10,   766,    86,    -1,  1177,
      -1,    -1,   768,   769,   770,    -1,    87,    -1,  1128,    -1,
     771,    -1,   772,    -1,    11,    -1,    10,   773,    88,    -1,
    1177,    -1,    -1,   775,   776,   777,    -1,    83,    -1,  1128,
      -1,   778,    -1,   779,    -1,    11,    -1,    10,   780,    84,
      -1,  1177,    -1,    -1,   782,   783,   784,    -1,   129,    -1,
    1128,    -1,   785,    -1,   786,    -1,    11,    -1,    10,   787,
     130,    -1,  1177,    -1,    -1,   789,   790,   791,    -1,   173,
      -1,  1128,    -1,   792,    -1,   793,    -1,    11,    -1,    10,
     794,   174,    -1,  1177,    -1,    -1,   796,   797,   798,    -1,
     187,    -1,  1128,    -1,   799,    -1,   800,    -1,    11,    -1,
      10,   801,   188,    -1,  1177,    -1,    -1,   802,   803,    -1,
     804,   805,   808,    -1,   143,    -1,   806,    -1,    -1,   806,
     807,    -1,  1142,    -1,  1129,    -1,  1118,    -1,  1102,    -1,
    1110,    -1,  1122,    -1,  1097,    -1,  1093,    -1,   809,    -1,
     810,    -1,    10,   144,    -1,    11,    -1,    10,   811,   144,
      -1,   812,    -1,   821,    -1,   813,    -1,   812,   813,    -1,
     814,   815,   817,    -1,   199,    -1,    -1,   815,   816,    -1,
    1101,    -1,  1102,    -1,   818,    -1,   819,    -1,    10,   200,
      -1,    11,    -1,    10,   820,   200,    -1,  1145,    -1,   822,
      -1,   821,   822,    -1,   823,   824,   827,    -1,   117,    -1,
     825,    -1,    -1,   825,   826,    -1,  1128,    -1,  1118,    -1,
    1093,    -1,   828,    -1,   829,    -1,    11,    -1,    10,   830,
     118,    -1,  1177,    -1,    -1,   832,   833,   834,    -1,   137,
      -1,    -1,  1134,    -1,   835,    -1,   836,    -1,    11,    -1,
      10,   837,   138,    -1,   838,   851,   906,    -1,    -1,   839,
     840,   841,    -1,   261,    -1,  1131,    -1,   842,    -1,   843,
      -1,    10,   262,    -1,    11,    -1,    10,   844,   262,    -1,
     845,    -1,   846,    -1,   845,   846,    -1,   847,   848,   850,
      -1,   135,    -1,    -1,   848,   849,    -1,  1101,    -1,  1102,
      -1,    10,  1144,   136,    -1,    -1,   852,   853,    -1,   101,
      -1,   854,    -1,   855,    -1,    11,    -1,    10,   856,   102,
      -1,   857,   864,   871,   878,   885,   892,   899,    -1,    -1,
     858,   859,   860,    -1,    99,    -1,  1128,    -1,   861,    -1,
     862,    -1,    11,    -1,    10,   863,   100,    -1,  1177,    -1,
      -1,   865,   866,   867,    -1,    85,    -1,  1128,    -1,   868,
      -1,   869,    -1,    11,    -1,    10,   870,    86,    -1,  1177,
      -1,    -1,   872,   873,   874,    -1,    87,    -1,  1128,    -1,
     875,    -1,   876,    -1,    11,    -1,    10,   877,    88,    -1,
    1177,    -1,    -1,   879,   880,   881,    -1,    83,    -1,  1128,
      -1,   882,    -1,   883,    -1,    11,    -1,    10,   884,    84,
      -1,  1177,    -1,    -1,   886,   887,   888,    -1,   129,    -1,
    1128,    -1,   889,    -1,   890,    -1,    11,    -1,    10,   891,
     130,    -1,  1177,    -1,    -1,   893,   894,   895,    -1,   173,
      -1,  1128,    -1,   896,    -1,   897,    -1,    11,    -1,    10,
     898,   174,    -1,  1177,    -1,    -1,   900,   901,   902,    -1,
     187,    -1,  1128,    -1,   903,    -1,   904,    -1,    11,    -1,
      10,   905,   188,    -1,  1177,    -1,    -1,   906,   907,    -1,
     908,   909,   912,    -1,   143,    -1,   910,    -1,    -1,   910,
     911,    -1,  1131,    -1,  1129,    -1,  1118,    -1,  1102,    -1,
    1110,    -1,  1106,    -1,  1097,    -1,  1093,    -1,   913,    -1,
     914,    -1,    10,   144,    -1,    11,    -1,    10,   915,   144,
      -1,   916,    -1,   925,    -1,   917,    -1,   916,   917,    -1,
     918,   919,   921,    -1,   135,    -1,    -1,   919,   920,    -1,
    1101,    -1,  1102,    -1,   922,    -1,   923,    -1,    10,   136,
      -1,    11,    -1,    10,   924,   136,    -1,  1145,    -1,   926,
      -1,   925,   926,    -1,   927,   928,   931,    -1,   117,    -1,
     929,    -1,    -1,   929,   930,    -1,  1128,    -1,  1118,    -1,
    1093,    -1,   932,    -1,   933,    -1,    11,    -1,    10,   934,
     118,    -1,  1177,    -1,    -1,   936,   937,   938,    -1,   107,
      -1,    -1,  1133,    -1,   939,    -1,   940,    -1,    11,    -1,
      10,   941,   108,    -1,   942,   955,  1010,    -1,    -1,   943,
     944,   945,    -1,   113,    -1,  1126,    -1,   946,    -1,   947,
      -1,    10,   114,    -1,    11,    -1,    10,   948,   114,    -1,
     949,    -1,   950,    -1,   949,   950,    -1,   951,   952,   954,
      -1,   105,    -1,    -1,   952,   953,    -1,  1101,    -1,  1102,
      -1,    10,  1144,   106,    -1,    -1,   956,   957,    -1,   101,
      -1,   958,    -1,   959,    -1,    11,    -1,    10,   960,   102,
      -1,   961,   968,   975,   982,   989,   996,  1003,    -1,    -1,
     962,   963,   964,    -1,    99,    -1,  1128,    -1,   965,    -1,
     966,    -1,    11,    -1,    10,   967,   100,    -1,  1177,    -1,
      -1,   969,   970,   971,    -1,    85,    -1,  1128,    -1,   972,
      -1,   973,    -1,    11,    -1,    10,   974,    86,    -1,  1177,
      -1,    -1,   976,   977,   978,    -1,    87,    -1,  1128,    -1,
     979,    -1,   980,    -1,    11,    -1,    10,   981,    88,    -1,
    1177,    -1,    -1,   983,   984,   985,    -1,    83,    -1,  1128,
      -1,   986,    -1,   987,    -1,    11,    -1,    10,   988,    84,
      -1,  1177,    -1,    -1,   990,   991,   992,    -1,   129,    -1,
    1128,    -1,   993,    -1,   994,    -1,    11,    -1,    10,   995,
     130,    -1,  1177,    -1,    -1,   997,   998,   999,    -1,   173,
      -1,  1128,    -1,  1000,    -1,  1001,    -1,    11,    -1,    10,
    1002,   174,    -1,  1177,    -1,    -1,  1004,  1005,  1006,    -1,
     187,    -1,  1128,    -1,  1007,    -1,  1008,    -1,    11,    -1,
      10,  1009,   188,    -1,  1177,    -1,    -1,  1010,  1011,    -1,
    1012,  1013,  1016,    -1,   143,    -1,  1014,    -1,    -1,  1014,
    1015,    -1,  1126,    -1,  1129,    -1,  1118,    -1,  1102,    -1,
    1110,    -1,  1089,    -1,  1097,    -1,  1093,    -1,  1017,    -1,
    1018,    -1,    10,   144,    -1,    11,    -1,    10,  1019,   144,
      -1,  1020,    -1,  1029,    -1,  1021,    -1,  1020,  1021,    -1,
    1022,  1023,  1025,    -1,   105,    -1,    -1,  1023,  1024,    -1,
    1101,    -1,  1102,    -1,  1026,    -1,  1027,    -1,    10,   106,
      -1,    11,    -1,    10,  1028,   106,    -1,  1145,    -1,  1030,
      -1,  1029,  1030,    -1,  1031,  1032,  1035,    -1,   117,    -1,
    1033,    -1,    -1,  1033,  1034,    -1,  1128,    -1,  1118,    -1,
    1093,    -1,  1036,    -1,  1037,    -1,    11,    -1,    10,  1038,
     118,    -1,  1177,    -1,    -1,  1040,  1041,  1042,    -1,   149,
      -1,  1136,    -1,  1043,    -1,  1044,    -1,    10,   150,    -1,
      11,    -1,    10,  1045,   150,    -1,  1046,    -1,  1047,    -1,
    1046,  1047,    -1,  1048,  1049,  1052,    -1,   147,    -1,  1050,
      -1,    -1,  1050,  1051,    -1,  1102,    -1,  1118,    -1,  1085,
      -1,  1093,    -1,  1130,    -1,  1053,    -1,  1054,    -1,    10,
     148,    -1,    11,    -1,    10,  1055,   148,    -1,  1056,    -1,
    1057,    -1,  1056,  1057,    -1,  1058,    -1,  1059,    -1,  1060,
      -1,    79,    -1,    80,    -1,    77,  1061,    78,    -1,     5,
      -1,    -1,  1063,  1064,  1065,    -1,   151,    -1,  1139,    -1,
    1066,    -1,  1067,    -1,    10,   152,    -1,    11,    -1,    10,
    1068,   152,    -1,  1069,    -1,  1070,    -1,  1069,  1070,    -1,
    1071,  1072,  1075,    -1,   165,    -1,  1073,    -1,    -1,  1073,
    1074,    -1,  1102,    -1,  1085,    -1,  1093,    -1,  1130,    -1,
    1076,    -1,  1077,    -1,    10,   166,    -1,    11,    -1,    10,
    1078,   166,    -1,  1079,    -1,  1080,    -1,  1079,  1080,    -1,
    1081,    -1,  1082,    -1,  1083,    -1,    79,    -1,    80,    -1,
      77,  1084,    78,    -1,     5,    -1,  1086,    -1,  1087,    -1,
    1088,    -1,    42,    -1,    41,     3,  1146,    -1,  1090,    -1,
    1091,    -1,  1092,    -1,    50,    -1,    49,     3,  1146,    -1,
    1094,    -1,  1095,    -1,  1096,    -1,    44,    -1,    43,     3,
    1146,    -1,  1098,    -1,  1099,    -1,  1100,    -1,    52,    -1,
      51,     3,  1146,    -1,    37,  1146,     6,  1146,    -1,  1103,
      -1,  1104,    -1,  1105,    -1,    46,    -1,    45,     3,  1146,
      -1,  1107,    -1,  1108,    -1,  1109,    -1,    54,    -1,    53,
       3,  1146,    -1,  1111,    -1,  1112,    -1,  1113,    -1,    48,
      -1,    47,     3,  1146,    -1,  1115,    -1,  1116,    -1,  1117,
      -1,    58,    -1,    57,     3,  1146,    -1,  1119,    -1,  1120,
      -1,  1121,    -1,    60,    -1,    59,     3,  1146,    -1,  1123,
      -1,  1124,    -1,  1125,    -1,    56,    -1,    55,     3,  1146,
      -1,    16,  1146,     6,  1146,    -1,    17,  1146,     6,  1146,
      -1,    18,  1146,     6,  1146,    -1,    19,  1146,     6,  1146,
      -1,    21,  1146,     6,  1146,    -1,    22,  1146,     6,  1146,
      -1,    23,  1146,     6,  1146,    -1,    24,  1146,     6,  1146,
      -1,    25,  1146,     6,  1146,    -1,    26,  1146,     6,  1146,
      -1,    27,  1146,     6,  1146,    -1,    28,  1146,     6,  1146,
      -1,    29,  1146,     6,  1146,    -1,    30,  1146,     6,  1146,
      -1,    31,  1146,     6,  1146,    -1,    32,  1146,     6,  1146,
      -1,    33,  1146,     6,  1146,    -1,    34,  1146,     6,  1146,
      -1,     6,    -1,     7,    -1,     4,    -1,     6,    -1,     7,
      -1,  1147,     8,    -1,    -1,  1147,  1148,    -1,   373,    -1,
     374,    -1,   375,    -1,   376,    -1,  1150,  1151,    -1,    65,
      -1,  1152,    -1,  1153,    -1,    11,    -1,    10,  1154,    66,
      -1,  1155,    -1,    -1,  1155,  1156,    -1,  1157,    -1,  1161,
      -1,  1165,    -1,  1169,    -1,  1173,    -1,  1158,    -1,  1159,
      -1,  1160,    -1,   208,    -1,   207,    -1,   205,     5,   206,
      -1,  1162,    -1,  1163,    -1,  1164,    -1,   212,    -1,   211,
      -1,   209,     5,   210,    -1,  1166,    -1,  1167,    -1,  1168,
      -1,   216,    -1,   215,    -1,   213,     5,   214,    -1,  1170,
      -1,  1171,    -1,  1172,    -1,   220,    -1,   219,    -1,   217,
       5,   218,    -1,  1174,    -1,  1175,    -1,  1176,    -1,   224,
      -1,   223,    -1,   221,     5,   222,    -1,  1178,    -1,  1185,
      -1,    -1,  1178,  1179,    -1,  1180,  1181,  1184,    -1,   115,
      -1,  1182,    -1,    -1,  1182,  1183,    -1,  1191,    -1,  1190,
      -1,    10,     6,   116,    -1,    97,  1189,  1186,    -1,  1187,
      -1,  1188,    -1,    10,    98,    -1,    11,    -1,    10,     4,
      98,    -1,    40,     8,     6,     8,    -1,    38,     8,     6,
       8,    -1,    39,     8,     6,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   324,   324,   325,   327,   334,   344,   344,   346,   346,
     348,   350,   352,   361,   362,   365,   374,   374,   387,   387,
     389,   403,   403,   405,   405,   407,   409,   411,   411,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   425,   427,
     442,   449,   449,   452,   457,   461,   470,   474,   479,   479,
     481,   483,   485,   485,   487,   492,   502,   508,   508,   511,
     516,   522,   522,   525,   527,   534,   534,   536,   536,   538,
     540,   543,   545,   552,   552,   554,   554,   556,   558,   563,
     565,   572,   572,   574,   574,   576,   578,   583,   585,   592,
     592,   594,   594,   596,   598,   603,   605,   612,   612,   614,
     614,   616,   618,   623,   625,   632,   632,   634,   634,   636,
     638,   643,   645,   652,   652,   654,   654,   656,   658,   663,
     665,   672,   682,   687,   693,   693,   695,   697,   699,   699,
     701,   706,   718,   724,   724,   727,   734,   739,   746,   746,
     750,   750,   752,   763,   763,   765,   765,   767,   769,   771,
     771,   774,   775,   776,   777,   778,   779,   782,   784,   791,
     791,   793,   793,   795,   797,   804,   806,   817,   819,   819,
     822,   828,   834,   836,   842,   844,   855,   857,   857,   860,
     866,   872,   874,   881,   883,   894,   896,   896,   899,   905,
     911,   913,   920,   922,   931,   932,   938,   940,   946,   948,
     955,   965,   970,   976,   976,   978,   980,   982,   982,   984,
     989,  1001,  1007,  1007,  1010,  1017,  1022,  1028,  1028,  1032,
    1032,  1034,  1045,  1045,  1047,  1047,  1049,  1051,  1053,  1053,
    1056,  1057,  1058,  1059,  1060,  1061,  1064,  1066,  1073,  1073,
    1075,  1075,  1077,  1079,  1087,  1089,  1096,  1096,  1098,  1098,
    1100,  1102,  1107,  1109,  1116,  1116,  1118,  1118,  1120,  1122,
    1127,  1129,  1136,  1136,  1138,  1138,  1140,  1142,  1147,  1149,
    1156,  1156,  1158,  1158,  1160,  1162,  1169,  1171,  1178,  1188,
    1193,  1199,  1199,  1201,  1203,  1205,  1205,  1207,  1212,  1224,
    1230,  1230,  1233,  1240,  1245,  1252,  1252,  1255,  1255,  1257,
    1273,  1273,  1275,  1275,  1277,  1279,  1281,  1281,  1284,  1285,
    1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1297,
    1299,  1306,  1306,  1308,  1308,  1310,  1312,  1320,  1322,  1329,
    1329,  1331,  1331,  1333,  1335,  1340,  1342,  1349,  1349,  1351,
    1351,  1353,  1355,  1360,  1362,  1369,  1369,  1371,  1371,  1373,
    1375,  1380,  1382,  1389,  1389,  1391,  1391,  1393,  1395,  1400,
    1402,  1409,  1419,  1424,  1430,  1430,  1432,  1434,  1436,  1436,
    1438,  1440,  1454,  1454,  1457,  1457,  1457,  1457,  1460,  1460,
    1462,  1462,  1464,  1466,  1475,  1476,  1479,  1481,  1492,  1494,
    1494,  1497,  1503,  1509,  1511,  1518,  1520,  1531,  1533,  1533,
    1536,  1542,  1548,  1550,  1557,  1559,  1570,  1572,  1572,  1575,
    1581,  1587,  1589,  1596,  1598,  1608,  1609,  1615,  1617,  1624,
    1626,  1633,  1643,  1648,  1654,  1654,  1656,  1658,  1660,  1660,
    1662,  1667,  1679,  1685,  1685,  1688,  1695,  1700,  1707,  1707,
    1710,  1710,  1712,  1720,  1726,  1726,  1729,  1736,  1742,  1748,
    1756,  1761,  1767,  1767,  1769,  1771,  1773,  1773,  1775,  1777,
    1786,  1788,  1788,  1790,  1790,  1790,  1792,  1802,  1812,  1832,
    1838,  1840,  1850,  1856,  1856,  1859,  1864,  1869,  1879,  1884,
    1890,  1890,  1892,  1894,  1896,  1896,  1898,  1903,  1913,  1919,
    1919,  1922,  1928,  1935,  1935,  1938,  1938,  1940,  1942,  1942,
    1944,  1944,  1946,  1948,  1956,  1956,  1958,  1964,  1964,  1972,
    1972,  1974,  1976,  1978,  1980,  1980,  1982,  1984,  1992,  1997,
    2003,  2003,  2005,  2007,  2009,  2009,  2011,  2022,  2031,  2031,
    2034,  2035,  2038,  2041,  2041,  2043,  2045,  2053,  2058,  2064,
    2064,  2066,  2068,  2070,  2070,  2072,  2083,  2092,  2092,  2095,
    2096,  2100,  2101,  2103,  2103,  2105,  2107,  2112,  2112,  2114,
    2119,  2119,  2121,  2123,  2125,  2127,  2127,  2136,  2138,  2145,
    2145,  2147,  2149,  2151,  2154,  2154,  2164,  2166,  2174,  2174,
    2176,  2178,  2180,  2183,  2183,  2192,  2194,  2202,  2202,  2204,
    2206,  2208,  2211,  2211,  2220,  2222,  2230,  2230,  2232,  2234,
    2236,  2239,  2239,  2248,  2250,  2258,  2258,  2260,  2262,  2264,
    2267,  2267,  2276,  2278,  2286,  2286,  2288,  2290,  2292,  2295,
    2295,  2304,  2306,  2314,  2314,  2316,  2318,  2320,  2323,  2323,
    2325,  2330,  2349,  2355,  2355,  2358,  2369,  2380,  2386,  2392,
    2398,  2404,  2410,  2417,  2417,  2419,  2419,  2421,  2423,  2423,
    2425,  2425,  2427,  2434,  2443,  2443,  2446,  2452,  2459,  2459,
    2461,  2461,  2463,  2465,  2474,  2474,  2476,  2487,  2495,  2501,
    2501,  2504,  2510,  2511,  2515,  2515,  2517,  2519,  2522,  2526,
    2526,  2528,  2536,  2536,  2544,  2544,  2546,  2548,  2550,  2552,
    2552,  2554,  2556,  2564,  2569,  2575,  2575,  2577,  2579,  2582,
    2582,  2584,  2593,  2603,  2603,  2606,  2607,  2610,  2613,  2613,
    2615,  2620,  2620,  2623,  2625,  2627,  2629,  2629,  2638,  2640,
    2647,  2647,  2649,  2651,  2653,  2655,  2655,  2664,  2666,  2674,
    2674,  2676,  2678,  2680,  2683,  2683,  2692,  2694,  2702,  2702,
    2704,  2706,  2708,  2711,  2711,  2720,  2722,  2730,  2730,  2732,
    2734,  2736,  2739,  2739,  2748,  2750,  2758,  2758,  2760,  2762,
    2764,  2767,  2767,  2776,  2778,  2786,  2786,  2788,  2790,  2792,
    2795,  2795,  2804,  2806,  2814,  2814,  2816,  2818,  2820,  2823,
    2823,  2825,  2831,  2850,  2857,  2857,  2860,  2871,  2882,  2888,
    2894,  2900,  2906,  2912,  2921,  2921,  2923,  2923,  2925,  2927,
    2927,  2929,  2929,  2931,  2936,  2947,  2947,  2950,  2955,  2962,
    2962,  2964,  2964,  2966,  2968,  2975,  2975,  2977,  2988,  2996,
    3002,  3002,  3005,  3011,  3012,  3016,  3016,  3018,  3020,  3023,
    3026,  3026,  3028,  3035,  3035,  3043,  3043,  3045,  3047,  3049,
    3051,  3051,  3053,  3056,  3064,  3069,  3075,  3075,  3077,  3079,
    3081,  3081,  3083,  3092,  3101,  3101,  3104,  3105,  3108,  3111,
    3111,  3113,  3118,  3118,  3120,  3122,  3124,  3126,  3126,  3135,
    3137,  3144,  3144,  3146,  3148,  3150,  3152,  3152,  3161,  3163,
    3171,  3171,  3173,  3175,  3177,  3180,  3180,  3189,  3191,  3199,
    3199,  3201,  3203,  3205,  3208,  3208,  3217,  3219,  3227,  3227,
    3229,  3231,  3233,  3236,  3236,  3245,  3247,  3255,  3255,  3257,
    3259,  3261,  3264,  3264,  3273,  3275,  3283,  3283,  3285,  3287,
    3289,  3292,  3292,  3301,  3303,  3311,  3311,  3313,  3315,  3317,
    3320,  3320,  3322,  3328,  3347,  3353,  3353,  3356,  3367,  3378,
    3385,  3391,  3397,  3403,  3409,  3416,  3416,  3418,  3418,  3420,
    3422,  3422,  3424,  3424,  3426,  3433,  3442,  3442,  3446,  3451,
    3459,  3459,  3461,  3461,  3463,  3465,  3472,  3472,  3474,  3485,
    3493,  3499,  3499,  3502,  3508,  3509,  3513,  3513,  3515,  3517,
    3519,  3523,  3523,  3525,  3530,  3539,  3544,  3550,  3550,  3552,
    3554,  3556,  3556,  3558,  3563,  3577,  3585,  3585,  3588,  3594,
    3600,  3606,  3614,  3624,  3629,  3635,  3635,  3637,  3639,  3641,
    3641,  3643,  3649,  3654,  3656,  3656,  3658,  3660,  3672,  3672,
    3674,  3679,  3688,  3693,  3699,  3699,  3701,  3703,  3705,  3705,
    3707,  3712,  3724,  3732,  3732,  3735,  3740,  3746,  3752,  3761,
    3766,  3772,  3772,  3774,  3776,  3778,  3778,  3780,  3786,  3791,
    3793,  3793,  3795,  3797,  3808,  3815,  3815,  3817,  3822,  3827,
    3834,  3834,  3836,  3841,  3846,  3853,  3853,  3855,  3860,  3865,
    3872,  3872,  3874,  3879,  3884,  3892,  3899,  3899,  3901,  3906,
    3911,  3918,  3918,  3920,  3925,  3930,  3937,  3937,  3939,  3944,
    3949,  3956,  3956,  3958,  3963,  3968,  3975,  3975,  3977,  3982,
    3987,  3994,  3994,  3996,  4001,  4007,  4013,  4022,  4028,  4042,
    4051,  4057,  4066,  4072,  4078,  4084,  4090,  4096,  4105,  4111,
    4120,  4125,  4131,  4148,  4149,  4153,  4154,  4155,  4157,  4159,
    4159,  4161,  4162,  4163,  4164,  4201,  4203,  4217,  4217,  4219,
    4221,  4223,  4225,  4225,  4228,  4229,  4230,  4231,  4232,  4234,
    4242,  4242,  4244,  4244,  4246,  4252,  4260,  4260,  4262,  4262,
    4264,  4270,  4278,  4278,  4280,  4280,  4282,  4288,  4296,  4296,
    4298,  4298,  4300,  4306,  4314,  4314,  4316,  4316,  4318,  4330,
    4338,  4340,  4340,  4342,  4344,  4353,  4355,  4355,  4357,  4357,
    4359,  4375,  4378,  4378,  4380,  4380,  4383,  5474,  5479,  5487
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
  "MATRIXTOSCALARSTART", "MATRIXTOSCALAREND", "MATRIXDIAGONALSTART",
  "MATRIXDIAGONALEND", "MATRIXDOTTIMESSTART", "MATRIXDOTTIMESEND",
  "MATRIXIDENTITYSTART", "MATRIXIDENTITYEND", "MATRIXINVERSESTART",
  "MATRIXINVERSEEND", "MATRIXLOWERTRIANGLESTART", "MATRIXLOWERTRIANGLEEND",
  "MATRIXUPPERTRIANGLESTART", "MATRIXUPPERTRIANGLEEND", "MATRIXMERGESTART",
  "MATRIXMERGEEND", "MATRIXMINUSSTART", "MATRIXMINUSEND",
  "MATRIXPLUSSTART", "MATRIXPLUSEND", "MATRIXTIMESSTART", "MATRIXTIMESEND",
  "MATRIXSCALARTIMESSTART", "MATRIXSCALARTIMESEND",
  "MATRIXSUBMATRIXATSTART", "MATRIXSUBMATRIXATEND", "MATRIXTRANSPOSESTART",
  "MATRIXTRANSPOSEEND", "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT",
  "IDATT", "COEFATT", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
  "osrldoc", "osrlStartEmpty", "osrlStart", "osrlAttributes",
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
  "osglIntVectorBase64", "osglIntVectorBase64Content",
  "osglIntVectorBase64Empty", "osglIntVectorBase64Laden",
  "osglBase64SizeATT", "osglIncrATT", "osglMultATT", 0
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
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   377,   378,   378,   379,   380,   381,   381,   382,   382,
     383,   384,   385,   386,   386,   387,   388,   388,   389,   389,
     390,   391,   391,   392,   392,   393,   394,   395,   395,   396,
     396,   396,   396,   396,   396,   396,   396,   396,   397,   398,
     399,   400,   400,   401,   401,   401,   402,   402,   403,   403,
     404,   405,   406,   406,   407,   408,   409,   410,   410,   411,
     411,   412,   412,   413,   414,   415,   415,   416,   416,   417,
     418,   419,   420,   421,   421,   422,   422,   423,   424,   425,
     426,   427,   427,   428,   428,   429,   430,   431,   432,   433,
     433,   434,   434,   435,   436,   437,   438,   439,   439,   440,
     440,   441,   442,   443,   444,   445,   445,   446,   446,   447,
     448,   449,   450,   451,   451,   452,   452,   453,   454,   455,
     456,   457,   458,   458,   459,   459,   460,   461,   462,   462,
     463,   464,   465,   466,   466,   467,   467,   467,   468,   468,
     469,   469,   470,   471,   471,   472,   472,   473,   474,   475,
     475,   476,   476,   476,   476,   476,   476,   477,   478,   479,
     479,   480,   480,   481,   482,   483,   484,   485,   486,   486,
     487,   487,   488,   489,   490,   491,   492,   493,   493,   494,
     494,   495,   496,   497,   498,   499,   500,   500,   501,   501,
     502,   503,   504,   505,   506,   506,   507,   508,   509,   510,
     511,   512,   512,   513,   513,   514,   515,   516,   516,   517,
     518,   519,   520,   520,   521,   521,   521,   522,   522,   523,
     523,   524,   525,   525,   526,   526,   527,   528,   529,   529,
     530,   530,   530,   530,   530,   530,   531,   532,   533,   533,
     534,   534,   535,   536,   537,   538,   539,   539,   540,   540,
     541,   542,   543,   544,   545,   545,   546,   546,   547,   548,
     549,   550,   551,   551,   552,   552,   553,   554,   555,   556,
     557,   557,   558,   558,   559,   560,   561,   562,   563,   564,
     564,   565,   565,   566,   567,   568,   568,   569,   570,   571,
     572,   572,   573,   573,   573,   574,   574,   575,   575,   576,
     577,   577,   578,   578,   579,   580,   581,   581,   582,   582,
     582,   582,   582,   582,   582,   582,   582,   582,   582,   583,
     584,   585,   585,   586,   586,   587,   588,   589,   590,   591,
     591,   592,   592,   593,   594,   595,   596,   597,   597,   598,
     598,   599,   600,   601,   602,   603,   603,   604,   604,   605,
     606,   607,   608,   609,   609,   610,   610,   611,   612,   613,
     614,   615,   616,   616,   617,   617,   618,   619,   620,   620,
     621,   622,   623,   623,   624,   624,   624,   624,   625,   625,
     626,   626,   627,   628,   629,   629,   630,   631,   632,   633,
     633,   634,   634,   635,   636,   637,   638,   639,   640,   640,
     641,   641,   642,   643,   644,   645,   646,   647,   647,   648,
     648,   649,   650,   651,   652,   653,   653,   654,   655,   656,
     657,   658,   659,   659,   660,   660,   661,   662,   663,   663,
     664,   665,   666,   667,   667,   668,   668,   668,   669,   669,
     670,   670,   671,   672,   673,   673,   674,   674,   674,   674,
     675,   675,   676,   676,   677,   678,   679,   679,   680,   681,
     682,   683,   683,   684,   684,   684,   685,   686,   687,   688,
     689,   690,   691,   692,   692,   693,   693,   693,   694,   694,
     695,   695,   696,   697,   698,   698,   699,   700,   701,   702,
     702,   703,   703,   704,   704,   705,   705,   706,   707,   707,
     708,   708,   709,   710,   711,   711,   712,   713,   713,   714,
     714,   715,   716,   717,   718,   718,   719,   720,   721,   721,
     722,   722,   723,   724,   725,   725,   726,   727,   728,   728,
     729,   729,   730,   731,   731,   732,   733,   734,   734,   735,
     735,   736,   737,   738,   738,   739,   740,   741,   741,   742,
     742,   743,   743,   744,   744,   745,   746,   747,   747,   748,
     749,   749,   750,   751,   752,   753,   753,   754,   755,   756,
     756,   757,   758,   759,   760,   760,   761,   762,   763,   763,
     764,   765,   766,   767,   767,   768,   769,   770,   770,   771,
     772,   773,   774,   774,   775,   776,   777,   777,   778,   779,
     780,   781,   781,   782,   783,   784,   784,   785,   786,   787,
     788,   788,   789,   790,   791,   791,   792,   793,   794,   795,
     795,   796,   797,   798,   798,   799,   800,   801,   802,   802,
     803,   804,   805,   806,   806,   807,   807,   807,   807,   807,
     807,   807,   807,   808,   808,   809,   809,   810,   811,   811,
     812,   812,   813,   814,   815,   815,   816,   816,   817,   817,
     818,   818,   819,   820,   821,   821,   822,   823,   824,   825,
     825,   826,   826,   826,   827,   827,   828,   829,   830,   831,
     831,   832,   833,   833,   834,   834,   835,   836,   837,   838,
     838,   839,   840,   841,   841,   842,   842,   843,   844,   845,
     845,   846,   847,   848,   848,   849,   849,   850,   851,   851,
     852,   853,   853,   854,   855,   856,   857,   857,   858,   859,
     860,   860,   861,   862,   863,   864,   864,   865,   866,   867,
     867,   868,   869,   870,   871,   871,   872,   873,   874,   874,
     875,   876,   877,   878,   878,   879,   880,   881,   881,   882,
     883,   884,   885,   885,   886,   887,   888,   888,   889,   890,
     891,   892,   892,   893,   894,   895,   895,   896,   897,   898,
     899,   899,   900,   901,   902,   902,   903,   904,   905,   906,
     906,   907,   908,   909,   910,   910,   911,   911,   911,   911,
     911,   911,   911,   911,   912,   912,   913,   913,   914,   915,
     915,   916,   916,   917,   918,   919,   919,   920,   920,   921,
     921,   922,   922,   923,   924,   925,   925,   926,   927,   928,
     929,   929,   930,   930,   930,   931,   931,   932,   933,   934,
     935,   935,   936,   937,   937,   938,   938,   939,   940,   941,
     942,   942,   943,   944,   945,   945,   946,   946,   947,   948,
     949,   949,   950,   951,   952,   952,   953,   953,   954,   955,
     955,   956,   957,   957,   958,   959,   960,   961,   961,   962,
     963,   964,   964,   965,   966,   967,   968,   968,   969,   970,
     971,   971,   972,   973,   974,   975,   975,   976,   977,   978,
     978,   979,   980,   981,   982,   982,   983,   984,   985,   985,
     986,   987,   988,   989,   989,   990,   991,   992,   992,   993,
     994,   995,   996,   996,   997,   998,   999,   999,  1000,  1001,
    1002,  1003,  1003,  1004,  1005,  1006,  1006,  1007,  1008,  1009,
    1010,  1010,  1011,  1012,  1013,  1014,  1014,  1015,  1015,  1015,
    1015,  1015,  1015,  1015,  1015,  1016,  1016,  1017,  1017,  1018,
    1019,  1019,  1020,  1020,  1021,  1022,  1023,  1023,  1024,  1024,
    1025,  1025,  1026,  1026,  1027,  1028,  1029,  1029,  1030,  1031,
    1032,  1033,  1033,  1034,  1034,  1034,  1035,  1035,  1036,  1037,
    1038,  1039,  1039,  1040,  1041,  1042,  1042,  1043,  1043,  1044,
    1045,  1046,  1046,  1047,  1048,  1049,  1050,  1050,  1051,  1051,
    1051,  1051,  1051,  1052,  1052,  1053,  1053,  1054,  1055,  1056,
    1056,  1057,  1058,  1058,  1059,  1059,  1060,  1061,  1062,  1062,
    1063,  1064,  1065,  1065,  1066,  1066,  1067,  1068,  1069,  1069,
    1070,  1071,  1072,  1073,  1073,  1074,  1074,  1074,  1074,  1075,
    1075,  1076,  1076,  1077,  1078,  1079,  1079,  1080,  1081,  1081,
    1082,  1082,  1083,  1084,  1085,  1086,  1086,  1087,  1088,  1089,
    1090,  1090,  1091,  1092,  1093,  1094,  1094,  1095,  1096,  1097,
    1098,  1098,  1099,  1100,  1101,  1102,  1103,  1103,  1104,  1105,
    1106,  1107,  1107,  1108,  1109,  1110,  1111,  1111,  1112,  1113,
    1114,  1115,  1115,  1116,  1117,  1118,  1119,  1119,  1120,  1121,
    1122,  1123,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,
    1131,  1132,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,
    1141,  1142,  1143,  1144,  1144,  1145,  1145,  1145,  1146,  1147,
    1147,  1148,  1148,  1148,  1148,  1149,  1150,  1151,  1151,  1152,
    1153,  1154,  1155,  1155,  1156,  1156,  1156,  1156,  1156,  1157,
    1158,  1158,  1159,  1159,  1160,  1161,  1162,  1162,  1163,  1163,
    1164,  1165,  1166,  1166,  1167,  1167,  1168,  1169,  1170,  1170,
    1171,  1171,  1172,  1173,  1174,  1174,  1175,  1175,  1176,  1177,
    1177,  1178,  1178,  1179,  1180,  1181,  1182,  1182,  1183,  1183,
    1184,  1185,  1186,  1186,  1187,  1187,  1188,  1189,  1190,  1191
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
       2,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       3,     3,     1,     1,     2,     1,     3,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,  1136,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   140,     0,
    1142,  1139,  1135,  1137,  1138,    16,    10,     3,     8,     9,
     142,   219,     0,     0,    24,    19,    21,    22,     0,  1141,
      14,   221,   297,     0,     0,   146,   141,   143,   144,    23,
      39,    88,    96,    64,   120,    80,    72,   104,   112,     0,
      26,    27,    29,     0,    30,     0,    31,     0,    32,     0,
      33,     0,    34,     0,    35,     0,    36,     0,    37,     0,
    1140,     0,  1153,  1152,     0,  1159,  1158,     0,  1165,  1164,
       0,  1171,  1170,     0,  1177,  1176,  1143,  1144,  1149,  1150,
    1151,  1145,  1155,  1156,  1157,  1146,  1161,  1162,  1163,  1147,
    1167,  1168,  1169,  1148,  1173,  1174,  1175,    11,   299,   440,
       0,     0,   225,   220,   222,   223,   145,   193,   184,   166,
     175,   199,   158,     0,   148,   149,   151,     0,   152,   168,
     153,   177,   154,   186,   155,   194,   156,     0,    25,    28,
    1129,     0,  1067,     0,  1088,     0,    40,    41,    44,  1064,
    1065,  1066,    43,  1085,  1086,  1087,    45,     0,    68,    63,
      65,    66,     0,    76,    71,    73,    74,     0,    84,    79,
      81,    82,     0,    92,    87,    89,    90,     0,   100,    95,
      97,    98,     0,   108,   103,   105,   106,     0,   116,   111,
     113,   114,  1129,     0,   121,     0,     0,     0,     0,     0,
     442,    15,   444,     0,   303,   298,   300,   301,   224,   245,
     237,   277,   269,   261,   253,     0,   227,   228,   230,     0,
     231,     0,   232,     0,   233,     0,   234,     0,   235,     0,
     147,   150,     0,   162,   157,   159,   160,     0,   167,     0,
     176,     0,   185,     0,   195,     0,   200,     0,     0,  1129,
    1129,     0,    49,    38,    46,    47,    42,    70,    67,     0,
      78,    75,     0,    86,    83,     0,    94,    91,     0,   102,
      99,     0,   110,   107,     0,   118,   115,     0,     0,     0,
     125,   119,   122,   123,  1154,  1160,  1166,  1172,  1178,     0,
     443,   302,   344,   352,   420,   336,   320,   328,   360,   414,
     405,   387,   396,     0,   305,   306,   308,     0,   309,     0,
     310,     0,   311,     0,   312,     0,   313,     0,   314,   389,
     315,   398,   316,   407,   317,   415,   318,     0,   226,   229,
       0,   241,   236,   238,   239,     0,   249,   244,   246,   247,
       0,   257,   252,   254,   255,     0,   265,   260,   262,   263,
       0,   273,   268,   270,   271,     0,   278,   164,   161,     0,
       0,   165,     0,  1093,   169,   171,   170,  1090,  1091,  1092,
       0,   174,   178,   180,   179,     0,   183,   187,   189,   188,
       0,   192,     0,   204,   198,   201,   202,  1129,  1128,  1131,
    1132,  1133,  1134,  1130,  1068,  1089,    48,    55,     0,    51,
      52,    57,    69,    77,    85,    93,   101,   109,   117,  1129,
     131,   124,     0,   127,   128,   133,     0,   453,   441,   450,
     451,  1129,  1129,  1129,  1129,   445,   448,   449,   446,   447,
     304,   307,     0,   324,   319,   321,   322,     0,   332,   327,
     329,   330,     0,   340,   335,   337,   338,     0,   348,   343,
     345,   346,     0,   356,   351,   353,   354,  1129,     0,   361,
       0,   388,     0,   397,     0,   406,     0,   416,     0,   421,
     243,   240,     0,   251,   248,     0,   259,   256,     0,   267,
     264,     0,  1123,  1124,   272,     0,   275,     0,   282,   276,
     279,   280,   163,     0,   173,  1129,     0,   182,     0,   191,
     197,     0,   210,   203,     0,   206,   207,   212,  1119,    50,
      53,     0,    56,  1114,   126,   129,     0,   132,   452,   459,
       0,  1018,   456,   461,     0,     0,     0,     0,   326,   323,
       0,   334,   331,     0,   342,   339,     0,   350,   347,     0,
     358,   355,     0,     0,     0,   365,   359,   362,   363,     0,
     386,   390,   392,   391,     0,   395,   399,   401,   400,     0,
     404,   408,   410,   409,     0,   413,     0,   425,   419,   422,
     423,   242,   250,   258,   266,   274,   288,   281,     0,   284,
     285,   290,   172,  1094,   181,   190,   196,   205,   208,     0,
     211,     0,    62,    54,     0,  1078,    58,    60,    59,  1075,
    1076,  1077,     0,   139,   130,     0,  1098,   134,   137,   135,
     136,  1095,  1096,  1097,   454,  1020,   457,   455,     0,     0,
     460,  1129,  1129,  1129,  1129,   325,   333,   341,   349,   357,
    1129,   371,   364,     0,   367,   368,   372,     0,   394,     0,
     403,     0,   412,   418,     0,   431,   424,     0,   427,   428,
     433,   283,   286,     0,   289,     0,   218,   209,   213,   216,
     214,   215,    61,  1129,   138,  1129,  1129,     0,  1021,     0,
     458,  1129,     0,     0,   462,   463,   464,   465,  1106,  1111,
    1117,  1122,  1120,   366,   369,     0,   393,   402,   411,   417,
     426,   429,     0,   432,     0,   296,   287,   291,   294,   292,
     293,   217,  1079,  1099,     0,     0,  1025,  1019,  1022,  1023,
     471,   495,     0,     0,  1129,  1129,     0,   381,     0,  1057,
     373,   370,   378,   379,   376,  1054,  1055,  1056,   377,   375,
     374,     0,   439,   430,   434,   437,   435,   436,   295,  1129,
    1024,  1031,     0,  1027,  1028,  1033,   497,   504,     0,     0,
     472,   473,   476,   475,   477,  1129,   468,   467,   385,   384,
     380,     0,   383,  1129,   438,  1118,  1026,  1029,     0,  1032,
     506,   679,   507,     0,   501,   496,   498,   499,     0,   481,
     470,   478,   479,   474,   466,   382,  1058,     0,  1042,  1030,
    1039,  1040,  1129,  1034,  1036,  1037,  1035,  1038,   681,   830,
     682,  1129,     0,   508,   503,   500,     0,   480,   487,     0,
     483,   484,   489,     0,  1050,  1051,  1041,     0,  1044,  1045,
    1047,  1048,  1049,     0,   832,   981,   833,  1129,     0,   683,
       0,   514,   511,   505,   509,   510,   502,   482,   485,     0,
     488,  1053,     0,  1043,  1046,  1129,   983,     0,     0,  1129,
       0,   834,     0,   689,   686,   680,   684,   685,  1129,   516,
       0,   533,     0,     0,   494,   486,   490,   492,   491,  1052,
    1109,   469,  1129,     0,   984,     0,   840,   837,   831,   835,
     836,  1129,   691,     0,   708,     0,  1116,   512,   535,   557,
       0,  1129,     0,   517,   493,     0,     0,   988,   982,   985,
     986,  1129,   842,     0,   859,     0,  1113,   687,   710,   779,
       0,  1129,     0,   692,   559,   628,     0,     0,   536,     0,
       0,   521,   515,   518,   519,  1129,   994,   987,     0,   990,
     991,   996,  1112,   838,   861,   930,     0,  1129,     0,   843,
     688,   716,   713,   709,   711,   712,     0,     0,   696,   690,
     693,   694,   513,   565,   562,   558,   560,   561,     0,   540,
     534,   537,   538,  1129,   527,   520,     0,   523,   524,   528,
    1115,   989,   992,     0,   995,   839,   867,   864,   860,   862,
     863,     0,     0,   847,   841,   844,   845,   782,   780,   784,
     718,     0,   725,     0,  1129,   702,   695,     0,   698,   699,
     703,   631,   629,   633,   567,     0,   574,     0,   539,   546,
       0,   542,   543,   547,  1121,   522,   525,     0,     0,  1006,
     993,  1003,  1004,   997,  1000,  1001,   998,   999,  1002,   933,
     931,   935,   869,     0,   876,     0,  1129,   853,   846,     0,
     849,   850,   854,     0,   783,   714,   727,   734,     0,  1129,
       0,   719,  1110,   697,   700,     0,     0,   632,   563,   576,
     583,     0,     0,   568,   541,   544,     0,     0,  1129,   529,
     526,   530,   531,     0,  1014,  1015,  1005,     0,  1008,  1009,
    1011,  1012,  1013,     0,   934,   865,   878,   885,     0,     0,
     870,  1105,   848,   851,     0,     0,   797,   781,   794,   795,
    1129,     0,  1072,     0,  1083,   785,   793,   792,  1069,  1070,
    1071,   789,   791,  1080,  1081,  1082,   790,   788,   787,   786,
     736,   743,     0,     0,   728,     0,  1181,   722,   717,   720,
     721,     0,   704,   701,   705,   706,     0,   646,   630,   643,
     644,     0,  1103,   634,   642,   641,   638,   639,   637,   640,
    1100,  1101,  1102,   636,   635,   585,   592,     0,     0,   577,
    1181,   571,   566,   569,   570,     0,   554,   548,   545,   551,
     552,   549,   550,     0,     0,  1017,     0,  1007,  1010,     0,
     948,   932,   945,   946,     0,  1062,   936,   942,  1059,  1060,
    1061,   944,   943,   940,   941,   939,   937,   938,   887,   894,
       0,     0,   879,  1181,   873,   868,   871,   872,     0,   855,
     852,   856,   857,   818,   804,   796,     0,   799,   801,   805,
     800,   815,   820,     0,  1129,  1129,   745,   752,     0,     0,
     737,  1181,   731,   726,   729,   730,  1129,     0,     0,   724,
    1179,  1180,     0,   667,   645,   653,     0,   648,   650,   654,
     649,   664,   669,  1129,   594,   601,     0,     0,   586,  1181,
     580,   575,   578,   579,     0,   573,   556,   553,     0,   532,
    1129,  1016,   955,   969,   947,     0,   950,   952,   956,   951,
     966,   971,  1129,   896,   903,     0,     0,   888,  1181,   882,
     877,   880,   881,     0,   875,     0,   798,   802,     0,   816,
       0,   819,  1129,  1073,  1084,   754,   761,     0,     0,   746,
    1181,   740,   735,   738,   739,     0,   733,  1107,     0,     0,
     723,  1184,  1182,  1186,   707,   647,   651,     0,   665,     0,
     668,  1104,   603,   610,     0,     0,   595,  1181,   589,   584,
     587,   588,     0,   582,   572,   555,  1074,   949,   953,     0,
     967,     0,   970,  1063,   905,   912,     0,     0,   897,  1181,
     891,   886,   889,   890,     0,   884,   874,   858,     0,   812,
     806,   803,   809,   810,   807,   808,  1181,   827,   817,   825,
     826,   821,   824,   823,   822,  1108,   763,   770,     0,     0,
     755,  1181,   749,   744,   747,   748,     0,   742,   732,     0,
       0,  1195,  1191,  1192,  1193,     0,  1185,     0,   661,   655,
     652,   658,   659,   656,   657,  1181,   676,   666,   674,   675,
     670,   673,   672,   671,   612,   619,     0,     0,   604,  1181,
     598,   593,   596,   597,     0,   591,   581,     0,   963,   957,
     954,   960,   961,   958,   959,  1181,   978,   968,   976,   977,
     972,   975,   974,   973,   914,   921,     0,     0,   906,  1181,
     900,   895,   898,   899,     0,   893,   883,  1125,  1126,  1127,
     811,     0,   814,     0,   829,   772,   715,     0,     0,   764,
    1181,   758,   753,   756,   757,     0,   751,   741,     0,     0,
    1194,     0,  1183,     0,     0,  1187,  1189,  1188,   660,     0,
     663,     0,   678,   621,   564,     0,     0,   613,  1181,   607,
     602,   605,   606,     0,   600,   590,   962,     0,   965,     0,
     980,   923,   866,     0,     0,   915,  1181,   909,   904,   907,
     908,     0,   902,   892,   813,   828,     0,   773,  1181,   767,
     762,   765,   766,     0,   760,   750,  1197,  1196,     0,     0,
       0,   662,   677,     0,   622,  1181,   616,   611,   614,   615,
       0,   609,   599,   964,   979,     0,   924,  1181,   918,   913,
     916,   917,     0,   911,   901,  1181,   776,   771,   774,   775,
       0,   769,   759,  1190,     0,     0,  1181,   625,   620,   623,
     624,     0,   618,   608,  1181,   927,   922,   925,   926,     0,
     920,   910,     0,   778,   768,  1198,  1199,     0,   627,   617,
       0,   929,   919,   777,   626,   928
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    27,    28,    29,    15,    16,
       8,     9,    18,    19,    35,    36,    37,    59,    60,    61,
      62,    63,   155,   156,   157,   263,   264,   265,   408,   409,
     410,   411,   521,   522,   606,   603,    64,    65,   169,   170,
     171,   269,    66,    67,   174,   175,   176,   272,    68,    69,
     179,   180,   181,   275,    70,    71,   184,   185,   186,   278,
      72,    73,   189,   190,   191,   281,    74,    75,   194,   195,
     196,   284,    76,    77,   199,   200,   201,   287,    78,    79,
     203,   291,   292,   293,   422,   423,   424,   425,   526,   527,
     617,   614,    31,    32,    46,    47,    48,   133,   134,   135,
     136,   137,   244,   245,   246,   369,   138,   139,   247,   248,
     374,   371,   503,   140,   141,   249,   250,   382,   381,   506,
     142,   143,   251,   252,   387,   386,   508,   144,   145,   253,
     391,   511,   146,   147,   255,   394,   395,   396,   514,   515,
     516,   517,   599,   600,   668,   667,    42,    43,   123,   124,
     125,   225,   226,   227,   228,   229,   342,   343,   344,   482,
     230,   231,   347,   348,   349,   485,   232,   233,   352,   353,
     354,   488,   234,   235,   357,   358,   359,   491,   236,   237,
     362,   363,   364,   495,   238,   239,   365,   499,   500,   501,
     588,   589,   590,   591,   663,   664,   707,   706,   119,   120,
     215,   216,   217,   313,   314,   315,   316,   317,   444,   445,
     446,   540,   318,   319,   449,   450,   451,   543,   320,   321,
     454,   455,   456,   546,   322,   323,   459,   460,   461,   549,
     324,   325,   464,   465,   466,   552,   326,   327,   468,   556,
     557,   558,   643,   644,   645,   646,   695,   730,   731,   732,
     733,   771,   772,   328,   329,   470,   471,   561,   560,   647,
     330,   331,   472,   473,   566,   565,   649,   332,   333,   474,
     475,   571,   570,   651,   334,   335,   476,   575,   654,   336,
     337,   478,   578,   579,   580,   657,   658,   659,   660,   702,
     703,   744,   743,   211,   212,   299,   300,   435,   428,   429,
     430,   530,   531,   532,   533,   629,   630,   684,   685,   686,
     687,   680,   721,   722,   759,   760,   761,   790,   791,   792,
     819,   820,   821,   822,   849,   850,   876,   875,   757,   758,
     785,   786,   787,   816,   781,   782,   812,   843,   844,   845,
     870,   871,   872,   902,   932,   933,   934,   976,   977,   978,
     979,  1027,  1079,  1080,   899,   900,   927,   970,   971,   972,
    1020,  1021,  1022,  1023,  1076,  1177,  1178,  1179,  1180,  1278,
     925,   926,   965,   966,   967,  1015,  1016,  1017,  1072,  1172,
    1173,  1174,  1274,  1070,  1071,  1168,  1271,  1272,  1273,  1352,
    1166,  1167,  1267,  1349,  1350,  1351,  1444,  1265,  1266,  1345,
    1441,  1442,  1443,  1523,  1343,  1344,  1437,  1520,  1521,  1522,
    1570,  1435,  1436,  1516,  1567,  1568,  1569,  1601,  1514,  1515,
    1563,  1598,  1599,  1600,  1617,   962,  1012,  1013,  1066,  1067,
    1153,  1148,  1149,  1150,  1256,  1257,  1258,  1259,  1337,  1419,
    1420,  1421,  1422,  1509,  1260,  1261,  1262,  1339,  1340,  1430,
    1427,  1428,  1429,  1511,   809,   810,   838,   865,   866,   867,
     893,   894,   895,   922,   959,   960,   961,  1007,  1008,  1009,
    1010,  1065,  1142,  1143,   919,   920,   953,   954,   955,  1001,
    1002,  1003,  1060,  1138,  1139,  1140,  1248,  1057,  1058,  1133,
    1243,  1244,  1245,  1325,  1131,  1132,  1239,  1322,  1323,  1324,
    1406,  1237,  1238,  1318,  1403,  1404,  1405,  1495,  1316,  1317,
    1399,  1492,  1493,  1494,  1553,  1397,  1398,  1488,  1550,  1551,
    1552,  1590,  1486,  1487,  1546,  1587,  1588,  1589,  1612,   950,
     998,   999,  1053,  1054,  1115,  1107,  1108,  1109,  1226,  1227,
    1228,  1229,  1308,  1380,  1381,  1382,  1383,  1481,  1230,  1231,
    1232,  1310,  1311,  1391,  1388,  1389,  1390,  1483,   835,   836,
     860,   888,   889,   890,   913,   914,   915,   948,   994,   995,
     996,  1049,  1050,  1051,  1052,  1104,  1219,  1220,   945,   946,
     988,   989,   990,  1043,  1044,  1045,  1099,  1215,  1216,  1217,
    1303,  1097,  1098,  1211,  1300,  1301,  1302,  1374,  1209,  1210,
    1296,  1371,  1372,  1373,  1474,  1294,  1295,  1367,  1471,  1472,
    1473,  1541,  1365,  1366,  1467,  1538,  1539,  1540,  1582,  1465,
    1466,  1534,  1579,  1580,  1581,  1609,  1532,  1533,  1575,  1606,
    1607,  1608,  1620,   985,  1040,  1041,  1093,  1094,  1196,  1191,
    1192,  1193,  1285,  1286,  1287,  1288,  1359,  1449,  1450,  1451,
    1452,  1527,  1289,  1290,  1291,  1361,  1362,  1460,  1457,  1458,
    1459,  1529,   857,   858,   883,   908,   909,   910,   938,   939,
     940,   941,   983,   984,  1033,  1030,  1031,  1032,  1087,  1088,
    1089,  1090,  1091,  1092,  1186,   627,   628,   677,   717,   718,
     719,   752,   753,   754,   755,   778,   779,   803,   799,   800,
     801,   827,   828,   829,   830,   831,   832,   852,   734,   735,
     736,   737,  1197,  1198,  1199,  1200,   158,   159,   160,   161,
    1117,  1118,  1119,  1120,  1081,   608,   609,   610,   611,  1122,
    1123,  1124,  1125,   162,   163,   164,   165,   376,   377,   378,
     379,   620,   621,   622,   623,  1159,  1160,  1161,  1162,   949,
     436,  1061,  1128,   807,   923,   437,   861,   839,   204,   884,
     813,   438,   678,   166,   469,   903,   439,   496,  1482,   257,
     258,   403,    10,    11,    22,    23,    24,    38,    39,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
    1249,  1250,  1332,  1333,  1415,  1416,  1505,  1502,  1251,  1412,
    1413,  1414,  1329,  1506,  1507
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1340
static const yytype_int16 yypact[] =
{
     121, -1340, -1340,    86,    27,    74, -1340, -1340,    75,    47,
   -1340,   267, -1340,   277, -1340, -1340, -1340, -1340,    41,   305,
   -1340, -1340, -1340, -1340, -1340,    27, -1340, -1340, -1340, -1340,
   -1340,    58,   336,    -6, -1340, -1340, -1340, -1340,    72,   433,
      75, -1340,    69,   348,   -21, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,    76,
     200, -1340, -1340,   441, -1340,   405, -1340,   419, -1340,   440,
   -1340,   480, -1340,   482, -1340,   485, -1340,   487, -1340,   122,
   -1340,   148, -1340, -1340,   168, -1340, -1340,   172, -1340, -1340,
     180, -1340, -1340,   187, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   120,
     489,   140, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,   133,   -28, -1340, -1340,   494, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   465, -1340,   122, -1340, -1340,
   -1340,   204, -1340,   213, -1340,   500,   441, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340,    25, -1340, -1340,
   -1340, -1340,    22, -1340, -1340, -1340, -1340,    28, -1340, -1340,
   -1340, -1340,    40, -1340, -1340, -1340, -1340,    38, -1340, -1340,
   -1340, -1340,    23, -1340, -1340, -1340, -1340,    19, -1340, -1340,
   -1340, -1340, -1340,   506, -1340,    16,    18,    26,    51,    67,
   -1340, -1340, -1340,   -17, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   184,   112, -1340, -1340,   512,
   -1340,   516, -1340,   518, -1340,   521, -1340,   524, -1340,   122,
   -1340, -1340,    17, -1340, -1340, -1340, -1340,   242,   307,   255,
     307,   263,   307,   283, -1340,   526, -1340,   292,    14, -1340,
   -1340,   -53, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   166,
   -1340, -1340,   144, -1340, -1340,   154, -1340, -1340,   176, -1340,
   -1340,   188, -1340, -1340,   160, -1340, -1340,   159,   337,    65,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   528,
     201, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,   280,   101, -1340, -1340,   534, -1340,   536,
   -1340,   545, -1340,   549, -1340,   551, -1340,   329, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   465, -1340,   122, -1340, -1340,
      49, -1340, -1340, -1340, -1340,    45, -1340, -1340, -1340, -1340,
      10, -1340, -1340, -1340, -1340,    20, -1340, -1340, -1340, -1340,
      29, -1340, -1340, -1340, -1340,   553, -1340, -1340, -1340,   195,
     560, -1340,   371, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
     560, -1340, -1340, -1340, -1340,   560, -1340, -1340, -1340, -1340,
     374, -1340,    93, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   269,   222,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340,   249,   258, -1340, -1340,   -26, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340,    30, -1340, -1340, -1340, -1340,    21, -1340, -1340,
   -1340, -1340,    34, -1340, -1340, -1340, -1340,    44, -1340, -1340,
   -1340, -1340,    43, -1340, -1340, -1340, -1340, -1340,   558, -1340,
     396,   307,   398,   307,   410,   307,   414, -1340,   561, -1340,
   -1340, -1340,   327, -1340, -1340,   342, -1340, -1340,   268, -1340,
   -1340,   289, -1340, -1340, -1340,   314, -1340,    98, -1340, -1340,
   -1340, -1340, -1340,   385, -1340, -1340,   387, -1340,   409, -1340,
   -1340,   416, -1340, -1340,   340,   369, -1340, -1340, -1340, -1340,
   -1340,   564,   413, -1340, -1340, -1340,   568,   418, -1340, -1340,
     438,   -62, -1340, -1340,   514,   542,   547,   570, -1340, -1340,
     350, -1340, -1340,   370, -1340, -1340,   388, -1340, -1340,   469,
   -1340, -1340,   471,   590,   -83, -1340, -1340, -1340, -1340,   560,
   -1340, -1340, -1340, -1340,   560, -1340, -1340, -1340, -1340,   560,
   -1340, -1340, -1340, -1340,   608, -1340,   117, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   455,   496,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   583,
     418,   475, -1340, -1340,   640, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340,   507, -1340, -1340,   655, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   651,   690,
      59, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,   520,   533, -1340, -1340,   552, -1340,   556,
   -1340,   565, -1340, -1340,   566, -1340, -1340,   613,   615, -1340,
   -1340, -1340, -1340,   589,   418,   616, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340,   593, -1340,   594,
   -1340, -1340,   759,   760, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   265, -1340, -1340, -1340, -1340,
   -1340, -1340,   595,   418,   621, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340,   758,   -72, -1340, -1340, -1340, -1340,
   -1340,   633,   441,   761, -1340, -1340,    24, -1340,   765, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340,   626, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340,   617,   606, -1340, -1340, -1340,   571,   597,   599,
     441, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340,   596, -1340, -1340, -1340, -1340, -1340, -1340,   602,   402,
   -1340,   641,   749,    37, -1340, -1340, -1340, -1340,   161, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340,   -25, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   672,
     755, -1340,   612, -1340, -1340, -1340,   647, -1340, -1340,   614,
     619, -1340, -1340,   778, -1340, -1340, -1340,   622,   299, -1340,
   -1340, -1340, -1340,   779, -1340,   637,   763, -1340,   618, -1340,
     783,   530, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   620,
     394, -1340,   714, -1340, -1340, -1340, -1340,   631,   767, -1340,
     625, -1340,   789,   535, -1340, -1340, -1340, -1340, -1340, -1340,
     598,   600,   766,   629, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,   650, -1340,   792,   689, -1340, -1340, -1340,
   -1340, -1340, -1340,   667,   702,   784, -1340, -1340, -1340,   706,
     766, -1340,   652, -1340, -1340,   802,    15, -1340, -1340, -1340,
   -1340, -1340, -1340,   701,   710,   794, -1340, -1340, -1340, -1340,
     654, -1340,   656, -1340, -1340, -1340,   659,   661, -1340,   806,
    -143, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   664,   668,
   -1340, -1340, -1340, -1340, -1340, -1340,   663, -1340,   665, -1340,
     674,   720, -1340, -1340, -1340, -1340,   810,  -102, -1340, -1340,
   -1340, -1340,   678,   723, -1340, -1340, -1340, -1340,   479, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340,   562,   624, -1340, -1340,
   -1340, -1340, -1340,   669,   293,   683,   729, -1340, -1340, -1340,
   -1340,   812,   -14, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340,   718,   742,   807, -1340, -1340, -1340,   567,   697, -1340,
   -1340, -1340, -1340, -1340, -1340,   731,   745,   807, -1340, -1340,
     636,   632, -1340, -1340, -1340, -1340, -1340,   216,    66, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,   735,   751,   807, -1340, -1340, -1340,   724,
     736, -1340, -1340,   673,   573, -1340, -1340,   753,   807, -1340,
     675, -1340, -1340, -1340, -1340,   235,   677,   366, -1340, -1340,
     756,   807,   679, -1340, -1340, -1340,   237,   560, -1340, -1340,
   -1340, -1340, -1340,   837, -1340, -1340, -1340,   699,   391, -1340,
   -1340, -1340, -1340,   682,   538, -1340, -1340,   757,   807,   684,
   -1340, -1340, -1340, -1340,   382,   -38, -1340, -1340, -1340, -1340,
   -1340,   842, -1340,   845, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340,   768,   807,   686, -1340,   843,   764, -1340, -1340, -1340,
   -1340,   560, -1340, -1340, -1340, -1340,   -35, -1340, -1340, -1340,
   -1340,   847, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340,   769,   807,   688, -1340,
     764, -1340, -1340, -1340, -1340,     6, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,   657,   848, -1340,   777, -1340, -1340,   -32,
   -1340, -1340, -1340, -1340,   853, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   775,
     807,   692, -1340,   764, -1340, -1340, -1340, -1340,   560, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340,   716,   727, -1340, -1340,
     746, -1340, -1340,   858, -1340, -1340, -1340,   737,   807,   696,
   -1340,   764, -1340, -1340, -1340, -1340, -1340,   825,   770, -1340,
     752, -1340,   733, -1340, -1340, -1340,   739,   676, -1340, -1340,
     754, -1340, -1340, -1340, -1340,   743,   807,   698, -1340,   764,
   -1340, -1340, -1340, -1340,   773, -1340, -1340, -1340,   680, -1340,
   -1340, -1340, -1340, -1340, -1340,   741,   771, -1340, -1340,   762,
   -1340, -1340, -1340, -1340,   748,   807,   703, -1340,   764, -1340,
   -1340, -1340, -1340,   774, -1340,   776, -1340, -1340,   338, -1340,
     705,   199, -1340, -1340, -1340, -1340,   708,   807,   707, -1340,
     764, -1340, -1340, -1340, -1340,   782, -1340, -1340,   876,   709,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340,   357, -1340,   712,
     199, -1340, -1340,   713,   807,   715, -1340,   764, -1340, -1340,
   -1340, -1340,   801, -1340, -1340, -1340, -1340, -1340, -1340,   359,
   -1340,   717,   199, -1340, -1340,   722,   807,   719, -1340,   764,
   -1340, -1340, -1340, -1340,   803, -1340, -1340, -1340,    33, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340,   764, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340,   704,   807,   721,
   -1340,   764, -1340, -1340, -1340, -1340,   800, -1340, -1340,   884,
      39, -1340, -1340, -1340, -1340,   882,   695,     5, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   764, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   711,   807,   726, -1340,   764,
   -1340, -1340, -1340, -1340,   805, -1340, -1340,    77, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   764, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   725,   807,   728, -1340,   764,
   -1340, -1340, -1340, -1340,   808, -1340, -1340, -1340, -1340, -1340,
   -1340,   772, -1340,   781, -1340, -1340, -1340,   807,   730, -1340,
     764, -1340, -1340, -1340, -1340,   813, -1340, -1340,   886,   804,
   -1340,   894, -1340,   893,   895, -1340, -1340, -1340, -1340,   747,
   -1340,   786, -1340, -1340, -1340,   807,   732, -1340,   764, -1340,
   -1340, -1340, -1340,   821, -1340, -1340, -1340,   809, -1340,   788,
   -1340, -1340, -1340,   807,   734, -1340,   764, -1340, -1340, -1340,
   -1340,   823, -1340, -1340, -1340, -1340,   738, -1340,   764, -1340,
   -1340, -1340, -1340,   787, -1340, -1340, -1340, -1340,   795,   907,
     908, -1340, -1340,   740, -1340,   764, -1340, -1340, -1340, -1340,
     790, -1340, -1340, -1340, -1340,   744, -1340,   764, -1340, -1340,
   -1340, -1340,   791, -1340, -1340,   764, -1340, -1340, -1340, -1340,
     750, -1340, -1340, -1340,   910,   911,   764, -1340, -1340, -1340,
   -1340,   780, -1340, -1340,   764, -1340, -1340, -1340, -1340,   785,
   -1340, -1340,   793, -1340, -1340, -1340, -1340,   796, -1340, -1340,
     797, -1340, -1340, -1340, -1340, -1340
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   883, -1340,
     891, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   865,
   -1340, -1340, -1340, -1340,   799, -1340, -1340, -1340, -1340, -1340,
     517, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340,   504, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   798,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
     415, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,   811, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340,   339, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,   623, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340,   285, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340,   273, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,   403, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340,   173, -1340, -1340, -1340,
   -1340, -1340,   115, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   -41,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340,   -82, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340,  -319, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340,  -320, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,   -67,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
    -285, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,  -287,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,  -106, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340,  -341, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,  -343, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
       9, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
    -138, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,   198, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,   124, -1340, -1340, -1340, -1340,  -771, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340,  -145, -1340, -1340, -1340,
    -971, -1340, -1340, -1340, -1058,  -524, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340,  -694, -1340, -1340, -1340,  -246, -1340, -1340,
   -1340,  -587, -1340, -1340, -1340, -1340, -1340, -1340, -1340,  -141,
   -1340, -1000,  -963,   -27,   -98, -1340, -1340, -1340,  -128, -1340,
   -1340, -1340, -1340,  -647, -1340,  -886, -1340,  -365, -1339,  -200,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1083, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340, -1340,
   -1340, -1340, -1340, -1340, -1340
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     254,   739,   288,   619,   384,   504,   389,  1144,   804,  1477,
    1276,  1478,  1479,   671,   928,   507,   486,  1073,  1181,   256,
     509,   367,   398,   285,   489,   541,   270,   282,   763,   267,
     768,   769,   273,  1005,   538,   492,   493,  1477,   544,  1478,
    1479,   814,   279,  1499,   276,  1100,  1221,   550,   547,   126,
     528,   483,   823,   480,   824,   825,   974,   301,  1134,   404,
     405,   127,    49,   128,   302,   129,   763,   130,   127,   406,
     128,  1169,   129,  1282,   130,   764,   670,   710,  1510,  1223,
     750,  1477,  1253,  1478,  1479,  1283,     6,  1275,    12,   625,
      14,  1047,     7,   751,   641,   681,  1155,  1224,  1212,   529,
    1048,   642,   303,   375,  1163,   383,  1225,   388,  1528,  1254,
      30,   366,  1284,   764,    17,    50,   747,   131,   407,   975,
     682,    51,   683,  1202,   131,    52,   548,    53,   304,    41,
    1304,  1207,  1240,     1,     2,   529,   305,  1500,    80,    54,
     709,   826,   118,  1083,   148,  1084,  1085,   132,   202,    55,
     306,    56,   307,   205,   132,   484,   878,    57,  1326,   268,
    1006,   481,   936,   551,  1255,   937,   308,  1268,   277,  1480,
     280,   815,   309,   206,   310,    58,   311,   207,   312,   746,
     271,  1164,   302,  1526,   274,   208,  1353,   283,   545,   494,
     477,   542,   209,   368,   648,   210,   487,   518,   539,   650,
     490,   286,   770,   240,   652,  1508,  1277,   259,   420,   479,
    1297,   421,   218,  1034,  1086,  1375,   260,  1059,   431,   523,
     303,   219,   294,   220,   432,   563,  1077,   568,   295,   573,
     433,   534,   535,   536,   537,   434,   512,  1407,  1319,   513,
     296,   586,   151,   152,   587,  1141,   304,  1175,  1176,   219,
    1384,   220,   370,  1078,   305,   806,   338,   221,   615,   616,
     655,   604,   605,   656,  1445,   380,  1346,   553,   306,   297,
     307,   222,  1078,   385,  1078,   726,   727,    20,    21,  1423,
     604,   605,   604,   605,   308,   221,  1475,    25,    26,   298,
     309,   223,   310,   390,   311,  1368,   312,   224,   397,   222,
     412,  1453,   413,  1484,   415,   593,   728,   729,   151,   152,
     414,  1394,   153,   154,   802,    33,    34,  1400,  1496,   223,
     416,    50,   372,   373,   417,   224,   562,    51,   567,   817,
     572,    52,   818,    53,   728,   729,   151,   152,   604,   605,
    1433,   418,  1512,   419,  1438,    54,    44,    45,  1378,  1379,
     151,   152,   615,   616,   440,    55,  1524,    56,   121,   122,
    1126,   467,  1463,    57,   372,   373,  1468,  1417,  1418,  1447,
    1448,   502,  1530,  1157,   505,  1078,   823,   607,   824,   825,
     510,    58,   618,   604,   605,  1110,  1542,   399,   400,   401,
     402,   519,  1218,   407,  1078,   524,  1078,  1037,  1489,   901,
    1204,   420,   604,   605,   604,   605,   559,  1554,   564,   151,
     152,   604,   605,   153,   154,   167,   168,  1111,  1112,  1078,
     569,  1151,  1152,   802,   574,   615,   616,   604,   605,   172,
     173,   688,   689,   690,   691,  1571,  1517,   151,   152,   581,
     692,   153,   154,   728,   729,   151,   152,   604,   605,   740,
     177,   178,   582,  1583,   583,   669,   151,   152,   604,   605,
    1036,   151,   152,   604,   605,  1591,  1535,  1127,  1083,   584,
    1084,  1085,   150,   712,   585,   713,   714,   615,   616,   592,
    1158,   723,  1602,   594,   151,   152,   597,  1547,   153,   154,
     182,   183,   187,   188,  1610,   192,   193,   197,   198,   213,
     214,   595,  1613,  1082,   242,   243,   596,  1205,   151,   152,
     261,   262,   512,  1618,   624,  1564,   289,   290,   635,   708,
     631,  1621,   340,   341,   766,   767,   345,   346,   350,   351,
    1121,   355,   356,  1576,   360,   361,   392,   393,   426,   427,
     636,  1145,   637,  1156,   442,   443,   447,   448,   632,   775,
     738,   638,  1182,   633,   947,   452,   453,  1110,   745,   457,
     458,   462,   463,   497,   498,   794,   492,   493,   554,   555,
    1203,   576,   577,   796,   601,   602,   634,   762,   612,   613,
    1222,   151,   152,   604,   605,   153,   154,  1194,  1195,  1111,
    1112,   639,  1110,   665,   666,   921,   640,   615,   616,   704,
     705,   661,   833,   715,   716,   741,   742,   783,   784,   788,
     789,   840,   797,   798,   653,   762,   151,   152,   604,   605,
     153,   154,   841,   842,  1111,  1112,  1113,  1114,   863,   864,
     873,   874,   615,   616,   805,   886,   887,   862,    81,   586,
      82,    83,    84,   673,    85,    86,    87,   672,    88,    89,
      90,   674,    91,    92,    93,   880,    94,    95,   675,   885,
     906,   907,   930,   931,   951,   952,   957,   958,   896,   963,
     964,   968,   969,   986,   987,   992,   993,  1018,  1019,  1028,
    1029,   676,   905,  1105,  1106,  1136,  1137,  1146,  1147,  1170,
    1171,   916,  1189,  1190,  1213,  1214,  1241,  1242,  1269,  1270,
     679,   929,  1298,  1299,   693,   877,  1320,  1321,  1347,  1348,
     641,   942,  1183,  1369,  1370,  1386,  1387,  1401,  1402,  1410,
    1411,   956,  1425,  1426,  1393,  1439,  1440,  1455,  1456,  1469,
    1470,  1490,  1491,  1503,  1504,   980,  1518,  1519,  1536,  1537,
    1548,  1549,  1565,  1566,  1577,  1578,   696,   991,  1585,  1586,
    1596,  1597,   697,  1432,  1604,  1605,   699,   698,   655,   700,
     711,   720,   724,   725,   749,   748,   756,   765,   773,   776,
     774,   751,   780,  1024,   795,  1462,  1252,   811,   808,   834,
     837,   846,   847,   851,  1385,   855,   856,   859,   853,   868,
     818,   869,   879,   881,   882,   891,   892,   898,   911,   901,
     897,   904,   912,   918,  1062,   917,   921,   924,   935,   943,
     947,   944,   973,  1424,   981,   936,  1004,   997,  1046,  1000,
    1055,  1011,  1014,   974,  1025,  1059,  1039,  1056,  1042,  1063,
    1069,  1019,  1005,  1068,  1074,  1454,  1096,  1095,  1102,  1035,
    1130,  1047,  1185,  1165,  1208,  1234,  1101,  1187,  1235,  1246,
    1263,  1236,  1264,  1305,  1280,  1281,  1292,  1279,  1293,  1135,
    1306,  1247,  1224,  1223,  1312,  1328,  1315,  1331,  1408,  1334,
    1330,  1253,  1342,  1354,  1376,  1255,  1282,  1364,  1184,  1283,
    1355,  1396,  1377,  1335,  1409,  1357,  1434,  1446,  1497,  1476,
    1498,  1485,  1501,  1525,  1556,  1464,  1543,  1555,  1513,  1545,
    1558,  1559,  1557,  1560,  1562,  1572,  1574,  1584,  1544,  1116,
    1233,  1593,  1531,  1594,  1595,  1573,    40,  1592,  1615,  1616,
    1603,  1611,  1154,   117,  1614,   149,   520,   525,   662,   694,
     598,   701,   241,   793,   626,   848,  1026,   441,  1336,  1075,
    1338,  1064,  1307,  1309,  1103,  1358,  1360,  1561,   982,  1201,
    1188,   777,   854,  1206,  1619,   266,  1129,  1038,     0,  1622,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1623,     0,     0,  1624,  1625,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1313,  1314,     0,   339,     0,     0,
       0,     0,     0,     0,     0,     0,  1327,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1341,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1363,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1395,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1392,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1431,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1461
};

static const yytype_int16 yycheck[] =
{
     145,   695,   202,   527,   250,   370,   252,  1065,   779,     4,
       4,     6,     7,   600,   900,   380,     6,  1017,  1076,   147,
     385,     4,     8,     4,     4,     4,     4,     4,   722,     4,
       6,     7,     4,   135,     4,     6,     7,     4,     4,     6,
       7,     4,     4,     4,     4,  1045,  1104,     4,     4,    70,
      76,     6,    77,     4,    79,    80,   199,    74,  1058,   259,
     260,    89,    68,    91,    81,    93,   760,    95,    89,   122,
      91,  1071,    93,   105,    95,   722,   600,   664,  1417,   117,
     152,     4,   117,     6,     7,   117,     0,  1170,    14,   151,
      15,   105,    65,   165,   177,    36,  1067,   135,  1098,   161,
     114,   184,   119,   248,  1067,   250,   144,   252,  1447,   144,
      69,   239,   144,   760,    67,   121,   703,   145,   171,   262,
      61,   127,    63,  1094,   145,   131,    82,   133,   145,    71,
    1213,  1094,  1132,    12,    13,   161,   153,    98,    66,   145,
     664,   166,    73,    77,    68,    79,    80,   175,    26,   155,
     167,   157,   169,     5,   175,   110,   850,   163,  1241,   134,
     262,   112,   147,   120,   199,   150,   183,  1167,   128,   136,
     132,   134,   189,     5,   191,   181,   193,     5,   195,   703,
     158,  1067,    81,   106,   156,     5,  1269,   164,   154,   160,
     335,   170,     5,   176,   559,    75,   186,   397,   168,   564,
     180,   182,   178,    70,   569,   200,   200,     3,   143,   337,
    1210,   146,    72,   984,   148,  1298,     3,    18,    17,   419,
     119,   109,   206,   111,    23,   471,    10,   473,   210,   475,
      29,   431,   432,   433,   434,    34,   143,  1320,  1238,   146,
     214,   143,    43,    44,   146,    10,   145,    10,    11,   109,
    1308,   111,    10,    37,   153,   779,    72,   145,    59,    60,
     143,    45,    46,   146,  1347,    10,  1266,   467,   167,   218,
     169,   159,    37,    10,    37,    10,    11,    10,    11,  1337,
      45,    46,    45,    46,   183,   145,  1369,    10,    11,   222,
     189,   179,   191,    10,   193,  1295,   195,   185,     6,   159,
     134,  1359,   158,  1386,   128,   505,    41,    42,    43,    44,
     156,  1311,    47,    48,    21,    10,    11,  1317,  1401,   179,
     132,   121,    57,    58,   164,   185,   471,   127,   473,   168,
     475,   131,   171,   133,    41,    42,    43,    44,    45,    46,
    1340,   182,  1425,     6,  1344,   145,    10,    11,    10,    11,
      43,    44,    59,    60,    74,   155,  1439,   157,    10,    11,
    1054,    32,  1362,   163,    57,    58,  1366,    10,    11,    10,
      11,   176,  1455,  1067,     3,    37,    77,   522,    79,    80,
       6,   181,   527,    45,    46,    19,  1469,   373,   374,   375,
     376,   122,    10,   171,    37,   146,    37,   984,  1398,    33,
    1094,   143,    45,    46,    45,    46,    10,  1490,    10,    43,
      44,    45,    46,    47,    48,    10,    11,    51,    52,    37,
      10,    55,    56,    21,    10,    59,    60,    45,    46,    10,
      11,   631,   632,   633,   634,  1518,  1436,    43,    44,   112,
     640,    47,    48,    41,    42,    43,    44,    45,    46,   695,
      10,    11,   110,  1536,   186,   600,    43,    44,    45,    46,
     984,    43,    44,    45,    46,  1548,  1466,  1054,    77,   180,
      79,    80,    31,   673,   160,   675,   676,    59,    60,    94,
    1067,   681,  1565,    96,    43,    44,   146,  1487,    47,    48,
      10,    11,    10,    11,  1577,    10,    11,    10,    11,    10,
      11,    92,  1585,  1027,    10,    11,    90,  1094,    43,    44,
      10,    11,   143,  1596,    76,  1515,    10,    11,   168,   664,
       6,  1604,    10,    11,   724,   725,    10,    11,    10,    11,
    1054,    10,    11,  1533,    10,    11,    10,    11,    10,    11,
     170,  1065,   154,  1067,    10,    11,    10,    11,     6,   749,
     695,    82,  1076,     6,    16,    10,    11,    19,   703,    10,
      11,    10,    11,    10,    11,   765,     6,     7,    10,    11,
    1094,    10,    11,   773,    10,    11,     6,   722,    10,    11,
    1104,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,   120,    19,    10,    11,    22,     6,    59,    60,    10,
      11,   146,   802,    10,    11,    10,    11,    10,    11,    10,
      11,   811,    10,    11,     6,   760,    43,    44,    45,    46,
      47,    48,    10,    11,    51,    52,    53,    54,    10,    11,
      10,    11,    59,    60,   779,    10,    11,   837,   205,   143,
     207,   208,   209,     3,   211,   212,   213,   172,   215,   216,
     217,   144,   219,   220,   221,   855,   223,   224,     3,   859,
      10,    11,    10,    11,    10,    11,    10,    11,   868,    10,
      11,    10,    11,    10,    11,    10,    11,   198,   199,    10,
      11,    30,   882,    10,    11,    10,    11,    10,    11,    10,
      11,   891,    10,    11,    10,    11,    10,    11,    10,    11,
      10,   901,    10,    11,   184,   850,    10,    11,    10,    11,
     177,   911,  1077,    10,    11,    10,    11,    10,    11,    10,
      11,   921,    10,    11,  1311,    10,    11,    10,    11,    10,
      11,    10,    11,    38,    39,   935,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,   194,   947,    10,    11,
      10,    11,   196,  1340,    10,    11,   190,   192,   143,   146,
     144,   167,     3,     3,     6,   144,   133,     6,     3,   152,
     144,   165,   201,   973,   178,  1362,  1141,    28,   137,   107,
      25,   134,   168,     5,  1308,     6,   149,    24,   166,     6,
     171,   261,    78,   162,    27,     6,   261,   197,     6,    33,
     202,   172,   113,   101,  1004,   138,    22,   101,     6,   108,
      16,   101,     6,  1337,   150,   147,     6,   143,     6,    99,
     102,   143,    99,   199,   262,    18,   143,    85,    99,   262,
      85,   199,   135,   102,   198,  1359,    85,   102,   114,   984,
      87,   105,     5,    87,    87,     3,  1046,   148,     3,     6,
       3,    83,    83,  1218,     6,    78,     3,   200,    83,  1059,
     144,    97,   135,   117,     6,    40,   129,   115,    86,   136,
     100,   117,   129,   100,   100,   199,   105,   129,  1078,   117,
     200,   173,   106,   144,     8,   144,   173,    86,    88,    86,
       6,   187,    10,    88,     8,   173,    88,    84,   187,   118,
       6,     8,    98,     8,   118,    84,   118,    84,   136,  1054,
    1110,   116,   187,     6,     6,   106,    25,   130,     8,     8,
     130,   130,  1067,    40,   174,    60,   409,   423,   589,   644,
     515,   658,   134,   760,   531,   820,   977,   314,  1257,  1021,
    1260,  1008,  1227,  1230,  1050,  1286,  1289,   200,   939,  1094,
    1088,   753,   828,  1094,   174,   156,  1054,   984,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,    -1,    -1,   188,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1234,  1235,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1246,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1311,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1340,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1362
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   378,   379,   380,     0,    65,   387,   388,
    1149,  1150,    14,   381,    15,   385,   386,    67,   389,   390,
      10,    11,  1151,  1152,  1153,    10,    11,   382,   383,   384,
      69,   469,   470,    10,    11,   391,   392,   393,  1154,  1155,
     387,    71,   523,   524,    10,    11,   471,   472,   473,    68,
     121,   127,   131,   133,   145,   155,   157,   163,   181,   394,
     395,   396,   397,   398,   413,   414,   419,   420,   425,   426,
     431,   432,   437,   438,   443,   444,   449,   450,   455,   456,
      66,   205,   207,   208,   209,   211,   212,   213,   215,   216,
     217,   219,   220,   221,   223,   224,  1156,  1157,  1158,  1159,
    1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,
    1170,  1171,  1172,  1173,  1174,  1175,  1176,   385,    73,   575,
     576,    10,    11,   525,   526,   527,    70,    89,    91,    93,
      95,   145,   175,   474,   475,   476,   477,   478,   483,   484,
     490,   491,   497,   498,   504,   505,   509,   510,    68,   396,
      31,    43,    44,    47,    48,   399,   400,   401,  1093,  1094,
    1095,  1096,  1110,  1111,  1112,  1113,  1140,    10,    11,   415,
     416,   417,    10,    11,   421,   422,   423,    10,    11,   427,
     428,   429,    10,    11,   433,   434,   435,    10,    11,   439,
     440,   441,    10,    11,   445,   446,   447,    10,    11,   451,
     452,   453,    26,   457,  1135,     5,     5,     5,     5,     5,
      75,   670,   671,    10,    11,   577,   578,   579,    72,   109,
     111,   145,   159,   179,   185,   528,   529,   530,   531,   532,
     537,   538,   543,   544,   549,   550,   555,   556,   561,   562,
      70,   476,    10,    11,   479,   480,   481,   485,   486,   492,
     493,   499,   500,   506,  1093,   511,  1135,  1146,  1147,     3,
       3,    10,    11,   402,   403,   404,   401,     4,   134,   418,
       4,   158,   424,     4,   156,   430,     4,   128,   436,     4,
     132,   442,     4,   164,   448,     4,   182,   454,  1146,    10,
      11,   458,   459,   460,   206,   210,   214,   218,   222,   672,
     673,    74,    81,   119,   145,   153,   167,   169,   183,   189,
     191,   193,   195,   580,   581,   582,   583,   584,   589,   590,
     595,   596,   601,   602,   607,   608,   613,   614,   630,   631,
     637,   638,   644,   645,   651,   652,   656,   657,    72,   530,
      10,    11,   533,   534,   535,    10,    11,   539,   540,   541,
      10,    11,   545,   546,   547,    10,    11,   551,   552,   553,
      10,    11,   557,   558,   559,   563,  1135,     4,   176,   482,
      10,   488,    57,    58,   487,  1093,  1114,  1115,  1116,  1117,
      10,   495,   494,  1093,  1114,    10,   502,   501,  1093,  1114,
      10,   507,    10,    11,   512,   513,   514,     6,     8,   373,
     374,   375,   376,  1148,  1146,  1146,   122,   171,   405,   406,
     407,   408,   134,   158,   156,   128,   132,   164,   182,     6,
     143,   146,   461,   462,   463,   464,    10,    11,   675,   676,
     677,    17,    23,    29,    34,   674,  1127,  1132,  1138,  1143,
      74,   582,    10,    11,   585,   586,   587,    10,    11,   591,
     592,   593,    10,    11,   597,   598,   599,    10,    11,   603,
     604,   605,    10,    11,   609,   610,   611,    32,   615,  1141,
     632,   633,   639,   640,   646,   647,   653,  1093,   658,  1135,
       4,   112,   536,     6,   110,   542,     6,   186,   548,     4,
     180,   554,     6,     7,   160,   560,  1144,    10,    11,   564,
     565,   566,   176,   489,  1144,     3,   496,  1144,   503,  1144,
       6,   508,   143,   146,   515,   516,   517,   518,  1146,   122,
     407,   409,   410,  1146,   146,   463,   465,   466,    76,   161,
     678,   679,   680,   681,  1146,  1146,  1146,  1146,     4,   168,
     588,     4,   170,   594,     4,   154,   600,     4,    82,   606,
       4,   120,   612,  1146,    10,    11,   616,   617,   618,    10,
     635,   634,  1093,  1114,    10,   642,   641,  1093,  1114,    10,
     649,   648,  1093,  1114,    10,   654,    10,    11,   659,   660,
     661,   112,   110,   186,   180,   160,   143,   146,   567,   568,
     569,   570,    94,  1146,    96,    92,    90,   146,   517,   519,
     520,    10,    11,   412,    45,    46,   411,  1093,  1102,  1103,
    1104,  1105,    10,    11,   468,    59,    60,   467,  1093,  1102,
    1118,  1119,  1120,  1121,    76,   151,   680,  1062,  1063,   682,
     683,     6,     6,     6,     6,   168,   170,   154,    82,   120,
       6,   177,   184,   619,   620,   621,   622,   636,  1144,   643,
    1144,   650,  1144,     6,   655,   143,   146,   662,   663,   664,
     665,   146,   569,   571,   572,    10,    11,   522,   521,  1093,
    1102,  1118,   172,     3,   144,     3,    30,  1064,  1139,    10,
     688,    36,    61,    63,   684,   685,   686,   687,  1146,  1146,
    1146,  1146,  1146,   184,   621,   623,   194,   196,   192,   190,
     146,   664,   666,   667,    10,    11,   574,   573,  1093,  1102,
    1118,   144,  1146,  1146,  1146,    10,    11,  1065,  1066,  1067,
     167,   689,   690,  1146,     3,     3,    10,    11,    41,    42,
     624,   625,   626,   627,  1085,  1086,  1087,  1088,  1093,  1110,
    1114,    10,    11,   669,   668,  1093,  1102,  1118,   144,     6,
     152,   165,  1068,  1069,  1070,  1071,   133,   705,   706,   691,
     692,   693,  1093,  1110,  1140,     6,  1146,  1146,     6,     7,
     178,   628,   629,     3,   144,  1146,   152,  1070,  1072,  1073,
     201,   711,   712,    10,    11,   707,   708,   709,    10,    11,
     694,   695,   696,   693,  1146,   178,  1146,    10,    11,  1075,
    1076,  1077,    21,  1074,  1085,  1093,  1102,  1130,   137,   831,
     832,    28,   713,  1137,     4,   134,   710,   168,   171,   697,
     698,   699,   700,    77,    79,    80,   166,  1078,  1079,  1080,
    1081,  1082,  1083,  1146,   107,   935,   936,    25,   833,  1134,
    1146,    10,    11,   714,   715,   716,   134,   168,   699,   701,
     702,     5,  1084,   166,  1080,     6,   149,  1039,  1040,    24,
     937,  1133,  1146,    10,    11,   834,   835,   836,     6,   261,
     717,   718,   719,    10,    11,   704,   703,  1093,  1110,    78,
    1146,   162,    27,  1041,  1136,  1146,    10,    11,   938,   939,
     940,     6,   261,   837,   838,   839,  1146,   202,   197,   731,
     732,    33,   720,  1142,   172,  1146,    10,    11,  1042,  1043,
    1044,     6,   113,   941,   942,   943,  1146,   138,   101,   851,
     852,    22,   840,  1131,   101,   747,   748,   733,  1142,  1146,
      10,    11,   721,   722,   723,     6,   147,   150,  1045,  1046,
    1047,  1048,  1146,   108,   101,   955,   956,    16,   944,  1126,
     906,    10,    11,   853,   854,   855,  1146,    10,    11,   841,
     842,   843,   802,    10,    11,   749,   750,   751,    10,    11,
     734,   735,   736,     6,   199,   262,   724,   725,   726,   727,
    1146,   150,  1047,  1049,  1050,  1010,    10,    11,   957,   958,
     959,  1146,    10,    11,   945,   946,   947,   143,   907,   908,
      99,   856,   857,   858,     6,   135,   262,   844,   845,   846,
     847,   143,   803,   804,    99,   752,   753,   754,   198,   199,
     737,   738,   739,   740,  1146,   262,   726,   728,    10,    11,
    1052,  1053,  1054,  1051,  1085,  1093,  1102,  1118,  1130,   143,
    1011,  1012,    99,   960,   961,   962,     6,   105,   114,   948,
     949,   950,   951,   909,   910,   102,    85,   864,   865,    18,
     859,  1128,  1146,   262,   846,   848,   805,   806,   102,    85,
     760,   761,   755,  1128,   198,   739,   741,    10,    37,   729,
     730,  1101,  1102,    77,    79,    80,   148,  1055,  1056,  1057,
    1058,  1059,  1060,  1013,  1014,   102,    85,   968,   969,   963,
    1128,  1146,   114,   950,   952,    10,    11,   912,   913,   914,
      19,    51,    52,    53,    54,   911,  1093,  1097,  1098,  1099,
    1100,  1102,  1106,  1107,  1108,  1109,  1110,  1118,  1129,  1131,
      87,   871,   872,   866,  1128,  1146,    10,    11,   860,   861,
     862,    10,   849,   850,  1101,  1102,    10,    11,   808,   809,
     810,    55,    56,   807,  1093,  1097,  1102,  1110,  1118,  1122,
    1123,  1124,  1125,  1129,  1142,    87,   767,   768,   762,  1128,
      10,    11,   756,   757,   758,    10,    11,   742,   743,   744,
     745,  1101,  1102,  1144,  1146,     5,  1061,   148,  1057,    10,
      11,  1016,  1017,  1018,    49,    50,  1015,  1089,  1090,  1091,
    1092,  1093,  1097,  1102,  1110,  1118,  1126,  1129,    87,   975,
     976,   970,  1128,    10,    11,   964,   965,   966,    10,   953,
     954,  1101,  1102,   117,   135,   144,   915,   916,   917,   918,
     925,   926,   927,  1146,     3,     3,    83,   878,   879,   873,
    1128,    10,    11,   867,   868,   869,     6,    97,   863,  1177,
    1178,  1185,  1144,   117,   144,   199,   811,   812,   813,   814,
     821,   822,   823,     3,    83,   774,   775,   769,  1128,    10,
      11,   763,   764,   765,   759,  1177,     4,   200,   746,   200,
       6,    78,   105,   117,   144,  1019,  1020,  1021,  1022,  1029,
    1030,  1031,     3,    83,   982,   983,   977,  1128,    10,    11,
     971,   972,   973,   967,  1177,  1144,   144,   917,   919,   926,
     928,   929,     6,  1146,  1146,   129,   885,   886,   880,  1128,
      10,    11,   874,   875,   876,   870,  1177,  1146,    40,  1189,
     100,   115,  1179,  1180,   136,   144,   813,   815,   822,   824,
     825,  1146,   129,   781,   782,   776,  1128,    10,    11,   770,
     771,   772,   766,  1177,   100,   200,  1146,   144,  1021,  1023,
    1030,  1032,  1033,  1146,   129,   989,   990,   984,  1128,    10,
      11,   978,   979,   980,   974,  1177,   100,   106,    10,    11,
     920,   921,   922,   923,  1101,  1102,    10,    11,   931,   932,
     933,   930,  1093,  1118,  1128,  1146,   173,   892,   893,   887,
    1128,    10,    11,   881,   882,   883,   877,  1177,    86,     8,
      10,    11,  1186,  1187,  1188,  1181,  1182,    10,    11,   816,
     817,   818,   819,  1101,  1102,    10,    11,   827,   828,   829,
     826,  1093,  1118,  1128,   173,   788,   789,   783,  1128,    10,
      11,   777,   778,   779,   773,  1177,    86,    10,    11,  1024,
    1025,  1026,  1027,  1101,  1102,    10,    11,  1035,  1036,  1037,
    1034,  1093,  1118,  1128,   173,   996,   997,   991,  1128,    10,
      11,   985,   986,   987,   981,  1177,    86,     4,     6,     7,
     136,   924,  1145,   934,  1177,   187,   899,   900,   894,  1128,
      10,    11,   888,   889,   890,   884,  1177,    88,     6,     4,
      98,    10,  1184,    38,    39,  1183,  1190,  1191,   200,   820,
    1145,   830,  1177,   187,   795,   796,   790,  1128,    10,    11,
     784,   785,   786,   780,  1177,    88,   106,  1028,  1145,  1038,
    1177,   187,  1003,  1004,   998,  1128,    10,    11,   992,   993,
     994,   988,  1177,    88,   136,   118,   901,  1128,    10,    11,
     895,   896,   897,   891,  1177,    84,     8,    98,     6,     8,
       8,   200,   118,   797,  1128,    10,    11,   791,   792,   793,
     787,  1177,    84,   106,   118,  1005,  1128,    10,    11,   999,
    1000,  1001,   995,  1177,    84,    10,    11,   902,   903,   904,
     898,  1177,   130,   116,     6,     6,    10,    11,   798,   799,
     800,   794,  1177,   130,    10,    11,  1006,  1007,  1008,  1002,
    1177,   130,   905,  1177,   174,     8,     8,   801,  1177,   174,
    1009,  1177,   174,   188,   188,   188
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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
    if (parserData->numberOf > 0)
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

  case 1149:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 1154:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1155:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 1160:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1161:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 1166:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1167:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 1172:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1173:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 1178:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1179:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1184:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 1190:

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

  case 1196:

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

  case 1197:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1198:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1199:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mult must be positive");
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


