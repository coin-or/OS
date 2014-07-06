
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
void  yygetOSOption(const char *ch, OSOption* m_osoption, OSoLParserData *m_parserData, OSgLParserData *osglData ) throw(ErrorClass);
void osol_empty_vectors( OSoLParserData* parserData);
void osgl_empty_vectors( OSgLParserData* osglData);






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
     HEADERSTART = 330,
     HEADEREND = 331,
     GENERALSTART = 332,
     GENERALEND = 333,
     SYSTEMSTART = 334,
     SYSTEMEND = 335,
     SERVICESTART = 336,
     SERVICEEND = 337,
     JOBSTART = 338,
     JOBEND = 339,
     OPTIMIZATIONSTART = 340,
     OPTIMIZATIONEND = 341,
     FILENAMESTART = 342,
     FILENAMEEND = 343,
     FILENAMEEMPTY = 344,
     FILENAMESTARTANDEND = 345,
     FILESOURCESTART = 346,
     FILESOURCEEND = 347,
     FILESOURCEEMPTY = 348,
     FILESOURCESTARTANDEND = 349,
     FILEDESCRIPTIONSTART = 350,
     FILEDESCRIPTIONEND = 351,
     FILEDESCRIPTIONEMPTY = 352,
     FILEDESCRIPTIONSTARTANDEND = 353,
     FILECREATORSTART = 354,
     FILECREATOREND = 355,
     FILECREATOREMPTY = 356,
     FILECREATORSTARTANDEND = 357,
     FILELICENCESTART = 358,
     FILELICENCEEND = 359,
     FILELICENCEEMPTY = 360,
     FILELICENCESTARTANDEND = 361,
     SERVICEURISTART = 362,
     SERVICEURIEND = 363,
     SERVICENAMESTART = 364,
     SERVICENAMEEND = 365,
     INSTANCENAMESTART = 366,
     INSTANCENAMEEND = 367,
     INSTANCELOCATIONSTART = 368,
     INSTANCELOCATIONEND = 369,
     JOBIDSTART = 370,
     JOBIDEND = 371,
     SOLVERTOINVOKESTART = 372,
     SOLVERTOINVOKEEND = 373,
     LICENSESTART = 374,
     LICENSEEND = 375,
     USERNAMESTART = 376,
     USERNAMEEND = 377,
     PASSWORDSTART = 378,
     PASSWORDEND = 379,
     CONTACTSTART = 380,
     CONTACTEND = 381,
     OTHEROPTIONSSTART = 382,
     OTHEROPTIONSEND = 383,
     OTHERSTART = 384,
     OTHEREND = 385,
     MINDISKSPACESTART = 386,
     MINDISKSPACEEND = 387,
     MINMEMORYSTART = 388,
     MINMEMORYEND = 389,
     MINCPUSPEEDSTART = 390,
     MINCPUSPEEDEND = 391,
     MINCPUNUMBERSTART = 392,
     MINCPUNUMBEREND = 393,
     SERVICETYPESTART = 394,
     SERVICETYPEEND = 395,
     MAXTIMESTART = 396,
     MAXTIMEEND = 397,
     REQUESTEDSTARTTIMESTART = 398,
     REQUESTEDSTARTTIMEEND = 399,
     DEPENDENCIESSTART = 400,
     DEPENDENCIESEND = 401,
     REQUIREDDIRECTORIESSTART = 402,
     REQUIREDDIRECTORIESEND = 403,
     REQUIREDFILESSTART = 404,
     REQUIREDFILESEND = 405,
     PATHSTART = 406,
     PATHEND = 407,
     PATHPAIRSTART = 408,
     PATHPAIREND = 409,
     DIRECTORIESTOMAKESTART = 410,
     DIRECTORIESTOMAKEEND = 411,
     FILESTOMAKESTART = 412,
     FILESTOMAKEEND = 413,
     DIRECTORIESTODELETESTART = 414,
     DIRECTORIESTODELETEEND = 415,
     FILESTODELETESTART = 416,
     FILESTODELETEEND = 417,
     INPUTDIRECTORIESTOMOVESTART = 418,
     INPUTDIRECTORIESTOMOVEEND = 419,
     INPUTFILESTOMOVESTART = 420,
     INPUTFILESTOMOVEEND = 421,
     OUTPUTDIRECTORIESTOMOVESTART = 422,
     OUTPUTDIRECTORIESTOMOVEEND = 423,
     OUTPUTFILESTOMOVESTART = 424,
     OUTPUTFILESTOMOVEEND = 425,
     PROCESSESTOKILLSTART = 426,
     PROCESSESTOKILLEND = 427,
     PROCESSSTART = 428,
     PROCESSEND = 429,
     VARIABLESSTART = 430,
     VARIABLESEND = 431,
     INITIALVARIABLEVALUESSTART = 432,
     INITIALVARIABLEVALUESEND = 433,
     VARSTART = 434,
     VAREND = 435,
     INITIALVARIABLEVALUESSTRINGSTART = 436,
     INITIALVARIABLEVALUESSTRINGEND = 437,
     INITIALBASISSTATUSSTART = 438,
     INITIALBASISSTATUSEND = 439,
     BASICSTART = 440,
     BASICEND = 441,
     ATUPPERSTART = 442,
     ATUPPEREND = 443,
     ATLOWERSTART = 444,
     ATLOWEREND = 445,
     ATEQUALITYSTART = 446,
     ATEQUALITYEND = 447,
     SUPERBASICSTART = 448,
     SUPERBASICEND = 449,
     ISFREESTART = 450,
     ISFREEEND = 451,
     UNKNOWNSTART = 452,
     UNKNOWNEND = 453,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 454,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 455,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 456,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 457,
     SOSSTART = 458,
     SOSEND = 459,
     OBJECTIVESSTART = 460,
     OBJECTIVESEND = 461,
     INITIALOBJECTIVEVALUESSTART = 462,
     INITIALOBJECTIVEVALUESEND = 463,
     OBJSTART = 464,
     OBJEND = 465,
     INITIALOBJECTIVEBOUNDSSTART = 466,
     INITIALOBJECTIVEBOUNDSEND = 467,
     CONSTRAINTSSTART = 468,
     CONSTRAINTSEND = 469,
     INITIALCONSTRAINTVALUESSTART = 470,
     INITIALCONSTRAINTVALUESEND = 471,
     CONSTART = 472,
     CONEND = 473,
     INITIALDUALVALUESSTART = 474,
     INITIALDUALVALUESEND = 475,
     SOLVEROPTIONSSTART = 476,
     SOLVEROPTIONSEND = 477,
     SOLVEROPTIONSTART = 478,
     SOLVEROPTIONEND = 479,
     ENUMERATIONSTART = 480,
     ENUMERATIONEND = 481,
     ITEMEMPTY = 482,
     ITEMSTART = 483,
     ITEMEND = 484,
     ITEMSTARTANDEND = 485,
     BASE64START = 486,
     BASE64END = 487,
     INCRATT = 488,
     MULTATT = 489,
     SIZEOFATT = 490,
     ELSTART = 491,
     ELEND = 492,
     MATRIXSTART = 493,
     MATRIXEND = 494,
     BASEMATRIXEND = 495,
     BASEMATRIXSTART = 496,
     BLOCKSTART = 497,
     BLOCKEND = 498,
     BLOCKSSTART = 499,
     BLOCKSEND = 500,
     EMPTYSYMMETRYATT = 501,
     SYMMETRYATT = 502,
     NUMBEROFBLOCKSATT = 503,
     NUMBEROFCOLUMNSATT = 504,
     NUMBEROFROWSATT = 505,
     BASEMATRIXIDXATT = 506,
     TARGETMATRIXFIRSTROWATT = 507,
     TARGETMATRIXFIRSTCOLATT = 508,
     BASEMATRIXSTARTROWATT = 509,
     BASEMATRIXSTARTCOLATT = 510,
     BASEMATRIXENDROWATT = 511,
     BASEMATRIXENDCOLATT = 512,
     SCALARMULTIPLIERATT = 513,
     EMPTYBASETRANSPOSEATT = 514,
     BASETRANSPOSEATT = 515,
     ELEMENTSSTART = 516,
     ELEMENTSEND = 517,
     CONSTANTELEMENTSSTART = 518,
     CONSTANTELEMENTSEND = 519,
     STARTVECTORSTART = 520,
     STARTVECTOREND = 521,
     NONZEROSSTART = 522,
     NONZEROSEND = 523,
     INDEXESSTART = 524,
     INDEXESEND = 525,
     VALUESSTART = 526,
     VALUESEND = 527,
     VARREFERENCEELEMENTSSTART = 528,
     VARREFERENCEELEMENTSEND = 529,
     LINEARELEMENTSSTART = 530,
     LINEARELEMENTSEND = 531,
     GENERALELEMENTSSTART = 532,
     GENERALELEMENTSEND = 533,
     COLOFFSETSSTART = 534,
     COLOFFSETSEND = 535,
     ROWOFFSETSSTART = 536,
     ROWOFFSETSEND = 537,
     EMPTYROWMAJORATT = 538,
     ROWMAJORATT = 539,
     BLOCKROWIDXATT = 540,
     BLOCKCOLIDXATT = 541,
     DUMMY = 542,
     NONLINEAREXPRESSIONSSTART = 543,
     NONLINEAREXPRESSIONSEND = 544,
     NUMBEROFNONLINEAREXPRESSIONS = 545,
     NLSTART = 546,
     NLEND = 547,
     POWERSTART = 548,
     POWEREND = 549,
     PLUSSTART = 550,
     PLUSEND = 551,
     MINUSSTART = 552,
     MINUSEND = 553,
     DIVIDESTART = 554,
     DIVIDEEND = 555,
     LNSTART = 556,
     LNEND = 557,
     SQRTSTART = 558,
     SQRTEND = 559,
     SUMSTART = 560,
     SUMEND = 561,
     PRODUCTSTART = 562,
     PRODUCTEND = 563,
     EXPSTART = 564,
     EXPEND = 565,
     NEGATESTART = 566,
     NEGATEEND = 567,
     IFSTART = 568,
     IFEND = 569,
     SQUARESTART = 570,
     SQUAREEND = 571,
     COSSTART = 572,
     COSEND = 573,
     SINSTART = 574,
     SINEND = 575,
     VARIABLESTART = 576,
     VARIABLEEND = 577,
     ABSSTART = 578,
     ABSEND = 579,
     ERFSTART = 580,
     ERFEND = 581,
     MAXSTART = 582,
     MAXEND = 583,
     ALLDIFFSTART = 584,
     ALLDIFFEND = 585,
     MINSTART = 586,
     MINEND = 587,
     ESTART = 588,
     EEND = 589,
     PISTART = 590,
     PIEND = 591,
     TIMESSTART = 592,
     TIMESEND = 593,
     NUMBERSTART = 594,
     NUMBEREND = 595,
     IDATT = 596,
     COEFATT = 597
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
#define HEADERSTART 330
#define HEADEREND 331
#define GENERALSTART 332
#define GENERALEND 333
#define SYSTEMSTART 334
#define SYSTEMEND 335
#define SERVICESTART 336
#define SERVICEEND 337
#define JOBSTART 338
#define JOBEND 339
#define OPTIMIZATIONSTART 340
#define OPTIMIZATIONEND 341
#define FILENAMESTART 342
#define FILENAMEEND 343
#define FILENAMEEMPTY 344
#define FILENAMESTARTANDEND 345
#define FILESOURCESTART 346
#define FILESOURCEEND 347
#define FILESOURCEEMPTY 348
#define FILESOURCESTARTANDEND 349
#define FILEDESCRIPTIONSTART 350
#define FILEDESCRIPTIONEND 351
#define FILEDESCRIPTIONEMPTY 352
#define FILEDESCRIPTIONSTARTANDEND 353
#define FILECREATORSTART 354
#define FILECREATOREND 355
#define FILECREATOREMPTY 356
#define FILECREATORSTARTANDEND 357
#define FILELICENCESTART 358
#define FILELICENCEEND 359
#define FILELICENCEEMPTY 360
#define FILELICENCESTARTANDEND 361
#define SERVICEURISTART 362
#define SERVICEURIEND 363
#define SERVICENAMESTART 364
#define SERVICENAMEEND 365
#define INSTANCENAMESTART 366
#define INSTANCENAMEEND 367
#define INSTANCELOCATIONSTART 368
#define INSTANCELOCATIONEND 369
#define JOBIDSTART 370
#define JOBIDEND 371
#define SOLVERTOINVOKESTART 372
#define SOLVERTOINVOKEEND 373
#define LICENSESTART 374
#define LICENSEEND 375
#define USERNAMESTART 376
#define USERNAMEEND 377
#define PASSWORDSTART 378
#define PASSWORDEND 379
#define CONTACTSTART 380
#define CONTACTEND 381
#define OTHEROPTIONSSTART 382
#define OTHEROPTIONSEND 383
#define OTHERSTART 384
#define OTHEREND 385
#define MINDISKSPACESTART 386
#define MINDISKSPACEEND 387
#define MINMEMORYSTART 388
#define MINMEMORYEND 389
#define MINCPUSPEEDSTART 390
#define MINCPUSPEEDEND 391
#define MINCPUNUMBERSTART 392
#define MINCPUNUMBEREND 393
#define SERVICETYPESTART 394
#define SERVICETYPEEND 395
#define MAXTIMESTART 396
#define MAXTIMEEND 397
#define REQUESTEDSTARTTIMESTART 398
#define REQUESTEDSTARTTIMEEND 399
#define DEPENDENCIESSTART 400
#define DEPENDENCIESEND 401
#define REQUIREDDIRECTORIESSTART 402
#define REQUIREDDIRECTORIESEND 403
#define REQUIREDFILESSTART 404
#define REQUIREDFILESEND 405
#define PATHSTART 406
#define PATHEND 407
#define PATHPAIRSTART 408
#define PATHPAIREND 409
#define DIRECTORIESTOMAKESTART 410
#define DIRECTORIESTOMAKEEND 411
#define FILESTOMAKESTART 412
#define FILESTOMAKEEND 413
#define DIRECTORIESTODELETESTART 414
#define DIRECTORIESTODELETEEND 415
#define FILESTODELETESTART 416
#define FILESTODELETEEND 417
#define INPUTDIRECTORIESTOMOVESTART 418
#define INPUTDIRECTORIESTOMOVEEND 419
#define INPUTFILESTOMOVESTART 420
#define INPUTFILESTOMOVEEND 421
#define OUTPUTDIRECTORIESTOMOVESTART 422
#define OUTPUTDIRECTORIESTOMOVEEND 423
#define OUTPUTFILESTOMOVESTART 424
#define OUTPUTFILESTOMOVEEND 425
#define PROCESSESTOKILLSTART 426
#define PROCESSESTOKILLEND 427
#define PROCESSSTART 428
#define PROCESSEND 429
#define VARIABLESSTART 430
#define VARIABLESEND 431
#define INITIALVARIABLEVALUESSTART 432
#define INITIALVARIABLEVALUESEND 433
#define VARSTART 434
#define VAREND 435
#define INITIALVARIABLEVALUESSTRINGSTART 436
#define INITIALVARIABLEVALUESSTRINGEND 437
#define INITIALBASISSTATUSSTART 438
#define INITIALBASISSTATUSEND 439
#define BASICSTART 440
#define BASICEND 441
#define ATUPPERSTART 442
#define ATUPPEREND 443
#define ATLOWERSTART 444
#define ATLOWEREND 445
#define ATEQUALITYSTART 446
#define ATEQUALITYEND 447
#define SUPERBASICSTART 448
#define SUPERBASICEND 449
#define ISFREESTART 450
#define ISFREEEND 451
#define UNKNOWNSTART 452
#define UNKNOWNEND 453
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 454
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 455
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 456
#define SOSVARIABLEBRANCHINGWEIGHTSEND 457
#define SOSSTART 458
#define SOSEND 459
#define OBJECTIVESSTART 460
#define OBJECTIVESEND 461
#define INITIALOBJECTIVEVALUESSTART 462
#define INITIALOBJECTIVEVALUESEND 463
#define OBJSTART 464
#define OBJEND 465
#define INITIALOBJECTIVEBOUNDSSTART 466
#define INITIALOBJECTIVEBOUNDSEND 467
#define CONSTRAINTSSTART 468
#define CONSTRAINTSEND 469
#define INITIALCONSTRAINTVALUESSTART 470
#define INITIALCONSTRAINTVALUESEND 471
#define CONSTART 472
#define CONEND 473
#define INITIALDUALVALUESSTART 474
#define INITIALDUALVALUESEND 475
#define SOLVEROPTIONSSTART 476
#define SOLVEROPTIONSEND 477
#define SOLVEROPTIONSTART 478
#define SOLVEROPTIONEND 479
#define ENUMERATIONSTART 480
#define ENUMERATIONEND 481
#define ITEMEMPTY 482
#define ITEMSTART 483
#define ITEMEND 484
#define ITEMSTARTANDEND 485
#define BASE64START 486
#define BASE64END 487
#define INCRATT 488
#define MULTATT 489
#define SIZEOFATT 490
#define ELSTART 491
#define ELEND 492
#define MATRIXSTART 493
#define MATRIXEND 494
#define BASEMATRIXEND 495
#define BASEMATRIXSTART 496
#define BLOCKSTART 497
#define BLOCKEND 498
#define BLOCKSSTART 499
#define BLOCKSEND 500
#define EMPTYSYMMETRYATT 501
#define SYMMETRYATT 502
#define NUMBEROFBLOCKSATT 503
#define NUMBEROFCOLUMNSATT 504
#define NUMBEROFROWSATT 505
#define BASEMATRIXIDXATT 506
#define TARGETMATRIXFIRSTROWATT 507
#define TARGETMATRIXFIRSTCOLATT 508
#define BASEMATRIXSTARTROWATT 509
#define BASEMATRIXSTARTCOLATT 510
#define BASEMATRIXENDROWATT 511
#define BASEMATRIXENDCOLATT 512
#define SCALARMULTIPLIERATT 513
#define EMPTYBASETRANSPOSEATT 514
#define BASETRANSPOSEATT 515
#define ELEMENTSSTART 516
#define ELEMENTSEND 517
#define CONSTANTELEMENTSSTART 518
#define CONSTANTELEMENTSEND 519
#define STARTVECTORSTART 520
#define STARTVECTOREND 521
#define NONZEROSSTART 522
#define NONZEROSEND 523
#define INDEXESSTART 524
#define INDEXESEND 525
#define VALUESSTART 526
#define VALUESEND 527
#define VARREFERENCEELEMENTSSTART 528
#define VARREFERENCEELEMENTSEND 529
#define LINEARELEMENTSSTART 530
#define LINEARELEMENTSEND 531
#define GENERALELEMENTSSTART 532
#define GENERALELEMENTSEND 533
#define COLOFFSETSSTART 534
#define COLOFFSETSEND 535
#define ROWOFFSETSSTART 536
#define ROWOFFSETSEND 537
#define EMPTYROWMAJORATT 538
#define ROWMAJORATT 539
#define BLOCKROWIDXATT 540
#define BLOCKCOLIDXATT 541
#define DUMMY 542
#define NONLINEAREXPRESSIONSSTART 543
#define NONLINEAREXPRESSIONSEND 544
#define NUMBEROFNONLINEAREXPRESSIONS 545
#define NLSTART 546
#define NLEND 547
#define POWERSTART 548
#define POWEREND 549
#define PLUSSTART 550
#define PLUSEND 551
#define MINUSSTART 552
#define MINUSEND 553
#define DIVIDESTART 554
#define DIVIDEEND 555
#define LNSTART 556
#define LNEND 557
#define SQRTSTART 558
#define SQRTEND 559
#define SUMSTART 560
#define SUMEND 561
#define PRODUCTSTART 562
#define PRODUCTEND 563
#define EXPSTART 564
#define EXPEND 565
#define NEGATESTART 566
#define NEGATEEND 567
#define IFSTART 568
#define IFEND 569
#define SQUARESTART 570
#define SQUAREEND 571
#define COSSTART 572
#define COSEND 573
#define SINSTART 574
#define SINEND 575
#define VARIABLESTART 576
#define VARIABLEEND 577
#define ABSSTART 578
#define ABSEND 579
#define ERFSTART 580
#define ERFEND 581
#define MAXSTART 582
#define MAXEND 583
#define ALLDIFFSTART 584
#define ALLDIFFEND 585
#define MINSTART 586
#define MINEND 587
#define ESTART 588
#define EEND 589
#define PISTART 590
#define PIEND 591
#define TIMESSTART 592
#define TIMESEND 593
#define NUMBERSTART 594
#define NUMBEREND 595
#define IDATT 596
#define COEFATT 597




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



