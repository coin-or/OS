
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

#define OSRESULT_AVAILABLE

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
     NUMBEROFENUMERATIONSATT = 273,
     NUMBEROFIDXATT = 274,
     NUMBEROFITEMSATT = 275,
     NUMBEROFOBJATT = 276,
     NUMBEROFOBJECTIVESATT = 277,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 278,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 279,
     NUMBEROFOTHERRESULTSATT = 280,
     NUMBEROFOTHERSOLUTIONRESULTSATT = 281,
     NUMBEROFOTHERVARIABLERESULTSATT = 282,
     NUMBEROFSOLUTIONSATT = 283,
     NUMBEROFSOLVEROUTPUTSATT = 284,
     NUMBEROFSUBSTATUSESATT = 285,
     NUMBEROFTIMESATT = 286,
     NUMBEROFVARATT = 287,
     NUMBEROFVARIABLESATT = 288,
     TARGETOBJECTIVEIDXATT = 289,
     CATEGORYATT = 290,
     EMPTYCATEGORYATT = 291,
     DESCRIPTIONATT = 292,
     EMPTYDESCRIPTIONATT = 293,
     CONTYPEATT = 294,
     EMPTYCONTYPEATT = 295,
     ENUMTYPEATT = 296,
     EMPTYENUMTYPEATT = 297,
     OBJTYPEATT = 298,
     EMPTYOBJTYPEATT = 299,
     VARTYPEATT = 300,
     EMPTYVARTYPEATT = 301,
     UNITATT = 302,
     EMPTYUNITATT = 303,
     VALUEATT = 304,
     EMPTYVALUEATT = 305,
     WEIGHTEDOBJECTIVESATT = 306,
     EMPTYWEIGHTEDOBJECTIVESATT = 307,
     TARGETOBJECTIVENAMEATT = 308,
     EMPTYTARGETOBJECTIVENAMEATT = 309,
     MATRIXVARTYPEATT = 310,
     EMPTYMATRIXVARTYPEATT = 311,
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
     ACTUALSTARTTIMESTART = 322,
     ACTUALSTARTTIMEEND = 323,
     ATEQUALITYSTART = 324,
     ATEQUALITYEND = 325,
     ATLOWERSTART = 326,
     ATLOWEREND = 327,
     ATUPPERSTART = 328,
     ATUPPEREND = 329,
     AVAILABLECPUNUMBERSTART = 330,
     AVAILABLECPUNUMBEREND = 331,
     AVAILABLECPUSPEEDSTART = 332,
     AVAILABLECPUSPEEDEND = 333,
     AVAILABLEDISKSPACESTART = 334,
     AVAILABLEDISKSPACEEND = 335,
     AVAILABLEMEMORYSTART = 336,
     AVAILABLEMEMORYEND = 337,
     BASICSTART = 338,
     BASICEND = 339,
     BASISSTATUSSTART = 340,
     BASISSTATUSEND = 341,
     BASSTATUSSTART = 342,
     BASSTATUSEND = 343,
     CONSTART = 344,
     CONEND = 345,
     CONSTRAINTSSTART = 346,
     CONSTRAINTSEND = 347,
     CURRENTJOBCOUNTSTART = 348,
     CURRENTJOBCOUNTEND = 349,
     CURRENTSTATESTART = 350,
     CURRENTSTATEEND = 351,
     DUALVALUESSTART = 352,
     DUALVALUESEND = 353,
     ENDTIMESTART = 354,
     ENDTIMEEND = 355,
     GENERALSTATUSSTART = 356,
     GENERALSTATUSEND = 357,
     GENERALSUBSTATUSSTART = 358,
     GENERALSUBSTATUSEND = 359,
     IDXSTART = 360,
     IDXEND = 361,
     INSTANCENAMESTART = 362,
     INSTANCENAMEEND = 363,
     ISFREESTART = 364,
     ISFREEEND = 365,
     JOBIDSTART = 366,
     JOBIDEND = 367,
     MESSAGESTART = 368,
     MESSAGEEND = 369,
     OBJSTART = 370,
     OBJEND = 371,
     OBJECTIVESSTART = 372,
     OBJECTIVESEND = 373,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 374,
     OPTIMIZATIONSOLUTIONSTATUSEND = 375,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 376,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 377,
     OTHERSTART = 378,
     OTHEREND = 379,
     OTHERRESULTSSTART = 380,
     OTHERRESULTSEND = 381,
     OTHERSOLUTIONRESULTSTART = 382,
     OTHERSOLUTIONRESULTEND = 383,
     OTHERSOLUTIONRESULTSSTART = 384,
     OTHERSOLUTIONRESULTSEND = 385,
     OTHERSOLVEROUTPUTSTART = 386,
     OTHERSOLVEROUTPUTEND = 387,
     SCHEDULEDSTARTTIMESTART = 388,
     SCHEDULEDSTARTTIMEEND = 389,
     SERVICENAMESTART = 390,
     SERVICENAMEEND = 391,
     SERVICEURISTART = 392,
     SERVICEURIEND = 393,
     SERVICEUTILIZATIONSTART = 394,
     SERVICEUTILIZATIONEND = 395,
     SOLUTIONSTART = 396,
     SOLUTIONEND = 397,
     SOLVERINVOKEDSTART = 398,
     SOLVERINVOKEDEND = 399,
     SOLVEROUTPUTSTART = 400,
     SOLVEROUTPUTEND = 401,
     STATUSSTART = 402,
     STATUSEND = 403,
     SUBMITTIMESTART = 404,
     SUBMITTIMEEND = 405,
     SUBSTATUSSTART = 406,
     SUBSTATUSEND = 407,
     SUPERBASICSTART = 408,
     SUPERBASICEND = 409,
     SYSTEMINFORMATIONSTART = 410,
     SYSTEMINFORMATIONEND = 411,
     TIMESTART = 412,
     TIMEEND = 413,
     TIMESERVICESTARTEDSTART = 414,
     TIMESERVICESTARTEDEND = 415,
     TIMESTAMPSTART = 416,
     TIMESTAMPEND = 417,
     TIMINGINFORMATIONSTART = 418,
     TIMINGINFORMATIONEND = 419,
     TOTALJOBSSOFARSTART = 420,
     TOTALJOBSSOFAREND = 421,
     UNKNOWNSTART = 422,
     UNKNOWNEND = 423,
     USEDCPUNUMBERSTART = 424,
     USEDCPUNUMBEREND = 425,
     USEDCPUSPEEDSTART = 426,
     USEDCPUSPEEDEND = 427,
     USEDDISKSPACESTART = 428,
     USEDDISKSPACEEND = 429,
     USEDMEMORYSTART = 430,
     USEDMEMORYEND = 431,
     VALUESSTRINGSTART = 432,
     VALUESSTRINGEND = 433,
     VARSTART = 434,
     VAREND = 435,
     VARIABLESSTART = 436,
     VARIABLESEND = 437,
     MATRIXVARIABLEVALUESSTART = 438,
     MATRIXVARIABLEVALUESEND = 439,
     NUMBEROFOTHERMATRIXVARIABLERESULTSATT = 440,
     OTHERMATRIXVARIABLERESULTSTART = 441,
     OTHERMATRIXVARIABLERESULTEND = 442,
     NUMBEROFOTHERMATRIXPROGRAMMINGRESULTSATT = 443,
     OTHERMATRIXPROGRAMMINGRESULTSTART = 444,
     OTHERMATRIXPROGRAMMINGRESULTEND = 445,
     HEADERSTART = 446,
     HEADEREND = 447,
     FILENAMESTART = 448,
     FILENAMEEND = 449,
     FILENAMEEMPTY = 450,
     FILENAMESTARTANDEND = 451,
     FILESOURCESTART = 452,
     FILESOURCEEND = 453,
     FILESOURCEEMPTY = 454,
     FILESOURCESTARTANDEND = 455,
     FILEDESCRIPTIONSTART = 456,
     FILEDESCRIPTIONEND = 457,
     FILEDESCRIPTIONEMPTY = 458,
     FILEDESCRIPTIONSTARTANDEND = 459,
     FILECREATORSTART = 460,
     FILECREATOREND = 461,
     FILECREATOREMPTY = 462,
     FILECREATORSTARTANDEND = 463,
     FILELICENCESTART = 464,
     FILELICENCEEND = 465,
     FILELICENCEEMPTY = 466,
     FILELICENCESTARTANDEND = 467,
     ENUMERATIONSTART = 468,
     ENUMERATIONEND = 469,
     NUMBEROFELATT = 470,
     ITEMEMPTY = 471,
     ITEMSTART = 472,
     ITEMEND = 473,
     ITEMSTARTANDEND = 474,
     BASE64START = 475,
     BASE64END = 476,
     INCRATT = 477,
     MULTATT = 478,
     SIZEOFATT = 479,
     ELSTART = 480,
     ELEND = 481,
     MATRIXSTART = 482,
     MATRIXEND = 483,
     BASEMATRIXEND = 484,
     BASEMATRIXSTART = 485,
     BLOCKSTART = 486,
     BLOCKEND = 487,
     BLOCKSSTART = 488,
     BLOCKSEND = 489,
     EMPTYNAMEATT = 490,
     NAMEATT = 491,
     EMPTYTYPEATT = 492,
     TYPEATT = 493,
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
     NUMBEROFVARIDXATT = 505,
     IDXATT = 506,
     COEFATT = 507,
     MATRIXVARIDXATT = 508,
     MATRIXOBJIDXATT = 509,
     MATRIXCONIDXATT = 510,
     BASEMATRIXIDXATT = 511,
     TARGETMATRIXFIRSTROWATT = 512,
     TARGETMATRIXFIRSTCOLATT = 513,
     BASEMATRIXSTARTROWATT = 514,
     BASEMATRIXSTARTCOLATT = 515,
     BASEMATRIXENDROWATT = 516,
     BASEMATRIXENDCOLATT = 517,
     SCALARMULTIPLIERATT = 518,
     EMPTYBASETRANSPOSEATT = 519,
     BASETRANSPOSEATT = 520,
     ELEMENTSSTART = 521,
     ELEMENTSEND = 522,
     CONSTANTELEMENTSSTART = 523,
     CONSTANTELEMENTSEND = 524,
     STARTVECTORSTART = 525,
     STARTVECTOREND = 526,
     NONZEROSSTART = 527,
     NONZEROSEND = 528,
     INDEXSTART = 529,
     INDEXEND = 530,
     VALUESTART = 531,
     VALUEEND = 532,
     INDEXESSTART = 533,
     INDEXESEND = 534,
     VALUESSTART = 535,
     VALUESEND = 536,
     VARREFERENCEELEMENTSSTART = 537,
     VARREFERENCEELEMENTSEND = 538,
     LINEARELEMENTSSTART = 539,
     LINEARELEMENTSEND = 540,
     GENERALELEMENTSSTART = 541,
     GENERALELEMENTSEND = 542,
     CONREFERENCEELEMENTSSTART = 543,
     CONREFERENCEELEMENTSEND = 544,
     VALUETYPEATT = 545,
     OBJREFERENCEELEMENTSSTART = 546,
     OBJREFERENCEELEMENTSEND = 547,
     PATTERNELEMENTSSTART = 548,
     PATTERNELEMENTSEND = 549,
     VARIDXSTART = 550,
     VARIDXEND = 551,
     TRANSFORMATIONSTART = 552,
     TRANSFORMATIONEND = 553,
     COLOFFSETSTART = 554,
     COLOFFSETEND = 555,
     ROWOFFSETSTART = 556,
     ROWOFFSETEND = 557,
     EMPTYROWMAJORATT = 558,
     ROWMAJORATT = 559,
     BLOCKROWIDXATT = 560,
     BLOCKCOLIDXATT = 561,
     MATRIXPROGRAMMINGSTART = 562,
     MATRIXPROGRAMMINGEND = 563,
     MATRIXVARIABLESSTART = 564,
     MATRIXVARIABLESEND = 565,
     NUMBEROFMATRIXVARATT = 566,
     MATRIXVARSTART = 567,
     MATRIXVAREND = 568,
     MATRIXOBJECTIVESSTART = 569,
     MATRIXOBJECTIVESEND = 570,
     NUMBEROFMATRIXOBJATT = 571,
     MATRIXOBJSTART = 572,
     MATRIXOBJEND = 573,
     MATRIXCONSTRAINTSSTART = 574,
     MATRIXCONSTRAINTSEND = 575,
     NUMBEROFMATRIXCONATT = 576,
     MATRIXCONSTART = 577,
     MATRIXCONEND = 578,
     DUMMY = 579,
     NONLINEAREXPRESSIONSSTART = 580,
     NONLINEAREXPRESSIONSEND = 581,
     NUMBEROFNONLINEAREXPRESSIONS = 582,
     NLSTART = 583,
     NLEND = 584,
     MATRIXEXPRESSIONSSTART = 585,
     MATRIXEXPRESSIONSEND = 586,
     NUMBEROFEXPR = 587,
     EXPRSTART = 588,
     EXPREND = 589,
     NUMBEROFMATRIXTERMSATT = 590,
     MATRIXTERMSTART = 591,
     MATRIXTERMEND = 592,
     POWERSTART = 593,
     POWEREND = 594,
     PLUSSTART = 595,
     PLUSEND = 596,
     MINUSSTART = 597,
     MINUSEND = 598,
     DIVIDESTART = 599,
     DIVIDEEND = 600,
     LNSTART = 601,
     LNEND = 602,
     SQRTSTART = 603,
     SQRTEND = 604,
     SUMSTART = 605,
     SUMEND = 606,
     PRODUCTSTART = 607,
     PRODUCTEND = 608,
     EXPSTART = 609,
     EXPEND = 610,
     NEGATESTART = 611,
     NEGATEEND = 612,
     IFSTART = 613,
     IFEND = 614,
     SQUARESTART = 615,
     SQUAREEND = 616,
     COSSTART = 617,
     COSEND = 618,
     SINSTART = 619,
     SINEND = 620,
     VARIABLESTART = 621,
     VARIABLEEND = 622,
     ABSSTART = 623,
     ABSEND = 624,
     ERFSTART = 625,
     ERFEND = 626,
     MAXSTART = 627,
     MAXEND = 628,
     ALLDIFFSTART = 629,
     ALLDIFFEND = 630,
     MINSTART = 631,
     MINEND = 632,
     ESTART = 633,
     EEND = 634,
     PISTART = 635,
     PIEND = 636,
     TIMESSTART = 637,
     TIMESEND = 638,
     NUMBERSTART = 639,
     NUMBEREND = 640,
     MATRIXDETERMINANTSTART = 641,
     MATRIXDETERMINANTEND = 642,
     MATRIXTRACESTART = 643,
     MATRIXTRACEEND = 644,
     MATRIXTOSCALARSTART = 645,
     MATRIXTOSCALAREND = 646,
     MATRIXDIAGONALSTART = 647,
     MATRIXDIAGONALEND = 648,
     MATRIXDOTTIMESSTART = 649,
     MATRIXDOTTIMESEND = 650,
     MATRIXLOWERTRIANGLESTART = 651,
     MATRIXLOWERTRIANGLEEND = 652,
     MATRIXUPPERTRIANGLESTART = 653,
     MATRIXUPPERTRIANGLEEND = 654,
     MATRIXMERGESTART = 655,
     MATRIXMERGEEND = 656,
     MATRIXMINUSSTART = 657,
     MATRIXMINUSEND = 658,
     MATRIXNEGATESTART = 659,
     MATRIXNEGATEEND = 660,
     MATRIXPLUSSTART = 661,
     MATRIXPLUSEND = 662,
     MATRIXTIMESSTART = 663,
     MATRIXTIMESEND = 664,
     MATRIXPRODUCTSTART = 665,
     MATRIXPRODUCTEND = 666,
     MATRIXSCALARTIMESSTART = 667,
     MATRIXSCALARTIMESEND = 668,
     MATRIXSUBMATRIXATSTART = 669,
     MATRIXSUBMATRIXATEND = 670,
     MATRIXTRANSPOSESTART = 671,
     MATRIXTRANSPOSEEND = 672,
     MATRIXREFERENCESTART = 673,
     MATRIXREFERENCEEND = 674,
     IDENTITYMATRIXSTART = 675,
     IDENTITYMATRIXEND = 676,
     MATRIXINVERSESTART = 677,
     MATRIXINVERSEEND = 678,
     EMPTYINCLUDEDIAGONALATT = 679,
     INCLUDEDIAGONALATT = 680,
     IDATT = 681
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
#define NUMBEROFENUMERATIONSATT 273
#define NUMBEROFIDXATT 274
#define NUMBEROFITEMSATT 275
#define NUMBEROFOBJATT 276
#define NUMBEROFOBJECTIVESATT 277
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 278
#define NUMBEROFOTHEROBJECTIVERESULTSATT 279
#define NUMBEROFOTHERRESULTSATT 280
#define NUMBEROFOTHERSOLUTIONRESULTSATT 281
#define NUMBEROFOTHERVARIABLERESULTSATT 282
#define NUMBEROFSOLUTIONSATT 283
#define NUMBEROFSOLVEROUTPUTSATT 284
#define NUMBEROFSUBSTATUSESATT 285
#define NUMBEROFTIMESATT 286
#define NUMBEROFVARATT 287
#define NUMBEROFVARIABLESATT 288
#define TARGETOBJECTIVEIDXATT 289
#define CATEGORYATT 290
#define EMPTYCATEGORYATT 291
#define DESCRIPTIONATT 292
#define EMPTYDESCRIPTIONATT 293
#define CONTYPEATT 294
#define EMPTYCONTYPEATT 295
#define ENUMTYPEATT 296
#define EMPTYENUMTYPEATT 297
#define OBJTYPEATT 298
#define EMPTYOBJTYPEATT 299
#define VARTYPEATT 300
#define EMPTYVARTYPEATT 301
#define UNITATT 302
#define EMPTYUNITATT 303
#define VALUEATT 304
#define EMPTYVALUEATT 305
#define WEIGHTEDOBJECTIVESATT 306
#define EMPTYWEIGHTEDOBJECTIVESATT 307
#define TARGETOBJECTIVENAMEATT 308
#define EMPTYTARGETOBJECTIVENAMEATT 309
#define MATRIXVARTYPEATT 310
#define EMPTYMATRIXVARTYPEATT 311
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
#define ACTUALSTARTTIMESTART 322
#define ACTUALSTARTTIMEEND 323
#define ATEQUALITYSTART 324
#define ATEQUALITYEND 325
#define ATLOWERSTART 326
#define ATLOWEREND 327
#define ATUPPERSTART 328
#define ATUPPEREND 329
#define AVAILABLECPUNUMBERSTART 330
#define AVAILABLECPUNUMBEREND 331
#define AVAILABLECPUSPEEDSTART 332
#define AVAILABLECPUSPEEDEND 333
#define AVAILABLEDISKSPACESTART 334
#define AVAILABLEDISKSPACEEND 335
#define AVAILABLEMEMORYSTART 336
#define AVAILABLEMEMORYEND 337
#define BASICSTART 338
#define BASICEND 339
#define BASISSTATUSSTART 340
#define BASISSTATUSEND 341
#define BASSTATUSSTART 342
#define BASSTATUSEND 343
#define CONSTART 344
#define CONEND 345
#define CONSTRAINTSSTART 346
#define CONSTRAINTSEND 347
#define CURRENTJOBCOUNTSTART 348
#define CURRENTJOBCOUNTEND 349
#define CURRENTSTATESTART 350
#define CURRENTSTATEEND 351
#define DUALVALUESSTART 352
#define DUALVALUESEND 353
#define ENDTIMESTART 354
#define ENDTIMEEND 355
#define GENERALSTATUSSTART 356
#define GENERALSTATUSEND 357
#define GENERALSUBSTATUSSTART 358
#define GENERALSUBSTATUSEND 359
#define IDXSTART 360
#define IDXEND 361
#define INSTANCENAMESTART 362
#define INSTANCENAMEEND 363
#define ISFREESTART 364
#define ISFREEEND 365
#define JOBIDSTART 366
#define JOBIDEND 367
#define MESSAGESTART 368
#define MESSAGEEND 369
#define OBJSTART 370
#define OBJEND 371
#define OBJECTIVESSTART 372
#define OBJECTIVESEND 373
#define OPTIMIZATIONSOLUTIONSTATUSSTART 374
#define OPTIMIZATIONSOLUTIONSTATUSEND 375
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 376
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 377
#define OTHERSTART 378
#define OTHEREND 379
#define OTHERRESULTSSTART 380
#define OTHERRESULTSEND 381
#define OTHERSOLUTIONRESULTSTART 382
#define OTHERSOLUTIONRESULTEND 383
#define OTHERSOLUTIONRESULTSSTART 384
#define OTHERSOLUTIONRESULTSEND 385
#define OTHERSOLVEROUTPUTSTART 386
#define OTHERSOLVEROUTPUTEND 387
#define SCHEDULEDSTARTTIMESTART 388
#define SCHEDULEDSTARTTIMEEND 389
#define SERVICENAMESTART 390
#define SERVICENAMEEND 391
#define SERVICEURISTART 392
#define SERVICEURIEND 393
#define SERVICEUTILIZATIONSTART 394
#define SERVICEUTILIZATIONEND 395
#define SOLUTIONSTART 396
#define SOLUTIONEND 397
#define SOLVERINVOKEDSTART 398
#define SOLVERINVOKEDEND 399
#define SOLVEROUTPUTSTART 400
#define SOLVEROUTPUTEND 401
#define STATUSSTART 402
#define STATUSEND 403
#define SUBMITTIMESTART 404
#define SUBMITTIMEEND 405
#define SUBSTATUSSTART 406
#define SUBSTATUSEND 407
#define SUPERBASICSTART 408
#define SUPERBASICEND 409
#define SYSTEMINFORMATIONSTART 410
#define SYSTEMINFORMATIONEND 411
#define TIMESTART 412
#define TIMEEND 413
#define TIMESERVICESTARTEDSTART 414
#define TIMESERVICESTARTEDEND 415
#define TIMESTAMPSTART 416
#define TIMESTAMPEND 417
#define TIMINGINFORMATIONSTART 418
#define TIMINGINFORMATIONEND 419
#define TOTALJOBSSOFARSTART 420
#define TOTALJOBSSOFAREND 421
#define UNKNOWNSTART 422
#define UNKNOWNEND 423
#define USEDCPUNUMBERSTART 424
#define USEDCPUNUMBEREND 425
#define USEDCPUSPEEDSTART 426
#define USEDCPUSPEEDEND 427
#define USEDDISKSPACESTART 428
#define USEDDISKSPACEEND 429
#define USEDMEMORYSTART 430
#define USEDMEMORYEND 431
#define VALUESSTRINGSTART 432
#define VALUESSTRINGEND 433
#define VARSTART 434
#define VAREND 435
#define VARIABLESSTART 436
#define VARIABLESEND 437
#define MATRIXVARIABLEVALUESSTART 438
#define MATRIXVARIABLEVALUESEND 439
#define NUMBEROFOTHERMATRIXVARIABLERESULTSATT 440
#define OTHERMATRIXVARIABLERESULTSTART 441
#define OTHERMATRIXVARIABLERESULTEND 442
#define NUMBEROFOTHERMATRIXPROGRAMMINGRESULTSATT 443
#define OTHERMATRIXPROGRAMMINGRESULTSTART 444
#define OTHERMATRIXPROGRAMMINGRESULTEND 445
#define HEADERSTART 446
#define HEADEREND 447
#define FILENAMESTART 448
#define FILENAMEEND 449
#define FILENAMEEMPTY 450
#define FILENAMESTARTANDEND 451
#define FILESOURCESTART 452
#define FILESOURCEEND 453
#define FILESOURCEEMPTY 454
#define FILESOURCESTARTANDEND 455
#define FILEDESCRIPTIONSTART 456
#define FILEDESCRIPTIONEND 457
#define FILEDESCRIPTIONEMPTY 458
#define FILEDESCRIPTIONSTARTANDEND 459
#define FILECREATORSTART 460
#define FILECREATOREND 461
#define FILECREATOREMPTY 462
#define FILECREATORSTARTANDEND 463
#define FILELICENCESTART 464
#define FILELICENCEEND 465
#define FILELICENCEEMPTY 466
#define FILELICENCESTARTANDEND 467
#define ENUMERATIONSTART 468
#define ENUMERATIONEND 469
#define NUMBEROFELATT 470
#define ITEMEMPTY 471
#define ITEMSTART 472
#define ITEMEND 473
#define ITEMSTARTANDEND 474
#define BASE64START 475
#define BASE64END 476
#define INCRATT 477
#define MULTATT 478
#define SIZEOFATT 479
#define ELSTART 480
#define ELEND 481
#define MATRIXSTART 482
#define MATRIXEND 483
#define BASEMATRIXEND 484
#define BASEMATRIXSTART 485
#define BLOCKSTART 486
#define BLOCKEND 487
#define BLOCKSSTART 488
#define BLOCKSEND 489
#define EMPTYNAMEATT 490
#define NAMEATT 491
#define EMPTYTYPEATT 492
#define TYPEATT 493
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
#define NUMBEROFVARIDXATT 505
#define IDXATT 506
#define COEFATT 507
#define MATRIXVARIDXATT 508
#define MATRIXOBJIDXATT 509
#define MATRIXCONIDXATT 510
#define BASEMATRIXIDXATT 511
#define TARGETMATRIXFIRSTROWATT 512
#define TARGETMATRIXFIRSTCOLATT 513
#define BASEMATRIXSTARTROWATT 514
#define BASEMATRIXSTARTCOLATT 515
#define BASEMATRIXENDROWATT 516
#define BASEMATRIXENDCOLATT 517
#define SCALARMULTIPLIERATT 518
#define EMPTYBASETRANSPOSEATT 519
#define BASETRANSPOSEATT 520
#define ELEMENTSSTART 521
#define ELEMENTSEND 522
#define CONSTANTELEMENTSSTART 523
#define CONSTANTELEMENTSEND 524
#define STARTVECTORSTART 525
#define STARTVECTOREND 526
#define NONZEROSSTART 527
#define NONZEROSEND 528
#define INDEXSTART 529
#define INDEXEND 530
#define VALUESTART 531
#define VALUEEND 532
#define INDEXESSTART 533
#define INDEXESEND 534
#define VALUESSTART 535
#define VALUESEND 536
#define VARREFERENCEELEMENTSSTART 537
#define VARREFERENCEELEMENTSEND 538
#define LINEARELEMENTSSTART 539
#define LINEARELEMENTSEND 540
#define GENERALELEMENTSSTART 541
#define GENERALELEMENTSEND 542
#define CONREFERENCEELEMENTSSTART 543
#define CONREFERENCEELEMENTSEND 544
#define VALUETYPEATT 545
#define OBJREFERENCEELEMENTSSTART 546
#define OBJREFERENCEELEMENTSEND 547
#define PATTERNELEMENTSSTART 548
#define PATTERNELEMENTSEND 549
#define VARIDXSTART 550
#define VARIDXEND 551
#define TRANSFORMATIONSTART 552
#define TRANSFORMATIONEND 553
#define COLOFFSETSTART 554
#define COLOFFSETEND 555
#define ROWOFFSETSTART 556
#define ROWOFFSETEND 557
#define EMPTYROWMAJORATT 558
#define ROWMAJORATT 559
#define BLOCKROWIDXATT 560
#define BLOCKCOLIDXATT 561
#define MATRIXPROGRAMMINGSTART 562
#define MATRIXPROGRAMMINGEND 563
#define MATRIXVARIABLESSTART 564
#define MATRIXVARIABLESEND 565
#define NUMBEROFMATRIXVARATT 566
#define MATRIXVARSTART 567
#define MATRIXVAREND 568
#define MATRIXOBJECTIVESSTART 569
#define MATRIXOBJECTIVESEND 570
#define NUMBEROFMATRIXOBJATT 571
#define MATRIXOBJSTART 572
#define MATRIXOBJEND 573
#define MATRIXCONSTRAINTSSTART 574
#define MATRIXCONSTRAINTSEND 575
#define NUMBEROFMATRIXCONATT 576
#define MATRIXCONSTART 577
#define MATRIXCONEND 578
#define DUMMY 579
#define NONLINEAREXPRESSIONSSTART 580
#define NONLINEAREXPRESSIONSEND 581
#define NUMBEROFNONLINEAREXPRESSIONS 582
#define NLSTART 583
#define NLEND 584
#define MATRIXEXPRESSIONSSTART 585
#define MATRIXEXPRESSIONSEND 586
#define NUMBEROFEXPR 587
#define EXPRSTART 588
#define EXPREND 589
#define NUMBEROFMATRIXTERMSATT 590
#define MATRIXTERMSTART 591
#define MATRIXTERMEND 592
#define POWERSTART 593
#define POWEREND 594
#define PLUSSTART 595
#define PLUSEND 596
#define MINUSSTART 597
#define MINUSEND 598
#define DIVIDESTART 599
#define DIVIDEEND 600
#define LNSTART 601
#define LNEND 602
#define SQRTSTART 603
#define SQRTEND 604
#define SUMSTART 605
#define SUMEND 606
#define PRODUCTSTART 607
#define PRODUCTEND 608
#define EXPSTART 609
#define EXPEND 610
#define NEGATESTART 611
#define NEGATEEND 612
#define IFSTART 613
#define IFEND 614
#define SQUARESTART 615
#define SQUAREEND 616
#define COSSTART 617
#define COSEND 618
#define SINSTART 619
#define SINEND 620
#define VARIABLESTART 621
#define VARIABLEEND 622
#define ABSSTART 623
#define ABSEND 624
#define ERFSTART 625
#define ERFEND 626
#define MAXSTART 627
#define MAXEND 628
#define ALLDIFFSTART 629
#define ALLDIFFEND 630
#define MINSTART 631
#define MINEND 632
#define ESTART 633
#define EEND 634
#define PISTART 635
#define PIEND 636
#define TIMESSTART 637
#define TIMESEND 638
#define NUMBERSTART 639
#define NUMBEREND 640
#define MATRIXDETERMINANTSTART 641
#define MATRIXDETERMINANTEND 642
#define MATRIXTRACESTART 643
#define MATRIXTRACEEND 644
#define MATRIXTOSCALARSTART 645
#define MATRIXTOSCALAREND 646
#define MATRIXDIAGONALSTART 647
#define MATRIXDIAGONALEND 648
#define MATRIXDOTTIMESSTART 649
#define MATRIXDOTTIMESEND 650
#define MATRIXLOWERTRIANGLESTART 651
#define MATRIXLOWERTRIANGLEEND 652
#define MATRIXUPPERTRIANGLESTART 653
#define MATRIXUPPERTRIANGLEEND 654
#define MATRIXMERGESTART 655
#define MATRIXMERGEEND 656
#define MATRIXMINUSSTART 657
#define MATRIXMINUSEND 658
#define MATRIXNEGATESTART 659
#define MATRIXNEGATEEND 660
#define MATRIXPLUSSTART 661
#define MATRIXPLUSEND 662
#define MATRIXTIMESSTART 663
#define MATRIXTIMESEND 664
#define MATRIXPRODUCTSTART 665
#define MATRIXPRODUCTEND 666
#define MATRIXSCALARTIMESSTART 667
#define MATRIXSCALARTIMESEND 668
#define MATRIXSUBMATRIXATSTART 669
#define MATRIXSUBMATRIXATEND 670
#define MATRIXTRANSPOSESTART 671
#define MATRIXTRANSPOSEEND 672
#define MATRIXREFERENCESTART 673
#define MATRIXREFERENCEEND 674
#define IDENTITYMATRIXSTART 675
#define IDENTITYMATRIXEND 676
#define MATRIXINVERSESTART 677
#define MATRIXINVERSEEND 678
#define EMPTYINCLUDEDIAGONALATT 679
#define INCLUDEDIAGONALATT 680
#define IDATT 681




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
#define YYLAST   2273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  431
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  1206
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1768
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2506

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   681

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   428,
     430,     2,     2,   429,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   427,     2,     2,     2,     2,     2,     2,     2,
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
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426
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
    1145,  1149,  1151,  1153,  1155,  1158,  1160,  1162,  1164,  1166,
    1168,  1171,  1173,  1177,  1179,  1181,  1184,  1188,  1190,  1192,
    1193,  1196,  1198,  1200,  1203,  1205,  1206,  1209,  1211,  1213,
    1215,  1218,  1220,  1224,  1226,  1227,  1231,  1233,  1234,  1236,
    1238,  1240,  1242,  1246,  1251,  1252,  1256,  1258,  1260,  1262,
    1264,  1267,  1269,  1273,  1275,  1277,  1280,  1284,  1286,  1287,
    1290,  1292,  1294,  1298,  1299,  1303,  1305,  1307,  1309,  1311,
    1314,  1316,  1320,  1322,  1324,  1327,  1331,  1333,  1334,  1337,
    1339,  1341,  1343,  1345,  1348,  1350,  1354,  1356,  1357,  1360,
    1362,  1364,  1366,  1368,  1372,  1380,  1381,  1385,  1387,  1389,
    1391,  1393,  1395,  1399,  1401,  1402,  1406,  1408,  1410,  1412,
    1414,  1416,  1420,  1422,  1423,  1427,  1429,  1431,  1433,  1435,
    1437,  1441,  1443,  1444,  1448,  1450,  1452,  1454,  1456,  1458,
    1462,  1464,  1465,  1469,  1471,  1473,  1475,  1477,  1479,  1483,
    1485,  1486,  1490,  1492,  1494,  1496,  1498,  1500,  1504,  1506,
    1507,  1511,  1513,  1515,  1517,  1519,  1521,  1525,  1527,  1528,
    1531,  1535,  1537,  1539,  1540,  1543,  1545,  1547,  1549,  1551,
    1553,  1555,  1557,  1559,  1561,  1563,  1566,  1568,  1572,  1574,
    1576,  1578,  1581,  1585,  1587,  1588,  1591,  1593,  1595,  1597,
    1599,  1602,  1604,  1608,  1610,  1612,  1615,  1619,  1621,  1623,
    1624,  1627,  1629,  1631,  1633,  1635,  1637,  1639,  1643,  1645,
    1646,  1650,  1652,  1653,  1655,  1657,  1659,  1661,  1665,  1669,
    1670,  1674,  1676,  1678,  1680,  1682,  1685,  1687,  1691,  1693,
    1695,  1698,  1702,  1704,  1705,  1708,  1710,  1712,  1716,  1717,
    1720,  1722,  1724,  1726,  1728,  1732,  1740,  1741,  1745,  1747,
    1749,  1751,  1753,  1755,  1759,  1761,  1762,  1766,  1768,  1770,
    1772,  1774,  1776,  1780,  1782,  1783,  1787,  1789,  1791,  1793,
    1795,  1797,  1801,  1803,  1804,  1808,  1810,  1812,  1814,  1816,
    1818,  1822,  1824,  1825,  1829,  1831,  1833,  1835,  1837,  1839,
    1843,  1845,  1846,  1850,  1852,  1854,  1856,  1858,  1860,  1864,
    1866,  1867,  1871,  1873,  1875,  1877,  1879,  1881,  1885,  1887,
    1888,  1891,  1895,  1897,  1899,  1900,  1903,  1905,  1907,  1909,
    1911,  1913,  1915,  1917,  1919,  1921,  1923,  1926,  1928,  1932,
    1934,  1936,  1938,  1941,  1945,  1947,  1948,  1951,  1953,  1955,
    1957,  1959,  1962,  1964,  1968,  1970,  1972,  1975,  1979,  1981,
    1983,  1984,  1987,  1989,  1991,  1993,  1995,  1997,  1999,  2003,
    2005,  2006,  2010,  2012,  2013,  2015,  2017,  2019,  2021,  2025,
    2029,  2030,  2034,  2036,  2038,  2040,  2042,  2045,  2047,  2051,
    2053,  2055,  2058,  2062,  2064,  2065,  2068,  2070,  2072,  2076,
    2077,  2080,  2082,  2084,  2086,  2088,  2092,  2100,  2101,  2105,
    2107,  2109,  2111,  2113,  2115,  2119,  2121,  2122,  2126,  2128,
    2130,  2132,  2134,  2136,  2140,  2142,  2143,  2147,  2149,  2151,
    2153,  2155,  2157,  2161,  2163,  2164,  2168,  2170,  2172,  2174,
    2176,  2178,  2182,  2184,  2185,  2189,  2191,  2193,  2195,  2197,
    2199,  2203,  2205,  2206,  2210,  2212,  2214,  2216,  2218,  2220,
    2224,  2226,  2227,  2231,  2233,  2235,  2237,  2239,  2241,  2245,
    2247,  2248,  2251,  2255,  2257,  2259,  2260,  2263,  2265,  2267,
    2269,  2271,  2273,  2275,  2277,  2279,  2281,  2283,  2286,  2288,
    2292,  2294,  2296,  2298,  2301,  2305,  2307,  2308,  2311,  2313,
    2315,  2317,  2319,  2322,  2324,  2328,  2330,  2332,  2335,  2339,
    2341,  2343,  2344,  2347,  2349,  2351,  2353,  2355,  2357,  2359,
    2363,  2365,  2366,  2369,  2371,  2373,  2375,  2377,  2382,  2383,
    2387,  2389,  2391,  2393,  2395,  2397,  2402,  2404,  2405,  2409,
    2411,  2413,  2415,  2417,  2419,  2423,  2425,  2426,  2429,  2430,
    2433,  2437,  2439,  2441,  2442,  2445,  2447,  2449,  2451,  2453,
    2455,  2457,  2459,  2461,  2463,  2465,  2468,  2470,  2474,  2476,
    2478,  2480,  2483,  2485,  2488,  2492,  2494,  2496,  2497,  2500,
    2502,  2504,  2506,  2508,  2510,  2512,  2516,  2518,  2519,  2522,
    2524,  2525,  2529,  2531,  2533,  2535,  2537,  2540,  2542,  2546,
    2548,  2550,  2553,  2557,  2559,  2561,  2562,  2565,  2567,  2569,
    2571,  2573,  2575,  2577,  2579,  2582,  2584,  2588,  2590,  2592,
    2595,  2597,  2599,  2601,  2603,  2605,  2609,  2611,  2612,  2616,
    2618,  2620,  2622,  2624,  2627,  2629,  2633,  2635,  2637,  2640,
    2644,  2646,  2648,  2649,  2652,  2654,  2656,  2658,  2660,  2662,
    2664,  2667,  2669,  2673,  2675,  2677,  2680,  2682,  2684,  2686,
    2688,  2690,  2694,  2696,  2698,  2700,  2702,  2704,  2708,  2710,
    2712,  2714,  2716,  2720,  2722,  2724,  2726,  2728,  2732,  2734,
    2736,  2738,  2740,  2744,  2748,  2753,  2755,  2757,  2759,  2761,
    2765,  2767,  2769,  2771,  2773,  2777,  2779,  2781,  2783,  2785,
    2789,  2791,  2793,  2795,  2797,  2801,  2803,  2805,  2807,  2809,
    2813,  2815,  2817,  2819,  2821,  2825,  2830,  2835,  2840,  2845,
    2850,  2855,  2860,  2865,  2870,  2875,  2880,  2885,  2890,  2895,
    2900,  2905,  2910,  2915,  2920,  2925,  2927,  2929,  2931,  2933,
    2935,  2938,  2939,  2942,  2944,  2946,  2948,  2950,  2953,  2955,
    2957,  2959,  2961,  2965,  2967,  2968,  2971,  2973,  2975,  2977,
    2979,  2981,  2983,  2985,  2987,  2989,  2991,  2995,  2997,  2999,
    3001,  3003,  3005,  3009,  3011,  3013,  3015,  3017,  3019,  3023,
    3025,  3027,  3029,  3031,  3033,  3037,  3039,  3041,  3043,  3045,
    3047,  3051,  3053,  3055,  3056,  3059,  3063,  3065,  3067,  3068,
    3071,  3073,  3075,  3079,  3083,  3085,  3087,  3090,  3092,  3096,
    3098,  3100,  3101,  3104,  3108,  3110,  3111,  3113,  3117,  3121,
    3123,  3125,  3128,  3130,  3134,  3135,  3140,  3142,  3144,  3145,
    3148,  3150,  3152,  3154,  3156,  3158,  3160,  3164,  3168,  3172,
    3177,  3179,  3181,  3183,  3187,  3190,  3191,  3195,  3197,  3199,
    3200,  3203,  3205,  3207,  3209,  3211,  3213,  3215,  3217,  3219,
    3221,  3226,  3231,  3236,  3241,  3246,  3251,  3256,  3258,  3260,
    3262,  3264,  3268,  3273,  3276,  3278,  3279,  3282,  3284,  3286,
    3288,  3290,  3292,  3294,  3296,  3298,  3303,  3305,  3307,  3308,
    3311,  3313,  3315,  3319,  3320,  3323,  3326,  3328,  3330,  3332,
    3334,  3338,  3340,  3343,  3345,  3347,  3349,  3351,  3355,  3357,
    3360,  3362,  3364,  3366,  3368,  3372,  3374,  3379,  3381,  3383,
    3384,  3387,  3389,  3391,  3395,  3396,  3399,  3402,  3404,  3406,
    3408,  3410,  3414,  3416,  3421,  3423,  3425,  3426,  3429,  3431,
    3433,  3437,  3438,  3441,  3442,  3445,  3447,  3449,  3451,  3453,
    3457,  3459,  3460,  3463,  3467,  3469,  3471,  3472,  3475,  3477,
    3479,  3484,  3486,  3488,  3490,  3494,  3495,  3498,  3502,  3504,
    3505,  3510,  3514,  3519,  3521,  3523,  3524,  3527,  3529,  3531,
    3535,  3536,  3539,  3540,  3543,  3545,  3547,  3549,  3551,  3555,
    3556,  3559,  3562,  3564,  3566,  3568,  3570,  3574,  3579,  3581,
    3583,  3584,  3587,  3589,  3591,  3595,  3596,  3599,  3602,  3604,
    3606,  3608,  3610,  3614,  3616,  3621,  3623,  3625,  3626,  3629,
    3631,  3633,  3637,  3638,  3641,  3642,  3645,  3647,  3649,  3651,
    3653,  3657,  3658,  3661,  3665,  3667,  3668,  3671,  3673,  3675,
    3677,  3681,  3685,  3691,  3693,  3694,  3696,  3698,  3702,  3704,
    3706,  3712,  3714,  3718,  3720,  3722,  3724,  3726,  3728,  3732,
    3734,  3738,  3740,  3742,  3744,  3746,  3748,  3752,  3754,  3755,
    3758,  3762,  3764,  3766,  3767,  3770,  3772,  3774,  3776,  3778,
    3783,  3788,  3790,  3792,  3794,  3798,  3801,  3806,  3811,  3816,
    3821,  3826,  3831,  3836,  3841,  3846,  3850,  3852,  3854,  3856,
    3860,  3862,  3864,  3866,  3868,  3870,  3872,  3874,  3876,  3878,
    3880,  3882,  3884,  3886,  3888,  3890,  3892,  3894,  3896,  3898,
    3900,  3902,  3904,  3906,  3908,  3910,  3912,  3914,  3915,  3919,
    3921,  3924,  3925,  3929,  3931,  3934,  3935,  3941,  3942,  3948,
    3949,  3955,  3956,  3961,  3962,  3968,  3969,  3975,  3976,  3981,
    3982,  3987,  3988,  3993,  3994,  3999,  4000,  4005,  4006,  4011,
    4015,  4017,  4019,  4020,  4025,  4026,  4033,  4034,  4039,  4040,
    4045,  4046,  4051,  4052,  4057,  4059,  4062,  4063,  4066,  4068,
    4070,  4072,  4073,  4078,  4079,  4084,  4089,  4090,  4095,  4097,
    4100,  4101,  4106,  4107,  4110,  4112,  4114,  4119,  4124,  4125,
    4130,  4131,  4134,  4135,  4140,  4141,  4144,  4145,  4150,  4151,
    4154,  4155,  4160,  4161,  4164,  4165,  4170,  4171,  4174,  4176,
    4178,  4180,  4182,  4184,  4186,  4188,  4190,  4192,  4194,  4196,
    4198,  4200,  4202,  4204,  4206,  4208,  4210,  4212,  4216,  4218,
    4220,  4223,  4228,  4232,  4234,  4236,  4239,  4244,  4248,  4250,
    4252,  4255,  4260,  4264,  4266,  4268,  4271,  4276,  4279,  4281,
    4284,  4287,  4289,  4293,  4296,  4298,  4301,  4304,  4306,  4309,
    4314,  4316,  4317,  4319,  4322,  4327,  4329,  4330,  4332,  4335,
    4339,  4342,  4344,  4346,  4349,  4352,  4354,  4358,  4361,  4363,
    4366,  4369,  4371,  4375,  4378,  4380,  4384,  4385,  4390,  4391,
    4394,  4397,  4399,  4403,  4406,  4408,  4415,  4418,  4420
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     432,     0,    -1,   433,   441,   439,    -1,   434,   435,   436,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   437,    -1,
     438,    -1,    11,    -1,    10,   441,   439,    -1,   440,    -1,
      15,    -1,    -1,   442,   443,   523,   577,   629,   724,    -1,
      -1,  1249,    -1,    -1,   444,   445,    -1,    57,    -1,   446,
      -1,   447,    -1,    10,    58,    -1,    11,    -1,    10,   448,
      58,    -1,   449,    -1,   450,    -1,   449,   450,    -1,   451,
      -1,   467,    -1,   473,    -1,   479,    -1,   485,    -1,   491,
      -1,   497,    -1,   503,    -1,   509,    -1,   452,   453,   456,
      -1,   101,    -1,   454,    -1,   455,    -1,   454,   455,    -1,
    1208,    -1,  1190,    -1,  1240,    -1,   457,    -1,   458,    -1,
      10,   102,    -1,    11,    -1,    10,   459,   102,    -1,   460,
      -1,   461,    -1,   460,   461,    -1,   462,   463,   466,    -1,
     151,    -1,   464,    -1,    -1,   464,   465,    -1,  1200,    -1,
    1190,    -1,    10,   152,    -1,    11,    -1,   468,   469,    -1,
     113,    -1,   470,    -1,   471,    -1,    10,   114,    -1,    11,
      -1,    10,   472,   114,    -1,     4,    -1,   474,   475,    -1,
     137,    -1,   476,    -1,   477,    -1,    10,   138,    -1,    11,
      -1,    10,   478,   138,    -1,     4,    -1,   480,   481,    -1,
     135,    -1,   482,    -1,   483,    -1,    10,   136,    -1,    11,
      -1,    10,   484,   136,    -1,     4,    -1,   486,   487,    -1,
     107,    -1,   488,    -1,   489,    -1,    10,   108,    -1,    11,
      -1,    10,   490,   108,    -1,     4,    -1,   492,   493,    -1,
     111,    -1,   494,    -1,   495,    -1,    10,   112,    -1,    11,
      -1,    10,   496,   112,    -1,     4,    -1,   498,   499,    -1,
     143,    -1,   500,    -1,   501,    -1,    10,   144,    -1,    11,
      -1,    10,   502,   144,    -1,     4,    -1,   504,   505,    -1,
     161,    -1,   506,    -1,   507,    -1,    10,   162,    -1,    11,
      -1,    10,   508,   162,    -1,     4,    -1,   510,   511,   512,
      -1,   125,    -1,  1235,    -1,   513,    -1,   514,    -1,    10,
     126,    -1,    11,    -1,    10,   515,   126,    -1,   516,    -1,
     517,    -1,   516,   517,    -1,   518,   519,   522,    -1,   123,
      -1,   520,    -1,    -1,   520,   521,    -1,  1200,    -1,  1216,
      -1,  1190,    -1,    10,   124,    -1,    11,    -1,    -1,   524,
     525,    -1,    59,    -1,   526,    -1,   527,    -1,    10,    60,
      -1,    11,    -1,    10,   528,    60,    -1,   529,    -1,   530,
      -1,   529,   530,    -1,   531,    -1,   537,    -1,   544,    -1,
     551,    -1,   558,    -1,   563,    -1,   532,   533,    -1,   155,
      -1,   534,    -1,   535,    -1,    10,   156,    -1,    11,    -1,
      10,   536,   156,    -1,     4,    -1,   538,   539,   542,    -1,
      79,    -1,   540,    -1,    -1,   540,   541,    -1,  1212,    -1,
    1190,    -1,    10,   543,    80,    -1,  1244,    -1,   545,   546,
     549,    -1,    81,    -1,   547,    -1,    -1,   547,   548,    -1,
    1212,    -1,  1190,    -1,    10,   550,    82,    -1,  1244,    -1,
     552,   553,   556,    -1,    77,    -1,   554,    -1,    -1,   554,
     555,    -1,  1212,    -1,  1190,    -1,    10,   557,    78,    -1,
    1244,    -1,   559,   560,   561,    -1,    75,    -1,    -1,  1190,
      -1,    10,   562,    76,    -1,     6,    -1,   564,   565,   566,
      -1,   125,    -1,  1235,    -1,   567,    -1,   568,    -1,    10,
     126,    -1,    11,    -1,    10,   569,   126,    -1,   570,    -1,
     571,    -1,   570,   571,    -1,   572,   573,   576,    -1,   123,
      -1,   574,    -1,    -1,   574,   575,    -1,  1200,    -1,  1216,
      -1,  1190,    -1,    10,   124,    -1,    11,    -1,    -1,   578,
     579,    -1,    61,    -1,   580,    -1,   581,    -1,    10,    62,
      -1,    11,    -1,    10,   582,    62,    -1,   583,    -1,   584,
      -1,   583,   584,    -1,   585,    -1,   591,    -1,   597,    -1,
     603,    -1,   609,    -1,   615,    -1,   586,   587,    -1,    95,
      -1,   588,    -1,   589,    -1,    10,    96,    -1,    11,    -1,
      10,   590,    96,    -1,     4,    -1,   592,   593,    -1,    93,
      -1,   594,    -1,   595,    -1,    10,    94,    -1,    11,    -1,
      10,   596,    94,    -1,     6,    -1,   598,   599,    -1,   165,
      -1,   600,    -1,   601,    -1,    10,   166,    -1,    11,    -1,
      10,   602,   166,    -1,     6,    -1,   604,   605,    -1,   159,
      -1,   606,    -1,   607,    -1,    10,   160,    -1,    11,    -1,
      10,   608,   160,    -1,     4,    -1,   610,   611,    -1,   139,
      -1,   612,    -1,   613,    -1,    10,   140,    -1,    11,    -1,
      10,   614,   140,    -1,  1244,    -1,   616,   617,   618,    -1,
     125,    -1,  1235,    -1,   619,    -1,   620,    -1,    10,   126,
      -1,    11,    -1,    10,   621,   126,    -1,   622,    -1,   623,
      -1,   622,   623,    -1,   624,   625,   628,    -1,   123,    -1,
     626,    -1,    -1,   626,   627,    -1,  1200,    -1,  1216,    -1,
    1190,    -1,    10,   124,    -1,    11,    -1,    -1,   630,   631,
      -1,    63,    -1,   632,    -1,   633,    -1,    10,    64,    -1,
      11,    -1,    10,   634,    64,    -1,   635,    -1,   636,    -1,
     635,   636,    -1,   637,    -1,   643,    -1,   649,    -1,   655,
      -1,   661,    -1,   667,    -1,   684,    -1,   691,    -1,   698,
      -1,   705,    -1,   710,    -1,   638,   639,    -1,   147,    -1,
     640,    -1,   641,    -1,    10,   148,    -1,    11,    -1,    10,
     642,   148,    -1,     4,    -1,   644,   645,    -1,   149,    -1,
     646,    -1,   647,    -1,    10,   150,    -1,    11,    -1,    10,
     648,   150,    -1,     4,    -1,   650,   651,    -1,   133,    -1,
     652,    -1,   653,    -1,    10,   134,    -1,    11,    -1,    10,
     654,   134,    -1,     4,    -1,   656,   657,    -1,    67,    -1,
     658,    -1,   659,    -1,    10,    68,    -1,    11,    -1,    10,
     660,    68,    -1,     4,    -1,   662,   663,    -1,    99,    -1,
     664,    -1,   665,    -1,    10,   100,    -1,    11,    -1,    10,
     666,   100,    -1,     4,    -1,   668,   669,   670,    -1,   163,
      -1,  1241,    -1,   671,    -1,   672,    -1,    10,   164,    -1,
      11,    -1,    10,   673,   164,    -1,   674,    -1,   675,    -1,
     674,   675,    -1,   676,   677,   679,    -1,   157,    -1,    -1,
     677,   678,    -1,  1212,    -1,  1208,    -1,  1182,    -1,  1190,
      -1,   680,    -1,   681,    -1,    10,   158,    -1,    11,    -1,
      10,   682,   158,    -1,   683,    -1,     7,    -1,     6,    -1,
     685,   686,   689,    -1,   173,    -1,   687,    -1,    -1,   687,
     688,    -1,  1212,    -1,  1190,    -1,    10,   690,   174,    -1,
    1244,    -1,   692,   693,   696,    -1,   175,    -1,   694,    -1,
      -1,   694,   695,    -1,  1212,    -1,  1190,    -1,    10,   697,
     176,    -1,  1244,    -1,   699,   700,   703,    -1,   171,    -1,
     701,    -1,    -1,   701,   702,    -1,  1212,    -1,  1190,    -1,
      10,   704,   172,    -1,  1244,    -1,   706,   707,   708,    -1,
     169,    -1,    -1,  1190,    -1,    10,   709,   170,    -1,     6,
      -1,   711,   712,   713,    -1,   125,    -1,  1235,    -1,   714,
      -1,   715,    -1,    10,   126,    -1,    11,    -1,    10,   716,
     126,    -1,   717,    -1,   718,    -1,   717,   718,    -1,   719,
     720,   723,    -1,   123,    -1,   721,    -1,    -1,   721,   722,
      -1,  1200,    -1,  1216,    -1,  1190,    -1,    10,   124,    -1,
      11,    -1,    -1,   725,   726,   729,    -1,    65,    -1,   727,
      -1,    -1,   727,   728,    -1,  1238,    -1,  1243,    -1,  1225,
      -1,  1231,    -1,   730,    -1,   731,    -1,    10,    66,    -1,
      11,    -1,    10,   732,    66,    -1,   733,  1159,    -1,   734,
      -1,   733,   734,    -1,   735,   736,   742,    -1,   141,    -1,
     737,    -1,    -1,   737,   738,    -1,   739,    -1,   740,    -1,
     741,    -1,    34,  1246,     6,  1246,    -1,    53,     3,  1246,
      -1,    51,     3,  1246,    -1,    10,   743,   759,   765,   885,
     989,  1093,  1136,   142,    -1,   744,   745,   748,    -1,   147,
      -1,   746,    -1,   747,    -1,   746,   747,    -1,  1208,    -1,
    1190,    -1,  1240,    -1,   749,    -1,   750,    -1,    10,   148,
      -1,    11,    -1,    10,   751,   148,    -1,   752,    -1,   753,
      -1,   752,   753,    -1,   754,   755,   758,    -1,   151,    -1,
     756,    -1,    -1,   756,   757,    -1,  1208,    -1,  1190,    -1,
      10,   152,    -1,    11,    -1,    -1,   760,   761,    -1,   113,
      -1,   762,    -1,   763,    -1,    10,   114,    -1,    11,    -1,
      10,   764,   114,    -1,     4,    -1,    -1,   766,   767,   768,
      -1,   181,    -1,    -1,  1237,    -1,   769,    -1,   770,    -1,
      11,    -1,    10,   771,   182,    -1,   772,   785,   801,   856,
      -1,    -1,   773,   774,   775,    -1,   280,    -1,  1242,    -1,
     776,    -1,   777,    -1,    10,   281,    -1,    11,    -1,    10,
     778,   281,    -1,   779,    -1,   780,    -1,   779,   780,    -1,
     781,   782,   784,    -1,   179,    -1,    -1,   782,   783,    -1,
    1199,    -1,  1200,    -1,    10,  1244,   180,    -1,    -1,   786,
     787,   788,    -1,   177,    -1,  1242,    -1,   789,    -1,   790,
      -1,    10,   178,    -1,    11,    -1,    10,   791,   178,    -1,
     792,    -1,   793,    -1,   792,   793,    -1,   794,   795,   797,
      -1,   179,    -1,    -1,   795,   796,    -1,  1199,    -1,  1200,
      -1,   798,    -1,   799,    -1,    10,   180,    -1,    11,    -1,
      10,   800,   180,    -1,     4,    -1,    -1,   802,   803,    -1,
      85,    -1,   804,    -1,   805,    -1,    11,    -1,    10,   806,
      86,    -1,   807,   814,   821,   828,   835,   842,   849,    -1,
      -1,   808,   809,   810,    -1,    83,    -1,  1226,    -1,   811,
      -1,   812,    -1,    11,    -1,    10,   813,    84,    -1,  1277,
      -1,    -1,   815,   816,   817,    -1,    71,    -1,  1226,    -1,
     818,    -1,   819,    -1,    11,    -1,    10,   820,    72,    -1,
    1277,    -1,    -1,   822,   823,   824,    -1,    73,    -1,  1226,
      -1,   825,    -1,   826,    -1,    11,    -1,    10,   827,    74,
      -1,  1277,    -1,    -1,   829,   830,   831,    -1,    69,    -1,
    1226,    -1,   832,    -1,   833,    -1,    11,    -1,    10,   834,
      70,    -1,  1277,    -1,    -1,   836,   837,   838,    -1,   109,
      -1,  1226,    -1,   839,    -1,   840,    -1,    11,    -1,    10,
     841,   110,    -1,  1277,    -1,    -1,   843,   844,   845,    -1,
     153,    -1,  1226,    -1,   846,    -1,   847,    -1,    11,    -1,
      10,   848,   154,    -1,  1277,    -1,    -1,   850,   851,   852,
      -1,   167,    -1,  1226,    -1,   853,    -1,   854,    -1,    11,
      -1,    10,   855,   168,    -1,  1277,    -1,    -1,   856,   857,
      -1,   858,   859,   862,    -1,   123,    -1,   860,    -1,    -1,
     860,   861,    -1,  1242,    -1,  1227,    -1,  1216,    -1,  1200,
      -1,  1208,    -1,  1220,    -1,  1194,    -1,  1190,    -1,   863,
      -1,   864,    -1,    10,   124,    -1,    11,    -1,    10,   865,
     124,    -1,   866,    -1,   875,    -1,   867,    -1,   866,   867,
      -1,   868,   869,   871,    -1,   179,    -1,    -1,   869,   870,
      -1,  1199,    -1,  1200,    -1,   872,    -1,   873,    -1,    10,
     180,    -1,    11,    -1,    10,   874,   180,    -1,  1245,    -1,
     876,    -1,   875,   876,    -1,   877,   878,   881,    -1,   213,
      -1,   879,    -1,    -1,   879,   880,    -1,  1226,    -1,  1216,
      -1,  1190,    -1,   882,    -1,   883,    -1,    11,    -1,    10,
     884,   214,    -1,  1277,    -1,    -1,   886,   887,   888,    -1,
     117,    -1,    -1,  1234,    -1,   889,    -1,   890,    -1,    11,
      -1,    10,   891,   118,    -1,   892,   905,   960,    -1,    -1,
     893,   894,   895,    -1,   280,    -1,  1230,    -1,   896,    -1,
     897,    -1,    10,   281,    -1,    11,    -1,    10,   898,   281,
      -1,   899,    -1,   900,    -1,   899,   900,    -1,   901,   902,
     904,    -1,   115,    -1,    -1,   902,   903,    -1,  1199,    -1,
    1200,    -1,    10,  1244,   116,    -1,    -1,   906,   907,    -1,
      85,    -1,   908,    -1,   909,    -1,    11,    -1,    10,   910,
      86,    -1,   911,   918,   925,   932,   939,   946,   953,    -1,
      -1,   912,   913,   914,    -1,    83,    -1,  1226,    -1,   915,
      -1,   916,    -1,    11,    -1,    10,   917,    84,    -1,  1277,
      -1,    -1,   919,   920,   921,    -1,    71,    -1,  1226,    -1,
     922,    -1,   923,    -1,    11,    -1,    10,   924,    72,    -1,
    1277,    -1,    -1,   926,   927,   928,    -1,    73,    -1,  1226,
      -1,   929,    -1,   930,    -1,    11,    -1,    10,   931,    74,
      -1,  1277,    -1,    -1,   933,   934,   935,    -1,    69,    -1,
    1226,    -1,   936,    -1,   937,    -1,    11,    -1,    10,   938,
      70,    -1,  1277,    -1,    -1,   940,   941,   942,    -1,   109,
      -1,  1226,    -1,   943,    -1,   944,    -1,    11,    -1,    10,
     945,   110,    -1,  1277,    -1,    -1,   947,   948,   949,    -1,
     153,    -1,  1226,    -1,   950,    -1,   951,    -1,    11,    -1,
      10,   952,   154,    -1,  1277,    -1,    -1,   954,   955,   956,
      -1,   167,    -1,  1226,    -1,   957,    -1,   958,    -1,    11,
      -1,    10,   959,   168,    -1,  1277,    -1,    -1,   960,   961,
      -1,   962,   963,   966,    -1,   123,    -1,   964,    -1,    -1,
     964,   965,    -1,  1230,    -1,  1227,    -1,  1216,    -1,  1200,
      -1,  1208,    -1,  1204,    -1,  1194,    -1,  1190,    -1,   967,
      -1,   968,    -1,    10,   124,    -1,    11,    -1,    10,   969,
     124,    -1,   970,    -1,   979,    -1,   971,    -1,   970,   971,
      -1,   972,   973,   975,    -1,   115,    -1,    -1,   973,   974,
      -1,  1199,    -1,  1200,    -1,   976,    -1,   977,    -1,    10,
     116,    -1,    11,    -1,    10,   978,   116,    -1,  1245,    -1,
     980,    -1,   979,   980,    -1,   981,   982,   985,    -1,   213,
      -1,   983,    -1,    -1,   983,   984,    -1,  1226,    -1,  1216,
      -1,  1190,    -1,   986,    -1,   987,    -1,    11,    -1,    10,
     988,   214,    -1,  1277,    -1,    -1,   990,   991,   992,    -1,
      91,    -1,    -1,  1232,    -1,   993,    -1,   994,    -1,    11,
      -1,    10,   995,    92,    -1,   996,  1009,  1064,    -1,    -1,
     997,   998,   999,    -1,    97,    -1,  1224,    -1,  1000,    -1,
    1001,    -1,    10,    98,    -1,    11,    -1,    10,  1002,    98,
      -1,  1003,    -1,  1004,    -1,  1003,  1004,    -1,  1005,  1006,
    1008,    -1,    89,    -1,    -1,  1006,  1007,    -1,  1199,    -1,
    1200,    -1,    10,  1244,    90,    -1,    -1,  1010,  1011,    -1,
      85,    -1,  1012,    -1,  1013,    -1,    11,    -1,    10,  1014,
      86,    -1,  1015,  1022,  1029,  1036,  1043,  1050,  1057,    -1,
      -1,  1016,  1017,  1018,    -1,    83,    -1,  1226,    -1,  1019,
      -1,  1020,    -1,    11,    -1,    10,  1021,    84,    -1,  1277,
      -1,    -1,  1023,  1024,  1025,    -1,    71,    -1,  1226,    -1,
    1026,    -1,  1027,    -1,    11,    -1,    10,  1028,    72,    -1,
    1277,    -1,    -1,  1030,  1031,  1032,    -1,    73,    -1,  1226,
      -1,  1033,    -1,  1034,    -1,    11,    -1,    10,  1035,    74,
      -1,  1277,    -1,    -1,  1037,  1038,  1039,    -1,    69,    -1,
    1226,    -1,  1040,    -1,  1041,    -1,    11,    -1,    10,  1042,
      70,    -1,  1277,    -1,    -1,  1044,  1045,  1046,    -1,   109,
      -1,  1226,    -1,  1047,    -1,  1048,    -1,    11,    -1,    10,
    1049,   110,    -1,  1277,    -1,    -1,  1051,  1052,  1053,    -1,
     153,    -1,  1226,    -1,  1054,    -1,  1055,    -1,    11,    -1,
      10,  1056,   154,    -1,  1277,    -1,    -1,  1058,  1059,  1060,
      -1,   167,    -1,  1226,    -1,  1061,    -1,  1062,    -1,    11,
      -1,    10,  1063,   168,    -1,  1277,    -1,    -1,  1064,  1065,
      -1,  1066,  1067,  1070,    -1,   123,    -1,  1068,    -1,    -1,
    1068,  1069,    -1,  1224,    -1,  1227,    -1,  1216,    -1,  1200,
      -1,  1208,    -1,  1186,    -1,  1194,    -1,  1190,    -1,  1071,
      -1,  1072,    -1,    10,   124,    -1,    11,    -1,    10,  1073,
     124,    -1,  1074,    -1,  1083,    -1,  1075,    -1,  1074,  1075,
      -1,  1076,  1077,  1079,    -1,    89,    -1,    -1,  1077,  1078,
      -1,  1199,    -1,  1200,    -1,  1080,    -1,  1081,    -1,    10,
      90,    -1,    11,    -1,    10,  1082,    90,    -1,  1245,    -1,
    1084,    -1,  1083,  1084,    -1,  1085,  1086,  1089,    -1,   213,
      -1,  1087,    -1,    -1,  1087,  1088,    -1,  1226,    -1,  1216,
      -1,  1190,    -1,  1090,    -1,  1091,    -1,    11,    -1,    10,
    1092,   214,    -1,  1277,    -1,    -1,  1094,  1095,    -1,   307,
      -1,  1096,    -1,  1097,    -1,    11,    -1,    10,  1098,  1134,
     308,    -1,    -1,  1099,  1100,  1101,    -1,   309,    -1,  1233,
      -1,  1102,    -1,  1103,    -1,    11,    -1,    10,  1105,  1113,
    1104,    -1,   310,    -1,    -1,  1106,  1107,  1108,    -1,   183,
      -1,  1229,    -1,  1109,    -1,  1110,    -1,    11,    -1,    10,
    1112,  1111,    -1,   184,    -1,    -1,  1112,  1299,    -1,    -1,
    1113,  1114,    -1,  1115,  1116,  1119,    -1,   186,    -1,  1117,
      -1,    -1,  1117,  1118,    -1,  1229,    -1,  1227,    -1,  1216,
      -1,  1200,    -1,  1208,    -1,  1198,    -1,  1194,    -1,  1190,
      -1,  1120,    -1,  1121,    -1,    10,   124,    -1,    11,    -1,
      10,  1122,   124,    -1,  1123,    -1,  1124,    -1,  1299,    -1,
    1123,  1299,    -1,  1125,    -1,  1124,  1125,    -1,  1126,  1127,
    1130,    -1,   213,    -1,  1128,    -1,    -1,  1128,  1129,    -1,
    1226,    -1,  1216,    -1,  1190,    -1,  1131,    -1,  1132,    -1,
      11,    -1,    10,  1133,   214,    -1,  1277,    -1,    -1,  1134,
    1135,    -1,   189,    -1,    -1,  1137,  1138,  1139,    -1,   129,
      -1,  1236,    -1,  1140,    -1,  1141,    -1,    10,   130,    -1,
      11,    -1,    10,  1142,   130,    -1,  1143,    -1,  1144,    -1,
    1143,  1144,    -1,  1145,  1146,  1149,    -1,   127,    -1,  1147,
      -1,    -1,  1147,  1148,    -1,  1200,    -1,  1216,    -1,  1182,
      -1,  1190,    -1,  1228,    -1,  1150,    -1,  1151,    -1,    10,
     128,    -1,    11,    -1,    10,  1152,   128,    -1,  1153,    -1,
    1154,    -1,  1153,  1154,    -1,  1155,    -1,  1156,    -1,  1157,
      -1,   219,    -1,   216,    -1,   217,  1158,   218,    -1,     5,
      -1,    -1,  1160,  1161,  1162,    -1,   131,    -1,  1239,    -1,
    1163,    -1,  1164,    -1,    10,   132,    -1,    11,    -1,    10,
    1165,   132,    -1,  1166,    -1,  1167,    -1,  1166,  1167,    -1,
    1168,  1169,  1172,    -1,   145,    -1,  1170,    -1,    -1,  1170,
    1171,    -1,  1200,    -1,  1182,    -1,  1190,    -1,  1228,    -1,
    1173,    -1,  1174,    -1,    10,   146,    -1,    11,    -1,    10,
    1175,   146,    -1,  1176,    -1,  1177,    -1,  1176,  1177,    -1,
    1178,    -1,  1179,    -1,  1180,    -1,   219,    -1,   216,    -1,
     217,  1181,   218,    -1,     5,    -1,  1183,    -1,  1184,    -1,
    1185,    -1,    36,    -1,    35,     3,  1246,    -1,  1187,    -1,
    1188,    -1,  1189,    -1,    40,    -1,    39,     3,  1246,    -1,
    1191,    -1,  1192,    -1,  1193,    -1,    38,    -1,    37,     3,
    1246,    -1,  1195,    -1,  1196,    -1,  1197,    -1,    42,    -1,
      41,     3,  1246,    -1,    55,     3,     8,    -1,   251,  1246,
       6,  1246,    -1,  1201,    -1,  1202,    -1,  1203,    -1,   235,
      -1,   236,     3,  1246,    -1,  1205,    -1,  1206,    -1,  1207,
      -1,    44,    -1,    43,     3,  1246,    -1,  1209,    -1,  1210,
      -1,  1211,    -1,   237,    -1,   238,     3,  1246,    -1,  1213,
      -1,  1214,    -1,  1215,    -1,    48,    -1,    47,     3,  1246,
      -1,  1217,    -1,  1218,    -1,  1219,    -1,    50,    -1,    49,
       3,  1246,    -1,  1221,    -1,  1222,    -1,  1223,    -1,    46,
      -1,    45,     3,  1246,    -1,    16,  1246,     6,  1246,    -1,
      17,  1246,     6,  1246,    -1,   215,  1246,     6,  1246,    -1,
      18,  1246,     6,  1246,    -1,    20,  1246,     6,  1246,    -1,
     311,  1246,     6,  1246,    -1,    21,  1246,     6,  1246,    -1,
      22,  1246,     6,  1246,    -1,    23,  1246,     6,  1246,    -1,
     185,  1246,     6,  1246,    -1,    24,  1246,     6,  1246,    -1,
      25,  1246,     6,  1246,    -1,    26,  1246,     6,  1246,    -1,
      27,  1246,     6,  1246,    -1,    28,  1246,     6,  1246,    -1,
      29,  1246,     6,  1246,    -1,    30,  1246,     6,  1246,    -1,
      31,  1246,     6,  1246,    -1,    32,  1246,     6,  1246,    -1,
      33,  1246,     6,  1246,    -1,     6,    -1,     7,    -1,     4,
      -1,     6,    -1,     7,    -1,  1247,     8,    -1,    -1,  1247,
    1248,    -1,   427,    -1,   428,    -1,   429,    -1,   430,    -1,
    1250,  1251,    -1,   191,    -1,  1252,    -1,  1253,    -1,    11,
      -1,    10,  1254,   192,    -1,  1255,    -1,    -1,  1255,  1256,
      -1,  1257,    -1,  1261,    -1,  1265,    -1,  1269,    -1,  1273,
      -1,  1258,    -1,  1259,    -1,  1260,    -1,   196,    -1,   195,
      -1,   193,     5,   194,    -1,  1262,    -1,  1263,    -1,  1264,
      -1,   200,    -1,   199,    -1,   197,     5,   198,    -1,  1266,
      -1,  1267,    -1,  1268,    -1,   204,    -1,   203,    -1,   201,
       5,   202,    -1,  1270,    -1,  1271,    -1,  1272,    -1,   208,
      -1,   207,    -1,   205,     5,   206,    -1,  1274,    -1,  1275,
      -1,  1276,    -1,   212,    -1,   211,    -1,   209,     5,   210,
      -1,  1278,    -1,  1285,    -1,    -1,  1278,  1279,    -1,  1280,
    1281,  1284,    -1,   225,    -1,  1282,    -1,    -1,  1282,  1283,
      -1,  1490,    -1,  1489,    -1,    10,     6,   226,    -1,   220,
    1488,  1286,    -1,  1287,    -1,  1288,    -1,    10,   221,    -1,
      11,    -1,    10,     4,   221,    -1,  1290,    -1,  1295,    -1,
      -1,  1290,  1291,    -1,  1292,  1293,  1294,    -1,   225,    -1,
      -1,  1490,    -1,    10,  1244,   226,    -1,   220,  1488,  1296,
      -1,  1297,    -1,  1298,    -1,    10,   221,    -1,    11,    -1,
      10,     4,   221,    -1,    -1,  1301,  1300,  1302,  1307,    -1,
     227,    -1,  1302,    -1,    -1,  1302,  1302,    -1,  1303,    -1,
    1485,    -1,  1483,    -1,  1304,    -1,  1305,    -1,  1306,    -1,
     242,     3,     8,    -1,   236,     3,     8,    -1,   238,     3,
       8,    -1,   253,  1246,     6,  1246,    -1,  1308,    -1,  1309,
      -1,    11,    -1,    10,  1310,   228,    -1,  1311,  1329,    -1,
      -1,  1312,  1313,  1328,    -1,   230,    -1,  1314,    -1,    -1,
    1314,  1315,    -1,  1316,    -1,  1317,    -1,  1318,    -1,  1319,
      -1,  1320,    -1,  1321,    -1,  1322,    -1,  1323,    -1,  1327,
      -1,   256,     8,     6,     8,    -1,   257,     8,     6,     8,
      -1,   258,     8,     6,     8,    -1,   259,     8,     6,     8,
      -1,   260,     8,     6,     8,    -1,   261,     8,     6,     8,
      -1,   262,     8,     6,     8,    -1,  1324,    -1,  1325,    -1,
    1326,    -1,   264,    -1,   265,     3,  1246,    -1,   263,     8,
    1244,     8,    -1,    10,   229,    -1,    11,    -1,    -1,  1329,
    1330,    -1,  1331,    -1,  1356,    -1,  1369,    -1,  1397,    -1,
    1415,    -1,  1428,    -1,  1447,    -1,  1451,    -1,  1332,  1333,
      10,  1336,    -1,   268,    -1,  1334,    -1,    -1,  1334,  1335,
      -1,  1486,    -1,  1492,    -1,  1338,  1337,   269,    -1,    -1,
    1344,  1350,    -1,  1339,  1340,    -1,   270,    -1,  1341,    -1,
    1342,    -1,    11,    -1,    10,  1343,   271,    -1,  1277,    -1,
    1345,  1346,    -1,   274,    -1,  1347,    -1,  1348,    -1,    11,
      -1,    10,  1349,   275,    -1,  1277,    -1,  1351,  1352,    -1,
     276,    -1,  1353,    -1,  1354,    -1,    11,    -1,    10,  1355,
     277,    -1,  1289,    -1,  1357,  1358,    10,  1361,    -1,   282,
      -1,  1359,    -1,    -1,  1359,  1360,    -1,  1486,    -1,  1492,
      -1,  1338,  1362,   283,    -1,    -1,  1344,  1363,    -1,  1364,
    1365,    -1,   276,    -1,  1366,    -1,  1367,    -1,    11,    -1,
      10,  1368,   277,    -1,  1277,    -1,  1370,  1371,    10,  1374,
      -1,   284,    -1,  1372,    -1,    -1,  1372,  1373,    -1,  1486,
      -1,  1492,    -1,  1338,  1375,   285,    -1,    -1,  1344,  1376,
      -1,    -1,  1377,  1378,    -1,   276,    -1,  1379,    -1,  1380,
      -1,    11,    -1,    10,  1381,   277,    -1,  1382,    -1,    -1,
    1382,  1383,    -1,  1384,  1385,  1389,    -1,   225,    -1,  1386,
      -1,    -1,  1386,  1387,    -1,  1487,    -1,  1388,    -1,   245,
       8,  1244,     8,    -1,  1390,    -1,  1391,    -1,    11,    -1,
      10,  1392,   226,    -1,    -1,  1392,  1393,    -1,  1394,  1395,
    1396,    -1,   295,    -1,    -1,   252,     8,  1244,     8,    -1,
      10,     6,   296,    -1,  1398,  1399,    10,  1402,    -1,   286,
      -1,  1400,    -1,    -1,  1400,  1401,    -1,  1486,    -1,  1492,
      -1,  1338,  1403,   287,    -1,    -1,  1344,  1404,    -1,    -1,
    1405,  1406,    -1,   276,    -1,  1407,    -1,  1408,    -1,    11,
      -1,    10,  1409,   277,    -1,    -1,  1409,  1410,    -1,  1411,
    1412,    -1,   225,    -1,  1413,    -1,  1414,    -1,    11,    -1,
      10,  1495,   226,    -1,  1416,  1417,    10,  1420,    -1,   291,
      -1,  1418,    -1,    -1,  1418,  1419,    -1,  1486,    -1,  1492,
      -1,  1338,  1421,   292,    -1,    -1,  1344,  1422,    -1,  1423,
    1424,    -1,   276,    -1,  1425,    -1,  1426,    -1,    11,    -1,
      10,  1427,   277,    -1,  1277,    -1,  1429,  1430,    10,  1433,
      -1,   288,    -1,  1431,    -1,    -1,  1431,  1432,    -1,  1486,
      -1,  1492,    -1,  1338,  1434,   289,    -1,    -1,  1344,  1435,
      -1,    -1,  1436,  1437,    -1,   276,    -1,  1438,    -1,  1439,
      -1,    11,    -1,    10,  1440,   277,    -1,    -1,  1440,  1441,
      -1,  1442,  1443,  1446,    -1,   225,    -1,    -1,  1443,  1444,
      -1,  1445,    -1,  1490,    -1,  1489,    -1,   290,     3,     8,
      -1,    10,     6,   226,    -1,  1448,  1449,    10,  1572,  1450,
      -1,   297,    -1,    -1,  1491,    -1,   298,    -1,  1452,  1453,
    1454,    -1,   233,    -1,  1482,    -1,    10,  1456,  1463,  1470,
    1455,    -1,   234,    -1,  1457,  1458,  1459,    -1,   299,    -1,
    1484,    -1,  1460,    -1,  1461,    -1,    11,    -1,    10,  1462,
     300,    -1,  1277,    -1,  1464,  1465,  1466,    -1,   301,    -1,
    1484,    -1,  1467,    -1,  1468,    -1,    11,    -1,    10,  1469,
     302,    -1,  1277,    -1,    -1,  1470,  1471,    -1,  1472,  1473,
    1478,    -1,   231,    -1,  1474,    -1,    -1,  1474,  1475,    -1,
    1476,    -1,  1477,    -1,  1303,    -1,  1305,    -1,   305,  1246,
       6,  1246,    -1,   306,  1246,     6,  1246,    -1,  1479,    -1,
    1480,    -1,    11,    -1,    10,  1481,   232,    -1,  1311,  1329,
      -1,   246,     8,     6,     8,    -1,   247,     8,     6,     8,
      -1,   215,     8,     6,     8,    -1,   248,     8,     6,     8,
      -1,   249,     8,     6,     8,    -1,   250,     8,     6,     8,
      -1,   224,     8,     6,     8,    -1,   222,     8,     6,     8,
      -1,   223,     8,     6,     8,    -1,   240,     3,     8,    -1,
    1493,    -1,  1494,    -1,   303,    -1,   304,     3,     8,    -1,
    1539,    -1,  1549,    -1,  1502,    -1,  1504,    -1,  1557,    -1,
    1506,    -1,  1508,    -1,  1510,    -1,  1512,    -1,  1569,    -1,
    1514,    -1,  1516,    -1,  1518,    -1,  1522,    -1,  1520,    -1,
    1524,    -1,  1531,    -1,  1526,    -1,  1529,    -1,  1563,    -1,
    1566,    -1,  1496,    -1,  1499,    -1,  1560,    -1,  1533,    -1,
    1535,    -1,  1537,    -1,    -1,   378,  1497,  1498,    -1,    11,
      -1,    10,   379,    -1,    -1,   380,  1500,  1501,    -1,    11,
      -1,    10,   381,    -1,    -1,   382,  1503,  1495,  1495,   383,
      -1,    -1,   340,  1505,  1495,  1495,   341,    -1,    -1,   342,
    1507,  1495,  1495,   343,    -1,    -1,   356,  1509,  1495,   357,
      -1,    -1,   344,  1511,  1495,  1495,   345,    -1,    -1,   338,
    1513,  1495,  1495,   339,    -1,    -1,   346,  1515,  1495,   347,
      -1,    -1,   348,  1517,  1495,   349,    -1,    -1,   360,  1519,
    1495,   361,    -1,    -1,   362,  1521,  1495,   363,    -1,    -1,
     364,  1523,  1495,   365,    -1,    -1,   354,  1525,  1495,   355,
      -1,  1527,  1495,  1528,    -1,   368,    -1,   369,    -1,    -1,
     370,  1530,  1495,   371,    -1,    -1,   358,  1532,  1495,  1495,
    1495,   359,    -1,    -1,   386,  1534,  1572,   387,    -1,    -1,
     388,  1536,  1572,   389,    -1,    -1,   390,  1538,  1572,   391,
      -1,    -1,   384,  1540,  1542,  1541,    -1,    11,    -1,    10,
     385,    -1,    -1,  1542,  1543,    -1,  1544,    -1,  1548,    -1,
    1546,    -1,    -1,   238,     3,  1545,     8,    -1,    -1,   426,
       3,  1547,     8,    -1,    49,     8,  1244,     8,    -1,    -1,
     366,  1550,  1553,  1551,    -1,    11,    -1,    10,   367,    -1,
      -1,    10,  1495,  1552,   367,    -1,    -1,  1553,  1554,    -1,
    1555,    -1,  1556,    -1,   252,     8,  1244,     8,    -1,   251,
       8,     6,     8,    -1,    -1,   350,  1558,  1559,   351,    -1,
      -1,  1559,  1495,    -1,    -1,   374,  1561,  1562,   375,    -1,
      -1,  1562,  1495,    -1,    -1,   372,  1564,  1565,   373,    -1,
      -1,  1565,  1495,    -1,    -1,   376,  1567,  1568,   377,    -1,
      -1,  1568,  1495,    -1,    -1,   352,  1570,  1571,   353,    -1,
      -1,  1571,  1495,    -1,  1573,    -1,  1577,    -1,  1581,    -1,
    1585,    -1,  1589,    -1,  1592,    -1,  1598,    -1,  1601,    -1,
    1605,    -1,  1610,    -1,  1613,    -1,  1616,    -1,  1619,    -1,
    1622,    -1,  1625,    -1,  1628,    -1,  1631,    -1,  1634,    -1,
    1595,    -1,  1574,  1576,  1575,    -1,   418,    -1,    11,    -1,
      10,   419,    -1,   251,     8,     6,     8,    -1,  1578,  1580,
    1579,    -1,   312,    -1,    11,    -1,    10,   313,    -1,   251,
       8,     6,     8,    -1,  1582,  1584,  1583,    -1,   317,    -1,
      11,    -1,    10,   318,    -1,   251,     8,     6,     8,    -1,
    1586,  1588,  1587,    -1,   322,    -1,    11,    -1,    10,   323,
      -1,   251,     8,     6,     8,    -1,  1590,  1591,    -1,   392,
      -1,  1572,   393,    -1,  1593,  1594,    -1,   394,    -1,  1572,
    1572,   395,    -1,  1596,  1597,    -1,   420,    -1,  1495,   421,
      -1,  1599,  1600,    -1,   422,    -1,  1572,   423,    -1,  1602,
    1603,    10,  1604,    -1,   396,    -1,    -1,  1609,    -1,  1572,
     397,    -1,  1606,  1607,    10,  1608,    -1,   398,    -1,    -1,
    1609,    -1,  1572,   399,    -1,   425,     3,     8,    -1,  1611,
    1612,    -1,   400,    -1,    11,    -1,    10,   401,    -1,  1614,
    1615,    -1,   402,    -1,  1572,  1572,   403,    -1,  1617,  1618,
      -1,   404,    -1,  1572,   405,    -1,  1620,  1621,    -1,   406,
      -1,  1572,  1572,   407,    -1,  1623,  1624,    -1,   408,    -1,
    1572,  1572,   409,    -1,    -1,   410,  1626,  1627,   411,    -1,
      -1,  1627,  1572,    -1,  1629,  1630,    -1,   412,    -1,  1495,
    1572,   413,    -1,  1632,  1633,    -1,   414,    -1,  1495,  1495,
    1495,  1495,  1572,   415,    -1,  1635,  1636,    -1,   416,    -1,
    1572,   417,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   356,   356,   357,   359,   366,   376,   376,   378,   378,
     380,   382,   384,   393,   394,   397,   406,   406,   419,   419,
     421,   435,   435,   437,   437,   439,   441,   443,   443,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   457,   459,
     474,   481,   481,   484,   489,   493,   502,   506,   511,   511,
     513,   515,   517,   517,   519,   524,   534,   540,   540,   543,
     548,   554,   554,   557,   559,   566,   566,   568,   568,   570,
     572,   575,   577,   584,   584,   586,   586,   588,   590,   595,
     597,   604,   604,   606,   606,   608,   610,   615,   617,   624,
     624,   626,   626,   628,   630,   635,   637,   644,   644,   646,
     646,   648,   650,   655,   657,   664,   664,   666,   666,   668,
     670,   675,   677,   684,   684,   686,   686,   688,   690,   695,
     697,   704,   714,   719,   725,   725,   727,   729,   731,   731,
     733,   738,   750,   756,   756,   759,   766,   771,   778,   778,
     782,   782,   784,   795,   795,   797,   797,   799,   801,   803,
     803,   806,   807,   808,   809,   810,   811,   814,   816,   823,
     823,   825,   825,   827,   829,   836,   838,   849,   851,   851,
     854,   860,   866,   868,   874,   876,   887,   889,   889,   892,
     898,   904,   906,   913,   915,   926,   928,   928,   931,   937,
     943,   945,   952,   954,   963,   964,   970,   972,   978,   980,
     987,   997,  1002,  1008,  1008,  1010,  1012,  1014,  1014,  1016,
    1021,  1033,  1039,  1039,  1042,  1049,  1054,  1060,  1060,  1064,
    1064,  1066,  1077,  1077,  1079,  1079,  1081,  1083,  1085,  1085,
    1088,  1089,  1090,  1091,  1092,  1093,  1096,  1098,  1105,  1105,
    1107,  1107,  1109,  1111,  1119,  1121,  1128,  1128,  1130,  1130,
    1132,  1134,  1139,  1141,  1148,  1148,  1150,  1150,  1152,  1154,
    1159,  1161,  1168,  1168,  1170,  1170,  1172,  1174,  1179,  1181,
    1188,  1188,  1190,  1190,  1192,  1194,  1201,  1203,  1210,  1220,
    1225,  1231,  1231,  1233,  1235,  1237,  1237,  1239,  1244,  1256,
    1262,  1262,  1265,  1272,  1277,  1284,  1284,  1287,  1287,  1289,
    1305,  1305,  1307,  1307,  1309,  1311,  1313,  1313,  1316,  1317,
    1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,  1329,
    1331,  1338,  1338,  1340,  1340,  1342,  1344,  1352,  1354,  1361,
    1361,  1363,  1363,  1365,  1367,  1372,  1374,  1381,  1381,  1383,
    1383,  1385,  1387,  1392,  1394,  1401,  1401,  1403,  1403,  1405,
    1407,  1412,  1414,  1421,  1421,  1423,  1423,  1425,  1427,  1432,
    1434,  1441,  1451,  1456,  1462,  1462,  1464,  1466,  1468,  1468,
    1470,  1472,  1486,  1486,  1489,  1489,  1489,  1489,  1492,  1492,
    1494,  1494,  1496,  1498,  1507,  1508,  1511,  1513,  1524,  1526,
    1526,  1529,  1535,  1541,  1543,  1550,  1552,  1563,  1565,  1565,
    1568,  1574,  1580,  1582,  1589,  1591,  1602,  1604,  1604,  1607,
    1613,  1619,  1621,  1628,  1630,  1640,  1641,  1647,  1649,  1656,
    1658,  1665,  1675,  1680,  1686,  1686,  1688,  1690,  1692,  1692,
    1694,  1699,  1711,  1717,  1717,  1720,  1727,  1732,  1739,  1739,
    1742,  1742,  1744,  1752,  1758,  1758,  1761,  1768,  1774,  1780,
    1788,  1793,  1799,  1799,  1801,  1803,  1805,  1805,  1807,  1809,
    1818,  1820,  1820,  1822,  1822,  1822,  1824,  1834,  1844,  1864,
    1870,  1872,  1882,  1888,  1888,  1891,  1896,  1901,  1911,  1916,
    1922,  1922,  1924,  1926,  1928,  1928,  1930,  1935,  1945,  1951,
    1951,  1954,  1960,  1967,  1967,  1970,  1970,  1972,  1974,  1974,
    1976,  1976,  1978,  1980,  1988,  1988,  1990,  1996,  1996,  2004,
    2004,  2006,  2008,  2010,  2012,  2012,  2014,  2016,  2024,  2029,
    2035,  2035,  2037,  2039,  2041,  2041,  2043,  2054,  2063,  2063,
    2066,  2067,  2070,  2073,  2073,  2075,  2077,  2085,  2090,  2096,
    2096,  2098,  2100,  2102,  2102,  2104,  2115,  2124,  2124,  2127,
    2128,  2132,  2133,  2135,  2135,  2137,  2139,  2144,  2144,  2146,
    2151,  2151,  2153,  2155,  2157,  2159,  2159,  2168,  2170,  2177,
    2177,  2179,  2181,  2183,  2186,  2186,  2196,  2198,  2206,  2206,
    2208,  2210,  2212,  2215,  2215,  2224,  2226,  2234,  2234,  2236,
    2238,  2240,  2243,  2243,  2252,  2254,  2262,  2262,  2264,  2266,
    2268,  2271,  2271,  2280,  2282,  2290,  2290,  2292,  2294,  2296,
    2299,  2299,  2308,  2310,  2318,  2318,  2320,  2322,  2324,  2327,
    2327,  2336,  2338,  2346,  2346,  2348,  2350,  2352,  2355,  2355,
    2357,  2362,  2381,  2387,  2387,  2390,  2401,  2412,  2418,  2424,
    2430,  2436,  2442,  2449,  2449,  2451,  2451,  2453,  2455,  2455,
    2457,  2457,  2459,  2466,  2475,  2475,  2478,  2484,  2491,  2491,
    2493,  2493,  2495,  2497,  2506,  2506,  2508,  2519,  2527,  2533,
    2533,  2536,  2542,  2543,  2547,  2547,  2549,  2551,  2554,  2558,
    2558,  2560,  2568,  2568,  2576,  2576,  2578,  2580,  2582,  2584,
    2584,  2586,  2588,  2596,  2601,  2607,  2607,  2609,  2611,  2614,
    2614,  2616,  2625,  2635,  2635,  2638,  2639,  2642,  2645,  2645,
    2647,  2652,  2652,  2655,  2657,  2659,  2661,  2661,  2670,  2672,
    2679,  2679,  2681,  2683,  2685,  2687,  2687,  2696,  2698,  2706,
    2706,  2708,  2710,  2712,  2715,  2715,  2724,  2726,  2734,  2734,
    2736,  2738,  2740,  2743,  2743,  2752,  2754,  2762,  2762,  2764,
    2766,  2768,  2771,  2771,  2780,  2782,  2790,  2790,  2792,  2794,
    2796,  2799,  2799,  2808,  2810,  2818,  2818,  2820,  2822,  2824,
    2827,  2827,  2836,  2838,  2846,  2846,  2848,  2850,  2852,  2855,
    2855,  2857,  2863,  2882,  2889,  2889,  2892,  2903,  2914,  2920,
    2926,  2932,  2938,  2944,  2953,  2953,  2955,  2955,  2957,  2959,
    2959,  2961,  2961,  2963,  2968,  2979,  2979,  2982,  2987,  2994,
    2994,  2996,  2996,  2998,  3000,  3007,  3007,  3009,  3020,  3028,
    3034,  3034,  3037,  3043,  3044,  3048,  3048,  3050,  3052,  3055,
    3058,  3058,  3060,  3067,  3067,  3075,  3075,  3077,  3079,  3081,
    3083,  3083,  3085,  3088,  3096,  3101,  3107,  3107,  3109,  3111,
    3113,  3113,  3115,  3124,  3133,  3133,  3136,  3137,  3140,  3143,
    3143,  3145,  3150,  3150,  3152,  3154,  3156,  3158,  3158,  3167,
    3169,  3176,  3176,  3178,  3180,  3182,  3184,  3184,  3193,  3195,
    3203,  3203,  3205,  3207,  3209,  3212,  3212,  3221,  3223,  3231,
    3231,  3233,  3235,  3237,  3240,  3240,  3249,  3251,  3259,  3259,
    3261,  3263,  3265,  3268,  3268,  3277,  3279,  3287,  3287,  3289,
    3291,  3293,  3296,  3296,  3305,  3307,  3315,  3315,  3317,  3319,
    3321,  3324,  3324,  3333,  3335,  3343,  3343,  3345,  3347,  3349,
    3352,  3352,  3354,  3360,  3379,  3385,  3385,  3388,  3399,  3410,
    3417,  3423,  3429,  3435,  3441,  3448,  3448,  3450,  3450,  3452,
    3454,  3454,  3456,  3456,  3458,  3465,  3474,  3474,  3478,  3483,
    3491,  3491,  3493,  3493,  3495,  3497,  3504,  3504,  3506,  3517,
    3525,  3531,  3531,  3534,  3540,  3541,  3545,  3545,  3547,  3549,
    3551,  3554,  3554,  3556,  3562,  3562,  3564,  3567,  3569,  3569,
    3576,  3582,  3590,  3590,  3592,  3594,  3596,  3598,  3598,  3601,
    3607,  3615,  3615,  3617,  3619,  3621,  3623,  3623,  3688,  3688,
    3690,  3696,  3717,  3724,  3724,  3727,  3738,  3749,  3755,  3761,
    3767,  3773,  3779,  3787,  3787,  3789,  3789,  3791,  3793,  3793,
    3795,  3795,  3838,  3839,  3841,  3853,  3861,  3867,  3867,  3870,
    3876,  3877,  3881,  3881,  3883,  3885,  3888,  4103,  4103,  4105,
    4254,  4254,  4256,  4261,  4270,  4275,  4281,  4281,  4283,  4285,
    4287,  4287,  4289,  4294,  4308,  4316,  4316,  4319,  4325,  4331,
    4337,  4345,  4355,  4360,  4366,  4366,  4368,  4370,  4372,  4372,
    4374,  4380,  4385,  4387,  4387,  4389,  4391,  4403,  4403,  4405,
    4410,  4419,  4424,  4430,  4430,  4432,  4434,  4436,  4436,  4438,
    4443,  4455,  4463,  4463,  4466,  4471,  4477,  4483,  4492,  4497,
    4503,  4503,  4505,  4507,  4509,  4509,  4511,  4517,  4522,  4524,
    4524,  4526,  4528,  4539,  4546,  4546,  4548,  4553,  4558,  4565,
    4565,  4567,  4572,  4577,  4584,  4584,  4586,  4591,  4596,  4603,
    4603,  4605,  4610,  4616,  4628,  4636,  4643,  4643,  4645,  4650,
    4655,  4662,  4662,  4664,  4669,  4674,  4681,  4681,  4683,  4688,
    4693,  4700,  4700,  4702,  4707,  4712,  4719,  4719,  4721,  4726,
    4731,  4738,  4738,  4740,  4745,  4751,  4757,  4766,  4772,  4786,
    4795,  4802,  4808,  4817,  4823,  4829,  4835,  4841,  4847,  4853,
    4862,  4868,  4877,  4882,  4888,  4905,  4906,  4910,  4911,  4912,
    4914,  4916,  4916,  4918,  4919,  4920,  4921,  4958,  4960,  4974,
    4974,  4976,  4978,  4980,  4982,  4982,  4985,  4986,  4987,  4988,
    4989,  4991,  4999,  4999,  5001,  5001,  5003,  5009,  5017,  5017,
    5019,  5019,  5021,  5027,  5035,  5035,  5037,  5037,  5039,  5045,
    5053,  5053,  5055,  5055,  5057,  5063,  5071,  5071,  5073,  5073,
    5075,  5087,  5095,  5097,  5097,  5099,  5101,  5110,  5112,  5112,
    5114,  5114,  5116,  5132,  5135,  5135,  5137,  5137,  5140,  5171,
    5179,  5181,  5181,  5183,  5185,  5193,  5193,  5195,  5211,  5213,
    5213,  5215,  5215,  5217,  5326,  5326,  5363,  5417,  5439,  5439,
    5442,  5443,  5444,  5445,  5446,  5447,  5512,  5521,  5530,  5539,
    5548,  5548,  5550,  5552,  5559,  5561,  5561,  5566,  5584,  5611,
    5611,  5614,  5615,  5616,  5617,  5618,  5619,  5620,  5621,  5622,
    5624,  5638,  5650,  5662,  5677,  5692,  5704,  5716,  5723,  5723,
    5725,  5730,  5738,  5748,  5748,  5750,  5750,  5755,  5755,  5755,
    5755,  5756,  5756,  5756,  5756,  5758,  5760,  5769,  5775,  5775,
    5778,  5784,  5790,  5792,  5792,  5798,  5808,  5818,  5818,  5820,
    5822,  5824,  5827,  5838,  5845,  5845,  5847,  5849,  5851,  5857,
    5867,  5874,  5874,  5876,  5878,  5880,  5883,  5885,  5894,  5900,
    5900,  5903,  5909,  5915,  5917,  5917,  5974,  5984,  5991,  5991,
    5993,  5995,  5997,  5999,  6001,  6010,  6016,  6016,  6019,  6025,
    6031,  6033,  6033,  6093,  6098,  6109,  6124,  6124,  6126,  6128,
    6130,  6132,  6132,  6134,  6141,  6147,  6158,  6158,  6161,  6162,
    6164,  6178,  6178,  6180,  6182,  6184,  6184,  6187,  6189,  6197,
    6197,  6204,  6211,  6213,  6222,  6228,  6228,  6231,  6237,  6243,
    6245,  6245,  6304,  6305,  6307,  6322,  6322,  6324,  6326,  6328,
    6328,  6330,  6332,  6347,  6347,  6349,  6351,  6361,  6363,  6372,
    6378,  6378,  6381,  6387,  6393,  6395,  6395,  6454,  6464,  6471,
    6471,  6473,  6475,  6477,  6480,  6482,  6491,  6497,  6497,  6500,
    6506,  6512,  6514,  6514,  6573,  6578,  6589,  6604,  6604,  6606,
    6608,  6610,  6610,  6612,  6620,  6632,  6632,  6635,  6636,  6637,
    6639,  6654,  6677,  6680,  6698,  6698,  6704,  6711,  6721,  6729,
    6735,  6737,  6751,  6763,  6769,  6775,  6775,  6777,  6779,  6781,
    6783,  6793,  6799,  6805,  6805,  6807,  6809,  6811,  6813,  6813,
    6818,  6823,  6835,  6837,  6837,  6840,  6841,  6842,  6850,  6857,
    6875,  6893,  6893,  6895,  6897,  6903,  6905,  6916,  6927,  6938,
    6949,  6960,  6971,  6978,  6988,  7027,  7036,  7036,  7038,  7047,
    7177,  7178,  7179,  7180,  7181,  7182,  7183,  7184,  7185,  7186,
    7187,  7188,  7189,  7190,  7191,  7192,  7193,  7194,  7195,  7196,
    7197,  7198,  7199,  7200,  7202,  7203,  7204,  7208,  7208,  7211,
    7212,  7214,  7214,  7217,  7218,  7222,  7222,  7227,  7227,  7232,
    7232,  7237,  7237,  7242,  7242,  7247,  7247,  7252,  7252,  7257,
    7257,  7262,  7262,  7267,  7267,  7272,  7272,  7277,  7277,  7282,
    7284,  7290,  7297,  7297,  7303,  7303,  7315,  7315,  7320,  7320,
    7325,  7325,  7335,  7335,  7340,  7341,  7343,  7344,  7346,  7347,
    7348,  7352,  7351,  7361,  7360,  7369,  7379,  7378,  7385,  7386,
    7388,  7387,  7394,  7395,  7398,  7404,  7412,  7419,  7437,  7437,
    7448,  7448,  7451,  7451,  7465,  7466,  7469,  7469,  7482,  7483,
    7486,  7486,  7499,  7500,  7503,  7503,  7513,  7514,  7520,  7521,
    7522,  7523,  7524,  7525,  7526,  7527,  7528,  7529,  7530,  7531,
    7532,  7533,  7534,  7535,  7536,  7537,  7538,  7541,  7546,  7553,
    7554,  7556,  7564,  7569,  7576,  7577,  7579,  7586,  7591,  7598,
    7599,  7601,  7608,  7613,  7620,  7621,  7623,  7630,  7632,  7638,
    7640,  7642,  7648,  7650,  7652,  7658,  7660,  7662,  7668,  7670,
    7672,  7678,  7678,  7683,  7685,  7687,  7693,  7693,  7698,  7700,
    7709,  7711,  7716,  7716,  7718,  7720,  7726,  7729,  7731,  7737,
    7740,  7742,  7748,  7751,  7753,  7759,  7763,  7762,  7774,  7774,
    7781,  7783,  7789,  7791,  7793,  7799,  7802,  7804,  7810
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
  "OSRLEND", "NUMBEROFCONATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFENUMERATIONSATT", "NUMBEROFIDXATT", "NUMBEROFITEMSATT",
  "NUMBEROFOBJATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFOTHERCONSTRAINTRESULTSATT", "NUMBEROFOTHEROBJECTIVERESULTSATT",
  "NUMBEROFOTHERRESULTSATT", "NUMBEROFOTHERSOLUTIONRESULTSATT",
  "NUMBEROFOTHERVARIABLERESULTSATT", "NUMBEROFSOLUTIONSATT",
  "NUMBEROFSOLVEROUTPUTSATT", "NUMBEROFSUBSTATUSESATT", "NUMBEROFTIMESATT",
  "NUMBEROFVARATT", "NUMBEROFVARIABLESATT", "TARGETOBJECTIVEIDXATT",
  "CATEGORYATT", "EMPTYCATEGORYATT", "DESCRIPTIONATT",
  "EMPTYDESCRIPTIONATT", "CONTYPEATT", "EMPTYCONTYPEATT", "ENUMTYPEATT",
  "EMPTYENUMTYPEATT", "OBJTYPEATT", "EMPTYOBJTYPEATT", "VARTYPEATT",
  "EMPTYVARTYPEATT", "UNITATT", "EMPTYUNITATT", "VALUEATT",
  "EMPTYVALUEATT", "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT",
  "TARGETOBJECTIVENAMEATT", "EMPTYTARGETOBJECTIVENAMEATT",
  "MATRIXVARTYPEATT", "EMPTYMATRIXVARTYPEATT", "GENERALSTART",
  "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND",
  "JOBSTART", "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
  "ACTUALSTARTTIMESTART", "ACTUALSTARTTIMEEND", "ATEQUALITYSTART",
  "ATEQUALITYEND", "ATLOWERSTART", "ATLOWEREND", "ATUPPERSTART",
  "ATUPPEREND", "AVAILABLECPUNUMBERSTART", "AVAILABLECPUNUMBEREND",
  "AVAILABLECPUSPEEDSTART", "AVAILABLECPUSPEEDEND",
  "AVAILABLEDISKSPACESTART", "AVAILABLEDISKSPACEEND",
  "AVAILABLEMEMORYSTART", "AVAILABLEMEMORYEND", "BASICSTART", "BASICEND",
  "BASISSTATUSSTART", "BASISSTATUSEND", "BASSTATUSSTART", "BASSTATUSEND",
  "CONSTART", "CONEND", "CONSTRAINTSSTART", "CONSTRAINTSEND",
  "CURRENTJOBCOUNTSTART", "CURRENTJOBCOUNTEND", "CURRENTSTATESTART",
  "CURRENTSTATEEND", "DUALVALUESSTART", "DUALVALUESEND", "ENDTIMESTART",
  "ENDTIMEEND", "GENERALSTATUSSTART", "GENERALSTATUSEND",
  "GENERALSUBSTATUSSTART", "GENERALSUBSTATUSEND", "IDXSTART", "IDXEND",
  "INSTANCENAMESTART", "INSTANCENAMEEND", "ISFREESTART", "ISFREEEND",
  "JOBIDSTART", "JOBIDEND", "MESSAGESTART", "MESSAGEEND", "OBJSTART",
  "OBJEND", "OBJECTIVESSTART", "OBJECTIVESEND",
  "OPTIMIZATIONSOLUTIONSTATUSSTART", "OPTIMIZATIONSOLUTIONSTATUSEND",
  "OPTIMIZATIONSOLUTIONSUBSTATUSSTART", "OPTIMIZATIONSOLUTIONSUBSTATUSEND",
  "OTHERSTART", "OTHEREND", "OTHERRESULTSSTART", "OTHERRESULTSEND",
  "OTHERSOLUTIONRESULTSTART", "OTHERSOLUTIONRESULTEND",
  "OTHERSOLUTIONRESULTSSTART", "OTHERSOLUTIONRESULTSEND",
  "OTHERSOLVEROUTPUTSTART", "OTHERSOLVEROUTPUTEND",
  "SCHEDULEDSTARTTIMESTART", "SCHEDULEDSTARTTIMEEND", "SERVICENAMESTART",
  "SERVICENAMEEND", "SERVICEURISTART", "SERVICEURIEND",
  "SERVICEUTILIZATIONSTART", "SERVICEUTILIZATIONEND", "SOLUTIONSTART",
  "SOLUTIONEND", "SOLVERINVOKEDSTART", "SOLVERINVOKEDEND",
  "SOLVEROUTPUTSTART", "SOLVEROUTPUTEND", "STATUSSTART", "STATUSEND",
  "SUBMITTIMESTART", "SUBMITTIMEEND", "SUBSTATUSSTART", "SUBSTATUSEND",
  "SUPERBASICSTART", "SUPERBASICEND", "SYSTEMINFORMATIONSTART",
  "SYSTEMINFORMATIONEND", "TIMESTART", "TIMEEND",
  "TIMESERVICESTARTEDSTART", "TIMESERVICESTARTEDEND", "TIMESTAMPSTART",
  "TIMESTAMPEND", "TIMINGINFORMATIONSTART", "TIMINGINFORMATIONEND",
  "TOTALJOBSSOFARSTART", "TOTALJOBSSOFAREND", "UNKNOWNSTART", "UNKNOWNEND",
  "USEDCPUNUMBERSTART", "USEDCPUNUMBEREND", "USEDCPUSPEEDSTART",
  "USEDCPUSPEEDEND", "USEDDISKSPACESTART", "USEDDISKSPACEEND",
  "USEDMEMORYSTART", "USEDMEMORYEND", "VALUESSTRINGSTART",
  "VALUESSTRINGEND", "VARSTART", "VAREND", "VARIABLESSTART",
  "VARIABLESEND", "MATRIXVARIABLEVALUESSTART", "MATRIXVARIABLEVALUESEND",
  "NUMBEROFOTHERMATRIXVARIABLERESULTSATT",
  "OTHERMATRIXVARIABLERESULTSTART", "OTHERMATRIXVARIABLERESULTEND",
  "NUMBEROFOTHERMATRIXPROGRAMMINGRESULTSATT",
  "OTHERMATRIXPROGRAMMINGRESULTSTART", "OTHERMATRIXPROGRAMMINGRESULTEND",
  "HEADERSTART", "HEADEREND", "FILENAMESTART", "FILENAMEEND",
  "FILENAMEEMPTY", "FILENAMESTARTANDEND", "FILESOURCESTART",
  "FILESOURCEEND", "FILESOURCEEMPTY", "FILESOURCESTARTANDEND",
  "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
  "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART", "FILECREATOREND",
  "FILECREATOREMPTY", "FILECREATORSTARTANDEND", "FILELICENCESTART",
  "FILELICENCEEND", "FILELICENCEEMPTY", "FILELICENCESTARTANDEND",
  "ENUMERATIONSTART", "ENUMERATIONEND", "NUMBEROFELATT", "ITEMEMPTY",
  "ITEMSTART", "ITEMEND", "ITEMSTARTANDEND", "BASE64START", "BASE64END",
  "INCRATT", "MULTATT", "SIZEOFATT", "ELSTART", "ELEND", "MATRIXSTART",
  "MATRIXEND", "BASEMATRIXEND", "BASEMATRIXSTART", "BLOCKSTART",
  "BLOCKEND", "BLOCKSSTART", "BLOCKSEND", "EMPTYNAMEATT", "NAMEATT",
  "EMPTYTYPEATT", "TYPEATT", "EMPTYSHAPEATT", "SHAPEATT",
  "EMPTYSYMMETRYATT", "SYMMETRYATT", "EMPTYNEGATIVEPATTERNATT",
  "NEGATIVEPATTERNATT", "CONSTANTATT", "NUMBEROFBLOCKSATT",
  "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT", "NUMBEROFVALUESATT",
  "NUMBEROFVARIDXATT", "IDXATT", "COEFATT", "MATRIXVARIDXATT",
  "MATRIXOBJIDXATT", "MATRIXCONIDXATT", "BASEMATRIXIDXATT",
  "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
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
  "PATTERNELEMENTSSTART", "PATTERNELEMENTSEND", "VARIDXSTART", "VARIDXEND",
  "TRANSFORMATIONSTART", "TRANSFORMATIONEND", "COLOFFSETSTART",
  "COLOFFSETEND", "ROWOFFSETSTART", "ROWOFFSETEND", "EMPTYROWMAJORATT",
  "ROWMAJORATT", "BLOCKROWIDXATT", "BLOCKCOLIDXATT",
  "MATRIXPROGRAMMINGSTART", "MATRIXPROGRAMMINGEND", "MATRIXVARIABLESSTART",
  "MATRIXVARIABLESEND", "NUMBEROFMATRIXVARATT", "MATRIXVARSTART",
  "MATRIXVAREND", "MATRIXOBJECTIVESSTART", "MATRIXOBJECTIVESEND",
  "NUMBEROFMATRIXOBJATT", "MATRIXOBJSTART", "MATRIXOBJEND",
  "MATRIXCONSTRAINTSSTART", "MATRIXCONSTRAINTSEND", "NUMBEROFMATRIXCONATT",
  "MATRIXCONSTART", "MATRIXCONEND", "DUMMY", "NONLINEAREXPRESSIONSSTART",
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
  "otherConEnumerationBody", "matrixProgramming", "matrixProgrammingStart",
  "matrixProgrammingContent", "matrixProgrammingEmpty",
  "matrixProgrammingLaden", "matrixVariables", "matrixVariablesStart",
  "matrixVariablesAttributes", "matrixVariablesContent",
  "matrixVariablesEmpty", "matrixVariablesLaden", "matrixVariablesEnd",
  "matrixVariableValues", "matrixVariableValuesStart",
  "matrixVariableValuesAttributes", "matrixVariableValuesContent",
  "matrixVariableValuesEmpty", "matrixVariableValuesLaden",
  "matrixVariableValuesEnd", "matrixVarList", "otherMatrixVariableResults",
  "otherMatrixVariableResult", "otherMatrixVariableResultStart",
  "otherMatrixVariableResultAttributes",
  "otherMatrixVariableResultAttList", "otherMatrixVariableResultATT",
  "otherMatrixVariableResultContent", "otherMatrixVariableResultEmpty",
  "otherMatrixVariableResultLaden", "otherMatrixVariableResultBody",
  "otherMatrixVarList", "otherMatrixVarEnumerationList",
  "otherMatrixVarEnumeration", "otherMatrixVarEnumerationStart",
  "otherMatrixVarEnumerationAttributes",
  "otherMatrixVarEnumerationAttList", "otherMatrixVarEnumerationATT",
  "otherMatrixVarEnumerationContent", "otherMatrixVarEnumerationEmpty",
  "otherMatrixVarEnumerationLaden", "otherMatrixVarEnumerationBody",
  "otherMatrixProgrammingResults", "otherMatrixProgrammingResult",
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
  "categoryAttContent", "conTypeAttribute", "conTypeAtt",
  "conTypeAttEmpty", "conTypeAttContent", "descriptionAttribute",
  "descriptionAtt", "descriptionAttEmpty", "descriptionAttContent",
  "enumTypeAttribute", "enumTypeAtt", "enumTypeAttEmpty",
  "enumTypeAttContent", "matrixVarTypeAttribute", "idxAttribute",
  "nameAttribute", "nameAtt", "nameAttEmpty", "nameAttContent",
  "objTypeAttribute", "objTypeAtt", "objTypeAttEmpty", "objTypeAttContent",
  "typeAttribute", "typeAtt", "typeAttEmpty", "typeAttContent",
  "unitAttribute", "unitAtt", "unitAttEmpty", "unitAttContent",
  "valueAttribute", "valueAtt", "valueAttEmpty", "valueAttContent",
  "varTypeAttribute", "varTypeAtt", "varTypeAttEmpty", "varTypeAttContent",
  "numberOfConAttribute", "numberOfConstraintsAttribute",
  "numberOfElAttribute", "numberOfEnumerationsAttribute",
  "numberOfItemsAttribute", "numberOfMatrixVarAttribute",
  "numberOfObjAttribute", "numberOfObjectivesAttribute",
  "numberOfOtherConstraintResultsAttribute",
  "numberOfOtherMatrixVariableResultsATT",
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
  "osglDblArrayData", "osglDblVectorElArray", "osglDblVectorEl",
  "osglDblVectorElStart", "osglDblVectorElAttributes",
  "osglDblVectorElContent", "osglDblVectorBase64",
  "osglDblVectorBase64Content", "osglDblVectorBase64Empty",
  "osglDblVectorBase64Laden", "osglMatrixWithMatrixVarIdx", "$@1",
  "matrixStart", "matrixAttributesWithMatrixVarIdx", "osglSymmetryATT",
  "osglMatrixNameATT", "osglMatrixTypeATT", "osglMatrixVarIdxATT",
  "matrixContent", "matrixEmpty", "matrixLaden", "matrixBody",
  "baseMatrix", "baseMatrixStart", "baseMatrixAttributes",
  "baseMatrixAttList", "baseMatrixAtt", "osglBaseMatrixIdxATT",
  "osglTargetMatrixFirstRowATT", "osglTargetMatrixFirstColATT",
  "osglBaseMatrixStartRowATT", "osglBaseMatrixStartColATT",
  "osglBaseMatrixEndRowATT", "osglBaseMatrixEndColATT",
  "baseTransposeAttribute", "osglBaseTransposeATT",
  "baseTransposeAttEmpty", "baseTransposeAttContent",
  "osglScalarMultiplierATT", "baseMatrixEnd", "matrixConstructorList",
  "matrixConstructor", "constantElements", "constantElementsStart",
  "constantElementsAttributes", "constantElementsAttList",
  "constantElementsAtt", "constantElementsContent",
  "constantElementsNonzeros", "matrixElementsStartVector",
  "matrixElementsStartVectorStart", "matrixElementsStartVectorContent",
  "matrixElementsStartVectorEmpty", "matrixElementsStartVectorLaden",
  "matrixElementsStartVectorBody", "matrixElementsIndexVector",
  "matrixElementsIndexStart", "matrixElementsIndexContent",
  "matrixElementsIndexEmpty", "matrixElementsIndexLaden",
  "matrixElementsIndexBody", "constantElementsValues",
  "constantElementsValueStart", "constantElementsValueContent",
  "constantElementsValueEmpty", "constantElementsValueLaden",
  "constantElementsValueBody", "varReferenceElements",
  "varReferenceElementsStart", "varReferenceElementsAttributes",
  "varReferenceElementsAttList", "varReferenceElementsAtt",
  "varReferenceElementsContent", "varReferenceElementsNonzeros",
  "varReferenceElementsValues", "varReferenceElementsValuesStart",
  "varReferenceElementsValuesContent", "varReferenceElementsValuesEmpty",
  "varReferenceElementsValuesLaden", "varReferenceElementsValuesBody",
  "linearElements", "linearElementsStart", "linearElementsAttributes",
  "linearElementsAttList", "linearElementsAtt", "linearElementsContent",
  "linearElementsNonzeros", "linearElementsValues",
  "linearElementsValuesStart", "linearElementsValuesContent",
  "linearElementsValuesEmpty", "linearElementsValuesLaden",
  "linearElementsValuesBody", "linearElementsValuesElList",
  "linearElementsValuesEl", "linearElementsValuesElStart",
  "linearElementsValuesElAttributes", "linearElementsValuesElAttList",
  "linearElementsValuesElAtt", "osglConstantATT",
  "linearElementsValuesElContent", "linearElementsValuesElEmpty",
  "linearElementsValuesElLaden", "linearElementsValuesVarIdxList",
  "linearElementsValuesVarIdx", "linearElementsValuesVarIdxStart",
  "osglLinearElementsValuesVarIdxCoefATT",
  "linearElementsValuesVarIdxContent", "generalElements",
  "generalElementsStart", "generalElementsAttributes",
  "generalElementsAttList", "generalElementsAtt", "generalElementsContent",
  "generalElementsNonzeros", "generalElementsValues",
  "generalElementsValuesStart", "generalElementsValuesContent",
  "generalElementsValuesEmpty", "generalElementsValuesLaden",
  "generalElementsElList", "generalElementsEl", "generalElementsElStart",
  "generalElementsElContent", "generalElementsElEmpty",
  "generalElementsElLaden", "objReferenceElements",
  "objReferenceElementsStart", "objReferenceElementsAttributes",
  "objReferenceElementsAttList", "objReferenceElementsAtt",
  "objReferenceElementsContent", "objReferenceElementsNonzeros",
  "objReferenceElementsValues", "objReferenceElementsValuesStart",
  "objReferenceElementsValuesContent", "objReferenceElementsValuesEmpty",
  "objReferenceElementsValuesLaden", "objReferenceElementsValuesBody",
  "conReferenceElements", "conReferenceElementsStart",
  "conReferenceElementsAttributes", "conReferenceElementsAttList",
  "conReferenceElementsAtt", "conReferenceElementsContent",
  "conReferenceElementsNonzeros", "conReferenceElementsValues",
  "conReferenceElementsValuesStart", "conReferenceElementsValuesContent",
  "conReferenceElementsValuesEmpty", "conReferenceElementsValuesLaden",
  "conReferenceElementsElList", "conReferenceElementsEl",
  "conReferenceElementsElStart", "conReferenceElementsElAttributeList",
  "conReferenceElementsElAttribute", "conReferenceElementsElValueTypeATT",
  "conReferenceElementsElContent", "matrixTransformation",
  "matrixTransformationStart", "matrixTransformationShapeATT",
  "matrixTransformationEnd", "matrixBlocks", "matrixBlocksStart",
  "matrixBlocksAttributes", "matrixBlocksContent", "matrixBlocksEnd",
  "colOffsets", "colOffsetStart", "colOffsetNumberOfElAttribute",
  "colOffsetContent", "colOffsetEmpty", "colOffsetLaden", "colOffsetBody",
  "rowOffsets", "rowOffsetStart", "rowOffsetNumberOfElAttribute",
  "rowOffsetContent", "rowOffsetEmpty", "rowOffsetLaden", "rowOffsetBody",
  "blockList", "matrixBlock", "matrixBlockStart", "matrixBlockAttributes",
  "matrixBlockAttList", "matrixBlockAtt", "osglBlockRowIdxATT",
  "osglBlockColIdxATT", "matrixBlockContent", "blockEmpty", "blockLaden",
  "blockBody", "osglNumberOfBlocksATT", "osglNumberOfColumnsATT",
  "osglNumberOfElATT", "osglNumberOfRowsATT", "osglNumberOfValuesATT",
  "osglNumberOfVarIdxATT", "osglBase64SizeATT", "osglIncrATT",
  "osglMultATT", "osglShapeATT", "osglRowMajorATT", "rowMajorAttEmpty",
  "rowMajorAttContent", "nlnode", "E", "$@4", "eend", "PI", "$@5", "piend",
  "times", "$@6", "plus", "$@7", "minus", "$@8", "negate", "$@9", "divide",
  "$@10", "power", "$@11", "ln", "$@12", "sqrt", "$@13", "square", "$@14",
  "cos", "$@15", "sin", "$@16", "exp", "$@17", "abs", "absStart", "absEnd",
  "erf", "$@18", "if", "$@19", "matrixDeterminant", "$@20", "matrixTrace",
  "$@21", "matrixToScalar", "$@22", "number", "$@23", "numberend",
  "anotherNumberATT", "numberATT", "numbertypeATT", "$@24", "numberidATT",
  "$@25", "numbervalueATT", "variable", "$@26", "variableend", "$@27",
  "anotherVariableATT", "variableATT", "variablecoefATT", "variableidxATT",
  "sum", "$@28", "anothersumnlnode", "allDiff", "$@29",
  "anotherallDiffnlnode", "max", "$@30", "anothermaxnlnode", "min", "$@31",
  "anotherminnlnode", "product", "$@32", "anotherproductnlnode",
  "OSnLMNode", "matrixReference", "matrixReferenceStart",
  "matrixReferenceEnd", "matrixIdxATT", "matrixVarReference",
  "matrixVarReferenceStart", "matrixVarReferenceEnd", "matrixVarIdxATT",
  "matrixObjReference", "matrixObjReferenceStart", "matrixObjReferenceEnd",
  "matrixObjIdxATT", "matrixConReference", "matrixConReferenceStart",
  "matrixConReferenceEnd", "matrixConIdxATT", "matrixDiagonal",
  "matrixDiagonalStart", "matrixDiagonalContent", "matrixDotTimes",
  "matrixDotTimesStart", "matrixDotTimesContent", "identityMatrix",
  "identityMatrixStart", "identityMatrixContent", "matrixInverse",
  "matrixInverseStart", "matrixInverseContent", "matrixLowerTriangle",
  "matrixLowerTriangleStart", "matrixLowerTriangleAttribute",
  "matrixLowerTriangleContent", "matrixUpperTriangle",
  "matrixUpperTriangleStart", "matrixUpperTriangleAttribute",
  "matrixUpperTriangleContent", "includeDiagonalATT", "matrixMerge",
  "matrixMergeStart", "matrixMergeEnd", "matrixMinus", "matrixMinusStart",
  "matrixMinusContent", "matrixNegate", "matrixNegateStart",
  "matrixNegateContent", "matrixPlus", "matrixPlusStart",
  "matrixPlusContent", "matrixTimes", "matrixTimesStart",
  "matrixTimesContent", "matrixProduct", "$@33",
  "anothermatrixproductnode", "matrixScalarTimes",
  "matrixScalarTimesStart", "matrixScalarTimesContent",
  "matrixSubMatrixAt", "matrixSubMatrixAtStart",
  "matrixSubMatrixAtContent", "matrixTranspose", "matrixTransposeStart",
  "matrixTransposeContent", 0
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
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,    32,     9,    13,
      10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   431,   432,   432,   433,   434,   435,   435,   436,   436,
     437,   438,   439,   440,   440,   441,   442,   442,   443,   443,
     444,   445,   445,   446,   446,   447,   448,   449,   449,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   451,   452,
     453,   454,   454,   455,   455,   455,   456,   456,   457,   457,
     458,   459,   460,   460,   461,   462,   463,   464,   464,   465,
     465,   466,   466,   467,   468,   469,   469,   470,   470,   471,
     472,   473,   474,   475,   475,   476,   476,   477,   478,   479,
     480,   481,   481,   482,   482,   483,   484,   485,   486,   487,
     487,   488,   488,   489,   490,   491,   492,   493,   493,   494,
     494,   495,   496,   497,   498,   499,   499,   500,   500,   501,
     502,   503,   504,   505,   505,   506,   506,   507,   508,   509,
     510,   511,   512,   512,   513,   513,   514,   515,   516,   516,
     517,   518,   519,   520,   520,   521,   521,   521,   522,   522,
     523,   523,   524,   525,   525,   526,   526,   527,   528,   529,
     529,   530,   530,   530,   530,   530,   530,   531,   532,   533,
     533,   534,   534,   535,   536,   537,   538,   539,   540,   540,
     541,   541,   542,   543,   544,   545,   546,   547,   547,   548,
     548,   549,   550,   551,   552,   553,   554,   554,   555,   555,
     556,   557,   558,   559,   560,   560,   561,   562,   563,   564,
     565,   566,   566,   567,   567,   568,   569,   570,   570,   571,
     572,   573,   574,   574,   575,   575,   575,   576,   576,   577,
     577,   578,   579,   579,   580,   580,   581,   582,   583,   583,
     584,   584,   584,   584,   584,   584,   585,   586,   587,   587,
     588,   588,   589,   590,   591,   592,   593,   593,   594,   594,
     595,   596,   597,   598,   599,   599,   600,   600,   601,   602,
     603,   604,   605,   605,   606,   606,   607,   608,   609,   610,
     611,   611,   612,   612,   613,   614,   615,   616,   617,   618,
     618,   619,   619,   620,   621,   622,   622,   623,   624,   625,
     626,   626,   627,   627,   627,   628,   628,   629,   629,   630,
     631,   631,   632,   632,   633,   634,   635,   635,   636,   636,
     636,   636,   636,   636,   636,   636,   636,   636,   636,   637,
     638,   639,   639,   640,   640,   641,   642,   643,   644,   645,
     645,   646,   646,   647,   648,   649,   650,   651,   651,   652,
     652,   653,   654,   655,   656,   657,   657,   658,   658,   659,
     660,   661,   662,   663,   663,   664,   664,   665,   666,   667,
     668,   669,   670,   670,   671,   671,   672,   673,   674,   674,
     675,   676,   677,   677,   678,   678,   678,   678,   679,   679,
     680,   680,   681,   682,   683,   683,   684,   685,   686,   687,
     687,   688,   688,   689,   690,   691,   692,   693,   694,   694,
     695,   695,   696,   697,   698,   699,   700,   701,   701,   702,
     702,   703,   704,   705,   706,   707,   707,   708,   709,   710,
     711,   712,   713,   713,   714,   714,   715,   716,   717,   717,
     718,   719,   720,   721,   721,   722,   722,   722,   723,   723,
     724,   724,   725,   726,   727,   727,   728,   728,   728,   728,
     729,   729,   730,   730,   731,   732,   733,   733,   734,   735,
     736,   737,   737,   738,   738,   738,   739,   740,   741,   742,
     743,   744,   745,   746,   746,   747,   747,   747,   748,   748,
     749,   749,   750,   751,   752,   752,   753,   754,   755,   756,
     756,   757,   757,   758,   758,   759,   759,   760,   761,   761,
     762,   762,   763,   764,   765,   765,   766,   767,   767,   768,
     768,   769,   770,   771,   772,   772,   773,   774,   775,   775,
     776,   776,   777,   778,   779,   779,   780,   781,   782,   782,
     783,   783,   784,   785,   785,   786,   787,   788,   788,   789,
     789,   790,   791,   792,   792,   793,   794,   795,   795,   796,
     796,   797,   797,   798,   798,   799,   800,   801,   801,   802,
     803,   803,   804,   805,   806,   807,   807,   808,   809,   810,
     810,   811,   812,   813,   814,   814,   815,   816,   817,   817,
     818,   819,   820,   821,   821,   822,   823,   824,   824,   825,
     826,   827,   828,   828,   829,   830,   831,   831,   832,   833,
     834,   835,   835,   836,   837,   838,   838,   839,   840,   841,
     842,   842,   843,   844,   845,   845,   846,   847,   848,   849,
     849,   850,   851,   852,   852,   853,   854,   855,   856,   856,
     857,   858,   859,   860,   860,   861,   861,   861,   861,   861,
     861,   861,   861,   862,   862,   863,   863,   864,   865,   865,
     866,   866,   867,   868,   869,   869,   870,   870,   871,   871,
     872,   872,   873,   874,   875,   875,   876,   877,   878,   879,
     879,   880,   880,   880,   881,   881,   882,   883,   884,   885,
     885,   886,   887,   887,   888,   888,   889,   890,   891,   892,
     892,   893,   894,   895,   895,   896,   896,   897,   898,   899,
     899,   900,   901,   902,   902,   903,   903,   904,   905,   905,
     906,   907,   907,   908,   909,   910,   911,   911,   912,   913,
     914,   914,   915,   916,   917,   918,   918,   919,   920,   921,
     921,   922,   923,   924,   925,   925,   926,   927,   928,   928,
     929,   930,   931,   932,   932,   933,   934,   935,   935,   936,
     937,   938,   939,   939,   940,   941,   942,   942,   943,   944,
     945,   946,   946,   947,   948,   949,   949,   950,   951,   952,
     953,   953,   954,   955,   956,   956,   957,   958,   959,   960,
     960,   961,   962,   963,   964,   964,   965,   965,   965,   965,
     965,   965,   965,   965,   966,   966,   967,   967,   968,   969,
     969,   970,   970,   971,   972,   973,   973,   974,   974,   975,
     975,   976,   976,   977,   978,   979,   979,   980,   981,   982,
     983,   983,   984,   984,   984,   985,   985,   986,   987,   988,
     989,   989,   990,   991,   991,   992,   992,   993,   994,   995,
     996,   996,   997,   998,   999,   999,  1000,  1000,  1001,  1002,
    1003,  1003,  1004,  1005,  1006,  1006,  1007,  1007,  1008,  1009,
    1009,  1010,  1011,  1011,  1012,  1013,  1014,  1015,  1015,  1016,
    1017,  1018,  1018,  1019,  1020,  1021,  1022,  1022,  1023,  1024,
    1025,  1025,  1026,  1027,  1028,  1029,  1029,  1030,  1031,  1032,
    1032,  1033,  1034,  1035,  1036,  1036,  1037,  1038,  1039,  1039,
    1040,  1041,  1042,  1043,  1043,  1044,  1045,  1046,  1046,  1047,
    1048,  1049,  1050,  1050,  1051,  1052,  1053,  1053,  1054,  1055,
    1056,  1057,  1057,  1058,  1059,  1060,  1060,  1061,  1062,  1063,
    1064,  1064,  1065,  1066,  1067,  1068,  1068,  1069,  1069,  1069,
    1069,  1069,  1069,  1069,  1069,  1070,  1070,  1071,  1071,  1072,
    1073,  1073,  1074,  1074,  1075,  1076,  1077,  1077,  1078,  1078,
    1079,  1079,  1080,  1080,  1081,  1082,  1083,  1083,  1084,  1085,
    1086,  1087,  1087,  1088,  1088,  1088,  1089,  1089,  1090,  1091,
    1092,  1093,  1093,  1094,  1095,  1095,  1096,  1097,  1098,  1098,
    1099,  1100,  1101,  1101,  1102,  1103,  1104,  1105,  1105,  1106,
    1107,  1108,  1108,  1109,  1110,  1111,  1112,  1112,  1113,  1113,
    1114,  1115,  1116,  1117,  1117,  1118,  1118,  1118,  1118,  1118,
    1118,  1118,  1118,  1119,  1119,  1120,  1120,  1121,  1122,  1122,
    1123,  1123,  1124,  1124,  1125,  1126,  1127,  1128,  1128,  1129,
    1129,  1129,  1130,  1130,  1131,  1132,  1133,  1134,  1134,  1135,
    1136,  1136,  1137,  1138,  1139,  1139,  1140,  1140,  1141,  1142,
    1143,  1143,  1144,  1145,  1146,  1147,  1147,  1148,  1148,  1148,
    1148,  1148,  1149,  1149,  1150,  1150,  1151,  1152,  1153,  1153,
    1154,  1155,  1155,  1156,  1156,  1157,  1158,  1159,  1159,  1160,
    1161,  1162,  1162,  1163,  1163,  1164,  1165,  1166,  1166,  1167,
    1168,  1169,  1170,  1170,  1171,  1171,  1171,  1171,  1172,  1172,
    1173,  1173,  1174,  1175,  1176,  1176,  1177,  1178,  1178,  1179,
    1179,  1180,  1181,  1182,  1183,  1183,  1184,  1185,  1186,  1187,
    1187,  1188,  1189,  1190,  1191,  1191,  1192,  1193,  1194,  1195,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,  1201,  1202,  1203,
    1204,  1205,  1205,  1206,  1207,  1208,  1209,  1209,  1210,  1211,
    1212,  1213,  1213,  1214,  1215,  1216,  1217,  1217,  1218,  1219,
    1220,  1221,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,
    1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,
    1239,  1240,  1241,  1242,  1243,  1244,  1244,  1245,  1245,  1245,
    1246,  1247,  1247,  1248,  1248,  1248,  1248,  1249,  1250,  1251,
    1251,  1252,  1253,  1254,  1255,  1255,  1256,  1256,  1256,  1256,
    1256,  1257,  1258,  1258,  1259,  1259,  1260,  1261,  1262,  1262,
    1263,  1263,  1264,  1265,  1266,  1266,  1267,  1267,  1268,  1269,
    1270,  1270,  1271,  1271,  1272,  1273,  1274,  1274,  1275,  1275,
    1276,  1277,  1277,  1278,  1278,  1279,  1280,  1281,  1282,  1282,
    1283,  1283,  1284,  1285,  1286,  1286,  1287,  1287,  1288,  1289,
    1289,  1290,  1290,  1291,  1292,  1293,  1293,  1294,  1295,  1296,
    1296,  1297,  1297,  1298,  1300,  1299,  1301,  1302,  1302,  1302,
    1302,  1302,  1302,  1302,  1302,  1302,  1303,  1304,  1305,  1306,
    1307,  1307,  1308,  1309,  1310,  1311,  1311,  1312,  1313,  1314,
    1314,  1315,  1315,  1315,  1315,  1315,  1315,  1315,  1315,  1315,
    1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1324,
    1325,  1326,  1327,  1328,  1328,  1329,  1329,  1330,  1330,  1330,
    1330,  1330,  1330,  1330,  1330,  1331,  1332,  1333,  1334,  1334,
    1335,  1335,  1336,  1337,  1337,  1338,  1339,  1340,  1340,  1341,
    1342,  1343,  1344,  1345,  1346,  1346,  1347,  1348,  1349,  1350,
    1351,  1352,  1352,  1353,  1354,  1355,  1356,  1357,  1358,  1359,
    1359,  1360,  1360,  1361,  1362,  1362,  1363,  1364,  1365,  1365,
    1366,  1367,  1368,  1369,  1370,  1371,  1372,  1372,  1373,  1373,
    1374,  1375,  1375,  1376,  1376,  1377,  1378,  1378,  1379,  1380,
    1381,  1382,  1382,  1383,  1384,  1385,  1386,  1386,  1387,  1387,
    1388,  1389,  1389,  1390,  1391,  1392,  1392,  1393,  1394,  1395,
    1395,  1396,  1397,  1398,  1399,  1400,  1400,  1401,  1401,  1402,
    1403,  1403,  1404,  1404,  1405,  1406,  1406,  1407,  1408,  1409,
    1409,  1410,  1411,  1412,  1412,  1413,  1414,  1415,  1416,  1417,
    1418,  1418,  1419,  1419,  1420,  1421,  1421,  1422,  1423,  1424,
    1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1431,  1432,
    1432,  1433,  1434,  1434,  1435,  1435,  1436,  1437,  1437,  1438,
    1439,  1440,  1440,  1441,  1442,  1443,  1443,  1444,  1444,  1444,
    1445,  1446,  1447,  1448,  1449,  1449,  1450,  1451,  1452,  1453,
    1454,  1455,  1456,  1457,  1458,  1459,  1459,  1460,  1461,  1462,
    1463,  1464,  1465,  1466,  1466,  1467,  1468,  1469,  1470,  1470,
    1471,  1472,  1473,  1474,  1474,  1475,  1475,  1475,  1475,  1476,
    1477,  1478,  1478,  1479,  1480,  1481,  1482,  1483,  1484,  1485,
    1486,  1487,  1488,  1489,  1490,  1491,  1492,  1492,  1493,  1494,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1497,  1496,  1498,
    1498,  1500,  1499,  1501,  1501,  1503,  1502,  1505,  1504,  1507,
    1506,  1509,  1508,  1511,  1510,  1513,  1512,  1515,  1514,  1517,
    1516,  1519,  1518,  1521,  1520,  1523,  1522,  1525,  1524,  1526,
    1527,  1528,  1530,  1529,  1532,  1531,  1534,  1533,  1536,  1535,
    1538,  1537,  1540,  1539,  1541,  1541,  1542,  1542,  1543,  1543,
    1543,  1545,  1544,  1547,  1546,  1548,  1550,  1549,  1551,  1551,
    1552,  1551,  1553,  1553,  1554,  1554,  1555,  1556,  1558,  1557,
    1559,  1559,  1561,  1560,  1562,  1562,  1564,  1563,  1565,  1565,
    1567,  1566,  1568,  1568,  1570,  1569,  1571,  1571,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1573,  1574,  1575,
    1575,  1576,  1577,  1578,  1579,  1579,  1580,  1581,  1582,  1583,
    1583,  1584,  1585,  1586,  1587,  1587,  1588,  1589,  1590,  1591,
    1592,  1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,
    1602,  1603,  1603,  1604,  1605,  1606,  1607,  1607,  1608,  1609,
    1610,  1611,  1612,  1612,  1613,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1624,  1626,  1625,  1627,  1627,
    1628,  1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636
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
       1,     0,     2,     1,     1,     1,     4,     3,     3,     9,
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
       1,     0,     2,     1,     1,     1,     1,     4,     0,     3,
       1,     1,     1,     1,     1,     4,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       1,     2,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     1,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     3,     4,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     1,
       2,     0,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     3,     3,     1,     1,     2,     1,     3,     1,
       1,     0,     2,     3,     1,     0,     1,     3,     3,     1,
       1,     2,     1,     3,     0,     4,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     4,
       1,     1,     1,     3,     2,     0,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     1,     1,     1,
       1,     3,     4,     2,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     0,     2,
       1,     1,     3,     0,     2,     2,     1,     1,     1,     1,
       3,     1,     2,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     3,     1,     4,     1,     1,     0,
       2,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     3,     1,     4,     1,     1,     0,     2,     1,     1,
       3,     0,     2,     0,     2,     1,     1,     1,     1,     3,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       4,     1,     1,     1,     3,     0,     2,     3,     1,     0,
       4,     3,     4,     1,     1,     0,     2,     1,     1,     3,
       0,     2,     0,     2,     1,     1,     1,     1,     3,     0,
       2,     2,     1,     1,     1,     1,     3,     4,     1,     1,
       0,     2,     1,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     3,     1,     4,     1,     1,     0,     2,     1,
       1,     3,     0,     2,     0,     2,     1,     1,     1,     1,
       3,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       3,     3,     5,     1,     0,     1,     1,     3,     1,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     4,
       4,     1,     1,     1,     3,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       2,     0,     3,     1,     2,     0,     5,     0,     5,     0,
       5,     0,     4,     0,     5,     0,     5,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       1,     1,     0,     4,     0,     6,     0,     4,     0,     4,
       0,     4,     0,     4,     1,     2,     0,     2,     1,     1,
       1,     0,     4,     0,     4,     4,     0,     4,     1,     2,
       0,     4,     0,     2,     1,     1,     4,     4,     0,     4,
       0,     2,     0,     4,     0,     2,     0,     4,     0,     2,
       0,     4,     0,     2,     0,     4,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     4,     3,     1,     1,     2,     4,     3,     1,     1,
       2,     4,     3,     1,     1,     2,     4,     2,     1,     2,
       2,     1,     3,     2,     1,     2,     2,     1,     2,     4,
       1,     0,     1,     2,     4,     1,     0,     1,     2,     3,
       2,     1,     1,     2,     2,     1,     3,     2,     1,     2,
       2,     1,     3,     2,     1,     3,     0,     4,     0,     2,
       2,     1,     3,     2,     1,     6,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,  1208,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   140,     0,
    1214,  1211,  1207,  1209,  1210,    16,    10,     3,     8,     9,
     142,   219,     0,     0,    24,    19,    21,    22,     0,  1213,
      14,   221,   297,     0,     0,   146,   141,   143,   144,    23,
      39,    88,    96,    64,   120,    80,    72,   104,   112,     0,
      26,    27,    29,     0,    30,     0,    31,     0,    32,     0,
      33,     0,    34,     0,    35,     0,    36,     0,    37,     0,
    1212,     0,  1225,  1224,     0,  1231,  1230,     0,  1237,  1236,
       0,  1243,  1242,     0,  1249,  1248,  1215,  1216,  1221,  1222,
    1223,  1217,  1227,  1228,  1229,  1218,  1233,  1234,  1235,  1219,
    1239,  1240,  1241,  1220,  1245,  1246,  1247,    11,   299,   440,
       0,     0,   225,   220,   222,   223,   145,   193,   184,   166,
     175,   199,   158,     0,   148,   149,   151,     0,   152,   168,
     153,   177,   154,   186,   155,   194,   156,     0,    25,    28,
    1201,     0,  1136,  1158,     0,     0,    40,    41,    44,  1133,
    1134,  1135,    43,  1155,  1156,  1157,    45,     0,    68,    63,
      65,    66,     0,    76,    71,    73,    74,     0,    84,    79,
      81,    82,     0,    92,    87,    89,    90,     0,   100,    95,
      97,    98,     0,   108,   103,   105,   106,     0,   116,   111,
     113,   114,  1201,     0,   121,     0,     0,     0,     0,     0,
     442,    15,   444,     0,   303,   298,   300,   301,   224,   245,
     237,   277,   269,   261,   253,     0,   227,   228,   230,     0,
     231,     0,   232,     0,   233,     0,   234,     0,   235,     0,
     147,   150,     0,   162,   157,   159,   160,     0,   167,     0,
     176,     0,   185,     0,   195,     0,   200,     0,     0,  1201,
    1201,     0,    49,    38,    46,    47,    42,    70,    67,     0,
      78,    75,     0,    86,    83,     0,    94,    91,     0,   102,
      99,     0,   110,   107,     0,   118,   115,     0,     0,     0,
     125,   119,   122,   123,  1226,  1232,  1238,  1244,  1250,     0,
     443,   302,   344,   352,   420,   336,   320,   328,   360,   414,
     405,   387,   396,     0,   305,   306,   308,     0,   309,     0,
     310,     0,   311,     0,   312,     0,   313,     0,   314,   389,
     315,   398,   316,   407,   317,   415,   318,     0,   226,   229,
       0,   241,   236,   238,   239,     0,   249,   244,   246,   247,
       0,   257,   252,   254,   255,     0,   265,   260,   262,   263,
       0,   273,   268,   270,   271,     0,   278,   164,   161,     0,
       0,   165,     0,  1163,   169,   171,   170,  1160,  1161,  1162,
       0,   174,   178,   180,   179,     0,   183,   187,   189,   188,
       0,   192,     0,   204,   198,   201,   202,  1201,  1200,  1203,
    1204,  1205,  1206,  1202,  1137,  1159,    48,    55,     0,    51,
      52,    57,    69,    77,    85,    93,   101,   109,   117,  1201,
     131,   124,     0,   127,   128,   133,     0,   453,   441,   450,
     451,  1201,  1201,  1201,  1201,   445,   448,   449,   446,   447,
     304,   307,     0,   324,   319,   321,   322,     0,   332,   327,
     329,   330,     0,   340,   335,   337,   338,     0,   348,   343,
     345,   346,     0,   356,   351,   353,   354,  1201,     0,   361,
       0,   388,     0,   397,     0,   406,     0,   416,     0,   421,
     243,   240,     0,   251,   248,     0,   259,   256,     0,   267,
     264,     0,  1195,  1196,   272,     0,   275,     0,   282,   276,
     279,   280,   163,     0,   173,  1201,     0,   182,     0,   191,
     197,     0,   210,   203,     0,   206,   207,   212,  1191,    50,
      53,     0,    56,  1186,   126,   129,     0,   132,   452,   459,
       0,  1087,   456,   461,     0,     0,     0,     0,   326,   323,
       0,   334,   331,     0,   342,   339,     0,   350,   347,     0,
     358,   355,     0,     0,     0,   365,   359,   362,   363,     0,
     386,   390,   392,   391,     0,   395,   399,   401,   400,     0,
     404,   408,   410,   409,     0,   413,     0,   425,   419,   422,
     423,   242,   250,   258,   266,   274,   288,   281,     0,   284,
     285,   290,   172,  1164,   181,   190,   196,   205,   208,     0,
     211,     0,    62,    54,  1148,     0,    58,    60,    59,  1145,
    1146,  1147,     0,   139,   130,     0,  1168,   134,   137,   135,
     136,  1165,  1166,  1167,   454,  1089,   457,   455,     0,     0,
     460,  1201,  1201,  1201,  1201,   325,   333,   341,   349,   357,
    1201,   371,   364,     0,   367,   368,   372,     0,   394,     0,
     403,     0,   412,   418,     0,   431,   424,     0,   427,   428,
     433,   283,   286,     0,   289,     0,   218,   209,   213,   216,
     214,   215,    61,  1201,   138,  1201,  1201,     0,  1090,     0,
     458,  1201,     0,     0,   462,   463,   464,   465,  1176,  1182,
    1189,  1194,  1192,   366,   369,     0,   393,   402,   411,   417,
     426,   429,     0,   432,     0,   296,   287,   291,   294,   292,
     293,   217,  1149,  1169,     0,     0,  1094,  1088,  1091,  1092,
     471,   495,     0,     0,  1201,  1201,     0,   381,     0,  1126,
     373,   370,   378,   379,   376,  1123,  1124,  1125,   377,   375,
     374,     0,   439,   430,   434,   437,   435,   436,   295,  1201,
    1093,  1100,     0,  1096,  1097,  1102,   497,   504,     0,     0,
     472,   473,   476,   475,   477,  1201,   468,   467,   385,   384,
     380,     0,   383,  1201,   438,  1190,  1095,  1098,     0,  1101,
     506,   679,   507,     0,   501,   496,   498,   499,     0,   481,
     470,   478,   479,   474,   466,   382,  1127,     0,  1111,  1099,
    1108,  1109,  1201,  1103,  1105,  1106,  1104,  1107,   681,   830,
     682,  1201,     0,   508,   503,   500,     0,   480,   487,     0,
     483,   484,   489,  1110,  1120,     0,  1119,     0,  1113,  1114,
    1116,  1117,  1118,     0,   832,   981,   833,  1201,     0,   683,
       0,   514,   511,   505,   509,   510,   502,   482,   485,     0,
     488,  1122,     0,  1112,  1115,  1201,   983,  1050,     0,  1201,
       0,   834,     0,   689,   686,   680,   684,   685,  1201,   516,
       0,   533,     0,     0,   494,   486,   490,   492,   491,  1121,
    1179,  1052,     0,     0,   988,   986,   982,   984,   985,     0,
     840,   837,   831,   835,   836,  1201,   691,     0,   708,     0,
    1188,   512,   535,   557,     0,  1201,     0,   517,   493,   469,
    1201,     0,  1053,   990,  1047,     0,  1201,   842,     0,   859,
       0,  1185,   687,   710,   779,     0,  1201,     0,   692,   559,
     628,     0,     0,   536,     0,     0,   521,   515,   518,   519,
       0,     0,  1057,  1051,  1054,  1055,     0,  1201,     0,   991,
    1183,   838,   861,   930,     0,  1201,     0,   843,   688,   716,
     713,   709,   711,   712,     0,     0,   696,   690,   693,   694,
     513,   565,   562,   558,   560,   561,     0,   540,   534,   537,
     538,  1201,   527,   520,     0,   523,   524,   528,  1201,  1063,
    1056,     0,  1059,  1060,  1065,  1049,   987,  1048,     0,   997,
     994,   989,   992,   993,   839,   867,   864,   860,   862,   863,
       0,     0,   847,   841,   844,   845,   782,   780,   784,   718,
       0,   725,     0,  1201,   702,   695,     0,   698,   699,   703,
     631,   629,   633,   567,     0,   574,     0,   539,   546,     0,
     542,   543,   547,  1193,   522,   525,     0,  1187,  1058,  1061,
       0,  1064,  1201,   999,  1008,     0,   933,   931,   935,   869,
       0,   876,     0,  1201,   853,   846,     0,   849,   850,   854,
       0,   783,   714,   727,   734,     0,  1201,     0,   719,  1181,
     697,   700,     0,     0,   632,   563,   576,   583,     0,     0,
     568,   541,   544,     0,     0,  1201,   529,   526,   530,   531,
       0,  1075,  1062,  1072,  1073,  1066,  1069,  1070,  1067,  1068,
    1071,  1184,     0,  1201,     0,  1000,     0,   934,   865,   878,
     885,     0,     0,   870,  1175,   848,   851,     0,     0,   797,
     781,   794,   795,  1201,     0,  1141,     0,  1153,   785,   793,
     792,  1138,  1139,  1140,   789,   791,  1150,  1151,  1152,   790,
     788,   787,   786,   736,   743,     0,     0,   728,     0,  1253,
     722,   717,   720,   721,     0,   704,   701,   705,   706,     0,
     646,   630,   643,   644,     0,  1173,   634,   642,   641,   638,
     639,   637,   640,  1170,  1171,  1172,   636,   635,   585,   592,
       0,     0,   577,  1253,   571,   566,   569,   570,     0,   554,
     548,   545,   551,   552,   549,   550,     0,     0,  1074,  1084,
       0,  1083,     0,  1077,  1078,  1080,  1081,  1082,  1011,   996,
     995,  1009,  1013,     0,  1006,  1003,   998,  1001,  1002,     0,
     948,   932,   945,   946,     0,  1131,   936,   942,  1128,  1129,
    1130,   944,   943,   940,   941,   939,   937,   938,   887,   894,
       0,     0,   879,  1253,   873,   868,   871,   872,     0,   855,
     852,   856,   857,   804,   796,   818,     0,   799,   801,   805,
     800,   815,   820,     0,  1201,  1201,   745,   752,     0,     0,
     737,  1253,   731,   726,   729,   730,  1201,     0,     0,   724,
    1251,  1252,     0,   645,   653,   667,     0,   648,   650,   654,
     649,   664,   669,  1201,   594,   601,     0,     0,   586,  1253,
     580,   575,   578,   579,     0,   573,   556,   553,     0,   532,
    1201,  1086,     0,  1076,  1079,     0,  1012,  1201,     0,   955,
     947,   969,     0,   950,   952,   956,   951,   966,   971,  1201,
     896,   903,     0,     0,   888,  1253,   882,   877,   880,   881,
       0,   875,     0,   798,   802,     0,   816,     0,   819,  1201,
    1142,  1154,   754,   761,     0,     0,   746,  1253,   740,   735,
     738,   739,     0,   733,  1177,     0,     0,   723,  1256,  1254,
    1258,   707,   647,   651,     0,   665,     0,   668,  1174,   603,
     610,     0,     0,   595,  1253,   589,   584,   587,   588,     0,
     582,   572,   555,  1144,  1085,     0,  1026,  1010,  1023,  1024,
       0,  1014,  1022,  1021,  1020,  1018,  1019,  1017,  1016,  1015,
    1180,  1005,  1286,  1004,  1007,  1284,   949,   953,     0,   967,
       0,   970,  1132,   905,   912,     0,     0,   897,  1253,   891,
     886,   889,   890,     0,   884,   874,   858,     0,   812,   806,
     803,   809,   810,   807,   808,  1253,   827,   817,   825,   826,
     821,   824,   823,   822,  1178,   763,   770,     0,     0,   755,
    1253,   749,   744,   747,   748,     0,   742,   732,     0,     0,
    1267,  1263,  1264,  1265,     0,  1257,     0,   661,   655,   652,
     658,   659,   656,   657,  1253,   676,   666,   674,   675,   670,
     673,   672,   671,   612,   619,     0,     0,   604,  1253,   598,
     593,   596,   597,     0,   591,   581,  1025,  1035,     0,  1028,
    1029,  1032,  1037,  1030,     0,  1288,     0,   963,   957,   954,
     960,   961,   958,   959,  1253,   978,   968,   976,   977,   972,
     975,   974,   973,   914,   921,     0,     0,   906,  1253,   900,
     895,   898,   899,     0,   893,   883,  1197,  1198,  1199,   811,
       0,   814,     0,   829,   772,   715,     0,     0,   764,  1253,
     758,   753,   756,   757,     0,   751,   741,     0,     0,  1266,
       0,  1255,     0,     0,  1259,  1261,  1260,   660,     0,   663,
       0,   678,   621,   564,     0,     0,   613,  1253,   607,   602,
     605,   606,     0,   600,   590,  1027,  1031,  1033,     0,  1036,
    1143,     0,     0,     0,     0,     0,  1201,     0,  1290,  1293,
    1294,  1295,  1292,  1291,   962,     0,   965,     0,   980,   923,
     866,     0,     0,   915,  1253,   909,   904,   907,   908,     0,
     902,   892,   813,   828,     0,   773,  1253,   767,   762,   765,
     766,     0,   760,   750,  1552,  1268,     0,     0,     0,   662,
     677,     0,   622,  1253,   616,   611,   614,   615,     0,   609,
     599,  1253,  1044,  1034,  1042,  1043,  1038,  1041,  1040,  1039,
       0,     0,     0,     0,     0,     0,  1305,  1302,  1287,  1285,
    1300,  1301,   964,   979,     0,   924,  1253,   918,   913,   916,
     917,     0,   911,   901,  1253,   776,   771,   774,   775,     0,
     769,   759,  1262,     0,     0,  1253,   625,   620,   623,   624,
       0,   618,   608,     0,  1046,  1297,  1298,  1296,     0,     0,
    1201,  1307,     0,  1335,  1309,  1253,   927,   922,   925,   926,
       0,   920,   910,     0,   778,   768,  1553,  1554,     0,   627,
     617,  1045,  1547,  1549,  1299,  1303,  1304,     0,  1308,     0,
     929,   919,   777,   626,  1508,  1346,  1377,  1394,  1433,  1475,
    1458,  1503,  1336,  1337,  1348,  1338,  1379,  1339,  1396,  1340,
    1435,  1341,  1460,  1342,  1477,  1343,  1504,  1344,     0,     0,
    1334,  1306,     0,     0,     0,     0,     0,     0,     0,     0,
    1330,     0,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,
    1318,  1327,  1328,  1329,  1319,   928,     0,  1347,     0,  1378,
       0,  1395,     0,  1434,     0,  1459,     0,  1476,     0,     0,
    1505,     0,     0,  1509,  1333,     0,     0,     0,     0,     0,
       0,     0,     0,  1201,     0,     0,  1558,     0,  1349,  1350,
    1351,  1556,  1557,     0,  1380,  1381,  1382,     0,  1397,  1398,
    1399,     0,  1436,  1437,  1438,     0,  1461,  1462,  1463,     0,
    1478,  1479,  1480,     0,     0,     0,     0,  1507,     0,     0,
       0,     0,     0,     0,     0,     0,  1331,  1356,  1345,  1353,
       0,     0,     0,  1384,  1376,  1401,  1393,  1440,  1432,  1465,
    1457,  1482,  1474,  1555,  1703,  1708,  1713,  1718,  1721,  1730,
    1735,  1741,  1745,  1748,  1751,  1754,  1756,  1761,  1764,  1767,
    1698,  1724,  1727,     0,  1678,     0,  1679,     0,  1680,     0,
    1681,     0,  1682,     0,  1683,     0,  1696,     0,  1684,     0,
    1685,  1731,  1686,  1736,  1687,     0,  1688,     0,  1689,     0,
    1690,     0,  1691,     0,  1692,  1693,     0,  1694,     0,  1695,
       0,     0,  1513,     0,     0,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1332,  1363,     0,     0,     0,  1253,  1359,  1355,
    1357,  1358,     0,  1559,     0,     0,  1403,     0,  1442,     0,
       0,     0,  1484,     0,  1758,  1506,  1502,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1717,     0,  1720,  1605,
    1597,  1599,  1603,  1607,  1609,  1658,  1674,  1617,  1601,  1624,
    1611,  1613,  1615,  1646,  1620,  1622,  1666,  1662,  1670,  1587,
    1591,  1595,  1632,  1626,  1628,  1630,     0,  1581,  1582,  1562,
    1563,  1565,  1566,  1567,  1568,  1570,  1571,  1572,  1574,  1573,
    1575,  1577,     0,  1578,  1576,  1584,  1585,  1586,  1560,  1561,
    1564,  1583,  1579,  1580,  1569,  1723,     0,  1726,     0,     0,
    1732,     0,  1737,     0,  1742,  1740,     0,  1744,     0,  1747,
       0,  1750,     0,  1753,     0,  1760,     0,  1763,     0,  1766,
    1546,  1521,  1528,     0,     0,     0,  1514,  1352,  1370,  1354,
       0,  1253,  1366,  1362,  1364,  1365,  1361,     0,  1550,  1387,
    1385,     0,  1383,  1405,  1402,     0,  1400,  1444,  1441,     0,
    1439,  1468,  1466,     0,  1464,  1486,  1483,     0,  1481,     0,
       0,     0,  1699,  1697,     0,     0,  1704,  1702,     0,     0,
    1709,  1707,     0,     0,  1714,  1712,  1719,     0,     0,     0,
       0,     0,     0,     0,  1660,  1676,     0,     0,     0,     0,
       0,     0,  1652,     0,  1668,  1664,  1672,     0,     0,     0,
    1636,     0,     0,     0,  1725,     0,  1728,     0,     0,     0,
    1743,     0,  1749,     0,     0,     0,     0,  1768,     0,     0,
    1522,     0,  1253,  1517,  1512,  1515,  1516,  1271,  1373,  1369,
    1371,  1372,  1368,     0,  1360,  1253,  1390,  1386,  1388,  1389,
    1411,  1408,  1404,  1406,  1407,  1449,  1447,  1443,  1445,  1446,
    1253,  1471,  1467,  1469,  1470,  1491,  1489,  1485,  1487,  1488,
    1757,  1759,     0,  1700,     0,  1705,     0,  1710,     0,  1715,
    1722,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1589,  1588,     0,  1593,  1592,     0,     0,     0,     0,
       0,  1621,  1619,  1739,     0,  1729,     0,  1734,  1746,  1752,
    1755,  1762,     0,  1531,  1511,  1510,  1529,  1533,  1253,  1525,
    1520,  1523,  1524,     0,  1519,     0,     0,  1375,  1269,  1270,
       0,  1367,  1392,     0,     0,  1410,     0,  1473,     0,     0,
    1701,  1706,  1711,  1716,     0,     0,     0,     0,  1608,  1610,
    1659,  1661,  1675,  1677,  1618,  1602,     0,  1612,  1614,  1616,
       0,  1648,     0,     0,  1647,  1653,  1654,  1655,  1623,  1667,
    1669,  1663,  1665,  1671,  1673,  1590,  1594,     0,     0,  1634,
       0,     0,     0,  1633,  1637,  1638,  1640,  1639,  1627,  1629,
    1631,  1733,  1738,     0,     0,  1532,  1527,     0,  1548,  1518,
       0,  1274,  1272,  1275,  1374,  1391,  1409,  1414,  1412,  1416,
    1452,  1448,  1450,     0,  1472,  1494,  1490,  1492,  1495,  1606,
    1598,  1600,  1604,     0,  1649,  1650,     0,     0,  1596,  1635,
       0,  1641,  1643,     0,  1305,  1543,  1530,  1541,  1542,  1201,
    1201,  1537,  1538,  1534,  1535,  1536,  1526,     0,  1282,  1278,
    1279,  1280,     0,  1276,     0,  1415,     0,  1455,  1451,  1453,
    1454,     0,  1625,     0,     0,     0,     0,     0,     0,  1765,
    1335,     0,     0,     0,     0,  1281,     0,  1273,  1425,  1423,
    1413,  1421,  1422,     0,     0,  1417,  1419,  1418,     0,     0,
       0,  1496,  1497,  1493,  1499,  1498,  1651,  1657,  1656,  1645,
    1642,  1644,  1545,  1544,  1201,  1201,  1283,     0,     0,     0,
       0,  1456,     0,     0,  1539,  1540,  1277,  1424,  1428,  1426,
    1429,     0,     0,  1501,  1500,     0,     0,  1420,  1551,     0,
       0,  1427,     0,     0,  1430,  1431
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
     870,   871,   872,   906,   937,   938,   939,   984,   985,   986,
     987,  1046,  1096,  1097,   903,   904,   932,   978,   979,   980,
    1039,  1040,  1041,  1042,  1093,  1200,  1201,  1202,  1203,  1318,
     930,   931,   973,   974,   975,  1034,  1035,  1036,  1089,  1195,
    1196,  1197,  1314,  1087,  1088,  1191,  1311,  1312,  1313,  1399,
    1189,  1190,  1307,  1396,  1397,  1398,  1513,  1305,  1306,  1392,
    1510,  1511,  1512,  1602,  1390,  1391,  1506,  1599,  1600,  1601,
    1668,  1504,  1505,  1595,  1665,  1666,  1667,  1720,  1593,  1594,
    1661,  1717,  1718,  1719,  1748,   970,  1031,  1032,  1083,  1084,
    1176,  1171,  1172,  1173,  1296,  1297,  1298,  1299,  1384,  1488,
    1489,  1490,  1491,  1588,  1300,  1301,  1302,  1386,  1387,  1499,
    1496,  1497,  1498,  1590,   809,   810,   838,   865,   866,   867,
     897,   898,   899,   927,   967,   968,   969,  1026,  1027,  1028,
    1029,  1082,  1165,  1166,   924,   925,   961,   962,   963,  1020,
    1021,  1022,  1077,  1161,  1162,  1163,  1288,  1074,  1075,  1156,
    1283,  1284,  1285,  1372,  1154,  1155,  1279,  1369,  1370,  1371,
    1475,  1277,  1278,  1365,  1472,  1473,  1474,  1574,  1363,  1364,
    1468,  1571,  1572,  1573,  1651,  1466,  1467,  1567,  1648,  1649,
    1650,  1709,  1565,  1566,  1644,  1706,  1707,  1708,  1743,   958,
    1017,  1018,  1070,  1071,  1138,  1130,  1131,  1132,  1266,  1267,
    1268,  1269,  1355,  1449,  1450,  1451,  1452,  1560,  1270,  1271,
    1272,  1357,  1358,  1460,  1457,  1458,  1459,  1562,   835,   836,
     860,   892,   893,   894,   918,   919,   920,   956,  1013,  1014,
    1015,  1066,  1067,  1068,  1069,  1127,  1259,  1260,   953,   954,
    1007,  1008,  1009,  1060,  1061,  1062,  1122,  1255,  1256,  1257,
    1350,  1120,  1121,  1251,  1347,  1348,  1349,  1443,  1249,  1250,
    1343,  1440,  1441,  1442,  1553,  1341,  1342,  1436,  1550,  1551,
    1552,  1639,  1434,  1435,  1546,  1636,  1637,  1638,  1701,  1544,
    1545,  1632,  1698,  1699,  1700,  1740,  1630,  1631,  1694,  1737,
    1738,  1739,  1759,  1004,  1057,  1058,  1116,  1117,  1236,  1231,
    1232,  1233,  1332,  1333,  1334,  1335,  1428,  1528,  1529,  1530,
    1531,  1625,  1336,  1337,  1338,  1430,  1431,  1539,  1536,  1537,
    1538,  1627,   857,   858,   886,   887,   888,   914,   915,   948,
    1001,  1002,  1003,  1220,  1054,  1055,  1114,  1226,  1227,  1228,
    1423,  1328,  1112,  1221,  1222,  1325,  1326,  1411,  1407,  1408,
    1409,  1518,  1519,  1520,  1521,  1522,  1608,  1609,  1676,  1673,
    1674,  1675,  1723,   946,   997,   882,   883,   911,   943,   944,
     945,   991,   992,   993,   994,  1050,  1051,  1105,  1102,  1103,
    1104,  1212,  1213,  1214,  1215,  1216,  1217,  1322,   627,   628,
     677,   717,   718,   719,   752,   753,   754,   755,   778,   779,
     803,   799,   800,   801,   827,   828,   829,   830,   831,   832,
     852,   734,   735,   736,   737,  1237,  1238,  1239,  1240,   158,
     159,   160,   161,  1140,  1141,  1142,  1143,  1414,  1098,   608,
     609,   610,   611,  1145,  1146,  1147,  1148,   162,   163,   164,
     165,   376,   377,   378,   379,   620,   621,   622,   623,  1182,
    1183,  1184,  1185,   957,   436,  1078,  1151,   807,  1115,   928,
     437,   861,   949,   839,   204,   912,   813,   438,   678,   166,
     469,   907,   439,   496,  1561,   257,   258,   403,    10,    11,
      22,    23,    24,    38,    39,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,  1289,  1290,  1379,  1380,
    1484,  1485,  1584,  1581,  1291,  1481,  1482,  1483,  2297,  2298,
    2372,  2373,  2422,  2447,  2299,  2419,  2420,  2421,  1424,  1525,
    1425,  1688,  1618,  1619,  1620,  1621,  1689,  1690,  1691,  1732,
    1733,  1734,  1757,  1758,  1802,  1803,  1804,  1805,  1806,  1807,
    1808,  1809,  1810,  1811,  1812,  1813,  1814,  1791,  1756,  1772,
    1773,  1774,  1816,  1817,  1848,  1888,  1974,  1889,  1890,  1979,
    1980,  1981,  2107,  1975,  1976,  2103,  2104,  2105,  2203,  2099,
    2100,  2199,  2200,  2201,  2300,  1775,  1776,  1818,  1819,  1854,
    1894,  1985,  2110,  2111,  2207,  2208,  2209,  2303,  1777,  1778,
    1820,  1821,  1858,  1896,  1987,  2114,  2115,  2212,  2213,  2214,
    2304,  2305,  2378,  2379,  2424,  2425,  2455,  2456,  2450,  2451,
    2452,  2478,  2489,  2490,  2496,  2501,  1779,  1780,  1822,  1823,
    1862,  1898,  1989,  2118,  2119,  2217,  2218,  2219,  2306,  2382,
    2383,  2428,  2429,  2430,  1781,  1782,  1824,  1825,  1866,  1900,
    1991,  2122,  2123,  2222,  2223,  2224,  2308,  1783,  1784,  1826,
    1827,  1870,  1902,  1993,  2126,  2127,  2227,  2228,  2229,  2309,
    2387,  2388,  2431,  2461,  2462,  2463,  1785,  1786,  1829,  1996,
    1787,  1788,  1832,  1877,  2285,  1963,  1964,  2095,  2194,  2195,
    2196,  2295,  2092,  2093,  2189,  2290,  2291,  2292,  2367,  2188,
    2286,  2287,  2364,  2365,  2413,  2414,  2415,  2406,  2407,  2408,
    2441,  1833,  1622,  2096,  1623,  1849,  2457,  1376,  1585,  1586,
    1830,  1850,  1851,  1852,  2036,  2037,  2167,  2262,  2038,  2168,
    2265,  2039,  2169,  2040,  2149,  2041,  2150,  2042,  2157,  2043,
    2151,  2044,  2148,  2045,  2152,  2046,  2153,  2047,  2159,  2048,
    2160,  2049,  2161,  2050,  2156,  2051,  2052,  2272,  2053,  2163,
    2054,  2158,  2055,  2171,  2056,  2172,  2057,  2173,  2058,  2170,
    2353,  2267,  2354,  2355,  2437,  2356,  2438,  2357,  2059,  2162,
    2334,  2433,  2255,  2335,  2336,  2337,  2060,  2154,  2247,  2061,
    2165,  2258,  2062,  2164,  2257,  2063,  2166,  2259,  2064,  2155,
    2248,  1923,  1924,  1925,  2133,  1998,  1926,  1927,  2137,  2000,
    1928,  1929,  2141,  2002,  1930,  1931,  2145,  2004,  1932,  1933,
    2006,  1934,  1935,  2008,  1936,  1937,  2065,  1938,  1939,  2067,
    1940,  1941,  2069,  2275,  1942,  1943,  2071,  2277,  2070,  1944,
    1945,  2075,  1946,  1947,  2077,  1948,  1949,  2079,  1950,  1951,
    2081,  1952,  1953,  2083,  1954,  1994,  2129,  1955,  1956,  2085,
    1957,  1958,  2087,  1959,  1960,  2089
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2206
static const yytype_int16 yypact[] =
{
     395, -2206, -2206,    21,   -36,   161, -2206, -2206,   168,   110,
   -2206,   416, -2206,   450, -2206, -2206, -2206, -2206,   131,   467,
   -2206, -2206, -2206, -2206, -2206,   -36, -2206, -2206, -2206, -2206,
   -2206,   154,   484,   274, -2206, -2206, -2206, -2206,     8,   820,
     168, -2206,   207,   492,   268, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   259,
     600, -2206, -2206,   122, -2206,   504, -2206,   568, -2206,   583,
   -2206,   587, -2206,   592, -2206,   618, -2206,   621, -2206,   284,
   -2206,   345, -2206, -2206,   352, -2206, -2206,   378, -2206, -2206,
     398, -2206, -2206,   408, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   363,
     628,   311, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,   373,   412, -2206, -2206,   632, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206,   617, -2206,   284, -2206, -2206,
   -2206,   434, -2206, -2206,   443,   650,   122, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206,   142, -2206, -2206,
   -2206, -2206,    48, -2206, -2206, -2206, -2206,    88, -2206, -2206,
   -2206, -2206,    73, -2206, -2206, -2206, -2206,   132, -2206, -2206,
   -2206, -2206,    65, -2206, -2206, -2206, -2206,    44, -2206, -2206,
   -2206, -2206, -2206,   665, -2206,   254,   269,   253,   263,   265,
   -2206, -2206, -2206,   573, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206,   422,   251, -2206, -2206,   669,
   -2206,   674, -2206,   678, -2206,   686, -2206,   689, -2206,   284,
   -2206, -2206,    36, -2206, -2206, -2206, -2206,   476,   406,   482,
     406,   500,   406,   517, -2206,   720, -2206,   523,    12, -2206,
   -2206,    69, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   417,
   -2206, -2206,   402, -2206, -2206,   400, -2206, -2206,   438, -2206,
   -2206,   430, -2206, -2206,   407, -2206, -2206,   399,   577,   198,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   722,
     516, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,   508,   249, -2206, -2206,   728, -2206,   730,
   -2206,   739, -2206,   741, -2206,   744, -2206,   556, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206,   617, -2206,   284, -2206, -2206,
     139, -2206, -2206, -2206, -2206,   151, -2206, -2206, -2206, -2206,
      32, -2206, -2206, -2206, -2206,    42, -2206, -2206, -2206, -2206,
      67, -2206, -2206, -2206, -2206,   746, -2206, -2206, -2206,   448,
     756, -2206,   607, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
     756, -2206, -2206, -2206, -2206,   756, -2206, -2206, -2206, -2206,
     606, -2206,   232, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   514,   469,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206,   498,   495, -2206, -2206,    47, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206,    60, -2206, -2206, -2206, -2206,    35, -2206, -2206,
   -2206, -2206,    71, -2206, -2206, -2206, -2206,   105, -2206, -2206,
   -2206, -2206,   143, -2206, -2206, -2206, -2206, -2206,   754, -2206,
     623,   406,   626,   406,   634,   406,   642, -2206,   761, -2206,
   -2206, -2206,   530, -2206, -2206,   562, -2206, -2206,   496, -2206,
   -2206,   510, -2206, -2206, -2206,   524, -2206,   240, -2206, -2206,
   -2206, -2206, -2206,   588, -2206, -2206,   599, -2206,   614, -2206,
   -2206,   633, -2206, -2206,   576,   581, -2206, -2206, -2206, -2206,
   -2206,   765,    49, -2206, -2206, -2206,   767,    17, -2206, -2206,
     652,    23, -2206, -2206,   710,   715,   752,   760, -2206, -2206,
     612, -2206, -2206,   597, -2206, -2206,   639, -2206, -2206,   716,
   -2206, -2206,   690,   786,    13, -2206, -2206, -2206, -2206,   756,
   -2206, -2206, -2206, -2206,   756, -2206, -2206, -2206, -2206,   756,
   -2206, -2206, -2206, -2206,   792, -2206,   244, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   676,   677,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   770,
      17,   654, -2206, -2206, -2206,   805, -2206, -2206, -2206, -2206,
   -2206, -2206,   688, -2206, -2206,   811, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   791,   854,
     413, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,   709,   737, -2206, -2206,   705, -2206,   758,
   -2206,   764, -2206, -2206,   762, -2206, -2206,   812,   817, -2206,
   -2206, -2206, -2206,   772,    17,   824, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206,   806, -2206,   795,
   -2206, -2206,   941,   947, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206,    70, -2206, -2206, -2206, -2206,
   -2206, -2206,   808,    17,   828, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,   963,    29, -2206, -2206, -2206, -2206,
   -2206,   858,   122,   967, -2206, -2206,    54, -2206,   972, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206,   853, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206,   849,   840, -2206, -2206, -2206,   802,   823,   825,
     122, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206,   829, -2206, -2206, -2206, -2206, -2206, -2206,   827,   104,
   -2206,   872,   964,   147, -2206, -2206, -2206, -2206,   229, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206,   145, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   902,
     971, -2206,   830, -2206, -2206, -2206,   883, -2206, -2206,   851,
     850, -2206, -2206, -2206, -2206,   998, -2206,   868,   178, -2206,
   -2206, -2206, -2206,   999, -2206,   711,  1003, -2206,   832, -2206,
    1024,   831, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   838,
     -10, -2206,   886, -2206, -2206, -2206, -2206,   981,   841, -2206,
     843, -2206,  1106,   833, -2206, -2206, -2206, -2206, -2206, -2206,
     932,   939,  1091,   965, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206,   973,  1093,   822, -2206, -2206, -2206, -2206,  1115,
    1030, -2206, -2206, -2206, -2206, -2206, -2206,  1011,  1062,  1112,
   -2206, -2206, -2206,  1095,  1091, -2206,   846, -2206, -2206, -2206,
   -2206,   848, -2206, -2206, -2206,   954, -2206, -2206,  1049,  1097,
    1127, -2206, -2206, -2206, -2206,   852, -2206,   856, -2206, -2206,
   -2206,   859,   861, -2206,  1139,   -68, -2206, -2206, -2206, -2206,
    1143,   261, -2206, -2206, -2206, -2206,   -66, -2206,   865, -2206,
   -2206, -2206, -2206, -2206,   867, -2206,   874, -2206,  1051,  1101,
   -2206, -2206, -2206, -2206,  1145,   -99, -2206, -2206, -2206, -2206,
    1053,  1103, -2206, -2206, -2206, -2206,   708, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,   921,   974, -2206, -2206, -2206, -2206,
   -2206,  1074,  1063, -2206, -2206, -2206, -2206, -2206,  1149,   995,
   -2206, -2206, -2206, -2206,  1069,  1113, -2206, -2206, -2206, -2206,
    1192,   173, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
    1114,  1135,   993, -2206, -2206, -2206,   929,  1099, -2206, -2206,
   -2206, -2206, -2206, -2206,  1126,  1142,   993, -2206, -2206,  1037,
    1039, -2206, -2206, -2206, -2206, -2206,    78, -2206, -2206, -2206,
     878,    95, -2206, -2206, -2206,   905, -2206, -2206, -2206, -2206,
    1131,  1148,   993, -2206, -2206, -2206,  1123,  1134, -2206, -2206,
     881,   532, -2206, -2206,  1152,   993, -2206,   885, -2206, -2206,
   -2206, -2206,    87,   887,   645, -2206, -2206,  1154,   993,   889,
   -2206, -2206, -2206,    15,   756, -2206, -2206, -2206, -2206, -2206,
     152, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206,   -91, -2206,   891, -2206,   893,   609, -2206, -2206,
    1156,   993,   895, -2206, -2206, -2206, -2206,    91,     5, -2206,
   -2206, -2206, -2206, -2206,  1228, -2206,  1230, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,  1166,   993,   897, -2206,  1231,  1019,
   -2206, -2206, -2206, -2206,   756, -2206, -2206, -2206, -2206,   123,
   -2206, -2206, -2206, -2206,  1238, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,  1174,
     993,   899, -2206,  1019, -2206, -2206, -2206, -2206,    30, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,  1065,  1241, -2206, -2206,
    1246, -2206,  1125,   369, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,  1249, -2206, -2206, -2206, -2206, -2206,    10,
   -2206, -2206, -2206, -2206,  1254, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,  1194,
     993,   904, -2206,  1019, -2206, -2206, -2206, -2206,   756, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,  1137,  1150, -2206, -2206,
    1076, -2206, -2206,  1261, -2206, -2206, -2206,  1160,   993,   906,
   -2206,  1019, -2206, -2206, -2206, -2206, -2206,  1047,  1189, -2206,
    1078, -2206,  1159, -2206, -2206, -2206,  1153,  1100, -2206, -2206,
    1082, -2206, -2206, -2206, -2206,  1172,   993,   909, -2206,  1019,
   -2206, -2206, -2206, -2206,  1199, -2206, -2206, -2206,  1105, -2206,
   -2206, -2206,  1073, -2206, -2206,   911,    41, -2206,   114, -2206,
   -2206, -2206,  1163,  1208, -2206, -2206,  1086, -2206, -2206, -2206,
   -2206,  1196,   993,   913, -2206,  1019, -2206, -2206, -2206, -2206,
    1217, -2206,  1219, -2206, -2206,    22, -2206,   915,   100, -2206,
   -2206, -2206, -2206,  1158,   993,   917, -2206,  1019, -2206, -2206,
   -2206, -2206,  1235, -2206, -2206,  1305,   919, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,    61, -2206,   997,   100, -2206, -2206,
    1177,   993,  1001, -2206,  1019, -2206, -2206, -2206, -2206,  1260,
   -2206, -2206, -2206, -2206, -2206,   -24, -2206, -2206, -2206, -2206,
    1331, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,    83, -2206,
    1023,   100, -2206, -2206,  1183,   993,  1025, -2206,  1019, -2206,
   -2206, -2206, -2206,  1266, -2206, -2206, -2206,   121, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206,  1019, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,  1173,   993,  1028, -2206,
    1019, -2206, -2206, -2206, -2206,  1268, -2206, -2206,  1338,    18,
   -2206, -2206, -2206, -2206,  1361,   818,   115, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,  1019, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,  1206,   993,  1032, -2206,  1019, -2206,
   -2206, -2206, -2206,  1301, -2206, -2206, -2206, -2206,  1253,  1162,
    1168, -2206, -2206, -2206,  1371,   481,   159, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,  1019, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,  1216,   993,  1034, -2206,  1019, -2206,
   -2206, -2206, -2206,  1311, -2206, -2206, -2206, -2206, -2206, -2206,
    1271, -2206,  1179, -2206, -2206, -2206,   993,  1036, -2206,  1019,
   -2206, -2206, -2206, -2206,  1321, -2206, -2206,  1387,  1176, -2206,
    1393, -2206,  1394,  1395, -2206, -2206, -2206, -2206,  1221, -2206,
    1190, -2206, -2206, -2206,   993,  1038, -2206,  1019, -2206, -2206,
   -2206, -2206,  1335, -2206, -2206, -2206, -2206, -2206,  1040,   100,
   -2206,  1403,  1404,  1405,  1401,  1402, -2206,    52, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206,  1322, -2206,  1197, -2206, -2206,
   -2206,   993,  1042, -2206,  1019, -2206, -2206, -2206, -2206,  1343,
   -2206, -2206, -2206, -2206,  1044, -2206,  1019, -2206, -2206, -2206,
   -2206,  1306, -2206, -2206, -2206, -2206,  1191,  1409,  1412, -2206,
   -2206,  1046, -2206,  1019, -2206, -2206, -2206, -2206,  1309, -2206,
   -2206,  1019, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
    1413,  1414,  1415,  1418,  1419,  1420,  1198, -2206,   481, -2206,
   -2206, -2206, -2206, -2206,  1048, -2206,  1019, -2206, -2206, -2206,
   -2206,  1310, -2206, -2206,  1019, -2206, -2206, -2206, -2206,  1273,
   -2206, -2206, -2206,  1421,  1422,  1019, -2206, -2206, -2206, -2206,
    1277, -2206, -2206,  1218, -2206, -2206, -2206, -2206,  1425,  1426,
   -2206, -2206,  1207, -2206, -2206,  1019, -2206, -2206, -2206, -2206,
    1282, -2206, -2206,  1269, -2206, -2206, -2206, -2206,  1270, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,   257,  1050,   566,  1272,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,  1201, -2206,  1193,  1213,
   -2206, -2206,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
   -2206,  1448, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,  1443,   153,  1444,   153,
    1445,   153,  1446,   153,  1447,   153,  1449,   153,  1455,  1450,
   -2206,  1453,  1452, -2206, -2206,  1457,  1458,  1459,  1460,  1461,
    1462,  1463,   756, -2206,  1182,  1464, -2206,  1467, -2206, -2206,
   -2206, -2206, -2206,  1182, -2206, -2206, -2206,  1182, -2206, -2206,
   -2206,  1182, -2206, -2206, -2206,  1182, -2206, -2206, -2206,  1182,
   -2206, -2206, -2206,  1465,   543,  1469,  1178, -2206,  1468,  1470,
    1471,  1472,  1473,  1474,  1475,  1476, -2206, -2206, -2206,  1211,
    1052,  1480,  1479,  1211, -2206,  1211, -2206,  1211, -2206,  1211,
   -2206,  1211, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,  1195, -2206,  1237, -2206,  1239, -2206,  1240,
   -2206,  1243, -2206,   543, -2206,   543, -2206,  1010, -2206,   543,
   -2206,  1067, -2206,  1067, -2206,  1054, -2206,   543, -2206,   543,
   -2206,   543, -2206,   543, -2206, -2206,  1010, -2206,  1010, -2206,
     543,  1481, -2206,  1200,  1280, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,  1227,  1222,  1056,  1019, -2206, -2206,
   -2206, -2206,  1489, -2206,  1223,  1220,  1224,  1225,  1226,  1229,
    1232,  1212,  1233,  1234, -2206, -2206, -2206,  1497,  1058,  1498,
    1060,  1499,  1064,  1503,  1066,  1119, -2206,   543, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,  1094, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206,  1010, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,  1090, -2206,  1511,  1507,
   -2206,  1508, -2206,  1118, -2206, -2206,   543, -2206,  1116, -2206,
     543, -2206,   543, -2206,   543, -2206,  1010, -2206,  1107, -2206,
   -2206, -2206, -2206,  1280,  1512,  1068, -2206, -2206, -2206, -2206,
    1070,  1019, -2206, -2206, -2206, -2206, -2206,  1251, -2206, -2206,
   -2206,  1072, -2206, -2206, -2206,  1075, -2206, -2206, -2206,  1077,
   -2206, -2206, -2206,  1079, -2206, -2206, -2206,  1081, -2206,   393,
    1519,  1108, -2206, -2206,  1520,  1236, -2206, -2206,  1523,  1214,
   -2206, -2206,  1524,  1210, -2206, -2206, -2206,  1136,  1010,  1010,
    1010,  1010,  1010,  1010, -2206, -2206,  1010,  1010,  1010,  1010,
    1010,  1010, -2206,  1010, -2206, -2206, -2206,  1083,  1085,  1010,
   -2206,   543,   543,   543, -2206,  1165, -2206,  1527,   543,   543,
   -2206,  1133, -2206,  1130,  1129,  1128,  1010, -2206,   234,  1087,
   -2206,  1533,  1019, -2206, -2206, -2206, -2206,  1320, -2206, -2206,
   -2206, -2206, -2206,  1267, -2206,  1019, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
    1019, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206,  1535, -2206,  1536, -2206,  1537, -2206,  1538, -2206,
   -2206,  1010,  1010,  1010,  1010,  1203,  1202,   616,   782,  1204,
    1205,  1010,  1186,  1185,  1187,    31,  1184,   821,   884,   938,
    1175, -2206, -2206,  1180, -2206, -2206,  1010,    -5,  1169,  1164,
    1167, -2206, -2206, -2206,  1170, -2206,  1161, -2206, -2206, -2206,
   -2206, -2206,  1010, -2206, -2206, -2206, -2206, -2206,  1019, -2206,
   -2206, -2206, -2206,  1549, -2206,  1263,  1047, -2206,  1339, -2206,
    1288, -2206, -2206,  1289,  1291,  1344,    16, -2206,  1293,    76,
   -2206, -2206, -2206, -2206,  1242,  1244,  1245,  1247, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,  1010, -2206, -2206, -2206,
     979, -2206,  1563,  1564, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206,  1215,  1188, -2206,
    1566,  1572,  1573, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,   543,  1089,   177, -2206,  1275, -2206, -2206,
    1092, -2206, -2206,  1355, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,  1096, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,  1248, -2206, -2206,  1574,   756, -2206, -2206,
     756, -2206, -2206,  1171,  1198, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206,    19, -2206, -2206,
   -2206, -2206,  1569, -2206,  1098,     9,  1010, -2206, -2206, -2206,
   -2206,    -1, -2206,  1250,  1575,  1576,  1579,  1581,  1582, -2206,
   -2206,  1350,  1585,  1587,  1373, -2206,   756, -2206, -2206, -2206,
   -2206, -2206, -2206,  1588,  1589, -2206, -2206, -2206,  1369,  1593,
    1597, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206,   257, -2206, -2206, -2206, -2206,  1375,   -47,   756,
    1596, -2206,  1377,  1598, -2206, -2206, -2206, -2206, -2206, -2206,
    1352,  1600,  1601, -2206, -2206,  1602,  1595, -2206, -2206,   756,
    1605, -2206,  1604,  1317, -2206, -2206
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,  1578, -2206,
    1590, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,  1554,
   -2206, -2206, -2206, -2206,  1466, -2206, -2206, -2206, -2206, -2206,
    1252, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,  1209, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,  1482,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
    1104, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,  1397, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206,  1031, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206,  1307, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,   980, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206,   968, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,  1102, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,   869, -2206, -2206, -2206,
   -2206, -2206,   807, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   640,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206,   590, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,   331, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206,   334, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   604,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
     368, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,   366,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,   570, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,   305, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,   303, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206,   120, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,   651, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,   429, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,   892, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206,   816, -2206, -2206, -2206,
   -2206,  -765, -2206, -2206, -2206, -2206, -2206, -2206, -2206,  -138,
   -2206, -2206, -2206, -1080, -2206, -2206, -2206, -2206, -1074,  -516,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206,  -692, -2206, -2206,
   -2206,  -237, -2206, -2206, -2206,  -599, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,   529, -2206,  -986, -1066,   596,   322,   578,
   -2206, -2206, -2206, -2206,  -123, -2206, -2206, -2206, -2206,  -566,
   -2206,  -868, -2206,  -368, -1333,  -202, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -1183, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -1320, -2206,
   -2206,   125,  -714, -2206,  -713, -2206, -2206, -2206, -2206, -2206,
    -751, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,  -786, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -1341, -2206, -2206,
   -2206, -2206, -2206, -1337, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206,  -438, -2206, -1206, -2206,  -640,  -774, -2205,
   -2206, -1154, -2206, -2206, -1652, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -1904, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,  -285, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206, -2206,
   -2206, -2206, -2206, -2206, -2206, -2206
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     288,   671,   504,   739,  1178,  2348,  2349,   254,  1167,  2459,
    1315,   619,   507,   384,   804,   389,  1024,   509,  1186,  1204,
     398,     6,  1578,  2444,   256,  1198,  1199,   151,   152,  2005,
     763,  2007,  1447,  1448,  1316,  2066,   933,  1242,   486,   541,
     367,  2330,  2331,  2076,  2350,  2078,   489,  2080,   285,  2082,
    1090,  1247,   270,  1261,   151,   152,  2088,   404,   405,  1133,
     768,   769,  1686,  1687,   538,   710,   615,   616,   763,   282,
    1351,  1486,  1487,   492,   493,   544,  1123,   276,   151,   152,
     726,   727,  1134,  1135,   670,  1523,   151,   152,  1094,  1157,
     615,   616,   273,  1526,  1527,  1218,  1410,  1164,  1373,  1329,
    1516,  1258,  1192,  2147,   747,   728,   729,   151,   152,   547,
     375,   982,   383,   528,   388,   802,   366,   372,   373,  1556,
    1263,  1557,  1558,   995,   802,  1556,  1400,  1557,  1558,  1264,
     728,   729,   151,   152,  1330,  1252,   279,   151,   152,   728,
     729,   151,   152,   480,   615,   616,   267,   550,   709,   615,
     616,   814,   150,  1589,   625,     7,   764,   483,   878,   151,
     152,   750,  1444,  1556,   529,  1557,  1558,    17,  2423,  1280,
     641,   406,  2181,   548,   751,    12,  2183,   642,  2184,  2487,
    2185,   277,  1025,    14,  1476,   542,   271,   746,   529,  1517,
      30,   648,   368,  1626,   764,   518,   650,   477,   487,  1606,
      80,   652,   490,  1422,  1308,   545,   286,   494,   539,   283,
    1317,  1514,   770,   983,   479,    41,  1187,   523,  1265,  1219,
     407,  1582,  1583,  1331,   274,  2231,  2465,   153,   154,   534,
     535,   536,   537,  2351,   563,   481,   568,  1559,   573,  1579,
    2445,  2380,   996,   551,   280,   484,  1413,  1293,  2488,  1624,
     604,   605,   604,   605,  2453,  1554,   268,   604,   605,  2454,
    1418,   815,  1064,   806,  1344,   553,  1095,  2268,  2269,  2270,
     118,  1065,  1563,  1095,  2274,  2276,   604,   605,   153,   154,
    1208,  1453,  2332,  2333,   604,   605,  1106,  1575,  1611,  2460,
    1612,   823,  1366,  2381,  1613,  1587,   604,   605,  1421,  1614,
    1615,  2385,  1294,   593,  2084,  1616,  2086,   153,   154,   202,
    1492,  1591,  1095,   604,   605,  1076,   302,   148,   604,   605,
    1393,   420,   604,   605,   421,  1603,   604,   605,   126,  1095,
     604,   605,    49,   562,  1095,   567,  1295,   572,  1095,   604,
     605,  1422,  1095,   127,   219,   128,   220,   129,   303,   130,
     205,  1628,  1113,  2386,  1532,   512,  1437,   206,   513,   153,
     154,   824,   825,   586,   826,  1640,   587,   655,  1209,  1210,
     656,  1211,  1463,   218,   304,    50,   221,   817,  1469,  1149,
     818,    51,   305,   207,   607,    52,  1652,    53,   989,   618,
     222,   990,  1180,   131,   824,   825,   306,   826,   307,    54,
    2175,  1502,  1845,   208,   219,  1507,   220,     1,     2,    55,
     223,    56,   308,   209,  1669,  1612,   224,    57,   309,  1613,
     310,  2352,   311,   132,   312,  1244,    20,    21,   210,   688,
     689,   690,   691,   240,  2186,    58,   221,   259,   692,   399,
     400,   401,   402,   151,   152,  1542,   260,   681,   294,  1547,
     222,  1702,  1109,   372,   373,   296,  1846,  1847,   740,  2403,
      25,    26,   669,  1710,   682,  2283,   683,   295,  2284,   297,
     223,   712,  1150,   713,   714,   298,   224,    33,    34,   723,
    1721,  1568,  2409,  2410,   338,  1181,   370,   127,  1724,   128,
    1764,   129,   380,   130,    44,    45,  2241,  2242,  2243,  2244,
    2245,  2246,   121,   122,  2249,  2250,  2251,  2252,  2253,  2254,
     385,  2256,  1893,  1741,   167,   168,  1895,  2266,  1245,  1596,
    1897,  1744,   766,   767,  1899,  1765,   708,   390,  1901,   397,
    1099,   412,  1749,   431,  2282,  1108,   414,   131,   432,  1766,
     413,  1767,   416,  1768,   433,  1769,   415,   775,  1770,   434,
    1133,   417,  1760,   926,  1771,  1144,  1984,   738,  1986,  1633,
    1988,   418,  1990,   794,  1992,   745,  1168,   132,  1179,   151,
     152,   796,   440,  1134,  1135,  1136,  1137,  1205,   172,   173,
    1645,   615,   616,   419,   762,  1209,  1210,   467,  1211,  2314,
    2315,  2316,  2317,   177,   178,  2321,  2323,   182,   183,  2326,
     833,  1243,   187,   188,   502,  2340,  2342,  2344,  1662,   840,
     505,  1262,   510,  1855,  2347,  1859,   519,  1863,   420,  1867,
     407,  1871,   762,  1679,   524,   955,   581,  1133,   192,   193,
    2363,   197,   198,   559,  1416,   862,   564,   301,   213,   214,
     302,   805,   242,   243,   569,  1695,   151,   152,  1234,  1235,
    1134,  1135,   574,   880,   151,   152,   582,   889,   615,   616,
     261,   262,   583,  1133,   585,  1856,   900,  1860,   592,  1864,
     584,  1868,   303,  1872,  2393,   289,   290,   905,  2395,   340,
     341,   594,   151,   152,   345,   346,  1134,  1135,   350,   351,
    1174,  1175,   595,   921,   615,   616,   355,   356,   304,   360,
     361,    50,   597,   934,   512,  1904,   305,    51,   940,   596,
    1905,    52,   877,    53,   950,  1906,   631,  1611,   624,  1612,
     306,   632,   307,  1613,   964,    54,  1206,  1417,  1614,  1615,
     392,   393,   426,   427,  1616,    55,   308,    56,   442,   443,
     447,   448,   309,    57,   310,   998,   311,   636,   312,   452,
     453,   457,   458,  1010,   462,   463,   497,   498,   633,  1462,
     635,    58,   492,   493,   554,   555,   634,   604,   605,   153,
     154,   576,   577,   637,  2458,   601,   602,   612,   613,  1043,
     665,   666,   704,   705,   638,  1907,  1047,  1908,  1501,  1909,
     639,  1910,   640,  1911,  2106,  1912,  1292,  1913,   653,  1914,
     586,  1915,   661,  1916,  2230,  1917,   672,  1918,   673,  1919,
    1415,  1920,   674,  1921,   675,  1922,   715,   716,   741,   742,
     676,  1079,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,
    1800,  1801,  1541,   783,   784,   788,   789,   797,   798,  1454,
     841,   842,   863,   864,   604,   605,   153,   154,   873,   874,
    1111,   884,   885,   890,   891,  1904,   935,   936,   941,   942,
    1905,  1124,   959,   960,   679,  1906,   965,   966,  1493,   971,
     972,   976,   977,   693,  1158,   999,  1000,  1005,  1006,   696,
     604,   605,   153,   154,  1011,  1012,  1037,  1038,  1100,  1101,
    1352,  1128,  1129,  1207,   641,  1159,  1160,  1169,  1170,  1193,
    1194,  1224,  1225,  1229,  1230,  1253,  1254,  1281,  1282,  1309,
    1310,  1223,  1533,  1107,  1345,  1346,  1367,  1368,  2202,  1394,
    1395,  1405,  1406,  1438,  1439,  1455,  1456,  1470,  1471,  1479,
    1480,  1273,   699,  1139,   697,  1907,   698,  1908,   700,  1909,
     655,  1910,   720,  1911,   724,  1912,  1177,  1913,   711,  1914,
     725,  1915,   748,  1916,  2009,  1917,  2010,  1918,  2011,  1919,
    2012,  1920,  2013,  1921,  2014,  1922,  2015,  2320,  2016,   749,
    2017,   756,  2018,   765,  2019,   773,  2020,   774,  2021,  1241,
    2022,   776,  2023,   780,  2024,   751,  2025,   795,  2026,   808,
    2027,   811,  2028,   834,  2029,   837,  2030,   846,  2031,   847,
    2032,   818,  2033,   851,  2034,   855,  2035,  1494,  1495,  2294,
    1678,  1508,  1509,    81,   853,    82,    83,    84,   856,    85,
      86,    87,  2302,    88,    89,    90,   859,    91,    92,    93,
     868,    94,    95,  1534,  1535,  1548,  1549,  2307,  1569,  1570,
    1582,  1583,  1597,  1598,  1634,  1635,  1646,  1647,  1663,  1664,
    1671,  1672,  1696,  1697,  1704,  1705,  1715,  1716,  1735,  1736,
    1789,  1790,  1977,  1978,  2073,  2074,  2101,  2102,  2131,  2132,
    2135,  2136,  1360,  1361,  2139,  2140,  2143,  2144,  2192,  2193,
    2197,  2198,  2205,  2206,  1374,  2210,  2211,  2215,  2216,  2220,
    2221,  2225,  2226,  2260,  2261,  2263,  2264,  2288,  2289,  2404,
    2405,  1388,  2417,  2418,   879,  2366,  2426,  2427,  2448,  2449,
     881,   869,   895,   896,   901,   909,   902,   908,  1403,   910,
    2009,   916,  2010,   905,  2011,  1420,  2012,   917,  2013,   922,
    2014,   913,  2015,   926,  2016,  2322,  2017,  1432,  2018,   947,
    2019,   951,  2020,   955,  2021,   981,  2022,   923,  2023,   988,
    2024,  1023,  2025,   982,  2026,  1052,  2027,  1464,  2028,  2009,
    2029,  2010,  2030,  2011,  2031,  2012,  2032,  2013,  2033,  2014,
    2034,  2015,  2035,  2016,  1016,  2017,  1030,  2018,  1053,  2019,
     929,  2020,   952,  2021,  1019,  2022,  1033,  2023,  1412,  2024,
     989,  2025,  1056,  2026,  2339,  2027,  1059,  2028,  1063,  2029,
    1072,  2030,  1044,  2031,  1048,  2032,  1073,  2033,  1076,  2034,
    1080,  2035,  1085,  1086,  1024,  1091,  1113,  1118,  1038,  1119,
    1461,  1125,  2009,  1064,  2010,  1153,  2011,  1188,  2012,  1248,
    2013,  1274,  2014,  1275,  2015,  1276,  2016,  1286,  2017,  1287,
    2018,  1303,  2019,  1304,  2020,  1319,  2021,  1320,  2022,  1500,
    2023,  1321,  2024,  1323,  2025,  1327,  2026,  1339,  2027,  2341,
    2028,  1353,  2029,  1340,  2030,  1263,  2031,  1359,  2032,  1362,
    2033,  1375,  2034,  1377,  2035,  1381,  2009,  1382,  2010,  1294,
    2011,  1389,  2012,  1401,  2013,  1402,  2014,  1426,  2015,  1265,
    2016,  1404,  2017,  1540,  2018,  1295,  2019,  1329,  2020,  1331,
    2021,  1445,  2022,  1378,  2023,  1433,  2024,  1477,  2025,  1446,
    2026,  1465,  2027,  1478,  2028,  2343,  2029,  2009,  2030,  2010,
    2031,  2011,  2032,  2012,  2033,  2013,  2034,  2014,  2035,  2015,
    1503,  2016,  1515,  2017,  1524,  2018,  1543,  2019,  1555,  2020,
    1564,  2021,  1576,  2022,  1577,  2023,  2394,  2024,  2009,  2025,
    2010,  2026,  2011,  2027,  2012,  2028,  2013,  2029,  2014,  2030,
    2015,  2031,  2016,  2032,  2017,  2033,  2018,  2034,  2019,  2035,
    2020,  1580,  2021,  1592,  2022,  1604,  2023,  1605,  2024,  1610,
    2025,  1517,  2026,  1629,  2027,  1641,  2028,  1642,  2029,  1422,
    2030,  1653,  2031,  1643,  2032,  1654,  2033,  1655,  2034,  1656,
    2035,  1659,  1657,  1658,  1660,  1670,  1680,  1681,  1682,  1683,
    1684,  1693,  1692,  1703,  1685,  1713,  1711,  1712,  1714,  1722,
    1742,  1725,  1726,  1727,  1728,  1729,  1730,  1745,  1731,  1746,
    1747,  1750,  1751,  1752,  1753,  1755,  1761,  1762,  1763,  1831,
    1815,  1828,  1834,  1835,  1836,  1837,  1838,  1839,  1840,  1841,
    1842,  1843,  1887,  1844,  1853,  1857,  1861,  1865,  1873,  1869,
    1874,  1875,  1876,  1878,  1879,  1880,  1881,  1882,  1883,  1884,
    1892,  1677,  1891,  1903,  1885,  1961,  1965,  1962,  1966,  1967,
    1968,  1969,  1970,  1971,  1972,  1973,  1982,  1983,  1997,  2090,
    1999,  2001,  2068,  1995,  2003,  2094,  2097,  2108,  2098,  2109,
    2113,  2091,  2117,  2112,  2124,  2130,  2134,  2138,  2121,  2125,
    2116,  2142,  2146,  2176,  2177,  2174,  2120,  2178,  2179,  2180,
    2191,  2182,  2204,  2128,  2187,  2232,  2234,  2233,  1754,  2236,
    2238,  2240,  2237,  2239,  2271,  2273,  2278,  2279,  2280,  2293,
    2296,  2281,  2301,  2310,  2311,  2312,  2313,  2327,  2328,  2235,
    2318,  2319,  2329,  2359,  2345,  2338,  2358,  2368,  2360,  2324,
    2362,  2346,  2325,  2369,  2371,  2374,  2375,  2361,  2376,  2377,
    2384,  2396,  2397,  2399,  2400,  2401,  2402,  2416,  1583,  2446,
    2434,  2389,  2473,  2467,  2468,  2390,  2439,  2469,  2391,  2470,
    2471,  2474,  2392,  2475,  2476,  2481,  2479,  2480,  2398,  2482,
    2483,  2486,  2492,  2493,  2495,  2500,  2494,  2432,  2497,  2498,
    2499,  2503,  2504,  2505,   149,    40,   241,  2466,   117,   598,
     662,   441,   266,   339,   694,  1045,   701,   848,  1383,   793,
    1092,  1081,   525,   626,  1385,  1354,  1356,  1126,  1427,  1429,
    1607,  1886,  1324,  1049,   854,   777,  1246,  1110,  1419,  1152,
    1617,  2411,  2412,  2440,  2472,  2190,  2370,  2464,  2072,     0,
       0,   520,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2435,
       0,     0,  2436,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2491,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2502,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2442,  2443,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2484,  2485
};

