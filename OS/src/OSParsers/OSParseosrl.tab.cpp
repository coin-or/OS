/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         osrlparse
#define yylex           osrllex
#define yyerror         osrlerror
#define yydebug         osrldebug
#define yynerrs         osrlnerrs


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






# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "OSParseosrl.tab.hpp".  */
#ifndef YY_OSRL_OS_SRC_OSPARSERS_OSPARSEOSRL_TAB_HPP_INCLUDED
# define YY_OSRL_OS_SRC_OSPARSERS_OSPARSEOSRL_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int osrldebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


    double   dval;
    OsXmlInt ival;
    char*    sval;


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int osrlparse (OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData);

#endif /* !YY_OSRL_OS_SRC_OSPARSERS_OSPARSEOSRL_TAB_HPP_INCLUDED  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  472
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  1214
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1807
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2546

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   722

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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
    3728,  3730,  3741,  3747,  3753,  3759,  3765,  3771,  3777,  3783,
    3792,  3798,  3807,  3835,  3836,  3840,  3841,  3842,  3844,  3846,
    3846,  3848,  3849,  3850,  3851,  3887,  3889,  3903,  3903,  3905,
    3907,  3909,  3911,  3911,  3914,  3915,  3916,  3917,  3918,  3920,
    3928,  3928,  3930,  3930,  3932,  3938,  3946,  3946,  3948,  3948,
    3950,  3956,  3964,  3964,  3966,  3966,  3968,  3974,  3982,  3982,
    3984,  3984,  3986,  3992,  4000,  4000,  4002,  4002,  4004,  4015,
    4023,  4031,  4033,  4033,  4035,  4037,  4046,  4048,  4048,  4050,
    4050,  4052,  4061,  4064,  4064,  4066,  4066,  4069,  4100,  4108,
    4110,  4110,  4112,  4114,  4122,  4122,  4124,  4133,  4135,  4135,
    4137,  4137,  4139,  4170,  4180,  4180,  4182,  4184,  4192,  4192,
    4194,  4330,  4332,  4337,  4337,  4339,  4341,  4343,  4346,  4348,
    4353,  4353,  4355,  4357,  4359,  4362,  4364,  4369,  4369,  4371,
    4373,  4375,  4378,  4380,  4385,  4385,  4387,  4389,  4391,  4394,
    4396,  4401,  4401,  4403,  4405,  4407,  4410,  4412,  4417,  4417,
    4419,  4421,  4423,  4426,  4428,  4433,  4433,  4435,  4437,  4439,
    4442,  4692,  4787,  4812,  4840,  4840,  4843,  4844,  4846,  4848,
    4849,  4850,  4994,  4994,  4996,  4998,  4998,  5028,  5030,  5030,
    5035,  5053,  5082,  5082,  5085,  5086,  5087,  5088,  5089,  5090,
    5091,  5092,  5093,  5096,  5096,  5098,  5098,  5103,  5103,  5103,
    5104,  5104,  5104,  5105,  5105,  5105,  5106,  5106,  5108,  5110,
    5119,  5125,  5125,  5128,  5132,  5138,  5140,  5140,  5146,  5156,
    5166,  5166,  5168,  5170,  5186,  5189,  5189,  5203,  5211,  5211,
    5213,  5215,  5217,  5223,  5233,  5241,  5241,  5243,  5245,  5247,
    5250,  5252,  5261,  5267,  5267,  5270,  5274,  5280,  5282,  5284,
    5284,  5294,  5302,  5302,  5304,  5306,  5308,  5311,  5313,  5322,
    5328,  5328,  5331,  5335,  5341,  5343,  5346,  5351,  5362,  5378,
    5378,  5380,  5382,  5384,  5386,  5386,  5388,  5395,  5402,  5421,
    5421,  5424,  5425,  5427,  5427,  5429,  5431,  5433,  5433,  5436,
    5438,  5446,  5446,  5451,  5458,  5460,  5469,  5475,  5475,  5478,
    5482,  5489,  5491,  5494,  5498,  5509,  5525,  5525,  5527,  5529,
    5531,  5531,  5533,  5535,  5550,  5550,  5552,  5554,  5563,  5565,
    5574,  5580,  5580,  5583,  5587,  5594,  5596,  5599,  5603,  5614,
    5631,  5631,  5633,  5635,  5637,  5637,  5639,  5641,  5656,  5656,
    5658,  5660,  5670,  5672,  5681,  5687,  5687,  5690,  5694,  5700,
    5702,  5704,  5704,  5714,  5722,  5722,  5724,  5726,  5728,  5731,
    5733,  5742,  5748,  5748,  5751,  5755,  5761,  5763,  5766,  5770,
    5781,  5797,  5797,  5799,  5801,  5803,  5803,  5805,  5808,  5820,
    5820,  5823,  5824,  5825,  5827,  5860,  5862,  5872,  5878,  5878,
    5881,  5885,  5891,  5893,  5896,  5900,  5911,  5924,  5924,  5926,
    5928,  5930,  5930,  5932,  5959,  5970,  5970,  5973,  5974,  5975,
    5977,  5977,  5980,  5982,  5991,  5997,  5997,  6000,  6004,  6010,
    6012,  6014,  6014,  6024,  6032,  6032,  6034,  6036,  6038,  6041,
    6044,  6062,  6062,  6073,  6080,  6090,  6098,  6104,  6106,  6120,
    6132,  6138,  6144,  6144,  6146,  6148,  6150,  6152,  6162,  6168,
    6174,  6174,  6176,  6178,  6180,  6182,  6182,  6187,  6192,  6204,
    6206,  6206,  6209,  6210,  6211,  6221,  6228,  6228,  6230,  6232,
    6250,  6261,  6272,  6294,  6305,  6316,  6327,  6371,  6382,  6404,
    6415,  6427,  6438,  6449,  6460,  6474,  6485,  6498,  6512,  6526,
    6538,  6550,  6570,  6590,  6600,  6630,  6640,  6651,  6663,  6677,
    6690,  6703,  6713,  6723,  6736,  6736,  6738,  6748,  6766,  6766,
    6768,  6775,  6784,  6784,  6786,  6793,  6802,  6802,  6804,  6811,
    6820,  6820,  6822,  6829,  6894,  6894,  6896,  6903,  6912,  6912,
    6914,  6921,  6930,  6930,  6932,  6939,  6948,  6948,  6950,  6959,
    6975,  6975,  6977,  6984,  6993,  6993,  6995,  7002,  7011,  7011,
    7013,  7020,  7029,  7029,  7031,  7038,  7047,  7047,  7049,  7056,
    7065,  7065,  7069,  7077,  7086,  7086,  7088,  7095,  7104,  7104,
    7106,  7113,  7265,  7266,  7267,  7268,  7269,  7270,  7271,  7272,
    7273,  7274,  7275,  7276,  7277,  7278,  7279,  7280,  7281,  7282,
    7283,  7284,  7285,  7286,  7287,  7288,  7290,  7291,  7292,  7296,
    7296,  7299,  7300,  7302,  7302,  7305,  7306,  7310,  7310,  7315,
    7315,  7320,  7320,  7325,  7325,  7330,  7330,  7335,  7335,  7340,
    7340,  7345,  7345,  7350,  7350,  7355,  7355,  7360,  7360,  7365,
    7365,  7370,  7372,  7378,  7385,  7385,  7391,  7391,  7403,  7403,
    7408,  7408,  7413,  7413,  7423,  7430,  7436,  7437,  7439,  7440,
    7443,  7447,  7451,  7455,  7454,  7475,  7474,  7481,  7482,  7484,
    7483,  7490,  7491,  7494,  7500,  7508,  7515,  7537,  7537,  7548,
    7548,  7551,  7551,  7565,  7566,  7569,  7569,  7582,  7583,  7586,
    7586,  7599,  7600,  7603,  7603,  7613,  7614,  7620,  7621,  7622,
    7623,  7624,  7625,  7626,  7627,  7628,  7629,  7630,  7631,  7632,
    7633,  7634,  7635,  7636,  7637,  7638,  7641,  7652,  7660,  7660,
    7663,  7664,  7667,  7668,  7670,  7682,  7696,  7701,  7708,  7709,
    7711,  7718,  7723,  7730,  7731,  7733,  7740,  7745,  7752,  7753,
    7755,  7762,  7764,  7770,  7772,  7774,  7780,  7782,  7784,  7790,
    7792,  7794,  7800,  7802,  7804,  7810,  7810,  7815,  7817,  7819,
    7825,  7825,  7830,  7832,  7843,  7845,  7850,  7850,  7852,  7854,
    7860,  7863,  7865,  7871,  7874,  7876,  7882,  7885,  7887,  7893,
    7897,  7896,  7908,  7908,  7915,  7917,  7923,  7925,  7927,  7933,
    7936,  7938,  7944,  8061,  8061,  8065,  8066,  8067,  8068,  8069,
    8070,  8071,  8072,  8073,  8077,  8081,  8090,  8091,  8093,  8100,
    8100,  8103,  8104,  8108,  8110,  8116,  8119,  8121,  8127,  8130,
    8130,  8140,  8141,  8147,  8149,  8155,  8158,  8160,  8166,  8169,
    8171,  8177,  8180,  8182,  8188,  8191,  8193,  8199
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "fileLicenceLaden", "osglNonNegativeIntArrayData", "osglIntArrayData",
  "osglIntVectorElArray", "osglIntVectorEl", "osglIntVectorElStart",
  "osglIntVectorElAttributes", "osglIntVectorElAttList",
  "osglIntVectorElAtt", "osglIntVectorElContent", "osglIntVectorBase64",
  "osglIntVectorBase64Content", "osglIntVectorBase64Empty",
  "osglIntVectorBase64Laden", "osglDblArrayData", "osglDblVectorElArray",
  "osglDblVectorEl", "osglDblVectorElStart", "osglDblVectorElAttributes",
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
  "matrixVarLaden", "$@1", "matrixOrBlockBody", "baseMatrix",
  "baseMatrixStart", "baseMatrixAttributes", "baseMatrixAttList",
  "baseMatrixAtt", "baseMatrixEnd", "matrixConstructorList",
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
  "varTypeAttEmpty", "varTypeAttContent", "nlnode", "E", "$@2", "eend",
  "PI", "$@3", "piend", "times", "$@4", "plus", "$@5", "minus", "$@6",
  "negate", "$@7", "divide", "$@8", "power", "$@9", "ln", "$@10", "sqrt",
  "$@11", "square", "$@12", "cos", "$@13", "sin", "$@14", "exp", "$@15",
  "abs", "absStart", "absEnd", "erf", "$@16", "if", "$@17",
  "matrixDeterminant", "$@18", "matrixTrace", "$@19", "matrixToScalar",
  "$@20", "number", "numberStart", "numberEnd", "numberAttributeList",
  "numberAttribute", "numberidATT", "$@21", "variable", "$@22",
  "variableend", "$@23", "anotherVariableATT", "variableATT",
  "variablecoefATT", "variableidxATT", "sum", "$@24", "anothersumnlnode",
  "allDiff", "$@25", "anotherallDiffnlnode", "max", "$@26",
  "anothermaxnlnode", "min", "$@27", "anotherminnlnode", "product", "$@28",
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
  "matrixTimesContent", "matrixProduct", "$@29",
  "anothermatrixproductnode", "matrixScalarTimes",
  "matrixScalarTimesStart", "matrixScalarTimesContent",
  "matrixSubMatrixAt", "matrixSubMatrixAtStart",
  "matrixSubMatrixAtContent", "matrixTranspose", "matrixTransposeStart",
  "matrixTransposeContent", "scalarNode", "OSnLCNode", "complexNumber",
  "complexNumberStart", "complexNumberEnd", "complexNumberAttributes",
  "complexNumberAttList", "complexNumberAtt", "createComplex",
  "createComplexStart", "createComplexContent", "complexPlus",
  "complexPlusStart", "complexPlusContent", "complexSum", "$@30",
  "anothercsumnode", "complexMinus", "complexMinusStart",
  "complexMinusContent", "complexNegate", "complexNegateStart",
  "complexNegateContent", "complexConjugate", "complexConjugateStart",
  "complexConjugateContent", "complexTimes", "complexTimesStart",
  "complexTimesContent", "complexSquare", "complexSquareStart",
  "complexSquareContent", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -2133

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-2133)))

