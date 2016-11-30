/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

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
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{


    double dval;
    int ival;
    char* sval;


};
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
#define YYLAST   2170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  472
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  1213
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1806
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2545

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
    3728,  3730,  4031,  4037,  4043,  4049,  4055,  4061,  4067,  4073,
    4082,  4088,  4097,  4125,  4126,  4130,  4131,  4132,  4134,  4136,
    4136,  4138,  4139,  4140,  4141,  4177,  4179,  4193,  4193,  4195,
    4197,  4199,  4201,  4201,  4204,  4205,  4206,  4207,  4208,  4210,
    4218,  4218,  4220,  4220,  4222,  4228,  4236,  4236,  4238,  4238,
    4240,  4246,  4254,  4254,  4256,  4256,  4258,  4264,  4272,  4272,
    4274,  4274,  4276,  4282,  4290,  4290,  4292,  4292,  4294,  4305,
    4313,  4321,  4323,  4323,  4325,  4327,  4336,  4338,  4338,  4340,
    4340,  4342,  4351,  4354,  4354,  4356,  4356,  4359,  4390,  4398,
    4400,  4400,  4402,  4404,  4412,  4412,  4414,  4423,  4425,  4425,
    4427,  4427,  4429,  4460,  4470,  4470,  4472,  4474,  4482,  4482,
    4484,  4620,  4622,  4627,  4627,  4629,  4631,  4633,  4636,  4638,
    4643,  4643,  4645,  4647,  4649,  4652,  4654,  4659,  4659,  4661,
    4663,  4665,  4668,  4670,  4675,  4675,  4677,  4679,  4681,  4684,
    4686,  4691,  4691,  4693,  4695,  4697,  4700,  4702,  4707,  4707,
    4709,  4711,  4713,  4716,  4718,  4723,  4723,  4725,  4727,  4729,
    4732,  4946,  5041,  5066,  5094,  5094,  5097,  5098,  5099,  5100,
    5101,  5102,  5245,  5245,  5247,  5249,  5278,  5280,  5280,  5285,
    5303,  5332,  5332,  5335,  5336,  5337,  5338,  5339,  5340,  5341,
    5342,  5343,  5346,  5346,  5348,  5348,  5353,  5353,  5353,  5354,
    5354,  5354,  5355,  5355,  5355,  5356,  5356,  5358,  5360,  5369,
    5375,  5375,  5378,  5382,  5388,  5390,  5390,  5396,  5406,  5416,
    5416,  5418,  5420,  5436,  5439,  5439,  5453,  5461,  5461,  5463,
    5465,  5467,  5473,  5483,  5491,  5491,  5493,  5495,  5497,  5500,
    5502,  5511,  5517,  5517,  5520,  5524,  5530,  5532,  5534,  5534,
    5544,  5552,  5552,  5554,  5556,  5558,  5561,  5563,  5572,  5578,
    5578,  5581,  5585,  5591,  5593,  5596,  5601,  5612,  5628,  5628,
    5630,  5632,  5634,  5636,  5636,  5638,  5645,  5652,  5671,  5671,
    5674,  5675,  5677,  5677,  5679,  5681,  5683,  5683,  5686,  5688,
    5696,  5696,  5701,  5708,  5710,  5719,  5725,  5725,  5728,  5732,
    5739,  5741,  5744,  5748,  5759,  5775,  5775,  5777,  5779,  5781,
    5781,  5783,  5785,  5800,  5800,  5802,  5804,  5813,  5815,  5824,
    5830,  5830,  5833,  5837,  5844,  5846,  5849,  5853,  5864,  5881,
    5881,  5883,  5885,  5887,  5887,  5889,  5891,  5906,  5906,  5908,
    5910,  5920,  5922,  5931,  5937,  5937,  5940,  5944,  5950,  5952,
    5954,  5954,  5964,  5972,  5972,  5974,  5976,  5978,  5981,  5983,
    5992,  5998,  5998,  6001,  6005,  6011,  6013,  6016,  6020,  6031,
    6047,  6047,  6049,  6051,  6053,  6053,  6055,  6058,  6070,  6070,
    6073,  6074,  6075,  6077,  6110,  6112,  6122,  6128,  6128,  6131,
    6135,  6141,  6143,  6146,  6150,  6161,  6174,  6174,  6176,  6178,
    6180,  6180,  6182,  6209,  6220,  6220,  6223,  6224,  6225,  6227,
    6227,  6230,  6232,  6241,  6247,  6247,  6250,  6254,  6260,  6262,
    6264,  6264,  6274,  6282,  6282,  6284,  6286,  6288,  6291,  6294,
    6312,  6312,  6323,  6330,  6340,  6348,  6354,  6356,  6370,  6382,
    6388,  6394,  6394,  6396,  6398,  6400,  6402,  6412,  6418,  6424,
    6424,  6426,  6428,  6430,  6432,  6432,  6437,  6442,  6454,  6456,
    6456,  6459,  6460,  6461,  6471,  6478,  6478,  6480,  6482,  6500,
    6511,  6522,  6544,  6555,  6566,  6577,  6621,  6645,  6667,  6678,
    6690,  6701,  6712,  6723,  6737,  6748,  6762,  6777,  6792,  6804,
    6816,  6836,  6856,  6866,  6896,  6906,  6917,  6929,  6943,  6956,
    6969,  6979,  6989,  7002,  7002,  7004,  7014,  7032,  7032,  7034,
    7041,  7050,  7050,  7052,  7059,  7068,  7068,  7070,  7077,  7086,
    7086,  7088,  7095,  7160,  7160,  7162,  7169,  7178,  7178,  7180,
    7187,  7196,  7196,  7198,  7205,  7214,  7214,  7216,  7225,  7241,
    7241,  7243,  7250,  7259,  7259,  7261,  7268,  7277,  7277,  7279,
    7286,  7295,  7295,  7297,  7304,  7313,  7313,  7315,  7322,  7331,
    7331,  7335,  7343,  7352,  7352,  7354,  7361,  7370,  7370,  7372,
    7379,  7531,  7532,  7533,  7534,  7535,  7536,  7537,  7538,  7539,
    7540,  7541,  7542,  7543,  7544,  7545,  7546,  7547,  7548,  7549,
    7550,  7551,  7552,  7553,  7554,  7556,  7557,  7558,  7562,  7562,
    7565,  7566,  7568,  7568,  7571,  7572,  7576,  7576,  7581,  7581,
    7586,  7586,  7591,  7591,  7596,  7596,  7601,  7601,  7606,  7606,
    7611,  7611,  7616,  7616,  7621,  7621,  7626,  7626,  7631,  7631,
    7636,  7638,  7644,  7651,  7651,  7657,  7657,  7669,  7669,  7674,
    7674,  7679,  7679,  7689,  7696,  7702,  7703,  7705,  7706,  7709,
    7713,  7717,  7721,  7720,  7741,  7740,  7747,  7748,  7750,  7749,
    7756,  7757,  7760,  7766,  7774,  7781,  7803,  7803,  7814,  7814,
    7817,  7817,  7831,  7832,  7835,  7835,  7848,  7849,  7852,  7852,
    7865,  7866,  7869,  7869,  7879,  7880,  7886,  7887,  7888,  7889,
    7890,  7891,  7892,  7893,  7894,  7895,  7896,  7897,  7898,  7899,
    7900,  7901,  7902,  7903,  7904,  7907,  7918,  7926,  7926,  7929,
    7930,  7933,  7934,  7936,  7948,  7962,  7967,  7974,  7975,  7977,
    7984,  7989,  7996,  7997,  7999,  8006,  8011,  8018,  8019,  8021,
    8028,  8030,  8036,  8038,  8040,  8046,  8048,  8050,  8056,  8058,
    8060,  8066,  8068,  8070,  8076,  8076,  8081,  8083,  8085,  8091,
    8091,  8096,  8098,  8109,  8111,  8116,  8116,  8118,  8120,  8126,
    8129,  8131,  8137,  8140,  8142,  8148,  8151,  8153,  8159,  8163,
    8162,  8174,  8174,  8181,  8183,  8189,  8191,  8193,  8199,  8202,
    8204,  8210,  8327,  8327,  8331,  8332,  8333,  8334,  8335,  8336,
    8337,  8338,  8339,  8343,  8347,  8356,  8357,  8359,  8366,  8366,
    8369,  8370,  8374,  8376,  8382,  8385,  8387,  8393,  8396,  8396,
    8406,  8407,  8413,  8415,  8421,  8424,  8426,  8432,  8435,  8437,
    8443,  8446,  8448,  8454,  8457,  8459,  8465
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

#define YYPACT_NINF -2211

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-2211)))

