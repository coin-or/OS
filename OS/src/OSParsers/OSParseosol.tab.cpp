
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
#define yyparse         osolparse
#define yylex           osollex
#define yyerror         osolerror
#define yylval          osollval
#define yychar          osolchar
#define yydebug         osoldebug
#define yynerrs         osolnerrs
#define yylloc          osollloc

/* Copy the first part of user declarations.  */




#include "OSConfig.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include "OSgLParserData.h"
#include "OSnLParserData.h"
#include "OSBase64.h"

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

#define OSOPTION_AVAILABLE

//#define DEBUG

#ifdef DEBUG
#define YYDEBUG 1
#endif

// This declaration produces *loads* of output
#ifdef YYDEBUG
    extern int osildebug;
    osildebug = 1;
#endif


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osol_scan_string (const char *yy_str , void* yyscanner  );
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* yyscanner );
int osolget_lineno( void* yyscanner);
char *osolget_text (void* yyscanner );
void osolset_lineno (int line_number , void* yyscanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );
void  yygetOSOption(const char *ch, OSOption* m_osoption, OSoLParserData *m_parserData, OSgLParserData *osglData, OSnLParserData *osnlData ) throw(ErrorClass);
void osol_empty_vectors( OSoLParserData* parserData);
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
     OSOLSTART = 268,
     OSOLSTARTEMPTY = 269,
     OSOLATTRIBUTETEXT = 270,
     OSOLEND = 271,
     EMPTYLBVALUEATT = 272,
     EMPTYUBVALUEATT = 273,
     LBVALUEATT = 274,
     UBVALUEATT = 275,
     EMPTYLBDUALVALUEATT = 276,
     EMPTYUBDUALVALUEATT = 277,
     LBDUALVALUEATT = 278,
     UBDUALVALUEATT = 279,
     WEIGHTATT = 280,
     EMPTYWEIGHTATT = 281,
     TRANSPORTTYPEATT = 282,
     LOCATIONTYPEATT = 283,
     FROMATT = 284,
     TOATT = 285,
     MAKECOPYATT = 286,
     NUMBEROFJOBIDSATT = 287,
     NUMBEROFPATHSATT = 288,
     NUMBEROFPATHPAIRSATT = 289,
     NUMBEROFPROCESSESATT = 290,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 291,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 292,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 293,
     NUMBEROFSOLVEROPTIONSATT = 294,
     NUMBEROFOTHEROPTIONSATT = 295,
     NUMBEROFSOSATT = 296,
     SOSIDXATT = 297,
     GROUPWEIGHTATT = 298,
     INSTANCELOCATIONSTART = 299,
     INSTANCELOCATIONEND = 300,
     SOLVERTOINVOKESTART = 301,
     SOLVERTOINVOKEEND = 302,
     LICENSESTART = 303,
     LICENSEEND = 304,
     USERNAMESTART = 305,
     USERNAMEEND = 306,
     PASSWORDSTART = 307,
     PASSWORDEND = 308,
     CONTACTSTART = 309,
     CONTACTEND = 310,
     MINDISKSPACESTART = 311,
     MINDISKSPACEEND = 312,
     MINMEMORYSTART = 313,
     MINMEMORYEND = 314,
     MINCPUSPEEDSTART = 315,
     MINCPUSPEEDEND = 316,
     MINCPUNUMBERSTART = 317,
     MINCPUNUMBEREND = 318,
     SERVICETYPESTART = 319,
     SERVICETYPEEND = 320,
     MAXTIMESTART = 321,
     MAXTIMEEND = 322,
     REQUESTEDSTARTTIMESTART = 323,
     REQUESTEDSTARTTIMEEND = 324,
     DEPENDENCIESSTART = 325,
     DEPENDENCIESEND = 326,
     PATHSTART = 327,
     PATHEND = 328,
     PATHPAIRSTART = 329,
     PATHPAIREND = 330,
     REQUIREDDIRECTORIESSTART = 331,
     REQUIREDDIRECTORIESEND = 332,
     REQUIREDFILESSTART = 333,
     REQUIREDFILESEND = 334,
     DIRECTORIESTOMAKESTART = 335,
     DIRECTORIESTOMAKEEND = 336,
     FILESTOMAKESTART = 337,
     FILESTOMAKEEND = 338,
     DIRECTORIESTODELETESTART = 339,
     DIRECTORIESTODELETEEND = 340,
     FILESTODELETESTART = 341,
     FILESTODELETEEND = 342,
     INPUTDIRECTORIESTOMOVESTART = 343,
     INPUTDIRECTORIESTOMOVEEND = 344,
     INPUTFILESTOMOVESTART = 345,
     INPUTFILESTOMOVEEND = 346,
     OUTPUTDIRECTORIESTOMOVESTART = 347,
     OUTPUTDIRECTORIESTOMOVEEND = 348,
     OUTPUTFILESTOMOVESTART = 349,
     OUTPUTFILESTOMOVEEND = 350,
     PROCESSESTOKILLSTART = 351,
     PROCESSESTOKILLEND = 352,
     PROCESSSTART = 353,
     PROCESSEND = 354,
     INITIALVARIABLEVALUESSTART = 355,
     INITIALVARIABLEVALUESEND = 356,
     INITIALVARIABLEVALUESSTRINGSTART = 357,
     INITIALVARIABLEVALUESSTRINGEND = 358,
     INITIALBASISSTATUSSTART = 359,
     INITIALBASISSTATUSEND = 360,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 361,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 362,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 363,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 364,
     SOSSTART = 365,
     SOSEND = 366,
     INITIALOBJECTIVEVALUESSTART = 367,
     INITIALOBJECTIVEVALUESEND = 368,
     INITIALOBJECTIVEBOUNDSSTART = 369,
     INITIALOBJECTIVEBOUNDSEND = 370,
     INITIALCONSTRAINTVALUESSTART = 371,
     INITIALCONSTRAINTVALUESEND = 372,
     INITIALDUALVALUESSTART = 373,
     INITIALDUALVALUESEND = 374,
     SOLVEROPTIONSSTART = 375,
     SOLVEROPTIONSEND = 376,
     SOLVEROPTIONSTART = 377,
     SOLVEROPTIONEND = 378,
     OTHEROPTIONSSTART = 379,
     OTHEROPTIONSEND = 380,
     HEADERSTART = 381,
     HEADEREND = 382,
     FILENAMESTART = 383,
     FILENAMEEND = 384,
     FILENAMEEMPTY = 385,
     FILENAMESTARTANDEND = 386,
     FILESOURCESTART = 387,
     FILESOURCEEND = 388,
     FILESOURCEEMPTY = 389,
     FILESOURCESTARTANDEND = 390,
     FILEDESCRIPTIONSTART = 391,
     FILEDESCRIPTIONEND = 392,
     FILEDESCRIPTIONEMPTY = 393,
     FILEDESCRIPTIONSTARTANDEND = 394,
     FILECREATORSTART = 395,
     FILECREATOREND = 396,
     FILECREATOREMPTY = 397,
     FILECREATORSTARTANDEND = 398,
     FILELICENCESTART = 399,
     FILELICENCEEND = 400,
     FILELICENCEEMPTY = 401,
     FILELICENCESTARTANDEND = 402,
     INDEXESSTART = 403,
     INDEXESEND = 404,
     VALUESSTART = 405,
     VALUESEND = 406,
     NONZEROSSTART = 407,
     NONZEROSEND = 408,
     ELSTART = 409,
     ELEND = 410,
     ENUMERATIONSTART = 411,
     ENUMERATIONEND = 412,
     ITEMEMPTY = 413,
     ITEMSTART = 414,
     ITEMEND = 415,
     ITEMSTARTANDEND = 416,
     BASE64START = 417,
     BASE64END = 418,
     NUMBEROFELATT = 419,
     NUMBEROFENUMERATIONSATT = 420,
     NUMBEROFITEMSATT = 421,
     EMPTYCATEGORYATT = 422,
     CATEGORYATT = 423,
     EMPTYDESCRIPTIONATT = 424,
     DESCRIPTIONATT = 425,
     EMPTYSOLVERATT = 426,
     SOLVERATT = 427,
     EMPTYNAMEATT = 428,
     NAMEATT = 429,
     EMPTYTYPEATT = 430,
     TYPEATT = 431,
     EMPTYENUMTYPEATT = 432,
     ENUMTYPEATT = 433,
     EMPTYSHAPEATT = 434,
     SHAPEATT = 435,
     EMPTYUNITATT = 436,
     UNITATT = 437,
     EMPTYVALUEATT = 438,
     VALUEATT = 439,
     EMPTYVALUETYPEATT = 440,
     VALUETYPEATT = 441,
     EMPTYCONTYPEATT = 442,
     CONTYPEATT = 443,
     EMPTYOBJTYPEATT = 444,
     OBJTYPEATT = 445,
     EMPTYVARTYPEATT = 446,
     VARTYPEATT = 447,
     EMPTYMATRIXCONTYPEATT = 448,
     MATRIXCONTYPEATT = 449,
     EMPTYMATRIXOBJTYPEATT = 450,
     MATRIXOBJTYPEATT = 451,
     EMPTYMATRIXVARTYPEATT = 452,
     MATRIXVARTYPEATT = 453,
     EMPTYMATRIXTYPEATT = 454,
     MATRIXTYPEATT = 455,
     EMPTYSYMMETRYATT = 456,
     SYMMETRYATT = 457,
     EMPTYROWMAJORATT = 458,
     ROWMAJORATT = 459,
     EMPTYBASETRANSPOSEATT = 460,
     BASETRANSPOSEATT = 461,
     NUMBEROFBLOCKSATT = 462,
     NUMBEROFCOLUMNSATT = 463,
     NUMBEROFROWSATT = 464,
     NUMBEROFMATRICESATT = 465,
     NUMBEROFVALUESATT = 466,
     NUMBEROFCONSTRAINTSATT = 467,
     NUMBEROFCONATT = 468,
     NUMBEROFCONIDXATT = 469,
     NUMBEROFOBJECTIVESATT = 470,
     NUMBEROFOBJATT = 471,
     NUMBEROFOBJIDXATT = 472,
     NUMBEROFVARIABLESATT = 473,
     NUMBEROFVARATT = 474,
     NUMBEROFVARIDXATT = 475,
     NUMBEROFMATRIXCONATT = 476,
     NUMBEROFMATRIXOBJATT = 477,
     NUMBEROFMATRIXVARATT = 478,
     BASEMATRIXIDXATT = 479,
     TARGETMATRIXFIRSTROWATT = 480,
     TARGETMATRIXFIRSTCOLATT = 481,
     BASEMATRIXSTARTROWATT = 482,
     BASEMATRIXSTARTCOLATT = 483,
     BASEMATRIXENDROWATT = 484,
     BASEMATRIXENDCOLATT = 485,
     SCALARMULTIPLIERATT = 486,
     BLOCKROWIDXATT = 487,
     BLOCKCOLIDXATT = 488,
     REATT = 489,
     IMATT = 490,
     MATRIXVARIDXATT = 491,
     MATRIXOBJIDXATT = 492,
     MATRIXCONIDXATT = 493,
     IDXATT = 494,
     INCRATT = 495,
     MULTATT = 496,
     SIZEOFATT = 497,
     COEFATT = 498,
     CONSTANTATT = 499,
     MATRICESSTART = 500,
     MATRICESEND = 501,
     MATRIXSTART = 502,
     MATRIXEND = 503,
     BASEMATRIXEND = 504,
     BASEMATRIXSTART = 505,
     BLOCKSSTART = 506,
     BLOCKSEND = 507,
     BLOCKSTART = 508,
     BLOCKEND = 509,
     COLOFFSETSTART = 510,
     COLOFFSETEND = 511,
     ROWOFFSETSTART = 512,
     ROWOFFSETEND = 513,
     ELEMENTSSTART = 514,
     ELEMENTSEND = 515,
     CONSTANTELEMENTSSTART = 516,
     CONSTANTELEMENTSEND = 517,
     COMPLEXELEMENTSSTART = 518,
     COMPLEXELEMENTSEND = 519,
     VARREFERENCEELEMENTSSTART = 520,
     VARREFERENCEELEMENTSEND = 521,
     LINEARELEMENTSSTART = 522,
     LINEARELEMENTSEND = 523,
     CONREFERENCEELEMENTSSTART = 524,
     CONREFERENCEELEMENTSEND = 525,
     OBJREFERENCEELEMENTSSTART = 526,
     OBJREFERENCEELEMENTSEND = 527,
     REALVALUEDEXPRESSIONSSTART = 528,
     REALVALUEDEXPRESSIONSSEND = 529,
     COMPLEXVALUEDEXPRESSIONSSTART = 530,
     COMPLEXVALUEDEXPRESSIONSSEND = 531,
     STRINGVALUEDELEMENTSSTART = 532,
     STRINGVALUEDELEMENTSEND = 533,
     STARTVECTORSTART = 534,
     STARTVECTOREND = 535,
     INDEXSTART = 536,
     INDEXEND = 537,
     VALUESTART = 538,
     VALUEEND = 539,
     VARIDXSTART = 540,
     VARIDXEND = 541,
     TRANSFORMATIONSTART = 542,
     TRANSFORMATIONEND = 543,
     MATRIXPROGRAMMINGSTART = 544,
     MATRIXPROGRAMMINGEND = 545,
     MATRIXVARIABLESSTART = 546,
     MATRIXVARIABLESEND = 547,
     MATRIXVARSTART = 548,
     MATRIXVAREND = 549,
     MATRIXOBJECTIVESSTART = 550,
     MATRIXOBJECTIVESEND = 551,
     MATRIXOBJSTART = 552,
     MATRIXOBJEND = 553,
     MATRIXCONSTRAINTSSTART = 554,
     MATRIXCONSTRAINTSEND = 555,
     MATRIXCONSTART = 556,
     MATRIXCONEND = 557,
     CONSTART = 558,
     CONEND = 559,
     CONSTRAINTSSTART = 560,
     CONSTRAINTSEND = 561,
     OBJSTART = 562,
     OBJEND = 563,
     OBJECTIVESSTART = 564,
     OBJECTIVESEND = 565,
     VARSTART = 566,
     VAREND = 567,
     VARIABLESSTART = 568,
     VARIABLESEND = 569,
     GENERALSTART = 570,
     GENERALEND = 571,
     SYSTEMSTART = 572,
     SYSTEMEND = 573,
     SERVICESTART = 574,
     SERVICEEND = 575,
     JOBSTART = 576,
     JOBEND = 577,
     OPTIMIZATIONSTART = 578,
     OPTIMIZATIONEND = 579,
     ATEQUALITYSTART = 580,
     ATEQUALITYEND = 581,
     ATLOWERSTART = 582,
     ATLOWEREND = 583,
     ATUPPERSTART = 584,
     ATUPPEREND = 585,
     BASICSTART = 586,
     BASICEND = 587,
     ISFREESTART = 588,
     ISFREEEND = 589,
     SUPERBASICSTART = 590,
     SUPERBASICEND = 591,
     UNKNOWNSTART = 592,
     UNKNOWNEND = 593,
     SERVICEURISTART = 594,
     SERVICEURIEND = 595,
     SERVICENAMESTART = 596,
     SERVICENAMEEND = 597,
     INSTANCENAMESTART = 598,
     INSTANCENAMEEND = 599,
     JOBIDSTART = 600,
     JOBIDEND = 601,
     OTHERSTART = 602,
     OTHEREND = 603,
     DUMMY = 604,
     NONLINEAREXPRESSIONSSTART = 605,
     NONLINEAREXPRESSIONSEND = 606,
     NUMBEROFNONLINEAREXPRESSIONS = 607,
     NLSTART = 608,
     NLEND = 609,
     MATRIXEXPRESSIONSSTART = 610,
     MATRIXEXPRESSIONSEND = 611,
     NUMBEROFEXPR = 612,
     EXPRSTART = 613,
     EXPREND = 614,
     NUMBEROFMATRIXTERMSATT = 615,
     MATRIXTERMSTART = 616,
     MATRIXTERMEND = 617,
     POWERSTART = 618,
     POWEREND = 619,
     PLUSSTART = 620,
     PLUSEND = 621,
     MINUSSTART = 622,
     MINUSEND = 623,
     DIVIDESTART = 624,
     DIVIDEEND = 625,
     LNSTART = 626,
     LNEND = 627,
     SQRTSTART = 628,
     SQRTEND = 629,
     SUMSTART = 630,
     SUMEND = 631,
     PRODUCTSTART = 632,
     PRODUCTEND = 633,
     EXPSTART = 634,
     EXPEND = 635,
     NEGATESTART = 636,
     NEGATEEND = 637,
     IFSTART = 638,
     IFEND = 639,
     SQUARESTART = 640,
     SQUAREEND = 641,
     COSSTART = 642,
     COSEND = 643,
     SINSTART = 644,
     SINEND = 645,
     VARIABLESTART = 646,
     VARIABLEEND = 647,
     ABSSTART = 648,
     ABSEND = 649,
     ERFSTART = 650,
     ERFEND = 651,
     MAXSTART = 652,
     MAXEND = 653,
     ALLDIFFSTART = 654,
     ALLDIFFEND = 655,
     MINSTART = 656,
     MINEND = 657,
     ESTART = 658,
     EEND = 659,
     PISTART = 660,
     PIEND = 661,
     TIMESSTART = 662,
     TIMESEND = 663,
     NUMBERSTART = 664,
     NUMBEREND = 665,
     MATRIXDETERMINANTSTART = 666,
     MATRIXDETERMINANTEND = 667,
     MATRIXTRACESTART = 668,
     MATRIXTRACEEND = 669,
     MATRIXTOSCALARSTART = 670,
     MATRIXTOSCALAREND = 671,
     MATRIXDIAGONALSTART = 672,
     MATRIXDIAGONALEND = 673,
     MATRIXDOTTIMESSTART = 674,
     MATRIXDOTTIMESEND = 675,
     MATRIXLOWERTRIANGLESTART = 676,
     MATRIXLOWERTRIANGLEEND = 677,
     MATRIXUPPERTRIANGLESTART = 678,
     MATRIXUPPERTRIANGLEEND = 679,
     MATRIXMERGESTART = 680,
     MATRIXMERGEEND = 681,
     MATRIXMINUSSTART = 682,
     MATRIXMINUSEND = 683,
     MATRIXNEGATESTART = 684,
     MATRIXNEGATEEND = 685,
     MATRIXPLUSSTART = 686,
     MATRIXPLUSEND = 687,
     MATRIXTIMESSTART = 688,
     MATRIXTIMESEND = 689,
     MATRIXPRODUCTSTART = 690,
     MATRIXPRODUCTEND = 691,
     MATRIXSCALARTIMESSTART = 692,
     MATRIXSCALARTIMESEND = 693,
     MATRIXSUBMATRIXATSTART = 694,
     MATRIXSUBMATRIXATEND = 695,
     MATRIXTRANSPOSESTART = 696,
     MATRIXTRANSPOSEEND = 697,
     MATRIXREFERENCESTART = 698,
     MATRIXREFERENCEEND = 699,
     IDENTITYMATRIXSTART = 700,
     IDENTITYMATRIXEND = 701,
     MATRIXINVERSESTART = 702,
     MATRIXINVERSEEND = 703,
     COMPLEXCONJUGATESTART = 704,
     COMPLEXCONJUGATEEND = 705,
     COMPLEXMINUSSTART = 706,
     COMPLEXMINUSEND = 707,
     COMPLEXNEGATESTART = 708,
     COMPLEXNEGATEEND = 709,
     COMPLEXNUMBERSTART = 710,
     COMPLEXNUMBEREND = 711,
     COMPLEXPLUSSTART = 712,
     COMPLEXPLUSEND = 713,
     COMPLEXSQUARESTART = 714,
     COMPLEXSQUAREEND = 715,
     COMPLEXSUMSTART = 716,
     COMPLEXSUMEND = 717,
     COMPLEXTIMESSTART = 718,
     COMPLEXTIMESEND = 719,
     CREATECOMPLEXSTART = 720,
     CREATECOMPLEXEND = 721,
     EMPTYINCLUDEDIAGONALATT = 722,
     INCLUDEDIAGONALATT = 723,
     EMPTYTRANSPOSEATT = 724,
     TRANSPOSEATT = 725,
     EMPTYIDATT = 726,
     IDATT = 727
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
#define OSOLSTART 268
#define OSOLSTARTEMPTY 269
#define OSOLATTRIBUTETEXT 270
#define OSOLEND 271
#define EMPTYLBVALUEATT 272
#define EMPTYUBVALUEATT 273
#define LBVALUEATT 274
#define UBVALUEATT 275
#define EMPTYLBDUALVALUEATT 276
#define EMPTYUBDUALVALUEATT 277
#define LBDUALVALUEATT 278
#define UBDUALVALUEATT 279
#define WEIGHTATT 280
#define EMPTYWEIGHTATT 281
#define TRANSPORTTYPEATT 282
#define LOCATIONTYPEATT 283
#define FROMATT 284
#define TOATT 285
#define MAKECOPYATT 286
#define NUMBEROFJOBIDSATT 287
#define NUMBEROFPATHSATT 288
#define NUMBEROFPATHPAIRSATT 289
#define NUMBEROFPROCESSESATT 290
#define NUMBEROFOTHERVARIABLEOPTIONSATT 291
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 292
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 293
#define NUMBEROFSOLVEROPTIONSATT 294
#define NUMBEROFOTHEROPTIONSATT 295
#define NUMBEROFSOSATT 296
#define SOSIDXATT 297
#define GROUPWEIGHTATT 298
#define INSTANCELOCATIONSTART 299
#define INSTANCELOCATIONEND 300
#define SOLVERTOINVOKESTART 301
#define SOLVERTOINVOKEEND 302
#define LICENSESTART 303
#define LICENSEEND 304
#define USERNAMESTART 305
#define USERNAMEEND 306
#define PASSWORDSTART 307
#define PASSWORDEND 308
#define CONTACTSTART 309
#define CONTACTEND 310
#define MINDISKSPACESTART 311
#define MINDISKSPACEEND 312
#define MINMEMORYSTART 313
#define MINMEMORYEND 314
#define MINCPUSPEEDSTART 315
#define MINCPUSPEEDEND 316
#define MINCPUNUMBERSTART 317
#define MINCPUNUMBEREND 318
#define SERVICETYPESTART 319
#define SERVICETYPEEND 320
#define MAXTIMESTART 321
#define MAXTIMEEND 322
#define REQUESTEDSTARTTIMESTART 323
#define REQUESTEDSTARTTIMEEND 324
#define DEPENDENCIESSTART 325
#define DEPENDENCIESEND 326
#define PATHSTART 327
#define PATHEND 328
#define PATHPAIRSTART 329
#define PATHPAIREND 330
#define REQUIREDDIRECTORIESSTART 331
#define REQUIREDDIRECTORIESEND 332
#define REQUIREDFILESSTART 333
#define REQUIREDFILESEND 334
#define DIRECTORIESTOMAKESTART 335
#define DIRECTORIESTOMAKEEND 336
#define FILESTOMAKESTART 337
#define FILESTOMAKEEND 338
#define DIRECTORIESTODELETESTART 339
#define DIRECTORIESTODELETEEND 340
#define FILESTODELETESTART 341
#define FILESTODELETEEND 342
#define INPUTDIRECTORIESTOMOVESTART 343
#define INPUTDIRECTORIESTOMOVEEND 344
#define INPUTFILESTOMOVESTART 345
#define INPUTFILESTOMOVEEND 346
#define OUTPUTDIRECTORIESTOMOVESTART 347
#define OUTPUTDIRECTORIESTOMOVEEND 348
#define OUTPUTFILESTOMOVESTART 349
#define OUTPUTFILESTOMOVEEND 350
#define PROCESSESTOKILLSTART 351
#define PROCESSESTOKILLEND 352
#define PROCESSSTART 353
#define PROCESSEND 354
#define INITIALVARIABLEVALUESSTART 355
#define INITIALVARIABLEVALUESEND 356
#define INITIALVARIABLEVALUESSTRINGSTART 357
#define INITIALVARIABLEVALUESSTRINGEND 358
#define INITIALBASISSTATUSSTART 359
#define INITIALBASISSTATUSEND 360
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 361
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 362
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 363
#define SOSVARIABLEBRANCHINGWEIGHTSEND 364
#define SOSSTART 365
#define SOSEND 366
#define INITIALOBJECTIVEVALUESSTART 367
#define INITIALOBJECTIVEVALUESEND 368
#define INITIALOBJECTIVEBOUNDSSTART 369
#define INITIALOBJECTIVEBOUNDSEND 370
#define INITIALCONSTRAINTVALUESSTART 371
#define INITIALCONSTRAINTVALUESEND 372
#define INITIALDUALVALUESSTART 373
#define INITIALDUALVALUESEND 374
#define SOLVEROPTIONSSTART 375
#define SOLVEROPTIONSEND 376
#define SOLVEROPTIONSTART 377
#define SOLVEROPTIONEND 378
#define OTHEROPTIONSSTART 379
#define OTHEROPTIONSEND 380
#define HEADERSTART 381
#define HEADEREND 382
#define FILENAMESTART 383
#define FILENAMEEND 384
#define FILENAMEEMPTY 385
#define FILENAMESTARTANDEND 386
#define FILESOURCESTART 387
#define FILESOURCEEND 388
#define FILESOURCEEMPTY 389
#define FILESOURCESTARTANDEND 390
#define FILEDESCRIPTIONSTART 391
#define FILEDESCRIPTIONEND 392
#define FILEDESCRIPTIONEMPTY 393
#define FILEDESCRIPTIONSTARTANDEND 394
#define FILECREATORSTART 395
#define FILECREATOREND 396
#define FILECREATOREMPTY 397
#define FILECREATORSTARTANDEND 398
#define FILELICENCESTART 399
#define FILELICENCEEND 400
#define FILELICENCEEMPTY 401
#define FILELICENCESTARTANDEND 402
#define INDEXESSTART 403
#define INDEXESEND 404
#define VALUESSTART 405
#define VALUESEND 406
#define NONZEROSSTART 407
#define NONZEROSEND 408
#define ELSTART 409
#define ELEND 410
#define ENUMERATIONSTART 411
#define ENUMERATIONEND 412
#define ITEMEMPTY 413
#define ITEMSTART 414
#define ITEMEND 415
#define ITEMSTARTANDEND 416
#define BASE64START 417
#define BASE64END 418
#define NUMBEROFELATT 419
#define NUMBEROFENUMERATIONSATT 420
#define NUMBEROFITEMSATT 421
#define EMPTYCATEGORYATT 422
#define CATEGORYATT 423
#define EMPTYDESCRIPTIONATT 424
#define DESCRIPTIONATT 425
#define EMPTYSOLVERATT 426
#define SOLVERATT 427
#define EMPTYNAMEATT 428
#define NAMEATT 429
#define EMPTYTYPEATT 430
#define TYPEATT 431
#define EMPTYENUMTYPEATT 432
#define ENUMTYPEATT 433
#define EMPTYSHAPEATT 434
#define SHAPEATT 435
#define EMPTYUNITATT 436
#define UNITATT 437
#define EMPTYVALUEATT 438
#define VALUEATT 439
#define EMPTYVALUETYPEATT 440
#define VALUETYPEATT 441
#define EMPTYCONTYPEATT 442
#define CONTYPEATT 443
#define EMPTYOBJTYPEATT 444
#define OBJTYPEATT 445
#define EMPTYVARTYPEATT 446
#define VARTYPEATT 447
#define EMPTYMATRIXCONTYPEATT 448
#define MATRIXCONTYPEATT 449
#define EMPTYMATRIXOBJTYPEATT 450
#define MATRIXOBJTYPEATT 451
#define EMPTYMATRIXVARTYPEATT 452
#define MATRIXVARTYPEATT 453
#define EMPTYMATRIXTYPEATT 454
#define MATRIXTYPEATT 455
#define EMPTYSYMMETRYATT 456
#define SYMMETRYATT 457
#define EMPTYROWMAJORATT 458
#define ROWMAJORATT 459
#define EMPTYBASETRANSPOSEATT 460
#define BASETRANSPOSEATT 461
#define NUMBEROFBLOCKSATT 462
#define NUMBEROFCOLUMNSATT 463
#define NUMBEROFROWSATT 464
#define NUMBEROFMATRICESATT 465
#define NUMBEROFVALUESATT 466
#define NUMBEROFCONSTRAINTSATT 467
#define NUMBEROFCONATT 468
#define NUMBEROFCONIDXATT 469
#define NUMBEROFOBJECTIVESATT 470
#define NUMBEROFOBJATT 471
#define NUMBEROFOBJIDXATT 472
#define NUMBEROFVARIABLESATT 473
#define NUMBEROFVARATT 474
#define NUMBEROFVARIDXATT 475
#define NUMBEROFMATRIXCONATT 476
#define NUMBEROFMATRIXOBJATT 477
#define NUMBEROFMATRIXVARATT 478
#define BASEMATRIXIDXATT 479
#define TARGETMATRIXFIRSTROWATT 480
#define TARGETMATRIXFIRSTCOLATT 481
#define BASEMATRIXSTARTROWATT 482
#define BASEMATRIXSTARTCOLATT 483
#define BASEMATRIXENDROWATT 484
#define BASEMATRIXENDCOLATT 485
#define SCALARMULTIPLIERATT 486
#define BLOCKROWIDXATT 487
#define BLOCKCOLIDXATT 488
#define REATT 489
#define IMATT 490
#define MATRIXVARIDXATT 491
#define MATRIXOBJIDXATT 492
#define MATRIXCONIDXATT 493
#define IDXATT 494
#define INCRATT 495
#define MULTATT 496
#define SIZEOFATT 497
#define COEFATT 498
#define CONSTANTATT 499
#define MATRICESSTART 500
#define MATRICESEND 501
#define MATRIXSTART 502
#define MATRIXEND 503
#define BASEMATRIXEND 504
#define BASEMATRIXSTART 505
#define BLOCKSSTART 506
#define BLOCKSEND 507
#define BLOCKSTART 508
#define BLOCKEND 509
#define COLOFFSETSTART 510
#define COLOFFSETEND 511
#define ROWOFFSETSTART 512
#define ROWOFFSETEND 513
#define ELEMENTSSTART 514
#define ELEMENTSEND 515
#define CONSTANTELEMENTSSTART 516
#define CONSTANTELEMENTSEND 517
#define COMPLEXELEMENTSSTART 518
#define COMPLEXELEMENTSEND 519
#define VARREFERENCEELEMENTSSTART 520
#define VARREFERENCEELEMENTSEND 521
#define LINEARELEMENTSSTART 522
#define LINEARELEMENTSEND 523
#define CONREFERENCEELEMENTSSTART 524
#define CONREFERENCEELEMENTSEND 525
#define OBJREFERENCEELEMENTSSTART 526
#define OBJREFERENCEELEMENTSEND 527
#define REALVALUEDEXPRESSIONSSTART 528
#define REALVALUEDEXPRESSIONSSEND 529
#define COMPLEXVALUEDEXPRESSIONSSTART 530
#define COMPLEXVALUEDEXPRESSIONSSEND 531
#define STRINGVALUEDELEMENTSSTART 532
#define STRINGVALUEDELEMENTSEND 533
#define STARTVECTORSTART 534
#define STARTVECTOREND 535
#define INDEXSTART 536
#define INDEXEND 537
#define VALUESTART 538
#define VALUEEND 539
#define VARIDXSTART 540
#define VARIDXEND 541
#define TRANSFORMATIONSTART 542
#define TRANSFORMATIONEND 543
#define MATRIXPROGRAMMINGSTART 544
#define MATRIXPROGRAMMINGEND 545
#define MATRIXVARIABLESSTART 546
#define MATRIXVARIABLESEND 547
#define MATRIXVARSTART 548
#define MATRIXVAREND 549
#define MATRIXOBJECTIVESSTART 550
#define MATRIXOBJECTIVESEND 551
#define MATRIXOBJSTART 552
#define MATRIXOBJEND 553
#define MATRIXCONSTRAINTSSTART 554
#define MATRIXCONSTRAINTSEND 555
#define MATRIXCONSTART 556
#define MATRIXCONEND 557
#define CONSTART 558
#define CONEND 559
#define CONSTRAINTSSTART 560
#define CONSTRAINTSEND 561
#define OBJSTART 562
#define OBJEND 563
#define OBJECTIVESSTART 564
#define OBJECTIVESEND 565
#define VARSTART 566
#define VAREND 567
#define VARIABLESSTART 568
#define VARIABLESEND 569
#define GENERALSTART 570
#define GENERALEND 571
#define SYSTEMSTART 572
#define SYSTEMEND 573
#define SERVICESTART 574
#define SERVICEEND 575
#define JOBSTART 576
#define JOBEND 577
#define OPTIMIZATIONSTART 578
#define OPTIMIZATIONEND 579
#define ATEQUALITYSTART 580
#define ATEQUALITYEND 581
#define ATLOWERSTART 582
#define ATLOWEREND 583
#define ATUPPERSTART 584
#define ATUPPEREND 585
#define BASICSTART 586
#define BASICEND 587
#define ISFREESTART 588
#define ISFREEEND 589
#define SUPERBASICSTART 590
#define SUPERBASICEND 591
#define UNKNOWNSTART 592
#define UNKNOWNEND 593
#define SERVICEURISTART 594
#define SERVICEURIEND 595
#define SERVICENAMESTART 596
#define SERVICENAMEEND 597
#define INSTANCENAMESTART 598
#define INSTANCENAMEEND 599
#define JOBIDSTART 600
#define JOBIDEND 601
#define OTHERSTART 602
#define OTHEREND 603
#define DUMMY 604
#define NONLINEAREXPRESSIONSSTART 605
#define NONLINEAREXPRESSIONSEND 606
#define NUMBEROFNONLINEAREXPRESSIONS 607
#define NLSTART 608
#define NLEND 609
#define MATRIXEXPRESSIONSSTART 610
#define MATRIXEXPRESSIONSEND 611
#define NUMBEROFEXPR 612
#define EXPRSTART 613
#define EXPREND 614
#define NUMBEROFMATRIXTERMSATT 615
#define MATRIXTERMSTART 616
#define MATRIXTERMEND 617
#define POWERSTART 618
#define POWEREND 619
#define PLUSSTART 620
#define PLUSEND 621
#define MINUSSTART 622
#define MINUSEND 623
#define DIVIDESTART 624
#define DIVIDEEND 625
#define LNSTART 626
#define LNEND 627
#define SQRTSTART 628
#define SQRTEND 629
#define SUMSTART 630
#define SUMEND 631
#define PRODUCTSTART 632
#define PRODUCTEND 633
#define EXPSTART 634
#define EXPEND 635
#define NEGATESTART 636
#define NEGATEEND 637
#define IFSTART 638
#define IFEND 639
#define SQUARESTART 640
#define SQUAREEND 641
#define COSSTART 642
#define COSEND 643
#define SINSTART 644
#define SINEND 645
#define VARIABLESTART 646
#define VARIABLEEND 647
#define ABSSTART 648
#define ABSEND 649
#define ERFSTART 650
#define ERFEND 651
#define MAXSTART 652
#define MAXEND 653
#define ALLDIFFSTART 654
#define ALLDIFFEND 655
#define MINSTART 656
#define MINEND 657
#define ESTART 658
#define EEND 659
#define PISTART 660
#define PIEND 661
#define TIMESSTART 662
#define TIMESEND 663
#define NUMBERSTART 664
#define NUMBEREND 665
#define MATRIXDETERMINANTSTART 666
#define MATRIXDETERMINANTEND 667
#define MATRIXTRACESTART 668
#define MATRIXTRACEEND 669
#define MATRIXTOSCALARSTART 670
#define MATRIXTOSCALAREND 671
#define MATRIXDIAGONALSTART 672
#define MATRIXDIAGONALEND 673
#define MATRIXDOTTIMESSTART 674
#define MATRIXDOTTIMESEND 675
#define MATRIXLOWERTRIANGLESTART 676
#define MATRIXLOWERTRIANGLEEND 677
#define MATRIXUPPERTRIANGLESTART 678
#define MATRIXUPPERTRIANGLEEND 679
#define MATRIXMERGESTART 680
#define MATRIXMERGEEND 681
#define MATRIXMINUSSTART 682
#define MATRIXMINUSEND 683
#define MATRIXNEGATESTART 684
#define MATRIXNEGATEEND 685
#define MATRIXPLUSSTART 686
#define MATRIXPLUSEND 687
#define MATRIXTIMESSTART 688
#define MATRIXTIMESEND 689
#define MATRIXPRODUCTSTART 690
#define MATRIXPRODUCTEND 691
#define MATRIXSCALARTIMESSTART 692
#define MATRIXSCALARTIMESEND 693
#define MATRIXSUBMATRIXATSTART 694
#define MATRIXSUBMATRIXATEND 695
#define MATRIXTRANSPOSESTART 696
#define MATRIXTRANSPOSEEND 697
#define MATRIXREFERENCESTART 698
#define MATRIXREFERENCEEND 699
#define IDENTITYMATRIXSTART 700
#define IDENTITYMATRIXEND 701
#define MATRIXINVERSESTART 702
#define MATRIXINVERSEEND 703
#define COMPLEXCONJUGATESTART 704
#define COMPLEXCONJUGATEEND 705
#define COMPLEXMINUSSTART 706
#define COMPLEXMINUSEND 707
#define COMPLEXNEGATESTART 708
#define COMPLEXNEGATEEND 709
#define COMPLEXNUMBERSTART 710
#define COMPLEXNUMBEREND 711
#define COMPLEXPLUSSTART 712
#define COMPLEXPLUSEND 713
#define COMPLEXSQUARESTART 714
#define COMPLEXSQUAREEND 715
#define COMPLEXSUMSTART 716
#define COMPLEXSUMEND 717
#define COMPLEXTIMESSTART 718
#define COMPLEXTIMESEND 719
#define CREATECOMPLEXSTART 720
#define CREATECOMPLEXEND 721
#define EMPTYINCLUDEDIAGONALATT 722
#define INCLUDEDIAGONALATT 723
#define EMPTYTRANSPOSEATT 724
#define TRANSPOSEATT 725
#define EMPTYIDATT 726
#define IDATT 727




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