#define YYTABLE_NINF -1206

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     395, -2133, -2133,   163,   -21,   161, -2133, -2133,   221,   -59,
   -2133,   419, -2133,   447, -2133, -2133, -2133, -2133,    18,   458,
   -2133, -2133, -2133, -2133, -2133,   -21, -2133, -2133, -2133, -2133,
   -2133,    -7,   466,    27, -2133, -2133, -2133, -2133,   204,   840,
     221, -2133,    30,   471,    56, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,    44,
      20, -2133, -2133,   209, -2133,   496, -2133,   525, -2133,   535,
   -2133,   540, -2133,   547, -2133,   571, -2133,   606, -2133,   334,
   -2133,   359, -2133, -2133,   361, -2133, -2133,   365, -2133, -2133,
     371, -2133, -2133,   377, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,    68,
     619,    66, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,    77,   414, -2133, -2133,   628, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133,   374, -2133,   334, -2133, -2133,
   -2133, -2133,   389, -2133,   409,   648,   209, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133,   141, -2133, -2133, -2133, -2133,
      17, -2133, -2133, -2133, -2133,    12, -2133, -2133, -2133, -2133,
      14, -2133, -2133, -2133, -2133,     4, -2133, -2133, -2133, -2133,
     124, -2133, -2133, -2133, -2133,   125, -2133, -2133, -2133, -2133,
   -2133,   660, -2133,   293,   298,   304,   302,   306, -2133, -2133,
   -2133,    45, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,   129,   589, -2133, -2133,   674, -2133,   690,
   -2133,   696, -2133,   700, -2133,   703, -2133,   334, -2133, -2133,
     132, -2133, -2133, -2133, -2133,   437,   224,   441,   224,   443,
     224,   451, -2133,   705, -2133,   473,    -5,   482,   486,   233,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133,   438, -2133, -2133,
     178, -2133, -2133,   186, -2133, -2133,   203, -2133, -2133,   184,
   -2133, -2133,   474, -2133, -2133,   455,   555,   -44, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133,   717,    96, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133,   247,   340, -2133, -2133,   720, -2133,   722, -2133,   730,
   -2133,   735, -2133,   755, -2133,   533, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,   374, -2133,   334, -2133, -2133,   147, -2133,
   -2133, -2133, -2133,   153, -2133, -2133, -2133, -2133,    98, -2133,
   -2133, -2133, -2133,   114, -2133, -2133, -2133, -2133,   131, -2133,
   -2133, -2133, -2133,   762, -2133, -2133, -2133,   478,   775, -2133,
   -2133,   569, -2133, -2133, -2133, -2133, -2133,   775, -2133, -2133,
   -2133, -2133,   775, -2133, -2133, -2133, -2133,   568, -2133,   -22,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133,   520,   501, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,   541,
     259, -2133, -2133,   -25, -2133, -2133, -2133, -2133, -2133,   595,
     603,   607, -2133, -2133, -2133, -2133, -2133, -2133, -2133,   135,
   -2133, -2133, -2133, -2133,   127, -2133, -2133, -2133, -2133,   138,
   -2133, -2133, -2133, -2133,   168, -2133, -2133, -2133, -2133,   145,
   -2133, -2133, -2133, -2133, -2133,   772, -2133,   608,   224,   626,
     224,   630,   224,   638, -2133,   778, -2133, -2133, -2133,   613,
   -2133, -2133,   621, -2133, -2133,   581, -2133, -2133,   577, -2133,
   -2133, -2133,   610, -2133,   -19, -2133, -2133, -2133, -2133, -2133,
     683, -2133,   710,   706, -2133,   718, -2133, -2133,   731, -2133,
   -2133,   709,   449, -2133, -2133, -2133, -2133, -2133,   787,   254,
   -2133, -2133, -2133,   800,   489, -2133, -2133,   460,   231, -2133,
   -2133,   820,   853,   857,   890, -2133, -2133,   707, -2133, -2133,
     810, -2133, -2133,   824, -2133, -2133,   877, -2133, -2133,   863,
     913,    82, -2133, -2133, -2133, -2133,   775, -2133, -2133, -2133,
   -2133,   775, -2133, -2133, -2133, -2133,   775, -2133, -2133, -2133,
   -2133,   915, -2133,   -18, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133,   855,   585, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,   802,   489,   839, -2133,
   -2133, -2133,   928, -2133, -2133, -2133, -2133, -2133,   590, -2133,
   -2133, -2133,   932, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,   906,   930,   387, -2133,   935,   937,   956,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,   872,   883,
   -2133, -2133,   892, -2133,   870, -2133,   904, -2133, -2133,   894,
   -2133, -2133,   934,   662, -2133, -2133, -2133, -2133,   806,   489,
     663, -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1000, -2133,
    1004, -2133,   808, -2133,   929, -2133,  1013,  1015, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
     322, -2133, -2133, -2133, -2133, -2133, -2133,   812,   489,   677,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1018,
     100, -2133, -2133, -2133, -2133, -2133,   965,   209, -2133, -2133,
    1022,   119, -2133, -2133,  1027, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133,   689, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,   987,   980, -2133, -2133,
   -2133,   747,   818,   823,   209, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133,   963, -2133,  1051, -2133, -2133,
   -2133, -2133,   826,   513, -2133,   761,  1042,   167, -2133, -2133,
   -2133, -2133,   225, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133,   260, -2133, -2133, -2133, -2133,  1061, -2133, -2133, -2133,
   -2133, -2133, -2133,   771,  1053, -2133,   828, -2133, -2133, -2133,
    1011, -2133, -2133,   991,   990, -2133, -2133, -2133, -2133,  1076,
   -2133,   999,   194, -2133, -2133, -2133, -2133,  1079, -2133,   804,
    1069, -2133,   831, -2133,  1086,   951, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,   833,   339, -2133,   939, -2133, -2133,  1090,
   -2133,  1031,  1092, -2133,   835, -2133,  1113,   978, -2133, -2133,
   -2133, -2133, -2133, -2133,   816,  1016,   917,  1039, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,  1055,  1109, -2133,   838,
   -2133,  1131,  1088, -2133, -2133, -2133, -2133, -2133, -2133,   836,
    1098,   944, -2133, -2133, -2133,  1100,   917,  1139,   850, -2133,
   -2133, -2133, -2133,   891, -2133,  1143,   867, -2133, -2133, -2133,
   -2133, -2133, -2133,   856,  1114,   953, -2133, -2133, -2133, -2133,
     893,  1155,   896, -2133, -2133, -2133,   898,   900, -2133,  1159,
     -70, -2133, -2133, -2133, -2133,  1161,   299, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133,  1141, -2133, -2133, -2133, -2133,   903,
    1165,   936, -2133,   827,   851, -2133, -2133, -2133, -2133,  1173,
     -80, -2133, -2133, -2133, -2133,   841,   851, -2133, -2133, -2133,
   -2133,   -48, -2133, -2133, -2133, -2133,  1177, -2133, -2133,  1035,
     881, -2133, -2133, -2133, -2133, -2133,  1117,  1122, -2133, -2133,
   -2133,   -23, -2133,   938, -2133,   859,   851, -2133, -2133, -2133,
   -2133,  1187,    -1, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133,  1149,   875, -2133,  1040,  1195, -2133, -2133,  1063,   909,
   -2133, -2133, -2133, -2133, -2133,  1169,   875, -2133, -2133, -2133,
    1107,   911, -2133, -2133, -2133, -2133, -2133,    51, -2133, -2133,
   -2133,   940,   483, -2133, -2133, -2133,  1240,  1111, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133,  1202,   875, -2133,  1242, -2133,
   -2133,  1200,   989, -2133, -2133,   942,   637, -2133, -2133,   955,
   -2133,  1040,  1246,   945, -2133, -2133, -2133, -2133,    74,   947,
     456, -2133,   955, -2133, -2133, -2133,    48,   775,  1269, -2133,
   -2133, -2133, -2133,   249, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1065,   949,   527,
   -2133,   955, -2133, -2133, -2133, -2133,    78,   -95, -2133, -2133,
   -2133, -2133,  1273, -2133,  1282, -2133,  1286, -2133,  1288, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,   973, -2133,  1040,   972,
    1289,  1157, -2133, -2133, -2133, -2133,   775, -2133, -2133, -2133,
   -2133,   -41, -2133, -2133, -2133, -2133, -2133,  1313, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
     973, -2133,    35, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
    1017,  1312, -2133, -2133,  1315, -2133,  1252,   358, -2133, -2133,
   -2133, -2133, -2133,  -152,  1318,   974, -2133,   -90, -2133, -2133,
   -2133, -2133, -2133,  1325, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,   973, -2133,   775, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,   993,  1028, -2133, -2133,
    1181, -2133, -2133,  1328,  1332,  1334,  1336, -2133,  1020, -2133,
    1040,   976,  1157, -2133, -2133, -2133, -2133,  1342,  1170, -2133,
    1260, -2133,  1094,  1110, -2133, -2133, -2133,  1072,  1119, -2133,
   -2133,  1266, -2133, -2133,  1411,  1020, -2133, -2133, -2133,  1116,
   -2133,  1419, -2133,  1274, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133,  1425, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
    1121,  1135, -2133, -2133,  1284, -2133, -2133,  1454,  1020, -2133,
    1167, -2133, -2133,    58, -2133,   979,   337,  1460, -2133, -2133,
   -2133, -2133,  1140, -2133,  1040,   981,  1157, -2133, -2133, -2133,
   -2133, -2133,  1151, -2133,  1464,   983, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,    71, -2133,   985,   337, -2133,  1140, -2133,
   -2133, -2133, -2133,  1093,   362,  1468,   -27, -2133, -2133,    91,
   -2133,  1095,   337, -2133,  1140, -2133, -2133,    36, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133,  1157, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,  1148, -2133,  1040,  1097,
    1157, -2133, -2133, -2133, -2133, -2133,  1153, -2133,  1476,    70,
   -2133, -2133, -2133, -2133,  1473,   551,    29, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133,  1157, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,  1148, -2133,   -76, -2133, -2133, -2133, -2133,
   -2133,  1483, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
      41, -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1157, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1148, -2133, -2133,
   -2133, -2133, -2133,  1185, -2133,  1338, -2133, -2133, -2133, -2133,
    1040,  1099,  1157, -2133, -2133, -2133, -2133, -2133,  1178, -2133,
    1492,  1343, -2133,  1496, -2133,  1495,  1497, -2133, -2133, -2133,
   -2133,  1197, -2133,  1355, -2133, -2133, -2133, -2133, -2133,  1163,
    1221,  1359, -2133, -2133, -2133,  1503,  1101,   264, -2133,  1213,
   -2133,  1361, -2133, -2133, -2133, -2133, -2133,  1103,  1157, -2133,
   -2133, -2133, -2133, -2133,  1186, -2133, -2133, -2133,  1367,  1508,
    1510, -2133, -2133, -2133, -2133, -2133,  1105,   337, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133,  1515,  1511,  1512, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
    1157, -2133, -2133, -2133, -2133, -2133,  1190, -2133, -2133,  1514,
    1516,  1157, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
    1278,  1517,  1520,  1521,  1522, -2133,  1196, -2133, -2133, -2133,
    1379, -2133, -2133,  1241, -2133, -2133, -2133,  1524,  1525, -2133,
   -2133, -2133, -2133,   493,  1341,   632, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
    1180, -2133,  1333,  1290, -2133, -2133, -2133,  1533,  1529,  1530,
    1531,  1532,  1534,  1535,  1536,  1537, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1538,   -29,
    1539,   -29,  1540,   -29,  1541,   -29,  1542,   -29,  1543,   -29,
    1544,   -29,  1545,   -29,  1546,   -29, -2133,  1555,  1548, -2133,
   -2133, -2133,  1552,  1550, -2133, -2133, -2133,  1556,  1557,  1558,
    1559,  1560,  1561,  1562,   775,  1267, -2133,  1566,  1563, -2133,
   -2133, -2133, -2133, -2133,  1267, -2133, -2133, -2133,  1267, -2133,
   -2133, -2133,  1267, -2133, -2133, -2133,  1267, -2133, -2133, -2133,
    1267, -2133, -2133, -2133,  1267, -2133, -2133, -2133,  1267, -2133,
   -2133, -2133,  1267, -2133, -2133, -2133,  1564,   504,  1567,  1296,
   -2133, -2133,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,
   -2133, -2133,    59,  1345,  1576,  1579,  1271, -2133,  1271, -2133,
    1271, -2133,  1271, -2133,  1271, -2133,  1271, -2133,  1271, -2133,
    1271, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133,  1265, -2133, -2133, -2133,  1340, -2133,  1353, -2133,
    1357, -2133,   504, -2133,   504, -2133,  1081, -2133,   504, -2133,
    1112, -2133,  1112, -2133,  1347, -2133,   504, -2133,   504, -2133,
     504, -2133,   504, -2133, -2133,   504, -2133,  1081, -2133,   504,
    1578, -2133,  1337,  1040, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,  1331,  1292,  1350,  1157, -2133, -2133, -2133,
   -2133, -2133,  1582,  1314,  1335,  1316,  1330,  1317,  1329,  1319,
    1339,  1321,  1344,  1322,  1348,  1323,  1346,  1324,  1349, -2133,
   -2133, -2133,    11,  1595,  1352,  1596,  1354,  1598,  1356,  1194,
   -2133,   504, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
    1168, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,  1081, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133,  1172, -2133,  1605,  1601, -2133,  1603, -2133,  1198, -2133,
   -2133,   504, -2133,  1191, -2133,   504, -2133,   504, -2133,   676,
   -2133,  1081, -2133,  1183, -2133, -2133, -2133, -2133,  1040,  1358,
   -2133, -2133, -2133, -2133,  1360,  1157, -2133, -2133, -2133, -2133,
   -2133, -2133,  1351, -2133, -2133, -2133,  1362, -2133, -2133, -2133,
    1364, -2133, -2133, -2133,  1366, -2133, -2133, -2133,  1368, -2133,
   -2133, -2133,  1370, -2133, -2133, -2133,  1372, -2133, -2133, -2133,
    1374, -2133, -2133, -2133,  1376, -2133,   452,  1179, -2133,  1609,
    1618, -2133, -2133, -2133, -2133,  1617,  1363, -2133, -2133,  1619,
    1365, -2133, -2133,  1621,  1327, -2133, -2133, -2133,  1214,  1081,
    1081,  1081,  1081,  1081,  1081, -2133, -2133,  1081,  1081,  1081,
    1081,  1081,  1081, -2133,  1081, -2133, -2133, -2133,  1378,  1380,
    1081,   504,   504,   504, -2133,  1239,     8, -2133,  1622,   504,
     504, -2133,  1208, -2133,  1205,  1204, -2133, -2133, -2133, -2133,
   -2133, -2133,  1623, -2133, -2133, -2133,  1203, -2133, -2133, -2133,
   -2133,  1624, -2133,  1626, -2133, -2133,  1627, -2133,  1628, -2133,
    1629, -2133,  1630, -2133,  1631,  1081, -2133,  1146,  1384, -2133,
    1157, -2133, -2133, -2133, -2133,  1487, -2133, -2133, -2133, -2133,
   -2133,  1369, -2133,  1157, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,  1157, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,  1637,  1639,  1640, -2133,
    1641, -2133,  1642, -2133, -2133,  1081,  1081,  1081,  1081,  1287,
    1276,   780,   834,  1280,  1279,  1081,  1270,  1277,  1268,    46,
    1272,   865,   902,   941,  1258, -2133, -2133,  1261, -2133, -2133,
    1081,  1254,  1250,  1253, -2133, -2133,  1263, -2133,  1662, -2133,
   -2133, -2133, -2133, -2133, -2133,  1249, -2133,  1251, -2133, -2133,
   -2133, -2133, -2133, -2133,  1387,  1171,  1081,   676,   676,   676,
     676,   676,   676,  1081, -2133, -2133, -2133, -2133, -2133,  1157,
   -2133, -2133, -2133, -2133, -2133,  1418,  1170, -2133,  1523, -2133,
    1392, -2133, -2133,  1394,  1395,  1526,   -35,   -15, -2133,  1397,
      -3,    16, -2133,  1528,  1399,  1671, -2133, -2133, -2133, -2133,
    1326,  1320,  1371,  1373, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133,  1081, -2133, -2133, -2133,  1050, -2133,  1672,  1674,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,  1281, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133,  1232, -2133, -2133,  1678,  1679, -2133, -2133, -2133,
    1081, -2133,   676, -2133,   676, -2133,  1243, -2133,  1244, -2133,
     676, -2133,  1233, -2133,   504,  1391,   214, -2133,  1437, -2133,
    1393, -2133, -2133,  1455, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,  1481, -2133, -2133, -2133,  1484, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1455,
   -2133, -2133, -2133, -2133, -2133, -2133,  1375, -2133, -2133,  1687,
     775, -2133,  1686,   643, -2133,   775,   775,  1234,  1245,  1255,
   -2133, -2133,  1237, -2133,  1262,  1278, -2133, -2133, -2133, -2133,
    1691,  1692, -2133, -2133, -2133, -2133, -2133, -2133,   123, -2133,
   -2133, -2133, -2133,  1690, -2133,  1486,    62,  1081, -2133, -2133,
   -2133, -2133,   121, -2133, -2133, -2133, -2133,    52,    60,  1693,
   -2133, -2133,  1377,  1695,  1697, -2133, -2133, -2133,  1698,  1699,
   -2133, -2133, -2133, -2133, -2133,  1459,  1703,  1704,  1553, -2133,
     775, -2133, -2133, -2133, -2133, -2133, -2133,  1705,  1706, -2133,
   -2133, -2133,  1565,  1577,  1710, -2133,  1709, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133,  1580, -2133, -2133, -2133, -2133, -2133,
   -2133,  1713, -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1711,
    1712, -2133,  1581,     3,  1715,   775, -2133, -2133,  1583,  1714,
   -2133,  1585, -2133, -2133, -2133, -2133, -2133, -2133,  1480,  1716,
    1717, -2133, -2133, -2133,  1718,  1721, -2133, -2133, -2133,   775,
    1722, -2133,  1728,  1442, -2133, -2133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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
     999,  1498,     0,  1534,     0,     0,    40,    41,    45,    44,
    1496,  1497,    43,  1532,  1533,     0,    68,    63,    65,    66,
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
    1538,     0,   169,   171,   170,  1536,  1537,     0,   174,   178,
     180,   179,     0,   183,   187,   189,   188,     0,   192,     0,
     204,   198,   201,   202,   999,   998,  1001,  1002,  1003,  1004,
    1000,  1499,  1535,    48,    55,     0,    51,    52,    57,    69,
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
    1539,   181,   190,   196,   205,   208,     0,   211,     0,    62,
      54,  1510,     0,    58,    60,    59,  1508,  1509,     0,   139,
     130,  1542,     0,   134,   137,   135,   136,  1540,  1541,   454,
     948,   457,   455,     0,     0,   460,   999,     0,     0,     0,
     325,   333,   341,   349,   357,   999,   371,   364,     0,   367,
     368,   372,     0,   394,     0,   403,     0,   412,   418,     0,
     424,   431,     0,   427,   428,   433,   283,   286,     0,   289,
       0,   218,   209,   213,   216,   214,   215,    61,     0,   138,
       0,   999,     0,   949,     0,   458,     0,     0,   999,   462,
     463,   464,   465,   989,  1453,  1459,  1464,   992,   366,   369,
       0,   393,   402,   411,   417,   426,   429,     0,   432,     0,
     296,   287,   291,   294,   292,   293,   217,  1511,  1543,     0,
       0,   953,   947,   950,   951,   471,   495,     0,   999,   999,
       0,     0,   381,  1490,     0,   373,   370,   378,   379,   376,
    1488,  1489,   377,   375,   374,     0,   439,   430,   434,   437,
     435,   436,   295,   999,   952,   959,     0,   955,   956,   961,
     497,   504,     0,     0,   472,   473,   477,   476,   475,   468,
     467,   999,   385,   384,   380,     0,   383,     0,   438,   990,
     954,   957,     0,   960,   506,   631,   507,     0,   501,   496,
     498,   499,     0,   481,   470,   478,   479,   474,   466,   382,
    1491,     0,   970,   958,   967,   968,     0,   962,   966,   964,
     965,   963,   633,   734,   634,   999,     0,   508,   503,   500,
       0,   480,   487,     0,   483,   484,   489,   969,   979,     0,
     978,     0,   972,   973,   975,   976,   977,     0,   736,   837,
     737,   999,     0,   635,     0,   514,   511,   505,   509,   510,
     502,   482,   485,     0,   488,   981,     0,   971,   974,     0,
     839,   909,   840,   999,     0,   738,     0,   641,   638,   632,
     636,   637,   999,   516,     0,   533,     0,     0,   494,   486,
     490,   492,   491,   980,  1456,   911,     0,     0,   999,     0,
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
    1092,     0,   670,   669,     0,     0,   647,   654,     0,   650,
     651,   655,   582,   580,   584,     0,   567,   566,   539,   546,
       0,   542,   543,   547,  1462,   522,   525,     0,   987,   917,
     920,     0,   923,   908,   845,   907,     0,   855,   852,   847,
     850,   851,   788,   786,   790,     0,   773,   772,     0,   750,
     757,     0,   753,   754,   758,     0,   686,   666,  1099,   672,
     671,     0,     0,     0,  1140,  1458,   649,   652,     0,     0,
     583,   563,   569,   568,   541,   544,     0,     0,     0,   529,
     526,   530,   531,     0,   934,   921,   931,   932,   925,   930,
     928,   929,   926,   927,   999,   857,   866,     0,     0,   789,
     769,   775,   774,  1452,   752,   755,     0,     0,   701,   684,
     698,   699,     0,  1526,     0,  1502,     0,  1514,     0,   688,
     690,   689,   697,   696,  1500,  1501,   693,   695,  1512,  1513,
     692,  1524,  1525,   694,   691,  1106,   674,   673,     0,     0,
       0,  1052,  1095,  1091,  1093,  1094,     0,   656,   653,   657,
     658,     0,   598,   581,   595,   596,  1550,     0,   585,   587,
     586,   594,   593,   590,   589,   591,   588,   592,  1548,  1549,
     571,   570,     0,   554,   548,   545,   551,   552,   549,   550,
       0,     0,   933,   943,     0,   942,     0,   936,   937,   939,
     940,   941,   984,     0,     0,     0,   858,     0,   804,   787,
     801,   802,  1494,     0,   791,   792,   793,   798,  1492,  1493,
     800,   799,   796,   795,   797,   794,   777,   776,     0,   759,
     756,   760,   761,   722,   708,   700,     0,   703,   705,   709,
     704,   719,   724,     0,     0,     0,     0,  1113,   676,   675,
       0,     0,  1052,  1102,  1098,  1100,  1101,     0,     0,  1097,
    1050,  1051,     0,     0,   619,   605,   597,     0,   600,   602,
     606,   601,   616,   621,     0,   573,   572,   556,   553,     0,
     532,     0,   945,     0,   935,   938,   854,   869,   853,   867,
     871,     0,   864,   861,   856,   859,   860,   825,   811,   803,
       0,   806,   808,   812,   807,   822,   827,     0,   779,   778,
       0,   702,   706,     0,   720,     0,   723,     0,  1527,  1503,
    1515,  1120,   678,   677,     0,     0,  1052,  1109,  1105,  1107,
    1108,  1104,     0,  1454,     0,     0,  1055,  1053,  1057,  1096,
     659,   599,   603,     0,   617,     0,   620,  1551,   575,   574,
     555,  1473,   944,     0,   870,     0,     0,   805,   809,     0,
     823,     0,   826,  1495,   781,   780,   762,     0,   716,   710,
     707,   713,   714,   711,   712,  1052,   731,   721,   729,   730,
     725,   726,   728,   727,  1455,  1127,   680,   679,     0,     0,
    1052,  1116,  1112,  1114,  1115,  1111,     0,  1103,     0,     0,
    1066,  1062,  1063,  1064,     0,  1056,     0,   613,   607,   604,
     610,   611,   608,   609,  1052,   628,   618,   626,   627,   622,
     623,   625,   624,   577,   576,     0,   885,   868,   882,   883,
    1506,     0,   872,   874,   873,   881,   880,   879,  1504,  1505,
     877,   876,   878,   875,  1457,   863,  1142,   862,   865,  1144,
       0,   819,   813,   810,   816,   817,   814,   815,  1052,   834,
     824,   832,   833,   828,   829,   831,   830,   783,   782,   995,
     996,   997,   715,     0,   718,     0,   733,  1134,   667,   681,
       0,     0,  1052,  1123,  1119,  1121,  1122,  1118,     0,  1110,
       0,     0,  1065,     0,  1054,     0,     0,  1058,  1060,  1059,
     612,     0,   615,     0,   630,   564,   578,   894,   884,     0,
     888,   887,   891,   896,   889,     0,     0,  1143,   818,     0,
     821,     0,   836,   770,   784,   717,   732,     0,  1052,  1130,
    1126,  1128,  1129,  1125,     0,  1117,  1465,  1067,     0,     0,
       0,   614,   629,   886,   890,   892,     0,   895,  1507,  1155,
    1154,  1141,  1152,  1153,  1530,     0,     0,     0,   999,  1145,
    1148,  1147,  1151,  1149,  1146,  1528,  1529,  1150,   820,   835,
    1052,  1137,  1133,  1135,  1136,  1132,     0,  1124,  1061,     0,
       0,  1052,   903,   893,   901,   902,   897,   898,   900,   899,
    1158,     0,     0,     0,     0,  1139,     0,  1131,  1474,  1476,
       0,   905,  1160,     0,  1175,  1162,  1531,     0,     0,   999,
    1138,   904,  1156,  1157,     0,  1161,  1451,  1460,  1475,  1415,
    1189,  1366,  1221,  1238,  1340,  1323,  1275,  1299,  1393,  1410,
    1176,  1177,  1191,  1180,  1223,  1183,  1240,  1184,  1277,  1185,
    1301,  1181,  1325,  1182,  1342,  1178,  1368,  1179,  1395,  1186,
    1411,  1187,     0,     0,  1174,  1159,  1486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1163,  1164,  1167,  1168,
    1169,  1170,  1165,  1166,  1172,  1171,  1484,  1485,     0,  1190,
       0,  1222,     0,  1239,     0,  1276,     0,  1300,     0,  1324,
       0,  1341,     0,  1367,     0,  1394,  1522,     0,     0,  1412,
    1520,  1521,     0,     0,  1416,  1173,   999,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1518,     0,     0,  1192,
    1193,  1194,  1516,  1517,     0,  1224,  1225,  1226,     0,  1241,
    1242,  1243,     0,  1278,  1279,  1280,     0,  1302,  1303,  1304,
       0,  1326,  1327,  1328,     0,  1343,  1344,  1345,     0,  1369,
    1370,  1371,     0,  1396,  1397,  1398,     0,     0,     0,     0,
    1414,  1487,     0,     0,     0,     0,     0,     0,     0,     0,
    1199,  1188,  1196,     0,     0,     0,  1205,  1220,  1205,  1237,
    1205,  1274,  1205,  1298,  1205,  1322,  1205,  1339,  1205,  1365,
    1205,  1392,  1523,  1697,  1702,  1707,  1712,  1715,  1724,  1729,
    1735,  1739,  1742,  1745,  1748,  1750,  1755,  1758,  1761,  1687,
    1718,  1721,     0,  1667,  1688,  1668,     0,  1669,     0,  1670,
       0,  1671,     0,  1672,     0,  1685,     0,  1673,     0,  1674,
    1725,  1675,  1730,  1676,     0,  1677,     0,  1678,     0,  1679,
       0,  1680,     0,  1681,  1682,     0,  1683,     0,  1684,     0,
       0,  1420,     0,     0,  1466,  1477,  1478,  1467,  1468,  1469,
    1470,  1483,  1207,     0,     0,     0,  1052,  1202,  1198,  1200,
    1201,  1519,     0,  1229,     0,  1246,     0,  1283,     0,  1307,
       0,  1331,     0,  1348,     0,  1374,     0,  1401,     0,  1752,
    1413,  1409,     0,     0,     0,     0,     0,     0,     0,     0,
    1711,     0,  1714,  1597,  1589,  1591,  1595,  1599,  1601,  1647,
    1663,  1609,  1593,  1616,  1603,  1605,  1607,  1635,  1612,  1614,
    1655,  1651,  1659,  1579,  1583,  1587,  1625,  1618,  1620,  1622,
       0,  1573,  1574,  1554,  1555,  1557,  1558,  1559,  1560,  1562,
    1563,  1564,  1566,  1565,  1567,  1569,     0,  1570,  1568,  1576,
    1577,  1578,  1552,  1628,  1553,  1556,  1575,  1571,  1572,  1561,
    1717,     0,  1720,     0,     0,  1726,     0,  1731,     0,  1736,
    1734,     0,  1738,     0,  1741,     0,  1744,     0,  1747,     0,
    1754,     0,  1757,     0,  1760,  1450,  1428,  1435,     0,     0,
    1421,  1195,  1214,  1197,     0,  1052,  1210,  1206,  1208,  1209,
    1204,  1049,     0,  1461,  1231,  1228,     0,  1227,  1248,  1245,
       0,  1244,  1285,  1282,     0,  1281,  1309,  1306,     0,  1305,
    1333,  1330,     0,  1329,  1350,  1347,     0,  1346,  1376,  1373,
       0,  1372,  1403,  1400,     0,  1399,     0,     0,  1692,     0,
       0,  1689,  1686,  1690,  1691,     0,     0,  1698,  1696,     0,
       0,  1703,  1701,     0,     0,  1708,  1706,  1713,     0,     0,
       0,     0,     0,     0,     0,  1649,  1665,     0,     0,     0,
       0,     0,     0,  1641,     0,  1657,  1653,  1661,     0,     0,
       0,     0,     0,     0,  1719,     0,     0,  1722,     0,     0,
       0,  1737,     0,  1743,     0,     0,  1800,  1794,  1797,  1775,
    1787,  1806,     0,  1803,  1784,  1763,     0,  1764,  1765,  1779,
    1766,     0,  1767,     0,  1768,  1769,     0,  1770,     0,  1771,
       0,  1772,     0,  1773,     0,     0,  1762,     0,     0,  1429,
    1052,  1424,  1419,  1422,  1423,  1070,  1217,  1213,  1215,  1216,
    1212,     0,  1203,  1052,  1234,  1230,  1232,  1233,  1254,  1251,
    1247,  1249,  1250,  1290,  1288,  1284,  1286,  1287,  1314,  1312,
    1308,  1310,  1311,  1052,  1336,  1332,  1334,  1335,  1355,  1353,
    1349,  1351,  1352,  1381,  1379,  1375,  1377,  1378,  1084,  1406,
    1402,  1404,  1405,  1751,  1753,  1693,     0,     0,     0,  1699,
       0,  1704,     0,  1709,  1716,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1581,  1580,     0,  1585,  1584,
       0,     0,     0,     0,  1613,  1611,     0,  1626,     0,  1630,
    1631,  1624,  1629,  1632,  1733,     0,  1723,     0,  1728,  1740,
    1746,  1749,  1789,  1756,     0,  1778,     0,     0,     0,     0,
       0,     0,     0,     0,  1418,  1438,  1417,  1436,  1440,  1052,
    1432,  1427,  1430,  1431,  1426,     0,     0,  1219,  1068,  1069,
       0,  1211,  1236,     0,     0,  1253,     0,     0,  1338,     0,
       0,     0,  1408,  1083,     0,     0,  1695,  1700,  1705,  1710,
       0,     0,     0,     0,  1600,  1602,  1648,  1650,  1664,  1666,
    1610,  1594,     0,  1604,  1606,  1608,     0,  1637,     0,     0,
    1636,  1642,  1643,  1644,  1615,  1656,  1658,  1652,  1654,  1660,
    1662,  1582,  1586,     0,  1619,  1621,  1623,  1627,  1633,  1727,
    1732,  1791,     0,  1776,  1774,     0,     0,  1782,  1781,  1780,
       0,  1783,     0,  1786,     0,  1793,     0,  1796,     0,  1799,
       0,  1802,     0,  1805,     0,     0,  1439,  1434,     0,  1425,
       0,  1073,  1071,  1074,  1218,  1235,  1252,  1257,  1255,  1259,
    1293,  1289,  1291,     0,  1317,  1313,  1315,     0,  1337,  1358,
    1354,  1356,  1359,  1384,  1380,  1382,  1385,  1087,  1085,  1088,
    1407,  1694,  1598,  1590,  1592,  1596,     0,  1638,  1639,     0,
       0,  1588,     0,     0,  1777,     0,     0,     0,     0,     0,
    1798,  1801,     0,  1807,     0,  1158,  1448,  1437,  1446,  1447,
       0,     0,  1441,  1442,  1443,  1444,  1445,  1433,     0,  1081,
    1077,  1078,  1079,     0,  1075,     0,  1258,     0,  1296,  1292,
    1294,  1295,     0,  1320,  1316,  1318,  1319,     0,     0,     0,
    1089,  1617,     0,     0,     0,  1634,  1790,  1792,     0,     0,
    1785,  1788,  1795,  1804,  1759,     0,     0,     0,     0,  1080,
       0,  1072,  1267,  1265,  1256,  1263,  1264,     0,     0,  1260,
    1261,  1262,     0,     0,     0,  1546,     0,  1360,  1357,  1363,
    1362,  1361,  1544,  1545,     0,  1391,  1386,  1383,  1389,  1388,
    1387,     0,  1086,  1640,  1646,  1645,  1482,  1481,  1449,     0,
       0,  1082,     0,     0,     0,     0,  1297,  1321,     0,     0,
    1390,     0,  1471,  1472,  1076,  1266,  1270,  1268,  1271,     0,
       0,  1364,  1547,  1090,     0,     0,  1272,  1463,  1480,     0,
       0,  1269,     0,     0,  1479,  1273
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1689, -2133,
    1719, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1677,
   -2133, -2133, -2133, -2133,  1584, -2133, -2133, -2133, -2133, -2133,
    1381, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,  1382, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1607,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
    1227, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,  1518, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133,  1160, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133,  1431, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133,  1106, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133,  1096, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,  1219, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,   994, -2133, -2133, -2133,
   -2133, -2133,   943, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,   770,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133,   721, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133,   485, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133,   480, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133,   736, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133,   519, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133,   518, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,   697,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,   459, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133,   457, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,   251,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,   776, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,   570, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133,  1019, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133,   946, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
     -79, -2133, -2133, -2133, -2133,  -549, -2133,  -368, -1266,  -198,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -1874, -1141, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,  -785,
   -2133, -2133, -2133, -2133, -2133,  -763, -2133, -2133, -2133, -2133,
   -2133,  -783, -2133, -2133, -2133, -2133, -2133, -1024, -2133, -2133,
   -2133, -2133, -2133, -1113, -2133, -2133, -2133, -2133, -2133, -1191,
   -2133, -2133, -2133, -2133, -2133, -1232, -2133, -2133, -2133, -2133,
   -2133, -1056, -1236, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133,  -650, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133,  -972, -2133, -2133,
   -2133, -2133, -2133, -1176, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133,   661, -2133, -1309,
   -1068,   727,   417,   708, -2133, -2133,  -814,  -805, -2133, -2133,
    -494, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -1000,  -674,
   -2133, -2132, -2133, -2133, -2133, -2133,  -673,  -672, -2133, -2133,
   -2133, -2133,  -721, -2133, -2133, -2133, -2133, -2133,  -141, -2133,
   -2133, -1054, -2133, -2133, -2133, -2133, -2133,  -518, -2133, -2133,
   -2133, -2133, -2133,  -796, -2133, -2133, -2133, -2133, -2133, -1036,
   -2133, -2133,  -579, -2133, -2133,  -689, -2133, -2133,  -218, -2133,
   -2133,  -592, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -1475, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -1811, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133,   -54, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -1853,  -663, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133, -2133,
   -2133, -2133, -2133, -2133
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
    1513,  1546,  1547,  1586,  1583,  1584,  1585,  1600,   991,  1045,
     876,   877,   903,   938,   939,   940,   986,   987,   988,   989,
    1041,  1042,  1098,  1095,  1096,  1097,  1196,  1197,  1198,  1199,
    1200,  1201,  1283,   622,   623,   672,   712,   713,   714,   746,
     747,   748,   749,   772,   773,   797,   793,   794,   795,   821,
     822,   823,   824,   825,   826,   846,   855,   880,   994,   833,
     202,   904,   807,   433,   673,   158,   466,   493,  1474,   255,
     256,   400,    10,    11,    22,    23,    24,    38,    39,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
    2000,  2001,  1260,  1337,  1338,  1404,  1405,  1497,  1494,  1261,
    1401,  1402,  1403,  2267,  2268,  2362,  2363,  2433,  2471,  2269,
    2430,  2431,  2432,  2282,  2283,  2388,  2389,  2449,  2502,  1013,
    1014,  1153,  1154,  1155,  1262,  1070,  1071,  1254,  1255,  1256,
    1332,  1147,  1148,  1328,  1329,  1330,  1396,  1249,  1250,  1392,
    1393,  1394,  1488,  1323,  1324,  1484,  1485,  1486,  1534,  1387,
    1388,  1530,  1531,  1532,  1576,  1479,  1480,  1572,  1573,  1574,
    1596,  1073,  1448,  1449,  1516,  1517,  1559,  1551,  1552,  1553,
    1590,  1603,  1604,  1605,  1614,  1615,  1666,  1655,  1613,  1630,
    1631,  1632,  1678,  1679,  1719,  1771,  1863,  1772,  1773,  1868,
    1869,  1870,  2002,  1864,  1865,  1997,  1998,  1999,  2141,  1993,
    1994,  2137,  2138,  2139,  2270,  1633,  1634,  1680,  1681,  1725,
    1777,  1874,  2005,  2006,  2145,  2146,  2147,  2273,  1635,  1636,
    1682,  1683,  1729,  1779,  1876,  2009,  2010,  2150,  2151,  2152,
    2274,  2275,  2368,  2369,  2435,  2436,  2479,  2474,  2475,  2476,
    2513,  2527,  2528,  2535,  2541,  1637,  1638,  1684,  1685,  1733,
    1781,  1878,  2013,  2014,  2155,  2156,  2157,  2276,  2372,  2373,
    2439,  2440,  2441,  1639,  1640,  1686,  1687,  1737,  1783,  1880,
    2017,  2018,  2160,  2161,  2162,  2277,  2376,  2377,  2444,  2445,
    2446,  1641,  1642,  1688,  1689,  1741,  1785,  1882,  2021,  2022,
    2165,  2166,  2167,  2279,  1643,  1644,  1690,  1691,  1745,  1787,
    1884,  2025,  2026,  2170,  2171,  2172,  2280,  2381,  2382,  2447,
    2487,  2488,  1645,  1646,  1692,  1693,  1749,  1789,  1886,  2029,
    2030,  2175,  2176,  2177,  2281,  2385,  2386,  2448,  2496,  2497,
    1647,  1648,  1694,  1695,  1753,  1791,  1888,  2033,  2034,  2180,
    2181,  2182,  2284,  1649,  1650,  1698,  1891,  1651,  1652,  1703,
    1760,  2256,  1852,  1853,  1989,  2132,  2133,  2134,  2265,  1987,
    1988,  2128,  2261,  2262,  2263,  2358,  2127,  2257,  2258,  2355,
    2356,  2422,  2417,  2418,  2419,  1704,  1560,   952,   434,  1074,
    1130,   798,  1206,   923,   435,  1561,  1720,   899,  2480,   436,
    1335,  1667,  1668,  1669,  1670,  1671,  2423,  2424,  1091,  1498,
    1562,  1499,  1672,  1673,  2536,  2481,  2337,  2338,  1674,  1675,
    1676,  1677,   729,   730,   731,  1217,  1218,  1219,   159,   160,
     161,  1133,  1134,  1135,  1437,  1438,  1439,   605,   606,   607,
    1137,  1138,  1139,  1721,  1722,  1723,  1699,  1700,  1701,  1140,
    1141,  1142,  1564,  1565,  1566,   162,   163,   164,   374,   375,
     376,   616,   617,   618,  2491,  2492,  2493,  1177,  1178,  1179,
    2105,  1931,  2078,  2216,  1932,  2079,  2219,  1933,  2080,  1934,
    2060,  1935,  2061,  1936,  2068,  1937,  2062,  1938,  2059,  1939,
    2063,  1940,  2064,  1941,  2070,  1942,  2071,  1943,  2072,  1944,
    2067,  1945,  1946,  2225,  1947,  2074,  1948,  2069,  1949,  2081,
    1950,  2082,  1951,  2083,  1952,  1953,  2231,  2086,  2232,  2233,
    2402,  1954,  2073,  2310,  2452,  2209,  2311,  2312,  2313,  1955,
    2065,  2201,  1956,  2076,  2212,  1957,  2075,  2211,  1958,  2077,
    2213,  1959,  2066,  2202,  1812,  1813,  1814,  1892,  2041,  2042,
    2043,  2044,  1815,  1816,  2048,  1894,  1817,  1818,  2052,  1896,
    1819,  1820,  2056,  1898,  1821,  1822,  1900,  1823,  1824,  1902,
    1825,  1826,  1960,  1827,  1828,  1962,  1829,  1830,  1964,  2236,
    1831,  1832,  1966,  2238,  1965,  1833,  1834,  1970,  1835,  1836,
    1972,  1837,  1838,  1974,  1839,  1840,  1976,  1841,  1842,  1978,
    1843,  1889,  2036,  1844,  1845,  1980,  1846,  1847,  1982,  1848,
    1849,  1984,  2106,  2107,  2108,  2109,  2334,  2244,  2245,  2339,
    2110,  2111,  2341,  2112,  2113,  2343,  2114,  2331,  2403,  2115,
    2116,  2345,  2117,  2118,  2347,  2119,  2120,  2349,  2121,  2122,
    2351,  2123,  2124,  2353
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     501,   733,   286,   395,   252,   666,   615,  1381,   277,   504,
    1259,  1899,  1169,  1901,   506,  1149,   271,  1961,   274,  2226,
    2227,   268,  2037,  2038,   417,  1971,  1172,  1973,   758,  1975,
     381,  1977,   386,  1469,  1979,  1470,  1471,  1420,  1983,  1277,
    1469,  1216,  1470,  1471,  1174,  1469,   509,  1470,  1471,   583,
     650,  1059,   799,  1464,   525,  1221,  1233,  2306,  2307,  1182,
    1183,  1297,  1087,  2484,  1028,   758,  1016,   705,   254,  1367,
    1368,  2494,  2495,  1223,  1491,  1507,   977,    49,  1159,   665,
     299,    50,  1406,  1407,    49,  1156,  1188,    51,    50,  1228,
    2058,   928,  1251,   126,    51,   127,  1043,   128,   300,   129,
       7,    52,  1450,  1451,   483,   373,   741,   380,    52,   385,
    1264,  1331,   301,   216,  2370,   217,  1231,    53,   486,  1445,
     302,  2140,   428,   130,    53,   762,   763,  2468,   280,   283,
     303,   538,   304,   218,  2374,  1286,   365,   489,   490,   535,
    1502,   704,   541,   219,   305,   265,  2379,   131,   306,   547,
     307,   477,   308,  2525,   309,   872,  1276,  1424,   364,   480,
    2092,   220,  1349,     6,  2094,  2383,  2095,   221,   756,  1716,
    1717,   808,   544,  1468,   744,   636,    12,  1718,   153,   154,
     740,  1027,   637,   745,  1520,  1395,   611,   612,   643,  1514,
    1287,  1506,   474,   645,  1325,  1365,   515,   478,   647,   548,
     484,   481,  1309,   266,   545,   756,   281,  1234,  1298,   491,
     487,  1057,  1446,   764,   542,   539,   601,   602,   520,   601,
     602,   536,  1017,   284,   366,  2184,   601,   602,  1492,   809,
     531,  2434,  2485,  2486,  1476,  1524,   978,    14,  1587,   601,
     602,   150,   601,   602,  2371,  2039,   601,   602,  1235,  1487,
     560,    17,   565,  1299,   570,   801,   476,  2450,  1029,   601,
     602,  1446,  1044,  1083,  2375,  1265,   550,  1508,  1389,  2272,
    2221,  2222,  2223,  1504,  1544,  1170,  2380,  2477,  2235,  2237,
    2308,  2469,  1088,  2526,  2309,  1088,  1433,  1495,  1496,  2335,
    2336,   403,  1088,  1112,   526,  2384,  1496,  1060,   418,  1181,
    1436,  2478,  1266,   429,   620,  1088,   430,    41,  1088,   431,
     525,   811,  1088,  1373,   812,  2490,  2498,  1522,  1441,  1192,
     510,  1100,   404,   584,   651,  1088,    80,   559,  1227,   564,
      30,   569,  1481,   721,   722,  1862,  1500, -1205,    54,  1472,
    1518,  1533,  1278,  1412,   817,   278,   118,   818,   819,   272,
     820,  1930,   269,   275,    55,   148,    56,   200,    57,  1456,
      58,    55,   310,    56,   203,    57,   204,    58,   984,   132,
     205,   985,  1981,   151,   152,   299,   206,  1143,   604,   153,
     154,   222,   207,   614,   153,   154,   208,  1575,   151,   152,
     238,  1175,   257,   300,  2342,  2344,  2346,  2348,  2350,  2352,
     370,   371,  1193,  1194,   676,  1195,   677,   301,     1,     2,
    1554,  1555,   258,   818,   819,   302,   820,   292,   151,   152,
    1224,   678,   601,   602,  1527,   303,   293,   304,   683,  1595,
      20,    21,   601,   602,   153,   154,   294,   687,   295,   305,
    1601,  2420,  2421,   306,   336,   307,   296,   308,   368,   309,
    1103,   126,   377,   127,   382,   128,   664,   129,    25,    26,
    1554,  1555,   387,   396,   397,   398,   399,  1556,  1557,    33,
      34,  2085,   734,   709,  1144,  2228,  2040,    44,    45,   394,
     720,   130,   121,   122,   723,   724,   151,   152,  1176,  2408,
     401,  2409,   153,   154,   402,  1558,  1072,  2412,   370,   371,
     409,   151,   152,   151,   152,   131,  2125,   165,   166,   153,
     154,  1193,  1194,   410,  1195,   611,   612,  1225,   703,  1092,
     759,   760,  1122,   411,  1102,   413,   151,   152,  1123,  1124,
     601,   602,   153,   154,  1125,  1126,   170,   171,   151,   152,
     611,   612,   412,  2414,  1990,   769,   175,   176,  1136,   732,
    2457,   180,   181,   415,  1430,  1431,   414,   739,   185,   186,
    1160,   416,  1173,   788,   437,  2096,   464,  2097,  1189,  2098,
     499,  2099,   502,  2100,   507,  2101,   757,  2102,   516,  2103,
    1204,  2104,   190,   191,  2195,  2196,  2197,  2198,  2199,  2200,
     404,  1222,  2203,  2204,  2205,  2206,  2207,  2208,  1232,  2210,
    1873,   418,  1875,   532,  1877,  2220,  1879,   834,  1881,   521,
    1883,   533,  1885,   757,  1887,   534,  1122,   195,   196,   556,
     151,   152,  1123,  1124,   601,   602,   153,   154,  1125,  1126,
     211,   212,   800,   856,   611,   612,   216,   561,   217,   240,
     241,   566,  1166,  1167,   796,   723,   724,   151,   152,   571,
    2253,   601,   602,   151,   152,   881,   218,   601,   602,   259,
     260,   611,   612,   578,   892,  1442,   219,   611,   612,   579,
     897,   287,   288,   581,   796,   723,   724,   151,   152,  2129,
     905,   601,   602,   580,   220,   338,   339,  1122,   582,   916,
     221,   151,   152,  1123,  1124,   601,   602,   153,   154,  1125,
    1126,   343,   344,   871,   935,   611,   612,   348,   349,  1212,
    1213,   353,   354,   945,   358,   359,   389,   390,   590,  1190,
    2290,  2291,  2292,  2293,  1383,   589,  2297,  2299,   423,   424,
    2302,   439,   440,   444,   445,   950,  2316,  2318,  2320,  1619,
    1793,   449,   450,   990,  1794,  2323,   454,   455,  1795,  1620,
     591,  1621,  1776,  1622,  1422,  1623,  1778,  1624,   592,  1625,
    1780,  1626,  1443,  1627,  1782,  1628,   459,   460,  1784,   593,
    1466,  2340,  1786,   494,   495,  1629,  1788,   594,  2354,   619,
    1790,   489,   490,   551,   552,  1038,  1495,  1496,  1263,   573,
     574,   510,  1793,   630,  1046,  1374,  1794,  1122,   598,   599,
    1795,   151,   152,  1123,  1124,   601,   602,   153,   154,  1125,
    1126,   608,   609,   660,   661,   611,   612,   699,   700,   710,
     711,  1127,  1128,   735,   736,  1413,   626,  2396,  1567,   777,
     778,  2398,  1656,  1657,   782,   783,  1440,   791,   792,   835,
     836,  1457,   857,   858,   867,   868,   882,   883,   921,   906,
     907,  1658,  1659,  1660,  1661,  1662,  1663,  1664,  1665,   627,
    1310,   930,   931,   628,  1796,  2407,  1797,  1726,  1798,  1730,
    1799,  1734,  1800,  1738,  1801,  1742,  1802,  1746,  1803,  1750,
    1804,  1754,  1805,  2183,  1806,  1727,  1807,  1731,  1808,  1735,
    1809,  1739,  1810,  1743,  1811,  1747,   629,  1751,   631,  1755,
     632,  1101,   936,   937,   954,   955,  1202,   960,   961,   966,
     967,   971,   972,   633,   996,   997,  1796,   634,  1797,   635,
    1798,   648,  1799,   656,  1800,  1132,  1801,   584,  1802,   667,
    1803,   668,  1804,   669,  1805,   670,  1806,   671,  1807,  1171,
    1808,   674,  1809,   684,  1810,   685,  1811,  1002,  1003,  1047,
    1048,  1093,  1094,  1117,  1118,  1589,  1151,  1152,  1161,  1162,
    1207,  1208,  2482,    81,   686,    82,    83,    84,  1220,    85,
      86,    87,   688,    88,    89,    90,   636,    91,    92,    93,
     692,    94,    95,  1252,  1253,  1292,  1293,  1326,  1327,  2264,
    1375,  1376,  1390,  1391,  1399,  1400,  1414,  1415,   694,  1563,
     691,  1903,   695,  1904,   651,  1905,   706,  1906,   707,  1907,
     693,  1908,   708,  1909,   715,  1910,   718,  1911,   719,  1912,
     742,  1913,  2278,  1914,   743,  1915,   750,  1916,   761,  1917,
     767,  1918,   768,  1919,  1903,  1920,  1904,  1921,  1905,  1922,
    1906,  1923,  1907,  1924,  1908,  1925,  1909,  1926,  1910,  1927,
    1911,  1928,  1912,  1929,  1913,   774,  1914,   789,  1915,   790,
    1916,   770,  1917,   745,  1918,   802,  1919,   805,  1920,   827,
    1921,   828,  1922,   840,  1923,   831,  1924,   841,  1925,   812,
    1926,   845,  1927,   847,  1928,   849,  1929,  2096,   850,  2097,
     853,  2098,   862,  2099,   873,  2100,   863,  2101,   874,  2102,
    2456,  2103,   875,  2104,  1425,  1426,  1458,  1459,  1482,  1483,
    1528,  1529,  1549,  1550,  1570,  1571,  1581,  1582,  2357,   887,
    2096,   878,  2097,   888,  2098,   893,  2099,   894,  2100,   900,
    2101,   897,  2102,   902,  2103,   901,  2104,   911,  1903,   912,
    1904,   917,  1905,   918,  1906,   924,  1907,   929,  1908,   941,
    1909,  2296,  1910,   942,  1911,   921,  1912,   946,  1913,   947,
    1914,   950,  1915,   959,  1916,   976,  1917,   983,  1918,  1007,
    1919,   992,  1920,  1001,  1921,  1382,  1922,  1010,  1923,  1015,
    1924,  1035,  1925,  1022,  1926,  1034,  1927,   978,  1928,  1039,
    1929,   984,  1903,  1058,  1904,  1067,  1905,  1068,  1906,  1072,
    1907,  1052,  1908,  1075,  1909,  1421,  1910,  2298,  1911,  1076,
    1912,  1017,  1913,  1435,  1914,  1081,  1915,  1029,  1916,  1084,
    1917,  1465,  1918,  1903,  1919,  1904,  1920,  1905,  1921,  1906,
    1922,  1907,  1923,  1908,  1924,  1909,  1925,  1910,  1926,  1911,
    1927,  1912,  1928,  1913,  1929,  1914,  1104,  1915,  1110,  1916,
    1113,  1917,  1114,  1918,  1150,  1919,  1105,  1920,  2315,  1921,
    1903,  1922,  1904,  1923,  1905,  1924,  1906,  1925,  1907,  1926,
    1908,  1927,  1909,  1928,  1910,  1929,  1911,  1191,  1912,  1145,
    1913,  1243,  1914,  1204,  1915,  1244,  1916,  1060,  1917,  1245,
    1918,  1246,  1919,  1247,  1920,  1257,  1921,  2317,  1922,  1903,
    1923,  1904,  1924,  1905,  1925,  1906,  1926,  1907,  1927,  1908,
    1928,  1909,  1929,  1910,  1258,  1911,  1274,  1912,  1281,  1913,
    1282,  1914,  1284,  1915,  1280,  1916,  1291,  1917,  1307,  1918,
    1234,  1919,  1233,  1920,  1317,  1921,  1311,  1922,  2319,  1923,
    1318,  1924,  1319,  1925,  1320,  1926,  1769,  1927,  1321,  1928,
    1333,  1929,  1653,  1654,  1696,  1697,  1866,  1867,  1968,  1969,
    1594,  1995,  1996,  2046,  2047,  2050,  2051,  2054,  2055,  2130,
    2131,  2135,  2136,  2143,  2144,  2148,  2149,  2153,  2154,  2158,
    2159,  2163,  2164,  2168,  2169,  2173,  2174,  2178,  2179,  2214,
    2215,  2217,  2218,  2254,  2255,  2259,  2260,  2229,  2332,  2333,
    2335,  2336,  2415,  2416,  2428,  2429,  1588,  1334,  1903,  1336,
    1904,  1618,  1905,  1340,  1906,  1341,  1907,  1264,  1908,  1347,
    1909,  1339,  1910,  1350,  1911,  1265,  1912,  1351,  1913,  1352,
    1914,  1355,  1915,  1298,  1916,  1297,  1917,  2397,  1918,  1903,
    1919,  1904,  1920,  1905,  1921,  1906,  1922,  1907,  1923,  1908,
    1924,  1909,  1925,  1910,  1926,  1911,  1927,  1912,  1928,  1913,
    1929,  1914,  1363,  1915,  1357,  1916,  1366,  1917,  1384,  1918,
    1385,  1919,  1398,  1920,  1397,  1921,  1444,  1922,  1489,  1923,
    1477,  1924,  1490,  1925,  1493,  1926,  1515,  1927,  1525,  1928,
    1526,  1929,  2437,  2438,  2230,  2442,  2443,  2472,  2473,  1535,
    1536,  1537,  1538,  1539,  1541,  1540,  1543,  1542,  1761,  1446,
    1507,  1548,  1568,  1569,  1579,  1577,  1580,  1578,  1591,  1592,
    1593,  1597,  1598,  1602,  1599,  1606,  1607,  1608,  1609,  1610,
    1612,  1611,  1616,  1617,  1705,  1702,  1706,  1707,  1708,  1709,
    1710,  1770,  1711,  1712,  1713,  1714,  1851,  1862,  1890,  1715,
    1724,  1728,  1732,  1736,  1740,  1744,  1748,  1752,  1756,  1757,
    1758,  1759,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1774,
    1992,  1775,  1792,  1850,  1893,  1963,  1854,  1855,  1856,  1857,
    1858,  1859,  1860,  1861,  1871,  1872,  1985,  1895,  1991,  1986,
    2003,  1897,  2004,  2011,  2008,  2012,  2007,  2016,  2015,  2020,
    2024,  2028,  2032,  2045,  2049,  2031,  2053,  2057,  2088,  2084,
    2019,  2023,  2089,  2027,  2090,  2087,  2093,  2186,  2185,  2091,
    2126,  2187,  2035,  2188,  2193,  2190,  2142,  2192,  2224,  2194,
    2234,  2239,  2240,  2241,  2242,  2246,  2243,  2247,  2248,  2249,
    2250,  2251,  2252,  2285,  2266,  2295,  2271,  2286,  2287,  2288,
    2289,  2303,  2189,  2305,  2294,  2300,  2301,  2321,  2191,  2325,
    2304,  2324,  2322,  2314,  2326,  2328,  2329,  2426,  2327,  2359,
    2330,  2364,  2361,  2365,  2366,  2367,  2378,  2387,  2390,  2391,
    2399,  2393,  2400,  2404,  2401,  2392,  2405,  2406,  2413,  2411,
    2427,  1496,  2410,  2453,  2455,  2460,  2463,  2464,  2461,  2466,
    2467,  2470,  2462,  2504,  2501,  2505,  2506,  2507,  2508,  2509,
    2510,  2511,  2519,  2514,  2515,  2516,  2518,  2521,  2534,  2522,
    2523,  2529,  2532,  2545,  2537,  2538,  2539,  2517,  2543,   117,
    2520,  2524,  2540,  2531,  2394,  2533,  2544,   149,  2395,   595,
     264,   239,   337,   438,    40,   689,   657,   621,   787,   696,
    1036,  1344,  1085,  1342,  2451,  1077,  1312,   842,  1314,  1115,
    1358,  1360,  1545,  1040,  2503,  2465,   771,  1285,   848,  1099,
    1215,  1434,  2360,  2489,  1131,  2499,  2500,  2425,  1967,  2483,
       0,     0,     0,     0,     0,     0,     0,   517,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   522,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,  2454,     0,     0,     0,     0,  2458,  2459,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2512,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2530,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2542
};