#define YYTABLE_NINF -1205

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     163, -2211, -2211,   159,   157,   148, -2211, -2211,   282,    12,
   -2211,   327, -2211,   464, -2211, -2211, -2211, -2211,    51,   499,
   -2211, -2211, -2211, -2211, -2211,   157, -2211, -2211, -2211, -2211,
   -2211,    58,   501,   -10, -2211, -2211, -2211, -2211,   260,   356,
     282, -2211,    68,   511,    23, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,    85,
      19, -2211, -2211,   215, -2211,   519, -2211,   553, -2211,   555,
   -2211,   560, -2211,   570, -2211,   585, -2211,   592, -2211,   389,
   -2211,   422, -2211, -2211,   450, -2211, -2211,   455, -2211, -2211,
     460, -2211, -2211,   462, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,   166,
     623,    50, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,   164,   132, -2211, -2211,   625, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,   475, -2211,   389, -2211, -2211,
   -2211, -2211,   435, -2211,   489,   635,   215, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,   149, -2211, -2211, -2211, -2211,
      15, -2211, -2211, -2211, -2211,    14, -2211, -2211, -2211, -2211,
       7, -2211, -2211, -2211, -2211,    -1, -2211, -2211, -2211, -2211,
     139, -2211, -2211, -2211, -2211,   114, -2211, -2211, -2211, -2211,
   -2211,   640, -2211,   375,   388,   394,   396,   399, -2211, -2211,
   -2211,    35, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,   227,   571, -2211, -2211,   642, -2211,   645,
   -2211,   647, -2211,   649, -2211,   651, -2211,   389, -2211, -2211,
     117, -2211, -2211, -2211, -2211,   535,   228,   542,   228,   544,
     228,   547, -2211,   670, -2211,   563,     0,   567,   569,   125,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211,   525, -2211, -2211,
     226, -2211, -2211,   252, -2211, -2211,   256, -2211, -2211,   268,
   -2211, -2211,   523, -2211, -2211,   513,   595,   -43, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211,   675,   161, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211,   302,   503, -2211, -2211,   679, -2211,   697, -2211,   699,
   -2211,   705, -2211,   711, -2211,   591, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,   475, -2211,   389, -2211, -2211,   213, -2211,
   -2211, -2211, -2211,   118, -2211, -2211, -2211, -2211,   106, -2211,
   -2211, -2211, -2211,   109, -2211, -2211, -2211, -2211,   155, -2211,
   -2211, -2211, -2211,   715, -2211, -2211, -2211,   536,   724, -2211,
   -2211,   641, -2211, -2211, -2211, -2211, -2211,   724, -2211, -2211,
   -2211, -2211,   724, -2211, -2211, -2211, -2211,   667, -2211,   -32,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,   618,   594, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,   634,
     363, -2211, -2211,   -25, -2211, -2211, -2211, -2211, -2211,   704,
     710,   712, -2211, -2211, -2211, -2211, -2211, -2211, -2211,   124,
   -2211, -2211, -2211, -2211,   156, -2211, -2211, -2211, -2211,   150,
   -2211, -2211, -2211, -2211,   170, -2211, -2211, -2211, -2211,   146,
   -2211, -2211, -2211, -2211, -2211,   722, -2211,   728,   228,   730,
     228,   735,   228,   739, -2211,   726, -2211, -2211, -2211,   685,
   -2211, -2211,   718, -2211, -2211,   656, -2211, -2211,   664, -2211,
   -2211, -2211,   690, -2211,    -7, -2211, -2211, -2211, -2211, -2211,
     732, -2211,   764,   747, -2211,   753, -2211, -2211,   786, -2211,
   -2211,   767,   487, -2211, -2211, -2211, -2211, -2211,   766,   458,
   -2211, -2211, -2211,   768,   415, -2211, -2211,   520,   264, -2211,
   -2211,   852,   856,   858,   871, -2211, -2211,   793, -2211, -2211,
     833, -2211, -2211,   847, -2211, -2211,   866, -2211, -2211,   829,
     921,   288, -2211, -2211, -2211, -2211,   724, -2211, -2211, -2211,
   -2211,   724, -2211, -2211, -2211, -2211,   724, -2211, -2211, -2211,
   -2211,   925, -2211,     5, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,   867,   599, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,   770,   415,   843, -2211,
   -2211, -2211,   934, -2211, -2211, -2211, -2211, -2211,   600, -2211,
   -2211, -2211,   942, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,   916,   938,   315, -2211,   943,   945,   949,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,   859,   873,
   -2211, -2211,   862, -2211,   854, -2211,   868, -2211, -2211,   872,
   -2211, -2211,   927,   630, -2211, -2211, -2211, -2211,   772,   415,
     650, -2211, -2211, -2211, -2211, -2211, -2211, -2211,   993, -2211,
     995, -2211,   775, -2211,   912, -2211,  1002,  1006, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
     281, -2211, -2211, -2211, -2211, -2211, -2211,   778,   415,   668,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1007,
     232, -2211, -2211, -2211, -2211, -2211,   954,   215, -2211, -2211,
    1011,   119, -2211, -2211,  1016, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,   696, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,   969,   958, -2211, -2211,
   -2211,   737,   795,   797,   215, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,   953, -2211,  1041, -2211, -2211,
   -2211, -2211,   801,   253, -2211,   774,  1026,   298, -2211, -2211,
   -2211, -2211,   350, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211,   241, -2211, -2211, -2211, -2211,  1060, -2211, -2211, -2211,
   -2211, -2211, -2211,   776,  1048, -2211,   803, -2211, -2211, -2211,
    1010, -2211, -2211,   988,   991, -2211, -2211, -2211, -2211,  1077,
   -2211,  1000,   208, -2211, -2211, -2211, -2211,  1080, -2211,   804,
    1069, -2211,   807, -2211,  1086,   951, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,   809,   283, -2211,   939, -2211, -2211,  1099,
   -2211,  1038,  1082, -2211,   811, -2211,  1107,   970, -2211, -2211,
   -2211, -2211, -2211, -2211,   810,  1012,   907,  1035, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,  1047,  1105, -2211,   815,
   -2211,  1127,  1084, -2211, -2211, -2211, -2211, -2211, -2211,   832,
    1094,   930, -2211, -2211, -2211,  1098,   907,  1137,   820, -2211,
   -2211, -2211, -2211,   822, -2211,  1141,   863, -2211, -2211, -2211,
   -2211, -2211, -2211,   850,  1108,   947, -2211, -2211, -2211, -2211,
     826,  1149,   884, -2211, -2211, -2211,   886,   967, -2211,  1153,
     -50, -2211, -2211, -2211, -2211,  1155,   390, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211,  1133, -2211, -2211, -2211, -2211,   978,
    1157,   980, -2211,   825,   845, -2211, -2211, -2211, -2211,  1167,
     -51, -2211, -2211, -2211, -2211,   835,   845, -2211, -2211, -2211,
   -2211,   -34, -2211, -2211, -2211, -2211,  1171, -2211, -2211,  1037,
     875, -2211, -2211, -2211, -2211, -2211,  1113,  1118, -2211, -2211,
   -2211,   -28, -2211,  1158, -2211,   849,   845, -2211, -2211, -2211,
   -2211,  1183,    -2, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211,  1147,   877, -2211,  1036,  1189, -2211, -2211,  1055,   901,
   -2211, -2211, -2211, -2211, -2211,  1163,   877, -2211, -2211, -2211,
    1103,   905, -2211, -2211, -2211, -2211, -2211,    34, -2211, -2211,
   -2211,  1304,   506, -2211, -2211, -2211,  1211,  1074, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,  1180,   877, -2211,  1220, -2211,
   -2211,  1178,   936, -2211, -2211,  1306,   632, -2211, -2211,   908,
   -2211,  1036,  1228,  1308, -2211, -2211, -2211, -2211,    73,  1310,
     528, -2211,   908, -2211, -2211, -2211,    47,   724,  1230, -2211,
   -2211, -2211, -2211,    66, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1022,  1312,   721,
   -2211,   908, -2211, -2211, -2211, -2211,   122,   -95, -2211, -2211,
   -2211, -2211,  1234, -2211,  1241, -2211,  1243, -2211,  1245, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,   932, -2211,  1036,  1314,
    1244,  1097, -2211, -2211, -2211, -2211,   724, -2211, -2211, -2211,
   -2211,   -79, -2211, -2211, -2211, -2211, -2211,  1253, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
     932, -2211,    16, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
     972,  1252, -2211, -2211,  1272, -2211,  1213,   270, -2211, -2211,
   -2211, -2211, -2211,  -148,  1273,  1316, -2211,   -59, -2211, -2211,
   -2211, -2211, -2211,  1282, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,   932, -2211,   724, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,   944,   987, -2211, -2211,
    1140, -2211, -2211,  1287,  1289,  1291,  1295, -2211,   977, -2211,
    1036,  1318,  1097, -2211, -2211, -2211, -2211,  1299,  1058, -2211,
    1160, -2211,   984,  1045, -2211, -2211, -2211,  1003,  1044, -2211,
   -2211,  1162, -2211, -2211,  1344,   977, -2211, -2211, -2211,  1049,
   -2211,  1346, -2211,  1203, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211,  1356, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
    1021,  1068, -2211, -2211,  1217, -2211, -2211,  1362,   977, -2211,
    1073, -2211, -2211,    63, -2211,  1320,   211,  1366, -2211, -2211,
   -2211, -2211,  1050, -2211,  1036,  1322,  1097, -2211, -2211, -2211,
   -2211, -2211,  1059, -2211,  1370,  1324, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,   120, -2211,  1326,   211, -2211,  1050, -2211,
   -2211, -2211, -2211,  1328,   336,  1376,   -45, -2211, -2211,   135,
   -2211,  1330,   211, -2211,  1050, -2211, -2211,    42, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,  1097, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,  1054, -2211,  1036,  1332,
    1097, -2211, -2211, -2211, -2211, -2211,  1063, -2211,  1384,   100,
   -2211, -2211, -2211, -2211,  1381,  1219,    37, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211,  1097, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,  1054, -2211,   -48, -2211, -2211, -2211, -2211,
   -2211,  1391, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
      20, -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1097, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1054, -2211, -2211,
   -2211, -2211, -2211,  1095, -2211,  1248, -2211, -2211, -2211, -2211,
    1036,  1445,  1097, -2211, -2211, -2211, -2211, -2211,  1081, -2211,
    1396,  1250, -2211,  1404, -2211,  1408,  1410, -2211, -2211, -2211,
   -2211,  1115, -2211,  1260, -2211, -2211, -2211, -2211, -2211,  1083,
    1132,  1277, -2211, -2211, -2211,  1416,  1447,   446, -2211,  1131,
   -2211,  1280, -2211, -2211, -2211, -2211, -2211,  1449,  1097, -2211,
   -2211, -2211, -2211, -2211,  1109, -2211, -2211, -2211,  1284,  1430,
    1434, -2211, -2211, -2211, -2211, -2211,  1451,   211, -2211,  1197,
   -2211, -2211, -2211, -2211, -2211,  1441,  1438,  1440, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
    1097, -2211, -2211, -2211, -2211, -2211,  1119, -2211, -2211,  1444,
    1484,  1097, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211,  1237, -2211, -2211,  1498,  1521,  1522,  1523, -2211,  1198,
   -2211, -2211, -2211,  1378, -2211, -2211,   584,  1453,   761, -2211,
    1524,  1525, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,  1292, -2211,  1333,  1290,
   -2211, -2211, -2211,  1533,  1529,  1530,  1531,  1532,  1534,  1535,
    1536,  1537, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1538,   243,  1539,
     243,  1540,   243,  1541,   243,  1542,   243,  1543,   243,  1544,
     243,  1545,   243,  1546,   243, -2211,  1555,  1548, -2211, -2211,
   -2211,  1552,  1550, -2211, -2211, -2211,  1556,  1557,  1558,  1559,
    1560,  1561,  1562,   724,  1267, -2211,  1566,  1563, -2211, -2211,
   -2211, -2211, -2211,  1267, -2211, -2211, -2211,  1267, -2211, -2211,
   -2211,  1267, -2211, -2211, -2211,  1267, -2211, -2211, -2211,  1267,
   -2211, -2211, -2211,  1267, -2211, -2211, -2211,  1267, -2211, -2211,
   -2211,  1267, -2211, -2211, -2211,  1564,   433,  1567,  1296, -2211,
   -2211,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575, -2211,
   -2211,   185,  1457,  1576,  1579,  1271, -2211,  1271, -2211,  1271,
   -2211,  1271, -2211,  1271, -2211,  1271, -2211,  1271, -2211,  1271,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211,  1265, -2211, -2211, -2211,  1336, -2211,  1340, -2211,  1341,
   -2211,   433, -2211,   433, -2211,  1043, -2211,   433, -2211,  1123,
   -2211,  1123, -2211,  1459, -2211,   433, -2211,   433, -2211,   433,
   -2211,   433, -2211, -2211,   433, -2211,  1043, -2211,   433,  1580,
   -2211,  1335,  1036, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211,  1334,  1311,  1461,  1097, -2211, -2211, -2211, -2211,
   -2211,  1582,  1315,  1331,  1317,  1337,  1319,  1325,  1321,  1327,
    1323,  1329,  1338,  1339,  1342,  1343,  1345,  1348, -2211, -2211,
   -2211,     1,  1595,  1463,  1597,  1465,  1598,  1467,  1194, -2211,
     433, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1168,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,  1043, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
    1165, -2211,  1607,  1600, -2211,  1601, -2211,  1192, -2211, -2211,
     433, -2211,  1190, -2211,   433, -2211,   433, -2211,   654, -2211,
    1043, -2211,  1177, -2211, -2211, -2211, -2211,  1036,  1469, -2211,
   -2211, -2211, -2211,  1471,  1097, -2211, -2211, -2211, -2211, -2211,
   -2211,  1347, -2211, -2211, -2211,  1473, -2211, -2211, -2211,  1475,
   -2211, -2211, -2211,  1477, -2211, -2211, -2211,  1479, -2211, -2211,
   -2211,  1483, -2211, -2211, -2211,  1485, -2211, -2211, -2211,  1487,
   -2211, -2211, -2211,  1489, -2211,   333,  1179, -2211,  1609,  1616,
   -2211, -2211, -2211, -2211,  1618,  1349, -2211, -2211,  1619,  1350,
   -2211, -2211,  1620,  1351, -2211, -2211, -2211,  1212,  1043,  1043,
    1043,  1043,  1043,  1043, -2211, -2211,  1043,  1043,  1043,  1043,
    1043,  1043, -2211,  1043, -2211, -2211, -2211,  1491,  1493,  1043,
     433,   433,   433, -2211,  1239,    11, -2211,  1621,   433,   433,
   -2211,  1207, -2211,  1204,  1205, -2211, -2211, -2211, -2211, -2211,
   -2211,  1622, -2211, -2211, -2211,  1199, -2211, -2211, -2211, -2211,
    1624, -2211,  1625, -2211, -2211,  1626, -2211,  1628, -2211,  1629,
   -2211,  1630, -2211,  1631,  1043, -2211,  1261,  1499, -2211,  1097,
   -2211, -2211, -2211, -2211,  1488, -2211, -2211, -2211, -2211, -2211,
    1367, -2211,  1097, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211,  1097, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,  1640,  1639,  1641, -2211,  1642,
   -2211,  1643, -2211, -2211,  1043,  1043,  1043,  1043,  1286,  1283,
     695,   758,  1279,  1278,  1043,  1275,  1274,  1276,    71,  1268,
     814,   865,   904,  1259, -2211, -2211,  1262, -2211, -2211,  1043,
    1255,  1251,  1254, -2211, -2211,  1263, -2211,  1661, -2211, -2211,
   -2211, -2211, -2211, -2211,  1256, -2211,  1257, -2211, -2211, -2211,
   -2211, -2211, -2211,  1501,  1285,  1043,   654,   654,   654,   654,
     654,   654,  1043, -2211, -2211, -2211, -2211, -2211,  1097, -2211,
   -2211, -2211, -2211, -2211,  1418,  1058, -2211,  1518, -2211,  1392,
   -2211, -2211,  1393,  1395,  1526,   -26,   -20, -2211,  1398,   -19,
     -12, -2211,  1547,  1399,  1662, -2211, -2211, -2211, -2211,  1352,
    1353,  1354,  1355, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211,  1043, -2211, -2211, -2211,   989, -2211,  1671,  1672, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211,  1281, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211,  1231, -2211, -2211,  1673,  1675, -2211, -2211, -2211,  1043,
   -2211,   654, -2211,   654, -2211,  1236, -2211,  1242, -2211,   654,
   -2211,  1233, -2211,   433,  1505,   403, -2211,  1433, -2211,  1507,
   -2211, -2211,  1454, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211,  1509, -2211, -2211, -2211,  1511, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1454, -2211,
   -2211, -2211, -2211, -2211, -2211,  1313, -2211, -2211,  1683,   724,
   -2211,  1685,   550, -2211,   724,   724,  1238,  1247,  1258, -2211,
   -2211,  1232, -2211,  1266,  1197, -2211, -2211, -2211, -2211,  1686,
    1687, -2211, -2211, -2211, -2211, -2211, -2211,   104, -2211, -2211,
   -2211, -2211,  1691, -2211,  1513,    72,  1043, -2211, -2211, -2211,
   -2211,   424, -2211, -2211, -2211, -2211,    44,   137,  1692, -2211,
   -2211,  1357,  1689,  1690, -2211, -2211, -2211,  1696,  1698, -2211,
   -2211, -2211, -2211, -2211,  1458,  1702,  1703,  1554, -2211,   724,
   -2211, -2211, -2211, -2211, -2211, -2211,  1705,  1707, -2211, -2211,
   -2211,  1577,  1578,  1704, -2211,  1713, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,  1581, -2211, -2211, -2211, -2211, -2211, -2211,
    1714, -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1711,  1715,
   -2211,  1583,     6,  1716,   724, -2211, -2211,  1584,  1717, -2211,
    1585, -2211, -2211, -2211, -2211, -2211, -2211,  1486,  1718,  1721,
   -2211, -2211, -2211,  1722,  1710, -2211, -2211, -2211,   724,  1726,
   -2211,  1728,  1456, -2211, -2211
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
     999,  1497,     0,  1533,     0,     0,    40,    41,    45,    44,
    1495,  1496,    43,  1531,  1532,     0,    68,    63,    65,    66,
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
    1537,     0,   169,   171,   170,  1535,  1536,     0,   174,   178,
     180,   179,     0,   183,   187,   189,   188,     0,   192,     0,
     204,   198,   201,   202,   999,   998,  1001,  1002,  1003,  1004,
    1000,  1498,  1534,    48,    55,     0,    51,    52,    57,    69,
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
    1538,   181,   190,   196,   205,   208,     0,   211,     0,    62,
      54,  1509,     0,    58,    60,    59,  1507,  1508,     0,   139,
     130,  1541,     0,   134,   137,   135,   136,  1539,  1540,   454,
     948,   457,   455,     0,     0,   460,   999,     0,     0,     0,
     325,   333,   341,   349,   357,   999,   371,   364,     0,   367,
     368,   372,     0,   394,     0,   403,     0,   412,   418,     0,
     424,   431,     0,   427,   428,   433,   283,   286,     0,   289,
       0,   218,   209,   213,   216,   214,   215,    61,     0,   138,
       0,   999,     0,   949,     0,   458,     0,     0,   999,   462,
     463,   464,   465,   989,  1452,  1458,  1463,   992,   366,   369,
       0,   393,   402,   411,   417,   426,   429,     0,   432,     0,
     296,   287,   291,   294,   292,   293,   217,  1510,  1542,     0,
       0,   953,   947,   950,   951,   471,   495,     0,   999,   999,
       0,     0,   381,  1489,     0,   373,   370,   378,   379,   376,
    1487,  1488,   377,   375,   374,     0,   439,   430,   434,   437,
     435,   436,   295,   999,   952,   959,     0,   955,   956,   961,
     497,   504,     0,     0,   472,   473,   477,   476,   475,   468,
     467,   999,   385,   384,   380,     0,   383,     0,   438,   990,
     954,   957,     0,   960,   506,   631,   507,     0,   501,   496,
     498,   499,     0,   481,   470,   478,   479,   474,   466,   382,
    1490,     0,   970,   958,   967,   968,     0,   962,   966,   964,
     965,   963,   633,   734,   634,   999,     0,   508,   503,   500,
       0,   480,   487,     0,   483,   484,   489,   969,   979,     0,
     978,     0,   972,   973,   975,   976,   977,     0,   736,   837,
     737,   999,     0,   635,     0,   514,   511,   505,   509,   510,
     502,   482,   485,     0,   488,   981,     0,   971,   974,     0,
     839,   909,   840,   999,     0,   738,     0,   641,   638,   632,
     636,   637,   999,   516,     0,   533,     0,     0,   494,   486,
     490,   492,   491,   980,  1455,   911,     0,     0,   999,     0,
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
       0,   542,   543,   547,  1461,   522,   525,     0,   987,   917,
     920,     0,   923,   908,   845,   907,     0,   855,   852,   847,
     850,   851,   788,   786,   790,     0,   773,   772,     0,   750,
     757,     0,   753,   754,   758,     0,   686,   666,  1099,   672,
     671,     0,     0,     0,  1140,  1457,   649,   652,     0,     0,
     583,   563,   569,   568,   541,   544,     0,     0,     0,   529,
     526,   530,   531,     0,   934,   921,   931,   932,   925,   930,
     928,   929,   926,   927,   999,   857,   866,     0,     0,   789,
     769,   775,   774,  1451,   752,   755,     0,     0,   701,   684,
     698,   699,     0,  1525,     0,  1501,     0,  1513,     0,   688,
     690,   689,   697,   696,  1499,  1500,   693,   695,  1511,  1512,
     692,  1523,  1524,   694,   691,  1106,   674,   673,     0,     0,
       0,  1052,  1095,  1091,  1093,  1094,     0,   656,   653,   657,
     658,     0,   598,   581,   595,   596,  1549,     0,   585,   587,
     586,   594,   593,   590,   589,   591,   588,   592,  1547,  1548,
     571,   570,     0,   554,   548,   545,   551,   552,   549,   550,
       0,     0,   933,   943,     0,   942,     0,   936,   937,   939,
     940,   941,   984,     0,     0,     0,   858,     0,   804,   787,
     801,   802,  1493,     0,   791,   792,   793,   798,  1491,  1492,
     800,   799,   796,   795,   797,   794,   777,   776,     0,   759,
     756,   760,   761,   722,   708,   700,     0,   703,   705,   709,
     704,   719,   724,     0,     0,     0,     0,  1113,   676,   675,
       0,     0,  1052,  1102,  1098,  1100,  1101,     0,     0,  1097,
    1050,  1051,     0,     0,   619,   605,   597,     0,   600,   602,
     606,   601,   616,   621,     0,   573,   572,   556,   553,     0,
     532,     0,   945,     0,   935,   938,   854,   869,   853,   867,
     871,     0,   864,   861,   856,   859,   860,   825,   811,   803,
       0,   806,   808,   812,   807,   822,   827,     0,   779,   778,
       0,   702,   706,     0,   720,     0,   723,     0,  1526,  1502,
    1514,  1120,   678,   677,     0,     0,  1052,  1109,  1105,  1107,
    1108,  1104,     0,  1453,     0,     0,  1055,  1053,  1057,  1096,
     659,   599,   603,     0,   617,     0,   620,  1550,   575,   574,
     555,  1472,   944,     0,   870,     0,     0,   805,   809,     0,
     823,     0,   826,  1494,   781,   780,   762,     0,   716,   710,
     707,   713,   714,   711,   712,  1052,   731,   721,   729,   730,
     725,   726,   728,   727,  1454,  1127,   680,   679,     0,     0,
    1052,  1116,  1112,  1114,  1115,  1111,     0,  1103,     0,     0,
    1066,  1062,  1063,  1064,     0,  1056,     0,   613,   607,   604,
     610,   611,   608,   609,  1052,   628,   618,   626,   627,   622,
     623,   625,   624,   577,   576,     0,   885,   868,   882,   883,
    1505,     0,   872,   874,   873,   881,   880,   879,  1503,  1504,
     877,   876,   878,   875,  1456,   863,  1142,   862,   865,  1144,
       0,   819,   813,   810,   816,   817,   814,   815,  1052,   834,
     824,   832,   833,   828,   829,   831,   830,   783,   782,   995,
     996,   997,   715,     0,   718,     0,   733,  1134,   667,   681,
       0,     0,  1052,  1123,  1119,  1121,  1122,  1118,     0,  1110,
       0,     0,  1065,     0,  1054,     0,     0,  1058,  1060,  1059,
     612,     0,   615,     0,   630,   564,   578,   894,   884,     0,
     888,   887,   891,   896,   889,     0,     0,  1143,   818,     0,
     821,     0,   836,   770,   784,   717,   732,     0,  1052,  1130,
    1126,  1128,  1129,  1125,     0,  1117,  1464,  1067,     0,     0,
       0,   614,   629,   886,   890,   892,     0,   895,  1506,  1157,
    1154,  1141,  1152,  1153,  1529,     0,     0,     0,   999,  1145,
    1148,  1147,  1151,  1149,  1146,  1527,  1528,  1150,   820,   835,
    1052,  1137,  1133,  1135,  1136,  1132,     0,  1124,  1061,     0,
       0,  1052,   903,   893,   901,   902,   897,   898,   900,   899,
    1159,     0,  1174,  1161,     0,     0,     0,     0,  1139,     0,
    1131,  1473,  1475,     0,   905,  1155,  1156,     0,  1160,  1530,
       0,     0,   999,  1138,   904,  1414,  1188,  1365,  1220,  1237,
    1339,  1322,  1274,  1298,  1392,  1409,  1175,  1176,  1190,  1179,
    1222,  1182,  1239,  1183,  1276,  1184,  1300,  1180,  1324,  1181,
    1341,  1177,  1367,  1178,  1394,  1185,  1410,  1186,     0,     0,
    1173,  1158,  1485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1162,  1163,  1166,  1167,  1168,  1169,  1164,  1165,
    1171,  1170,  1483,  1484,  1450,  1459,  1474,     0,  1189,     0,
    1221,     0,  1238,     0,  1275,     0,  1299,     0,  1323,     0,
    1340,     0,  1366,     0,  1393,  1521,     0,     0,  1411,  1519,
    1520,     0,     0,  1415,  1172,   999,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1517,     0,     0,  1191,  1192,
    1193,  1515,  1516,     0,  1223,  1224,  1225,     0,  1240,  1241,
    1242,     0,  1277,  1278,  1279,     0,  1301,  1302,  1303,     0,
    1325,  1326,  1327,     0,  1342,  1343,  1344,     0,  1368,  1369,
    1370,     0,  1395,  1396,  1397,     0,     0,     0,     0,  1413,
    1486,     0,     0,     0,     0,     0,     0,     0,     0,  1198,
    1187,  1195,     0,     0,     0,  1204,  1219,  1204,  1236,  1204,
    1273,  1204,  1297,  1204,  1321,  1204,  1338,  1204,  1364,  1204,
    1391,  1522,  1696,  1701,  1706,  1711,  1714,  1723,  1728,  1734,
    1738,  1741,  1744,  1747,  1749,  1754,  1757,  1760,  1686,  1717,
    1720,     0,  1666,  1687,  1667,     0,  1668,     0,  1669,     0,
    1670,     0,  1671,     0,  1684,     0,  1672,     0,  1673,  1724,
    1674,  1729,  1675,     0,  1676,     0,  1677,     0,  1678,     0,
    1679,     0,  1680,  1681,     0,  1682,     0,  1683,     0,     0,
    1419,     0,     0,  1465,  1476,  1477,  1466,  1467,  1468,  1469,
    1482,  1206,     0,     0,     0,  1052,  1201,  1197,  1199,  1200,
    1518,     0,  1228,     0,  1245,     0,  1282,     0,  1306,     0,
    1330,     0,  1347,     0,  1373,     0,  1400,     0,  1751,  1412,
    1408,     0,     0,     0,     0,     0,     0,     0,     0,  1710,
       0,  1713,  1596,  1588,  1590,  1594,  1598,  1600,  1646,  1662,
    1608,  1592,  1615,  1602,  1604,  1606,  1634,  1611,  1613,  1654,
    1650,  1658,  1578,  1582,  1586,  1624,  1617,  1619,  1621,     0,
    1572,  1573,  1553,  1554,  1556,  1557,  1558,  1559,  1561,  1562,
    1563,  1565,  1564,  1566,  1568,     0,  1569,  1567,  1575,  1576,
    1577,  1551,  1627,  1552,  1555,  1574,  1570,  1571,  1560,  1716,
       0,  1719,     0,     0,  1725,     0,  1730,     0,  1735,  1733,
       0,  1737,     0,  1740,     0,  1743,     0,  1746,     0,  1753,
       0,  1756,     0,  1759,  1449,  1427,  1434,     0,     0,  1420,
    1194,  1213,  1196,     0,  1052,  1209,  1205,  1207,  1208,  1203,
    1049,     0,  1460,  1230,  1227,     0,  1226,  1247,  1244,     0,
    1243,  1284,  1281,     0,  1280,  1308,  1305,     0,  1304,  1332,
    1329,     0,  1328,  1349,  1346,     0,  1345,  1375,  1372,     0,
    1371,  1402,  1399,     0,  1398,     0,     0,  1691,     0,     0,
    1688,  1685,  1689,  1690,     0,     0,  1697,  1695,     0,     0,
    1702,  1700,     0,     0,  1707,  1705,  1712,     0,     0,     0,
       0,     0,     0,     0,  1648,  1664,     0,     0,     0,     0,
       0,     0,  1640,     0,  1656,  1652,  1660,     0,     0,     0,
       0,     0,     0,  1718,     0,     0,  1721,     0,     0,     0,
    1736,     0,  1742,     0,     0,  1799,  1793,  1796,  1774,  1786,
    1805,     0,  1802,  1783,  1762,     0,  1763,  1764,  1778,  1765,
       0,  1766,     0,  1767,  1768,     0,  1769,     0,  1770,     0,
    1771,     0,  1772,     0,     0,  1761,     0,     0,  1428,  1052,
    1423,  1418,  1421,  1422,  1070,  1216,  1212,  1214,  1215,  1211,
       0,  1202,  1052,  1233,  1229,  1231,  1232,  1253,  1250,  1246,
    1248,  1249,  1289,  1287,  1283,  1285,  1286,  1313,  1311,  1307,
    1309,  1310,  1052,  1335,  1331,  1333,  1334,  1354,  1352,  1348,
    1350,  1351,  1380,  1378,  1374,  1376,  1377,  1084,  1405,  1401,
    1403,  1404,  1750,  1752,  1692,     0,     0,     0,  1698,     0,
    1703,     0,  1708,  1715,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1580,  1579,     0,  1584,  1583,     0,
       0,     0,     0,  1612,  1610,     0,  1625,     0,  1629,  1630,
    1623,  1628,  1631,  1732,     0,  1722,     0,  1727,  1739,  1745,
    1748,  1788,  1755,     0,  1777,     0,     0,     0,     0,     0,
       0,     0,     0,  1417,  1437,  1416,  1435,  1439,  1052,  1431,
    1426,  1429,  1430,  1425,     0,     0,  1218,  1068,  1069,     0,
    1210,  1235,     0,     0,  1252,     0,     0,  1337,     0,     0,
       0,  1407,  1083,     0,     0,  1694,  1699,  1704,  1709,     0,
       0,     0,     0,  1599,  1601,  1647,  1649,  1663,  1665,  1609,
    1593,     0,  1603,  1605,  1607,     0,  1636,     0,     0,  1635,
    1641,  1642,  1643,  1614,  1655,  1657,  1651,  1653,  1659,  1661,
    1581,  1585,     0,  1618,  1620,  1622,  1626,  1632,  1726,  1731,
    1790,     0,  1775,  1773,     0,     0,  1781,  1780,  1779,     0,
    1782,     0,  1785,     0,  1792,     0,  1795,     0,  1798,     0,
    1801,     0,  1804,     0,     0,  1438,  1433,     0,  1424,     0,
    1073,  1071,  1074,  1217,  1234,  1251,  1256,  1254,  1258,  1292,
    1288,  1290,     0,  1316,  1312,  1314,     0,  1336,  1357,  1353,
    1355,  1358,  1383,  1379,  1381,  1384,  1087,  1085,  1088,  1406,
    1693,  1597,  1589,  1591,  1595,     0,  1637,  1638,     0,     0,
    1587,     0,     0,  1776,     0,     0,     0,     0,     0,  1797,
    1800,     0,  1806,     0,  1157,  1447,  1436,  1445,  1446,     0,
       0,  1440,  1441,  1442,  1443,  1444,  1432,     0,  1081,  1077,
    1078,  1079,     0,  1075,     0,  1257,     0,  1295,  1291,  1293,
    1294,     0,  1319,  1315,  1317,  1318,     0,     0,     0,  1089,
    1616,     0,     0,     0,  1633,  1789,  1791,     0,     0,  1784,
    1787,  1794,  1803,  1758,     0,     0,     0,     0,  1080,     0,
    1072,  1266,  1264,  1255,  1262,  1263,     0,     0,  1259,  1260,
    1261,     0,     0,     0,  1545,     0,  1359,  1356,  1362,  1361,
    1360,  1543,  1544,     0,  1390,  1385,  1382,  1388,  1387,  1386,
       0,  1086,  1639,  1645,  1644,  1481,  1480,  1448,     0,     0,
    1082,     0,     0,     0,     0,  1296,  1320,     0,     0,  1389,
       0,  1470,  1471,  1076,  1265,  1269,  1267,  1270,     0,     0,
    1363,  1546,  1090,     0,     0,  1271,  1462,  1479,     0,     0,
    1268,     0,     0,  1478,  1272
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1699, -2211,
    1720, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1678,
   -2211, -2211, -2211, -2211,  1586, -2211, -2211, -2211, -2211, -2211,
    1358, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,  1359, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1606,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
    1229, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,  1519, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211,  1161, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,  1436, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211,  1110, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211,  1093, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,  1222, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,   997, -2211, -2211, -2211,
   -2211, -2211,   940, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,   773,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211,   725, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211,   484, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,   486, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211,   736, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,   521, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211,   522, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,   698,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,   465, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211,   457, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,   248,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,   780, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,   566, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211,  1018, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211,   946, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
     -58, -2211, -2211, -2211, -2211,  -582, -2211,  -368, -1249,  -198,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -1896, -1141, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,  -799,
   -2211, -2211, -2211, -2211, -2211,  -708, -2211, -2211, -2211, -2211,
   -2211,  -811, -2211, -2211, -2211, -2211, -2211,  -910, -2211, -2211,
   -2211, -2211, -2211, -1117, -2211, -2211, -2211, -2211, -2211, -1103,
   -2211, -2211, -2211, -2211, -2211, -1239, -2211, -2211, -2211, -2211,
   -2211, -1055, -1306, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
    -645, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,  -995, -2211, -2211, -2211,
   -2211, -2211,  -870, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211,   661, -2211, -1309, -1046,
     729,   418,   707, -2211, -2211,  -717,  -815, -2211, -2211,  -491,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -1001,  -671, -2211,
   -2210, -2211, -2211, -2211, -2211,  -670,  -669, -2211, -2211, -2211,
   -2211,  -721, -2211, -2211, -2211, -2211, -2211,  -141, -2211, -2211,
   -1041, -2211, -2211, -2211, -2211, -2211,  -518, -2211, -2211, -2211,
   -2211, -2211,  -657, -2211, -2211, -2211, -2211, -2211, -1040, -2211,
   -2211,  -579, -2211, -2211,  -689, -2211, -2211,  -218, -2211, -2211,
    -592, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -1660,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -1806, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211,   -49, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -1816,  -661, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211, -2211,
   -2211, -2211, -2211
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
    1999,  2000,  1260,  1337,  1338,  1404,  1405,  1497,  1494,  1261,
    1401,  1402,  1403,  2266,  2267,  2361,  2362,  2432,  2470,  2268,
    2429,  2430,  2431,  2281,  2282,  2387,  2388,  2448,  2501,  1013,
    1014,  1153,  1154,  1155,  1262,  1070,  1071,  1254,  1255,  1256,
    1332,  1147,  1148,  1328,  1329,  1330,  1396,  1249,  1250,  1392,
    1393,  1394,  1488,  1323,  1324,  1484,  1485,  1486,  1534,  1387,
    1388,  1530,  1531,  1532,  1576,  1479,  1480,  1572,  1573,  1574,
    1599,  1073,  1448,  1449,  1516,  1517,  1559,  1551,  1552,  1553,
    1591,  1592,  1593,  1607,  1608,  1662,  1651,  1606,  1626,  1627,
    1628,  1677,  1678,  1718,  1770,  1862,  1771,  1772,  1867,  1868,
    1869,  2001,  1863,  1864,  1996,  1997,  1998,  2140,  1992,  1993,
    2136,  2137,  2138,  2269,  1629,  1630,  1679,  1680,  1724,  1776,
    1873,  2004,  2005,  2144,  2145,  2146,  2272,  1631,  1632,  1681,
    1682,  1728,  1778,  1875,  2008,  2009,  2149,  2150,  2151,  2273,
    2274,  2367,  2368,  2434,  2435,  2478,  2473,  2474,  2475,  2512,
    2526,  2527,  2534,  2540,  1633,  1634,  1683,  1684,  1732,  1780,
    1877,  2012,  2013,  2154,  2155,  2156,  2275,  2371,  2372,  2438,
    2439,  2440,  1635,  1636,  1685,  1686,  1736,  1782,  1879,  2016,
    2017,  2159,  2160,  2161,  2276,  2375,  2376,  2443,  2444,  2445,
    1637,  1638,  1687,  1688,  1740,  1784,  1881,  2020,  2021,  2164,
    2165,  2166,  2278,  1639,  1640,  1689,  1690,  1744,  1786,  1883,
    2024,  2025,  2169,  2170,  2171,  2279,  2380,  2381,  2446,  2486,
    2487,  1641,  1642,  1691,  1692,  1748,  1788,  1885,  2028,  2029,
    2174,  2175,  2176,  2280,  2384,  2385,  2447,  2495,  2496,  1643,
    1644,  1693,  1694,  1752,  1790,  1887,  2032,  2033,  2179,  2180,
    2181,  2283,  1645,  1646,  1697,  1890,  1647,  1648,  1702,  1759,
    2255,  1851,  1852,  1988,  2131,  2132,  2133,  2264,  1986,  1987,
    2127,  2260,  2261,  2262,  2357,  2126,  2256,  2257,  2354,  2355,
    2421,  2416,  2417,  2418,  1703,  1560,   952,   434,  1074,  1130,
     798,  1206,   923,   435,  1561,  1719,   899,  2479,   436,  1335,
    1663,  1664,  1665,  1666,  1667,  2422,  2423,  1091,  1498,  1562,
    1499,  1668,  1669,  2535,  2480,  2336,  2337,  1670,  1671,  1672,
    1673,   729,   730,   731,  1217,  1218,  1219,   159,   160,   161,
    1133,  1134,  1135,  1437,  1438,  1439,   605,   606,   607,  1137,
    1138,  1139,  1720,  1721,  1722,  1698,  1699,  1700,  1140,  1141,
    1142,  1564,  1565,  1566,   162,   163,   164,   374,   375,   376,
     616,   617,   618,  2490,  2491,  2492,  1177,  1178,  1179,  2104,
    1930,  2077,  2215,  1931,  2078,  2218,  1932,  2079,  1933,  2059,
    1934,  2060,  1935,  2067,  1936,  2061,  1937,  2058,  1938,  2062,
    1939,  2063,  1940,  2069,  1941,  2070,  1942,  2071,  1943,  2066,
    1944,  1945,  2224,  1946,  2073,  1947,  2068,  1948,  2080,  1949,
    2081,  1950,  2082,  1951,  1952,  2230,  2085,  2231,  2232,  2401,
    1953,  2072,  2309,  2451,  2208,  2310,  2311,  2312,  1954,  2064,
    2200,  1955,  2075,  2211,  1956,  2074,  2210,  1957,  2076,  2212,
    1958,  2065,  2201,  1811,  1812,  1813,  1891,  2040,  2041,  2042,
    2043,  1814,  1815,  2047,  1893,  1816,  1817,  2051,  1895,  1818,
    1819,  2055,  1897,  1820,  1821,  1899,  1822,  1823,  1901,  1824,
    1825,  1959,  1826,  1827,  1961,  1828,  1829,  1963,  2235,  1830,
    1831,  1965,  2237,  1964,  1832,  1833,  1969,  1834,  1835,  1971,
    1836,  1837,  1973,  1838,  1839,  1975,  1840,  1841,  1977,  1842,
    1888,  2035,  1843,  1844,  1979,  1845,  1846,  1981,  1847,  1848,
    1983,  2105,  2106,  2107,  2108,  2333,  2243,  2244,  2338,  2109,
    2110,  2340,  2111,  2112,  2342,  2113,  2330,  2402,  2114,  2115,
    2344,  2116,  2117,  2346,  2118,  2119,  2348,  2120,  2121,  2350,
    2122,  2123,  2352
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     501,   733,   286,   277,   252,   666,   615,  1381,   395,   504,
    1259,   274,  2036,  2037,   506,  1898,  1149,  1900,   271,   268,
    1277,  1960,  2225,  2226,  1469,   417,  1470,  1471,   758,  1970,
     381,  1972,   386,  1974,  1169,  1976,   509,  1420,  1978,  1172,
    1174,  1469,  1982,  1470,  1471,  1087,  1469,    49,  1470,  1471,
    1059,    50,   799,  1464,   525,  2483,  1233,    51,  1182,  1183,
     126,   583,   127,  1216,   128,   758,   129,   705,  1221,  1223,
     299,    52,  1264,   650,  1367,  1368,    49,  1159,  1028,   665,
      50,   928,  2305,  2306,  1156,  1188,    51,    53,   300,   254,
     130,  1043,  1297,  1251,  2057,  1016,   977,   216,  2139,   217,
      52,  1445,   301,  1507,  1491,   373,   741,   380,  2467,   385,
     302,  1331,   483,   486,   131,  1231,    53,   218,   283,  1514,
     303,   365,   304,  2369,   480,   762,   763,   219,   535,  2373,
    2378,  1406,  1407,  1228,   305,   756,  1192,  2382,   306,  1286,
     307,   704,   308,   280,   309,   220,  1450,  1451,  2493,  2494,
     547,   221,  2433,   265,   541,   872,  2524,  1502,  1349,     6,
     538,   489,   490,    12,  2091,  1929,   481,  1027,  2093,   126,
    2094,   127,   756,   128,   544,   129,     1,     2,  2449,   364,
     740,   153,   154,   403,  1506,  1395,  1980,   428,   643,   611,
     612,  1365,   474,   645,  1287,  1325,   515,  1057,   647,   130,
     548,  1520,   601,   602,  1544,   487,   545,  1234,   484,   366,
     536,   266,   284,   764,   404,   601,   602,   477,   520,  1193,
    1194,   281,  1195,   131,  2484,  2485,   542,  1265,  1524,  2183,
     531,   601,   602,   491,  1476,  2038,  2489,  2497,  1587,  1298,
    1446,   601,   602,  1446,   539,  1424,  2271,   150,  1235,  1487,
     560,  1017,   565,  2370,   570,   801,   978,  1044,  1492,  2374,
    2379,  1468,  2468,   478,  1266,  1170,   550,  2383,  1088,  1389,
    1276,  1181,  1029,  1504,  2220,  2221,  2222,   476,     7,  1495,
    1496,  1088,  2234,  2236,  1299,  2084,  2525,  2476,   601,   602,
     601,   602,   721,   722,   526,  1508,  1060,  1088,    14,   418,
    1227,    54,   808,   601,   602,  2307,   744,  1088,  1433,  2308,
     510,  2477,  1373,  1436,  1441,   745,  1309,  1522,  1083,  1518,
    2124,  1100,    17,  1278,    55,   817,    56,   559,    57,   564,
      58,   569,   676,  1481,   677,   584,   132,   620,    20,    21,
     278,  1533,  1412,   525,  1500,  1472,   275,   651,  1112,   678,
     269,   272,   310,    55,  1088,    56,  1088,    57,  1456,    58,
     809,   818,   819,    30,   820,   222,  2334,  2335,   429,  1088,
    1072,   430,    41,  1496,   431,   151,   152,  1143,   604,   151,
     152,   636,    80,   614,   118,   153,   154,  1575,   637,   611,
     612,  1175,   151,   152,   818,   819,   148,   820,  2194,  2195,
    2196,  2197,  2198,  2199,   370,   371,  2202,  2203,  2204,  2205,
    2206,  2207,   200,  2209,   796,   723,   724,   151,   152,  2219,
    1224,   601,   602,  1193,  1194,  1527,  1195,   203,   683,  1598,
    2341,  2343,  2345,  2347,  2349,  2351,   811,   687,   257,   812,
    1604,  1715,  1716,   723,   724,   151,   152,   151,   152,  1717,
    1103,   153,   154,   153,   154,   204,   664,   370,   371,   984,
     205,  1861,   985, -1204,  2252,   206,  2039,   207,   396,   397,
     398,   399,   734,   709,  1144,    25,    26,   238,  2227,    81,
     720,    82,    83,    84,   208,    85,    86,    87,  1176,    88,
      89,    90,   258,    91,    92,    93,  1122,    94,    95,   292,
     151,   152,  1123,  1124,   601,   602,   153,   154,  1125,  1126,
      33,    34,    44,    45,   611,   612,   293,  1225,   703,  1092,
     759,   760,   121,   122,  1102,  2407,   294,  2408,  1430,  1431,
     165,   166,   295,  2411,  2289,  2290,  2291,  2292,   299,   296,
    2296,  2298,   336,  1989,  2301,   769,   368,  2413,  1136,   732,
    2315,  2317,  2319,   377,  1204,   382,   300,   739,   387,  2322,
    1160,   410,  1173,   788,   170,   171,   175,   176,  1189,   394,
     301,   180,   181,   153,   154,   401,   757,   402,   302,   151,
     152,   185,   186,   601,   602,  2339,  2456,   409,   303,   411,
     304,  1222,  2353,   611,   612,   412,   190,   191,  1232,  1554,
    1555,   416,   305,   195,   196,   414,   306,   834,   307,   413,
     308,   415,   309,   757,   601,   602,   153,   154,   216,   437,
     217,  1792,   151,   152,   464,  1793,   601,   602,   499,  1794,
    2419,  2420,   800,   856,   211,   212,   240,   241,   218,   151,
     152,  2395,  1554,  1555,   502,  2397,   259,   260,   219,  1556,
    1557,   287,   288,   338,   339,   881,   343,   344,   348,   349,
     353,   354,   358,   359,   892,  1442,   220,   796,   723,   724,
     151,   152,   221,   507,   601,   602,   516,  1558,  2128,  2406,
     905,   389,   390,   404,   611,   612,   423,   424,  1122,   916,
     439,   440,   151,   152,  1123,  1124,   601,   602,   153,   154,
    1125,  1126,   521,   871,   935,   418,   611,   612,   444,   445,
     449,   450,   532,   945,  1166,  1167,   454,   455,   533,  1190,
     534,  1792,   459,   460,  1383,  1793,   494,   495,  1775,  1794,
     489,   490,  1777,   551,   552,   578,  1779,   573,   574,   556,
    1781,   561,   897,   990,  1783,  1795,   566,  1796,  1785,  1797,
     571,  1798,  1787,  1799,  1422,  1800,  1789,  1801,   580,  1802,
     581,  1803,  1443,  1804,  2182,  1805,   579,  1806,   582,  1807,
    1466,  1808,   590,  1809,   589,  1810,  2481,   598,   599,   608,
     609,   660,   661,   699,   700,  1038,   710,   711,  1263,   735,
     736,   591,  1122,   592,  1046,  1374,   151,   152,  1123,  1124,
     601,   602,   153,   154,  1125,  1126,   777,   778,   782,   783,
     611,   612,   791,   792,   835,   836,  1127,  1128,   857,   858,
     867,   868,   882,   883,   593,  1413,   906,   907,  1567,   510,
    1615,   930,   931,   936,   937,   594,  1440,   954,   955,   619,
    1616,  1457,  1617,   921,  1618,  1795,  1619,  1796,  1620,  1797,
    1621,  1798,  1622,  1799,  1623,  1800,  1624,  1801,   626,  1802,
    1310,  1803,   627,  1804,   628,  1805,  1625,  1806,  2095,  1807,
    2096,  1808,  2097,  1809,  2098,  1810,  2099,   629,  2100,   630,
    2101,  1122,  2102,   634,  2103,   151,   152,  1123,  1124,   601,
     602,   153,   154,  1125,  1126,   960,   961,   966,   967,   611,
     612,  1101,   633,  1212,  1213,  1872,  1202,  1874,  1902,  1876,
    1903,  1878,  1904,  1880,  1905,  1882,  1906,  1884,  1907,  1886,
    1908,   631,  1909,   632,  1910,  1132,  1911,   635,  1912,   950,
    1913,   648,  1914,   667,  1915,   656,  1916,   668,  1917,  1171,
    1918,   584,  1919,   669,  1920,   670,  1921,   671,  1922,   674,
    1923,   684,  1924,   685,  1925,  1589,  1926,   686,  1927,   688,
    1928,  1652,  1653,  1725,   692,  1729,   636,  1733,  1220,  1737,
     691,  1741,   651,  1745,   693,  1749,   694,  1753,   971,   972,
    1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  2263,   996,
     997,  1002,  1003,   706,  2095,   695,  2096,   715,  2097,  1563,
    2098,   707,  2099,   708,  2100,   718,  2101,  2455,  2102,   719,
    2103,   742,  1902,   743,  1903,   750,  1904,   761,  1905,   767,
    1906,  2277,  1907,  1726,  1908,  1730,  1909,  1734,  1910,  1738,
    1911,  1742,  1912,  1746,  1913,  1750,  1914,  1754,  1915,   768,
    1916,   745,  1917,   770,  1918,   774,  1919,   789,  1920,   790,
    1921,   805,  1922,  1902,  1923,  1903,  1924,  1904,  1925,  1905,
    1926,  1906,  1927,  1907,  1928,  1908,  2295,  1909,   827,  1910,
     831,  1911,   840,  1912,   841,  1913,   828,  1914,   802,  1915,
     812,  1916,   845,  1917,   847,  1918,   849,  1919,   850,  1920,
     853,  1921,   862,  1922,   873,  1923,   863,  1924,  2095,  1925,
    2096,  1926,  2097,  1927,  2098,  1928,  2099,   874,  2100,   875,
    2101,   878,  2102,   887,  2103,   888,  1902,  2356,  1903,   893,
    1904,   897,  1905,   894,  1906,   900,  1907,   901,  1908,   902,
    1909,  2297,  1910,   911,  1911,   912,  1912,   917,  1913,   918,
    1914,   921,  1915,   924,  1916,   929,  1917,   941,  1918,   942,
    1919,   946,  1920,   947,  1921,   950,  1922,   959,  1923,   976,
    1924,   983,  1925,   992,  1926,  1001,  1927,  1007,  1928,  1047,
    1048,  1010,  1902,  1015,  1903,  1382,  1904,  1022,  1905,  1034,
    1906,   978,  1907,  1035,  1908,  1039,  1909,   984,  1910,  1058,
    1911,  1052,  1912,  1067,  1913,  1072,  1914,  1075,  1915,  1068,
    1916,  1076,  1917,  1017,  1918,  1421,  1919,  2314,  1920,  1081,
    1921,  1029,  1922,  1435,  1923,  1084,  1924,  1104,  1925,  1105,
    1926,  1465,  1927,  1902,  1928,  1903,  1110,  1904,  1113,  1905,
    1114,  1906,  1145,  1907,  1060,  1908,  1150,  1909,  1191,  1910,
    1204,  1911,  1243,  1912,  1244,  1913,  1245,  1914,  1246,  1915,
    1257,  1916,  1247,  1917,  1258,  1918,  1274,  1919,  1281,  1920,
    2316,  1921,  1902,  1922,  1903,  1923,  1904,  1924,  1905,  1925,
    1906,  1926,  1907,  1927,  1908,  1928,  1909,  1282,  1910,  1280,
    1911,  1291,  1912,  1284,  1913,  1307,  1914,  1311,  1915,  1234,
    1916,  1233,  1917,  1317,  1918,  1334,  1919,  1318,  1920,  1319,
    1921,  2318,  1922,  1320,  1923,  1321,  1924,  1333,  1925,  1336,
    1926,  1339,  1927,  1264,  1928,  1093,  1094,  1117,  1118,  1151,
    1152,  1161,  1162,  1207,  1208,  1252,  1253,  1292,  1293,  1326,
    1327,  1375,  1376,  1390,  1391,  1399,  1400,  1414,  1415,  1425,
    1426,  1458,  1459,  1482,  1483,  1768,  1341,  1902,  1340,  1903,
    1265,  1904,  1347,  1905,  1351,  1906,  1350,  1907,  1352,  1908,
    1597,  1909,  1355,  1910,  1357,  1911,  1298,  1912,  1297,  1913,
    1363,  1914,  1366,  1915,  1384,  1916,  2396,  1917,  1398,  1918,
    1385,  1919,  1397,  1920,  1444,  1921,  1477,  1922,  1489,  1923,
    1490,  1924,  1493,  1925,  1515,  1926,  2228,  1927,  1525,  1928,
    1526,  1902,  1535,  1903,  1536,  1904,  1588,  1905,  1537,  1906,
    1538,  1907,  1542,  1908,  1676,  1909,  1539,  1910,  1540,  1911,
    1446,  1912,  1541,  1913,  1548,  1914,  1543,  1915,  1507,  1916,
    1568,  1917,  1569,  1918,  1578,  1919,  1579,  1920,  1577,  1921,
    1580,  1922,  1590,  1923,  1594,  1924,  1595,  1925,  1596,  1926,
    1600,  1927,  1601,  1928,  1495,  1496,  1528,  1529,  1549,  1550,
    1570,  1571,  1581,  1582,  1649,  1650,  1695,  1696,  1865,  1866,
    1967,  1968,  1994,  1995,  2045,  2046,  2049,  2050,  2053,  2054,
    2129,  2130,  2134,  2135,  2142,  2143,  2147,  2148,  2152,  2153,
    2157,  2158,  1602,  2229,  2162,  2163,  2167,  2168,  2172,  2173,
    2177,  2178,  2213,  2214,  2216,  2217,  1609,  1760,  2253,  2254,
    2258,  2259,  2331,  2332,  2334,  2335,  2414,  2415,  2427,  2428,
    2436,  2437,  2441,  2442,  2471,  2472,  1605,  1610,  1611,  1612,
    1614,  1613,  1674,  1675,  1704,  1701,  1705,  1706,  1707,  1708,
    1709,  1769,  1710,  1711,  1712,  1713,  1850,  1861,  1889,  1714,
    1723,  1727,  1731,  1735,  1739,  1743,  1747,  1751,  1755,  1756,
    1757,  1758,  1761,  1762,  1763,  1764,  1765,  1766,  1767,  1773,
    1892,  1774,  1791,  1849,  1894,  1896,  1853,  1854,  1855,  1856,
    1857,  1858,  1859,  1860,  1870,  1871,  1962,  1985,  1984,  1991,
    2002,  1990,  2006,  2003,  2014,  2007,  2022,  2011,  2018,  2015,
    2010,  2019,  2030,  2044,  2026,  2048,  2052,  2056,  2086,  2083,
    2087,  2088,  2089,  2090,  2125,  2092,  2023,  2185,  2184,  2186,
    2027,  2034,  2141,  2031,  2187,  2189,  2191,  2193,  2223,  2233,
    2238,  2239,  2242,  2241,  2240,  2245,  2246,  2247,  2188,  2248,
    2249,  2250,  2251,  2190,  2270,  2265,  2284,  2285,  2192,  2286,
    2287,  2288,  2294,  2293,  2299,  2300,  2302,  2303,  2320,  2313,
    2324,  2304,  2323,  2321,  2327,  2325,  2425,  2360,  2326,  2358,
    2390,  2363,  2364,  2328,  2365,  2366,  2329,  2377,  2389,  2398,
    2399,  2404,  2403,  2405,  2400,  2409,  2426,  2410,  2412,  2452,
    1496,  2462,  2450,  2454,  2465,  2466,  2386,  2503,  2504,  2459,
    2460,  2463,  2469,  2500,  2505,  2461,  2506,  2507,  2508,  2509,
    2517,  2391,  2510,  2513,  2392,  2514,  2518,  2393,  2520,  2521,
    2394,  2539,  2528,  2522,  2533,  2531,  2536,  2515,  2516,  2537,
    2538,  2519,  2542,  2523,  2530,  2532,  2543,  2544,   149,   117,
     239,   595,   264,   337,  2502,    40,   696,   657,   438,   689,
     621,   787,  1342,  1036,   842,  1077,  1085,  1344,  1312,  1545,
    1115,  1360,  1314,  1285,   517,   771,  1358,  1040,   848,  2464,
    1215,  1099,  1434,  1131,  2359,  2488,  2424,  2498,  2499,   522,
    2482,     0,  1966,     0,     0,     0,     0,     0,     0,     0,
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
       0,  2453,     0,     0,     0,     0,  2457,  2458,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2511,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2529,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2541
};

