
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
     COMPLEXCONJUGATESTART = 698,
     COMPLEXCONJUGATEEND = 699,
     COMPLEXMINUSSTART = 700,
     COMPLEXMINUSEND = 701,
     COMPLEXNEGATESTART = 702,
     COMPLEXNEGATEEND = 703,
     COMPLEXNUMBERSTART = 704,
     COMPLEXNUMBEREND = 705,
     COMPLEXPLUSSTART = 706,
     COMPLEXPLUSEND = 707,
     COMPLEXSQUARESTART = 708,
     COMPLEXSQUAREEND = 709,
     COMPLEXSUMSTART = 710,
     COMPLEXSUMEND = 711,
     COMPLEXTIMESSTART = 712,
     COMPLEXTIMESEND = 713,
     CREATECOMPLEXSTART = 714,
     CREATECOMPLEXEND = 715,
     EMPTYINCLUDEDIAGONALATT = 716,
     INCLUDEDIAGONALATT = 717,
     EMPTYIDATT = 718,
     IDATT = 719
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
#define COMPLEXCONJUGATESTART 698
#define COMPLEXCONJUGATEEND 699
#define COMPLEXMINUSSTART 700
#define COMPLEXMINUSEND 701
#define COMPLEXNEGATESTART 702
#define COMPLEXNEGATEEND 703
#define COMPLEXNUMBERSTART 704
#define COMPLEXNUMBEREND 705
#define COMPLEXPLUSSTART 706
#define COMPLEXPLUSEND 707
#define COMPLEXSQUARESTART 708
#define COMPLEXSQUAREEND 709
#define COMPLEXSUMSTART 710
#define COMPLEXSUMEND 711
#define COMPLEXTIMESSTART 712
#define COMPLEXTIMESEND 713
#define CREATECOMPLEXSTART 714
#define CREATECOMPLEXEND 715
#define EMPTYINCLUDEDIAGONALATT 716
#define INCLUDEDIAGONALATT 717
#define EMPTYIDATT 718
#define IDATT 719




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
#define YYLAST   2163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  469
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  1209
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1804
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2538

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   719

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   466,
     468,     2,     2,   467,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   465,     2,     2,     2,     2,     2,     2,     2,
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
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464
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
    4346,  4349,  4352,  4354,  4358,  4361,  4363,  4370,  4373,  4375,
    4378,  4380,  4382,  4384,  4386,  4388,  4390,  4392,  4394,  4396,
    4398,  4400,  4404,  4406,  4408,  4411,  4413,  4414,  4417,  4419,
    4421,  4425,  4427,  4431,  4435,  4437,  4441,  4442,  4448,  4449,
    4452,  4456,  4458,  4462,  4466,  4468,  4471,  4475,  4477,  4480,
    4484,  4486,  4490,  4494,  4496
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     470,     0,    -1,   471,   479,   477,    -1,   472,   473,   474,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   475,    -1,
     476,    -1,    11,    -1,    10,   479,   477,    -1,   478,    -1,
      15,    -1,    -1,   480,   481,   561,   615,   667,   762,    -1,
      -1,  1111,    -1,    -1,   482,   483,    -1,   309,    -1,   484,
      -1,   485,    -1,    10,   310,    -1,    11,    -1,    10,   486,
     310,    -1,   487,    -1,   488,    -1,   487,   488,    -1,   489,
      -1,   505,    -1,   511,    -1,   517,    -1,   523,    -1,   529,
      -1,   535,    -1,   541,    -1,   547,    -1,   490,   491,   494,
      -1,    56,    -1,   492,    -1,   493,    -1,   492,   493,    -1,
    1492,    -1,  1465,    -1,  1104,    -1,   495,    -1,   496,    -1,
      10,    57,    -1,    11,    -1,    10,   497,    57,    -1,   498,
      -1,   499,    -1,   498,   499,    -1,   500,   501,   504,    -1,
      88,    -1,   502,    -1,    -1,   502,   503,    -1,  1474,    -1,
    1465,    -1,    10,    89,    -1,    11,    -1,   506,   507,    -1,
      60,    -1,   508,    -1,   509,    -1,    10,    61,    -1,    11,
      -1,    10,   510,    61,    -1,     4,    -1,   512,   513,    -1,
     333,    -1,   514,    -1,   515,    -1,    10,   334,    -1,    11,
      -1,    10,   516,   334,    -1,     4,    -1,   518,   519,    -1,
     335,    -1,   520,    -1,   521,    -1,    10,   336,    -1,    11,
      -1,    10,   522,   336,    -1,     4,    -1,   524,   525,    -1,
     337,    -1,   526,    -1,   527,    -1,    10,   338,    -1,    11,
      -1,    10,   528,   338,    -1,     4,    -1,   530,   531,    -1,
     339,    -1,   532,    -1,   533,    -1,    10,   340,    -1,    11,
      -1,    10,   534,   340,    -1,     4,    -1,   536,   537,    -1,
      80,    -1,   538,    -1,   539,    -1,    10,    81,    -1,    11,
      -1,    10,   540,    81,    -1,     4,    -1,   542,   543,    -1,
      96,    -1,   544,    -1,   545,    -1,    10,    97,    -1,    11,
      -1,    10,   546,    97,    -1,     4,    -1,   548,   549,   550,
      -1,    66,    -1,  1099,    -1,   551,    -1,   552,    -1,    10,
      67,    -1,    11,    -1,    10,   553,    67,    -1,   554,    -1,
     555,    -1,   554,   555,    -1,   556,   557,   560,    -1,   341,
      -1,   558,    -1,    -1,   558,   559,    -1,  1474,    -1,  1498,
      -1,  1465,    -1,    10,   342,    -1,    11,    -1,    -1,   562,
     563,    -1,   311,    -1,   564,    -1,   565,    -1,    10,   312,
      -1,    11,    -1,    10,   566,   312,    -1,   567,    -1,   568,
      -1,   567,   568,    -1,   569,    -1,   575,    -1,   582,    -1,
     589,    -1,   596,    -1,   601,    -1,   570,   571,    -1,    90,
      -1,   572,    -1,   573,    -1,    10,    91,    -1,    11,    -1,
      10,   574,    91,    -1,     4,    -1,   576,   577,   580,    -1,
      40,    -1,   578,    -1,    -1,   578,   579,    -1,  1495,    -1,
    1465,    -1,    10,   581,    41,    -1,  1106,    -1,   583,   584,
     587,    -1,    42,    -1,   585,    -1,    -1,   585,   586,    -1,
    1495,    -1,  1465,    -1,    10,   588,    43,    -1,  1106,    -1,
     590,   591,   594,    -1,    38,    -1,   592,    -1,    -1,   592,
     593,    -1,  1495,    -1,  1465,    -1,    10,   595,    39,    -1,
    1106,    -1,   597,   598,   599,    -1,    36,    -1,    -1,  1465,
      -1,    10,   600,    37,    -1,     6,    -1,   602,   603,   604,
      -1,    66,    -1,  1099,    -1,   605,    -1,   606,    -1,    10,
      67,    -1,    11,    -1,    10,   607,    67,    -1,   608,    -1,
     609,    -1,   608,   609,    -1,   610,   611,   614,    -1,   341,
      -1,   612,    -1,    -1,   612,   613,    -1,  1474,    -1,  1498,
      -1,  1465,    -1,    10,   342,    -1,    11,    -1,    -1,   616,
     617,    -1,   313,    -1,   618,    -1,   619,    -1,    10,   314,
      -1,    11,    -1,    10,   620,   314,    -1,   621,    -1,   622,
      -1,   621,   622,    -1,   623,    -1,   629,    -1,   635,    -1,
     641,    -1,   647,    -1,   653,    -1,   624,   625,    -1,    48,
      -1,   626,    -1,   627,    -1,    10,    49,    -1,    11,    -1,
      10,   628,    49,    -1,     4,    -1,   630,   631,    -1,    46,
      -1,   632,    -1,   633,    -1,    10,    47,    -1,    11,    -1,
      10,   634,    47,    -1,     6,    -1,   636,   637,    -1,   100,
      -1,   638,    -1,   639,    -1,    10,   101,    -1,    11,    -1,
      10,   640,   101,    -1,     6,    -1,   642,   643,    -1,    94,
      -1,   644,    -1,   645,    -1,    10,    95,    -1,    11,    -1,
      10,   646,    95,    -1,     4,    -1,   648,   649,    -1,    76,
      -1,   650,    -1,   651,    -1,    10,    77,    -1,    11,    -1,
      10,   652,    77,    -1,  1106,    -1,   654,   655,   656,    -1,
      66,    -1,  1099,    -1,   657,    -1,   658,    -1,    10,    67,
      -1,    11,    -1,    10,   659,    67,    -1,   660,    -1,   661,
      -1,   660,   661,    -1,   662,   663,   666,    -1,   341,    -1,
     664,    -1,    -1,   664,   665,    -1,  1474,    -1,  1498,    -1,
    1465,    -1,    10,   342,    -1,    11,    -1,    -1,   668,   669,
      -1,   315,    -1,   670,    -1,   671,    -1,    10,   316,    -1,
      11,    -1,    10,   672,   316,    -1,   673,    -1,   674,    -1,
     673,   674,    -1,   675,    -1,   681,    -1,   687,    -1,   693,
      -1,   699,    -1,   705,    -1,   722,    -1,   729,    -1,   736,
      -1,   743,    -1,   748,    -1,   676,   677,    -1,    84,    -1,
     678,    -1,   679,    -1,    10,    85,    -1,    11,    -1,    10,
     680,    85,    -1,     4,    -1,   682,   683,    -1,    86,    -1,
     684,    -1,   685,    -1,    10,    87,    -1,    11,    -1,    10,
     686,    87,    -1,     4,    -1,   688,   689,    -1,    74,    -1,
     690,    -1,   691,    -1,    10,    75,    -1,    11,    -1,    10,
     692,    75,    -1,     4,    -1,   694,   695,    -1,    34,    -1,
     696,    -1,   697,    -1,    10,    35,    -1,    11,    -1,    10,
     698,    35,    -1,     4,    -1,   700,   701,    -1,    52,    -1,
     702,    -1,   703,    -1,    10,    53,    -1,    11,    -1,    10,
     704,    53,    -1,     4,    -1,   706,   707,   708,    -1,    98,
      -1,  1105,    -1,   709,    -1,   710,    -1,    10,    99,    -1,
      11,    -1,    10,   711,    99,    -1,   712,    -1,   713,    -1,
     712,   713,    -1,   714,   715,   717,    -1,    92,    -1,    -1,
     715,   716,    -1,  1495,    -1,  1492,    -1,  1459,    -1,  1465,
      -1,   718,    -1,   719,    -1,    10,    93,    -1,    11,    -1,
      10,   720,    93,    -1,   721,    -1,     7,    -1,     6,    -1,
     723,   724,   727,    -1,   106,    -1,   725,    -1,    -1,   725,
     726,    -1,  1495,    -1,  1465,    -1,    10,   728,   107,    -1,
    1106,    -1,   730,   731,   734,    -1,   108,    -1,   732,    -1,
      -1,   732,   733,    -1,  1495,    -1,  1465,    -1,    10,   735,
     109,    -1,  1106,    -1,   737,   738,   741,    -1,   104,    -1,
     739,    -1,    -1,   739,   740,    -1,  1495,    -1,  1465,    -1,
      10,   742,   105,    -1,  1106,    -1,   744,   745,   746,    -1,
     102,    -1,    -1,  1465,    -1,    10,   747,   103,    -1,     6,
      -1,   749,   750,   751,    -1,    66,    -1,  1099,    -1,   752,
      -1,   753,    -1,    10,    67,    -1,    11,    -1,    10,   754,
      67,    -1,   755,    -1,   756,    -1,   755,   756,    -1,   757,
     758,   761,    -1,   341,    -1,   759,    -1,    -1,   759,   760,
      -1,  1474,    -1,  1498,    -1,  1465,    -1,    10,   342,    -1,
      11,    -1,    -1,   763,   764,   767,    -1,   317,    -1,   765,
      -1,    -1,   765,   766,    -1,  1102,    -1,  1436,    -1,  1425,
      -1,  1431,    -1,   768,    -1,   769,    -1,    10,   318,    -1,
      11,    -1,    10,   770,   318,    -1,   771,  1072,    -1,   772,
      -1,   771,   772,    -1,   773,   774,   780,    -1,    78,    -1,
     775,    -1,    -1,   775,   776,    -1,   777,    -1,   778,    -1,
     779,    -1,    33,  1108,     6,  1108,    -1,    18,     3,  1108,
      -1,    16,     3,  1108,    -1,    10,   781,   797,   803,   881,
     943,  1005,  1049,    79,    -1,   782,   783,   786,    -1,    84,
      -1,   784,    -1,   785,    -1,   784,   785,    -1,  1492,    -1,
    1465,    -1,  1104,    -1,   787,    -1,   788,    -1,    10,    85,
      -1,    11,    -1,    10,   789,    85,    -1,   790,    -1,   791,
      -1,   790,   791,    -1,   792,   793,   796,    -1,    88,    -1,
     794,    -1,    -1,   794,   795,    -1,  1492,    -1,  1465,    -1,
      10,    89,    -1,    11,    -1,    -1,   798,   799,    -1,    60,
      -1,   800,    -1,   801,    -1,    10,    61,    -1,    11,    -1,
      10,   802,    61,    -1,     4,    -1,    -1,   804,   805,   806,
      -1,   307,    -1,    -1,  1101,    -1,   807,    -1,   808,    -1,
      11,    -1,    10,   809,   308,    -1,   810,   823,   839,   852,
      -1,    -1,   811,   812,   813,    -1,   144,    -1,  1434,    -1,
     814,    -1,   815,    -1,    10,   145,    -1,    11,    -1,    10,
     816,   145,    -1,   817,    -1,   818,    -1,   817,   818,    -1,
     819,   820,   822,    -1,   305,    -1,    -1,   820,   821,    -1,
    1445,    -1,  1474,    -1,    10,  1106,   306,    -1,    -1,   824,
     825,   826,    -1,   110,    -1,  1434,    -1,   827,    -1,   828,
      -1,    10,   111,    -1,    11,    -1,    10,   829,   111,    -1,
     830,    -1,   831,    -1,   830,   831,    -1,   832,   833,   835,
      -1,   305,    -1,    -1,   833,   834,    -1,  1445,    -1,  1474,
      -1,   836,    -1,   837,    -1,    10,   306,    -1,    11,    -1,
      10,   838,   306,    -1,     4,    -1,    -1,   840,   841,    -1,
      44,    -1,   842,    -1,   843,    -1,    11,    -1,    10,   844,
      45,    -1,   845,   846,   847,   848,   849,   850,   851,    -1,
      -1,  1167,    -1,    -1,  1173,    -1,    -1,  1179,    -1,    -1,
    1185,    -1,    -1,  1191,    -1,    -1,  1197,    -1,    -1,  1203,
      -1,    -1,   852,   853,    -1,   854,   855,   858,    -1,   341,
      -1,   856,    -1,    -1,   856,   857,    -1,  1434,    -1,  1427,
      -1,  1498,    -1,  1486,    -1,  1474,    -1,  1492,    -1,  1504,
      -1,  1468,    -1,  1465,    -1,   859,    -1,   860,    -1,    10,
     342,    -1,    11,    -1,    10,   861,   342,    -1,   862,    -1,
     871,    -1,   863,    -1,   862,   863,    -1,   864,   865,   867,
      -1,   305,    -1,    -1,   865,   866,    -1,  1445,    -1,  1474,
      -1,   868,    -1,   869,    -1,    10,   306,    -1,    11,    -1,
      10,   870,   306,    -1,  1107,    -1,   872,    -1,   871,   872,
      -1,   873,   874,   877,    -1,   150,    -1,   875,    -1,    -1,
     875,   876,    -1,  1426,    -1,  1498,    -1,  1465,    -1,   878,
      -1,   879,    -1,    11,    -1,    10,   880,   151,    -1,  1139,
      -1,    -1,   882,   883,   884,    -1,   303,    -1,    -1,  1098,
      -1,   885,    -1,   886,    -1,    11,    -1,    10,   887,   304,
      -1,   888,   901,   914,    -1,    -1,   889,   890,   891,    -1,
     144,    -1,  1430,    -1,   892,    -1,   893,    -1,    10,   145,
      -1,    11,    -1,    10,   894,   145,    -1,   895,    -1,   896,
      -1,   895,   896,    -1,   897,   898,   900,    -1,   301,    -1,
      -1,   898,   899,    -1,  1445,    -1,  1474,    -1,    10,  1106,
     302,    -1,    -1,   902,   903,    -1,    44,    -1,   904,    -1,
     905,    -1,    11,    -1,    10,   906,    45,    -1,   907,   908,
     909,   910,   911,   912,   913,    -1,    -1,  1167,    -1,    -1,
    1173,    -1,    -1,  1179,    -1,    -1,  1185,    -1,    -1,  1191,
      -1,    -1,  1197,    -1,    -1,  1203,    -1,    -1,   914,   915,
      -1,   916,   917,   920,    -1,   341,    -1,   918,    -1,    -1,
     918,   919,    -1,  1430,    -1,  1427,    -1,  1498,    -1,  1486,
      -1,  1474,    -1,  1492,    -1,  1477,    -1,  1468,    -1,  1465,
      -1,   921,    -1,   922,    -1,    10,   342,    -1,    11,    -1,
      10,   923,   342,    -1,   924,    -1,   933,    -1,   925,    -1,
     924,   925,    -1,   926,   927,   929,    -1,   301,    -1,    -1,
     927,   928,    -1,  1445,    -1,  1474,    -1,   930,    -1,   931,
      -1,    10,   302,    -1,    11,    -1,    10,   932,   302,    -1,
    1107,    -1,   934,    -1,   933,   934,    -1,   935,   936,   939,
      -1,   150,    -1,   937,    -1,    -1,   937,   938,    -1,  1426,
      -1,  1498,    -1,  1465,    -1,   940,    -1,   941,    -1,    11,
      -1,    10,   942,   151,    -1,  1139,    -1,    -1,   944,   945,
     946,    -1,   299,    -1,    -1,  1095,    -1,   947,    -1,   948,
      -1,    11,    -1,    10,   949,   300,    -1,   950,   963,   976,
      -1,    -1,   951,   952,   953,    -1,    50,    -1,  1424,    -1,
     954,    -1,   955,    -1,    10,    51,    -1,    11,    -1,    10,
     956,    51,    -1,   957,    -1,   958,    -1,   957,   958,    -1,
     959,   960,   962,    -1,   297,    -1,    -1,   960,   961,    -1,
    1445,    -1,  1474,    -1,    10,  1106,   298,    -1,    -1,   964,
     965,    -1,    44,    -1,   966,    -1,   967,    -1,    11,    -1,
      10,   968,    45,    -1,   969,   970,   971,   972,   973,   974,
     975,    -1,    -1,  1167,    -1,    -1,  1173,    -1,    -1,  1179,
      -1,    -1,  1185,    -1,    -1,  1191,    -1,    -1,  1197,    -1,
      -1,  1203,    -1,    -1,   976,   977,    -1,   978,   979,   982,
      -1,   341,    -1,   980,    -1,    -1,   980,   981,    -1,  1424,
      -1,  1427,    -1,  1498,    -1,  1486,    -1,  1474,    -1,  1492,
      -1,  1462,    -1,  1468,    -1,  1465,    -1,   983,    -1,   984,
      -1,    10,   342,    -1,    11,    -1,    10,   985,   342,    -1,
     986,    -1,   995,    -1,   987,    -1,   986,   987,    -1,   988,
     989,   991,    -1,   297,    -1,    -1,   989,   990,    -1,  1445,
      -1,  1474,    -1,   992,    -1,   993,    -1,    10,   298,    -1,
      11,    -1,    10,   994,   298,    -1,  1107,    -1,   996,    -1,
     995,   996,    -1,   997,   998,  1001,    -1,   150,    -1,   999,
      -1,    -1,   999,  1000,    -1,  1426,    -1,  1498,    -1,  1465,
      -1,  1002,    -1,  1003,    -1,    11,    -1,    10,  1004,   151,
      -1,  1139,    -1,    -1,  1006,  1007,  1008,    -1,   283,    -1,
      -1,  1096,    -1,  1009,    -1,  1010,    -1,    11,    -1,    10,
    1011,  1047,   284,    -1,    -1,  1012,  1013,  1014,    -1,   285,
      -1,  1097,    -1,  1015,    -1,  1016,    -1,    11,    -1,    10,
    1018,  1026,  1017,    -1,   286,    -1,    -1,  1019,  1020,  1021,
      -1,   144,    -1,  1429,    -1,  1022,    -1,  1023,    -1,    11,
      -1,    10,  1025,  1024,    -1,   145,    -1,    -1,  1025,  1210,
      -1,    -1,  1026,  1027,    -1,  1028,  1029,  1032,    -1,   341,
      -1,  1030,    -1,    -1,  1030,  1031,    -1,  1429,    -1,  1427,
      -1,  1498,    -1,  1486,    -1,  1474,    -1,  1492,    -1,  1471,
      -1,  1468,    -1,  1465,    -1,  1033,    -1,  1034,    -1,    10,
     342,    -1,    11,    -1,    10,  1035,   342,    -1,  1037,    -1,
    1036,    -1,  1210,    -1,  1036,  1210,    -1,  1038,    -1,  1037,
    1038,    -1,  1039,  1040,  1043,    -1,   150,    -1,  1041,    -1,
      -1,  1041,  1042,    -1,  1426,    -1,  1498,    -1,  1465,    -1,
    1044,    -1,  1045,    -1,    11,    -1,    10,  1046,   151,    -1,
    1139,    -1,    -1,  1047,  1048,    -1,   118,    -1,    -1,  1050,
    1051,  1052,    -1,    70,    -1,  1100,    -1,  1053,    -1,  1054,
      -1,    10,    71,    -1,    11,    -1,    10,  1055,    71,    -1,
    1056,    -1,  1057,    -1,  1056,  1057,    -1,  1058,  1059,  1062,
      -1,    68,    -1,  1060,    -1,    -1,  1060,  1061,    -1,  1474,
      -1,  1498,    -1,  1459,    -1,  1465,    -1,  1428,    -1,  1063,
      -1,  1064,    -1,    10,    69,    -1,    11,    -1,    10,  1065,
      69,    -1,  1066,    -1,  1067,    -1,  1066,  1067,    -1,  1068,
      -1,  1069,    -1,  1070,    -1,   155,    -1,   152,    -1,   153,
    1071,   154,    -1,     5,    -1,    -1,  1073,  1074,  1075,    -1,
      72,    -1,  1103,    -1,  1076,    -1,  1077,    -1,    10,    73,
      -1,    11,    -1,    10,  1078,    73,    -1,  1079,    -1,  1080,
      -1,  1079,  1080,    -1,  1081,  1082,  1085,    -1,    82,    -1,
    1083,    -1,    -1,  1083,  1084,    -1,  1474,    -1,  1459,    -1,
    1465,    -1,  1428,    -1,  1086,    -1,  1087,    -1,    10,    83,
      -1,    11,    -1,    10,  1088,    83,    -1,  1089,    -1,  1090,
      -1,  1089,  1090,    -1,  1091,    -1,  1092,    -1,  1093,    -1,
     155,    -1,   152,    -1,   153,  1094,   154,    -1,     5,    -1,
      20,  1108,     6,  1108,    -1,    28,  1108,     6,  1108,    -1,
      29,  1108,     6,  1108,    -1,    21,  1108,     6,  1108,    -1,
      22,  1108,     6,  1108,    -1,    23,  1108,     6,  1108,    -1,
      24,  1108,     6,  1108,    -1,    25,  1108,     6,  1108,    -1,
      30,  1108,     6,  1108,    -1,    31,  1108,     6,  1108,    -1,
      32,  1108,     6,  1108,    -1,     6,    -1,     7,    -1,     4,
      -1,     6,    -1,     7,    -1,  1109,     8,    -1,    -1,  1109,
    1110,    -1,   465,    -1,   466,    -1,   467,    -1,   468,    -1,
    1112,  1113,    -1,   120,    -1,  1114,    -1,  1115,    -1,    11,
      -1,    10,  1116,   121,    -1,  1117,    -1,    -1,  1117,  1118,
      -1,  1119,    -1,  1123,    -1,  1127,    -1,  1131,    -1,  1135,
      -1,  1120,    -1,  1121,    -1,  1122,    -1,   125,    -1,   124,
      -1,   122,     5,   123,    -1,  1124,    -1,  1125,    -1,  1126,
      -1,   129,    -1,   128,    -1,   126,     5,   127,    -1,  1128,
      -1,  1129,    -1,  1130,    -1,   133,    -1,   132,    -1,   130,
       5,   131,    -1,  1132,    -1,  1133,    -1,  1134,    -1,   137,
      -1,   136,    -1,   134,     5,   135,    -1,  1136,    -1,  1137,
      -1,  1138,    -1,   141,    -1,   140,    -1,   138,     5,   139,
      -1,  1140,    -1,  1147,    -1,    -1,  1140,  1141,    -1,  1142,
    1143,  1146,    -1,   148,    -1,  1144,    -1,    -1,  1144,  1145,
      -1,  1448,    -1,  1446,    -1,    10,     6,   149,    -1,   156,
    1437,  1148,    -1,  1149,    -1,  1150,    -1,    10,   157,    -1,
      11,    -1,    10,     4,   157,    -1,  1152,    -1,  1157,    -1,
      -1,  1152,  1153,    -1,  1154,  1155,  1156,    -1,   148,    -1,
      -1,  1448,    -1,    10,  1106,   149,    -1,   156,  1437,  1158,
      -1,  1159,    -1,  1160,    -1,    10,   157,    -1,    11,    -1,
      10,     4,   157,    -1,  1162,    -1,    -1,  1162,  1163,    -1,
    1164,  1165,  1166,    -1,   148,    -1,    -1,  1448,    -1,    10,
       4,   149,    -1,  1168,  1209,  1169,    -1,   325,    -1,  1170,
      -1,  1171,    -1,    11,    -1,    10,  1172,   326,    -1,  1139,
      -1,  1174,  1209,  1175,    -1,   321,    -1,  1176,    -1,  1177,
      -1,    11,    -1,    10,  1178,   322,    -1,  1139,    -1,  1180,
    1209,  1181,    -1,   323,    -1,  1182,    -1,  1183,    -1,    11,
      -1,    10,  1184,   324,    -1,  1139,    -1,  1186,  1209,  1187,
      -1,   319,    -1,  1188,    -1,  1189,    -1,    11,    -1,    10,
    1190,   320,    -1,  1139,    -1,  1192,  1209,  1193,    -1,   327,
      -1,  1194,    -1,  1195,    -1,    11,    -1,    10,  1196,   328,
      -1,  1139,    -1,  1198,  1209,  1199,    -1,   329,    -1,  1200,
      -1,  1201,    -1,    11,    -1,    10,  1202,   330,    -1,  1139,
      -1,  1204,  1209,  1205,    -1,   331,    -1,  1206,    -1,  1207,
      -1,    11,    -1,    10,  1208,   332,    -1,  1139,    -1,  1426,
      -1,  1211,  1212,  1215,    -1,   287,    -1,  1213,    -1,    -1,
    1213,  1214,    -1,  1489,    -1,  1432,    -1,  1423,    -1,  1474,
      -1,  1492,    -1,  1447,    -1,  1216,    -1,  1217,    -1,    11,
      -1,    10,  1218,   288,    -1,  1219,  1225,    -1,    -1,  1220,
    1221,  1224,    -1,   244,    -1,  1222,    -1,    -1,  1222,  1223,
      -1,  1438,    -1,  1449,    -1,  1450,    -1,  1439,    -1,  1440,
      -1,  1441,    -1,  1442,    -1,  1456,    -1,  1455,    -1,    10,
     243,    -1,    11,    -1,    -1,  1225,  1226,    -1,  1227,    -1,
    1252,    -1,  1265,    -1,  1292,    -1,  1328,    -1,  1341,    -1,
    1359,    -1,  1310,    -1,  1377,    -1,  1390,    -1,  1394,    -1,
    1228,  1229,    10,  1232,    -1,   255,    -1,  1230,    -1,    -1,
    1230,  1231,    -1,  1433,    -1,  1480,    -1,  1234,  1233,   256,
      -1,    -1,  1240,  1246,    -1,  1235,  1236,    -1,   273,    -1,
    1237,    -1,  1238,    -1,    11,    -1,    10,  1239,   274,    -1,
    1139,    -1,  1241,  1242,    -1,   275,    -1,  1243,    -1,  1244,
      -1,    11,    -1,    10,  1245,   276,    -1,  1139,    -1,  1247,
    1248,    -1,   277,    -1,  1249,    -1,  1250,    -1,    11,    -1,
      10,  1251,   278,    -1,  1151,    -1,  1253,  1254,    10,  1257,
      -1,   259,    -1,  1255,    -1,    -1,  1255,  1256,    -1,  1433,
      -1,  1480,    -1,  1234,  1258,   260,    -1,    -1,  1240,  1259,
      -1,  1260,  1261,    -1,   277,    -1,  1262,    -1,  1263,    -1,
      11,    -1,    10,  1264,   278,    -1,  1139,    -1,  1266,  1267,
      10,  1270,    -1,   261,    -1,  1268,    -1,    -1,  1268,  1269,
      -1,  1433,    -1,  1480,    -1,  1234,  1271,   262,    -1,    -1,
    1240,  1272,    -1,    -1,  1273,  1274,    -1,   277,    -1,  1275,
      -1,  1276,    -1,    11,    -1,    10,  1277,   278,    -1,  1278,
      -1,    -1,  1278,  1279,    -1,  1280,  1281,  1284,    -1,   148,
      -1,  1282,    -1,    -1,  1282,  1283,    -1,  1435,    -1,  1452,
      -1,  1285,    -1,  1286,    -1,    11,    -1,    10,  1287,   149,
      -1,    -1,  1287,  1288,    -1,  1289,  1290,  1291,    -1,   279,
      -1,    -1,  1451,    -1,    10,     6,   280,    -1,  1293,  1294,
      10,  1297,    -1,   267,    -1,  1295,    -1,    -1,  1295,  1296,
      -1,  1433,    -1,  1480,    -1,  1234,  1298,   268,    -1,    -1,
    1240,  1299,    -1,    -1,  1300,  1301,    -1,   277,    -1,  1302,
      -1,  1303,    -1,    11,    -1,    10,  1304,   278,    -1,    -1,
    1304,  1305,    -1,  1306,  1307,    -1,   148,    -1,  1308,    -1,
    1309,    -1,    11,    -1,    10,  1507,   149,    -1,  1311,  1312,
      10,  1315,    -1,   269,    -1,  1313,    -1,    -1,  1313,  1314,
      -1,  1433,    -1,  1480,    -1,  1234,  1316,   270,    -1,    -1,
    1240,  1317,    -1,    -1,  1318,  1319,    -1,   277,    -1,  1320,
      -1,  1321,    -1,    11,    -1,    10,  1322,   278,    -1,    -1,
    1322,  1323,    -1,  1324,  1325,    -1,   148,    -1,  1326,    -1,
    1327,    -1,    11,    -1,    10,  1647,   149,    -1,  1329,  1330,
      10,  1333,    -1,   265,    -1,  1331,    -1,    -1,  1331,  1332,
      -1,  1433,    -1,  1480,    -1,  1234,  1334,   266,    -1,    -1,
    1240,  1335,    -1,  1336,  1337,    -1,   277,    -1,  1338,    -1,
    1339,    -1,    11,    -1,    10,  1340,   278,    -1,  1139,    -1,
    1342,  1343,    10,  1346,    -1,   263,    -1,  1344,    -1,    -1,
    1344,  1345,    -1,  1433,    -1,  1480,    -1,  1234,  1347,   264,
      -1,    -1,  1240,  1348,    -1,    -1,  1349,  1350,    -1,   277,
      -1,  1351,    -1,  1352,    -1,    11,    -1,    10,  1353,   278,
      -1,    -1,  1353,  1354,    -1,  1355,  1356,  1358,    -1,   148,
      -1,    -1,  1356,  1357,    -1,  1501,    -1,  1448,    -1,  1446,
      -1,    10,     6,   149,    -1,  1360,  1361,    10,  1364,    -1,
     257,    -1,  1362,    -1,    -1,  1362,  1363,    -1,  1433,    -1,
    1480,    -1,  1234,  1365,   258,    -1,    -1,  1240,  1366,    -1,
      -1,  1367,  1368,    -1,   277,    -1,  1369,    -1,  1370,    -1,
      11,    -1,    10,  1371,   278,    -1,    -1,  1371,  1372,    -1,
    1373,  1374,  1376,    -1,   148,    -1,    -1,  1374,  1375,    -1,
    1454,    -1,  1453,    -1,  1448,    -1,    10,   149,    -1,    11,
      -1,  1378,  1379,    10,  1382,    -1,   271,    -1,  1380,    -1,
      -1,  1380,  1381,    -1,  1433,    -1,  1480,    -1,  1234,  1383,
     272,    -1,    -1,  1240,  1384,    -1,  1385,  1386,    -1,   277,
      -1,  1387,    -1,  1388,    -1,    11,    -1,    10,  1389,   278,
      -1,  1161,    -1,  1391,  1392,    10,  1581,  1393,    -1,   281,
      -1,    -1,  1483,    -1,   282,    -1,  1395,  1396,  1397,    -1,
     245,    -1,  1422,    -1,    10,  1399,  1406,  1413,  1398,    -1,
     246,    -1,  1400,  1401,  1402,    -1,   249,    -1,  1426,    -1,
    1403,    -1,  1404,    -1,    11,    -1,    10,  1405,   250,    -1,
    1139,    -1,  1407,  1408,  1409,    -1,   251,    -1,  1426,    -1,
    1410,    -1,  1411,    -1,    11,    -1,    10,  1412,   252,    -1,
    1139,    -1,    -1,  1413,  1414,    -1,  1415,  1416,  1419,    -1,
     247,    -1,  1417,    -1,    -1,  1417,  1418,    -1,  1443,    -1,
    1444,    -1,  1489,    -1,  1492,    -1,  1420,    -1,  1421,    -1,
      11,    -1,    10,  1218,   248,    -1,   201,     8,     6,     8,
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
      -1,   230,  1108,     6,  1108,    -1,   235,     8,     6,     8,
      -1,   219,     8,     6,     8,    -1,   220,     8,     6,     8,
      -1,   237,     8,  1106,     8,    -1,   238,     8,  1106,     8,
      -1,   229,     8,  1106,     8,    -1,   228,     8,  1106,     8,
      -1,   225,     8,  1106,     8,    -1,  1457,    -1,  1458,    -1,
     199,    -1,   200,     3,  1108,    -1,  1460,    -1,  1461,    -1,
     161,    -1,   162,     3,     8,    -1,  1463,    -1,  1464,    -1,
     181,    -1,   182,     3,     8,    -1,  1466,    -1,  1467,    -1,
     163,    -1,   164,     3,     8,    -1,  1469,    -1,  1470,    -1,
     171,    -1,   172,     3,     8,    -1,  1472,    -1,  1473,    -1,
     191,    -1,   192,     3,     8,    -1,  1475,    -1,  1476,    -1,
     167,    -1,   168,     3,     8,    -1,  1478,    -1,  1479,    -1,
     183,    -1,   184,     3,     8,    -1,  1481,    -1,  1482,    -1,
     197,    -1,   198,     3,     8,    -1,  1484,    -1,  1485,    -1,
     173,    -1,   174,     3,     8,    -1,  1487,    -1,  1488,    -1,
     165,    -1,   166,     3,     8,    -1,  1490,    -1,  1491,    -1,
     195,    -1,   196,     3,     8,    -1,  1493,    -1,  1494,    -1,
     169,    -1,   170,     3,     8,    -1,  1496,    -1,  1497,    -1,
     175,    -1,   176,     3,     8,    -1,  1499,    -1,  1500,    -1,
     177,    -1,   178,     3,     8,    -1,  1502,    -1,  1503,    -1,
     179,    -1,   180,     3,     8,    -1,  1505,    -1,  1506,    -1,
     185,    -1,   186,     3,     8,    -1,  1551,    -1,  1558,    -1,
    1514,    -1,  1516,    -1,  1566,    -1,  1518,    -1,  1520,    -1,
    1522,    -1,  1524,    -1,  1578,    -1,  1526,    -1,  1528,    -1,
    1530,    -1,  1534,    -1,  1532,    -1,  1536,    -1,  1543,    -1,
    1538,    -1,  1541,    -1,  1572,    -1,  1575,    -1,  1508,    -1,
    1511,    -1,  1569,    -1,  1545,    -1,  1547,    -1,  1549,    -1,
      -1,   397,  1509,  1510,    -1,    11,    -1,    10,   398,    -1,
      -1,   399,  1512,  1513,    -1,    11,    -1,    10,   400,    -1,
      -1,   401,  1515,  1507,  1507,   402,    -1,    -1,   359,  1517,
    1507,  1507,   360,    -1,    -1,   361,  1519,  1507,  1507,   362,
      -1,    -1,   375,  1521,  1507,   376,    -1,    -1,   363,  1523,
    1507,  1507,   364,    -1,    -1,   357,  1525,  1507,  1507,   358,
      -1,    -1,   365,  1527,  1507,   366,    -1,    -1,   367,  1529,
    1507,   368,    -1,    -1,   379,  1531,  1507,   380,    -1,    -1,
     381,  1533,  1507,   382,    -1,    -1,   383,  1535,  1507,   384,
      -1,    -1,   373,  1537,  1507,   374,    -1,  1539,  1507,  1540,
      -1,   387,    -1,   388,    -1,    -1,   389,  1542,  1507,   390,
      -1,    -1,   377,  1544,  1507,  1507,  1507,   378,    -1,    -1,
     405,  1546,  1581,   406,    -1,    -1,   407,  1548,  1581,   408,
      -1,    -1,   409,  1550,  1581,   410,    -1,  1552,  1554,  1553,
      -1,   403,    -1,    11,    -1,    10,   404,    -1,    -1,  1554,
    1555,    -1,  1492,    -1,  1498,    -1,  1556,    -1,    -1,   464,
       3,  1557,     8,    -1,    -1,   385,  1559,  1562,  1560,    -1,
      11,    -1,    10,   386,    -1,    -1,    10,  1507,  1561,   386,
      -1,    -1,  1562,  1563,    -1,  1564,    -1,  1565,    -1,   237,
       8,  1106,     8,    -1,   233,     8,     6,     8,    -1,    -1,
     369,  1567,  1568,   370,    -1,    -1,  1568,  1507,    -1,    -1,
     393,  1570,  1571,   394,    -1,    -1,  1571,  1507,    -1,    -1,
     391,  1573,  1574,   392,    -1,    -1,  1574,  1507,    -1,    -1,
     395,  1576,  1577,   396,    -1,    -1,  1577,  1507,    -1,    -1,
     371,  1579,  1580,   372,    -1,    -1,  1580,  1507,    -1,  1582,
      -1,  1586,    -1,  1590,    -1,  1594,    -1,  1598,    -1,  1601,
      -1,  1607,    -1,  1610,    -1,  1614,    -1,  1619,    -1,  1622,
      -1,  1625,    -1,  1628,    -1,  1631,    -1,  1634,    -1,  1637,
      -1,  1640,    -1,  1643,    -1,  1604,    -1,  1583,  1585,  1584,
      -1,   437,    -1,    11,    -1,    10,   438,    -1,   233,     8,
       6,     8,    -1,  1587,  1589,  1588,    -1,   287,    -1,    11,
      -1,    10,   288,    -1,   233,     8,     6,     8,    -1,  1591,
    1593,  1592,    -1,   291,    -1,    11,    -1,    10,   292,    -1,
     233,     8,     6,     8,    -1,  1595,  1597,  1596,    -1,   295,
      -1,    11,    -1,    10,   296,    -1,   233,     8,     6,     8,
      -1,  1599,  1600,    -1,   411,    -1,  1581,   412,    -1,  1602,
    1603,    -1,   413,    -1,  1581,  1581,   414,    -1,  1605,  1606,
      -1,   439,    -1,  1507,   440,    -1,  1608,  1609,    -1,   441,
      -1,  1581,   442,    -1,  1611,  1612,    10,  1613,    -1,   415,
      -1,    -1,  1618,    -1,  1581,   416,    -1,  1615,  1616,    10,
    1617,    -1,   417,    -1,    -1,  1618,    -1,  1581,   418,    -1,
     462,     3,     8,    -1,  1620,  1621,    -1,   419,    -1,    11,
      -1,    10,   420,    -1,  1623,  1624,    -1,   421,    -1,  1581,
    1581,   422,    -1,  1626,  1627,    -1,   423,    -1,  1581,   424,
      -1,  1629,  1630,    -1,   425,    -1,  1581,  1581,   426,    -1,
    1632,  1633,    -1,   427,    -1,  1581,  1581,   428,    -1,    -1,
     429,  1635,  1636,   430,    -1,    -1,  1636,  1581,    -1,  1638,
    1639,    -1,   431,    -1,  1581,  1646,   432,    -1,  1641,  1642,
      -1,   433,    -1,  1507,  1507,  1507,  1507,  1581,   434,    -1,
    1644,  1645,    -1,   435,    -1,  1581,   436,    -1,  1507,    -1,
    1647,    -1,  1648,    -1,  1654,    -1,  1657,    -1,  1660,    -1,
    1663,    -1,  1666,    -1,  1669,    -1,  1672,    -1,  1675,    -1,
    1649,  1651,  1650,    -1,   449,    -1,    11,    -1,    10,   450,
      -1,  1652,    -1,    -1,  1652,  1653,    -1,  1454,    -1,  1453,
      -1,  1655,    10,  1656,    -1,   459,    -1,  1507,  1507,   460,
      -1,  1658,    10,  1659,    -1,   451,    -1,  1646,  1646,   452,
      -1,    -1,   455,    10,  1661,  1662,   456,    -1,    -1,  1662,
    1646,    -1,  1664,    10,  1665,    -1,   445,    -1,  1646,  1646,
     446,    -1,  1667,    10,  1668,    -1,   447,    -1,  1646,   448,
      -1,  1670,    10,  1671,    -1,   443,    -1,  1646,   444,    -1,
    1673,    10,  1674,    -1,   457,    -1,  1646,  1646,   458,    -1,
    1676,    10,  1677,    -1,   453,    -1,  1646,   454,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   354,   354,   355,   357,   364,   374,   374,   376,   376,
     378,   380,   382,   391,   392,   395,   404,   404,   417,   417,
     419,   433,   433,   435,   435,   437,   439,   441,   441,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   455,   457,
     472,   479,   479,   482,   487,   491,   500,   504,   509,   509,
     511,   513,   515,   515,   517,   522,   532,   538,   538,   541,
     546,   552,   552,   555,   557,   564,   564,   566,   566,   568,
     570,   573,   575,   582,   582,   584,   584,   586,   588,   593,
     595,   602,   602,   604,   604,   606,   608,   613,   615,   622,
     622,   624,   624,   626,   628,   633,   635,   642,   642,   644,
     644,   646,   648,   653,   655,   662,   662,   664,   664,   666,
     668,   673,   675,   682,   682,   684,   684,   686,   688,   693,
     695,   702,   712,   717,   723,   723,   725,   727,   729,   729,
     731,   736,   748,   754,   754,   757,   764,   769,   776,   776,
     780,   780,   782,   793,   793,   795,   795,   797,   799,   801,
     801,   804,   805,   806,   807,   808,   809,   812,   814,   821,
     821,   823,   823,   825,   827,   834,   836,   847,   849,   849,
     852,   858,   864,   866,   872,   874,   885,   887,   887,   890,
     896,   902,   904,   911,   913,   924,   926,   926,   929,   935,
     941,   943,   950,   952,   961,   962,   968,   970,   976,   978,
     985,   995,  1000,  1006,  1006,  1008,  1010,  1012,  1012,  1014,
    1019,  1031,  1037,  1037,  1040,  1047,  1052,  1058,  1058,  1062,
    1062,  1064,  1075,  1075,  1077,  1077,  1079,  1081,  1083,  1083,
    1086,  1087,  1088,  1089,  1090,  1091,  1094,  1096,  1103,  1103,
    1105,  1105,  1107,  1109,  1117,  1119,  1126,  1126,  1128,  1128,
    1130,  1132,  1137,  1139,  1146,  1146,  1148,  1148,  1150,  1152,
    1157,  1159,  1166,  1166,  1168,  1168,  1170,  1172,  1177,  1179,
    1186,  1186,  1188,  1188,  1190,  1192,  1199,  1201,  1208,  1218,
    1223,  1229,  1229,  1231,  1233,  1235,  1235,  1237,  1242,  1254,
    1260,  1260,  1263,  1270,  1275,  1282,  1282,  1285,  1285,  1287,
    1303,  1303,  1305,  1305,  1307,  1309,  1311,  1311,  1314,  1315,
    1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1327,
    1329,  1336,  1336,  1338,  1338,  1340,  1342,  1350,  1352,  1359,
    1359,  1361,  1361,  1363,  1365,  1370,  1372,  1379,  1379,  1381,
    1381,  1383,  1385,  1390,  1392,  1399,  1399,  1401,  1401,  1403,
    1405,  1410,  1412,  1419,  1419,  1421,  1421,  1423,  1425,  1430,
    1432,  1439,  1449,  1454,  1460,  1460,  1462,  1464,  1466,  1466,
    1468,  1470,  1484,  1484,  1487,  1487,  1487,  1487,  1490,  1490,
    1492,  1492,  1494,  1496,  1505,  1506,  1509,  1511,  1522,  1524,
    1524,  1527,  1533,  1539,  1541,  1548,  1550,  1561,  1563,  1563,
    1566,  1572,  1578,  1580,  1587,  1589,  1600,  1602,  1602,  1605,
    1611,  1617,  1619,  1626,  1628,  1638,  1639,  1645,  1647,  1654,
    1656,  1663,  1673,  1678,  1684,  1684,  1686,  1688,  1690,  1690,
    1692,  1697,  1709,  1715,  1715,  1718,  1725,  1730,  1737,  1737,
    1740,  1740,  1742,  1750,  1756,  1756,  1759,  1766,  1771,  1776,
    1783,  1788,  1794,  1794,  1796,  1798,  1800,  1800,  1802,  1804,
    1813,  1815,  1815,  1817,  1817,  1817,  1819,  1829,  1839,  1859,
    1865,  1867,  1877,  1883,  1883,  1886,  1891,  1896,  1906,  1911,
    1917,  1917,  1919,  1921,  1923,  1923,  1925,  1930,  1940,  1946,
    1946,  1949,  1955,  1962,  1962,  1965,  1965,  1967,  1969,  1969,
    1971,  1971,  1973,  1975,  1983,  1983,  1985,  1991,  1991,  1999,
    1999,  2001,  2003,  2005,  2007,  2007,  2009,  2014,  2022,  2027,
    2033,  2033,  2035,  2037,  2039,  2039,  2041,  2051,  2060,  2060,
    2063,  2064,  2067,  2070,  2070,  2072,  2077,  2085,  2090,  2096,
    2096,  2098,  2100,  2102,  2102,  2104,  2114,  2123,  2123,  2126,
    2127,  2131,  2132,  2134,  2134,  2136,  2138,  2143,  2143,  2145,
    2150,  2150,  2152,  2154,  2156,  2158,  2158,  2167,  2167,  2176,
    2176,  2185,  2185,  2194,  2194,  2203,  2203,  2212,  2212,  2222,
    2222,  2224,  2229,  2253,  2259,  2259,  2262,  2271,  2279,  2285,
    2291,  2297,  2303,  2309,  2315,  2322,  2322,  2324,  2324,  2326,
    2328,  2328,  2330,  2330,  2332,  2339,  2348,  2348,  2351,  2357,
    2364,  2364,  2366,  2366,  2368,  2370,  2379,  2379,  2381,  2392,
    2402,  2408,  2408,  2411,  2416,  2417,  2421,  2421,  2423,  2425,
    2428,  2432,  2432,  2434,  2442,  2442,  2450,  2450,  2452,  2454,
    2456,  2458,  2458,  2460,  2465,  2473,  2478,  2484,  2484,  2486,
    2488,  2491,  2491,  2493,  2501,  2511,  2511,  2514,  2515,  2518,
    2521,  2521,  2523,  2528,  2528,  2531,  2533,  2535,  2537,  2537,
    2546,  2546,  2555,  2555,  2564,  2564,  2573,  2573,  2582,  2582,
    2591,  2591,  2601,  2601,  2603,  2609,  2633,  2640,  2640,  2643,
    2651,  2659,  2665,  2671,  2677,  2683,  2689,  2695,  2703,  2703,
    2705,  2705,  2707,  2709,  2709,  2711,  2711,  2713,  2718,  2728,
    2728,  2731,  2737,  2744,  2744,  2746,  2746,  2748,  2750,  2757,
    2757,  2759,  2771,  2781,  2787,  2787,  2790,  2795,  2796,  2800,
    2800,  2802,  2804,  2807,  2810,  2810,  2812,  2819,  2819,  2827,
    2827,  2829,  2831,  2833,  2835,  2835,  2837,  2842,  2850,  2855,
    2861,  2861,  2863,  2865,  2867,  2867,  2869,  2877,  2886,  2886,
    2889,  2890,  2893,  2896,  2896,  2898,  2903,  2903,  2905,  2907,
    2909,  2911,  2911,  2920,  2920,  2929,  2929,  2938,  2938,  2947,
    2947,  2956,  2956,  2965,  2965,  2975,  2975,  2977,  2983,  3007,
    3013,  3013,  3016,  3024,  3032,  3038,  3044,  3050,  3056,  3062,
    3068,  3075,  3075,  3077,  3077,  3079,  3081,  3081,  3083,  3083,
    3085,  3092,  3101,  3101,  3105,  3110,  3118,  3118,  3120,  3120,
    3122,  3124,  3132,  3132,  3134,  3146,  3156,  3162,  3162,  3165,
    3170,  3171,  3175,  3175,  3177,  3179,  3181,  3184,  3184,  3186,
    3192,  3192,  3200,  3200,  3202,  3204,  3207,  3207,  3215,  3221,
    3234,  3234,  3236,  3238,  3240,  3242,  3242,  3245,  3252,  3264,
    3264,  3266,  3268,  3270,  3276,  3276,  3278,  3278,  3280,  3286,
    3315,  3322,  3322,  3325,  3335,  3341,  3346,  3351,  3356,  3361,
    3366,  3371,  3378,  3378,  3380,  3380,  3382,  3385,  3386,  3392,
    3392,  3395,  3396,  3398,  3411,  3421,  3427,  3427,  3430,  3435,
    3436,  3440,  3440,  3442,  3444,  3446,  3453,  3453,  3455,  3460,
    3460,  3462,  3467,  3476,  3481,  3487,  3487,  3489,  3491,  3493,
    3493,  3495,  3500,  3514,  3522,  3522,  3525,  3531,  3537,  3543,
    3549,  3559,  3564,  3570,  3570,  3572,  3574,  3576,  3576,  3578,
    3584,  3589,  3591,  3591,  3593,  3595,  3607,  3607,  3609,  3614,
    3623,  3628,  3634,  3634,  3636,  3638,  3640,  3640,  3642,  3647,
    3659,  3667,  3667,  3670,  3675,  3680,  3685,  3693,  3698,  3704,
    3704,  3706,  3708,  3710,  3710,  3712,  3718,  3723,  3725,  3725,
    3727,  3729,  4030,  4036,  4042,  4048,  4054,  4060,  4066,  4072,
    4081,  4087,  4096,  4124,  4125,  4129,  4130,  4131,  4133,  4135,
    4135,  4137,  4138,  4139,  4140,  4176,  4178,  4192,  4192,  4194,
    4196,  4198,  4200,  4200,  4203,  4204,  4205,  4206,  4207,  4209,
    4217,  4217,  4219,  4219,  4221,  4227,  4235,  4235,  4237,  4237,
    4239,  4245,  4253,  4253,  4255,  4255,  4257,  4263,  4271,  4271,
    4273,  4273,  4275,  4281,  4289,  4289,  4291,  4291,  4293,  4305,
    4313,  4315,  4315,  4317,  4319,  4328,  4330,  4330,  4332,  4332,
    4334,  4350,  4353,  4353,  4355,  4355,  4358,  4389,  4397,  4399,
    4399,  4401,  4403,  4411,  4411,  4413,  4429,  4431,  4431,  4433,
    4433,  4435,  4466,  4476,  4476,  4478,  4480,  4488,  4488,  4490,
    4633,  4635,  4640,  4640,  4642,  4644,  4646,  4649,  4651,  4656,
    4656,  4658,  4660,  4662,  4665,  4667,  4672,  4672,  4674,  4676,
    4678,  4681,  4683,  4688,  4688,  4690,  4692,  4694,  4697,  4699,
    4704,  4704,  4706,  4708,  4710,  4713,  4715,  4720,  4720,  4722,
    4724,  4726,  4729,  4731,  4736,  4736,  4738,  4740,  4742,  4745,
    4774,  4862,  4887,  4909,  4909,  4912,  4913,  4914,  4915,  4916,
    4917,  5048,  5048,  5050,  5052,  5081,  5083,  5083,  5088,  5106,
    5133,  5133,  5136,  5137,  5138,  5139,  5140,  5141,  5142,  5143,
    5144,  5147,  5147,  5149,  5149,  5154,  5154,  5154,  5154,  5155,
    5155,  5156,  5156,  5156,  5157,  5157,  5159,  5161,  5170,  5176,
    5176,  5179,  5185,  5191,  5193,  5193,  5199,  5209,  5219,  5219,
    5221,  5223,  5225,  5228,  5239,  5246,  5246,  5248,  5250,  5252,
    5258,  5268,  5275,  5275,  5277,  5279,  5281,  5284,  5286,  5295,
    5301,  5301,  5304,  5310,  5316,  5318,  5318,  5320,  5330,  5337,
    5337,  5339,  5341,  5343,  5345,  5347,  5356,  5362,  5362,  5365,
    5371,  5377,  5379,  5379,  5382,  5387,  5398,  5413,  5413,  5415,
    5417,  5419,  5421,  5421,  5423,  5430,  5437,  5450,  5450,  5453,
    5454,  5456,  5456,  5458,  5460,  5462,  5462,  5465,  5467,  5475,
    5475,  5480,  5488,  5490,  5499,  5505,  5505,  5508,  5514,  5521,
    5523,  5523,  5526,  5530,  5541,  5556,  5556,  5558,  5560,  5562,
    5562,  5564,  5566,  5581,  5581,  5583,  5585,  5594,  5596,  5605,
    5611,  5611,  5614,  5621,  5628,  5630,  5630,  5633,  5637,  5648,
    5664,  5664,  5666,  5668,  5670,  5670,  5672,  5674,  5689,  5689,
    5691,  5693,  5702,  5704,  5713,  5719,  5719,  5722,  5728,  5734,
    5736,  5736,  5738,  5748,  5755,  5755,  5757,  5759,  5761,  5764,
    5766,  5775,  5781,  5781,  5784,  5790,  5796,  5798,  5798,  5801,
    5805,  5816,  5831,  5831,  5833,  5835,  5837,  5837,  5839,  5842,
    5854,  5854,  5857,  5858,  5859,  5861,  5893,  5895,  5905,  5911,
    5911,  5914,  5920,  5926,  5928,  5928,  5931,  5935,  5946,  5958,
    5958,  5960,  5962,  5964,  5964,  5966,  5993,  6004,  6004,  6007,
    6008,  6009,  6011,  6011,  6014,  6016,  6025,  6031,  6031,  6034,
    6040,  6046,  6048,  6048,  6050,  6060,  6067,  6067,  6069,  6071,
    6073,  6076,  6079,  6097,  6097,  6108,  6115,  6125,  6133,  6139,
    6141,  6155,  6167,  6173,  6179,  6179,  6181,  6183,  6185,  6187,
    6197,  6203,  6209,  6209,  6211,  6213,  6215,  6217,  6217,  6222,
    6227,  6239,  6241,  6241,  6244,  6245,  6246,  6254,  6261,  6261,
    6263,  6265,  6283,  6294,  6305,  6327,  6338,  6349,  6360,  6404,
    6428,  6450,  6461,  6472,  6483,  6494,  6505,  6519,  6530,  6544,
    6559,  6574,  6586,  6598,  6618,  6638,  6648,  6676,  6685,  6696,
    6708,  6722,  6735,  6748,  6758,  6768,  6781,  6781,  6783,  6793,
    6809,  6809,  6811,  6818,  6827,  6827,  6829,  6836,  6845,  6845,
    6847,  6854,  6863,  6863,  6865,  6872,  6937,  6937,  6939,  6946,
    6955,  6955,  6957,  6964,  6973,  6973,  6975,  6982,  6991,  6991,
    6993,  7002,  7016,  7016,  7018,  7025,  7034,  7034,  7036,  7043,
    7052,  7052,  7054,  7061,  7070,  7070,  7072,  7079,  7088,  7088,
    7090,  7097,  7106,  7106,  7110,  7118,  7127,  7127,  7129,  7136,
    7145,  7145,  7147,  7154,  7283,  7284,  7285,  7286,  7287,  7288,
    7289,  7290,  7291,  7292,  7293,  7294,  7295,  7296,  7297,  7298,
    7299,  7300,  7301,  7302,  7303,  7304,  7305,  7306,  7308,  7309,
    7310,  7314,  7314,  7317,  7318,  7320,  7320,  7323,  7324,  7328,
    7328,  7333,  7333,  7338,  7338,  7343,  7343,  7348,  7348,  7353,
    7353,  7358,  7358,  7363,  7363,  7368,  7368,  7373,  7373,  7378,
    7378,  7383,  7383,  7388,  7390,  7396,  7403,  7403,  7409,  7409,
    7421,  7421,  7426,  7426,  7431,  7431,  7441,  7448,  7454,  7455,
    7457,  7458,  7461,  7465,  7469,  7473,  7472,  7493,  7492,  7499,
    7500,  7502,  7501,  7508,  7509,  7512,  7518,  7526,  7533,  7551,
    7551,  7562,  7562,  7565,  7565,  7579,  7580,  7583,  7583,  7596,
    7597,  7600,  7600,  7613,  7614,  7617,  7617,  7627,  7628,  7634,
    7635,  7636,  7637,  7638,  7639,  7640,  7641,  7642,  7643,  7644,
    7645,  7646,  7647,  7648,  7649,  7650,  7651,  7652,  7655,  7660,
    7667,  7668,  7670,  7678,  7683,  7690,  7691,  7693,  7700,  7705,
    7712,  7713,  7715,  7722,  7727,  7734,  7735,  7737,  7744,  7746,
    7752,  7754,  7756,  7762,  7764,  7766,  7772,  7774,  7776,  7782,
    7784,  7786,  7792,  7792,  7797,  7799,  7801,  7807,  7807,  7812,
    7814,  7823,  7825,  7830,  7830,  7832,  7834,  7840,  7843,  7845,
    7851,  7854,  7856,  7862,  7865,  7867,  7873,  7877,  7876,  7888,
    7888,  7895,  7897,  7903,  7905,  7907,  7913,  7916,  7918,  7924,
    8040,  8040,  8044,  8045,  8046,  8047,  8048,  8049,  8050,  8051,
    8052,  8056,  8060,  8069,  8070,  8072,  8077,  8077,  8082,  8083,
    8108,  8110,  8116,  8119,  8121,  8127,  8130,  8130,  8140,  8141,
    8147,  8149,  8155,  8158,  8160,  8166,  8169,  8171,  8177,  8180,
    8182,  8188,  8191,  8193,  8199
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
  "MATRIXINVERSEEND", "COMPLEXCONJUGATESTART", "COMPLEXCONJUGATEEND",
  "COMPLEXMINUSSTART", "COMPLEXMINUSEND", "COMPLEXNEGATESTART",
  "COMPLEXNEGATEEND", "COMPLEXNUMBERSTART", "COMPLEXNUMBEREND",
  "COMPLEXPLUSSTART", "COMPLEXPLUSEND", "COMPLEXSQUARESTART",
  "COMPLEXSQUAREEND", "COMPLEXSUMSTART", "COMPLEXSUMEND",
  "COMPLEXTIMESSTART", "COMPLEXTIMESEND", "CREATECOMPLEXSTART",
  "CREATECOMPLEXEND", "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT",
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
     715,   716,   717,   718,   719,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   469,   470,   470,   471,   472,   473,   473,   474,   474,
     475,   476,   477,   478,   478,   479,   480,   480,   481,   481,
     482,   483,   483,   484,   484,   485,   486,   487,   487,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   489,   490,
     491,   492,   492,   493,   493,   493,   494,   494,   495,   495,
     496,   497,   498,   498,   499,   500,   501,   502,   502,   503,
     503,   504,   504,   505,   506,   507,   507,   508,   508,   509,
     510,   511,   512,   513,   513,   514,   514,   515,   516,   517,
     518,   519,   519,   520,   520,   521,   522,   523,   524,   525,
     525,   526,   526,   527,   528,   529,   530,   531,   531,   532,
     532,   533,   534,   535,   536,   537,   537,   538,   538,   539,
     540,   541,   542,   543,   543,   544,   544,   545,   546,   547,
     548,   549,   550,   550,   551,   551,   552,   553,   554,   554,
     555,   556,   557,   558,   558,   559,   559,   559,   560,   560,
     561,   561,   562,   563,   563,   564,   564,   565,   566,   567,
     567,   568,   568,   568,   568,   568,   568,   569,   570,   571,
     571,   572,   572,   573,   574,   575,   576,   577,   578,   578,
     579,   579,   580,   581,   582,   583,   584,   585,   585,   586,
     586,   587,   588,   589,   590,   591,   592,   592,   593,   593,
     594,   595,   596,   597,   598,   598,   599,   600,   601,   602,
     603,   604,   604,   605,   605,   606,   607,   608,   608,   609,
     610,   611,   612,   612,   613,   613,   613,   614,   614,   615,
     615,   616,   617,   617,   618,   618,   619,   620,   621,   621,
     622,   622,   622,   622,   622,   622,   623,   624,   625,   625,
     626,   626,   627,   628,   629,   630,   631,   631,   632,   632,
     633,   634,   635,   636,   637,   637,   638,   638,   639,   640,
     641,   642,   643,   643,   644,   644,   645,   646,   647,   648,
     649,   649,   650,   650,   651,   652,   653,   654,   655,   656,
     656,   657,   657,   658,   659,   660,   660,   661,   662,   663,
     664,   664,   665,   665,   665,   666,   666,   667,   667,   668,
     669,   669,   670,   670,   671,   672,   673,   673,   674,   674,
     674,   674,   674,   674,   674,   674,   674,   674,   674,   675,
     676,   677,   677,   678,   678,   679,   680,   681,   682,   683,
     683,   684,   684,   685,   686,   687,   688,   689,   689,   690,
     690,   691,   692,   693,   694,   695,   695,   696,   696,   697,
     698,   699,   700,   701,   701,   702,   702,   703,   704,   705,
     706,   707,   708,   708,   709,   709,   710,   711,   712,   712,
     713,   714,   715,   715,   716,   716,   716,   716,   717,   717,
     718,   718,   719,   720,   721,   721,   722,   723,   724,   725,
     725,   726,   726,   727,   728,   729,   730,   731,   732,   732,
     733,   733,   734,   735,   736,   737,   738,   739,   739,   740,
     740,   741,   742,   743,   744,   745,   745,   746,   747,   748,
     749,   750,   751,   751,   752,   752,   753,   754,   755,   755,
     756,   757,   758,   759,   759,   760,   760,   760,   761,   761,
     762,   762,   763,   764,   765,   765,   766,   766,   766,   766,
     767,   767,   768,   768,   769,   770,   771,   771,   772,   773,
     774,   775,   775,   776,   776,   776,   777,   778,   779,   780,
     781,   782,   783,   784,   784,   785,   785,   785,   786,   786,
     787,   787,   788,   789,   790,   790,   791,   792,   793,   794,
     794,   795,   795,   796,   796,   797,   797,   798,   799,   799,
     800,   800,   801,   802,   803,   803,   804,   805,   805,   806,
     806,   807,   808,   809,   810,   810,   811,   812,   813,   813,
     814,   814,   815,   816,   817,   817,   818,   819,   820,   820,
     821,   821,   822,   823,   823,   824,   825,   826,   826,   827,
     827,   828,   829,   830,   830,   831,   832,   833,   833,   834,
     834,   835,   835,   836,   836,   837,   838,   839,   839,   840,
     841,   841,   842,   843,   844,   845,   845,   846,   846,   847,
     847,   848,   848,   849,   849,   850,   850,   851,   851,   852,
     852,   853,   854,   855,   856,   856,   857,   857,   857,   857,
     857,   857,   857,   857,   857,   858,   858,   859,   859,   860,
     861,   861,   862,   862,   863,   864,   865,   865,   866,   866,
     867,   867,   868,   868,   869,   870,   871,   871,   872,   873,
     874,   875,   875,   876,   876,   876,   877,   877,   878,   879,
     880,   881,   881,   882,   883,   883,   884,   884,   885,   886,
     887,   888,   888,   889,   890,   891,   891,   892,   892,   893,
     894,   895,   895,   896,   897,   898,   898,   899,   899,   900,
     901,   901,   902,   903,   903,   904,   905,   906,   907,   907,
     908,   908,   909,   909,   910,   910,   911,   911,   912,   912,
     913,   913,   914,   914,   915,   916,   917,   918,   918,   919,
     919,   919,   919,   919,   919,   919,   919,   919,   920,   920,
     921,   921,   922,   923,   923,   924,   924,   925,   926,   927,
     927,   928,   928,   929,   929,   930,   930,   931,   932,   933,
     933,   934,   935,   936,   937,   937,   938,   938,   938,   939,
     939,   940,   941,   942,   943,   943,   944,   945,   945,   946,
     946,   947,   948,   949,   950,   950,   951,   952,   953,   953,
     954,   954,   955,   956,   957,   957,   958,   959,   960,   960,
     961,   961,   962,   963,   963,   964,   965,   965,   966,   967,
     968,   969,   969,   970,   970,   971,   971,   972,   972,   973,
     973,   974,   974,   975,   975,   976,   976,   977,   978,   979,
     980,   980,   981,   981,   981,   981,   981,   981,   981,   981,
     981,   982,   982,   983,   983,   984,   985,   985,   986,   986,
     987,   988,   989,   989,   990,   990,   991,   991,   992,   992,
     993,   994,   995,   995,   996,   997,   998,   999,   999,  1000,
    1000,  1000,  1001,  1001,  1002,  1003,  1004,  1005,  1005,  1006,
    1007,  1007,  1008,  1008,  1009,  1010,  1011,  1011,  1012,  1013,
    1014,  1014,  1015,  1016,  1017,  1018,  1018,  1019,  1020,  1021,
    1021,  1022,  1023,  1024,  1025,  1025,  1026,  1026,  1027,  1028,
    1029,  1030,  1030,  1031,  1031,  1031,  1031,  1031,  1031,  1031,
    1031,  1031,  1032,  1032,  1033,  1033,  1034,  1035,  1035,  1036,
    1036,  1037,  1037,  1038,  1039,  1040,  1041,  1041,  1042,  1042,
    1042,  1043,  1043,  1044,  1045,  1046,  1047,  1047,  1048,  1049,
    1049,  1050,  1051,  1052,  1052,  1053,  1053,  1054,  1055,  1056,
    1056,  1057,  1058,  1059,  1060,  1060,  1061,  1061,  1061,  1061,
    1061,  1062,  1062,  1063,  1063,  1064,  1065,  1066,  1066,  1067,
    1068,  1068,  1069,  1069,  1070,  1071,  1072,  1072,  1073,  1074,
    1075,  1075,  1076,  1076,  1077,  1078,  1079,  1079,  1080,  1081,
    1082,  1083,  1083,  1084,  1084,  1084,  1084,  1085,  1085,  1086,
    1086,  1087,  1088,  1089,  1089,  1090,  1091,  1091,  1092,  1092,
    1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1106,  1107,  1107,  1107,  1108,  1109,
    1109,  1110,  1110,  1110,  1110,  1111,  1112,  1113,  1113,  1114,
    1115,  1116,  1117,  1117,  1118,  1118,  1118,  1118,  1118,  1119,
    1120,  1120,  1121,  1121,  1122,  1123,  1124,  1124,  1125,  1125,
    1126,  1127,  1128,  1128,  1129,  1129,  1130,  1131,  1132,  1132,
    1133,  1133,  1134,  1135,  1136,  1136,  1137,  1137,  1138,  1139,
    1139,  1140,  1140,  1141,  1142,  1143,  1144,  1144,  1145,  1145,
    1146,  1147,  1148,  1148,  1149,  1149,  1150,  1151,  1151,  1152,
    1152,  1153,  1154,  1155,  1155,  1156,  1157,  1158,  1158,  1159,
    1159,  1160,  1161,  1162,  1162,  1163,  1164,  1165,  1165,  1166,
    1167,  1168,  1169,  1169,  1170,  1171,  1172,  1173,  1174,  1175,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1187,  1188,  1189,  1190,  1191,  1192,
    1193,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1199,  1200,
    1201,  1202,  1203,  1204,  1205,  1205,  1206,  1207,  1208,  1209,
    1210,  1211,  1212,  1213,  1213,  1214,  1214,  1214,  1214,  1214,
    1214,  1215,  1215,  1216,  1217,  1218,  1219,  1219,  1220,  1221,
    1222,  1222,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
    1223,  1224,  1224,  1225,  1225,  1226,  1226,  1226,  1226,  1226,
    1226,  1226,  1226,  1226,  1226,  1226,  1227,  1228,  1229,  1230,
    1230,  1231,  1231,  1232,  1233,  1233,  1234,  1235,  1236,  1236,
    1237,  1238,  1239,  1240,  1241,  1242,  1242,  1243,  1244,  1245,
    1246,  1247,  1248,  1248,  1249,  1250,  1251,  1252,  1253,  1254,
    1255,  1255,  1256,  1256,  1257,  1258,  1258,  1259,  1260,  1261,
    1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1268,  1269,
    1269,  1270,  1271,  1271,  1272,  1272,  1273,  1274,  1274,  1275,
    1276,  1277,  1278,  1278,  1279,  1280,  1281,  1282,  1282,  1283,
    1283,  1284,  1284,  1285,  1286,  1287,  1287,  1288,  1289,  1290,
    1290,  1291,  1292,  1293,  1294,  1295,  1295,  1296,  1296,  1297,
    1298,  1298,  1299,  1299,  1300,  1301,  1301,  1302,  1303,  1304,
    1304,  1305,  1306,  1307,  1307,  1308,  1309,  1310,  1311,  1312,
    1313,  1313,  1314,  1314,  1315,  1316,  1316,  1317,  1317,  1318,
    1319,  1319,  1320,  1321,  1322,  1322,  1323,  1324,  1325,  1325,
    1326,  1327,  1328,  1329,  1330,  1331,  1331,  1332,  1332,  1333,
    1334,  1334,  1335,  1336,  1337,  1337,  1338,  1339,  1340,  1341,
    1342,  1343,  1344,  1344,  1345,  1345,  1346,  1347,  1347,  1348,
    1348,  1349,  1350,  1350,  1351,  1352,  1353,  1353,  1354,  1355,
    1356,  1356,  1357,  1357,  1357,  1358,  1359,  1360,  1361,  1362,
    1362,  1363,  1363,  1364,  1365,  1365,  1366,  1366,  1367,  1368,
    1368,  1369,  1370,  1371,  1371,  1372,  1373,  1374,  1374,  1375,
    1375,  1375,  1376,  1376,  1377,  1378,  1379,  1380,  1380,  1381,
    1381,  1382,  1383,  1383,  1384,  1385,  1386,  1386,  1387,  1388,
    1389,  1390,  1391,  1392,  1392,  1393,  1394,  1395,  1396,  1397,
    1398,  1399,  1400,  1401,  1402,  1402,  1403,  1404,  1405,  1406,
    1407,  1408,  1409,  1409,  1410,  1411,  1412,  1413,  1413,  1414,
    1415,  1416,  1417,  1417,  1418,  1418,  1418,  1418,  1419,  1419,
    1420,  1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,
    1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,
    1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,
    1450,  1451,  1452,  1453,  1454,  1455,  1456,  1456,  1457,  1458,
    1459,  1459,  1460,  1461,  1462,  1462,  1463,  1464,  1465,  1465,
    1466,  1467,  1468,  1468,  1469,  1470,  1471,  1471,  1472,  1473,
    1474,  1474,  1475,  1476,  1477,  1477,  1478,  1479,  1480,  1480,
    1481,  1482,  1483,  1483,  1484,  1485,  1486,  1486,  1487,  1488,
    1489,  1489,  1490,  1491,  1492,  1492,  1493,  1494,  1495,  1495,
    1496,  1497,  1498,  1498,  1499,  1500,  1501,  1501,  1502,  1503,
    1504,  1504,  1505,  1506,  1507,  1507,  1507,  1507,  1507,  1507,
    1507,  1507,  1507,  1507,  1507,  1507,  1507,  1507,  1507,  1507,
    1507,  1507,  1507,  1507,  1507,  1507,  1507,  1507,  1507,  1507,
    1507,  1509,  1508,  1510,  1510,  1512,  1511,  1513,  1513,  1515,
    1514,  1517,  1516,  1519,  1518,  1521,  1520,  1523,  1522,  1525,
    1524,  1527,  1526,  1529,  1528,  1531,  1530,  1533,  1532,  1535,
    1534,  1537,  1536,  1538,  1539,  1540,  1542,  1541,  1544,  1543,
    1546,  1545,  1548,  1547,  1550,  1549,  1551,  1552,  1553,  1553,
    1554,  1554,  1555,  1555,  1555,  1557,  1556,  1559,  1558,  1560,
    1560,  1561,  1560,  1562,  1562,  1563,  1563,  1564,  1565,  1567,
    1566,  1568,  1568,  1570,  1569,  1571,  1571,  1573,  1572,  1574,
    1574,  1576,  1575,  1577,  1577,  1579,  1578,  1580,  1580,  1581,
    1581,  1581,  1581,  1581,  1581,  1581,  1581,  1581,  1581,  1581,
    1581,  1581,  1581,  1581,  1581,  1581,  1581,  1581,  1582,  1583,
    1584,  1584,  1585,  1586,  1587,  1588,  1588,  1589,  1590,  1591,
    1592,  1592,  1593,  1594,  1595,  1596,  1596,  1597,  1598,  1599,
    1600,  1601,  1602,  1603,  1604,  1605,  1606,  1607,  1608,  1609,
    1610,  1611,  1612,  1612,  1613,  1614,  1615,  1616,  1616,  1617,
    1618,  1619,  1620,  1621,  1621,  1622,  1623,  1624,  1625,  1626,
    1627,  1628,  1629,  1630,  1631,  1632,  1633,  1635,  1634,  1636,
    1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,  1645,
    1646,  1646,  1647,  1647,  1647,  1647,  1647,  1647,  1647,  1647,
    1647,  1648,  1649,  1650,  1650,  1651,  1652,  1652,  1653,  1653,
    1654,  1655,  1656,  1657,  1658,  1659,  1661,  1660,  1662,  1662,
    1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677
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
       2,     2,     1,     3,     2,     1,     6,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     2,     1,     0,     2,     1,     1,
       3,     1,     3,     3,     1,     3,     0,     5,     0,     2,
       3,     1,     3,     3,     1,     2,     3,     1,     2,     3,
       1,     3,     3,     1,     2
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
       0,  1797,  1791,  1794,  1772,  1784,  1803,     0,  1800,  1781,
    1760,     0,  1761,  1762,  1776,  1763,     0,  1764,     0,  1765,
    1766,     0,  1767,     0,  1768,     0,  1769,     0,  1770,     0,
       0,  1759,     0,     0,  1431,  1051,  1426,  1421,  1424,  1425,
    1069,  1214,  1210,  1212,  1213,  1209,     0,  1201,  1051,  1231,
    1227,  1229,  1230,  1252,  1249,  1245,  1247,  1248,  1289,  1287,
    1283,  1285,  1286,  1314,  1312,  1308,  1310,  1311,  1051,  1336,
    1332,  1334,  1335,  1356,  1354,  1350,  1352,  1353,  1383,  1381,
    1377,  1379,  1380,  1083,  1408,  1404,  1406,  1407,  1748,  1750,
       0,  1691,     0,  1696,     0,  1701,     0,  1706,  1713,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1583,
    1582,     0,  1587,  1586,     0,     0,     0,     0,  1615,  1613,
       0,  1628,     0,  1632,  1633,  1626,  1631,  1634,  1730,     0,
    1720,     0,  1725,  1737,  1743,  1746,  1786,  1753,     0,  1775,
       0,     0,     0,     0,     0,     0,     0,     0,  1420,  1440,
    1419,  1438,  1442,  1051,  1434,  1429,  1432,  1433,  1428,     0,
       0,  1216,  1067,  1068,     0,  1208,  1233,     0,     0,  1251,
       0,     0,  1338,     0,     0,     0,  1410,  1082,     0,  1692,
    1697,  1702,  1707,     0,     0,     0,     0,  1602,  1604,  1650,
    1652,  1666,  1668,  1612,  1596,     0,  1606,  1608,  1610,     0,
    1639,     0,     0,  1638,  1644,  1645,  1646,  1617,  1658,  1660,
    1654,  1656,  1662,  1664,  1584,  1588,     0,  1621,  1623,  1625,
    1629,  1635,  1724,  1729,  1788,     0,  1773,  1771,     0,     0,
    1779,  1778,  1777,     0,  1780,     0,  1783,     0,  1790,     0,
    1793,     0,  1796,     0,  1799,     0,  1802,     0,     0,  1441,
    1436,     0,  1427,     0,  1072,  1070,  1073,  1215,  1232,  1250,
    1255,  1253,  1257,  1292,  1288,  1290,     0,  1317,  1313,  1315,
       0,  1337,  1359,  1355,  1357,  1360,  1386,  1382,  1384,  1387,
    1086,  1084,  1087,  1409,  1600,  1592,  1594,  1598,     0,  1640,
    1641,     0,     0,  1590,     0,     0,  1774,     0,     0,     0,
       0,     0,  1795,  1798,     0,  1804,     0,  1156,  1450,  1439,
    1448,  1449,     0,     0,  1443,  1444,  1445,  1446,  1447,  1435,
       0,  1080,  1076,  1077,  1078,     0,  1074,     0,  1256,     0,
    1295,  1291,  1293,  1294,     0,  1320,  1316,  1318,  1319,     0,
       0,     0,  1088,  1619,     0,     0,     0,  1636,  1787,  1789,
       0,     0,  1782,  1785,  1792,  1801,  1756,     0,     0,     0,
       0,  1079,     0,  1071,  1265,  1263,  1254,  1261,  1262,     0,
       0,  1258,  1259,  1260,     0,     0,     0,  1548,     0,  1361,
    1358,  1364,  1363,  1362,  1546,  1547,     0,  1393,  1388,  1385,
    1391,  1390,  1389,     0,  1085,  1642,  1648,  1647,  1484,  1483,
    1451,     0,     0,  1081,     0,     0,     0,     0,  1296,  1321,
       0,     0,  1392,     0,  1473,  1474,  1075,  1264,  1268,  1266,
    1269,     0,     0,  1365,  1549,  1089,     0,     0,  1270,  1465,
    1482,     0,     0,  1267,     0,     0,  1481,  1271
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
    1402,  1403,  2261,  2262,  2355,  2356,  2425,  2463,  2263,  2422,
    2423,  2424,  2276,  2277,  2381,  2382,  2441,  2494,  1013,  1014,
    1153,  1154,  1155,  1262,  1070,  1071,  1254,  1255,  1256,  1332,
    1147,  1148,  1328,  1329,  1330,  1396,  1249,  1250,  1392,  1393,
    1394,  1488,  1323,  1324,  1484,  1485,  1486,  1534,  1387,  1388,
    1530,  1531,  1532,  1576,  1479,  1480,  1572,  1573,  1574,  1599,
    1073,  1448,  1449,  1516,  1517,  1559,  1551,  1552,  1553,  1591,
    1592,  1593,  1607,  1608,  1662,  1651,  1606,  1626,  1627,  1628,
    1677,  1678,  1718,  1770,  1862,  1771,  1772,  1867,  1868,  1869,
    2001,  1863,  1864,  1997,  1998,  1999,  2136,  1993,  1994,  2132,
    2133,  2134,  2264,  1629,  1630,  1679,  1680,  1724,  1776,  1873,
    2004,  2005,  2140,  2141,  2142,  2267,  1631,  1632,  1681,  1682,
    1728,  1778,  1875,  2008,  2009,  2145,  2146,  2147,  2268,  2269,
    2361,  2362,  2427,  2428,  2471,  2466,  2467,  2468,  2505,  2519,
    2520,  2527,  2533,  1633,  1634,  1683,  1684,  1732,  1780,  1877,
    2012,  2013,  2150,  2151,  2152,  2270,  2365,  2366,  2431,  2432,
    2433,  1635,  1636,  1685,  1686,  1736,  1782,  1879,  2016,  2017,
    2155,  2156,  2157,  2271,  2369,  2370,  2436,  2437,  2438,  1637,
    1638,  1687,  1688,  1740,  1784,  1881,  2020,  2021,  2160,  2161,
    2162,  2273,  1639,  1640,  1689,  1690,  1744,  1786,  1883,  2024,
    2025,  2165,  2166,  2167,  2274,  2374,  2375,  2439,  2479,  2480,
    1641,  1642,  1691,  1692,  1748,  1788,  1885,  2028,  2029,  2170,
    2171,  2172,  2275,  2378,  2379,  2440,  2488,  2489,  1643,  1644,
    1693,  1694,  1752,  1790,  1887,  2032,  2033,  2175,  2176,  2177,
    2278,  1645,  1646,  1697,  1890,  1647,  1648,  1702,  1759,  2250,
    1851,  1852,  1989,  2127,  2128,  2129,  2259,  1987,  1988,  2123,
    2255,  2256,  2257,  2351,  2122,  2251,  2252,  2348,  2349,  2414,
    2409,  2410,  2411,  1703,  1560,   952,   434,  1074,  1130,   798,
    1206,   923,   435,  1561,  1719,   899,  2472,   436,  1335,  1663,
    1664,  1665,  1666,  1667,  2415,  2416,  1091,  1498,  1562,  1499,
    1668,  1669,  2528,  2473,  2330,  2331,  1670,  1671,  1672,  1673,
     729,   730,   731,  1217,  1218,  1219,   159,   160,   161,  1133,
    1134,  1135,  1437,  1438,  1439,   605,   606,   607,  1137,  1138,
    1139,  1720,  1721,  1722,  1698,  1699,  1700,  1140,  1141,  1142,
    1564,  1565,  1566,   162,   163,   164,   374,   375,   376,   616,
     617,   618,  2483,  2484,  2485,  1177,  1178,  1179,  2100,  1931,
    2073,  2210,  1932,  2074,  2213,  1933,  2075,  1934,  2055,  1935,
    2056,  1936,  2063,  1937,  2057,  1938,  2054,  1939,  2058,  1940,
    2059,  1941,  2065,  1942,  2066,  1943,  2067,  1944,  2062,  1945,
    1946,  2219,  1947,  2069,  1948,  2064,  1949,  2076,  1950,  2077,
    1951,  2078,  1952,  1953,  2225,  2081,  2226,  2227,  2394,  1954,
    2068,  2303,  2444,  2203,  2304,  2305,  2306,  1955,  2060,  2195,
    1956,  2071,  2206,  1957,  2070,  2205,  1958,  2072,  2207,  1959,
    2061,  2196,  1811,  1812,  1813,  2039,  1892,  1814,  1815,  2043,
    1894,  1816,  1817,  2047,  1896,  1818,  1819,  2051,  1898,  1820,
    1821,  1900,  1822,  1823,  1902,  1824,  1825,  1960,  1826,  1827,
    1962,  1828,  1829,  1964,  2230,  1830,  1831,  1966,  2232,  1965,
    1832,  1833,  1970,  1834,  1835,  1972,  1836,  1837,  1974,  1838,
    1839,  1976,  1840,  1841,  1978,  1842,  1888,  2035,  1843,  1844,
    1980,  1845,  1846,  1982,  1847,  1848,  1984,  2101,  2102,  2103,
    2104,  2327,  2238,  2239,  2332,  2105,  2106,  2334,  2107,  2108,
    2336,  2109,  2324,  2395,  2110,  2111,  2338,  2112,  2113,  2340,
    2114,  2115,  2342,  2116,  2117,  2344,  2118,  2119,  2346
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1987
static const yytype_int16 yypact[] =
{
     469, -1987, -1987,   140,    29,   144, -1987, -1987,   204,   -11,
   -1987,   374, -1987,   476, -1987, -1987, -1987, -1987,    -4,   488,
   -1987, -1987, -1987, -1987, -1987,    29, -1987, -1987, -1987, -1987,
   -1987,    38,   505,     2, -1987, -1987, -1987, -1987,   188,   837,
     204, -1987,    84,   519,    49, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,    12,
      15, -1987, -1987,   203, -1987,   524, -1987,   526, -1987,   533,
   -1987,   544, -1987,   557, -1987,   569, -1987,   582, -1987,   295,
   -1987,   323, -1987, -1987,   348, -1987, -1987,   410, -1987, -1987,
     425, -1987, -1987,   427, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   107,
     588,   105, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987,   122,   404, -1987, -1987,   590, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,   398, -1987,   295, -1987, -1987,
   -1987, -1987,   438, -1987,   440,   593,   203, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,   164, -1987, -1987, -1987, -1987,
       9, -1987, -1987, -1987, -1987,    11, -1987, -1987, -1987, -1987,
       7, -1987, -1987, -1987, -1987,     4, -1987, -1987, -1987, -1987,
     158, -1987, -1987, -1987, -1987,    93, -1987, -1987, -1987, -1987,
   -1987,   595, -1987,   332,   312,   376,   387,   324, -1987, -1987,
   -1987,    44, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987,   212,   385, -1987, -1987,   598, -1987,   604,
   -1987,   607, -1987,   609, -1987,   612, -1987,   295, -1987, -1987,
     100, -1987, -1987, -1987, -1987,   522,   284,   538,   284,   540,
     284,   546, -1987,   620, -1987,   532,    -1,   550,   562,   246,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987,   516, -1987, -1987,
     247, -1987, -1987,   276, -1987, -1987,   256, -1987, -1987,   286,
   -1987, -1987,   543, -1987, -1987,   531,   629,   -55, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987,   640,   186, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987,   321,   467, -1987, -1987,   646, -1987,   652, -1987,   665,
   -1987,   671, -1987,   673, -1987,   622, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987,   398, -1987,   295, -1987, -1987,   118, -1987,
   -1987, -1987, -1987,   129, -1987, -1987, -1987, -1987,    96, -1987,
   -1987, -1987, -1987,    99, -1987, -1987, -1987, -1987,   294, -1987,
   -1987, -1987, -1987,   675, -1987, -1987, -1987,   575,   695, -1987,
   -1987,   674, -1987, -1987, -1987, -1987, -1987,   695, -1987, -1987,
   -1987, -1987,   695, -1987, -1987, -1987, -1987,   684, -1987,   -42,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,   678,   591, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   653,
     396, -1987, -1987,   -35, -1987, -1987, -1987, -1987, -1987,   742,
     750,   758, -1987, -1987, -1987, -1987, -1987, -1987, -1987,    97,
   -1987, -1987, -1987, -1987,   121, -1987, -1987, -1987, -1987,   128,
   -1987, -1987, -1987, -1987,   239, -1987, -1987, -1987, -1987,   108,
   -1987, -1987, -1987, -1987, -1987,   697, -1987,   729,   284,   767,
     284,   769,   284,   773, -1987,   699, -1987, -1987, -1987,   711,
   -1987, -1987,   721, -1987, -1987,   680, -1987, -1987,   692, -1987,
   -1987, -1987,   716, -1987,   -30, -1987, -1987, -1987, -1987, -1987,
     754, -1987,   835,   803, -1987,   809, -1987, -1987,   813, -1987,
   -1987,   785,   513, -1987, -1987, -1987, -1987, -1987,   715,   250,
   -1987, -1987, -1987,   719,   328, -1987, -1987,   548,    88, -1987,
   -1987,   850,   852,   856,   858, -1987, -1987,   789, -1987, -1987,
     783, -1987, -1987,   797, -1987, -1987,   844, -1987, -1987,   830,
     875,   221, -1987, -1987, -1987, -1987,   695, -1987, -1987, -1987,
   -1987,   695, -1987, -1987, -1987, -1987,   695, -1987, -1987, -1987,
   -1987,   879, -1987,   -25, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,   838,   552, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,   723,   328,   798, -1987,
   -1987, -1987,   888, -1987, -1987, -1987, -1987, -1987,   565, -1987,
   -1987, -1987,   908, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987,   883,   905,   322, -1987,   909,   911,   915,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   832,   841,
   -1987, -1987,   834, -1987,   818, -1987,   840, -1987, -1987,   846,
   -1987, -1987,   862,   594, -1987, -1987, -1987, -1987,   731,   328,
     601, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   929, -1987,
     939, -1987,   779, -1987,   867, -1987,   950,   954, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
     314, -1987, -1987, -1987, -1987, -1987, -1987,   781,   328,   630,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   958,
      65, -1987, -1987, -1987, -1987, -1987,   916,   203, -1987, -1987,
     994,   117, -1987, -1987,  1003, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,   666, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,   937,   930, -1987, -1987,
   -1987,   707,   787,   800,   203, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,   923, -1987,  1010, -1987, -1987,
   -1987, -1987,   802,   554, -1987,   774,  1055,   224, -1987, -1987,
   -1987, -1987,   277, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987,   227, -1987, -1987, -1987, -1987,  1073, -1987, -1987, -1987,
   -1987, -1987, -1987,   784,  1064, -1987,   806, -1987, -1987, -1987,
    1026, -1987, -1987,  1007,  1006, -1987, -1987, -1987, -1987,  1091,
   -1987,  1015,   316, -1987, -1987, -1987, -1987,  1094, -1987,   843,
    1082, -1987,   810, -1987,  1159,  1023, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987,   812,   340, -1987,  1017, -1987, -1987,  1161,
   -1987,  1103,  1165, -1987,   814, -1987,  1189,  1053, -1987, -1987,
   -1987, -1987, -1987, -1987,   891,  1093,   996,  1112, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,  1128,  1188, -1987,   816,
   -1987,  1209,  1167, -1987, -1987, -1987, -1987, -1987, -1987,   932,
    1194,  1030, -1987, -1987, -1987,  1198,   996,  1236,   820, -1987,
   -1987, -1987, -1987,   822, -1987,  1240,   963, -1987, -1987, -1987,
   -1987, -1987, -1987,   952,  1206,  1047, -1987, -1987, -1987, -1987,
     824,  1248,   826, -1987, -1987, -1987,   828,   831, -1987,  1252,
     -76, -1987, -1987, -1987, -1987,  1254,   381, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987,  1250, -1987, -1987, -1987, -1987,   885,
    1269,   887, -1987,   940,   960, -1987, -1987, -1987, -1987,  1277,
     -31, -1987, -1987, -1987, -1987,   946,   960, -1987, -1987, -1987,
   -1987,   -57, -1987, -1987, -1987, -1987,  1281, -1987, -1987,  1146,
     992, -1987, -1987, -1987, -1987, -1987,  1224,  1231, -1987, -1987,
   -1987,   -46, -1987,   889, -1987,   962,   960, -1987, -1987, -1987,
   -1987,  1295,    -5, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987,  1260,   986, -1987,  1151,  1303, -1987, -1987,  1168,  1014,
   -1987, -1987, -1987, -1987, -1987,  1301,   986, -1987, -1987, -1987,
    1237,  1045, -1987, -1987, -1987, -1987, -1987,    45, -1987, -1987,
   -1987,   892,   819, -1987, -1987, -1987,  1346,  1210, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,  1329,   986, -1987,  1348, -1987,
   -1987,  1335,  1061, -1987, -1987,   974,   528, -1987, -1987,  1039,
   -1987,  1151,  1356,   978, -1987, -1987, -1987, -1987,    54,   980,
     475, -1987,  1039, -1987, -1987, -1987,   109,   695,  1358, -1987,
   -1987, -1987, -1987,    17, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987,  1153,   982,   637,
   -1987,  1039, -1987, -1987, -1987, -1987,    82,   -84, -1987, -1987,
   -1987, -1987,  1360, -1987,  1369, -1987,  1373, -1987,  1375, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,  1063, -1987,  1151,   984,
    1374,  1228, -1987, -1987, -1987, -1987,   695, -1987, -1987, -1987,
   -1987,   -74, -1987, -1987, -1987, -1987, -1987,  1385, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
    1063, -1987,    13, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
    1084,  1388, -1987, -1987,  1391, -1987,  1344,   372, -1987, -1987,
   -1987, -1987, -1987,  -178,  1447,   988, -1987,   -62, -1987, -1987,
   -1987, -1987, -1987,  1395, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,  1063, -1987,   695, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,  1114,  1156, -1987, -1987,
    1308, -1987, -1987,  1453,  1452,  1454,  1455, -1987,  1134, -1987,
    1151,   991,  1228, -1987, -1987, -1987, -1987,  1456,  1229, -1987,
    1318, -1987,  1141,  1169, -1987, -1987, -1987,  1126,  1164, -1987,
   -1987,  1320, -1987, -1987,  1464,  1134, -1987, -1987, -1987,  1170,
   -1987,  1465, -1987,  1324, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987,  1468, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
    1133,  1180, -1987, -1987,  1330, -1987, -1987,  1471,  1134, -1987,
    1183, -1987, -1987,   126, -1987,  1079,   258,  1474, -1987, -1987,
   -1987, -1987,  1154, -1987,  1151,  1307,  1228, -1987, -1987, -1987,
   -1987, -1987,  1162, -1987,  1477,  1309, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987,   190, -1987,  1311,   258, -1987,  1154, -1987,
   -1987, -1987, -1987,  1313,   419,  1478,   -72, -1987, -1987,   196,
   -1987,  1315,   258, -1987,  1154, -1987, -1987,    34, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,  1228, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,  1157, -1987,  1151,  1317,
    1228, -1987, -1987, -1987, -1987, -1987,  1163, -1987,  1484,    57,
   -1987, -1987, -1987, -1987,  1481,   424,    20, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987,  1228, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987,  1157, -1987,   -51, -1987, -1987, -1987, -1987,
   -1987,  1489, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
      25, -1987, -1987, -1987, -1987, -1987, -1987, -1987,  1228, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987,  1157, -1987, -1987,
   -1987, -1987, -1987,  1192, -1987,  1342, -1987, -1987, -1987, -1987,
    1151,  1319,  1228, -1987, -1987, -1987, -1987, -1987,  1175, -1987,
    1488,  1340, -1987,  1492, -1987,  1491,  1493, -1987, -1987, -1987,
   -1987,  1196, -1987,  1349, -1987, -1987, -1987, -1987, -1987,  1171,
    1216,  1354, -1987, -1987, -1987,  1497,  1321,   344, -1987,  1208,
   -1987,  1357, -1987, -1987, -1987, -1987, -1987,  1323,  1228, -1987,
   -1987, -1987, -1987, -1987,  1181, -1987, -1987, -1987,  1361,  1505,
    1506, -1987, -1987, -1987, -1987, -1987,  1325,   258, -1987,  1270,
   -1987, -1987, -1987, -1987, -1987,  1512,  1508,  1509, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
    1228, -1987, -1987, -1987, -1987, -1987,  1190, -1987, -1987,  1510,
    1511,  1228, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987,  1233, -1987, -1987,  1514,  1517,  1518,  1519, -1987,  1195,
   -1987, -1987, -1987,  1377, -1987, -1987,   623,  1327,   449, -1987,
    1521,  1522, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,  1166, -1987,  1332,  1283,
   -1987, -1987, -1987,  1528,  1524,  1526,  1527,  1529,  1530,  1531,
    1532,  1533, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987,  1534,   171,  1535,
     171,  1536,   171,  1537,   171,  1538,   171,  1539,   171,  1540,
     171,  1541,   171,  1542,   171, -1987,  1550,  1544, -1987, -1987,
   -1987,  1547,  1546, -1987, -1987, -1987,  1551,  1552,  1553,  1554,
    1555,  1556,  1557,   695,  1263, -1987,  1561,  1558, -1987, -1987,
   -1987, -1987, -1987,  1263, -1987, -1987, -1987,  1263, -1987, -1987,
   -1987,  1263, -1987, -1987, -1987,  1263, -1987, -1987, -1987,  1263,
   -1987, -1987, -1987,  1263, -1987, -1987, -1987,  1263, -1987, -1987,
   -1987,  1263, -1987, -1987, -1987,  1559,   436,  1562,  1293, -1987,
   -1987,  1563,  1564,  1565,  1566,  1567,  1568,  1569,  1570, -1987,
   -1987,  1268,  1331,  1571,  1574,  1268, -1987,  1268, -1987,  1268,
   -1987,  1268, -1987,  1268, -1987,  1268, -1987,  1268, -1987,  1268,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987,  1287, -1987,  1337, -1987,  1350, -1987,  1351, -1987,  1352,
   -1987,   436, -1987,   436, -1987,   990, -1987,   436, -1987,  1119,
   -1987,  1119, -1987,  1333, -1987,   436, -1987,   436, -1987,   436,
   -1987,   436, -1987, -1987,   436, -1987,   990, -1987,   436,  1578,
   -1987,  1314,  1151, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987,  1326,  1310,  1390,  1228, -1987, -1987, -1987, -1987,
   -1987,  1580,  1312,  1334,  1316,  1328,  1322,  1336,  1338,  1339,
    1341,  1345,  1343,  1353,  1347,  1355,  1359,  1362, -1987, -1987,
   -1987,  1583,  1392,  1584,  1394,  1587,  1397,  1588,  1399,  1185,
   -1987,   436, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
    1158, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,   990, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987,  1160, -1987,  1597,  1591, -1987,  1593, -1987,  1186, -1987,
   -1987,   436, -1987,  1184, -1987,   436, -1987,   436, -1987,   663,
   -1987,   990, -1987,  1174, -1987, -1987, -1987, -1987,  1151,  1401,
   -1987, -1987, -1987, -1987,  1405,  1228, -1987, -1987, -1987, -1987,
   -1987,  1363, -1987, -1987, -1987,  1407, -1987, -1987, -1987,  1409,
   -1987, -1987, -1987,  1411, -1987, -1987, -1987,  1413, -1987, -1987,
   -1987,  1415, -1987, -1987, -1987,  1417, -1987, -1987, -1987,  1419,
   -1987, -1987, -1987,  1421, -1987,   334,  1599,  1176, -1987, -1987,
    1601,  1364, -1987, -1987,  1606,  1365, -1987, -1987,  1610,  1366,
   -1987, -1987, -1987,  1205,   990,   990,   990,   990,   990,   990,
   -1987, -1987,   990,   990,   990,   990,   990,   990, -1987,   990,
   -1987, -1987, -1987,  1423,  1425,   990,   436,   436,   436, -1987,
    1234,     8, -1987,  1613,   436,   436, -1987,  1201, -1987,  1199,
    1200, -1987, -1987, -1987, -1987, -1987, -1987,  1616, -1987, -1987,
   -1987,  1197, -1987, -1987, -1987, -1987,  1617, -1987,  1620, -1987,
   -1987,  1621, -1987,  1622, -1987,  1623, -1987,  1625, -1987,  1628,
     990, -1987,  1191,  1429, -1987,  1228, -1987, -1987, -1987, -1987,
    1483, -1987, -1987, -1987, -1987, -1987,  1367, -1987,  1228, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,  1228, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
    1632, -1987,  1633, -1987,  1634, -1987,  1636, -1987, -1987,   990,
     990,   990,   990,  1279,  1278,   551,   752,  1273,  1272,   990,
    1271,  1267,  1266,    69,  1264,   771,   825,   866,  1255, -1987,
   -1987,  1256, -1987, -1987,   990,  1249,  1251,  1253, -1987, -1987,
    1257, -1987,  1655, -1987, -1987, -1987, -1987, -1987, -1987,  1258,
   -1987,  1246, -1987, -1987, -1987, -1987, -1987, -1987,  1431,  1215,
     990,   663,   663,   663,   663,   663,   663,   990, -1987, -1987,
   -1987, -1987, -1987,  1228, -1987, -1987, -1987, -1987, -1987,  1416,
    1229, -1987,  1520, -1987,  1387, -1987, -1987,  1389,  1393,  1525,
     -58,   -54, -1987,  1398,   -32,     6, -1987,  1543,  1400, -1987,
   -1987, -1987, -1987,  1368,  1370,  1371,  1305, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,   990, -1987, -1987, -1987,   907,
   -1987,  1662,  1664, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,  1275, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,  1225, -1987, -1987,  1671,  1672,
   -1987, -1987, -1987,   990, -1987,   663, -1987,   663, -1987,  1235,
   -1987,  1238, -1987,   663, -1987,  1227, -1987,   436,  1435,   231,
   -1987,  1432, -1987,  1437, -1987, -1987,  1450, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,  1439, -1987, -1987, -1987,
    1441, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987,  1450, -1987, -1987, -1987, -1987, -1987,  1372, -1987,
   -1987,  1680,   695, -1987,  1679,   648, -1987,   695,   695,  1230,
    1241,  1242, -1987, -1987,  1239, -1987,  1261,  1270, -1987, -1987,
   -1987, -1987,  1681,  1684, -1987, -1987, -1987, -1987, -1987, -1987,
      66, -1987, -1987, -1987, -1987,  1686, -1987,  1443,    37,   990,
   -1987, -1987, -1987, -1987,   616, -1987, -1987, -1987, -1987,    47,
     146,  1688, -1987, -1987,  1376,  1691,  1692, -1987, -1987, -1987,
    1693,  1694, -1987, -1987, -1987, -1987, -1987,  1446,  1697,  1698,
    1548, -1987,   695, -1987, -1987, -1987, -1987, -1987, -1987,  1699,
    1700, -1987, -1987, -1987,  1560,  1572,  1704, -1987,  1703, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,  1573, -1987, -1987, -1987,
   -1987, -1987, -1987,  1707, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987,  1705,  1706, -1987,  1575,   -75,  1709,   695, -1987, -1987,
    1576,  1708, -1987,  1579, -1987, -1987, -1987, -1987, -1987, -1987,
    1475,  1710,  1711, -1987, -1987, -1987,  1712,  1713, -1987, -1987,
   -1987,   695,  1721, -1987,  1723,  1449, -1987, -1987
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,  1677, -1987,
    1714, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,  1674,
   -1987, -1987, -1987, -1987,  1581, -1987, -1987, -1987, -1987, -1987,
    1378, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,  1379, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,  1598,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
    1223, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987,  1516, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987,  1150, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,  1426, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987,  1102, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987,  1089, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987,  1217, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,   989, -1987, -1987, -1987,
   -1987, -1987,   933, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   764,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987,   717, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987,   478, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987,   480, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987,   730, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,   515, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,   514, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   691,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   454, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987,   452, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   248,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   770, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   561, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987,  1013, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987,   941, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
     -63, -1987, -1987, -1987, -1987,  -574, -1987,  -368, -1275,  -198,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1249, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,  -832, -1987,
   -1987, -1987, -1987, -1987,  -785, -1987, -1987, -1987, -1987, -1987,
    -866, -1987, -1987, -1987, -1987, -1987, -1053, -1987, -1987, -1987,
   -1987, -1987, -1175, -1987, -1987, -1987, -1987, -1987, -1018, -1987,
   -1987, -1987, -1987, -1987, -1118, -1987, -1987, -1987, -1987, -1987,
   -1055, -1308, -1987, -1987, -1987, -1987, -1987, -1987, -1987,  -646,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,  -995, -1987, -1987, -1987, -1987,
   -1987, -1003, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987,   655, -1987, -1310, -1059,   724,
     411,   701, -1987, -1987,  -606,  -848, -1987, -1987,  -492, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987,  -957,  -670, -1987, -1986,
   -1987, -1987, -1987, -1987,  -669,  -668, -1987, -1987, -1987, -1987,
    -728, -1987, -1987, -1987, -1987, -1987,  -141, -1987, -1987, -1050,
   -1987, -1987, -1987, -1987, -1987,  -514, -1987, -1987, -1987, -1987,
   -1987,  -503, -1987, -1987, -1987, -1987, -1987, -1046, -1987, -1987,
    -579, -1987, -1987,  -689, -1987, -1987,  -228, -1987, -1987,  -592,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1802, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1788, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,   -56,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1835,  -661, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987,
   -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987, -1987
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     501,   733,   286,  1331,   252,   666,  1381,   395,   277,   504,
     615,   274,   417,   268,   506,   271,  1149,  1277,  2220,  2221,
     381,  1169,   386,  1930,  1469,   509,  1470,  1471,   758,  1469,
    1172,  1470,  1471,  1899,  1174,  1901,  1420,   583,  1469,  1961,
    1470,  1471,   650,   525,  1981,   799,  1059,  1971,   928,  1973,
    1216,  1975,  1464,  1977,  1028,  1087,  1979,  2476,    49,  1221,
    1983,  1491,    50,  1223,  1156,   758,  1233,   705,    51,   977,
    2460,    49,  1043,  1445,  2517,    50,  1264,  1395,   299,  2299,
    2300,    51,    52,   665,   254,   126,  1192,   127,  1297,   128,
    2363,   129,  1228,  1251,  2367,    52,   300,   283,    53,  1507,
    1349,   535,   483,   486,   365,   373,   741,   380,  1286,   385,
     301,    53,   547,  2053,  1016,   130,  2372,  1514,   302,  1182,
    1183,  1159,   477,   762,   763,   538,  1476,  1276,   303,  1188,
     304,  1502,   541,  1365,  1027,   480,  1367,  1368,   744,   131,
       6,  1487,   305,   756,  2080,   704,   306,   745,   307,     7,
     308,   216,   309,   217,  2376,   872,  2486,  2487,    12,  1231,
     620,   548,   280,  1287,  1057,  1504,   525,   478,   265,  1193,
    1194,   218,  1195,  1309,   364,  1520,   481,   153,   154,  2120,
     756,   219,   536,  2087,   740,   611,   612,  2089,   643,  2090,
     284,   366,   474,   645,   487,  1325,   515,   484,   647,   220,
    1406,  1407,  1544,   542,  2518,   221,  1450,  1451,   539,  1522,
     764,   428,   601,   602,  1492,  1446,  1181,  1234,   520,    14,
    2364,   601,   602,  2461,  2368,   266,  2477,  2478,   808,   978,
     531,  1265,  1170,  1533,   150,  1298,  1446,  1587,  1044,   281,
     560,  1083,   565,   544,   570,  1227,  2373,  2179,  1029,   601,
     602,  2469,  2189,  2190,  2191,  2192,  2193,  2194,  1235,   801,
    2197,  2198,  2199,  2200,  2201,  2202,   550,  2204,  1266,  1389,
    1017,  1112,   476,  2214,   545,  2470,   601,   602,  1088,  1575,
    1299,  1495,  1496,   526,  2377,   809,   418,  1088,  2215,  2216,
    2217,  1508,  1060,   601,   602,  1433,  2229,  2231,    17,   510,
     489,   490,  2301,   403,  1436,  1506,  2302,    30,  1441,    80,
     817,   584,    54,   636,  1100,  1088,   651,   200,  2247,  1278,
     637,  1598,   148,  1518,   721,   722,  1500,   559,   203,   564,
    1424,   569,  1604,  1481,   404,    55,  1472,    56,   676,    57,
     677,    58,  1088,   269,   278,   275,  1468,   272,    55,  1524,
      56,    41,    57,   204,    58,   678,  1373,   601,   602,  1088,
     310,   132,   811,   601,   602,   812,   151,   152,  1715,  1716,
    2426,   491,   153,   154,  2328,  2329,  1717,  1143,   604,   818,
     819,  1496,   820,   614,    20,    21,  1412,  2283,  2284,  2285,
    2286,  1175,   429,  2290,  2292,   430,  2442,  2295,   431,   118,
     153,   154,  1456,  2309,  2311,  2313,  2335,  2337,  2339,  2341,
    2343,  2345,  2316,   151,   152,   205,  1072,   601,   602,   222,
    1224,   151,   152,  1088,   208,  1527,  1554,  1555,   683,  1088,
     206,   216,   207,   217,   238,   611,   612,   687,  2333,   293,
     126,   257,   127,   258,   128,  2347,   129,   151,   152,   984,
    1103,   218,   985,  2482,  2490,   292,   664,  2412,  2413,   370,
     371,   219,   734,   296,   396,   397,   398,   399,   818,   819,
     130,   820,  2222,   709,  1144,   723,   724,   151,   152,   220,
     720,     1,     2,   153,   154,   221,    25,    26,  1176,   370,
     371,   151,   152,  2388,   131,   601,   602,  2390,    33,    34,
    2400,   299,  2401,   151,   152,   611,   612,   294,  2404,   153,
     154,   601,   602,   153,   154,    44,    45,  1225,   703,   300,
     759,   760,   295,  1092,  1193,  1194,   336,  1195,  1102,   121,
     122,  2399,   368,   301,   165,   166,   170,   171,   394,  1554,
    1555,   302,  1990,   175,   176,   769,  1556,  1557,   377,   732,
     382,   303,  1136,   304,   180,   181,   387,   739,   401,  2406,
    2449,   151,   152,   788,  1160,   305,  1173,   185,   186,   306,
     402,   307,  1189,   308,  1558,   309,   757,   409,  1122,   190,
     191,   410,   151,   152,  1123,  1124,   601,   602,   153,   154,
    1125,  1126,   195,   196,   412,  1222,   611,   612,   211,   212,
     240,   241,  1232,   259,   260,   287,   288,   834,   338,   339,
    1430,  1431,   411,   757,   343,   344,  2000,   348,   349,   353,
     354,  1792,   358,   359,   414,  1793,   413,  2474,   415,  1794,
     389,   390,   800,   856,  1122,   416,  1204,   437,   151,   152,
    1123,  1124,   601,   602,   153,   154,  1125,  1126,  1652,  1653,
     423,   424,   611,   612,   464,   881,   439,   440,  1495,  1496,
    1166,  1167,   444,   445,   892,  1442,   499,  1654,  1655,  1656,
    1657,  1658,  1659,  1660,  1661,   449,   450,   502,  2124,   404,
     905,   454,   455,   459,   460,   494,   495,  1122,   897,   916,
     507,   151,   152,  1123,  1124,   601,   602,   153,   154,  1125,
    1126,   489,   490,   871,   935,   611,   612,   551,   552,   573,
     574,  1127,  1128,   945,   796,   723,   724,   151,   152,  1190,
     521,   601,   602,  1792,  1383,   598,   599,  1793,  1775,   608,
     609,  1794,  1777,   660,   661,   516,  1779,   418,   921,   556,
    1781,   699,   700,   990,  1783,  1795,  2135,  1796,  1785,  1797,
     532,  1798,  1787,  1799,  1422,  1800,  1789,  1801,   533,  1802,
     578,  1803,  1443,  1804,  2178,  1805,   534,  1806,   579,  1807,
    1466,  1808,  1872,  1809,  1874,  1810,  1876,   561,  1878,   566,
    1880,   580,  1882,   571,  1884,  1038,  1886,   581,  1263,   710,
     711,   735,   736,   582,  1046,   589,  1122,   777,   778,  1374,
     151,   152,  1123,  1124,   601,   602,   153,   154,  1125,  1126,
     782,   783,   791,   792,   611,   612,   835,   836,  1212,  1213,
     857,   858,   867,   868,   882,   883,   906,   907,  1567,  1413,
     930,   931,   936,   937,   954,   955,   960,   961,   966,   967,
    1440,   971,   972,   590,   950,  1457,   591,  1795,   592,  1796,
     593,  1797,   594,  1798,   510,  1799,   626,  1800,   627,  1801,
    1310,  1802,   628,  1803,   629,  1804,   619,  1805,  1615,  1806,
     631,  1807,   632,  1808,   630,  1809,  2258,  1810,  1616,   633,
    1617,   635,  1618,   634,  1619,   648,  1620,   667,  1621,  2266,
    1622,   668,  1623,   584,  1624,   996,   997,  1002,  1003,  1047,
    1048,  1101,  1093,  1094,  1625,   656,  1202,   669,  1903,  2272,
    1904,   670,  1905,   671,  1906,   674,  1907,   684,  1908,   685,
    1909,  2289,  1910,   686,  1911,  1132,  1912,   692,  1913,   695,
    1914,   688,  1915,   636,  1916,   651,  1917,   707,  1918,  1171,
    1919,   691,  1920,   706,  1921,   693,  1922,   708,  1923,   694,
    1924,   715,  1925,   718,  1926,  1589,  1927,   719,  1928,    81,
    1929,    82,    83,    84,   743,    85,    86,    87,  1220,    88,
      89,    90,   742,    91,    92,    93,   750,    94,    95,   796,
     723,   724,   151,   152,  1117,  1118,   601,   602,  1151,  1152,
    1161,  1162,  1207,  1208,  1252,  1253,   611,   612,  1292,  1293,
     761,  1326,  1327,  1563,  2350,  1903,   767,  1904,   768,  1905,
     770,  1906,   745,  1907,   774,  1908,   789,  1909,   790,  1910,
    1903,  1911,  1904,  1912,  1905,  1913,  1906,  1914,  1907,  1915,
    1908,  1916,  1909,  1917,  1910,  1918,  1911,  1919,  1912,  1920,
    1913,  1921,  1914,  1922,  1915,  1923,  1916,  1924,  1917,  1925,
    1918,  1926,  1919,  1927,  1920,  1928,  1921,  1929,  1922,  2091,
    1923,  2092,  1924,  2093,  1925,  2094,  1926,  2095,  1927,  2096,
    1928,  2097,  1929,  2098,  1725,  2099,  1729,   802,  1733,   805,
    1737,   827,  1741,   828,  1745,   831,  1749,   840,  1753,  1375,
    1376,  2091,   841,  2092,   812,  2093,   845,  2094,   847,  2095,
     849,  2096,   853,  2097,  2448,  2098,  2091,  2099,  2092,  1903,
    2093,  1904,  2094,  1905,  2095,  1906,  2096,  1907,  2097,  1908,
    2098,  1909,  2099,  1910,  2291,  1911,   850,  1912,  1903,  1913,
    1904,  1914,  1905,  1915,  1906,  1916,  1907,  1917,  1908,  1918,
    1909,  1919,  1910,  1920,  1911,  1921,  1912,  1922,  1913,  1923,
    1914,  1924,  1915,  1925,  1916,  1926,  1917,  1927,  1918,  1928,
    1919,  1929,  1920,  2308,  1921,   862,  1922,   863,  1923,   874,
    1924,   873,  1925,   875,  1926,  1382,  1927,  1726,  1928,  1730,
    1929,  1734,  1903,  1738,  1904,  1742,  1905,  1746,  1906,  1750,
    1907,  1754,  1908,   878,  1909,   887,  1910,   888,  1911,   893,
    1912,   900,  1913,   894,  1914,  1421,  1915,   901,  1916,   897,
    1917,   902,  1918,  1435,  1919,   911,  1920,   912,  1921,  2310,
    1922,  1465,  1923,  1903,  1924,  1904,  1925,  1905,  1926,  1906,
    1927,  1907,  1928,  1908,  1929,  1909,   917,  1910,   918,  1911,
     921,  1912,   924,  1913,   929,  1914,   941,  1915,   942,  1916,
     947,  1917,   946,  1918,   950,  1919,   959,  1920,   976,  1921,
     983,  1922,  2312,  1923,  1903,  1924,  1904,  1925,  1905,  1926,
    1906,  1927,  1907,  1928,  1908,  1929,  1909,  1001,  1910,   992,
    1911,  1007,  1912,  1015,  1913,  1010,  1914,  1022,  1915,  1034,
    1916,  1035,  1917,  2389,  1918,  1039,  1919,   978,  1920,   984,
    1921,  1058,  1922,  1052,  1923,  1067,  1924,  1068,  1925,  1072,
    1926,  1075,  1927,  1076,  1928,  1017,  1929,  1390,  1391,  1399,
    1400,  1414,  1415,  1425,  1426,  1458,  1459,  1482,  1483,  1528,
    1529,  1549,  1550,  1570,  1571,  1581,  1582,  1649,  1650,  1695,
    1696,  1865,  1866,  1968,  1969,  1768,  1081,  1903,  1084,  1904,
    1029,  1905,  1104,  1906,  1105,  1907,  1113,  1908,  1060,  1909,
    1597,  1910,  1145,  1911,  1150,  1912,  1191,  1913,  1243,  1914,
    1204,  1915,  1244,  1916,  1110,  1917,  1245,  1918,  1246,  1919,
    1257,  1920,  1247,  1921,  1258,  1922,  1114,  1923,  1274,  1924,
    1280,  1925,  2223,  1926,  1281,  1927,  1282,  1928,  1307,  1929,
    1995,  1996,  2037,  2038,  2041,  2042,  1588,  2045,  2046,  2049,
    2050,  2125,  2126,  1284,  1676,  2130,  2131,  2138,  2139,  2143,
    2144,  2148,  2149,  2153,  2154,  2158,  2159,  2163,  2164,  2168,
    2169,  2173,  2174,  2208,  2209,  2211,  2212,  2248,  2249,  2253,
    2254,  2325,  2326,  2328,  2329,  2407,  2408,  2420,  2421,  2429,
    2430,  2434,  2435,  2464,  2465,  1291,  1311,  1234,  1233,  1317,
    1318,  1321,  1319,  1320,  1333,  1334,  1336,  1339,  1341,  1265,
    1264,  1340,  1347,  1351,  1355,  1357,  1350,  1298,  1352,  1363,
    1297,  1366,  1384,  1385,  1397,  1398,  1444,  1489,  1477,  2224,
    1490,  1493,  1515,  1526,  1525,  1535,  1536,  1537,  1538,  1539,
    1542,  1540,  1541,  1446,  1507,  1548,  1568,  1760,  1569,  1577,
    1578,  1579,  1580,  1543,  1590,  1594,  1595,  1596,  1601,  1602,
    1600,  1605,  1609,  1610,  1611,  1612,  1704,  1613,  1614,  1674,
    1675,  1705,  1706,  1701,  1707,  1708,  1769,  1709,  1710,  1711,
    1712,  1713,  1850,  1861,  1714,  1723,  1727,  1731,  1735,  1739,
    1743,  1747,  1751,  1755,  1756,  1757,  1758,  1761,  1762,  1763,
    1764,  1765,  1766,  1767,  1773,  1986,  1774,  1791,  1849,  1889,
    1891,  1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,  1870,
    1871,  1963,  1991,  1893,  1895,  1897,  1985,  1992,  2002,  2003,
    2010,  2036,  2040,  2007,  2006,  2044,  2048,  2052,  2079,  2011,
    2083,  2084,  2082,  2085,  2014,  2180,  2086,  2182,  2088,  2018,
    2121,  2022,  2184,  2030,  2181,  2015,  2186,  2026,  2019,  2188,
    2023,  2228,  2218,  2233,  2027,  2234,  2236,  2240,  2235,  2237,
    2241,  2242,  2243,  2244,  2034,  2245,  2031,  2137,  2246,  2260,
    2279,  2280,  2281,  2265,  2282,  2287,  2288,  2293,  2294,  2297,
    2298,  2296,  2183,  2314,  2307,  2317,  2315,  2185,  2321,  2318,
    2418,  2320,  2187,  2319,  2323,  2357,  2352,  2358,  2354,  2387,
    2391,  2359,  2392,  2360,  2322,  2396,  2371,  2393,  2383,  2397,
    2398,  2405,  2403,  2402,  2419,  1496,  2445,  2447,  2454,  2458,
    2452,  2380,  2459,  2453,  2500,  2456,  2462,  2455,  2493,  2496,
    2497,  2498,  2499,  2501,  2502,  2503,  2511,  2506,  2507,  2508,
    2510,  2513,  2526,  2514,  2515,  2521,  2524,   117,  2529,  2530,
    2531,  2509,  2512,  2532,  2516,  2523,  2384,  2535,  2525,  2537,
    2385,  2536,   239,  2386,   149,   595,   657,   264,   438,    40,
     337,   689,   696,   787,  1036,   621,  1342,   842,  1085,  1077,
    2443,  1344,  1312,  1115,  1314,  1358,  1360,  1040,  1285,  1545,
     771,  2457,  2495,   848,  1215,  1434,  1099,  1131,  2353,  2481,
    2417,  2491,  2492,  2475,     0,  1967,     0,     0,     0,     0,
       0,     0,     0,     0,   517,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   522,
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
       0,     0,     0,     0,  2446,     0,     0,     0,     0,  2450,
    2451,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2522,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2534
};

