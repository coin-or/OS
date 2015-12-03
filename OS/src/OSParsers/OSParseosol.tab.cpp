
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
     EMPTYINCLUDEDIAGONALATT = 703,
     INCLUDEDIAGONALATT = 704,
     EMPTYIDATT = 705,
     IDATT = 706
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
#define EMPTYINCLUDEDIAGONALATT 703
#define INCLUDEDIAGONALATT 704
#define EMPTYIDATT 705
#define IDATT 706




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
#define YYNTOKENS  456
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  720
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1097
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1501

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   706

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   453,
     455,     2,     2,   454,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   452,     2,     2,     2,     2,     2,     2,     2,
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
     445,   446,   447,   448,   449,   450,   451
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
     457,     0,    -1,   458,   466,   464,    -1,   459,   460,   461,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   462,    -1,
     463,    -1,    11,    -1,    10,   466,   464,    -1,   465,    -1,
      15,    -1,    -1,   467,   468,   554,   597,   620,   731,    -1,
      -1,  1047,    -1,    -1,   469,   470,    -1,   314,    -1,   471,
      -1,   472,    -1,    10,   315,    -1,    11,    -1,    10,   473,
     315,    -1,   474,    -1,   475,    -1,   474,   475,    -1,   476,
      -1,   482,    -1,   488,    -1,   494,    -1,   502,    -1,   508,
      -1,   514,    -1,   520,    -1,   526,    -1,   532,    -1,   540,
      -1,   477,   478,    -1,   338,    -1,   479,    -1,   480,    -1,
      10,   339,    -1,    11,    -1,    10,   481,   339,    -1,     4,
      -1,   483,   484,    -1,   340,    -1,   485,    -1,   486,    -1,
      10,   341,    -1,    11,    -1,    10,   487,   341,    -1,     4,
      -1,   489,   490,    -1,   342,    -1,   491,    -1,   492,    -1,
      10,   343,    -1,    11,    -1,    10,   493,   343,    -1,     4,
      -1,   495,   496,   498,    -1,    43,    -1,    -1,   497,    -1,
      27,     3,     8,    -1,   499,    -1,   500,    -1,    10,    44,
      -1,    11,    -1,    10,   501,    44,    -1,     4,    -1,   503,
     504,    -1,   344,    -1,   505,    -1,   506,    -1,    10,   345,
      -1,    11,    -1,    10,   507,   345,    -1,     4,    -1,   509,
     510,    -1,    45,    -1,   511,    -1,   512,    -1,    10,    46,
      -1,    11,    -1,    10,   513,    46,    -1,     4,    -1,   515,
     516,    -1,    47,    -1,   517,    -1,   518,    -1,    10,    48,
      -1,    11,    -1,    10,   519,    48,    -1,     4,    -1,   521,
     522,    -1,    49,    -1,   523,    -1,   524,    -1,    10,    50,
      -1,    11,    -1,    10,   525,    50,    -1,     4,    -1,   527,
     528,    -1,    51,    -1,   529,    -1,   530,    -1,    10,    52,
      -1,    11,    -1,    10,   531,    52,    -1,     4,    -1,   533,
     534,   536,    -1,    53,    -1,    -1,   535,    -1,    26,     3,
       8,    -1,   537,    -1,   538,    -1,    10,    54,    -1,    11,
      -1,    10,   539,    54,    -1,     4,    -1,   541,   542,   543,
      -1,   123,    -1,  1027,    -1,   544,    -1,   545,    -1,    10,
     124,    -1,    11,    -1,    10,   546,   124,    -1,   547,    -1,
     548,    -1,   547,   548,    -1,   549,   550,   553,    -1,   346,
      -1,   551,    -1,    -1,   551,   552,    -1,  1155,    -1,  1170,
      -1,  1149,    -1,    10,   347,    -1,    11,    -1,    -1,   555,
     556,    -1,   316,    -1,   557,    -1,   558,    -1,    10,   317,
      -1,    11,    -1,    10,   559,   317,    -1,   560,    -1,   561,
      -1,   560,   561,    -1,   562,    -1,   569,    -1,   576,    -1,
     583,    -1,   588,    -1,   563,   564,   567,    -1,    55,    -1,
     565,    -1,    -1,   565,   566,    -1,  1167,    -1,  1149,    -1,
      10,   568,    56,    -1,  1043,    -1,   570,   571,   574,    -1,
      57,    -1,   572,    -1,    -1,   572,   573,    -1,  1167,    -1,
    1149,    -1,    10,   575,    58,    -1,  1043,    -1,   577,   578,
     581,    -1,    59,    -1,   579,    -1,    -1,   579,   580,    -1,
    1167,    -1,  1149,    -1,    10,   582,    60,    -1,  1043,    -1,
     584,   585,   586,    -1,    61,    -1,    -1,  1149,    -1,    10,
     587,    62,    -1,     6,    -1,   589,   590,   591,    -1,   123,
      -1,  1027,    -1,   592,    -1,   593,    -1,    10,   124,    -1,
      11,    -1,    10,   594,   124,    -1,   595,    -1,   596,    -1,
     595,   596,    -1,   549,   550,   553,    -1,    -1,   598,   599,
      -1,   318,    -1,   600,    -1,   601,    -1,    10,   319,    -1,
      11,    -1,    10,   602,   319,    -1,   603,    -1,   604,    -1,
     603,   604,    -1,   605,    -1,   611,    -1,   606,   607,    -1,
      63,    -1,   608,    -1,   609,    -1,    10,    64,    -1,    11,
      -1,    10,   610,    64,    -1,     4,    -1,   612,   613,   614,
      -1,   123,    -1,  1027,    -1,   615,    -1,   616,    -1,    10,
     124,    -1,    11,    -1,    10,   617,   124,    -1,   618,    -1,
     619,    -1,   618,   619,    -1,   549,   550,   553,    -1,    -1,
     621,   622,    -1,   320,    -1,   623,    -1,   624,    -1,    10,
     321,    -1,    11,    -1,    10,   625,   321,    -1,   626,    -1,
     627,    -1,   626,   627,    -1,   628,    -1,   636,    -1,   642,
      -1,   650,    -1,   655,    -1,   660,    -1,   665,    -1,   670,
      -1,   678,    -1,   694,    -1,   686,    -1,   702,    -1,   708,
      -1,   714,    -1,   722,    -1,   629,   630,   631,    -1,    65,
      -1,    -1,  1167,    -1,   632,    -1,   633,    -1,    10,    66,
      -1,    11,    -1,    10,   634,    66,    -1,   635,    -1,  1043,
      -1,   637,   638,    -1,    67,    -1,   639,    -1,   640,    -1,
      10,    68,    -1,    11,    -1,    10,   641,    68,    -1,     4,
      -1,   643,   644,   645,    -1,    69,    -1,  1024,    -1,   646,
      -1,   647,    -1,    10,    70,    -1,    11,    -1,    10,   648,
      70,    -1,   649,    -1,   648,   649,    -1,   344,    10,     4,
     345,    -1,   651,  1030,   652,    -1,    75,    -1,   653,    -1,
     654,    -1,    10,    76,    -1,    11,    -1,    10,   992,    76,
      -1,   656,  1030,   657,    -1,    77,    -1,   658,    -1,   659,
      -1,    10,    78,    -1,    11,    -1,    10,   992,    78,    -1,
     661,  1030,   662,    -1,    79,    -1,   663,    -1,   664,    -1,
      10,    80,    -1,    11,    -1,    10,   992,    80,    -1,   666,
    1030,   667,    -1,    81,    -1,   668,    -1,   669,    -1,    10,
      82,    -1,    11,    -1,    10,   992,    82,    -1,   671,   672,
     673,    -1,    87,    -1,  1029,    -1,   674,    -1,   675,    -1,
      10,    88,    -1,    11,    -1,    10,   676,    88,    -1,   677,
      -1,   676,   677,    -1,   994,    -1,   679,   680,   681,    -1,
      89,    -1,  1029,    -1,   682,    -1,   683,    -1,    10,    90,
      -1,    11,    -1,    10,   684,    90,    -1,   685,    -1,   684,
     685,    -1,   994,    -1,   687,   688,   689,    -1,    93,    -1,
    1029,    -1,   690,    -1,   691,    -1,    10,    94,    -1,    11,
      -1,    10,   692,    94,    -1,   693,    -1,   692,   693,    -1,
     994,    -1,   695,   696,   697,    -1,    91,    -1,  1029,    -1,
     698,    -1,   699,    -1,    10,    92,    -1,    11,    -1,    10,
     700,    92,    -1,   701,    -1,   700,   701,    -1,   994,    -1,
     703,   704,   705,    -1,    85,    -1,  1030,    -1,   706,    -1,
     707,    -1,    10,    86,    -1,    11,    -1,    10,   992,    86,
      -1,   709,   710,   711,    -1,    83,    -1,  1030,    -1,   712,
      -1,   713,    -1,    10,    84,    -1,    11,    -1,    10,   992,
      84,    -1,   715,   716,   717,    -1,    95,    -1,  1031,    -1,
     718,    -1,   719,    -1,    10,    96,    -1,    11,    -1,    10,
     720,    96,    -1,   721,    -1,   720,   721,    -1,    97,    10,
       4,    98,    -1,   723,   724,   725,    -1,   123,    -1,  1027,
      -1,   726,    -1,   727,    -1,    10,   124,    -1,    11,    -1,
      10,   728,   124,    -1,   729,    -1,   730,    -1,   729,   730,
      -1,   549,   550,   553,    -1,    -1,   732,   733,   736,    -1,
     322,    -1,   734,    -1,    -1,   734,   735,    -1,  1138,    -1,
    1131,    -1,  1136,    -1,   737,    -1,   738,    -1,    11,    -1,
      10,   739,   323,    -1,   740,   836,   903,   970,    -1,    -1,
     741,   742,   744,    -1,   312,    -1,   743,    -1,    -1,  1028,
      -1,   745,    -1,   746,    -1,    11,    -1,    10,   747,   313,
      -1,   748,   762,   776,   789,   803,   818,    -1,    -1,   749,
     750,   751,    -1,    99,    -1,  1137,    -1,   752,    -1,   753,
      -1,    10,   100,    -1,    11,    -1,    10,   754,   100,    -1,
     755,    -1,   756,    -1,   755,   756,    -1,   757,   758,   761,
      -1,   310,    -1,   759,    -1,    -1,   759,   760,    -1,  1140,
      -1,  1155,    -1,  1170,    -1,    10,   311,    -1,    11,    -1,
      -1,   763,   764,   765,    -1,   101,    -1,  1137,    -1,   766,
      -1,   767,    -1,    10,   102,    -1,    11,    -1,    10,   768,
     102,    -1,   769,    -1,   770,    -1,   769,   770,    -1,   771,
     772,   775,    -1,   310,    -1,   773,    -1,    -1,   773,   774,
      -1,  1140,    -1,  1155,    -1,  1170,    -1,    10,   311,    -1,
      11,    -1,    -1,   777,   778,    -1,   103,    -1,   779,    -1,
     780,    -1,    11,    -1,    10,   781,   104,    -1,   782,   783,
     784,   785,   786,   787,   788,    -1,    -1,  1087,    -1,    -1,
    1093,    -1,    -1,  1099,    -1,    -1,  1105,    -1,    -1,  1111,
      -1,    -1,  1117,    -1,    -1,  1123,    -1,    -1,   790,   791,
     792,    -1,   105,    -1,  1137,    -1,   793,    -1,   794,    -1,
      10,   106,    -1,    11,    -1,    10,   795,   106,    -1,   796,
      -1,   797,    -1,   796,   797,    -1,   798,   799,   802,    -1,
     310,    -1,   800,    -1,    -1,   800,   801,    -1,  1140,    -1,
    1155,    -1,  1170,    -1,    10,   311,    -1,    11,    -1,    -1,
     804,   805,   806,    -1,   107,    -1,    40,     8,     6,     8,
      -1,   807,    -1,   808,    -1,    10,   108,    -1,    11,    -1,
      10,   809,   108,    -1,   810,    -1,   809,   810,    -1,   811,
     812,   815,    -1,   109,    -1,   813,    -1,    -1,   813,   814,
      -1,  1013,    -1,  1137,    -1,  1003,    -1,   816,    -1,   817,
      -1,    10,   110,    -1,    11,    -1,    10,   796,   110,    -1,
      -1,   818,   819,    -1,   820,   821,   824,    -1,   346,    -1,
     822,    -1,    -1,   822,   823,    -1,  1137,    -1,  1133,    -1,
    1155,    -1,  1170,    -1,  1161,    -1,  1143,    -1,  1164,    -1,
    1173,    -1,  1152,    -1,  1149,    -1,   825,    -1,   826,    -1,
      10,   347,    -1,    11,    -1,    10,   827,   347,    -1,   828,
      -1,  1033,    -1,   829,    -1,   828,   829,    -1,   830,   831,
     834,    -1,   310,    -1,   832,    -1,    -1,   832,   833,    -1,
    1140,    -1,  1155,    -1,  1170,    -1,  1005,    -1,  1016,    -1,
     835,    -1,    10,   311,    -1,    11,    -1,    -1,   837,   838,
     840,    -1,   308,    -1,   839,    -1,    -1,  1026,    -1,   841,
      -1,   842,    -1,    11,    -1,    10,   843,   309,    -1,   844,
     858,   872,   885,    -1,    -1,   845,   846,   847,    -1,   111,
      -1,  1135,    -1,   848,    -1,   849,    -1,    10,   112,    -1,
      11,    -1,    10,   850,   112,    -1,   851,    -1,   852,    -1,
     851,   852,    -1,   853,   854,   857,    -1,   306,    -1,   855,
      -1,    -1,   855,   856,    -1,  1140,    -1,  1155,    -1,  1170,
      -1,    10,   307,    -1,    11,    -1,    -1,   859,   860,   861,
      -1,   113,    -1,  1135,    -1,   862,    -1,   863,    -1,    10,
     114,    -1,    11,    -1,    10,   864,   114,    -1,   865,    -1,
     866,    -1,   865,   866,    -1,   867,   868,   871,    -1,   306,
      -1,   869,    -1,    -1,   869,   870,    -1,  1140,    -1,  1155,
      -1,  1005,    -1,  1016,    -1,    10,   307,    -1,    11,    -1,
      -1,   873,   874,    -1,   103,    -1,   875,    -1,   876,    -1,
      11,    -1,    10,   877,   104,    -1,   878,   879,   880,   881,
     882,   883,   884,    -1,    -1,  1087,    -1,    -1,  1093,    -1,
      -1,  1099,    -1,    -1,  1105,    -1,    -1,  1111,    -1,    -1,
    1117,    -1,    -1,  1123,    -1,    -1,   885,   886,    -1,   887,
     888,   891,    -1,   346,    -1,   889,    -1,    -1,   889,   890,
      -1,  1135,    -1,  1133,    -1,  1155,    -1,  1170,    -1,  1161,
      -1,  1143,    -1,  1164,    -1,  1158,    -1,  1152,    -1,  1149,
      -1,   892,    -1,   893,    -1,    10,   347,    -1,    11,    -1,
      10,   894,   347,    -1,   895,    -1,  1033,    -1,   896,    -1,
     895,   896,    -1,   897,   898,   901,    -1,   306,    -1,   899,
      -1,    -1,   899,   900,    -1,  1140,    -1,  1155,    -1,  1170,
      -1,  1005,    -1,  1016,    -1,   902,    -1,    10,   307,    -1,
      11,    -1,    -1,   904,   905,   907,    -1,   304,    -1,   906,
      -1,    -1,  1025,    -1,   908,    -1,   909,    -1,    11,    -1,
      10,   910,   305,    -1,   911,   925,   939,   952,    -1,    -1,
     912,   913,   914,    -1,   115,    -1,  1130,    -1,   915,    -1,
     916,    -1,    10,   116,    -1,    11,    -1,    10,   917,   116,
      -1,   918,    -1,   919,    -1,   918,   919,    -1,   920,   921,
     924,    -1,   302,    -1,   922,    -1,    -1,   922,   923,    -1,
    1140,    -1,  1155,    -1,  1170,    -1,    10,   303,    -1,    11,
      -1,    -1,   926,   927,   928,    -1,   117,    -1,  1130,    -1,
     929,    -1,   930,    -1,    10,   118,    -1,    11,    -1,    10,
     931,   118,    -1,   932,    -1,   933,    -1,   932,   933,    -1,
     934,   935,   938,    -1,   302,    -1,   936,    -1,    -1,   936,
     937,    -1,  1140,    -1,  1155,    -1,  1009,    -1,  1020,    -1,
      10,   303,    -1,    11,    -1,    -1,   940,   941,    -1,   103,
      -1,   942,    -1,   943,    -1,    11,    -1,    10,   944,   104,
      -1,   945,   946,   947,   948,   949,   950,   951,    -1,    -1,
    1087,    -1,    -1,  1093,    -1,    -1,  1099,    -1,    -1,  1105,
      -1,    -1,  1111,    -1,    -1,  1117,    -1,    -1,  1123,    -1,
      -1,   952,   953,    -1,   954,   955,   958,    -1,   346,    -1,
     956,    -1,    -1,   956,   957,    -1,  1130,    -1,  1133,    -1,
    1155,    -1,  1170,    -1,  1161,    -1,  1143,    -1,  1164,    -1,
    1146,    -1,  1152,    -1,  1149,    -1,   959,    -1,   960,    -1,
      10,   347,    -1,    11,    -1,    10,   961,   347,    -1,   962,
      -1,  1033,    -1,   963,    -1,   962,   963,    -1,   964,   965,
     968,    -1,   302,    -1,   966,    -1,    -1,   966,   967,    -1,
    1140,    -1,  1155,    -1,  1170,    -1,  1005,    -1,  1016,    -1,
     969,    -1,    10,   303,    -1,    11,    -1,    -1,   971,   972,
     973,    -1,   119,    -1,  1032,    -1,   974,    -1,   975,    -1,
      11,    -1,    10,   976,   120,    -1,    -1,   976,   977,    -1,
     978,   979,   982,    -1,   121,    -1,   980,    -1,   981,    -1,
     980,   981,    -1,  1155,    -1,  1170,    -1,  1161,    -1,  1143,
      -1,  1164,    -1,  1149,    -1,  1134,    -1,   983,    -1,   984,
      -1,    10,   122,    -1,    11,    -1,    10,   985,   122,    -1,
     986,    -1,   987,    -1,   986,   987,    -1,   988,    -1,   989,
      -1,   990,    -1,   160,    -1,   157,    -1,   158,   991,   159,
      -1,     5,    -1,   993,    -1,   992,   993,    -1,    71,    10,
       4,    72,    -1,   995,   996,  1002,    -1,    73,    -1,   997,
      -1,    -1,   997,   998,    -1,   999,    -1,  1000,    -1,  1001,
      -1,    28,     3,     8,    -1,    29,     3,     8,    -1,    30,
       3,     8,    -1,    10,    74,    -1,    11,    -1,  1004,    -1,
      42,     8,  1043,     8,    -1,  1006,    -1,  1007,    -1,  1008,
      -1,    16,    -1,    18,     3,  1044,    -1,  1010,    -1,  1011,
      -1,  1012,    -1,    20,    -1,    22,  1044,  1043,  1044,    -1,
    1014,    -1,  1015,    -1,    41,  1044,     6,  1044,    -1,  1017,
      -1,  1018,    -1,  1019,    -1,    17,    -1,    19,     3,  1044,
      -1,  1021,    -1,  1022,    -1,  1023,    -1,    21,    -1,    23,
    1044,  1043,  1044,    -1,    31,     8,     6,     8,    -1,    37,
    1044,     6,  1044,    -1,    36,  1044,     6,  1044,    -1,    39,
    1044,     6,  1044,    -1,    35,  1044,     6,  1044,    -1,    33,
       8,     6,     8,    -1,    32,     8,     6,     8,    -1,    34,
       8,     6,     8,    -1,    38,  1044,     6,  1044,    -1,  1034,
      -1,  1033,  1034,    -1,  1035,  1036,  1039,    -1,   155,    -1,
    1037,    -1,    -1,  1037,  1038,    -1,  1132,    -1,  1170,    -1,
    1149,    -1,  1040,    -1,  1041,    -1,    11,    -1,    10,  1042,
     156,    -1,  1075,    -1,     6,    -1,     7,    -1,  1045,     8,
      -1,    -1,  1045,  1046,    -1,   452,    -1,   453,    -1,   454,
      -1,   455,    -1,  1048,  1049,    -1,   125,    -1,  1050,    -1,
    1051,    -1,    11,    -1,    10,  1052,   126,    -1,  1053,    -1,
      -1,  1053,  1054,    -1,  1055,    -1,  1059,    -1,  1063,    -1,
    1067,    -1,  1071,    -1,  1056,    -1,  1057,    -1,  1058,    -1,
     130,    -1,   129,    -1,   127,     5,   128,    -1,  1060,    -1,
    1061,    -1,  1062,    -1,   134,    -1,   133,    -1,   131,     5,
     132,    -1,  1064,    -1,  1065,    -1,  1066,    -1,   138,    -1,
     137,    -1,   135,     5,   136,    -1,  1068,    -1,  1069,    -1,
    1070,    -1,   142,    -1,   141,    -1,   139,     5,   140,    -1,
    1072,    -1,  1073,    -1,  1074,    -1,   146,    -1,   145,    -1,
     143,     5,   144,    -1,  1076,    -1,  1083,    -1,    -1,  1076,
    1077,    -1,  1078,  1079,  1082,    -1,   153,    -1,  1080,    -1,
      -1,  1080,  1081,    -1,  1142,    -1,  1141,    -1,    10,     6,
     154,    -1,   161,  1139,  1084,    -1,  1085,    -1,  1086,    -1,
      10,   162,    -1,    11,    -1,    10,     4,   162,    -1,  1088,
    1129,  1089,    -1,   330,    -1,  1090,    -1,  1091,    -1,    11,
      -1,    10,  1092,   331,    -1,  1075,    -1,  1094,  1129,  1095,
      -1,   326,    -1,  1096,    -1,  1097,    -1,    11,    -1,    10,
    1098,   327,    -1,  1075,    -1,  1100,  1129,  1101,    -1,   328,
      -1,  1102,    -1,  1103,    -1,    11,    -1,    10,  1104,   329,
      -1,  1075,    -1,  1106,  1129,  1107,    -1,   324,    -1,  1108,
      -1,  1109,    -1,    11,    -1,    10,  1110,   325,    -1,  1075,
      -1,  1112,  1129,  1113,    -1,   332,    -1,  1114,    -1,  1115,
      -1,    11,    -1,    10,  1116,   333,    -1,  1075,    -1,  1118,
    1129,  1119,    -1,   334,    -1,  1120,    -1,  1121,    -1,    11,
      -1,    10,  1122,   335,    -1,  1075,    -1,  1124,  1129,  1125,
      -1,   336,    -1,  1126,    -1,  1127,    -1,    11,    -1,    10,
    1128,   337,    -1,  1075,    -1,  1132,    -1,   212,     8,     6,
       8,    -1,   211,     8,     6,     8,    -1,   163,     8,     6,
       8,    -1,   164,     8,     6,     8,    -1,   165,     8,     6,
       8,    -1,   215,     8,     6,     8,    -1,   214,     8,     6,
       8,    -1,   218,     8,     6,     8,    -1,   217,     8,     6,
       8,    -1,   241,     8,     6,     8,    -1,   238,     8,     6,
       8,    -1,   239,     8,     6,     8,    -1,   240,     8,     6,
       8,    -1,  1144,    -1,  1145,    -1,   166,    -1,   167,     3,
       8,    -1,  1147,    -1,  1148,    -1,   186,    -1,   187,     3,
       8,    -1,  1150,    -1,  1151,    -1,   168,    -1,   169,     3,
       8,    -1,  1153,    -1,  1154,    -1,   176,    -1,   177,     3,
       8,    -1,  1156,    -1,  1157,    -1,   172,    -1,   173,     3,
       8,    -1,  1159,    -1,  1160,    -1,   188,    -1,   189,     3,
       8,    -1,  1162,    -1,  1163,    -1,   170,    -1,   171,     3,
       8,    -1,  1165,    -1,  1166,    -1,   174,    -1,   175,     3,
       8,    -1,  1168,    -1,  1169,    -1,   180,    -1,   181,     3,
       8,    -1,  1171,    -1,  1172,    -1,   182,    -1,   183,     3,
       8,    -1,  1174,    -1,  1175,    -1,   190,    -1,   191,     3,
       8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   342,   342,   343,   345,   352,   362,   362,   364,   364,
     366,   368,   370,   379,   380,   383,   391,   391,   404,   404,
     406,   422,   422,   424,   424,   426,   428,   430,   430,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     447,   449,   458,   458,   460,   460,   462,   464,   474,   476,
     483,   483,   485,   485,   487,   489,   499,   501,   507,   507,
     509,   509,   511,   513,   523,   530,   538,   539,   546,   552,
     552,   554,   554,   556,   558,   566,   568,   574,   574,   576,
     576,   578,   580,   589,   591,   598,   598,   600,   600,   602,
     604,   614,   616,   623,   623,   625,   625,   627,   629,   639,
     641,   647,   647,   649,   649,   651,   653,   663,   665,   671,
     671,   673,   673,   675,   677,   687,   694,   703,   704,   710,
     717,   717,   719,   719,   721,   723,   731,   737,   747,   755,
     760,   766,   766,   768,   770,   774,   774,   776,   787,   806,
     812,   812,   815,   819,   820,   823,   823,   871,   871,   873,
     883,   883,   885,   885,   887,   889,   891,   891,   894,   895,
     896,   897,   898,   902,   904,   914,   916,   916,   919,   920,
     923,   925,   933,   935,   945,   947,   947,   950,   951,   954,
     956,   965,   967,   977,   979,   979,   982,   983,   986,   988,
     997,   999,  1009,  1010,  1012,  1014,  1025,  1031,  1041,  1049,
    1053,  1058,  1058,  1060,  1062,  1066,  1066,  1068,  1123,  1123,
    1125,  1132,  1132,  1134,  1134,  1136,  1138,  1140,  1140,  1143,
    1144,  1148,  1150,  1156,  1156,  1158,  1158,  1160,  1162,  1173,
    1179,  1189,  1197,  1201,  1206,  1206,  1208,  1210,  1214,  1214,
    1216,  1269,  1269,  1271,  1291,  1291,  1293,  1293,  1295,  1297,
    1299,  1299,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,
    1310,  1311,  1312,  1313,  1314,  1315,  1316,  1321,  1327,  1337,
    1338,  1340,  1340,  1342,  1342,  1344,  1346,  1348,  1355,  1357,
    1363,  1363,  1365,  1365,  1367,  1369,  1379,  1390,  1400,  1402,
    1402,  1404,  1404,  1406,  1415,  1415,  1417,  1438,  1449,  1459,
    1459,  1461,  1461,  1463,  1474,  1485,  1495,  1495,  1497,  1497,
    1499,  1510,  1521,  1531,  1531,  1533,  1533,  1535,  1546,  1557,
    1567,  1567,  1569,  1569,  1571,  1582,  1598,  1608,  1610,  1610,
    1612,  1612,  1614,  1623,  1623,  1625,  1629,  1645,  1655,  1657,
    1657,  1659,  1659,  1661,  1670,  1670,  1672,  1676,  1692,  1702,
    1704,  1704,  1706,  1706,  1708,  1717,  1717,  1719,  1723,  1739,
    1749,  1751,  1751,  1753,  1753,  1755,  1764,  1764,  1766,  1770,
    1781,  1791,  1793,  1793,  1795,  1795,  1797,  1808,  1819,  1829,
    1831,  1831,  1833,  1833,  1835,  1861,  1872,  1882,  1884,  1884,
    1886,  1886,  1888,  1897,  1897,  1899,  1920,  1926,  1936,  1944,
    1948,  1953,  1953,  1955,  1957,  1961,  1961,  1963,  2017,  2017,
    2019,  2027,  2029,  2029,  2032,  2039,  2046,  2055,  2055,  2057,
    2059,  2061,  2068,  2068,  2070,  2076,  2083,  2083,  2088,  2088,
    2090,  2092,  2094,  2104,  2104,  2119,  2124,  2135,  2143,  2152,
    2152,  2154,  2156,  2158,  2158,  2161,  2166,  2180,  2186,  2186,
    2189,  2203,  2208,  2216,  2216,  2220,  2220,  2235,  2240,  2251,
    2259,  2268,  2268,  2270,  2272,  2274,  2274,  2277,  2283,  2298,
    2304,  2304,  2307,  2319,  2324,  2330,  2330,  2334,  2334,  2336,
    2341,  2341,  2343,  2345,  2347,  2350,  2350,  2388,  2388,  2424,
    2424,  2459,  2459,  2494,  2494,  2529,  2529,  2564,  2564,  2599,
    2599,  2615,  2620,  2631,  2639,  2648,  2648,  2650,  2652,  2658,
    2658,  2660,  2665,  2681,  2687,  2687,  2690,  2702,  2707,  2715,
    2715,  2719,  2719,  2725,  2731,  2739,  2747,  2755,  2755,  2757,
    2759,  2759,  2761,  2780,  2796,  2804,  2804,  2807,  2808,  2817,
    2820,  2820,  2822,  2822,  2824,  2829,  2829,  2831,  2836,  2868,
    2888,  2888,  2891,  2895,  2899,  2900,  2901,  2902,  2903,  2904,
    2905,  2906,  2909,  2909,  2911,  2911,  2913,  2915,  2915,  2917,
    2917,  2920,  2935,  2955,  2957,  2957,  2960,  2970,  2971,  2972,
    2973,  2976,  2978,  2978,  2986,  2986,  2988,  2994,  3001,  3001,
    3006,  3006,  3008,  3010,  3012,  3021,  3021,  3037,  3043,  3055,
    3063,  3072,  3072,  3074,  3076,  3078,  3078,  3081,  3086,  3101,
    3103,  3103,  3106,  3117,  3121,  3128,  3128,  3131,  3131,  3149,
    3154,  3168,  3176,  3185,  3185,  3187,  3189,  3191,  3191,  3194,
    3199,  3217,  3219,  3219,  3222,  3233,  3237,  3243,  3250,  3250,
    3254,  3254,  3256,  3261,  3261,  3263,  3265,  3267,  3270,  3270,
    3304,  3304,  3338,  3338,  3372,  3372,  3406,  3406,  3440,  3440,
    3476,  3476,  3511,  3511,  3513,  3519,  3550,  3571,  3571,  3574,
    3578,  3582,  3583,  3584,  3585,  3586,  3587,  3588,  3589,  3592,
    3592,  3594,  3594,  3596,  3598,  3598,  3600,  3600,  3603,  3618,
    3640,  3642,  3642,  3645,  3655,  3656,  3657,  3658,  3661,  3663,
    3663,  3671,  3671,  3673,  3679,  3686,  3686,  3691,  3691,  3693,
    3695,  3697,  3706,  3706,  3722,  3727,  3738,  3746,  3755,  3755,
    3757,  3759,  3761,  3761,  3764,  3769,  3785,  3792,  3792,  3795,
    3806,  3810,  3817,  3817,  3821,  3821,  3839,  3844,  3857,  3865,
    3874,  3874,  3876,  3878,  3880,  3880,  3883,  3888,  3907,  3914,
    3914,  3917,  3928,  3932,  3936,  3942,  3942,  3946,  3946,  3948,
    3953,  3953,  3955,  3957,  3959,  3962,  3962,  3996,  3996,  4031,
    4031,  4067,  4067,  4102,  4102,  4137,  4137,  4172,  4172,  4207,
    4207,  4209,  4215,  4246,  4266,  4266,  4269,  4273,  4277,  4278,
    4279,  4280,  4281,  4282,  4283,  4284,  4287,  4287,  4289,  4289,
    4291,  4293,  4293,  4295,  4295,  4298,  4313,  4333,  4335,  4335,
    4338,  4350,  4351,  4352,  4353,  4356,  4358,  4358,  4366,  4366,
    4372,  4374,  4382,  4390,  4399,  4401,  4403,  4403,  4407,  4427,
    4445,  4451,  4451,  4454,  4455,  4456,  4457,  4458,  4459,  4460,
    4467,  4475,  4484,  4484,  4486,  4488,  4490,  4490,  4492,  4499,
    4510,  4512,  4512,  4514,  4516,  4533,  4533,  4535,  4557,  4574,
    4586,  4591,  4591,  4594,  4595,  4596,  4598,  4607,  4616,  4625,
    4625,  4709,  4716,  4738,  4745,  4745,  4747,  4752,  4759,  4765,
    4765,  4767,  4772,  4836,  4842,  4844,  4870,  4877,  4877,  4879,
    4884,  4891,  4897,  4897,  4899,  4902,  5014,  5042,  5048,  5054,
    5060,  5066,  5080,  5090,  5101,  5137,  5137,  5139,  5158,  5175,
    5183,  5183,  5186,  5194,  5195,  5199,  5199,  5201,  5204,  5206,
    5210,  5211,  5218,  5220,  5220,  5222,  5223,  5224,  5225,  5260,
    5262,  5276,  5276,  5278,  5280,  5282,  5284,  5284,  5287,  5288,
    5289,  5290,  5291,  5293,  5301,  5301,  5303,  5303,  5305,  5311,
    5319,  5319,  5321,  5321,  5323,  5329,  5337,  5337,  5339,  5339,
    5341,  5347,  5355,  5355,  5357,  5357,  5359,  5365,  5373,  5373,
    5375,  5375,  5377,  5389,  5397,  5399,  5399,  5401,  5403,  5412,
    5414,  5414,  5416,  5416,  5418,  5434,  5437,  5437,  5439,  5439,
    5442,  5717,  5719,  5724,  5724,  5726,  5728,  5730,  5733,  5735,
    5740,  5740,  5742,  5744,  5746,  5749,  5751,  5756,  5756,  5758,
    5760,  5762,  5765,  5767,  5772,  5772,  5774,  5776,  5778,  5781,
    5783,  5788,  5788,  5790,  5792,  5794,  5797,  5799,  5804,  5804,
    5806,  5808,  5810,  5813,  5815,  5820,  5820,  5822,  5824,  5826,
    5829,  7281,  7303,  7314,  7325,  7336,  7404,  7426,  7459,  7481,
    7495,  7614,  7624,  7661,  7787,  7787,  7789,  7796,  7805,  7805,
    7807,  7814,  7823,  7823,  7825,  7832,  7841,  7841,  7843,  7850,
    7933,  7933,  7935,  7942,  7951,  7951,  7953,  7960,  8012,  8012,
    8014,  8021,  8048,  8048,  8050,  8057,  8066,  8066,  8068,  8075,
    8084,  8084,  8088,  8096,  8123,  8123,  8125,  8132
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
  "MATRIXINVERSEEND", "EMPTYINCLUDEDIAGONALATT", "INCLUDEDIAGONALATT",
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
     705,   706,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   456,   457,   457,   458,   459,   460,   460,   461,   461,
     462,   463,   464,   465,   465,   466,   467,   467,   468,   468,
     469,   470,   470,   471,   471,   472,   473,   474,   474,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     476,   477,   478,   478,   479,   479,   480,   481,   482,   483,
     484,   484,   485,   485,   486,   487,   488,   489,   490,   490,
     491,   491,   492,   493,   494,   495,   496,   496,   497,   498,
     498,   499,   499,   500,   501,   502,   503,   504,   504,   505,
     505,   506,   507,   508,   509,   510,   510,   511,   511,   512,
     513,   514,   515,   516,   516,   517,   517,   518,   519,   520,
     521,   522,   522,   523,   523,   524,   525,   526,   527,   528,
     528,   529,   529,   530,   531,   532,   533,   534,   534,   535,
     536,   536,   537,   537,   538,   539,   540,   541,   542,   543,
     543,   544,   544,   545,   546,   547,   547,   548,   549,   550,
     551,   551,   552,   552,   552,   553,   553,   554,   554,   555,
     556,   556,   557,   557,   558,   559,   560,   560,   561,   561,
     561,   561,   561,   562,   563,   564,   565,   565,   566,   566,
     567,   568,   569,   570,   571,   572,   572,   573,   573,   574,
     575,   576,   577,   578,   579,   579,   580,   580,   581,   582,
     583,   584,   585,   585,   586,   587,   588,   589,   590,   591,
     591,   592,   592,   593,   594,   595,   595,   596,   597,   597,
     598,   599,   599,   600,   600,   601,   602,   603,   603,   604,
     604,   605,   606,   607,   607,   608,   608,   609,   610,   611,
     612,   613,   614,   614,   615,   615,   616,   617,   618,   618,
     619,   620,   620,   621,   622,   622,   623,   623,   624,   625,
     626,   626,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   628,   629,   630,
     630,   631,   631,   632,   632,   633,   634,   635,   636,   637,
     638,   638,   639,   639,   640,   641,   642,   643,   644,   645,
     645,   646,   646,   647,   648,   648,   649,   650,   651,   652,
     652,   653,   653,   654,   655,   656,   657,   657,   658,   658,
     659,   660,   661,   662,   662,   663,   663,   664,   665,   666,
     667,   667,   668,   668,   669,   670,   671,   672,   673,   673,
     674,   674,   675,   676,   676,   677,   678,   679,   680,   681,
     681,   682,   682,   683,   684,   684,   685,   686,   687,   688,
     689,   689,   690,   690,   691,   692,   692,   693,   694,   695,
     696,   697,   697,   698,   698,   699,   700,   700,   701,   702,
     703,   704,   705,   705,   706,   706,   707,   708,   709,   710,
     711,   711,   712,   712,   713,   714,   715,   716,   717,   717,
     718,   718,   719,   720,   720,   721,   722,   723,   724,   725,
     725,   726,   726,   727,   728,   729,   729,   730,   731,   731,
     732,   733,   734,   734,   735,   735,   735,   736,   736,   737,
     738,   739,   740,   740,   741,   742,   743,   743,   744,   744,
     745,   746,   747,   748,   748,   749,   750,   751,   751,   752,
     752,   753,   754,   755,   755,   756,   757,   758,   759,   759,
     760,   760,   760,   761,   761,   762,   762,   763,   764,   765,
     765,   766,   766,   767,   768,   769,   769,   770,   771,   772,
     773,   773,   774,   774,   774,   775,   775,   776,   776,   777,
     778,   778,   779,   780,   781,   782,   782,   783,   783,   784,
     784,   785,   785,   786,   786,   787,   787,   788,   788,   789,
     789,   790,   791,   792,   792,   793,   793,   794,   795,   796,
     796,   797,   798,   799,   800,   800,   801,   801,   801,   802,
     802,   803,   803,   804,   805,   806,   806,   807,   807,   808,
     809,   809,   810,   811,   812,   813,   813,   814,   814,   814,
     815,   815,   816,   816,   817,   818,   818,   819,   820,   821,
     822,   822,   823,   823,   823,   823,   823,   823,   823,   823,
     823,   823,   824,   824,   825,   825,   826,   827,   827,   828,
     828,   829,   830,   831,   832,   832,   833,   833,   833,   833,
     833,   834,   835,   835,   836,   836,   837,   838,   839,   839,
     840,   840,   841,   842,   843,   844,   844,   845,   846,   847,
     847,   848,   848,   849,   850,   851,   851,   852,   853,   854,
     855,   855,   856,   856,   856,   857,   857,   858,   858,   859,
     860,   861,   861,   862,   862,   863,   864,   865,   865,   866,
     867,   868,   869,   869,   870,   870,   870,   870,   871,   871,
     872,   872,   873,   874,   874,   875,   876,   877,   878,   878,
     879,   879,   880,   880,   881,   881,   882,   882,   883,   883,
     884,   884,   885,   885,   886,   887,   888,   889,   889,   890,
     890,   890,   890,   890,   890,   890,   890,   890,   890,   891,
     891,   892,   892,   893,   894,   894,   895,   895,   896,   897,
     898,   899,   899,   900,   900,   900,   900,   900,   901,   902,
     902,   903,   903,   904,   905,   906,   906,   907,   907,   908,
     909,   910,   911,   911,   912,   913,   914,   914,   915,   915,
     916,   917,   918,   918,   919,   920,   921,   922,   922,   923,
     923,   923,   924,   924,   925,   925,   926,   927,   928,   928,
     929,   929,   930,   931,   932,   932,   933,   934,   935,   936,
     936,   937,   937,   937,   937,   938,   938,   939,   939,   940,
     941,   941,   942,   943,   944,   945,   945,   946,   946,   947,
     947,   948,   948,   949,   949,   950,   950,   951,   951,   952,
     952,   953,   954,   955,   956,   956,   957,   957,   957,   957,
     957,   957,   957,   957,   957,   957,   958,   958,   959,   959,
     960,   961,   961,   962,   962,   963,   964,   965,   966,   966,
     967,   967,   967,   967,   967,   968,   969,   969,   970,   970,
     971,   972,   973,   973,   974,   975,   976,   976,   977,   978,
     979,   980,   980,   981,   981,   981,   981,   981,   981,   981,
     982,   982,   983,   983,   984,   985,   986,   986,   987,   988,
     988,   989,   989,   990,   991,   992,   992,   993,   994,   995,
     996,   997,   997,   998,   998,   998,   999,  1000,  1001,  1002,
    1002,  1003,  1004,  1005,  1006,  1006,  1007,  1008,  1009,  1010,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1017,  1018,
    1019,  1020,  1021,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1033,  1034,  1035,  1036,
    1037,  1037,  1038,  1038,  1038,  1039,  1039,  1040,  1041,  1042,
    1043,  1043,  1044,  1045,  1045,  1046,  1046,  1046,  1046,  1047,
    1048,  1049,  1049,  1050,  1051,  1052,  1053,  1053,  1054,  1054,
    1054,  1054,  1054,  1055,  1056,  1056,  1057,  1057,  1058,  1059,
    1060,  1060,  1061,  1061,  1062,  1063,  1064,  1064,  1065,  1065,
    1066,  1067,  1068,  1068,  1069,  1069,  1070,  1071,  1072,  1072,
    1073,  1073,  1074,  1075,  1075,  1076,  1076,  1077,  1078,  1079,
    1080,  1080,  1081,  1081,  1082,  1083,  1084,  1084,  1085,  1085,
    1086,  1087,  1088,  1089,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1107,  1108,  1109,  1110,  1111,
    1112,  1113,  1113,  1114,  1115,  1116,  1117,  1118,  1119,  1119,
    1120,  1121,  1122,  1123,  1124,  1125,  1125,  1126,  1127,  1128,
    1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1138,
    1139,  1140,  1141,  1142,  1143,  1143,  1144,  1145,  1146,  1146,
    1147,  1148,  1149,  1149,  1150,  1151,  1152,  1152,  1153,  1154,
    1155,  1155,  1156,  1157,  1158,  1158,  1159,  1160,  1161,  1161,
    1162,  1163,  1164,  1164,  1165,  1166,  1167,  1167,  1168,  1169,
    1170,  1170,  1171,  1172,  1173,  1173,  1174,  1175
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
   -1236,   -65,   401,   -28, -1236, -1236, -1236, -1236,   135,   425,
     230, -1236,   -18,   417,   -21, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,    11,   -23, -1236, -1236,   421, -1236,   423, -1236,   426,
   -1236,   253, -1236,   430, -1236,   432, -1236,   436, -1236,   438,
   -1236,   459, -1236,   302, -1236,   285, -1236,   331, -1236, -1236,
     335, -1236, -1236,   339, -1236, -1236,   343, -1236, -1236,   348,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,    34,   461,   -31, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,    45,    55,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   249, -1236,
     285, -1236, -1236,    10, -1236, -1236, -1236, -1236,     9, -1236,
   -1236, -1236, -1236,     8, -1236, -1236, -1236, -1236,   366,   465,
   -1236,     7, -1236, -1236, -1236, -1236,   129, -1236, -1236, -1236,
   -1236,   154, -1236, -1236, -1236, -1236,   140, -1236, -1236, -1236,
   -1236,   145, -1236, -1236, -1236, -1236,   373,   467, -1236, -1236,
     469, -1236,   252,   250,   248,   258,   244, -1236, -1236, -1236,
     -30, -1236, -1236, -1236, -1236, -1236, -1236, -1236,    71,    76,
   -1236, -1236,   473, -1236,   285, -1236, -1236,   382,   178,   404,
     178,   412,   178, -1236,   435,   444, -1236, -1236, -1236,   475,
   -1236, -1236, -1236,    96, -1236, -1236,   115, -1236, -1236,   163,
     503,   132, -1236, -1236, -1236, -1236, -1236, -1236,   205, -1236,
   -1236,   507, -1236, -1236,   509, -1236, -1236,   515, -1236, -1236,
     517,   607,   123, -1236, -1236, -1236, -1236,   685,    -2,   -82,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   479,
     143, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   371,   298, -1236,
   -1236,   311, -1236,   483, -1236,   662, -1236,   664, -1236,   664,
   -1236,   664, -1236,   664, -1236,   661, -1236,   661, -1236,   661,
   -1236,   661, -1236,   664, -1236,   664, -1236,   666, -1236,   285,
   -1236, -1236,   125, -1236, -1236, -1236, -1236,   485, -1236,   491,
   -1236, -1236,   692, -1236, -1236, -1236, -1236, -1236,   491, -1236,
   -1236, -1236, -1236,   491, -1236, -1236, -1236, -1236,   689,   693,
   -1236,   -81, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236,   654, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   648, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   579,   355, -1236, -1236,   392, -1236, -1236, -1236, -1236,
     697,   698,   699, -1236, -1236, -1236, -1236, -1236, -1236,   489,
   -1236,   114, -1236, -1236, -1236, -1236,   700,   494, -1236,   701,
     514,   516,   520,   522,   702,   526, -1236,   528, -1236,   530,
   -1236,   536, -1236,   538, -1236,   573, -1236,   703,   575, -1236,
     577, -1236, -1236, -1236,   649,   -80, -1236, -1236, -1236, -1236,
   -1236, -1236,   656, -1236,   706,   658, -1236,   660, -1236, -1236,
   -1236,   668, -1236, -1236,   594,   355, -1236, -1236, -1236, -1236,
   -1236, -1236,   581,   103, -1236,   394,   411,   680,   715,   716,
     717,   113, -1236, -1236, -1236, -1236, -1236, -1236,   669,   718,
     -52, -1236, -1236, -1236, -1236,   719,    79, -1236, -1236, -1236,
   -1236,   142, -1236, -1236, -1236, -1236,    74, -1236, -1236, -1236,
   -1236,   213, -1236, -1236, -1236, -1236,   720,   139, -1236, -1236,
   -1236, -1236,    80, -1236, -1236, -1236, -1236,    67, -1236, -1236,
   -1236, -1236,    68, -1236, -1236, -1236, -1236,   151, -1236, -1236,
   -1236, -1236,    72, -1236, -1236, -1236, -1236,   721,   405, -1236,
   -1236, -1236, -1236,   -78, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   604,   355, -1236, -1236, -1236, -1236, -1236, -1236,   581,
   -1236, -1236,   385, -1236, -1236, -1236,   726, -1236,   728, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   429,
     704, -1236,   583, -1236, -1236,   727,   730,   731, -1236,   670,
   -1236, -1236, -1236,   733, -1236,   724,   -43, -1236,   734,   735,
   -1236,   207, -1236, -1236,   240, -1236,   228, -1236,   238,   736,
   -1236, -1236,   167, -1236, -1236, -1236, -1236,    84, -1236, -1236,
   -1236,    75, -1236, -1236, -1236,    73, -1236, -1236, -1236,   208,
   -1236,   206,   738, -1236,   737,   499, -1236, -1236, -1236,   624,
     355, -1236,   581, -1236, -1236, -1236, -1236,   741,   742, -1236,
     632,   722, -1236,   587, -1236, -1236,   746,   644, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   749, -1236, -1236,
   -1236,   750, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
     589,   396, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   751, -1236, -1236,   581, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236,   723, -1236,   591, -1236, -1236,   752,   646, -1236,
   -1236, -1236, -1236, -1236, -1236,   443,   671,   542,   418,   690,
     691, -1236, -1236,   761,   763,   764, -1236, -1236, -1236, -1236,
     672, -1236, -1236,   593, -1236,   762,   674, -1236, -1236, -1236,
   -1236, -1236, -1236,   460,   678,   556, -1236, -1236, -1236,   676,
     542,   765,   595, -1236, -1236, -1236, -1236,   766,   767,   768,
   -1236,   771, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   476,
     681,   566, -1236, -1236, -1236,   682,   556,   772,   597, -1236,
   -1236,   683,   601,   603, -1236,   776,   -50, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,   497, -1236, -1236, -1236,   684,
     566,   775,   609, -1236, -1236, -1236,   611,   613, -1236,   778,
     -33, -1236, -1236, -1236, -1236, -1236,   686,   542,   456, -1236,
   -1236, -1236, -1236,   -54, -1236, -1236, -1236, -1236,   782, -1236,
   -1236,   694,   482, -1236, -1236, -1236, -1236, -1236, -1236,   407,
   -1236, -1236,   615,   617, -1236,   789,   -35, -1236, -1236, -1236,
   -1236,   450,   456, -1236, -1236, -1236, -1236,   -24, -1236, -1236,
   -1236, -1236,   791, -1236, -1236,   688,   495, -1236, -1236, -1236,
   -1236,   757,   619, -1236, -1236,   705,   477, -1236,   639, -1236,
   -1236,   708,   496, -1236, -1236, -1236, -1236, -1236,   621,   -51,
     796, -1236,   802, -1236,   804, -1236,   805,   623,   407, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236,   466,   456, -1236, -1236, -1236, -1236,   -44,
   -1236, -1236, -1236, -1236,   803, -1236, -1236,   707,   511, -1236,
   -1236, -1236, -1236, -1236,   710,   477, -1236, -1236, -1236,   711,
     510, -1236, -1236, -1236, -1236, -1236,   625,   -51,   471,   807,
     627,   -40, -1236, -1236, -1236, -1236, -1236, -1236,   490, -1236,
     639,   811,   629, -1236, -1236, -1236,   631,   -51,   513, -1236,
   -1236,   812, -1236, -1236, -1236, -1236,   820,   819,   821,   822,
      86, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   732,
     477, -1236, -1236, -1236,   713,   533, -1236, -1236, -1236, -1236,
   -1236,   633,   -51,   635,   346, -1236,   490, -1236, -1236, -1236,
     637,    51,   521, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236,   826,   541, -1236, -1236, -1236, -1236, -1236, -1236,
     739,   529, -1236, -1236, -1236,   518, -1236,   639,   641,   832,
     687, -1236, -1236, -1236, -1236,   532, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236,   834,   833, -1236, -1236, -1236, -1236, -1236,
     839, -1236,   725,   214, -1236, -1236, -1236, -1236,   643,   233,
   -1236,   490, -1236, -1236, -1236,   645,    66,   543, -1236, -1236,
   -1236, -1236, -1236, -1236,   -99, -1236, -1236, -1236, -1236,   841,
   -1236,   847, -1236,   850, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   518,
   -1236,   547, -1236, -1236, -1236, -1236,   852,   853, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
     647,   291,   849, -1236, -1236,   551, -1236, -1236, -1236, -1236,
     651,   -51, -1236,   527, -1236,   639,   653,   687, -1236, -1236,
   -1236, -1236,   854,   620, -1236,   712, -1236,   535, -1236,   855,
   -1236, -1236,   709, -1236, -1236,   -97, -1236, -1236, -1236, -1236,
   -1236,   857, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,   518, -1236,   555, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   523,
     558, -1236, -1236,   714, -1236, -1236,   861,   863,   864,   527,
   -1236, -1236, -1236, -1236,   -84, -1236, -1236, -1236, -1236, -1236,
     870, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   655,    56,   563,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   544, -1236,   639,
     657,   687, -1236, -1236, -1236, -1236, -1236,   548, -1236,   869,
     659, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   534,
     578, -1236, -1236,   714,   871,   527, -1236, -1236,   491,   491,
   -1236, -1236,   663,    59, -1236,   665,    46,   874, -1236, -1236,
     544, -1236, -1236, -1236, -1236, -1236,   537,   576, -1236, -1236,
     714,   875,   -58, -1236, -1236, -1236, -1236, -1236,   877, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   552, -1236,
     639,   667,   687, -1236, -1236, -1236, -1236, -1236,   560, -1236,
     881,    95, -1236, -1236, -1236, -1236,   880,   440, -1236, -1236,
     673,    59, -1236,   544, -1236, -1236, -1236,   586, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   687, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   552, -1236, -1236,
   -1236,   675,    59, -1236, -1236,   -56,   888,   491, -1236, -1236,
   -1236,   639,   677,   687, -1236, -1236, -1236, -1236, -1236,   570,
   -1236,   889,   740, -1236,   890, -1236,   891,   892, -1236, -1236,
   -1236,   598, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   552, -1236, -1236, -1236, -1236,   747, -1236, -1236, -1236,
     596, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236,   896,   679,   687, -1236, -1236, -1236, -1236, -1236,
     565, -1236, -1236, -1236,   754,   899,   900, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236,   687, -1236, -1236, -1236, -1236, -1236,
     574, -1236, -1236,   902,   903, -1236,   580, -1236, -1236, -1236,
   -1236
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   872, -1236,
     893, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   851,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236,   512,  -338,  -411, -1236, -1236,  -496, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,   777, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
     445, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   696, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236,   347, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   616, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236,   305, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236,   294, -1236, -1236, -1236, -1236, -1236, -1236, -1236,   288,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236,   286, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,   283, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236,   274, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236,   270, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
      81, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236,    29, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
    -400, -1041, -1236, -1236, -1236, -1236, -1236, -1236, -1236, -1236,
   -1236, -1236, -1236, -1236,  -221, -1236, -1236, -1236, -1236, -1236,
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
     340,   303,   349,   304,    33,    34,   816,  1109,   287,   911,
     912,   233,   234,   913,   914,   585,   586,   915,   916,  1110,
    1111,    44,    45,  1438,   358,   587,   588,   233,   234,  1190,
    1191,   305,   363,   855,   743,   744,   745,   127,   128,   994,
     995,   153,   154,   158,   159,   376,   163,   164,   368,  1463,
     171,   172,   176,   177,  1457,   821,   181,   182,   186,   187,
     394,   395,   396,   397,   369,  1109,   377,   911,   912,   233,
     234,   913,   914,   585,   586,   915,   916,  1110,  1111,   191,
     192,   210,   211,   587,   588,   251,   252,   272,   273,   279,
     280,  1249,  1250,   342,   343,   371,   372,  1037,  1038,   405,
     406,   351,   352,   421,   422,   455,   456,   460,   461,   491,
     492,   653,   654,  1345,   500,   501,   378,  1070,  1071,   771,
    1109,   379,   911,   912,   233,   234,   913,   914,   585,   586,
     915,   916,  1110,  1111,   506,   507,   511,   512,   587,   588,
     516,   517,   521,   522,  1112,  1113,   527,   528,   532,   533,
     537,   538,  1102,  1103,  1122,  1128,   542,   543,   547,   548,
     383,  1148,    87,   384,    88,    89,    90,   385,    91,    92,
      93,   797,    94,    95,    96,   386,    97,    98,    99,   387,
     100,   101,   910,   911,   912,   233,   234,   913,   914,   585,
     586,   915,   916,   552,   553,   558,   559,   563,   564,   587,
     588,   582,   583,   677,   678,   712,   654,   728,   729,   740,
     741,   756,   757,   782,   783,   806,   807,   830,   831,  1201,
    1204,   838,   839,   843,   844,   388,  1224,   856,   857,   866,
     867,   872,   873,   877,   878,   934,   935,   939,   940,   971,
     972,   988,   989,  1000,  1001,  1032,  1033,  1043,  1044,  1060,
    1061,  1065,  1066,  1097,  1098,  1104,  1105,  1131,  1132,  1153,
    1154,  1167,  1168,  1185,  1186,  1207,  1208,  1244,  1245,  1265,
    1154,  1269,  1270,  1281,  1282,  1332,  1333,  1352,  1353,  1361,
    1362,  1257,  1260,  1377,  1378,  1387,  1388,  1413,  1414,  1426,
    1427,  1274,  1275,  1431,  1432,  1450,  1451,  1464,  1465,  1484,
    1485,   392,   417,   426,   434,   464,   429,   469,   477,   470,
     447,   400,   478,   480,   484,   488,   489,   490,   499,   505,
     526,   557,   574,   568,   575,   601,   576,   597,   580,   598,
     577,   605,   606,   607,   613,   618,   629,   652,   663,   667,
     578,   668,   666,   669,   687,   682,   685,   612,   683,   684,
     672,   686,   690,   734,   697,   691,   710,   711,   715,   718,
     719,   720,   733,   738,   739,   750,   767,   762,   761,   723,
     771,   752,   775,   774,   777,   776,   778,   779,   787,   793,
     780,   797,   768,   805,   811,   812,   813,   814,   821,   800,
     829,   817,   848,   865,   882,   824,   894,   860,   835,   788,
     905,   794,   850,   889,   906,   944,   951,   969,   818,   963,
     964,   884,   981,   977,   996,   997,   900,   998,   999,   976,
     984,  1018,  1006,   946,  1025,  1042,   958,  1039,  1054,  1059,
    1073,  1308,  1309,  1019,  1072,  1028,  1074,  1075,  1149,  1076,
    1077,  1093,  1152,  1385,  1386,  1013,  1090,  1395,  1172,  1049,
    1179,  1180,  1162,  1178,  1181,  1158,  1225,  1183,  1173,  1236,
    1237,  1322,  1323,  1238,  1241,  1242,  1243,  1264,  1307,  1276,
    1304,  1289,  1288,  1295,  1227,  1291,  1294,  1317,  1296,  1226,
    1310,  1318,  1319,  1331,  1346,  1359,  1118,  1360,  1347,  1372,
    1297,  1368,  1396,  1403,  1399,  1407,  1324,  1421,  1408,  1420,
    1424,  1439,  1440,  1445,  1461,  1471,  1474,  1472,  1491,  1475,
    1476,  1477,  1473,  1480,  1483,  1493,  1494,  1481,  1492,  1497,
    1498,  1499,   123,   152,   481,   341,   226,  1500,    40,   664,
     581,   689,  1458,  1459,   418,   703,   699,   705,   707,   713,
     716,   985,  1405,   907,  1266,  1400,   965,  1311,  1029,  1020,
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
     319,    93,    10,    95,    10,    11,   787,   164,   140,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,    10,    11,  1371,    10,   182,   183,   168,   169,   186,
     187,   123,    10,   814,    28,    29,    30,    10,    11,   909,
     909,    10,    11,    10,    11,   339,    10,    11,     3,  1411,
      10,    11,    10,    11,  1402,   212,    10,    11,    10,    11,
     452,   453,   454,   455,    10,   164,   341,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,    10,
      11,    10,    11,   182,   183,    10,    11,    10,    11,    10,
      11,   190,   191,    10,    11,    10,    11,   967,   967,    10,
      11,   180,   181,    10,    11,    10,    11,     6,     7,    10,
      11,    96,    97,  1268,    10,    11,   343,   987,   987,   218,
     164,     8,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,    10,    11,    10,    11,   182,   183,
      10,    11,    10,    11,   188,   189,    10,    11,    10,    11,
      10,    11,  1022,  1022,  1024,  1024,    10,    11,    10,    11,
     345,  1031,   127,    46,   129,   130,   131,    48,   133,   134,
     135,   215,   137,   138,   139,    50,   141,   142,   143,    52,
     145,   146,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    10,    11,    10,    11,    10,    11,   182,
     183,    10,    11,    10,    11,    96,    97,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,  1089,
    1089,    10,    11,    10,    11,     8,  1096,   120,   121,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   108,
     109,    10,    11,    10,    11,    10,    11,    10,    11,   108,
     109,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,  1151,  1151,    10,    11,    10,    11,    10,    11,   239,
     240,  1161,  1161,    10,    11,    10,    11,    10,    11,    10,
      11,     6,   321,    31,    33,     3,    32,     8,    44,     6,
      34,   346,    54,   124,   312,     8,     8,     8,     8,     8,
       8,     8,    56,    64,     8,    35,    58,   323,   124,   308,
      60,     6,     6,     6,     6,     6,     6,     6,   124,     3,
      62,     3,   347,   304,    10,     8,    66,    68,     8,     8,
      36,     8,     8,    99,     8,    10,     8,    10,   124,     8,
       8,   119,     6,     4,     4,     4,   313,   111,     6,    37,
     218,    38,    72,   345,     3,    74,     3,     3,     6,   309,
      98,   215,   101,     8,     8,     8,     8,     6,   212,   103,
       8,   305,     6,     8,     6,   103,   330,   103,   105,   115,
       8,   113,   310,   107,   100,     6,   346,    40,   117,     8,
     112,   306,   163,   326,     8,     3,   310,     3,     3,   104,
     102,     8,   346,   302,   104,     8,   306,   346,   328,     8,
       8,  1212,  1213,   116,   311,   114,     6,     8,   307,     8,
       8,   118,     6,  1313,  1313,   302,   104,  1316,     6,   310,
       6,     8,   324,   311,     5,   106,   303,   122,   161,     8,
       3,  1242,  1243,     3,   307,     3,     3,     8,   303,   332,
       3,   241,     8,     8,   306,   153,   331,     6,   159,   155,
     347,     8,     8,     3,   311,   327,  1024,     8,   334,     8,
     302,   347,     8,     8,   347,     8,   310,     6,   336,   329,
      10,  1371,  1371,   307,     6,   325,     6,     8,   333,     8,
       8,   303,   162,   156,     8,     6,     6,   311,   154,   335,
       8,     8,    40,    62,   402,   219,   139,   337,    25,   572,
     475,   616,  1402,  1402,   308,   637,   632,   641,   645,   655,
     660,   902,  1332,   852,  1155,  1327,   886,  1230,   960,   948,
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
       0,    12,    13,   457,   458,   459,     0,   125,   466,   467,
    1047,  1048,    14,   460,    15,   464,   465,   314,   468,   469,
      10,    11,  1049,  1050,  1051,    10,    11,   461,   462,   463,
     316,   554,   555,    10,    11,   470,   471,   472,  1052,  1053,
     466,   318,   597,   598,    10,    11,   556,   557,   558,    43,
      45,    47,    49,    51,    53,   123,   315,   338,   340,   342,
     344,   473,   474,   475,   476,   477,   482,   483,   488,   489,
     494,   495,   502,   503,   508,   509,   514,   515,   520,   521,
     526,   527,   532,   533,   540,   541,   126,   127,   129,   130,
     131,   133,   134,   135,   137,   138,   139,   141,   142,   143,
     145,   146,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,  1073,  1074,   464,   320,   620,   621,    10,    11,   599,
     600,   601,    55,    57,    59,    61,   123,   317,   559,   560,
     561,   562,   563,   569,   570,   576,   577,   583,   584,   588,
     589,   315,   475,    10,    11,   478,   479,   480,    10,    11,
     484,   485,   486,    10,    11,   490,   491,   492,    27,   496,
     497,    10,    11,   504,   505,   506,    10,    11,   510,   511,
     512,    10,    11,   516,   517,   518,    10,    11,   522,   523,
     524,    10,    11,   528,   529,   530,    26,   534,   535,    39,
     542,  1027,     5,     5,     5,     5,     5,   322,   731,   732,
      10,    11,   622,   623,   624,    63,   123,   319,   602,   603,
     604,   605,   606,   611,   612,   317,   561,   564,   565,   571,
     572,   578,   579,   168,   169,   585,  1149,  1150,  1151,   590,
    1027,     4,   339,   481,     4,   341,   487,     4,   343,   493,
       3,    10,    11,   498,   499,   500,     4,   345,   507,     4,
      46,   513,     4,    48,   519,     4,    50,   525,     4,    52,
     531,     3,    10,    11,   536,   537,   538,  1044,  1045,    10,
      11,   543,   544,   545,   128,   132,   136,   140,   144,   733,
     734,    65,    67,    69,    75,    77,    79,    81,    83,    85,
      87,    89,    91,    93,    95,   123,   321,   625,   626,   627,
     628,   629,   636,   637,   642,   643,   650,   651,   655,   656,
     660,   661,   665,   666,   670,   671,   678,   679,   686,   687,
     694,   695,   702,   703,   708,   709,   714,   715,   722,   723,
     319,   604,    10,    11,   607,   608,   609,   613,  1027,    10,
     567,   180,   181,   566,  1149,  1167,  1168,  1169,    10,   574,
     573,  1149,  1167,    10,   581,   580,  1149,  1167,     3,    10,
     586,    10,    11,   591,   592,   593,   339,   341,   343,     8,
       4,    44,   501,   345,    46,    48,    50,    52,     8,     4,
      54,   539,     6,     8,   452,   453,   454,   455,  1046,   124,
     346,   546,   547,   548,   549,    10,    11,   736,   737,   738,
     211,   214,   217,   735,  1131,  1136,  1138,   321,   627,   630,
    1167,    10,    11,   638,   639,   640,    31,   644,  1024,    32,
    1030,  1030,  1030,  1030,    33,   672,  1029,   680,  1029,   688,
    1029,   696,  1029,   704,  1030,   710,  1030,    34,   716,  1031,
     724,  1027,     4,    64,   610,    10,    11,   614,   615,   616,
       6,     7,   568,  1043,     3,   575,  1043,   582,  1043,     8,
       6,   587,   124,   549,   594,   595,   596,    44,    54,  1044,
     124,   548,   550,   551,   312,   739,   740,   741,     8,     8,
       8,    10,    11,   631,   632,   633,     4,    68,   641,     8,
      10,    11,   645,   646,   647,     8,    10,    11,   652,   653,
     654,    10,    11,   657,   658,   659,    10,    11,   662,   663,
     664,    10,    11,   667,   668,   669,     8,    10,    11,   673,
     674,   675,    10,    11,   681,   682,   683,    10,    11,   689,
     690,   691,    10,    11,   697,   698,   699,    10,    11,   705,
     706,   707,    10,    11,   711,   712,   713,     8,    10,    11,
     717,   718,   719,    10,    11,   725,   726,   727,    64,   124,
     549,   617,   618,   619,    56,     8,    58,    60,    62,   550,
     124,   596,    10,    11,   553,   172,   173,   182,   183,   552,
    1149,  1155,  1156,  1157,  1170,  1171,  1172,   323,   308,   836,
     837,    35,   742,   743,  1028,     6,     6,     6,    66,   634,
     635,  1043,    68,     6,    70,   344,   648,   649,     6,    71,
      76,   992,   993,    78,   992,    80,   992,    82,   992,     6,
      73,    88,   676,   677,   994,   995,    90,   684,   685,   994,
      94,   692,   693,   994,    92,   700,   701,   994,    86,   992,
      84,   992,     6,    96,    97,   720,   721,   124,   549,   728,
     729,   730,   550,   124,   619,   553,   347,     3,     3,   304,
     903,   904,    36,   838,   839,  1026,  1044,    10,    11,   744,
     745,   746,     8,     8,     8,    66,     8,    10,    70,   649,
       8,    10,    76,   993,    78,    80,    82,     8,    88,   677,
     996,   997,    90,   685,    94,   693,    92,   701,    86,    84,
       8,    10,    96,   721,   550,   124,   730,   553,     8,     8,
     119,   970,   971,    37,   905,   906,  1025,  1044,    10,    11,
     840,   841,   842,     6,    99,   747,   748,   749,     4,     4,
      10,    11,  1002,    28,    29,    30,   998,   999,  1000,  1001,
       4,   553,    38,   972,  1032,  1044,    10,    11,   907,   908,
     909,     6,   111,   843,   844,   845,  1044,   313,   101,   762,
     763,   218,   750,  1137,   345,    72,    74,     3,     3,     3,
      98,  1044,    10,    11,   973,   974,   975,     6,   115,   910,
     911,   912,  1044,   309,   113,   858,   859,   215,   846,  1135,
     103,   776,   777,   764,  1137,     8,    10,    11,   751,   752,
     753,     8,     8,     8,     6,   976,  1044,   305,   117,   925,
     926,   212,   913,  1130,   103,   872,   873,   860,  1135,     8,
      10,    11,   847,   848,   849,   105,   789,   790,    10,    11,
     778,   779,   780,    10,    11,   765,   766,   767,     6,   100,
     310,   754,   755,   756,   757,  1044,   120,   121,   977,   978,
     103,   939,   940,   927,  1130,     8,    10,    11,   914,   915,
     916,   885,    10,    11,   874,   875,   876,    10,    11,   861,
     862,   863,     6,   112,   306,   850,   851,   852,   853,   107,
     803,   804,   791,  1137,   330,   781,   782,  1087,  1088,   102,
     310,   768,   769,   770,   771,     8,   100,   756,   758,   759,
     165,   166,   167,   170,   171,   174,   175,   979,   980,   981,
    1134,  1143,  1144,  1145,  1149,  1155,  1161,  1162,  1163,  1164,
    1165,  1166,  1170,   952,    10,    11,   941,   942,   943,    10,
      11,   928,   929,   930,     6,   116,   302,   917,   918,   919,
     920,   346,   886,   887,   877,   878,  1087,   114,   306,   864,
     865,   866,   867,     8,   112,   852,   854,   855,   818,    40,
     805,    10,    11,   792,   793,   794,   104,   326,   783,  1093,
    1094,   163,  1129,  1132,   102,   770,   772,   773,    10,    11,
     761,   238,   760,  1140,  1155,  1170,     8,     3,     3,     3,
      10,    11,   982,   983,   984,   981,   346,   953,   954,   944,
     945,  1087,   118,   302,   931,   932,   933,   934,     8,   116,
     919,   921,   922,   888,   889,   104,   879,  1093,   114,   866,
     868,   869,    10,    11,   857,   856,  1140,  1155,  1170,   346,
     819,   820,     8,    10,    11,   806,   807,   808,   106,   310,
     795,   796,   797,   798,   328,   784,  1099,  1100,  1129,     8,
      10,    11,  1089,  1090,  1091,    10,    11,   775,   774,  1140,
    1155,  1170,   311,     8,     6,     8,     8,     8,   122,   157,
     158,   160,   985,   986,   987,   988,   989,   990,   955,   956,
     104,   946,  1093,   118,   933,   935,   936,    10,    11,   924,
     923,  1140,  1155,  1170,    10,    11,   891,   892,   893,   164,
     176,   177,   188,   189,   890,  1133,  1135,  1143,  1149,  1152,
    1153,  1154,  1155,  1158,  1159,  1160,  1161,  1164,  1170,   880,
    1099,    10,    11,   871,    16,    17,    18,    19,   870,  1005,
    1006,  1007,  1008,  1016,  1017,  1018,  1019,  1140,  1155,   307,
     821,   822,     6,   108,   109,   809,   810,   811,   106,   797,
     799,   800,   324,   785,  1105,  1106,  1129,    10,    11,  1095,
    1096,  1097,     6,   161,  1075,  1076,  1083,  1092,   311,     6,
       8,     5,   991,   122,   987,    10,    11,   958,   959,   960,
     186,   187,   957,  1130,  1133,  1143,  1146,  1147,  1148,  1149,
    1152,  1155,  1161,  1164,  1170,   947,  1099,    10,    11,   938,
      20,    21,    22,    23,   937,  1009,  1010,  1011,  1012,  1020,
    1021,  1022,  1023,  1140,  1155,   303,   155,   306,   347,   894,
     895,   896,   897,  1033,  1034,  1035,     8,     3,     3,   881,
    1105,   307,     3,     3,    10,    11,   824,   825,   826,   190,
     191,   823,  1133,  1137,  1143,  1149,  1152,  1155,  1161,  1164,
    1170,  1173,  1174,  1175,     8,   108,   810,   812,   813,    10,
      11,   802,   801,  1140,  1155,  1170,   332,   786,  1111,  1112,
    1129,    10,    11,  1101,  1102,  1103,  1075,  1098,     8,   241,
    1139,   153,  1077,  1078,   331,     8,   159,   302,   347,   961,
     962,   963,   964,  1033,     3,   948,  1105,   303,  1044,  1044,
     347,   896,   898,   899,  1034,  1036,  1037,     6,     8,     8,
     882,  1111,  1044,  1044,   310,   347,   827,   828,   829,   830,
    1033,     3,    10,    11,   815,   816,   817,    41,    42,   814,
    1003,  1004,  1013,  1014,  1015,  1137,   311,   334,   787,  1117,
    1118,  1129,    10,    11,  1107,  1108,  1109,  1075,  1104,   327,
       8,    10,    11,  1084,  1085,  1086,  1079,  1080,   347,   963,
     965,   966,     8,   949,  1111,  1043,  1043,    10,    11,   901,
     902,   900,  1005,  1016,  1140,  1155,  1170,    10,    11,  1039,
    1040,  1041,  1038,  1132,  1149,  1170,     8,   883,  1117,   347,
     829,   831,   832,     8,   110,   796,  1044,     8,   336,   788,
    1123,  1124,  1129,    10,    11,  1113,  1114,  1115,  1075,  1110,
     329,     6,     4,   162,    10,  1082,   239,   240,  1081,  1141,
    1142,    10,    11,   968,   969,   967,  1005,  1016,  1140,  1155,
    1170,   950,  1117,  1044,  1044,   307,  1042,  1075,   884,  1123,
      10,    11,   834,   835,   833,  1005,  1016,  1140,  1155,  1170,
     110,     6,  1043,  1129,    10,    11,  1119,  1120,  1121,  1075,
    1116,   325,     8,   162,     6,     8,     8,   303,   951,  1123,
     156,   311,  1044,     8,    10,    11,  1125,  1126,  1127,  1075,
    1122,   333,   154,     6,     6,  1075,  1128,   335,     8,     8,
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