static const yytype_int16 yycheck[] =
{
     368,   690,   200,     4,   145,   597,   524,  1316,     8,   377,
    1151,     4,    11,    12,   382,  1821,  1071,  1823,     4,     4,
       4,  1827,    11,    12,     4,    68,     6,     7,   717,  1835,
     248,  1837,   250,  1839,  1080,  1841,    68,  1346,  1844,  1080,
    1080,     4,  1848,     6,     7,    11,     4,    57,     6,     7,
      52,    61,   773,  1362,    79,    11,   151,    67,    11,    12,
      37,    68,    39,  1109,    41,   754,    43,   659,  1109,  1109,
      35,    81,   151,    68,    11,    12,    57,  1078,   112,   597,
      61,   896,    11,    12,    11,  1086,    67,    97,    53,   147,
      67,   119,   151,  1148,  1900,   146,   146,    47,  1994,    49,
      81,   146,    67,   151,     4,   246,   698,   248,     4,   250,
      75,  1252,     6,     4,    91,  1116,    97,    67,     4,  1425,
      85,     4,    87,   149,     6,     6,     7,    77,     4,   149,
     149,    11,    12,    11,    99,   717,    70,   149,   103,   287,
     105,   659,   107,     4,   109,    95,    11,    12,    11,    12,
       4,   101,  2362,     4,     4,   844,   150,  1406,  1275,     0,
       4,     6,     7,    15,  1970,  1825,    48,   966,  1974,    37,
    1976,    39,   754,    41,     4,    43,    13,    14,  2388,   237,
     698,   170,   171,    58,  1423,  1326,  1846,    26,   556,   178,
     179,  1308,   333,   561,   342,  1250,   394,   996,   566,    67,
      54,  1450,   168,   169,  1510,    96,    36,   302,   102,    92,
      86,    62,    98,    94,    89,   168,   169,     4,   416,   153,
     154,    82,   156,    91,   180,   181,    76,   306,  1467,  2035,
     428,   168,   169,    78,  1375,   234,  2446,  2447,  1547,   298,
     288,   168,   169,   288,    88,  1348,  2142,    32,   343,  1390,
     468,   302,   470,   279,   472,   773,   306,   285,   158,   279,
     279,  1364,   158,    50,   343,  1080,   464,   279,   234,  1324,
    1180,  1082,   306,  1414,  2080,  2081,  2082,   335,   121,   235,
     236,   234,  2088,  2089,   343,  1945,   280,   215,   168,   169,
     168,   169,    11,    12,   319,   343,   298,   234,    16,   342,
    1111,   311,     4,   168,   169,   234,    74,   234,  1354,   238,
     342,   239,  1313,  1354,  1354,    83,  1226,  1458,  1026,   299,
    1980,  1042,   310,   307,   334,    84,   336,   468,   338,   470,
     340,   472,    17,  1388,    19,   342,   313,    73,    11,    12,
     341,  1482,  1343,    79,   307,   303,   339,   342,  1056,    34,
     335,   337,   317,   334,   234,   336,   234,   338,  1359,   340,
      62,   153,   154,   312,   156,   315,   229,   230,   207,   234,
     159,   210,   314,   236,   213,   164,   165,  1066,   519,   164,
     165,    93,   122,   524,   316,   170,   171,  1528,   100,   178,
     179,  1080,   164,   165,   153,   154,   311,   156,  2058,  2059,
    2060,  2061,  2062,  2063,   176,   177,  2066,  2067,  2068,  2069,
    2070,  2071,    23,  2073,   161,   162,   163,   164,   165,  2079,
    1109,   168,   169,   153,   154,  1480,   156,     5,   626,  1570,
    2246,  2247,  2248,  2249,  2250,  2251,    86,   635,     3,    89,
    1581,   198,   199,   162,   163,   164,   165,   164,   165,   206,
    1042,   170,   171,   170,   171,     5,   597,   176,   177,    69,
       5,   276,    72,   278,  2124,     5,   465,     5,   468,   469,
     470,   471,   690,   671,  1066,    11,    12,   313,   467,   123,
     678,   125,   126,   127,   318,   129,   130,   131,  1080,   133,
     134,   135,     3,   137,   138,   139,   160,   141,   142,   124,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      11,    12,    11,    12,   178,   179,   128,  1109,   659,  1037,
     718,   719,    11,    12,  1042,  2341,   132,  2343,   192,   193,
      11,    12,   136,  2349,  2194,  2195,  2196,  2197,    35,   140,
    2200,  2201,   315,  1852,  2204,   743,    11,  2353,  1066,   690,
    2210,  2211,  2212,    11,   218,    11,    53,   698,    11,  2219,
    1078,   335,  1080,   761,    11,    12,    11,    12,  1086,     6,
      67,    11,    12,   170,   171,     8,   717,     8,    75,   164,
     165,    11,    12,   168,   169,  2245,  2402,    62,    85,   337,
      87,  1109,  2252,   178,   179,   339,    11,    12,  1116,   196,
     197,     6,    99,    11,    12,    82,   103,   805,   105,   341,
     107,    98,   109,   754,   168,   169,   170,   171,    47,   317,
      49,   288,   164,   165,    33,   292,   168,   169,    92,   296,
     227,   228,   773,   831,    11,    12,    11,    12,    67,   164,
     165,  2301,   196,   197,     3,  2305,    11,    12,    77,   203,
     204,    11,    12,    11,    12,   853,    11,    12,    11,    12,
      11,    12,    11,    12,   862,  1354,    95,   161,   162,   163,
     164,   165,   101,     6,   168,   169,    58,   231,  1987,  2339,
     878,    11,    12,    89,   178,   179,    11,    12,   160,   887,
      11,    12,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    68,   844,   902,   342,   178,   179,    11,    12,
      11,    12,     8,   911,   186,   187,    11,    12,     8,  1087,
       8,   288,    11,    12,  1316,   292,    11,    12,  1723,   296,
       6,     7,  1727,    11,    12,    50,  1731,    11,    12,    11,
    1735,    11,   214,   941,  1739,   412,    11,   414,  1743,   416,
      11,   418,  1747,   420,  1346,   422,  1751,   424,   102,   426,
      96,   428,  1354,   430,   431,   432,    48,   434,    78,   436,
    1362,   438,     8,   440,    42,   442,  2436,    11,    12,    11,
      12,    11,    12,    11,    12,   983,    11,    12,  1156,    11,
      12,    44,   160,    40,   992,  1313,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    11,    12,    11,    12,
     178,   179,    11,    12,    11,    12,   184,   185,    11,    12,
      11,    12,    11,    12,    38,  1343,    11,    12,  1517,   342,
     246,    11,    12,    11,    12,    68,  1354,    11,    12,   319,
     256,  1359,   258,   211,   260,   412,   262,   414,   264,   416,
     266,   418,   268,   420,   270,   422,   272,   424,     6,   426,
    1228,   428,     6,   430,     6,   432,   282,   434,   444,   436,
     446,   438,   448,   440,   450,   442,   452,     6,   454,    86,
     456,   160,   458,    54,   460,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,    11,    12,    11,    12,   178,
     179,  1042,    36,   182,   183,  1775,  1104,  1777,   358,  1779,
     360,  1781,   362,  1783,   364,  1785,   366,  1787,   368,  1789,
     370,    88,   372,    76,   374,  1066,   376,     6,   378,   208,
     380,     6,   382,    90,   384,    68,   386,     3,   388,  1080,
     390,   342,   392,   343,   394,     3,   396,    31,   398,    11,
     400,     8,   402,     8,   404,  1547,   406,     8,   408,   100,
     410,   200,   201,  1680,   110,  1682,    93,  1684,  1109,  1686,
     108,  1688,   342,  1690,   106,  1692,   104,  1694,    11,    12,
     219,   220,   221,   222,   223,   224,   225,   226,  2129,    11,
      12,    11,    12,   343,   444,    68,   446,    85,   448,  1517,
     450,     8,   452,     8,   454,     3,   456,   457,   458,     3,
     460,   343,   358,     6,   360,    61,   362,     6,   364,     3,
     366,  2162,   368,  1680,   370,  1682,   372,  1684,   374,  1686,
     376,  1688,   378,  1690,   380,  1692,   382,  1694,   384,   343,
     386,    83,   388,    74,   390,   308,   392,    94,   394,     8,
     396,    25,   398,   358,   400,   360,   402,   362,   404,   364,
     406,   366,   408,   368,   410,   370,   371,   372,     8,   374,
      22,   376,    62,   378,    86,   380,   300,   382,   304,   384,
      89,   386,     5,   388,    84,   390,     6,   392,   284,   394,
      21,   396,     6,   398,   155,   400,   145,   402,   444,   404,
     446,   406,   448,   408,   450,   410,   452,     8,   454,    71,
     456,    29,   458,     6,   460,   145,   358,  2258,   360,   309,
     362,   214,   364,   111,   366,    90,   368,    80,   370,    24,
     372,   373,   374,     6,   376,    51,   378,   305,   380,    45,
     382,   211,   384,    45,   386,     8,   388,     6,   390,   286,
     392,   301,   394,    45,   396,   208,   398,     8,   400,     6,
     402,     6,   404,    30,   406,     8,   408,   342,   410,    11,
      12,   326,   358,     6,   360,  1316,   362,   342,   364,     8,
     366,   306,   368,   146,   370,    72,   372,    69,   374,     6,
     376,   342,   378,    46,   380,   159,   382,     8,   384,   322,
     386,   146,   388,   302,   390,  1346,   392,   393,   394,    46,
     396,   306,   398,  1354,   400,   112,   402,     6,   404,   145,
     406,  1362,   408,   358,   410,   360,    46,   362,     8,   364,
      52,   366,   324,   368,   298,   370,     8,   372,     8,   374,
     218,   376,     8,   378,     3,   380,     3,   382,     3,   384,
       6,   386,   320,   388,   157,   390,     3,   392,     6,   394,
     395,   396,   358,   398,   360,   400,   362,   402,   364,   404,
     366,   406,   368,   408,   370,   410,   372,     5,   374,   307,
     376,     8,   378,    70,   380,     3,   382,   343,   384,   302,
     386,   151,   388,     6,   390,   237,   392,     8,   394,     8,
     396,   397,   398,     8,   400,   328,   402,     8,   404,   149,
     406,   327,   408,   151,   410,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,  1713,   343,   358,   303,   360,
     306,   362,     8,   364,     8,   366,   307,   368,   155,   370,
    1558,   372,     6,   374,   343,   376,   298,   378,   151,   380,
       8,   382,   299,   384,     8,   386,   387,   388,     8,   390,
     330,   392,   323,   394,     8,   396,   332,   398,   325,   400,
       6,   402,    11,   404,     3,   406,  2085,   408,   303,   410,
     152,   358,   321,   360,     8,   362,  1547,   364,   158,   366,
       6,   368,   152,   370,  1612,   372,     8,   374,     8,   376,
     288,   378,   307,   380,     8,   382,   343,   384,   151,   386,
     299,   388,   152,   390,   150,   392,     6,   394,   329,   396,
       6,   398,   245,   400,     3,   402,     8,   404,     8,   406,
     331,   408,     8,   410,   235,   236,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,   174,   175,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,     8,  2085,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,     8,  1705,   247,   248,
      11,    12,    11,    12,   229,   230,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,   289,     6,     6,     6,
     152,   333,     8,     8,   244,   202,     3,     8,     8,     8,
       8,   274,     8,     8,     8,     8,   250,   276,   283,    11,
      11,    11,    11,    11,    11,    11,    11,    11,     3,    11,
       8,    11,     6,     6,     6,     6,     6,     6,     6,     3,
     234,     8,     8,     6,   234,   234,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     6,   463,   252,     8,   278,
       8,   257,   261,   278,   269,   278,   267,   278,   271,   278,
     263,   278,   259,     8,   265,     8,     8,   413,   443,   441,
       3,    11,    11,   421,   437,   425,   278,     8,   439,     3,
     278,   273,   275,   278,     6,     6,     6,   415,   389,     8,
     423,   427,   433,    11,   429,    11,    11,    11,   289,    11,
      11,    11,    11,   293,   277,   157,     6,     8,   297,     8,
       8,     8,   369,   367,   375,   377,   381,   383,   399,   391,
     409,   385,   407,   401,     3,   411,  2355,   149,   405,   251,
       8,   279,   279,   417,   279,   149,   419,   279,   279,     8,
       8,     8,   451,     8,   403,   449,   253,   445,   455,     6,
     236,   459,   379,     8,     8,     8,   149,     8,     8,   461,
     453,   435,    11,    11,     8,   447,     8,   249,     6,     6,
       6,   359,   158,     8,   361,     8,     3,   363,     4,     8,
     365,    11,     6,     8,   238,     8,     8,   150,   150,     8,
       8,   150,     6,   150,   150,   150,     8,   281,    60,    40,
     134,   512,   156,   224,   387,    25,   653,   586,   312,   639,
     528,   754,  1268,   980,   814,  1019,  1031,  1271,  1237,  1511,
    1062,  1304,  1240,  1197,   406,   747,  1301,   987,   822,  2414,
    1109,  1042,  1354,  1066,  2265,  2446,  2355,  2447,  2447,   420,
    2441,    -1,  1831,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,  2399,    -1,    -1,    -1,    -1,  2404,  2405,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2514,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2538
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
      32,   164,   165,   170,   171,   494,   495,   496,  1107,  1469,
    1470,  1471,  1496,  1497,  1498,    11,    12,   510,   511,   512,
      11,    12,   516,   517,   518,    11,    12,   522,   523,   524,
      11,    12,   528,   529,   530,    11,    12,   534,   535,   536,
      11,    12,   540,   541,   542,    11,    12,   546,   547,   548,
      23,   552,  1102,     5,     5,     5,     5,     5,   318,   765,
     766,    11,    12,   672,   673,   674,    47,    49,    67,    77,
      95,   101,   315,   623,   624,   625,   626,   627,   632,   633,
     638,   639,   644,   645,   650,   651,   656,   657,   313,   571,
      11,    12,   574,   575,   576,   580,   581,   587,   588,   594,
     595,   601,  1469,   606,  1102,  1111,  1112,     3,     3,    11,
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
     176,   177,   582,  1469,  1499,  1500,  1501,    11,   590,   589,
    1469,  1499,    11,   597,   596,  1469,  1499,    11,   602,    11,
      12,   607,   608,   609,     6,     8,   468,   469,   470,   471,
    1113,     8,     8,    58,    89,   500,   501,   502,   503,    62,
     335,   337,   339,   341,    82,    98,     6,    68,   342,   556,
     557,   558,   559,    11,    12,   770,   771,   772,    26,   207,
     210,   213,   769,  1105,  1429,  1435,  1440,   317,   677,    11,
      12,   680,   681,   682,    11,    12,   686,   687,   688,    11,
      12,   692,   693,   694,    11,    12,   698,   699,   700,    11,
      12,   704,   705,   706,    33,   710,  1108,   727,   728,   734,
     735,   741,   742,   748,  1469,   753,  1102,     4,    50,   631,
       6,    48,   637,     6,   102,   643,     4,    96,   649,     6,
       7,    78,   655,  1109,    11,    12,   659,   660,   661,    92,
     584,  1109,     3,   591,  1109,   598,  1109,     6,   603,    68,
     342,   610,   611,   612,   613,  1111,    58,   502,   504,   505,
    1111,    68,   558,   560,   561,    79,   319,   773,   774,   775,
     776,  1111,     8,     8,     8,     4,    86,   683,     4,    88,
     689,     4,    76,   695,     4,    36,   701,     4,    54,   707,
    1111,    11,    12,   711,   712,   713,    11,   730,   729,  1469,
    1499,    11,   737,   736,  1469,  1499,    11,   744,   743,  1469,
    1499,    11,   749,    11,    12,   754,   755,   756,    50,    48,
     102,    96,    78,    68,   342,   662,   663,   664,   665,    42,
       8,    44,    40,    38,    68,   612,   614,   615,    11,    12,
     507,   168,   169,   506,  1469,  1478,  1479,  1480,    11,    12,
     563,   178,   179,   562,  1469,  1478,  1502,  1503,  1504,   319,
      73,   775,  1075,  1076,   777,   778,     6,     6,     6,     6,
      86,    88,    76,    36,    54,     6,    93,   100,   714,   715,
     716,   717,   731,  1109,   738,  1109,   745,  1109,     6,   750,
      68,   342,   757,   758,   759,   760,    68,   664,   666,   667,
      11,    12,   617,   616,  1469,  1478,  1502,    90,     3,   343,
       3,    31,  1077,  1106,    11,   783,    17,    19,    34,   779,
     780,   781,   782,  1111,     8,     8,     8,  1111,   100,   716,
     718,   108,   110,   106,   104,    68,   759,   761,   762,    11,
      12,   669,   668,  1469,  1478,  1502,   343,     8,     8,  1111,
      11,    12,  1078,  1079,  1080,    85,   784,   785,     3,     3,
    1111,    11,    12,   162,   163,   719,   720,   721,   722,  1463,
    1464,  1465,  1469,  1496,  1499,    11,    12,   764,   763,  1469,
    1478,  1502,   343,     6,    74,    83,  1081,  1082,  1083,  1084,
      61,   800,   801,   786,   787,   788,  1107,  1469,  1496,  1111,
    1111,     6,     6,     7,    94,   723,   724,     3,   343,  1111,
      74,  1083,  1085,  1086,   308,   806,   807,    11,    12,   802,
     803,   804,    11,    12,   789,   790,   791,   788,  1111,    94,
       8,    11,    12,  1088,  1089,  1090,   161,  1087,  1432,  1463,
    1469,  1478,   304,   884,   885,    25,   808,  1104,     4,    62,
     805,    86,    89,   792,   793,   794,   795,    84,   153,   154,
     156,  1091,  1092,  1093,  1094,  1095,  1096,     8,   300,   946,
     947,    22,   886,  1101,  1111,    11,    12,   809,   810,   811,
      62,    86,   794,   796,   797,     5,  1097,    84,  1093,     6,
     284,  1008,  1009,    21,   948,  1098,  1111,    11,    12,   887,
     888,   889,     6,   145,   812,   813,   814,    11,    12,   799,
     798,  1469,  1496,   155,     8,    71,  1052,  1053,    29,  1010,
    1099,  1111,    11,    12,   949,   950,   951,     6,   145,   890,
     891,   892,  1111,   309,   111,   826,   827,   214,   815,  1438,
      90,    80,    24,  1054,  1103,  1111,    11,    12,  1011,  1012,
    1013,     6,    51,   952,   953,   954,  1111,   305,    45,   904,
     905,   211,   893,  1434,    45,   842,   843,   828,  1438,     8,
      11,    12,   816,   817,   818,  1111,    11,    12,  1055,  1056,
    1057,     6,   286,  1014,  1015,  1111,   301,    45,   966,   967,
     208,   955,  1428,   917,    11,    12,   906,   907,   908,     8,
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
    1177,  1178,   159,  1213,  1430,     8,   146,   899,   901,   858,
     859,    46,   849,  1177,   112,   834,   836,    11,   234,   824,
     825,  1449,  1478,    11,    12,  1065,  1066,  1067,  1064,  1432,
    1463,  1469,  1478,  1502,     6,   145,  1021,  1022,   982,   983,
      46,   973,  1177,     8,    52,   961,   963,    11,    12,   923,
     924,   925,   160,   166,   167,   172,   173,   184,   185,   922,
    1431,  1434,  1469,  1472,  1473,  1474,  1478,  1481,  1482,  1483,
    1490,  1491,  1492,  1496,  1502,   324,   912,  1183,  1184,  1213,
       8,    11,    12,  1173,  1174,  1175,    11,   902,   903,  1449,
    1478,    11,    12,   861,   862,   863,   186,   187,   860,  1431,
    1438,  1469,  1472,  1478,  1490,  1496,  1502,  1508,  1509,  1510,
     850,  1183,    11,    12,   837,   838,   839,   840,  1449,  1478,
    1109,     8,    70,   153,   154,   156,  1068,  1069,  1070,  1071,
    1072,  1073,  1111,  1029,   218,  1023,  1433,    11,    12,   985,
     986,   987,   182,   183,   984,  1428,  1431,  1466,  1467,  1468,
    1469,  1472,  1478,  1490,  1496,  1502,   974,  1183,    11,   964,
     965,  1449,  1478,   151,   302,   343,   926,   927,   928,   929,
     936,   937,   938,     8,     3,     3,     3,   320,   913,  1189,
    1190,  1213,    11,    12,  1179,  1180,  1181,     6,   157,  1143,
    1144,  1151,  1176,  1109,   151,   306,   343,   864,   865,   866,
     867,   874,   875,   876,     3,   851,  1189,     4,   307,   841,
     307,     6,     5,  1074,    70,  1070,   287,   342,  1020,  1030,
    1031,     8,    11,    12,  1024,  1025,  1026,   151,   298,   343,
     988,   989,   990,   991,   998,   999,  1000,     3,   975,  1189,
    1109,   343,   928,   930,   937,   939,   940,     6,     8,     8,
       8,   328,   914,  1195,  1196,  1213,    11,    12,  1185,  1186,
    1187,  1143,  1182,     8,   237,  1441,   149,  1145,  1146,   327,
     303,   343,   866,   868,   875,   877,   878,     8,   852,  1195,
     307,     8,   155,  1032,  1033,     6,  1028,   343,   990,   992,
     999,  1001,  1002,     8,   976,  1195,   299,    11,    12,   931,
     932,   933,   934,  1449,  1478,    11,    12,   942,   943,   944,
     941,  1430,  1469,  1502,     8,   330,   915,  1201,  1202,  1213,
      11,    12,  1191,  1192,  1193,  1143,  1188,   323,     8,    11,
      12,  1152,  1153,  1154,  1147,  1148,    11,    12,   869,   870,
     871,   872,  1449,  1478,    11,    12,   880,   881,   882,   879,
    1430,  1469,  1502,   853,  1201,    11,    12,  1035,  1036,  1037,
     192,   193,  1034,  1431,  1433,  1469,  1472,  1475,  1476,  1477,
    1478,  1490,  1496,  1502,     8,   146,   288,  1027,  1214,  1215,
      11,    12,   993,   994,   995,   996,  1449,  1478,    11,    12,
    1004,  1005,  1006,  1003,  1430,  1469,  1502,   977,  1201,     4,
       6,     7,   303,   935,  1110,   945,  1143,   332,   916,  1207,
    1208,  1213,    11,    12,  1197,  1198,  1199,  1143,  1194,   325,
       6,     4,   158,    11,  1150,   235,   236,  1149,  1450,  1452,
     307,   873,  1110,   883,  1143,   854,  1207,   151,   343,  1038,
    1039,  1040,  1041,  1042,  1214,     3,  1216,  1217,   299,   997,
    1110,  1007,  1143,   978,  1207,   303,   152,  1213,    11,    12,
    1203,  1204,  1205,  1143,  1200,   321,     8,   158,     6,     8,
       8,   307,   152,   343,  1214,  1041,  1043,  1044,     8,    11,
      12,  1219,  1220,  1221,   196,   197,   203,   204,   231,  1218,
    1427,  1436,  1451,  1478,  1493,  1494,  1495,  1496,   299,   152,
      11,    12,  1209,  1210,  1211,  1143,  1206,   329,   150,     6,
       6,    11,    12,  1046,  1047,  1048,  1045,  1430,  1469,  1502,
     245,  1222,  1223,  1224,     3,     8,     8,  1111,  1143,  1212,
     331,     8,     8,  1049,  1143,   289,  1229,  1225,  1226,     8,
       6,     6,     6,   333,   152,   246,   256,   258,   260,   262,
     264,   266,   268,   270,   272,   282,  1230,  1231,  1232,  1256,
    1257,  1269,  1270,  1296,  1297,  1314,  1315,  1332,  1333,  1345,
    1346,  1363,  1364,  1381,  1382,  1394,  1395,  1398,  1399,    11,
      12,  1228,   200,   201,   219,   220,   221,   222,   223,   224,
     225,   226,  1227,  1442,  1443,  1444,  1445,  1446,  1453,  1454,
    1459,  1460,  1461,  1462,     8,     8,  1111,  1233,  1234,  1258,
    1259,  1271,  1272,  1298,  1299,  1316,  1317,  1334,  1335,  1347,
    1348,  1365,  1366,  1383,  1384,   174,   175,  1396,  1487,  1488,
    1489,   202,  1400,  1426,   244,     3,     8,     8,     8,     8,
       8,     8,     8,     8,    11,   198,   199,   206,  1235,  1437,
    1484,  1485,  1486,    11,  1260,  1437,  1484,    11,  1273,  1437,
    1484,    11,  1300,  1437,  1484,    11,  1318,  1437,  1484,    11,
    1336,  1437,  1484,    11,  1349,  1437,  1484,    11,  1367,  1437,
    1484,    11,  1385,  1437,  1484,     3,    11,     8,    11,  1401,
    1111,     6,     6,     6,     6,     6,     6,     6,  1109,   274,
    1236,  1238,  1239,     3,     8,  1238,  1261,  1238,  1274,  1238,
    1301,  1238,  1319,  1238,  1337,  1238,  1350,  1238,  1368,  1238,
    1386,     8,   288,   292,   296,   412,   414,   416,   418,   420,
     422,   424,   426,   428,   430,   432,   434,   436,   438,   440,
     442,  1585,  1586,  1587,  1593,  1594,  1597,  1598,  1601,  1602,
    1605,  1606,  1608,  1609,  1611,  1612,  1614,  1615,  1617,  1618,
    1621,  1622,  1626,  1627,  1629,  1630,  1632,  1633,  1635,  1636,
    1638,  1639,  1641,  1644,  1645,  1647,  1648,  1650,  1651,     6,
     250,  1403,  1404,     8,     8,     8,     8,     8,     8,     8,
       8,   276,  1237,  1244,  1245,    11,    12,  1240,  1241,  1242,
       8,     6,  1244,  1262,  1244,  1275,  1244,  1302,  1244,  1320,
    1244,  1338,  1244,  1351,  1244,  1369,  1244,  1387,  1642,   283,
    1397,  1588,   234,  1596,   234,  1600,   234,  1604,  1585,  1607,
    1585,  1610,   358,   360,   362,   364,   366,   368,   370,   372,
     374,   376,   378,   380,   382,   384,   386,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,   408,   410,  1511,
    1512,  1515,  1518,  1520,  1522,  1524,  1526,  1528,  1530,  1532,
    1534,  1536,  1538,  1540,  1542,  1543,  1545,  1547,  1549,  1551,
    1553,  1555,  1556,  1562,  1570,  1573,  1576,  1579,  1582,  1613,
    1585,  1616,   463,  1619,  1625,  1623,  1625,    11,    12,  1628,
    1585,  1631,  1585,  1634,  1585,  1637,  1585,  1640,  1585,  1646,
    1511,  1649,  1585,  1652,     8,   252,  1410,  1411,  1405,  1430,
     257,   278,  1250,  1251,    11,    12,  1246,  1247,  1248,  1142,
    1143,  1243,     8,   278,  1263,  1264,   261,   278,  1276,  1277,
     263,   278,  1303,  1304,   269,   278,  1321,  1322,   271,   278,
    1339,  1340,   267,   278,  1352,  1353,   265,   278,  1370,  1371,
     259,   278,  1388,  1389,   273,  1643,    11,    12,   234,   465,
    1589,  1590,  1591,  1592,     8,    11,    12,  1595,     8,    11,
      12,  1599,     8,    11,    12,  1603,   413,  1585,  1529,  1521,
    1523,  1527,  1531,  1533,  1571,  1583,  1541,  1525,  1548,  1535,
    1537,  1539,  1563,  1546,  1577,  1574,  1580,  1513,  1516,  1519,
    1550,  1552,  1554,   441,  1511,  1558,   443,     3,    11,    11,
     421,  1585,   425,  1585,  1585,   444,   446,   448,   450,   452,
     454,   456,   458,   460,  1511,  1653,  1654,  1655,  1656,  1661,
    1662,  1664,  1665,  1667,  1670,  1671,  1673,  1674,  1676,  1677,
    1679,  1680,  1682,  1683,  1511,   437,  1417,  1412,  1430,    11,
      12,  1406,  1407,  1408,    11,    12,  1252,  1253,  1254,  1142,
    1249,   275,    11,    12,  1265,  1266,  1267,    11,    12,  1278,
    1279,  1280,    11,    12,  1305,  1306,  1307,    11,    12,  1323,
    1324,  1325,    11,    12,  1341,  1342,  1343,    11,    12,  1354,
    1355,  1356,    11,    12,  1372,  1373,  1374,    11,    12,  1390,
    1391,  1392,   431,  1585,   439,     8,     3,     6,   289,     6,
     293,     6,   297,   415,  1511,  1511,  1511,  1511,  1511,  1511,
    1572,  1584,  1511,  1511,  1511,  1511,  1511,  1511,  1566,  1511,
    1578,  1575,  1581,    11,    12,  1514,    11,    12,  1517,  1511,
    1585,  1585,  1585,   389,  1544,    11,    12,   467,  1496,  1502,
    1557,  1559,  1560,     8,  1585,  1620,  1585,  1624,   423,   427,
     429,    11,   433,  1658,  1659,    11,    11,    11,    11,    11,
      11,    11,  1511,   247,   248,  1402,  1418,  1419,    11,    12,
    1413,  1414,  1415,  1143,  1409,   157,  1155,  1156,  1161,  1255,
     277,  1142,  1268,  1281,  1282,  1308,  1326,  1143,  1344,  1357,
    1375,  1165,  1166,  1393,     6,     8,     8,     8,     8,  1511,
    1511,  1511,  1511,   367,   369,   371,  1511,   373,  1511,   375,
     377,  1511,   381,   383,   385,    11,    12,   234,   238,  1564,
    1567,  1568,  1569,   391,   393,  1511,   395,  1511,   397,  1511,
     399,   401,  1511,   407,   409,   411,   405,     3,   417,   419,
    1668,    11,    12,  1657,   229,   230,  1457,  1458,  1660,  1511,
    1663,  1653,  1666,  1653,  1672,  1653,  1675,  1653,  1678,  1653,
    1681,  1653,  1684,  1511,  1420,  1421,  1143,  1416,   251,  1441,
     149,  1157,  1158,   279,   279,   279,   149,  1283,  1284,   149,
     279,  1309,  1310,   149,   279,  1327,  1328,   279,   149,   279,
    1358,  1359,   149,   279,  1376,  1377,   149,  1167,  1168,   279,
       8,   359,   361,   363,   365,  1511,   387,  1511,     8,     8,
     403,  1561,  1669,   451,     8,     8,  1511,  1653,  1653,   449,
     445,  1653,   455,  1585,    11,    12,  1423,  1424,  1425,   227,
     228,  1422,  1447,  1448,  1493,  1496,   253,    11,    12,  1162,
    1163,  1164,  1159,  1452,  1285,  1286,    11,    12,  1311,  1312,
    1313,    11,    12,  1329,  1330,  1331,  1360,  1378,  1169,  1452,
     379,  1565,     6,  1109,     8,   457,  1653,  1109,  1109,   461,
     453,   447,   459,   435,  1222,     8,     8,     4,   158,    11,
    1160,    11,    12,  1288,  1289,  1290,   215,   239,  1287,  1439,
    1456,  1511,  1654,    11,   180,   181,  1361,  1362,  1450,  1452,
    1505,  1506,  1507,    11,    12,  1379,  1380,  1452,  1457,  1458,
      11,  1170,   387,     8,     8,     8,     8,   249,     6,     6,
     158,  1109,  1291,     8,     8,   150,   150,     6,     3,   150,
       4,     8,     8,   150,   150,   280,  1292,  1293,     6,  1109,
     150,     8,   150,   238,  1294,  1455,     8,     8,     8,    11,
    1295,  1109,     6,     8,   281
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
    1218,  1218,  1219,  1219,  1220,  1221,  1222,  1223,  1223,  1224,
    1225,  1226,  1226,  1227,  1227,  1227,  1227,  1227,  1227,  1227,
    1227,  1227,  1228,  1228,  1229,  1229,  1230,  1230,  1230,  1230,
    1230,  1230,  1230,  1230,  1230,  1230,  1230,  1231,  1232,  1233,
    1234,  1234,  1235,  1235,  1236,  1237,  1237,  1238,  1239,  1240,
    1240,  1241,  1242,  1243,  1244,  1244,  1245,  1246,  1246,  1247,
    1248,  1249,  1250,  1251,  1252,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,  1259,  1259,  1260,  1260,  1261,  1262,  1263,  1263,
    1264,  1265,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,
    1272,  1273,  1273,  1274,  1275,  1276,  1276,  1277,  1278,  1278,
    1279,  1280,  1281,  1282,  1282,  1283,  1284,  1285,  1286,  1286,
    1287,  1287,  1288,  1288,  1289,  1290,  1291,  1291,  1292,  1293,
    1294,  1294,  1295,  1296,  1297,  1298,  1299,  1299,  1300,  1300,
    1301,  1302,  1303,  1303,  1304,  1305,  1305,  1306,  1307,  1308,
    1308,  1309,  1310,  1311,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1317,  1318,  1318,  1319,  1320,  1321,  1321,  1322,  1323,
    1323,  1324,  1325,  1326,  1326,  1327,  1328,  1329,  1329,  1330,
    1331,  1332,  1333,  1334,  1335,  1335,  1336,  1336,  1337,  1338,
    1339,  1339,  1340,  1341,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1348,  1349,  1349,  1350,  1351,  1352,  1352,  1353,
    1354,  1354,  1355,  1356,  1357,  1357,  1358,  1359,  1360,  1360,
    1361,  1361,  1361,  1362,  1363,  1364,  1365,  1366,  1366,  1367,
    1367,  1368,  1369,  1370,  1370,  1371,  1372,  1372,  1373,  1374,
    1375,  1375,  1376,  1377,  1378,  1378,  1379,  1379,  1379,  1380,
    1380,  1381,  1382,  1383,  1384,  1384,  1385,  1385,  1386,  1387,
    1388,  1388,  1389,  1390,  1390,  1391,  1392,  1393,  1394,  1395,
    1396,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,
    1405,  1406,  1406,  1407,  1408,  1409,  1410,  1411,  1412,  1413,
    1413,  1414,  1415,  1416,  1417,  1417,  1418,  1419,  1420,  1421,
    1421,  1422,  1422,  1422,  1422,  1423,  1423,  1424,  1425,  1426,
    1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,
    1447,  1448,  1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,
    1457,  1458,  1459,  1460,  1460,  1461,  1462,  1463,  1463,  1464,
    1465,  1466,  1466,  1467,  1468,  1469,  1469,  1470,  1471,  1472,
    1472,  1473,  1474,  1475,  1475,  1476,  1477,  1478,  1478,  1479,
    1480,  1481,  1481,  1482,  1483,  1484,  1484,  1485,  1486,  1487,
    1487,  1488,  1489,  1490,  1490,  1491,  1492,  1493,  1493,  1494,
    1495,  1496,  1496,  1497,  1498,  1499,  1499,  1500,  1501,  1502,
    1502,  1503,  1504,  1505,  1505,  1506,  1507,  1508,  1508,  1509,
    1510,  1511,  1511,  1511,  1511,  1511,  1511,  1511,  1511,  1511,
    1511,  1511,  1511,  1511,  1511,  1511,  1511,  1511,  1511,  1511,
    1511,  1511,  1511,  1511,  1511,  1511,  1511,  1511,  1513,  1512,
    1514,  1514,  1516,  1515,  1517,  1517,  1519,  1518,  1521,  1520,
    1523,  1522,  1525,  1524,  1527,  1526,  1529,  1528,  1531,  1530,
    1533,  1532,  1535,  1534,  1537,  1536,  1539,  1538,  1541,  1540,
    1542,  1543,  1544,  1546,  1545,  1548,  1547,  1550,  1549,  1552,
    1551,  1554,  1553,  1555,  1556,  1557,  1557,  1558,  1558,  1559,
    1559,  1559,  1561,  1560,  1563,  1562,  1564,  1564,  1565,  1564,
    1566,  1566,  1567,  1567,  1568,  1569,  1571,  1570,  1572,  1572,
    1574,  1573,  1575,  1575,  1577,  1576,  1578,  1578,  1580,  1579,
    1581,  1581,  1583,  1582,  1584,  1584,  1585,  1585,  1585,  1585,
    1585,  1585,  1585,  1585,  1585,  1585,  1585,  1585,  1585,  1585,
    1585,  1585,  1585,  1585,  1585,  1586,  1587,  1588,  1588,  1589,
    1589,  1590,  1590,  1591,  1592,  1593,  1594,  1595,  1595,  1596,
    1597,  1598,  1599,  1599,  1600,  1601,  1602,  1603,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1619,  1619,  1620,  1621,  1622,  1623,
    1623,  1624,  1625,  1626,  1627,  1628,  1628,  1629,  1630,  1631,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1642,
    1641,  1643,  1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,
    1651,  1652,  1653,  1653,  1654,  1654,  1654,  1654,  1654,  1654,
    1654,  1654,  1654,  1655,  1656,  1657,  1657,  1658,  1659,  1659,
    1660,  1660,  1661,  1662,  1663,  1664,  1665,  1666,  1668,  1667,
    1669,  1669,  1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,
    1678,  1679,  1680,  1681,  1682,  1683,  1684
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
       1,     1,     1,     1,     1,     3,     2,     0,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       0,     2,     1,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       3,     1,     2,     1,     1,     1,     1,     3,     1,     4,
       1,     1,     0,     2,     1,     1,     3,     2,     0,     2,
       1,     1,     1,     1,     3,     1,     4,     1,     1,     0,
       2,     1,     1,     3,     2,     0,     2,     1,     1,     1,
       1,     3,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     3,     0,     2,     3,     1,
       0,     1,     3,     4,     1,     1,     0,     2,     1,     1,
       3,     2,     0,     2,     1,     1,     1,     1,     3,     0,
       2,     2,     1,     1,     1,     1,     3,     4,     1,     1,
       0,     2,     1,     1,     3,     2,     0,     2,     1,     1,
       1,     1,     3,     0,     2,     2,     1,     1,     1,     1,
       3,     4,     1,     1,     0,     2,     1,     1,     3,     2,
       0,     2,     1,     1,     1,     1,     3,     1,     4,     1,
       1,     0,     2,     1,     1,     3,     2,     0,     2,     1,
       1,     1,     1,     3,     0,     2,     3,     1,     0,     2,
       1,     1,     1,     3,     4,     1,     1,     0,     2,     1,
       1,     3,     2,     0,     2,     1,     1,     1,     1,     3,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     2,
       1,     4,     1,     1,     0,     2,     1,     1,     3,     2,
       0,     2,     1,     1,     1,     1,     3,     1,     5,     1,
       0,     1,     1,     3,     1,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       1,     2,     0,     3,     1,     2,     0,     5,     0,     5,
       0,     5,     0,     4,     0,     5,     0,     5,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       3,     1,     1,     0,     4,     0,     6,     0,     4,     0,
       4,     0,     4,     3,     1,     1,     2,     0,     2,     1,
       1,     1,     0,     4,     0,     4,     1,     2,     0,     4,
       0,     2,     1,     1,     4,     4,     0,     4,     0,     2,
       0,     4,     0,     2,     0,     4,     0,     2,     0,     4,
       0,     2,     0,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     1,
       1,     1,     2,     4,     3,     3,     1,     1,     2,     4,
       3,     1,     1,     2,     4,     3,     1,     1,     2,     4,
       2,     1,     2,     2,     1,     3,     2,     1,     2,     2,
       1,     2,     4,     1,     0,     1,     2,     4,     1,     0,
       1,     2,     3,     2,     1,     1,     2,     2,     1,     3,
       2,     1,     2,     2,     1,     3,     2,     1,     3,     0,
       4,     0,     2,     2,     1,     3,     2,     1,     6,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     1,     0,     2,
       1,     1,     3,     1,     3,     3,     1,     3,     0,     5,
       0,     2,     3,     1,     3,     3,     1,     2,     3,     1,
       2,     3,     1,     3,     3,     1,     2
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

  case 1155:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}

    break;

  case 1158:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}

    break;

  case 1159:

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

  case 1160:

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

  case 1175:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++;
}

    break;

  case 1188:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1189:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}

    break;

  case 1192:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1193:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1197:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1198:

    {
    if (osglData->rowMajor == false)
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 1202:

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

  case 1205:

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

  case 1206:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 1212:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1213:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 1220:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1221:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}

    break;

  case 1224:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1225:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1229:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1230:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 1237:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1238:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}

    break;

  case 1241:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1242:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1245:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 1246:

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

  case 1247:

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

  case 1255:

    {
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}

    break;

  case 1256:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
}

    break;

  case 1257:

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

  case 1269:

    {
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}

    break;

  case 1271:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}

    break;

  case 1272:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[-1].ival);
    osglData->osglCounter++;
}

    break;

  case 1274:

    {
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1275:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
}

    break;

  case 1278:

    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1279:

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
        ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
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
    if (osglData->numberOfValues > 0)
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
    }

    break;

  case 1303:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1306:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 1307:

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

  case 1308:

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

  case 1316:

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

  case 1320:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osglData->nonzeroCounter < osglData->numberOfValues) 
            ((ComplexValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
                ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }

    break;

  case 1322:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1323:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}

    break;

  case 1326:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1327:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1331:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1332:

    {
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 1339:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1340:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}

    break;

  case 1343:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1344:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1347:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 1348:

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

  case 1349:

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

  case 1357:

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

  case 1363:

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

  case 1365:

    {
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1366:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
}

    break;

  case 1369:

    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1370:

    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1373:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "expected <value> element");
    }

    break;

  case 1374:

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

  case 1375:

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

  case 1382:

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

  case 1383:

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

  case 1392:

    {
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}

    break;

  case 1393:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
}

    break;

  case 1396:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }

    break;

  case 1397:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }

    break;

  case 1401:

    {
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1402:

    {
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
}

    break;

  case 1409:

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

  case 1411:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}

    break;

  case 1412:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}

    break;

  case 1413:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}

    break;

  case 1414:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}

    break;

  case 1415:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}

    break;

  case 1417:

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

  case 1418:

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

  case 1419:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}

    break;

  case 1420:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}

    break;

  case 1426:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}

    break;

  case 1427:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}

    break;

  case 1428:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}

    break;

  case 1435:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}

    break;

  case 1436:

    {
    osglData->mtxBlkVec.pop_back();
}

    break;

  case 1437:

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

  case 1443:

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

  case 1444:

    {
        ((MatrixBlock*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }

    break;

  case 1448:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}

    break;

  case 1449:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksPresent = true;        
    osglData->numberOfBlocks = (yyvsp[-1].ival);
}

    break;

  case 1450:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsPresent = true;        
    osglData->numberOfColumns = (yyvsp[-1].ival);
}

    break;

  case 1451:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfCon attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <con> cannot be negative");
    osglData->numberOfConPresent = true;        
    osglData->numberOfCon = (yyvsp[-1].ival);
}

    break;

  case 1452:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of constraints cannot be negative");
    osglData->numberOfConstraintsPresent = true;        
    osglData->numberOfConstraints = (yyvsp[-1].ival);
}

    break;

  case 1453:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->numberOfElPresent = true;        
    osglData->numberOfEl = (yyvsp[-1].ival);
}

    break;

  case 1454:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfEnumerationsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <enumerations> cannot be negative");
    osglData->numberOfEnumerationsPresent = true;        
    osglData->numberOfEnumerations = (yyvsp[-1].ival);
}

    break;

  case 1455:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfItemsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfItems attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <items> cannot be negative");
    osglData->numberOfItemsPresent = true;        
    osglData->numberOfItems = (yyvsp[-1].ival);
}

    break;

  case 1456:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfMatrixVar attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <matrixVar> cannot be negative");
    osglData->numberOfMatrixVarPresent = true;        
    osglData->numberOfMatrixVar = (yyvsp[-1].ival);
}

    break;

  case 1457:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfObj attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    osglData->numberOfObjPresent = true;        
    osglData->numberOfObj = (yyvsp[-1].ival);
}

    break;

  case 1458:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of objectives cannot be negative");
    osglData->numberOfObjectivesPresent = true;        
    osglData->numberOfObjectives = (yyvsp[-1].ival);
}

    break;

  case 1459:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <rows> cannot be negative");