static const yytype_int16 yycheck[] =
{
     202,   600,   370,   695,  1084,    10,    11,   145,  1082,    10,
    1193,   527,   380,   250,   779,   252,   115,   385,  1084,  1093,
       8,     0,     4,     4,   147,    10,    11,    37,    38,  1933,
     722,  1935,    10,    11,     4,  1939,   904,  1117,     6,     4,
       4,    10,    11,  1947,    49,  1949,     4,  1951,     4,  1953,
    1036,  1117,     4,  1127,    37,    38,  1960,   259,   260,    18,
       6,     7,    10,    11,     4,   664,    49,    50,   760,     4,
    1253,    10,    11,     6,     7,     4,  1062,     4,    37,    38,
      10,    11,    41,    42,   600,  1405,    37,    38,    10,  1075,
      49,    50,     4,    10,    11,   186,    55,    10,  1281,    89,
     124,    10,  1088,  2007,   703,    35,    36,    37,    38,     4,
     248,   179,   250,    66,   252,    20,   239,    47,    48,     4,
     115,     6,     7,   189,    20,     4,  1309,     6,     7,   124,
      35,    36,    37,    38,   124,  1121,     4,    37,    38,    35,
      36,    37,    38,     4,    49,    50,     4,     4,   664,    49,
      50,     4,    30,  1486,   131,   191,   722,     6,   850,    37,
      38,   132,  1345,     4,   141,     6,     7,    57,  2373,  1155,
     157,   102,  2076,    68,   145,    14,  2080,   164,  2082,   226,
    2084,   108,   281,    15,  1367,   150,   138,   703,   141,   213,
      59,   559,   156,  1526,   760,   397,   564,   335,   166,  1519,
     192,   569,   160,   227,  1190,   134,   162,   140,   148,   144,
     180,  1394,   158,   281,   337,    61,  1084,   419,   213,   310,
     151,   222,   223,   213,   136,  2129,  2431,   237,   238,   431,
     432,   433,   434,   238,   471,    96,   473,   116,   475,   221,
     221,   225,   308,   100,   112,    94,  1326,   124,   295,    90,
     235,   236,   235,   236,   245,  1438,   114,   235,   236,   250,
    1326,   114,    89,   779,  1250,   467,   251,  2171,  2172,  2173,
      63,    98,  1455,   251,  2178,  2179,   235,   236,   237,   238,
     128,  1355,   251,   252,   235,   236,  1051,  1470,   236,   290,
     238,   146,  1278,   277,   242,   180,   235,   236,   184,   247,
     248,   225,   179,   505,  1956,   253,  1958,   237,   238,    25,
    1384,  1494,   251,   235,   236,   215,    67,    58,   235,   236,
    1306,   123,   235,   236,   126,  1508,   235,   236,    60,   251,
     235,   236,    58,   471,   251,   473,   213,   475,   251,   235,
     236,   227,   251,    75,    93,    77,    95,    79,    99,    81,
       5,  1534,   311,   277,  1428,   123,  1342,     5,   126,   237,
     238,   216,   217,   123,   219,  1548,   126,   123,   216,   217,
     126,   219,  1358,    62,   125,   101,   125,   148,  1364,  1071,
     151,   107,   133,     5,   522,   111,  1569,   113,   127,   527,
     139,   130,  1084,   125,   216,   217,   147,   219,   149,   125,
    2052,  1387,   249,     5,    93,  1391,    95,    12,    13,   135,
     159,   137,   163,     5,  1597,   238,   165,   143,   169,   242,
     171,   426,   173,   155,   175,  1117,    10,    11,    65,   631,
     632,   633,   634,    60,  2086,   161,   125,     3,   640,   427,
     428,   429,   430,    37,    38,  1431,     3,    34,   194,  1435,
     139,  1634,  1051,    47,    48,   202,   303,   304,   695,  2363,
      10,    11,   600,  1646,    51,   231,    53,   198,   234,   206,
     159,   673,  1071,   675,   676,   210,   165,    10,    11,   681,
    1663,  1467,   305,   306,    62,  1084,    10,    75,  1671,    77,
     233,    79,    10,    81,    10,    11,  2148,  2149,  2150,  2151,
    2152,  2153,    10,    11,  2156,  2157,  2158,  2159,  2160,  2161,
      10,  2163,  1853,  1696,    10,    11,  1857,  2169,  1117,  1505,
    1861,  1704,   724,   725,  1865,   268,   664,    10,  1869,     6,
    1046,   114,  1715,    17,  2186,  1051,   136,   125,    22,   282,
     138,   284,   112,   286,    28,   288,   108,   749,   291,    33,
      18,   144,  1735,    21,   297,  1071,  1893,   695,  1895,  1545,
    1897,   162,  1899,   765,  1901,   703,  1082,   155,  1084,    37,
      38,   773,    64,    41,    42,    43,    44,  1093,    10,    11,
    1566,    49,    50,     6,   722,   216,   217,    31,   219,  2241,
    2242,  2243,  2244,    10,    11,  2247,  2248,    10,    11,  2251,
     802,  1117,    10,    11,   156,  2257,  2258,  2259,  1594,   811,
       3,  1127,     6,  1819,  2266,  1821,   102,  1823,   123,  1825,
     151,  1827,   760,  1609,   126,    16,    96,    18,    10,    11,
    2282,    10,    11,    10,  1326,   837,    10,    64,    10,    11,
      67,   779,    10,    11,    10,  1631,    37,    38,    39,    40,
      41,    42,    10,   855,    37,    38,    94,   859,    49,    50,
      10,    11,   166,    18,   140,  1819,   868,  1821,    80,  1823,
     160,  1825,    99,  1827,  2326,    10,    11,    32,  2330,    10,
      11,    82,    37,    38,    10,    11,    41,    42,    10,    11,
      45,    46,    78,   895,    49,    50,    10,    11,   125,    10,
      11,   101,   126,   905,   123,   312,   133,   107,   910,    76,
     317,   111,   850,   113,   916,   322,     6,   236,    66,   238,
     147,     6,   149,   242,   926,   125,  1094,  1326,   247,   248,
      10,    11,    10,    11,   253,   135,   163,   137,    10,    11,
      10,    11,   169,   143,   171,   947,   173,   150,   175,    10,
      11,    10,    11,   955,    10,    11,    10,    11,     6,  1358,
     148,   161,     6,     7,    10,    11,     6,   235,   236,   237,
     238,    10,    11,   134,  2426,    10,    11,    10,    11,   981,
      10,    11,    10,    11,    68,   392,   988,   394,  1387,   396,
     100,   398,     6,   400,  1977,   402,  1164,   404,     6,   406,
     123,   408,   126,   410,   411,   412,   152,   414,     3,   416,
    1326,   418,   124,   420,     3,   422,    10,    11,    10,    11,
      29,  1023,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,  1431,    10,    11,    10,    11,    10,    11,  1355,
      10,    11,    10,    11,   235,   236,   237,   238,    10,    11,
    1052,    10,    11,    10,    11,   312,    10,    11,    10,    11,
     317,  1063,    10,    11,    10,   322,    10,    11,  1384,    10,
      11,    10,    11,   164,  1076,    10,    11,    10,    11,   174,
     235,   236,   237,   238,    10,    11,   178,   179,    10,    11,
    1258,    10,    11,  1095,   157,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,  1113,  1428,  1051,    10,    11,    10,    11,  2101,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,  1133,   170,  1071,   176,   392,   172,   394,   126,   396,
     123,   398,   147,   400,     3,   402,  1084,   404,   124,   406,
       3,   408,   124,   410,   338,   412,   340,   414,   342,   416,
     344,   418,   346,   420,   348,   422,   350,   351,   352,     6,
     354,   113,   356,     6,   358,     3,   360,   124,   362,  1117,
     364,   132,   366,   181,   368,   145,   370,   158,   372,   117,
     374,    27,   376,    91,   378,    24,   380,   114,   382,   148,
     384,   151,   386,     5,   388,     6,   390,    10,    11,  2192,
    1609,    10,    11,   193,   146,   195,   196,   197,   307,   199,
     200,   201,  2205,   203,   204,   205,    23,   207,   208,   209,
       6,   211,   212,    10,    11,    10,    11,  2220,    10,    11,
     222,   223,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,  1274,  1275,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,  1286,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,  1303,    10,    11,   218,  2288,    10,    11,    10,    11,
     129,   280,     6,   280,   182,   142,   177,   152,  1320,    26,
     338,     6,   340,    32,   342,  1327,   344,    97,   346,   118,
     348,   309,   350,    21,   352,   353,   354,  1339,   356,   185,
     358,    92,   360,    16,   362,     6,   364,    85,   366,     6,
     368,     6,   370,   179,   372,     6,   374,  1359,   376,   338,
     378,   340,   380,   342,   382,   344,   384,   346,   386,   348,
     388,   350,   390,   352,   123,   354,   123,   356,   183,   358,
      85,   360,    85,   362,    83,   364,    83,   366,  1326,   368,
     127,   370,   123,   372,   373,   374,    83,   376,     6,   378,
      86,   380,   281,   382,   130,   384,    71,   386,   215,   388,
     281,   390,    86,    71,   115,   178,   311,    86,   179,    71,
    1358,    98,   338,    89,   340,    73,   342,    73,   344,    73,
     346,     3,   348,     3,   350,    69,   352,     6,   354,   220,
     356,     3,   358,    69,   360,   180,   362,     6,   364,  1387,
     366,     5,   368,   128,   370,     6,   372,     3,   374,   375,
     376,   124,   378,    69,   380,   115,   382,     6,   384,   109,
     386,   224,   388,    84,   390,   116,   338,   124,   340,   179,
     342,   109,   344,    84,   346,   180,   348,   124,   350,   213,
     352,   218,   354,  1431,   356,   213,   358,    89,   360,   213,
     362,    84,   364,   225,   366,   109,   368,    72,   370,    90,
     372,   153,   374,     8,   376,   377,   378,   338,   380,   340,
     382,   342,   384,   344,   386,   346,   388,   348,   390,   350,
     153,   352,    72,   354,     3,   356,   153,   358,    72,   360,
     167,   362,    74,   364,     6,   366,   367,   368,   338,   370,
     340,   372,   342,   374,   344,   376,   346,   378,   348,   380,
     350,   382,   352,   384,   354,   386,   356,   388,   358,   390,
     360,    10,   362,   167,   364,    74,   366,   124,   368,     8,
     370,   213,   372,   167,   374,    74,   376,   116,   378,   227,
     380,    70,   382,   214,   384,     8,   386,   221,   388,     6,
     390,   180,     8,     8,   214,    70,     3,     3,     3,     8,
       8,   214,    90,    70,  1616,     6,   110,   226,     6,   110,
     110,     8,     8,     8,     6,     6,     6,   154,   230,     8,
       8,   154,   214,     8,     8,   228,   154,   168,   168,   246,
     168,   240,   229,     8,     8,     8,     8,     8,     8,     8,
       8,     3,   270,    10,    10,    10,    10,    10,     3,    10,
      10,     8,    10,     6,     6,     6,     6,     6,     6,     6,
       3,  1609,     8,     8,  1842,     6,     8,   299,     8,     8,
       8,     8,     8,     8,     8,   274,     6,     8,   251,     8,
     251,   251,   425,   298,   251,   215,   269,     8,   276,   276,
     276,   301,   276,   283,   292,     8,     8,     8,   276,   276,
     285,     8,   393,   423,     3,   421,   287,    10,    10,   401,
       8,   405,   271,   289,   417,     6,     6,   419,  1730,     6,
       6,   395,   318,   323,   369,     8,   403,   407,   409,     6,
     220,   413,   275,     8,     8,     8,     8,   361,   363,   313,
     347,   349,   365,   389,   379,   371,   387,     8,   391,   355,
     399,   381,   357,   300,   225,   277,   277,   397,   277,   225,
     277,     8,     8,   385,     8,     3,     3,   302,   223,    10,
       6,   339,   232,     8,     8,   341,   415,     8,   343,     8,
       8,     6,   345,     6,   221,   226,     8,     8,   383,     6,
       3,   226,     6,   226,   252,    10,     8,   359,     8,     8,
       8,     6,     8,   296,    60,    25,   134,   367,    40,   515,
     589,   314,   156,   226,   644,   985,   658,   820,  1297,   760,
    1040,  1027,   423,   531,  1300,  1267,  1270,  1067,  1333,  1336,
    1520,  1843,  1213,   992,   828,   753,  1117,  1051,  1326,  1071,
    1525,  2365,  2365,  2404,  2440,  2093,  2296,  2431,  1943,    -1,
      -1,   409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2397,
      -1,    -1,  2400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2446,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2409,  2410,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2474,  2475
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   432,   433,   434,     0,   191,   441,   442,
    1249,  1250,    14,   435,    15,   439,   440,    57,   443,   444,
      10,    11,  1251,  1252,  1253,    10,    11,   436,   437,   438,
      59,   523,   524,    10,    11,   445,   446,   447,  1254,  1255,
     441,    61,   577,   578,    10,    11,   525,   526,   527,    58,
     101,   107,   111,   113,   125,   135,   137,   143,   161,   448,
     449,   450,   451,   452,   467,   468,   473,   474,   479,   480,
     485,   486,   491,   492,   497,   498,   503,   504,   509,   510,
     192,   193,   195,   196,   197,   199,   200,   201,   203,   204,
     205,   207,   208,   209,   211,   212,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,  1273,  1274,  1275,  1276,   439,    63,   629,
     630,    10,    11,   579,   580,   581,    60,    75,    77,    79,
      81,   125,   155,   528,   529,   530,   531,   532,   537,   538,
     544,   545,   551,   552,   558,   559,   563,   564,    58,   450,
      30,    37,    38,   237,   238,   453,   454,   455,  1190,  1191,
    1192,  1193,  1208,  1209,  1210,  1211,  1240,    10,    11,   469,
     470,   471,    10,    11,   475,   476,   477,    10,    11,   481,
     482,   483,    10,    11,   487,   488,   489,    10,    11,   493,
     494,   495,    10,    11,   499,   500,   501,    10,    11,   505,
     506,   507,    25,   511,  1235,     5,     5,     5,     5,     5,
      65,   724,   725,    10,    11,   631,   632,   633,    62,    93,
      95,   125,   139,   159,   165,   582,   583,   584,   585,   586,
     591,   592,   597,   598,   603,   604,   609,   610,   615,   616,
      60,   530,    10,    11,   533,   534,   535,   539,   540,   546,
     547,   553,   554,   560,  1190,   565,  1235,  1246,  1247,     3,
       3,    10,    11,   456,   457,   458,   455,     4,   114,   472,
       4,   138,   478,     4,   136,   484,     4,   108,   490,     4,
     112,   496,     4,   144,   502,     4,   162,   508,  1246,    10,
      11,   512,   513,   514,   194,   198,   202,   206,   210,   726,
     727,    64,    67,    99,   125,   133,   147,   149,   163,   169,
     171,   173,   175,   634,   635,   636,   637,   638,   643,   644,
     649,   650,   655,   656,   661,   662,   667,   668,   684,   685,
     691,   692,   698,   699,   705,   706,   710,   711,    62,   584,
      10,    11,   587,   588,   589,    10,    11,   593,   594,   595,
      10,    11,   599,   600,   601,    10,    11,   605,   606,   607,
      10,    11,   611,   612,   613,   617,  1235,     4,   156,   536,
      10,   542,    47,    48,   541,  1190,  1212,  1213,  1214,  1215,
      10,   549,   548,  1190,  1212,    10,   556,   555,  1190,  1212,
      10,   561,    10,    11,   566,   567,   568,     6,     8,   427,
     428,   429,   430,  1248,  1246,  1246,   102,   151,   459,   460,
     461,   462,   114,   138,   136,   108,   112,   144,   162,     6,
     123,   126,   515,   516,   517,   518,    10,    11,   729,   730,
     731,    17,    22,    28,    33,   728,  1225,  1231,  1238,  1243,
      64,   636,    10,    11,   639,   640,   641,    10,    11,   645,
     646,   647,    10,    11,   651,   652,   653,    10,    11,   657,
     658,   659,    10,    11,   663,   664,   665,    31,   669,  1241,
     686,   687,   693,   694,   700,   701,   707,  1190,   712,  1235,
       4,    96,   590,     6,    94,   596,     6,   166,   602,     4,
     160,   608,     6,     7,   140,   614,  1244,    10,    11,   618,
     619,   620,   156,   543,  1244,     3,   550,  1244,   557,  1244,
       6,   562,   123,   126,   569,   570,   571,   572,  1246,   102,
     461,   463,   464,  1246,   126,   517,   519,   520,    66,   141,
     732,   733,   734,   735,  1246,  1246,  1246,  1246,     4,   148,
     642,     4,   150,   648,     4,   134,   654,     4,    68,   660,
       4,   100,   666,  1246,    10,    11,   670,   671,   672,    10,
     689,   688,  1190,  1212,    10,   696,   695,  1190,  1212,    10,
     703,   702,  1190,  1212,    10,   708,    10,    11,   713,   714,
     715,    96,    94,   166,   160,   140,   123,   126,   621,   622,
     623,   624,    80,  1246,    82,    78,    76,   126,   571,   573,
     574,    10,    11,   466,   235,   236,   465,  1190,  1200,  1201,
    1202,  1203,    10,    11,   522,    49,    50,   521,  1190,  1200,
    1216,  1217,  1218,  1219,    66,   131,   734,  1159,  1160,   736,
     737,     6,     6,     6,     6,   148,   150,   134,    68,   100,
       6,   157,   164,   673,   674,   675,   676,   690,  1244,   697,
    1244,   704,  1244,     6,   709,   123,   126,   716,   717,   718,
     719,   126,   623,   625,   626,    10,    11,   576,   575,  1190,
    1200,  1216,   152,     3,   124,     3,    29,  1161,  1239,    10,
     742,    34,    51,    53,   738,   739,   740,   741,  1246,  1246,
    1246,  1246,  1246,   164,   675,   677,   174,   176,   172,   170,
     126,   718,   720,   721,    10,    11,   628,   627,  1190,  1200,
    1216,   124,  1246,  1246,  1246,    10,    11,  1162,  1163,  1164,
     147,   743,   744,  1246,     3,     3,    10,    11,    35,    36,
     678,   679,   680,   681,  1182,  1183,  1184,  1185,  1190,  1208,
    1212,    10,    11,   723,   722,  1190,  1200,  1216,   124,     6,
     132,   145,  1165,  1166,  1167,  1168,   113,   759,   760,   745,
     746,   747,  1190,  1208,  1240,     6,  1246,  1246,     6,     7,
     158,   682,   683,     3,   124,  1246,   132,  1167,  1169,  1170,
     181,   765,   766,    10,    11,   761,   762,   763,    10,    11,
     748,   749,   750,   747,  1246,   158,  1246,    10,    11,  1172,
    1173,  1174,    20,  1171,  1182,  1190,  1200,  1228,   117,   885,
     886,    27,   767,  1237,     4,   114,   764,   148,   151,   751,
     752,   753,   754,   146,   216,   217,   219,  1175,  1176,  1177,
    1178,  1179,  1180,  1246,    91,   989,   990,    24,   887,  1234,
    1246,    10,    11,   768,   769,   770,   114,   148,   753,   755,
     756,     5,  1181,   146,  1177,     6,   307,  1093,  1094,    23,
     991,  1232,  1246,    10,    11,   888,   889,   890,     6,   280,
     771,   772,   773,    10,    11,   758,   757,  1190,  1208,   218,
    1246,   129,  1136,  1137,    10,    11,  1095,  1096,  1097,  1246,
      10,    11,   992,   993,   994,     6,   280,   891,   892,   893,
    1246,   182,   177,   785,   786,    32,   774,  1242,   152,   142,
      26,  1138,  1236,   309,  1098,  1099,     6,    97,   995,   996,
     997,  1246,   118,    85,   905,   906,    21,   894,  1230,    85,
     801,   802,   787,  1242,  1246,    10,    11,   775,   776,   777,
    1246,    10,    11,  1139,  1140,  1141,  1134,   185,  1100,  1233,
    1246,    92,    85,  1009,  1010,    16,   998,  1224,   960,    10,
      11,   907,   908,   909,  1246,    10,    11,   895,   896,   897,
     856,    10,    11,   803,   804,   805,    10,    11,   788,   789,
     790,     6,   179,   281,   778,   779,   780,   781,     6,   127,
     130,  1142,  1143,  1144,  1145,   189,   308,  1135,  1246,    10,
      11,  1101,  1102,  1103,  1064,    10,    11,  1011,  1012,  1013,
    1246,    10,    11,   999,  1000,  1001,   123,   961,   962,    83,
     910,   911,   912,     6,   115,   281,   898,   899,   900,   901,
     123,   857,   858,    83,   806,   807,   808,   178,   179,   791,
     792,   793,   794,  1246,   281,   780,   782,  1246,   130,  1144,
    1146,  1147,     6,   183,  1105,  1106,   123,  1065,  1066,    83,
    1014,  1015,  1016,     6,    89,    98,  1002,  1003,  1004,  1005,
     963,   964,    86,    71,   918,   919,   215,   913,  1226,  1246,
     281,   900,   902,   859,   860,    86,    71,   814,   815,   809,
    1226,   178,   793,   795,    10,   251,   783,   784,  1199,  1200,
      10,    11,  1149,  1150,  1151,  1148,  1182,  1190,  1200,  1216,
    1228,  1246,  1113,   311,  1107,  1229,  1067,  1068,    86,    71,
    1022,  1023,  1017,  1226,  1246,    98,  1004,  1006,    10,    11,
     966,   967,   968,    18,    41,    42,    43,    44,   965,  1190,
    1194,  1195,  1196,  1197,  1200,  1204,  1205,  1206,  1207,  1208,
    1216,  1227,  1230,    73,   925,   926,   920,  1226,  1246,    10,
      11,   914,   915,   916,    10,   903,   904,  1199,  1200,    10,
      11,   862,   863,   864,    45,    46,   861,  1190,  1194,  1200,
    1208,  1216,  1220,  1221,  1222,  1223,  1227,  1242,    73,   821,
     822,   816,  1226,    10,    11,   810,   811,   812,    10,    11,
     796,   797,   798,   799,  1199,  1200,  1244,  1246,   128,   216,
     217,   219,  1152,  1153,  1154,  1155,  1156,  1157,   186,   310,
    1104,  1114,  1115,  1246,    10,    11,  1108,  1109,  1110,    10,
      11,  1070,  1071,  1072,    39,    40,  1069,  1186,  1187,  1188,
    1189,  1190,  1194,  1200,  1208,  1216,  1224,  1227,    73,  1029,
    1030,  1024,  1226,    10,    11,  1018,  1019,  1020,    10,  1007,
    1008,  1199,  1200,   115,   124,   213,   969,   970,   971,   972,
     979,   980,   981,  1246,     3,     3,    69,   932,   933,   927,
    1226,    10,    11,   921,   922,   923,     6,   220,   917,  1277,
    1278,  1285,  1244,   124,   179,   213,   865,   866,   867,   868,
     875,   876,   877,     3,    69,   828,   829,   823,  1226,    10,
      11,   817,   818,   819,   813,  1277,     4,   180,   800,   180,
       6,     5,  1158,   128,  1154,  1116,  1117,     6,  1112,    89,
     124,   213,  1073,  1074,  1075,  1076,  1083,  1084,  1085,     3,
      69,  1036,  1037,  1031,  1226,    10,    11,  1025,  1026,  1027,
    1021,  1277,  1244,   124,   971,   973,   980,   982,   983,     6,
    1246,  1246,   109,   939,   940,   934,  1226,    10,    11,   928,
     929,   930,   924,  1277,  1246,   224,  1488,    84,   225,  1279,
    1280,   116,   124,   867,   869,   876,   878,   879,  1246,   109,
     835,   836,   830,  1226,    10,    11,   824,   825,   826,   820,
    1277,    84,   180,  1246,   218,    10,    11,  1119,  1120,  1121,
      55,  1118,  1190,  1194,  1198,  1200,  1208,  1216,  1227,  1229,
    1246,   184,   227,  1111,  1299,  1301,   124,  1075,  1077,  1084,
    1086,  1087,  1246,   109,  1043,  1044,  1038,  1226,    10,    11,
    1032,  1033,  1034,  1028,  1277,    84,    90,    10,    11,   974,
     975,   976,   977,  1199,  1200,    10,    11,   985,   986,   987,
     984,  1190,  1216,  1226,  1246,   153,   946,   947,   941,  1226,
      10,    11,   935,   936,   937,   931,  1277,    72,     8,    10,
      11,  1286,  1287,  1288,  1281,  1282,    10,    11,   870,   871,
     872,   873,  1199,  1200,    10,    11,   881,   882,   883,   880,
    1190,  1216,  1226,   153,   842,   843,   837,  1226,    10,    11,
     831,   832,   833,   827,  1277,    72,   124,   213,  1122,  1123,
    1124,  1125,  1126,  1299,     3,  1300,    10,    11,  1078,  1079,
    1080,  1081,  1199,  1200,    10,    11,  1089,  1090,  1091,  1088,
    1190,  1216,  1226,   153,  1050,  1051,  1045,  1226,    10,    11,
    1039,  1040,  1041,  1035,  1277,    72,     4,     6,     7,   116,
     978,  1245,   988,  1277,   167,   953,   954,   948,  1226,    10,
      11,   942,   943,   944,   938,  1277,    74,     6,     4,   221,
      10,  1284,   222,   223,  1283,  1489,  1490,   180,   874,  1245,
     884,  1277,   167,   849,   850,   844,  1226,    10,    11,   838,
     839,   840,   834,  1277,    74,   124,  1299,  1125,  1127,  1128,
       8,   236,   238,   242,   247,   248,   253,  1302,  1303,  1304,
    1305,  1306,  1483,  1485,    90,  1082,  1245,  1092,  1277,   167,
    1057,  1058,  1052,  1226,    10,    11,  1046,  1047,  1048,  1042,
    1277,    74,   116,   214,   955,  1226,    10,    11,   949,   950,
     951,   945,  1277,    70,     8,   221,     6,     8,     8,   180,
     214,   851,  1226,    10,    11,   845,   846,   847,   841,  1277,
      70,    10,    11,  1130,  1131,  1132,  1129,  1190,  1216,  1226,
       3,     3,     3,     8,     8,  1246,    10,    11,  1302,  1307,
    1308,  1309,    90,   214,  1059,  1226,    10,    11,  1053,  1054,
    1055,  1049,  1277,    70,    10,    11,   956,   957,   958,   952,
    1277,   110,   226,     6,     6,    10,    11,   852,   853,   854,
     848,  1277,   110,  1133,  1277,     8,     8,     8,     6,     6,
       6,   230,  1310,  1311,  1312,    10,    11,  1060,  1061,  1062,
    1056,  1277,   110,   959,  1277,   154,     8,     8,   855,  1277,
     154,   214,     8,     8,  1246,   228,  1329,  1313,  1314,  1063,
    1277,   154,   168,   168,   233,   268,   282,   284,   286,   288,
     291,   297,  1330,  1331,  1332,  1356,  1357,  1369,  1370,  1397,
    1398,  1415,  1416,  1428,  1429,  1447,  1448,  1451,  1452,    10,
      11,  1328,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,  1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,
    1323,  1324,  1325,  1326,  1327,   168,  1333,  1334,  1358,  1359,
    1371,  1372,  1399,  1400,  1417,  1418,  1430,  1431,   240,  1449,
    1491,   246,  1453,  1482,   229,     8,     8,     8,     8,     8,
       8,     8,     8,     3,    10,   249,   303,   304,  1335,  1486,
    1492,  1493,  1494,    10,  1360,  1486,  1492,    10,  1373,  1486,
    1492,    10,  1401,  1486,  1492,    10,  1419,  1486,  1492,    10,
    1432,  1486,  1492,     3,    10,     8,    10,  1454,     6,     6,
       6,     6,     6,     6,     6,  1244,  1246,   270,  1336,  1338,
    1339,     8,     3,  1338,  1361,  1338,  1374,  1338,  1402,  1338,
    1420,  1338,  1433,     8,   312,   317,   322,   392,   394,   396,
     398,   400,   402,   404,   406,   408,   410,   412,   414,   416,
     418,   420,   422,  1572,  1573,  1574,  1577,  1578,  1581,  1582,
    1585,  1586,  1589,  1590,  1592,  1593,  1595,  1596,  1598,  1599,
    1601,  1602,  1605,  1606,  1610,  1611,  1613,  1614,  1616,  1617,
    1619,  1620,  1622,  1623,  1625,  1628,  1629,  1631,  1632,  1634,
    1635,     6,   299,  1456,  1457,     8,     8,     8,     8,     8,
       8,     8,     8,   274,  1337,  1344,  1345,    10,    11,  1340,
    1341,  1342,     6,     8,  1344,  1362,  1344,  1375,  1344,  1403,
    1344,  1421,  1344,  1434,  1626,   298,  1450,   251,  1576,   251,
    1580,   251,  1584,   251,  1588,  1572,  1591,  1572,  1594,   338,
     340,   342,   344,   346,   348,   350,   352,   354,   356,   358,
     360,   362,   364,   366,   368,   370,   372,   374,   376,   378,
     380,   382,   384,   386,   388,   390,  1495,  1496,  1499,  1502,
    1504,  1506,  1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,
    1524,  1526,  1527,  1529,  1531,  1533,  1535,  1537,  1539,  1549,
    1557,  1560,  1563,  1566,  1569,  1597,  1572,  1600,   425,  1603,
    1609,  1607,  1609,    10,    11,  1612,  1572,  1615,  1572,  1618,
    1572,  1621,  1572,  1624,  1495,  1630,  1495,  1633,  1572,  1636,
       8,   301,  1463,  1464,   215,  1458,  1484,   269,   276,  1350,
    1351,    10,    11,  1346,  1347,  1348,  1277,  1343,     8,   276,
    1363,  1364,   283,   276,  1376,  1377,   285,   276,  1404,  1405,
     287,   276,  1422,  1423,   292,   276,  1435,  1436,   289,  1627,
       8,    10,    11,  1575,     8,    10,    11,  1579,     8,    10,
      11,  1583,     8,    10,    11,  1587,   393,  1572,  1513,  1505,
    1507,  1511,  1515,  1517,  1558,  1570,  1525,  1509,  1532,  1519,
    1521,  1523,  1550,  1530,  1564,  1561,  1567,  1497,  1500,  1503,
    1540,  1534,  1536,  1538,   421,  1495,   423,     3,    10,    10,
     401,  1572,   405,  1572,  1572,  1572,  1495,   417,  1470,  1465,
    1484,     8,    10,    11,  1459,  1460,  1461,    10,    11,  1352,
    1353,  1354,  1277,  1349,   271,    10,    11,  1365,  1366,  1367,
      10,    11,  1378,  1379,  1380,    10,    11,  1406,  1407,  1408,
      10,    11,  1424,  1425,  1426,    10,    11,  1437,  1438,  1439,
     411,  1572,     6,   419,     6,   313,     6,   318,     6,   323,
     395,  1495,  1495,  1495,  1495,  1495,  1495,  1559,  1571,  1495,
    1495,  1495,  1495,  1495,  1495,  1553,  1495,  1565,  1562,  1568,
      10,    11,  1498,    10,    11,  1501,  1495,  1542,  1572,  1572,
    1572,   369,  1528,     8,  1572,  1604,  1572,  1608,   403,   407,
     409,   413,  1495,   231,   234,  1455,  1471,  1472,    10,    11,
    1466,  1467,  1468,     6,  1277,  1462,   220,  1289,  1290,  1295,
    1355,   275,  1277,  1368,  1381,  1382,  1409,  1277,  1427,  1440,
       8,     8,     8,     8,  1495,  1495,  1495,  1495,   347,   349,
     351,  1495,   353,  1495,   355,   357,  1495,   361,   363,   365,
      10,    11,   251,   252,  1551,  1554,  1555,  1556,   371,   373,
    1495,   375,  1495,   377,  1495,   379,   381,  1495,    10,    11,
      49,   238,   426,  1541,  1543,  1544,  1546,  1548,   387,   389,
     391,   397,   399,  1495,  1473,  1474,  1277,  1469,     8,   300,
    1488,   225,  1291,  1292,   277,   277,   277,   225,  1383,  1384,
     225,   277,  1410,  1411,   277,   225,   277,  1441,  1442,   339,
     341,   343,   345,  1495,   367,  1495,     8,     8,   383,   385,
       8,     3,     3,  1572,    10,    11,  1478,  1479,  1480,   305,
     306,  1303,  1305,  1475,  1476,  1477,   302,    10,    11,  1296,
    1297,  1298,  1293,  1490,  1385,  1386,    10,    11,  1412,  1413,
    1414,  1443,   359,  1552,     6,  1244,  1244,  1545,  1547,   415,
    1311,  1481,  1246,  1246,     4,   221,    10,  1294,    10,    11,
    1389,  1390,  1391,   245,   250,  1387,  1388,  1487,  1495,    10,
     290,  1444,  1445,  1446,  1489,  1490,   367,     8,     8,     8,
       8,     8,  1329,   232,     6,     6,   221,  1244,  1392,     8,
       8,   226,     6,     3,  1246,  1246,   226,   226,   295,  1393,
    1394,  1244,     6,   226,     8,   252,  1395,     8,     8,     8,
      10,  1396,  1244,     6,     8,   296
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
    parserData->valueAttributePresent = false;    
    parserData->typeAttributePresent = false;
    parserData->varTypeAttributePresent = false;
    parserData->descriptionAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->typeAttribute = "";
    parserData->varTypeAttribute = "";
    parserData->descriptionAttribute = "";    
    osglData->numberOfEnumerationsAttributePresent = false;    
    osglData->enumTypeAttributePresent = false;
    osglData->enumTypeAttribute = "";
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
        if (osglData->numberOfEnumerationsAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
        osglData->numberOfEnumerationsAttributePresent = true;
         if (osresult->setOtherVariableResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfEnumerations) == false)
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
                                                  osglData->enumTypeAttribute) == false)
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
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, parserData->valueAttribute, 
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
    parserData->valueAttributePresent = false;
    parserData->typeAttributePresent = false;
    parserData->objTypeAttributePresent = false;
    parserData->descriptionAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->typeAttribute = "";
    parserData->objTypeAttribute = "";
    parserData->descriptionAttribute = "";
    osglData->numberOfEnumerationsAttributePresent = false;    
    osglData->enumTypeAttributePresent = false;
    osglData->enumTypeAttribute = "";
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
        if (osglData->numberOfEnumerationsAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
        osglData->numberOfEnumerationsAttributePresent = true;
         if (osresult->setOtherObjectiveResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfEnumerations) == false)
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
                                                  osglData->enumTypeAttribute) == false)
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
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_objectives, parserData->kounter, parserData->valueAttribute, 
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
    parserData->valueAttributePresent = false;    
    parserData->typeAttributePresent = false;
    parserData->conTypeAttributePresent = false;
    parserData->descriptionAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->typeAttribute = "";
    parserData->conTypeAttribute = "";
    parserData->descriptionAttribute = "";
    osglData->numberOfEnumerationsAttributePresent = false;    
    osglData->enumTypeAttributePresent = false;
    osglData->enumTypeAttribute = "";
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
        if (osglData->numberOfEnumerationsAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
        osglData->numberOfEnumerationsAttributePresent = true;
         if (osresult->setOtherConstraintResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfEnumerations) == false)
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
                                                  osglData->enumTypeAttribute) == false)
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
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_constraints, parserData->kounter, parserData->valueAttribute, 
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
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming
        = new MatrixProgrammingSolution();
}
    break;

  case 989:

    {  
        if (parserData->kounter < osglData->numberOfMatrixVar)  
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "actual number of matrixVar less than number attribute");   
    }
    break;

  case 990:

    {
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
        = new MatrixVariableSolution(); 
}
    break;

  case 991:

    {
    parserData->numberOfOtherMatrixVariableResults = parserData->tempInt;
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
        ->numberOfOtherMatrixVariableResults = parserData->tempInt;
    parserData->iOther = 0;
}
    break;

  case 999:

    {
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables->values
        = new MatrixVariableValues(); 
}
    break;

  case 1000:

    {
    osglData->numberOfMatrixVar = parserData->tempInt;
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables->values
        ->numberOfMatrixVar = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 1010:

    {      
        parserData->iOther++;
    }
    break;

  case 1011:

    {
    if (parserData->iOther >= parserData->numberOfOtherMatrixVariableResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherMatrixVariableResults> than specified");
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->typeAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    //solver
    //category 
    parserData->numberOfVarAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->typeAttribute = "";
    parserData->descriptionAttribute = "";    
    osglData->numberOfEnumerationsAttributePresent = false;    
    osglData->osglMatrixVarTypeAttributePresent = false;
    osglData->enumTypeAttributePresent = false;
    osglData->osglMatrixVarTypeAttribute = "";
    osglData->enumTypeAttribute = "";
}
    break;

  case 1012:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, 
                "<other> element requires name attribute"); 
    }
    break;

  case 1015:

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

  case 1016:

    {
        if (osglData->numberOfEnumerationsAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
        osglData->numberOfEnumerationsAttributePresent = true;
         if (osresult->setOtherVariableResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }
    break;

  case 1017:

    {    
         if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
                                                   parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultValue failed");
    }
    break;

  case 1018:

    {    
         if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultName failed");
    }
    break;

  case 1019:

    {    
         if (osresult->setOtherVariableResultType(parserData->solutionIdx, parserData->iOther, 
                                                  parserData->typeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultType failed");
    }
    break;

  case 1020:

    {    
//         if (osresult->setOtherVariableResultVarType(parserData->solutionIdx, parserData->iOther, 
//                                                  parserData->varTypeAttribute) == false)
//            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVarType failed");
    }
    break;

  case 1021:

    {    
         if (osresult->setOtherVariableResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->enumTypeAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultEnumType failed");
    }
    break;

  case 1022:

    {    
         if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                         parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultDescription failed");
    }
    break;

  case 1034:

    {     
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther, ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, parserData->valueAttribute, 
            parserData->descriptionAttribute, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other variable option failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 1035:

    {
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 1036:

    {
        if(!parserData->nameAttributePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    }
    break;

  case 1039:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 1049:

    {
    parserData->numberOf = 0; 
}
    break;

  case 1052:

    {
    parserData->numberOf = 0; 
}
    break;

  case 1053:

    {    
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherSolutionResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 1054:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <otherSolutionResult> element");
    }
    break;

  case 1055:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <otherSolutionResult> elements than specified");
    }
    break;

  case 1062:

    {
    parserData->iOther++;
}
    break;

  case 1063:

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

  case 1064:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<otherSolutionResult> element must have name attribute");
    //if (!parserData->numberOfItemsPresent)
    //    osrlerror (NULL, NULL, parserData, osglData, osnlData, "<otherSolutionResult> element must have numberOfItems attribute");
}
    break;

  case 1067:

    {    
        if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
                                                 parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultName failed");
    }
    break;

  case 1068:

    {    
        if (osresult->setOtherSolutionResultValue(parserData->solutionIdx, parserData->iOther,
                                                 parserData->valueAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultValuee failed");
    }
    break;

  case 1069:

    {    
        if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
                                                     parserData->categoryAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultCategory failed");
    }
    break;

  case 1070:

    {    
        if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, 
                                                        parserData->iOther,
                                                        parserData->descriptionAttribute) 
                                                            == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultDescription failed");
    }
    break;

  case 1071:

    {    
        if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
                                                          parserData->iOther,
                                                          parserData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 1072:

    {
        if (parserData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <item> element");
    }
    break;

  case 1073:

    {
        if (parserData->kounter != parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <item> elements than specified");
    }
    break;

  case 1080:

    {
    parserData->kounter++;
}
    break;

  case 1081:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    }
    break;

  case 1086:

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

  case 1089:

    {
    parserData->numberOf = 0; 
}
    break;

  case 1090:

    {    
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfSolverOutputs failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 1091:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <solverOutput> element");
    }
    break;

  case 1092:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <solverOutput> elements than specified");
    }
    break;

  case 1099:

    {
    parserData->iOther++;
}
    break;

  case 1100:

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

  case 1101:

    {
    if (!parserData->nameAttributePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<solverOutput> element must have name attribute");
    if (!parserData->numberOfItemsPresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<solverOutput> element must have numberOfItems attribute");
}
    break;

  case 1104:

    {    
        if (osresult->setSolverOutputName(parserData->iOther, parserData->nameAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputName failed");
    }
    break;

  case 1105:

    {    
        if (osresult->setSolverOutputCategory(parserData->iOther, 
                                              parserData->categoryAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputCategory failed");
    }
    break;

  case 1106:

    {    
        if (osresult->setSolverOutputDescription(parserData->iOther, 
                                                 parserData->descriptionAttribute) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputDescription failed");
    }
    break;

  case 1107:

    {    
        if (osresult->setSolverOutputNumberOfItems(parserData->iOther, 
                                                   parserData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 1108:

    {
        if (parserData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <item> element");
    }
    break;

  case 1109:

    {
        if (parserData->kounter != parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <item> elements than specified");
    }
    break;

  case 1116:

    {
    parserData->kounter++;
}
    break;

  case 1117:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    }
    break;

  case 1122:

    {
    if (parserData->kounter >= parserData->numberOfItems)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
                                      parserData->itemContent) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputItem failed");
}
    break;

  case 1123:

    {
        if (parserData->categoryAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one category attribute allowed for this element");
        parserData->categoryAttributePresent = true;
    }
    break;

  case 1126:

    { 
    parserData->categoryAttribute = ""; 
}
    break;

  case 1127:

    { 
    parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1128:

    {
        if (parserData->conTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one conType attribute allowed for this element");
        parserData->conTypeAttributePresent = true;
    }
    break;

  case 1131:

    { 
    parserData->conTypeAttribute = ""; 
}
    break;

  case 1132:

    { 
    parserData->conTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1133:

    {
        if (parserData->descriptionAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one description attribute allowed for this element");
        parserData->descriptionAttributePresent = true;
    }
    break;

  case 1136:

    { 
    parserData->descriptionAttribute = ""; 
}
    break;

  case 1137:

    { 
    parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1138:

    {
        if (osglData->enumTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one enumType attribute allowed for this element");
        osglData->enumTypeAttributePresent = true;
    }
    break;

  case 1141:

    { 
    osglData->enumTypeAttribute = ""; 
}
    break;

  case 1142:

    { 
    osglData->enumTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1143:

    {
    if (osglData->osglMatrixVarTypeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
            "more than one matrixVarType attribute");
    osglData->osglMatrixVarTypeAttributePresent = true;
    osglData->osglMatrixVarTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1144:

    {    
        if (parserData->idxAttributePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute was previously set");
        parserData->idxAttributePresent = true;
        parserData->idx = (yyvsp[(3) - (4)].ival); 
    }
    break;

  case 1145:

    {
       if (parserData->nameAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one name attribute allowed for this element");
        parserData->nameAttributePresent = true;
    }
    break;

  case 1148:

    { 
    parserData->nameAttribute = ""; 
}
    break;

  case 1149:

    { 
    parserData->nameAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1150:

    {
        if (parserData->objTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one objType attribute allowed for this element");
        parserData->objTypeAttributePresent = true;
    }
    break;

  case 1153:

    { 
    parserData->objTypeAttribute = ""; 
}
    break;

  case 1154:

    { 
    parserData->objTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1155:

    {
        if (parserData->typeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one type attribute allowed for this element");
        parserData->typeAttributePresent = true;
    }
    break;

  case 1158:

    { 
    parserData->typeAttribute = ""; 
}
    break;

  case 1159:

    { 
    parserData->typeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1160:

    {
        if (parserData->unitAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one unit attribute allowed for this element");
        parserData->unitAttributePresent = true;
    }
    break;

  case 1163:

    { 
    parserData->unitAttribute = ""; 
}
    break;

  case 1164:

    { 
    parserData->unitAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1165:

    {
        if (parserData->valueAttributePresent ) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one value attribute allowed for this element");
        parserData->valueAttributePresent = true;
    }
    break;

  case 1168:

    { 
    parserData->valueAttribute = ""; 
}
    break;

  case 1169:

    { 
    parserData->valueAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1170:

    {
        if (parserData->varTypeAttributePresent ) 
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one varType attribute allowed for this element");
        parserData->varTypeAttributePresent = true;
    }
    break;

  case 1173:

    { 
    parserData->varTypeAttribute = ""; 
}
    break;

  case 1174:

    { 
    parserData->varTypeAttribute = (yyvsp[(2) - (3)].sval); free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1175:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <con> cannot be negative");
    parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1176:

    {
    if (parserData->nConPresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of constraints cannot be negative");
    parserData->nConPresent = true;        
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1177:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <el> cannot be negative");
    parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1178:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <enumeration> elements cannot be negative");
    osglData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1179:

    {    
   if (parserData->numberOfItemsPresent ) 
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one numberOfItems attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1180:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData,
        "number of <matrixVar> cannot be negative");
    osglData->numberOfMatrixVar = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1181:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1182:

    {
    if (parserData->nObjPresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of objectives cannot be negative");
    parserData->nObjPresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1183:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other constraint results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1184:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other matrix variable results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1185:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other objective results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1186:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1187:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other solution results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1188:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other variable results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1189:

    {
    if (parserData->numberAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfSolutions attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of solutions cannot be negative");
    parserData->numberAttributePresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1190:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other solver outputs cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1191:

    {
   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <substatus> elements cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1192:

    {
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1193:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <var> cannot be negative");
    parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1194:

    {
    if (parserData->nVarPresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of variables cannot be negative");
    parserData->nVarPresent = true;    
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1195:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1196:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 1197:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); }
    break;

  case 1198:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); }
    break;

  case 1199:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].dval)); }
    break;

  case 1208:

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

  case 1221:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 1226:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1227:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 1232:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1233:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 1238:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1239:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 1244:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1245:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 1250:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1251:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1256:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 1262:

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

  case 1268:

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

  case 1269:

    {
        if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1274:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
}
    break;

  case 1277:

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
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
}
    break;

  case 1283:

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

  case 1284:

    {osglData->osglMatrixVarIdxATTPresent = false;}
    break;

  case 1285:

    {
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    ((OSMatrixWithMatrixVarIdx*)osglData->matrix[osglData->matrixCounter])->matrixVarIdx
        = osglData->osglMatrixVarIdxATT;
    osglData->matrixCounter++;
}
    break;

  case 1286:

    {
std::cout << "Starting matrix " << osglData->matrixCounter;
std::cout << " out of " << osglData->numberOfMatrices << std::endl;
    if (osglData->matrixCounter >= osglData->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more matrices than specified");
    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->mtxConstructorVec.clear();
    osglData->mtxBlocksVec.clear();
    osglData->mtxBlkVec.clear();
    osglData->nBlocksVec.clear();

    /**
     *  The <matrix> tag combines the functions of the <nl> tag and the top OSnLNode,
     *  so we also initial the storage vectors here
     */
    osglData->tempC = new OSMatrix();
    osglData->mtxConstructorVec.push_back((OSMatrix*)osglData->tempC);
    osglData->mtxBlkVec.push_back((OSMatrix*)osglData->tempC);
}
    break;

  case 1287:

    {
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->osglMatrixVarIdxATTPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute matrixVarIdx is missing");    
    else
        ((OSMatrixWithMatrixVarIdx*)osglData->tempC)->matrixVarIdx = osglData->osglMatrixVarIdxATT;
    if (osglData->symmetryPresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->matrixType = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
}
    break;

  case 1296:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1297:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute in <matrix> element");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1298:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute in <matrix> element");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1299:

    {
    if (osglData->osglMatrixVarIdxATTPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarIdx attribute in <matrixVar> element");
    osglData->osglMatrixVarIdxATTPresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "<matrixVarIdx> cannot be negative");
    osglData->osglMatrixVarIdxATT = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1303:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1306:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 1307:

    {
    osglData->tempC = new BaseMatrix();
    osglData->mtxConstructorVec.push_back((BaseMatrix*)osglData->tempC);

    osglData->baseMatrixIdxPresent = false;
    osglData->targetMatrixFirstRowPresent = false;
    osglData->targetMatrixFirstColPresent = false;
    osglData->baseMatrixStartRowPresent = false;
    osglData->baseMatrixStartColPresent = false;
    osglData->baseMatrixEndRowPresent = false;
    osglData->baseMatrixEndColPresent = false;
    osglData->baseTransposePresent = false;
    osglData->scalarMultiplierPresent = false;
    osglData->baseMatrixEndRow = -1;
    osglData->baseMatrixEndCol = -1;
}
    break;

  case 1308:

    {
    if (osglData->baseMatrixIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute baseMatrixIdx is missing");
    else
    {
        ((BaseMatrix*)osglData->tempC)->baseMatrixIdx = osglData->baseMatrixIdx;
        ((BaseMatrix*)osglData->tempC)->baseMatrix = (OSMatrix*)osglData->matrix[osglData->baseMatrixIdx];
    }
    if (osglData->targetMatrixFirstRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->targetMatrixFirstRow = osglData->targetMatrixFirstRow;
    if (osglData->targetMatrixFirstColPresent == true)
        ((BaseMatrix*)osglData->tempC)->targetMatrixFirstCol = osglData->targetMatrixFirstCol;
    if (osglData->baseMatrixStartRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixStartRow = osglData->baseMatrixStartRow;
    if (osglData->baseMatrixStartColPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixStartCol = osglData->baseMatrixStartCol;
    if (osglData->baseMatrixEndRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixEndRow = osglData->baseMatrixEndRow;
    if (osglData->baseMatrixEndColPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixEndCol = osglData->baseMatrixEndCol;
    if (osglData->baseTransposePresent == true)
        ((BaseMatrix*)osglData->tempC)->baseTranspose = osglData->baseTranspose;
    if (osglData->scalarMultiplierPresent == true)
        ((BaseMatrix*)osglData->tempC)->scalarMultiplier = osglData->scalarMultiplier;
}
    break;

  case 1320:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    if ((yyvsp[(3) - (4)].ival) > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1321:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowPresent = true;   
    osglData->targetMatrixFirstRow = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1322:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColPresent = true;   
    osglData->targetMatrixFirstCol = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1323:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1324:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "baseMatrix first column cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1325:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix end row cannot be negative");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1326:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix end col cannot be negative");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1327:

    { 
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseTranspose attribute in <baseMatrix> element");
    osglData->baseTransposePresent = true;   
}
    break;

  case 1330:

    {
    osglData->baseTranspose = true;
}
    break;

  case 1331:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->baseTranspose = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->baseTranspose = true;
    else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1332:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}
    break;

  case 1336:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++;
}
    break;

  case 1346:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1347:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 1350:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_constant;
    }
    break;

  case 1351:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1355:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1356:

    {
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1362:

    {
    ((MatrixElements*)osglData->tempC)->index = new IntVector();
    ((MatrixElements*)osglData->tempC)->index->numberOfEl
        = ((MatrixElements*)osglData->tempC)->numberOfValues;
    ((MatrixElements*)osglData->tempC)->index->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1363:

    {
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1369:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->osglNumberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1370:

    {
    osglData->osglNumberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglDblArray = new double[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1377:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1378:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1381:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_varReference;
    }
    break;

  case 1382:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1386:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->osglNumberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1387:

    {
    osglData->osglNumberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1394:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1395:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 1398:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_linear;
    }
    break;

  case 1399:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1403:

    {
        if (osglData->osglNumberOfNonzeros > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1404:

    {
        if (osglData->osglNumberOfNonzeros > osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->osglNumberOfNonzeros < osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");        
        ((LinearMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->osglNumberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1405:

    {
    osglData->osglNumberOfNonzeros = ((LinearMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglNonzeroCounter = 0;
    ((LinearMatrixElements*)osglData->tempC)->value = new LinearMatrixValues();
    ((LinearMatrixElements*)osglData->tempC)->value->numberOfEl
        = ((LinearMatrixElements*)osglData->tempC)->numberOfValues;    
    ((LinearMatrixElements*)osglData->tempC)->value->el
        = new LinearMatrixElement*[((LinearMatrixElements*)osglData->tempC)->numberOfValues]; 
    for (int i=0; i < ((LinearMatrixElements*)osglData->tempC)->numberOfValues; i++)
        ((LinearMatrixElements*)osglData->tempC)->value->el[i] = new LinearMatrixElement(); 
    osglData->osglCounter = 0;
    osglData->numberOfVarIdxPresent = false;
}
    break;

  case 1413:

    {
    osglData->osglNonzeroCounter++;
    if (osglData->osglNonzeroCounter > osglData->osglNumberOfNonzeros)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}
    break;

  case 1414:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
}
    break;

  case 1415:

    {
    if (!osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->osglNonzeroCounter]->numberOfVarIdx
        = osglData->numberOfVarIdx;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->osglNonzeroCounter]->varIdx
        = new LinearMatrixElementTerm*[osglData->numberOfVarIdx];
    osglData->osglCounter = 0;
}
    break;

  case 1420:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglConstantPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "linear matrix elements: duplicate constant");    
    else
    {
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->osglNonzeroCounter]->constant
             = parserData->tempVal;
        osglData->osglConstantPresent = true;
    }
}
    break;

  case 1428:

    {
    osglData->osglCoefPresent = false;
    osglData->osglCoef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 1430:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->coef = parserData->tempVal;
}
    break;

  case 1431:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[(2) - (3)].ival);
    osglData->osglCounter++;
}
    break;

  case 1433:

    {
    osglData->tempC = new GeneralMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1434:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<generalElements>: numberOfValues attribute missing");    
}
    break;

  case 1437:

    {
        ((GeneralMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_general;
    }
    break;

  case 1438:

    {
        ((GeneralMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1444:

    {
    osglData->osglNonzeroCounter = 0;
    osglData->osglNumberOfNonzeros = ((GeneralMatrixElements*)osglData->tempC)->numberOfValues;

    ((GeneralMatrixElements*)osglData->tempC)->value = new GeneralMatrixValues();
    ((GeneralMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->osglNumberOfNonzeros;
    ((GeneralMatrixElements*)osglData->tempC)->value->el
        = new ScalarExpressionTree*[osglData->osglNumberOfNonzeros];

    for (int i=0; i<osglData->osglNumberOfNonzeros; i++)
        ((GeneralMatrixElements*)osglData->tempC)->value->el[i] = new ScalarExpressionTree();
}
    break;

  case 1452:

    {
        if (osglData->osglNonzeroCounter >= osglData->osglNumberOfNonzeros) 
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
        osnlData->matrixSumVec.clear();
        osnlData->matrixProductVec.clear();
    }
    break;

  case 1456:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE

        ((GeneralMatrixElements*)osglData->tempC)->value->el[osglData->osglNonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->osglNonzeroCounter++;
    }
    break;

  case 1458:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1459:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1462:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_objReference;
    }
    break;

  case 1463:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1467:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->osglNumberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1468:

    {
    osglData->osglNumberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1475:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1476:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1479:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_conReference;
    }
    break;

  case 1480:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1484:

    {
        if (osglData->osglNumberOfNonzeros > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1485:

    {
        if (osglData->osglNumberOfNonzeros > osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->osglNumberOfNonzeros < osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");        
        ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->osglNumberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1486:

    {
    osglData->osglNumberOfNonzeros = ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglNonzeroCounter = 0;

    ((ConReferenceMatrixElements*)osglData->tempC)->value = new ConReferenceMatrixValues();
    ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->osglNumberOfNonzeros;
    ((ConReferenceMatrixElements*)osglData->tempC)->value->el
        = new ConReferenceMatrixElement*[osglData->osglNumberOfNonzeros];

    for (int i=0; i<osglData->osglNumberOfNonzeros; i++)
        ((ConReferenceMatrixElements*)osglData->tempC)->value->el[i] = new ConReferenceMatrixElement();
}
    break;

  case 1493:

    {
//    osglData->osglNonzeroCounter++;
//    if (osglData->osglNonzeroCounter > osglData->osglNumberOfNonzeros)
//        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "conReference matrix elements: too many nonzeros");
}
    break;

  case 1494:

    {
        if (osglData->osglNonzeroCounter >= osglData->osglNumberOfNonzeros) 
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->valueTypePresent = false;
        osglData->osglMultPresent = false;
        osglData->osglIncrPresent = false;
        osglData->osglMult = 1;
        osglData->osglIncr = 0;
        osglData->valueType = ENUM_CONREFERENCE_VALUETYPE_value;
    }
    break;

  case 1500:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
            "only one valueType attribute allowed");

    std::string tmpStr = (yyvsp[(2) - (3)].sval); 
    if (returnConReferenceValueType(tmpStr) > 0)  
        osglData->valueType = (ENUM_CONREFERENCE_VALUETYPE)returnConReferenceValueType(tmpStr); 
    else
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
            "valueType must be one of \"value\", \"status\", \"surplus\", \"shortage\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1501:

    {
    if (osglData->osglNonzeroCounter + osglData->osglMult > osglData->osglNumberOfEl)
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
        {
            ((ConReferenceMatrixElements*)osglData->tempC)->value->el[osglData->osglNonzeroCounter + i]->conReference
                = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;
            ((ConReferenceMatrixElements*)osglData->tempC)->value->el[osglData->osglNonzeroCounter]->valueType
                = osglData->valueType; 
        }
        osglData->osglNonzeroCounter += osglData->osglMult;
    }
    break;

  case 1503:

    {
    osglData->tempC = new MatrixTransformation();
    osglData->mtxConstructorVec.push_back((MatrixTransformation*)osglData->tempC);

    // clear the vectors of pointers
    osnlData->nlNodeVec.clear();
    osnlData->sumVec.clear();
    osnlData->allDiffVec.clear();
    osnlData->maxVec.clear();
    osnlData->minVec.clear();
    osnlData->productVec.clear();
    osnlData->matrixSumVec.clear();
    osnlData->matrixProductVec.clear();

    osglData->shapePresent = false;   
}
    break;

  case 1505:

    {
    ((MatrixTransformation*)osglData->tempC)->shape = osglData->shape;
}
    break;

  case 1506:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 1507:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 1508:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}
    break;

  case 1509:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}
    break;

  case 1511:

    {
    if ( ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren != 
                           osglData->nBlocksVec.back())
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "Number of blocks does not agree with attribute value numberOfBlocks");

    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->m_mChildren
        = new MatrixNode*[((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren];
    osglData->mtxBlocksVec.pop_back();
    osglData->nBlocksVec.pop_back();
}
    break;

  case 1512:

    {
    if (osglData->osglCounter != osglData->osglNumberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of colOffsets does not match numberOfEl");
    ((MatrixBlocks*)osglData->tempC)->colOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->colOffset->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixBlocks*)osglData->tempC)->colOffset->el = osglData->osglIntArray;
    osglData->colOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1513:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 1514:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 1520:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1521:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
}
    break;

  case 1522:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}
    break;

  case 1529:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}
    break;

  case 1530:

    {
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1531:

    {
    osglData->tempC = new MatrixBlock();
    osglData->mtxConstructorVec.push_back((MatrixBlock*)osglData->tempC);
    osglData->mtxBlkVec.push_back(osglData->tempC);

    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->blockRowIdxPresent = false;
    osglData->blockColIdxPresent = false;   
}
    break;

  case 1537:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    break;

  case 1538:

    {
        ((MatrixBlock*)osglData->tempC)->type
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
    break;

  case 1539:

    {
    if (osglData->blockRowIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
        osglData->blockRowIdxPresent = true;        
        osglData->blockRowIdx = (yyvsp[(3) - (4)].ival);
        ((MatrixBlock*)osglData->tempC)->blockRowIdx = (yyvsp[(3) - (4)].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfRows 
        = osglData->rowOffsets.back()[osglData->blockRowIdx+1] 
        - osglData->rowOffsets.back()[osglData->blockRowIdx];
}
    break;

  case 1540:

    {
    if (osglData->blockColIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockColIdx cannot be negative");
        osglData->blockColIdxPresent = true;
        osglData->blockColIdx = (yyvsp[(3) - (4)].ival);       
        ((MatrixBlock*)osglData->tempC)->blockColIdx = (yyvsp[(3) - (4)].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfColumns 
        = osglData->colOffsets.back()[osglData->blockColIdx+1] 
        - osglData->colOffsets.back()[osglData->blockColIdx];
}
    break;

  case 1544:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 1546:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksPresent = true;        
    osglData->numberOfBlocks = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1547:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsPresent = true;        
    osglData->numberOfColumns = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1548:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;        
    osglData->osglNumberOfEl = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1549:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfRowsPresent = true;        
    osglData->numberOfRows = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1550:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesPresent = true;        
    osglData->numberOfValues = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1551:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxPresent = true;        
    osglData->numberOfVarIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1552:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1553:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1554:

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

  case 1555:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (ENUM_NL_EXPR_SHAPE)returnNlExprShape((yyvsp[(2) - (3)].sval));
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1558:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}
    break;

  case 1559:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->rowMajor = false;
        else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->rowMajor = true;
        else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1587:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1591:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1595:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1597:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1599:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1601:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1603:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1605:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1607:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1609:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1611:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1613:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1615:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1617:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1620:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1621:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1622:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1623:

    {
}
    break;

  case 1624:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1625:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1626:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1628:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1630:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1632:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 1633:

    {osnlData->numbervalueattON = false; osnlData->numbertypeattON = false; osnlData->numberidattON = false;}
    break;

  case 1641:

    {
    if (osnlData->numbertypeattON) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many number type attributes"); 
    osnlData->numbertypeattON = true;
    osnlData->nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 1643:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 1645:

    {
    if (osnlData->numbervalueattON) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many number value attributes"); 
    osnlData->numbervalueattON = true;
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
}
    break;

  case 1646:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 1647:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 1650:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
        }
    break;

  case 1654:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 1655:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 1656:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 1657:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1658:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1659:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 1661:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 1662:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1663:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1665:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 1666:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1667:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1669:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 1670:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1671:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1673:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 1674:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1675:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 1677:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 1697:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1698:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 1701:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1702:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1703:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 1706:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1707:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1708:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 1711:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1712:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1713:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 1716:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1718:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1721:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1724:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1727:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1730:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1732:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1735:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1737:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1739:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1741:

    {
     parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 1745:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1748:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1751:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1754:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1756:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1757:

    {
    osnlData->matrixProductVec.back()->m_mMatrixChildren = new OSnLMNode*[ osnlData->matrixProductVec.back()->inumberOfMatrixChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 1759:

    { 
    osnlData->matrixProductVec.back()->inumberOfMatrixChildren++; 
}
    break;

  case 1761:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1764:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1767:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
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


