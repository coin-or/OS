
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
     BOOLEAN = 265,
     GREATERTHAN = 266,
     ENDOFELEMENT = 267,
     OSRLSTART = 268,
     OSRLSTARTEMPTY = 269,
     OSRLATTRIBUTETEXT = 270,
     OSRLEND = 271,
     WEIGHTEDOBJECTIVESATT = 272,
     EMPTYWEIGHTEDOBJECTIVESATT = 273,
     TARGETOBJECTIVENAMEATT = 274,
     EMPTYTARGETOBJECTIVENAMEATT = 275,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 276,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 277,
     NUMBEROFOTHERRESULTSATT = 278,
     NUMBEROFOTHERSOLUTIONRESULTSATT = 279,
     NUMBEROFOTHERVARIABLERESULTSATT = 280,
     NUMBEROFSOLUTIONSATT = 281,
     NUMBEROFOTHERMATRIXOBJECTIVERESULTSATT = 282,
     NUMBEROFOTHERMATRIXCONSTRAINTRESULTSATT = 283,
     NUMBEROFOTHERMATRIXPROGRAMMINGRESULTSATT = 284,
     NUMBEROFOTHERMATRIXVARIABLERESULTSATT = 285,
     NUMBEROFSOLVEROUTPUTSATT = 286,
     NUMBEROFSUBSTATUSESATT = 287,
     NUMBEROFTIMESATT = 288,
     TARGETOBJECTIVEIDXATT = 289,
     ACTUALSTARTTIMESTART = 290,
     ACTUALSTARTTIMEEND = 291,
     AVAILABLECPUNUMBERSTART = 292,
     AVAILABLECPUNUMBEREND = 293,
     AVAILABLECPUSPEEDSTART = 294,
     AVAILABLECPUSPEEDEND = 295,
     AVAILABLEDISKSPACESTART = 296,
     AVAILABLEDISKSPACEEND = 297,
     AVAILABLEMEMORYSTART = 298,
     AVAILABLEMEMORYEND = 299,
     BASISSTATUSSTART = 300,
     BASISSTATUSEND = 301,
     CURRENTJOBCOUNTSTART = 302,
     CURRENTJOBCOUNTEND = 303,
     CURRENTSTATESTART = 304,
     CURRENTSTATEEND = 305,
     DUALVALUESSTART = 306,
     DUALVALUESEND = 307,
     ENDTIMESTART = 308,
     ENDTIMEEND = 309,
     IDXSTART = 310,
     IDXEND = 311,
     GENERALSTATUSSTART = 312,
     GENERALSTATUSEND = 313,
     GENERALSUBSTATUSSTART = 314,
     GENERALSUBSTATUSEND = 315,
     MESSAGESTART = 316,
     MESSAGEEND = 317,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 318,
     OPTIMIZATIONSOLUTIONSTATUSEND = 319,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 320,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 321,
     OTHERRESULTSSTART = 322,
     OTHERRESULTSEND = 323,
     OTHERSOLUTIONRESULTSTART = 324,
     OTHERSOLUTIONRESULTEND = 325,
     OTHERSOLUTIONRESULTSSTART = 326,
     OTHERSOLUTIONRESULTSEND = 327,
     OTHERSOLVEROUTPUTSTART = 328,
     OTHERSOLVEROUTPUTEND = 329,
     SCHEDULEDSTARTTIMESTART = 330,
     SCHEDULEDSTARTTIMEEND = 331,
     SERVICEUTILIZATIONSTART = 332,
     SERVICEUTILIZATIONEND = 333,
     SOLUTIONSTART = 334,
     SOLUTIONEND = 335,
     SOLVERINVOKEDSTART = 336,
     SOLVERINVOKEDEND = 337,
     SOLVEROUTPUTSTART = 338,
     SOLVEROUTPUTEND = 339,
     STATUSSTART = 340,
     STATUSEND = 341,
     SUBMITTIMESTART = 342,
     SUBMITTIMEEND = 343,
     SUBSTATUSSTART = 344,
     SUBSTATUSEND = 345,
     SYSTEMINFORMATIONSTART = 346,
     SYSTEMINFORMATIONEND = 347,
     TIMESTART = 348,
     TIMEEND = 349,
     TIMESERVICESTARTEDSTART = 350,
     TIMESERVICESTARTEDEND = 351,
     TIMESTAMPSTART = 352,
     TIMESTAMPEND = 353,
     TIMINGINFORMATIONSTART = 354,
     TIMINGINFORMATIONEND = 355,
     TOTALJOBSSOFARSTART = 356,
     TOTALJOBSSOFAREND = 357,
     USEDCPUNUMBERSTART = 358,
     USEDCPUNUMBEREND = 359,
     USEDCPUSPEEDSTART = 360,
     USEDCPUSPEEDEND = 361,
     USEDDISKSPACESTART = 362,
     USEDDISKSPACEEND = 363,
     USEDMEMORYSTART = 364,
     USEDMEMORYEND = 365,
     VALUESSTRINGSTART = 366,
     VALUESSTRINGEND = 367,
     OTHERMATRIXVARIABLERESULTSTART = 368,
     OTHERMATRIXVARIABLERESULTEND = 369,
     OTHERMATRIXOBJECTIVERESULTSTART = 370,
     OTHERMATRIXOBJECTIVERESULTEND = 371,
     OTHERMATRIXCONSTRAINTRESULTSTART = 372,
     OTHERMATRIXCONSTRAINTRESULTEND = 373,
     OTHERMATRIXPROGRAMMINGRESULTSTART = 374,
     OTHERMATRIXPROGRAMMINGRESULTEND = 375,
     HEADERSTART = 376,
     HEADEREND = 377,
     FILENAMESTART = 378,
     FILENAMEEND = 379,
     FILENAMEEMPTY = 380,
     FILENAMESTARTANDEND = 381,
     FILESOURCESTART = 382,
     FILESOURCEEND = 383,
     FILESOURCEEMPTY = 384,
     FILESOURCESTARTANDEND = 385,
     FILEDESCRIPTIONSTART = 386,
     FILEDESCRIPTIONEND = 387,
     FILEDESCRIPTIONEMPTY = 388,
     FILEDESCRIPTIONSTARTANDEND = 389,
     FILECREATORSTART = 390,
     FILECREATOREND = 391,
     FILECREATOREMPTY = 392,
     FILECREATORSTARTANDEND = 393,
     FILELICENCESTART = 394,
     FILELICENCEEND = 395,
     FILELICENCEEMPTY = 396,
     FILELICENCESTARTANDEND = 397,
     INDEXESSTART = 398,
     INDEXESEND = 399,
     VALUESSTART = 400,
     VALUESEND = 401,
     NONZEROSSTART = 402,
     NONZEROSEND = 403,
     ELSTART = 404,
     ELEND = 405,
     ENUMERATIONSTART = 406,
     ENUMERATIONEND = 407,
     ITEMEMPTY = 408,
     ITEMSTART = 409,
     ITEMEND = 410,
     ITEMSTARTANDEND = 411,
     BASE64START = 412,
     BASE64END = 413,
     NUMBEROFELATT = 414,
     NUMBEROFENUMERATIONSATT = 415,
     NUMBEROFITEMSATT = 416,
     EMPTYCATEGORYATT = 417,
     CATEGORYATT = 418,
     EMPTYDESCRIPTIONATT = 419,
     DESCRIPTIONATT = 420,
     EMPTYSOLVERATT = 421,
     SOLVERATT = 422,
     EMPTYNAMEATT = 423,
     NAMEATT = 424,
     EMPTYTYPEATT = 425,
     TYPEATT = 426,
     EMPTYENUMTYPEATT = 427,
     ENUMTYPEATT = 428,
     EMPTYSHAPEATT = 429,
     SHAPEATT = 430,
     EMPTYUNITATT = 431,
     UNITATT = 432,
     EMPTYVALUEATT = 433,
     VALUEATT = 434,
     EMPTYVALUETYPEATT = 435,
     VALUETYPEATT = 436,
     EMPTYCONTYPEATT = 437,
     CONTYPEATT = 438,
     EMPTYOBJTYPEATT = 439,
     OBJTYPEATT = 440,
     EMPTYVARTYPEATT = 441,
     VARTYPEATT = 442,
     EMPTYMATRIXCONTYPEATT = 443,
     MATRIXCONTYPEATT = 444,
     EMPTYMATRIXOBJTYPEATT = 445,
     MATRIXOBJTYPEATT = 446,
     EMPTYMATRIXVARTYPEATT = 447,
     MATRIXVARTYPEATT = 448,
     EMPTYMATRIXTYPEATT = 449,
     MATRIXTYPEATT = 450,
     EMPTYSYMMETRYATT = 451,
     SYMMETRYATT = 452,
     EMPTYROWMAJORATT = 453,
     ROWMAJORATT = 454,
     EMPTYBASETRANSPOSEATT = 455,
     BASETRANSPOSEATT = 456,
     NUMBEROFBLOCKSATT = 457,
     NUMBEROFCOLUMNSATT = 458,
     NUMBEROFROWSATT = 459,
     NUMBEROFMATRICESATT = 460,
     NUMBEROFVALUESATT = 461,
     NUMBEROFCONSTRAINTSATT = 462,
     NUMBEROFCONATT = 463,
     NUMBEROFCONIDXATT = 464,
     NUMBEROFOBJECTIVESATT = 465,
     NUMBEROFOBJATT = 466,
     NUMBEROFOBJIDXATT = 467,
     NUMBEROFVARIABLESATT = 468,
     NUMBEROFVARATT = 469,
     NUMBEROFVARIDXATT = 470,
     NUMBEROFMATRIXCONATT = 471,
     NUMBEROFMATRIXOBJATT = 472,
     NUMBEROFMATRIXVARATT = 473,
     BASEMATRIXIDXATT = 474,
     TARGETMATRIXFIRSTROWATT = 475,
     TARGETMATRIXFIRSTCOLATT = 476,
     BASEMATRIXSTARTROWATT = 477,
     BASEMATRIXSTARTCOLATT = 478,
     BASEMATRIXENDROWATT = 479,
     BASEMATRIXENDCOLATT = 480,
     SCALARMULTIPLIERATT = 481,
     BLOCKROWIDXATT = 482,
     BLOCKCOLIDXATT = 483,
     REATT = 484,
     IMATT = 485,
     MATRIXVARIDXATT = 486,
     MATRIXOBJIDXATT = 487,
     MATRIXCONIDXATT = 488,
     IDXATT = 489,
     INCRATT = 490,
     MULTATT = 491,
     SIZEOFATT = 492,
     COEFATT = 493,
     CONSTANTATT = 494,
     MATRICESSTART = 495,
     MATRICESEND = 496,
     MATRIXSTART = 497,
     MATRIXEND = 498,
     BASEMATRIXEND = 499,
     BASEMATRIXSTART = 500,
     BLOCKSSTART = 501,
     BLOCKSEND = 502,
     BLOCKSTART = 503,
     BLOCKEND = 504,
     COLOFFSETSTART = 505,
     COLOFFSETEND = 506,
     ROWOFFSETSTART = 507,
     ROWOFFSETEND = 508,
     ELEMENTSSTART = 509,
     ELEMENTSEND = 510,
     CONSTANTELEMENTSSTART = 511,
     CONSTANTELEMENTSEND = 512,
     COMPLEXELEMENTSSTART = 513,
     COMPLEXELEMENTSEND = 514,
     VARREFERENCEELEMENTSSTART = 515,
     VARREFERENCEELEMENTSEND = 516,
     LINEARELEMENTSSTART = 517,
     LINEARELEMENTSEND = 518,
     CONREFERENCEELEMENTSSTART = 519,
     CONREFERENCEELEMENTSEND = 520,
     OBJREFERENCEELEMENTSSTART = 521,
     OBJREFERENCEELEMENTSEND = 522,
     REALVALUEDEXPRESSIONSSTART = 523,
     REALVALUEDEXPRESSIONSSEND = 524,
     COMPLEXVALUEDEXPRESSIONSSTART = 525,
     COMPLEXVALUEDEXPRESSIONSSEND = 526,
     STRINGVALUEDELEMENTSSTART = 527,
     STRINGVALUEDELEMENTSEND = 528,
     STARTVECTORSTART = 529,
     STARTVECTOREND = 530,
     INDEXSTART = 531,
     INDEXEND = 532,
     VALUESTART = 533,
     VALUEEND = 534,
     VARIDXSTART = 535,
     VARIDXEND = 536,
     TRANSFORMATIONSTART = 537,
     TRANSFORMATIONEND = 538,
     MATRIXPROGRAMMINGSTART = 539,
     MATRIXPROGRAMMINGEND = 540,
     MATRIXVARIABLESSTART = 541,
     MATRIXVARIABLESEND = 542,
     MATRIXVARSTART = 543,
     MATRIXVAREND = 544,
     MATRIXOBJECTIVESSTART = 545,
     MATRIXOBJECTIVESEND = 546,
     MATRIXOBJSTART = 547,
     MATRIXOBJEND = 548,
     MATRIXCONSTRAINTSSTART = 549,
     MATRIXCONSTRAINTSEND = 550,
     MATRIXCONSTART = 551,
     MATRIXCONEND = 552,
     CONSTART = 553,
     CONEND = 554,
     CONSTRAINTSSTART = 555,
     CONSTRAINTSEND = 556,
     OBJSTART = 557,
     OBJEND = 558,
     OBJECTIVESSTART = 559,
     OBJECTIVESEND = 560,
     VARSTART = 561,
     VAREND = 562,
     VARIABLESSTART = 563,
     VARIABLESEND = 564,
     GENERALSTART = 565,
     GENERALEND = 566,
     SYSTEMSTART = 567,
     SYSTEMEND = 568,
     SERVICESTART = 569,
     SERVICEEND = 570,
     JOBSTART = 571,
     JOBEND = 572,
     OPTIMIZATIONSTART = 573,
     OPTIMIZATIONEND = 574,
     ATEQUALITYSTART = 575,
     ATEQUALITYEND = 576,
     ATLOWERSTART = 577,
     ATLOWEREND = 578,
     ATUPPERSTART = 579,
     ATUPPEREND = 580,
     BASICSTART = 581,
     BASICEND = 582,
     ISFREESTART = 583,
     ISFREEEND = 584,
     SUPERBASICSTART = 585,
     SUPERBASICEND = 586,
     UNKNOWNSTART = 587,
     UNKNOWNEND = 588,
     SERVICEURISTART = 589,
     SERVICEURIEND = 590,
     SERVICENAMESTART = 591,
     SERVICENAMEEND = 592,
     INSTANCENAMESTART = 593,
     INSTANCENAMEEND = 594,
     JOBIDSTART = 595,
     JOBIDEND = 596,
     OTHERSTART = 597,
     OTHEREND = 598,
     DUMMY = 599,
     NONLINEAREXPRESSIONSSTART = 600,
     NONLINEAREXPRESSIONSEND = 601,
     NUMBEROFNONLINEAREXPRESSIONS = 602,
     NLSTART = 603,
     NLEND = 604,
     MATRIXEXPRESSIONSSTART = 605,
     MATRIXEXPRESSIONSEND = 606,
     NUMBEROFEXPR = 607,
     EXPRSTART = 608,
     EXPREND = 609,
     NUMBEROFMATRIXTERMSATT = 610,
     MATRIXTERMSTART = 611,
     MATRIXTERMEND = 612,
     POWERSTART = 613,
     POWEREND = 614,
     PLUSSTART = 615,
     PLUSEND = 616,
     MINUSSTART = 617,
     MINUSEND = 618,
     DIVIDESTART = 619,
     DIVIDEEND = 620,
     LNSTART = 621,
     LNEND = 622,
     SQRTSTART = 623,
     SQRTEND = 624,
     SUMSTART = 625,
     SUMEND = 626,
     PRODUCTSTART = 627,
     PRODUCTEND = 628,
     EXPSTART = 629,
     EXPEND = 630,
     NEGATESTART = 631,
     NEGATEEND = 632,
     IFSTART = 633,
     IFEND = 634,
     SQUARESTART = 635,
     SQUAREEND = 636,
     COSSTART = 637,
     COSEND = 638,
     SINSTART = 639,
     SINEND = 640,
     VARIABLESTART = 641,
     VARIABLEEND = 642,
     ABSSTART = 643,
     ABSEND = 644,
     ERFSTART = 645,
     ERFEND = 646,
     MAXSTART = 647,
     MAXEND = 648,
     ALLDIFFSTART = 649,
     ALLDIFFEND = 650,
     MINSTART = 651,
     MINEND = 652,
     ESTART = 653,
     EEND = 654,
     PISTART = 655,
     PIEND = 656,
     TIMESSTART = 657,
     TIMESEND = 658,
     NUMBERSTART = 659,
     NUMBEREND = 660,
     MATRIXDETERMINANTSTART = 661,
     MATRIXDETERMINANTEND = 662,
     MATRIXTRACESTART = 663,
     MATRIXTRACEEND = 664,
     MATRIXTOSCALARSTART = 665,
     MATRIXTOSCALAREND = 666,
     MATRIXDIAGONALSTART = 667,
     MATRIXDIAGONALEND = 668,
     MATRIXDOTTIMESSTART = 669,
     MATRIXDOTTIMESEND = 670,
     MATRIXLOWERTRIANGLESTART = 671,
     MATRIXLOWERTRIANGLEEND = 672,
     MATRIXUPPERTRIANGLESTART = 673,
     MATRIXUPPERTRIANGLEEND = 674,
     MATRIXMERGESTART = 675,
     MATRIXMERGEEND = 676,
     MATRIXMINUSSTART = 677,
     MATRIXMINUSEND = 678,
     MATRIXNEGATESTART = 679,
     MATRIXNEGATEEND = 680,
     MATRIXPLUSSTART = 681,
     MATRIXPLUSEND = 682,
     MATRIXTIMESSTART = 683,
     MATRIXTIMESEND = 684,
     MATRIXPRODUCTSTART = 685,
     MATRIXPRODUCTEND = 686,
     MATRIXSCALARTIMESSTART = 687,
     MATRIXSCALARTIMESEND = 688,
     MATRIXSUBMATRIXATSTART = 689,
     MATRIXSUBMATRIXATEND = 690,
     MATRIXTRANSPOSESTART = 691,
     MATRIXTRANSPOSEEND = 692,
     MATRIXREFERENCESTART = 693,
     MATRIXREFERENCEEND = 694,
     IDENTITYMATRIXSTART = 695,
     IDENTITYMATRIXEND = 696,
     MATRIXINVERSESTART = 697,
     MATRIXINVERSEEND = 698,
     COMPLEXCONJUGATESTART = 699,
     COMPLEXCONJUGATEEND = 700,
     COMPLEXMINUSSTART = 701,
     COMPLEXMINUSEND = 702,
     COMPLEXNEGATESTART = 703,
     COMPLEXNEGATEEND = 704,
     COMPLEXNUMBERSTART = 705,
     COMPLEXNUMBEREND = 706,
     COMPLEXPLUSSTART = 707,
     COMPLEXPLUSEND = 708,
     COMPLEXSQUARESTART = 709,
     COMPLEXSQUAREEND = 710,
     COMPLEXSUMSTART = 711,
     COMPLEXSUMEND = 712,
     COMPLEXTIMESSTART = 713,
     COMPLEXTIMESEND = 714,
     CREATECOMPLEXSTART = 715,
     CREATECOMPLEXEND = 716,
     EMPTYINCLUDEDIAGONALATT = 717,
     INCLUDEDIAGONALATT = 718,
     EMPTYTRANSPOSEATT = 719,
     TRANSPOSEATT = 720,
     EMPTYIDATT = 721,
     IDATT = 722
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
#define BOOLEAN 265
#define GREATERTHAN 266
#define ENDOFELEMENT 267
#define OSRLSTART 268
#define OSRLSTARTEMPTY 269
#define OSRLATTRIBUTETEXT 270
#define OSRLEND 271
#define WEIGHTEDOBJECTIVESATT 272
#define EMPTYWEIGHTEDOBJECTIVESATT 273
#define TARGETOBJECTIVENAMEATT 274
#define EMPTYTARGETOBJECTIVENAMEATT 275
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 276
#define NUMBEROFOTHEROBJECTIVERESULTSATT 277
#define NUMBEROFOTHERRESULTSATT 278
#define NUMBEROFOTHERSOLUTIONRESULTSATT 279
#define NUMBEROFOTHERVARIABLERESULTSATT 280
#define NUMBEROFSOLUTIONSATT 281
#define NUMBEROFOTHERMATRIXOBJECTIVERESULTSATT 282
#define NUMBEROFOTHERMATRIXCONSTRAINTRESULTSATT 283
#define NUMBEROFOTHERMATRIXPROGRAMMINGRESULTSATT 284
#define NUMBEROFOTHERMATRIXVARIABLERESULTSATT 285
#define NUMBEROFSOLVEROUTPUTSATT 286
#define NUMBEROFSUBSTATUSESATT 287
#define NUMBEROFTIMESATT 288
#define TARGETOBJECTIVEIDXATT 289
#define ACTUALSTARTTIMESTART 290
#define ACTUALSTARTTIMEEND 291
#define AVAILABLECPUNUMBERSTART 292
#define AVAILABLECPUNUMBEREND 293
#define AVAILABLECPUSPEEDSTART 294
#define AVAILABLECPUSPEEDEND 295
#define AVAILABLEDISKSPACESTART 296
#define AVAILABLEDISKSPACEEND 297
#define AVAILABLEMEMORYSTART 298
#define AVAILABLEMEMORYEND 299
#define BASISSTATUSSTART 300
#define BASISSTATUSEND 301
#define CURRENTJOBCOUNTSTART 302
#define CURRENTJOBCOUNTEND 303
#define CURRENTSTATESTART 304
#define CURRENTSTATEEND 305
#define DUALVALUESSTART 306
#define DUALVALUESEND 307
#define ENDTIMESTART 308
#define ENDTIMEEND 309
#define IDXSTART 310
#define IDXEND 311
#define GENERALSTATUSSTART 312
#define GENERALSTATUSEND 313
#define GENERALSUBSTATUSSTART 314
#define GENERALSUBSTATUSEND 315
#define MESSAGESTART 316
#define MESSAGEEND 317
#define OPTIMIZATIONSOLUTIONSTATUSSTART 318
#define OPTIMIZATIONSOLUTIONSTATUSEND 319
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 320
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 321
#define OTHERRESULTSSTART 322
#define OTHERRESULTSEND 323
#define OTHERSOLUTIONRESULTSTART 324
#define OTHERSOLUTIONRESULTEND 325
#define OTHERSOLUTIONRESULTSSTART 326
#define OTHERSOLUTIONRESULTSEND 327
#define OTHERSOLVEROUTPUTSTART 328
#define OTHERSOLVEROUTPUTEND 329
#define SCHEDULEDSTARTTIMESTART 330
#define SCHEDULEDSTARTTIMEEND 331
#define SERVICEUTILIZATIONSTART 332
#define SERVICEUTILIZATIONEND 333
#define SOLUTIONSTART 334
#define SOLUTIONEND 335
#define SOLVERINVOKEDSTART 336
#define SOLVERINVOKEDEND 337
#define SOLVEROUTPUTSTART 338
#define SOLVEROUTPUTEND 339
#define STATUSSTART 340
#define STATUSEND 341
#define SUBMITTIMESTART 342
#define SUBMITTIMEEND 343
#define SUBSTATUSSTART 344
#define SUBSTATUSEND 345
#define SYSTEMINFORMATIONSTART 346
#define SYSTEMINFORMATIONEND 347
#define TIMESTART 348
#define TIMEEND 349
#define TIMESERVICESTARTEDSTART 350
#define TIMESERVICESTARTEDEND 351
#define TIMESTAMPSTART 352
#define TIMESTAMPEND 353
#define TIMINGINFORMATIONSTART 354
#define TIMINGINFORMATIONEND 355
#define TOTALJOBSSOFARSTART 356
#define TOTALJOBSSOFAREND 357
#define USEDCPUNUMBERSTART 358
#define USEDCPUNUMBEREND 359
#define USEDCPUSPEEDSTART 360
#define USEDCPUSPEEDEND 361
#define USEDDISKSPACESTART 362
#define USEDDISKSPACEEND 363
#define USEDMEMORYSTART 364
#define USEDMEMORYEND 365
#define VALUESSTRINGSTART 366
#define VALUESSTRINGEND 367
#define OTHERMATRIXVARIABLERESULTSTART 368
#define OTHERMATRIXVARIABLERESULTEND 369
#define OTHERMATRIXOBJECTIVERESULTSTART 370
#define OTHERMATRIXOBJECTIVERESULTEND 371
#define OTHERMATRIXCONSTRAINTRESULTSTART 372
#define OTHERMATRIXCONSTRAINTRESULTEND 373
#define OTHERMATRIXPROGRAMMINGRESULTSTART 374
#define OTHERMATRIXPROGRAMMINGRESULTEND 375
#define HEADERSTART 376
#define HEADEREND 377
#define FILENAMESTART 378
#define FILENAMEEND 379
#define FILENAMEEMPTY 380
#define FILENAMESTARTANDEND 381
#define FILESOURCESTART 382
#define FILESOURCEEND 383
#define FILESOURCEEMPTY 384
#define FILESOURCESTARTANDEND 385
#define FILEDESCRIPTIONSTART 386
#define FILEDESCRIPTIONEND 387
#define FILEDESCRIPTIONEMPTY 388
#define FILEDESCRIPTIONSTARTANDEND 389
#define FILECREATORSTART 390
#define FILECREATOREND 391
#define FILECREATOREMPTY 392
#define FILECREATORSTARTANDEND 393
#define FILELICENCESTART 394
#define FILELICENCEEND 395
#define FILELICENCEEMPTY 396
#define FILELICENCESTARTANDEND 397
#define INDEXESSTART 398
#define INDEXESEND 399
#define VALUESSTART 400
#define VALUESEND 401
#define NONZEROSSTART 402
#define NONZEROSEND 403
#define ELSTART 404
#define ELEND 405
#define ENUMERATIONSTART 406
#define ENUMERATIONEND 407
#define ITEMEMPTY 408
#define ITEMSTART 409
#define ITEMEND 410
#define ITEMSTARTANDEND 411
#define BASE64START 412
#define BASE64END 413
#define NUMBEROFELATT 414
#define NUMBEROFENUMERATIONSATT 415
#define NUMBEROFITEMSATT 416
#define EMPTYCATEGORYATT 417
#define CATEGORYATT 418
#define EMPTYDESCRIPTIONATT 419
#define DESCRIPTIONATT 420
#define EMPTYSOLVERATT 421
#define SOLVERATT 422
#define EMPTYNAMEATT 423
#define NAMEATT 424
#define EMPTYTYPEATT 425
#define TYPEATT 426
#define EMPTYENUMTYPEATT 427
#define ENUMTYPEATT 428
#define EMPTYSHAPEATT 429
#define SHAPEATT 430
#define EMPTYUNITATT 431
#define UNITATT 432
#define EMPTYVALUEATT 433
#define VALUEATT 434
#define EMPTYVALUETYPEATT 435
#define VALUETYPEATT 436
#define EMPTYCONTYPEATT 437
#define CONTYPEATT 438
#define EMPTYOBJTYPEATT 439
#define OBJTYPEATT 440
#define EMPTYVARTYPEATT 441
#define VARTYPEATT 442
#define EMPTYMATRIXCONTYPEATT 443
#define MATRIXCONTYPEATT 444
#define EMPTYMATRIXOBJTYPEATT 445
#define MATRIXOBJTYPEATT 446
#define EMPTYMATRIXVARTYPEATT 447
#define MATRIXVARTYPEATT 448
#define EMPTYMATRIXTYPEATT 449
#define MATRIXTYPEATT 450
#define EMPTYSYMMETRYATT 451
#define SYMMETRYATT 452
#define EMPTYROWMAJORATT 453
#define ROWMAJORATT 454
#define EMPTYBASETRANSPOSEATT 455
#define BASETRANSPOSEATT 456
#define NUMBEROFBLOCKSATT 457
#define NUMBEROFCOLUMNSATT 458
#define NUMBEROFROWSATT 459
#define NUMBEROFMATRICESATT 460
#define NUMBEROFVALUESATT 461
#define NUMBEROFCONSTRAINTSATT 462
#define NUMBEROFCONATT 463
#define NUMBEROFCONIDXATT 464
#define NUMBEROFOBJECTIVESATT 465
#define NUMBEROFOBJATT 466
#define NUMBEROFOBJIDXATT 467
#define NUMBEROFVARIABLESATT 468
#define NUMBEROFVARATT 469
#define NUMBEROFVARIDXATT 470
#define NUMBEROFMATRIXCONATT 471
#define NUMBEROFMATRIXOBJATT 472
#define NUMBEROFMATRIXVARATT 473
#define BASEMATRIXIDXATT 474
#define TARGETMATRIXFIRSTROWATT 475
#define TARGETMATRIXFIRSTCOLATT 476
#define BASEMATRIXSTARTROWATT 477
#define BASEMATRIXSTARTCOLATT 478
#define BASEMATRIXENDROWATT 479
#define BASEMATRIXENDCOLATT 480
#define SCALARMULTIPLIERATT 481
#define BLOCKROWIDXATT 482
#define BLOCKCOLIDXATT 483
#define REATT 484
#define IMATT 485
#define MATRIXVARIDXATT 486
#define MATRIXOBJIDXATT 487
#define MATRIXCONIDXATT 488
#define IDXATT 489
#define INCRATT 490
#define MULTATT 491
#define SIZEOFATT 492
#define COEFATT 493
#define CONSTANTATT 494
#define MATRICESSTART 495
#define MATRICESEND 496
#define MATRIXSTART 497
#define MATRIXEND 498
#define BASEMATRIXEND 499
#define BASEMATRIXSTART 500
#define BLOCKSSTART 501
#define BLOCKSEND 502
#define BLOCKSTART 503
#define BLOCKEND 504
#define COLOFFSETSTART 505
#define COLOFFSETEND 506
#define ROWOFFSETSTART 507
#define ROWOFFSETEND 508
#define ELEMENTSSTART 509
#define ELEMENTSEND 510
#define CONSTANTELEMENTSSTART 511
#define CONSTANTELEMENTSEND 512
#define COMPLEXELEMENTSSTART 513
#define COMPLEXELEMENTSEND 514
#define VARREFERENCEELEMENTSSTART 515
#define VARREFERENCEELEMENTSEND 516
#define LINEARELEMENTSSTART 517
#define LINEARELEMENTSEND 518
#define CONREFERENCEELEMENTSSTART 519
#define CONREFERENCEELEMENTSEND 520
#define OBJREFERENCEELEMENTSSTART 521
#define OBJREFERENCEELEMENTSEND 522
#define REALVALUEDEXPRESSIONSSTART 523
#define REALVALUEDEXPRESSIONSSEND 524
#define COMPLEXVALUEDEXPRESSIONSSTART 525
#define COMPLEXVALUEDEXPRESSIONSSEND 526
#define STRINGVALUEDELEMENTSSTART 527
#define STRINGVALUEDELEMENTSEND 528
#define STARTVECTORSTART 529
#define STARTVECTOREND 530
#define INDEXSTART 531
#define INDEXEND 532
#define VALUESTART 533
#define VALUEEND 534
#define VARIDXSTART 535
#define VARIDXEND 536
#define TRANSFORMATIONSTART 537
#define TRANSFORMATIONEND 538
#define MATRIXPROGRAMMINGSTART 539
#define MATRIXPROGRAMMINGEND 540
#define MATRIXVARIABLESSTART 541
#define MATRIXVARIABLESEND 542
#define MATRIXVARSTART 543
#define MATRIXVAREND 544
#define MATRIXOBJECTIVESSTART 545
#define MATRIXOBJECTIVESEND 546
#define MATRIXOBJSTART 547
#define MATRIXOBJEND 548
#define MATRIXCONSTRAINTSSTART 549
#define MATRIXCONSTRAINTSEND 550
#define MATRIXCONSTART 551
#define MATRIXCONEND 552
#define CONSTART 553
#define CONEND 554
#define CONSTRAINTSSTART 555
#define CONSTRAINTSEND 556
#define OBJSTART 557
#define OBJEND 558
#define OBJECTIVESSTART 559
#define OBJECTIVESEND 560
#define VARSTART 561
#define VAREND 562
#define VARIABLESSTART 563
#define VARIABLESEND 564
#define GENERALSTART 565
#define GENERALEND 566
#define SYSTEMSTART 567
#define SYSTEMEND 568
#define SERVICESTART 569
#define SERVICEEND 570
#define JOBSTART 571
#define JOBEND 572
#define OPTIMIZATIONSTART 573
#define OPTIMIZATIONEND 574
#define ATEQUALITYSTART 575
#define ATEQUALITYEND 576
#define ATLOWERSTART 577
#define ATLOWEREND 578
#define ATUPPERSTART 579
#define ATUPPEREND 580
#define BASICSTART 581
#define BASICEND 582
#define ISFREESTART 583
#define ISFREEEND 584
#define SUPERBASICSTART 585
#define SUPERBASICEND 586
#define UNKNOWNSTART 587
#define UNKNOWNEND 588
#define SERVICEURISTART 589
#define SERVICEURIEND 590
#define SERVICENAMESTART 591
#define SERVICENAMEEND 592
#define INSTANCENAMESTART 593
#define INSTANCENAMEEND 594
#define JOBIDSTART 595
#define JOBIDEND 596
#define OTHERSTART 597
#define OTHEREND 598
#define DUMMY 599
#define NONLINEAREXPRESSIONSSTART 600
#define NONLINEAREXPRESSIONSEND 601
#define NUMBEROFNONLINEAREXPRESSIONS 602
#define NLSTART 603
#define NLEND 604
#define MATRIXEXPRESSIONSSTART 605
#define MATRIXEXPRESSIONSEND 606
#define NUMBEROFEXPR 607
#define EXPRSTART 608
#define EXPREND 609
#define NUMBEROFMATRIXTERMSATT 610
#define MATRIXTERMSTART 611
#define MATRIXTERMEND 612
#define POWERSTART 613
#define POWEREND 614
#define PLUSSTART 615
#define PLUSEND 616
#define MINUSSTART 617
#define MINUSEND 618
#define DIVIDESTART 619
#define DIVIDEEND 620
#define LNSTART 621
#define LNEND 622
#define SQRTSTART 623
#define SQRTEND 624
#define SUMSTART 625
#define SUMEND 626
#define PRODUCTSTART 627
#define PRODUCTEND 628
#define EXPSTART 629
#define EXPEND 630
#define NEGATESTART 631
#define NEGATEEND 632
#define IFSTART 633
#define IFEND 634
#define SQUARESTART 635
#define SQUAREEND 636
#define COSSTART 637
#define COSEND 638
#define SINSTART 639
#define SINEND 640
#define VARIABLESTART 641
#define VARIABLEEND 642
#define ABSSTART 643
#define ABSEND 644
#define ERFSTART 645
#define ERFEND 646
#define MAXSTART 647
#define MAXEND 648
#define ALLDIFFSTART 649
#define ALLDIFFEND 650
#define MINSTART 651
#define MINEND 652
#define ESTART 653
#define EEND 654
#define PISTART 655
#define PIEND 656
#define TIMESSTART 657
#define TIMESEND 658
#define NUMBERSTART 659
#define NUMBEREND 660
#define MATRIXDETERMINANTSTART 661
#define MATRIXDETERMINANTEND 662
#define MATRIXTRACESTART 663
#define MATRIXTRACEEND 664
#define MATRIXTOSCALARSTART 665
#define MATRIXTOSCALAREND 666
#define MATRIXDIAGONALSTART 667
#define MATRIXDIAGONALEND 668
#define MATRIXDOTTIMESSTART 669
#define MATRIXDOTTIMESEND 670
#define MATRIXLOWERTRIANGLESTART 671
#define MATRIXLOWERTRIANGLEEND 672
#define MATRIXUPPERTRIANGLESTART 673
#define MATRIXUPPERTRIANGLEEND 674
#define MATRIXMERGESTART 675
#define MATRIXMERGEEND 676
#define MATRIXMINUSSTART 677
#define MATRIXMINUSEND 678
#define MATRIXNEGATESTART 679
#define MATRIXNEGATEEND 680
#define MATRIXPLUSSTART 681
#define MATRIXPLUSEND 682
#define MATRIXTIMESSTART 683
#define MATRIXTIMESEND 684
#define MATRIXPRODUCTSTART 685
#define MATRIXPRODUCTEND 686
#define MATRIXSCALARTIMESSTART 687
#define MATRIXSCALARTIMESEND 688
#define MATRIXSUBMATRIXATSTART 689
#define MATRIXSUBMATRIXATEND 690
#define MATRIXTRANSPOSESTART 691
#define MATRIXTRANSPOSEEND 692
#define MATRIXREFERENCESTART 693
#define MATRIXREFERENCEEND 694
#define IDENTITYMATRIXSTART 695
#define IDENTITYMATRIXEND 696
#define MATRIXINVERSESTART 697
#define MATRIXINVERSEEND 698
#define COMPLEXCONJUGATESTART 699
#define COMPLEXCONJUGATEEND 700
#define COMPLEXMINUSSTART 701
#define COMPLEXMINUSEND 702
#define COMPLEXNEGATESTART 703
#define COMPLEXNEGATEEND 704
#define COMPLEXNUMBERSTART 705
#define COMPLEXNUMBEREND 706
#define COMPLEXPLUSSTART 707
#define COMPLEXPLUSEND 708
#define COMPLEXSQUARESTART 709
#define COMPLEXSQUAREEND 710
#define COMPLEXSUMSTART 711
#define COMPLEXSUMEND 712
#define COMPLEXTIMESSTART 713
#define COMPLEXTIMESEND 714
#define CREATECOMPLEXSTART 715
#define CREATECOMPLEXEND 716
#define EMPTYINCLUDEDIAGONALATT 717
#define INCLUDEDIAGONALATT 718
#define EMPTYTRANSPOSEATT 719
#define TRANSPOSEATT 720
#define EMPTYIDATT 721
#define IDATT 722




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
#define YYLAST   2169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  472
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  1212
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1805
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2544

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   722

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   469,
     471,     2,     2,   470,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   468,     2,     2,     2,     2,     2,     2,     2,
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
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467
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
    2874,  2876,  2880,  2882,  2883,  2886,  2888,  2890,  2892,  2894,
    2898,  2900,  2903,  2905,  2907,  2909,  2911,  2915,  2917,  2922,
    2924,  2926,  2927,  2930,  2932,  2934,  2938,  2941,  2942,  2945,
    2947,  2949,  2951,  2953,  2957,  2959,  2964,  2966,  2968,  2969,
    2972,  2974,  2976,  2980,  2983,  2984,  2987,  2989,  2991,  2993,
    2995,  2999,  3001,  3002,  3005,  3009,  3011,  3013,  3014,  3017,
    3019,  3021,  3023,  3025,  3027,  3031,  3032,  3035,  3039,  3041,
    3042,  3044,  3048,  3053,  3055,  3057,  3058,  3061,  3063,  3065,
    3069,  3072,  3073,  3076,  3078,  3080,  3082,  3084,  3088,  3089,
    3092,  3095,  3097,  3099,  3101,  3103,  3107,  3112,  3114,  3116,
    3117,  3120,  3122,  3124,  3128,  3131,  3132,  3135,  3137,  3139,
    3141,  3143,  3147,  3148,  3151,  3154,  3156,  3158,  3160,  3162,
    3166,  3171,  3173,  3175,  3176,  3179,  3181,  3183,  3187,  3190,
    3191,  3194,  3196,  3198,  3200,  3202,  3206,  3208,  3213,  3215,
    3217,  3218,  3221,  3223,  3225,  3229,  3232,  3233,  3236,  3238,
    3240,  3242,  3244,  3248,  3249,  3252,  3256,  3258,  3259,  3262,
    3264,  3266,  3268,  3272,  3277,  3279,  3281,  3282,  3285,  3287,
    3289,  3293,  3296,  3297,  3300,  3302,  3304,  3306,  3308,  3312,
    3313,  3316,  3320,  3322,  3323,  3326,  3328,  3330,  3332,  3335,
    3337,  3342,  3344,  3346,  3347,  3350,  3352,  3354,  3358,  3361,
    3362,  3365,  3367,  3369,  3371,  3373,  3377,  3379,  3385,  3387,
    3388,  3390,  3392,  3396,  3398,  3400,  3406,  3408,  3412,  3414,
    3416,  3418,  3420,  3422,  3426,  3428,  3432,  3434,  3436,  3438,
    3440,  3442,  3446,  3448,  3449,  3452,  3456,  3458,  3460,  3461,
    3464,  3466,  3468,  3470,  3472,  3474,  3476,  3478,  3482,  3487,
    3492,  3497,  3502,  3507,  3512,  3517,  3522,  3527,  3532,  3537,
    3542,  3547,  3552,  3557,  3562,  3567,  3572,  3577,  3582,  3587,
    3592,  3597,  3602,  3607,  3612,  3617,  3622,  3627,  3632,  3637,
    3642,  3647,  3652,  3654,  3656,  3658,  3662,  3664,  3666,  3668,
    3672,  3674,  3676,  3678,  3682,  3684,  3686,  3688,  3692,  3694,
    3696,  3698,  3702,  3704,  3706,  3708,  3712,  3714,  3716,  3718,
    3722,  3724,  3726,  3728,  3732,  3734,  3736,  3738,  3742,  3744,
    3746,  3748,  3752,  3754,  3756,  3758,  3762,  3764,  3766,  3768,
    3772,  3774,  3776,  3778,  3782,  3784,  3786,  3788,  3792,  3794,
    3796,  3798,  3802,  3804,  3806,  3808,  3812,  3814,  3816,  3818,
    3822,  3824,  3826,  3828,  3830,  3832,  3834,  3836,  3838,  3840,
    3842,  3844,  3846,  3848,  3850,  3852,  3854,  3856,  3858,  3860,
    3862,  3864,  3866,  3868,  3870,  3872,  3874,  3876,  3877,  3881,
    3883,  3886,  3887,  3891,  3893,  3896,  3897,  3903,  3904,  3910,
    3911,  3917,  3918,  3923,  3924,  3930,  3931,  3937,  3938,  3943,
    3944,  3949,  3950,  3955,  3956,  3961,  3962,  3967,  3968,  3973,
    3977,  3979,  3981,  3982,  3987,  3988,  3995,  3996,  4001,  4002,
    4007,  4008,  4013,  4017,  4019,  4021,  4024,  4025,  4028,  4030,
    4032,  4034,  4035,  4040,  4041,  4046,  4048,  4051,  4052,  4057,
    4058,  4061,  4063,  4065,  4070,  4075,  4076,  4081,  4082,  4085,
    4086,  4091,  4092,  4095,  4096,  4101,  4102,  4105,  4106,  4111,
    4112,  4115,  4116,  4121,  4122,  4125,  4127,  4129,  4131,  4133,
    4135,  4137,  4139,  4141,  4143,  4145,  4147,  4149,  4151,  4153,
    4155,  4157,  4159,  4161,  4163,  4167,  4169,  4170,  4173,  4175,
    4177,  4179,  4182,  4187,  4191,  4195,  4197,  4199,  4202,  4207,
    4211,  4213,  4215,  4218,  4223,  4227,  4229,  4231,  4234,  4239,
    4242,  4244,  4247,  4250,  4252,  4256,  4259,  4261,  4264,  4267,
    4269,  4272,  4277,  4279,  4280,  4282,  4285,  4290,  4292,  4293,
    4295,  4298,  4302,  4305,  4307,  4309,  4312,  4315,  4317,  4321,
    4324,  4326,  4329,  4332,  4334,  4338,  4341,  4343,  4347,  4348,
    4353,  4354,  4357,  4360,  4362,  4366,  4369,  4371,  4378,  4381,
    4383,  4386,  4388,  4390,  4392,  4394,  4396,  4398,  4400,  4402,
    4404,  4406,  4408,  4412,  4414,  4416,  4419,  4421,  4422,  4425,
    4427,  4429,  4433,  4435,  4439,  4443,  4445,  4449,  4450,  4456,
    4457,  4460,  4464,  4466,  4470,  4474,  4476,  4479,  4483,  4485,
    4488,  4492,  4494,  4498,  4502,  4504
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     473,     0,    -1,   474,   482,   480,    -1,   475,   476,   477,
      -1,    14,    -1,    13,    -1,    -1,    15,    -1,   478,    -1,
     479,    -1,    12,    -1,    11,   482,   480,    -1,   481,    -1,
      16,    -1,    -1,   483,   484,   564,   618,   670,   765,    -1,
      -1,  1114,    -1,    -1,   485,   486,    -1,   310,    -1,   487,
      -1,   488,    -1,    11,   311,    -1,    12,    -1,    11,   489,
     311,    -1,   490,    -1,   491,    -1,   490,   491,    -1,   492,
      -1,   508,    -1,   514,    -1,   520,    -1,   526,    -1,   532,
      -1,   538,    -1,   544,    -1,   550,    -1,   493,   494,   497,
      -1,    57,    -1,   495,    -1,   496,    -1,   495,   496,    -1,
    1495,    -1,  1468,    -1,  1107,    -1,   498,    -1,   499,    -1,
      11,    58,    -1,    12,    -1,    11,   500,    58,    -1,   501,
      -1,   502,    -1,   501,   502,    -1,   503,   504,   507,    -1,
      89,    -1,   505,    -1,    -1,   505,   506,    -1,  1477,    -1,
    1468,    -1,    11,    90,    -1,    12,    -1,   509,   510,    -1,
      61,    -1,   511,    -1,   512,    -1,    11,    62,    -1,    12,
      -1,    11,   513,    62,    -1,     4,    -1,   515,   516,    -1,
     334,    -1,   517,    -1,   518,    -1,    11,   335,    -1,    12,
      -1,    11,   519,   335,    -1,     4,    -1,   521,   522,    -1,
     336,    -1,   523,    -1,   524,    -1,    11,   337,    -1,    12,
      -1,    11,   525,   337,    -1,     4,    -1,   527,   528,    -1,
     338,    -1,   529,    -1,   530,    -1,    11,   339,    -1,    12,
      -1,    11,   531,   339,    -1,     4,    -1,   533,   534,    -1,
     340,    -1,   535,    -1,   536,    -1,    11,   341,    -1,    12,
      -1,    11,   537,   341,    -1,     4,    -1,   539,   540,    -1,
      81,    -1,   541,    -1,   542,    -1,    11,    82,    -1,    12,
      -1,    11,   543,    82,    -1,     4,    -1,   545,   546,    -1,
      97,    -1,   547,    -1,   548,    -1,    11,    98,    -1,    12,
      -1,    11,   549,    98,    -1,     4,    -1,   551,   552,   553,
      -1,    67,    -1,  1102,    -1,   554,    -1,   555,    -1,    11,
      68,    -1,    12,    -1,    11,   556,    68,    -1,   557,    -1,
     558,    -1,   557,   558,    -1,   559,   560,   563,    -1,   342,
      -1,   561,    -1,    -1,   561,   562,    -1,  1477,    -1,  1501,
      -1,  1468,    -1,    11,   343,    -1,    12,    -1,    -1,   565,
     566,    -1,   312,    -1,   567,    -1,   568,    -1,    11,   313,
      -1,    12,    -1,    11,   569,   313,    -1,   570,    -1,   571,
      -1,   570,   571,    -1,   572,    -1,   578,    -1,   585,    -1,
     592,    -1,   599,    -1,   604,    -1,   573,   574,    -1,    91,
      -1,   575,    -1,   576,    -1,    11,    92,    -1,    12,    -1,
      11,   577,    92,    -1,     4,    -1,   579,   580,   583,    -1,
      41,    -1,   581,    -1,    -1,   581,   582,    -1,  1498,    -1,
    1468,    -1,    11,   584,    42,    -1,  1109,    -1,   586,   587,
     590,    -1,    43,    -1,   588,    -1,    -1,   588,   589,    -1,
    1498,    -1,  1468,    -1,    11,   591,    44,    -1,  1109,    -1,
     593,   594,   597,    -1,    39,    -1,   595,    -1,    -1,   595,
     596,    -1,  1498,    -1,  1468,    -1,    11,   598,    40,    -1,
    1109,    -1,   600,   601,   602,    -1,    37,    -1,    -1,  1468,
      -1,    11,   603,    38,    -1,     6,    -1,   605,   606,   607,
      -1,    67,    -1,  1102,    -1,   608,    -1,   609,    -1,    11,
      68,    -1,    12,    -1,    11,   610,    68,    -1,   611,    -1,
     612,    -1,   611,   612,    -1,   613,   614,   617,    -1,   342,
      -1,   615,    -1,    -1,   615,   616,    -1,  1477,    -1,  1501,
      -1,  1468,    -1,    11,   343,    -1,    12,    -1,    -1,   619,
     620,    -1,   314,    -1,   621,    -1,   622,    -1,    11,   315,
      -1,    12,    -1,    11,   623,   315,    -1,   624,    -1,   625,
      -1,   624,   625,    -1,   626,    -1,   632,    -1,   638,    -1,
     644,    -1,   650,    -1,   656,    -1,   627,   628,    -1,    49,
      -1,   629,    -1,   630,    -1,    11,    50,    -1,    12,    -1,
      11,   631,    50,    -1,     4,    -1,   633,   634,    -1,    47,
      -1,   635,    -1,   636,    -1,    11,    48,    -1,    12,    -1,
      11,   637,    48,    -1,     6,    -1,   639,   640,    -1,   101,
      -1,   641,    -1,   642,    -1,    11,   102,    -1,    12,    -1,
      11,   643,   102,    -1,     6,    -1,   645,   646,    -1,    95,
      -1,   647,    -1,   648,    -1,    11,    96,    -1,    12,    -1,
      11,   649,    96,    -1,     4,    -1,   651,   652,    -1,    77,
      -1,   653,    -1,   654,    -1,    11,    78,    -1,    12,    -1,
      11,   655,    78,    -1,  1109,    -1,   657,   658,   659,    -1,
      67,    -1,  1102,    -1,   660,    -1,   661,    -1,    11,    68,
      -1,    12,    -1,    11,   662,    68,    -1,   663,    -1,   664,
      -1,   663,   664,    -1,   665,   666,   669,    -1,   342,    -1,
     667,    -1,    -1,   667,   668,    -1,  1477,    -1,  1501,    -1,
    1468,    -1,    11,   343,    -1,    12,    -1,    -1,   671,   672,
      -1,   316,    -1,   673,    -1,   674,    -1,    11,   317,    -1,
      12,    -1,    11,   675,   317,    -1,   676,    -1,   677,    -1,
     676,   677,    -1,   678,    -1,   684,    -1,   690,    -1,   696,
      -1,   702,    -1,   708,    -1,   725,    -1,   732,    -1,   739,
      -1,   746,    -1,   751,    -1,   679,   680,    -1,    85,    -1,
     681,    -1,   682,    -1,    11,    86,    -1,    12,    -1,    11,
     683,    86,    -1,     4,    -1,   685,   686,    -1,    87,    -1,
     687,    -1,   688,    -1,    11,    88,    -1,    12,    -1,    11,
     689,    88,    -1,     4,    -1,   691,   692,    -1,    75,    -1,
     693,    -1,   694,    -1,    11,    76,    -1,    12,    -1,    11,
     695,    76,    -1,     4,    -1,   697,   698,    -1,    35,    -1,
     699,    -1,   700,    -1,    11,    36,    -1,    12,    -1,    11,
     701,    36,    -1,     4,    -1,   703,   704,    -1,    53,    -1,
     705,    -1,   706,    -1,    11,    54,    -1,    12,    -1,    11,
     707,    54,    -1,     4,    -1,   709,   710,   711,    -1,    99,
      -1,  1108,    -1,   712,    -1,   713,    -1,    11,   100,    -1,
      12,    -1,    11,   714,   100,    -1,   715,    -1,   716,    -1,
     715,   716,    -1,   717,   718,   720,    -1,    93,    -1,    -1,
     718,   719,    -1,  1498,    -1,  1495,    -1,  1462,    -1,  1468,
      -1,   721,    -1,   722,    -1,    11,    94,    -1,    12,    -1,
      11,   723,    94,    -1,   724,    -1,     7,    -1,     6,    -1,
     726,   727,   730,    -1,   107,    -1,   728,    -1,    -1,   728,
     729,    -1,  1498,    -1,  1468,    -1,    11,   731,   108,    -1,
    1109,    -1,   733,   734,   737,    -1,   109,    -1,   735,    -1,
      -1,   735,   736,    -1,  1498,    -1,  1468,    -1,    11,   738,
     110,    -1,  1109,    -1,   740,   741,   744,    -1,   105,    -1,
     742,    -1,    -1,   742,   743,    -1,  1498,    -1,  1468,    -1,
      11,   745,   106,    -1,  1109,    -1,   747,   748,   749,    -1,
     103,    -1,    -1,  1468,    -1,    11,   750,   104,    -1,     6,
      -1,   752,   753,   754,    -1,    67,    -1,  1102,    -1,   755,
      -1,   756,    -1,    11,    68,    -1,    12,    -1,    11,   757,
      68,    -1,   758,    -1,   759,    -1,   758,   759,    -1,   760,
     761,   764,    -1,   342,    -1,   762,    -1,    -1,   762,   763,
      -1,  1477,    -1,  1501,    -1,  1468,    -1,    11,   343,    -1,
      12,    -1,    -1,   766,   767,   770,    -1,   318,    -1,   768,
      -1,    -1,   768,   769,    -1,  1105,    -1,  1439,    -1,  1428,
      -1,  1434,    -1,   771,    -1,   772,    -1,    11,   319,    -1,
      12,    -1,    11,   773,   319,    -1,   774,  1075,    -1,   775,
      -1,   774,   775,    -1,   776,   777,   783,    -1,    79,    -1,
     778,    -1,    -1,   778,   779,    -1,   780,    -1,   781,    -1,
     782,    -1,    34,  1111,     6,  1111,    -1,    19,     3,  1111,
      -1,    17,     3,  1111,    -1,    11,   784,   800,   806,   884,
     946,  1008,  1052,    80,    -1,   785,   786,   789,    -1,    85,
      -1,   787,    -1,   788,    -1,   787,   788,    -1,  1495,    -1,
    1468,    -1,  1107,    -1,   790,    -1,   791,    -1,    11,    86,
      -1,    12,    -1,    11,   792,    86,    -1,   793,    -1,   794,
      -1,   793,   794,    -1,   795,   796,   799,    -1,    89,    -1,
     797,    -1,    -1,   797,   798,    -1,  1495,    -1,  1468,    -1,
      11,    90,    -1,    12,    -1,    -1,   801,   802,    -1,    61,
      -1,   803,    -1,   804,    -1,    11,    62,    -1,    12,    -1,
      11,   805,    62,    -1,     4,    -1,    -1,   807,   808,   809,
      -1,   308,    -1,    -1,  1104,    -1,   810,    -1,   811,    -1,
      12,    -1,    11,   812,   309,    -1,   813,   826,   842,   855,
      -1,    -1,   814,   815,   816,    -1,   145,    -1,  1437,    -1,
     817,    -1,   818,    -1,    11,   146,    -1,    12,    -1,    11,
     819,   146,    -1,   820,    -1,   821,    -1,   820,   821,    -1,
     822,   823,   825,    -1,   306,    -1,    -1,   823,   824,    -1,
    1448,    -1,  1477,    -1,    11,  1109,   307,    -1,    -1,   827,
     828,   829,    -1,   111,    -1,  1437,    -1,   830,    -1,   831,
      -1,    11,   112,    -1,    12,    -1,    11,   832,   112,    -1,
     833,    -1,   834,    -1,   833,   834,    -1,   835,   836,   838,
      -1,   306,    -1,    -1,   836,   837,    -1,  1448,    -1,  1477,
      -1,   839,    -1,   840,    -1,    11,   307,    -1,    12,    -1,
      11,   841,   307,    -1,     4,    -1,    -1,   843,   844,    -1,
      45,    -1,   845,    -1,   846,    -1,    12,    -1,    11,   847,
      46,    -1,   848,   849,   850,   851,   852,   853,   854,    -1,
      -1,  1170,    -1,    -1,  1176,    -1,    -1,  1182,    -1,    -1,
    1188,    -1,    -1,  1194,    -1,    -1,  1200,    -1,    -1,  1206,
      -1,    -1,   855,   856,    -1,   857,   858,   861,    -1,   342,
      -1,   859,    -1,    -1,   859,   860,    -1,  1437,    -1,  1430,
      -1,  1501,    -1,  1489,    -1,  1477,    -1,  1495,    -1,  1507,
      -1,  1471,    -1,  1468,    -1,   862,    -1,   863,    -1,    11,
     343,    -1,    12,    -1,    11,   864,   343,    -1,   865,    -1,
     874,    -1,   866,    -1,   865,   866,    -1,   867,   868,   870,
      -1,   306,    -1,    -1,   868,   869,    -1,  1448,    -1,  1477,
      -1,   871,    -1,   872,    -1,    11,   307,    -1,    12,    -1,
      11,   873,   307,    -1,  1110,    -1,   875,    -1,   874,   875,
      -1,   876,   877,   880,    -1,   151,    -1,   878,    -1,    -1,
     878,   879,    -1,  1429,    -1,  1501,    -1,  1468,    -1,   881,
      -1,   882,    -1,    12,    -1,    11,   883,   152,    -1,  1142,
      -1,    -1,   885,   886,   887,    -1,   304,    -1,    -1,  1101,
      -1,   888,    -1,   889,    -1,    12,    -1,    11,   890,   305,
      -1,   891,   904,   917,    -1,    -1,   892,   893,   894,    -1,
     145,    -1,  1433,    -1,   895,    -1,   896,    -1,    11,   146,
      -1,    12,    -1,    11,   897,   146,    -1,   898,    -1,   899,
      -1,   898,   899,    -1,   900,   901,   903,    -1,   302,    -1,
      -1,   901,   902,    -1,  1448,    -1,  1477,    -1,    11,  1109,
     303,    -1,    -1,   905,   906,    -1,    45,    -1,   907,    -1,
     908,    -1,    12,    -1,    11,   909,    46,    -1,   910,   911,
     912,   913,   914,   915,   916,    -1,    -1,  1170,    -1,    -1,
    1176,    -1,    -1,  1182,    -1,    -1,  1188,    -1,    -1,  1194,
      -1,    -1,  1200,    -1,    -1,  1206,    -1,    -1,   917,   918,
      -1,   919,   920,   923,    -1,   342,    -1,   921,    -1,    -1,
     921,   922,    -1,  1433,    -1,  1430,    -1,  1501,    -1,  1489,
      -1,  1477,    -1,  1495,    -1,  1480,    -1,  1471,    -1,  1468,
      -1,   924,    -1,   925,    -1,    11,   343,    -1,    12,    -1,
      11,   926,   343,    -1,   927,    -1,   936,    -1,   928,    -1,
     927,   928,    -1,   929,   930,   932,    -1,   302,    -1,    -1,
     930,   931,    -1,  1448,    -1,  1477,    -1,   933,    -1,   934,
      -1,    11,   303,    -1,    12,    -1,    11,   935,   303,    -1,
    1110,    -1,   937,    -1,   936,   937,    -1,   938,   939,   942,
      -1,   151,    -1,   940,    -1,    -1,   940,   941,    -1,  1429,
      -1,  1501,    -1,  1468,    -1,   943,    -1,   944,    -1,    12,
      -1,    11,   945,   152,    -1,  1142,    -1,    -1,   947,   948,
     949,    -1,   300,    -1,    -1,  1098,    -1,   950,    -1,   951,
      -1,    12,    -1,    11,   952,   301,    -1,   953,   966,   979,
      -1,    -1,   954,   955,   956,    -1,    51,    -1,  1427,    -1,
     957,    -1,   958,    -1,    11,    52,    -1,    12,    -1,    11,
     959,    52,    -1,   960,    -1,   961,    -1,   960,   961,    -1,
     962,   963,   965,    -1,   298,    -1,    -1,   963,   964,    -1,
    1448,    -1,  1477,    -1,    11,  1109,   299,    -1,    -1,   967,
     968,    -1,    45,    -1,   969,    -1,   970,    -1,    12,    -1,
      11,   971,    46,    -1,   972,   973,   974,   975,   976,   977,
     978,    -1,    -1,  1170,    -1,    -1,  1176,    -1,    -1,  1182,
      -1,    -1,  1188,    -1,    -1,  1194,    -1,    -1,  1200,    -1,
      -1,  1206,    -1,    -1,   979,   980,    -1,   981,   982,   985,
      -1,   342,    -1,   983,    -1,    -1,   983,   984,    -1,  1427,
      -1,  1430,    -1,  1501,    -1,  1489,    -1,  1477,    -1,  1495,
      -1,  1465,    -1,  1471,    -1,  1468,    -1,   986,    -1,   987,
      -1,    11,   343,    -1,    12,    -1,    11,   988,   343,    -1,
     989,    -1,   998,    -1,   990,    -1,   989,   990,    -1,   991,
     992,   994,    -1,   298,    -1,    -1,   992,   993,    -1,  1448,
      -1,  1477,    -1,   995,    -1,   996,    -1,    11,   299,    -1,
      12,    -1,    11,   997,   299,    -1,  1110,    -1,   999,    -1,
     998,   999,    -1,  1000,  1001,  1004,    -1,   151,    -1,  1002,
      -1,    -1,  1002,  1003,    -1,  1429,    -1,  1501,    -1,  1468,
      -1,  1005,    -1,  1006,    -1,    12,    -1,    11,  1007,   152,
      -1,  1142,    -1,    -1,  1009,  1010,  1011,    -1,   284,    -1,
      -1,  1099,    -1,  1012,    -1,  1013,    -1,    12,    -1,    11,
    1014,  1050,   285,    -1,    -1,  1015,  1016,  1017,    -1,   286,
      -1,  1100,    -1,  1018,    -1,  1019,    -1,    12,    -1,    11,
    1021,  1029,  1020,    -1,   287,    -1,    -1,  1022,  1023,  1024,
      -1,   145,    -1,  1432,    -1,  1025,    -1,  1026,    -1,    12,
      -1,    11,  1028,  1027,    -1,   146,    -1,    -1,  1028,  1213,
      -1,    -1,  1029,  1030,    -1,  1031,  1032,  1035,    -1,   342,
      -1,  1033,    -1,    -1,  1033,  1034,    -1,  1432,    -1,  1430,
      -1,  1501,    -1,  1489,    -1,  1477,    -1,  1495,    -1,  1474,
      -1,  1471,    -1,  1468,    -1,  1036,    -1,  1037,    -1,    11,
     343,    -1,    12,    -1,    11,  1038,   343,    -1,  1040,    -1,
    1039,    -1,  1213,    -1,  1039,  1213,    -1,  1041,    -1,  1040,
    1041,    -1,  1042,  1043,  1046,    -1,   151,    -1,  1044,    -1,
      -1,  1044,  1045,    -1,  1429,    -1,  1501,    -1,  1468,    -1,
    1047,    -1,  1048,    -1,    12,    -1,    11,  1049,   152,    -1,
    1142,    -1,    -1,  1050,  1051,    -1,   119,    -1,    -1,  1053,
    1054,  1055,    -1,    71,    -1,  1103,    -1,  1056,    -1,  1057,
      -1,    11,    72,    -1,    12,    -1,    11,  1058,    72,    -1,
    1059,    -1,  1060,    -1,  1059,  1060,    -1,  1061,  1062,  1065,
      -1,    69,    -1,  1063,    -1,    -1,  1063,  1064,    -1,  1477,
      -1,  1501,    -1,  1462,    -1,  1468,    -1,  1431,    -1,  1066,
      -1,  1067,    -1,    11,    70,    -1,    12,    -1,    11,  1068,
      70,    -1,  1069,    -1,  1070,    -1,  1069,  1070,    -1,  1071,
      -1,  1072,    -1,  1073,    -1,   156,    -1,   153,    -1,   154,
    1074,   155,    -1,     5,    -1,    -1,  1076,  1077,  1078,    -1,
      73,    -1,  1106,    -1,  1079,    -1,  1080,    -1,    11,    74,
      -1,    12,    -1,    11,  1081,    74,    -1,  1082,    -1,  1083,
      -1,  1082,  1083,    -1,  1084,  1085,  1088,    -1,    83,    -1,
    1086,    -1,    -1,  1086,  1087,    -1,  1477,    -1,  1462,    -1,
    1468,    -1,  1431,    -1,  1089,    -1,  1090,    -1,    11,    84,
      -1,    12,    -1,    11,  1091,    84,    -1,  1092,    -1,  1093,
      -1,  1092,  1093,    -1,  1094,    -1,  1095,    -1,  1096,    -1,
     156,    -1,   153,    -1,   154,  1097,   155,    -1,     5,    -1,
      21,  1111,     6,  1111,    -1,    29,  1111,     6,  1111,    -1,
      30,  1111,     6,  1111,    -1,    22,  1111,     6,  1111,    -1,
      23,  1111,     6,  1111,    -1,    24,  1111,     6,  1111,    -1,
      25,  1111,     6,  1111,    -1,    26,  1111,     6,  1111,    -1,
      31,  1111,     6,  1111,    -1,    32,  1111,     6,  1111,    -1,
      33,  1111,     6,  1111,    -1,     6,    -1,     7,    -1,     4,
      -1,     6,    -1,     7,    -1,  1112,     8,    -1,    -1,  1112,
    1113,    -1,   468,    -1,   469,    -1,   470,    -1,   471,    -1,
    1115,  1116,    -1,   121,    -1,  1117,    -1,  1118,    -1,    12,
      -1,    11,  1119,   122,    -1,  1120,    -1,    -1,  1120,  1121,
      -1,  1122,    -1,  1126,    -1,  1130,    -1,  1134,    -1,  1138,
      -1,  1123,    -1,  1124,    -1,  1125,    -1,   126,    -1,   125,
      -1,   123,     5,   124,    -1,  1127,    -1,  1128,    -1,  1129,
      -1,   130,    -1,   129,    -1,   127,     5,   128,    -1,  1131,
      -1,  1132,    -1,  1133,    -1,   134,    -1,   133,    -1,   131,
       5,   132,    -1,  1135,    -1,  1136,    -1,  1137,    -1,   138,
      -1,   137,    -1,   135,     5,   136,    -1,  1139,    -1,  1140,
      -1,  1141,    -1,   142,    -1,   141,    -1,   139,     5,   140,
      -1,  1143,    -1,  1150,    -1,    -1,  1143,  1144,    -1,  1145,
    1146,  1149,    -1,   149,    -1,  1147,    -1,    -1,  1147,  1148,
      -1,  1451,    -1,  1449,    -1,    11,     6,   150,    -1,   157,
    1440,  1151,    -1,  1152,    -1,  1153,    -1,    11,   158,    -1,
      12,    -1,    11,     4,   158,    -1,  1155,    -1,  1160,    -1,
      -1,  1155,  1156,    -1,  1157,  1158,  1159,    -1,   149,    -1,
      -1,  1451,    -1,    11,  1109,   150,    -1,   157,  1440,  1161,
      -1,  1162,    -1,  1163,    -1,    11,   158,    -1,    12,    -1,
      11,     4,   158,    -1,  1165,    -1,    -1,  1165,  1166,    -1,
    1167,  1168,  1169,    -1,   149,    -1,    -1,  1451,    -1,    11,
       4,   150,    -1,  1171,  1212,  1172,    -1,   326,    -1,  1173,
      -1,  1174,    -1,    12,    -1,    11,  1175,   327,    -1,  1142,
      -1,  1177,  1212,  1178,    -1,   322,    -1,  1179,    -1,  1180,
      -1,    12,    -1,    11,  1181,   323,    -1,  1142,    -1,  1183,
    1212,  1184,    -1,   324,    -1,  1185,    -1,  1186,    -1,    12,
      -1,    11,  1187,   325,    -1,  1142,    -1,  1189,  1212,  1190,
      -1,   320,    -1,  1191,    -1,  1192,    -1,    12,    -1,    11,
    1193,   321,    -1,  1142,    -1,  1195,  1212,  1196,    -1,   328,
      -1,  1197,    -1,  1198,    -1,    12,    -1,    11,  1199,   329,
      -1,  1142,    -1,  1201,  1212,  1202,    -1,   330,    -1,  1203,
      -1,  1204,    -1,    12,    -1,    11,  1205,   331,    -1,  1142,
      -1,  1207,  1212,  1208,    -1,   332,    -1,  1209,    -1,  1210,
      -1,    12,    -1,    11,  1211,   333,    -1,  1142,    -1,  1429,
      -1,  1214,  1215,  1218,    -1,   288,    -1,  1216,    -1,    -1,
    1216,  1217,    -1,  1492,    -1,  1435,    -1,  1426,    -1,  1477,
      -1,  1495,    -1,  1450,    -1,  1219,    -1,  1220,    -1,    12,
      -1,    11,  1221,   289,    -1,  1222,  1228,    -1,    -1,  1223,
    1224,  1227,    -1,   245,    -1,  1225,    -1,    -1,  1225,  1226,
      -1,  1441,    -1,  1452,    -1,  1453,    -1,  1442,    -1,  1443,
      -1,  1444,    -1,  1445,    -1,  1459,    -1,  1458,    -1,    11,
     244,    -1,    12,    -1,    -1,  1228,  1229,    -1,  1230,    -1,
    1362,    -1,  1380,    -1,  1255,    -1,  1331,    -1,  1344,    -1,
    1268,    -1,  1295,    -1,  1313,    -1,  1393,    -1,  1397,    -1,
    1231,  1232,    11,  1235,    -1,   256,    -1,  1233,    -1,    -1,
    1233,  1234,    -1,  1436,    -1,  1483,    -1,  1237,  1236,   257,
      -1,    -1,  1243,  1249,    -1,  1238,  1239,    -1,   274,    -1,
    1240,    -1,  1241,    -1,    12,    -1,    11,  1242,   275,    -1,
    1142,    -1,    -1,  1244,  1245,    -1,   276,    -1,  1246,    -1,
    1247,    -1,    12,    -1,    11,  1248,   277,    -1,  1142,    -1,
    1250,  1251,    -1,   278,    -1,  1252,    -1,  1253,    -1,    12,
      -1,    11,  1254,   279,    -1,  1154,    -1,  1256,  1257,    11,
    1260,    -1,   260,    -1,  1258,    -1,    -1,  1258,  1259,    -1,
    1436,    -1,  1483,    -1,  1237,  1261,   261,    -1,  1243,  1262,
      -1,    -1,  1263,  1264,    -1,   278,    -1,  1265,    -1,  1266,
      -1,    12,    -1,    11,  1267,   279,    -1,  1142,    -1,  1269,
    1270,    11,  1273,    -1,   262,    -1,  1271,    -1,    -1,  1271,
    1272,    -1,  1436,    -1,  1483,    -1,  1237,  1274,   263,    -1,
    1243,  1275,    -1,    -1,  1276,  1277,    -1,   278,    -1,  1278,
      -1,  1279,    -1,    12,    -1,    11,  1280,   279,    -1,  1281,
      -1,    -1,  1281,  1282,    -1,  1283,  1284,  1287,    -1,   149,
      -1,  1285,    -1,    -1,  1285,  1286,    -1,  1438,    -1,  1455,
      -1,  1288,    -1,  1289,    -1,    12,    -1,    11,  1290,   150,
      -1,    -1,  1290,  1291,    -1,  1292,  1293,  1294,    -1,   280,
      -1,    -1,  1454,    -1,    11,     6,   281,    -1,  1296,  1297,
      11,  1300,    -1,   268,    -1,  1298,    -1,    -1,  1298,  1299,
      -1,  1436,    -1,  1483,    -1,  1237,  1301,   269,    -1,  1243,
    1302,    -1,    -1,  1303,  1304,    -1,   278,    -1,  1305,    -1,
    1306,    -1,    12,    -1,    11,  1307,   279,    -1,    -1,  1307,
    1308,    -1,  1309,  1310,    -1,   149,    -1,  1311,    -1,  1312,
      -1,    12,    -1,    11,  1510,   150,    -1,  1314,  1315,    11,
    1318,    -1,   270,    -1,  1316,    -1,    -1,  1316,  1317,    -1,
    1436,    -1,  1483,    -1,  1237,  1319,   271,    -1,  1243,  1320,
      -1,    -1,  1321,  1322,    -1,   278,    -1,  1323,    -1,  1324,
      -1,    12,    -1,    11,  1325,   279,    -1,    -1,  1325,  1326,
      -1,  1327,  1328,    -1,   149,    -1,  1329,    -1,  1330,    -1,
      12,    -1,    11,  1653,   150,    -1,  1332,  1333,    11,  1336,
      -1,   266,    -1,  1334,    -1,    -1,  1334,  1335,    -1,  1436,
      -1,  1483,    -1,  1237,  1337,   267,    -1,  1243,  1338,    -1,
      -1,  1339,  1340,    -1,   278,    -1,  1341,    -1,  1342,    -1,
      12,    -1,    11,  1343,   279,    -1,  1142,    -1,  1345,  1346,
      11,  1349,    -1,   264,    -1,  1347,    -1,    -1,  1347,  1348,
      -1,  1436,    -1,  1483,    -1,  1237,  1350,   265,    -1,  1243,
    1351,    -1,    -1,  1352,  1353,    -1,   278,    -1,  1354,    -1,
    1355,    -1,    12,    -1,    11,  1356,   279,    -1,    -1,  1356,
    1357,    -1,  1358,  1359,  1361,    -1,   149,    -1,    -1,  1359,
    1360,    -1,  1504,    -1,  1451,    -1,  1449,    -1,    11,     6,
     150,    -1,  1363,  1364,    11,  1367,    -1,   258,    -1,  1365,
      -1,    -1,  1365,  1366,    -1,  1436,    -1,  1483,    -1,  1237,
    1368,   259,    -1,  1243,  1369,    -1,    -1,  1370,  1371,    -1,
     278,    -1,  1372,    -1,  1373,    -1,    12,    -1,    11,  1374,
     279,    -1,    -1,  1374,  1375,    -1,  1376,  1377,  1379,    -1,
     149,    -1,    -1,  1377,  1378,    -1,  1457,    -1,  1456,    -1,
    1451,    -1,    11,   150,    -1,    12,    -1,  1381,  1382,    11,
    1385,    -1,   272,    -1,  1383,    -1,    -1,  1383,  1384,    -1,
    1436,    -1,  1483,    -1,  1237,  1386,   273,    -1,  1243,  1387,
      -1,    -1,  1388,  1389,    -1,   278,    -1,  1390,    -1,  1391,
      -1,    12,    -1,    11,  1392,   279,    -1,  1164,    -1,  1394,
    1395,    11,  1584,  1396,    -1,   282,    -1,    -1,  1486,    -1,
     283,    -1,  1398,  1399,  1400,    -1,   246,    -1,  1425,    -1,
      11,  1402,  1409,  1416,  1401,    -1,   247,    -1,  1403,  1404,
    1405,    -1,   250,    -1,  1429,    -1,  1406,    -1,  1407,    -1,
      12,    -1,    11,  1408,   251,    -1,  1142,    -1,  1410,  1411,
    1412,    -1,   252,    -1,  1429,    -1,  1413,    -1,  1414,    -1,
      12,    -1,    11,  1415,   253,    -1,  1142,    -1,    -1,  1416,
    1417,    -1,  1418,  1419,  1422,    -1,   248,    -1,  1420,    -1,
      -1,  1420,  1421,    -1,  1446,    -1,  1447,    -1,  1492,    -1,
    1495,    -1,  1423,    -1,  1424,    -1,    12,    -1,    11,  1221,
     249,    -1,   202,     8,     6,     8,    -1,   203,     8,     6,
       8,    -1,   208,     8,     6,     8,    -1,   207,     8,     6,
       8,    -1,   159,     8,     6,     8,    -1,   160,     8,     6,
       8,    -1,   161,     8,     6,     8,    -1,   218,     8,     6,
       8,    -1,   211,     8,     6,     8,    -1,   210,     8,     6,
       8,    -1,   204,     8,     6,     8,    -1,   206,     8,     6,
       8,    -1,   214,     8,     6,     8,    -1,   215,     8,     6,
       8,    -1,   213,     8,     6,     8,    -1,   237,     8,     6,
       8,    -1,   219,     8,     6,     8,    -1,   222,     8,     6,
       8,    -1,   223,     8,     6,     8,    -1,   224,     8,     6,
       8,    -1,   225,     8,     6,     8,    -1,   227,     8,     6,
       8,    -1,   228,     8,     6,     8,    -1,   234,     8,     6,
       8,    -1,   235,     8,     6,     8,    -1,   231,  1111,     6,
    1111,    -1,   236,     8,     6,     8,    -1,   220,     8,     6,
       8,    -1,   221,     8,     6,     8,    -1,   238,     8,  1109,
       8,    -1,   239,     8,  1109,     8,    -1,   230,     8,  1109,
       8,    -1,   229,     8,  1109,     8,    -1,   226,     8,  1109,
       8,    -1,  1460,    -1,  1461,    -1,   200,    -1,   201,     3,
    1111,    -1,  1463,    -1,  1464,    -1,   162,    -1,   163,     3,
       8,    -1,  1466,    -1,  1467,    -1,   182,    -1,   183,     3,
       8,    -1,  1469,    -1,  1470,    -1,   164,    -1,   165,     3,
       8,    -1,  1472,    -1,  1473,    -1,   172,    -1,   173,     3,
       8,    -1,  1475,    -1,  1476,    -1,   192,    -1,   193,     3,
       8,    -1,  1478,    -1,  1479,    -1,   168,    -1,   169,     3,
       8,    -1,  1481,    -1,  1482,    -1,   184,    -1,   185,     3,
       8,    -1,  1484,    -1,  1485,    -1,   198,    -1,   199,     3,
       8,    -1,  1487,    -1,  1488,    -1,   174,    -1,   175,     3,
       8,    -1,  1490,    -1,  1491,    -1,   166,    -1,   167,     3,
       8,    -1,  1493,    -1,  1494,    -1,   196,    -1,   197,     3,
       8,    -1,  1496,    -1,  1497,    -1,   170,    -1,   171,     3,
       8,    -1,  1499,    -1,  1500,    -1,   176,    -1,   177,     3,
       8,    -1,  1502,    -1,  1503,    -1,   178,    -1,   179,     3,
       8,    -1,  1505,    -1,  1506,    -1,   180,    -1,   181,     3,
       8,    -1,  1508,    -1,  1509,    -1,   186,    -1,   187,     3,
       8,    -1,  1554,    -1,  1561,    -1,  1517,    -1,  1519,    -1,
    1569,    -1,  1521,    -1,  1523,    -1,  1525,    -1,  1527,    -1,
    1581,    -1,  1529,    -1,  1531,    -1,  1533,    -1,  1537,    -1,
    1535,    -1,  1539,    -1,  1546,    -1,  1541,    -1,  1544,    -1,
    1575,    -1,  1578,    -1,  1511,    -1,  1514,    -1,  1572,    -1,
    1548,    -1,  1550,    -1,  1552,    -1,    -1,   398,  1512,  1513,
      -1,    12,    -1,    11,   399,    -1,    -1,   400,  1515,  1516,
      -1,    12,    -1,    11,   401,    -1,    -1,   402,  1518,  1510,
    1510,   403,    -1,    -1,   360,  1520,  1510,  1510,   361,    -1,
      -1,   362,  1522,  1510,  1510,   363,    -1,    -1,   376,  1524,
    1510,   377,    -1,    -1,   364,  1526,  1510,  1510,   365,    -1,
      -1,   358,  1528,  1510,  1510,   359,    -1,    -1,   366,  1530,
    1510,   367,    -1,    -1,   368,  1532,  1510,   369,    -1,    -1,
     380,  1534,  1510,   381,    -1,    -1,   382,  1536,  1510,   383,
      -1,    -1,   384,  1538,  1510,   385,    -1,    -1,   374,  1540,
    1510,   375,    -1,  1542,  1510,  1543,    -1,   388,    -1,   389,
      -1,    -1,   390,  1545,  1510,   391,    -1,    -1,   378,  1547,
    1510,  1510,  1510,   379,    -1,    -1,   406,  1549,  1584,   407,
      -1,    -1,   408,  1551,  1584,   409,    -1,    -1,   410,  1553,
    1584,   411,    -1,  1555,  1557,  1556,    -1,   404,    -1,    12,
      -1,    11,   405,    -1,    -1,  1557,  1558,    -1,  1495,    -1,
    1501,    -1,  1559,    -1,    -1,   467,     3,  1560,     8,    -1,
      -1,   386,  1562,  1565,  1563,    -1,    12,    -1,    11,   387,
      -1,    -1,    11,  1510,  1564,   387,    -1,    -1,  1565,  1566,
      -1,  1567,    -1,  1568,    -1,   238,     8,  1109,     8,    -1,
     234,     8,     6,     8,    -1,    -1,   370,  1570,  1571,   371,
      -1,    -1,  1571,  1510,    -1,    -1,   394,  1573,  1574,   395,
      -1,    -1,  1574,  1510,    -1,    -1,   392,  1576,  1577,   393,
      -1,    -1,  1577,  1510,    -1,    -1,   396,  1579,  1580,   397,
      -1,    -1,  1580,  1510,    -1,    -1,   372,  1582,  1583,   373,
      -1,    -1,  1583,  1510,    -1,  1585,    -1,  1592,    -1,  1596,
      -1,  1600,    -1,  1604,    -1,  1607,    -1,  1613,    -1,  1616,
      -1,  1620,    -1,  1625,    -1,  1628,    -1,  1631,    -1,  1634,
      -1,  1637,    -1,  1640,    -1,  1643,    -1,  1646,    -1,  1649,
      -1,  1610,    -1,  1586,  1587,  1589,    -1,   438,    -1,    -1,
    1587,  1588,    -1,  1590,    -1,  1591,    -1,    12,    -1,    11,
     439,    -1,   234,     8,     6,     8,    -1,   465,     3,     8,
      -1,  1593,  1595,  1594,    -1,   288,    -1,    12,    -1,    11,
     289,    -1,   234,     8,     6,     8,    -1,  1597,  1599,  1598,
      -1,   292,    -1,    12,    -1,    11,   293,    -1,   234,     8,
       6,     8,    -1,  1601,  1603,  1602,    -1,   296,    -1,    12,
      -1,    11,   297,    -1,   234,     8,     6,     8,    -1,  1605,
    1606,    -1,   412,    -1,  1584,   413,    -1,  1608,  1609,    -1,
     414,    -1,  1584,  1584,   415,    -1,  1611,  1612,    -1,   440,
      -1,  1510,   441,    -1,  1614,  1615,    -1,   442,    -1,  1584,
     443,    -1,  1617,  1618,    11,  1619,    -1,   416,    -1,    -1,
    1624,    -1,  1584,   417,    -1,  1621,  1622,    11,  1623,    -1,
     418,    -1,    -1,  1624,    -1,  1584,   419,    -1,   463,     3,
       8,    -1,  1626,  1627,    -1,   420,    -1,    12,    -1,    11,
     421,    -1,  1629,  1630,    -1,   422,    -1,  1584,  1584,   423,
      -1,  1632,  1633,    -1,   424,    -1,  1584,   425,    -1,  1635,
    1636,    -1,   426,    -1,  1584,  1584,   427,    -1,  1638,  1639,
      -1,   428,    -1,  1584,  1584,   429,    -1,    -1,   430,  1641,
    1642,   431,    -1,    -1,  1642,  1584,    -1,  1644,  1645,    -1,
     432,    -1,  1584,  1652,   433,    -1,  1647,  1648,    -1,   434,
      -1,  1510,  1510,  1510,  1510,  1584,   435,    -1,  1650,  1651,
      -1,   436,    -1,  1584,   437,    -1,  1510,    -1,  1653,    -1,
    1654,    -1,  1660,    -1,  1663,    -1,  1666,    -1,  1669,    -1,
    1672,    -1,  1675,    -1,  1678,    -1,  1681,    -1,  1655,  1657,
    1656,    -1,   450,    -1,    12,    -1,    11,   451,    -1,  1658,
      -1,    -1,  1658,  1659,    -1,  1457,    -1,  1456,    -1,  1661,
      11,  1662,    -1,   460,    -1,  1510,  1510,   461,    -1,  1664,
      11,  1665,    -1,   452,    -1,  1652,  1652,   453,    -1,    -1,
     456,    11,  1667,  1668,   457,    -1,    -1,  1668,  1652,    -1,
    1670,    11,  1671,    -1,   446,    -1,  1652,  1652,   447,    -1,
    1673,    11,  1674,    -1,   448,    -1,  1652,   449,    -1,  1676,
      11,  1677,    -1,   444,    -1,  1652,   445,    -1,  1679,    11,
    1680,    -1,   458,    -1,  1652,  1652,   459,    -1,  1682,    11,
    1683,    -1,   454,    -1,  1652,   455,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   355,   355,   356,   358,   365,   375,   375,   377,   377,
     379,   381,   383,   392,   393,   396,   405,   405,   418,   418,
     420,   434,   434,   436,   436,   438,   440,   442,   442,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   456,   458,
     473,   480,   480,   483,   488,   492,   501,   505,   510,   510,
     512,   514,   516,   516,   518,   523,   533,   539,   539,   542,
     547,   553,   553,   556,   558,   565,   565,   567,   567,   569,
     571,   574,   576,   583,   583,   585,   585,   587,   589,   594,
     596,   603,   603,   605,   605,   607,   609,   614,   616,   623,
     623,   625,   625,   627,   629,   634,   636,   643,   643,   645,
     645,   647,   649,   654,   656,   663,   663,   665,   665,   667,
     669,   674,   676,   683,   683,   685,   685,   687,   689,   694,
     696,   703,   713,   718,   724,   724,   726,   728,   730,   730,
     732,   737,   749,   755,   755,   758,   765,   770,   777,   777,
     781,   781,   783,   794,   794,   796,   796,   798,   800,   802,
     802,   805,   806,   807,   808,   809,   810,   813,   815,   822,
     822,   824,   824,   826,   828,   835,   837,   848,   850,   850,
     853,   859,   865,   867,   873,   875,   886,   888,   888,   891,
     897,   903,   905,   912,   914,   925,   927,   927,   930,   936,
     942,   944,   951,   953,   962,   963,   969,   971,   977,   979,
     986,   996,  1001,  1007,  1007,  1009,  1011,  1013,  1013,  1015,
    1020,  1032,  1038,  1038,  1041,  1048,  1053,  1059,  1059,  1063,
    1063,  1065,  1076,  1076,  1078,  1078,  1080,  1082,  1084,  1084,
    1087,  1088,  1089,  1090,  1091,  1092,  1095,  1097,  1104,  1104,
    1106,  1106,  1108,  1110,  1118,  1120,  1127,  1127,  1129,  1129,
    1131,  1133,  1138,  1140,  1147,  1147,  1149,  1149,  1151,  1153,
    1158,  1160,  1167,  1167,  1169,  1169,  1171,  1173,  1178,  1180,
    1187,  1187,  1189,  1189,  1191,  1193,  1200,  1202,  1209,  1219,
    1224,  1230,  1230,  1232,  1234,  1236,  1236,  1238,  1243,  1255,
    1261,  1261,  1264,  1271,  1276,  1283,  1283,  1286,  1286,  1288,
    1304,  1304,  1306,  1306,  1308,  1310,  1312,  1312,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1328,
    1330,  1337,  1337,  1339,  1339,  1341,  1343,  1351,  1353,  1360,
    1360,  1362,  1362,  1364,  1366,  1371,  1373,  1380,  1380,  1382,
    1382,  1384,  1386,  1391,  1393,  1400,  1400,  1402,  1402,  1404,
    1406,  1411,  1413,  1420,  1420,  1422,  1422,  1424,  1426,  1431,
    1433,  1440,  1450,  1455,  1461,  1461,  1463,  1465,  1467,  1467,
    1469,  1471,  1485,  1485,  1488,  1488,  1488,  1488,  1491,  1491,
    1493,  1493,  1495,  1497,  1506,  1507,  1510,  1512,  1523,  1525,
    1525,  1528,  1534,  1540,  1542,  1549,  1551,  1562,  1564,  1564,
    1567,  1573,  1579,  1581,  1588,  1590,  1601,  1603,  1603,  1606,
    1612,  1618,  1620,  1627,  1629,  1639,  1640,  1646,  1648,  1655,
    1657,  1664,  1674,  1679,  1685,  1685,  1687,  1689,  1691,  1691,
    1693,  1698,  1710,  1716,  1716,  1719,  1726,  1731,  1738,  1738,
    1741,  1741,  1743,  1751,  1757,  1757,  1760,  1767,  1772,  1777,
    1784,  1789,  1795,  1795,  1797,  1799,  1801,  1801,  1803,  1805,
    1814,  1816,  1816,  1818,  1818,  1818,  1820,  1830,  1840,  1860,
    1866,  1868,  1878,  1884,  1884,  1887,  1892,  1897,  1907,  1912,
    1918,  1918,  1920,  1922,  1924,  1924,  1926,  1931,  1941,  1947,
    1947,  1950,  1956,  1963,  1963,  1966,  1966,  1968,  1970,  1970,
    1972,  1972,  1974,  1976,  1984,  1984,  1986,  1992,  1992,  2000,
    2000,  2002,  2004,  2006,  2008,  2008,  2010,  2015,  2023,  2028,
    2034,  2034,  2036,  2038,  2040,  2040,  2042,  2052,  2061,  2061,
    2064,  2065,  2068,  2071,  2071,  2073,  2078,  2086,  2091,  2097,
    2097,  2099,  2101,  2103,  2103,  2105,  2115,  2124,  2124,  2127,
    2128,  2132,  2133,  2135,  2135,  2137,  2139,  2144,  2144,  2146,
    2151,  2151,  2153,  2155,  2157,  2159,  2159,  2168,  2168,  2177,
    2177,  2186,  2186,  2195,  2195,  2204,  2204,  2213,  2213,  2223,
    2223,  2225,  2230,  2254,  2260,  2260,  2263,  2272,  2280,  2286,
    2292,  2298,  2304,  2310,  2316,  2323,  2323,  2325,  2325,  2327,
    2329,  2329,  2331,  2331,  2333,  2340,  2349,  2349,  2352,  2358,
    2365,  2365,  2367,  2367,  2369,  2371,  2380,  2380,  2382,  2393,
    2403,  2409,  2409,  2412,  2417,  2418,  2422,  2422,  2424,  2426,
    2429,  2433,  2433,  2435,  2443,  2443,  2451,  2451,  2453,  2455,
    2457,  2459,  2459,  2461,  2466,  2474,  2479,  2485,  2485,  2487,
    2489,  2492,  2492,  2494,  2502,  2512,  2512,  2515,  2516,  2519,
    2522,  2522,  2524,  2529,  2529,  2532,  2534,  2536,  2538,  2538,
    2547,  2547,  2556,  2556,  2565,  2565,  2574,  2574,  2583,  2583,
    2592,  2592,  2602,  2602,  2604,  2610,  2634,  2641,  2641,  2644,
    2652,  2660,  2666,  2672,  2678,  2684,  2690,  2696,  2704,  2704,
    2706,  2706,  2708,  2710,  2710,  2712,  2712,  2714,  2719,  2729,
    2729,  2732,  2738,  2745,  2745,  2747,  2747,  2749,  2751,  2758,
    2758,  2760,  2772,  2782,  2788,  2788,  2791,  2796,  2797,  2801,
    2801,  2803,  2805,  2808,  2811,  2811,  2813,  2820,  2820,  2828,
    2828,  2830,  2832,  2834,  2836,  2836,  2838,  2843,  2851,  2856,
    2862,  2862,  2864,  2866,  2868,  2868,  2870,  2878,  2887,  2887,
    2890,  2891,  2894,  2897,  2897,  2899,  2904,  2904,  2906,  2908,
    2910,  2912,  2912,  2921,  2921,  2930,  2930,  2939,  2939,  2948,
    2948,  2957,  2957,  2966,  2966,  2976,  2976,  2978,  2984,  3008,
    3014,  3014,  3017,  3025,  3033,  3039,  3045,  3051,  3057,  3063,
    3069,  3076,  3076,  3078,  3078,  3080,  3082,  3082,  3084,  3084,
    3086,  3093,  3102,  3102,  3106,  3111,  3119,  3119,  3121,  3121,
    3123,  3125,  3133,  3133,  3135,  3147,  3157,  3163,  3163,  3166,
    3171,  3172,  3176,  3176,  3178,  3180,  3182,  3185,  3185,  3187,
    3193,  3193,  3201,  3201,  3203,  3205,  3208,  3208,  3216,  3222,
    3235,  3235,  3237,  3239,  3241,  3243,  3243,  3246,  3253,  3265,
    3265,  3267,  3269,  3271,  3277,  3277,  3279,  3279,  3281,  3287,
    3316,  3323,  3323,  3326,  3336,  3342,  3347,  3352,  3357,  3362,
    3367,  3372,  3379,  3379,  3381,  3381,  3383,  3386,  3387,  3393,
    3393,  3396,  3397,  3399,  3412,  3422,  3428,  3428,  3431,  3436,
    3437,  3441,  3441,  3443,  3445,  3447,  3454,  3454,  3456,  3461,
    3461,  3463,  3468,  3477,  3482,  3488,  3488,  3490,  3492,  3494,
    3494,  3496,  3501,  3515,  3523,  3523,  3526,  3532,  3538,  3544,
    3550,  3560,  3565,  3571,  3571,  3573,  3575,  3577,  3577,  3579,
    3585,  3590,  3592,  3592,  3594,  3596,  3608,  3608,  3610,  3615,
    3624,  3629,  3635,  3635,  3637,  3639,  3641,  3641,  3643,  3648,
    3660,  3668,  3668,  3671,  3676,  3681,  3686,  3694,  3699,  3705,
    3705,  3707,  3709,  3711,  3711,  3713,  3719,  3724,  3726,  3726,
    3728,  3730,  4031,  4037,  4043,  4049,  4055,  4061,  4067,  4073,
    4082,  4088,  4097,  4125,  4126,  4130,  4131,  4132,  4134,  4136,
    4136,  4138,  4139,  4140,  4141,  4177,  4179,  4193,  4193,  4195,
    4197,  4199,  4201,  4201,  4204,  4205,  4206,  4207,  4208,  4210,
    4218,  4218,  4220,  4220,  4222,  4228,  4236,  4236,  4238,  4238,
    4240,  4246,  4254,  4254,  4256,  4256,  4258,  4264,  4272,  4272,
    4274,  4274,  4276,  4282,  4290,  4290,  4292,  4292,  4294,  4306,
    4314,  4316,  4316,  4318,  4320,  4329,  4331,  4331,  4333,  4333,
    4335,  4351,  4354,  4354,  4356,  4356,  4359,  4390,  4398,  4400,
    4400,  4402,  4404,  4412,  4412,  4414,  4430,  4432,  4432,  4434,
    4434,  4436,  4467,  4477,  4477,  4479,  4481,  4489,  4489,  4491,
    4634,  4636,  4641,  4641,  4643,  4645,  4647,  4650,  4652,  4657,
    4657,  4659,  4661,  4663,  4666,  4668,  4673,  4673,  4675,  4677,
    4679,  4682,  4684,  4689,  4689,  4691,  4693,  4695,  4698,  4700,
    4705,  4705,  4707,  4709,  4711,  4714,  4716,  4721,  4721,  4723,
    4725,  4727,  4730,  4732,  4737,  4737,  4739,  4741,  4743,  4746,
    4775,  4865,  4890,  4913,  4913,  4916,  4917,  4918,  4919,  4920,
    4921,  5054,  5054,  5056,  5058,  5087,  5089,  5089,  5094,  5112,
    5139,  5139,  5142,  5143,  5144,  5145,  5146,  5147,  5148,  5149,
    5150,  5153,  5153,  5155,  5155,  5160,  5160,  5160,  5161,  5161,
    5161,  5162,  5162,  5162,  5163,  5163,  5165,  5167,  5176,  5182,
    5182,  5185,  5189,  5195,  5197,  5197,  5203,  5213,  5223,  5223,
    5225,  5227,  5229,  5232,  5232,  5243,  5251,  5251,  5253,  5255,
    5257,  5263,  5273,  5281,  5281,  5283,  5285,  5287,  5290,  5292,
    5301,  5307,  5307,  5310,  5314,  5320,  5322,  5324,  5324,  5334,
    5342,  5342,  5344,  5346,  5348,  5351,  5353,  5362,  5368,  5368,
    5371,  5375,  5381,  5383,  5386,  5391,  5402,  5418,  5418,  5420,
    5422,  5424,  5426,  5426,  5428,  5435,  5442,  5461,  5461,  5464,
    5465,  5467,  5467,  5469,  5471,  5473,  5473,  5476,  5478,  5486,
    5486,  5491,  5498,  5500,  5509,  5515,  5515,  5518,  5522,  5529,
    5531,  5534,  5538,  5549,  5565,  5565,  5567,  5569,  5571,  5571,
    5573,  5575,  5590,  5590,  5592,  5594,  5603,  5605,  5614,  5620,
    5620,  5623,  5627,  5634,  5636,  5639,  5643,  5654,  5671,  5671,
    5673,  5675,  5677,  5677,  5679,  5681,  5696,  5696,  5698,  5700,
    5710,  5712,  5721,  5727,  5727,  5730,  5734,  5740,  5742,  5744,
    5744,  5754,  5762,  5762,  5764,  5766,  5768,  5771,  5773,  5782,
    5788,  5788,  5791,  5795,  5801,  5803,  5806,  5810,  5821,  5837,
    5837,  5839,  5841,  5843,  5843,  5845,  5848,  5860,  5860,  5863,
    5864,  5865,  5867,  5900,  5902,  5912,  5918,  5918,  5921,  5925,
    5931,  5933,  5936,  5940,  5951,  5964,  5964,  5966,  5968,  5970,
    5970,  5972,  5999,  6010,  6010,  6013,  6014,  6015,  6017,  6017,
    6020,  6022,  6031,  6037,  6037,  6040,  6044,  6050,  6052,  6054,
    6054,  6064,  6072,  6072,  6074,  6076,  6078,  6081,  6084,  6102,
    6102,  6113,  6120,  6130,  6138,  6144,  6146,  6160,  6172,  6178,
    6184,  6184,  6186,  6188,  6190,  6192,  6202,  6208,  6214,  6214,
    6216,  6218,  6220,  6222,  6222,  6227,  6232,  6244,  6246,  6246,
    6249,  6250,  6251,  6259,  6266,  6266,  6268,  6270,  6288,  6299,
    6310,  6332,  6343,  6354,  6365,  6409,  6433,  6455,  6466,  6477,
    6488,  6499,  6510,  6524,  6535,  6549,  6564,  6579,  6591,  6603,
    6623,  6643,  6653,  6681,  6690,  6701,  6713,  6727,  6740,  6753,
    6763,  6773,  6786,  6786,  6788,  6798,  6816,  6816,  6818,  6825,
    6834,  6834,  6836,  6843,  6852,  6852,  6854,  6861,  6870,  6870,
    6872,  6879,  6944,  6944,  6946,  6953,  6962,  6962,  6964,  6971,
    6980,  6980,  6982,  6989,  6998,  6998,  7000,  7009,  7025,  7025,
    7027,  7034,  7043,  7043,  7045,  7052,  7061,  7061,  7063,  7070,
    7079,  7079,  7081,  7088,  7097,  7097,  7099,  7106,  7115,  7115,
    7119,  7127,  7136,  7136,  7138,  7145,  7154,  7154,  7156,  7163,
    7300,  7301,  7302,  7303,  7304,  7305,  7306,  7307,  7308,  7309,
    7310,  7311,  7312,  7313,  7314,  7315,  7316,  7317,  7318,  7319,
    7320,  7321,  7322,  7323,  7325,  7326,  7327,  7331,  7331,  7334,
    7335,  7337,  7337,  7340,  7341,  7345,  7345,  7350,  7350,  7355,
    7355,  7360,  7360,  7365,  7365,  7370,  7370,  7375,  7375,  7380,
    7380,  7385,  7385,  7390,  7390,  7395,  7395,  7400,  7400,  7405,
    7407,  7413,  7420,  7420,  7426,  7426,  7438,  7438,  7443,  7443,
    7448,  7448,  7458,  7465,  7471,  7472,  7474,  7475,  7478,  7482,
    7486,  7490,  7489,  7510,  7509,  7516,  7517,  7519,  7518,  7525,
    7526,  7529,  7535,  7543,  7550,  7568,  7568,  7579,  7579,  7582,
    7582,  7596,  7597,  7600,  7600,  7613,  7614,  7617,  7617,  7630,
    7631,  7634,  7634,  7644,  7645,  7651,  7652,  7653,  7654,  7655,
    7656,  7657,  7658,  7659,  7660,  7661,  7662,  7663,  7664,  7665,
    7666,  7667,  7668,  7669,  7672,  7683,  7691,  7691,  7694,  7695,
    7698,  7699,  7701,  7711,  7725,  7730,  7737,  7738,  7740,  7747,
    7752,  7759,  7760,  7762,  7769,  7774,  7781,  7782,  7784,  7791,
    7793,  7799,  7801,  7803,  7809,  7811,  7813,  7819,  7821,  7823,
    7829,  7831,  7833,  7839,  7839,  7844,  7846,  7848,  7854,  7854,
    7859,  7861,  7872,  7874,  7879,  7879,  7881,  7883,  7889,  7892,
    7894,  7900,  7903,  7905,  7911,  7914,  7916,  7922,  7926,  7925,
    7937,  7937,  7944,  7946,  7952,  7954,  7956,  7962,  7965,  7967,
    7973,  8090,  8090,  8094,  8095,  8096,  8097,  8098,  8099,  8100,
    8101,  8102,  8106,  8110,  8119,  8120,  8122,  8129,  8129,  8132,
    8133,  8137,  8139,  8145,  8148,  8150,  8156,  8159,  8159,  8169,
    8170,  8176,  8178,  8184,  8187,  8189,  8195,  8198,  8200,  8206,
    8209,  8211,  8217,  8220,  8222,  8228
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "BOOLEAN",
  "GREATERTHAN", "ENDOFELEMENT", "OSRLSTART", "OSRLSTARTEMPTY",
  "OSRLATTRIBUTETEXT", "OSRLEND", "WEIGHTEDOBJECTIVESATT",
  "EMPTYWEIGHTEDOBJECTIVESATT", "TARGETOBJECTIVENAMEATT",
  "EMPTYTARGETOBJECTIVENAMEATT", "NUMBEROFOTHERCONSTRAINTRESULTSATT",
  "NUMBEROFOTHEROBJECTIVERESULTSATT", "NUMBEROFOTHERRESULTSATT",
  "NUMBEROFOTHERSOLUTIONRESULTSATT", "NUMBEROFOTHERVARIABLERESULTSATT",
  "NUMBEROFSOLUTIONSATT", "NUMBEROFOTHERMATRIXOBJECTIVERESULTSATT",
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
  "MATRIXINVERSEEND", "COMPLEXCONJUGATESTART", "COMPLEXCONJUGATEEND",
  "COMPLEXMINUSSTART", "COMPLEXMINUSEND", "COMPLEXNEGATESTART",
  "COMPLEXNEGATEEND", "COMPLEXNUMBERSTART", "COMPLEXNUMBEREND",
  "COMPLEXPLUSSTART", "COMPLEXPLUSEND", "COMPLEXSQUARESTART",
  "COMPLEXSQUAREEND", "COMPLEXSUMSTART", "COMPLEXSUMEND",
  "COMPLEXTIMESSTART", "COMPLEXTIMESEND", "CREATECOMPLEXSTART",
  "CREATECOMPLEXEND", "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT",
  "EMPTYTRANSPOSEATT", "TRANSPOSEATT", "EMPTYIDATT", "IDATT", "' '",
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
  "matrixReferenceStart", "matrixRefAttributeList", "matrixRefAttribute",
  "matrixReferenceEnd", "matrixIdxATT", "matrixTransposeATT",
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
  "matrixTransposeContent", "scalarNode", "OSnLCNode", "complexNumber",
  "complexNumberStart", "complexNumberEnd", "complexNumberAttributes",
  "complexNumberAttList", "complexNumberAtt", "createComplex",
  "createComplexStart", "createComplexContent", "complexPlus",
  "complexPlusStart", "complexPlusContent", "complexSum", "$@29",
  "anothercsumnode", "complexMinus", "complexMinusStart",
  "complexMinusContent", "complexNegate", "complexNegateStart",
  "complexNegateContent", "complexConjugate", "complexConjugateStart",
  "complexConjugateContent", "complexTimes", "complexTimesStart",
  "complexTimesContent", "complexSquare", "complexSquareStart",
  "complexSquareContent", 0
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
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,    32,     9,
      13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   472,   473,   473,   474,   475,   476,   476,   477,   477,
     478,   479,   480,   481,   481,   482,   483,   483,   484,   484,
     485,   486,   486,   487,   487,   488,   489,   490,   490,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   492,   493,
     494,   495,   495,   496,   496,   496,   497,   497,   498,   498,
     499,   500,   501,   501,   502,   503,   504,   505,   505,   506,
     506,   507,   507,   508,   509,   510,   510,   511,   511,   512,
     513,   514,   515,   516,   516,   517,   517,   518,   519,   520,
     521,   522,   522,   523,   523,   524,   525,   526,   527,   528,
     528,   529,   529,   530,   531,   532,   533,   534,   534,   535,
     535,   536,   537,   538,   539,   540,   540,   541,   541,   542,
     543,   544,   545,   546,   546,   547,   547,   548,   549,   550,
     551,   552,   553,   553,   554,   554,   555,   556,   557,   557,
     558,   559,   560,   561,   561,   562,   562,   562,   563,   563,
     564,   564,   565,   566,   566,   567,   567,   568,   569,   570,
     570,   571,   571,   571,   571,   571,   571,   572,   573,   574,
     574,   575,   575,   576,   577,   578,   579,   580,   581,   581,
     582,   582,   583,   584,   585,   586,   587,   588,   588,   589,
     589,   590,   591,   592,   593,   594,   595,   595,   596,   596,
     597,   598,   599,   600,   601,   601,   602,   603,   604,   605,
     606,   607,   607,   608,   608,   609,   610,   611,   611,   612,
     613,   614,   615,   615,   616,   616,   616,   617,   617,   618,
     618,   619,   620,   620,   621,   621,   622,   623,   624,   624,
     625,   625,   625,   625,   625,   625,   626,   627,   628,   628,
     629,   629,   630,   631,   632,   633,   634,   634,   635,   635,
     636,   637,   638,   639,   640,   640,   641,   641,   642,   643,
     644,   645,   646,   646,   647,   647,   648,   649,   650,   651,
     652,   652,   653,   653,   654,   655,   656,   657,   658,   659,
     659,   660,   660,   661,   662,   663,   663,   664,   665,   666,
     667,   667,   668,   668,   668,   669,   669,   670,   670,   671,
     672,   672,   673,   673,   674,   675,   676,   676,   677,   677,
     677,   677,   677,   677,   677,   677,   677,   677,   677,   678,
     679,   680,   680,   681,   681,   682,   683,   684,   685,   686,
     686,   687,   687,   688,   689,   690,   691,   692,   692,   693,
     693,   694,   695,   696,   697,   698,   698,   699,   699,   700,
     701,   702,   703,   704,   704,   705,   705,   706,   707,   708,
     709,   710,   711,   711,   712,   712,   713,   714,   715,   715,
     716,   717,   718,   718,   719,   719,   719,   719,   720,   720,
     721,   721,   722,   723,   724,   724,   725,   726,   727,   728,
     728,   729,   729,   730,   731,   732,   733,   734,   735,   735,
     736,   736,   737,   738,   739,   740,   741,   742,   742,   743,
     743,   744,   745,   746,   747,   748,   748,   749,   750,   751,
     752,   753,   754,   754,   755,   755,   756,   757,   758,   758,
     759,   760,   761,   762,   762,   763,   763,   763,   764,   764,
     765,   765,   766,   767,   768,   768,   769,   769,   769,   769,
     770,   770,   771,   771,   772,   773,   774,   774,   775,   776,
     777,   778,   778,   779,   779,   779,   780,   781,   782,   783,
     784,   785,   786,   787,   787,   788,   788,   788,   789,   789,
     790,   790,   791,   792,   793,   793,   794,   795,   796,   797,
     797,   798,   798,   799,   799,   800,   800,   801,   802,   802,
     803,   803,   804,   805,   806,   806,   807,   808,   808,   809,
     809,   810,   811,   812,   813,   813,   814,   815,   816,   816,
     817,   817,   818,   819,   820,   820,   821,   822,   823,   823,
     824,   824,   825,   826,   826,   827,   828,   829,   829,   830,
     830,   831,   832,   833,   833,   834,   835,   836,   836,   837,
     837,   838,   838,   839,   839,   840,   841,   842,   842,   843,
     844,   844,   845,   846,   847,   848,   848,   849,   849,   850,
     850,   851,   851,   852,   852,   853,   853,   854,   854,   855,
     855,   856,   857,   858,   859,   859,   860,   860,   860,   860,
     860,   860,   860,   860,   860,   861,   861,   862,   862,   863,
     864,   864,   865,   865,   866,   867,   868,   868,   869,   869,
     870,   870,   871,   871,   872,   873,   874,   874,   875,   876,
     877,   878,   878,   879,   879,   879,   880,   880,   881,   882,
     883,   884,   884,   885,   886,   886,   887,   887,   888,   889,
     890,   891,   891,   892,   893,   894,   894,   895,   895,   896,
     897,   898,   898,   899,   900,   901,   901,   902,   902,   903,
     904,   904,   905,   906,   906,   907,   908,   909,   910,   910,
     911,   911,   912,   912,   913,   913,   914,   914,   915,   915,
     916,   916,   917,   917,   918,   919,   920,   921,   921,   922,
     922,   922,   922,   922,   922,   922,   922,   922,   923,   923,
     924,   924,   925,   926,   926,   927,   927,   928,   929,   930,
     930,   931,   931,   932,   932,   933,   933,   934,   935,   936,
     936,   937,   938,   939,   940,   940,   941,   941,   941,   942,
     942,   943,   944,   945,   946,   946,   947,   948,   948,   949,
     949,   950,   951,   952,   953,   953,   954,   955,   956,   956,
     957,   957,   958,   959,   960,   960,   961,   962,   963,   963,
     964,   964,   965,   966,   966,   967,   968,   968,   969,   970,
     971,   972,   972,   973,   973,   974,   974,   975,   975,   976,
     976,   977,   977,   978,   978,   979,   979,   980,   981,   982,
     983,   983,   984,   984,   984,   984,   984,   984,   984,   984,
     984,   985,   985,   986,   986,   987,   988,   988,   989,   989,
     990,   991,   992,   992,   993,   993,   994,   994,   995,   995,
     996,   997,   998,   998,   999,  1000,  1001,  1002,  1002,  1003,
    1003,  1003,  1004,  1004,  1005,  1006,  1007,  1008,  1008,  1009,
    1010,  1010,  1011,  1011,  1012,  1013,  1014,  1014,  1015,  1016,
    1017,  1017,  1018,  1019,  1020,  1021,  1021,  1022,  1023,  1024,
    1024,  1025,  1026,  1027,  1028,  1028,  1029,  1029,  1030,  1031,
    1032,  1033,  1033,  1034,  1034,  1034,  1034,  1034,  1034,  1034,
    1034,  1034,  1035,  1035,  1036,  1036,  1037,  1038,  1038,  1039,
    1039,  1040,  1040,  1041,  1042,  1043,  1044,  1044,  1045,  1045,
    1045,  1046,  1046,  1047,  1048,  1049,  1050,  1050,  1051,  1052,
    1052,  1053,  1054,  1055,  1055,  1056,  1056,  1057,  1058,  1059,
    1059,  1060,  1061,  1062,  1063,  1063,  1064,  1064,  1064,  1064,
    1064,  1065,  1065,  1066,  1066,  1067,  1068,  1069,  1069,  1070,
    1071,  1071,  1072,  1072,  1073,  1074,  1075,  1075,  1076,  1077,
    1078,  1078,  1079,  1079,  1080,  1081,  1082,  1082,  1083,  1084,
    1085,  1086,  1086,  1087,  1087,  1087,  1087,  1088,  1088,  1089,
    1089,  1090,  1091,  1092,  1092,  1093,  1094,  1094,  1095,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1109,  1110,  1110,  1110,  1111,  1112,
    1112,  1113,  1113,  1113,  1113,  1114,  1115,  1116,  1116,  1117,
    1118,  1119,  1120,  1120,  1121,  1121,  1121,  1121,  1121,  1122,
    1123,  1123,  1124,  1124,  1125,  1126,  1127,  1127,  1128,  1128,
    1129,  1130,  1131,  1131,  1132,  1132,  1133,  1134,  1135,  1135,
    1136,  1136,  1137,  1138,  1139,  1139,  1140,  1140,  1141,  1142,
    1142,  1143,  1143,  1144,  1145,  1146,  1147,  1147,  1148,  1148,
    1149,  1150,  1151,  1151,  1152,  1152,  1153,  1154,  1154,  1155,
    1155,  1156,  1157,  1158,  1158,  1159,  1160,  1161,  1161,  1162,
    1162,  1163,  1164,  1165,  1165,  1166,  1167,  1168,  1168,  1169,
    1170,  1171,  1172,  1172,  1173,  1174,  1175,  1176,  1177,  1178,
    1178,  1179,  1180,  1181,  1182,  1183,  1184,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1190,  1191,  1192,  1193,  1194,  1195,
    1196,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1202,  1203,
    1204,  1205,  1206,  1207,  1208,  1208,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,  1216,  1216,  1217,  1217,  1217,  1217,  1217,
    1217,  1218,  1218,  1219,  1220,  1221,  1222,  1222,  1223,  1224,
    1225,  1225,  1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,
    1226,  1227,  1227,  1228,  1228,  1229,  1229,  1229,  1229,  1229,
    1229,  1229,  1229,  1229,  1229,  1229,  1230,  1231,  1232,  1233,
    1233,  1234,  1234,  1235,  1236,  1236,  1237,  1238,  1239,  1239,
    1240,  1241,  1242,  1243,  1243,  1244,  1245,  1245,  1246,  1247,
    1248,  1249,  1250,  1251,  1251,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,  1258,  1259,  1259,  1260,  1261,  1262,  1262,  1263,
    1264,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1271,
    1272,  1272,  1273,  1274,  1275,  1275,  1276,  1277,  1277,  1278,
    1279,  1280,  1281,  1281,  1282,  1283,  1284,  1285,  1285,  1286,
    1286,  1287,  1287,  1288,  1289,  1290,  1290,  1291,  1292,  1293,
    1293,  1294,  1295,  1296,  1297,  1298,  1298,  1299,  1299,  1300,
    1301,  1302,  1302,  1303,  1304,  1304,  1305,  1306,  1307,  1307,
    1308,  1309,  1310,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1316,  1317,  1317,  1318,  1319,  1320,  1320,  1321,  1322,  1322,
    1323,  1324,  1325,  1325,  1326,  1327,  1328,  1328,  1329,  1330,
    1331,  1332,  1333,  1334,  1334,  1335,  1335,  1336,  1337,  1338,
    1338,  1339,  1340,  1340,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1347,  1348,  1348,  1349,  1350,  1351,  1351,  1352,  1353,
    1353,  1354,  1355,  1356,  1356,  1357,  1358,  1359,  1359,  1360,
    1360,  1360,  1361,  1362,  1363,  1364,  1365,  1365,  1366,  1366,
    1367,  1368,  1369,  1369,  1370,  1371,  1371,  1372,  1373,  1374,
    1374,  1375,  1376,  1377,  1377,  1378,  1378,  1378,  1379,  1379,
    1380,  1381,  1382,  1383,  1383,  1384,  1384,  1385,  1386,  1387,
    1387,  1388,  1389,  1389,  1390,  1391,  1392,  1393,  1394,  1395,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,
    1405,  1405,  1406,  1407,  1408,  1409,  1410,  1411,  1412,  1412,
    1413,  1414,  1415,  1416,  1416,  1417,  1418,  1419,  1420,  1420,
    1421,  1421,  1421,  1421,  1422,  1422,  1423,  1424,  1425,  1426,
    1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,
    1447,  1448,  1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,
    1457,  1458,  1459,  1459,  1460,  1461,  1462,  1462,  1463,  1464,
    1465,  1465,  1466,  1467,  1468,  1468,  1469,  1470,  1471,  1471,
    1472,  1473,  1474,  1474,  1475,  1476,  1477,  1477,  1478,  1479,
    1480,  1480,  1481,  1482,  1483,  1483,  1484,  1485,  1486,  1486,
    1487,  1488,  1489,  1489,  1490,  1491,  1492,  1492,  1493,  1494,
    1495,  1495,  1496,  1497,  1498,  1498,  1499,  1500,  1501,  1501,
    1502,  1503,  1504,  1504,  1505,  1506,  1507,  1507,  1508,  1509,
    1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,
    1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,
    1510,  1510,  1510,  1510,  1510,  1510,  1510,  1512,  1511,  1513,
    1513,  1515,  1514,  1516,  1516,  1518,  1517,  1520,  1519,  1522,
    1521,  1524,  1523,  1526,  1525,  1528,  1527,  1530,  1529,  1532,
    1531,  1534,  1533,  1536,  1535,  1538,  1537,  1540,  1539,  1541,
    1542,  1543,  1545,  1544,  1547,  1546,  1549,  1548,  1551,  1550,
    1553,  1552,  1554,  1555,  1556,  1556,  1557,  1557,  1558,  1558,
    1558,  1560,  1559,  1562,  1561,  1563,  1563,  1564,  1563,  1565,
    1565,  1566,  1566,  1567,  1568,  1570,  1569,  1571,  1571,  1573,
    1572,  1574,  1574,  1576,  1575,  1577,  1577,  1579,  1578,  1580,
    1580,  1582,  1581,  1583,  1583,  1584,  1584,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1585,  1586,  1587,  1587,  1588,  1588,
    1589,  1589,  1590,  1591,  1592,  1593,  1594,  1594,  1595,  1596,
    1597,  1598,  1598,  1599,  1600,  1601,  1602,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1618,  1619,  1620,  1621,  1622,  1622,
    1623,  1624,  1625,  1626,  1627,  1627,  1628,  1629,  1630,  1631,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1641,  1640,
    1642,  1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,
    1651,  1652,  1652,  1653,  1653,  1653,  1653,  1653,  1653,  1653,
    1653,  1653,  1654,  1655,  1656,  1656,  1657,  1658,  1658,  1659,
    1659,  1660,  1661,  1662,  1663,  1664,  1665,  1667,  1666,  1668,
    1668,  1669,  1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,
    1678,  1679,  1680,  1681,  1682,  1683
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
       1,     3,     1,     0,     2,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     3,     1,     4,     1,
       1,     0,     2,     1,     1,     3,     2,     0,     2,     1,
       1,     1,     1,     3,     1,     4,     1,     1,     0,     2,
       1,     1,     3,     2,     0,     2,     1,     1,     1,     1,
       3,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     3,     0,     2,     3,     1,     0,
       1,     3,     4,     1,     1,     0,     2,     1,     1,     3,
       2,     0,     2,     1,     1,     1,     1,     3,     0,     2,
       2,     1,     1,     1,     1,     3,     4,     1,     1,     0,
       2,     1,     1,     3,     2,     0,     2,     1,     1,     1,
       1,     3,     0,     2,     2,     1,     1,     1,     1,     3,
       4,     1,     1,     0,     2,     1,     1,     3,     2,     0,
       2,     1,     1,     1,     1,     3,     1,     4,     1,     1,
       0,     2,     1,     1,     3,     2,     0,     2,     1,     1,
       1,     1,     3,     0,     2,     3,     1,     0,     2,     1,
       1,     1,     3,     4,     1,     1,     0,     2,     1,     1,
       3,     2,     0,     2,     1,     1,     1,     1,     3,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     2,     1,
       4,     1,     1,     0,     2,     1,     1,     3,     2,     0,
       2,     1,     1,     1,     1,     3,     1,     5,     1,     0,
       1,     1,     3,     1,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       2,     0,     3,     1,     2,     0,     5,     0,     5,     0,
       5,     0,     4,     0,     5,     0,     5,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       1,     1,     0,     4,     0,     6,     0,     4,     0,     4,
       0,     4,     3,     1,     1,     2,     0,     2,     1,     1,
       1,     0,     4,     0,     4,     1,     2,     0,     4,     0,
       2,     1,     1,     4,     4,     0,     4,     0,     2,     0,
       4,     0,     2,     0,     4,     0,     2,     0,     4,     0,
       2,     0,     4,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     1,     1,
       1,     2,     4,     3,     3,     1,     1,     2,     4,     3,
       1,     1,     2,     4,     3,     1,     1,     2,     4,     2,
       1,     2,     2,     1,     3,     2,     1,     2,     2,     1,
       2,     4,     1,     0,     1,     2,     4,     1,     0,     1,
       2,     3,     2,     1,     1,     2,     2,     1,     3,     2,
       1,     2,     2,     1,     3,     2,     1,     3,     0,     4,
       0,     2,     2,     1,     3,     2,     1,     6,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     2,     1,     0,     2,     1,
       1,     3,     1,     3,     3,     1,     3,     0,     5,     0,
       2,     3,     1,     3,     3,     1,     2,     3,     1,     2,
       3,     1,     3,     3,     1,     2
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
     999,  1496,     0,  1532,     0,     0,    40,    41,    45,    44,
    1494,  1495,    43,  1530,  1531,     0,    68,    63,    65,    66,
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
    1536,     0,   169,   171,   170,  1534,  1535,     0,   174,   178,
     180,   179,     0,   183,   187,   189,   188,     0,   192,     0,
     204,   198,   201,   202,   999,   998,  1001,  1002,  1003,  1004,
    1000,  1497,  1533,    48,    55,     0,    51,    52,    57,    69,
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
    1537,   181,   190,   196,   205,   208,     0,   211,     0,    62,
      54,  1508,     0,    58,    60,    59,  1506,  1507,     0,   139,
     130,  1540,     0,   134,   137,   135,   136,  1538,  1539,   454,
     948,   457,   455,     0,     0,   460,   999,     0,     0,     0,
     325,   333,   341,   349,   357,   999,   371,   364,     0,   367,
     368,   372,     0,   394,     0,   403,     0,   412,   418,     0,
     424,   431,     0,   427,   428,   433,   283,   286,     0,   289,
       0,   218,   209,   213,   216,   214,   215,    61,     0,   138,
       0,   999,     0,   949,     0,   458,     0,     0,   999,   462,
     463,   464,   465,   989,  1451,  1457,  1462,   992,   366,   369,
       0,   393,   402,   411,   417,   426,   429,     0,   432,     0,
     296,   287,   291,   294,   292,   293,   217,  1509,  1541,     0,
       0,   953,   947,   950,   951,   471,   495,     0,   999,   999,
       0,     0,   381,  1488,     0,   373,   370,   378,   379,   376,
    1486,  1487,   377,   375,   374,     0,   439,   430,   434,   437,
     435,   436,   295,   999,   952,   959,     0,   955,   956,   961,
     497,   504,     0,     0,   472,   473,   477,   476,   475,   468,
     467,   999,   385,   384,   380,     0,   383,     0,   438,   990,
     954,   957,     0,   960,   506,   631,   507,     0,   501,   496,
     498,   499,     0,   481,   470,   478,   479,   474,   466,   382,
    1489,     0,   970,   958,   967,   968,     0,   962,   966,   964,
     965,   963,   633,   734,   634,   999,     0,   508,   503,   500,
       0,   480,   487,     0,   483,   484,   489,   969,   979,     0,
     978,     0,   972,   973,   975,   976,   977,     0,   736,   837,
     737,   999,     0,   635,     0,   514,   511,   505,   509,   510,
     502,   482,   485,     0,   488,   981,     0,   971,   974,     0,
     839,   909,   840,   999,     0,   738,     0,   641,   638,   632,
     636,   637,   999,   516,     0,   533,     0,     0,   494,   486,
     490,   492,   491,   980,  1454,   911,     0,     0,   999,     0,
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
       0,   542,   543,   547,  1460,   522,   525,     0,   987,   917,
     920,     0,   923,   908,   845,   907,     0,   855,   852,   847,
     850,   851,   788,   786,   790,     0,   773,   772,     0,   750,
     757,     0,   753,   754,   758,     0,   686,   666,  1098,   672,
     671,     0,     0,     0,  1139,  1456,   649,   652,     0,     0,
     583,   563,   569,   568,   541,   544,     0,     0,     0,   529,
     526,   530,   531,     0,   934,   921,   931,   932,   925,   930,
     928,   929,   926,   927,   999,   857,   866,     0,     0,   789,
     769,   775,   774,  1450,   752,   755,     0,     0,   701,   684,
     698,   699,     0,  1524,     0,  1500,     0,  1512,     0,   688,
     690,   689,   697,   696,  1498,  1499,   693,   695,  1510,  1511,
     692,  1522,  1523,   694,   691,  1105,   674,   673,     0,     0,
       0,  1051,  1094,  1090,  1092,  1093,     0,   656,   653,   657,
     658,     0,   598,   581,   595,   596,  1548,     0,   585,   587,
     586,   594,   593,   590,   589,   591,   588,   592,  1546,  1547,
     571,   570,     0,   554,   548,   545,   551,   552,   549,   550,
       0,     0,   933,   943,     0,   942,     0,   936,   937,   939,
     940,   941,   984,     0,     0,     0,   858,     0,   804,   787,
     801,   802,  1492,     0,   791,   792,   793,   798,  1490,  1491,
     800,   799,   796,   795,   797,   794,   777,   776,     0,   759,
     756,   760,   761,   722,   708,   700,     0,   703,   705,   709,
     704,   719,   724,     0,     0,     0,     0,  1112,   676,   675,
       0,     0,  1051,  1101,  1097,  1099,  1100,     0,     0,  1096,
    1049,  1050,     0,     0,   619,   605,   597,     0,   600,   602,
     606,   601,   616,   621,     0,   573,   572,   556,   553,     0,
     532,     0,   945,     0,   935,   938,   854,   869,   853,   867,
     871,     0,   864,   861,   856,   859,   860,   825,   811,   803,
       0,   806,   808,   812,   807,   822,   827,     0,   779,   778,
       0,   702,   706,     0,   720,     0,   723,     0,  1525,  1501,
    1513,  1119,   678,   677,     0,     0,  1051,  1108,  1104,  1106,
    1107,  1103,     0,  1452,     0,     0,  1054,  1052,  1056,  1095,
     659,   599,   603,     0,   617,     0,   620,  1549,   575,   574,
     555,  1471,   944,     0,   870,     0,     0,   805,   809,     0,
     823,     0,   826,  1493,   781,   780,   762,     0,   716,   710,
     707,   713,   714,   711,   712,  1051,   731,   721,   729,   730,
     725,   726,   728,   727,  1453,  1126,   680,   679,     0,     0,
    1051,  1115,  1111,  1113,  1114,  1110,     0,  1102,     0,     0,
    1065,  1061,  1062,  1063,     0,  1055,     0,   613,   607,   604,
     610,   611,   608,   609,  1051,   628,   618,   626,   627,   622,
     623,   625,   624,   577,   576,     0,   885,   868,   882,   883,
    1504,     0,   872,   874,   873,   881,   880,   879,  1502,  1503,
     877,   876,   878,   875,  1455,   863,  1141,   862,   865,  1143,
       0,   819,   813,   810,   816,   817,   814,   815,  1051,   834,
     824,   832,   833,   828,   829,   831,   830,   783,   782,   995,
     996,   997,   715,     0,   718,     0,   733,  1133,   667,   681,
       0,     0,  1051,  1122,  1118,  1120,  1121,  1117,     0,  1109,
       0,     0,  1064,     0,  1053,     0,     0,  1057,  1059,  1058,
     612,     0,   615,     0,   630,   564,   578,   894,   884,     0,
     888,   887,   891,   896,   889,     0,     0,  1142,   818,     0,
     821,     0,   836,   770,   784,   717,   732,     0,  1051,  1129,
    1125,  1127,  1128,  1124,     0,  1116,  1463,  1066,     0,     0,
       0,   614,   629,   886,   890,   892,     0,   895,  1505,  1156,
    1153,  1140,  1151,  1152,  1528,     0,     0,     0,   999,  1144,
    1147,  1146,  1150,  1148,  1145,  1526,  1527,  1149,   820,   835,
    1051,  1136,  1132,  1134,  1135,  1131,     0,  1123,  1060,     0,
       0,  1051,   903,   893,   901,   902,   897,   898,   900,   899,
    1158,     0,  1173,  1160,     0,     0,     0,     0,  1138,     0,
    1130,  1472,  1474,     0,   905,  1154,  1155,     0,  1159,  1529,
       0,     0,   999,  1137,   904,  1413,  1187,  1364,  1219,  1236,
    1338,  1321,  1273,  1297,  1391,  1408,  1174,  1175,  1189,  1178,
    1221,  1181,  1238,  1182,  1275,  1183,  1299,  1179,  1323,  1180,
    1340,  1176,  1366,  1177,  1393,  1184,  1409,  1185,     0,     0,
    1172,  1157,  1484,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1161,  1162,  1165,  1166,  1167,  1168,  1163,  1164,
    1170,  1169,  1482,  1483,  1449,  1458,  1473,     0,  1188,     0,
    1220,     0,  1237,     0,  1274,     0,  1298,     0,  1322,     0,
    1339,     0,  1365,     0,  1392,  1520,     0,     0,  1410,  1518,
    1519,     0,     0,  1414,  1171,   999,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1516,     0,     0,  1190,  1191,
    1192,  1514,  1515,     0,  1222,  1223,  1224,     0,  1239,  1240,
    1241,     0,  1276,  1277,  1278,     0,  1300,  1301,  1302,     0,
    1324,  1325,  1326,     0,  1341,  1342,  1343,     0,  1367,  1368,
    1369,     0,  1394,  1395,  1396,     0,     0,     0,     0,  1412,
    1485,     0,     0,     0,     0,     0,     0,     0,     0,  1197,
    1186,  1194,     0,     0,     0,  1203,  1218,  1203,  1235,  1203,
    1272,  1203,  1296,  1203,  1320,  1203,  1337,  1203,  1363,  1203,
    1390,  1521,  1695,  1700,  1705,  1710,  1713,  1722,  1727,  1733,
    1737,  1740,  1743,  1746,  1748,  1753,  1756,  1759,  1685,  1716,
    1719,     0,  1665,  1686,  1666,     0,  1667,     0,  1668,     0,
    1669,     0,  1670,     0,  1683,     0,  1671,     0,  1672,  1723,
    1673,  1728,  1674,     0,  1675,     0,  1676,     0,  1677,     0,
    1678,     0,  1679,  1680,     0,  1681,     0,  1682,     0,     0,
    1418,     0,     0,  1464,  1475,  1476,  1465,  1466,  1467,  1468,
    1481,  1205,     0,     0,     0,  1051,  1200,  1196,  1198,  1199,
    1517,     0,  1227,     0,  1244,     0,  1281,     0,  1305,     0,
    1329,     0,  1346,     0,  1372,     0,  1399,     0,  1750,  1411,
    1407,     0,     0,     0,     0,     0,     0,     0,     0,  1709,
       0,  1712,  1595,  1587,  1589,  1593,  1597,  1599,  1645,  1661,
    1607,  1591,  1614,  1601,  1603,  1605,  1633,  1610,  1612,  1653,
    1649,  1657,  1577,  1581,  1585,  1623,  1616,  1618,  1620,     0,
    1571,  1572,  1552,  1553,  1555,  1556,  1557,  1558,  1560,  1561,
    1562,  1564,  1563,  1565,  1567,     0,  1568,  1566,  1574,  1575,
    1576,  1550,  1626,  1551,  1554,  1573,  1569,  1570,  1559,  1715,
       0,  1718,     0,     0,  1724,     0,  1729,     0,  1734,  1732,
       0,  1736,     0,  1739,     0,  1742,     0,  1745,     0,  1752,
       0,  1755,     0,  1758,  1448,  1426,  1433,     0,     0,  1419,
    1193,  1212,  1195,     0,  1051,  1208,  1204,  1206,  1207,  1202,
       0,  1459,  1229,  1226,     0,  1225,  1246,  1243,     0,  1242,
    1283,  1280,     0,  1279,  1307,  1304,     0,  1303,  1331,  1328,
       0,  1327,  1348,  1345,     0,  1344,  1374,  1371,     0,  1370,
    1401,  1398,     0,  1397,     0,     0,  1690,     0,     0,  1687,
    1684,  1688,  1689,     0,     0,  1696,  1694,     0,     0,  1701,
    1699,     0,     0,  1706,  1704,  1711,     0,     0,     0,     0,
       0,     0,     0,  1647,  1663,     0,     0,     0,     0,     0,
       0,  1639,     0,  1655,  1651,  1659,     0,     0,     0,     0,
       0,     0,  1717,     0,     0,  1720,     0,     0,     0,  1735,
       0,  1741,     0,     0,  1798,  1792,  1795,  1773,  1785,  1804,
       0,  1801,  1782,  1761,     0,  1762,  1763,  1777,  1764,     0,
    1765,     0,  1766,  1767,     0,  1768,     0,  1769,     0,  1770,
       0,  1771,     0,     0,  1760,     0,     0,  1427,  1051,  1422,
    1417,  1420,  1421,  1069,  1215,  1211,  1213,  1214,  1210,     0,
    1201,  1051,  1232,  1228,  1230,  1231,  1252,  1249,  1245,  1247,
    1248,  1288,  1286,  1282,  1284,  1285,  1312,  1310,  1306,  1308,
    1309,  1051,  1334,  1330,  1332,  1333,  1353,  1351,  1347,  1349,
    1350,  1379,  1377,  1373,  1375,  1376,  1083,  1404,  1400,  1402,
    1403,  1749,  1751,  1691,     0,     0,     0,  1697,     0,  1702,
       0,  1707,  1714,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1579,  1578,     0,  1583,  1582,     0,     0,
       0,     0,  1611,  1609,     0,  1624,     0,  1628,  1629,  1622,
    1627,  1630,  1731,     0,  1721,     0,  1726,  1738,  1744,  1747,
    1787,  1754,     0,  1776,     0,     0,     0,     0,     0,     0,
       0,     0,  1416,  1436,  1415,  1434,  1438,  1051,  1430,  1425,
    1428,  1429,  1424,     0,     0,  1217,  1067,  1068,     0,  1209,
    1234,     0,     0,  1251,     0,     0,  1336,     0,     0,     0,
    1406,  1082,     0,     0,  1693,  1698,  1703,  1708,     0,     0,
       0,     0,  1598,  1600,  1646,  1648,  1662,  1664,  1608,  1592,
       0,  1602,  1604,  1606,     0,  1635,     0,     0,  1634,  1640,
    1641,  1642,  1613,  1654,  1656,  1650,  1652,  1658,  1660,  1580,
    1584,     0,  1617,  1619,  1621,  1625,  1631,  1725,  1730,  1789,
       0,  1774,  1772,     0,     0,  1780,  1779,  1778,     0,  1781,
       0,  1784,     0,  1791,     0,  1794,     0,  1797,     0,  1800,
       0,  1803,     0,     0,  1437,  1432,     0,  1423,     0,  1072,
    1070,  1073,  1216,  1233,  1250,  1255,  1253,  1257,  1291,  1287,
    1289,     0,  1315,  1311,  1313,     0,  1335,  1356,  1352,  1354,
    1357,  1382,  1378,  1380,  1383,  1086,  1084,  1087,  1405,  1692,
    1596,  1588,  1590,  1594,     0,  1636,  1637,     0,     0,  1586,
       0,     0,  1775,     0,     0,     0,     0,     0,  1796,  1799,
       0,  1805,     0,  1156,  1446,  1435,  1444,  1445,     0,     0,
    1439,  1440,  1441,  1442,  1443,  1431,     0,  1080,  1076,  1077,
    1078,     0,  1074,     0,  1256,     0,  1294,  1290,  1292,  1293,
       0,  1318,  1314,  1316,  1317,     0,     0,     0,  1088,  1615,
       0,     0,     0,  1632,  1788,  1790,     0,     0,  1783,  1786,
    1793,  1802,  1757,     0,     0,     0,     0,  1079,     0,  1071,
    1265,  1263,  1254,  1261,  1262,     0,     0,  1258,  1259,  1260,
       0,     0,     0,  1544,     0,  1358,  1355,  1361,  1360,  1359,
    1542,  1543,     0,  1389,  1384,  1381,  1387,  1386,  1385,     0,
    1085,  1638,  1644,  1643,  1480,  1479,  1447,     0,     0,  1081,
       0,     0,     0,     0,  1295,  1319,     0,     0,  1388,     0,
    1469,  1470,  1075,  1264,  1268,  1266,  1269,     0,     0,  1362,
    1545,  1089,     0,     0,  1270,  1461,  1478,     0,     0,  1267,
       0,     0,  1477,  1271
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
    1402,  1403,  2265,  2266,  2360,  2361,  2431,  2469,  2267,  2428,
    2429,  2430,  2280,  2281,  2386,  2387,  2447,  2500,  1013,  1014,
    1153,  1154,  1155,  1262,  1070,  1071,  1254,  1255,  1256,  1332,
    1147,  1148,  1328,  1329,  1330,  1396,  1249,  1250,  1392,  1393,
    1394,  1488,  1323,  1324,  1484,  1485,  1486,  1534,  1387,  1388,
    1530,  1531,  1532,  1576,  1479,  1480,  1572,  1573,  1574,  1599,
    1073,  1448,  1449,  1516,  1517,  1559,  1551,  1552,  1553,  1591,
    1592,  1593,  1607,  1608,  1662,  1651,  1606,  1626,  1627,  1628,
    1677,  1678,  1718,  1770,  1862,  1771,  1772,  1867,  1868,  1869,
    2000,  1863,  1864,  1996,  1997,  1998,  2139,  1992,  1993,  2135,
    2136,  2137,  2268,  1629,  1630,  1679,  1680,  1724,  1776,  1873,
    2003,  2004,  2143,  2144,  2145,  2271,  1631,  1632,  1681,  1682,
    1728,  1778,  1875,  2007,  2008,  2148,  2149,  2150,  2272,  2273,
    2366,  2367,  2433,  2434,  2477,  2472,  2473,  2474,  2511,  2525,
    2526,  2533,  2539,  1633,  1634,  1683,  1684,  1732,  1780,  1877,
    2011,  2012,  2153,  2154,  2155,  2274,  2370,  2371,  2437,  2438,
    2439,  1635,  1636,  1685,  1686,  1736,  1782,  1879,  2015,  2016,
    2158,  2159,  2160,  2275,  2374,  2375,  2442,  2443,  2444,  1637,
    1638,  1687,  1688,  1740,  1784,  1881,  2019,  2020,  2163,  2164,
    2165,  2277,  1639,  1640,  1689,  1690,  1744,  1786,  1883,  2023,
    2024,  2168,  2169,  2170,  2278,  2379,  2380,  2445,  2485,  2486,
    1641,  1642,  1691,  1692,  1748,  1788,  1885,  2027,  2028,  2173,
    2174,  2175,  2279,  2383,  2384,  2446,  2494,  2495,  1643,  1644,
    1693,  1694,  1752,  1790,  1887,  2031,  2032,  2178,  2179,  2180,
    2282,  1645,  1646,  1697,  1890,  1647,  1648,  1702,  1759,  2254,
    1851,  1852,  1988,  2130,  2131,  2132,  2263,  1986,  1987,  2126,
    2259,  2260,  2261,  2356,  2125,  2255,  2256,  2353,  2354,  2420,
    2415,  2416,  2417,  1703,  1560,   952,   434,  1074,  1130,   798,
    1206,   923,   435,  1561,  1719,   899,  2478,   436,  1335,  1663,
    1664,  1665,  1666,  1667,  2421,  2422,  1091,  1498,  1562,  1499,
    1668,  1669,  2534,  2479,  2335,  2336,  1670,  1671,  1672,  1673,
     729,   730,   731,  1217,  1218,  1219,   159,   160,   161,  1133,
    1134,  1135,  1437,  1438,  1439,   605,   606,   607,  1137,  1138,
    1139,  1720,  1721,  1722,  1698,  1699,  1700,  1140,  1141,  1142,
    1564,  1565,  1566,   162,   163,   164,   374,   375,   376,   616,
     617,   618,  2489,  2490,  2491,  1177,  1178,  1179,  2103,  1930,
    2076,  2214,  1931,  2077,  2217,  1932,  2078,  1933,  2058,  1934,
    2059,  1935,  2066,  1936,  2060,  1937,  2057,  1938,  2061,  1939,
    2062,  1940,  2068,  1941,  2069,  1942,  2070,  1943,  2065,  1944,
    1945,  2223,  1946,  2072,  1947,  2067,  1948,  2079,  1949,  2080,
    1950,  2081,  1951,  1952,  2229,  2084,  2230,  2231,  2400,  1953,
    2071,  2308,  2450,  2207,  2309,  2310,  2311,  1954,  2063,  2199,
    1955,  2074,  2210,  1956,  2073,  2209,  1957,  2075,  2211,  1958,
    2064,  2200,  1811,  1812,  1813,  1891,  2039,  2040,  2041,  2042,
    1814,  1815,  2046,  1893,  1816,  1817,  2050,  1895,  1818,  1819,
    2054,  1897,  1820,  1821,  1899,  1822,  1823,  1901,  1824,  1825,
    1959,  1826,  1827,  1961,  1828,  1829,  1963,  2234,  1830,  1831,
    1965,  2236,  1964,  1832,  1833,  1969,  1834,  1835,  1971,  1836,
    1837,  1973,  1838,  1839,  1975,  1840,  1841,  1977,  1842,  1888,
    2034,  1843,  1844,  1979,  1845,  1846,  1981,  1847,  1848,  1983,
    2104,  2105,  2106,  2107,  2332,  2242,  2243,  2337,  2108,  2109,
    2339,  2110,  2111,  2341,  2112,  2329,  2401,  2113,  2114,  2343,
    2115,  2116,  2345,  2117,  2118,  2347,  2119,  2120,  2349,  2121,
    2122,  2351
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2003
static const yytype_int16 yypact[] =
{
     256, -2003, -2003,   131,    37,   163, -2003, -2003,   156,   -14,
   -2003,   333, -2003,   472, -2003, -2003, -2003, -2003,    63,   515,
   -2003, -2003, -2003, -2003, -2003,    37, -2003, -2003, -2003, -2003,
   -2003,   -95,   525,    32, -2003, -2003, -2003, -2003,   227,   948,
     156, -2003,    70,   536,     6, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,    86,
      33, -2003, -2003,   192, -2003,   539, -2003,   543, -2003,   558,
   -2003,   562, -2003,   566, -2003,   570, -2003,   578, -2003,   389,
   -2003,   418, -2003, -2003,   422, -2003, -2003,   433, -2003, -2003,
     446, -2003, -2003,   453, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,   122,
     586,    69, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003,   151,   455, -2003, -2003,   598, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,   450, -2003,   389, -2003, -2003,
   -2003, -2003,   469, -2003,   474,   607,   192, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,   115, -2003, -2003, -2003, -2003,
      18, -2003, -2003, -2003, -2003,    17, -2003, -2003, -2003, -2003,
      13, -2003, -2003, -2003, -2003,     9, -2003, -2003, -2003, -2003,
     138, -2003, -2003, -2003, -2003,    88, -2003, -2003, -2003, -2003,
   -2003,   613, -2003,   363,   374,   359,   368,   372, -2003, -2003,
   -2003,    82, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003,   209,   467, -2003, -2003,   617, -2003,   633,
   -2003,   635, -2003,   640, -2003,   642, -2003,   389, -2003, -2003,
     116, -2003, -2003, -2003, -2003,   519,   265,   521,   265,   554,
     265,   560, -2003,   645, -2003,   561,    -1,   567,   575,   213,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003,   523, -2003, -2003,
     264, -2003, -2003,   254, -2003, -2003,   262, -2003, -2003,   276,
   -2003, -2003,   538, -2003, -2003,   524,   597,   -45, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003,   648,    50, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003,   309,   426, -2003, -2003,   660, -2003,   664, -2003,   667,
   -2003,   670, -2003,   672, -2003,   625, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003,   450, -2003,   389, -2003, -2003,   152, -2003,
   -2003, -2003, -2003,   157, -2003, -2003, -2003, -2003,    92, -2003,
   -2003, -2003, -2003,    84, -2003, -2003, -2003, -2003,   137, -2003,
   -2003, -2003, -2003,   674, -2003, -2003, -2003,   569,   695, -2003,
   -2003,   687, -2003, -2003, -2003, -2003, -2003,   695, -2003, -2003,
   -2003, -2003,   695, -2003, -2003, -2003, -2003,   712, -2003,   -29,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,   686,   641, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,   654,
     404, -2003, -2003,   -33, -2003, -2003, -2003, -2003, -2003,   740,
     742,   744, -2003, -2003, -2003, -2003, -2003, -2003, -2003,   135,
   -2003, -2003, -2003, -2003,   111, -2003, -2003, -2003, -2003,   100,
   -2003, -2003, -2003, -2003,   263, -2003, -2003, -2003, -2003,   108,
   -2003, -2003, -2003, -2003, -2003,   696, -2003,   745,   265,   747,
     265,   749,   265,   753, -2003,   698, -2003, -2003, -2003,   718,
   -2003, -2003,   731, -2003, -2003,   679, -2003, -2003,   691, -2003,
   -2003, -2003,   715, -2003,   -26, -2003, -2003, -2003, -2003, -2003,
     741, -2003,   787,   766, -2003,   773, -2003, -2003,   808, -2003,
   -2003,   788,   506, -2003, -2003, -2003, -2003, -2003,   703,   341,
   -2003, -2003, -2003,   705,   321, -2003, -2003,   535,   189, -2003,
   -2003,   852,   874,   876,   878, -2003, -2003,   800, -2003, -2003,
     802, -2003, -2003,   818, -2003, -2003,   860, -2003, -2003,   846,
     896,    59, -2003, -2003, -2003, -2003,   695, -2003, -2003, -2003,
   -2003,   695, -2003, -2003, -2003, -2003,   695, -2003, -2003, -2003,
   -2003,   898, -2003,   -24, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,   840,   568, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003,   709,   321,   829, -2003,
   -2003, -2003,   918, -2003, -2003, -2003, -2003, -2003,   580, -2003,
   -2003, -2003,   926, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003,   900,   922,   373, -2003,   927,   929,   933,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,   843,   854,
   -2003, -2003,   837, -2003,   839, -2003,   845, -2003, -2003,   849,
   -2003, -2003,   934,   668, -2003, -2003, -2003, -2003,   714,   321,
     661, -2003, -2003, -2003, -2003, -2003, -2003, -2003,   998, -2003,
    1004, -2003,   717, -2003,   931, -2003,  1011,  1056, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
     217, -2003, -2003, -2003, -2003, -2003, -2003,   721,   321,   720,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1055,
     291, -2003, -2003, -2003, -2003, -2003,  1006,   192, -2003, -2003,
    1059,   117, -2003, -2003,  1066, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,   733, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003,  1010,   997, -2003, -2003,
   -2003,   784,   723,   725,   192, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,   994, -2003,  1086, -2003, -2003,
   -2003, -2003,   728,   505, -2003,   792,  1073,   144, -2003, -2003,
   -2003, -2003,   202, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003,   322, -2003, -2003, -2003, -2003,  1092, -2003, -2003, -2003,
   -2003, -2003, -2003,   826,  1080, -2003,   730, -2003, -2003, -2003,
    1103, -2003, -2003,  1081,  1082, -2003, -2003, -2003, -2003,  1164,
   -2003,  1089,   301, -2003, -2003, -2003, -2003,  1171, -2003,   895,
    1160, -2003,   778, -2003,  1177,  1040, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003,   780,   441, -2003,  1032, -2003, -2003,  1181,
   -2003,  1120,  1166, -2003,   786, -2003,  1187,  1052, -2003, -2003,
   -2003, -2003, -2003, -2003,   890,  1090,   993,  1113, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003,  1129,  1191, -2003,   805,
   -2003,  1205,  1185, -2003, -2003, -2003, -2003, -2003, -2003,   912,
    1193,  1029, -2003, -2003, -2003,  1197,   993,  1236,   807, -2003,
   -2003, -2003, -2003,   809, -2003,  1240,   962, -2003, -2003, -2003,
   -2003, -2003, -2003,   949,  1207,  1046, -2003, -2003, -2003, -2003,
     813,  1248,   815, -2003, -2003, -2003,   827,   830, -2003,  1252,
     -65, -2003, -2003, -2003, -2003,  1254,   292, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003,  1247, -2003, -2003, -2003, -2003,   832,
    1271,   887, -2003,   939,   957, -2003, -2003, -2003, -2003,  1279,
     -55, -2003, -2003, -2003, -2003,   945,   957, -2003, -2003, -2003,
   -2003,   -71, -2003, -2003, -2003, -2003,  1281, -2003, -2003,  1145,
     991, -2003, -2003, -2003, -2003, -2003,  1223,  1230, -2003, -2003,
   -2003,   -63, -2003,   961, -2003,   959,   957, -2003, -2003, -2003,
   -2003,  1297,   -44, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003,  1259,  1074, -2003,  1148,  1301, -2003, -2003,  1165,  1013,
   -2003, -2003, -2003, -2003, -2003,  1267,  1074, -2003, -2003, -2003,
    1286,  1094, -2003, -2003, -2003, -2003, -2003,    58, -2003, -2003,
   -2003,   973,   284, -2003, -2003, -2003,  1396,  1263, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,  1374,  1074, -2003,  1402, -2003,
   -2003,  1380,  1106, -2003, -2003,   975,   527, -2003, -2003,  1088,
   -2003,  1148,  1408,   979, -2003, -2003, -2003, -2003,   155,   983,
     636, -2003,  1088, -2003, -2003, -2003,    75,   695,  1410, -2003,
   -2003, -2003, -2003,   242, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1204,   985,   810,
   -2003,  1088, -2003, -2003, -2003, -2003,   179,   -92, -2003, -2003,
   -2003, -2003,  1416, -2003,  1423, -2003,  1425, -2003,  1427, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003,  1114, -2003,  1148,   987,
    1430,  1283, -2003, -2003, -2003, -2003,   695, -2003, -2003, -2003,
   -2003,   -93, -2003, -2003, -2003, -2003, -2003,  1435, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
    1114, -2003,    15, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
    1135,  1438, -2003, -2003,  1453, -2003,  1389,   387, -2003, -2003,
   -2003, -2003, -2003,  -191,  1440,   989, -2003,   -91, -2003, -2003,
   -2003, -2003, -2003,  1457, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003,  1114, -2003,   695, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003,  1118,  1144, -2003, -2003,
    1311, -2003, -2003,  1458,  1455,  1459,  1460, -2003,  1137, -2003,
    1148,  1306,  1283, -2003, -2003, -2003, -2003,  1461,  1229, -2003,
    1321, -2003,  1146,  1168, -2003, -2003, -2003,  1131,  1169, -2003,
   -2003,  1325, -2003, -2003,  1464,  1137, -2003, -2003, -2003,  1170,
   -2003,  1470, -2003,  1327, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003,  1473, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
    1140,  1182, -2003, -2003,  1333, -2003, -2003,  1477,  1137, -2003,
    1188, -2003, -2003,   121, -2003,  1308,   257,  1478, -2003, -2003,
   -2003, -2003,  1151, -2003,  1148,  1310,  1283, -2003, -2003, -2003,
   -2003, -2003,  1167, -2003,  1480,  1312, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003,   126, -2003,  1314,   257, -2003,  1151, -2003,
   -2003, -2003, -2003,  1316,   470,  1481,   -72, -2003, -2003,   142,
   -2003,  1318,   257, -2003,  1151, -2003, -2003,    31, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,  1283, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003,  1159, -2003,  1148,  1320,
    1283, -2003, -2003, -2003, -2003, -2003,  1173, -2003,  1487,    78,
   -2003, -2003, -2003, -2003,  1483,  1098,    23, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003,  1283, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003,  1159, -2003,   -88, -2003, -2003, -2003, -2003,
   -2003,  1492, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
      27, -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1283, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1159, -2003, -2003,
   -2003, -2003, -2003,  1194, -2003,  1344, -2003, -2003, -2003, -2003,
    1148,  1324,  1283, -2003, -2003, -2003, -2003, -2003,  1178, -2003,
    1493,  1342, -2003,  1496, -2003,  1495,  1497, -2003, -2003, -2003,
   -2003,  1199, -2003,  1357, -2003, -2003, -2003, -2003, -2003,  1161,
    1220,  1359, -2003, -2003, -2003,  1503,  1326,   390, -2003,  1213,
   -2003,  1361, -2003, -2003, -2003, -2003, -2003,  1328,  1283, -2003,
   -2003, -2003, -2003, -2003,  1186, -2003, -2003, -2003,  1367,  1508,
    1510, -2003, -2003, -2003, -2003, -2003,  1330,   257, -2003,  1273,
   -2003, -2003, -2003, -2003, -2003,  1516,  1512,  1513, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
    1283, -2003, -2003, -2003, -2003, -2003,  1192, -2003, -2003,  1514,
    1517,  1283, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003,  1235, -2003, -2003,  1518,  1521,  1522,  1523, -2003,  1198,
   -2003, -2003, -2003,  1381, -2003, -2003,   606,  1332,   611, -2003,
    1524,  1526, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003,  1172, -2003,  1334,  1291,
   -2003, -2003, -2003,  1527,  1529,  1530,  1531,  1532,  1533,  1534,
    1535,  1536, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1537,   233,  1538,
     233,  1539,   233,  1540,   233,  1541,   233,  1542,   233,  1543,
     233,  1544,   233,  1545,   233, -2003,  1554,  1547, -2003, -2003,
   -2003,  1551,  1549, -2003, -2003, -2003,  1555,  1556,  1557,  1558,
    1559,  1560,  1561,   695,  1272, -2003,  1565,  1562, -2003, -2003,
   -2003, -2003, -2003,  1272, -2003, -2003, -2003,  1272, -2003, -2003,
   -2003,  1272, -2003, -2003, -2003,  1272, -2003, -2003, -2003,  1272,
   -2003, -2003, -2003,  1272, -2003, -2003, -2003,  1272, -2003, -2003,
   -2003,  1272, -2003, -2003, -2003,  1563,   435,  1566,  1295, -2003,
   -2003,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574, -2003,
   -2003,   141,  1337,  1575,  1578,  1293, -2003,  1293, -2003,  1293,
   -2003,  1293, -2003,  1293, -2003,  1293, -2003,  1293, -2003,  1293,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003,  1264, -2003, -2003, -2003,  1340, -2003,  1351, -2003,  1353,
   -2003,   435, -2003,   435, -2003,  1039, -2003,   435, -2003,  1110,
   -2003,  1110, -2003,  1339, -2003,   435, -2003,   435, -2003,   435,
   -2003,   435, -2003, -2003,   435, -2003,  1039, -2003,   435,  1580,
   -2003,  1338,  1148, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003,  1329,  1313,  1341,  1283, -2003, -2003, -2003, -2003,
   -2003,  1581,  1315,  1331,  1317,  1335,  1319,  1336,  1322,  1323,
    1346,  1348,  1349,  1355,  1363,  1369,  1365,  1371, -2003, -2003,
   -2003,     0,  1588,  1343,  1591,  1345,  1593,  1347,  1189, -2003,
     435, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1163,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,  1039, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
    1174, -2003,  1600,  1595, -2003,  1596, -2003,  1190, -2003, -2003,
     435, -2003,  1183, -2003,   435, -2003,   435, -2003,   662, -2003,
    1039, -2003,  1175, -2003, -2003, -2003, -2003,  1148,  1350, -2003,
   -2003, -2003, -2003,  1352,  1283, -2003, -2003, -2003, -2003, -2003,
    1373, -2003, -2003, -2003,  1354, -2003, -2003, -2003,  1356, -2003,
   -2003, -2003,  1358, -2003, -2003, -2003,  1360, -2003, -2003, -2003,
    1362, -2003, -2003, -2003,  1364, -2003, -2003, -2003,  1366, -2003,
   -2003, -2003,  1368, -2003,   335,  1179, -2003,  1601,  1607, -2003,
   -2003, -2003, -2003,  1608,  1375, -2003, -2003,  1610,  1377, -2003,
   -2003,  1613,  1379, -2003, -2003, -2003,  1206,  1039,  1039,  1039,
    1039,  1039,  1039, -2003, -2003,  1039,  1039,  1039,  1039,  1039,
    1039, -2003,  1039, -2003, -2003, -2003,  1370,  1372,  1039,   435,
     435,   435, -2003,  1224,     4, -2003,  1614,   435,   435, -2003,
    1200, -2003,  1202,  1196, -2003, -2003, -2003, -2003, -2003, -2003,
    1615, -2003, -2003, -2003,  1201, -2003, -2003, -2003, -2003,  1619,
   -2003,  1620, -2003, -2003,  1621, -2003,  1622, -2003,  1624, -2003,
    1625, -2003,  1626,  1039, -2003,  1138,  1376, -2003,  1283, -2003,
   -2003, -2003, -2003,  1482, -2003, -2003, -2003, -2003, -2003,  1383,
   -2003,  1283, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003,  1283, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003,  1632,  1634,  1637, -2003,  1638, -2003,
    1639, -2003, -2003,  1039,  1039,  1039,  1039,  1282,  1284,   556,
     751,  1265,  1274,  1039,  1269,  1275,  1270,    99,  1261,   770,
     824,   865,  1255, -2003, -2003,  1256, -2003, -2003,  1039,  1249,
    1250,  1251, -2003, -2003,  1258, -2003,  1658, -2003, -2003, -2003,
   -2003, -2003, -2003,  1257, -2003,  1253, -2003, -2003, -2003, -2003,
   -2003, -2003,  1378,  1162,  1039,   662,   662,   662,   662,   662,
     662,  1039, -2003, -2003, -2003, -2003, -2003,  1283, -2003, -2003,
   -2003, -2003, -2003,  1415,  1229, -2003,  1519, -2003,  1388, -2003,
   -2003,  1390,  1392,  1528,   -54,   -48, -2003,  1394,   -21,   -15,
   -2003,  1546,  1399,  1667, -2003, -2003, -2003, -2003,  1384,  1385,
    1386,  1387, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
    1039, -2003, -2003, -2003,   906, -2003,  1671,  1672, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003,  1278, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
    1231, -2003, -2003,  1675,  1676, -2003, -2003, -2003,  1039, -2003,
     662, -2003,   662, -2003,  1237, -2003,  1242, -2003,   662, -2003,
    1233, -2003,   435,  1382,   311, -2003,  1432, -2003,  1439, -2003,
   -2003,  1454, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003,  1441, -2003, -2003, -2003,  1443, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1454, -2003, -2003,
   -2003, -2003, -2003, -2003,  1391, -2003, -2003,  1683,   695, -2003,
    1684,   647, -2003,   695,   695,  1232,  1238,  1260, -2003, -2003,
    1239, -2003,  1262,  1273, -2003, -2003, -2003, -2003,  1686,  1688,
   -2003, -2003, -2003, -2003, -2003, -2003,    81, -2003, -2003, -2003,
   -2003,  1689, -2003,  1445,   102,  1039, -2003, -2003, -2003, -2003,
     437, -2003, -2003, -2003, -2003,    68,   110,  1690, -2003, -2003,
    1393,  1691,  1694, -2003, -2003, -2003,  1695,  1696, -2003, -2003,
   -2003, -2003, -2003,  1456,  1700,  1702,  1552, -2003,   695, -2003,
   -2003, -2003, -2003, -2003, -2003,  1701,  1703, -2003, -2003, -2003,
    1564,  1576,  1706, -2003,  1710, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003,  1577, -2003, -2003, -2003, -2003, -2003, -2003,  1711,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1708,  1709, -2003,
    1579,   -66,  1712,   695, -2003, -2003,  1582,  1713, -2003,  1583,
   -2003, -2003, -2003, -2003, -2003, -2003,  1484,  1715,  1716, -2003,
   -2003, -2003,  1717,  1719, -2003, -2003, -2003,   695,  1714, -2003,
    1720,  1450, -2003, -2003
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1679, -2003,
    1722, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1674,
   -2003, -2003, -2003, -2003,  1584, -2003, -2003, -2003, -2003, -2003,
    1395, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003,  1397, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1602,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
    1225, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003,  1511, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003,  1152, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,  1429, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003,  1100, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003,  1091, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003,  1214, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003,   996, -2003, -2003, -2003,
   -2003, -2003,   937, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,   765,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003,   722, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003,   480, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003,   483, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003,   736, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003,   520, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,   516, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,   697,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,   457, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003,   456, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,   250,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,   775, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,   571, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003,  1016, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003,   942, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
     -90, -2003, -2003, -2003, -2003,  -614, -2003,  -368, -1238,  -198,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -1249, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,  -743, -2003,
   -2003, -2003, -2003, -2003,  -698, -2003, -2003, -2003, -2003, -2003,
    -932, -2003, -2003, -2003, -2003, -2003, -1055, -2003, -2003, -2003,
   -2003, -2003, -1043, -2003, -2003, -2003, -2003, -2003, -1028, -2003,
   -2003, -2003, -2003, -2003, -1250, -2003, -2003, -2003, -2003, -2003,
   -1046, -1264, -2003, -2003, -2003, -2003, -2003, -2003, -2003,  -648,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -1143, -2003, -2003, -2003, -2003,
   -2003, -1003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003,   657, -2003, -1310, -1056,   727,
     413,   706, -2003, -2003,  -777,  -824, -2003, -2003,  -493, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -1008,  -672, -2003, -2002,
   -2003, -2003, -2003, -2003,  -671,  -670, -2003, -2003, -2003, -2003,
    -741, -2003, -2003, -2003, -2003, -2003,  -141, -2003, -2003, -1054,
   -2003, -2003, -2003, -2003, -2003,  -514, -2003, -2003, -2003, -2003,
   -2003,  -723, -2003, -2003, -2003, -2003, -2003, -1029, -2003, -2003,
    -580, -2003, -2003,  -689, -2003, -2003,  -230, -2003, -2003,  -592,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -1785, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -1773, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003,   -53, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -1845,  -663, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003, -2003,
   -2003, -2003
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1204
static const yytype_int16 yytable[] =
{
     501,   733,   286,  1331,   252,   666,  1381,   395,  1059,   504,
     615,  2035,  2036,   277,   506,  2224,  2225,   274,   381,  1277,
     386,   271,   268,   417,  1169,  1149,  1172,  1469,   758,  1470,
    1471,  1469,   799,  1470,  1471,  1469,  1420,  1470,  1471,   509,
    1929,  1028,   583,   126,   650,   127,   525,   128,  1898,   129,
    1900,  1174,  1464,  1216,  1960,  1221,  1043,   254,  1264,  1233,
    1297,  1980,  1970,  1507,  1972,   758,  1974,   705,  1976,  1087,
    1159,  1978,   928,   130,  1445,  1982,   428,  1395,  1188,  2482,
    1223,   977,  1491,   665,  2523,  2466,  1182,  1183,   486,    49,
      49,  1016,   283,    50,    50,  2368,  1286,   131,   483,    51,
      51,  2372,  1251,   756,   541,   373,   741,   380,  1231,   385,
    2304,  2305,   547,    52,    52,   538,   216,   299,   217,   265,
     365,  2492,  2493,   762,   763,  1276,  1476,  2056,  2377,    53,
      53,     6,  1367,  1368,  2381,   300,   218,  1406,  1407,   535,
     756,  1487,   280,   489,   490,   704,   219,   364,   808,   301,
    1181,  1287,   636,  1450,  1451,   872,   477,   302,     7,   637,
    2083,  1514,   548,   480,   220,  1504,  1156,   303,  1502,   304,
     221,  1309,    14,  1506,   153,   154,   542,   266,    12,  1227,
     487,   305,   611,   612,   740,   306,   284,   307,   643,   308,
    1228,   309,   474,   645,   484,  2123,   515,  2090,   647,   539,
    1446,  2092,   478,  2093,  1325,   481,   809,  1298,   366,  1522,
    1234,   764,  1520,  1265,  2524,   491,  1446,  1524,   520,    41,
     281,   536,  1044,  1027,   150,  2369,   601,   602,   721,   722,
     531,  2373,  1349,  1533,  2037,  1029,  1492,  1587,   560,  2467,
     565,   978,   570,   601,   602,   476,  1544,  1017,  2483,  2484,
    1266,  1235,  1299,  1057,  1060,  1508,  1170,   429,  2378,   801,
     430,  2182,   620,   431,  2382,  1365,   550,   544,   525,     1,
       2,   403,  2193,  2194,  2195,  2196,  2197,  2198,  1389,  1575,
    2201,  2202,  2203,  2204,  2205,  2206,   526,  2208,   811,   601,
     602,   812,  1088,  2218,   601,   602,    17,   418,  1433,   545,
    1436,  1100,   404,  1495,  1496,  1373,  2219,  2220,  2221,  1088,
     601,   602,  1192,   510,  2233,  2235,   584,  2475,   651,   132,
    1424,  1598,  1278,   601,   602,  1441,  1518,   559,  1083,   564,
    1500,   569,  1604,  2306,  1472,  1412,  1468,  2307,  2251,  2333,
    2334,  2476,  1481,    54,    20,    21,  1496,   601,   602,    80,
     278,  1456,   275,   269,   272,  1088,   151,   152,  1112,  2432,
    1088,   984,   153,   154,   985,   744,    55,    55,    56,    56,
      57,    57,    58,    58,   745,    30,  1088,  1143,   604,   723,
     724,   151,   152,   614,   222,  2448,   118,   153,   154,  1088,
     676,  1175,   677,   370,   371,  1193,  1194,   148,  1195,   310,
    2340,  2342,  2344,  2346,  2348,  2350,   817,   678,  2288,  2289,
    2290,  2291,   200,  1088,  2295,  2297,  1072,  1861,  2300, -1203,
    1224,   151,   152,   203,  2314,  2316,  2318,   204,   683,   151,
     152,  1715,  1716,  2321,  1527,   611,   612,   687,   205,  1717,
     208,   370,   371,  2488,  2496,   796,   723,   724,   151,   152,
    1103,   206,   601,   602,   818,   819,   664,   820,   207,  2338,
     734,   299,   611,   612,   238,  2038,  2352,   396,   397,   398,
     399,  2226,   257,   709,  1144,   818,   819,   258,   820,   300,
     720,   153,   154,    25,    26,   151,   152,   292,  1176,   601,
     602,   294,   126,   301,   127,  2406,   128,  2407,   129,   611,
     612,   302,   293,  2410,   295,   151,   152,  1554,  1555,   601,
     602,   303,   296,   304,   216,  2394,   217,  1225,   703,  2396,
     759,   760,   130,  1092,   336,   305,    33,    34,  1102,   306,
     368,   307,   377,   308,   218,   309,    44,    45,  2418,  2419,
    1193,  1194,  1989,  1195,   219,   769,   131,   121,   122,   732,
     165,   166,  1136,  2405,   170,   171,  2455,   739,   601,   602,
     153,   154,   220,   788,  1160,   382,  1173,   394,   221,   175,
     176,   387,  1189,   180,   181,   401,   757,   185,   186,  2412,
    1775,   190,   191,   402,  1777,   409,  1554,  1555,  1779,   195,
     196,   411,  1781,  1556,  1557,  1222,  1783,   211,   212,   410,
    1785,   412,  1232,   416,  1787,   151,   152,   834,  1789,   240,
     241,   153,   154,   757,   151,   152,  1999,   413,   259,   260,
     414,  1558,   415,  1792,   287,   288,   437,  1793,   338,   339,
    1122,  1794,   800,   856,   151,   152,  1123,  1124,   601,   602,
     153,   154,  1125,  1126,   343,   344,   348,   349,   611,   612,
    2480,   353,   354,   358,   359,   881,   389,   390,   464,   423,
     424,   499,  1430,  1431,   892,  1442,   796,   723,   724,   151,
     152,   439,   440,   601,   602,   444,   445,  2127,   449,   450,
     905,   454,   455,   459,   460,   494,   495,  1122,  1204,   916,
     502,   151,   152,  1123,  1124,   601,   602,   153,   154,  1125,
    1126,   489,   490,   871,   935,   611,   612,   551,   552,   573,
     574,  1127,  1128,   945,   598,   599,   608,   609,   507,  1190,
     660,   661,   521,  1792,  1383,   699,   700,  1793,   710,   711,
     404,  1794,   735,   736,   777,   778,   782,   783,   921,   791,
     792,   835,   836,   990,   516,  2138,   418,  1795,   532,  1796,
     533,  1797,   534,  1798,  1422,  1799,   556,  1800,   561,  1801,
     566,  1802,  1443,  1803,   571,  1804,  2181,  1805,   578,  1806,
    1466,  1807,  1872,  1808,  1874,  1809,  1876,  1810,  1878,   579,
    1880,   580,  1882,   589,  1884,  1038,  1886,   581,  1263,   857,
     858,   867,   868,   582,  1046,   590,  1122,   882,   883,  1374,
     151,   152,  1123,  1124,   601,   602,   153,   154,  1125,  1126,
     591,  1652,  1653,   592,   611,   612,   906,   907,   930,   931,
     936,   937,  1166,  1167,   954,   955,   960,   961,  1567,  1413,
    1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,   966,   967,
    1440,   971,   972,   996,   997,  1457,   593,  1795,   510,  1796,
     897,  1797,  1615,  1798,   619,  1799,   594,  1800,   626,  1801,
    1310,  1802,  1616,  1803,  1617,  1804,  1618,  1805,  1619,  1806,
    1620,  1807,  1621,  1808,  1622,  1809,  1623,  1810,  1624,  2262,
     627,  2094,   628,  2095,   629,  2096,   630,  2097,  1625,  2098,
     631,  2099,  2270,  2100,   632,  2101,   633,  2102,  1002,  1003,
     634,  1101,   635,  1725,   648,  1729,  1202,  1733,   656,  1737,
     584,  1741,  2276,  1745,  1902,  1749,  1903,  1753,  1904,   667,
    1905,   668,  1906,   669,  1907,  1132,  1908,  2294,  1909,   670,
    1910,   671,  1911,   674,  1912,   684,  1913,   685,  1914,  1171,
    1915,   686,  1916,   688,  1917,   691,  1918,   636,  1919,   692,
    1920,   693,  1921,   694,  1922,  1589,  1923,  1726,  1924,  1730,
    1925,  1734,  1926,  1738,  1927,  1742,  1928,  1746,  1220,  1750,
    1122,  1754,  1047,  1048,   151,   152,  1123,  1124,   601,   602,
     153,   154,  1125,  1126,  1093,  1094,  1117,  1118,   611,   612,
    1151,  1152,  1212,  1213,  1161,  1162,  1207,  1208,  1252,  1253,
    1292,  1293,   695,  1563,   706,  1902,   707,  1903,  2355,  1904,
     651,  1905,   708,  1906,   718,  1907,   715,  1908,   950,  1909,
    1902,  1910,  1903,  1911,  1904,  1912,  1905,  1913,  1906,  1914,
    1907,  1915,  1908,  1916,  1909,  1917,  1910,  1918,  1911,  1919,
    1912,  1920,  1913,  1921,  1914,  1922,  1915,  1923,  1916,  1924,
    1917,  1925,  1918,  1926,  1919,  1927,  1920,  1928,  1921,   719,
    1922,   743,  1923,   742,  1924,   761,  1925,   750,  1926,   767,
    1927,    81,  1928,    82,    83,    84,   768,    85,    86,    87,
     745,    88,    89,    90,   770,    91,    92,    93,   789,    94,
      95,  2094,   774,  2095,   790,  2096,   802,  2097,   805,  2098,
     827,  2099,   831,  2100,  2454,  2101,  2094,  2102,  2095,  1902,
    2096,  1903,  2097,  1904,  2098,  1905,  2099,  1906,  2100,  1907,
    2101,  1908,  2102,  1909,  2296,  1910,   828,  1911,  1902,  1912,
    1903,  1913,  1904,  1914,  1905,  1915,  1906,  1916,  1907,  1917,
    1908,  1918,  1909,  1919,  1910,  1920,  1911,  1921,  1912,  1922,
    1913,  1923,  1914,  1924,  1915,  1925,  1916,  1926,  1917,  1927,
    1918,  1928,  1919,  2313,  1920,   840,  1921,   841,  1922,   845,
    1923,   812,  1924,   847,  1925,  1382,  1926,   849,  1927,   850,
    1928,   853,  1902,   862,  1903,   863,  1904,   873,  1905,   874,
    1906,   875,  1907,   887,  1908,   878,  1909,   888,  1910,   893,
    1911,   894,  1912,   900,  1913,  1421,  1914,   897,  1915,   901,
    1916,   911,  1917,  1435,  1918,   902,  1919,   917,  1920,  2315,
    1921,  1465,  1922,  1902,  1923,  1903,  1924,  1904,  1925,  1905,
    1926,  1906,  1927,  1907,  1928,  1908,   912,  1909,   918,  1910,
     921,  1911,   924,  1912,   929,  1913,   941,  1914,   942,  1915,
     946,  1916,   947,  1917,   950,  1918,   959,  1919,   976,  1920,
     983,  1921,  2317,  1922,  1902,  1923,  1903,  1924,  1904,  1925,
    1905,  1926,  1906,  1927,  1907,  1928,  1908,   992,  1909,  1001,
    1910,  1007,  1911,  1010,  1912,  1015,  1913,  1022,  1914,  1034,
    1915,  1035,  1916,  2395,  1917,  1039,  1918,   978,  1919,   984,
    1920,  1052,  1921,  1058,  1922,  1067,  1923,  1072,  1924,  1075,
    1925,  1076,  1926,  1081,  1927,  1017,  1928,  1326,  1327,  1375,
    1376,  1390,  1391,  1399,  1400,  1414,  1415,  1425,  1426,  1458,
    1459,  1482,  1483,  1495,  1496,  1528,  1529,  1549,  1550,  1570,
    1571,  1581,  1582,  1649,  1650,  1768,  1695,  1696,  1865,  1866,
    1967,  1968,  1994,  1995,  2044,  2045,  2048,  2049,  2052,  2053,
    1597,  2128,  2129,  2133,  2134,  2141,  2142,  2146,  2147,  2151,
    2152,  2156,  2157,  2161,  2162,  2166,  2167,  2171,  2172,  2176,
    2177,  2212,  2213,  2215,  2216,  2252,  2253,  2257,  2258,  2330,
    2331,  2333,  2334,  2413,  2414,  2227,  1068,  1902,  1084,  1903,
    1029,  1904,  1104,  1905,  1060,  1906,  1588,  1907,  1105,  1908,
    1113,  1909,  1145,  1910,  1676,  1911,  1150,  1912,  1191,  1913,
    1110,  1914,  1204,  1915,  1243,  1916,  1244,  1917,  1245,  1918,
    1246,  1919,  1114,  1920,  1247,  1921,  1257,  1922,  1274,  1923,
    1258,  1924,  1280,  1925,  1281,  1926,  1234,  1927,  1291,  1928,
    2426,  2427,  2435,  2436,  2440,  2441,  2470,  2471,  1282,  1284,
    1307,  1311,  1233,  1318,  1317,  1321,  1334,  1319,  1320,  1333,
    1336,  1340,  1347,  1339,  1341,  1265,  1264,  1350,  1351,  1355,
    1298,  1385,  1352,  1357,  1297,  1363,  1384,  1366,  1398,  1444,
    1397,  1477,  2228,  1490,  1493,  1515,  1526,  1525,  1489,  1535,
    1537,  1536,  1538,  1539,  1543,  1540,  1541,  1760,  1446,  1542,
    1507,  1548,  1568,  1569,  1579,  1577,  1580,  1578,  1590,  1594,
    1595,  1596,  1601,  1600,  1605,  1602,  1609,  1610,  1611,  1612,
    1705,  1613,  1674,  1614,  1675,  1704,  1701,  1706,  1707,  1708,
    1709,  1710,  1711,  1712,  1713,  1850,  1769,  1889,  1714,  1723,
    1727,  1731,  1735,  1739,  1743,  1747,  1751,  1755,  1756,  1757,
    1758,  1761,  1762,  1763,  1764,  1765,  1766,  1767,  1773,  1861,
    1774,  1791,  1849,  1962,  1892,  1853,  1854,  1855,  1856,  1857,
    1858,  1859,  1860,  1870,  1871,  1894,  1990,  1896,  1984,  2001,
    1985,  1991,  2005,  2002,  2017,  2006,  2043,  2010,  2009,  2047,
    2014,  2051,  2055,  2086,  2082,  2013,  2087,  2088,  2091,  2184,
    2185,  2089,  2124,  2222,  2186,  2021,  2188,  2085,  2183,  2190,
    2025,  2192,  2232,  2237,  2018,  2239,  2240,  2022,  2029,  2238,
    2244,  2245,  2246,  2247,  2241,  2248,  2249,  2250,  2283,  2264,
    2298,  2026,  2284,  2030,  2033,  2285,  2286,  2287,  2140,  2292,
    2301,  2299,  2312,  2293,  2319,  2303,  2322,  2320,  2302,  2323,
    2269,  2326,  2324,  2325,  2187,  2424,  2357,  2362,  2359,  2363,
    2189,  2364,  2328,  2376,  2327,  2389,  2191,  2365,  2388,  2397,
    2398,  2399,  2402,  2403,  2404,  2425,  2408,  2409,  2411,  2451,
    1496,  2459,  2453,  2458,  2464,  2385,  2465,  2462,  2461,  2502,
    2468,  2499,  2503,  2504,  2505,  2506,  2507,  2460,  2508,  2512,
    2509,  2513,  2516,  2517,  2514,  2519,  2520,  2521,  2527,   117,
    2541,  2530,  2532,  2535,  2536,  2537,  2515,  2518,  2542,  2522,
    2538,  2543,  2529,  2531,   149,   337,   239,   595,   657,   689,
     264,   438,   621,  2390,   696,  1036,  2391,    40,  1342,  2392,
     787,   842,  2393,  1085,  1344,  1077,  1314,  1312,  1358,  1115,
    1360,  1545,  1040,   771,   848,  2463,  1215,  1434,  1285,  1099,
    2449,  2358,  1131,  2487,  2423,  2497,  2498,  2481,  1966,     0,
    2501,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   517,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   522,     0,     0,
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
    2452,     0,     0,     0,     0,  2456,  2457,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2510,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2540
};

static const yytype_int16 yycheck[] =
{
     368,   690,   200,  1252,   145,   597,  1316,     8,    52,   377,
     524,    11,    12,     4,   382,    11,    12,     4,   248,     4,
     250,     4,     4,    68,  1080,  1071,  1080,     4,   717,     6,
       7,     4,   773,     6,     7,     4,  1346,     6,     7,    68,
    1825,   112,    68,    37,    68,    39,    79,    41,  1821,    43,
    1823,  1080,  1362,  1109,  1827,  1109,   119,   147,   151,   151,
     151,  1846,  1835,   151,  1837,   754,  1839,   659,  1841,    11,
    1078,  1844,   896,    67,   146,  1848,    26,  1326,  1086,    11,
    1109,   146,     4,   597,   150,     4,    11,    12,     4,    57,
      57,   146,     4,    61,    61,   149,   287,    91,     6,    67,
      67,   149,  1148,   717,     4,   246,   698,   248,  1116,   250,
      11,    12,     4,    81,    81,     4,    47,    35,    49,     4,
       4,    11,    12,     6,     7,  1180,  1375,  1900,   149,    97,
      97,     0,    11,    12,   149,    53,    67,    11,    12,     4,
     754,  1390,     4,     6,     7,   659,    77,   237,     4,    67,
    1082,   342,    93,    11,    12,   844,     4,    75,   121,   100,
    1945,  1425,    54,     6,    95,  1414,    11,    85,  1406,    87,
     101,  1226,    16,  1423,   170,   171,    76,    62,    15,  1111,
      96,    99,   178,   179,   698,   103,    98,   105,   556,   107,
      11,   109,   333,   561,   102,  1980,   394,  1970,   566,    88,
     288,  1974,    50,  1976,  1250,    48,    62,   298,    92,  1458,
     302,    94,  1450,   306,   280,    78,   288,  1467,   416,   314,
      82,    86,   285,   966,    32,   279,   168,   169,    11,    12,
     428,   279,  1275,  1482,   234,   306,   158,  1547,   468,   158,
     470,   306,   472,   168,   169,   335,  1510,   302,   180,   181,
     343,   343,   343,   996,   298,   343,  1080,   207,   279,   773,
     210,  2034,    73,   213,   279,  1308,   464,     4,    79,    13,
      14,    58,  2057,  2058,  2059,  2060,  2061,  2062,  1324,  1528,
    2065,  2066,  2067,  2068,  2069,  2070,   319,  2072,    86,   168,
     169,    89,   234,  2078,   168,   169,   310,   342,  1354,    36,
    1354,  1042,    89,   235,   236,  1313,  2079,  2080,  2081,   234,
     168,   169,    70,   342,  2087,  2088,   342,   215,   342,   313,
    1348,  1570,   307,   168,   169,  1354,   299,   468,  1026,   470,
     307,   472,  1581,   234,   303,  1343,  1364,   238,  2123,   229,
     230,   239,  1388,   311,    11,    12,   236,   168,   169,   122,
     341,  1359,   339,   335,   337,   234,   164,   165,  1056,  2361,
     234,    69,   170,   171,    72,    74,   334,   334,   336,   336,
     338,   338,   340,   340,    83,   312,   234,  1066,   519,   162,
     163,   164,   165,   524,   315,  2387,   316,   170,   171,   234,
      17,  1080,    19,   176,   177,   153,   154,   311,   156,   317,
    2245,  2246,  2247,  2248,  2249,  2250,    84,    34,  2193,  2194,
    2195,  2196,    23,   234,  2199,  2200,   159,   276,  2203,   278,
    1109,   164,   165,     5,  2209,  2210,  2211,     5,   626,   164,
     165,   198,   199,  2218,  1480,   178,   179,   635,     5,   206,
     318,   176,   177,  2445,  2446,   161,   162,   163,   164,   165,
    1042,     5,   168,   169,   153,   154,   597,   156,     5,  2244,
     690,    35,   178,   179,   313,   465,  2251,   468,   469,   470,
     471,   467,     3,   671,  1066,   153,   154,     3,   156,    53,
     678,   170,   171,    11,    12,   164,   165,   124,  1080,   168,
     169,   132,    37,    67,    39,  2340,    41,  2342,    43,   178,
     179,    75,   128,  2348,   136,   164,   165,   196,   197,   168,
     169,    85,   140,    87,    47,  2300,    49,  1109,   659,  2304,
     718,   719,    67,  1037,   315,    99,    11,    12,  1042,   103,
      11,   105,    11,   107,    67,   109,    11,    12,   227,   228,
     153,   154,  1852,   156,    77,   743,    91,    11,    12,   690,
      11,    12,  1066,  2338,    11,    12,  2401,   698,   168,   169,
     170,   171,    95,   761,  1078,    11,  1080,     6,   101,    11,
      12,    11,  1086,    11,    12,     8,   717,    11,    12,  2352,
    1723,    11,    12,     8,  1727,    62,   196,   197,  1731,    11,
      12,   337,  1735,   203,   204,  1109,  1739,    11,    12,   335,
    1743,   339,  1116,     6,  1747,   164,   165,   805,  1751,    11,
      12,   170,   171,   754,   164,   165,  1865,   341,    11,    12,
      82,   231,    98,   288,    11,    12,   317,   292,    11,    12,
     160,   296,   773,   831,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    11,    12,    11,    12,   178,   179,
    2435,    11,    12,    11,    12,   853,    11,    12,    33,    11,
      12,    92,   192,   193,   862,  1354,   161,   162,   163,   164,
     165,    11,    12,   168,   169,    11,    12,  1987,    11,    12,
     878,    11,    12,    11,    12,    11,    12,   160,   218,   887,
       3,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     6,     7,   844,   902,   178,   179,    11,    12,    11,
      12,   184,   185,   911,    11,    12,    11,    12,     6,  1087,
      11,    12,    68,   288,  1316,    11,    12,   292,    11,    12,
      89,   296,    11,    12,    11,    12,    11,    12,   211,    11,
      12,    11,    12,   941,    58,  1994,   342,   412,     8,   414,
       8,   416,     8,   418,  1346,   420,    11,   422,    11,   424,
      11,   426,  1354,   428,    11,   430,   431,   432,    50,   434,
    1362,   436,  1775,   438,  1777,   440,  1779,   442,  1781,    48,
    1783,   102,  1785,    42,  1787,   983,  1789,    96,  1156,    11,
      12,    11,    12,    78,   992,     8,   160,    11,    12,  1313,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      44,   200,   201,    40,   178,   179,    11,    12,    11,    12,
      11,    12,   186,   187,    11,    12,    11,    12,  1517,  1343,
     219,   220,   221,   222,   223,   224,   225,   226,    11,    12,
    1354,    11,    12,    11,    12,  1359,    38,   412,   342,   414,
     214,   416,   246,   418,   319,   420,    68,   422,     6,   424,
    1228,   426,   256,   428,   258,   430,   260,   432,   262,   434,
     264,   436,   266,   438,   268,   440,   270,   442,   272,  2128,
       6,   444,     6,   446,     6,   448,    86,   450,   282,   452,
      88,   454,  2141,   456,    76,   458,    36,   460,    11,    12,
      54,  1042,     6,  1680,     6,  1682,  1104,  1684,    68,  1686,
     342,  1688,  2161,  1690,   358,  1692,   360,  1694,   362,    90,
     364,     3,   366,   343,   368,  1066,   370,   371,   372,     3,
     374,    31,   376,    11,   378,     8,   380,     8,   382,  1080,
     384,     8,   386,   100,   388,   108,   390,    93,   392,   110,
     394,   106,   396,   104,   398,  1547,   400,  1680,   402,  1682,
     404,  1684,   406,  1686,   408,  1688,   410,  1690,  1109,  1692,
     160,  1694,    11,    12,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    11,    12,    11,    12,   178,   179,
      11,    12,   182,   183,    11,    12,    11,    12,    11,    12,
      11,    12,    68,  1517,   343,   358,     8,   360,  2257,   362,
     342,   364,     8,   366,     3,   368,    85,   370,   208,   372,
     358,   374,   360,   376,   362,   378,   364,   380,   366,   382,
     368,   384,   370,   386,   372,   388,   374,   390,   376,   392,
     378,   394,   380,   396,   382,   398,   384,   400,   386,   402,
     388,   404,   390,   406,   392,   408,   394,   410,   396,     3,
     398,     6,   400,   343,   402,     6,   404,    61,   406,     3,
     408,   123,   410,   125,   126,   127,   343,   129,   130,   131,
      83,   133,   134,   135,    74,   137,   138,   139,    94,   141,
     142,   444,   308,   446,     8,   448,   304,   450,    25,   452,
       8,   454,    22,   456,   457,   458,   444,   460,   446,   358,
     448,   360,   450,   362,   452,   364,   454,   366,   456,   368,
     458,   370,   460,   372,   373,   374,   300,   376,   358,   378,
     360,   380,   362,   382,   364,   384,   366,   386,   368,   388,
     370,   390,   372,   392,   374,   394,   376,   396,   378,   398,
     380,   400,   382,   402,   384,   404,   386,   406,   388,   408,
     390,   410,   392,   393,   394,    62,   396,    86,   398,     5,
     400,    89,   402,    84,   404,  1316,   406,     6,   408,   284,
     410,    21,   358,     6,   360,   145,   362,   155,   364,     8,
     366,    71,   368,     6,   370,    29,   372,   145,   374,   309,
     376,   111,   378,    90,   380,  1346,   382,   214,   384,    80,
     386,     6,   388,  1354,   390,    24,   392,   305,   394,   395,
     396,  1362,   398,   358,   400,   360,   402,   362,   404,   364,
     406,   366,   408,   368,   410,   370,    51,   372,    45,   374,
     211,   376,    45,   378,     8,   380,     6,   382,   286,   384,
     301,   386,    45,   388,   208,   390,     8,   392,     6,   394,
       6,   396,   397,   398,   358,   400,   360,   402,   362,   404,
     364,   406,   366,   408,   368,   410,   370,    30,   372,     8,
     374,   342,   376,   326,   378,     6,   380,   342,   382,     8,
     384,   146,   386,   387,   388,    72,   390,   306,   392,    69,
     394,   342,   396,     6,   398,    46,   400,   159,   402,     8,
     404,   146,   406,    46,   408,   302,   410,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,   235,   236,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,  1713,   174,   175,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
    1558,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,   247,   248,    11,    12,    11,
      12,   229,   230,    11,    12,  2084,   322,   358,   112,   360,
     306,   362,     6,   364,   298,   366,  1547,   368,   145,   370,
       8,   372,   324,   374,  1612,   376,     8,   378,     8,   380,
      46,   382,   218,   384,     8,   386,     3,   388,     3,   390,
       3,   392,    52,   394,   320,   396,     6,   398,     3,   400,
     157,   402,   307,   404,     6,   406,   302,   408,     8,   410,
      11,    12,    11,    12,    11,    12,    11,    12,     5,    70,
       3,   343,   151,     8,     6,   328,   237,     8,     8,     8,
     149,   303,     8,   327,   343,   306,   151,   307,     8,     6,
     298,   330,   155,   343,   151,     8,     8,   299,     8,     8,
     323,   332,  2084,     6,    11,     3,   152,   303,   325,   321,
     158,     8,     6,     8,   343,     8,   307,  1705,   288,   152,
     151,     8,   299,   152,     6,   329,     6,   150,   245,     3,
       8,     8,     8,   331,   289,     8,     8,     6,     6,     6,
       3,   333,     8,   152,     8,   244,   202,     8,     8,     8,
       8,     8,     8,     8,     8,   250,   274,   283,    11,    11,
      11,    11,    11,    11,    11,    11,    11,     3,    11,     8,
      11,     6,     6,     6,     6,     6,     6,     6,     3,   276,
       8,     8,     6,   463,   234,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     6,   234,   257,   234,     8,     8,
     252,   278,   261,   278,   271,   278,     8,   278,   263,     8,
     278,     8,   413,     3,   441,   269,    11,    11,   425,     8,
       3,   421,   437,   389,     6,   267,     6,   443,   439,     6,
     265,   415,     8,   423,   278,   429,    11,   278,   259,   427,
      11,    11,    11,    11,   433,    11,    11,    11,     6,   157,
     375,   278,     8,   278,   273,     8,     8,     8,   275,   367,
     381,   377,   391,   369,   399,   385,   407,   401,   383,   409,
     277,     3,   411,   405,   289,  2354,   251,   279,   149,   279,
     293,   279,   419,   279,   417,     8,   297,   149,   279,     8,
       8,   403,   451,     8,     8,   253,   449,   445,   455,     6,
     236,   453,     8,   461,     8,   149,     8,   435,   459,     8,
      11,    11,     8,     8,     8,   249,     6,   447,     6,     8,
     158,     8,     6,     3,   150,     4,     8,     8,     6,    40,
       6,     8,   238,     8,     8,     8,   150,   150,     8,   150,
      11,   281,   150,   150,    60,   224,   134,   512,   586,   639,
     156,   312,   528,   359,   653,   980,   361,    25,  1268,   363,
     754,   814,   365,  1031,  1271,  1019,  1240,  1237,  1301,  1062,
    1304,  1511,   987,   747,   822,  2413,  1109,  1354,  1197,  1042,
     379,  2264,  1066,  2445,  2354,  2446,  2446,  2440,  1831,    -1,
     387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,    -1,    -1,
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
    2398,    -1,    -1,    -1,    -1,  2403,  2404,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2513,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2537
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    13,    14,   473,   474,   475,     0,   121,   482,   483,
    1114,  1115,    15,   476,    16,   480,   481,   310,   484,   485,
      11,    12,  1116,  1117,  1118,    11,    12,   477,   478,   479,
     312,   564,   565,    11,    12,   486,   487,   488,  1119,  1120,
     482,   314,   618,   619,    11,    12,   566,   567,   568,    57,
      61,    67,    81,    97,   311,   334,   336,   338,   340,   489,
     490,   491,   492,   493,   508,   509,   514,   515,   520,   521,
     526,   527,   532,   533,   538,   539,   544,   545,   550,   551,
     122,   123,   125,   126,   127,   129,   130,   131,   133,   134,
     135,   137,   138,   139,   141,   142,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1139,  1140,  1141,   480,   316,   670,
     671,    11,    12,   620,   621,   622,    37,    39,    41,    43,
      67,    91,   313,   569,   570,   571,   572,   573,   578,   579,
     585,   586,   592,   593,   599,   600,   604,   605,   311,   491,
      32,   164,   165,   170,   171,   494,   495,   496,  1107,  1468,
    1469,  1470,  1495,  1496,  1497,    11,    12,   510,   511,   512,
      11,    12,   516,   517,   518,    11,    12,   522,   523,   524,
      11,    12,   528,   529,   530,    11,    12,   534,   535,   536,
      11,    12,   540,   541,   542,    11,    12,   546,   547,   548,
      23,   552,  1102,     5,     5,     5,     5,     5,   318,   765,
     766,    11,    12,   672,   673,   674,    47,    49,    67,    77,
      95,   101,   315,   623,   624,   625,   626,   627,   632,   633,
     638,   639,   644,   645,   650,   651,   656,   657,   313,   571,
      11,    12,   574,   575,   576,   580,   581,   587,   588,   594,
     595,   601,  1468,   606,  1102,  1111,  1112,     3,     3,    11,
      12,   497,   498,   499,   496,     4,    62,   513,     4,   335,
     519,     4,   337,   525,     4,   339,   531,     4,   341,   537,
       4,    82,   543,     4,    98,   549,  1111,    11,    12,   553,
     554,   555,   124,   128,   132,   136,   140,   767,   768,    35,
      53,    67,    75,    85,    87,    99,   103,   105,   107,   109,
     317,   675,   676,   677,   678,   679,   684,   685,   690,   691,
     696,   697,   702,   703,   708,   709,   725,   726,   732,   733,
     739,   740,   746,   747,   751,   752,   315,   625,    11,    12,
     628,   629,   630,    11,    12,   634,   635,   636,    11,    12,
     640,   641,   642,    11,    12,   646,   647,   648,    11,    12,
     652,   653,   654,   658,  1102,     4,    92,   577,    11,   583,
     176,   177,   582,  1468,  1498,  1499,  1500,    11,   590,   589,
    1468,  1498,    11,   597,   596,  1468,  1498,    11,   602,    11,
      12,   607,   608,   609,     6,     8,   468,   469,   470,   471,
    1113,     8,     8,    58,    89,   500,   501,   502,   503,    62,
     335,   337,   339,   341,    82,    98,     6,    68,   342,   556,
     557,   558,   559,    11,    12,   770,   771,   772,    26,   207,
     210,   213,   769,  1105,  1428,  1434,  1439,   317,   677,    11,
      12,   680,   681,   682,    11,    12,   686,   687,   688,    11,
      12,   692,   693,   694,    11,    12,   698,   699,   700,    11,
      12,   704,   705,   706,    33,   710,  1108,   727,   728,   734,
     735,   741,   742,   748,  1468,   753,  1102,     4,    50,   631,
       6,    48,   637,     6,   102,   643,     4,    96,   649,     6,
       7,    78,   655,  1109,    11,    12,   659,   660,   661,    92,
     584,  1109,     3,   591,  1109,   598,  1109,     6,   603,    68,
     342,   610,   611,   612,   613,  1111,    58,   502,   504,   505,
    1111,    68,   558,   560,   561,    79,   319,   773,   774,   775,
     776,  1111,     8,     8,     8,     4,    86,   683,     4,    88,
     689,     4,    76,   695,     4,    36,   701,     4,    54,   707,
    1111,    11,    12,   711,   712,   713,    11,   730,   729,  1468,
    1498,    11,   737,   736,  1468,  1498,    11,   744,   743,  1468,
    1498,    11,   749,    11,    12,   754,   755,   756,    50,    48,
     102,    96,    78,    68,   342,   662,   663,   664,   665,    42,
       8,    44,    40,    38,    68,   612,   614,   615,    11,    12,
     507,   168,   169,   506,  1468,  1477,  1478,  1479,    11,    12,
     563,   178,   179,   562,  1468,  1477,  1501,  1502,  1503,   319,
      73,   775,  1075,  1076,   777,   778,     6,     6,     6,     6,
      86,    88,    76,    36,    54,     6,    93,   100,   714,   715,
     716,   717,   731,  1109,   738,  1109,   745,  1109,     6,   750,
      68,   342,   757,   758,   759,   760,    68,   664,   666,   667,
      11,    12,   617,   616,  1468,  1477,  1501,    90,     3,   343,
       3,    31,  1077,  1106,    11,   783,    17,    19,    34,   779,
     780,   781,   782,  1111,     8,     8,     8,  1111,   100,   716,
     718,   108,   110,   106,   104,    68,   759,   761,   762,    11,
      12,   669,   668,  1468,  1477,  1501,   343,     8,     8,  1111,
      11,    12,  1078,  1079,  1080,    85,   784,   785,     3,     3,
    1111,    11,    12,   162,   163,   719,   720,   721,   722,  1462,
    1463,  1464,  1468,  1495,  1498,    11,    12,   764,   763,  1468,
    1477,  1501,   343,     6,    74,    83,  1081,  1082,  1083,  1084,
      61,   800,   801,   786,   787,   788,  1107,  1468,  1495,  1111,
    1111,     6,     6,     7,    94,   723,   724,     3,   343,  1111,
      74,  1083,  1085,  1086,   308,   806,   807,    11,    12,   802,
     803,   804,    11,    12,   789,   790,   791,   788,  1111,    94,
       8,    11,    12,  1088,  1089,  1090,   161,  1087,  1431,  1462,
    1468,  1477,   304,   884,   885,    25,   808,  1104,     4,    62,
     805,    86,    89,   792,   793,   794,   795,    84,   153,   154,
     156,  1091,  1092,  1093,  1094,  1095,  1096,     8,   300,   946,
     947,    22,   886,  1101,  1111,    11,    12,   809,   810,   811,
      62,    86,   794,   796,   797,     5,  1097,    84,  1093,     6,
     284,  1008,  1009,    21,   948,  1098,  1111,    11,    12,   887,
     888,   889,     6,   145,   812,   813,   814,    11,    12,   799,
     798,  1468,  1495,   155,     8,    71,  1052,  1053,    29,  1010,
    1099,  1111,    11,    12,   949,   950,   951,     6,   145,   890,
     891,   892,  1111,   309,   111,   826,   827,   214,   815,  1437,
      90,    80,    24,  1054,  1103,  1111,    11,    12,  1011,  1012,
    1013,     6,    51,   952,   953,   954,  1111,   305,    45,   904,
     905,   211,   893,  1433,    45,   842,   843,   828,  1437,     8,
      11,    12,   816,   817,   818,  1111,    11,    12,  1055,  1056,
    1057,     6,   286,  1014,  1015,  1111,   301,    45,   966,   967,
     208,   955,  1427,   917,    11,    12,   906,   907,   908,     8,
      11,    12,   894,   895,   896,   855,    11,    12,   844,   845,
     846,    11,    12,   829,   830,   831,     6,   146,   306,   819,
     820,   821,   822,     6,    69,    72,  1058,  1059,  1060,  1061,
    1111,  1050,    30,  1016,  1100,   979,    11,    12,   968,   969,
     970,     8,    11,    12,   956,   957,   958,   342,   918,   919,
     326,   909,   910,  1170,  1171,     6,   146,   302,   897,   898,
     899,   900,   342,   856,   857,   847,   848,  1170,   112,   306,
     832,   833,   834,   835,     8,   146,   821,   823,  1111,    72,
    1060,  1062,  1063,   119,   285,  1051,  1111,    11,    12,  1017,
    1018,  1019,   342,   980,   981,   971,   972,  1170,     6,    52,
     298,   959,   960,   961,   962,   920,   921,    46,   322,   911,
    1176,  1177,   159,  1212,  1429,     8,   146,   899,   901,   858,
     859,    46,   849,  1176,   112,   834,   836,    11,   234,   824,
     825,  1448,  1477,    11,    12,  1065,  1066,  1067,  1064,  1431,
    1462,  1468,  1477,  1501,     6,   145,  1021,  1022,   982,   983,
      46,   973,  1176,     8,    52,   961,   963,    11,    12,   923,
     924,   925,   160,   166,   167,   172,   173,   184,   185,   922,
    1430,  1433,  1468,  1471,  1472,  1473,  1477,  1480,  1481,  1482,
    1489,  1490,  1491,  1495,  1501,   324,   912,  1182,  1183,  1212,
       8,    11,    12,  1172,  1173,  1174,    11,   902,   903,  1448,
    1477,    11,    12,   861,   862,   863,   186,   187,   860,  1430,
    1437,  1468,  1471,  1477,  1489,  1495,  1501,  1507,  1508,  1509,
     850,  1182,    11,    12,   837,   838,   839,   840,  1448,  1477,
    1109,     8,    70,   153,   154,   156,  1068,  1069,  1070,  1071,
    1072,  1073,  1111,  1029,   218,  1023,  1432,    11,    12,   985,
     986,   987,   182,   183,   984,  1427,  1430,  1465,  1466,  1467,
    1468,  1471,  1477,  1489,  1495,  1501,   974,  1182,    11,   964,
     965,  1448,  1477,   151,   302,   343,   926,   927,   928,   929,
     936,   937,   938,     8,     3,     3,     3,   320,   913,  1188,
    1189,  1212,    11,    12,  1178,  1179,  1180,     6,   157,  1142,
    1143,  1150,  1175,  1109,   151,   306,   343,   864,   865,   866,
     867,   874,   875,   876,     3,   851,  1188,     4,   307,   841,
     307,     6,     5,  1074,    70,  1070,   287,   342,  1020,  1030,
    1031,     8,    11,    12,  1024,  1025,  1026,   151,   298,   343,
     988,   989,   990,   991,   998,   999,  1000,     3,   975,  1188,
    1109,   343,   928,   930,   937,   939,   940,     6,     8,     8,
       8,   328,   914,  1194,  1195,  1212,    11,    12,  1184,  1185,
    1186,  1142,  1181,     8,   237,  1440,   149,  1144,  1145,   327,
     303,   343,   866,   868,   875,   877,   878,     8,   852,  1194,
     307,     8,   155,  1032,  1033,     6,  1028,   343,   990,   992,
     999,  1001,  1002,     8,   976,  1194,   299,    11,    12,   931,
     932,   933,   934,  1448,  1477,    11,    12,   942,   943,   944,
     941,  1429,  1468,  1501,     8,   330,   915,  1200,  1201,  1212,
      11,    12,  1190,  1191,  1192,  1142,  1187,   323,     8,    11,
      12,  1151,  1152,  1153,  1146,  1147,    11,    12,   869,   870,
     871,   872,  1448,  1477,    11,    12,   880,   881,   882,   879,
    1429,  1468,  1501,   853,  1200,    11,    12,  1035,  1036,  1037,
     192,   193,  1034,  1430,  1432,  1468,  1471,  1474,  1475,  1476,
    1477,  1489,  1495,  1501,     8,   146,   288,  1027,  1213,  1214,
      11,    12,   993,   994,   995,   996,  1448,  1477,    11,    12,
    1004,  1005,  1006,  1003,  1429,  1468,  1501,   977,  1200,     4,
       6,     7,   303,   935,  1110,   945,  1142,   332,   916,  1206,
    1207,  1212,    11,    12,  1196,  1197,  1198,  1142,  1193,   325,
       6,     4,   158,    11,  1149,   235,   236,  1148,  1449,  1451,
     307,   873,  1110,   883,  1142,   854,  1206,   151,   343,  1038,
    1039,  1040,  1041,  1042,  1213,     3,  1215,  1216,   299,   997,
    1110,  1007,  1142,   978,  1206,   303,   152,  1212,    11,    12,
    1202,  1203,  1204,  1142,  1199,   321,     8,   158,     6,     8,
       8,   307,   152,   343,  1213,  1041,  1043,  1044,     8,    11,
      12,  1218,  1219,  1220,   196,   197,   203,   204,   231,  1217,
    1426,  1435,  1450,  1477,  1492,  1493,  1494,  1495,   299,   152,
      11,    12,  1208,  1209,  1210,  1142,  1205,   329,   150,     6,
       6,    11,    12,  1046,  1047,  1048,  1045,  1429,  1468,  1501,
     245,  1221,  1222,  1223,     3,     8,     8,  1111,  1142,  1211,
     331,     8,     8,  1049,  1142,   289,  1228,  1224,  1225,     8,
       6,     6,     6,   333,   152,   246,   256,   258,   260,   262,
     264,   266,   268,   270,   272,   282,  1229,  1230,  1231,  1255,
    1256,  1268,  1269,  1295,  1296,  1313,  1314,  1331,  1332,  1344,
    1345,  1362,  1363,  1380,  1381,  1393,  1394,  1397,  1398,    11,
      12,  1227,   200,   201,   219,   220,   221,   222,   223,   224,
     225,   226,  1226,  1441,  1442,  1443,  1444,  1445,  1452,  1453,
    1458,  1459,  1460,  1461,     8,     8,  1111,  1232,  1233,  1257,
    1258,  1270,  1271,  1297,  1298,  1315,  1316,  1333,  1334,  1346,
    1347,  1364,  1365,  1382,  1383,   174,   175,  1395,  1486,  1487,
    1488,   202,  1399,  1425,   244,     3,     8,     8,     8,     8,
       8,     8,     8,     8,    11,   198,   199,   206,  1234,  1436,
    1483,  1484,  1485,    11,  1259,  1436,  1483,    11,  1272,  1436,
    1483,    11,  1299,  1436,  1483,    11,  1317,  1436,  1483,    11,
    1335,  1436,  1483,    11,  1348,  1436,  1483,    11,  1366,  1436,
    1483,    11,  1384,  1436,  1483,     3,    11,     8,    11,  1400,
    1111,     6,     6,     6,     6,     6,     6,     6,  1109,   274,
    1235,  1237,  1238,     3,     8,  1237,  1260,  1237,  1273,  1237,
    1300,  1237,  1318,  1237,  1336,  1237,  1349,  1237,  1367,  1237,
    1385,     8,   288,   292,   296,   412,   414,   416,   418,   420,
     422,   424,   426,   428,   430,   432,   434,   436,   438,   440,
     442,  1584,  1585,  1586,  1592,  1593,  1596,  1597,  1600,  1601,
    1604,  1605,  1607,  1608,  1610,  1611,  1613,  1614,  1616,  1617,
    1620,  1621,  1625,  1626,  1628,  1629,  1631,  1632,  1634,  1635,
    1637,  1638,  1640,  1643,  1644,  1646,  1647,  1649,  1650,     6,
     250,  1402,  1403,     8,     8,     8,     8,     8,     8,     8,
       8,   276,  1236,  1243,  1244,    11,    12,  1239,  1240,  1241,
       8,     6,  1243,  1261,  1243,  1274,  1243,  1301,  1243,  1319,
    1243,  1337,  1243,  1350,  1243,  1368,  1243,  1386,  1641,   283,
    1396,  1587,   234,  1595,   234,  1599,   234,  1603,  1584,  1606,
    1584,  1609,   358,   360,   362,   364,   366,   368,   370,   372,
     374,   376,   378,   380,   382,   384,   386,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,   408,   410,  1510,
    1511,  1514,  1517,  1519,  1521,  1523,  1525,  1527,  1529,  1531,
    1533,  1535,  1537,  1539,  1541,  1542,  1544,  1546,  1548,  1550,
    1552,  1554,  1555,  1561,  1569,  1572,  1575,  1578,  1581,  1612,
    1584,  1615,   463,  1618,  1624,  1622,  1624,    11,    12,  1627,
    1584,  1630,  1584,  1633,  1584,  1636,  1584,  1639,  1584,  1645,
    1510,  1648,  1584,  1651,     8,   252,  1409,  1410,  1404,  1429,
     257,   278,  1249,  1250,    11,    12,  1245,  1246,  1247,  1142,
    1242,     8,   278,  1262,  1263,   261,   278,  1275,  1276,   263,
     278,  1302,  1303,   269,   278,  1320,  1321,   271,   278,  1338,
    1339,   267,   278,  1351,  1352,   265,   278,  1369,  1370,   259,
     278,  1387,  1388,   273,  1642,    11,    12,   234,   465,  1588,
    1589,  1590,  1591,     8,    11,    12,  1594,     8,    11,    12,
    1598,     8,    11,    12,  1602,   413,  1584,  1528,  1520,  1522,
    1526,  1530,  1532,  1570,  1582,  1540,  1524,  1547,  1534,  1536,
    1538,  1562,  1545,  1576,  1573,  1579,  1512,  1515,  1518,  1549,
    1551,  1553,   441,  1510,  1557,   443,     3,    11,    11,   421,
    1584,   425,  1584,  1584,   444,   446,   448,   450,   452,   454,
     456,   458,   460,  1510,  1652,  1653,  1654,  1655,  1660,  1661,
    1663,  1664,  1666,  1669,  1670,  1672,  1673,  1675,  1676,  1678,
    1679,  1681,  1682,  1510,   437,  1416,  1411,  1429,    11,    12,
    1405,  1406,  1407,    11,    12,  1251,  1252,  1253,  1142,  1248,
     275,    11,    12,  1264,  1265,  1266,    11,    12,  1277,  1278,
    1279,    11,    12,  1304,  1305,  1306,    11,    12,  1322,  1323,
    1324,    11,    12,  1340,  1341,  1342,    11,    12,  1353,  1354,
    1355,    11,    12,  1371,  1372,  1373,    11,    12,  1389,  1390,
    1391,   431,  1584,   439,     8,     3,     6,   289,     6,   293,
       6,   297,   415,  1510,  1510,  1510,  1510,  1510,  1510,  1571,
    1583,  1510,  1510,  1510,  1510,  1510,  1510,  1565,  1510,  1577,
    1574,  1580,    11,    12,  1513,    11,    12,  1516,  1510,  1584,
    1584,  1584,   389,  1543,    11,    12,   467,  1495,  1501,  1556,
    1558,  1559,     8,  1584,  1619,  1584,  1623,   423,   427,   429,
      11,   433,  1657,  1658,    11,    11,    11,    11,    11,    11,
      11,  1510,   247,   248,  1401,  1417,  1418,    11,    12,  1412,
    1413,  1414,  1142,  1408,   157,  1154,  1155,  1160,  1254,   277,
    1142,  1267,  1280,  1281,  1307,  1325,  1142,  1343,  1356,  1374,
    1164,  1165,  1392,     6,     8,     8,     8,     8,  1510,  1510,
    1510,  1510,   367,   369,   371,  1510,   373,  1510,   375,   377,
    1510,   381,   383,   385,    11,    12,   234,   238,  1563,  1566,
    1567,  1568,   391,   393,  1510,   395,  1510,   397,  1510,   399,
     401,  1510,   407,   409,   411,   405,     3,   417,   419,  1667,
      11,    12,  1656,   229,   230,  1456,  1457,  1659,  1510,  1662,
    1652,  1665,  1652,  1671,  1652,  1674,  1652,  1677,  1652,  1680,
    1652,  1683,  1510,  1419,  1420,  1142,  1415,   251,  1440,   149,
    1156,  1157,   279,   279,   279,   149,  1282,  1283,   149,   279,
    1308,  1309,   149,   279,  1326,  1327,   279,   149,   279,  1357,
    1358,   149,   279,  1375,  1376,   149,  1166,  1167,   279,     8,
     359,   361,   363,   365,  1510,   387,  1510,     8,     8,   403,
    1560,  1668,   451,     8,     8,  1510,  1652,  1652,   449,   445,
    1652,   455,  1584,    11,    12,  1422,  1423,  1424,   227,   228,
    1421,  1446,  1447,  1492,  1495,   253,    11,    12,  1161,  1162,
    1163,  1158,  1451,  1284,  1285,    11,    12,  1310,  1311,  1312,
      11,    12,  1328,  1329,  1330,  1359,  1377,  1168,  1451,   379,
    1564,     6,  1109,     8,   457,  1652,  1109,  1109,   461,   453,
     447,   459,   435,  1221,     8,     8,     4,   158,    11,  1159,
      11,    12,  1287,  1288,  1289,   215,   239,  1286,  1438,  1455,
    1510,  1653,    11,   180,   181,  1360,  1361,  1449,  1451,  1504,
    1505,  1506,    11,    12,  1378,  1379,  1451,  1456,  1457,    11,
    1169,   387,     8,     8,     8,     8,   249,     6,     6,   158,
    1109,  1290,     8,     8,   150,   150,     6,     3,   150,     4,
       8,     8,   150,   150,   280,  1291,  1292,     6,  1109,   150,
       8,   150,   238,  1293,  1454,     8,     8,     8,    11,  1294,
    1109,     6,     8,   281
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
    if (parserData->tempStr == "true" || parserData->tempStr == "1")
    {
          if (osresult->setSolutionWeightedObjectives(parserData->solutionIdx, true) == false)
            osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionWeightedObjectives failed");
    }
    else if (parserData->tempStr == "false" || parserData->tempStr == "0")
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
        throw ErrorClass("more matrices than specified");
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
        ((OSMatrix*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
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

  case 1204:

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

  case 1205:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1211:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1212:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1219:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1220:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1223:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1224:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1228:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1229:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1236:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1237:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 1240:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1241:

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
    if (osglData->numberOfValues > 0)
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
    if (osglData->numberOfVarIdxPresent)
    {
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->numberOfVarIdx
            = osglData->numberOfVarIdx;
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx
            = new LinearMatrixElementTerm*[osglData->numberOfVarIdx];
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->constant
            = osglData->constant;
    }
    else
    {
        ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->numberOfVarIdx = 0;
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    }
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
    }
    break;

  case 1278:

    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1281:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1282:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");        
        ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1283:

    {
    osglData->numberOfValues = ((RealValuedExpressions*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((RealValuedExpressions*)osglData->tempC)->value = new RealValuedExpressionArray();
    ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues > 0)
    ((RealValuedExpressions*)osglData->tempC)->value->el
        = new RealValuedExpressionTree*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((RealValuedExpressions*)osglData->tempC)->value->el[i] = new RealValuedExpressionTree();
}
    break;

  case 1291:

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

  case 1295:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 1297:

    {
    osglData->tempC = new ComplexValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1298:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<complexValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 1301:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1302:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1305:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1306:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many <el> elements");        
        ((ComplexValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1307:

    {
    osglData->numberOfValues = ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ComplexValuedExpressions*)osglData->tempC)->value = new ComplexValuedExpressionArray();
    ((ComplexValuedExpressions*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues > 0)
    ((ComplexValuedExpressions*)osglData->tempC)->value->el
        = new ComplexValuedExpressionTree*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((ComplexValuedExpressions*)osglData->tempC)->value->el[i] = new ComplexValuedExpressionTree();
}
    break;

  case 1315:

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

  case 1319:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osglData->nonzeroCounter < osglData->numberOfValues) 
            ((ComplexValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
                ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 1321:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1322:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1325:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1326:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1330:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1331:

    {
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1338:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1339:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1342:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1343:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1346:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1347:

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

  case 1348:

    {
    osglData->numberOfValues = ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ConReferenceMatrixElements*)osglData->tempC)->value = new ConReferenceMatrixValues();
    ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues > 0)
    ((ConReferenceMatrixElements*)osglData->tempC)->value->el
        = new ConReferenceMatrixElement*[osglData->numberOfValues];

    for (int i=0; i<osglData->numberOfValues; i++)
        ((ConReferenceMatrixElements*)osglData->tempC)->value->el[i] = new ConReferenceMatrixElement();
}
    break;

  case 1356:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->valueTypePresent = false;
        osglData->multPresent = false;
        osglData->incrPresent = false;
        osglData->mult = 1;
        osglData->incr = 0;
        osglData->valueType = "";
    }
    break;

  case 1362:

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

  case 1364:

    {
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1365:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
}
    break;

  case 1368:

    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1369:

    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1372:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1373:

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

  case 1374:

    {
    osglData->numberOfValues = ((ComplexMatrixElements*)osglData->tempC)->numberOfValues;
    osglData->nonzeroCounter = 0;

    ((ComplexMatrixElements*)osglData->tempC)->value = new ComplexMatrixValues();
    ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl
        = osglData->numberOfValues;
    if (osglData->numberOfValues> 0)
    ((ComplexMatrixElements*)osglData->tempC)->value->el
        = new std::complex<double>[osglData->numberOfValues];
}
    break;

  case 1381:

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
                = std::complex<double>(osglData->realPart,osglData->imagPart); 
        }
        osglData->nonzeroCounter += osglData->mult;
    }
}
    break;

  case 1382:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                "number of <el> terms greater than expected");
        osglData->realPartPresent = false;
        osglData->imagPartPresent = false;
        osglData->multPresent = false;
        osglData->mult = 1;
    }
    break;

  case 1391:

    {
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1392:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
}
    break;

  case 1395:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1396:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1400:

    {
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1401:

    {
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1408:

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

  case 1410:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}
    break;

  case 1411:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 1412:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 1413:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}
    break;

  case 1414:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}
    break;

  case 1416:

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

  case 1417:

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

  case 1418:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 1419:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1425:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1426:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 1427:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1434:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}
    break;

  case 1435:

    {
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1436:

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

  case 1442:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    break;

  case 1443:

    {
        ((MatrixBlock*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
    break;

  case 1447:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 1448:

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

  case 1449:

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

  case 1450:

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

  case 1451:

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

  case 1452:

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

  case 1453:

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

  case 1454:

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

  case 1455:

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

  case 1456:

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

  case 1457:

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

  case 1458:

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

  case 1459:

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

  case 1460:

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

  case 1461:

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

  case 1462:

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

  case 1463:

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

  case 1464:

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

  case 1465:

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

  case 1466:

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

  case 1467:

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

  case 1468:

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

  case 1469:

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

  case 1470:

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

  case 1471:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1472:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1473:

    {
    if (osglData->matrixVarIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarIdx attribute in <matrixVar> element");
    osglData->matrixVarIdxPresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "<matrixVarIdx> cannot be negative");
    osglData->matrixVarIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1474:

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

  case 1475:

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

  case 1476:

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

  case 1477:

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

  case 1478:

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

  case 1479:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
}
    break;

  case 1480:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
}
    break;

  case 1481:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}
    break;

  case 1484:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}
    break;

  case 1485:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
    {
        if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->baseTranspose = false;
        else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osglData->baseTranspose = false;
        else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    }
    osglData->baseTransposePresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1488:

    {
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;
}
    break;

  case 1489:

    { 
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;   
    osglData->category = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1492:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;  
}
    break;

  case 1493:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;   
    osglData->conType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1496:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;
}
    break;

  case 1497:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;   
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1500:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
}
    break;

  case 1501:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
    osglData->enumType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1504:

    {
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
}
    break;

  case 1505:

    {
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
    osglData->matrixVarType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1508:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}
    break;

  case 1509:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1512:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
}
    break;

  case 1513:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
    osglData->objType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1516:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}
    break;

  case 1517:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->rowMajor = false;
        else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osglData->rowMajor = false;
        else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1520:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}
    break;

  case 1521:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1524:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
}
    break;

  case 1525:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
    osglData->solver = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1528:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}
    break;

  case 1529:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1532:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}
    break;

  case 1533:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1536:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
}
    break;

  case 1537:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
    osglData->unit = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1540:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}
    break;

  case 1541:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1544:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}
    break;

  case 1545:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1548:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}
    break;

  case 1549:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1577:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1581:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1585:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1587:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1589:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1591:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1593:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1595:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1597:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1599:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1601:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1603:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1605:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1607:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1610:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1611:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1612:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1613:

    {
}
    break;

  case 1614:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
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
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1618:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1620:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1622:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}
    break;

  case 1623:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 1628:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }
    break;

  case 1629:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }
    break;

  case 1631:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 1633:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 1634:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 1637:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }
    break;

  case 1641:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 1642:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 1643:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 1644:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1645:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1646:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 1648:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 1649:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1650:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1652:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 1653:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1654:

    {
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1656:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 1657:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1658:

    {
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1660:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 1661:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1662:

    {
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 1664:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 1684:

    {
    osnlData->matrixidxattON = false;
    if (osnlData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory idx attribute missing");
    if (osnlData->transposeAttributePresent == true)
        osnlData->nlMNodeMatrixRef->transpose = osnlData->matrixTransposeAttribute;
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}
    break;

  case 1685:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}
    break;

  case 1692:

    {
    if (osnlData->idxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "idx attribute repeated");
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
    osnlData->idxAttributePresent = true;
}
    break;

  case 1693:

    {
    if (osnlData->transposeAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "transpose attribute repeated");
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->matrixTransposeAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osnlData->matrixTransposeAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
    osnlData->transposeAttributePresent = true;
}
    break;

  case 1694:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1695:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 1698:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1699:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1700:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 1703:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1704:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1705:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 1708:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1710:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1713:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1716:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1719:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1722:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1724:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1727:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1729:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1731:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osnlData->includeDiagonalAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1733:

    {
     parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 1737:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1740:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1743:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1746:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1748:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1749:

    {
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 1751:

    { 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
}
    break;

  case 1753:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1756:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1759:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1772:

    {
}
    break;

  case 1773:

    {
    osglData->realPartPresent = false;
    osglData->imagPartPresent = false;
    osnlData->nlNodePoint = new OSnLCNodeNumber();
    osnlData->nlNodeVec.push_back(osnlData->nlNodePoint);
}
    break;

  case 1776:

    {
    ((OSnLCNodeNumber*)osnlData->nlNodePoint)->setValue(osglData->realPart, osglData->imagPart);
std::cout << "just to verify: value = " 
          << ((OSnLCNodeNumber*)osnlData->nlNodePoint)->getValue() << std::endl;
}
    break;

  case 1782:

    {
    osnlData->nlNodePoint = new OSnLCNodeCreate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1785:

    {
    osnlData->nlNodePoint = new OSnLCNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1787:

    {
    osnlData->nlNodePoint = new OSnLCNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->cSumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1788:

    {
    osnlData->cSumVec.back()->m_mChildren = new ExprNode*[ osnlData->cSumVec.back()->inumberOfChildren];
    osnlData->cSumVec.pop_back();
}
    break;

  case 1790:

    { 
    osnlData->cSumVec.back()->inumberOfChildren++; 
}
    break;

  case 1792:

    {
    osnlData->nlNodePoint = new OSnLCNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1795:

    {
    osnlData->nlNodePoint = new OSnLCNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1798:

    {
    osnlData->nlNodePoint = new OSnLCNodeConjugate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1801:

    {
    osnlData->nlNodePoint = new OSnLCNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1804:

    {
    osnlData->nlNodePoint = new OSnLCNodeSquare();
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