std::cout << "Number of rows present" << std::endl;
    osglData->numberOfRowsPresent = true;        
    osglData->numberOfRows = (yyvsp[-1].ival);
}

    break;

  case 1460:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesPresent = true;        
    osglData->numberOfValues = (yyvsp[-1].ival);
}

    break;

  case 1461:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVar attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <var> cannot be negative");
    osglData->numberOfVarPresent = true;        
    osglData->numberOfVar = (yyvsp[-1].ival);
}

    break;

  case 1462:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxPresent = true;        
    osglData->numberOfVarIdx = (yyvsp[-1].ival);
}

    break;

  case 1463:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVariablesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "number of variables cannot be negative");
    osglData->numberOfVariablesPresent = true;        
    osglData->numberOfVariables = (yyvsp[-1].ival);
}

    break;

  case 1464:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->base64SizePresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base64Size attribute previously set");
    if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "base64Size cannot be negative");
    osglData->base64SizePresent = true;        
    osglData->base64Size = (yyvsp[-1].ival);
}

    break;

  case 1465:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    if ((yyvsp[-1].ival) > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = (yyvsp[-1].ival); 
}

    break;

  case 1466:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = (yyvsp[-1].ival); 
}

    break;

  case 1467:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
                                         "baseMatrix first column cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = (yyvsp[-1].ival); 
}

    break;

  case 1468:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix end row cannot be negative");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = (yyvsp[-1].ival); 
}

    break;

  case 1469:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "baseMatrix end col cannot be negative");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = (yyvsp[-1].ival); 
}

    break;

  case 1470:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockRowIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
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

  case 1471:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockColIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ((yyvsp[-1].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "blockColIdx cannot be negative");
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

  case 1472:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[-1].ival);
}

    break;

  case 1473:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[-1].ival);
}

    break;

  case 1474:

    {
    if (osglData->matrixVarIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarIdx attribute in <matrixVar> element");
    osglData->matrixVarIdxPresent = true;
    if ((yyvsp[-1].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "<matrixVarIdx> cannot be negative");
    osglData->matrixVarIdx = (yyvsp[-1].ival); 
}

    break;

  case 1475:

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

  case 1476:

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

  case 1477:

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

  case 1478:

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

  case 1479:

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

  case 1480:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
}

    break;

  case 1481:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
}

    break;

  case 1482:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}

    break;

  case 1485:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}

    break;

  case 1486:

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

  case 1489:

    {
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;
}

    break;

  case 1490:

    { 
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;   
    osglData->category = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1493:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;  
}

    break;

  case 1494:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;   
    osglData->conType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1497:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;
}

    break;

  case 1498:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;   
    osglData->description = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));
}

    break;

  case 1501:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
}

    break;

  case 1502:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
    osglData->enumType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1505:

    {
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
}

    break;

  case 1506:

    {
    if (osglData->matrixVarTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one matrixVarType attribute");
    osglData->matrixVarTypePresent = true;   
    osglData->matrixVarType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1509:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}

    break;

  case 1510:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1513:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
}

    break;

  case 1514:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
    osglData->objType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1517:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}

    break;

  case 1518:

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

  case 1521:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}

    break;

  case 1522:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[-1].sval);
    free((yyvsp[-1].sval));
}

    break;

  case 1525:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
}

    break;

  case 1526:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
    osglData->solver = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1529:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}

    break;

  case 1530:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1533:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}

    break;

  case 1534:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1537:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
}

    break;

  case 1538:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
    osglData->unit = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1541:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}

    break;

  case 1542:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1545:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}

    break;

  case 1546:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1549:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}

    break;

  case 1550:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[-1].sval); 
    free((yyvsp[-1].sval));
}

    break;

  case 1578:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}

    break;

  case 1582:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}

    break;

  case 1586:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1588:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1590:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1592:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1594:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1596:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1598:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1600:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1602:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1604:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1606:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1608:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1611:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1612:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 1613:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1614:

    {
}

    break;

  case 1615:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1616:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 1617:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1619:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1621:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1623:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}

    break;

  case 1624:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}

    break;

  case 1629:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }

    break;

  case 1630:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }

    break;

  case 1632:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[0].sval);
    free((yyvsp[0].sval));
}

    break;

  case 1634:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}

    break;

  case 1635:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}

    break;

  case 1638:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }

    break;

  case 1642:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }

    break;

  case 1643:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }

    break;

  case 1644:

    { 
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}

    break;

  case 1645:

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

  case 1646:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1647:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}

    break;

  case 1649:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }

    break;

  case 1650:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1651:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 1653:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }

    break;

  case 1654:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1655:

    {
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 1657:

    { osnlData->maxVec.back()->inumberOfChildren++; }

    break;

  case 1658:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1659:

    {
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}

    break;

  case 1661:

    { osnlData->minVec.back()->inumberOfChildren++; }

    break;

  case 1662:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1663:

    {
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}

    break;

  case 1665:

    { osnlData->productVec.back()->inumberOfChildren++; }

    break;

  case 1685:

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

  case 1686:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}

    break;

  case 1693:

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

  case 1694:

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

  case 1695:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 1696:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}

    break;

  case 1699:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[-1].ival);
}

    break;

  case 1700:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 1701:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}

    break;

  case 1704:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[-1].ival);
}

    break;

  case 1705:

    {
    osnlData->matrixidxattON = false;
}

    break;

  case 1706:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}

    break;

  case 1709:

    {
    if ( *(yyvsp[-2].sval) != *(yyvsp[0].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[-1].ival);
}

    break;

  case 1711:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1714:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1717:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1720:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1723:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1725:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}

    break;

  case 1728:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1730:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}

    break;

  case 1732:

    {
    if      (strcmp((yyvsp[-1].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[-1].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"1"    ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[-1].sval),"0"    ) == 0) osnlData->includeDiagonalAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[-1].sval));
}

    break;

  case 1734:

    {
     parserData->parser_errors += addErrorMsg( NULL, osresult, parserData, osglData, osnlData, "matrix merge not yet implemented");
}

    break;

  case 1738:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1741:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1744:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1747:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1749:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1750:

    {
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
}

    break;

  case 1752:

    { 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
}

    break;

  case 1754:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1757:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1760:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1773:

    {
}

    break;

  case 1774:

    {
    osglData->realPartPresent = false;
    osglData->imagPartPresent = false;
    osnlData->nlNodePoint = new OSnLCNodeNumber();
    osnlData->nlNodeVec.push_back(osnlData->nlNodePoint);
}

    break;

  case 1777:

    {
    ((OSnLCNodeNumber*)osnlData->nlNodePoint)->setValue(osglData->realPart, osglData->imagPart);
std::cout << "just to verify: value = " 
          << ((OSnLCNodeNumber*)osnlData->nlNodePoint)->getValue() << std::endl;
}

    break;

  case 1783:

    {
    osnlData->nlNodePoint = new OSnLCNodeCreate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1786:

    {
    osnlData->nlNodePoint = new OSnLCNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1788:

    {
    osnlData->nlNodePoint = new OSnLCNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->cSumVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1789:

    {
    osnlData->cSumVec.back()->m_mChildren = new ExprNode*[ osnlData->cSumVec.back()->inumberOfChildren];
    osnlData->cSumVec.pop_back();
}

    break;

  case 1791:

    { 
    osnlData->cSumVec.back()->inumberOfChildren++; 
}

    break;

  case 1793:

    {
    osnlData->nlNodePoint = new OSnLCNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1796:

    {
    osnlData->nlNodePoint = new OSnLCNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1799:

    {
    osnlData->nlNodePoint = new OSnLCNodeConjugate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1802:

    {
    osnlData->nlNodePoint = new OSnLCNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}

    break;

  case 1805:

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