static const yytype_int16 yycheck[] =
{
     368,   690,   200,  1252,   145,   597,  1316,     8,     4,   377,
     524,     4,    67,     4,   382,     4,  1071,     4,    10,    11,
     248,  1080,   250,  1825,     4,    67,     6,     7,   717,     4,
    1080,     6,     7,  1821,  1080,  1823,  1346,    67,     4,  1827,
       6,     7,    67,    78,  1846,   773,    51,  1835,   896,  1837,
    1109,  1839,  1362,  1841,   111,    10,  1844,    10,    56,  1109,
    1848,     4,    60,  1109,    10,   754,   150,   659,    66,   145,
       4,    56,   118,   145,   149,    60,   150,  1326,    34,    10,
      11,    66,    80,   597,   147,    36,    69,    38,   150,    40,
     148,    42,    10,  1148,   148,    80,    52,     4,    96,   150,
    1275,     4,     6,     4,     4,   246,   698,   248,   286,   250,
      66,    96,     4,  1901,   145,    66,   148,  1425,    74,    10,
      11,  1078,     4,     6,     7,     4,  1375,  1180,    84,  1086,
      86,  1406,     4,  1308,   966,     6,    10,    11,    73,    90,
       0,  1390,    98,   717,  1946,   659,   102,    82,   104,   120,
     106,    46,   108,    48,   148,   844,    10,    11,    14,  1116,
      72,    53,     4,   341,   996,  1414,    78,    49,     4,   152,
     153,    66,   155,  1226,   237,  1450,    47,   169,   170,  1981,
     754,    76,    85,  1971,   698,   177,   178,  1975,   556,  1977,
      97,    91,   333,   561,    95,  1250,   394,   101,   566,    94,
      10,    11,  1510,    75,   279,   100,    10,    11,    87,  1458,
      93,    25,   167,   168,   157,   287,  1082,   301,   416,    15,
     278,   167,   168,   157,   278,    61,   179,   180,     4,   305,
     428,   305,  1080,  1482,    31,   297,   287,  1547,   284,    81,
     468,  1026,   470,     4,   472,  1111,   278,  2035,   305,   167,
     168,   214,  2054,  2055,  2056,  2057,  2058,  2059,   342,   773,
    2062,  2063,  2064,  2065,  2066,  2067,   464,  2069,   342,  1324,
     301,  1056,   335,  2075,    35,   238,   167,   168,   233,  1528,
     342,   234,   235,   318,   278,    61,   341,   233,  2076,  2077,
    2078,   342,   297,   167,   168,  1354,  2084,  2085,   309,   341,
       6,     7,   233,    57,  1354,  1423,   237,   311,  1354,   121,
      83,   341,   310,    92,  1042,   233,   341,    22,  2120,   306,
      99,  1570,   310,   298,    10,    11,   306,   468,     5,   470,
    1348,   472,  1581,  1388,    88,   333,   302,   335,    16,   337,
      18,   339,   233,   334,   340,   338,  1364,   336,   333,  1467,
     335,   313,   337,     5,   339,    33,  1313,   167,   168,   233,
     316,   312,    85,   167,   168,    88,   163,   164,   197,   198,
    2356,    77,   169,   170,   228,   229,   205,  1066,   519,   152,
     153,   235,   155,   524,    10,    11,  1343,  2189,  2190,  2191,
    2192,  1080,   206,  2195,  2196,   209,  2382,  2199,   212,   315,
     169,   170,  1359,  2205,  2206,  2207,  2241,  2242,  2243,  2244,
    2245,  2246,  2214,   163,   164,     5,   158,   167,   168,   314,
    1109,   163,   164,   233,   317,  1480,   195,   196,   626,   233,
       5,    46,     5,    48,   312,   177,   178,   635,  2240,   127,
      36,     3,    38,     3,    40,  2247,    42,   163,   164,    68,
    1042,    66,    71,  2439,  2440,   123,   597,   226,   227,   175,
     176,    76,   690,   139,   465,   466,   467,   468,   152,   153,
      66,   155,   464,   671,  1066,   161,   162,   163,   164,    94,
     678,    12,    13,   169,   170,   100,    10,    11,  1080,   175,
     176,   163,   164,  2295,    90,   167,   168,  2299,    10,    11,
    2335,    34,  2337,   163,   164,   177,   178,   131,  2343,   169,
     170,   167,   168,   169,   170,    10,    11,  1109,   659,    52,
     718,   719,   135,  1037,   152,   153,   314,   155,  1042,    10,
      11,  2333,    10,    66,    10,    11,    10,    11,     6,   195,
     196,    74,  1852,    10,    11,   743,   202,   203,    10,   690,
      10,    84,  1066,    86,    10,    11,    10,   698,     8,  2347,
    2395,   163,   164,   761,  1078,    98,  1080,    10,    11,   102,
       8,   104,  1086,   106,   230,   108,   717,    61,   159,    10,
      11,   334,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    10,    11,   338,  1109,   177,   178,    10,    11,
      10,    11,  1116,    10,    11,    10,    11,   805,    10,    11,
     191,   192,   336,   754,    10,    11,  1865,    10,    11,    10,
      11,   287,    10,    11,    81,   291,   340,  2429,    97,   295,
      10,    11,   773,   831,   159,     6,   217,   316,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   199,   200,
      10,    11,   177,   178,    32,   853,    10,    11,   234,   235,
     185,   186,    10,    11,   862,  1354,    91,   218,   219,   220,
     221,   222,   223,   224,   225,    10,    11,     3,  1988,    88,
     878,    10,    11,    10,    11,    10,    11,   159,   213,   887,
       6,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     6,     7,   844,   902,   177,   178,    10,    11,    10,
      11,   183,   184,   911,   160,   161,   162,   163,   164,  1087,
      67,   167,   168,   287,  1316,    10,    11,   291,  1723,    10,
      11,   295,  1727,    10,    11,    57,  1731,   341,   210,    10,
    1735,    10,    11,   941,  1739,   411,  1995,   413,  1743,   415,
       8,   417,  1747,   419,  1346,   421,  1751,   423,     8,   425,
      49,   427,  1354,   429,   430,   431,     8,   433,    47,   435,
    1362,   437,  1775,   439,  1777,   441,  1779,    10,  1781,    10,
    1783,   101,  1785,    10,  1787,   983,  1789,    95,  1156,    10,
      11,    10,    11,    77,   992,    41,   159,    10,    11,  1313,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      10,    11,    10,    11,   177,   178,    10,    11,   181,   182,
      10,    11,    10,    11,    10,    11,    10,    11,  1517,  1343,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
    1354,    10,    11,     8,   207,  1359,    43,   411,    39,   413,
      37,   415,    67,   417,   341,   419,     6,   421,     6,   423,
    1228,   425,     6,   427,     6,   429,   318,   431,   245,   433,
      87,   435,    75,   437,    85,   439,  2125,   441,   255,    35,
     257,     6,   259,    53,   261,     6,   263,    89,   265,  2138,
     267,     3,   269,   341,   271,    10,    11,    10,    11,    10,
      11,  1042,    10,    11,   281,    67,  1104,   342,   357,  2158,
     359,     3,   361,    30,   363,    10,   365,     8,   367,     8,
     369,   370,   371,     8,   373,  1066,   375,   109,   377,    67,
     379,    99,   381,    92,   383,   341,   385,     8,   387,  1080,
     389,   107,   391,   342,   393,   105,   395,     8,   397,   103,
     399,    84,   401,     3,   403,  1547,   405,     3,   407,   122,
     409,   124,   125,   126,     6,   128,   129,   130,  1109,   132,
     133,   134,   342,   136,   137,   138,    60,   140,   141,   160,
     161,   162,   163,   164,    10,    11,   167,   168,    10,    11,
      10,    11,    10,    11,    10,    11,   177,   178,    10,    11,
       6,    10,    11,  1517,  2253,   357,     3,   359,   342,   361,
      73,   363,    82,   365,   307,   367,    93,   369,     8,   371,
     357,   373,   359,   375,   361,   377,   363,   379,   365,   381,
     367,   383,   369,   385,   371,   387,   373,   389,   375,   391,
     377,   393,   379,   395,   381,   397,   383,   399,   385,   401,
     387,   403,   389,   405,   391,   407,   393,   409,   395,   443,
     397,   445,   399,   447,   401,   449,   403,   451,   405,   453,
     407,   455,   409,   457,  1680,   459,  1682,   303,  1684,    24,
    1686,     8,  1688,   299,  1690,    21,  1692,    61,  1694,    10,
      11,   443,    85,   445,    88,   447,     5,   449,    83,   451,
       6,   453,    20,   455,   456,   457,   443,   459,   445,   357,
     447,   359,   449,   361,   451,   363,   453,   365,   455,   367,
     457,   369,   459,   371,   372,   373,   283,   375,   357,   377,
     359,   379,   361,   381,   363,   383,   365,   385,   367,   387,
     369,   389,   371,   391,   373,   393,   375,   395,   377,   397,
     379,   399,   381,   401,   383,   403,   385,   405,   387,   407,
     389,   409,   391,   392,   393,     6,   395,   144,   397,     8,
     399,   154,   401,    70,   403,  1316,   405,  1680,   407,  1682,
     409,  1684,   357,  1686,   359,  1688,   361,  1690,   363,  1692,
     365,  1694,   367,    28,   369,     6,   371,   144,   373,   308,
     375,    89,   377,   110,   379,  1346,   381,    79,   383,   213,
     385,    23,   387,  1354,   389,     6,   391,    50,   393,   394,
     395,  1362,   397,   357,   399,   359,   401,   361,   403,   363,
     405,   365,   407,   367,   409,   369,   304,   371,    44,   373,
     210,   375,    44,   377,     8,   379,     6,   381,   285,   383,
      44,   385,   300,   387,   207,   389,     8,   391,     6,   393,
       6,   395,   396,   397,   357,   399,   359,   401,   361,   403,
     363,   405,   365,   407,   367,   409,   369,     8,   371,    29,
     373,   341,   375,     6,   377,   325,   379,   341,   381,     8,
     383,   145,   385,   386,   387,    71,   389,   305,   391,    68,
     393,     6,   395,   341,   397,    45,   399,   321,   401,   158,
     403,     8,   405,   145,   407,   301,   409,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   173,
     174,    10,    11,    10,    11,  1713,    45,   357,   111,   359,
     305,   361,     6,   363,   144,   365,     8,   367,   297,   369,
    1558,   371,   323,   373,     8,   375,     8,   377,     8,   379,
     217,   381,     3,   383,    45,   385,     3,   387,     3,   389,
       6,   391,   319,   393,   156,   395,    51,   397,     3,   399,
     306,   401,  2081,   403,     6,   405,     5,   407,     3,   409,
      10,    11,    10,    11,    10,    11,  1547,    10,    11,    10,
      11,    10,    11,    69,  1612,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,   246,   247,    10,
      11,    10,    11,   228,   229,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,     8,   342,   301,   150,     6,
       8,   327,     8,     8,     8,   236,   148,   326,   342,   305,
     150,   302,     8,     8,     6,   342,   306,   297,   154,     8,
     150,   298,     8,   329,   322,     8,     8,   324,   331,  2081,
       6,    10,     3,   151,   302,   320,     8,   157,     6,     8,
     151,     8,   306,   287,   150,     8,   298,  1705,   151,   328,
     149,     6,     6,   342,   244,     3,     8,     8,     8,     8,
     330,   288,     8,     6,     6,     6,   243,   332,   151,     8,
       8,     3,     8,   201,     8,     8,   273,     8,     8,     8,
       8,     8,   249,   275,    10,    10,    10,    10,    10,    10,
      10,    10,    10,     3,    10,     8,    10,     6,     6,     6,
       6,     6,     6,     6,     3,   251,     8,     8,     6,   282,
     233,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       6,   462,   256,   233,   233,   233,     8,   277,     8,   277,
     262,     8,     8,   277,   260,     8,     8,   412,   440,   277,
       3,    10,   442,    10,   268,     6,   420,     6,   424,   270,
     436,   266,     6,   258,   438,   277,     6,   264,   277,   414,
     277,     8,   388,   422,   277,   426,    10,    10,   428,   432,
      10,    10,    10,    10,   272,    10,   277,   274,    10,   156,
       8,     8,     8,   276,     8,   366,   368,   374,   376,   382,
     384,   380,   288,   398,   390,   406,   400,   292,     3,   408,
    2349,   404,   296,   410,   418,   278,   250,   278,   148,   364,
       8,   278,     8,   148,   416,   450,   278,   402,   278,     8,
       8,   454,   444,   448,   252,   235,     6,     8,   446,     8,
     460,   148,     8,   452,   248,   434,    10,   458,    10,     8,
       8,     8,     8,     6,     6,   157,     3,     8,     8,   149,
       6,     4,   237,     8,     8,     6,     8,    40,     8,     8,
       8,   149,   149,    10,   149,   149,   358,     6,   149,   280,
     360,     8,   134,   362,    60,   512,   586,   156,   312,    25,
     224,   639,   653,   754,   980,   528,  1268,   814,  1031,  1019,
     378,  1271,  1237,  1062,  1240,  1301,  1304,   987,  1197,  1511,
     747,  2407,   386,   822,  1109,  1354,  1042,  1066,  2260,  2439,
    2349,  2440,  2440,  2434,    -1,  1831,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   406,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
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
      -1,    -1,    -1,    -1,  2392,    -1,    -1,    -1,    -1,  2397,
    2398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2462,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2507,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2531
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   470,   471,   472,     0,   120,   479,   480,
    1111,  1112,    14,   473,    15,   477,   478,   309,   481,   482,
      10,    11,  1113,  1114,  1115,    10,    11,   474,   475,   476,
     311,   561,   562,    10,    11,   483,   484,   485,  1116,  1117,
     479,   313,   615,   616,    10,    11,   563,   564,   565,    56,
      60,    66,    80,    96,   310,   333,   335,   337,   339,   486,
     487,   488,   489,   490,   505,   506,   511,   512,   517,   518,
     523,   524,   529,   530,   535,   536,   541,   542,   547,   548,
     121,   122,   124,   125,   126,   128,   129,   130,   132,   133,
     134,   136,   137,   138,   140,   141,  1118,  1119,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,
    1132,  1133,  1134,  1135,  1136,  1137,  1138,   477,   315,   667,
     668,    10,    11,   617,   618,   619,    36,    38,    40,    42,
      66,    90,   312,   566,   567,   568,   569,   570,   575,   576,
     582,   583,   589,   590,   596,   597,   601,   602,   310,   488,
      31,   163,   164,   169,   170,   491,   492,   493,  1104,  1465,
    1466,  1467,  1492,  1493,  1494,    10,    11,   507,   508,   509,
      10,    11,   513,   514,   515,    10,    11,   519,   520,   521,
      10,    11,   525,   526,   527,    10,    11,   531,   532,   533,
      10,    11,   537,   538,   539,    10,    11,   543,   544,   545,
      22,   549,  1099,     5,     5,     5,     5,     5,   317,   762,
     763,    10,    11,   669,   670,   671,    46,    48,    66,    76,
      94,   100,   314,   620,   621,   622,   623,   624,   629,   630,
     635,   636,   641,   642,   647,   648,   653,   654,   312,   568,
      10,    11,   571,   572,   573,   577,   578,   584,   585,   591,
     592,   598,  1465,   603,  1099,  1108,  1109,     3,     3,    10,
      11,   494,   495,   496,   493,     4,    61,   510,     4,   334,
     516,     4,   336,   522,     4,   338,   528,     4,   340,   534,
       4,    81,   540,     4,    97,   546,  1108,    10,    11,   550,
     551,   552,   123,   127,   131,   135,   139,   764,   765,    34,
      52,    66,    74,    84,    86,    98,   102,   104,   106,   108,
     316,   672,   673,   674,   675,   676,   681,   682,   687,   688,
     693,   694,   699,   700,   705,   706,   722,   723,   729,   730,
     736,   737,   743,   744,   748,   749,   314,   622,    10,    11,
     625,   626,   627,    10,    11,   631,   632,   633,    10,    11,
     637,   638,   639,    10,    11,   643,   644,   645,    10,    11,
     649,   650,   651,   655,  1099,     4,    91,   574,    10,   580,
     175,   176,   579,  1465,  1495,  1496,  1497,    10,   587,   586,
    1465,  1495,    10,   594,   593,  1465,  1495,    10,   599,    10,
      11,   604,   605,   606,     6,     8,   465,   466,   467,   468,
    1110,     8,     8,    57,    88,   497,   498,   499,   500,    61,
     334,   336,   338,   340,    81,    97,     6,    67,   341,   553,
     554,   555,   556,    10,    11,   767,   768,   769,    25,   206,
     209,   212,   766,  1102,  1425,  1431,  1436,   316,   674,    10,
      11,   677,   678,   679,    10,    11,   683,   684,   685,    10,
      11,   689,   690,   691,    10,    11,   695,   696,   697,    10,
      11,   701,   702,   703,    32,   707,  1105,   724,   725,   731,
     732,   738,   739,   745,  1465,   750,  1099,     4,    49,   628,
       6,    47,   634,     6,   101,   640,     4,    95,   646,     6,
       7,    77,   652,  1106,    10,    11,   656,   657,   658,    91,
     581,  1106,     3,   588,  1106,   595,  1106,     6,   600,    67,
     341,   607,   608,   609,   610,  1108,    57,   499,   501,   502,
    1108,    67,   555,   557,   558,    78,   318,   770,   771,   772,
     773,  1108,     8,     8,     8,     4,    85,   680,     4,    87,
     686,     4,    75,   692,     4,    35,   698,     4,    53,   704,
    1108,    10,    11,   708,   709,   710,    10,   727,   726,  1465,
    1495,    10,   734,   733,  1465,  1495,    10,   741,   740,  1465,
    1495,    10,   746,    10,    11,   751,   752,   753,    49,    47,
     101,    95,    77,    67,   341,   659,   660,   661,   662,    41,
       8,    43,    39,    37,    67,   609,   611,   612,    10,    11,
     504,   167,   168,   503,  1465,  1474,  1475,  1476,    10,    11,
     560,   177,   178,   559,  1465,  1474,  1498,  1499,  1500,   318,
      72,   772,  1072,  1073,   774,   775,     6,     6,     6,     6,
      85,    87,    75,    35,    53,     6,    92,    99,   711,   712,
     713,   714,   728,  1106,   735,  1106,   742,  1106,     6,   747,
      67,   341,   754,   755,   756,   757,    67,   661,   663,   664,
      10,    11,   614,   613,  1465,  1474,  1498,    89,     3,   342,
       3,    30,  1074,  1103,    10,   780,    16,    18,    33,   776,
     777,   778,   779,  1108,     8,     8,     8,  1108,    99,   713,
     715,   107,   109,   105,   103,    67,   756,   758,   759,    10,
      11,   666,   665,  1465,  1474,  1498,   342,     8,     8,  1108,
      10,    11,  1075,  1076,  1077,    84,   781,   782,     3,     3,
    1108,    10,    11,   161,   162,   716,   717,   718,   719,  1459,
    1460,  1461,  1465,  1492,  1495,    10,    11,   761,   760,  1465,
    1474,  1498,   342,     6,    73,    82,  1078,  1079,  1080,  1081,
      60,   797,   798,   783,   784,   785,  1104,  1465,  1492,  1108,
    1108,     6,     6,     7,    93,   720,   721,     3,   342,  1108,
      73,  1080,  1082,  1083,   307,   803,   804,    10,    11,   799,
     800,   801,    10,    11,   786,   787,   788,   785,  1108,    93,
       8,    10,    11,  1085,  1086,  1087,   160,  1084,  1428,  1459,
    1465,  1474,   303,   881,   882,    24,   805,  1101,     4,    61,
     802,    85,    88,   789,   790,   791,   792,    83,   152,   153,
     155,  1088,  1089,  1090,  1091,  1092,  1093,     8,   299,   943,
     944,    21,   883,  1098,  1108,    10,    11,   806,   807,   808,
      61,    85,   791,   793,   794,     5,  1094,    83,  1090,     6,
     283,  1005,  1006,    20,   945,  1095,  1108,    10,    11,   884,
     885,   886,     6,   144,   809,   810,   811,    10,    11,   796,
     795,  1465,  1492,   154,     8,    70,  1049,  1050,    28,  1007,
    1096,  1108,    10,    11,   946,   947,   948,     6,   144,   887,
     888,   889,  1108,   308,   110,   823,   824,   213,   812,  1434,
      89,    79,    23,  1051,  1100,  1108,    10,    11,  1008,  1009,
    1010,     6,    50,   949,   950,   951,  1108,   304,    44,   901,
     902,   210,   890,  1430,    44,   839,   840,   825,  1434,     8,
      10,    11,   813,   814,   815,  1108,    10,    11,  1052,  1053,
    1054,     6,   285,  1011,  1012,  1108,   300,    44,   963,   964,
     207,   952,  1424,   914,    10,    11,   903,   904,   905,     8,
      10,    11,   891,   892,   893,   852,    10,    11,   841,   842,
     843,    10,    11,   826,   827,   828,     6,   145,   305,   816,
     817,   818,   819,     6,    68,    71,  1055,  1056,  1057,  1058,
    1108,  1047,    29,  1013,  1097,   976,    10,    11,   965,   966,
     967,     8,    10,    11,   953,   954,   955,   341,   915,   916,
     325,   906,   907,  1167,  1168,     6,   145,   301,   894,   895,
     896,   897,   341,   853,   854,   844,   845,  1167,   111,   305,
     829,   830,   831,   832,     8,   145,   818,   820,  1108,    71,
    1057,  1059,  1060,   118,   284,  1048,  1108,    10,    11,  1014,
    1015,  1016,   341,   977,   978,   968,   969,  1167,     6,    51,
     297,   956,   957,   958,   959,   917,   918,    45,   321,   908,
    1173,  1174,   158,  1209,  1426,     8,   145,   896,   898,   855,
     856,    45,   846,  1173,   111,   831,   833,    10,   233,   821,
     822,  1445,  1474,    10,    11,  1062,  1063,  1064,  1061,  1428,
    1459,  1465,  1474,  1498,     6,   144,  1018,  1019,   979,   980,
      45,   970,  1173,     8,    51,   958,   960,    10,    11,   920,
     921,   922,   159,   165,   166,   171,   172,   183,   184,   919,
    1427,  1430,  1465,  1468,  1469,  1470,  1474,  1477,  1478,  1479,
    1486,  1487,  1488,  1492,  1498,   323,   909,  1179,  1180,  1209,
       8,    10,    11,  1169,  1170,  1171,    10,   899,   900,  1445,
    1474,    10,    11,   858,   859,   860,   185,   186,   857,  1427,
    1434,  1465,  1468,  1474,  1486,  1492,  1498,  1504,  1505,  1506,
     847,  1179,    10,    11,   834,   835,   836,   837,  1445,  1474,
    1106,     8,    69,   152,   153,   155,  1065,  1066,  1067,  1068,
    1069,  1070,  1108,  1026,   217,  1020,  1429,    10,    11,   982,
     983,   984,   181,   182,   981,  1424,  1427,  1462,  1463,  1464,
    1465,  1468,  1474,  1486,  1492,  1498,   971,  1179,    10,   961,
     962,  1445,  1474,   150,   301,   342,   923,   924,   925,   926,
     933,   934,   935,     8,     3,     3,     3,   319,   910,  1185,
    1186,  1209,    10,    11,  1175,  1176,  1177,     6,   156,  1139,
    1140,  1147,  1172,  1106,   150,   305,   342,   861,   862,   863,
     864,   871,   872,   873,     3,   848,  1185,     4,   306,   838,
     306,     6,     5,  1071,    69,  1067,   286,   341,  1017,  1027,
    1028,     8,    10,    11,  1021,  1022,  1023,   150,   297,   342,
     985,   986,   987,   988,   995,   996,   997,     3,   972,  1185,
    1106,   342,   925,   927,   934,   936,   937,     6,     8,     8,
       8,   327,   911,  1191,  1192,  1209,    10,    11,  1181,  1182,
    1183,  1139,  1178,     8,   236,  1437,   148,  1141,  1142,   326,
     302,   342,   863,   865,   872,   874,   875,     8,   849,  1191,
     306,     8,   154,  1029,  1030,     6,  1025,   342,   987,   989,
     996,   998,   999,     8,   973,  1191,   298,    10,    11,   928,
     929,   930,   931,  1445,  1474,    10,    11,   939,   940,   941,
     938,  1426,  1465,  1498,     8,   329,   912,  1197,  1198,  1209,
      10,    11,  1187,  1188,  1189,  1139,  1184,   322,     8,    10,
      11,  1148,  1149,  1150,  1143,  1144,    10,    11,   866,   867,
     868,   869,  1445,  1474,    10,    11,   877,   878,   879,   876,
    1426,  1465,  1498,   850,  1197,    10,    11,  1032,  1033,  1034,
     191,   192,  1031,  1427,  1429,  1465,  1468,  1471,  1472,  1473,
    1474,  1486,  1492,  1498,     8,   145,   287,  1024,  1210,  1211,
      10,    11,   990,   991,   992,   993,  1445,  1474,    10,    11,
    1001,  1002,  1003,  1000,  1426,  1465,  1498,   974,  1197,     4,
       6,     7,   302,   932,  1107,   942,  1139,   331,   913,  1203,
    1204,  1209,    10,    11,  1193,  1194,  1195,  1139,  1190,   324,
       6,     4,   157,    10,  1146,   234,   235,  1145,  1446,  1448,
     306,   870,  1107,   880,  1139,   851,  1203,   150,   342,  1035,
    1036,  1037,  1038,  1039,  1210,     3,  1212,  1213,   298,   994,
    1107,  1004,  1139,   975,  1203,   302,   151,  1209,    10,    11,
    1199,  1200,  1201,  1139,  1196,   320,     8,   157,     6,     8,
       8,   306,   151,   342,  1210,  1038,  1040,  1041,     8,    10,
      11,  1215,  1216,  1217,   195,   196,   202,   203,   230,  1214,
    1423,  1432,  1447,  1474,  1489,  1490,  1491,  1492,   298,   151,
      10,    11,  1205,  1206,  1207,  1139,  1202,   328,   149,     6,
       6,    10,    11,  1043,  1044,  1045,  1042,  1426,  1465,  1498,
     244,  1218,  1219,  1220,     3,     8,     8,  1108,  1139,  1208,
     330,     8,     8,  1046,  1139,   288,  1225,  1221,  1222,     8,
       6,     6,     6,   332,   151,   245,   255,   257,   259,   261,
     263,   265,   267,   269,   271,   281,  1226,  1227,  1228,  1252,
    1253,  1265,  1266,  1292,  1293,  1310,  1311,  1328,  1329,  1341,
    1342,  1359,  1360,  1377,  1378,  1390,  1391,  1394,  1395,    10,
      11,  1224,   199,   200,   218,   219,   220,   221,   222,   223,
     224,   225,  1223,  1438,  1439,  1440,  1441,  1442,  1449,  1450,
    1455,  1456,  1457,  1458,     8,     8,  1108,  1229,  1230,  1254,
    1255,  1267,  1268,  1294,  1295,  1312,  1313,  1330,  1331,  1343,
    1344,  1361,  1362,  1379,  1380,   173,   174,  1392,  1483,  1484,
    1485,   201,  1396,  1422,   243,     3,     8,     8,     8,     8,
       8,     8,     8,     8,    10,   197,   198,   205,  1231,  1433,
    1480,  1481,  1482,    10,  1256,  1433,  1480,    10,  1269,  1433,
    1480,    10,  1296,  1433,  1480,    10,  1314,  1433,  1480,    10,
    1332,  1433,  1480,    10,  1345,  1433,  1480,    10,  1363,  1433,
    1480,    10,  1381,  1433,  1480,     3,    10,     8,    10,  1397,
    1108,     6,     6,     6,     6,     6,     6,     6,  1106,   273,
    1232,  1234,  1235,     3,     8,  1234,  1257,  1234,  1270,  1234,
    1297,  1234,  1315,  1234,  1333,  1234,  1346,  1234,  1364,  1234,
    1382,     8,   287,   291,   295,   411,   413,   415,   417,   419,
     421,   423,   425,   427,   429,   431,   433,   435,   437,   439,
     441,  1581,  1582,  1583,  1586,  1587,  1590,  1591,  1594,  1595,
    1598,  1599,  1601,  1602,  1604,  1605,  1607,  1608,  1610,  1611,
    1614,  1615,  1619,  1620,  1622,  1623,  1625,  1626,  1628,  1629,
    1631,  1632,  1634,  1637,  1638,  1640,  1641,  1643,  1644,     6,
     249,  1399,  1400,     8,     8,     8,     8,     8,     8,     8,
       8,   275,  1233,  1240,  1241,    10,    11,  1236,  1237,  1238,
       8,     6,  1240,  1258,  1240,  1271,  1240,  1298,  1240,  1316,
    1240,  1334,  1240,  1347,  1240,  1365,  1240,  1383,  1635,   282,
    1393,   233,  1585,   233,  1589,   233,  1593,   233,  1597,  1581,
    1600,  1581,  1603,   357,   359,   361,   363,   365,   367,   369,
     371,   373,   375,   377,   379,   381,   383,   385,   387,   389,
     391,   393,   395,   397,   399,   401,   403,   405,   407,   409,
    1507,  1508,  1511,  1514,  1516,  1518,  1520,  1522,  1524,  1526,
    1528,  1530,  1532,  1534,  1536,  1538,  1539,  1541,  1543,  1545,
    1547,  1549,  1551,  1552,  1558,  1566,  1569,  1572,  1575,  1578,
    1606,  1581,  1609,   462,  1612,  1618,  1616,  1618,    10,    11,
    1621,  1581,  1624,  1581,  1627,  1581,  1630,  1581,  1633,  1581,
    1639,  1507,  1642,  1581,  1645,     8,   251,  1406,  1407,  1401,
    1426,   256,   277,  1246,  1247,    10,    11,  1242,  1243,  1244,
    1139,  1239,     8,   277,  1259,  1260,   260,   277,  1272,  1273,
     262,   277,  1299,  1300,   268,   277,  1317,  1318,   270,   277,
    1335,  1336,   266,   277,  1348,  1349,   264,   277,  1366,  1367,
     258,   277,  1384,  1385,   272,  1636,     8,    10,    11,  1584,
       8,    10,    11,  1588,     8,    10,    11,  1592,     8,    10,
      11,  1596,   412,  1581,  1525,  1517,  1519,  1523,  1527,  1529,
    1567,  1579,  1537,  1521,  1544,  1531,  1533,  1535,  1559,  1542,
    1573,  1570,  1576,  1509,  1512,  1515,  1546,  1548,  1550,   440,
    1507,  1554,   442,     3,    10,    10,   420,  1581,   424,  1581,
    1581,   443,   445,   447,   449,   451,   453,   455,   457,   459,
    1507,  1646,  1647,  1648,  1649,  1654,  1655,  1657,  1658,  1660,
    1663,  1664,  1666,  1667,  1669,  1670,  1672,  1673,  1675,  1676,
    1507,   436,  1413,  1408,  1426,    10,    11,  1402,  1403,  1404,
      10,    11,  1248,  1249,  1250,  1139,  1245,   274,    10,    11,
    1261,  1262,  1263,    10,    11,  1274,  1275,  1276,    10,    11,
    1301,  1302,  1303,    10,    11,  1319,  1320,  1321,    10,    11,
    1337,  1338,  1339,    10,    11,  1350,  1351,  1352,    10,    11,
    1368,  1369,  1370,    10,    11,  1386,  1387,  1388,   430,  1581,
       6,   438,     6,   288,     6,   292,     6,   296,   414,  1507,
    1507,  1507,  1507,  1507,  1507,  1568,  1580,  1507,  1507,  1507,
    1507,  1507,  1507,  1562,  1507,  1574,  1571,  1577,    10,    11,
    1510,    10,    11,  1513,  1507,  1581,  1581,  1581,   388,  1540,
      10,    11,   464,  1492,  1498,  1553,  1555,  1556,     8,  1581,
    1613,  1581,  1617,   422,   426,   428,    10,   432,  1651,  1652,
      10,    10,    10,    10,    10,    10,    10,  1507,   246,   247,
    1398,  1414,  1415,    10,    11,  1409,  1410,  1411,  1139,  1405,
     156,  1151,  1152,  1157,  1251,   276,  1139,  1264,  1277,  1278,
    1304,  1322,  1139,  1340,  1353,  1371,  1161,  1162,  1389,     8,
       8,     8,     8,  1507,  1507,  1507,  1507,   366,   368,   370,
    1507,   372,  1507,   374,   376,  1507,   380,   382,   384,    10,
      11,   233,   237,  1560,  1563,  1564,  1565,   390,   392,  1507,
     394,  1507,   396,  1507,   398,   400,  1507,   406,   408,   410,
     404,     3,   416,   418,  1661,    10,    11,  1650,   228,   229,
    1453,  1454,  1653,  1507,  1656,  1646,  1659,  1646,  1665,  1646,
    1668,  1646,  1671,  1646,  1674,  1646,  1677,  1507,  1416,  1417,
    1139,  1412,   250,  1437,   148,  1153,  1154,   278,   278,   278,
     148,  1279,  1280,   148,   278,  1305,  1306,   148,   278,  1323,
    1324,   278,   148,   278,  1354,  1355,   148,   278,  1372,  1373,
     148,  1163,  1164,   278,   358,   360,   362,   364,  1507,   386,
    1507,     8,     8,   402,  1557,  1662,   450,     8,     8,  1507,
    1646,  1646,   448,   444,  1646,   454,  1581,    10,    11,  1419,
    1420,  1421,   226,   227,  1418,  1443,  1444,  1489,  1492,   252,
      10,    11,  1158,  1159,  1160,  1155,  1448,  1281,  1282,    10,
      11,  1307,  1308,  1309,    10,    11,  1325,  1326,  1327,  1356,
    1374,  1165,  1448,   378,  1561,     6,  1106,     8,   456,  1646,
    1106,  1106,   460,   452,   446,   458,   434,  1218,     8,     8,
       4,   157,    10,  1156,    10,    11,  1284,  1285,  1286,   214,
     238,  1283,  1435,  1452,  1507,  1647,    10,   179,   180,  1357,
    1358,  1446,  1448,  1501,  1502,  1503,    10,    11,  1375,  1376,
    1448,  1453,  1454,    10,  1166,   386,     8,     8,     8,     8,
     248,     6,     6,   157,  1106,  1287,     8,     8,   149,   149,
       6,     3,   149,     4,     8,     8,   149,   149,   279,  1288,
    1289,     6,  1106,   149,     8,   149,   237,  1290,  1451,     8,
       8,     8,    10,  1291,  1106,     6,     8,   280
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
                = std::complex<double>(osglData->realPart,osglData->imagPart); 
        }
        osglData->nonzeroCounter += osglData->mult;
    }
}
    break;

  case 1386:

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

  case 1771:

    {
}
    break;

  case 1772:

    {
    osglData->realPartPresent = false;
    osglData->imagPartPresent = false;
    osnlData->nlNodePoint = new OSnLCNodeNumber();
    osnlData->nlNodeVec.push_back(osnlData->nlNodePoint);
}
    break;

  case 1775:

    {
    osnlData->nlCNodeComplexNumber->setValue(osnlData->Re, osnlData->Im);
}
    break;

  case 1781:

    {
    osnlData->nlNodePoint = new OSnLCNodeCreate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1784:

    {
    osnlData->nlNodePoint = new OSnLCNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1786:

    {
    osnlData->nlNodePoint = new OSnLCNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->cSumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1787:

    {
    osnlData->cSumVec.back()->m_mChildren = new ExprNode*[ osnlData->cSumVec.back()->inumberOfChildren];
    osnlData->cSumVec.pop_back();
}
    break;

  case 1789:

    { 
    osnlData->cSumVec.back()->inumberOfChildren++; 
}
    break;

  case 1791:

    {
    osnlData->nlNodePoint = new OSnLCNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1794:

    {
    osnlData->nlNodePoint = new OSnLCNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1797:

    {
    osnlData->nlNodePoint = new OSnLCNodeConjugate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1800:

    {
    osnlData->nlNodePoint = new OSnLCNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1803:

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


