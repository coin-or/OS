
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
     INDEXSTART = 524,
     INDEXEND = 525,
     VALUESTART = 526,
     VALUEEND = 527,
     INDEXESSTART = 528,
     INDEXESEND = 529,
     VALUESSTART = 530,
     VALUESEND = 531,
     VARREFERENCEELEMENTSSTART = 532,
     VARREFERENCEELEMENTSEND = 533,
     LINEARELEMENTSSTART = 534,
     LINEARELEMENTSEND = 535,
     GENERALELEMENTSSTART = 536,
     GENERALELEMENTSEND = 537,
     CONREFERENCEELEMENTSSTART = 538,
     CONREFERENCEELEMENTSEND = 539,
     VALUETYPEATT = 540,
     OBJREFERENCEELEMENTSSTART = 541,
     OBJREFERENCEELEMENTSEND = 542,
     PATTERNELEMENTSSTART = 543,
     PATTERNELEMENTSEND = 544,
     TRANSFORMATIONSTART = 545,
     TRANSFORMATIONEND = 546,
     COLOFFSETSTART = 547,
     COLOFFSETEND = 548,
     ROWOFFSETSTART = 549,
     ROWOFFSETEND = 550,
     EMPTYROWMAJORATT = 551,
     ROWMAJORATT = 552,
     BLOCKROWIDXATT = 553,
     BLOCKCOLIDXATT = 554,
     DUMMY = 555,
     NONLINEAREXPRESSIONSSTART = 556,
     NONLINEAREXPRESSIONSEND = 557,
     NUMBEROFNONLINEAREXPRESSIONS = 558,
     NLSTART = 559,
     NLEND = 560,
     MATRIXEXPRESSIONSSTART = 561,
     MATRIXEXPRESSIONSEND = 562,
     NUMBEROFEXPR = 563,
     EXPRSTART = 564,
     EXPREND = 565,
     NUMBEROFMATRIXTERMSATT = 566,
     MATRIXTERMSTART = 567,
     MATRIXTERMEND = 568,
     POWERSTART = 569,
     POWEREND = 570,
     PLUSSTART = 571,
     PLUSEND = 572,
     MINUSSTART = 573,
     MINUSEND = 574,
     DIVIDESTART = 575,
     DIVIDEEND = 576,
     LNSTART = 577,
     LNEND = 578,
     SQRTSTART = 579,
     SQRTEND = 580,
     SUMSTART = 581,
     SUMEND = 582,
     PRODUCTSTART = 583,
     PRODUCTEND = 584,
     EXPSTART = 585,
     EXPEND = 586,
     NEGATESTART = 587,
     NEGATEEND = 588,
     IFSTART = 589,
     IFEND = 590,
     SQUARESTART = 591,
     SQUAREEND = 592,
     COSSTART = 593,
     COSEND = 594,
     SINSTART = 595,
     SINEND = 596,
     VARIABLESTART = 597,
     VARIABLEEND = 598,
     ABSSTART = 599,
     ABSEND = 600,
     ERFSTART = 601,
     ERFEND = 602,
     MAXSTART = 603,
     MAXEND = 604,
     ALLDIFFSTART = 605,
     ALLDIFFEND = 606,
     MINSTART = 607,
     MINEND = 608,
     ESTART = 609,
     EEND = 610,
     PISTART = 611,
     PIEND = 612,
     TIMESSTART = 613,
     TIMESEND = 614,
     NUMBERSTART = 615,
     NUMBEREND = 616,
     MATRIXDETERMINANTSTART = 617,
     MATRIXDETERMINANTEND = 618,
     MATRIXTRACESTART = 619,
     MATRIXTRACEEND = 620,
     MATRIXTOSCALARSTART = 621,
     MATRIXTOSCALAREND = 622,
     MATRIXDIAGONALSTART = 623,
     MATRIXDIAGONALEND = 624,
     MATRIXDOTTIMESSTART = 625,
     MATRIXDOTTIMESEND = 626,
     MATRIXLOWERTRIANGLESTART = 627,
     MATRIXLOWERTRIANGLEEND = 628,
     MATRIXUPPERTRIANGLESTART = 629,
     MATRIXUPPERTRIANGLEEND = 630,
     MATRIXMERGESTART = 631,
     MATRIXMERGEEND = 632,
     MATRIXMINUSSTART = 633,
     MATRIXMINUSEND = 634,
     MATRIXNEGATESTART = 635,
     MATRIXNEGATEEND = 636,
     MATRIXPLUSSTART = 637,
     MATRIXPLUSEND = 638,
     MATRIXTIMESSTART = 639,
     MATRIXTIMESEND = 640,
     MATRIXPRODUCTSTART = 641,
     MATRIXPRODUCTEND = 642,
     MATRIXSCALARTIMESSTART = 643,
     MATRIXSCALARTIMESEND = 644,
     MATRIXSUBMATRIXATSTART = 645,
     MATRIXSUBMATRIXATEND = 646,
     MATRIXTRANSPOSESTART = 647,
     MATRIXTRANSPOSEEND = 648,
     MATRIXREFERENCESTART = 649,
     MATRIXREFERENCEEND = 650,
     IDENTITYMATRIXSTART = 651,
     IDENTITYMATRIXEND = 652,
     MATRIXINVERSESTART = 653,
     MATRIXINVERSEEND = 654,
     EMPTYINCLUDEDIAGONALATT = 655,
     INCLUDEDIAGONALATT = 656,
     IDATT = 657
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
#define INDEXSTART 524
#define INDEXEND 525
#define VALUESTART 526
#define VALUEEND 527
#define INDEXESSTART 528
#define INDEXESEND 529
#define VALUESSTART 530
#define VALUESEND 531
#define VARREFERENCEELEMENTSSTART 532
#define VARREFERENCEELEMENTSEND 533
#define LINEARELEMENTSSTART 534
#define LINEARELEMENTSEND 535
#define GENERALELEMENTSSTART 536
#define GENERALELEMENTSEND 537
#define CONREFERENCEELEMENTSSTART 538
#define CONREFERENCEELEMENTSEND 539
#define VALUETYPEATT 540
#define OBJREFERENCEELEMENTSSTART 541
#define OBJREFERENCEELEMENTSEND 542
#define PATTERNELEMENTSSTART 543
#define PATTERNELEMENTSEND 544
#define TRANSFORMATIONSTART 545
#define TRANSFORMATIONEND 546
#define COLOFFSETSTART 547
#define COLOFFSETEND 548
#define ROWOFFSETSTART 549
#define ROWOFFSETEND 550
#define EMPTYROWMAJORATT 551
#define ROWMAJORATT 552
#define BLOCKROWIDXATT 553
#define BLOCKCOLIDXATT 554
#define DUMMY 555
#define NONLINEAREXPRESSIONSSTART 556
#define NONLINEAREXPRESSIONSEND 557
#define NUMBEROFNONLINEAREXPRESSIONS 558
#define NLSTART 559
#define NLEND 560
#define MATRIXEXPRESSIONSSTART 561
#define MATRIXEXPRESSIONSEND 562
#define NUMBEROFEXPR 563
#define EXPRSTART 564
#define EXPREND 565
#define NUMBEROFMATRIXTERMSATT 566
#define MATRIXTERMSTART 567
#define MATRIXTERMEND 568
#define POWERSTART 569
#define POWEREND 570
#define PLUSSTART 571
#define PLUSEND 572
#define MINUSSTART 573
#define MINUSEND 574
#define DIVIDESTART 575
#define DIVIDEEND 576
#define LNSTART 577
#define LNEND 578
#define SQRTSTART 579
#define SQRTEND 580
#define SUMSTART 581
#define SUMEND 582
#define PRODUCTSTART 583
#define PRODUCTEND 584
#define EXPSTART 585
#define EXPEND 586
#define NEGATESTART 587
#define NEGATEEND 588
#define IFSTART 589
#define IFEND 590
#define SQUARESTART 591
#define SQUAREEND 592
#define COSSTART 593
#define COSEND 594
#define SINSTART 595
#define SINEND 596
#define VARIABLESTART 597
#define VARIABLEEND 598
#define ABSSTART 599
#define ABSEND 600
#define ERFSTART 601
#define ERFEND 602
#define MAXSTART 603
#define MAXEND 604
#define ALLDIFFSTART 605
#define ALLDIFFEND 606
#define MINSTART 607
#define MINEND 608
#define ESTART 609
#define EEND 610
#define PISTART 611
#define PIEND 612
#define TIMESSTART 613
#define TIMESEND 614
#define NUMBERSTART 615
#define NUMBEREND 616
#define MATRIXDETERMINANTSTART 617
#define MATRIXDETERMINANTEND 618
#define MATRIXTRACESTART 619
#define MATRIXTRACEEND 620
#define MATRIXTOSCALARSTART 621
#define MATRIXTOSCALAREND 622
#define MATRIXDIAGONALSTART 623
#define MATRIXDIAGONALEND 624
#define MATRIXDOTTIMESSTART 625
#define MATRIXDOTTIMESEND 626
#define MATRIXLOWERTRIANGLESTART 627
#define MATRIXLOWERTRIANGLEEND 628
#define MATRIXUPPERTRIANGLESTART 629
#define MATRIXUPPERTRIANGLEEND 630
#define MATRIXMERGESTART 631
#define MATRIXMERGEEND 632
#define MATRIXMINUSSTART 633
#define MATRIXMINUSEND 634
#define MATRIXNEGATESTART 635
#define MATRIXNEGATEEND 636
#define MATRIXPLUSSTART 637
#define MATRIXPLUSEND 638
#define MATRIXTIMESSTART 639
#define MATRIXTIMESEND 640
#define MATRIXPRODUCTSTART 641
#define MATRIXPRODUCTEND 642
#define MATRIXSCALARTIMESSTART 643
#define MATRIXSCALARTIMESEND 644
#define MATRIXSUBMATRIXATSTART 645
#define MATRIXSUBMATRIXATEND 646
#define MATRIXTRANSPOSESTART 647
#define MATRIXTRANSPOSEEND 648
#define MATRIXREFERENCESTART 649
#define MATRIXREFERENCEEND 650
#define IDENTITYMATRIXSTART 651
#define IDENTITYMATRIXEND 652
#define MATRIXINVERSESTART 653
#define MATRIXINVERSEEND 654
#define EMPTYINCLUDEDIAGONALATT 655
#define INCLUDEDIAGONALATT 656
#define IDATT 657




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
#define YYNTOKENS  407
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  815
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1199
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1626

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   657

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   404,
     406,     2,     2,   405,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   403,     2,     2,     2,     2,     2,     2,     2,
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
     395,   396,   397,   398,   399,   400,   401,   402
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
     408,     0,    -1,   409,   417,   415,    -1,   410,   411,   412,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   413,    -1,
     414,    -1,    11,    -1,    10,   417,   415,    -1,   416,    -1,
      15,    -1,    -1,   418,   419,   499,   553,   605,   700,    -1,
      -1,  1179,    -1,    -1,   420,   421,    -1,    67,    -1,   422,
      -1,   423,    -1,    10,    68,    -1,    11,    -1,    10,   424,
      68,    -1,   425,    -1,   426,    -1,   425,   426,    -1,   427,
      -1,   443,    -1,   449,    -1,   455,    -1,   461,    -1,   467,
      -1,   473,    -1,   479,    -1,   485,    -1,   428,   429,   432,
      -1,   121,    -1,   430,    -1,   431,    -1,   430,   431,    -1,
    1140,    -1,  1123,    -1,  1170,    -1,   433,    -1,   434,    -1,
      10,   122,    -1,    11,    -1,    10,   435,   122,    -1,   436,
      -1,   437,    -1,   436,   437,    -1,   438,   439,   442,    -1,
     171,    -1,   440,    -1,    -1,   440,   441,    -1,  1132,    -1,
    1123,    -1,    10,   172,    -1,    11,    -1,   444,   445,    -1,
     133,    -1,   446,    -1,   447,    -1,    10,   134,    -1,    11,
      -1,    10,   448,   134,    -1,     4,    -1,   450,   451,    -1,
     157,    -1,   452,    -1,   453,    -1,    10,   158,    -1,    11,
      -1,    10,   454,   158,    -1,     4,    -1,   456,   457,    -1,
     155,    -1,   458,    -1,   459,    -1,    10,   156,    -1,    11,
      -1,    10,   460,   156,    -1,     4,    -1,   462,   463,    -1,
     127,    -1,   464,    -1,   465,    -1,    10,   128,    -1,    11,
      -1,    10,   466,   128,    -1,     4,    -1,   468,   469,    -1,
     131,    -1,   470,    -1,   471,    -1,    10,   132,    -1,    11,
      -1,    10,   472,   132,    -1,     4,    -1,   474,   475,    -1,
     163,    -1,   476,    -1,   477,    -1,    10,   164,    -1,    11,
      -1,    10,   478,   164,    -1,     4,    -1,   480,   481,    -1,
     181,    -1,   482,    -1,   483,    -1,    10,   182,    -1,    11,
      -1,    10,   484,   182,    -1,     4,    -1,   486,   487,   488,
      -1,   145,    -1,  1165,    -1,   489,    -1,   490,    -1,    10,
     146,    -1,    11,    -1,    10,   491,   146,    -1,   492,    -1,
     493,    -1,   492,   493,    -1,   494,   495,   498,    -1,   143,
      -1,   496,    -1,    -1,   496,   497,    -1,  1132,    -1,  1148,
      -1,  1123,    -1,    10,   144,    -1,    11,    -1,    -1,   500,
     501,    -1,    69,    -1,   502,    -1,   503,    -1,    10,    70,
      -1,    11,    -1,    10,   504,    70,    -1,   505,    -1,   506,
      -1,   505,   506,    -1,   507,    -1,   513,    -1,   520,    -1,
     527,    -1,   534,    -1,   539,    -1,   508,   509,    -1,   175,
      -1,   510,    -1,   511,    -1,    10,   176,    -1,    11,    -1,
      10,   512,   176,    -1,     4,    -1,   514,   515,   518,    -1,
      93,    -1,   516,    -1,    -1,   516,   517,    -1,  1144,    -1,
    1123,    -1,    10,   519,    94,    -1,  1174,    -1,   521,   522,
     525,    -1,    95,    -1,   523,    -1,    -1,   523,   524,    -1,
    1144,    -1,  1123,    -1,    10,   526,    96,    -1,  1174,    -1,
     528,   529,   532,    -1,    91,    -1,   530,    -1,    -1,   530,
     531,    -1,  1144,    -1,  1123,    -1,    10,   533,    92,    -1,
    1174,    -1,   535,   536,   537,    -1,    89,    -1,    -1,  1123,
      -1,    10,   538,    90,    -1,     6,    -1,   540,   541,   542,
      -1,   145,    -1,  1165,    -1,   543,    -1,   544,    -1,    10,
     146,    -1,    11,    -1,    10,   545,   146,    -1,   546,    -1,
     547,    -1,   546,   547,    -1,   548,   549,   552,    -1,   143,
      -1,   550,    -1,    -1,   550,   551,    -1,  1132,    -1,  1148,
      -1,  1123,    -1,    10,   144,    -1,    11,    -1,    -1,   554,
     555,    -1,    71,    -1,   556,    -1,   557,    -1,    10,    72,
      -1,    11,    -1,    10,   558,    72,    -1,   559,    -1,   560,
      -1,   559,   560,    -1,   561,    -1,   567,    -1,   573,    -1,
     579,    -1,   585,    -1,   591,    -1,   562,   563,    -1,   111,
      -1,   564,    -1,   565,    -1,    10,   112,    -1,    11,    -1,
      10,   566,   112,    -1,     4,    -1,   568,   569,    -1,   109,
      -1,   570,    -1,   571,    -1,    10,   110,    -1,    11,    -1,
      10,   572,   110,    -1,     6,    -1,   574,   575,    -1,   185,
      -1,   576,    -1,   577,    -1,    10,   186,    -1,    11,    -1,
      10,   578,   186,    -1,     6,    -1,   580,   581,    -1,   179,
      -1,   582,    -1,   583,    -1,    10,   180,    -1,    11,    -1,
      10,   584,   180,    -1,     4,    -1,   586,   587,    -1,   159,
      -1,   588,    -1,   589,    -1,    10,   160,    -1,    11,    -1,
      10,   590,   160,    -1,  1174,    -1,   592,   593,   594,    -1,
     145,    -1,  1165,    -1,   595,    -1,   596,    -1,    10,   146,
      -1,    11,    -1,    10,   597,   146,    -1,   598,    -1,   599,
      -1,   598,   599,    -1,   600,   601,   604,    -1,   143,    -1,
     602,    -1,    -1,   602,   603,    -1,  1132,    -1,  1148,    -1,
    1123,    -1,    10,   144,    -1,    11,    -1,    -1,   606,   607,
      -1,    73,    -1,   608,    -1,   609,    -1,    10,    74,    -1,
      11,    -1,    10,   610,    74,    -1,   611,    -1,   612,    -1,
     611,   612,    -1,   613,    -1,   619,    -1,   625,    -1,   631,
      -1,   637,    -1,   643,    -1,   660,    -1,   667,    -1,   674,
      -1,   681,    -1,   686,    -1,   614,   615,    -1,   167,    -1,
     616,    -1,   617,    -1,    10,   168,    -1,    11,    -1,    10,
     618,   168,    -1,     4,    -1,   620,   621,    -1,   169,    -1,
     622,    -1,   623,    -1,    10,   170,    -1,    11,    -1,    10,
     624,   170,    -1,     4,    -1,   626,   627,    -1,   153,    -1,
     628,    -1,   629,    -1,    10,   154,    -1,    11,    -1,    10,
     630,   154,    -1,     4,    -1,   632,   633,    -1,    81,    -1,
     634,    -1,   635,    -1,    10,    82,    -1,    11,    -1,    10,
     636,    82,    -1,     4,    -1,   638,   639,    -1,   119,    -1,
     640,    -1,   641,    -1,    10,   120,    -1,    11,    -1,    10,
     642,   120,    -1,     4,    -1,   644,   645,   646,    -1,   183,
      -1,  1171,    -1,   647,    -1,   648,    -1,    10,   184,    -1,
      11,    -1,    10,   649,   184,    -1,   650,    -1,   651,    -1,
     650,   651,    -1,   652,   653,   655,    -1,   177,    -1,    -1,
     653,   654,    -1,  1144,    -1,  1140,    -1,  1115,    -1,  1123,
      -1,   656,    -1,   657,    -1,    10,   178,    -1,    11,    -1,
      10,   658,   178,    -1,   659,    -1,     7,    -1,     6,    -1,
     661,   662,   665,    -1,   193,    -1,   663,    -1,    -1,   663,
     664,    -1,  1144,    -1,  1123,    -1,    10,   666,   194,    -1,
    1174,    -1,   668,   669,   672,    -1,   195,    -1,   670,    -1,
      -1,   670,   671,    -1,  1144,    -1,  1123,    -1,    10,   673,
     196,    -1,  1174,    -1,   675,   676,   679,    -1,   191,    -1,
     677,    -1,    -1,   677,   678,    -1,  1144,    -1,  1123,    -1,
      10,   680,   192,    -1,  1174,    -1,   682,   683,   684,    -1,
     189,    -1,    -1,  1123,    -1,    10,   685,   190,    -1,     6,
      -1,   687,   688,   689,    -1,   145,    -1,  1165,    -1,   690,
      -1,   691,    -1,    10,   146,    -1,    11,    -1,    10,   692,
     146,    -1,   693,    -1,   694,    -1,   693,   694,    -1,   695,
     696,   699,    -1,   143,    -1,   697,    -1,    -1,   697,   698,
      -1,  1132,    -1,  1148,    -1,  1123,    -1,    10,   144,    -1,
      11,    -1,    -1,   701,   702,   705,    -1,    75,    -1,   703,
      -1,    -1,   703,   704,    -1,  1168,    -1,  1173,    -1,  1157,
      -1,  1162,    -1,   706,    -1,   707,    -1,    10,    76,    -1,
      11,    -1,    10,   708,    76,    -1,   709,  1092,    -1,   710,
      -1,   709,   710,    -1,   711,   712,   718,    -1,   161,    -1,
     713,    -1,    -1,   713,   714,    -1,   715,    -1,   716,    -1,
     717,    -1,    36,  1176,     6,  1176,    -1,    63,     3,  1176,
      -1,    61,     3,  1176,    -1,    10,   719,   735,   741,   861,
     965,  1069,   162,    -1,   720,   721,   724,    -1,   167,    -1,
     722,    -1,   723,    -1,   722,   723,    -1,  1140,    -1,  1123,
      -1,  1170,    -1,   725,    -1,   726,    -1,    10,   168,    -1,
      11,    -1,    10,   727,   168,    -1,   728,    -1,   729,    -1,
     728,   729,    -1,   730,   731,   734,    -1,   171,    -1,   732,
      -1,    -1,   732,   733,    -1,  1140,    -1,  1123,    -1,    10,
     172,    -1,    11,    -1,    -1,   736,   737,    -1,   133,    -1,
     738,    -1,   739,    -1,    10,   134,    -1,    11,    -1,    10,
     740,   134,    -1,     4,    -1,    -1,   742,   743,   744,    -1,
     201,    -1,    -1,  1167,    -1,   745,    -1,   746,    -1,    11,
      -1,    10,   747,   202,    -1,   748,   761,   777,   832,    -1,
      -1,   749,   750,   751,    -1,   275,    -1,  1172,    -1,   752,
      -1,   753,    -1,    10,   276,    -1,    11,    -1,    10,   754,
     276,    -1,   755,    -1,   756,    -1,   755,   756,    -1,   757,
     758,   760,    -1,   199,    -1,    -1,   758,   759,    -1,  1131,
      -1,  1132,    -1,    10,  1174,   200,    -1,    -1,   762,   763,
     764,    -1,   197,    -1,  1172,    -1,   765,    -1,   766,    -1,
      10,   198,    -1,    11,    -1,    10,   767,   198,    -1,   768,
      -1,   769,    -1,   768,   769,    -1,   770,   771,   773,    -1,
     199,    -1,    -1,   771,   772,    -1,  1131,    -1,  1132,    -1,
     774,    -1,   775,    -1,    10,   200,    -1,    11,    -1,    10,
     776,   200,    -1,     4,    -1,    -1,   778,   779,    -1,   101,
      -1,   780,    -1,   781,    -1,    11,    -1,    10,   782,   102,
      -1,   783,   790,   797,   804,   811,   818,   825,    -1,    -1,
     784,   785,   786,    -1,    99,    -1,  1158,    -1,   787,    -1,
     788,    -1,    11,    -1,    10,   789,   100,    -1,  1207,    -1,
      -1,   791,   792,   793,    -1,    85,    -1,  1158,    -1,   794,
      -1,   795,    -1,    11,    -1,    10,   796,    86,    -1,  1207,
      -1,    -1,   798,   799,   800,    -1,    87,    -1,  1158,    -1,
     801,    -1,   802,    -1,    11,    -1,    10,   803,    88,    -1,
    1207,    -1,    -1,   805,   806,   807,    -1,    83,    -1,  1158,
      -1,   808,    -1,   809,    -1,    11,    -1,    10,   810,    84,
      -1,  1207,    -1,    -1,   812,   813,   814,    -1,   129,    -1,
    1158,    -1,   815,    -1,   816,    -1,    11,    -1,    10,   817,
     130,    -1,  1207,    -1,    -1,   819,   820,   821,    -1,   173,
      -1,  1158,    -1,   822,    -1,   823,    -1,    11,    -1,    10,
     824,   174,    -1,  1207,    -1,    -1,   826,   827,   828,    -1,
     187,    -1,  1158,    -1,   829,    -1,   830,    -1,    11,    -1,
      10,   831,   188,    -1,  1207,    -1,    -1,   832,   833,    -1,
     834,   835,   838,    -1,   143,    -1,   836,    -1,    -1,   836,
     837,    -1,  1172,    -1,  1159,    -1,  1148,    -1,  1132,    -1,
    1140,    -1,  1152,    -1,  1127,    -1,  1123,    -1,   839,    -1,
     840,    -1,    10,   144,    -1,    11,    -1,    10,   841,   144,
      -1,   842,    -1,   851,    -1,   843,    -1,   842,   843,    -1,
     844,   845,   847,    -1,   199,    -1,    -1,   845,   846,    -1,
    1131,    -1,  1132,    -1,   848,    -1,   849,    -1,    10,   200,
      -1,    11,    -1,    10,   850,   200,    -1,  1175,    -1,   852,
      -1,   851,   852,    -1,   853,   854,   857,    -1,   117,    -1,
     855,    -1,    -1,   855,   856,    -1,  1158,    -1,  1148,    -1,
    1123,    -1,   858,    -1,   859,    -1,    11,    -1,    10,   860,
     118,    -1,  1207,    -1,    -1,   862,   863,   864,    -1,   137,
      -1,    -1,  1164,    -1,   865,    -1,   866,    -1,    11,    -1,
      10,   867,   138,    -1,   868,   881,   936,    -1,    -1,   869,
     870,   871,    -1,   275,    -1,  1161,    -1,   872,    -1,   873,
      -1,    10,   276,    -1,    11,    -1,    10,   874,   276,    -1,
     875,    -1,   876,    -1,   875,   876,    -1,   877,   878,   880,
      -1,   135,    -1,    -1,   878,   879,    -1,  1131,    -1,  1132,
      -1,    10,  1174,   136,    -1,    -1,   882,   883,    -1,   101,
      -1,   884,    -1,   885,    -1,    11,    -1,    10,   886,   102,
      -1,   887,   894,   901,   908,   915,   922,   929,    -1,    -1,
     888,   889,   890,    -1,    99,    -1,  1158,    -1,   891,    -1,
     892,    -1,    11,    -1,    10,   893,   100,    -1,  1207,    -1,
      -1,   895,   896,   897,    -1,    85,    -1,  1158,    -1,   898,
      -1,   899,    -1,    11,    -1,    10,   900,    86,    -1,  1207,
      -1,    -1,   902,   903,   904,    -1,    87,    -1,  1158,    -1,
     905,    -1,   906,    -1,    11,    -1,    10,   907,    88,    -1,
    1207,    -1,    -1,   909,   910,   911,    -1,    83,    -1,  1158,
      -1,   912,    -1,   913,    -1,    11,    -1,    10,   914,    84,
      -1,  1207,    -1,    -1,   916,   917,   918,    -1,   129,    -1,
    1158,    -1,   919,    -1,   920,    -1,    11,    -1,    10,   921,
     130,    -1,  1207,    -1,    -1,   923,   924,   925,    -1,   173,
      -1,  1158,    -1,   926,    -1,   927,    -1,    11,    -1,    10,
     928,   174,    -1,  1207,    -1,    -1,   930,   931,   932,    -1,
     187,    -1,  1158,    -1,   933,    -1,   934,    -1,    11,    -1,
      10,   935,   188,    -1,  1207,    -1,    -1,   936,   937,    -1,
     938,   939,   942,    -1,   143,    -1,   940,    -1,    -1,   940,
     941,    -1,  1161,    -1,  1159,    -1,  1148,    -1,  1132,    -1,
    1140,    -1,  1136,    -1,  1127,    -1,  1123,    -1,   943,    -1,
     944,    -1,    10,   144,    -1,    11,    -1,    10,   945,   144,
      -1,   946,    -1,   955,    -1,   947,    -1,   946,   947,    -1,
     948,   949,   951,    -1,   135,    -1,    -1,   949,   950,    -1,
    1131,    -1,  1132,    -1,   952,    -1,   953,    -1,    10,   136,
      -1,    11,    -1,    10,   954,   136,    -1,  1175,    -1,   956,
      -1,   955,   956,    -1,   957,   958,   961,    -1,   117,    -1,
     959,    -1,    -1,   959,   960,    -1,  1158,    -1,  1148,    -1,
    1123,    -1,   962,    -1,   963,    -1,    11,    -1,    10,   964,
     118,    -1,  1207,    -1,    -1,   966,   967,   968,    -1,   107,
      -1,    -1,  1163,    -1,   969,    -1,   970,    -1,    11,    -1,
      10,   971,   108,    -1,   972,   985,  1040,    -1,    -1,   973,
     974,   975,    -1,   113,    -1,  1156,    -1,   976,    -1,   977,
      -1,    10,   114,    -1,    11,    -1,    10,   978,   114,    -1,
     979,    -1,   980,    -1,   979,   980,    -1,   981,   982,   984,
      -1,   105,    -1,    -1,   982,   983,    -1,  1131,    -1,  1132,
      -1,    10,  1174,   106,    -1,    -1,   986,   987,    -1,   101,
      -1,   988,    -1,   989,    -1,    11,    -1,    10,   990,   102,
      -1,   991,   998,  1005,  1012,  1019,  1026,  1033,    -1,    -1,
     992,   993,   994,    -1,    99,    -1,  1158,    -1,   995,    -1,
     996,    -1,    11,    -1,    10,   997,   100,    -1,  1207,    -1,
      -1,   999,  1000,  1001,    -1,    85,    -1,  1158,    -1,  1002,
      -1,  1003,    -1,    11,    -1,    10,  1004,    86,    -1,  1207,
      -1,    -1,  1006,  1007,  1008,    -1,    87,    -1,  1158,    -1,
    1009,    -1,  1010,    -1,    11,    -1,    10,  1011,    88,    -1,
    1207,    -1,    -1,  1013,  1014,  1015,    -1,    83,    -1,  1158,
      -1,  1016,    -1,  1017,    -1,    11,    -1,    10,  1018,    84,
      -1,  1207,    -1,    -1,  1020,  1021,  1022,    -1,   129,    -1,
    1158,    -1,  1023,    -1,  1024,    -1,    11,    -1,    10,  1025,
     130,    -1,  1207,    -1,    -1,  1027,  1028,  1029,    -1,   173,
      -1,  1158,    -1,  1030,    -1,  1031,    -1,    11,    -1,    10,
    1032,   174,    -1,  1207,    -1,    -1,  1034,  1035,  1036,    -1,
     187,    -1,  1158,    -1,  1037,    -1,  1038,    -1,    11,    -1,
      10,  1039,   188,    -1,  1207,    -1,    -1,  1040,  1041,    -1,
    1042,  1043,  1046,    -1,   143,    -1,  1044,    -1,    -1,  1044,
    1045,    -1,  1156,    -1,  1159,    -1,  1148,    -1,  1132,    -1,
    1140,    -1,  1119,    -1,  1127,    -1,  1123,    -1,  1047,    -1,
    1048,    -1,    10,   144,    -1,    11,    -1,    10,  1049,   144,
      -1,  1050,    -1,  1059,    -1,  1051,    -1,  1050,  1051,    -1,
    1052,  1053,  1055,    -1,   105,    -1,    -1,  1053,  1054,    -1,
    1131,    -1,  1132,    -1,  1056,    -1,  1057,    -1,    10,   106,
      -1,    11,    -1,    10,  1058,   106,    -1,  1175,    -1,  1060,
      -1,  1059,  1060,    -1,  1061,  1062,  1065,    -1,   117,    -1,
    1063,    -1,    -1,  1063,  1064,    -1,  1158,    -1,  1148,    -1,
    1123,    -1,  1066,    -1,  1067,    -1,    11,    -1,    10,  1068,
     118,    -1,  1207,    -1,    -1,  1070,  1071,  1072,    -1,   149,
      -1,  1166,    -1,  1073,    -1,  1074,    -1,    10,   150,    -1,
      11,    -1,    10,  1075,   150,    -1,  1076,    -1,  1077,    -1,
    1076,  1077,    -1,  1078,  1079,  1082,    -1,   147,    -1,  1080,
      -1,    -1,  1080,  1081,    -1,  1132,    -1,  1148,    -1,  1115,
      -1,  1123,    -1,  1160,    -1,  1083,    -1,  1084,    -1,    10,
     148,    -1,    11,    -1,    10,  1085,   148,    -1,  1086,    -1,
    1087,    -1,  1086,  1087,    -1,  1088,    -1,  1089,    -1,  1090,
      -1,    79,    -1,    80,    -1,    77,  1091,    78,    -1,     5,
      -1,    -1,  1093,  1094,  1095,    -1,   151,    -1,  1169,    -1,
    1096,    -1,  1097,    -1,    10,   152,    -1,    11,    -1,    10,
    1098,   152,    -1,  1099,    -1,  1100,    -1,  1099,  1100,    -1,
    1101,  1102,  1105,    -1,   165,    -1,  1103,    -1,    -1,  1103,
    1104,    -1,  1132,    -1,  1115,    -1,  1123,    -1,  1160,    -1,
    1106,    -1,  1107,    -1,    10,   166,    -1,    11,    -1,    10,
    1108,   166,    -1,  1109,    -1,  1110,    -1,  1109,  1110,    -1,
    1111,    -1,  1112,    -1,  1113,    -1,    79,    -1,    80,    -1,
      77,  1114,    78,    -1,     5,    -1,  1116,    -1,  1117,    -1,
    1118,    -1,    42,    -1,    41,     3,  1176,    -1,  1120,    -1,
    1121,    -1,  1122,    -1,    50,    -1,    49,     3,  1176,    -1,
    1124,    -1,  1125,    -1,  1126,    -1,    44,    -1,    43,     3,
    1176,    -1,  1128,    -1,  1129,    -1,  1130,    -1,    52,    -1,
      51,     3,  1176,    -1,    37,  1176,     6,  1176,    -1,  1133,
      -1,  1134,    -1,  1135,    -1,    46,    -1,    45,     3,  1176,
      -1,  1137,    -1,  1138,    -1,  1139,    -1,    54,    -1,    53,
       3,  1176,    -1,  1141,    -1,  1142,    -1,  1143,    -1,    48,
      -1,    47,     3,  1176,    -1,  1145,    -1,  1146,    -1,  1147,
      -1,    58,    -1,    57,     3,  1176,    -1,  1149,    -1,  1150,
      -1,  1151,    -1,    60,    -1,    59,     3,  1176,    -1,  1153,
      -1,  1154,    -1,  1155,    -1,    56,    -1,    55,     3,  1176,
      -1,    16,  1176,     6,  1176,    -1,    17,  1176,     6,  1176,
      -1,    18,  1176,     6,  1176,    -1,    19,  1176,     6,  1176,
      -1,    21,  1176,     6,  1176,    -1,    22,  1176,     6,  1176,
      -1,    23,  1176,     6,  1176,    -1,    24,  1176,     6,  1176,
      -1,    25,  1176,     6,  1176,    -1,    26,  1176,     6,  1176,
      -1,    27,  1176,     6,  1176,    -1,    28,  1176,     6,  1176,
      -1,    29,  1176,     6,  1176,    -1,    30,  1176,     6,  1176,
      -1,    31,  1176,     6,  1176,    -1,    32,  1176,     6,  1176,
      -1,    33,  1176,     6,  1176,    -1,    34,  1176,     6,  1176,
      -1,     6,    -1,     7,    -1,     4,    -1,     6,    -1,     7,
      -1,  1177,     8,    -1,    -1,  1177,  1178,    -1,   403,    -1,
     404,    -1,   405,    -1,   406,    -1,  1180,  1181,    -1,    65,
      -1,  1182,    -1,  1183,    -1,    11,    -1,    10,  1184,    66,
      -1,  1185,    -1,    -1,  1185,  1186,    -1,  1187,    -1,  1191,
      -1,  1195,    -1,  1199,    -1,  1203,    -1,  1188,    -1,  1189,
      -1,  1190,    -1,   214,    -1,   213,    -1,   211,     5,   212,
      -1,  1192,    -1,  1193,    -1,  1194,    -1,   218,    -1,   217,
      -1,   215,     5,   216,    -1,  1196,    -1,  1197,    -1,  1198,
      -1,   222,    -1,   221,    -1,   219,     5,   220,    -1,  1200,
      -1,  1201,    -1,  1202,    -1,   226,    -1,   225,    -1,   223,
       5,   224,    -1,  1204,    -1,  1205,    -1,  1206,    -1,   230,
      -1,   229,    -1,   227,     5,   228,    -1,  1208,    -1,  1215,
      -1,    -1,  1208,  1209,    -1,  1210,  1211,  1214,    -1,   115,
      -1,  1212,    -1,    -1,  1212,  1213,    -1,  1221,    -1,  1220,
      -1,    10,     6,   116,    -1,    97,  1219,  1216,    -1,  1217,
      -1,  1218,    -1,    10,    98,    -1,    11,    -1,    10,     4,
      98,    -1,    40,     8,     6,     8,    -1,    38,     8,     6,
       8,    -1,    39,     8,     6,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   336,   336,   337,   339,   346,   356,   356,   358,   358,
     360,   362,   364,   373,   374,   377,   386,   386,   399,   399,
     401,   415,   415,   417,   417,   419,   421,   423,   423,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   437,   439,
     454,   461,   461,   464,   469,   473,   482,   486,   491,   491,
     493,   495,   497,   497,   499,   504,   514,   520,   520,   523,
     528,   534,   534,   537,   539,   546,   546,   548,   548,   550,
     552,   555,   557,   564,   564,   566,   566,   568,   570,   575,
     577,   584,   584,   586,   586,   588,   590,   595,   597,   604,
     604,   606,   606,   608,   610,   615,   617,   624,   624,   626,
     626,   628,   630,   635,   637,   644,   644,   646,   646,   648,
     650,   655,   657,   664,   664,   666,   666,   668,   670,   675,
     677,   684,   694,   699,   705,   705,   707,   709,   711,   711,
     713,   718,   730,   736,   736,   739,   746,   751,   758,   758,
     762,   762,   764,   775,   775,   777,   777,   779,   781,   783,
     783,   786,   787,   788,   789,   790,   791,   794,   796,   803,
     803,   805,   805,   807,   809,   816,   818,   829,   831,   831,
     834,   840,   846,   848,   854,   856,   867,   869,   869,   872,
     878,   884,   886,   893,   895,   906,   908,   908,   911,   917,
     923,   925,   932,   934,   943,   944,   950,   952,   958,   960,
     967,   977,   982,   988,   988,   990,   992,   994,   994,   996,
    1001,  1013,  1019,  1019,  1022,  1029,  1034,  1040,  1040,  1044,
    1044,  1046,  1057,  1057,  1059,  1059,  1061,  1063,  1065,  1065,
    1068,  1069,  1070,  1071,  1072,  1073,  1076,  1078,  1085,  1085,
    1087,  1087,  1089,  1091,  1099,  1101,  1108,  1108,  1110,  1110,
    1112,  1114,  1119,  1121,  1128,  1128,  1130,  1130,  1132,  1134,
    1139,  1141,  1148,  1148,  1150,  1150,  1152,  1154,  1159,  1161,
    1168,  1168,  1170,  1170,  1172,  1174,  1181,  1183,  1190,  1200,
    1205,  1211,  1211,  1213,  1215,  1217,  1217,  1219,  1224,  1236,
    1242,  1242,  1245,  1252,  1257,  1264,  1264,  1267,  1267,  1269,
    1285,  1285,  1287,  1287,  1289,  1291,  1293,  1293,  1296,  1297,
    1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1309,
    1311,  1318,  1318,  1320,  1320,  1322,  1324,  1332,  1334,  1341,
    1341,  1343,  1343,  1345,  1347,  1352,  1354,  1361,  1361,  1363,
    1363,  1365,  1367,  1372,  1374,  1381,  1381,  1383,  1383,  1385,
    1387,  1392,  1394,  1401,  1401,  1403,  1403,  1405,  1407,  1412,
    1414,  1421,  1431,  1436,  1442,  1442,  1444,  1446,  1448,  1448,
    1450,  1452,  1466,  1466,  1469,  1469,  1469,  1469,  1472,  1472,
    1474,  1474,  1476,  1478,  1487,  1488,  1491,  1493,  1504,  1506,
    1506,  1509,  1515,  1521,  1523,  1530,  1532,  1543,  1545,  1545,
    1548,  1554,  1560,  1562,  1569,  1571,  1582,  1584,  1584,  1587,
    1593,  1599,  1601,  1608,  1610,  1620,  1621,  1627,  1629,  1636,
    1638,  1645,  1655,  1660,  1666,  1666,  1668,  1670,  1672,  1672,
    1674,  1679,  1691,  1697,  1697,  1700,  1707,  1712,  1719,  1719,
    1722,  1722,  1724,  1732,  1738,  1738,  1741,  1748,  1754,  1760,
    1768,  1773,  1779,  1779,  1781,  1783,  1785,  1785,  1787,  1789,
    1798,  1800,  1800,  1802,  1802,  1802,  1804,  1814,  1824,  1844,
    1850,  1852,  1862,  1868,  1868,  1871,  1876,  1881,  1891,  1896,
    1902,  1902,  1904,  1906,  1908,  1908,  1910,  1915,  1925,  1931,
    1931,  1934,  1940,  1947,  1947,  1950,  1950,  1952,  1954,  1954,
    1956,  1956,  1958,  1960,  1968,  1968,  1970,  1976,  1976,  1984,
    1984,  1986,  1988,  1990,  1992,  1992,  1994,  1996,  2004,  2009,
    2015,  2015,  2017,  2019,  2021,  2021,  2023,  2034,  2043,  2043,
    2046,  2047,  2050,  2053,  2053,  2055,  2057,  2065,  2070,  2076,
    2076,  2078,  2080,  2082,  2082,  2084,  2095,  2104,  2104,  2107,
    2108,  2112,  2113,  2115,  2115,  2117,  2119,  2124,  2124,  2126,
    2131,  2131,  2133,  2135,  2137,  2139,  2139,  2148,  2150,  2157,
    2157,  2159,  2161,  2163,  2166,  2166,  2176,  2178,  2186,  2186,
    2188,  2190,  2192,  2195,  2195,  2204,  2206,  2214,  2214,  2216,
    2218,  2220,  2223,  2223,  2232,  2234,  2242,  2242,  2244,  2246,
    2248,  2251,  2251,  2260,  2262,  2270,  2270,  2272,  2274,  2276,
    2279,  2279,  2288,  2290,  2298,  2298,  2300,  2302,  2304,  2307,
    2307,  2316,  2318,  2326,  2326,  2328,  2330,  2332,  2335,  2335,
    2337,  2342,  2361,  2367,  2367,  2370,  2381,  2392,  2398,  2404,
    2410,  2416,  2422,  2429,  2429,  2431,  2431,  2433,  2435,  2435,
    2437,  2437,  2439,  2446,  2455,  2455,  2458,  2464,  2471,  2471,
    2473,  2473,  2475,  2477,  2486,  2486,  2488,  2499,  2507,  2513,
    2513,  2516,  2522,  2523,  2527,  2527,  2529,  2531,  2534,  2538,
    2538,  2540,  2548,  2548,  2556,  2556,  2558,  2560,  2562,  2564,
    2564,  2566,  2568,  2576,  2581,  2587,  2587,  2589,  2591,  2594,
    2594,  2596,  2605,  2615,  2615,  2618,  2619,  2622,  2625,  2625,
    2627,  2632,  2632,  2635,  2637,  2639,  2641,  2641,  2650,  2652,
    2659,  2659,  2661,  2663,  2665,  2667,  2667,  2676,  2678,  2686,
    2686,  2688,  2690,  2692,  2695,  2695,  2704,  2706,  2714,  2714,
    2716,  2718,  2720,  2723,  2723,  2732,  2734,  2742,  2742,  2744,
    2746,  2748,  2751,  2751,  2760,  2762,  2770,  2770,  2772,  2774,
    2776,  2779,  2779,  2788,  2790,  2798,  2798,  2800,  2802,  2804,
    2807,  2807,  2816,  2818,  2826,  2826,  2828,  2830,  2832,  2835,
    2835,  2837,  2843,  2862,  2869,  2869,  2872,  2883,  2894,  2900,
    2906,  2912,  2918,  2924,  2933,  2933,  2935,  2935,  2937,  2939,
    2939,  2941,  2941,  2943,  2948,  2959,  2959,  2962,  2967,  2974,
    2974,  2976,  2976,  2978,  2980,  2987,  2987,  2989,  3000,  3008,
    3014,  3014,  3017,  3023,  3024,  3028,  3028,  3030,  3032,  3035,
    3038,  3038,  3040,  3047,  3047,  3055,  3055,  3057,  3059,  3061,
    3063,  3063,  3065,  3068,  3076,  3081,  3087,  3087,  3089,  3091,
    3093,  3093,  3095,  3104,  3113,  3113,  3116,  3117,  3120,  3123,
    3123,  3125,  3130,  3130,  3132,  3134,  3136,  3138,  3138,  3147,
    3149,  3156,  3156,  3158,  3160,  3162,  3164,  3164,  3173,  3175,
    3183,  3183,  3185,  3187,  3189,  3192,  3192,  3201,  3203,  3211,
    3211,  3213,  3215,  3217,  3220,  3220,  3229,  3231,  3239,  3239,
    3241,  3243,  3245,  3248,  3248,  3257,  3259,  3267,  3267,  3269,
    3271,  3273,  3276,  3276,  3285,  3287,  3295,  3295,  3297,  3299,
    3301,  3304,  3304,  3313,  3315,  3323,  3323,  3325,  3327,  3329,
    3332,  3332,  3334,  3340,  3359,  3365,  3365,  3368,  3379,  3390,
    3397,  3403,  3409,  3415,  3421,  3428,  3428,  3430,  3430,  3432,
    3434,  3434,  3436,  3436,  3438,  3445,  3454,  3454,  3458,  3463,
    3471,  3471,  3473,  3473,  3475,  3477,  3484,  3484,  3486,  3497,
    3505,  3511,  3511,  3514,  3520,  3521,  3525,  3525,  3527,  3529,
    3531,  3535,  3535,  3537,  3542,  3551,  3556,  3562,  3562,  3564,
    3566,  3568,  3568,  3570,  3575,  3589,  3597,  3597,  3600,  3606,
    3612,  3618,  3626,  3636,  3641,  3647,  3647,  3649,  3651,  3653,
    3653,  3655,  3661,  3666,  3668,  3668,  3670,  3672,  3684,  3684,
    3686,  3691,  3700,  3705,  3711,  3711,  3713,  3715,  3717,  3717,
    3719,  3724,  3736,  3744,  3744,  3747,  3752,  3758,  3764,  3773,
    3778,  3784,  3784,  3786,  3788,  3790,  3790,  3792,  3798,  3803,
    3805,  3805,  3807,  3809,  3820,  3827,  3827,  3829,  3834,  3839,
    3846,  3846,  3848,  3853,  3858,  3865,  3865,  3867,  3872,  3877,
    3884,  3884,  3886,  3891,  3896,  3904,  3911,  3911,  3913,  3918,
    3923,  3930,  3930,  3932,  3937,  3942,  3949,  3949,  3951,  3956,
    3961,  3968,  3968,  3970,  3975,  3980,  3987,  3987,  3989,  3994,
    3999,  4006,  4006,  4008,  4013,  4019,  4025,  4034,  4040,  4054,
    4063,  4069,  4078,  4084,  4090,  4096,  4102,  4108,  4117,  4123,
    4132,  4137,  4143,  4160,  4161,  4165,  4166,  4167,  4169,  4171,
    4171,  4173,  4174,  4175,  4176,  4213,  4215,  4229,  4229,  4231,
    4233,  4235,  4237,  4237,  4240,  4241,  4242,  4243,  4244,  4246,
    4254,  4254,  4256,  4256,  4258,  4264,  4272,  4272,  4274,  4274,
    4276,  4282,  4290,  4290,  4292,  4292,  4294,  4300,  4308,  4308,
    4310,  4310,  4312,  4318,  4326,  4326,  4328,  4328,  4330,  4342,
    4350,  4352,  4352,  4354,  4356,  4365,  4367,  4367,  4369,  4369,
    4371,  4387,  4390,  4390,  4392,  4392,  4395,  6074,  6081,  6091
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
  "STARTVECTOREND", "NONZEROSSTART", "NONZEROSEND", "INDEXSTART",
  "INDEXEND", "VALUESTART", "VALUEEND", "INDEXESSTART", "INDEXESEND",
  "VALUESSTART", "VALUESEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "GENERALELEMENTSSTART", "GENERALELEMENTSEND",
  "CONREFERENCEELEMENTSSTART", "CONREFERENCEELEMENTSEND", "VALUETYPEATT",
  "OBJREFERENCEELEMENTSSTART", "OBJREFERENCEELEMENTSEND",
  "PATTERNELEMENTSSTART", "PATTERNELEMENTSEND", "TRANSFORMATIONSTART",
  "TRANSFORMATIONEND", "COLOFFSETSTART", "COLOFFSETEND", "ROWOFFSETSTART",
  "ROWOFFSETEND", "EMPTYROWMAJORATT", "ROWMAJORATT", "BLOCKROWIDXATT",
  "BLOCKCOLIDXATT", "DUMMY", "NONLINEAREXPRESSIONSSTART",
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
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   407,   408,   408,   409,   410,   411,   411,   412,   412,
     413,   414,   415,   416,   416,   417,   418,   418,   419,   419,
     420,   421,   421,   422,   422,   423,   424,   425,   425,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   427,   428,
     429,   430,   430,   431,   431,   431,   432,   432,   433,   433,
     434,   435,   436,   436,   437,   438,   439,   440,   440,   441,
     441,   442,   442,   443,   444,   445,   445,   446,   446,   447,
     448,   449,   450,   451,   451,   452,   452,   453,   454,   455,
     456,   457,   457,   458,   458,   459,   460,   461,   462,   463,
     463,   464,   464,   465,   466,   467,   468,   469,   469,   470,
     470,   471,   472,   473,   474,   475,   475,   476,   476,   477,
     478,   479,   480,   481,   481,   482,   482,   483,   484,   485,
     486,   487,   488,   488,   489,   489,   490,   491,   492,   492,
     493,   494,   495,   496,   496,   497,   497,   497,   498,   498,
     499,   499,   500,   501,   501,   502,   502,   503,   504,   505,
     505,   506,   506,   506,   506,   506,   506,   507,   508,   509,
     509,   510,   510,   511,   512,   513,   514,   515,   516,   516,
     517,   517,   518,   519,   520,   521,   522,   523,   523,   524,
     524,   525,   526,   527,   528,   529,   530,   530,   531,   531,
     532,   533,   534,   535,   536,   536,   537,   538,   539,   540,
     541,   542,   542,   543,   543,   544,   545,   546,   546,   547,
     548,   549,   550,   550,   551,   551,   551,   552,   552,   553,
     553,   554,   555,   555,   556,   556,   557,   558,   559,   559,
     560,   560,   560,   560,   560,   560,   561,   562,   563,   563,
     564,   564,   565,   566,   567,   568,   569,   569,   570,   570,
     571,   572,   573,   574,   575,   575,   576,   576,   577,   578,
     579,   580,   581,   581,   582,   582,   583,   584,   585,   586,
     587,   587,   588,   588,   589,   590,   591,   592,   593,   594,
     594,   595,   595,   596,   597,   598,   598,   599,   600,   601,
     602,   602,   603,   603,   603,   604,   604,   605,   605,   606,
     607,   607,   608,   608,   609,   610,   611,   611,   612,   612,
     612,   612,   612,   612,   612,   612,   612,   612,   612,   613,
     614,   615,   615,   616,   616,   617,   618,   619,   620,   621,
     621,   622,   622,   623,   624,   625,   626,   627,   627,   628,
     628,   629,   630,   631,   632,   633,   633,   634,   634,   635,
     636,   637,   638,   639,   639,   640,   640,   641,   642,   643,
     644,   645,   646,   646,   647,   647,   648,   649,   650,   650,
     651,   652,   653,   653,   654,   654,   654,   654,   655,   655,
     656,   656,   657,   658,   659,   659,   660,   661,   662,   663,
     663,   664,   664,   665,   666,   667,   668,   669,   670,   670,
     671,   671,   672,   673,   674,   675,   676,   677,   677,   678,
     678,   679,   680,   681,   682,   683,   683,   684,   685,   686,
     687,   688,   689,   689,   690,   690,   691,   692,   693,   693,
     694,   695,   696,   697,   697,   698,   698,   698,   699,   699,
     700,   700,   701,   702,   703,   703,   704,   704,   704,   704,
     705,   705,   706,   706,   707,   708,   709,   709,   710,   711,
     712,   713,   713,   714,   714,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   722,   723,   723,   723,   724,   724,
     725,   725,   726,   727,   728,   728,   729,   730,   731,   732,
     732,   733,   733,   734,   734,   735,   735,   736,   737,   737,
     738,   738,   739,   740,   741,   741,   742,   743,   743,   744,
     744,   745,   746,   747,   748,   748,   749,   750,   751,   751,
     752,   752,   753,   754,   755,   755,   756,   757,   758,   758,
     759,   759,   760,   761,   761,   762,   763,   764,   764,   765,
     765,   766,   767,   768,   768,   769,   770,   771,   771,   772,
     772,   773,   773,   774,   774,   775,   776,   777,   777,   778,
     779,   779,   780,   781,   782,   783,   783,   784,   785,   786,
     786,   787,   788,   789,   790,   790,   791,   792,   793,   793,
     794,   795,   796,   797,   797,   798,   799,   800,   800,   801,
     802,   803,   804,   804,   805,   806,   807,   807,   808,   809,
     810,   811,   811,   812,   813,   814,   814,   815,   816,   817,
     818,   818,   819,   820,   821,   821,   822,   823,   824,   825,
     825,   826,   827,   828,   828,   829,   830,   831,   832,   832,
     833,   834,   835,   836,   836,   837,   837,   837,   837,   837,
     837,   837,   837,   838,   838,   839,   839,   840,   841,   841,
     842,   842,   843,   844,   845,   845,   846,   846,   847,   847,
     848,   848,   849,   850,   851,   851,   852,   853,   854,   855,
     855,   856,   856,   856,   857,   857,   858,   859,   860,   861,
     861,   862,   863,   863,   864,   864,   865,   866,   867,   868,
     868,   869,   870,   871,   871,   872,   872,   873,   874,   875,
     875,   876,   877,   878,   878,   879,   879,   880,   881,   881,
     882,   883,   883,   884,   885,   886,   887,   887,   888,   889,
     890,   890,   891,   892,   893,   894,   894,   895,   896,   897,
     897,   898,   899,   900,   901,   901,   902,   903,   904,   904,
     905,   906,   907,   908,   908,   909,   910,   911,   911,   912,
     913,   914,   915,   915,   916,   917,   918,   918,   919,   920,
     921,   922,   922,   923,   924,   925,   925,   926,   927,   928,
     929,   929,   930,   931,   932,   932,   933,   934,   935,   936,
     936,   937,   938,   939,   940,   940,   941,   941,   941,   941,
     941,   941,   941,   941,   942,   942,   943,   943,   944,   945,
     945,   946,   946,   947,   948,   949,   949,   950,   950,   951,
     951,   952,   952,   953,   954,   955,   955,   956,   957,   958,
     959,   959,   960,   960,   960,   961,   961,   962,   963,   964,
     965,   965,   966,   967,   967,   968,   968,   969,   970,   971,
     972,   972,   973,   974,   975,   975,   976,   976,   977,   978,
     979,   979,   980,   981,   982,   982,   983,   983,   984,   985,
     985,   986,   987,   987,   988,   989,   990,   991,   991,   992,
     993,   994,   994,   995,   996,   997,   998,   998,   999,  1000,
    1001,  1001,  1002,  1003,  1004,  1005,  1005,  1006,  1007,  1008,
    1008,  1009,  1010,  1011,  1012,  1012,  1013,  1014,  1015,  1015,
    1016,  1017,  1018,  1019,  1019,  1020,  1021,  1022,  1022,  1023,
    1024,  1025,  1026,  1026,  1027,  1028,  1029,  1029,  1030,  1031,
    1032,  1033,  1033,  1034,  1035,  1036,  1036,  1037,  1038,  1039,
    1040,  1040,  1041,  1042,  1043,  1044,  1044,  1045,  1045,  1045,
    1045,  1045,  1045,  1045,  1045,  1046,  1046,  1047,  1047,  1048,
    1049,  1049,  1050,  1050,  1051,  1052,  1053,  1053,  1054,  1054,
    1055,  1055,  1056,  1056,  1057,  1058,  1059,  1059,  1060,  1061,
    1062,  1063,  1063,  1064,  1064,  1064,  1065,  1065,  1066,  1067,
    1068,  1069,  1069,  1070,  1071,  1072,  1072,  1073,  1073,  1074,
    1075,  1076,  1076,  1077,  1078,  1079,  1080,  1080,  1081,  1081,
    1081,  1081,  1081,  1082,  1082,  1083,  1083,  1084,  1085,  1086,
    1086,  1087,  1088,  1088,  1089,  1089,  1090,  1091,  1092,  1092,
    1093,  1094,  1095,  1095,  1096,  1096,  1097,  1098,  1099,  1099,
    1100,  1101,  1102,  1103,  1103,  1104,  1104,  1104,  1104,  1105,
    1105,  1106,  1106,  1107,  1108,  1109,  1109,  1110,  1111,  1111,
    1112,  1112,  1113,  1114,  1115,  1116,  1116,  1117,  1118,  1119,
    1120,  1120,  1121,  1122,  1123,  1124,  1124,  1125,  1126,  1127,
    1128,  1128,  1129,  1130,  1131,  1132,  1133,  1133,  1134,  1135,
    1136,  1137,  1137,  1138,  1139,  1140,  1141,  1141,  1142,  1143,
    1144,  1145,  1145,  1146,  1147,  1148,  1149,  1149,  1150,  1151,
    1152,  1153,  1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,
    1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,
    1171,  1172,  1173,  1174,  1174,  1175,  1175,  1175,  1176,  1177,
    1177,  1178,  1178,  1178,  1178,  1179,  1180,  1181,  1181,  1182,
    1183,  1184,  1185,  1185,  1186,  1186,  1186,  1186,  1186,  1187,
    1188,  1188,  1189,  1189,  1190,  1191,  1192,  1192,  1193,  1193,
    1194,  1195,  1196,  1196,  1197,  1197,  1198,  1199,  1200,  1200,
    1201,  1201,  1202,  1203,  1204,  1204,  1205,  1205,  1206,  1207,
    1207,  1208,  1208,  1209,  1210,  1211,  1212,  1212,  1213,  1213,
    1214,  1215,  1216,  1216,  1217,  1217,  1218,  1219,  1220,  1221
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
#define YYPACT_NINF -1363
static const yytype_int16 yypact[] =
{
     116, -1363, -1363,    73,    13,    80, -1363, -1363,    95,    56,
   -1363,   289, -1363,   328, -1363, -1363, -1363, -1363,    68,   339,
   -1363, -1363, -1363, -1363, -1363,    13, -1363, -1363, -1363, -1363,
   -1363,    71,   360,   -12, -1363, -1363, -1363, -1363,    89,   395,
      95, -1363,    84,   407,    -9, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   106,
     115, -1363, -1363,   321, -1363,   419, -1363,   431, -1363,   458,
   -1363,   460, -1363,   473, -1363,   488, -1363,   498, -1363,   158,
   -1363,   191, -1363, -1363,   198, -1363, -1363,   200, -1363, -1363,
     218, -1363, -1363,   223, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   146,
     500,     2, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   160,   129, -1363, -1363,   506, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   479, -1363,   158, -1363, -1363,
   -1363,   237, -1363,   242, -1363,   516,   321, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363,    36, -1363, -1363,
   -1363, -1363,    37, -1363, -1363, -1363, -1363,    27, -1363, -1363,
   -1363, -1363,    45, -1363, -1363, -1363, -1363,    33, -1363, -1363,
   -1363, -1363,    29, -1363, -1363, -1363, -1363,    10, -1363, -1363,
   -1363, -1363, -1363,   518, -1363,    42,    76,    43,    26,    24,
   -1363, -1363, -1363,    90, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   184,   130, -1363, -1363,   521,
   -1363,   545, -1363,   552, -1363,   556, -1363,   558, -1363,   158,
   -1363, -1363,    12, -1363, -1363, -1363, -1363,   248,   381,   267,
     381,   274,   381,   284, -1363,   561, -1363,   263,    -1, -1363,
   -1363,   -59, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   167,
   -1363, -1363,   150, -1363, -1363,   154, -1363, -1363,   186, -1363,
   -1363,   180, -1363, -1363,   152, -1363, -1363,   141,   323,   -71,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   564,
     259, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   253,   168, -1363, -1363,   568, -1363,   581,
   -1363,   583, -1363,   585, -1363,   589, -1363,   299, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   479, -1363,   158, -1363, -1363,
      40, -1363, -1363, -1363, -1363,    44, -1363, -1363, -1363, -1363,
       5, -1363, -1363, -1363, -1363,    18, -1363, -1363, -1363, -1363,
      20, -1363, -1363, -1363, -1363,   593, -1363, -1363, -1363,   165,
     620, -1363,   331, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
     620, -1363, -1363, -1363, -1363,   620, -1363, -1363, -1363, -1363,
     330, -1363,    70, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   221,   174,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363,   207,   215, -1363, -1363,   -30, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363,    21, -1363, -1363, -1363, -1363,    30, -1363, -1363,
   -1363, -1363,    28, -1363, -1363, -1363, -1363,    53, -1363, -1363,
   -1363, -1363,    39, -1363, -1363, -1363, -1363, -1363,   618, -1363,
     357,   381,   366,   381,   373,   381,   378, -1363,   621, -1363,
   -1363, -1363,   281, -1363, -1363,   286, -1363, -1363,   213, -1363,
   -1363,   226, -1363, -1363, -1363,   266, -1363,   101, -1363, -1363,
   -1363, -1363, -1363,   314, -1363, -1363,   341, -1363,   362, -1363,
   -1363,   382, -1363, -1363,   306,   320, -1363, -1363, -1363, -1363,
   -1363,   625,   413, -1363, -1363, -1363,   628,   501, -1363, -1363,
     398,   -43, -1363, -1363,   489,   512,   514,   534, -1363, -1363,
     311, -1363, -1363,   336, -1363, -1363,   358, -1363, -1363,   466,
   -1363, -1363,   422,   547,   -50, -1363, -1363, -1363, -1363,   620,
   -1363, -1363, -1363, -1363,   620, -1363, -1363, -1363, -1363,   620,
   -1363, -1363, -1363, -1363,   553, -1363,   125, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   405,   421,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   630,
     501,   404, -1363, -1363,   598, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363,   461, -1363, -1363,   604, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   600,   609,
      61, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   439,   456, -1363, -1363,   464, -1363,   485,
   -1363,   462, -1363, -1363,   510, -1363, -1363,   606,   567, -1363,
   -1363, -1363, -1363,   632,   501,   560, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363,   634, -1363,   579,
   -1363, -1363,   759,   760, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   337, -1363, -1363, -1363, -1363,
   -1363, -1363,   636,   501,   622, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363,   758,   -69, -1363, -1363, -1363, -1363,
   -1363,   635,   321,   761, -1363, -1363,    23, -1363,   762, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363,   626, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363,   617,   607, -1363, -1363, -1363,   570,   638,   640,
     321, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363,   596, -1363, -1363, -1363, -1363, -1363, -1363,   642,   493,
   -1363,   641,   749,    38, -1363, -1363, -1363, -1363,     7, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363,    11, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   672,
     755, -1363,   646, -1363, -1363, -1363,   647, -1363, -1363,   614,
     612, -1363, -1363,   780, -1363, -1363, -1363,   623,    83, -1363,
   -1363, -1363, -1363,   781, -1363,   637,   764, -1363,   650, -1363,
     784,   517, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   652,
     164, -1363,   713, -1363, -1363, -1363, -1363,   631,   767, -1363,
     654, -1363,   789,   522, -1363, -1363, -1363, -1363, -1363, -1363,
     594,   601,   766,   629, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   656, -1363,   794,   689, -1363, -1363, -1363,
   -1363, -1363, -1363,   668,   704,   785, -1363, -1363, -1363,   708,
     766, -1363,   659, -1363, -1363,   797,   175, -1363, -1363, -1363,
   -1363, -1363, -1363,   700,   710,   796, -1363, -1363, -1363, -1363,
     661, -1363,   663, -1363, -1363, -1363,   665,   667, -1363,   804,
    -151, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   664,   670,
   -1363, -1363, -1363, -1363, -1363, -1363,   669, -1363,   673, -1363,
     675,   716, -1363, -1363, -1363, -1363,   810,  -100, -1363, -1363,
   -1363, -1363,   676,   722, -1363, -1363, -1363, -1363,   487, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,   544,   624, -1363, -1363,
   -1363, -1363, -1363,   677,   402,   681,   727, -1363, -1363, -1363,
   -1363,   816,    34, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363,   725,   743,   807, -1363, -1363, -1363,   554,   694, -1363,
   -1363, -1363, -1363, -1363, -1363,   729,   747,   807, -1363, -1363,
     639,   643, -1363, -1363, -1363, -1363, -1363,    55,   -10, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   731,   751,   807, -1363, -1363, -1363,   720,
     733, -1363, -1363,   679,   368, -1363, -1363,   753,   807, -1363,
     682, -1363, -1363, -1363, -1363,   104,   684,   445, -1363, -1363,
     754,   807,   686, -1363, -1363, -1363,   287,   620, -1363, -1363,
   -1363, -1363, -1363,   838, -1363, -1363, -1363,   697,   312, -1363,
   -1363, -1363, -1363,   688,   538, -1363, -1363,   757,   807,   692,
   -1363, -1363, -1363, -1363,   216,   -18, -1363, -1363, -1363, -1363,
   -1363,   844, -1363,   845, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363,   768,   807,   696, -1363,   843,   763, -1363, -1363, -1363,
   -1363,   620, -1363, -1363, -1363, -1363,   -55, -1363, -1363, -1363,
   -1363,   847, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,   769,   807,   698, -1363,
     763, -1363, -1363, -1363, -1363,     6, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   655,   848, -1363,   778, -1363, -1363,   -24,
   -1363, -1363, -1363, -1363,   854, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   775,
     807,   703, -1363,   763, -1363, -1363, -1363, -1363,   620, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,   718,   730, -1363, -1363,
     752, -1363, -1363,   855, -1363, -1363, -1363,   735,   807,   705,
   -1363,   763, -1363, -1363, -1363, -1363, -1363,   823,   770, -1363,
     756, -1363,   736, -1363, -1363, -1363,   724,   674, -1363, -1363,
     765, -1363, -1363, -1363, -1363,   737,   807,   707, -1363,   763,
   -1363, -1363, -1363, -1363,   774, -1363, -1363, -1363,   680, -1363,
   -1363, -1363, -1363, -1363, -1363,   739,   771, -1363, -1363,   772,
   -1363, -1363, -1363, -1363,   773,   807,   709, -1363,   763, -1363,
   -1363, -1363, -1363,   777, -1363,   779, -1363, -1363,   309, -1363,
     712,   247, -1363, -1363, -1363, -1363,   706,   807,   715, -1363,
     763, -1363, -1363, -1363, -1363,   795, -1363, -1363,   859,   717,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363,   364, -1363,   719,
     247, -1363, -1363,   711,   807,   721, -1363,   763, -1363, -1363,
   -1363, -1363,   800, -1363, -1363, -1363, -1363, -1363, -1363,   440,
   -1363,   723,   247, -1363, -1363,   714,   807,   726, -1363,   763,
   -1363, -1363, -1363, -1363,   802, -1363, -1363, -1363,    32, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,   763, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363,   741,   807,   728,
   -1363,   763, -1363, -1363, -1363, -1363,   787, -1363, -1363,   884,
      48, -1363, -1363, -1363, -1363,   881,   702,    17, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   763, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   742,   807,   732, -1363,   763,
   -1363, -1363, -1363, -1363,   805, -1363, -1363,    47, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   763, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   745,   807,   734, -1363,   763,
   -1363, -1363, -1363, -1363,   806, -1363, -1363, -1363, -1363, -1363,
   -1363,   776, -1363,   782, -1363, -1363, -1363,   807,   738, -1363,
     763, -1363, -1363, -1363, -1363,   808, -1363, -1363,   887,   798,
   -1363,   891, -1363,   890,   893, -1363, -1363, -1363, -1363,   699,
   -1363,   786, -1363, -1363, -1363,   807,   740, -1363,   763, -1363,
   -1363, -1363, -1363,   819, -1363, -1363, -1363,   799, -1363,   788,
   -1363, -1363, -1363,   807,   744, -1363,   763, -1363, -1363, -1363,
   -1363,   824, -1363, -1363, -1363, -1363,   746, -1363,   763, -1363,
   -1363, -1363, -1363,   783, -1363, -1363, -1363, -1363,   791,   905,
     908, -1363, -1363,   748, -1363,   763, -1363, -1363, -1363, -1363,
     790, -1363, -1363, -1363, -1363,   750, -1363,   763, -1363, -1363,
   -1363, -1363,   793, -1363, -1363,   763, -1363, -1363, -1363, -1363,
     792, -1363, -1363, -1363,   907,   909,   763, -1363, -1363, -1363,
   -1363,   801, -1363, -1363,   763, -1363, -1363, -1363, -1363,   803,
   -1363, -1363,   809, -1363, -1363, -1363, -1363,   811, -1363, -1363,
     812, -1363, -1363, -1363, -1363, -1363
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   876, -1363,
     894, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   858,
   -1363, -1363, -1363, -1363,   813, -1363, -1363, -1363, -1363, -1363,
     515, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,   502, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   814,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
     406, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   701, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363,   342, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   616, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363,   282, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363,   275, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   403, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,   176, -1363, -1363, -1363,
   -1363, -1363,   117, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   -42,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363,   -83, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,  -318, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,  -320, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   -67,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
    -285, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,  -287,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,  -106, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363,  -341, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,  -343, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
       8, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
    -138, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   199, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   123, -1363, -1363, -1363, -1363,  -770, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,  -145, -1363, -1363, -1363,
    -999, -1363, -1363, -1363, -1057,  -524, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,  -694, -1363, -1363, -1363,  -246, -1363, -1363,
   -1363,  -587, -1363, -1363, -1363, -1363, -1363, -1363, -1363,  -141,
   -1363, -1000,  -988,   -29,   -98, -1363, -1363, -1363,  -135, -1363,
   -1363, -1363, -1363,  -658, -1363,  -882, -1363,  -365, -1362,  -200,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1083, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     254,   739,   288,   619,   384,   504,   389,   398,  1144,   804,
    1276,   486,   256,   671,   285,   507,   367,  1073,   928,  1181,
     509,  1477,   489,  1478,  1479,   538,   492,   493,   763,   768,
     769,   273,   544,   282,   541,  1005,  1477,   279,  1478,  1479,
     267,   270,   814,   550,   480,  1100,   528,  1221,   974,   276,
     483,  1477,  1499,  1478,  1479,  1510,    49,   547,  1134,   404,
     405,   126,  1253,   406,   764,  1077,   763,  1083,  1155,  1084,
    1085,  1169,   420,     6,   218,   421,   670,   710,     7,  1163,
     127,  1282,   128,   750,   129,  1528,   130,  1275,   823,  1254,
     824,   825,  1078,  1283,    12,  1202,   751,   681,  1212,  1223,
     604,   605,   764,   375,   366,   383,  1207,   388,   625,    50,
      14,   219,   407,   220,  1141,    51,   747,  1224,   529,    52,
    1284,    53,   682,    17,   683,   975,  1225,   641,     1,     2,
    1304,   529,  1240,    54,   642,   548,   131,    30,  1086,  1047,
     709,  1078,    41,    55,  1255,    56,  1500,   221,  1048,   604,
     605,    57,   481,  1526,   484,    80,   878,   118,  1326,   551,
     823,   222,   824,   825,   301,   280,   132,  1268,  1480,    58,
     268,   302,   815,   277,   148,   817,  1006,   826,   818,   746,
     494,   223,   545,   274,   202,  1164,  1353,   224,   368,   539,
     477,   487,   286,   283,   648,   271,   205,   518,   490,   650,
     542,   770,   479,   206,   652,   207,  1277,   151,   152,   303,
    1297,   153,   154,   512,  1034,  1375,   513,  1508,   127,   523,
     128,   210,   129,   208,   130,   563,  1218,   568,   209,   573,
     240,   534,   535,   536,   537,   304,    50,  1407,  1319,   219,
     259,   220,    51,   305,   586,   260,    52,   587,    53,   302,
     297,  1384,   298,  1078,   294,   806,   338,   306,   370,   307,
      54,   604,   605,   296,  1445,  1059,  1346,   553,   655,   397,
      55,   656,    56,   308,   131,   221,   431,   380,    57,   309,
    1423,   310,   432,   311,   385,   312,  1475,   303,   433,   222,
     151,   152,   295,   434,   390,  1368,    58,  1175,  1176,    20,
      21,   412,  1453,  1484,   132,   593,   615,   616,   413,   223,
     414,  1394,   416,   304,   415,   224,   417,  1400,  1496,  1378,
    1379,   305,   936,   418,  1078,   937,   562,   440,   567,   419,
     572,   467,   604,   605,   505,   306,   510,   307,    25,    26,
    1433,   502,  1512,   519,  1438,   407,  1078,   726,   727,    33,
      34,   308,   150,   524,   604,   605,  1524,   309,   420,   310,
    1126,   311,  1463,   312,   151,   152,  1468,   559,   153,   154,
      44,    45,  1530,  1157,  1417,  1418,   564,   607,   728,   729,
     151,   152,   618,   569,   153,   154,  1542,  1110,   574,  1083,
     921,  1084,  1085,   581,   372,   373,   582,  1037,  1489,   583,
    1204,  1078,   399,   400,   401,   402,   584,  1554,   592,   604,
     605,   151,   152,   604,   605,   153,   154,   121,   122,  1111,
    1112,  1113,  1114,   802,   151,   152,   585,   615,   616,   167,
     168,   688,   689,   690,   691,  1571,  1517,   594,   372,   373,
     692,   172,   173,   728,   729,   151,   152,   604,   605,   740,
    1447,  1448,   597,  1583,   595,   669,   151,   152,   604,   605,
    1036,   615,   616,   512,  1110,  1591,  1535,  1127,   177,   178,
     182,   183,   596,   712,   624,   713,   714,  1078,   901,   635,
    1158,   723,  1602,   187,   188,   604,   605,  1547,   151,   152,
     604,   605,   153,   154,  1610,   631,  1111,  1112,   192,   193,
    1151,  1152,  1613,  1082,   615,   616,   636,  1205,   197,   198,
     213,   214,   637,  1618,   802,  1564,   242,   243,   632,   708,
     633,  1621,   151,   152,   766,   767,   261,   262,   289,   290,
    1121,   340,   341,  1576,   728,   729,   151,   152,   604,   605,
     634,  1145,   639,  1156,   151,   152,   604,   605,   638,   775,
     738,   661,  1182,   640,   947,   345,   346,  1110,   745,   653,
     615,   616,   350,   351,   586,   794,   355,   356,   360,   361,
    1203,   392,   393,   796,   426,   427,   672,   762,   442,   443,
    1222,   151,   152,   604,   605,   153,   154,  1194,  1195,  1111,
    1112,   447,   448,   452,   453,   457,   458,   615,   616,   462,
     463,   673,   833,   497,   498,   674,    81,   675,    82,    83,
      84,   840,    85,    86,    87,   762,    88,    89,    90,   679,
      91,    92,    93,   693,    94,    95,   492,   493,   554,   555,
     676,   576,   577,   641,   805,   601,   602,   862,   612,   613,
     665,   666,   704,   705,   715,   716,   741,   742,   783,   784,
     788,   789,   797,   798,   698,   880,   841,   842,   696,   885,
     863,   864,   873,   874,   886,   887,   906,   907,   896,   930,
     931,   951,   952,   957,   958,   963,   964,   968,   969,   986,
     987,   697,   905,   992,   993,  1018,  1019,  1028,  1029,  1105,
    1106,   916,  1136,  1137,  1146,  1147,  1170,  1171,  1189,  1190,
     699,   929,  1213,  1214,   711,   877,  1241,  1242,  1269,  1270,
     655,   942,  1183,  1298,  1299,  1320,  1321,  1347,  1348,  1369,
    1370,   956,  1386,  1387,  1393,  1401,  1402,  1410,  1411,  1425,
    1426,  1439,  1440,  1455,  1456,   980,  1469,  1470,  1490,  1491,
    1503,  1504,  1518,  1519,  1536,  1537,   720,   991,  1548,  1549,
    1565,  1566,   700,  1432,  1577,  1578,  1585,  1586,  1596,  1597,
    1604,  1605,   724,   725,   749,   773,   748,   765,   756,   776,
     774,   780,   751,  1024,   795,  1462,  1252,   811,   808,   834,
     837,   846,   847,   818,  1385,   851,   856,   855,   859,   853,
     868,   879,   869,   881,   882,   891,   897,   892,   898,   901,
     911,   904,   912,   935,  1062,   918,   917,   921,   943,   924,
     973,   944,   947,  1424,   981,  1000,  1004,   936,   997,  1011,
    1025,  1014,  1046,   974,  1039,  1059,  1042,  1055,  1056,  1005,
    1063,  1068,  1069,  1095,  1102,  1454,  1096,  1074,  1047,  1035,
    1130,  1165,  1019,  1185,  1208,  1187,  1101,  1234,  1235,  1246,
    1263,  1236,  1264,  1305,  1280,  1279,  1281,  1292,  1293,  1135,
    1247,  1312,  1306,  1328,  1315,  1224,  1342,  1409,  1335,  1223,
    1330,  1331,  1334,  1255,  1354,  1497,  1282,  1376,  1184,  1396,
    1355,  1408,  1253,  1357,  1434,  1377,  1446,  1464,  1476,  1283,
    1498,  1501,  1555,  1525,  1543,  1556,  1557,  1558,  1559,  1561,
    1545,  1560,  1364,  1572,  1562,  1573,  1574,  1593,  1584,  1116,
    1233,  1594,  1544,  1592,  1595,  1615,   117,  1616,   149,    40,
    1603,   598,  1154,  1611,   520,   525,   694,   339,  1485,  1513,
     441,   662,  1531,   701,   626,  1026,   793,   848,  1075,  1336,
    1338,  1064,  1307,  1309,  1103,  1358,  1360,   982,   241,  1201,
    1188,   854,   777,  1206,     0,  1038,  1129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1614,     0,     0,   266,
       0,     0,     0,     0,     0,  1619,     0,  1622,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1623,     0,  1624,
    1625,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1313,  1314,     0,     0,     0,     0,
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
     145,   695,   202,   527,   250,   370,   252,     8,  1065,   779,
       4,     6,   147,   600,     4,   380,     4,  1017,   900,  1076,
     385,     4,     4,     6,     7,     4,     6,     7,   722,     6,
       7,     4,     4,     4,     4,   135,     4,     4,     6,     7,
       4,     4,     4,     4,     4,  1045,    76,  1104,   199,     4,
       6,     4,     4,     6,     7,  1417,    68,     4,  1058,   259,
     260,    70,   117,   122,   722,    10,   760,    77,  1067,    79,
      80,  1071,   143,     0,    72,   146,   600,   664,    65,  1067,
      89,   105,    91,   152,    93,  1447,    95,  1170,    77,   144,
      79,    80,    37,   117,    14,  1094,   165,    36,  1098,   117,
      45,    46,   760,   248,   239,   250,  1094,   252,   151,   121,
      15,   109,   171,   111,    10,   127,   703,   135,   161,   131,
     144,   133,    61,    67,    63,   276,   144,   177,    12,    13,
    1213,   161,  1132,   145,   184,    82,   145,    69,   148,   105,
     664,    37,    71,   155,   199,   157,    98,   145,   114,    45,
      46,   163,   112,   106,   110,    66,   850,    73,  1241,   120,
      77,   159,    79,    80,    74,   132,   175,  1167,   136,   181,
     134,    81,   134,   128,    68,   168,   276,   166,   171,   703,
     160,   179,   154,   156,    26,  1067,  1269,   185,   176,   168,
     335,   186,   182,   164,   559,   158,     5,   397,   180,   564,
     170,   178,   337,     5,   569,     5,   200,    43,    44,   119,
    1210,    47,    48,   143,   984,  1298,   146,   200,    89,   419,
      91,    75,    93,     5,    95,   471,    10,   473,     5,   475,
      70,   431,   432,   433,   434,   145,   121,  1320,  1238,   109,
       3,   111,   127,   153,   143,     3,   131,   146,   133,    81,
     224,  1308,   228,    37,   212,   779,    72,   167,    10,   169,
     145,    45,    46,   220,  1347,    18,  1266,   467,   143,     6,
     155,   146,   157,   183,   145,   145,    17,    10,   163,   189,
    1337,   191,    23,   193,    10,   195,  1369,   119,    29,   159,
      43,    44,   216,    34,    10,  1295,   181,    10,    11,    10,
      11,   134,  1359,  1386,   175,   505,    59,    60,   158,   179,
     156,  1311,   132,   145,   128,   185,   164,  1317,  1401,    10,
      11,   153,   147,   182,    37,   150,   471,    74,   473,     6,
     475,    32,    45,    46,     3,   167,     6,   169,    10,    11,
    1340,   176,  1425,   122,  1344,   171,    37,    10,    11,    10,
      11,   183,    31,   146,    45,    46,  1439,   189,   143,   191,
    1054,   193,  1362,   195,    43,    44,  1366,    10,    47,    48,
      10,    11,  1455,  1067,    10,    11,    10,   522,    41,    42,
      43,    44,   527,    10,    47,    48,  1469,    19,    10,    77,
      22,    79,    80,   112,    57,    58,   110,   984,  1398,   186,
    1094,    37,   403,   404,   405,   406,   180,  1490,    94,    45,
      46,    43,    44,    45,    46,    47,    48,    10,    11,    51,
      52,    53,    54,    21,    43,    44,   160,    59,    60,    10,
      11,   631,   632,   633,   634,  1518,  1436,    96,    57,    58,
     640,    10,    11,    41,    42,    43,    44,    45,    46,   695,
      10,    11,   146,  1536,    92,   600,    43,    44,    45,    46,
     984,    59,    60,   143,    19,  1548,  1466,  1054,    10,    11,
      10,    11,    90,   673,    76,   675,   676,    37,    33,   168,
    1067,   681,  1565,    10,    11,    45,    46,  1487,    43,    44,
      45,    46,    47,    48,  1577,     6,    51,    52,    10,    11,
      55,    56,  1585,  1027,    59,    60,   170,  1094,    10,    11,
      10,    11,   154,  1596,    21,  1515,    10,    11,     6,   664,
       6,  1604,    43,    44,   724,   725,    10,    11,    10,    11,
    1054,    10,    11,  1533,    41,    42,    43,    44,    45,    46,
       6,  1065,   120,  1067,    43,    44,    45,    46,    82,   749,
     695,   146,  1076,     6,    16,    10,    11,    19,   703,     6,
      59,    60,    10,    11,   143,   765,    10,    11,    10,    11,
    1094,    10,    11,   773,    10,    11,   172,   722,    10,    11,
    1104,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    10,    11,    10,    11,    10,    11,    59,    60,    10,
      11,     3,   802,    10,    11,   144,   211,     3,   213,   214,
     215,   811,   217,   218,   219,   760,   221,   222,   223,    10,
     225,   226,   227,   184,   229,   230,     6,     7,    10,    11,
      30,    10,    11,   177,   779,    10,    11,   837,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   192,   855,    10,    11,   194,   859,
      10,    11,    10,    11,    10,    11,    10,    11,   868,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,   196,   882,    10,    11,   198,   199,    10,    11,    10,
      11,   891,    10,    11,    10,    11,    10,    11,    10,    11,
     190,   901,    10,    11,   144,   850,    10,    11,    10,    11,
     143,   911,  1077,    10,    11,    10,    11,    10,    11,    10,
      11,   921,    10,    11,  1311,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,   935,    10,    11,    10,    11,
      38,    39,    10,    11,    10,    11,   167,   947,    10,    11,
      10,    11,   146,  1340,    10,    11,    10,    11,    10,    11,
      10,    11,     3,     3,     6,     3,   144,     6,   133,   152,
     144,   201,   165,   973,   178,  1362,  1141,    28,   137,   107,
      25,   134,   168,   171,  1308,     5,   149,     6,    24,   166,
       6,    78,   275,   162,    27,     6,   202,   275,   197,    33,
       6,   172,   113,     6,  1004,   101,   138,    22,   108,   101,
       6,   101,    16,  1337,   150,    99,     6,   147,   143,   143,
     276,    99,     6,   199,   143,    18,    99,   102,    85,   135,
     276,   102,    85,   102,   114,  1359,    85,   198,   105,   984,
      87,    87,   199,     5,    87,   148,  1046,     3,     3,     6,
       3,    83,    83,  1218,     6,   200,    78,     3,    83,  1059,
      97,     6,   144,    40,   129,   135,   129,     8,   144,   117,
     100,   115,   136,   199,   100,    88,   105,   100,  1078,   173,
     200,    86,   117,   144,   173,   106,    86,   173,    86,   117,
       6,    10,    84,    88,    88,     8,    98,     6,     8,   200,
     118,     8,   129,    84,   118,   106,   118,   116,    84,  1054,
    1110,     6,   136,   130,     6,     8,    40,     8,    60,    25,
     130,   515,  1067,   130,   409,   423,   644,   226,   187,   187,
     314,   589,   187,   658,   531,   977,   760,   820,  1021,  1257,
    1260,  1008,  1227,  1230,  1050,  1286,  1289,   939,   134,  1094,
    1088,   828,   753,  1094,    -1,   984,  1054,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,   174,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,   188,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1234,  1235,    -1,    -1,    -1,    -1,
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
       0,    12,    13,   408,   409,   410,     0,    65,   417,   418,
    1179,  1180,    14,   411,    15,   415,   416,    67,   419,   420,
      10,    11,  1181,  1182,  1183,    10,    11,   412,   413,   414,
      69,   499,   500,    10,    11,   421,   422,   423,  1184,  1185,
     417,    71,   553,   554,    10,    11,   501,   502,   503,    68,
     121,   127,   131,   133,   145,   155,   157,   163,   181,   424,
     425,   426,   427,   428,   443,   444,   449,   450,   455,   456,
     461,   462,   467,   468,   473,   474,   479,   480,   485,   486,
      66,   211,   213,   214,   215,   217,   218,   219,   221,   222,
     223,   225,   226,   227,   229,   230,  1186,  1187,  1188,  1189,
    1190,  1191,  1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,
    1200,  1201,  1202,  1203,  1204,  1205,  1206,   415,    73,   605,
     606,    10,    11,   555,   556,   557,    70,    89,    91,    93,
      95,   145,   175,   504,   505,   506,   507,   508,   513,   514,
     520,   521,   527,   528,   534,   535,   539,   540,    68,   426,
      31,    43,    44,    47,    48,   429,   430,   431,  1123,  1124,
    1125,  1126,  1140,  1141,  1142,  1143,  1170,    10,    11,   445,
     446,   447,    10,    11,   451,   452,   453,    10,    11,   457,
     458,   459,    10,    11,   463,   464,   465,    10,    11,   469,
     470,   471,    10,    11,   475,   476,   477,    10,    11,   481,
     482,   483,    26,   487,  1165,     5,     5,     5,     5,     5,
      75,   700,   701,    10,    11,   607,   608,   609,    72,   109,
     111,   145,   159,   179,   185,   558,   559,   560,   561,   562,
     567,   568,   573,   574,   579,   580,   585,   586,   591,   592,
      70,   506,    10,    11,   509,   510,   511,   515,   516,   522,
     523,   529,   530,   536,  1123,   541,  1165,  1176,  1177,     3,
       3,    10,    11,   432,   433,   434,   431,     4,   134,   448,
       4,   158,   454,     4,   156,   460,     4,   128,   466,     4,
     132,   472,     4,   164,   478,     4,   182,   484,  1176,    10,
      11,   488,   489,   490,   212,   216,   220,   224,   228,   702,
     703,    74,    81,   119,   145,   153,   167,   169,   183,   189,
     191,   193,   195,   610,   611,   612,   613,   614,   619,   620,
     625,   626,   631,   632,   637,   638,   643,   644,   660,   661,
     667,   668,   674,   675,   681,   682,   686,   687,    72,   560,
      10,    11,   563,   564,   565,    10,    11,   569,   570,   571,
      10,    11,   575,   576,   577,    10,    11,   581,   582,   583,
      10,    11,   587,   588,   589,   593,  1165,     4,   176,   512,
      10,   518,    57,    58,   517,  1123,  1144,  1145,  1146,  1147,
      10,   525,   524,  1123,  1144,    10,   532,   531,  1123,  1144,
      10,   537,    10,    11,   542,   543,   544,     6,     8,   403,
     404,   405,   406,  1178,  1176,  1176,   122,   171,   435,   436,
     437,   438,   134,   158,   156,   128,   132,   164,   182,     6,
     143,   146,   491,   492,   493,   494,    10,    11,   705,   706,
     707,    17,    23,    29,    34,   704,  1157,  1162,  1168,  1173,
      74,   612,    10,    11,   615,   616,   617,    10,    11,   621,
     622,   623,    10,    11,   627,   628,   629,    10,    11,   633,
     634,   635,    10,    11,   639,   640,   641,    32,   645,  1171,
     662,   663,   669,   670,   676,   677,   683,  1123,   688,  1165,
       4,   112,   566,     6,   110,   572,     6,   186,   578,     4,
     180,   584,     6,     7,   160,   590,  1174,    10,    11,   594,
     595,   596,   176,   519,  1174,     3,   526,  1174,   533,  1174,
       6,   538,   143,   146,   545,   546,   547,   548,  1176,   122,
     437,   439,   440,  1176,   146,   493,   495,   496,    76,   161,
     708,   709,   710,   711,  1176,  1176,  1176,  1176,     4,   168,
     618,     4,   170,   624,     4,   154,   630,     4,    82,   636,
       4,   120,   642,  1176,    10,    11,   646,   647,   648,    10,
     665,   664,  1123,  1144,    10,   672,   671,  1123,  1144,    10,
     679,   678,  1123,  1144,    10,   684,    10,    11,   689,   690,
     691,   112,   110,   186,   180,   160,   143,   146,   597,   598,
     599,   600,    94,  1176,    96,    92,    90,   146,   547,   549,
     550,    10,    11,   442,    45,    46,   441,  1123,  1132,  1133,
    1134,  1135,    10,    11,   498,    59,    60,   497,  1123,  1132,
    1148,  1149,  1150,  1151,    76,   151,   710,  1092,  1093,   712,
     713,     6,     6,     6,     6,   168,   170,   154,    82,   120,
       6,   177,   184,   649,   650,   651,   652,   666,  1174,   673,
    1174,   680,  1174,     6,   685,   143,   146,   692,   693,   694,
     695,   146,   599,   601,   602,    10,    11,   552,   551,  1123,
    1132,  1148,   172,     3,   144,     3,    30,  1094,  1169,    10,
     718,    36,    61,    63,   714,   715,   716,   717,  1176,  1176,
    1176,  1176,  1176,   184,   651,   653,   194,   196,   192,   190,
     146,   694,   696,   697,    10,    11,   604,   603,  1123,  1132,
    1148,   144,  1176,  1176,  1176,    10,    11,  1095,  1096,  1097,
     167,   719,   720,  1176,     3,     3,    10,    11,    41,    42,
     654,   655,   656,   657,  1115,  1116,  1117,  1118,  1123,  1140,
    1144,    10,    11,   699,   698,  1123,  1132,  1148,   144,     6,
     152,   165,  1098,  1099,  1100,  1101,   133,   735,   736,   721,
     722,   723,  1123,  1140,  1170,     6,  1176,  1176,     6,     7,
     178,   658,   659,     3,   144,  1176,   152,  1100,  1102,  1103,
     201,   741,   742,    10,    11,   737,   738,   739,    10,    11,
     724,   725,   726,   723,  1176,   178,  1176,    10,    11,  1105,
    1106,  1107,    21,  1104,  1115,  1123,  1132,  1160,   137,   861,
     862,    28,   743,  1167,     4,   134,   740,   168,   171,   727,
     728,   729,   730,    77,    79,    80,   166,  1108,  1109,  1110,
    1111,  1112,  1113,  1176,   107,   965,   966,    25,   863,  1164,
    1176,    10,    11,   744,   745,   746,   134,   168,   729,   731,
     732,     5,  1114,   166,  1110,     6,   149,  1069,  1070,    24,
     967,  1163,  1176,    10,    11,   864,   865,   866,     6,   275,
     747,   748,   749,    10,    11,   734,   733,  1123,  1140,    78,
    1176,   162,    27,  1071,  1166,  1176,    10,    11,   968,   969,
     970,     6,   275,   867,   868,   869,  1176,   202,   197,   761,
     762,    33,   750,  1172,   172,  1176,    10,    11,  1072,  1073,
    1074,     6,   113,   971,   972,   973,  1176,   138,   101,   881,
     882,    22,   870,  1161,   101,   777,   778,   763,  1172,  1176,
      10,    11,   751,   752,   753,     6,   147,   150,  1075,  1076,
    1077,  1078,  1176,   108,   101,   985,   986,    16,   974,  1156,
     936,    10,    11,   883,   884,   885,  1176,    10,    11,   871,
     872,   873,   832,    10,    11,   779,   780,   781,    10,    11,
     764,   765,   766,     6,   199,   276,   754,   755,   756,   757,
    1176,   150,  1077,  1079,  1080,  1040,    10,    11,   987,   988,
     989,  1176,    10,    11,   975,   976,   977,   143,   937,   938,
      99,   886,   887,   888,     6,   135,   276,   874,   875,   876,
     877,   143,   833,   834,    99,   782,   783,   784,   198,   199,
     767,   768,   769,   770,  1176,   276,   756,   758,    10,    11,
    1082,  1083,  1084,  1081,  1115,  1123,  1132,  1148,  1160,   143,
    1041,  1042,    99,   990,   991,   992,     6,   105,   114,   978,
     979,   980,   981,   939,   940,   102,    85,   894,   895,    18,
     889,  1158,  1176,   276,   876,   878,   835,   836,   102,    85,
     790,   791,   785,  1158,   198,   769,   771,    10,    37,   759,
     760,  1131,  1132,    77,    79,    80,   148,  1085,  1086,  1087,
    1088,  1089,  1090,  1043,  1044,   102,    85,   998,   999,   993,
    1158,  1176,   114,   980,   982,    10,    11,   942,   943,   944,
      19,    51,    52,    53,    54,   941,  1123,  1127,  1128,  1129,
    1130,  1132,  1136,  1137,  1138,  1139,  1140,  1148,  1159,  1161,
      87,   901,   902,   896,  1158,  1176,    10,    11,   890,   891,
     892,    10,   879,   880,  1131,  1132,    10,    11,   838,   839,
     840,    55,    56,   837,  1123,  1127,  1132,  1140,  1148,  1152,
    1153,  1154,  1155,  1159,  1172,    87,   797,   798,   792,  1158,
      10,    11,   786,   787,   788,    10,    11,   772,   773,   774,
     775,  1131,  1132,  1174,  1176,     5,  1091,   148,  1087,    10,
      11,  1046,  1047,  1048,    49,    50,  1045,  1119,  1120,  1121,
    1122,  1123,  1127,  1132,  1140,  1148,  1156,  1159,    87,  1005,
    1006,  1000,  1158,    10,    11,   994,   995,   996,    10,   983,
     984,  1131,  1132,   117,   135,   144,   945,   946,   947,   948,
     955,   956,   957,  1176,     3,     3,    83,   908,   909,   903,
    1158,    10,    11,   897,   898,   899,     6,    97,   893,  1207,
    1208,  1215,  1174,   117,   144,   199,   841,   842,   843,   844,
     851,   852,   853,     3,    83,   804,   805,   799,  1158,    10,
      11,   793,   794,   795,   789,  1207,     4,   200,   776,   200,
       6,    78,   105,   117,   144,  1049,  1050,  1051,  1052,  1059,
    1060,  1061,     3,    83,  1012,  1013,  1007,  1158,    10,    11,
    1001,  1002,  1003,   997,  1207,  1174,   144,   947,   949,   956,
     958,   959,     6,  1176,  1176,   129,   915,   916,   910,  1158,
      10,    11,   904,   905,   906,   900,  1207,  1176,    40,  1219,
     100,   115,  1209,  1210,   136,   144,   843,   845,   852,   854,
     855,  1176,   129,   811,   812,   806,  1158,    10,    11,   800,
     801,   802,   796,  1207,   100,   200,  1176,   144,  1051,  1053,
    1060,  1062,  1063,  1176,   129,  1019,  1020,  1014,  1158,    10,
      11,  1008,  1009,  1010,  1004,  1207,   100,   106,    10,    11,
     950,   951,   952,   953,  1131,  1132,    10,    11,   961,   962,
     963,   960,  1123,  1148,  1158,  1176,   173,   922,   923,   917,
    1158,    10,    11,   911,   912,   913,   907,  1207,    86,     8,
      10,    11,  1216,  1217,  1218,  1211,  1212,    10,    11,   846,
     847,   848,   849,  1131,  1132,    10,    11,   857,   858,   859,
     856,  1123,  1148,  1158,   173,   818,   819,   813,  1158,    10,
      11,   807,   808,   809,   803,  1207,    86,    10,    11,  1054,
    1055,  1056,  1057,  1131,  1132,    10,    11,  1065,  1066,  1067,
    1064,  1123,  1148,  1158,   173,  1026,  1027,  1021,  1158,    10,
      11,  1015,  1016,  1017,  1011,  1207,    86,     4,     6,     7,
     136,   954,  1175,   964,  1207,   187,   929,   930,   924,  1158,
      10,    11,   918,   919,   920,   914,  1207,    88,     6,     4,
      98,    10,  1214,    38,    39,  1213,  1220,  1221,   200,   850,
    1175,   860,  1207,   187,   825,   826,   820,  1158,    10,    11,
     814,   815,   816,   810,  1207,    88,   106,  1058,  1175,  1068,
    1207,   187,  1033,  1034,  1028,  1158,    10,    11,  1022,  1023,
    1024,  1018,  1207,    88,   136,   118,   931,  1158,    10,    11,
     925,   926,   927,   921,  1207,    84,     8,    98,     6,     8,
       8,   200,   118,   827,  1158,    10,    11,   821,   822,   823,
     817,  1207,    84,   106,   118,  1035,  1158,    10,    11,  1029,
    1030,  1031,  1025,  1207,    84,    10,    11,   932,   933,   934,
     928,  1207,   130,   116,     6,     6,    10,    11,   828,   829,
     830,   824,  1207,   130,    10,    11,  1036,  1037,  1038,  1032,
    1207,   130,   935,  1207,   174,     8,     8,   831,  1207,   174,
    1039,  1207,   174,   188,   188,   188
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


