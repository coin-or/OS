
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
     WEIGHTEDOBJECTIVESATT = 271,
     EMPTYWEIGHTEDOBJECTIVESATT = 272,
     TARGETOBJECTIVENAMEATT = 273,
     EMPTYTARGETOBJECTIVENAMEATT = 274,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 275,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 276,
     NUMBEROFOTHERRESULTSATT = 277,
     NUMBEROFOTHERSOLUTIONRESULTSATT = 278,
     NUMBEROFOTHERVARIABLERESULTSATT = 279,
     NUMBEROFSOLUTIONSATT = 280,
     NUMBEROFOTHERMATRIXOBJECTIVERESULTSATT = 281,
     NUMBEROFOTHERMATRIXCONSTRAINTRESULTSATT = 282,
     NUMBEROFOTHERMATRIXPROGRAMMINGRESULTSATT = 283,
     NUMBEROFOTHERMATRIXVARIABLERESULTSATT = 284,
     NUMBEROFSOLVEROUTPUTSATT = 285,
     NUMBEROFSUBSTATUSESATT = 286,
     NUMBEROFTIMESATT = 287,
     TARGETOBJECTIVEIDXATT = 288,
     ACTUALSTARTTIMESTART = 289,
     ACTUALSTARTTIMEEND = 290,
     AVAILABLECPUNUMBERSTART = 291,
     AVAILABLECPUNUMBEREND = 292,
     AVAILABLECPUSPEEDSTART = 293,
     AVAILABLECPUSPEEDEND = 294,
     AVAILABLEDISKSPACESTART = 295,
     AVAILABLEDISKSPACEEND = 296,
     AVAILABLEMEMORYSTART = 297,
     AVAILABLEMEMORYEND = 298,
     BASISSTATUSSTART = 299,
     BASISSTATUSEND = 300,
     CURRENTJOBCOUNTSTART = 301,
     CURRENTJOBCOUNTEND = 302,
     CURRENTSTATESTART = 303,
     CURRENTSTATEEND = 304,
     DUALVALUESSTART = 305,
     DUALVALUESEND = 306,
     ENDTIMESTART = 307,
     ENDTIMEEND = 308,
     IDXSTART = 309,
     IDXEND = 310,
     GENERALSTATUSSTART = 311,
     GENERALSTATUSEND = 312,
     GENERALSUBSTATUSSTART = 313,
     GENERALSUBSTATUSEND = 314,
     MESSAGESTART = 315,
     MESSAGEEND = 316,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 317,
     OPTIMIZATIONSOLUTIONSTATUSEND = 318,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 319,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 320,
     OTHERRESULTSSTART = 321,
     OTHERRESULTSEND = 322,
     OTHERSOLUTIONRESULTSTART = 323,
     OTHERSOLUTIONRESULTEND = 324,
     OTHERSOLUTIONRESULTSSTART = 325,
     OTHERSOLUTIONRESULTSEND = 326,
     OTHERSOLVEROUTPUTSTART = 327,
     OTHERSOLVEROUTPUTEND = 328,
     SCHEDULEDSTARTTIMESTART = 329,
     SCHEDULEDSTARTTIMEEND = 330,
     SERVICEUTILIZATIONSTART = 331,
     SERVICEUTILIZATIONEND = 332,
     SOLUTIONSTART = 333,
     SOLUTIONEND = 334,
     SOLVERINVOKEDSTART = 335,
     SOLVERINVOKEDEND = 336,
     SOLVEROUTPUTSTART = 337,
     SOLVEROUTPUTEND = 338,
     STATUSSTART = 339,
     STATUSEND = 340,
     SUBMITTIMESTART = 341,
     SUBMITTIMEEND = 342,
     SUBSTATUSSTART = 343,
     SUBSTATUSEND = 344,
     SYSTEMINFORMATIONSTART = 345,
     SYSTEMINFORMATIONEND = 346,
     TIMESTART = 347,
     TIMEEND = 348,
     TIMESERVICESTARTEDSTART = 349,
     TIMESERVICESTARTEDEND = 350,
     TIMESTAMPSTART = 351,
     TIMESTAMPEND = 352,
     TIMINGINFORMATIONSTART = 353,
     TIMINGINFORMATIONEND = 354,
     TOTALJOBSSOFARSTART = 355,
     TOTALJOBSSOFAREND = 356,
     USEDCPUNUMBERSTART = 357,
     USEDCPUNUMBEREND = 358,
     USEDCPUSPEEDSTART = 359,
     USEDCPUSPEEDEND = 360,
     USEDDISKSPACESTART = 361,
     USEDDISKSPACEEND = 362,
     USEDMEMORYSTART = 363,
     USEDMEMORYEND = 364,
     VALUESSTRINGSTART = 365,
     VALUESSTRINGEND = 366,
     OTHERMATRIXVARIABLERESULTSTART = 367,
     OTHERMATRIXVARIABLERESULTEND = 368,
     OTHERMATRIXOBJECTIVERESULTSTART = 369,
     OTHERMATRIXOBJECTIVERESULTEND = 370,
     OTHERMATRIXCONSTRAINTRESULTSTART = 371,
     OTHERMATRIXCONSTRAINTRESULTEND = 372,
     OTHERMATRIXPROGRAMMINGRESULTSTART = 373,
     OTHERMATRIXPROGRAMMINGRESULTEND = 374,
     HEADERSTART = 375,
     HEADEREND = 376,
     FILENAMESTART = 377,
     FILENAMEEND = 378,
     FILENAMEEMPTY = 379,
     FILENAMESTARTANDEND = 380,
     FILESOURCESTART = 381,
     FILESOURCEEND = 382,
     FILESOURCEEMPTY = 383,
     FILESOURCESTARTANDEND = 384,
     FILEDESCRIPTIONSTART = 385,
     FILEDESCRIPTIONEND = 386,
     FILEDESCRIPTIONEMPTY = 387,
     FILEDESCRIPTIONSTARTANDEND = 388,
     FILECREATORSTART = 389,
     FILECREATOREND = 390,
     FILECREATOREMPTY = 391,
     FILECREATORSTARTANDEND = 392,
     FILELICENCESTART = 393,
     FILELICENCEEND = 394,
     FILELICENCEEMPTY = 395,
     FILELICENCESTARTANDEND = 396,
     INDEXESSTART = 397,
     INDEXESEND = 398,
     VALUESSTART = 399,
     VALUESEND = 400,
     NONZEROSSTART = 401,
     NONZEROSEND = 402,
     ELSTART = 403,
     ELEND = 404,
     ENUMERATIONSTART = 405,
     ENUMERATIONEND = 406,
     ITEMEMPTY = 407,
     ITEMSTART = 408,
     ITEMEND = 409,
     ITEMSTARTANDEND = 410,
     BASE64START = 411,
     BASE64END = 412,
     NUMBEROFELATT = 413,
     NUMBEROFENUMERATIONSATT = 414,
     NUMBEROFITEMSATT = 415,
     EMPTYCATEGORYATT = 416,
     CATEGORYATT = 417,
     EMPTYDESCRIPTIONATT = 418,
     DESCRIPTIONATT = 419,
     EMPTYSOLVERATT = 420,
     SOLVERATT = 421,
     EMPTYNAMEATT = 422,
     NAMEATT = 423,
     EMPTYTYPEATT = 424,
     TYPEATT = 425,
     EMPTYENUMTYPEATT = 426,
     ENUMTYPEATT = 427,
     EMPTYSHAPEATT = 428,
     SHAPEATT = 429,
     EMPTYUNITATT = 430,
     UNITATT = 431,
     EMPTYVALUEATT = 432,
     VALUEATT = 433,
     EMPTYVALUETYPEATT = 434,
     VALUETYPEATT = 435,
     EMPTYCONTYPEATT = 436,
     CONTYPEATT = 437,
     EMPTYOBJTYPEATT = 438,
     OBJTYPEATT = 439,
     EMPTYVARTYPEATT = 440,
     VARTYPEATT = 441,
     EMPTYMATRIXCONTYPEATT = 442,
     MATRIXCONTYPEATT = 443,
     EMPTYMATRIXOBJTYPEATT = 444,
     MATRIXOBJTYPEATT = 445,
     EMPTYMATRIXVARTYPEATT = 446,
     MATRIXVARTYPEATT = 447,
     EMPTYMATRIXTYPEATT = 448,
     MATRIXTYPEATT = 449,
     EMPTYSYMMETRYATT = 450,
     SYMMETRYATT = 451,
     EMPTYROWMAJORATT = 452,
     ROWMAJORATT = 453,
     EMPTYBASETRANSPOSEATT = 454,
     BASETRANSPOSEATT = 455,
     NUMBEROFBLOCKSATT = 456,
     NUMBEROFCOLUMNSATT = 457,
     NUMBEROFROWSATT = 458,
     NUMBEROFMATRICESATT = 459,
     NUMBEROFVALUESATT = 460,
     NUMBEROFCONSTRAINTSATT = 461,
     NUMBEROFCONATT = 462,
     NUMBEROFCONIDXATT = 463,
     NUMBEROFOBJECTIVESATT = 464,
     NUMBEROFOBJATT = 465,
     NUMBEROFOBJIDXATT = 466,
     NUMBEROFVARIABLESATT = 467,
     NUMBEROFVARATT = 468,
     NUMBEROFVARIDXATT = 469,
     NUMBEROFMATRIXCONATT = 470,
     NUMBEROFMATRIXOBJATT = 471,
     NUMBEROFMATRIXVARATT = 472,
     BASEMATRIXIDXATT = 473,
     TARGETMATRIXFIRSTROWATT = 474,
     TARGETMATRIXFIRSTCOLATT = 475,
     BASEMATRIXSTARTROWATT = 476,
     BASEMATRIXSTARTCOLATT = 477,
     BASEMATRIXENDROWATT = 478,
     BASEMATRIXENDCOLATT = 479,
     SCALARMULTIPLIERATT = 480,
     BLOCKROWIDXATT = 481,
     BLOCKCOLIDXATT = 482,
     REATT = 483,
     IMATT = 484,
     MATRIXVARIDXATT = 485,
     MATRIXOBJIDXATT = 486,
     MATRIXCONIDXATT = 487,
     IDXATT = 488,
     INCRATT = 489,
     MULTATT = 490,
     SIZEOFATT = 491,
     COEFATT = 492,
     CONSTANTATT = 493,
     MATRICESSTART = 494,
     MATRICESEND = 495,
     MATRIXSTART = 496,
     MATRIXEND = 497,
     BASEMATRIXEND = 498,
     BASEMATRIXSTART = 499,
     BLOCKSSTART = 500,
     BLOCKSEND = 501,
     BLOCKSTART = 502,
     BLOCKEND = 503,
     COLOFFSETSTART = 504,
     COLOFFSETEND = 505,
     ROWOFFSETSTART = 506,
     ROWOFFSETEND = 507,
     ELEMENTSSTART = 508,
     ELEMENTSEND = 509,
     CONSTANTELEMENTSSTART = 510,
     CONSTANTELEMENTSEND = 511,
     COMPLEXELEMENTSSTART = 512,
     COMPLEXELEMENTSEND = 513,
     VARREFERENCEELEMENTSSTART = 514,
     VARREFERENCEELEMENTSEND = 515,
     LINEARELEMENTSSTART = 516,
     LINEARELEMENTSEND = 517,
     CONREFERENCEELEMENTSSTART = 518,
     CONREFERENCEELEMENTSEND = 519,
     OBJREFERENCEELEMENTSSTART = 520,
     OBJREFERENCEELEMENTSEND = 521,
     REALVALUEDEXPRESSIONSSTART = 522,
     REALVALUEDEXPRESSIONSSEND = 523,
     COMPLEXVALUEDEXPRESSIONSSTART = 524,
     COMPLEXVALUEDEXPRESSIONSSEND = 525,
     STRINGVALUEDELEMENTSSTART = 526,
     STRINGVALUEDELEMENTSEND = 527,
     STARTVECTORSTART = 528,
     STARTVECTOREND = 529,
     INDEXSTART = 530,
     INDEXEND = 531,
     VALUESTART = 532,
     VALUEEND = 533,
     VARIDXSTART = 534,
     VARIDXEND = 535,
     TRANSFORMATIONSTART = 536,
     TRANSFORMATIONEND = 537,
     MATRIXPROGRAMMINGSTART = 538,
     MATRIXPROGRAMMINGEND = 539,
     MATRIXVARIABLESSTART = 540,
     MATRIXVARIABLESEND = 541,
     MATRIXVARSTART = 542,
     MATRIXVAREND = 543,
     MATRIXOBJECTIVESSTART = 544,
     MATRIXOBJECTIVESEND = 545,
     MATRIXOBJSTART = 546,
     MATRIXOBJEND = 547,
     MATRIXCONSTRAINTSSTART = 548,
     MATRIXCONSTRAINTSEND = 549,
     MATRIXCONSTART = 550,
     MATRIXCONEND = 551,
     CONSTART = 552,
     CONEND = 553,
     CONSTRAINTSSTART = 554,
     CONSTRAINTSEND = 555,
     OBJSTART = 556,
     OBJEND = 557,
     OBJECTIVESSTART = 558,
     OBJECTIVESEND = 559,
     VARSTART = 560,
     VAREND = 561,
     VARIABLESSTART = 562,
     VARIABLESEND = 563,
     GENERALSTART = 564,
     GENERALEND = 565,
     SYSTEMSTART = 566,
     SYSTEMEND = 567,
     SERVICESTART = 568,
     SERVICEEND = 569,
     JOBSTART = 570,
     JOBEND = 571,
     OPTIMIZATIONSTART = 572,
     OPTIMIZATIONEND = 573,
     ATEQUALITYSTART = 574,
     ATEQUALITYEND = 575,
     ATLOWERSTART = 576,
     ATLOWEREND = 577,
     ATUPPERSTART = 578,
     ATUPPEREND = 579,
     BASICSTART = 580,
     BASICEND = 581,
     ISFREESTART = 582,
     ISFREEEND = 583,
     SUPERBASICSTART = 584,
     SUPERBASICEND = 585,
     UNKNOWNSTART = 586,
     UNKNOWNEND = 587,
     SERVICEURISTART = 588,
     SERVICEURIEND = 589,
     SERVICENAMESTART = 590,
     SERVICENAMEEND = 591,
     INSTANCENAMESTART = 592,
     INSTANCENAMEEND = 593,
     JOBIDSTART = 594,
     JOBIDEND = 595,
     OTHERSTART = 596,
     OTHEREND = 597,
     DUMMY = 598,
     NONLINEAREXPRESSIONSSTART = 599,
     NONLINEAREXPRESSIONSEND = 600,
     NUMBEROFNONLINEAREXPRESSIONS = 601,
     NLSTART = 602,
     NLEND = 603,
     MATRIXEXPRESSIONSSTART = 604,
     MATRIXEXPRESSIONSEND = 605,
     NUMBEROFEXPR = 606,
     EXPRSTART = 607,
     EXPREND = 608,
     NUMBEROFMATRIXTERMSATT = 609,
     MATRIXTERMSTART = 610,
     MATRIXTERMEND = 611,
     POWERSTART = 612,
     POWEREND = 613,
     PLUSSTART = 614,
     PLUSEND = 615,
     MINUSSTART = 616,
     MINUSEND = 617,
     DIVIDESTART = 618,
     DIVIDEEND = 619,
     LNSTART = 620,
     LNEND = 621,
     SQRTSTART = 622,
     SQRTEND = 623,
     SUMSTART = 624,
     SUMEND = 625,
     PRODUCTSTART = 626,
     PRODUCTEND = 627,
     EXPSTART = 628,
     EXPEND = 629,
     NEGATESTART = 630,
     NEGATEEND = 631,
     IFSTART = 632,
     IFEND = 633,
     SQUARESTART = 634,
     SQUAREEND = 635,
     COSSTART = 636,
     COSEND = 637,
     SINSTART = 638,
     SINEND = 639,
     VARIABLESTART = 640,
     VARIABLEEND = 641,
     ABSSTART = 642,
     ABSEND = 643,
     ERFSTART = 644,
     ERFEND = 645,
     MAXSTART = 646,
     MAXEND = 647,
     ALLDIFFSTART = 648,
     ALLDIFFEND = 649,
     MINSTART = 650,
     MINEND = 651,
     ESTART = 652,
     EEND = 653,
     PISTART = 654,
     PIEND = 655,
     TIMESSTART = 656,
     TIMESEND = 657,
     NUMBERSTART = 658,
     NUMBEREND = 659,
     MATRIXDETERMINANTSTART = 660,
     MATRIXDETERMINANTEND = 661,
     MATRIXTRACESTART = 662,
     MATRIXTRACEEND = 663,
     MATRIXTOSCALARSTART = 664,
     MATRIXTOSCALAREND = 665,
     MATRIXDIAGONALSTART = 666,
     MATRIXDIAGONALEND = 667,
     MATRIXDOTTIMESSTART = 668,
     MATRIXDOTTIMESEND = 669,
     MATRIXLOWERTRIANGLESTART = 670,
     MATRIXLOWERTRIANGLEEND = 671,
     MATRIXUPPERTRIANGLESTART = 672,
     MATRIXUPPERTRIANGLEEND = 673,
     MATRIXMERGESTART = 674,
     MATRIXMERGEEND = 675,
     MATRIXMINUSSTART = 676,
     MATRIXMINUSEND = 677,
     MATRIXNEGATESTART = 678,
     MATRIXNEGATEEND = 679,
     MATRIXPLUSSTART = 680,
     MATRIXPLUSEND = 681,
     MATRIXTIMESSTART = 682,
     MATRIXTIMESEND = 683,
     MATRIXPRODUCTSTART = 684,
     MATRIXPRODUCTEND = 685,
     MATRIXSCALARTIMESSTART = 686,
     MATRIXSCALARTIMESEND = 687,
     MATRIXSUBMATRIXATSTART = 688,
     MATRIXSUBMATRIXATEND = 689,
     MATRIXTRANSPOSESTART = 690,
     MATRIXTRANSPOSEEND = 691,
     MATRIXREFERENCESTART = 692,
     MATRIXREFERENCEEND = 693,
     IDENTITYMATRIXSTART = 694,
     IDENTITYMATRIXEND = 695,
     MATRIXINVERSESTART = 696,
     MATRIXINVERSEEND = 697,
     EMPTYINCLUDEDIAGONALATT = 698,
     INCLUDEDIAGONALATT = 699,
     EMPTYIDATT = 700,
     IDATT = 701
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
#define WEIGHTEDOBJECTIVESATT 271
#define EMPTYWEIGHTEDOBJECTIVESATT 272
#define TARGETOBJECTIVENAMEATT 273
#define EMPTYTARGETOBJECTIVENAMEATT 274
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 275
#define NUMBEROFOTHEROBJECTIVERESULTSATT 276
#define NUMBEROFOTHERRESULTSATT 277
#define NUMBEROFOTHERSOLUTIONRESULTSATT 278
#define NUMBEROFOTHERVARIABLERESULTSATT 279
#define NUMBEROFSOLUTIONSATT 280
#define NUMBEROFOTHERMATRIXOBJECTIVERESULTSATT 281
#define NUMBEROFOTHERMATRIXCONSTRAINTRESULTSATT 282
#define NUMBEROFOTHERMATRIXPROGRAMMINGRESULTSATT 283
#define NUMBEROFOTHERMATRIXVARIABLERESULTSATT 284
#define NUMBEROFSOLVEROUTPUTSATT 285
#define NUMBEROFSUBSTATUSESATT 286
#define NUMBEROFTIMESATT 287
#define TARGETOBJECTIVEIDXATT 288
#define ACTUALSTARTTIMESTART 289
#define ACTUALSTARTTIMEEND 290
#define AVAILABLECPUNUMBERSTART 291
#define AVAILABLECPUNUMBEREND 292
#define AVAILABLECPUSPEEDSTART 293
#define AVAILABLECPUSPEEDEND 294
#define AVAILABLEDISKSPACESTART 295
#define AVAILABLEDISKSPACEEND 296
#define AVAILABLEMEMORYSTART 297
#define AVAILABLEMEMORYEND 298
#define BASISSTATUSSTART 299
#define BASISSTATUSEND 300
#define CURRENTJOBCOUNTSTART 301
#define CURRENTJOBCOUNTEND 302
#define CURRENTSTATESTART 303
#define CURRENTSTATEEND 304
#define DUALVALUESSTART 305
#define DUALVALUESEND 306
#define ENDTIMESTART 307
#define ENDTIMEEND 308
#define IDXSTART 309
#define IDXEND 310
#define GENERALSTATUSSTART 311
#define GENERALSTATUSEND 312
#define GENERALSUBSTATUSSTART 313
#define GENERALSUBSTATUSEND 314
#define MESSAGESTART 315
#define MESSAGEEND 316
#define OPTIMIZATIONSOLUTIONSTATUSSTART 317
#define OPTIMIZATIONSOLUTIONSTATUSEND 318
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 319
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 320
#define OTHERRESULTSSTART 321
#define OTHERRESULTSEND 322
#define OTHERSOLUTIONRESULTSTART 323
#define OTHERSOLUTIONRESULTEND 324
#define OTHERSOLUTIONRESULTSSTART 325
#define OTHERSOLUTIONRESULTSEND 326
#define OTHERSOLVEROUTPUTSTART 327
#define OTHERSOLVEROUTPUTEND 328
#define SCHEDULEDSTARTTIMESTART 329
#define SCHEDULEDSTARTTIMEEND 330
#define SERVICEUTILIZATIONSTART 331
#define SERVICEUTILIZATIONEND 332
#define SOLUTIONSTART 333
#define SOLUTIONEND 334
#define SOLVERINVOKEDSTART 335
#define SOLVERINVOKEDEND 336
#define SOLVEROUTPUTSTART 337
#define SOLVEROUTPUTEND 338
#define STATUSSTART 339
#define STATUSEND 340
#define SUBMITTIMESTART 341
#define SUBMITTIMEEND 342
#define SUBSTATUSSTART 343
#define SUBSTATUSEND 344
#define SYSTEMINFORMATIONSTART 345
#define SYSTEMINFORMATIONEND 346
#define TIMESTART 347
#define TIMEEND 348
#define TIMESERVICESTARTEDSTART 349
#define TIMESERVICESTARTEDEND 350
#define TIMESTAMPSTART 351
#define TIMESTAMPEND 352
#define TIMINGINFORMATIONSTART 353
#define TIMINGINFORMATIONEND 354
#define TOTALJOBSSOFARSTART 355
#define TOTALJOBSSOFAREND 356
#define USEDCPUNUMBERSTART 357
#define USEDCPUNUMBEREND 358
#define USEDCPUSPEEDSTART 359
#define USEDCPUSPEEDEND 360
#define USEDDISKSPACESTART 361
#define USEDDISKSPACEEND 362
#define USEDMEMORYSTART 363
#define USEDMEMORYEND 364
#define VALUESSTRINGSTART 365
#define VALUESSTRINGEND 366
#define OTHERMATRIXVARIABLERESULTSTART 367
#define OTHERMATRIXVARIABLERESULTEND 368
#define OTHERMATRIXOBJECTIVERESULTSTART 369
#define OTHERMATRIXOBJECTIVERESULTEND 370
#define OTHERMATRIXCONSTRAINTRESULTSTART 371
#define OTHERMATRIXCONSTRAINTRESULTEND 372
#define OTHERMATRIXPROGRAMMINGRESULTSTART 373
#define OTHERMATRIXPROGRAMMINGRESULTEND 374
#define HEADERSTART 375
#define HEADEREND 376
#define FILENAMESTART 377
#define FILENAMEEND 378
#define FILENAMEEMPTY 379
#define FILENAMESTARTANDEND 380
#define FILESOURCESTART 381
#define FILESOURCEEND 382
#define FILESOURCEEMPTY 383
#define FILESOURCESTARTANDEND 384
#define FILEDESCRIPTIONSTART 385
#define FILEDESCRIPTIONEND 386
#define FILEDESCRIPTIONEMPTY 387
#define FILEDESCRIPTIONSTARTANDEND 388
#define FILECREATORSTART 389
#define FILECREATOREND 390
#define FILECREATOREMPTY 391
#define FILECREATORSTARTANDEND 392
#define FILELICENCESTART 393
#define FILELICENCEEND 394
#define FILELICENCEEMPTY 395
#define FILELICENCESTARTANDEND 396
#define INDEXESSTART 397
#define INDEXESEND 398
#define VALUESSTART 399
#define VALUESEND 400
#define NONZEROSSTART 401
#define NONZEROSEND 402
#define ELSTART 403
#define ELEND 404
#define ENUMERATIONSTART 405
#define ENUMERATIONEND 406
#define ITEMEMPTY 407
#define ITEMSTART 408
#define ITEMEND 409
#define ITEMSTARTANDEND 410
#define BASE64START 411
#define BASE64END 412
#define NUMBEROFELATT 413
#define NUMBEROFENUMERATIONSATT 414
#define NUMBEROFITEMSATT 415
#define EMPTYCATEGORYATT 416
#define CATEGORYATT 417
#define EMPTYDESCRIPTIONATT 418
#define DESCRIPTIONATT 419
#define EMPTYSOLVERATT 420
#define SOLVERATT 421
#define EMPTYNAMEATT 422
#define NAMEATT 423
#define EMPTYTYPEATT 424
#define TYPEATT 425
#define EMPTYENUMTYPEATT 426
#define ENUMTYPEATT 427
#define EMPTYSHAPEATT 428
#define SHAPEATT 429
#define EMPTYUNITATT 430
#define UNITATT 431
#define EMPTYVALUEATT 432
#define VALUEATT 433
#define EMPTYVALUETYPEATT 434
#define VALUETYPEATT 435
#define EMPTYCONTYPEATT 436
#define CONTYPEATT 437
#define EMPTYOBJTYPEATT 438
#define OBJTYPEATT 439
#define EMPTYVARTYPEATT 440
#define VARTYPEATT 441
#define EMPTYMATRIXCONTYPEATT 442
#define MATRIXCONTYPEATT 443
#define EMPTYMATRIXOBJTYPEATT 444
#define MATRIXOBJTYPEATT 445
#define EMPTYMATRIXVARTYPEATT 446
#define MATRIXVARTYPEATT 447
#define EMPTYMATRIXTYPEATT 448
#define MATRIXTYPEATT 449
#define EMPTYSYMMETRYATT 450
#define SYMMETRYATT 451
#define EMPTYROWMAJORATT 452
#define ROWMAJORATT 453
#define EMPTYBASETRANSPOSEATT 454
#define BASETRANSPOSEATT 455
#define NUMBEROFBLOCKSATT 456
#define NUMBEROFCOLUMNSATT 457
#define NUMBEROFROWSATT 458
#define NUMBEROFMATRICESATT 459
#define NUMBEROFVALUESATT 460
#define NUMBEROFCONSTRAINTSATT 461
#define NUMBEROFCONATT 462
#define NUMBEROFCONIDXATT 463
#define NUMBEROFOBJECTIVESATT 464
#define NUMBEROFOBJATT 465
#define NUMBEROFOBJIDXATT 466
#define NUMBEROFVARIABLESATT 467
#define NUMBEROFVARATT 468
#define NUMBEROFVARIDXATT 469
#define NUMBEROFMATRIXCONATT 470
#define NUMBEROFMATRIXOBJATT 471
#define NUMBEROFMATRIXVARATT 472
#define BASEMATRIXIDXATT 473
#define TARGETMATRIXFIRSTROWATT 474
#define TARGETMATRIXFIRSTCOLATT 475
#define BASEMATRIXSTARTROWATT 476
#define BASEMATRIXSTARTCOLATT 477
#define BASEMATRIXENDROWATT 478
#define BASEMATRIXENDCOLATT 479
#define SCALARMULTIPLIERATT 480
#define BLOCKROWIDXATT 481
#define BLOCKCOLIDXATT 482
#define REATT 483
#define IMATT 484
#define MATRIXVARIDXATT 485
#define MATRIXOBJIDXATT 486
#define MATRIXCONIDXATT 487
#define IDXATT 488
#define INCRATT 489
#define MULTATT 490
#define SIZEOFATT 491
#define COEFATT 492
#define CONSTANTATT 493
#define MATRICESSTART 494
#define MATRICESEND 495
#define MATRIXSTART 496
#define MATRIXEND 497
#define BASEMATRIXEND 498
#define BASEMATRIXSTART 499
#define BLOCKSSTART 500
#define BLOCKSEND 501
#define BLOCKSTART 502
#define BLOCKEND 503
#define COLOFFSETSTART 504
#define COLOFFSETEND 505
#define ROWOFFSETSTART 506
#define ROWOFFSETEND 507
#define ELEMENTSSTART 508
#define ELEMENTSEND 509
#define CONSTANTELEMENTSSTART 510
#define CONSTANTELEMENTSEND 511
#define COMPLEXELEMENTSSTART 512
#define COMPLEXELEMENTSEND 513
#define VARREFERENCEELEMENTSSTART 514
#define VARREFERENCEELEMENTSEND 515
#define LINEARELEMENTSSTART 516
#define LINEARELEMENTSEND 517
#define CONREFERENCEELEMENTSSTART 518
#define CONREFERENCEELEMENTSEND 519
#define OBJREFERENCEELEMENTSSTART 520
#define OBJREFERENCEELEMENTSEND 521
#define REALVALUEDEXPRESSIONSSTART 522
#define REALVALUEDEXPRESSIONSSEND 523
#define COMPLEXVALUEDEXPRESSIONSSTART 524
#define COMPLEXVALUEDEXPRESSIONSSEND 525
#define STRINGVALUEDELEMENTSSTART 526
#define STRINGVALUEDELEMENTSEND 527
#define STARTVECTORSTART 528
#define STARTVECTOREND 529
#define INDEXSTART 530
#define INDEXEND 531
#define VALUESTART 532
#define VALUEEND 533
#define VARIDXSTART 534
#define VARIDXEND 535
#define TRANSFORMATIONSTART 536
#define TRANSFORMATIONEND 537
#define MATRIXPROGRAMMINGSTART 538
#define MATRIXPROGRAMMINGEND 539
#define MATRIXVARIABLESSTART 540
#define MATRIXVARIABLESEND 541
#define MATRIXVARSTART 542
#define MATRIXVAREND 543
#define MATRIXOBJECTIVESSTART 544
#define MATRIXOBJECTIVESEND 545
#define MATRIXOBJSTART 546
#define MATRIXOBJEND 547
#define MATRIXCONSTRAINTSSTART 548
#define MATRIXCONSTRAINTSEND 549
#define MATRIXCONSTART 550
#define MATRIXCONEND 551
#define CONSTART 552
#define CONEND 553
#define CONSTRAINTSSTART 554
#define CONSTRAINTSEND 555
#define OBJSTART 556
#define OBJEND 557
#define OBJECTIVESSTART 558
#define OBJECTIVESEND 559
#define VARSTART 560
#define VAREND 561
#define VARIABLESSTART 562
#define VARIABLESEND 563
#define GENERALSTART 564
#define GENERALEND 565
#define SYSTEMSTART 566
#define SYSTEMEND 567
#define SERVICESTART 568
#define SERVICEEND 569
#define JOBSTART 570
#define JOBEND 571
#define OPTIMIZATIONSTART 572
#define OPTIMIZATIONEND 573
#define ATEQUALITYSTART 574
#define ATEQUALITYEND 575
#define ATLOWERSTART 576
#define ATLOWEREND 577
#define ATUPPERSTART 578
#define ATUPPEREND 579
#define BASICSTART 580
#define BASICEND 581
#define ISFREESTART 582
#define ISFREEEND 583
#define SUPERBASICSTART 584
#define SUPERBASICEND 585
#define UNKNOWNSTART 586
#define UNKNOWNEND 587
#define SERVICEURISTART 588
#define SERVICEURIEND 589
#define SERVICENAMESTART 590
#define SERVICENAMEEND 591
#define INSTANCENAMESTART 592
#define INSTANCENAMEEND 593
#define JOBIDSTART 594
#define JOBIDEND 595
#define OTHERSTART 596
#define OTHEREND 597
#define DUMMY 598
#define NONLINEAREXPRESSIONSSTART 599
#define NONLINEAREXPRESSIONSEND 600
#define NUMBEROFNONLINEAREXPRESSIONS 601
#define NLSTART 602
#define NLEND 603
#define MATRIXEXPRESSIONSSTART 604
#define MATRIXEXPRESSIONSEND 605
#define NUMBEROFEXPR 606
#define EXPRSTART 607
#define EXPREND 608
#define NUMBEROFMATRIXTERMSATT 609
#define MATRIXTERMSTART 610
#define MATRIXTERMEND 611
#define POWERSTART 612
#define POWEREND 613
#define PLUSSTART 614
#define PLUSEND 615
#define MINUSSTART 616
#define MINUSEND 617
#define DIVIDESTART 618
#define DIVIDEEND 619
#define LNSTART 620
#define LNEND 621
#define SQRTSTART 622
#define SQRTEND 623
#define SUMSTART 624
#define SUMEND 625
#define PRODUCTSTART 626
#define PRODUCTEND 627
#define EXPSTART 628
#define EXPEND 629
#define NEGATESTART 630
#define NEGATEEND 631
#define IFSTART 632
#define IFEND 633
#define SQUARESTART 634
#define SQUAREEND 635
#define COSSTART 636
#define COSEND 637
#define SINSTART 638
#define SINEND 639
#define VARIABLESTART 640
#define VARIABLEEND 641
#define ABSSTART 642
#define ABSEND 643
#define ERFSTART 644
#define ERFEND 645
#define MAXSTART 646
#define MAXEND 647
#define ALLDIFFSTART 648
#define ALLDIFFEND 649
#define MINSTART 650
#define MINEND 651
#define ESTART 652
#define EEND 653
#define PISTART 654
#define PIEND 655
#define TIMESSTART 656
#define TIMESEND 657
#define NUMBERSTART 658
#define NUMBEREND 659
#define MATRIXDETERMINANTSTART 660
#define MATRIXDETERMINANTEND 661
#define MATRIXTRACESTART 662
#define MATRIXTRACEEND 663
#define MATRIXTOSCALARSTART 664
#define MATRIXTOSCALAREND 665
#define MATRIXDIAGONALSTART 666
#define MATRIXDIAGONALEND 667
#define MATRIXDOTTIMESSTART 668
#define MATRIXDOTTIMESEND 669
#define MATRIXLOWERTRIANGLESTART 670
#define MATRIXLOWERTRIANGLEEND 671
#define MATRIXUPPERTRIANGLESTART 672
#define MATRIXUPPERTRIANGLEEND 673
#define MATRIXMERGESTART 674
#define MATRIXMERGEEND 675
#define MATRIXMINUSSTART 676
#define MATRIXMINUSEND 677
#define MATRIXNEGATESTART 678
#define MATRIXNEGATEEND 679
#define MATRIXPLUSSTART 680
#define MATRIXPLUSEND 681
#define MATRIXTIMESSTART 682
#define MATRIXTIMESEND 683
#define MATRIXPRODUCTSTART 684
#define MATRIXPRODUCTEND 685
#define MATRIXSCALARTIMESSTART 686
#define MATRIXSCALARTIMESEND 687
#define MATRIXSUBMATRIXATSTART 688
#define MATRIXSUBMATRIXATEND 689
#define MATRIXTRANSPOSESTART 690
#define MATRIXTRANSPOSEEND 691
#define MATRIXREFERENCESTART 692
#define MATRIXREFERENCEEND 693
#define IDENTITYMATRIXSTART 694
#define IDENTITYMATRIXEND 695
#define MATRIXINVERSESTART 696
#define MATRIXINVERSEEND 697
#define EMPTYINCLUDEDIAGONALATT 698
#define INCLUDEDIAGONALATT 699
#define EMPTYIDATT 700
#define IDATT 701




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
#define YYLAST   2089

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  451
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  1177
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1759
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2464

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   701

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   448,
     450,     2,     2,   449,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   447,     2,     2,     2,     2,     2,     2,     2,
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446
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
    1362,  1364,  1366,  1368,  1372,  1380,  1381,  1383,  1384,  1386,
    1387,  1389,  1390,  1392,  1393,  1395,  1396,  1398,  1399,  1401,
    1402,  1405,  1409,  1411,  1413,  1414,  1417,  1419,  1421,  1423,
    1425,  1427,  1429,  1431,  1433,  1435,  1437,  1439,  1442,  1444,
    1448,  1450,  1452,  1454,  1457,  1461,  1463,  1464,  1467,  1469,
    1471,  1473,  1475,  1478,  1480,  1484,  1486,  1488,  1491,  1495,
    1497,  1499,  1500,  1503,  1505,  1507,  1509,  1511,  1513,  1515,
    1519,  1521,  1522,  1526,  1528,  1529,  1531,  1533,  1535,  1537,
    1541,  1545,  1546,  1550,  1552,  1554,  1556,  1558,  1561,  1563,
    1567,  1569,  1571,  1574,  1578,  1580,  1581,  1584,  1586,  1588,
    1592,  1593,  1596,  1598,  1600,  1602,  1604,  1608,  1616,  1617,
    1619,  1620,  1622,  1623,  1625,  1626,  1628,  1629,  1631,  1632,
    1634,  1635,  1637,  1638,  1641,  1645,  1647,  1649,  1650,  1653,
    1655,  1657,  1659,  1661,  1663,  1665,  1667,  1669,  1671,  1673,
    1675,  1678,  1680,  1684,  1686,  1688,  1690,  1693,  1697,  1699,
    1700,  1703,  1705,  1707,  1709,  1711,  1714,  1716,  1720,  1722,
    1724,  1727,  1731,  1733,  1735,  1736,  1739,  1741,  1743,  1745,
    1747,  1749,  1751,  1755,  1757,  1758,  1762,  1764,  1765,  1767,
    1769,  1771,  1773,  1777,  1781,  1782,  1786,  1788,  1790,  1792,
    1794,  1797,  1799,  1803,  1805,  1807,  1810,  1814,  1816,  1817,
    1820,  1822,  1824,  1828,  1829,  1832,  1834,  1836,  1838,  1840,
    1844,  1852,  1853,  1855,  1856,  1858,  1859,  1861,  1862,  1864,
    1865,  1867,  1868,  1870,  1871,  1873,  1874,  1877,  1881,  1883,
    1885,  1886,  1889,  1891,  1893,  1895,  1897,  1899,  1901,  1903,
    1905,  1907,  1909,  1911,  1914,  1916,  1920,  1922,  1924,  1926,
    1929,  1933,  1935,  1936,  1939,  1941,  1943,  1945,  1947,  1950,
    1952,  1956,  1958,  1960,  1963,  1967,  1969,  1971,  1972,  1975,
    1977,  1979,  1981,  1983,  1985,  1987,  1991,  1993,  1994,  1998,
    2000,  2001,  2003,  2005,  2007,  2009,  2014,  2015,  2019,  2021,
    2023,  2025,  2027,  2029,  2034,  2036,  2037,  2041,  2043,  2045,
    2047,  2049,  2051,  2055,  2057,  2058,  2061,  2062,  2065,  2069,
    2071,  2073,  2074,  2077,  2079,  2081,  2083,  2085,  2087,  2089,
    2091,  2093,  2095,  2097,  2099,  2102,  2104,  2108,  2110,  2112,
    2114,  2117,  2119,  2122,  2126,  2128,  2130,  2131,  2134,  2136,
    2138,  2140,  2142,  2144,  2146,  2150,  2152,  2153,  2156,  2158,
    2159,  2163,  2165,  2167,  2169,  2171,  2174,  2176,  2180,  2182,
    2184,  2187,  2191,  2193,  2195,  2196,  2199,  2201,  2203,  2205,
    2207,  2209,  2211,  2213,  2216,  2218,  2222,  2224,  2226,  2229,
    2231,  2233,  2235,  2237,  2239,  2243,  2245,  2246,  2250,  2252,
    2254,  2256,  2258,  2261,  2263,  2267,  2269,  2271,  2274,  2278,
    2280,  2282,  2283,  2286,  2288,  2290,  2292,  2294,  2296,  2298,
    2301,  2303,  2307,  2309,  2311,  2314,  2316,  2318,  2320,  2322,
    2324,  2328,  2330,  2335,  2340,  2345,  2350,  2355,  2360,  2365,
    2370,  2375,  2380,  2385,  2387,  2389,  2391,  2393,  2395,  2398,
    2399,  2402,  2404,  2406,  2408,  2410,  2413,  2415,  2417,  2419,
    2421,  2425,  2427,  2428,  2431,  2433,  2435,  2437,  2439,  2441,
    2443,  2445,  2447,  2449,  2451,  2455,  2457,  2459,  2461,  2463,
    2465,  2469,  2471,  2473,  2475,  2477,  2479,  2483,  2485,  2487,
    2489,  2491,  2493,  2497,  2499,  2501,  2503,  2505,  2507,  2511,
    2513,  2515,  2516,  2519,  2523,  2525,  2527,  2528,  2531,  2533,
    2535,  2539,  2543,  2545,  2547,  2550,  2552,  2556,  2558,  2560,
    2561,  2564,  2568,  2570,  2571,  2573,  2577,  2581,  2583,  2585,
    2588,  2590,  2594,  2596,  2597,  2600,  2604,  2606,  2607,  2609,
    2613,  2617,  2619,  2621,  2623,  2625,  2629,  2631,  2635,  2637,
    2639,  2641,  2643,  2647,  2649,  2653,  2655,  2657,  2659,  2661,
    2665,  2667,  2671,  2673,  2675,  2677,  2679,  2683,  2685,  2689,
    2691,  2693,  2695,  2697,  2701,  2703,  2707,  2709,  2711,  2713,
    2715,  2719,  2721,  2725,  2727,  2729,  2731,  2733,  2737,  2739,
    2741,  2745,  2747,  2749,  2750,  2753,  2755,  2757,  2759,  2761,
    2763,  2765,  2767,  2769,  2771,  2775,  2778,  2779,  2783,  2785,
    2787,  2788,  2791,  2793,  2795,  2797,  2799,  2801,  2803,  2805,
    2807,  2809,  2812,  2814,  2815,  2818,  2820,  2822,  2824,  2826,
    2828,  2830,  2832,  2834,  2836,  2838,  2840,  2845,  2847,  2849,
    2850,  2853,  2855,  2857,  2861,  2862,  2865,  2868,  2870,  2872,
    2874,  2876,  2880,  2882,  2885,  2887,  2889,  2891,  2893,  2897,
    2899,  2902,  2904,  2906,  2908,  2910,  2914,  2916,  2921,  2923,
    2925,  2926,  2929,  2931,  2933,  2937,  2938,  2941,  2944,  2946,
    2948,  2950,  2952,  2956,  2958,  2963,  2965,  2967,  2968,  2971,
    2973,  2975,  2979,  2980,  2983,  2984,  2987,  2989,  2991,  2993,
    2995,  2999,  3001,  3002,  3005,  3009,  3011,  3013,  3014,  3017,
    3019,  3021,  3023,  3025,  3027,  3031,  3032,  3035,  3039,  3041,
    3042,  3044,  3048,  3053,  3055,  3057,  3058,  3061,  3063,  3065,
    3069,  3070,  3073,  3074,  3077,  3079,  3081,  3083,  3085,  3089,
    3090,  3093,  3096,  3098,  3100,  3102,  3104,  3108,  3113,  3115,
    3117,  3118,  3121,  3123,  3125,  3129,  3130,  3133,  3134,  3137,
    3139,  3141,  3143,  3145,  3149,  3150,  3153,  3156,  3158,  3160,
    3162,  3164,  3168,  3173,  3175,  3177,  3178,  3181,  3183,  3185,
    3189,  3190,  3193,  3196,  3198,  3200,  3202,  3204,  3208,  3210,
    3215,  3217,  3219,  3220,  3223,  3225,  3227,  3231,  3232,  3235,
    3236,  3239,  3241,  3243,  3245,  3247,  3251,  3252,  3255,  3259,
    3261,  3262,  3265,  3267,  3269,  3271,  3275,  3280,  3282,  3284,
    3285,  3288,  3290,  3292,  3296,  3297,  3300,  3301,  3304,  3306,
    3308,  3310,  3312,  3316,  3317,  3320,  3324,  3326,  3327,  3330,
    3332,  3334,  3336,  3339,  3341,  3346,  3348,  3350,  3351,  3354,
    3356,  3358,  3362,  3363,  3366,  3369,  3371,  3373,  3375,  3377,
    3381,  3383,  3389,  3391,  3392,  3394,  3396,  3400,  3402,  3404,
    3410,  3412,  3416,  3418,  3420,  3422,  3424,  3426,  3430,  3432,
    3436,  3438,  3440,  3442,  3444,  3446,  3450,  3452,  3453,  3456,
    3460,  3462,  3464,  3465,  3468,  3470,  3472,  3474,  3476,  3478,
    3480,  3482,  3486,  3491,  3496,  3501,  3506,  3511,  3516,  3521,
    3526,  3531,  3536,  3541,  3546,  3551,  3556,  3561,  3566,  3571,
    3576,  3581,  3586,  3591,  3596,  3601,  3606,  3611,  3616,  3621,
    3626,  3631,  3636,  3641,  3646,  3651,  3656,  3658,  3660,  3662,
    3666,  3668,  3670,  3672,  3676,  3678,  3680,  3682,  3686,  3688,
    3690,  3692,  3696,  3698,  3700,  3702,  3706,  3708,  3710,  3712,
    3716,  3718,  3720,  3722,  3726,  3728,  3730,  3732,  3736,  3738,
    3740,  3742,  3746,  3748,  3750,  3752,  3756,  3758,  3760,  3762,
    3766,  3768,  3770,  3772,  3776,  3778,  3780,  3782,  3786,  3788,
    3790,  3792,  3796,  3798,  3800,  3802,  3806,  3808,  3810,  3812,
    3816,  3818,  3820,  3822,  3826,  3828,  3830,  3832,  3834,  3836,
    3838,  3840,  3842,  3844,  3846,  3848,  3850,  3852,  3854,  3856,
    3858,  3860,  3862,  3864,  3866,  3868,  3870,  3872,  3874,  3876,
    3878,  3880,  3881,  3885,  3887,  3890,  3891,  3895,  3897,  3900,
    3901,  3907,  3908,  3914,  3915,  3921,  3922,  3927,  3928,  3934,
    3935,  3941,  3942,  3947,  3948,  3953,  3954,  3959,  3960,  3965,
    3966,  3971,  3972,  3977,  3981,  3983,  3985,  3986,  3991,  3992,
    3999,  4000,  4005,  4006,  4011,  4012,  4017,  4021,  4023,  4025,
    4028,  4029,  4032,  4034,  4036,  4038,  4039,  4044,  4045,  4050,
    4052,  4055,  4056,  4061,  4062,  4065,  4067,  4069,  4074,  4079,
    4080,  4085,  4086,  4089,  4090,  4095,  4096,  4099,  4100,  4105,
    4106,  4109,  4110,  4115,  4116,  4119,  4120,  4125,  4126,  4129,
    4131,  4133,  4135,  4137,  4139,  4141,  4143,  4145,  4147,  4149,
    4151,  4153,  4155,  4157,  4159,  4161,  4163,  4165,  4167,  4171,
    4173,  4175,  4178,  4183,  4187,  4189,  4191,  4194,  4199,  4203,
    4205,  4207,  4210,  4215,  4219,  4221,  4223,  4226,  4231,  4234,
    4236,  4239,  4242,  4244,  4248,  4251,  4253,  4256,  4259,  4261,
    4264,  4269,  4271,  4272,  4274,  4277,  4282,  4284,  4285,  4287,
    4290,  4294,  4297,  4299,  4301,  4304,  4307,  4309,  4313,  4316,
    4318,  4321,  4324,  4326,  4330,  4333,  4335,  4339,  4340,  4345,
    4346,  4349,  4352,  4354,  4358,  4361,  4363,  4370,  4373,  4375
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     452,     0,    -1,   453,   461,   459,    -1,   454,   455,   456,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   457,    -1,
     458,    -1,    11,    -1,    10,   461,   459,    -1,   460,    -1,
      15,    -1,    -1,   462,   463,   543,   597,   649,   744,    -1,
      -1,  1093,    -1,    -1,   464,   465,    -1,   309,    -1,   466,
      -1,   467,    -1,    10,   310,    -1,    11,    -1,    10,   468,
     310,    -1,   469,    -1,   470,    -1,   469,   470,    -1,   471,
      -1,   487,    -1,   493,    -1,   499,    -1,   505,    -1,   511,
      -1,   517,    -1,   523,    -1,   529,    -1,   472,   473,   476,
      -1,    56,    -1,   474,    -1,   475,    -1,   474,   475,    -1,
    1474,    -1,  1447,    -1,  1086,    -1,   477,    -1,   478,    -1,
      10,    57,    -1,    11,    -1,    10,   479,    57,    -1,   480,
      -1,   481,    -1,   480,   481,    -1,   482,   483,   486,    -1,
      88,    -1,   484,    -1,    -1,   484,   485,    -1,  1456,    -1,
    1447,    -1,    10,    89,    -1,    11,    -1,   488,   489,    -1,
      60,    -1,   490,    -1,   491,    -1,    10,    61,    -1,    11,
      -1,    10,   492,    61,    -1,     4,    -1,   494,   495,    -1,
     333,    -1,   496,    -1,   497,    -1,    10,   334,    -1,    11,
      -1,    10,   498,   334,    -1,     4,    -1,   500,   501,    -1,
     335,    -1,   502,    -1,   503,    -1,    10,   336,    -1,    11,
      -1,    10,   504,   336,    -1,     4,    -1,   506,   507,    -1,
     337,    -1,   508,    -1,   509,    -1,    10,   338,    -1,    11,
      -1,    10,   510,   338,    -1,     4,    -1,   512,   513,    -1,
     339,    -1,   514,    -1,   515,    -1,    10,   340,    -1,    11,
      -1,    10,   516,   340,    -1,     4,    -1,   518,   519,    -1,
      80,    -1,   520,    -1,   521,    -1,    10,    81,    -1,    11,
      -1,    10,   522,    81,    -1,     4,    -1,   524,   525,    -1,
      96,    -1,   526,    -1,   527,    -1,    10,    97,    -1,    11,
      -1,    10,   528,    97,    -1,     4,    -1,   530,   531,   532,
      -1,    66,    -1,  1081,    -1,   533,    -1,   534,    -1,    10,
      67,    -1,    11,    -1,    10,   535,    67,    -1,   536,    -1,
     537,    -1,   536,   537,    -1,   538,   539,   542,    -1,   341,
      -1,   540,    -1,    -1,   540,   541,    -1,  1456,    -1,  1480,
      -1,  1447,    -1,    10,   342,    -1,    11,    -1,    -1,   544,
     545,    -1,   311,    -1,   546,    -1,   547,    -1,    10,   312,
      -1,    11,    -1,    10,   548,   312,    -1,   549,    -1,   550,
      -1,   549,   550,    -1,   551,    -1,   557,    -1,   564,    -1,
     571,    -1,   578,    -1,   583,    -1,   552,   553,    -1,    90,
      -1,   554,    -1,   555,    -1,    10,    91,    -1,    11,    -1,
      10,   556,    91,    -1,     4,    -1,   558,   559,   562,    -1,
      40,    -1,   560,    -1,    -1,   560,   561,    -1,  1477,    -1,
    1447,    -1,    10,   563,    41,    -1,  1088,    -1,   565,   566,
     569,    -1,    42,    -1,   567,    -1,    -1,   567,   568,    -1,
    1477,    -1,  1447,    -1,    10,   570,    43,    -1,  1088,    -1,
     572,   573,   576,    -1,    38,    -1,   574,    -1,    -1,   574,
     575,    -1,  1477,    -1,  1447,    -1,    10,   577,    39,    -1,
    1088,    -1,   579,   580,   581,    -1,    36,    -1,    -1,  1447,
      -1,    10,   582,    37,    -1,     6,    -1,   584,   585,   586,
      -1,    66,    -1,  1081,    -1,   587,    -1,   588,    -1,    10,
      67,    -1,    11,    -1,    10,   589,    67,    -1,   590,    -1,
     591,    -1,   590,   591,    -1,   592,   593,   596,    -1,   341,
      -1,   594,    -1,    -1,   594,   595,    -1,  1456,    -1,  1480,
      -1,  1447,    -1,    10,   342,    -1,    11,    -1,    -1,   598,
     599,    -1,   313,    -1,   600,    -1,   601,    -1,    10,   314,
      -1,    11,    -1,    10,   602,   314,    -1,   603,    -1,   604,
      -1,   603,   604,    -1,   605,    -1,   611,    -1,   617,    -1,
     623,    -1,   629,    -1,   635,    -1,   606,   607,    -1,    48,
      -1,   608,    -1,   609,    -1,    10,    49,    -1,    11,    -1,
      10,   610,    49,    -1,     4,    -1,   612,   613,    -1,    46,
      -1,   614,    -1,   615,    -1,    10,    47,    -1,    11,    -1,
      10,   616,    47,    -1,     6,    -1,   618,   619,    -1,   100,
      -1,   620,    -1,   621,    -1,    10,   101,    -1,    11,    -1,
      10,   622,   101,    -1,     6,    -1,   624,   625,    -1,    94,
      -1,   626,    -1,   627,    -1,    10,    95,    -1,    11,    -1,
      10,   628,    95,    -1,     4,    -1,   630,   631,    -1,    76,
      -1,   632,    -1,   633,    -1,    10,    77,    -1,    11,    -1,
      10,   634,    77,    -1,  1088,    -1,   636,   637,   638,    -1,
      66,    -1,  1081,    -1,   639,    -1,   640,    -1,    10,    67,
      -1,    11,    -1,    10,   641,    67,    -1,   642,    -1,   643,
      -1,   642,   643,    -1,   644,   645,   648,    -1,   341,    -1,
     646,    -1,    -1,   646,   647,    -1,  1456,    -1,  1480,    -1,
    1447,    -1,    10,   342,    -1,    11,    -1,    -1,   650,   651,
      -1,   315,    -1,   652,    -1,   653,    -1,    10,   316,    -1,
      11,    -1,    10,   654,   316,    -1,   655,    -1,   656,    -1,
     655,   656,    -1,   657,    -1,   663,    -1,   669,    -1,   675,
      -1,   681,    -1,   687,    -1,   704,    -1,   711,    -1,   718,
      -1,   725,    -1,   730,    -1,   658,   659,    -1,    84,    -1,
     660,    -1,   661,    -1,    10,    85,    -1,    11,    -1,    10,
     662,    85,    -1,     4,    -1,   664,   665,    -1,    86,    -1,
     666,    -1,   667,    -1,    10,    87,    -1,    11,    -1,    10,
     668,    87,    -1,     4,    -1,   670,   671,    -1,    74,    -1,
     672,    -1,   673,    -1,    10,    75,    -1,    11,    -1,    10,
     674,    75,    -1,     4,    -1,   676,   677,    -1,    34,    -1,
     678,    -1,   679,    -1,    10,    35,    -1,    11,    -1,    10,
     680,    35,    -1,     4,    -1,   682,   683,    -1,    52,    -1,
     684,    -1,   685,    -1,    10,    53,    -1,    11,    -1,    10,
     686,    53,    -1,     4,    -1,   688,   689,   690,    -1,    98,
      -1,  1087,    -1,   691,    -1,   692,    -1,    10,    99,    -1,
      11,    -1,    10,   693,    99,    -1,   694,    -1,   695,    -1,
     694,   695,    -1,   696,   697,   699,    -1,    92,    -1,    -1,
     697,   698,    -1,  1477,    -1,  1474,    -1,  1441,    -1,  1447,
      -1,   700,    -1,   701,    -1,    10,    93,    -1,    11,    -1,
      10,   702,    93,    -1,   703,    -1,     7,    -1,     6,    -1,
     705,   706,   709,    -1,   106,    -1,   707,    -1,    -1,   707,
     708,    -1,  1477,    -1,  1447,    -1,    10,   710,   107,    -1,
    1088,    -1,   712,   713,   716,    -1,   108,    -1,   714,    -1,
      -1,   714,   715,    -1,  1477,    -1,  1447,    -1,    10,   717,
     109,    -1,  1088,    -1,   719,   720,   723,    -1,   104,    -1,
     721,    -1,    -1,   721,   722,    -1,  1477,    -1,  1447,    -1,
      10,   724,   105,    -1,  1088,    -1,   726,   727,   728,    -1,
     102,    -1,    -1,  1447,    -1,    10,   729,   103,    -1,     6,
      -1,   731,   732,   733,    -1,    66,    -1,  1081,    -1,   734,
      -1,   735,    -1,    10,    67,    -1,    11,    -1,    10,   736,
      67,    -1,   737,    -1,   738,    -1,   737,   738,    -1,   739,
     740,   743,    -1,   341,    -1,   741,    -1,    -1,   741,   742,
      -1,  1456,    -1,  1480,    -1,  1447,    -1,    10,   342,    -1,
      11,    -1,    -1,   745,   746,   749,    -1,   317,    -1,   747,
      -1,    -1,   747,   748,    -1,  1084,    -1,  1418,    -1,  1407,
      -1,  1413,    -1,   750,    -1,   751,    -1,    10,   318,    -1,
      11,    -1,    10,   752,   318,    -1,   753,  1054,    -1,   754,
      -1,   753,   754,    -1,   755,   756,   762,    -1,    78,    -1,
     757,    -1,    -1,   757,   758,    -1,   759,    -1,   760,    -1,
     761,    -1,    33,  1090,     6,  1090,    -1,    18,     3,  1090,
      -1,    16,     3,  1090,    -1,    10,   763,   779,   785,   863,
     925,   987,  1031,    79,    -1,   764,   765,   768,    -1,    84,
      -1,   766,    -1,   767,    -1,   766,   767,    -1,  1474,    -1,
    1447,    -1,  1086,    -1,   769,    -1,   770,    -1,    10,    85,
      -1,    11,    -1,    10,   771,    85,    -1,   772,    -1,   773,
      -1,   772,   773,    -1,   774,   775,   778,    -1,    88,    -1,
     776,    -1,    -1,   776,   777,    -1,  1474,    -1,  1447,    -1,
      10,    89,    -1,    11,    -1,    -1,   780,   781,    -1,    60,
      -1,   782,    -1,   783,    -1,    10,    61,    -1,    11,    -1,
      10,   784,    61,    -1,     4,    -1,    -1,   786,   787,   788,
      -1,   307,    -1,    -1,  1083,    -1,   789,    -1,   790,    -1,
      11,    -1,    10,   791,   308,    -1,   792,   805,   821,   834,
      -1,    -1,   793,   794,   795,    -1,   144,    -1,  1416,    -1,
     796,    -1,   797,    -1,    10,   145,    -1,    11,    -1,    10,
     798,   145,    -1,   799,    -1,   800,    -1,   799,   800,    -1,
     801,   802,   804,    -1,   305,    -1,    -1,   802,   803,    -1,
    1427,    -1,  1456,    -1,    10,  1088,   306,    -1,    -1,   806,
     807,   808,    -1,   110,    -1,  1416,    -1,   809,    -1,   810,
      -1,    10,   111,    -1,    11,    -1,    10,   811,   111,    -1,
     812,    -1,   813,    -1,   812,   813,    -1,   814,   815,   817,
      -1,   305,    -1,    -1,   815,   816,    -1,  1427,    -1,  1456,
      -1,   818,    -1,   819,    -1,    10,   306,    -1,    11,    -1,
      10,   820,   306,    -1,     4,    -1,    -1,   822,   823,    -1,
      44,    -1,   824,    -1,   825,    -1,    11,    -1,    10,   826,
      45,    -1,   827,   828,   829,   830,   831,   832,   833,    -1,
      -1,  1149,    -1,    -1,  1155,    -1,    -1,  1161,    -1,    -1,
    1167,    -1,    -1,  1173,    -1,    -1,  1179,    -1,    -1,  1185,
      -1,    -1,   834,   835,    -1,   836,   837,   840,    -1,   341,
      -1,   838,    -1,    -1,   838,   839,    -1,  1416,    -1,  1409,
      -1,  1480,    -1,  1468,    -1,  1456,    -1,  1474,    -1,  1486,
      -1,  1450,    -1,  1447,    -1,   841,    -1,   842,    -1,    10,
     342,    -1,    11,    -1,    10,   843,   342,    -1,   844,    -1,
     853,    -1,   845,    -1,   844,   845,    -1,   846,   847,   849,
      -1,   305,    -1,    -1,   847,   848,    -1,  1427,    -1,  1456,
      -1,   850,    -1,   851,    -1,    10,   306,    -1,    11,    -1,
      10,   852,   306,    -1,  1089,    -1,   854,    -1,   853,   854,
      -1,   855,   856,   859,    -1,   150,    -1,   857,    -1,    -1,
     857,   858,    -1,  1408,    -1,  1480,    -1,  1447,    -1,   860,
      -1,   861,    -1,    11,    -1,    10,   862,   151,    -1,  1121,
      -1,    -1,   864,   865,   866,    -1,   303,    -1,    -1,  1080,
      -1,   867,    -1,   868,    -1,    11,    -1,    10,   869,   304,
      -1,   870,   883,   896,    -1,    -1,   871,   872,   873,    -1,
     144,    -1,  1412,    -1,   874,    -1,   875,    -1,    10,   145,
      -1,    11,    -1,    10,   876,   145,    -1,   877,    -1,   878,
      -1,   877,   878,    -1,   879,   880,   882,    -1,   301,    -1,
      -1,   880,   881,    -1,  1427,    -1,  1456,    -1,    10,  1088,
     302,    -1,    -1,   884,   885,    -1,    44,    -1,   886,    -1,
     887,    -1,    11,    -1,    10,   888,    45,    -1,   889,   890,
     891,   892,   893,   894,   895,    -1,    -1,  1149,    -1,    -1,
    1155,    -1,    -1,  1161,    -1,    -1,  1167,    -1,    -1,  1173,
      -1,    -1,  1179,    -1,    -1,  1185,    -1,    -1,   896,   897,
      -1,   898,   899,   902,    -1,   341,    -1,   900,    -1,    -1,
     900,   901,    -1,  1412,    -1,  1409,    -1,  1480,    -1,  1468,
      -1,  1456,    -1,  1474,    -1,  1459,    -1,  1450,    -1,  1447,
      -1,   903,    -1,   904,    -1,    10,   342,    -1,    11,    -1,
      10,   905,   342,    -1,   906,    -1,   915,    -1,   907,    -1,
     906,   907,    -1,   908,   909,   911,    -1,   301,    -1,    -1,
     909,   910,    -1,  1427,    -1,  1456,    -1,   912,    -1,   913,
      -1,    10,   302,    -1,    11,    -1,    10,   914,   302,    -1,
    1089,    -1,   916,    -1,   915,   916,    -1,   917,   918,   921,
      -1,   150,    -1,   919,    -1,    -1,   919,   920,    -1,  1408,
      -1,  1480,    -1,  1447,    -1,   922,    -1,   923,    -1,    11,
      -1,    10,   924,   151,    -1,  1121,    -1,    -1,   926,   927,
     928,    -1,   299,    -1,    -1,  1077,    -1,   929,    -1,   930,
      -1,    11,    -1,    10,   931,   300,    -1,   932,   945,   958,
      -1,    -1,   933,   934,   935,    -1,    50,    -1,  1406,    -1,
     936,    -1,   937,    -1,    10,    51,    -1,    11,    -1,    10,
     938,    51,    -1,   939,    -1,   940,    -1,   939,   940,    -1,
     941,   942,   944,    -1,   297,    -1,    -1,   942,   943,    -1,
    1427,    -1,  1456,    -1,    10,  1088,   298,    -1,    -1,   946,
     947,    -1,    44,    -1,   948,    -1,   949,    -1,    11,    -1,
      10,   950,    45,    -1,   951,   952,   953,   954,   955,   956,
     957,    -1,    -1,  1149,    -1,    -1,  1155,    -1,    -1,  1161,
      -1,    -1,  1167,    -1,    -1,  1173,    -1,    -1,  1179,    -1,
      -1,  1185,    -1,    -1,   958,   959,    -1,   960,   961,   964,
      -1,   341,    -1,   962,    -1,    -1,   962,   963,    -1,  1406,
      -1,  1409,    -1,  1480,    -1,  1468,    -1,  1456,    -1,  1474,
      -1,  1444,    -1,  1450,    -1,  1447,    -1,   965,    -1,   966,
      -1,    10,   342,    -1,    11,    -1,    10,   967,   342,    -1,
     968,    -1,   977,    -1,   969,    -1,   968,   969,    -1,   970,
     971,   973,    -1,   297,    -1,    -1,   971,   972,    -1,  1427,
      -1,  1456,    -1,   974,    -1,   975,    -1,    10,   298,    -1,
      11,    -1,    10,   976,   298,    -1,  1089,    -1,   978,    -1,
     977,   978,    -1,   979,   980,   983,    -1,   150,    -1,   981,
      -1,    -1,   981,   982,    -1,  1408,    -1,  1480,    -1,  1447,
      -1,   984,    -1,   985,    -1,    11,    -1,    10,   986,   151,
      -1,  1121,    -1,    -1,   988,   989,   990,    -1,   283,    -1,
      -1,  1078,    -1,   991,    -1,   992,    -1,    11,    -1,    10,
     993,  1029,   284,    -1,    -1,   994,   995,   996,    -1,   285,
      -1,  1079,    -1,   997,    -1,   998,    -1,    11,    -1,    10,
    1000,  1008,   999,    -1,   286,    -1,    -1,  1001,  1002,  1003,
      -1,   144,    -1,  1411,    -1,  1004,    -1,  1005,    -1,    11,
      -1,    10,  1007,  1006,    -1,   145,    -1,    -1,  1007,  1192,
      -1,    -1,  1008,  1009,    -1,  1010,  1011,  1014,    -1,   341,
      -1,  1012,    -1,    -1,  1012,  1013,    -1,  1411,    -1,  1409,
      -1,  1480,    -1,  1468,    -1,  1456,    -1,  1474,    -1,  1453,
      -1,  1450,    -1,  1447,    -1,  1015,    -1,  1016,    -1,    10,
     342,    -1,    11,    -1,    10,  1017,   342,    -1,  1019,    -1,
    1018,    -1,  1192,    -1,  1018,  1192,    -1,  1020,    -1,  1019,
    1020,    -1,  1021,  1022,  1025,    -1,   150,    -1,  1023,    -1,
      -1,  1023,  1024,    -1,  1408,    -1,  1480,    -1,  1447,    -1,
    1026,    -1,  1027,    -1,    11,    -1,    10,  1028,   151,    -1,
    1121,    -1,    -1,  1029,  1030,    -1,   118,    -1,    -1,  1032,
    1033,  1034,    -1,    70,    -1,  1082,    -1,  1035,    -1,  1036,
      -1,    10,    71,    -1,    11,    -1,    10,  1037,    71,    -1,
    1038,    -1,  1039,    -1,  1038,  1039,    -1,  1040,  1041,  1044,
      -1,    68,    -1,  1042,    -1,    -1,  1042,  1043,    -1,  1456,
      -1,  1480,    -1,  1441,    -1,  1447,    -1,  1410,    -1,  1045,
      -1,  1046,    -1,    10,    69,    -1,    11,    -1,    10,  1047,
      69,    -1,  1048,    -1,  1049,    -1,  1048,  1049,    -1,  1050,
      -1,  1051,    -1,  1052,    -1,   155,    -1,   152,    -1,   153,
    1053,   154,    -1,     5,    -1,    -1,  1055,  1056,  1057,    -1,
      72,    -1,  1085,    -1,  1058,    -1,  1059,    -1,    10,    73,
      -1,    11,    -1,    10,  1060,    73,    -1,  1061,    -1,  1062,
      -1,  1061,  1062,    -1,  1063,  1064,  1067,    -1,    82,    -1,
    1065,    -1,    -1,  1065,  1066,    -1,  1456,    -1,  1441,    -1,
    1447,    -1,  1410,    -1,  1068,    -1,  1069,    -1,    10,    83,
      -1,    11,    -1,    10,  1070,    83,    -1,  1071,    -1,  1072,
      -1,  1071,  1072,    -1,  1073,    -1,  1074,    -1,  1075,    -1,
     155,    -1,   152,    -1,   153,  1076,   154,    -1,     5,    -1,
      20,  1090,     6,  1090,    -1,    28,  1090,     6,  1090,    -1,
      29,  1090,     6,  1090,    -1,    21,  1090,     6,  1090,    -1,
      22,  1090,     6,  1090,    -1,    23,  1090,     6,  1090,    -1,
      24,  1090,     6,  1090,    -1,    25,  1090,     6,  1090,    -1,
      30,  1090,     6,  1090,    -1,    31,  1090,     6,  1090,    -1,
      32,  1090,     6,  1090,    -1,     6,    -1,     7,    -1,     4,
      -1,     6,    -1,     7,    -1,  1091,     8,    -1,    -1,  1091,
    1092,    -1,   447,    -1,   448,    -1,   449,    -1,   450,    -1,
    1094,  1095,    -1,   120,    -1,  1096,    -1,  1097,    -1,    11,
      -1,    10,  1098,   121,    -1,  1099,    -1,    -1,  1099,  1100,
      -1,  1101,    -1,  1105,    -1,  1109,    -1,  1113,    -1,  1117,
      -1,  1102,    -1,  1103,    -1,  1104,    -1,   125,    -1,   124,
      -1,   122,     5,   123,    -1,  1106,    -1,  1107,    -1,  1108,
      -1,   129,    -1,   128,    -1,   126,     5,   127,    -1,  1110,
      -1,  1111,    -1,  1112,    -1,   133,    -1,   132,    -1,   130,
       5,   131,    -1,  1114,    -1,  1115,    -1,  1116,    -1,   137,
      -1,   136,    -1,   134,     5,   135,    -1,  1118,    -1,  1119,
      -1,  1120,    -1,   141,    -1,   140,    -1,   138,     5,   139,
      -1,  1122,    -1,  1129,    -1,    -1,  1122,  1123,    -1,  1124,
    1125,  1128,    -1,   148,    -1,  1126,    -1,    -1,  1126,  1127,
      -1,  1430,    -1,  1428,    -1,    10,     6,   149,    -1,   156,
    1419,  1130,    -1,  1131,    -1,  1132,    -1,    10,   157,    -1,
      11,    -1,    10,     4,   157,    -1,  1134,    -1,  1139,    -1,
      -1,  1134,  1135,    -1,  1136,  1137,  1138,    -1,   148,    -1,
      -1,  1430,    -1,    10,  1088,   149,    -1,   156,  1419,  1140,
      -1,  1141,    -1,  1142,    -1,    10,   157,    -1,    11,    -1,
      10,     4,   157,    -1,  1144,    -1,    -1,  1144,  1145,    -1,
    1146,  1147,  1148,    -1,   148,    -1,    -1,  1430,    -1,    10,
       4,   149,    -1,  1150,  1191,  1151,    -1,   325,    -1,  1152,
      -1,  1153,    -1,    11,    -1,    10,  1154,   326,    -1,  1121,
      -1,  1156,  1191,  1157,    -1,   321,    -1,  1158,    -1,  1159,
      -1,    11,    -1,    10,  1160,   322,    -1,  1121,    -1,  1162,
    1191,  1163,    -1,   323,    -1,  1164,    -1,  1165,    -1,    11,
      -1,    10,  1166,   324,    -1,  1121,    -1,  1168,  1191,  1169,
      -1,   319,    -1,  1170,    -1,  1171,    -1,    11,    -1,    10,
    1172,   320,    -1,  1121,    -1,  1174,  1191,  1175,    -1,   327,
      -1,  1176,    -1,  1177,    -1,    11,    -1,    10,  1178,   328,
      -1,  1121,    -1,  1180,  1191,  1181,    -1,   329,    -1,  1182,
      -1,  1183,    -1,    11,    -1,    10,  1184,   330,    -1,  1121,
      -1,  1186,  1191,  1187,    -1,   331,    -1,  1188,    -1,  1189,
      -1,    11,    -1,    10,  1190,   332,    -1,  1121,    -1,  1408,
      -1,  1193,  1194,  1197,    -1,   287,    -1,  1195,    -1,    -1,
    1195,  1196,    -1,  1471,    -1,  1414,    -1,  1405,    -1,  1456,
      -1,  1474,    -1,  1429,    -1,  1198,    -1,  1199,    -1,    11,
      -1,    10,  1200,   288,    -1,  1201,  1207,    -1,    -1,  1202,
    1203,  1206,    -1,   244,    -1,  1204,    -1,    -1,  1204,  1205,
      -1,  1420,    -1,  1431,    -1,  1432,    -1,  1421,    -1,  1422,
      -1,  1423,    -1,  1424,    -1,  1438,    -1,  1437,    -1,    10,
     243,    -1,    11,    -1,    -1,  1207,  1208,    -1,  1209,    -1,
    1234,    -1,  1247,    -1,  1274,    -1,  1310,    -1,  1323,    -1,
    1341,    -1,  1292,    -1,  1359,    -1,  1372,    -1,  1376,    -1,
    1210,  1211,    10,  1214,    -1,   255,    -1,  1212,    -1,    -1,
    1212,  1213,    -1,  1415,    -1,  1462,    -1,  1216,  1215,   256,
      -1,    -1,  1222,  1228,    -1,  1217,  1218,    -1,   273,    -1,
    1219,    -1,  1220,    -1,    11,    -1,    10,  1221,   274,    -1,
    1121,    -1,  1223,  1224,    -1,   275,    -1,  1225,    -1,  1226,
      -1,    11,    -1,    10,  1227,   276,    -1,  1121,    -1,  1229,
    1230,    -1,   277,    -1,  1231,    -1,  1232,    -1,    11,    -1,
      10,  1233,   278,    -1,  1133,    -1,  1235,  1236,    10,  1239,
      -1,   259,    -1,  1237,    -1,    -1,  1237,  1238,    -1,  1415,
      -1,  1462,    -1,  1216,  1240,   260,    -1,    -1,  1222,  1241,
      -1,  1242,  1243,    -1,   277,    -1,  1244,    -1,  1245,    -1,
      11,    -1,    10,  1246,   278,    -1,  1121,    -1,  1248,  1249,
      10,  1252,    -1,   261,    -1,  1250,    -1,    -1,  1250,  1251,
      -1,  1415,    -1,  1462,    -1,  1216,  1253,   262,    -1,    -1,
    1222,  1254,    -1,    -1,  1255,  1256,    -1,   277,    -1,  1257,
      -1,  1258,    -1,    11,    -1,    10,  1259,   278,    -1,  1260,
      -1,    -1,  1260,  1261,    -1,  1262,  1263,  1266,    -1,   148,
      -1,  1264,    -1,    -1,  1264,  1265,    -1,  1417,    -1,  1434,
      -1,  1267,    -1,  1268,    -1,    11,    -1,    10,  1269,   149,
      -1,    -1,  1269,  1270,    -1,  1271,  1272,  1273,    -1,   279,
      -1,    -1,  1433,    -1,    10,     6,   280,    -1,  1275,  1276,
      10,  1279,    -1,   267,    -1,  1277,    -1,    -1,  1277,  1278,
      -1,  1415,    -1,  1462,    -1,  1216,  1280,   268,    -1,    -1,
    1222,  1281,    -1,    -1,  1282,  1283,    -1,   277,    -1,  1284,
      -1,  1285,    -1,    11,    -1,    10,  1286,   278,    -1,    -1,
    1286,  1287,    -1,  1288,  1289,    -1,   148,    -1,  1290,    -1,
    1291,    -1,    11,    -1,    10,  1489,   149,    -1,  1293,  1294,
      10,  1297,    -1,   269,    -1,  1295,    -1,    -1,  1295,  1296,
      -1,  1415,    -1,  1462,    -1,  1216,  1298,   270,    -1,    -1,
    1222,  1299,    -1,    -1,  1300,  1301,    -1,   277,    -1,  1302,
      -1,  1303,    -1,    11,    -1,    10,  1304,   278,    -1,    -1,
    1304,  1305,    -1,  1306,  1307,    -1,   148,    -1,  1308,    -1,
    1309,    -1,    11,    -1,    10,  1489,   149,    -1,  1311,  1312,
      10,  1315,    -1,   265,    -1,  1313,    -1,    -1,  1313,  1314,
      -1,  1415,    -1,  1462,    -1,  1216,  1316,   266,    -1,    -1,
    1222,  1317,    -1,  1318,  1319,    -1,   277,    -1,  1320,    -1,
    1321,    -1,    11,    -1,    10,  1322,   278,    -1,  1121,    -1,
    1324,  1325,    10,  1328,    -1,   263,    -1,  1326,    -1,    -1,
    1326,  1327,    -1,  1415,    -1,  1462,    -1,  1216,  1329,   264,
      -1,    -1,  1222,  1330,    -1,    -1,  1331,  1332,    -1,   277,
      -1,  1333,    -1,  1334,    -1,    11,    -1,    10,  1335,   278,
      -1,    -1,  1335,  1336,    -1,  1337,  1338,  1340,    -1,   148,
      -1,    -1,  1338,  1339,    -1,  1483,    -1,  1430,    -1,  1428,
      -1,    10,     6,   149,    -1,  1342,  1343,    10,  1346,    -1,
     257,    -1,  1344,    -1,    -1,  1344,  1345,    -1,  1415,    -1,
    1462,    -1,  1216,  1347,   258,    -1,    -1,  1222,  1348,    -1,
      -1,  1349,  1350,    -1,   277,    -1,  1351,    -1,  1352,    -1,
      11,    -1,    10,  1353,   278,    -1,    -1,  1353,  1354,    -1,
    1355,  1356,  1358,    -1,   148,    -1,    -1,  1356,  1357,    -1,
    1436,    -1,  1435,    -1,  1430,    -1,    10,   149,    -1,    11,
      -1,  1360,  1361,    10,  1364,    -1,   271,    -1,  1362,    -1,
      -1,  1362,  1363,    -1,  1415,    -1,  1462,    -1,  1216,  1365,
     272,    -1,    -1,  1222,  1366,    -1,  1367,  1368,    -1,   277,
      -1,  1369,    -1,  1370,    -1,    11,    -1,    10,  1371,   278,
      -1,  1143,    -1,  1373,  1374,    10,  1563,  1375,    -1,   281,
      -1,    -1,  1465,    -1,   282,    -1,  1377,  1378,  1379,    -1,
     245,    -1,  1404,    -1,    10,  1381,  1388,  1395,  1380,    -1,
     246,    -1,  1382,  1383,  1384,    -1,   249,    -1,  1408,    -1,
    1385,    -1,  1386,    -1,    11,    -1,    10,  1387,   250,    -1,
    1121,    -1,  1389,  1390,  1391,    -1,   251,    -1,  1408,    -1,
    1392,    -1,  1393,    -1,    11,    -1,    10,  1394,   252,    -1,
    1121,    -1,    -1,  1395,  1396,    -1,  1397,  1398,  1401,    -1,
     247,    -1,  1399,    -1,    -1,  1399,  1400,    -1,  1425,    -1,
    1426,    -1,  1471,    -1,  1474,    -1,  1402,    -1,  1403,    -1,
      11,    -1,    10,  1200,   248,    -1,   201,     8,     6,     8,
      -1,   202,     8,     6,     8,    -1,   207,     8,     6,     8,
      -1,   206,     8,     6,     8,    -1,   158,     8,     6,     8,
      -1,   159,     8,     6,     8,    -1,   160,     8,     6,     8,
      -1,   217,     8,     6,     8,    -1,   210,     8,     6,     8,
      -1,   209,     8,     6,     8,    -1,   203,     8,     6,     8,
      -1,   205,     8,     6,     8,    -1,   213,     8,     6,     8,
      -1,   214,     8,     6,     8,    -1,   212,     8,     6,     8,
      -1,   236,     8,     6,     8,    -1,   218,     8,     6,     8,
      -1,   221,     8,     6,     8,    -1,   222,     8,     6,     8,
      -1,   223,     8,     6,     8,    -1,   224,     8,     6,     8,
      -1,   226,     8,     6,     8,    -1,   227,     8,     6,     8,
      -1,   233,     8,     6,     8,    -1,   234,     8,     6,     8,
      -1,   230,  1090,     6,  1090,    -1,   235,     8,     6,     8,
      -1,   219,     8,     6,     8,    -1,   220,     8,     6,     8,
      -1,   237,     8,  1088,     8,    -1,   238,     8,  1088,     8,
      -1,   229,     8,  1088,     8,    -1,   228,     8,  1088,     8,
      -1,   225,     8,  1088,     8,    -1,  1439,    -1,  1440,    -1,
     199,    -1,   200,     3,  1090,    -1,  1442,    -1,  1443,    -1,
     161,    -1,   162,     3,     8,    -1,  1445,    -1,  1446,    -1,
     181,    -1,   182,     3,     8,    -1,  1448,    -1,  1449,    -1,
     163,    -1,   164,     3,     8,    -1,  1451,    -1,  1452,    -1,
     171,    -1,   172,     3,     8,    -1,  1454,    -1,  1455,    -1,
     191,    -1,   192,     3,     8,    -1,  1457,    -1,  1458,    -1,
     167,    -1,   168,     3,     8,    -1,  1460,    -1,  1461,    -1,
     183,    -1,   184,     3,     8,    -1,  1463,    -1,  1464,    -1,
     197,    -1,   198,     3,     8,    -1,  1466,    -1,  1467,    -1,
     173,    -1,   174,     3,     8,    -1,  1469,    -1,  1470,    -1,
     165,    -1,   166,     3,     8,    -1,  1472,    -1,  1473,    -1,
     195,    -1,   196,     3,     8,    -1,  1475,    -1,  1476,    -1,
     169,    -1,   170,     3,     8,    -1,  1478,    -1,  1479,    -1,
     175,    -1,   176,     3,     8,    -1,  1481,    -1,  1482,    -1,
     177,    -1,   178,     3,     8,    -1,  1484,    -1,  1485,    -1,
     179,    -1,   180,     3,     8,    -1,  1487,    -1,  1488,    -1,
     185,    -1,   186,     3,     8,    -1,  1533,    -1,  1540,    -1,
    1496,    -1,  1498,    -1,  1548,    -1,  1500,    -1,  1502,    -1,
    1504,    -1,  1506,    -1,  1560,    -1,  1508,    -1,  1510,    -1,
    1512,    -1,  1516,    -1,  1514,    -1,  1518,    -1,  1525,    -1,
    1520,    -1,  1523,    -1,  1554,    -1,  1557,    -1,  1490,    -1,
    1493,    -1,  1551,    -1,  1527,    -1,  1529,    -1,  1531,    -1,
      -1,   397,  1491,  1492,    -1,    11,    -1,    10,   398,    -1,
      -1,   399,  1494,  1495,    -1,    11,    -1,    10,   400,    -1,
      -1,   401,  1497,  1489,  1489,   402,    -1,    -1,   359,  1499,
    1489,  1489,   360,    -1,    -1,   361,  1501,  1489,  1489,   362,
      -1,    -1,   375,  1503,  1489,   376,    -1,    -1,   363,  1505,
    1489,  1489,   364,    -1,    -1,   357,  1507,  1489,  1489,   358,
      -1,    -1,   365,  1509,  1489,   366,    -1,    -1,   367,  1511,
    1489,   368,    -1,    -1,   379,  1513,  1489,   380,    -1,    -1,
     381,  1515,  1489,   382,    -1,    -1,   383,  1517,  1489,   384,
      -1,    -1,   373,  1519,  1489,   374,    -1,  1521,  1489,  1522,
      -1,   387,    -1,   388,    -1,    -1,   389,  1524,  1489,   390,
      -1,    -1,   377,  1526,  1489,  1489,  1489,   378,    -1,    -1,
     405,  1528,  1563,   406,    -1,    -1,   407,  1530,  1563,   408,
      -1,    -1,   409,  1532,  1563,   410,    -1,  1534,  1536,  1535,
      -1,   403,    -1,    11,    -1,    10,   404,    -1,    -1,  1536,
    1537,    -1,  1474,    -1,  1480,    -1,  1538,    -1,    -1,   446,
       3,  1539,     8,    -1,    -1,   385,  1541,  1544,  1542,    -1,
      11,    -1,    10,   386,    -1,    -1,    10,  1489,  1543,   386,
      -1,    -1,  1544,  1545,    -1,  1546,    -1,  1547,    -1,   237,
       8,  1088,     8,    -1,   233,     8,     6,     8,    -1,    -1,
     369,  1549,  1550,   370,    -1,    -1,  1550,  1489,    -1,    -1,
     393,  1552,  1553,   394,    -1,    -1,  1553,  1489,    -1,    -1,
     391,  1555,  1556,   392,    -1,    -1,  1556,  1489,    -1,    -1,
     395,  1558,  1559,   396,    -1,    -1,  1559,  1489,    -1,    -1,
     371,  1561,  1562,   372,    -1,    -1,  1562,  1489,    -1,  1564,
      -1,  1568,    -1,  1572,    -1,  1576,    -1,  1580,    -1,  1583,
      -1,  1589,    -1,  1592,    -1,  1596,    -1,  1601,    -1,  1604,
      -1,  1607,    -1,  1610,    -1,  1613,    -1,  1616,    -1,  1619,
      -1,  1622,    -1,  1625,    -1,  1586,    -1,  1565,  1567,  1566,
      -1,   437,    -1,    11,    -1,    10,   438,    -1,   233,     8,
       6,     8,    -1,  1569,  1571,  1570,    -1,   287,    -1,    11,
      -1,    10,   288,    -1,   233,     8,     6,     8,    -1,  1573,
    1575,  1574,    -1,   291,    -1,    11,    -1,    10,   292,    -1,
     233,     8,     6,     8,    -1,  1577,  1579,  1578,    -1,   295,
      -1,    11,    -1,    10,   296,    -1,   233,     8,     6,     8,
      -1,  1581,  1582,    -1,   411,    -1,  1563,   412,    -1,  1584,
    1585,    -1,   413,    -1,  1563,  1563,   414,    -1,  1587,  1588,
      -1,   439,    -1,  1489,   440,    -1,  1590,  1591,    -1,   441,
      -1,  1563,   442,    -1,  1593,  1594,    10,  1595,    -1,   415,
      -1,    -1,  1600,    -1,  1563,   416,    -1,  1597,  1598,    10,
    1599,    -1,   417,    -1,    -1,  1600,    -1,  1563,   418,    -1,
     444,     3,     8,    -1,  1602,  1603,    -1,   419,    -1,    11,
      -1,    10,   420,    -1,  1605,  1606,    -1,   421,    -1,  1563,
    1563,   422,    -1,  1608,  1609,    -1,   423,    -1,  1563,   424,
      -1,  1611,  1612,    -1,   425,    -1,  1563,  1563,   426,    -1,
    1614,  1615,    -1,   427,    -1,  1563,  1563,   428,    -1,    -1,
     429,  1617,  1618,   430,    -1,    -1,  1618,  1563,    -1,  1620,
    1621,    -1,   431,    -1,  1489,  1563,   432,    -1,  1623,  1624,
      -1,   433,    -1,  1489,  1489,  1489,  1489,  1563,   434,    -1,
    1626,  1627,    -1,   435,    -1,  1563,   436,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   348,   348,   349,   351,   358,   368,   368,   370,   370,
     372,   374,   376,   385,   386,   389,   398,   398,   411,   411,
     413,   427,   427,   429,   429,   431,   433,   435,   435,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   449,   451,
     466,   473,   473,   476,   481,   485,   494,   498,   503,   503,
     505,   507,   509,   509,   511,   516,   526,   532,   532,   535,
     540,   546,   546,   549,   551,   558,   558,   560,   560,   562,
     564,   567,   569,   576,   576,   578,   578,   580,   582,   587,
     589,   596,   596,   598,   598,   600,   602,   607,   609,   616,
     616,   618,   618,   620,   622,   627,   629,   636,   636,   638,
     638,   640,   642,   647,   649,   656,   656,   658,   658,   660,
     662,   667,   669,   676,   676,   678,   678,   680,   682,   687,
     689,   696,   706,   711,   717,   717,   719,   721,   723,   723,
     725,   730,   742,   748,   748,   751,   758,   763,   770,   770,
     774,   774,   776,   787,   787,   789,   789,   791,   793,   795,
     795,   798,   799,   800,   801,   802,   803,   806,   808,   815,
     815,   817,   817,   819,   821,   828,   830,   841,   843,   843,
     846,   852,   858,   860,   866,   868,   879,   881,   881,   884,
     890,   896,   898,   905,   907,   918,   920,   920,   923,   929,
     935,   937,   944,   946,   955,   956,   962,   964,   970,   972,
     979,   989,   994,  1000,  1000,  1002,  1004,  1006,  1006,  1008,
    1013,  1025,  1031,  1031,  1034,  1041,  1046,  1052,  1052,  1056,
    1056,  1058,  1069,  1069,  1071,  1071,  1073,  1075,  1077,  1077,
    1080,  1081,  1082,  1083,  1084,  1085,  1088,  1090,  1097,  1097,
    1099,  1099,  1101,  1103,  1111,  1113,  1120,  1120,  1122,  1122,
    1124,  1126,  1131,  1133,  1140,  1140,  1142,  1142,  1144,  1146,
    1151,  1153,  1160,  1160,  1162,  1162,  1164,  1166,  1171,  1173,
    1180,  1180,  1182,  1182,  1184,  1186,  1193,  1195,  1202,  1212,
    1217,  1223,  1223,  1225,  1227,  1229,  1229,  1231,  1236,  1248,
    1254,  1254,  1257,  1264,  1269,  1276,  1276,  1279,  1279,  1281,
    1297,  1297,  1299,  1299,  1301,  1303,  1305,  1305,  1308,  1309,
    1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,  1318,  1321,
    1323,  1330,  1330,  1332,  1332,  1334,  1336,  1344,  1346,  1353,
    1353,  1355,  1355,  1357,  1359,  1364,  1366,  1373,  1373,  1375,
    1375,  1377,  1379,  1384,  1386,  1393,  1393,  1395,  1395,  1397,
    1399,  1404,  1406,  1413,  1413,  1415,  1415,  1417,  1419,  1424,
    1426,  1433,  1443,  1448,  1454,  1454,  1456,  1458,  1460,  1460,
    1462,  1464,  1478,  1478,  1481,  1481,  1481,  1481,  1484,  1484,
    1486,  1486,  1488,  1490,  1499,  1500,  1503,  1505,  1516,  1518,
    1518,  1521,  1527,  1533,  1535,  1542,  1544,  1555,  1557,  1557,
    1560,  1566,  1572,  1574,  1581,  1583,  1594,  1596,  1596,  1599,
    1605,  1611,  1613,  1620,  1622,  1632,  1633,  1639,  1641,  1648,
    1650,  1657,  1667,  1672,  1678,  1678,  1680,  1682,  1684,  1684,
    1686,  1691,  1703,  1709,  1709,  1712,  1719,  1724,  1731,  1731,
    1734,  1734,  1736,  1744,  1750,  1750,  1753,  1760,  1765,  1770,
    1777,  1782,  1788,  1788,  1790,  1792,  1794,  1794,  1796,  1798,
    1807,  1809,  1809,  1811,  1811,  1811,  1813,  1823,  1833,  1853,
    1859,  1861,  1871,  1877,  1877,  1880,  1885,  1890,  1900,  1905,
    1911,  1911,  1913,  1915,  1917,  1917,  1919,  1924,  1934,  1940,
    1940,  1943,  1949,  1956,  1956,  1959,  1959,  1961,  1963,  1963,
    1965,  1965,  1967,  1969,  1977,  1977,  1979,  1985,  1985,  1993,
    1993,  1995,  1997,  1999,  2001,  2001,  2003,  2008,  2016,  2021,
    2027,  2027,  2029,  2031,  2033,  2033,  2035,  2045,  2054,  2054,
    2057,  2058,  2061,  2064,  2064,  2066,  2071,  2079,  2084,  2090,
    2090,  2092,  2094,  2096,  2096,  2098,  2108,  2117,  2117,  2120,
    2121,  2125,  2126,  2128,  2128,  2130,  2132,  2137,  2137,  2139,
    2144,  2144,  2146,  2148,  2150,  2152,  2152,  2161,  2161,  2170,
    2170,  2179,  2179,  2188,  2188,  2197,  2197,  2206,  2206,  2216,
    2216,  2218,  2223,  2247,  2253,  2253,  2256,  2265,  2273,  2279,
    2285,  2291,  2297,  2303,  2309,  2316,  2316,  2318,  2318,  2320,
    2322,  2322,  2324,  2324,  2326,  2333,  2342,  2342,  2345,  2351,
    2358,  2358,  2360,  2360,  2362,  2364,  2373,  2373,  2375,  2386,
    2396,  2402,  2402,  2405,  2410,  2411,  2415,  2415,  2417,  2419,
    2422,  2426,  2426,  2428,  2436,  2436,  2444,  2444,  2446,  2448,
    2450,  2452,  2452,  2454,  2459,  2467,  2472,  2478,  2478,  2480,
    2482,  2485,  2485,  2487,  2495,  2505,  2505,  2508,  2509,  2512,
    2515,  2515,  2517,  2522,  2522,  2525,  2527,  2529,  2531,  2531,
    2540,  2540,  2549,  2549,  2558,  2558,  2567,  2567,  2576,  2576,
    2585,  2585,  2595,  2595,  2597,  2603,  2627,  2634,  2634,  2637,
    2645,  2653,  2659,  2665,  2671,  2677,  2683,  2689,  2697,  2697,
    2699,  2699,  2701,  2703,  2703,  2705,  2705,  2707,  2712,  2722,
    2722,  2725,  2731,  2738,  2738,  2740,  2740,  2742,  2744,  2751,
    2751,  2753,  2765,  2775,  2781,  2781,  2784,  2789,  2790,  2794,
    2794,  2796,  2798,  2801,  2804,  2804,  2806,  2813,  2813,  2821,
    2821,  2823,  2825,  2827,  2829,  2829,  2831,  2836,  2844,  2849,
    2855,  2855,  2857,  2859,  2861,  2861,  2863,  2871,  2880,  2880,
    2883,  2884,  2887,  2890,  2890,  2892,  2897,  2897,  2899,  2901,
    2903,  2905,  2905,  2914,  2914,  2923,  2923,  2932,  2932,  2941,
    2941,  2950,  2950,  2959,  2959,  2969,  2969,  2971,  2977,  3001,
    3007,  3007,  3010,  3018,  3026,  3032,  3038,  3044,  3050,  3056,
    3062,  3069,  3069,  3071,  3071,  3073,  3075,  3075,  3077,  3077,
    3079,  3086,  3095,  3095,  3099,  3104,  3112,  3112,  3114,  3114,
    3116,  3118,  3126,  3126,  3128,  3140,  3150,  3156,  3156,  3159,
    3164,  3165,  3169,  3169,  3171,  3173,  3175,  3178,  3178,  3180,
    3186,  3186,  3194,  3194,  3196,  3198,  3201,  3201,  3209,  3215,
    3228,  3228,  3230,  3232,  3234,  3236,  3236,  3239,  3246,  3258,
    3258,  3260,  3262,  3264,  3270,  3270,  3272,  3272,  3274,  3280,
    3309,  3316,  3316,  3319,  3329,  3335,  3340,  3345,  3350,  3355,
    3360,  3365,  3372,  3372,  3374,  3374,  3376,  3379,  3380,  3386,
    3386,  3389,  3390,  3392,  3405,  3415,  3421,  3421,  3424,  3429,
    3430,  3434,  3434,  3436,  3438,  3440,  3447,  3447,  3449,  3454,
    3454,  3456,  3461,  3470,  3475,  3481,  3481,  3483,  3485,  3487,
    3487,  3489,  3494,  3508,  3516,  3516,  3519,  3525,  3531,  3537,
    3543,  3553,  3558,  3564,  3564,  3566,  3568,  3570,  3570,  3572,
    3578,  3583,  3585,  3585,  3587,  3589,  3601,  3601,  3603,  3608,
    3617,  3622,  3628,  3628,  3630,  3632,  3634,  3634,  3636,  3641,
    3653,  3661,  3661,  3664,  3669,  3674,  3679,  3687,  3692,  3698,
    3698,  3700,  3702,  3704,  3704,  3706,  3712,  3717,  3719,  3719,
    3721,  3723,  4024,  4030,  4036,  4042,  4048,  4054,  4060,  4066,
    4075,  4081,  4090,  4118,  4119,  4123,  4124,  4125,  4127,  4129,
    4129,  4131,  4132,  4133,  4134,  4170,  4172,  4186,  4186,  4188,
    4190,  4192,  4194,  4194,  4197,  4198,  4199,  4200,  4201,  4203,
    4211,  4211,  4213,  4213,  4215,  4221,  4229,  4229,  4231,  4231,
    4233,  4239,  4247,  4247,  4249,  4249,  4251,  4257,  4265,  4265,
    4267,  4267,  4269,  4275,  4283,  4283,  4285,  4285,  4287,  4299,
    4307,  4309,  4309,  4311,  4313,  4322,  4324,  4324,  4326,  4326,
    4328,  4344,  4347,  4347,  4349,  4349,  4352,  4383,  4391,  4393,
    4393,  4395,  4397,  4405,  4405,  4407,  4423,  4425,  4425,  4427,
    4427,  4429,  4460,  4470,  4470,  4472,  4474,  4482,  4482,  4484,
    4627,  4629,  4634,  4634,  4636,  4638,  4640,  4643,  4645,  4650,
    4650,  4652,  4654,  4656,  4659,  4661,  4666,  4666,  4668,  4670,
    4672,  4675,  4677,  4682,  4682,  4684,  4686,  4688,  4691,  4693,
    4698,  4698,  4700,  4702,  4704,  4707,  4709,  4714,  4714,  4716,
    4718,  4720,  4723,  4725,  4730,  4730,  4732,  4734,  4736,  4739,
    4768,  4856,  4881,  4903,  4903,  4906,  4907,  4908,  4909,  4910,
    4911,  5042,  5042,  5044,  5046,  5075,  5077,  5077,  5082,  5100,
    5127,  5127,  5130,  5131,  5132,  5133,  5134,  5135,  5136,  5137,
    5138,  5141,  5141,  5143,  5143,  5148,  5148,  5148,  5148,  5149,
    5149,  5150,  5150,  5150,  5151,  5151,  5153,  5155,  5164,  5170,
    5170,  5173,  5179,  5185,  5187,  5187,  5193,  5203,  5213,  5213,
    5215,  5217,  5219,  5222,  5233,  5240,  5240,  5242,  5244,  5246,
    5252,  5262,  5269,  5269,  5271,  5273,  5275,  5278,  5280,  5289,
    5295,  5295,  5298,  5304,  5310,  5312,  5312,  5314,  5324,  5331,
    5331,  5333,  5335,  5337,  5339,  5341,  5350,  5356,  5356,  5359,
    5365,  5371,  5373,  5373,  5376,  5381,  5392,  5407,  5407,  5409,
    5411,  5413,  5415,  5415,  5417,  5424,  5431,  5444,  5444,  5447,
    5448,  5450,  5450,  5452,  5454,  5456,  5456,  5459,  5461,  5469,
    5469,  5474,  5482,  5484,  5493,  5499,  5499,  5502,  5508,  5515,
    5517,  5517,  5520,  5524,  5535,  5550,  5550,  5552,  5554,  5556,
    5556,  5558,  5560,  5575,  5575,  5577,  5579,  5588,  5590,  5599,
    5605,  5605,  5608,  5615,  5622,  5624,  5624,  5627,  5631,  5642,
    5658,  5658,  5660,  5662,  5664,  5664,  5666,  5668,  5683,  5683,
    5685,  5687,  5696,  5698,  5707,  5713,  5713,  5716,  5722,  5728,
    5730,  5730,  5732,  5742,  5749,  5749,  5751,  5753,  5755,  5758,
    5760,  5769,  5775,  5775,  5778,  5784,  5790,  5792,  5792,  5795,
    5799,  5810,  5825,  5825,  5827,  5829,  5831,  5831,  5833,  5836,
    5848,  5848,  5851,  5852,  5853,  5855,  5887,  5889,  5899,  5905,
    5905,  5908,  5914,  5920,  5922,  5922,  5925,  5929,  5940,  5952,
    5952,  5954,  5956,  5958,  5958,  5960,  5987,  5998,  5998,  6001,
    6002,  6003,  6005,  6005,  6008,  6010,  6019,  6025,  6025,  6028,
    6034,  6040,  6042,  6042,  6044,  6054,  6061,  6061,  6063,  6065,
    6067,  6070,  6073,  6091,  6091,  6102,  6109,  6119,  6127,  6133,
    6135,  6149,  6161,  6167,  6173,  6173,  6175,  6177,  6179,  6181,
    6191,  6197,  6203,  6203,  6205,  6207,  6209,  6211,  6211,  6216,
    6221,  6233,  6235,  6235,  6238,  6239,  6240,  6248,  6255,  6255,
    6257,  6259,  6277,  6288,  6299,  6321,  6332,  6343,  6354,  6398,
    6422,  6444,  6455,  6466,  6477,  6488,  6499,  6513,  6524,  6538,
    6553,  6568,  6580,  6592,  6612,  6632,  6642,  6670,  6679,  6690,
    6702,  6716,  6729,  6742,  6753,  6764,  6777,  6777,  6779,  6789,
    6805,  6805,  6807,  6814,  6823,  6823,  6825,  6832,  6841,  6841,
    6843,  6850,  6859,  6859,  6861,  6868,  6933,  6933,  6935,  6942,
    6951,  6951,  6953,  6960,  6969,  6969,  6971,  6978,  6987,  6987,
    6989,  6998,  7012,  7012,  7014,  7021,  7030,  7030,  7032,  7039,
    7048,  7048,  7050,  7057,  7066,  7066,  7068,  7075,  7084,  7084,
    7086,  7093,  7102,  7102,  7106,  7114,  7123,  7123,  7125,  7132,
    7141,  7141,  7143,  7150,  7279,  7280,  7281,  7282,  7283,  7284,
    7285,  7286,  7287,  7288,  7289,  7290,  7291,  7292,  7293,  7294,
    7295,  7296,  7297,  7298,  7299,  7300,  7301,  7302,  7304,  7305,
    7306,  7310,  7310,  7313,  7314,  7316,  7316,  7319,  7320,  7324,
    7324,  7329,  7329,  7334,  7334,  7339,  7339,  7344,  7344,  7349,
    7349,  7354,  7354,  7359,  7359,  7364,  7364,  7369,  7369,  7374,
    7374,  7379,  7379,  7384,  7386,  7392,  7399,  7399,  7405,  7405,
    7417,  7417,  7422,  7422,  7427,  7427,  7437,  7444,  7450,  7451,
    7453,  7454,  7457,  7461,  7465,  7469,  7468,  7487,  7486,  7493,
    7494,  7496,  7495,  7502,  7503,  7506,  7512,  7520,  7527,  7545,
    7545,  7556,  7556,  7559,  7559,  7573,  7574,  7577,  7577,  7590,
    7591,  7594,  7594,  7607,  7608,  7611,  7611,  7621,  7622,  7628,
    7629,  7630,  7631,  7632,  7633,  7634,  7635,  7636,  7637,  7638,
    7639,  7640,  7641,  7642,  7643,  7644,  7645,  7646,  7649,  7654,
    7661,  7662,  7664,  7672,  7677,  7684,  7685,  7687,  7694,  7699,
    7706,  7707,  7709,  7716,  7721,  7728,  7729,  7731,  7738,  7740,
    7746,  7748,  7750,  7756,  7758,  7760,  7766,  7768,  7770,  7776,
    7778,  7780,  7786,  7786,  7791,  7793,  7795,  7801,  7801,  7806,
    7808,  7817,  7819,  7824,  7824,  7826,  7828,  7834,  7837,  7839,
    7845,  7848,  7850,  7856,  7859,  7861,  7867,  7871,  7870,  7882,
    7882,  7889,  7891,  7897,  7899,  7901,  7907,  7910,  7912,  7918
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
  "OSRLEND", "WEIGHTEDOBJECTIVESATT", "EMPTYWEIGHTEDOBJECTIVESATT",
  "TARGETOBJECTIVENAMEATT", "EMPTYTARGETOBJECTIVENAMEATT",
  "NUMBEROFOTHERCONSTRAINTRESULTSATT", "NUMBEROFOTHEROBJECTIVERESULTSATT",
  "NUMBEROFOTHERRESULTSATT", "NUMBEROFOTHERSOLUTIONRESULTSATT",
  "NUMBEROFOTHERVARIABLERESULTSATT", "NUMBEROFSOLUTIONSATT",
  "NUMBEROFOTHERMATRIXOBJECTIVERESULTSATT",
  "NUMBEROFOTHERMATRIXCONSTRAINTRESULTSATT",
  "NUMBEROFOTHERMATRIXPROGRAMMINGRESULTSATT",
  "NUMBEROFOTHERMATRIXVARIABLERESULTSATT", "NUMBEROFSOLVEROUTPUTSATT",
  "NUMBEROFSUBSTATUSESATT", "NUMBEROFTIMESATT", "TARGETOBJECTIVEIDXATT",
  "ACTUALSTARTTIMESTART", "ACTUALSTARTTIMEEND", "AVAILABLECPUNUMBERSTART",
  "AVAILABLECPUNUMBEREND", "AVAILABLECPUSPEEDSTART",
  "AVAILABLECPUSPEEDEND", "AVAILABLEDISKSPACESTART",
  "AVAILABLEDISKSPACEEND", "AVAILABLEMEMORYSTART", "AVAILABLEMEMORYEND",
  "BASISSTATUSSTART", "BASISSTATUSEND", "CURRENTJOBCOUNTSTART",
  "CURRENTJOBCOUNTEND", "CURRENTSTATESTART", "CURRENTSTATEEND",
  "DUALVALUESSTART", "DUALVALUESEND", "ENDTIMESTART", "ENDTIMEEND",
  "IDXSTART", "IDXEND", "GENERALSTATUSSTART", "GENERALSTATUSEND",
  "GENERALSUBSTATUSSTART", "GENERALSUBSTATUSEND", "MESSAGESTART",
  "MESSAGEEND", "OPTIMIZATIONSOLUTIONSTATUSSTART",
  "OPTIMIZATIONSOLUTIONSTATUSEND", "OPTIMIZATIONSOLUTIONSUBSTATUSSTART",
  "OPTIMIZATIONSOLUTIONSUBSTATUSEND", "OTHERRESULTSSTART",
  "OTHERRESULTSEND", "OTHERSOLUTIONRESULTSTART", "OTHERSOLUTIONRESULTEND",
  "OTHERSOLUTIONRESULTSSTART", "OTHERSOLUTIONRESULTSEND",
  "OTHERSOLVEROUTPUTSTART", "OTHERSOLVEROUTPUTEND",
  "SCHEDULEDSTARTTIMESTART", "SCHEDULEDSTARTTIMEEND",
  "SERVICEUTILIZATIONSTART", "SERVICEUTILIZATIONEND", "SOLUTIONSTART",
  "SOLUTIONEND", "SOLVERINVOKEDSTART", "SOLVERINVOKEDEND",
  "SOLVEROUTPUTSTART", "SOLVEROUTPUTEND", "STATUSSTART", "STATUSEND",
  "SUBMITTIMESTART", "SUBMITTIMEEND", "SUBSTATUSSTART", "SUBSTATUSEND",
  "SYSTEMINFORMATIONSTART", "SYSTEMINFORMATIONEND", "TIMESTART", "TIMEEND",
  "TIMESERVICESTARTEDSTART", "TIMESERVICESTARTEDEND", "TIMESTAMPSTART",
  "TIMESTAMPEND", "TIMINGINFORMATIONSTART", "TIMINGINFORMATIONEND",
  "TOTALJOBSSOFARSTART", "TOTALJOBSSOFAREND", "USEDCPUNUMBERSTART",
  "USEDCPUNUMBEREND", "USEDCPUSPEEDSTART", "USEDCPUSPEEDEND",
  "USEDDISKSPACESTART", "USEDDISKSPACEEND", "USEDMEMORYSTART",
  "USEDMEMORYEND", "VALUESSTRINGSTART", "VALUESSTRINGEND",
  "OTHERMATRIXVARIABLERESULTSTART", "OTHERMATRIXVARIABLERESULTEND",
  "OTHERMATRIXOBJECTIVERESULTSTART", "OTHERMATRIXOBJECTIVERESULTEND",
  "OTHERMATRIXCONSTRAINTRESULTSTART", "OTHERMATRIXCONSTRAINTRESULTEND",
  "OTHERMATRIXPROGRAMMINGRESULTSTART", "OTHERMATRIXPROGRAMMINGRESULTEND",
  "HEADERSTART", "HEADEREND", "FILENAMESTART", "FILENAMEEND",
  "FILENAMEEMPTY", "FILENAMESTARTANDEND", "FILESOURCESTART",
  "FILESOURCEEND", "FILESOURCEEMPTY", "FILESOURCESTARTANDEND",
  "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
  "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART", "FILECREATOREND",
  "FILECREATOREMPTY", "FILECREATORSTARTANDEND", "FILELICENCESTART",
  "FILELICENCEEND", "FILELICENCEEMPTY", "FILELICENCESTARTANDEND",
  "INDEXESSTART", "INDEXESEND", "VALUESSTART", "VALUESEND",
  "NONZEROSSTART", "NONZEROSEND", "ELSTART", "ELEND", "ENUMERATIONSTART",
  "ENUMERATIONEND", "ITEMEMPTY", "ITEMSTART", "ITEMEND", "ITEMSTARTANDEND",
  "BASE64START", "BASE64END", "NUMBEROFELATT", "NUMBEROFENUMERATIONSATT",
  "NUMBEROFITEMSATT", "EMPTYCATEGORYATT", "CATEGORYATT",
  "EMPTYDESCRIPTIONATT", "DESCRIPTIONATT", "EMPTYSOLVERATT", "SOLVERATT",
  "EMPTYNAMEATT", "NAMEATT", "EMPTYTYPEATT", "TYPEATT", "EMPTYENUMTYPEATT",
  "ENUMTYPEATT", "EMPTYSHAPEATT", "SHAPEATT", "EMPTYUNITATT", "UNITATT",
  "EMPTYVALUEATT", "VALUEATT", "EMPTYVALUETYPEATT", "VALUETYPEATT",
  "EMPTYCONTYPEATT", "CONTYPEATT", "EMPTYOBJTYPEATT", "OBJTYPEATT",
  "EMPTYVARTYPEATT", "VARTYPEATT", "EMPTYMATRIXCONTYPEATT",
  "MATRIXCONTYPEATT", "EMPTYMATRIXOBJTYPEATT", "MATRIXOBJTYPEATT",
  "EMPTYMATRIXVARTYPEATT", "MATRIXVARTYPEATT", "EMPTYMATRIXTYPEATT",
  "MATRIXTYPEATT", "EMPTYSYMMETRYATT", "SYMMETRYATT", "EMPTYROWMAJORATT",
  "ROWMAJORATT", "EMPTYBASETRANSPOSEATT", "BASETRANSPOSEATT",
  "NUMBEROFBLOCKSATT", "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT",
  "NUMBEROFMATRICESATT", "NUMBEROFVALUESATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFCONATT", "NUMBEROFCONIDXATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFOBJATT", "NUMBEROFOBJIDXATT", "NUMBEROFVARIABLESATT",
  "NUMBEROFVARATT", "NUMBEROFVARIDXATT", "NUMBEROFMATRIXCONATT",
  "NUMBEROFMATRIXOBJATT", "NUMBEROFMATRIXVARATT", "BASEMATRIXIDXATT",
  "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
  "BASEMATRIXSTARTROWATT", "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT",
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "BLOCKROWIDXATT",
  "BLOCKCOLIDXATT", "REATT", "IMATT", "MATRIXVARIDXATT", "MATRIXOBJIDXATT",
  "MATRIXCONIDXATT", "IDXATT", "INCRATT", "MULTATT", "SIZEOFATT",
  "COEFATT", "CONSTANTATT", "MATRICESSTART", "MATRICESEND", "MATRIXSTART",
  "MATRIXEND", "BASEMATRIXEND", "BASEMATRIXSTART", "BLOCKSSTART",
  "BLOCKSEND", "BLOCKSTART", "BLOCKEND", "COLOFFSETSTART", "COLOFFSETEND",
  "ROWOFFSETSTART", "ROWOFFSETEND", "ELEMENTSSTART", "ELEMENTSEND",
  "CONSTANTELEMENTSSTART", "CONSTANTELEMENTSEND", "COMPLEXELEMENTSSTART",
  "COMPLEXELEMENTSEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "CONREFERENCEELEMENTSSTART", "CONREFERENCEELEMENTSEND",
  "OBJREFERENCEELEMENTSSTART", "OBJREFERENCEELEMENTSEND",
  "REALVALUEDEXPRESSIONSSTART", "REALVALUEDEXPRESSIONSSEND",
  "COMPLEXVALUEDEXPRESSIONSSTART", "COMPLEXVALUEDEXPRESSIONSSEND",
  "STRINGVALUEDELEMENTSSTART", "STRINGVALUEDELEMENTSEND",
  "STARTVECTORSTART", "STARTVECTOREND", "INDEXSTART", "INDEXEND",
  "VALUESTART", "VALUEEND", "VARIDXSTART", "VARIDXEND",
  "TRANSFORMATIONSTART", "TRANSFORMATIONEND", "MATRIXPROGRAMMINGSTART",
  "MATRIXPROGRAMMINGEND", "MATRIXVARIABLESSTART", "MATRIXVARIABLESEND",
  "MATRIXVARSTART", "MATRIXVAREND", "MATRIXOBJECTIVESSTART",
  "MATRIXOBJECTIVESEND", "MATRIXOBJSTART", "MATRIXOBJEND",
  "MATRIXCONSTRAINTSSTART", "MATRIXCONSTRAINTSEND", "MATRIXCONSTART",
  "MATRIXCONEND", "CONSTART", "CONEND", "CONSTRAINTSSTART",
  "CONSTRAINTSEND", "OBJSTART", "OBJEND", "OBJECTIVESSTART",
  "OBJECTIVESEND", "VARSTART", "VAREND", "VARIABLESSTART", "VARIABLESEND",
  "GENERALSTART", "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART",
  "SERVICEEND", "JOBSTART", "JOBEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "ATEQUALITYSTART", "ATEQUALITYEND", "ATLOWERSTART",
  "ATLOWEREND", "ATUPPERSTART", "ATUPPEREND", "BASICSTART", "BASICEND",
  "ISFREESTART", "ISFREEEND", "SUPERBASICSTART", "SUPERBASICEND",
  "UNKNOWNSTART", "UNKNOWNEND", "SERVICEURISTART", "SERVICEURIEND",
  "SERVICENAMESTART", "SERVICENAMEEND", "INSTANCENAMESTART",
  "INSTANCENAMEEND", "JOBIDSTART", "JOBIDEND", "OTHERSTART", "OTHEREND",
  "DUMMY", "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND",
  "NUMBEROFNONLINEAREXPRESSIONS", "NLSTART", "NLEND",
  "MATRIXEXPRESSIONSSTART", "MATRIXEXPRESSIONSEND", "NUMBEROFEXPR",
  "EXPRSTART", "EXPREND", "NUMBEROFMATRIXTERMSATT", "MATRIXTERMSTART",
  "MATRIXTERMEND", "POWERSTART", "POWEREND", "PLUSSTART", "PLUSEND",
  "MINUSSTART", "MINUSEND", "DIVIDESTART", "DIVIDEEND", "LNSTART", "LNEND",
  "SQRTSTART", "SQRTEND", "SUMSTART", "SUMEND", "PRODUCTSTART",
  "PRODUCTEND", "EXPSTART", "EXPEND", "NEGATESTART", "NEGATEEND",
  "IFSTART", "IFEND", "SQUARESTART", "SQUAREEND", "COSSTART", "COSEND",
  "SINSTART", "SINEND", "VARIABLESTART", "VARIABLEEND", "ABSSTART",
  "ABSEND", "ERFSTART", "ERFEND", "MAXSTART", "MAXEND", "ALLDIFFSTART",
  "ALLDIFFEND", "MINSTART", "MINEND", "ESTART", "EEND", "PISTART", "PIEND",
  "TIMESSTART", "TIMESEND", "NUMBERSTART", "NUMBEREND",
  "MATRIXDETERMINANTSTART", "MATRIXDETERMINANTEND", "MATRIXTRACESTART",
  "MATRIXTRACEEND", "MATRIXTOSCALARSTART", "MATRIXTOSCALAREND",
  "MATRIXDIAGONALSTART", "MATRIXDIAGONALEND", "MATRIXDOTTIMESSTART",
  "MATRIXDOTTIMESEND", "MATRIXLOWERTRIANGLESTART",
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
  "EMPTYIDATT", "IDATT", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
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
  "variablesAtLower", "variablesAtUpper", "variablesAtEquality",
  "variablesIsFree", "variablesSuperbasic", "variablesUnknown",
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
  "objectivesBasic", "objectivesAtLower", "objectivesAtUpper",
  "objectivesAtEquality", "objectivesIsFree", "objectivesSuperbasic",
  "objectivesUnknown", "otherObjectiveResultsArray",
  "otherObjectiveResult", "otherObjectiveResultStart",
  "otherObjectiveResultAttributes", "otherObjectiveResultAttList",
  "otherObjectiveResultATT", "otherObjectiveResultContent",
  "otherObjectiveResultEmpty", "otherObjectiveResultLaden",
  "otherObjectiveResultBody", "otherObjList", "otherObj", "otherObjStart",
  "otherObjAttList", "otherObjAtt", "otherObjContent", "otherObjEmpty",
  "otherObjLaden", "otherObjBody", "otherObjEnumerationList",
  "otherObjEnumeration", "otherObjEnumerationStart",
  "otherObjEnumerationAttributes", "otherObjEnumerationAttList",
  "otherObjEnumerationATT", "otherObjEnumerationContent",
  "otherObjEnumerationEmpty", "otherObjEnumerationLaden",
  "otherObjEnumerationBody", "constraints", "constraintsStart",
  "numberOfOtherConstraintResults", "constraintsContent",
  "constraintsEmpty", "constraintsLaden", "constraintsBody", "dualValues",
  "dualValuesStart", "numberOfConAttribute", "dualValuesContent",
  "dualValuesEmpty", "dualValuesLaden", "dualValuesBody", "dualValueArray",
  "dualValue", "dualValueStart", "dualValueAttList", "dualValueAtt",
  "dualValueContent", "slackBasisStatus", "slackBasisStatusStart",
  "slackBasisStatusContent", "slackBasisStatusEmpty",
  "slackBasisStatusLaden", "slackBasisStatusBody", "slacksBasic",
  "slacksAtLower", "slacksAtUpper", "slacksAtEquality", "slacksIsFree",
  "slacksSuperbasic", "slacksUnknown", "otherConstraintResultsArray",
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
  "matrixProgrammingAttributes", "matrixProgrammingContent",
  "matrixProgrammingEmpty", "matrixProgrammingLaden", "matrixVariables",
  "matrixVariablesStart", "matrixVariablesAttributes",
  "matrixVariablesContent", "matrixVariablesEmpty", "matrixVariablesLaden",
  "matrixVariablesEnd", "matrixVariableValues",
  "matrixVariableValuesStart", "matrixVariableValuesAttributes",
  "matrixVariableValuesContent", "matrixVariableValuesEmpty",
  "matrixVariableValuesLaden", "matrixVariableValuesEnd", "matrixVarList",
  "otherMatrixVariableResults", "otherMatrixVariableResult",
  "otherMatrixVariableResultStart", "otherMatrixVariableResultAttributes",
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
  "numberOfOtherConstraintResultsAttribute",
  "numberOfOtherMatrixProgrammingResultsATT",
  "numberOfOtherMatrixVariableResultsATT",
  "numberOfOtherObjectiveResultsAttribute",
  "numberOfOtherResultsAttribute", "numberOfOtherSolutionResultsAttribute",
  "numberOfOtherVariableResultsAttribute", "numberOfSolutionsAttribute",
  "numberOfSolverOutputsAttribute", "numberOfSubstatusesAttribute",
  "numberOfTimesAttribute", "aNumber", "ElementValue", "quote",
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
  "osglDblVectorBase64Laden", "osglStrArrayData", "osglStrVectorElArray",
  "osglStrVectorEl", "osglStrVectorElStart", "osglStrVectorElAttributes",
  "osglStrVectorElContent", "osglBasisStatusBasic", "osglBasicStart",
  "osglBasicContent", "osglBasicEmpty", "osglBasicLaden", "osglBasicBody",
  "osglBasisStatusAtLower", "osglAtLowerStart", "osglAtLowerContent",
  "osglAtLowerEmpty", "osglAtLowerLaden", "osglAtLowerBody",
  "osglBasisStatusAtUpper", "osglAtUpperStart", "osglAtUpperContent",
  "osglAtUpperEmpty", "osglAtUpperLaden", "osglAtUpperBody",
  "osglBasisStatusAtEquality", "osglAtEqualityStart",
  "osglAtEqualityContent", "osglAtEqualityEmpty", "osglAtEqualityLaden",
  "osglAtEqualityBody", "osglBasisStatusIsFree", "osglIsFreeStart",
  "osglIsFreeContent", "osglIsFreeEmpty", "osglIsFreeLaden",
  "osglIsFreeBody", "osglBasisStatusSuperbasic", "osglSuperbasicStart",
  "osglSuperbasicContent", "osglSuperbasicEmpty", "osglSuperbasicLaden",
  "osglSuperbasicBody", "osglBasisStatusUnknown", "osglUnknownStart",
  "osglUnknownContent", "osglUnknownEmpty", "osglUnknownLaden",
  "osglUnknownBody", "osglBasisNumberOfElAttribute",
  "osglMatrixWithMatrixVarIdx", "matrixVarStart",
  "matrixWithMatrixVarIdxAttributes", "matrixWithMatrixVarIdxATTList",
  "matrixWithMatrixVarIdxATT", "matrixVarContent", "matrixVarEmpty",
  "matrixVarLaden", "matrixOrBlockBody", "baseMatrix", "baseMatrixStart",
  "baseMatrixAttributes", "baseMatrixAttList", "baseMatrixAtt",
  "baseMatrixEnd", "matrixConstructorList", "matrixConstructor",
  "constantElements", "constantElementsStart",
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
  "linearElementsValuesElAtt", "linearElementsValuesElContent",
  "linearElementsValuesElEmpty", "linearElementsValuesElLaden",
  "linearElementsValuesVarIdxList", "linearElementsValuesVarIdx",
  "linearElementsValuesVarIdxStart", "linearElementsValuesVarIdxCoefATT",
  "linearElementsValuesVarIdxContent", "realValuedExpressions",
  "realValuedExpressionsStart", "realValuedExpressionsAttributes",
  "realValuedExpressionsAttList", "realValuedExpressionsAtt",
  "realValuedExpressionsContent", "realValuedExpressionsNonzeros",
  "realValuedExpressionsValues", "realValuedExpressionsValuesStart",
  "realValuedExpressionsValuesContent", "realValuedExpressionsValuesEmpty",
  "realValuedExpressionsValuesLaden", "realValuedExpressionsElList",
  "realValuedExpressionsEl", "realValuedExpressionsElStart",
  "realValuedExpressionsElContent", "realValuedExpressionsElEmpty",
  "realValuedExpressionsElLaden", "complexValuedExpressions",
  "complexValuedExpressionsStart", "complexValuedExpressionsAttributes",
  "complexValuedExpressionsAttList", "complexValuedExpressionsAtt",
  "complexValuedExpressionsContent", "complexValuedExpressionsNonzeros",
  "complexValuedExpressionsValues", "complexValuedExpressionsValuesStart",
  "complexValuedExpressionsValuesContent",
  "complexValuedExpressionsValuesEmpty",
  "complexValuedExpressionsValuesLaden", "complexValuedExpressionsElList",
  "complexValuedExpressionsEl", "complexValuedExpressionsElStart",
  "complexValuedExpressionsElContent", "complexValuedExpressionsElEmpty",
  "complexValuedExpressionsElLaden", "objReferenceElements",
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
  "conReferenceElementsElAttribute", "conReferenceElementsElContent",
  "complexElements", "complexElementsStart", "complexElementsAttributes",
  "complexElementsAttList", "complexElementsAtt", "complexElementsContent",
  "complexElementsNonzeros", "complexElementsValues",
  "complexElementsValuesStart", "complexElementsValuesContent",
  "complexElementsValuesEmpty", "complexElementsValuesLaden",
  "complexElementsElList", "complexElementsEl", "complexElementsElStart",
  "complexElementsElAttributeList", "complexElementsElAttribute",
  "complexElementsElEnd", "stringValuedElements",
  "stringValuedElementsStart", "stringValuedElementsAttributes",
  "stringValuedElementsAttList", "stringValuedElementsAtt",
  "stringValuedElementsContent", "stringValuedElementsNonzeros",
  "stringValuedElementsValues", "stringValuedElementsValueStart",
  "stringValuedElementsValueContent", "stringValuedElementsValueEmpty",
  "stringValuedElementsValueLaden", "stringValuedElementsValueBody",
  "matrixTransformation", "matrixTransformationStart",
  "matrixTransformationShapeATT", "matrixTransformationEnd",
  "matrixBlocks", "matrixBlocksStart", "matrixBlocksAttributes",
  "matrixBlocksContent", "matrixBlocksEnd", "colOffsets", "colOffsetStart",
  "colOffsetNumberOfElAttribute", "colOffsetContent", "colOffsetEmpty",
  "colOffsetLaden", "colOffsetBody", "rowOffsets", "rowOffsetStart",
  "rowOffsetNumberOfElAttribute", "rowOffsetContent", "rowOffsetEmpty",
  "rowOffsetLaden", "rowOffsetBody", "blockList", "matrixBlock",
  "matrixBlockStart", "matrixBlockAttributes", "matrixBlockAttList",
  "matrixBlockAtt", "matrixBlockContent", "blockEmpty", "blockLaden",
  "osglNumberOfBlocksATT", "osglNumberOfColumnsATT", "osglNumberOfConATT",
  "osglNumberOfConstraintsATT", "osglNumberOfElATT",
  "osglNumberOfEnumerationsATT", "osglNumberOfItemsATT",
  "osglNumberOfMatrixVarATT", "osglNumberOfObjATT",
  "osglNumberOfObjectivesATT", "osglNumberOfRowsATT",
  "osglNumberOfValuesATT", "osglNumberOfVarATT", "osglNumberOfVarIdxATT",
  "osglNumberOfVariablesATT", "osglBase64SizeATT", "osglBaseMatrixIdxATT",
  "osglBaseMatrixStartRowATT", "osglBaseMatrixStartColATT",
  "osglBaseMatrixEndRowATT", "osglBaseMatrixEndColATT",
  "osglBlockRowIdxATT", "osglBlockColIdxATT", "osglIdxATT", "osglIncrATT",
  "osglMatrixVarIdxATT", "osglMultATT", "osglTargetMatrixFirstRowATT",
  "osglTargetMatrixFirstColATT", "osglCoefATT", "osglConstantATT",
  "osglImagPartATT", "osglRealPartATT", "osglScalarMultiplierATT",
  "osglBaseTransposeATT", "baseTransposeAttEmpty",
  "baseTransposeAttContent", "osglCategoryATT", "categoryAttEmpty",
  "categoryAttContent", "osglConTypeATT", "conTypeAttEmpty",
  "conTypeAttContent", "osglDescriptionATT", "descriptionAttEmpty",
  "descriptionAttContent", "osglEnumTypeATT", "enumTypeAttEmpty",
  "enumTypeAttContent", "osglMatrixVarTypeATT", "matrixVarTypeAttEmpty",
  "matrixVarTypeAttContent", "osglNameATT", "nameAttEmpty",
  "nameAttContent", "osglObjTypeATT", "objTypeAttEmpty",
  "objTypeAttContent", "osglRowMajorATT", "rowMajorAttEmpty",
  "rowMajorAttContent", "osglShapeATT", "shapeAttEmpty", "shape",
  "osglSolverATT", "solverAttEmpty", "solverAttContent", "osglSymmetryATT",
  "symmetryAttEmpty", "symmetryAttContent", "osglTypeATT", "typeAttEmpty",
  "typeAttContent", "osglUnitATT", "unitAttEmpty", "unitAttContent",
  "osglValueATT", "valueAttEmpty", "valueAttContent", "osglValueTypeATT",
  "valueTypeAttEmpty", "valueTypeAttContent", "osglVarTypeATT",
  "varTypeAttEmpty", "varTypeAttContent", "nlnode", "E", "$@1", "eend",
  "PI", "$@2", "piend", "times", "$@3", "plus", "$@4", "minus", "$@5",
  "negate", "$@6", "divide", "$@7", "power", "$@8", "ln", "$@9", "sqrt",
  "$@10", "square", "$@11", "cos", "$@12", "sin", "$@13", "exp", "$@14",
  "abs", "absStart", "absEnd", "erf", "$@15", "if", "$@16",
  "matrixDeterminant", "$@17", "matrixTrace", "$@18", "matrixToScalar",
  "$@19", "number", "numberStart", "numberEnd", "numberAttributeList",
  "numberAttribute", "numberidATT", "$@20", "variable", "$@21",
  "variableend", "$@22", "anotherVariableATT", "variableATT",
  "variablecoefATT", "variableidxATT", "sum", "$@23", "anothersumnlnode",
  "allDiff", "$@24", "anotherallDiffnlnode", "max", "$@25",
  "anothermaxnlnode", "min", "$@26", "anotherminnlnode", "product", "$@27",
  "anotherproductnlnode", "OSnLMNode", "matrixReference",
  "matrixReferenceStart", "matrixReferenceEnd", "matrixIdxATT",
  "matrixVarReference", "matrixVarReferenceStart", "matrixVarReferenceEnd",
  "matrixVarIdxATT", "matrixObjReference", "matrixObjReferenceStart",
  "matrixObjReferenceEnd", "matrixObjIdxATT", "matrixConReference",
  "matrixConReferenceStart", "matrixConReferenceEnd", "matrixConIdxATT",
  "matrixDiagonal", "matrixDiagonalStart", "matrixDiagonalContent",
  "matrixDotTimes", "matrixDotTimesStart", "matrixDotTimesContent",
  "identityMatrix", "identityMatrixStart", "identityMatrixContent",
  "matrixInverse", "matrixInverseStart", "matrixInverseContent",
  "matrixLowerTriangle", "matrixLowerTriangleStart",
  "matrixLowerTriangleAttribute", "matrixLowerTriangleContent",
  "matrixUpperTriangle", "matrixUpperTriangleStart",
  "matrixUpperTriangleAttribute", "matrixUpperTriangleContent",
  "includeDiagonalATT", "matrixMerge", "matrixMergeStart",
  "matrixMergeEnd", "matrixMinus", "matrixMinusStart",
  "matrixMinusContent", "matrixNegate", "matrixNegateStart",
  "matrixNegateContent", "matrixPlus", "matrixPlusStart",
  "matrixPlusContent", "matrixTimes", "matrixTimesStart",
  "matrixTimesContent", "matrixProduct", "$@28",
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
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,    32,     9,    13,
      10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   451,   452,   452,   453,   454,   455,   455,   456,   456,
     457,   458,   459,   460,   460,   461,   462,   462,   463,   463,
     464,   465,   465,   466,   466,   467,   468,   469,   469,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   471,   472,
     473,   474,   474,   475,   475,   475,   476,   476,   477,   477,
     478,   479,   480,   480,   481,   482,   483,   484,   484,   485,
     485,   486,   486,   487,   488,   489,   489,   490,   490,   491,
     492,   493,   494,   495,   495,   496,   496,   497,   498,   499,
     500,   501,   501,   502,   502,   503,   504,   505,   506,   507,
     507,   508,   508,   509,   510,   511,   512,   513,   513,   514,
     514,   515,   516,   517,   518,   519,   519,   520,   520,   521,
     522,   523,   524,   525,   525,   526,   526,   527,   528,   529,
     530,   531,   532,   532,   533,   533,   534,   535,   536,   536,
     537,   538,   539,   540,   540,   541,   541,   541,   542,   542,
     543,   543,   544,   545,   545,   546,   546,   547,   548,   549,
     549,   550,   550,   550,   550,   550,   550,   551,   552,   553,
     553,   554,   554,   555,   556,   557,   558,   559,   560,   560,
     561,   561,   562,   563,   564,   565,   566,   567,   567,   568,
     568,   569,   570,   571,   572,   573,   574,   574,   575,   575,
     576,   577,   578,   579,   580,   580,   581,   582,   583,   584,
     585,   586,   586,   587,   587,   588,   589,   590,   590,   591,
     592,   593,   594,   594,   595,   595,   595,   596,   596,   597,
     597,   598,   599,   599,   600,   600,   601,   602,   603,   603,
     604,   604,   604,   604,   604,   604,   605,   606,   607,   607,
     608,   608,   609,   610,   611,   612,   613,   613,   614,   614,
     615,   616,   617,   618,   619,   619,   620,   620,   621,   622,
     623,   624,   625,   625,   626,   626,   627,   628,   629,   630,
     631,   631,   632,   632,   633,   634,   635,   636,   637,   638,
     638,   639,   639,   640,   641,   642,   642,   643,   644,   645,
     646,   646,   647,   647,   647,   648,   648,   649,   649,   650,
     651,   651,   652,   652,   653,   654,   655,   655,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   657,
     658,   659,   659,   660,   660,   661,   662,   663,   664,   665,
     665,   666,   666,   667,   668,   669,   670,   671,   671,   672,
     672,   673,   674,   675,   676,   677,   677,   678,   678,   679,
     680,   681,   682,   683,   683,   684,   684,   685,   686,   687,
     688,   689,   690,   690,   691,   691,   692,   693,   694,   694,
     695,   696,   697,   697,   698,   698,   698,   698,   699,   699,
     700,   700,   701,   702,   703,   703,   704,   705,   706,   707,
     707,   708,   708,   709,   710,   711,   712,   713,   714,   714,
     715,   715,   716,   717,   718,   719,   720,   721,   721,   722,
     722,   723,   724,   725,   726,   727,   727,   728,   729,   730,
     731,   732,   733,   733,   734,   734,   735,   736,   737,   737,
     738,   739,   740,   741,   741,   742,   742,   742,   743,   743,
     744,   744,   745,   746,   747,   747,   748,   748,   748,   748,
     749,   749,   750,   750,   751,   752,   753,   753,   754,   755,
     756,   757,   757,   758,   758,   758,   759,   760,   761,   762,
     763,   764,   765,   766,   766,   767,   767,   767,   768,   768,
     769,   769,   770,   771,   772,   772,   773,   774,   775,   776,
     776,   777,   777,   778,   778,   779,   779,   780,   781,   781,
     782,   782,   783,   784,   785,   785,   786,   787,   787,   788,
     788,   789,   790,   791,   792,   792,   793,   794,   795,   795,
     796,   796,   797,   798,   799,   799,   800,   801,   802,   802,
     803,   803,   804,   805,   805,   806,   807,   808,   808,   809,
     809,   810,   811,   812,   812,   813,   814,   815,   815,   816,
     816,   817,   817,   818,   818,   819,   820,   821,   821,   822,
     823,   823,   824,   825,   826,   827,   827,   828,   828,   829,
     829,   830,   830,   831,   831,   832,   832,   833,   833,   834,
     834,   835,   836,   837,   838,   838,   839,   839,   839,   839,
     839,   839,   839,   839,   839,   840,   840,   841,   841,   842,
     843,   843,   844,   844,   845,   846,   847,   847,   848,   848,
     849,   849,   850,   850,   851,   852,   853,   853,   854,   855,
     856,   857,   857,   858,   858,   858,   859,   859,   860,   861,
     862,   863,   863,   864,   865,   865,   866,   866,   867,   868,
     869,   870,   870,   871,   872,   873,   873,   874,   874,   875,
     876,   877,   877,   878,   879,   880,   880,   881,   881,   882,
     883,   883,   884,   885,   885,   886,   887,   888,   889,   889,
     890,   890,   891,   891,   892,   892,   893,   893,   894,   894,
     895,   895,   896,   896,   897,   898,   899,   900,   900,   901,
     901,   901,   901,   901,   901,   901,   901,   901,   902,   902,
     903,   903,   904,   905,   905,   906,   906,   907,   908,   909,
     909,   910,   910,   911,   911,   912,   912,   913,   914,   915,
     915,   916,   917,   918,   919,   919,   920,   920,   920,   921,
     921,   922,   923,   924,   925,   925,   926,   927,   927,   928,
     928,   929,   930,   931,   932,   932,   933,   934,   935,   935,
     936,   936,   937,   938,   939,   939,   940,   941,   942,   942,
     943,   943,   944,   945,   945,   946,   947,   947,   948,   949,
     950,   951,   951,   952,   952,   953,   953,   954,   954,   955,
     955,   956,   956,   957,   957,   958,   958,   959,   960,   961,
     962,   962,   963,   963,   963,   963,   963,   963,   963,   963,
     963,   964,   964,   965,   965,   966,   967,   967,   968,   968,
     969,   970,   971,   971,   972,   972,   973,   973,   974,   974,
     975,   976,   977,   977,   978,   979,   980,   981,   981,   982,
     982,   982,   983,   983,   984,   985,   986,   987,   987,   988,
     989,   989,   990,   990,   991,   992,   993,   993,   994,   995,
     996,   996,   997,   998,   999,  1000,  1000,  1001,  1002,  1003,
    1003,  1004,  1005,  1006,  1007,  1007,  1008,  1008,  1009,  1010,
    1011,  1012,  1012,  1013,  1013,  1013,  1013,  1013,  1013,  1013,
    1013,  1013,  1014,  1014,  1015,  1015,  1016,  1017,  1017,  1018,
    1018,  1019,  1019,  1020,  1021,  1022,  1023,  1023,  1024,  1024,
    1024,  1025,  1025,  1026,  1027,  1028,  1029,  1029,  1030,  1031,
    1031,  1032,  1033,  1034,  1034,  1035,  1035,  1036,  1037,  1038,
    1038,  1039,  1040,  1041,  1042,  1042,  1043,  1043,  1043,  1043,
    1043,  1044,  1044,  1045,  1045,  1046,  1047,  1048,  1048,  1049,
    1050,  1050,  1051,  1051,  1052,  1053,  1054,  1054,  1055,  1056,
    1057,  1057,  1058,  1058,  1059,  1060,  1061,  1061,  1062,  1063,
    1064,  1065,  1065,  1066,  1066,  1066,  1066,  1067,  1067,  1068,
    1068,  1069,  1070,  1071,  1071,  1072,  1073,  1073,  1074,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1088,  1089,  1089,  1089,  1090,  1091,
    1091,  1092,  1092,  1092,  1092,  1093,  1094,  1095,  1095,  1096,
    1097,  1098,  1099,  1099,  1100,  1100,  1100,  1100,  1100,  1101,
    1102,  1102,  1103,  1103,  1104,  1105,  1106,  1106,  1107,  1107,
    1108,  1109,  1110,  1110,  1111,  1111,  1112,  1113,  1114,  1114,
    1115,  1115,  1116,  1117,  1118,  1118,  1119,  1119,  1120,  1121,
    1121,  1122,  1122,  1123,  1124,  1125,  1126,  1126,  1127,  1127,
    1128,  1129,  1130,  1130,  1131,  1131,  1132,  1133,  1133,  1134,
    1134,  1135,  1136,  1137,  1137,  1138,  1139,  1140,  1140,  1141,
    1141,  1142,  1143,  1144,  1144,  1145,  1146,  1147,  1147,  1148,
    1149,  1150,  1151,  1151,  1152,  1153,  1154,  1155,  1156,  1157,
    1157,  1158,  1159,  1160,  1161,  1162,  1163,  1163,  1164,  1165,
    1166,  1167,  1168,  1169,  1169,  1170,  1171,  1172,  1173,  1174,
    1175,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1187,  1188,  1189,  1190,  1191,
    1192,  1193,  1194,  1195,  1195,  1196,  1196,  1196,  1196,  1196,
    1196,  1197,  1197,  1198,  1199,  1200,  1201,  1201,  1202,  1203,
    1204,  1204,  1205,  1205,  1205,  1205,  1205,  1205,  1205,  1205,
    1205,  1206,  1206,  1207,  1207,  1208,  1208,  1208,  1208,  1208,
    1208,  1208,  1208,  1208,  1208,  1208,  1209,  1210,  1211,  1212,
    1212,  1213,  1213,  1214,  1215,  1215,  1216,  1217,  1218,  1218,
    1219,  1220,  1221,  1222,  1223,  1224,  1224,  1225,  1226,  1227,
    1228,  1229,  1230,  1230,  1231,  1232,  1233,  1234,  1235,  1236,
    1237,  1237,  1238,  1238,  1239,  1240,  1240,  1241,  1242,  1243,
    1243,  1244,  1245,  1246,  1247,  1248,  1249,  1250,  1250,  1251,
    1251,  1252,  1253,  1253,  1254,  1254,  1255,  1256,  1256,  1257,
    1258,  1259,  1260,  1260,  1261,  1262,  1263,  1264,  1264,  1265,
    1265,  1266,  1266,  1267,  1268,  1269,  1269,  1270,  1271,  1272,
    1272,  1273,  1274,  1275,  1276,  1277,  1277,  1278,  1278,  1279,
    1280,  1280,  1281,  1281,  1282,  1283,  1283,  1284,  1285,  1286,
    1286,  1287,  1288,  1289,  1289,  1290,  1291,  1292,  1293,  1294,
    1295,  1295,  1296,  1296,  1297,  1298,  1298,  1299,  1299,  1300,
    1301,  1301,  1302,  1303,  1304,  1304,  1305,  1306,  1307,  1307,
    1308,  1309,  1310,  1311,  1312,  1313,  1313,  1314,  1314,  1315,
    1316,  1316,  1317,  1318,  1319,  1319,  1320,  1321,  1322,  1323,
    1324,  1325,  1326,  1326,  1327,  1327,  1328,  1329,  1329,  1330,
    1330,  1331,  1332,  1332,  1333,  1334,  1335,  1335,  1336,  1337,
    1338,  1338,  1339,  1339,  1339,  1340,  1341,  1342,  1343,  1344,
    1344,  1345,  1345,  1346,  1347,  1347,  1348,  1348,  1349,  1350,
    1350,  1351,  1352,  1353,  1353,  1354,  1355,  1356,  1356,  1357,
    1357,  1357,  1358,  1358,  1359,  1360,  1361,  1362,  1362,  1363,
    1363,  1364,  1365,  1365,  1366,  1367,  1368,  1368,  1369,  1370,
    1371,  1372,  1373,  1374,  1374,  1375,  1376,  1377,  1378,  1379,
    1380,  1381,  1382,  1383,  1384,  1384,  1385,  1386,  1387,  1388,
    1389,  1390,  1391,  1391,  1392,  1393,  1394,  1395,  1395,  1396,
    1397,  1398,  1399,  1399,  1400,  1400,  1400,  1400,  1401,  1401,
    1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,
    1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,
    1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,
    1432,  1433,  1434,  1435,  1436,  1437,  1438,  1438,  1439,  1440,
    1441,  1441,  1442,  1443,  1444,  1444,  1445,  1446,  1447,  1447,
    1448,  1449,  1450,  1450,  1451,  1452,  1453,  1453,  1454,  1455,
    1456,  1456,  1457,  1458,  1459,  1459,  1460,  1461,  1462,  1462,
    1463,  1464,  1465,  1465,  1466,  1467,  1468,  1468,  1469,  1470,
    1471,  1471,  1472,  1473,  1474,  1474,  1475,  1476,  1477,  1477,
    1478,  1479,  1480,  1480,  1481,  1482,  1483,  1483,  1484,  1485,
    1486,  1486,  1487,  1488,  1489,  1489,  1489,  1489,  1489,  1489,
    1489,  1489,  1489,  1489,  1489,  1489,  1489,  1489,  1489,  1489,
    1489,  1489,  1489,  1489,  1489,  1489,  1489,  1489,  1489,  1489,
    1489,  1491,  1490,  1492,  1492,  1494,  1493,  1495,  1495,  1497,
    1496,  1499,  1498,  1501,  1500,  1503,  1502,  1505,  1504,  1507,
    1506,  1509,  1508,  1511,  1510,  1513,  1512,  1515,  1514,  1517,
    1516,  1519,  1518,  1520,  1521,  1522,  1524,  1523,  1526,  1525,
    1528,  1527,  1530,  1529,  1532,  1531,  1533,  1534,  1535,  1535,
    1536,  1536,  1537,  1537,  1537,  1539,  1538,  1541,  1540,  1542,
    1542,  1543,  1542,  1544,  1544,  1545,  1545,  1546,  1547,  1549,
    1548,  1550,  1550,  1552,  1551,  1553,  1553,  1555,  1554,  1556,
    1556,  1558,  1557,  1559,  1559,  1561,  1560,  1562,  1562,  1563,
    1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,
    1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1564,  1565,
    1566,  1566,  1567,  1568,  1569,  1570,  1570,  1571,  1572,  1573,
    1574,  1574,  1575,  1576,  1577,  1578,  1578,  1579,  1580,  1581,
    1582,  1583,  1584,  1585,  1586,  1587,  1588,  1589,  1590,  1591,
    1592,  1593,  1594,  1594,  1595,  1596,  1597,  1598,  1598,  1599,
    1600,  1601,  1602,  1603,  1603,  1604,  1605,  1606,  1607,  1608,
    1609,  1610,  1611,  1612,  1613,  1614,  1615,  1617,  1616,  1618,
    1618,  1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627
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
       1,     1,     1,     3,     7,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     1,     2,     3,     1,     0,     2,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     0,     1,     1,     1,     1,     3,
       3,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     0,     2,     1,     1,     3,
       0,     2,     1,     1,     1,     1,     3,     7,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     2,     3,     1,     0,
       2,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     0,     1,     1,
       1,     1,     3,     3,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     0,     2,
       1,     1,     3,     0,     2,     1,     1,     1,     1,     3,
       7,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     2,
       3,     1,     0,     2,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       0,     1,     1,     1,     1,     4,     0,     3,     1,     1,
       1,     1,     1,     4,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     2,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     1,
       2,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     1,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     2,     0,
       2,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       3,     3,     1,     1,     2,     1,     3,     1,     1,     0,
       2,     3,     1,     0,     1,     3,     3,     1,     1,     2,
       1,     3,     1,     0,     2,     3,     1,     0,     1,     3,
       3,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     0,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     0,
       2,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     3,     1,
       2,     1,     1,     1,     1,     3,     1,     4,     1,     1,
       0,     2,     1,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     3,     1,     4,     1,     1,     0,     2,     1,
       1,     3,     0,     2,     0,     2,     1,     1,     1,     1,
       3,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     3,     0,     2,     3,     1,     0,
       1,     3,     4,     1,     1,     0,     2,     1,     1,     3,
       0,     2,     0,     2,     1,     1,     1,     1,     3,     0,
       2,     2,     1,     1,     1,     1,     3,     4,     1,     1,
       0,     2,     1,     1,     3,     0,     2,     0,     2,     1,
       1,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     3,     4,     1,     1,     0,     2,     1,     1,     3,
       0,     2,     2,     1,     1,     1,     1,     3,     1,     4,
       1,     1,     0,     2,     1,     1,     3,     0,     2,     0,
       2,     1,     1,     1,     1,     3,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     3,     4,     1,     1,     0,
       2,     1,     1,     3,     0,     2,     0,     2,     1,     1,
       1,     1,     3,     0,     2,     3,     1,     0,     2,     1,
       1,     1,     2,     1,     4,     1,     1,     0,     2,     1,
       1,     3,     0,     2,     2,     1,     1,     1,     1,     3,
       1,     5,     1,     0,     1,     1,     3,     1,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     1,     2,     0,     3,     1,     2,     0,
       5,     0,     5,     0,     5,     0,     4,     0,     5,     0,
       5,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     3,     1,     1,     0,     4,     0,     6,
       0,     4,     0,     4,     0,     4,     3,     1,     1,     2,
       0,     2,     1,     1,     1,     0,     4,     0,     4,     1,
       2,     0,     4,     0,     2,     1,     1,     4,     4,     0,
       4,     0,     2,     0,     4,     0,     2,     0,     4,     0,
       2,     0,     4,     0,     2,     0,     4,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     2,     4,     3,     1,     1,     2,     4,     3,     1,
       1,     2,     4,     3,     1,     1,     2,     4,     2,     1,
       2,     2,     1,     3,     2,     1,     2,     2,     1,     2,
       4,     1,     0,     1,     2,     4,     1,     0,     1,     2,
       3,     2,     1,     1,     2,     2,     1,     3,     2,     1,
       2,     2,     1,     3,     2,     1,     3,     0,     4,     0,
       2,     2,     1,     3,     2,     1,     6,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,  1006,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   140,     0,
    1012,  1009,  1005,  1007,  1008,    16,    10,     3,     8,     9,
     142,   219,     0,     0,    24,    19,    21,    22,     0,  1011,
      14,   221,   297,     0,     0,   146,   141,   143,   144,    39,
      64,   120,   104,   112,    23,    72,    80,    88,    96,     0,
      26,    27,    29,     0,    30,     0,    31,     0,    32,     0,
      33,     0,    34,     0,    35,     0,    36,     0,    37,     0,
    1010,     0,  1023,  1022,     0,  1029,  1028,     0,  1035,  1034,
       0,  1041,  1040,     0,  1047,  1046,  1013,  1014,  1019,  1020,
    1021,  1015,  1025,  1026,  1027,  1016,  1031,  1032,  1033,  1017,
    1037,  1038,  1039,  1018,  1043,  1044,  1045,    11,   299,   440,
       0,     0,   225,   220,   222,   223,   193,   184,   166,   175,
     199,   158,   145,     0,   148,   149,   151,     0,   152,   168,
     153,   177,   154,   186,   155,   194,   156,     0,    25,    28,
     999,  1500,     0,  1536,     0,     0,    40,    41,    45,    44,
    1498,  1499,    43,  1534,  1535,     0,    68,    63,    65,    66,
       0,    76,    71,    73,    74,     0,    84,    79,    81,    82,
       0,    92,    87,    89,    90,     0,   100,    95,    97,    98,
       0,   108,   103,   105,   106,     0,   116,   111,   113,   114,
     999,     0,   121,     0,     0,     0,     0,     0,   442,    15,
     444,     0,   303,   298,   300,   301,   245,   237,   277,   269,
     261,   253,   224,     0,   227,   228,   230,     0,   231,     0,
     232,     0,   233,     0,   234,     0,   235,     0,   147,   150,
       0,   162,   157,   159,   160,     0,   167,     0,   176,     0,
     185,     0,   195,     0,   200,     0,     0,     0,     0,     0,
      49,    38,    46,    47,    42,    70,    67,     0,    78,    75,
       0,    86,    83,     0,    94,    91,     0,   102,    99,     0,
     110,   107,     0,   118,   115,     0,     0,     0,   125,   119,
     122,   123,  1024,  1030,  1036,  1042,  1048,     0,   443,   344,
     352,   420,   336,   320,   328,   360,   414,   405,   387,   396,
     302,     0,   305,   306,   308,     0,   309,     0,   310,     0,
     311,     0,   312,     0,   313,     0,   314,   389,   315,   398,
     316,   407,   317,   415,   318,     0,   226,   229,     0,   241,
     236,   238,   239,     0,   249,   244,   246,   247,     0,   257,
     252,   254,   255,     0,   265,   260,   262,   263,     0,   273,
     268,   270,   271,     0,   278,   164,   161,     0,     0,   165,
    1540,     0,   169,   171,   170,  1538,  1539,     0,   174,   178,
     180,   179,     0,   183,   187,   189,   188,     0,   192,     0,
     204,   198,   201,   202,   999,   998,  1001,  1002,  1003,  1004,
    1000,  1501,  1537,    48,    55,     0,    51,    52,    57,    69,
      77,    85,    93,   101,   109,   117,   999,   124,   131,     0,
     127,   128,   133,     0,   453,   441,   450,   451,   999,     0,
       0,     0,   445,   446,   448,   449,   447,   304,   307,     0,
     324,   319,   321,   322,     0,   332,   327,   329,   330,     0,
     340,   335,   337,   338,     0,   348,   343,   345,   346,     0,
     356,   351,   353,   354,   999,     0,   361,     0,   388,     0,
     397,     0,   406,     0,   416,     0,   421,   243,   240,     0,
     251,   248,     0,   259,   256,     0,   267,   264,     0,   993,
     994,   272,     0,   275,     0,   282,   276,   279,   280,   163,
       0,   173,     0,     0,   182,     0,   191,   197,     0,   203,
     210,     0,   206,   207,   212,   991,    50,    53,     0,    56,
     986,   126,   129,     0,   132,   459,   452,     0,   946,   456,
     461,     0,     0,     0,     0,   326,   323,     0,   334,   331,
       0,   342,   339,     0,   350,   347,     0,   358,   355,     0,
       0,     0,   365,   359,   362,   363,     0,   386,   390,   392,
     391,     0,   395,   399,   401,   400,     0,   404,   408,   410,
     409,     0,   413,     0,   425,   419,   422,   423,   242,   250,
     258,   266,   274,   281,   288,     0,   284,   285,   290,   172,
    1541,   181,   190,   196,   205,   208,     0,   211,     0,    62,
      54,  1512,     0,    58,    60,    59,  1510,  1511,     0,   139,
     130,  1544,     0,   134,   137,   135,   136,  1542,  1543,   454,
     948,   457,   455,     0,     0,   460,   999,     0,     0,     0,
     325,   333,   341,   349,   357,   999,   371,   364,     0,   367,
     368,   372,     0,   394,     0,   403,     0,   412,   418,     0,
     424,   431,     0,   427,   428,   433,   283,   286,     0,   289,
       0,   218,   209,   213,   216,   214,   215,    61,     0,   138,
       0,   999,     0,   949,     0,   458,     0,     0,   999,   462,
     463,   464,   465,   989,  1455,  1461,  1466,   992,   366,   369,
       0,   393,   402,   411,   417,   426,   429,     0,   432,     0,
     296,   287,   291,   294,   292,   293,   217,  1513,  1545,     0,
       0,   953,   947,   950,   951,   471,   495,     0,   999,   999,
       0,     0,   381,  1492,     0,   373,   370,   378,   379,   376,
    1490,  1491,   377,   375,   374,     0,   439,   430,   434,   437,
     435,   436,   295,   999,   952,   959,     0,   955,   956,   961,
     497,   504,     0,     0,   472,   473,   477,   476,   475,   468,
     467,   999,   385,   384,   380,     0,   383,     0,   438,   990,
     954,   957,     0,   960,   506,   631,   507,     0,   501,   496,
     498,   499,     0,   481,   470,   478,   479,   474,   466,   382,
    1493,     0,   970,   958,   967,   968,     0,   962,   966,   964,
     965,   963,   633,   734,   634,   999,     0,   508,   503,   500,
       0,   480,   487,     0,   483,   484,   489,   969,   979,     0,
     978,     0,   972,   973,   975,   976,   977,     0,   736,   837,
     737,   999,     0,   635,     0,   514,   511,   505,   509,   510,
     502,   482,   485,     0,   488,   981,     0,   971,   974,     0,
     839,   909,   840,   999,     0,   738,     0,   641,   638,   632,
     636,   637,   999,   516,     0,   533,     0,     0,   494,   486,
     490,   492,   491,   980,  1458,   911,     0,     0,   999,     0,
     841,     0,   744,   741,   735,   739,   740,   999,   643,     0,
     660,     0,   988,   512,   535,   557,     0,     0,     0,   517,
     493,   469,   999,     0,   912,     0,   846,   844,   838,   842,
     843,   999,   746,     0,   763,     0,   985,   639,   662,   682,
       0,     0,     0,   644,   559,   579,     0,     0,   536,     0,
       0,   521,   515,   518,   519,     0,     0,   916,   910,   913,
     914,   999,   848,   906,     0,   982,   742,   765,   785,     0,
       0,     0,   747,   640,   668,   665,   661,   663,   664,     0,
       0,   648,   642,   645,   646,   513,   565,   562,   558,   560,
     561,     0,   540,   534,   537,   538,     0,   520,   527,     0,
     523,   524,   528,   999,   922,   915,     0,   918,   919,   924,
     983,     0,   999,     0,   849,   743,   771,   768,   764,   766,
     767,     0,     0,   751,   745,   748,   749,   685,   683,   687,
    1091,     0,   670,   669,     0,     0,   647,   654,     0,   650,
     651,   655,   582,   580,   584,     0,   567,   566,   539,   546,
       0,   542,   543,   547,  1464,   522,   525,     0,   987,   917,
     920,     0,   923,   908,   845,   907,     0,   855,   852,   847,
     850,   851,   788,   786,   790,     0,   773,   772,     0,   750,
     757,     0,   753,   754,   758,     0,   686,   666,  1098,   672,
     671,     0,     0,     0,  1139,  1460,   649,   652,     0,     0,
     583,   563,   569,   568,   541,   544,     0,     0,     0,   529,
     526,   530,   531,     0,   934,   921,   931,   932,   925,   930,
     928,   929,   926,   927,   999,   857,   866,     0,     0,   789,
     769,   775,   774,  1454,   752,   755,     0,     0,   701,   684,
     698,   699,     0,  1528,     0,  1504,     0,  1516,     0,   688,
     690,   689,   697,   696,  1502,  1503,   693,   695,  1514,  1515,
     692,  1526,  1527,   694,   691,  1105,   674,   673,     0,     0,
       0,  1051,  1094,  1090,  1092,  1093,     0,   656,   653,   657,
     658,     0,   598,   581,   595,   596,  1552,     0,   585,   587,
     586,   594,   593,   590,   589,   591,   588,   592,  1550,  1551,
     571,   570,     0,   554,   548,   545,   551,   552,   549,   550,
       0,     0,   933,   943,     0,   942,     0,   936,   937,   939,
     940,   941,   984,     0,     0,     0,   858,     0,   804,   787,
     801,   802,  1496,     0,   791,   792,   793,   798,  1494,  1495,
     800,   799,   796,   795,   797,   794,   777,   776,     0,   759,
     756,   760,   761,   722,   708,   700,     0,   703,   705,   709,
     704,   719,   724,     0,     0,     0,     0,  1112,   676,   675,
       0,     0,  1051,  1101,  1097,  1099,  1100,     0,     0,  1096,
    1049,  1050,     0,     0,   619,   605,   597,     0,   600,   602,
     606,   601,   616,   621,     0,   573,   572,   556,   553,     0,
     532,     0,   945,     0,   935,   938,   854,   869,   853,   867,
     871,     0,   864,   861,   856,   859,   860,   825,   811,   803,
       0,   806,   808,   812,   807,   822,   827,     0,   779,   778,
       0,   702,   706,     0,   720,     0,   723,     0,  1529,  1505,
    1517,  1119,   678,   677,     0,     0,  1051,  1108,  1104,  1106,
    1107,  1103,     0,  1456,     0,     0,  1054,  1052,  1056,  1095,
     659,   599,   603,     0,   617,     0,   620,  1553,   575,   574,
     555,  1475,   944,     0,   870,     0,     0,   805,   809,     0,
     823,     0,   826,  1497,   781,   780,   762,     0,   716,   710,
     707,   713,   714,   711,   712,  1051,   731,   721,   729,   730,
     725,   726,   728,   727,  1457,  1126,   680,   679,     0,     0,
    1051,  1115,  1111,  1113,  1114,  1110,     0,  1102,     0,     0,
    1065,  1061,  1062,  1063,     0,  1055,     0,   613,   607,   604,
     610,   611,   608,   609,  1051,   628,   618,   626,   627,   622,
     623,   625,   624,   577,   576,     0,   885,   868,   882,   883,
    1508,     0,   872,   874,   873,   881,   880,   879,  1506,  1507,
     877,   876,   878,   875,  1459,   863,  1141,   862,   865,  1143,
       0,   819,   813,   810,   816,   817,   814,   815,  1051,   834,
     824,   832,   833,   828,   829,   831,   830,   783,   782,   995,
     996,   997,   715,     0,   718,     0,   733,  1133,   667,   681,
       0,     0,  1051,  1122,  1118,  1120,  1121,  1117,     0,  1109,
       0,     0,  1064,     0,  1053,     0,     0,  1057,  1059,  1058,
     612,     0,   615,     0,   630,   564,   578,   894,   884,     0,
     888,   887,   891,   896,   889,     0,     0,  1142,   818,     0,
     821,     0,   836,   770,   784,   717,   732,     0,  1051,  1129,
    1125,  1127,  1128,  1124,     0,  1116,  1467,  1066,     0,     0,
       0,   614,   629,   886,   890,   892,     0,   895,  1509,  1156,
    1153,  1140,  1151,  1152,  1532,     0,     0,     0,   999,  1144,
    1147,  1146,  1150,  1148,  1145,  1530,  1531,  1149,   820,   835,
    1051,  1136,  1132,  1134,  1135,  1131,     0,  1123,  1060,     0,
       0,  1051,   903,   893,   901,   902,   897,   898,   900,   899,
    1158,     0,  1173,  1160,     0,     0,     0,     0,  1138,     0,
    1130,  1476,  1478,     0,   905,  1154,  1155,     0,  1159,  1533,
       0,     0,   999,  1137,   904,  1417,  1187,  1367,  1218,  1235,
    1340,  1323,  1273,  1298,  1395,  1412,  1174,  1175,  1189,  1176,
    1220,  1177,  1237,  1178,  1275,  1182,  1300,  1179,  1325,  1180,
    1342,  1181,  1369,  1183,  1397,  1184,  1413,  1185,     0,     0,
    1172,  1157,  1488,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1161,  1162,  1165,  1166,  1167,  1168,  1163,  1164,
    1170,  1169,  1486,  1487,  1453,  1462,  1477,     0,  1188,     0,
    1219,     0,  1236,     0,  1274,     0,  1299,     0,  1324,     0,
    1341,     0,  1368,     0,  1396,  1524,     0,     0,  1414,  1522,
    1523,     0,     0,  1418,  1171,   999,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1520,     0,     0,  1190,  1191,
    1192,  1518,  1519,     0,  1221,  1222,  1223,     0,  1238,  1239,
    1240,     0,  1276,  1277,  1278,     0,  1301,  1302,  1303,     0,
    1326,  1327,  1328,     0,  1343,  1344,  1345,     0,  1370,  1371,
    1372,     0,  1398,  1399,  1400,     0,     0,     0,     0,  1416,
    1489,     0,     0,     0,     0,     0,     0,     0,     0,  1197,
    1186,  1194,     0,     0,     0,  1225,  1217,  1242,  1234,  1280,
    1272,  1305,  1297,  1330,  1322,  1347,  1339,  1374,  1366,  1402,
    1394,  1525,  1694,  1699,  1704,  1709,  1712,  1721,  1726,  1732,
    1736,  1739,  1742,  1745,  1747,  1752,  1755,  1758,  1689,  1715,
    1718,     0,  1669,     0,  1670,     0,  1671,     0,  1672,     0,
    1673,     0,  1674,     0,  1687,     0,  1675,     0,  1676,  1722,
    1677,  1727,  1678,     0,  1679,     0,  1680,     0,  1681,     0,
    1682,     0,  1683,  1684,     0,  1685,     0,  1686,     0,     0,
    1422,     0,     0,  1468,  1479,  1480,  1469,  1470,  1471,  1472,
    1485,  1204,     0,     0,     0,  1051,  1200,  1196,  1198,  1199,
    1521,     0,     0,     0,  1244,     0,  1282,     0,  1307,     0,
       0,     0,  1349,     0,  1376,     0,     0,     0,  1749,  1415,
    1411,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1708,     0,  1711,  1599,  1591,  1593,  1597,  1601,  1603,  1649,
    1665,  1611,  1595,  1618,  1605,  1607,  1609,  1637,  1614,  1616,
    1657,  1653,  1661,  1581,  1585,  1589,  1627,  1620,  1622,  1624,
       0,  1575,  1576,  1556,  1557,  1559,  1560,  1561,  1562,  1564,
    1565,  1566,  1568,  1567,  1569,  1571,     0,  1572,  1570,  1578,
    1579,  1580,  1554,  1630,  1555,  1558,  1577,  1573,  1574,  1563,
    1714,     0,  1717,     0,     0,  1723,     0,  1728,     0,  1733,
    1731,     0,  1735,     0,  1738,     0,  1741,     0,  1744,     0,
    1751,     0,  1754,     0,  1757,  1452,  1430,  1437,     0,     0,
    1423,  1193,  1211,  1195,     0,  1051,  1207,  1203,  1205,  1206,
    1202,     0,  1463,  1228,  1226,     0,  1224,  1246,  1243,     0,
    1241,  1284,  1281,     0,  1279,  1309,  1306,     0,  1304,  1333,
    1331,     0,  1329,  1351,  1348,     0,  1346,  1378,  1375,     0,
    1373,  1405,  1403,     0,  1401,     0,     0,     0,  1690,  1688,
       0,     0,  1695,  1693,     0,     0,  1700,  1698,     0,     0,
    1705,  1703,  1710,     0,     0,     0,     0,     0,     0,     0,
    1651,  1667,     0,     0,     0,     0,     0,     0,  1643,     0,
    1659,  1655,  1663,     0,     0,     0,     0,     0,     0,  1716,
       0,     0,  1719,     0,     0,     0,  1734,     0,  1740,     0,
       0,     0,     0,  1759,     0,     0,  1431,  1051,  1426,  1421,
    1424,  1425,  1069,  1214,  1210,  1212,  1213,  1209,     0,  1201,
    1051,  1231,  1227,  1229,  1230,  1252,  1249,  1245,  1247,  1248,
    1289,  1287,  1283,  1285,  1286,  1314,  1312,  1308,  1310,  1311,
    1051,  1336,  1332,  1334,  1335,  1356,  1354,  1350,  1352,  1353,
    1383,  1381,  1377,  1379,  1380,  1083,  1408,  1404,  1406,  1407,
    1748,  1750,     0,  1691,     0,  1696,     0,  1701,     0,  1706,
    1713,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1583,  1582,     0,  1587,  1586,     0,     0,     0,     0,
    1615,  1613,     0,  1628,     0,  1632,  1633,  1626,  1631,  1634,
    1730,     0,  1720,     0,  1725,  1737,  1743,  1746,  1753,     0,
    1420,  1440,  1419,  1438,  1442,  1051,  1434,  1429,  1432,  1433,
    1428,     0,     0,  1216,  1067,  1068,     0,  1208,  1233,     0,
       0,  1251,     0,     0,  1338,     0,     0,     0,  1410,  1082,
       0,  1692,  1697,  1702,  1707,     0,     0,     0,     0,  1602,
    1604,  1650,  1652,  1666,  1668,  1612,  1596,     0,  1606,  1608,
    1610,     0,  1639,     0,     0,  1638,  1644,  1645,  1646,  1617,
    1658,  1660,  1654,  1656,  1662,  1664,  1584,  1588,     0,  1621,
    1623,  1625,  1629,  1635,  1724,  1729,     0,     0,  1441,  1436,
       0,  1427,     0,  1072,  1070,  1073,  1215,  1232,  1250,  1255,
    1253,  1257,  1292,  1288,  1290,     0,  1317,  1313,  1315,     0,
    1337,  1359,  1355,  1357,  1360,  1386,  1382,  1384,  1387,  1086,
    1084,  1087,  1409,  1600,  1592,  1594,  1598,     0,  1640,  1641,
       0,     0,  1590,     0,     0,  1156,  1450,  1439,  1448,  1449,
       0,     0,  1443,  1444,  1445,  1446,  1447,  1435,     0,  1080,
    1076,  1077,  1078,     0,  1074,     0,  1256,     0,  1295,  1291,
    1293,  1294,     0,  1320,  1316,  1318,  1319,     0,     0,     0,
    1088,  1619,     0,     0,     0,  1636,  1756,     0,     0,     0,
       0,  1079,     0,  1071,  1265,  1263,  1254,  1261,  1262,     0,
       0,  1258,  1259,  1260,     0,     0,     0,  1548,     0,  1361,
    1358,  1364,  1363,  1362,  1546,  1547,     0,  1393,     0,     0,
    1388,  1385,  1391,  1390,  1389,     0,  1085,  1642,  1648,  1647,
    1451,     0,     0,  1081,     0,     0,     0,     0,  1296,  1321,
       0,     0,  1392,     0,     0,     0,  1473,  1474,  1075,  1264,
    1268,  1266,  1269,     0,     0,  1365,  1549,     0,     0,  1089,
       0,     0,  1270,  1465,  1482,  1484,  1483,     0,     0,  1267,
       0,     0,  1481,  1271
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    27,    28,    29,    15,    16,
       8,     9,    18,    19,    35,    36,    37,    59,    60,    61,
      62,    63,   155,   156,   157,   261,   262,   263,   405,   406,
     407,   408,   518,   519,   603,   600,    64,    65,   167,   168,
     169,   267,    66,    67,   172,   173,   174,   270,    68,    69,
     177,   178,   179,   273,    70,    71,   182,   183,   184,   276,
      72,    73,   187,   188,   189,   279,    74,    75,   192,   193,
     194,   282,    76,    77,   197,   198,   199,   285,    78,    79,
     201,   289,   290,   291,   419,   420,   421,   422,   523,   524,
     613,   610,    31,    32,    46,    47,    48,   133,   134,   135,
     136,   137,   242,   243,   244,   367,   138,   139,   245,   246,
     372,   369,   500,   140,   141,   247,   248,   379,   378,   503,
     142,   143,   249,   250,   384,   383,   505,   144,   145,   251,
     388,   508,   146,   147,   253,   391,   392,   393,   511,   512,
     513,   514,   596,   597,   663,   662,    42,    43,   123,   124,
     125,   223,   224,   225,   226,   227,   340,   341,   342,   479,
     228,   229,   345,   346,   347,   482,   230,   231,   350,   351,
     352,   485,   232,   233,   355,   356,   357,   488,   234,   235,
     360,   361,   362,   492,   236,   237,   363,   496,   497,   498,
     585,   586,   587,   588,   658,   659,   702,   701,   119,   120,
     213,   214,   215,   311,   312,   313,   314,   315,   441,   442,
     443,   537,   316,   317,   446,   447,   448,   540,   318,   319,
     451,   452,   453,   543,   320,   321,   456,   457,   458,   546,
     322,   323,   461,   462,   463,   549,   324,   325,   465,   553,
     554,   555,   638,   639,   640,   641,   690,   725,   726,   727,
     728,   765,   766,   326,   327,   467,   468,   558,   557,   642,
     328,   329,   469,   470,   563,   562,   644,   330,   331,   471,
     472,   568,   567,   646,   332,   333,   473,   572,   649,   334,
     335,   475,   575,   576,   577,   652,   653,   654,   655,   697,
     698,   738,   737,   209,   210,   297,   298,   432,   425,   426,
     427,   527,   528,   529,   530,   624,   625,   679,   680,   681,
     682,   675,   716,   717,   753,   754,   755,   784,   785,   786,
     813,   814,   815,   816,   843,   844,   870,   869,   751,   752,
     779,   780,   781,   810,   775,   776,   806,   837,   838,   839,
     864,   865,   866,   898,   932,   933,   934,   979,   980,   981,
     982,  1037,  1089,  1090,   895,   896,   927,   973,   974,   975,
    1030,  1031,  1032,  1033,  1086,  1184,  1185,  1186,  1187,  1279,
     925,   926,   968,   969,   970,  1025,  1026,  1082,  1180,  1275,
    1348,  1423,  1505,   965,  1023,  1024,  1079,  1080,  1168,  1163,
    1164,  1165,  1267,  1268,  1269,  1270,  1343,  1408,  1409,  1410,
    1411,  1501,  1271,  1272,  1273,  1345,  1346,  1419,  1416,  1417,
    1418,  1503,   803,   804,   832,   859,   860,   861,   889,   890,
     891,   922,   962,   963,   964,  1018,  1019,  1020,  1021,  1078,
    1157,  1158,   919,   920,   956,   957,   958,  1011,  1012,  1069,
    1146,  1248,  1322,  1386,  1478,   953,  1008,  1009,  1065,  1066,
    1129,  1119,  1120,  1121,  1236,  1237,  1238,  1239,  1313,  1369,
    1370,  1371,  1372,  1473,  1240,  1241,  1242,  1315,  1316,  1380,
    1377,  1378,  1379,  1475,   829,   830,   854,   884,   885,   886,
     913,   914,   915,   951,  1004,  1005,  1006,  1061,  1062,  1063,
    1064,  1116,  1229,  1230,   948,   949,   998,   999,  1000,  1055,
    1056,  1111,  1226,  1308,  1364,  1467,  1523,   995,  1053,  1054,
    1108,  1109,  1214,  1209,  1210,  1211,  1300,  1301,  1302,  1303,
    1359,  1452,  1453,  1454,  1455,  1519,  1304,  1305,  1306,  1361,
    1362,  1463,  1460,  1461,  1462,  1521,   851,   852,   879,   908,
     909,   910,   943,   944,   993,  1049,  1050,  1051,  1288,  1106,
    1107,  1205,  1294,  1295,  1296,  1447,  1356,  1203,  1289,  1290,
    1353,  1354,  1432,  1427,  1428,  1429,  1509,  1510,  1511,  1512,
    1513,  1546,  1547,  1586,  1583,  1584,  1585,  1603,   991,  1045,
     876,   877,   903,   938,   939,   940,   986,   987,   988,   989,
    1041,  1042,  1098,  1095,  1096,  1097,  1196,  1197,  1198,  1199,
    1200,  1201,  1283,   622,   623,   672,   712,   713,   714,   746,
     747,   748,   749,   772,   773,   797,   793,   794,   795,   821,
     822,   823,   824,   825,   826,   846,   855,   880,   994,   833,
     202,   904,   807,   433,   673,   158,   466,   493,  1474,   255,
     256,   400,    10,    11,    22,    23,    24,    38,    39,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
    1259,  1260,  1337,  1338,  1404,  1405,  1497,  1494,  1261,  1401,
    1402,  1403,  2223,  2224,  2294,  2295,  2353,  2383,  2225,  2350,
    2351,  2352,  2238,  2239,  2320,  2321,  2369,  2416,  1013,  1014,
    1153,  1154,  1155,  1262,  1070,  1071,  1254,  1255,  1256,  1332,
    1147,  1148,  1328,  1329,  1330,  1396,  1249,  1250,  1392,  1393,
    1394,  1488,  1323,  1324,  1484,  1485,  1486,  1534,  1387,  1388,
    1530,  1531,  1532,  1576,  1479,  1480,  1572,  1573,  1574,  1599,
    1073,  1448,  1449,  1516,  1517,  1559,  1551,  1552,  1553,  1591,
    1592,  1593,  1607,  1608,  1662,  1651,  1606,  1626,  1627,  1628,
    1677,  1678,  1718,  1770,  1862,  1771,  1772,  1867,  1868,  1869,
    2001,  1863,  1864,  1997,  1998,  1999,  2108,  1993,  1994,  2104,
    2105,  2106,  2226,  1629,  1630,  1679,  1680,  1724,  1776,  1873,
    2004,  2005,  2112,  2113,  2114,  2229,  1631,  1632,  1681,  1682,
    1728,  1778,  1875,  2008,  2009,  2117,  2118,  2119,  2230,  2231,
    2300,  2301,  2355,  2356,  2391,  2386,  2387,  2388,  2425,  2441,
    2442,  2451,  2459,  1633,  1634,  1683,  1684,  1732,  1780,  1877,
    2012,  2013,  2122,  2123,  2124,  2232,  2304,  2305,  2359,  2360,
    2361,  1635,  1636,  1685,  1686,  1736,  1782,  1879,  2016,  2017,
    2127,  2128,  2129,  2233,  2308,  2309,  2364,  2365,  2366,  1637,
    1638,  1687,  1688,  1740,  1784,  1881,  2020,  2021,  2132,  2133,
    2134,  2235,  1639,  1640,  1689,  1690,  1744,  1786,  1883,  2024,
    2025,  2137,  2138,  2139,  2236,  2313,  2314,  2367,  2399,  2400,
    1641,  1642,  1691,  1692,  1748,  1788,  1885,  2028,  2029,  2142,
    2143,  2144,  2237,  2317,  2318,  2368,  2410,  2411,  1643,  1644,
    1693,  1694,  1752,  1790,  1887,  2032,  2033,  2147,  2148,  2149,
    2240,  1645,  1646,  1697,  1890,  1647,  1648,  1702,  1759,  2212,
    1851,  1852,  1989,  2099,  2100,  2101,  2221,  1987,  1988,  2095,
    2217,  2218,  2219,  2290,  2094,  2213,  2214,  2287,  2288,  2342,
    2337,  2338,  2339,  1703,  1560,   952,   434,  1074,  1130,   798,
    1206,   923,   435,  1561,  1719,   899,  2392,   436,  1335,  1663,
    1664,  1665,  1666,  1667,  2343,  2344,  1091,  1498,  1562,  1499,
    1668,  1669,  2452,  2393,  2413,  2414,  1670,  1671,  1672,  1673,
     729,   730,   731,  1217,  1218,  1219,   159,   160,   161,  1133,
    1134,  1135,  1437,  1438,  1439,   605,   606,   607,  1137,  1138,
    1139,  1720,  1721,  1722,  1698,  1699,  1700,  1140,  1141,  1142,
    1564,  1565,  1566,   162,   163,   164,   374,   375,   376,   616,
     617,   618,  2403,  2404,  2405,  1177,  1178,  1179,  1930,  1931,
    2073,  2182,  1932,  2074,  2185,  1933,  2075,  1934,  2055,  1935,
    2056,  1936,  2063,  1937,  2057,  1938,  2054,  1939,  2058,  1940,
    2059,  1941,  2065,  1942,  2066,  1943,  2067,  1944,  2062,  1945,
    1946,  2191,  1947,  2069,  1948,  2064,  1949,  2076,  1950,  2077,
    1951,  2078,  1952,  1953,  2197,  2081,  2198,  2199,  2333,  1954,
    2068,  2265,  2372,  2175,  2266,  2267,  2268,  1955,  2060,  2167,
    1956,  2071,  2178,  1957,  2070,  2177,  1958,  2072,  2179,  1959,
    2061,  2168,  1811,  1812,  1813,  2039,  1892,  1814,  1815,  2043,
    1894,  1816,  1817,  2047,  1896,  1818,  1819,  2051,  1898,  1820,
    1821,  1900,  1822,  1823,  1902,  1824,  1825,  1960,  1826,  1827,
    1962,  1828,  1829,  1964,  2202,  1830,  1831,  1966,  2204,  1965,
    1832,  1833,  1970,  1834,  1835,  1972,  1836,  1837,  1974,  1838,
    1839,  1976,  1840,  1841,  1978,  1842,  1888,  2035,  1843,  1844,
    1980,  1845,  1846,  1982,  1847,  1848,  1984
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2144
static const yytype_int16 yypact[] =
{
     285, -2144, -2144,   162,    65,   125, -2144, -2144,   158,  -130,
   -2144,   444, -2144,   485, -2144, -2144, -2144, -2144,  -124,   533,
   -2144, -2144, -2144, -2144, -2144,    65, -2144, -2144, -2144, -2144,
   -2144,  -108,   542,     0, -2144, -2144, -2144, -2144,   197,  1101,
     158, -2144,    -7,   554,    53, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,    20,
      22, -2144, -2144,   245, -2144,   556, -2144,   559, -2144,   582,
   -2144,   589, -2144,   591, -2144,   593, -2144,   595, -2144,   346,
   -2144,   375, -2144, -2144,   414, -2144, -2144,   420, -2144, -2144,
     425, -2144, -2144,   429, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   135,
     601,    81, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144,   151,   350, -2144, -2144,   604, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,   453, -2144,   346, -2144, -2144,
   -2144, -2144,   465, -2144,   467,   608,   245, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,   149, -2144, -2144, -2144, -2144,
      17, -2144, -2144, -2144, -2144,     6, -2144, -2144, -2144, -2144,
      12, -2144, -2144, -2144, -2144,     4, -2144, -2144, -2144, -2144,
     157, -2144, -2144, -2144, -2144,    93, -2144, -2144, -2144, -2144,
   -2144,   612, -2144,   324,   348,   347,   349,   351, -2144, -2144,
   -2144,    42, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144,   172,   416, -2144, -2144,   616, -2144,   620,
   -2144,   626, -2144,   638, -2144,   646, -2144,   346, -2144, -2144,
     111, -2144, -2144, -2144, -2144,   483,   339,   487,   339,   494,
     339,   501, -2144,   657, -2144,   519,    11,   522,   524,   330,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144,   474, -2144, -2144,
     204, -2144, -2144,   210, -2144, -2144,   218, -2144, -2144,   240,
   -2144, -2144,   513, -2144, -2144,   500,   602,   -50, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144,   661,   164, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144,   308,   383, -2144, -2144,   666, -2144,   671, -2144,   673,
   -2144,   675, -2144,   691, -2144,   596, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144,   453, -2144,   346, -2144, -2144,   133, -2144,
   -2144, -2144, -2144,   130, -2144, -2144, -2144, -2144,   108, -2144,
   -2144, -2144, -2144,   100, -2144, -2144, -2144, -2144,   283, -2144,
   -2144, -2144, -2144,   701, -2144, -2144, -2144,   560,   708, -2144,
   -2144,   656, -2144, -2144, -2144, -2144, -2144,   708, -2144, -2144,
   -2144, -2144,   708, -2144, -2144, -2144, -2144,   663, -2144,   -40,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,   606,   585, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   623,
     338, -2144, -2144,   -25, -2144, -2144, -2144, -2144, -2144,   717,
     733,   736, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   129,
   -2144, -2144, -2144, -2144,    99, -2144, -2144, -2144, -2144,   109,
   -2144, -2144, -2144, -2144,   398, -2144, -2144, -2144, -2144,   117,
   -2144, -2144, -2144, -2144, -2144,   706, -2144,   724,   339,   738,
     339,   742,   339,   746, -2144,   710, -2144, -2144, -2144,   669,
   -2144, -2144,   711, -2144, -2144,   659, -2144, -2144,   682, -2144,
   -2144, -2144,   689, -2144,   -30, -2144, -2144, -2144, -2144, -2144,
     727, -2144,   771,   740, -2144,   748, -2144, -2144,   744, -2144,
   -2144,   757,   450, -2144, -2144, -2144, -2144, -2144,   712,   391,
   -2144, -2144, -2144,   726,   373, -2144, -2144,   526,    87, -2144,
   -2144,   787,   836,   840,   842, -2144, -2144,   765, -2144, -2144,
     767, -2144, -2144,   781, -2144, -2144,   828, -2144, -2144,   805,
     861,   337, -2144, -2144, -2144, -2144,   708, -2144, -2144, -2144,
   -2144,   708, -2144, -2144, -2144, -2144,   708, -2144, -2144, -2144,
   -2144,   863, -2144,   -19, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,   806,   534, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,   729,   373,   788, -2144,
   -2144, -2144,   876, -2144, -2144, -2144, -2144, -2144,   539, -2144,
   -2144, -2144,   880, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144,   857,   879,   461, -2144,   896,   915,   919,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   792,   837,
   -2144, -2144,   824, -2144,   826, -2144,   832, -2144, -2144,   830,
   -2144, -2144,   874,   610, -2144, -2144, -2144, -2144,   779,   373,
     603, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   935, -2144,
     939, -2144,   796, -2144,   865, -2144,   950,   954, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
     235, -2144, -2144, -2144, -2144, -2144, -2144,   798,   373,   622,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   956,
      78, -2144, -2144, -2144, -2144, -2144,   906,   245, -2144, -2144,
     969,   118, -2144, -2144,   974, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,   637, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,   908,   901, -2144, -2144,
   -2144,   678,   802,   804,   245, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,   898, -2144,   981, -2144, -2144,
   -2144, -2144,   808,   411, -2144,   690,   971,   154, -2144, -2144,
   -2144, -2144,   232, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144,   229, -2144, -2144, -2144, -2144,   989, -2144, -2144, -2144,
   -2144, -2144, -2144,   731,  1005, -2144,   810, -2144, -2144, -2144,
     967, -2144, -2144,   947,   946, -2144, -2144, -2144, -2144,  1050,
   -2144,   976,   286, -2144, -2144, -2144, -2144,  1051, -2144,   778,
    1043, -2144,   812, -2144,  1059,   923, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144,   816,   302, -2144,   917, -2144, -2144,  1061,
   -2144,  1003,  1064, -2144,   819, -2144,  1088,   952, -2144, -2144,
   -2144, -2144, -2144, -2144,   790,   990,   891,  1013, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,  1027,  1085, -2144,   821,
   -2144,  1104,  1062, -2144, -2144, -2144, -2144, -2144, -2144,   831,
    1070,   921, -2144, -2144, -2144,  1089,   891,  1129,   823, -2144,
   -2144, -2144, -2144,   827, -2144,  1133,   856, -2144, -2144, -2144,
   -2144, -2144, -2144,   843,  1105,   938, -2144, -2144, -2144, -2144,
     829,  1143,   883, -2144, -2144, -2144,   885,   887, -2144,  1147,
     -46, -2144, -2144, -2144, -2144,  1149,   377, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144,  1128, -2144, -2144, -2144, -2144,   889,
    1151,   892, -2144,   820,   838, -2144, -2144, -2144, -2144,  1159,
     -34, -2144, -2144, -2144, -2144,   844,   838, -2144, -2144, -2144,
   -2144,   -36, -2144, -2144, -2144, -2144,  1161, -2144, -2144,  1022,
     866, -2144, -2144, -2144, -2144, -2144,  1102,  1109, -2144, -2144,
   -2144,   -28, -2144,  1233, -2144,   846,   838, -2144, -2144, -2144,
   -2144,  1173,    -9, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144,  1136,   862, -2144,  1031,  1183, -2144, -2144,  1048,   894,
   -2144, -2144, -2144, -2144, -2144,  1152,   862, -2144, -2144, -2144,
    1090,   902, -2144, -2144, -2144, -2144, -2144,    54, -2144, -2144,
   -2144,  1235,   345, -2144, -2144, -2144,  1193,  1065, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,  1158,   862, -2144,  1203, -2144,
   -2144,  1164,   920, -2144, -2144,  1237,   633, -2144, -2144,   905,
   -2144,  1031,  1211,  1239, -2144, -2144, -2144, -2144,   139,  1241,
     475, -2144,   905, -2144, -2144, -2144,    52,   708,  1224, -2144,
   -2144, -2144, -2144,    51, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144,  1019,  1243,   528,
   -2144,   905, -2144, -2144, -2144, -2144,   173,   -89, -2144, -2144,
   -2144, -2144,  1232, -2144,  1338, -2144,  1339, -2144,  1340, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,  1025, -2144,  1031,  1245,
    1341,  1190, -2144, -2144, -2144, -2144,   708, -2144, -2144, -2144,
   -2144,   -27, -2144, -2144, -2144, -2144, -2144,  1345, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
    1025, -2144,     8, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
    1044,  1343, -2144, -2144,  1346, -2144,  1284,   376, -2144, -2144,
   -2144, -2144, -2144,  -174,  1344,  1247, -2144,   -18, -2144, -2144,
   -2144, -2144, -2144,  1351, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,  1025, -2144,   708, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,  1014,  1054, -2144, -2144,
    1207, -2144, -2144,  1352,  1353,  1354,  1355, -2144,  1032, -2144,
    1031,  1249,  1190, -2144, -2144, -2144, -2144,  1356,  1130, -2144,
    1217, -2144,  1042,  1067, -2144, -2144, -2144,  1028,  1066, -2144,
   -2144,  1222, -2144, -2144,  1359,  1032, -2144, -2144, -2144,  1068,
   -2144,  1365, -2144,  1221, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144,  1370, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
    1035,  1082, -2144, -2144,  1228, -2144, -2144,  1372,  1032, -2144,
    1083, -2144, -2144,    59, -2144,  1251,   249,  1374, -2144, -2144,
   -2144, -2144,  1055, -2144,  1031,  1253,  1190, -2144, -2144, -2144,
   -2144, -2144,  1063, -2144,  1375,  1255, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144,    61, -2144,  1257,   249, -2144,  1055, -2144,
   -2144, -2144, -2144,  1259,   418,  1378,   -23, -2144, -2144,    90,
   -2144,  1261,   249, -2144,  1055, -2144, -2144,    19, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,  1190, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,  1056, -2144,  1031,  1263,
    1190, -2144, -2144, -2144, -2144, -2144,  1069, -2144,  1382,    79,
   -2144, -2144, -2144, -2144,  1379,  1041,    48, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144,  1190, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144,  1056, -2144,   -16, -2144, -2144, -2144, -2144,
   -2144,  1387, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
      40, -2144, -2144, -2144, -2144, -2144, -2144, -2144,  1190, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144,  1056, -2144, -2144,
   -2144, -2144, -2144,  1092, -2144,  1240, -2144, -2144, -2144, -2144,
    1031,  1267,  1190, -2144, -2144, -2144, -2144, -2144,  1075, -2144,
    1388,  1242, -2144,  1391, -2144,  1390,  1392, -2144, -2144, -2144,
   -2144,  1095, -2144,  1252, -2144, -2144, -2144, -2144, -2144,  1060,
    1117,  1258, -2144, -2144, -2144,  1397,  1269,   331, -2144,  1111,
   -2144,  1256, -2144, -2144, -2144, -2144, -2144,  1271,  1190, -2144,
   -2144, -2144, -2144, -2144,  1084, -2144, -2144, -2144,  1262,  1404,
    1407, -2144, -2144, -2144, -2144, -2144,  1273,   249, -2144,  1171,
   -2144, -2144, -2144, -2144, -2144,  1413,  1409,  1410, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
    1190, -2144, -2144, -2144, -2144, -2144,  1091, -2144, -2144,  1411,
    1412,  1190, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144,  1134, -2144, -2144,  1415,  1418,  1419,  1420, -2144,  1096,
   -2144, -2144, -2144,  1276, -2144, -2144,   590,  1275,   508, -2144,
    1421,  1422, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,  1114, -2144,  1230,  1189,
   -2144, -2144, -2144,  1430,  1426,  1427,  1428,  1429,  1431,  1432,
    1433,  1434, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144,  1435,   246,  1436,
     246,  1437,   246,  1438,   246,  1439,   246,  1440,   246,  1441,
     246,  1442,   246,  1443,   246, -2144,  1451,  1445, -2144, -2144,
   -2144,  1448,  1447, -2144, -2144, -2144,  1452,  1453,  1454,  1455,
    1456,  1457,  1458,   708,  1165, -2144,  1462,  1459, -2144, -2144,
   -2144, -2144, -2144,  1165, -2144, -2144, -2144,  1165, -2144, -2144,
   -2144,  1165, -2144, -2144, -2144,  1165, -2144, -2144, -2144,  1165,
   -2144, -2144, -2144,  1165, -2144, -2144, -2144,  1165, -2144, -2144,
   -2144,  1165, -2144, -2144, -2144,  1460,   451,  1463,  1194, -2144,
   -2144,  1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471, -2144,
   -2144,  1169,  1279,  1472,  1475,  1169, -2144,  1169, -2144,  1169,
   -2144,  1169, -2144,  1169, -2144,  1169, -2144,  1169, -2144,  1169,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144,  1184, -2144,  1238, -2144,  1250, -2144,  1254, -2144,  1260,
   -2144,   451, -2144,   451, -2144,   815, -2144,   451, -2144,  1026,
   -2144,  1026, -2144,  1281, -2144,   451, -2144,   451, -2144,   451,
   -2144,   451, -2144, -2144,   815, -2144,   815, -2144,   451,  1474,
   -2144,  1234,  1031, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144,  1236,  1209,  1283,  1190, -2144, -2144, -2144, -2144,
   -2144,  1476,  1213,  1231,  1218,  1226,  1219,  1229,  1223,  1244,
    1225,  1246,  1227,  1264,  1248,  1265,  1266,  1268, -2144, -2144,
   -2144,  1486,  1285,  1490,  1287,  1491,  1289,  1493,  1291,  1093,
   -2144,   451, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
    1071, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,   815, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144,  1073, -2144,  1500,  1496, -2144,  1498, -2144,  1097, -2144,
   -2144,   451, -2144,  1086, -2144,   451, -2144,   451, -2144,   451,
   -2144,   815, -2144,  1077, -2144, -2144, -2144, -2144,  1031,  1293,
   -2144, -2144, -2144, -2144,  1295,  1190, -2144, -2144, -2144, -2144,
   -2144,  1270, -2144, -2144, -2144,  1297, -2144, -2144, -2144,  1299,
   -2144, -2144, -2144,  1301, -2144, -2144, -2144,  1303, -2144, -2144,
   -2144,  1305, -2144, -2144, -2144,  1307, -2144, -2144, -2144,  1309,
   -2144, -2144, -2144,  1311, -2144,   334,  1503,  1078, -2144, -2144,
    1512,  1272, -2144, -2144,  1513,  1274, -2144, -2144,  1514,  1277,
   -2144, -2144, -2144,  1107,   815,   815,   815,   815,   815,   815,
   -2144, -2144,   815,   815,   815,   815,   815,   815, -2144,   815,
   -2144, -2144, -2144,  1313,  1315,   815,   451,   451,   451, -2144,
    1138,    30, -2144,  1516,   451,   451, -2144,  1100, -2144,  1103,
    1099,  1098,   815, -2144,  1081,  1319, -2144,  1190, -2144, -2144,
   -2144, -2144,  1376, -2144, -2144, -2144, -2144, -2144,  1278, -2144,
    1190, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
    1190, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144,  1523, -2144,  1525, -2144,  1526, -2144,  1527, -2144,
   -2144,   815,   815,   815,   815,  1170,  1174,   551,   615,  1163,
    1162,   815,  1166,  1157,  1167,    47,  1155,   644,   681,   720,
    1150, -2144, -2144,  1141, -2144, -2144,   815,  1144,  1139,  1142,
   -2144, -2144,  1145, -2144,  1550, -2144, -2144, -2144, -2144, -2144,
   -2144,  1140, -2144,  1137, -2144, -2144, -2144, -2144, -2144,   815,
   -2144, -2144, -2144, -2144, -2144,  1190, -2144, -2144, -2144, -2144,
   -2144,  1308,  1130, -2144,  1414, -2144,  1286, -2144, -2144,  1290,
    1292,  1417,   -62,   -61, -2144,  1294,   -13,    -6, -2144,  1423,
    1296, -2144, -2144, -2144, -2144,  1199,  1201,  1197,  1205, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144,   815, -2144, -2144,
   -2144,   761, -2144,  1555,  1559, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,  1175, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,   451,  1321,   205, -2144,
    1324, -2144,  1323, -2144, -2144,  1347, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,  1325, -2144, -2144, -2144,  1327,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144,  1347, -2144, -2144, -2144, -2144, -2144,  1200, -2144, -2144,
    1569,   708, -2144,  1571,  1146,  1171, -2144, -2144, -2144, -2144,
    1573,  1575, -2144, -2144, -2144, -2144, -2144, -2144,   106, -2144,
   -2144, -2144, -2144,  1574, -2144,  1329,   165,   815, -2144, -2144,
   -2144, -2144,   815, -2144, -2144, -2144, -2144,   187,    74,  1576,
   -2144, -2144,  1202,  1577,  1579, -2144, -2144,  1342,  1583,  1585,
    1444, -2144,   708, -2144, -2144, -2144, -2144, -2144, -2144,  1584,
    1586, -2144, -2144, -2144,  1446,  1449,  1587, -2144,  1593, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,  1461, -2144,  1589,  1592,
   -2144, -2144, -2144, -2144, -2144,  1598, -2144, -2144, -2144, -2144,
   -2144,  1595,  1596, -2144,  1473,     7,  1599,   708, -2144, -2144,
    1477,  1600, -2144,   708,   708,  1478, -2144, -2144, -2144, -2144,
   -2144, -2144,  1369,  1601,  1603, -2144, -2144,  1604,  1605, -2144,
    1606,  1597, -2144, -2144, -2144, -2144, -2144,   708,  1609, -2144,
    1608,  1337, -2144, -2144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,  1578, -2144,
    1594, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,  1560,
   -2144, -2144, -2144, -2144,  1479, -2144, -2144, -2144, -2144, -2144,
    1215, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,  1204, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,  1489,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
    1113, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144,  1405, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144,  1045, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,  1316, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144,   991, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144,   979, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144,  1106, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,   882, -2144, -2144, -2144,
   -2144, -2144,   825, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   653,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144,   607, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144,   369, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144,   370, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144,   621, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144,   405, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,   403, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   583,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   343, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144,   342, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   136,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   662, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,   454, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144,   903, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144,   833, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
     -73, -2144, -2144, -2144, -2144,  -563, -2144,  -368, -1107,  -198,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -1245, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,  -795, -2144,
   -2144, -2144, -2144, -2144,  -633, -2144, -2144, -2144, -2144, -2144,
    -777, -2144, -2144, -2144, -2144, -2144, -1063, -2144, -2144, -2144,
   -2144, -2144,  -980, -2144, -2144, -2144, -2144, -2144,  -979, -2144,
   -2144, -2144, -2144, -2144, -1078, -2144, -2144, -2144, -2144, -2144,
   -1056, -1287, -2144, -2144, -2144, -2144, -2144, -2144, -2144,  -687,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -1073, -2144, -2144, -2144, -2144,
   -2144, -1003, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144,   543, -2144, -1313, -1058,   611,
     300,   592, -2144, -2144,  -775,  -819, -2144, -2144,  -566, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -1043,  -710, -2144, -2143,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
    -723, -2144, -2144, -2144, -2144, -2144,  -141, -2144, -2144, -1050,
   -2144, -2144, -2144, -2144, -2144,  -518, -2144, -2144, -2144, -2144,
   -2144,  -721, -2144, -2144, -2144, -2144, -2144, -1041, -2144, -2144,
    -629, -2144, -2144,  -689, -2144, -2144,  -237, -2144, -2144,  -592,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -1815, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -1803, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,  -171,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144, -2144,
   -2144, -2144, -2144, -2144, -2144, -2144, -2144
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     501,   733,   286,  1381,   252,   666,   615,  1331,   277,   504,
     271,   381,  1277,   386,   506,  1149,   274,   417,  1899,   395,
    1901,   268,  1169,  1469,  1961,  1470,  1471,   509,   758,  1979,
    1172,  1981,  1971,  1420,  1973,  1159,  1975,   583,  1977,  1174,
    2192,  2193,  1059,  1188,  1469,  1983,  1470,  1471,   650,  1464,
     799,  1216,  1469,   525,  1470,  1471,    49,  2261,  2262,  1221,
      50,  1233,  1182,  1183,  1087,   758,    51,   705,  1223,  1367,
    1368,  1406,  1407,  1231,   254,  1028,   299,   928,    49,   665,
      52,  1395,    50,  1491,  2406,  2407,  2302,  2306,    51,   126,
    1043,   127,  1251,   128,   300,   129,    53,   283,  2053,   977,
    1450,  1451,    52,   538,   486,   373,   741,   380,   301,   385,
    2380,  1016,  1286,   541,   483,   365,   302,  1276,    53,   130,
    1192,   547,  1445,  1264,   762,   763,   303,   216,   304,   217,
    1476,  2080,  1297,   535,  1507,  2311,   480,   477,  1514,    12,
     305,   704,  2315,   131,   306,  1487,   307,   218,   308,  1156,
     309,   744,  2354,   265,   756,   872,  2439,   219,   808,   620,
     745,   280,     6,  1309,   364,   525,  2092,  1287,  2087,  1504,
     548,  1027,  2089,    14,  2090,   220,  2091,   481,  2370,    17,
     740,   221,   478,  1228,   542,     7,   539,    30,   643,   428,
     284,   756,   474,   645,  1325,   487,   515,  2396,   647,   153,
     154,  1057,   366,  1193,  1194,    41,  1195,   611,   612,   484,
     266,   764,  1234,  1522,   536,   809,  2303,  2307,   520,   601,
     602,   601,   602,  1544,  2402,  2412,   601,   602,   601,   602,
     531,   560,  2151,   565,  1587,   570,  1492,  1533,   281,  2161,
    2162,  2163,  2164,  2165,  2166,   721,   722,  2169,  2170,  2171,
    2172,  2173,  2174,  1235,  2176,   801,  1044,   601,   602,   978,
    2186,  1170,   476,  2381,  1446,  2312,   550,  1017,  1389,  1029,
    1373,  1446,  2316,  2187,  2188,  2189,   150,  2209,  1265,  1298,
    2263,  2201,  2203,  1575,  2264,  1088,  2440,  1088,  1060,   489,
     490,   418,  1088,   526,  1088,  1349,  1433,     1,     2,  1502,
    1412,   510,  2408,  2409,  1436,  1181,   601,   602,   118,  1496,
      54,   584,   817,  1441,  1278,  1266,  1456,   811,    80,  1100,
     812,  1472,   651,  1088,  1299,  1598,  1508,   559,  1365,   564,
     148,   569,  1481,    55,  1227,    56,  1604,    57,  1518,    58,
     601,   602,   272,  1520,   278,  1506,  2245,  2246,  2247,  2248,
     275,   269,  2252,  2254,  1500,    55,  2257,    56,   310,    57,
     491,    58,  2271,  2273,  2275,   132,  2397,  2398,   200,  1424,
     429,  2278,  1088,   430,   153,   154,   431,  1143,   604,  2389,
     203,   818,   819,   614,   820,  1468,   126,   403,   127,  1524,
     128,  1175,   129,  1083,  2286,   222,   723,   724,   151,   152,
    1554,  1555,   544,  2390,   153,   154,  1088,  1072,   151,   152,
     370,   371,   151,   152,   153,   154,   130,   299,   404,   204,
    1224,  1495,  1496,  1112,  1527,   205,   611,   612,   683,   636,
     206,  2340,  2341,   545,   207,   300,   637,   687,   818,   819,
     131,   820,  2327,  1715,  1716,   984,  2329,   292,   985,   301,
    1103,  1717,   208,   734,    20,    21,   664,   302,   396,   397,
     398,   399,   216,   238,   217,   151,   152,   303,   257,   304,
     258,   153,   154,   709,  1144,   293,  2194,   676,   294,   677,
     720,   305,   218,  2334,   295,   306,   336,   307,  1176,   308,
     296,   309,   219,   368,   678,    25,    26,   377,   601,   602,
     153,   154,   151,   152,   382,   796,   723,   724,   151,   152,
     220,   387,   601,   602,   370,   371,   221,  1225,   703,  1092,
     759,   760,   611,   612,  1102,   394,  1554,  1555,  1193,  1194,
     401,  1195,   402,  1556,  1557,   409,   151,   152,   410,  1990,
     601,   602,  2394,    33,    34,   769,   411,  2395,  1136,   732,
     611,   612,    44,    45,   151,   152,   412,   739,   601,   602,
    1160,  1558,  1173,   788,   121,   122,   165,   166,  1189,   170,
     171,   796,   723,   724,   151,   152,   757,  1122,   601,   602,
     413,   151,   152,  1123,  1124,   601,   602,   153,   154,  1125,
    1126,  1222,   175,   176,   414,   611,   612,   415,  1232,   180,
     181,   185,   186,   190,   191,   195,   196,   834,   416,  1430,
    1431,   211,   212,   757,   240,   241,   151,   152,   259,   260,
    2000,  1792,   287,   288,   437,  1793,   338,   339,   464,  1794,
     343,   344,   800,   856,  1122,  1204,   348,   349,   151,   152,
    1123,  1124,   601,   602,   153,   154,  1125,  1126,   353,   354,
    1775,   499,   611,   612,  1777,   881,   358,   359,  1779,   502,
    1166,  1167,  1781,   516,   892,  1442,  1783,   389,   390,   507,
    1785,   423,   424,   404,  1787,  2096,   439,   440,  1789,   418,
     905,   444,   445,   449,   450,   454,   455,  1122,   897,   916,
     521,   151,   152,  1123,  1124,   601,   602,   153,   154,  1125,
    1126,   459,   460,   871,   935,   611,   612,  1652,  1653,  1212,
    1213,   494,   495,   945,   489,   490,   551,   552,   578,  1190,
     573,   574,   598,   599,  1383,   532,  1654,  1655,  1656,  1657,
    1658,  1659,  1660,  1661,   556,   950,   608,   609,  1792,   660,
     661,   533,  1793,   990,   534,  1795,  1794,  1796,   561,  1797,
    2107,  1798,   566,  1799,  1422,  1800,   571,  1801,   579,  1802,
     580,  1803,  1443,  1804,  2150,  1805,   582,  1806,   589,  1807,
    1466,  1808,  1872,  1809,  1874,  1810,  1876,   581,  1878,   590,
    1880,   593,  1882,   591,  1884,  1038,  1886,   592,  1263,   699,
     700,   510,  1122,   626,  1046,  1374,   151,   152,  1123,  1124,
     601,   602,   153,   154,  1125,  1126,   710,   711,   735,   736,
     611,   612,   777,   778,   782,   783,  1127,  1128,   791,   792,
     835,   836,   857,   858,   594,  1413,   867,   868,  1567,   882,
     883,   906,   907,   930,   931,  1615,  1440,   936,   937,   954,
     955,  1457,   627,   921,   619,  1616,   628,  1617,   629,  1618,
     630,  1619,  2220,  1620,   631,  1621,   632,  1622,   634,  1623,
    1310,  1624,  1795,   633,  1796,  2228,  1797,   635,  1798,   648,
    1799,  1625,  1800,   656,  1801,   584,  1802,   667,  1803,   668,
    1804,   669,  1805,   670,  1806,  2234,  1807,   671,  1808,   674,
    1809,   688,  1810,   960,   961,   966,   967,   971,   972,   996,
     997,  1101,  1002,  1003,   684,  1725,  1202,  1729,  1903,  1733,
    1904,  1737,  1905,  1741,  1906,  1745,  1907,  1749,  1908,  1753,
    1909,  2251,  1910,   685,  1911,  1132,  1912,   686,  1913,   636,
    1914,   691,  1915,   694,  1916,   692,  1917,   693,  1918,  1171,
    1919,   695,  1920,   707,  1921,   706,  1922,   708,  1923,   715,
    1924,   651,  1925,   718,  1926,  1589,  1927,   719,  1928,  1726,
    1929,  1730,   743,  1734,   742,  1738,   750,  1742,  1220,  1746,
    2289,  1750,  1903,  1754,  1904,   761,  1905,   767,  1906,   768,
    1907,   770,  1908,   745,  1909,   774,  1910,  2253,  1911,   790,
    1912,   789,  1913,   802,  1914,   805,  1915,   827,  1916,  1563,
    1917,  1903,  1918,  1904,  1919,  1905,  1920,  1906,  1921,  1907,
    1922,  1908,  1923,  1909,  1924,  1910,  1925,  1911,  1926,  1912,
    1927,  1913,  1928,  1914,  1929,  1915,   831,  1916,   840,  1917,
     828,  1918,   841,  1919,   812,  1920,  2270,  1921,  1903,  1922,
    1904,  1923,  1905,  1924,  1906,  1925,  1907,  1926,  1908,  1927,
    1909,  1928,  1910,  1929,  1911,   845,  1912,   849,  1913,   847,
    1914,   850,  1915,   853,  1916,   862,  1917,   863,  1918,   874,
    1919,   873,  1920,   875,  1921,  2272,  1922,  1903,  1923,  1904,
    1924,  1905,  1925,  1906,  1926,  1907,  1927,  1908,  1928,  1909,
    1929,  1910,   878,  1911,   887,  1912,   888,  1913,   893,  1914,
     894,  1915,   900,  1916,   897,  1917,   901,  1918,   902,  1919,
     911,  1920,   912,  1921,   918,  1922,  2274,  1923,  1903,  1924,
    1904,  1925,  1905,  1926,  1906,  1927,  1907,  1928,  1908,  1929,
    1909,   921,  1910,   924,  1911,   917,  1912,   929,  1913,   941,
    1914,   942,  1915,   946,  1916,   950,  1917,  2328,  1918,   947,
    1919,   959,  1920,   976,  1921,   983,  1922,   992,  1923,  1001,
    1924,  1007,  1925,  1010,  1926,  1015,  1927,  1035,  1928,  1034,
    1929,   978,  1903,  1039,  1904,  1382,  1905,   984,  1906,  1058,
    1907,  1067,  1908,  1068,  1909,  1022,  1910,  1052,  1911,  1072,
    1912,  1075,  1913,  1076,  1914,  1017,  1915,  1081,  1916,  1104,
    1917,  1084,  1918,  1110,  1919,  1421,  1920,  1029,  1921,  1105,
    1922,  1113,  1923,  1435,  1924,  1114,  1925,  1060,  1926,  1150,
    1927,  1465,  1928,    81,  1929,    82,    83,    84,  1145,    85,
      86,    87,  1191,    88,    89,    90,  1204,    91,    92,    93,
    1243,    94,    95,  1047,  1048,  1093,  1094,  1117,  1118,  1151,
    1152,  1161,  1162,  1207,  1208,  1252,  1253,  1292,  1293,  1326,
    1327,  1375,  1376,  1390,  1391,  1399,  1400,  1414,  1415,  1425,
    1426,  1458,  1459,  1482,  1483,  1495,  1496,  1528,  1529,  1549,
    1550,  1570,  1571,  1581,  1582,  1649,  1650,  1695,  1696,  1865,
    1866,  1968,  1969,  1995,  1996,  2037,  2038,  2041,  2042,  2045,
    2046,  2049,  2050,  2097,  2098,  2102,  2103,  2110,  2111,  2115,
    2116,  2120,  2121,  2125,  2126,  2130,  2131,  2135,  2136,  2140,
    2141,  2145,  2146,  2180,  2181,  2183,  2184,  2210,  2211,  2215,
    2216,  2335,  2336,  2348,  2349,  2357,  2358,  2362,  2363,  2384,
    2385,  1244,  1245,  1246,  1247,  1768,  1258,  1257,  1274,  1281,
    1280,  1282,  1291,  1284,  1307,  1234,  1311,  1233,  1317,  1321,
    1597,  1318,  1319,  1320,  1333,  1336,  1334,  1347,  1339,  1340,
    1341,  1265,  1264,  1351,  1350,  1352,  1355,  1357,  1297,  1298,
    1363,  1366,  1384,  1398,  1385,  1397,  1444,  1477,  1490,  1493,
    1515,  1526,  2195,  1489,  1525,  1535,  1536,  1538,  1539,  1537,
    1540,  1541,  1543,  1542,  1446,  1548,  1588,  1569,  1507,  1568,
    1579,  1578,  1577,  1580,  1676,  1590,  1594,  1595,  1596,  1601,
    1602,  1600,  1605,  1609,  1610,  1611,  1612,  1614,  1613,  1674,
    1675,  1701,  1704,  1705,  1706,  1707,  1708,  1709,  1769,  1710,
    1711,  1712,  1713,  1850,  1861,  1714,  1723,  1727,  1731,  1735,
    1739,  1743,  1747,  1751,  1755,  1756,  1757,  1758,  1761,  1762,
    1763,  1764,  1765,  1766,  1767,  1773,  1889,  1774,  1791,  1849,
    1963,  1891,  1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,
    1870,  1871,  1985,  1893,  2002,  1986,  1992,  1895,  2010,  2196,
    2003,  2006,  1991,  1897,  2036,  2007,  2011,  2014,  2040,  2044,
    2015,  2048,  2019,  2083,  2023,  2052,  2084,  1760,  2085,  2152,
    2088,  2079,  2022,  2093,  2018,  2082,  2153,  2086,  2154,  2156,
    2158,  2160,  2205,  2030,  2200,  2027,  2190,  2207,  2026,  2206,
    2208,  2241,  2222,  2242,  2243,  2244,  2249,  2255,  2256,  2259,
    2034,  2277,  2250,  2031,  2109,  2269,  2258,  2280,  2276,  2282,
    2279,  2260,  2281,  2283,  2227,  2285,  2284,  2323,  2291,  2325,
    2155,  2324,  2293,  2330,  2296,  2299,  2157,  2331,  2297,  2326,
    2298,  2319,  2310,  2159,  2322,  2373,  2347,  2332,  2371,  2375,
    2376,  2378,  1496,  2379,  2382,  2418,  2415,  2419,  2417,  2421,
    2420,  2422,  2426,  2430,  2427,  2428,  2431,  2433,  2429,  2346,
    2434,  2423,  2435,  2436,  2437,  2443,  2450,  2458,  2446,  2453,
    2432,  2454,  2455,  2456,  2457,  2461,  2462,  2463,   117,    40,
     149,   517,  2438,   239,   522,   595,  2445,  2449,   438,   337,
     689,   657,   696,  1036,   621,   264,   787,  1342,  1085,   842,
    1077,  1344,  1312,  1314,  1358,  1115,  1360,  1545,  2377,  1040,
     771,  1285,  1215,  1099,  1434,   848,  2292,  2401,  1131,  2345,
    1967,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,  2374,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2424,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2444,
       0,     0,     0,     0,     0,  2447,  2448,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2460
};

