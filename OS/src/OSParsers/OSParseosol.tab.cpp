
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
     GREATERTHAN = 265,
     ENDOFELEMENT = 266,
     OSOLSTART = 267,
     OSOLSTARTEMPTY = 268,
     OSOLATTRIBUTETEXT = 269,
     OSOLEND = 270,
     EMPTYLBVALUEATT = 271,
     EMPTYUBVALUEATT = 272,
     LBVALUEATT = 273,
     UBVALUEATT = 274,
     EMPTYLBDUALVALUEATT = 275,
     EMPTYUBDUALVALUEATT = 276,
     LBDUALVALUEATT = 277,
     UBDUALVALUEATT = 278,
     WEIGHTATT = 279,
     EMPTYWEIGHTATT = 280,
     TRANSPORTTYPEATT = 281,
     LOCATIONTYPEATT = 282,
     FROMATT = 283,
     TOATT = 284,
     MAKECOPYATT = 285,
     NUMBEROFJOBIDSATT = 286,
     NUMBEROFPATHSATT = 287,
     NUMBEROFPATHPAIRSATT = 288,
     NUMBEROFPROCESSESATT = 289,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 290,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 291,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 292,
     NUMBEROFSOLVEROPTIONSATT = 293,
     NUMBEROFOTHEROPTIONSATT = 294,
     NUMBEROFSOSATT = 295,
     SOSIDXATT = 296,
     GROUPWEIGHTATT = 297,
     INSTANCELOCATIONSTART = 298,
     INSTANCELOCATIONEND = 299,
     SOLVERTOINVOKESTART = 300,
     SOLVERTOINVOKEEND = 301,
     LICENSESTART = 302,
     LICENSEEND = 303,
     USERNAMESTART = 304,
     USERNAMEEND = 305,
     PASSWORDSTART = 306,
     PASSWORDEND = 307,
     CONTACTSTART = 308,
     CONTACTEND = 309,
     MINDISKSPACESTART = 310,
     MINDISKSPACEEND = 311,
     MINMEMORYSTART = 312,
     MINMEMORYEND = 313,
     MINCPUSPEEDSTART = 314,
     MINCPUSPEEDEND = 315,
     MINCPUNUMBERSTART = 316,
     MINCPUNUMBEREND = 317,
     SERVICETYPESTART = 318,
     SERVICETYPEEND = 319,
     MAXTIMESTART = 320,
     MAXTIMEEND = 321,
     REQUESTEDSTARTTIMESTART = 322,
     REQUESTEDSTARTTIMEEND = 323,
     DEPENDENCIESSTART = 324,
     DEPENDENCIESEND = 325,
     PATHSTART = 326,
     PATHEND = 327,
     PATHPAIRSTART = 328,
     PATHPAIREND = 329,
     REQUIREDDIRECTORIESSTART = 330,
     REQUIREDDIRECTORIESEND = 331,
     REQUIREDFILESSTART = 332,
     REQUIREDFILESEND = 333,
     DIRECTORIESTOMAKESTART = 334,
     DIRECTORIESTOMAKEEND = 335,
     FILESTOMAKESTART = 336,
     FILESTOMAKEEND = 337,
     DIRECTORIESTODELETESTART = 338,
     DIRECTORIESTODELETEEND = 339,
     FILESTODELETESTART = 340,
     FILESTODELETEEND = 341,
     INPUTDIRECTORIESTOMOVESTART = 342,
     INPUTDIRECTORIESTOMOVEEND = 343,
     INPUTFILESTOMOVESTART = 344,
     INPUTFILESTOMOVEEND = 345,
     OUTPUTDIRECTORIESTOMOVESTART = 346,
     OUTPUTDIRECTORIESTOMOVEEND = 347,
     OUTPUTFILESTOMOVESTART = 348,
     OUTPUTFILESTOMOVEEND = 349,
     PROCESSESTOKILLSTART = 350,
     PROCESSESTOKILLEND = 351,
     PROCESSSTART = 352,
     PROCESSEND = 353,
     INITIALVARIABLEVALUESSTART = 354,
     INITIALVARIABLEVALUESEND = 355,
     INITIALVARIABLEVALUESSTRINGSTART = 356,
     INITIALVARIABLEVALUESSTRINGEND = 357,
     INITIALBASISSTATUSSTART = 358,
     INITIALBASISSTATUSEND = 359,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 360,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 361,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 362,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 363,
     SOSSTART = 364,
     SOSEND = 365,
     INITIALOBJECTIVEVALUESSTART = 366,
     INITIALOBJECTIVEVALUESEND = 367,
     INITIALOBJECTIVEBOUNDSSTART = 368,
     INITIALOBJECTIVEBOUNDSEND = 369,
     INITIALCONSTRAINTVALUESSTART = 370,
     INITIALCONSTRAINTVALUESEND = 371,
     INITIALDUALVALUESSTART = 372,
     INITIALDUALVALUESEND = 373,
     SOLVEROPTIONSSTART = 374,
     SOLVEROPTIONSEND = 375,
     SOLVEROPTIONSTART = 376,
     SOLVEROPTIONEND = 377,
     OTHEROPTIONSSTART = 378,
     OTHEROPTIONSEND = 379,
     HEADERSTART = 380,
     HEADEREND = 381,
     FILENAMESTART = 382,
     FILENAMEEND = 383,
     FILENAMEEMPTY = 384,
     FILENAMESTARTANDEND = 385,
     FILESOURCESTART = 386,
     FILESOURCEEND = 387,
     FILESOURCEEMPTY = 388,
     FILESOURCESTARTANDEND = 389,
     FILEDESCRIPTIONSTART = 390,
     FILEDESCRIPTIONEND = 391,
     FILEDESCRIPTIONEMPTY = 392,
     FILEDESCRIPTIONSTARTANDEND = 393,
     FILECREATORSTART = 394,
     FILECREATOREND = 395,
     FILECREATOREMPTY = 396,
     FILECREATORSTARTANDEND = 397,
     FILELICENCESTART = 398,
     FILELICENCEEND = 399,
     FILELICENCEEMPTY = 400,
     FILELICENCESTARTANDEND = 401,
     INDEXESSTART = 402,
     INDEXESEND = 403,
     VALUESSTART = 404,
     VALUESEND = 405,
     NONZEROSSTART = 406,
     NONZEROSEND = 407,
     ELSTART = 408,
     ELEND = 409,
     ENUMERATIONSTART = 410,
     ENUMERATIONEND = 411,
     ITEMEMPTY = 412,
     ITEMSTART = 413,
     ITEMEND = 414,
     ITEMSTARTANDEND = 415,
     BASE64START = 416,
     BASE64END = 417,
     NUMBEROFELATT = 418,
     NUMBEROFENUMERATIONSATT = 419,
     NUMBEROFITEMSATT = 420,
     EMPTYCATEGORYATT = 421,
     CATEGORYATT = 422,
     EMPTYDESCRIPTIONATT = 423,
     DESCRIPTIONATT = 424,
     EMPTYSOLVERATT = 425,
     SOLVERATT = 426,
     EMPTYNAMEATT = 427,
     NAMEATT = 428,
     EMPTYTYPEATT = 429,
     TYPEATT = 430,
     EMPTYENUMTYPEATT = 431,
     ENUMTYPEATT = 432,
     EMPTYSHAPEATT = 433,
     SHAPEATT = 434,
     EMPTYUNITATT = 435,
     UNITATT = 436,
     EMPTYVALUEATT = 437,
     VALUEATT = 438,
     EMPTYVALUETYPEATT = 439,
     VALUETYPEATT = 440,
     EMPTYCONTYPEATT = 441,
     CONTYPEATT = 442,
     EMPTYOBJTYPEATT = 443,
     OBJTYPEATT = 444,
     EMPTYVARTYPEATT = 445,
     VARTYPEATT = 446,
     EMPTYMATRIXCONTYPEATT = 447,
     MATRIXCONTYPEATT = 448,
     EMPTYMATRIXOBJTYPEATT = 449,
     MATRIXOBJTYPEATT = 450,
     EMPTYMATRIXVARTYPEATT = 451,
     MATRIXVARTYPEATT = 452,
     EMPTYMATRIXTYPEATT = 453,
     MATRIXTYPEATT = 454,
     EMPTYSYMMETRYATT = 455,
     SYMMETRYATT = 456,
     EMPTYROWMAJORATT = 457,
     ROWMAJORATT = 458,
     EMPTYBASETRANSPOSEATT = 459,
     BASETRANSPOSEATT = 460,
     NUMBEROFBLOCKSATT = 461,
     NUMBEROFCOLUMNSATT = 462,
     NUMBEROFROWSATT = 463,
     NUMBEROFMATRICESATT = 464,
     NUMBEROFVALUESATT = 465,
     NUMBEROFCONSTRAINTSATT = 466,
     NUMBEROFCONATT = 467,
     NUMBEROFCONIDXATT = 468,
     NUMBEROFOBJECTIVESATT = 469,
     NUMBEROFOBJATT = 470,
     NUMBEROFOBJIDXATT = 471,
     NUMBEROFVARIABLESATT = 472,
     NUMBEROFVARATT = 473,
     NUMBEROFVARIDXATT = 474,
     NUMBEROFMATRIXCONATT = 475,
     NUMBEROFMATRIXOBJATT = 476,
     NUMBEROFMATRIXVARATT = 477,
     BASEMATRIXIDXATT = 478,
     TARGETMATRIXFIRSTROWATT = 479,
     TARGETMATRIXFIRSTCOLATT = 480,
     BASEMATRIXSTARTROWATT = 481,
     BASEMATRIXSTARTCOLATT = 482,
     BASEMATRIXENDROWATT = 483,
     BASEMATRIXENDCOLATT = 484,
     SCALARMULTIPLIERATT = 485,
     BLOCKROWIDXATT = 486,
     BLOCKCOLIDXATT = 487,
     REATT = 488,
     IMATT = 489,
     MATRIXVARIDXATT = 490,
     MATRIXOBJIDXATT = 491,
     MATRIXCONIDXATT = 492,
     IDXATT = 493,
     INCRATT = 494,
     MULTATT = 495,
     SIZEOFATT = 496,
     COEFATT = 497,
     CONSTANTATT = 498,
     MATRICESSTART = 499,
     MATRICESEND = 500,
     MATRIXSTART = 501,
     MATRIXEND = 502,
     BASEMATRIXEND = 503,
     BASEMATRIXSTART = 504,
     BLOCKSSTART = 505,
     BLOCKSEND = 506,
     BLOCKSTART = 507,
     BLOCKEND = 508,
     COLOFFSETSTART = 509,
     COLOFFSETEND = 510,
     ROWOFFSETSTART = 511,
     ROWOFFSETEND = 512,
     ELEMENTSSTART = 513,
     ELEMENTSEND = 514,
     CONSTANTELEMENTSSTART = 515,
     CONSTANTELEMENTSEND = 516,
     COMPLEXELEMENTSSTART = 517,
     COMPLEXELEMENTSEND = 518,
     VARREFERENCEELEMENTSSTART = 519,
     VARREFERENCEELEMENTSEND = 520,
     LINEARELEMENTSSTART = 521,
     LINEARELEMENTSEND = 522,
     CONREFERENCEELEMENTSSTART = 523,
     CONREFERENCEELEMENTSEND = 524,
     OBJREFERENCEELEMENTSSTART = 525,
     OBJREFERENCEELEMENTSEND = 526,
     REALVALUEDEXPRESSIONSSTART = 527,
     REALVALUEDEXPRESSIONSSEND = 528,
     COMPLEXVALUEDEXPRESSIONSSTART = 529,
     COMPLEXVALUEDEXPRESSIONSSEND = 530,
     STRINGVALUEDELEMENTSSTART = 531,
     STRINGVALUEDELEMENTSEND = 532,
     STARTVECTORSTART = 533,
     STARTVECTOREND = 534,
     INDEXSTART = 535,
     INDEXEND = 536,
     VALUESTART = 537,
     VALUEEND = 538,
     VARIDXSTART = 539,
     VARIDXEND = 540,
     TRANSFORMATIONSTART = 541,
     TRANSFORMATIONEND = 542,
     MATRIXPROGRAMMINGSTART = 543,
     MATRIXPROGRAMMINGEND = 544,
     MATRIXVARIABLESSTART = 545,
     MATRIXVARIABLESEND = 546,
     MATRIXVARSTART = 547,
     MATRIXVAREND = 548,
     MATRIXOBJECTIVESSTART = 549,
     MATRIXOBJECTIVESEND = 550,
     MATRIXOBJSTART = 551,
     MATRIXOBJEND = 552,
     MATRIXCONSTRAINTSSTART = 553,
     MATRIXCONSTRAINTSEND = 554,
     MATRIXCONSTART = 555,
     MATRIXCONEND = 556,
     CONSTART = 557,
     CONEND = 558,
     CONSTRAINTSSTART = 559,
     CONSTRAINTSEND = 560,
     OBJSTART = 561,
     OBJEND = 562,
     OBJECTIVESSTART = 563,
     OBJECTIVESEND = 564,
     VARSTART = 565,
     VAREND = 566,
     VARIABLESSTART = 567,
     VARIABLESEND = 568,
     GENERALSTART = 569,
     GENERALEND = 570,
     SYSTEMSTART = 571,
     SYSTEMEND = 572,
     SERVICESTART = 573,
     SERVICEEND = 574,
     JOBSTART = 575,
     JOBEND = 576,
     OPTIMIZATIONSTART = 577,
     OPTIMIZATIONEND = 578,
     ATEQUALITYSTART = 579,
     ATEQUALITYEND = 580,
     ATLOWERSTART = 581,
     ATLOWEREND = 582,
     ATUPPERSTART = 583,
     ATUPPEREND = 584,
     BASICSTART = 585,
     BASICEND = 586,
     ISFREESTART = 587,
     ISFREEEND = 588,
     SUPERBASICSTART = 589,
     SUPERBASICEND = 590,
     UNKNOWNSTART = 591,
     UNKNOWNEND = 592,
     SERVICEURISTART = 593,
     SERVICEURIEND = 594,
     SERVICENAMESTART = 595,
     SERVICENAMEEND = 596,
     INSTANCENAMESTART = 597,
     INSTANCENAMEEND = 598,
     JOBIDSTART = 599,
     JOBIDEND = 600,
     OTHERSTART = 601,
     OTHEREND = 602,
     DUMMY = 603,
     NONLINEAREXPRESSIONSSTART = 604,
     NONLINEAREXPRESSIONSEND = 605,
     NUMBEROFNONLINEAREXPRESSIONS = 606,
     NLSTART = 607,
     NLEND = 608,
     MATRIXEXPRESSIONSSTART = 609,
     MATRIXEXPRESSIONSEND = 610,
     NUMBEROFEXPR = 611,
     EXPRSTART = 612,
     EXPREND = 613,
     NUMBEROFMATRIXTERMSATT = 614,
     MATRIXTERMSTART = 615,
     MATRIXTERMEND = 616,
     POWERSTART = 617,
     POWEREND = 618,
     PLUSSTART = 619,
     PLUSEND = 620,
     MINUSSTART = 621,
     MINUSEND = 622,
     DIVIDESTART = 623,
     DIVIDEEND = 624,
     LNSTART = 625,
     LNEND = 626,
     SQRTSTART = 627,
     SQRTEND = 628,
     SUMSTART = 629,
     SUMEND = 630,
     PRODUCTSTART = 631,
     PRODUCTEND = 632,
     EXPSTART = 633,
     EXPEND = 634,
     NEGATESTART = 635,
     NEGATEEND = 636,
     IFSTART = 637,
     IFEND = 638,
     SQUARESTART = 639,
     SQUAREEND = 640,
     COSSTART = 641,
     COSEND = 642,
     SINSTART = 643,
     SINEND = 644,
     VARIABLESTART = 645,
     VARIABLEEND = 646,
     ABSSTART = 647,
     ABSEND = 648,
     ERFSTART = 649,
     ERFEND = 650,
     MAXSTART = 651,
     MAXEND = 652,
     ALLDIFFSTART = 653,
     ALLDIFFEND = 654,
     MINSTART = 655,
     MINEND = 656,
     ESTART = 657,
     EEND = 658,
     PISTART = 659,
     PIEND = 660,
     TIMESSTART = 661,
     TIMESEND = 662,
     NUMBERSTART = 663,
     NUMBEREND = 664,
     MATRIXDETERMINANTSTART = 665,
     MATRIXDETERMINANTEND = 666,
     MATRIXTRACESTART = 667,
     MATRIXTRACEEND = 668,
     MATRIXTOSCALARSTART = 669,
     MATRIXTOSCALAREND = 670,
     MATRIXDIAGONALSTART = 671,
     MATRIXDIAGONALEND = 672,
     MATRIXDOTTIMESSTART = 673,
     MATRIXDOTTIMESEND = 674,
     MATRIXLOWERTRIANGLESTART = 675,
     MATRIXLOWERTRIANGLEEND = 676,
     MATRIXUPPERTRIANGLESTART = 677,
     MATRIXUPPERTRIANGLEEND = 678,
     MATRIXMERGESTART = 679,
     MATRIXMERGEEND = 680,
     MATRIXMINUSSTART = 681,
     MATRIXMINUSEND = 682,
     MATRIXNEGATESTART = 683,
     MATRIXNEGATEEND = 684,
     MATRIXPLUSSTART = 685,
     MATRIXPLUSEND = 686,
     MATRIXTIMESSTART = 687,
     MATRIXTIMESEND = 688,
     MATRIXPRODUCTSTART = 689,
     MATRIXPRODUCTEND = 690,
     MATRIXSCALARTIMESSTART = 691,
     MATRIXSCALARTIMESEND = 692,
     MATRIXSUBMATRIXATSTART = 693,
     MATRIXSUBMATRIXATEND = 694,
     MATRIXTRANSPOSESTART = 695,
     MATRIXTRANSPOSEEND = 696,
     MATRIXREFERENCESTART = 697,
     MATRIXREFERENCEEND = 698,
     IDENTITYMATRIXSTART = 699,
     IDENTITYMATRIXEND = 700,
     MATRIXINVERSESTART = 701,
     MATRIXINVERSEEND = 702,
     COMPLEXCONJUGATESTART = 703,
     COMPLEXCONJUGATEEND = 704,
     COMPLEXMINUSSTART = 705,
     COMPLEXMINUSEND = 706,
     COMPLEXNEGATESTART = 707,
     COMPLEXNEGATEEND = 708,
     COMPLEXNUMBERSTART = 709,
     COMPLEXNUMBEREND = 710,
     COMPLEXPLUSSTART = 711,
     COMPLEXPLUSEND = 712,
     COMPLEXSQUARESTART = 713,
     COMPLEXSQUAREEND = 714,
     COMPLEXSUMSTART = 715,
     COMPLEXSUMEND = 716,
     COMPLEXTIMESSTART = 717,
     COMPLEXTIMESEND = 718,
     CREATECOMPLEXSTART = 719,
     CREATECOMPLEXEND = 720,
     EMPTYINCLUDEDIAGONALATT = 721,
     INCLUDEDIAGONALATT = 722,
     EMPTYIDATT = 723,
     IDATT = 724
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
#define OSOLSTART 267
#define OSOLSTARTEMPTY 268
#define OSOLATTRIBUTETEXT 269
#define OSOLEND 270
#define EMPTYLBVALUEATT 271
#define EMPTYUBVALUEATT 272
#define LBVALUEATT 273
#define UBVALUEATT 274
#define EMPTYLBDUALVALUEATT 275
#define EMPTYUBDUALVALUEATT 276
#define LBDUALVALUEATT 277
#define UBDUALVALUEATT 278
#define WEIGHTATT 279
#define EMPTYWEIGHTATT 280
#define TRANSPORTTYPEATT 281
#define LOCATIONTYPEATT 282
#define FROMATT 283
#define TOATT 284
#define MAKECOPYATT 285
#define NUMBEROFJOBIDSATT 286
#define NUMBEROFPATHSATT 287
#define NUMBEROFPATHPAIRSATT 288
#define NUMBEROFPROCESSESATT 289
#define NUMBEROFOTHERVARIABLEOPTIONSATT 290
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 291
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 292
#define NUMBEROFSOLVEROPTIONSATT 293
#define NUMBEROFOTHEROPTIONSATT 294
#define NUMBEROFSOSATT 295
#define SOSIDXATT 296
#define GROUPWEIGHTATT 297
#define INSTANCELOCATIONSTART 298
#define INSTANCELOCATIONEND 299
#define SOLVERTOINVOKESTART 300
#define SOLVERTOINVOKEEND 301
#define LICENSESTART 302
#define LICENSEEND 303
#define USERNAMESTART 304
#define USERNAMEEND 305
#define PASSWORDSTART 306
#define PASSWORDEND 307
#define CONTACTSTART 308
#define CONTACTEND 309
#define MINDISKSPACESTART 310
#define MINDISKSPACEEND 311
#define MINMEMORYSTART 312
#define MINMEMORYEND 313
#define MINCPUSPEEDSTART 314
#define MINCPUSPEEDEND 315
#define MINCPUNUMBERSTART 316
#define MINCPUNUMBEREND 317
#define SERVICETYPESTART 318
#define SERVICETYPEEND 319
#define MAXTIMESTART 320
#define MAXTIMEEND 321
#define REQUESTEDSTARTTIMESTART 322
#define REQUESTEDSTARTTIMEEND 323
#define DEPENDENCIESSTART 324
#define DEPENDENCIESEND 325
#define PATHSTART 326
#define PATHEND 327
#define PATHPAIRSTART 328
#define PATHPAIREND 329
#define REQUIREDDIRECTORIESSTART 330
#define REQUIREDDIRECTORIESEND 331
#define REQUIREDFILESSTART 332
#define REQUIREDFILESEND 333
#define DIRECTORIESTOMAKESTART 334
#define DIRECTORIESTOMAKEEND 335
#define FILESTOMAKESTART 336
#define FILESTOMAKEEND 337
#define DIRECTORIESTODELETESTART 338
#define DIRECTORIESTODELETEEND 339
#define FILESTODELETESTART 340
#define FILESTODELETEEND 341
#define INPUTDIRECTORIESTOMOVESTART 342
#define INPUTDIRECTORIESTOMOVEEND 343
#define INPUTFILESTOMOVESTART 344
#define INPUTFILESTOMOVEEND 345
#define OUTPUTDIRECTORIESTOMOVESTART 346
#define OUTPUTDIRECTORIESTOMOVEEND 347
#define OUTPUTFILESTOMOVESTART 348
#define OUTPUTFILESTOMOVEEND 349
#define PROCESSESTOKILLSTART 350
#define PROCESSESTOKILLEND 351
#define PROCESSSTART 352
#define PROCESSEND 353
#define INITIALVARIABLEVALUESSTART 354
#define INITIALVARIABLEVALUESEND 355
#define INITIALVARIABLEVALUESSTRINGSTART 356
#define INITIALVARIABLEVALUESSTRINGEND 357
#define INITIALBASISSTATUSSTART 358
#define INITIALBASISSTATUSEND 359
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 360
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 361
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 362
#define SOSVARIABLEBRANCHINGWEIGHTSEND 363
#define SOSSTART 364
#define SOSEND 365
#define INITIALOBJECTIVEVALUESSTART 366
#define INITIALOBJECTIVEVALUESEND 367
#define INITIALOBJECTIVEBOUNDSSTART 368
#define INITIALOBJECTIVEBOUNDSEND 369
#define INITIALCONSTRAINTVALUESSTART 370
#define INITIALCONSTRAINTVALUESEND 371
#define INITIALDUALVALUESSTART 372
#define INITIALDUALVALUESEND 373
#define SOLVEROPTIONSSTART 374
#define SOLVEROPTIONSEND 375
#define SOLVEROPTIONSTART 376
#define SOLVEROPTIONEND 377
#define OTHEROPTIONSSTART 378
#define OTHEROPTIONSEND 379
#define HEADERSTART 380
#define HEADEREND 381
#define FILENAMESTART 382
#define FILENAMEEND 383
#define FILENAMEEMPTY 384
#define FILENAMESTARTANDEND 385
#define FILESOURCESTART 386
#define FILESOURCEEND 387
#define FILESOURCEEMPTY 388
#define FILESOURCESTARTANDEND 389
#define FILEDESCRIPTIONSTART 390
#define FILEDESCRIPTIONEND 391
#define FILEDESCRIPTIONEMPTY 392
#define FILEDESCRIPTIONSTARTANDEND 393
#define FILECREATORSTART 394
#define FILECREATOREND 395
#define FILECREATOREMPTY 396
#define FILECREATORSTARTANDEND 397
#define FILELICENCESTART 398
#define FILELICENCEEND 399
#define FILELICENCEEMPTY 400
#define FILELICENCESTARTANDEND 401
#define INDEXESSTART 402
#define INDEXESEND 403
#define VALUESSTART 404
#define VALUESEND 405
#define NONZEROSSTART 406
#define NONZEROSEND 407
#define ELSTART 408
#define ELEND 409
#define ENUMERATIONSTART 410
#define ENUMERATIONEND 411
#define ITEMEMPTY 412
#define ITEMSTART 413
#define ITEMEND 414
#define ITEMSTARTANDEND 415
#define BASE64START 416
#define BASE64END 417
#define NUMBEROFELATT 418
#define NUMBEROFENUMERATIONSATT 419
#define NUMBEROFITEMSATT 420
#define EMPTYCATEGORYATT 421
#define CATEGORYATT 422
#define EMPTYDESCRIPTIONATT 423
#define DESCRIPTIONATT 424
#define EMPTYSOLVERATT 425
#define SOLVERATT 426
#define EMPTYNAMEATT 427
#define NAMEATT 428
#define EMPTYTYPEATT 429
#define TYPEATT 430
#define EMPTYENUMTYPEATT 431
#define ENUMTYPEATT 432
#define EMPTYSHAPEATT 433
#define SHAPEATT 434
#define EMPTYUNITATT 435
#define UNITATT 436
#define EMPTYVALUEATT 437
#define VALUEATT 438
#define EMPTYVALUETYPEATT 439
#define VALUETYPEATT 440
#define EMPTYCONTYPEATT 441
#define CONTYPEATT 442
#define EMPTYOBJTYPEATT 443
#define OBJTYPEATT 444
#define EMPTYVARTYPEATT 445
#define VARTYPEATT 446
#define EMPTYMATRIXCONTYPEATT 447
#define MATRIXCONTYPEATT 448
#define EMPTYMATRIXOBJTYPEATT 449
#define MATRIXOBJTYPEATT 450
#define EMPTYMATRIXVARTYPEATT 451
#define MATRIXVARTYPEATT 452
#define EMPTYMATRIXTYPEATT 453
#define MATRIXTYPEATT 454
#define EMPTYSYMMETRYATT 455
#define SYMMETRYATT 456
#define EMPTYROWMAJORATT 457
#define ROWMAJORATT 458
#define EMPTYBASETRANSPOSEATT 459
#define BASETRANSPOSEATT 460
#define NUMBEROFBLOCKSATT 461
#define NUMBEROFCOLUMNSATT 462
#define NUMBEROFROWSATT 463
#define NUMBEROFMATRICESATT 464
#define NUMBEROFVALUESATT 465
#define NUMBEROFCONSTRAINTSATT 466
#define NUMBEROFCONATT 467
#define NUMBEROFCONIDXATT 468
#define NUMBEROFOBJECTIVESATT 469
#define NUMBEROFOBJATT 470
#define NUMBEROFOBJIDXATT 471
#define NUMBEROFVARIABLESATT 472
#define NUMBEROFVARATT 473
#define NUMBEROFVARIDXATT 474
#define NUMBEROFMATRIXCONATT 475
#define NUMBEROFMATRIXOBJATT 476
#define NUMBEROFMATRIXVARATT 477
#define BASEMATRIXIDXATT 478
#define TARGETMATRIXFIRSTROWATT 479
#define TARGETMATRIXFIRSTCOLATT 480
#define BASEMATRIXSTARTROWATT 481
#define BASEMATRIXSTARTCOLATT 482
#define BASEMATRIXENDROWATT 483
#define BASEMATRIXENDCOLATT 484
#define SCALARMULTIPLIERATT 485
#define BLOCKROWIDXATT 486
#define BLOCKCOLIDXATT 487
#define REATT 488
#define IMATT 489
#define MATRIXVARIDXATT 490
#define MATRIXOBJIDXATT 491
#define MATRIXCONIDXATT 492
#define IDXATT 493
#define INCRATT 494
#define MULTATT 495
#define SIZEOFATT 496
#define COEFATT 497
#define CONSTANTATT 498
#define MATRICESSTART 499
#define MATRICESEND 500
#define MATRIXSTART 501
#define MATRIXEND 502
#define BASEMATRIXEND 503
#define BASEMATRIXSTART 504
#define BLOCKSSTART 505
#define BLOCKSEND 506
#define BLOCKSTART 507
#define BLOCKEND 508
#define COLOFFSETSTART 509
#define COLOFFSETEND 510
#define ROWOFFSETSTART 511
#define ROWOFFSETEND 512
#define ELEMENTSSTART 513
#define ELEMENTSEND 514
#define CONSTANTELEMENTSSTART 515
#define CONSTANTELEMENTSEND 516
#define COMPLEXELEMENTSSTART 517
#define COMPLEXELEMENTSEND 518
#define VARREFERENCEELEMENTSSTART 519
#define VARREFERENCEELEMENTSEND 520
#define LINEARELEMENTSSTART 521
#define LINEARELEMENTSEND 522
#define CONREFERENCEELEMENTSSTART 523
#define CONREFERENCEELEMENTSEND 524
#define OBJREFERENCEELEMENTSSTART 525
#define OBJREFERENCEELEMENTSEND 526
#define REALVALUEDEXPRESSIONSSTART 527
#define REALVALUEDEXPRESSIONSSEND 528
#define COMPLEXVALUEDEXPRESSIONSSTART 529
#define COMPLEXVALUEDEXPRESSIONSSEND 530
#define STRINGVALUEDELEMENTSSTART 531
#define STRINGVALUEDELEMENTSEND 532
#define STARTVECTORSTART 533
#define STARTVECTOREND 534
#define INDEXSTART 535
#define INDEXEND 536
#define VALUESTART 537
#define VALUEEND 538
#define VARIDXSTART 539
#define VARIDXEND 540
#define TRANSFORMATIONSTART 541
#define TRANSFORMATIONEND 542
#define MATRIXPROGRAMMINGSTART 543
#define MATRIXPROGRAMMINGEND 544
#define MATRIXVARIABLESSTART 545
#define MATRIXVARIABLESEND 546
#define MATRIXVARSTART 547
#define MATRIXVAREND 548
#define MATRIXOBJECTIVESSTART 549
#define MATRIXOBJECTIVESEND 550
#define MATRIXOBJSTART 551
#define MATRIXOBJEND 552
#define MATRIXCONSTRAINTSSTART 553
#define MATRIXCONSTRAINTSEND 554
#define MATRIXCONSTART 555
#define MATRIXCONEND 556
#define CONSTART 557
#define CONEND 558
#define CONSTRAINTSSTART 559
#define CONSTRAINTSEND 560
#define OBJSTART 561
#define OBJEND 562
#define OBJECTIVESSTART 563
#define OBJECTIVESEND 564
#define VARSTART 565
#define VAREND 566
#define VARIABLESSTART 567
#define VARIABLESEND 568
#define GENERALSTART 569
#define GENERALEND 570
#define SYSTEMSTART 571
#define SYSTEMEND 572
#define SERVICESTART 573
#define SERVICEEND 574
#define JOBSTART 575
#define JOBEND 576
#define OPTIMIZATIONSTART 577
#define OPTIMIZATIONEND 578
#define ATEQUALITYSTART 579
#define ATEQUALITYEND 580
#define ATLOWERSTART 581
#define ATLOWEREND 582
#define ATUPPERSTART 583
#define ATUPPEREND 584
#define BASICSTART 585
#define BASICEND 586
#define ISFREESTART 587
#define ISFREEEND 588
#define SUPERBASICSTART 589
#define SUPERBASICEND 590
#define UNKNOWNSTART 591
#define UNKNOWNEND 592
#define SERVICEURISTART 593
#define SERVICEURIEND 594
#define SERVICENAMESTART 595
#define SERVICENAMEEND 596
#define INSTANCENAMESTART 597
#define INSTANCENAMEEND 598
#define JOBIDSTART 599
#define JOBIDEND 600
#define OTHERSTART 601
#define OTHEREND 602
#define DUMMY 603
#define NONLINEAREXPRESSIONSSTART 604
#define NONLINEAREXPRESSIONSEND 605
#define NUMBEROFNONLINEAREXPRESSIONS 606
#define NLSTART 607
#define NLEND 608
#define MATRIXEXPRESSIONSSTART 609
#define MATRIXEXPRESSIONSEND 610
#define NUMBEROFEXPR 611
#define EXPRSTART 612
#define EXPREND 613
#define NUMBEROFMATRIXTERMSATT 614
#define MATRIXTERMSTART 615
#define MATRIXTERMEND 616
#define POWERSTART 617
#define POWEREND 618
#define PLUSSTART 619
#define PLUSEND 620
#define MINUSSTART 621
#define MINUSEND 622
#define DIVIDESTART 623
#define DIVIDEEND 624
#define LNSTART 625
#define LNEND 626
#define SQRTSTART 627
#define SQRTEND 628
#define SUMSTART 629
#define SUMEND 630
#define PRODUCTSTART 631
#define PRODUCTEND 632
#define EXPSTART 633
#define EXPEND 634
#define NEGATESTART 635
#define NEGATEEND 636
#define IFSTART 637
#define IFEND 638
#define SQUARESTART 639
#define SQUAREEND 640
#define COSSTART 641
#define COSEND 642
#define SINSTART 643
#define SINEND 644
#define VARIABLESTART 645
#define VARIABLEEND 646
#define ABSSTART 647
#define ABSEND 648
#define ERFSTART 649
#define ERFEND 650
#define MAXSTART 651
#define MAXEND 652
#define ALLDIFFSTART 653
#define ALLDIFFEND 654
#define MINSTART 655
#define MINEND 656
#define ESTART 657
#define EEND 658
#define PISTART 659
#define PIEND 660
#define TIMESSTART 661
#define TIMESEND 662
#define NUMBERSTART 663
#define NUMBEREND 664
#define MATRIXDETERMINANTSTART 665
#define MATRIXDETERMINANTEND 666
#define MATRIXTRACESTART 667
#define MATRIXTRACEEND 668
#define MATRIXTOSCALARSTART 669
#define MATRIXTOSCALAREND 670
#define MATRIXDIAGONALSTART 671
#define MATRIXDIAGONALEND 672
#define MATRIXDOTTIMESSTART 673
#define MATRIXDOTTIMESEND 674
#define MATRIXLOWERTRIANGLESTART 675
#define MATRIXLOWERTRIANGLEEND 676
#define MATRIXUPPERTRIANGLESTART 677
#define MATRIXUPPERTRIANGLEEND 678
#define MATRIXMERGESTART 679
#define MATRIXMERGEEND 680
#define MATRIXMINUSSTART 681
#define MATRIXMINUSEND 682
#define MATRIXNEGATESTART 683
#define MATRIXNEGATEEND 684
#define MATRIXPLUSSTART 685
#define MATRIXPLUSEND 686
#define MATRIXTIMESSTART 687
#define MATRIXTIMESEND 688
#define MATRIXPRODUCTSTART 689
#define MATRIXPRODUCTEND 690
#define MATRIXSCALARTIMESSTART 691
#define MATRIXSCALARTIMESEND 692
#define MATRIXSUBMATRIXATSTART 693
#define MATRIXSUBMATRIXATEND 694
#define MATRIXTRANSPOSESTART 695
#define MATRIXTRANSPOSEEND 696
#define MATRIXREFERENCESTART 697
#define MATRIXREFERENCEEND 698
#define IDENTITYMATRIXSTART 699
#define IDENTITYMATRIXEND 700
#define MATRIXINVERSESTART 701
#define MATRIXINVERSEEND 702
#define COMPLEXCONJUGATESTART 703
#define COMPLEXCONJUGATEEND 704
#define COMPLEXMINUSSTART 705
#define COMPLEXMINUSEND 706
#define COMPLEXNEGATESTART 707
#define COMPLEXNEGATEEND 708
#define COMPLEXNUMBERSTART 709
#define COMPLEXNUMBEREND 710
#define COMPLEXPLUSSTART 711
#define COMPLEXPLUSEND 712
#define COMPLEXSQUARESTART 713
#define COMPLEXSQUAREEND 714
#define COMPLEXSUMSTART 715
#define COMPLEXSUMEND 716
#define COMPLEXTIMESSTART 717
#define COMPLEXTIMESEND 718
#define CREATECOMPLEXSTART 719
#define CREATECOMPLEXEND 720
#define EMPTYINCLUDEDIAGONALATT 721
#define INCLUDEDIAGONALATT 722
#define EMPTYIDATT 723
#define IDATT 724




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
#define YYNTOKENS  474
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  720
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1097
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1501

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   724

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   471,
     473,     2,     2,   472,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   470,     2,     2,     2,     2,     2,     2,     2,
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
     465,   466,   467,   468,   469
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
     475,     0,    -1,   476,   484,   482,    -1,   477,   478,   479,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   480,    -1,
     481,    -1,    11,    -1,    10,   484,   482,    -1,   483,    -1,
      15,    -1,    -1,   485,   486,   572,   615,   638,   749,    -1,
      -1,  1065,    -1,    -1,   487,   488,    -1,   314,    -1,   489,
      -1,   490,    -1,    10,   315,    -1,    11,    -1,    10,   491,
     315,    -1,   492,    -1,   493,    -1,   492,   493,    -1,   494,
      -1,   500,    -1,   506,    -1,   512,    -1,   520,    -1,   526,
      -1,   532,    -1,   538,    -1,   544,    -1,   550,    -1,   558,
      -1,   495,   496,    -1,   338,    -1,   497,    -1,   498,    -1,
      10,   339,    -1,    11,    -1,    10,   499,   339,    -1,     4,
      -1,   501,   502,    -1,   340,    -1,   503,    -1,   504,    -1,
      10,   341,    -1,    11,    -1,    10,   505,   341,    -1,     4,
      -1,   507,   508,    -1,   342,    -1,   509,    -1,   510,    -1,
      10,   343,    -1,    11,    -1,    10,   511,   343,    -1,     4,
      -1,   513,   514,   516,    -1,    43,    -1,    -1,   515,    -1,
      27,     3,     8,    -1,   517,    -1,   518,    -1,    10,    44,
      -1,    11,    -1,    10,   519,    44,    -1,     4,    -1,   521,
     522,    -1,   344,    -1,   523,    -1,   524,    -1,    10,   345,
      -1,    11,    -1,    10,   525,   345,    -1,     4,    -1,   527,
     528,    -1,    45,    -1,   529,    -1,   530,    -1,    10,    46,
      -1,    11,    -1,    10,   531,    46,    -1,     4,    -1,   533,
     534,    -1,    47,    -1,   535,    -1,   536,    -1,    10,    48,
      -1,    11,    -1,    10,   537,    48,    -1,     4,    -1,   539,
     540,    -1,    49,    -1,   541,    -1,   542,    -1,    10,    50,
      -1,    11,    -1,    10,   543,    50,    -1,     4,    -1,   545,
     546,    -1,    51,    -1,   547,    -1,   548,    -1,    10,    52,
      -1,    11,    -1,    10,   549,    52,    -1,     4,    -1,   551,
     552,   554,    -1,    53,    -1,    -1,   553,    -1,    26,     3,
       8,    -1,   555,    -1,   556,    -1,    10,    54,    -1,    11,
      -1,    10,   557,    54,    -1,     4,    -1,   559,   560,   561,
      -1,   123,    -1,  1045,    -1,   562,    -1,   563,    -1,    10,
     124,    -1,    11,    -1,    10,   564,   124,    -1,   565,    -1,
     566,    -1,   565,   566,    -1,   567,   568,   571,    -1,   346,
      -1,   569,    -1,    -1,   569,   570,    -1,  1173,    -1,  1188,
      -1,  1167,    -1,    10,   347,    -1,    11,    -1,    -1,   573,
     574,    -1,   316,    -1,   575,    -1,   576,    -1,    10,   317,
      -1,    11,    -1,    10,   577,   317,    -1,   578,    -1,   579,
      -1,   578,   579,    -1,   580,    -1,   587,    -1,   594,    -1,
     601,    -1,   606,    -1,   581,   582,   585,    -1,    55,    -1,
     583,    -1,    -1,   583,   584,    -1,  1185,    -1,  1167,    -1,
      10,   586,    56,    -1,  1061,    -1,   588,   589,   592,    -1,
      57,    -1,   590,    -1,    -1,   590,   591,    -1,  1185,    -1,
    1167,    -1,    10,   593,    58,    -1,  1061,    -1,   595,   596,
     599,    -1,    59,    -1,   597,    -1,    -1,   597,   598,    -1,
    1185,    -1,  1167,    -1,    10,   600,    60,    -1,  1061,    -1,
     602,   603,   604,    -1,    61,    -1,    -1,  1167,    -1,    10,
     605,    62,    -1,     6,    -1,   607,   608,   609,    -1,   123,
      -1,  1045,    -1,   610,    -1,   611,    -1,    10,   124,    -1,
      11,    -1,    10,   612,   124,    -1,   613,    -1,   614,    -1,
     613,   614,    -1,   567,   568,   571,    -1,    -1,   616,   617,
      -1,   318,    -1,   618,    -1,   619,    -1,    10,   319,    -1,
      11,    -1,    10,   620,   319,    -1,   621,    -1,   622,    -1,
     621,   622,    -1,   623,    -1,   629,    -1,   624,   625,    -1,
      63,    -1,   626,    -1,   627,    -1,    10,    64,    -1,    11,
      -1,    10,   628,    64,    -1,     4,    -1,   630,   631,   632,
      -1,   123,    -1,  1045,    -1,   633,    -1,   634,    -1,    10,
     124,    -1,    11,    -1,    10,   635,   124,    -1,   636,    -1,
     637,    -1,   636,   637,    -1,   567,   568,   571,    -1,    -1,
     639,   640,    -1,   320,    -1,   641,    -1,   642,    -1,    10,
     321,    -1,    11,    -1,    10,   643,   321,    -1,   644,    -1,
     645,    -1,   644,   645,    -1,   646,    -1,   654,    -1,   660,
      -1,   668,    -1,   673,    -1,   678,    -1,   683,    -1,   688,
      -1,   696,    -1,   712,    -1,   704,    -1,   720,    -1,   726,
      -1,   732,    -1,   740,    -1,   647,   648,   649,    -1,    65,
      -1,    -1,  1185,    -1,   650,    -1,   651,    -1,    10,    66,
      -1,    11,    -1,    10,   652,    66,    -1,   653,    -1,  1061,
      -1,   655,   656,    -1,    67,    -1,   657,    -1,   658,    -1,
      10,    68,    -1,    11,    -1,    10,   659,    68,    -1,     4,
      -1,   661,   662,   663,    -1,    69,    -1,  1042,    -1,   664,
      -1,   665,    -1,    10,    70,    -1,    11,    -1,    10,   666,
      70,    -1,   667,    -1,   666,   667,    -1,   344,    10,     4,
     345,    -1,   669,  1048,   670,    -1,    75,    -1,   671,    -1,
     672,    -1,    10,    76,    -1,    11,    -1,    10,  1010,    76,
      -1,   674,  1048,   675,    -1,    77,    -1,   676,    -1,   677,
      -1,    10,    78,    -1,    11,    -1,    10,  1010,    78,    -1,
     679,  1048,   680,    -1,    79,    -1,   681,    -1,   682,    -1,
      10,    80,    -1,    11,    -1,    10,  1010,    80,    -1,   684,
    1048,   685,    -1,    81,    -1,   686,    -1,   687,    -1,    10,
      82,    -1,    11,    -1,    10,  1010,    82,    -1,   689,   690,
     691,    -1,    87,    -1,  1047,    -1,   692,    -1,   693,    -1,
      10,    88,    -1,    11,    -1,    10,   694,    88,    -1,   695,
      -1,   694,   695,    -1,  1012,    -1,   697,   698,   699,    -1,
      89,    -1,  1047,    -1,   700,    -1,   701,    -1,    10,    90,
      -1,    11,    -1,    10,   702,    90,    -1,   703,    -1,   702,
     703,    -1,  1012,    -1,   705,   706,   707,    -1,    93,    -1,
    1047,    -1,   708,    -1,   709,    -1,    10,    94,    -1,    11,
      -1,    10,   710,    94,    -1,   711,    -1,   710,   711,    -1,
    1012,    -1,   713,   714,   715,    -1,    91,    -1,  1047,    -1,
     716,    -1,   717,    -1,    10,    92,    -1,    11,    -1,    10,
     718,    92,    -1,   719,    -1,   718,   719,    -1,  1012,    -1,
     721,   722,   723,    -1,    85,    -1,  1048,    -1,   724,    -1,
     725,    -1,    10,    86,    -1,    11,    -1,    10,  1010,    86,
      -1,   727,   728,   729,    -1,    83,    -1,  1048,    -1,   730,
      -1,   731,    -1,    10,    84,    -1,    11,    -1,    10,  1010,
      84,    -1,   733,   734,   735,    -1,    95,    -1,  1049,    -1,
     736,    -1,   737,    -1,    10,    96,    -1,    11,    -1,    10,
     738,    96,    -1,   739,    -1,   738,   739,    -1,    97,    10,
       4,    98,    -1,   741,   742,   743,    -1,   123,    -1,  1045,
      -1,   744,    -1,   745,    -1,    10,   124,    -1,    11,    -1,
      10,   746,   124,    -1,   747,    -1,   748,    -1,   747,   748,
      -1,   567,   568,   571,    -1,    -1,   750,   751,   754,    -1,
     322,    -1,   752,    -1,    -1,   752,   753,    -1,  1156,    -1,
    1149,    -1,  1154,    -1,   755,    -1,   756,    -1,    11,    -1,
      10,   757,   323,    -1,   758,   854,   921,   988,    -1,    -1,
     759,   760,   762,    -1,   312,    -1,   761,    -1,    -1,  1046,
      -1,   763,    -1,   764,    -1,    11,    -1,    10,   765,   313,
      -1,   766,   780,   794,   807,   821,   836,    -1,    -1,   767,
     768,   769,    -1,    99,    -1,  1155,    -1,   770,    -1,   771,
      -1,    10,   100,    -1,    11,    -1,    10,   772,   100,    -1,
     773,    -1,   774,    -1,   773,   774,    -1,   775,   776,   779,
      -1,   310,    -1,   777,    -1,    -1,   777,   778,    -1,  1158,
      -1,  1173,    -1,  1188,    -1,    10,   311,    -1,    11,    -1,
      -1,   781,   782,   783,    -1,   101,    -1,  1155,    -1,   784,
      -1,   785,    -1,    10,   102,    -1,    11,    -1,    10,   786,
     102,    -1,   787,    -1,   788,    -1,   787,   788,    -1,   789,
     790,   793,    -1,   310,    -1,   791,    -1,    -1,   791,   792,
      -1,  1158,    -1,  1173,    -1,  1188,    -1,    10,   311,    -1,
      11,    -1,    -1,   795,   796,    -1,   103,    -1,   797,    -1,
     798,    -1,    11,    -1,    10,   799,   104,    -1,   800,   801,
     802,   803,   804,   805,   806,    -1,    -1,  1105,    -1,    -1,
    1111,    -1,    -1,  1117,    -1,    -1,  1123,    -1,    -1,  1129,
      -1,    -1,  1135,    -1,    -1,  1141,    -1,    -1,   808,   809,
     810,    -1,   105,    -1,  1155,    -1,   811,    -1,   812,    -1,
      10,   106,    -1,    11,    -1,    10,   813,   106,    -1,   814,
      -1,   815,    -1,   814,   815,    -1,   816,   817,   820,    -1,
     310,    -1,   818,    -1,    -1,   818,   819,    -1,  1158,    -1,
    1173,    -1,  1188,    -1,    10,   311,    -1,    11,    -1,    -1,
     822,   823,   824,    -1,   107,    -1,    40,     8,     6,     8,
      -1,   825,    -1,   826,    -1,    10,   108,    -1,    11,    -1,
      10,   827,   108,    -1,   828,    -1,   827,   828,    -1,   829,
     830,   833,    -1,   109,    -1,   831,    -1,    -1,   831,   832,
      -1,  1031,    -1,  1155,    -1,  1021,    -1,   834,    -1,   835,
      -1,    10,   110,    -1,    11,    -1,    10,   814,   110,    -1,
      -1,   836,   837,    -1,   838,   839,   842,    -1,   346,    -1,
     840,    -1,    -1,   840,   841,    -1,  1155,    -1,  1151,    -1,
    1173,    -1,  1188,    -1,  1179,    -1,  1161,    -1,  1182,    -1,
    1191,    -1,  1170,    -1,  1167,    -1,   843,    -1,   844,    -1,
      10,   347,    -1,    11,    -1,    10,   845,   347,    -1,   846,
      -1,  1051,    -1,   847,    -1,   846,   847,    -1,   848,   849,
     852,    -1,   310,    -1,   850,    -1,    -1,   850,   851,    -1,
    1158,    -1,  1173,    -1,  1188,    -1,  1023,    -1,  1034,    -1,
     853,    -1,    10,   311,    -1,    11,    -1,    -1,   855,   856,
     858,    -1,   308,    -1,   857,    -1,    -1,  1044,    -1,   859,
      -1,   860,    -1,    11,    -1,    10,   861,   309,    -1,   862,
     876,   890,   903,    -1,    -1,   863,   864,   865,    -1,   111,
      -1,  1153,    -1,   866,    -1,   867,    -1,    10,   112,    -1,
      11,    -1,    10,   868,   112,    -1,   869,    -1,   870,    -1,
     869,   870,    -1,   871,   872,   875,    -1,   306,    -1,   873,
      -1,    -1,   873,   874,    -1,  1158,    -1,  1173,    -1,  1188,
      -1,    10,   307,    -1,    11,    -1,    -1,   877,   878,   879,
      -1,   113,    -1,  1153,    -1,   880,    -1,   881,    -1,    10,
     114,    -1,    11,    -1,    10,   882,   114,    -1,   883,    -1,
     884,    -1,   883,   884,    -1,   885,   886,   889,    -1,   306,
      -1,   887,    -1,    -1,   887,   888,    -1,  1158,    -1,  1173,
      -1,  1023,    -1,  1034,    -1,    10,   307,    -1,    11,    -1,
      -1,   891,   892,    -1,   103,    -1,   893,    -1,   894,    -1,
      11,    -1,    10,   895,   104,    -1,   896,   897,   898,   899,
     900,   901,   902,    -1,    -1,  1105,    -1,    -1,  1111,    -1,
      -1,  1117,    -1,    -1,  1123,    -1,    -1,  1129,    -1,    -1,
    1135,    -1,    -1,  1141,    -1,    -1,   903,   904,    -1,   905,
     906,   909,    -1,   346,    -1,   907,    -1,    -1,   907,   908,
      -1,  1153,    -1,  1151,    -1,  1173,    -1,  1188,    -1,  1179,
      -1,  1161,    -1,  1182,    -1,  1176,    -1,  1170,    -1,  1167,
      -1,   910,    -1,   911,    -1,    10,   347,    -1,    11,    -1,
      10,   912,   347,    -1,   913,    -1,  1051,    -1,   914,    -1,
     913,   914,    -1,   915,   916,   919,    -1,   306,    -1,   917,
      -1,    -1,   917,   918,    -1,  1158,    -1,  1173,    -1,  1188,
      -1,  1023,    -1,  1034,    -1,   920,    -1,    10,   307,    -1,
      11,    -1,    -1,   922,   923,   925,    -1,   304,    -1,   924,
      -1,    -1,  1043,    -1,   926,    -1,   927,    -1,    11,    -1,
      10,   928,   305,    -1,   929,   943,   957,   970,    -1,    -1,
     930,   931,   932,    -1,   115,    -1,  1148,    -1,   933,    -1,
     934,    -1,    10,   116,    -1,    11,    -1,    10,   935,   116,
      -1,   936,    -1,   937,    -1,   936,   937,    -1,   938,   939,
     942,    -1,   302,    -1,   940,    -1,    -1,   940,   941,    -1,
    1158,    -1,  1173,    -1,  1188,    -1,    10,   303,    -1,    11,
      -1,    -1,   944,   945,   946,    -1,   117,    -1,  1148,    -1,
     947,    -1,   948,    -1,    10,   118,    -1,    11,    -1,    10,
     949,   118,    -1,   950,    -1,   951,    -1,   950,   951,    -1,
     952,   953,   956,    -1,   302,    -1,   954,    -1,    -1,   954,
     955,    -1,  1158,    -1,  1173,    -1,  1027,    -1,  1038,    -1,
      10,   303,    -1,    11,    -1,    -1,   958,   959,    -1,   103,
      -1,   960,    -1,   961,    -1,    11,    -1,    10,   962,   104,
      -1,   963,   964,   965,   966,   967,   968,   969,    -1,    -1,
    1105,    -1,    -1,  1111,    -1,    -1,  1117,    -1,    -1,  1123,
      -1,    -1,  1129,    -1,    -1,  1135,    -1,    -1,  1141,    -1,
      -1,   970,   971,    -1,   972,   973,   976,    -1,   346,    -1,
     974,    -1,    -1,   974,   975,    -1,  1148,    -1,  1151,    -1,
    1173,    -1,  1188,    -1,  1179,    -1,  1161,    -1,  1182,    -1,
    1164,    -1,  1170,    -1,  1167,    -1,   977,    -1,   978,    -1,
      10,   347,    -1,    11,    -1,    10,   979,   347,    -1,   980,
      -1,  1051,    -1,   981,    -1,   980,   981,    -1,   982,   983,
     986,    -1,   302,    -1,   984,    -1,    -1,   984,   985,    -1,
    1158,    -1,  1173,    -1,  1188,    -1,  1023,    -1,  1034,    -1,
     987,    -1,    10,   303,    -1,    11,    -1,    -1,   989,   990,
     991,    -1,   119,    -1,  1050,    -1,   992,    -1,   993,    -1,
      11,    -1,    10,   994,   120,    -1,    -1,   994,   995,    -1,
     996,   997,  1000,    -1,   121,    -1,   998,    -1,   999,    -1,
     998,   999,    -1,  1173,    -1,  1188,    -1,  1179,    -1,  1161,
      -1,  1182,    -1,  1167,    -1,  1152,    -1,  1001,    -1,  1002,
      -1,    10,   122,    -1,    11,    -1,    10,  1003,   122,    -1,
    1004,    -1,  1005,    -1,  1004,  1005,    -1,  1006,    -1,  1007,
      -1,  1008,    -1,   160,    -1,   157,    -1,   158,  1009,   159,
      -1,     5,    -1,  1011,    -1,  1010,  1011,    -1,    71,    10,
       4,    72,    -1,  1013,  1014,  1020,    -1,    73,    -1,  1015,
      -1,    -1,  1015,  1016,    -1,  1017,    -1,  1018,    -1,  1019,
      -1,    28,     3,     8,    -1,    29,     3,     8,    -1,    30,
       3,     8,    -1,    10,    74,    -1,    11,    -1,  1022,    -1,
      42,     8,  1061,     8,    -1,  1024,    -1,  1025,    -1,  1026,
      -1,    16,    -1,    18,     3,  1062,    -1,  1028,    -1,  1029,
      -1,  1030,    -1,    20,    -1,    22,  1062,  1061,  1062,    -1,
    1032,    -1,  1033,    -1,    41,  1062,     6,  1062,    -1,  1035,
      -1,  1036,    -1,  1037,    -1,    17,    -1,    19,     3,  1062,
      -1,  1039,    -1,  1040,    -1,  1041,    -1,    21,    -1,    23,
    1062,  1061,  1062,    -1,    31,     8,     6,     8,    -1,    37,
    1062,     6,  1062,    -1,    36,  1062,     6,  1062,    -1,    39,
    1062,     6,  1062,    -1,    35,  1062,     6,  1062,    -1,    33,
       8,     6,     8,    -1,    32,     8,     6,     8,    -1,    34,
       8,     6,     8,    -1,    38,  1062,     6,  1062,    -1,  1052,
      -1,  1051,  1052,    -1,  1053,  1054,  1057,    -1,   155,    -1,
    1055,    -1,    -1,  1055,  1056,    -1,  1150,    -1,  1188,    -1,
    1167,    -1,  1058,    -1,  1059,    -1,    11,    -1,    10,  1060,
     156,    -1,  1093,    -1,     6,    -1,     7,    -1,  1063,     8,
      -1,    -1,  1063,  1064,    -1,   470,    -1,   471,    -1,   472,
      -1,   473,    -1,  1066,  1067,    -1,   125,    -1,  1068,    -1,
    1069,    -1,    11,    -1,    10,  1070,   126,    -1,  1071,    -1,
      -1,  1071,  1072,    -1,  1073,    -1,  1077,    -1,  1081,    -1,
    1085,    -1,  1089,    -1,  1074,    -1,  1075,    -1,  1076,    -1,
     130,    -1,   129,    -1,   127,     5,   128,    -1,  1078,    -1,
    1079,    -1,  1080,    -1,   134,    -1,   133,    -1,   131,     5,
     132,    -1,  1082,    -1,  1083,    -1,  1084,    -1,   138,    -1,
     137,    -1,   135,     5,   136,    -1,  1086,    -1,  1087,    -1,
    1088,    -1,   142,    -1,   141,    -1,   139,     5,   140,    -1,
    1090,    -1,  1091,    -1,  1092,    -1,   146,    -1,   145,    -1,
     143,     5,   144,    -1,  1094,    -1,  1101,    -1,    -1,  1094,
    1095,    -1,  1096,  1097,  1100,    -1,   153,    -1,  1098,    -1,
      -1,  1098,  1099,    -1,  1160,    -1,  1159,    -1,    10,     6,
     154,    -1,   161,  1157,  1102,    -1,  1103,    -1,  1104,    -1,
      10,   162,    -1,    11,    -1,    10,     4,   162,    -1,  1106,
    1147,  1107,    -1,   330,    -1,  1108,    -1,  1109,    -1,    11,
      -1,    10,  1110,   331,    -1,  1093,    -1,  1112,  1147,  1113,
      -1,   326,    -1,  1114,    -1,  1115,    -1,    11,    -1,    10,
    1116,   327,    -1,  1093,    -1,  1118,  1147,  1119,    -1,   328,
      -1,  1120,    -1,  1121,    -1,    11,    -1,    10,  1122,   329,
      -1,  1093,    -1,  1124,  1147,  1125,    -1,   324,    -1,  1126,
      -1,  1127,    -1,    11,    -1,    10,  1128,   325,    -1,  1093,
      -1,  1130,  1147,  1131,    -1,   332,    -1,  1132,    -1,  1133,
      -1,    11,    -1,    10,  1134,   333,    -1,  1093,    -1,  1136,
    1147,  1137,    -1,   334,    -1,  1138,    -1,  1139,    -1,    11,
      -1,    10,  1140,   335,    -1,  1093,    -1,  1142,  1147,  1143,
      -1,   336,    -1,  1144,    -1,  1145,    -1,    11,    -1,    10,
    1146,   337,    -1,  1093,    -1,  1150,    -1,   212,     8,     6,
       8,    -1,   211,     8,     6,     8,    -1,   163,     8,     6,
       8,    -1,   164,     8,     6,     8,    -1,   165,     8,     6,
       8,    -1,   215,     8,     6,     8,    -1,   214,     8,     6,
       8,    -1,   218,     8,     6,     8,    -1,   217,     8,     6,
       8,    -1,   241,     8,     6,     8,    -1,   238,     8,     6,
       8,    -1,   239,     8,     6,     8,    -1,   240,     8,     6,
       8,    -1,  1162,    -1,  1163,    -1,   166,    -1,   167,     3,
       8,    -1,  1165,    -1,  1166,    -1,   186,    -1,   187,     3,
       8,    -1,  1168,    -1,  1169,    -1,   168,    -1,   169,     3,
       8,    -1,  1171,    -1,  1172,    -1,   176,    -1,   177,     3,
       8,    -1,  1174,    -1,  1175,    -1,   172,    -1,   173,     3,
       8,    -1,  1177,    -1,  1178,    -1,   188,    -1,   189,     3,
       8,    -1,  1180,    -1,  1181,    -1,   170,    -1,   171,     3,
       8,    -1,  1183,    -1,  1184,    -1,   174,    -1,   175,     3,
       8,    -1,  1186,    -1,  1187,    -1,   180,    -1,   181,     3,
       8,    -1,  1189,    -1,  1190,    -1,   182,    -1,   183,     3,
       8,    -1,  1192,    -1,  1193,    -1,   190,    -1,   191,     3,
       8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   348,   348,   349,   351,   358,   368,   368,   370,   370,
     372,   374,   376,   385,   386,   389,   397,   397,   410,   410,
     412,   428,   428,   430,   430,   432,   434,   436,   436,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     453,   455,   464,   464,   466,   466,   468,   470,   480,   482,
     489,   489,   491,   491,   493,   495,   505,   507,   513,   513,
     515,   515,   517,   519,   529,   536,   544,   545,   552,   558,
     558,   560,   560,   562,   564,   572,   574,   580,   580,   582,
     582,   584,   586,   595,   597,   604,   604,   606,   606,   608,
     610,   620,   622,   629,   629,   631,   631,   633,   635,   645,
     647,   653,   653,   655,   655,   657,   659,   669,   671,   677,
     677,   679,   679,   681,   683,   693,   700,   709,   710,   716,
     723,   723,   725,   725,   727,   729,   737,   743,   753,   761,
     766,   772,   772,   774,   776,   780,   780,   782,   793,   812,
     818,   818,   821,   825,   826,   829,   829,   877,   877,   879,
     889,   889,   891,   891,   893,   895,   897,   897,   900,   901,
     902,   903,   904,   908,   910,   920,   922,   922,   925,   926,
     929,   931,   939,   941,   951,   953,   953,   956,   957,   960,
     962,   971,   973,   983,   985,   985,   988,   989,   992,   994,
    1003,  1005,  1015,  1016,  1018,  1020,  1031,  1037,  1047,  1055,
    1059,  1064,  1064,  1066,  1068,  1072,  1072,  1074,  1129,  1129,
    1131,  1138,  1138,  1140,  1140,  1142,  1144,  1146,  1146,  1149,
    1150,  1154,  1156,  1162,  1162,  1164,  1164,  1166,  1168,  1179,
    1185,  1195,  1203,  1207,  1212,  1212,  1214,  1216,  1220,  1220,
    1222,  1275,  1275,  1277,  1297,  1297,  1299,  1299,  1301,  1303,
    1305,  1305,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,
    1316,  1317,  1318,  1319,  1320,  1321,  1322,  1327,  1333,  1343,
    1344,  1346,  1346,  1348,  1348,  1350,  1352,  1354,  1361,  1363,
    1369,  1369,  1371,  1371,  1373,  1375,  1385,  1396,  1406,  1408,
    1408,  1410,  1410,  1412,  1421,  1421,  1423,  1444,  1455,  1465,
    1465,  1467,  1467,  1469,  1480,  1491,  1501,  1501,  1503,  1503,
    1505,  1516,  1527,  1537,  1537,  1539,  1539,  1541,  1552,  1563,
    1573,  1573,  1575,  1575,  1577,  1588,  1604,  1614,  1616,  1616,
    1618,  1618,  1620,  1629,  1629,  1631,  1635,  1651,  1661,  1663,
    1663,  1665,  1665,  1667,  1676,  1676,  1678,  1682,  1698,  1708,
    1710,  1710,  1712,  1712,  1714,  1723,  1723,  1725,  1729,  1745,
    1755,  1757,  1757,  1759,  1759,  1761,  1770,  1770,  1772,  1776,
    1787,  1797,  1799,  1799,  1801,  1801,  1803,  1814,  1825,  1835,
    1837,  1837,  1839,  1839,  1841,  1867,  1878,  1888,  1890,  1890,
    1892,  1892,  1894,  1903,  1903,  1905,  1926,  1932,  1942,  1950,
    1954,  1959,  1959,  1961,  1963,  1967,  1967,  1969,  2023,  2023,
    2025,  2033,  2035,  2035,  2038,  2045,  2052,  2061,  2061,  2063,
    2065,  2067,  2074,  2074,  2076,  2082,  2089,  2089,  2094,  2094,
    2096,  2098,  2100,  2110,  2110,  2125,  2130,  2141,  2149,  2158,
    2158,  2160,  2162,  2164,  2164,  2167,  2172,  2186,  2192,  2192,
    2195,  2209,  2214,  2222,  2222,  2226,  2226,  2241,  2246,  2257,
    2265,  2274,  2274,  2276,  2278,  2280,  2280,  2283,  2289,  2304,
    2310,  2310,  2313,  2325,  2330,  2336,  2336,  2340,  2340,  2342,
    2347,  2347,  2349,  2351,  2353,  2356,  2356,  2394,  2394,  2430,
    2430,  2465,  2465,  2500,  2500,  2535,  2535,  2570,  2570,  2605,
    2605,  2621,  2626,  2637,  2645,  2654,  2654,  2656,  2658,  2664,
    2664,  2666,  2671,  2687,  2693,  2693,  2696,  2708,  2713,  2721,
    2721,  2725,  2725,  2731,  2737,  2745,  2753,  2761,  2761,  2763,
    2765,  2765,  2767,  2786,  2802,  2810,  2810,  2813,  2814,  2823,
    2826,  2826,  2828,  2828,  2830,  2835,  2835,  2837,  2842,  2874,
    2894,  2894,  2897,  2901,  2905,  2906,  2907,  2908,  2909,  2910,
    2911,  2912,  2915,  2915,  2917,  2917,  2919,  2921,  2921,  2923,
    2923,  2926,  2941,  2961,  2963,  2963,  2966,  2976,  2977,  2978,
    2979,  2982,  2984,  2984,  2992,  2992,  2994,  3000,  3007,  3007,
    3012,  3012,  3014,  3016,  3018,  3027,  3027,  3043,  3049,  3061,
    3069,  3078,  3078,  3080,  3082,  3084,  3084,  3087,  3092,  3107,
    3109,  3109,  3112,  3123,  3127,  3134,  3134,  3137,  3137,  3155,
    3160,  3174,  3182,  3191,  3191,  3193,  3195,  3197,  3197,  3200,
    3205,  3223,  3225,  3225,  3228,  3239,  3243,  3249,  3256,  3256,
    3260,  3260,  3262,  3267,  3267,  3269,  3271,  3273,  3276,  3276,
    3310,  3310,  3344,  3344,  3378,  3378,  3412,  3412,  3446,  3446,
    3482,  3482,  3517,  3517,  3519,  3525,  3556,  3577,  3577,  3580,
    3584,  3588,  3589,  3590,  3591,  3592,  3593,  3594,  3595,  3598,
    3598,  3600,  3600,  3602,  3604,  3604,  3606,  3606,  3609,  3624,
    3646,  3648,  3648,  3651,  3661,  3662,  3663,  3664,  3667,  3669,
    3669,  3677,  3677,  3679,  3685,  3692,  3692,  3697,  3697,  3699,
    3701,  3703,  3712,  3712,  3728,  3733,  3744,  3752,  3761,  3761,
    3763,  3765,  3767,  3767,  3770,  3775,  3791,  3798,  3798,  3801,
    3812,  3816,  3823,  3823,  3827,  3827,  3845,  3850,  3863,  3871,
    3880,  3880,  3882,  3884,  3886,  3886,  3889,  3894,  3913,  3920,
    3920,  3923,  3934,  3938,  3942,  3948,  3948,  3952,  3952,  3954,
    3959,  3959,  3961,  3963,  3965,  3968,  3968,  4002,  4002,  4037,
    4037,  4073,  4073,  4108,  4108,  4143,  4143,  4178,  4178,  4213,
    4213,  4215,  4221,  4252,  4272,  4272,  4275,  4279,  4283,  4284,
    4285,  4286,  4287,  4288,  4289,  4290,  4293,  4293,  4295,  4295,
    4297,  4299,  4299,  4301,  4301,  4304,  4319,  4339,  4341,  4341,
    4344,  4356,  4357,  4358,  4359,  4362,  4364,  4364,  4372,  4372,
    4378,  4380,  4388,  4396,  4405,  4407,  4409,  4409,  4413,  4433,
    4451,  4457,  4457,  4460,  4461,  4462,  4463,  4464,  4465,  4466,
    4473,  4481,  4490,  4490,  4492,  4494,  4496,  4496,  4498,  4505,
    4516,  4518,  4518,  4520,  4522,  4539,  4539,  4541,  4563,  4580,
    4592,  4597,  4597,  4600,  4601,  4602,  4604,  4613,  4622,  4631,
    4631,  4715,  4722,  4744,  4751,  4751,  4753,  4758,  4765,  4771,
    4771,  4773,  4778,  4842,  4848,  4850,  4876,  4883,  4883,  4885,
    4890,  4897,  4903,  4903,  4905,  4908,  5020,  5048,  5054,  5060,
    5066,  5072,  5086,  5096,  5107,  5143,  5143,  5145,  5164,  5181,
    5189,  5189,  5192,  5200,  5201,  5205,  5205,  5207,  5210,  5212,
    5216,  5217,  5224,  5226,  5226,  5228,  5229,  5230,  5231,  5266,
    5268,  5282,  5282,  5284,  5286,  5288,  5290,  5290,  5293,  5294,
    5295,  5296,  5297,  5299,  5307,  5307,  5309,  5309,  5311,  5317,
    5325,  5325,  5327,  5327,  5329,  5335,  5343,  5343,  5345,  5345,
    5347,  5353,  5361,  5361,  5363,  5363,  5365,  5371,  5379,  5379,
    5381,  5381,  5383,  5395,  5403,  5405,  5405,  5407,  5409,  5418,
    5420,  5420,  5422,  5422,  5424,  5440,  5443,  5443,  5445,  5445,
    5448,  5723,  5725,  5730,  5730,  5732,  5734,  5736,  5739,  5741,
    5746,  5746,  5748,  5750,  5752,  5755,  5757,  5762,  5762,  5764,
    5766,  5768,  5771,  5773,  5778,  5778,  5780,  5782,  5784,  5787,
    5789,  5794,  5794,  5796,  5798,  5800,  5803,  5805,  5810,  5810,
    5812,  5814,  5816,  5819,  5821,  5826,  5826,  5828,  5830,  5832,
    5835,  7395,  7417,  7428,  7439,  7450,  7518,  7540,  7573,  7595,
    7609,  7728,  7738,  7775,  7899,  7899,  7901,  7908,  7917,  7917,
    7919,  7926,  7935,  7935,  7937,  7944,  7953,  7953,  7955,  7962,
    8045,  8045,  8047,  8054,  8063,  8063,  8065,  8072,  8124,  8124,
    8126,  8133,  8160,  8160,  8162,  8169,  8178,  8178,  8180,  8187,
    8196,  8196,  8200,  8208,  8235,  8235,  8237,  8244
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "GREATERTHAN",
  "ENDOFELEMENT", "OSOLSTART", "OSOLSTARTEMPTY", "OSOLATTRIBUTETEXT",
  "OSOLEND", "EMPTYLBVALUEATT", "EMPTYUBVALUEATT", "LBVALUEATT",
  "UBVALUEATT", "EMPTYLBDUALVALUEATT", "EMPTYUBDUALVALUEATT",
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
  "EMPTYIDATT", "IDATT", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
  "osoldoc", "osolStartEmpty", "osolStart", "osolAttributes",
  "osolContent", "osolEmpty", "osolLaden", "osolEnd", "osolEnding",
  "osolBody", "headerElement", "generalElement", "generalElementStart",
  "generalElementContent", "generalElementEmpty", "generalElementLaden",
  "generalElementBody", "generalElementList", "generalChild", "serviceURI",
  "serviceURIStart", "serviceURIContent", "serviceURIEmpty",
  "serviceURILaden", "serviceURIBody", "serviceName", "serviceNameStart",
  "serviceNameContent", "serviceNameEmpty", "serviceNameLaden",
  "serviceNameBody", "instanceName", "instanceNameStart",
  "instanceNameContent", "instanceNameEmpty", "instanceNameLaden",
  "instanceNameBody", "instanceLocation", "instanceLocationStart",
  "instanceLocationAttributes", "locationTypeAttribute",
  "instanceLocationContent", "instanceLocationEmpty",
  "instanceLocationLaden", "instanceLocationBody", "jobID", "jobIDStart",
  "jobIDContent", "jobIDEmpty", "jobIDLaden", "jobIDBody",
  "solverToInvoke", "solverToInvokeStart", "solverToInvokeContent",
  "solverToInvokeEmpty", "solverToInvokeLaden", "solverToInvokeBody",
  "license", "licenseStart", "licenseContent", "licenseEmpty",
  "licenseLaden", "licensebody", "username", "usernameStart",
  "usernameContent", "usernameEmpty", "usernameLaden", "usernamebody",
  "password", "passwordStart", "passwordContent", "passwordEmpty",
  "passwordLaden", "passwordbody", "contact", "contactStart",
  "contactAttributes", "transportTypeAttribute", "contactContent",
  "contactContentEmpty", "contactContentLaden", "contactBody",
  "otherGeneralOptions", "otherGeneralOptionsStart",
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
      32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   474,   475,   475,   476,   477,   478,   478,   479,   479,
     480,   481,   482,   483,   483,   484,   485,   485,   486,   486,
     487,   488,   488,   489,   489,   490,   491,   492,   492,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     494,   495,   496,   496,   497,   497,   498,   499,   500,   501,
     502,   502,   503,   503,   504,   505,   506,   507,   508,   508,
     509,   509,   510,   511,   512,   513,   514,   514,   515,   516,
     516,   517,   517,   518,   519,   520,   521,   522,   522,   523,
     523,   524,   525,   526,   527,   528,   528,   529,   529,   530,
     531,   532,   533,   534,   534,   535,   535,   536,   537,   538,
     539,   540,   540,   541,   541,   542,   543,   544,   545,   546,
     546,   547,   547,   548,   549,   550,   551,   552,   552,   553,
     554,   554,   555,   555,   556,   557,   558,   559,   560,   561,
     561,   562,   562,   563,   564,   565,   565,   566,   567,   568,
     569,   569,   570,   570,   570,   571,   571,   572,   572,   573,
     574,   574,   575,   575,   576,   577,   578,   578,   579,   579,
     579,   579,   579,   580,   581,   582,   583,   583,   584,   584,
     585,   586,   587,   588,   589,   590,   590,   591,   591,   592,
     593,   594,   595,   596,   597,   597,   598,   598,   599,   600,
     601,   602,   603,   603,   604,   605,   606,   607,   608,   609,
     609,   610,   610,   611,   612,   613,   613,   614,   615,   615,
     616,   617,   617,   618,   618,   619,   620,   621,   621,   622,
     622,   623,   624,   625,   625,   626,   626,   627,   628,   629,
     630,   631,   632,   632,   633,   633,   634,   635,   636,   636,
     637,   638,   638,   639,   640,   640,   641,   641,   642,   643,
     644,   644,   645,   645,   645,   645,   645,   645,   645,   645,
     645,   645,   645,   645,   645,   645,   645,   646,   647,   648,
     648,   649,   649,   650,   650,   651,   652,   653,   654,   655,
     656,   656,   657,   657,   658,   659,   660,   661,   662,   663,
     663,   664,   664,   665,   666,   666,   667,   668,   669,   670,
     670,   671,   671,   672,   673,   674,   675,   675,   676,   676,
     677,   678,   679,   680,   680,   681,   681,   682,   683,   684,
     685,   685,   686,   686,   687,   688,   689,   690,   691,   691,
     692,   692,   693,   694,   694,   695,   696,   697,   698,   699,
     699,   700,   700,   701,   702,   702,   703,   704,   705,   706,
     707,   707,   708,   708,   709,   710,   710,   711,   712,   713,
     714,   715,   715,   716,   716,   717,   718,   718,   719,   720,
     721,   722,   723,   723,   724,   724,   725,   726,   727,   728,
     729,   729,   730,   730,   731,   732,   733,   734,   735,   735,
     736,   736,   737,   738,   738,   739,   740,   741,   742,   743,
     743,   744,   744,   745,   746,   747,   747,   748,   749,   749,
     750,   751,   752,   752,   753,   753,   753,   754,   754,   755,
     756,   757,   758,   758,   759,   760,   761,   761,   762,   762,
     763,   764,   765,   766,   766,   767,   768,   769,   769,   770,
     770,   771,   772,   773,   773,   774,   775,   776,   777,   777,
     778,   778,   778,   779,   779,   780,   780,   781,   782,   783,
     783,   784,   784,   785,   786,   787,   787,   788,   789,   790,
     791,   791,   792,   792,   792,   793,   793,   794,   794,   795,
     796,   796,   797,   798,   799,   800,   800,   801,   801,   802,
     802,   803,   803,   804,   804,   805,   805,   806,   806,   807,
     807,   808,   809,   810,   810,   811,   811,   812,   813,   814,
     814,   815,   816,   817,   818,   818,   819,   819,   819,   820,
     820,   821,   821,   822,   823,   824,   824,   825,   825,   826,
     827,   827,   828,   829,   830,   831,   831,   832,   832,   832,
     833,   833,   834,   834,   835,   836,   836,   837,   838,   839,
     840,   840,   841,   841,   841,   841,   841,   841,   841,   841,
     841,   841,   842,   842,   843,   843,   844,   845,   845,   846,
     846,   847,   848,   849,   850,   850,   851,   851,   851,   851,
     851,   852,   853,   853,   854,   854,   855,   856,   857,   857,
     858,   858,   859,   860,   861,   862,   862,   863,   864,   865,
     865,   866,   866,   867,   868,   869,   869,   870,   871,   872,
     873,   873,   874,   874,   874,   875,   875,   876,   876,   877,
     878,   879,   879,   880,   880,   881,   882,   883,   883,   884,
     885,   886,   887,   887,   888,   888,   888,   888,   889,   889,
     890,   890,   891,   892,   892,   893,   894,   895,   896,   896,
     897,   897,   898,   898,   899,   899,   900,   900,   901,   901,
     902,   902,   903,   903,   904,   905,   906,   907,   907,   908,
     908,   908,   908,   908,   908,   908,   908,   908,   908,   909,
     909,   910,   910,   911,   912,   912,   913,   913,   914,   915,
     916,   917,   917,   918,   918,   918,   918,   918,   919,   920,
     920,   921,   921,   922,   923,   924,   924,   925,   925,   926,
     927,   928,   929,   929,   930,   931,   932,   932,   933,   933,
     934,   935,   936,   936,   937,   938,   939,   940,   940,   941,
     941,   941,   942,   942,   943,   943,   944,   945,   946,   946,
     947,   947,   948,   949,   950,   950,   951,   952,   953,   954,
     954,   955,   955,   955,   955,   956,   956,   957,   957,   958,
     959,   959,   960,   961,   962,   963,   963,   964,   964,   965,
     965,   966,   966,   967,   967,   968,   968,   969,   969,   970,
     970,   971,   972,   973,   974,   974,   975,   975,   975,   975,
     975,   975,   975,   975,   975,   975,   976,   976,   977,   977,
     978,   979,   979,   980,   980,   981,   982,   983,   984,   984,
     985,   985,   985,   985,   985,   986,   987,   987,   988,   988,
     989,   990,   991,   991,   992,   993,   994,   994,   995,   996,
     997,   998,   998,   999,   999,   999,   999,   999,   999,   999,
    1000,  1000,  1001,  1001,  1002,  1003,  1004,  1004,  1005,  1006,
    1006,  1007,  1007,  1008,  1009,  1010,  1010,  1011,  1012,  1013,
    1014,  1015,  1015,  1016,  1016,  1016,  1017,  1018,  1019,  1020,
    1020,  1021,  1022,  1023,  1024,  1024,  1025,  1026,  1027,  1028,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1035,  1036,
    1037,  1038,  1039,  1039,  1040,  1041,  1042,  1043,  1044,  1045,
    1046,  1047,  1048,  1049,  1050,  1051,  1051,  1052,  1053,  1054,
    1055,  1055,  1056,  1056,  1056,  1057,  1057,  1058,  1059,  1060,
    1061,  1061,  1062,  1063,  1063,  1064,  1064,  1064,  1064,  1065,
    1066,  1067,  1067,  1068,  1069,  1070,  1071,  1071,  1072,  1072,
    1072,  1072,  1072,  1073,  1074,  1074,  1075,  1075,  1076,  1077,
    1078,  1078,  1079,  1079,  1080,  1081,  1082,  1082,  1083,  1083,
    1084,  1085,  1086,  1086,  1087,  1087,  1088,  1089,  1090,  1090,
    1091,  1091,  1092,  1093,  1093,  1094,  1094,  1095,  1096,  1097,
    1098,  1098,  1099,  1099,  1100,  1101,  1102,  1102,  1103,  1103,
    1104,  1105,  1106,  1107,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1113,  1114,  1115,  1116,  1117,  1118,  1119,  1119,  1120,
    1121,  1122,  1123,  1124,  1125,  1125,  1126,  1127,  1128,  1129,
    1130,  1131,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1137,
    1138,  1139,  1140,  1141,  1142,  1143,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1160,  1161,  1161,  1162,  1163,  1164,  1164,
    1165,  1166,  1167,  1167,  1168,  1169,  1170,  1170,  1171,  1172,
    1173,  1173,  1174,  1175,  1176,  1176,  1177,  1178,  1179,  1179,
    1180,  1181,  1182,  1182,  1183,  1184,  1185,  1185,  1186,  1187,
    1188,  1188,  1189,  1190,  1191,  1191,  1192,  1193
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
#define YYPACT_NINF -1236
static const yytype_int16 yypact[] =
{
     293, -1236, -1236,   147,    91,   197, -1236, -1236,   230,   -63,
   -1236,   141, -1236,   320, -1236, -1236, -1236, -1236,   -57,   384,
   -1236, -1236, -1236, -1236, -1236,    91, -1236, -1236, -1236, -1236,
   -1236,   -65,   404,   -28, -1236, -1236, -1236, -1236,   135,   425,
     230, -1236,   -18,   416,   -21, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,    11,   -23, -1236, -1236,   421, -1236,   423, -1236,   426,
   -1236,   253, -1236,   430, -1236,   432, -1236,   435, -1236,   437,
   -1236,   439, -1236,   302, -1236,   285, -1236,   331, -1236, -1236,
     335, -1236, -1236,   339, -1236, -1236,   343, -1236, -1236,   348,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,    34,   464,   -31, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,    45,    55,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   308, -1236,
     285, -1236, -1236,    10, -1236, -1236, -1236, -1236,     9, -1236,
   -1236, -1236, -1236,     8, -1236, -1236, -1236, -1236,   366,   470,
   -1236,     7, -1236, -1236, -1236, -1236,   129, -1236, -1236, -1236,
   -1236,   154, -1236, -1236, -1236, -1236,   140, -1236, -1236, -1236,
   -1236,   145, -1236, -1236, -1236, -1236,   373,   472, -1236, -1236,
     474, -1236,   252,   250,   248,   257,   244, -1236, -1236, -1236,
     -30, -1236, -1236, -1236, -1236, -1236, -1236, -1236,    71,    76,
   -1236, -1236,   479, -1236,   285, -1236, -1236,   382,   178,   389,
     178,   402,   178, -1236,   419,   418, -1236, -1236, -1236,   481,
   -1236, -1236, -1236,    96, -1236, -1236,    97, -1236, -1236,   108,
     445,   132, -1236, -1236, -1236, -1236, -1236, -1236,   110, -1236,
   -1236,   440, -1236, -1236,   456, -1236, -1236,   460, -1236, -1236,
     454,   533,   123, -1236, -1236, -1236, -1236,   544,    -2,   -82,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   483,
     143, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   232,   298, -1236,
   -1236,   315, -1236,   487, -1236,   530, -1236,   537, -1236,   537,
   -1236,   537, -1236,   537, -1236,   532, -1236,   532, -1236,   532,
   -1236,   532, -1236,   537, -1236,   537, -1236,   664, -1236,   285,
   -1236, -1236,   125, -1236, -1236, -1236, -1236,   489, -1236,   495,
   -1236, -1236,   612, -1236, -1236, -1236, -1236, -1236,   495, -1236,
   -1236, -1236, -1236,   495, -1236, -1236, -1236, -1236,   689,   693,
   -1236,   -81, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236,   656, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   648, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   579,   355, -1236, -1236,   392, -1236, -1236, -1236, -1236,
     697,   698,   699, -1236, -1236, -1236, -1236, -1236, -1236,   513,
   -1236,   114, -1236, -1236, -1236, -1236,   700,   515, -1236,   701,
     519,   523,   525,   527,   702,   529, -1236,   536, -1236,   538,
   -1236,   573, -1236,   575, -1236,   577, -1236,   703,   581, -1236,
     583, -1236, -1236, -1236,   650,   -80, -1236, -1236, -1236, -1236,
   -1236, -1236,   660, -1236,   704,   655, -1236,   658, -1236, -1236,
   -1236,   661, -1236, -1236,   591,   355, -1236, -1236, -1236, -1236,
   -1236, -1236,   585,   103, -1236,   394,   411,   686,   714,   716,
     718,   113, -1236, -1236, -1236, -1236, -1236, -1236,   662,   719,
     -52, -1236, -1236, -1236, -1236,   720,    79, -1236, -1236, -1236,
   -1236,   142, -1236, -1236, -1236, -1236,    74, -1236, -1236, -1236,
   -1236,   213, -1236, -1236, -1236, -1236,   721,   139, -1236, -1236,
   -1236, -1236,    80, -1236, -1236, -1236, -1236,    67, -1236, -1236,
   -1236, -1236,    68, -1236, -1236, -1236, -1236,   151, -1236, -1236,
   -1236, -1236,    72, -1236, -1236, -1236, -1236,   722,   501, -1236,
   -1236, -1236, -1236,   -78, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   605,   355, -1236, -1236, -1236, -1236, -1236, -1236,   585,
   -1236, -1236,   385, -1236, -1236, -1236,   728, -1236,   730, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   431,
     705, -1236,   589, -1236, -1236,   726,   729,   731, -1236,   670,
   -1236, -1236, -1236,   732, -1236,   733,   -43, -1236,   734,   735,
   -1236,   207, -1236, -1236,   240, -1236,   228, -1236,   238,   736,
   -1236, -1236,   167, -1236, -1236, -1236, -1236,    84, -1236, -1236,
   -1236,    75, -1236, -1236, -1236,    73, -1236, -1236, -1236,   208,
   -1236,   206,   738, -1236,   737,   505, -1236, -1236, -1236,   614,
     355, -1236,   585, -1236, -1236, -1236, -1236,   740,   741, -1236,
     632,   713, -1236,   593, -1236, -1236,   746,   654, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   750, -1236, -1236,
   -1236,   751, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
     595,   390, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   752, -1236, -1236,   585, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236,   723, -1236,   597, -1236, -1236,   753,   646, -1236,
   -1236, -1236, -1236, -1236, -1236,   447,   666,   540,   417,   691,
     690, -1236, -1236,   762,   763,   765, -1236, -1236, -1236, -1236,
     671, -1236, -1236,   601, -1236,   764,   668, -1236, -1236, -1236,
   -1236, -1236, -1236,   462,   672,   558, -1236, -1236, -1236,   674,
     540,   766,   603, -1236, -1236, -1236, -1236,   767,   768,   770,
   -1236,   773, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   467,
     676,   568, -1236, -1236, -1236,   678,   558,   774,   607, -1236,
   -1236,   682,   609,   611, -1236,   778,   -50, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,   503, -1236, -1236, -1236,   687,
     568,   780,   615, -1236, -1236, -1236,   617,   619, -1236,   783,
     -33, -1236, -1236, -1236, -1236, -1236,   684,   540,   465, -1236,
   -1236, -1236, -1236,   -54, -1236, -1236, -1236, -1236,   784, -1236,
   -1236,   694,   476, -1236, -1236, -1236, -1236, -1236, -1236,   407,
   -1236, -1236,   621,   623, -1236,   790,   -35, -1236, -1236, -1236,
   -1236,   451,   465, -1236, -1236, -1236, -1236,   -24, -1236, -1236,
   -1236, -1236,   791, -1236, -1236,   688,   492, -1236, -1236, -1236,
   -1236,   761,   625, -1236, -1236,   706,   477, -1236,   642, -1236,
   -1236,   707,   494, -1236, -1236, -1236, -1236, -1236,   627,   -51,
     794, -1236,   803, -1236,   804, -1236,   805,   629,   407, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236,   466,   465, -1236, -1236, -1236, -1236,   -44,
   -1236, -1236, -1236, -1236,   806, -1236, -1236,   695,   511, -1236,
   -1236, -1236, -1236, -1236,   711,   477, -1236, -1236, -1236,   709,
     510, -1236, -1236, -1236, -1236, -1236,   631,   -51,   471,   810,
     633,   -40, -1236, -1236, -1236, -1236, -1236, -1236,   491, -1236,
     642,   812,   635, -1236, -1236, -1236,   637,   -51,   514, -1236,
   -1236,   816, -1236, -1236, -1236, -1236,   820,   819,   821,   822,
      86, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   724,
     477, -1236, -1236, -1236,   717,   534, -1236, -1236, -1236, -1236,
   -1236,   639,   -51,   641,   290, -1236,   491, -1236, -1236, -1236,
     643,    51,   524, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236,   826,   547, -1236, -1236, -1236, -1236, -1236, -1236,
     739,   528, -1236, -1236, -1236,   516, -1236,   642,   647,   833,
     680, -1236, -1236, -1236, -1236,   531, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236,   837,   836, -1236, -1236, -1236, -1236, -1236,
     841, -1236,   725,   214, -1236, -1236, -1236, -1236,   649,   345,
   -1236,   491, -1236, -1236, -1236,   651,    66,   545, -1236, -1236,
   -1236, -1236, -1236, -1236,   -99, -1236, -1236, -1236, -1236,   842,
   -1236,   846, -1236,   850, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   516,
   -1236,   548, -1236, -1236, -1236, -1236,   851,   853, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
     653,   234,   849, -1236, -1236,   557, -1236, -1236, -1236, -1236,
     657,   -51, -1236,   526, -1236,   642,   659,   680, -1236, -1236,
   -1236, -1236,   852,   618, -1236,   708, -1236,   535, -1236,   854,
   -1236, -1236,   710, -1236, -1236,   -97, -1236, -1236, -1236, -1236,
   -1236,   860, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,   516, -1236,   561, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   518,
     562, -1236, -1236,   712, -1236, -1236,   864,   863,   865,   526,
   -1236, -1236, -1236, -1236,   -84, -1236, -1236, -1236, -1236, -1236,
     869, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   663,    56,   563,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   541, -1236,   642,
     665,   680, -1236, -1236, -1236, -1236, -1236,   550, -1236,   870,
     667, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   539,
     578, -1236, -1236,   712,   871,   526, -1236, -1236,   495,   495,
   -1236, -1236,   669,    59, -1236,   673,    46,   873, -1236, -1236,
     541, -1236, -1236, -1236, -1236, -1236,   542,   572, -1236, -1236,
     712,   875,   -58, -1236, -1236, -1236, -1236, -1236,   876, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   549, -1236,
     642,   675,   680, -1236, -1236, -1236, -1236, -1236,   559, -1236,
     881,    95, -1236, -1236, -1236, -1236,   880,   448, -1236, -1236,
     679,    59, -1236,   541, -1236, -1236, -1236,   586, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   680, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   549, -1236, -1236,
   -1236,   681,    59, -1236, -1236,   -56,   888,   495, -1236, -1236,
   -1236,   642,   683,   680, -1236, -1236, -1236, -1236, -1236,   570,
   -1236,   889,   742, -1236,   890, -1236,   891,   892, -1236, -1236,
   -1236,   598, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   549, -1236, -1236, -1236, -1236,   747, -1236, -1236, -1236,
     587, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236,   894,   685,   680, -1236, -1236, -1236, -1236, -1236,
     574, -1236, -1236, -1236,   754,   899,   900, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236,   680, -1236, -1236, -1236, -1236, -1236,
     576, -1236, -1236,   901,   902, -1236,   580, -1236, -1236, -1236,
   -1236
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   872, -1236,
     893, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   857,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236,   512,  -338,  -411, -1236, -1236,  -496, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,   776, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
     438, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   715, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236,   344, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   613, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236,   304, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   292, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   288,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   286, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,   281, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,   273, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236,   269, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
      78, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236,    29, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
    -400, -1041, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236,  -222, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236,  -392, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236,    50, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
     -22, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
    -293, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236,    -9, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   -75, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,  -358, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,    25, -1236, -1236, -1236, -1236,
   -1236,  -139, -1236, -1236, -1236, -1236,  -218,  -283,  -441, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1208,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1204, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   -90, -1236,  -110,     4, -1236, -1236, -1060, -1139, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,  -356,  -391, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1151,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,  -749, -1236, -1236, -1236, -1236, -1236,  -827, -1236, -1236,
   -1236, -1236, -1236,  -919, -1236, -1236, -1236, -1236, -1236, -1025,
   -1236, -1236, -1236, -1236, -1236, -1124, -1236, -1236, -1236, -1236,
   -1236, -1178, -1236, -1236, -1236, -1236, -1236, -1235, -1236, -1236,
   -1236, -1236, -1236,  -972,  -789, -1236,  -371,  -965, -1236,  -755,
   -1236,  -765, -1236, -1236,  -958, -1236, -1236,  -921, -1236, -1236,
   -1236, -1236, -1236,  -148, -1236, -1236,  -963, -1236, -1236,  -480,
   -1236, -1236, -1236, -1236, -1236,  -918, -1236, -1236,  -916, -1236,
   -1236,  -119, -1236, -1236,  -479, -1236, -1236, -1236, -1236, -1236
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
     957,   639,   216,   305,  1314,    55,   643,  1337,  1338,  1422,
      55,   647,   136,  1117,  1240,  1382,  1126,  1130,  1127,  1383,
     132,   362,   133,   367,   134,  1321,   135,   570,   496,   460,
     461,   585,   586,   956,  1194,  1303,  1200,   389,  1027,   452,
    1357,   587,   588,   259,   348,   611,   380,   473,  1223,   215,
     630,   630,  1398,   619,   265,   619,   630,     6,   630,   268,
     619,    20,    21,   630,   625,   620,   650,   630,   262,   662,
     644,   640,  1449,  1436,  1314,   706,   717,  1437,  1195,   704,
     636,  1202,  1206,  1203,   702,   260,   381,   390,   136,   608,
    1306,  1374,   497,  1092,  1330,  1011,  1252,   991,  1256,   453,
     266,  1314,   420,  1280,  1455,  1442,   639,   269,  1456,   216,
     643,  1418,   263,  1273,   647,  1297,  1479,  1227,  1078,   981,
     676,    12,   630,   619,   233,   234,     7,   438,   751,   440,
     623,   442,   619,   585,   586,   658,  1324,   631,   587,   588,
    1254,   585,   586,  1258,   570,  1259,  1447,   648,   585,   586,
     630,   587,   588,  1079,  1080,    14,  1081,   714,  1228,   451,
    1298,    17,  1049,    41,  1049,   698,   900,  1423,  1013,    30,
     850,    86,  1469,  1325,   400,   400,   400,   946,   400,  1116,
    1049,   233,   234,   884,   771,   585,   586,   619,   619,   619,
     168,   727,   958,   692,   619,   587,   588,    56,   217,   991,
     709,   306,   615,   624,   708,   627,   137,   991,   626,   619,
    1193,   615,   124,   628,   991,     1,     2,  1351,   695,   619,
      57,   619,    58,  1489,    59,    57,    60,    58,   694,    59,
     696,    60,   658,   431,   199,   432,   151,   433,   196,   649,
      25,    26,   755,  1495,   651,   590,   202,   444,   693,   446,
     203,   693,   766,   693,   204,   693,   233,   234,   205,   242,
     245,   248,   257,   206,   410,  1384,   207,   411,   351,   352,
     412,   781,   225,   291,  1159,   292,   693,   293,   693,   250,
     792,  1079,  1080,   294,  1081,   295,   271,   296,  1412,   297,
     284,   298,   285,   299,   286,   300,  1253,   301,   288,   302,
     340,   303,   349,   304,    33,    34,   816,   287,  1109,   358,
     911,   912,   233,   234,   913,   914,   585,   586,   915,   916,
    1110,  1111,   363,  1438,    44,    45,   587,   588,   743,   744,
     745,   305,   368,   855,  1249,  1250,   127,   128,   369,   994,
     995,   153,   154,   158,   159,   376,   163,   164,   377,  1463,
     171,   172,   176,   177,  1457,   181,   182,   186,   187,   191,
     192,   378,   771,   379,  1109,   383,   911,   912,   233,   234,
     913,   914,   585,   586,   915,   916,  1110,  1111,   394,   395,
     396,   397,   587,   588,   210,   211,   233,   234,  1112,  1113,
     251,   252,   272,   273,   279,   280,   384,  1037,  1038,   342,
     343,   371,   372,   405,   406,   351,   352,   421,   422,   455,
     456,   460,   461,  1345,   385,   797,   387,  1070,  1071,  1109,
     386,   911,   912,   233,   234,   913,   914,   585,   586,   915,
     916,  1110,  1111,   491,   492,   500,   501,   587,   588,   506,
     507,  1190,  1191,   511,   512,   516,   517,   521,   522,   527,
     528,   388,  1102,  1103,  1122,  1128,   532,   533,   537,   538,
     392,  1148,    87,   417,    88,    89,    90,   821,    91,    92,
      93,   426,    94,    95,    96,   434,    97,    98,    99,   429,
     100,   101,   910,   911,   912,   233,   234,   913,   914,   585,
     586,   915,   916,   542,   543,   547,   548,   552,   553,   587,
     588,   558,   559,   563,   564,   582,   583,   653,   654,   677,
     678,   712,   654,   728,   729,   740,   741,   756,   757,  1201,
    1204,   782,   783,   806,   807,   464,  1224,   830,   831,   838,
     839,   843,   844,   856,   857,   866,   867,   872,   873,   877,
     878,   934,   935,   939,   940,   971,   972,   988,   989,  1000,
    1001,  1032,  1033,  1043,  1044,  1060,  1061,  1065,  1066,  1097,
    1098,  1104,  1105,  1131,  1132,  1153,  1154,  1167,  1168,  1185,
    1186,  1207,  1208,  1244,  1245,  1265,  1154,  1269,  1270,  1281,
    1282,  1257,  1260,  1332,  1333,  1352,  1353,  1361,  1362,  1377,
    1378,  1274,  1275,  1387,  1388,  1413,  1414,  1426,  1427,  1431,
    1432,  1450,  1451,  1464,  1465,  1484,  1485,   469,   447,   470,
     477,   400,   478,   480,   484,   488,   489,   490,   499,   505,
     526,   557,   575,   576,   568,   580,   574,   597,   577,   598,
     605,   601,   606,   578,   607,   613,   618,   629,   652,   663,
     612,   667,   666,   668,   682,   669,   685,   683,   715,   684,
     686,   672,   690,   687,   697,   691,   710,   711,   718,   719,
     723,   720,   733,   734,   738,   739,   750,   762,   771,   761,
     767,   752,   774,   775,   776,   777,   778,   768,   779,   780,
     787,   793,   817,   797,   805,   811,   812,   800,   813,   814,
     821,   824,   829,   788,   848,   794,   850,   835,   865,   882,
     860,   889,   905,   818,   906,   894,   944,   951,   884,   963,
     964,   969,   996,   977,   900,   981,   997,   998,   999,   984,
     976,  1019,  1006,   946,  1018,  1025,   958,  1039,  1042,  1054,
    1059,  1308,  1309,  1028,  1073,  1072,  1074,  1075,  1090,  1076,
    1077,  1149,  1152,  1385,  1386,  1093,  1013,  1395,  1049,  1172,
    1162,  1173,  1178,  1179,  1180,  1158,  1181,  1183,  1225,  1237,
    1236,  1322,  1323,  1238,  1242,  1241,  1243,  1264,  1276,  1289,
    1288,  1291,  1295,  1304,  1307,  1310,  1294,  1226,  1227,  1296,
    1317,  1318,  1331,  1319,  1346,  1347,  1118,  1359,  1360,  1372,
    1297,  1396,  1324,  1403,  1407,  1408,  1368,  1421,  1420,  1399,
    1424,  1439,  1440,  1445,  1461,  1471,  1474,  1472,  1481,  1475,
    1476,  1477,  1483,  1480,  1473,  1493,  1494,  1491,  1492,  1498,
    1499,  1497,   123,   581,   481,   226,   664,  1500,    40,   152,
     689,   418,  1458,  1459,   699,   703,   707,   705,   713,   716,
     907,   985,  1405,  1266,   341,  1400,   965,  1311,  1029,  1020,
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
    1051,     4,     4,     4,     4,    43,  1167,    45,    70,    47,
      43,    49,    45,    51,    47,    53,    49,    70,    51,   987,
      53,   820,    63,   371,    55,    65,    57,    67,    59,    69,
      61,   796,   124,   124,   124,    75,   124,    77,   102,    79,
     100,    81,   110,    83,   110,    85,   155,    87,   155,    89,
     150,    91,   473,    93,  1022,    95,   106,    16,    17,    18,
      19,   155,   837,  1031,   118,    16,    17,    18,    19,   112,
     228,   116,   230,   579,   232,  1057,    20,    21,    22,    23,
     114,   532,   123,   123,  1233,   123,   537,    41,    42,     4,
     123,   542,   123,  1024,  1129,  1313,  1024,  1026,  1024,  1313,
      55,   230,    57,   232,    59,  1239,    61,   455,     4,     6,
       7,   172,   173,   872,  1089,  1185,  1089,     4,   955,     4,
    1281,   182,   183,     4,   224,   491,     4,   475,  1096,    63,
      73,    73,  1320,    71,     4,    71,    73,     0,    73,     4,
      71,    10,    11,    73,    80,    76,    84,    73,     4,   570,
      92,    94,  1397,  1371,  1303,    92,   662,  1371,  1089,    94,
      90,  1089,  1091,  1089,    90,    46,    44,    54,   123,    66,
    1205,  1305,    68,  1010,  1244,   934,  1151,   238,  1151,    64,
      50,  1330,   311,  1165,  1402,  1373,   637,    52,  1402,   123,
     641,  1352,    48,  1161,   645,   302,  1441,   306,   122,   163,
     601,    14,    73,    71,   168,   169,   125,   327,   714,   329,
      78,   331,    71,   172,   173,   563,   310,    88,   182,   183,
    1151,   172,   173,  1151,   572,  1151,  1387,    86,   172,   173,
      73,   182,   183,   157,   158,    15,   160,   658,   347,   339,
     347,   314,   310,   318,   310,    88,   310,   162,   302,   316,
     310,   126,  1413,   347,   346,   346,   346,   302,   346,  1024,
     310,   168,   169,   306,   218,   172,   173,    71,    71,    71,
      27,   672,   306,    76,    71,   182,   183,   315,   319,   238,
      84,   321,   344,   511,    86,    82,   317,   238,   516,    71,
    1089,   344,   320,   521,   238,    12,    13,  1279,    80,    71,
     338,    71,   340,  1464,   342,   338,   344,   340,    78,   342,
      82,   344,   660,   319,    39,   321,   315,   323,    26,   547,
      10,    11,   723,  1484,   552,   483,     5,   333,   621,   335,
       5,   624,   733,   626,     5,   628,   168,   169,     5,   339,
     341,   343,   345,     5,   211,  1313,   322,   214,   180,   181,
     217,   752,   317,    65,  1405,    67,   649,    69,   651,     3,
     761,   157,   158,    75,   160,    77,     3,    79,  1350,    81,
     128,    83,   132,    85,   136,    87,  1151,    89,   144,    91,
     319,    93,    10,    95,    10,    11,   787,   140,   164,    10,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    10,  1371,    10,    11,   182,   183,    28,    29,
      30,   123,     3,   814,   190,   191,    10,    11,    10,   909,
     909,    10,    11,    10,    11,   339,    10,    11,   341,  1411,
      10,    11,    10,    11,  1402,    10,    11,    10,    11,    10,
      11,   343,   218,     8,   164,   345,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   470,   471,
     472,   473,   182,   183,    10,    11,   168,   169,   188,   189,
      10,    11,    10,    11,    10,    11,    46,   967,   967,    10,
      11,    10,    11,    10,    11,   180,   181,    10,    11,    10,
      11,     6,     7,  1268,    48,   215,    52,   987,   987,   164,
      50,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,    10,    11,    10,    11,   182,   183,    10,
      11,   186,   187,    10,    11,    10,    11,    10,    11,    10,
      11,     8,  1022,  1022,  1024,  1024,    10,    11,    10,    11,
       6,  1031,   127,   321,   129,   130,   131,   212,   133,   134,
     135,    31,   137,   138,   139,    33,   141,   142,   143,    32,
     145,   146,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    10,    11,    10,    11,    10,    11,   182,
     183,    10,    11,    10,    11,    10,    11,    96,    97,    10,
      11,    96,    97,    10,    11,    10,    11,    10,    11,  1089,
    1089,    10,    11,    10,    11,     3,  1096,    10,    11,    10,
      11,    10,    11,   120,   121,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,   108,   109,    10,    11,    10,
      11,    10,    11,    10,    11,   108,   109,    10,    11,    10,
      11,  1151,  1151,    10,    11,    10,    11,    10,    11,    10,
      11,  1161,  1161,    10,    11,    10,    11,   239,   240,    10,
      11,    10,    11,    10,    11,    10,    11,     8,    34,     6,
      44,   346,    54,   124,   312,     8,     8,     8,     8,     8,
       8,     8,     8,    58,    64,   124,    56,   323,    60,   308,
       6,    35,     6,    62,     6,     6,     6,     6,     6,   124,
      68,     3,   347,     3,     8,   304,    66,     8,   124,     8,
       8,    36,     8,    10,     8,    10,     8,    10,     8,     8,
      37,   119,     6,    99,     4,     4,     4,   111,   218,     6,
     313,    38,   345,    72,    74,     3,     3,   101,     3,    98,
       6,   309,   305,   215,     8,     8,     8,   103,     8,     6,
     212,   103,     8,   115,     6,   113,   310,   105,     8,     6,
     103,   107,     8,   117,   100,   330,     6,   346,   306,     8,
     112,    40,     8,   326,   310,   163,     3,     3,     3,   102,
     104,   116,   346,   302,     8,   104,   306,   346,     8,   328,
       8,  1212,  1213,   114,     8,   311,     6,     8,   104,     8,
       8,   307,     6,  1313,  1313,   118,   302,  1316,   310,     6,
     324,   161,   311,     6,     8,   106,     5,   122,   303,     3,
       8,  1242,  1243,     3,     3,   307,     3,     8,   332,   241,
       8,   153,     8,     3,   303,   347,   331,   155,   306,   159,
       6,     8,     3,     8,   311,   334,  1024,   327,     8,     8,
     302,     8,   310,     8,     8,   336,   347,     6,   329,   347,
      10,  1371,  1371,   307,     6,   325,     6,     8,   311,     8,
       8,   303,     8,   156,   162,     6,     6,   333,   154,     8,
       8,   335,    40,   475,   402,   139,   572,   337,    25,    62,
     616,   308,  1402,  1402,   632,   637,   645,   641,   655,   660,
     852,   902,  1332,  1155,   219,  1327,   886,  1230,   960,   948,
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
       0,    12,    13,   475,   476,   477,     0,   125,   484,   485,
    1065,  1066,    14,   478,    15,   482,   483,   314,   486,   487,
      10,    11,  1067,  1068,  1069,    10,    11,   479,   480,   481,
     316,   572,   573,    10,    11,   488,   489,   490,  1070,  1071,
     484,   318,   615,   616,    10,    11,   574,   575,   576,    43,
      45,    47,    49,    51,    53,   123,   315,   338,   340,   342,
     344,   491,   492,   493,   494,   495,   500,   501,   506,   507,
     512,   513,   520,   521,   526,   527,   532,   533,   538,   539,
     544,   545,   550,   551,   558,   559,   126,   127,   129,   130,
     131,   133,   134,   135,   137,   138,   139,   141,   142,   143,
     145,   146,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,   482,   320,   638,   639,    10,    11,   617,
     618,   619,    55,    57,    59,    61,   123,   317,   577,   578,
     579,   580,   581,   587,   588,   594,   595,   601,   602,   606,
     607,   315,   493,    10,    11,   496,   497,   498,    10,    11,
     502,   503,   504,    10,    11,   508,   509,   510,    27,   514,
     515,    10,    11,   522,   523,   524,    10,    11,   528,   529,
     530,    10,    11,   534,   535,   536,    10,    11,   540,   541,
     542,    10,    11,   546,   547,   548,    26,   552,   553,    39,
     560,  1045,     5,     5,     5,     5,     5,   322,   749,   750,
      10,    11,   640,   641,   642,    63,   123,   319,   620,   621,
     622,   623,   624,   629,   630,   317,   579,   582,   583,   589,
     590,   596,   597,   168,   169,   603,  1167,  1168,  1169,   608,
    1045,     4,   339,   499,     4,   341,   505,     4,   343,   511,
       3,    10,    11,   516,   517,   518,     4,   345,   525,     4,
      46,   531,     4,    48,   537,     4,    50,   543,     4,    52,
     549,     3,    10,    11,   554,   555,   556,  1062,  1063,    10,
      11,   561,   562,   563,   128,   132,   136,   140,   144,   751,
     752,    65,    67,    69,    75,    77,    79,    81,    83,    85,
      87,    89,    91,    93,    95,   123,   321,   643,   644,   645,
     646,   647,   654,   655,   660,   661,   668,   669,   673,   674,
     678,   679,   683,   684,   688,   689,   696,   697,   704,   705,
     712,   713,   720,   721,   726,   727,   732,   733,   740,   741,
     319,   622,    10,    11,   625,   626,   627,   631,  1045,    10,
     585,   180,   181,   584,  1167,  1185,  1186,  1187,    10,   592,
     591,  1167,  1185,    10,   599,   598,  1167,  1185,     3,    10,
     604,    10,    11,   609,   610,   611,   339,   341,   343,     8,
       4,    44,   519,   345,    46,    48,    50,    52,     8,     4,
      54,   557,     6,     8,   470,   471,   472,   473,  1064,   124,
     346,   564,   565,   566,   567,    10,    11,   754,   755,   756,
     211,   214,   217,   753,  1149,  1154,  1156,   321,   645,   648,
    1185,    10,    11,   656,   657,   658,    31,   662,  1042,    32,
    1048,  1048,  1048,  1048,    33,   690,  1047,   698,  1047,   706,
    1047,   714,  1047,   722,  1048,   728,  1048,    34,   734,  1049,
     742,  1045,     4,    64,   628,    10,    11,   632,   633,   634,
       6,     7,   586,  1061,     3,   593,  1061,   600,  1061,     8,
       6,   605,   124,   567,   612,   613,   614,    44,    54,  1062,
     124,   566,   568,   569,   312,   757,   758,   759,     8,     8,
       8,    10,    11,   649,   650,   651,     4,    68,   659,     8,
      10,    11,   663,   664,   665,     8,    10,    11,   670,   671,
     672,    10,    11,   675,   676,   677,    10,    11,   680,   681,
     682,    10,    11,   685,   686,   687,     8,    10,    11,   691,
     692,   693,    10,    11,   699,   700,   701,    10,    11,   707,
     708,   709,    10,    11,   715,   716,   717,    10,    11,   723,
     724,   725,    10,    11,   729,   730,   731,     8,    10,    11,
     735,   736,   737,    10,    11,   743,   744,   745,    64,   124,
     567,   635,   636,   637,    56,     8,    58,    60,    62,   568,
     124,   614,    10,    11,   571,   172,   173,   182,   183,   570,
    1167,  1173,  1174,  1175,  1188,  1189,  1190,   323,   308,   854,
     855,    35,   760,   761,  1046,     6,     6,     6,    66,   652,
     653,  1061,    68,     6,    70,   344,   666,   667,     6,    71,
      76,  1010,  1011,    78,  1010,    80,  1010,    82,  1010,     6,
      73,    88,   694,   695,  1012,  1013,    90,   702,   703,  1012,
      94,   710,   711,  1012,    92,   718,   719,  1012,    86,  1010,
      84,  1010,     6,    96,    97,   738,   739,   124,   567,   746,
     747,   748,   568,   124,   637,   571,   347,     3,     3,   304,
     921,   922,    36,   856,   857,  1044,  1062,    10,    11,   762,
     763,   764,     8,     8,     8,    66,     8,    10,    70,   667,
       8,    10,    76,  1011,    78,    80,    82,     8,    88,   695,
    1014,  1015,    90,   703,    94,   711,    92,   719,    86,    84,
       8,    10,    96,   739,   568,   124,   748,   571,     8,     8,
     119,   988,   989,    37,   923,   924,  1043,  1062,    10,    11,
     858,   859,   860,     6,    99,   765,   766,   767,     4,     4,
      10,    11,  1020,    28,    29,    30,  1016,  1017,  1018,  1019,
       4,   571,    38,   990,  1050,  1062,    10,    11,   925,   926,
     927,     6,   111,   861,   862,   863,  1062,   313,   101,   780,
     781,   218,   768,  1155,   345,    72,    74,     3,     3,     3,
      98,  1062,    10,    11,   991,   992,   993,     6,   115,   928,
     929,   930,  1062,   309,   113,   876,   877,   215,   864,  1153,
     103,   794,   795,   782,  1155,     8,    10,    11,   769,   770,
     771,     8,     8,     8,     6,   994,  1062,   305,   117,   943,
     944,   212,   931,  1148,   103,   890,   891,   878,  1153,     8,
      10,    11,   865,   866,   867,   105,   807,   808,    10,    11,
     796,   797,   798,    10,    11,   783,   784,   785,     6,   100,
     310,   772,   773,   774,   775,  1062,   120,   121,   995,   996,
     103,   957,   958,   945,  1148,     8,    10,    11,   932,   933,
     934,   903,    10,    11,   892,   893,   894,    10,    11,   879,
     880,   881,     6,   112,   306,   868,   869,   870,   871,   107,
     821,   822,   809,  1155,   330,   799,   800,  1105,  1106,   102,
     310,   786,   787,   788,   789,     8,   100,   774,   776,   777,
     165,   166,   167,   170,   171,   174,   175,   997,   998,   999,
    1152,  1161,  1162,  1163,  1167,  1173,  1179,  1180,  1181,  1182,
    1183,  1184,  1188,   970,    10,    11,   959,   960,   961,    10,
      11,   946,   947,   948,     6,   116,   302,   935,   936,   937,
     938,   346,   904,   905,   895,   896,  1105,   114,   306,   882,
     883,   884,   885,     8,   112,   870,   872,   873,   836,    40,
     823,    10,    11,   810,   811,   812,   104,   326,   801,  1111,
    1112,   163,  1147,  1150,   102,   788,   790,   791,    10,    11,
     779,   238,   778,  1158,  1173,  1188,     8,     3,     3,     3,
      10,    11,  1000,  1001,  1002,   999,   346,   971,   972,   962,
     963,  1105,   118,   302,   949,   950,   951,   952,     8,   116,
     937,   939,   940,   906,   907,   104,   897,  1111,   114,   884,
     886,   887,    10,    11,   875,   874,  1158,  1173,  1188,   346,
     837,   838,     8,    10,    11,   824,   825,   826,   106,   310,
     813,   814,   815,   816,   328,   802,  1117,  1118,  1147,     8,
      10,    11,  1107,  1108,  1109,    10,    11,   793,   792,  1158,
    1173,  1188,   311,     8,     6,     8,     8,     8,   122,   157,
     158,   160,  1003,  1004,  1005,  1006,  1007,  1008,   973,   974,
     104,   964,  1111,   118,   951,   953,   954,    10,    11,   942,
     941,  1158,  1173,  1188,    10,    11,   909,   910,   911,   164,
     176,   177,   188,   189,   908,  1151,  1153,  1161,  1167,  1170,
    1171,  1172,  1173,  1176,  1177,  1178,  1179,  1182,  1188,   898,
    1117,    10,    11,   889,    16,    17,    18,    19,   888,  1023,
    1024,  1025,  1026,  1034,  1035,  1036,  1037,  1158,  1173,   307,
     839,   840,     6,   108,   109,   827,   828,   829,   106,   815,
     817,   818,   324,   803,  1123,  1124,  1147,    10,    11,  1113,
    1114,  1115,     6,   161,  1093,  1094,  1101,  1110,   311,     6,
       8,     5,  1009,   122,  1005,    10,    11,   976,   977,   978,
     186,   187,   975,  1148,  1151,  1161,  1164,  1165,  1166,  1167,
    1170,  1173,  1179,  1182,  1188,   965,  1117,    10,    11,   956,
      20,    21,    22,    23,   955,  1027,  1028,  1029,  1030,  1038,
    1039,  1040,  1041,  1158,  1173,   303,   155,   306,   347,   912,
     913,   914,   915,  1051,  1052,  1053,     8,     3,     3,   899,
    1123,   307,     3,     3,    10,    11,   842,   843,   844,   190,
     191,   841,  1151,  1155,  1161,  1167,  1170,  1173,  1179,  1182,
    1188,  1191,  1192,  1193,     8,   108,   828,   830,   831,    10,
      11,   820,   819,  1158,  1173,  1188,   332,   804,  1129,  1130,
    1147,    10,    11,  1119,  1120,  1121,  1093,  1116,     8,   241,
    1157,   153,  1095,  1096,   331,     8,   159,   302,   347,   979,
     980,   981,   982,  1051,     3,   966,  1123,   303,  1062,  1062,
     347,   914,   916,   917,  1052,  1054,  1055,     6,     8,     8,
     900,  1129,  1062,  1062,   310,   347,   845,   846,   847,   848,
    1051,     3,    10,    11,   833,   834,   835,    41,    42,   832,
    1021,  1022,  1031,  1032,  1033,  1155,   311,   334,   805,  1135,
    1136,  1147,    10,    11,  1125,  1126,  1127,  1093,  1122,   327,
       8,    10,    11,  1102,  1103,  1104,  1097,  1098,   347,   981,
     983,   984,     8,   967,  1129,  1061,  1061,    10,    11,   919,
     920,   918,  1023,  1034,  1158,  1173,  1188,    10,    11,  1057,
    1058,  1059,  1056,  1150,  1167,  1188,     8,   901,  1135,   347,
     847,   849,   850,     8,   110,   814,  1062,     8,   336,   806,
    1141,  1142,  1147,    10,    11,  1131,  1132,  1133,  1093,  1128,
     329,     6,     4,   162,    10,  1100,   239,   240,  1099,  1159,
    1160,    10,    11,   986,   987,   985,  1023,  1034,  1158,  1173,
    1188,   968,  1135,  1062,  1062,   307,  1060,  1093,   902,  1141,
      10,    11,   852,   853,   851,  1023,  1034,  1158,  1173,  1188,
     110,     6,  1061,  1147,    10,    11,  1137,  1138,  1139,  1093,
    1134,   325,     8,   162,     6,     8,     8,   303,   969,  1141,
     156,   311,  1062,     8,    10,    11,  1143,  1144,  1145,  1093,
    1140,   333,   154,     6,     6,  1093,  1146,   335,     8,     8,
     337
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
    parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
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
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
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


