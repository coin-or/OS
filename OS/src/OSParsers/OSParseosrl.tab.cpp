
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
     MATRIXVARIDXATT = 483,
     MATRIXOBJIDXATT = 484,
     MATRIXCONIDXATT = 485,
     IDXATT = 486,
     INCRATT = 487,
     MULTATT = 488,
     SIZEOFATT = 489,
     COEFATT = 490,
     CONSTANTATT = 491,
     MATRICESSTART = 492,
     MATRICESEND = 493,
     MATRIXSTART = 494,
     MATRIXEND = 495,
     BASEMATRIXEND = 496,
     BASEMATRIXSTART = 497,
     BLOCKSSTART = 498,
     BLOCKSEND = 499,
     BLOCKSTART = 500,
     BLOCKEND = 501,
     COLOFFSETSTART = 502,
     COLOFFSETEND = 503,
     ROWOFFSETSTART = 504,
     ROWOFFSETEND = 505,
     ELEMENTSSTART = 506,
     ELEMENTSEND = 507,
     CONSTANTELEMENTSSTART = 508,
     CONSTANTELEMENTSEND = 509,
     COMPLEXELEMENTSSTART = 510,
     COMPLEXELEMENTSEND = 511,
     VARREFERENCEELEMENTSSTART = 512,
     VARREFERENCEELEMENTSEND = 513,
     LINEARELEMENTSSTART = 514,
     LINEARELEMENTSEND = 515,
     CONREFERENCEELEMENTSSTART = 516,
     CONREFERENCEELEMENTSEND = 517,
     OBJREFERENCEELEMENTSSTART = 518,
     OBJREFERENCEELEMENTSEND = 519,
     REALVALUEDEXPRESSIONSSTART = 520,
     REALVALUEDEXPRESSIONSSEND = 521,
     COMPLEXVALUEDEXPRESSIONSSTART = 522,
     COMPLEXVALUEDEXPRESSIONSSEND = 523,
     STRINGVALUEDELEMENTSSTART = 524,
     STRINGVALUEDELEMENTSEND = 525,
     STARTVECTORSTART = 526,
     STARTVECTOREND = 527,
     INDEXSTART = 528,
     INDEXEND = 529,
     VALUESTART = 530,
     VALUEEND = 531,
     VARIDXSTART = 532,
     VARIDXEND = 533,
     TRANSFORMATIONSTART = 534,
     TRANSFORMATIONEND = 535,
     MATRIXPROGRAMMINGSTART = 536,
     MATRIXPROGRAMMINGEND = 537,
     MATRIXVARIABLESSTART = 538,
     MATRIXVARIABLESEND = 539,
     MATRIXVARSTART = 540,
     MATRIXVAREND = 541,
     MATRIXOBJECTIVESSTART = 542,
     MATRIXOBJECTIVESEND = 543,
     MATRIXOBJSTART = 544,
     MATRIXOBJEND = 545,
     MATRIXCONSTRAINTSSTART = 546,
     MATRIXCONSTRAINTSEND = 547,
     MATRIXCONSTART = 548,
     MATRIXCONEND = 549,
     CONSTART = 550,
     CONEND = 551,
     CONSTRAINTSSTART = 552,
     CONSTRAINTSEND = 553,
     OBJSTART = 554,
     OBJEND = 555,
     OBJECTIVESSTART = 556,
     OBJECTIVESEND = 557,
     VARSTART = 558,
     VAREND = 559,
     VARIABLESSTART = 560,
     VARIABLESEND = 561,
     GENERALSTART = 562,
     GENERALEND = 563,
     SYSTEMSTART = 564,
     SYSTEMEND = 565,
     SERVICESTART = 566,
     SERVICEEND = 567,
     JOBSTART = 568,
     JOBEND = 569,
     OPTIMIZATIONSTART = 570,
     OPTIMIZATIONEND = 571,
     ATEQUALITYSTART = 572,
     ATEQUALITYEND = 573,
     ATLOWERSTART = 574,
     ATLOWEREND = 575,
     ATUPPERSTART = 576,
     ATUPPEREND = 577,
     BASICSTART = 578,
     BASICEND = 579,
     ISFREESTART = 580,
     ISFREEEND = 581,
     SUPERBASICSTART = 582,
     SUPERBASICEND = 583,
     UNKNOWNSTART = 584,
     UNKNOWNEND = 585,
     SERVICEURISTART = 586,
     SERVICEURIEND = 587,
     SERVICENAMESTART = 588,
     SERVICENAMEEND = 589,
     INSTANCENAMESTART = 590,
     INSTANCENAMEEND = 591,
     JOBIDSTART = 592,
     JOBIDEND = 593,
     OTHERSTART = 594,
     OTHEREND = 595,
     DUMMY = 596,
     NONLINEAREXPRESSIONSSTART = 597,
     NONLINEAREXPRESSIONSEND = 598,
     NUMBEROFNONLINEAREXPRESSIONS = 599,
     NLSTART = 600,
     NLEND = 601,
     MATRIXEXPRESSIONSSTART = 602,
     MATRIXEXPRESSIONSEND = 603,
     NUMBEROFEXPR = 604,
     EXPRSTART = 605,
     EXPREND = 606,
     NUMBEROFMATRIXTERMSATT = 607,
     MATRIXTERMSTART = 608,
     MATRIXTERMEND = 609,
     POWERSTART = 610,
     POWEREND = 611,
     PLUSSTART = 612,
     PLUSEND = 613,
     MINUSSTART = 614,
     MINUSEND = 615,
     DIVIDESTART = 616,
     DIVIDEEND = 617,
     LNSTART = 618,
     LNEND = 619,
     SQRTSTART = 620,
     SQRTEND = 621,
     SUMSTART = 622,
     SUMEND = 623,
     PRODUCTSTART = 624,
     PRODUCTEND = 625,
     EXPSTART = 626,
     EXPEND = 627,
     NEGATESTART = 628,
     NEGATEEND = 629,
     IFSTART = 630,
     IFEND = 631,
     SQUARESTART = 632,
     SQUAREEND = 633,
     COSSTART = 634,
     COSEND = 635,
     SINSTART = 636,
     SINEND = 637,
     VARIABLESTART = 638,
     VARIABLEEND = 639,
     ABSSTART = 640,
     ABSEND = 641,
     ERFSTART = 642,
     ERFEND = 643,
     MAXSTART = 644,
     MAXEND = 645,
     ALLDIFFSTART = 646,
     ALLDIFFEND = 647,
     MINSTART = 648,
     MINEND = 649,
     ESTART = 650,
     EEND = 651,
     PISTART = 652,
     PIEND = 653,
     TIMESSTART = 654,
     TIMESEND = 655,
     NUMBERSTART = 656,
     NUMBEREND = 657,
     MATRIXDETERMINANTSTART = 658,
     MATRIXDETERMINANTEND = 659,
     MATRIXTRACESTART = 660,
     MATRIXTRACEEND = 661,
     MATRIXTOSCALARSTART = 662,
     MATRIXTOSCALAREND = 663,
     MATRIXDIAGONALSTART = 664,
     MATRIXDIAGONALEND = 665,
     MATRIXDOTTIMESSTART = 666,
     MATRIXDOTTIMESEND = 667,
     MATRIXLOWERTRIANGLESTART = 668,
     MATRIXLOWERTRIANGLEEND = 669,
     MATRIXUPPERTRIANGLESTART = 670,
     MATRIXUPPERTRIANGLEEND = 671,
     MATRIXMERGESTART = 672,
     MATRIXMERGEEND = 673,
     MATRIXMINUSSTART = 674,
     MATRIXMINUSEND = 675,
     MATRIXNEGATESTART = 676,
     MATRIXNEGATEEND = 677,
     MATRIXPLUSSTART = 678,
     MATRIXPLUSEND = 679,
     MATRIXTIMESSTART = 680,
     MATRIXTIMESEND = 681,
     MATRIXPRODUCTSTART = 682,
     MATRIXPRODUCTEND = 683,
     MATRIXSCALARTIMESSTART = 684,
     MATRIXSCALARTIMESEND = 685,
     MATRIXSUBMATRIXATSTART = 686,
     MATRIXSUBMATRIXATEND = 687,
     MATRIXTRANSPOSESTART = 688,
     MATRIXTRANSPOSEEND = 689,
     MATRIXREFERENCESTART = 690,
     MATRIXREFERENCEEND = 691,
     IDENTITYMATRIXSTART = 692,
     IDENTITYMATRIXEND = 693,
     MATRIXINVERSESTART = 694,
     MATRIXINVERSEEND = 695,
     EMPTYINCLUDEDIAGONALATT = 696,
     INCLUDEDIAGONALATT = 697,
     EMPTYIDATT = 698,
     IDATT = 699
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
#define MATRIXVARIDXATT 483
#define MATRIXOBJIDXATT 484
#define MATRIXCONIDXATT 485
#define IDXATT 486
#define INCRATT 487
#define MULTATT 488
#define SIZEOFATT 489
#define COEFATT 490
#define CONSTANTATT 491
#define MATRICESSTART 492
#define MATRICESEND 493
#define MATRIXSTART 494
#define MATRIXEND 495
#define BASEMATRIXEND 496
#define BASEMATRIXSTART 497
#define BLOCKSSTART 498
#define BLOCKSEND 499
#define BLOCKSTART 500
#define BLOCKEND 501
#define COLOFFSETSTART 502
#define COLOFFSETEND 503
#define ROWOFFSETSTART 504
#define ROWOFFSETEND 505
#define ELEMENTSSTART 506
#define ELEMENTSEND 507
#define CONSTANTELEMENTSSTART 508
#define CONSTANTELEMENTSEND 509
#define COMPLEXELEMENTSSTART 510
#define COMPLEXELEMENTSEND 511
#define VARREFERENCEELEMENTSSTART 512
#define VARREFERENCEELEMENTSEND 513
#define LINEARELEMENTSSTART 514
#define LINEARELEMENTSEND 515
#define CONREFERENCEELEMENTSSTART 516
#define CONREFERENCEELEMENTSEND 517
#define OBJREFERENCEELEMENTSSTART 518
#define OBJREFERENCEELEMENTSEND 519
#define REALVALUEDEXPRESSIONSSTART 520
#define REALVALUEDEXPRESSIONSSEND 521
#define COMPLEXVALUEDEXPRESSIONSSTART 522
#define COMPLEXVALUEDEXPRESSIONSSEND 523
#define STRINGVALUEDELEMENTSSTART 524
#define STRINGVALUEDELEMENTSEND 525
#define STARTVECTORSTART 526
#define STARTVECTOREND 527
#define INDEXSTART 528
#define INDEXEND 529
#define VALUESTART 530
#define VALUEEND 531
#define VARIDXSTART 532
#define VARIDXEND 533
#define TRANSFORMATIONSTART 534
#define TRANSFORMATIONEND 535
#define MATRIXPROGRAMMINGSTART 536
#define MATRIXPROGRAMMINGEND 537
#define MATRIXVARIABLESSTART 538
#define MATRIXVARIABLESEND 539
#define MATRIXVARSTART 540
#define MATRIXVAREND 541
#define MATRIXOBJECTIVESSTART 542
#define MATRIXOBJECTIVESEND 543
#define MATRIXOBJSTART 544
#define MATRIXOBJEND 545
#define MATRIXCONSTRAINTSSTART 546
#define MATRIXCONSTRAINTSEND 547
#define MATRIXCONSTART 548
#define MATRIXCONEND 549
#define CONSTART 550
#define CONEND 551
#define CONSTRAINTSSTART 552
#define CONSTRAINTSEND 553
#define OBJSTART 554
#define OBJEND 555
#define OBJECTIVESSTART 556
#define OBJECTIVESEND 557
#define VARSTART 558
#define VAREND 559
#define VARIABLESSTART 560
#define VARIABLESEND 561
#define GENERALSTART 562
#define GENERALEND 563
#define SYSTEMSTART 564
#define SYSTEMEND 565
#define SERVICESTART 566
#define SERVICEEND 567
#define JOBSTART 568
#define JOBEND 569
#define OPTIMIZATIONSTART 570
#define OPTIMIZATIONEND 571
#define ATEQUALITYSTART 572
#define ATEQUALITYEND 573
#define ATLOWERSTART 574
#define ATLOWEREND 575
#define ATUPPERSTART 576
#define ATUPPEREND 577
#define BASICSTART 578
#define BASICEND 579
#define ISFREESTART 580
#define ISFREEEND 581
#define SUPERBASICSTART 582
#define SUPERBASICEND 583
#define UNKNOWNSTART 584
#define UNKNOWNEND 585
#define SERVICEURISTART 586
#define SERVICEURIEND 587
#define SERVICENAMESTART 588
#define SERVICENAMEEND 589
#define INSTANCENAMESTART 590
#define INSTANCENAMEEND 591
#define JOBIDSTART 592
#define JOBIDEND 593
#define OTHERSTART 594
#define OTHEREND 595
#define DUMMY 596
#define NONLINEAREXPRESSIONSSTART 597
#define NONLINEAREXPRESSIONSEND 598
#define NUMBEROFNONLINEAREXPRESSIONS 599
#define NLSTART 600
#define NLEND 601
#define MATRIXEXPRESSIONSSTART 602
#define MATRIXEXPRESSIONSEND 603
#define NUMBEROFEXPR 604
#define EXPRSTART 605
#define EXPREND 606
#define NUMBEROFMATRIXTERMSATT 607
#define MATRIXTERMSTART 608
#define MATRIXTERMEND 609
#define POWERSTART 610
#define POWEREND 611
#define PLUSSTART 612
#define PLUSEND 613
#define MINUSSTART 614
#define MINUSEND 615
#define DIVIDESTART 616
#define DIVIDEEND 617
#define LNSTART 618
#define LNEND 619
#define SQRTSTART 620
#define SQRTEND 621
#define SUMSTART 622
#define SUMEND 623
#define PRODUCTSTART 624
#define PRODUCTEND 625
#define EXPSTART 626
#define EXPEND 627
#define NEGATESTART 628
#define NEGATEEND 629
#define IFSTART 630
#define IFEND 631
#define SQUARESTART 632
#define SQUAREEND 633
#define COSSTART 634
#define COSEND 635
#define SINSTART 636
#define SINEND 637
#define VARIABLESTART 638
#define VARIABLEEND 639
#define ABSSTART 640
#define ABSEND 641
#define ERFSTART 642
#define ERFEND 643
#define MAXSTART 644
#define MAXEND 645
#define ALLDIFFSTART 646
#define ALLDIFFEND 647
#define MINSTART 648
#define MINEND 649
#define ESTART 650
#define EEND 651
#define PISTART 652
#define PIEND 653
#define TIMESSTART 654
#define TIMESEND 655
#define NUMBERSTART 656
#define NUMBEREND 657
#define MATRIXDETERMINANTSTART 658
#define MATRIXDETERMINANTEND 659
#define MATRIXTRACESTART 660
#define MATRIXTRACEEND 661
#define MATRIXTOSCALARSTART 662
#define MATRIXTOSCALAREND 663
#define MATRIXDIAGONALSTART 664
#define MATRIXDIAGONALEND 665
#define MATRIXDOTTIMESSTART 666
#define MATRIXDOTTIMESEND 667
#define MATRIXLOWERTRIANGLESTART 668
#define MATRIXLOWERTRIANGLEEND 669
#define MATRIXUPPERTRIANGLESTART 670
#define MATRIXUPPERTRIANGLEEND 671
#define MATRIXMERGESTART 672
#define MATRIXMERGEEND 673
#define MATRIXMINUSSTART 674
#define MATRIXMINUSEND 675
#define MATRIXNEGATESTART 676
#define MATRIXNEGATEEND 677
#define MATRIXPLUSSTART 678
#define MATRIXPLUSEND 679
#define MATRIXTIMESSTART 680
#define MATRIXTIMESEND 681
#define MATRIXPRODUCTSTART 682
#define MATRIXPRODUCTEND 683
#define MATRIXSCALARTIMESSTART 684
#define MATRIXSCALARTIMESEND 685
#define MATRIXSUBMATRIXATSTART 686
#define MATRIXSUBMATRIXATEND 687
#define MATRIXTRANSPOSESTART 688
#define MATRIXTRANSPOSEEND 689
#define MATRIXREFERENCESTART 690
#define MATRIXREFERENCEEND 691
#define IDENTITYMATRIXSTART 692
#define IDENTITYMATRIXEND 693
#define MATRIXINVERSESTART 694
#define MATRIXINVERSEEND 695
#define EMPTYINCLUDEDIAGONALATT 696
#define INCLUDEDIAGONALATT 697
#define EMPTYIDATT 698
#define IDATT 699




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
#define YYLAST   2121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  449
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  1121
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1677
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2353

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   699

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   446,
     448,     2,     2,   447,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   445,     2,     2,     2,     2,     2,     2,     2,
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
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444
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
    2588,  2590,  2594,  2598,  2600,  2602,  2604,  2606,  2610,  2612,
    2616,  2618,  2620,  2622,  2624,  2628,  2630,  2634,  2636,  2638,
    2640,  2642,  2646,  2648,  2652,  2654,  2656,  2658,  2660,  2664,
    2666,  2670,  2672,  2674,  2676,  2678,  2682,  2684,  2688,  2690,
    2692,  2694,  2696,  2700,  2702,  2706,  2708,  2710,  2712,  2714,
    2718,  2720,  2722,  2726,  2728,  2730,  2731,  2734,  2736,  2738,
    2740,  2742,  2744,  2746,  2748,  2750,  2752,  2756,  2759,  2760,
    2764,  2766,  2768,  2769,  2772,  2774,  2776,  2778,  2780,  2782,
    2784,  2786,  2788,  2790,  2793,  2795,  2796,  2799,  2801,  2803,
    2805,  2807,  2809,  2811,  2813,  2815,  2820,  2822,  2824,  2825,
    2828,  2830,  2832,  2836,  2837,  2840,  2843,  2845,  2847,  2849,
    2851,  2855,  2857,  2860,  2862,  2864,  2866,  2868,  2872,  2874,
    2877,  2879,  2881,  2883,  2885,  2889,  2891,  2896,  2898,  2900,
    2901,  2904,  2906,  2908,  2912,  2913,  2916,  2919,  2921,  2923,
    2925,  2927,  2931,  2933,  2938,  2940,  2942,  2943,  2946,  2948,
    2950,  2954,  2955,  2958,  2959,  2962,  2964,  2966,  2968,  2970,
    2974,  2976,  2977,  2980,  2984,  2986,  2988,  2989,  2992,  2994,
    2996,  2998,  3000,  3002,  3006,  3007,  3010,  3014,  3016,  3017,
    3019,  3023,  3028,  3030,  3032,  3033,  3036,  3038,  3040,  3044,
    3045,  3048,  3049,  3052,  3054,  3056,  3058,  3060,  3064,  3065,
    3068,  3071,  3073,  3075,  3077,  3079,  3083,  3088,  3090,  3092,
    3093,  3096,  3098,  3100,  3104,  3105,  3108,  3111,  3113,  3115,
    3117,  3119,  3123,  3125,  3130,  3132,  3134,  3135,  3138,  3140,
    3142,  3146,  3147,  3150,  3151,  3154,  3156,  3158,  3160,  3162,
    3166,  3167,  3170,  3174,  3176,  3177,  3180,  3182,  3184,  3186,
    3190,  3196,  3198,  3199,  3201,  3203,  3207,  3209,  3211,  3217,
    3219,  3223,  3225,  3227,  3229,  3231,  3233,  3237,  3239,  3243,
    3245,  3247,  3249,  3251,  3253,  3257,  3259,  3260,  3263,  3267,
    3269,  3271,  3272,  3275,  3277,  3279,  3281,  3283,  3285,  3287,
    3289,  3293,  3296,  3301,  3306,  3311,  3316,  3321,  3326,  3331,
    3336,  3341,  3346,  3351,  3356,  3361,  3366,  3371,  3376,  3381,
    3386,  3391,  3396,  3401,  3406,  3411,  3416,  3421,  3426,  3431,
    3436,  3441,  3446,  3451,  3456,  3458,  3460,  3462,  3466,  3468,
    3470,  3472,  3476,  3478,  3480,  3482,  3486,  3488,  3490,  3492,
    3496,  3498,  3500,  3502,  3506,  3508,  3510,  3512,  3516,  3518,
    3520,  3522,  3526,  3528,  3530,  3532,  3536,  3538,  3540,  3542,
    3546,  3548,  3550,  3552,  3556,  3558,  3560,  3562,  3566,  3568,
    3570,  3572,  3576,  3578,  3580,  3582,  3586,  3588,  3590,  3592,
    3596,  3598,  3600,  3602,  3606,  3608,  3610,  3612,  3616,  3618,
    3620,  3622,  3626,  3628,  3630,  3632,  3634,  3636,  3638,  3640,
    3642,  3644,  3646,  3648,  3650,  3652,  3654,  3656,  3658,  3660,
    3662,  3664,  3666,  3668,  3670,  3672,  3674,  3676,  3678,  3680,
    3681,  3685,  3687,  3690,  3691,  3695,  3697,  3700,  3701,  3707,
    3708,  3714,  3715,  3721,  3722,  3727,  3728,  3734,  3735,  3741,
    3742,  3747,  3748,  3753,  3754,  3759,  3760,  3765,  3766,  3771,
    3772,  3777,  3781,  3783,  3785,  3786,  3791,  3792,  3799,  3800,
    3805,  3806,  3811,  3812,  3817,  3821,  3823,  3825,  3828,  3829,
    3832,  3834,  3836,  3838,  3839,  3844,  3845,  3850,  3852,  3855,
    3856,  3861,  3862,  3865,  3867,  3869,  3874,  3879,  3880,  3885,
    3886,  3889,  3890,  3895,  3896,  3899,  3900,  3905,  3906,  3909,
    3910,  3915,  3916,  3919,  3920,  3925,  3926,  3929,  3931,  3933,
    3935,  3937,  3939,  3941,  3943,  3945,  3947,  3949,  3951,  3953,
    3955,  3957,  3959,  3961,  3963,  3965,  3967,  3971,  3973,  3975,
    3978,  3983,  3987,  3989,  3991,  3994,  3999,  4003,  4005,  4007,
    4010,  4015,  4019,  4021,  4023,  4026,  4031,  4034,  4036,  4039,
    4042,  4044,  4048,  4051,  4053,  4056,  4059,  4061,  4064,  4069,
    4071,  4072,  4074,  4077,  4082,  4084,  4085,  4087,  4090,  4094,
    4097,  4099,  4101,  4104,  4107,  4109,  4113,  4116,  4118,  4121,
    4124,  4126,  4130,  4133,  4135,  4139,  4140,  4145,  4146,  4149,
    4152,  4154,  4158,  4161,  4163,  4170,  4173,  4175
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     450,     0,    -1,   451,   459,   457,    -1,   452,   453,   454,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   455,    -1,
     456,    -1,    11,    -1,    10,   459,   457,    -1,   458,    -1,
      15,    -1,    -1,   460,   461,   541,   595,   647,   742,    -1,
      -1,  1091,    -1,    -1,   462,   463,    -1,   307,    -1,   464,
      -1,   465,    -1,    10,   308,    -1,    11,    -1,    10,   466,
     308,    -1,   467,    -1,   468,    -1,   467,   468,    -1,   469,
      -1,   485,    -1,   491,    -1,   497,    -1,   503,    -1,   509,
      -1,   515,    -1,   521,    -1,   527,    -1,   470,   471,   474,
      -1,    56,    -1,   472,    -1,   473,    -1,   472,   473,    -1,
    1416,    -1,  1389,    -1,  1084,    -1,   475,    -1,   476,    -1,
      10,    57,    -1,    11,    -1,    10,   477,    57,    -1,   478,
      -1,   479,    -1,   478,   479,    -1,   480,   481,   484,    -1,
      88,    -1,   482,    -1,    -1,   482,   483,    -1,  1398,    -1,
    1389,    -1,    10,    89,    -1,    11,    -1,   486,   487,    -1,
      60,    -1,   488,    -1,   489,    -1,    10,    61,    -1,    11,
      -1,    10,   490,    61,    -1,     4,    -1,   492,   493,    -1,
     331,    -1,   494,    -1,   495,    -1,    10,   332,    -1,    11,
      -1,    10,   496,   332,    -1,     4,    -1,   498,   499,    -1,
     333,    -1,   500,    -1,   501,    -1,    10,   334,    -1,    11,
      -1,    10,   502,   334,    -1,     4,    -1,   504,   505,    -1,
     335,    -1,   506,    -1,   507,    -1,    10,   336,    -1,    11,
      -1,    10,   508,   336,    -1,     4,    -1,   510,   511,    -1,
     337,    -1,   512,    -1,   513,    -1,    10,   338,    -1,    11,
      -1,    10,   514,   338,    -1,     4,    -1,   516,   517,    -1,
      80,    -1,   518,    -1,   519,    -1,    10,    81,    -1,    11,
      -1,    10,   520,    81,    -1,     4,    -1,   522,   523,    -1,
      96,    -1,   524,    -1,   525,    -1,    10,    97,    -1,    11,
      -1,    10,   526,    97,    -1,     4,    -1,   528,   529,   530,
      -1,    66,    -1,  1079,    -1,   531,    -1,   532,    -1,    10,
      67,    -1,    11,    -1,    10,   533,    67,    -1,   534,    -1,
     535,    -1,   534,   535,    -1,   536,   537,   540,    -1,   339,
      -1,   538,    -1,    -1,   538,   539,    -1,  1398,    -1,  1422,
      -1,  1389,    -1,    10,   340,    -1,    11,    -1,    -1,   542,
     543,    -1,   309,    -1,   544,    -1,   545,    -1,    10,   310,
      -1,    11,    -1,    10,   546,   310,    -1,   547,    -1,   548,
      -1,   547,   548,    -1,   549,    -1,   555,    -1,   562,    -1,
     569,    -1,   576,    -1,   581,    -1,   550,   551,    -1,    90,
      -1,   552,    -1,   553,    -1,    10,    91,    -1,    11,    -1,
      10,   554,    91,    -1,     4,    -1,   556,   557,   560,    -1,
      40,    -1,   558,    -1,    -1,   558,   559,    -1,  1419,    -1,
    1389,    -1,    10,   561,    41,    -1,  1086,    -1,   563,   564,
     567,    -1,    42,    -1,   565,    -1,    -1,   565,   566,    -1,
    1419,    -1,  1389,    -1,    10,   568,    43,    -1,  1086,    -1,
     570,   571,   574,    -1,    38,    -1,   572,    -1,    -1,   572,
     573,    -1,  1419,    -1,  1389,    -1,    10,   575,    39,    -1,
    1086,    -1,   577,   578,   579,    -1,    36,    -1,    -1,  1389,
      -1,    10,   580,    37,    -1,     6,    -1,   582,   583,   584,
      -1,    66,    -1,  1079,    -1,   585,    -1,   586,    -1,    10,
      67,    -1,    11,    -1,    10,   587,    67,    -1,   588,    -1,
     589,    -1,   588,   589,    -1,   590,   591,   594,    -1,   339,
      -1,   592,    -1,    -1,   592,   593,    -1,  1398,    -1,  1422,
      -1,  1389,    -1,    10,   340,    -1,    11,    -1,    -1,   596,
     597,    -1,   311,    -1,   598,    -1,   599,    -1,    10,   312,
      -1,    11,    -1,    10,   600,   312,    -1,   601,    -1,   602,
      -1,   601,   602,    -1,   603,    -1,   609,    -1,   615,    -1,
     621,    -1,   627,    -1,   633,    -1,   604,   605,    -1,    48,
      -1,   606,    -1,   607,    -1,    10,    49,    -1,    11,    -1,
      10,   608,    49,    -1,     4,    -1,   610,   611,    -1,    46,
      -1,   612,    -1,   613,    -1,    10,    47,    -1,    11,    -1,
      10,   614,    47,    -1,     6,    -1,   616,   617,    -1,   100,
      -1,   618,    -1,   619,    -1,    10,   101,    -1,    11,    -1,
      10,   620,   101,    -1,     6,    -1,   622,   623,    -1,    94,
      -1,   624,    -1,   625,    -1,    10,    95,    -1,    11,    -1,
      10,   626,    95,    -1,     4,    -1,   628,   629,    -1,    76,
      -1,   630,    -1,   631,    -1,    10,    77,    -1,    11,    -1,
      10,   632,    77,    -1,  1086,    -1,   634,   635,   636,    -1,
      66,    -1,  1079,    -1,   637,    -1,   638,    -1,    10,    67,
      -1,    11,    -1,    10,   639,    67,    -1,   640,    -1,   641,
      -1,   640,   641,    -1,   642,   643,   646,    -1,   339,    -1,
     644,    -1,    -1,   644,   645,    -1,  1398,    -1,  1422,    -1,
    1389,    -1,    10,   340,    -1,    11,    -1,    -1,   648,   649,
      -1,   313,    -1,   650,    -1,   651,    -1,    10,   314,    -1,
      11,    -1,    10,   652,   314,    -1,   653,    -1,   654,    -1,
     653,   654,    -1,   655,    -1,   661,    -1,   667,    -1,   673,
      -1,   679,    -1,   685,    -1,   702,    -1,   709,    -1,   716,
      -1,   723,    -1,   728,    -1,   656,   657,    -1,    84,    -1,
     658,    -1,   659,    -1,    10,    85,    -1,    11,    -1,    10,
     660,    85,    -1,     4,    -1,   662,   663,    -1,    86,    -1,
     664,    -1,   665,    -1,    10,    87,    -1,    11,    -1,    10,
     666,    87,    -1,     4,    -1,   668,   669,    -1,    74,    -1,
     670,    -1,   671,    -1,    10,    75,    -1,    11,    -1,    10,
     672,    75,    -1,     4,    -1,   674,   675,    -1,    34,    -1,
     676,    -1,   677,    -1,    10,    35,    -1,    11,    -1,    10,
     678,    35,    -1,     4,    -1,   680,   681,    -1,    52,    -1,
     682,    -1,   683,    -1,    10,    53,    -1,    11,    -1,    10,
     684,    53,    -1,     4,    -1,   686,   687,   688,    -1,    98,
      -1,  1085,    -1,   689,    -1,   690,    -1,    10,    99,    -1,
      11,    -1,    10,   691,    99,    -1,   692,    -1,   693,    -1,
     692,   693,    -1,   694,   695,   697,    -1,    92,    -1,    -1,
     695,   696,    -1,  1419,    -1,  1416,    -1,  1383,    -1,  1389,
      -1,   698,    -1,   699,    -1,    10,    93,    -1,    11,    -1,
      10,   700,    93,    -1,   701,    -1,     7,    -1,     6,    -1,
     703,   704,   707,    -1,   106,    -1,   705,    -1,    -1,   705,
     706,    -1,  1419,    -1,  1389,    -1,    10,   708,   107,    -1,
    1086,    -1,   710,   711,   714,    -1,   108,    -1,   712,    -1,
      -1,   712,   713,    -1,  1419,    -1,  1389,    -1,    10,   715,
     109,    -1,  1086,    -1,   717,   718,   721,    -1,   104,    -1,
     719,    -1,    -1,   719,   720,    -1,  1419,    -1,  1389,    -1,
      10,   722,   105,    -1,  1086,    -1,   724,   725,   726,    -1,
     102,    -1,    -1,  1389,    -1,    10,   727,   103,    -1,     6,
      -1,   729,   730,   731,    -1,    66,    -1,  1079,    -1,   732,
      -1,   733,    -1,    10,    67,    -1,    11,    -1,    10,   734,
      67,    -1,   735,    -1,   736,    -1,   735,   736,    -1,   737,
     738,   741,    -1,   339,    -1,   739,    -1,    -1,   739,   740,
      -1,  1398,    -1,  1422,    -1,  1389,    -1,    10,   340,    -1,
      11,    -1,    -1,   743,   744,   747,    -1,   315,    -1,   745,
      -1,    -1,   745,   746,    -1,  1082,    -1,  1362,    -1,  1351,
      -1,  1357,    -1,   748,    -1,   749,    -1,    10,   316,    -1,
      11,    -1,    10,   750,   316,    -1,   751,  1052,    -1,   752,
      -1,   751,   752,    -1,   753,   754,   760,    -1,    78,    -1,
     755,    -1,    -1,   755,   756,    -1,   757,    -1,   758,    -1,
     759,    -1,    33,  1088,     6,  1088,    -1,    18,     3,  1088,
      -1,    16,     3,  1088,    -1,    10,   761,   777,   783,   861,
     923,   985,  1029,    79,    -1,   762,   763,   766,    -1,    84,
      -1,   764,    -1,   765,    -1,   764,   765,    -1,  1416,    -1,
    1389,    -1,  1084,    -1,   767,    -1,   768,    -1,    10,    85,
      -1,    11,    -1,    10,   769,    85,    -1,   770,    -1,   771,
      -1,   770,   771,    -1,   772,   773,   776,    -1,    88,    -1,
     774,    -1,    -1,   774,   775,    -1,  1416,    -1,  1389,    -1,
      10,    89,    -1,    11,    -1,    -1,   778,   779,    -1,    60,
      -1,   780,    -1,   781,    -1,    10,    61,    -1,    11,    -1,
      10,   782,    61,    -1,     4,    -1,    -1,   784,   785,   786,
      -1,   305,    -1,    -1,  1081,    -1,   787,    -1,   788,    -1,
      11,    -1,    10,   789,   306,    -1,   790,   803,   819,   832,
      -1,    -1,   791,   792,   793,    -1,   144,    -1,  1360,    -1,
     794,    -1,   795,    -1,    10,   145,    -1,    11,    -1,    10,
     796,   145,    -1,   797,    -1,   798,    -1,   797,   798,    -1,
     799,   800,   802,    -1,   303,    -1,    -1,   800,   801,    -1,
    1373,    -1,  1398,    -1,    10,  1086,   304,    -1,    -1,   804,
     805,   806,    -1,   110,    -1,  1360,    -1,   807,    -1,   808,
      -1,    10,   111,    -1,    11,    -1,    10,   809,   111,    -1,
     810,    -1,   811,    -1,   810,   811,    -1,   812,   813,   815,
      -1,   303,    -1,    -1,   813,   814,    -1,  1373,    -1,  1398,
      -1,   816,    -1,   817,    -1,    10,   304,    -1,    11,    -1,
      10,   818,   304,    -1,     4,    -1,    -1,   820,   821,    -1,
      44,    -1,   822,    -1,   823,    -1,    11,    -1,    10,   824,
      45,    -1,   825,   826,   827,   828,   829,   830,   831,    -1,
      -1,  1141,    -1,    -1,  1147,    -1,    -1,  1153,    -1,    -1,
    1159,    -1,    -1,  1165,    -1,    -1,  1171,    -1,    -1,  1177,
      -1,    -1,   832,   833,    -1,   834,   835,   838,    -1,   339,
      -1,   836,    -1,    -1,   836,   837,    -1,  1360,    -1,  1353,
      -1,  1422,    -1,  1410,    -1,  1398,    -1,  1416,    -1,  1428,
      -1,  1392,    -1,  1389,    -1,   839,    -1,   840,    -1,    10,
     340,    -1,    11,    -1,    10,   841,   340,    -1,   842,    -1,
     851,    -1,   843,    -1,   842,   843,    -1,   844,   845,   847,
      -1,   303,    -1,    -1,   845,   846,    -1,  1373,    -1,  1398,
      -1,   848,    -1,   849,    -1,    10,   304,    -1,    11,    -1,
      10,   850,   304,    -1,  1087,    -1,   852,    -1,   851,   852,
      -1,   853,   854,   857,    -1,   150,    -1,   855,    -1,    -1,
     855,   856,    -1,  1352,    -1,  1422,    -1,  1389,    -1,   858,
      -1,   859,    -1,    11,    -1,    10,   860,   151,    -1,  1119,
      -1,    -1,   862,   863,   864,    -1,   301,    -1,    -1,  1078,
      -1,   865,    -1,   866,    -1,    11,    -1,    10,   867,   302,
      -1,   868,   881,   894,    -1,    -1,   869,   870,   871,    -1,
     144,    -1,  1356,    -1,   872,    -1,   873,    -1,    10,   145,
      -1,    11,    -1,    10,   874,   145,    -1,   875,    -1,   876,
      -1,   875,   876,    -1,   877,   878,   880,    -1,   299,    -1,
      -1,   878,   879,    -1,  1373,    -1,  1398,    -1,    10,  1086,
     300,    -1,    -1,   882,   883,    -1,    44,    -1,   884,    -1,
     885,    -1,    11,    -1,    10,   886,    45,    -1,   887,   888,
     889,   890,   891,   892,   893,    -1,    -1,  1141,    -1,    -1,
    1147,    -1,    -1,  1153,    -1,    -1,  1159,    -1,    -1,  1165,
      -1,    -1,  1171,    -1,    -1,  1177,    -1,    -1,   894,   895,
      -1,   896,   897,   900,    -1,   339,    -1,   898,    -1,    -1,
     898,   899,    -1,  1356,    -1,  1353,    -1,  1422,    -1,  1410,
      -1,  1398,    -1,  1416,    -1,  1401,    -1,  1392,    -1,  1389,
      -1,   901,    -1,   902,    -1,    10,   340,    -1,    11,    -1,
      10,   903,   340,    -1,   904,    -1,   913,    -1,   905,    -1,
     904,   905,    -1,   906,   907,   909,    -1,   299,    -1,    -1,
     907,   908,    -1,  1373,    -1,  1398,    -1,   910,    -1,   911,
      -1,    10,   300,    -1,    11,    -1,    10,   912,   300,    -1,
    1087,    -1,   914,    -1,   913,   914,    -1,   915,   916,   919,
      -1,   150,    -1,   917,    -1,    -1,   917,   918,    -1,  1352,
      -1,  1422,    -1,  1389,    -1,   920,    -1,   921,    -1,    11,
      -1,    10,   922,   151,    -1,  1119,    -1,    -1,   924,   925,
     926,    -1,   297,    -1,    -1,  1075,    -1,   927,    -1,   928,
      -1,    11,    -1,    10,   929,   298,    -1,   930,   943,   956,
      -1,    -1,   931,   932,   933,    -1,    50,    -1,  1350,    -1,
     934,    -1,   935,    -1,    10,    51,    -1,    11,    -1,    10,
     936,    51,    -1,   937,    -1,   938,    -1,   937,   938,    -1,
     939,   940,   942,    -1,   295,    -1,    -1,   940,   941,    -1,
    1373,    -1,  1398,    -1,    10,  1086,   296,    -1,    -1,   944,
     945,    -1,    44,    -1,   946,    -1,   947,    -1,    11,    -1,
      10,   948,    45,    -1,   949,   950,   951,   952,   953,   954,
     955,    -1,    -1,  1141,    -1,    -1,  1147,    -1,    -1,  1153,
      -1,    -1,  1159,    -1,    -1,  1165,    -1,    -1,  1171,    -1,
      -1,  1177,    -1,    -1,   956,   957,    -1,   958,   959,   962,
      -1,   339,    -1,   960,    -1,    -1,   960,   961,    -1,  1350,
      -1,  1353,    -1,  1422,    -1,  1410,    -1,  1398,    -1,  1416,
      -1,  1386,    -1,  1392,    -1,  1389,    -1,   963,    -1,   964,
      -1,    10,   340,    -1,    11,    -1,    10,   965,   340,    -1,
     966,    -1,   975,    -1,   967,    -1,   966,   967,    -1,   968,
     969,   971,    -1,   295,    -1,    -1,   969,   970,    -1,  1373,
      -1,  1398,    -1,   972,    -1,   973,    -1,    10,   296,    -1,
      11,    -1,    10,   974,   296,    -1,  1087,    -1,   976,    -1,
     975,   976,    -1,   977,   978,   981,    -1,   150,    -1,   979,
      -1,    -1,   979,   980,    -1,  1352,    -1,  1422,    -1,  1389,
      -1,   982,    -1,   983,    -1,    11,    -1,    10,   984,   151,
      -1,  1119,    -1,    -1,   986,   987,   988,    -1,   281,    -1,
      -1,  1076,    -1,   989,    -1,   990,    -1,    11,    -1,    10,
     991,  1027,   282,    -1,    -1,   992,   993,   994,    -1,   283,
      -1,  1077,    -1,   995,    -1,   996,    -1,    11,    -1,    10,
     998,  1006,   997,    -1,   284,    -1,    -1,   999,  1000,  1001,
      -1,   144,    -1,  1355,    -1,  1002,    -1,  1003,    -1,    11,
      -1,    10,  1005,  1004,    -1,   145,    -1,    -1,  1005,  1184,
      -1,    -1,  1006,  1007,    -1,  1008,  1009,  1012,    -1,   339,
      -1,  1010,    -1,    -1,  1010,  1011,    -1,  1355,    -1,  1353,
      -1,  1422,    -1,  1410,    -1,  1398,    -1,  1416,    -1,  1395,
      -1,  1392,    -1,  1389,    -1,  1013,    -1,  1014,    -1,    10,
     340,    -1,    11,    -1,    10,  1015,   340,    -1,  1017,    -1,
    1016,    -1,  1184,    -1,  1016,  1184,    -1,  1018,    -1,  1017,
    1018,    -1,  1019,  1020,  1023,    -1,   150,    -1,  1021,    -1,
      -1,  1021,  1022,    -1,  1352,    -1,  1422,    -1,  1389,    -1,
    1024,    -1,  1025,    -1,    11,    -1,    10,  1026,   151,    -1,
    1119,    -1,    -1,  1027,  1028,    -1,   118,    -1,    -1,  1030,
    1031,  1032,    -1,    70,    -1,  1080,    -1,  1033,    -1,  1034,
      -1,    10,    71,    -1,    11,    -1,    10,  1035,    71,    -1,
    1036,    -1,  1037,    -1,  1036,  1037,    -1,  1038,  1039,  1042,
      -1,    68,    -1,  1040,    -1,    -1,  1040,  1041,    -1,  1398,
      -1,  1422,    -1,  1383,    -1,  1389,    -1,  1354,    -1,  1043,
      -1,  1044,    -1,    10,    69,    -1,    11,    -1,    10,  1045,
      69,    -1,  1046,    -1,  1047,    -1,  1046,  1047,    -1,  1048,
      -1,  1049,    -1,  1050,    -1,   155,    -1,   152,    -1,   153,
    1051,   154,    -1,     5,    -1,    -1,  1053,  1054,  1055,    -1,
      72,    -1,  1083,    -1,  1056,    -1,  1057,    -1,    10,    73,
      -1,    11,    -1,    10,  1058,    73,    -1,  1059,    -1,  1060,
      -1,  1059,  1060,    -1,  1061,  1062,  1065,    -1,    82,    -1,
    1063,    -1,    -1,  1063,  1064,    -1,  1398,    -1,  1383,    -1,
    1389,    -1,  1354,    -1,  1066,    -1,  1067,    -1,    10,    83,
      -1,    11,    -1,    10,  1068,    83,    -1,  1069,    -1,  1070,
      -1,  1069,  1070,    -1,  1071,    -1,  1072,    -1,  1073,    -1,
     155,    -1,   152,    -1,   153,  1074,   154,    -1,     5,    -1,
      20,  1088,     6,  1088,    -1,    28,  1088,     6,  1088,    -1,
      29,  1088,     6,  1088,    -1,    21,  1088,     6,  1088,    -1,
      22,  1088,     6,  1088,    -1,    23,  1088,     6,  1088,    -1,
      24,  1088,     6,  1088,    -1,    25,  1088,     6,  1088,    -1,
      30,  1088,     6,  1088,    -1,    31,  1088,     6,  1088,    -1,
      32,  1088,     6,  1088,    -1,     6,    -1,     7,    -1,     4,
      -1,     6,    -1,     7,    -1,  1089,     8,    -1,    -1,  1089,
    1090,    -1,   445,    -1,   446,    -1,   447,    -1,   448,    -1,
    1092,  1093,    -1,   120,    -1,  1094,    -1,  1095,    -1,    11,
      -1,    10,  1096,   121,    -1,  1097,    -1,    -1,  1097,  1098,
      -1,  1099,    -1,  1103,    -1,  1107,    -1,  1111,    -1,  1115,
      -1,  1100,    -1,  1101,    -1,  1102,    -1,   125,    -1,   124,
      -1,   122,     5,   123,    -1,  1104,    -1,  1105,    -1,  1106,
      -1,   129,    -1,   128,    -1,   126,     5,   127,    -1,  1108,
      -1,  1109,    -1,  1110,    -1,   133,    -1,   132,    -1,   130,
       5,   131,    -1,  1112,    -1,  1113,    -1,  1114,    -1,   137,
      -1,   136,    -1,   134,     5,   135,    -1,  1116,    -1,  1117,
      -1,  1118,    -1,   141,    -1,   140,    -1,   138,     5,   139,
      -1,  1120,    -1,  1127,    -1,    -1,  1120,  1121,    -1,  1122,
    1123,  1126,    -1,   148,    -1,  1124,    -1,    -1,  1124,  1125,
      -1,  1376,    -1,  1374,    -1,    10,     6,   149,    -1,   156,
    1363,  1128,    -1,  1129,    -1,  1130,    -1,    10,   157,    -1,
      11,    -1,    10,     4,   157,    -1,  1132,    -1,  1137,    -1,
      -1,  1132,  1133,    -1,  1134,  1135,  1136,    -1,   148,    -1,
      -1,  1376,    -1,    10,  1086,   149,    -1,   156,  1363,  1138,
      -1,  1139,    -1,  1140,    -1,    10,   157,    -1,    11,    -1,
      10,     4,   157,    -1,  1142,  1183,  1143,    -1,   323,    -1,
    1144,    -1,  1145,    -1,    11,    -1,    10,  1146,   324,    -1,
    1119,    -1,  1148,  1183,  1149,    -1,   319,    -1,  1150,    -1,
    1151,    -1,    11,    -1,    10,  1152,   320,    -1,  1119,    -1,
    1154,  1183,  1155,    -1,   321,    -1,  1156,    -1,  1157,    -1,
      11,    -1,    10,  1158,   322,    -1,  1119,    -1,  1160,  1183,
    1161,    -1,   317,    -1,  1162,    -1,  1163,    -1,    11,    -1,
      10,  1164,   318,    -1,  1119,    -1,  1166,  1183,  1167,    -1,
     325,    -1,  1168,    -1,  1169,    -1,    11,    -1,    10,  1170,
     326,    -1,  1119,    -1,  1172,  1183,  1173,    -1,   327,    -1,
    1174,    -1,  1175,    -1,    11,    -1,    10,  1176,   328,    -1,
    1119,    -1,  1178,  1183,  1179,    -1,   329,    -1,  1180,    -1,
    1181,    -1,    11,    -1,    10,  1182,   330,    -1,  1119,    -1,
    1352,    -1,  1185,  1186,  1189,    -1,   285,    -1,  1187,    -1,
      -1,  1187,  1188,    -1,  1413,    -1,  1358,    -1,  1349,    -1,
    1398,    -1,  1416,    -1,  1375,    -1,  1190,    -1,  1191,    -1,
      11,    -1,    10,  1192,   286,    -1,  1193,  1199,    -1,    -1,
    1194,  1195,  1198,    -1,   242,    -1,  1196,    -1,    -1,  1196,
    1197,    -1,  1364,    -1,  1378,    -1,  1379,    -1,  1365,    -1,
    1366,    -1,  1367,    -1,  1368,    -1,  1380,    -1,  1377,    -1,
      10,   241,    -1,    11,    -1,    -1,  1199,  1200,    -1,  1201,
      -1,  1226,    -1,  1239,    -1,  1266,    -1,  1284,    -1,  1297,
      -1,  1315,    -1,  1319,    -1,  1202,  1203,    10,  1206,    -1,
     253,    -1,  1204,    -1,    -1,  1204,  1205,    -1,  1359,    -1,
    1404,    -1,  1208,  1207,   254,    -1,    -1,  1214,  1220,    -1,
    1209,  1210,    -1,   271,    -1,  1211,    -1,  1212,    -1,    11,
      -1,    10,  1213,   272,    -1,  1119,    -1,  1215,  1216,    -1,
     273,    -1,  1217,    -1,  1218,    -1,    11,    -1,    10,  1219,
     274,    -1,  1119,    -1,  1221,  1222,    -1,   275,    -1,  1223,
      -1,  1224,    -1,    11,    -1,    10,  1225,   276,    -1,  1131,
      -1,  1227,  1228,    10,  1231,    -1,   257,    -1,  1229,    -1,
      -1,  1229,  1230,    -1,  1359,    -1,  1404,    -1,  1208,  1232,
     258,    -1,    -1,  1214,  1233,    -1,  1234,  1235,    -1,   275,
      -1,  1236,    -1,  1237,    -1,    11,    -1,    10,  1238,   276,
      -1,  1119,    -1,  1240,  1241,    10,  1244,    -1,   259,    -1,
    1242,    -1,    -1,  1242,  1243,    -1,  1359,    -1,  1404,    -1,
    1208,  1245,   260,    -1,    -1,  1214,  1246,    -1,    -1,  1247,
    1248,    -1,   275,    -1,  1249,    -1,  1250,    -1,    11,    -1,
      10,  1251,   276,    -1,  1252,    -1,    -1,  1252,  1253,    -1,
    1254,  1255,  1258,    -1,   148,    -1,  1256,    -1,    -1,  1256,
    1257,    -1,  1361,    -1,  1372,    -1,  1259,    -1,  1260,    -1,
      11,    -1,    10,  1261,   149,    -1,    -1,  1261,  1262,    -1,
    1263,  1264,  1265,    -1,   277,    -1,    -1,  1371,    -1,    10,
       6,   278,    -1,  1267,  1268,    10,  1271,    -1,   265,    -1,
    1269,    -1,    -1,  1269,  1270,    -1,  1359,    -1,  1404,    -1,
    1208,  1272,   266,    -1,    -1,  1214,  1273,    -1,    -1,  1274,
    1275,    -1,   275,    -1,  1276,    -1,  1277,    -1,    11,    -1,
      10,  1278,   276,    -1,    -1,  1278,  1279,    -1,  1280,  1281,
      -1,   148,    -1,  1282,    -1,  1283,    -1,    11,    -1,    10,
    1431,   149,    -1,  1285,  1286,    10,  1289,    -1,   263,    -1,
    1287,    -1,    -1,  1287,  1288,    -1,  1359,    -1,  1404,    -1,
    1208,  1290,   264,    -1,    -1,  1214,  1291,    -1,  1292,  1293,
      -1,   275,    -1,  1294,    -1,  1295,    -1,    11,    -1,    10,
    1296,   276,    -1,  1119,    -1,  1298,  1299,    10,  1302,    -1,
     261,    -1,  1300,    -1,    -1,  1300,  1301,    -1,  1359,    -1,
    1404,    -1,  1208,  1303,   262,    -1,    -1,  1214,  1304,    -1,
      -1,  1305,  1306,    -1,   275,    -1,  1307,    -1,  1308,    -1,
      11,    -1,    10,  1309,   276,    -1,    -1,  1309,  1310,    -1,
    1311,  1312,  1314,    -1,   148,    -1,    -1,  1312,  1313,    -1,
    1425,    -1,  1376,    -1,  1374,    -1,    10,     6,   149,    -1,
    1316,  1317,    10,  1505,  1318,    -1,   279,    -1,    -1,  1407,
      -1,   280,    -1,  1320,  1321,  1322,    -1,   243,    -1,  1348,
      -1,    10,  1324,  1331,  1338,  1323,    -1,   244,    -1,  1325,
    1326,  1327,    -1,   247,    -1,  1352,    -1,  1328,    -1,  1329,
      -1,    11,    -1,    10,  1330,   248,    -1,  1119,    -1,  1332,
    1333,  1334,    -1,   249,    -1,  1352,    -1,  1335,    -1,  1336,
      -1,    11,    -1,    10,  1337,   250,    -1,  1119,    -1,    -1,
    1338,  1339,    -1,  1340,  1341,  1344,    -1,   245,    -1,  1342,
      -1,    -1,  1342,  1343,    -1,  1369,    -1,  1370,    -1,  1413,
      -1,  1416,    -1,  1345,    -1,  1346,    -1,    11,    -1,    10,
    1347,   246,    -1,  1193,  1199,    -1,   201,     8,     6,     8,
      -1,   202,     8,     6,     8,    -1,   207,     8,     6,     8,
      -1,   206,     8,     6,     8,    -1,   158,     8,     6,     8,
      -1,   159,     8,     6,     8,    -1,   160,     8,     6,     8,
      -1,   217,     8,     6,     8,    -1,   210,     8,     6,     8,
      -1,   209,     8,     6,     8,    -1,   203,     8,     6,     8,
      -1,   205,     8,     6,     8,    -1,   213,     8,     6,     8,
      -1,   214,     8,     6,     8,    -1,   212,     8,     6,     8,
      -1,   234,     8,     6,     8,    -1,   218,     8,     6,     8,
      -1,   221,     8,     6,     8,    -1,   222,     8,     6,     8,
      -1,   223,     8,     6,     8,    -1,   224,     8,     6,     8,
      -1,   226,  1088,     6,  1088,    -1,   227,  1088,     6,  1088,
      -1,   235,     8,  1086,     8,    -1,   236,     8,  1086,     8,
      -1,   231,     8,     6,     8,    -1,   232,     8,     6,     8,
      -1,   228,  1088,     6,  1088,    -1,   233,     8,     6,     8,
      -1,   225,     8,  1086,     8,    -1,   219,     8,     6,     8,
      -1,   220,     8,     6,     8,    -1,  1381,    -1,  1382,    -1,
     199,    -1,   200,     3,  1088,    -1,  1384,    -1,  1385,    -1,
     161,    -1,   162,     3,     8,    -1,  1387,    -1,  1388,    -1,
     181,    -1,   182,     3,     8,    -1,  1390,    -1,  1391,    -1,
     163,    -1,   164,     3,     8,    -1,  1393,    -1,  1394,    -1,
     171,    -1,   172,     3,     8,    -1,  1396,    -1,  1397,    -1,
     191,    -1,   192,     3,     8,    -1,  1399,    -1,  1400,    -1,
     167,    -1,   168,     3,     8,    -1,  1402,    -1,  1403,    -1,
     183,    -1,   184,     3,     8,    -1,  1405,    -1,  1406,    -1,
     197,    -1,   198,     3,     8,    -1,  1408,    -1,  1409,    -1,
     173,    -1,   174,     3,     8,    -1,  1411,    -1,  1412,    -1,
     165,    -1,   166,     3,     8,    -1,  1414,    -1,  1415,    -1,
     195,    -1,   196,     3,     8,    -1,  1417,    -1,  1418,    -1,
     169,    -1,   170,     3,     8,    -1,  1420,    -1,  1421,    -1,
     175,    -1,   176,     3,     8,    -1,  1423,    -1,  1424,    -1,
     177,    -1,   178,     3,     8,    -1,  1426,    -1,  1427,    -1,
     179,    -1,   180,     3,     8,    -1,  1429,    -1,  1430,    -1,
     185,    -1,   186,     3,     8,    -1,  1475,    -1,  1482,    -1,
    1438,    -1,  1440,    -1,  1490,    -1,  1442,    -1,  1444,    -1,
    1446,    -1,  1448,    -1,  1502,    -1,  1450,    -1,  1452,    -1,
    1454,    -1,  1458,    -1,  1456,    -1,  1460,    -1,  1467,    -1,
    1462,    -1,  1465,    -1,  1496,    -1,  1499,    -1,  1432,    -1,
    1435,    -1,  1493,    -1,  1469,    -1,  1471,    -1,  1473,    -1,
      -1,   395,  1433,  1434,    -1,    11,    -1,    10,   396,    -1,
      -1,   397,  1436,  1437,    -1,    11,    -1,    10,   398,    -1,
      -1,   399,  1439,  1431,  1431,   400,    -1,    -1,   357,  1441,
    1431,  1431,   358,    -1,    -1,   359,  1443,  1431,  1431,   360,
      -1,    -1,   373,  1445,  1431,   374,    -1,    -1,   361,  1447,
    1431,  1431,   362,    -1,    -1,   355,  1449,  1431,  1431,   356,
      -1,    -1,   363,  1451,  1431,   364,    -1,    -1,   365,  1453,
    1431,   366,    -1,    -1,   377,  1455,  1431,   378,    -1,    -1,
     379,  1457,  1431,   380,    -1,    -1,   381,  1459,  1431,   382,
      -1,    -1,   371,  1461,  1431,   372,    -1,  1463,  1431,  1464,
      -1,   385,    -1,   386,    -1,    -1,   387,  1466,  1431,   388,
      -1,    -1,   375,  1468,  1431,  1431,  1431,   376,    -1,    -1,
     403,  1470,  1505,   404,    -1,    -1,   405,  1472,  1505,   406,
      -1,    -1,   407,  1474,  1505,   408,    -1,  1476,  1478,  1477,
      -1,   401,    -1,    11,    -1,    10,   402,    -1,    -1,  1478,
    1479,    -1,  1416,    -1,  1422,    -1,  1480,    -1,    -1,   444,
       3,  1481,     8,    -1,    -1,   383,  1483,  1486,  1484,    -1,
      11,    -1,    10,   384,    -1,    -1,    10,  1431,  1485,   384,
      -1,    -1,  1486,  1487,    -1,  1488,    -1,  1489,    -1,   235,
       8,  1086,     8,    -1,   231,     8,     6,     8,    -1,    -1,
     367,  1491,  1492,   368,    -1,    -1,  1492,  1431,    -1,    -1,
     391,  1494,  1495,   392,    -1,    -1,  1495,  1431,    -1,    -1,
     389,  1497,  1498,   390,    -1,    -1,  1498,  1431,    -1,    -1,
     393,  1500,  1501,   394,    -1,    -1,  1501,  1431,    -1,    -1,
     369,  1503,  1504,   370,    -1,    -1,  1504,  1431,    -1,  1506,
      -1,  1510,    -1,  1514,    -1,  1518,    -1,  1522,    -1,  1525,
      -1,  1531,    -1,  1534,    -1,  1538,    -1,  1543,    -1,  1546,
      -1,  1549,    -1,  1552,    -1,  1555,    -1,  1558,    -1,  1561,
      -1,  1564,    -1,  1567,    -1,  1528,    -1,  1507,  1509,  1508,
      -1,   435,    -1,    11,    -1,    10,   436,    -1,   231,     8,
       6,     8,    -1,  1511,  1513,  1512,    -1,   285,    -1,    11,
      -1,    10,   286,    -1,   231,     8,     6,     8,    -1,  1515,
    1517,  1516,    -1,   289,    -1,    11,    -1,    10,   290,    -1,
     231,     8,     6,     8,    -1,  1519,  1521,  1520,    -1,   293,
      -1,    11,    -1,    10,   294,    -1,   231,     8,     6,     8,
      -1,  1523,  1524,    -1,   409,    -1,  1505,   410,    -1,  1526,
    1527,    -1,   411,    -1,  1505,  1505,   412,    -1,  1529,  1530,
      -1,   437,    -1,  1431,   438,    -1,  1532,  1533,    -1,   439,
      -1,  1505,   440,    -1,  1535,  1536,    10,  1537,    -1,   413,
      -1,    -1,  1542,    -1,  1505,   414,    -1,  1539,  1540,    10,
    1541,    -1,   415,    -1,    -1,  1542,    -1,  1505,   416,    -1,
     442,     3,     8,    -1,  1544,  1545,    -1,   417,    -1,    11,
      -1,    10,   418,    -1,  1547,  1548,    -1,   419,    -1,  1505,
    1505,   420,    -1,  1550,  1551,    -1,   421,    -1,  1505,   422,
      -1,  1553,  1554,    -1,   423,    -1,  1505,  1505,   424,    -1,
    1556,  1557,    -1,   425,    -1,  1505,  1505,   426,    -1,    -1,
     427,  1559,  1560,   428,    -1,    -1,  1560,  1505,    -1,  1562,
    1563,    -1,   429,    -1,  1431,  1505,   430,    -1,  1565,  1566,
      -1,   431,    -1,  1431,  1431,  1431,  1431,  1505,   432,    -1,
    1568,  1569,    -1,   433,    -1,  1505,   434,    -1
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
    4427,  4429,  4580,  4582,  4587,  4587,  4589,  4591,  4593,  4596,
    4598,  4603,  4603,  4605,  4607,  4609,  4612,  4614,  4619,  4619,
    4621,  4623,  4625,  4628,  4630,  4635,  4635,  4637,  4639,  4641,
    4644,  4646,  4651,  4651,  4653,  4655,  4657,  4660,  4662,  4667,
    4667,  4669,  4671,  4673,  4676,  4678,  4683,  4683,  4685,  4687,
    4689,  4692,  4721,  4809,  4834,  4856,  4856,  4859,  4860,  4861,
    4862,  4863,  4864,  4995,  4995,  4997,  4999,  5028,  5030,  5030,
    5035,  5053,  5080,  5080,  5083,  5084,  5085,  5086,  5087,  5088,
    5089,  5090,  5091,  5094,  5094,  5096,  5096,  5101,  5101,  5101,
    5101,  5102,  5102,  5102,  5102,  5104,  5106,  5115,  5121,  5121,
    5124,  5130,  5136,  5138,  5138,  5144,  5154,  5164,  5164,  5166,
    5168,  5170,  5173,  5184,  5191,  5191,  5193,  5195,  5197,  5203,
    5213,  5220,  5220,  5222,  5224,  5226,  5229,  5231,  5240,  5246,
    5246,  5249,  5255,  5261,  5263,  5263,  5265,  5275,  5282,  5282,
    5284,  5286,  5288,  5290,  5292,  5301,  5307,  5307,  5310,  5316,
    5322,  5324,  5324,  5327,  5332,  5343,  5358,  5358,  5360,  5362,
    5364,  5366,  5366,  5368,  5375,  5382,  5395,  5395,  5398,  5399,
    5401,  5401,  5403,  5405,  5407,  5407,  5410,  5412,  5420,  5420,
    5425,  5432,  5434,  5443,  5449,  5449,  5452,  5458,  5465,  5467,
    5467,  5469,  5470,  5472,  5487,  5487,  5489,  5491,  5493,  5493,
    5495,  5497,  5512,  5512,  5514,  5516,  5526,  5528,  5537,  5543,
    5543,  5546,  5552,  5558,  5560,  5560,  5562,  5572,  5579,  5579,
    5581,  5583,  5585,  5588,  5590,  5599,  5605,  5605,  5608,  5614,
    5620,  5622,  5622,  5625,  5630,  5641,  5656,  5656,  5658,  5660,
    5662,  5662,  5664,  5672,  5684,  5684,  5687,  5688,  5689,  5707,
    5740,  5743,  5761,  5761,  5772,  5779,  5789,  5797,  5803,  5805,
    5819,  5831,  5837,  5843,  5843,  5845,  5847,  5849,  5851,  5861,
    5867,  5873,  5873,  5875,  5877,  5879,  5881,  5881,  5886,  5891,
    5903,  5905,  5905,  5908,  5909,  5910,  5918,  5925,  5925,  5927,
    5929,  5935,  5949,  5960,  5971,  5993,  6004,  6015,  6026,  6070,
    6094,  6116,  6127,  6138,  6149,  6160,  6171,  6184,  6195,  6209,
    6224,  6239,  6251,  6263,  6281,  6299,  6312,  6325,  6335,  6363,
    6372,  6383,  6393,  6405,  6419,  6419,  6421,  6431,  6447,  6447,
    6449,  6456,  6465,  6465,  6467,  6474,  6483,  6483,  6485,  6492,
    6501,  6501,  6503,  6510,  6575,  6575,  6577,  6584,  6593,  6593,
    6595,  6602,  6611,  6611,  6613,  6620,  6629,  6629,  6631,  6640,
    6654,  6654,  6656,  6663,  6672,  6672,  6674,  6681,  6690,  6690,
    6692,  6699,  6708,  6708,  6710,  6717,  6726,  6726,  6728,  6735,
    6744,  6744,  6748,  6756,  6765,  6765,  6767,  6774,  6783,  6783,
    6785,  6792,  6921,  6922,  6923,  6924,  6925,  6926,  6927,  6928,
    6929,  6930,  6931,  6932,  6933,  6934,  6935,  6936,  6937,  6938,
    6939,  6940,  6941,  6942,  6943,  6944,  6946,  6947,  6948,  6952,
    6952,  6955,  6956,  6958,  6958,  6961,  6962,  6966,  6966,  6971,
    6971,  6976,  6976,  6981,  6981,  6986,  6986,  6991,  6991,  6996,
    6996,  7001,  7001,  7006,  7006,  7011,  7011,  7016,  7016,  7021,
    7021,  7026,  7028,  7034,  7041,  7041,  7047,  7047,  7059,  7059,
    7064,  7064,  7069,  7069,  7079,  7086,  7092,  7093,  7095,  7096,
    7099,  7103,  7107,  7111,  7110,  7129,  7128,  7135,  7136,  7138,
    7137,  7144,  7145,  7148,  7154,  7162,  7169,  7187,  7187,  7198,
    7198,  7201,  7201,  7215,  7216,  7219,  7219,  7232,  7233,  7236,
    7236,  7249,  7250,  7253,  7253,  7263,  7264,  7270,  7271,  7272,
    7273,  7274,  7275,  7276,  7277,  7278,  7279,  7280,  7281,  7282,
    7283,  7284,  7285,  7286,  7287,  7288,  7291,  7296,  7303,  7304,
    7306,  7314,  7319,  7326,  7327,  7329,  7336,  7341,  7348,  7349,
    7351,  7358,  7363,  7370,  7371,  7373,  7380,  7382,  7388,  7390,
    7392,  7398,  7400,  7402,  7408,  7410,  7412,  7418,  7420,  7422,
    7428,  7428,  7433,  7435,  7437,  7443,  7443,  7448,  7450,  7459,
    7461,  7466,  7466,  7468,  7470,  7476,  7479,  7481,  7487,  7490,
    7492,  7498,  7501,  7503,  7509,  7513,  7512,  7524,  7524,  7531,
    7533,  7539,  7541,  7543,  7549,  7552,  7554,  7560
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
  "BLOCKCOLIDXATT", "MATRIXVARIDXATT", "MATRIXOBJIDXATT",
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
  "osglDblVectorBase64Laden", "osglBasisStatusBasic", "osglBasicStart",
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
  "matrixVarLaden", "matrixBody", "baseMatrix", "baseMatrixStart",
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
  "linearElementsValuesVarIdxStart", "LinearElementsValuesVarIdxCoefATT",
  "linearElementsValuesVarIdxContent", "realValuedExpressions",
  "realValuedExpressionsStart", "realValuedExpressionsAttributes",
  "realValuedExpressionsAttList", "realValuedExpressionsAtt",
  "realValuedExpressionsContent", "realValuedExpressionsNonzeros",
  "realValuedExpressionsValues", "realValuedExpressionsValuesStart",
  "realValuedExpressionsValuesContent", "realValuedExpressionsValuesEmpty",
  "realValuedExpressionsValuesLaden", "realValuedExpressionsElList",
  "realValuedExpressionsEl", "realValuedExpressionsElStart",
  "realValuedExpressionsElContent", "realValuedExpressionsElEmpty",
  "realValuedExpressionsElLaden", "objReferenceElements",
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
  "blockBody", "osglNumberOfBlocksATT", "osglNumberOfColumnsATT",
  "osglNumberOfConATT", "osglNumberOfConstraintsATT", "osglNumberOfElATT",
  "osglNumberOfEnumerationsATT", "osglNumberOfItemsATT",
  "osglNumberOfMatrixVarATT", "osglNumberOfObjATT",
  "osglNumberOfObjectivesATT", "osglNumberOfRowsATT",
  "osglNumberOfValuesATT", "osglNumberOfVarATT", "osglNumberOfVarIdxATT",
  "osglNumberOfVariablesATT", "osglBase64SizeATT", "osglBaseMatrixIdxATT",
  "osglBaseMatrixStartRowATT", "osglBaseMatrixStartColATT",
  "osglBaseMatrixEndRowATT", "osglBaseMatrixEndColATT",
  "osglBlockRowIdxATT", "osglBlockColIdxATT", "osglCoefATT",
  "osglConstantATT", "osglIdxATT", "osglIncrATT", "osglMatrixVarIdxATT",
  "osglMultATT", "osglScalarMultiplierATT", "osglTargetMatrixFirstRowATT",
  "osglTargetMatrixFirstColATT", "osglBaseTransposeATT",
  "baseTransposeAttEmpty", "baseTransposeAttContent", "osglCategoryATT",
  "categoryAttEmpty", "categoryAttContent", "osglConTypeATT",
  "conTypeAttEmpty", "conTypeAttContent", "osglDescriptionATT",
  "descriptionAttEmpty", "descriptionAttContent", "osglEnumTypeATT",
  "enumTypeAttEmpty", "enumTypeAttContent", "osglMatrixVarTypeATT",
  "matrixVarTypeAttEmpty", "matrixVarTypeAttContent", "osglNameATT",
  "nameAttEmpty", "nameAttContent", "osglObjTypeATT", "objTypeAttEmpty",
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
     695,   696,   697,   698,   699,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   449,   450,   450,   451,   452,   453,   453,   454,   454,
     455,   456,   457,   458,   458,   459,   460,   460,   461,   461,
     462,   463,   463,   464,   464,   465,   466,   467,   467,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   469,   470,
     471,   472,   472,   473,   473,   473,   474,   474,   475,   475,
     476,   477,   478,   478,   479,   480,   481,   482,   482,   483,
     483,   484,   484,   485,   486,   487,   487,   488,   488,   489,
     490,   491,   492,   493,   493,   494,   494,   495,   496,   497,
     498,   499,   499,   500,   500,   501,   502,   503,   504,   505,
     505,   506,   506,   507,   508,   509,   510,   511,   511,   512,
     512,   513,   514,   515,   516,   517,   517,   518,   518,   519,
     520,   521,   522,   523,   523,   524,   524,   525,   526,   527,
     528,   529,   530,   530,   531,   531,   532,   533,   534,   534,
     535,   536,   537,   538,   538,   539,   539,   539,   540,   540,
     541,   541,   542,   543,   543,   544,   544,   545,   546,   547,
     547,   548,   548,   548,   548,   548,   548,   549,   550,   551,
     551,   552,   552,   553,   554,   555,   556,   557,   558,   558,
     559,   559,   560,   561,   562,   563,   564,   565,   565,   566,
     566,   567,   568,   569,   570,   571,   572,   572,   573,   573,
     574,   575,   576,   577,   578,   578,   579,   580,   581,   582,
     583,   584,   584,   585,   585,   586,   587,   588,   588,   589,
     590,   591,   592,   592,   593,   593,   593,   594,   594,   595,
     595,   596,   597,   597,   598,   598,   599,   600,   601,   601,
     602,   602,   602,   602,   602,   602,   603,   604,   605,   605,
     606,   606,   607,   608,   609,   610,   611,   611,   612,   612,
     613,   614,   615,   616,   617,   617,   618,   618,   619,   620,
     621,   622,   623,   623,   624,   624,   625,   626,   627,   628,
     629,   629,   630,   630,   631,   632,   633,   634,   635,   636,
     636,   637,   637,   638,   639,   640,   640,   641,   642,   643,
     644,   644,   645,   645,   645,   646,   646,   647,   647,   648,
     649,   649,   650,   650,   651,   652,   653,   653,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   655,
     656,   657,   657,   658,   658,   659,   660,   661,   662,   663,
     663,   664,   664,   665,   666,   667,   668,   669,   669,   670,
     670,   671,   672,   673,   674,   675,   675,   676,   676,   677,
     678,   679,   680,   681,   681,   682,   682,   683,   684,   685,
     686,   687,   688,   688,   689,   689,   690,   691,   692,   692,
     693,   694,   695,   695,   696,   696,   696,   696,   697,   697,
     698,   698,   699,   700,   701,   701,   702,   703,   704,   705,
     705,   706,   706,   707,   708,   709,   710,   711,   712,   712,
     713,   713,   714,   715,   716,   717,   718,   719,   719,   720,
     720,   721,   722,   723,   724,   725,   725,   726,   727,   728,
     729,   730,   731,   731,   732,   732,   733,   734,   735,   735,
     736,   737,   738,   739,   739,   740,   740,   740,   741,   741,
     742,   742,   743,   744,   745,   745,   746,   746,   746,   746,
     747,   747,   748,   748,   749,   750,   751,   751,   752,   753,
     754,   755,   755,   756,   756,   756,   757,   758,   759,   760,
     761,   762,   763,   764,   764,   765,   765,   765,   766,   766,
     767,   767,   768,   769,   770,   770,   771,   772,   773,   774,
     774,   775,   775,   776,   776,   777,   777,   778,   779,   779,
     780,   780,   781,   782,   783,   783,   784,   785,   785,   786,
     786,   787,   788,   789,   790,   790,   791,   792,   793,   793,
     794,   794,   795,   796,   797,   797,   798,   799,   800,   800,
     801,   801,   802,   803,   803,   804,   805,   806,   806,   807,
     807,   808,   809,   810,   810,   811,   812,   813,   813,   814,
     814,   815,   815,   816,   816,   817,   818,   819,   819,   820,
     821,   821,   822,   823,   824,   825,   825,   826,   826,   827,
     827,   828,   828,   829,   829,   830,   830,   831,   831,   832,
     832,   833,   834,   835,   836,   836,   837,   837,   837,   837,
     837,   837,   837,   837,   837,   838,   838,   839,   839,   840,
     841,   841,   842,   842,   843,   844,   845,   845,   846,   846,
     847,   847,   848,   848,   849,   850,   851,   851,   852,   853,
     854,   855,   855,   856,   856,   856,   857,   857,   858,   859,
     860,   861,   861,   862,   863,   863,   864,   864,   865,   866,
     867,   868,   868,   869,   870,   871,   871,   872,   872,   873,
     874,   875,   875,   876,   877,   878,   878,   879,   879,   880,
     881,   881,   882,   883,   883,   884,   885,   886,   887,   887,
     888,   888,   889,   889,   890,   890,   891,   891,   892,   892,
     893,   893,   894,   894,   895,   896,   897,   898,   898,   899,
     899,   899,   899,   899,   899,   899,   899,   899,   900,   900,
     901,   901,   902,   903,   903,   904,   904,   905,   906,   907,
     907,   908,   908,   909,   909,   910,   910,   911,   912,   913,
     913,   914,   915,   916,   917,   917,   918,   918,   918,   919,
     919,   920,   921,   922,   923,   923,   924,   925,   925,   926,
     926,   927,   928,   929,   930,   930,   931,   932,   933,   933,
     934,   934,   935,   936,   937,   937,   938,   939,   940,   940,
     941,   941,   942,   943,   943,   944,   945,   945,   946,   947,
     948,   949,   949,   950,   950,   951,   951,   952,   952,   953,
     953,   954,   954,   955,   955,   956,   956,   957,   958,   959,
     960,   960,   961,   961,   961,   961,   961,   961,   961,   961,
     961,   962,   962,   963,   963,   964,   965,   965,   966,   966,
     967,   968,   969,   969,   970,   970,   971,   971,   972,   972,
     973,   974,   975,   975,   976,   977,   978,   979,   979,   980,
     980,   980,   981,   981,   982,   983,   984,   985,   985,   986,
     987,   987,   988,   988,   989,   990,   991,   991,   992,   993,
     994,   994,   995,   996,   997,   998,   998,   999,  1000,  1001,
    1001,  1002,  1003,  1004,  1005,  1005,  1006,  1006,  1007,  1008,
    1009,  1010,  1010,  1011,  1011,  1011,  1011,  1011,  1011,  1011,
    1011,  1011,  1012,  1012,  1013,  1013,  1014,  1015,  1015,  1016,
    1016,  1017,  1017,  1018,  1019,  1020,  1021,  1021,  1022,  1022,
    1022,  1023,  1023,  1024,  1025,  1026,  1027,  1027,  1028,  1029,
    1029,  1030,  1031,  1032,  1032,  1033,  1033,  1034,  1035,  1036,
    1036,  1037,  1038,  1039,  1040,  1040,  1041,  1041,  1041,  1041,
    1041,  1042,  1042,  1043,  1043,  1044,  1045,  1046,  1046,  1047,
    1048,  1048,  1049,  1049,  1050,  1051,  1052,  1052,  1053,  1054,
    1055,  1055,  1056,  1056,  1057,  1058,  1059,  1059,  1060,  1061,
    1062,  1063,  1063,  1064,  1064,  1064,  1064,  1065,  1065,  1066,
    1066,  1067,  1068,  1069,  1069,  1070,  1071,  1071,  1072,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1086,  1087,  1087,  1087,  1088,  1089,
    1089,  1090,  1090,  1090,  1090,  1091,  1092,  1093,  1093,  1094,
    1095,  1096,  1097,  1097,  1098,  1098,  1098,  1098,  1098,  1099,
    1100,  1100,  1101,  1101,  1102,  1103,  1104,  1104,  1105,  1105,
    1106,  1107,  1108,  1108,  1109,  1109,  1110,  1111,  1112,  1112,
    1113,  1113,  1114,  1115,  1116,  1116,  1117,  1117,  1118,  1119,
    1119,  1120,  1120,  1121,  1122,  1123,  1124,  1124,  1125,  1125,
    1126,  1127,  1128,  1128,  1129,  1129,  1130,  1131,  1131,  1132,
    1132,  1133,  1134,  1135,  1135,  1136,  1137,  1138,  1138,  1139,
    1139,  1140,  1141,  1142,  1143,  1143,  1144,  1145,  1146,  1147,
    1148,  1149,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1187,  1188,  1188,  1188,
    1188,  1188,  1188,  1189,  1189,  1190,  1191,  1192,  1193,  1193,
    1194,  1195,  1196,  1196,  1197,  1197,  1197,  1197,  1197,  1197,
    1197,  1197,  1197,  1198,  1198,  1199,  1199,  1200,  1200,  1200,
    1200,  1200,  1200,  1200,  1200,  1201,  1202,  1203,  1204,  1204,
    1205,  1205,  1206,  1207,  1207,  1208,  1209,  1210,  1210,  1211,
    1212,  1213,  1214,  1215,  1216,  1216,  1217,  1218,  1219,  1220,
    1221,  1222,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1229,
    1229,  1230,  1230,  1231,  1232,  1232,  1233,  1234,  1235,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1242,  1243,  1243,
    1244,  1245,  1245,  1246,  1246,  1247,  1248,  1248,  1249,  1250,
    1251,  1252,  1252,  1253,  1254,  1255,  1256,  1256,  1257,  1257,
    1258,  1258,  1259,  1260,  1261,  1261,  1262,  1263,  1264,  1264,
    1265,  1266,  1267,  1268,  1269,  1269,  1270,  1270,  1271,  1272,
    1272,  1273,  1273,  1274,  1275,  1275,  1276,  1277,  1278,  1278,
    1279,  1280,  1281,  1281,  1282,  1283,  1284,  1285,  1286,  1287,
    1287,  1288,  1288,  1289,  1290,  1290,  1291,  1292,  1293,  1293,
    1294,  1295,  1296,  1297,  1298,  1299,  1300,  1300,  1301,  1301,
    1302,  1303,  1303,  1304,  1304,  1305,  1306,  1306,  1307,  1308,
    1309,  1309,  1310,  1311,  1312,  1312,  1313,  1313,  1313,  1314,
    1315,  1316,  1317,  1317,  1318,  1319,  1320,  1321,  1322,  1323,
    1324,  1325,  1326,  1327,  1327,  1328,  1329,  1330,  1331,  1332,
    1333,  1334,  1334,  1335,  1336,  1337,  1338,  1338,  1339,  1340,
    1341,  1342,  1342,  1343,  1343,  1343,  1343,  1344,  1344,  1345,
    1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,
    1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,
    1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,  1375,
    1376,  1377,  1378,  1379,  1380,  1380,  1381,  1382,  1383,  1383,
    1384,  1385,  1386,  1386,  1387,  1388,  1389,  1389,  1390,  1391,
    1392,  1392,  1393,  1394,  1395,  1395,  1396,  1397,  1398,  1398,
    1399,  1400,  1401,  1401,  1402,  1403,  1404,  1404,  1405,  1406,
    1407,  1407,  1408,  1409,  1410,  1410,  1411,  1412,  1413,  1413,
    1414,  1415,  1416,  1416,  1417,  1418,  1419,  1419,  1420,  1421,
    1422,  1422,  1423,  1424,  1425,  1425,  1426,  1427,  1428,  1428,
    1429,  1430,  1431,  1431,  1431,  1431,  1431,  1431,  1431,  1431,
    1431,  1431,  1431,  1431,  1431,  1431,  1431,  1431,  1431,  1431,
    1431,  1431,  1431,  1431,  1431,  1431,  1431,  1431,  1431,  1433,
    1432,  1434,  1434,  1436,  1435,  1437,  1437,  1439,  1438,  1441,
    1440,  1443,  1442,  1445,  1444,  1447,  1446,  1449,  1448,  1451,
    1450,  1453,  1452,  1455,  1454,  1457,  1456,  1459,  1458,  1461,
    1460,  1462,  1463,  1464,  1466,  1465,  1468,  1467,  1470,  1469,
    1472,  1471,  1474,  1473,  1475,  1476,  1477,  1477,  1478,  1478,
    1479,  1479,  1479,  1481,  1480,  1483,  1482,  1484,  1484,  1485,
    1484,  1486,  1486,  1487,  1487,  1488,  1489,  1491,  1490,  1492,
    1492,  1494,  1493,  1495,  1495,  1497,  1496,  1498,  1498,  1500,
    1499,  1501,  1501,  1503,  1502,  1504,  1504,  1505,  1505,  1505,
    1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,  1505,
    1505,  1505,  1505,  1505,  1505,  1505,  1506,  1507,  1508,  1508,
    1509,  1510,  1511,  1512,  1512,  1513,  1514,  1515,  1516,  1516,
    1517,  1518,  1519,  1520,  1520,  1521,  1522,  1523,  1524,  1525,
    1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,
    1536,  1536,  1537,  1538,  1539,  1540,  1540,  1541,  1542,  1543,
    1544,  1545,  1545,  1546,  1547,  1548,  1549,  1550,  1551,  1552,
    1553,  1554,  1555,  1556,  1557,  1559,  1558,  1560,  1560,  1561,
    1562,  1563,  1564,  1565,  1566,  1567,  1568,  1569
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
       1,     3,     3,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     0,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     0,     2,
       1,     1,     3,     0,     2,     2,     1,     1,     1,     1,
       3,     1,     2,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     3,     1,     4,     1,     1,     0,
       2,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     3,     1,     4,     1,     1,     0,     2,     1,     1,
       3,     0,     2,     0,     2,     1,     1,     1,     1,     3,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     3,     0,     2,     3,     1,     0,     1,
       3,     4,     1,     1,     0,     2,     1,     1,     3,     0,
       2,     0,     2,     1,     1,     1,     1,     3,     0,     2,
       2,     1,     1,     1,     1,     3,     4,     1,     1,     0,
       2,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     3,     1,     4,     1,     1,     0,     2,     1,     1,
       3,     0,     2,     0,     2,     1,     1,     1,     1,     3,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     3,
       5,     1,     0,     1,     1,     3,     1,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     0,     3,     1,     2,     0,     5,     0,
       5,     0,     5,     0,     4,     0,     5,     0,     5,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     3,     1,     1,     0,     4,     0,     6,     0,     4,
       0,     4,     0,     4,     3,     1,     1,     2,     0,     2,
       1,     1,     1,     0,     4,     0,     4,     1,     2,     0,
       4,     0,     2,     1,     1,     4,     4,     0,     4,     0,
       2,     0,     4,     0,     2,     0,     4,     0,     2,     0,
       4,     0,     2,     0,     4,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     2,
       4,     3,     1,     1,     2,     4,     3,     1,     1,     2,
       4,     3,     1,     1,     2,     4,     2,     1,     2,     2,
       1,     3,     2,     1,     2,     2,     1,     2,     4,     1,
       0,     1,     2,     4,     1,     0,     1,     2,     3,     2,
       1,     1,     2,     2,     1,     3,     2,     1,     2,     2,
       1,     3,     2,     1,     3,     0,     4,     0,     2,     2,
       1,     3,     2,     1,     6,     2,     1,     2
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
     999,  1418,     0,  1454,     0,     0,    40,    41,    45,    44,
    1416,  1417,    43,  1452,  1453,     0,    68,    63,    65,    66,
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
    1458,     0,   169,   171,   170,  1456,  1457,     0,   174,   178,
     180,   179,     0,   183,   187,   189,   188,     0,   192,     0,
     204,   198,   201,   202,   999,   998,  1001,  1002,  1003,  1004,
    1000,  1419,  1455,    48,    55,     0,    51,    52,    57,    69,
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
    1459,   181,   190,   196,   205,   208,     0,   211,     0,    62,
      54,  1430,     0,    58,    60,    59,  1428,  1429,     0,   139,
     130,  1462,     0,   134,   137,   135,   136,  1460,  1461,   454,
     948,   457,   455,     0,     0,   460,   999,     0,     0,     0,
     325,   333,   341,   349,   357,   999,   371,   364,     0,   367,
     368,   372,     0,   394,     0,   403,     0,   412,   418,     0,
     424,   431,     0,   427,   428,   433,   283,   286,     0,   289,
       0,   218,   209,   213,   216,   214,   215,    61,     0,   138,
       0,   999,     0,   949,     0,   458,     0,     0,   999,   462,
     463,   464,   465,   989,  1375,  1381,  1386,   992,   366,   369,
       0,   393,   402,   411,   417,   426,   429,     0,   432,     0,
     296,   287,   291,   294,   292,   293,   217,  1431,  1463,     0,
       0,   953,   947,   950,   951,   471,   495,     0,   999,   999,
       0,     0,   381,  1410,     0,   373,   370,   378,   379,   376,
    1408,  1409,   377,   375,   374,     0,   439,   430,   434,   437,
     435,   436,   295,   999,   952,   959,     0,   955,   956,   961,
     497,   504,     0,     0,   472,   473,   477,   476,   475,   468,
     467,   999,   385,   384,   380,     0,   383,     0,   438,   990,
     954,   957,     0,   960,   506,   631,   507,     0,   501,   496,
     498,   499,     0,   481,   470,   478,   479,   474,   466,   382,
    1411,     0,   970,   958,   967,   968,     0,   962,   966,   964,
     965,   963,   633,   734,   634,   999,     0,   508,   503,   500,
       0,   480,   487,     0,   483,   484,   489,   969,   979,     0,
     978,     0,   972,   973,   975,   976,   977,     0,   736,   837,
     737,   999,     0,   635,     0,   514,   511,   505,   509,   510,
     502,   482,   485,     0,   488,   981,     0,   971,   974,     0,
     839,   909,   840,   999,     0,   738,     0,   641,   638,   632,
     636,   637,   999,   516,     0,   533,     0,     0,   494,   486,
     490,   492,   491,   980,  1378,   911,     0,     0,   999,     0,
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
    1083,     0,   670,   669,     0,     0,   647,   654,     0,   650,
     651,   655,   582,   580,   584,     0,   567,   566,   539,   546,
       0,   542,   543,   547,  1384,   522,   525,     0,   987,   917,
     920,     0,   923,   908,   845,   907,     0,   855,   852,   847,
     850,   851,   788,   786,   790,     0,   773,   772,     0,   750,
     757,     0,   753,   754,   758,     0,   686,   666,  1090,   672,
     671,     0,     0,     0,  1131,  1380,   649,   652,     0,     0,
     583,   563,   569,   568,   541,   544,     0,     0,     0,   529,
     526,   530,   531,     0,   934,   921,   931,   932,   925,   930,
     928,   929,   926,   927,   999,   857,   866,     0,     0,   789,
     769,   775,   774,  1374,   752,   755,     0,     0,   701,   684,
     698,   699,     0,  1446,     0,  1422,     0,  1434,     0,   688,
     690,   689,   697,   696,  1420,  1421,   693,   695,  1432,  1433,
     692,  1444,  1445,   694,   691,  1097,   674,   673,     0,     0,
       0,  1051,  1086,  1082,  1084,  1085,     0,   656,   653,   657,
     658,     0,   598,   581,   595,   596,  1470,     0,   585,   587,
     586,   594,   593,   590,   589,   591,   588,   592,  1468,  1469,
     571,   570,     0,   554,   548,   545,   551,   552,   549,   550,
       0,     0,   933,   943,     0,   942,     0,   936,   937,   939,
     940,   941,   984,     0,     0,     0,   858,     0,   804,   787,
     801,   802,  1414,     0,   791,   792,   793,   798,  1412,  1413,
     800,   799,   796,   795,   797,   794,   777,   776,     0,   759,
     756,   760,   761,   722,   708,   700,     0,   703,   705,   709,
     704,   719,   724,     0,     0,     0,     0,  1104,   676,   675,
       0,     0,  1051,  1093,  1089,  1091,  1092,     0,     0,  1088,
    1049,  1050,     0,     0,   619,   605,   597,     0,   600,   602,
     606,   601,   616,   621,     0,   573,   572,   556,   553,     0,
     532,     0,   945,     0,   935,   938,   854,   869,   853,   867,
     871,     0,   864,   861,   856,   859,   860,   825,   811,   803,
       0,   806,   808,   812,   807,   822,   827,     0,   779,   778,
       0,   702,   706,     0,   720,     0,   723,     0,  1447,  1423,
    1435,  1111,   678,   677,     0,     0,  1051,  1100,  1096,  1098,
    1099,  1095,     0,  1376,     0,     0,  1054,  1052,  1056,  1087,
     659,   599,   603,     0,   617,     0,   620,  1471,   575,   574,
     555,  1397,   944,     0,   870,     0,     0,   805,   809,     0,
     823,     0,   826,  1415,   781,   780,   762,     0,   716,   710,
     707,   713,   714,   711,   712,  1051,   731,   721,   729,   730,
     725,   726,   728,   727,  1377,  1118,   680,   679,     0,     0,
    1051,  1107,  1103,  1105,  1106,  1102,     0,  1094,     0,     0,
    1065,  1061,  1062,  1063,     0,  1055,     0,   613,   607,   604,
     610,   611,   608,   609,  1051,   628,   618,   626,   627,   622,
     623,   625,   624,   577,   576,     0,   885,   868,   882,   883,
    1426,     0,   872,   874,   873,   881,   880,   879,  1424,  1425,
     877,   876,   878,   875,  1379,   863,  1133,   862,   865,  1135,
       0,   819,   813,   810,   816,   817,   814,   815,  1051,   834,
     824,   832,   833,   828,   829,   831,   830,   783,   782,   995,
     996,   997,   715,     0,   718,     0,   733,  1125,   667,   681,
       0,     0,  1051,  1114,  1110,  1112,  1113,  1109,     0,  1101,
       0,     0,  1064,     0,  1053,     0,     0,  1057,  1059,  1058,
     612,     0,   615,     0,   630,   564,   578,   894,   884,     0,
     888,   887,   891,   896,   889,     0,     0,  1134,   818,     0,
     821,     0,   836,   770,   784,   717,   732,     0,  1051,  1121,
    1117,  1119,  1120,  1116,     0,  1108,  1387,  1066,     0,     0,
       0,   614,   629,   886,   890,   892,     0,   895,  1427,  1148,
    1145,  1132,  1143,  1144,  1450,     0,     0,     0,   999,  1136,
    1139,  1138,  1142,  1140,  1137,  1448,  1449,  1141,   820,   835,
    1051,  1128,  1124,  1126,  1127,  1123,     0,  1115,  1060,     0,
       0,  1051,   903,   893,   901,   902,   897,   898,   900,   899,
    1150,     0,  1165,  1152,     0,     0,     0,     0,  1130,     0,
    1122,  1398,  1400,     0,   905,  1146,  1147,     0,  1151,  1451,
       0,     0,   999,  1129,   904,  1336,  1176,  1207,  1224,  1304,
    1287,  1262,  1331,  1166,  1167,  1178,  1168,  1209,  1169,  1226,
    1170,  1264,  1171,  1289,  1172,  1306,  1173,  1332,  1174,     0,
       0,  1164,  1149,  1406,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1153,  1154,  1157,  1158,  1159,  1160,  1162,
    1155,  1156,  1161,  1404,  1405,  1373,  1382,  1399,     0,  1177,
       0,  1208,     0,  1225,     0,  1263,     0,  1288,     0,  1305,
    1442,     0,     0,  1333,  1440,  1441,     0,     0,  1337,  1163,
     999,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1438,     0,     0,  1179,  1180,  1181,  1436,  1437,     0,  1210,
    1211,  1212,     0,  1227,  1228,  1229,     0,  1265,  1266,  1267,
       0,  1290,  1291,  1292,     0,  1307,  1308,  1309,     0,     0,
       0,     0,  1335,  1407,     0,     0,     0,     0,     0,     0,
       0,     0,  1186,  1175,  1183,     0,     0,     0,  1214,  1206,
    1231,  1223,  1269,  1261,  1294,  1286,  1311,  1303,  1443,  1612,
    1617,  1622,  1627,  1630,  1639,  1644,  1650,  1654,  1657,  1660,
    1663,  1665,  1670,  1673,  1676,  1607,  1633,  1636,     0,  1587,
       0,  1588,     0,  1589,     0,  1590,     0,  1591,     0,  1592,
       0,  1605,     0,  1593,     0,  1594,  1640,  1595,  1645,  1596,
       0,  1597,     0,  1598,     0,  1599,     0,  1600,     0,  1601,
    1602,     0,  1603,     0,  1604,     0,     0,  1341,     0,     0,
    1388,  1402,  1403,  1389,  1390,  1391,  1392,  1401,  1193,     0,
       0,     0,  1051,  1189,  1185,  1187,  1188,  1439,     0,     0,
       0,  1233,     0,  1271,     0,     0,     0,  1313,     0,  1667,
    1334,  1330,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1626,     0,  1629,  1517,  1509,  1511,  1515,  1519,  1521,
    1567,  1583,  1529,  1513,  1536,  1523,  1525,  1527,  1555,  1532,
    1534,  1575,  1571,  1579,  1499,  1503,  1507,  1545,  1538,  1540,
    1542,     0,  1493,  1494,  1474,  1475,  1477,  1478,  1479,  1480,
    1482,  1483,  1484,  1486,  1485,  1487,  1489,     0,  1490,  1488,
    1496,  1497,  1498,  1472,  1548,  1473,  1476,  1495,  1491,  1492,
    1481,  1632,     0,  1635,     0,     0,  1641,     0,  1646,     0,
    1651,  1649,     0,  1653,     0,  1656,     0,  1659,     0,  1662,
       0,  1669,     0,  1672,     0,  1675,  1372,  1349,  1356,     0,
       0,  1342,  1182,  1200,  1184,     0,  1051,  1196,  1192,  1194,
    1195,  1191,     0,  1383,  1217,  1215,     0,  1213,  1235,  1232,
       0,  1230,  1273,  1270,     0,  1268,  1297,  1295,     0,  1293,
    1315,  1312,     0,  1310,     0,     0,     0,  1608,  1606,     0,
       0,  1613,  1611,     0,     0,  1618,  1616,     0,     0,  1623,
    1621,  1628,     0,     0,     0,     0,     0,     0,     0,  1569,
    1585,     0,     0,     0,     0,     0,     0,  1561,     0,  1577,
    1573,  1581,     0,     0,     0,     0,     0,     0,  1634,     0,
       0,  1637,     0,     0,     0,  1652,     0,  1658,     0,     0,
       0,     0,  1677,     0,     0,  1350,  1051,  1345,  1340,  1343,
    1344,  1069,  1203,  1199,  1201,  1202,  1198,     0,  1190,  1051,
    1220,  1216,  1218,  1219,  1241,  1238,  1234,  1236,  1237,  1278,
    1276,  1272,  1274,  1275,  1051,  1300,  1296,  1298,  1299,  1320,
    1318,  1314,  1316,  1317,  1666,  1668,     0,  1609,     0,  1614,
       0,  1619,     0,  1624,  1631,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1501,  1500,     0,  1505,  1504,
       0,     0,     0,     0,  1533,  1531,     0,  1546,     0,  1550,
    1551,  1544,  1549,  1552,  1648,     0,  1638,     0,  1643,  1655,
    1661,  1664,  1671,     0,  1339,  1359,  1338,  1357,  1361,  1051,
    1353,  1348,  1351,  1352,  1347,     0,     0,  1205,  1067,  1068,
       0,  1197,  1222,     0,     0,  1240,     0,  1302,     0,     0,
    1610,  1615,  1620,  1625,     0,     0,     0,     0,  1520,  1522,
    1568,  1570,  1584,  1586,  1530,  1514,     0,  1524,  1526,  1528,
       0,  1557,     0,     0,  1556,  1562,  1563,  1564,  1535,  1576,
    1578,  1572,  1574,  1580,  1582,  1502,  1506,     0,  1539,  1541,
    1543,  1547,  1553,  1642,  1647,     0,     0,  1360,  1355,     0,
    1346,     0,  1072,  1070,  1073,  1204,  1221,  1239,  1244,  1242,
    1246,  1281,  1277,  1279,     0,  1301,  1323,  1319,  1321,  1324,
    1518,  1510,  1512,  1516,     0,  1558,  1559,     0,     0,  1508,
       0,     0,  1148,  1369,  1358,  1367,  1368,   999,   999,  1362,
    1363,  1364,  1365,  1366,  1354,     0,  1080,  1076,  1077,  1078,
       0,  1074,     0,  1245,     0,  1284,  1280,  1282,  1283,     0,
    1537,     0,     0,     0,  1554,  1674,  1165,     0,     0,     0,
       0,  1079,     0,  1071,  1254,  1252,  1243,  1250,  1251,     0,
       0,  1247,  1248,  1249,     0,     0,  1466,     0,  1325,  1322,
    1328,  1327,  1326,  1464,  1465,  1560,  1566,  1565,  1371,  1370,
     999,   999,  1081,     0,     0,     0,     0,  1285,     0,     0,
    1393,  1394,  1075,  1253,  1257,  1255,  1258,     0,     0,  1329,
    1467,     0,     0,  1259,  1385,  1396,     0,     0,  1256,     0,
       0,  1395,  1260
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
    1402,  1403,  2157,  2158,  2223,  2224,  2270,  2293,  2159,  2267,
    2268,  2269,  1013,  1014,  1153,  1154,  1155,  1262,  1070,  1071,
    1254,  1255,  1256,  1332,  1147,  1148,  1328,  1329,  1330,  1396,
    1249,  1250,  1392,  1393,  1394,  1488,  1323,  1324,  1484,  1485,
    1486,  1534,  1387,  1388,  1530,  1531,  1532,  1576,  1479,  1480,
    1572,  1573,  1574,  1599,  1073,  1448,  1449,  1516,  1517,  1559,
    1551,  1552,  1553,  1591,  1592,  1593,  1607,  1608,  1653,  1642,
    1606,  1623,  1624,  1625,  1668,  1669,  1703,  1743,  1829,  1744,
    1745,  1834,  1835,  1836,  1962,  1830,  1831,  1958,  1959,  1960,
    2057,  1954,  1955,  2053,  2054,  2055,  2160,  1626,  1627,  1670,
    1671,  1709,  1749,  1840,  1965,  1966,  2061,  2062,  2063,  2163,
    1628,  1629,  1672,  1673,  1713,  1751,  1842,  1969,  1970,  2066,
    2067,  2068,  2164,  2165,  2229,  2230,  2272,  2273,  2301,  2296,
    2297,  2298,  2324,  2335,  2336,  2342,  2348,  1630,  1631,  1674,
    1675,  1717,  1753,  1844,  1973,  1974,  2071,  2072,  2073,  2166,
    2233,  2234,  2276,  2277,  2278,  1632,  1633,  1676,  1677,  1721,
    1755,  1846,  1977,  1978,  2076,  2077,  2078,  2168,  1634,  1635,
    1678,  1679,  1725,  1757,  1848,  1981,  1982,  2081,  2082,  2083,
    2169,  2238,  2239,  2279,  2308,  2309,  1636,  1637,  1682,  1851,
    1638,  1639,  1687,  1732,  2146,  1818,  1819,  1950,  2048,  2049,
    2050,  2155,  1948,  1949,  2044,  2151,  2152,  2153,  2219,  2043,
    2147,  2148,  2216,  2217,  2259,  2254,  2255,  2256,  2287,  1688,
    1560,   952,   434,  1074,  1130,   798,  1206,   923,   435,  1561,
    1704,   899,  2302,   436,  1335,  1654,  1655,  1656,  1657,  1658,
    2260,  2261,  2343,  2303,  1091,  1498,  1562,  1499,  1659,  1660,
    1661,  1662,  1663,  1664,   729,   730,   731,  1217,  1218,  1219,
     159,   160,   161,  1133,  1134,  1135,  1437,  1438,  1439,   605,
     606,   607,  1137,  1138,  1139,  1705,  1706,  1707,  1683,  1684,
    1685,  1140,  1141,  1142,  1564,  1565,  1566,   162,   163,   164,
     374,   375,   376,   616,   617,   618,  2312,  2313,  2314,  1177,
    1178,  1179,  1891,  1892,  2022,  2116,  1893,  2023,  2119,  1894,
    2024,  1895,  2004,  1896,  2005,  1897,  2012,  1898,  2006,  1899,
    2003,  1900,  2007,  1901,  2008,  1902,  2014,  1903,  2015,  1904,
    2016,  1905,  2011,  1906,  1907,  2125,  1908,  2018,  1909,  2013,
    1910,  2025,  1911,  2026,  1912,  2027,  1913,  1914,  2131,  2030,
    2132,  2133,  2250,  1915,  2017,  2194,  2281,  2109,  2195,  2196,
    2197,  1916,  2009,  2101,  1917,  2020,  2112,  1918,  2019,  2111,
    1919,  2021,  2113,  1920,  2010,  2102,  1778,  1779,  1780,  1988,
    1853,  1781,  1782,  1992,  1855,  1783,  1784,  1996,  1857,  1785,
    1786,  2000,  1859,  1787,  1788,  1861,  1789,  1790,  1863,  1791,
    1792,  1921,  1793,  1794,  1923,  1795,  1796,  1925,  2136,  1797,
    1798,  1927,  2138,  1926,  1799,  1800,  1931,  1801,  1802,  1933,
    1803,  1804,  1935,  1805,  1806,  1937,  1807,  1808,  1939,  1809,
    1849,  1984,  1810,  1811,  1941,  1812,  1813,  1943,  1814,  1815,
    1945
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2088
static const yytype_int16 yypact[] =
{
     223, -2088, -2088,   125,    61,   115, -2088, -2088,   186,   -70,
   -2088,   250, -2088,   342, -2088, -2088, -2088, -2088,   -38,   351,
   -2088, -2088, -2088, -2088, -2088,    61, -2088, -2088, -2088, -2088,
   -2088,   -12,   361,   -25, -2088, -2088, -2088, -2088,   278,   487,
     186, -2088,    35,   427,    58, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,    20,
      -6, -2088, -2088,   217, -2088,   449, -2088,   510, -2088,   531,
   -2088,   574, -2088,   622, -2088,   624, -2088,   629, -2088,   389,
   -2088,   412, -2088, -2088,   418, -2088, -2088,   429, -2088, -2088,
     448, -2088, -2088,   462, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,   117,
     653,    86, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088,   159,   439, -2088, -2088,   656, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,   505, -2088,   389, -2088, -2088,
   -2088, -2088,   469, -2088,   471,   662,   217, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,   107, -2088, -2088, -2088, -2088,
      11, -2088, -2088, -2088, -2088,     8, -2088, -2088, -2088, -2088,
       9, -2088, -2088, -2088, -2088,     6, -2088, -2088, -2088, -2088,
      80, -2088, -2088, -2088, -2088,    77, -2088, -2088, -2088, -2088,
   -2088,   664, -2088,   353,   357,   360,   345,   356, -2088, -2088,
   -2088,    52, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088,   200,   437, -2088, -2088,   666, -2088,   688,
   -2088,   767, -2088,   769, -2088,   771, -2088,   389, -2088, -2088,
      72, -2088, -2088, -2088, -2088,   488,   238,   507,   238,   523,
     238,   525, -2088,   774, -2088,   533,    -2,   547,   555,    42,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088,   499, -2088, -2088,
     234, -2088, -2088,   235, -2088, -2088,   236, -2088, -2088,   240,
   -2088, -2088,   493, -2088, -2088,   483,   583,   -30, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088,   776,    38, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088,   281,   384, -2088, -2088,   778, -2088,   783, -2088,   785,
   -2088,   787, -2088,   806, -2088,   560, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088,   505, -2088,   389, -2088, -2088,   203, -2088,
   -2088, -2088, -2088,   100, -2088, -2088, -2088, -2088,    66, -2088,
   -2088, -2088, -2088,    84, -2088, -2088, -2088, -2088,   116, -2088,
   -2088, -2088, -2088,   810, -2088, -2088, -2088,   519,   816, -2088,
   -2088,   611, -2088, -2088, -2088, -2088, -2088,   816, -2088, -2088,
   -2088, -2088,   816, -2088, -2088, -2088, -2088,   623, -2088,   -23,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,   584,   564, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,   621,
     355, -2088, -2088,   -44, -2088, -2088, -2088, -2088, -2088,   682,
     684,   692, -2088, -2088, -2088, -2088, -2088, -2088, -2088,    98,
   -2088, -2088, -2088, -2088,    85, -2088, -2088, -2088, -2088,    91,
   -2088, -2088, -2088, -2088,   227, -2088, -2088, -2088, -2088,   155,
   -2088, -2088, -2088, -2088, -2088,   814, -2088,   694,   238,   696,
     238,   700,   238,   703, -2088,   821, -2088, -2088, -2088,   668,
   -2088, -2088,   672, -2088, -2088,   614, -2088, -2088,   630, -2088,
   -2088, -2088,   650, -2088,   -22, -2088, -2088, -2088, -2088, -2088,
     690, -2088,   721,   712, -2088,   698, -2088, -2088,   702, -2088,
   -2088,   704,   396, -2088, -2088, -2088, -2088, -2088,   824,   491,
   -2088, -2088, -2088,   826,   419, -2088, -2088,   441,   328, -2088,
   -2088,   753,   757,   759,   761, -2088, -2088,   706, -2088, -2088,
     686, -2088, -2088,   724, -2088, -2088,   740, -2088, -2088,   748,
     808,   189, -2088, -2088, -2088, -2088,   816, -2088, -2088, -2088,
   -2088,   816, -2088, -2088, -2088, -2088,   816, -2088, -2088, -2088,
   -2088,   823, -2088,   -21, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,   789,   511, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,   828,   419,   763, -2088,
   -2088, -2088,   855, -2088, -2088, -2088, -2088, -2088,   520, -2088,
   -2088, -2088,   863, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088,   838,   860,   379, -2088,   864,   866,   868,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,   779,   788,
   -2088, -2088,   775, -2088,   777, -2088,   791, -2088, -2088,   781,
   -2088, -2088,   825,   549, -2088, -2088, -2088, -2088,   830,   419,
     550, -2088, -2088, -2088, -2088, -2088, -2088, -2088,   886, -2088,
     890, -2088,   832, -2088,   818, -2088,   897,   905, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
     246, -2088, -2088, -2088, -2088, -2088, -2088,   835,   419,   570,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,   906,
     268, -2088, -2088, -2088, -2088, -2088,   854,   217, -2088, -2088,
     910,   133, -2088, -2088,   915, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,   580, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,   851,   844, -2088, -2088,
   -2088,   627,   837,  1163,   217, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,   841, -2088,   920, -2088, -2088,
   -2088, -2088,  1165,   440, -2088,   635,   914,   112, -2088, -2088,
   -2088, -2088,   207, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088,   241, -2088, -2088, -2088, -2088,   932, -2088, -2088, -2088,
   -2088, -2088, -2088,   645,   925, -2088,  1168, -2088, -2088, -2088,
     887, -2088, -2088,   865,   873, -2088, -2088, -2088, -2088,   947,
   -2088,   880,   272, -2088, -2088, -2088, -2088,   959, -2088,   708,
     949, -2088,  1181, -2088,   961,   827, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088,  1183,   330, -2088,   829, -2088, -2088,   967,
   -2088,   907,   951, -2088,  1187, -2088,   975,   843, -2088, -2088,
   -2088, -2088, -2088, -2088,   679,   883,   782,   908, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,   922,   976, -2088,  1191,
   -2088,   997,   955, -2088, -2088, -2088, -2088, -2088, -2088,   710,
     966,   804, -2088, -2088, -2088,   972,   782,  1010,  1193, -2088,
   -2088, -2088, -2088,  1195, -2088,  1014,   739, -2088, -2088, -2088,
   -2088, -2088, -2088,   726,   982,   831, -2088, -2088, -2088, -2088,
    1197,  1020,  1201, -2088, -2088, -2088,  1203,  1205, -2088,  1024,
     -88, -2088, -2088, -2088, -2088,  1026,   262, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088,  1005, -2088, -2088, -2088, -2088,  1209,
    1028,  1211, -2088,   701,   719, -2088, -2088, -2088, -2088,  1038,
     -97, -2088, -2088, -2088, -2088,   728,   719, -2088, -2088, -2088,
   -2088,   -64, -2088, -2088, -2088, -2088,  1055, -2088, -2088,   924,
     762, -2088, -2088, -2088, -2088, -2088,  1000,  1007, -2088, -2088,
   -2088,   -60, -2088,  1213, -2088,   738,   719, -2088, -2088, -2088,
   -2088,  1067,    -8, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088,  1034,   764, -2088,   923,  1077, -2088, -2088,   957,   805,
   -2088, -2088, -2088, -2088, -2088,  1061,   764, -2088, -2088, -2088,
     999,   809, -2088, -2088, -2088, -2088, -2088,   123, -2088, -2088,
   -2088,  1217,   347, -2088, -2088, -2088,  1102,   970, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,  1071,   764, -2088,  1135, -2088,
   -2088,  1094,   852, -2088, -2088,  1219,   381, -2088, -2088,   834,
   -2088,   923,  1141,  1221, -2088, -2088, -2088, -2088,   202,  1223,
     641, -2088,   834, -2088, -2088, -2088,    51,   816,  1143, -2088,
   -2088, -2088, -2088,   141, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088,   936,  1225,  1018,
   -2088,   834, -2088, -2088, -2088, -2088,   211,  -108, -2088, -2088,
   -2088, -2088,  1149, -2088,  1156, -2088,  1158, -2088,  1160, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,   848, -2088,   923,  1227,
    1161,  1013, -2088, -2088, -2088, -2088,   816, -2088, -2088, -2088,
   -2088,   -94, -2088, -2088, -2088, -2088, -2088,  1206, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
     848, -2088,    16, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
     867,  1309, -2088, -2088,  1212, -2088,  1247,   349, -2088, -2088,
   -2088, -2088, -2088,  -157,  1310,  1229, -2088,   -99, -2088, -2088,
   -2088, -2088, -2088,  1314, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,   848, -2088,   816, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,   979,  1021, -2088, -2088,
    1171, -2088, -2088,  1316,  1315,  1317,  1318, -2088,  1002, -2088,
     923,  1231,  1013, -2088, -2088, -2088, -2088,  1320,  1090, -2088,
    1182, -2088,  1009,  1029, -2088, -2088, -2088,   991,  1031, -2088,
   -2088,  1185, -2088, -2088,  1328,  1002, -2088, -2088, -2088,  1033,
   -2088,  1330, -2088,  1186, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088,  1333, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
    1003,  1047, -2088, -2088,  1194, -2088, -2088,  1337,  1002, -2088,
    1050, -2088, -2088,   134, -2088,  1233,   226,  1339, -2088, -2088,
   -2088, -2088,  1022, -2088,   923,  1235,  1013, -2088, -2088, -2088,
   -2088, -2088,  1030, -2088,  1340,  1237, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088,   154, -2088,  1239,   226, -2088,  1022, -2088,
   -2088, -2088, -2088,  1241,   479,  1343,   -62, -2088, -2088,   188,
   -2088,  1243,   226, -2088,  1022, -2088, -2088,    23, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,  1013, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,  1023, -2088,   923,  1245,
    1013, -2088, -2088, -2088, -2088, -2088,  1032, -2088,  1347,    60,
   -2088, -2088, -2088, -2088,  1345,  1025,    15, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088,  1013, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088,  1023, -2088,   -98, -2088, -2088, -2088, -2088,
   -2088,  1353, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
      19, -2088, -2088, -2088, -2088, -2088, -2088, -2088,  1013, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088,  1023, -2088, -2088,
   -2088, -2088, -2088,  1057, -2088,  1208, -2088, -2088, -2088, -2088,
     923,  1249,  1013, -2088, -2088, -2088, -2088, -2088,  1042, -2088,
    1354,  1204, -2088,  1357, -2088,  1356,  1358, -2088, -2088, -2088,
   -2088,  1063, -2088,  1214, -2088, -2088, -2088, -2088, -2088,  1035,
    1083,  1220, -2088, -2088, -2088,  1361,  1251,   261, -2088,  1075,
   -2088,  1222, -2088, -2088, -2088, -2088, -2088,  1253,  1013, -2088,
   -2088, -2088, -2088, -2088,  1046, -2088, -2088, -2088,  1228,  1368,
    1370, -2088, -2088, -2088, -2088, -2088,  1255,   226, -2088,  1136,
   -2088, -2088, -2088, -2088, -2088,  1376,  1372,  1373, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
    1013, -2088, -2088, -2088, -2088, -2088,  1054, -2088, -2088,  1375,
    1377,  1013, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088,  1098, -2088, -2088,  1378,  1381,  1382,  1383, -2088,  1060,
   -2088, -2088, -2088,  1240, -2088, -2088,   314,  1257,   461, -2088,
    1384,  1385, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088,  1096, -2088,  1196,
    1153, -2088, -2088, -2088,  1392,  1388,  1390,  1391,  1393,  1394,
    1395,  1396,  1397, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,  1398,   257,
    1399,   257,  1400,   257,  1403,   257,  1404,   257,  1405,   257,
   -2088,  1413,  1407, -2088, -2088, -2088,  1410,  1409, -2088, -2088,
   -2088,  1401,  1414,  1415,  1416,  1417,  1418,  1419,   816,  1129,
   -2088,  1423,  1420, -2088, -2088, -2088, -2088, -2088,  1129, -2088,
   -2088, -2088,  1129, -2088, -2088, -2088,  1129, -2088, -2088, -2088,
    1129, -2088, -2088, -2088,  1129, -2088, -2088, -2088,  1421,   337,
    1424,  1159, -2088, -2088,  1425,  1426,  1427,  1428,  1430,  1431,
    1432,  1433, -2088, -2088,  1154,  1261,  1434,  1437,  1154, -2088,
    1154, -2088,  1154, -2088,  1154, -2088,  1154, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,  1151, -2088,
    1215, -2088,  1216, -2088,  1218, -2088,  1224, -2088,   337, -2088,
     337, -2088,   765, -2088,   337, -2088,   990, -2088,   990, -2088,
    1263, -2088,   337, -2088,   337, -2088,   337, -2088,   337, -2088,
   -2088,   765, -2088,   765, -2088,   337,  1436, -2088,  1199,   923,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,  1198,
    1170,  1265,  1013, -2088, -2088, -2088, -2088, -2088,  1442,  1176,
    1200,  1178,  1202,  1179,  1190,  1184,  1207,  1188,  1210, -2088,
   -2088, -2088,  1449,  1267,  1452,  1269,  1453,  1271,  1456,  1273,
    1056, -2088,   337, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088,  1027, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088,   765, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088,  1036, -2088,  1464,  1458, -2088,  1459, -2088,  1052,
   -2088, -2088,   337, -2088,  1051, -2088,   337, -2088,   337, -2088,
     337, -2088,   765, -2088,  1040, -2088, -2088, -2088, -2088,   923,
    1275, -2088, -2088, -2088, -2088,  1277,  1013, -2088, -2088, -2088,
   -2088, -2088,  1226, -2088, -2088, -2088,  1279, -2088, -2088, -2088,
    1281, -2088, -2088, -2088,  1283, -2088, -2088, -2088,  1285, -2088,
   -2088, -2088,  1287, -2088,   305,  1469,  1041, -2088, -2088,  1472,
    1230, -2088, -2088,  1473,  1192, -2088, -2088,  1474,  1189, -2088,
   -2088, -2088,  1069,   765,   765,   765,   765,   765,   765, -2088,
   -2088,   765,   765,   765,   765,   765,   765, -2088,   765, -2088,
   -2088, -2088,  1289,  1291,   765,   337,   337,   337, -2088,  1099,
       7, -2088,  1476,   337,   337, -2088,  1066, -2088,  1064,  1065,
    1062,   765, -2088,  1059,  1295, -2088,  1013, -2088, -2088, -2088,
   -2088,  1331, -2088, -2088, -2088, -2088, -2088,  1232, -2088,  1013,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088,  1013, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,  1481, -2088,  1485, -2088,
    1486, -2088,  1487, -2088, -2088,   765,   765,   765,   765,  1132,
    1131,   496,   552,  1127,  1126,   765,  1123,  1122,  1121,    69,
    1116,   601,   654,   693,  1109, -2088, -2088,  1110, -2088, -2088,
     765,  1103,  1104,  1101, -2088, -2088,  1111, -2088,  1508, -2088,
   -2088, -2088, -2088, -2088, -2088,  1100, -2088,  1105, -2088, -2088,
   -2088, -2088, -2088,   765, -2088, -2088, -2088, -2088, -2088,  1013,
   -2088, -2088, -2088, -2088, -2088,  1264,  1090, -2088,  1367, -2088,
    1242, -2088, -2088,  1244,  1246,  1369,   -63, -2088,  1248,   -56,
   -2088, -2088, -2088, -2088,  1167,  1169,  1166,  1157, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,   765, -2088, -2088, -2088,
     734, -2088,  1517,  1521, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088,  1130, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,   337,  1297,   270, -2088,  1282,
   -2088,  1299, -2088, -2088,  1298, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088,  1301, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088,  1162, -2088, -2088,  1527,   816, -2088,
    1526,  1107,  1136, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,    73, -2088, -2088, -2088, -2088,
    1525, -2088,  1303,    75,   765, -2088, -2088, -2088, -2088,    26,
   -2088,  1152,  1529,  1532, -2088, -2088, -2088,  1296,  1535,  1537,
    1387, -2088,   816, -2088, -2088, -2088, -2088, -2088, -2088,  1538,
    1539, -2088, -2088, -2088,  1402,  1542, -2088,  1546, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,   314, -2088,
   -2088, -2088, -2088,  1406,     2,  1544,   816, -2088,  1408,  1545,
   -2088, -2088, -2088, -2088, -2088, -2088,  1319,  1548,  1550, -2088,
   -2088,  1551,  1552, -2088, -2088, -2088,   816,  1554, -2088,  1553,
    1274, -2088, -2088
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,  1505, -2088,
    1540, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,  1503,
   -2088, -2088, -2088, -2088,  1411, -2088, -2088, -2088, -2088, -2088,
    1164, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,  1144, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,  1435,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
    1068, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088,  1342, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088,   985, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,  1256, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088,   933, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088,   921, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088,  1045, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,   822, -2088, -2088, -2088,
   -2088, -2088,   768, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,   595,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088,   546, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088,   310, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088,   308, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088,   562, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088,   346, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088,   344, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,   524,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,   284, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088,   283, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,    78,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,   603, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,   391, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088,   845, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088,   772, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
     -80, -2088, -2088, -2088, -2088,  -514, -2088,  -366, -1315,  -200,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -1244, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088,  -825, -2088, -2088, -2088, -2088, -2088,  -802, -2088,
   -2088, -2088, -2088, -2088,  -969, -2088, -2088, -2088, -2088, -2088,
   -1083, -2088, -2088, -2088, -2088, -2088, -1155, -2088, -2088, -2088,
   -2088, -2088,  -972, -2088, -2088, -2088, -2088, -2088, -1234, -2088,
   -2088, -2088, -2088, -2088, -1039, -1332, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088,  -661, -2088, -2088, -2088, -2088, -2088,
    -693, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -1186,
   -2088, -2088, -2088, -2088, -2088, -1059, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088,   486, -2088, -1313, -1056,   554,   243,   532, -2088, -2088,
    -970,  -837, -2088, -2088,  -557, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -1008,  -679, -2088, -2087, -2088, -2088,
   -2088, -2088, -2088, -2088,  -735, -2088, -2088, -2088, -2088, -2088,
    -136, -2088, -2088, -1041, -2088, -2088, -2088, -2088, -2088,  -510,
   -2088, -2088, -2088, -2088, -2088,  -928, -2088, -2088, -2088, -2088,
   -2088, -1040, -2088, -2088,  -616, -2088, -2088,  -689, -2088, -2088,
    -243, -2088, -2088,  -593, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -1738, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -1687, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088,  -196, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088, -2088,
   -2088
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     286,   733,   501,  1381,   666,   381,   395,   386,  1331,   252,
     277,   504,   271,   274,   615,   268,   506,  2126,  2127,  1469,
    1277,  1470,  1471,  1469,  1169,  1470,  1471,  1469,   758,  1470,
    1471,    49,  1149,  1420,   525,    50,  2305,   417,   799,  1172,
    1174,    51,  1233,  1059,   509,   583,   650,  1028,  1016,  1464,
      49,  1297,  1507,  1216,    50,    52,  1264,   977,  1043,   928,
      51,  1182,  1183,   428,  1491,   758,   705,   254,  1221,  1223,
    1159,    53,   483,  1940,    52,  1942,   365,  2290,  1188,  2190,
    2191,   283,  1395,  1445,   280,  2231,   299,   665,   486,   538,
      53,  1502,  2236,  1514,   126,   541,   127,  1276,   128,   403,
     129,  1860,   535,  1862,   300,   741,   480,  1922,  1231,  1251,
     373,   265,   380,  1181,   385,  1932,   808,  1934,   301,  1936,
    1349,  1938,   489,   490,   130,     6,   302,  1286,  1944,    12,
     404,  1476,   216,  1087,   217,  1520,   303,  2271,   304,   762,
     763,  1027,  1227,  1309,  1367,  1368,  1487,   481,   131,   704,
     305,  2333,   218,  1365,   306,   872,   307,   364,   308,   547,
     309,   281,   219,   366,  1406,  1407,   542,   484,   266,  2029,
    1504,  1057,   539,   809,   284,  2002,   153,   154,  1544,   487,
     220,     7,  1287,   536,   611,   612,   221,  1446,   740,  1506,
     643,  1234,  2311,   491,   515,   645,  1298,   474,  1450,  1451,
     647,    14,  1017,   756,  2041,  2306,  2307,   477,   548,  1265,
    1192,  1325,  1156,  2232,  1522,   978,   520,  1492,   601,   602,
    2237,  1228,  1044,  1446,  1083,   560,   764,   565,   531,   570,
    2291,   544,  1235,  1524,  1587,     1,     2,    17,  1533,  1029,
     756,  1299,  1508,  1170,   429,  2036,  1266,   430,   150,  2038,
     431,  2039,   478,  2040,  1112,   476,   721,   722,  1495,  1496,
      20,    21,   545,   801,   550,  2095,  2096,  2097,  2098,  2099,
    2100,    30,   526,  2103,  2104,  2105,  2106,  2107,  2108,  2334,
    2110,   636,  1088,    54,  1575,  1389,  2120,  1060,   637,  2299,
     601,   602,   811,  1193,  1194,   812,  1195,  2085,  1433,    41,
    2192,   601,   602,  2143,  2193,  1373,    55,  1100,    56,   418,
      57,  2300,    58,  1436,  1441,  1518,   510,   584,   651,  1500,
    1278,   601,   602,  1472,   817,    55,  1598,    56,   148,    57,
     984,    58,   559,   985,   564,  1412,   569,  1604,  2121,  2122,
    2123,   744,   272,   269,   278,   275,  2135,  2137,   118,  1481,
     745,  1456,    25,    26,  1088,   601,   602,  2174,  2175,  2176,
    2177,    33,    34,  2181,  2183,  1088,   310,  2186,   132,   601,
     602,    44,    45,  2200,  2202,  2204,  1424,  1143,   601,   602,
     151,   152,  2207,   604,  1072,  1088,   153,   154,   614,   151,
     152,  1175,  1468,   818,   819,   676,   820,   677,   222,    80,
     620,   151,   152,   611,   612,  2215,   525,   723,   724,   151,
     152,   200,   678,   370,   371,   153,   154,   203,   299,  1088,
    1224,   370,   371,   204,   818,   819,   683,   820,   601,   602,
     153,   154,   208,  1088,   205,   687,   300,   121,   122,   153,
     154,  1527,  1088,   396,   397,   398,   399,   734,  2244,  1103,
     301,  2128,  2246,   206,  1700,  1701,  1554,  1555,   302,   165,
     166,   664,  1702,  1556,  1557,  1554,  1555,   207,   303,   238,
     304,   709,   257,  1144,   258,   126,   292,   127,   720,   128,
     295,   129,   305,   216,   293,   217,   306,  1176,   307,  1558,
     308,   294,   309,   151,   152,   296,  2257,  2258,   368,   153,
     154,  1193,  1194,   218,  1195,   130,  1951,   796,   723,   724,
     151,   152,   336,   219,   601,   602,  1225,   377,   759,   760,
     170,   171,  1748,   703,   611,   612,  1750,  1092,  2251,   131,
    1752,   220,  1102,   382,  1754,   387,  2304,   221,  1756,   394,
    1122,   175,   176,   769,   151,   152,  1123,  1124,   601,   602,
     153,   154,  1125,  1126,   732,   401,  1136,  1615,   611,   612,
     409,   788,   739,   402,  1127,  1128,   410,  1616,  1160,   411,
    1173,  1617,   412,  1618,   414,  1619,  1189,  1620,   413,  1621,
     415,   757,   151,   152,   180,   181,   601,   602,  1961,   416,
    1759,   921,   464,  1622,  1760,   437,   611,   612,  1761,  1222,
     796,   723,   724,   151,   152,   834,  1232,   601,   602,    81,
     499,    82,    83,    84,   502,    85,    86,    87,   757,    88,
      89,    90,  1759,    91,    92,    93,  1760,    94,    95,   507,
    1761,   856,   185,   186,   190,   191,  2045,   800,  1122,   195,
     196,   516,   151,   152,  1123,  1124,   601,   602,   153,   154,
    1125,  1126,   404,   881,   151,   152,   611,   612,   601,   602,
    1643,  1644,   892,   211,   212,  1442,   240,   241,   151,   152,
    1430,  1431,   259,   260,   287,   288,   338,   339,   905,  1645,
    1646,  1647,  1648,  1649,  1650,  1651,  1652,   916,   521,  1839,
     532,  1841,   533,  1843,   418,  1845,  1204,  1847,   343,   344,
     534,  1710,   935,  1714,   556,  1718,   561,  1722,   871,  1726,
     566,   945,  2056,   571,  1762,   580,  1763,   578,  1764,   579,
    1765,  1190,  1766,  1383,  1767,   581,  1768,   582,  1769,   590,
    1770,   589,  1771,  2084,  1772,   510,  1773,   592,  1774,   593,
    1775,   990,  1776,  1711,  1777,  1715,  1762,  1719,  1763,  1723,
    1764,  1727,  1765,  1422,  1766,   591,  1767,   619,  1768,   626,
    1769,  1443,  1770,   627,  1771,   628,  1772,   629,  1773,  1466,
    1774,   594,  1775,   631,  1776,   633,  1777,   348,   349,   353,
     354,   358,   359,  1038,   389,   390,   423,   424,   439,   440,
    1263,   630,  1046,   444,   445,   449,   450,   454,   455,   632,
    1122,   634,  2154,  1374,   151,   152,  1123,  1124,   601,   602,
     153,   154,  1125,  1126,   635,  2162,   459,   460,   611,   612,
     494,   495,   489,   490,   551,   552,  1166,  1167,  1567,   648,
    2167,   573,   574,  1413,   598,   599,   608,   609,   660,   661,
     699,   700,   710,   711,  1440,   735,   736,   777,   778,  1457,
     584,  1864,   667,  1865,   897,  1866,   656,  1867,   668,  1868,
     669,  1869,  1310,  1870,  2180,  1871,   670,  1872,   671,  1873,
     674,  1874,   684,  1875,   685,  1876,   686,  1877,   688,  1878,
     636,  1879,   691,  1880,   694,  1881,   692,  1882,   651,  1883,
     706,  1884,   695,  1885,   707,  1886,   693,  1887,   708,  1888,
     718,  1889,   715,  1890,  1202,  2218,  1101,  1864,   719,  1865,
     742,  1866,   743,  1867,   750,  1868,   761,  1869,   767,  1870,
     768,  1871,  2182,  1872,   770,  1873,   745,  1874,   790,  1875,
    1132,  1876,   774,  1877,   789,  1878,   802,  1879,   805,  1880,
     827,  1881,   828,  1882,  1171,  1883,   831,  1884,   840,  1885,
     841,  1886,   845,  1887,  1589,  1888,  1864,  1889,  1865,  1890,
    1866,   812,  1867,   847,  1868,   849,  1869,   862,  1870,   853,
    1871,   863,  1872,  1220,  1873,   874,  1874,   875,  1875,   878,
    1876,   887,  1877,   873,  1878,   893,  1879,   888,  1880,   850,
    1881,  2199,  1882,   894,  1883,   897,  1884,   900,  1885,   902,
    1886,   901,  1887,   911,  1888,   912,  1889,  1563,  1890,  1864,
     918,  1865,   917,  1866,   921,  1867,   924,  1868,   929,  1869,
     941,  1870,   942,  1871,   946,  1872,   947,  1873,   959,  1874,
     976,  1875,   983,  1876,   992,  1877,  1001,  1878,   950,  1879,
    1007,  1880,  1010,  1881,  1015,  1882,  2201,  1883,  1864,  1884,
    1865,  1885,  1866,  1886,  1867,  1887,  1868,  1888,  1869,  1889,
    1870,  1890,  1871,  1034,  1872,   978,  1873,  1022,  1874,  1035,
    1875,  1039,  1876,  1058,  1877,   984,  1878,  1052,  1879,  1067,
    1880,  1072,  1881,  1068,  1882,  1075,  1883,  2203,  1884,  1864,
    1885,  1865,  1886,  1866,  1887,  1867,  1888,  1868,  1889,  1869,
    1890,  1870,  1076,  1871,  1017,  1872,  1081,  1873,  1104,  1874,
    1084,  1875,  1029,  1876,  1105,  1877,  1110,  1878,  2245,  1879,
    1864,  1880,  1865,  1881,  1866,  1882,  1867,  1883,  1868,  1884,
    1869,  1885,  1870,  1886,  1871,  1887,  1872,  1888,  1873,  1889,
    1874,  1890,  1875,  1113,  1876,  1114,  1877,  1060,  1878,  1150,
    1879,  1191,  1880,  1204,  1881,  1145,  1882,  1243,  1883,  1244,
    1884,  1245,  1885,  1246,  1886,  1247,  1887,  1257,  1888,  1258,
    1889,  1280,  1890,   782,   783,   791,   792,  1122,   835,   836,
    1382,   151,   152,  1123,  1124,   601,   602,   153,   154,  1125,
    1126,   857,   858,   867,   868,   611,   612,   882,   883,  1212,
    1213,   906,   907,   930,   931,   936,   937,   954,   955,  1274,
    1421,   960,   961,   966,   967,   971,   972,  1282,  1435,   996,
     997,  1002,  1003,  1047,  1048,   950,  1465,  1093,  1094,  1117,
    1118,  1151,  1152,  1161,  1162,  1207,  1208,  1252,  1253,  1292,
    1293,  1326,  1327,  1375,  1376,  1390,  1391,  1399,  1400,  1414,
    1415,  1425,  1426,  1458,  1459,  1482,  1483,  1495,  1496,  1528,
    1529,  1549,  1550,  1570,  1571,  1581,  1582,  1640,  1641,  1680,
    1681,  1832,  1833,  1929,  1930,  1956,  1957,  1986,  1987,  1990,
    1991,  1994,  1995,  1998,  1999,  2046,  2047,  2051,  2052,  2059,
    2060,  2064,  2065,  2069,  2070,  2074,  2075,  2079,  2080,  2114,
    2115,  2117,  2118,  2144,  2145,  2149,  2150,  2252,  2253,  2265,
    2266,  2274,  2275,  2294,  2295,  1281,  1284,  1307,  1291,  1311,
    1234,  1233,  1317,  1318,  1334,  1319,  1320,  1321,  1333,  1340,
    1336,  1341,  1741,  1339,  1265,  1264,  1347,  1350,  1351,  1355,
    1352,  2129,  1298,  1357,  1297,  1363,  1366,  1384,  1398,  1385,
    1397,  1444,  1477,  1490,  1489,  1493,  1515,  1525,  1597,  1526,
    1535,  1537,  1536,  1538,  1539,  1542,  1540,  1541,  1446,  1548,
    1507,  1568,  1577,  1569,  1579,  1543,  1580,  1578,  1590,  1594,
    1595,  1596,  1600,  1601,  1605,  1602,  1609,  1610,  1611,  1612,
    1613,  1614,  1665,  1666,  1689,  1690,  1691,  1686,  1692,  1693,
    1742,  1694,  1695,  1696,  1697,  1698,  1817,  1734,  1699,  1708,
    1712,  1588,  1667,  1716,  1720,  1724,  1728,  1729,  1730,  1731,
    1735,  1736,  1737,  1738,  1739,  1740,  1746,  1828,  1747,  1758,
    1816,  1850,  1924,  1820,  1821,  1822,  1823,  2130,  1824,  1825,
    1826,  1827,  1837,  1838,  1946,  1953,  1852,  1854,  1947,  1856,
    1963,  1964,  1952,  1968,  1972,  1858,  1975,  1985,  1967,  1976,
    1989,  1993,  1971,  1980,  1997,  2028,  2001,  2032,  2033,  2034,
    2035,  1979,  1983,  2037,  2042,  2086,  2031,  2087,  2088,  2090,
    2092,  2094,  2091,  2093,  2134,  2124,  2139,  2156,  2140,  2170,
    1733,  2141,  2142,  2171,  2172,  2173,  2178,  2179,  2058,  2184,
    2185,  2187,  2188,  2189,  2198,  2205,  2161,  2208,  2206,  2210,
    2209,  2212,  2220,  2211,  2213,  2222,  2089,  2228,  2225,  2243,
    2226,  2214,  2227,  2240,  2235,  2247,  2242,  2241,  2263,  2248,
    2249,  1496,  2264,  2282,  2284,  2292,  2315,  2316,  2280,  2285,
    2317,  2320,  2319,  2321,  2322,   117,  2325,  2326,  2328,  2329,
    2337,  2327,  2352,  2340,  2341,  2332,  2344,  2339,  2345,  2346,
    2350,  2351,  2347,   149,   522,    40,   337,   264,   438,   239,
     517,   657,   689,   621,   696,  1036,   787,  1085,  1342,  1344,
     595,  1077,   842,  1312,  1314,  1358,  1115,  1360,  1285,  1545,
    1040,  2286,   771,  2318,   848,  1215,  1099,  1434,  1131,  2221,
    2310,  2262,  1928,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,  2283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2323,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2338,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2349,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2288,  2289,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2330,  2331
};

