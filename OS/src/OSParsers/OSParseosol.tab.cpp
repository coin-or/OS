
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
     NUMBEROFOTHEROPTIONSATT = 271,
     NUMBEROFENUMERATIONSATT = 272,
     NUMBEROFJOBIDSATT = 273,
     NUMBEROFPATHSATT = 274,
     NUMBEROFPATHPAIRSATT = 275,
     FROMATT = 276,
     TOATT = 277,
     MAKECOPYATT = 278,
     CATEGORYATT = 279,
     TYPEATT = 280,
     GROUPWEIGHTATT = 281,
     NUMBEROFPROCESSESATT = 282,
     NUMBEROFSOLVEROPTIONSATT = 283,
     NUMBEROFSOSATT = 284,
     NUMBEROFVARIABLESATT = 285,
     NUMBEROFOBJECTIVESATT = 286,
     NUMBEROFCONSTRAINTSATT = 287,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 288,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 289,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 290,
     NUMBEROFITEMSATT = 291,
     NUMBEROFVARATT = 292,
     NUMBEROFOBJATT = 293,
     NUMBEROFCONATT = 294,
     NUMBEROFELATT = 295,
     NAMEATT = 296,
     IDXATT = 297,
     SOSIDXATT = 298,
     VALUEATT = 299,
     UNITATT = 300,
     DESCRIPTIONATT = 301,
     CONTYPEATT = 302,
     EMPTYCONTYPEATT = 303,
     ENUMTYPEATT = 304,
     EMPTYENUMTYPEATT = 305,
     OBJTYPEATT = 306,
     EMPTYOBJTYPEATT = 307,
     VARTYPEATT = 308,
     EMPTYVARTYPEATT = 309,
     EMPTYTYPEATT = 310,
     EMPTYNAMEATT = 311,
     EMPTYCATEGORYATT = 312,
     EMPTYDESCRIPTIONATT = 313,
     EMPTYUNITATT = 314,
     EMPTYVALUEATT = 315,
     EMPTYLBVALUEATT = 316,
     EMPTYUBVALUEATT = 317,
     LBVALUEATT = 318,
     UBVALUEATT = 319,
     EMPTYLBDUALVALUEATT = 320,
     EMPTYUBDUALVALUEATT = 321,
     LBDUALVALUEATT = 322,
     UBDUALVALUEATT = 323,
     SOLVERATT = 324,
     EMPTYSOLVERATT = 325,
     WEIGHTATT = 326,
     EMPTYWEIGHTATT = 327,
     TRANSPORTTYPEATT = 328,
     LOCATIONTYPEATT = 329,
     GENERALSTART = 330,
     GENERALEND = 331,
     SYSTEMSTART = 332,
     SYSTEMEND = 333,
     SERVICESTART = 334,
     SERVICEEND = 335,
     JOBSTART = 336,
     JOBEND = 337,
     OPTIMIZATIONSTART = 338,
     OPTIMIZATIONEND = 339,
     SERVICEURISTART = 340,
     SERVICEURIEND = 341,
     SERVICENAMESTART = 342,
     SERVICENAMEEND = 343,
     INSTANCENAMESTART = 344,
     INSTANCENAMEEND = 345,
     INSTANCELOCATIONSTART = 346,
     INSTANCELOCATIONEND = 347,
     JOBIDSTART = 348,
     JOBIDEND = 349,
     SOLVERTOINVOKESTART = 350,
     SOLVERTOINVOKEEND = 351,
     LICENSESTART = 352,
     LICENSEEND = 353,
     USERNAMESTART = 354,
     USERNAMEEND = 355,
     PASSWORDSTART = 356,
     PASSWORDEND = 357,
     CONTACTSTART = 358,
     CONTACTEND = 359,
     OTHEROPTIONSSTART = 360,
     OTHEROPTIONSEND = 361,
     OTHERSTART = 362,
     OTHEREND = 363,
     MINDISKSPACESTART = 364,
     MINDISKSPACEEND = 365,
     MINMEMORYSTART = 366,
     MINMEMORYEND = 367,
     MINCPUSPEEDSTART = 368,
     MINCPUSPEEDEND = 369,
     MINCPUNUMBERSTART = 370,
     MINCPUNUMBEREND = 371,
     SERVICETYPESTART = 372,
     SERVICETYPEEND = 373,
     MAXTIMESTART = 374,
     MAXTIMEEND = 375,
     REQUESTEDSTARTTIMESTART = 376,
     REQUESTEDSTARTTIMEEND = 377,
     DEPENDENCIESSTART = 378,
     DEPENDENCIESEND = 379,
     REQUIREDDIRECTORIESSTART = 380,
     REQUIREDDIRECTORIESEND = 381,
     REQUIREDFILESSTART = 382,
     REQUIREDFILESEND = 383,
     PATHSTART = 384,
     PATHEND = 385,
     PATHPAIRSTART = 386,
     PATHPAIREND = 387,
     DIRECTORIESTOMAKESTART = 388,
     DIRECTORIESTOMAKEEND = 389,
     FILESTOMAKESTART = 390,
     FILESTOMAKEEND = 391,
     DIRECTORIESTODELETESTART = 392,
     DIRECTORIESTODELETEEND = 393,
     FILESTODELETESTART = 394,
     FILESTODELETEEND = 395,
     INPUTDIRECTORIESTOMOVESTART = 396,
     INPUTDIRECTORIESTOMOVEEND = 397,
     INPUTFILESTOMOVESTART = 398,
     INPUTFILESTOMOVEEND = 399,
     OUTPUTDIRECTORIESTOMOVESTART = 400,
     OUTPUTDIRECTORIESTOMOVEEND = 401,
     OUTPUTFILESTOMOVESTART = 402,
     OUTPUTFILESTOMOVEEND = 403,
     PROCESSESTOKILLSTART = 404,
     PROCESSESTOKILLEND = 405,
     PROCESSSTART = 406,
     PROCESSEND = 407,
     VARIABLESSTART = 408,
     VARIABLESEND = 409,
     INITIALVARIABLEVALUESSTART = 410,
     INITIALVARIABLEVALUESEND = 411,
     VARSTART = 412,
     VAREND = 413,
     INITIALVARIABLEVALUESSTRINGSTART = 414,
     INITIALVARIABLEVALUESSTRINGEND = 415,
     INITIALBASISSTATUSSTART = 416,
     INITIALBASISSTATUSEND = 417,
     BASICSTART = 418,
     BASICEND = 419,
     ATUPPERSTART = 420,
     ATUPPEREND = 421,
     ATLOWERSTART = 422,
     ATLOWEREND = 423,
     ATEQUALITYSTART = 424,
     ATEQUALITYEND = 425,
     SUPERBASICSTART = 426,
     SUPERBASICEND = 427,
     ISFREESTART = 428,
     ISFREEEND = 429,
     UNKNOWNSTART = 430,
     UNKNOWNEND = 431,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 432,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 433,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 434,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 435,
     SOSSTART = 436,
     SOSEND = 437,
     OBJECTIVESSTART = 438,
     OBJECTIVESEND = 439,
     INITIALOBJECTIVEVALUESSTART = 440,
     INITIALOBJECTIVEVALUESEND = 441,
     OBJSTART = 442,
     OBJEND = 443,
     INITIALOBJECTIVEBOUNDSSTART = 444,
     INITIALOBJECTIVEBOUNDSEND = 445,
     CONSTRAINTSSTART = 446,
     CONSTRAINTSEND = 447,
     INITIALCONSTRAINTVALUESSTART = 448,
     INITIALCONSTRAINTVALUESEND = 449,
     CONSTART = 450,
     CONEND = 451,
     INITIALDUALVALUESSTART = 452,
     INITIALDUALVALUESEND = 453,
     SOLVEROPTIONSSTART = 454,
     SOLVEROPTIONSEND = 455,
     SOLVEROPTIONSTART = 456,
     SOLVEROPTIONEND = 457,
     ENUMERATIONSTART = 458,
     ENUMERATIONEND = 459,
     ITEMEMPTY = 460,
     ITEMSTART = 461,
     ITEMEND = 462,
     ITEMSTARTANDEND = 463,
     BASE64START = 464,
     BASE64END = 465,
     INCRATT = 466,
     MULTATT = 467,
     SIZEOFATT = 468,
     ELSTART = 469,
     ELEND = 470,
     MATRIXVARSTART = 471,
     MATRIXVAREND = 472,
     MATRIXOBJSTART = 473,
     MATRIXOBJEND = 474,
     MATRIXCONSTART = 475,
     MATRIXCONEND = 476,
     HEADERSTART = 477,
     HEADEREND = 478,
     FILENAMESTART = 479,
     FILENAMEEND = 480,
     FILENAMEEMPTY = 481,
     FILENAMESTARTANDEND = 482,
     FILESOURCESTART = 483,
     FILESOURCEEND = 484,
     FILESOURCEEMPTY = 485,
     FILESOURCESTARTANDEND = 486,
     FILEDESCRIPTIONSTART = 487,
     FILEDESCRIPTIONEND = 488,
     FILEDESCRIPTIONEMPTY = 489,
     FILEDESCRIPTIONSTARTANDEND = 490,
     FILECREATORSTART = 491,
     FILECREATOREND = 492,
     FILECREATOREMPTY = 493,
     FILECREATORSTARTANDEND = 494,
     FILELICENCESTART = 495,
     FILELICENCEEND = 496,
     FILELICENCEEMPTY = 497,
     FILELICENCESTARTANDEND = 498,
     MATRIXSTART = 499,
     MATRIXEND = 500,
     BASEMATRIXEND = 501,
     BASEMATRIXSTART = 502,
     BLOCKSTART = 503,
     BLOCKEND = 504,
     BLOCKSSTART = 505,
     BLOCKSEND = 506,
     EMPTYSHAPEATT = 507,
     SHAPEATT = 508,
     EMPTYSYMMETRYATT = 509,
     SYMMETRYATT = 510,
     EMPTYNEGATIVEPATTERNATT = 511,
     NEGATIVEPATTERNATT = 512,
     CONSTANTATT = 513,
     NUMBEROFBLOCKSATT = 514,
     NUMBEROFCOLUMNSATT = 515,
     NUMBEROFROWSATT = 516,
     NUMBEROFVALUESATT = 517,
     NUMBEROFVARIDXATT = 518,
     COEFATT = 519,
     BASEMATRIXIDXATT = 520,
     TARGETMATRIXFIRSTROWATT = 521,
     TARGETMATRIXFIRSTCOLATT = 522,
     BASEMATRIXSTARTROWATT = 523,
     BASEMATRIXSTARTCOLATT = 524,
     BASEMATRIXENDROWATT = 525,
     BASEMATRIXENDCOLATT = 526,
     SCALARMULTIPLIERATT = 527,
     EMPTYBASETRANSPOSEATT = 528,
     BASETRANSPOSEATT = 529,
     ELEMENTSSTART = 530,
     ELEMENTSEND = 531,
     CONSTANTELEMENTSSTART = 532,
     CONSTANTELEMENTSEND = 533,
     STARTVECTORSTART = 534,
     STARTVECTOREND = 535,
     NONZEROSSTART = 536,
     NONZEROSEND = 537,
     INDEXESSTART = 538,
     INDEXESEND = 539,
     VALUESSTART = 540,
     VALUESEND = 541,
     VARREFERENCEELEMENTSSTART = 542,
     VARREFERENCEELEMENTSEND = 543,
     LINEARELEMENTSSTART = 544,
     LINEARELEMENTSEND = 545,
     GENERALELEMENTSSTART = 546,
     GENERALELEMENTSEND = 547,
     CONREFERENCEELEMENTSSTART = 548,
     CONREFERENCEELEMENTSEND = 549,
     VALUETYPEATT = 550,
     OBJREFERENCEELEMENTSSTART = 551,
     OBJREFERENCEELEMENTSEND = 552,
     PATTERNELEMENTSSTART = 553,
     PATTERNELEMENTSEND = 554,
     VARIDXSTART = 555,
     VARIDXEND = 556,
     TRANSFORMATIONSTART = 557,
     TRANSFORMATIONEND = 558,
     COLOFFSETSSTART = 559,
     COLOFFSETSEND = 560,
     ROWOFFSETSSTART = 561,
     ROWOFFSETSEND = 562,
     EMPTYROWMAJORATT = 563,
     ROWMAJORATT = 564,
     BLOCKROWIDXATT = 565,
     BLOCKCOLIDXATT = 566,
     DUMMY = 567,
     NONLINEAREXPRESSIONSSTART = 568,
     NONLINEAREXPRESSIONSEND = 569,
     NUMBEROFNONLINEAREXPRESSIONS = 570,
     NLSTART = 571,
     NLEND = 572,
     MATRIXEXPRESSIONSSTART = 573,
     MATRIXEXPRESSIONSEND = 574,
     NUMBEROFEXPR = 575,
     EXPRSTART = 576,
     EXPREND = 577,
     NUMBEROFMATRIXTERMSATT = 578,
     MATRIXTERMSTART = 579,
     MATRIXTERMEND = 580,
     POWERSTART = 581,
     POWEREND = 582,
     PLUSSTART = 583,
     PLUSEND = 584,
     MINUSSTART = 585,
     MINUSEND = 586,
     DIVIDESTART = 587,
     DIVIDEEND = 588,
     LNSTART = 589,
     LNEND = 590,
     SQRTSTART = 591,
     SQRTEND = 592,
     SUMSTART = 593,
     SUMEND = 594,
     PRODUCTSTART = 595,
     PRODUCTEND = 596,
     EXPSTART = 597,
     EXPEND = 598,
     NEGATESTART = 599,
     NEGATEEND = 600,
     IFSTART = 601,
     IFEND = 602,
     SQUARESTART = 603,
     SQUAREEND = 604,
     COSSTART = 605,
     COSEND = 606,
     SINSTART = 607,
     SINEND = 608,
     VARIABLESTART = 609,
     VARIABLEEND = 610,
     ABSSTART = 611,
     ABSEND = 612,
     ERFSTART = 613,
     ERFEND = 614,
     MAXSTART = 615,
     MAXEND = 616,
     ALLDIFFSTART = 617,
     ALLDIFFEND = 618,
     MINSTART = 619,
     MINEND = 620,
     ESTART = 621,
     EEND = 622,
     PISTART = 623,
     PIEND = 624,
     TIMESSTART = 625,
     TIMESEND = 626,
     NUMBERSTART = 627,
     NUMBEREND = 628,
     MATRIXDETERMINANTSTART = 629,
     MATRIXDETERMINANTEND = 630,
     MATRIXTRACESTART = 631,
     MATRIXTRACEEND = 632,
     MATRIXTOSCALARSTART = 633,
     MATRIXTOSCALAREND = 634,
     MATRIXDIAGONALSTART = 635,
     MATRIXDIAGONALEND = 636,
     MATRIXDOTTIMESSTART = 637,
     MATRIXDOTTIMESEND = 638,
     MATRIXLOWERTRIANGLESTART = 639,
     MATRIXLOWERTRIANGLEEND = 640,
     MATRIXUPPERTRIANGLESTART = 641,
     MATRIXUPPERTRIANGLEEND = 642,
     MATRIXMERGESTART = 643,
     MATRIXMERGEEND = 644,
     MATRIXMINUSSTART = 645,
     MATRIXMINUSEND = 646,
     MATRIXNEGATESTART = 647,
     MATRIXNEGATEEND = 648,
     MATRIXPLUSSTART = 649,
     MATRIXPLUSEND = 650,
     MATRIXTIMESSTART = 651,
     MATRIXTIMESEND = 652,
     MATRIXPRODUCTSTART = 653,
     MATRIXPRODUCTEND = 654,
     MATRIXSCALARTIMESSTART = 655,
     MATRIXSCALARTIMESEND = 656,
     MATRIXSUBMATRIXATSTART = 657,
     MATRIXSUBMATRIXATEND = 658,
     MATRIXTRANSPOSESTART = 659,
     MATRIXTRANSPOSEEND = 660,
     MATRIXREFERENCESTART = 661,
     MATRIXREFERENCEEND = 662,
     IDENTITYMATRIXSTART = 663,
     IDENTITYMATRIXEND = 664,
     MATRIXINVERSESTART = 665,
     MATRIXINVERSEEND = 666,
     EMPTYINCLUDEDIAGONALATT = 667,
     INCLUDEDIAGONALATT = 668,
     IDATT = 669
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
#define NUMBEROFOTHEROPTIONSATT 271
#define NUMBEROFENUMERATIONSATT 272
#define NUMBEROFJOBIDSATT 273
#define NUMBEROFPATHSATT 274
#define NUMBEROFPATHPAIRSATT 275
#define FROMATT 276
#define TOATT 277
#define MAKECOPYATT 278
#define CATEGORYATT 279
#define TYPEATT 280
#define GROUPWEIGHTATT 281
#define NUMBEROFPROCESSESATT 282
#define NUMBEROFSOLVEROPTIONSATT 283
#define NUMBEROFSOSATT 284
#define NUMBEROFVARIABLESATT 285
#define NUMBEROFOBJECTIVESATT 286
#define NUMBEROFCONSTRAINTSATT 287
#define NUMBEROFOTHERVARIABLEOPTIONSATT 288
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 289
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 290
#define NUMBEROFITEMSATT 291
#define NUMBEROFVARATT 292
#define NUMBEROFOBJATT 293
#define NUMBEROFCONATT 294
#define NUMBEROFELATT 295
#define NAMEATT 296
#define IDXATT 297
#define SOSIDXATT 298
#define VALUEATT 299
#define UNITATT 300
#define DESCRIPTIONATT 301
#define CONTYPEATT 302
#define EMPTYCONTYPEATT 303
#define ENUMTYPEATT 304
#define EMPTYENUMTYPEATT 305
#define OBJTYPEATT 306
#define EMPTYOBJTYPEATT 307
#define VARTYPEATT 308
#define EMPTYVARTYPEATT 309
#define EMPTYTYPEATT 310
#define EMPTYNAMEATT 311
#define EMPTYCATEGORYATT 312
#define EMPTYDESCRIPTIONATT 313
#define EMPTYUNITATT 314
#define EMPTYVALUEATT 315
#define EMPTYLBVALUEATT 316
#define EMPTYUBVALUEATT 317
#define LBVALUEATT 318
#define UBVALUEATT 319
#define EMPTYLBDUALVALUEATT 320
#define EMPTYUBDUALVALUEATT 321
#define LBDUALVALUEATT 322
#define UBDUALVALUEATT 323
#define SOLVERATT 324
#define EMPTYSOLVERATT 325
#define WEIGHTATT 326
#define EMPTYWEIGHTATT 327
#define TRANSPORTTYPEATT 328
#define LOCATIONTYPEATT 329
#define GENERALSTART 330
#define GENERALEND 331
#define SYSTEMSTART 332
#define SYSTEMEND 333
#define SERVICESTART 334
#define SERVICEEND 335
#define JOBSTART 336
#define JOBEND 337
#define OPTIMIZATIONSTART 338
#define OPTIMIZATIONEND 339
#define SERVICEURISTART 340
#define SERVICEURIEND 341
#define SERVICENAMESTART 342
#define SERVICENAMEEND 343
#define INSTANCENAMESTART 344
#define INSTANCENAMEEND 345
#define INSTANCELOCATIONSTART 346
#define INSTANCELOCATIONEND 347
#define JOBIDSTART 348
#define JOBIDEND 349
#define SOLVERTOINVOKESTART 350
#define SOLVERTOINVOKEEND 351
#define LICENSESTART 352
#define LICENSEEND 353
#define USERNAMESTART 354
#define USERNAMEEND 355
#define PASSWORDSTART 356
#define PASSWORDEND 357
#define CONTACTSTART 358
#define CONTACTEND 359
#define OTHEROPTIONSSTART 360
#define OTHEROPTIONSEND 361
#define OTHERSTART 362
#define OTHEREND 363
#define MINDISKSPACESTART 364
#define MINDISKSPACEEND 365
#define MINMEMORYSTART 366
#define MINMEMORYEND 367
#define MINCPUSPEEDSTART 368
#define MINCPUSPEEDEND 369
#define MINCPUNUMBERSTART 370
#define MINCPUNUMBEREND 371
#define SERVICETYPESTART 372
#define SERVICETYPEEND 373
#define MAXTIMESTART 374
#define MAXTIMEEND 375
#define REQUESTEDSTARTTIMESTART 376
#define REQUESTEDSTARTTIMEEND 377
#define DEPENDENCIESSTART 378
#define DEPENDENCIESEND 379
#define REQUIREDDIRECTORIESSTART 380
#define REQUIREDDIRECTORIESEND 381
#define REQUIREDFILESSTART 382
#define REQUIREDFILESEND 383
#define PATHSTART 384
#define PATHEND 385
#define PATHPAIRSTART 386
#define PATHPAIREND 387
#define DIRECTORIESTOMAKESTART 388
#define DIRECTORIESTOMAKEEND 389
#define FILESTOMAKESTART 390
#define FILESTOMAKEEND 391
#define DIRECTORIESTODELETESTART 392
#define DIRECTORIESTODELETEEND 393
#define FILESTODELETESTART 394
#define FILESTODELETEEND 395
#define INPUTDIRECTORIESTOMOVESTART 396
#define INPUTDIRECTORIESTOMOVEEND 397
#define INPUTFILESTOMOVESTART 398
#define INPUTFILESTOMOVEEND 399
#define OUTPUTDIRECTORIESTOMOVESTART 400
#define OUTPUTDIRECTORIESTOMOVEEND 401
#define OUTPUTFILESTOMOVESTART 402
#define OUTPUTFILESTOMOVEEND 403
#define PROCESSESTOKILLSTART 404
#define PROCESSESTOKILLEND 405
#define PROCESSSTART 406
#define PROCESSEND 407
#define VARIABLESSTART 408
#define VARIABLESEND 409
#define INITIALVARIABLEVALUESSTART 410
#define INITIALVARIABLEVALUESEND 411
#define VARSTART 412
#define VAREND 413
#define INITIALVARIABLEVALUESSTRINGSTART 414
#define INITIALVARIABLEVALUESSTRINGEND 415
#define INITIALBASISSTATUSSTART 416
#define INITIALBASISSTATUSEND 417
#define BASICSTART 418
#define BASICEND 419
#define ATUPPERSTART 420
#define ATUPPEREND 421
#define ATLOWERSTART 422
#define ATLOWEREND 423
#define ATEQUALITYSTART 424
#define ATEQUALITYEND 425
#define SUPERBASICSTART 426
#define SUPERBASICEND 427
#define ISFREESTART 428
#define ISFREEEND 429
#define UNKNOWNSTART 430
#define UNKNOWNEND 431
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 432
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 433
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 434
#define SOSVARIABLEBRANCHINGWEIGHTSEND 435
#define SOSSTART 436
#define SOSEND 437
#define OBJECTIVESSTART 438
#define OBJECTIVESEND 439
#define INITIALOBJECTIVEVALUESSTART 440
#define INITIALOBJECTIVEVALUESEND 441
#define OBJSTART 442
#define OBJEND 443
#define INITIALOBJECTIVEBOUNDSSTART 444
#define INITIALOBJECTIVEBOUNDSEND 445
#define CONSTRAINTSSTART 446
#define CONSTRAINTSEND 447
#define INITIALCONSTRAINTVALUESSTART 448
#define INITIALCONSTRAINTVALUESEND 449
#define CONSTART 450
#define CONEND 451
#define INITIALDUALVALUESSTART 452
#define INITIALDUALVALUESEND 453
#define SOLVEROPTIONSSTART 454
#define SOLVEROPTIONSEND 455
#define SOLVEROPTIONSTART 456
#define SOLVEROPTIONEND 457
#define ENUMERATIONSTART 458
#define ENUMERATIONEND 459
#define ITEMEMPTY 460
#define ITEMSTART 461
#define ITEMEND 462
#define ITEMSTARTANDEND 463
#define BASE64START 464
#define BASE64END 465
#define INCRATT 466
#define MULTATT 467
#define SIZEOFATT 468
#define ELSTART 469
#define ELEND 470
#define MATRIXVARSTART 471
#define MATRIXVAREND 472
#define MATRIXOBJSTART 473
#define MATRIXOBJEND 474
#define MATRIXCONSTART 475
#define MATRIXCONEND 476
#define HEADERSTART 477
#define HEADEREND 478
#define FILENAMESTART 479
#define FILENAMEEND 480
#define FILENAMEEMPTY 481
#define FILENAMESTARTANDEND 482
#define FILESOURCESTART 483
#define FILESOURCEEND 484
#define FILESOURCEEMPTY 485
#define FILESOURCESTARTANDEND 486
#define FILEDESCRIPTIONSTART 487
#define FILEDESCRIPTIONEND 488
#define FILEDESCRIPTIONEMPTY 489
#define FILEDESCRIPTIONSTARTANDEND 490
#define FILECREATORSTART 491
#define FILECREATOREND 492
#define FILECREATOREMPTY 493
#define FILECREATORSTARTANDEND 494
#define FILELICENCESTART 495
#define FILELICENCEEND 496
#define FILELICENCEEMPTY 497
#define FILELICENCESTARTANDEND 498
#define MATRIXSTART 499
#define MATRIXEND 500
#define BASEMATRIXEND 501
#define BASEMATRIXSTART 502
#define BLOCKSTART 503
#define BLOCKEND 504
#define BLOCKSSTART 505
#define BLOCKSEND 506
#define EMPTYSHAPEATT 507
#define SHAPEATT 508
#define EMPTYSYMMETRYATT 509
#define SYMMETRYATT 510
#define EMPTYNEGATIVEPATTERNATT 511
#define NEGATIVEPATTERNATT 512
#define CONSTANTATT 513
#define NUMBEROFBLOCKSATT 514
#define NUMBEROFCOLUMNSATT 515
#define NUMBEROFROWSATT 516
#define NUMBEROFVALUESATT 517
#define NUMBEROFVARIDXATT 518
#define COEFATT 519
#define BASEMATRIXIDXATT 520
#define TARGETMATRIXFIRSTROWATT 521
#define TARGETMATRIXFIRSTCOLATT 522
#define BASEMATRIXSTARTROWATT 523
#define BASEMATRIXSTARTCOLATT 524
#define BASEMATRIXENDROWATT 525
#define BASEMATRIXENDCOLATT 526
#define SCALARMULTIPLIERATT 527
#define EMPTYBASETRANSPOSEATT 528
#define BASETRANSPOSEATT 529
#define ELEMENTSSTART 530
#define ELEMENTSEND 531
#define CONSTANTELEMENTSSTART 532
#define CONSTANTELEMENTSEND 533
#define STARTVECTORSTART 534
#define STARTVECTOREND 535
#define NONZEROSSTART 536
#define NONZEROSEND 537
#define INDEXESSTART 538
#define INDEXESEND 539
#define VALUESSTART 540
#define VALUESEND 541
#define VARREFERENCEELEMENTSSTART 542
#define VARREFERENCEELEMENTSEND 543
#define LINEARELEMENTSSTART 544
#define LINEARELEMENTSEND 545
#define GENERALELEMENTSSTART 546
#define GENERALELEMENTSEND 547
#define CONREFERENCEELEMENTSSTART 548
#define CONREFERENCEELEMENTSEND 549
#define VALUETYPEATT 550
#define OBJREFERENCEELEMENTSSTART 551
#define OBJREFERENCEELEMENTSEND 552
#define PATTERNELEMENTSSTART 553
#define PATTERNELEMENTSEND 554
#define VARIDXSTART 555
#define VARIDXEND 556
#define TRANSFORMATIONSTART 557
#define TRANSFORMATIONEND 558
#define COLOFFSETSSTART 559
#define COLOFFSETSEND 560
#define ROWOFFSETSSTART 561
#define ROWOFFSETSEND 562
#define EMPTYROWMAJORATT 563
#define ROWMAJORATT 564
#define BLOCKROWIDXATT 565
#define BLOCKCOLIDXATT 566
#define DUMMY 567
#define NONLINEAREXPRESSIONSSTART 568
#define NONLINEAREXPRESSIONSEND 569
#define NUMBEROFNONLINEAREXPRESSIONS 570
#define NLSTART 571
#define NLEND 572
#define MATRIXEXPRESSIONSSTART 573
#define MATRIXEXPRESSIONSEND 574
#define NUMBEROFEXPR 575
#define EXPRSTART 576
#define EXPREND 577
#define NUMBEROFMATRIXTERMSATT 578
#define MATRIXTERMSTART 579
#define MATRIXTERMEND 580
#define POWERSTART 581
#define POWEREND 582
#define PLUSSTART 583
#define PLUSEND 584
#define MINUSSTART 585
#define MINUSEND 586
#define DIVIDESTART 587
#define DIVIDEEND 588
#define LNSTART 589
#define LNEND 590
#define SQRTSTART 591
#define SQRTEND 592
#define SUMSTART 593
#define SUMEND 594
#define PRODUCTSTART 595
#define PRODUCTEND 596
#define EXPSTART 597
#define EXPEND 598
#define NEGATESTART 599
#define NEGATEEND 600
#define IFSTART 601
#define IFEND 602
#define SQUARESTART 603
#define SQUAREEND 604
#define COSSTART 605
#define COSEND 606
#define SINSTART 607
#define SINEND 608
#define VARIABLESTART 609
#define VARIABLEEND 610
#define ABSSTART 611
#define ABSEND 612
#define ERFSTART 613
#define ERFEND 614
#define MAXSTART 615
#define MAXEND 616
#define ALLDIFFSTART 617
#define ALLDIFFEND 618
#define MINSTART 619
#define MINEND 620
#define ESTART 621
#define EEND 622
#define PISTART 623
#define PIEND 624
#define TIMESSTART 625
#define TIMESEND 626
#define NUMBERSTART 627
#define NUMBEREND 628
#define MATRIXDETERMINANTSTART 629
#define MATRIXDETERMINANTEND 630
#define MATRIXTRACESTART 631
#define MATRIXTRACEEND 632
#define MATRIXTOSCALARSTART 633
#define MATRIXTOSCALAREND 634
#define MATRIXDIAGONALSTART 635
#define MATRIXDIAGONALEND 636
#define MATRIXDOTTIMESSTART 637
#define MATRIXDOTTIMESEND 638
#define MATRIXLOWERTRIANGLESTART 639
#define MATRIXLOWERTRIANGLEEND 640
#define MATRIXUPPERTRIANGLESTART 641
#define MATRIXUPPERTRIANGLEEND 642
#define MATRIXMERGESTART 643
#define MATRIXMERGEEND 644
#define MATRIXMINUSSTART 645
#define MATRIXMINUSEND 646
#define MATRIXNEGATESTART 647
#define MATRIXNEGATEEND 648
#define MATRIXPLUSSTART 649
#define MATRIXPLUSEND 650
#define MATRIXTIMESSTART 651
#define MATRIXTIMESEND 652
#define MATRIXPRODUCTSTART 653
#define MATRIXPRODUCTEND 654
#define MATRIXSCALARTIMESSTART 655
#define MATRIXSCALARTIMESEND 656
#define MATRIXSUBMATRIXATSTART 657
#define MATRIXSUBMATRIXATEND 658
#define MATRIXTRANSPOSESTART 659
#define MATRIXTRANSPOSEEND 660
#define MATRIXREFERENCESTART 661
#define MATRIXREFERENCEEND 662
#define IDENTITYMATRIXSTART 663
#define IDENTITYMATRIXEND 664
#define MATRIXINVERSESTART 665
#define MATRIXINVERSEEND 666
#define EMPTYINCLUDEDIAGONALATT 667
#define INCLUDEDIAGONALATT 668
#define IDATT 669




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
#define YYLAST   1250

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  419
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  831
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1234
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1694

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   669

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   416,
     418,     2,     2,   417,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   415,     2,     2,     2,     2,     2,     2,     2,
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
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414
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
     485,   487,   490,   492,   496,   498,   500,   503,   507,   509,
     511,   512,   515,   517,   519,   521,   524,   526,   527,   530,
     532,   534,   536,   539,   541,   545,   547,   549,   552,   554,
     556,   559,   561,   563,   565,   568,   570,   574,   576,   580,
     582,   584,   586,   588,   591,   593,   597,   599,   601,   604,
     608,   610,   612,   613,   616,   618,   620,   622,   625,   627,
     628,   631,   633,   635,   637,   640,   642,   646,   648,   650,
     653,   655,   657,   659,   661,   663,   665,   667,   669,   671,
     673,   675,   677,   679,   681,   683,   687,   689,   690,   692,
     694,   696,   699,   701,   705,   707,   709,   712,   714,   716,
     718,   721,   723,   727,   729,   733,   735,   737,   739,   741,
     744,   746,   750,   752,   755,   760,   764,   766,   768,   770,
     773,   775,   779,   783,   785,   787,   789,   792,   794,   798,
     802,   804,   806,   808,   811,   813,   817,   821,   823,   825,
     827,   830,   832,   836,   840,   842,   844,   846,   848,   851,
     853,   857,   859,   862,   864,   868,   870,   872,   874,   876,
     879,   881,   885,   887,   890,   892,   896,   898,   900,   902,
     904,   907,   909,   913,   915,   918,   920,   924,   926,   928,
     930,   932,   935,   937,   941,   943,   946,   948,   952,   954,
     956,   958,   960,   963,   965,   969,   973,   975,   977,   979,
     981,   984,   986,   990,   994,   996,   998,  1000,  1002,  1005,
    1007,  1011,  1013,  1016,  1021,  1025,  1027,  1029,  1031,  1033,
    1036,  1038,  1042,  1044,  1046,  1049,  1053,  1055,  1057,  1058,
    1061,  1063,  1065,  1067,  1070,  1072,  1073,  1077,  1079,  1081,
    1082,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1101,  1106,
    1107,  1111,  1113,  1115,  1116,  1118,  1120,  1122,  1124,  1128,
    1135,  1136,  1140,  1142,  1144,  1146,  1148,  1151,  1153,  1157,
    1159,  1161,  1164,  1168,  1170,  1172,  1173,  1176,  1178,  1180,
    1182,  1185,  1187,  1188,  1192,  1194,  1196,  1198,  1200,  1203,
    1205,  1209,  1211,  1213,  1216,  1220,  1222,  1224,  1225,  1228,
    1230,  1232,  1234,  1237,  1239,  1240,  1243,  1245,  1247,  1249,
    1251,  1255,  1263,  1264,  1268,  1270,  1272,  1274,  1276,  1278,
    1282,  1284,  1285,  1289,  1291,  1293,  1295,  1297,  1299,  1303,
    1305,  1306,  1310,  1312,  1314,  1316,  1318,  1320,  1324,  1326,
    1327,  1331,  1333,  1335,  1337,  1339,  1341,  1345,  1347,  1348,
    1352,  1354,  1356,  1358,  1360,  1362,  1366,  1368,  1369,  1373,
    1375,  1377,  1379,  1381,  1383,  1387,  1389,  1390,  1394,  1396,
    1398,  1400,  1402,  1404,  1408,  1410,  1411,  1415,  1417,  1419,
    1421,  1423,  1426,  1428,  1432,  1434,  1436,  1439,  1443,  1445,
    1447,  1448,  1451,  1453,  1455,  1457,  1460,  1462,  1463,  1467,
    1469,  1474,  1476,  1478,  1481,  1483,  1487,  1489,  1492,  1496,
    1498,  1500,  1501,  1504,  1506,  1508,  1510,  1512,  1514,  1517,
    1519,  1523,  1524,  1527,  1531,  1533,  1535,  1536,  1539,  1541,
    1543,  1545,  1547,  1549,  1551,  1553,  1555,  1557,  1559,  1561,
    1563,  1566,  1568,  1572,  1574,  1576,  1578,  1581,  1585,  1587,
    1589,  1590,  1593,  1595,  1597,  1599,  1601,  1603,  1605,  1608,
    1610,  1611,  1615,  1617,  1619,  1620,  1622,  1624,  1626,  1628,
    1632,  1637,  1638,  1642,  1644,  1646,  1648,  1650,  1653,  1655,
    1659,  1661,  1663,  1666,  1670,  1672,  1674,  1675,  1678,  1680,
    1682,  1684,  1687,  1689,  1690,  1694,  1696,  1698,  1700,  1702,
    1705,  1707,  1711,  1713,  1715,  1718,  1722,  1724,  1726,  1727,
    1730,  1732,  1734,  1736,  1738,  1741,  1743,  1744,  1747,  1749,
    1751,  1753,  1755,  1759,  1767,  1768,  1772,  1774,  1776,  1778,
    1780,  1782,  1786,  1788,  1789,  1793,  1795,  1797,  1799,  1801,
    1803,  1807,  1809,  1810,  1814,  1816,  1818,  1820,  1822,  1824,
    1828,  1830,  1831,  1835,  1837,  1839,  1841,  1843,  1845,  1849,
    1851,  1852,  1856,  1858,  1860,  1862,  1864,  1866,  1870,  1872,
    1873,  1877,  1879,  1881,  1883,  1885,  1887,  1891,  1893,  1894,
    1898,  1900,  1902,  1904,  1906,  1908,  1912,  1914,  1915,  1918,
    1922,  1924,  1926,  1927,  1930,  1932,  1934,  1936,  1938,  1940,
    1942,  1944,  1946,  1948,  1950,  1952,  1954,  1957,  1959,  1963,
    1965,  1967,  1969,  1972,  1976,  1978,  1980,  1981,  1984,  1986,
    1988,  1990,  1992,  1994,  1996,  1999,  2001,  2002,  2006,  2008,
    2010,  2011,  2013,  2015,  2017,  2019,  2023,  2028,  2029,  2033,
    2035,  2037,  2039,  2041,  2044,  2046,  2050,  2052,  2054,  2057,
    2061,  2063,  2065,  2066,  2069,  2071,  2073,  2075,  2078,  2080,
    2081,  2085,  2087,  2089,  2091,  2093,  2096,  2098,  2102,  2104,
    2106,  2109,  2113,  2115,  2117,  2118,  2121,  2123,  2125,  2127,
    2129,  2132,  2134,  2135,  2138,  2140,  2142,  2144,  2146,  2150,
    2158,  2159,  2163,  2165,  2167,  2169,  2171,  2173,  2177,  2179,
    2180,  2184,  2186,  2188,  2190,  2192,  2194,  2198,  2200,  2201,
    2205,  2207,  2209,  2211,  2213,  2215,  2219,  2221,  2222,  2226,
    2228,  2230,  2232,  2234,  2236,  2240,  2242,  2243,  2247,  2249,
    2251,  2253,  2255,  2257,  2261,  2263,  2264,  2268,  2270,  2272,
    2274,  2276,  2278,  2282,  2284,  2285,  2289,  2291,  2293,  2295,
    2297,  2299,  2303,  2305,  2306,  2309,  2313,  2315,  2317,  2318,
    2321,  2323,  2325,  2327,  2329,  2331,  2333,  2335,  2337,  2339,
    2341,  2343,  2345,  2348,  2350,  2354,  2356,  2358,  2360,  2363,
    2367,  2369,  2371,  2372,  2375,  2377,  2379,  2381,  2383,  2385,
    2387,  2390,  2392,  2393,  2397,  2399,  2401,  2403,  2405,  2407,
    2411,  2412,  2415,  2419,  2421,  2423,  2425,  2428,  2430,  2432,
    2434,  2436,  2438,  2440,  2442,  2444,  2446,  2449,  2451,  2455,
    2457,  2459,  2462,  2464,  2466,  2468,  2470,  2472,  2476,  2478,
    2480,  2483,  2488,  2492,  2494,  2496,  2497,  2500,  2502,  2504,
    2506,  2510,  2514,  2518,  2521,  2523,  2525,  2527,  2529,  2531,
    2535,  2537,  2539,  2541,  2543,  2547,  2549,  2551,  2553,  2555,
    2559,  2561,  2563,  2565,  2567,  2571,  2573,  2578,  2580,  2582,
    2587,  2589,  2591,  2593,  2595,  2599,  2601,  2603,  2605,  2607,
    2612,  2614,  2616,  2618,  2620,  2624,  2626,  2628,  2630,  2632,
    2636,  2638,  2640,  2642,  2644,  2648,  2650,  2652,  2657,  2659,
    2661,  2663,  2665,  2669,  2671,  2673,  2675,  2677,  2681,  2683,
    2685,  2687,  2689,  2694,  2696,  2698,  2700,  2702,  2706,  2708,
    2710,  2712,  2714,  2718,  2720,  2722,  2724,  2726,  2730,  2735,
    2740,  2745,  2750,  2755,  2760,  2765,  2770,  2775,  2780,  2785,
    2790,  2795,  2800,  2805,  2810,  2815,  2820,  2822,  2825,  2829,
    2831,  2833,  2834,  2837,  2839,  2841,  2843,  2845,  2847,  2849,
    2853,  2855,  2857,  2859,  2862,  2863,  2866,  2868,  2870,  2872,
    2874,  2877,  2879,  2881,  2883,  2885,  2889,  2891,  2892,  2895,
    2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,
    2919,  2921,  2923,  2925,  2927,  2929,  2933,  2935,  2937,  2939,
    2941,  2943,  2947,  2949,  2951,  2953,  2955,  2957,  2961,  2963,
    2965,  2967,  2969,  2971,  2975,  2977,  2979,  2980,  2983,  2987,
    2989,  2991,  2992,  2995,  2997,  2999,  3003,  3007,  3009,  3011,
    3014,  3016,  3020,  3025,  3030
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     420,     0,    -1,   421,   429,   427,    -1,   422,   423,   424,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   425,    -1,
     426,    -1,    11,    -1,    10,   429,   427,    -1,   428,    -1,
      15,    -1,    -1,   430,   431,   517,   565,   593,   709,    -1,
      -1,  1207,    -1,    -1,   432,   433,    -1,    75,    -1,   434,
      -1,   435,    -1,    10,    76,    -1,    11,    -1,    10,   436,
      76,    -1,   437,    -1,   438,    -1,   437,   438,    -1,   439,
      -1,   445,    -1,   451,    -1,   457,    -1,   465,    -1,   471,
      -1,   477,    -1,   483,    -1,   489,    -1,   495,    -1,   503,
      -1,   440,   441,    -1,    85,    -1,   442,    -1,   443,    -1,
      10,    86,    -1,    11,    -1,    10,   444,    86,    -1,     4,
      -1,   446,   447,    -1,    87,    -1,   448,    -1,   449,    -1,
      10,    88,    -1,    11,    -1,    10,   450,    88,    -1,     4,
      -1,   452,   453,    -1,    89,    -1,   454,    -1,   455,    -1,
      10,    90,    -1,    11,    -1,    10,   456,    90,    -1,     4,
      -1,   458,   459,   461,    -1,    91,    -1,    -1,   460,    -1,
      74,     3,     8,    -1,   462,    -1,   463,    -1,    10,    92,
      -1,    11,    -1,    10,   464,    92,    -1,     4,    -1,   466,
     467,    -1,    93,    -1,   468,    -1,   469,    -1,    10,    94,
      -1,    11,    -1,    10,   470,    94,    -1,     4,    -1,   472,
     473,    -1,    95,    -1,   474,    -1,   475,    -1,    10,    96,
      -1,    11,    -1,    10,   476,    96,    -1,     4,    -1,   478,
     479,    -1,    97,    -1,   480,    -1,   481,    -1,    10,    98,
      -1,    11,    -1,    10,   482,    98,    -1,     4,    -1,   484,
     485,    -1,    99,    -1,   486,    -1,   487,    -1,    10,   100,
      -1,    11,    -1,    10,   488,   100,    -1,     4,    -1,   490,
     491,    -1,   101,    -1,   492,    -1,   493,    -1,    10,   102,
      -1,    11,    -1,    10,   494,   102,    -1,     4,    -1,   496,
     497,   499,    -1,   103,    -1,    -1,   498,    -1,    73,     3,
       8,    -1,   500,    -1,   501,    -1,    10,   104,    -1,    11,
      -1,    10,   502,   104,    -1,     4,    -1,   504,   505,   506,
      -1,   105,    -1,  1185,    -1,   507,    -1,   508,    -1,    10,
     106,    -1,    11,    -1,    10,   509,   106,    -1,   510,    -1,
     511,    -1,   510,   511,    -1,   512,   513,   516,    -1,   107,
      -1,   514,    -1,    -1,   514,   515,    -1,  1136,    -1,  1167,
      -1,  1115,    -1,    10,   108,    -1,    11,    -1,    -1,   518,
     519,    -1,    77,    -1,   520,    -1,   521,    -1,    10,    78,
      -1,    11,    -1,    10,   522,    78,    -1,   523,    -1,   524,
      -1,   523,   524,    -1,   525,    -1,   532,    -1,   539,    -1,
     546,    -1,   551,    -1,   526,   527,   530,    -1,   109,    -1,
     528,    -1,    -1,   528,   529,    -1,  1163,    -1,  1115,    -1,
      10,   531,   110,    -1,  1203,    -1,   533,   534,   537,    -1,
     111,    -1,   535,    -1,    -1,   535,   536,    -1,  1163,    -1,
    1115,    -1,    10,   538,   112,    -1,  1203,    -1,   540,   541,
     544,    -1,   113,    -1,   542,    -1,    -1,   542,   543,    -1,
    1163,    -1,  1115,    -1,    10,   545,   114,    -1,  1203,    -1,
     547,   548,   549,    -1,   115,    -1,    -1,  1115,    -1,    10,
     550,   116,    -1,     6,    -1,   552,   553,   554,    -1,   105,
      -1,  1185,    -1,   555,    -1,   556,    -1,    10,   106,    -1,
      11,    -1,    10,   557,   106,    -1,   558,    -1,   559,    -1,
     558,   559,    -1,   560,   561,   564,    -1,   107,    -1,   562,
      -1,    -1,   562,   563,    -1,  1136,    -1,  1167,    -1,  1115,
      -1,    10,   108,    -1,    11,    -1,    -1,   566,   567,    -1,
      79,    -1,   568,    -1,   569,    -1,    10,    80,    -1,    11,
      -1,    10,   570,    80,    -1,   571,    -1,   572,    -1,   571,
     572,    -1,   573,    -1,   579,    -1,   574,   575,    -1,   117,
      -1,   576,    -1,   577,    -1,    10,   118,    -1,    11,    -1,
      10,   578,   118,    -1,     4,    -1,   580,   581,   582,    -1,
     105,    -1,  1185,    -1,   583,    -1,   584,    -1,    10,   106,
      -1,    11,    -1,    10,   585,   106,    -1,   586,    -1,   587,
      -1,   586,   587,    -1,   588,   589,   592,    -1,   107,    -1,
     590,    -1,    -1,   590,   591,    -1,  1136,    -1,  1167,    -1,
    1115,    -1,    10,   108,    -1,    11,    -1,    -1,   594,   595,
      -1,    81,    -1,   596,    -1,   597,    -1,    10,    82,    -1,
      11,    -1,    10,   598,    82,    -1,   599,    -1,   600,    -1,
     599,   600,    -1,   601,    -1,   609,    -1,   615,    -1,   623,
      -1,   628,    -1,   633,    -1,   638,    -1,   643,    -1,   651,
      -1,   667,    -1,   659,    -1,   675,    -1,   681,    -1,   687,
      -1,   695,    -1,   602,   603,   604,    -1,   119,    -1,    -1,
    1163,    -1,   605,    -1,   606,    -1,    10,   120,    -1,    11,
      -1,    10,   607,   120,    -1,   608,    -1,  1203,    -1,   610,
     611,    -1,   121,    -1,   612,    -1,   613,    -1,    10,   122,
      -1,    11,    -1,    10,   614,   122,    -1,     4,    -1,   616,
     617,   618,    -1,   123,    -1,  1180,    -1,   619,    -1,   620,
      -1,    10,   124,    -1,    11,    -1,    10,   621,   124,    -1,
     622,    -1,   621,   622,    -1,    93,    10,     4,    94,    -1,
     624,  1188,   625,    -1,   125,    -1,   626,    -1,   627,    -1,
      10,   126,    -1,    11,    -1,    10,  1096,   126,    -1,   629,
    1188,   630,    -1,   127,    -1,   631,    -1,   632,    -1,    10,
     128,    -1,    11,    -1,    10,  1096,   128,    -1,   634,  1188,
     635,    -1,   133,    -1,   636,    -1,   637,    -1,    10,   134,
      -1,    11,    -1,    10,  1096,   134,    -1,   639,  1188,   640,
      -1,   135,    -1,   641,    -1,   642,    -1,    10,   136,    -1,
      11,    -1,    10,  1096,   136,    -1,   644,   645,   646,    -1,
     141,    -1,  1187,    -1,   647,    -1,   648,    -1,    10,   142,
      -1,    11,    -1,    10,   649,   142,    -1,   650,    -1,   649,
     650,    -1,  1098,    -1,   652,   653,   654,    -1,   143,    -1,
    1187,    -1,   655,    -1,   656,    -1,    10,   144,    -1,    11,
      -1,    10,   657,   144,    -1,   658,    -1,   657,   658,    -1,
    1098,    -1,   660,   661,   662,    -1,   147,    -1,  1187,    -1,
     663,    -1,   664,    -1,    10,   148,    -1,    11,    -1,    10,
     665,   148,    -1,   666,    -1,   665,   666,    -1,  1098,    -1,
     668,   669,   670,    -1,   145,    -1,  1187,    -1,   671,    -1,
     672,    -1,    10,   146,    -1,    11,    -1,    10,   673,   146,
      -1,   674,    -1,   673,   674,    -1,  1098,    -1,   676,   677,
     678,    -1,   139,    -1,  1188,    -1,   679,    -1,   680,    -1,
      10,   140,    -1,    11,    -1,    10,  1096,   140,    -1,   682,
     683,   684,    -1,   137,    -1,  1188,    -1,   685,    -1,   686,
      -1,    10,   138,    -1,    11,    -1,    10,  1096,   138,    -1,
     688,   689,   690,    -1,   149,    -1,  1189,    -1,   691,    -1,
     692,    -1,    10,   150,    -1,    11,    -1,    10,   693,   150,
      -1,   694,    -1,   693,   694,    -1,   151,    10,     4,   152,
      -1,   696,   697,   698,    -1,   105,    -1,  1185,    -1,   699,
      -1,   700,    -1,    10,   106,    -1,    11,    -1,    10,   701,
     106,    -1,   702,    -1,   703,    -1,   702,   703,    -1,   704,
     705,   708,    -1,   107,    -1,   706,    -1,    -1,   706,   707,
      -1,  1136,    -1,  1167,    -1,  1115,    -1,    10,   108,    -1,
      11,    -1,    -1,   710,   711,   714,    -1,    83,    -1,   712,
      -1,    -1,   712,   713,    -1,  1192,    -1,  1176,    -1,  1182,
      -1,   715,    -1,   716,    -1,    11,    -1,    10,   717,    84,
      -1,   718,   856,   965,  1074,    -1,    -1,   719,   720,   722,
      -1,   153,    -1,   721,    -1,    -1,  1186,    -1,   723,    -1,
     724,    -1,    11,    -1,    10,   725,   154,    -1,   726,   740,
     754,   809,   823,   838,    -1,    -1,   727,   728,   729,    -1,
     155,    -1,  1191,    -1,   730,    -1,   731,    -1,    10,   156,
      -1,    11,    -1,    10,   732,   156,    -1,   733,    -1,   734,
      -1,   733,   734,    -1,   735,   736,   739,    -1,   157,    -1,
     737,    -1,    -1,   737,   738,    -1,  1125,    -1,  1136,    -1,
    1167,    -1,    10,   158,    -1,    11,    -1,    -1,   741,   742,
     743,    -1,   159,    -1,  1191,    -1,   744,    -1,   745,    -1,
      10,   160,    -1,    11,    -1,    10,   746,   160,    -1,   747,
      -1,   748,    -1,   747,   748,    -1,   749,   750,   753,    -1,
     157,    -1,   751,    -1,    -1,   751,   752,    -1,  1125,    -1,
    1136,    -1,  1167,    -1,    10,   158,    -1,    11,    -1,    -1,
     755,   756,    -1,   161,    -1,   757,    -1,   758,    -1,    11,
      -1,    10,   759,   162,    -1,   760,   767,   774,   781,   788,
     795,   802,    -1,    -1,   761,   762,   763,    -1,   163,    -1,
    1177,    -1,   764,    -1,   765,    -1,    11,    -1,    10,   766,
     164,    -1,  1235,    -1,    -1,   768,   769,   770,    -1,   167,
      -1,  1177,    -1,   771,    -1,   772,    -1,    11,    -1,    10,
     773,   168,    -1,  1235,    -1,    -1,   775,   776,   777,    -1,
     165,    -1,  1177,    -1,   778,    -1,   779,    -1,    11,    -1,
      10,   780,   166,    -1,  1235,    -1,    -1,   782,   783,   784,
      -1,   169,    -1,  1177,    -1,   785,    -1,   786,    -1,    11,
      -1,    10,   787,   170,    -1,  1235,    -1,    -1,   789,   790,
     791,    -1,   173,    -1,  1177,    -1,   792,    -1,   793,    -1,
      11,    -1,    10,   794,   174,    -1,  1235,    -1,    -1,   796,
     797,   798,    -1,   171,    -1,  1177,    -1,   799,    -1,   800,
      -1,    11,    -1,    10,   801,   172,    -1,  1235,    -1,    -1,
     803,   804,   805,    -1,   175,    -1,  1177,    -1,   806,    -1,
     807,    -1,    11,    -1,    10,   808,   176,    -1,  1235,    -1,
      -1,   810,   811,   812,    -1,   177,    -1,  1191,    -1,   813,
      -1,   814,    -1,    10,   178,    -1,    11,    -1,    10,   815,
     178,    -1,   816,    -1,   817,    -1,   816,   817,    -1,   818,
     819,   822,    -1,   157,    -1,   820,    -1,    -1,   820,   821,
      -1,  1125,    -1,  1136,    -1,  1167,    -1,    10,   158,    -1,
      11,    -1,    -1,   824,   825,   826,    -1,   179,    -1,    29,
       8,     6,     8,    -1,   827,    -1,   828,    -1,    10,   180,
      -1,    11,    -1,    10,   829,   180,    -1,   830,    -1,   829,
     830,    -1,   831,   832,   835,    -1,   181,    -1,   833,    -1,
      -1,   833,   834,    -1,  1148,    -1,  1191,    -1,  1123,    -1,
     836,    -1,   837,    -1,    10,   182,    -1,    11,    -1,    10,
     816,   182,    -1,    -1,   838,   839,    -1,   840,   841,   844,
      -1,   107,    -1,   842,    -1,    -1,   842,   843,    -1,  1191,
      -1,  1178,    -1,  1136,    -1,  1167,    -1,  1144,    -1,  1107,
      -1,  1151,    -1,  1171,    -1,  1119,    -1,  1115,    -1,   845,
      -1,   846,    -1,    10,   108,    -1,    11,    -1,    10,   847,
     108,    -1,   848,    -1,  1193,    -1,   849,    -1,   848,   849,
      -1,   850,   851,   854,    -1,   157,    -1,   852,    -1,    -1,
     852,   853,    -1,  1125,    -1,  1136,    -1,  1167,    -1,  1128,
      -1,  1155,    -1,   855,    -1,    10,   158,    -1,    11,    -1,
      -1,   857,   858,   860,    -1,   183,    -1,   859,    -1,    -1,
    1184,    -1,   861,    -1,   862,    -1,    11,    -1,    10,   863,
     184,    -1,   864,   878,   892,   947,    -1,    -1,   865,   866,
     867,    -1,   185,    -1,  1181,    -1,   868,    -1,   869,    -1,
      10,   186,    -1,    11,    -1,    10,   870,   186,    -1,   871,
      -1,   872,    -1,   871,   872,    -1,   873,   874,   877,    -1,
     187,    -1,   875,    -1,    -1,   875,   876,    -1,  1125,    -1,
    1136,    -1,  1167,    -1,    10,   188,    -1,    11,    -1,    -1,
     879,   880,   881,    -1,   189,    -1,  1181,    -1,   882,    -1,
     883,    -1,    10,   190,    -1,    11,    -1,    10,   884,   190,
      -1,   885,    -1,   886,    -1,   885,   886,    -1,   887,   888,
     891,    -1,   187,    -1,   889,    -1,    -1,   889,   890,    -1,
    1125,    -1,  1136,    -1,  1128,    -1,  1155,    -1,    10,   188,
      -1,    11,    -1,    -1,   893,   894,    -1,   161,    -1,   895,
      -1,   896,    -1,    11,    -1,    10,   897,   162,    -1,   898,
     905,   912,   919,   926,   933,   940,    -1,    -1,   899,   900,
     901,    -1,   163,    -1,  1177,    -1,   902,    -1,   903,    -1,
      11,    -1,    10,   904,   164,    -1,  1235,    -1,    -1,   906,
     907,   908,    -1,   167,    -1,  1177,    -1,   909,    -1,   910,
      -1,    11,    -1,    10,   911,   168,    -1,  1235,    -1,    -1,
     913,   914,   915,    -1,   165,    -1,  1177,    -1,   916,    -1,
     917,    -1,    11,    -1,    10,   918,   166,    -1,  1235,    -1,
      -1,   920,   921,   922,    -1,   169,    -1,  1177,    -1,   923,
      -1,   924,    -1,    11,    -1,    10,   925,   170,    -1,  1235,
      -1,    -1,   927,   928,   929,    -1,   173,    -1,  1177,    -1,
     930,    -1,   931,    -1,    11,    -1,    10,   932,   174,    -1,
    1235,    -1,    -1,   934,   935,   936,    -1,   171,    -1,  1177,
      -1,   937,    -1,   938,    -1,    11,    -1,    10,   939,   172,
      -1,  1235,    -1,    -1,   941,   942,   943,    -1,   175,    -1,
    1177,    -1,   944,    -1,   945,    -1,    11,    -1,    10,   946,
     176,    -1,  1235,    -1,    -1,   947,   948,    -1,   949,   950,
     953,    -1,   107,    -1,   951,    -1,    -1,   951,   952,    -1,
    1181,    -1,  1178,    -1,  1136,    -1,  1167,    -1,  1144,    -1,
    1107,    -1,  1151,    -1,  1140,    -1,  1119,    -1,  1115,    -1,
     954,    -1,   955,    -1,    10,   108,    -1,    11,    -1,    10,
     956,   108,    -1,   957,    -1,  1193,    -1,   958,    -1,   957,
     958,    -1,   959,   960,   963,    -1,   187,    -1,   961,    -1,
      -1,   961,   962,    -1,  1125,    -1,  1136,    -1,  1167,    -1,
    1128,    -1,  1155,    -1,   964,    -1,    10,   188,    -1,    11,
      -1,    -1,   966,   967,   969,    -1,   191,    -1,   968,    -1,
      -1,  1183,    -1,   970,    -1,   971,    -1,    11,    -1,    10,
     972,   192,    -1,   973,   987,  1001,  1056,    -1,    -1,   974,
     975,   976,    -1,   193,    -1,  1175,    -1,   977,    -1,   978,
      -1,    10,   194,    -1,    11,    -1,    10,   979,   194,    -1,
     980,    -1,   981,    -1,   980,   981,    -1,   982,   983,   986,
      -1,   195,    -1,   984,    -1,    -1,   984,   985,    -1,  1125,
      -1,  1136,    -1,  1167,    -1,    10,   196,    -1,    11,    -1,
      -1,   988,   989,   990,    -1,   197,    -1,  1175,    -1,   991,
      -1,   992,    -1,    10,   198,    -1,    11,    -1,    10,   993,
     198,    -1,   994,    -1,   995,    -1,   994,   995,    -1,   996,
     997,  1000,    -1,   195,    -1,   998,    -1,    -1,   998,   999,
      -1,  1125,    -1,  1136,    -1,  1132,    -1,  1159,    -1,    10,
     196,    -1,    11,    -1,    -1,  1002,  1003,    -1,   161,    -1,
    1004,    -1,  1005,    -1,    11,    -1,    10,  1006,   162,    -1,
    1007,  1014,  1021,  1028,  1035,  1042,  1049,    -1,    -1,  1008,
    1009,  1010,    -1,   163,    -1,  1177,    -1,  1011,    -1,  1012,
      -1,    11,    -1,    10,  1013,   164,    -1,  1235,    -1,    -1,
    1015,  1016,  1017,    -1,   167,    -1,  1177,    -1,  1018,    -1,
    1019,    -1,    11,    -1,    10,  1020,   168,    -1,  1235,    -1,
      -1,  1022,  1023,  1024,    -1,   165,    -1,  1177,    -1,  1025,
      -1,  1026,    -1,    11,    -1,    10,  1027,   166,    -1,  1235,
      -1,    -1,  1029,  1030,  1031,    -1,   169,    -1,  1177,    -1,
    1032,    -1,  1033,    -1,    11,    -1,    10,  1034,   170,    -1,
    1235,    -1,    -1,  1036,  1037,  1038,    -1,   173,    -1,  1177,
      -1,  1039,    -1,  1040,    -1,    11,    -1,    10,  1041,   174,
      -1,  1235,    -1,    -1,  1043,  1044,  1045,    -1,   171,    -1,
    1177,    -1,  1046,    -1,  1047,    -1,    11,    -1,    10,  1048,
     172,    -1,  1235,    -1,    -1,  1050,  1051,  1052,    -1,   175,
      -1,  1177,    -1,  1053,    -1,  1054,    -1,    11,    -1,    10,
    1055,   176,    -1,  1235,    -1,    -1,  1056,  1057,    -1,  1058,
    1059,  1062,    -1,   107,    -1,  1060,    -1,    -1,  1060,  1061,
      -1,  1175,    -1,  1178,    -1,  1136,    -1,  1167,    -1,  1144,
      -1,  1107,    -1,  1151,    -1,  1111,    -1,  1119,    -1,  1115,
      -1,  1063,    -1,  1064,    -1,    10,   108,    -1,    11,    -1,
      10,  1065,   108,    -1,  1066,    -1,  1193,    -1,  1067,    -1,
    1066,  1067,    -1,  1068,  1069,  1072,    -1,   195,    -1,  1070,
      -1,    -1,  1070,  1071,    -1,  1125,    -1,  1136,    -1,  1167,
      -1,  1128,    -1,  1155,    -1,  1073,    -1,    10,   196,    -1,
      11,    -1,    -1,  1075,  1076,  1077,    -1,   199,    -1,  1190,
      -1,  1078,    -1,  1079,    -1,    11,    -1,    10,  1080,   200,
      -1,    -1,  1080,  1081,    -1,  1082,  1083,  1086,    -1,   201,
      -1,  1084,    -1,  1085,    -1,  1084,  1085,    -1,  1136,    -1,
    1167,    -1,  1144,    -1,  1107,    -1,  1151,    -1,  1115,    -1,
    1179,    -1,  1087,    -1,  1088,    -1,    10,   202,    -1,    11,
      -1,    10,  1089,   202,    -1,  1090,    -1,  1091,    -1,  1090,
    1091,    -1,  1092,    -1,  1093,    -1,  1094,    -1,   208,    -1,
     205,    -1,   206,  1095,   207,    -1,     5,    -1,  1097,    -1,
    1096,  1097,    -1,   129,    10,     4,   130,    -1,  1099,  1100,
    1106,    -1,   131,    -1,  1101,    -1,    -1,  1101,  1102,    -1,
    1103,    -1,  1104,    -1,  1105,    -1,    21,     3,     8,    -1,
      22,     3,     8,    -1,    23,     3,     8,    -1,    10,   132,
      -1,    11,    -1,  1108,    -1,  1109,    -1,  1110,    -1,    57,
      -1,    24,     3,  1204,    -1,  1112,    -1,  1113,    -1,  1114,
      -1,    48,    -1,    47,     3,     8,    -1,  1116,    -1,  1117,
      -1,  1118,    -1,    58,    -1,    46,     3,  1204,    -1,  1120,
      -1,  1121,    -1,  1122,    -1,    50,    -1,    49,     3,     8,
      -1,  1124,    -1,    26,     8,  1203,     8,    -1,  1126,    -1,
    1127,    -1,    42,  1204,     6,  1204,    -1,  1129,    -1,  1130,
      -1,  1131,    -1,    61,    -1,    63,     3,  1204,    -1,  1133,
      -1,  1134,    -1,  1135,    -1,    65,    -1,    67,  1204,  1203,
    1204,    -1,  1137,    -1,  1138,    -1,  1139,    -1,    56,    -1,
      41,     3,  1204,    -1,  1141,    -1,  1142,    -1,  1143,    -1,
      52,    -1,    51,     3,     8,    -1,  1145,    -1,  1146,    -1,
    1147,    -1,    70,    -1,    69,     3,  1204,    -1,  1149,    -1,
    1150,    -1,    43,  1204,     6,  1204,    -1,  1152,    -1,  1153,
      -1,  1154,    -1,    55,    -1,    25,     3,     8,    -1,  1156,
      -1,  1157,    -1,  1158,    -1,    62,    -1,    64,     3,  1204,
      -1,  1160,    -1,  1161,    -1,  1162,    -1,    66,    -1,    68,
    1204,  1203,  1204,    -1,  1164,    -1,  1165,    -1,  1166,    -1,
      59,    -1,    45,     3,     8,    -1,  1168,    -1,  1169,    -1,
    1170,    -1,    60,    -1,    44,     3,     8,    -1,  1172,    -1,
    1173,    -1,  1174,    -1,    54,    -1,    53,     3,     8,    -1,
      39,  1204,     6,  1204,    -1,    32,  1204,     6,  1204,    -1,
      40,  1204,     6,  1204,    -1,    17,  1204,     6,  1204,    -1,
      36,  1204,     6,  1204,    -1,    18,     8,     6,     8,    -1,
      38,  1204,     6,  1204,    -1,    31,  1204,     6,  1204,    -1,
      35,  1204,     6,  1204,    -1,    34,  1204,     6,  1204,    -1,
      16,  1204,     6,  1204,    -1,    33,  1204,     6,  1204,    -1,
      20,     8,     6,     8,    -1,    19,     8,     6,     8,    -1,
      27,     8,     6,     8,    -1,    28,  1204,     6,  1204,    -1,
      37,  1204,     6,  1204,    -1,    30,  1204,     6,  1204,    -1,
    1194,    -1,  1193,  1194,    -1,  1195,  1196,  1199,    -1,   203,
      -1,  1197,    -1,    -1,  1197,  1198,    -1,  1177,    -1,  1167,
      -1,  1115,    -1,  1200,    -1,  1201,    -1,    11,    -1,    10,
    1202,   204,    -1,  1235,    -1,     6,    -1,     7,    -1,  1205,
       8,    -1,    -1,  1205,  1206,    -1,   415,    -1,   416,    -1,
     417,    -1,   418,    -1,  1208,  1209,    -1,   222,    -1,  1210,
      -1,  1211,    -1,    11,    -1,    10,  1212,   223,    -1,  1213,
      -1,    -1,  1213,  1214,    -1,  1215,    -1,  1219,    -1,  1223,
      -1,  1227,    -1,  1231,    -1,  1216,    -1,  1217,    -1,  1218,
      -1,   227,    -1,   226,    -1,   224,     5,   225,    -1,  1220,
      -1,  1221,    -1,  1222,    -1,   231,    -1,   230,    -1,   228,
       5,   229,    -1,  1224,    -1,  1225,    -1,  1226,    -1,   235,
      -1,   234,    -1,   232,     5,   233,    -1,  1228,    -1,  1229,
      -1,  1230,    -1,   239,    -1,   238,    -1,   236,     5,   237,
      -1,  1232,    -1,  1233,    -1,  1234,    -1,   243,    -1,   242,
      -1,   240,     5,   241,    -1,  1236,    -1,  1243,    -1,    -1,
    1236,  1237,    -1,  1238,  1239,  1242,    -1,   214,    -1,  1240,
      -1,    -1,  1240,  1241,    -1,  1249,    -1,  1248,    -1,    10,
       6,   215,    -1,   209,  1247,  1244,    -1,  1245,    -1,  1246,
      -1,    10,   210,    -1,    11,    -1,    10,     4,   210,    -1,
     213,     8,     6,     8,    -1,   211,     8,     6,     8,    -1,
     212,     8,     6,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   304,   304,   305,   307,   314,   324,   324,   326,   326,
     328,   330,   332,   341,   342,   345,   353,   353,   366,   366,
     368,   384,   384,   386,   386,   388,   390,   392,   392,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     409,   411,   420,   420,   422,   422,   424,   426,   436,   438,
     445,   445,   447,   447,   449,   451,   461,   463,   469,   469,
     471,   471,   473,   475,   485,   492,   500,   501,   508,   514,
     514,   516,   516,   518,   520,   528,   530,   536,   536,   538,
     538,   540,   542,   551,   553,   560,   560,   562,   562,   564,
     566,   576,   578,   585,   585,   587,   587,   589,   591,   601,
     603,   609,   609,   611,   611,   613,   615,   625,   627,   633,
     633,   635,   635,   637,   639,   649,   656,   665,   666,   672,
     679,   679,   681,   681,   683,   685,   693,   699,   709,   717,
     722,   728,   728,   730,   732,   736,   736,   738,   746,   765,
     771,   771,   774,   778,   779,   782,   782,   791,   791,   793,
     803,   803,   805,   805,   807,   809,   811,   811,   814,   815,
     816,   817,   818,   822,   824,   834,   836,   836,   839,   840,
     843,   845,   853,   855,   865,   867,   867,   870,   871,   874,
     876,   885,   887,   897,   899,   899,   902,   903,   906,   908,
     917,   919,   927,   928,   930,   932,   943,   949,   959,   967,
     971,   976,   976,   978,   980,   984,   984,   986,   994,  1013,
    1018,  1018,  1021,  1026,  1027,  1030,  1030,  1039,  1039,  1041,
    1048,  1048,  1050,  1050,  1052,  1054,  1056,  1056,  1059,  1060,
    1064,  1066,  1072,  1072,  1074,  1074,  1076,  1078,  1089,  1095,
    1105,  1113,  1117,  1122,  1122,  1124,  1126,  1130,  1130,  1132,
    1140,  1159,  1164,  1164,  1167,  1172,  1173,  1176,  1176,  1184,
    1184,  1186,  1206,  1206,  1208,  1208,  1210,  1212,  1214,  1214,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,
    1227,  1228,  1229,  1230,  1231,  1236,  1242,  1252,  1253,  1255,
    1255,  1257,  1257,  1259,  1261,  1263,  1270,  1272,  1278,  1278,
    1280,  1280,  1282,  1284,  1294,  1305,  1315,  1317,  1317,  1319,
    1319,  1321,  1330,  1330,  1332,  1353,  1364,  1374,  1374,  1376,
    1376,  1378,  1389,  1400,  1410,  1410,  1412,  1412,  1414,  1425,
    1436,  1446,  1446,  1448,  1448,  1450,  1461,  1472,  1482,  1482,
    1484,  1484,  1486,  1497,  1513,  1523,  1525,  1525,  1527,  1527,
    1529,  1538,  1538,  1540,  1544,  1560,  1570,  1572,  1572,  1574,
    1574,  1576,  1585,  1585,  1587,  1591,  1607,  1617,  1619,  1619,
    1621,  1621,  1623,  1632,  1632,  1634,  1638,  1654,  1664,  1666,
    1666,  1668,  1668,  1670,  1679,  1679,  1681,  1685,  1696,  1706,
    1708,  1708,  1710,  1710,  1712,  1723,  1734,  1744,  1746,  1746,
    1748,  1748,  1750,  1776,  1787,  1797,  1799,  1799,  1801,  1801,
    1803,  1812,  1812,  1814,  1835,  1841,  1851,  1859,  1863,  1868,
    1868,  1870,  1872,  1876,  1876,  1878,  1886,  1905,  1911,  1911,
    1914,  1919,  1920,  1923,  1923,  1931,  1931,  1933,  1941,  1943,
    1943,  1946,  1952,  1958,  1966,  1966,  1968,  1970,  1972,  1979,
    1979,  1981,  1987,  1994,  1994,  1999,  1999,  2001,  2003,  2005,
    2015,  2015,  2030,  2035,  2046,  2054,  2063,  2063,  2065,  2067,
    2069,  2069,  2072,  2077,  2091,  2097,  2097,  2100,  2112,  2117,
    2125,  2125,  2129,  2129,  2144,  2149,  2160,  2168,  2177,  2177,
    2179,  2181,  2183,  2183,  2186,  2191,  2206,  2212,  2212,  2215,
    2227,  2232,  2238,  2238,  2242,  2242,  2244,  2249,  2249,  2251,
    2253,  2255,  2258,  2258,  2269,  2275,  2283,  2283,  2285,  2287,
    2289,  2293,  2293,  2305,  2311,  2319,  2319,  2321,  2323,  2325,
    2329,  2329,  2340,  2346,  2354,  2354,  2356,  2358,  2360,  2364,
    2364,  2375,  2381,  2389,  2389,  2391,  2393,  2395,  2399,  2399,
    2410,  2416,  2424,  2424,  2426,  2428,  2430,  2434,  2434,  2445,
    2451,  2459,  2459,  2461,  2463,  2465,  2469,  2469,  2480,  2486,
    2494,  2494,  2496,  2498,  2500,  2504,  2504,  2520,  2525,  2536,
    2544,  2553,  2553,  2555,  2557,  2563,  2563,  2565,  2570,  2586,
    2592,  2592,  2595,  2607,  2612,  2620,  2620,  2624,  2624,  2630,
    2636,  2644,  2652,  2660,  2660,  2662,  2664,  2664,  2666,  2685,
    2701,  2709,  2709,  2712,  2713,  2722,  2725,  2725,  2727,  2727,
    2729,  2734,  2734,  2736,  2741,  2772,  2792,  2792,  2795,  2799,
    2803,  2804,  2805,  2806,  2807,  2808,  2809,  2810,  2813,  2813,
    2815,  2815,  2817,  2819,  2819,  2821,  2821,  2824,  2839,  2859,
    2861,  2861,  2864,  2874,  2875,  2876,  2877,  2880,  2882,  2882,
    2890,  2890,  2892,  2898,  2905,  2905,  2910,  2910,  2912,  2914,
    2916,  2925,  2925,  2941,  2947,  2959,  2967,  2976,  2976,  2978,
    2980,  2982,  2982,  2985,  2990,  3005,  3007,  3007,  3010,  3021,
    3025,  3032,  3032,  3035,  3035,  3053,  3058,  3072,  3080,  3089,
    3089,  3091,  3093,  3095,  3095,  3098,  3103,  3121,  3123,  3123,
    3126,  3137,  3141,  3147,  3154,  3154,  3158,  3158,  3160,  3165,
    3165,  3167,  3169,  3171,  3174,  3174,  3185,  3191,  3199,  3199,
    3201,  3203,  3205,  3208,  3208,  3219,  3225,  3233,  3233,  3235,
    3237,  3239,  3242,  3242,  3253,  3259,  3267,  3267,  3269,  3271,
    3273,  3276,  3276,  3287,  3293,  3301,  3301,  3303,  3305,  3307,
    3310,  3310,  3321,  3327,  3335,  3335,  3337,  3339,  3341,  3344,
    3344,  3355,  3362,  3370,  3370,  3372,  3374,  3376,  3380,  3380,
    3391,  3397,  3405,  3405,  3407,  3409,  3411,  3415,  3415,  3417,
    3423,  3454,  3475,  3475,  3478,  3482,  3486,  3487,  3488,  3489,
    3490,  3491,  3492,  3493,  3496,  3496,  3498,  3498,  3500,  3502,
    3502,  3504,  3504,  3507,  3522,  3544,  3546,  3546,  3549,  3559,
    3560,  3561,  3562,  3565,  3567,  3567,  3575,  3575,  3577,  3583,
    3590,  3590,  3595,  3595,  3597,  3599,  3601,  3610,  3610,  3626,
    3631,  3642,  3650,  3659,  3659,  3661,  3663,  3665,  3665,  3668,
    3673,  3688,  3694,  3694,  3697,  3708,  3712,  3719,  3719,  3723,
    3723,  3741,  3746,  3759,  3767,  3776,  3776,  3778,  3780,  3782,
    3782,  3785,  3790,  3808,  3814,  3814,  3817,  3828,  3832,  3836,
    3842,  3842,  3846,  3846,  3848,  3853,  3853,  3855,  3857,  3859,
    3862,  3862,  3873,  3879,  3887,  3887,  3889,  3891,  3893,  3896,
    3896,  3907,  3913,  3921,  3921,  3923,  3925,  3927,  3931,  3931,
    3942,  3948,  3956,  3956,  3958,  3960,  3962,  3966,  3966,  3977,
    3983,  3991,  3991,  3993,  3995,  3997,  4001,  4001,  4012,  4018,
    4026,  4026,  4028,  4030,  4032,  4036,  4036,  4047,  4053,  4061,
    4061,  4063,  4065,  4067,  4071,  4071,  4082,  4088,  4096,  4096,
    4098,  4100,  4102,  4106,  4106,  4108,  4114,  4145,  4165,  4165,
    4168,  4172,  4176,  4177,  4178,  4179,  4180,  4181,  4182,  4183,
    4186,  4186,  4188,  4188,  4190,  4192,  4192,  4194,  4194,  4197,
    4212,  4232,  4234,  4234,  4237,  4247,  4248,  4249,  4250,  4253,
    4255,  4255,  4263,  4263,  4269,  4271,  4279,  4287,  4296,  4298,
    4300,  4300,  4304,  4324,  4342,  4348,  4348,  4351,  4352,  4353,
    4354,  4355,  4356,  4357,  4364,  4372,  4381,  4381,  4383,  4385,
    4387,  4387,  4389,  4396,  4407,  4409,  4409,  4411,  4413,  4430,
    4430,  4432,  4454,  4471,  4483,  4488,  4488,  4491,  4492,  4493,
    4495,  4504,  4513,  4522,  4522,  4528,  4535,  4535,  4537,  4542,
    4549,  4555,  4555,  4557,  4560,  4567,  4574,  4574,  4576,  4579,
    4586,  4592,  4592,  4594,  4597,  4605,  4612,  4619,  4626,  4628,
    4634,  4641,  4641,  4643,  4648,  4655,  4661,  4661,  4663,  4668,
    4674,  4681,  4681,  4683,  4688,  4695,  4701,  4701,  4703,  4706,
    4714,  4720,  4720,  4722,  4725,  4732,  4738,  4740,  4748,  4754,
    4754,  4756,  4759,  4766,  4773,  4773,  4775,  4780,  4787,  4793,
    4793,  4795,  4798,  4805,  4811,  4811,  4813,  4816,  4823,  4829,
    4829,  4831,  4834,  4841,  4847,  4847,  4849,  4852,  4864,  4873,
    4882,  4891,  4900,  4909,  4919,  4928,  4937,  4943,  4949,  4955,
    4961,  4975,  4985,  4996,  5002,  5011,  5032,  5032,  5034,  5052,
    5068,  5076,  5076,  5079,  5087,  5088,  5092,  5092,  5094,  5097,
    5099,  5103,  5104,  5111,  5113,  5113,  5115,  5116,  5117,  5118,
    5154,  5156,  5170,  5170,  5172,  5174,  5176,  5178,  5178,  5181,
    5182,  5183,  5184,  5185,  5187,  5195,  5195,  5197,  5197,  5199,
    5205,  5213,  5213,  5215,  5215,  5217,  5223,  5231,  5231,  5233,
    5233,  5235,  5241,  5249,  5249,  5251,  5251,  5253,  5259,  5267,
    5267,  5269,  5269,  5271,  5283,  5291,  5293,  5293,  5295,  5297,
    5306,  5308,  5308,  5310,  5310,  5312,  5328,  5331,  5331,  5333,
    5333,  5336,  6985,  6992,  7002
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
  "OSOLEND", "NUMBEROFOTHEROPTIONSATT", "NUMBEROFENUMERATIONSATT",
  "NUMBEROFJOBIDSATT", "NUMBEROFPATHSATT", "NUMBEROFPATHPAIRSATT",
  "FROMATT", "TOATT", "MAKECOPYATT", "CATEGORYATT", "TYPEATT",
  "GROUPWEIGHTATT", "NUMBEROFPROCESSESATT", "NUMBEROFSOLVEROPTIONSATT",
  "NUMBEROFSOSATT", "NUMBEROFVARIABLESATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFCONSTRAINTSATT", "NUMBEROFOTHERVARIABLEOPTIONSATT",
  "NUMBEROFOTHEROBJECTIVEOPTIONSATT", "NUMBEROFOTHERCONSTRAINTOPTIONSATT",
  "NUMBEROFITEMSATT", "NUMBEROFVARATT", "NUMBEROFOBJATT", "NUMBEROFCONATT",
  "NUMBEROFELATT", "NAMEATT", "IDXATT", "SOSIDXATT", "VALUEATT", "UNITATT",
  "DESCRIPTIONATT", "CONTYPEATT", "EMPTYCONTYPEATT", "ENUMTYPEATT",
  "EMPTYENUMTYPEATT", "OBJTYPEATT", "EMPTYOBJTYPEATT", "VARTYPEATT",
  "EMPTYVARTYPEATT", "EMPTYTYPEATT", "EMPTYNAMEATT", "EMPTYCATEGORYATT",
  "EMPTYDESCRIPTIONATT", "EMPTYUNITATT", "EMPTYVALUEATT",
  "EMPTYLBVALUEATT", "EMPTYUBVALUEATT", "LBVALUEATT", "UBVALUEATT",
  "EMPTYLBDUALVALUEATT", "EMPTYUBDUALVALUEATT", "LBDUALVALUEATT",
  "UBDUALVALUEATT", "SOLVERATT", "EMPTYSOLVERATT", "WEIGHTATT",
  "EMPTYWEIGHTATT", "TRANSPORTTYPEATT", "LOCATIONTYPEATT", "GENERALSTART",
  "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND",
  "JOBSTART", "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
  "SERVICEURISTART", "SERVICEURIEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "INSTANCENAMESTART", "INSTANCENAMEEND", "INSTANCELOCATIONSTART",
  "INSTANCELOCATIONEND", "JOBIDSTART", "JOBIDEND", "SOLVERTOINVOKESTART",
  "SOLVERTOINVOKEEND", "LICENSESTART", "LICENSEEND", "USERNAMESTART",
  "USERNAMEEND", "PASSWORDSTART", "PASSWORDEND", "CONTACTSTART",
  "CONTACTEND", "OTHEROPTIONSSTART", "OTHEROPTIONSEND", "OTHERSTART",
  "OTHEREND", "MINDISKSPACESTART", "MINDISKSPACEEND", "MINMEMORYSTART",
  "MINMEMORYEND", "MINCPUSPEEDSTART", "MINCPUSPEEDEND",
  "MINCPUNUMBERSTART", "MINCPUNUMBEREND", "SERVICETYPESTART",
  "SERVICETYPEEND", "MAXTIMESTART", "MAXTIMEEND",
  "REQUESTEDSTARTTIMESTART", "REQUESTEDSTARTTIMEEND", "DEPENDENCIESSTART",
  "DEPENDENCIESEND", "REQUIREDDIRECTORIESSTART", "REQUIREDDIRECTORIESEND",
  "REQUIREDFILESSTART", "REQUIREDFILESEND", "PATHSTART", "PATHEND",
  "PATHPAIRSTART", "PATHPAIREND", "DIRECTORIESTOMAKESTART",
  "DIRECTORIESTOMAKEEND", "FILESTOMAKESTART", "FILESTOMAKEEND",
  "DIRECTORIESTODELETESTART", "DIRECTORIESTODELETEEND",
  "FILESTODELETESTART", "FILESTODELETEEND", "INPUTDIRECTORIESTOMOVESTART",
  "INPUTDIRECTORIESTOMOVEEND", "INPUTFILESTOMOVESTART",
  "INPUTFILESTOMOVEEND", "OUTPUTDIRECTORIESTOMOVESTART",
  "OUTPUTDIRECTORIESTOMOVEEND", "OUTPUTFILESTOMOVESTART",
  "OUTPUTFILESTOMOVEEND", "PROCESSESTOKILLSTART", "PROCESSESTOKILLEND",
  "PROCESSSTART", "PROCESSEND", "VARIABLESSTART", "VARIABLESEND",
  "INITIALVARIABLEVALUESSTART", "INITIALVARIABLEVALUESEND", "VARSTART",
  "VAREND", "INITIALVARIABLEVALUESSTRINGSTART",
  "INITIALVARIABLEVALUESSTRINGEND", "INITIALBASISSTATUSSTART",
  "INITIALBASISSTATUSEND", "BASICSTART", "BASICEND", "ATUPPERSTART",
  "ATUPPEREND", "ATLOWERSTART", "ATLOWEREND", "ATEQUALITYSTART",
  "ATEQUALITYEND", "SUPERBASICSTART", "SUPERBASICEND", "ISFREESTART",
  "ISFREEEND", "UNKNOWNSTART", "UNKNOWNEND",
  "INTEGERVARIABLEBRANCHINGWEIGHTSSTART",
  "INTEGERVARIABLEBRANCHINGWEIGHTSEND", "SOSVARIABLEBRANCHINGWEIGHTSSTART",
  "SOSVARIABLEBRANCHINGWEIGHTSEND", "SOSSTART", "SOSEND",
  "OBJECTIVESSTART", "OBJECTIVESEND", "INITIALOBJECTIVEVALUESSTART",
  "INITIALOBJECTIVEVALUESEND", "OBJSTART", "OBJEND",
  "INITIALOBJECTIVEBOUNDSSTART", "INITIALOBJECTIVEBOUNDSEND",
  "CONSTRAINTSSTART", "CONSTRAINTSEND", "INITIALCONSTRAINTVALUESSTART",
  "INITIALCONSTRAINTVALUESEND", "CONSTART", "CONEND",
  "INITIALDUALVALUESSTART", "INITIALDUALVALUESEND", "SOLVEROPTIONSSTART",
  "SOLVEROPTIONSEND", "SOLVEROPTIONSTART", "SOLVEROPTIONEND",
  "ENUMERATIONSTART", "ENUMERATIONEND", "ITEMEMPTY", "ITEMSTART",
  "ITEMEND", "ITEMSTARTANDEND", "BASE64START", "BASE64END", "INCRATT",
  "MULTATT", "SIZEOFATT", "ELSTART", "ELEND", "MATRIXVARSTART",
  "MATRIXVAREND", "MATRIXOBJSTART", "MATRIXOBJEND", "MATRIXCONSTART",
  "MATRIXCONEND", "HEADERSTART", "HEADEREND", "FILENAMESTART",
  "FILENAMEEND", "FILENAMEEMPTY", "FILENAMESTARTANDEND", "FILESOURCESTART",
  "FILESOURCEEND", "FILESOURCEEMPTY", "FILESOURCESTARTANDEND",
  "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
  "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART", "FILECREATOREND",
  "FILECREATOREMPTY", "FILECREATORSTARTANDEND", "FILELICENCESTART",
  "FILELICENCEEND", "FILELICENCEEMPTY", "FILELICENCESTARTANDEND",
  "MATRIXSTART", "MATRIXEND", "BASEMATRIXEND", "BASEMATRIXSTART",
  "BLOCKSTART", "BLOCKEND", "BLOCKSSTART", "BLOCKSEND", "EMPTYSHAPEATT",
  "SHAPEATT", "EMPTYSYMMETRYATT", "SYMMETRYATT", "EMPTYNEGATIVEPATTERNATT",
  "NEGATIVEPATTERNATT", "CONSTANTATT", "NUMBEROFBLOCKSATT",
  "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT", "NUMBEROFVALUESATT",
  "NUMBEROFVARIDXATT", "COEFATT", "BASEMATRIXIDXATT",
  "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
  "BASEMATRIXSTARTROWATT", "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT",
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "EMPTYBASETRANSPOSEATT",
  "BASETRANSPOSEATT", "ELEMENTSSTART", "ELEMENTSEND",
  "CONSTANTELEMENTSSTART", "CONSTANTELEMENTSEND", "STARTVECTORSTART",
  "STARTVECTOREND", "NONZEROSSTART", "NONZEROSEND", "INDEXESSTART",
  "INDEXESEND", "VALUESSTART", "VALUESEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "GENERALELEMENTSSTART", "GENERALELEMENTSEND",
  "CONREFERENCEELEMENTSSTART", "CONREFERENCEELEMENTSEND", "VALUETYPEATT",
  "OBJREFERENCEELEMENTSSTART", "OBJREFERENCEELEMENTSEND",
  "PATTERNELEMENTSSTART", "PATTERNELEMENTSEND", "VARIDXSTART", "VARIDXEND",
  "TRANSFORMATIONSTART", "TRANSFORMATIONEND", "COLOFFSETSSTART",
  "COLOFFSETSEND", "ROWOFFSETSSTART", "ROWOFFSETSEND", "EMPTYROWMAJORATT",
  "ROWMAJORATT", "BLOCKROWIDXATT", "BLOCKCOLIDXATT", "DUMMY",
  "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND",
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
  "IDATT", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept", "osoldoc",
  "osolStartEmpty", "osolStart", "osolAttributes", "osolContent",
  "osolEmpty", "osolLaden", "osolEnd", "osolEnding", "osolBody",
  "headerElement", "generalElement", "generalElementStart",
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
  "otherGeneralOption", "otherGeneralOptionStart",
  "otherGeneralAttributes", "otherGeneralAttList", "otherGeneralAtt",
  "otherGeneralEnd", "systemElement", "systemElementStart",
  "systemElementContent", "systemElementEmpty", "systemElementLaden",
  "systemElementBody", "systemElementList", "systemChild", "minDiskSpace",
  "minDiskSpaceStart", "minDiskSpaceAttributes", "minDiskSpaceAttList",
  "minDiskSpaceAtt", "minDiskSpaceContent", "minDiskSpaceValue",
  "minMemorySize", "minMemoryStart", "minMemoryAttributes",
  "minMemoryAttList", "minMemoryAtt", "minMemoryContent", "minMemoryValue",
  "minCPUSpeed", "minCPUSpeedStart", "minCPUSpeedAttributes",
  "minCPUSpeedAttList", "minCPUSpeedAtt", "minCPUSpeedContent",
  "minCPUSpeedValue", "minCPUNumber", "minCPUNumberStart",
  "minCPUNumberAttributes", "minCPUNumberContent", "minCPUNumberValue",
  "otherSystemOptions", "otherSystemOptionsStart",
  "otherSystemOptionsAttributes", "otherSystemOptionsContent",
  "otherSystemOptionsEmpty", "otherSystemOptionsLaden",
  "otherSystemOptionsBody", "otherSystemOptionArray", "otherSystemOption",
  "otherSystemOptionStart", "otherSystemOptionAttributes",
  "otherSystemOptionAttList", "otherSystemOptionAtt",
  "otherSystemOptionEnd", "serviceElement", "serviceElementStart",
  "serviceElementContent", "serviceElementEmpty", "serviceElementLaden",
  "serviceElementBody", "serviceElementList", "serviceChild",
  "serviceType", "serviceTypeStart", "serviceTypeContent",
  "serviceTypeEmpty", "serviceTypeLaden", "serviceTypeBody",
  "otherServiceOptions", "otherServiceOptionsStart",
  "otherServiceOptionsAttributes", "otherServiceOptionsContent",
  "otherServiceOptionsEmpty", "otherServiceOptionsLaden",
  "otherServiceOptionsBody", "otherServiceOptionArray",
  "otherServiceOption", "otherServiceOptionStart",
  "otherServiceOptionAttributes", "otherServiceOptionAttList",
  "otherServiceOptionAtt", "otherServiceOptionEnd", "jobElement",
  "jobElementStart", "jobElementContent", "jobElementEmpty",
  "jobElementLaden", "jobElementBody", "jobElementList", "jobChild",
  "maxTime", "maxTimeStart", "maxTimeAttributes", "maxTimeContent",
  "maxTimeEmpty", "maxTimeLaden", "maxTimeBody", "maxTimeValue",
  "requestedStartTime", "requestedStartTimeStart",
  "requestedStartTimeContent", "requestedStartTimeEmpty",
  "requestedStartTimeLaden", "requestedStartTimeBody", "dependencies",
  "dependenciesStart", "dependenciesAttributes", "dependenciesContent",
  "dependenciesEmpty", "dependenciesLaden", "dependenciesList",
  "dependencyJobID", "requiredDirectories", "requiredDirectoriesStart",
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
  "otherJobOptionStart", "otherJobOptionAttributes",
  "otherJobOptionAttList", "otherJobOptionAtt", "otherJobOptionEnd",
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
  "variableInitialBasisBody", "variablesBasic", "variablesBasicStart",
  "variablesBasicNumberOfElATT", "variablesBasicContent",
  "variablesBasicEmpty", "variablesBasicLaden", "variablesBasicBody",
  "variablesAtLower", "variablesAtLowerStart",
  "variablesAtLowerNumberOfElATT", "variablesAtLowerContent",
  "variablesAtLowerEmpty", "variablesAtLowerLaden", "variablesAtLowerBody",
  "variablesAtUpper", "variablesAtUpperStart",
  "variablesAtUpperNumberOfElATT", "variablesAtUpperContent",
  "variablesAtUpperEmpty", "variablesAtUpperLaden", "variablesAtUpperBody",
  "variablesAtEquality", "variablesAtEqualityStart",
  "variablesAtEqualityNumberOfElATT", "variablesAtEqualityContent",
  "variablesAtEqualityEmpty", "variablesAtEqualityLaden",
  "variablesAtEqualityBody", "variablesIsFree", "variablesIsFreeStart",
  "variablesIsFreeNumberOfElATT", "variablesIsFreeContent",
  "variablesIsFreeEmpty", "variablesIsFreeLaden", "variablesIsFreeBody",
  "variablesSuperbasic", "variablesSuperbasicStart",
  "variablesSuperbasicNumberOfElATT", "variablesSuperbasicContent",
  "variablesSuperbasicEmpty", "variablesSuperbasicLaden",
  "variablesSuperbasicBody", "variablesUnknown", "variablesUnknownStart",
  "variablesUnknownNumberOfElATT", "variablesUnknownContent",
  "variablesUnknownEmpty", "variablesUnknownLaden", "variablesUnknownBody",
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
  "objectiveInitialBasisBody", "objectivesBasic", "objectivesBasicStart",
  "objectivesBasicNumberOfElATT", "objectivesBasicContent",
  "objectivesBasicEmpty", "objectivesBasicLaden", "objectivesBasicBody",
  "objectivesAtLower", "objectivesAtLowerStart",
  "objectivesAtLowerNumberOfElATT", "objectivesAtLowerContent",
  "objectivesAtLowerEmpty", "objectivesAtLowerLaden",
  "objectivesAtLowerBody", "objectivesAtUpper", "objectivesAtUpperStart",
  "objectivesAtUpperNumberOfElATT", "objectivesAtUpperContent",
  "objectivesAtUpperEmpty", "objectivesAtUpperLaden",
  "objectivesAtUpperBody", "objectivesAtEquality",
  "objectivesAtEqualityStart", "objectivesAtEqualityNumberOfElATT",
  "objectivesAtEqualityContent", "objectivesAtEqualityEmpty",
  "objectivesAtEqualityLaden", "objectivesAtEqualityBody",
  "objectivesIsFree", "objectivesIsFreeStart",
  "objectivesIsFreeNumberOfElATT", "objectivesIsFreeContent",
  "objectivesIsFreeEmpty", "objectivesIsFreeLaden", "objectivesIsFreeBody",
  "objectivesSuperbasic", "objectivesSuperbasicStart",
  "objectivesSuperbasicNumberOfElATT", "objectivesSuperbasicContent",
  "objectivesSuperbasicEmpty", "objectivesSuperbasicLaden",
  "objectivesSuperbasicBody", "objectivesUnknown",
  "objectivesUnknownStart", "objectivesUnknownNumberOfElATT",
  "objectivesUnknownContent", "objectivesUnknownEmpty",
  "objectivesUnknownLaden", "objectivesUnknownBody",
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
  "slacksBasicStart", "slacksBasicNumberOfElATT", "slacksBasicContent",
  "slacksBasicEmpty", "slacksBasicLaden", "slacksBasicBody",
  "slacksAtLower", "slacksAtLowerStart", "slacksAtLowerNumberOfElATT",
  "slacksAtLowerContent", "slacksAtLowerEmpty", "slacksAtLowerLaden",
  "slacksAtLowerBody", "slacksAtUpper", "slacksAtUpperStart",
  "slacksAtUpperNumberOfElATT", "slacksAtUpperContent",
  "slacksAtUpperEmpty", "slacksAtUpperLaden", "slacksAtUpperBody",
  "slacksAtEquality", "slacksAtEqualityStart",
  "slacksAtEqualityNumberOfElATT", "slacksAtEqualityContent",
  "slacksAtEqualityEmpty", "slacksAtEqualityLaden", "slacksAtEqualityBody",
  "slacksIsFree", "slacksIsFreeStart", "slacksIsFreeNumberOfElATT",
  "slacksIsFreeContent", "slacksIsFreeEmpty", "slacksIsFreeLaden",
  "slacksIsFreeBody", "slacksSuperbasic", "slacksSuperbasicStart",
  "slacksSuperbasicNumberOfElATT", "slacksSuperbasicContent",
  "slacksSuperbasicEmpty", "slacksSuperbasicLaden", "slacksSuperbasicBody",
  "slacksUnknown", "slacksUnknownStart", "slacksUnknownNumberOfElATT",
  "slacksUnknownContent", "slacksUnknownEmpty", "slacksUnknownLaden",
  "slacksUnknownBody", "otherConstraintOptionsArray",
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
  "categoryAttribute", "categoryAtt", "categoryAttEmpty",
  "categoryAttContent", "conTypeAttribute", "conTypeAtt",
  "conTypeAttEmpty", "conTypeAttContent", "descriptionAttribute",
  "descriptionAtt", "descriptionAttEmpty", "descriptionAttContent",
  "enumTypeAttribute", "enumTypeAtt", "enumTypeAttEmpty",
  "enumTypeAttContent", "groupWeightAttribute", "groupWeightAtt",
  "idxAttribute", "idxAtt", "idxAttContent", "lbValueAttribute",
  "lbValueAtt", "lbValueAttEmpty", "lbValueAttContent",
  "lbDualValueAttribute", "lbDualValueAtt", "lbDualValueAttEmpty",
  "lbDualValueAttContent", "nameAttribute", "nameAtt", "nameAttEmpty",
  "nameAttContent", "objTypeAttribute", "objTypeAtt", "objTypeAttEmpty",
  "objTypeAttContent", "solverAttribute", "solverAtt", "solverAttEmpty",
  "solverAttContent", "sosIdxAttribute", "sosIdxAtt", "sosIdxAttContent",
  "typeAttribute", "typeAtt", "typeAttEmpty", "typeAttContent",
  "ubValueAttribute", "ubValueAtt", "ubValueAttEmpty", "ubValueAttContent",
  "ubDualValueAttribute", "ubDualValueAtt", "ubDualValueAttEmpty",
  "ubDualValueAttContent", "unitAttribute", "unitAtt", "unitAttEmpty",
  "unitAttContent", "valueAttribute", "valueAtt", "valueAttEmpty",
  "valueAttContent", "varTypeAttribute", "varTypeAtt", "varTypeAttEmpty",
  "varTypeAttContent", "numberOfConAttribute",
  "numberOfConstraintsAttribute", "numberOfElAttribute",
  "numberOfEnumerationsAttribute", "numberOfItemsAttribute",
  "numberOfJobIDsATT", "numberOfObjAttribute",
  "numberOfObjectivesAttribute", "numberOfOtherConstraintOptionsAttribute",
  "numberOfOtherObjectiveOptionsAttribute",
  "numberOfOtherOptionsAttribute", "numberOfOtherVariableOptionsAttribute",
  "numberOfPathPairsAttribute", "numberOfPathsAttribute",
  "numberOfProcessesATT", "numberOfSolverOptionsAttribute",
  "numberOfVarAttribute", "numberOfVariablesAttribute",
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
  "osglIntVectorBase64Laden", "osglBase64SizeATT", "osglIncrATT",
  "osglMultATT", 0
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
     665,   666,   667,   668,   669,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   419,   420,   420,   421,   422,   423,   423,   424,   424,
     425,   426,   427,   428,   428,   429,   430,   430,   431,   431,
     432,   433,   433,   434,   434,   435,   436,   437,   437,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     439,   440,   441,   441,   442,   442,   443,   444,   445,   446,
     447,   447,   448,   448,   449,   450,   451,   452,   453,   453,
     454,   454,   455,   456,   457,   458,   459,   459,   460,   461,
     461,   462,   462,   463,   464,   465,   466,   467,   467,   468,
     468,   469,   470,   471,   472,   473,   473,   474,   474,   475,
     476,   477,   478,   479,   479,   480,   480,   481,   482,   483,
     484,   485,   485,   486,   486,   487,   488,   489,   490,   491,
     491,   492,   492,   493,   494,   495,   496,   497,   497,   498,
     499,   499,   500,   500,   501,   502,   503,   504,   505,   506,
     506,   507,   507,   508,   509,   510,   510,   511,   512,   513,
     514,   514,   515,   515,   515,   516,   516,   517,   517,   518,
     519,   519,   520,   520,   521,   522,   523,   523,   524,   524,
     524,   524,   524,   525,   526,   527,   528,   528,   529,   529,
     530,   531,   532,   533,   534,   535,   535,   536,   536,   537,
     538,   539,   540,   541,   542,   542,   543,   543,   544,   545,
     546,   547,   548,   548,   549,   550,   551,   552,   553,   554,
     554,   555,   555,   556,   557,   558,   558,   559,   560,   561,
     562,   562,   563,   563,   563,   564,   564,   565,   565,   566,
     567,   567,   568,   568,   569,   570,   571,   571,   572,   572,
     573,   574,   575,   575,   576,   576,   577,   578,   579,   580,
     581,   582,   582,   583,   583,   584,   585,   586,   586,   587,
     588,   589,   590,   590,   591,   591,   591,   592,   592,   593,
     593,   594,   595,   595,   596,   596,   597,   598,   599,   599,
     600,   600,   600,   600,   600,   600,   600,   600,   600,   600,
     600,   600,   600,   600,   600,   601,   602,   603,   603,   604,
     604,   605,   605,   606,   607,   608,   609,   610,   611,   611,
     612,   612,   613,   614,   615,   616,   617,   618,   618,   619,
     619,   620,   621,   621,   622,   623,   624,   625,   625,   626,
     626,   627,   628,   629,   630,   630,   631,   631,   632,   633,
     634,   635,   635,   636,   636,   637,   638,   639,   640,   640,
     641,   641,   642,   643,   644,   645,   646,   646,   647,   647,
     648,   649,   649,   650,   651,   652,   653,   654,   654,   655,
     655,   656,   657,   657,   658,   659,   660,   661,   662,   662,
     663,   663,   664,   665,   665,   666,   667,   668,   669,   670,
     670,   671,   671,   672,   673,   673,   674,   675,   676,   677,
     678,   678,   679,   679,   680,   681,   682,   683,   684,   684,
     685,   685,   686,   687,   688,   689,   690,   690,   691,   691,
     692,   693,   693,   694,   695,   696,   697,   698,   698,   699,
     699,   700,   701,   702,   702,   703,   704,   705,   706,   706,
     707,   707,   707,   708,   708,   709,   709,   710,   711,   712,
     712,   713,   713,   713,   714,   714,   715,   716,   717,   718,
     718,   719,   720,   721,   721,   722,   722,   723,   724,   725,
     726,   726,   727,   728,   729,   729,   730,   730,   731,   732,
     733,   733,   734,   735,   736,   737,   737,   738,   738,   738,
     739,   739,   740,   740,   741,   742,   743,   743,   744,   744,
     745,   746,   747,   747,   748,   749,   750,   751,   751,   752,
     752,   752,   753,   753,   754,   754,   755,   756,   756,   757,
     758,   759,   760,   760,   761,   762,   763,   763,   764,   765,
     766,   767,   767,   768,   769,   770,   770,   771,   772,   773,
     774,   774,   775,   776,   777,   777,   778,   779,   780,   781,
     781,   782,   783,   784,   784,   785,   786,   787,   788,   788,
     789,   790,   791,   791,   792,   793,   794,   795,   795,   796,
     797,   798,   798,   799,   800,   801,   802,   802,   803,   804,
     805,   805,   806,   807,   808,   809,   809,   810,   811,   812,
     812,   813,   813,   814,   815,   816,   816,   817,   818,   819,
     820,   820,   821,   821,   821,   822,   822,   823,   823,   824,
     825,   826,   826,   827,   827,   828,   829,   829,   830,   831,
     832,   833,   833,   834,   834,   834,   835,   835,   836,   836,
     837,   838,   838,   839,   840,   841,   842,   842,   843,   843,
     843,   843,   843,   843,   843,   843,   843,   843,   844,   844,
     845,   845,   846,   847,   847,   848,   848,   849,   850,   851,
     852,   852,   853,   853,   853,   853,   853,   854,   855,   855,
     856,   856,   857,   858,   859,   859,   860,   860,   861,   862,
     863,   864,   864,   865,   866,   867,   867,   868,   868,   869,
     870,   871,   871,   872,   873,   874,   875,   875,   876,   876,
     876,   877,   877,   878,   878,   879,   880,   881,   881,   882,
     882,   883,   884,   885,   885,   886,   887,   888,   889,   889,
     890,   890,   890,   890,   891,   891,   892,   892,   893,   894,
     894,   895,   896,   897,   898,   898,   899,   900,   901,   901,
     902,   903,   904,   905,   905,   906,   907,   908,   908,   909,
     910,   911,   912,   912,   913,   914,   915,   915,   916,   917,
     918,   919,   919,   920,   921,   922,   922,   923,   924,   925,
     926,   926,   927,   928,   929,   929,   930,   931,   932,   933,
     933,   934,   935,   936,   936,   937,   938,   939,   940,   940,
     941,   942,   943,   943,   944,   945,   946,   947,   947,   948,
     949,   950,   951,   951,   952,   952,   952,   952,   952,   952,
     952,   952,   952,   952,   953,   953,   954,   954,   955,   956,
     956,   957,   957,   958,   959,   960,   961,   961,   962,   962,
     962,   962,   962,   963,   964,   964,   965,   965,   966,   967,
     968,   968,   969,   969,   970,   971,   972,   973,   973,   974,
     975,   976,   976,   977,   977,   978,   979,   980,   980,   981,
     982,   983,   984,   984,   985,   985,   985,   986,   986,   987,
     987,   988,   989,   990,   990,   991,   991,   992,   993,   994,
     994,   995,   996,   997,   998,   998,   999,   999,   999,   999,
    1000,  1000,  1001,  1001,  1002,  1003,  1003,  1004,  1005,  1006,
    1007,  1007,  1008,  1009,  1010,  1010,  1011,  1012,  1013,  1014,
    1014,  1015,  1016,  1017,  1017,  1018,  1019,  1020,  1021,  1021,
    1022,  1023,  1024,  1024,  1025,  1026,  1027,  1028,  1028,  1029,
    1030,  1031,  1031,  1032,  1033,  1034,  1035,  1035,  1036,  1037,
    1038,  1038,  1039,  1040,  1041,  1042,  1042,  1043,  1044,  1045,
    1045,  1046,  1047,  1048,  1049,  1049,  1050,  1051,  1052,  1052,
    1053,  1054,  1055,  1056,  1056,  1057,  1058,  1059,  1060,  1060,
    1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,
    1062,  1062,  1063,  1063,  1064,  1065,  1065,  1066,  1066,  1067,
    1068,  1069,  1070,  1070,  1071,  1071,  1071,  1071,  1071,  1072,
    1073,  1073,  1074,  1074,  1075,  1076,  1077,  1077,  1078,  1079,
    1080,  1080,  1081,  1082,  1083,  1084,  1084,  1085,  1085,  1085,
    1085,  1085,  1085,  1085,  1086,  1086,  1087,  1087,  1088,  1089,
    1090,  1090,  1091,  1092,  1092,  1093,  1093,  1094,  1095,  1096,
    1096,  1097,  1098,  1099,  1100,  1101,  1101,  1102,  1102,  1102,
    1103,  1104,  1105,  1106,  1106,  1107,  1108,  1108,  1109,  1110,
    1111,  1112,  1112,  1113,  1114,  1115,  1116,  1116,  1117,  1118,
    1119,  1120,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,
    1128,  1129,  1129,  1130,  1131,  1132,  1133,  1133,  1134,  1135,
    1136,  1137,  1137,  1138,  1139,  1140,  1141,  1141,  1142,  1143,
    1144,  1145,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1152,  1153,  1154,  1155,  1156,  1156,  1157,  1158,  1159,  1160,
    1160,  1161,  1162,  1163,  1164,  1164,  1165,  1166,  1167,  1168,
    1168,  1169,  1170,  1171,  1172,  1172,  1173,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1192,  1193,  1193,  1194,  1195,
    1196,  1197,  1197,  1198,  1198,  1198,  1199,  1199,  1200,  1201,
    1202,  1203,  1203,  1204,  1205,  1205,  1206,  1206,  1206,  1206,
    1207,  1208,  1209,  1209,  1210,  1211,  1212,  1213,  1213,  1214,
    1214,  1214,  1214,  1214,  1215,  1216,  1216,  1217,  1217,  1218,
    1219,  1220,  1220,  1221,  1221,  1222,  1223,  1224,  1224,  1225,
    1225,  1226,  1227,  1228,  1228,  1229,  1229,  1230,  1231,  1232,
    1232,  1233,  1233,  1234,  1235,  1235,  1236,  1236,  1237,  1238,
    1239,  1240,  1240,  1241,  1241,  1242,  1243,  1244,  1244,  1245,
    1245,  1246,  1247,  1248,  1249
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
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       2,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     4,     3,     1,     1,     1,     2,
       1,     3,     3,     1,     1,     1,     2,     1,     3,     3,
       1,     1,     1,     2,     1,     3,     3,     1,     1,     1,
       2,     1,     3,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     3,     1,     1,     1,     1,
       2,     1,     3,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     4,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     0,
       3,     1,     1,     0,     1,     1,     1,     1,     3,     6,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       2,     1,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     0,     2,     1,     1,     1,     1,
       3,     7,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     3,     1,
       4,     1,     1,     2,     1,     3,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     2,     1,
       3,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     3,     1,     1,     0,     1,     1,     1,     1,     3,
       4,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     2,     1,     0,     2,     1,     1,
       1,     1,     3,     7,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     0,     3,     1,     1,
       0,     1,     1,     1,     1,     3,     4,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       2,     1,     0,     2,     1,     1,     1,     1,     3,     7,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       0,     2,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     4,     3,     1,     1,     0,     2,     1,     1,     1,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     4,     1,     1,     4,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     4,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     3,     3,     1,     1,     2,
       1,     3,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,  1171,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   147,     0,
    1177,  1174,  1170,  1172,  1173,    16,    10,     3,     8,     9,
     149,   217,     0,     0,    24,    19,    21,    22,     0,  1176,
      14,   219,   259,     0,     0,   153,   148,   150,   151,    23,
      41,    49,    57,    65,    76,    84,    92,   100,   108,   116,
     127,     0,    26,    27,    29,     0,    30,     0,    31,     0,
      32,    66,    33,     0,    34,     0,    35,     0,    36,     0,
      37,     0,    38,   117,    39,     0,  1175,     0,  1188,  1187,
       0,  1194,  1193,     0,  1200,  1199,     0,  1206,  1205,     0,
    1212,  1211,  1178,  1179,  1184,  1185,  1186,  1180,  1190,  1191,
    1192,  1181,  1196,  1197,  1198,  1182,  1202,  1203,  1204,  1183,
    1208,  1209,  1210,    11,   261,   435,     0,     0,   223,   218,
     220,   221,   152,   197,   164,   173,   182,   191,     0,   155,
     156,   158,   166,   159,   175,   160,   184,   161,   192,   162,
       0,    25,    28,     0,    45,    40,    42,    43,     0,    53,
      48,    50,    51,     0,    61,    56,    58,    59,     0,     0,
      67,     0,    80,    75,    77,    78,     0,    88,    83,    85,
      86,     0,    96,    91,    93,    94,     0,   104,    99,   101,
     102,     0,   112,   107,   109,   110,     0,     0,   118,  1164,
       0,   128,     0,     0,     0,     0,     0,   437,    15,   439,
       0,   265,   260,   262,   263,   222,   239,   231,     0,   225,
     226,   228,     0,   229,     0,   154,   157,     0,   165,     0,
     174,     0,   183,     0,  1058,     0,   193,  1055,  1056,  1057,
       0,   198,    47,    44,     0,    55,    52,     0,    63,    60,
       0,     0,     0,    72,    64,    69,    70,    82,    79,     0,
      90,    87,     0,    98,    95,     0,   106,   103,     0,   114,
     111,     0,     0,     0,   123,   115,   120,   121,     0,     0,
       0,   132,   126,   129,   130,  1189,  1195,  1201,  1207,  1213,
       0,   438,   264,   415,   286,   297,   305,   316,   323,   330,
     337,   396,   388,   344,   355,   377,   366,   404,     0,   267,
     268,   270,   287,   271,     0,   272,     0,   273,     0,   274,
       0,   275,     0,   276,     0,   277,     0,   278,     0,   280,
       0,   279,     0,   281,     0,   282,     0,   283,     0,   284,
       0,   224,   227,     0,   235,   230,   232,   233,     0,   240,
       0,   163,     0,  1116,   167,   169,   168,  1113,  1114,  1115,
       0,   172,   176,   178,   177,     0,   181,   185,   187,   186,
    1164,     0,   190,     0,   202,   196,   199,   200,    46,    54,
      62,    68,    74,    71,     0,    81,    89,    97,   105,   113,
     119,   125,   122,     0,  1164,  1163,  1166,  1167,  1168,  1169,
    1165,   131,   138,     0,   134,   135,   140,   449,   446,   436,
     444,   445,  1164,  1164,  1164,   440,   442,   443,   441,   266,
     269,     0,   288,     0,   301,   296,   298,   299,     0,     0,
     306,     0,     0,     0,     0,     0,     0,     0,   345,     0,
     356,     0,   367,     0,   378,     0,   389,     0,   397,     0,
       0,   405,     0,   416,   237,   234,     0,     0,   244,   238,
     241,   242,  1161,  1162,     0,   171,     0,     0,   180,     0,
     189,  1059,   195,     0,   201,   208,     0,   204,   205,   210,
      73,   124,  1138,   133,   136,     0,   139,   451,     0,   660,
     453,     0,     0,     0,     0,   292,   285,   289,   290,   303,
     300,     0,     0,     0,   310,   304,   307,   308,     0,     0,
     320,   315,   317,   318,     0,   327,   322,   324,   325,     0,
     334,   329,   331,   332,     0,   341,   336,   338,   339,     0,
       0,   349,   343,   346,   347,     0,   360,   354,   357,   358,
       0,   371,   365,   368,   369,     0,   382,   376,   379,   380,
       0,   393,   387,   390,   391,     0,   401,   395,   398,   399,
       0,     0,   409,   403,   406,   407,     0,   420,   414,   417,
     418,   236,   243,   250,     0,   246,   247,   252,   170,  1117,
     179,   188,   194,   203,   206,     0,   209,     0,   146,   137,
       0,     0,  1083,  1121,   141,   144,   142,  1080,  1081,  1082,
     143,  1118,  1119,  1120,   447,   662,   826,   664,  1164,     0,
     452,   454,  1164,  1164,  1164,   291,     0,   294,   295,   302,
       0,     0,   309,     0,   312,     0,   319,     0,     0,  1029,
     326,     0,   333,     0,   340,     0,     0,  1033,   348,     0,
     351,   353,  1035,   359,     0,   362,   364,   370,     0,   373,
     375,   381,     0,   384,   386,   392,     0,   400,     0,     0,
     408,     0,     0,   411,   419,   426,     0,   422,   423,   428,
     245,   248,     0,   251,     0,   216,   207,   211,   214,   212,
     213,   145,  1164,     0,   828,   992,   830,  1164,     0,   663,
     665,     0,   460,   457,   450,   455,   456,  1145,  1135,  1129,
     293,  1133,     0,   311,   313,  1141,     0,   321,  1030,   328,
     335,   342,  1140,   350,   352,     0,  1034,   361,   363,   372,
     374,   383,   385,   394,   402,  1142,     0,   410,   412,   421,
     424,     0,   427,     0,   258,   249,   253,   256,   254,   255,
     215,  1084,  1122,   994,   448,     0,  1164,     0,   829,   831,
       0,   671,   668,   661,   666,   667,  1164,   462,     0,   482,
       0,     0,     0,     0,  1044,  1032,     0,     0,     0,  1036,
    1037,  1038,  1039,     0,     0,   434,   425,   429,   432,   430,
     431,   257,  1164,     0,   995,     0,   837,   834,   827,   832,
     833,  1164,   673,     0,   693,     0,  1139,   458,   484,   504,
       0,  1164,     0,   463,   314,  1031,  1043,     0,     0,     0,
     413,   433,     0,  1000,   998,   993,   996,   997,  1164,   839,
       0,   859,     0,  1137,   669,   695,   716,     0,  1164,     0,
     674,   506,   575,     0,     0,   485,     0,     0,   467,   461,
     464,   465,  1040,  1041,  1042,  1164,     0,  1136,   835,   861,
     882,     0,  1164,     0,   840,   718,   787,     0,     0,   696,
       0,     0,   678,   672,   675,   676,   577,   597,     0,   512,
     509,   505,   507,   508,     0,   489,   483,   486,   487,  1164,
     466,   473,     0,   469,   470,   475,  1143,   999,  1003,  1001,
       0,   884,   953,     0,     0,   862,     0,     0,   844,   838,
     841,   842,   670,   724,   721,   717,   719,   720,     0,   700,
     694,   697,   698,  1164,   677,   684,     0,   680,   681,   686,
     599,   621,     0,     0,   578,   514,     0,   521,     0,   495,
     488,     0,   491,   492,   497,  1144,   468,   471,     0,   474,
       0,     0,  1164,  1101,  1048,     0,  1093,     0,  1004,  1005,
    1010,  1045,  1046,  1047,  1012,  1007,  1009,  1090,  1091,  1092,
    1011,  1098,  1099,  1100,  1008,  1013,   836,   890,   887,   883,
     885,   886,     0,   866,   860,   863,   864,  1164,   843,   850,
       0,   846,   847,   852,   790,   788,   792,   726,     0,   733,
       0,   706,   699,     0,   702,   703,   708,  1134,   679,   682,
       0,   685,   459,     0,     0,     0,   582,   576,   579,   580,
     510,   523,   530,     0,  1164,     0,   515,   490,   493,     0,
     496,     0,   481,   472,  1164,   476,   477,  1067,  1068,   478,
     479,  1164,     0,     0,  1164,     0,  1017,  1002,  1014,  1015,
    1006,   956,   954,   958,   892,     0,   899,     0,   872,   865,
       0,   868,   869,   874,  1128,   845,   848,     0,   851,     0,
     791,   722,   735,   742,     0,     0,   727,   701,   704,     0,
     707,     0,   692,   683,   687,   688,   689,   690,   624,   622,
     626,     0,     0,   604,   598,   601,   602,   588,   581,     0,
     584,   585,   590,   532,   539,     0,     0,   524,     0,  1216,
     518,   513,   516,   517,     0,   503,   494,   498,   499,   500,
     501,   480,     0,  1049,  1102,  1164,  1094,  1016,  1026,     0,
    1025,     0,  1019,  1020,  1022,  1023,  1024,     0,   957,   888,
     901,   908,     0,     0,   893,   867,   870,     0,   873,     0,
     858,   849,   853,   854,   855,   856,     0,   807,   789,   804,
     805,  1164,     0,  1063,     0,  1088,   793,   799,   803,   802,
    1060,  1061,  1062,   796,   801,  1085,  1086,  1087,   798,   800,
     797,   795,   794,   744,   751,     0,     0,   736,  1216,   730,
     725,   728,   729,     0,   715,   705,  1073,  1106,     0,     0,
     709,   710,   712,  1070,  1071,  1072,   711,   713,  1103,  1104,
    1105,   691,     0,   625,     0,   603,   609,     0,   606,   611,
     583,   586,     0,   589,   541,   548,     0,     0,   533,  1216,
     527,   522,   525,   526,  1164,     0,     0,   520,  1214,  1215,
     502,  1164,  1132,  1028,     0,  1018,  1021,     0,   973,   955,
     970,   971,     0,  1053,   959,   965,   967,  1050,  1051,  1052,
     969,   968,   962,   964,   966,   963,   960,   961,   910,   917,
       0,     0,   902,  1216,   896,   891,   894,   895,     0,   881,
     871,  1078,  1111,  1164,  1164,   875,   876,   878,  1075,  1076,
    1077,   877,   879,  1108,  1109,  1110,   857,   806,   814,  1149,
       0,   809,   811,   816,   810,  1146,  1151,     0,     0,     0,
     753,   760,     0,     0,   745,  1216,   739,   734,   737,   738,
       0,   732,   714,  1164,  1164,     0,   641,   623,   638,   639,
       0,  1126,   627,   633,   637,   636,   630,   632,   634,   631,
     635,  1123,  1124,  1125,   629,   628,   600,   605,   607,     0,
     610,     0,   596,   587,   591,   592,   593,   594,   550,   557,
       0,     0,   542,  1216,   536,   531,   534,   535,     0,   529,
    1130,     0,     0,   519,  1219,  1217,  1221,  1069,  1027,   972,
     980,     0,   975,   977,   982,   976,     0,   919,   926,     0,
       0,   911,  1216,   905,   900,   903,   904,     0,   898,   880,
       0,     0,   808,   812,     0,   815,  1147,     0,  1150,  1164,
    1064,  1089,   762,   769,     0,     0,   754,  1216,   748,   743,
     746,   747,     0,   741,   731,  1074,  1107,   640,   648,     0,
     643,   645,   650,   644,     0,     0,   619,   608,   616,   617,
       0,  1164,   612,   615,  1065,   613,  1095,  1096,   614,   595,
     559,   566,     0,     0,   551,  1216,   545,   540,   543,   544,
       0,   538,   528,     0,     0,  1230,  1226,  1227,  1228,     0,
    1220,   974,   978,     0,   981,  1054,   928,   935,     0,     0,
     920,  1216,   914,   909,   912,   913,     0,   907,   897,  1164,
    1164,     0,   825,   813,   823,   817,   818,   821,   819,   822,
     820,  1216,  1158,  1148,  1156,  1157,  1155,  1154,  1153,  1152,
    1131,   771,   778,     0,     0,   763,  1216,   757,   752,   755,
     756,     0,   750,   740,   642,   646,     0,   649,  1127,   618,
       0,     0,     0,   568,   511,     0,     0,   560,  1216,   554,
     549,   552,   553,     0,   547,   537,     0,     0,  1229,     0,
    1218,     0,     0,  1222,  1224,  1223,     0,   991,   979,   989,
     983,   984,   987,   985,   988,   986,   937,   944,     0,     0,
     929,  1216,   923,   918,   921,   922,     0,   916,   906,  1079,
    1112,   824,     0,  1160,   780,   723,     0,     0,   772,  1216,
     766,   761,   764,   765,     0,   759,   749,     0,   659,   647,
     657,   651,   652,   655,   653,   656,   654,   620,     0,  1164,
       0,   569,  1216,   563,   558,   561,   562,     0,   556,   546,
    1232,  1231,     0,     0,     0,   990,   946,   889,     0,     0,
     938,  1216,   932,   927,   930,   931,     0,   925,   915,  1159,
       0,   781,  1216,   775,   770,   773,   774,     0,   768,   758,
     658,  1066,  1097,  1216,   572,   567,   570,   571,     0,   565,
     555,  1225,     0,     0,     0,   947,  1216,   941,   936,   939,
     940,     0,   934,   924,  1216,   784,   779,   782,   783,     0,
     777,   767,     0,   574,   564,  1233,  1234,  1216,   950,   945,
     948,   949,     0,   943,   933,     0,   786,   776,   573,     0,
     952,   942,   785,   951
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    27,    28,    29,    15,    16,
       8,     9,    18,    19,    35,    36,    37,    61,    62,    63,
      64,    65,   155,   156,   157,   244,    66,    67,   160,   161,
     162,   247,    68,    69,   165,   166,   167,   250,    70,    71,
     169,   170,   254,   255,   256,   384,    72,    73,   173,   174,
     175,   259,    74,    75,   178,   179,   180,   262,    76,    77,
     183,   184,   185,   265,    78,    79,   188,   189,   190,   268,
      80,    81,   193,   194,   195,   271,    82,    83,   197,   198,
     275,   276,   277,   393,    84,    85,   200,   282,   283,   284,
     403,   404,   405,   406,   485,   486,   594,   589,    31,    32,
      46,    47,    48,   138,   139,   140,   141,   142,   227,   228,
     354,   351,   464,   143,   144,   229,   230,   362,   361,   467,
     145,   146,   231,   232,   367,   366,   469,   147,   148,   235,
     372,   473,   149,   150,   240,   375,   376,   377,   476,   477,
     478,   479,   585,   586,   677,   676,    42,    43,   129,   130,
     131,   218,   219,   220,   221,   222,   345,   346,   347,   456,
     223,   224,   348,   459,   460,   461,   574,   575,   576,   577,
     672,   673,   736,   735,   125,   126,   212,   213,   214,   308,
     309,   310,   311,   312,   421,   496,   497,   498,   616,   617,
     313,   314,   425,   426,   427,   501,   315,   316,   429,   505,
     506,   507,   623,   624,   317,   318,   511,   512,   513,   319,
     320,   516,   517,   518,   321,   322,   521,   522,   523,   323,
     324,   526,   527,   528,   325,   326,   437,   532,   533,   534,
     639,   640,   327,   328,   439,   537,   538,   539,   644,   645,
     329,   330,   441,   542,   543,   544,   648,   649,   331,   332,
     443,   547,   548,   549,   652,   653,   333,   334,   445,   552,
     553,   554,   335,   336,   447,   557,   558,   559,   337,   338,
     450,   563,   564,   565,   662,   663,   339,   340,   452,   568,
     569,   570,   666,   667,   668,   669,   731,   732,   777,   776,
     208,   209,   290,   291,   415,   409,   410,   411,   488,   489,
     490,   609,   610,   694,   695,   696,   758,   759,   760,   802,
     839,   840,   841,   882,   883,   884,   885,   938,   939,  1025,
    1023,   799,   800,   834,   876,   877,   878,   931,   932,   933,
     934,  1019,  1020,  1107,  1106,   832,   833,   871,   872,   873,
     926,   927,   928,  1015,  1101,  1102,  1103,  1226,  1012,  1013,
    1096,  1221,  1222,  1223,  1358,  1094,  1095,  1217,  1355,  1356,
    1357,  1450,  1215,  1216,  1351,  1447,  1448,  1449,  1533,  1349,
    1350,  1443,  1530,  1531,  1532,  1607,  1441,  1442,  1526,  1604,
    1605,  1606,  1648,  1524,  1525,  1600,  1645,  1646,  1647,  1672,
     867,   868,   923,  1007,  1008,  1009,  1089,  1090,  1091,  1092,
    1212,  1213,  1344,  1343,   921,   922,  1004,  1084,  1085,  1086,
    1207,  1208,  1209,  1339,  1340,  1432,  1427,  1428,  1429,  1002,
    1079,  1080,  1202,  1203,  1322,  1317,  1318,  1319,  1419,  1420,
    1421,  1422,  1516,  1517,  1591,  1589,  1590,   606,   607,   688,
     689,   753,   754,   755,   793,   794,   795,   829,   863,   864,
     865,   916,   917,   918,   919,  1000,  1001,  1074,  1073,   826,
     827,   858,   910,   911,   912,   993,   994,   995,   996,  1069,
    1070,  1190,  1185,   856,   857,   905,   906,   907,   988,   989,
     990,  1065,  1180,  1181,  1182,  1310,  1063,  1064,  1176,  1307,
    1308,  1309,  1412,  1174,  1175,  1303,  1409,  1410,  1411,  1511,
    1301,  1302,  1405,  1508,  1509,  1510,  1584,  1403,  1404,  1504,
    1581,  1582,  1583,  1637,  1502,  1503,  1577,  1634,  1635,  1636,
    1669,  1575,  1576,  1630,  1666,  1667,  1668,  1685,   902,   985,
     986,  1059,  1060,  1156,  1148,  1149,  1150,  1290,  1291,  1292,
    1293,  1394,  1395,  1485,  1483,  1484,   685,   686,   747,   748,
     788,   789,   790,   820,   821,   822,   853,   899,   900,   901,
     980,   981,   982,   983,  1057,  1058,  1142,  1141,   850,   851,
     894,   974,   975,   976,  1050,  1051,  1052,  1053,  1137,  1138,
    1275,  1270,   892,   893,   969,   970,   971,  1045,  1046,  1047,
    1133,  1265,  1266,  1267,  1387,  1131,  1132,  1261,  1384,  1385,
    1386,  1476,  1259,  1260,  1380,  1473,  1474,  1475,  1566,  1378,
    1379,  1469,  1563,  1564,  1565,  1626,  1467,  1468,  1559,  1623,
    1624,  1625,  1661,  1557,  1558,  1619,  1658,  1659,  1660,  1682,
    1617,  1618,  1654,  1679,  1680,  1681,  1689,   966,  1042,  1043,
    1127,  1128,  1244,  1239,  1240,  1241,  1371,  1372,  1373,  1374,
    1463,  1464,  1550,  1548,  1549,   744,   745,   783,   815,   816,
     817,   846,   889,   890,   947,   948,   949,  1037,  1038,  1039,
    1121,  1122,  1123,  1124,  1125,  1126,  1234,   628,   629,   641,
     642,   715,   716,   769,   770,   771,   772,   765,   950,   951,
     952,   953,  1246,  1247,  1248,  1249,   954,   237,   238,   239,
    1159,  1160,  1161,  1162,  1433,  1434,  1026,  1027,  1028,  1192,
    1193,  1194,  1195,  1277,  1278,  1279,  1280,   955,   597,   598,
     599,  1164,  1165,  1166,  1167,   956,   957,   958,   959,  1435,
    1436,  1437,   960,   961,   962,   963,  1197,  1198,  1199,  1200,
    1282,  1283,  1284,  1285,   356,   357,   358,   359,   964,   601,
     602,   603,  1330,  1331,  1332,  1333,   854,   416,  1016,  1171,
     965,   430,   830,   417,   749,   690,   201,   611,   438,   432,
     451,   784,   803,   418,  1294,  1295,  1296,  1397,  1398,  1499,
    1493,  1494,  1495,  1572,   465,   278,   279,   400,    10,    11,
      22,    23,    24,    38,    39,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,  1227,  1228,  1365,  1366,
    1459,  1460,  1543,  1540,  1229,  1456,  1457,  1458,  1362,  1544,
    1545
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1374
static const yytype_int16 yypact[] =
{
     252, -1374, -1374,   102,  -166,    92, -1374, -1374,   166,   115,
   -1374,   300, -1374,   320, -1374, -1374, -1374, -1374,   137,   323,
   -1374, -1374, -1374, -1374, -1374,  -166, -1374, -1374, -1374, -1374,
   -1374,   169,   325,   304, -1374, -1374, -1374, -1374,     7,   394,
     166, -1374,   178,   336,    -2, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374,   196,   467, -1374, -1374,   338, -1374,   351, -1374,   353,
   -1374,   204, -1374,   404, -1374,   420, -1374,   424, -1374,   429,
   -1374,   431, -1374,   213, -1374,   285, -1374,   318, -1374, -1374,
     339, -1374, -1374,   363, -1374, -1374,   368, -1374, -1374,   374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374,   221,   433,   -27, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   247,   273,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   128, -1374,
     285, -1374, -1374,    37, -1374, -1374, -1374, -1374,    50, -1374,
   -1374, -1374, -1374,    28, -1374, -1374, -1374, -1374,   382,   435,
   -1374,    38, -1374, -1374, -1374, -1374,    33, -1374, -1374, -1374,
   -1374,    35, -1374, -1374, -1374, -1374,    25, -1374, -1374, -1374,
   -1374,    26, -1374, -1374, -1374, -1374,   387,   437, -1374, -1374,
     440, -1374,   116,   163,   161,   171,   157, -1374, -1374, -1374,
      74, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   330,    91,
   -1374, -1374,   442, -1374,   285, -1374, -1374,   390,   179,   402,
     179,   410,   179,   423, -1374,   418, -1374, -1374, -1374, -1374,
     444, -1374, -1374, -1374,   370, -1374, -1374,   349, -1374, -1374,
     375,   460,    45, -1374, -1374, -1374, -1374, -1374, -1374,   391,
   -1374, -1374,   385, -1374, -1374,   392, -1374, -1374,   406, -1374,
   -1374,   411,   484,    17, -1374, -1374, -1374, -1374,   517,     1,
     354, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
     453,   135, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   422,   470,
   -1374, -1374,    15, -1374,   462, -1374,   500, -1374,   528, -1374,
     528, -1374,   528, -1374,   528, -1374,   507, -1374,   507, -1374,
     507, -1374,   507, -1374,   528, -1374,   528, -1374,   515, -1374,
     285, -1374, -1374,    22, -1374, -1374, -1374, -1374,   464, -1374,
     471, -1374,   546, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
     471, -1374, -1374, -1374, -1374,   471, -1374, -1374, -1374, -1374,
   -1374,   547, -1374,   373, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374,   459, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374,   451, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374,   457,   450, -1374, -1374,   412, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374,   477, -1374,    12, -1374, -1374, -1374, -1374,   551,   486,
   -1374,   559,   498,   501,   506,   511,   563,   519, -1374,   521,
   -1374,   523, -1374,   525, -1374,   530, -1374,   535, -1374,   566,
     570, -1374,   575, -1374, -1374, -1374,   469,   492, -1374, -1374,
   -1374, -1374, -1374, -1374,   480, -1374,   584,   482, -1374,   488,
   -1374, -1374, -1374,   494, -1374, -1374,   529,   489, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374,   628,   314, -1374,   516,   421,
     573,   606,   608,   610,    27, -1374, -1374, -1374, -1374, -1374,
   -1374,   505,   617,   -45, -1374, -1374, -1374, -1374,   625,   -10,
   -1374, -1374, -1374, -1374,   512, -1374, -1374, -1374, -1374,    98,
   -1374, -1374, -1374, -1374,    76, -1374, -1374, -1374, -1374,   636,
     -34, -1374, -1374, -1374, -1374,   -80, -1374, -1374, -1374, -1374,
     -79, -1374, -1374, -1374, -1374,   -85, -1374, -1374, -1374, -1374,
     -28, -1374, -1374, -1374, -1374,    23, -1374, -1374, -1374, -1374,
     638,   499, -1374, -1374, -1374, -1374,   545, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374,   542,   554, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374,   643,   314,   612, -1374, -1374,
     742,   778, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374,   609,   768, -1374,   647,
   -1374, -1374, -1374, -1374, -1374, -1374,   679, -1374, -1374, -1374,
     793,   794, -1374,   -43, -1374,   795, -1374,   796,   105, -1374,
   -1374,   531, -1374,   113, -1374,    97,   797, -1374, -1374,    56,
   -1374, -1374, -1374, -1374,   -69, -1374, -1374, -1374,   -31, -1374,
   -1374, -1374,   -76, -1374, -1374, -1374,   100, -1374,    51,   799,
   -1374,   798,   513, -1374, -1374, -1374,   703,   705, -1374, -1374,
   -1374, -1374,   656,   314,   707, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374,   802, -1374,   614,   776, -1374,   658, -1374,
   -1374,   808,   661, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374,   813, -1374, -1374, -1374,   814, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374,   660,   269, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374,   815, -1374, -1374, -1374,
   -1374,   662,   314,   712, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374,   800, -1374,   664, -1374, -1374,
     816,   639, -1374, -1374, -1374, -1374, -1374, -1374,   667,   671,
     786,   732,   695,   697, -1374, -1374,   824,   828,   829, -1374,
   -1374, -1374, -1374,   681,   726, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374,   666, -1374,   830,   642, -1374, -1374, -1374,
   -1374, -1374, -1374,   653,   649,   801, -1374, -1374, -1374,   680,
     786, -1374,   668, -1374, -1374, -1374, -1374,   832,   834,   835,
   -1374, -1374,   838, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
     654,   648,   809, -1374, -1374, -1374,   686,   801, -1374,   670,
   -1374, -1374,   673,   672,   674, -1374,   843,   532, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374,   490, -1374, -1374, -1374,
     691,   809, -1374,   676, -1374, -1374, -1374,   682,   684, -1374,
     845,   510, -1374, -1374, -1374, -1374, -1374,   675,   786,   693,
   -1374, -1374, -1374, -1374,   122, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374,   701,   709, -1374, -1374, -1374, -1374, -1374, -1374,
     296, -1374, -1374,   688,   690, -1374,   847,   508, -1374, -1374,
   -1374, -1374,   752,   710, -1374, -1374, -1374, -1374,    83, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374,   677,   678, -1374, -1374,
   -1374, -1374,   831,   694, -1374, -1374,   699,   711,   818, -1374,
   -1374,   714,   718, -1374, -1374, -1374, -1374, -1374,   696,   162,
     861,   864, -1374, -1374, -1374,   865, -1374,   698,   296, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374,   762,   716, -1374, -1374,
   -1374, -1374,   104, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
     683,   685, -1374, -1374, -1374, -1374, -1374, -1374,   719,   720,
     818, -1374, -1374,   692,   689, -1374, -1374, -1374, -1374, -1374,
     700,   162,   763,   863,   702,    -3, -1374, -1374, -1374, -1374,
   -1374, -1374,   721,   818, -1374,   704, -1374, -1374, -1374,   706,
     162,   730, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374,   875,   866, -1374,   219, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374,   722,   724,   818, -1374, -1374,
     687,   728, -1374, -1374, -1374, -1374, -1374,   708,   162,   713,
     211, -1374, -1374,   734,   818,   715, -1374, -1374, -1374,   717,
     108,   736, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374,   883,   549, -1374, -1374, -1374, -1374, -1374, -1374,   737,
     735, -1374, -1374, -1374,   738,   818,   723, -1374,   884,   740,
   -1374, -1374, -1374, -1374,   744, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374,   887, -1374, -1374, -1374, -1374, -1374, -1374,   889,
   -1374,   746,    48, -1374, -1374, -1374, -1374,   725,   259, -1374,
   -1374,   754,   818,   727, -1374, -1374, -1374,   729,   117,   750,
   -1374, -1374, -1374, -1374, -1374, -1374,   -77, -1374, -1374, -1374,
   -1374, -1374,   892, -1374,   893, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374,   756,   818,   731, -1374,   740, -1374,
   -1374, -1374, -1374,   748, -1374, -1374, -1374, -1374,   894,   895,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374,   733,   445,   898, -1374, -1374,   567, -1374, -1374,
   -1374, -1374,   739,   162, -1374,   758,   818,   741, -1374,   740,
   -1374, -1374, -1374, -1374, -1374,   760,   764, -1374,   770, -1374,
   -1374, -1374, -1374, -1374,   771, -1374, -1374,   -73, -1374, -1374,
   -1374, -1374,   897, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   766,
     818,   743, -1374,   740, -1374, -1374, -1374, -1374,   772, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
     803,   774, -1374, -1374,   782, -1374, -1374,   902,   901,   908,
   -1374,   780,   818,   745, -1374,   740, -1374, -1374, -1374, -1374,
     788, -1374, -1374, -1374, -1374,   -61, -1374, -1374, -1374, -1374,
     900, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   747,
     151,   784, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   789,
     818,   749, -1374,   740, -1374, -1374, -1374, -1374,   790, -1374,
   -1374,   910,   751, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374,   812,   791, -1374, -1374,   782,   913, -1374,   792,   818,
     753, -1374,   740, -1374, -1374, -1374, -1374,   805, -1374, -1374,
     471,   471, -1374, -1374,   755,   233, -1374,   757,   299, -1374,
   -1374, -1374, -1374,   804,   818,   759, -1374,   740, -1374, -1374,
   -1374, -1374,   806, -1374, -1374, -1374, -1374, -1374, -1374,   819,
     807, -1374, -1374,   782,   914,   -90, -1374, -1374, -1374, -1374,
     918, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374,   817,   818,   761, -1374,   740, -1374, -1374, -1374, -1374,
     810, -1374, -1374,   904,     6, -1374, -1374, -1374, -1374,   891,
     562, -1374, -1374,   765,   233, -1374, -1374,   820,   818,   767,
   -1374,   740, -1374, -1374, -1374, -1374,   811, -1374, -1374, -1374,
   -1374,   821, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374,   740, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374,   822,   818,   769, -1374,   740, -1374, -1374, -1374,
   -1374,   823, -1374, -1374, -1374, -1374,   773,   233, -1374, -1374,
     -84,   471,   923, -1374, -1374,   818,   775, -1374,   740, -1374,
   -1374, -1374, -1374,   825, -1374, -1374,   922,   827, -1374,   926,
   -1374,   925,   929, -1374, -1374, -1374,   826, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374,   833,   818,   777,
   -1374,   740, -1374, -1374, -1374, -1374,   836, -1374, -1374, -1374,
   -1374, -1374,   837, -1374, -1374, -1374,   818,   779, -1374,   740,
   -1374, -1374, -1374, -1374,   840, -1374, -1374,   841, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   930, -1374,
     781, -1374,   740, -1374, -1374, -1374, -1374,   839, -1374, -1374,
   -1374, -1374,   842,   928,   933, -1374, -1374, -1374,   818,   783,
   -1374,   740, -1374, -1374, -1374, -1374,   844, -1374, -1374, -1374,
     785, -1374,   740, -1374, -1374, -1374, -1374,   846, -1374, -1374,
   -1374, -1374, -1374,   740, -1374, -1374, -1374, -1374,   849, -1374,
   -1374, -1374,   932,   935,   787, -1374,   740, -1374, -1374, -1374,
   -1374,   850, -1374, -1374,   740, -1374, -1374, -1374, -1374,   851,
   -1374, -1374,   852, -1374, -1374, -1374, -1374,   740, -1374, -1374,
   -1374, -1374,   853, -1374, -1374,   855, -1374, -1374, -1374,   858,
   -1374, -1374, -1374, -1374
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   907, -1374,
     916, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   888,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374,   550, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374,   848, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
     474, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374,   854, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   380, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374,   650, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374,   333, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374,   324, -1374, -1374, -1374, -1374, -1374, -1374, -1374,   313,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374,   319, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374,   310, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374,   308, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374,   305, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374,    88, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,    34,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374,  -448, -1084, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374,  -226, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
    -432, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374,    73, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374,    -1, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,  -297,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374,    19, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374,   -55, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,  -374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374,    53, -1374, -1374, -1374,
   -1374, -1374,  -119, -1374, -1374, -1374, -1374,  -456,  -480,  -517,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1043, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374,  -148, -1374, -1374, -1374,
   -1088, -1374, -1374, -1374, -1374, -1374,  -993, -1374, -1374, -1373,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374,  -482, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1041, -1374, -1374, -1374, -1374,
   -1374, -1374, -1040, -1374, -1374, -1374, -1371, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374,  -173, -1374, -1374, -1374,  -481, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374,  -840, -1374,  -975, -1062,
   -1374, -1374,  -814, -1374, -1374, -1374,  -138, -1374,    -6,    47,
   -1374, -1374,  -797, -1374, -1201, -1280, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374,  -358,  -369, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1095, -1374, -1374, -1374,
   -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374, -1374,
   -1374
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     236,   471,   468,   835,   596,   600,  1211,   470,  1075,   395,
    1537,   895,   241,   859,  1396,  1066,   499,  1157,   646,  1168,
    1169,   391,  1487,   650,  1489,   482,   454,  1108,   654,   266,
     269,  1287,   248,   462,   463,  1369,  1375,   260,  1097,   263,
    1251,   242,   257,   491,   492,   493,   637,  1417,   621,   382,
     621,   637,   637,   215,   245,   637,     7,   364,   631,   369,
     352,   651,   637,   633,   643,  1143,  1257,  1087,   635,   647,
     721,   924,  1134,  1087,   353,   717,   132,  1191,   216,   622,
     355,   703,   363,  1311,   368,  1245,   349,  1253,  1254,  1177,
     217,  1552,  1519,  1554,   656,  1396,  1418,   637,  1597,   658,
     637,   627,     6,   133,   679,   680,    12,   134,   638,   135,
    1288,   136,   655,   137,  1423,  1325,   626,   719,   249,   627,
    1218,   392,  1370,   243,  1359,   267,  1289,   646,   270,   261,
    1289,   650,   258,   264,   500,   654,   618,   383,   246,   422,
     455,  1334,  1289,  1396,  1593,  1276,  1595,   615,   708,   590,
    1024,   708,   627,   708,  1087,   708,   292,  1262,   590,  1024,
    1323,   657,  1327,  1328,   592,   412,   413,   414,  1388,  1186,
    1187,  1188,  1189,   592,   233,  1088,   708,  1430,   708,   293,
     627,    14,  1271,  1272,  1273,  1274,   234,   637,   801,   724,
      17,   738,   739,   294,  1431,   295,   216,   296,   713,   297,
    1304,   298,   453,   590,  1024,   627,   591,   299,   217,   300,
    1413,   301,   634,   302,    30,   303,  1538,   304,   592,   305,
    1345,   306,   593,   307,   352,   233,   627,   627,  1151,   627,
      86,   707,   632,   711,   627,   940,   941,   234,   353,   691,
     723,  1352,   627,   697,   698,   699,  1172,   710,    41,   828,
     779,   780,   590,  1118,  1119,   591,  1120,   233,  1451,   124,
    1152,  1153,  1154,  1155,     1,     2,   943,   592,   944,   234,
     991,   593,   151,   992,   590,  1024,  1151,   591,   168,   929,
     945,   946,   930,   940,   941,  1381,   196,  1477,  1256,   592,
     766,   767,   768,   593,  1186,  1187,  1188,  1189,   852,  1048,
     590,   199,  1049,   591,   207,   233,  1242,  1243,  1152,  1153,
      20,    21,  1512,   741,   943,   592,   944,   234,   750,   593,
     940,   941,   440,   202,   442,   225,   444,  1406,   945,   946,
      25,    26,   942,    33,    34,    44,    45,   590,   595,  1014,
     591,   285,   233,   591,   203,   233,   127,   128,   153,   154,
    1534,   943,   592,   944,   234,   590,   593,   234,   591,   593,
     233,   158,   159,   163,   164,   945,   946,   433,   204,   434,
     592,   435,   234,   205,   593,  1444,  1567,   785,   133,   206,
      49,   446,   134,   448,   135,   251,   136,   796,   137,    50,
     272,    51,   286,    52,   287,    53,  1573,    54,   289,    55,
     350,    56,  1486,    57,  1470,    58,  1335,    59,   288,    60,
     341,  1585,   360,   812,   171,   172,   396,   397,   398,   399,
     365,  1117,   823,  1498,  1118,  1119,   370,  1120,   371,  1505,
     176,   177,   836,  1608,   181,   182,  1211,   379,   678,   186,
     187,   191,   192,   210,   211,   252,   253,   273,   274,   847,
     280,   281,   343,   344,   373,   374,   378,  1029,  1030,   860,
     401,   402,  1151,   407,   408,   380,  1627,  1527,   381,   940,
     941,  1551,   423,   424,   457,   458,   886,   462,   463,   474,
     475,   386,   801,   896,  1638,   385,   590,   494,   495,   591,
     387,   233,   390,  1560,  1152,  1153,   503,   504,  1320,  1321,
     943,   592,   944,   234,   419,   593,   388,  1649,   509,   510,
     935,   514,   515,   389,   945,   946,   519,   520,   428,  1076,
    1077,   524,   525,   394,  1592,   737,  1662,   436,  1578,   530,
     531,   535,   536,   540,   541,   545,   546,  1670,  1109,  1110,
     550,   551,   449,  1438,   997,   555,   556,   431,  1673,   466,
    1601,   480,    50,   472,    51,   481,    52,   402,    53,   502,
      54,  1683,    55,   483,    56,   487,    57,   508,    58,  1686,
      59,   529,    60,  1033,   560,   293,  1144,  1145,  1163,  1170,
     561,   562,  1690,  1620,   778,   566,   567,   571,  1196,   294,
     578,   295,   579,   296,   580,   297,   475,   298,   572,   573,
     604,  1631,   581,   299,   605,   300,   608,   301,  1054,   302,
     582,   303,   612,   304,   613,   305,   614,   306,    87,   307,
      88,    89,    90,   620,    91,    92,    93,   619,    94,    95,
      96,   625,    97,    98,    99,   583,   100,   101,   587,   588,
     630,   627,   636,  1655,   659,  1098,  1252,  1255,   670,   660,
     661,   664,   665,   674,   675,  1112,  1281,   692,   693,   709,
     627,   573,  1113,   727,   661,  1116,   733,   734,   751,   752,
     763,   764,   774,   775,   786,   787,   813,   814,   837,   838,
     861,   862,   869,   870,   874,   875,   897,   898,   880,   881,
     887,   888,   903,   904,   908,   909,   914,   915,   967,   968,
     972,   973,   978,   979,  1005,  1006,  1021,  1022,  1035,  1036,
    1071,  1072,  1082,  1083,  1099,  1100,  1104,  1105,  1139,  1140,
     681,  1326,  1329,  1146,  1147,  1178,  1179,  1183,  1184,  1205,
    1206,  1346,  1347,  1219,  1220,  1237,  1238,  1263,  1264,  1268,
    1269,  1305,  1306,  1315,  1316,   682,  1232,  1337,  1206,  1341,
    1342,  1353,  1354,  1382,  1383,  1407,  1408,  1425,  1426,  1445,
    1446,  1454,  1455,  1471,  1472,  1481,  1482,  1491,  1492,  1506,
    1507,  1528,  1529,  1541,  1542,  1546,  1547,  1561,  1562,  1579,
    1580,   683,  1297,  1587,  1588,  1602,  1603,  1621,  1622,  1632,
    1633,  1643,  1644,  1656,  1657,  1664,  1665,  1677,  1678,   700,
     684,   701,   687,   705,   702,   712,   706,   725,   726,   729,
     742,   746,   665,   743,   756,   740,   757,   761,   762,   773,
     781,   797,   791,   801,   792,   805,   804,   807,   782,   806,
     798,   808,   809,   810,   811,   819,   818,   824,   825,   828,
     842,   831,   843,   844,   845,   849,   848,   855,   852,   879,
     866,   913,   891,   977,   920,  1360,   925,   936,  1014,   984,
    1003,  1010,  1367,   998,  1031,   915,   881,  1032,  1034,  1041,
    1078,  1081,  1115,   987,  1017,   929,   991,  1055,  1011,  1044,
     979,  1061,  1067,  1114,  1129,  1135,  1093,  1062,  1111,  1204,
    1224,  1130,  1087,  1231,  1233,  1298,  1299,  1313,  1314,  1173,
    1376,  1539,  1230,  1424,  1390,  1391,  1336,  1214,  1399,  1400,
    1536,  1392,  1158,  1488,  1490,  1210,  1401,  1497,  1453,  1258,
    1461,  1465,  1518,  1048,  1201,  1300,  1521,  1514,  1363,  1599,
    1610,  1348,  1612,  1613,  1652,  1377,  1312,  1614,  1641,  1653,
    1675,    40,  1439,  1676,  1415,  1416,  1286,   123,  1235,  1225,
     152,   584,  1414,  1402,   484,   671,   704,   718,  1452,   420,
    1440,  1288,   722,   714,  1418,  1466,  1018,   720,  1389,  1478,
     728,   937,   730,  1361,  1513,  1501,  1535,  1520,  1368,  1568,
    1250,  1338,  1553,  1555,  1364,  1289,  1370,   226,  1515,  1586,
     999,  1556,  1523,  1068,  1393,  1609,  1136,  1574,  1462,  1640,
    1056,  1040,  1628,  1236,     0,     0,     0,     0,  1616,  1571,
    1639,     0,     0,  1650,  1663,     0,     0,     0,     0,     0,
    1671,  1674,  1615,  1687,  1684,  1691,     0,     0,  1688,     0,
    1500,  1692,  1479,  1480,  1693,  1594,  1596,  1611,     0,     0,
       0,  1629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1324,     0,  1651,     0,     0,
       0,     0,  1522,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   342,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1569,  1570,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1642,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1496
};

