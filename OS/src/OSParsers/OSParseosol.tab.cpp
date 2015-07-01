
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
     MATRIXVARIDXATT = 488,
     MATRIXOBJIDXATT = 489,
     MATRIXCONIDXATT = 490,
     IDXATT = 491,
     INCRATT = 492,
     MULTATT = 493,
     SIZEOFATT = 494,
     COEFATT = 495,
     CONSTANTATT = 496,
     MATRICESSTART = 497,
     MATRICESEND = 498,
     MATRIXSTART = 499,
     MATRIXEND = 500,
     BASEMATRIXEND = 501,
     BASEMATRIXSTART = 502,
     BLOCKSSTART = 503,
     BLOCKSEND = 504,
     BLOCKSTART = 505,
     BLOCKEND = 506,
     COLOFFSETSTART = 507,
     COLOFFSETEND = 508,
     ROWOFFSETSTART = 509,
     ROWOFFSETEND = 510,
     ELEMENTSSTART = 511,
     ELEMENTSEND = 512,
     CONSTANTELEMENTSSTART = 513,
     CONSTANTELEMENTSEND = 514,
     VARREFERENCEELEMENTSSTART = 515,
     VARREFERENCEELEMENTSEND = 516,
     LINEARELEMENTSSTART = 517,
     LINEARELEMENTSEND = 518,
     GENERALELEMENTSSTART = 519,
     GENERALELEMENTSEND = 520,
     CONREFERENCEELEMENTSSTART = 521,
     CONREFERENCEELEMENTSEND = 522,
     OBJREFERENCEELEMENTSSTART = 523,
     OBJREFERENCEELEMENTSEND = 524,
     STRINGVALUEDELEMENTSSTART = 525,
     STRINGVALUEDELEMENTSEND = 526,
     STARTVECTORSTART = 527,
     STARTVECTOREND = 528,
     INDEXSTART = 529,
     INDEXEND = 530,
     VALUESTART = 531,
     VALUEEND = 532,
     VARIDXSTART = 533,
     VARIDXEND = 534,
     TRANSFORMATIONSTART = 535,
     TRANSFORMATIONEND = 536,
     MATRIXPROGRAMMINGSTART = 537,
     MATRIXPROGRAMMINGEND = 538,
     MATRIXVARIABLESSTART = 539,
     MATRIXVARIABLESEND = 540,
     MATRIXVARSTART = 541,
     MATRIXVAREND = 542,
     MATRIXOBJECTIVESSTART = 543,
     MATRIXOBJECTIVESEND = 544,
     MATRIXOBJSTART = 545,
     MATRIXOBJEND = 546,
     MATRIXCONSTRAINTSSTART = 547,
     MATRIXCONSTRAINTSEND = 548,
     MATRIXCONSTART = 549,
     MATRIXCONEND = 550,
     CONSTART = 551,
     CONEND = 552,
     CONSTRAINTSSTART = 553,
     CONSTRAINTSEND = 554,
     OBJSTART = 555,
     OBJEND = 556,
     OBJECTIVESSTART = 557,
     OBJECTIVESEND = 558,
     VARSTART = 559,
     VAREND = 560,
     VARIABLESSTART = 561,
     VARIABLESEND = 562,
     GENERALSTART = 563,
     GENERALEND = 564,
     SYSTEMSTART = 565,
     SYSTEMEND = 566,
     SERVICESTART = 567,
     SERVICEEND = 568,
     JOBSTART = 569,
     JOBEND = 570,
     OPTIMIZATIONSTART = 571,
     OPTIMIZATIONEND = 572,
     ATEQUALITYSTART = 573,
     ATEQUALITYEND = 574,
     ATLOWERSTART = 575,
     ATLOWEREND = 576,
     ATUPPERSTART = 577,
     ATUPPEREND = 578,
     BASICSTART = 579,
     BASICEND = 580,
     ISFREESTART = 581,
     ISFREEEND = 582,
     SUPERBASICSTART = 583,
     SUPERBASICEND = 584,
     UNKNOWNSTART = 585,
     UNKNOWNEND = 586,
     SERVICEURISTART = 587,
     SERVICEURIEND = 588,
     SERVICENAMESTART = 589,
     SERVICENAMEEND = 590,
     INSTANCENAMESTART = 591,
     INSTANCENAMEEND = 592,
     JOBIDSTART = 593,
     JOBIDEND = 594,
     OTHERSTART = 595,
     OTHEREND = 596,
     DUMMY = 597,
     NONLINEAREXPRESSIONSSTART = 598,
     NONLINEAREXPRESSIONSEND = 599,
     NUMBEROFNONLINEAREXPRESSIONS = 600,
     NLSTART = 601,
     NLEND = 602,
     MATRIXEXPRESSIONSSTART = 603,
     MATRIXEXPRESSIONSEND = 604,
     NUMBEROFEXPR = 605,
     EXPRSTART = 606,
     EXPREND = 607,
     NUMBEROFMATRIXTERMSATT = 608,
     MATRIXTERMSTART = 609,
     MATRIXTERMEND = 610,
     POWERSTART = 611,
     POWEREND = 612,
     PLUSSTART = 613,
     PLUSEND = 614,
     MINUSSTART = 615,
     MINUSEND = 616,
     DIVIDESTART = 617,
     DIVIDEEND = 618,
     LNSTART = 619,
     LNEND = 620,
     SQRTSTART = 621,
     SQRTEND = 622,
     SUMSTART = 623,
     SUMEND = 624,
     PRODUCTSTART = 625,
     PRODUCTEND = 626,
     EXPSTART = 627,
     EXPEND = 628,
     NEGATESTART = 629,
     NEGATEEND = 630,
     IFSTART = 631,
     IFEND = 632,
     SQUARESTART = 633,
     SQUAREEND = 634,
     COSSTART = 635,
     COSEND = 636,
     SINSTART = 637,
     SINEND = 638,
     VARIABLESTART = 639,
     VARIABLEEND = 640,
     ABSSTART = 641,
     ABSEND = 642,
     ERFSTART = 643,
     ERFEND = 644,
     MAXSTART = 645,
     MAXEND = 646,
     ALLDIFFSTART = 647,
     ALLDIFFEND = 648,
     MINSTART = 649,
     MINEND = 650,
     ESTART = 651,
     EEND = 652,
     PISTART = 653,
     PIEND = 654,
     TIMESSTART = 655,
     TIMESEND = 656,
     NUMBERSTART = 657,
     NUMBEREND = 658,
     MATRIXDETERMINANTSTART = 659,
     MATRIXDETERMINANTEND = 660,
     MATRIXTRACESTART = 661,
     MATRIXTRACEEND = 662,
     MATRIXTOSCALARSTART = 663,
     MATRIXTOSCALAREND = 664,
     MATRIXDIAGONALSTART = 665,
     MATRIXDIAGONALEND = 666,
     MATRIXDOTTIMESSTART = 667,
     MATRIXDOTTIMESEND = 668,
     MATRIXLOWERTRIANGLESTART = 669,
     MATRIXLOWERTRIANGLEEND = 670,
     MATRIXUPPERTRIANGLESTART = 671,
     MATRIXUPPERTRIANGLEEND = 672,
     MATRIXMERGESTART = 673,
     MATRIXMERGEEND = 674,
     MATRIXMINUSSTART = 675,
     MATRIXMINUSEND = 676,
     MATRIXNEGATESTART = 677,
     MATRIXNEGATEEND = 678,
     MATRIXPLUSSTART = 679,
     MATRIXPLUSEND = 680,
     MATRIXTIMESSTART = 681,
     MATRIXTIMESEND = 682,
     MATRIXPRODUCTSTART = 683,
     MATRIXPRODUCTEND = 684,
     MATRIXSCALARTIMESSTART = 685,
     MATRIXSCALARTIMESEND = 686,
     MATRIXSUBMATRIXATSTART = 687,
     MATRIXSUBMATRIXATEND = 688,
     MATRIXTRANSPOSESTART = 689,
     MATRIXTRANSPOSEEND = 690,
     MATRIXREFERENCESTART = 691,
     MATRIXREFERENCEEND = 692,
     IDENTITYMATRIXSTART = 693,
     IDENTITYMATRIXEND = 694,
     MATRIXINVERSESTART = 695,
     MATRIXINVERSEEND = 696,
     EMPTYINCLUDEDIAGONALATT = 697,
     INCLUDEDIAGONALATT = 698,
     EMPTYIDATT = 699,
     IDATT = 700
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
#define MATRIXVARIDXATT 488
#define MATRIXOBJIDXATT 489
#define MATRIXCONIDXATT 490
#define IDXATT 491
#define INCRATT 492
#define MULTATT 493
#define SIZEOFATT 494
#define COEFATT 495
#define CONSTANTATT 496
#define MATRICESSTART 497
#define MATRICESEND 498
#define MATRIXSTART 499
#define MATRIXEND 500
#define BASEMATRIXEND 501
#define BASEMATRIXSTART 502
#define BLOCKSSTART 503
#define BLOCKSEND 504
#define BLOCKSTART 505
#define BLOCKEND 506
#define COLOFFSETSTART 507
#define COLOFFSETEND 508
#define ROWOFFSETSTART 509
#define ROWOFFSETEND 510
#define ELEMENTSSTART 511
#define ELEMENTSEND 512
#define CONSTANTELEMENTSSTART 513
#define CONSTANTELEMENTSEND 514
#define VARREFERENCEELEMENTSSTART 515
#define VARREFERENCEELEMENTSEND 516
#define LINEARELEMENTSSTART 517
#define LINEARELEMENTSEND 518
#define GENERALELEMENTSSTART 519
#define GENERALELEMENTSEND 520
#define CONREFERENCEELEMENTSSTART 521
#define CONREFERENCEELEMENTSEND 522
#define OBJREFERENCEELEMENTSSTART 523
#define OBJREFERENCEELEMENTSEND 524
#define STRINGVALUEDELEMENTSSTART 525
#define STRINGVALUEDELEMENTSEND 526
#define STARTVECTORSTART 527
#define STARTVECTOREND 528
#define INDEXSTART 529
#define INDEXEND 530
#define VALUESTART 531
#define VALUEEND 532
#define VARIDXSTART 533
#define VARIDXEND 534
#define TRANSFORMATIONSTART 535
#define TRANSFORMATIONEND 536
#define MATRIXPROGRAMMINGSTART 537
#define MATRIXPROGRAMMINGEND 538
#define MATRIXVARIABLESSTART 539
#define MATRIXVARIABLESEND 540
#define MATRIXVARSTART 541
#define MATRIXVAREND 542
#define MATRIXOBJECTIVESSTART 543
#define MATRIXOBJECTIVESEND 544
#define MATRIXOBJSTART 545
#define MATRIXOBJEND 546
#define MATRIXCONSTRAINTSSTART 547
#define MATRIXCONSTRAINTSEND 548
#define MATRIXCONSTART 549
#define MATRIXCONEND 550
#define CONSTART 551
#define CONEND 552
#define CONSTRAINTSSTART 553
#define CONSTRAINTSEND 554
#define OBJSTART 555
#define OBJEND 556
#define OBJECTIVESSTART 557
#define OBJECTIVESEND 558
#define VARSTART 559
#define VAREND 560
#define VARIABLESSTART 561
#define VARIABLESEND 562
#define GENERALSTART 563
#define GENERALEND 564
#define SYSTEMSTART 565
#define SYSTEMEND 566
#define SERVICESTART 567
#define SERVICEEND 568
#define JOBSTART 569
#define JOBEND 570
#define OPTIMIZATIONSTART 571
#define OPTIMIZATIONEND 572
#define ATEQUALITYSTART 573
#define ATEQUALITYEND 574
#define ATLOWERSTART 575
#define ATLOWEREND 576
#define ATUPPERSTART 577
#define ATUPPEREND 578
#define BASICSTART 579
#define BASICEND 580
#define ISFREESTART 581
#define ISFREEEND 582
#define SUPERBASICSTART 583
#define SUPERBASICEND 584
#define UNKNOWNSTART 585
#define UNKNOWNEND 586
#define SERVICEURISTART 587
#define SERVICEURIEND 588
#define SERVICENAMESTART 589
#define SERVICENAMEEND 590
#define INSTANCENAMESTART 591
#define INSTANCENAMEEND 592
#define JOBIDSTART 593
#define JOBIDEND 594
#define OTHERSTART 595
#define OTHEREND 596
#define DUMMY 597
#define NONLINEAREXPRESSIONSSTART 598
#define NONLINEAREXPRESSIONSEND 599
#define NUMBEROFNONLINEAREXPRESSIONS 600
#define NLSTART 601
#define NLEND 602
#define MATRIXEXPRESSIONSSTART 603
#define MATRIXEXPRESSIONSEND 604
#define NUMBEROFEXPR 605
#define EXPRSTART 606
#define EXPREND 607
#define NUMBEROFMATRIXTERMSATT 608
#define MATRIXTERMSTART 609
#define MATRIXTERMEND 610
#define POWERSTART 611
#define POWEREND 612
#define PLUSSTART 613
#define PLUSEND 614
#define MINUSSTART 615
#define MINUSEND 616
#define DIVIDESTART 617
#define DIVIDEEND 618
#define LNSTART 619
#define LNEND 620
#define SQRTSTART 621
#define SQRTEND 622
#define SUMSTART 623
#define SUMEND 624
#define PRODUCTSTART 625
#define PRODUCTEND 626
#define EXPSTART 627
#define EXPEND 628
#define NEGATESTART 629
#define NEGATEEND 630
#define IFSTART 631
#define IFEND 632
#define SQUARESTART 633
#define SQUAREEND 634
#define COSSTART 635
#define COSEND 636
#define SINSTART 637
#define SINEND 638
#define VARIABLESTART 639
#define VARIABLEEND 640
#define ABSSTART 641
#define ABSEND 642
#define ERFSTART 643
#define ERFEND 644
#define MAXSTART 645
#define MAXEND 646
#define ALLDIFFSTART 647
#define ALLDIFFEND 648
#define MINSTART 649
#define MINEND 650
#define ESTART 651
#define EEND 652
#define PISTART 653
#define PIEND 654
#define TIMESSTART 655
#define TIMESEND 656
#define NUMBERSTART 657
#define NUMBEREND 658
#define MATRIXDETERMINANTSTART 659
#define MATRIXDETERMINANTEND 660
#define MATRIXTRACESTART 661
#define MATRIXTRACEEND 662
#define MATRIXTOSCALARSTART 663
#define MATRIXTOSCALAREND 664
#define MATRIXDIAGONALSTART 665
#define MATRIXDIAGONALEND 666
#define MATRIXDOTTIMESSTART 667
#define MATRIXDOTTIMESEND 668
#define MATRIXLOWERTRIANGLESTART 669
#define MATRIXLOWERTRIANGLEEND 670
#define MATRIXUPPERTRIANGLESTART 671
#define MATRIXUPPERTRIANGLEEND 672
#define MATRIXMERGESTART 673
#define MATRIXMERGEEND 674
#define MATRIXMINUSSTART 675
#define MATRIXMINUSEND 676
#define MATRIXNEGATESTART 677
#define MATRIXNEGATEEND 678
#define MATRIXPLUSSTART 679
#define MATRIXPLUSEND 680
#define MATRIXTIMESSTART 681
#define MATRIXTIMESEND 682
#define MATRIXPRODUCTSTART 683
#define MATRIXPRODUCTEND 684
#define MATRIXSCALARTIMESSTART 685
#define MATRIXSCALARTIMESEND 686
#define MATRIXSUBMATRIXATSTART 687
#define MATRIXSUBMATRIXATEND 688
#define MATRIXTRANSPOSESTART 689
#define MATRIXTRANSPOSEEND 690
#define MATRIXREFERENCESTART 691
#define MATRIXREFERENCEEND 692
#define IDENTITYMATRIXSTART 693
#define IDENTITYMATRIXEND 694
#define MATRIXINVERSESTART 695
#define MATRIXINVERSEEND 696
#define EMPTYINCLUDEDIAGONALATT 697
#define INCLUDEDIAGONALATT 698
#define EMPTYIDATT 699
#define IDATT 700




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
#define YYNTOKENS  450
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  720
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1097
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1501

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   700

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   447,
     449,     2,     2,   448,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   446,     2,     2,     2,     2,     2,     2,     2,
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
     445
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
     451,     0,    -1,   452,   460,   458,    -1,   453,   454,   455,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   456,    -1,
     457,    -1,    11,    -1,    10,   460,   458,    -1,   459,    -1,
      15,    -1,    -1,   461,   462,   548,   591,   614,   725,    -1,
      -1,  1041,    -1,    -1,   463,   464,    -1,   308,    -1,   465,
      -1,   466,    -1,    10,   309,    -1,    11,    -1,    10,   467,
     309,    -1,   468,    -1,   469,    -1,   468,   469,    -1,   470,
      -1,   476,    -1,   482,    -1,   488,    -1,   496,    -1,   502,
      -1,   508,    -1,   514,    -1,   520,    -1,   526,    -1,   534,
      -1,   471,   472,    -1,   332,    -1,   473,    -1,   474,    -1,
      10,   333,    -1,    11,    -1,    10,   475,   333,    -1,     4,
      -1,   477,   478,    -1,   334,    -1,   479,    -1,   480,    -1,
      10,   335,    -1,    11,    -1,    10,   481,   335,    -1,     4,
      -1,   483,   484,    -1,   336,    -1,   485,    -1,   486,    -1,
      10,   337,    -1,    11,    -1,    10,   487,   337,    -1,     4,
      -1,   489,   490,   492,    -1,    43,    -1,    -1,   491,    -1,
      27,     3,     8,    -1,   493,    -1,   494,    -1,    10,    44,
      -1,    11,    -1,    10,   495,    44,    -1,     4,    -1,   497,
     498,    -1,   338,    -1,   499,    -1,   500,    -1,    10,   339,
      -1,    11,    -1,    10,   501,   339,    -1,     4,    -1,   503,
     504,    -1,    45,    -1,   505,    -1,   506,    -1,    10,    46,
      -1,    11,    -1,    10,   507,    46,    -1,     4,    -1,   509,
     510,    -1,    47,    -1,   511,    -1,   512,    -1,    10,    48,
      -1,    11,    -1,    10,   513,    48,    -1,     4,    -1,   515,
     516,    -1,    49,    -1,   517,    -1,   518,    -1,    10,    50,
      -1,    11,    -1,    10,   519,    50,    -1,     4,    -1,   521,
     522,    -1,    51,    -1,   523,    -1,   524,    -1,    10,    52,
      -1,    11,    -1,    10,   525,    52,    -1,     4,    -1,   527,
     528,   530,    -1,    53,    -1,    -1,   529,    -1,    26,     3,
       8,    -1,   531,    -1,   532,    -1,    10,    54,    -1,    11,
      -1,    10,   533,    54,    -1,     4,    -1,   535,   536,   537,
      -1,   123,    -1,  1021,    -1,   538,    -1,   539,    -1,    10,
     124,    -1,    11,    -1,    10,   540,   124,    -1,   541,    -1,
     542,    -1,   541,   542,    -1,   543,   544,   547,    -1,   340,
      -1,   545,    -1,    -1,   545,   546,    -1,  1149,    -1,  1164,
      -1,  1143,    -1,    10,   341,    -1,    11,    -1,    -1,   549,
     550,    -1,   310,    -1,   551,    -1,   552,    -1,    10,   311,
      -1,    11,    -1,    10,   553,   311,    -1,   554,    -1,   555,
      -1,   554,   555,    -1,   556,    -1,   563,    -1,   570,    -1,
     577,    -1,   582,    -1,   557,   558,   561,    -1,    55,    -1,
     559,    -1,    -1,   559,   560,    -1,  1161,    -1,  1143,    -1,
      10,   562,    56,    -1,  1037,    -1,   564,   565,   568,    -1,
      57,    -1,   566,    -1,    -1,   566,   567,    -1,  1161,    -1,
    1143,    -1,    10,   569,    58,    -1,  1037,    -1,   571,   572,
     575,    -1,    59,    -1,   573,    -1,    -1,   573,   574,    -1,
    1161,    -1,  1143,    -1,    10,   576,    60,    -1,  1037,    -1,
     578,   579,   580,    -1,    61,    -1,    -1,  1143,    -1,    10,
     581,    62,    -1,     6,    -1,   583,   584,   585,    -1,   123,
      -1,  1021,    -1,   586,    -1,   587,    -1,    10,   124,    -1,
      11,    -1,    10,   588,   124,    -1,   589,    -1,   590,    -1,
     589,   590,    -1,   543,   544,   547,    -1,    -1,   592,   593,
      -1,   312,    -1,   594,    -1,   595,    -1,    10,   313,    -1,
      11,    -1,    10,   596,   313,    -1,   597,    -1,   598,    -1,
     597,   598,    -1,   599,    -1,   605,    -1,   600,   601,    -1,
      63,    -1,   602,    -1,   603,    -1,    10,    64,    -1,    11,
      -1,    10,   604,    64,    -1,     4,    -1,   606,   607,   608,
      -1,   123,    -1,  1021,    -1,   609,    -1,   610,    -1,    10,
     124,    -1,    11,    -1,    10,   611,   124,    -1,   612,    -1,
     613,    -1,   612,   613,    -1,   543,   544,   547,    -1,    -1,
     615,   616,    -1,   314,    -1,   617,    -1,   618,    -1,    10,
     315,    -1,    11,    -1,    10,   619,   315,    -1,   620,    -1,
     621,    -1,   620,   621,    -1,   622,    -1,   630,    -1,   636,
      -1,   644,    -1,   649,    -1,   654,    -1,   659,    -1,   664,
      -1,   672,    -1,   688,    -1,   680,    -1,   696,    -1,   702,
      -1,   708,    -1,   716,    -1,   623,   624,   625,    -1,    65,
      -1,    -1,  1161,    -1,   626,    -1,   627,    -1,    10,    66,
      -1,    11,    -1,    10,   628,    66,    -1,   629,    -1,  1037,
      -1,   631,   632,    -1,    67,    -1,   633,    -1,   634,    -1,
      10,    68,    -1,    11,    -1,    10,   635,    68,    -1,     4,
      -1,   637,   638,   639,    -1,    69,    -1,  1018,    -1,   640,
      -1,   641,    -1,    10,    70,    -1,    11,    -1,    10,   642,
      70,    -1,   643,    -1,   642,   643,    -1,   338,    10,     4,
     339,    -1,   645,  1024,   646,    -1,    75,    -1,   647,    -1,
     648,    -1,    10,    76,    -1,    11,    -1,    10,   986,    76,
      -1,   650,  1024,   651,    -1,    77,    -1,   652,    -1,   653,
      -1,    10,    78,    -1,    11,    -1,    10,   986,    78,    -1,
     655,  1024,   656,    -1,    79,    -1,   657,    -1,   658,    -1,
      10,    80,    -1,    11,    -1,    10,   986,    80,    -1,   660,
    1024,   661,    -1,    81,    -1,   662,    -1,   663,    -1,    10,
      82,    -1,    11,    -1,    10,   986,    82,    -1,   665,   666,
     667,    -1,    87,    -1,  1023,    -1,   668,    -1,   669,    -1,
      10,    88,    -1,    11,    -1,    10,   670,    88,    -1,   671,
      -1,   670,   671,    -1,   988,    -1,   673,   674,   675,    -1,
      89,    -1,  1023,    -1,   676,    -1,   677,    -1,    10,    90,
      -1,    11,    -1,    10,   678,    90,    -1,   679,    -1,   678,
     679,    -1,   988,    -1,   681,   682,   683,    -1,    93,    -1,
    1023,    -1,   684,    -1,   685,    -1,    10,    94,    -1,    11,
      -1,    10,   686,    94,    -1,   687,    -1,   686,   687,    -1,
     988,    -1,   689,   690,   691,    -1,    91,    -1,  1023,    -1,
     692,    -1,   693,    -1,    10,    92,    -1,    11,    -1,    10,
     694,    92,    -1,   695,    -1,   694,   695,    -1,   988,    -1,
     697,   698,   699,    -1,    85,    -1,  1024,    -1,   700,    -1,
     701,    -1,    10,    86,    -1,    11,    -1,    10,   986,    86,
      -1,   703,   704,   705,    -1,    83,    -1,  1024,    -1,   706,
      -1,   707,    -1,    10,    84,    -1,    11,    -1,    10,   986,
      84,    -1,   709,   710,   711,    -1,    95,    -1,  1025,    -1,
     712,    -1,   713,    -1,    10,    96,    -1,    11,    -1,    10,
     714,    96,    -1,   715,    -1,   714,   715,    -1,    97,    10,
       4,    98,    -1,   717,   718,   719,    -1,   123,    -1,  1021,
      -1,   720,    -1,   721,    -1,    10,   124,    -1,    11,    -1,
      10,   722,   124,    -1,   723,    -1,   724,    -1,   723,   724,
      -1,   543,   544,   547,    -1,    -1,   726,   727,   730,    -1,
     316,    -1,   728,    -1,    -1,   728,   729,    -1,  1132,    -1,
    1125,    -1,  1130,    -1,   731,    -1,   732,    -1,    11,    -1,
      10,   733,   317,    -1,   734,   830,   897,   964,    -1,    -1,
     735,   736,   738,    -1,   306,    -1,   737,    -1,    -1,  1022,
      -1,   739,    -1,   740,    -1,    11,    -1,    10,   741,   307,
      -1,   742,   756,   770,   783,   797,   812,    -1,    -1,   743,
     744,   745,    -1,    99,    -1,  1131,    -1,   746,    -1,   747,
      -1,    10,   100,    -1,    11,    -1,    10,   748,   100,    -1,
     749,    -1,   750,    -1,   749,   750,    -1,   751,   752,   755,
      -1,   304,    -1,   753,    -1,    -1,   753,   754,    -1,  1134,
      -1,  1149,    -1,  1164,    -1,    10,   305,    -1,    11,    -1,
      -1,   757,   758,   759,    -1,   101,    -1,  1131,    -1,   760,
      -1,   761,    -1,    10,   102,    -1,    11,    -1,    10,   762,
     102,    -1,   763,    -1,   764,    -1,   763,   764,    -1,   765,
     766,   769,    -1,   304,    -1,   767,    -1,    -1,   767,   768,
      -1,  1134,    -1,  1149,    -1,  1164,    -1,    10,   305,    -1,
      11,    -1,    -1,   771,   772,    -1,   103,    -1,   773,    -1,
     774,    -1,    11,    -1,    10,   775,   104,    -1,   776,   777,
     778,   779,   780,   781,   782,    -1,    -1,  1081,    -1,    -1,
    1087,    -1,    -1,  1093,    -1,    -1,  1099,    -1,    -1,  1105,
      -1,    -1,  1111,    -1,    -1,  1117,    -1,    -1,   784,   785,
     786,    -1,   105,    -1,  1131,    -1,   787,    -1,   788,    -1,
      10,   106,    -1,    11,    -1,    10,   789,   106,    -1,   790,
      -1,   791,    -1,   790,   791,    -1,   792,   793,   796,    -1,
     304,    -1,   794,    -1,    -1,   794,   795,    -1,  1134,    -1,
    1149,    -1,  1164,    -1,    10,   305,    -1,    11,    -1,    -1,
     798,   799,   800,    -1,   107,    -1,    40,     8,     6,     8,
      -1,   801,    -1,   802,    -1,    10,   108,    -1,    11,    -1,
      10,   803,   108,    -1,   804,    -1,   803,   804,    -1,   805,
     806,   809,    -1,   109,    -1,   807,    -1,    -1,   807,   808,
      -1,  1007,    -1,  1131,    -1,   997,    -1,   810,    -1,   811,
      -1,    10,   110,    -1,    11,    -1,    10,   790,   110,    -1,
      -1,   812,   813,    -1,   814,   815,   818,    -1,   340,    -1,
     816,    -1,    -1,   816,   817,    -1,  1131,    -1,  1127,    -1,
    1149,    -1,  1164,    -1,  1155,    -1,  1137,    -1,  1158,    -1,
    1167,    -1,  1146,    -1,  1143,    -1,   819,    -1,   820,    -1,
      10,   341,    -1,    11,    -1,    10,   821,   341,    -1,   822,
      -1,  1027,    -1,   823,    -1,   822,   823,    -1,   824,   825,
     828,    -1,   304,    -1,   826,    -1,    -1,   826,   827,    -1,
    1134,    -1,  1149,    -1,  1164,    -1,   999,    -1,  1010,    -1,
     829,    -1,    10,   305,    -1,    11,    -1,    -1,   831,   832,
     834,    -1,   302,    -1,   833,    -1,    -1,  1020,    -1,   835,
      -1,   836,    -1,    11,    -1,    10,   837,   303,    -1,   838,
     852,   866,   879,    -1,    -1,   839,   840,   841,    -1,   111,
      -1,  1129,    -1,   842,    -1,   843,    -1,    10,   112,    -1,
      11,    -1,    10,   844,   112,    -1,   845,    -1,   846,    -1,
     845,   846,    -1,   847,   848,   851,    -1,   300,    -1,   849,
      -1,    -1,   849,   850,    -1,  1134,    -1,  1149,    -1,  1164,
      -1,    10,   301,    -1,    11,    -1,    -1,   853,   854,   855,
      -1,   113,    -1,  1129,    -1,   856,    -1,   857,    -1,    10,
     114,    -1,    11,    -1,    10,   858,   114,    -1,   859,    -1,
     860,    -1,   859,   860,    -1,   861,   862,   865,    -1,   300,
      -1,   863,    -1,    -1,   863,   864,    -1,  1134,    -1,  1149,
      -1,   999,    -1,  1010,    -1,    10,   301,    -1,    11,    -1,
      -1,   867,   868,    -1,   103,    -1,   869,    -1,   870,    -1,
      11,    -1,    10,   871,   104,    -1,   872,   873,   874,   875,
     876,   877,   878,    -1,    -1,  1081,    -1,    -1,  1087,    -1,
      -1,  1093,    -1,    -1,  1099,    -1,    -1,  1105,    -1,    -1,
    1111,    -1,    -1,  1117,    -1,    -1,   879,   880,    -1,   881,
     882,   885,    -1,   340,    -1,   883,    -1,    -1,   883,   884,
      -1,  1129,    -1,  1127,    -1,  1149,    -1,  1164,    -1,  1155,
      -1,  1137,    -1,  1158,    -1,  1152,    -1,  1146,    -1,  1143,
      -1,   886,    -1,   887,    -1,    10,   341,    -1,    11,    -1,
      10,   888,   341,    -1,   889,    -1,  1027,    -1,   890,    -1,
     889,   890,    -1,   891,   892,   895,    -1,   300,    -1,   893,
      -1,    -1,   893,   894,    -1,  1134,    -1,  1149,    -1,  1164,
      -1,   999,    -1,  1010,    -1,   896,    -1,    10,   301,    -1,
      11,    -1,    -1,   898,   899,   901,    -1,   298,    -1,   900,
      -1,    -1,  1019,    -1,   902,    -1,   903,    -1,    11,    -1,
      10,   904,   299,    -1,   905,   919,   933,   946,    -1,    -1,
     906,   907,   908,    -1,   115,    -1,  1124,    -1,   909,    -1,
     910,    -1,    10,   116,    -1,    11,    -1,    10,   911,   116,
      -1,   912,    -1,   913,    -1,   912,   913,    -1,   914,   915,
     918,    -1,   296,    -1,   916,    -1,    -1,   916,   917,    -1,
    1134,    -1,  1149,    -1,  1164,    -1,    10,   297,    -1,    11,
      -1,    -1,   920,   921,   922,    -1,   117,    -1,  1124,    -1,
     923,    -1,   924,    -1,    10,   118,    -1,    11,    -1,    10,
     925,   118,    -1,   926,    -1,   927,    -1,   926,   927,    -1,
     928,   929,   932,    -1,   296,    -1,   930,    -1,    -1,   930,
     931,    -1,  1134,    -1,  1149,    -1,  1003,    -1,  1014,    -1,
      10,   297,    -1,    11,    -1,    -1,   934,   935,    -1,   103,
      -1,   936,    -1,   937,    -1,    11,    -1,    10,   938,   104,
      -1,   939,   940,   941,   942,   943,   944,   945,    -1,    -1,
    1081,    -1,    -1,  1087,    -1,    -1,  1093,    -1,    -1,  1099,
      -1,    -1,  1105,    -1,    -1,  1111,    -1,    -1,  1117,    -1,
      -1,   946,   947,    -1,   948,   949,   952,    -1,   340,    -1,
     950,    -1,    -1,   950,   951,    -1,  1124,    -1,  1127,    -1,
    1149,    -1,  1164,    -1,  1155,    -1,  1137,    -1,  1158,    -1,
    1140,    -1,  1146,    -1,  1143,    -1,   953,    -1,   954,    -1,
      10,   341,    -1,    11,    -1,    10,   955,   341,    -1,   956,
      -1,  1027,    -1,   957,    -1,   956,   957,    -1,   958,   959,
     962,    -1,   296,    -1,   960,    -1,    -1,   960,   961,    -1,
    1134,    -1,  1149,    -1,  1164,    -1,   999,    -1,  1010,    -1,
     963,    -1,    10,   297,    -1,    11,    -1,    -1,   965,   966,
     967,    -1,   119,    -1,  1026,    -1,   968,    -1,   969,    -1,
      11,    -1,    10,   970,   120,    -1,    -1,   970,   971,    -1,
     972,   973,   976,    -1,   121,    -1,   974,    -1,   975,    -1,
     974,   975,    -1,  1149,    -1,  1164,    -1,  1155,    -1,  1137,
      -1,  1158,    -1,  1143,    -1,  1128,    -1,   977,    -1,   978,
      -1,    10,   122,    -1,    11,    -1,    10,   979,   122,    -1,
     980,    -1,   981,    -1,   980,   981,    -1,   982,    -1,   983,
      -1,   984,    -1,   160,    -1,   157,    -1,   158,   985,   159,
      -1,     5,    -1,   987,    -1,   986,   987,    -1,    71,    10,
       4,    72,    -1,   989,   990,   996,    -1,    73,    -1,   991,
      -1,    -1,   991,   992,    -1,   993,    -1,   994,    -1,   995,
      -1,    28,     3,     8,    -1,    29,     3,     8,    -1,    30,
       3,     8,    -1,    10,    74,    -1,    11,    -1,   998,    -1,
      42,     8,  1037,     8,    -1,  1000,    -1,  1001,    -1,  1002,
      -1,    16,    -1,    18,     3,  1038,    -1,  1004,    -1,  1005,
      -1,  1006,    -1,    20,    -1,    22,  1038,  1037,  1038,    -1,
    1008,    -1,  1009,    -1,    41,  1038,     6,  1038,    -1,  1011,
      -1,  1012,    -1,  1013,    -1,    17,    -1,    19,     3,  1038,
      -1,  1015,    -1,  1016,    -1,  1017,    -1,    21,    -1,    23,
    1038,  1037,  1038,    -1,    31,     8,     6,     8,    -1,    37,
    1038,     6,  1038,    -1,    36,  1038,     6,  1038,    -1,    39,
    1038,     6,  1038,    -1,    35,  1038,     6,  1038,    -1,    33,
       8,     6,     8,    -1,    32,     8,     6,     8,    -1,    34,
       8,     6,     8,    -1,    38,  1038,     6,  1038,    -1,  1028,
      -1,  1027,  1028,    -1,  1029,  1030,  1033,    -1,   155,    -1,
    1031,    -1,    -1,  1031,  1032,    -1,  1126,    -1,  1164,    -1,
    1143,    -1,  1034,    -1,  1035,    -1,    11,    -1,    10,  1036,
     156,    -1,  1069,    -1,     6,    -1,     7,    -1,  1039,     8,
      -1,    -1,  1039,  1040,    -1,   446,    -1,   447,    -1,   448,
      -1,   449,    -1,  1042,  1043,    -1,   125,    -1,  1044,    -1,
    1045,    -1,    11,    -1,    10,  1046,   126,    -1,  1047,    -1,
      -1,  1047,  1048,    -1,  1049,    -1,  1053,    -1,  1057,    -1,
    1061,    -1,  1065,    -1,  1050,    -1,  1051,    -1,  1052,    -1,
     130,    -1,   129,    -1,   127,     5,   128,    -1,  1054,    -1,
    1055,    -1,  1056,    -1,   134,    -1,   133,    -1,   131,     5,
     132,    -1,  1058,    -1,  1059,    -1,  1060,    -1,   138,    -1,
     137,    -1,   135,     5,   136,    -1,  1062,    -1,  1063,    -1,
    1064,    -1,   142,    -1,   141,    -1,   139,     5,   140,    -1,
    1066,    -1,  1067,    -1,  1068,    -1,   146,    -1,   145,    -1,
     143,     5,   144,    -1,  1070,    -1,  1077,    -1,    -1,  1070,
    1071,    -1,  1072,  1073,  1076,    -1,   153,    -1,  1074,    -1,
      -1,  1074,  1075,    -1,  1136,    -1,  1135,    -1,    10,     6,
     154,    -1,   161,  1133,  1078,    -1,  1079,    -1,  1080,    -1,
      10,   162,    -1,    11,    -1,    10,     4,   162,    -1,  1082,
    1123,  1083,    -1,   324,    -1,  1084,    -1,  1085,    -1,    11,
      -1,    10,  1086,   325,    -1,  1069,    -1,  1088,  1123,  1089,
      -1,   320,    -1,  1090,    -1,  1091,    -1,    11,    -1,    10,
    1092,   321,    -1,  1069,    -1,  1094,  1123,  1095,    -1,   322,
      -1,  1096,    -1,  1097,    -1,    11,    -1,    10,  1098,   323,
      -1,  1069,    -1,  1100,  1123,  1101,    -1,   318,    -1,  1102,
      -1,  1103,    -1,    11,    -1,    10,  1104,   319,    -1,  1069,
      -1,  1106,  1123,  1107,    -1,   326,    -1,  1108,    -1,  1109,
      -1,    11,    -1,    10,  1110,   327,    -1,  1069,    -1,  1112,
    1123,  1113,    -1,   328,    -1,  1114,    -1,  1115,    -1,    11,
      -1,    10,  1116,   329,    -1,  1069,    -1,  1118,  1123,  1119,
      -1,   330,    -1,  1120,    -1,  1121,    -1,    11,    -1,    10,
    1122,   331,    -1,  1069,    -1,  1126,    -1,   212,     8,     6,
       8,    -1,   211,     8,     6,     8,    -1,   163,     8,     6,
       8,    -1,   164,     8,     6,     8,    -1,   165,     8,     6,
       8,    -1,   215,     8,     6,     8,    -1,   214,     8,     6,
       8,    -1,   218,     8,     6,     8,    -1,   217,     8,     6,
       8,    -1,   239,     8,     6,     8,    -1,   236,     8,     6,
       8,    -1,   237,     8,     6,     8,    -1,   238,     8,     6,
       8,    -1,  1138,    -1,  1139,    -1,   166,    -1,   167,     3,
       8,    -1,  1141,    -1,  1142,    -1,   186,    -1,   187,     3,
       8,    -1,  1144,    -1,  1145,    -1,   168,    -1,   169,     3,
       8,    -1,  1147,    -1,  1148,    -1,   176,    -1,   177,     3,
       8,    -1,  1150,    -1,  1151,    -1,   172,    -1,   173,     3,
       8,    -1,  1153,    -1,  1154,    -1,   188,    -1,   189,     3,
       8,    -1,  1156,    -1,  1157,    -1,   170,    -1,   171,     3,
       8,    -1,  1159,    -1,  1160,    -1,   174,    -1,   175,     3,
       8,    -1,  1162,    -1,  1163,    -1,   180,    -1,   181,     3,
       8,    -1,  1165,    -1,  1166,    -1,   182,    -1,   183,     3,
       8,    -1,  1168,    -1,  1169,    -1,   190,    -1,   191,     3,
       8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   332,   332,   333,   335,   342,   352,   352,   354,   354,
     356,   358,   360,   369,   370,   373,   381,   381,   394,   394,
     396,   412,   412,   414,   414,   416,   418,   420,   420,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     437,   439,   448,   448,   450,   450,   452,   454,   464,   466,
     473,   473,   475,   475,   477,   479,   489,   491,   497,   497,
     499,   499,   501,   503,   513,   520,   528,   529,   536,   542,
     542,   544,   544,   546,   548,   556,   558,   564,   564,   566,
     566,   568,   570,   579,   581,   588,   588,   590,   590,   592,
     594,   604,   606,   613,   613,   615,   615,   617,   619,   629,
     631,   637,   637,   639,   639,   641,   643,   653,   655,   661,
     661,   663,   663,   665,   667,   677,   684,   693,   694,   700,
     707,   707,   709,   709,   711,   713,   721,   727,   737,   745,
     750,   756,   756,   758,   760,   764,   764,   766,   777,   796,
     802,   802,   805,   809,   810,   813,   813,   861,   861,   863,
     873,   873,   875,   875,   877,   879,   881,   881,   884,   885,
     886,   887,   888,   892,   894,   904,   906,   906,   909,   910,
     913,   915,   923,   925,   935,   937,   937,   940,   941,   944,
     946,   955,   957,   967,   969,   969,   972,   973,   976,   978,
     987,   989,   999,  1000,  1002,  1004,  1015,  1021,  1031,  1039,
    1043,  1048,  1048,  1050,  1052,  1056,  1056,  1058,  1113,  1113,
    1115,  1122,  1122,  1124,  1124,  1126,  1128,  1130,  1130,  1133,
    1134,  1138,  1140,  1146,  1146,  1148,  1148,  1150,  1152,  1163,
    1169,  1179,  1187,  1191,  1196,  1196,  1198,  1200,  1204,  1204,
    1206,  1259,  1259,  1261,  1281,  1281,  1283,  1283,  1285,  1287,
    1289,  1289,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
    1300,  1301,  1302,  1303,  1304,  1305,  1306,  1311,  1317,  1327,
    1328,  1330,  1330,  1332,  1332,  1334,  1336,  1338,  1345,  1347,
    1353,  1353,  1355,  1355,  1357,  1359,  1369,  1380,  1390,  1392,
    1392,  1394,  1394,  1396,  1405,  1405,  1407,  1428,  1439,  1449,
    1449,  1451,  1451,  1453,  1464,  1475,  1485,  1485,  1487,  1487,
    1489,  1500,  1511,  1521,  1521,  1523,  1523,  1525,  1536,  1547,
    1557,  1557,  1559,  1559,  1561,  1572,  1588,  1598,  1600,  1600,
    1602,  1602,  1604,  1613,  1613,  1615,  1619,  1635,  1645,  1647,
    1647,  1649,  1649,  1651,  1660,  1660,  1662,  1666,  1682,  1692,
    1694,  1694,  1696,  1696,  1698,  1707,  1707,  1709,  1713,  1729,
    1739,  1741,  1741,  1743,  1743,  1745,  1754,  1754,  1756,  1760,
    1771,  1781,  1783,  1783,  1785,  1785,  1787,  1798,  1809,  1819,
    1821,  1821,  1823,  1823,  1825,  1851,  1862,  1872,  1874,  1874,
    1876,  1876,  1878,  1887,  1887,  1889,  1910,  1916,  1926,  1934,
    1938,  1943,  1943,  1945,  1947,  1951,  1951,  1953,  2007,  2007,
    2009,  2017,  2019,  2019,  2022,  2029,  2036,  2045,  2045,  2047,
    2049,  2051,  2058,  2058,  2060,  2066,  2073,  2073,  2078,  2078,
    2080,  2082,  2084,  2094,  2094,  2109,  2114,  2125,  2133,  2142,
    2142,  2144,  2146,  2148,  2148,  2151,  2156,  2170,  2176,  2176,
    2179,  2193,  2198,  2206,  2206,  2210,  2210,  2225,  2230,  2241,
    2249,  2258,  2258,  2260,  2262,  2264,  2264,  2267,  2273,  2288,
    2294,  2294,  2297,  2309,  2314,  2320,  2320,  2324,  2324,  2326,
    2331,  2331,  2333,  2335,  2337,  2340,  2340,  2378,  2378,  2414,
    2414,  2449,  2449,  2484,  2484,  2519,  2519,  2554,  2554,  2589,
    2589,  2605,  2610,  2621,  2629,  2638,  2638,  2640,  2642,  2648,
    2648,  2650,  2655,  2671,  2677,  2677,  2680,  2692,  2697,  2705,
    2705,  2709,  2709,  2715,  2721,  2729,  2737,  2745,  2745,  2747,
    2749,  2749,  2751,  2770,  2786,  2794,  2794,  2797,  2798,  2807,
    2810,  2810,  2812,  2812,  2814,  2819,  2819,  2821,  2826,  2858,
    2878,  2878,  2881,  2885,  2889,  2890,  2891,  2892,  2893,  2894,
    2895,  2896,  2899,  2899,  2901,  2901,  2903,  2905,  2905,  2907,
    2907,  2910,  2925,  2945,  2947,  2947,  2950,  2960,  2961,  2962,
    2963,  2966,  2968,  2968,  2976,  2976,  2978,  2984,  2991,  2991,
    2996,  2996,  2998,  3000,  3002,  3011,  3011,  3027,  3033,  3045,
    3053,  3062,  3062,  3064,  3066,  3068,  3068,  3071,  3076,  3091,
    3093,  3093,  3096,  3107,  3111,  3118,  3118,  3121,  3121,  3139,
    3144,  3158,  3166,  3175,  3175,  3177,  3179,  3181,  3181,  3184,
    3189,  3207,  3209,  3209,  3212,  3223,  3227,  3233,  3240,  3240,
    3244,  3244,  3246,  3251,  3251,  3253,  3255,  3257,  3260,  3260,
    3294,  3294,  3328,  3328,  3362,  3362,  3396,  3396,  3430,  3430,
    3466,  3466,  3501,  3501,  3503,  3509,  3540,  3561,  3561,  3564,
    3568,  3572,  3573,  3574,  3575,  3576,  3577,  3578,  3579,  3582,
    3582,  3584,  3584,  3586,  3588,  3588,  3590,  3590,  3593,  3608,
    3630,  3632,  3632,  3635,  3645,  3646,  3647,  3648,  3651,  3653,
    3653,  3661,  3661,  3663,  3669,  3676,  3676,  3681,  3681,  3683,
    3685,  3687,  3696,  3696,  3712,  3717,  3728,  3736,  3745,  3745,
    3747,  3749,  3751,  3751,  3754,  3759,  3775,  3782,  3782,  3785,
    3796,  3800,  3807,  3807,  3811,  3811,  3829,  3834,  3847,  3855,
    3864,  3864,  3866,  3868,  3870,  3870,  3873,  3878,  3897,  3904,
    3904,  3907,  3918,  3922,  3926,  3932,  3932,  3936,  3936,  3938,
    3943,  3943,  3945,  3947,  3949,  3952,  3952,  3986,  3986,  4021,
    4021,  4057,  4057,  4092,  4092,  4127,  4127,  4162,  4162,  4197,
    4197,  4199,  4205,  4236,  4256,  4256,  4259,  4263,  4267,  4268,
    4269,  4270,  4271,  4272,  4273,  4274,  4277,  4277,  4279,  4279,
    4281,  4283,  4283,  4285,  4285,  4288,  4303,  4323,  4325,  4325,
    4328,  4340,  4341,  4342,  4343,  4346,  4348,  4348,  4356,  4356,
    4362,  4364,  4372,  4380,  4389,  4391,  4393,  4393,  4397,  4417,
    4435,  4441,  4441,  4444,  4445,  4446,  4447,  4448,  4449,  4450,
    4457,  4465,  4474,  4474,  4476,  4478,  4480,  4480,  4482,  4489,
    4500,  4502,  4502,  4504,  4506,  4523,  4523,  4525,  4547,  4564,
    4576,  4581,  4581,  4584,  4585,  4586,  4588,  4597,  4606,  4615,
    4615,  4699,  4706,  4728,  4735,  4735,  4737,  4742,  4749,  4755,
    4755,  4757,  4762,  4826,  4832,  4834,  4860,  4867,  4867,  4869,
    4874,  4881,  4887,  4887,  4889,  4892,  5004,  5032,  5038,  5044,
    5050,  5056,  5070,  5080,  5091,  5127,  5127,  5129,  5148,  5165,
    5173,  5173,  5176,  5184,  5185,  5189,  5189,  5191,  5194,  5196,
    5200,  5201,  5208,  5210,  5210,  5212,  5213,  5214,  5215,  5250,
    5252,  5266,  5266,  5268,  5270,  5272,  5274,  5274,  5277,  5278,
    5279,  5280,  5281,  5283,  5291,  5291,  5293,  5293,  5295,  5301,
    5309,  5309,  5311,  5311,  5313,  5319,  5327,  5327,  5329,  5329,
    5331,  5337,  5345,  5345,  5347,  5347,  5349,  5355,  5363,  5363,
    5365,  5365,  5367,  5379,  5387,  5389,  5389,  5391,  5393,  5402,
    5404,  5404,  5406,  5406,  5408,  5424,  5427,  5427,  5429,  5429,
    5432,  5660,  5662,  5667,  5667,  5669,  5671,  5673,  5676,  5678,
    5683,  5683,  5685,  5687,  5689,  5692,  5694,  5699,  5699,  5701,
    5703,  5705,  5708,  5710,  5715,  5715,  5717,  5719,  5721,  5724,
    5726,  5731,  5731,  5733,  5735,  5737,  5740,  5742,  5747,  5747,
    5749,  5751,  5753,  5756,  5758,  5763,  5763,  5765,  5767,  5769,
    5772,  7050,  7072,  7083,  7094,  7105,  7173,  7195,  7228,  7250,
    7263,  7404,  7414,  7451,  7526,  7526,  7528,  7535,  7544,  7544,
    7546,  7553,  7562,  7562,  7564,  7571,  7580,  7580,  7582,  7589,
    7672,  7672,  7674,  7681,  7690,  7690,  7692,  7699,  7751,  7751,
    7753,  7760,  7787,  7787,  7789,  7796,  7805,  7805,  7807,  7814,
    7823,  7823,  7827,  7835,  7862,  7862,  7864,  7871
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
  "SCALARMULTIPLIERATT", "BLOCKROWIDXATT", "BLOCKCOLIDXATT",
  "MATRIXVARIDXATT", "MATRIXOBJIDXATT", "MATRIXCONIDXATT", "IDXATT",
  "INCRATT", "MULTATT", "SIZEOFATT", "COEFATT", "CONSTANTATT",
  "MATRICESSTART", "MATRICESEND", "MATRIXSTART", "MATRIXEND",
  "BASEMATRIXEND", "BASEMATRIXSTART", "BLOCKSSTART", "BLOCKSEND",
  "BLOCKSTART", "BLOCKEND", "COLOFFSETSTART", "COLOFFSETEND",
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
     695,   696,   697,   698,   699,   700,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   450,   451,   451,   452,   453,   454,   454,   455,   455,
     456,   457,   458,   459,   459,   460,   461,   461,   462,   462,
     463,   464,   464,   465,   465,   466,   467,   468,   468,   469,
     469,   469,   469,   469,   469,   469,   469,   469,   469,   469,
     470,   471,   472,   472,   473,   473,   474,   475,   476,   477,
     478,   478,   479,   479,   480,   481,   482,   483,   484,   484,
     485,   485,   486,   487,   488,   489,   490,   490,   491,   492,
     492,   493,   493,   494,   495,   496,   497,   498,   498,   499,
     499,   500,   501,   502,   503,   504,   504,   505,   505,   506,
     507,   508,   509,   510,   510,   511,   511,   512,   513,   514,
     515,   516,   516,   517,   517,   518,   519,   520,   521,   522,
     522,   523,   523,   524,   525,   526,   527,   528,   528,   529,
     530,   530,   531,   531,   532,   533,   534,   535,   536,   537,
     537,   538,   538,   539,   540,   541,   541,   542,   543,   544,
     545,   545,   546,   546,   546,   547,   547,   548,   548,   549,
     550,   550,   551,   551,   552,   553,   554,   554,   555,   555,
     555,   555,   555,   556,   557,   558,   559,   559,   560,   560,
     561,   562,   563,   564,   565,   566,   566,   567,   567,   568,
     569,   570,   571,   572,   573,   573,   574,   574,   575,   576,
     577,   578,   579,   579,   580,   581,   582,   583,   584,   585,
     585,   586,   586,   587,   588,   589,   589,   590,   591,   591,
     592,   593,   593,   594,   594,   595,   596,   597,   597,   598,
     598,   599,   600,   601,   601,   602,   602,   603,   604,   605,
     606,   607,   608,   608,   609,   609,   610,   611,   612,   612,
     613,   614,   614,   615,   616,   616,   617,   617,   618,   619,
     620,   620,   621,   621,   621,   621,   621,   621,   621,   621,
     621,   621,   621,   621,   621,   621,   621,   622,   623,   624,
     624,   625,   625,   626,   626,   627,   628,   629,   630,   631,
     632,   632,   633,   633,   634,   635,   636,   637,   638,   639,
     639,   640,   640,   641,   642,   642,   643,   644,   645,   646,
     646,   647,   647,   648,   649,   650,   651,   651,   652,   652,
     653,   654,   655,   656,   656,   657,   657,   658,   659,   660,
     661,   661,   662,   662,   663,   664,   665,   666,   667,   667,
     668,   668,   669,   670,   670,   671,   672,   673,   674,   675,
     675,   676,   676,   677,   678,   678,   679,   680,   681,   682,
     683,   683,   684,   684,   685,   686,   686,   687,   688,   689,
     690,   691,   691,   692,   692,   693,   694,   694,   695,   696,
     697,   698,   699,   699,   700,   700,   701,   702,   703,   704,
     705,   705,   706,   706,   707,   708,   709,   710,   711,   711,
     712,   712,   713,   714,   714,   715,   716,   717,   718,   719,
     719,   720,   720,   721,   722,   723,   723,   724,   725,   725,
     726,   727,   728,   728,   729,   729,   729,   730,   730,   731,
     732,   733,   734,   734,   735,   736,   737,   737,   738,   738,
     739,   740,   741,   742,   742,   743,   744,   745,   745,   746,
     746,   747,   748,   749,   749,   750,   751,   752,   753,   753,
     754,   754,   754,   755,   755,   756,   756,   757,   758,   759,
     759,   760,   760,   761,   762,   763,   763,   764,   765,   766,
     767,   767,   768,   768,   768,   769,   769,   770,   770,   771,
     772,   772,   773,   774,   775,   776,   776,   777,   777,   778,
     778,   779,   779,   780,   780,   781,   781,   782,   782,   783,
     783,   784,   785,   786,   786,   787,   787,   788,   789,   790,
     790,   791,   792,   793,   794,   794,   795,   795,   795,   796,
     796,   797,   797,   798,   799,   800,   800,   801,   801,   802,
     803,   803,   804,   805,   806,   807,   807,   808,   808,   808,
     809,   809,   810,   810,   811,   812,   812,   813,   814,   815,
     816,   816,   817,   817,   817,   817,   817,   817,   817,   817,
     817,   817,   818,   818,   819,   819,   820,   821,   821,   822,
     822,   823,   824,   825,   826,   826,   827,   827,   827,   827,
     827,   828,   829,   829,   830,   830,   831,   832,   833,   833,
     834,   834,   835,   836,   837,   838,   838,   839,   840,   841,
     841,   842,   842,   843,   844,   845,   845,   846,   847,   848,
     849,   849,   850,   850,   850,   851,   851,   852,   852,   853,
     854,   855,   855,   856,   856,   857,   858,   859,   859,   860,
     861,   862,   863,   863,   864,   864,   864,   864,   865,   865,
     866,   866,   867,   868,   868,   869,   870,   871,   872,   872,
     873,   873,   874,   874,   875,   875,   876,   876,   877,   877,
     878,   878,   879,   879,   880,   881,   882,   883,   883,   884,
     884,   884,   884,   884,   884,   884,   884,   884,   884,   885,
     885,   886,   886,   887,   888,   888,   889,   889,   890,   891,
     892,   893,   893,   894,   894,   894,   894,   894,   895,   896,
     896,   897,   897,   898,   899,   900,   900,   901,   901,   902,
     903,   904,   905,   905,   906,   907,   908,   908,   909,   909,
     910,   911,   912,   912,   913,   914,   915,   916,   916,   917,
     917,   917,   918,   918,   919,   919,   920,   921,   922,   922,
     923,   923,   924,   925,   926,   926,   927,   928,   929,   930,
     930,   931,   931,   931,   931,   932,   932,   933,   933,   934,
     935,   935,   936,   937,   938,   939,   939,   940,   940,   941,
     941,   942,   942,   943,   943,   944,   944,   945,   945,   946,
     946,   947,   948,   949,   950,   950,   951,   951,   951,   951,
     951,   951,   951,   951,   951,   951,   952,   952,   953,   953,
     954,   955,   955,   956,   956,   957,   958,   959,   960,   960,
     961,   961,   961,   961,   961,   962,   963,   963,   964,   964,
     965,   966,   967,   967,   968,   969,   970,   970,   971,   972,
     973,   974,   974,   975,   975,   975,   975,   975,   975,   975,
     976,   976,   977,   977,   978,   979,   980,   980,   981,   982,
     982,   983,   983,   984,   985,   986,   986,   987,   988,   989,
     990,   991,   991,   992,   992,   992,   993,   994,   995,   996,
     996,   997,   998,   999,  1000,  1000,  1001,  1002,  1003,  1004,
    1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,  1011,  1012,
    1013,  1014,  1015,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1027,  1028,  1029,  1030,
    1031,  1031,  1032,  1032,  1032,  1033,  1033,  1034,  1035,  1036,
    1037,  1037,  1038,  1039,  1039,  1040,  1040,  1040,  1040,  1041,
    1042,  1043,  1043,  1044,  1045,  1046,  1047,  1047,  1048,  1048,
    1048,  1048,  1048,  1049,  1050,  1050,  1051,  1051,  1052,  1053,
    1054,  1054,  1055,  1055,  1056,  1057,  1058,  1058,  1059,  1059,
    1060,  1061,  1062,  1062,  1063,  1063,  1064,  1065,  1066,  1066,
    1067,  1067,  1068,  1069,  1069,  1070,  1070,  1071,  1072,  1073,
    1074,  1074,  1075,  1075,  1076,  1077,  1078,  1078,  1079,  1079,
    1080,  1081,  1082,  1083,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1137,  1138,  1139,  1140,  1140,
    1141,  1142,  1143,  1143,  1144,  1145,  1146,  1146,  1147,  1148,
    1149,  1149,  1150,  1151,  1152,  1152,  1153,  1154,  1155,  1155,
    1156,  1157,  1158,  1158,  1159,  1160,  1161,  1161,  1162,  1163,
    1164,  1164,  1165,  1166,  1167,  1167,  1168,  1169
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
#define YYPACT_NINF -1240
static const yytype_int16 yypact[] =
{
     308, -1240, -1240,   153,    18,   148, -1240, -1240,   167,  -128,
   -1240,   328, -1240,   365, -1240, -1240, -1240, -1240,   -99,   388,
   -1240, -1240, -1240, -1240, -1240,    18, -1240, -1240, -1240, -1240,
   -1240,   -83,   404,   -24, -1240, -1240, -1240, -1240,   113,   425,
     167, -1240,   -63,   410,   -20, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   -30,   -19, -1240, -1240,   421, -1240,   423, -1240,   426,
   -1240,   226, -1240,   430, -1240,   432, -1240,   439, -1240,   441,
   -1240,   457, -1240,   264, -1240,   259, -1240,   295, -1240, -1240,
     299, -1240, -1240,   318, -1240, -1240,   325, -1240, -1240,   349,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240,    40,   459,   -21, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,    49,    55,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   305, -1240,
     259, -1240, -1240,    13, -1240, -1240, -1240, -1240,     8, -1240,
   -1240, -1240, -1240,     7, -1240, -1240, -1240, -1240,   361,   465,
   -1240,     6, -1240, -1240, -1240, -1240,   163, -1240, -1240, -1240,
   -1240,   136, -1240, -1240, -1240, -1240,   156, -1240, -1240, -1240,
   -1240,   140, -1240, -1240, -1240, -1240,   377,   469, -1240, -1240,
     471, -1240,   254,   252,   256,   248,   246, -1240, -1240, -1240,
     -22, -1240, -1240, -1240, -1240, -1240, -1240, -1240,    81,    54,
   -1240, -1240,   473, -1240,   259, -1240, -1240,   391,   114,   406,
     114,   412,   114, -1240,   435,   414, -1240, -1240, -1240,   475,
   -1240, -1240, -1240,    95, -1240, -1240,   100, -1240, -1240,   173,
     533,   129, -1240, -1240, -1240, -1240, -1240, -1240,   211, -1240,
   -1240,   507, -1240, -1240,   517, -1240, -1240,   511, -1240, -1240,
     563,   561,   146, -1240, -1240, -1240, -1240,   685,    -2,   -93,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   479,
     138, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,   378,   302, -1240,
   -1240,   311, -1240,   483, -1240,   661, -1240,   662, -1240,   662,
   -1240,   662, -1240,   662, -1240,   664, -1240,   664, -1240,   664,
   -1240,   664, -1240,   662, -1240,   662, -1240,   666, -1240,   259,
   -1240, -1240,   130, -1240, -1240, -1240, -1240,   485, -1240,   491,
   -1240, -1240,   692, -1240, -1240, -1240, -1240, -1240,   491, -1240,
   -1240, -1240, -1240,   491, -1240, -1240, -1240, -1240,   688,   693,
   -1240,   -88, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240,   654, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   648, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   579,   364, -1240, -1240,   395, -1240, -1240, -1240, -1240,
     697,   698,   699, -1240, -1240, -1240, -1240, -1240, -1240,   489,
   -1240,   111, -1240, -1240, -1240, -1240,   700,   495, -1240,   701,
     513,   515,   519,   523,   702,   525, -1240,   527, -1240,   529,
   -1240,   536, -1240,   538, -1240,   573, -1240,   703,   575, -1240,
     577, -1240, -1240, -1240,   649,   -86, -1240, -1240, -1240, -1240,
   -1240, -1240,   656, -1240,   706,   658, -1240,   660, -1240, -1240,
   -1240,   668, -1240, -1240,   594,   364, -1240, -1240, -1240, -1240,
   -1240, -1240,   581,   168, -1240,   398,   415,   684,   715,   716,
     717,   132, -1240, -1240, -1240, -1240, -1240, -1240,   669,   718,
     -52, -1240, -1240, -1240, -1240,   719,   282, -1240, -1240, -1240,
   -1240,   209, -1240, -1240, -1240, -1240,   245, -1240, -1240, -1240,
   -1240,    75, -1240, -1240, -1240, -1240,   720,   139, -1240, -1240,
   -1240, -1240,    64, -1240, -1240, -1240, -1240,    74, -1240, -1240,
   -1240, -1240,    72, -1240, -1240, -1240, -1240,   142, -1240, -1240,
   -1240, -1240,    92, -1240, -1240, -1240, -1240,   721,   405, -1240,
   -1240, -1240, -1240,   -84, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   604,   364, -1240, -1240, -1240, -1240, -1240, -1240,   581,
   -1240, -1240,   390, -1240, -1240, -1240,   726, -1240,   729, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   436,
     704, -1240,   583, -1240, -1240,   725,   727,   728, -1240,   672,
   -1240, -1240, -1240,   731, -1240,   732,   -50, -1240,   733,   734,
   -1240,   286, -1240, -1240,   251, -1240,   247, -1240,   154,   735,
   -1240, -1240,   143, -1240, -1240, -1240, -1240,    79, -1240, -1240,
   -1240,    78, -1240, -1240, -1240,    82, -1240, -1240, -1240,   192,
   -1240,   205,   737, -1240,   736,   499, -1240, -1240, -1240,   624,
     364, -1240,   581, -1240, -1240, -1240, -1240,   739,   741, -1240,
     632,   713, -1240,   587, -1240, -1240,   746,   670, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,   749, -1240, -1240,
   -1240,   750, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
     589,   344, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   751, -1240, -1240,   581, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240,   722, -1240,   591, -1240, -1240,   752,   646, -1240,
   -1240, -1240, -1240, -1240, -1240,   449,   671,   543,   420,   690,
     689, -1240, -1240,   761,   762,   763, -1240, -1240, -1240, -1240,
     676, -1240, -1240,   593, -1240,   764,   652, -1240, -1240, -1240,
   -1240, -1240, -1240,   468,   674,   553, -1240, -1240, -1240,   678,
     543,   765,   595, -1240, -1240, -1240, -1240,   767,   768,   769,
   -1240,   772, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   480,
     680,   568, -1240, -1240, -1240,   681,   553,   774,   597, -1240,
   -1240,   683,   601,   603, -1240,   777,   -56, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240,   497, -1240, -1240, -1240,   682,
     568,   778,   609, -1240, -1240, -1240,   611,   613, -1240,   783,
     -38, -1240, -1240, -1240, -1240, -1240,   686,   543,   466, -1240,
   -1240, -1240, -1240,   -46, -1240, -1240, -1240, -1240,   784, -1240,
   -1240,   691,   490, -1240, -1240, -1240, -1240, -1240, -1240,   407,
   -1240, -1240,   615,   617, -1240,   789,   -58, -1240, -1240, -1240,
   -1240,   456,   466, -1240, -1240, -1240, -1240,   -23, -1240, -1240,
   -1240, -1240,   790, -1240, -1240,   687,   500, -1240, -1240, -1240,
   -1240,   766,   619, -1240, -1240,   705,   481, -1240,   639, -1240,
   -1240,   708,   501, -1240, -1240, -1240, -1240, -1240,   621,   -51,
     795, -1240,   801, -1240,   804, -1240,   805,   623,   407, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,   472,   466, -1240, -1240, -1240, -1240,   -26,
   -1240, -1240, -1240, -1240,   803, -1240, -1240,   707,   518, -1240,
   -1240, -1240, -1240, -1240,   709,   481, -1240, -1240, -1240,   710,
     516, -1240, -1240, -1240, -1240, -1240,   625,   -51,   477,   807,
     627,   -60, -1240, -1240, -1240, -1240, -1240, -1240,   496, -1240,
     639,   811,   629, -1240, -1240, -1240,   631,   -51,   520, -1240,
   -1240,   812, -1240, -1240, -1240, -1240,   820,   819,   821,   822,
     115, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   724,
     481, -1240, -1240, -1240,   714,   535, -1240, -1240, -1240, -1240,
   -1240,   633,   -51,   635,   289, -1240,   496, -1240, -1240, -1240,
     637,    70,   534, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240,   830,   541, -1240, -1240, -1240, -1240, -1240, -1240,
     738,   537, -1240, -1240, -1240,   521, -1240,   639,   641,   832,
     694, -1240, -1240, -1240, -1240,   540, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,   834,   835, -1240, -1240, -1240, -1240, -1240,
     837, -1240,   740,   208, -1240, -1240, -1240, -1240,   643,   345,
   -1240,   496, -1240, -1240, -1240,   645,    73,   549, -1240, -1240,
   -1240, -1240, -1240, -1240,   -76, -1240, -1240, -1240, -1240,   839,
   -1240,   845, -1240,   846, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   521,
   -1240,   552, -1240, -1240, -1240, -1240,   847,   851, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
     647,   236,   848, -1240, -1240,   551, -1240, -1240, -1240, -1240,
     651,   -51, -1240,   531, -1240,   639,   653,   694, -1240, -1240,
   -1240, -1240,   850,   620, -1240,   711, -1240,   542, -1240,   852,
   -1240, -1240,   712, -1240, -1240,  -101, -1240, -1240, -1240, -1240,
   -1240,   858, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240,   521, -1240,   566, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   524,
     569, -1240, -1240,   723, -1240, -1240,   860,   862,   864,   531,
   -1240, -1240, -1240, -1240,   -74, -1240, -1240, -1240, -1240, -1240,
     865, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,   655,    56,   570,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,   545, -1240,   639,
     657,   694, -1240, -1240, -1240, -1240, -1240,   556, -1240,   866,
     659, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   539,
     585, -1240, -1240,   723,   871,   531, -1240, -1240,   491,   491,
   -1240, -1240,   663,    32, -1240,   665,   165,   874, -1240, -1240,
     545, -1240, -1240, -1240, -1240, -1240,   544,   580, -1240, -1240,
     723,   875,   -40, -1240, -1240, -1240, -1240, -1240,   878, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   557, -1240,
     639,   667,   694, -1240, -1240, -1240, -1240, -1240,   565, -1240,
     883,    58, -1240, -1240, -1240, -1240,   880,   442, -1240, -1240,
     673,    32, -1240,   545, -1240, -1240, -1240,   592, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,   694, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,   557, -1240, -1240,
   -1240,   675,    32, -1240, -1240,   -35,   888,   491, -1240, -1240,
   -1240,   639,   677,   694, -1240, -1240, -1240, -1240, -1240,   576,
   -1240,   889,   742, -1240,   890, -1240,   891,   892, -1240, -1240,
   -1240,   605, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   557, -1240, -1240, -1240, -1240,   745, -1240, -1240, -1240,
     598, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240,   897,   679,   694, -1240, -1240, -1240, -1240, -1240,
     571, -1240, -1240, -1240,   753,   900,   902, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240,   694, -1240, -1240, -1240, -1240, -1240,
     582, -1240, -1240,   901,   904, -1240,   584, -1240, -1240, -1240,
   -1240
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   870, -1240,
     893, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   854,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240,   512,  -355,  -409, -1240, -1240,  -513, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240,   780, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
     438, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   730, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,   348, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   616, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,   301, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   293, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   284,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,   285, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240,   283, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240,   272, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240,   269, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
      80, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240,    28, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
    -401, -1042, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240,  -222, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,  -393, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240,    50, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
     -25, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
    -293, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,   -10, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,   -75, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,  -361, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240,    24, -1240, -1240, -1240, -1240,
   -1240,  -140, -1240, -1240, -1240, -1240,  -250,  -325,  -419, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1206,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1205, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   -98, -1240,   -72,  -100, -1240, -1240, -1056, -1155, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,  -356,  -391, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1153,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,  -753, -1240, -1240, -1240, -1240, -1240,  -819, -1240, -1240,
   -1240, -1240, -1240,  -920, -1240, -1240, -1240, -1240, -1240, -1046,
   -1240, -1240, -1240, -1240, -1240, -1149, -1240, -1240, -1240, -1240,
   -1240, -1190, -1240, -1240, -1240, -1240, -1240, -1239, -1240, -1240,
   -1240, -1240, -1240,  -972,  -805, -1240,  -372,  -965, -1240,  -774,
   -1240,  -765, -1240, -1240,  -954, -1240, -1240,  -964, -1240, -1240,
   -1240, -1240, -1240,  -148, -1240, -1240,  -962, -1240, -1240,  -480,
   -1240, -1240, -1240, -1240, -1240,  -948, -1240, -1240,  -919, -1240,
   -1240,  -121, -1240, -1240,  -479, -1240, -1240, -1240, -1240, -1240
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     236,   479,   466,   591,   594,   804,   393,   468,  1058,  1159,
     256,   247,   244,  1036,  1286,   864,   473,   241,   614,    49,
     688,    50,   828,    51,    49,    52,    50,    53,    51,    54,
      52,   399,    53,  1069,    54,   132,   472,   133,   569,   134,
     657,   135,   215,   291,   849,   292,  1048,   293,  1134,  1135,
    1136,  1137,   240,   294,  1226,   295,   899,   296,   945,   297,
    1117,   298,  1422,   299,   579,   300,   665,   301,  1101,   302,
    1404,   303,   893,   304,   883,  1460,  1126,  1147,  1314,  1226,
     354,  1226,   361,  1240,   366,  1166,  1134,  1135,  1136,  1137,
    1321,   957,  1012,  1210,  1211,  1212,  1213,  1337,  1338,    55,
     570,   305,   216,   136,    55,  1127,  1130,  1382,  1383,   362,
     132,   367,   133,   639,   134,   496,   135,   215,   643,   956,
     473,   585,   586,   647,  1194,  1195,   348,  1200,  1357,  1303,
    1398,   587,   588,   380,   452,   611,  1027,   630,   460,   461,
     262,  1202,  1223,     7,   268,   630,   619,   630,  1314,   717,
     389,   630,   630,     6,   636,   630,  1374,   627,  1449,  1306,
     265,   662,    12,   619,   644,  1436,  1437,   259,   640,   702,
    1203,  1206,   704,   381,   706,  1314,   650,   216,   136,   497,
      17,  1011,    14,  1442,   263,   991,  1252,  1254,  1330,  1256,
     420,  1092,   269,  1280,   453,  1297,  1455,  1456,   608,  1418,
     390,   751,  1479,  1258,   585,   586,   266,  1273,   658,   260,
     676,    30,   630,   619,   587,   588,   630,   570,   639,   431,
    1423,   432,   643,   433,  1227,   619,   647,   631,   648,    41,
    1324,   698,  1259,   444,  1447,   446,   696,  1078,   946,    86,
    1298,   451,   585,   586,  1049,   585,   586,   400,   850,   714,
    1116,   124,   400,   168,   400,   438,   400,   440,   900,   442,
    1469,   624,   884,   619,  1049,  1228,   626,  1325,   991,  1049,
    1013,   628,  1079,  1080,   771,  1081,   619,   958,   708,   151,
     619,   727,   233,   234,  1193,    56,   615,   623,   615,   709,
     196,   137,   217,   306,   351,   352,   693,   649,   199,   693,
     202,   693,   651,   693,   203,   658,   991,  1351,    57,   991,
      58,  1489,    59,    57,    60,    58,   619,    59,   619,    60,
       1,     2,   619,   204,   693,   625,   693,   695,   981,   694,
     205,  1495,   755,   233,   234,   590,   233,   234,    20,    21,
     585,   586,   766,   245,   248,   257,   242,   587,   588,   410,
     587,   588,   411,   619,   206,   412,   207,   619,   620,  1384,
     225,   781,   692,  1159,   250,  1079,  1080,   291,  1081,   292,
     792,   293,   743,   744,   745,    25,    26,   294,  1412,   295,
     271,   296,   284,   297,   285,   298,  1253,   299,   287,   300,
     288,   301,   286,   302,   340,   303,   816,   304,    33,    34,
    1109,   349,   911,   912,   233,   234,   913,   914,   585,   586,
     915,   916,  1110,  1111,    44,    45,   358,  1438,   587,   588,
     127,   128,   363,   855,   369,   305,  1249,  1250,   376,   994,
     995,   153,   154,   158,   159,   377,   163,   164,   368,  1463,
     171,   172,   176,   177,   394,   395,   396,   397,  1457,   181,
     182,   186,   187,  1109,   771,   911,   912,   233,   234,   913,
     914,   585,   586,   915,   916,  1110,  1111,   191,   192,   210,
     211,   587,   588,   233,   234,   251,   252,  1112,  1113,   272,
     273,   279,   280,   342,   343,   371,   372,  1037,  1038,   405,
     406,   351,   352,   421,   422,   455,   456,   460,   461,   491,
     492,   653,   654,  1345,   797,   500,   501,  1070,  1071,  1109,
     378,   911,   912,   233,   234,   913,   914,   585,   586,   915,
     916,  1110,  1111,   506,   507,   511,   512,   587,   588,   516,
     517,  1190,  1191,   521,   522,   527,   528,   532,   533,   537,
     538,   379,  1102,  1103,  1122,  1128,   542,   543,   547,   548,
     383,  1148,    87,   384,    88,    89,    90,   821,    91,    92,
      93,   386,    94,    95,    96,   385,    97,    98,    99,   388,
     100,   101,   910,   911,   912,   233,   234,   913,   914,   585,
     586,   915,   916,   552,   553,   558,   559,   563,   564,   587,
     588,   582,   583,   677,   678,   712,   654,   728,   729,   740,
     741,   756,   757,   782,   783,   806,   807,   830,   831,  1201,
    1204,   838,   839,   843,   844,   387,  1224,   856,   857,   866,
     867,   872,   873,   877,   878,   934,   935,   939,   940,   971,
     972,   988,   989,  1000,  1001,  1032,  1033,  1043,  1044,  1060,
    1061,  1065,  1066,  1097,  1098,  1104,  1105,  1131,  1132,  1153,
    1154,  1167,  1168,  1185,  1186,  1207,  1208,  1244,  1245,  1265,
    1154,  1269,  1270,  1281,  1282,  1332,  1333,  1352,  1353,  1361,
    1362,  1257,  1260,  1377,  1378,  1387,  1388,  1413,  1414,  1426,
    1427,  1274,  1275,  1431,  1432,  1450,  1451,  1464,  1465,  1484,
    1485,   392,   426,   417,   429,   464,   469,   434,   477,   470,
     447,   484,   478,   480,   400,   488,   489,   490,   499,   505,
     526,   557,   574,   568,   575,   597,   576,   598,   580,   601,
     577,   605,   606,   607,   613,   618,   629,   652,   663,   667,
     578,   666,   668,   682,   669,   683,   684,   612,   685,   686,
     672,   690,   687,   697,   691,   710,   711,   718,   715,   719,
     723,   720,   733,   738,   739,   750,   767,   762,   761,   774,
     752,   771,   775,   776,   777,   778,   779,   788,   797,   734,
     787,   793,   768,   805,   780,   811,   812,   813,   814,   817,
     821,   800,   829,   848,   824,   860,   865,   794,   835,   882,
     894,   906,   905,   889,   850,   944,   951,   818,   963,   964,
     884,   977,   981,   996,   997,   900,   969,   998,   999,   976,
     984,  1018,  1006,  1025,   946,  1042,   958,  1039,  1054,  1059,
    1073,  1308,  1309,  1019,  1028,  1072,  1074,  1075,  1090,  1076,
    1077,  1013,  1093,  1385,  1386,  1149,  1152,  1395,  1172,  1162,
    1179,  1049,  1181,  1180,  1158,  1178,  1225,  1236,  1237,  1238,
    1242,  1322,  1323,  1241,  1243,  1173,  1264,  1276,  1288,  1289,
    1295,  1304,  1183,  1307,  1291,  1310,  1317,  1294,  1331,  1227,
    1318,  1296,  1319,  1347,  1360,  1346,  1118,  1359,  1226,  1372,
    1368,  1297,  1396,  1403,  1324,  1399,  1407,  1408,  1420,  1421,
    1424,  1439,  1440,  1445,  1461,  1471,  1474,  1472,  1491,  1475,
    1476,  1480,  1477,  1481,  1473,  1483,  1493,  1492,  1494,  1498,
     123,  1497,  1499,   581,   481,  1500,   152,   689,    40,   226,
     664,   703,  1458,  1459,   418,   699,   705,   713,   707,   716,
     985,  1405,   907,  1266,  1400,  1029,   965,  1311,  1020,  1369,
    1094,  1199,  1005,  1184,  1393,     0,  1406,     0,     0,   341,
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
     148,   392,   358,   483,   483,   770,     8,   363,   980,  1051,
       4,     4,     4,   967,  1167,   820,   371,     4,    70,    43,
      70,    45,   796,    47,    43,    49,    45,    51,    47,    53,
      49,   124,    51,   987,    53,    55,   124,    57,   124,    59,
     124,    61,    63,    65,   100,    67,   106,    69,    16,    17,
      18,    19,   150,    75,   155,    77,   102,    79,   116,    81,
    1024,    83,     4,    85,   473,    87,   579,    89,  1022,    91,
     110,    93,   837,    95,   112,   110,  1024,  1031,  1233,   155,
     228,   155,   230,  1129,   232,  1057,    16,    17,    18,    19,
    1239,   114,   118,    20,    21,    22,    23,    41,    42,   123,
     455,   123,   123,   123,   123,  1024,  1026,  1313,  1313,   230,
      55,   232,    57,   532,    59,     4,    61,    63,   537,   872,
     475,   172,   173,   542,  1089,  1089,   224,  1089,  1281,  1185,
    1320,   182,   183,     4,     4,   491,   955,    73,     6,     7,
       4,  1089,  1096,   125,     4,    73,    71,    73,  1303,   662,
       4,    73,    73,     0,    90,    73,  1305,    82,  1397,  1205,
       4,   570,    14,    71,    92,  1371,  1371,     4,    94,    90,
    1089,  1091,    94,    44,    92,  1330,    84,   123,   123,    68,
     308,   934,    15,  1373,    48,   236,  1151,  1151,  1244,  1151,
     311,  1010,    52,  1165,    64,   296,  1402,  1402,    66,  1352,
      54,   714,  1441,  1151,   172,   173,    50,  1161,   563,    46,
     601,   310,    73,    71,   182,   183,    73,   572,   637,   319,
     162,   321,   641,   323,   300,    71,   645,    88,    86,   312,
     304,    88,  1151,   333,  1387,   335,    82,   122,   296,   126,
     341,   339,   172,   173,   304,   172,   173,   340,   304,   658,
    1024,   314,   340,    27,   340,   327,   340,   329,   304,   331,
    1413,   511,   300,    71,   304,   341,   516,   341,   236,   304,
     296,   521,   157,   158,   218,   160,    71,   300,    86,   309,
      71,   672,   168,   169,  1089,   309,   338,    78,   338,    84,
      26,   311,   313,   315,   180,   181,   621,   547,    39,   624,
       5,   626,   552,   628,     5,   660,   236,  1279,   332,   236,
     334,  1464,   336,   332,   338,   334,    71,   336,    71,   338,
      12,    13,    71,     5,   649,    80,   651,    80,   163,    78,
       5,  1484,   723,   168,   169,   483,   168,   169,    10,    11,
     172,   173,   733,   335,   337,   339,   333,   182,   183,   211,
     182,   183,   214,    71,     5,   217,   316,    71,    76,  1313,
     311,   752,    76,  1405,     3,   157,   158,    65,   160,    67,
     761,    69,    28,    29,    30,    10,    11,    75,  1350,    77,
       3,    79,   128,    81,   132,    83,  1151,    85,   140,    87,
     144,    89,   136,    91,   313,    93,   787,    95,    10,    11,
     164,    10,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,    10,    11,    10,  1371,   182,   183,
      10,    11,    10,   814,    10,   123,   190,   191,   333,   909,
     909,    10,    11,    10,    11,   335,    10,    11,     3,  1411,
      10,    11,    10,    11,   446,   447,   448,   449,  1402,    10,
      11,    10,    11,   164,   218,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    10,    11,    10,
      11,   182,   183,   168,   169,    10,    11,   188,   189,    10,
      11,    10,    11,    10,    11,    10,    11,   967,   967,    10,
      11,   180,   181,    10,    11,    10,    11,     6,     7,    10,
      11,    96,    97,  1268,   215,    10,    11,   987,   987,   164,
     337,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,    10,    11,    10,    11,   182,   183,    10,
      11,   186,   187,    10,    11,    10,    11,    10,    11,    10,
      11,     8,  1022,  1022,  1024,  1024,    10,    11,    10,    11,
     339,  1031,   127,    46,   129,   130,   131,   212,   133,   134,
     135,    50,   137,   138,   139,    48,   141,   142,   143,     8,
     145,   146,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,    10,    11,    10,    11,    10,    11,   182,
     183,    10,    11,    10,    11,    96,    97,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,  1089,
    1089,    10,    11,    10,    11,    52,  1096,   120,   121,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   108,
     109,    10,    11,    10,    11,    10,    11,    10,    11,   108,
     109,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,  1151,  1151,    10,    11,    10,    11,    10,    11,   237,
     238,  1161,  1161,    10,    11,    10,    11,    10,    11,    10,
      11,     6,    31,   315,    32,     3,     8,    33,    44,     6,
      34,   306,    54,   124,   340,     8,     8,     8,     8,     8,
       8,     8,    56,    64,     8,   317,    58,   302,   124,    35,
      60,     6,     6,     6,     6,     6,     6,     6,   124,     3,
      62,   341,     3,     8,   298,     8,     8,    68,    66,     8,
      36,     8,    10,     8,    10,     8,    10,     8,   124,     8,
      37,   119,     6,     4,     4,     4,   307,   111,     6,   339,
      38,   218,    72,    74,     3,     3,     3,   115,   215,    99,
       6,   303,   101,     8,    98,     8,     8,     8,     6,   299,
     212,   103,     8,     6,   103,   103,     8,   113,   105,     6,
     324,   100,     8,   107,   304,     6,   340,   117,     8,   112,
     300,   320,   163,     8,     3,   304,    40,     3,     3,   104,
     102,     8,   340,   104,   296,     8,   300,   340,   322,     8,
       8,  1212,  1213,   116,   114,   305,     6,     8,   104,     8,
       8,   296,   118,  1313,  1313,   301,     6,  1316,     6,   318,
       6,   304,     5,     8,   106,   305,   297,     8,     3,     3,
       3,  1242,  1243,   301,     3,   161,     8,   326,     8,   239,
       8,     3,   122,   297,   153,   341,     6,   325,     3,   300,
       8,   159,     8,   328,     8,   305,  1024,   321,   155,     8,
     341,   296,     8,     8,   304,   341,     8,   330,   323,     6,
      10,  1371,  1371,   301,     6,   319,     6,     8,   327,     8,
       8,   156,   297,   305,   162,     8,     6,   154,     6,     8,
      40,   329,     8,   475,   402,   331,    62,   616,    25,   139,
     572,   637,  1402,  1402,   308,   632,   641,   655,   645,   660,
     902,  1332,   852,  1155,  1327,   960,   886,  1230,   948,  1300,
    1015,  1089,   918,  1083,  1316,    -1,  1337,    -1,    -1,   219,
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
       0,    12,    13,   451,   452,   453,     0,   125,   460,   461,
    1041,  1042,    14,   454,    15,   458,   459,   308,   462,   463,
      10,    11,  1043,  1044,  1045,    10,    11,   455,   456,   457,
     310,   548,   549,    10,    11,   464,   465,   466,  1046,  1047,
     460,   312,   591,   592,    10,    11,   550,   551,   552,    43,
      45,    47,    49,    51,    53,   123,   309,   332,   334,   336,
     338,   467,   468,   469,   470,   471,   476,   477,   482,   483,
     488,   489,   496,   497,   502,   503,   508,   509,   514,   515,
     520,   521,   526,   527,   534,   535,   126,   127,   129,   130,
     131,   133,   134,   135,   137,   138,   139,   141,   142,   143,
     145,   146,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,
    1066,  1067,  1068,   458,   314,   614,   615,    10,    11,   593,
     594,   595,    55,    57,    59,    61,   123,   311,   553,   554,
     555,   556,   557,   563,   564,   570,   571,   577,   578,   582,
     583,   309,   469,    10,    11,   472,   473,   474,    10,    11,
     478,   479,   480,    10,    11,   484,   485,   486,    27,   490,
     491,    10,    11,   498,   499,   500,    10,    11,   504,   505,
     506,    10,    11,   510,   511,   512,    10,    11,   516,   517,
     518,    10,    11,   522,   523,   524,    26,   528,   529,    39,
     536,  1021,     5,     5,     5,     5,     5,   316,   725,   726,
      10,    11,   616,   617,   618,    63,   123,   313,   596,   597,
     598,   599,   600,   605,   606,   311,   555,   558,   559,   565,
     566,   572,   573,   168,   169,   579,  1143,  1144,  1145,   584,
    1021,     4,   333,   475,     4,   335,   481,     4,   337,   487,
       3,    10,    11,   492,   493,   494,     4,   339,   501,     4,
      46,   507,     4,    48,   513,     4,    50,   519,     4,    52,
     525,     3,    10,    11,   530,   531,   532,  1038,  1039,    10,
      11,   537,   538,   539,   128,   132,   136,   140,   144,   727,
     728,    65,    67,    69,    75,    77,    79,    81,    83,    85,
      87,    89,    91,    93,    95,   123,   315,   619,   620,   621,
     622,   623,   630,   631,   636,   637,   644,   645,   649,   650,
     654,   655,   659,   660,   664,   665,   672,   673,   680,   681,
     688,   689,   696,   697,   702,   703,   708,   709,   716,   717,
     313,   598,    10,    11,   601,   602,   603,   607,  1021,    10,
     561,   180,   181,   560,  1143,  1161,  1162,  1163,    10,   568,
     567,  1143,  1161,    10,   575,   574,  1143,  1161,     3,    10,
     580,    10,    11,   585,   586,   587,   333,   335,   337,     8,
       4,    44,   495,   339,    46,    48,    50,    52,     8,     4,
      54,   533,     6,     8,   446,   447,   448,   449,  1040,   124,
     340,   540,   541,   542,   543,    10,    11,   730,   731,   732,
     211,   214,   217,   729,  1125,  1130,  1132,   315,   621,   624,
    1161,    10,    11,   632,   633,   634,    31,   638,  1018,    32,
    1024,  1024,  1024,  1024,    33,   666,  1023,   674,  1023,   682,
    1023,   690,  1023,   698,  1024,   704,  1024,    34,   710,  1025,
     718,  1021,     4,    64,   604,    10,    11,   608,   609,   610,
       6,     7,   562,  1037,     3,   569,  1037,   576,  1037,     8,
       6,   581,   124,   543,   588,   589,   590,    44,    54,  1038,
     124,   542,   544,   545,   306,   733,   734,   735,     8,     8,
       8,    10,    11,   625,   626,   627,     4,    68,   635,     8,
      10,    11,   639,   640,   641,     8,    10,    11,   646,   647,
     648,    10,    11,   651,   652,   653,    10,    11,   656,   657,
     658,    10,    11,   661,   662,   663,     8,    10,    11,   667,
     668,   669,    10,    11,   675,   676,   677,    10,    11,   683,
     684,   685,    10,    11,   691,   692,   693,    10,    11,   699,
     700,   701,    10,    11,   705,   706,   707,     8,    10,    11,
     711,   712,   713,    10,    11,   719,   720,   721,    64,   124,
     543,   611,   612,   613,    56,     8,    58,    60,    62,   544,
     124,   590,    10,    11,   547,   172,   173,   182,   183,   546,
    1143,  1149,  1150,  1151,  1164,  1165,  1166,   317,   302,   830,
     831,    35,   736,   737,  1022,     6,     6,     6,    66,   628,
     629,  1037,    68,     6,    70,   338,   642,   643,     6,    71,
      76,   986,   987,    78,   986,    80,   986,    82,   986,     6,
      73,    88,   670,   671,   988,   989,    90,   678,   679,   988,
      94,   686,   687,   988,    92,   694,   695,   988,    86,   986,
      84,   986,     6,    96,    97,   714,   715,   124,   543,   722,
     723,   724,   544,   124,   613,   547,   341,     3,     3,   298,
     897,   898,    36,   832,   833,  1020,  1038,    10,    11,   738,
     739,   740,     8,     8,     8,    66,     8,    10,    70,   643,
       8,    10,    76,   987,    78,    80,    82,     8,    88,   671,
     990,   991,    90,   679,    94,   687,    92,   695,    86,    84,
       8,    10,    96,   715,   544,   124,   724,   547,     8,     8,
     119,   964,   965,    37,   899,   900,  1019,  1038,    10,    11,
     834,   835,   836,     6,    99,   741,   742,   743,     4,     4,
      10,    11,   996,    28,    29,    30,   992,   993,   994,   995,
       4,   547,    38,   966,  1026,  1038,    10,    11,   901,   902,
     903,     6,   111,   837,   838,   839,  1038,   307,   101,   756,
     757,   218,   744,  1131,   339,    72,    74,     3,     3,     3,
      98,  1038,    10,    11,   967,   968,   969,     6,   115,   904,
     905,   906,  1038,   303,   113,   852,   853,   215,   840,  1129,
     103,   770,   771,   758,  1131,     8,    10,    11,   745,   746,
     747,     8,     8,     8,     6,   970,  1038,   299,   117,   919,
     920,   212,   907,  1124,   103,   866,   867,   854,  1129,     8,
      10,    11,   841,   842,   843,   105,   783,   784,    10,    11,
     772,   773,   774,    10,    11,   759,   760,   761,     6,   100,
     304,   748,   749,   750,   751,  1038,   120,   121,   971,   972,
     103,   933,   934,   921,  1124,     8,    10,    11,   908,   909,
     910,   879,    10,    11,   868,   869,   870,    10,    11,   855,
     856,   857,     6,   112,   300,   844,   845,   846,   847,   107,
     797,   798,   785,  1131,   324,   775,   776,  1081,  1082,   102,
     304,   762,   763,   764,   765,     8,   100,   750,   752,   753,
     165,   166,   167,   170,   171,   174,   175,   973,   974,   975,
    1128,  1137,  1138,  1139,  1143,  1149,  1155,  1156,  1157,  1158,
    1159,  1160,  1164,   946,    10,    11,   935,   936,   937,    10,
      11,   922,   923,   924,     6,   116,   296,   911,   912,   913,
     914,   340,   880,   881,   871,   872,  1081,   114,   300,   858,
     859,   860,   861,     8,   112,   846,   848,   849,   812,    40,
     799,    10,    11,   786,   787,   788,   104,   320,   777,  1087,
    1088,   163,  1123,  1126,   102,   764,   766,   767,    10,    11,
     755,   236,   754,  1134,  1149,  1164,     8,     3,     3,     3,
      10,    11,   976,   977,   978,   975,   340,   947,   948,   938,
     939,  1081,   118,   296,   925,   926,   927,   928,     8,   116,
     913,   915,   916,   882,   883,   104,   873,  1087,   114,   860,
     862,   863,    10,    11,   851,   850,  1134,  1149,  1164,   340,
     813,   814,     8,    10,    11,   800,   801,   802,   106,   304,
     789,   790,   791,   792,   322,   778,  1093,  1094,  1123,     8,
      10,    11,  1083,  1084,  1085,    10,    11,   769,   768,  1134,
    1149,  1164,   305,     8,     6,     8,     8,     8,   122,   157,
     158,   160,   979,   980,   981,   982,   983,   984,   949,   950,
     104,   940,  1087,   118,   927,   929,   930,    10,    11,   918,
     917,  1134,  1149,  1164,    10,    11,   885,   886,   887,   164,
     176,   177,   188,   189,   884,  1127,  1129,  1137,  1143,  1146,
    1147,  1148,  1149,  1152,  1153,  1154,  1155,  1158,  1164,   874,
    1093,    10,    11,   865,    16,    17,    18,    19,   864,   999,
    1000,  1001,  1002,  1010,  1011,  1012,  1013,  1134,  1149,   301,
     815,   816,     6,   108,   109,   803,   804,   805,   106,   791,
     793,   794,   318,   779,  1099,  1100,  1123,    10,    11,  1089,
    1090,  1091,     6,   161,  1069,  1070,  1077,  1086,   305,     6,
       8,     5,   985,   122,   981,    10,    11,   952,   953,   954,
     186,   187,   951,  1124,  1127,  1137,  1140,  1141,  1142,  1143,
    1146,  1149,  1155,  1158,  1164,   941,  1093,    10,    11,   932,
      20,    21,    22,    23,   931,  1003,  1004,  1005,  1006,  1014,
    1015,  1016,  1017,  1134,  1149,   297,   155,   300,   341,   888,
     889,   890,   891,  1027,  1028,  1029,     8,     3,     3,   875,
    1099,   301,     3,     3,    10,    11,   818,   819,   820,   190,
     191,   817,  1127,  1131,  1137,  1143,  1146,  1149,  1155,  1158,
    1164,  1167,  1168,  1169,     8,   108,   804,   806,   807,    10,
      11,   796,   795,  1134,  1149,  1164,   326,   780,  1105,  1106,
    1123,    10,    11,  1095,  1096,  1097,  1069,  1092,     8,   239,
    1133,   153,  1071,  1072,   325,     8,   159,   296,   341,   955,
     956,   957,   958,  1027,     3,   942,  1099,   297,  1038,  1038,
     341,   890,   892,   893,  1028,  1030,  1031,     6,     8,     8,
     876,  1105,  1038,  1038,   304,   341,   821,   822,   823,   824,
    1027,     3,    10,    11,   809,   810,   811,    41,    42,   808,
     997,   998,  1007,  1008,  1009,  1131,   305,   328,   781,  1111,
    1112,  1123,    10,    11,  1101,  1102,  1103,  1069,  1098,   321,
       8,    10,    11,  1078,  1079,  1080,  1073,  1074,   341,   957,
     959,   960,     8,   943,  1105,  1037,  1037,    10,    11,   895,
     896,   894,   999,  1010,  1134,  1149,  1164,    10,    11,  1033,
    1034,  1035,  1032,  1126,  1143,  1164,     8,   877,  1111,   341,
     823,   825,   826,     8,   110,   790,  1038,     8,   330,   782,
    1117,  1118,  1123,    10,    11,  1107,  1108,  1109,  1069,  1104,
     323,     6,     4,   162,    10,  1076,   237,   238,  1075,  1135,
    1136,    10,    11,   962,   963,   961,   999,  1010,  1134,  1149,
    1164,   944,  1111,  1038,  1038,   301,  1036,  1069,   878,  1117,
      10,    11,   828,   829,   827,   999,  1010,  1134,  1149,  1164,
     110,     6,  1037,  1123,    10,    11,  1113,  1114,  1115,  1069,
    1110,   319,     8,   162,     6,     8,     8,   297,   945,  1117,
     156,   305,  1038,     8,    10,    11,  1119,  1120,  1121,  1069,
    1116,   327,   154,     6,     6,  1069,  1122,   329,     8,     8,
     331
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
        if (osglData->idxPresent == true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one idx attribute");
        osglData->idxPresent = true;
        if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
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