static const yytype_int16 yycheck[] =
{
     368,   690,   200,     8,   145,   597,   524,  1316,     4,   377,
    1151,  1822,  1080,  1824,   382,  1071,     4,  1828,     4,    11,
      12,     4,    11,    12,    68,  1836,  1080,  1838,   717,  1840,
     248,  1842,   250,     4,  1845,     6,     7,  1346,  1849,     4,
       4,  1109,     6,     7,  1080,     4,    68,     6,     7,    68,
      68,    52,   773,  1362,    79,  1109,   151,    11,    12,    11,
      12,   151,    11,    11,   112,   754,   146,   659,   147,    11,
      12,    11,    12,  1109,     4,   151,   146,    57,  1078,   597,
      35,    61,    11,    12,    57,    11,  1086,    67,    61,    11,
    1901,   896,  1148,    37,    67,    39,   119,    41,    53,    43,
     121,    81,    11,    12,     6,   246,   698,   248,    81,   250,
     151,  1252,    67,    47,   149,    49,  1116,    97,     4,   146,
      75,  1995,    26,    67,    97,     6,     7,     4,     4,     4,
      85,     4,    87,    67,   149,   287,     4,     6,     7,     4,
    1406,   659,     4,    77,    99,     4,   149,    91,   103,     4,
     105,     4,   107,   150,   109,   844,  1180,  1348,   237,     6,
    1971,    95,  1275,     0,  1975,   149,  1977,   101,   717,   198,
     199,     4,     4,  1364,    74,    93,    15,   206,   170,   171,
     698,   966,   100,    83,  1450,  1326,   178,   179,   556,  1425,
     342,  1423,   333,   561,  1250,  1308,   394,    50,   566,    54,
     102,    48,  1226,    62,    36,   754,    82,   302,   298,    78,
      96,   996,   288,    94,    76,    88,   168,   169,   416,   168,
     169,    86,   302,    98,    92,  2036,   168,   169,   158,    62,
     428,  2363,   180,   181,  1375,  1467,   306,    16,  1547,   168,
     169,    32,   168,   169,   279,   234,   168,   169,   343,  1390,
     468,   310,   470,   343,   472,   773,   335,  2389,   306,   168,
     169,   288,   285,  1026,   279,   306,   464,   343,  1324,  2143,
    2081,  2082,  2083,  1414,  1510,  1080,   279,   215,  2089,  2090,
     234,   158,   234,   280,   238,   234,  1354,   235,   236,   229,
     230,    58,   234,  1056,   319,   279,   236,   298,   342,  1082,
    1354,   239,   343,   207,    73,   234,   210,   314,   234,   213,
      79,    86,   234,  1313,    89,  2447,  2448,  1458,  1354,    70,
     342,  1042,    89,   342,   342,   234,   122,   468,  1111,   470,
     312,   472,  1388,    11,    12,   276,   307,   278,   311,   303,
     299,  1482,   307,  1343,    84,   341,   316,   153,   154,   337,
     156,  1826,   335,   339,   334,   311,   336,    23,   338,  1359,
     340,   334,   317,   336,     5,   338,     5,   340,    69,   313,
       5,    72,  1847,   164,   165,    35,     5,  1066,   519,   170,
     171,   315,     5,   524,   170,   171,   318,  1528,   164,   165,
     313,  1080,     3,    53,  2247,  2248,  2249,  2250,  2251,  2252,
     176,   177,   153,   154,    17,   156,    19,    67,    13,    14,
     196,   197,     3,   153,   154,    75,   156,   124,   164,   165,
    1109,    34,   168,   169,  1480,    85,   128,    87,   626,  1570,
      11,    12,   168,   169,   170,   171,   132,   635,   136,    99,
    1581,   227,   228,   103,   315,   105,   140,   107,    11,   109,
    1042,    37,    11,    39,    11,    41,   597,    43,    11,    12,
     196,   197,    11,   468,   469,   470,   471,   203,   204,    11,
      12,  1946,   690,   671,  1066,   467,   465,    11,    12,     6,
     678,    67,    11,    12,   162,   163,   164,   165,  1080,  2342,
       8,  2344,   170,   171,     8,   231,   159,  2350,   176,   177,
      62,   164,   165,   164,   165,    91,  1981,    11,    12,   170,
     171,   153,   154,   335,   156,   178,   179,  1109,   659,  1037,
     718,   719,   160,   337,  1042,   341,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    11,    12,   164,   165,
     178,   179,   339,  2354,  1853,   743,    11,    12,  1066,   690,
    2403,    11,    12,    98,   192,   193,    82,   698,    11,    12,
    1078,     6,  1080,   761,   317,   444,    33,   446,  1086,   448,
      92,   450,     3,   452,     6,   454,   717,   456,    58,   458,
     218,   460,    11,    12,  2059,  2060,  2061,  2062,  2063,  2064,
      89,  1109,  2067,  2068,  2069,  2070,  2071,  2072,  1116,  2074,
    1776,   342,  1778,     8,  1780,  2080,  1782,   805,  1784,    68,
    1786,     8,  1788,   754,  1790,     8,   160,    11,    12,    11,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      11,    12,   773,   831,   178,   179,    47,    11,    49,    11,
      12,    11,   186,   187,   161,   162,   163,   164,   165,    11,
    2125,   168,   169,   164,   165,   853,    67,   168,   169,    11,
      12,   178,   179,    50,   862,  1354,    77,   178,   179,    48,
     214,    11,    12,    96,   161,   162,   163,   164,   165,  1988,
     878,   168,   169,   102,    95,    11,    12,   160,    78,   887,
     101,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    11,    12,   844,   902,   178,   179,    11,    12,   182,
     183,    11,    12,   911,    11,    12,    11,    12,     8,  1087,
    2195,  2196,  2197,  2198,  1316,    42,  2201,  2202,    11,    12,
    2205,    11,    12,    11,    12,   208,  2211,  2212,  2213,   246,
     288,    11,    12,   941,   292,  2220,    11,    12,   296,   256,
      44,   258,  1724,   260,  1346,   262,  1728,   264,    40,   266,
    1732,   268,  1354,   270,  1736,   272,    11,    12,  1740,    38,
    1362,  2246,  1744,    11,    12,   282,  1748,    68,  2253,   319,
    1752,     6,     7,    11,    12,   983,   235,   236,  1156,    11,
      12,   342,   288,    86,   992,  1313,   292,   160,    11,    12,
     296,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    11,    12,    11,    12,   178,   179,    11,    12,    11,
      12,   184,   185,    11,    12,  1343,     6,  2302,  1517,    11,
      12,  2306,   200,   201,    11,    12,  1354,    11,    12,    11,
      12,  1359,    11,    12,    11,    12,    11,    12,   211,    11,
      12,   219,   220,   221,   222,   223,   224,   225,   226,     6,
    1228,    11,    12,     6,   412,  2340,   414,  1681,   416,  1683,
     418,  1685,   420,  1687,   422,  1689,   424,  1691,   426,  1693,
     428,  1695,   430,   431,   432,  1681,   434,  1683,   436,  1685,
     438,  1687,   440,  1689,   442,  1691,     6,  1693,    88,  1695,
      76,  1042,    11,    12,    11,    12,  1104,    11,    12,    11,
      12,    11,    12,    36,    11,    12,   412,    54,   414,     6,
     416,     6,   418,    68,   420,  1066,   422,   342,   424,    90,
     426,     3,   428,   343,   430,     3,   432,    31,   434,  1080,
     436,    11,   438,     8,   440,     8,   442,    11,    12,    11,
      12,    11,    12,    11,    12,  1547,    11,    12,    11,    12,
      11,    12,  2437,   123,     8,   125,   126,   127,  1109,   129,
     130,   131,   100,   133,   134,   135,    93,   137,   138,   139,
     110,   141,   142,    11,    12,    11,    12,    11,    12,  2130,
      11,    12,    11,    12,    11,    12,    11,    12,   104,  1517,
     108,   358,    68,   360,   342,   362,   343,   364,     8,   366,
     106,   368,     8,   370,    85,   372,     3,   374,     3,   376,
     343,   378,  2163,   380,     6,   382,    61,   384,     6,   386,
       3,   388,   343,   390,   358,   392,   360,   394,   362,   396,
     364,   398,   366,   400,   368,   402,   370,   404,   372,   406,
     374,   408,   376,   410,   378,   308,   380,    94,   382,     8,
     384,    74,   386,    83,   388,   304,   390,    25,   392,     8,
     394,   300,   396,    62,   398,    22,   400,    86,   402,    89,
     404,     5,   406,    84,   408,     6,   410,   444,   284,   446,
      21,   448,     6,   450,   155,   452,   145,   454,     8,   456,
     457,   458,    71,   460,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,  2259,     6,
     444,    29,   446,   145,   448,   309,   450,   111,   452,    90,
     454,   214,   456,    24,   458,    80,   460,     6,   358,    51,
     360,   305,   362,    45,   364,    45,   366,     8,   368,     6,
     370,   371,   372,   286,   374,   211,   376,   301,   378,    45,
     380,   208,   382,     8,   384,     6,   386,     6,   388,   342,
     390,    30,   392,     8,   394,  1316,   396,   326,   398,     6,
     400,   146,   402,   342,   404,     8,   406,   306,   408,    72,
     410,    69,   358,     6,   360,    46,   362,   322,   364,   159,
     366,   342,   368,     8,   370,  1346,   372,   373,   374,   146,
     376,   302,   378,  1354,   380,    46,   382,   306,   384,   112,
     386,  1362,   388,   358,   390,   360,   392,   362,   394,   364,
     396,   366,   398,   368,   400,   370,   402,   372,   404,   374,
     406,   376,   408,   378,   410,   380,     6,   382,    46,   384,
       8,   386,    52,   388,     8,   390,   145,   392,   393,   394,
     358,   396,   360,   398,   362,   400,   364,   402,   366,   404,
     368,   406,   370,   408,   372,   410,   374,     8,   376,   324,
     378,     8,   380,   218,   382,     3,   384,   298,   386,     3,
     388,     3,   390,   320,   392,     6,   394,   395,   396,   358,
     398,   360,   400,   362,   402,   364,   404,   366,   406,   368,
     408,   370,   410,   372,   157,   374,     3,   376,     6,   378,
       5,   380,    70,   382,   307,   384,     8,   386,     3,   388,
     302,   390,   151,   392,     6,   394,   343,   396,   397,   398,
       8,   400,     8,   402,     8,   404,  1714,   406,   328,   408,
       8,   410,    11,    12,   174,   175,    11,    12,    11,    12,
    1558,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,   247,   248,    11,    12,  2086,    11,    12,
     229,   230,    11,    12,    11,    12,  1547,   237,   358,   149,
     360,  1609,   362,   303,   364,   343,   366,   151,   368,     8,
     370,   327,   372,   307,   374,   306,   376,     8,   378,   155,
     380,     6,   382,   298,   384,   151,   386,   387,   388,   358,
     390,   360,   392,   362,   394,   364,   396,   366,   398,   368,
     400,   370,   402,   372,   404,   374,   406,   376,   408,   378,
     410,   380,     8,   382,   343,   384,   299,   386,     8,   388,
     330,   390,     8,   392,   323,   394,     8,   396,   325,   398,
     332,   400,     6,   402,    11,   404,     3,   406,   303,   408,
     152,   410,    11,    12,  2086,    11,    12,    11,    12,   321,
       8,   158,     6,     8,   307,     8,   343,   152,  1706,   288,
     151,     8,   299,   152,     6,   329,     6,   150,     3,     8,
       8,   331,     8,   245,     8,     8,     6,     6,     6,   333,
     289,   152,     8,     8,   244,   202,     3,     8,     8,     8,
       8,   274,     8,     8,     8,     8,   250,   276,   283,    11,
      11,    11,    11,    11,    11,    11,    11,    11,     3,    11,
       8,    11,     6,     6,     6,     6,     6,     6,     6,     3,
     278,     8,     8,     6,   234,   463,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     6,     8,   234,   257,   252,
       8,   234,   278,   263,   278,   278,   261,   278,   269,   278,
     278,   278,   278,     8,     8,   259,     8,   413,     3,   441,
     271,   267,    11,   265,    11,   443,   425,     8,   439,   421,
     437,     3,   273,     6,   297,     6,   275,     6,   389,   415,
       8,   423,   427,   429,    11,    11,   433,    11,    11,    11,
      11,    11,    11,     6,   157,   369,   277,     8,     8,     8,
       8,   381,   289,   385,   367,   375,   377,   399,   293,   409,
     383,   407,   401,   391,   411,     3,   417,  2356,   405,   251,
     419,   279,   149,   279,   279,   149,   279,   149,   279,     8,
       8,   361,     8,   451,   403,   359,     8,     8,   455,   445,
     253,   236,   449,     6,     8,   461,   459,   435,   453,     8,
       8,    11,   447,     8,    11,     8,     8,     8,   249,     6,
       6,   158,     3,     8,     8,   150,     6,     4,   238,     8,
       8,     6,     8,   281,     8,     8,     8,   150,     6,    40,
     150,   150,    11,   150,   363,   150,     8,    60,   365,   512,
     156,   134,   224,   312,    25,   639,   586,   528,   754,   653,
     980,  1271,  1031,  1268,   379,  1019,  1237,   814,  1240,  1062,
    1301,  1304,  1511,   987,   387,  2415,   747,  1197,   822,  1042,
    1109,  1354,  2266,  2447,  1066,  2448,  2448,  2356,  1832,  2442,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,  2400,    -1,    -1,    -1,    -1,  2405,  2406,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2515,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2539
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
      32,   164,   165,   170,   171,   494,   495,   496,  1107,  1470,
    1471,  1472,  1497,  1498,  1499,    11,    12,   510,   511,   512,
      11,    12,   516,   517,   518,    11,    12,   522,   523,   524,
      11,    12,   528,   529,   530,    11,    12,   534,   535,   536,
      11,    12,   540,   541,   542,    11,    12,   546,   547,   548,
      23,   552,  1102,     5,     5,     5,     5,     5,   318,   765,
     766,    11,    12,   672,   673,   674,    47,    49,    67,    77,
      95,   101,   315,   623,   624,   625,   626,   627,   632,   633,
     638,   639,   644,   645,   650,   651,   656,   657,   313,   571,
      11,    12,   574,   575,   576,   580,   581,   587,   588,   594,
     595,   601,  1470,   606,  1102,  1111,  1112,     3,     3,    11,
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
     176,   177,   582,  1470,  1500,  1501,  1502,    11,   590,   589,
    1470,  1500,    11,   597,   596,  1470,  1500,    11,   602,    11,
      12,   607,   608,   609,     6,     8,   468,   469,   470,   471,
    1113,     8,     8,    58,    89,   500,   501,   502,   503,    62,
     335,   337,   339,   341,    82,    98,     6,    68,   342,   556,
     557,   558,   559,    11,    12,   770,   771,   772,    26,   207,
     210,   213,   769,  1105,  1430,  1436,  1441,   317,   677,    11,
      12,   680,   681,   682,    11,    12,   686,   687,   688,    11,
      12,   692,   693,   694,    11,    12,   698,   699,   700,    11,
      12,   704,   705,   706,    33,   710,  1108,   727,   728,   734,
     735,   741,   742,   748,  1470,   753,  1102,     4,    50,   631,
       6,    48,   637,     6,   102,   643,     4,    96,   649,     6,
       7,    78,   655,  1109,    11,    12,   659,   660,   661,    92,
     584,  1109,     3,   591,  1109,   598,  1109,     6,   603,    68,
     342,   610,   611,   612,   613,  1111,    58,   502,   504,   505,
    1111,    68,   558,   560,   561,    79,   319,   773,   774,   775,
     776,  1111,     8,     8,     8,     4,    86,   683,     4,    88,
     689,     4,    76,   695,     4,    36,   701,     4,    54,   707,
    1111,    11,    12,   711,   712,   713,    11,   730,   729,  1470,
    1500,    11,   737,   736,  1470,  1500,    11,   744,   743,  1470,
    1500,    11,   749,    11,    12,   754,   755,   756,    50,    48,
     102,    96,    78,    68,   342,   662,   663,   664,   665,    42,
       8,    44,    40,    38,    68,   612,   614,   615,    11,    12,
     507,   168,   169,   506,  1470,  1479,  1480,  1481,    11,    12,
     563,   178,   179,   562,  1470,  1479,  1503,  1504,  1505,   319,
      73,   775,  1075,  1076,   777,   778,     6,     6,     6,     6,
      86,    88,    76,    36,    54,     6,    93,   100,   714,   715,
     716,   717,   731,  1109,   738,  1109,   745,  1109,     6,   750,
      68,   342,   757,   758,   759,   760,    68,   664,   666,   667,
      11,    12,   617,   616,  1470,  1479,  1503,    90,     3,   343,
       3,    31,  1077,  1106,    11,   783,    17,    19,    34,   779,
     780,   781,   782,  1111,     8,     8,     8,  1111,   100,   716,
     718,   108,   110,   106,   104,    68,   759,   761,   762,    11,
      12,   669,   668,  1470,  1479,  1503,   343,     8,     8,  1111,
      11,    12,  1078,  1079,  1080,    85,   784,   785,     3,     3,
    1111,    11,    12,   162,   163,   719,   720,   721,   722,  1464,
    1465,  1466,  1470,  1497,  1500,    11,    12,   764,   763,  1470,
    1479,  1503,   343,     6,    74,    83,  1081,  1082,  1083,  1084,
      61,   800,   801,   786,   787,   788,  1107,  1470,  1497,  1111,
    1111,     6,     6,     7,    94,   723,   724,     3,   343,  1111,
      74,  1083,  1085,  1086,   308,   806,   807,    11,    12,   802,
     803,   804,    11,    12,   789,   790,   791,   788,  1111,    94,
       8,    11,    12,  1088,  1089,  1090,   161,  1087,  1433,  1464,
    1470,  1479,   304,   884,   885,    25,   808,  1104,     4,    62,
     805,    86,    89,   792,   793,   794,   795,    84,   153,   154,
     156,  1091,  1092,  1093,  1094,  1095,  1096,     8,   300,   946,
     947,    22,   886,  1101,  1111,    11,    12,   809,   810,   811,
      62,    86,   794,   796,   797,     5,  1097,    84,  1093,     6,
     284,  1008,  1009,    21,   948,  1098,  1111,    11,    12,   887,
     888,   889,     6,   145,   812,   813,   814,    11,    12,   799,
     798,  1470,  1497,   155,     8,    71,  1052,  1053,    29,  1010,
    1099,  1111,    11,    12,   949,   950,   951,     6,   145,   890,
     891,   892,  1111,   309,   111,   826,   827,   214,   815,  1439,
      90,    80,    24,  1054,  1103,  1111,    11,    12,  1011,  1012,
    1013,     6,    51,   952,   953,   954,  1111,   305,    45,   904,
     905,   211,   893,  1435,    45,   842,   843,   828,  1439,     8,
      11,    12,   816,   817,   818,  1111,    11,    12,  1055,  1056,
    1057,     6,   286,  1014,  1015,  1111,   301,    45,   966,   967,
     208,   955,  1429,   917,    11,    12,   906,   907,   908,     8,
      11,    12,   894,   895,   896,   855,    11,    12,   844,   845,
     846,    11,    12,   829,   830,   831,     6,   146,   306,   819,
     820,   821,   822,     6,    69,    72,  1058,  1059,  1060,  1061,
    1111,  1050,    30,  1016,  1100,   979,    11,    12,   968,   969,
     970,     8,    11,    12,   956,   957,   958,   342,   918,   919,
     326,   909,   910,  1171,  1172,     6,   146,   302,   897,   898,
     899,   900,   342,   856,   857,   847,   848,  1171,   112,   306,
     832,   833,   834,   835,     8,   146,   821,   823,  1111,    72,
    1060,  1062,  1063,   119,   285,  1051,  1111,    11,    12,  1017,
    1018,  1019,   342,   980,   981,   971,   972,  1171,     6,    52,
     298,   959,   960,   961,   962,   920,   921,    46,   322,   911,
    1177,  1178,   159,  1213,  1431,     8,   146,   899,   901,   858,
     859,    46,   849,  1177,   112,   834,   836,    11,   234,   824,
     825,  1450,  1479,    11,    12,  1065,  1066,  1067,  1064,  1433,
    1464,  1470,  1479,  1503,     6,   145,  1021,  1022,   982,   983,
      46,   973,  1177,     8,    52,   961,   963,    11,    12,   923,
     924,   925,   160,   166,   167,   172,   173,   184,   185,   922,
    1432,  1435,  1470,  1473,  1474,  1475,  1479,  1482,  1483,  1484,
    1491,  1492,  1493,  1497,  1503,   324,   912,  1183,  1184,  1213,
       8,    11,    12,  1173,  1174,  1175,    11,   902,   903,  1450,
    1479,    11,    12,   861,   862,   863,   186,   187,   860,  1432,
    1439,  1470,  1473,  1479,  1491,  1497,  1503,  1509,  1510,  1511,
     850,  1183,    11,    12,   837,   838,   839,   840,  1450,  1479,
    1109,     8,    70,   153,   154,   156,  1068,  1069,  1070,  1071,
    1072,  1073,  1111,  1029,   218,  1023,  1434,    11,    12,   985,
     986,   987,   182,   183,   984,  1429,  1432,  1467,  1468,  1469,
    1470,  1473,  1479,  1491,  1497,  1503,   974,  1183,    11,   964,
     965,  1450,  1479,   151,   302,   343,   926,   927,   928,   929,
     936,   937,   938,     8,     3,     3,     3,   320,   913,  1189,
    1190,  1213,    11,    12,  1179,  1180,  1181,     6,   157,  1143,
    1144,  1151,  1176,  1109,   151,   306,   343,   864,   865,   866,
     867,   874,   875,   876,     3,   851,  1189,     4,   307,   841,
     307,     6,     5,  1074,    70,  1070,   287,   342,  1020,  1030,
    1031,     8,    11,    12,  1024,  1025,  1026,   151,   298,   343,
     988,   989,   990,   991,   998,   999,  1000,     3,   975,  1189,
    1109,   343,   928,   930,   937,   939,   940,     6,     8,     8,
       8,   328,   914,  1195,  1196,  1213,    11,    12,  1185,  1186,
    1187,  1143,  1182,     8,   237,  1442,   149,  1145,  1146,   327,
     303,   343,   866,   868,   875,   877,   878,     8,   852,  1195,
     307,     8,   155,  1032,  1033,     6,  1028,   343,   990,   992,
     999,  1001,  1002,     8,   976,  1195,   299,    11,    12,   931,
     932,   933,   934,  1450,  1479,    11,    12,   942,   943,   944,
     941,  1431,  1470,  1503,     8,   330,   915,  1201,  1202,  1213,
      11,    12,  1191,  1192,  1193,  1143,  1188,   323,     8,    11,
      12,  1152,  1153,  1154,  1147,  1148,    11,    12,   869,   870,
     871,   872,  1450,  1479,    11,    12,   880,   881,   882,   879,
    1431,  1470,  1503,   853,  1201,    11,    12,  1035,  1036,  1037,
     192,   193,  1034,  1432,  1434,  1470,  1473,  1476,  1477,  1478,
    1479,  1491,  1497,  1503,     8,   146,   288,  1027,  1214,  1215,
      11,    12,   993,   994,   995,   996,  1450,  1479,    11,    12,
    1004,  1005,  1006,  1003,  1431,  1470,  1503,   977,  1201,     4,
       6,     7,   303,   935,  1110,   945,  1143,   332,   916,  1207,
    1208,  1213,    11,    12,  1197,  1198,  1199,  1143,  1194,   325,
       6,     4,   158,    11,  1150,   235,   236,  1149,  1451,  1453,
     307,   873,  1110,   883,  1143,   854,  1207,   151,   343,  1038,
    1039,  1040,  1041,  1042,  1214,     3,  1216,  1217,   299,   997,
    1110,  1007,  1143,   978,  1207,   303,   152,  1213,    11,    12,
    1203,  1204,  1205,  1143,  1200,   321,     8,   158,     6,     8,
       8,   307,   152,   343,  1214,  1041,  1043,  1044,     8,    11,
      12,  1219,  1220,  1221,   196,   197,   203,   204,   231,  1218,
    1428,  1437,  1452,  1479,  1494,  1495,  1496,  1497,   299,   152,
      11,    12,  1209,  1210,  1211,  1143,  1206,   329,   150,     6,
       6,    11,    12,  1046,  1047,  1048,  1045,  1431,  1470,  1503,
    1222,     3,     8,     8,  1111,  1143,  1212,   331,     8,     8,
    1049,  1143,   245,  1223,  1224,  1225,     8,     6,     6,     6,
     333,   152,   289,  1230,  1226,  1227,     8,     8,  1111,   246,
     256,   258,   260,   262,   264,   266,   268,   270,   272,   282,
    1231,  1232,  1233,  1257,  1258,  1270,  1271,  1297,  1298,  1315,
    1316,  1333,  1334,  1346,  1347,  1364,  1365,  1382,  1383,  1395,
    1396,  1399,  1400,    11,    12,  1229,   200,   201,   219,   220,
     221,   222,   223,   224,   225,   226,  1228,  1443,  1444,  1445,
    1446,  1447,  1454,  1455,  1460,  1461,  1462,  1463,  1234,  1235,
    1259,  1260,  1272,  1273,  1299,  1300,  1317,  1318,  1335,  1336,
    1348,  1349,  1366,  1367,  1384,  1385,   174,   175,  1397,  1488,
    1489,  1490,   202,  1401,  1427,   244,     3,     8,     8,     8,
       8,     8,     8,     8,     8,    11,   198,   199,   206,  1236,
    1438,  1485,  1486,  1487,    11,  1261,  1438,  1485,    11,  1274,
    1438,  1485,    11,  1301,  1438,  1485,    11,  1319,  1438,  1485,
      11,  1337,  1438,  1485,    11,  1350,  1438,  1485,    11,  1368,
    1438,  1485,    11,  1386,  1438,  1485,     3,    11,     8,    11,
    1402,  1111,     6,     6,     6,     6,     6,     6,     6,  1109,
     274,  1237,  1239,  1240,     3,     8,  1239,  1262,  1239,  1275,
    1239,  1302,  1239,  1320,  1239,  1338,  1239,  1351,  1239,  1369,
    1239,  1387,     8,   288,   292,   296,   412,   414,   416,   418,
     420,   422,   424,   426,   428,   430,   432,   434,   436,   438,
     440,   442,  1586,  1587,  1588,  1594,  1595,  1598,  1599,  1602,
    1603,  1606,  1607,  1609,  1610,  1612,  1613,  1615,  1616,  1618,
    1619,  1622,  1623,  1627,  1628,  1630,  1631,  1633,  1634,  1636,
    1637,  1639,  1640,  1642,  1645,  1646,  1648,  1649,  1651,  1652,
       6,   250,  1404,  1405,     8,     8,     8,     8,     8,     8,
       8,     8,   276,  1238,  1245,  1246,    11,    12,  1241,  1242,
    1243,     8,     6,  1245,  1263,  1245,  1276,  1245,  1303,  1245,
    1321,  1245,  1339,  1245,  1352,  1245,  1370,  1245,  1388,  1643,
     283,  1398,  1589,   234,  1597,   234,  1601,   234,  1605,  1586,
    1608,  1586,  1611,   358,   360,   362,   364,   366,   368,   370,
     372,   374,   376,   378,   380,   382,   384,   386,   388,   390,
     392,   394,   396,   398,   400,   402,   404,   406,   408,   410,
    1512,  1513,  1516,  1519,  1521,  1523,  1525,  1527,  1529,  1531,
    1533,  1535,  1537,  1539,  1541,  1543,  1544,  1546,  1548,  1550,
    1552,  1554,  1556,  1557,  1563,  1571,  1574,  1577,  1580,  1583,
    1614,  1586,  1617,   463,  1620,  1626,  1624,  1626,    11,    12,
    1629,  1586,  1632,  1586,  1635,  1586,  1638,  1586,  1641,  1586,
    1647,  1512,  1650,  1586,  1653,     8,   252,  1411,  1412,  1406,
    1431,   257,   278,  1251,  1252,    11,    12,  1247,  1248,  1249,
    1142,  1143,  1244,     8,   278,  1264,  1265,   261,   278,  1277,
    1278,   263,   278,  1304,  1305,   269,   278,  1322,  1323,   271,
     278,  1340,  1341,   267,   278,  1353,  1354,   265,   278,  1371,
    1372,   259,   278,  1389,  1390,   273,  1644,    11,    12,   234,
     465,  1590,  1591,  1592,  1593,     8,    11,    12,  1596,     8,
      11,    12,  1600,     8,    11,    12,  1604,   413,  1586,  1530,
    1522,  1524,  1528,  1532,  1534,  1572,  1584,  1542,  1526,  1549,
    1536,  1538,  1540,  1564,  1547,  1578,  1575,  1581,  1514,  1517,
    1520,  1551,  1553,  1555,   441,  1512,  1559,   443,     3,    11,
      11,   421,  1586,   425,  1586,  1586,   444,   446,   448,   450,
     452,   454,   456,   458,   460,  1512,  1654,  1655,  1656,  1657,
    1662,  1663,  1665,  1666,  1668,  1671,  1672,  1674,  1675,  1677,
    1678,  1680,  1681,  1683,  1684,  1512,   437,  1418,  1413,  1431,
      11,    12,  1407,  1408,  1409,    11,    12,  1253,  1254,  1255,
    1142,  1250,   275,    11,    12,  1266,  1267,  1268,    11,    12,
    1279,  1280,  1281,    11,    12,  1306,  1307,  1308,    11,    12,
    1324,  1325,  1326,    11,    12,  1342,  1343,  1344,    11,    12,
    1355,  1356,  1357,    11,    12,  1373,  1374,  1375,    11,    12,
    1391,  1392,  1393,   431,  1586,   439,     8,     3,     6,   289,
       6,   293,     6,   297,   415,  1512,  1512,  1512,  1512,  1512,
    1512,  1573,  1585,  1512,  1512,  1512,  1512,  1512,  1512,  1567,
    1512,  1579,  1576,  1582,    11,    12,  1515,    11,    12,  1518,
    1512,  1586,  1586,  1586,   389,  1545,    11,    12,   467,  1497,
    1503,  1558,  1560,  1561,     8,  1586,  1621,  1586,  1625,   423,
     427,   429,    11,   433,  1659,  1660,    11,    11,    11,    11,
      11,    11,    11,  1512,   247,   248,  1403,  1419,  1420,    11,
      12,  1414,  1415,  1416,  1143,  1410,   157,  1155,  1156,  1161,
    1256,   277,  1142,  1269,  1282,  1283,  1309,  1327,  1143,  1345,
    1358,  1376,  1165,  1166,  1394,     6,     8,     8,     8,     8,
    1512,  1512,  1512,  1512,   367,   369,   371,  1512,   373,  1512,
     375,   377,  1512,   381,   383,   385,    11,    12,   234,   238,
    1565,  1568,  1569,  1570,   391,   393,  1512,   395,  1512,   397,
    1512,   399,   401,  1512,   407,   409,   411,   405,     3,   417,
     419,  1669,    11,    12,  1658,   229,   230,  1458,  1459,  1661,
    1512,  1664,  1654,  1667,  1654,  1673,  1654,  1676,  1654,  1679,
    1654,  1682,  1654,  1685,  1512,  1421,  1422,  1143,  1417,   251,
    1442,   149,  1157,  1158,   279,   279,   279,   149,  1284,  1285,
     149,   279,  1310,  1311,   149,   279,  1328,  1329,   279,   149,
     279,  1359,  1360,   149,   279,  1377,  1378,   149,  1167,  1168,
     279,     8,   359,   361,   363,   365,  1512,   387,  1512,     8,
       8,   403,  1562,  1670,   451,     8,     8,  1512,  1654,  1654,
     449,   445,  1654,   455,  1586,    11,    12,  1424,  1425,  1426,
     227,   228,  1423,  1448,  1449,  1494,  1497,   253,    11,    12,
    1162,  1163,  1164,  1159,  1453,  1286,  1287,    11,    12,  1312,
    1313,  1314,    11,    12,  1330,  1331,  1332,  1361,  1379,  1169,
    1453,   379,  1566,     6,  1109,     8,   457,  1654,  1109,  1109,
     461,   453,   447,   459,   435,  1223,     8,     8,     4,   158,
      11,  1160,    11,    12,  1289,  1290,  1291,   215,   239,  1288,
    1440,  1457,  1512,  1655,    11,   180,   181,  1362,  1363,  1451,
    1453,  1506,  1507,  1508,    11,    12,  1380,  1381,  1453,  1458,
    1459,    11,  1170,   387,     8,     8,     8,     8,   249,     6,
       6,   158,  1109,  1292,     8,     8,   150,   150,     6,     3,
     150,     4,     8,     8,   150,   150,   280,  1293,  1294,     6,
    1109,   150,     8,   150,   238,  1295,  1456,     8,     8,     8,
      11,  1296,  1109,     6,     8,   281
};

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
    1143,  1143,  1144,  1144,  1145,  1146,  1147,  1148,  1148,  1149,
    1149,  1150,  1151,  1152,  1152,  1153,  1153,  1154,  1155,  1155,
    1156,  1156,  1157,  1158,  1159,  1159,  1160,  1161,  1162,  1162,
    1163,  1163,  1164,  1165,  1166,  1166,  1167,  1168,  1169,  1169,
    1170,  1171,  1172,  1173,  1173,  1174,  1175,  1176,  1177,  1178,
    1179,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1191,  1192,  1193,  1194,  1195,
    1196,  1197,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1203,
    1204,  1205,  1206,  1207,  1208,  1209,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,  1216,  1217,  1217,  1218,  1218,  1218,  1218,
    1218,  1218,  1219,  1219,  1220,  1222,  1221,  1223,  1224,  1224,
    1225,  1226,  1227,  1227,  1228,  1228,  1228,  1228,  1228,  1228,
    1228,  1228,  1228,  1229,  1229,  1230,  1230,  1231,  1231,  1231,
    1231,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1232,  1233,
    1234,  1235,  1235,  1236,  1236,  1237,  1238,  1238,  1239,  1240,
    1241,  1241,  1242,  1243,  1244,  1245,  1245,  1246,  1247,  1247,
    1248,  1249,  1250,  1251,  1252,  1253,  1253,  1254,  1255,  1256,
    1257,  1258,  1259,  1260,  1260,  1261,  1261,  1262,  1263,  1264,
    1264,  1265,  1266,  1266,  1267,  1268,  1269,  1270,  1271,  1272,
    1273,  1273,  1274,  1274,  1275,  1276,  1277,  1277,  1278,  1279,
    1279,  1280,  1281,  1282,  1283,  1283,  1284,  1285,  1286,  1287,
    1287,  1288,  1288,  1289,  1289,  1290,  1291,  1292,  1292,  1293,
    1294,  1295,  1295,  1296,  1297,  1298,  1299,  1300,  1300,  1301,
    1301,  1302,  1303,  1304,  1304,  1305,  1306,  1306,  1307,  1308,
    1309,  1309,  1310,  1311,  1312,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1318,  1319,  1319,  1320,  1321,  1322,  1322,  1323,
    1324,  1324,  1325,  1326,  1327,  1327,  1328,  1329,  1330,  1330,
    1331,  1332,  1333,  1334,  1335,  1336,  1336,  1337,  1337,  1338,
    1339,  1340,  1340,  1341,  1342,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,  1349,  1350,  1350,  1351,  1352,  1353,  1353,
    1354,  1355,  1355,  1356,  1357,  1358,  1358,  1359,  1360,  1361,
    1361,  1362,  1362,  1362,  1363,  1364,  1365,  1366,  1367,  1367,
    1368,  1368,  1369,  1370,  1371,  1371,  1372,  1373,  1373,  1374,
    1375,  1376,  1376,  1377,  1378,  1379,  1379,  1380,  1380,  1380,
    1381,  1381,  1382,  1383,  1384,  1385,  1385,  1386,  1386,  1387,
    1388,  1389,  1389,  1390,  1391,  1391,  1392,  1393,  1394,  1395,
    1396,  1397,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,
    1405,  1406,  1407,  1407,  1408,  1409,  1410,  1411,  1412,  1413,
    1414,  1414,  1415,  1416,  1417,  1418,  1418,  1419,  1420,  1421,
    1422,  1422,  1423,  1423,  1423,  1423,  1424,  1424,  1425,  1426,
    1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,
    1447,  1448,  1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,
    1457,  1458,  1459,  1460,  1461,  1461,  1462,  1463,  1464,  1464,
    1465,  1466,  1467,  1467,  1468,  1469,  1470,  1470,  1471,  1472,
    1473,  1473,  1474,  1475,  1476,  1476,  1477,  1478,  1479,  1479,
    1480,  1481,  1482,  1482,  1483,  1484,  1485,  1485,  1486,  1487,
    1488,  1488,  1489,  1490,  1491,  1491,  1492,  1493,  1494,  1494,
    1495,  1496,  1497,  1497,  1498,  1499,  1500,  1500,  1501,  1502,
    1503,  1503,  1504,  1505,  1506,  1506,  1507,  1508,  1509,  1509,
    1510,  1511,  1512,  1512,  1512,  1512,  1512,  1512,  1512,  1512,
    1512,  1512,  1512,  1512,  1512,  1512,  1512,  1512,  1512,  1512,
    1512,  1512,  1512,  1512,  1512,  1512,  1512,  1512,  1512,  1514,
    1513,  1515,  1515,  1517,  1516,  1518,  1518,  1520,  1519,  1522,
    1521,  1524,  1523,  1526,  1525,  1528,  1527,  1530,  1529,  1532,
    1531,  1534,  1533,  1536,  1535,  1538,  1537,  1540,  1539,  1542,
    1541,  1543,  1544,  1545,  1547,  1546,  1549,  1548,  1551,  1550,
    1553,  1552,  1555,  1554,  1556,  1557,  1558,  1558,  1559,  1559,
    1560,  1560,  1560,  1562,  1561,  1564,  1563,  1565,  1565,  1566,
    1565,  1567,  1567,  1568,  1568,  1569,  1570,  1572,  1571,  1573,
    1573,  1575,  1574,  1576,  1576,  1578,  1577,  1579,  1579,  1581,
    1580,  1582,  1582,  1584,  1583,  1585,  1585,  1586,  1586,  1586,
    1586,  1586,  1586,  1586,  1586,  1586,  1586,  1586,  1586,  1586,
    1586,  1586,  1586,  1586,  1586,  1586,  1587,  1588,  1589,  1589,
    1590,  1590,  1591,  1591,  1592,  1593,  1594,  1595,  1596,  1596,
    1597,  1598,  1599,  1600,  1600,  1601,  1602,  1603,  1604,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1619,  1620,  1620,  1621,  1622,  1623,
    1624,  1624,  1625,  1626,  1627,  1628,  1629,  1629,  1630,  1631,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,
    1643,  1642,  1644,  1644,  1645,  1646,  1647,  1648,  1649,  1650,
    1651,  1652,  1653,  1654,  1654,  1655,  1655,  1655,  1655,  1655,
    1655,  1655,  1655,  1655,  1656,  1657,  1658,  1658,  1659,  1660,
    1660,  1661,  1661,  1662,  1663,  1664,  1665,  1666,  1667,  1669,
    1668,  1670,  1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,
    1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       1,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     3,     3,     1,     1,     2,     1,     3,     1,     1,
       0,     2,     3,     1,     0,     1,     3,     3,     1,     1,
       2,     1,     3,     1,     0,     2,     3,     1,     0,     1,
       3,     3,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     2,     0,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     0,     2,     1,     1,     3,     0,     2,     2,     1,
       1,     1,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     3,     1,
       4,     1,     1,     0,     2,     1,     1,     3,     2,     0,
       2,     1,     1,     1,     1,     3,     1,     4,     1,     1,
       0,     2,     1,     1,     3,     2,     0,     2,     1,     1,
       1,     1,     3,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     3,     0,     2,     3,
       1,     0,     1,     3,     4,     1,     1,     0,     2,     1,
       1,     3,     2,     0,     2,     1,     1,     1,     1,     3,
       0,     2,     2,     1,     1,     1,     1,     3,     4,     1,
       1,     0,     2,     1,     1,     3,     2,     0,     2,     1,
       1,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     3,     4,     1,     1,     0,     2,     1,     1,     3,
       2,     0,     2,     1,     1,     1,     1,     3,     1,     4,
       1,     1,     0,     2,     1,     1,     3,     2,     0,     2,
       1,     1,     1,     1,     3,     0,     2,     3,     1,     0,
       2,     1,     1,     1,     3,     4,     1,     1,     0,     2,
       1,     1,     3,     2,     0,     2,     1,     1,     1,     1,
       3,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       2,     1,     4,     1,     1,     0,     2,     1,     1,     3,
       2,     0,     2,     1,     1,     1,     1,     3,     1,     5,
       1,     0,     1,     1,     3,     1,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
       1,     1,     1,     1,     1,     1,     3,     1,     0,     2,
       1,     1,     1,     2,     4,     3,     3,     1,     1,     2,
       4,     3,     1,     1,     2,     4,     3,     1,     1,     2,
       4,     2,     1,     2,     2,     1,     3,     2,     1,     2,
       2,     1,     2,     4,     1,     0,     1,     2,     4,     1,
       0,     1,     2,     3,     2,     1,     1,     2,     2,     1,
       3,     2,     1,     2,     2,     1,     3,     2,     1,     3,
       0,     4,     0,     2,     2,     1,     3,     2,     1,     6,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     2,     1,     0,
       2,     1,     1,     3,     1,     3,     3,     1,     3,     0,
       5,     0,     2,     3,     1,     3,     3,     1,     2,     3,
       1,     2,     3,     1,     3,     3,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, osresult, parserData, osglData, osnlData, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, osresult, parserData, osglData, osnlData); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (osresult);
  YYUSE (parserData);
  YYUSE (osglData);
  YYUSE (osnlData);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osresult, parserData, osglData, osnlData);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , osresult, parserData, osglData, osnlData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, osresult, parserData, osglData, osnlData); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (OSResult *osresult, OSrLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
     '$$ = $1'.

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

    {osresult->setGeneralMessage((yyvsp[0].sval)); free((yyvsp[0].sval)); parserData->errorText = NULL;}

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
        osresult->setServiceURI((yyvsp[0].sval)); free((yyvsp[0].sval)); parserData->errorText = NULL;
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
        osresult->setServiceName((yyvsp[0].sval)); free((yyvsp[0].sval)); parserData->errorText = NULL;
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
        osresult->setInstanceName((yyvsp[0].sval)); free((yyvsp[0].sval)); parserData->errorText = NULL;
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
        osresult->setJobID((yyvsp[0].sval)); free((yyvsp[0].sval)); parserData->errorText = NULL;
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
        osresult->setSolverInvoked((yyvsp[0].sval)); free((yyvsp[0].sval)); parserData->errorText = NULL;
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
        osresult->setTimeStamp((yyvsp[0].sval)); free((yyvsp[0].sval)); parserData->errorText = NULL;
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
        osresult->setSystemInformation((yyvsp[0].sval)); 
        free((yyvsp[0].sval)); 
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
    osresult->setAvailableCPUNumberValue( (yyvsp[0].ival));  parserData->errorText = NULL;
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
       parserData->tempStr = (yyvsp[0].sval); free((yyvsp[0].sval));
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
        osresult->setCurrentJobCount((yyvsp[0].ival)); parserData->errorText = NULL;
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
        osresult->setTotalJobsSoFar((yyvsp[0].ival)); parserData->errorText = NULL; 
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
        osresult->setTimeServiceStarted((yyvsp[0].sval)); free((yyvsp[0].sval)); parserData->errorText = NULL;
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
        parserData->tempStr = (yyvsp[0].sval); free((yyvsp[0].sval));
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
        osresult->setJobSubmitTime((yyvsp[0].sval)); free((yyvsp[0].sval)); parserData->errorText = NULL;
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
        osresult->setScheduledStartTime((yyvsp[0].sval)); free((yyvsp[0].sval)); parserData->errorText = NULL;
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
        osresult->setActualStartTime((yyvsp[0].sval)); free((yyvsp[0].sval));  parserData->errorText = NULL;
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
        osresult->setJobEndTime((yyvsp[0].sval)); free((yyvsp[0].sval));  parserData->errorText = NULL;
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

    { parserData->timeValue = (yyvsp[0].dval); }

    break;

  case 385:

    { parserData->timeValue = (yyvsp[0].ival); }

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
    osresult->setUsedCPUNumberValue( (yyvsp[0].ival));  parserData->errorText = NULL; 
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
    if((yyvsp[-1].ival) >= 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "target objective index must be negative");
      if (osresult->setSolutionTargetObjectiveIdx(parserData->solutionIdx, (yyvsp[-1].ival)) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionTargetObjectiveIdx failed");
 }

    break;

  case 467:

    {
    if (parserData->nameAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "target objective name previously set");
    parserData->nameAttributePresent = true;
    parserData->tempStr = (yyvsp[-1].sval); free((yyvsp[-1].sval));
      if (osresult->setSolutionTargetObjectiveName(parserData->solutionIdx, parserData->tempStr) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolutionTargetObjectiveName failed");
 }

    break;

  case 468:

    {
    if (parserData->weightedObjAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "weighted objective attribute previously set");
    parserData->weightedObjAttributePresent = true;
    parserData->tempStr = (yyvsp[-1].sval); free((yyvsp[-1].sval));
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
        parserData->tempStr = (yyvsp[0].sval);
        free((yyvsp[0].sval));
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
        parserData->tempStr = (yyvsp[0].sval); free((yyvsp[0].sval));
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
    parserData->itemContent = (yyvsp[0].sval); free((yyvsp[0].sval));
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
    parserData->itemContent = (yyvsp[0].sval); free((yyvsp[0].sval));
    if (osresult->setSolverOutputItem(parserData->iOther, parserData->kounter, 
                                      parserData->itemContent) == false)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "setSolverOutputItem failed");
}

    break;

  case 982:

    {
    if ((yyvsp[-1].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other constraint results cannot be negative");
    parserData->tempInt = (yyvsp[-1].ival);
}

    break;

  case 983:

    {
    if ((yyvsp[-1].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other matrix programming results cannot be negative");
    parserData->tempInt = (yyvsp[-1].ival);
}

    break;

  case 984:

    {
    if ((yyvsp[-1].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other matrix variable results cannot be negative");
    parserData->tempInt = (yyvsp[-1].ival);
}

    break;

  case 985:

    {
    if ((yyvsp[-1].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other objective results cannot be negative");
    parserData->tempInt = (yyvsp[-1].ival);
}

    break;

  case 986:

    {
    if ((yyvsp[-1].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other results cannot be negative");
    parserData->tempInt = (yyvsp[-1].ival);
}

    break;

  case 987:

    {    
    if ((yyvsp[-1].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other solution results cannot be negative");
    parserData->tempInt = (yyvsp[-1].ival);
}

    break;

  case 988:

    {    
    if ((yyvsp[-1].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other variable results cannot be negative");
    parserData->tempInt = (yyvsp[-1].ival);
}

    break;

  case 989:

    {
    if (parserData->numberAttributePresent)
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "numberOfSolutions attribute previously set");
    if ((yyvsp[-1].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of solutions cannot be negative");
    parserData->numberAttributePresent = true;
    parserData->tempInt = (yyvsp[-1].ival); 
}

    break;

  case 990:

    {    
    if ((yyvsp[-1].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of other solver outputs cannot be negative");
    parserData->tempInt = (yyvsp[-1].ival);
}

    break;

  case 991:

    {
   if (parserData->numberAttributePresent ) 
        osrlerror(NULL, NULL, parserData, osglData, osnlData, "only one numberOfSubstatuses attribute allowed");
    parserData->numberAttributePresent = true;
    if ((yyvsp[-1].ival) < 0) osrlerror(NULL, NULL, parserData, osglData, osnlData, "number of <substatus> elements cannot be negative");
    parserData->tempInt = (yyvsp[-1].ival);
}

    break;

  case 992:

    {
    parserData->tempInt = (yyvsp[-1].ival);
}

    break;

  case 993:

    {parserData->tempVal = (yyvsp[0].ival);}

    break;

  case 994:

    {parserData->tempVal = (yyvsp[0].dval);}

    break;

  case 995:

    { parserData->tempStr = (yyvsp[0].sval);       free((yyvsp[0].sval)); }

    break;

  case 996:

    { parserData->tempStr = os_dtoa_format((yyvsp[0].ival)); }

    break;

  case 997:

    { parserData->tempStr = os_dtoa_format((yyvsp[0].dval)); }

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
    osglData->fileName = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));
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
    osglData->source = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));
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
    osglData->description = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));
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
    osglData->fileCreator = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));
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
    osglData->licence = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));
}

    break;

  case 1049:

    {
    for (int i=0; i<osglData->numberOfEl; i++)
        if (osglData->osglIntArray < 0)
            throw ErrorClass("negative entry detected in nonnegativeIntVector");
}

    break;

  case 1050:

    {
         if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }

    break;

  case 1055:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
    osglData->incr = 0;
}

    break;

  case 1061:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL IntVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[-1].ival) + i*osglData->incr;    
}

    break;

  case 1067:

    {
    char* b64string = (yyvsp[-1].sval);
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
    free((yyvsp[-1].sval));
}

    break;

  case 1068:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }

    break;

  case 1073:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}

    break;

  case 1076:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL DblVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
}

    break;

  case 1082:

    {
    char* b64string = (yyvsp[-1].sval);
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
    free((yyvsp[-1].sval));
}

    break;

  case 1083:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }

    break;

  case 1087:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}

    break;

  case 1090:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL StrVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglStrArray[osglData->osglCounter++] = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));    
}

    break;

  case 1092:

    {
    osglData->numberOfElPresent = false;
}

    break;

  case 1099:

    {
    osglData->numberOfElPresent = false;
}

    break;

  case 1106:

    {
    osglData->numberOfElPresent = false;
}

    break;

  case 1113:

    {
    osglData->numberOfElPresent = false;
}

    break;

  case 1120:

    {
    osglData->numberOfElPresent = false;
}

    break;

  case 1127:

    {
    osglData->numberOfElPresent = false;
}

    break;

  case 1134:

    {
    osglData->numberOfElPresent = false;
}

    break;

  case 1140:

    {
    osglData->osglCounter = 0;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
}

    break;

  case 1141:

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

  case 1142:

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

  case 1143:

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
    {
        if (osglData->symmetry == "default")
            osglData->symmetry =  "none";
        ((OSMatrix*)osglData->tempC)->symmetry 
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
}

    break;

  case 1147:

    {std::cout << "processed osglNumberOfRowsATT attribute: " << osglData->numberOfRows << std::endl;}

    break;

  case 1148:

    {std::cout << "processed osglNumberOfColumnsATT attribute: " << osglData->numberOfColumns  << std::endl;}

    break;

  case 1151:

    {std::cout << "processed osglMatrixVarIdxATT attribute: " << osglData->matrixVarIdx  << std::endl;}

    break;

  case 1155:

    {std::cout << " start matrixVar" << std::endl;}

    break;

  case 1156:

    {
std::cout << "matrixVar is finished" << std::endl;
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}

    break;

  case 1159:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}

    break;

  case 1160:

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

  case 1161:

    {
    if (osglData->baseMatrixIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mandatory attribute baseMatrixIdx is missing");
    else
    {
        if (osglData->baseMatrixIdx < 0 || osglData->baseMatrixIdx >= osglData->matrixCounter)
            throw ErrorClass("Improper idx value for baseMatrix reference");
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

  case 1176:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++;
}

    break;

  case 1189:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1190:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}

    break;

  case 1193:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1194:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1198:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1199:

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
    //verify start vector: first element must be zero, vector must be nondecreasing, 
    //last element must equal numberOfValues; length must equal numberOfRows + 1 or numberOfColumns + 1
    if (osglData->osglIntArray[0] != 0)
        throw ErrorClass("first entry of matrix element start vector is not zero");
    for (int i=1; i < osglData->numberOfEl; i++)
    {
        if (osglData->osglIntArray[i] < osglData->osglIntArray[i-1])
            throw ErrorClass("matrix element start vector must be nondecreasing");
    }
    if (osglData->osglIntArray[osglData->numberOfEl-1] 
        != ((MatrixElements*)osglData->tempC)->numberOfValues)
            throw ErrorClass("last entry of matrix element start vector does not equal numberOfValues");
}

    break;

  case 1206:

    {
    ((MatrixElements*)osglData->tempC)->index = new IntVector();
    ((MatrixElements*)osglData->tempC)->index->numberOfEl
        = ((MatrixElements*)osglData->tempC)->numberOfValues;
    //check whether the values of the index array are legal and satisfy symmetry assertions
    int maxindex;
    //symmetry.substr(0,5) == "upper"/"lower"
    ((MatrixElements*)osglData->tempC)->index->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1207:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 1213:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1214:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 1221:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1222:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}

    break;

  case 1225:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1226:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1230:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1231:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 1238:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1239:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}

    break;

  case 1242:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1243:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1246:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 1247:

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

  case 1248:

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

  case 1256:

    {
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}

    break;

  case 1257:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
}

    break;

  case 1258:

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

  case 1270:

    {
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}

    break;

  case 1272:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}

    break;

  case 1273:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[-1].ival);
    osglData->osglCounter++;
}

    break;

  case 1275:

    {
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1276:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
}

    break;

  case 1279:

    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1280:

    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1283:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 1284:

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

  case 1285:

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

  case 1293:

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

  case 1297:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }

    break;

  case 1299:

    {
    osglData->tempC = new ComplexValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1300:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<complexValuedExpressions>: numberOfValues attribute missing");    
}

    break;

  case 1303:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1304:

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
        ((ComplexValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
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
    if (osglData->numberOfValues > 0)
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
        if (osglData->nonzeroCounter < osglData->numberOfValues) 
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
    if (osglData->numberOfEl > 0)
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
    }

    break;

  case 1345:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1348:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 1349:

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

  case 1350:

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

  case 1358:

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

  case 1364:

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
                    = (yyvsp[-1].ival) + i*osglData->incr;
                ((ConReferenceMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter + i]->valueType
                    = (ENUM_CONREFERENCE_VALUETYPE)returnConReferenceValueType(osglData->valueType);
            }
        }
        osglData->nonzeroCounter += osglData->mult;
    }
}

    break;

  case 1366:

    {
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1367:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
}

    break;

  case 1370:

    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1371:

    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1374:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 1375:

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

  case 1376:

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

  case 1383:

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

  case 1384:

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

  case 1393:

    {
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1394:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
}

    break;

  case 1397:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1398:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1402:

    {
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1403:

    {
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 1410:

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

  case 1412:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}

    break;

  case 1413:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}

    break;

  case 1414:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}

    break;

  case 1415:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}

    break;

  case 1416:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}

    break;

  case 1418:

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

  case 1419:

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

  case 1420:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}

    break;

  case 1421:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}

    break;

  case 1427:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1428:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}

    break;

  case 1429:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}

    break;

  case 1436:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}

    break;

  case 1437:

    {
    osglData->mtxBlkVec.pop_back();
}

    break;

  case 1438:

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

  case 1444:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        if (osglData->symmetry == "none")
            osglData->symmetry =  "default";
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }

    break;

  case 1445:

    {
        ((MatrixBlock*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }

    break;

  case 1449:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}

    break;

  case 1450:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <blocks> cannot be negative");
    osglData->numberOfBlocksPresent = true;        
    osglData->numberOfBlocks = (yyvsp[-1].ival);
}

    break;

  case 1451:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <blocks> cannot be negative");
    osglData->numberOfColumnsPresent = true;        
    osglData->numberOfColumns = (yyvsp[-1].ival);
}

    break;

  case 1452:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfCon attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <con> cannot be negative");
    osglData->numberOfConPresent = true;        
    osglData->numberOfCon = (yyvsp[-1].ival);
}

    break;

  case 1453:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of constraints cannot be negative");
    osglData->numberOfConstraintsPresent = true;        
    osglData->numberOfConstraints = (yyvsp[-1].ival);
}

    break;

  case 1454:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <el> cannot be negative");
    osglData->numberOfElPresent = true;        
    osglData->numberOfEl = (yyvsp[-1].ival);
}

    break;

  case 1455:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfEnumerationsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <enumerations> cannot be negative");
    osglData->numberOfEnumerationsPresent = true;        
    osglData->numberOfEnumerations = (yyvsp[-1].ival);
}

    break;

  case 1456:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfItemsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfItems attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <items> cannot be negative");
    osglData->numberOfItemsPresent = true;        
    osglData->numberOfItems = (yyvsp[-1].ival);
}

    break;

  case 1457:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfMatrixVar attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <matrixVar> cannot be negative");
    osglData->numberOfMatrixVarPresent = true;        
    osglData->numberOfMatrixVar = (yyvsp[-1].ival);
}

    break;

  case 1458:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfObj attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <obj> cannot be negative");
    osglData->numberOfObjPresent = true;        
    osglData->numberOfObj = (yyvsp[-1].ival);
}

    break;

  case 1459:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of objectives cannot be negative");
    osglData->numberOfObjectivesPresent = true;        
    osglData->numberOfObjectives = (yyvsp[-1].ival);
}

    break;

  case 1460:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <rows> cannot be negative");