std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg ) ;
void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, std::string errormsg );
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
#define YYLAST   1283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  347
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  831
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1246
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1696

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   597

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   344,
     346,     2,     2,   345,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   343,     2,     2,     2,     2,     2,     2,     2,
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
     335,   336,   337,   338,   339,   340,   341,   342
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
    2874,  2877,  2879,  2881,  2883,  2886,  2888,  2892,  2894,  2896,
    2899,  2901,  2903,  2905,  2907,  2909,  2910,  2912,  2914,  2916,
    2918,  2920,  2924,  2925,  2927,  2929,  2931,  2933,  2935,  2939,
    2940,  2942,  2944,  2946,  2948,  2950,  2954,  2955,  2957,  2959,
    2961,  2963,  2965,  2969,  2970,  2972,  2974,  2976,  2978,  2980,
    2984,  2986,  2988,  2989,  2992,  2996,  2998,  3000,  3001,  3004,
    3006,  3008,  3012,  3016,  3021,  3023,  3025,  3028,  3030,  3034,
    3039,  3044,  3049,  3051,  3053,  3056,  3058
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     348,     0,    -1,   349,   357,   355,    -1,   350,   351,   352,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   353,    -1,
     354,    -1,    11,    -1,    10,   357,   355,    -1,   356,    -1,
      15,    -1,    -1,   358,   359,   445,   493,   521,   637,    -1,
      -1,  1135,    -1,    -1,   360,   361,    -1,    77,    -1,   362,
      -1,   363,    -1,    10,    78,    -1,    11,    -1,    10,   364,
      78,    -1,   365,    -1,   366,    -1,   365,   366,    -1,   367,
      -1,   373,    -1,   379,    -1,   385,    -1,   393,    -1,   399,
      -1,   405,    -1,   411,    -1,   417,    -1,   423,    -1,   431,
      -1,   368,   369,    -1,   107,    -1,   370,    -1,   371,    -1,
      10,   108,    -1,    11,    -1,    10,   372,   108,    -1,     4,
      -1,   374,   375,    -1,   109,    -1,   376,    -1,   377,    -1,
      10,   110,    -1,    11,    -1,    10,   378,   110,    -1,     4,
      -1,   380,   381,    -1,   111,    -1,   382,    -1,   383,    -1,
      10,   112,    -1,    11,    -1,    10,   384,   112,    -1,     4,
      -1,   386,   387,   389,    -1,   113,    -1,    -1,   388,    -1,
      74,     3,     8,    -1,   390,    -1,   391,    -1,    10,   114,
      -1,    11,    -1,    10,   392,   114,    -1,     4,    -1,   394,
     395,    -1,   115,    -1,   396,    -1,   397,    -1,    10,   116,
      -1,    11,    -1,    10,   398,   116,    -1,     4,    -1,   400,
     401,    -1,   117,    -1,   402,    -1,   403,    -1,    10,   118,
      -1,    11,    -1,    10,   404,   118,    -1,     4,    -1,   406,
     407,    -1,   119,    -1,   408,    -1,   409,    -1,    10,   120,
      -1,    11,    -1,    10,   410,   120,    -1,     4,    -1,   412,
     413,    -1,   121,    -1,   414,    -1,   415,    -1,    10,   122,
      -1,    11,    -1,    10,   416,   122,    -1,     4,    -1,   418,
     419,    -1,   123,    -1,   420,    -1,   421,    -1,    10,   124,
      -1,    11,    -1,    10,   422,   124,    -1,     4,    -1,   424,
     425,   427,    -1,   125,    -1,    -1,   426,    -1,    73,     3,
       8,    -1,   428,    -1,   429,    -1,    10,   126,    -1,    11,
      -1,    10,   430,   126,    -1,     4,    -1,   432,   433,   434,
      -1,   127,    -1,  1113,    -1,   435,    -1,   436,    -1,    10,
     128,    -1,    11,    -1,    10,   437,   128,    -1,   438,    -1,
     439,    -1,   438,   439,    -1,   440,   441,   444,    -1,   129,
      -1,   442,    -1,    -1,   442,   443,    -1,  1064,    -1,  1095,
      -1,  1043,    -1,    10,   130,    -1,    11,    -1,    -1,   446,
     447,    -1,    79,    -1,   448,    -1,   449,    -1,    10,    80,
      -1,    11,    -1,    10,   450,    80,    -1,   451,    -1,   452,
      -1,   451,   452,    -1,   453,    -1,   460,    -1,   467,    -1,
     474,    -1,   479,    -1,   454,   455,   458,    -1,   131,    -1,
     456,    -1,    -1,   456,   457,    -1,  1091,    -1,  1043,    -1,
      10,   459,   132,    -1,  1131,    -1,   461,   462,   465,    -1,
     133,    -1,   463,    -1,    -1,   463,   464,    -1,  1091,    -1,
    1043,    -1,    10,   466,   134,    -1,  1131,    -1,   468,   469,
     472,    -1,   135,    -1,   470,    -1,    -1,   470,   471,    -1,
    1091,    -1,  1043,    -1,    10,   473,   136,    -1,  1131,    -1,
     475,   476,   477,    -1,   137,    -1,    -1,  1043,    -1,    10,
     478,   138,    -1,     6,    -1,   480,   481,   482,    -1,   127,
      -1,  1113,    -1,   483,    -1,   484,    -1,    10,   128,    -1,
      11,    -1,    10,   485,   128,    -1,   486,    -1,   487,    -1,
     486,   487,    -1,   488,   489,   492,    -1,   129,    -1,   490,
      -1,    -1,   490,   491,    -1,  1064,    -1,  1095,    -1,  1043,
      -1,    10,   130,    -1,    11,    -1,    -1,   494,   495,    -1,
      81,    -1,   496,    -1,   497,    -1,    10,    82,    -1,    11,
      -1,    10,   498,    82,    -1,   499,    -1,   500,    -1,   499,
     500,    -1,   501,    -1,   507,    -1,   502,   503,    -1,   139,
      -1,   504,    -1,   505,    -1,    10,   140,    -1,    11,    -1,
      10,   506,   140,    -1,     4,    -1,   508,   509,   510,    -1,
     127,    -1,  1113,    -1,   511,    -1,   512,    -1,    10,   128,
      -1,    11,    -1,    10,   513,   128,    -1,   514,    -1,   515,
      -1,   514,   515,    -1,   516,   517,   520,    -1,   129,    -1,
     518,    -1,    -1,   518,   519,    -1,  1064,    -1,  1095,    -1,
    1043,    -1,    10,   130,    -1,    11,    -1,    -1,   522,   523,
      -1,    83,    -1,   524,    -1,   525,    -1,    10,    84,    -1,
      11,    -1,    10,   526,    84,    -1,   527,    -1,   528,    -1,
     527,   528,    -1,   529,    -1,   537,    -1,   543,    -1,   551,
      -1,   556,    -1,   561,    -1,   566,    -1,   571,    -1,   579,
      -1,   595,    -1,   587,    -1,   603,    -1,   609,    -1,   615,
      -1,   623,    -1,   530,   531,   532,    -1,   141,    -1,    -1,
    1091,    -1,   533,    -1,   534,    -1,    10,   142,    -1,    11,
      -1,    10,   535,   142,    -1,   536,    -1,  1131,    -1,   538,
     539,    -1,   143,    -1,   540,    -1,   541,    -1,    10,   144,
      -1,    11,    -1,    10,   542,   144,    -1,     4,    -1,   544,
     545,   546,    -1,   145,    -1,  1108,    -1,   547,    -1,   548,
      -1,    10,   146,    -1,    11,    -1,    10,   549,   146,    -1,
     550,    -1,   549,   550,    -1,   115,    10,     4,   116,    -1,
     552,  1116,   553,    -1,   147,    -1,   554,    -1,   555,    -1,
      10,   148,    -1,    11,    -1,    10,  1024,   148,    -1,   557,
    1116,   558,    -1,   149,    -1,   559,    -1,   560,    -1,    10,
     150,    -1,    11,    -1,    10,  1024,   150,    -1,   562,  1116,
     563,    -1,   155,    -1,   564,    -1,   565,    -1,    10,   156,
      -1,    11,    -1,    10,  1024,   156,    -1,   567,  1116,   568,
      -1,   157,    -1,   569,    -1,   570,    -1,    10,   158,    -1,
      11,    -1,    10,  1024,   158,    -1,   572,   573,   574,    -1,
     163,    -1,  1115,    -1,   575,    -1,   576,    -1,    10,   164,
      -1,    11,    -1,    10,   577,   164,    -1,   578,    -1,   577,
     578,    -1,  1026,    -1,   580,   581,   582,    -1,   165,    -1,
    1115,    -1,   583,    -1,   584,    -1,    10,   166,    -1,    11,
      -1,    10,   585,   166,    -1,   586,    -1,   585,   586,    -1,
    1026,    -1,   588,   589,   590,    -1,   169,    -1,  1115,    -1,
     591,    -1,   592,    -1,    10,   170,    -1,    11,    -1,    10,
     593,   170,    -1,   594,    -1,   593,   594,    -1,  1026,    -1,
     596,   597,   598,    -1,   167,    -1,  1115,    -1,   599,    -1,
     600,    -1,    10,   168,    -1,    11,    -1,    10,   601,   168,
      -1,   602,    -1,   601,   602,    -1,  1026,    -1,   604,   605,
     606,    -1,   161,    -1,  1116,    -1,   607,    -1,   608,    -1,
      10,   162,    -1,    11,    -1,    10,  1024,   162,    -1,   610,
     611,   612,    -1,   159,    -1,  1116,    -1,   613,    -1,   614,
      -1,    10,   160,    -1,    11,    -1,    10,  1024,   160,    -1,
     616,   617,   618,    -1,   171,    -1,  1117,    -1,   619,    -1,
     620,    -1,    10,   172,    -1,    11,    -1,    10,   621,   172,
      -1,   622,    -1,   621,   622,    -1,   173,    10,     4,   174,
      -1,   624,   625,   626,    -1,   127,    -1,  1113,    -1,   627,
      -1,   628,    -1,    10,   128,    -1,    11,    -1,    10,   629,
     128,    -1,   630,    -1,   631,    -1,   630,   631,    -1,   632,
     633,   636,    -1,   129,    -1,   634,    -1,    -1,   634,   635,
      -1,  1064,    -1,  1095,    -1,  1043,    -1,    10,   130,    -1,
      11,    -1,    -1,   638,   639,   642,    -1,    85,    -1,   640,
      -1,    -1,   640,   641,    -1,  1120,    -1,  1104,    -1,  1110,
      -1,   643,    -1,   644,    -1,    11,    -1,    10,   645,    86,
      -1,   646,   784,   893,  1002,    -1,    -1,   647,   648,   650,
      -1,   175,    -1,   649,    -1,    -1,  1114,    -1,   651,    -1,
     652,    -1,    11,    -1,    10,   653,   176,    -1,   654,   668,
     682,   737,   751,   766,    -1,    -1,   655,   656,   657,    -1,
     177,    -1,  1119,    -1,   658,    -1,   659,    -1,    10,   178,
      -1,    11,    -1,    10,   660,   178,    -1,   661,    -1,   662,
      -1,   661,   662,    -1,   663,   664,   667,    -1,   179,    -1,
     665,    -1,    -1,   665,   666,    -1,  1053,    -1,  1064,    -1,
    1095,    -1,    10,   180,    -1,    11,    -1,    -1,   669,   670,
     671,    -1,   181,    -1,  1119,    -1,   672,    -1,   673,    -1,
      10,   182,    -1,    11,    -1,    10,   674,   182,    -1,   675,
      -1,   676,    -1,   675,   676,    -1,   677,   678,   681,    -1,
     179,    -1,   679,    -1,    -1,   679,   680,    -1,  1053,    -1,
    1064,    -1,  1095,    -1,    10,   180,    -1,    11,    -1,    -1,
     683,   684,    -1,   183,    -1,   685,    -1,   686,    -1,    11,
      -1,    10,   687,   184,    -1,   688,   695,   702,   709,   716,
     723,   730,    -1,    -1,   689,   690,   691,    -1,   185,    -1,
    1105,    -1,   692,    -1,   693,    -1,    11,    -1,    10,   694,
     186,    -1,  1163,    -1,    -1,   696,   697,   698,    -1,   189,
      -1,  1105,    -1,   699,    -1,   700,    -1,    11,    -1,    10,
     701,   190,    -1,  1163,    -1,    -1,   703,   704,   705,    -1,
     187,    -1,  1105,    -1,   706,    -1,   707,    -1,    11,    -1,
      10,   708,   188,    -1,  1163,    -1,    -1,   710,   711,   712,
      -1,   191,    -1,  1105,    -1,   713,    -1,   714,    -1,    11,
      -1,    10,   715,   192,    -1,  1163,    -1,    -1,   717,   718,
     719,    -1,   195,    -1,  1105,    -1,   720,    -1,   721,    -1,
      11,    -1,    10,   722,   196,    -1,  1163,    -1,    -1,   724,
     725,   726,    -1,   193,    -1,  1105,    -1,   727,    -1,   728,
      -1,    11,    -1,    10,   729,   194,    -1,  1163,    -1,    -1,
     731,   732,   733,    -1,   197,    -1,  1105,    -1,   734,    -1,
     735,    -1,    11,    -1,    10,   736,   198,    -1,  1163,    -1,
      -1,   738,   739,   740,    -1,   199,    -1,  1119,    -1,   741,
      -1,   742,    -1,    10,   200,    -1,    11,    -1,    10,   743,
     200,    -1,   744,    -1,   745,    -1,   744,   745,    -1,   746,
     747,   750,    -1,   179,    -1,   748,    -1,    -1,   748,   749,
      -1,  1053,    -1,  1064,    -1,  1095,    -1,    10,   180,    -1,
      11,    -1,    -1,   752,   753,   754,    -1,   201,    -1,    29,
       8,     6,     8,    -1,   755,    -1,   756,    -1,    10,   202,
      -1,    11,    -1,    10,   757,   202,    -1,   758,    -1,   757,
     758,    -1,   759,   760,   763,    -1,   203,    -1,   761,    -1,
      -1,   761,   762,    -1,  1076,    -1,  1119,    -1,  1051,    -1,
     764,    -1,   765,    -1,    10,   204,    -1,    11,    -1,    10,
     744,   204,    -1,    -1,   766,   767,    -1,   768,   769,   772,
      -1,   129,    -1,   770,    -1,    -1,   770,   771,    -1,  1119,
      -1,  1106,    -1,  1064,    -1,  1095,    -1,  1072,    -1,  1035,
      -1,  1079,    -1,  1099,    -1,  1047,    -1,  1043,    -1,   773,
      -1,   774,    -1,    10,   130,    -1,    11,    -1,    10,   775,
     130,    -1,   776,    -1,  1121,    -1,   777,    -1,   776,   777,
      -1,   778,   779,   782,    -1,   179,    -1,   780,    -1,    -1,
     780,   781,    -1,  1053,    -1,  1064,    -1,  1095,    -1,  1056,
      -1,  1083,    -1,   783,    -1,    10,   180,    -1,    11,    -1,
      -1,   785,   786,   788,    -1,   205,    -1,   787,    -1,    -1,
    1112,    -1,   789,    -1,   790,    -1,    11,    -1,    10,   791,
     206,    -1,   792,   806,   820,   875,    -1,    -1,   793,   794,
     795,    -1,   207,    -1,  1109,    -1,   796,    -1,   797,    -1,
      10,   208,    -1,    11,    -1,    10,   798,   208,    -1,   799,
      -1,   800,    -1,   799,   800,    -1,   801,   802,   805,    -1,
     209,    -1,   803,    -1,    -1,   803,   804,    -1,  1053,    -1,
    1064,    -1,  1095,    -1,    10,   210,    -1,    11,    -1,    -1,
     807,   808,   809,    -1,   211,    -1,  1109,    -1,   810,    -1,
     811,    -1,    10,   212,    -1,    11,    -1,    10,   812,   212,
      -1,   813,    -1,   814,    -1,   813,   814,    -1,   815,   816,
     819,    -1,   209,    -1,   817,    -1,    -1,   817,   818,    -1,
    1053,    -1,  1064,    -1,  1056,    -1,  1083,    -1,    10,   210,
      -1,    11,    -1,    -1,   821,   822,    -1,   183,    -1,   823,
      -1,   824,    -1,    11,    -1,    10,   825,   184,    -1,   826,
     833,   840,   847,   854,   861,   868,    -1,    -1,   827,   828,
     829,    -1,   185,    -1,  1105,    -1,   830,    -1,   831,    -1,
      11,    -1,    10,   832,   186,    -1,  1163,    -1,    -1,   834,
     835,   836,    -1,   189,    -1,  1105,    -1,   837,    -1,   838,
      -1,    11,    -1,    10,   839,   190,    -1,  1163,    -1,    -1,
     841,   842,   843,    -1,   187,    -1,  1105,    -1,   844,    -1,
     845,    -1,    11,    -1,    10,   846,   188,    -1,  1163,    -1,
      -1,   848,   849,   850,    -1,   191,    -1,  1105,    -1,   851,
      -1,   852,    -1,    11,    -1,    10,   853,   192,    -1,  1163,
      -1,    -1,   855,   856,   857,    -1,   195,    -1,  1105,    -1,
     858,    -1,   859,    -1,    11,    -1,    10,   860,   196,    -1,
    1163,    -1,    -1,   862,   863,   864,    -1,   193,    -1,  1105,
      -1,   865,    -1,   866,    -1,    11,    -1,    10,   867,   194,
      -1,  1163,    -1,    -1,   869,   870,   871,    -1,   197,    -1,
    1105,    -1,   872,    -1,   873,    -1,    11,    -1,    10,   874,
     198,    -1,  1163,    -1,    -1,   875,   876,    -1,   877,   878,
     881,    -1,   129,    -1,   879,    -1,    -1,   879,   880,    -1,
    1109,    -1,  1106,    -1,  1064,    -1,  1095,    -1,  1072,    -1,
    1035,    -1,  1079,    -1,  1068,    -1,  1047,    -1,  1043,    -1,
     882,    -1,   883,    -1,    10,   130,    -1,    11,    -1,    10,
     884,   130,    -1,   885,    -1,  1121,    -1,   886,    -1,   885,
     886,    -1,   887,   888,   891,    -1,   209,    -1,   889,    -1,
      -1,   889,   890,    -1,  1053,    -1,  1064,    -1,  1095,    -1,
    1056,    -1,  1083,    -1,   892,    -1,    10,   210,    -1,    11,
      -1,    -1,   894,   895,   897,    -1,   213,    -1,   896,    -1,
      -1,  1111,    -1,   898,    -1,   899,    -1,    11,    -1,    10,
     900,   214,    -1,   901,   915,   929,   984,    -1,    -1,   902,
     903,   904,    -1,   215,    -1,  1103,    -1,   905,    -1,   906,
      -1,    10,   216,    -1,    11,    -1,    10,   907,   216,    -1,
     908,    -1,   909,    -1,   908,   909,    -1,   910,   911,   914,
      -1,   217,    -1,   912,    -1,    -1,   912,   913,    -1,  1053,
      -1,  1064,    -1,  1095,    -1,    10,   218,    -1,    11,    -1,
      -1,   916,   917,   918,    -1,   219,    -1,  1103,    -1,   919,
      -1,   920,    -1,    10,   220,    -1,    11,    -1,    10,   921,
     220,    -1,   922,    -1,   923,    -1,   922,   923,    -1,   924,
     925,   928,    -1,   217,    -1,   926,    -1,    -1,   926,   927,
      -1,  1053,    -1,  1064,    -1,  1060,    -1,  1087,    -1,    10,
     218,    -1,    11,    -1,    -1,   930,   931,    -1,   183,    -1,
     932,    -1,   933,    -1,    11,    -1,    10,   934,   184,    -1,
     935,   942,   949,   956,   963,   970,   977,    -1,    -1,   936,
     937,   938,    -1,   185,    -1,  1105,    -1,   939,    -1,   940,
      -1,    11,    -1,    10,   941,   186,    -1,  1163,    -1,    -1,
     943,   944,   945,    -1,   189,    -1,  1105,    -1,   946,    -1,
     947,    -1,    11,    -1,    10,   948,   190,    -1,  1163,    -1,
      -1,   950,   951,   952,    -1,   187,    -1,  1105,    -1,   953,
      -1,   954,    -1,    11,    -1,    10,   955,   188,    -1,  1163,
      -1,    -1,   957,   958,   959,    -1,   191,    -1,  1105,    -1,
     960,    -1,   961,    -1,    11,    -1,    10,   962,   192,    -1,
    1163,    -1,    -1,   964,   965,   966,    -1,   195,    -1,  1105,
      -1,   967,    -1,   968,    -1,    11,    -1,    10,   969,   196,
      -1,  1163,    -1,    -1,   971,   972,   973,    -1,   193,    -1,
    1105,    -1,   974,    -1,   975,    -1,    11,    -1,    10,   976,
     194,    -1,  1163,    -1,    -1,   978,   979,   980,    -1,   197,
      -1,  1105,    -1,   981,    -1,   982,    -1,    11,    -1,    10,
     983,   198,    -1,  1163,    -1,    -1,   984,   985,    -1,   986,
     987,   990,    -1,   129,    -1,   988,    -1,    -1,   988,   989,
      -1,  1103,    -1,  1106,    -1,  1064,    -1,  1095,    -1,  1072,
      -1,  1035,    -1,  1079,    -1,  1039,    -1,  1047,    -1,  1043,
      -1,   991,    -1,   992,    -1,    10,   130,    -1,    11,    -1,
      10,   993,   130,    -1,   994,    -1,  1121,    -1,   995,    -1,
     994,   995,    -1,   996,   997,  1000,    -1,   217,    -1,   998,
      -1,    -1,   998,   999,    -1,  1053,    -1,  1064,    -1,  1095,
      -1,  1056,    -1,  1083,    -1,  1001,    -1,    10,   218,    -1,
      11,    -1,    -1,  1003,  1004,  1005,    -1,   221,    -1,  1118,
      -1,  1006,    -1,  1007,    -1,    11,    -1,    10,  1008,   222,
      -1,    -1,  1008,  1009,    -1,  1010,  1011,  1014,    -1,   223,
      -1,  1012,    -1,  1013,    -1,  1012,  1013,    -1,  1064,    -1,
    1095,    -1,  1072,    -1,  1035,    -1,  1079,    -1,  1043,    -1,
    1107,    -1,  1015,    -1,  1016,    -1,    10,   224,    -1,    11,
      -1,    10,  1017,   224,    -1,  1018,    -1,  1019,    -1,  1018,
    1019,    -1,  1020,    -1,  1021,    -1,  1022,    -1,   230,    -1,
     227,    -1,   228,  1023,   229,    -1,     5,    -1,  1025,    -1,
    1024,  1025,    -1,   151,    10,     4,   152,    -1,  1027,  1028,
    1034,    -1,   153,    -1,  1029,    -1,    -1,  1029,  1030,    -1,
    1031,    -1,  1032,    -1,  1033,    -1,    21,     3,     8,    -1,
      22,     3,     8,    -1,    23,     3,     8,    -1,    10,   154,
      -1,    11,    -1,  1036,    -1,  1037,    -1,  1038,    -1,    57,
      -1,    24,     3,  1132,    -1,  1040,    -1,  1041,    -1,  1042,
      -1,    48,    -1,    47,     3,     8,    -1,  1044,    -1,  1045,
      -1,  1046,    -1,    58,    -1,    46,     3,  1132,    -1,  1048,
      -1,  1049,    -1,  1050,    -1,    50,    -1,    49,     3,     8,
      -1,  1052,    -1,    26,     8,  1131,     8,    -1,  1054,    -1,
    1055,    -1,    42,  1132,     6,  1132,    -1,  1057,    -1,  1058,
      -1,  1059,    -1,    61,    -1,    63,     3,  1132,    -1,  1061,
      -1,  1062,    -1,  1063,    -1,    65,    -1,    67,  1132,  1131,
    1132,    -1,  1065,    -1,  1066,    -1,  1067,    -1,    56,    -1,
      41,     3,  1132,    -1,  1069,    -1,  1070,    -1,  1071,    -1,
      52,    -1,    51,     3,     8,    -1,  1073,    -1,  1074,    -1,
    1075,    -1,    70,    -1,    69,     3,  1132,    -1,  1077,    -1,
    1078,    -1,    43,  1132,     6,  1132,    -1,  1080,    -1,  1081,
      -1,  1082,    -1,    55,    -1,    25,     3,     8,    -1,  1084,
      -1,  1085,    -1,  1086,    -1,    62,    -1,    64,     3,  1132,
      -1,  1088,    -1,  1089,    -1,  1090,    -1,    66,    -1,    68,
    1132,  1131,  1132,    -1,  1092,    -1,  1093,    -1,  1094,    -1,
      59,    -1,    45,     3,     8,    -1,  1096,    -1,  1097,    -1,
    1098,    -1,    60,    -1,    44,     3,     8,    -1,  1100,    -1,
    1101,    -1,  1102,    -1,    54,    -1,    53,     3,     8,    -1,
      39,  1132,     6,  1132,    -1,    32,  1132,     6,  1132,    -1,
      40,  1132,     6,  1132,    -1,    17,  1132,     6,  1132,    -1,
      36,  1132,     6,  1132,    -1,    18,     8,     6,     8,    -1,
      38,  1132,     6,  1132,    -1,    31,  1132,     6,  1132,    -1,
      35,  1132,     6,  1132,    -1,    34,  1132,     6,  1132,    -1,
      16,  1132,     6,  1132,    -1,    33,  1132,     6,  1132,    -1,
      20,     8,     6,     8,    -1,    19,     8,     6,     8,    -1,
      27,     8,     6,     8,    -1,    28,  1132,     6,  1132,    -1,
      37,  1132,     6,  1132,    -1,    30,  1132,     6,  1132,    -1,
    1122,    -1,  1121,  1122,    -1,  1123,  1124,  1127,    -1,   225,
      -1,  1125,    -1,    -1,  1125,  1126,    -1,  1105,    -1,  1095,
      -1,  1043,    -1,  1128,    -1,  1129,    -1,    11,    -1,    10,
    1130,   226,    -1,  1163,    -1,     6,    -1,     7,    -1,  1133,
       8,    -1,    -1,  1133,  1134,    -1,   343,    -1,   344,    -1,
     345,    -1,   346,    -1,  1136,  1137,    -1,    75,    -1,  1138,
      -1,  1139,    -1,    10,    76,    -1,    11,    -1,    10,  1140,
      76,    -1,  1141,    -1,  1142,    -1,  1141,  1142,    -1,  1143,
      -1,  1147,    -1,  1151,    -1,  1155,    -1,  1159,    -1,    -1,
    1144,    -1,  1145,    -1,  1146,    -1,    90,    -1,    89,    -1,
      87,     5,    88,    -1,    -1,  1148,    -1,  1149,    -1,  1150,
      -1,    94,    -1,    93,    -1,    91,     5,    92,    -1,    -1,
    1152,    -1,  1153,    -1,  1154,    -1,    98,    -1,    97,    -1,
      95,     5,    96,    -1,    -1,  1156,    -1,  1157,    -1,  1158,
      -1,   102,    -1,   101,    -1,    99,     5,   100,    -1,    -1,
    1160,    -1,  1161,    -1,  1162,    -1,   106,    -1,   105,    -1,
     103,     5,   104,    -1,  1164,    -1,  1171,    -1,    -1,  1164,
    1165,    -1,  1166,  1167,  1170,    -1,   236,    -1,  1168,    -1,
      -1,  1168,  1169,    -1,  1177,    -1,  1176,    -1,    10,     6,
     237,    -1,   231,  1172,  1173,    -1,   235,  1132,     6,  1132,
      -1,  1174,    -1,  1175,    -1,    10,   232,    -1,    11,    -1,
      10,     4,   232,    -1,   233,  1132,     6,  1132,    -1,   234,
    1132,     6,  1132,    -1,   235,  1132,     6,  1132,    -1,  1174,
      -1,  1175,    -1,    10,   232,    -1,    11,    -1,    10,     4,
     232,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   269,   269,   270,   272,   279,   289,   289,   291,   291,
     293,   295,   297,   306,   307,   310,   318,   318,   331,   331,
     333,   349,   349,   351,   351,   353,   355,   357,   357,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     374,   376,   385,   385,   387,   387,   389,   391,   401,   403,
     410,   410,   412,   412,   414,   416,   426,   428,   434,   434,
     436,   436,   438,   440,   450,   457,   465,   466,   473,   479,
     479,   481,   481,   483,   485,   493,   495,   501,   501,   503,
     503,   505,   507,   516,   518,   525,   525,   527,   527,   529,
     531,   541,   543,   550,   550,   552,   552,   554,   556,   566,
     568,   574,   574,   576,   576,   578,   580,   590,   592,   598,
     598,   600,   600,   602,   604,   614,   621,   630,   631,   637,
     644,   644,   646,   646,   648,   650,   658,   664,   674,   682,
     687,   693,   693,   695,   697,   701,   701,   703,   711,   730,
     736,   736,   739,   743,   744,   747,   747,   756,   756,   758,
     768,   768,   770,   770,   772,   774,   776,   776,   779,   780,
     781,   782,   783,   787,   789,   799,   801,   801,   804,   805,
     808,   810,   818,   820,   830,   832,   832,   835,   836,   839,
     841,   850,   852,   862,   864,   864,   867,   868,   871,   873,
     882,   884,   892,   893,   895,   897,   908,   914,   924,   932,
     936,   941,   941,   943,   945,   949,   949,   951,   959,   978,
     983,   983,   986,   991,   992,   995,   995,  1004,  1004,  1006,
    1013,  1013,  1015,  1015,  1017,  1019,  1021,  1021,  1024,  1025,
    1029,  1031,  1037,  1037,  1039,  1039,  1041,  1043,  1054,  1060,
    1070,  1078,  1082,  1087,  1087,  1089,  1091,  1095,  1095,  1097,
    1105,  1124,  1129,  1129,  1132,  1137,  1138,  1141,  1141,  1149,
    1149,  1151,  1171,  1171,  1173,  1173,  1175,  1177,  1179,  1179,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1193,  1194,  1195,  1196,  1201,  1207,  1217,  1218,  1220,
    1220,  1222,  1222,  1224,  1226,  1228,  1235,  1237,  1243,  1243,
    1245,  1245,  1247,  1249,  1259,  1270,  1280,  1282,  1282,  1284,
    1284,  1286,  1295,  1295,  1297,  1318,  1329,  1339,  1339,  1341,
    1341,  1343,  1354,  1365,  1375,  1375,  1377,  1377,  1379,  1390,
    1401,  1411,  1411,  1413,  1413,  1415,  1426,  1437,  1447,  1447,
    1449,  1449,  1451,  1462,  1478,  1488,  1490,  1490,  1492,  1492,
    1494,  1503,  1503,  1505,  1509,  1525,  1535,  1537,  1537,  1539,
    1539,  1541,  1550,  1550,  1552,  1556,  1572,  1582,  1584,  1584,
    1586,  1586,  1588,  1597,  1597,  1599,  1603,  1619,  1629,  1631,
    1631,  1633,  1633,  1635,  1644,  1644,  1646,  1650,  1661,  1671,
    1673,  1673,  1675,  1675,  1677,  1688,  1699,  1709,  1711,  1711,
    1713,  1713,  1715,  1740,  1751,  1761,  1763,  1763,  1765,  1765,
    1767,  1776,  1776,  1778,  1799,  1805,  1815,  1823,  1827,  1832,
    1832,  1834,  1836,  1840,  1840,  1842,  1850,  1869,  1875,  1875,
    1878,  1883,  1884,  1887,  1887,  1895,  1895,  1897,  1905,  1907,
    1907,  1910,  1916,  1922,  1930,  1930,  1932,  1934,  1936,  1943,
    1943,  1945,  1951,  1958,  1958,  1963,  1963,  1965,  1967,  1969,
    1979,  1979,  1994,  1999,  2010,  2018,  2027,  2027,  2029,  2031,
    2033,  2033,  2036,  2041,  2055,  2061,  2061,  2064,  2076,  2081,
    2089,  2089,  2093,  2093,  2108,  2113,  2124,  2132,  2141,  2141,
    2143,  2145,  2147,  2147,  2150,  2155,  2170,  2176,  2176,  2179,
    2191,  2196,  2202,  2202,  2206,  2206,  2208,  2213,  2213,  2215,
    2217,  2219,  2222,  2222,  2233,  2239,  2246,  2246,  2248,  2250,
    2252,  2256,  2256,  2268,  2274,  2281,  2281,  2283,  2285,  2287,
    2291,  2291,  2302,  2308,  2315,  2315,  2317,  2319,  2321,  2325,
    2325,  2336,  2342,  2349,  2349,  2351,  2353,  2355,  2359,  2359,
    2370,  2376,  2383,  2383,  2385,  2387,  2389,  2393,  2393,  2404,
    2410,  2417,  2417,  2419,  2421,  2423,  2427,  2427,  2438,  2444,
    2451,  2451,  2453,  2455,  2457,  2461,  2461,  2477,  2482,  2493,
    2501,  2510,  2510,  2512,  2514,  2520,  2520,  2522,  2527,  2543,
    2549,  2549,  2552,  2564,  2569,  2577,  2577,  2581,  2581,  2587,
    2593,  2601,  2609,  2617,  2617,  2619,  2621,  2621,  2623,  2642,
    2658,  2666,  2666,  2669,  2670,  2679,  2682,  2682,  2684,  2684,
    2686,  2691,  2691,  2693,  2698,  2729,  2749,  2749,  2752,  2756,
    2760,  2761,  2762,  2763,  2764,  2765,  2766,  2767,  2770,  2770,
    2772,  2772,  2774,  2776,  2776,  2778,  2778,  2781,  2796,  2816,
    2818,  2818,  2821,  2831,  2832,  2833,  2834,  2837,  2839,  2839,
    2847,  2847,  2849,  2855,  2862,  2862,  2867,  2867,  2869,  2871,
    2873,  2882,  2882,  2898,  2904,  2916,  2924,  2933,  2933,  2935,
    2937,  2939,  2939,  2942,  2947,  2962,  2964,  2964,  2967,  2978,
    2982,  2989,  2989,  2992,  2992,  3010,  3015,  3029,  3037,  3046,
    3046,  3048,  3050,  3052,  3052,  3055,  3060,  3078,  3080,  3080,
    3083,  3094,  3098,  3104,  3111,  3111,  3115,  3115,  3117,  3122,
    3122,  3124,  3126,  3128,  3131,  3131,  3142,  3148,  3155,  3155,
    3157,  3159,  3161,  3164,  3164,  3175,  3181,  3188,  3188,  3190,
    3192,  3194,  3197,  3197,  3208,  3214,  3221,  3221,  3223,  3225,
    3227,  3230,  3230,  3241,  3247,  3254,  3254,  3256,  3258,  3260,
    3263,  3263,  3274,  3280,  3287,  3287,  3289,  3291,  3293,  3296,
    3296,  3307,  3314,  3321,  3321,  3323,  3325,  3327,  3331,  3331,
    3342,  3348,  3355,  3355,  3357,  3359,  3361,  3365,  3365,  3367,
    3373,  3404,  3425,  3425,  3428,  3432,  3436,  3437,  3438,  3439,
    3440,  3441,  3442,  3443,  3446,  3446,  3448,  3448,  3450,  3452,
    3452,  3454,  3454,  3457,  3472,  3494,  3496,  3496,  3499,  3509,
    3510,  3511,  3512,  3515,  3517,  3517,  3525,  3525,  3527,  3533,
    3540,  3540,  3545,  3545,  3547,  3549,  3551,  3560,  3560,  3576,
    3581,  3592,  3600,  3609,  3609,  3611,  3613,  3615,  3615,  3618,
    3623,  3638,  3644,  3644,  3647,  3658,  3662,  3669,  3669,  3673,
    3673,  3691,  3696,  3709,  3717,  3726,  3726,  3728,  3730,  3732,
    3732,  3735,  3740,  3758,  3764,  3764,  3767,  3778,  3782,  3786,
    3792,  3792,  3796,  3796,  3798,  3803,  3803,  3805,  3807,  3809,
    3812,  3812,  3823,  3829,  3836,  3836,  3838,  3840,  3842,  3845,
    3845,  3856,  3862,  3869,  3869,  3871,  3873,  3875,  3879,  3879,
    3890,  3896,  3903,  3903,  3905,  3907,  3909,  3913,  3913,  3924,
    3930,  3937,  3937,  3939,  3941,  3943,  3947,  3947,  3958,  3964,
    3971,  3971,  3973,  3975,  3977,  3981,  3981,  3992,  3998,  4005,
    4005,  4007,  4009,  4011,  4015,  4015,  4026,  4032,  4039,  4039,
    4041,  4043,  4045,  4049,  4049,  4051,  4057,  4088,  4108,  4108,
    4111,  4115,  4119,  4120,  4121,  4122,  4123,  4124,  4125,  4126,
    4129,  4129,  4131,  4131,  4133,  4135,  4135,  4137,  4137,  4140,
    4155,  4175,  4177,  4177,  4180,  4190,  4191,  4192,  4193,  4196,
    4198,  4198,  4206,  4206,  4212,  4214,  4222,  4230,  4239,  4241,
    4243,  4243,  4247,  4267,  4285,  4291,  4291,  4294,  4295,  4296,
    4297,  4298,  4299,  4300,  4307,  4315,  4324,  4324,  4326,  4328,
    4330,  4330,  4332,  4339,  4350,  4352,  4352,  4354,  4356,  4373,
    4373,  4375,  4397,  4414,  4426,  4431,  4431,  4434,  4435,  4436,
    4438,  4447,  4456,  4465,  4465,  4471,  4478,  4478,  4480,  4485,
    4492,  4498,  4498,  4500,  4503,  4510,  4517,  4517,  4519,  4522,
    4529,  4535,  4535,  4537,  4540,  4548,  4555,  4562,  4569,  4571,
    4577,  4584,  4584,  4586,  4591,  4598,  4604,  4604,  4606,  4611,
    4617,  4624,  4624,  4626,  4631,  4638,  4644,  4644,  4646,  4649,
    4657,  4663,  4663,  4665,  4668,  4675,  4681,  4683,  4691,  4697,
    4697,  4699,  4702,  4709,  4716,  4716,  4718,  4723,  4730,  4736,
    4736,  4738,  4741,  4748,  4754,  4754,  4756,  4759,  4766,  4772,
    4772,  4774,  4777,  4784,  4790,  4790,  4792,  4795,  4807,  4816,
    4825,  4834,  4843,  4852,  4862,  4871,  4880,  4886,  4892,  4898,
    4904,  4918,  4928,  4939,  4945,  4954,  4975,  4975,  4977,  4995,
    5011,  5019,  5019,  5022,  5029,  5030,  5034,  5034,  5036,  5039,
    5041,  5045,  5046,  5053,  5055,  5055,  5057,  5058,  5059,  5060,
    5093,  5095,  5109,  5109,  5111,  5111,  5113,  5115,  5117,  5117,
    5120,  5121,  5122,  5123,  5124,  5126,  5126,  5134,  5134,  5136,
    5136,  5138,  5144,  5144,  5152,  5152,  5154,  5154,  5156,  5162,
    5162,  5170,  5170,  5172,  5172,  5174,  5180,  5180,  5188,  5188,
    5190,  5190,  5192,  5198,  5198,  5206,  5206,  5208,  5208,  5210,
    5222,  5230,  5232,  5232,  5234,  5236,  5245,  5247,  5247,  5249,
    5249,  5251,  5267,  5269,  5274,  5274,  5276,  5276,  5279,  5305,
    5313,  5370,  5375,  5375,  5377,  5377,  5379
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
  "EMPTYWEIGHTATT", "TRANSPORTTYPEATT", "LOCATIONTYPEATT", "HEADERSTART",
  "HEADEREND", "GENERALSTART", "GENERALEND", "SYSTEMSTART", "SYSTEMEND",
  "SERVICESTART", "SERVICEEND", "JOBSTART", "JOBEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "FILENAMESTART", "FILENAMEEND", "FILENAMEEMPTY",
  "FILENAMESTARTANDEND", "FILESOURCESTART", "FILESOURCEEND",
  "FILESOURCEEMPTY", "FILESOURCESTARTANDEND", "FILEDESCRIPTIONSTART",
  "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
  "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART", "FILECREATOREND",
  "FILECREATOREMPTY", "FILECREATORSTARTANDEND", "FILELICENCESTART",
  "FILELICENCEEND", "FILELICENCEEMPTY", "FILELICENCESTARTANDEND",
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
  "MULTATT", "SIZEOFATT", "ELSTART", "ELEND", "MATRIXSTART", "MATRIXEND",
  "BASEMATRIXEND", "BASEMATRIXSTART", "BLOCKSTART", "BLOCKEND",
  "BLOCKSSTART", "BLOCKSEND", "EMPTYSYMMETRYATT", "SYMMETRYATT",
  "NUMBEROFBLOCKSATT", "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT",
  "BASEMATRIXIDXATT", "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
  "BASEMATRIXSTARTROWATT", "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT",
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "EMPTYBASETRANSPOSEATT",
  "BASETRANSPOSEATT", "ELEMENTSSTART", "ELEMENTSEND",
  "CONSTANTELEMENTSSTART", "CONSTANTELEMENTSEND", "STARTVECTORSTART",
  "STARTVECTOREND", "NONZEROSSTART", "NONZEROSEND", "INDEXESSTART",
  "INDEXESEND", "VALUESSTART", "VALUESEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "GENERALELEMENTSSTART", "GENERALELEMENTSEND", "COLOFFSETSSTART",
  "COLOFFSETSEND", "ROWOFFSETSSTART", "ROWOFFSETSEND", "EMPTYROWMAJORATT",
  "ROWMAJORATT", "BLOCKROWIDXATT", "BLOCKCOLIDXATT", "DUMMY",
  "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND",
  "NUMBEROFNONLINEAREXPRESSIONS", "NLSTART", "NLEND", "POWERSTART",
  "POWEREND", "PLUSSTART", "PLUSEND", "MINUSSTART", "MINUSEND",
  "DIVIDESTART", "DIVIDEEND", "LNSTART", "LNEND", "SQRTSTART", "SQRTEND",
  "SUMSTART", "SUMEND", "PRODUCTSTART", "PRODUCTEND", "EXPSTART", "EXPEND",
  "NEGATESTART", "NEGATEEND", "IFSTART", "IFEND", "SQUARESTART",
  "SQUAREEND", "COSSTART", "COSEND", "SINSTART", "SINEND", "VARIABLESTART",
  "VARIABLEEND", "ABSSTART", "ABSEND", "ERFSTART", "ERFEND", "MAXSTART",
  "MAXEND", "ALLDIFFSTART", "ALLDIFFEND", "MINSTART", "MINEND", "ESTART",
  "EEND", "PISTART", "PIEND", "TIMESSTART", "TIMESEND", "NUMBERSTART",
  "NUMBEREND", "IDATT", "COEFATT", "' '", "'\\t'", "'\\r'", "'\\n'",
  "$accept", "osoldoc", "osolStartEmpty", "osolStart", "osolAttributes",
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
  "Base64SizeAttribute", "Base64Content", "Base64Empty", "Base64Laden",
  "osglIncrAttribute", "osglMultAttribute", 0
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
     595,   596,   597,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   347,   348,   348,   349,   350,   351,   351,   352,   352,
     353,   354,   355,   356,   356,   357,   358,   358,   359,   359,
     360,   361,   361,   362,   362,   363,   364,   365,   365,   366,
     366,   366,   366,   366,   366,   366,   366,   366,   366,   366,
     367,   368,   369,   369,   370,   370,   371,   372,   373,   374,
     375,   375,   376,   376,   377,   378,   379,   380,   381,   381,
     382,   382,   383,   384,   385,   386,   387,   387,   388,   389,
     389,   390,   390,   391,   392,   393,   394,   395,   395,   396,
     396,   397,   398,   399,   400,   401,   401,   402,   402,   403,
     404,   405,   406,   407,   407,   408,   408,   409,   410,   411,
     412,   413,   413,   414,   414,   415,   416,   417,   418,   419,
     419,   420,   420,   421,   422,   423,   424,   425,   425,   426,
     427,   427,   428,   428,   429,   430,   431,   432,   433,   434,
     434,   435,   435,   436,   437,   438,   438,   439,   440,   441,
     442,   442,   443,   443,   443,   444,   444,   445,   445,   446,
     447,   447,   448,   448,   449,   450,   451,   451,   452,   452,
     452,   452,   452,   453,   454,   455,   456,   456,   457,   457,
     458,   459,   460,   461,   462,   463,   463,   464,   464,   465,
     466,   467,   468,   469,   470,   470,   471,   471,   472,   473,
     474,   475,   476,   476,   477,   478,   479,   480,   481,   482,
     482,   483,   483,   484,   485,   486,   486,   487,   488,   489,
     490,   490,   491,   491,   491,   492,   492,   493,   493,   494,
     495,   495,   496,   496,   497,   498,   499,   499,   500,   500,
     501,   502,   503,   503,   504,   504,   505,   506,   507,   508,
     509,   510,   510,   511,   511,   512,   513,   514,   514,   515,
     516,   517,   518,   518,   519,   519,   519,   520,   520,   521,
     521,   522,   523,   523,   524,   524,   525,   526,   527,   527,
     528,   528,   528,   528,   528,   528,   528,   528,   528,   528,
     528,   528,   528,   528,   528,   529,   530,   531,   531,   532,
     532,   533,   533,   534,   535,   536,   537,   538,   539,   539,
     540,   540,   541,   542,   543,   544,   545,   546,   546,   547,
     547,   548,   549,   549,   550,   551,   552,   553,   553,   554,
     554,   555,   556,   557,   558,   558,   559,   559,   560,   561,
     562,   563,   563,   564,   564,   565,   566,   567,   568,   568,
     569,   569,   570,   571,   572,   573,   574,   574,   575,   575,
     576,   577,   577,   578,   579,   580,   581,   582,   582,   583,
     583,   584,   585,   585,   586,   587,   588,   589,   590,   590,
     591,   591,   592,   593,   593,   594,   595,   596,   597,   598,
     598,   599,   599,   600,   601,   601,   602,   603,   604,   605,
     606,   606,   607,   607,   608,   609,   610,   611,   612,   612,
     613,   613,   614,   615,   616,   617,   618,   618,   619,   619,
     620,   621,   621,   622,   623,   624,   625,   626,   626,   627,
     627,   628,   629,   630,   630,   631,   632,   633,   634,   634,
     635,   635,   635,   636,   636,   637,   637,   638,   639,   640,
     640,   641,   641,   641,   642,   642,   643,   644,   645,   646,
     646,   647,   648,   649,   649,   650,   650,   651,   652,   653,
     654,   654,   655,   656,   657,   657,   658,   658,   659,   660,
     661,   661,   662,   663,   664,   665,   665,   666,   666,   666,
     667,   667,   668,   668,   669,   670,   671,   671,   672,   672,
     673,   674,   675,   675,   676,   677,   678,   679,   679,   680,
     680,   680,   681,   681,   682,   682,   683,   684,   684,   685,
     686,   687,   688,   688,   689,   690,   691,   691,   692,   693,
     694,   695,   695,   696,   697,   698,   698,   699,   700,   701,
     702,   702,   703,   704,   705,   705,   706,   707,   708,   709,
     709,   710,   711,   712,   712,   713,   714,   715,   716,   716,
     717,   718,   719,   719,   720,   721,   722,   723,   723,   724,
     725,   726,   726,   727,   728,   729,   730,   730,   731,   732,
     733,   733,   734,   735,   736,   737,   737,   738,   739,   740,
     740,   741,   741,   742,   743,   744,   744,   745,   746,   747,
     748,   748,   749,   749,   749,   750,   750,   751,   751,   752,
     753,   754,   754,   755,   755,   756,   757,   757,   758,   759,
     760,   761,   761,   762,   762,   762,   763,   763,   764,   764,
     765,   766,   766,   767,   768,   769,   770,   770,   771,   771,
     771,   771,   771,   771,   771,   771,   771,   771,   772,   772,
     773,   773,   774,   775,   775,   776,   776,   777,   778,   779,
     780,   780,   781,   781,   781,   781,   781,   782,   783,   783,
     784,   784,   785,   786,   787,   787,   788,   788,   789,   790,
     791,   792,   792,   793,   794,   795,   795,   796,   796,   797,
     798,   799,   799,   800,   801,   802,   803,   803,   804,   804,
     804,   805,   805,   806,   806,   807,   808,   809,   809,   810,
     810,   811,   812,   813,   813,   814,   815,   816,   817,   817,
     818,   818,   818,   818,   819,   819,   820,   820,   821,   822,
     822,   823,   824,   825,   826,   826,   827,   828,   829,   829,
     830,   831,   832,   833,   833,   834,   835,   836,   836,   837,
     838,   839,   840,   840,   841,   842,   843,   843,   844,   845,
     846,   847,   847,   848,   849,   850,   850,   851,   852,   853,
     854,   854,   855,   856,   857,   857,   858,   859,   860,   861,
     861,   862,   863,   864,   864,   865,   866,   867,   868,   868,
     869,   870,   871,   871,   872,   873,   874,   875,   875,   876,
     877,   878,   879,   879,   880,   880,   880,   880,   880,   880,
     880,   880,   880,   880,   881,   881,   882,   882,   883,   884,
     884,   885,   885,   886,   887,   888,   889,   889,   890,   890,
     890,   890,   890,   891,   892,   892,   893,   893,   894,   895,
     896,   896,   897,   897,   898,   899,   900,   901,   901,   902,
     903,   904,   904,   905,   905,   906,   907,   908,   908,   909,
     910,   911,   912,   912,   913,   913,   913,   914,   914,   915,
     915,   916,   917,   918,   918,   919,   919,   920,   921,   922,
     922,   923,   924,   925,   926,   926,   927,   927,   927,   927,
     928,   928,   929,   929,   930,   931,   931,   932,   933,   934,
     935,   935,   936,   937,   938,   938,   939,   940,   941,   942,
     942,   943,   944,   945,   945,   946,   947,   948,   949,   949,
     950,   951,   952,   952,   953,   954,   955,   956,   956,   957,
     958,   959,   959,   960,   961,   962,   963,   963,   964,   965,
     966,   966,   967,   968,   969,   970,   970,   971,   972,   973,
     973,   974,   975,   976,   977,   977,   978,   979,   980,   980,
     981,   982,   983,   984,   984,   985,   986,   987,   988,   988,
     989,   989,   989,   989,   989,   989,   989,   989,   989,   989,
     990,   990,   991,   991,   992,   993,   993,   994,   994,   995,
     996,   997,   998,   998,   999,   999,   999,   999,   999,  1000,
    1001,  1001,  1002,  1002,  1003,  1004,  1005,  1005,  1006,  1007,
    1008,  1008,  1009,  1010,  1011,  1012,  1012,  1013,  1013,  1013,
    1013,  1013,  1013,  1013,  1014,  1014,  1015,  1015,  1016,  1017,
    1018,  1018,  1019,  1020,  1020,  1021,  1021,  1022,  1023,  1024,
    1024,  1025,  1026,  1027,  1028,  1029,  1029,  1030,  1030,  1030,
    1031,  1032,  1033,  1034,  1034,  1035,  1036,  1036,  1037,  1038,
    1039,  1040,  1040,  1041,  1042,  1043,  1044,  1044,  1045,  1046,
    1047,  1048,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,
    1056,  1057,  1057,  1058,  1059,  1060,  1061,  1061,  1062,  1063,
    1064,  1065,  1065,  1066,  1067,  1068,  1069,  1069,  1070,  1071,
    1072,  1073,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1080,  1081,  1082,  1083,  1084,  1084,  1085,  1086,  1087,  1088,
    1088,  1089,  1090,  1091,  1092,  1092,  1093,  1094,  1095,  1096,
    1096,  1097,  1098,  1099,  1100,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1121,  1122,  1123,
    1124,  1125,  1125,  1126,  1126,  1126,  1127,  1127,  1128,  1129,
    1130,  1131,  1131,  1132,  1133,  1133,  1134,  1134,  1134,  1134,
    1135,  1136,  1137,  1137,  1138,  1138,  1139,  1140,  1141,  1141,
    1142,  1142,  1142,  1142,  1142,  1143,  1143,  1144,  1144,  1145,
    1145,  1146,  1147,  1147,  1148,  1148,  1149,  1149,  1150,  1151,
    1151,  1152,  1152,  1153,  1153,  1154,  1155,  1155,  1156,  1156,
    1157,  1157,  1158,  1159,  1159,  1160,  1160,  1161,  1161,  1162,
    1163,  1163,  1164,  1164,  1165,  1166,  1167,  1168,  1168,  1169,
    1169,  1170,  1171,  1172,  1173,  1173,  1174,  1174,  1175,  1176,
    1177,  1172,  1173,  1173,  1174,  1174,  1175
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
       2,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     1,
       1,     1,     3,     0,     1,     1,     1,     1,     1,     3,
       1,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     3,     3,     4,     1,     1,     2,     1,     3,     4,
       4,     4,     1,     1,     2,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,  1171,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   147,     0,
       0,  1175,  1170,  1172,  1173,    16,    10,     3,     8,     9,
     149,   217,     0,     0,    24,    19,    21,    22,  1174,     0,
    1190,  1189,     0,  1197,  1196,     0,  1204,  1203,     0,  1211,
    1210,     0,  1218,  1217,     0,  1177,  1178,  1180,  1186,  1187,
    1188,  1181,  1193,  1194,  1195,  1182,  1200,  1201,  1202,  1183,
    1207,  1208,  1209,  1184,  1214,  1215,  1216,    14,   219,   259,
       0,     0,   153,   148,   150,   151,    23,    41,    49,    57,
      65,    76,    84,    92,   100,   108,   116,   127,     0,    26,
      27,    29,     0,    30,     0,    31,     0,    32,    66,    33,
       0,    34,     0,    35,     0,    36,     0,    37,     0,    38,
     117,    39,     0,     0,     0,     0,     0,     0,  1176,  1179,
      11,   261,   435,     0,     0,   223,   218,   220,   221,   152,
     197,   164,   173,   182,   191,     0,   155,   156,   158,   166,
     159,   175,   160,   184,   161,   192,   162,     0,    25,    28,
       0,    45,    40,    42,    43,     0,    53,    48,    50,    51,
       0,    61,    56,    58,    59,     0,     0,    67,     0,    80,
      75,    77,    78,     0,    88,    83,    85,    86,     0,    96,
      91,    93,    94,     0,   104,    99,   101,   102,     0,   112,
     107,   109,   110,     0,     0,   118,  1164,     0,   128,  1191,
    1198,  1205,  1212,  1219,   437,    15,   439,     0,   265,   260,
     262,   263,   222,   239,   231,     0,   225,   226,   228,     0,
     229,     0,   154,   157,     0,   165,     0,   174,     0,   183,
       0,  1058,     0,   193,  1055,  1056,  1057,     0,   198,    47,
      44,     0,    55,    52,     0,    63,    60,     0,     0,     0,
      72,    64,    69,    70,    82,    79,     0,    90,    87,     0,
      98,    95,     0,   106,   103,     0,   114,   111,     0,     0,
       0,   123,   115,   120,   121,     0,     0,     0,   132,   126,
     129,   130,     0,   438,   264,   415,   286,   297,   305,   316,
     323,   330,   337,   396,   388,   344,   355,   377,   366,   404,
       0,   267,   268,   270,   287,   271,     0,   272,     0,   273,
       0,   274,     0,   275,     0,   276,     0,   277,     0,   278,
       0,   280,     0,   279,     0,   281,     0,   282,     0,   283,
       0,   284,     0,   224,   227,     0,   235,   230,   232,   233,
       0,   240,     0,   163,     0,  1116,   167,   169,   168,  1113,
    1114,  1115,     0,   172,   176,   178,   177,     0,   181,   185,
     187,   186,  1164,     0,   190,     0,   202,   196,   199,   200,
      46,    54,    62,    68,    74,    71,     0,    81,    89,    97,
     105,   113,   119,   125,   122,     0,  1164,  1163,  1166,  1167,
    1168,  1169,  1165,   131,   138,     0,   134,   135,   140,   449,
     446,   436,   444,   445,  1164,  1164,  1164,   440,   442,   443,
     441,   266,   269,     0,   288,     0,   301,   296,   298,   299,
       0,     0,   306,     0,     0,     0,     0,     0,     0,     0,
     345,     0,   356,     0,   367,     0,   378,     0,   389,     0,
     397,     0,     0,   405,     0,   416,   237,   234,     0,     0,
     244,   238,   241,   242,  1161,  1162,     0,   171,     0,     0,
     180,     0,   189,  1059,   195,     0,   201,   208,     0,   204,
     205,   210,    73,   124,  1138,   133,   136,     0,   139,   451,
       0,   660,   453,     0,     0,     0,     0,   292,   285,   289,
     290,   303,   300,     0,     0,     0,   310,   304,   307,   308,
       0,     0,   320,   315,   317,   318,     0,   327,   322,   324,
     325,     0,   334,   329,   331,   332,     0,   341,   336,   338,
     339,     0,     0,   349,   343,   346,   347,     0,   360,   354,
     357,   358,     0,   371,   365,   368,   369,     0,   382,   376,
     379,   380,     0,   393,   387,   390,   391,     0,   401,   395,
     398,   399,     0,     0,   409,   403,   406,   407,     0,   420,
     414,   417,   418,   236,   243,   250,     0,   246,   247,   252,
     170,  1117,   179,   188,   194,   203,   206,     0,   209,     0,
     146,   137,     0,     0,  1083,  1121,   141,   144,   142,  1080,
    1081,  1082,   143,  1118,  1119,  1120,   447,   662,   826,   664,
    1164,     0,   452,   454,  1164,  1164,  1164,   291,     0,   294,
     295,   302,     0,     0,   309,     0,   312,     0,   319,     0,
       0,  1029,   326,     0,   333,     0,   340,     0,     0,  1033,
     348,     0,   351,   353,  1035,   359,     0,   362,   364,   370,
       0,   373,   375,   381,     0,   384,   386,   392,     0,   400,
       0,     0,   408,     0,     0,   411,   419,   426,     0,   422,
     423,   428,   245,   248,     0,   251,     0,   216,   207,   211,
     214,   212,   213,   145,  1164,     0,   828,   992,   830,  1164,
       0,   663,   665,     0,   460,   457,   450,   455,   456,  1145,
    1135,  1129,   293,  1133,     0,   311,   313,  1141,     0,   321,
    1030,   328,   335,   342,  1140,   350,   352,     0,  1034,   361,
     363,   372,   374,   383,   385,   394,   402,  1142,     0,   410,
     412,   421,   424,     0,   427,     0,   258,   249,   253,   256,
     254,   255,   215,  1084,  1122,   994,   448,     0,  1164,     0,
     829,   831,     0,   671,   668,   661,   666,   667,  1164,   462,
       0,   482,     0,     0,     0,     0,  1044,  1032,     0,     0,
       0,  1036,  1037,  1038,  1039,     0,     0,   434,   425,   429,
     432,   430,   431,   257,  1164,     0,   995,     0,   837,   834,
     827,   832,   833,  1164,   673,     0,   693,     0,  1139,   458,
     484,   504,     0,  1164,     0,   463,   314,  1031,  1043,     0,
       0,     0,   413,   433,     0,  1000,   998,   993,   996,   997,
    1164,   839,     0,   859,     0,  1137,   669,   695,   716,     0,
    1164,     0,   674,   506,   575,     0,     0,   485,     0,     0,
     467,   461,   464,   465,  1040,  1041,  1042,  1164,     0,  1136,
     835,   861,   882,     0,  1164,     0,   840,   718,   787,     0,
       0,   696,     0,     0,   678,   672,   675,   676,   577,   597,
       0,   512,   509,   505,   507,   508,     0,   489,   483,   486,
     487,  1164,   466,   473,     0,   469,   470,   475,  1143,   999,
    1003,  1001,     0,   884,   953,     0,     0,   862,     0,     0,
     844,   838,   841,   842,   670,   724,   721,   717,   719,   720,
       0,   700,   694,   697,   698,  1164,   677,   684,     0,   680,
     681,   686,   599,   621,     0,     0,   578,   514,     0,   521,
       0,   495,   488,     0,   491,   492,   497,  1144,   468,   471,
       0,   474,     0,     0,  1164,  1101,  1048,     0,  1093,     0,
    1004,  1005,  1010,  1045,  1046,  1047,  1012,  1007,  1009,  1090,
    1091,  1092,  1011,  1098,  1099,  1100,  1008,  1013,   836,   890,
     887,   883,   885,   886,     0,   866,   860,   863,   864,  1164,
     843,   850,     0,   846,   847,   852,   790,   788,   792,   726,
       0,   733,     0,   706,   699,     0,   702,   703,   708,  1134,
     679,   682,     0,   685,   459,     0,     0,     0,   582,   576,
     579,   580,   510,   523,   530,     0,  1164,     0,   515,   490,
     493,     0,   496,     0,   481,   472,  1164,   476,   477,  1067,
    1068,   478,   479,  1164,     0,     0,  1164,     0,  1017,  1002,
    1014,  1015,  1006,   956,   954,   958,   892,     0,   899,     0,
     872,   865,     0,   868,   869,   874,  1128,   845,   848,     0,
     851,     0,   791,   722,   735,   742,     0,     0,   727,   701,
     704,     0,   707,     0,   692,   683,   687,   688,   689,   690,
     624,   622,   626,     0,     0,   604,   598,   601,   602,   588,
     581,     0,   584,   585,   590,   532,   539,     0,     0,   524,
       0,  1222,   518,   513,   516,   517,     0,   503,   494,   498,
     499,   500,   501,   480,     0,  1049,  1102,  1164,  1094,  1016,
    1026,     0,  1025,     0,  1019,  1020,  1022,  1023,  1024,     0,
     957,   888,   901,   908,     0,     0,   893,   867,   870,     0,
     873,     0,   858,   849,   853,   854,   855,   856,     0,   807,
     789,   804,   805,  1164,     0,  1063,     0,  1088,   793,   799,
     803,   802,  1060,  1061,  1062,   796,   801,  1085,  1086,  1087,
     798,   800,   797,   795,   794,   744,   751,     0,     0,   736,
    1222,   730,   725,   728,   729,     0,   715,   705,  1073,  1106,
       0,     0,   709,   710,   712,  1070,  1071,  1072,   711,   713,
    1103,  1104,  1105,   691,     0,   625,     0,   603,   609,     0,
     606,   611,   583,   586,     0,   589,   541,   548,     0,     0,
     533,  1222,   527,   522,   525,   526,  1164,     0,     0,   520,
    1220,  1221,   502,  1164,  1132,  1028,     0,  1018,  1021,     0,
     973,   955,   970,   971,     0,  1053,   959,   965,   967,  1050,
    1051,  1052,   969,   968,   962,   964,   966,   963,   960,   961,
     910,   917,     0,     0,   902,  1222,   896,   891,   894,   895,
       0,   881,   871,  1078,  1111,  1164,  1164,   875,   876,   878,
    1075,  1076,  1077,   877,   879,  1108,  1109,  1110,   857,   806,
     814,  1149,     0,   809,   811,   816,   810,  1146,  1151,     0,
       0,     0,   753,   760,     0,     0,   745,  1222,   739,   734,
     737,   738,     0,   732,   714,  1164,  1164,     0,   641,   623,
     638,   639,     0,  1126,   627,   633,   637,   636,   630,   632,
     634,   631,   635,  1123,  1124,  1125,   629,   628,   600,   605,
     607,     0,   610,     0,   596,   587,   591,   592,   593,   594,
     550,   557,     0,     0,   542,  1222,   536,   531,   534,   535,
       0,   529,  1130,  1164,     0,   519,  1225,  1223,  1227,  1069,
    1027,   972,   980,     0,   975,   977,   982,   976,     0,   919,
     926,     0,     0,   911,  1222,   905,   900,   903,   904,     0,
     898,   880,     0,     0,   808,   812,     0,   815,  1147,     0,
    1150,  1164,  1064,  1089,   762,   769,     0,     0,   754,  1222,
     748,   743,   746,   747,     0,   741,   731,  1074,  1107,   640,
     648,     0,   643,   645,   650,   644,     0,     0,   619,   608,
     616,   617,     0,  1164,   612,   615,  1065,   613,  1095,  1096,
     614,   595,   559,   566,     0,     0,   551,  1222,   545,   540,
     543,   544,     0,   538,   528,     0,     0,  1237,  1232,  1234,
    1235,     0,  1226,   974,   978,     0,   981,  1054,   928,   935,
       0,     0,   920,  1222,   914,   909,   912,   913,     0,   907,
     897,  1164,  1164,     0,   825,   813,   823,   817,   818,   821,
     819,   822,   820,  1222,  1158,  1148,  1156,  1157,  1155,  1154,
    1153,  1152,  1131,   771,   778,     0,     0,   763,  1222,   757,
     752,   755,   756,     0,   750,   740,   642,   646,     0,   649,
    1127,   618,     0,     0,     0,   568,   511,     0,     0,   560,
    1222,   554,   549,   552,   553,     0,   547,   537,  1164,     0,
    1236,     0,  1224,  1164,  1164,  1228,  1230,  1229,     0,   991,
     979,   989,   983,   984,   987,   985,   988,   986,   937,   944,
       0,     0,   929,  1222,   923,   918,   921,   922,     0,   916,
     906,  1079,  1112,   824,     0,  1160,   780,   723,     0,     0,
     772,  1222,   766,   761,   764,   765,     0,   759,   749,     0,
     659,   647,   657,   651,   652,   655,   653,   656,   654,   620,
       0,  1164,     0,   569,  1222,   563,   558,   561,   562,     0,
     556,   546,  1233,  1238,     0,     0,     0,   990,   946,   889,
       0,     0,   938,  1222,   932,   927,   930,   931,     0,   925,
     915,  1159,     0,   781,  1222,   775,   770,   773,   774,     0,
     768,   758,   658,  1066,  1097,  1222,   572,   567,   570,   571,
       0,   565,   555,  1231,  1164,  1164,     0,   947,  1222,   941,
     936,   939,   940,     0,   934,   924,  1222,   784,   779,   782,
     783,     0,   777,   767,     0,   574,   564,  1239,  1240,  1222,
     950,   945,   948,   949,     0,   943,   933,     0,   786,   776,
     573,     0,   952,   942,   785,   951
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    27,    28,    29,    15,    16,
       8,     9,    18,    19,    35,    36,    37,    98,    99,   100,
     101,   102,   162,   163,   164,   251,   103,   104,   167,   168,
     169,   254,   105,   106,   172,   173,   174,   257,   107,   108,
     176,   177,   261,   262,   263,   386,   109,   110,   180,   181,
     182,   266,   111,   112,   185,   186,   187,   269,   113,   114,
     190,   191,   192,   272,   115,   116,   195,   196,   197,   275,
     117,   118,   200,   201,   202,   278,   119,   120,   204,   205,
     282,   283,   284,   395,   121,   122,   207,   289,   290,   291,
     405,   406,   407,   408,   487,   488,   596,   591,    31,    32,
      83,    84,    85,   145,   146,   147,   148,   149,   234,   235,
     356,   353,   466,   150,   151,   236,   237,   364,   363,   469,
     152,   153,   238,   239,   369,   368,   471,   154,   155,   242,
     374,   475,   156,   157,   247,   377,   378,   379,   478,   479,
     480,   481,   587,   588,   679,   678,    79,    80,   136,   137,
     138,   225,   226,   227,   228,   229,   347,   348,   349,   458,
     230,   231,   350,   461,   462,   463,   576,   577,   578,   579,
     674,   675,   738,   737,   132,   133,   219,   220,   221,   310,
     311,   312,   313,   314,   423,   498,   499,   500,   618,   619,
     315,   316,   427,   428,   429,   503,   317,   318,   431,   507,
     508,   509,   625,   626,   319,   320,   513,   514,   515,   321,
     322,   518,   519,   520,   323,   324,   523,   524,   525,   325,
     326,   528,   529,   530,   327,   328,   439,   534,   535,   536,
     641,   642,   329,   330,   441,   539,   540,   541,   646,   647,
     331,   332,   443,   544,   545,   546,   650,   651,   333,   334,
     445,   549,   550,   551,   654,   655,   335,   336,   447,   554,
     555,   556,   337,   338,   449,   559,   560,   561,   339,   340,
     452,   565,   566,   567,   664,   665,   341,   342,   454,   570,
     571,   572,   668,   669,   670,   671,   733,   734,   779,   778,
     215,   216,   292,   293,   417,   411,   412,   413,   490,   491,
     492,   611,   612,   696,   697,   698,   760,   761,   762,   804,
     841,   842,   843,   884,   885,   886,   887,   940,   941,  1027,
    1025,   801,   802,   836,   878,   879,   880,   933,   934,   935,
     936,  1021,  1022,  1109,  1108,   834,   835,   873,   874,   875,
     928,   929,   930,  1017,  1103,  1104,  1105,  1228,  1014,  1015,
    1098,  1223,  1224,  1225,  1360,  1096,  1097,  1219,  1357,  1358,
    1359,  1452,  1217,  1218,  1353,  1449,  1450,  1451,  1535,  1351,
    1352,  1445,  1532,  1533,  1534,  1609,  1443,  1444,  1528,  1606,
    1607,  1608,  1650,  1526,  1527,  1602,  1647,  1648,  1649,  1674,
     869,   870,   925,  1009,  1010,  1011,  1091,  1092,  1093,  1094,
    1214,  1215,  1346,  1345,   923,   924,  1006,  1086,  1087,  1088,
    1209,  1210,  1211,  1341,  1342,  1434,  1429,  1430,  1431,  1004,
    1081,  1082,  1204,  1205,  1324,  1319,  1320,  1321,  1421,  1422,
    1423,  1424,  1518,  1519,  1593,  1591,  1592,   608,   609,   690,
     691,   755,   756,   757,   795,   796,   797,   831,   865,   866,
     867,   918,   919,   920,   921,  1002,  1003,  1076,  1075,   828,
     829,   860,   912,   913,   914,   995,   996,   997,   998,  1071,
    1072,  1192,  1187,   858,   859,   907,   908,   909,   990,   991,
     992,  1067,  1182,  1183,  1184,  1312,  1065,  1066,  1178,  1309,
    1310,  1311,  1414,  1176,  1177,  1305,  1411,  1412,  1413,  1513,
    1303,  1304,  1407,  1510,  1511,  1512,  1586,  1405,  1406,  1506,
    1583,  1584,  1585,  1639,  1504,  1505,  1579,  1636,  1637,  1638,
    1671,  1577,  1578,  1632,  1668,  1669,  1670,  1687,   904,   987,
     988,  1061,  1062,  1158,  1150,  1151,  1152,  1292,  1293,  1294,
    1295,  1396,  1397,  1487,  1485,  1486,   687,   688,   749,   750,
     790,   791,   792,   822,   823,   824,   855,   901,   902,   903,
     982,   983,   984,   985,  1059,  1060,  1144,  1143,   852,   853,
     896,   976,   977,   978,  1052,  1053,  1054,  1055,  1139,  1140,
    1277,  1272,   894,   895,   971,   972,   973,  1047,  1048,  1049,
    1135,  1267,  1268,  1269,  1389,  1133,  1134,  1263,  1386,  1387,
    1388,  1478,  1261,  1262,  1382,  1475,  1476,  1477,  1568,  1380,
    1381,  1471,  1565,  1566,  1567,  1628,  1469,  1470,  1561,  1625,
    1626,  1627,  1663,  1559,  1560,  1621,  1660,  1661,  1662,  1684,
    1619,  1620,  1656,  1681,  1682,  1683,  1691,   968,  1044,  1045,
    1129,  1130,  1246,  1241,  1242,  1243,  1373,  1374,  1375,  1376,
    1465,  1466,  1552,  1550,  1551,   746,   747,   785,   817,   818,
     819,   848,   891,   892,   949,   950,   951,  1039,  1040,  1041,
    1123,  1124,  1125,  1126,  1127,  1128,  1236,   630,   631,   643,
     644,   717,   718,   771,   772,   773,   774,   767,   952,   953,
     954,   955,  1248,  1249,  1250,  1251,   956,   244,   245,   246,
    1161,  1162,  1163,  1164,  1435,  1436,  1028,  1029,  1030,  1194,
    1195,  1196,  1197,  1279,  1280,  1281,  1282,   957,   599,   600,
     601,  1166,  1167,  1168,  1169,   958,   959,   960,   961,  1437,
    1438,  1439,   962,   963,   964,   965,  1199,  1200,  1201,  1202,
    1284,  1285,  1286,  1287,   358,   359,   360,   361,   966,   603,
     604,   605,  1332,  1333,  1334,  1335,   856,   418,  1018,  1173,
     967,   432,   832,   419,   751,   692,   208,   613,   440,   434,
     453,   786,   805,   420,  1296,  1297,  1298,  1399,  1400,  1501,
    1495,  1496,  1497,  1574,   467,   285,   286,   402,    10,    11,
      22,    23,    24,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,  1229,  1230,  1367,  1368,
    1461,  1462,  1545,  1542,  1231,  1364,  1458,  1459,  1460,  1546,
    1547
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1372
static const yytype_int16 yypact[] =
{
     141, -1372, -1372,    76,    47,   114, -1372, -1372,   159,    93,
   -1372,   294, -1372,   350, -1372, -1372, -1372, -1372,    97,   370,
     576, -1372, -1372, -1372, -1372,    47, -1372, -1372, -1372, -1372,
   -1372,    99,   377,    94, -1372, -1372, -1372, -1372, -1372,   181,
   -1372, -1372,   183, -1372, -1372,   205, -1372, -1372,   217, -1372,
   -1372,   223, -1372, -1372,   171,   596, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   159, -1372,   152,
     379,   -25, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   175,   444,
   -1372, -1372,   383, -1372,   387, -1372,   400, -1372,   187, -1372,
     403, -1372,   425, -1372,   430, -1372,   439, -1372,   442, -1372,
     195, -1372,   256,   194,   188,   196,   186,   210, -1372, -1372,
   -1372, -1372,   211,   449,   -28, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   218,   -65, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,    71, -1372,   256, -1372, -1372,
      32, -1372, -1372, -1372, -1372,    29, -1372, -1372, -1372, -1372,
      35, -1372, -1372, -1372, -1372,   297,   453, -1372,    28, -1372,
   -1372, -1372, -1372,    27, -1372, -1372, -1372, -1372,    26, -1372,
   -1372, -1372, -1372,    30, -1372, -1372, -1372, -1372,    17, -1372,
   -1372, -1372, -1372,   317,   457, -1372, -1372,   460, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   124, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   258,    38, -1372, -1372,   468,
   -1372,   256, -1372, -1372,   325,   139,   332,   139,   334,   139,
     347, -1372,   346, -1372, -1372, -1372, -1372,   470, -1372, -1372,
   -1372,   284, -1372, -1372,   285, -1372, -1372,   287,   394,    41,
   -1372, -1372, -1372, -1372, -1372, -1372,   289, -1372, -1372,   307,
   -1372, -1372,   299, -1372, -1372,   305, -1372, -1372,   309,   399,
      25, -1372, -1372, -1372, -1372,   431,     2,   238, -1372, -1372,
   -1372, -1372,   473,   301, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
     363,   385, -1372, -1372,    75, -1372,   477, -1372,   443, -1372,
     446, -1372,   446, -1372,   446, -1372,   446, -1372,   452, -1372,
     452, -1372,   452, -1372,   452, -1372,   446, -1372,   446, -1372,
     447, -1372,   256, -1372, -1372,    23, -1372, -1372, -1372, -1372,
     479, -1372,   448, -1372,   482, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,   448, -1372, -1372, -1372, -1372,   448, -1372, -1372,
   -1372, -1372, -1372,   489, -1372,   372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,   392, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   367, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   380,   388, -1372, -1372,   345,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   492, -1372,    13, -1372, -1372, -1372, -1372,
     521,   494, -1372,   523,   500,   503,   505,   513,   531,   525,
   -1372,   563, -1372,   573, -1372,   575, -1372,   580, -1372,   582,
   -1372,   539,   584, -1372,   586, -1372, -1372, -1372,   393,   487,
   -1372, -1372, -1372, -1372, -1372, -1372,   409, -1372,   550,   391,
   -1372,   424, -1372, -1372, -1372,   426, -1372, -1372,   434,   437,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   588,   283, -1372,
     484,   374,   535,   598,   600,   603,    16, -1372, -1372, -1372,
   -1372, -1372, -1372,   499,   635,   -56, -1372, -1372, -1372, -1372,
     645,   115, -1372, -1372, -1372, -1372,   451, -1372, -1372, -1372,
   -1372,    36, -1372, -1372, -1372, -1372,   -20, -1372, -1372, -1372,
   -1372,   647,   -32, -1372, -1372, -1372, -1372,   -40, -1372, -1372,
   -1372, -1372,  -103, -1372, -1372, -1372, -1372,   -88, -1372, -1372,
   -1372, -1372,    63, -1372, -1372, -1372, -1372,    69, -1372, -1372,
   -1372, -1372,   654,   445, -1372, -1372, -1372, -1372,   497, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,   495,   543, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   617,   283,   532,
   -1372, -1372,   665,   673, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   467,   650,
   -1372,   619, -1372, -1372, -1372, -1372, -1372, -1372,   546, -1372,
   -1372, -1372,   684,   686, -1372,   -55, -1372,   692, -1372,   709,
     167, -1372, -1372,   481, -1372,   103, -1372,    31,   724, -1372,
   -1372,    14, -1372, -1372, -1372, -1372,   -29, -1372, -1372, -1372,
     -76, -1372, -1372, -1372,   -61, -1372, -1372, -1372,    65, -1372,
      79,   816, -1372,   770,   463, -1372, -1372, -1372,   698,   696,
   -1372, -1372, -1372, -1372,   627,   283,   700, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   819, -1372,   607,   797, -1372,
     629, -1372, -1372,   823,   656, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   827, -1372, -1372, -1372,   830, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   637,   356, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   831, -1372,
   -1372, -1372, -1372,   639,   283,   706, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   809, -1372,   646,
   -1372, -1372,   832,   632, -1372, -1372, -1372, -1372, -1372, -1372,
     664,   660,   805,   728,   691,   694, -1372, -1372,   842,   843,
     844, -1372, -1372, -1372, -1372,   675,   720, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   648, -1372,   845,   638, -1372,
   -1372, -1372, -1372, -1372, -1372,   649,   641,   818, -1372, -1372,
   -1372,   674,   805, -1372,   693, -1372, -1372, -1372, -1372,   850,
     851,   852, -1372, -1372,   856, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,   651,   644,   825, -1372, -1372, -1372,   683,   818,
   -1372,   695, -1372, -1372,   668,   697,   699, -1372,   862,   533,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   491, -1372,
   -1372, -1372,   687,   825, -1372,   705, -1372, -1372, -1372,   707,
     712, -1372,   863,   516, -1372, -1372, -1372, -1372, -1372,   670,
     805,   688, -1372, -1372, -1372, -1372,   137, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   701,   702, -1372, -1372, -1372, -1372,
   -1372, -1372,   360, -1372, -1372,   716,   718, -1372,   866,   517,
   -1372, -1372, -1372, -1372,   745,   690, -1372, -1372, -1372, -1372,
     116, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   669,   667,
   -1372, -1372, -1372, -1372,   849,   725, -1372, -1372,   703,   704,
     840, -1372, -1372,   708,   710, -1372, -1372, -1372, -1372, -1372,
     727,   192,   879,   880, -1372, -1372, -1372,   881, -1372,   729,
     360, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   757,   711,
   -1372, -1372, -1372, -1372,   155, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,   672,   677, -1372, -1372, -1372, -1372, -1372, -1372,
     713,   717,   840, -1372, -1372,   679,   676, -1372, -1372, -1372,
   -1372, -1372,   731,   192,   763,   887,   733,  -121, -1372, -1372,
   -1372, -1372, -1372, -1372,   714,   840, -1372,   736, -1372, -1372,
   -1372,   738,   192,   719, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   890,   894, -1372,   125, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   721,   722,   840,
   -1372, -1372,   682,   715, -1372, -1372, -1372, -1372, -1372,   740,
     192,   742,   313, -1372, -1372,   723,   840,   744, -1372, -1372,
   -1372,   746,   435,   726, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   901,   556, -1372, -1372, -1372, -1372, -1372,
   -1372,   730,   735, -1372, -1372, -1372,   732,   840,   750, -1372,
     903,   689, -1372, -1372, -1372, -1372,   737, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   909, -1372, -1372, -1372, -1372, -1372,
   -1372,   913, -1372,   734,    -4, -1372, -1372, -1372, -1372,   752,
     564, -1372, -1372,   739,   840,   754, -1372, -1372, -1372,   756,
     190,   741, -1372, -1372, -1372, -1372, -1372, -1372,   -95, -1372,
   -1372, -1372, -1372, -1372,   916, -1372,   918, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,   743,   840,   758, -1372,
     689, -1372, -1372, -1372, -1372,   747, -1372, -1372, -1372, -1372,
     919,   921, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   760,   253,   917, -1372, -1372,   570,
   -1372, -1372, -1372, -1372,   764,   192, -1372,   751,   840,   766,
   -1372,   689, -1372, -1372, -1372, -1372, -1372,   748,   749, -1372,
     753, -1372, -1372, -1372, -1372, -1372,   755, -1372, -1372,   -92,
   -1372, -1372, -1372, -1372,   924, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,   759,   840,   768, -1372,   689, -1372, -1372, -1372, -1372,
     761, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,   799,   762, -1372, -1372,   765, -1372, -1372,   922,
     923,   925, -1372,   767,   840,   772, -1372,   689, -1372, -1372,
   -1372, -1372,   769, -1372, -1372, -1372, -1372,   -83, -1372, -1372,
   -1372, -1372,   934, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,   774,    72,   771, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,   773,   840,   776, -1372,   689, -1372, -1372, -1372, -1372,
     775, -1372, -1372, -1372,   778, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   811,   777, -1372, -1372,   765,   930, -1372,
     779,   840,   780, -1372,   689, -1372, -1372, -1372, -1372,   781,
   -1372, -1372,   448,   448, -1372, -1372,   782,   382, -1372,   784,
     135, -1372, -1372, -1372, -1372,   785,   840,   786, -1372,   689,
   -1372, -1372, -1372, -1372,   783, -1372, -1372, -1372, -1372, -1372,
   -1372,   815,   789, -1372, -1372,   765,   931,  -126, -1372, -1372,
   -1372, -1372,   932, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   790,   840,   788, -1372,   689, -1372, -1372,
   -1372, -1372,   787, -1372, -1372,   936,     9, -1372, -1372, -1372,
   -1372,   937,   567, -1372, -1372,   792,   382, -1372, -1372,   793,
     840,   794, -1372,   689, -1372, -1372, -1372, -1372,   795, -1372,
   -1372, -1372, -1372,   791, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   689, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   801,   840,   796, -1372,   689, -1372,
   -1372, -1372, -1372,   807, -1372, -1372, -1372, -1372,   798,   382,
   -1372, -1372,  -122,   448,   942, -1372, -1372,   840,   800, -1372,
     689, -1372, -1372, -1372, -1372,   813, -1372, -1372, -1372,   814,
   -1372,   943, -1372, -1372, -1372, -1372, -1372, -1372,   803, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   817,
     840,   802, -1372,   689, -1372, -1372, -1372, -1372,   820, -1372,
   -1372, -1372, -1372, -1372,   821, -1372, -1372, -1372,   840,   804,
   -1372,   689, -1372, -1372, -1372, -1372,   824, -1372, -1372,   822,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
     944, -1372,   806, -1372,   689, -1372, -1372, -1372, -1372,   826,
   -1372, -1372, -1372, -1372,   828,   947,   948, -1372, -1372, -1372,
     840,   808, -1372,   689, -1372, -1372, -1372, -1372,   833, -1372,
   -1372, -1372,   810, -1372,   689, -1372, -1372, -1372, -1372,   834,
   -1372, -1372, -1372, -1372, -1372,   689, -1372, -1372, -1372, -1372,
     829, -1372, -1372, -1372, -1372, -1372,   812, -1372,   689, -1372,
   -1372, -1372, -1372,   835, -1372, -1372,   689, -1372, -1372, -1372,
   -1372,   846, -1372, -1372,   838, -1372, -1372, -1372, -1372,   689,
   -1372, -1372, -1372, -1372,   847, -1372, -1372,   839, -1372, -1372,
   -1372,   841, -1372, -1372, -1372, -1372
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   883, -1372,
     938, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   857,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,   555, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   853, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
     485, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   836, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   395, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,   658, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,   352, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,   329, -1372, -1372, -1372, -1372, -1372, -1372, -1372,   342,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,   330, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   338, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   333, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,   324, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   111, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,    66,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,  -424, -1083, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372,  -205, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
    -416, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372,    88, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,    15, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,  -284,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372,    34, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,   -43, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,  -362, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,    68, -1372, -1372, -1372,
   -1372, -1372,  -111, -1372, -1372, -1372, -1372,  -452,  -464,  -486,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1046, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,  -154, -1372, -1372, -1372,
   -1089, -1372, -1372, -1372, -1372, -1372,  -997, -1372, -1372, -1371,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372,  -485, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1044, -1372, -1372, -1372, -1372,
   -1372, -1372, -1043, -1372, -1372, -1372, -1369, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,  -191, -1372, -1372, -1372,  -484, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372,  -842, -1372,  -978, -1078,
   -1372, -1372,  -817, -1372, -1372, -1372,  -142, -1372,  -128,   -62,
   -1372, -1372,  -797, -1372, -1199, -1276, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372,  -360,  -372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372,   960, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1172, -1372, -1372, -1372,
   -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372, -1372,
   -1372
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     473,   243,   470,   598,   602,   837,  1077,   472,  1313,  1213,
     397,   897,   861,  1539,  1068,   248,  1159,   501,  1170,  1171,
    1398,   276,   464,   465,   484,  1110,  1489,   456,  1491,   393,
     270,   267,   264,   252,   273,  1289,   249,  1099,  1371,   255,
    1377,  1253,   493,   494,   495,   384,   366,  1419,   371,  1361,
     639,   648,  1259,  1089,   222,   139,   652,  1089,  1089,   623,
     623,   656,   140,  1145,   633,   639,   141,   649,   142,   635,
     143,  1136,   144,   926,   637,  1193,     6,   639,  1521,  1090,
     653,   357,  1599,   365,  1247,   370,  1255,  1256,  1179,   351,
     624,   705,   639,  1390,   721,  1554,  1420,  1556,  1432,   223,
     658,  1398,   140,   681,   682,   660,   141,   723,   142,   803,
     143,   224,   144,   639,  1290,  1433,  1327,   240,  1425,  1220,
     354,   639,     7,   424,   639,  1372,   645,  1336,    12,   241,
    1291,   629,   640,  1291,   355,  1415,   620,   719,   636,   253,
     250,   277,  1291,  1278,   265,   268,   271,   256,  1595,  1398,
    1597,   394,   274,     1,     2,   385,  1264,   502,   617,  1325,
     648,  1329,  1330,   457,   652,   223,   710,   639,   656,   710,
      17,   710,    86,   710,    14,  1016,    30,   224,   715,   593,
      78,   240,   629,  1453,   354,   240,   123,   629,   124,   713,
     740,   741,   634,   241,   710,   595,   710,   241,   355,  1306,
     455,    87,   442,    88,   444,    89,   446,    90,   294,    91,
     125,    92,  1479,    93,   629,    94,   629,    95,  1347,    96,
     629,    97,   126,  1120,  1121,   657,  1122,   725,   127,   659,
     629,   592,  1026,   592,  1026,   131,   593,  1514,   693,   726,
    1354,  1540,   699,   700,   701,  1174,   594,   128,   594,   781,
     782,   295,   595,   158,   629,  1273,  1274,  1275,  1276,   712,
     435,   175,   436,   628,   437,   296,   629,   297,   203,   298,
    1153,   299,   206,   300,   448,  1536,   450,   942,   943,   301,
     210,   302,   209,   303,  1383,   304,   212,   305,  1258,   306,
     803,   307,   211,   308,   592,   309,   214,   593,   232,   240,
     258,  1569,  1154,  1155,    20,    21,  1322,  1323,   945,   594,
     946,   241,   743,   595,   213,   709,   931,   752,   629,   932,
     279,  1575,   947,   948,   592,   993,  1408,   593,   994,   240,
    1153,   414,   415,   416,   597,   352,  1587,   942,   943,   594,
     343,   241,   362,   595,   367,   398,   399,   400,   401,  1119,
     372,   830,  1120,  1121,   592,  1122,   373,   593,  1610,   240,
      25,    26,  1154,  1155,  1156,  1157,   403,   404,   945,   594,
     946,   241,  1050,   595,  1446,  1051,   787,   768,   769,   770,
      33,    34,   947,   948,   942,   943,   798,    81,    82,   134,
     135,  1629,   380,   160,   161,   381,   944,   165,   166,   382,
    1488,   592,   383,  1472,   593,   387,   240,   392,  1337,  1640,
     170,   171,   814,   178,   179,   945,   594,   946,   241,   389,
     595,   825,  1500,   592,  1026,   388,   593,   390,  1507,   947,
     948,   838,  1651,   391,   680,   183,   184,   396,   594,  1213,
     188,   189,   595,  1188,  1189,  1190,  1191,   421,   849,   193,
     194,  1664,   198,   199,   464,   465,  1031,  1032,   862,   217,
     218,   430,  1672,   259,   260,   433,  1529,   280,   281,  1553,
     287,   288,   438,  1675,   451,   888,   592,  1026,   345,   346,
     375,   376,   898,   409,   410,   468,  1685,   425,   426,   459,
     460,   594,  1562,   483,  1688,   474,  1188,  1189,  1190,  1191,
     476,   477,   496,   497,   505,   506,   482,  1692,   485,   937,
     511,   512,   295,   516,   517,   521,   522,   404,  1078,  1079,
     489,   739,  1594,   526,   527,   582,   296,  1580,   297,   504,
     298,   510,   299,   573,   300,   532,   533,  1111,  1112,   531,
     301,   580,   302,   999,   303,  1440,   304,   562,   305,  1603,
     306,    87,   307,    88,   308,    89,   309,    90,   581,    91,
     583,    92,   585,    93,   584,    94,   477,    95,   610,    96,
     606,    97,  1035,   537,   538,  1146,  1147,  1165,  1172,   607,
     780,  1153,  1622,   542,   543,   547,   548,  1198,   942,   943,
     552,   553,   557,   558,   563,   564,   568,   569,   589,   590,
    1633,   632,   629,   854,   614,   592,   615,  1056,   593,   616,
     240,  1244,  1245,  1154,  1155,   574,   575,   662,   663,   945,
     594,   946,   241,   672,   595,   666,   667,   676,   677,   694,
     695,   711,   629,   947,   948,   729,   663,   735,   736,   753,
     754,   622,  1657,   621,  1100,  1254,  1257,   765,   766,   776,
     777,   627,    38,   638,  1114,  1283,   788,   789,   815,   816,
     661,  1115,   683,    39,  1118,    40,    41,    42,   684,    43,
      44,    45,   575,    46,    47,    48,   685,    49,    50,    51,
     686,    52,    53,    39,   689,    40,    41,    42,   702,    43,
      44,    45,   703,    46,    47,    48,   704,    49,    50,    51,
     707,    52,    53,   839,   840,   863,   864,   871,   872,   876,
     877,   882,   883,   889,   890,   899,   900,   905,   906,   708,
    1328,  1331,   910,   911,   916,   917,   969,   970,   974,   975,
    1348,  1349,   714,   980,   981,  1007,  1008,  1023,  1024,  1037,
    1038,  1073,  1074,  1084,  1085,  1234,  1101,  1102,  1106,  1107,
    1141,  1142,  1148,  1149,  1180,  1181,  1185,  1186,  1207,  1208,
    1221,  1222,  1239,  1240,  1265,  1266,  1270,  1271,  1307,  1308,
    1317,  1318,  1339,  1208,  1343,  1344,  1355,  1356,  1384,  1385,
     728,  1299,  1409,  1410,  1427,  1428,  1447,  1448,  1456,  1457,
    1473,  1474,  1483,  1484,  1493,  1494,  1508,  1509,  1530,  1531,
    1543,  1544,  1548,  1549,  1563,  1564,  1581,  1582,  1589,  1590,
    1604,  1605,  1623,  1624,  1634,  1635,  1645,  1646,  1658,  1659,
    1666,  1667,  1679,  1680,   727,   667,   731,   744,   745,   758,
     742,   763,   748,   759,   764,   775,   783,   784,   793,   794,
     799,   800,   803,   807,   806,   809,   810,   811,   808,   812,
     813,   820,   827,   821,  1362,   826,   830,   833,   844,   845,
     846,  1369,   847,   851,   854,   850,   857,   868,   881,   915,
     893,   922,   979,   927,   986,   989,   917,  1000,  1005,   938,
    1016,   883,  1033,  1034,  1036,   993,  1043,  1012,  1057,   931,
    1019,  1069,  1080,  1013,   981,  1083,  1046,  1063,  1116,  1113,
    1117,  1095,  1137,  1392,  1393,  1131,  1064,  1206,  1160,  1226,
    1175,  1132,  1490,  1492,  1089,  1233,  1499,  1232,  1235,  1300,
    1227,  1301,  1315,  1216,  1316,  1338,  1260,  1378,  1401,  1394,
    1212,  1402,  1050,  1403,  1302,  1365,  1203,  1426,  1467,  1520,
    1523,  1463,  1538,  1417,  1418,  1516,  1350,  1541,  1601,  1614,
    1379,  1441,  1643,  1654,  1655,  1416,   159,  1314,  1237,  1288,
     130,   486,  1404,    77,   586,  1454,  1442,  1480,  1420,   422,
     716,  1290,   673,  1515,  1468,  1537,  1252,   706,  1503,  1391,
     722,  1555,  1557,  1363,  1370,  1570,  1558,  1525,   720,  1366,
    1291,  1455,   724,   732,  1372,  1588,   939,   730,  1576,   233,
    1020,  1573,  1642,  1522,  1340,  1611,  1517,  1001,  1630,  1395,
    1138,  1070,  1464,  1238,  1618,   129,  1641,  1058,  1042,     0,
       0,  1617,  1652,  1676,     0,  1665,     0,     0,     0,  1502,
    1673,  1686,  1481,  1482,  1596,  1598,  1690,  1694,     0,  1695,
    1689,  1693,     0,     0,     0,     0,  1613,  1631,     0,     0,
       0,  1326,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1524,   344,     0,     0,  1653,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1571,
    1572,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1600,     0,     0,  1612,     0,     0,     0,
       0,  1615,  1616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1644,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1498,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1677,  1678
};