std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg ) ;
void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg );
int osollex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
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
#define YYLAST   1168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  477
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  720
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1097
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1501

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   727

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   474,
     476,     2,     2,   475,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   473,     2,     2,     2,     2,     2,     2,     2,
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
     465,   466,   467,   468,   469,   470,   471,   472
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    16,    18,    20,
      22,    24,    28,    30,    32,    33,    40,    41,    43,    44,
      47,    49,    51,    53,    56,    58,    62,    64,    66,    69,
      71,    73,    75,    77,    79,    81,    83,    85,    87,    89,
      91,    94,    96,    98,   100,   103,   105,   109,   111,   114,
     116,   118,   120,   123,   125,   129,   131,   134,   136,   138,
     140,   143,   145,   149,   151,   155,   157,   158,   160,   164,
     166,   168,   171,   173,   177,   179,   182,   184,   186,   188,
     191,   193,   197,   199,   202,   204,   206,   208,   211,   213,
     217,   219,   222,   224,   226,   228,   231,   233,   237,   239,
     242,   244,   246,   248,   251,   253,   257,   259,   262,   264,
     266,   268,   271,   273,   277,   279,   283,   285,   286,   288,
     292,   294,   296,   299,   301,   305,   307,   311,   313,   315,
     317,   319,   322,   324,   328,   330,   332,   335,   339,   341,
     343,   344,   347,   349,   351,   353,   356,   358,   359,   362,
     364,   366,   368,   371,   373,   377,   379,   381,   384,   386,
     388,   390,   392,   394,   398,   400,   402,   403,   406,   408,
     410,   414,   416,   420,   422,   424,   425,   428,   430,   432,
     436,   438,   442,   444,   446,   447,   450,   452,   454,   458,
     460,   464,   466,   467,   469,   473,   475,   479,   481,   483,
     485,   487,   490,   492,   496,   498,   500,   503,   507,   508,
     511,   513,   515,   517,   520,   522,   526,   528,   530,   533,
     535,   537,   540,   542,   544,   546,   549,   551,   555,   557,
     561,   563,   565,   567,   569,   572,   574,   578,   580,   582,
     585,   589,   590,   593,   595,   597,   599,   602,   604,   608,
     610,   612,   615,   617,   619,   621,   623,   625,   627,   629,
     631,   633,   635,   637,   639,   641,   643,   645,   649,   651,
     652,   654,   656,   658,   661,   663,   667,   669,   671,   674,
     676,   678,   680,   683,   685,   689,   691,   695,   697,   699,
     701,   703,   706,   708,   712,   714,   717,   722,   726,   728,
     730,   732,   735,   737,   741,   745,   747,   749,   751,   754,
     756,   760,   764,   766,   768,   770,   773,   775,   779,   783,
     785,   787,   789,   792,   794,   798,   802,   804,   806,   808,
     810,   813,   815,   819,   821,   824,   826,   830,   832,   834,
     836,   838,   841,   843,   847,   849,   852,   854,   858,   860,
     862,   864,   866,   869,   871,   875,   877,   880,   882,   886,
     888,   890,   892,   894,   897,   899,   903,   905,   908,   910,
     914,   916,   918,   920,   922,   925,   927,   931,   935,   937,
     939,   941,   943,   946,   948,   952,   956,   958,   960,   962,
     964,   967,   969,   973,   975,   978,   983,   987,   989,   991,
     993,   995,   998,  1000,  1004,  1006,  1008,  1011,  1015,  1016,
    1020,  1022,  1024,  1025,  1028,  1030,  1032,  1034,  1036,  1038,
    1040,  1044,  1049,  1050,  1054,  1056,  1058,  1059,  1061,  1063,
    1065,  1067,  1071,  1078,  1079,  1083,  1085,  1087,  1089,  1091,
    1094,  1096,  1100,  1102,  1104,  1107,  1111,  1113,  1115,  1116,
    1119,  1121,  1123,  1125,  1128,  1130,  1131,  1135,  1137,  1139,
    1141,  1143,  1146,  1148,  1152,  1154,  1156,  1159,  1163,  1165,
    1167,  1168,  1171,  1173,  1175,  1177,  1180,  1182,  1183,  1186,
    1188,  1190,  1192,  1194,  1198,  1206,  1207,  1209,  1210,  1212,
    1213,  1215,  1216,  1218,  1219,  1221,  1222,  1224,  1225,  1227,
    1228,  1232,  1234,  1236,  1238,  1240,  1243,  1245,  1249,  1251,
    1253,  1256,  1260,  1262,  1264,  1265,  1268,  1270,  1272,  1274,
    1277,  1279,  1280,  1284,  1286,  1291,  1293,  1295,  1298,  1300,
    1304,  1306,  1309,  1313,  1315,  1317,  1318,  1321,  1323,  1325,
    1327,  1329,  1331,  1334,  1336,  1340,  1341,  1344,  1348,  1350,
    1352,  1353,  1356,  1358,  1360,  1362,  1364,  1366,  1368,  1370,
    1372,  1374,  1376,  1378,  1380,  1383,  1385,  1389,  1391,  1393,
    1395,  1398,  1402,  1404,  1406,  1407,  1410,  1412,  1414,  1416,
    1418,  1420,  1422,  1425,  1427,  1428,  1432,  1434,  1436,  1437,
    1439,  1441,  1443,  1445,  1449,  1454,  1455,  1459,  1461,  1463,
    1465,  1467,  1470,  1472,  1476,  1478,  1480,  1483,  1487,  1489,
    1491,  1492,  1495,  1497,  1499,  1501,  1504,  1506,  1507,  1511,
    1513,  1515,  1517,  1519,  1522,  1524,  1528,  1530,  1532,  1535,
    1539,  1541,  1543,  1544,  1547,  1549,  1551,  1553,  1555,  1558,
    1560,  1561,  1564,  1566,  1568,  1570,  1572,  1576,  1584,  1585,
    1587,  1588,  1590,  1591,  1593,  1594,  1596,  1597,  1599,  1600,
    1602,  1603,  1605,  1606,  1609,  1613,  1615,  1617,  1618,  1621,
    1623,  1625,  1627,  1629,  1631,  1633,  1635,  1637,  1639,  1641,
    1643,  1645,  1648,  1650,  1654,  1656,  1658,  1660,  1663,  1667,
    1669,  1671,  1672,  1675,  1677,  1679,  1681,  1683,  1685,  1687,
    1690,  1692,  1693,  1697,  1699,  1701,  1702,  1704,  1706,  1708,
    1710,  1714,  1719,  1720,  1724,  1726,  1728,  1730,  1732,  1735,
    1737,  1741,  1743,  1745,  1748,  1752,  1754,  1756,  1757,  1760,
    1762,  1764,  1766,  1769,  1771,  1772,  1776,  1778,  1780,  1782,
    1784,  1787,  1789,  1793,  1795,  1797,  1800,  1804,  1806,  1808,
    1809,  1812,  1814,  1816,  1818,  1820,  1823,  1825,  1826,  1829,
    1831,  1833,  1835,  1837,  1841,  1849,  1850,  1852,  1853,  1855,
    1856,  1858,  1859,  1861,  1862,  1864,  1865,  1867,  1868,  1870,
    1871,  1874,  1878,  1880,  1882,  1883,  1886,  1888,  1890,  1892,
    1894,  1896,  1898,  1900,  1902,  1904,  1906,  1908,  1910,  1913,
    1915,  1919,  1921,  1923,  1925,  1928,  1932,  1934,  1936,  1937,
    1940,  1942,  1944,  1946,  1948,  1950,  1952,  1955,  1957,  1958,
    1962,  1964,  1966,  1968,  1970,  1972,  1976,  1977,  1980,  1984,
    1986,  1988,  1990,  1993,  1995,  1997,  1999,  2001,  2003,  2005,
    2007,  2009,  2011,  2014,  2016,  2020,  2022,  2024,  2027,  2029,
    2031,  2033,  2035,  2037,  2041,  2043,  2045,  2048,  2053,  2057,
    2059,  2061,  2062,  2065,  2067,  2069,  2071,  2075,  2079,  2083,
    2086,  2088,  2090,  2095,  2097,  2099,  2101,  2103,  2107,  2109,
    2111,  2113,  2115,  2120,  2122,  2124,  2129,  2131,  2133,  2135,
    2137,  2141,  2143,  2145,  2147,  2149,  2154,  2159,  2164,  2169,
    2174,  2179,  2184,  2189,  2194,  2199,  2201,  2204,  2208,  2210,
    2212,  2213,  2216,  2218,  2220,  2222,  2224,  2226,  2228,  2232,
    2234,  2236,  2238,  2241,  2242,  2245,  2247,  2249,  2251,  2253,
    2256,  2258,  2260,  2262,  2264,  2268,  2270,  2271,  2274,  2276,
    2278,  2280,  2282,  2284,  2286,  2288,  2290,  2292,  2294,  2298,
    2300,  2302,  2304,  2306,  2308,  2312,  2314,  2316,  2318,  2320,
    2322,  2326,  2328,  2330,  2332,  2334,  2336,  2340,  2342,  2344,
    2346,  2348,  2350,  2354,  2356,  2358,  2359,  2362,  2366,  2368,
    2370,  2371,  2374,  2376,  2378,  2382,  2386,  2388,  2390,  2393,
    2395,  2399,  2403,  2405,  2407,  2409,  2411,  2415,  2417,  2421,
    2423,  2425,  2427,  2429,  2433,  2435,  2439,  2441,  2443,  2445,
    2447,  2451,  2453,  2457,  2459,  2461,  2463,  2465,  2469,  2471,
    2475,  2477,  2479,  2481,  2483,  2487,  2489,  2493,  2495,  2497,
    2499,  2501,  2505,  2507,  2511,  2513,  2515,  2517,  2519,  2523,
    2525,  2527,  2532,  2537,  2542,  2547,  2552,  2557,  2562,  2567,
    2572,  2577,  2582,  2587,  2592,  2594,  2596,  2598,  2602,  2604,
    2606,  2608,  2612,  2614,  2616,  2618,  2622,  2624,  2626,  2628,
    2632,  2634,  2636,  2638,  2642,  2644,  2646,  2648,  2652,  2654,
    2656,  2658,  2662,  2664,  2666,  2668,  2672,  2674,  2676,  2678,
    2682,  2684,  2686,  2688,  2692,  2694,  2696,  2698
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     478,     0,    -1,   479,   487,   485,    -1,   480,   481,   482,
      -1,    14,    -1,    13,    -1,    -1,    15,    -1,   483,    -1,
     484,    -1,    12,    -1,    11,   487,   485,    -1,   486,    -1,
      16,    -1,    -1,   488,   489,   575,   618,   641,   752,    -1,
      -1,  1068,    -1,    -1,   490,   491,    -1,   315,    -1,   492,
      -1,   493,    -1,    11,   316,    -1,    12,    -1,    11,   494,
     316,    -1,   495,    -1,   496,    -1,   495,   496,    -1,   497,
      -1,   503,    -1,   509,    -1,   515,    -1,   523,    -1,   529,
      -1,   535,    -1,   541,    -1,   547,    -1,   553,    -1,   561,
      -1,   498,   499,    -1,   339,    -1,   500,    -1,   501,    -1,
      11,   340,    -1,    12,    -1,    11,   502,   340,    -1,     4,
      -1,   504,   505,    -1,   341,    -1,   506,    -1,   507,    -1,
      11,   342,    -1,    12,    -1,    11,   508,   342,    -1,     4,
      -1,   510,   511,    -1,   343,    -1,   512,    -1,   513,    -1,
      11,   344,    -1,    12,    -1,    11,   514,   344,    -1,     4,
      -1,   516,   517,   519,    -1,    44,    -1,    -1,   518,    -1,
      28,     3,     8,    -1,   520,    -1,   521,    -1,    11,    45,
      -1,    12,    -1,    11,   522,    45,    -1,     4,    -1,   524,
     525,    -1,   345,    -1,   526,    -1,   527,    -1,    11,   346,
      -1,    12,    -1,    11,   528,   346,    -1,     4,    -1,   530,
     531,    -1,    46,    -1,   532,    -1,   533,    -1,    11,    47,
      -1,    12,    -1,    11,   534,    47,    -1,     4,    -1,   536,
     537,    -1,    48,    -1,   538,    -1,   539,    -1,    11,    49,
      -1,    12,    -1,    11,   540,    49,    -1,     4,    -1,   542,
     543,    -1,    50,    -1,   544,    -1,   545,    -1,    11,    51,
      -1,    12,    -1,    11,   546,    51,    -1,     4,    -1,   548,
     549,    -1,    52,    -1,   550,    -1,   551,    -1,    11,    53,
      -1,    12,    -1,    11,   552,    53,    -1,     4,    -1,   554,
     555,   557,    -1,    54,    -1,    -1,   556,    -1,    27,     3,
       8,    -1,   558,    -1,   559,    -1,    11,    55,    -1,    12,
      -1,    11,   560,    55,    -1,     4,    -1,   562,   563,   564,
      -1,   124,    -1,  1048,    -1,   565,    -1,   566,    -1,    11,
     125,    -1,    12,    -1,    11,   567,   125,    -1,   568,    -1,
     569,    -1,   568,   569,    -1,   570,   571,   574,    -1,   347,
      -1,   572,    -1,    -1,   572,   573,    -1,  1176,    -1,  1191,
      -1,  1170,    -1,    11,   348,    -1,    12,    -1,    -1,   576,
     577,    -1,   317,    -1,   578,    -1,   579,    -1,    11,   318,
      -1,    12,    -1,    11,   580,   318,    -1,   581,    -1,   582,
      -1,   581,   582,    -1,   583,    -1,   590,    -1,   597,    -1,
     604,    -1,   609,    -1,   584,   585,   588,    -1,    56,    -1,
     586,    -1,    -1,   586,   587,    -1,  1188,    -1,  1170,    -1,
      11,   589,    57,    -1,  1064,    -1,   591,   592,   595,    -1,
      58,    -1,   593,    -1,    -1,   593,   594,    -1,  1188,    -1,
    1170,    -1,    11,   596,    59,    -1,  1064,    -1,   598,   599,
     602,    -1,    60,    -1,   600,    -1,    -1,   600,   601,    -1,
    1188,    -1,  1170,    -1,    11,   603,    61,    -1,  1064,    -1,
     605,   606,   607,    -1,    62,    -1,    -1,  1170,    -1,    11,
     608,    63,    -1,     6,    -1,   610,   611,   612,    -1,   124,
      -1,  1048,    -1,   613,    -1,   614,    -1,    11,   125,    -1,
      12,    -1,    11,   615,   125,    -1,   616,    -1,   617,    -1,
     616,   617,    -1,   570,   571,   574,    -1,    -1,   619,   620,
      -1,   319,    -1,   621,    -1,   622,    -1,    11,   320,    -1,
      12,    -1,    11,   623,   320,    -1,   624,    -1,   625,    -1,
     624,   625,    -1,   626,    -1,   632,    -1,   627,   628,    -1,
      64,    -1,   629,    -1,   630,    -1,    11,    65,    -1,    12,
      -1,    11,   631,    65,    -1,     4,    -1,   633,   634,   635,
      -1,   124,    -1,  1048,    -1,   636,    -1,   637,    -1,    11,
     125,    -1,    12,    -1,    11,   638,   125,    -1,   639,    -1,
     640,    -1,   639,   640,    -1,   570,   571,   574,    -1,    -1,
     642,   643,    -1,   321,    -1,   644,    -1,   645,    -1,    11,
     322,    -1,    12,    -1,    11,   646,   322,    -1,   647,    -1,
     648,    -1,   647,   648,    -1,   649,    -1,   657,    -1,   663,
      -1,   671,    -1,   676,    -1,   681,    -1,   686,    -1,   691,
      -1,   699,    -1,   715,    -1,   707,    -1,   723,    -1,   729,
      -1,   735,    -1,   743,    -1,   650,   651,   652,    -1,    66,
      -1,    -1,  1188,    -1,   653,    -1,   654,    -1,    11,    67,
      -1,    12,    -1,    11,   655,    67,    -1,   656,    -1,  1064,
      -1,   658,   659,    -1,    68,    -1,   660,    -1,   661,    -1,
      11,    69,    -1,    12,    -1,    11,   662,    69,    -1,     4,
      -1,   664,   665,   666,    -1,    70,    -1,  1045,    -1,   667,
      -1,   668,    -1,    11,    71,    -1,    12,    -1,    11,   669,
      71,    -1,   670,    -1,   669,   670,    -1,   345,    11,     4,
     346,    -1,   672,  1051,   673,    -1,    76,    -1,   674,    -1,
     675,    -1,    11,    77,    -1,    12,    -1,    11,  1013,    77,
      -1,   677,  1051,   678,    -1,    78,    -1,   679,    -1,   680,
      -1,    11,    79,    -1,    12,    -1,    11,  1013,    79,    -1,
     682,  1051,   683,    -1,    80,    -1,   684,    -1,   685,    -1,
      11,    81,    -1,    12,    -1,    11,  1013,    81,    -1,   687,
    1051,   688,    -1,    82,    -1,   689,    -1,   690,    -1,    11,
      83,    -1,    12,    -1,    11,  1013,    83,    -1,   692,   693,
     694,    -1,    88,    -1,  1050,    -1,   695,    -1,   696,    -1,
      11,    89,    -1,    12,    -1,    11,   697,    89,    -1,   698,
      -1,   697,   698,    -1,  1015,    -1,   700,   701,   702,    -1,
      90,    -1,  1050,    -1,   703,    -1,   704,    -1,    11,    91,
      -1,    12,    -1,    11,   705,    91,    -1,   706,    -1,   705,
     706,    -1,  1015,    -1,   708,   709,   710,    -1,    94,    -1,
    1050,    -1,   711,    -1,   712,    -1,    11,    95,    -1,    12,
      -1,    11,   713,    95,    -1,   714,    -1,   713,   714,    -1,
    1015,    -1,   716,   717,   718,    -1,    92,    -1,  1050,    -1,
     719,    -1,   720,    -1,    11,    93,    -1,    12,    -1,    11,
     721,    93,    -1,   722,    -1,   721,   722,    -1,  1015,    -1,
     724,   725,   726,    -1,    86,    -1,  1051,    -1,   727,    -1,
     728,    -1,    11,    87,    -1,    12,    -1,    11,  1013,    87,
      -1,   730,   731,   732,    -1,    84,    -1,  1051,    -1,   733,
      -1,   734,    -1,    11,    85,    -1,    12,    -1,    11,  1013,
      85,    -1,   736,   737,   738,    -1,    96,    -1,  1052,    -1,
     739,    -1,   740,    -1,    11,    97,    -1,    12,    -1,    11,
     741,    97,    -1,   742,    -1,   741,   742,    -1,    98,    11,
       4,    99,    -1,   744,   745,   746,    -1,   124,    -1,  1048,
      -1,   747,    -1,   748,    -1,    11,   125,    -1,    12,    -1,
      11,   749,   125,    -1,   750,    -1,   751,    -1,   750,   751,
      -1,   570,   571,   574,    -1,    -1,   753,   754,   757,    -1,
     323,    -1,   755,    -1,    -1,   755,   756,    -1,  1159,    -1,
    1152,    -1,  1157,    -1,   758,    -1,   759,    -1,    12,    -1,
      11,   760,   324,    -1,   761,   857,   924,   991,    -1,    -1,
     762,   763,   765,    -1,   313,    -1,   764,    -1,    -1,  1049,
      -1,   766,    -1,   767,    -1,    12,    -1,    11,   768,   314,
      -1,   769,   783,   797,   810,   824,   839,    -1,    -1,   770,
     771,   772,    -1,   100,    -1,  1158,    -1,   773,    -1,   774,
      -1,    11,   101,    -1,    12,    -1,    11,   775,   101,    -1,
     776,    -1,   777,    -1,   776,   777,    -1,   778,   779,   782,
      -1,   311,    -1,   780,    -1,    -1,   780,   781,    -1,  1161,
      -1,  1176,    -1,  1191,    -1,    11,   312,    -1,    12,    -1,
      -1,   784,   785,   786,    -1,   102,    -1,  1158,    -1,   787,
      -1,   788,    -1,    11,   103,    -1,    12,    -1,    11,   789,
     103,    -1,   790,    -1,   791,    -1,   790,   791,    -1,   792,
     793,   796,    -1,   311,    -1,   794,    -1,    -1,   794,   795,
      -1,  1161,    -1,  1176,    -1,  1191,    -1,    11,   312,    -1,
      12,    -1,    -1,   798,   799,    -1,   104,    -1,   800,    -1,
     801,    -1,    12,    -1,    11,   802,   105,    -1,   803,   804,
     805,   806,   807,   808,   809,    -1,    -1,  1108,    -1,    -1,
    1114,    -1,    -1,  1120,    -1,    -1,  1126,    -1,    -1,  1132,
      -1,    -1,  1138,    -1,    -1,  1144,    -1,    -1,   811,   812,
     813,    -1,   106,    -1,  1158,    -1,   814,    -1,   815,    -1,
      11,   107,    -1,    12,    -1,    11,   816,   107,    -1,   817,
      -1,   818,    -1,   817,   818,    -1,   819,   820,   823,    -1,
     311,    -1,   821,    -1,    -1,   821,   822,    -1,  1161,    -1,
    1176,    -1,  1191,    -1,    11,   312,    -1,    12,    -1,    -1,
     825,   826,   827,    -1,   108,    -1,    41,     8,     6,     8,
      -1,   828,    -1,   829,    -1,    11,   109,    -1,    12,    -1,
      11,   830,   109,    -1,   831,    -1,   830,   831,    -1,   832,
     833,   836,    -1,   110,    -1,   834,    -1,    -1,   834,   835,
      -1,  1034,    -1,  1158,    -1,  1024,    -1,   837,    -1,   838,
      -1,    11,   111,    -1,    12,    -1,    11,   817,   111,    -1,
      -1,   839,   840,    -1,   841,   842,   845,    -1,   347,    -1,
     843,    -1,    -1,   843,   844,    -1,  1158,    -1,  1154,    -1,
    1176,    -1,  1191,    -1,  1182,    -1,  1164,    -1,  1185,    -1,
    1194,    -1,  1173,    -1,  1170,    -1,   846,    -1,   847,    -1,
      11,   348,    -1,    12,    -1,    11,   848,   348,    -1,   849,
      -1,  1054,    -1,   850,    -1,   849,   850,    -1,   851,   852,
     855,    -1,   311,    -1,   853,    -1,    -1,   853,   854,    -1,
    1161,    -1,  1176,    -1,  1191,    -1,  1026,    -1,  1037,    -1,
     856,    -1,    11,   312,    -1,    12,    -1,    -1,   858,   859,
     861,    -1,   309,    -1,   860,    -1,    -1,  1047,    -1,   862,
      -1,   863,    -1,    12,    -1,    11,   864,   310,    -1,   865,
     879,   893,   906,    -1,    -1,   866,   867,   868,    -1,   112,
      -1,  1156,    -1,   869,    -1,   870,    -1,    11,   113,    -1,
      12,    -1,    11,   871,   113,    -1,   872,    -1,   873,    -1,
     872,   873,    -1,   874,   875,   878,    -1,   307,    -1,   876,
      -1,    -1,   876,   877,    -1,  1161,    -1,  1176,    -1,  1191,
      -1,    11,   308,    -1,    12,    -1,    -1,   880,   881,   882,
      -1,   114,    -1,  1156,    -1,   883,    -1,   884,    -1,    11,
     115,    -1,    12,    -1,    11,   885,   115,    -1,   886,    -1,
     887,    -1,   886,   887,    -1,   888,   889,   892,    -1,   307,
      -1,   890,    -1,    -1,   890,   891,    -1,  1161,    -1,  1176,
      -1,  1026,    -1,  1037,    -1,    11,   308,    -1,    12,    -1,
      -1,   894,   895,    -1,   104,    -1,   896,    -1,   897,    -1,
      12,    -1,    11,   898,   105,    -1,   899,   900,   901,   902,
     903,   904,   905,    -1,    -1,  1108,    -1,    -1,  1114,    -1,
      -1,  1120,    -1,    -1,  1126,    -1,    -1,  1132,    -1,    -1,
    1138,    -1,    -1,  1144,    -1,    -1,   906,   907,    -1,   908,
     909,   912,    -1,   347,    -1,   910,    -1,    -1,   910,   911,
      -1,  1156,    -1,  1154,    -1,  1176,    -1,  1191,    -1,  1182,
      -1,  1164,    -1,  1185,    -1,  1179,    -1,  1173,    -1,  1170,
      -1,   913,    -1,   914,    -1,    11,   348,    -1,    12,    -1,
      11,   915,   348,    -1,   916,    -1,  1054,    -1,   917,    -1,
     916,   917,    -1,   918,   919,   922,    -1,   307,    -1,   920,
      -1,    -1,   920,   921,    -1,  1161,    -1,  1176,    -1,  1191,
      -1,  1026,    -1,  1037,    -1,   923,    -1,    11,   308,    -1,
      12,    -1,    -1,   925,   926,   928,    -1,   305,    -1,   927,
      -1,    -1,  1046,    -1,   929,    -1,   930,    -1,    12,    -1,
      11,   931,   306,    -1,   932,   946,   960,   973,    -1,    -1,
     933,   934,   935,    -1,   116,    -1,  1151,    -1,   936,    -1,
     937,    -1,    11,   117,    -1,    12,    -1,    11,   938,   117,
      -1,   939,    -1,   940,    -1,   939,   940,    -1,   941,   942,
     945,    -1,   303,    -1,   943,    -1,    -1,   943,   944,    -1,
    1161,    -1,  1176,    -1,  1191,    -1,    11,   304,    -1,    12,
      -1,    -1,   947,   948,   949,    -1,   118,    -1,  1151,    -1,
     950,    -1,   951,    -1,    11,   119,    -1,    12,    -1,    11,
     952,   119,    -1,   953,    -1,   954,    -1,   953,   954,    -1,
     955,   956,   959,    -1,   303,    -1,   957,    -1,    -1,   957,
     958,    -1,  1161,    -1,  1176,    -1,  1030,    -1,  1041,    -1,
      11,   304,    -1,    12,    -1,    -1,   961,   962,    -1,   104,
      -1,   963,    -1,   964,    -1,    12,    -1,    11,   965,   105,
      -1,   966,   967,   968,   969,   970,   971,   972,    -1,    -1,
    1108,    -1,    -1,  1114,    -1,    -1,  1120,    -1,    -1,  1126,
      -1,    -1,  1132,    -1,    -1,  1138,    -1,    -1,  1144,    -1,
      -1,   973,   974,    -1,   975,   976,   979,    -1,   347,    -1,
     977,    -1,    -1,   977,   978,    -1,  1151,    -1,  1154,    -1,
    1176,    -1,  1191,    -1,  1182,    -1,  1164,    -1,  1185,    -1,
    1167,    -1,  1173,    -1,  1170,    -1,   980,    -1,   981,    -1,
      11,   348,    -1,    12,    -1,    11,   982,   348,    -1,   983,
      -1,  1054,    -1,   984,    -1,   983,   984,    -1,   985,   986,
     989,    -1,   303,    -1,   987,    -1,    -1,   987,   988,    -1,
    1161,    -1,  1176,    -1,  1191,    -1,  1026,    -1,  1037,    -1,
     990,    -1,    11,   304,    -1,    12,    -1,    -1,   992,   993,
     994,    -1,   120,    -1,  1053,    -1,   995,    -1,   996,    -1,
      12,    -1,    11,   997,   121,    -1,    -1,   997,   998,    -1,
     999,  1000,  1003,    -1,   122,    -1,  1001,    -1,  1002,    -1,
    1001,  1002,    -1,  1176,    -1,  1191,    -1,  1182,    -1,  1164,
      -1,  1185,    -1,  1170,    -1,  1155,    -1,  1004,    -1,  1005,
      -1,    11,   123,    -1,    12,    -1,    11,  1006,   123,    -1,
    1007,    -1,  1008,    -1,  1007,  1008,    -1,  1009,    -1,  1010,
      -1,  1011,    -1,   161,    -1,   158,    -1,   159,  1012,   160,
      -1,     5,    -1,  1014,    -1,  1013,  1014,    -1,    72,    11,
       4,    73,    -1,  1016,  1017,  1023,    -1,    74,    -1,  1018,
      -1,    -1,  1018,  1019,    -1,  1020,    -1,  1021,    -1,  1022,
      -1,    29,     3,     8,    -1,    30,     3,     8,    -1,    31,
       3,     8,    -1,    11,    75,    -1,    12,    -1,  1025,    -1,
      43,     8,  1064,     8,    -1,  1027,    -1,  1028,    -1,  1029,
      -1,    17,    -1,    19,     3,  1065,    -1,  1031,    -1,  1032,
      -1,  1033,    -1,    21,    -1,    23,  1065,  1064,  1065,    -1,
    1035,    -1,  1036,    -1,    42,  1065,     6,  1065,    -1,  1038,
      -1,  1039,    -1,  1040,    -1,    18,    -1,    20,     3,  1065,
      -1,  1042,    -1,  1043,    -1,  1044,    -1,    22,    -1,    24,
    1065,  1064,  1065,    -1,    32,     8,     6,     8,    -1,    38,
    1065,     6,  1065,    -1,    37,  1065,     6,  1065,    -1,    40,
    1065,     6,  1065,    -1,    36,  1065,     6,  1065,    -1,    34,
       8,     6,     8,    -1,    33,     8,     6,     8,    -1,    35,
       8,     6,     8,    -1,    39,  1065,     6,  1065,    -1,  1055,
      -1,  1054,  1055,    -1,  1056,  1057,  1060,    -1,   156,    -1,
    1058,    -1,    -1,  1058,  1059,    -1,  1153,    -1,  1191,    -1,
    1170,    -1,  1061,    -1,  1062,    -1,    12,    -1,    11,  1063,
     157,    -1,  1096,    -1,     6,    -1,     7,    -1,  1066,     8,
      -1,    -1,  1066,  1067,    -1,   473,    -1,   474,    -1,   475,
      -1,   476,    -1,  1069,  1070,    -1,   126,    -1,  1071,    -1,
    1072,    -1,    12,    -1,    11,  1073,   127,    -1,  1074,    -1,
      -1,  1074,  1075,    -1,  1076,    -1,  1080,    -1,  1084,    -1,
    1088,    -1,  1092,    -1,  1077,    -1,  1078,    -1,  1079,    -1,
     131,    -1,   130,    -1,   128,     5,   129,    -1,  1081,    -1,
    1082,    -1,  1083,    -1,   135,    -1,   134,    -1,   132,     5,
     133,    -1,  1085,    -1,  1086,    -1,  1087,    -1,   139,    -1,
     138,    -1,   136,     5,   137,    -1,  1089,    -1,  1090,    -1,
    1091,    -1,   143,    -1,   142,    -1,   140,     5,   141,    -1,
    1093,    -1,  1094,    -1,  1095,    -1,   147,    -1,   146,    -1,
     144,     5,   145,    -1,  1097,    -1,  1104,    -1,    -1,  1097,
    1098,    -1,  1099,  1100,  1103,    -1,   154,    -1,  1101,    -1,
      -1,  1101,  1102,    -1,  1163,    -1,  1162,    -1,    11,     6,
     155,    -1,   162,  1160,  1105,    -1,  1106,    -1,  1107,    -1,
      11,   163,    -1,    12,    -1,    11,     4,   163,    -1,  1109,
    1150,  1110,    -1,   331,    -1,  1111,    -1,  1112,    -1,    12,
      -1,    11,  1113,   332,    -1,  1096,    -1,  1115,  1150,  1116,
      -1,   327,    -1,  1117,    -1,  1118,    -1,    12,    -1,    11,
    1119,   328,    -1,  1096,    -1,  1121,  1150,  1122,    -1,   329,
      -1,  1123,    -1,  1124,    -1,    12,    -1,    11,  1125,   330,
      -1,  1096,    -1,  1127,  1150,  1128,    -1,   325,    -1,  1129,
      -1,  1130,    -1,    12,    -1,    11,  1131,   326,    -1,  1096,
      -1,  1133,  1150,  1134,    -1,   333,    -1,  1135,    -1,  1136,
      -1,    12,    -1,    11,  1137,   334,    -1,  1096,    -1,  1139,
    1150,  1140,    -1,   335,    -1,  1141,    -1,  1142,    -1,    12,
      -1,    11,  1143,   336,    -1,  1096,    -1,  1145,  1150,  1146,
      -1,   337,    -1,  1147,    -1,  1148,    -1,    12,    -1,    11,
    1149,   338,    -1,  1096,    -1,  1153,    -1,   213,     8,     6,
       8,    -1,   212,     8,     6,     8,    -1,   164,     8,     6,
       8,    -1,   165,     8,     6,     8,    -1,   166,     8,     6,
       8,    -1,   216,     8,     6,     8,    -1,   215,     8,     6,
       8,    -1,   219,     8,     6,     8,    -1,   218,     8,     6,
       8,    -1,   242,     8,     6,     8,    -1,   239,     8,     6,
       8,    -1,   240,     8,     6,     8,    -1,   241,     8,     6,
       8,    -1,  1165,    -1,  1166,    -1,   167,    -1,   168,     3,
       8,    -1,  1168,    -1,  1169,    -1,   187,    -1,   188,     3,
       8,    -1,  1171,    -1,  1172,    -1,   169,    -1,   170,     3,
       8,    -1,  1174,    -1,  1175,    -1,   177,    -1,   178,     3,
       8,    -1,  1177,    -1,  1178,    -1,   173,    -1,   174,     3,
       8,    -1,  1180,    -1,  1181,    -1,   189,    -1,   190,     3,
       8,    -1,  1183,    -1,  1184,    -1,   171,    -1,   172,     3,
       8,    -1,  1186,    -1,  1187,    -1,   175,    -1,   176,     3,
       8,    -1,  1189,    -1,  1190,    -1,   181,    -1,   182,     3,
       8,    -1,  1192,    -1,  1193,    -1,   183,    -1,   184,     3,
       8,    -1,  1195,    -1,  1196,    -1,   191,    -1,   192,     3,
       8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   349,   349,   350,   352,   359,   369,   369,   371,   371,
     373,   375,   377,   386,   387,   390,   398,   398,   411,   411,
     413,   429,   429,   431,   431,   433,   435,   437,   437,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     454,   456,   465,   465,   467,   467,   469,   471,   481,   483,
     490,   490,   492,   492,   494,   496,   506,   508,   514,   514,
     516,   516,   518,   520,   530,   537,   545,   546,   553,   559,
     559,   561,   561,   563,   565,   573,   575,   581,   581,   583,
     583,   585,   587,   596,   598,   605,   605,   607,   607,   609,
     611,   621,   623,   630,   630,   632,   632,   634,   636,   646,
     648,   654,   654,   656,   656,   658,   660,   670,   672,   678,
     678,   680,   680,   682,   684,   694,   701,   710,   711,   717,
     724,   724,   726,   726,   728,   730,   738,   744,   754,   762,
     767,   773,   773,   775,   777,   781,   781,   783,   794,   813,
     819,   819,   822,   826,   827,   830,   830,   878,   878,   880,
     890,   890,   892,   892,   894,   896,   898,   898,   901,   902,
     903,   904,   905,   909,   911,   921,   923,   923,   926,   927,
     930,   932,   940,   942,   952,   954,   954,   957,   958,   961,
     963,   972,   974,   984,   986,   986,   989,   990,   993,   995,
    1004,  1006,  1016,  1017,  1019,  1021,  1032,  1038,  1048,  1056,
    1060,  1065,  1065,  1067,  1069,  1073,  1073,  1075,  1130,  1130,
    1132,  1139,  1139,  1141,  1141,  1143,  1145,  1147,  1147,  1150,
    1151,  1155,  1157,  1163,  1163,  1165,  1165,  1167,  1169,  1180,
    1186,  1196,  1204,  1208,  1213,  1213,  1215,  1217,  1221,  1221,
    1223,  1276,  1276,  1278,  1298,  1298,  1300,  1300,  1302,  1304,
    1306,  1306,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,  1323,  1328,  1334,  1344,
    1345,  1347,  1347,  1349,  1349,  1351,  1353,  1355,  1362,  1364,
    1370,  1370,  1372,  1372,  1374,  1376,  1386,  1397,  1407,  1409,
    1409,  1411,  1411,  1413,  1422,  1422,  1424,  1445,  1456,  1466,
    1466,  1468,  1468,  1470,  1481,  1492,  1502,  1502,  1504,  1504,
    1506,  1517,  1528,  1538,  1538,  1540,  1540,  1542,  1553,  1564,
    1574,  1574,  1576,  1576,  1578,  1589,  1605,  1615,  1617,  1617,
    1619,  1619,  1621,  1630,  1630,  1632,  1636,  1652,  1662,  1664,
    1664,  1666,  1666,  1668,  1677,  1677,  1679,  1683,  1699,  1709,
    1711,  1711,  1713,  1713,  1715,  1724,  1724,  1726,  1730,  1746,
    1756,  1758,  1758,  1760,  1760,  1762,  1771,  1771,  1773,  1777,
    1788,  1798,  1800,  1800,  1802,  1802,  1804,  1815,  1826,  1836,
    1838,  1838,  1840,  1840,  1842,  1868,  1879,  1889,  1891,  1891,
    1893,  1893,  1895,  1904,  1904,  1906,  1927,  1933,  1943,  1951,
    1955,  1960,  1960,  1962,  1964,  1968,  1968,  1970,  2024,  2024,
    2026,  2034,  2036,  2036,  2039,  2046,  2053,  2062,  2062,  2064,
    2066,  2068,  2075,  2075,  2077,  2083,  2090,  2090,  2095,  2095,
    2097,  2099,  2101,  2111,  2111,  2126,  2131,  2142,  2150,  2159,
    2159,  2161,  2163,  2165,  2165,  2168,  2173,  2187,  2193,  2193,
    2196,  2210,  2215,  2223,  2223,  2227,  2227,  2242,  2247,  2258,
    2266,  2275,  2275,  2277,  2279,  2281,  2281,  2284,  2290,  2305,
    2311,  2311,  2314,  2326,  2331,  2337,  2337,  2341,  2341,  2343,
    2348,  2348,  2350,  2352,  2354,  2357,  2357,  2395,  2395,  2431,
    2431,  2466,  2466,  2501,  2501,  2536,  2536,  2571,  2571,  2606,
    2606,  2622,  2627,  2638,  2646,  2655,  2655,  2657,  2659,  2665,
    2665,  2667,  2672,  2688,  2694,  2694,  2697,  2709,  2714,  2722,
    2722,  2726,  2726,  2732,  2738,  2746,  2754,  2762,  2762,  2764,
    2766,  2766,  2768,  2787,  2803,  2811,  2811,  2814,  2815,  2824,
    2827,  2827,  2829,  2829,  2831,  2836,  2836,  2838,  2843,  2875,
    2895,  2895,  2898,  2902,  2906,  2907,  2908,  2909,  2910,  2911,
    2912,  2913,  2916,  2916,  2918,  2918,  2920,  2922,  2922,  2924,
    2924,  2927,  2942,  2962,  2964,  2964,  2967,  2977,  2978,  2979,
    2980,  2983,  2985,  2985,  2993,  2993,  2995,  3001,  3008,  3008,
    3013,  3013,  3015,  3017,  3019,  3028,  3028,  3044,  3050,  3062,
    3070,  3079,  3079,  3081,  3083,  3085,  3085,  3088,  3093,  3108,
    3110,  3110,  3113,  3124,  3128,  3135,  3135,  3138,  3138,  3156,
    3161,  3175,  3183,  3192,  3192,  3194,  3196,  3198,  3198,  3201,
    3206,  3224,  3226,  3226,  3229,  3240,  3244,  3250,  3257,  3257,
    3261,  3261,  3263,  3268,  3268,  3270,  3272,  3274,  3277,  3277,
    3311,  3311,  3345,  3345,  3379,  3379,  3413,  3413,  3447,  3447,
    3483,  3483,  3518,  3518,  3520,  3526,  3557,  3578,  3578,  3581,
    3585,  3589,  3590,  3591,  3592,  3593,  3594,  3595,  3596,  3599,
    3599,  3601,  3601,  3603,  3605,  3605,  3607,  3607,  3610,  3625,
    3647,  3649,  3649,  3652,  3662,  3663,  3664,  3665,  3668,  3670,
    3670,  3678,  3678,  3680,  3686,  3693,  3693,  3698,  3698,  3700,
    3702,  3704,  3713,  3713,  3729,  3734,  3745,  3753,  3762,  3762,
    3764,  3766,  3768,  3768,  3771,  3776,  3792,  3799,  3799,  3802,
    3813,  3817,  3824,  3824,  3828,  3828,  3846,  3851,  3864,  3872,
    3881,  3881,  3883,  3885,  3887,  3887,  3890,  3895,  3914,  3921,
    3921,  3924,  3935,  3939,  3943,  3949,  3949,  3953,  3953,  3955,
    3960,  3960,  3962,  3964,  3966,  3969,  3969,  4003,  4003,  4038,
    4038,  4074,  4074,  4109,  4109,  4144,  4144,  4179,  4179,  4214,
    4214,  4216,  4222,  4253,  4273,  4273,  4276,  4280,  4284,  4285,
    4286,  4287,  4288,  4289,  4290,  4291,  4294,  4294,  4296,  4296,
    4298,  4300,  4300,  4302,  4302,  4305,  4320,  4340,  4342,  4342,
    4345,  4357,  4358,  4359,  4360,  4363,  4365,  4365,  4373,  4373,
    4379,  4381,  4389,  4397,  4406,  4408,  4410,  4410,  4414,  4434,
    4452,  4458,  4458,  4461,  4462,  4463,  4464,  4465,  4466,  4467,
    4474,  4482,  4491,  4491,  4493,  4495,  4497,  4497,  4499,  4506,
    4517,  4519,  4519,  4521,  4523,  4540,  4540,  4542,  4564,  4581,
    4593,  4598,  4598,  4601,  4602,  4603,  4605,  4614,  4623,  4632,
    4632,  4716,  4723,  4745,  4752,  4752,  4754,  4759,  4766,  4772,
    4772,  4774,  4779,  4843,  4849,  4851,  4877,  4884,  4884,  4886,
    4891,  4898,  4904,  4904,  4906,  4909,  5021,  5049,  5055,  5061,
    5067,  5073,  5087,  5097,  5108,  5144,  5144,  5146,  5165,  5182,
    5190,  5190,  5193,  5201,  5202,  5206,  5206,  5208,  5211,  5213,
    5217,  5218,  5225,  5227,  5227,  5229,  5230,  5231,  5232,  5267,
    5269,  5283,  5283,  5285,  5287,  5289,  5291,  5291,  5294,  5295,
    5296,  5297,  5298,  5300,  5308,  5308,  5310,  5310,  5312,  5318,
    5326,  5326,  5328,  5328,  5330,  5336,  5344,  5344,  5346,  5346,
    5348,  5354,  5362,  5362,  5364,  5364,  5366,  5372,  5380,  5380,
    5382,  5382,  5384,  5403,  5411,  5413,  5413,  5415,  5417,  5426,
    5428,  5428,  5430,  5430,  5432,  5441,  5444,  5444,  5446,  5446,
    5449,  5710,  5712,  5717,  5717,  5719,  5721,  5723,  5726,  5728,
    5733,  5733,  5735,  5737,  5739,  5742,  5744,  5749,  5749,  5751,
    5753,  5755,  5758,  5760,  5765,  5765,  5767,  5769,  5771,  5774,
    5776,  5781,  5781,  5783,  5785,  5787,  5790,  5792,  5797,  5797,
    5799,  5801,  5803,  5806,  5808,  5813,  5813,  5815,  5817,  5819,
    5822,  7427,  7449,  7460,  7471,  7482,  7550,  7572,  7606,  7628,
    7642,  7761,  7771,  7808,  7934,  7934,  7936,  7943,  7952,  7952,
    7954,  7961,  7970,  7970,  7972,  7979,  7988,  7988,  7990,  7997,
    8080,  8080,  8082,  8089,  8098,  8098,  8100,  8107,  8161,  8161,
    8163,  8170,  8197,  8197,  8199,  8206,  8215,  8215,  8217,  8224,
    8233,  8233,  8237,  8245,  8272,  8272,  8274,  8281
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "BOOLEAN",
  "GREATERTHAN", "ENDOFELEMENT", "OSOLSTART", "OSOLSTARTEMPTY",
  "OSOLATTRIBUTETEXT", "OSOLEND", "EMPTYLBVALUEATT", "EMPTYUBVALUEATT",
  "LBVALUEATT", "UBVALUEATT", "EMPTYLBDUALVALUEATT", "EMPTYUBDUALVALUEATT",
  "LBDUALVALUEATT", "UBDUALVALUEATT", "WEIGHTATT", "EMPTYWEIGHTATT",
  "TRANSPORTTYPEATT", "LOCATIONTYPEATT", "FROMATT", "TOATT", "MAKECOPYATT",
  "NUMBEROFJOBIDSATT", "NUMBEROFPATHSATT", "NUMBEROFPATHPAIRSATT",
  "NUMBEROFPROCESSESATT", "NUMBEROFOTHERVARIABLEOPTIONSATT",
  "NUMBEROFOTHEROBJECTIVEOPTIONSATT", "NUMBEROFOTHERCONSTRAINTOPTIONSATT",
  "NUMBEROFSOLVEROPTIONSATT", "NUMBEROFOTHEROPTIONSATT", "NUMBEROFSOSATT",
  "SOSIDXATT", "GROUPWEIGHTATT", "INSTANCELOCATIONSTART",
  "INSTANCELOCATIONEND", "SOLVERTOINVOKESTART", "SOLVERTOINVOKEEND",
  "LICENSESTART", "LICENSEEND", "USERNAMESTART", "USERNAMEEND",
  "PASSWORDSTART", "PASSWORDEND", "CONTACTSTART", "CONTACTEND",
  "MINDISKSPACESTART", "MINDISKSPACEEND", "MINMEMORYSTART", "MINMEMORYEND",
  "MINCPUSPEEDSTART", "MINCPUSPEEDEND", "MINCPUNUMBERSTART",
  "MINCPUNUMBEREND", "SERVICETYPESTART", "SERVICETYPEEND", "MAXTIMESTART",
  "MAXTIMEEND", "REQUESTEDSTARTTIMESTART", "REQUESTEDSTARTTIMEEND",
  "DEPENDENCIESSTART", "DEPENDENCIESEND", "PATHSTART", "PATHEND",
  "PATHPAIRSTART", "PATHPAIREND", "REQUIREDDIRECTORIESSTART",
  "REQUIREDDIRECTORIESEND", "REQUIREDFILESSTART", "REQUIREDFILESEND",
  "DIRECTORIESTOMAKESTART", "DIRECTORIESTOMAKEEND", "FILESTOMAKESTART",
  "FILESTOMAKEEND", "DIRECTORIESTODELETESTART", "DIRECTORIESTODELETEEND",
  "FILESTODELETESTART", "FILESTODELETEEND", "INPUTDIRECTORIESTOMOVESTART",
  "INPUTDIRECTORIESTOMOVEEND", "INPUTFILESTOMOVESTART",
  "INPUTFILESTOMOVEEND", "OUTPUTDIRECTORIESTOMOVESTART",
  "OUTPUTDIRECTORIESTOMOVEEND", "OUTPUTFILESTOMOVESTART",
  "OUTPUTFILESTOMOVEEND", "PROCESSESTOKILLSTART", "PROCESSESTOKILLEND",
  "PROCESSSTART", "PROCESSEND", "INITIALVARIABLEVALUESSTART",
  "INITIALVARIABLEVALUESEND", "INITIALVARIABLEVALUESSTRINGSTART",
  "INITIALVARIABLEVALUESSTRINGEND", "INITIALBASISSTATUSSTART",
  "INITIALBASISSTATUSEND", "INTEGERVARIABLEBRANCHINGWEIGHTSSTART",
  "INTEGERVARIABLEBRANCHINGWEIGHTSEND", "SOSVARIABLEBRANCHINGWEIGHTSSTART",
  "SOSVARIABLEBRANCHINGWEIGHTSEND", "SOSSTART", "SOSEND",
  "INITIALOBJECTIVEVALUESSTART", "INITIALOBJECTIVEVALUESEND",
  "INITIALOBJECTIVEBOUNDSSTART", "INITIALOBJECTIVEBOUNDSEND",
  "INITIALCONSTRAINTVALUESSTART", "INITIALCONSTRAINTVALUESEND",
  "INITIALDUALVALUESSTART", "INITIALDUALVALUESEND", "SOLVEROPTIONSSTART",
  "SOLVEROPTIONSEND", "SOLVEROPTIONSTART", "SOLVEROPTIONEND",
  "OTHEROPTIONSSTART", "OTHEROPTIONSEND", "HEADERSTART", "HEADEREND",
  "FILENAMESTART", "FILENAMEEND", "FILENAMEEMPTY", "FILENAMESTARTANDEND",
  "FILESOURCESTART", "FILESOURCEEND", "FILESOURCEEMPTY",
  "FILESOURCESTARTANDEND", "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND",
  "FILEDESCRIPTIONEMPTY", "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART",
  "FILECREATOREND", "FILECREATOREMPTY", "FILECREATORSTARTANDEND",
  "FILELICENCESTART", "FILELICENCEEND", "FILELICENCEEMPTY",
  "FILELICENCESTARTANDEND", "INDEXESSTART", "INDEXESEND", "VALUESSTART",
  "VALUESEND", "NONZEROSSTART", "NONZEROSEND", "ELSTART", "ELEND",
  "ENUMERATIONSTART", "ENUMERATIONEND", "ITEMEMPTY", "ITEMSTART",
  "ITEMEND", "ITEMSTARTANDEND", "BASE64START", "BASE64END",
  "NUMBEROFELATT", "NUMBEROFENUMERATIONSATT", "NUMBEROFITEMSATT",
  "EMPTYCATEGORYATT", "CATEGORYATT", "EMPTYDESCRIPTIONATT",
  "DESCRIPTIONATT", "EMPTYSOLVERATT", "SOLVERATT", "EMPTYNAMEATT",
  "NAMEATT", "EMPTYTYPEATT", "TYPEATT", "EMPTYENUMTYPEATT", "ENUMTYPEATT",
  "EMPTYSHAPEATT", "SHAPEATT", "EMPTYUNITATT", "UNITATT", "EMPTYVALUEATT",
  "VALUEATT", "EMPTYVALUETYPEATT", "VALUETYPEATT", "EMPTYCONTYPEATT",
  "CONTYPEATT", "EMPTYOBJTYPEATT", "OBJTYPEATT", "EMPTYVARTYPEATT",
  "VARTYPEATT", "EMPTYMATRIXCONTYPEATT", "MATRIXCONTYPEATT",
  "EMPTYMATRIXOBJTYPEATT", "MATRIXOBJTYPEATT", "EMPTYMATRIXVARTYPEATT",
  "MATRIXVARTYPEATT", "EMPTYMATRIXTYPEATT", "MATRIXTYPEATT",
  "EMPTYSYMMETRYATT", "SYMMETRYATT", "EMPTYROWMAJORATT", "ROWMAJORATT",
  "EMPTYBASETRANSPOSEATT", "BASETRANSPOSEATT", "NUMBEROFBLOCKSATT",
  "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT", "NUMBEROFMATRICESATT",
  "NUMBEROFVALUESATT", "NUMBEROFCONSTRAINTSATT", "NUMBEROFCONATT",
  "NUMBEROFCONIDXATT", "NUMBEROFOBJECTIVESATT", "NUMBEROFOBJATT",
  "NUMBEROFOBJIDXATT", "NUMBEROFVARIABLESATT", "NUMBEROFVARATT",
  "NUMBEROFVARIDXATT", "NUMBEROFMATRIXCONATT", "NUMBEROFMATRIXOBJATT",
  "NUMBEROFMATRIXVARATT", "BASEMATRIXIDXATT", "TARGETMATRIXFIRSTROWATT",
  "TARGETMATRIXFIRSTCOLATT", "BASEMATRIXSTARTROWATT",
  "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT", "BASEMATRIXENDCOLATT",
  "SCALARMULTIPLIERATT", "BLOCKROWIDXATT", "BLOCKCOLIDXATT", "REATT",
  "IMATT", "MATRIXVARIDXATT", "MATRIXOBJIDXATT", "MATRIXCONIDXATT",
  "IDXATT", "INCRATT", "MULTATT", "SIZEOFATT", "COEFATT", "CONSTANTATT",
  "MATRICESSTART", "MATRICESEND", "MATRIXSTART", "MATRIXEND",
  "BASEMATRIXEND", "BASEMATRIXSTART", "BLOCKSSTART", "BLOCKSEND",
  "BLOCKSTART", "BLOCKEND", "COLOFFSETSTART", "COLOFFSETEND",
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
  "'\\t'", "'\\r'", "'\\n'", "$accept", "osoldoc", "osolStartEmpty",
  "osolStart", "osolAttributes", "osolContent", "osolEmpty", "osolLaden",
  "osolEnd", "osolEnding", "osolBody", "headerElement", "generalElement",
  "generalElementStart", "generalElementContent", "generalElementEmpty",
  "generalElementLaden", "generalElementBody", "generalElementList",
  "generalChild", "serviceURI", "serviceURIStart", "serviceURIContent",
  "serviceURIEmpty", "serviceURILaden", "serviceURIBody", "serviceName",
  "serviceNameStart", "serviceNameContent", "serviceNameEmpty",
  "serviceNameLaden", "serviceNameBody", "instanceName",
  "instanceNameStart", "instanceNameContent", "instanceNameEmpty",
  "instanceNameLaden", "instanceNameBody", "instanceLocation",
  "instanceLocationStart", "instanceLocationAttributes",
  "locationTypeAttribute", "instanceLocationContent",
  "instanceLocationEmpty", "instanceLocationLaden", "instanceLocationBody",
  "jobID", "jobIDStart", "jobIDContent", "jobIDEmpty", "jobIDLaden",
  "jobIDBody", "solverToInvoke", "solverToInvokeStart",
  "solverToInvokeContent", "solverToInvokeEmpty", "solverToInvokeLaden",
  "solverToInvokeBody", "license", "licenseStart", "licenseContent",
  "licenseEmpty", "licenseLaden", "licensebody", "username",
  "usernameStart", "usernameContent", "usernameEmpty", "usernameLaden",
  "usernamebody", "password", "passwordStart", "passwordContent",
  "passwordEmpty", "passwordLaden", "passwordbody", "contact",
  "contactStart", "contactAttributes", "transportTypeAttribute",
  "contactContent", "contactContentEmpty", "contactContentLaden",
  "contactBody", "otherGeneralOptions", "otherGeneralOptionsStart",
  "otherGeneralOptionsAttributes", "otherGeneralOptionsContent",
  "otherGeneralOptionsEmpty", "otherGeneralOptionsLaden",
  "otherGeneralOptionsBody", "otherGeneralOptionArray",
  "otherGeneralOption", "otherOptionStart", "otherOptionAttributes",
  "otherOptionAttList", "otherOptionAtt", "otherOptionEnd",
  "systemElement", "systemElementStart", "systemElementContent",
  "systemElementEmpty", "systemElementLaden", "systemElementBody",
  "systemElementList", "systemChild", "minDiskSpace", "minDiskSpaceStart",
  "minDiskSpaceAttributes", "minDiskSpaceAttList", "minDiskSpaceAtt",
  "minDiskSpaceContent", "minDiskSpaceValue", "minMemorySize",
  "minMemoryStart", "minMemoryAttributes", "minMemoryAttList",
  "minMemoryAtt", "minMemoryContent", "minMemoryValue", "minCPUSpeed",
  "minCPUSpeedStart", "minCPUSpeedAttributes", "minCPUSpeedAttList",
  "minCPUSpeedAtt", "minCPUSpeedContent", "minCPUSpeedValue",
  "minCPUNumber", "minCPUNumberStart", "minCPUNumberAttributes",
  "minCPUNumberContent", "minCPUNumberValue", "otherSystemOptions",
  "otherSystemOptionsStart", "otherSystemOptionsAttributes",
  "otherSystemOptionsContent", "otherSystemOptionsEmpty",
  "otherSystemOptionsLaden", "otherSystemOptionsBody",
  "otherSystemOptionArray", "otherSystemOption", "serviceElement",
  "serviceElementStart", "serviceElementContent", "serviceElementEmpty",
  "serviceElementLaden", "serviceElementBody", "serviceElementList",
  "serviceChild", "serviceType", "serviceTypeStart", "serviceTypeContent",
  "serviceTypeEmpty", "serviceTypeLaden", "serviceTypeBody",
  "otherServiceOptions", "otherServiceOptionsStart",
  "otherServiceOptionsAttributes", "otherServiceOptionsContent",
  "otherServiceOptionsEmpty", "otherServiceOptionsLaden",
  "otherServiceOptionsBody", "otherServiceOptionArray",
  "otherServiceOption", "jobElement", "jobElementStart",
  "jobElementContent", "jobElementEmpty", "jobElementLaden",
  "jobElementBody", "jobElementList", "jobChild", "maxTime",
  "maxTimeStart", "maxTimeAttributes", "maxTimeContent", "maxTimeEmpty",
  "maxTimeLaden", "maxTimeBody", "maxTimeValue", "requestedStartTime",
  "requestedStartTimeStart", "requestedStartTimeContent",
  "requestedStartTimeEmpty", "requestedStartTimeLaden",
  "requestedStartTimeBody", "dependencies", "dependenciesStart",
  "dependenciesAttributes", "dependenciesContent", "dependenciesEmpty",
  "dependenciesLaden", "dependenciesList", "dependencyJobID",
  "requiredDirectories", "requiredDirectoriesStart",
  "requiredDirectoriesContent", "requiredDirectoriesEmpty",
  "requiredDirectoriesLaden", "requiredFiles", "requiredFilesStart",
  "requiredFilesContent", "requiredFilesEmpty", "requiredFilesLaden",
  "directoriesToMake", "directoriesToMakeStart",
  "directoriesToMakeContent", "directoriesToMakeEmpty",
  "directoriesToMakeLaden", "filesToMake", "filesToMakeStart",
  "filesToMakeContent", "filesToMakeEmpty", "filesToMakeLaden",
  "inputDirectoriesToMove", "inputDirectoriesToMoveStart",
  "inputDirectoriesToMoveAttributes", "inputDirectoriesToMoveContent",
  "inputDirectoriesToMoveEmpty", "inputDirectoriesToMoveLaden",
  "inputDirectoriesToMoveList", "inputDirectoryToMove", "inputFilesToMove",
  "inputFilesToMoveStart", "inputFilesToMoveAttributes",
  "inputFilesToMoveContent", "inputFilesToMoveEmpty",
  "inputFilesToMoveLaden", "inputFilesToMoveList", "inputFileToMove",
  "outputFilesToMove", "outputFilesToMoveStart",
  "outputFilesToMoveAttributes", "outputFilesToMoveContent",
  "outputFilesToMoveEmpty", "outputFilesToMoveLaden",
  "outputFilesToMoveList", "outputFileToMove", "outputDirectoriesToMove",
  "outputDirectoriesToMoveStart", "outputDirectoriesToMoveAttributes",
  "outputDirectoriesToMoveContent", "outputDirectoriesToMoveEmpty",
  "outputDirectoriesToMoveLaden", "outputDirectoriesToMoveList",
  "outputDirectoryToMove", "filesToDelete", "filesToDeleteStart",
  "filesToDeleteAttributes", "filesToDeleteContent", "filesToDeleteEmpty",
  "filesToDeleteLaden", "directoriesToDelete", "directoriesToDeleteStart",
  "directoriesToDeleteAttributes", "directoriesToDeleteContent",
  "directoriesToDeleteEmpty", "directoriesToDeleteLaden",
  "processesToKill", "processesToKillStart", "processesToKillAttributes",
  "processesToKillContent", "processesToKillEmpty", "processesToKillLaden",
  "processesToKillList", "processID", "otherJobOptions",
  "otherJobOptionsStart", "otherJobOptionsAttributes",
  "otherJobOptionsContent", "otherJobOptionsEmpty", "otherJobOptionsLaden",
  "otherJobOptionsBody", "otherJobOptionArray", "otherJobOption",
  "optimizationElement", "optimizationStart", "optimizationAttributes",
  "optimizationAttList", "optimizationATT", "optimizationContent",
  "optimizationEmpty", "optimizationLaden", "optimizationBody",
  "variables", "variablesStart", "variablesAttributes",
  "numberOfOtherVariableOptions", "variablesContent", "variablesEmpty",
  "variablesLaden", "variablesBody", "initialVariableValues",
  "initialVariableValuesStart", "initialVariableValuesAttributes",
  "initialVariableValuesContent", "initialVariableValuesEmpty",
  "initialVariableValuesLaden", "initialVariableValuesBody",
  "initVarValueArray", "initVarValue", "initVarValueStart",
  "initVarValueAttributes", "initVarValueAttList", "initVarValueAtt",
  "initVarValueContent", "initialVariableValuesString",
  "initialVariableValuesStringStart",
  "initialVariableValuesStringAttributes",
  "initialVariableValuesStringContent", "initialVariableValuesStringEmpty",
  "initialVariableValuesStringLaden", "initialVariableValuesStringBody",
  "initVarValueStringArray", "initVarValueString",
  "initVarValueStringStart", "initVarValueStringAttributes",
  "initVarValueStringAttList", "initVarValueStringAtt",
  "initVarValueStringContent", "variableInitialBasis",
  "variableInitialBasisStart", "variableInitialBasisContent",
  "variableInitialBasisEmpty", "variableInitialBasisLaden",
  "variableInitialBasisBody", "variablesBasic", "variablesAtLower",
  "variablesAtUpper", "variablesAtEquality", "variablesIsFree",
  "variablesSuperbasic", "variablesUnknown",
  "integerVariableBranchingWeights",
  "integerVariableBranchingWeightsStart",
  "integerVariableBranchingWeightsAttributes",
  "integerVariableBranchingWeightsContent",
  "integerVariableBranchingWeightsEmpty",
  "integerVariableBranchingWeightsLaden",
  "integerVariableBranchingWeightsBody", "branchingWeightsArray",
  "branchingWeight", "branchingWeightStart", "branchingWeightAttributes",
  "branchingWeightAttList", "branchingWeightAtt", "branchingWeightContent",
  "sosVariableBranchingWeights", "sosVariableBranchingWeightsStart",
  "sosVariableBranchingWeightsAttributes",
  "sosVariableBranchingWeightsContent", "sosVariableBranchingWeightsEmpty",
  "sosVariableBranchingWeightsLaden", "sosWeightGroupArray",
  "sosWeightGroup", "sosWeightGroupStart", "sosWeightGroupAttributes",
  "sosWeightGroupAttList", "sosWeightGroupAtt", "sosWeightGroupContent",
  "sosWeightGroupEmpty", "sosWeightGroupLaden",
  "otherVariableOptionsArray", "otherVariableOption",
  "otherVariableOptionStart", "otherVariableOptionAttributes",
  "otherVariableOptionAttList", "otherVariableOptionATT",
  "otherVariableOptionContent", "otherVariableOptionEmpty",
  "otherVariableOptionLaden", "otherVariableOptionBody", "otherVarList",
  "otherVar", "otherVarStart", "otherVarAttributes", "otherVarAttList",
  "otherVarAtt", "otherVarContent", "otherVarEmpty", "objectives",
  "objectivesStart", "objectivesAttributes",
  "numberOfOtherObjectiveOptions", "objectivesContent", "objectivesEmpty",
  "objectivesLaden", "objectivesBody", "initialObjectiveValues",
  "initialObjectiveValuesStart", "initialObjectiveValuesAttributes",
  "initialObjectiveValuesContent", "initialObjectiveValuesEmpty",
  "initialObjectiveValuesLaden", "initialObjectiveValuesBody",
  "initObjValueArray", "initObjValue", "initObjValueStart",
  "initObjValueAttributes", "initObjValueAttList", "initObjValueAtt",
  "initObjValueContent", "initialObjectiveBounds",
  "initialObjectiveBoundsStart", "numberOfObjATT",
  "initialObjectiveBoundsContent", "initialObjectiveBoundsEmpty",
  "initialObjectiveBoundsLaden", "initialObjectiveBoundsBody",
  "initObjBoundArray", "initObjBound", "initObjBoundStart",
  "initObjBoundAttributes", "initObjBoundAttList", "initObjBoundAtt",
  "initObjBoundContent", "objectiveInitialBasis",
  "objectiveInitialBasisStart", "objectiveInitialBasisContent",
  "objectiveInitialBasisEmpty", "objectiveInitialBasisLaden",
  "objectiveInitialBasisBody", "objectivesBasic", "objectivesAtLower",
  "objectivesAtUpper", "objectivesAtEquality", "objectivesIsFree",
  "objectivesSuperbasic", "objectivesUnknown",
  "otherObjectiveOptionsArray", "otherObjectiveOption",
  "otherObjectiveOptionStart", "otherObjectiveOptionAttributes",
  "otherObjectiveOptionAttList", "otherObjectiveOptionATT",
  "otherObjectiveOptionContent", "otherObjectiveOptionEmpty",
  "otherObjectiveOptionLaden", "otherObjectiveOptionBody", "otherObjList",
  "otherObj", "otherObjStart", "otherObjAttributes", "otherObjAttList",
  "otherObjAtt", "otherObjContent", "otherObjEmpty", "constraints",
  "constraintsStart", "constraintsAttributes",
  "numberOfOtherConstraintOptions", "constraintsContent",
  "constraintsEmpty", "constraintsLaden", "constraintsBody",
  "initialConstraintValues", "initialConstraintValuesStart",
  "initialConstraintValuesAttributes", "initialConstraintValuesContent",
  "initialConstraintValuesEmpty", "initialConstraintValuesLaden",
  "initialConstraintValuesBody", "initConValueArray", "initConValue",
  "initConValueStart", "initConValueAttributes", "initConValueAttList",
  "initConValueAtt", "initConValueContent", "initialDualValues",
  "initialDualValuesStart", "initialDualValuesAttributes",
  "initialDualValuesContent", "initialDualValuesEmpty",
  "initialDualValuesLaden", "initialDualValuesBody", "initDualValueArray",
  "initDualValue", "initDualValueStart", "initDualValueAttributes",
  "initDualValueAttList", "initDualValueAtt", "initDualValueContent",
  "slacksInitialBasis", "slacksInitialBasisStart",
  "slacksInitialBasisContent", "slacksInitialBasisEmpty",
  "slacksInitialBasisLaden", "slacksInitialBasisBody", "slacksBasic",
  "slacksAtLower", "slacksAtUpper", "slacksAtEquality", "slacksIsFree",
  "slacksSuperbasic", "slacksUnknown", "otherConstraintOptionsArray",
  "otherConstraintOption", "otherConstraintOptionStart",
  "otherConstraintOptionAttributes", "otherConstraintOptionAttList",
  "otherConstraintOptionATT", "otherConstraintOptionContent",
  "otherConstraintOptionEmpty", "otherConstraintOptionLaden",
  "otherConstraintOptionBody", "otherConList", "otherCon", "otherConStart",
  "otherConAttributes", "otherConAttList", "otherConAtt",
  "otherConContent", "otherConEmpty", "solverOptions",
  "solverOptionsStart", "numberOfSolverOptionsATT", "solverOptionsContent",
  "solverOptionsEmpty", "solverOptionsLaden", "solverOptionArray",
  "solverOption", "solverOptionStart", "solverOptionAttributes",
  "solverOptionAttList", "solverOptionATT", "solverOptionContent",
  "solverOptionEmpty", "solverOptionLaden", "solverOptionBody",
  "solverOptionItemArray", "solverOptionItem", "solverOptionItemContent",
  "solverOptionItemEmpty", "solverOptionItemLaden", "solverOptionItemBody",
  "PathList", "Path", "PathPair", "PathPairStart", "PathPairAttributes",
  "PathPairAttList", "PathPairAttribute", "PathPairFromATT",
  "PathPairToATT", "PathPairMakeCopyATT", "PathPairEnd",
  "groupWeightAttribute", "groupWeightAtt", "lbValueAttribute",
  "lbValueAtt", "lbValueAttEmpty", "lbValueAttContent",
  "lbDualValueAttribute", "lbDualValueAtt", "lbDualValueAttEmpty",
  "lbDualValueAttContent", "sosIdxAttribute", "sosIdxAtt",
  "sosIdxAttContent", "ubValueAttribute", "ubValueAtt", "ubValueAttEmpty",
  "ubValueAttContent", "ubDualValueAttribute", "ubDualValueAtt",
  "ubDualValueAttEmpty", "ubDualValueAttContent", "numberOfJobIDsATT",
  "numberOfOtherConstraintOptionsAttribute",
  "numberOfOtherObjectiveOptionsAttribute",
  "numberOfOtherOptionsAttribute", "numberOfOtherVariableOptionsAttribute",
  "numberOfPathPairsAttribute", "numberOfPathsAttribute",
  "numberOfProcessesATT", "numberOfSolverOptionsAttribute",
  "otherEnumerationList", "otherEnumeration", "otherEnumerationStart",
  "otherEnumerationAttributes", "otherEnumerationAttList",
  "otherEnumerationATT", "otherEnumerationContent",
  "otherEnumerationEmpty", "otherEnumerationLaden", "otherEnumerationBody",
  "aNumber", "quote", "xmlWhiteSpace", "xmlWhiteSpaceChar",
  "osglFileHeader", "headerElementStart", "headerElementContent",
  "headerElementEmpty", "headerElementLaden", "headerElementBody",
  "headerElementList", "headerChild", "fileName", "fileNameContent",
  "fileNameEmpty", "fileNameLaden", "fileSource", "fileSourceContent",
  "fileSourceEmpty", "fileSourceLaden", "fileDescription",
  "fileDescriptionContent", "fileDescriptionEmpty", "fileDescriptionLaden",
  "fileCreator", "fileCreatorContent", "fileCreatorEmpty",
  "fileCreatorLaden", "fileLicence", "fileLicenceContent",
  "fileLicenceEmpty", "fileLicenceLaden", "osglIntArrayData",
  "osglIntVectorElArray", "osglIntVectorEl", "osglIntVectorElStart",
  "osglIntVectorElAttributes", "osglIntVectorElAttList",
  "osglIntVectorElAtt", "osglIntVectorElContent", "osglIntVectorBase64",
  "osglIntVectorBase64Content", "osglIntVectorBase64Empty",
  "osglIntVectorBase64Laden", "osglBasisStatusBasic", "osglBasicStart",
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
  "osglUnknownBody", "osglBasisNumberOfElAttribute", "osglNumberOfConATT",
  "osglNumberOfConstraintsATT", "osglNumberOfElATT",
  "osglNumberOfEnumerationsATT", "osglNumberOfItemsATT",
  "osglNumberOfObjATT", "osglNumberOfObjectivesATT", "osglNumberOfVarATT",
  "osglNumberOfVariablesATT", "osglBase64SizeATT", "osglIdxATT",
  "osglIncrATT", "osglMultATT", "osglCategoryATT", "categoryAttEmpty",
  "categoryAttContent", "osglConTypeATT", "conTypeAttEmpty",
  "conTypeAttContent", "osglDescriptionATT", "descriptionAttEmpty",
  "descriptionAttContent", "osglEnumTypeATT", "enumTypeAttEmpty",
  "enumTypeAttContent", "osglNameATT", "nameAttEmpty", "nameAttContent",
  "osglObjTypeATT", "objTypeAttEmpty", "objTypeAttContent",
  "osglSolverATT", "solverAttEmpty", "solverAttContent", "osglTypeATT",
  "typeAttEmpty", "typeAttContent", "osglUnitATT", "unitAttEmpty",
  "unitAttContent", "osglValueATT", "valueAttEmpty", "valueAttContent",
  "osglVarTypeATT", "varTypeAttEmpty", "varTypeAttContent", 0
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
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   477,   478,   478,   479,   480,   481,   481,   482,   482,
     483,   484,   485,   486,   486,   487,   488,   488,   489,   489,
     490,   491,   491,   492,   492,   493,   494,   495,   495,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     497,   498,   499,   499,   500,   500,   501,   502,   503,   504,
     505,   505,   506,   506,   507,   508,   509,   510,   511,   511,
     512,   512,   513,   514,   515,   516,   517,   517,   518,   519,
     519,   520,   520,   521,   522,   523,   524,   525,   525,   526,
     526,   527,   528,   529,   530,   531,   531,   532,   532,   533,
     534,   535,   536,   537,   537,   538,   538,   539,   540,   541,
     542,   543,   543,   544,   544,   545,   546,   547,   548,   549,
     549,   550,   550,   551,   552,   553,   554,   555,   555,   556,
     557,   557,   558,   558,   559,   560,   561,   562,   563,   564,
     564,   565,   565,   566,   567,   568,   568,   569,   570,   571,
     572,   572,   573,   573,   573,   574,   574,   575,   575,   576,
     577,   577,   578,   578,   579,   580,   581,   581,   582,   582,
     582,   582,   582,   583,   584,   585,   586,   586,   587,   587,
     588,   589,   590,   591,   592,   593,   593,   594,   594,   595,
     596,   597,   598,   599,   600,   600,   601,   601,   602,   603,
     604,   605,   606,   606,   607,   608,   609,   610,   611,   612,
     612,   613,   613,   614,   615,   616,   616,   617,   618,   618,
     619,   620,   620,   621,   621,   622,   623,   624,   624,   625,
     625,   626,   627,   628,   628,   629,   629,   630,   631,   632,
     633,   634,   635,   635,   636,   636,   637,   638,   639,   639,
     640,   641,   641,   642,   643,   643,   644,   644,   645,   646,
     647,   647,   648,   648,   648,   648,   648,   648,   648,   648,
     648,   648,   648,   648,   648,   648,   648,   649,   650,   651,
     651,   652,   652,   653,   653,   654,   655,   656,   657,   658,
     659,   659,   660,   660,   661,   662,   663,   664,   665,   666,
     666,   667,   667,   668,   669,   669,   670,   671,   672,   673,
     673,   674,   674,   675,   676,   677,   678,   678,   679,   679,
     680,   681,   682,   683,   683,   684,   684,   685,   686,   687,
     688,   688,   689,   689,   690,   691,   692,   693,   694,   694,
     695,   695,   696,   697,   697,   698,   699,   700,   701,   702,
     702,   703,   703,   704,   705,   705,   706,   707,   708,   709,
     710,   710,   711,   711,   712,   713,   713,   714,   715,   716,
     717,   718,   718,   719,   719,   720,   721,   721,   722,   723,
     724,   725,   726,   726,   727,   727,   728,   729,   730,   731,
     732,   732,   733,   733,   734,   735,   736,   737,   738,   738,
     739,   739,   740,   741,   741,   742,   743,   744,   745,   746,
     746,   747,   747,   748,   749,   750,   750,   751,   752,   752,
     753,   754,   755,   755,   756,   756,   756,   757,   757,   758,
     759,   760,   761,   761,   762,   763,   764,   764,   765,   765,
     766,   767,   768,   769,   769,   770,   771,   772,   772,   773,
     773,   774,   775,   776,   776,   777,   778,   779,   780,   780,
     781,   781,   781,   782,   782,   783,   783,   784,   785,   786,
     786,   787,   787,   788,   789,   790,   790,   791,   792,   793,
     794,   794,   795,   795,   795,   796,   796,   797,   797,   798,
     799,   799,   800,   801,   802,   803,   803,   804,   804,   805,
     805,   806,   806,   807,   807,   808,   808,   809,   809,   810,
     810,   811,   812,   813,   813,   814,   814,   815,   816,   817,
     817,   818,   819,   820,   821,   821,   822,   822,   822,   823,
     823,   824,   824,   825,   826,   827,   827,   828,   828,   829,
     830,   830,   831,   832,   833,   834,   834,   835,   835,   835,
     836,   836,   837,   837,   838,   839,   839,   840,   841,   842,
     843,   843,   844,   844,   844,   844,   844,   844,   844,   844,
     844,   844,   845,   845,   846,   846,   847,   848,   848,   849,
     849,   850,   851,   852,   853,   853,   854,   854,   854,   854,
     854,   855,   856,   856,   857,   857,   858,   859,   860,   860,
     861,   861,   862,   863,   864,   865,   865,   866,   867,   868,
     868,   869,   869,   870,   871,   872,   872,   873,   874,   875,
     876,   876,   877,   877,   877,   878,   878,   879,   879,   880,
     881,   882,   882,   883,   883,   884,   885,   886,   886,   887,
     888,   889,   890,   890,   891,   891,   891,   891,   892,   892,
     893,   893,   894,   895,   895,   896,   897,   898,   899,   899,
     900,   900,   901,   901,   902,   902,   903,   903,   904,   904,
     905,   905,   906,   906,   907,   908,   909,   910,   910,   911,
     911,   911,   911,   911,   911,   911,   911,   911,   911,   912,
     912,   913,   913,   914,   915,   915,   916,   916,   917,   918,
     919,   920,   920,   921,   921,   921,   921,   921,   922,   923,
     923,   924,   924,   925,   926,   927,   927,   928,   928,   929,
     930,   931,   932,   932,   933,   934,   935,   935,   936,   936,
     937,   938,   939,   939,   940,   941,   942,   943,   943,   944,
     944,   944,   945,   945,   946,   946,   947,   948,   949,   949,
     950,   950,   951,   952,   953,   953,   954,   955,   956,   957,
     957,   958,   958,   958,   958,   959,   959,   960,   960,   961,
     962,   962,   963,   964,   965,   966,   966,   967,   967,   968,
     968,   969,   969,   970,   970,   971,   971,   972,   972,   973,
     973,   974,   975,   976,   977,   977,   978,   978,   978,   978,
     978,   978,   978,   978,   978,   978,   979,   979,   980,   980,
     981,   982,   982,   983,   983,   984,   985,   986,   987,   987,
     988,   988,   988,   988,   988,   989,   990,   990,   991,   991,
     992,   993,   994,   994,   995,   996,   997,   997,   998,   999,
    1000,  1001,  1001,  1002,  1002,  1002,  1002,  1002,  1002,  1002,
    1003,  1003,  1004,  1004,  1005,  1006,  1007,  1007,  1008,  1009,
    1009,  1010,  1010,  1011,  1012,  1013,  1013,  1014,  1015,  1016,
    1017,  1018,  1018,  1019,  1019,  1019,  1020,  1021,  1022,  1023,
    1023,  1024,  1025,  1026,  1027,  1027,  1028,  1029,  1030,  1031,
    1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1038,  1039,
    1040,  1041,  1042,  1042,  1043,  1044,  1045,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,  1054,  1054,  1055,  1056,  1057,
    1058,  1058,  1059,  1059,  1059,  1060,  1060,  1061,  1062,  1063,
    1064,  1064,  1065,  1066,  1066,  1067,  1067,  1067,  1067,  1068,
    1069,  1070,  1070,  1071,  1072,  1073,  1074,  1074,  1075,  1075,
    1075,  1075,  1075,  1076,  1077,  1077,  1078,  1078,  1079,  1080,
    1081,  1081,  1082,  1082,  1083,  1084,  1085,  1085,  1086,  1086,
    1087,  1088,  1089,  1089,  1090,  1090,  1091,  1092,  1093,  1093,
    1094,  1094,  1095,  1096,  1096,  1097,  1097,  1098,  1099,  1100,
    1101,  1101,  1102,  1102,  1103,  1104,  1105,  1105,  1106,  1106,
    1107,  1108,  1109,  1110,  1110,  1111,  1112,  1113,  1114,  1115,
    1116,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1122,  1123,
    1124,  1125,  1126,  1127,  1128,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1140,
    1141,  1142,  1143,  1144,  1145,  1146,  1146,  1147,  1148,  1149,
    1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,
    1160,  1161,  1162,  1163,  1164,  1164,  1165,  1166,  1167,  1167,
    1168,  1169,  1170,  1170,  1171,  1172,  1173,  1173,  1174,  1175,
    1176,  1176,  1177,  1178,  1179,  1179,  1180,  1181,  1182,  1182,
    1183,  1184,  1185,  1185,  1186,  1187,  1188,  1188,  1189,  1190,
    1191,  1191,  1192,  1193,  1194,  1194,  1195,  1196
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     1,     0,     6,     0,     1,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     0,     1,     3,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     3,     1,     0,     1,     3,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     1,     0,     2,     1,     1,     3,
       1,     3,     1,     1,     0,     2,     1,     1,     3,     1,
       3,     1,     0,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     0,     2,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     0,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     4,     3,     1,     1,
       1,     2,     1,     3,     3,     1,     1,     1,     2,     1,
       3,     3,     1,     1,     1,     2,     1,     3,     3,     1,
       1,     1,     2,     1,     3,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     3,     1,     1,
       1,     1,     2,     1,     3,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     4,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     0,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     0,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     6,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     1,     3,     7,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     2,
       1,     0,     3,     1,     4,     1,     1,     2,     1,     3,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     2,     1,     3,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     0,     3,     1,     1,     0,     1,
       1,     1,     1,     3,     4,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     2,     1,
       0,     2,     1,     1,     1,     1,     3,     7,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     3,     1,     1,     0,     1,     1,     1,     1,
       3,     4,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     1,     3,     7,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     0,     2,     3,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     4,     3,     1,
       1,     0,     2,     1,     1,     1,     3,     3,     3,     2,
       1,     1,     4,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     4,     1,     1,     4,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     2,     0,     2,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     3,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     3,     3,     1,     1,     2,     1,
       3,     3,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,   930,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   147,     0,
     936,   933,   929,   931,   932,    16,    10,     3,     8,     9,
     149,   208,     0,     0,    24,    19,    21,    22,     0,   935,
      14,   210,   241,     0,     0,   153,   148,   150,   151,    65,
      84,    92,   100,   108,   116,   127,    23,    41,    49,    57,
      76,     0,    26,    27,    29,     0,    30,     0,    31,     0,
      32,    66,    33,     0,    34,     0,    35,     0,    36,     0,
      37,     0,    38,   117,    39,     0,   934,     0,   947,   946,
       0,   953,   952,     0,   959,   958,     0,   965,   964,     0,
     971,   970,   937,   938,   943,   944,   945,   939,   949,   950,
     951,   940,   955,   956,   957,   941,   961,   962,   963,   942,
     967,   968,   969,    11,   243,   408,     0,     0,   214,   209,
     211,   212,   164,   173,   182,   191,   197,   152,     0,   155,
     156,   158,   166,   159,   175,   160,   184,   161,   192,   162,
       0,    25,    28,     0,    45,    40,    42,    43,     0,    53,
      48,    50,    51,     0,    61,    56,    58,    59,     0,     0,
      67,     0,    80,    75,    77,    78,     0,    88,    83,    85,
      86,     0,    96,    91,    93,    94,     0,   104,    99,   101,
     102,     0,   112,   107,   109,   110,     0,     0,   118,   923,
       0,   128,     0,     0,     0,     0,     0,   410,    15,   412,
       0,   247,   242,   244,   245,   222,   230,   213,     0,   216,
     217,   219,     0,   220,     0,   154,   157,     0,   165,     0,
     174,     0,   183,  1064,     0,     0,   193,  1062,  1063,     0,
     198,    47,    44,     0,    55,    52,     0,    63,    60,     0,
       0,     0,    72,    64,    69,    70,    82,    79,     0,    90,
      87,     0,    98,    95,     0,   106,   103,     0,   114,   111,
       0,     0,     0,   123,   115,   120,   121,     0,     0,     0,
     132,   126,   129,   130,   948,   954,   960,   966,   972,     0,
     411,   268,   279,   287,   298,   305,   312,   319,   378,   370,
     326,   337,   359,   348,   386,   397,   246,     0,   249,   250,
     252,   269,   253,     0,   254,     0,   255,     0,   256,     0,
     257,     0,   258,     0,   259,     0,   260,     0,   262,     0,
     261,     0,   263,     0,   264,     0,   265,     0,   266,     0,
     215,   218,     0,   226,   221,   223,   224,     0,   231,     0,
     163,  1088,     0,   167,   169,   168,  1086,  1087,     0,   172,
     176,   178,   177,     0,   181,   185,   187,   186,     0,     0,
     190,     0,   202,   196,   199,   200,    46,    54,    62,    68,
      74,    71,     0,    81,    89,    97,   105,   113,   119,   125,
     122,     0,   923,   922,   925,   926,   927,   928,   924,   131,
     138,     0,   134,   135,   140,   422,   419,   409,   417,   418,
       0,     0,     0,   413,   415,   416,   414,   248,   251,     0,
     270,     0,   283,   278,   280,   281,     0,     0,   288,     0,
       0,     0,     0,     0,     0,     0,   327,     0,   338,     0,
     349,     0,   360,     0,   371,     0,   379,     0,     0,   387,
       0,   398,   228,   225,     0,     0,   235,   229,   232,   233,
     920,   921,     0,   171,     0,     0,   180,     0,   189,  1065,
     195,     0,   201,   140,     0,   204,   205,    73,   124,   899,
     133,   136,     0,   139,   424,     0,   584,   426,     0,     0,
       0,     0,   274,   267,   271,   272,   285,   282,     0,     0,
       0,   292,   286,   289,   290,     0,     0,   302,   297,   299,
     300,     0,   309,   304,   306,   307,     0,   316,   311,   313,
     314,     0,   323,   318,   320,   321,     0,     0,   331,   325,
     328,   329,     0,   342,   336,   339,   340,     0,   353,   347,
     350,   351,     0,   364,   358,   361,   362,     0,   375,   369,
     372,   373,     0,   383,   377,   380,   381,     0,     0,   391,
     385,   388,   389,     0,   402,   396,   399,   400,   227,   234,
     140,     0,   237,   238,   170,  1089,   179,   188,   194,     0,
     203,   206,     0,   146,   137,  1072,     0,  1092,     0,   141,
     144,   142,  1070,  1071,   143,  1090,  1091,   420,   586,   701,
     588,   923,     0,   425,   427,     0,     0,     0,   273,     0,
     276,   277,   284,     0,   291,     0,     0,   294,     0,     0,
     301,     0,   855,   308,     0,   315,     0,   322,     0,     0,
     859,   330,     0,   333,   335,   861,   341,     0,   344,   346,
     352,     0,   355,   357,   363,     0,   366,   368,   374,     0,
     382,     0,     0,   390,     0,     0,   393,   401,   140,     0,
     404,   405,     0,   236,   239,   207,   145,     0,     0,   703,
     818,   705,   923,     0,   587,   589,     0,   433,   430,   423,
     428,   429,  1042,  1047,  1049,   275,   896,     0,   293,   295,
     902,     0,   303,   856,   310,   317,   324,   901,   332,   334,
       0,   860,   343,   345,   354,   356,   365,   367,   376,   384,
     903,     0,   392,   394,     0,   403,   406,   240,  1073,  1093,
     820,   421,     0,   923,     0,   704,   706,     0,   595,   592,
     585,   590,   591,   923,   435,     0,   455,     0,     0,     0,
       0,   870,   858,     0,     0,     0,   862,   863,   864,   865,
       0,   407,   923,     0,   821,     0,   712,   709,   702,   707,
     708,   923,   597,     0,   617,     0,   900,   431,   457,   477,
       0,     0,     0,   436,   296,   857,   869,     0,     0,     0,
     395,     0,   826,   824,   819,   822,   823,   923,   714,     0,
     734,     0,   898,   593,   619,   640,     0,     0,     0,   598,
     479,   499,     0,     0,   458,     0,     0,   440,   434,   437,
     438,   866,   867,   868,   923,     0,   897,   710,   736,   757,
       0,     0,     0,   715,   642,   662,     0,     0,   620,     0,
       0,   602,   596,   599,   600,   501,   521,     0,   485,   482,
     478,   480,   481,     0,   462,   456,   459,   460,     0,   439,
     446,     0,   442,   443,   448,   904,   825,   829,   827,     0,
     759,   779,     0,     0,   737,     0,     0,   719,   713,   716,
     717,   594,   648,   645,   641,   643,   644,     0,   624,   618,
     621,   622,     0,   601,   608,     0,   604,   605,   610,   523,
     545,     0,     0,   502,   992,     0,   487,   486,     0,   461,
     468,     0,   464,   465,   470,  1048,   441,   444,     0,   447,
       0,  1056,     0,  1080,     0,  1084,     0,     0,   830,   831,
     839,   836,  1054,  1055,   838,   833,   835,  1078,  1079,   837,
    1082,  1083,   834,   711,   765,   762,   758,   760,   761,     0,
     741,   735,   738,   739,     0,   718,   725,     0,   721,   722,
     727,   665,   663,   667,     0,   650,   649,   623,   630,     0,
     626,   627,   632,  1046,   603,   606,     0,   609,   432,     0,
       0,     0,   506,   500,   503,   504,   483,   999,   489,   488,
       0,     0,     0,  1040,   463,   466,     0,   469,     0,   454,
     445,     0,   449,   450,   451,   452,     0,     0,     0,     0,
       0,   843,   828,   840,   841,   832,   782,   780,   784,     0,
     767,   766,   740,   747,     0,   743,   744,   749,  1041,   720,
     723,     0,   726,     0,   666,   646,   652,   651,   625,   628,
       0,   631,     0,   616,   607,   611,   612,   613,   614,   548,
     546,   550,     0,     0,   528,   522,   525,   526,   505,   512,
       0,   508,   509,   514,  1006,   491,   490,     0,     0,     0,
     975,   995,   991,   993,   994,     0,   476,   467,   471,   472,
     473,   474,   453,     0,     0,  1057,  1081,  1085,   842,   852,
       0,   851,     0,   845,   846,   848,   849,   850,     0,   783,
     763,   769,   768,   742,   745,     0,   748,     0,   733,   724,
     728,   729,   730,   731,     0,   682,   664,   679,   680,     0,
    1068,     0,  1076,     0,   668,   670,   669,   674,   678,   677,
    1066,  1067,   671,   676,  1074,  1075,   673,   675,   672,   654,
     653,     0,   639,   629,   876,   889,     0,     0,   633,   636,
     873,   874,   875,   637,   886,   887,   888,   634,   635,   615,
       0,   549,     0,   527,   533,     0,   530,   535,   507,   510,
       0,   513,  1013,   493,   492,     0,     0,   975,  1002,   998,
    1000,  1001,     0,     0,   997,   973,   974,     0,   475,     0,
    1045,   854,     0,   844,   847,     0,   799,   781,   796,   797,
    1060,     0,   785,   786,   787,   791,   793,  1058,  1059,   795,
     794,   788,   790,   792,   789,   771,   770,     0,   756,   746,
     881,   894,   923,   923,   750,   753,   878,   879,   880,   754,
     891,   892,   893,   751,   752,   732,   908,   689,   681,     0,
     684,   686,   691,   685,   905,   910,     0,     0,     0,   656,
     655,   638,   923,   923,     0,   565,   547,   562,   563,  1096,
       0,   551,   553,   552,   557,   561,   560,   554,   556,   558,
     555,   559,  1094,  1095,   524,   529,   531,     0,   534,     0,
     520,   511,   515,   516,   517,   518,  1020,   495,   494,     0,
       0,   975,  1009,  1005,  1007,  1008,  1004,     0,  1043,     0,
       0,   978,   976,   980,   996,  1051,   853,   806,   798,     0,
     801,   803,   808,   802,     0,   773,   772,   755,     0,     0,
     683,   687,     0,   690,   906,     0,   909,     0,  1069,  1077,
     658,   657,   877,   890,   572,   564,     0,   567,   569,   574,
     568,     0,     0,   543,   532,   540,   541,   923,     0,   536,
     539,   871,   537,   883,   884,   538,   519,  1027,   497,   496,
       0,     0,   975,  1016,  1012,  1014,  1015,  1011,     0,  1003,
       0,     0,   989,   985,   986,   987,     0,   979,   800,   804,
       0,   807,  1061,   775,   774,   923,   923,     0,   700,   688,
     698,   692,   696,   697,   693,   694,   695,   975,   917,   907,
     915,   916,   911,   912,   914,   913,  1044,   660,   659,   566,
     570,     0,   573,  1097,   542,     0,     0,     0,  1034,   484,
     498,     0,     0,   975,  1023,  1019,  1021,  1022,  1018,     0,
    1010,     0,     0,   988,     0,   977,     0,     0,   981,   983,
     982,     0,   817,   805,   815,   809,   813,   814,   810,   811,
     812,   777,   776,   882,   895,   699,     0,   919,   647,   661,
       0,   583,   571,   581,   575,   579,   580,   576,   577,   578,
     544,   923,     0,     0,   975,  1030,  1026,  1028,  1029,  1025,
       0,  1017,  1050,   990,     0,     0,     0,   816,   764,   778,
     918,   582,   885,   872,   975,  1037,  1033,  1035,  1036,  1032,
       0,  1024,   984,     0,     0,  1039,     0,  1031,  1052,  1053,
    1038
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    27,    28,    29,    15,    16,
       8,     9,    18,    19,    35,    36,    37,    61,    62,    63,
      64,    65,   155,   156,   157,   243,    66,    67,   160,   161,
     162,   246,    68,    69,   165,   166,   167,   249,    70,    71,
     169,   170,   253,   254,   255,   382,    72,    73,   173,   174,
     175,   258,    74,    75,   178,   179,   180,   261,    76,    77,
     183,   184,   185,   264,    78,    79,   188,   189,   190,   267,
      80,    81,   193,   194,   195,   270,    82,    83,   197,   198,
     274,   275,   276,   391,    84,    85,   200,   281,   282,   283,
     401,   402,   403,   404,   482,   483,   589,   584,    31,    32,
      46,    47,    48,   138,   139,   140,   141,   142,   227,   228,
     353,   350,   462,   143,   144,   229,   230,   360,   359,   465,
     145,   146,   231,   232,   365,   364,   467,   147,   148,   235,
     370,   471,   149,   150,   239,   373,   374,   375,   474,   475,
     476,    42,    43,   129,   130,   131,   218,   219,   220,   221,
     222,   344,   345,   346,   454,   223,   224,   347,   457,   458,
     459,   571,   572,   573,   125,   126,   212,   213,   214,   307,
     308,   309,   310,   311,   419,   493,   494,   495,   609,   610,
     312,   313,   423,   424,   425,   498,   314,   315,   427,   502,
     503,   504,   616,   617,   316,   317,   508,   509,   510,   318,
     319,   513,   514,   515,   320,   321,   518,   519,   520,   322,
     323,   523,   524,   525,   324,   325,   435,   529,   530,   531,
     632,   633,   326,   327,   437,   534,   535,   536,   637,   638,
     328,   329,   439,   539,   540,   541,   641,   642,   330,   331,
     441,   544,   545,   546,   645,   646,   332,   333,   443,   549,
     550,   551,   334,   335,   445,   554,   555,   556,   336,   337,
     448,   560,   561,   562,   655,   656,   338,   339,   450,   565,
     566,   567,   659,   660,   661,   208,   209,   289,   290,   413,
     407,   408,   409,   485,   486,   487,   602,   603,   679,   680,
     681,   735,   736,   737,   772,   808,   809,   810,   851,   852,
     853,   854,   908,   909,   992,   990,   769,   770,   803,   845,
     846,   847,   901,   902,   903,   904,   986,   987,  1068,  1067,
     801,   802,   840,   841,   842,   895,   896,   978,  1055,  1163,
    1277,  1348,  1409,   836,   837,   892,   973,   974,   975,  1050,
    1051,  1052,  1053,  1160,  1161,  1272,  1271,   890,   891,   970,
    1045,  1046,  1047,  1155,  1156,  1157,  1267,  1268,  1339,  1334,
    1335,  1336,   968,  1040,  1041,  1150,  1151,  1251,  1246,  1247,
    1248,  1326,  1327,  1328,  1329,  1401,  1402,  1454,  1452,  1453,
     599,   600,   673,   674,   730,   731,   732,   763,   764,   765,
     798,   832,   833,   834,   885,   886,   887,   888,   966,   967,
    1035,  1034,   795,   796,   827,   879,   880,   881,   959,   960,
     961,   962,  1030,  1031,  1138,  1133,   825,   826,   874,   875,
     876,   954,   955,  1026,  1129,  1239,  1320,  1397,  1448,   871,
     952,   953,  1023,  1024,  1114,  1106,  1107,  1108,  1229,  1230,
    1231,  1232,  1312,  1313,  1381,  1379,  1380,   670,   671,   724,
     725,   758,   759,   760,   789,   790,   791,   822,   868,   869,
     870,   947,   948,   949,   950,  1021,  1022,  1100,  1099,   819,
     820,   863,   941,   942,   943,  1014,  1015,  1016,  1017,  1095,
    1096,  1214,  1209,   861,   862,   936,   937,   938,  1009,  1010,
    1091,  1205,  1305,  1373,  1441,  1478,   933,  1007,  1008,  1088,
    1089,  1192,  1187,  1188,  1189,  1299,  1300,  1301,  1302,  1370,
    1371,  1435,  1433,  1434,   721,   722,   753,   784,   785,   786,
     815,   858,   859,   917,   918,   919,  1002,  1003,  1004,  1082,
    1083,  1084,  1085,  1086,  1087,  1182,   621,   622,   634,   635,
     700,   701,   746,   747,   748,   749,   742,  1340,  1341,  1139,
    1140,  1141,  1142,  1215,  1216,  1217,  1218,  1342,  1343,  1344,
    1143,  1144,  1145,  1146,  1219,  1220,  1221,  1222,   428,   726,
     675,   201,   604,   436,   430,   449,   754,  1233,  1234,  1235,
    1315,  1316,  1392,  1389,  1390,  1391,  1446,   463,   277,   278,
     398,    10,    11,    22,    23,    24,    38,    39,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,  1174,
    1175,  1292,  1293,  1366,  1367,  1428,  1425,  1176,  1363,  1364,
    1365,   897,   898,  1062,  1063,  1064,  1177,   979,   980,  1169,
    1170,  1171,  1287,  1056,  1057,  1283,  1284,  1285,  1358,  1164,
    1165,  1354,  1355,  1356,  1419,  1278,  1279,  1415,  1416,  1417,
    1470,  1349,  1350,  1466,  1467,  1468,  1490,  1410,  1411,  1486,
    1487,  1488,  1496,   982,   823,   414,   983,  1115,   920,   799,
     415,   773,   416,  1290,   993,  1429,  1430,   921,   922,   923,
    1196,  1197,  1198,   924,   237,   238,  1119,  1120,  1121,   925,
     592,   593,  1123,  1124,  1125,   926,   927,   928,   929,   930,
     931,   355,   356,   357,   932,   595,   596,  1261,  1262,  1263
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1257
static const yytype_int16 yypact[] =
{
     317, -1257, -1257,   156,    22,   202, -1257, -1257,   203,   -64,
   -1257,   337, -1257,   383, -1257, -1257, -1257, -1257,   -72,   403,
   -1257, -1257, -1257, -1257, -1257,    22, -1257, -1257, -1257, -1257,
   -1257,   -17,   407,   -29, -1257, -1257, -1257, -1257,   178,   424,
     203, -1257,   -12,   415,   -22, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257,     2,   -24, -1257, -1257,   420, -1257,   422, -1257,   425,
   -1257,   292, -1257,   429, -1257,   431, -1257,   434, -1257,   436,
   -1257,   438, -1257,   299, -1257,   284, -1257,   323, -1257, -1257,
     331, -1257, -1257,   335, -1257, -1257,   339, -1257, -1257,   351,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257,    39,   454,   -32, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,    51,    60,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   298, -1257,
     284, -1257, -1257,    10, -1257, -1257, -1257, -1257,     9, -1257,
   -1257, -1257, -1257,     8, -1257, -1257, -1257, -1257,   373,   466,
   -1257,     7, -1257, -1257, -1257, -1257,   159, -1257, -1257, -1257,
   -1257,   150, -1257, -1257, -1257, -1257,   146, -1257, -1257, -1257,
   -1257,   124, -1257, -1257, -1257, -1257,   377,   468, -1257, -1257,
     470, -1257,   253,   251,   255,   247,   245, -1257, -1257, -1257,
     -31, -1257, -1257, -1257, -1257, -1257, -1257, -1257,    79,    62,
   -1257, -1257,   472, -1257,   284, -1257, -1257,   386,   177,   401,
     177,   409,   177, -1257,   419,   417, -1257, -1257, -1257,   474,
   -1257, -1257, -1257,    95, -1257, -1257,    96, -1257, -1257,   157,
     502,   166, -1257, -1257, -1257, -1257, -1257, -1257,   160, -1257,
   -1257,   494, -1257, -1257,   501, -1257, -1257,   510, -1257, -1257,
     516,   545,   135, -1257, -1257, -1257, -1257,   559,    -2,   -83,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   478,
     142, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257,   293,   297, -1257,
   -1257,   310, -1257,   482, -1257,   661, -1257,   663, -1257,   663,
   -1257,   663, -1257,   663, -1257,   660, -1257,   660, -1257,   660,
   -1257,   660, -1257,   663, -1257,   663, -1257,   665, -1257,   284,
   -1257, -1257,   129, -1257, -1257, -1257, -1257,   484, -1257,   491,
   -1257, -1257,   692, -1257, -1257, -1257, -1257, -1257,   491, -1257,
   -1257, -1257, -1257,   491, -1257, -1257, -1257, -1257,   689,   693,
   -1257,   -82, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257,   653, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257,   647, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257,   578,   354, -1257, -1257,   391, -1257, -1257, -1257, -1257,
     697,   698,   699, -1257, -1257, -1257, -1257, -1257, -1257,   488,
   -1257,   103, -1257, -1257, -1257, -1257,   700,   493, -1257,   701,
     512,   514,   518,   522,   702,   524, -1257,   526, -1257,   528,
   -1257,   535, -1257,   537, -1257,   572, -1257,   703,   574, -1257,
     576, -1257, -1257, -1257,   649,   -81, -1257, -1257, -1257, -1257,
   -1257, -1257,   655, -1257,   705,   657, -1257,   659, -1257, -1257,
   -1257,   667, -1257, -1257,   593,   354, -1257, -1257, -1257, -1257,
   -1257, -1257,   580,   102, -1257,   393,   410,   679,   715,   716,
     717,   125, -1257, -1257, -1257, -1257, -1257, -1257,   669,   718,
     -53, -1257, -1257, -1257, -1257,   719,   144, -1257, -1257, -1257,
   -1257,    74, -1257, -1257, -1257, -1257,    77, -1257, -1257, -1257,
   -1257,   211, -1257, -1257, -1257, -1257,   720,   138, -1257, -1257,
   -1257, -1257,    71, -1257, -1257, -1257, -1257,    69, -1257, -1257,
   -1257, -1257,    68, -1257, -1257, -1257, -1257,    64, -1257, -1257,
   -1257, -1257,    75, -1257, -1257, -1257, -1257,   721,   496, -1257,
   -1257, -1257, -1257,   -79, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257,   603,   354, -1257, -1257, -1257, -1257, -1257, -1257,   580,
   -1257, -1257,   381, -1257, -1257, -1257,   728, -1257,   729, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   428,
     704, -1257,   584, -1257, -1257,   726,   727,   731, -1257,   670,
   -1257, -1257, -1257,   732, -1257,   725,   -44, -1257,   734,   733,
   -1257,   234, -1257, -1257,   141, -1257,   227, -1257,   212,   735,
   -1257, -1257,   148, -1257, -1257, -1257, -1257,    78, -1257, -1257,
   -1257,    70, -1257, -1257, -1257,    81, -1257, -1257, -1257,   168,
   -1257,   205,   737, -1257,   736,   500, -1257, -1257, -1257,   621,
     354, -1257,   580, -1257, -1257, -1257, -1257,   740,   741, -1257,
     631,   712, -1257,   588, -1257, -1257,   746,   671, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257,   749, -1257, -1257,
   -1257,   750, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
     590,   249, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257,   751, -1257, -1257,   580, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257,   722, -1257,   592, -1257, -1257,   752,   645, -1257,
   -1257, -1257, -1257, -1257, -1257,   442,   672,   540,   414,   690,
     687, -1257, -1257,   761,   762,   763, -1257, -1257, -1257, -1257,
     673, -1257, -1257,   594, -1257,   764,   651, -1257, -1257, -1257,
   -1257, -1257, -1257,   458,   675,   553, -1257, -1257, -1257,   677,
     540,   765,   596, -1257, -1257, -1257, -1257,   767,   768,   769,
   -1257,   772, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   473,
     681,   567, -1257, -1257, -1257,   682,   553,   774,   600, -1257,
   -1257,   684,   602,   606, -1257,   777,   -51, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257,   498, -1257, -1257, -1257,   683,
     567,   776,   610, -1257, -1257, -1257,   612,   614, -1257,   779,
     -34, -1257, -1257, -1257, -1257, -1257,   685,   540,   457, -1257,
   -1257, -1257, -1257,   -55, -1257, -1257, -1257, -1257,   783, -1257,
   -1257,   691,   483, -1257, -1257, -1257, -1257, -1257, -1257,   406,
   -1257, -1257,   616,   618, -1257,   789,   -36, -1257, -1257, -1257,
   -1257,   449,   457, -1257, -1257, -1257, -1257,   -25, -1257, -1257,
   -1257, -1257,   790, -1257, -1257,   688,   490, -1257, -1257, -1257,
   -1257,   759,   620, -1257, -1257,   706,   475, -1257,   639, -1257,
   -1257,   707,   495, -1257, -1257, -1257, -1257, -1257,   622,   -60,
     796, -1257,   802, -1257,   804, -1257,   805,   624,   406, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257,   462,   457, -1257, -1257, -1257, -1257,   -45,
   -1257, -1257, -1257, -1257,   806, -1257, -1257,   695,   513, -1257,
   -1257, -1257, -1257, -1257,   708,   475, -1257, -1257, -1257,   709,
     508, -1257, -1257, -1257, -1257, -1257,   626,   -60,   471,   809,
     628,   -41, -1257, -1257, -1257, -1257, -1257, -1257,   497, -1257,
     639,   811,   630, -1257, -1257, -1257,   632,   -60,   511, -1257,
   -1257,   812, -1257, -1257, -1257, -1257,   819,   820,   821,   822,
      85, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   730,
     475, -1257, -1257, -1257,   713,   533, -1257, -1257, -1257, -1257,
   -1257,   634,   -60,   636,   286, -1257,   497, -1257, -1257, -1257,
     638,    50,   519, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257,   825,   542, -1257, -1257, -1257, -1257, -1257, -1257,
     738,   527, -1257, -1257, -1257,   515, -1257,   639,   642,   833,
     686, -1257, -1257, -1257, -1257,   529, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257,   836,   835, -1257, -1257, -1257, -1257, -1257,
     839, -1257,   723,   213, -1257, -1257, -1257, -1257,   644,   344,
   -1257,   497, -1257, -1257, -1257,   646,    65,   543, -1257, -1257,
   -1257, -1257, -1257, -1257,  -100, -1257, -1257, -1257, -1257,   841,
   -1257,   847, -1257,   850, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   515,
   -1257,   546, -1257, -1257, -1257, -1257,   852,   853, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
     648,   233,   849, -1257, -1257,   552, -1257, -1257, -1257, -1257,
     652,   -60, -1257,   525, -1257,   639,   654,   686, -1257, -1257,
   -1257, -1257,   851,   619, -1257,   710, -1257,   530, -1257,   855,
   -1257, -1257,   711, -1257, -1257,   -98, -1257, -1257, -1257, -1257,
   -1257,   857, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257,   515, -1257,   561, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   520,
     560, -1257, -1257,   714, -1257, -1257,   860,   861,   864,   525,
   -1257, -1257, -1257, -1257,   -85, -1257, -1257, -1257, -1257, -1257,
     870, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257,   656,    55,   562,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257,   544, -1257,   639,
     658,   686, -1257, -1257, -1257, -1257, -1257,   547, -1257,   869,
     662, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   532,
     575, -1257, -1257,   714,   873,   525, -1257, -1257,   491,   491,
   -1257, -1257,   664,    58, -1257,   666,    45,   874, -1257, -1257,
     544, -1257, -1257, -1257, -1257, -1257,   536,   577, -1257, -1257,
     714,   875,   -59, -1257, -1257, -1257, -1257, -1257,   877, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   549, -1257,
     639,   668,   686, -1257, -1257, -1257, -1257, -1257,   557, -1257,
     883,    90, -1257, -1257, -1257, -1257,   879,   443, -1257, -1257,
     674,    58, -1257,   544, -1257, -1257, -1257,   585, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257,   686, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257,   549, -1257, -1257,
   -1257,   676,    58, -1257, -1257,   -57,   888,   491, -1257, -1257,
   -1257,   639,   678,   686, -1257, -1257, -1257, -1257, -1257,   569,
   -1257,   889,   739, -1257,   890, -1257,   891,   892, -1257, -1257,
   -1257,   597, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257,   549, -1257, -1257, -1257, -1257,   747, -1257, -1257, -1257,
     586, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257,   895,   680,   686, -1257, -1257, -1257, -1257, -1257,
     571, -1257, -1257, -1257,   753,   900,   901, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257,   686, -1257, -1257, -1257, -1257, -1257,
     573, -1257, -1257,   902,   903, -1257,   579, -1257, -1257, -1257,
   -1257
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   872, -1257,
     893, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   854,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257,   517,  -338,  -411, -1257, -1257,  -496, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257,   775, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
     440, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   694, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257,   348, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257,   613, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257,   308, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257,   294, -1257, -1257, -1257, -1257, -1257, -1257, -1257,   288,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257,   287, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257,   282, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257,   274, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257,   270, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
      80, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257,    29, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
    -399, -1041, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257,  -221, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257,  -392, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257,    52, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
     -23, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
    -294, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257,    -9, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257,   -75, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257,  -358, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257,    25, -1257, -1257, -1257, -1257,
   -1257,  -139, -1257, -1257, -1257, -1257,  -218,  -283,  -441, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1214,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1204, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257,   -90, -1257,   -70,     4, -1257, -1257, -1066, -1128, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257,  -356,  -391, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1151,
   -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257, -1257,
   -1257,  -751, -1257, -1257, -1257, -1257, -1257,  -815, -1257, -1257,
   -1257, -1257, -1257,  -915, -1257, -1257, -1257, -1257, -1257, -1025,
   -1257, -1257, -1257, -1257, -1257, -1124, -1257, -1257, -1257, -1257,
   -1257, -1191, -1257, -1257, -1257, -1257, -1257, -1256, -1257, -1257,
   -1257, -1257, -1257,  -972,  -789, -1257,  -371,  -964, -1257,  -755,
   -1257,  -765, -1257, -1257,  -958, -1257, -1257,  -921, -1257, -1257,
   -1257, -1257, -1257,  -148, -1257, -1257,  -962, -1257, -1257,  -480,
   -1257, -1257, -1257, -1257, -1257,  -918, -1257, -1257,  -916, -1257,
   -1257,  -120, -1257, -1257,  -479, -1257, -1257, -1257, -1257, -1257
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     236,   479,   466,   591,   594,   804,   393,   468,  1058,  1036,
    1159,   256,   247,   244,   241,    49,  1286,    50,   614,    51,
      49,    52,    50,    53,    51,    54,    52,   688,    53,  1069,
      54,   864,   215,   473,   132,   291,   133,   292,   134,   293,
     135,   828,   399,   472,   569,   294,   657,   295,   899,   296,
     849,   297,  1404,   298,  1460,   299,  1226,   300,  1226,   301,
     240,   302,   579,   303,  1101,   304,  1048,  1134,  1135,  1136,
    1137,  1226,   893,  1147,  1012,  1134,  1135,  1136,  1137,   883,
     354,   945,   361,   665,   366,  1166,  1210,  1211,  1212,  1213,
     957,   639,   216,   305,  1422,    55,   643,  1337,  1338,  1382,
      55,   647,   136,  1117,  1240,  1314,  1126,   496,  1127,  1383,
     362,  1130,   367,   585,   586,  1321,   132,   570,   133,  1303,
     134,   956,   135,   587,   588,  1194,   215,  1200,   268,  1398,
    1357,   460,   461,   452,   348,   611,   619,   473,  1223,   389,
    1027,  1449,   630,   630,   630,   630,   619,   619,     7,   619,
     265,   648,   630,   623,   262,   630,     6,  1436,   625,   662,
     650,   644,   636,   259,   640,   704,   717,  1437,  1195,   702,
     380,  1202,   497,  1203,   706,  1314,  1206,   269,  1330,   991,
    1306,  1374,  1442,  1011,   136,  1479,   216,  1252,  1455,  1256,
     390,   420,   608,  1280,   453,  1092,   639,   266,  1456,   263,
     643,  1418,  1314,  1273,   647,  1297,   260,  1227,  1078,   981,
     676,   381,   630,   619,   233,   234,   619,    12,   751,    14,
     694,   620,   630,   585,   586,   658,  1324,   631,   587,   588,
    1254,   585,   586,  1258,   570,  1259,  1447,   698,   585,   586,
     619,   587,   588,  1079,  1080,    30,  1081,   714,  1228,   451,
    1298,    17,  1049,  1423,  1049,   708,   900,   438,  1013,   440,
     850,   442,  1469,  1325,   400,   400,   400,   946,   400,  1116,
    1049,   233,   234,   884,   771,   585,   586,   619,   743,   744,
     745,   727,   958,   619,   619,   587,   588,    56,   217,   991,
     709,   306,   615,   624,   627,   696,   137,   991,   626,   619,
    1193,   615,    41,   628,   991,    86,   619,  1351,   695,   124,
      57,   692,    58,  1489,    59,    57,    60,    58,   151,    59,
     168,    60,   658,   431,   199,   432,   196,   433,   202,   649,
       1,     2,   755,  1495,   651,   590,   203,   444,   693,   446,
     204,   693,   766,   693,   205,   693,   233,   234,    20,    21,
     242,   245,   248,   257,   410,  1384,   206,   411,   351,   352,
     412,   781,   207,   291,  1159,   292,   693,   293,   693,   225,
     792,  1079,  1080,   294,  1081,   295,   250,   296,  1412,   297,
     271,   298,   284,   299,   285,   300,  1253,   301,   287,   302,
     288,   303,   286,   304,    25,    26,   816,   349,  1109,   340,
     911,   912,   233,   234,   913,   914,   585,   586,   915,   916,
    1110,  1111,   358,  1438,    33,    34,   587,   588,    44,    45,
     363,   305,   368,   855,  1249,  1250,   127,   128,   369,   994,
     995,   153,   154,   158,   159,   376,   163,   164,   377,  1463,
     171,   172,   176,   177,  1457,   181,   182,   186,   187,   191,
     192,  1109,   771,   911,   912,   233,   234,   913,   914,   585,
     586,   915,   916,  1110,  1111,   210,   211,   233,   234,   587,
     588,   394,   395,   396,   397,  1112,  1113,   251,   252,   272,
     273,   279,   280,   342,   343,   371,   372,  1037,  1038,   405,
     406,   351,   352,   421,   422,   455,   456,   460,   461,   491,
     492,   378,   797,  1345,   500,   501,   383,  1070,  1071,  1109,
     379,   911,   912,   233,   234,   913,   914,   585,   586,   915,
     916,  1110,  1111,   506,   507,   511,   512,   587,   588,   516,
     517,  1190,  1191,   521,   522,   527,   528,   532,   533,   537,
     538,   384,  1102,  1103,  1122,  1128,   542,   543,   547,   548,
     385,  1148,    87,   388,    88,    89,    90,   821,    91,    92,
      93,   386,    94,    95,    96,   392,    97,    98,    99,   387,
     100,   101,   910,   911,   912,   233,   234,   913,   914,   585,
     586,   915,   916,   552,   553,   558,   559,   563,   564,   587,
     588,   582,   583,   653,   654,   677,   678,   712,   654,   728,
     729,   740,   741,   756,   757,   782,   783,   806,   807,  1201,
    1204,   830,   831,   838,   839,   417,  1224,   843,   844,   856,
     857,   866,   867,   872,   873,   877,   878,   934,   935,   939,
     940,   971,   972,   988,   989,  1000,  1001,  1032,  1033,  1043,
    1044,  1060,  1061,  1065,  1066,  1097,  1098,  1104,  1105,  1131,
    1132,  1153,  1154,  1167,  1168,  1185,  1186,  1207,  1208,  1244,
    1245,  1265,  1154,  1269,  1270,  1281,  1282,  1332,  1333,  1352,
    1353,  1257,  1260,  1361,  1362,  1377,  1378,  1387,  1388,  1413,
    1414,  1274,  1275,  1426,  1427,  1431,  1432,  1450,  1451,  1464,
    1465,  1484,  1485,   426,   434,   464,   429,   469,   477,   470,
     447,   400,   478,   480,   484,   488,   489,   490,   499,   505,
     526,   557,   574,   575,   568,   601,   576,   597,   580,   598,
     577,   605,   606,   607,   613,   618,   629,   652,   663,   666,
     578,   667,   668,   669,   682,   683,   687,   685,   612,   684,
     686,   672,   690,   697,   691,   710,   715,   711,   718,   719,
     723,   720,   733,   738,   739,   750,   767,   762,   761,   771,
     774,   752,   776,   775,   777,   778,   779,   788,   793,   797,
     787,   734,   780,   805,   768,   811,   812,   813,   814,   817,
     821,   800,   829,   848,   865,   882,   824,   860,   894,   794,
     835,   905,   906,   889,   850,   944,   951,   884,   963,   818,
     969,   964,   977,   981,   996,   997,   900,   998,   999,  1006,
     984,   976,  1019,  1025,  1018,   958,   946,  1042,  1039,  1059,
    1073,  1308,  1309,  1072,  1028,  1074,  1054,  1149,  1075,  1076,
    1077,  1152,  1093,  1385,  1386,  1090,  1013,  1395,  1049,  1172,
    1162,  1178,  1179,  1180,  1181,  1158,  1183,  1225,  1173,  1236,
    1237,  1322,  1323,  1238,  1241,  1242,  1243,  1264,  1276,  1288,
    1304,  1289,  1294,  1295,  1291,  1307,  1317,  1227,  1310,  1318,
    1226,  1296,  1319,  1331,  1346,  1359,  1118,  1360,  1297,  1347,
    1368,  1372,  1396,  1403,  1399,  1407,  1408,  1420,  1324,  1421,
    1424,  1439,  1440,  1445,  1461,  1471,  1474,  1472,  1481,  1475,
    1476,  1477,  1473,  1483,  1480,  1491,  1493,  1494,  1492,  1497,
    1498,  1499,   123,   341,   226,   581,   152,  1500,    40,   481,
     664,   418,  1458,  1459,   689,   703,   699,   707,   705,   713,
     716,   985,   907,  1405,  1266,  1400,  1311,  1029,   965,  1020,
    1094,  1199,  1369,  1005,  1184,  1393,  1406,     0,     0,     0,
       0,     0,  1375,  1376,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1443,  1444,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1255,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1462,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1482,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1394
};