static const yytype_int16 yycheck[] =
{
     148,   370,   360,   800,   486,   486,  1090,   365,  1001,     8,
       4,   851,   150,   827,  1294,   990,     4,  1060,   535,  1060,
    1060,     4,  1395,   540,  1395,   394,     4,  1020,   545,     4,
       4,   108,     4,     6,     7,   108,  1237,     4,  1013,     4,
    1128,     4,     4,   412,   413,   414,   131,   108,    93,     4,
      93,   131,   131,    80,     4,   131,   222,   230,   514,   232,
      45,   146,   131,   519,   144,  1058,  1128,   157,   524,   148,
     146,   868,  1047,   157,    59,   144,    78,  1070,   105,   124,
     228,   124,   230,  1178,   232,  1128,   224,  1128,  1128,  1064,
     117,  1464,   182,  1464,   550,  1375,   157,   131,   182,   555,
     131,   129,     0,   105,   586,   586,    14,   109,   142,   111,
     187,   113,   140,   115,  1315,  1203,   126,   148,    90,   129,
    1095,   104,   195,    86,  1219,   100,   203,   644,   102,    96,
     203,   648,    94,    98,   122,   652,   494,    92,    88,   312,
     118,  1203,   203,  1423,  1517,  1138,  1517,   120,   628,    41,
      42,   631,   129,   633,   157,   635,    82,  1132,    41,    42,
    1203,   138,  1203,  1203,    56,    30,    31,    32,  1263,    61,
      62,    63,    64,    56,    46,   178,   656,    26,   658,   105,
     129,    15,    65,    66,    67,    68,    58,   131,    37,   138,
      75,   673,   673,   119,    43,   121,   105,   123,   142,   125,
    1175,   127,   340,    41,    42,   129,    44,   133,   117,   135,
    1305,   137,   136,   139,    77,   141,   210,   143,    56,   145,
    1213,   147,    60,   149,    45,    46,   129,   129,    17,   129,
     223,   126,   134,   136,   129,    24,    25,    58,    59,   608,
     140,  1216,   129,   612,   613,   614,  1060,   134,    79,    38,
     732,   732,    41,   205,   206,    44,   208,    46,  1353,    81,
      49,    50,    51,    52,    12,    13,    55,    56,    57,    58,
     187,    60,    76,   190,    41,    42,    17,    44,    74,   157,
      69,    70,   160,    24,    25,  1260,    73,  1382,  1128,    56,
      21,    22,    23,    60,    61,    62,    63,    64,    39,   195,
      41,    16,   198,    44,    83,    46,    47,    48,    49,    50,
      10,    11,  1407,   682,    55,    56,    57,    58,   687,    60,
      24,    25,   328,     5,   330,    78,   332,  1302,    69,    70,
      10,    11,    36,    10,    11,    10,    11,    41,   486,    40,
      44,   225,    46,    44,     5,    46,    10,    11,    10,    11,
    1445,    55,    56,    57,    58,    41,    60,    58,    44,    60,
      46,    10,    11,    10,    11,    69,    70,   320,     5,   322,
      56,   324,    58,     5,    60,  1350,  1471,   746,   105,     5,
      76,   334,   109,   336,   111,     3,   113,   756,   115,    85,
       3,    87,   229,    89,   233,    91,  1491,    93,   241,    95,
      10,    97,  1395,    99,  1379,   101,  1203,   103,   237,   105,
      80,  1506,    10,   782,    10,    11,   415,   416,   417,   418,
      10,   202,   791,  1398,   205,   206,     3,   208,    10,  1404,
      10,    11,   801,  1528,    10,    11,  1520,    88,   586,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   818,
      10,    11,    10,    11,    10,    11,    86,   939,   939,   828,
     106,   107,    17,    10,    11,    90,  1561,  1442,     8,    24,
      25,  1464,    10,    11,    10,    11,   845,     6,     7,   106,
     107,    96,    37,   852,  1579,    94,    41,    10,    11,    44,
      98,    46,     8,  1468,    49,    50,    10,    11,    53,    54,
      55,    56,    57,    58,    82,    60,   100,  1602,    10,    11,
     879,    10,    11,   102,    69,    70,    10,    11,    18,  1001,
    1001,    10,    11,     6,  1517,   673,  1621,    20,  1503,    10,
      11,    10,    11,    10,    11,    10,    11,  1632,  1020,  1020,
      10,    11,    27,  1340,   913,    10,    11,    19,  1643,     3,
    1525,    92,    85,     6,    87,   104,    89,   107,    91,     8,
      93,  1656,    95,   106,    97,   153,    99,     8,   101,  1664,
     103,     8,   105,   942,     8,   105,  1058,  1058,  1060,  1060,
      10,    11,  1677,  1558,   732,    10,    11,   118,  1070,   119,
     110,   121,     8,   123,   112,   125,   107,   127,   106,   107,
      84,  1576,   114,   133,   183,   135,    33,   137,   977,   139,
     116,   141,     6,   143,     6,   145,     6,   147,   224,   149,
     226,   227,   228,     6,   230,   231,   232,   122,   234,   235,
     236,     6,   238,   239,   240,   106,   242,   243,    10,    11,
     128,   129,     6,  1618,     6,  1014,  1128,  1128,   106,   150,
     151,   106,   107,    10,    11,  1024,  1138,    10,    11,   128,
     129,   107,  1031,   150,   151,  1034,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,   156,   157,
     200,   201,    10,    11,    10,    11,   186,   187,    10,    11,
      10,    11,   194,   195,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     108,  1203,  1203,    10,    11,    10,    11,    10,    11,   180,
     181,  1213,  1213,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,     3,  1115,   180,   181,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   211,   212,    10,    11,    10,    11,    10,
      11,     3,  1151,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,   120,
     191,     8,    34,     8,    10,     8,    10,     8,    10,   106,
       8,    35,   107,   199,     6,   108,   155,     4,     4,     4,
     108,   154,     6,    37,   185,   130,    94,     3,    28,   132,
     159,     3,     3,   152,   108,   193,     6,   184,   189,    38,
       8,   161,     8,     8,     6,   197,   192,   161,    39,     6,
     177,     6,   161,     6,   179,  1224,   163,   156,    40,   107,
      29,   162,  1231,   186,     3,   187,   157,     3,     3,   107,
     107,     8,     6,   163,   160,   157,   187,   194,   167,   163,
     195,   162,   190,     8,   162,   198,   165,   167,   158,     6,
       6,   167,   157,     6,     5,     3,     3,     3,     3,   165,
       3,    10,   158,     3,  1273,  1274,     8,   169,     6,     8,
       6,   108,  1060,  1395,  1395,   178,     8,  1398,     8,   165,
     108,     8,     8,   195,   188,   169,     8,   108,   164,     6,
       8,   173,     6,     8,     6,   169,   188,     8,     8,     6,
       8,    25,   158,     8,  1313,  1314,   196,    40,   202,   209,
      62,   477,   164,   173,   404,   575,   623,   644,   168,   309,
     171,   187,   652,   639,   157,   173,   932,   648,   196,   164,
     662,   883,   667,   213,   168,   171,   166,  1425,   207,   168,
    1128,  1207,  1464,  1464,   214,   203,   195,   139,  1420,   166,
     917,   171,   175,   994,  1291,   170,  1051,   175,  1372,   158,
     981,   948,   166,  1122,    -1,    -1,    -1,    -1,   175,   188,
     170,    -1,    -1,   174,   170,    -1,    -1,    -1,    -1,    -1,
     174,   172,   196,   172,   174,   172,    -1,    -1,   176,    -1,
    1399,   176,  1390,  1391,   176,  1517,  1517,   210,    -1,    -1,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1203,    -1,   215,    -1,    -1,
      -1,    -1,  1431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1479,  1480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1521,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1398
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   420,   421,   422,     0,   222,   429,   430,
    1207,  1208,    14,   423,    15,   427,   428,    75,   431,   432,
      10,    11,  1209,  1210,  1211,    10,    11,   424,   425,   426,
      77,   517,   518,    10,    11,   433,   434,   435,  1212,  1213,
     429,    79,   565,   566,    10,    11,   519,   520,   521,    76,
      85,    87,    89,    91,    93,    95,    97,    99,   101,   103,
     105,   436,   437,   438,   439,   440,   445,   446,   451,   452,
     457,   458,   465,   466,   471,   472,   477,   478,   483,   484,
     489,   490,   495,   496,   503,   504,   223,   224,   226,   227,
     228,   230,   231,   232,   234,   235,   236,   238,   239,   240,
     242,   243,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,
    1222,  1223,  1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,
    1232,  1233,  1234,   427,    81,   593,   594,    10,    11,   567,
     568,   569,    78,   105,   109,   111,   113,   115,   522,   523,
     524,   525,   526,   532,   533,   539,   540,   546,   547,   551,
     552,    76,   438,    10,    11,   441,   442,   443,    10,    11,
     447,   448,   449,    10,    11,   453,   454,   455,    74,   459,
     460,    10,    11,   467,   468,   469,    10,    11,   473,   474,
     475,    10,    11,   479,   480,   481,    10,    11,   485,   486,
     487,    10,    11,   491,   492,   493,    73,   497,   498,    16,
     505,  1185,     5,     5,     5,     5,     5,    83,   709,   710,
      10,    11,   595,   596,   597,    80,   105,   117,   570,   571,
     572,   573,   574,   579,   580,    78,   524,   527,   528,   534,
     535,   541,   542,    46,    58,   548,  1115,  1116,  1117,  1118,
     553,  1185,     4,    86,   444,     4,    88,   450,     4,    90,
     456,     3,    10,    11,   461,   462,   463,     4,    94,   470,
       4,    96,   476,     4,    98,   482,     4,   100,   488,     4,
     102,   494,     3,    10,    11,   499,   500,   501,  1204,  1205,
      10,    11,   506,   507,   508,   225,   229,   233,   237,   241,
     711,   712,    82,   105,   119,   121,   123,   125,   127,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   598,   599,
     600,   601,   602,   609,   610,   615,   616,   623,   624,   628,
     629,   633,   634,   638,   639,   643,   644,   651,   652,   659,
     660,   667,   668,   675,   676,   681,   682,   687,   688,   695,
     696,    80,   572,    10,    11,   575,   576,   577,   581,  1185,
      10,   530,    45,    59,   529,  1115,  1163,  1164,  1165,  1166,
      10,   537,   536,  1115,  1163,    10,   544,   543,  1115,  1163,
       3,    10,   549,    10,    11,   554,   555,   556,    86,    88,
      90,     8,     4,    92,   464,    94,    96,    98,   100,   102,
       8,     4,   104,   502,     6,     8,   415,   416,   417,   418,
    1206,   106,   107,   509,   510,   511,   512,    10,    11,   714,
     715,   716,    30,    31,    32,   713,  1176,  1182,  1192,    82,
     600,   603,  1163,    10,    11,   611,   612,   613,    18,   617,
    1180,    19,  1188,  1188,  1188,  1188,    20,   645,  1187,   653,
    1187,   661,  1187,   669,  1187,   677,  1188,   683,  1188,    27,
     689,  1189,   697,  1185,     4,   118,   578,    10,    11,   582,
     583,   584,     6,     7,   531,  1203,     3,   538,  1203,   545,
    1203,  1204,     6,   550,   106,   107,   557,   558,   559,   560,
      92,   104,  1204,   106,   511,   513,   514,   153,   717,   718,
     719,  1204,  1204,  1204,    10,    11,   604,   605,   606,     4,
     122,   614,     8,    10,    11,   618,   619,   620,     8,    10,
      11,   625,   626,   627,    10,    11,   630,   631,   632,    10,
      11,   635,   636,   637,    10,    11,   640,   641,   642,     8,
      10,    11,   646,   647,   648,    10,    11,   654,   655,   656,
      10,    11,   662,   663,   664,    10,    11,   670,   671,   672,
      10,    11,   678,   679,   680,    10,    11,   684,   685,   686,
       8,    10,    11,   690,   691,   692,    10,    11,   698,   699,
     700,   118,   106,   107,   585,   586,   587,   588,   110,     8,
     112,   114,   116,   106,   559,   561,   562,    10,    11,   516,
      41,    44,    56,    60,   515,  1115,  1136,  1137,  1138,  1139,
    1167,  1168,  1169,  1170,    84,   183,   856,   857,    33,   720,
     721,  1186,     6,     6,     6,   120,   607,   608,  1203,   122,
       6,    93,   124,   621,   622,     6,   126,   129,  1096,  1097,
     128,  1096,   134,  1096,   136,  1096,     6,   131,   142,   649,
     650,  1098,  1099,   144,   657,   658,  1098,   148,   665,   666,
    1098,   146,   673,   674,  1098,   140,  1096,   138,  1096,     6,
     150,   151,   693,   694,   106,   107,   701,   702,   703,   704,
     106,   587,   589,   590,    10,    11,   564,   563,  1115,  1136,
    1167,   108,     3,     3,   191,   965,   966,    34,   858,   859,
    1184,  1204,    10,    11,   722,   723,   724,  1204,  1204,  1204,
     120,     8,    10,   124,   622,     8,    10,   126,  1097,   128,
     134,   136,     8,   142,   650,  1100,  1101,   144,   658,   148,
     666,   146,   674,   140,   138,     8,    10,   150,   694,   106,
     703,   705,   706,    10,    11,   592,   591,  1115,  1136,  1167,
     108,  1204,     8,   199,  1074,  1075,    35,   967,   968,  1183,
    1204,    10,    11,   860,   861,   862,     6,   155,   725,   726,
     727,     4,     4,    10,    11,  1106,    21,    22,    23,  1102,
    1103,  1104,  1105,     4,    10,    11,   708,   707,  1115,  1136,
    1167,   108,    28,  1076,  1190,  1204,    10,    11,   969,   970,
     971,     6,   185,   863,   864,   865,  1204,   154,   159,   740,
     741,    37,   728,  1191,    94,   130,   132,     3,     3,     3,
     152,   108,  1204,    10,    11,  1077,  1078,  1079,     6,   193,
     972,   973,   974,  1204,   184,   189,   878,   879,    38,   866,
    1181,   161,   754,   755,   742,  1191,  1204,    10,    11,   729,
     730,   731,     8,     8,     8,     6,  1080,  1204,   192,   197,
     987,   988,    39,   975,  1175,   161,   892,   893,   880,  1181,
    1204,    10,    11,   867,   868,   869,   177,   809,   810,    10,
      11,   756,   757,   758,    10,    11,   743,   744,   745,     6,
     156,   157,   732,   733,   734,   735,  1204,   200,   201,  1081,
    1082,   161,  1001,  1002,   989,  1175,  1204,    10,    11,   976,
     977,   978,   947,    10,    11,   894,   895,   896,    10,    11,
     881,   882,   883,     6,   186,   187,   870,   871,   872,   873,
     179,   823,   824,   811,  1191,   163,   759,   760,   761,   157,
     160,   746,   747,   748,   749,  1204,   156,   734,   736,   737,
      24,    25,    36,    55,    57,    69,    70,  1083,  1084,  1085,
    1107,  1108,  1109,  1110,  1115,  1136,  1144,  1145,  1146,  1147,
    1151,  1152,  1153,  1154,  1167,  1179,  1056,    10,    11,  1003,
    1004,  1005,    10,    11,   990,   991,   992,     6,   194,   195,
     979,   980,   981,   982,   107,   948,   949,   163,   897,   898,
     899,   187,   190,   884,   885,   886,   887,  1204,   186,   872,
     874,   875,   838,    29,   825,    10,    11,   812,   813,   814,
     162,   167,   767,   768,    40,   762,  1177,   160,   748,   750,
     751,    10,    11,   739,    42,   738,  1125,  1126,  1127,  1136,
    1167,     3,     3,  1204,     3,    10,    11,  1086,  1087,  1088,
    1085,   107,  1057,  1058,   163,  1006,  1007,  1008,   195,   198,
     993,   994,   995,   996,  1204,   194,   981,   983,   984,   950,
     951,   162,   167,   905,   906,   900,  1177,   190,   886,   888,
     889,    10,    11,   877,   876,  1125,  1136,  1167,   107,   839,
     840,     8,    10,    11,   826,   827,   828,   157,   178,   815,
     816,   817,   818,   165,   774,   775,   769,  1177,  1204,    10,
      11,   763,   764,   765,    10,    11,   753,   752,  1125,  1136,
    1167,   158,  1204,  1204,     8,     6,  1204,   202,   205,   206,
     208,  1089,  1090,  1091,  1092,  1093,  1094,  1059,  1060,   162,
     167,  1014,  1015,  1009,  1177,   198,   995,   997,   998,    10,
      11,   986,   985,  1125,  1136,  1167,    10,    11,   953,   954,
     955,    17,    49,    50,    51,    52,   952,  1107,  1115,  1119,
    1120,  1121,  1122,  1136,  1140,  1141,  1142,  1143,  1144,  1151,
    1167,  1178,  1181,   165,   912,   913,   907,  1177,    10,    11,
     901,   902,   903,    10,    11,   891,    61,    62,    63,    64,
     890,  1125,  1128,  1129,  1130,  1131,  1136,  1155,  1156,  1157,
    1158,   188,   841,   842,     6,   180,   181,   829,   830,   831,
     178,   817,   819,   820,   169,   781,   782,   776,  1177,    10,
      11,   770,   771,   772,     6,   209,   766,  1235,  1236,  1243,
     158,     6,  1204,     5,  1095,   202,  1091,    10,    11,  1062,
    1063,  1064,    47,    48,  1061,  1107,  1111,  1112,  1113,  1114,
    1115,  1119,  1136,  1144,  1151,  1167,  1175,  1178,   165,  1021,
    1022,  1016,  1177,    10,    11,  1010,  1011,  1012,    10,    11,
    1000,    65,    66,    67,    68,   999,  1125,  1132,  1133,  1134,
    1135,  1136,  1159,  1160,  1161,  1162,   196,   108,   187,   203,
     956,   957,   958,   959,  1193,  1194,  1195,  1204,     3,     3,
     169,   919,   920,   914,  1177,    10,    11,   908,   909,   910,
     904,  1235,   188,     3,     3,    10,    11,   844,   845,   846,
      53,    54,   843,  1107,  1115,  1119,  1136,  1144,  1151,  1167,
    1171,  1172,  1173,  1174,  1178,  1191,     8,   180,   830,   832,
     833,    10,    11,   822,   821,  1125,  1136,  1167,   173,   788,
     789,   783,  1177,    10,    11,   777,   778,   779,   773,  1235,
    1204,   213,  1247,   164,   214,  1237,  1238,  1204,   207,   108,
     195,  1065,  1066,  1067,  1068,  1193,     3,   169,  1028,  1029,
    1023,  1177,    10,    11,  1017,  1018,  1019,  1013,  1235,   196,
    1204,  1204,   108,   958,   960,   961,  1194,  1196,  1197,     6,
       8,     8,   173,   926,   927,   921,  1177,    10,    11,   915,
     916,   917,   911,  1235,   164,  1204,  1204,   108,   157,   847,
     848,   849,   850,  1193,     3,    10,    11,   835,   836,   837,
      26,    43,   834,  1123,  1124,  1148,  1149,  1150,  1191,   158,
     171,   795,   796,   790,  1177,    10,    11,   784,   785,   786,
     780,  1235,   168,     8,    10,    11,  1244,  1245,  1246,  1239,
    1240,   108,  1067,  1069,  1070,     8,   173,  1035,  1036,  1030,
    1177,    10,    11,  1024,  1025,  1026,  1020,  1235,   164,  1203,
    1203,    10,    11,   963,   964,   962,  1125,  1128,  1136,  1155,
    1167,    10,    11,  1199,  1200,  1201,  1115,  1167,  1177,  1198,
    1204,   171,   933,   934,   928,  1177,    10,    11,   922,   923,
     924,   918,  1235,   168,   108,   849,   851,   852,     8,   182,
     816,     8,  1204,   175,   802,   803,   797,  1177,    10,    11,
     791,   792,   793,   787,  1235,   166,     6,     4,   210,    10,
    1242,   211,   212,  1241,  1248,  1249,    10,    11,  1072,  1073,
    1071,  1125,  1128,  1136,  1155,  1167,   171,  1042,  1043,  1037,
    1177,    10,    11,  1031,  1032,  1033,  1027,  1235,   168,  1204,
    1204,   188,  1202,  1235,   175,   940,   941,   935,  1177,    10,
      11,   929,   930,   931,   925,  1235,   166,    10,    11,   854,
     855,   853,  1125,  1128,  1136,  1155,  1167,   182,  1203,     6,
     804,  1177,    10,    11,   798,   799,   800,   794,  1235,   170,
       8,   210,     6,     8,     8,   196,   175,  1049,  1050,  1044,
    1177,    10,    11,  1038,  1039,  1040,  1034,  1235,   166,   204,
     942,  1177,    10,    11,   936,   937,   938,   932,  1235,   170,
     158,     8,  1204,    10,    11,   805,   806,   807,   801,  1235,
     174,   215,     6,     6,  1051,  1177,    10,    11,  1045,  1046,
    1047,  1041,  1235,   170,    10,    11,   943,   944,   945,   939,
    1235,   174,   808,  1235,   172,     8,     8,    10,    11,  1052,
    1053,  1054,  1048,  1235,   174,   946,  1235,   172,   176,  1055,
    1235,   172,   176,   176
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
            parserData->parser_errors += ("\n\nOSoL input is either not valid or well formed.\n"); 
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
            if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherGeneralOption failed");
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
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 139:

    {
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 142:

    {    if (parserData->nameAttribute.length() == 0)
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
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "byte";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 171:

    {
    if (osoption->setMinDiskSpace(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinDiskSpace failed");
    parserData->errorText = NULL;
}
    break;

  case 173:

    {    if (parserData->minMemoryPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minMemory element allowed");
        parserData->minMemoryPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "byte";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 180:

    {
    if (osoption->setMinMemorySize(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinMemorySize failed");
    parserData->errorText = NULL;
}
    break;

  case 182:

    {    if (parserData->minCPUSpeedPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minCPUSpeed element allowed");
        parserData->minCPUSpeedPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "hertz";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 189:

    {    
    if (osoption->setMinCPUSpeed(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
}
    break;

  case 191:

    {    if (parserData->minCPUNumberPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minCPUNumber element allowed");
        parserData->minCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 195:

    {
    if (osoption->setMinCPUNumber((yyvsp[(1) - (1)].ival), parserData->descriptionAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinCPUNumber failed");
    //free($1); 
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
            if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherSystemOption failed");
    }
    break;

  case 208:

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
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 209:

    {    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 212:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
    break;

  case 219:

    {
    parserData->serviceTypePresent = false;    
    parserData->otherServiceOptionsPresent = false;
    osoption->service = new ServiceOption();
}
    break;

  case 231:

    {    if (parserData->serviceTypePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one currentState element allowed");
        parserData->serviceTypePresent = true;
    }
    break;

  case 237:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); 
        free((yyvsp[(1) - (1)].sval));
        if (osoption->setServiceType(parserData->tempStr) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceType failed; current system state not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 238:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 239:

    {
    if (parserData->otherServiceOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <service> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherServiceOptionsPresent = true;
}
    break;

  case 240:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other service options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 241:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 242:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 249:

    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherServiceOption failed");
    }
    break;

  case 250:

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
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 251:

    {    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 254:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
    break;

  case 261:

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

  case 285:

    {    
    if (osoption->setMaxTime(parserData->maxTimeValue, parserData->unitAttribute) == false)       
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "max time request could not be honored");
}
    break;

  case 286:

    {    
    if (parserData->maxTimePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <maxTime> element allowed");
    parserData->maxTimePresent = true;
    parserData->unitAttributePresent = false;    
    parserData->unitAttribute = "second"; 
    parserData->maxTimeValue = OSDBL_MAX;
}
    break;

  case 295:

    {
    parserData->maxTimeValue = parserData->tempVal;
}
    break;

  case 297:

    {    if (parserData->requestedStartTimePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one requestedStartTime element allowed");
        parserData->requestedStartTimePresent = true;
    }
    break;

  case 303:

    {
        if (osoption->setRequestedStartTime((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setRequestedStartTime failed");    
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
        }
    break;

  case 304:

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

  case 305:

    {
    if (parserData->dependenciesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <dependencies> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->dependenciesPresent = true;
}
    break;

  case 311:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few job IDs in <dependencies> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 314:

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

  case 315:

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

  case 316:

    {
    if (parserData->requiredDirectoriesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <requiredDirectories> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredDirectoriesPresent = true;
}
    break;

  case 321:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <requiredDirectories> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 322:

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

  case 323:

    {
    if (parserData->requiredFilesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <requiredFiles> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredFilesPresent = true;
}
    break;

  case 328:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <requiredFiles> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 329:

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

  case 330:

    {
    if (parserData->directoriesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <directoriesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToMakePresent = true;
}
    break;

  case 335:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <directoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 336:

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

  case 337:

    {
    if (parserData->filesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <filesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToMakePresent = true;
}
    break;

  case 342:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <filesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 343:

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

  case 344:

    {
    if (parserData->inputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <inputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputDirectoriesToMovePresent = true;
}
    break;

  case 350:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <inputDirectoriesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 354:

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

  case 355:

    {
    if (parserData->inputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <inputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputFilesToMovePresent = true;
}
    break;

  case 361:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <inputFilesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 365:

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

  case 366:

    {
    if (parserData->outputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <outputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputFilesToMovePresent = true;
}
    break;

  case 372:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <outputFilesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 376:

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

  case 377:

    {
    if (parserData->outputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <outputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputDirectoriesToMovePresent = true;
}
    break;

  case 383:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <outputDirectoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 387:

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

  case 388:

    {
    if (parserData->filesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <filesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToDeletePresent = true;
}
    break;

  case 394:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <filesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 395:

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

  case 396:

    {
    if (parserData->directoriesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <directoriesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToDeletePresent = true;
}
    break;

  case 402:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <directoriesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 403:

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

  case 404:

    {
    if (parserData->processesToKillPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <processesToKill> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->processesToKillPresent = true;
}
    break;

  case 410:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few process IDs in <processesToKill> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 413:

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

  case 414:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 415:

    {
    if (parserData->otherJobOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <job> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherJobOptionsPresent = true;
}
    break;

  case 416:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other job options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 417:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 418:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 425:

    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherJobOption failed");
    }
    break;

  case 426:

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
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 427:

    {
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 430:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
    break;

  case 437:

    {
    osoption->optimization = new OptimizationOption();
    parserData->numberOfVariablesPresent = false;
    parserData->numberOfObjectivesPresent = false;
    parserData->numberOfConstraintsPresent = false;
}
    break;

  case 441:

    {    
        parserData->numberOfVariables = parserData->tempInt; 
        if (osoption->setNumberOfVariables(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfVariables failed");
    }
    break;

  case 442:

    {
        parserData->numberOfConstraints = parserData->tempInt; 
        if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfConstraints failed");
    }
    break;

  case 443:

    {    
        parserData->numberOfObjectives = parserData->tempInt; 
        if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfObjectives failed");
    }
    break;

  case 451:

    {
    parserData->numberOfOtherVariableOptions = 0;
    osoption->optimization->variables = new VariableOption();
}
    break;

  case 452:

    {    
    if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
}
    break;

  case 454:

    {    
    parserData->numberOfOtherVariableOptions = parserData->tempInt;
}
    break;

  case 459:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 461:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValues(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
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

  case 462:

    {
    parserData->numberOfVarAttributePresent = false;
}
    break;

  case 463:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfVar];
    parserData->namArray = new std::string[parserData->numberOfVar];
    parserData->valArray = new      double[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 464:

    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValues>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 465:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValues>: fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 472:

    {
    parserData->kounter++;
}
    break;

  case 473:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
}
    break;

  case 474:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
}
    break;

  case 477:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 478:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 479:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 483:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString, parserData->namArray) == false)
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

  case 484:

    {
    parserData->numberOfVarAttributePresent = false;
}
    break;

  case 485:

    {
    parserData->kounter = 0;
    parserData->idxArray    = new         int[parserData->numberOfVar];
    parserData->namArray    = new std::string[parserData->numberOfVar];
    parserData->valueString = new std::string[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valueString[i] = "";
}
    break;

  case 486:

    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValuesString>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 487:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few initial values in <initialVariableValuesString> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 494:

    {
    parserData->kounter++;
}
    break;

  case 495:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->valueAttribute = "48r 87e WY EUV e7 df"; //random string...
}
    break;

  case 496:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
}
    break;

  case 499:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 500:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 501:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->valueString[parserData->kounter] = parserData->valueAttribute;
    }
    break;

  case 506:

    {
    osoption->optimization->variables->initialBasisStatus = new BasisStatus();
}
    break;

  case 513:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 514:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 515:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 522:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 523:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 524:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 531:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 532:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 533:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 540:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 541:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 542:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 549:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 550:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 551:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 558:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 559:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 560:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 567:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 568:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 569:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 576:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
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

  case 577:

    {
    parserData->numberOfVarAttributePresent = false;
}
    break;

  case 578:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfVar];
    parserData->namArray = new std::string[parserData->numberOfVar];
    parserData->valArray = new      double[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 579:

    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 580:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 587:

    {
    parserData->kounter++;
}
    break;

  case 588:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;
    parserData->valueAttribute = "1.0";
}
    break;

  case 589:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
}
    break;

  case 592:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 593:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 594:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 598:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 599:

    {
    parserData->sosIdxAttributePresent = false;    
    parserData->currentSOS = 0;
}
    break;

  case 600:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <sos> elements must be nonnegative");
    parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
}
    break;

  case 601:

    {
        if (parserData->numberOfSOS > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <sos> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 602:

    {    if (parserData->currentSOS != parserData->numberOfSOS)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <sos> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 608:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setAnotherSOSVariableBranchingWeight(parserData->sosIdx, 
                    parserData->numberOfVar, parserData->groupWeight,
                    parserData->idxArray,     parserData->valArray, parserData->namArray) )
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

  case 609:

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
    parserData->numberOfVarAttributePresent = false;
    parserData->groupWeight = 1.0;
    parserData->numberOfSOSVar = 0;
}
    break;

  case 610:

    {
    if (!parserData->sosIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index required");
    if (!parserData->numberOfVarAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVar required");
}
    break;

  case 614:

    {
        parserData->kounter = 0;
        parserData->idxArray = new         int[parserData->numberOfVar];
        parserData->namArray = new std::string[parserData->numberOfVar];
        parserData->valArray = new      double[parserData->numberOfVar];
        for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
        parserData->numberOfVarAttributePresent = true;
    }
    break;

  case 623:

    {      
        parserData->iOther++;
    }
    break;

  case 624:

    {
    if (parserData->iOther >= parserData->numberOfOtherVariableOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherVariableOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfVarAttributePresent = false;
    parserData->numberOfVar = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->varTypeAttributePresent = false;    
    parserData->varTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_variables;
}
    break;

  case 625:

    {
        if (!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherVariableOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfVar,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->varTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    }
    break;

  case 628:

    {
        parserData->kounter = 0;
    }
    break;

  case 629:

    {
        parserData->kounter = 0;
    }
    break;

  case 647:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherVariableOptionVar(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other variable option <var> element failed");
    parserData->kounter++;
}
    break;

  case 648:

    {
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 652:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
    }
    break;

  case 662:

    {
    parserData->numberOfOtherObjectiveOptions = 0; 
    osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 663:

    {    
    if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
}
    break;

  case 665:

    {    
    parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
}
    break;

  case 670:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 672:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjValues(parserData->numberOfObj, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
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

  case 673:

    {
    parserData->numberOfObjAttributePresent = false;
}
    break;

  case 674:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfObj];
    parserData->namArray = new std::string[parserData->numberOfObj];
    parserData->valArray = new      double[parserData->numberOfObj];
    for (int i=0; i < parserData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < parserData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfObj; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 675:

    {    
        if (parserData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveValues>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 676:

    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveValues>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 683:

    {
    parserData->kounter++;
}
    break;

  case 684:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->idxAttribute = -1;
}
    break;

  case 688:

    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 689:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 690:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 694:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjBounds(parserData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
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

  case 695:

    {
    parserData->numberOfObjAttributePresent = false;
}
    break;

  case 696:

    {
    parserData->kounter = 0;
    parserData->idxArray   = new         int[parserData->numberOfObj];
    parserData->lbValArray = new      double[parserData->numberOfObj];
    parserData->ubValArray = new      double[parserData->numberOfObj];
    parserData->namArray   = new std::string[parserData->numberOfObj];
    for (int i=0; i < parserData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < parserData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfObj; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < parserData->numberOfObj; i++) parserData->ubValArray[i] = OSNaN();
}
    break;

  case 697:

    {
        if (parserData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveBounds>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 698:

    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 705:

    {
    parserData->kounter++;
}
    break;

  case 706:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->idxAttribute = -1;
    parserData->lbValueAttribute = "-INF";
    parserData->ubValueAttribute = "INF";
}
    break;

  case 710:

    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be nonnegative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 711:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 712:

    {
        if (parserData->lbValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
    }
    break;

  case 713:

    {
        if (parserData->ubValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
    }
    break;

  case 718:

    {
    osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
}
    break;

  case 725:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 726:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 727:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 734:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 735:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 736:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 743:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 744:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 745:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 752:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 753:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 754:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 761:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 762:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 763:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 770:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 771:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 772:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 779:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 780:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 781:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 789:

    {      
        parserData->iOther++;  
    }
    break;

  case 790:

    {
    if (parserData->iOther >= parserData->numberOfOtherObjectiveOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherObjectiveOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfObjAttributePresent = false;    
    parserData->numberOfObj = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->objTypeAttributePresent = false;    
    parserData->objTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_objectives;
}
    break;

  case 791:

    {
        if (!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherObjectiveOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfObj,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->objTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    }
    break;

  case 794:

    {
        parserData->kounter = 0;
    }
    break;

  case 795:

    {
        parserData->kounter = 0;
    }
    break;

  case 813:

    {  
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherObjectiveOptionObj(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other objective option <obj> element failed");
    parserData->kounter++;
}
    break;

  case 814:

    {

    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->idxAttribute = -1;
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 818:

    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
    }
    break;

  case 828:

    {
    parserData->numberOfOtherConstraintOptions = 0; 
    osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 829:

    {    
    if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherConstraintOptions failed");
    parserData->iOther = 0;
}
    break;

  case 831:

    {    
    parserData->numberOfOtherConstraintOptions = parserData->tempInt;
}
    break;

  case 836:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 838:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitConValues(parserData->numberOfCon, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
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

  case 839:

    {
    parserData->numberOfConAttributePresent = false;
}
    break;

  case 840:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfCon];
    parserData->namArray = new std::string[parserData->numberOfCon];
    parserData->valArray = new      double[parserData->numberOfCon];
    for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfCon; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 841:

    {
        if (parserData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialConstraintValues>: expected at least one <con element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 842:

    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialConstraintValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 849:

    {
    parserData->kounter++;
}
    break;

  case 850:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
}
    break;

  case 851:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<con> element must have idx attribute");
}
    break;

  case 854:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 855:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 856:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 860:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitDualValues(parserData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
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

  case 861:

    {
    parserData->numberOfConAttributePresent = false;
}
    break;

  case 862:

    {
    parserData->kounter = 0;
    parserData->idxArray   = new         int[parserData->numberOfCon];
    parserData->namArray   = new std::string[parserData->numberOfCon];
    parserData->lbValArray = new      double[parserData->numberOfCon];
    parserData->ubValArray = new      double[parserData->numberOfCon];
    for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfCon; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < parserData->numberOfCon; i++) parserData->ubValArray[i] = OSNaN();
}
    break;

  case 863:

    {
        if (parserData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialDualValues>: expected at least one <con> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 864:

    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialDualValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 871:

    {    
    parserData->kounter++;
}
    break;

  case 872:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->lbDualValue = OSNaN();
    parserData->ubDualValue = OSNaN();
}
    break;

  case 873:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<con> element must have idx attribute");
}
    break;

  case 876:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 877:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 878:

    {
        parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
    }
    break;

  case 879:

    {
        parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
    }
    break;

  case 884:

    {
    osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
}
    break;

  case 891:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 892:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 893:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 900:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 901:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 902:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 909:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 910:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 911:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 918:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 919:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 920:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 927:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 928:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 929:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 936:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 937:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 938:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 945:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 946:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 947:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 955:

    {      
        parserData->iOther++;  
    }
    break;

  case 956:

    {
    if (parserData->iOther >= parserData->numberOfOtherConstraintOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherConstraintOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfConAttributePresent = false;    
    parserData->numberOfCon = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->conTypeAttributePresent = false;    
    parserData->conTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_constraints;
}
    break;

  case 957:

    {
        if(!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherConstraintOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfCon,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->conTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    }
    break;

  case 960:

    {
        parserData->kounter = 0;
    }
    break;

  case 961:

    {
        parserData->kounter = 0;
    }
    break;

  case 979:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherConstraintOptionCon(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other constraint option <con> element failed");
    parserData->kounter++;
}
    break;

  case 980:

    {
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 984:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
    }
    break;

  case 993:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 995:

    {
    if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfSolverOptions failed");
    parserData->iOption = 0;
}
    break;

  case 996:

    {
        if (parserData->numberOfSolverOptions > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <solverOption> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 997:

    {
        if (parserData->iOption != parserData->numberOfSolverOptions)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <solverOption> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 1002:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setSolverOptionContent(
                    parserData->iOption, 
                    parserData->numberOfItems,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->descriptionAttribute,
                    parserData->itemList) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setSolverOptionContent failed");
    if (parserData->numberOfItems > 0)
        delete[] parserData->itemList;
    parserData->itemList = NULL;
    parserData->iOption++;
}
    break;

  case 1003:

    {
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->solverAttributePresent = false;
    parserData->categoryAttributePresent = false;
    parserData->typeAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->numberOfItemsPresent = false;
    parserData->valueAttribute = "";
    parserData->solverAttribute = "";
    parserData->categoryAttribute = "";
    parserData->typeAttribute = "";
    parserData->descriptionAttribute = "";
    parserData->numberOfItems = 0;
    parserData->kounter = 0;
}
    break;

  case 1004:

    {
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "name attribute must be present");
}
    break;

  case 1013:

    {
            parserData->itemList = new std::string[parserData->numberOfItems];
    }
    break;

  case 1014:

    {
        if (parserData->numberOfItems > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <item> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 1015:

    {
        if (parserData->kounter < parserData->numberOfItems)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <item> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 1022:

    {    
    parserData->itemList[parserData->kounter] = parserData->itemContent;
    parserData->kounter++;
}
    break;

  case 1023:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            if (!parserData->suppressFurtherErrorMessages)
            {
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
                parserData->suppressFurtherErrorMessages = true;
                parserData->ignoreDataAfterErrors = true;
            }
        parserData->itemContent = "";            
    }
    break;

  case 1028:

    {
    if (parserData->kounter >= parserData->numberOf)
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

  case 1031:

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

  case 1032:

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

  case 1033:

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

  case 1034:

    {
//    parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 1040:

    {
    if (parserData->pathPairFromPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"from\" attribute allowed");
    parserData->pathPairFromPresent = true;
    parserData->pathPairFrom = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1041:

    {
    if (parserData->pathPairToPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"to\" attribute allowed");
    parserData->pathPairToPresent = true;
    parserData->pathPairTo = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1042:

    {
    if (parserData->pathPairMakeCopyPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"makeCopy\" attribute allowed");
    parserData->pathPairMakeCopyPresent = true;
    parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1045:

    {   
    if (parserData->categoryAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one category attribute allowed for this element");
    parserData->categoryAttributePresent = true;
}
    break;

  case 1048:

    { 
    parserData->categoryAttribute = "";
}
    break;

  case 1049:

    { 
    parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1050:

    {   if (parserData->conTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one conType attribute allowed for this element");
            parserData->conTypeAttributePresent = true;
        }
    break;

  case 1053:

    { parserData->conTypeAttribute = ""; }
    break;

  case 1054:

    { 
    parserData->conTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1055:

    {
    if (parserData->descriptionAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one description attribute allowed for this element");
    parserData->descriptionAttributePresent = true;
}
    break;

  case 1058:

    { parserData->descriptionAttribute = ""; }
    break;

  case 1059:

    { 
    parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1060:

    {   if (parserData->enumTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one enumType attribute allowed for this element");
            parserData->enumTypeAttributePresent = true;
        }
    break;

  case 1063:

    { parserData->enumTypeAttribute = ""; }
    break;

  case 1064:

    { 
    parserData->enumTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1065:

    {
    if (parserData->groupWeightAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one groupWeight attribute allowed for this element");
    parserData->groupWeightAttributePresent = true;
}
    break;

  case 1066:

    {
    parserData->groupWeight = parserData->tempVal;
}
    break;

  case 1067:

    {   
    if (parserData->idxAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one idx attribute allowed for this element");
    parserData->idxAttributePresent = true;
}
    break;

  case 1069:

    { 
    parserData->idxAttribute = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1070:

    {   
    if (parserData->lbValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
    parserData->lbValueAttributePresent = true;
}
    break;

  case 1073:

    { 
    parserData->lbValueAttribute = ""; 
}
    break;

  case 1074:

    { 
    parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1075:

    {   if (parserData->lbValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
            parserData->lbValueAttributePresent = true;
        }
    break;

  case 1078:

    { 
    parserData->lbDualValue = 0.0; 
}
    break;

  case 1079:

    {
    parserData->lbDualValue = parserData->tempVal;
}
    break;

  case 1080:

    {
        if (parserData->nameAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one name attribute allowed for this element");
        parserData->nameAttributePresent = true;
    }
    break;

  case 1083:

    { 
        parserData->nameAttribute = ""; 
    }
    break;

  case 1084:

    { 
        parserData->nameAttribute = (yyvsp[(2) - (3)].sval); 
        free((yyvsp[(2) - (3)].sval));
    }
    break;

  case 1085:

    {   if (parserData->objTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one objType attribute allowed for this element");
            parserData->objTypeAttributePresent = true;
        }
    break;

  case 1088:

    { parserData->objTypeAttribute = ""; }
    break;

  case 1089:

    { 
    parserData->objTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1090:

    {   if (parserData->solverAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one solver attribute allowed for this element");
        parserData->solverAttributePresent = true;
    }
    break;

  case 1093:

    { parserData->solverAttribute = ""; }
    break;

  case 1094:

    { 
    parserData->solverAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1095:

    {   if (parserData->sosIdxAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one sosIdx attribute allowed for this element");
        parserData->sosIdxAttributePresent = true;
    }
    break;

  case 1097:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index must be nonnegative");
    parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1098:

    {   if (parserData->typeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one type attribute allowed for this element");
            parserData->typeAttributePresent = true;
        }
    break;

  case 1101:

    { parserData->typeAttribute = ""; }
    break;

  case 1102:

    { 
    parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1103:

    {
   if (parserData->ubValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
    parserData->ubValueAttributePresent = true;
}
    break;

  case 1106:

    { 
    parserData->ubValueAttribute = ""; 
}
    break;

  case 1107:

    { 
    parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1108:

    {   if (parserData->ubValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
            parserData->ubValueAttributePresent = true;
        }
    break;

  case 1111:

    { parserData->ubDualValue = 0.0; }
    break;

  case 1112:

    { 
    parserData->ubDualValue = parserData->tempVal;
}
    break;

  case 1113:

    {   if (parserData->unitAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one unit attribute allowed for this element");
            parserData->unitAttributePresent = true;
        }
    break;

  case 1116:

    { parserData->unitAttribute = ""; }
    break;

  case 1117:

    { 
    parserData->unitAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1118:

    {   if (parserData->valueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one value attribute allowed for this element");
            parserData->valueAttributePresent = true;
        }
    break;

  case 1121:

    { parserData->valueAttribute = ""; }
    break;

  case 1122:

    {
    parserData->valueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1123:

    {   if (parserData->varTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one varType attribute allowed for this element");
            parserData->varTypeAttributePresent = true;
        }
    break;

  case 1126:

    { parserData->varTypeAttribute = ""; }
    break;

  case 1127:

    { 
    parserData->varTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1128:

    {
    if (parserData->numberOfConAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfCon attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <con> cannot be negative");
    parserData->numberOfConAttributePresent = true;        
    parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1129:

    {
    if (parserData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of constraints cannot be negative");
    parserData->numberOfConstraintsPresent = true;        
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1130:

    {
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;
    parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1131:

    {
    if (parserData->numberOfEnumerationsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <enumeration> elements cannot be negative");
    parserData->numberOfEnumerationsAttributePresent = true;        
    parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1132:

    {    
   if (parserData->numberOfItemsPresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one numberOfItems attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1133:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1134:

    {
    if (parserData->numberOfObjAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObj attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    parserData->numberOfObjAttributePresent = true;        
    parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1135:

    {
    if (parserData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of objectives cannot be negative");
    parserData->numberOfObjectivesPresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1136:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other constraint options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1137:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other objective options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1138:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1139:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other variable options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1140:

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

  case 1141:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of paths cannot be negative");
    else
        parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1142:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1143:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of solver options cannot be negative");
    parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1144:

    {
    if (parserData->numberOfVarAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVar attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <var> cannot be negative");
    parserData->numberOfVarAttributePresent = true;        
    parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1145:

    {    if (parserData->numberOfVariablesPresent)

        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of variables cannot be negative");
    parserData->numberOfVariablesPresent = true;    
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1148:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherOptionEnumeration(parserData->otherOptionType, 
                parserData->iOther,
                parserData->kounter,
                osglData->osglNumberOfEl, 
                parserData->valueAttribute, 
                parserData->descriptionAttribute, 
                osglData->osglIntArray) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <other> option enumeration failed");

    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 1149:

    {
    if (parserData->kounter >= parserData->numberOfEnumerations)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <enumeration> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->osglNumberOfElPresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 1150:

    {
        if(!osglData->osglNumberOfElPresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires numberOfEl attribute"); 
        if(!parserData->valueAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires value attribute"); 
    }
    break;

  case 1153:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfElPresent = true;
        osglData->osglNumberOfEl = parserData->numberOf;
        if (parserData->numberOf > 0)
            osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 1161:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1162:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 1171:

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

  case 1184:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 1189:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1190:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 1195:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1196:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 1201:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1202:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 1207:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1208:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 1213:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1214:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1219:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 1225:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;    
}
    break;

  case 1231:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        intvec = (int*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglIntArray[i] = *(intvec++);
        }
    }
    //delete[] b64string;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1232:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1233:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1234:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
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
    error = "OSoL input is either not valid or well formed: "  + error;
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