static const yytype_int16 yycheck[] =
{
     372,   155,   362,   488,   488,   802,  1003,   367,  1180,  1092,
       8,   853,   829,     4,   992,   157,  1062,     4,  1062,  1062,
    1296,     4,     6,     7,   396,  1022,  1397,     4,  1397,     4,
       4,     4,     4,     4,     4,   130,     4,  1015,   130,     4,
    1239,  1130,   414,   415,   416,     4,   237,   130,   239,  1221,
     153,   537,  1130,   179,    82,    80,   542,   179,   179,   115,
     115,   547,   127,  1060,   516,   153,   131,   170,   133,   521,
     135,  1049,   137,   870,   526,  1072,     0,   153,   204,   200,
     168,   235,   204,   237,  1130,   239,  1130,  1130,  1066,   231,
     146,   146,   153,  1265,   170,  1466,   179,  1466,    26,   127,
     552,  1377,   127,   588,   588,   557,   131,   168,   133,    37,
     135,   139,   137,   153,   209,    43,  1205,    46,  1317,  1097,
      45,   153,    75,   314,   153,   217,   166,  1205,    14,    58,
     225,   151,   164,   225,    59,  1307,   496,   166,   158,   110,
     108,   124,   225,  1140,   116,   118,   120,   112,  1519,  1425,
    1519,   126,   122,    12,    13,   114,  1134,   144,   142,  1205,
     646,  1205,  1205,   140,   650,   127,   630,   153,   654,   633,
      77,   635,    78,   637,    15,    40,    79,   139,   164,    44,
      81,    46,   151,  1355,    45,    46,     5,   151,     5,   158,
     675,   675,   156,    58,   658,    60,   660,    58,    59,  1177,
     342,   107,   330,   109,   332,   111,   334,   113,    84,   115,
       5,   117,  1384,   119,   151,   121,   151,   123,  1215,   125,
     151,   127,     5,   227,   228,   162,   230,   162,     5,   160,
     151,    41,    42,    41,    42,    83,    44,  1409,   610,   160,
    1218,   232,   614,   615,   616,  1062,    56,    76,    56,   734,
     734,   127,    60,    78,   151,    65,    66,    67,    68,   156,
     322,    74,   324,   148,   326,   141,   151,   143,    73,   145,
      17,   147,    16,   149,   336,  1447,   338,    24,    25,   155,
      92,   157,    88,   159,  1262,   161,   100,   163,  1130,   165,
      37,   167,    96,   169,    41,   171,    85,    44,    80,    46,
       3,  1473,    49,    50,    10,    11,    53,    54,    55,    56,
      57,    58,   684,    60,   104,   148,   179,   689,   151,   182,
       3,  1493,    69,    70,    41,   209,  1304,    44,   212,    46,
      17,    30,    31,    32,   488,    10,  1508,    24,    25,    56,
      82,    58,    10,    60,    10,   343,   344,   345,   346,   224,
       3,    38,   227,   228,    41,   230,    10,    44,  1530,    46,
      10,    11,    49,    50,    51,    52,   128,   129,    55,    56,
      57,    58,   217,    60,  1352,   220,   748,    21,    22,    23,
      10,    11,    69,    70,    24,    25,   758,    10,    11,    10,
      11,  1563,   108,    10,    11,   110,    36,    10,    11,   112,
    1397,    41,     8,  1381,    44,   116,    46,     8,  1205,  1581,
      10,    11,   784,    10,    11,    55,    56,    57,    58,   120,
      60,   793,  1400,    41,    42,   118,    44,   122,  1406,    69,
      70,   803,  1604,   124,   588,    10,    11,     6,    56,  1522,
      10,    11,    60,    61,    62,    63,    64,    84,   820,    10,
      11,  1623,    10,    11,     6,     7,   941,   941,   830,    10,
      11,    18,  1634,    10,    11,    19,  1444,    10,    11,  1466,
      10,    11,    20,  1645,    27,   847,    41,    42,    10,    11,
      10,    11,   854,    10,    11,     3,  1658,    10,    11,    10,
      11,    56,  1470,   126,  1666,     6,    61,    62,    63,    64,
     128,   129,    10,    11,    10,    11,   114,  1679,   128,   881,
      10,    11,   127,    10,    11,    10,    11,   129,  1003,  1003,
     175,   675,  1519,    10,    11,   134,   141,  1505,   143,     8,
     145,     8,   147,   140,   149,    10,    11,  1022,  1022,     8,
     155,   132,   157,   915,   159,  1342,   161,     8,   163,  1527,
     165,   107,   167,   109,   169,   111,   171,   113,     8,   115,
     136,   117,   128,   119,   138,   121,   129,   123,    33,   125,
      86,   127,   944,    10,    11,  1060,  1060,  1062,  1062,   205,
     734,    17,  1560,    10,    11,    10,    11,  1072,    24,    25,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
    1578,   150,   151,    39,     6,    41,     6,   979,    44,     6,
      46,    47,    48,    49,    50,   128,   129,   172,   173,    55,
      56,    57,    58,   128,    60,   128,   129,    10,    11,    10,
      11,   150,   151,    69,    70,   172,   173,    10,    11,    10,
      11,     6,  1620,   144,  1016,  1130,  1130,    10,    11,    10,
      11,     6,    76,     6,  1026,  1140,    10,    11,    10,    11,
       6,  1033,   130,    87,  1036,    89,    90,    91,     3,    93,
      94,    95,   129,    97,    98,    99,     3,   101,   102,   103,
     213,   105,   106,    87,    34,    89,    90,    91,   142,    93,
      94,    95,     8,    97,    98,    99,    10,   101,   102,   103,
       8,   105,   106,    10,    11,    10,    11,    10,    11,    10,
      11,   178,   179,   222,   223,    10,    11,    10,    11,    10,
    1205,  1205,    10,    11,   208,   209,    10,    11,    10,    11,
    1215,  1215,     8,   216,   217,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,  1117,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,   202,   203,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,   202,   203,    10,    11,    10,    11,    10,    11,
      10,  1153,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     233,   234,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,     8,   129,   128,     8,   221,     6,
     130,     4,    35,   177,     4,     4,   130,    28,     6,   207,
     176,   181,    37,   152,   116,     3,     3,     3,   154,   174,
     130,     6,   211,   215,  1226,   206,    38,   183,     8,     8,
       8,  1233,     6,   219,    39,   214,   183,   199,     6,     6,
     183,   201,     6,   185,   129,   185,   209,   208,    29,   178,
      40,   179,     3,     3,     3,   209,   129,   184,   216,   179,
     182,   212,   129,   189,   217,     8,   185,   184,     8,   180,
       6,   187,   220,  1275,  1276,   184,   189,     6,  1062,     6,
     187,   189,  1397,  1397,   179,     6,  1400,   180,     5,     3,
     231,     3,     3,   191,     3,     8,   187,     3,     6,   130,
     200,     8,   217,     8,   191,   186,   210,     3,     8,     8,
       8,   130,     6,  1315,  1316,   130,   195,    10,     6,     6,
     191,   180,     8,     6,     6,   186,    99,   210,   224,   218,
      77,   406,   195,    25,   479,   190,   193,   186,   179,   311,
     641,   209,   577,   190,   195,   188,  1130,   625,   193,   218,
     650,  1466,  1466,   235,   229,   190,   193,   197,   646,   236,
     225,  1363,   654,   669,   217,   188,   885,   664,   197,   146,
     934,   210,   180,  1427,  1209,   192,  1422,   919,   188,  1293,
    1053,   996,  1374,  1124,   197,    55,   192,   983,   950,    -1,
      -1,   218,   196,   194,    -1,   192,    -1,    -1,    -1,  1401,
     196,   196,  1392,  1393,  1519,  1519,   198,   198,    -1,   198,
     194,   194,    -1,    -1,    -1,    -1,   232,   226,    -1,    -1,
      -1,  1205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1433,   226,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1481,
    1482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1523,    -1,    -1,  1538,    -1,    -1,    -1,
      -1,  1543,  1544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1601,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1400,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1654,  1655
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   348,   349,   350,     0,    75,   357,   358,
    1135,  1136,    14,   351,    15,   355,   356,    77,   359,   360,
      10,    11,  1137,  1138,  1139,    10,    11,   352,   353,   354,
      79,   445,   446,    10,    11,   361,   362,   363,    76,    87,
      89,    90,    91,    93,    94,    95,    97,    98,    99,   101,
     102,   103,   105,   106,  1140,  1141,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,   357,    81,   493,
     494,    10,    11,   447,   448,   449,    78,   107,   109,   111,
     113,   115,   117,   119,   121,   123,   125,   127,   364,   365,
     366,   367,   368,   373,   374,   379,   380,   385,   386,   393,
     394,   399,   400,   405,   406,   411,   412,   417,   418,   423,
     424,   431,   432,     5,     5,     5,     5,     5,    76,  1142,
     355,    83,   521,   522,    10,    11,   495,   496,   497,    80,
     127,   131,   133,   135,   137,   450,   451,   452,   453,   454,
     460,   461,   467,   468,   474,   475,   479,   480,    78,   366,
      10,    11,   369,   370,   371,    10,    11,   375,   376,   377,
      10,    11,   381,   382,   383,    74,   387,   388,    10,    11,
     395,   396,   397,    10,    11,   401,   402,   403,    10,    11,
     407,   408,   409,    10,    11,   413,   414,   415,    10,    11,
     419,   420,   421,    73,   425,   426,    16,   433,  1113,    88,
      92,    96,   100,   104,    85,   637,   638,    10,    11,   523,
     524,   525,    82,   127,   139,   498,   499,   500,   501,   502,
     507,   508,    80,   452,   455,   456,   462,   463,   469,   470,
      46,    58,   476,  1043,  1044,  1045,  1046,   481,  1113,     4,
     108,   372,     4,   110,   378,     4,   112,   384,     3,    10,
      11,   389,   390,   391,     4,   116,   398,     4,   118,   404,
       4,   120,   410,     4,   122,   416,     4,   124,   422,     3,
      10,    11,   427,   428,   429,  1132,  1133,    10,    11,   434,
     435,   436,   639,   640,    84,   127,   141,   143,   145,   147,
     149,   155,   157,   159,   161,   163,   165,   167,   169,   171,
     526,   527,   528,   529,   530,   537,   538,   543,   544,   551,
     552,   556,   557,   561,   562,   566,   567,   571,   572,   579,
     580,   587,   588,   595,   596,   603,   604,   609,   610,   615,
     616,   623,   624,    82,   500,    10,    11,   503,   504,   505,
     509,  1113,    10,   458,    45,    59,   457,  1043,  1091,  1092,
    1093,  1094,    10,   465,   464,  1043,  1091,    10,   472,   471,
    1043,  1091,     3,    10,   477,    10,    11,   482,   483,   484,
     108,   110,   112,     8,     4,   114,   392,   116,   118,   120,
     122,   124,     8,     4,   126,   430,     6,     8,   343,   344,
     345,   346,  1134,   128,   129,   437,   438,   439,   440,    10,
      11,   642,   643,   644,    30,    31,    32,   641,  1104,  1110,
    1120,    84,   528,   531,  1091,    10,    11,   539,   540,   541,
      18,   545,  1108,    19,  1116,  1116,  1116,  1116,    20,   573,
    1115,   581,  1115,   589,  1115,   597,  1115,   605,  1116,   611,
    1116,    27,   617,  1117,   625,  1113,     4,   140,   506,    10,
      11,   510,   511,   512,     6,     7,   459,  1131,     3,   466,
    1131,   473,  1131,  1132,     6,   478,   128,   129,   485,   486,
     487,   488,   114,   126,  1132,   128,   439,   441,   442,   175,
     645,   646,   647,  1132,  1132,  1132,    10,    11,   532,   533,
     534,     4,   144,   542,     8,    10,    11,   546,   547,   548,
       8,    10,    11,   553,   554,   555,    10,    11,   558,   559,
     560,    10,    11,   563,   564,   565,    10,    11,   568,   569,
     570,     8,    10,    11,   574,   575,   576,    10,    11,   582,
     583,   584,    10,    11,   590,   591,   592,    10,    11,   598,
     599,   600,    10,    11,   606,   607,   608,    10,    11,   612,
     613,   614,     8,    10,    11,   618,   619,   620,    10,    11,
     626,   627,   628,   140,   128,   129,   513,   514,   515,   516,
     132,     8,   134,   136,   138,   128,   487,   489,   490,    10,
      11,   444,    41,    44,    56,    60,   443,  1043,  1064,  1065,
    1066,  1067,  1095,  1096,  1097,  1098,    86,   205,   784,   785,
      33,   648,   649,  1114,     6,     6,     6,   142,   535,   536,
    1131,   144,     6,   115,   146,   549,   550,     6,   148,   151,
    1024,  1025,   150,  1024,   156,  1024,   158,  1024,     6,   153,
     164,   577,   578,  1026,  1027,   166,   585,   586,  1026,   170,
     593,   594,  1026,   168,   601,   602,  1026,   162,  1024,   160,
    1024,     6,   172,   173,   621,   622,   128,   129,   629,   630,
     631,   632,   128,   515,   517,   518,    10,    11,   492,   491,
    1043,  1064,  1095,   130,     3,     3,   213,   893,   894,    34,
     786,   787,  1112,  1132,    10,    11,   650,   651,   652,  1132,
    1132,  1132,   142,     8,    10,   146,   550,     8,    10,   148,
    1025,   150,   156,   158,     8,   164,   578,  1028,  1029,   166,
     586,   170,   594,   168,   602,   162,   160,     8,    10,   172,
     622,   128,   631,   633,   634,    10,    11,   520,   519,  1043,
    1064,  1095,   130,  1132,     8,   221,  1002,  1003,    35,   895,
     896,  1111,  1132,    10,    11,   788,   789,   790,     6,   177,
     653,   654,   655,     4,     4,    10,    11,  1034,    21,    22,
      23,  1030,  1031,  1032,  1033,     4,    10,    11,   636,   635,
    1043,  1064,  1095,   130,    28,  1004,  1118,  1132,    10,    11,
     897,   898,   899,     6,   207,   791,   792,   793,  1132,   176,
     181,   668,   669,    37,   656,  1119,   116,   152,   154,     3,
       3,     3,   174,   130,  1132,    10,    11,  1005,  1006,  1007,
       6,   215,   900,   901,   902,  1132,   206,   211,   806,   807,
      38,   794,  1109,   183,   682,   683,   670,  1119,  1132,    10,
      11,   657,   658,   659,     8,     8,     8,     6,  1008,  1132,
     214,   219,   915,   916,    39,   903,  1103,   183,   820,   821,
     808,  1109,  1132,    10,    11,   795,   796,   797,   199,   737,
     738,    10,    11,   684,   685,   686,    10,    11,   671,   672,
     673,     6,   178,   179,   660,   661,   662,   663,  1132,   222,
     223,  1009,  1010,   183,   929,   930,   917,  1103,  1132,    10,
      11,   904,   905,   906,   875,    10,    11,   822,   823,   824,
      10,    11,   809,   810,   811,     6,   208,   209,   798,   799,
     800,   801,   201,   751,   752,   739,  1119,   185,   687,   688,
     689,   179,   182,   674,   675,   676,   677,  1132,   178,   662,
     664,   665,    24,    25,    36,    55,    57,    69,    70,  1011,
    1012,  1013,  1035,  1036,  1037,  1038,  1043,  1064,  1072,  1073,
    1074,  1075,  1079,  1080,  1081,  1082,  1095,  1107,   984,    10,
      11,   931,   932,   933,    10,    11,   918,   919,   920,     6,
     216,   217,   907,   908,   909,   910,   129,   876,   877,   185,
     825,   826,   827,   209,   212,   812,   813,   814,   815,  1132,
     208,   800,   802,   803,   766,    29,   753,    10,    11,   740,
     741,   742,   184,   189,   695,   696,    40,   690,  1105,   182,
     676,   678,   679,    10,    11,   667,    42,   666,  1053,  1054,
    1055,  1064,  1095,     3,     3,  1132,     3,    10,    11,  1014,
    1015,  1016,  1013,   129,   985,   986,   185,   934,   935,   936,
     217,   220,   921,   922,   923,   924,  1132,   216,   909,   911,
     912,   878,   879,   184,   189,   833,   834,   828,  1105,   212,
     814,   816,   817,    10,    11,   805,   804,  1053,  1064,  1095,
     129,   767,   768,     8,    10,    11,   754,   755,   756,   179,
     200,   743,   744,   745,   746,   187,   702,   703,   697,  1105,
    1132,    10,    11,   691,   692,   693,    10,    11,   681,   680,
    1053,  1064,  1095,   180,  1132,  1132,     8,     6,  1132,   224,
     227,   228,   230,  1017,  1018,  1019,  1020,  1021,  1022,   987,
     988,   184,   189,   942,   943,   937,  1105,   220,   923,   925,
     926,    10,    11,   914,   913,  1053,  1064,  1095,    10,    11,
     881,   882,   883,    17,    49,    50,    51,    52,   880,  1035,
    1043,  1047,  1048,  1049,  1050,  1064,  1068,  1069,  1070,  1071,
    1072,  1079,  1095,  1106,  1109,   187,   840,   841,   835,  1105,
      10,    11,   829,   830,   831,    10,    11,   819,    61,    62,
      63,    64,   818,  1053,  1056,  1057,  1058,  1059,  1064,  1083,
    1084,  1085,  1086,   210,   769,   770,     6,   202,   203,   757,
     758,   759,   200,   745,   747,   748,   191,   709,   710,   704,
    1105,    10,    11,   698,   699,   700,     6,   231,   694,  1163,
    1164,  1171,   180,     6,  1132,     5,  1023,   224,  1019,    10,
      11,   990,   991,   992,    47,    48,   989,  1035,  1039,  1040,
    1041,  1042,  1043,  1047,  1064,  1072,  1079,  1095,  1103,  1106,
     187,   949,   950,   944,  1105,    10,    11,   938,   939,   940,
      10,    11,   928,    65,    66,    67,    68,   927,  1053,  1060,
    1061,  1062,  1063,  1064,  1087,  1088,  1089,  1090,   218,   130,
     209,   225,   884,   885,   886,   887,  1121,  1122,  1123,  1132,
       3,     3,   191,   847,   848,   842,  1105,    10,    11,   836,
     837,   838,   832,  1163,   210,     3,     3,    10,    11,   772,
     773,   774,    53,    54,   771,  1035,  1043,  1047,  1064,  1072,
    1079,  1095,  1099,  1100,  1101,  1102,  1106,  1119,     8,   202,
     758,   760,   761,    10,    11,   750,   749,  1053,  1064,  1095,
     195,   716,   717,   711,  1105,    10,    11,   705,   706,   707,
     701,  1163,  1132,   235,  1172,   186,   236,  1165,  1166,  1132,
     229,   130,   217,   993,   994,   995,   996,  1121,     3,   191,
     956,   957,   951,  1105,    10,    11,   945,   946,   947,   941,
    1163,   218,  1132,  1132,   130,   886,   888,   889,  1122,  1124,
    1125,     6,     8,     8,   195,   854,   855,   849,  1105,    10,
      11,   843,   844,   845,   839,  1163,   186,  1132,  1132,   130,
     179,   775,   776,   777,   778,  1121,     3,    10,    11,   763,
     764,   765,    26,    43,   762,  1051,  1052,  1076,  1077,  1078,
    1119,   180,   193,   723,   724,   718,  1105,    10,    11,   712,
     713,   714,   708,  1163,   190,  1132,    10,    11,  1173,  1174,
    1175,  1167,  1168,   130,   995,   997,   998,     8,   195,   963,
     964,   958,  1105,    10,    11,   952,   953,   954,   948,  1163,
     186,  1131,  1131,    10,    11,   891,   892,   890,  1053,  1056,
    1064,  1083,  1095,    10,    11,  1127,  1128,  1129,  1043,  1095,
    1105,  1126,  1132,   193,   861,   862,   856,  1105,    10,    11,
     850,   851,   852,   846,  1163,   190,   130,   777,   779,   780,
       8,   204,   744,     8,  1132,   197,   730,   731,   725,  1105,
      10,    11,   719,   720,   721,   715,  1163,   188,     6,     4,
     232,    10,  1170,   233,   234,  1169,  1176,  1177,    10,    11,
    1000,  1001,   999,  1053,  1056,  1064,  1083,  1095,   193,   970,
     971,   965,  1105,    10,    11,   959,   960,   961,   955,  1163,
     190,  1132,  1132,   210,  1130,  1163,   197,   868,   869,   863,
    1105,    10,    11,   857,   858,   859,   853,  1163,   188,    10,
      11,   782,   783,   781,  1053,  1056,  1064,  1083,  1095,   204,
    1131,     6,   732,  1105,    10,    11,   726,   727,   728,   722,
    1163,   192,  1132,   232,     6,  1132,  1132,   218,   197,   977,
     978,   972,  1105,    10,    11,   966,   967,   968,   962,  1163,
     188,   226,   870,  1105,    10,    11,   864,   865,   866,   860,
    1163,   192,   180,     8,  1132,    10,    11,   733,   734,   735,
     729,  1163,   196,   237,     6,     6,   979,  1105,    10,    11,
     973,   974,   975,   969,  1163,   192,    10,    11,   871,   872,
     873,   867,  1163,   196,   736,  1163,   194,  1132,  1132,    10,
      11,   980,   981,   982,   976,  1163,   196,   874,  1163,   194,
     198,   983,  1163,   194,   198,   198
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
      yyerror (&yylloc, osoption, parserData, osglData, YY_("syntax error: cannot back up")); \
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
		  Type, Value, Location, osoption, parserData, osglData); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osoption);
  YYUSE (parserData);
  YYUSE (osglData);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osoption, parserData, osglData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osoption, parserData, osglData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osoption, parserData, osglData); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osoption, parserData, osglData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osoption);
  YYUSE (parserData);
  YYUSE (osglData);

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
int yyparse (OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData);
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
yyparse (OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData)
#else
int
yyparse (osoption, parserData, osglData)
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
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
            osolerror( NULL, osoption, parserData, osglData, parserData->parser_errors);
        }
    }
    break;

  case 14:

    { parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "unexpected end of file, expecting </osol>");}
    break;

  case 17:

    {
    if (!osoption->setHeader(osglData->fileName, osglData->source,
            osglData->description, osglData->fileCreator, osglData->licence) )     
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setHeader failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <serviceURI>");
    else
        parserData->serviceURIPresent = true;
    
}
    break;

  case 47:

    {
        if (osoption->setServiceURI((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceURI failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 49:

    {
        if (parserData->serviceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <serviceName>");
        parserData->serviceNamePresent = true;
    }
    break;

  case 55:

    {
        if (osoption->setServiceName((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceName failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 57:

    {    if (parserData->instanceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <instanceName>");
        parserData->instanceNamePresent = true;
    }
    break;

  case 63:

    {
        if (osoption->setInstanceName((yyvsp[(1) - (1)].sval)) == false) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setInstanceName failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 64:

    {
    if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setInstanceLocation failed");
    parserData->errorText = NULL;
}
    break;

  case 65:

    {
        if (parserData->instanceLocationPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <instanceLocation>");
        parserData->instanceLocationPresent = true;
        parserData->typeAttribute = "local";
    }
    break;

  case 67:

    {   
        if (verifyLocationType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "instance location type not recognized");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <jobID>");
        parserData->jobIDPresent = true;
    }
    break;

  case 82:

    {
        if (osoption->setJobID((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setJobID failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 84:

    {
        if (parserData->solverToInvokePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <solverToInvoke>");
        parserData->solverToInvokePresent = true;
    }
    break;

  case 90:

    {
        if (osoption->setSolverToInvoke((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setSolverToInvoke failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 92:

    {
    if (parserData->licensePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <license>");
    parserData->licensePresent = true;    
}
    break;

  case 98:

    {
        if (osoption->setLicense((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setLicense failed");
        free((yyvsp[(1) - (1)].sval));
        parserData->errorText = NULL;
    }
    break;

  case 100:

    {    if (parserData->usernamePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <username>");
    parserData->usernamePresent = true;    
}
    break;

  case 106:

    {
        if (osoption->setUserName((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setUsername failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 108:

    {    if (parserData->passwordPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <password>");
    parserData->passwordPresent = true;    
}
    break;

  case 114:

    {
        if (osoption->setPassword((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setPassword failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 115:

    {
    if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setContact failed");
    parserData->errorText = NULL;
}
    break;

  case 116:

    {
    if (parserData->contactPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <contact>");
    parserData->contactPresent = true;
    parserData->typeAttribute = "osp";
    parserData->tempStr = "";
}
    break;

  case 118:

    {   
        if (verifyTransportType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "transport type not recognized");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <general> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
        parserData->otherGeneralOptionsPresent = true;
    }
    break;

  case 128:

    {
        if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other general options cannot be negative");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 129:

    {
        if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 130:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 137:

    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherGeneralOption failed");
    }
    break;

  case 138:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 142:

    {    if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one minDiskSpace element allowed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setMinDiskSpace failed");
    parserData->errorText = NULL;
}
    break;

  case 173:

    {    if (parserData->minMemoryPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one minMemory element allowed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setMinMemorySize failed");
    parserData->errorText = NULL;
}
    break;

  case 182:

    {    if (parserData->minCPUSpeedPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one minCPUSpeed element allowed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
}
    break;

  case 191:

    {    if (parserData->minCPUNumberPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one minCPUNumber element allowed");
        parserData->minCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 195:

    {
    if (osoption->setMinCPUNumber((yyvsp[(1) - (1)].ival), parserData->descriptionAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setMinCPUNumber failed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <system> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->otherSystemOptionsPresent = true;
}
    break;

  case 198:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other system options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 199:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 200:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 207:

    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherSystemOption failed");
    }
    break;

  case 208:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 212:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one currentState element allowed");
        parserData->serviceTypePresent = true;
    }
    break;

  case 237:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); 
        free((yyvsp[(1) - (1)].sval));
        if (osoption->setServiceType(parserData->tempStr) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceType failed; current system state not recognized");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <service> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherServiceOptionsPresent = true;
}
    break;

  case 240:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other service options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 241:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 242:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 249:

    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherServiceOption failed");
    }
    break;

  case 250:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 254:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "max time request could not be honored");
}
    break;

  case 286:

    {    
    if (parserData->maxTimePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <maxTime> element allowed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one requestedStartTime element allowed");
        parserData->requestedStartTimePresent = true;
    }
    break;

  case 303:

    {
        if (osoption->setRequestedStartTime((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setRequestedStartTime failed");    
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
        }
    break;

  case 304:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <job> <dependencies> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <dependencies> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->dependenciesPresent = true;
}
    break;

  case 311:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few job IDs in <dependencies> element");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many job IDs in <dependencies> element");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <requiredDirectories> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <requiredDirectories> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredDirectoriesPresent = true;
}
    break;

  case 321:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <requiredDirectories> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 322:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <requiredFiles> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <requiredFiles> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredFilesPresent = true;
}
    break;

  case 328:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <requiredFiles> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 329:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <directoriesToMake> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <directoriesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToMakePresent = true;
}
    break;

  case 335:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <directoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 336:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <filesToMake> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <filesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToMakePresent = true;
}
    break;

  case 342:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <filesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 343:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMove> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <inputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputDirectoriesToMovePresent = true;
}
    break;

  case 350:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <inputDirectoriesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 354:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputFilesToMove> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <inputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputFilesToMovePresent = true;
}
    break;

  case 361:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <inputFilesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 365:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <outputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputFilesToMovePresent = true;
}
    break;

  case 372:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <outputFilesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 376:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <outputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputDirectoriesToMovePresent = true;
}
    break;

  case 383:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <outputDirectoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 387:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <filesToDelete> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <filesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToDeletePresent = true;
}
    break;

  case 394:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <filesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 395:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <directoriesToDelete> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <directoriesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToDeletePresent = true;
}
    break;

  case 402:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <directoriesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 403:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <processesToKill> failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one <processesToKill> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->processesToKillPresent = true;
}
    break;

  case 410:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few process IDs in <processesToKill> element");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many process IDs in <processesToKill> element");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <job> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherJobOptionsPresent = true;
}
    break;

  case 416:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other job options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 417:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
    }
    break;

  case 418:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
    }
    break;

  case 425:

    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherJobOption failed");
    }
    break;

  case 426:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 430:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfVariables failed");
    }
    break;

  case 442:

    {
        parserData->numberOfConstraints = parserData->tempInt; 
        if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfConstraints failed");
    }
    break;

  case 443:

    {    
        parserData->numberOfObjectives = parserData->tempInt; 
        if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfObjectives failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValues>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 465:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValues>: fewer <var> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 477:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 483:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValuesString> failed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValuesString>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 487:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too few initial values in <initialVariableValuesString> element");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 499:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables basic failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 522:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atLower failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 531:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atUpper failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 540:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atEquality failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 549:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables isFree failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 558:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 567:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables unknown failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 576:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 580:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <var> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 592:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <sos> elements must be nonnegative");
    parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
}
    break;

  case 601:

    {
        if (parserData->numberOfSOS > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <sos> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 602:

    {    if (parserData->currentSOS != parserData->numberOfSOS)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <sos> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "error processing SOS branching weights");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many SOS branching weights");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index required");
    if (!parserData->numberOfVarAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar required");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherVariableOptions> than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set other variable option <var> element failed");
    parserData->kounter++;
}
    break;

  case 648:

    {
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialObjectiveValues> failed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 676:

    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: fewer <obj> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <obj> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 694:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjBounds(parserData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialObjectiveBounds> failed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 698:

    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be nonnegative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
    }
    break;

  case 713:

    {
        if (parserData->ubValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives basic failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 734:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atLower failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 743:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atUpper failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 752:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atEquality failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 761:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives isFree failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 770:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives superbasic failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 779:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives unknown failed");    
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherObjectiveOptions> than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set other objective option <obj> element failed");
    parserData->kounter++;
}
    break;

  case 814:

    {

    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <obj> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherConstraintOptions failed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: expected at least one <con element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 842:

    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: fewer <con> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 854:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 860:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitDualValues(parserData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: expected at least one <con> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 864:

    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: fewer <con> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 876:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks basic failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 900:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atLower failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 909:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atUpper failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 918:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atEquality failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 927:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks isFree failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 936:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");    
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
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 945:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks unknown failed");    
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherConstraintOptions> than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set other constraint option <con> element failed");
    parserData->kounter++;
}
    break;

  case 980:

    {
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfSolverOptions failed");
    parserData->iOption = 0;
}
    break;

  case 996:

    {
        if (parserData->numberOfSolverOptions > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <solverOption> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 997:

    {
        if (parserData->iOption != parserData->numberOfSolverOptions)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <solverOption> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "setSolverOptionContent failed");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "name attribute must be present");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <item> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 1015:

    {
        if (parserData->kounter < parserData->numberOfItems)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <item> elements than specified");
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <item> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <item> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many paths in <requiredDirectories> element");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many path pairs");
    else
    {
        if (!parserData->pathPairFromPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "\"from\" attribute must be present");
        if (!parserData->pathPairToPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "\"to\" attribute must be present");
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
//        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "too many path pairs");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"from\" attribute allowed");
    parserData->pathPairFromPresent = true;
    parserData->pathPairFrom = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1041:

    {
    if (parserData->pathPairToPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"to\" attribute allowed");
    parserData->pathPairToPresent = true;
    parserData->pathPairTo = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1042:

    {
    if (parserData->pathPairMakeCopyPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"makeCopy\" attribute allowed");
    parserData->pathPairMakeCopyPresent = true;
    parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1045:

    {   
    if (parserData->categoryAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one category attribute allowed for this element");
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one conType attribute allowed for this element");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one description attribute allowed for this element");
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one enumType attribute allowed for this element");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one groupWeight attribute allowed for this element");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one idx attribute allowed for this element");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one name attribute allowed for this element");
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one objType attribute allowed for this element");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one solver attribute allowed for this element");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one sosIdx attribute allowed for this element");
        parserData->sosIdxAttributePresent = true;
    }
    break;

  case 1097:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index must be nonnegative");
    parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1098:

    {   if (parserData->typeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one type attribute allowed for this element");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one unit attribute allowed for this element");
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one value attribute allowed for this element");
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
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one varType attribute allowed for this element");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfCon attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <con> cannot be negative");
    parserData->numberOfConAttributePresent = true;        
    parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1129:

    {
    if (parserData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfConstraints attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of constraints cannot be negative");
    parserData->numberOfConstraintsPresent = true;        
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1130:

    {
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;
    parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1131:

    {
    if (parserData->numberOfEnumerationsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEnumerations attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <enumeration> elements cannot be negative");
    parserData->numberOfEnumerationsAttributePresent = true;        
    parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1132:

    {    
   if (parserData->numberOfItemsPresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one numberOfItems attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1133:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
        parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1134:

    {
    if (parserData->numberOfObjAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObj attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <obj> cannot be negative");
    parserData->numberOfObjAttributePresent = true;        
    parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1135:

    {
    if (parserData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObjectives attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of objectives cannot be negative");
    parserData->numberOfObjectivesPresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1136:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other constraint options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1137:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other objective options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1138:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1139:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of other variable options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1140:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Number of path pairs cannot be negative");
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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Number of paths cannot be negative");
    else
        parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1142:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
        parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1143:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of solver options cannot be negative");
    parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1144:

    {
    if (parserData->numberOfVarAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <var> cannot be negative");
    parserData->numberOfVarAttributePresent = true;        
    parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1145:

    {    if (parserData->numberOfVariablesPresent)

        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVariables attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of variables cannot be negative");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "set <other> option enumeration failed");

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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more <enumeration> elements than specified");
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
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires numberOfEl attribute"); 
        if(!parserData->valueAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires value attribute"); 
    }
    break;

  case 1153:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfElPresent = true;
        osglData->osglNumberOfEl = parserData->numberOf;
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

  case 1186:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 1191:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1193:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 1198:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1200:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 1205:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1207:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 1212:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1214:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 1219:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1220:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1225:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 1231:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;    
}
    break;

  case 1233:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1238:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 data length does not match numberOfEl"); 
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

  case 1239:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1240:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1241:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1246:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    double *dblvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 data length does not match numberOfEl"); 
    else
    {
        dblvec = (double*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglDblArray[i] = *(dblvec++);
        }
    }
    //delete[] b64string;
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
      yyerror (&yylloc, osoption, parserData, osglData, YY_("syntax error"));
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
	    yyerror (&yylloc, osoption, parserData, osglData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osoption, parserData, osglData, YY_("syntax error"));
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
		      yytoken, &yylval, &yylloc, osoption, parserData, osglData);
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
		  yystos[yystate], yyvsp, yylsp, osoption, parserData, osglData);
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
  yyerror (&yylloc, osoption, parserData, osglData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osoption, parserData, osglData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osoption, parserData, osglData);
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

std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osolget_lineno( scanner) << ": "; 
    outStr << osolget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg

void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, std::string errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    throw ErrorClass( errormsg);
} //end osolerror

void  yygetOSOption(const char *parsestring, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData) throw(ErrorClass){
    try{
        osol_scan_string( parsestring, scanner);
        osolset_lineno (1 , scanner );
        //
        // call the Bison parser
        //
        if(  osolparse( osoption,  parserData, osglData) != 0) {
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