static const yytype_int16 yycheck[] =
{
     148,   392,   358,   483,   483,   770,     8,   363,   980,   967,
    1051,     4,     4,     4,     4,    44,  1167,    46,    71,    48,
      44,    50,    46,    52,    48,    54,    50,    71,    52,   987,
      54,   820,    64,   371,    56,    66,    58,    68,    60,    70,
      62,   796,   125,   125,   125,    76,   125,    78,   103,    80,
     101,    82,   111,    84,   111,    86,   156,    88,   156,    90,
     150,    92,   473,    94,  1022,    96,   107,    17,    18,    19,
      20,   156,   837,  1031,   119,    17,    18,    19,    20,   113,
     228,   117,   230,   579,   232,  1057,    21,    22,    23,    24,
     115,   532,   124,   124,     4,   124,   537,    42,    43,  1313,
     124,   542,   124,  1024,  1129,  1233,  1024,     4,  1024,  1313,
     230,  1026,   232,   173,   174,  1239,    56,   455,    58,  1185,
      60,   872,    62,   183,   184,  1089,    64,  1089,     4,  1320,
    1281,     6,     7,     4,   224,   491,    72,   475,  1096,     4,
     955,  1397,    74,    74,    74,    74,    72,    72,   126,    72,
       4,    87,    74,    79,     4,    74,     0,  1371,    81,   570,
      85,    93,    91,     4,    95,    95,   662,  1371,  1089,    91,
       4,  1089,    69,  1089,    93,  1303,  1091,    53,  1244,   239,
    1205,  1305,  1373,   934,   124,  1441,   124,  1151,  1402,  1151,
      55,   311,    67,  1165,    65,  1010,   637,    51,  1402,    49,
     641,  1352,  1330,  1161,   645,   303,    47,   307,   123,   164,
     601,    45,    74,    72,   169,   170,    72,    15,   714,    16,
      79,    77,    74,   173,   174,   563,   311,    89,   183,   184,
    1151,   173,   174,  1151,   572,  1151,  1387,    89,   173,   174,
      72,   183,   184,   158,   159,   317,   161,   658,   348,   339,
     348,   315,   311,   163,   311,    87,   311,   327,   303,   329,
     311,   331,  1413,   348,   347,   347,   347,   303,   347,  1024,
     311,   169,   170,   307,   219,   173,   174,    72,    29,    30,
      31,   672,   307,    72,    72,   183,   184,   316,   320,   239,
      85,   322,   345,   511,    83,    83,   318,   239,   516,    72,
    1089,   345,   319,   521,   239,   127,    72,  1279,    81,   321,
     339,    77,   341,  1464,   343,   339,   345,   341,   316,   343,
      28,   345,   660,   319,    40,   321,    27,   323,     5,   547,
      13,    14,   723,  1484,   552,   483,     5,   333,   621,   335,
       5,   624,   733,   626,     5,   628,   169,   170,    11,    12,
     340,   342,   344,   346,   212,  1313,     5,   215,   181,   182,
     218,   752,   323,    66,  1405,    68,   649,    70,   651,   318,
     761,   158,   159,    76,   161,    78,     3,    80,  1350,    82,
       3,    84,   129,    86,   133,    88,  1151,    90,   141,    92,
     145,    94,   137,    96,    11,    12,   787,    11,   165,   320,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,    11,  1371,    11,    12,   183,   184,    11,    12,
      11,   124,     3,   814,   191,   192,    11,    12,    11,   909,
     909,    11,    12,    11,    12,   340,    11,    12,   342,  1411,
      11,    12,    11,    12,  1402,    11,    12,    11,    12,    11,
      12,   165,   219,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,    11,    12,   169,   170,   183,
     184,   473,   474,   475,   476,   189,   190,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,   967,   967,    11,
      12,   181,   182,    11,    12,    11,    12,     6,     7,    11,
      12,   344,   216,  1268,    11,    12,   346,   987,   987,   165,
       8,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,    11,    12,    11,    12,   183,   184,    11,
      12,   187,   188,    11,    12,    11,    12,    11,    12,    11,
      12,    47,  1022,  1022,  1024,  1024,    11,    12,    11,    12,
      49,  1031,   128,     8,   130,   131,   132,   213,   134,   135,
     136,    51,   138,   139,   140,     6,   142,   143,   144,    53,
     146,   147,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    11,    12,    11,    12,    11,    12,   183,
     184,    11,    12,    97,    98,    11,    12,    97,    98,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,  1089,
    1089,    11,    12,    11,    12,   322,  1096,    11,    12,   121,
     122,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,   109,   110,    11,    12,    11,    12,    11,    12,    11,
      12,   109,   110,    11,    12,    11,    12,    11,    12,    11,
      12,  1151,  1151,    11,    12,    11,    12,    11,    12,    11,
      12,  1161,  1161,   240,   241,    11,    12,    11,    12,    11,
      12,    11,    12,    32,    34,     3,    33,     8,    45,     6,
      35,   347,    55,   125,   313,     8,     8,     8,     8,     8,
       8,     8,    57,     8,    65,    36,    59,   324,   125,   309,
      61,     6,     6,     6,     6,     6,     6,     6,   125,   348,
      63,     3,     3,   305,     8,     8,    11,    67,    69,     8,
       8,    37,     8,     8,    11,     8,   125,    11,     8,     8,
      38,   120,     6,     4,     4,     4,   314,   112,     6,   219,
     346,    39,    75,    73,     3,     3,     3,   116,   310,   216,
       6,   100,    99,     8,   102,     8,     8,     8,     6,   306,
     213,   104,     8,     6,     8,     6,   104,   104,   331,   114,
     106,     8,   101,   108,   311,     6,   347,   307,     8,   118,
      41,   113,   327,   164,     8,     3,   311,     3,     3,   347,
     103,   105,   117,   105,     8,   307,   303,     8,   347,     8,
       8,  1212,  1213,   312,   115,     6,   329,   308,     8,     8,
       8,     6,   119,  1313,  1313,   105,   303,  1316,   311,     6,
     325,   312,     6,     8,     5,   107,   123,   304,   162,     8,
       3,  1242,  1243,     3,   308,     3,     3,     8,   333,     8,
       3,   242,   332,     8,   154,   304,     6,   307,   348,     8,
     156,   160,     8,     3,   312,   328,  1024,     8,   303,   335,
     348,     8,     8,     8,   348,     8,   337,   330,   311,     6,
      11,  1371,  1371,   308,     6,   326,     6,     8,   312,     8,
       8,   304,   163,     8,   157,   334,     6,     6,   155,   336,
       8,     8,    40,   219,   139,   475,    62,   338,    25,   402,
     572,   308,  1402,  1402,   616,   637,   632,   645,   641,   655,
     660,   902,   852,  1332,  1155,  1327,  1230,   960,   886,   948,
    1015,  1089,  1300,   918,  1083,  1316,  1337,    -1,    -1,    -1,
      -1,    -1,  1308,  1309,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1375,  1376,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1316
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    13,    14,   478,   479,   480,     0,   126,   487,   488,
    1068,  1069,    15,   481,    16,   485,   486,   315,   489,   490,
      11,    12,  1070,  1071,  1072,    11,    12,   482,   483,   484,
     317,   575,   576,    11,    12,   491,   492,   493,  1073,  1074,
     487,   319,   618,   619,    11,    12,   577,   578,   579,    44,
      46,    48,    50,    52,    54,   124,   316,   339,   341,   343,
     345,   494,   495,   496,   497,   498,   503,   504,   509,   510,
     515,   516,   523,   524,   529,   530,   535,   536,   541,   542,
     547,   548,   553,   554,   561,   562,   127,   128,   130,   131,
     132,   134,   135,   136,   138,   139,   140,   142,   143,   144,
     146,   147,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,   485,   321,   641,   642,    11,    12,   620,
     621,   622,    56,    58,    60,    62,   124,   318,   580,   581,
     582,   583,   584,   590,   591,   597,   598,   604,   605,   609,
     610,   316,   496,    11,    12,   499,   500,   501,    11,    12,
     505,   506,   507,    11,    12,   511,   512,   513,    28,   517,
     518,    11,    12,   525,   526,   527,    11,    12,   531,   532,
     533,    11,    12,   537,   538,   539,    11,    12,   543,   544,
     545,    11,    12,   549,   550,   551,    27,   555,   556,    40,
     563,  1048,     5,     5,     5,     5,     5,   323,   752,   753,
      11,    12,   643,   644,   645,    64,   124,   320,   623,   624,
     625,   626,   627,   632,   633,   318,   582,   585,   586,   592,
     593,   599,   600,   169,   170,   606,  1170,  1171,  1172,   611,
    1048,     4,   340,   502,     4,   342,   508,     4,   344,   514,
       3,    11,    12,   519,   520,   521,     4,   346,   528,     4,
      47,   534,     4,    49,   540,     4,    51,   546,     4,    53,
     552,     3,    11,    12,   557,   558,   559,  1065,  1066,    11,
      12,   564,   565,   566,   129,   133,   137,   141,   145,   754,
     755,    66,    68,    70,    76,    78,    80,    82,    84,    86,
      88,    90,    92,    94,    96,   124,   322,   646,   647,   648,
     649,   650,   657,   658,   663,   664,   671,   672,   676,   677,
     681,   682,   686,   687,   691,   692,   699,   700,   707,   708,
     715,   716,   723,   724,   729,   730,   735,   736,   743,   744,
     320,   625,    11,    12,   628,   629,   630,   634,  1048,    11,
     588,   181,   182,   587,  1170,  1188,  1189,  1190,    11,   595,
     594,  1170,  1188,    11,   602,   601,  1170,  1188,     3,    11,
     607,    11,    12,   612,   613,   614,   340,   342,   344,     8,
       4,    45,   522,   346,    47,    49,    51,    53,     8,     4,
      55,   560,     6,     8,   473,   474,   475,   476,  1067,   125,
     347,   567,   568,   569,   570,    11,    12,   757,   758,   759,
     212,   215,   218,   756,  1152,  1157,  1159,   322,   648,   651,
    1188,    11,    12,   659,   660,   661,    32,   665,  1045,    33,
    1051,  1051,  1051,  1051,    34,   693,  1050,   701,  1050,   709,
    1050,   717,  1050,   725,  1051,   731,  1051,    35,   737,  1052,
     745,  1048,     4,    65,   631,    11,    12,   635,   636,   637,
       6,     7,   589,  1064,     3,   596,  1064,   603,  1064,     8,
       6,   608,   125,   570,   615,   616,   617,    45,    55,  1065,
     125,   569,   571,   572,   313,   760,   761,   762,     8,     8,
       8,    11,    12,   652,   653,   654,     4,    69,   662,     8,
      11,    12,   666,   667,   668,     8,    11,    12,   673,   674,
     675,    11,    12,   678,   679,   680,    11,    12,   683,   684,
     685,    11,    12,   688,   689,   690,     8,    11,    12,   694,
     695,   696,    11,    12,   702,   703,   704,    11,    12,   710,
     711,   712,    11,    12,   718,   719,   720,    11,    12,   726,
     727,   728,    11,    12,   732,   733,   734,     8,    11,    12,
     738,   739,   740,    11,    12,   746,   747,   748,    65,   125,
     570,   638,   639,   640,    57,     8,    59,    61,    63,   571,
     125,   617,    11,    12,   574,   173,   174,   183,   184,   573,
    1170,  1176,  1177,  1178,  1191,  1192,  1193,   324,   309,   857,
     858,    36,   763,   764,  1049,     6,     6,     6,    67,   655,
     656,  1064,    69,     6,    71,   345,   669,   670,     6,    72,
      77,  1013,  1014,    79,  1013,    81,  1013,    83,  1013,     6,
      74,    89,   697,   698,  1015,  1016,    91,   705,   706,  1015,
      95,   713,   714,  1015,    93,   721,   722,  1015,    87,  1013,
      85,  1013,     6,    97,    98,   741,   742,   125,   570,   749,
     750,   751,   571,   125,   640,   574,   348,     3,     3,   305,
     924,   925,    37,   859,   860,  1047,  1065,    11,    12,   765,
     766,   767,     8,     8,     8,    67,     8,    11,    71,   670,
       8,    11,    77,  1014,    79,    81,    83,     8,    89,   698,
    1017,  1018,    91,   706,    95,   714,    93,   722,    87,    85,
       8,    11,    97,   742,   571,   125,   751,   574,     8,     8,
     120,   991,   992,    38,   926,   927,  1046,  1065,    11,    12,
     861,   862,   863,     6,   100,   768,   769,   770,     4,     4,
      11,    12,  1023,    29,    30,    31,  1019,  1020,  1021,  1022,
       4,   574,    39,   993,  1053,  1065,    11,    12,   928,   929,
     930,     6,   112,   864,   865,   866,  1065,   314,   102,   783,
     784,   219,   771,  1158,   346,    73,    75,     3,     3,     3,
      99,  1065,    11,    12,   994,   995,   996,     6,   116,   931,
     932,   933,  1065,   310,   114,   879,   880,   216,   867,  1156,
     104,   797,   798,   785,  1158,     8,    11,    12,   772,   773,
     774,     8,     8,     8,     6,   997,  1065,   306,   118,   946,
     947,   213,   934,  1151,   104,   893,   894,   881,  1156,     8,
      11,    12,   868,   869,   870,   106,   810,   811,    11,    12,
     799,   800,   801,    11,    12,   786,   787,   788,     6,   101,
     311,   775,   776,   777,   778,  1065,   121,   122,   998,   999,
     104,   960,   961,   948,  1151,     8,    11,    12,   935,   936,
     937,   906,    11,    12,   895,   896,   897,    11,    12,   882,
     883,   884,     6,   113,   307,   871,   872,   873,   874,   108,
     824,   825,   812,  1158,   331,   802,   803,  1108,  1109,   103,
     311,   789,   790,   791,   792,     8,   101,   777,   779,   780,
     166,   167,   168,   171,   172,   175,   176,  1000,  1001,  1002,
    1155,  1164,  1165,  1166,  1170,  1176,  1182,  1183,  1184,  1185,
    1186,  1187,  1191,   973,    11,    12,   962,   963,   964,    11,
      12,   949,   950,   951,     6,   117,   303,   938,   939,   940,
     941,   347,   907,   908,   898,   899,  1108,   115,   307,   885,
     886,   887,   888,     8,   113,   873,   875,   876,   839,    41,
     826,    11,    12,   813,   814,   815,   105,   327,   804,  1114,
    1115,   164,  1150,  1153,   103,   791,   793,   794,    11,    12,
     782,   239,   781,  1161,  1176,  1191,     8,     3,     3,     3,
      11,    12,  1003,  1004,  1005,  1002,   347,   974,   975,   965,
     966,  1108,   119,   303,   952,   953,   954,   955,     8,   117,
     940,   942,   943,   909,   910,   105,   900,  1114,   115,   887,
     889,   890,    11,    12,   878,   877,  1161,  1176,  1191,   347,
     840,   841,     8,    11,    12,   827,   828,   829,   107,   311,
     816,   817,   818,   819,   329,   805,  1120,  1121,  1150,     8,
      11,    12,  1110,  1111,  1112,    11,    12,   796,   795,  1161,
    1176,  1191,   312,     8,     6,     8,     8,     8,   123,   158,
     159,   161,  1006,  1007,  1008,  1009,  1010,  1011,   976,   977,
     105,   967,  1114,   119,   954,   956,   957,    11,    12,   945,
     944,  1161,  1176,  1191,    11,    12,   912,   913,   914,   165,
     177,   178,   189,   190,   911,  1154,  1156,  1164,  1170,  1173,
    1174,  1175,  1176,  1179,  1180,  1181,  1182,  1185,  1191,   901,
    1120,    11,    12,   892,    17,    18,    19,    20,   891,  1026,
    1027,  1028,  1029,  1037,  1038,  1039,  1040,  1161,  1176,   308,
     842,   843,     6,   109,   110,   830,   831,   832,   107,   818,
     820,   821,   325,   806,  1126,  1127,  1150,    11,    12,  1116,
    1117,  1118,     6,   162,  1096,  1097,  1104,  1113,   312,     6,
       8,     5,  1012,   123,  1008,    11,    12,   979,   980,   981,
     187,   188,   978,  1151,  1154,  1164,  1167,  1168,  1169,  1170,
    1173,  1176,  1182,  1185,  1191,   968,  1120,    11,    12,   959,
      21,    22,    23,    24,   958,  1030,  1031,  1032,  1033,  1041,
    1042,  1043,  1044,  1161,  1176,   304,   156,   307,   348,   915,
     916,   917,   918,  1054,  1055,  1056,     8,     3,     3,   902,
    1126,   308,     3,     3,    11,    12,   845,   846,   847,   191,
     192,   844,  1154,  1158,  1164,  1170,  1173,  1176,  1182,  1185,
    1191,  1194,  1195,  1196,     8,   109,   831,   833,   834,    11,
      12,   823,   822,  1161,  1176,  1191,   333,   807,  1132,  1133,
    1150,    11,    12,  1122,  1123,  1124,  1096,  1119,     8,   242,
    1160,   154,  1098,  1099,   332,     8,   160,   303,   348,   982,
     983,   984,   985,  1054,     3,   969,  1126,   304,  1065,  1065,
     348,   917,   919,   920,  1055,  1057,  1058,     6,     8,     8,
     903,  1132,  1065,  1065,   311,   348,   848,   849,   850,   851,
    1054,     3,    11,    12,   836,   837,   838,    42,    43,   835,
    1024,  1025,  1034,  1035,  1036,  1158,   312,   335,   808,  1138,
    1139,  1150,    11,    12,  1128,  1129,  1130,  1096,  1125,   328,
       8,    11,    12,  1105,  1106,  1107,  1100,  1101,   348,   984,
     986,   987,     8,   970,  1132,  1064,  1064,    11,    12,   922,
     923,   921,  1026,  1037,  1161,  1176,  1191,    11,    12,  1060,
    1061,  1062,  1059,  1153,  1170,  1191,     8,   904,  1138,   348,
     850,   852,   853,     8,   111,   817,  1065,     8,   337,   809,
    1144,  1145,  1150,    11,    12,  1134,  1135,  1136,  1096,  1131,
     330,     6,     4,   163,    11,  1103,   240,   241,  1102,  1162,
    1163,    11,    12,   989,   990,   988,  1026,  1037,  1161,  1176,
    1191,   971,  1138,  1065,  1065,   308,  1063,  1096,   905,  1144,
      11,    12,   855,   856,   854,  1026,  1037,  1161,  1176,  1191,
     111,     6,  1064,  1150,    11,    12,  1140,  1141,  1142,  1096,
    1137,   326,     8,   163,     6,     8,     8,   304,   972,  1144,
     157,   312,  1065,     8,    11,    12,  1146,  1147,  1148,  1096,
    1143,   334,   155,     6,     6,  1096,  1149,   336,     8,     8,
     338
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
      yyerror (&yylloc, osoption, parserData, osglData, osnlData, YY_("syntax error: cannot back up")); \
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
		  Type, Value, Location, osoption, parserData, osglData, osnlData); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData, osnlData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osoption);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData, osnlData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
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
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData, osnlData);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osoption, parserData, osglData, osnlData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSOption *osoption;
    OSoLParserData *parserData;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osoption, parserData, osglData, osnlData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osoption, parserData, osglData, osnlData); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osoption, parserData, osglData, osnlData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osoption);
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
int yyparse (OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData);
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
yyparse (OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
int
yyparse (osoption, parserData, osglData, osnlData)
    OSOption *osoption;
    OSoLParserData *parserData;
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
            parserData->parser_errors += ("\n\nOSoL input is either invalid or not well-formed.\n"); 
            osolerror( NULL, osoption, parserData, osglData, osnlData, parserData->parser_errors);
        }
    }
    break;

  case 14:

    { parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "unexpected end of file, expecting </osol>");}
    break;

  case 17:

    {
    if (!osoption->setHeader(osglData->fileName, osglData->source,
            osglData->description, osglData->fileCreator, osglData->licence) )     
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setHeader failed");
}
    break;

  case 20:

    {
    parserData->serviceURIPresent          = false;    
    parserData->serviceNamePresent         = false;
    parserData->instanceNamePresent        = false;
    parserData->instanceLocationPresent    = false;
    parserData->jobIDPresent               = false;
    parserData->solverToInvokePresent      = false;
    parserData->licensePresent             = false;
    parserData->usernamePresent            = false;
    parserData->passwordPresent            = false;
    parserData->contactPresent             = false;
    parserData->otherGeneralOptionsPresent = false;
    osoption->general = new GeneralOption();
}
    break;

  case 41:

    {
    if (parserData->serviceURIPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <serviceURI>");
    else
        parserData->serviceURIPresent = true;
    
}
    break;

  case 47:

    {
        if (osoption->setServiceURI((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceURI failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 49:

    {
        if (parserData->serviceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <serviceName>");
        parserData->serviceNamePresent = true;
    }
    break;

  case 55:

    {
        if (osoption->setServiceName((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceName failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 57:

    {    if (parserData->instanceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <instanceName>");
        parserData->instanceNamePresent = true;
    }
    break;

  case 63:

    {
        if (osoption->setInstanceName((yyvsp[(1) - (1)].sval)) == false) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setInstanceName failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 64:

    {
    if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setInstanceLocation failed");
    parserData->errorText = NULL;
}
    break;

  case 65:

    {
        if (parserData->instanceLocationPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <instanceLocation>");
        parserData->instanceLocationPresent = true;
        parserData->typeAttribute = "local";
    }
    break;

  case 67:

    {   
        if (verifyLocationType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "instance location type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 68:

    { 
    parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 74:

    {    
        parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval)); 
    }
    break;

  case 76:

    {    if (parserData->jobIDPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <jobID>");
        parserData->jobIDPresent = true;
    }
    break;

  case 82:

    {
        if (osoption->setJobID((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setJobID failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 84:

    {
        if (parserData->solverToInvokePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <solverToInvoke>");
        parserData->solverToInvokePresent = true;
    }
    break;

  case 90:

    {
        if (osoption->setSolverToInvoke((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setSolverToInvoke failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 92:

    {
    if (parserData->licensePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <license>");
    parserData->licensePresent = true;    
}
    break;

  case 98:

    {
        if (osoption->setLicense((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setLicense failed");
        free((yyvsp[(1) - (1)].sval));
        parserData->errorText = NULL;
    }
    break;

  case 100:

    {    if (parserData->usernamePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <username>");
    parserData->usernamePresent = true;    
}
    break;

  case 106:

    {
        if (osoption->setUserName((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setUsername failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 108:

    {    if (parserData->passwordPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <password>");
    parserData->passwordPresent = true;    
}
    break;

  case 114:

    {
        if (osoption->setPassword((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setPassword failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 115:

    {
    if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setContact failed");
    parserData->errorText = NULL;
}
    break;

  case 116:

    {
    if (parserData->contactPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <contact>");
    parserData->contactPresent = true;
    parserData->typeAttribute = "osp";
    parserData->tempStr = "";
}
    break;

  case 118:

    {   
        if (verifyTransportType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "transport type not recognized");
    }
    break;

  case 119:

    { 
        parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
        free((yyvsp[(2) - (3)].sval));
    }
    break;

  case 125:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
    }
    break;

  case 126:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 127:

    {
        if (parserData->otherGeneralOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <general> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
        parserData->otherGeneralOptionsPresent = true;
    }
    break;

  case 128:

    {
        if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other general options cannot be negative");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 129:

    {
        if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 130:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 137:

    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherGeneralOption(osglData->name, osglData->value, 
                                                  osglData->description) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                    "setOtherGeneralOption failed");
    }
    break;

  case 138:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->descriptionPresent = false;
    osglData->name = "";
    osglData->value = "";
    osglData->description = "";
}
    break;

  case 139:

    {
    if (!osglData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 142:

    {    if (osglData->name.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
    break;

  case 149:

    {
    parserData->minDiskSpacePresent = false;    
    parserData->minMemoryPresent = false;
    parserData->minCPUSpeedPresent = false;
    parserData->minCPUNumberPresent = false;
    parserData->otherSystemOptionsPresent = false;
    osoption->system = new SystemOption();
}
    break;

  case 164:

    {    if (parserData->minDiskSpacePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minDiskSpace element allowed");
        parserData->minDiskSpacePresent = true;
        osglData->unitPresent = false;    
        osglData->descriptionPresent = false;    
        osglData->unit = "byte";    
        osglData->description = "";
    }
    break;

  case 171:

    {
    if (osoption->setMinDiskSpace(osglData->unit, osglData->description, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinDiskSpace failed");
    parserData->errorText = NULL;
}
    break;

  case 173:

    {    if (parserData->minMemoryPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minMemory element allowed");
        parserData->minMemoryPresent = true;
        osglData->unitPresent = false;    
        osglData->descriptionPresent = false;    
        osglData->unit = "byte";    
        osglData->description = "";
    }
    break;

  case 180:

    {
    if (osoption->setMinMemorySize(osglData->unit, osglData->description, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinMemorySize failed");
    parserData->errorText = NULL;
}
    break;

  case 182:

    {    if (parserData->minCPUSpeedPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minCPUSpeed element allowed");
        parserData->minCPUSpeedPresent = true;
        osglData->unitPresent = false;    
        osglData->descriptionPresent = false;    
        osglData->unit = "hertz";    
        osglData->description = "";
    }
    break;

  case 189:

    {    
    if (osoption->setMinCPUSpeed(osglData->unit, osglData->description, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
}
    break;

  case 191:

    {    
    if (parserData->minCPUNumberPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "only one minCPUNumber element allowed");
    parserData->minCPUNumberPresent = true;
    osglData->descriptionPresent = false;    
    osglData->description = "";    
}
    break;

  case 195:

    {
    if (osoption->setMinCPUNumber((yyvsp[(1) - (1)].ival), osglData->description) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "setMinCPUNumber failed");
    parserData->errorText = NULL; 
}
    break;

  case 196:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 197:

    {
    if (parserData->otherSystemOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <system> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->otherSystemOptionsPresent = true;
}
    break;

  case 198:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other system options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 199:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 200:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 207:

    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherSystemOption(osglData->name, osglData->value, osglData->description) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherSystemOption failed");
    }
    break;

  case 210:

    {
    parserData->serviceTypePresent = false;    
    parserData->otherServiceOptionsPresent = false;
    osoption->service = new ServiceOption();
}
    break;

  case 222:

    {    if (parserData->serviceTypePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one currentState element allowed");
        parserData->serviceTypePresent = true;
    }
    break;

  case 228:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); 
        free((yyvsp[(1) - (1)].sval));
        if (osoption->setServiceType(parserData->tempStr) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceType failed; current system state not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 229:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 230:

    {
    if (parserData->otherServiceOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <service> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherServiceOptionsPresent = true;
}
    break;

  case 231:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other service options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 232:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 233:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 240:

    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherServiceOption(osglData->name, osglData->value, osglData->description) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherServiceOption failed");
    }
    break;

  case 243:

    {
    parserData->maxTimePresent = false;    
    parserData->requestedStartTimePresent = false;    
    parserData->dependenciesPresent = false;    
    parserData->requiredDirectoriesPresent = false;    
    parserData->requiredFilesPresent = false;    
    parserData->directoriesToMakePresent = false;    
    parserData->filesToMakePresent = false;    
    parserData->inputDirectoriesToMovePresent = false;    
    parserData->inputFilesToMovePresent = false;    
    parserData->outputDirectoriesToMovePresent = false;    
    parserData->outputFilesToMovePresent = false;    
    parserData->filesToDeletePresent = false;    
    parserData->directoriesToDeletePresent = false;    
    parserData->processesToKillPresent = false;    
    parserData->otherJobOptionsPresent = false;     
    osoption->job = new JobOption();
 }
    break;

  case 267:

    {    
    if (osoption->setMaxTime(parserData->maxTimeValue, osglData->unit) == false)       
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "max time request could not be honored");
}
    break;

  case 268:

    {    
    if (parserData->maxTimePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <maxTime> element allowed");
    osglData->unitPresent = false;    
    osglData->unit = "second"; 
    parserData->maxTimePresent = true;
    parserData->maxTimeValue = OSDBL_MAX;
}
    break;

  case 277:

    {
    parserData->maxTimeValue = parserData->tempVal;
}
    break;

  case 279:

    {    if (parserData->requestedStartTimePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one requestedStartTime element allowed");
        parserData->requestedStartTimePresent = true;
    }
    break;

  case 285:

    {
        if (osoption->setRequestedStartTime((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setRequestedStartTime failed");    
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
        }
    break;

  case 286:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <job> <dependencies> failed");
    delete[] parserData->jobDependencies;
    parserData->jobDependencies = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 287:

    {
    if (parserData->dependenciesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <dependencies> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->dependenciesPresent = true;
}
    break;

  case 293:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few job IDs in <dependencies> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 296:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many job IDs in <dependencies> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->jobDependencies[parserData->kounter] = (yyvsp[(3) - (4)].sval);
        parserData->kounter++;
    }
    free((yyvsp[(3) - (4)].sval)); 
}
    break;

  case 297:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <requiredDirectories> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 298:

    {
    if (parserData->requiredDirectoriesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <requiredDirectories> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredDirectoriesPresent = true;
}
    break;

  case 303:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <requiredDirectories> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 304:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <requiredFiles> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 305:

    {
    if (parserData->requiredFilesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <requiredFiles> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredFilesPresent = true;
}
    break;

  case 310:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <requiredFiles> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 311:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <directoriesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 312:

    {
    if (parserData->directoriesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <directoriesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToMakePresent = true;
}
    break;

  case 317:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <directoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 318:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <filesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 319:

    {
    if (parserData->filesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <filesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToMakePresent = true;
}
    break;

  case 324:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <filesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 325:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;
}
    break;

  case 326:

    {
    if (parserData->inputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <inputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputDirectoriesToMovePresent = true;
}
    break;

  case 332:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <inputDirectoriesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 336:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputFilesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 337:

    {
    if (parserData->inputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <inputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputFilesToMovePresent = true;
}
    break;

  case 343:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <inputFilesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 347:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 348:

    {
    if (parserData->outputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <outputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputFilesToMovePresent = true;
}
    break;

  case 354:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <outputFilesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 358:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 359:

    {
    if (parserData->outputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <outputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputDirectoriesToMovePresent = true;
}
    break;

  case 365:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <outputDirectoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 369:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <filesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 370:

    {
    if (parserData->filesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <filesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToDeletePresent = true;
}
    break;

  case 376:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <filesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 377:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <directoriesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 378:

    {
    if (parserData->directoriesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <directoriesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToDeletePresent = true;
}
    break;

  case 384:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <directoriesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 385:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <processesToKill> failed");
    delete[] parserData->processesToKill;
    parserData->processesToKill = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 386:

    {
    if (parserData->processesToKillPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <processesToKill> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->processesToKillPresent = true;
}
    break;

  case 392:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few process IDs in <processesToKill> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 395:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
    if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many process IDs in <processesToKill> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->processesToKill[parserData->kounter] = (yyvsp[(3) - (4)].sval);
        parserData->kounter++;
    }
    free((yyvsp[(3) - (4)].sval)); 
}
    break;

  case 396:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 397:

    {
    if (parserData->otherJobOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <job> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherJobOptionsPresent = true;
}
    break;

  case 398:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other job options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 399:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 400:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 407:

    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherJobOption(osglData->name, osglData->value, osglData->description) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherJobOption failed");
    }
    break;

  case 410:

    {
    osoption->optimization = new OptimizationOption();
    osglData->numberOfVariablesPresent = false;
    osglData->numberOfObjectivesPresent = false;
    osglData->numberOfConstraintsPresent = false;
}
    break;

  case 414:

    {    
//        osglData->numberOfVariables = parserData->tempInt; 
        if (osoption->setNumberOfVariables(osglData->numberOfVariables) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "setNumberOfVariables failed");
    }
    break;

  case 415:

    {
//        osglData->numberOfConstraints = parserData->tempInt; 
        if (osoption->setNumberOfConstraints(osglData->numberOfConstraints) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "setNumberOfConstraints failed");
    }
    break;

  case 416:

    {    
//        osglData->numberOfObjectives = parserData->tempInt; 
        if (osoption->setNumberOfObjectives(osglData->numberOfObjectives) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "setNumberOfObjectives failed");
    }
    break;

  case 424:

    {
    parserData->numberOfOtherVariableOptions = 0;
    osoption->optimization->variables = new VariableOption();
}
    break;

  case 425:

    {    
    if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
}
    break;

  case 427:

    {    
    parserData->numberOfOtherVariableOptions = parserData->tempInt;
}
    break;

  case 432:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 434:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValues(osglData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialVariableValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 435:

    {
    osglData->numberOfVarPresent = false;
}
    break;

  case 436:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[osglData->numberOfVar];
    parserData->namArray = new std::string[osglData->numberOfVar];
    parserData->valArray = new      double[osglData->numberOfVar];
    for (int i=0; i < osglData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 437:

    {
        if (osglData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValues>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 438:

    {
        if (parserData->kounter < osglData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValues>: fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 445:

    {
    parserData->kounter++;
}
    break;

  case 446:

    {    
    if (parserData->kounter >= osglData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->valuePresent = false;
}
    break;

  case 447:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
}
    break;

  case 450:

    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                    "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = osglData->idx;
    }
    break;

  case 451:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = osglData->name;
    }
    break;

  case 452:

    {
        if (osglData->value == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((osglData->value).c_str(), NULL);
    }
    break;

  case 456:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValuesString(osglData->numberOfVar, parserData->idxArray, parserData->valueString, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialVariableValuesString> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valueString;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valueString = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 457:

    {
    osglData->numberOfVarPresent = false;
}
    break;

  case 458:

    {
    parserData->kounter = 0;
    parserData->idxArray    = new         int[osglData->numberOfVar];
    parserData->namArray    = new std::string[osglData->numberOfVar];
    parserData->valueString = new std::string[osglData->numberOfVar];
    for (int i=0; i < osglData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfVar; i++) parserData->valueString[i] = "";
}
    break;

  case 459:

    {
        if (osglData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValuesString>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 460:

    {
        if (parserData->kounter < osglData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few initial values in <initialVariableValuesString> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 467:

    {
    parserData->kounter++;
    osglData->value = ""; //Make sure to remove random string
}
    break;

  case 468:

    {    
    if (parserData->kounter >= osglData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->value = "48r 87e WY EUV e7 df"; //random string...
}
    break;

  case 469:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
}
    break;

  case 472:

    {
        if (osglData->idx< 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = osglData->idx;
    }
    break;

  case 473:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = osglData->name;
    }
    break;

  case 474:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->valueString[parserData->kounter] = osglData->value;
    }
    break;

  case 479:

    {
    osoption->optimization->variables->initialBasisStatus = new BasisStatus();
}
    break;

  case 486:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 488:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 490:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 492:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 494:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 496:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 498:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 500:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setIntegerVariableBranchingWeights(osglData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <IntegerVariableBranchingWeights> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 501:

    {
    osglData->numberOfVarPresent = false;
}
    break;

  case 502:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[osglData->numberOfVar];
    parserData->namArray = new std::string[osglData->numberOfVar];
    parserData->valArray = new      double[osglData->numberOfVar];
    for (int i=0; i < osglData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 503:

    {
        if (osglData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 504:

    {
        if (parserData->kounter < osglData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 511:

    {
    parserData->kounter++;
}
    break;

  case 512:

    {    
    if (parserData->kounter >= osglData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = "";
    osglData->valuePresent = false;
    osglData->value = "1.0";
}
    break;

  case 513:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
}
    break;

  case 516:

    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = osglData->idx;
    }
    break;

  case 517:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = osglData->name;
    }
    break;

  case 518:

    {
        if (osglData->value == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((osglData->value).c_str(), NULL);
    }
    break;

  case 522:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 523:

    {
    parserData->sosIdxAttributePresent = false;    
    parserData->currentSOS = 0;
}
    break;

  case 524:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <sos> elements must be nonnegative");
    parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
}
    break;

  case 525:

    {
        if (parserData->numberOfSOS > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <sos> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 526:

    {    if (parserData->currentSOS != parserData->numberOfSOS)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <sos> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 532:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setAnotherSOSVariableBranchingWeight(parserData->sosIdx, 
                    osglData->numberOfVar, parserData->groupWeight,
                    parserData->idxArray, parserData->valArray, parserData->namArray) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "error processing SOS branching weights");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->currentSOS++;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 533:

    {
    if (parserData->currentSOS >= parserData->numberOfSOS)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many SOS branching weights");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->sosIdxAttributePresent = false;
    parserData->groupWeightAttributePresent = false;
    parserData->groupWeight = 1.0;
    parserData->numberOfSOSVar = 0;
    osglData->numberOfVarPresent = false;
}
    break;

  case 534:

    {
    if (!parserData->sosIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index required");
    if (!osglData->numberOfVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVar required");
}
    break;

  case 538:

    {
        parserData->kounter = 0;
        parserData->idxArray = new         int[osglData->numberOfVar];
        parserData->namArray = new std::string[osglData->numberOfVar];
        parserData->valArray = new      double[osglData->numberOfVar];
        for (int i=0; i < osglData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
        osglData->numberOfVarPresent = true;
    }
    break;

  case 547:

    {      
        parserData->iOther++;
    }
    break;

  case 548:

    {
    if (parserData->iOther >= parserData->numberOfOtherVariableOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "more <otherVariableOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->numberOfVarPresent = false;
    osglData->numberOfVar = 0;
    osglData->numberOfEnumerationsPresent = false;    
    osglData->numberOfEnumerations = 0;
    osglData->namePresent = false;    
    osglData->valuePresent = false;    
    osglData->value = "";
    osglData->solverPresent = false;    
    osglData->solver = "";
    osglData->categoryPresent = false;    
    osglData->category = "";
    osglData->typePresent = false;    
    osglData->type = "";
    osglData->varTypePresent = false;    
    osglData->varType = "";
    osglData->enumTypePresent = false;    
    osglData->enumType = "";
    osglData->descriptionPresent = false;    
    osglData->description = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_variables;
}
    break;

  case 549:

    {
        if (!osglData->namePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherVariableOptionAttributes(
                    parserData->iOther,
                    osglData->numberOfVar,
                    osglData->numberOfEnumerations,
                    osglData->name,
                    osglData->value,
                    osglData->solver,
                    osglData->category,
                    osglData->type,
                    osglData->varType,
                    osglData->enumType,
                    osglData->description) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    }
    break;

  case 552:

    {
        parserData->kounter = 0;
    }
    break;

  case 553:

    {
        parserData->kounter = 0;
    }
    break;

  case 571:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherVariableOptionVar(
                parserData->iOther, 
                parserData->kounter,
                osglData->idx, 
                osglData->name,
                osglData->value,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other variable option <var> element failed");
    parserData->kounter++;
}
    break;

  case 572:

    {
    if (parserData->kounter >= osglData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;    
    osglData->namePresent = false;    
    osglData->name = "";
    osglData->valuePresent = false;    
    osglData->value = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 576:

    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
    }
    break;

  case 586:

    {
    parserData->numberOfOtherObjectiveOptions = 0; 
    osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 587:

    {    
    if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
}
    break;

  case 589:

    {    
    parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
}
    break;

  case 594:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 596:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjValues(osglData->numberOfObj, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialObjectiveValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 597:

    {
    osglData->numberOfObjPresent = false;
}
    break;

  case 598:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[osglData->numberOfObj];
    parserData->namArray = new std::string[osglData->numberOfObj];
    parserData->valArray = new      double[osglData->numberOfObj];
    for (int i=0; i < osglData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < osglData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfObj; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 599:

    {    
        if (osglData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveValues>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 600:

    {
        if (parserData->kounter < osglData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveValues>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 607:

    {
    parserData->kounter++;
}
    break;

  case 608:

    {    
    if (parserData->kounter >= osglData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->idx = -1;
}
    break;

  case 612:

    {
        if (osglData->idx >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (osglData->idx < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = osglData->idx;
    }
    break;

  case 613:

    {
        parserData->namArray[parserData->kounter] = osglData->name;
    }
    break;

  case 614:

    {
        if (osglData->value == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((osglData->value).c_str(), NULL);
    }
    break;

  case 618:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjBounds(osglData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialObjectiveBounds> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 619:

    {
    osglData->numberOfObjPresent = false;
}
    break;

  case 620:

    {
    parserData->kounter = 0;
    parserData->idxArray   = new         int[osglData->numberOfObj];
    parserData->lbValArray = new      double[osglData->numberOfObj];
    parserData->ubValArray = new      double[osglData->numberOfObj];
    parserData->namArray   = new std::string[osglData->numberOfObj];
    for (int i=0; i < osglData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < osglData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfObj; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < osglData->numberOfObj; i++) parserData->ubValArray[i] = OSNaN();
}
    break;

  case 621:

    {
        if (osglData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveBounds>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 622:

    {
        if (parserData->kounter < osglData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 629:

    {
    parserData->kounter++;
}
    break;

  case 630:

    {    
    if (parserData->kounter >= osglData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idx = -1;
    osglData->idxPresent = false;
    osglData->namePresent = false;
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->lbValueAttribute = "-INF";
    parserData->ubValueAttribute = "INF";
}
    break;

  case 634:

    {
        if (osglData->idx >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be nonnegative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (osglData->idx < -osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = osglData->idx;
    }
    break;

  case 635:

    {
        parserData->namArray[parserData->kounter] = osglData->name;
    }
    break;

  case 636:

    {
        if (parserData->lbValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
    }
    break;

  case 637:

    {
        if (parserData->ubValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
    }
    break;

  case 642:

    {
    osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
}
    break;

  case 649:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 651:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 653:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 655:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 657:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 659:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 661:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 664:

    {      
        parserData->iOther++;  
    }
    break;

  case 665:

    {
    if (parserData->iOther >= parserData->numberOfOtherObjectiveOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherObjectiveOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->numberOfObjPresent = false;    
    osglData->numberOfObj = 0;
    osglData->numberOfEnumerationsPresent = false;    
    osglData->numberOfEnumerations = 0;
    osglData->namePresent = false;    
    osglData->valuePresent = false;    
    osglData->value = "";
    osglData->solverPresent = false;    
    osglData->solver = "";
    osglData->categoryPresent = false;    
    osglData->category = "";
    osglData->typePresent = false;    
    osglData->type = "";
    osglData->objTypePresent = false;    
    osglData->objType = "";
    osglData->enumTypePresent = false;    
    osglData->enumType = "";
    osglData->descriptionPresent = false;    
    osglData->description = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_objectives;
}
    break;

  case 666:

    {
        if (!osglData->namePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherObjectiveOptionAttributes(
                    parserData->iOther,
                    osglData->numberOfObj,
                    osglData->numberOfEnumerations,
                    osglData->name,
                    osglData->value,
                    osglData->solver,
                    osglData->category,
                    osglData->type,
                    osglData->objType,
                    osglData->enumType,
                    osglData->description) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    }
    break;

  case 669:

    {
        parserData->kounter = 0;
    }
    break;

  case 670:

    {
        parserData->kounter = 0;
    }
    break;

  case 688:

    {  
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherObjectiveOptionObj(
                parserData->iOther, 
                parserData->kounter,
                osglData->idx, 
                osglData->name,
                osglData->value,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other objective option <obj> element failed");
    parserData->kounter++;
}
    break;

  case 689:

    {

    if (parserData->kounter >= osglData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;    
    osglData->idx = -1;
    osglData->namePresent = false;    
    osglData->name = "";
    osglData->valuePresent = false;    
    osglData->value = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 693:

    {
        if (osglData->idx >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (osglData->idx < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
    }
    break;

  case 703:

    {
    parserData->numberOfOtherConstraintOptions = 0; 
    osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 704:

    {    
    if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherConstraintOptions failed");
    parserData->iOther = 0;
}
    break;

  case 706:

    {    
    parserData->numberOfOtherConstraintOptions = parserData->tempInt;
}
    break;

  case 711:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 713:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitConValues(osglData->numberOfCon, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 714:

    {
    osglData->numberOfConPresent = false;
}
    break;

  case 715:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[osglData->numberOfCon];
    parserData->namArray = new std::string[osglData->numberOfCon];
    parserData->valArray = new      double[osglData->numberOfCon];
    for (int i=0; i < osglData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfCon; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 716:

    {
        if (osglData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialConstraintValues>: expected at least one <con element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 717:

    {
        if (parserData->kounter < osglData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialConstraintValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 724:

    {
    parserData->kounter++;
}
    break;

  case 725:

    {    
    if (parserData->kounter >= osglData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->name = "";
    osglData->namePresent = false;
    osglData->valuePresent = false;
}
    break;

  case 726:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "<con> element must have idx attribute");
}
    break;

  case 729:

    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = osglData->idx;
    }
    break;

  case 730:

    {
        parserData->namArray[parserData->kounter] = osglData->name;
    }
    break;

  case 731:

    {
        if (osglData->value == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((osglData->value).c_str(), NULL);
    }
    break;

  case 735:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitDualValues(osglData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 736:

    {
    osglData->numberOfConPresent = false;
}
    break;

  case 737:

    {
    parserData->kounter = 0;
    parserData->idxArray   = new         int[osglData->numberOfCon];
    parserData->namArray   = new std::string[osglData->numberOfCon];
    parserData->lbValArray = new      double[osglData->numberOfCon];
    parserData->ubValArray = new      double[osglData->numberOfCon];
    for (int i=0; i < osglData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < osglData->numberOfCon; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < osglData->numberOfCon; i++) parserData->ubValArray[i] = OSNaN();
}
    break;

  case 738:

    {
        if (osglData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialDualValues>: expected at least one <con> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 739:

    {
        if (parserData->kounter < osglData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialDualValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 746:

    {    
    parserData->kounter++;
}
    break;

  case 747:

    {    
    if (parserData->kounter >= osglData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;
    osglData->namePresent = false;
    osglData->name = "";
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->lbDualValue = OSNaN();
    parserData->ubDualValue = OSNaN();
}
    break;

  case 748:

    {
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "<con> element must have idx attribute");
}
    break;

  case 751:

    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = osglData->idx;
    }
    break;

  case 752:

    {
        parserData->namArray[parserData->kounter] = osglData->name;
    }
    break;

  case 753:

    {
        parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
    }
    break;

  case 754:

    {
        parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
    }
    break;

  case 759:

    {
    osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
}
    break;

  case 766:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 768:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 770:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 772:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 774:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 776:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 778:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->numberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 781:

    {      
        parserData->iOther++;  
    }
    break;

  case 782:

    {
    if (parserData->iOther >= parserData->numberOfOtherConstraintOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherConstraintOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->numberOfConPresent = false;    
    osglData->numberOfCon = 0;
    osglData->numberOfEnumerationsPresent = false;    
    osglData->numberOfEnumerations = 0;
    osglData->namePresent = false;    
    osglData->valuePresent = false;    
    osglData->value = "";
    osglData->solverPresent = false;    
    osglData->solver = "";
    osglData->categoryPresent = false;    
    osglData->category = "";
    osglData->typePresent = false;    
    osglData->type = "";
    osglData->conTypePresent = false;    
    osglData->conType = "";
    osglData->enumTypePresent = false;    
    osglData->enumType = "";
    osglData->descriptionPresent = false;    
    osglData->description = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_constraints;
}
    break;

  case 783:

    {
        if(!osglData->namePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherConstraintOptionAttributes(
                    parserData->iOther,
                    osglData->numberOfCon,
                    osglData->numberOfEnumerations,
                    osglData->name,
                    osglData->value,
                    osglData->solver,
                    osglData->category,
                    osglData->type,
                    osglData->conType,
                    osglData->enumType,
                    osglData->description) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    }
    break;

  case 786:

    {
        parserData->kounter = 0;
    }
    break;

  case 787:

    {
        parserData->kounter = 0;
    }
    break;

  case 805:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherConstraintOptionCon(
                parserData->iOther, 
                parserData->kounter,
                osglData->idx, 
                osglData->name,
                osglData->value,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other constraint option <con> element failed");
    parserData->kounter++;
}
    break;

  case 806:

    {
    if (parserData->kounter >= osglData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->idxPresent = false;    
    osglData->namePresent = false;    
    osglData->name = "";
    osglData->valuePresent = false;    
    osglData->value = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 810:

    {
        if (osglData->idx < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (osglData->idx >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                    "constraint index exceeds upper limit");
        };
    }
    break;

  case 819:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 821:

    {
    if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfSolverOptions failed");
    parserData->iOption = 0;
}
    break;

  case 822:

    {
        if (parserData->numberOfSolverOptions > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <solverOption> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 823:

    {
        if (parserData->iOption != parserData->numberOfSolverOptions)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <solverOption> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 828:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setSolverOptionContent(
                    parserData->iOption, 
                    osglData->numberOfItems,
                    osglData->name,
                    osglData->value,
                    osglData->solver,
                    osglData->category,
                    osglData->type,
                    osglData->description,
                    parserData->itemList) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setSolverOptionContent failed");
    if (osglData->numberOfItems > 0)
        delete[] parserData->itemList;
    parserData->itemList = NULL;
    parserData->iOption++;
}
    break;

  case 829:

    {
    osglData->namePresent = false;
    osglData->valuePresent = false;
    osglData->solverPresent = false;
    osglData->categoryPresent = false;
    osglData->typePresent = false;
    osglData->descriptionPresent = false;
    osglData->numberOfItemsPresent = false;
    osglData->value = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->type = "";
    osglData->description = "";
    osglData->numberOfItems = 0;
    parserData->kounter = 0;
}
    break;

  case 830:

    {
    if (!osglData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "name attribute must be present");
}
    break;

  case 839:

    {
            parserData->itemList = new std::string[osglData->numberOfItems];
    }
    break;

  case 840:

    {
        if (osglData->numberOfItems > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <item> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 841:

    {
        if (parserData->kounter < osglData->numberOfItems)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <item> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 848:

    {    
    parserData->itemList[parserData->kounter] = parserData->itemContent;
    parserData->kounter++;
}
    break;

  case 849:

    {
        if (parserData->kounter >= osglData->numberOfItems)
            if (!parserData->suppressFurtherErrorMessages)
            {
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
                parserData->suppressFurtherErrorMessages = true;
                parserData->ignoreDataAfterErrors = true;
            }
        parserData->itemContent = "";            
    }
    break;

  case 854:

    {
    if (parserData->kounter >= osglData->numberOfItems)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->itemContent = (yyvsp[(1) - (1)].sval); 
    free((yyvsp[(1) - (1)].sval));
}
    break;

  case 857:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many paths in <requiredDirectories> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
        parserData->kounter++;
    }
    free((yyvsp[(3) - (4)].sval)); 
}
    break;

  case 858:

    {    
    if (parserData->kounter >= parserData->numberOfPathPairs)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many path pairs");
    else
    {
        if (!parserData->pathPairFromPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "\"from\" attribute must be present");
        if (!parserData->pathPairToPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "\"to\" attribute must be present");
           parserData->fromPaths[parserData->kounter] = parserData->pathPairFrom;
           parserData->toPaths[parserData->kounter] = parserData->pathPairTo;
        parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
         parserData->kounter++;
    }
}
    break;

  case 859:

    {
//    if (parserData->kounter >= parserData->numberOfPathPairs)
//        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many path pairs");
    parserData->pathPairFrom = "";
    parserData->pathPairTo = "";
    parserData->pathPairFromPresent = false;
    parserData->pathPairToPresent = false;
    parserData->pathPairMakeCopyPresent = false;
    parserData->pathPairMakeCopy = false;
}
    break;

  case 860:

    {
//    parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 866:

    {
    if (parserData->pathPairFromPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"from\" attribute allowed");
    parserData->pathPairFromPresent = true;
    parserData->pathPairFrom = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 867:

    {
    if (parserData->pathPairToPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"to\" attribute allowed");
    parserData->pathPairToPresent = true;
    parserData->pathPairTo = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 868:

    {
    if (parserData->pathPairMakeCopyPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"makeCopy\" attribute allowed");
    parserData->pathPairMakeCopyPresent = true;
    parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0 || strcmp((yyvsp[(2) - (3)].sval),"1") == 0);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 871:

    {
    if (parserData->groupWeightAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one groupWeight attribute allowed for this element");
    parserData->groupWeightAttributePresent = true;
}
    break;

  case 872:

    {
    parserData->groupWeight = parserData->tempVal;
}
    break;

  case 873:

    {   
    if (parserData->lbValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
    parserData->lbValueAttributePresent = true;
}
    break;

  case 876:

    { 
    parserData->lbValueAttribute = ""; 
}
    break;

  case 877:

    { 
    parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 878:

    {   if (parserData->lbValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
            parserData->lbValueAttributePresent = true;
        }
    break;

  case 881:

    { 
    parserData->lbDualValue = 0.0; 
}
    break;

  case 882:

    {
    parserData->lbDualValue = parserData->tempVal;
}
    break;

  case 883:

    {   if (parserData->sosIdxAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one sosIdx attribute allowed for this element");
        parserData->sosIdxAttributePresent = true;
    }
    break;

  case 885:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index must be nonnegative");
    parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 886:

    {
   if (parserData->ubValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
    parserData->ubValueAttributePresent = true;
}
    break;

  case 889:

    { 
    parserData->ubValueAttribute = ""; 
}
    break;

  case 890:

    { 
    parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 891:

    {   if (parserData->ubValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
            parserData->ubValueAttributePresent = true;
        }
    break;

  case 894:

    { parserData->ubDualValue = 0.0; }
    break;

  case 895:

    { 
    parserData->ubDualValue = parserData->tempVal;
}
    break;

  case 896:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 897:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other constraint options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 898:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other objective options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 899:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 900:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other variable options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 901:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of path pairs cannot be negative");
    else if ((yyvsp[(3) - (4)].ival) > 0)
    {
        parserData->fromPaths = new std::string[(yyvsp[(3) - (4)].ival)];
        parserData->toPaths   = new std::string[(yyvsp[(3) - (4)].ival)];
        parserData->makeCopy  = new bool[(yyvsp[(3) - (4)].ival)];
    }
    parserData->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 902:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of paths cannot be negative");
    else
        parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 903:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 904:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of solver options cannot be negative");
    parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 907:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherOptionOrResultEnumeration(parserData->otherOptionType, 
                parserData->iOther,
                parserData->kounter,
                osglData->numberOfEl, 
                osglData->value, 
                osglData->description, 
                osglData->osglIntArray) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "set <other> option enumeration failed");

    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->numberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 908:

    {
    if (parserData->kounter >= osglData->numberOfEnumerations)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <enumeration> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->numberOfElPresent = false;
    osglData->numberOfEl = 0;
    osglData->valuePresent = false;
    osglData->value = "";
    osglData->descriptionPresent = false;
    osglData->description = "";
}
    break;

  case 909:

    {
        if(!osglData->numberOfElPresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires numberOfEl attribute"); 
        if(!osglData->valuePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires value attribute"); 
    }
    break;

  case 912:

    {
        osglData->osglCounter = 0;
//        osglData->numberOfElPresent = true;
//        osglData->numberOfEl = parserData->numberOf;
        if (osglData->numberOfEl > 0)
            osglData->osglIntArray = new int[osglData->numberOfEl];
    }
    break;

  case 920:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 921:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 930:

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

  case 943:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 948:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 949:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 954:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 955:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 960:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 961:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 966:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 967:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 972:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 973:

    {
         if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 978:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
    osglData->incr = 0;
}
    break;

  case 984:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL IntVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->incr;    
}
    break;

  case 990:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
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

  case 992:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 999:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1006:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1013:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1020:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1027:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1034:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1040:

    {
    osglData->osglCounter = 0;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1041:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfCon attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <con> cannot be negative");
    osglData->numberOfConPresent = true;        
    osglData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1042:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of constraints cannot be negative");
    osglData->numberOfConstraintsPresent = true;        
    osglData->numberOfConstraints = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1043:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->numberOfElPresent = true;        
    osglData->numberOfEl = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1044:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfEnumerationsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <enumerations> cannot be negative");
    osglData->numberOfEnumerationsPresent = true;        
    osglData->numberOfEnumerations = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1045:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfItemsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfItems attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <items> cannot be negative");
    osglData->numberOfItemsPresent = true;        
    osglData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1046:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObj attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    osglData->numberOfObjPresent = true;        
    osglData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1047:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of objectives cannot be negative");
    osglData->numberOfObjectivesPresent = true;        
    osglData->numberOfObjectives = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1048:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVar attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <var> cannot be negative");
    osglData->numberOfVarPresent = true;        
    osglData->numberOfVar = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1049:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVariablesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of variables cannot be negative");
    osglData->numberOfVariablesPresent = true;        
    osglData->numberOfVariables = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1050:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->base64SizePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base64Size attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base64Size cannot be negative");
    osglData->base64SizePresent = true;        
    osglData->base64Size = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1051:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1052:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1053:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->multPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mult must be positive");
    osglData->multPresent = true;
    osglData->mult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1056:

    {
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;
}
    break;

  case 1057:

    { 
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;   
    osglData->category = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1060:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;  
}
    break;

  case 1061:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;   
    osglData->conType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1064:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;
}
    break;

  case 1065:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;   
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1068:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
}
    break;

  case 1069:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
    osglData->enumType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1072:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}
    break;

  case 1073:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1076:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
}
    break;

  case 1077:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
    osglData->objType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1080:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
}
    break;

  case 1081:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
    osglData->solver = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1084:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}
    break;

  case 1085:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1088:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
}
    break;

  case 1089:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
    osglData->unit = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1092:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}
    break;

  case 1093:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1096:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}
    break;

  case 1097:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
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
      yyerror (&yylloc, osoption, parserData, osglData, osnlData, YY_("syntax error"));
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
	    yyerror (&yylloc, osoption, parserData, osglData, osnlData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osoption, parserData, osglData, osnlData, YY_("syntax error"));
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
		      yytoken, &yylval, &yylloc, osoption, parserData, osglData, osnlData);
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
		  yystos[yystate], yyvsp, yylsp, osoption, parserData, osglData, osnlData);
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
  yyerror (&yylloc, osoption, parserData, osglData, osnlData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osoption, parserData, osglData, osnlData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osoption, parserData, osglData, osnlData);
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
void addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    std::ostringstream outStr;
    std::string error = errormsg;
    error = "OSoL input is either invalid or not well-formed: "  + error;
    outStr << error << std::endl;
    outStr << "Error occurred when reading: " << osolget_text ( scanner ) << std::endl; 
    outStr << "See line number: " << osolget_lineno( scanner) << std::endl; 
    error = outStr.str();

} //end addErrorMsg
#endif

std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osolget_lineno( scanner) << ": "; 
    outStr << osolget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg

void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    osnl_empty_vectors( osnlData);
    throw ErrorClass( errormsg);
} //end osolerror

void  yygetOSOption(const char *parsestring, OSOption *osoption, 
      OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) throw(ErrorClass)
{
    try{
        osol_scan_string( parsestring, scanner);
        osolset_lineno (1 , scanner );
        //
        // call the Bison parser
        //
        if(  osolparse( osoption,  parserData, osglData, osnlData) != 0) {
            //osollex_destroy(scanner);
              throw ErrorClass(  "Error parsing the OSoL file");
         }
    }
    catch(const ErrorClass& eclass){
        throw ErrorClass(  eclass.errormsg); 
    }
} //end yygetOSOption


void osol_empty_vectors( OSoLParserData* parserData){
/*
    int k;
    int numOtherVarVec = parserData->otherVarVec.size();
   
    for( k = 0; k < numOtherVarVec; k++){
        if( (parserData->otherVarVec[ k]  != NULL) && (parserData->otherVarVec[ k]->otherVarText != NULL) ) 
            delete[] parserData->otherVarVec[ k]->otherVarText;
        if( (parserData->otherVarVec[ k]  != NULL) && (parserData->otherVarVec[ k]->otherVarIndex != NULL) ) 
            delete[] parserData->otherVarVec[ k]->otherVarIndex;
            
        if( parserData->otherVarVec[ k]  != NULL) delete parserData->otherVarVec[ k];
    }

      parserData->otherVarVec.clear(); 
      
      int numDualVals =  parserData->dualVals.size();
      for(k = 0; k < numDualVals; k++){
          if( parserData->dualVals[ k]  != NULL  ) 
            delete parserData->dualVals[ k];
      }
      parserData->dualVals.clear();
      
      
       int numObjVals =  parserData->objVals.size();
      for(k = 0; k < numObjVals; k++){
          if( parserData->objVals[ k]  != NULL  ) 
            delete parserData->objVals[ k];
      }
      parserData->objVals.clear();
      
      
       int numPrimalVals =  parserData->primalVals.size();
      for(k = 0; k < numPrimalVals; k++){    
          if( parserData->primalVals[ k]  != NULL  ) 
            delete parserData->primalVals[ k];
      }
      parserData->primalVals.clear();
*/      
}//end osol_empty_vectors