std::cout << "Number of rows present" << std::endl;
    osglData->numberOfRowsPresent = true;        
    osglData->numberOfRows = (yyvsp[-1].ival);
}

    break;

  case 1461:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <values> cannot be negative");
    osglData->numberOfValuesPresent = true;        
    osglData->numberOfValues = (yyvsp[-1].ival);
}

    break;

  case 1462:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVar attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <var> cannot be negative");
    osglData->numberOfVarPresent = true;        
    osglData->numberOfVar = (yyvsp[-1].ival);
}

    break;

  case 1463:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxPresent = true;        
    osglData->numberOfVarIdx = (yyvsp[-1].ival);
}

    break;

  case 1464:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVariablesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("number of variables cannot be negative");
    osglData->numberOfVariablesPresent = true;        
    osglData->numberOfVariables = (yyvsp[-1].ival);
}

    break;

  case 1465:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->base64SizePresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base64Size attribute previously set");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("base64Size cannot be negative");
    osglData->base64SizePresent = true;        
    osglData->base64Size = (yyvsp[-1].ival);
}

    break;

  case 1466:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0) throw ErrorClass("baseMatrix idx cannot be negative");
    if ((yyvsp[-1].ival) > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = (yyvsp[-1].ival); 
}

    break;

  case 1467:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = (yyvsp[-1].ival); 
}

    break;

  case 1468:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix first column cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = (yyvsp[-1].ival); 
}

    break;

  case 1469:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix end row cannot be negative");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = (yyvsp[-1].ival); 
}

    break;

  case 1470:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("baseMatrix end col cannot be negative");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = (yyvsp[-1].ival); 
}

    break;

  case 1471:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockRowIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ((yyvsp[-1].ival) < 0) throw ErrorClass("blockRowIdx cannot be negative");
        osglData->blockRowIdxPresent = true;        
        osglData->blockRowIdx = (yyvsp[-1].ival);
        ((MatrixBlock*)osglData->tempC)->blockRowIdx = (yyvsp[-1].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfRows 
        = osglData->rowOffsets.back()[osglData->blockRowIdx+1]
        - osglData->rowOffsets.back()[osglData->blockRowIdx];
}

    break;

  case 1472:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockColIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ((yyvsp[-1].ival) < 0) throw ErrorClass("blockColIdx cannot be negative");
        osglData->blockColIdxPresent = true;
        osglData->blockColIdx = (yyvsp[-1].ival);       
        ((MatrixBlock*)osglData->tempC)->blockColIdx = (yyvsp[-1].ival);
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfColumns 
        = osglData->colOffsets.back()[osglData->blockColIdx+1] 
        - osglData->colOffsets.back()[osglData->blockColIdx];
}

    break;

  case 1473:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[-1].ival);
}

    break;

  case 1474:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[-1].ival);
}

    break;

  case 1475:

    {
    if (osglData->matrixVarIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarIdx attribute in <matrixVar> element");
    osglData->matrixVarIdxPresent = true;
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<matrixVarIdx> cannot be negative");
    osglData->matrixVarIdx = (yyvsp[-1].ival); 
}

    break;

  case 1476:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->multPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[-1].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "mult must be positive");
    osglData->multPresent = true;
    osglData->mult = (yyvsp[-1].ival);
}

    break;

  case 1477:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowPresent = true;   
    osglData->targetMatrixFirstRow = (yyvsp[-1].ival); 
}

    break;

  case 1478:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColPresent = true;   
    osglData->targetMatrixFirstCol = (yyvsp[-1].ival); 
}

    break;

  case 1479:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
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

  case 1480:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
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

  case 1481:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
}

    break;

  case 1482:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
}

    break;

  case 1483:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}

    break;

  case 1486:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}

    break;

  case 1487:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
    {
        if      (strcmp((yyvsp[-1].sval),"false") == 0) osglData->baseTranspose = false;
        else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osglData->baseTranspose = false;
        else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    }
    osglData->baseTransposePresent = true;
    free((yyvsp[-1].sval));
}

    break;

  case 1490:

    {
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;
}

    break;

  case 1491:

    { 
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;   
    osglData->category = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1494:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;  
}

    break;

  case 1495:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;   
    osglData->conType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1498:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;
}

    break;

  case 1499:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;   
    osglData->description = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));
}

    break;

  case 1502:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
}

    break;

  case 1503:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
    osglData->enumType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1506:

    {
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
}

    break;

  case 1507:

    {
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
    osglData->matrixVarType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1510:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}

    break;

  case 1511:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1514:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
}

    break;

  case 1515:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
    osglData->objType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1518:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}

    break;

  case 1519:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp((yyvsp[-1].sval),"false") == 0) osglData->rowMajor = false;
        else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osglData->rowMajor = false;
        else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free((yyvsp[-1].sval));
}

    break;

  case 1522:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}

    break;

  case 1523:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));
}

    break;

  case 1526:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
}

    break;

  case 1527:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
    osglData->solver = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1530:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}

    break;

  case 1531:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1534:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}

    break;

  case 1535:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1538:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
}

    break;

  case 1539:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
    osglData->unit = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1542:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}

    break;

  case 1543:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1546:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}

    break;

  case 1547:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1550:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}

    break;

  case 1551:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1579:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}

    break;

  case 1583:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}

    break;

  case 1587:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1589:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1591:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1593:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1595:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1597:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1599:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1601:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1603:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1605:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1607:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1609:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1612:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1613:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 1614:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1615:

    {
}

    break;

  case 1616:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1617:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 1618:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1620:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1622:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1624:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}

    break;

  case 1625:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}

    break;

  case 1630:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }

    break;

  case 1631:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }

    break;

  case 1633:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[0].sval);
    free((yyvsp[0].sval));
}

    break;

  case 1635:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}

    break;

  case 1636:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}

    break;

  case 1639:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }

    break;

  case 1643:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }

    break;

  case 1644:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }

    break;

  case 1645:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}

    break;

  case 1646:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += 
            addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += 
            addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "variable index cannot be negative");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[-1].ival);
}

    break;

  case 1647:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1648:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}

    break;

  case 1650:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }

    break;

  case 1651:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1652:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 1654:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }

    break;

  case 1655:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1656:

    {
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 1658:

    { osnlData->maxVec.back()->inumberOfChildren++; }

    break;

  case 1659:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1660:

    {
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 1662:

    { osnlData->minVec.back()->inumberOfChildren++; }

    break;

  case 1663:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1664:

    {
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}

    break;

  case 1666:

    { osnlData->productVec.back()->inumberOfChildren++; }

    break;

  case 1686:

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

  case 1687:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}

    break;

  case 1694:

    {
    if (osnlData->idxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "idx attribute repeated");
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ((yyvsp[-1].ival) < 0)
        throw ErrorClass("Matrix reference must be nonnegative");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[-1].ival);
    osnlData->idxAttributePresent = true;
}

    break;

  case 1695:

    {
    if (osnlData->transposeAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "transpose attribute repeated");
    if      (strcmp((yyvsp[-1].sval),"false") == 0) osnlData->matrixTransposeAttribute = false;
    else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osnlData->matrixTransposeAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[-1].sval));
    osnlData->transposeAttributePresent = true;
}

    break;

  case 1696:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 1697:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}

    break;

  case 1700:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[-1].ival);
}

    break;

  case 1701:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 1702:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}

    break;

  case 1705:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[-1].ival);
}

    break;

  case 1706:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 1707:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}

    break;

  case 1710:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[-1].ival);
}

    break;

  case 1712:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1715:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1718:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1721:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1724:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1726:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}

    break;

  case 1729:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1731:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}

    break;

  case 1733:

    {
    if      (strcmp((yyvsp[-1].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osnlData->includeDiagonalAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[-1].sval));
}

    break;

  case 1735:

    {
     parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "matrix merge not yet implemented");
}

    break;

  case 1739:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1742:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1745:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1748:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1750:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1751:

    {
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
}

    break;

  case 1753:

    { 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
}

    break;

  case 1755:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1758:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1761:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1774:

    {
}

    break;

  case 1775:

    {
    osglData->realPartPresent = false;
    osglData->imagPartPresent = false;
    osnlData->nlNodePoint = new OSnLCNodeNumber();
    osnlData->nlNodeVec.push_back(osnlData->nlNodePoint);
}

    break;

  case 1778:

    {
    ((OSnLCNodeNumber*)osnlData->nlNodePoint)->setValue(osglData->realPart, osglData->imagPart);
std::cout << "just to verify: value = " 
          << ((OSnLCNodeNumber*)osnlData->nlNodePoint)->getValue() << std::endl;
}

    break;

  case 1784:

    {
    osnlData->nlNodePoint = new OSnLCNodeCreate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1787:

    {
    osnlData->nlNodePoint = new OSnLCNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1789:

    {
    osnlData->nlNodePoint = new OSnLCNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->cSumVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1790:

    {
    osnlData->cSumVec.back()->m_mChildren = new ExprNode*[ osnlData->cSumVec.back()->inumberOfChildren];
    osnlData->cSumVec.pop_back();
}

    break;

  case 1792:

    { 
    osnlData->cSumVec.back()->inumberOfChildren++; 
}

    break;

  case 1794:

    {
    osnlData->nlNodePoint = new OSnLCNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1797:

    {
    osnlData->nlNodePoint = new OSnLCNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1800:

    {
    osnlData->nlNodePoint = new OSnLCNodeConjugate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1803:

    {
    osnlData->nlNodePoint = new OSnLCNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1806:

    {
    osnlData->nlNodePoint = new OSnLCNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, osresult, parserData, osglData, osnlData, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, osresult, parserData, osglData, osnlData, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, osresult, parserData, osglData, osnlData);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, osresult, parserData, osglData, osnlData);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
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