static const yytype_int16 yycheck[] =
{
     200,   690,   368,  1316,   597,   248,     8,   250,  1252,   145,
       4,   377,     4,     4,   524,     4,   382,    10,    11,     4,
       4,     6,     7,     4,  1080,     6,     7,     4,   717,     6,
       7,    56,  1071,  1346,    78,    60,    10,    67,   773,  1080,
    1080,    66,   150,    51,    67,    67,    67,   111,   145,  1362,
      56,   150,   150,  1109,    60,    80,   150,   145,   118,   896,
      66,    10,    11,    25,     4,   754,   659,   147,  1109,  1109,
    1078,    96,     6,  1811,    80,  1813,     4,     4,  1086,    10,
      11,     4,  1326,   145,     4,   148,    34,   597,     4,     4,
      96,  1406,   148,  1425,    36,     4,    38,  1180,    40,    57,
      42,  1788,     4,  1790,    52,   698,     6,  1794,  1116,  1148,
     246,     4,   248,  1082,   250,  1802,     4,  1804,    66,  1806,
    1275,  1808,     6,     7,    66,     0,    74,   284,  1815,    14,
      88,  1375,    46,    10,    48,  1450,    84,  2224,    86,     6,
       7,   966,  1111,  1226,    10,    11,  1390,    47,    90,   659,
      98,   149,    66,  1308,   102,   844,   104,   237,   106,     4,
     108,    81,    76,    91,    10,    11,    75,   101,    61,  1907,
    1414,   996,    87,    61,    97,  1862,   169,   170,  1510,    95,
      94,   120,   339,    85,   177,   178,   100,   285,   698,  1423,
     556,   299,  2279,    77,   394,   561,   295,   333,    10,    11,
     566,    15,   299,   717,  1942,   179,   180,     4,    53,   303,
      69,  1250,    10,   276,  1458,   303,   416,   157,   167,   168,
     276,    10,   282,   285,  1026,   468,    93,   470,   428,   472,
     157,     4,   340,  1467,  1547,    12,    13,   307,  1482,   303,
     754,   340,   340,  1080,   206,  1932,   340,   209,    31,  1936,
     212,  1938,    49,  1940,  1056,   335,    10,    11,   232,   233,
      10,    11,    35,   773,   464,  2003,  2004,  2005,  2006,  2007,
    2008,   309,   316,  2011,  2012,  2013,  2014,  2015,  2016,   277,
    2018,    92,   231,   308,  1528,  1324,  2024,   295,    99,   214,
     167,   168,    85,   152,   153,    88,   155,  1984,  1354,   311,
     231,   167,   168,  2041,   235,  1313,   331,  1042,   333,   339,
     335,   236,   337,  1354,  1354,   296,   339,   339,   339,   304,
     304,   167,   168,   300,    83,   331,  1570,   333,   308,   335,
      68,   337,   468,    71,   470,  1343,   472,  1581,  2025,  2026,
    2027,    73,   334,   332,   338,   336,  2033,  2034,   313,  1388,
      82,  1359,    10,    11,   231,   167,   168,  2095,  2096,  2097,
    2098,    10,    11,  2101,  2102,   231,   314,  2105,   310,   167,
     168,    10,    11,  2111,  2112,  2113,  1348,  1066,   167,   168,
     163,   164,  2120,   519,   158,   231,   169,   170,   524,   163,
     164,  1080,  1364,   152,   153,    16,   155,    18,   312,   121,
      72,   163,   164,   177,   178,  2143,    78,   161,   162,   163,
     164,    22,    33,   175,   176,   169,   170,     5,    34,   231,
    1109,   175,   176,     5,   152,   153,   626,   155,   167,   168,
     169,   170,   315,   231,     5,   635,    52,    10,    11,   169,
     170,  1480,   231,   445,   446,   447,   448,   690,  2186,  1042,
      66,   444,  2190,     5,   197,   198,   195,   196,    74,    10,
      11,   597,   205,   202,   203,   195,   196,     5,    84,   310,
      86,   671,     3,  1066,     3,    36,   123,    38,   678,    40,
     135,    42,    98,    46,   127,    48,   102,  1080,   104,   228,
     106,   131,   108,   163,   164,   139,   226,   227,    10,   169,
     170,   152,   153,    66,   155,    66,  1819,   160,   161,   162,
     163,   164,   312,    76,   167,   168,  1109,    10,   718,   719,
      10,    11,  1708,   659,   177,   178,  1712,  1037,  2215,    90,
    1716,    94,  1042,    10,  1720,    10,  2274,   100,  1724,     6,
     159,    10,    11,   743,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   690,     8,  1066,   243,   177,   178,
      61,   761,   698,     8,   183,   184,   332,   253,  1078,   334,
    1080,   257,   336,   259,    81,   261,  1086,   263,   338,   265,
      97,   717,   163,   164,    10,    11,   167,   168,  1832,     6,
     285,   210,    32,   279,   289,   314,   177,   178,   293,  1109,
     160,   161,   162,   163,   164,   805,  1116,   167,   168,   122,
      91,   124,   125,   126,     3,   128,   129,   130,   754,   132,
     133,   134,   285,   136,   137,   138,   289,   140,   141,     6,
     293,   831,    10,    11,    10,    11,  1949,   773,   159,    10,
      11,    57,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    88,   853,   163,   164,   177,   178,   167,   168,
     199,   200,   862,    10,    11,  1354,    10,    11,   163,   164,
     191,   192,    10,    11,    10,    11,    10,    11,   878,   218,
     219,   220,   221,   222,   223,   224,   225,   887,    67,  1748,
       8,  1750,     8,  1752,   339,  1754,   217,  1756,    10,    11,
       8,  1671,   902,  1673,    10,  1675,    10,  1677,   844,  1679,
      10,   911,  1956,    10,   409,   101,   411,    49,   413,    47,
     415,  1087,   417,  1316,   419,    95,   421,    77,   423,     8,
     425,    41,   427,   428,   429,   339,   431,    39,   433,    37,
     435,   941,   437,  1671,   439,  1673,   409,  1675,   411,  1677,
     413,  1679,   415,  1346,   417,    43,   419,   316,   421,     6,
     423,  1354,   425,     6,   427,     6,   429,     6,   431,  1362,
     433,    67,   435,    87,   437,    35,   439,    10,    11,    10,
      11,    10,    11,   983,    10,    11,    10,    11,    10,    11,
    1156,    85,   992,    10,    11,    10,    11,    10,    11,    75,
     159,    53,  2046,  1313,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,     6,  2059,    10,    11,   177,   178,
      10,    11,     6,     7,    10,    11,   185,   186,  1517,     6,
    2074,    10,    11,  1343,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,  1354,    10,    11,    10,    11,  1359,
     339,   355,    89,   357,   213,   359,    67,   361,     3,   363,
     340,   365,  1228,   367,   368,   369,     3,   371,    30,   373,
      10,   375,     8,   377,     8,   379,     8,   381,    99,   383,
      92,   385,   107,   387,   103,   389,   109,   391,   339,   393,
     340,   395,    67,   397,     8,   399,   105,   401,     8,   403,
       3,   405,    84,   407,  1104,  2149,  1042,   355,     3,   357,
     340,   359,     6,   361,    60,   363,     6,   365,     3,   367,
     340,   369,   370,   371,    73,   373,    82,   375,     8,   377,
    1066,   379,   305,   381,    93,   383,   301,   385,    24,   387,
       8,   389,   297,   391,  1080,   393,    21,   395,    61,   397,
      85,   399,     5,   401,  1547,   403,   355,   405,   357,   407,
     359,    88,   361,    83,   363,     6,   365,     6,   367,    20,
     369,   144,   371,  1109,   373,     8,   375,    70,   377,    28,
     379,     6,   381,   154,   383,   306,   385,   144,   387,   281,
     389,   390,   391,   110,   393,   213,   395,    89,   397,    23,
     399,    79,   401,     6,   403,    50,   405,  1517,   407,   355,
      44,   357,   302,   359,   210,   361,    44,   363,     8,   365,
       6,   367,   283,   369,   298,   371,    44,   373,     8,   375,
       6,   377,     6,   379,    29,   381,     8,   383,   207,   385,
     339,   387,   323,   389,     6,   391,   392,   393,   355,   395,
     357,   397,   359,   399,   361,   401,   363,   403,   365,   405,
     367,   407,   369,     8,   371,   303,   373,   339,   375,   145,
     377,    71,   379,     6,   381,    68,   383,   339,   385,    45,
     387,   158,   389,   319,   391,     8,   393,   394,   395,   355,
     397,   357,   399,   359,   401,   361,   403,   363,   405,   365,
     407,   367,   145,   369,   299,   371,    45,   373,     6,   375,
     111,   377,   303,   379,   144,   381,    45,   383,   384,   385,
     355,   387,   357,   389,   359,   391,   361,   393,   363,   395,
     365,   397,   367,   399,   369,   401,   371,   403,   373,   405,
     375,   407,   377,     8,   379,    51,   381,   295,   383,     8,
     385,     8,   387,   217,   389,   321,   391,     8,   393,     3,
     395,     3,   397,     3,   399,   317,   401,     6,   403,   156,
     405,   304,   407,    10,    11,    10,    11,   159,    10,    11,
    1316,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    10,    11,    10,    11,   177,   178,    10,    11,   181,
     182,    10,    11,    10,    11,    10,    11,    10,    11,     3,
    1346,    10,    11,    10,    11,    10,    11,     5,  1354,    10,
      11,    10,    11,    10,    11,   207,  1362,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,   232,   233,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   173,
     174,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   244,   245,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,     6,    69,     3,     8,   340,
     299,   150,     6,     8,   234,     8,     8,   325,     8,   300,
     148,   340,  1698,   324,   303,   150,     8,   304,     8,     6,
     154,  2030,   295,   340,   150,     8,   296,     8,     8,   327,
     320,     8,   329,     6,   322,    10,     3,   300,  1558,   151,
     318,   157,     8,     6,     8,   151,     8,   304,   285,     8,
     150,   296,   326,   151,     6,   340,     6,   149,   242,     3,
       8,     8,   328,     8,   286,     8,     8,     6,     6,     6,
     330,   151,     8,     8,   241,     3,     8,   201,     8,     8,
     271,     8,     8,     8,     8,     8,   247,     6,    10,    10,
      10,  1547,  1612,    10,    10,    10,     3,    10,     8,    10,
       6,     6,     6,     6,     6,     6,     3,   273,     8,     8,
       6,   280,   442,     8,     8,     8,     8,  2030,     8,     8,
       8,     8,     8,     6,     8,   275,   231,   231,   249,   231,
       8,   275,   254,   275,   275,   231,   266,     8,   258,   275,
       8,     8,   260,   275,     8,   438,   410,     3,    10,    10,
     418,   264,   262,   422,   434,     6,   440,   436,     6,     6,
       6,   412,   290,   294,     8,   386,   420,   156,   424,     8,
    1690,   426,   430,     8,     8,     8,   364,   366,   272,   372,
     374,   378,   380,   382,   388,   396,   274,   404,   398,   408,
     406,     3,   248,   402,   414,   148,   286,   148,   276,   362,
     276,   416,   276,   356,   276,     8,   360,   358,  2217,     8,
     400,   233,   250,     6,     8,    10,   384,     8,   376,   432,
       8,     6,   246,     6,   157,    40,     8,     8,     6,     3,
       6,   149,   278,     8,   235,   149,     8,   149,     8,     8,
       6,     8,    10,    60,   420,    25,   224,   156,   312,   134,
     406,   586,   639,   528,   653,   980,   754,  1031,  1268,  1271,
     512,  1019,   814,  1237,  1240,  1301,  1062,  1304,  1197,  1511,
     987,  2252,   747,  2286,   822,  1109,  1042,  1354,  1066,  2156,
    2279,  2217,  1798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,  2248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2292,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2257,  2258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2320,  2321
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   450,   451,   452,     0,   120,   459,   460,
    1091,  1092,    14,   453,    15,   457,   458,   307,   461,   462,
      10,    11,  1093,  1094,  1095,    10,    11,   454,   455,   456,
     309,   541,   542,    10,    11,   463,   464,   465,  1096,  1097,
     459,   311,   595,   596,    10,    11,   543,   544,   545,    56,
      60,    66,    80,    96,   308,   331,   333,   335,   337,   466,
     467,   468,   469,   470,   485,   486,   491,   492,   497,   498,
     503,   504,   509,   510,   515,   516,   521,   522,   527,   528,
     121,   122,   124,   125,   126,   128,   129,   130,   132,   133,
     134,   136,   137,   138,   140,   141,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    1112,  1113,  1114,  1115,  1116,  1117,  1118,   457,   313,   647,
     648,    10,    11,   597,   598,   599,    36,    38,    40,    42,
      66,    90,   310,   546,   547,   548,   549,   550,   555,   556,
     562,   563,   569,   570,   576,   577,   581,   582,   308,   468,
      31,   163,   164,   169,   170,   471,   472,   473,  1084,  1389,
    1390,  1391,  1416,  1417,  1418,    10,    11,   487,   488,   489,
      10,    11,   493,   494,   495,    10,    11,   499,   500,   501,
      10,    11,   505,   506,   507,    10,    11,   511,   512,   513,
      10,    11,   517,   518,   519,    10,    11,   523,   524,   525,
      22,   529,  1079,     5,     5,     5,     5,     5,   315,   742,
     743,    10,    11,   649,   650,   651,    46,    48,    66,    76,
      94,   100,   312,   600,   601,   602,   603,   604,   609,   610,
     615,   616,   621,   622,   627,   628,   633,   634,   310,   548,
      10,    11,   551,   552,   553,   557,   558,   564,   565,   571,
     572,   578,  1389,   583,  1079,  1088,  1089,     3,     3,    10,
      11,   474,   475,   476,   473,     4,    61,   490,     4,   332,
     496,     4,   334,   502,     4,   336,   508,     4,   338,   514,
       4,    81,   520,     4,    97,   526,  1088,    10,    11,   530,
     531,   532,   123,   127,   131,   135,   139,   744,   745,    34,
      52,    66,    74,    84,    86,    98,   102,   104,   106,   108,
     314,   652,   653,   654,   655,   656,   661,   662,   667,   668,
     673,   674,   679,   680,   685,   686,   702,   703,   709,   710,
     716,   717,   723,   724,   728,   729,   312,   602,    10,    11,
     605,   606,   607,    10,    11,   611,   612,   613,    10,    11,
     617,   618,   619,    10,    11,   623,   624,   625,    10,    11,
     629,   630,   631,   635,  1079,     4,    91,   554,    10,   560,
     175,   176,   559,  1389,  1419,  1420,  1421,    10,   567,   566,
    1389,  1419,    10,   574,   573,  1389,  1419,    10,   579,    10,
      11,   584,   585,   586,     6,     8,   445,   446,   447,   448,
    1090,     8,     8,    57,    88,   477,   478,   479,   480,    61,
     332,   334,   336,   338,    81,    97,     6,    67,   339,   533,
     534,   535,   536,    10,    11,   747,   748,   749,    25,   206,
     209,   212,   746,  1082,  1351,  1357,  1362,   314,   654,    10,
      11,   657,   658,   659,    10,    11,   663,   664,   665,    10,
      11,   669,   670,   671,    10,    11,   675,   676,   677,    10,
      11,   681,   682,   683,    32,   687,  1085,   704,   705,   711,
     712,   718,   719,   725,  1389,   730,  1079,     4,    49,   608,
       6,    47,   614,     6,   101,   620,     4,    95,   626,     6,
       7,    77,   632,  1086,    10,    11,   636,   637,   638,    91,
     561,  1086,     3,   568,  1086,   575,  1086,     6,   580,    67,
     339,   587,   588,   589,   590,  1088,    57,   479,   481,   482,
    1088,    67,   535,   537,   538,    78,   316,   750,   751,   752,
     753,  1088,     8,     8,     8,     4,    85,   660,     4,    87,
     666,     4,    75,   672,     4,    35,   678,     4,    53,   684,
    1088,    10,    11,   688,   689,   690,    10,   707,   706,  1389,
    1419,    10,   714,   713,  1389,  1419,    10,   721,   720,  1389,
    1419,    10,   726,    10,    11,   731,   732,   733,    49,    47,
     101,    95,    77,    67,   339,   639,   640,   641,   642,    41,
       8,    43,    39,    37,    67,   589,   591,   592,    10,    11,
     484,   167,   168,   483,  1389,  1398,  1399,  1400,    10,    11,
     540,   177,   178,   539,  1389,  1398,  1422,  1423,  1424,   316,
      72,   752,  1052,  1053,   754,   755,     6,     6,     6,     6,
      85,    87,    75,    35,    53,     6,    92,    99,   691,   692,
     693,   694,   708,  1086,   715,  1086,   722,  1086,     6,   727,
      67,   339,   734,   735,   736,   737,    67,   641,   643,   644,
      10,    11,   594,   593,  1389,  1398,  1422,    89,     3,   340,
       3,    30,  1054,  1083,    10,   760,    16,    18,    33,   756,
     757,   758,   759,  1088,     8,     8,     8,  1088,    99,   693,
     695,   107,   109,   105,   103,    67,   736,   738,   739,    10,
      11,   646,   645,  1389,  1398,  1422,   340,     8,     8,  1088,
      10,    11,  1055,  1056,  1057,    84,   761,   762,     3,     3,
    1088,    10,    11,   161,   162,   696,   697,   698,   699,  1383,
    1384,  1385,  1389,  1416,  1419,    10,    11,   741,   740,  1389,
    1398,  1422,   340,     6,    73,    82,  1058,  1059,  1060,  1061,
      60,   777,   778,   763,   764,   765,  1084,  1389,  1416,  1088,
    1088,     6,     6,     7,    93,   700,   701,     3,   340,  1088,
      73,  1060,  1062,  1063,   305,   783,   784,    10,    11,   779,
     780,   781,    10,    11,   766,   767,   768,   765,  1088,    93,
       8,    10,    11,  1065,  1066,  1067,   160,  1064,  1354,  1383,
    1389,  1398,   301,   861,   862,    24,   785,  1081,     4,    61,
     782,    85,    88,   769,   770,   771,   772,    83,   152,   153,
     155,  1068,  1069,  1070,  1071,  1072,  1073,     8,   297,   923,
     924,    21,   863,  1078,  1088,    10,    11,   786,   787,   788,
      61,    85,   771,   773,   774,     5,  1074,    83,  1070,     6,
     281,   985,   986,    20,   925,  1075,  1088,    10,    11,   864,
     865,   866,     6,   144,   789,   790,   791,    10,    11,   776,
     775,  1389,  1416,   154,     8,    70,  1029,  1030,    28,   987,
    1076,  1088,    10,    11,   926,   927,   928,     6,   144,   867,
     868,   869,  1088,   306,   110,   803,   804,   213,   792,  1360,
      89,    79,    23,  1031,  1080,  1088,    10,    11,   988,   989,
     990,     6,    50,   929,   930,   931,  1088,   302,    44,   881,
     882,   210,   870,  1356,    44,   819,   820,   805,  1360,     8,
      10,    11,   793,   794,   795,  1088,    10,    11,  1032,  1033,
    1034,     6,   283,   991,   992,  1088,   298,    44,   943,   944,
     207,   932,  1350,   894,    10,    11,   883,   884,   885,     8,
      10,    11,   871,   872,   873,   832,    10,    11,   821,   822,
     823,    10,    11,   806,   807,   808,     6,   145,   303,   796,
     797,   798,   799,     6,    68,    71,  1035,  1036,  1037,  1038,
    1088,  1027,    29,   993,  1077,   956,    10,    11,   945,   946,
     947,     8,    10,    11,   933,   934,   935,   339,   895,   896,
     323,   886,   887,  1141,  1142,     6,   145,   299,   874,   875,
     876,   877,   339,   833,   834,   824,   825,  1141,   111,   303,
     809,   810,   811,   812,     8,   145,   798,   800,  1088,    71,
    1037,  1039,  1040,   118,   282,  1028,  1088,    10,    11,   994,
     995,   996,   339,   957,   958,   948,   949,  1141,     6,    51,
     295,   936,   937,   938,   939,   897,   898,    45,   319,   888,
    1147,  1148,   158,  1183,  1352,     8,   145,   876,   878,   835,
     836,    45,   826,  1147,   111,   811,   813,    10,   231,   801,
     802,  1373,  1398,    10,    11,  1042,  1043,  1044,  1041,  1354,
    1383,  1389,  1398,  1422,     6,   144,   998,   999,   959,   960,
      45,   950,  1147,     8,    51,   938,   940,    10,    11,   900,
     901,   902,   159,   165,   166,   171,   172,   183,   184,   899,
    1353,  1356,  1389,  1392,  1393,  1394,  1398,  1401,  1402,  1403,
    1410,  1411,  1412,  1416,  1422,   321,   889,  1153,  1154,  1183,
       8,    10,    11,  1143,  1144,  1145,    10,   879,   880,  1373,
    1398,    10,    11,   838,   839,   840,   185,   186,   837,  1353,
    1360,  1389,  1392,  1398,  1410,  1416,  1422,  1428,  1429,  1430,
     827,  1153,    10,    11,   814,   815,   816,   817,  1373,  1398,
    1086,     8,    69,   152,   153,   155,  1045,  1046,  1047,  1048,
    1049,  1050,  1088,  1006,   217,  1000,  1355,    10,    11,   962,
     963,   964,   181,   182,   961,  1350,  1353,  1386,  1387,  1388,
    1389,  1392,  1398,  1410,  1416,  1422,   951,  1153,    10,   941,
     942,  1373,  1398,   150,   299,   340,   903,   904,   905,   906,
     913,   914,   915,     8,     3,     3,     3,   317,   890,  1159,
    1160,  1183,    10,    11,  1149,  1150,  1151,     6,   156,  1119,
    1120,  1127,  1146,  1086,   150,   303,   340,   841,   842,   843,
     844,   851,   852,   853,     3,   828,  1159,     4,   304,   818,
     304,     6,     5,  1051,    69,  1047,   284,   339,   997,  1007,
    1008,     8,    10,    11,  1001,  1002,  1003,   150,   295,   340,
     965,   966,   967,   968,   975,   976,   977,     3,   952,  1159,
    1086,   340,   905,   907,   914,   916,   917,     6,     8,     8,
       8,   325,   891,  1165,  1166,  1183,    10,    11,  1155,  1156,
    1157,  1119,  1152,     8,   234,  1363,   148,  1121,  1122,   324,
     300,   340,   843,   845,   852,   854,   855,     8,   829,  1165,
     304,     8,   154,  1009,  1010,     6,  1005,   340,   967,   969,
     976,   978,   979,     8,   953,  1165,   296,    10,    11,   908,
     909,   910,   911,  1373,  1398,    10,    11,   919,   920,   921,
     918,  1352,  1389,  1422,     8,   327,   892,  1171,  1172,  1183,
      10,    11,  1161,  1162,  1163,  1119,  1158,   320,     8,    10,
      11,  1128,  1129,  1130,  1123,  1124,    10,    11,   846,   847,
     848,   849,  1373,  1398,    10,    11,   857,   858,   859,   856,
    1352,  1389,  1422,   830,  1171,    10,    11,  1012,  1013,  1014,
     191,   192,  1011,  1353,  1355,  1389,  1392,  1395,  1396,  1397,
    1398,  1410,  1416,  1422,     8,   145,   285,  1004,  1184,  1185,
      10,    11,   970,   971,   972,   973,  1373,  1398,    10,    11,
     981,   982,   983,   980,  1352,  1389,  1422,   954,  1171,     4,
       6,     7,   300,   912,  1087,   922,  1119,   329,   893,  1177,
    1178,  1183,    10,    11,  1167,  1168,  1169,  1119,  1164,   322,
       6,     4,   157,    10,  1126,   232,   233,  1125,  1374,  1376,
     304,   850,  1087,   860,  1119,   831,  1177,   150,   340,  1015,
    1016,  1017,  1018,  1019,  1184,     3,  1186,  1187,   296,   974,
    1087,   984,  1119,   955,  1177,   300,   151,  1183,    10,    11,
    1173,  1174,  1175,  1119,  1170,   318,     8,   157,     6,     8,
       8,   304,   151,   340,  1184,  1018,  1020,  1021,     8,    10,
      11,  1189,  1190,  1191,   195,   196,   202,   203,   228,  1188,
    1349,  1358,  1375,  1398,  1413,  1414,  1415,  1416,   296,   151,
      10,    11,  1179,  1180,  1181,  1119,  1176,   326,   149,     6,
       6,    10,    11,  1023,  1024,  1025,  1022,  1352,  1389,  1422,
     242,  1192,  1193,  1194,     3,     8,     8,  1088,  1119,  1182,
     328,     8,     8,  1026,  1119,   286,  1199,  1195,  1196,     8,
       6,     6,     6,   330,   151,   243,   253,   257,   259,   261,
     263,   265,   279,  1200,  1201,  1202,  1226,  1227,  1239,  1240,
    1266,  1267,  1284,  1285,  1297,  1298,  1315,  1316,  1319,  1320,
      10,    11,  1198,   199,   200,   218,   219,   220,   221,   222,
     223,   224,   225,  1197,  1364,  1365,  1366,  1367,  1368,  1377,
    1378,  1379,  1380,  1381,  1382,     8,     8,  1088,  1203,  1204,
    1228,  1229,  1241,  1242,  1268,  1269,  1286,  1287,  1299,  1300,
     173,   174,  1317,  1407,  1408,  1409,   201,  1321,  1348,   241,
       3,     8,     8,     8,     8,     8,     8,     8,     8,    10,
     197,   198,   205,  1205,  1359,  1404,  1405,  1406,    10,  1230,
    1359,  1404,    10,  1243,  1359,  1404,    10,  1270,  1359,  1404,
      10,  1288,  1359,  1404,    10,  1301,  1359,  1404,     3,    10,
       8,    10,  1322,  1088,     6,     6,     6,     6,     6,     6,
       6,  1086,   271,  1206,  1208,  1209,     3,     8,  1208,  1231,
    1208,  1244,  1208,  1271,  1208,  1289,  1208,  1302,     8,   285,
     289,   293,   409,   411,   413,   415,   417,   419,   421,   423,
     425,   427,   429,   431,   433,   435,   437,   439,  1505,  1506,
    1507,  1510,  1511,  1514,  1515,  1518,  1519,  1522,  1523,  1525,
    1526,  1528,  1529,  1531,  1532,  1534,  1535,  1538,  1539,  1543,
    1544,  1546,  1547,  1549,  1550,  1552,  1553,  1555,  1556,  1558,
    1561,  1562,  1564,  1565,  1567,  1568,     6,   247,  1324,  1325,
       8,     8,     8,     8,     8,     8,     8,     8,   273,  1207,
    1214,  1215,    10,    11,  1210,  1211,  1212,     8,     6,  1214,
    1232,  1214,  1245,  1214,  1272,  1214,  1290,  1214,  1303,  1559,
     280,  1318,   231,  1509,   231,  1513,   231,  1517,   231,  1521,
    1505,  1524,  1505,  1527,   355,   357,   359,   361,   363,   365,
     367,   369,   371,   373,   375,   377,   379,   381,   383,   385,
     387,   389,   391,   393,   395,   397,   399,   401,   403,   405,
     407,  1431,  1432,  1435,  1438,  1440,  1442,  1444,  1446,  1448,
    1450,  1452,  1454,  1456,  1458,  1460,  1462,  1463,  1465,  1467,
    1469,  1471,  1473,  1475,  1476,  1482,  1490,  1493,  1496,  1499,
    1502,  1530,  1505,  1533,   442,  1536,  1542,  1540,  1542,    10,
      11,  1545,  1505,  1548,  1505,  1551,  1505,  1554,  1505,  1557,
    1431,  1563,  1431,  1566,  1505,  1569,     8,   249,  1331,  1332,
    1326,  1352,   254,   275,  1220,  1221,    10,    11,  1216,  1217,
    1218,  1119,  1213,     8,   275,  1233,  1234,   258,   275,  1246,
    1247,   260,   275,  1273,  1274,   266,   275,  1291,  1292,   264,
     275,  1304,  1305,   262,  1560,     8,    10,    11,  1508,     8,
      10,    11,  1512,     8,    10,    11,  1516,     8,    10,    11,
    1520,   410,  1505,  1449,  1441,  1443,  1447,  1451,  1453,  1491,
    1503,  1461,  1445,  1468,  1455,  1457,  1459,  1483,  1466,  1497,
    1494,  1500,  1433,  1436,  1439,  1470,  1472,  1474,   438,  1431,
    1478,   440,     3,    10,    10,   418,  1505,   422,  1505,  1505,
    1505,  1431,   434,  1338,  1333,  1352,    10,    11,  1327,  1328,
    1329,    10,    11,  1222,  1223,  1224,  1119,  1219,   272,    10,
      11,  1235,  1236,  1237,    10,    11,  1248,  1249,  1250,    10,
      11,  1275,  1276,  1277,    10,    11,  1293,  1294,  1295,    10,
      11,  1306,  1307,  1308,   428,  1505,     6,   436,     6,   286,
       6,   290,     6,   294,   412,  1431,  1431,  1431,  1431,  1431,
    1431,  1492,  1504,  1431,  1431,  1431,  1431,  1431,  1431,  1486,
    1431,  1498,  1495,  1501,    10,    11,  1434,    10,    11,  1437,
    1431,  1505,  1505,  1505,   386,  1464,    10,    11,   444,  1416,
    1422,  1477,  1479,  1480,     8,  1505,  1537,  1505,  1541,   420,
     424,   426,   430,  1431,   244,   245,  1323,  1339,  1340,    10,
      11,  1334,  1335,  1336,  1119,  1330,   156,  1131,  1132,  1137,
    1225,   274,  1119,  1238,  1251,  1252,  1278,  1119,  1296,  1309,
       8,     8,     8,     8,  1431,  1431,  1431,  1431,   364,   366,
     368,  1431,   370,  1431,   372,   374,  1431,   378,   380,   382,
      10,    11,   231,   235,  1484,  1487,  1488,  1489,   388,   390,
    1431,   392,  1431,   394,  1431,   396,   398,  1431,   404,   406,
     408,   402,     3,   414,   416,  1431,  1341,  1342,  1119,  1337,
     248,  1363,   148,  1133,  1134,   276,   276,   276,   148,  1253,
    1254,   148,   276,  1279,  1280,   276,   148,   276,  1310,  1311,
     356,   358,   360,   362,  1431,   384,  1431,     8,     8,   400,
    1481,  1505,    10,    11,  1344,  1345,  1346,   226,   227,  1343,
    1369,  1370,  1413,  1416,   250,    10,    11,  1138,  1139,  1140,
    1135,  1376,  1255,  1256,    10,    11,  1281,  1282,  1283,  1312,
     376,  1485,     6,  1086,     8,   432,  1193,  1347,  1088,  1088,
       4,   157,    10,  1136,    10,    11,  1258,  1259,  1260,   214,
     236,  1257,  1361,  1372,  1431,    10,   179,   180,  1313,  1314,
    1374,  1376,  1425,  1426,  1427,   384,     8,     8,  1199,   246,
       6,     6,   157,  1086,  1261,     8,     8,   149,     6,     3,
    1088,  1088,   149,   149,   277,  1262,  1263,     6,  1086,   149,
       8,   235,  1264,  1371,     8,     8,     8,    10,  1265,  1086,
       6,     8,   278
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

  case 1083:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1090:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1097:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1104:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1111:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1118:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1125:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1131:

    {
    osglData->osglCounter = 0;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1132:

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

  case 1133:

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

  case 1134:

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

  case 1146:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1149:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 1150:

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

  case 1151:

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

  case 1166:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++;
}
    break;

  case 1176:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1177:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 1180:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_constant;
    }
    break;

  case 1181:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1185:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1186:

    {
    if (osglData->rowMajor == false)
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1192:

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

  case 1193:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1199:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1200:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1207:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1208:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1211:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_varReference;
    }
    break;

  case 1212:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1216:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1217:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1224:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1225:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 1228:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_linear;
    }
    break;

  case 1229:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1233:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1234:

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

  case 1235:

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

  case 1243:

    {
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}
    break;

  case 1244:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
}
    break;

  case 1245:

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

  case 1257:

    {
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 1259:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}
    break;

  case 1260:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[(2) - (3)].ival);
    osglData->osglCounter++;
}
    break;

  case 1262:

    {
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1263:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 1266:

    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_realValuedExpressions;
    }
    break;

  case 1267:

    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1273:

    {
    osglData->nonzeroCounter = 0;
    osglData->numberOfValues = ((RealValuedExpressions*)osglData->tempC)->numberOfValues;

    ((RealValuedExpressions*)osglData->tempC)->value = new RealValuedExpressionArray();
    ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    ((RealValuedExpressions*)osglData->tempC)->value->el
        = new RealValuedExpressionTree*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((RealValuedExpressions*)osglData->tempC)->value->el[i] = new RealValuedExpressionTree();
}
    break;

  case 1281:

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

  case 1285:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE

        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 1287:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1288:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1291:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_objReference;
    }
    break;

  case 1292:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1296:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1297:

    {
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1304:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1305:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1308:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_conReference;
    }
    break;

  case 1309:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1313:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1314:

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

  case 1315:

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

  case 1322:

    {
//    osglData->nonzeroCounter++;
//    if (osglData->nonzeroCounter > osglData->osglNumberOfNonzeros)
//        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "conReference matrix elements: too many nonzeros");
}
    break;

  case 1323:

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

  case 1329:

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
                "valueType must be one of \"value\", \"status\", \"surplus\", \"shortage\"");
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

  case 1331:

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

  case 1333:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}
    break;

  case 1334:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 1335:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 1336:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}
    break;

  case 1337:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}
    break;

  case 1339:

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

  case 1340:

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

  case 1341:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 1342:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1348:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1349:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 1350:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1357:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}
    break;

  case 1358:

    {
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1359:

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

  case 1365:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    break;

  case 1366:

    {
        ((MatrixBlock*)osglData->tempC)->type
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
    break;

  case 1370:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 1372:

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

  case 1373:

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

  case 1374:

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

  case 1375:

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

  case 1376:

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

  case 1377:

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

  case 1378:

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

  case 1379:

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

  case 1380:

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

  case 1381:

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

  case 1382:

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

  case 1383:

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

  case 1384:

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

  case 1385:

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

  case 1386:

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

  case 1387:

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

  case 1388:

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

  case 1389:

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

  case 1390:

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

  case 1391:

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

  case 1392:

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

  case 1393:

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

  case 1394:

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

  case 1395:

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

  case 1396:

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

  case 1397:

    { 
        if (osglData->idxPresent == true)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one idx attribute");
        osglData->idxPresent = true;
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
        osglData->idx = (yyvsp[(3) - (4)].ival);
    }
    break;

  case 1398:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1399:

    {
    if (osglData->matrixVarIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarIdx attribute in <matrixVar> element");
    osglData->matrixVarIdxPresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "<matrixVarIdx> cannot be negative");
    osglData->matrixVarIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1400:

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

  case 1401:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}
    break;

  case 1402:

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

  case 1403:

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

  case 1406:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}
    break;

  case 1407:

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

  case 1410:

    {
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;
}
    break;

  case 1411:

    { 
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;   
    osglData->category = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1414:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;  
}
    break;

  case 1415:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;   
    osglData->conType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1418:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;
}
    break;

  case 1419:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;   
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1422:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
}
    break;

  case 1423:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
    osglData->enumType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1426:

    {
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
}
    break;

  case 1427:

    {
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
    osglData->matrixVarType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1430:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}
    break;

  case 1431:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1434:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
}
    break;

  case 1435:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
    osglData->objType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1438:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}
    break;

  case 1439:

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

  case 1442:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}
    break;

  case 1443:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1446:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
}
    break;

  case 1447:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
    osglData->solver = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1450:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}
    break;

  case 1451:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1454:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}
    break;

  case 1455:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1458:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
}
    break;

  case 1459:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
    osglData->unit = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1462:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}
    break;

  case 1463:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1466:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}
    break;

  case 1467:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1470:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}
    break;

  case 1471:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1499:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1503:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1507:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1509:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1511:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1513:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1515:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1517:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1519:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1521:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1523:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1525:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1527:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1529:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1532:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1533:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1534:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1535:

    {
}
    break;

  case 1536:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1537:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1538:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1540:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1542:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1544:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}
    break;

  case 1545:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 1550:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }
    break;

  case 1551:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }
    break;

  case 1553:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 1555:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 1556:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 1559:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
        }
    break;

  case 1563:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 1564:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 1565:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 1566:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1567:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1568:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 1570:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 1571:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1572:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1574:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 1575:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1576:

    {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1578:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 1579:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1580:

    {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1582:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 1583:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1584:

    {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 1586:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 1606:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1607:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
}
    break;

  case 1610:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1611:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1612:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 1615:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1616:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1617:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 1620:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1621:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1622:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 1625:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1627:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1630:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1633:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1636:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1639:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1641:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1644:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1646:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1648:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1650:

    {
     parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 1654:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1657:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1660:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1663:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1665:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1666:

    {
    osnlData->matrixProductVec.back()->m_mMatrixChildren = new OSnLMNode*[ osnlData->matrixProductVec.back()->inumberOfMatrixChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 1668:

    { 
    osnlData->matrixProductVec.back()->inumberOfMatrixChildren++; 
}
    break;

  case 1670:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1673:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1676:

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


