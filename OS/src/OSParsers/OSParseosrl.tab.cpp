
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
     VARREFERENCEELEMENTSSTART = 510,
     VARREFERENCEELEMENTSEND = 511,
     LINEARELEMENTSSTART = 512,
     LINEARELEMENTSEND = 513,
     GENERALELEMENTSSTART = 514,
     GENERALELEMENTSEND = 515,
     CONREFERENCEELEMENTSSTART = 516,
     CONREFERENCEELEMENTSEND = 517,
     OBJREFERENCEELEMENTSSTART = 518,
     OBJREFERENCEELEMENTSEND = 519,
     STRINGVALUEDELEMENTSSTART = 520,
     STRINGVALUEDELEMENTSEND = 521,
     STARTVECTORSTART = 522,
     STARTVECTOREND = 523,
     INDEXSTART = 524,
     INDEXEND = 525,
     VALUESTART = 526,
     VALUEEND = 527,
     VARIDXSTART = 528,
     VARIDXEND = 529,
     TRANSFORMATIONSTART = 530,
     TRANSFORMATIONEND = 531,
     MATRIXPROGRAMMINGSTART = 532,
     MATRIXPROGRAMMINGEND = 533,
     MATRIXVARIABLESSTART = 534,
     MATRIXVARIABLESEND = 535,
     MATRIXVARSTART = 536,
     MATRIXVAREND = 537,
     MATRIXOBJECTIVESSTART = 538,
     MATRIXOBJECTIVESEND = 539,
     MATRIXOBJSTART = 540,
     MATRIXOBJEND = 541,
     MATRIXCONSTRAINTSSTART = 542,
     MATRIXCONSTRAINTSEND = 543,
     MATRIXCONSTART = 544,
     MATRIXCONEND = 545,
     CONSTART = 546,
     CONEND = 547,
     CONSTRAINTSSTART = 548,
     CONSTRAINTSEND = 549,
     OBJSTART = 550,
     OBJEND = 551,
     OBJECTIVESSTART = 552,
     OBJECTIVESEND = 553,
     VARSTART = 554,
     VAREND = 555,
     VARIABLESSTART = 556,
     VARIABLESEND = 557,
     GENERALSTART = 558,
     GENERALEND = 559,
     SYSTEMSTART = 560,
     SYSTEMEND = 561,
     SERVICESTART = 562,
     SERVICEEND = 563,
     JOBSTART = 564,
     JOBEND = 565,
     OPTIMIZATIONSTART = 566,
     OPTIMIZATIONEND = 567,
     ATEQUALITYSTART = 568,
     ATEQUALITYEND = 569,
     ATLOWERSTART = 570,
     ATLOWEREND = 571,
     ATUPPERSTART = 572,
     ATUPPEREND = 573,
     BASICSTART = 574,
     BASICEND = 575,
     ISFREESTART = 576,
     ISFREEEND = 577,
     SUPERBASICSTART = 578,
     SUPERBASICEND = 579,
     UNKNOWNSTART = 580,
     UNKNOWNEND = 581,
     SERVICEURISTART = 582,
     SERVICEURIEND = 583,
     SERVICENAMESTART = 584,
     SERVICENAMEEND = 585,
     INSTANCENAMESTART = 586,
     INSTANCENAMEEND = 587,
     JOBIDSTART = 588,
     JOBIDEND = 589,
     OTHERSTART = 590,
     OTHEREND = 591,
     DUMMY = 592,
     NONLINEAREXPRESSIONSSTART = 593,
     NONLINEAREXPRESSIONSEND = 594,
     NUMBEROFNONLINEAREXPRESSIONS = 595,
     NLSTART = 596,
     NLEND = 597,
     MATRIXEXPRESSIONSSTART = 598,
     MATRIXEXPRESSIONSEND = 599,
     NUMBEROFEXPR = 600,
     EXPRSTART = 601,
     EXPREND = 602,
     NUMBEROFMATRIXTERMSATT = 603,
     MATRIXTERMSTART = 604,
     MATRIXTERMEND = 605,
     POWERSTART = 606,
     POWEREND = 607,
     PLUSSTART = 608,
     PLUSEND = 609,
     MINUSSTART = 610,
     MINUSEND = 611,
     DIVIDESTART = 612,
     DIVIDEEND = 613,
     LNSTART = 614,
     LNEND = 615,
     SQRTSTART = 616,
     SQRTEND = 617,
     SUMSTART = 618,
     SUMEND = 619,
     PRODUCTSTART = 620,
     PRODUCTEND = 621,
     EXPSTART = 622,
     EXPEND = 623,
     NEGATESTART = 624,
     NEGATEEND = 625,
     IFSTART = 626,
     IFEND = 627,
     SQUARESTART = 628,
     SQUAREEND = 629,
     COSSTART = 630,
     COSEND = 631,
     SINSTART = 632,
     SINEND = 633,
     VARIABLESTART = 634,
     VARIABLEEND = 635,
     ABSSTART = 636,
     ABSEND = 637,
     ERFSTART = 638,
     ERFEND = 639,
     MAXSTART = 640,
     MAXEND = 641,
     ALLDIFFSTART = 642,
     ALLDIFFEND = 643,
     MINSTART = 644,
     MINEND = 645,
     ESTART = 646,
     EEND = 647,
     PISTART = 648,
     PIEND = 649,
     TIMESSTART = 650,
     TIMESEND = 651,
     NUMBERSTART = 652,
     NUMBEREND = 653,
     MATRIXDETERMINANTSTART = 654,
     MATRIXDETERMINANTEND = 655,
     MATRIXTRACESTART = 656,
     MATRIXTRACEEND = 657,
     MATRIXTOSCALARSTART = 658,
     MATRIXTOSCALAREND = 659,
     MATRIXDIAGONALSTART = 660,
     MATRIXDIAGONALEND = 661,
     MATRIXDOTTIMESSTART = 662,
     MATRIXDOTTIMESEND = 663,
     MATRIXLOWERTRIANGLESTART = 664,
     MATRIXLOWERTRIANGLEEND = 665,
     MATRIXUPPERTRIANGLESTART = 666,
     MATRIXUPPERTRIANGLEEND = 667,
     MATRIXMERGESTART = 668,
     MATRIXMERGEEND = 669,
     MATRIXMINUSSTART = 670,
     MATRIXMINUSEND = 671,
     MATRIXNEGATESTART = 672,
     MATRIXNEGATEEND = 673,
     MATRIXPLUSSTART = 674,
     MATRIXPLUSEND = 675,
     MATRIXTIMESSTART = 676,
     MATRIXTIMESEND = 677,
     MATRIXPRODUCTSTART = 678,
     MATRIXPRODUCTEND = 679,
     MATRIXSCALARTIMESSTART = 680,
     MATRIXSCALARTIMESEND = 681,
     MATRIXSUBMATRIXATSTART = 682,
     MATRIXSUBMATRIXATEND = 683,
     MATRIXTRANSPOSESTART = 684,
     MATRIXTRANSPOSEEND = 685,
     MATRIXREFERENCESTART = 686,
     MATRIXREFERENCEEND = 687,
     IDENTITYMATRIXSTART = 688,
     IDENTITYMATRIXEND = 689,
     MATRIXINVERSESTART = 690,
     MATRIXINVERSEEND = 691,
     EMPTYINCLUDEDIAGONALATT = 692,
     INCLUDEDIAGONALATT = 693,
     EMPTYIDATT = 694,
     IDATT = 695
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
#define VARREFERENCEELEMENTSSTART 510
#define VARREFERENCEELEMENTSEND 511
#define LINEARELEMENTSSTART 512
#define LINEARELEMENTSEND 513
#define GENERALELEMENTSSTART 514
#define GENERALELEMENTSEND 515
#define CONREFERENCEELEMENTSSTART 516
#define CONREFERENCEELEMENTSEND 517
#define OBJREFERENCEELEMENTSSTART 518
#define OBJREFERENCEELEMENTSEND 519
#define STRINGVALUEDELEMENTSSTART 520
#define STRINGVALUEDELEMENTSEND 521
#define STARTVECTORSTART 522
#define STARTVECTOREND 523
#define INDEXSTART 524
#define INDEXEND 525
#define VALUESTART 526
#define VALUEEND 527
#define VARIDXSTART 528
#define VARIDXEND 529
#define TRANSFORMATIONSTART 530
#define TRANSFORMATIONEND 531
#define MATRIXPROGRAMMINGSTART 532
#define MATRIXPROGRAMMINGEND 533
#define MATRIXVARIABLESSTART 534
#define MATRIXVARIABLESEND 535
#define MATRIXVARSTART 536
#define MATRIXVAREND 537
#define MATRIXOBJECTIVESSTART 538
#define MATRIXOBJECTIVESEND 539
#define MATRIXOBJSTART 540
#define MATRIXOBJEND 541
#define MATRIXCONSTRAINTSSTART 542
#define MATRIXCONSTRAINTSEND 543
#define MATRIXCONSTART 544
#define MATRIXCONEND 545
#define CONSTART 546
#define CONEND 547
#define CONSTRAINTSSTART 548
#define CONSTRAINTSEND 549
#define OBJSTART 550
#define OBJEND 551
#define OBJECTIVESSTART 552
#define OBJECTIVESEND 553
#define VARSTART 554
#define VAREND 555
#define VARIABLESSTART 556
#define VARIABLESEND 557
#define GENERALSTART 558
#define GENERALEND 559
#define SYSTEMSTART 560
#define SYSTEMEND 561
#define SERVICESTART 562
#define SERVICEEND 563
#define JOBSTART 564
#define JOBEND 565
#define OPTIMIZATIONSTART 566
#define OPTIMIZATIONEND 567
#define ATEQUALITYSTART 568
#define ATEQUALITYEND 569
#define ATLOWERSTART 570
#define ATLOWEREND 571
#define ATUPPERSTART 572
#define ATUPPEREND 573
#define BASICSTART 574
#define BASICEND 575
#define ISFREESTART 576
#define ISFREEEND 577
#define SUPERBASICSTART 578
#define SUPERBASICEND 579
#define UNKNOWNSTART 580
#define UNKNOWNEND 581
#define SERVICEURISTART 582
#define SERVICEURIEND 583
#define SERVICENAMESTART 584
#define SERVICENAMEEND 585
#define INSTANCENAMESTART 586
#define INSTANCENAMEEND 587
#define JOBIDSTART 588
#define JOBIDEND 589
#define OTHERSTART 590
#define OTHEREND 591
#define DUMMY 592
#define NONLINEAREXPRESSIONSSTART 593
#define NONLINEAREXPRESSIONSEND 594
#define NUMBEROFNONLINEAREXPRESSIONS 595
#define NLSTART 596
#define NLEND 597
#define MATRIXEXPRESSIONSSTART 598
#define MATRIXEXPRESSIONSEND 599
#define NUMBEROFEXPR 600
#define EXPRSTART 601
#define EXPREND 602
#define NUMBEROFMATRIXTERMSATT 603
#define MATRIXTERMSTART 604
#define MATRIXTERMEND 605
#define POWERSTART 606
#define POWEREND 607
#define PLUSSTART 608
#define PLUSEND 609
#define MINUSSTART 610
#define MINUSEND 611
#define DIVIDESTART 612
#define DIVIDEEND 613
#define LNSTART 614
#define LNEND 615
#define SQRTSTART 616
#define SQRTEND 617
#define SUMSTART 618
#define SUMEND 619
#define PRODUCTSTART 620
#define PRODUCTEND 621
#define EXPSTART 622
#define EXPEND 623
#define NEGATESTART 624
#define NEGATEEND 625
#define IFSTART 626
#define IFEND 627
#define SQUARESTART 628
#define SQUAREEND 629
#define COSSTART 630
#define COSEND 631
#define SINSTART 632
#define SINEND 633
#define VARIABLESTART 634
#define VARIABLEEND 635
#define ABSSTART 636
#define ABSEND 637
#define ERFSTART 638
#define ERFEND 639
#define MAXSTART 640
#define MAXEND 641
#define ALLDIFFSTART 642
#define ALLDIFFEND 643
#define MINSTART 644
#define MINEND 645
#define ESTART 646
#define EEND 647
#define PISTART 648
#define PIEND 649
#define TIMESSTART 650
#define TIMESEND 651
#define NUMBERSTART 652
#define NUMBEREND 653
#define MATRIXDETERMINANTSTART 654
#define MATRIXDETERMINANTEND 655
#define MATRIXTRACESTART 656
#define MATRIXTRACEEND 657
#define MATRIXTOSCALARSTART 658
#define MATRIXTOSCALAREND 659
#define MATRIXDIAGONALSTART 660
#define MATRIXDIAGONALEND 661
#define MATRIXDOTTIMESSTART 662
#define MATRIXDOTTIMESEND 663
#define MATRIXLOWERTRIANGLESTART 664
#define MATRIXLOWERTRIANGLEEND 665
#define MATRIXUPPERTRIANGLESTART 666
#define MATRIXUPPERTRIANGLEEND 667
#define MATRIXMERGESTART 668
#define MATRIXMERGEEND 669
#define MATRIXMINUSSTART 670
#define MATRIXMINUSEND 671
#define MATRIXNEGATESTART 672
#define MATRIXNEGATEEND 673
#define MATRIXPLUSSTART 674
#define MATRIXPLUSEND 675
#define MATRIXTIMESSTART 676
#define MATRIXTIMESEND 677
#define MATRIXPRODUCTSTART 678
#define MATRIXPRODUCTEND 679
#define MATRIXSCALARTIMESSTART 680
#define MATRIXSCALARTIMESEND 681
#define MATRIXSUBMATRIXATSTART 682
#define MATRIXSUBMATRIXATEND 683
#define MATRIXTRANSPOSESTART 684
#define MATRIXTRANSPOSEEND 685
#define MATRIXREFERENCESTART 686
#define MATRIXREFERENCEEND 687
#define IDENTITYMATRIXSTART 688
#define IDENTITYMATRIXEND 689
#define MATRIXINVERSESTART 690
#define MATRIXINVERSEEND 691
#define EMPTYINCLUDEDIAGONALATT 692
#define INCLUDEDIAGONALATT 693
#define EMPTYIDATT 694
#define IDATT 695




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
#define YYNTOKENS  445
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  1121
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1677
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2353

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   695

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   442,
     444,     2,     2,   443,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   441,     2,     2,     2,     2,     2,     2,     2,
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
     435,   436,   437,   438,   439,   440
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
     446,     0,    -1,   447,   455,   453,    -1,   448,   449,   450,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   451,    -1,
     452,    -1,    11,    -1,    10,   455,   453,    -1,   454,    -1,
      15,    -1,    -1,   456,   457,   537,   591,   643,   738,    -1,
      -1,  1087,    -1,    -1,   458,   459,    -1,   303,    -1,   460,
      -1,   461,    -1,    10,   304,    -1,    11,    -1,    10,   462,
     304,    -1,   463,    -1,   464,    -1,   463,   464,    -1,   465,
      -1,   481,    -1,   487,    -1,   493,    -1,   499,    -1,   505,
      -1,   511,    -1,   517,    -1,   523,    -1,   466,   467,   470,
      -1,    56,    -1,   468,    -1,   469,    -1,   468,   469,    -1,
    1412,    -1,  1385,    -1,  1080,    -1,   471,    -1,   472,    -1,
      10,    57,    -1,    11,    -1,    10,   473,    57,    -1,   474,
      -1,   475,    -1,   474,   475,    -1,   476,   477,   480,    -1,
      88,    -1,   478,    -1,    -1,   478,   479,    -1,  1394,    -1,
    1385,    -1,    10,    89,    -1,    11,    -1,   482,   483,    -1,
      60,    -1,   484,    -1,   485,    -1,    10,    61,    -1,    11,
      -1,    10,   486,    61,    -1,     4,    -1,   488,   489,    -1,
     327,    -1,   490,    -1,   491,    -1,    10,   328,    -1,    11,
      -1,    10,   492,   328,    -1,     4,    -1,   494,   495,    -1,
     329,    -1,   496,    -1,   497,    -1,    10,   330,    -1,    11,
      -1,    10,   498,   330,    -1,     4,    -1,   500,   501,    -1,
     331,    -1,   502,    -1,   503,    -1,    10,   332,    -1,    11,
      -1,    10,   504,   332,    -1,     4,    -1,   506,   507,    -1,
     333,    -1,   508,    -1,   509,    -1,    10,   334,    -1,    11,
      -1,    10,   510,   334,    -1,     4,    -1,   512,   513,    -1,
      80,    -1,   514,    -1,   515,    -1,    10,    81,    -1,    11,
      -1,    10,   516,    81,    -1,     4,    -1,   518,   519,    -1,
      96,    -1,   520,    -1,   521,    -1,    10,    97,    -1,    11,
      -1,    10,   522,    97,    -1,     4,    -1,   524,   525,   526,
      -1,    66,    -1,  1075,    -1,   527,    -1,   528,    -1,    10,
      67,    -1,    11,    -1,    10,   529,    67,    -1,   530,    -1,
     531,    -1,   530,   531,    -1,   532,   533,   536,    -1,   335,
      -1,   534,    -1,    -1,   534,   535,    -1,  1394,    -1,  1418,
      -1,  1385,    -1,    10,   336,    -1,    11,    -1,    -1,   538,
     539,    -1,   305,    -1,   540,    -1,   541,    -1,    10,   306,
      -1,    11,    -1,    10,   542,   306,    -1,   543,    -1,   544,
      -1,   543,   544,    -1,   545,    -1,   551,    -1,   558,    -1,
     565,    -1,   572,    -1,   577,    -1,   546,   547,    -1,    90,
      -1,   548,    -1,   549,    -1,    10,    91,    -1,    11,    -1,
      10,   550,    91,    -1,     4,    -1,   552,   553,   556,    -1,
      40,    -1,   554,    -1,    -1,   554,   555,    -1,  1415,    -1,
    1385,    -1,    10,   557,    41,    -1,  1082,    -1,   559,   560,
     563,    -1,    42,    -1,   561,    -1,    -1,   561,   562,    -1,
    1415,    -1,  1385,    -1,    10,   564,    43,    -1,  1082,    -1,
     566,   567,   570,    -1,    38,    -1,   568,    -1,    -1,   568,
     569,    -1,  1415,    -1,  1385,    -1,    10,   571,    39,    -1,
    1082,    -1,   573,   574,   575,    -1,    36,    -1,    -1,  1385,
      -1,    10,   576,    37,    -1,     6,    -1,   578,   579,   580,
      -1,    66,    -1,  1075,    -1,   581,    -1,   582,    -1,    10,
      67,    -1,    11,    -1,    10,   583,    67,    -1,   584,    -1,
     585,    -1,   584,   585,    -1,   586,   587,   590,    -1,   335,
      -1,   588,    -1,    -1,   588,   589,    -1,  1394,    -1,  1418,
      -1,  1385,    -1,    10,   336,    -1,    11,    -1,    -1,   592,
     593,    -1,   307,    -1,   594,    -1,   595,    -1,    10,   308,
      -1,    11,    -1,    10,   596,   308,    -1,   597,    -1,   598,
      -1,   597,   598,    -1,   599,    -1,   605,    -1,   611,    -1,
     617,    -1,   623,    -1,   629,    -1,   600,   601,    -1,    48,
      -1,   602,    -1,   603,    -1,    10,    49,    -1,    11,    -1,
      10,   604,    49,    -1,     4,    -1,   606,   607,    -1,    46,
      -1,   608,    -1,   609,    -1,    10,    47,    -1,    11,    -1,
      10,   610,    47,    -1,     6,    -1,   612,   613,    -1,   100,
      -1,   614,    -1,   615,    -1,    10,   101,    -1,    11,    -1,
      10,   616,   101,    -1,     6,    -1,   618,   619,    -1,    94,
      -1,   620,    -1,   621,    -1,    10,    95,    -1,    11,    -1,
      10,   622,    95,    -1,     4,    -1,   624,   625,    -1,    76,
      -1,   626,    -1,   627,    -1,    10,    77,    -1,    11,    -1,
      10,   628,    77,    -1,  1082,    -1,   630,   631,   632,    -1,
      66,    -1,  1075,    -1,   633,    -1,   634,    -1,    10,    67,
      -1,    11,    -1,    10,   635,    67,    -1,   636,    -1,   637,
      -1,   636,   637,    -1,   638,   639,   642,    -1,   335,    -1,
     640,    -1,    -1,   640,   641,    -1,  1394,    -1,  1418,    -1,
    1385,    -1,    10,   336,    -1,    11,    -1,    -1,   644,   645,
      -1,   309,    -1,   646,    -1,   647,    -1,    10,   310,    -1,
      11,    -1,    10,   648,   310,    -1,   649,    -1,   650,    -1,
     649,   650,    -1,   651,    -1,   657,    -1,   663,    -1,   669,
      -1,   675,    -1,   681,    -1,   698,    -1,   705,    -1,   712,
      -1,   719,    -1,   724,    -1,   652,   653,    -1,    84,    -1,
     654,    -1,   655,    -1,    10,    85,    -1,    11,    -1,    10,
     656,    85,    -1,     4,    -1,   658,   659,    -1,    86,    -1,
     660,    -1,   661,    -1,    10,    87,    -1,    11,    -1,    10,
     662,    87,    -1,     4,    -1,   664,   665,    -1,    74,    -1,
     666,    -1,   667,    -1,    10,    75,    -1,    11,    -1,    10,
     668,    75,    -1,     4,    -1,   670,   671,    -1,    34,    -1,
     672,    -1,   673,    -1,    10,    35,    -1,    11,    -1,    10,
     674,    35,    -1,     4,    -1,   676,   677,    -1,    52,    -1,
     678,    -1,   679,    -1,    10,    53,    -1,    11,    -1,    10,
     680,    53,    -1,     4,    -1,   682,   683,   684,    -1,    98,
      -1,  1081,    -1,   685,    -1,   686,    -1,    10,    99,    -1,
      11,    -1,    10,   687,    99,    -1,   688,    -1,   689,    -1,
     688,   689,    -1,   690,   691,   693,    -1,    92,    -1,    -1,
     691,   692,    -1,  1415,    -1,  1412,    -1,  1379,    -1,  1385,
      -1,   694,    -1,   695,    -1,    10,    93,    -1,    11,    -1,
      10,   696,    93,    -1,   697,    -1,     7,    -1,     6,    -1,
     699,   700,   703,    -1,   106,    -1,   701,    -1,    -1,   701,
     702,    -1,  1415,    -1,  1385,    -1,    10,   704,   107,    -1,
    1082,    -1,   706,   707,   710,    -1,   108,    -1,   708,    -1,
      -1,   708,   709,    -1,  1415,    -1,  1385,    -1,    10,   711,
     109,    -1,  1082,    -1,   713,   714,   717,    -1,   104,    -1,
     715,    -1,    -1,   715,   716,    -1,  1415,    -1,  1385,    -1,
      10,   718,   105,    -1,  1082,    -1,   720,   721,   722,    -1,
     102,    -1,    -1,  1385,    -1,    10,   723,   103,    -1,     6,
      -1,   725,   726,   727,    -1,    66,    -1,  1075,    -1,   728,
      -1,   729,    -1,    10,    67,    -1,    11,    -1,    10,   730,
      67,    -1,   731,    -1,   732,    -1,   731,   732,    -1,   733,
     734,   737,    -1,   335,    -1,   735,    -1,    -1,   735,   736,
      -1,  1394,    -1,  1418,    -1,  1385,    -1,    10,   336,    -1,
      11,    -1,    -1,   739,   740,   743,    -1,   311,    -1,   741,
      -1,    -1,   741,   742,    -1,  1078,    -1,  1358,    -1,  1347,
      -1,  1353,    -1,   744,    -1,   745,    -1,    10,   312,    -1,
      11,    -1,    10,   746,   312,    -1,   747,  1048,    -1,   748,
      -1,   747,   748,    -1,   749,   750,   756,    -1,    78,    -1,
     751,    -1,    -1,   751,   752,    -1,   753,    -1,   754,    -1,
     755,    -1,    33,  1084,     6,  1084,    -1,    18,     3,  1084,
      -1,    16,     3,  1084,    -1,    10,   757,   773,   779,   857,
     919,   981,  1025,    79,    -1,   758,   759,   762,    -1,    84,
      -1,   760,    -1,   761,    -1,   760,   761,    -1,  1412,    -1,
    1385,    -1,  1080,    -1,   763,    -1,   764,    -1,    10,    85,
      -1,    11,    -1,    10,   765,    85,    -1,   766,    -1,   767,
      -1,   766,   767,    -1,   768,   769,   772,    -1,    88,    -1,
     770,    -1,    -1,   770,   771,    -1,  1412,    -1,  1385,    -1,
      10,    89,    -1,    11,    -1,    -1,   774,   775,    -1,    60,
      -1,   776,    -1,   777,    -1,    10,    61,    -1,    11,    -1,
      10,   778,    61,    -1,     4,    -1,    -1,   780,   781,   782,
      -1,   301,    -1,    -1,  1077,    -1,   783,    -1,   784,    -1,
      11,    -1,    10,   785,   302,    -1,   786,   799,   815,   828,
      -1,    -1,   787,   788,   789,    -1,   144,    -1,  1356,    -1,
     790,    -1,   791,    -1,    10,   145,    -1,    11,    -1,    10,
     792,   145,    -1,   793,    -1,   794,    -1,   793,   794,    -1,
     795,   796,   798,    -1,   299,    -1,    -1,   796,   797,    -1,
    1369,    -1,  1394,    -1,    10,  1082,   300,    -1,    -1,   800,
     801,   802,    -1,   110,    -1,  1356,    -1,   803,    -1,   804,
      -1,    10,   111,    -1,    11,    -1,    10,   805,   111,    -1,
     806,    -1,   807,    -1,   806,   807,    -1,   808,   809,   811,
      -1,   299,    -1,    -1,   809,   810,    -1,  1369,    -1,  1394,
      -1,   812,    -1,   813,    -1,    10,   300,    -1,    11,    -1,
      10,   814,   300,    -1,     4,    -1,    -1,   816,   817,    -1,
      44,    -1,   818,    -1,   819,    -1,    11,    -1,    10,   820,
      45,    -1,   821,   822,   823,   824,   825,   826,   827,    -1,
      -1,  1137,    -1,    -1,  1143,    -1,    -1,  1149,    -1,    -1,
    1155,    -1,    -1,  1161,    -1,    -1,  1167,    -1,    -1,  1173,
      -1,    -1,   828,   829,    -1,   830,   831,   834,    -1,   335,
      -1,   832,    -1,    -1,   832,   833,    -1,  1356,    -1,  1349,
      -1,  1418,    -1,  1406,    -1,  1394,    -1,  1412,    -1,  1424,
      -1,  1388,    -1,  1385,    -1,   835,    -1,   836,    -1,    10,
     336,    -1,    11,    -1,    10,   837,   336,    -1,   838,    -1,
     847,    -1,   839,    -1,   838,   839,    -1,   840,   841,   843,
      -1,   299,    -1,    -1,   841,   842,    -1,  1369,    -1,  1394,
      -1,   844,    -1,   845,    -1,    10,   300,    -1,    11,    -1,
      10,   846,   300,    -1,  1083,    -1,   848,    -1,   847,   848,
      -1,   849,   850,   853,    -1,   150,    -1,   851,    -1,    -1,
     851,   852,    -1,  1348,    -1,  1418,    -1,  1385,    -1,   854,
      -1,   855,    -1,    11,    -1,    10,   856,   151,    -1,  1115,
      -1,    -1,   858,   859,   860,    -1,   297,    -1,    -1,  1074,
      -1,   861,    -1,   862,    -1,    11,    -1,    10,   863,   298,
      -1,   864,   877,   890,    -1,    -1,   865,   866,   867,    -1,
     144,    -1,  1352,    -1,   868,    -1,   869,    -1,    10,   145,
      -1,    11,    -1,    10,   870,   145,    -1,   871,    -1,   872,
      -1,   871,   872,    -1,   873,   874,   876,    -1,   295,    -1,
      -1,   874,   875,    -1,  1369,    -1,  1394,    -1,    10,  1082,
     296,    -1,    -1,   878,   879,    -1,    44,    -1,   880,    -1,
     881,    -1,    11,    -1,    10,   882,    45,    -1,   883,   884,
     885,   886,   887,   888,   889,    -1,    -1,  1137,    -1,    -1,
    1143,    -1,    -1,  1149,    -1,    -1,  1155,    -1,    -1,  1161,
      -1,    -1,  1167,    -1,    -1,  1173,    -1,    -1,   890,   891,
      -1,   892,   893,   896,    -1,   335,    -1,   894,    -1,    -1,
     894,   895,    -1,  1352,    -1,  1349,    -1,  1418,    -1,  1406,
      -1,  1394,    -1,  1412,    -1,  1397,    -1,  1388,    -1,  1385,
      -1,   897,    -1,   898,    -1,    10,   336,    -1,    11,    -1,
      10,   899,   336,    -1,   900,    -1,   909,    -1,   901,    -1,
     900,   901,    -1,   902,   903,   905,    -1,   295,    -1,    -1,
     903,   904,    -1,  1369,    -1,  1394,    -1,   906,    -1,   907,
      -1,    10,   296,    -1,    11,    -1,    10,   908,   296,    -1,
    1083,    -1,   910,    -1,   909,   910,    -1,   911,   912,   915,
      -1,   150,    -1,   913,    -1,    -1,   913,   914,    -1,  1348,
      -1,  1418,    -1,  1385,    -1,   916,    -1,   917,    -1,    11,
      -1,    10,   918,   151,    -1,  1115,    -1,    -1,   920,   921,
     922,    -1,   293,    -1,    -1,  1071,    -1,   923,    -1,   924,
      -1,    11,    -1,    10,   925,   294,    -1,   926,   939,   952,
      -1,    -1,   927,   928,   929,    -1,    50,    -1,  1346,    -1,
     930,    -1,   931,    -1,    10,    51,    -1,    11,    -1,    10,
     932,    51,    -1,   933,    -1,   934,    -1,   933,   934,    -1,
     935,   936,   938,    -1,   291,    -1,    -1,   936,   937,    -1,
    1369,    -1,  1394,    -1,    10,  1082,   292,    -1,    -1,   940,
     941,    -1,    44,    -1,   942,    -1,   943,    -1,    11,    -1,
      10,   944,    45,    -1,   945,   946,   947,   948,   949,   950,
     951,    -1,    -1,  1137,    -1,    -1,  1143,    -1,    -1,  1149,
      -1,    -1,  1155,    -1,    -1,  1161,    -1,    -1,  1167,    -1,
      -1,  1173,    -1,    -1,   952,   953,    -1,   954,   955,   958,
      -1,   335,    -1,   956,    -1,    -1,   956,   957,    -1,  1346,
      -1,  1349,    -1,  1418,    -1,  1406,    -1,  1394,    -1,  1412,
      -1,  1382,    -1,  1388,    -1,  1385,    -1,   959,    -1,   960,
      -1,    10,   336,    -1,    11,    -1,    10,   961,   336,    -1,
     962,    -1,   971,    -1,   963,    -1,   962,   963,    -1,   964,
     965,   967,    -1,   291,    -1,    -1,   965,   966,    -1,  1369,
      -1,  1394,    -1,   968,    -1,   969,    -1,    10,   292,    -1,
      11,    -1,    10,   970,   292,    -1,  1083,    -1,   972,    -1,
     971,   972,    -1,   973,   974,   977,    -1,   150,    -1,   975,
      -1,    -1,   975,   976,    -1,  1348,    -1,  1418,    -1,  1385,
      -1,   978,    -1,   979,    -1,    11,    -1,    10,   980,   151,
      -1,  1115,    -1,    -1,   982,   983,   984,    -1,   277,    -1,
      -1,  1072,    -1,   985,    -1,   986,    -1,    11,    -1,    10,
     987,  1023,   278,    -1,    -1,   988,   989,   990,    -1,   279,
      -1,  1073,    -1,   991,    -1,   992,    -1,    11,    -1,    10,
     994,  1002,   993,    -1,   280,    -1,    -1,   995,   996,   997,
      -1,   144,    -1,  1351,    -1,   998,    -1,   999,    -1,    11,
      -1,    10,  1001,  1000,    -1,   145,    -1,    -1,  1001,  1180,
      -1,    -1,  1002,  1003,    -1,  1004,  1005,  1008,    -1,   335,
      -1,  1006,    -1,    -1,  1006,  1007,    -1,  1351,    -1,  1349,
      -1,  1418,    -1,  1406,    -1,  1394,    -1,  1412,    -1,  1391,
      -1,  1388,    -1,  1385,    -1,  1009,    -1,  1010,    -1,    10,
     336,    -1,    11,    -1,    10,  1011,   336,    -1,  1013,    -1,
    1012,    -1,  1180,    -1,  1012,  1180,    -1,  1014,    -1,  1013,
    1014,    -1,  1015,  1016,  1019,    -1,   150,    -1,  1017,    -1,
      -1,  1017,  1018,    -1,  1348,    -1,  1418,    -1,  1385,    -1,
    1020,    -1,  1021,    -1,    11,    -1,    10,  1022,   151,    -1,
    1115,    -1,    -1,  1023,  1024,    -1,   118,    -1,    -1,  1026,
    1027,  1028,    -1,    70,    -1,  1076,    -1,  1029,    -1,  1030,
      -1,    10,    71,    -1,    11,    -1,    10,  1031,    71,    -1,
    1032,    -1,  1033,    -1,  1032,  1033,    -1,  1034,  1035,  1038,
      -1,    68,    -1,  1036,    -1,    -1,  1036,  1037,    -1,  1394,
      -1,  1418,    -1,  1379,    -1,  1385,    -1,  1350,    -1,  1039,
      -1,  1040,    -1,    10,    69,    -1,    11,    -1,    10,  1041,
      69,    -1,  1042,    -1,  1043,    -1,  1042,  1043,    -1,  1044,
      -1,  1045,    -1,  1046,    -1,   155,    -1,   152,    -1,   153,
    1047,   154,    -1,     5,    -1,    -1,  1049,  1050,  1051,    -1,
      72,    -1,  1079,    -1,  1052,    -1,  1053,    -1,    10,    73,
      -1,    11,    -1,    10,  1054,    73,    -1,  1055,    -1,  1056,
      -1,  1055,  1056,    -1,  1057,  1058,  1061,    -1,    82,    -1,
    1059,    -1,    -1,  1059,  1060,    -1,  1394,    -1,  1379,    -1,
    1385,    -1,  1350,    -1,  1062,    -1,  1063,    -1,    10,    83,
      -1,    11,    -1,    10,  1064,    83,    -1,  1065,    -1,  1066,
      -1,  1065,  1066,    -1,  1067,    -1,  1068,    -1,  1069,    -1,
     155,    -1,   152,    -1,   153,  1070,   154,    -1,     5,    -1,
      20,  1084,     6,  1084,    -1,    28,  1084,     6,  1084,    -1,
      29,  1084,     6,  1084,    -1,    21,  1084,     6,  1084,    -1,
      22,  1084,     6,  1084,    -1,    23,  1084,     6,  1084,    -1,
      24,  1084,     6,  1084,    -1,    25,  1084,     6,  1084,    -1,
      30,  1084,     6,  1084,    -1,    31,  1084,     6,  1084,    -1,
      32,  1084,     6,  1084,    -1,     6,    -1,     7,    -1,     4,
      -1,     6,    -1,     7,    -1,  1085,     8,    -1,    -1,  1085,
    1086,    -1,   441,    -1,   442,    -1,   443,    -1,   444,    -1,
    1088,  1089,    -1,   120,    -1,  1090,    -1,  1091,    -1,    11,
      -1,    10,  1092,   121,    -1,  1093,    -1,    -1,  1093,  1094,
      -1,  1095,    -1,  1099,    -1,  1103,    -1,  1107,    -1,  1111,
      -1,  1096,    -1,  1097,    -1,  1098,    -1,   125,    -1,   124,
      -1,   122,     5,   123,    -1,  1100,    -1,  1101,    -1,  1102,
      -1,   129,    -1,   128,    -1,   126,     5,   127,    -1,  1104,
      -1,  1105,    -1,  1106,    -1,   133,    -1,   132,    -1,   130,
       5,   131,    -1,  1108,    -1,  1109,    -1,  1110,    -1,   137,
      -1,   136,    -1,   134,     5,   135,    -1,  1112,    -1,  1113,
      -1,  1114,    -1,   141,    -1,   140,    -1,   138,     5,   139,
      -1,  1116,    -1,  1123,    -1,    -1,  1116,  1117,    -1,  1118,
    1119,  1122,    -1,   148,    -1,  1120,    -1,    -1,  1120,  1121,
      -1,  1372,    -1,  1370,    -1,    10,     6,   149,    -1,   156,
    1359,  1124,    -1,  1125,    -1,  1126,    -1,    10,   157,    -1,
      11,    -1,    10,     4,   157,    -1,  1128,    -1,  1133,    -1,
      -1,  1128,  1129,    -1,  1130,  1131,  1132,    -1,   148,    -1,
      -1,  1372,    -1,    10,  1082,   149,    -1,   156,  1359,  1134,
      -1,  1135,    -1,  1136,    -1,    10,   157,    -1,    11,    -1,
      10,     4,   157,    -1,  1138,  1179,  1139,    -1,   319,    -1,
    1140,    -1,  1141,    -1,    11,    -1,    10,  1142,   320,    -1,
    1115,    -1,  1144,  1179,  1145,    -1,   315,    -1,  1146,    -1,
    1147,    -1,    11,    -1,    10,  1148,   316,    -1,  1115,    -1,
    1150,  1179,  1151,    -1,   317,    -1,  1152,    -1,  1153,    -1,
      11,    -1,    10,  1154,   318,    -1,  1115,    -1,  1156,  1179,
    1157,    -1,   313,    -1,  1158,    -1,  1159,    -1,    11,    -1,
      10,  1160,   314,    -1,  1115,    -1,  1162,  1179,  1163,    -1,
     321,    -1,  1164,    -1,  1165,    -1,    11,    -1,    10,  1166,
     322,    -1,  1115,    -1,  1168,  1179,  1169,    -1,   323,    -1,
    1170,    -1,  1171,    -1,    11,    -1,    10,  1172,   324,    -1,
    1115,    -1,  1174,  1179,  1175,    -1,   325,    -1,  1176,    -1,
    1177,    -1,    11,    -1,    10,  1178,   326,    -1,  1115,    -1,
    1348,    -1,  1181,  1182,  1185,    -1,   281,    -1,  1183,    -1,
      -1,  1183,  1184,    -1,  1409,    -1,  1354,    -1,  1345,    -1,
    1394,    -1,  1412,    -1,  1371,    -1,  1186,    -1,  1187,    -1,
      11,    -1,    10,  1188,   282,    -1,  1189,  1195,    -1,    -1,
    1190,  1191,  1194,    -1,   242,    -1,  1192,    -1,    -1,  1192,
    1193,    -1,  1360,    -1,  1374,    -1,  1375,    -1,  1361,    -1,
    1362,    -1,  1363,    -1,  1364,    -1,  1376,    -1,  1373,    -1,
      10,   241,    -1,    11,    -1,    -1,  1195,  1196,    -1,  1197,
      -1,  1222,    -1,  1235,    -1,  1262,    -1,  1280,    -1,  1293,
      -1,  1311,    -1,  1315,    -1,  1198,  1199,    10,  1202,    -1,
     253,    -1,  1200,    -1,    -1,  1200,  1201,    -1,  1355,    -1,
    1400,    -1,  1204,  1203,   254,    -1,    -1,  1210,  1216,    -1,
    1205,  1206,    -1,   267,    -1,  1207,    -1,  1208,    -1,    11,
      -1,    10,  1209,   268,    -1,  1115,    -1,  1211,  1212,    -1,
     269,    -1,  1213,    -1,  1214,    -1,    11,    -1,    10,  1215,
     270,    -1,  1115,    -1,  1217,  1218,    -1,   271,    -1,  1219,
      -1,  1220,    -1,    11,    -1,    10,  1221,   272,    -1,  1127,
      -1,  1223,  1224,    10,  1227,    -1,   255,    -1,  1225,    -1,
      -1,  1225,  1226,    -1,  1355,    -1,  1400,    -1,  1204,  1228,
     256,    -1,    -1,  1210,  1229,    -1,  1230,  1231,    -1,   271,
      -1,  1232,    -1,  1233,    -1,    11,    -1,    10,  1234,   272,
      -1,  1115,    -1,  1236,  1237,    10,  1240,    -1,   257,    -1,
    1238,    -1,    -1,  1238,  1239,    -1,  1355,    -1,  1400,    -1,
    1204,  1241,   258,    -1,    -1,  1210,  1242,    -1,    -1,  1243,
    1244,    -1,   271,    -1,  1245,    -1,  1246,    -1,    11,    -1,
      10,  1247,   272,    -1,  1248,    -1,    -1,  1248,  1249,    -1,
    1250,  1251,  1254,    -1,   148,    -1,  1252,    -1,    -1,  1252,
    1253,    -1,  1357,    -1,  1368,    -1,  1255,    -1,  1256,    -1,
      11,    -1,    10,  1257,   149,    -1,    -1,  1257,  1258,    -1,
    1259,  1260,  1261,    -1,   273,    -1,    -1,  1367,    -1,    10,
       6,   274,    -1,  1263,  1264,    10,  1267,    -1,   259,    -1,
    1265,    -1,    -1,  1265,  1266,    -1,  1355,    -1,  1400,    -1,
    1204,  1268,   260,    -1,    -1,  1210,  1269,    -1,    -1,  1270,
    1271,    -1,   271,    -1,  1272,    -1,  1273,    -1,    11,    -1,
      10,  1274,   272,    -1,    -1,  1274,  1275,    -1,  1276,  1277,
      -1,   148,    -1,  1278,    -1,  1279,    -1,    11,    -1,    10,
    1427,   149,    -1,  1281,  1282,    10,  1285,    -1,   263,    -1,
    1283,    -1,    -1,  1283,  1284,    -1,  1355,    -1,  1400,    -1,
    1204,  1286,   264,    -1,    -1,  1210,  1287,    -1,  1288,  1289,
      -1,   271,    -1,  1290,    -1,  1291,    -1,    11,    -1,    10,
    1292,   272,    -1,  1115,    -1,  1294,  1295,    10,  1298,    -1,
     261,    -1,  1296,    -1,    -1,  1296,  1297,    -1,  1355,    -1,
    1400,    -1,  1204,  1299,   262,    -1,    -1,  1210,  1300,    -1,
      -1,  1301,  1302,    -1,   271,    -1,  1303,    -1,  1304,    -1,
      11,    -1,    10,  1305,   272,    -1,    -1,  1305,  1306,    -1,
    1307,  1308,  1310,    -1,   148,    -1,    -1,  1308,  1309,    -1,
    1421,    -1,  1372,    -1,  1370,    -1,    10,     6,   149,    -1,
    1312,  1313,    10,  1501,  1314,    -1,   275,    -1,    -1,  1403,
      -1,   276,    -1,  1316,  1317,  1318,    -1,   243,    -1,  1344,
      -1,    10,  1320,  1327,  1334,  1319,    -1,   244,    -1,  1321,
    1322,  1323,    -1,   247,    -1,  1348,    -1,  1324,    -1,  1325,
      -1,    11,    -1,    10,  1326,   248,    -1,  1115,    -1,  1328,
    1329,  1330,    -1,   249,    -1,  1348,    -1,  1331,    -1,  1332,
      -1,    11,    -1,    10,  1333,   250,    -1,  1115,    -1,    -1,
    1334,  1335,    -1,  1336,  1337,  1340,    -1,   245,    -1,  1338,
      -1,    -1,  1338,  1339,    -1,  1365,    -1,  1366,    -1,  1409,
      -1,  1412,    -1,  1341,    -1,  1342,    -1,    11,    -1,    10,
    1343,   246,    -1,  1189,  1195,    -1,   201,     8,     6,     8,
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
      -1,   226,  1084,     6,  1084,    -1,   227,  1084,     6,  1084,
      -1,   235,     8,  1082,     8,    -1,   236,     8,  1082,     8,
      -1,   231,     8,     6,     8,    -1,   232,     8,     6,     8,
      -1,   228,  1084,     6,  1084,    -1,   233,     8,     6,     8,
      -1,   225,     8,  1082,     8,    -1,   219,     8,     6,     8,
      -1,   220,     8,     6,     8,    -1,  1377,    -1,  1378,    -1,
     199,    -1,   200,     3,  1084,    -1,  1380,    -1,  1381,    -1,
     161,    -1,   162,     3,     8,    -1,  1383,    -1,  1384,    -1,
     181,    -1,   182,     3,     8,    -1,  1386,    -1,  1387,    -1,
     163,    -1,   164,     3,     8,    -1,  1389,    -1,  1390,    -1,
     171,    -1,   172,     3,     8,    -1,  1392,    -1,  1393,    -1,
     191,    -1,   192,     3,     8,    -1,  1395,    -1,  1396,    -1,
     167,    -1,   168,     3,     8,    -1,  1398,    -1,  1399,    -1,
     183,    -1,   184,     3,     8,    -1,  1401,    -1,  1402,    -1,
     197,    -1,   198,     3,     8,    -1,  1404,    -1,  1405,    -1,
     173,    -1,   174,     3,     8,    -1,  1407,    -1,  1408,    -1,
     165,    -1,   166,     3,     8,    -1,  1410,    -1,  1411,    -1,
     195,    -1,   196,     3,     8,    -1,  1413,    -1,  1414,    -1,
     169,    -1,   170,     3,     8,    -1,  1416,    -1,  1417,    -1,
     175,    -1,   176,     3,     8,    -1,  1419,    -1,  1420,    -1,
     177,    -1,   178,     3,     8,    -1,  1422,    -1,  1423,    -1,
     179,    -1,   180,     3,     8,    -1,  1425,    -1,  1426,    -1,
     185,    -1,   186,     3,     8,    -1,  1471,    -1,  1478,    -1,
    1434,    -1,  1436,    -1,  1486,    -1,  1438,    -1,  1440,    -1,
    1442,    -1,  1444,    -1,  1498,    -1,  1446,    -1,  1448,    -1,
    1450,    -1,  1454,    -1,  1452,    -1,  1456,    -1,  1463,    -1,
    1458,    -1,  1461,    -1,  1492,    -1,  1495,    -1,  1428,    -1,
    1431,    -1,  1489,    -1,  1465,    -1,  1467,    -1,  1469,    -1,
      -1,   391,  1429,  1430,    -1,    11,    -1,    10,   392,    -1,
      -1,   393,  1432,  1433,    -1,    11,    -1,    10,   394,    -1,
      -1,   395,  1435,  1427,  1427,   396,    -1,    -1,   353,  1437,
    1427,  1427,   354,    -1,    -1,   355,  1439,  1427,  1427,   356,
      -1,    -1,   369,  1441,  1427,   370,    -1,    -1,   357,  1443,
    1427,  1427,   358,    -1,    -1,   351,  1445,  1427,  1427,   352,
      -1,    -1,   359,  1447,  1427,   360,    -1,    -1,   361,  1449,
    1427,   362,    -1,    -1,   373,  1451,  1427,   374,    -1,    -1,
     375,  1453,  1427,   376,    -1,    -1,   377,  1455,  1427,   378,
      -1,    -1,   367,  1457,  1427,   368,    -1,  1459,  1427,  1460,
      -1,   381,    -1,   382,    -1,    -1,   383,  1462,  1427,   384,
      -1,    -1,   371,  1464,  1427,  1427,  1427,   372,    -1,    -1,
     399,  1466,  1501,   400,    -1,    -1,   401,  1468,  1501,   402,
      -1,    -1,   403,  1470,  1501,   404,    -1,  1472,  1474,  1473,
      -1,   397,    -1,    11,    -1,    10,   398,    -1,    -1,  1474,
    1475,    -1,  1412,    -1,  1418,    -1,  1476,    -1,    -1,   440,
       3,  1477,     8,    -1,    -1,   379,  1479,  1482,  1480,    -1,
      11,    -1,    10,   380,    -1,    -1,    10,  1427,  1481,   380,
      -1,    -1,  1482,  1483,    -1,  1484,    -1,  1485,    -1,   235,
       8,  1082,     8,    -1,   231,     8,     6,     8,    -1,    -1,
     363,  1487,  1488,   364,    -1,    -1,  1488,  1427,    -1,    -1,
     387,  1490,  1491,   388,    -1,    -1,  1491,  1427,    -1,    -1,
     385,  1493,  1494,   386,    -1,    -1,  1494,  1427,    -1,    -1,
     389,  1496,  1497,   390,    -1,    -1,  1497,  1427,    -1,    -1,
     365,  1499,  1500,   366,    -1,    -1,  1500,  1427,    -1,  1502,
      -1,  1506,    -1,  1510,    -1,  1514,    -1,  1518,    -1,  1521,
      -1,  1527,    -1,  1530,    -1,  1534,    -1,  1539,    -1,  1542,
      -1,  1545,    -1,  1548,    -1,  1551,    -1,  1554,    -1,  1557,
      -1,  1560,    -1,  1563,    -1,  1524,    -1,  1503,  1505,  1504,
      -1,   431,    -1,    11,    -1,    10,   432,    -1,   231,     8,
       6,     8,    -1,  1507,  1509,  1508,    -1,   281,    -1,    11,
      -1,    10,   282,    -1,   231,     8,     6,     8,    -1,  1511,
    1513,  1512,    -1,   285,    -1,    11,    -1,    10,   286,    -1,
     231,     8,     6,     8,    -1,  1515,  1517,  1516,    -1,   289,
      -1,    11,    -1,    10,   290,    -1,   231,     8,     6,     8,
      -1,  1519,  1520,    -1,   405,    -1,  1501,   406,    -1,  1522,
    1523,    -1,   407,    -1,  1501,  1501,   408,    -1,  1525,  1526,
      -1,   433,    -1,  1427,   434,    -1,  1528,  1529,    -1,   435,
      -1,  1501,   436,    -1,  1531,  1532,    10,  1533,    -1,   409,
      -1,    -1,  1538,    -1,  1501,   410,    -1,  1535,  1536,    10,
    1537,    -1,   411,    -1,    -1,  1538,    -1,  1501,   412,    -1,
     438,     3,     8,    -1,  1540,  1541,    -1,   413,    -1,    11,
      -1,    10,   414,    -1,  1543,  1544,    -1,   415,    -1,  1501,
    1501,   416,    -1,  1546,  1547,    -1,   417,    -1,  1501,   418,
      -1,  1549,  1550,    -1,   419,    -1,  1501,  1501,   420,    -1,
    1552,  1553,    -1,   421,    -1,  1501,  1501,   422,    -1,    -1,
     423,  1555,  1556,   424,    -1,    -1,  1556,  1501,    -1,  1558,
    1559,    -1,   425,    -1,  1427,  1501,   426,    -1,  1561,  1562,
      -1,   427,    -1,  1427,  1427,  1427,  1427,  1501,   428,    -1,
    1564,  1565,    -1,   429,    -1,  1501,   430,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   345,   345,   346,   348,   355,   365,   365,   367,   367,
     369,   371,   373,   382,   383,   386,   395,   395,   408,   408,
     410,   424,   424,   426,   426,   428,   430,   432,   432,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   446,   448,
     463,   470,   470,   473,   478,   482,   491,   495,   500,   500,
     502,   504,   506,   506,   508,   513,   523,   529,   529,   532,
     537,   543,   543,   546,   548,   555,   555,   557,   557,   559,
     561,   564,   566,   573,   573,   575,   575,   577,   579,   584,
     586,   593,   593,   595,   595,   597,   599,   604,   606,   613,
     613,   615,   615,   617,   619,   624,   626,   633,   633,   635,
     635,   637,   639,   644,   646,   653,   653,   655,   655,   657,
     659,   664,   666,   673,   673,   675,   675,   677,   679,   684,
     686,   693,   703,   708,   714,   714,   716,   718,   720,   720,
     722,   727,   739,   745,   745,   748,   755,   760,   767,   767,
     771,   771,   773,   784,   784,   786,   786,   788,   790,   792,
     792,   795,   796,   797,   798,   799,   800,   803,   805,   812,
     812,   814,   814,   816,   818,   825,   827,   838,   840,   840,
     843,   849,   855,   857,   863,   865,   876,   878,   878,   881,
     887,   893,   895,   902,   904,   915,   917,   917,   920,   926,
     932,   934,   941,   943,   952,   953,   959,   961,   967,   969,
     976,   986,   991,   997,   997,   999,  1001,  1003,  1003,  1005,
    1010,  1022,  1028,  1028,  1031,  1038,  1043,  1049,  1049,  1053,
    1053,  1055,  1066,  1066,  1068,  1068,  1070,  1072,  1074,  1074,
    1077,  1078,  1079,  1080,  1081,  1082,  1085,  1087,  1094,  1094,
    1096,  1096,  1098,  1100,  1108,  1110,  1117,  1117,  1119,  1119,
    1121,  1123,  1128,  1130,  1137,  1137,  1139,  1139,  1141,  1143,
    1148,  1150,  1157,  1157,  1159,  1159,  1161,  1163,  1168,  1170,
    1177,  1177,  1179,  1179,  1181,  1183,  1190,  1192,  1199,  1209,
    1214,  1220,  1220,  1222,  1224,  1226,  1226,  1228,  1233,  1245,
    1251,  1251,  1254,  1261,  1266,  1273,  1273,  1276,  1276,  1278,
    1294,  1294,  1296,  1296,  1298,  1300,  1302,  1302,  1305,  1306,
    1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1318,
    1320,  1327,  1327,  1329,  1329,  1331,  1333,  1341,  1343,  1350,
    1350,  1352,  1352,  1354,  1356,  1361,  1363,  1370,  1370,  1372,
    1372,  1374,  1376,  1381,  1383,  1390,  1390,  1392,  1392,  1394,
    1396,  1401,  1403,  1410,  1410,  1412,  1412,  1414,  1416,  1421,
    1423,  1430,  1440,  1445,  1451,  1451,  1453,  1455,  1457,  1457,
    1459,  1461,  1475,  1475,  1478,  1478,  1478,  1478,  1481,  1481,
    1483,  1483,  1485,  1487,  1496,  1497,  1500,  1502,  1513,  1515,
    1515,  1518,  1524,  1530,  1532,  1539,  1541,  1552,  1554,  1554,
    1557,  1563,  1569,  1571,  1578,  1580,  1591,  1593,  1593,  1596,
    1602,  1608,  1610,  1617,  1619,  1629,  1630,  1636,  1638,  1645,
    1647,  1654,  1664,  1669,  1675,  1675,  1677,  1679,  1681,  1681,
    1683,  1688,  1700,  1706,  1706,  1709,  1716,  1721,  1728,  1728,
    1731,  1731,  1733,  1741,  1747,  1747,  1750,  1757,  1762,  1767,
    1774,  1779,  1785,  1785,  1787,  1789,  1791,  1791,  1793,  1795,
    1804,  1806,  1806,  1808,  1808,  1808,  1810,  1820,  1830,  1850,
    1856,  1858,  1868,  1874,  1874,  1877,  1882,  1887,  1897,  1902,
    1908,  1908,  1910,  1912,  1914,  1914,  1916,  1921,  1931,  1937,
    1937,  1940,  1946,  1953,  1953,  1956,  1956,  1958,  1960,  1960,
    1962,  1962,  1964,  1966,  1974,  1974,  1976,  1982,  1982,  1990,
    1990,  1992,  1994,  1996,  1998,  1998,  2000,  2005,  2013,  2018,
    2024,  2024,  2026,  2028,  2030,  2030,  2032,  2042,  2051,  2051,
    2054,  2055,  2058,  2061,  2061,  2063,  2068,  2076,  2081,  2087,
    2087,  2089,  2091,  2093,  2093,  2095,  2105,  2114,  2114,  2117,
    2118,  2122,  2123,  2125,  2125,  2127,  2129,  2134,  2134,  2136,
    2141,  2141,  2143,  2145,  2147,  2149,  2149,  2158,  2158,  2167,
    2167,  2176,  2176,  2185,  2185,  2194,  2194,  2203,  2203,  2213,
    2213,  2215,  2220,  2244,  2250,  2250,  2253,  2262,  2270,  2276,
    2282,  2288,  2294,  2300,  2306,  2313,  2313,  2315,  2315,  2317,
    2319,  2319,  2321,  2321,  2323,  2330,  2339,  2339,  2342,  2348,
    2355,  2355,  2357,  2357,  2359,  2361,  2370,  2370,  2372,  2383,
    2393,  2399,  2399,  2402,  2407,  2408,  2412,  2412,  2414,  2416,
    2419,  2423,  2423,  2425,  2433,  2433,  2441,  2441,  2443,  2445,
    2447,  2449,  2449,  2451,  2456,  2464,  2469,  2475,  2475,  2477,
    2479,  2482,  2482,  2484,  2492,  2502,  2502,  2505,  2506,  2509,
    2512,  2512,  2514,  2519,  2519,  2522,  2524,  2526,  2528,  2528,
    2537,  2537,  2546,  2546,  2555,  2555,  2564,  2564,  2573,  2573,
    2582,  2582,  2592,  2592,  2594,  2600,  2624,  2631,  2631,  2634,
    2642,  2650,  2656,  2662,  2668,  2674,  2680,  2686,  2694,  2694,
    2696,  2696,  2698,  2700,  2700,  2702,  2702,  2704,  2709,  2719,
    2719,  2722,  2728,  2735,  2735,  2737,  2737,  2739,  2741,  2748,
    2748,  2750,  2762,  2772,  2778,  2778,  2781,  2786,  2787,  2791,
    2791,  2793,  2795,  2798,  2801,  2801,  2803,  2810,  2810,  2818,
    2818,  2820,  2822,  2824,  2826,  2826,  2828,  2833,  2841,  2846,
    2852,  2852,  2854,  2856,  2858,  2858,  2860,  2868,  2877,  2877,
    2880,  2881,  2884,  2887,  2887,  2889,  2894,  2894,  2896,  2898,
    2900,  2902,  2902,  2911,  2911,  2920,  2920,  2929,  2929,  2938,
    2938,  2947,  2947,  2956,  2956,  2966,  2966,  2968,  2974,  2998,
    3004,  3004,  3007,  3015,  3023,  3029,  3035,  3041,  3047,  3053,
    3059,  3066,  3066,  3068,  3068,  3070,  3072,  3072,  3074,  3074,
    3076,  3083,  3092,  3092,  3096,  3101,  3109,  3109,  3111,  3111,
    3113,  3115,  3123,  3123,  3125,  3137,  3147,  3153,  3153,  3156,
    3161,  3162,  3166,  3166,  3168,  3170,  3172,  3175,  3175,  3177,
    3183,  3183,  3191,  3191,  3193,  3195,  3198,  3198,  3206,  3212,
    3225,  3225,  3227,  3229,  3231,  3233,  3233,  3236,  3243,  3255,
    3255,  3257,  3259,  3261,  3267,  3267,  3269,  3269,  3271,  3277,
    3306,  3313,  3313,  3316,  3326,  3332,  3337,  3342,  3347,  3352,
    3357,  3362,  3369,  3369,  3371,  3371,  3373,  3376,  3377,  3383,
    3383,  3386,  3387,  3389,  3402,  3412,  3418,  3418,  3421,  3426,
    3427,  3431,  3431,  3433,  3435,  3437,  3444,  3444,  3446,  3451,
    3451,  3453,  3458,  3467,  3472,  3478,  3478,  3480,  3482,  3484,
    3484,  3486,  3491,  3505,  3513,  3513,  3516,  3522,  3528,  3534,
    3540,  3550,  3555,  3561,  3561,  3563,  3565,  3567,  3567,  3569,
    3575,  3580,  3582,  3582,  3584,  3586,  3598,  3598,  3600,  3605,
    3614,  3619,  3625,  3625,  3627,  3629,  3631,  3631,  3633,  3638,
    3650,  3658,  3658,  3661,  3666,  3671,  3676,  3684,  3689,  3695,
    3695,  3697,  3699,  3701,  3701,  3703,  3709,  3714,  3716,  3716,
    3718,  3720,  4021,  4027,  4033,  4039,  4045,  4051,  4057,  4063,
    4072,  4078,  4087,  4115,  4116,  4120,  4121,  4122,  4124,  4126,
    4126,  4128,  4129,  4130,  4131,  4167,  4169,  4183,  4183,  4185,
    4187,  4189,  4191,  4191,  4194,  4195,  4196,  4197,  4198,  4200,
    4208,  4208,  4210,  4210,  4212,  4218,  4226,  4226,  4228,  4228,
    4230,  4236,  4244,  4244,  4246,  4246,  4248,  4254,  4262,  4262,
    4264,  4264,  4266,  4272,  4280,  4280,  4282,  4282,  4284,  4296,
    4304,  4306,  4306,  4308,  4310,  4319,  4321,  4321,  4323,  4323,
    4325,  4341,  4344,  4344,  4346,  4346,  4349,  4380,  4388,  4390,
    4390,  4392,  4394,  4402,  4402,  4404,  4420,  4422,  4422,  4424,
    4424,  4426,  4577,  4579,  4584,  4584,  4586,  4588,  4590,  4593,
    4595,  4600,  4600,  4602,  4604,  4606,  4609,  4611,  4616,  4616,
    4618,  4620,  4622,  4625,  4627,  4632,  4632,  4634,  4636,  4638,
    4641,  4643,  4648,  4648,  4650,  4652,  4654,  4657,  4659,  4664,
    4664,  4666,  4668,  4670,  4673,  4675,  4680,  4680,  4682,  4684,
    4686,  4689,  4718,  4806,  4831,  4853,  4853,  4856,  4857,  4858,
    4859,  4860,  4861,  4992,  4992,  4994,  4996,  5025,  5027,  5027,
    5032,  5050,  5077,  5077,  5080,  5081,  5082,  5083,  5084,  5085,
    5086,  5087,  5088,  5091,  5091,  5093,  5093,  5098,  5098,  5098,
    5098,  5099,  5099,  5099,  5099,  5101,  5103,  5112,  5118,  5118,
    5121,  5127,  5133,  5135,  5135,  5141,  5151,  5161,  5161,  5163,
    5165,  5167,  5170,  5181,  5188,  5188,  5190,  5192,  5194,  5200,
    5210,  5217,  5217,  5219,  5221,  5223,  5226,  5228,  5237,  5243,
    5243,  5246,  5252,  5258,  5260,  5260,  5262,  5272,  5279,  5279,
    5281,  5283,  5285,  5287,  5289,  5298,  5304,  5304,  5307,  5313,
    5319,  5321,  5321,  5324,  5329,  5340,  5355,  5355,  5357,  5359,
    5361,  5363,  5363,  5365,  5372,  5379,  5392,  5392,  5395,  5396,
    5398,  5398,  5400,  5402,  5404,  5404,  5407,  5409,  5417,  5417,
    5422,  5429,  5431,  5440,  5446,  5446,  5449,  5455,  5461,  5463,
    5463,  5465,  5466,  5468,  5483,  5483,  5485,  5487,  5489,  5489,
    5491,  5493,  5508,  5508,  5510,  5512,  5522,  5524,  5533,  5539,
    5539,  5542,  5548,  5554,  5556,  5556,  5558,  5568,  5575,  5575,
    5577,  5579,  5581,  5584,  5586,  5595,  5601,  5601,  5604,  5610,
    5616,  5618,  5618,  5621,  5626,  5637,  5652,  5652,  5654,  5656,
    5658,  5658,  5660,  5668,  5680,  5680,  5683,  5684,  5685,  5703,
    5736,  5739,  5757,  5757,  5768,  5775,  5785,  5793,  5799,  5801,
    5815,  5827,  5833,  5839,  5839,  5841,  5843,  5845,  5847,  5857,
    5863,  5869,  5869,  5871,  5873,  5875,  5877,  5877,  5882,  5887,
    5899,  5901,  5901,  5904,  5905,  5906,  5914,  5921,  5921,  5923,
    5925,  5931,  5945,  5956,  5967,  5989,  6000,  6011,  6022,  6066,
    6090,  6112,  6123,  6134,  6145,  6156,  6167,  6180,  6191,  6205,
    6220,  6235,  6247,  6259,  6277,  6295,  6308,  6321,  6331,  6359,
    6368,  6379,  6389,  6401,  6415,  6415,  6417,  6427,  6443,  6443,
    6445,  6452,  6461,  6461,  6463,  6470,  6479,  6479,  6481,  6488,
    6497,  6497,  6499,  6506,  6571,  6571,  6573,  6580,  6589,  6589,
    6591,  6598,  6607,  6607,  6609,  6616,  6625,  6625,  6627,  6636,
    6650,  6650,  6652,  6659,  6668,  6668,  6670,  6677,  6686,  6686,
    6688,  6695,  6704,  6704,  6706,  6713,  6722,  6722,  6724,  6731,
    6740,  6740,  6744,  6752,  6761,  6761,  6763,  6770,  6779,  6779,
    6781,  6788,  6917,  6918,  6919,  6920,  6921,  6922,  6923,  6924,
    6925,  6926,  6927,  6928,  6929,  6930,  6931,  6932,  6933,  6934,
    6935,  6936,  6937,  6938,  6939,  6940,  6942,  6943,  6944,  6948,
    6948,  6951,  6952,  6954,  6954,  6957,  6958,  6962,  6962,  6967,
    6967,  6972,  6972,  6977,  6977,  6982,  6982,  6987,  6987,  6992,
    6992,  6997,  6997,  7002,  7002,  7007,  7007,  7012,  7012,  7017,
    7017,  7022,  7024,  7030,  7037,  7037,  7043,  7043,  7055,  7055,
    7060,  7060,  7065,  7065,  7075,  7082,  7088,  7089,  7091,  7092,
    7095,  7099,  7103,  7107,  7106,  7125,  7124,  7131,  7132,  7134,
    7133,  7140,  7141,  7144,  7150,  7158,  7165,  7183,  7183,  7194,
    7194,  7197,  7197,  7211,  7212,  7215,  7215,  7228,  7229,  7232,
    7232,  7245,  7246,  7249,  7249,  7259,  7260,  7266,  7267,  7268,
    7269,  7270,  7271,  7272,  7273,  7274,  7275,  7276,  7277,  7278,
    7279,  7280,  7281,  7282,  7283,  7284,  7287,  7292,  7299,  7300,
    7302,  7310,  7315,  7322,  7323,  7325,  7332,  7337,  7344,  7345,
    7347,  7354,  7359,  7366,  7367,  7369,  7376,  7378,  7384,  7386,
    7388,  7394,  7396,  7398,  7404,  7406,  7408,  7414,  7416,  7418,
    7424,  7424,  7429,  7431,  7433,  7439,  7439,  7444,  7446,  7455,
    7457,  7462,  7462,  7464,  7466,  7472,  7475,  7477,  7483,  7486,
    7488,  7494,  7497,  7499,  7505,  7509,  7508,  7520,  7520,  7527,
    7529,  7535,  7537,  7539,  7545,  7548,  7550,  7556
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
  "CONSTANTELEMENTSSTART", "CONSTANTELEMENTSEND",
  "VARREFERENCEELEMENTSSTART", "VARREFERENCEELEMENTSEND",
  "LINEARELEMENTSSTART", "LINEARELEMENTSEND", "GENERALELEMENTSSTART",
  "GENERALELEMENTSEND", "CONREFERENCEELEMENTSSTART",
  "CONREFERENCEELEMENTSEND", "OBJREFERENCEELEMENTSSTART",
  "OBJREFERENCEELEMENTSEND", "STRINGVALUEDELEMENTSSTART",
  "STRINGVALUEDELEMENTSEND", "STARTVECTORSTART", "STARTVECTOREND",
  "INDEXSTART", "INDEXEND", "VALUESTART", "VALUEEND", "VARIDXSTART",
  "VARIDXEND", "TRANSFORMATIONSTART", "TRANSFORMATIONEND",
  "MATRIXPROGRAMMINGSTART", "MATRIXPROGRAMMINGEND", "MATRIXVARIABLESSTART",
  "MATRIXVARIABLESEND", "MATRIXVARSTART", "MATRIXVAREND",
  "MATRIXOBJECTIVESSTART", "MATRIXOBJECTIVESEND", "MATRIXOBJSTART",
  "MATRIXOBJEND", "MATRIXCONSTRAINTSSTART", "MATRIXCONSTRAINTSEND",
  "MATRIXCONSTART", "MATRIXCONEND", "CONSTART", "CONEND",
  "CONSTRAINTSSTART", "CONSTRAINTSEND", "OBJSTART", "OBJEND",
  "OBJECTIVESSTART", "OBJECTIVESEND", "VARSTART", "VAREND",
  "VARIABLESSTART", "VARIABLESEND", "GENERALSTART", "GENERALEND",
  "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND", "JOBSTART",
  "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND", "ATEQUALITYSTART",
  "ATEQUALITYEND", "ATLOWERSTART", "ATLOWEREND", "ATUPPERSTART",
  "ATUPPEREND", "BASICSTART", "BASICEND", "ISFREESTART", "ISFREEEND",
  "SUPERBASICSTART", "SUPERBASICEND", "UNKNOWNSTART", "UNKNOWNEND",
  "SERVICEURISTART", "SERVICEURIEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "INSTANCENAMESTART", "INSTANCENAMEEND", "JOBIDSTART", "JOBIDEND",
  "OTHERSTART", "OTHEREND", "DUMMY", "NONLINEAREXPRESSIONSSTART",
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
     695,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   445,   446,   446,   447,   448,   449,   449,   450,   450,
     451,   452,   453,   454,   454,   455,   456,   456,   457,   457,
     458,   459,   459,   460,   460,   461,   462,   463,   463,   464,
     464,   464,   464,   464,   464,   464,   464,   464,   465,   466,
     467,   468,   468,   469,   469,   469,   470,   470,   471,   471,
     472,   473,   474,   474,   475,   476,   477,   478,   478,   479,
     479,   480,   480,   481,   482,   483,   483,   484,   484,   485,
     486,   487,   488,   489,   489,   490,   490,   491,   492,   493,
     494,   495,   495,   496,   496,   497,   498,   499,   500,   501,
     501,   502,   502,   503,   504,   505,   506,   507,   507,   508,
     508,   509,   510,   511,   512,   513,   513,   514,   514,   515,
     516,   517,   518,   519,   519,   520,   520,   521,   522,   523,
     524,   525,   526,   526,   527,   527,   528,   529,   530,   530,
     531,   532,   533,   534,   534,   535,   535,   535,   536,   536,
     537,   537,   538,   539,   539,   540,   540,   541,   542,   543,
     543,   544,   544,   544,   544,   544,   544,   545,   546,   547,
     547,   548,   548,   549,   550,   551,   552,   553,   554,   554,
     555,   555,   556,   557,   558,   559,   560,   561,   561,   562,
     562,   563,   564,   565,   566,   567,   568,   568,   569,   569,
     570,   571,   572,   573,   574,   574,   575,   576,   577,   578,
     579,   580,   580,   581,   581,   582,   583,   584,   584,   585,
     586,   587,   588,   588,   589,   589,   589,   590,   590,   591,
     591,   592,   593,   593,   594,   594,   595,   596,   597,   597,
     598,   598,   598,   598,   598,   598,   599,   600,   601,   601,
     602,   602,   603,   604,   605,   606,   607,   607,   608,   608,
     609,   610,   611,   612,   613,   613,   614,   614,   615,   616,
     617,   618,   619,   619,   620,   620,   621,   622,   623,   624,
     625,   625,   626,   626,   627,   628,   629,   630,   631,   632,
     632,   633,   633,   634,   635,   636,   636,   637,   638,   639,
     640,   640,   641,   641,   641,   642,   642,   643,   643,   644,
     645,   645,   646,   646,   647,   648,   649,   649,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   651,
     652,   653,   653,   654,   654,   655,   656,   657,   658,   659,
     659,   660,   660,   661,   662,   663,   664,   665,   665,   666,
     666,   667,   668,   669,   670,   671,   671,   672,   672,   673,
     674,   675,   676,   677,   677,   678,   678,   679,   680,   681,
     682,   683,   684,   684,   685,   685,   686,   687,   688,   688,
     689,   690,   691,   691,   692,   692,   692,   692,   693,   693,
     694,   694,   695,   696,   697,   697,   698,   699,   700,   701,
     701,   702,   702,   703,   704,   705,   706,   707,   708,   708,
     709,   709,   710,   711,   712,   713,   714,   715,   715,   716,
     716,   717,   718,   719,   720,   721,   721,   722,   723,   724,
     725,   726,   727,   727,   728,   728,   729,   730,   731,   731,
     732,   733,   734,   735,   735,   736,   736,   736,   737,   737,
     738,   738,   739,   740,   741,   741,   742,   742,   742,   742,
     743,   743,   744,   744,   745,   746,   747,   747,   748,   749,
     750,   751,   751,   752,   752,   752,   753,   754,   755,   756,
     757,   758,   759,   760,   760,   761,   761,   761,   762,   762,
     763,   763,   764,   765,   766,   766,   767,   768,   769,   770,
     770,   771,   771,   772,   772,   773,   773,   774,   775,   775,
     776,   776,   777,   778,   779,   779,   780,   781,   781,   782,
     782,   783,   784,   785,   786,   786,   787,   788,   789,   789,
     790,   790,   791,   792,   793,   793,   794,   795,   796,   796,
     797,   797,   798,   799,   799,   800,   801,   802,   802,   803,
     803,   804,   805,   806,   806,   807,   808,   809,   809,   810,
     810,   811,   811,   812,   812,   813,   814,   815,   815,   816,
     817,   817,   818,   819,   820,   821,   821,   822,   822,   823,
     823,   824,   824,   825,   825,   826,   826,   827,   827,   828,
     828,   829,   830,   831,   832,   832,   833,   833,   833,   833,
     833,   833,   833,   833,   833,   834,   834,   835,   835,   836,
     837,   837,   838,   838,   839,   840,   841,   841,   842,   842,
     843,   843,   844,   844,   845,   846,   847,   847,   848,   849,
     850,   851,   851,   852,   852,   852,   853,   853,   854,   855,
     856,   857,   857,   858,   859,   859,   860,   860,   861,   862,
     863,   864,   864,   865,   866,   867,   867,   868,   868,   869,
     870,   871,   871,   872,   873,   874,   874,   875,   875,   876,
     877,   877,   878,   879,   879,   880,   881,   882,   883,   883,
     884,   884,   885,   885,   886,   886,   887,   887,   888,   888,
     889,   889,   890,   890,   891,   892,   893,   894,   894,   895,
     895,   895,   895,   895,   895,   895,   895,   895,   896,   896,
     897,   897,   898,   899,   899,   900,   900,   901,   902,   903,
     903,   904,   904,   905,   905,   906,   906,   907,   908,   909,
     909,   910,   911,   912,   913,   913,   914,   914,   914,   915,
     915,   916,   917,   918,   919,   919,   920,   921,   921,   922,
     922,   923,   924,   925,   926,   926,   927,   928,   929,   929,
     930,   930,   931,   932,   933,   933,   934,   935,   936,   936,
     937,   937,   938,   939,   939,   940,   941,   941,   942,   943,
     944,   945,   945,   946,   946,   947,   947,   948,   948,   949,
     949,   950,   950,   951,   951,   952,   952,   953,   954,   955,
     956,   956,   957,   957,   957,   957,   957,   957,   957,   957,
     957,   958,   958,   959,   959,   960,   961,   961,   962,   962,
     963,   964,   965,   965,   966,   966,   967,   967,   968,   968,
     969,   970,   971,   971,   972,   973,   974,   975,   975,   976,
     976,   976,   977,   977,   978,   979,   980,   981,   981,   982,
     983,   983,   984,   984,   985,   986,   987,   987,   988,   989,
     990,   990,   991,   992,   993,   994,   994,   995,   996,   997,
     997,   998,   999,  1000,  1001,  1001,  1002,  1002,  1003,  1004,
    1005,  1006,  1006,  1007,  1007,  1007,  1007,  1007,  1007,  1007,
    1007,  1007,  1008,  1008,  1009,  1009,  1010,  1011,  1011,  1012,
    1012,  1013,  1013,  1014,  1015,  1016,  1017,  1017,  1018,  1018,
    1018,  1019,  1019,  1020,  1021,  1022,  1023,  1023,  1024,  1025,
    1025,  1026,  1027,  1028,  1028,  1029,  1029,  1030,  1031,  1032,
    1032,  1033,  1034,  1035,  1036,  1036,  1037,  1037,  1037,  1037,
    1037,  1038,  1038,  1039,  1039,  1040,  1041,  1042,  1042,  1043,
    1044,  1044,  1045,  1045,  1046,  1047,  1048,  1048,  1049,  1050,
    1051,  1051,  1052,  1052,  1053,  1054,  1055,  1055,  1056,  1057,
    1058,  1059,  1059,  1060,  1060,  1060,  1060,  1061,  1061,  1062,
    1062,  1063,  1064,  1065,  1065,  1066,  1067,  1067,  1068,  1068,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1082,  1083,  1083,  1083,  1084,  1085,
    1085,  1086,  1086,  1086,  1086,  1087,  1088,  1089,  1089,  1090,
    1091,  1092,  1093,  1093,  1094,  1094,  1094,  1094,  1094,  1095,
    1096,  1096,  1097,  1097,  1098,  1099,  1100,  1100,  1101,  1101,
    1102,  1103,  1104,  1104,  1105,  1105,  1106,  1107,  1108,  1108,
    1109,  1109,  1110,  1111,  1112,  1112,  1113,  1113,  1114,  1115,
    1115,  1116,  1116,  1117,  1118,  1119,  1120,  1120,  1121,  1121,
    1122,  1123,  1124,  1124,  1125,  1125,  1126,  1127,  1127,  1128,
    1128,  1129,  1130,  1131,  1131,  1132,  1133,  1134,  1134,  1135,
    1135,  1136,  1137,  1138,  1139,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1151,
    1152,  1153,  1154,  1155,  1156,  1157,  1157,  1158,  1159,  1160,
    1161,  1162,  1163,  1163,  1164,  1165,  1166,  1167,  1168,  1169,
    1169,  1170,  1171,  1172,  1173,  1174,  1175,  1175,  1176,  1177,
    1178,  1179,  1180,  1181,  1182,  1183,  1183,  1184,  1184,  1184,
    1184,  1184,  1184,  1185,  1185,  1186,  1187,  1188,  1189,  1189,
    1190,  1191,  1192,  1192,  1193,  1193,  1193,  1193,  1193,  1193,
    1193,  1193,  1193,  1194,  1194,  1195,  1195,  1196,  1196,  1196,
    1196,  1196,  1196,  1196,  1196,  1197,  1198,  1199,  1200,  1200,
    1201,  1201,  1202,  1203,  1203,  1204,  1205,  1206,  1206,  1207,
    1208,  1209,  1210,  1211,  1212,  1212,  1213,  1214,  1215,  1216,
    1217,  1218,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,
    1225,  1226,  1226,  1227,  1228,  1228,  1229,  1230,  1231,  1231,
    1232,  1233,  1234,  1235,  1236,  1237,  1238,  1238,  1239,  1239,
    1240,  1241,  1241,  1242,  1242,  1243,  1244,  1244,  1245,  1246,
    1247,  1248,  1248,  1249,  1250,  1251,  1252,  1252,  1253,  1253,
    1254,  1254,  1255,  1256,  1257,  1257,  1258,  1259,  1260,  1260,
    1261,  1262,  1263,  1264,  1265,  1265,  1266,  1266,  1267,  1268,
    1268,  1269,  1269,  1270,  1271,  1271,  1272,  1273,  1274,  1274,
    1275,  1276,  1277,  1277,  1278,  1279,  1280,  1281,  1282,  1283,
    1283,  1284,  1284,  1285,  1286,  1286,  1287,  1288,  1289,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1296,  1297,  1297,
    1298,  1299,  1299,  1300,  1300,  1301,  1302,  1302,  1303,  1304,
    1305,  1305,  1306,  1307,  1308,  1308,  1309,  1309,  1309,  1310,
    1311,  1312,  1313,  1313,  1314,  1315,  1316,  1317,  1318,  1319,
    1320,  1321,  1322,  1323,  1323,  1324,  1325,  1326,  1327,  1328,
    1329,  1330,  1330,  1331,  1332,  1333,  1334,  1334,  1335,  1336,
    1337,  1338,  1338,  1339,  1339,  1339,  1339,  1340,  1340,  1341,
    1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,
    1352,  1353,  1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,
    1362,  1363,  1364,  1365,  1366,  1367,  1368,  1369,  1370,  1371,
    1372,  1373,  1374,  1375,  1376,  1376,  1377,  1378,  1379,  1379,
    1380,  1381,  1382,  1382,  1383,  1384,  1385,  1385,  1386,  1387,
    1388,  1388,  1389,  1390,  1391,  1391,  1392,  1393,  1394,  1394,
    1395,  1396,  1397,  1397,  1398,  1399,  1400,  1400,  1401,  1402,
    1403,  1403,  1404,  1405,  1406,  1406,  1407,  1408,  1409,  1409,
    1410,  1411,  1412,  1412,  1413,  1414,  1415,  1415,  1416,  1417,
    1418,  1418,  1419,  1420,  1421,  1421,  1422,  1423,  1424,  1424,
    1425,  1426,  1427,  1427,  1427,  1427,  1427,  1427,  1427,  1427,
    1427,  1427,  1427,  1427,  1427,  1427,  1427,  1427,  1427,  1427,
    1427,  1427,  1427,  1427,  1427,  1427,  1427,  1427,  1427,  1429,
    1428,  1430,  1430,  1432,  1431,  1433,  1433,  1435,  1434,  1437,
    1436,  1439,  1438,  1441,  1440,  1443,  1442,  1445,  1444,  1447,
    1446,  1449,  1448,  1451,  1450,  1453,  1452,  1455,  1454,  1457,
    1456,  1458,  1459,  1460,  1462,  1461,  1464,  1463,  1466,  1465,
    1468,  1467,  1470,  1469,  1471,  1472,  1473,  1473,  1474,  1474,
    1475,  1475,  1475,  1477,  1476,  1479,  1478,  1480,  1480,  1481,
    1480,  1482,  1482,  1483,  1483,  1484,  1485,  1487,  1486,  1488,
    1488,  1490,  1489,  1491,  1491,  1493,  1492,  1494,  1494,  1496,
    1495,  1497,  1497,  1499,  1498,  1500,  1500,  1501,  1501,  1501,
    1501,  1501,  1501,  1501,  1501,  1501,  1501,  1501,  1501,  1501,
    1501,  1501,  1501,  1501,  1501,  1501,  1502,  1503,  1504,  1504,
    1505,  1506,  1507,  1508,  1508,  1509,  1510,  1511,  1512,  1512,
    1513,  1514,  1515,  1516,  1516,  1517,  1518,  1519,  1520,  1521,
    1522,  1523,  1524,  1525,  1526,  1527,  1528,  1529,  1530,  1531,
    1532,  1532,  1533,  1534,  1535,  1536,  1536,  1537,  1538,  1539,
    1540,  1541,  1541,  1542,  1543,  1544,  1545,  1546,  1547,  1548,
    1549,  1550,  1551,  1552,  1553,  1555,  1554,  1556,  1556,  1557,
    1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565
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
       0,     0,   999,  1129,   904,  1336,  1176,  1207,  1224,  1262,
    1304,  1287,  1331,  1166,  1167,  1178,  1168,  1209,  1169,  1226,
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
#define YYPACT_NINF -2074
static const yytype_int16 yypact[] =
{
     425, -2074, -2074,   148,    17,   210, -2074, -2074,   228,   -62,
   -2074,   464, -2074,   469, -2074, -2074, -2074, -2074,    -7,   474,
   -2074, -2074, -2074, -2074, -2074,    17, -2074, -2074, -2074, -2074,
   -2074,     1,   488,   -13, -2074, -2074, -2074, -2074,   191,  1083,
     228, -2074,    20,   514,    87, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,    29,
     -20, -2074, -2074,   217, -2074,   520, -2074,   555, -2074,   561,
   -2074,   585, -2074,   618, -2074,   629, -2074,   644, -2074,   295,
   -2074,   340, -2074, -2074,   347, -2074, -2074,   351, -2074, -2074,
     356, -2074, -2074,   371, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,    67,
     653,    42, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074,    79,   455, -2074, -2074,   656, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,   505, -2074,   295, -2074, -2074,
   -2074, -2074,   389, -2074,   393,   671,   217, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,   128, -2074, -2074, -2074, -2074,
      16, -2074, -2074, -2074, -2074,    13, -2074, -2074, -2074, -2074,
       9, -2074, -2074, -2074, -2074,     8, -2074, -2074, -2074, -2074,
     137, -2074, -2074, -2074, -2074,    85, -2074, -2074, -2074, -2074,
   -2074,   673, -2074,   275,   279,   282,   284,   312, -2074, -2074,
   -2074,    18, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074,   115,   435, -2074, -2074,   675, -2074,   681,
   -2074,   683, -2074,   687, -2074,   689, -2074,   295, -2074, -2074,
     102, -2074, -2074, -2074, -2074,   424,   269,   436,   269,   443,
     269,   445, -2074,   693, -2074,   456,    -2,   459,   461,   233,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074,   411, -2074, -2074,
     166, -2074, -2074,   175, -2074, -2074,   183, -2074, -2074,   173,
   -2074, -2074,   439, -2074, -2074,   420,   516,   -25, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074,   695,   156, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074,   216,   384, -2074, -2074,   699, -2074,   767, -2074,   770,
   -2074,   774, -2074,   776, -2074,   507, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074,   505, -2074,   295, -2074, -2074,   129, -2074,
   -2074, -2074, -2074,   255, -2074, -2074, -2074, -2074,   138, -2074,
   -2074, -2074, -2074,    92, -2074, -2074, -2074, -2074,   160, -2074,
   -2074, -2074, -2074,   778, -2074, -2074, -2074,   450,   787, -2074,
   -2074,   545, -2074, -2074, -2074, -2074, -2074,   787, -2074, -2074,
   -2074, -2074,   787, -2074, -2074, -2074, -2074,   544, -2074,   -11,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,   495,   470, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   508,
     232, -2074, -2074,   -60, -2074, -2074, -2074, -2074, -2074,   569,
     571,   575, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   126,
   -2074, -2074, -2074, -2074,   136, -2074, -2074, -2074, -2074,   105,
   -2074, -2074, -2074, -2074,   331, -2074, -2074, -2074, -2074,   146,
   -2074, -2074, -2074, -2074, -2074,   785, -2074,   577,   269,   579,
     269,   583,   269,   587, -2074,   788, -2074, -2074, -2074,   536,
   -2074, -2074,   562, -2074, -2074,   519, -2074, -2074,   529, -2074,
   -2074, -2074,   557, -2074,   -10, -2074, -2074, -2074, -2074, -2074,
     600, -2074,   652,   609, -2074,   638, -2074, -2074,   651, -2074,
   -2074,   628,   366, -2074, -2074, -2074, -2074, -2074,   806,   346,
   -2074, -2074, -2074,   810,   396, -2074, -2074,   395,    86, -2074,
   -2074,   707,   709,   711,   713, -2074, -2074,   640, -2074, -2074,
     642, -2074, -2074,   660, -2074, -2074,   692, -2074, -2074,   678,
     731,    62, -2074, -2074, -2074, -2074,   787, -2074, -2074, -2074,
   -2074,   787, -2074, -2074, -2074, -2074,   787, -2074, -2074, -2074,
   -2074,   733, -2074,    -8, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,   676,   410, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,   812,   396,   662, -2074,
   -2074, -2074,   744, -2074, -2074, -2074, -2074, -2074,   413, -2074,
   -2074, -2074,   752, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074,   727,   749,   379, -2074,   755,   757,   759,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   672,   690,
   -2074, -2074,   666, -2074,   670, -2074,   686, -2074, -2074,   694,
   -2074, -2074,   708,   466, -2074, -2074, -2074, -2074,   814,   396,
     478, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   842, -2074,
     844, -2074,   821, -2074,   745, -2074,   853,   855, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
     246, -2074, -2074, -2074, -2074, -2074, -2074,   824,   396,   524,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   860,
      83, -2074, -2074, -2074, -2074, -2074,   808,   217, -2074, -2074,
     864,    93, -2074, -2074,   869, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,   538, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,   803,   796, -2074, -2074,
   -2074,   581,   826,   828,   217, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,   791, -2074,   872, -2074, -2074,
   -2074, -2074,   830,   440, -2074,   589,   866,   141, -2074, -2074,
   -2074, -2074,    74, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074,   272, -2074, -2074, -2074, -2074,   880, -2074, -2074, -2074,
   -2074, -2074, -2074,   599,   873, -2074,   832, -2074, -2074, -2074,
     839, -2074, -2074,   811,   820, -2074, -2074, -2074, -2074,   893,
   -2074,   819,   480, -2074, -2074, -2074, -2074,   904, -2074,   635,
     894, -2074,   835, -2074,   910,   780, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074,   837,   296, -2074,   764, -2074, -2074,   912,
   -2074,   856,   900, -2074,  1163, -2074,   926,   790, -2074, -2074,
   -2074, -2074, -2074, -2074,   634,   836,   725,   851, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,   863,   925, -2074,  1165,
   -2074,   944,   902, -2074, -2074, -2074, -2074, -2074, -2074,   663,
     919,   761, -2074, -2074, -2074,   921,   725,   959,  1168, -2074,
   -2074, -2074, -2074,  1181, -2074,   963,   696, -2074, -2074, -2074,
   -2074, -2074, -2074,   685,   933,   782, -2074, -2074, -2074, -2074,
    1183,   973,  1187, -2074, -2074, -2074,  1189,  1193, -2074,   977,
     -59, -2074, -2074, -2074, -2074,   979,   343, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074,   958, -2074, -2074, -2074, -2074,  1229,
     985,  1231, -2074,   664,   682, -2074, -2074, -2074, -2074,   989,
     -65, -2074, -2074, -2074, -2074,   668,   682, -2074, -2074, -2074,
   -2074,   -57, -2074, -2074, -2074, -2074,   997, -2074, -2074,   852,
     715, -2074, -2074, -2074, -2074, -2074,   939,   948, -2074, -2074,
   -2074,   -77, -2074,  1235, -2074,   677,   682, -2074, -2074, -2074,
   -2074,  1012,   -12, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074,   975,   717, -2074,   868,  1014, -2074, -2074,   879,   735,
   -2074, -2074, -2074, -2074, -2074,   983,   717, -2074, -2074, -2074,
     923,   737, -2074, -2074, -2074, -2074, -2074,    54, -2074, -2074,
   -2074,  1239,   512, -2074, -2074, -2074,  1032,   896, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,   999,   717, -2074,  1034, -2074,
   -2074,  1016,   772, -2074, -2074,  1241,  1018, -2074, -2074,   748,
   -2074,   868,  1061,  1243, -2074, -2074, -2074, -2074,    64,  1245,
     641, -2074,   748, -2074, -2074, -2074,    40,   787,  1063, -2074,
   -2074, -2074, -2074,   107, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074,   858,  1247,  1066,
   -2074,   748, -2074, -2074, -2074, -2074,   186,   -92, -2074, -2074,
   -2074, -2074,  1065, -2074,  1074, -2074,  1076, -2074,  1078, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,   789, -2074,   868,  1249,
    1077,   929, -2074, -2074, -2074, -2074,   787, -2074, -2074, -2074,
   -2074,   -82, -2074, -2074, -2074, -2074, -2074,  1101, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
     789, -2074,     6, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
     816,  1100, -2074, -2074,  1103, -2074,  1041,   506, -2074, -2074,
   -2074, -2074, -2074,  -183,  1104,  1251, -2074,   -81, -2074, -2074,
   -2074, -2074, -2074,  1111, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,   789, -2074,   787, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,   807,   850, -2074, -2074,
    1001, -2074, -2074,  1141,  1145,  1147,  1149, -2074,   838, -2074,
     868,  1253,   929, -2074, -2074, -2074, -2074,  1153,   915, -2074,
    1015, -2074,   845,   871, -2074, -2074, -2074,   833,   907, -2074,
   -2074,  1021, -2074, -2074,  1206,   838, -2074, -2074, -2074,   922,
   -2074,  1219, -2074,  1185, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074,  1334, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
    1006,  1052, -2074, -2074,  1194, -2074, -2074,  1337,   838, -2074,
    1054, -2074, -2074,    52, -2074,  1255,   226,  1339, -2074, -2074,
   -2074, -2074,  1025, -2074,   868,  1257,   929, -2074, -2074, -2074,
   -2074, -2074,  1033, -2074,  1342,  1259, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074,    68, -2074,  1261,   226, -2074,  1025, -2074,
   -2074, -2074, -2074,  1264,   479,  1343,    12, -2074, -2074,   163,
   -2074,  1266,   226, -2074,  1025, -2074, -2074,    23, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,   929, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,  1027, -2074,   868,  1268,
     929, -2074, -2074, -2074, -2074, -2074,  1035, -2074,  1348,    89,
   -2074, -2074, -2074, -2074,  1345,  1048,    15, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074,   929, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074,  1027, -2074,   -55, -2074, -2074, -2074, -2074,
   -2074,  1353, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
      31, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   929, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074,  1027, -2074, -2074,
   -2074, -2074, -2074,  1064, -2074,  1208, -2074, -2074, -2074, -2074,
     868,  1272,   929, -2074, -2074, -2074, -2074, -2074,  1043, -2074,
    1354,  1204, -2074,  1357, -2074,  1356,  1358, -2074, -2074, -2074,
   -2074,  1067, -2074,  1214, -2074, -2074, -2074, -2074, -2074,  1036,
    1087,  1220, -2074, -2074, -2074,  1361,  1274,   261, -2074,  1079,
   -2074,  1222, -2074, -2074, -2074, -2074, -2074,  1276,   929, -2074,
   -2074, -2074, -2074, -2074,  1053, -2074, -2074, -2074,  1225,  1370,
    1371, -2074, -2074, -2074, -2074, -2074,  1278,   226, -2074,  1136,
   -2074, -2074, -2074, -2074, -2074,  1376,  1372,  1373, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
     929, -2074, -2074, -2074, -2074, -2074,  1058, -2074, -2074,  1375,
    1377,   929, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074,  1102, -2074, -2074,  1378,  1381,  1382,  1383, -2074,  1068,
   -2074, -2074, -2074,  1240, -2074, -2074,   294,  1280,   392, -2074,
    1384,  1385, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074,  1119, -2074,  1195,
    1154, -2074, -2074, -2074,  1387,  1389,  1390,  1391,  1392,  1393,
    1394,  1395,  1396, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,  1397,   174,
    1398,   174,  1399,   174,  1400,   174,  1403,   174,  1404,   174,
   -2074,  1402,  1405, -2074, -2074, -2074,  1408,  1407, -2074, -2074,
   -2074,  1412,  1413,  1414,  1415,  1416,  1417,  1418,   787,  1139,
   -2074,  1422,  1419, -2074, -2074, -2074, -2074, -2074,  1139, -2074,
   -2074, -2074,  1139, -2074, -2074, -2074,  1139, -2074, -2074, -2074,
    1139, -2074, -2074, -2074,  1139, -2074, -2074, -2074,  1420,   341,
    1423,  1179, -2074, -2074,  1424,  1425,  1426,  1427,  1428,  1430,
    1431,  1432, -2074, -2074,  1161,  1284,  1433,  1436,  1161, -2074,
    1161, -2074,  1161, -2074,  1161, -2074,  1161, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,  1155, -2074,
    1212, -2074,  1213, -2074,  1215, -2074,  1216, -2074,   341, -2074,
     341, -2074,   769, -2074,   341, -2074,  1007, -2074,  1007, -2074,
    1286, -2074,   341, -2074,   341, -2074,   341, -2074,   341, -2074,
   -2074,   769, -2074,   769, -2074,   341,  1440, -2074,  1200,   868,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,  1196,
    1180,  1288,   929, -2074, -2074, -2074, -2074, -2074,  1444,  1182,
    1198,  1184,  1199,  1188,  1201,  1191,  1192,  1197,  1202, -2074,
   -2074, -2074,  1450,  1290,  1452,  1292,  1455,  1294,  1457,  1296,
    1060, -2074,   341, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074,  1037, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074,   769, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074,  1031, -2074,  1466,  1460, -2074,  1462, -2074,  1059,
   -2074, -2074,   341, -2074,  1056, -2074,   341, -2074,   341, -2074,
     341, -2074,   769, -2074,  1045, -2074, -2074, -2074, -2074,   868,
    1298, -2074, -2074, -2074, -2074,  1300,   929, -2074, -2074, -2074,
   -2074, -2074,  1209, -2074, -2074, -2074,  1302, -2074, -2074, -2074,
    1304, -2074, -2074, -2074,  1306, -2074, -2074, -2074,  1308, -2074,
   -2074, -2074,  1310, -2074,   309,  1470,  1046, -2074, -2074,  1473,
    1203, -2074, -2074,  1474,  1205, -2074, -2074,  1475,  1207, -2074,
   -2074, -2074,  1075,   769,   769,   769,   769,   769,   769, -2074,
   -2074,   769,   769,   769,   769,   769,   769, -2074,   769, -2074,
   -2074, -2074,  1312,  1314,   769,   341,   341,   341, -2074,  1105,
      14, -2074,  1476,   341,   341, -2074,  1070, -2074,  1062,  1071,
    1069,   769, -2074,  1082,  1318, -2074,   929, -2074, -2074, -2074,
   -2074,  1332, -2074, -2074, -2074, -2074, -2074,  1224, -2074,   929,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074,   929, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,  1481, -2074,  1484, -2074,
    1488, -2074,  1490, -2074, -2074,   769,   769,   769,   769,  1140,
    1137,   500,   556,  1133,  1132,   769,  1129,  1128,  1127,    61,
    1122,   605,   658,   697,  1115, -2074, -2074,  1114, -2074, -2074,
     769,  1109,  1108,  1107, -2074, -2074,  1116, -2074,  1509, -2074,
   -2074, -2074, -2074, -2074, -2074,  1106, -2074,  1110, -2074, -2074,
   -2074, -2074, -2074,   769, -2074, -2074, -2074, -2074, -2074,   929,
   -2074, -2074, -2074, -2074, -2074,  1265,   915, -2074,  1367, -2074,
    1246, -2074, -2074,  1248,  1252,  1369,   -67, -2074,  1254,   -63,
   -2074, -2074, -2074, -2074,  1167,  1169,  1171,  1172, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,   769, -2074, -2074, -2074,
     738, -2074,  1513,  1517, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074,  1135, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,   341,  1320,   307, -2074,  1279,
   -2074,  1323, -2074, -2074,  1299, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074,  1325, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074,  1162, -2074, -2074,  1527,   787, -2074,
    1528,  1112,  1136, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,    90, -2074, -2074, -2074, -2074,
    1525, -2074,  1327,   -76,   769, -2074, -2074, -2074, -2074,   169,
   -2074,  1157,  1530,  1531, -2074, -2074, -2074,  1295,  1536,  1537,
    1388, -2074,   787, -2074, -2074, -2074, -2074, -2074, -2074,  1538,
    1539, -2074, -2074, -2074,  1401,  1542, -2074,  1541, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   294, -2074,
   -2074, -2074, -2074,  1406,   -58,  1543,   787, -2074,  1409,  1544,
   -2074, -2074, -2074, -2074, -2074, -2074,  1316,  1545,  1546, -2074,
   -2074,  1548,  1547, -2074, -2074, -2074,   787,  1553, -2074,  1552,
    1287, -2074, -2074
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,  1522, -2074,
    1540, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,  1503,
   -2074, -2074, -2074, -2074,  1410, -2074, -2074, -2074, -2074, -2074,
    1158, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,  1148, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,  1435,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
    1055, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074,  1346, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074,   986, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,  1262, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074,   932, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074,   920, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074,  1047, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,   822, -2074, -2074, -2074,
   -2074, -2074,   763, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   598,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074,   548, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074,   313, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074,   311, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074,   564, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074,   348, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074,   344, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   518,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   285, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074,   283, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,    77,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   602, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,   394, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074,   843, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074,   771, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
    -102, -2074, -2074, -2074, -2074,  -583, -2074,  -366, -1238,  -200,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -1244, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074,  -597, -2074, -2074, -2074, -2074, -2074,  -656, -2074,
   -2074, -2074, -2074, -2074,  -939, -2074, -2074, -2074, -2074, -2074,
   -1041, -2074, -2074, -2074, -2074, -2074, -1003, -2074, -2074, -2074,
   -2074, -2074, -1201, -2074, -2074, -2074, -2074, -2074, -1173, -2074,
   -2074, -2074, -2074, -2074, -1037, -1312, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074,  -660, -2074, -2074, -2074, -2074, -2074,
    -692, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -1212,
   -2074, -2074, -2074, -2074, -2074, -1210, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074,   486, -2074, -1313, -1065,   554,   243,   532, -2074, -2074,
   -1093,  -798, -2074, -2074,  -557, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -1055,  -679, -2074, -2073, -2074, -2074,
   -2074, -2074, -2074, -2074,  -741, -2074, -2074, -2074, -2074, -2074,
    -136, -2074, -2074, -1054, -2074, -2074, -2074, -2074, -2074,  -510,
   -2074, -2074, -2074, -2074, -2074, -1052, -2074, -2074, -2074, -2074,
   -2074, -1032, -2074, -2074,  -616, -2074, -2074,  -689, -2074, -2074,
    -243, -2074, -2074,  -593, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -1738, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -1687, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074,  -196, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074, -2074,
   -2074
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     286,   733,   501,  1381,   666,   381,   395,   386,  1331,   252,
    1277,   504,   277,   274,   615,  1169,   506,   271,   525,  1469,
     268,  1470,  1471,  1159,  2126,  2127,  1172,  1469,   758,  1470,
    1471,  1188,   799,  1420,  1149,  1469,    49,  1470,  1471,  1059,
      50,  1043,   417,    49,  1216,   254,    51,    50,  1174,  1464,
    1182,  1183,   299,    51,  1028,  1221,   509,   583,  1233,   650,
      52,  1231,  1367,  1368,  1087,   758,   705,    52,  1264,  1297,
     300,  2190,  2191,  1940,  1156,  1942,    53,  1223,  1406,  1407,
    1016,  2231,  1395,    53,   301,  2236,   977,   665,   216,   283,
     217,  2333,   302,  1491,  2290,  1507,   486,  1286,   928,   762,
     763,  1860,   303,  1862,   304,   741,   365,  1922,   218,   541,
     373,  1251,   380,  1514,   385,  1932,   305,  1934,   219,  1936,
     306,  1938,   307,   126,   308,   127,   309,   128,  1944,   129,
     535,  1476,   265,   477,   756,   364,   220,     7,  2299,  1276,
     538,   280,   221,  1181,   483,   808,  1487,  1424,     6,   704,
     547,  2271,  1287,   130,   636,   872,   744,  1445,   620,   811,
    2300,   637,   812,  1468,   525,   745,   489,   490,  1502,  2029,
    1504,   756,  1227,  1450,  1451,  2002,  1192,   131,   478,  2305,
     542,   428,   284,   153,   154,  1309,   764,   487,   740,   266,
     643,   611,   612,   366,   515,   645,  1228,   474,  1544,   548,
     647,  1044,   809,  1234,  2041,  2232,  2311,   601,   602,  2237,
    1298,   536,  1520,  1325,  1522,  2334,   520,  1265,   281,   601,
     602,   601,   602,   539,    12,   560,  1446,   565,   531,   570,
    1017,   601,   602,   476,  1587,   601,   602,   491,  1533,   484,
     978,    17,  1029,    14,  1235,  2036,  1492,  2291,   150,  2038,
    1506,  2039,   526,  2040,  1266,  1299,   721,   722,  1373,  1193,
    1194,   480,  1195,   801,   550,  2095,  2096,  2097,  2098,  2099,
    2100,  1088,  1349,  2103,  2104,  2105,  2106,  2107,  2108,  1060,
    2110,  1508,  1170,  1088,  1575,  1088,  2120,  1389,  1412,  1433,
     403,    54,  2192,  1446,  1524,  1088,  2193,  2085,    30,  1088,
    1436,  1100,   481,  2143,  1456,  1365,  1278,    55,    41,    56,
     418,    57,    80,    58,    55,  1500,    56,   200,    57,  1472,
      58,   404,  1441,  1518,   510,   584,  1598,   651,   310,   118,
     601,   602,   559,   148,   564,   544,   569,  1604,  2121,  2122,
    2123,   275,   278,   272,   269,   203,  2135,  2137,  2306,  2307,
     222,  1481,   204,   601,   602,   817,   205,  2174,  2175,  2176,
    2177,   206,   429,  2181,  2183,   430,   545,  2186,   431,  1027,
    1083,  1700,  1701,  2200,  2202,  2204,   207,  1143,   208,  1702,
     151,   152,  2207,   604,  1072,   238,   153,   154,   614,   151,
     152,  1175,   257,   132,  1088,   676,   258,   677,   292,  1057,
    1112,  1495,  1496,   611,   612,  2215,   293,   723,   724,   151,
     152,   984,   678,   294,   985,   153,   154,  1088,   299,   295,
    1224,   370,   371,   336,   818,   819,   683,   820,   601,   602,
     153,   154,   151,   152,   368,   687,   300,     1,     2,   396,
     397,   398,   399,  1527,   370,   371,   377,   734,  2244,  1103,
     301,   296,  2246,   382,  2128,   387,  1554,  1555,   302,   151,
     152,   664,   394,  1556,  1557,   153,   154,   401,   303,   402,
     304,   709,   409,  1144,    20,    21,   153,   154,   720,    25,
      26,   216,   305,   217,    33,    34,   306,  1176,   307,  1558,
     308,   126,   309,   127,   410,   128,  1748,   129,    44,    45,
    1750,   218,  1554,  1555,  1752,   411,  1951,   413,  1754,   151,
     152,   219,  1756,   601,   602,   412,  1225,   415,   759,   760,
     414,   130,   416,   703,   121,   122,   437,  1092,  2251,   220,
     165,   166,  1102,  2257,  2258,   221,  2304,  1615,  1839,   464,
    1841,   499,  1843,   769,  1845,   131,  1847,  1616,   502,  1617,
     507,  1618,   516,  1619,   732,  1620,  1136,  1621,   404,   151,
     152,   788,   739,   601,   602,   170,   171,   418,  1160,  1622,
    1173,   175,   176,   611,   612,   521,  1189,   532,  1710,   533,
    1714,   757,  1718,   534,  1722,   578,  1726,   556,  1961,   561,
    1759,  1643,  1644,   566,  1760,   180,   181,   571,  1761,  1222,
     796,   723,   724,   151,   152,   834,  1232,   601,   602,   579,
    1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,   757,  1711,
     580,  1715,  1759,  1719,   581,  1723,  1760,  1727,   185,   186,
    1761,   856,   818,   819,   582,   820,  2045,   800,  1122,   190,
     191,   589,   151,   152,  1123,  1124,   601,   602,   153,   154,
    1125,  1126,   591,   881,   195,   196,   611,   612,  1193,  1194,
     590,  1195,   892,   211,   212,  1442,   240,   241,   151,   152,
    1430,  1431,   796,   723,   724,   151,   152,   592,   905,   601,
     602,   259,   260,   287,   288,   338,   339,   916,   593,   611,
     612,   343,   344,   348,   349,   594,  1204,   353,   354,   358,
     359,   510,   935,   389,   390,   423,   424,   619,   871,   439,
     440,   945,  2056,   626,  1762,   627,  1763,   628,  1764,   629,
    1765,  1190,  1766,  1383,  1767,   630,  1768,   633,  1769,   631,
    1770,   634,  1771,  2084,  1772,   632,  1773,   635,  1774,   648,
    1775,   990,  1776,   656,  1777,   584,  1762,   668,  1763,   669,
    1764,   667,  1765,  1422,  1766,   670,  1767,   671,  1768,   674,
    1769,  1443,  1770,   684,  1771,   685,  1772,   686,  1773,  1466,
    1774,   688,  1775,   691,  1776,   695,  1777,   444,   445,   692,
     449,   450,   636,  1038,   454,   455,   459,   460,   494,   495,
    1263,   693,  1046,   489,   490,   551,   552,   694,   573,   574,
    1122,   651,  2154,  1374,   151,   152,  1123,  1124,   601,   602,
     153,   154,  1125,  1126,   706,  2162,   598,   599,   611,   612,
     608,   609,   660,   661,   699,   700,  1166,  1167,  1567,   715,
    2167,   710,   711,  1413,   735,   736,   777,   778,   782,   783,
     791,   792,   835,   836,  1440,   857,   858,   867,   868,  1457,
     707,  1864,   708,  1865,   897,  1866,   718,  1867,   719,  1868,
     742,  1869,  1310,  1870,  2180,  1871,   743,  1872,   750,  1873,
     761,  1874,   767,  1875,   768,  1876,   770,  1877,   745,  1878,
     790,  1879,   774,  1880,   789,  1881,   802,  1882,   827,  1883,
     805,  1884,   828,  1885,   831,  1886,   841,  1887,   845,  1888,
     840,  1889,   847,  1890,  1202,  2218,  1101,  1864,   812,  1865,
     849,  1866,   850,  1867,   853,  1868,   862,  1869,   873,  1870,
     874,  1871,  2182,  1872,   863,  1873,   875,  1874,   878,  1875,
    1132,  1876,   887,  1877,   888,  1878,   893,  1879,   897,  1880,
     900,  1881,   901,  1882,  1171,  1883,   894,  1884,   902,  1885,
     911,  1886,   912,  1887,  1589,  1888,  1864,  1889,  1865,  1890,
    1866,   917,  1867,   918,  1868,   924,  1869,   929,  1870,   941,
    1871,   921,  1872,  1220,  1873,   942,  1874,   947,  1875,   946,
    1876,   959,  1877,   976,  1878,   983,  1879,   992,  1880,   950,
    1881,  2199,  1882,  1001,  1883,  1015,  1884,  1035,  1885,  1007,
    1886,  1010,  1887,  1022,  1888,  1034,  1889,  1563,  1890,  1864,
    1039,  1865,  1052,  1866,   978,  1867,   984,  1868,  1058,  1869,
    1067,  1870,  1075,  1871,  1076,  1872,  1072,  1873,  1081,  1874,
    1017,  1875,  1068,  1876,  1084,  1877,  1029,  1878,  1104,  1879,
    1105,  1880,  1113,  1881,  1110,  1882,  2201,  1883,  1864,  1884,
    1865,  1885,  1866,  1886,  1867,  1887,  1868,  1888,  1869,  1889,
    1870,  1890,  1871,  1060,  1872,  1145,  1873,  1114,  1874,  1150,
    1875,  1191,  1876,  1243,  1877,  1204,  1878,  1244,  1879,  1245,
    1880,  1246,  1881,  1257,  1882,  1258,  1883,  2203,  1884,  1864,
    1885,  1865,  1886,  1866,  1887,  1867,  1888,  1868,  1889,  1869,
    1890,  1870,  1247,  1871,  1274,  1872,  1281,  1873,  1282,  1874,
    1284,  1875,  1291,  1876,  1307,  1877,  1280,  1878,  2245,  1879,
    1864,  1880,  1865,  1881,  1866,  1882,  1867,  1883,  1868,  1884,
    1869,  1885,  1870,  1886,  1871,  1887,  1872,  1888,  1873,  1889,
    1874,  1890,  1875,  1311,  1876,  1234,  1877,  1317,  1878,  1334,
    1879,  1233,  1880,  1318,  1881,  1319,  1882,  1320,  1883,  1321,
    1884,  1333,  1885,  1336,  1886,  1339,  1887,  1340,  1888,  1341,
    1889,  1264,  1890,   882,   883,   906,   907,  1122,   930,   931,
    1382,   151,   152,  1123,  1124,   601,   602,   153,   154,  1125,
    1126,   936,   937,   954,   955,   611,   612,   960,   961,   966,
     967,  1127,  1128,   971,   972,    81,  1265,    82,    83,    84,
    1421,    85,    86,    87,  1347,    88,    89,    90,  1435,    91,
      92,    93,  1350,    94,    95,  1122,  1465,  1351,   921,   151,
     152,  1123,  1124,   601,   602,   153,   154,  1125,  1126,   996,
     997,  1002,  1003,   611,   612,  1047,  1048,  1212,  1213,  1093,
    1094,  1117,  1118,  1151,  1152,  1161,  1162,  1207,  1208,  1252,
    1253,  1292,  1293,  1326,  1327,  1375,  1376,  1390,  1391,  1399,
    1400,  1414,  1415,   950,  1425,  1426,  1458,  1459,  1482,  1483,
    1495,  1496,  1528,  1529,  1549,  1550,  1570,  1571,  1581,  1582,
    1640,  1641,  1680,  1681,  1832,  1833,  1929,  1930,  1956,  1957,
    1986,  1987,  1990,  1991,  1994,  1995,  1998,  1999,  2046,  2047,
    2051,  2052,  2059,  2060,  2064,  2065,  2069,  2070,  2074,  2075,
    2079,  2080,  2114,  2115,  2117,  2118,  2144,  2145,  2149,  2150,
    2252,  2253,  1741,  2265,  2266,  2274,  2275,  2294,  2295,  1352,
    1355,  2129,  1357,  1298,  1297,  1363,  1366,  1384,  1385,  1397,
    1398,  1444,  1477,  1489,  1490,  1493,  1515,  1535,  1597,  1526,
    1525,  1537,  1536,  1538,  1539,  1542,  1540,  1541,  1446,  1548,
    1507,  1568,  1543,  1569,  1578,  1577,  1579,  1580,  1590,  1594,
    1595,  1596,  1600,  1601,  1605,  1602,  1609,  1610,  1611,  1612,
    1690,  1614,  1665,  1666,  1613,  1689,  1686,  1691,  1692,  1693,
    1694,  1695,  1696,  1697,  1698,  1728,  1742,  1699,  1708,  1712,
    1716,  1588,  1667,  1720,  1724,  1729,  1730,  1731,  1734,  1735,
    1736,  1737,  1738,  1739,  1740,  1746,  1817,  1747,  1758,  1816,
    1828,  1850,  1820,  1821,  1822,  1823,  1824,  2130,  1825,  1826,
    1827,  1837,  1838,  1852,  1854,  1924,  1856,  1858,  1946,  1947,
    1952,  1953,  1963,  1964,  1967,  1968,  1979,  1971,  1985,  1972,
    1989,  1975,  1976,  1993,  1983,  1997,  2001,  2031,  1980,  2032,
    2033,  2028,  2034,  2035,  2037,  2042,  2086,  2058,  2087,  2088,
    2090,  2092,  2140,  2094,  2134,  2089,  2139,  2124,  2156,  2170,
    1733,  2091,  2171,  2141,  2161,  2142,  2172,  2093,  2173,  2179,
    2178,  2184,  2185,  2187,  2188,  2189,  2198,  2205,  2206,  2208,
    2209,  2210,  2212,  2220,  2211,  2222,  2213,  2228,  2225,  2240,
    2226,  2247,  2214,  2241,  2227,  2248,  2235,  2242,  2263,  2264,
    2243,  2249,  1496,  2282,  2280,  2292,  2284,  2315,  2316,  2317,
    2285,  2319,  2320,  2321,  2329,  2322,  2325,  2326,  2328,  2337,
    2327,  2341,  2340,  2344,  2345,  2332,  2346,  2347,  2339,  2350,
    2351,  2352,   117,   149,   517,    40,   264,   595,   522,   239,
     337,   689,   657,   696,   438,   621,   787,   842,  1036,  1085,
    1115,  1342,  1344,  1077,  1314,  1312,  1358,  1360,  1545,  1040,
     771,  1285,  2286,   848,  2318,  1215,  1099,  1434,  1131,  2221,
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
       4,   377,     4,     4,   524,  1080,   382,     4,    78,     4,
       4,     6,     7,  1078,    10,    11,  1080,     4,   717,     6,
       7,  1086,   773,  1346,  1071,     4,    56,     6,     7,    51,
      60,   118,    67,    56,  1109,   147,    66,    60,  1080,  1362,
      10,    11,    34,    66,   111,  1109,    67,    67,   150,    67,
      80,  1116,    10,    11,    10,   754,   659,    80,   150,   150,
      52,    10,    11,  1811,    10,  1813,    96,  1109,    10,    11,
     145,   148,  1326,    96,    66,   148,   145,   597,    46,     4,
      48,   149,    74,     4,     4,   150,     4,   280,   896,     6,
       7,  1788,    84,  1790,    86,   698,     4,  1794,    66,     4,
     246,  1148,   248,  1425,   250,  1802,    98,  1804,    76,  1806,
     102,  1808,   104,    36,   106,    38,   108,    40,  1815,    42,
       4,  1375,     4,     4,   717,   237,    94,   120,   214,  1180,
       4,     4,   100,  1082,     6,     4,  1390,  1348,     0,   659,
       4,  2224,   335,    66,    92,   844,    73,   145,    72,    85,
     236,    99,    88,  1364,    78,    82,     6,     7,  1406,  1907,
    1414,   754,  1111,    10,    11,  1862,    69,    90,    49,    10,
      75,    25,    97,   169,   170,  1226,    93,    95,   698,    61,
     556,   177,   178,    91,   394,   561,    10,   333,  1510,    53,
     566,   278,    61,   295,  1942,   272,  2279,   167,   168,   272,
     291,    85,  1450,  1250,  1458,   273,   416,   299,    81,   167,
     168,   167,   168,    87,    14,   468,   281,   470,   428,   472,
     295,   167,   168,   335,  1547,   167,   168,    77,  1482,   101,
     299,   303,   299,    15,   336,  1932,   157,   157,    31,  1936,
    1423,  1938,   312,  1940,   336,   336,    10,    11,  1313,   152,
     153,     6,   155,   773,   464,  2003,  2004,  2005,  2006,  2007,
    2008,   231,  1275,  2011,  2012,  2013,  2014,  2015,  2016,   291,
    2018,   336,  1080,   231,  1528,   231,  2024,  1324,  1343,  1354,
      57,   304,   231,   281,  1467,   231,   235,  1984,   305,   231,
    1354,  1042,    47,  2041,  1359,  1308,   300,   327,   307,   329,
     335,   331,   121,   333,   327,   300,   329,    22,   331,   296,
     333,    88,  1354,   292,   335,   335,  1570,   335,   310,   309,
     167,   168,   468,   304,   470,     4,   472,  1581,  2025,  2026,
    2027,   332,   334,   330,   328,     5,  2033,  2034,   179,   180,
     308,  1388,     5,   167,   168,    83,     5,  2095,  2096,  2097,
    2098,     5,   206,  2101,  2102,   209,    35,  2105,   212,   966,
    1026,   197,   198,  2111,  2112,  2113,     5,  1066,   311,   205,
     163,   164,  2120,   519,   158,   306,   169,   170,   524,   163,
     164,  1080,     3,   306,   231,    16,     3,    18,   123,   996,
    1056,   232,   233,   177,   178,  2143,   127,   161,   162,   163,
     164,    68,    33,   131,    71,   169,   170,   231,    34,   135,
    1109,   175,   176,   308,   152,   153,   626,   155,   167,   168,
     169,   170,   163,   164,    10,   635,    52,    12,    13,   441,
     442,   443,   444,  1480,   175,   176,    10,   690,  2186,  1042,
      66,   139,  2190,    10,   440,    10,   195,   196,    74,   163,
     164,   597,     6,   202,   203,   169,   170,     8,    84,     8,
      86,   671,    61,  1066,    10,    11,   169,   170,   678,    10,
      11,    46,    98,    48,    10,    11,   102,  1080,   104,   228,
     106,    36,   108,    38,   328,    40,  1708,    42,    10,    11,
    1712,    66,   195,   196,  1716,   330,  1819,   334,  1720,   163,
     164,    76,  1724,   167,   168,   332,  1109,    97,   718,   719,
      81,    66,     6,   659,    10,    11,   310,  1037,  2215,    94,
      10,    11,  1042,   226,   227,   100,  2274,   243,  1748,    32,
    1750,    91,  1752,   743,  1754,    90,  1756,   253,     3,   255,
       6,   257,    57,   259,   690,   261,  1066,   263,    88,   163,
     164,   761,   698,   167,   168,    10,    11,   335,  1078,   275,
    1080,    10,    11,   177,   178,    67,  1086,     8,  1671,     8,
    1673,   717,  1675,     8,  1677,    49,  1679,    10,  1832,    10,
     281,   199,   200,    10,   285,    10,    11,    10,   289,  1109,
     160,   161,   162,   163,   164,   805,  1116,   167,   168,    47,
     218,   219,   220,   221,   222,   223,   224,   225,   754,  1671,
     101,  1673,   281,  1675,    95,  1677,   285,  1679,    10,    11,
     289,   831,   152,   153,    77,   155,  1949,   773,   159,    10,
      11,    41,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    43,   853,    10,    11,   177,   178,   152,   153,
       8,   155,   862,    10,    11,  1354,    10,    11,   163,   164,
     191,   192,   160,   161,   162,   163,   164,    39,   878,   167,
     168,    10,    11,    10,    11,    10,    11,   887,    37,   177,
     178,    10,    11,    10,    11,    67,   217,    10,    11,    10,
      11,   335,   902,    10,    11,    10,    11,   312,   844,    10,
      11,   911,  1956,     6,   405,     6,   407,     6,   409,     6,
     411,  1087,   413,  1316,   415,    85,   417,    35,   419,    87,
     421,    53,   423,   424,   425,    75,   427,     6,   429,     6,
     431,   941,   433,    67,   435,   335,   405,     3,   407,   336,
     409,    89,   411,  1346,   413,     3,   415,    30,   417,    10,
     419,  1354,   421,     8,   423,     8,   425,     8,   427,  1362,
     429,    99,   431,   107,   433,    67,   435,    10,    11,   109,
      10,    11,    92,   983,    10,    11,    10,    11,    10,    11,
    1156,   105,   992,     6,     7,    10,    11,   103,    10,    11,
     159,   335,  2046,  1313,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   336,  2059,    10,    11,   177,   178,
      10,    11,    10,    11,    10,    11,   185,   186,  1517,    84,
    2074,    10,    11,  1343,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,  1354,    10,    11,    10,    11,  1359,
       8,   351,     8,   353,   213,   355,     3,   357,     3,   359,
     336,   361,  1228,   363,   364,   365,     6,   367,    60,   369,
       6,   371,     3,   373,   336,   375,    73,   377,    82,   379,
       8,   381,   301,   383,    93,   385,   297,   387,     8,   389,
      24,   391,   293,   393,    21,   395,    85,   397,     5,   399,
      61,   401,    83,   403,  1104,  2149,  1042,   351,    88,   353,
       6,   355,   277,   357,    20,   359,     6,   361,   154,   363,
       8,   365,   366,   367,   144,   369,    70,   371,    28,   373,
    1066,   375,     6,   377,   144,   379,   302,   381,   213,   383,
      89,   385,    79,   387,  1080,   389,   110,   391,    23,   393,
       6,   395,    50,   397,  1547,   399,   351,   401,   353,   403,
     355,   298,   357,    44,   359,    44,   361,     8,   363,     6,
     365,   210,   367,  1109,   369,   279,   371,    44,   373,   294,
     375,     8,   377,     6,   379,     6,   381,    29,   383,   207,
     385,   386,   387,     8,   389,     6,   391,   145,   393,   335,
     395,   319,   397,   335,   399,     8,   401,  1517,   403,   351,
      71,   353,   335,   355,   299,   357,    68,   359,     6,   361,
      45,   363,     8,   365,   145,   367,   158,   369,    45,   371,
     295,   373,   315,   375,   111,   377,   299,   379,     6,   381,
     144,   383,     8,   385,    45,   387,   388,   389,   351,   391,
     353,   393,   355,   395,   357,   397,   359,   399,   361,   401,
     363,   403,   365,   291,   367,   317,   369,    51,   371,     8,
     373,     8,   375,     8,   377,   217,   379,     3,   381,     3,
     383,     3,   385,     6,   387,   156,   389,   390,   391,   351,
     393,   353,   395,   355,   397,   357,   399,   359,   401,   361,
     403,   363,   313,   365,     3,   367,     6,   369,     5,   371,
      69,   373,     8,   375,     3,   377,   300,   379,   380,   381,
     351,   383,   353,   385,   355,   387,   357,   389,   359,   391,
     361,   393,   363,   395,   365,   397,   367,   399,   369,   401,
     371,   403,   373,   336,   375,   295,   377,     6,   379,   234,
     381,   150,   383,     8,   385,     8,   387,     8,   389,   321,
     391,     8,   393,   148,   395,   320,   397,   296,   399,   336,
     401,   150,   403,    10,    11,    10,    11,   159,    10,    11,
    1316,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    10,    11,    10,    11,   177,   178,    10,    11,    10,
      11,   183,   184,    10,    11,   122,   299,   124,   125,   126,
    1346,   128,   129,   130,     8,   132,   133,   134,  1354,   136,
     137,   138,   300,   140,   141,   159,  1362,     8,   210,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    10,
      11,    10,    11,   177,   178,    10,    11,   181,   182,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   207,    10,    11,    10,    11,    10,    11,
     232,   233,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,   173,   174,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,   244,   245,    10,    11,
      10,    11,  1698,    10,    11,    10,    11,    10,    11,   154,
       6,  2030,   336,   291,   150,     8,   292,     8,   323,   316,
       8,     8,   325,   318,     6,    10,     3,   314,  1558,   151,
     296,   157,     8,     6,     8,   151,     8,   300,   281,     8,
     150,   292,   336,   151,   149,   322,     6,     6,   242,     3,
       8,     8,   324,     8,   282,     8,     8,     6,     6,     6,
       3,   151,     8,     8,   326,   241,   201,     8,     8,     8,
       8,     8,     8,     8,     8,     3,   267,    10,    10,    10,
      10,  1547,  1612,    10,    10,    10,     8,    10,     6,     6,
       6,     6,     6,     6,     6,     3,   247,     8,     8,     6,
     269,   276,     8,     8,     8,     8,     8,  2030,     8,     8,
       8,     8,     6,   231,   231,   438,   231,   231,     8,   249,
     254,   271,     8,   271,   256,   271,   264,   258,     8,   271,
       8,   260,   271,     8,   262,     8,   406,   436,   271,     3,
      10,   434,    10,   414,   418,   430,     6,   268,   432,     6,
       6,     6,   420,   408,     8,   282,   416,   382,   156,     8,
    1690,   286,     8,   422,   270,   426,     8,   290,     8,   362,
     360,   368,   370,   374,   376,   378,   384,   392,   394,   400,
     402,   404,     3,   248,   398,   148,   410,   148,   272,   352,
     272,     8,   412,   354,   272,     8,   272,   356,  2217,   250,
     358,   396,   233,     6,   372,    10,     8,   380,     8,     8,
     428,   246,     6,     6,     3,   157,     8,     8,     6,     6,
     149,   235,     8,     8,     8,   149,     8,    10,   149,     6,
       8,   274,    40,    60,   406,    25,   156,   512,   420,   134,
     224,   639,   586,   653,   312,   528,   754,   814,   980,  1031,
    1062,  1268,  1271,  1019,  1240,  1237,  1301,  1304,  1511,   987,
     747,  1197,  2252,   822,  2286,  1109,  1042,  1354,  1066,  2156,
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
       0,    12,    13,   446,   447,   448,     0,   120,   455,   456,
    1087,  1088,    14,   449,    15,   453,   454,   303,   457,   458,
      10,    11,  1089,  1090,  1091,    10,    11,   450,   451,   452,
     305,   537,   538,    10,    11,   459,   460,   461,  1092,  1093,
     455,   307,   591,   592,    10,    11,   539,   540,   541,    56,
      60,    66,    80,    96,   304,   327,   329,   331,   333,   462,
     463,   464,   465,   466,   481,   482,   487,   488,   493,   494,
     499,   500,   505,   506,   511,   512,   517,   518,   523,   524,
     121,   122,   124,   125,   126,   128,   129,   130,   132,   133,
     134,   136,   137,   138,   140,   141,  1094,  1095,  1096,  1097,
    1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1114,   453,   309,   643,
     644,    10,    11,   593,   594,   595,    36,    38,    40,    42,
      66,    90,   306,   542,   543,   544,   545,   546,   551,   552,
     558,   559,   565,   566,   572,   573,   577,   578,   304,   464,
      31,   163,   164,   169,   170,   467,   468,   469,  1080,  1385,
    1386,  1387,  1412,  1413,  1414,    10,    11,   483,   484,   485,
      10,    11,   489,   490,   491,    10,    11,   495,   496,   497,
      10,    11,   501,   502,   503,    10,    11,   507,   508,   509,
      10,    11,   513,   514,   515,    10,    11,   519,   520,   521,
      22,   525,  1075,     5,     5,     5,     5,     5,   311,   738,
     739,    10,    11,   645,   646,   647,    46,    48,    66,    76,
      94,   100,   308,   596,   597,   598,   599,   600,   605,   606,
     611,   612,   617,   618,   623,   624,   629,   630,   306,   544,
      10,    11,   547,   548,   549,   553,   554,   560,   561,   567,
     568,   574,  1385,   579,  1075,  1084,  1085,     3,     3,    10,
      11,   470,   471,   472,   469,     4,    61,   486,     4,   328,
     492,     4,   330,   498,     4,   332,   504,     4,   334,   510,
       4,    81,   516,     4,    97,   522,  1084,    10,    11,   526,
     527,   528,   123,   127,   131,   135,   139,   740,   741,    34,
      52,    66,    74,    84,    86,    98,   102,   104,   106,   108,
     310,   648,   649,   650,   651,   652,   657,   658,   663,   664,
     669,   670,   675,   676,   681,   682,   698,   699,   705,   706,
     712,   713,   719,   720,   724,   725,   308,   598,    10,    11,
     601,   602,   603,    10,    11,   607,   608,   609,    10,    11,
     613,   614,   615,    10,    11,   619,   620,   621,    10,    11,
     625,   626,   627,   631,  1075,     4,    91,   550,    10,   556,
     175,   176,   555,  1385,  1415,  1416,  1417,    10,   563,   562,
    1385,  1415,    10,   570,   569,  1385,  1415,    10,   575,    10,
      11,   580,   581,   582,     6,     8,   441,   442,   443,   444,
    1086,     8,     8,    57,    88,   473,   474,   475,   476,    61,
     328,   330,   332,   334,    81,    97,     6,    67,   335,   529,
     530,   531,   532,    10,    11,   743,   744,   745,    25,   206,
     209,   212,   742,  1078,  1347,  1353,  1358,   310,   650,    10,
      11,   653,   654,   655,    10,    11,   659,   660,   661,    10,
      11,   665,   666,   667,    10,    11,   671,   672,   673,    10,
      11,   677,   678,   679,    32,   683,  1081,   700,   701,   707,
     708,   714,   715,   721,  1385,   726,  1075,     4,    49,   604,
       6,    47,   610,     6,   101,   616,     4,    95,   622,     6,
       7,    77,   628,  1082,    10,    11,   632,   633,   634,    91,
     557,  1082,     3,   564,  1082,   571,  1082,     6,   576,    67,
     335,   583,   584,   585,   586,  1084,    57,   475,   477,   478,
    1084,    67,   531,   533,   534,    78,   312,   746,   747,   748,
     749,  1084,     8,     8,     8,     4,    85,   656,     4,    87,
     662,     4,    75,   668,     4,    35,   674,     4,    53,   680,
    1084,    10,    11,   684,   685,   686,    10,   703,   702,  1385,
    1415,    10,   710,   709,  1385,  1415,    10,   717,   716,  1385,
    1415,    10,   722,    10,    11,   727,   728,   729,    49,    47,
     101,    95,    77,    67,   335,   635,   636,   637,   638,    41,
       8,    43,    39,    37,    67,   585,   587,   588,    10,    11,
     480,   167,   168,   479,  1385,  1394,  1395,  1396,    10,    11,
     536,   177,   178,   535,  1385,  1394,  1418,  1419,  1420,   312,
      72,   748,  1048,  1049,   750,   751,     6,     6,     6,     6,
      85,    87,    75,    35,    53,     6,    92,    99,   687,   688,
     689,   690,   704,  1082,   711,  1082,   718,  1082,     6,   723,
      67,   335,   730,   731,   732,   733,    67,   637,   639,   640,
      10,    11,   590,   589,  1385,  1394,  1418,    89,     3,   336,
       3,    30,  1050,  1079,    10,   756,    16,    18,    33,   752,
     753,   754,   755,  1084,     8,     8,     8,  1084,    99,   689,
     691,   107,   109,   105,   103,    67,   732,   734,   735,    10,
      11,   642,   641,  1385,  1394,  1418,   336,     8,     8,  1084,
      10,    11,  1051,  1052,  1053,    84,   757,   758,     3,     3,
    1084,    10,    11,   161,   162,   692,   693,   694,   695,  1379,
    1380,  1381,  1385,  1412,  1415,    10,    11,   737,   736,  1385,
    1394,  1418,   336,     6,    73,    82,  1054,  1055,  1056,  1057,
      60,   773,   774,   759,   760,   761,  1080,  1385,  1412,  1084,
    1084,     6,     6,     7,    93,   696,   697,     3,   336,  1084,
      73,  1056,  1058,  1059,   301,   779,   780,    10,    11,   775,
     776,   777,    10,    11,   762,   763,   764,   761,  1084,    93,
       8,    10,    11,  1061,  1062,  1063,   160,  1060,  1350,  1379,
    1385,  1394,   297,   857,   858,    24,   781,  1077,     4,    61,
     778,    85,    88,   765,   766,   767,   768,    83,   152,   153,
     155,  1064,  1065,  1066,  1067,  1068,  1069,     8,   293,   919,
     920,    21,   859,  1074,  1084,    10,    11,   782,   783,   784,
      61,    85,   767,   769,   770,     5,  1070,    83,  1066,     6,
     277,   981,   982,    20,   921,  1071,  1084,    10,    11,   860,
     861,   862,     6,   144,   785,   786,   787,    10,    11,   772,
     771,  1385,  1412,   154,     8,    70,  1025,  1026,    28,   983,
    1072,  1084,    10,    11,   922,   923,   924,     6,   144,   863,
     864,   865,  1084,   302,   110,   799,   800,   213,   788,  1356,
      89,    79,    23,  1027,  1076,  1084,    10,    11,   984,   985,
     986,     6,    50,   925,   926,   927,  1084,   298,    44,   877,
     878,   210,   866,  1352,    44,   815,   816,   801,  1356,     8,
      10,    11,   789,   790,   791,  1084,    10,    11,  1028,  1029,
    1030,     6,   279,   987,   988,  1084,   294,    44,   939,   940,
     207,   928,  1346,   890,    10,    11,   879,   880,   881,     8,
      10,    11,   867,   868,   869,   828,    10,    11,   817,   818,
     819,    10,    11,   802,   803,   804,     6,   145,   299,   792,
     793,   794,   795,     6,    68,    71,  1031,  1032,  1033,  1034,
    1084,  1023,    29,   989,  1073,   952,    10,    11,   941,   942,
     943,     8,    10,    11,   929,   930,   931,   335,   891,   892,
     319,   882,   883,  1137,  1138,     6,   145,   295,   870,   871,
     872,   873,   335,   829,   830,   820,   821,  1137,   111,   299,
     805,   806,   807,   808,     8,   145,   794,   796,  1084,    71,
    1033,  1035,  1036,   118,   278,  1024,  1084,    10,    11,   990,
     991,   992,   335,   953,   954,   944,   945,  1137,     6,    51,
     291,   932,   933,   934,   935,   893,   894,    45,   315,   884,
    1143,  1144,   158,  1179,  1348,     8,   145,   872,   874,   831,
     832,    45,   822,  1143,   111,   807,   809,    10,   231,   797,
     798,  1369,  1394,    10,    11,  1038,  1039,  1040,  1037,  1350,
    1379,  1385,  1394,  1418,     6,   144,   994,   995,   955,   956,
      45,   946,  1143,     8,    51,   934,   936,    10,    11,   896,
     897,   898,   159,   165,   166,   171,   172,   183,   184,   895,
    1349,  1352,  1385,  1388,  1389,  1390,  1394,  1397,  1398,  1399,
    1406,  1407,  1408,  1412,  1418,   317,   885,  1149,  1150,  1179,
       8,    10,    11,  1139,  1140,  1141,    10,   875,   876,  1369,
    1394,    10,    11,   834,   835,   836,   185,   186,   833,  1349,
    1356,  1385,  1388,  1394,  1406,  1412,  1418,  1424,  1425,  1426,
     823,  1149,    10,    11,   810,   811,   812,   813,  1369,  1394,
    1082,     8,    69,   152,   153,   155,  1041,  1042,  1043,  1044,
    1045,  1046,  1084,  1002,   217,   996,  1351,    10,    11,   958,
     959,   960,   181,   182,   957,  1346,  1349,  1382,  1383,  1384,
    1385,  1388,  1394,  1406,  1412,  1418,   947,  1149,    10,   937,
     938,  1369,  1394,   150,   295,   336,   899,   900,   901,   902,
     909,   910,   911,     8,     3,     3,     3,   313,   886,  1155,
    1156,  1179,    10,    11,  1145,  1146,  1147,     6,   156,  1115,
    1116,  1123,  1142,  1082,   150,   299,   336,   837,   838,   839,
     840,   847,   848,   849,     3,   824,  1155,     4,   300,   814,
     300,     6,     5,  1047,    69,  1043,   280,   335,   993,  1003,
    1004,     8,    10,    11,   997,   998,   999,   150,   291,   336,
     961,   962,   963,   964,   971,   972,   973,     3,   948,  1155,
    1082,   336,   901,   903,   910,   912,   913,     6,     8,     8,
       8,   321,   887,  1161,  1162,  1179,    10,    11,  1151,  1152,
    1153,  1115,  1148,     8,   234,  1359,   148,  1117,  1118,   320,
     296,   336,   839,   841,   848,   850,   851,     8,   825,  1161,
     300,     8,   154,  1005,  1006,     6,  1001,   336,   963,   965,
     972,   974,   975,     8,   949,  1161,   292,    10,    11,   904,
     905,   906,   907,  1369,  1394,    10,    11,   915,   916,   917,
     914,  1348,  1385,  1418,     8,   323,   888,  1167,  1168,  1179,
      10,    11,  1157,  1158,  1159,  1115,  1154,   316,     8,    10,
      11,  1124,  1125,  1126,  1119,  1120,    10,    11,   842,   843,
     844,   845,  1369,  1394,    10,    11,   853,   854,   855,   852,
    1348,  1385,  1418,   826,  1167,    10,    11,  1008,  1009,  1010,
     191,   192,  1007,  1349,  1351,  1385,  1388,  1391,  1392,  1393,
    1394,  1406,  1412,  1418,     8,   145,   281,  1000,  1180,  1181,
      10,    11,   966,   967,   968,   969,  1369,  1394,    10,    11,
     977,   978,   979,   976,  1348,  1385,  1418,   950,  1167,     4,
       6,     7,   296,   908,  1083,   918,  1115,   325,   889,  1173,
    1174,  1179,    10,    11,  1163,  1164,  1165,  1115,  1160,   318,
       6,     4,   157,    10,  1122,   232,   233,  1121,  1370,  1372,
     300,   846,  1083,   856,  1115,   827,  1173,   150,   336,  1011,
    1012,  1013,  1014,  1015,  1180,     3,  1182,  1183,   292,   970,
    1083,   980,  1115,   951,  1173,   296,   151,  1179,    10,    11,
    1169,  1170,  1171,  1115,  1166,   314,     8,   157,     6,     8,
       8,   300,   151,   336,  1180,  1014,  1016,  1017,     8,    10,
      11,  1185,  1186,  1187,   195,   196,   202,   203,   228,  1184,
    1345,  1354,  1371,  1394,  1409,  1410,  1411,  1412,   292,   151,
      10,    11,  1175,  1176,  1177,  1115,  1172,   322,   149,     6,
       6,    10,    11,  1019,  1020,  1021,  1018,  1348,  1385,  1418,
     242,  1188,  1189,  1190,     3,     8,     8,  1084,  1115,  1178,
     324,     8,     8,  1022,  1115,   282,  1195,  1191,  1192,     8,
       6,     6,     6,   326,   151,   243,   253,   255,   257,   259,
     261,   263,   275,  1196,  1197,  1198,  1222,  1223,  1235,  1236,
    1262,  1263,  1280,  1281,  1293,  1294,  1311,  1312,  1315,  1316,
      10,    11,  1194,   199,   200,   218,   219,   220,   221,   222,
     223,   224,   225,  1193,  1360,  1361,  1362,  1363,  1364,  1373,
    1374,  1375,  1376,  1377,  1378,     8,     8,  1084,  1199,  1200,
    1224,  1225,  1237,  1238,  1264,  1265,  1282,  1283,  1295,  1296,
     173,   174,  1313,  1403,  1404,  1405,   201,  1317,  1344,   241,
       3,     8,     8,     8,     8,     8,     8,     8,     8,    10,
     197,   198,   205,  1201,  1355,  1400,  1401,  1402,    10,  1226,
    1355,  1400,    10,  1239,  1355,  1400,    10,  1266,  1355,  1400,
      10,  1284,  1355,  1400,    10,  1297,  1355,  1400,     3,    10,
       8,    10,  1318,  1084,     6,     6,     6,     6,     6,     6,
       6,  1082,   267,  1202,  1204,  1205,     3,     8,  1204,  1227,
    1204,  1240,  1204,  1267,  1204,  1285,  1204,  1298,     8,   281,
     285,   289,   405,   407,   409,   411,   413,   415,   417,   419,
     421,   423,   425,   427,   429,   431,   433,   435,  1501,  1502,
    1503,  1506,  1507,  1510,  1511,  1514,  1515,  1518,  1519,  1521,
    1522,  1524,  1525,  1527,  1528,  1530,  1531,  1534,  1535,  1539,
    1540,  1542,  1543,  1545,  1546,  1548,  1549,  1551,  1552,  1554,
    1557,  1558,  1560,  1561,  1563,  1564,     6,   247,  1320,  1321,
       8,     8,     8,     8,     8,     8,     8,     8,   269,  1203,
    1210,  1211,    10,    11,  1206,  1207,  1208,     8,     6,  1210,
    1228,  1210,  1241,  1210,  1268,  1210,  1286,  1210,  1299,  1555,
     276,  1314,   231,  1505,   231,  1509,   231,  1513,   231,  1517,
    1501,  1520,  1501,  1523,   351,   353,   355,   357,   359,   361,
     363,   365,   367,   369,   371,   373,   375,   377,   379,   381,
     383,   385,   387,   389,   391,   393,   395,   397,   399,   401,
     403,  1427,  1428,  1431,  1434,  1436,  1438,  1440,  1442,  1444,
    1446,  1448,  1450,  1452,  1454,  1456,  1458,  1459,  1461,  1463,
    1465,  1467,  1469,  1471,  1472,  1478,  1486,  1489,  1492,  1495,
    1498,  1526,  1501,  1529,   438,  1532,  1538,  1536,  1538,    10,
      11,  1541,  1501,  1544,  1501,  1547,  1501,  1550,  1501,  1553,
    1427,  1559,  1427,  1562,  1501,  1565,     8,   249,  1327,  1328,
    1322,  1348,   254,   271,  1216,  1217,    10,    11,  1212,  1213,
    1214,  1115,  1209,     8,   271,  1229,  1230,   256,   271,  1242,
    1243,   258,   271,  1269,  1270,   260,   271,  1287,  1288,   264,
     271,  1300,  1301,   262,  1556,     8,    10,    11,  1504,     8,
      10,    11,  1508,     8,    10,    11,  1512,     8,    10,    11,
    1516,   406,  1501,  1445,  1437,  1439,  1443,  1447,  1449,  1487,
    1499,  1457,  1441,  1464,  1451,  1453,  1455,  1479,  1462,  1493,
    1490,  1496,  1429,  1432,  1435,  1466,  1468,  1470,   434,  1427,
    1474,   436,     3,    10,    10,   414,  1501,   418,  1501,  1501,
    1501,  1427,   430,  1334,  1329,  1348,    10,    11,  1323,  1324,
    1325,    10,    11,  1218,  1219,  1220,  1115,  1215,   268,    10,
      11,  1231,  1232,  1233,    10,    11,  1244,  1245,  1246,    10,
      11,  1271,  1272,  1273,    10,    11,  1289,  1290,  1291,    10,
      11,  1302,  1303,  1304,   424,  1501,     6,   432,     6,   282,
       6,   286,     6,   290,   408,  1427,  1427,  1427,  1427,  1427,
    1427,  1488,  1500,  1427,  1427,  1427,  1427,  1427,  1427,  1482,
    1427,  1494,  1491,  1497,    10,    11,  1430,    10,    11,  1433,
    1427,  1501,  1501,  1501,   382,  1460,    10,    11,   440,  1412,
    1418,  1473,  1475,  1476,     8,  1501,  1533,  1501,  1537,   416,
     420,   422,   426,  1427,   244,   245,  1319,  1335,  1336,    10,
      11,  1330,  1331,  1332,  1115,  1326,   156,  1127,  1128,  1133,
    1221,   270,  1115,  1234,  1247,  1248,  1274,  1115,  1292,  1305,
       8,     8,     8,     8,  1427,  1427,  1427,  1427,   360,   362,
     364,  1427,   366,  1427,   368,   370,  1427,   374,   376,   378,
      10,    11,   231,   235,  1480,  1483,  1484,  1485,   384,   386,
    1427,   388,  1427,   390,  1427,   392,   394,  1427,   400,   402,
     404,   398,     3,   410,   412,  1427,  1337,  1338,  1115,  1333,
     248,  1359,   148,  1129,  1130,   272,   272,   272,   148,  1249,
    1250,   148,   272,  1275,  1276,   272,   148,   272,  1306,  1307,
     352,   354,   356,   358,  1427,   380,  1427,     8,     8,   396,
    1477,  1501,    10,    11,  1340,  1341,  1342,   226,   227,  1339,
    1365,  1366,  1409,  1412,   250,    10,    11,  1134,  1135,  1136,
    1131,  1372,  1251,  1252,    10,    11,  1277,  1278,  1279,  1308,
     372,  1481,     6,  1082,     8,   428,  1189,  1343,  1084,  1084,
       4,   157,    10,  1132,    10,    11,  1254,  1255,  1256,   214,
     236,  1253,  1357,  1368,  1427,    10,   179,   180,  1309,  1310,
    1370,  1372,  1421,  1422,  1423,   380,     8,     8,  1195,   246,
       6,     6,   157,  1082,  1257,     8,     8,   149,     6,     3,
    1084,  1084,   149,   149,   273,  1258,  1259,     6,  1082,   149,
       8,   235,  1260,  1367,     8,     8,     8,    10,  1261,  1082,
       6,     8,   274
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
    osglData->tempC = new GeneralMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1263:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<generalElements>: numberOfValues attribute missing");    
}
    break;

  case 1266:

    {
        ((GeneralMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
        if (osglData->numberOfValues > 0)
            ((MatrixType*)osglData->mtxBlkVec.back())->matrixType = ENUM_MATRIX_TYPE_general;
    }
    break;

  case 1267:

    {
        ((GeneralMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1273:

    {
    osglData->nonzeroCounter = 0;
    osglData->numberOfValues = ((GeneralMatrixElements*)osglData->tempC)->numberOfValues;

    ((GeneralMatrixElements*)osglData->tempC)->value = new GeneralMatrixValues();
    ((GeneralMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    ((GeneralMatrixElements*)osglData->tempC)->value->el
        = new ScalarExpressionTree*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((GeneralMatrixElements*)osglData->tempC)->value->el[i] = new ScalarExpressionTree();
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

        ((GeneralMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
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


