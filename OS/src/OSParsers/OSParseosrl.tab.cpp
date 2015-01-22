
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
     MATRIXVARSTART = 460,
     MATRIXVAREND = 461,
     MATRIXOBJSTART = 462,
     MATRIXOBJEND = 463,
     MATRIXCONSTART = 464,
     MATRIXCONEND = 465,
     FILENAMESTART = 466,
     FILENAMEEND = 467,
     FILENAMEEMPTY = 468,
     FILENAMESTARTANDEND = 469,
     FILESOURCESTART = 470,
     FILESOURCEEND = 471,
     FILESOURCEEMPTY = 472,
     FILESOURCESTARTANDEND = 473,
     FILEDESCRIPTIONSTART = 474,
     FILEDESCRIPTIONEND = 475,
     FILEDESCRIPTIONEMPTY = 476,
     FILEDESCRIPTIONSTARTANDEND = 477,
     FILECREATORSTART = 478,
     FILECREATOREND = 479,
     FILECREATOREMPTY = 480,
     FILECREATORSTARTANDEND = 481,
     FILELICENCESTART = 482,
     FILELICENCEEND = 483,
     FILELICENCEEMPTY = 484,
     FILELICENCESTARTANDEND = 485,
     MATRIXSTART = 486,
     MATRIXEND = 487,
     BASEMATRIXEND = 488,
     BASEMATRIXSTART = 489,
     BLOCKSTART = 490,
     BLOCKEND = 491,
     BLOCKSSTART = 492,
     BLOCKSEND = 493,
     EMPTYSHAPEATT = 494,
     SHAPEATT = 495,
     EMPTYSYMMETRYATT = 496,
     SYMMETRYATT = 497,
     EMPTYNEGATIVEPATTERNATT = 498,
     NEGATIVEPATTERNATT = 499,
     CONSTANTATT = 500,
     NUMBEROFBLOCKSATT = 501,
     NUMBEROFCOLUMNSATT = 502,
     NUMBEROFROWSATT = 503,
     NUMBEROFVALUESATT = 504,
     COEFATT = 505,
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
     CONSTANTELEMENTSSTART = 518,
     CONSTANTELEMENTSEND = 519,
     STARTVECTORSTART = 520,
     STARTVECTOREND = 521,
     NONZEROSSTART = 522,
     NONZEROSEND = 523,
     INDEXESSTART = 524,
     INDEXESEND = 525,
     VALUESSTART = 526,
     VALUESEND = 527,
     VARREFERENCEELEMENTSSTART = 528,
     VARREFERENCEELEMENTSEND = 529,
     LINEARELEMENTSSTART = 530,
     LINEARELEMENTSEND = 531,
     GENERALELEMENTSSTART = 532,
     GENERALELEMENTSEND = 533,
     CONREFERENCEELEMENTSSTART = 534,
     CONREFERENCEELEMENTSEND = 535,
     OBJREFERENCEELEMENTSSTART = 536,
     OBJREFERENCEELEMENTSEND = 537,
     PATTERNELEMENTSSTART = 538,
     PATTERNELEMENTSEND = 539,
     TRANSFORMATIONSTART = 540,
     TRANSFORMATIONEND = 541,
     COLOFFSETSSTART = 542,
     COLOFFSETSEND = 543,
     ROWOFFSETSSTART = 544,
     ROWOFFSETSEND = 545,
     EMPTYROWMAJORATT = 546,
     ROWMAJORATT = 547,
     BLOCKROWIDXATT = 548,
     BLOCKCOLIDXATT = 549,
     DUMMY = 550,
     NONLINEAREXPRESSIONSSTART = 551,
     NONLINEAREXPRESSIONSEND = 552,
     NUMBEROFNONLINEAREXPRESSIONS = 553,
     NLSTART = 554,
     NLEND = 555,
     MATRIXEXPRESSIONSSTART = 556,
     MATRIXEXPRESSIONSEND = 557,
     NUMBEROFEXPR = 558,
     EXPRSTART = 559,
     EXPREND = 560,
     NUMBEROFMATRIXTERMSATT = 561,
     MATRIXTERMSTART = 562,
     MATRIXTERMEND = 563,
     POWERSTART = 564,
     POWEREND = 565,
     PLUSSTART = 566,
     PLUSEND = 567,
     MINUSSTART = 568,
     MINUSEND = 569,
     DIVIDESTART = 570,
     DIVIDEEND = 571,
     LNSTART = 572,
     LNEND = 573,
     SQRTSTART = 574,
     SQRTEND = 575,
     SUMSTART = 576,
     SUMEND = 577,
     PRODUCTSTART = 578,
     PRODUCTEND = 579,
     EXPSTART = 580,
     EXPEND = 581,
     NEGATESTART = 582,
     NEGATEEND = 583,
     IFSTART = 584,
     IFEND = 585,
     SQUARESTART = 586,
     SQUAREEND = 587,
     COSSTART = 588,
     COSEND = 589,
     SINSTART = 590,
     SINEND = 591,
     VARIABLESTART = 592,
     VARIABLEEND = 593,
     ABSSTART = 594,
     ABSEND = 595,
     ERFSTART = 596,
     ERFEND = 597,
     MAXSTART = 598,
     MAXEND = 599,
     ALLDIFFSTART = 600,
     ALLDIFFEND = 601,
     MINSTART = 602,
     MINEND = 603,
     ESTART = 604,
     EEND = 605,
     PISTART = 606,
     PIEND = 607,
     TIMESSTART = 608,
     TIMESEND = 609,
     NUMBERSTART = 610,
     NUMBEREND = 611,
     MATRIXDETERMINANTSTART = 612,
     MATRIXDETERMINANTEND = 613,
     MATRIXTRACESTART = 614,
     MATRIXTRACEEND = 615,
     MATRIXTOSCALARSTART = 616,
     MATRIXTOSCALAREND = 617,
     MATRIXDIAGONALSTART = 618,
     MATRIXDIAGONALEND = 619,
     MATRIXDOTTIMESSTART = 620,
     MATRIXDOTTIMESEND = 621,
     MATRIXLOWERTRIANGLESTART = 622,
     MATRIXLOWERTRIANGLEEND = 623,
     MATRIXUPPERTRIANGLESTART = 624,
     MATRIXUPPERTRIANGLEEND = 625,
     MATRIXMERGESTART = 626,
     MATRIXMERGEEND = 627,
     MATRIXMINUSSTART = 628,
     MATRIXMINUSEND = 629,
     MATRIXNEGATESTART = 630,
     MATRIXNEGATEEND = 631,
     MATRIXPLUSSTART = 632,
     MATRIXPLUSEND = 633,
     MATRIXTIMESSTART = 634,
     MATRIXTIMESEND = 635,
     MATRIXPRODUCTSTART = 636,
     MATRIXPRODUCTEND = 637,
     MATRIXSCALARTIMESSTART = 638,
     MATRIXSCALARTIMESEND = 639,
     MATRIXSUBMATRIXATSTART = 640,
     MATRIXSUBMATRIXATEND = 641,
     MATRIXTRANSPOSESTART = 642,
     MATRIXTRANSPOSEEND = 643,
     MATRIXREFERENCESTART = 644,
     MATRIXREFERENCEEND = 645,
     IDENTITYMATRIXSTART = 646,
     IDENTITYMATRIXEND = 647,
     MATRIXINVERSESTART = 648,
     MATRIXINVERSEEND = 649,
     EMPTYINCLUDEDIAGONALATT = 650,
     INCLUDEDIAGONALATT = 651,
     IDATT = 652
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
#define MATRIXVARSTART 460
#define MATRIXVAREND 461
#define MATRIXOBJSTART 462
#define MATRIXOBJEND 463
#define MATRIXCONSTART 464
#define MATRIXCONEND 465
#define FILENAMESTART 466
#define FILENAMEEND 467
#define FILENAMEEMPTY 468
#define FILENAMESTARTANDEND 469
#define FILESOURCESTART 470
#define FILESOURCEEND 471
#define FILESOURCEEMPTY 472
#define FILESOURCESTARTANDEND 473
#define FILEDESCRIPTIONSTART 474
#define FILEDESCRIPTIONEND 475
#define FILEDESCRIPTIONEMPTY 476
#define FILEDESCRIPTIONSTARTANDEND 477
#define FILECREATORSTART 478
#define FILECREATOREND 479
#define FILECREATOREMPTY 480
#define FILECREATORSTARTANDEND 481
#define FILELICENCESTART 482
#define FILELICENCEEND 483
#define FILELICENCEEMPTY 484
#define FILELICENCESTARTANDEND 485
#define MATRIXSTART 486
#define MATRIXEND 487
#define BASEMATRIXEND 488
#define BASEMATRIXSTART 489
#define BLOCKSTART 490
#define BLOCKEND 491
#define BLOCKSSTART 492
#define BLOCKSEND 493
#define EMPTYSHAPEATT 494
#define SHAPEATT 495
#define EMPTYSYMMETRYATT 496
#define SYMMETRYATT 497
#define EMPTYNEGATIVEPATTERNATT 498
#define NEGATIVEPATTERNATT 499
#define CONSTANTATT 500
#define NUMBEROFBLOCKSATT 501
#define NUMBEROFCOLUMNSATT 502
#define NUMBEROFROWSATT 503
#define NUMBEROFVALUESATT 504
#define COEFATT 505
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
#define CONSTANTELEMENTSSTART 518
#define CONSTANTELEMENTSEND 519
#define STARTVECTORSTART 520
#define STARTVECTOREND 521
#define NONZEROSSTART 522
#define NONZEROSEND 523
#define INDEXESSTART 524
#define INDEXESEND 525
#define VALUESSTART 526
#define VALUESEND 527
#define VARREFERENCEELEMENTSSTART 528
#define VARREFERENCEELEMENTSEND 529
#define LINEARELEMENTSSTART 530
#define LINEARELEMENTSEND 531
#define GENERALELEMENTSSTART 532
#define GENERALELEMENTSEND 533
#define CONREFERENCEELEMENTSSTART 534
#define CONREFERENCEELEMENTSEND 535
#define OBJREFERENCEELEMENTSSTART 536
#define OBJREFERENCEELEMENTSEND 537
#define PATTERNELEMENTSSTART 538
#define PATTERNELEMENTSEND 539
#define TRANSFORMATIONSTART 540
#define TRANSFORMATIONEND 541
#define COLOFFSETSSTART 542
#define COLOFFSETSEND 543
#define ROWOFFSETSSTART 544
#define ROWOFFSETSEND 545
#define EMPTYROWMAJORATT 546
#define ROWMAJORATT 547
#define BLOCKROWIDXATT 548
#define BLOCKCOLIDXATT 549
#define DUMMY 550
#define NONLINEAREXPRESSIONSSTART 551
#define NONLINEAREXPRESSIONSEND 552
#define NUMBEROFNONLINEAREXPRESSIONS 553
#define NLSTART 554
#define NLEND 555
#define MATRIXEXPRESSIONSSTART 556
#define MATRIXEXPRESSIONSEND 557
#define NUMBEROFEXPR 558
#define EXPRSTART 559
#define EXPREND 560
#define NUMBEROFMATRIXTERMSATT 561
#define MATRIXTERMSTART 562
#define MATRIXTERMEND 563
#define POWERSTART 564
#define POWEREND 565
#define PLUSSTART 566
#define PLUSEND 567
#define MINUSSTART 568
#define MINUSEND 569
#define DIVIDESTART 570
#define DIVIDEEND 571
#define LNSTART 572
#define LNEND 573
#define SQRTSTART 574
#define SQRTEND 575
#define SUMSTART 576
#define SUMEND 577
#define PRODUCTSTART 578
#define PRODUCTEND 579
#define EXPSTART 580
#define EXPEND 581
#define NEGATESTART 582
#define NEGATEEND 583
#define IFSTART 584
#define IFEND 585
#define SQUARESTART 586
#define SQUAREEND 587
#define COSSTART 588
#define COSEND 589
#define SINSTART 590
#define SINEND 591
#define VARIABLESTART 592
#define VARIABLEEND 593
#define ABSSTART 594
#define ABSEND 595
#define ERFSTART 596
#define ERFEND 597
#define MAXSTART 598
#define MAXEND 599
#define ALLDIFFSTART 600
#define ALLDIFFEND 601
#define MINSTART 602
#define MINEND 603
#define ESTART 604
#define EEND 605
#define PISTART 606
#define PIEND 607
#define TIMESSTART 608
#define TIMESEND 609
#define NUMBERSTART 610
#define NUMBEREND 611
#define MATRIXDETERMINANTSTART 612
#define MATRIXDETERMINANTEND 613
#define MATRIXTRACESTART 614
#define MATRIXTRACEEND 615
#define MATRIXTOSCALARSTART 616
#define MATRIXTOSCALAREND 617
#define MATRIXDIAGONALSTART 618
#define MATRIXDIAGONALEND 619
#define MATRIXDOTTIMESSTART 620
#define MATRIXDOTTIMESEND 621
#define MATRIXLOWERTRIANGLESTART 622
#define MATRIXLOWERTRIANGLEEND 623
#define MATRIXUPPERTRIANGLESTART 624
#define MATRIXUPPERTRIANGLEEND 625
#define MATRIXMERGESTART 626
#define MATRIXMERGEEND 627
#define MATRIXMINUSSTART 628
#define MATRIXMINUSEND 629
#define MATRIXNEGATESTART 630
#define MATRIXNEGATEEND 631
#define MATRIXPLUSSTART 632
#define MATRIXPLUSEND 633
#define MATRIXTIMESSTART 634
#define MATRIXTIMESEND 635
#define MATRIXPRODUCTSTART 636
#define MATRIXPRODUCTEND 637
#define MATRIXSCALARTIMESSTART 638
#define MATRIXSCALARTIMESEND 639
#define MATRIXSUBMATRIXATSTART 640
#define MATRIXSUBMATRIXATEND 641
#define MATRIXTRANSPOSESTART 642
#define MATRIXTRANSPOSEEND 643
#define MATRIXREFERENCESTART 644
#define MATRIXREFERENCEEND 645
#define IDENTITYMATRIXSTART 646
#define IDENTITYMATRIXEND 647
#define MATRIXINVERSESTART 648
#define MATRIXINVERSEEND 649
#define EMPTYINCLUDEDIAGONALATT 650
#define INCLUDEDIAGONALATT 651
#define IDATT 652




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
#define YYNTOKENS  402
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  815
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1199
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1626

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   652

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   399,
     401,     2,     2,   400,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   398,     2,     2,     2,     2,     2,     2,     2,
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397
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
     403,     0,    -1,   404,   412,   410,    -1,   405,   406,   407,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   408,    -1,
     409,    -1,    11,    -1,    10,   412,   410,    -1,   411,    -1,
      15,    -1,    -1,   413,   414,   494,   548,   600,   695,    -1,
      -1,  1174,    -1,    -1,   415,   416,    -1,    67,    -1,   417,
      -1,   418,    -1,    10,    68,    -1,    11,    -1,    10,   419,
      68,    -1,   420,    -1,   421,    -1,   420,   421,    -1,   422,
      -1,   438,    -1,   444,    -1,   450,    -1,   456,    -1,   462,
      -1,   468,    -1,   474,    -1,   480,    -1,   423,   424,   427,
      -1,   121,    -1,   425,    -1,   426,    -1,   425,   426,    -1,
    1135,    -1,  1118,    -1,  1165,    -1,   428,    -1,   429,    -1,
      10,   122,    -1,    11,    -1,    10,   430,   122,    -1,   431,
      -1,   432,    -1,   431,   432,    -1,   433,   434,   437,    -1,
     171,    -1,   435,    -1,    -1,   435,   436,    -1,  1127,    -1,
    1118,    -1,    10,   172,    -1,    11,    -1,   439,   440,    -1,
     133,    -1,   441,    -1,   442,    -1,    10,   134,    -1,    11,
      -1,    10,   443,   134,    -1,     4,    -1,   445,   446,    -1,
     157,    -1,   447,    -1,   448,    -1,    10,   158,    -1,    11,
      -1,    10,   449,   158,    -1,     4,    -1,   451,   452,    -1,
     155,    -1,   453,    -1,   454,    -1,    10,   156,    -1,    11,
      -1,    10,   455,   156,    -1,     4,    -1,   457,   458,    -1,
     127,    -1,   459,    -1,   460,    -1,    10,   128,    -1,    11,
      -1,    10,   461,   128,    -1,     4,    -1,   463,   464,    -1,
     131,    -1,   465,    -1,   466,    -1,    10,   132,    -1,    11,
      -1,    10,   467,   132,    -1,     4,    -1,   469,   470,    -1,
     163,    -1,   471,    -1,   472,    -1,    10,   164,    -1,    11,
      -1,    10,   473,   164,    -1,     4,    -1,   475,   476,    -1,
     181,    -1,   477,    -1,   478,    -1,    10,   182,    -1,    11,
      -1,    10,   479,   182,    -1,     4,    -1,   481,   482,   483,
      -1,   145,    -1,  1160,    -1,   484,    -1,   485,    -1,    10,
     146,    -1,    11,    -1,    10,   486,   146,    -1,   487,    -1,
     488,    -1,   487,   488,    -1,   489,   490,   493,    -1,   143,
      -1,   491,    -1,    -1,   491,   492,    -1,  1127,    -1,  1143,
      -1,  1118,    -1,    10,   144,    -1,    11,    -1,    -1,   495,
     496,    -1,    69,    -1,   497,    -1,   498,    -1,    10,    70,
      -1,    11,    -1,    10,   499,    70,    -1,   500,    -1,   501,
      -1,   500,   501,    -1,   502,    -1,   508,    -1,   515,    -1,
     522,    -1,   529,    -1,   534,    -1,   503,   504,    -1,   175,
      -1,   505,    -1,   506,    -1,    10,   176,    -1,    11,    -1,
      10,   507,   176,    -1,     4,    -1,   509,   510,   513,    -1,
      93,    -1,   511,    -1,    -1,   511,   512,    -1,  1139,    -1,
    1118,    -1,    10,   514,    94,    -1,  1169,    -1,   516,   517,
     520,    -1,    95,    -1,   518,    -1,    -1,   518,   519,    -1,
    1139,    -1,  1118,    -1,    10,   521,    96,    -1,  1169,    -1,
     523,   524,   527,    -1,    91,    -1,   525,    -1,    -1,   525,
     526,    -1,  1139,    -1,  1118,    -1,    10,   528,    92,    -1,
    1169,    -1,   530,   531,   532,    -1,    89,    -1,    -1,  1118,
      -1,    10,   533,    90,    -1,     6,    -1,   535,   536,   537,
      -1,   145,    -1,  1160,    -1,   538,    -1,   539,    -1,    10,
     146,    -1,    11,    -1,    10,   540,   146,    -1,   541,    -1,
     542,    -1,   541,   542,    -1,   543,   544,   547,    -1,   143,
      -1,   545,    -1,    -1,   545,   546,    -1,  1127,    -1,  1143,
      -1,  1118,    -1,    10,   144,    -1,    11,    -1,    -1,   549,
     550,    -1,    71,    -1,   551,    -1,   552,    -1,    10,    72,
      -1,    11,    -1,    10,   553,    72,    -1,   554,    -1,   555,
      -1,   554,   555,    -1,   556,    -1,   562,    -1,   568,    -1,
     574,    -1,   580,    -1,   586,    -1,   557,   558,    -1,   111,
      -1,   559,    -1,   560,    -1,    10,   112,    -1,    11,    -1,
      10,   561,   112,    -1,     4,    -1,   563,   564,    -1,   109,
      -1,   565,    -1,   566,    -1,    10,   110,    -1,    11,    -1,
      10,   567,   110,    -1,     6,    -1,   569,   570,    -1,   185,
      -1,   571,    -1,   572,    -1,    10,   186,    -1,    11,    -1,
      10,   573,   186,    -1,     6,    -1,   575,   576,    -1,   179,
      -1,   577,    -1,   578,    -1,    10,   180,    -1,    11,    -1,
      10,   579,   180,    -1,     4,    -1,   581,   582,    -1,   159,
      -1,   583,    -1,   584,    -1,    10,   160,    -1,    11,    -1,
      10,   585,   160,    -1,  1169,    -1,   587,   588,   589,    -1,
     145,    -1,  1160,    -1,   590,    -1,   591,    -1,    10,   146,
      -1,    11,    -1,    10,   592,   146,    -1,   593,    -1,   594,
      -1,   593,   594,    -1,   595,   596,   599,    -1,   143,    -1,
     597,    -1,    -1,   597,   598,    -1,  1127,    -1,  1143,    -1,
    1118,    -1,    10,   144,    -1,    11,    -1,    -1,   601,   602,
      -1,    73,    -1,   603,    -1,   604,    -1,    10,    74,    -1,
      11,    -1,    10,   605,    74,    -1,   606,    -1,   607,    -1,
     606,   607,    -1,   608,    -1,   614,    -1,   620,    -1,   626,
      -1,   632,    -1,   638,    -1,   655,    -1,   662,    -1,   669,
      -1,   676,    -1,   681,    -1,   609,   610,    -1,   167,    -1,
     611,    -1,   612,    -1,    10,   168,    -1,    11,    -1,    10,
     613,   168,    -1,     4,    -1,   615,   616,    -1,   169,    -1,
     617,    -1,   618,    -1,    10,   170,    -1,    11,    -1,    10,
     619,   170,    -1,     4,    -1,   621,   622,    -1,   153,    -1,
     623,    -1,   624,    -1,    10,   154,    -1,    11,    -1,    10,
     625,   154,    -1,     4,    -1,   627,   628,    -1,    81,    -1,
     629,    -1,   630,    -1,    10,    82,    -1,    11,    -1,    10,
     631,    82,    -1,     4,    -1,   633,   634,    -1,   119,    -1,
     635,    -1,   636,    -1,    10,   120,    -1,    11,    -1,    10,
     637,   120,    -1,     4,    -1,   639,   640,   641,    -1,   183,
      -1,  1166,    -1,   642,    -1,   643,    -1,    10,   184,    -1,
      11,    -1,    10,   644,   184,    -1,   645,    -1,   646,    -1,
     645,   646,    -1,   647,   648,   650,    -1,   177,    -1,    -1,
     648,   649,    -1,  1139,    -1,  1135,    -1,  1110,    -1,  1118,
      -1,   651,    -1,   652,    -1,    10,   178,    -1,    11,    -1,
      10,   653,   178,    -1,   654,    -1,     7,    -1,     6,    -1,
     656,   657,   660,    -1,   193,    -1,   658,    -1,    -1,   658,
     659,    -1,  1139,    -1,  1118,    -1,    10,   661,   194,    -1,
    1169,    -1,   663,   664,   667,    -1,   195,    -1,   665,    -1,
      -1,   665,   666,    -1,  1139,    -1,  1118,    -1,    10,   668,
     196,    -1,  1169,    -1,   670,   671,   674,    -1,   191,    -1,
     672,    -1,    -1,   672,   673,    -1,  1139,    -1,  1118,    -1,
      10,   675,   192,    -1,  1169,    -1,   677,   678,   679,    -1,
     189,    -1,    -1,  1118,    -1,    10,   680,   190,    -1,     6,
      -1,   682,   683,   684,    -1,   145,    -1,  1160,    -1,   685,
      -1,   686,    -1,    10,   146,    -1,    11,    -1,    10,   687,
     146,    -1,   688,    -1,   689,    -1,   688,   689,    -1,   690,
     691,   694,    -1,   143,    -1,   692,    -1,    -1,   692,   693,
      -1,  1127,    -1,  1143,    -1,  1118,    -1,    10,   144,    -1,
      11,    -1,    -1,   696,   697,   700,    -1,    75,    -1,   698,
      -1,    -1,   698,   699,    -1,  1163,    -1,  1168,    -1,  1152,
      -1,  1157,    -1,   701,    -1,   702,    -1,    10,    76,    -1,
      11,    -1,    10,   703,    76,    -1,   704,  1087,    -1,   705,
      -1,   704,   705,    -1,   706,   707,   713,    -1,   161,    -1,
     708,    -1,    -1,   708,   709,    -1,   710,    -1,   711,    -1,
     712,    -1,    36,  1171,     6,  1171,    -1,    63,     3,  1171,
      -1,    61,     3,  1171,    -1,    10,   714,   730,   736,   856,
     960,  1064,   162,    -1,   715,   716,   719,    -1,   167,    -1,
     717,    -1,   718,    -1,   717,   718,    -1,  1135,    -1,  1118,
      -1,  1165,    -1,   720,    -1,   721,    -1,    10,   168,    -1,
      11,    -1,    10,   722,   168,    -1,   723,    -1,   724,    -1,
     723,   724,    -1,   725,   726,   729,    -1,   171,    -1,   727,
      -1,    -1,   727,   728,    -1,  1135,    -1,  1118,    -1,    10,
     172,    -1,    11,    -1,    -1,   731,   732,    -1,   133,    -1,
     733,    -1,   734,    -1,    10,   134,    -1,    11,    -1,    10,
     735,   134,    -1,     4,    -1,    -1,   737,   738,   739,    -1,
     201,    -1,    -1,  1162,    -1,   740,    -1,   741,    -1,    11,
      -1,    10,   742,   202,    -1,   743,   756,   772,   827,    -1,
      -1,   744,   745,   746,    -1,   271,    -1,  1167,    -1,   747,
      -1,   748,    -1,    10,   272,    -1,    11,    -1,    10,   749,
     272,    -1,   750,    -1,   751,    -1,   750,   751,    -1,   752,
     753,   755,    -1,   199,    -1,    -1,   753,   754,    -1,  1126,
      -1,  1127,    -1,    10,  1169,   200,    -1,    -1,   757,   758,
     759,    -1,   197,    -1,  1167,    -1,   760,    -1,   761,    -1,
      10,   198,    -1,    11,    -1,    10,   762,   198,    -1,   763,
      -1,   764,    -1,   763,   764,    -1,   765,   766,   768,    -1,
     199,    -1,    -1,   766,   767,    -1,  1126,    -1,  1127,    -1,
     769,    -1,   770,    -1,    10,   200,    -1,    11,    -1,    10,
     771,   200,    -1,     4,    -1,    -1,   773,   774,    -1,   101,
      -1,   775,    -1,   776,    -1,    11,    -1,    10,   777,   102,
      -1,   778,   785,   792,   799,   806,   813,   820,    -1,    -1,
     779,   780,   781,    -1,    99,    -1,  1153,    -1,   782,    -1,
     783,    -1,    11,    -1,    10,   784,   100,    -1,  1202,    -1,
      -1,   786,   787,   788,    -1,    85,    -1,  1153,    -1,   789,
      -1,   790,    -1,    11,    -1,    10,   791,    86,    -1,  1202,
      -1,    -1,   793,   794,   795,    -1,    87,    -1,  1153,    -1,
     796,    -1,   797,    -1,    11,    -1,    10,   798,    88,    -1,
    1202,    -1,    -1,   800,   801,   802,    -1,    83,    -1,  1153,
      -1,   803,    -1,   804,    -1,    11,    -1,    10,   805,    84,
      -1,  1202,    -1,    -1,   807,   808,   809,    -1,   129,    -1,
    1153,    -1,   810,    -1,   811,    -1,    11,    -1,    10,   812,
     130,    -1,  1202,    -1,    -1,   814,   815,   816,    -1,   173,
      -1,  1153,    -1,   817,    -1,   818,    -1,    11,    -1,    10,
     819,   174,    -1,  1202,    -1,    -1,   821,   822,   823,    -1,
     187,    -1,  1153,    -1,   824,    -1,   825,    -1,    11,    -1,
      10,   826,   188,    -1,  1202,    -1,    -1,   827,   828,    -1,
     829,   830,   833,    -1,   143,    -1,   831,    -1,    -1,   831,
     832,    -1,  1167,    -1,  1154,    -1,  1143,    -1,  1127,    -1,
    1135,    -1,  1147,    -1,  1122,    -1,  1118,    -1,   834,    -1,
     835,    -1,    10,   144,    -1,    11,    -1,    10,   836,   144,
      -1,   837,    -1,   846,    -1,   838,    -1,   837,   838,    -1,
     839,   840,   842,    -1,   199,    -1,    -1,   840,   841,    -1,
    1126,    -1,  1127,    -1,   843,    -1,   844,    -1,    10,   200,
      -1,    11,    -1,    10,   845,   200,    -1,  1170,    -1,   847,
      -1,   846,   847,    -1,   848,   849,   852,    -1,   117,    -1,
     850,    -1,    -1,   850,   851,    -1,  1153,    -1,  1143,    -1,
    1118,    -1,   853,    -1,   854,    -1,    11,    -1,    10,   855,
     118,    -1,  1202,    -1,    -1,   857,   858,   859,    -1,   137,
      -1,    -1,  1159,    -1,   860,    -1,   861,    -1,    11,    -1,
      10,   862,   138,    -1,   863,   876,   931,    -1,    -1,   864,
     865,   866,    -1,   271,    -1,  1156,    -1,   867,    -1,   868,
      -1,    10,   272,    -1,    11,    -1,    10,   869,   272,    -1,
     870,    -1,   871,    -1,   870,   871,    -1,   872,   873,   875,
      -1,   135,    -1,    -1,   873,   874,    -1,  1126,    -1,  1127,
      -1,    10,  1169,   136,    -1,    -1,   877,   878,    -1,   101,
      -1,   879,    -1,   880,    -1,    11,    -1,    10,   881,   102,
      -1,   882,   889,   896,   903,   910,   917,   924,    -1,    -1,
     883,   884,   885,    -1,    99,    -1,  1153,    -1,   886,    -1,
     887,    -1,    11,    -1,    10,   888,   100,    -1,  1202,    -1,
      -1,   890,   891,   892,    -1,    85,    -1,  1153,    -1,   893,
      -1,   894,    -1,    11,    -1,    10,   895,    86,    -1,  1202,
      -1,    -1,   897,   898,   899,    -1,    87,    -1,  1153,    -1,
     900,    -1,   901,    -1,    11,    -1,    10,   902,    88,    -1,
    1202,    -1,    -1,   904,   905,   906,    -1,    83,    -1,  1153,
      -1,   907,    -1,   908,    -1,    11,    -1,    10,   909,    84,
      -1,  1202,    -1,    -1,   911,   912,   913,    -1,   129,    -1,
    1153,    -1,   914,    -1,   915,    -1,    11,    -1,    10,   916,
     130,    -1,  1202,    -1,    -1,   918,   919,   920,    -1,   173,
      -1,  1153,    -1,   921,    -1,   922,    -1,    11,    -1,    10,
     923,   174,    -1,  1202,    -1,    -1,   925,   926,   927,    -1,
     187,    -1,  1153,    -1,   928,    -1,   929,    -1,    11,    -1,
      10,   930,   188,    -1,  1202,    -1,    -1,   931,   932,    -1,
     933,   934,   937,    -1,   143,    -1,   935,    -1,    -1,   935,
     936,    -1,  1156,    -1,  1154,    -1,  1143,    -1,  1127,    -1,
    1135,    -1,  1131,    -1,  1122,    -1,  1118,    -1,   938,    -1,
     939,    -1,    10,   144,    -1,    11,    -1,    10,   940,   144,
      -1,   941,    -1,   950,    -1,   942,    -1,   941,   942,    -1,
     943,   944,   946,    -1,   135,    -1,    -1,   944,   945,    -1,
    1126,    -1,  1127,    -1,   947,    -1,   948,    -1,    10,   136,
      -1,    11,    -1,    10,   949,   136,    -1,  1170,    -1,   951,
      -1,   950,   951,    -1,   952,   953,   956,    -1,   117,    -1,
     954,    -1,    -1,   954,   955,    -1,  1153,    -1,  1143,    -1,
    1118,    -1,   957,    -1,   958,    -1,    11,    -1,    10,   959,
     118,    -1,  1202,    -1,    -1,   961,   962,   963,    -1,   107,
      -1,    -1,  1158,    -1,   964,    -1,   965,    -1,    11,    -1,
      10,   966,   108,    -1,   967,   980,  1035,    -1,    -1,   968,
     969,   970,    -1,   113,    -1,  1151,    -1,   971,    -1,   972,
      -1,    10,   114,    -1,    11,    -1,    10,   973,   114,    -1,
     974,    -1,   975,    -1,   974,   975,    -1,   976,   977,   979,
      -1,   105,    -1,    -1,   977,   978,    -1,  1126,    -1,  1127,
      -1,    10,  1169,   106,    -1,    -1,   981,   982,    -1,   101,
      -1,   983,    -1,   984,    -1,    11,    -1,    10,   985,   102,
      -1,   986,   993,  1000,  1007,  1014,  1021,  1028,    -1,    -1,
     987,   988,   989,    -1,    99,    -1,  1153,    -1,   990,    -1,
     991,    -1,    11,    -1,    10,   992,   100,    -1,  1202,    -1,
      -1,   994,   995,   996,    -1,    85,    -1,  1153,    -1,   997,
      -1,   998,    -1,    11,    -1,    10,   999,    86,    -1,  1202,
      -1,    -1,  1001,  1002,  1003,    -1,    87,    -1,  1153,    -1,
    1004,    -1,  1005,    -1,    11,    -1,    10,  1006,    88,    -1,
    1202,    -1,    -1,  1008,  1009,  1010,    -1,    83,    -1,  1153,
      -1,  1011,    -1,  1012,    -1,    11,    -1,    10,  1013,    84,
      -1,  1202,    -1,    -1,  1015,  1016,  1017,    -1,   129,    -1,
    1153,    -1,  1018,    -1,  1019,    -1,    11,    -1,    10,  1020,
     130,    -1,  1202,    -1,    -1,  1022,  1023,  1024,    -1,   173,
      -1,  1153,    -1,  1025,    -1,  1026,    -1,    11,    -1,    10,
    1027,   174,    -1,  1202,    -1,    -1,  1029,  1030,  1031,    -1,
     187,    -1,  1153,    -1,  1032,    -1,  1033,    -1,    11,    -1,
      10,  1034,   188,    -1,  1202,    -1,    -1,  1035,  1036,    -1,
    1037,  1038,  1041,    -1,   143,    -1,  1039,    -1,    -1,  1039,
    1040,    -1,  1151,    -1,  1154,    -1,  1143,    -1,  1127,    -1,
    1135,    -1,  1114,    -1,  1122,    -1,  1118,    -1,  1042,    -1,
    1043,    -1,    10,   144,    -1,    11,    -1,    10,  1044,   144,
      -1,  1045,    -1,  1054,    -1,  1046,    -1,  1045,  1046,    -1,
    1047,  1048,  1050,    -1,   105,    -1,    -1,  1048,  1049,    -1,
    1126,    -1,  1127,    -1,  1051,    -1,  1052,    -1,    10,   106,
      -1,    11,    -1,    10,  1053,   106,    -1,  1170,    -1,  1055,
      -1,  1054,  1055,    -1,  1056,  1057,  1060,    -1,   117,    -1,
    1058,    -1,    -1,  1058,  1059,    -1,  1153,    -1,  1143,    -1,
    1118,    -1,  1061,    -1,  1062,    -1,    11,    -1,    10,  1063,
     118,    -1,  1202,    -1,    -1,  1065,  1066,  1067,    -1,   149,
      -1,  1161,    -1,  1068,    -1,  1069,    -1,    10,   150,    -1,
      11,    -1,    10,  1070,   150,    -1,  1071,    -1,  1072,    -1,
    1071,  1072,    -1,  1073,  1074,  1077,    -1,   147,    -1,  1075,
      -1,    -1,  1075,  1076,    -1,  1127,    -1,  1143,    -1,  1110,
      -1,  1118,    -1,  1155,    -1,  1078,    -1,  1079,    -1,    10,
     148,    -1,    11,    -1,    10,  1080,   148,    -1,  1081,    -1,
    1082,    -1,  1081,  1082,    -1,  1083,    -1,  1084,    -1,  1085,
      -1,    79,    -1,    80,    -1,    77,  1086,    78,    -1,     5,
      -1,    -1,  1088,  1089,  1090,    -1,   151,    -1,  1164,    -1,
    1091,    -1,  1092,    -1,    10,   152,    -1,    11,    -1,    10,
    1093,   152,    -1,  1094,    -1,  1095,    -1,  1094,  1095,    -1,
    1096,  1097,  1100,    -1,   165,    -1,  1098,    -1,    -1,  1098,
    1099,    -1,  1127,    -1,  1110,    -1,  1118,    -1,  1155,    -1,
    1101,    -1,  1102,    -1,    10,   166,    -1,    11,    -1,    10,
    1103,   166,    -1,  1104,    -1,  1105,    -1,  1104,  1105,    -1,
    1106,    -1,  1107,    -1,  1108,    -1,    79,    -1,    80,    -1,
      77,  1109,    78,    -1,     5,    -1,  1111,    -1,  1112,    -1,
    1113,    -1,    42,    -1,    41,     3,  1171,    -1,  1115,    -1,
    1116,    -1,  1117,    -1,    50,    -1,    49,     3,  1171,    -1,
    1119,    -1,  1120,    -1,  1121,    -1,    44,    -1,    43,     3,
    1171,    -1,  1123,    -1,  1124,    -1,  1125,    -1,    52,    -1,
      51,     3,  1171,    -1,    37,  1171,     6,  1171,    -1,  1128,
      -1,  1129,    -1,  1130,    -1,    46,    -1,    45,     3,  1171,
      -1,  1132,    -1,  1133,    -1,  1134,    -1,    54,    -1,    53,
       3,  1171,    -1,  1136,    -1,  1137,    -1,  1138,    -1,    48,
      -1,    47,     3,  1171,    -1,  1140,    -1,  1141,    -1,  1142,
      -1,    58,    -1,    57,     3,  1171,    -1,  1144,    -1,  1145,
      -1,  1146,    -1,    60,    -1,    59,     3,  1171,    -1,  1148,
      -1,  1149,    -1,  1150,    -1,    56,    -1,    55,     3,  1171,
      -1,    16,  1171,     6,  1171,    -1,    17,  1171,     6,  1171,
      -1,    18,  1171,     6,  1171,    -1,    19,  1171,     6,  1171,
      -1,    21,  1171,     6,  1171,    -1,    22,  1171,     6,  1171,
      -1,    23,  1171,     6,  1171,    -1,    24,  1171,     6,  1171,
      -1,    25,  1171,     6,  1171,    -1,    26,  1171,     6,  1171,
      -1,    27,  1171,     6,  1171,    -1,    28,  1171,     6,  1171,
      -1,    29,  1171,     6,  1171,    -1,    30,  1171,     6,  1171,
      -1,    31,  1171,     6,  1171,    -1,    32,  1171,     6,  1171,
      -1,    33,  1171,     6,  1171,    -1,    34,  1171,     6,  1171,
      -1,     6,    -1,     7,    -1,     4,    -1,     6,    -1,     7,
      -1,  1172,     8,    -1,    -1,  1172,  1173,    -1,   398,    -1,
     399,    -1,   400,    -1,   401,    -1,  1175,  1176,    -1,    65,
      -1,  1177,    -1,  1178,    -1,    11,    -1,    10,  1179,    66,
      -1,  1180,    -1,    -1,  1180,  1181,    -1,  1182,    -1,  1186,
      -1,  1190,    -1,  1194,    -1,  1198,    -1,  1183,    -1,  1184,
      -1,  1185,    -1,   214,    -1,   213,    -1,   211,     5,   212,
      -1,  1187,    -1,  1188,    -1,  1189,    -1,   218,    -1,   217,
      -1,   215,     5,   216,    -1,  1191,    -1,  1192,    -1,  1193,
      -1,   222,    -1,   221,    -1,   219,     5,   220,    -1,  1195,
      -1,  1196,    -1,  1197,    -1,   226,    -1,   225,    -1,   223,
       5,   224,    -1,  1199,    -1,  1200,    -1,  1201,    -1,   230,
      -1,   229,    -1,   227,     5,   228,    -1,  1203,    -1,  1210,
      -1,    -1,  1203,  1204,    -1,  1205,  1206,  1209,    -1,   115,
      -1,  1207,    -1,    -1,  1207,  1208,    -1,  1216,    -1,  1215,
      -1,    10,     6,   116,    -1,    97,  1214,  1211,    -1,  1212,
      -1,  1213,    -1,    10,    98,    -1,    11,    -1,    10,     4,
      98,    -1,    40,     8,     6,     8,    -1,    38,     8,     6,
       8,    -1,    39,     8,     6,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   334,   334,   335,   337,   344,   354,   354,   356,   356,
     358,   360,   362,   371,   372,   375,   384,   384,   397,   397,
     399,   413,   413,   415,   415,   417,   419,   421,   421,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   435,   437,
     452,   459,   459,   462,   467,   471,   480,   484,   489,   489,
     491,   493,   495,   495,   497,   502,   512,   518,   518,   521,
     526,   532,   532,   535,   537,   544,   544,   546,   546,   548,
     550,   553,   555,   562,   562,   564,   564,   566,   568,   573,
     575,   582,   582,   584,   584,   586,   588,   593,   595,   602,
     602,   604,   604,   606,   608,   613,   615,   622,   622,   624,
     624,   626,   628,   633,   635,   642,   642,   644,   644,   646,
     648,   653,   655,   662,   662,   664,   664,   666,   668,   673,
     675,   682,   692,   697,   703,   703,   705,   707,   709,   709,
     711,   716,   728,   734,   734,   737,   744,   749,   756,   756,
     760,   760,   762,   773,   773,   775,   775,   777,   779,   781,
     781,   784,   785,   786,   787,   788,   789,   792,   794,   801,
     801,   803,   803,   805,   807,   814,   816,   827,   829,   829,
     832,   838,   844,   846,   852,   854,   865,   867,   867,   870,
     876,   882,   884,   891,   893,   904,   906,   906,   909,   915,
     921,   923,   930,   932,   941,   942,   948,   950,   956,   958,
     965,   975,   980,   986,   986,   988,   990,   992,   992,   994,
     999,  1011,  1017,  1017,  1020,  1027,  1032,  1038,  1038,  1042,
    1042,  1044,  1055,  1055,  1057,  1057,  1059,  1061,  1063,  1063,
    1066,  1067,  1068,  1069,  1070,  1071,  1074,  1076,  1083,  1083,
    1085,  1085,  1087,  1089,  1097,  1099,  1106,  1106,  1108,  1108,
    1110,  1112,  1117,  1119,  1126,  1126,  1128,  1128,  1130,  1132,
    1137,  1139,  1146,  1146,  1148,  1148,  1150,  1152,  1157,  1159,
    1166,  1166,  1168,  1168,  1170,  1172,  1179,  1181,  1188,  1198,
    1203,  1209,  1209,  1211,  1213,  1215,  1215,  1217,  1222,  1234,
    1240,  1240,  1243,  1250,  1255,  1262,  1262,  1265,  1265,  1267,
    1283,  1283,  1285,  1285,  1287,  1289,  1291,  1291,  1294,  1295,
    1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1307,
    1309,  1316,  1316,  1318,  1318,  1320,  1322,  1330,  1332,  1339,
    1339,  1341,  1341,  1343,  1345,  1350,  1352,  1359,  1359,  1361,
    1361,  1363,  1365,  1370,  1372,  1379,  1379,  1381,  1381,  1383,
    1385,  1390,  1392,  1399,  1399,  1401,  1401,  1403,  1405,  1410,
    1412,  1419,  1429,  1434,  1440,  1440,  1442,  1444,  1446,  1446,
    1448,  1450,  1464,  1464,  1467,  1467,  1467,  1467,  1470,  1470,
    1472,  1472,  1474,  1476,  1485,  1486,  1489,  1491,  1502,  1504,
    1504,  1507,  1513,  1519,  1521,  1528,  1530,  1541,  1543,  1543,
    1546,  1552,  1558,  1560,  1567,  1569,  1580,  1582,  1582,  1585,
    1591,  1597,  1599,  1606,  1608,  1618,  1619,  1625,  1627,  1634,
    1636,  1643,  1653,  1658,  1664,  1664,  1666,  1668,  1670,  1670,
    1672,  1677,  1689,  1695,  1695,  1698,  1705,  1710,  1717,  1717,
    1720,  1720,  1722,  1730,  1736,  1736,  1739,  1746,  1752,  1758,
    1766,  1771,  1777,  1777,  1779,  1781,  1783,  1783,  1785,  1787,
    1796,  1798,  1798,  1800,  1800,  1800,  1802,  1812,  1822,  1842,
    1848,  1850,  1860,  1866,  1866,  1869,  1874,  1879,  1889,  1894,
    1900,  1900,  1902,  1904,  1906,  1906,  1908,  1913,  1923,  1929,
    1929,  1932,  1938,  1945,  1945,  1948,  1948,  1950,  1952,  1952,
    1954,  1954,  1956,  1958,  1966,  1966,  1968,  1974,  1974,  1982,
    1982,  1984,  1986,  1988,  1990,  1990,  1992,  1994,  2002,  2007,
    2013,  2013,  2015,  2017,  2019,  2019,  2021,  2032,  2041,  2041,
    2044,  2045,  2048,  2051,  2051,  2053,  2055,  2063,  2068,  2074,
    2074,  2076,  2078,  2080,  2080,  2082,  2093,  2102,  2102,  2105,
    2106,  2110,  2111,  2113,  2113,  2115,  2117,  2122,  2122,  2124,
    2129,  2129,  2131,  2133,  2135,  2137,  2137,  2146,  2148,  2155,
    2155,  2157,  2159,  2161,  2164,  2164,  2174,  2176,  2184,  2184,
    2186,  2188,  2190,  2193,  2193,  2202,  2204,  2212,  2212,  2214,
    2216,  2218,  2221,  2221,  2230,  2232,  2240,  2240,  2242,  2244,
    2246,  2249,  2249,  2258,  2260,  2268,  2268,  2270,  2272,  2274,
    2277,  2277,  2286,  2288,  2296,  2296,  2298,  2300,  2302,  2305,
    2305,  2314,  2316,  2324,  2324,  2326,  2328,  2330,  2333,  2333,
    2335,  2340,  2359,  2365,  2365,  2368,  2379,  2390,  2396,  2402,
    2408,  2414,  2420,  2427,  2427,  2429,  2429,  2431,  2433,  2433,
    2435,  2435,  2437,  2444,  2453,  2453,  2456,  2462,  2469,  2469,
    2471,  2471,  2473,  2475,  2484,  2484,  2486,  2497,  2505,  2511,
    2511,  2514,  2520,  2521,  2525,  2525,  2527,  2529,  2532,  2536,
    2536,  2538,  2546,  2546,  2554,  2554,  2556,  2558,  2560,  2562,
    2562,  2564,  2566,  2574,  2579,  2585,  2585,  2587,  2589,  2592,
    2592,  2594,  2603,  2613,  2613,  2616,  2617,  2620,  2623,  2623,
    2625,  2630,  2630,  2633,  2635,  2637,  2639,  2639,  2648,  2650,
    2657,  2657,  2659,  2661,  2663,  2665,  2665,  2674,  2676,  2684,
    2684,  2686,  2688,  2690,  2693,  2693,  2702,  2704,  2712,  2712,
    2714,  2716,  2718,  2721,  2721,  2730,  2732,  2740,  2740,  2742,
    2744,  2746,  2749,  2749,  2758,  2760,  2768,  2768,  2770,  2772,
    2774,  2777,  2777,  2786,  2788,  2796,  2796,  2798,  2800,  2802,
    2805,  2805,  2814,  2816,  2824,  2824,  2826,  2828,  2830,  2833,
    2833,  2835,  2841,  2860,  2867,  2867,  2870,  2881,  2892,  2898,
    2904,  2910,  2916,  2922,  2931,  2931,  2933,  2933,  2935,  2937,
    2937,  2939,  2939,  2941,  2946,  2957,  2957,  2960,  2965,  2972,
    2972,  2974,  2974,  2976,  2978,  2985,  2985,  2987,  2998,  3006,
    3012,  3012,  3015,  3021,  3022,  3026,  3026,  3028,  3030,  3033,
    3036,  3036,  3038,  3045,  3045,  3053,  3053,  3055,  3057,  3059,
    3061,  3061,  3063,  3066,  3074,  3079,  3085,  3085,  3087,  3089,
    3091,  3091,  3093,  3102,  3111,  3111,  3114,  3115,  3118,  3121,
    3121,  3123,  3128,  3128,  3130,  3132,  3134,  3136,  3136,  3145,
    3147,  3154,  3154,  3156,  3158,  3160,  3162,  3162,  3171,  3173,
    3181,  3181,  3183,  3185,  3187,  3190,  3190,  3199,  3201,  3209,
    3209,  3211,  3213,  3215,  3218,  3218,  3227,  3229,  3237,  3237,
    3239,  3241,  3243,  3246,  3246,  3255,  3257,  3265,  3265,  3267,
    3269,  3271,  3274,  3274,  3283,  3285,  3293,  3293,  3295,  3297,
    3299,  3302,  3302,  3311,  3313,  3321,  3321,  3323,  3325,  3327,
    3330,  3330,  3332,  3338,  3357,  3363,  3363,  3366,  3377,  3388,
    3395,  3401,  3407,  3413,  3419,  3426,  3426,  3428,  3428,  3430,
    3432,  3432,  3434,  3434,  3436,  3443,  3452,  3452,  3456,  3461,
    3469,  3469,  3471,  3471,  3473,  3475,  3482,  3482,  3484,  3495,
    3503,  3509,  3509,  3512,  3518,  3519,  3523,  3523,  3525,  3527,
    3529,  3533,  3533,  3535,  3540,  3549,  3554,  3560,  3560,  3562,
    3564,  3566,  3566,  3568,  3573,  3587,  3595,  3595,  3598,  3604,
    3610,  3616,  3624,  3634,  3639,  3645,  3645,  3647,  3649,  3651,
    3651,  3653,  3659,  3664,  3666,  3666,  3668,  3670,  3682,  3682,
    3684,  3689,  3698,  3703,  3709,  3709,  3711,  3713,  3715,  3715,
    3717,  3722,  3734,  3742,  3742,  3745,  3750,  3756,  3762,  3771,
    3776,  3782,  3782,  3784,  3786,  3788,  3788,  3790,  3796,  3801,
    3803,  3803,  3805,  3807,  3818,  3825,  3825,  3827,  3832,  3837,
    3844,  3844,  3846,  3851,  3856,  3863,  3863,  3865,  3870,  3875,
    3882,  3882,  3884,  3889,  3894,  3902,  3909,  3909,  3911,  3916,
    3921,  3928,  3928,  3930,  3935,  3940,  3947,  3947,  3949,  3954,
    3959,  3966,  3966,  3968,  3973,  3978,  3985,  3985,  3987,  3992,
    3997,  4004,  4004,  4006,  4011,  4017,  4023,  4032,  4038,  4052,
    4061,  4067,  4076,  4082,  4088,  4094,  4100,  4106,  4115,  4121,
    4130,  4135,  4141,  4158,  4159,  4163,  4164,  4165,  4167,  4169,
    4169,  4171,  4172,  4173,  4174,  4211,  4213,  4227,  4227,  4229,
    4231,  4233,  4235,  4235,  4238,  4239,  4240,  4241,  4242,  4244,
    4252,  4252,  4254,  4254,  4256,  4262,  4270,  4270,  4272,  4272,
    4274,  4280,  4288,  4288,  4290,  4290,  4292,  4298,  4306,  4306,
    4308,  4308,  4310,  4316,  4324,  4324,  4326,  4326,  4328,  4340,
    4349,  4351,  4351,  4353,  4355,  4364,  4366,  4366,  4368,  4368,
    4370,  4387,  4390,  4390,  4392,  4392,  4395,  5972,  5979,  5989
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
  "MATRIXVARSTART", "MATRIXVAREND", "MATRIXOBJSTART", "MATRIXOBJEND",
  "MATRIXCONSTART", "MATRIXCONEND", "FILENAMESTART", "FILENAMEEND",
  "FILENAMEEMPTY", "FILENAMESTARTANDEND", "FILESOURCESTART",
  "FILESOURCEEND", "FILESOURCEEMPTY", "FILESOURCESTARTANDEND",
  "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
  "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART", "FILECREATOREND",
  "FILECREATOREMPTY", "FILECREATORSTARTANDEND", "FILELICENCESTART",
  "FILELICENCEEND", "FILELICENCEEMPTY", "FILELICENCESTARTANDEND",
  "MATRIXSTART", "MATRIXEND", "BASEMATRIXEND", "BASEMATRIXSTART",
  "BLOCKSTART", "BLOCKEND", "BLOCKSSTART", "BLOCKSEND", "EMPTYSHAPEATT",
  "SHAPEATT", "EMPTYSYMMETRYATT", "SYMMETRYATT", "EMPTYNEGATIVEPATTERNATT",
  "NEGATIVEPATTERNATT", "CONSTANTATT", "NUMBEROFBLOCKSATT",
  "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT", "NUMBEROFVALUESATT", "COEFATT",
  "BASEMATRIXIDXATT", "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
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
  "PATTERNELEMENTSSTART", "PATTERNELEMENTSEND", "TRANSFORMATIONSTART",
  "TRANSFORMATIONEND", "COLOFFSETSSTART", "COLOFFSETSEND",
  "ROWOFFSETSSTART", "ROWOFFSETSEND", "EMPTYROWMAJORATT", "ROWMAJORATT",
  "BLOCKROWIDXATT", "BLOCKCOLIDXATT", "DUMMY", "NONLINEAREXPRESSIONSSTART",
  "NONLINEAREXPRESSIONSEND", "NUMBEROFNONLINEAREXPRESSIONS", "NLSTART",
  "NLEND", "MATRIXEXPRESSIONSSTART", "MATRIXEXPRESSIONSEND",
  "NUMBEROFEXPR", "EXPRSTART", "EXPREND", "NUMBEROFMATRIXTERMSATT",
  "MATRIXTERMSTART", "MATRIXTERMEND", "POWERSTART", "POWEREND",
  "PLUSSTART", "PLUSEND", "MINUSSTART", "MINUSEND", "DIVIDESTART",
  "DIVIDEEND", "LNSTART", "LNEND", "SQRTSTART", "SQRTEND", "SUMSTART",
  "SUMEND", "PRODUCTSTART", "PRODUCTEND", "EXPSTART", "EXPEND",
  "NEGATESTART", "NEGATEEND", "IFSTART", "IFEND", "SQUARESTART",
  "SQUAREEND", "COSSTART", "COSEND", "SINSTART", "SINEND", "VARIABLESTART",
  "VARIABLEEND", "ABSSTART", "ABSEND", "ERFSTART", "ERFEND", "MAXSTART",
  "MAXEND", "ALLDIFFSTART", "ALLDIFFEND", "MINSTART", "MINEND", "ESTART",
  "EEND", "PISTART", "PIEND", "TIMESSTART", "TIMESEND", "NUMBERSTART",
  "NUMBEREND", "MATRIXDETERMINANTSTART", "MATRIXDETERMINANTEND",
  "MATRIXTRACESTART", "MATRIXTRACEEND", "MATRIXTOSCALARSTART",
  "MATRIXTOSCALAREND", "MATRIXDIAGONALSTART", "MATRIXDIAGONALEND",
  "MATRIXDOTTIMESSTART", "MATRIXDOTTIMESEND", "MATRIXLOWERTRIANGLESTART",
  "MATRIXLOWERTRIANGLEEND", "MATRIXUPPERTRIANGLESTART",
  "MATRIXUPPERTRIANGLEEND", "MATRIXMERGESTART", "MATRIXMERGEEND",
  "MATRIXMINUSSTART", "MATRIXMINUSEND", "MATRIXNEGATESTART",
  "MATRIXNEGATEEND", "MATRIXPLUSSTART", "MATRIXPLUSEND",
  "MATRIXTIMESSTART", "MATRIXTIMESEND", "MATRIXPRODUCTSTART",
  "MATRIXPRODUCTEND", "MATRIXSCALARTIMESSTART", "MATRIXSCALARTIMESEND",
  "MATRIXSUBMATRIXATSTART", "MATRIXSUBMATRIXATEND", "MATRIXTRANSPOSESTART",
  "MATRIXTRANSPOSEEND", "MATRIXREFERENCESTART", "MATRIXREFERENCEEND",
  "IDENTITYMATRIXSTART", "IDENTITYMATRIXEND", "MATRIXINVERSESTART",
  "MATRIXINVERSEEND", "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT",
  "IDATT", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept", "osrldoc",
  "osrlStartEmpty", "osrlStart", "osrlAttributes", "osrlContent",
  "osrlEmpty", "osrlLaden", "osrlEnd", "osrlEnding", "osrlBody",
  "headerElement", "generalElement", "generalElementStart",
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
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,    32,     9,
      13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   402,   403,   403,   404,   405,   406,   406,   407,   407,
     408,   409,   410,   411,   411,   412,   413,   413,   414,   414,
     415,   416,   416,   417,   417,   418,   419,   420,   420,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   422,   423,
     424,   425,   425,   426,   426,   426,   427,   427,   428,   428,
     429,   430,   431,   431,   432,   433,   434,   435,   435,   436,
     436,   437,   437,   438,   439,   440,   440,   441,   441,   442,
     443,   444,   445,   446,   446,   447,   447,   448,   449,   450,
     451,   452,   452,   453,   453,   454,   455,   456,   457,   458,
     458,   459,   459,   460,   461,   462,   463,   464,   464,   465,
     465,   466,   467,   468,   469,   470,   470,   471,   471,   472,
     473,   474,   475,   476,   476,   477,   477,   478,   479,   480,
     481,   482,   483,   483,   484,   484,   485,   486,   487,   487,
     488,   489,   490,   491,   491,   492,   492,   492,   493,   493,
     494,   494,   495,   496,   496,   497,   497,   498,   499,   500,
     500,   501,   501,   501,   501,   501,   501,   502,   503,   504,
     504,   505,   505,   506,   507,   508,   509,   510,   511,   511,
     512,   512,   513,   514,   515,   516,   517,   518,   518,   519,
     519,   520,   521,   522,   523,   524,   525,   525,   526,   526,
     527,   528,   529,   530,   531,   531,   532,   533,   534,   535,
     536,   537,   537,   538,   538,   539,   540,   541,   541,   542,
     543,   544,   545,   545,   546,   546,   546,   547,   547,   548,
     548,   549,   550,   550,   551,   551,   552,   553,   554,   554,
     555,   555,   555,   555,   555,   555,   556,   557,   558,   558,
     559,   559,   560,   561,   562,   563,   564,   564,   565,   565,
     566,   567,   568,   569,   570,   570,   571,   571,   572,   573,
     574,   575,   576,   576,   577,   577,   578,   579,   580,   581,
     582,   582,   583,   583,   584,   585,   586,   587,   588,   589,
     589,   590,   590,   591,   592,   593,   593,   594,   595,   596,
     597,   597,   598,   598,   598,   599,   599,   600,   600,   601,
     602,   602,   603,   603,   604,   605,   606,   606,   607,   607,
     607,   607,   607,   607,   607,   607,   607,   607,   607,   608,
     609,   610,   610,   611,   611,   612,   613,   614,   615,   616,
     616,   617,   617,   618,   619,   620,   621,   622,   622,   623,
     623,   624,   625,   626,   627,   628,   628,   629,   629,   630,
     631,   632,   633,   634,   634,   635,   635,   636,   637,   638,
     639,   640,   641,   641,   642,   642,   643,   644,   645,   645,
     646,   647,   648,   648,   649,   649,   649,   649,   650,   650,
     651,   651,   652,   653,   654,   654,   655,   656,   657,   658,
     658,   659,   659,   660,   661,   662,   663,   664,   665,   665,
     666,   666,   667,   668,   669,   670,   671,   672,   672,   673,
     673,   674,   675,   676,   677,   678,   678,   679,   680,   681,
     682,   683,   684,   684,   685,   685,   686,   687,   688,   688,
     689,   690,   691,   692,   692,   693,   693,   693,   694,   694,
     695,   695,   696,   697,   698,   698,   699,   699,   699,   699,
     700,   700,   701,   701,   702,   703,   704,   704,   705,   706,
     707,   708,   708,   709,   709,   709,   710,   711,   712,   713,
     714,   715,   716,   717,   717,   718,   718,   718,   719,   719,
     720,   720,   721,   722,   723,   723,   724,   725,   726,   727,
     727,   728,   728,   729,   729,   730,   730,   731,   732,   732,
     733,   733,   734,   735,   736,   736,   737,   738,   738,   739,
     739,   740,   741,   742,   743,   743,   744,   745,   746,   746,
     747,   747,   748,   749,   750,   750,   751,   752,   753,   753,
     754,   754,   755,   756,   756,   757,   758,   759,   759,   760,
     760,   761,   762,   763,   763,   764,   765,   766,   766,   767,
     767,   768,   768,   769,   769,   770,   771,   772,   772,   773,
     774,   774,   775,   776,   777,   778,   778,   779,   780,   781,
     781,   782,   783,   784,   785,   785,   786,   787,   788,   788,
     789,   790,   791,   792,   792,   793,   794,   795,   795,   796,
     797,   798,   799,   799,   800,   801,   802,   802,   803,   804,
     805,   806,   806,   807,   808,   809,   809,   810,   811,   812,
     813,   813,   814,   815,   816,   816,   817,   818,   819,   820,
     820,   821,   822,   823,   823,   824,   825,   826,   827,   827,
     828,   829,   830,   831,   831,   832,   832,   832,   832,   832,
     832,   832,   832,   833,   833,   834,   834,   835,   836,   836,
     837,   837,   838,   839,   840,   840,   841,   841,   842,   842,
     843,   843,   844,   845,   846,   846,   847,   848,   849,   850,
     850,   851,   851,   851,   852,   852,   853,   854,   855,   856,
     856,   857,   858,   858,   859,   859,   860,   861,   862,   863,
     863,   864,   865,   866,   866,   867,   867,   868,   869,   870,
     870,   871,   872,   873,   873,   874,   874,   875,   876,   876,
     877,   878,   878,   879,   880,   881,   882,   882,   883,   884,
     885,   885,   886,   887,   888,   889,   889,   890,   891,   892,
     892,   893,   894,   895,   896,   896,   897,   898,   899,   899,
     900,   901,   902,   903,   903,   904,   905,   906,   906,   907,
     908,   909,   910,   910,   911,   912,   913,   913,   914,   915,
     916,   917,   917,   918,   919,   920,   920,   921,   922,   923,
     924,   924,   925,   926,   927,   927,   928,   929,   930,   931,
     931,   932,   933,   934,   935,   935,   936,   936,   936,   936,
     936,   936,   936,   936,   937,   937,   938,   938,   939,   940,
     940,   941,   941,   942,   943,   944,   944,   945,   945,   946,
     946,   947,   947,   948,   949,   950,   950,   951,   952,   953,
     954,   954,   955,   955,   955,   956,   956,   957,   958,   959,
     960,   960,   961,   962,   962,   963,   963,   964,   965,   966,
     967,   967,   968,   969,   970,   970,   971,   971,   972,   973,
     974,   974,   975,   976,   977,   977,   978,   978,   979,   980,
     980,   981,   982,   982,   983,   984,   985,   986,   986,   987,
     988,   989,   989,   990,   991,   992,   993,   993,   994,   995,
     996,   996,   997,   998,   999,  1000,  1000,  1001,  1002,  1003,
    1003,  1004,  1005,  1006,  1007,  1007,  1008,  1009,  1010,  1010,
    1011,  1012,  1013,  1014,  1014,  1015,  1016,  1017,  1017,  1018,
    1019,  1020,  1021,  1021,  1022,  1023,  1024,  1024,  1025,  1026,
    1027,  1028,  1028,  1029,  1030,  1031,  1031,  1032,  1033,  1034,
    1035,  1035,  1036,  1037,  1038,  1039,  1039,  1040,  1040,  1040,
    1040,  1040,  1040,  1040,  1040,  1041,  1041,  1042,  1042,  1043,
    1044,  1044,  1045,  1045,  1046,  1047,  1048,  1048,  1049,  1049,
    1050,  1050,  1051,  1051,  1052,  1053,  1054,  1054,  1055,  1056,
    1057,  1058,  1058,  1059,  1059,  1059,  1060,  1060,  1061,  1062,
    1063,  1064,  1064,  1065,  1066,  1067,  1067,  1068,  1068,  1069,
    1070,  1071,  1071,  1072,  1073,  1074,  1075,  1075,  1076,  1076,
    1076,  1076,  1076,  1077,  1077,  1078,  1078,  1079,  1080,  1081,
    1081,  1082,  1083,  1083,  1084,  1084,  1085,  1086,  1087,  1087,
    1088,  1089,  1090,  1090,  1091,  1091,  1092,  1093,  1094,  1094,
    1095,  1096,  1097,  1098,  1098,  1099,  1099,  1099,  1099,  1100,
    1100,  1101,  1101,  1102,  1103,  1104,  1104,  1105,  1106,  1106,
    1107,  1107,  1108,  1109,  1110,  1111,  1111,  1112,  1113,  1114,
    1115,  1115,  1116,  1117,  1118,  1119,  1119,  1120,  1121,  1122,
    1123,  1123,  1124,  1125,  1126,  1127,  1128,  1128,  1129,  1130,
    1131,  1132,  1132,  1133,  1134,  1135,  1136,  1136,  1137,  1138,
    1139,  1140,  1140,  1141,  1142,  1143,  1144,  1144,  1145,  1146,
    1147,  1148,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,  1167,  1168,  1169,  1169,  1170,  1170,  1170,  1171,  1172,
    1172,  1173,  1173,  1173,  1173,  1174,  1175,  1176,  1176,  1177,
    1178,  1179,  1180,  1180,  1181,  1181,  1181,  1181,  1181,  1182,
    1183,  1183,  1184,  1184,  1185,  1186,  1187,  1187,  1188,  1188,
    1189,  1190,  1191,  1191,  1192,  1192,  1193,  1194,  1195,  1195,
    1196,  1196,  1197,  1198,  1199,  1199,  1200,  1200,  1201,  1202,
    1202,  1203,  1203,  1204,  1205,  1206,  1207,  1207,  1208,  1208,
    1209,  1210,  1211,  1211,  1212,  1212,  1213,  1214,  1215,  1216
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
#define YYPACT_NINF -1334
static const yytype_int16 yypact[] =
{
     107, -1334, -1334,    85,     0,   111, -1334, -1334,   106,    62,
   -1334,   191, -1334,   229, -1334, -1334, -1334, -1334,    74,   242,
   -1334, -1334, -1334, -1334, -1334,     0, -1334, -1334, -1334, -1334,
   -1334,   104,   305,   -21, -1334, -1334, -1334, -1334,    79,   395,
     106, -1334,   110,   321,    -1, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   139,
     157, -1334, -1334,   345, -1334,   347, -1334,   353, -1334,   364,
   -1334,   407, -1334,   419, -1334,   431, -1334,   440, -1334,   190,
   -1334,   219, -1334, -1334,   236, -1334, -1334,   256, -1334, -1334,
     260, -1334, -1334,   264, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   155,
     451,    69, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,   177,     2, -1334, -1334,   488, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334,   465, -1334,   190, -1334, -1334,
   -1334,   274, -1334,   284, -1334,   500,   345, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334,    32, -1334, -1334,
   -1334, -1334,    31, -1334, -1334, -1334, -1334,    28, -1334, -1334,
   -1334, -1334,    34, -1334, -1334, -1334, -1334,    39, -1334, -1334,
   -1334, -1334,    18, -1334, -1334, -1334, -1334,    21, -1334, -1334,
   -1334, -1334, -1334,   506, -1334,    84,    82,   102,   115,   113,
   -1334, -1334, -1334,   -30, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334,   271,    97, -1334, -1334,   512,
   -1334,   516, -1334,   518, -1334,   521, -1334,   524, -1334,   190,
   -1334, -1334,    12, -1334, -1334, -1334, -1334,   349,   381,   355,
     381,   361,   381,   373, -1334,   526, -1334,   385,     3, -1334,
   -1334,   -60, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   221,
   -1334, -1334,   238, -1334, -1334,   243, -1334, -1334,   280, -1334,
   -1334,   294, -1334, -1334,   273, -1334, -1334,   270,   448,   -47,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   528,
     234, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,   389,   130, -1334, -1334,   534, -1334,   536,
   -1334,   545, -1334,   549, -1334,   551, -1334,   442, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334,   465, -1334,   190, -1334, -1334,
      45, -1334, -1334, -1334, -1334,    66, -1334, -1334, -1334, -1334,
       6, -1334, -1334, -1334, -1334,    15, -1334, -1334, -1334, -1334,
      27, -1334, -1334, -1334, -1334,   553, -1334, -1334, -1334,   296,
     560, -1334,   474, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
     560, -1334, -1334, -1334, -1334,   560, -1334, -1334, -1334, -1334,
     473, -1334,     8, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   384,   312,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334,   340,   352, -1334, -1334,    -6, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334,    25, -1334, -1334, -1334, -1334,    26, -1334, -1334,
   -1334, -1334,    37, -1334, -1334, -1334, -1334,    51, -1334, -1334,
   -1334, -1334,    44, -1334, -1334, -1334, -1334, -1334,   558, -1334,
     502,   381,   504,   381,   508,   381,   510, -1334,   561, -1334,
   -1334, -1334,   428, -1334, -1334,   432, -1334, -1334,   365, -1334,
   -1334,   396, -1334, -1334, -1334,   388, -1334,    80, -1334, -1334,
   -1334, -1334, -1334,   459, -1334, -1334,   505, -1334,   513, -1334,
   -1334,   517, -1334, -1334,   477,   476, -1334, -1334, -1334, -1334,
   -1334,   564,   413, -1334, -1334, -1334,   568,   425, -1334, -1334,
     578,   -94, -1334, -1334,   694,   704,   709,   714, -1334, -1334,
     490, -1334, -1334,   511, -1334, -1334,   550, -1334, -1334,   657,
   -1334, -1334,   621,   732,  -109, -1334, -1334, -1334, -1334,   560,
   -1334, -1334, -1334, -1334,   560, -1334, -1334, -1334, -1334,   560,
   -1334, -1334, -1334, -1334,   734, -1334,   181, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   596,   600,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   581,
     425,   572, -1334, -1334,   742, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334,   602, -1334, -1334,   745, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   720,   739,
      65, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,   567,   575, -1334, -1334,   562, -1334,   559,
   -1334,   565, -1334, -1334,   569, -1334, -1334,   608,   615, -1334,
   -1334, -1334, -1334,   583,   425,   617, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334,   585, -1334,   595,
   -1334, -1334,   757,   760, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334,   337, -1334, -1334, -1334, -1334,
   -1334, -1334,   589,   425,   623, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334,   758,    57, -1334, -1334, -1334, -1334,
   -1334,   633,   345,   759, -1334, -1334,    20, -1334,   765, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334,   626, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334,   619,   604, -1334, -1334, -1334,   571,   593,   616,
     345, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334,   599, -1334, -1334, -1334, -1334, -1334, -1334,   618,   402,
   -1334,   637,   750,    38, -1334, -1334, -1334, -1334,   165, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334,   -16, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   672,
     755, -1334,   620, -1334, -1334, -1334,   647, -1334, -1334,   614,
     612, -1334, -1334,   780, -1334, -1334, -1334,   624,   212, -1334,
   -1334, -1334, -1334,   781, -1334,   639,   762, -1334,   622, -1334,
     783,   520, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   625,
     362, -1334,   716, -1334, -1334, -1334, -1334,   631,   768, -1334,
     628, -1334,   786,   525, -1334, -1334, -1334, -1334, -1334, -1334,
     597,   601,   764,   629, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,   630, -1334,   794,   689, -1334, -1334, -1334,
   -1334, -1334, -1334,   668,   702,   785, -1334, -1334, -1334,   707,
     764, -1334,   632, -1334, -1334,   799,    23, -1334, -1334, -1334,
   -1334, -1334, -1334,   701,   710,   796, -1334, -1334, -1334, -1334,
     634, -1334,   636, -1334, -1334, -1334,   638,   640, -1334,   804,
    -126, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   664,   670,
   -1334, -1334, -1334, -1334, -1334, -1334,   642, -1334,   646, -1334,
     676,   722, -1334, -1334, -1334, -1334,   809,  -104, -1334, -1334,
   -1334, -1334,   680,   725, -1334, -1334, -1334, -1334,   462, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334,   544,   627, -1334, -1334,
   -1334, -1334, -1334,   652,   308,   685,   728, -1334, -1334, -1334,
   -1334,   812,    13, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334,   718,   737,   807, -1334, -1334, -1334,   557,   695, -1334,
   -1334, -1334, -1334, -1334, -1334,   729,   747,   807, -1334, -1334,
     635,   641, -1334, -1334, -1334, -1334, -1334,   175,     1, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,   735,   749,   807, -1334, -1334, -1334,   724,
     731, -1334, -1334,   654,   368, -1334, -1334,   754,   807, -1334,
     656, -1334, -1334, -1334, -1334,   248,   659,   445, -1334, -1334,
     756,   807,   661, -1334, -1334, -1334,   225,   560, -1334, -1334,
   -1334, -1334, -1334,   837, -1334, -1334, -1334,   697,   227, -1334,
   -1334, -1334, -1334,   663,   538, -1334, -1334,   761,   807,   665,
   -1334, -1334, -1334, -1334,   300,   -13, -1334, -1334, -1334, -1334,
   -1334,   841, -1334,   844, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334,   766,   807,   667, -1334,   845,   753, -1334, -1334, -1334,
   -1334,   560, -1334, -1334, -1334, -1334,   -61, -1334, -1334, -1334,
   -1334,   849, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334,   771,   807,   669, -1334,
     753, -1334, -1334, -1334, -1334,     5, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,   655,   850, -1334,   779, -1334, -1334,   -31,
   -1334, -1334, -1334, -1334,   855, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   777,
     807,   673, -1334,   753, -1334, -1334, -1334, -1334,   560, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334,   727,   730, -1334, -1334,
     744, -1334, -1334,   856, -1334, -1334, -1334,   738,   807,   675,
   -1334,   753, -1334, -1334, -1334, -1334, -1334,   823,   769, -1334,
     751, -1334,   736, -1334, -1334, -1334,   733,   671, -1334, -1334,
     763, -1334, -1334, -1334, -1334,   746,   807,   677, -1334,   753,
   -1334, -1334, -1334, -1334,   773, -1334, -1334, -1334,   674, -1334,
   -1334, -1334, -1334, -1334, -1334,   740,   774, -1334, -1334,   770,
   -1334, -1334, -1334, -1334,   752,   807,   679, -1334,   753, -1334,
   -1334, -1334, -1334,   776, -1334,   782, -1334, -1334,   235, -1334,
     682,   200, -1334, -1334, -1334, -1334,   691,   807,   684, -1334,
     753, -1334, -1334, -1334, -1334,   797, -1334, -1334,   860,   686,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334,   263, -1334,   688,
     200, -1334, -1334,   713,   807,   692, -1334,   753, -1334, -1334,
   -1334, -1334,   803, -1334, -1334, -1334, -1334, -1334, -1334,   324,
   -1334,   696,   200, -1334, -1334,   741,   807,   698, -1334,   753,
   -1334, -1334, -1334, -1334,   805, -1334, -1334, -1334,    33, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334,   753, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334,   705,   807,   703,
   -1334,   753, -1334, -1334, -1334, -1334,   802, -1334, -1334,   876,
      50, -1334, -1334, -1334, -1334,   875,   678,    17, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334,   753, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334,   706,   807,   708, -1334,   753,
   -1334, -1334, -1334, -1334,   806, -1334, -1334,    46, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334,   753, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334,   711,   807,   712, -1334,   753,
   -1334, -1334, -1334, -1334,   808, -1334, -1334, -1334, -1334, -1334,
   -1334,   767, -1334,   784, -1334, -1334, -1334,   807,   715, -1334,
     753, -1334, -1334, -1334, -1334,   811, -1334, -1334,   889,   801,
   -1334,   894, -1334,   893,   896, -1334, -1334, -1334, -1334,   743,
   -1334,   787, -1334, -1334, -1334,   807,   717, -1334,   753, -1334,
   -1334, -1334, -1334,   822, -1334, -1334, -1334,   810, -1334,   789,
   -1334, -1334, -1334,   807,   719, -1334,   753, -1334, -1334, -1334,
   -1334,   824, -1334, -1334, -1334, -1334,   721, -1334,   753, -1334,
   -1334, -1334, -1334,   788, -1334, -1334, -1334, -1334,   795,   906,
     907, -1334, -1334,   723, -1334,   753, -1334, -1334, -1334, -1334,
     790, -1334, -1334, -1334, -1334,   726, -1334,   753, -1334, -1334,
   -1334, -1334,   791, -1334, -1334,   753, -1334, -1334, -1334, -1334,
     772, -1334, -1334, -1334,   909,   911,   753, -1334, -1334, -1334,
   -1334,   778, -1334, -1334,   753, -1334, -1334, -1334, -1334,   792,
   -1334, -1334,   748, -1334, -1334, -1334, -1334,   775, -1334, -1334,
     793, -1334, -1334, -1334, -1334, -1334
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   883, -1334,
     890, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   864,
   -1334, -1334, -1334, -1334,   798, -1334, -1334, -1334, -1334, -1334,
     519, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334,   503, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   800,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
     410, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,   813, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334,   338, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334,   643, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334,   285, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334,   272, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,   400, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334,   172, -1334, -1334, -1334,
   -1334, -1334,   117, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   -44,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334,   -86, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334,  -319, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334,  -321, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,   -68,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
    -286, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,  -288,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,  -106, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334,  -341, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,  -342, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
       9, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
    -138, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,   198, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,   125, -1334, -1334, -1334, -1334,  -771, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334,  -145, -1334, -1334, -1334,
    -985, -1334, -1334, -1334, -1058,  -524, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334,  -694, -1334, -1334, -1334,  -246, -1334, -1334,
   -1334,  -587, -1334, -1334, -1334, -1334, -1334, -1334, -1334,  -139,
   -1334, -1000,  -959,   -28,   -96, -1334, -1334, -1334,  -137, -1334,
   -1334, -1334, -1334,  -643, -1334,  -886, -1334,  -365, -1333,  -200,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1083, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334, -1334,
   -1334, -1334, -1334, -1334, -1334
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     254,   739,   288,   619,   384,   504,   389,  1144,   804,  1276,
     256,   398,   486,   671,   928,   507,   367,  1073,  1181,   489,
     509,  1477,   282,  1478,  1479,   285,   768,   769,   763,   538,
     541,  1005,   273,   492,   493,   270,   267,  1477,   276,  1478,
    1479,   544,   814,   279,   301,  1100,  1221,    49,   550,   480,
    1477,   302,  1478,  1479,  1499,   547,  1253,   625,  1134,   404,
     405,   823,   406,   824,   825,     7,   763,   529,   641,   126,
     528,  1169,   483,   974,  1282,   642,   670,   710,  1083,   764,
    1084,  1085,  1155,  1254,  1510,     6,  1283,  1275,   127,   303,
     128,   127,   129,   128,   130,   129,   420,   130,  1212,   421,
      50,   681,   366,   375,  1223,   383,    51,   388,  1163,  1202,
      52,   407,    53,  1284,  1528,   304,   747,   764,  1047,     1,
       2,    14,  1224,   305,    54,    12,   682,  1048,   683,    17,
    1304,  1225,  1240,   548,    55,  1207,    56,   306,  1255,   307,
     709,   218,    57,    30,   131,    80,   975,   131,  1500,  1086,
     826,   512,  1526,   308,   513,   529,   878,   481,  1326,   309,
      58,   310,   277,   311,   551,   312,   268,  1268,  1006,  1480,
     936,   280,   815,   937,   132,    41,   484,   132,   219,   746,
     220,  1164,   283,   118,   274,  1077,  1353,   494,   368,   271,
     477,   545,   487,   539,   648,   490,   542,   518,   770,   650,
     479,    20,    21,   286,   652,  1277,   219,   148,   220,   750,
    1297,   302,  1078,  1034,   221,  1375,   202,  1508,  1059,   523,
     604,   605,   751,   586,   205,   563,   587,   568,   222,   573,
     210,   534,   535,   536,   537,  1175,  1176,  1407,  1319,    25,
      26,   206,   221,   151,   152,  1378,  1379,   240,   223,   303,
    1384,   431,    33,    34,   224,   806,   222,   432,  1141,   615,
     616,   207,  1078,   433,  1445,   208,  1346,   553,   434,   209,
     604,   605,  1078,  1417,  1418,   304,   223,   259,    50,  1423,
     604,   605,   224,   305,    51,  1078,  1475,   260,    52,   823,
      53,   824,   825,   604,   605,  1368,   294,   306,   295,   307,
    1078,  1453,    54,  1484,  1083,   593,  1084,  1085,   604,   605,
    1218,  1394,    55,   308,    56,    44,    45,  1400,  1496,   309,
      57,   310,   296,   311,   655,   312,   562,   656,   567,   802,
     572,   121,   122,   817,  1447,  1448,   818,  1078,    58,   297,
    1433,   298,  1512,   338,  1438,   604,   605,   726,   727,   728,
     729,   151,   152,   604,   605,   412,  1524,   167,   168,   370,
    1126,  1078,  1463,   172,   173,   380,  1468,   615,   616,   604,
     605,   385,  1530,  1157,   177,   178,   150,   607,   728,   729,
     151,   152,   618,   390,   153,   154,  1542,  1110,   151,   152,
     921,   397,   153,   154,   372,   373,   413,  1037,  1489,   414,
    1204,   399,   400,   401,   402,   151,   152,  1554,   415,   153,
     154,   151,   152,   604,   605,   153,   154,   182,   183,  1111,
    1112,  1113,  1114,   802,   151,   152,   416,   615,   616,   187,
     188,   688,   689,   690,   691,  1571,  1517,   417,   372,   373,
     692,   192,   193,   728,   729,   151,   152,   604,   605,   740,
     197,   198,   418,  1583,   419,   669,   151,   152,   604,   605,
    1036,   213,   214,   440,  1110,  1591,  1535,  1127,   151,   152,
     604,   605,   502,   712,   467,   713,   714,   505,   901,   510,
    1158,   723,  1602,   407,   615,   616,   524,  1547,   151,   152,
     604,   605,   153,   154,  1610,   420,  1111,  1112,   242,   243,
    1151,  1152,  1613,  1082,   615,   616,   519,  1205,   151,   152,
     261,   262,   559,  1618,   564,  1564,   289,   290,   569,   708,
     574,  1621,   340,   341,   766,   767,   345,   346,   350,   351,
    1121,   355,   356,  1576,   360,   361,   392,   393,   426,   427,
     581,  1145,   582,  1156,   442,   443,   447,   448,   585,   775,
     738,   583,  1182,   592,   947,   452,   453,  1110,   745,   457,
     458,   462,   463,   497,   498,   794,   492,   493,   554,   555,
    1203,   576,   577,   796,   601,   602,   584,   762,   612,   613,
    1222,   151,   152,   604,   605,   153,   154,  1194,  1195,  1111,
    1112,   665,   666,   704,   705,   715,   716,   615,   616,   741,
     742,   594,   833,   783,   784,   595,    81,   596,    82,    83,
      84,   840,    85,    86,    87,   762,    88,    89,    90,   512,
      91,    92,    93,   597,    94,    95,   788,   789,   797,   798,
     841,   842,   863,   864,   805,   873,   874,   862,   886,   887,
     906,   907,   930,   931,   951,   952,   957,   958,   963,   964,
     968,   969,   986,   987,   624,   880,   992,   993,   635,   885,
    1018,  1019,  1028,  1029,  1105,  1106,  1136,  1137,   896,  1146,
    1147,  1170,  1171,  1189,  1190,  1213,  1214,  1241,  1242,  1269,
    1270,   636,   905,  1298,  1299,  1320,  1321,  1347,  1348,  1369,
    1370,   916,  1386,  1387,  1401,  1402,  1410,  1411,  1425,  1426,
     631,   929,  1439,  1440,   637,   877,  1455,  1456,  1469,  1470,
     632,   942,  1183,  1490,  1491,   633,  1503,  1504,  1518,  1519,
     634,   956,  1536,  1537,  1393,  1548,  1549,  1565,  1566,  1577,
    1578,  1585,  1586,  1596,  1597,   980,  1604,  1605,   640,   638,
     653,   639,   661,   586,   672,   673,   674,   991,   675,   679,
     676,   693,   641,  1432,   700,   697,   696,   698,   655,   699,
     724,   711,   720,   725,   749,   765,   756,   748,   773,   751,
     774,   776,   780,  1024,   808,  1462,  1252,   795,   811,   834,
     837,   846,   847,   818,  1385,   851,   859,   855,   856,   868,
     853,   869,   891,   881,   879,   882,   892,   901,   898,   897,
     911,   904,   912,   918,  1062,   935,   917,   921,   924,   943,
     973,   944,   947,  1424,   981,  1004,  1025,   936,  1046,   997,
    1055,  1000,  1056,  1011,  1014,  1059,   974,  1042,  1039,  1063,
    1005,  1068,  1069,  1074,  1096,  1454,  1047,  1095,  1102,  1035,
    1019,  1130,  1185,  1165,  1234,  1187,  1101,  1235,  1208,  1236,
    1247,  1246,  1263,  1305,  1264,  1279,  1280,  1281,  1292,  1135,
    1293,  1223,  1312,  1328,  1396,  1224,  1331,  1315,  1409,  1330,
    1255,  1306,  1334,  1354,  1355,  1342,  1376,  1335,  1184,  1282,
    1253,  1364,  1498,  1408,  1357,  1501,  1434,  1283,  1377,  1446,
    1497,  1476,  1485,  1513,  1525,  1555,  1543,  1556,  1531,  1557,
    1558,  1559,  1545,  1544,  1560,  1562,  1572,  1574,  1584,  1116,
    1233,  1593,  1594,  1595,  1464,    40,  1573,  1615,  1592,  1616,
    1603,  1611,  1154,   117,   149,   598,   525,   662,   520,   694,
     701,   626,   793,  1026,   241,  1075,  1623,   848,  1336,  1338,
    1064,  1307,  1309,  1561,  1103,  1358,  1614,  1360,   982,  1201,
    1188,   777,  1619,   854,   266,  1206,  1038,   441,  1129,     0,
       0,     0,     0,  1624,     0,     0,  1622,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1625,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1313,  1314,     0,     0,     0,   339,
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
     147,     8,     6,   600,   900,   380,     4,  1017,  1076,     4,
     385,     4,     4,     6,     7,     4,     6,     7,   722,     4,
       4,   135,     4,     6,     7,     4,     4,     4,     4,     6,
       7,     4,     4,     4,    74,  1045,  1104,    68,     4,     4,
       4,    81,     6,     7,     4,     4,   117,   151,  1058,   259,
     260,    77,   122,    79,    80,    65,   760,   161,   177,    70,
      76,  1071,     6,   199,   105,   184,   600,   664,    77,   722,
      79,    80,  1067,   144,  1417,     0,   117,  1170,    89,   119,
      91,    89,    93,    91,    95,    93,   143,    95,  1098,   146,
     121,    36,   239,   248,   117,   250,   127,   252,  1067,  1094,
     131,   171,   133,   144,  1447,   145,   703,   760,   105,    12,
      13,    15,   135,   153,   145,    14,    61,   114,    63,    67,
    1213,   144,  1132,    82,   155,  1094,   157,   167,   199,   169,
     664,    72,   163,    69,   145,    66,   272,   145,    98,   148,
     166,   143,   106,   183,   146,   161,   850,   112,  1241,   189,
     181,   191,   128,   193,   120,   195,   134,  1167,   272,   136,
     147,   132,   134,   150,   175,    71,   110,   175,   109,   703,
     111,  1067,   164,    73,   156,    10,  1269,   160,   176,   158,
     335,   154,   186,   168,   559,   180,   170,   397,   178,   564,
     337,    10,    11,   182,   569,   200,   109,    68,   111,   152,
    1210,    81,    37,   984,   145,  1298,    26,   200,    18,   419,
      45,    46,   165,   143,     5,   471,   146,   473,   159,   475,
      75,   431,   432,   433,   434,    10,    11,  1320,  1238,    10,
      11,     5,   145,    43,    44,    10,    11,    70,   179,   119,
    1308,    17,    10,    11,   185,   779,   159,    23,    10,    59,
      60,     5,    37,    29,  1347,     5,  1266,   467,    34,     5,
      45,    46,    37,    10,    11,   145,   179,     3,   121,  1337,
      45,    46,   185,   153,   127,    37,  1369,     3,   131,    77,
     133,    79,    80,    45,    46,  1295,   212,   167,   216,   169,
      37,  1359,   145,  1386,    77,   505,    79,    80,    45,    46,
      10,  1311,   155,   183,   157,    10,    11,  1317,  1401,   189,
     163,   191,   220,   193,   143,   195,   471,   146,   473,    21,
     475,    10,    11,   168,    10,    11,   171,    37,   181,   224,
    1340,   228,  1425,    72,  1344,    45,    46,    10,    11,    41,
      42,    43,    44,    45,    46,   134,  1439,    10,    11,    10,
    1054,    37,  1362,    10,    11,    10,  1366,    59,    60,    45,
      46,    10,  1455,  1067,    10,    11,    31,   522,    41,    42,
      43,    44,   527,    10,    47,    48,  1469,    19,    43,    44,
      22,     6,    47,    48,    57,    58,   158,   984,  1398,   156,
    1094,   398,   399,   400,   401,    43,    44,  1490,   128,    47,
      48,    43,    44,    45,    46,    47,    48,    10,    11,    51,
      52,    53,    54,    21,    43,    44,   132,    59,    60,    10,
      11,   631,   632,   633,   634,  1518,  1436,   164,    57,    58,
     640,    10,    11,    41,    42,    43,    44,    45,    46,   695,
      10,    11,   182,  1536,     6,   600,    43,    44,    45,    46,
     984,    10,    11,    74,    19,  1548,  1466,  1054,    43,    44,
      45,    46,   176,   673,    32,   675,   676,     3,    33,     6,
    1067,   681,  1565,   171,    59,    60,   146,  1487,    43,    44,
      45,    46,    47,    48,  1577,   143,    51,    52,    10,    11,
      55,    56,  1585,  1027,    59,    60,   122,  1094,    43,    44,
      10,    11,    10,  1596,    10,  1515,    10,    11,    10,   664,
      10,  1604,    10,    11,   724,   725,    10,    11,    10,    11,
    1054,    10,    11,  1533,    10,    11,    10,    11,    10,    11,
     112,  1065,   110,  1067,    10,    11,    10,    11,   160,   749,
     695,   186,  1076,    94,    16,    10,    11,    19,   703,    10,
      11,    10,    11,    10,    11,   765,     6,     7,    10,    11,
    1094,    10,    11,   773,    10,    11,   180,   722,    10,    11,
    1104,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    10,    11,    10,    11,    10,    11,    59,    60,    10,
      11,    96,   802,    10,    11,    92,   211,    90,   213,   214,
     215,   811,   217,   218,   219,   760,   221,   222,   223,   143,
     225,   226,   227,   146,   229,   230,    10,    11,    10,    11,
      10,    11,    10,    11,   779,    10,    11,   837,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    76,   855,    10,    11,   168,   859,
     198,   199,    10,    11,    10,    11,    10,    11,   868,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,   170,   882,    10,    11,    10,    11,    10,    11,    10,
      11,   891,    10,    11,    10,    11,    10,    11,    10,    11,
       6,   901,    10,    11,   154,   850,    10,    11,    10,    11,
       6,   911,  1077,    10,    11,     6,    38,    39,    10,    11,
       6,   921,    10,    11,  1311,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,   935,    10,    11,     6,    82,
       6,   120,   146,   143,   172,     3,   144,   947,     3,    10,
      30,   184,   177,  1340,   146,   196,   194,   192,   143,   190,
       3,   144,   167,     3,     6,     6,   133,   144,     3,   165,
     144,   152,   201,   973,   137,  1362,  1141,   178,    28,   107,
      25,   134,   168,   171,  1308,     5,    24,     6,   149,     6,
     166,   271,     6,   162,    78,    27,   271,    33,   197,   202,
       6,   172,   113,   101,  1004,     6,   138,    22,   101,   108,
       6,   101,    16,  1337,   150,     6,   272,   147,     6,   143,
     102,    99,    85,   143,    99,    18,   199,    99,   143,   272,
     135,   102,    85,   198,    85,  1359,   105,   102,   114,   984,
     199,    87,     5,    87,     3,   148,  1046,     3,    87,    83,
      97,     6,     3,  1218,    83,   200,     6,    78,     3,  1059,
      83,   117,     6,    40,   173,   135,   115,   129,     8,   100,
     199,   144,   136,   100,   200,   129,   100,   144,  1078,   105,
     117,   129,     6,    86,   144,    10,   173,   117,   106,    86,
      88,    86,   187,   187,    88,    84,    88,     8,   187,    98,
       6,     8,   118,   136,     8,   118,    84,   118,    84,  1054,
    1110,   116,     6,     6,   173,    25,   106,     8,   130,     8,
     130,   130,  1067,    40,    60,   515,   423,   589,   409,   644,
     658,   531,   760,   977,   134,  1021,   188,   820,  1257,  1260,
    1008,  1227,  1230,   200,  1050,  1286,   174,  1289,   939,  1094,
    1088,   753,   174,   828,   156,  1094,   984,   314,  1054,    -1,
      -1,    -1,    -1,   188,    -1,    -1,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1234,  1235,    -1,    -1,    -1,   226,
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
       0,    12,    13,   403,   404,   405,     0,    65,   412,   413,
    1174,  1175,    14,   406,    15,   410,   411,    67,   414,   415,
      10,    11,  1176,  1177,  1178,    10,    11,   407,   408,   409,
      69,   494,   495,    10,    11,   416,   417,   418,  1179,  1180,
     412,    71,   548,   549,    10,    11,   496,   497,   498,    68,
     121,   127,   131,   133,   145,   155,   157,   163,   181,   419,
     420,   421,   422,   423,   438,   439,   444,   445,   450,   451,
     456,   457,   462,   463,   468,   469,   474,   475,   480,   481,
      66,   211,   213,   214,   215,   217,   218,   219,   221,   222,
     223,   225,   226,   227,   229,   230,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,   410,    73,   600,
     601,    10,    11,   550,   551,   552,    70,    89,    91,    93,
      95,   145,   175,   499,   500,   501,   502,   503,   508,   509,
     515,   516,   522,   523,   529,   530,   534,   535,    68,   421,
      31,    43,    44,    47,    48,   424,   425,   426,  1118,  1119,
    1120,  1121,  1135,  1136,  1137,  1138,  1165,    10,    11,   440,
     441,   442,    10,    11,   446,   447,   448,    10,    11,   452,
     453,   454,    10,    11,   458,   459,   460,    10,    11,   464,
     465,   466,    10,    11,   470,   471,   472,    10,    11,   476,
     477,   478,    26,   482,  1160,     5,     5,     5,     5,     5,
      75,   695,   696,    10,    11,   602,   603,   604,    72,   109,
     111,   145,   159,   179,   185,   553,   554,   555,   556,   557,
     562,   563,   568,   569,   574,   575,   580,   581,   586,   587,
      70,   501,    10,    11,   504,   505,   506,   510,   511,   517,
     518,   524,   525,   531,  1118,   536,  1160,  1171,  1172,     3,
       3,    10,    11,   427,   428,   429,   426,     4,   134,   443,
       4,   158,   449,     4,   156,   455,     4,   128,   461,     4,
     132,   467,     4,   164,   473,     4,   182,   479,  1171,    10,
      11,   483,   484,   485,   212,   216,   220,   224,   228,   697,
     698,    74,    81,   119,   145,   153,   167,   169,   183,   189,
     191,   193,   195,   605,   606,   607,   608,   609,   614,   615,
     620,   621,   626,   627,   632,   633,   638,   639,   655,   656,
     662,   663,   669,   670,   676,   677,   681,   682,    72,   555,
      10,    11,   558,   559,   560,    10,    11,   564,   565,   566,
      10,    11,   570,   571,   572,    10,    11,   576,   577,   578,
      10,    11,   582,   583,   584,   588,  1160,     4,   176,   507,
      10,   513,    57,    58,   512,  1118,  1139,  1140,  1141,  1142,
      10,   520,   519,  1118,  1139,    10,   527,   526,  1118,  1139,
      10,   532,    10,    11,   537,   538,   539,     6,     8,   398,
     399,   400,   401,  1173,  1171,  1171,   122,   171,   430,   431,
     432,   433,   134,   158,   156,   128,   132,   164,   182,     6,
     143,   146,   486,   487,   488,   489,    10,    11,   700,   701,
     702,    17,    23,    29,    34,   699,  1152,  1157,  1163,  1168,
      74,   607,    10,    11,   610,   611,   612,    10,    11,   616,
     617,   618,    10,    11,   622,   623,   624,    10,    11,   628,
     629,   630,    10,    11,   634,   635,   636,    32,   640,  1166,
     657,   658,   664,   665,   671,   672,   678,  1118,   683,  1160,
       4,   112,   561,     6,   110,   567,     6,   186,   573,     4,
     180,   579,     6,     7,   160,   585,  1169,    10,    11,   589,
     590,   591,   176,   514,  1169,     3,   521,  1169,   528,  1169,
       6,   533,   143,   146,   540,   541,   542,   543,  1171,   122,
     432,   434,   435,  1171,   146,   488,   490,   491,    76,   161,
     703,   704,   705,   706,  1171,  1171,  1171,  1171,     4,   168,
     613,     4,   170,   619,     4,   154,   625,     4,    82,   631,
       4,   120,   637,  1171,    10,    11,   641,   642,   643,    10,
     660,   659,  1118,  1139,    10,   667,   666,  1118,  1139,    10,
     674,   673,  1118,  1139,    10,   679,    10,    11,   684,   685,
     686,   112,   110,   186,   180,   160,   143,   146,   592,   593,
     594,   595,    94,  1171,    96,    92,    90,   146,   542,   544,
     545,    10,    11,   437,    45,    46,   436,  1118,  1127,  1128,
    1129,  1130,    10,    11,   493,    59,    60,   492,  1118,  1127,
    1143,  1144,  1145,  1146,    76,   151,   705,  1087,  1088,   707,
     708,     6,     6,     6,     6,   168,   170,   154,    82,   120,
       6,   177,   184,   644,   645,   646,   647,   661,  1169,   668,
    1169,   675,  1169,     6,   680,   143,   146,   687,   688,   689,
     690,   146,   594,   596,   597,    10,    11,   547,   546,  1118,
    1127,  1143,   172,     3,   144,     3,    30,  1089,  1164,    10,
     713,    36,    61,    63,   709,   710,   711,   712,  1171,  1171,
    1171,  1171,  1171,   184,   646,   648,   194,   196,   192,   190,
     146,   689,   691,   692,    10,    11,   599,   598,  1118,  1127,
    1143,   144,  1171,  1171,  1171,    10,    11,  1090,  1091,  1092,
     167,   714,   715,  1171,     3,     3,    10,    11,    41,    42,
     649,   650,   651,   652,  1110,  1111,  1112,  1113,  1118,  1135,
    1139,    10,    11,   694,   693,  1118,  1127,  1143,   144,     6,
     152,   165,  1093,  1094,  1095,  1096,   133,   730,   731,   716,
     717,   718,  1118,  1135,  1165,     6,  1171,  1171,     6,     7,
     178,   653,   654,     3,   144,  1171,   152,  1095,  1097,  1098,
     201,   736,   737,    10,    11,   732,   733,   734,    10,    11,
     719,   720,   721,   718,  1171,   178,  1171,    10,    11,  1100,
    1101,  1102,    21,  1099,  1110,  1118,  1127,  1155,   137,   856,
     857,    28,   738,  1162,     4,   134,   735,   168,   171,   722,
     723,   724,   725,    77,    79,    80,   166,  1103,  1104,  1105,
    1106,  1107,  1108,  1171,   107,   960,   961,    25,   858,  1159,
    1171,    10,    11,   739,   740,   741,   134,   168,   724,   726,
     727,     5,  1109,   166,  1105,     6,   149,  1064,  1065,    24,
     962,  1158,  1171,    10,    11,   859,   860,   861,     6,   271,
     742,   743,   744,    10,    11,   729,   728,  1118,  1135,    78,
    1171,   162,    27,  1066,  1161,  1171,    10,    11,   963,   964,
     965,     6,   271,   862,   863,   864,  1171,   202,   197,   756,
     757,    33,   745,  1167,   172,  1171,    10,    11,  1067,  1068,
    1069,     6,   113,   966,   967,   968,  1171,   138,   101,   876,
     877,    22,   865,  1156,   101,   772,   773,   758,  1167,  1171,
      10,    11,   746,   747,   748,     6,   147,   150,  1070,  1071,
    1072,  1073,  1171,   108,   101,   980,   981,    16,   969,  1151,
     931,    10,    11,   878,   879,   880,  1171,    10,    11,   866,
     867,   868,   827,    10,    11,   774,   775,   776,    10,    11,
     759,   760,   761,     6,   199,   272,   749,   750,   751,   752,
    1171,   150,  1072,  1074,  1075,  1035,    10,    11,   982,   983,
     984,  1171,    10,    11,   970,   971,   972,   143,   932,   933,
      99,   881,   882,   883,     6,   135,   272,   869,   870,   871,
     872,   143,   828,   829,    99,   777,   778,   779,   198,   199,
     762,   763,   764,   765,  1171,   272,   751,   753,    10,    11,
    1077,  1078,  1079,  1076,  1110,  1118,  1127,  1143,  1155,   143,
    1036,  1037,    99,   985,   986,   987,     6,   105,   114,   973,
     974,   975,   976,   934,   935,   102,    85,   889,   890,    18,
     884,  1153,  1171,   272,   871,   873,   830,   831,   102,    85,
     785,   786,   780,  1153,   198,   764,   766,    10,    37,   754,
     755,  1126,  1127,    77,    79,    80,   148,  1080,  1081,  1082,
    1083,  1084,  1085,  1038,  1039,   102,    85,   993,   994,   988,
    1153,  1171,   114,   975,   977,    10,    11,   937,   938,   939,
      19,    51,    52,    53,    54,   936,  1118,  1122,  1123,  1124,
    1125,  1127,  1131,  1132,  1133,  1134,  1135,  1143,  1154,  1156,
      87,   896,   897,   891,  1153,  1171,    10,    11,   885,   886,
     887,    10,   874,   875,  1126,  1127,    10,    11,   833,   834,
     835,    55,    56,   832,  1118,  1122,  1127,  1135,  1143,  1147,
    1148,  1149,  1150,  1154,  1167,    87,   792,   793,   787,  1153,
      10,    11,   781,   782,   783,    10,    11,   767,   768,   769,
     770,  1126,  1127,  1169,  1171,     5,  1086,   148,  1082,    10,
      11,  1041,  1042,  1043,    49,    50,  1040,  1114,  1115,  1116,
    1117,  1118,  1122,  1127,  1135,  1143,  1151,  1154,    87,  1000,
    1001,   995,  1153,    10,    11,   989,   990,   991,    10,   978,
     979,  1126,  1127,   117,   135,   144,   940,   941,   942,   943,
     950,   951,   952,  1171,     3,     3,    83,   903,   904,   898,
    1153,    10,    11,   892,   893,   894,     6,    97,   888,  1202,
    1203,  1210,  1169,   117,   144,   199,   836,   837,   838,   839,
     846,   847,   848,     3,    83,   799,   800,   794,  1153,    10,
      11,   788,   789,   790,   784,  1202,     4,   200,   771,   200,
       6,    78,   105,   117,   144,  1044,  1045,  1046,  1047,  1054,
    1055,  1056,     3,    83,  1007,  1008,  1002,  1153,    10,    11,
     996,   997,   998,   992,  1202,  1169,   144,   942,   944,   951,
     953,   954,     6,  1171,  1171,   129,   910,   911,   905,  1153,
      10,    11,   899,   900,   901,   895,  1202,  1171,    40,  1214,
     100,   115,  1204,  1205,   136,   144,   838,   840,   847,   849,
     850,  1171,   129,   806,   807,   801,  1153,    10,    11,   795,
     796,   797,   791,  1202,   100,   200,  1171,   144,  1046,  1048,
    1055,  1057,  1058,  1171,   129,  1014,  1015,  1009,  1153,    10,
      11,  1003,  1004,  1005,   999,  1202,   100,   106,    10,    11,
     945,   946,   947,   948,  1126,  1127,    10,    11,   956,   957,
     958,   955,  1118,  1143,  1153,  1171,   173,   917,   918,   912,
    1153,    10,    11,   906,   907,   908,   902,  1202,    86,     8,
      10,    11,  1211,  1212,  1213,  1206,  1207,    10,    11,   841,
     842,   843,   844,  1126,  1127,    10,    11,   852,   853,   854,
     851,  1118,  1143,  1153,   173,   813,   814,   808,  1153,    10,
      11,   802,   803,   804,   798,  1202,    86,    10,    11,  1049,
    1050,  1051,  1052,  1126,  1127,    10,    11,  1060,  1061,  1062,
    1059,  1118,  1143,  1153,   173,  1021,  1022,  1016,  1153,    10,
      11,  1010,  1011,  1012,  1006,  1202,    86,     4,     6,     7,
     136,   949,  1170,   959,  1202,   187,   924,   925,   919,  1153,
      10,    11,   913,   914,   915,   909,  1202,    88,     6,     4,
      98,    10,  1209,    38,    39,  1208,  1215,  1216,   200,   845,
    1170,   855,  1202,   187,   820,   821,   815,  1153,    10,    11,
     809,   810,   811,   805,  1202,    88,   106,  1053,  1170,  1063,
    1202,   187,  1028,  1029,  1023,  1153,    10,    11,  1017,  1018,
    1019,  1013,  1202,    88,   136,   118,   926,  1153,    10,    11,
     920,   921,   922,   916,  1202,    84,     8,    98,     6,     8,
       8,   200,   118,   822,  1153,    10,    11,   816,   817,   818,
     812,  1202,    84,   106,   118,  1030,  1153,    10,    11,  1024,
    1025,  1026,  1020,  1202,    84,    10,    11,   927,   928,   929,
     923,  1202,   130,   116,     6,     6,    10,    11,   823,   824,
     825,   819,  1202,   130,    10,    11,  1031,  1032,  1033,  1027,
    1202,   130,   930,  1202,   174,     8,     8,   826,  1202,   174,
    1034,  1202,   174,   188,   188,   188
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
std::cout << "expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter << std::endl;
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
std::cout << "IntVec: expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter + osglData->osglMult << std::endl;
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
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1198:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1199:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
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