static const yytype_int16 yycheck[] =
{
     368,   690,   200,  1316,   145,   597,   524,  1252,     4,   377,
       4,   248,     4,   250,   382,  1071,     4,    67,  1821,     8,
    1823,     4,  1080,     4,  1827,     6,     7,    67,   717,  1844,
    1080,  1846,  1835,  1346,  1837,  1078,  1839,    67,  1841,  1080,
      10,    11,    51,  1086,     4,  1848,     6,     7,    67,  1362,
     773,  1109,     4,    78,     6,     7,    56,    10,    11,  1109,
      60,   150,    10,    11,    10,   754,    66,   659,  1109,    10,
      11,    10,    11,  1116,   147,   111,    34,   896,    56,   597,
      80,  1326,    60,     4,    10,    11,   148,   148,    66,    36,
     118,    38,  1148,    40,    52,    42,    96,     4,  1901,   145,
      10,    11,    80,     4,     4,   246,   698,   248,    66,   250,
       4,   145,   286,     4,     6,     4,    74,  1180,    96,    66,
      69,     4,   145,   150,     6,     7,    84,    46,    86,    48,
    1375,  1946,   150,     4,   150,   148,     6,     4,  1425,    14,
      98,   659,   148,    90,   102,  1390,   104,    66,   106,    10,
     108,    73,  2295,     4,   717,   844,   149,    76,     4,    72,
      82,     4,     0,  1226,   237,    78,  1981,   341,  1971,  1414,
      53,   966,  1975,    15,  1977,    94,  1979,    47,  2321,   309,
     698,   100,    49,    10,    75,   120,    87,   311,   556,    25,
      97,   754,   333,   561,  1250,    95,   394,    10,   566,   169,
     170,   996,    91,   152,   153,   313,   155,   177,   178,   101,
      61,    93,   301,  1458,    85,    61,   278,   278,   416,   167,
     168,   167,   168,  1510,  2367,  2368,   167,   168,   167,   168,
     428,   468,  2035,   470,  1547,   472,   157,  1482,    81,  2054,
    2055,  2056,  2057,  2058,  2059,    10,    11,  2062,  2063,  2064,
    2065,  2066,  2067,   342,  2069,   773,   284,   167,   168,   305,
    2075,  1080,   335,   157,   287,   278,   464,   301,  1324,   305,
    1313,   287,   278,  2076,  2077,  2078,    31,  2092,   305,   297,
     233,  2084,  2085,  1528,   237,   233,   279,   233,   297,     6,
       7,   341,   233,   318,   233,  1275,  1354,    12,    13,  1406,
    1343,   341,   228,   229,  1354,  1082,   167,   168,   315,   235,
     310,   341,    83,  1354,   306,   342,  1359,    85,   121,  1042,
      88,   302,   341,   233,   342,  1570,   342,   468,  1308,   470,
     310,   472,  1388,   333,  1111,   335,  1581,   337,   298,   339,
     167,   168,   336,  1450,   340,  1423,  2161,  2162,  2163,  2164,
     338,   334,  2167,  2168,   306,   333,  2171,   335,   316,   337,
      77,   339,  2177,  2178,  2179,   312,   179,   180,    22,  1348,
     206,  2186,   233,   209,   169,   170,   212,  1066,   519,   214,
       5,   152,   153,   524,   155,  1364,    36,    57,    38,  1467,
      40,  1080,    42,  1026,  2209,   314,   161,   162,   163,   164,
     195,   196,     4,   238,   169,   170,   233,   158,   163,   164,
     175,   176,   163,   164,   169,   170,    66,    34,    88,     5,
    1109,   234,   235,  1056,  1480,     5,   177,   178,   626,    92,
       5,   226,   227,    35,     5,    52,    99,   635,   152,   153,
      90,   155,  2257,   197,   198,    68,  2261,   123,    71,    66,
    1042,   205,   317,   690,    10,    11,   597,    74,   447,   448,
     449,   450,    46,   312,    48,   163,   164,    84,     3,    86,
       3,   169,   170,   671,  1066,   127,   446,    16,   131,    18,
     678,    98,    66,  2286,   135,   102,   314,   104,  1080,   106,
     139,   108,    76,    10,    33,    10,    11,    10,   167,   168,
     169,   170,   163,   164,    10,   160,   161,   162,   163,   164,
      94,    10,   167,   168,   175,   176,   100,  1109,   659,  1037,
     718,   719,   177,   178,  1042,     6,   195,   196,   152,   153,
       8,   155,     8,   202,   203,    61,   163,   164,   334,  1852,
     167,   168,  2357,    10,    11,   743,   336,  2362,  1066,   690,
     177,   178,    10,    11,   163,   164,   338,   698,   167,   168,
    1078,   230,  1080,   761,    10,    11,    10,    11,  1086,    10,
      11,   160,   161,   162,   163,   164,   717,   159,   167,   168,
     340,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,  1109,    10,    11,    81,   177,   178,    97,  1116,    10,
      11,    10,    11,    10,    11,    10,    11,   805,     6,   191,
     192,    10,    11,   754,    10,    11,   163,   164,    10,    11,
    1865,   287,    10,    11,   316,   291,    10,    11,    32,   295,
      10,    11,   773,   831,   159,   217,    10,    11,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    10,    11,
    1723,    91,   177,   178,  1727,   853,    10,    11,  1731,     3,
     185,   186,  1735,    57,   862,  1354,  1739,    10,    11,     6,
    1743,    10,    11,    88,  1747,  1988,    10,    11,  1751,   341,
     878,    10,    11,    10,    11,    10,    11,   159,   213,   887,
      67,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    10,    11,   844,   902,   177,   178,   199,   200,   181,
     182,    10,    11,   911,     6,     7,    10,    11,    49,  1087,
      10,    11,    10,    11,  1316,     8,   218,   219,   220,   221,
     222,   223,   224,   225,    10,   207,    10,    11,   287,    10,
      11,     8,   291,   941,     8,   411,   295,   413,    10,   415,
    1995,   417,    10,   419,  1346,   421,    10,   423,    47,   425,
     101,   427,  1354,   429,   430,   431,    77,   433,    41,   435,
    1362,   437,  1775,   439,  1777,   441,  1779,    95,  1781,     8,
    1783,    37,  1785,    43,  1787,   983,  1789,    39,  1156,    10,
      11,   341,   159,     6,   992,  1313,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    10,    11,    10,    11,
     177,   178,    10,    11,    10,    11,   183,   184,    10,    11,
      10,    11,    10,    11,    67,  1343,    10,    11,  1517,    10,
      11,    10,    11,    10,    11,   245,  1354,    10,    11,    10,
      11,  1359,     6,   210,   318,   255,     6,   257,     6,   259,
      85,   261,  2097,   263,    87,   265,    75,   267,    53,   269,
    1228,   271,   411,    35,   413,  2110,   415,     6,   417,     6,
     419,   281,   421,    67,   423,   341,   425,    89,   427,     3,
     429,   342,   431,     3,   433,  2130,   435,    30,   437,    10,
     439,    99,   441,    10,    11,    10,    11,    10,    11,    10,
      11,  1042,    10,    11,     8,  1680,  1104,  1682,   357,  1684,
     359,  1686,   361,  1688,   363,  1690,   365,  1692,   367,  1694,
     369,   370,   371,     8,   373,  1066,   375,     8,   377,    92,
     379,   107,   381,   103,   383,   109,   385,   105,   387,  1080,
     389,    67,   391,     8,   393,   342,   395,     8,   397,    84,
     399,   341,   401,     3,   403,  1547,   405,     3,   407,  1680,
     409,  1682,     6,  1684,   342,  1686,    60,  1688,  1109,  1690,
    2215,  1692,   357,  1694,   359,     6,   361,     3,   363,   342,
     365,    73,   367,    82,   369,   307,   371,   372,   373,     8,
     375,    93,   377,   303,   379,    24,   381,     8,   383,  1517,
     385,   357,   387,   359,   389,   361,   391,   363,   393,   365,
     395,   367,   397,   369,   399,   371,   401,   373,   403,   375,
     405,   377,   407,   379,   409,   381,    21,   383,    61,   385,
     299,   387,    85,   389,    88,   391,   392,   393,   357,   395,
     359,   397,   361,   399,   363,   401,   365,   403,   367,   405,
     369,   407,   371,   409,   373,     5,   375,     6,   377,    83,
     379,   283,   381,    20,   383,     6,   385,   144,   387,     8,
     389,   154,   391,    70,   393,   394,   395,   357,   397,   359,
     399,   361,   401,   363,   403,   365,   405,   367,   407,   369,
     409,   371,    28,   373,     6,   375,   144,   377,   308,   379,
     110,   381,    89,   383,   213,   385,    79,   387,    23,   389,
       6,   391,    50,   393,    44,   395,   396,   397,   357,   399,
     359,   401,   361,   403,   363,   405,   365,   407,   367,   409,
     369,   210,   371,    44,   373,   304,   375,     8,   377,     6,
     379,   285,   381,   300,   383,   207,   385,   386,   387,    44,
     389,     8,   391,     6,   393,     6,   395,    29,   397,     8,
     399,   341,   401,   325,   403,     6,   405,   145,   407,     8,
     409,   305,   357,    71,   359,  1316,   361,    68,   363,     6,
     365,    45,   367,   321,   369,   341,   371,   341,   373,   158,
     375,     8,   377,   145,   379,   301,   381,    45,   383,     6,
     385,   111,   387,    45,   389,  1346,   391,   305,   393,   144,
     395,     8,   397,  1354,   399,    51,   401,   297,   403,     8,
     405,  1362,   407,   122,   409,   124,   125,   126,   323,   128,
     129,   130,     8,   132,   133,   134,   217,   136,   137,   138,
       8,   140,   141,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,   234,   235,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,   173,   174,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,   246,   247,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,     3,     3,     3,   319,  1713,   156,     6,     3,     6,
     306,     5,     8,    69,     3,   301,   342,   150,     6,   327,
    1558,     8,     8,     8,     8,   148,   236,     8,   326,   302,
     342,   305,   150,     8,   306,   154,     6,   342,   150,   297,
       8,   298,     8,     8,   329,   322,     8,   331,     6,    10,
       3,   151,  2081,   324,   302,   320,     8,     6,     8,   157,
       8,   306,   342,   151,   287,     8,  1547,   151,   150,   298,
       6,   149,   328,     6,  1612,   244,     3,     8,     8,     8,
       8,   330,   288,     8,     6,     6,     6,   151,   332,     8,
       8,   201,   243,     3,     8,     8,     8,     8,   273,     8,
       8,     8,     8,   249,   275,    10,    10,    10,    10,    10,
      10,    10,    10,    10,     3,    10,     8,    10,     6,     6,
       6,     6,     6,     6,     6,     3,   282,     8,     8,     6,
     444,   233,     8,     8,     8,     8,     8,     8,     8,     8,
       8,     6,     8,   233,     8,   251,   277,   233,   262,  2081,
     277,   260,   256,   233,     8,   277,   277,   268,     8,     8,
     277,     8,   277,     3,   277,   412,    10,  1705,    10,     6,
     424,   440,   266,   436,   270,   442,   438,   420,     6,     6,
       6,   414,   422,   258,     8,   277,   388,   428,   264,   426,
     432,     8,   156,     8,     8,     8,   366,   374,   376,   382,
     272,   400,   368,   277,   274,   390,   380,   408,   398,   404,
     406,   384,   410,     3,   276,   418,   416,   358,   250,   362,
     288,   360,   148,     8,   278,   148,   292,     8,   278,   364,
     278,   148,   278,   296,   278,     6,   252,   402,   378,     8,
     434,     8,   235,     8,    10,     8,    10,     8,   386,     6,
     248,     6,     8,     6,     8,   149,     3,     8,   149,  2288,
       8,   157,     4,     8,     8,     6,   237,    10,     8,     8,
     149,     8,     8,     8,     8,     6,     8,   280,    40,    25,
      60,   406,   149,   134,   420,   512,   149,   149,   312,   224,
     639,   586,   653,   980,   528,   156,   754,  1268,  1031,   814,
    1019,  1271,  1237,  1240,  1301,  1062,  1304,  1511,  2335,   987,
     747,  1197,  1109,  1042,  1354,   822,  2222,  2367,  1066,  2288,
    1831,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,  2331,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2382,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2427,
      -1,    -1,    -1,    -1,    -1,  2433,  2434,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2457
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   452,   453,   454,     0,   120,   461,   462,
    1093,  1094,    14,   455,    15,   459,   460,   309,   463,   464,
      10,    11,  1095,  1096,  1097,    10,    11,   456,   457,   458,
     311,   543,   544,    10,    11,   465,   466,   467,  1098,  1099,
     461,   313,   597,   598,    10,    11,   545,   546,   547,    56,
      60,    66,    80,    96,   310,   333,   335,   337,   339,   468,
     469,   470,   471,   472,   487,   488,   493,   494,   499,   500,
     505,   506,   511,   512,   517,   518,   523,   524,   529,   530,
     121,   122,   124,   125,   126,   128,   129,   130,   132,   133,
     134,   136,   137,   138,   140,   141,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1120,   459,   315,   649,
     650,    10,    11,   599,   600,   601,    36,    38,    40,    42,
      66,    90,   312,   548,   549,   550,   551,   552,   557,   558,
     564,   565,   571,   572,   578,   579,   583,   584,   310,   470,
      31,   163,   164,   169,   170,   473,   474,   475,  1086,  1447,
    1448,  1449,  1474,  1475,  1476,    10,    11,   489,   490,   491,
      10,    11,   495,   496,   497,    10,    11,   501,   502,   503,
      10,    11,   507,   508,   509,    10,    11,   513,   514,   515,
      10,    11,   519,   520,   521,    10,    11,   525,   526,   527,
      22,   531,  1081,     5,     5,     5,     5,     5,   317,   744,
     745,    10,    11,   651,   652,   653,    46,    48,    66,    76,
      94,   100,   314,   602,   603,   604,   605,   606,   611,   612,
     617,   618,   623,   624,   629,   630,   635,   636,   312,   550,
      10,    11,   553,   554,   555,   559,   560,   566,   567,   573,
     574,   580,  1447,   585,  1081,  1090,  1091,     3,     3,    10,
      11,   476,   477,   478,   475,     4,    61,   492,     4,   334,
     498,     4,   336,   504,     4,   338,   510,     4,   340,   516,
       4,    81,   522,     4,    97,   528,  1090,    10,    11,   532,
     533,   534,   123,   127,   131,   135,   139,   746,   747,    34,
      52,    66,    74,    84,    86,    98,   102,   104,   106,   108,
     316,   654,   655,   656,   657,   658,   663,   664,   669,   670,
     675,   676,   681,   682,   687,   688,   704,   705,   711,   712,
     718,   719,   725,   726,   730,   731,   314,   604,    10,    11,
     607,   608,   609,    10,    11,   613,   614,   615,    10,    11,
     619,   620,   621,    10,    11,   625,   626,   627,    10,    11,
     631,   632,   633,   637,  1081,     4,    91,   556,    10,   562,
     175,   176,   561,  1447,  1477,  1478,  1479,    10,   569,   568,
    1447,  1477,    10,   576,   575,  1447,  1477,    10,   581,    10,
      11,   586,   587,   588,     6,     8,   447,   448,   449,   450,
    1092,     8,     8,    57,    88,   479,   480,   481,   482,    61,
     334,   336,   338,   340,    81,    97,     6,    67,   341,   535,
     536,   537,   538,    10,    11,   749,   750,   751,    25,   206,
     209,   212,   748,  1084,  1407,  1413,  1418,   316,   656,    10,
      11,   659,   660,   661,    10,    11,   665,   666,   667,    10,
      11,   671,   672,   673,    10,    11,   677,   678,   679,    10,
      11,   683,   684,   685,    32,   689,  1087,   706,   707,   713,
     714,   720,   721,   727,  1447,   732,  1081,     4,    49,   610,
       6,    47,   616,     6,   101,   622,     4,    95,   628,     6,
       7,    77,   634,  1088,    10,    11,   638,   639,   640,    91,
     563,  1088,     3,   570,  1088,   577,  1088,     6,   582,    67,
     341,   589,   590,   591,   592,  1090,    57,   481,   483,   484,
    1090,    67,   537,   539,   540,    78,   318,   752,   753,   754,
     755,  1090,     8,     8,     8,     4,    85,   662,     4,    87,
     668,     4,    75,   674,     4,    35,   680,     4,    53,   686,
    1090,    10,    11,   690,   691,   692,    10,   709,   708,  1447,
    1477,    10,   716,   715,  1447,  1477,    10,   723,   722,  1447,
    1477,    10,   728,    10,    11,   733,   734,   735,    49,    47,
     101,    95,    77,    67,   341,   641,   642,   643,   644,    41,
       8,    43,    39,    37,    67,   591,   593,   594,    10,    11,
     486,   167,   168,   485,  1447,  1456,  1457,  1458,    10,    11,
     542,   177,   178,   541,  1447,  1456,  1480,  1481,  1482,   318,
      72,   754,  1054,  1055,   756,   757,     6,     6,     6,     6,
      85,    87,    75,    35,    53,     6,    92,    99,   693,   694,
     695,   696,   710,  1088,   717,  1088,   724,  1088,     6,   729,
      67,   341,   736,   737,   738,   739,    67,   643,   645,   646,
      10,    11,   596,   595,  1447,  1456,  1480,    89,     3,   342,
       3,    30,  1056,  1085,    10,   762,    16,    18,    33,   758,
     759,   760,   761,  1090,     8,     8,     8,  1090,    99,   695,
     697,   107,   109,   105,   103,    67,   738,   740,   741,    10,
      11,   648,   647,  1447,  1456,  1480,   342,     8,     8,  1090,
      10,    11,  1057,  1058,  1059,    84,   763,   764,     3,     3,
    1090,    10,    11,   161,   162,   698,   699,   700,   701,  1441,
    1442,  1443,  1447,  1474,  1477,    10,    11,   743,   742,  1447,
    1456,  1480,   342,     6,    73,    82,  1060,  1061,  1062,  1063,
      60,   779,   780,   765,   766,   767,  1086,  1447,  1474,  1090,
    1090,     6,     6,     7,    93,   702,   703,     3,   342,  1090,
      73,  1062,  1064,  1065,   307,   785,   786,    10,    11,   781,
     782,   783,    10,    11,   768,   769,   770,   767,  1090,    93,
       8,    10,    11,  1067,  1068,  1069,   160,  1066,  1410,  1441,
    1447,  1456,   303,   863,   864,    24,   787,  1083,     4,    61,
     784,    85,    88,   771,   772,   773,   774,    83,   152,   153,
     155,  1070,  1071,  1072,  1073,  1074,  1075,     8,   299,   925,
     926,    21,   865,  1080,  1090,    10,    11,   788,   789,   790,
      61,    85,   773,   775,   776,     5,  1076,    83,  1072,     6,
     283,   987,   988,    20,   927,  1077,  1090,    10,    11,   866,
     867,   868,     6,   144,   791,   792,   793,    10,    11,   778,
     777,  1447,  1474,   154,     8,    70,  1031,  1032,    28,   989,
    1078,  1090,    10,    11,   928,   929,   930,     6,   144,   869,
     870,   871,  1090,   308,   110,   805,   806,   213,   794,  1416,
      89,    79,    23,  1033,  1082,  1090,    10,    11,   990,   991,
     992,     6,    50,   931,   932,   933,  1090,   304,    44,   883,
     884,   210,   872,  1412,    44,   821,   822,   807,  1416,     8,
      10,    11,   795,   796,   797,  1090,    10,    11,  1034,  1035,
    1036,     6,   285,   993,   994,  1090,   300,    44,   945,   946,
     207,   934,  1406,   896,    10,    11,   885,   886,   887,     8,
      10,    11,   873,   874,   875,   834,    10,    11,   823,   824,
     825,    10,    11,   808,   809,   810,     6,   145,   305,   798,
     799,   800,   801,     6,    68,    71,  1037,  1038,  1039,  1040,
    1090,  1029,    29,   995,  1079,   958,    10,    11,   947,   948,
     949,     8,    10,    11,   935,   936,   937,   341,   897,   898,
     325,   888,   889,  1149,  1150,     6,   145,   301,   876,   877,
     878,   879,   341,   835,   836,   826,   827,  1149,   111,   305,
     811,   812,   813,   814,     8,   145,   800,   802,  1090,    71,
    1039,  1041,  1042,   118,   284,  1030,  1090,    10,    11,   996,
     997,   998,   341,   959,   960,   950,   951,  1149,     6,    51,
     297,   938,   939,   940,   941,   899,   900,    45,   321,   890,
    1155,  1156,   158,  1191,  1408,     8,   145,   878,   880,   837,
     838,    45,   828,  1155,   111,   813,   815,    10,   233,   803,
     804,  1427,  1456,    10,    11,  1044,  1045,  1046,  1043,  1410,
    1441,  1447,  1456,  1480,     6,   144,  1000,  1001,   961,   962,
      45,   952,  1155,     8,    51,   940,   942,    10,    11,   902,
     903,   904,   159,   165,   166,   171,   172,   183,   184,   901,
    1409,  1412,  1447,  1450,  1451,  1452,  1456,  1459,  1460,  1461,
    1468,  1469,  1470,  1474,  1480,   323,   891,  1161,  1162,  1191,
       8,    10,    11,  1151,  1152,  1153,    10,   881,   882,  1427,
    1456,    10,    11,   840,   841,   842,   185,   186,   839,  1409,
    1416,  1447,  1450,  1456,  1468,  1474,  1480,  1486,  1487,  1488,
     829,  1161,    10,    11,   816,   817,   818,   819,  1427,  1456,
    1088,     8,    69,   152,   153,   155,  1047,  1048,  1049,  1050,
    1051,  1052,  1090,  1008,   217,  1002,  1411,    10,    11,   964,
     965,   966,   181,   182,   963,  1406,  1409,  1444,  1445,  1446,
    1447,  1450,  1456,  1468,  1474,  1480,   953,  1161,    10,   943,
     944,  1427,  1456,   150,   301,   342,   905,   906,   907,   908,
     915,   916,   917,     8,     3,     3,     3,   319,   892,  1167,
    1168,  1191,    10,    11,  1157,  1158,  1159,     6,   156,  1121,
    1122,  1129,  1154,  1088,   150,   305,   342,   843,   844,   845,
     846,   853,   854,   855,     3,   830,  1167,     4,   306,   820,
     306,     6,     5,  1053,    69,  1049,   286,   341,   999,  1009,
    1010,     8,    10,    11,  1003,  1004,  1005,   150,   297,   342,
     967,   968,   969,   970,   977,   978,   979,     3,   954,  1167,
    1088,   342,   907,   909,   916,   918,   919,     6,     8,     8,
       8,   327,   893,  1173,  1174,  1191,    10,    11,  1163,  1164,
    1165,  1121,  1160,     8,   236,  1419,   148,  1123,  1124,   326,
     302,   342,   845,   847,   854,   856,   857,     8,   831,  1173,
     306,     8,   154,  1011,  1012,     6,  1007,   342,   969,   971,
     978,   980,   981,     8,   955,  1173,   298,    10,    11,   910,
     911,   912,   913,  1427,  1456,    10,    11,   921,   922,   923,
     920,  1408,  1447,  1480,     8,   329,   894,  1179,  1180,  1191,
      10,    11,  1169,  1170,  1171,  1121,  1166,   322,     8,    10,
      11,  1130,  1131,  1132,  1125,  1126,    10,    11,   848,   849,
     850,   851,  1427,  1456,    10,    11,   859,   860,   861,   858,
    1408,  1447,  1480,   832,  1179,    10,    11,  1014,  1015,  1016,
     191,   192,  1013,  1409,  1411,  1447,  1450,  1453,  1454,  1455,
    1456,  1468,  1474,  1480,     8,   145,   287,  1006,  1192,  1193,
      10,    11,   972,   973,   974,   975,  1427,  1456,    10,    11,
     983,   984,   985,   982,  1408,  1447,  1480,   956,  1179,     4,
       6,     7,   302,   914,  1089,   924,  1121,   331,   895,  1185,
    1186,  1191,    10,    11,  1175,  1176,  1177,  1121,  1172,   324,
       6,     4,   157,    10,  1128,   234,   235,  1127,  1428,  1430,
     306,   852,  1089,   862,  1121,   833,  1185,   150,   342,  1017,
    1018,  1019,  1020,  1021,  1192,     3,  1194,  1195,   298,   976,
    1089,   986,  1121,   957,  1185,   302,   151,  1191,    10,    11,
    1181,  1182,  1183,  1121,  1178,   320,     8,   157,     6,     8,
       8,   306,   151,   342,  1192,  1020,  1022,  1023,     8,    10,
      11,  1197,  1198,  1199,   195,   196,   202,   203,   230,  1196,
    1405,  1414,  1429,  1456,  1471,  1472,  1473,  1474,   298,   151,
      10,    11,  1187,  1188,  1189,  1121,  1184,   328,   149,     6,
       6,    10,    11,  1025,  1026,  1027,  1024,  1408,  1447,  1480,
     244,  1200,  1201,  1202,     3,     8,     8,  1090,  1121,  1190,
     330,     8,     8,  1028,  1121,   288,  1207,  1203,  1204,     8,
       6,     6,     6,   332,   151,   245,   255,   257,   259,   261,
     263,   265,   267,   269,   271,   281,  1208,  1209,  1210,  1234,
    1235,  1247,  1248,  1274,  1275,  1292,  1293,  1310,  1311,  1323,
    1324,  1341,  1342,  1359,  1360,  1372,  1373,  1376,  1377,    10,
      11,  1206,   199,   200,   218,   219,   220,   221,   222,   223,
     224,   225,  1205,  1420,  1421,  1422,  1423,  1424,  1431,  1432,
    1437,  1438,  1439,  1440,     8,     8,  1090,  1211,  1212,  1236,
    1237,  1249,  1250,  1276,  1277,  1294,  1295,  1312,  1313,  1325,
    1326,  1343,  1344,  1361,  1362,   173,   174,  1374,  1465,  1466,
    1467,   201,  1378,  1404,   243,     3,     8,     8,     8,     8,
       8,     8,     8,     8,    10,   197,   198,   205,  1213,  1415,
    1462,  1463,  1464,    10,  1238,  1415,  1462,    10,  1251,  1415,
    1462,    10,  1278,  1415,  1462,    10,  1296,  1415,  1462,    10,
    1314,  1415,  1462,    10,  1327,  1415,  1462,    10,  1345,  1415,
    1462,    10,  1363,  1415,  1462,     3,    10,     8,    10,  1379,
    1090,     6,     6,     6,     6,     6,     6,     6,  1088,   273,
    1214,  1216,  1217,     3,     8,  1216,  1239,  1216,  1252,  1216,
    1279,  1216,  1297,  1216,  1315,  1216,  1328,  1216,  1346,  1216,
    1364,     8,   287,   291,   295,   411,   413,   415,   417,   419,
     421,   423,   425,   427,   429,   431,   433,   435,   437,   439,
     441,  1563,  1564,  1565,  1568,  1569,  1572,  1573,  1576,  1577,
    1580,  1581,  1583,  1584,  1586,  1587,  1589,  1590,  1592,  1593,
    1596,  1597,  1601,  1602,  1604,  1605,  1607,  1608,  1610,  1611,
    1613,  1614,  1616,  1619,  1620,  1622,  1623,  1625,  1626,     6,
     249,  1381,  1382,     8,     8,     8,     8,     8,     8,     8,
       8,   275,  1215,  1222,  1223,    10,    11,  1218,  1219,  1220,
       8,     6,  1222,  1240,  1222,  1253,  1222,  1280,  1222,  1298,
    1222,  1316,  1222,  1329,  1222,  1347,  1222,  1365,  1617,   282,
    1375,   233,  1567,   233,  1571,   233,  1575,   233,  1579,  1563,
    1582,  1563,  1585,   357,   359,   361,   363,   365,   367,   369,
     371,   373,   375,   377,   379,   381,   383,   385,   387,   389,
     391,   393,   395,   397,   399,   401,   403,   405,   407,   409,
    1489,  1490,  1493,  1496,  1498,  1500,  1502,  1504,  1506,  1508,
    1510,  1512,  1514,  1516,  1518,  1520,  1521,  1523,  1525,  1527,
    1529,  1531,  1533,  1534,  1540,  1548,  1551,  1554,  1557,  1560,
    1588,  1563,  1591,   444,  1594,  1600,  1598,  1600,    10,    11,
    1603,  1563,  1606,  1563,  1609,  1563,  1612,  1563,  1615,  1489,
    1621,  1489,  1624,  1563,  1627,     8,   251,  1388,  1389,  1383,
    1408,   256,   277,  1228,  1229,    10,    11,  1224,  1225,  1226,
    1121,  1221,     8,   277,  1241,  1242,   260,   277,  1254,  1255,
     262,   277,  1281,  1282,   268,   277,  1299,  1300,   270,   277,
    1317,  1318,   266,   277,  1330,  1331,   264,   277,  1348,  1349,
     258,   277,  1366,  1367,   272,  1618,     8,    10,    11,  1566,
       8,    10,    11,  1570,     8,    10,    11,  1574,     8,    10,
      11,  1578,   412,  1563,  1507,  1499,  1501,  1505,  1509,  1511,
    1549,  1561,  1519,  1503,  1526,  1513,  1515,  1517,  1541,  1524,
    1555,  1552,  1558,  1491,  1494,  1497,  1528,  1530,  1532,   440,
    1489,  1536,   442,     3,    10,    10,   420,  1563,   424,  1563,
    1563,  1563,  1489,   436,  1395,  1390,  1408,    10,    11,  1384,
    1385,  1386,    10,    11,  1230,  1231,  1232,  1121,  1227,   274,
      10,    11,  1243,  1244,  1245,    10,    11,  1256,  1257,  1258,
      10,    11,  1283,  1284,  1285,    10,    11,  1301,  1302,  1303,
      10,    11,  1319,  1320,  1321,    10,    11,  1332,  1333,  1334,
      10,    11,  1350,  1351,  1352,    10,    11,  1368,  1369,  1370,
     430,  1563,     6,   438,     6,   288,     6,   292,     6,   296,
     414,  1489,  1489,  1489,  1489,  1489,  1489,  1550,  1562,  1489,
    1489,  1489,  1489,  1489,  1489,  1544,  1489,  1556,  1553,  1559,
      10,    11,  1492,    10,    11,  1495,  1489,  1563,  1563,  1563,
     388,  1522,    10,    11,   446,  1474,  1480,  1535,  1537,  1538,
       8,  1563,  1595,  1563,  1599,   422,   426,   428,   432,  1489,
     246,   247,  1380,  1396,  1397,    10,    11,  1391,  1392,  1393,
    1121,  1387,   156,  1133,  1134,  1139,  1233,   276,  1121,  1246,
    1259,  1260,  1286,  1304,  1121,  1322,  1335,  1353,  1143,  1144,
    1371,     8,     8,     8,     8,  1489,  1489,  1489,  1489,   366,
     368,   370,  1489,   372,  1489,   374,   376,  1489,   380,   382,
     384,    10,    11,   233,   237,  1542,  1545,  1546,  1547,   390,
     392,  1489,   394,  1489,   396,  1489,   398,   400,  1489,   406,
     408,   410,   404,     3,   416,   418,  1489,  1398,  1399,  1121,
    1394,   250,  1419,   148,  1135,  1136,   278,   278,   278,   148,
    1261,  1262,   148,   278,  1287,  1288,   148,   278,  1305,  1306,
     278,   148,   278,  1336,  1337,   148,   278,  1354,  1355,   148,
    1145,  1146,   278,   358,   360,   362,   364,  1489,   386,  1489,
       8,     8,   402,  1539,  1563,    10,    11,  1401,  1402,  1403,
     226,   227,  1400,  1425,  1426,  1471,  1474,   252,    10,    11,
    1140,  1141,  1142,  1137,  1430,  1263,  1264,    10,    11,  1289,
    1290,  1291,    10,    11,  1307,  1308,  1309,  1338,  1356,  1147,
    1430,   378,  1543,     6,  1088,     8,   434,  1200,     8,     8,
       4,   157,    10,  1138,    10,    11,  1266,  1267,  1268,   214,
     238,  1265,  1417,  1434,  1489,  1489,    10,   179,   180,  1339,
    1340,  1428,  1430,  1483,  1484,  1485,    10,    11,   228,   229,
    1357,  1358,  1430,  1435,  1436,    10,  1148,   386,     8,     8,
     248,     6,     6,   157,  1088,  1269,     8,     8,   149,   149,
       6,     3,   149,     8,     8,     4,     8,     8,   149,   149,
     279,  1270,  1271,     6,  1088,   149,     8,  1088,  1088,   149,
     237,  1272,  1433,     8,     8,     8,     8,     8,    10,  1273,
    1088,     6,     8,   280
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
            parserData->parser_errors += ("\n\nOSrL input is either invalid or not well-formed.\n"); 
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
        parserData->numberAttributePresent = false;
        parserData->numberOf = 0;
        osglData->typePresent = false;
        osglData->type = "";
        osglData->descriptionPresent = false;
        osglData->description = "";
    }
    break;

  case 40:

    {
        if (!osglData->typePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "type attribute must be present for generalStatus element");
        parserData->kounter = 0;
    }
    break;

  case 43:

    { 
        if (osresult->setGeneralStatusType(osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "general status type does not match any legal value");
    }
    break;

  case 44:

    {   
        osresult->setGeneralStatusDescription(osglData->description);
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
    osglData->namePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->description = "";
}
    break;

  case 56:

    {
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<substatus> must have name attribute");
}
    break;

  case 59:

    {    
        if (osresult->setGeneralSubstatusName(parserData->kounter, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "Error while setting <general> substatus name");
    }
    break;

  case 60:

    {    
        if (osresult->setGeneralSubstatusDescription(parserData->kounter, osglData->description) == false)
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
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->value = "";
    osglData->description = "";
}
    break;

  case 132:

    {
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 135:

    {
        if (osglData->name.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherGeneralResultName(parserData->kounter, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setGeneralOtherResultName failed");
    }
    break;

  case 136:

    {    
        if (osresult->setOtherGeneralResultValue(parserData->kounter, osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setGeneralOtherResultValue failed");
    }
    break;

  case 137:

    {    
        if (osresult->setOtherGeneralResultDescription(parserData->kounter, osglData->description) == false)
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
        osglData->unitPresent = false;    
        osglData->unit = "byte";    
        osglData->descriptionPresent = false;
        osglData->description = "";
    }
    break;

  case 170:

    {
        if (osresult->setAvailableDiskSpaceUnit( osglData->unit) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 171:

    {
        osresult->setAvailableDiskSpaceDescription( osglData->description); 
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
        osglData->unitPresent = false;    
        osglData->unit = "byte";    
        osglData->descriptionPresent = false;
        osglData->description = "";
    }
    break;

  case 179:

    {
        if (osresult->setAvailableMemoryUnit( osglData->unit) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableDiskSpace unit not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 180:

    {
        osresult->setAvailableMemoryDescription( osglData->description); 
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
        osglData->unitPresent = false;    
        osglData->unit = "hertz";    
        osglData->descriptionPresent = false;    
        osglData->description = "";
    }
    break;

  case 188:

    {
        if (osresult->setAvailableCPUSpeedUnit( osglData->unit) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "available CPU Speed could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 189:

    {
        osresult->setAvailableCPUSpeedDescription( osglData->description); 
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
        osglData->descriptionPresent = false;    
        osglData->description = "";    
    }
    break;

  case 195:

    {
        osresult->setAvailableCPUNumberDescription( osglData->description); 
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
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->value = "";
    osglData->description = "";
}
    break;

  case 211:

    {
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 214:

    {
        if (osglData->name.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherSystemResultName(parserData->kounter, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSystemOtherResultName failed");
    }
    break;

  case 215:

    {    
        if (osresult->setOtherSystemResultValue(parserData->kounter, osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSystemOtherResultValue failed");
    }
    break;

  case 216:

    {    
        if (osresult->setOtherSystemResultDescription(parserData->kounter, osglData->description) == false)
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
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->value = "";
    osglData->description = "";
}
    break;

  case 289:

    {
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 292:

    {
        if (osglData->name.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherServiceResultName(parserData->kounter, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setServiceOtherResultName failed");
    }
    break;

  case 293:

    {    
        if (osresult->setOtherServiceResultValue(parserData->kounter, osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setServiceOtherResultValue failed");
    }
    break;

  case 294:

    {    
        if (osresult->setOtherServiceResultDescription(parserData->kounter, osglData->description) == false)
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
    osglData->unitPresent = false;
    osglData->typePresent = false;
    osglData->categoryPresent = false;
    osglData->descriptionPresent = false;
    osglData->unit = "second";
    osglData->type = "elapsedTime";
    osglData->category = "total";
    osglData->description = "";
}
    break;

  case 383:

    {    
    if (osresult->setTimingInformation(parserData->ivar, osglData->type, osglData->category,
        osglData->unit, osglData->description, parserData->timeValue) == false)       
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
        osglData->unitPresent = false;    
        osglData->unit = "byte";
        osglData->descriptionPresent = false;
        osglData->description = "";
    }
    break;

  case 391:

    {
        if (osresult->setUsedDiskSpaceUnit( osglData->unit) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableDiskSpace unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 392:

    {
        osresult->setUsedDiskSpaceDescription( osglData->description); 
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
        osglData->unitPresent = false;    
        osglData->unit = "byte";
        osglData->descriptionPresent = false;    
        osglData->description = "";
    }
    break;

  case 400:

    {
        if (osresult->setUsedMemoryUnit( osglData->unit) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "usedMemory unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 401:

    {
        osresult->setUsedMemoryDescription( osglData->description); 
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
        osglData->unitPresent = false;    
        osglData->unit = "hertz";    
        osglData->descriptionPresent = false;    
        osglData->description = "";    
    }
    break;

  case 409:

    {
        if (osresult->setUsedCPUSpeedUnit( osglData->unit) == false) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "availableCPUSpeed unit could not be set");
        parserData->errorText = NULL;
    }
    break;

  case 410:

    {
        osresult->setUsedCPUSpeedDescription( osglData->description); 
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
        osglData->descriptionPresent = false;    
        osglData->description = "";    
    }
    break;

  case 416:

    {
        osresult->setUsedCPUNumberDescription( osglData->description); 
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
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->value = "";
    osglData->description = "";
}
    break;

  case 432:

    {
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 435:

    {
        if (osglData->name.length() == 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "otherResult name cannot be empty");
        if (osresult->setOtherJobResultName(parserData->kounter, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setJobOtherResultName failed");
    }
    break;

  case 436:

    {    
        if (osresult->setOtherJobResultValue(parserData->kounter, osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setJobOtherResultValue failed");
    }
    break;

  case 437:

    {    
        if (osresult->setOtherJobResultDescription(parserData->kounter, osglData->description) == false)
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
        if (osresult->setVariableNumber(osglData->numberOfVariables) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setVariableNumber failed");
    }
    break;

  case 448:

    {
        if (osresult->setConstraintNumber(osglData->numberOfConstraints) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setConstraintNumber failed");
    }
    break;

  case 449:

    {    
        if (osresult->setObjectiveNumber(osglData->numberOfObjectives) == false)
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
        osglData->typePresent = false;
        osglData->type = "";
        osglData->description = "";
        osglData->descriptionPresent = false;
        parserData->numberAttributePresent = false;
        parserData->numberOf = 0;
    }
    break;

  case 472:

    {
        if (!osglData->typePresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "type attribute must be present for solution status element");
    }
    break;

  case 475:

    {   
        if (osresult->setSolutionStatusType(parserData->solutionIdx, osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionStatusType failed");
    }
    break;

  case 476:

    {
       if (osresult->setSolutionStatusDescription(parserData->solutionIdx, osglData->description) == false)
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
    osglData->typePresent = false;
    osglData->type = "";
    osglData->descriptionPresent = false;
    osglData->description = "";
}
    break;

  case 488:

    {
    if (!osglData->typePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<substatus> must have type attribute");
}
    break;

  case 491:

    {    
        if (osresult->setSolutionSubstatusType(parserData->solutionIdx, parserData->kounter, 
                                               osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionSubstatusType failed");
    }
    break;

  case 492:

    {    
        if (osresult->setSolutionSubstatusDescription(parserData->solutionIdx, parserData->kounter,
                                                      osglData->description) == false)
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

  case 516:

    {
    osglData->numberOfVarPresent = false;
}
    break;

  case 517:

    {
    if (osresult->setNumberOfVarValues(parserData->solutionIdx, osglData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfVarValues failed");
    parserData->kounter = 0;
}
    break;

  case 518:

    {
        if (osglData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <var> element");
    }
    break;

  case 519:

    {
        if (parserData->kounter != osglData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <var> elements than specified");
    }
    break;

  case 526:

    {
    if (!osglData->idxPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    if (osresult->setVarValue(parserData->solutionIdx, parserData->kounter, 
                              osglData->idx, osglData->name, parserData->tempVal) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setVarValue failed");
    parserData->kounter++;
}
    break;

  case 527:

    {    
    if (parserData->kounter >= osglData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <var> elements than specified");
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = "";    
}
    break;

  case 535:

    {
    osglData->numberOfVarPresent = false;
}
    break;

  case 536:

    {
    if (osresult->setNumberOfVarValuesString(parserData->solutionIdx, osglData->numberOfVar) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfVarValuesString failed");
    parserData->kounter = 0;
}
    break;

  case 537:

    {
        if (osglData->numberOfVar > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <var> element");
    }
    break;

  case 538:

    {
        if (parserData->kounter != osglData->numberOfVar)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <var> elements than specified");
    }
    break;

  case 545:

    {
    if (!osglData->idxPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    if (osresult->setVarValueString(parserData->solutionIdx, parserData->kounter, 
                                    osglData->idx, osglData->name, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setVarValueString failed");
    parserData->kounter++;
}
    break;

  case 546:

    {    
    if (parserData->kounter >= osglData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <var> elements than specified");
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = "";    
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
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 568:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 570:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 572:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 574:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 576:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 578:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 581:

    {      
        parserData->iOther++;
    }
    break;

  case 582:

    {
    if (parserData->iOther >= parserData->numberOfOtherVariableResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherVariableResults> than specified");
    osglData->namePresent = false;    
    osglData->typePresent = false;
    osglData->valuePresent = false; 
    osglData->solverPresent = false;    
    osglData->categoryPresent = false;    
    osglData->descriptionPresent = false;
    osglData->numberOfVarPresent = false;    
    osglData->varTypePresent = false;
    osglData->name = "";
    osglData->type = "";
    osglData->value = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->description = "";    
    osglData->varType = "";
    osglData->numberOfEnumerationsPresent = false;    
    osglData->enumTypePresent = false;
    osglData->enumType = "";
}
    break;

  case 583:

    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element requires name attribute"); 
    }
    break;

  case 586:

    {
        if (osresult->setOtherVariableResultNumberOfVar(parserData->solutionIdx, 
                                                        parserData->iOther, 
                                                        osglData->numberOfVar) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData,
                "setOtherVariableResultNumberOfVar failed");
        parserData->kounter = 0;
    }
    break;

  case 587:

    {
        if (osresult->setOtherVariableResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }
    break;

  case 588:

    {    
         if (osresult->setOtherVariableResultValue(parserData->solutionIdx, parserData->iOther, 
                                                   osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultValue failed");
    }
    break;

  case 589:

    {    
         if (osresult->setOtherVariableResultSolver(parserData->solutionIdx, parserData->iOther, 
                                                    osglData->solver) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultSolver failed");
    }
    break;

  case 590:

    {    
         if (osresult->setOtherVariableResultName(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultName failed");
    }
    break;

  case 591:

    {    
         if (osresult->setOtherVariableResultType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultType failed");
    }
    break;

  case 592:

    {    
         if (osresult->setOtherVariableResultVarType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->varType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVarType failed");
    }
    break;

  case 593:

    {    
         if (osresult->setOtherVariableResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->enumType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultEnumType failed");
    }
    break;

  case 594:

    {    
         if (osresult->setOtherVariableResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                         osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultDescription failed");
    }
    break;

  case 604:

    {     
    if (!osglData->idxPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    parserData->kounter++;
}
    break;

  case 605:

    {    
    if (parserData->kounter >= osglData->numberOfVar)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <var> elements than specified");
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = ""    ;
}
    break;

  case 608:

    {    
         if (osresult->setOtherVariableResultVarIdx(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, osglData->idx) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVarIdx failed");
    }
    break;

  case 609:

    {    
         if (osresult->setOtherVariableResultVarName(parserData->solutionIdx, parserData->iOther, 
                                                     parserData->kounter, osglData->name) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVarName failed");
    }
    break;

  case 615:

    {    
         if (osresult->setOtherVariableResultVar(parserData->solutionIdx, parserData->iOther, 
                                                 parserData->kounter,     parserData->tempStr) 
                                                     == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherVariableResultVar failed");
    }
    break;

  case 618:

    {     
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther,
            ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, osglData->value, 
            osglData->description, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other variable option failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->kounter++;
}
    break;

  case 619:

    {
    osglData->numberOfElPresent = false;
    osglData->numberOfEl = 0;
    osglData->valuePresent = false;
    osglData->value = "";
    osglData->descriptionPresent = false;
    osglData->description = "";
}
    break;

  case 620:

    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    }
    break;

  case 623:

    {
        osglData->osglCounter = 0;
        osglData->osglIntArray = new int[osglData->numberOfEl];
    }
    break;

  case 633:

    {
    parserData->numberOfOtherObjectiveResults = 0; 
    parserData->iOther = 0;
    osresult->optimization->solution[parserData->solutionIdx]->objectives = new ObjectiveSolution();
}
    break;

  case 635:

    {
    parserData->numberOfOtherObjectiveResults = parserData->tempInt;
    if (osresult->setNumberOfOtherObjectiveResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherObjectiveResults failed");
    parserData->iOther = 0;
}
    break;

  case 643:

    {
    osglData->numberOfObjPresent = false;
}
    break;

  case 644:

    {
    if (osresult->setNumberOfObjValues(parserData->solutionIdx, osglData->numberOfObj) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfObjValues failed");
    parserData->kounter = 0;
}
    break;

  case 645:

    {
        if (osglData->numberOfObj > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <obj> element");
    }
    break;

  case 646:

    {
        if (parserData->kounter != osglData->numberOfObj)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <obj> elements than specified");
    }
    break;

  case 653:

    {
    if (osresult->setObjValue(parserData->solutionIdx, parserData->kounter, 
                              osglData->idx, osglData->name, parserData->tempVal) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setObjValue failed");
    parserData->kounter++;
}
    break;

  case 654:

    {    
    if (parserData->kounter >= osglData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <obj> elements than specified");
    osglData->idxPresent = false;
    osglData->idx = -1;
    osglData->namePresent = false;
    osglData->name = ""    ;
}
    break;

  case 662:

    {
    osresult->optimization->solution[parserData->solutionIdx]->objectives->basisStatus = new BasisStatus();
}
    break;

  case 669:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 671:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 673:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 675:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 677:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 679:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 681:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 684:

    {      
        parserData->iOther++;  
    }
    break;

  case 685:

    {
    if (parserData->iOther >= parserData->numberOfOtherObjectiveResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherObjectiveResults> than specified");
    osglData->namePresent = false;    
    osglData->typePresent = false;
    osglData->valuePresent = false; 
    osglData->solverPresent = false;    
    osglData->categoryPresent = false;    
    osglData->descriptionPresent = false;
    osglData->numberOfObjPresent = false;    
    osglData->objTypePresent = false;
    osglData->name = "";
    osglData->type = "";
    osglData->value = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->description = "";    
    osglData->objType = "";
    osglData->numberOfEnumerationsPresent = false;    
    osglData->enumTypePresent = false;
    osglData->enumType = "";
}
    break;

  case 686:

    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element requires name attribute"); 
    }
    break;

  case 689:

    {
        if (osresult->setOtherObjectiveResultNumberOfObj(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfObj) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultNumberOfObj failed");
        parserData->kounter = 0;
    }
    break;

  case 690:

    {
        if (osresult->setOtherObjectiveResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }
    break;

  case 691:

    {    
         if (osresult->setOtherObjectiveResultValue(parserData->solutionIdx, parserData->iOther, 
                                                    osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultValue failed");
    }
    break;

  case 692:

    {    
         if (osresult->setOtherObjectiveResultSolver(parserData->solutionIdx, parserData->iOther, 
                                                     osglData->solver) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultSolver failed");
    }
    break;

  case 693:

    {    
          if (osresult->setOtherObjectiveResultName(parserData->solutionIdx, parserData->iOther, 
                                                   osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultName failed");
    }
    break;

  case 694:

    {    
         if (osresult->setOtherObjectiveResultType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultType failed");
    }
    break;

  case 695:

    {    
         if (osresult->setOtherObjectiveResultObjType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->objType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObjType failed");
    }
    break;

  case 696:

    {    
         if (osresult->setOtherObjectiveResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->enumType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultEnumType failed");
    }
    break;

  case 697:

    {    
         if (osresult->setOtherObjectiveResultDescription(parserData->solutionIdx, 
                                                          parserData->iOther, 
                                                          osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultDescription failed");
    }
    break;

  case 707:

    {  
    parserData->kounter++;
}
    break;

  case 708:

    {    
    if (parserData->kounter >= osglData->numberOfObj)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <obj> elements than specified");
    osglData->idxPresent = false;
    osglData->idx = -1;    
    osglData->namePresent = false;
    osglData->name = ""    ;
}
    break;

  case 711:

    {
        if (osresult->setOtherObjectiveResultObjIdx(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, osglData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObjIdx failed");
    }
    break;

  case 712:

    {    
         if (osresult->setOtherObjectiveResultObjName(parserData->solutionIdx, parserData->iOther, 
                                                    parserData->kounter, osglData->name) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObjName failed");
    }
    break;

  case 718:

    {
        if (osresult->setOtherObjectiveResultObj(parserData->solutionIdx, parserData->iOther, parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherObjectiveResultObj failed");
    }
    break;

  case 721:

    {     
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther,
            ENUM_PROBLEM_COMPONENT_objectives, parserData->kounter, osglData->value, 
            osglData->description, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other objective option failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 722:

    {
    osglData->numberOfElPresent = false;
    osglData->numberOfEl = 0;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->value = "";
    osglData->description = "";
}
    break;

  case 723:

    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    }
    break;

  case 726:

    {
        osglData->osglCounter = 0;
        osglData->osglIntArray = new int[osglData->numberOfEl];
    }
    break;

  case 736:

    {
    parserData->numberOfOtherConstraintResults = 0; 
    parserData->iOther = 0;
    osresult->optimization->solution[parserData->solutionIdx]->constraints = new ConstraintSolution();
}
    break;

  case 738:

    {
    parserData->numberOfOtherConstraintResults = parserData->tempInt;
    if (osresult->setNumberOfOtherConstraintResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherConstraintResults failed");
    parserData->iOther = 0;
}
    break;

  case 746:

    {
    osglData->numberOfConPresent = false;
}
    break;

  case 747:

    {
    if (osresult->setNumberOfDualValues(parserData->solutionIdx, osglData->numberOfCon) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfDualValues failed");
    parserData->kounter = 0;
}
    break;

  case 748:

    {
        if (osglData->numberOfCon > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <con> element");
    }
    break;

  case 749:

    {
        if (parserData->kounter != osglData->numberOfCon)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <con> elements than specified");
    }
    break;

  case 756:

    {
    if (osresult->setDualValue(parserData->solutionIdx, parserData->kounter, 
                               osglData->idx, osglData->name, parserData->tempVal ) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setDualValue failed");
    parserData->kounter++;
}
    break;

  case 757:

    {    
    if (parserData->kounter >= osglData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <con> elements than specified");
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = "";    
}
    break;

  case 765:

    {
    osresult->optimization->solution[parserData->solutionIdx]->constraints->basisStatus = new BasisStatus();
}
    break;

  case 772:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 774:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 776:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 778:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 780:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 782:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 784:

    {
    if (osresult->setBasisStatus(parserData->solutionIdx, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
}
    break;

  case 787:

    {      
        parserData->iOther++;  
    }
    break;

  case 788:

    {
    if (parserData->iOther >= parserData->numberOfOtherConstraintResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherConstraintResults> than specified");
    osglData->namePresent = false;    
    osglData->typePresent = false;
    osglData->valuePresent = false; 
    osglData->solverPresent = false;    
    osglData->categoryPresent = false;    
    osglData->descriptionPresent = false;
    osglData->numberOfConPresent = false;    
    osglData->conTypePresent = false;
    osglData->name = "";
    osglData->type = "";
    osglData->value = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->description = "";    
    osglData->conType = "";
    osglData->numberOfEnumerationsPresent = false;    
    osglData->enumTypePresent = false;
    osglData->enumType = "";
}
    break;

  case 789:

    {
        if (!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element requires name attribute"); 
    }
    break;

  case 792:

    {
        if (osresult->setOtherConstraintResultNumberOfCon(parserData->solutionIdx, 
                                                          parserData->iOther, 
                                                          osglData->numberOfCon) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultNumberOfCon failed");
        parserData->kounter = 0;
    }
    break;

  case 793:

    {
        if (osresult->setOtherConstraintResultNumberOfEnumerations(parserData->solutionIdx, 
                                                         parserData->iOther, 
                                                         osglData->numberOfEnumerations) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultNumberOfEnumerations failed");
        parserData->kounter = 0;
    }
    break;

  case 794:

    {    
         if (osresult->setOtherConstraintResultValue(parserData->solutionIdx, parserData->iOther, 
                                                     osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultValue failed");
    }
    break;

  case 795:

    {    
         if (osresult->setOtherConstraintResultSolver(parserData->solutionIdx, parserData->iOther, 
                                                      osglData->solver) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultSolver failed");
    }
    break;

  case 796:

    {    
         if (osresult->setOtherConstraintResultName(parserData->solutionIdx, parserData->iOther, 
                                                    osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultName failed");
    }
    break;

  case 797:

    {    
         if (osresult->setOtherConstraintResultType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->type) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultType failed");
    }
    break;

  case 798:

    {    
         if (osresult->setOtherConstraintResultConType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->conType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultConType failed");
    }
    break;

  case 799:

    {    
         if (osresult->setOtherConstraintResultEnumType(parserData->solutionIdx, parserData->iOther, 
                                                  osglData->enumType) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultEnumType failed");
    }
    break;

  case 800:

    {    
         if (osresult->setOtherConstraintResultDescription(parserData->solutionIdx, parserData->iOther, 
                                                           osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultDescription failed");
    }
    break;

  case 810:

    {     
    if (!osglData->idxPresent)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "idx attribute not set");
    parserData->kounter++;
}
    break;

  case 811:

    {    
    if (parserData->kounter >= osglData->numberOfCon)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <con> elements than specified");
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = ""    ;
}
    break;

  case 814:

    {    
         if (osresult->setOtherConstraintResultConIdx(parserData->solutionIdx, parserData->iOther, parserData->kounter, osglData->idx) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultConIdx failed");
    }
    break;

  case 815:

    {
         if (osresult->setOtherConstraintResultConName(parserData->solutionIdx, parserData->iOther, 
                                                       parserData->kounter, osglData->name) == false)
                osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultConName failed");
    }
    break;

  case 821:

    {    
         if (osresult->setOtherConstraintResultCon(parserData->solutionIdx, parserData->iOther,
                parserData->kounter, parserData->tempStr) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherConstraintResultCon failed");
    }
    break;

  case 824:

    {     
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther,
            ENUM_PROBLEM_COMPONENT_constraints, parserData->kounter, osglData->value, 
            osglData->description, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other constraint option failed");
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 825:

    {
    osglData->numberOfElPresent = false;
    osglData->numberOfEl = 0;
    osglData->valuePresent = false;
    osglData->value = "";
    osglData->descriptionPresent = false;
    osglData->description = "";
}
    break;

  case 826:

    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    }
    break;

  case 829:

    {
        osglData->osglCounter = 0;
        osglData->osglIntArray = new int[osglData->numberOfEl];
    }
    break;

  case 839:

    {
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming
        = new MatrixProgrammingSolution();
}
    break;

  case 841:

    {
    parserData->numberOfOtherMatrixProgrammingResults = parserData->tempInt;
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming
        ->numberOfOtherMatrixProgrammingResults = parserData->tempInt;
}
    break;

  case 847:

    {
        if (osglData->matrixCounter < osglData->numberOfMatrixVar)  
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                "actual number of matrixVar less than number attribute");   
    }
    break;

  case 848:

    {
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
        = new MatrixVariableSolution(); 
}
    break;

  case 849:

    {
    parserData->numberOfOtherMatrixVariableResults = parserData->tempInt;
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
        ->numberOfOtherMatrixVariableResults = parserData->tempInt;
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
        ->other = new OtherMatrixVariableResult*[parserData->tempInt];
    for (int i=0; i < parserData->tempInt; i++)
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[i] = NULL;
    parserData->iOther = 0;
}
    break;

  case 857:

    {
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables->values
        = new MatrixVariableValues();
    osglData->numberOfMatrixVarPresent = false;
}
    break;

  case 858:

    {
    osglData->numberOfMatrixVar = parserData->tempInt;
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming
        ->matrixVariables->values->numberOfMatrixVar = parserData->tempInt;

    osglData->matrixWithMatrixVarIdx = new OSMatrixWithMatrixVarIdx*[parserData->tempInt];
    for (int i=0; i < parserData->tempInt; i++)
        osglData->matrixWithMatrixVarIdx[i] = NULL;
    osglData->matrixCounter = 0;
}
    break;

  case 863:

    {
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming
        ->matrixVariables->values->matrixVar = osglData->matrixWithMatrixVarIdx;
}
    break;

  case 868:

    {      
        parserData->iOther++;
    }
    break;

  case 869:

    {
    if (parserData->iOther >= parserData->numberOfOtherMatrixVariableResults)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherMatrixVariableResults> than specified");
    osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
        ->other[parserData->iOther] = new OtherMatrixVariableResult();

    osglData->namePresent = false;    
    osglData->typePresent = false;
    osglData->valuePresent = false; 
    osglData->solverPresent = false;    
    osglData->categoryPresent = false;    
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->type = "";
    osglData->value = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->description = "";    
    osglData->numberOfMatrixVarPresent = false;
    osglData->numberOfEnumerationsPresent = false;    
    osglData->matrixVarTypePresent = false;
    osglData->enumTypePresent = false;
    osglData->matrixVarType = "";
    osglData->enumType = "";

    osglData->matrixCounter = 0; 
}
    break;

  case 870:

    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, 
                "<other> element requires name attribute"); 
    }
    break;

  case 873:

    {
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->numberOfMatrixVar = osglData->numberOfMatrixVar;
    
        osglData->matrixWithMatrixVarIdx = new OSMatrixWithMatrixVarIdx*[osglData->numberOfMatrixVar];
        for (int i=0; i < parserData->tempInt; i++)
            osglData->matrixWithMatrixVarIdx[i] = NULL;
        osglData->matrixCounter = 0;
    }
    break;

  case 874:

    {
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->numberOfEnumerations = osglData->numberOfEnumerations;
        parserData->kounter = 0;
    }
    break;

  case 875:

    {    
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->value = osglData->value;
    }
    break;

  case 876:

    {    
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->solver = osglData->solver;
    }
    break;

  case 877:

    {    
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->name = osglData->name;
    }
    break;

  case 878:

    {    
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->type = osglData->type;
    }
    break;

  case 879:

    {
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->matrixType = osglData->matrixVarType;
    }
    break;

  case 880:

    {    
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->enumType = osglData->enumType;
    }
    break;

  case 881:

    {
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->description = osglData->description;
    }
    break;

  case 888:

    {
        osresult->optimization->solution[parserData->solutionIdx]->matrixProgramming->matrixVariables
            ->other[parserData->iOther]->matrixVar = osglData->matrixWithMatrixVarIdx;
    }
    break;

  case 893:

    {     
    if (osresult->setOtherOptionOrResultEnumeration(parserData->solutionIdx, parserData->iOther,
            ENUM_PROBLEM_COMPONENT_variables, parserData->kounter, osglData->value, 
            osglData->description, osglData->osglIntArray, osglData->numberOfEl) != true)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "set other variable option failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 894:

    {
    osglData->numberOfElPresent = false;
    osglData->numberOfEl = 0;
    osglData->valuePresent = false;
    osglData->value = "";
    osglData->descriptionPresent = false;
    osglData->description = "";
}
    break;

  case 895:

    {
        if(!osglData->namePresent) 
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "other element enumeration requires name attribute"); 
    }
    break;

  case 898:

    {
        osglData->osglCounter = 0;
        osglData->osglIntArray = new int[osglData->numberOfEl];
    }
    break;

  case 908:

    {
    parserData->numberOf = 0; 
}
    break;

  case 911:

    {
    parserData->numberOf = 0; 
}
    break;

  case 912:

    {    
    if (osresult->setNumberOfOtherSolutionResults(parserData->solutionIdx, parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfOtherSolutionResults failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 913:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <otherSolutionResult> element");
    }
    break;

  case 914:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <otherSolutionResult> elements than specified");
    }
    break;

  case 921:

    {
    parserData->iOther++;
}
    break;

  case 922:

    {
    if (parserData->iOther >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <otherSolutionResult> elements than specified");
    osglData->numberOfItemsPresent = false; 
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->categoryPresent = false;
    osglData->descriptionPresent = false;
    osglData->category = "";
    osglData->description = "";
    osglData->numberOfItems = 0;
}
    break;

  case 923:

    {
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<otherSolutionResult> element must have name attribute");
    //if (!parserData->numberOfItemsPresent)
    //    osrlerror (NULL, NULL, parserData, osglData, osnlData, "<otherSolutionResult> element must have numberOfItems attribute");
}
    break;

  case 926:

    {    
        if (osresult->setOtherSolutionResultName(parserData->solutionIdx, parserData->iOther,
                                                 osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultName failed");
    }
    break;

  case 927:

    {    
        if (osresult->setOtherSolutionResultValue(parserData->solutionIdx, parserData->iOther,
                                                  osglData->value) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultValuee failed");
    }
    break;

  case 928:

    {    
        if (osresult->setOtherSolutionResultCategory(parserData->solutionIdx, parserData->iOther,
                                                     osglData->category) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultCategory failed");
    }
    break;

  case 929:

    {    
        if (osresult->setOtherSolutionResultDescription(parserData->solutionIdx, parserData->iOther,
                                                        osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultDescription failed");
    }
    break;

  case 930:

    {    
        if (osresult->setOtherSolutionResultNumberOfItems(parserData->solutionIdx, 
                                                          parserData->iOther,
                                                          osglData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 931:

    {
        if (osglData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <item> element");
    }
    break;

  case 932:

    {
        if (parserData->kounter != osglData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <item> elements than specified");
    }
    break;

  case 939:

    {
    parserData->kounter++;
}
    break;

  case 940:

    {
        if (parserData->kounter >= osglData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    }
    break;

  case 945:

    {
    if (parserData->kounter >= osglData->numberOfItems)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    if (osresult->setOtherSolutionResultItem(parserData->solutionIdx, parserData->iOther, 
                                             parserData->kounter, parserData->itemContent) 
                                                 == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setOtherSolutionResultItem failed");
}
    break;

  case 948:

    {
    parserData->numberOf = 0; 
}
    break;

  case 949:

    {    
    if (osresult->setNumberOfSolverOutputs(parserData->tempInt) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setNumberOfSolverOutputs failed");
    parserData->numberOf = parserData->tempInt;
    parserData->iOther = 0; 
}
    break;

  case 950:

    {
        if (parserData->numberOf > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <solverOutput> element");
    }
    break;

  case 951:

    {
        if (parserData->iOther != parserData->numberOf)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <solverOutput> elements than specified");
    }
    break;

  case 958:

    {
    parserData->iOther++;
}
    break;

  case 959:

    {
    if (parserData->iOther >= parserData->numberOf)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <solverOutput> elements than specified");
    osglData->numberOfItemsPresent = false; 
    osglData->namePresent = false;
    osglData->categoryPresent = false;
    osglData->descriptionPresent = false;
    osglData->category = "";
    osglData->description = "";
}
    break;

  case 960:

    {
    if (!osglData->namePresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<solverOutput> element must have name attribute");
    if (!osglData->numberOfItemsPresent)
        osrlerror (NULL, NULL, parserData, osglData, osnlData, "<solverOutput> element must have numberOfItems attribute");
}
    break;

  case 963:

    {    
        if (osresult->setSolverOutputName(parserData->iOther, osglData->name) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputName failed");
    }
    break;

  case 964:

    {    
        if (osresult->setSolverOutputCategory(parserData->iOther, osglData->category) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputCategory failed");
    }
    break;

  case 965:

    {    
        if (osresult->setSolverOutputDescription(parserData->iOther, osglData->description) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputDescription failed");
    }
    break;

  case 966:

    {    
        if (osresult->setSolverOutputNumberOfItems(parserData->iOther, osglData->numberOfItems) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputNumberOfItems failed");
        parserData->kounter = 0;
    }
    break;

  case 967:

    {
        if (osglData->numberOfItems > 0)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "expected at least one <item> element");
    }
    break;

  case 968:

    {
        if (parserData->kounter != osglData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "fewer <item> elements than specified");
    }
    break;

  case 975:

    {
    parserData->kounter++;
}
    break;

  case 976:

    {
        if (parserData->kounter >= osglData->numberOfItems)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    }
    break;

  case 981:

    {
    if (parserData->kounter >= osglData->numberOfItems)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "more <item> elements than specified");
    parserData->itemContent = (yyvsp[(1) - (1)].sval); free((yyvsp[(1) - (1)].sval));
    if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
                                      parserData->itemContent) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputItem failed");
}
    break;

  case 982:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other constraint results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 983:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other matrix programming results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 984:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other matrix variable results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 985:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other objective results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 986:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 987:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other solution results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 988:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other variable results cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 989:

    {
    if (parserData->numberAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfSolutions attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of solutions cannot be negative");
    parserData->numberAttributePresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 990:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other solver outputs cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 991:

    {
   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <substatus> elements cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 992:

    {
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 993:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 994:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 995:

    { parserData->tempStr = (yyvsp[(1) - (1)].sval);       free((yyvsp[(1) - (1)].sval)); }
    break;

  case 996:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].ival)); }
    break;

  case 997:

    { parserData->tempStr = os_dtoa_format((yyvsp[(1) - (1)].dval)); }
    break;

  case 1006:

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

  case 1019:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 1024:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1025:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 1030:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1031:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 1036:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1037:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 1042:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1043:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 1048:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1049:

    {
         if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1054:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
    osglData->incr = 0;
}
    break;

  case 1060:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->incr;    
}
    break;

  case 1066:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        intvec = (int*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->base64Size); i++)
        {
            osglData->osglIntArray[i] = *(intvec++);
        }
    }
    //delete[] b64string;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1067:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1072:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}
    break;

  case 1075:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
}
    break;

  case 1081:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    double *dblvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        dblvec = (double*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->base64Size); i++)
        {
            osglData->osglDblArray[i] = *(dblvec++);
        }
    }
    //delete[] b64string;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1082:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1086:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}
    break;

  case 1089:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglStrArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));    
}
    break;

  case 1091:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1098:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1105:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1112:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1119:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1126:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1133:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1139:

    {
    osglData->osglCounter = 0;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1140:

    {
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrixWithMatrixVarIdx[osglData->matrixCounter] = 
        (OSMatrixWithMatrixVarIdx*)((OSMatrixWithMatrixVarIdx*)osglData->mtxConstructorVec[0])
            ->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrixWithMatrixVarIdx[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixWithMatrixVarIdx[osglData->matrixCounter]->matrixVarIdx
        = osglData->matrixVarIdx;
    osglData->matrixCounter++;
}
    break;

  case 1141:

    {
    if (osglData->matrixCounter >= osglData->numberOfMatrixVar)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more matrices than specified");
    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->matrixVarIdxPresent = false;

    osglData->mtxConstructorVec.clear();
    osglData->mtxBlocksVec.clear();
    osglData->mtxBlkVec.clear();
    osglData->nBlocksVec.clear();

    /**
     *  The <matrix> tag combines the functions of the <nl> tag and the top OSnLNode,
     *  so we also initial the storage vectors here
     */
    osglData->tempC = new OSMatrixWithMatrixVarIdx();
    osglData->mtxConstructorVec.push_back((OSMatrixWithMatrixVarIdx*)osglData->tempC);
    osglData->mtxBlkVec.push_back((OSMatrixWithMatrixVarIdx*)osglData->tempC);
}
    break;

  case 1142:

    {
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->matrixVarIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute matrixVarIdx is missing");    
    else
        ((OSMatrixWithMatrixVarIdx*)osglData->tempC)->matrixVarIdx = osglData->matrixVarIdx;
    if (osglData->symmetryPresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->matrixType = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
}
    break;

  case 1154:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1157:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 1158:

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

  case 1159:

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

  case 1174:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++;
}
    break;

  case 1187:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1188:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 1191:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_constant;
    }
    break;

  case 1192:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1196:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1197:

    {
    if (osglData->rowMajor == false)
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1203:

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

  case 1204:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1210:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1211:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1218:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1219:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1222:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_varReference;
    }
    break;

  case 1223:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1227:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1228:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1235:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1236:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 1239:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_linear;
    }
    break;

  case 1240:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1244:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1245:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");        
        ((LinearMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1246:

    {
    osglData->numberOfValues = ((LinearMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;
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

  case 1254:

    {
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}
    break;

  case 1255:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
}
    break;

  case 1256:

    {
    if (!osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->numberOfVarIdx
        = osglData->numberOfVarIdx;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx
        = new LinearMatrixElementTerm*[osglData->numberOfVarIdx];
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->constant
        = osglData->constant;
    osglData->osglCounter = 0;
}
    break;

  case 1268:

    {
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 1270:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}
    break;

  case 1271:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[(2) - (3)].ival);
    osglData->osglCounter++;
}
    break;

  case 1273:

    {
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1274:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 1277:

    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_realValuedExpressions;
    }
    break;

  case 1278:

    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1282:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1283:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");        
        ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1284:

    {
    osglData->numberOfValues = ((RealValuedExpressions*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((RealValuedExpressions*)osglData->tempC)->value = new RealValuedExpressionArray();
    ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    ((RealValuedExpressions*)osglData->tempC)->value->el
        = new RealValuedExpressionTree*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((RealValuedExpressions*)osglData->tempC)->value->el[i] = new RealValuedExpressionTree();
}
    break;

  case 1292:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
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

  case 1296:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 1298:

    {
    osglData->tempC = new ComplexValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1299:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<complexValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 1302:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType =
                ENUM_MATRIX_TYPE_complexValuedExpressions;
    }
    break;

  case 1303:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1307:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1308:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");        
        ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1309:

    {
    osglData->numberOfValues = ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ComplexValuedExpressions*)osglData->tempC)->value = new ComplexValuedExpressionArray();
    ((ComplexValuedExpressions*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    ((ComplexValuedExpressions*)osglData->tempC)->value->el
        = new ComplexValuedExpressionTree*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((ComplexValuedExpressions*)osglData->tempC)->value->el[i] = new ComplexValuedExpressionTree();
}
    break;

  case 1317:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
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

  case 1321:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        ((ComplexValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 1323:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1324:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1327:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_objReference;
    }
    break;

  case 1328:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1332:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1333:

    {
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1340:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1341:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1344:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_conReference;
    }
    break;

  case 1345:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1349:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1350:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");        
        ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1351:

    {
    osglData->numberOfValues = ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ConReferenceMatrixElements*)osglData->tempC)->value = new ConReferenceMatrixValues();
    ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    ((ConReferenceMatrixElements*)osglData->tempC)->value->el
        = new ConReferenceMatrixElement*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((ConReferenceMatrixElements*)osglData->tempC)->value->el[i] = new ConReferenceMatrixElement();
}
    break;

  case 1359:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->valueTypePresent = false;
        osglData->multPresent = false;
        osglData->incrPresent = false;
        osglData->mult = 1;
        osglData->incr = 0;
        osglData->valueType = ""; //ENUM_CONREFERENCE_VALUETYPE_value;
    }
    break;

  case 1365:

    {
    if (osglData->nonzeroCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        if (osglData->valueType == "")
            osglData->valueType = "value";
        if (returnConReferenceValueType(osglData->valueType) <= 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
                "invalid valueType attribute in conReferenceElements");
        else
        {
            for (int i=0; i<osglData->mult; i++)
            {
                ((ConReferenceMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]->conReference
                    = (yyvsp[(2) - (3)].ival) + i*osglData->incr;
                ((ConReferenceMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]->valueType
                    = (ENUM_CONREFERENCE_VALUETYPE)returnConReferenceValueType(osglData->valueType);
            }
        }
        osglData->nonzeroCounter += osglData->mult;
    }
}
    break;

  case 1367:

    {
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1368:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
}
    break;

  case 1371:

    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_complexConstant;
    }
    break;

  case 1372:

    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1376:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1377:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");
        ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1378:

    {
    osglData->numberOfValues = ((ComplexMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ComplexMatrixElements*)osglData->tempC)->value = new ComplexMatrixValues();
    ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    ((ComplexMatrixElements*)osglData->tempC)->value->el
        = new std::complex<double>[osglData->numberOfValues];
}
    break;

  case 1385:

    {
    if (!osglData->realPartPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "real part missing");
    if (!osglData->imagPartPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "imaginary part missing");

    if (osglData->nonzeroCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        for (int i=0; i<osglData->mult; i++)
        {
            ((ComplexMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]
                = (osglData->realPart,osglData->imagPart); 
        }
        osglData->nonzeroCounter += osglData->mult;
    }
}
    break;

  case 1386:

    {
std::cout << "matched <complexElements> <values> <el; next should be \"Re=\"" << std::endl;
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->realPartPresent = false;
        osglData->imagPartPresent = false;
        osglData->multPresent = false;
        osglData->mult = 1;
    }
    break;

  case 1395:

    {
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1396:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
}
    break;

  case 1399:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_string;
    }
    break;

  case 1400:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1404:

    {
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1405:

    {
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1412:

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

  case 1414:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}
    break;

  case 1415:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 1416:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 1417:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}
    break;

  case 1418:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}
    break;

  case 1420:

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

  case 1421:

    {
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of colOffsets does not match numberOfEl");
    ((MatrixBlocks*)osglData->tempC)->colOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->colOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->colOffset->el = osglData->osglIntArray;
    osglData->colOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1422:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 1423:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1429:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1430:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 1431:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1438:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}
    break;

  case 1439:

    {
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1440:

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

  case 1446:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    break;

  case 1447:

    {
        ((MatrixBlock*)osglData->tempC)->type
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
    break;

  case 1451:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 1452:

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

  case 1453:

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

  case 1454:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfCon attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <con> cannot be negative");
    osglData->numberOfConPresent = true;        
    osglData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1455:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of constraints cannot be negative");
    osglData->numberOfConstraintsPresent = true;        
    osglData->numberOfConstraints = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1456:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->numberOfElPresent = true;        
    osglData->numberOfEl = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1457:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfEnumerationsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <enumerations> cannot be negative");
    osglData->numberOfEnumerationsPresent = true;        
    osglData->numberOfEnumerations = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1458:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfItemsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfItems attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <items> cannot be negative");
    osglData->numberOfItemsPresent = true;        
    osglData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1459:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfMatrixVar attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <matrixVar> cannot be negative");
    osglData->numberOfMatrixVarPresent = true;        
    osglData->numberOfMatrixVar = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1460:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfObj attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    osglData->numberOfObjPresent = true;        
    osglData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1461:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of objectives cannot be negative");
    osglData->numberOfObjectivesPresent = true;        
    osglData->numberOfObjectives = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1462:

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

  case 1463:

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

  case 1464:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVar attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <var> cannot be negative");
    osglData->numberOfVarPresent = true;        
    osglData->numberOfVar = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1465:

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

  case 1466:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVariablesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of variables cannot be negative");
    osglData->numberOfVariablesPresent = true;        
    osglData->numberOfVariables = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1467:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->base64SizePresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base64Size attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base64Size cannot be negative");
    osglData->base64SizePresent = true;        
    osglData->base64Size = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1468:

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

  case 1469:

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

  case 1470:

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

  case 1471:

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

  case 1472:

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

  case 1473:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
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

  case 1474:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
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

  case 1475:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1476:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1477:

    {
    if (osglData->matrixVarIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarIdx attribute in <matrixVar> element");
    osglData->matrixVarIdxPresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "<matrixVarIdx> cannot be negative");
    osglData->matrixVarIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1478:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->multPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mult must be positive");
    osglData->multPresent = true;
    osglData->mult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1479:

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

  case 1480:

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

  case 1481:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->coefPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "linear matrix elements: duplicate coef");    
    else
    {
        osglData->coef = parserData->tempVal;
        osglData->coefPresent = true;
    }
}
    break;

  case 1482:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->constantPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "linear matrix elements: duplicate constant");    
    else
    {
        osglData->constant = parserData->tempVal;
        osglData->constantPresent = true;
    }
}
    break;

  case 1483:

    {
std::cout << "matched \"Im\"; value = " << parserData->tempVal << std::cout;
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
}
    break;

  case 1484:

    {
std::cout << "matched \"Re\"; value = " << parserData->tempVal << std::cout;
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
}
    break;

  case 1485:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}
    break;

  case 1488:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}
    break;

  case 1489:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
    {
        if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->baseTranspose = false;
        else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->baseTranspose = true;
        else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    }
    osglData->baseTransposePresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1492:

    {
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;
}
    break;

  case 1493:

    { 
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;   
    osglData->category = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1496:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;  
}
    break;

  case 1497:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;   
    osglData->conType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1500:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;
}
    break;

  case 1501:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;   
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1504:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
}
    break;

  case 1505:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
    osglData->enumType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1508:

    {
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
}
    break;

  case 1509:

    {
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
    osglData->matrixVarType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1512:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}
    break;

  case 1513:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1516:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
}
    break;

  case 1517:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
    osglData->objType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1520:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}
    break;

  case 1521:

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

  case 1524:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}
    break;

  case 1525:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1528:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
}
    break;

  case 1529:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
    osglData->solver = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1532:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}
    break;

  case 1533:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1536:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}
    break;

  case 1537:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1540:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
}
    break;

  case 1541:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
    osglData->unit = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1544:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}
    break;

  case 1545:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1548:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}
    break;

  case 1549:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1552:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}
    break;

  case 1553:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1581:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1585:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1589:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1591:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1593:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1595:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1597:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1599:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1601:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1603:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1605:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1607:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1609:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1611:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1614:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1615:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1616:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1617:

    {
}
    break;

  case 1618:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1619:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1620:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1622:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1624:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1626:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}
    break;

  case 1627:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 1632:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }
    break;

  case 1633:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }
    break;

  case 1635:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 1637:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 1638:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 1641:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }
    break;

  case 1645:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 1646:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 1647:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 1648:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1649:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1650:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 1652:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 1653:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1654:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1656:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 1657:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1658:

    {
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1660:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 1661:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1662:

    {
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1664:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 1665:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1666:

    {
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 1668:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 1688:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1689:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 1692:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1693:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1694:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 1697:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1698:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1699:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 1702:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1703:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1704:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 1707:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1709:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1712:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1715:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1718:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1721:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1723:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1726:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1728:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1730:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1732:

    {
     parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 1736:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1739:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1742:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1745:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1747:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1748:

    {
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 1750:

    { 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
}
    break;

  case 1752:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1755:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1758:

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
    error = "OSrL input is either invalid or not well-formed: "  + error;
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


