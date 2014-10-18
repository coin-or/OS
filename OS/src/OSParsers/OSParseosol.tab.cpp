
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
     HEADERSTART = 471,
     HEADEREND = 472,
     FILENAMESTART = 473,
     FILENAMEEND = 474,
     FILENAMEEMPTY = 475,
     FILENAMESTARTANDEND = 476,
     FILESOURCESTART = 477,
     FILESOURCEEND = 478,
     FILESOURCEEMPTY = 479,
     FILESOURCESTARTANDEND = 480,
     FILEDESCRIPTIONSTART = 481,
     FILEDESCRIPTIONEND = 482,
     FILEDESCRIPTIONEMPTY = 483,
     FILEDESCRIPTIONSTARTANDEND = 484,
     FILECREATORSTART = 485,
     FILECREATOREND = 486,
     FILECREATOREMPTY = 487,
     FILECREATORSTARTANDEND = 488,
     FILELICENCESTART = 489,
     FILELICENCEEND = 490,
     FILELICENCEEMPTY = 491,
     FILELICENCESTARTANDEND = 492,
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
     EMPTYNEGATIVEPATTERNATT = 503,
     NEGATIVEPATTERNATT = 504,
     CONSTANTATT = 505,
     NUMBEROFBLOCKSATT = 506,
     NUMBEROFCOLUMNSATT = 507,
     NUMBEROFROWSATT = 508,
     NUMBEROFVALUESATT = 509,
     NUMBEROFVARIDXATT = 510,
     BASEMATRIXIDXATT = 511,
     TARGETMATRIXFIRSTROWATT = 512,
     TARGETMATRIXFIRSTCOLATT = 513,
     BASEMATRIXSTARTROWATT = 514,
     BASEMATRIXSTARTCOLATT = 515,
     BASEMATRIXENDROWATT = 516,
     BASEMATRIXENDCOLATT = 517,
     SCALARMULTIPLIERATT = 518,
     EMPTYBASETRANSPOSEATT = 519,
     BASETRANSPOSEATT = 520,
     ELEMENTSSTART = 521,
     ELEMENTSEND = 522,
     CONSTANTELEMENTSSTART = 523,
     CONSTANTELEMENTSEND = 524,
     STARTVECTORSTART = 525,
     STARTVECTOREND = 526,
     NONZEROSSTART = 527,
     NONZEROSEND = 528,
     INDEXESSTART = 529,
     INDEXESEND = 530,
     VALUESSTART = 531,
     VALUESEND = 532,
     VARREFERENCEELEMENTSSTART = 533,
     VARREFERENCEELEMENTSEND = 534,
     LINEARELEMENTSSTART = 535,
     LINEARELEMENTSEND = 536,
     GENERALELEMENTSSTART = 537,
     GENERALELEMENTSEND = 538,
     CONREFERENCEELEMENTSSTART = 539,
     CONREFERENCEELEMENTSEND = 540,
     OBJREFERENCEELEMENTSSTART = 541,
     OBJREFERENCEELEMENTSEND = 542,
     PATTERNELEMENTSSTART = 543,
     PATTERNELEMENTSEND = 544,
     VARIDXSTART = 545,
     VARIDXEND = 546,
     TRANSFORMATIONSTART = 547,
     TRANSFORMATIONEND = 548,
     COLOFFSETSSTART = 549,
     COLOFFSETSEND = 550,
     ROWOFFSETSSTART = 551,
     ROWOFFSETSEND = 552,
     EMPTYROWMAJORATT = 553,
     ROWMAJORATT = 554,
     BLOCKROWIDXATT = 555,
     BLOCKCOLIDXATT = 556,
     DUMMY = 557,
     NONLINEAREXPRESSIONSSTART = 558,
     NONLINEAREXPRESSIONSEND = 559,
     NUMBEROFNONLINEAREXPRESSIONS = 560,
     NLSTART = 561,
     NLEND = 562,
     POWERSTART = 563,
     POWEREND = 564,
     PLUSSTART = 565,
     PLUSEND = 566,
     MINUSSTART = 567,
     MINUSEND = 568,
     DIVIDESTART = 569,
     DIVIDEEND = 570,
     LNSTART = 571,
     LNEND = 572,
     SQRTSTART = 573,
     SQRTEND = 574,
     SUMSTART = 575,
     SUMEND = 576,
     PRODUCTSTART = 577,
     PRODUCTEND = 578,
     EXPSTART = 579,
     EXPEND = 580,
     NEGATESTART = 581,
     NEGATEEND = 582,
     IFSTART = 583,
     IFEND = 584,
     SQUARESTART = 585,
     SQUAREEND = 586,
     COSSTART = 587,
     COSEND = 588,
     SINSTART = 589,
     SINEND = 590,
     VARIABLESTART = 591,
     VARIABLEEND = 592,
     ABSSTART = 593,
     ABSEND = 594,
     ERFSTART = 595,
     ERFEND = 596,
     MAXSTART = 597,
     MAXEND = 598,
     ALLDIFFSTART = 599,
     ALLDIFFEND = 600,
     MINSTART = 601,
     MINEND = 602,
     ESTART = 603,
     EEND = 604,
     PISTART = 605,
     PIEND = 606,
     TIMESSTART = 607,
     TIMESEND = 608,
     NUMBERSTART = 609,
     NUMBEREND = 610,
     MATRIXDETERMINANTSTART = 611,
     MATRIXDETERMINANTEND = 612,
     MATRIXTRACESTART = 613,
     MATRIXTRACEEND = 614,
     MATRIXTOSCALARSTART = 615,
     MATRIXTOSCALAREND = 616,
     MATRIXDIAGONALSTART = 617,
     MATRIXDIAGONALEND = 618,
     MATRIXDOTTIMESSTART = 619,
     MATRIXDOTTIMESEND = 620,
     MATRIXLOWERTRIANGLESTART = 621,
     MATRIXLOWERTRIANGLEEND = 622,
     MATRIXUPPERTRIANGLESTART = 623,
     MATRIXUPPERTRIANGLEEND = 624,
     MATRIXMERGESTART = 625,
     MATRIXMERGEEND = 626,
     MATRIXMINUSSTART = 627,
     MATRIXMINUSEND = 628,
     MATRIXNEGATESTART = 629,
     MATRIXNEGATEEND = 630,
     MATRIXPLUSSTART = 631,
     MATRIXPLUSEND = 632,
     MATRIXTIMESSTART = 633,
     MATRIXTIMESEND = 634,
     MATRIXPRODUCTSTART = 635,
     MATRIXPRODUCTEND = 636,
     MATRIXSCALARTIMESSTART = 637,
     MATRIXSCALARTIMESEND = 638,
     MATRIXSUBMATRIXATSTART = 639,
     MATRIXSUBMATRIXATEND = 640,
     MATRIXTRANSPOSESTART = 641,
     MATRIXTRANSPOSEEND = 642,
     MATRIXREFERENCESTART = 643,
     MATRIXREFERENCEEND = 644,
     IDENTITYMATRIXSTART = 645,
     IDENTITYMATRIXEND = 646,
     MATRIXINVERSESTART = 647,
     MATRIXINVERSEEND = 648,
     EMPTYINCLUDEDIAGONALATT = 649,
     INCLUDEDIAGONALATT = 650,
     IDATT = 651,
     COEFATT = 652
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
#define HEADERSTART 471
#define HEADEREND 472
#define FILENAMESTART 473
#define FILENAMEEND 474
#define FILENAMEEMPTY 475
#define FILENAMESTARTANDEND 476
#define FILESOURCESTART 477
#define FILESOURCEEND 478
#define FILESOURCEEMPTY 479
#define FILESOURCESTARTANDEND 480
#define FILEDESCRIPTIONSTART 481
#define FILEDESCRIPTIONEND 482
#define FILEDESCRIPTIONEMPTY 483
#define FILEDESCRIPTIONSTARTANDEND 484
#define FILECREATORSTART 485
#define FILECREATOREND 486
#define FILECREATOREMPTY 487
#define FILECREATORSTARTANDEND 488
#define FILELICENCESTART 489
#define FILELICENCEEND 490
#define FILELICENCEEMPTY 491
#define FILELICENCESTARTANDEND 492
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
#define EMPTYNEGATIVEPATTERNATT 503
#define NEGATIVEPATTERNATT 504
#define CONSTANTATT 505
#define NUMBEROFBLOCKSATT 506
#define NUMBEROFCOLUMNSATT 507
#define NUMBEROFROWSATT 508
#define NUMBEROFVALUESATT 509
#define NUMBEROFVARIDXATT 510
#define BASEMATRIXIDXATT 511
#define TARGETMATRIXFIRSTROWATT 512
#define TARGETMATRIXFIRSTCOLATT 513
#define BASEMATRIXSTARTROWATT 514
#define BASEMATRIXSTARTCOLATT 515
#define BASEMATRIXENDROWATT 516
#define BASEMATRIXENDCOLATT 517
#define SCALARMULTIPLIERATT 518
#define EMPTYBASETRANSPOSEATT 519
#define BASETRANSPOSEATT 520
#define ELEMENTSSTART 521
#define ELEMENTSEND 522
#define CONSTANTELEMENTSSTART 523
#define CONSTANTELEMENTSEND 524
#define STARTVECTORSTART 525
#define STARTVECTOREND 526
#define NONZEROSSTART 527
#define NONZEROSEND 528
#define INDEXESSTART 529
#define INDEXESEND 530
#define VALUESSTART 531
#define VALUESEND 532
#define VARREFERENCEELEMENTSSTART 533
#define VARREFERENCEELEMENTSEND 534
#define LINEARELEMENTSSTART 535
#define LINEARELEMENTSEND 536
#define GENERALELEMENTSSTART 537
#define GENERALELEMENTSEND 538
#define CONREFERENCEELEMENTSSTART 539
#define CONREFERENCEELEMENTSEND 540
#define OBJREFERENCEELEMENTSSTART 541
#define OBJREFERENCEELEMENTSEND 542
#define PATTERNELEMENTSSTART 543
#define PATTERNELEMENTSEND 544
#define VARIDXSTART 545
#define VARIDXEND 546
#define TRANSFORMATIONSTART 547
#define TRANSFORMATIONEND 548
#define COLOFFSETSSTART 549
#define COLOFFSETSEND 550
#define ROWOFFSETSSTART 551
#define ROWOFFSETSEND 552
#define EMPTYROWMAJORATT 553
#define ROWMAJORATT 554
#define BLOCKROWIDXATT 555
#define BLOCKCOLIDXATT 556
#define DUMMY 557
#define NONLINEAREXPRESSIONSSTART 558
#define NONLINEAREXPRESSIONSEND 559
#define NUMBEROFNONLINEAREXPRESSIONS 560
#define NLSTART 561
#define NLEND 562
#define POWERSTART 563
#define POWEREND 564
#define PLUSSTART 565
#define PLUSEND 566
#define MINUSSTART 567
#define MINUSEND 568
#define DIVIDESTART 569
#define DIVIDEEND 570
#define LNSTART 571
#define LNEND 572
#define SQRTSTART 573
#define SQRTEND 574
#define SUMSTART 575
#define SUMEND 576
#define PRODUCTSTART 577
#define PRODUCTEND 578
#define EXPSTART 579
#define EXPEND 580
#define NEGATESTART 581
#define NEGATEEND 582
#define IFSTART 583
#define IFEND 584
#define SQUARESTART 585
#define SQUAREEND 586
#define COSSTART 587
#define COSEND 588
#define SINSTART 589
#define SINEND 590
#define VARIABLESTART 591
#define VARIABLEEND 592
#define ABSSTART 593
#define ABSEND 594
#define ERFSTART 595
#define ERFEND 596
#define MAXSTART 597
#define MAXEND 598
#define ALLDIFFSTART 599
#define ALLDIFFEND 600
#define MINSTART 601
#define MINEND 602
#define ESTART 603
#define EEND 604
#define PISTART 605
#define PIEND 606
#define TIMESSTART 607
#define TIMESEND 608
#define NUMBERSTART 609
#define NUMBEREND 610
#define MATRIXDETERMINANTSTART 611
#define MATRIXDETERMINANTEND 612
#define MATRIXTRACESTART 613
#define MATRIXTRACEEND 614
#define MATRIXTOSCALARSTART 615
#define MATRIXTOSCALAREND 616
#define MATRIXDIAGONALSTART 617
#define MATRIXDIAGONALEND 618
#define MATRIXDOTTIMESSTART 619
#define MATRIXDOTTIMESEND 620
#define MATRIXLOWERTRIANGLESTART 621
#define MATRIXLOWERTRIANGLEEND 622
#define MATRIXUPPERTRIANGLESTART 623
#define MATRIXUPPERTRIANGLEEND 624
#define MATRIXMERGESTART 625
#define MATRIXMERGEEND 626
#define MATRIXMINUSSTART 627
#define MATRIXMINUSEND 628
#define MATRIXNEGATESTART 629
#define MATRIXNEGATEEND 630
#define MATRIXPLUSSTART 631
#define MATRIXPLUSEND 632
#define MATRIXTIMESSTART 633
#define MATRIXTIMESEND 634
#define MATRIXPRODUCTSTART 635
#define MATRIXPRODUCTEND 636
#define MATRIXSCALARTIMESSTART 637
#define MATRIXSCALARTIMESEND 638
#define MATRIXSUBMATRIXATSTART 639
#define MATRIXSUBMATRIXATEND 640
#define MATRIXTRANSPOSESTART 641
#define MATRIXTRANSPOSEEND 642
#define MATRIXREFERENCESTART 643
#define MATRIXREFERENCEEND 644
#define IDENTITYMATRIXSTART 645
#define IDENTITYMATRIXEND 646
#define MATRIXINVERSESTART 647
#define MATRIXINVERSEEND 648
#define EMPTYINCLUDEDIAGONALATT 649
#define INCLUDEDIAGONALATT 650
#define IDATT 651
#define COEFATT 652




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
#define YYNTOKENS  402
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  831
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1234
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1694

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   652

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   399,
     401,     2,     2,   400,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   398,     2,     2,     2,     2,     2,     2,     2,
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
     395,   396,   397
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
     403,     0,    -1,   404,   412,   410,    -1,   405,   406,   407,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   408,    -1,
     409,    -1,    11,    -1,    10,   412,   410,    -1,   411,    -1,
      15,    -1,    -1,   413,   414,   500,   548,   576,   692,    -1,
      -1,  1190,    -1,    -1,   415,   416,    -1,    75,    -1,   417,
      -1,   418,    -1,    10,    76,    -1,    11,    -1,    10,   419,
      76,    -1,   420,    -1,   421,    -1,   420,   421,    -1,   422,
      -1,   428,    -1,   434,    -1,   440,    -1,   448,    -1,   454,
      -1,   460,    -1,   466,    -1,   472,    -1,   478,    -1,   486,
      -1,   423,   424,    -1,    85,    -1,   425,    -1,   426,    -1,
      10,    86,    -1,    11,    -1,    10,   427,    86,    -1,     4,
      -1,   429,   430,    -1,    87,    -1,   431,    -1,   432,    -1,
      10,    88,    -1,    11,    -1,    10,   433,    88,    -1,     4,
      -1,   435,   436,    -1,    89,    -1,   437,    -1,   438,    -1,
      10,    90,    -1,    11,    -1,    10,   439,    90,    -1,     4,
      -1,   441,   442,   444,    -1,    91,    -1,    -1,   443,    -1,
      74,     3,     8,    -1,   445,    -1,   446,    -1,    10,    92,
      -1,    11,    -1,    10,   447,    92,    -1,     4,    -1,   449,
     450,    -1,    93,    -1,   451,    -1,   452,    -1,    10,    94,
      -1,    11,    -1,    10,   453,    94,    -1,     4,    -1,   455,
     456,    -1,    95,    -1,   457,    -1,   458,    -1,    10,    96,
      -1,    11,    -1,    10,   459,    96,    -1,     4,    -1,   461,
     462,    -1,    97,    -1,   463,    -1,   464,    -1,    10,    98,
      -1,    11,    -1,    10,   465,    98,    -1,     4,    -1,   467,
     468,    -1,    99,    -1,   469,    -1,   470,    -1,    10,   100,
      -1,    11,    -1,    10,   471,   100,    -1,     4,    -1,   473,
     474,    -1,   101,    -1,   475,    -1,   476,    -1,    10,   102,
      -1,    11,    -1,    10,   477,   102,    -1,     4,    -1,   479,
     480,   482,    -1,   103,    -1,    -1,   481,    -1,    73,     3,
       8,    -1,   483,    -1,   484,    -1,    10,   104,    -1,    11,
      -1,    10,   485,   104,    -1,     4,    -1,   487,   488,   489,
      -1,   105,    -1,  1168,    -1,   490,    -1,   491,    -1,    10,
     106,    -1,    11,    -1,    10,   492,   106,    -1,   493,    -1,
     494,    -1,   493,   494,    -1,   495,   496,   499,    -1,   107,
      -1,   497,    -1,    -1,   497,   498,    -1,  1119,    -1,  1150,
      -1,  1098,    -1,    10,   108,    -1,    11,    -1,    -1,   501,
     502,    -1,    77,    -1,   503,    -1,   504,    -1,    10,    78,
      -1,    11,    -1,    10,   505,    78,    -1,   506,    -1,   507,
      -1,   506,   507,    -1,   508,    -1,   515,    -1,   522,    -1,
     529,    -1,   534,    -1,   509,   510,   513,    -1,   109,    -1,
     511,    -1,    -1,   511,   512,    -1,  1146,    -1,  1098,    -1,
      10,   514,   110,    -1,  1186,    -1,   516,   517,   520,    -1,
     111,    -1,   518,    -1,    -1,   518,   519,    -1,  1146,    -1,
    1098,    -1,    10,   521,   112,    -1,  1186,    -1,   523,   524,
     527,    -1,   113,    -1,   525,    -1,    -1,   525,   526,    -1,
    1146,    -1,  1098,    -1,    10,   528,   114,    -1,  1186,    -1,
     530,   531,   532,    -1,   115,    -1,    -1,  1098,    -1,    10,
     533,   116,    -1,     6,    -1,   535,   536,   537,    -1,   105,
      -1,  1168,    -1,   538,    -1,   539,    -1,    10,   106,    -1,
      11,    -1,    10,   540,   106,    -1,   541,    -1,   542,    -1,
     541,   542,    -1,   543,   544,   547,    -1,   107,    -1,   545,
      -1,    -1,   545,   546,    -1,  1119,    -1,  1150,    -1,  1098,
      -1,    10,   108,    -1,    11,    -1,    -1,   549,   550,    -1,
      79,    -1,   551,    -1,   552,    -1,    10,    80,    -1,    11,
      -1,    10,   553,    80,    -1,   554,    -1,   555,    -1,   554,
     555,    -1,   556,    -1,   562,    -1,   557,   558,    -1,   117,
      -1,   559,    -1,   560,    -1,    10,   118,    -1,    11,    -1,
      10,   561,   118,    -1,     4,    -1,   563,   564,   565,    -1,
     105,    -1,  1168,    -1,   566,    -1,   567,    -1,    10,   106,
      -1,    11,    -1,    10,   568,   106,    -1,   569,    -1,   570,
      -1,   569,   570,    -1,   571,   572,   575,    -1,   107,    -1,
     573,    -1,    -1,   573,   574,    -1,  1119,    -1,  1150,    -1,
    1098,    -1,    10,   108,    -1,    11,    -1,    -1,   577,   578,
      -1,    81,    -1,   579,    -1,   580,    -1,    10,    82,    -1,
      11,    -1,    10,   581,    82,    -1,   582,    -1,   583,    -1,
     582,   583,    -1,   584,    -1,   592,    -1,   598,    -1,   606,
      -1,   611,    -1,   616,    -1,   621,    -1,   626,    -1,   634,
      -1,   650,    -1,   642,    -1,   658,    -1,   664,    -1,   670,
      -1,   678,    -1,   585,   586,   587,    -1,   119,    -1,    -1,
    1146,    -1,   588,    -1,   589,    -1,    10,   120,    -1,    11,
      -1,    10,   590,   120,    -1,   591,    -1,  1186,    -1,   593,
     594,    -1,   121,    -1,   595,    -1,   596,    -1,    10,   122,
      -1,    11,    -1,    10,   597,   122,    -1,     4,    -1,   599,
     600,   601,    -1,   123,    -1,  1163,    -1,   602,    -1,   603,
      -1,    10,   124,    -1,    11,    -1,    10,   604,   124,    -1,
     605,    -1,   604,   605,    -1,    93,    10,     4,    94,    -1,
     607,  1171,   608,    -1,   125,    -1,   609,    -1,   610,    -1,
      10,   126,    -1,    11,    -1,    10,  1079,   126,    -1,   612,
    1171,   613,    -1,   127,    -1,   614,    -1,   615,    -1,    10,
     128,    -1,    11,    -1,    10,  1079,   128,    -1,   617,  1171,
     618,    -1,   133,    -1,   619,    -1,   620,    -1,    10,   134,
      -1,    11,    -1,    10,  1079,   134,    -1,   622,  1171,   623,
      -1,   135,    -1,   624,    -1,   625,    -1,    10,   136,    -1,
      11,    -1,    10,  1079,   136,    -1,   627,   628,   629,    -1,
     141,    -1,  1170,    -1,   630,    -1,   631,    -1,    10,   142,
      -1,    11,    -1,    10,   632,   142,    -1,   633,    -1,   632,
     633,    -1,  1081,    -1,   635,   636,   637,    -1,   143,    -1,
    1170,    -1,   638,    -1,   639,    -1,    10,   144,    -1,    11,
      -1,    10,   640,   144,    -1,   641,    -1,   640,   641,    -1,
    1081,    -1,   643,   644,   645,    -1,   147,    -1,  1170,    -1,
     646,    -1,   647,    -1,    10,   148,    -1,    11,    -1,    10,
     648,   148,    -1,   649,    -1,   648,   649,    -1,  1081,    -1,
     651,   652,   653,    -1,   145,    -1,  1170,    -1,   654,    -1,
     655,    -1,    10,   146,    -1,    11,    -1,    10,   656,   146,
      -1,   657,    -1,   656,   657,    -1,  1081,    -1,   659,   660,
     661,    -1,   139,    -1,  1171,    -1,   662,    -1,   663,    -1,
      10,   140,    -1,    11,    -1,    10,  1079,   140,    -1,   665,
     666,   667,    -1,   137,    -1,  1171,    -1,   668,    -1,   669,
      -1,    10,   138,    -1,    11,    -1,    10,  1079,   138,    -1,
     671,   672,   673,    -1,   149,    -1,  1172,    -1,   674,    -1,
     675,    -1,    10,   150,    -1,    11,    -1,    10,   676,   150,
      -1,   677,    -1,   676,   677,    -1,   151,    10,     4,   152,
      -1,   679,   680,   681,    -1,   105,    -1,  1168,    -1,   682,
      -1,   683,    -1,    10,   106,    -1,    11,    -1,    10,   684,
     106,    -1,   685,    -1,   686,    -1,   685,   686,    -1,   687,
     688,   691,    -1,   107,    -1,   689,    -1,    -1,   689,   690,
      -1,  1119,    -1,  1150,    -1,  1098,    -1,    10,   108,    -1,
      11,    -1,    -1,   693,   694,   697,    -1,    83,    -1,   695,
      -1,    -1,   695,   696,    -1,  1175,    -1,  1159,    -1,  1165,
      -1,   698,    -1,   699,    -1,    11,    -1,    10,   700,    84,
      -1,   701,   839,   948,  1057,    -1,    -1,   702,   703,   705,
      -1,   153,    -1,   704,    -1,    -1,  1169,    -1,   706,    -1,
     707,    -1,    11,    -1,    10,   708,   154,    -1,   709,   723,
     737,   792,   806,   821,    -1,    -1,   710,   711,   712,    -1,
     155,    -1,  1174,    -1,   713,    -1,   714,    -1,    10,   156,
      -1,    11,    -1,    10,   715,   156,    -1,   716,    -1,   717,
      -1,   716,   717,    -1,   718,   719,   722,    -1,   157,    -1,
     720,    -1,    -1,   720,   721,    -1,  1108,    -1,  1119,    -1,
    1150,    -1,    10,   158,    -1,    11,    -1,    -1,   724,   725,
     726,    -1,   159,    -1,  1174,    -1,   727,    -1,   728,    -1,
      10,   160,    -1,    11,    -1,    10,   729,   160,    -1,   730,
      -1,   731,    -1,   730,   731,    -1,   732,   733,   736,    -1,
     157,    -1,   734,    -1,    -1,   734,   735,    -1,  1108,    -1,
    1119,    -1,  1150,    -1,    10,   158,    -1,    11,    -1,    -1,
     738,   739,    -1,   161,    -1,   740,    -1,   741,    -1,    11,
      -1,    10,   742,   162,    -1,   743,   750,   757,   764,   771,
     778,   785,    -1,    -1,   744,   745,   746,    -1,   163,    -1,
    1160,    -1,   747,    -1,   748,    -1,    11,    -1,    10,   749,
     164,    -1,  1218,    -1,    -1,   751,   752,   753,    -1,   167,
      -1,  1160,    -1,   754,    -1,   755,    -1,    11,    -1,    10,
     756,   168,    -1,  1218,    -1,    -1,   758,   759,   760,    -1,
     165,    -1,  1160,    -1,   761,    -1,   762,    -1,    11,    -1,
      10,   763,   166,    -1,  1218,    -1,    -1,   765,   766,   767,
      -1,   169,    -1,  1160,    -1,   768,    -1,   769,    -1,    11,
      -1,    10,   770,   170,    -1,  1218,    -1,    -1,   772,   773,
     774,    -1,   173,    -1,  1160,    -1,   775,    -1,   776,    -1,
      11,    -1,    10,   777,   174,    -1,  1218,    -1,    -1,   779,
     780,   781,    -1,   171,    -1,  1160,    -1,   782,    -1,   783,
      -1,    11,    -1,    10,   784,   172,    -1,  1218,    -1,    -1,
     786,   787,   788,    -1,   175,    -1,  1160,    -1,   789,    -1,
     790,    -1,    11,    -1,    10,   791,   176,    -1,  1218,    -1,
      -1,   793,   794,   795,    -1,   177,    -1,  1174,    -1,   796,
      -1,   797,    -1,    10,   178,    -1,    11,    -1,    10,   798,
     178,    -1,   799,    -1,   800,    -1,   799,   800,    -1,   801,
     802,   805,    -1,   157,    -1,   803,    -1,    -1,   803,   804,
      -1,  1108,    -1,  1119,    -1,  1150,    -1,    10,   158,    -1,
      11,    -1,    -1,   807,   808,   809,    -1,   179,    -1,    29,
       8,     6,     8,    -1,   810,    -1,   811,    -1,    10,   180,
      -1,    11,    -1,    10,   812,   180,    -1,   813,    -1,   812,
     813,    -1,   814,   815,   818,    -1,   181,    -1,   816,    -1,
      -1,   816,   817,    -1,  1131,    -1,  1174,    -1,  1106,    -1,
     819,    -1,   820,    -1,    10,   182,    -1,    11,    -1,    10,
     799,   182,    -1,    -1,   821,   822,    -1,   823,   824,   827,
      -1,   107,    -1,   825,    -1,    -1,   825,   826,    -1,  1174,
      -1,  1161,    -1,  1119,    -1,  1150,    -1,  1127,    -1,  1090,
      -1,  1134,    -1,  1154,    -1,  1102,    -1,  1098,    -1,   828,
      -1,   829,    -1,    10,   108,    -1,    11,    -1,    10,   830,
     108,    -1,   831,    -1,  1176,    -1,   832,    -1,   831,   832,
      -1,   833,   834,   837,    -1,   157,    -1,   835,    -1,    -1,
     835,   836,    -1,  1108,    -1,  1119,    -1,  1150,    -1,  1111,
      -1,  1138,    -1,   838,    -1,    10,   158,    -1,    11,    -1,
      -1,   840,   841,   843,    -1,   183,    -1,   842,    -1,    -1,
    1167,    -1,   844,    -1,   845,    -1,    11,    -1,    10,   846,
     184,    -1,   847,   861,   875,   930,    -1,    -1,   848,   849,
     850,    -1,   185,    -1,  1164,    -1,   851,    -1,   852,    -1,
      10,   186,    -1,    11,    -1,    10,   853,   186,    -1,   854,
      -1,   855,    -1,   854,   855,    -1,   856,   857,   860,    -1,
     187,    -1,   858,    -1,    -1,   858,   859,    -1,  1108,    -1,
    1119,    -1,  1150,    -1,    10,   188,    -1,    11,    -1,    -1,
     862,   863,   864,    -1,   189,    -1,  1164,    -1,   865,    -1,
     866,    -1,    10,   190,    -1,    11,    -1,    10,   867,   190,
      -1,   868,    -1,   869,    -1,   868,   869,    -1,   870,   871,
     874,    -1,   187,    -1,   872,    -1,    -1,   872,   873,    -1,
    1108,    -1,  1119,    -1,  1111,    -1,  1138,    -1,    10,   188,
      -1,    11,    -1,    -1,   876,   877,    -1,   161,    -1,   878,
      -1,   879,    -1,    11,    -1,    10,   880,   162,    -1,   881,
     888,   895,   902,   909,   916,   923,    -1,    -1,   882,   883,
     884,    -1,   163,    -1,  1160,    -1,   885,    -1,   886,    -1,
      11,    -1,    10,   887,   164,    -1,  1218,    -1,    -1,   889,
     890,   891,    -1,   167,    -1,  1160,    -1,   892,    -1,   893,
      -1,    11,    -1,    10,   894,   168,    -1,  1218,    -1,    -1,
     896,   897,   898,    -1,   165,    -1,  1160,    -1,   899,    -1,
     900,    -1,    11,    -1,    10,   901,   166,    -1,  1218,    -1,
      -1,   903,   904,   905,    -1,   169,    -1,  1160,    -1,   906,
      -1,   907,    -1,    11,    -1,    10,   908,   170,    -1,  1218,
      -1,    -1,   910,   911,   912,    -1,   173,    -1,  1160,    -1,
     913,    -1,   914,    -1,    11,    -1,    10,   915,   174,    -1,
    1218,    -1,    -1,   917,   918,   919,    -1,   171,    -1,  1160,
      -1,   920,    -1,   921,    -1,    11,    -1,    10,   922,   172,
      -1,  1218,    -1,    -1,   924,   925,   926,    -1,   175,    -1,
    1160,    -1,   927,    -1,   928,    -1,    11,    -1,    10,   929,
     176,    -1,  1218,    -1,    -1,   930,   931,    -1,   932,   933,
     936,    -1,   107,    -1,   934,    -1,    -1,   934,   935,    -1,
    1164,    -1,  1161,    -1,  1119,    -1,  1150,    -1,  1127,    -1,
    1090,    -1,  1134,    -1,  1123,    -1,  1102,    -1,  1098,    -1,
     937,    -1,   938,    -1,    10,   108,    -1,    11,    -1,    10,
     939,   108,    -1,   940,    -1,  1176,    -1,   941,    -1,   940,
     941,    -1,   942,   943,   946,    -1,   187,    -1,   944,    -1,
      -1,   944,   945,    -1,  1108,    -1,  1119,    -1,  1150,    -1,
    1111,    -1,  1138,    -1,   947,    -1,    10,   188,    -1,    11,
      -1,    -1,   949,   950,   952,    -1,   191,    -1,   951,    -1,
      -1,  1166,    -1,   953,    -1,   954,    -1,    11,    -1,    10,
     955,   192,    -1,   956,   970,   984,  1039,    -1,    -1,   957,
     958,   959,    -1,   193,    -1,  1158,    -1,   960,    -1,   961,
      -1,    10,   194,    -1,    11,    -1,    10,   962,   194,    -1,
     963,    -1,   964,    -1,   963,   964,    -1,   965,   966,   969,
      -1,   195,    -1,   967,    -1,    -1,   967,   968,    -1,  1108,
      -1,  1119,    -1,  1150,    -1,    10,   196,    -1,    11,    -1,
      -1,   971,   972,   973,    -1,   197,    -1,  1158,    -1,   974,
      -1,   975,    -1,    10,   198,    -1,    11,    -1,    10,   976,
     198,    -1,   977,    -1,   978,    -1,   977,   978,    -1,   979,
     980,   983,    -1,   195,    -1,   981,    -1,    -1,   981,   982,
      -1,  1108,    -1,  1119,    -1,  1115,    -1,  1142,    -1,    10,
     196,    -1,    11,    -1,    -1,   985,   986,    -1,   161,    -1,
     987,    -1,   988,    -1,    11,    -1,    10,   989,   162,    -1,
     990,   997,  1004,  1011,  1018,  1025,  1032,    -1,    -1,   991,
     992,   993,    -1,   163,    -1,  1160,    -1,   994,    -1,   995,
      -1,    11,    -1,    10,   996,   164,    -1,  1218,    -1,    -1,
     998,   999,  1000,    -1,   167,    -1,  1160,    -1,  1001,    -1,
    1002,    -1,    11,    -1,    10,  1003,   168,    -1,  1218,    -1,
      -1,  1005,  1006,  1007,    -1,   165,    -1,  1160,    -1,  1008,
      -1,  1009,    -1,    11,    -1,    10,  1010,   166,    -1,  1218,
      -1,    -1,  1012,  1013,  1014,    -1,   169,    -1,  1160,    -1,
    1015,    -1,  1016,    -1,    11,    -1,    10,  1017,   170,    -1,
    1218,    -1,    -1,  1019,  1020,  1021,    -1,   173,    -1,  1160,
      -1,  1022,    -1,  1023,    -1,    11,    -1,    10,  1024,   174,
      -1,  1218,    -1,    -1,  1026,  1027,  1028,    -1,   171,    -1,
    1160,    -1,  1029,    -1,  1030,    -1,    11,    -1,    10,  1031,
     172,    -1,  1218,    -1,    -1,  1033,  1034,  1035,    -1,   175,
      -1,  1160,    -1,  1036,    -1,  1037,    -1,    11,    -1,    10,
    1038,   176,    -1,  1218,    -1,    -1,  1039,  1040,    -1,  1041,
    1042,  1045,    -1,   107,    -1,  1043,    -1,    -1,  1043,  1044,
      -1,  1158,    -1,  1161,    -1,  1119,    -1,  1150,    -1,  1127,
      -1,  1090,    -1,  1134,    -1,  1094,    -1,  1102,    -1,  1098,
      -1,  1046,    -1,  1047,    -1,    10,   108,    -1,    11,    -1,
      10,  1048,   108,    -1,  1049,    -1,  1176,    -1,  1050,    -1,
    1049,  1050,    -1,  1051,  1052,  1055,    -1,   195,    -1,  1053,
      -1,    -1,  1053,  1054,    -1,  1108,    -1,  1119,    -1,  1150,
      -1,  1111,    -1,  1138,    -1,  1056,    -1,    10,   196,    -1,
      11,    -1,    -1,  1058,  1059,  1060,    -1,   199,    -1,  1173,
      -1,  1061,    -1,  1062,    -1,    11,    -1,    10,  1063,   200,
      -1,    -1,  1063,  1064,    -1,  1065,  1066,  1069,    -1,   201,
      -1,  1067,    -1,  1068,    -1,  1067,  1068,    -1,  1119,    -1,
    1150,    -1,  1127,    -1,  1090,    -1,  1134,    -1,  1098,    -1,
    1162,    -1,  1070,    -1,  1071,    -1,    10,   202,    -1,    11,
      -1,    10,  1072,   202,    -1,  1073,    -1,  1074,    -1,  1073,
    1074,    -1,  1075,    -1,  1076,    -1,  1077,    -1,   208,    -1,
     205,    -1,   206,  1078,   207,    -1,     5,    -1,  1080,    -1,
    1079,  1080,    -1,   129,    10,     4,   130,    -1,  1082,  1083,
    1089,    -1,   131,    -1,  1084,    -1,    -1,  1084,  1085,    -1,
    1086,    -1,  1087,    -1,  1088,    -1,    21,     3,     8,    -1,
      22,     3,     8,    -1,    23,     3,     8,    -1,    10,   132,
      -1,    11,    -1,  1091,    -1,  1092,    -1,  1093,    -1,    57,
      -1,    24,     3,  1187,    -1,  1095,    -1,  1096,    -1,  1097,
      -1,    48,    -1,    47,     3,     8,    -1,  1099,    -1,  1100,
      -1,  1101,    -1,    58,    -1,    46,     3,  1187,    -1,  1103,
      -1,  1104,    -1,  1105,    -1,    50,    -1,    49,     3,     8,
      -1,  1107,    -1,    26,     8,  1186,     8,    -1,  1109,    -1,
    1110,    -1,    42,  1187,     6,  1187,    -1,  1112,    -1,  1113,
      -1,  1114,    -1,    61,    -1,    63,     3,  1187,    -1,  1116,
      -1,  1117,    -1,  1118,    -1,    65,    -1,    67,  1187,  1186,
    1187,    -1,  1120,    -1,  1121,    -1,  1122,    -1,    56,    -1,
      41,     3,  1187,    -1,  1124,    -1,  1125,    -1,  1126,    -1,
      52,    -1,    51,     3,     8,    -1,  1128,    -1,  1129,    -1,
    1130,    -1,    70,    -1,    69,     3,  1187,    -1,  1132,    -1,
    1133,    -1,    43,  1187,     6,  1187,    -1,  1135,    -1,  1136,
      -1,  1137,    -1,    55,    -1,    25,     3,     8,    -1,  1139,
      -1,  1140,    -1,  1141,    -1,    62,    -1,    64,     3,  1187,
      -1,  1143,    -1,  1144,    -1,  1145,    -1,    66,    -1,    68,
    1187,  1186,  1187,    -1,  1147,    -1,  1148,    -1,  1149,    -1,
      59,    -1,    45,     3,     8,    -1,  1151,    -1,  1152,    -1,
    1153,    -1,    60,    -1,    44,     3,     8,    -1,  1155,    -1,
    1156,    -1,  1157,    -1,    54,    -1,    53,     3,     8,    -1,
      39,  1187,     6,  1187,    -1,    32,  1187,     6,  1187,    -1,
      40,  1187,     6,  1187,    -1,    17,  1187,     6,  1187,    -1,
      36,  1187,     6,  1187,    -1,    18,     8,     6,     8,    -1,
      38,  1187,     6,  1187,    -1,    31,  1187,     6,  1187,    -1,
      35,  1187,     6,  1187,    -1,    34,  1187,     6,  1187,    -1,
      16,  1187,     6,  1187,    -1,    33,  1187,     6,  1187,    -1,
      20,     8,     6,     8,    -1,    19,     8,     6,     8,    -1,
      27,     8,     6,     8,    -1,    28,  1187,     6,  1187,    -1,
      37,  1187,     6,  1187,    -1,    30,  1187,     6,  1187,    -1,
    1177,    -1,  1176,  1177,    -1,  1178,  1179,  1182,    -1,   203,
      -1,  1180,    -1,    -1,  1180,  1181,    -1,  1160,    -1,  1150,
      -1,  1098,    -1,  1183,    -1,  1184,    -1,    11,    -1,    10,
    1185,   204,    -1,  1218,    -1,     6,    -1,     7,    -1,  1188,
       8,    -1,    -1,  1188,  1189,    -1,   398,    -1,   399,    -1,
     400,    -1,   401,    -1,  1191,  1192,    -1,   216,    -1,  1193,
      -1,  1194,    -1,    11,    -1,    10,  1195,   217,    -1,  1196,
      -1,    -1,  1196,  1197,    -1,  1198,    -1,  1202,    -1,  1206,
      -1,  1210,    -1,  1214,    -1,  1199,    -1,  1200,    -1,  1201,
      -1,   221,    -1,   220,    -1,   218,     5,   219,    -1,  1203,
      -1,  1204,    -1,  1205,    -1,   225,    -1,   224,    -1,   222,
       5,   223,    -1,  1207,    -1,  1208,    -1,  1209,    -1,   229,
      -1,   228,    -1,   226,     5,   227,    -1,  1211,    -1,  1212,
      -1,  1213,    -1,   233,    -1,   232,    -1,   230,     5,   231,
      -1,  1215,    -1,  1216,    -1,  1217,    -1,   237,    -1,   236,
      -1,   234,     5,   235,    -1,  1219,    -1,  1226,    -1,    -1,
    1219,  1220,    -1,  1221,  1222,  1225,    -1,   214,    -1,  1223,
      -1,    -1,  1223,  1224,    -1,  1232,    -1,  1231,    -1,    10,
       6,   215,    -1,   209,  1230,  1227,    -1,  1228,    -1,  1229,
      -1,    10,   210,    -1,    11,    -1,    10,     4,   210,    -1,
     213,     8,     6,     8,    -1,   211,     8,     6,     8,    -1,
     212,     8,     6,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   295,   295,   296,   298,   305,   315,   315,   317,   317,
     319,   321,   323,   332,   333,   336,   344,   344,   357,   357,
     359,   375,   375,   377,   377,   379,   381,   383,   383,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     400,   402,   411,   411,   413,   413,   415,   417,   427,   429,
     436,   436,   438,   438,   440,   442,   452,   454,   460,   460,
     462,   462,   464,   466,   476,   483,   491,   492,   499,   505,
     505,   507,   507,   509,   511,   519,   521,   527,   527,   529,
     529,   531,   533,   542,   544,   551,   551,   553,   553,   555,
     557,   567,   569,   576,   576,   578,   578,   580,   582,   592,
     594,   600,   600,   602,   602,   604,   606,   616,   618,   624,
     624,   626,   626,   628,   630,   640,   647,   656,   657,   663,
     670,   670,   672,   672,   674,   676,   684,   690,   700,   708,
     713,   719,   719,   721,   723,   727,   727,   729,   737,   756,
     762,   762,   765,   769,   770,   773,   773,   782,   782,   784,
     794,   794,   796,   796,   798,   800,   802,   802,   805,   806,
     807,   808,   809,   813,   815,   825,   827,   827,   830,   831,
     834,   836,   844,   846,   856,   858,   858,   861,   862,   865,
     867,   876,   878,   888,   890,   890,   893,   894,   897,   899,
     908,   910,   918,   919,   921,   923,   934,   940,   950,   958,
     962,   967,   967,   969,   971,   975,   975,   977,   985,  1004,
    1009,  1009,  1012,  1017,  1018,  1021,  1021,  1030,  1030,  1032,
    1039,  1039,  1041,  1041,  1043,  1045,  1047,  1047,  1050,  1051,
    1055,  1057,  1063,  1063,  1065,  1065,  1067,  1069,  1080,  1086,
    1096,  1104,  1108,  1113,  1113,  1115,  1117,  1121,  1121,  1123,
    1131,  1150,  1155,  1155,  1158,  1163,  1164,  1167,  1167,  1175,
    1175,  1177,  1197,  1197,  1199,  1199,  1201,  1203,  1205,  1205,
    1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,
    1218,  1219,  1220,  1221,  1222,  1227,  1233,  1243,  1244,  1246,
    1246,  1248,  1248,  1250,  1252,  1254,  1261,  1263,  1269,  1269,
    1271,  1271,  1273,  1275,  1285,  1296,  1306,  1308,  1308,  1310,
    1310,  1312,  1321,  1321,  1323,  1344,  1355,  1365,  1365,  1367,
    1367,  1369,  1380,  1391,  1401,  1401,  1403,  1403,  1405,  1416,
    1427,  1437,  1437,  1439,  1439,  1441,  1452,  1463,  1473,  1473,
    1475,  1475,  1477,  1488,  1504,  1514,  1516,  1516,  1518,  1518,
    1520,  1529,  1529,  1531,  1535,  1551,  1561,  1563,  1563,  1565,
    1565,  1567,  1576,  1576,  1578,  1582,  1598,  1608,  1610,  1610,
    1612,  1612,  1614,  1623,  1623,  1625,  1629,  1645,  1655,  1657,
    1657,  1659,  1659,  1661,  1670,  1670,  1672,  1676,  1687,  1697,
    1699,  1699,  1701,  1701,  1703,  1714,  1725,  1735,  1737,  1737,
    1739,  1739,  1741,  1767,  1778,  1788,  1790,  1790,  1792,  1792,
    1794,  1803,  1803,  1805,  1826,  1832,  1842,  1850,  1854,  1859,
    1859,  1861,  1863,  1867,  1867,  1869,  1877,  1896,  1902,  1902,
    1905,  1910,  1911,  1914,  1914,  1922,  1922,  1924,  1932,  1934,
    1934,  1937,  1943,  1949,  1957,  1957,  1959,  1961,  1963,  1970,
    1970,  1972,  1978,  1985,  1985,  1990,  1990,  1992,  1994,  1996,
    2006,  2006,  2021,  2026,  2037,  2045,  2054,  2054,  2056,  2058,
    2060,  2060,  2063,  2068,  2082,  2088,  2088,  2091,  2103,  2108,
    2116,  2116,  2120,  2120,  2135,  2140,  2151,  2159,  2168,  2168,
    2170,  2172,  2174,  2174,  2177,  2182,  2197,  2203,  2203,  2206,
    2218,  2223,  2229,  2229,  2233,  2233,  2235,  2240,  2240,  2242,
    2244,  2246,  2249,  2249,  2260,  2266,  2274,  2274,  2276,  2278,
    2280,  2284,  2284,  2296,  2302,  2310,  2310,  2312,  2314,  2316,
    2320,  2320,  2331,  2337,  2345,  2345,  2347,  2349,  2351,  2355,
    2355,  2366,  2372,  2380,  2380,  2382,  2384,  2386,  2390,  2390,
    2401,  2407,  2415,  2415,  2417,  2419,  2421,  2425,  2425,  2436,
    2442,  2450,  2450,  2452,  2454,  2456,  2460,  2460,  2471,  2477,
    2485,  2485,  2487,  2489,  2491,  2495,  2495,  2511,  2516,  2527,
    2535,  2544,  2544,  2546,  2548,  2554,  2554,  2556,  2561,  2577,
    2583,  2583,  2586,  2598,  2603,  2611,  2611,  2615,  2615,  2621,
    2627,  2635,  2643,  2651,  2651,  2653,  2655,  2655,  2657,  2676,
    2692,  2700,  2700,  2703,  2704,  2713,  2716,  2716,  2718,  2718,
    2720,  2725,  2725,  2727,  2732,  2763,  2783,  2783,  2786,  2790,
    2794,  2795,  2796,  2797,  2798,  2799,  2800,  2801,  2804,  2804,
    2806,  2806,  2808,  2810,  2810,  2812,  2812,  2815,  2830,  2850,
    2852,  2852,  2855,  2865,  2866,  2867,  2868,  2871,  2873,  2873,
    2881,  2881,  2883,  2889,  2896,  2896,  2901,  2901,  2903,  2905,
    2907,  2916,  2916,  2932,  2938,  2950,  2958,  2967,  2967,  2969,
    2971,  2973,  2973,  2976,  2981,  2996,  2998,  2998,  3001,  3012,
    3016,  3023,  3023,  3026,  3026,  3044,  3049,  3063,  3071,  3080,
    3080,  3082,  3084,  3086,  3086,  3089,  3094,  3112,  3114,  3114,
    3117,  3128,  3132,  3138,  3145,  3145,  3149,  3149,  3151,  3156,
    3156,  3158,  3160,  3162,  3165,  3165,  3176,  3182,  3190,  3190,
    3192,  3194,  3196,  3199,  3199,  3210,  3216,  3224,  3224,  3226,
    3228,  3230,  3233,  3233,  3244,  3250,  3258,  3258,  3260,  3262,
    3264,  3267,  3267,  3278,  3284,  3292,  3292,  3294,  3296,  3298,
    3301,  3301,  3312,  3318,  3326,  3326,  3328,  3330,  3332,  3335,
    3335,  3346,  3353,  3361,  3361,  3363,  3365,  3367,  3371,  3371,
    3382,  3388,  3396,  3396,  3398,  3400,  3402,  3406,  3406,  3408,
    3414,  3445,  3466,  3466,  3469,  3473,  3477,  3478,  3479,  3480,
    3481,  3482,  3483,  3484,  3487,  3487,  3489,  3489,  3491,  3493,
    3493,  3495,  3495,  3498,  3513,  3535,  3537,  3537,  3540,  3550,
    3551,  3552,  3553,  3556,  3558,  3558,  3566,  3566,  3568,  3574,
    3581,  3581,  3586,  3586,  3588,  3590,  3592,  3601,  3601,  3617,
    3622,  3633,  3641,  3650,  3650,  3652,  3654,  3656,  3656,  3659,
    3664,  3679,  3685,  3685,  3688,  3699,  3703,  3710,  3710,  3714,
    3714,  3732,  3737,  3750,  3758,  3767,  3767,  3769,  3771,  3773,
    3773,  3776,  3781,  3799,  3805,  3805,  3808,  3819,  3823,  3827,
    3833,  3833,  3837,  3837,  3839,  3844,  3844,  3846,  3848,  3850,
    3853,  3853,  3864,  3870,  3878,  3878,  3880,  3882,  3884,  3887,
    3887,  3898,  3904,  3912,  3912,  3914,  3916,  3918,  3922,  3922,
    3933,  3939,  3947,  3947,  3949,  3951,  3953,  3957,  3957,  3968,
    3974,  3982,  3982,  3984,  3986,  3988,  3992,  3992,  4003,  4009,
    4017,  4017,  4019,  4021,  4023,  4027,  4027,  4038,  4044,  4052,
    4052,  4054,  4056,  4058,  4062,  4062,  4073,  4079,  4087,  4087,
    4089,  4091,  4093,  4097,  4097,  4099,  4105,  4136,  4156,  4156,
    4159,  4163,  4167,  4168,  4169,  4170,  4171,  4172,  4173,  4174,
    4177,  4177,  4179,  4179,  4181,  4183,  4183,  4185,  4185,  4188,
    4203,  4223,  4225,  4225,  4228,  4238,  4239,  4240,  4241,  4244,
    4246,  4246,  4254,  4254,  4260,  4262,  4270,  4278,  4287,  4289,
    4291,  4291,  4295,  4315,  4333,  4339,  4339,  4342,  4343,  4344,
    4345,  4346,  4347,  4348,  4355,  4363,  4372,  4372,  4374,  4376,
    4378,  4378,  4380,  4387,  4398,  4400,  4400,  4402,  4404,  4421,
    4421,  4423,  4445,  4462,  4474,  4479,  4479,  4482,  4483,  4484,
    4486,  4495,  4504,  4513,  4513,  4519,  4526,  4526,  4528,  4533,
    4540,  4546,  4546,  4548,  4551,  4558,  4565,  4565,  4567,  4570,
    4577,  4583,  4583,  4585,  4588,  4596,  4603,  4610,  4617,  4619,
    4625,  4632,  4632,  4634,  4639,  4646,  4652,  4652,  4654,  4659,
    4665,  4672,  4672,  4674,  4679,  4686,  4692,  4692,  4694,  4697,
    4705,  4711,  4711,  4713,  4716,  4723,  4729,  4731,  4739,  4745,
    4745,  4747,  4750,  4757,  4764,  4764,  4766,  4771,  4778,  4784,
    4784,  4786,  4789,  4796,  4802,  4802,  4804,  4807,  4814,  4820,
    4820,  4822,  4825,  4832,  4838,  4838,  4840,  4843,  4855,  4864,
    4873,  4882,  4891,  4900,  4910,  4919,  4928,  4934,  4940,  4946,
    4952,  4966,  4976,  4987,  4993,  5002,  5023,  5023,  5025,  5043,
    5059,  5067,  5067,  5070,  5078,  5079,  5083,  5083,  5085,  5088,
    5090,  5094,  5095,  5102,  5104,  5104,  5106,  5107,  5108,  5109,
    5145,  5147,  5161,  5161,  5163,  5165,  5167,  5169,  5169,  5172,
    5173,  5174,  5175,  5176,  5178,  5186,  5186,  5188,  5188,  5190,
    5196,  5204,  5204,  5206,  5206,  5208,  5214,  5222,  5222,  5224,
    5224,  5226,  5232,  5240,  5240,  5242,  5242,  5244,  5250,  5258,
    5258,  5260,  5260,  5262,  5274,  5283,  5285,  5285,  5287,  5289,
    5298,  5300,  5300,  5302,  5302,  5304,  5321,  5324,  5324,  5326,
    5326,  5329,  7220,  7225,  7233
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
  "MULTATT", "SIZEOFATT", "ELSTART", "ELEND", "HEADERSTART", "HEADEREND",
  "FILENAMESTART", "FILENAMEEND", "FILENAMEEMPTY", "FILENAMESTARTANDEND",
  "FILESOURCESTART", "FILESOURCEEND", "FILESOURCEEMPTY",
  "FILESOURCESTARTANDEND", "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND",
  "FILEDESCRIPTIONEMPTY", "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART",
  "FILECREATOREND", "FILECREATOREMPTY", "FILECREATORSTARTANDEND",
  "FILELICENCESTART", "FILELICENCEEND", "FILELICENCEEMPTY",
  "FILELICENCESTARTANDEND", "MATRIXSTART", "MATRIXEND", "BASEMATRIXEND",
  "BASEMATRIXSTART", "BLOCKSTART", "BLOCKEND", "BLOCKSSTART", "BLOCKSEND",
  "EMPTYSYMMETRYATT", "SYMMETRYATT", "EMPTYNEGATIVEPATTERNATT",
  "NEGATIVEPATTERNATT", "CONSTANTATT", "NUMBEROFBLOCKSATT",
  "NUMBEROFCOLUMNSATT", "NUMBEROFROWSATT", "NUMBEROFVALUESATT",
  "NUMBEROFVARIDXATT", "BASEMATRIXIDXATT", "TARGETMATRIXFIRSTROWATT",
  "TARGETMATRIXFIRSTCOLATT", "BASEMATRIXSTARTROWATT",
  "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT", "BASEMATRIXENDCOLATT",
  "SCALARMULTIPLIERATT", "EMPTYBASETRANSPOSEATT", "BASETRANSPOSEATT",
  "ELEMENTSSTART", "ELEMENTSEND", "CONSTANTELEMENTSSTART",
  "CONSTANTELEMENTSEND", "STARTVECTORSTART", "STARTVECTOREND",
  "NONZEROSSTART", "NONZEROSEND", "INDEXESSTART", "INDEXESEND",
  "VALUESSTART", "VALUESEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "GENERALELEMENTSSTART", "GENERALELEMENTSEND",
  "CONREFERENCEELEMENTSSTART", "CONREFERENCEELEMENTSEND",
  "OBJREFERENCEELEMENTSSTART", "OBJREFERENCEELEMENTSEND",
  "PATTERNELEMENTSSTART", "PATTERNELEMENTSEND", "VARIDXSTART", "VARIDXEND",
  "TRANSFORMATIONSTART", "TRANSFORMATIONEND", "COLOFFSETSSTART",
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
  "IDATT", "COEFATT", "' '", "'\\t'", "'\\r'", "'\\n'", "$accept",
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
     645,   646,   647,   648,   649,   650,   651,   652,    32,     9,
      13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   402,   403,   403,   404,   405,   406,   406,   407,   407,
     408,   409,   410,   411,   411,   412,   413,   413,   414,   414,
     415,   416,   416,   417,   417,   418,   419,   420,   420,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     422,   423,   424,   424,   425,   425,   426,   427,   428,   429,
     430,   430,   431,   431,   432,   433,   434,   435,   436,   436,
     437,   437,   438,   439,   440,   441,   442,   442,   443,   444,
     444,   445,   445,   446,   447,   448,   449,   450,   450,   451,
     451,   452,   453,   454,   455,   456,   456,   457,   457,   458,
     459,   460,   461,   462,   462,   463,   463,   464,   465,   466,
     467,   468,   468,   469,   469,   470,   471,   472,   473,   474,
     474,   475,   475,   476,   477,   478,   479,   480,   480,   481,
     482,   482,   483,   483,   484,   485,   486,   487,   488,   489,
     489,   490,   490,   491,   492,   493,   493,   494,   495,   496,
     497,   497,   498,   498,   498,   499,   499,   500,   500,   501,
     502,   502,   503,   503,   504,   505,   506,   506,   507,   507,
     507,   507,   507,   508,   509,   510,   511,   511,   512,   512,
     513,   514,   515,   516,   517,   518,   518,   519,   519,   520,
     521,   522,   523,   524,   525,   525,   526,   526,   527,   528,
     529,   530,   531,   531,   532,   533,   534,   535,   536,   537,
     537,   538,   538,   539,   540,   541,   541,   542,   543,   544,
     545,   545,   546,   546,   546,   547,   547,   548,   548,   549,
     550,   550,   551,   551,   552,   553,   554,   554,   555,   555,
     556,   557,   558,   558,   559,   559,   560,   561,   562,   563,
     564,   565,   565,   566,   566,   567,   568,   569,   569,   570,
     571,   572,   573,   573,   574,   574,   574,   575,   575,   576,
     576,   577,   578,   578,   579,   579,   580,   581,   582,   582,
     583,   583,   583,   583,   583,   583,   583,   583,   583,   583,
     583,   583,   583,   583,   583,   584,   585,   586,   586,   587,
     587,   588,   588,   589,   590,   591,   592,   593,   594,   594,
     595,   595,   596,   597,   598,   599,   600,   601,   601,   602,
     602,   603,   604,   604,   605,   606,   607,   608,   608,   609,
     609,   610,   611,   612,   613,   613,   614,   614,   615,   616,
     617,   618,   618,   619,   619,   620,   621,   622,   623,   623,
     624,   624,   625,   626,   627,   628,   629,   629,   630,   630,
     631,   632,   632,   633,   634,   635,   636,   637,   637,   638,
     638,   639,   640,   640,   641,   642,   643,   644,   645,   645,
     646,   646,   647,   648,   648,   649,   650,   651,   652,   653,
     653,   654,   654,   655,   656,   656,   657,   658,   659,   660,
     661,   661,   662,   662,   663,   664,   665,   666,   667,   667,
     668,   668,   669,   670,   671,   672,   673,   673,   674,   674,
     675,   676,   676,   677,   678,   679,   680,   681,   681,   682,
     682,   683,   684,   685,   685,   686,   687,   688,   689,   689,
     690,   690,   690,   691,   691,   692,   692,   693,   694,   695,
     695,   696,   696,   696,   697,   697,   698,   699,   700,   701,
     701,   702,   703,   704,   704,   705,   705,   706,   707,   708,
     709,   709,   710,   711,   712,   712,   713,   713,   714,   715,
     716,   716,   717,   718,   719,   720,   720,   721,   721,   721,
     722,   722,   723,   723,   724,   725,   726,   726,   727,   727,
     728,   729,   730,   730,   731,   732,   733,   734,   734,   735,
     735,   735,   736,   736,   737,   737,   738,   739,   739,   740,
     741,   742,   743,   743,   744,   745,   746,   746,   747,   748,
     749,   750,   750,   751,   752,   753,   753,   754,   755,   756,
     757,   757,   758,   759,   760,   760,   761,   762,   763,   764,
     764,   765,   766,   767,   767,   768,   769,   770,   771,   771,
     772,   773,   774,   774,   775,   776,   777,   778,   778,   779,
     780,   781,   781,   782,   783,   784,   785,   785,   786,   787,
     788,   788,   789,   790,   791,   792,   792,   793,   794,   795,
     795,   796,   796,   797,   798,   799,   799,   800,   801,   802,
     803,   803,   804,   804,   804,   805,   805,   806,   806,   807,
     808,   809,   809,   810,   810,   811,   812,   812,   813,   814,
     815,   816,   816,   817,   817,   817,   818,   818,   819,   819,
     820,   821,   821,   822,   823,   824,   825,   825,   826,   826,
     826,   826,   826,   826,   826,   826,   826,   826,   827,   827,
     828,   828,   829,   830,   830,   831,   831,   832,   833,   834,
     835,   835,   836,   836,   836,   836,   836,   837,   838,   838,
     839,   839,   840,   841,   842,   842,   843,   843,   844,   845,
     846,   847,   847,   848,   849,   850,   850,   851,   851,   852,
     853,   854,   854,   855,   856,   857,   858,   858,   859,   859,
     859,   860,   860,   861,   861,   862,   863,   864,   864,   865,
     865,   866,   867,   868,   868,   869,   870,   871,   872,   872,
     873,   873,   873,   873,   874,   874,   875,   875,   876,   877,
     877,   878,   879,   880,   881,   881,   882,   883,   884,   884,
     885,   886,   887,   888,   888,   889,   890,   891,   891,   892,
     893,   894,   895,   895,   896,   897,   898,   898,   899,   900,
     901,   902,   902,   903,   904,   905,   905,   906,   907,   908,
     909,   909,   910,   911,   912,   912,   913,   914,   915,   916,
     916,   917,   918,   919,   919,   920,   921,   922,   923,   923,
     924,   925,   926,   926,   927,   928,   929,   930,   930,   931,
     932,   933,   934,   934,   935,   935,   935,   935,   935,   935,
     935,   935,   935,   935,   936,   936,   937,   937,   938,   939,
     939,   940,   940,   941,   942,   943,   944,   944,   945,   945,
     945,   945,   945,   946,   947,   947,   948,   948,   949,   950,
     951,   951,   952,   952,   953,   954,   955,   956,   956,   957,
     958,   959,   959,   960,   960,   961,   962,   963,   963,   964,
     965,   966,   967,   967,   968,   968,   968,   969,   969,   970,
     970,   971,   972,   973,   973,   974,   974,   975,   976,   977,
     977,   978,   979,   980,   981,   981,   982,   982,   982,   982,
     983,   983,   984,   984,   985,   986,   986,   987,   988,   989,
     990,   990,   991,   992,   993,   993,   994,   995,   996,   997,
     997,   998,   999,  1000,  1000,  1001,  1002,  1003,  1004,  1004,
    1005,  1006,  1007,  1007,  1008,  1009,  1010,  1011,  1011,  1012,
    1013,  1014,  1014,  1015,  1016,  1017,  1018,  1018,  1019,  1020,
    1021,  1021,  1022,  1023,  1024,  1025,  1025,  1026,  1027,  1028,
    1028,  1029,  1030,  1031,  1032,  1032,  1033,  1034,  1035,  1035,
    1036,  1037,  1038,  1039,  1039,  1040,  1041,  1042,  1043,  1043,
    1044,  1044,  1044,  1044,  1044,  1044,  1044,  1044,  1044,  1044,
    1045,  1045,  1046,  1046,  1047,  1048,  1048,  1049,  1049,  1050,
    1051,  1052,  1053,  1053,  1054,  1054,  1054,  1054,  1054,  1055,
    1056,  1056,  1057,  1057,  1058,  1059,  1060,  1060,  1061,  1062,
    1063,  1063,  1064,  1065,  1066,  1067,  1067,  1068,  1068,  1068,
    1068,  1068,  1068,  1068,  1069,  1069,  1070,  1070,  1071,  1072,
    1073,  1073,  1074,  1075,  1075,  1076,  1076,  1077,  1078,  1079,
    1079,  1080,  1081,  1082,  1083,  1084,  1084,  1085,  1085,  1085,
    1086,  1087,  1088,  1089,  1089,  1090,  1091,  1091,  1092,  1093,
    1094,  1095,  1095,  1096,  1097,  1098,  1099,  1099,  1100,  1101,
    1102,  1103,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1112,  1113,  1114,  1115,  1116,  1116,  1117,  1118,
    1119,  1120,  1120,  1121,  1122,  1123,  1124,  1124,  1125,  1126,
    1127,  1128,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,
    1135,  1136,  1137,  1138,  1139,  1139,  1140,  1141,  1142,  1143,
    1143,  1144,  1145,  1146,  1147,  1147,  1148,  1149,  1150,  1151,
    1151,  1152,  1153,  1154,  1155,  1155,  1156,  1157,  1158,  1159,
    1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,
    1170,  1171,  1172,  1173,  1174,  1175,  1176,  1176,  1177,  1178,
    1179,  1180,  1180,  1181,  1181,  1181,  1182,  1182,  1183,  1184,
    1185,  1186,  1186,  1187,  1188,  1188,  1189,  1189,  1189,  1189,
    1190,  1191,  1192,  1192,  1193,  1194,  1195,  1196,  1196,  1197,
    1197,  1197,  1197,  1197,  1198,  1199,  1199,  1200,  1200,  1201,
    1202,  1203,  1203,  1204,  1204,  1205,  1206,  1207,  1207,  1208,
    1208,  1209,  1210,  1211,  1211,  1212,  1212,  1213,  1214,  1215,
    1215,  1216,  1216,  1217,  1218,  1218,  1219,  1219,  1220,  1221,
    1222,  1223,  1223,  1224,  1224,  1225,  1226,  1227,  1227,  1228,
    1228,  1229,  1230,  1231,  1232
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
#define YYPACT_NINF -1375
static const yytype_int16 yypact[] =
{
     298, -1375, -1375,    59,   -39,   126, -1375, -1375,   145,    98,
   -1375,   315, -1375,   372, -1375, -1375, -1375, -1375,   129,   381,
   -1375, -1375, -1375, -1375, -1375,   -39, -1375, -1375, -1375, -1375,
   -1375,   133,   384,   269, -1375, -1375, -1375, -1375,    -3,   385,
     145, -1375,   137,   414,     1, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375,   146,   467, -1375, -1375,   420, -1375,   433, -1375,   435,
   -1375,   150, -1375,   437, -1375,   440, -1375,   442, -1375,   444,
   -1375,   462, -1375,   167, -1375,   226, -1375,   251, -1375, -1375,
     265, -1375, -1375,   273, -1375, -1375,   277, -1375, -1375,   289,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375,   219,   470,    -6, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,   245,   275,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,    11, -1375,
     226, -1375, -1375,    32, -1375, -1375, -1375, -1375,    33, -1375,
   -1375, -1375, -1375,    43, -1375, -1375, -1375, -1375,   330,   477,
   -1375,    28, -1375, -1375, -1375, -1375,    29, -1375, -1375, -1375,
   -1375,    31, -1375, -1375, -1375, -1375,    27, -1375, -1375, -1375,
   -1375,    26, -1375, -1375, -1375, -1375,   339,   486, -1375, -1375,
     498, -1375,   121,   123,   140,   117,   136, -1375, -1375, -1375,
      84, -1375, -1375, -1375, -1375, -1375, -1375, -1375,   272,    54,
   -1375, -1375,   501, -1375,   226, -1375, -1375,   359,   369,   363,
     369,   375,   369,   386, -1375,   393, -1375, -1375, -1375, -1375,
     506, -1375, -1375, -1375,   319, -1375, -1375,   324, -1375, -1375,
     331,   418,    42, -1375, -1375, -1375, -1375, -1375, -1375,   341,
   -1375, -1375,   360, -1375, -1375,   366, -1375, -1375,   361, -1375,
   -1375,   335,   460,    22, -1375, -1375, -1375, -1375,   468,     9,
     415, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
     519,   300, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,   396,   216,
   -1375, -1375,    90, -1375,   521, -1375,   472, -1375,   466, -1375,
     466, -1375,   466, -1375,   466, -1375,   484, -1375,   484, -1375,
     484, -1375,   484, -1375,   466, -1375,   466, -1375,   465, -1375,
     226, -1375, -1375,    12, -1375, -1375, -1375, -1375,   523, -1375,
     529, -1375,   510, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
     529, -1375, -1375, -1375, -1375,   529, -1375, -1375, -1375, -1375,
   -1375,   500, -1375,   434, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375,   426, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375,   423, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375,   417,   446, -1375, -1375,   389, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375,   535, -1375,    10, -1375, -1375, -1375, -1375,   539,   564,
   -1375,   541,   570,   575,   579,   581,   547,   583, -1375,   585,
   -1375,   587, -1375,   589, -1375,   613, -1375,   615, -1375,   549,
     617, -1375,   619, -1375, -1375, -1375,   441,   525, -1375, -1375,
   -1375, -1375, -1375, -1375,   453, -1375,   557,   439, -1375,   457,
   -1375, -1375, -1375,   451, -1375, -1375,   481,   495, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375,   623,   419, -1375,   520,   429,
     611,   610,   614,   648,    17, -1375, -1375, -1375, -1375, -1375,
   -1375,   574,   655,   -43, -1375, -1375, -1375, -1375,   787,   -26,
   -1375, -1375, -1375, -1375,   507, -1375, -1375, -1375, -1375,   119,
   -1375, -1375, -1375, -1375,   -69, -1375, -1375, -1375, -1375,   788,
     -33, -1375, -1375, -1375, -1375,   -76, -1375, -1375, -1375, -1375,
     -35, -1375, -1375, -1375, -1375,    24, -1375, -1375, -1375, -1375,
      73, -1375, -1375, -1375, -1375,    58, -1375, -1375, -1375, -1375,
     789,   487, -1375, -1375, -1375, -1375,   533, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375,   639,   690, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375,   631,   419,   673, -1375, -1375,
     793,   795, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375,   608,   766, -1375,   638,
   -1375, -1375, -1375, -1375, -1375, -1375,   681, -1375, -1375, -1375,
     794,   796, -1375,   -30, -1375,   797, -1375,   798,   148, -1375,
   -1375,   522, -1375,   125, -1375,   -28,   799, -1375, -1375,    95,
   -1375, -1375, -1375, -1375,    64, -1375, -1375, -1375,    19, -1375,
   -1375, -1375,    34, -1375, -1375, -1375,    75, -1375,   109,   801,
   -1375,   800,   502, -1375, -1375, -1375,   698,   696, -1375, -1375,
   -1375, -1375,   647,   419,   704, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375,   803, -1375,   616,   778, -1375,   649, -1375,
   -1375,   808,   661, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375,   813, -1375, -1375, -1375,   814, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375,   653,   395, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375,   815, -1375, -1375, -1375,
   -1375,   656,   419,   712, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375,   802, -1375,   658, -1375, -1375,
     816,   636, -1375, -1375, -1375, -1375, -1375, -1375,   669,   665,
     790,   732,   702,   706, -1375, -1375,   822,   825,   826, -1375,
   -1375, -1375, -1375,   679,   726, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375,   660, -1375,   827,   642, -1375, -1375, -1375,
   -1375, -1375, -1375,   652,   650,   804, -1375, -1375, -1375,   680,
     790, -1375,   662, -1375, -1375, -1375, -1375,   829,   832,   835,
   -1375, -1375,   838, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
     654,   651,   806, -1375, -1375, -1375,   686,   804, -1375,   664,
   -1375, -1375,   672,   666,   668, -1375,   844,   524, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375,   482, -1375, -1375, -1375,
     692,   806, -1375,   674, -1375, -1375, -1375,   676,   678, -1375,
     845,   504, -1375, -1375, -1375, -1375, -1375,   675,   790,   694,
   -1375, -1375, -1375, -1375,   135, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375,   700,   708, -1375, -1375, -1375, -1375, -1375, -1375,
     128, -1375, -1375,   682,   684, -1375,   846,   503, -1375, -1375,
   -1375, -1375,   752,   710, -1375, -1375, -1375, -1375,   114, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375,   677,   671, -1375, -1375,
   -1375, -1375,   831,   689, -1375, -1375,   713,   711,   821, -1375,
   -1375,   714,   720, -1375, -1375, -1375, -1375, -1375,   691,   134,
     861,   863, -1375, -1375, -1375,   864, -1375,   693,   128, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375,   762,   716, -1375, -1375,
   -1375, -1375,   149, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
     687,   685, -1375, -1375, -1375, -1375, -1375, -1375,   721,   718,
     821, -1375, -1375,   728,   683, -1375, -1375, -1375, -1375, -1375,
     695,   134,   764,   860,   697,  -103, -1375, -1375, -1375, -1375,
   -1375, -1375,   722,   821, -1375,   699, -1375, -1375, -1375,   701,
     134,   724, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375,   868,   866, -1375,    91, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375,   729,   730,   821, -1375, -1375,
     688,   734, -1375, -1375, -1375, -1375, -1375,   703,   134,   705,
     211, -1375, -1375,   735,   821,   707, -1375, -1375, -1375,   709,
     378,   736, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375,   878,   543, -1375, -1375, -1375, -1375, -1375, -1375,   738,
     742, -1375, -1375, -1375,   740,   821,   715, -1375,   882,   744,
   -1375, -1375, -1375, -1375,   748, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375,   883, -1375, -1375, -1375, -1375, -1375, -1375,   885,
   -1375,   746,    67, -1375, -1375, -1375, -1375,   717,   259, -1375,
   -1375,   750,   821,   719, -1375, -1375, -1375,   723,   223,   754,
   -1375, -1375, -1375, -1375, -1375, -1375,   -80, -1375, -1375, -1375,
   -1375, -1375,   889, -1375,   890, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375,   756,   821,   725, -1375,   744, -1375,
   -1375, -1375, -1375,   758, -1375, -1375, -1375, -1375,   891,   892,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375,   727,   445,   888, -1375, -1375,   559, -1375, -1375,
   -1375, -1375,   731,   134, -1375,   757,   821,   733, -1375,   744,
   -1375, -1375, -1375, -1375, -1375,   760,   768, -1375,   770, -1375,
   -1375, -1375, -1375, -1375,   771, -1375, -1375,   -56, -1375, -1375,
   -1375, -1375,   895, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,   772,
     821,   737, -1375,   744, -1375, -1375, -1375, -1375,   774, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
     811,   776, -1375, -1375,   782, -1375, -1375,   896,   893,   899,
   -1375,   783,   821,   739, -1375,   744, -1375, -1375, -1375, -1375,
     785, -1375, -1375, -1375, -1375,   -55, -1375, -1375, -1375, -1375,
     900, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,   741,
     156,   780, -1375, -1375, -1375, -1375, -1375, -1375, -1375,   784,
     821,   743, -1375,   744, -1375, -1375, -1375, -1375,   786, -1375,
   -1375,   902,   745, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375,   812,   791, -1375, -1375,   782,   903, -1375,   792,   821,
     747, -1375,   744, -1375, -1375, -1375, -1375,   805, -1375, -1375,
     529,   529, -1375, -1375,   749,   337, -1375,   751,    18, -1375,
   -1375, -1375, -1375,   810,   821,   753, -1375,   744, -1375, -1375,
   -1375, -1375,   807, -1375, -1375, -1375, -1375, -1375, -1375,   818,
     809, -1375, -1375,   782,   913,  -109, -1375, -1375, -1375, -1375,
     914, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375,   817,   821,   755, -1375,   744, -1375, -1375, -1375, -1375,
     823, -1375, -1375,   917,     6, -1375, -1375, -1375, -1375,   898,
     556, -1375, -1375,   759,   337, -1375, -1375,   819,   821,   761,
   -1375,   744, -1375, -1375, -1375, -1375,   820, -1375, -1375, -1375,
   -1375,   824, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375,   744, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375,   828,   821,   763, -1375,   744, -1375, -1375, -1375,
   -1375,   830, -1375, -1375, -1375, -1375,   765,   337, -1375, -1375,
     -87,   529,   921, -1375, -1375,   821,   767, -1375,   744, -1375,
   -1375, -1375, -1375,   834, -1375, -1375,   920,   833, -1375,   925,
   -1375,   926,   927, -1375, -1375, -1375,   841, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375,   836,   821,   769,
   -1375,   744, -1375, -1375, -1375, -1375,   839, -1375, -1375, -1375,
   -1375, -1375,   837, -1375, -1375, -1375,   821,   773, -1375,   744,
   -1375, -1375, -1375, -1375,   840, -1375, -1375,   842, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,   928, -1375,
     775, -1375,   744, -1375, -1375, -1375, -1375,   843, -1375, -1375,
   -1375, -1375,   848,   931,   933, -1375, -1375, -1375,   821,   777,
   -1375,   744, -1375, -1375, -1375, -1375,   849, -1375, -1375, -1375,
     779, -1375,   744, -1375, -1375, -1375, -1375,   847, -1375, -1375,
   -1375, -1375, -1375,   744, -1375, -1375, -1375, -1375,   850, -1375,
   -1375, -1375,   932,   934,   781, -1375,   744, -1375, -1375, -1375,
   -1375,   851, -1375, -1375,   744, -1375, -1375, -1375, -1375,   852,
   -1375, -1375,   853, -1375, -1375, -1375, -1375,   744, -1375, -1375,
   -1375, -1375,   854, -1375, -1375,   855, -1375, -1375, -1375,   858,
   -1375, -1375, -1375, -1375
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,   907, -1375,
     908, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,   881,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375,   548, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375,   856, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
     474, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375,   857, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,   382, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375,   659, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375,   336, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375,   321, -1375, -1375, -1375, -1375, -1375, -1375, -1375,   314,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375,   313, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375,   310, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375,   302, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375,   304, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375,    89, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,    35,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375,  -451, -1084, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375,  -231, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
    -443, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375,    62, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375,    -7, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,  -300,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375,    13, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375,   -58, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,  -375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375,    50, -1375, -1375, -1375,
   -1375, -1375,  -123, -1375, -1375, -1375, -1375,  -458,  -477,  -506,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1042, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375,  -148, -1375, -1375, -1375,
   -1088, -1375, -1375, -1375, -1375, -1375,  -993, -1375, -1375, -1374,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375,  -482, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1041, -1375, -1375, -1375, -1375,
   -1375, -1375, -1040, -1375, -1375, -1375, -1373, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375,  -181, -1375, -1375, -1375,  -481, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375,  -842, -1375,  -975, -1086,
   -1375, -1375,  -814, -1375, -1375, -1375,  -139, -1375,   -98,     0,
   -1375, -1375,  -797, -1375, -1196, -1282, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375,  -358,  -369, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1095, -1375, -1375, -1375,
   -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375, -1375,
   -1375
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     236,   471,   468,   835,   596,   600,  1211,   470,  1075,   895,
    1537,   241,  1396,   859,   499,  1066,   454,   395,  1157,  1168,
    1169,  1487,  1489,   462,   463,   482,   391,  1108,  1287,   646,
     269,   266,   257,   260,   650,   263,   242,   245,  1097,   654,
    1251,  1375,  1257,   491,   492,   493,   382,   248,  1087,   364,
     621,   369,  1369,  1417,  1087,   637,   631,   233,  1014,     6,
     627,   633,   591,   621,   233,  1143,   635,   634,   643,   234,
    1087,   924,  1134,  1519,   215,  1088,   234,  1191,   593,   132,
     355,   622,   363,  1311,   368,   349,  1245,  1253,  1254,  1177,
    1552,  1554,   656,  1396,   703,  1597,   637,   658,   637,   216,
     626,   627,  1418,   627,   679,   680,   133,  1288,   711,   638,
     134,   217,   135,   647,   136,  1325,   137,  1334,   243,  1423,
    1218,   246,   258,  1289,  1359,   261,   392,   267,   270,   264,
     455,   422,   500,   249,   383,   352,   618,   615,   646,  1370,
      12,  1396,   650,  1593,  1595,  1276,   654,  1289,  1289,   353,
     637,   708,   940,   941,   708,   637,   708,  1262,   708,   216,
      14,  1323,  1327,  1328,   942,   637,   292,   719,  1388,   590,
     651,   217,   591,    17,   233,   590,  1024,     7,   591,   708,
     721,   708,  1430,   943,   592,   944,   234,   627,   593,   293,
     592,   738,   739,   801,   593,   637,   657,   945,   946,  1431,
    1304,   453,   627,   294,   627,   295,    30,   296,   717,   297,
    1413,   298,    41,   655,    86,   723,  1538,   299,   124,   300,
    1345,   301,   151,   302,   168,   303,   637,   304,  1151,   305,
     440,   306,   442,   307,   444,   940,   941,   713,   627,   691,
     196,  1352,   199,   697,   698,   699,  1172,   724,   627,   828,
     779,   780,   590,   632,   627,   591,   202,   233,  1451,   710,
    1152,  1153,  1154,  1155,   590,  1024,   943,   592,   944,   234,
     203,   593,  1118,  1119,   707,  1120,  1151,   627,   204,   592,
     945,   946,   205,   940,   941,  1381,  1256,  1477,  1271,  1272,
    1273,  1274,   929,  1117,   206,   930,  1118,  1119,   852,  1120,
     590,   991,   207,   591,   992,   233,  1242,  1243,  1152,  1153,
       1,     2,  1512,   741,   943,   592,   944,   234,   750,   593,
     433,   293,   434,   225,   435,    20,    21,  1406,   945,   946,
     412,   413,   414,   251,   446,   294,   448,   295,   595,   296,
     285,   297,   272,   298,  1048,    49,   286,  1049,   288,   299,
    1534,   300,   341,   301,    50,   302,    51,   303,    52,   304,
      53,   305,    54,   306,    55,   307,    56,   287,    57,   350,
      58,   289,    59,   360,    60,  1444,  1567,   785,   590,  1024,
     133,   591,    25,    26,   134,   365,   135,   796,   136,   370,
     137,    33,    34,   592,    44,    45,  1573,   593,  1186,  1187,
    1188,  1189,  1486,   371,  1470,   378,  1335,   396,   397,   398,
     399,  1585,   379,   812,   352,   233,   766,   767,   768,   590,
    1024,   380,   823,  1498,   127,   128,   381,   234,   353,  1505,
     153,   154,   836,  1608,   592,   385,  1211,   389,   678,  1186,
    1187,  1188,  1189,   158,   159,   163,   164,   171,   172,   847,
     176,   177,   181,   182,   186,   187,   386,  1029,  1030,   860,
     590,   388,  1151,   591,   387,   233,  1627,  1527,   390,   940,
     941,  1551,   191,   192,   394,   592,   886,   234,   419,   593,
     210,   211,   801,   896,  1638,   431,   590,   252,   253,   591,
     428,   233,   449,  1560,  1152,  1153,   273,   274,  1320,  1321,
     943,   592,   944,   234,   436,   593,   472,  1649,   280,   281,
     935,   343,   344,   466,   945,   946,   373,   374,   480,  1076,
    1077,   401,   402,   483,  1592,   737,  1662,   481,  1578,   407,
     408,   423,   424,   457,   458,   462,   463,  1670,  1109,  1110,
     474,   475,   487,  1438,   997,   494,   495,   502,  1673,   508,
    1601,   580,    50,   402,    51,   529,    52,   560,    53,   571,
      54,  1683,    55,   578,    56,   579,    57,   582,    58,  1686,
      59,   581,    60,  1033,   503,   504,  1144,  1145,  1163,  1170,
     509,   510,  1690,  1620,   778,   514,   515,   583,  1196,   519,
     520,   524,   525,   530,   531,   535,   536,   540,   541,   545,
     546,  1631,   475,    87,   604,    88,    89,    90,  1054,    91,
      92,    93,   605,    94,    95,    96,   612,    97,    98,    99,
     613,   100,   101,   550,   551,   555,   556,   561,   562,   566,
     567,   572,   573,   587,   588,   630,   627,   660,   661,   664,
     665,   674,   675,  1655,   608,  1098,  1252,  1255,   692,   693,
     709,   627,   727,   661,   614,  1112,  1281,   733,   734,   751,
     752,   620,  1113,   763,   764,  1116,   774,   775,   786,   787,
     813,   814,   837,   838,   861,   862,   869,   870,   874,   875,
     880,   881,   887,   888,   897,   898,   903,   904,   908,   909,
     914,   915,   967,   968,   972,   973,   619,   978,   979,  1005,
    1006,  1021,  1022,  1035,  1036,  1071,  1072,  1082,  1083,  1099,
    1100,  1104,  1105,  1139,  1140,  1146,  1147,  1178,  1179,  1183,
    1184,  1326,  1329,  1205,  1206,  1219,  1220,  1237,  1238,  1263,
    1264,  1346,  1347,  1268,  1269,  1305,  1306,  1315,  1316,  1337,
    1206,  1341,  1342,  1353,  1354,   670,  1232,  1382,  1383,  1407,
    1408,  1425,  1426,  1445,  1446,  1454,  1455,  1471,  1472,  1481,
    1482,  1491,  1492,  1506,  1507,  1528,  1529,  1541,  1542,  1546,
    1547,  1561,  1562,  1579,  1580,  1587,  1588,  1602,  1603,  1621,
    1622,   681,  1297,  1632,  1633,  1643,  1644,  1656,  1657,  1664,
    1665,  1677,  1678,   625,   636,   659,   682,   573,   683,   684,
     687,   700,   701,   665,   729,   705,   702,   712,   706,   725,
     726,   742,   740,   746,   756,   743,   757,   761,   762,   773,
     781,   792,   791,   797,   798,   807,   804,   801,   808,   809,
     782,   810,   805,   818,   811,   819,   824,   842,   806,   825,
     843,   831,   828,   844,   845,   852,   848,   855,   849,   866,
     879,   913,   977,   891,   920,  1360,   936,   925,   915,   984,
    1003,  1014,  1367,   998,  1031,   881,  1032,  1034,  1081,  1041,
     991,  1078,  1115,   987,  1017,  1010,  1114,   929,  1011,  1044,
     979,  1055,  1111,  1061,  1204,  1062,  1135,  1093,  1224,  1231,
    1233,  1129,  1298,  1299,  1313,  1314,  1336,  1130,  1376,  1087,
    1173,  1400,  1399,  1424,  1390,  1391,  1230,  1401,  1539,  1214,
    1453,  1465,  1158,  1488,  1490,  1258,  1210,  1497,  1067,  1392,
    1461,  1518,  1521,  1536,  1201,  1300,  1514,  1599,  1610,  1048,
    1348,  1612,  1363,    40,  1613,  1614,  1641,  1652,  1439,  1653,
    1675,  1377,  1676,   152,  1415,  1416,  1312,   123,  1235,  1414,
    1286,   584,   484,  1225,  1452,  1440,  1402,   671,   718,   704,
     714,   720,   722,  1288,   728,  1466,  1418,  1018,   420,  1478,
    1389,   730,   937,  1361,  1520,  1513,  1338,  1515,  1368,   999,
    1250,  1501,  1553,  1555,  1364,  1289,  1370,  1068,  1568,  1535,
    1556,  1393,  1523,  1136,  1056,   226,  1586,  1462,  1040,  1236,
    1640,     0,     0,  1574,  1609,  1628,     0,     0,     0,     0,
    1639,  1616,  1571,     0,     0,     0,     0,  1650,     0,  1663,
       0,  1671,  1674,     0,  1687,  1684,  1691,     0,     0,  1688,
    1500,  1692,  1479,  1480,  1693,  1594,  1596,  1615,     0,     0,
       0,  1629,     0,  1611,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1324,     0,     0,     0,     0,
       0,     0,  1522,  1651,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   342,     0,     0,     0,
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
     148,   370,   360,   800,   486,   486,  1090,   365,  1001,   851,
       4,   150,  1294,   827,     4,   990,     4,     8,  1060,  1060,
    1060,  1395,  1395,     6,     7,   394,     4,  1020,   108,   535,
       4,     4,     4,     4,   540,     4,     4,     4,  1013,   545,
    1128,  1237,  1128,   412,   413,   414,     4,     4,   157,   230,
      93,   232,   108,   108,   157,   131,   514,    46,    40,     0,
     129,   519,    44,    93,    46,  1058,   524,   136,   144,    58,
     157,   868,  1047,   182,    80,   178,    58,  1070,    60,    78,
     228,   124,   230,  1178,   232,   224,  1128,  1128,  1128,  1064,
    1464,  1464,   550,  1375,   124,   182,   131,   555,   131,   105,
     126,   129,   157,   129,   586,   586,   105,   187,   136,   142,
     109,   117,   111,   148,   113,  1203,   115,  1203,    86,  1315,
    1095,    88,    94,   203,  1219,    96,   104,   100,   102,    98,
     118,   312,   122,    90,    92,    45,   494,   120,   644,   195,
      14,  1423,   648,  1517,  1517,  1138,   652,   203,   203,    59,
     131,   628,    24,    25,   631,   131,   633,  1132,   635,   105,
      15,  1203,  1203,  1203,    36,   131,    82,   148,  1263,    41,
     146,   117,    44,    75,    46,    41,    42,   216,    44,   656,
     146,   658,    26,    55,    56,    57,    58,   129,    60,   105,
      56,   673,   673,    37,    60,   131,   138,    69,    70,    43,
    1175,   340,   129,   119,   129,   121,    77,   123,   144,   125,
    1305,   127,    79,   140,   217,   140,   210,   133,    81,   135,
    1213,   137,    76,   139,    74,   141,   131,   143,    17,   145,
     328,   147,   330,   149,   332,    24,    25,   142,   129,   608,
      73,  1216,    16,   612,   613,   614,  1060,   138,   129,    38,
     732,   732,    41,   134,   129,    44,     5,    46,  1353,   134,
      49,    50,    51,    52,    41,    42,    55,    56,    57,    58,
       5,    60,   205,   206,   126,   208,    17,   129,     5,    56,
      69,    70,     5,    24,    25,  1260,  1128,  1382,    65,    66,
      67,    68,   157,   202,     5,   160,   205,   206,    39,   208,
      41,   187,    83,    44,   190,    46,    47,    48,    49,    50,
      12,    13,  1407,   682,    55,    56,    57,    58,   687,    60,
     320,   105,   322,    78,   324,    10,    11,  1302,    69,    70,
      30,    31,    32,     3,   334,   119,   336,   121,   486,   123,
     219,   125,     3,   127,   195,    76,   223,   198,   231,   133,
    1445,   135,    80,   137,    85,   139,    87,   141,    89,   143,
      91,   145,    93,   147,    95,   149,    97,   227,    99,    10,
     101,   235,   103,    10,   105,  1350,  1471,   746,    41,    42,
     105,    44,    10,    11,   109,    10,   111,   756,   113,     3,
     115,    10,    11,    56,    10,    11,  1491,    60,    61,    62,
      63,    64,  1395,    10,  1379,    86,  1203,   398,   399,   400,
     401,  1506,    88,   782,    45,    46,    21,    22,    23,    41,
      42,    90,   791,  1398,    10,    11,     8,    58,    59,  1404,
      10,    11,   801,  1528,    56,    94,  1520,   102,   586,    61,
      62,    63,    64,    10,    11,    10,    11,    10,    11,   818,
      10,    11,    10,    11,    10,    11,    96,   939,   939,   828,
      41,   100,    17,    44,    98,    46,  1561,  1442,     8,    24,
      25,  1464,    10,    11,     6,    56,   845,    58,    82,    60,
      10,    11,    37,   852,  1579,    19,    41,    10,    11,    44,
      18,    46,    27,  1468,    49,    50,    10,    11,    53,    54,
      55,    56,    57,    58,    20,    60,     6,  1602,    10,    11,
     879,    10,    11,     3,    69,    70,    10,    11,    92,  1001,
    1001,   106,   107,   106,  1517,   673,  1621,   104,  1503,    10,
      11,    10,    11,    10,    11,     6,     7,  1632,  1020,  1020,
     106,   107,   153,  1340,   913,    10,    11,     8,  1643,     8,
    1525,   112,    85,   107,    87,     8,    89,     8,    91,   118,
      93,  1656,    95,   110,    97,     8,    99,   116,   101,  1664,
     103,   114,   105,   942,    10,    11,  1058,  1058,  1060,  1060,
      10,    11,  1677,  1558,   732,    10,    11,   106,  1070,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,  1576,   107,   218,    84,   220,   221,   222,   977,   224,
     225,   226,   183,   228,   229,   230,     6,   232,   233,   234,
       6,   236,   237,    10,    11,    10,    11,    10,    11,    10,
      11,   106,   107,    10,    11,   128,   129,   150,   151,   106,
     107,    10,    11,  1618,    33,  1014,  1128,  1128,    10,    11,
     128,   129,   150,   151,     6,  1024,  1138,    10,    11,    10,
      11,     6,  1031,    10,    11,  1034,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     156,   157,   200,   201,    10,    11,    10,    11,    10,    11,
     186,   187,    10,    11,    10,    11,   122,   194,   195,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,  1203,  1203,   180,   181,    10,    11,    10,    11,    10,
      11,  1213,  1213,    10,    11,    10,    11,    10,    11,   180,
     181,    10,    11,    10,    11,   106,  1115,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,   211,   212,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,   108,  1151,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,     6,     6,     6,     3,   107,     3,   191,
      34,   120,     8,   107,   106,     8,    10,     8,    10,     8,
      10,     8,   108,    35,     6,   199,   155,     4,     4,     4,
     108,   185,     6,   154,   159,     3,    94,    37,     3,     3,
      28,   152,   130,     6,   108,   193,   184,     8,   132,   189,
       8,   161,    38,     8,     6,    39,   192,   161,   197,   177,
       6,     6,     6,   161,   179,  1224,   156,   163,   187,   107,
      29,    40,  1231,   186,     3,   157,     3,     3,     8,   107,
     187,   107,     6,   163,   160,   162,     8,   157,   167,   163,
     195,   194,   158,   162,     6,   167,   198,   165,     6,     6,
       5,   162,     3,     3,     3,     3,     8,   167,     3,   157,
     165,     8,     6,     3,  1273,  1274,   158,     8,    10,   169,
       8,     8,  1060,  1395,  1395,   165,   178,  1398,   190,   108,
     108,     8,     8,     6,   188,   169,   108,     6,     8,   195,
     173,     6,   164,    25,     8,     8,     8,     6,   158,     6,
       8,   169,     8,    62,  1313,  1314,   188,    40,   202,   164,
     196,   477,   404,   209,   168,   171,   173,   575,   644,   623,
     639,   648,   652,   187,   662,   173,   157,   932,   309,   164,
     196,   667,   883,   213,  1425,   168,  1207,  1420,   207,   917,
    1128,   171,  1464,  1464,   214,   203,   195,   994,   168,   166,
     171,  1291,   175,  1051,   981,   139,   166,  1372,   948,  1122,
     158,    -1,    -1,   175,   170,   166,    -1,    -1,    -1,    -1,
     170,   175,   188,    -1,    -1,    -1,    -1,   174,    -1,   170,
      -1,   174,   172,    -1,   172,   174,   172,    -1,    -1,   176,
    1399,   176,  1390,  1391,   176,  1517,  1517,   196,    -1,    -1,
      -1,   204,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1203,    -1,    -1,    -1,    -1,
      -1,    -1,  1431,   215,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
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
       0,    12,    13,   403,   404,   405,     0,   216,   412,   413,
    1190,  1191,    14,   406,    15,   410,   411,    75,   414,   415,
      10,    11,  1192,  1193,  1194,    10,    11,   407,   408,   409,
      77,   500,   501,    10,    11,   416,   417,   418,  1195,  1196,
     412,    79,   548,   549,    10,    11,   502,   503,   504,    76,
      85,    87,    89,    91,    93,    95,    97,    99,   101,   103,
     105,   419,   420,   421,   422,   423,   428,   429,   434,   435,
     440,   441,   448,   449,   454,   455,   460,   461,   466,   467,
     472,   473,   478,   479,   486,   487,   217,   218,   220,   221,
     222,   224,   225,   226,   228,   229,   230,   232,   233,   234,
     236,   237,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,  1216,  1217,   410,    81,   576,   577,    10,    11,   550,
     551,   552,    78,   105,   109,   111,   113,   115,   505,   506,
     507,   508,   509,   515,   516,   522,   523,   529,   530,   534,
     535,    76,   421,    10,    11,   424,   425,   426,    10,    11,
     430,   431,   432,    10,    11,   436,   437,   438,    74,   442,
     443,    10,    11,   450,   451,   452,    10,    11,   456,   457,
     458,    10,    11,   462,   463,   464,    10,    11,   468,   469,
     470,    10,    11,   474,   475,   476,    73,   480,   481,    16,
     488,  1168,     5,     5,     5,     5,     5,    83,   692,   693,
      10,    11,   578,   579,   580,    80,   105,   117,   553,   554,
     555,   556,   557,   562,   563,    78,   507,   510,   511,   517,
     518,   524,   525,    46,    58,   531,  1098,  1099,  1100,  1101,
     536,  1168,     4,    86,   427,     4,    88,   433,     4,    90,
     439,     3,    10,    11,   444,   445,   446,     4,    94,   453,
       4,    96,   459,     4,    98,   465,     4,   100,   471,     4,
     102,   477,     3,    10,    11,   482,   483,   484,  1187,  1188,
      10,    11,   489,   490,   491,   219,   223,   227,   231,   235,
     694,   695,    82,   105,   119,   121,   123,   125,   127,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   581,   582,
     583,   584,   585,   592,   593,   598,   599,   606,   607,   611,
     612,   616,   617,   621,   622,   626,   627,   634,   635,   642,
     643,   650,   651,   658,   659,   664,   665,   670,   671,   678,
     679,    80,   555,    10,    11,   558,   559,   560,   564,  1168,
      10,   513,    45,    59,   512,  1098,  1146,  1147,  1148,  1149,
      10,   520,   519,  1098,  1146,    10,   527,   526,  1098,  1146,
       3,    10,   532,    10,    11,   537,   538,   539,    86,    88,
      90,     8,     4,    92,   447,    94,    96,    98,   100,   102,
       8,     4,   104,   485,     6,     8,   398,   399,   400,   401,
    1189,   106,   107,   492,   493,   494,   495,    10,    11,   697,
     698,   699,    30,    31,    32,   696,  1159,  1165,  1175,    82,
     583,   586,  1146,    10,    11,   594,   595,   596,    18,   600,
    1163,    19,  1171,  1171,  1171,  1171,    20,   628,  1170,   636,
    1170,   644,  1170,   652,  1170,   660,  1171,   666,  1171,    27,
     672,  1172,   680,  1168,     4,   118,   561,    10,    11,   565,
     566,   567,     6,     7,   514,  1186,     3,   521,  1186,   528,
    1186,  1187,     6,   533,   106,   107,   540,   541,   542,   543,
      92,   104,  1187,   106,   494,   496,   497,   153,   700,   701,
     702,  1187,  1187,  1187,    10,    11,   587,   588,   589,     4,
     122,   597,     8,    10,    11,   601,   602,   603,     8,    10,
      11,   608,   609,   610,    10,    11,   613,   614,   615,    10,
      11,   618,   619,   620,    10,    11,   623,   624,   625,     8,
      10,    11,   629,   630,   631,    10,    11,   637,   638,   639,
      10,    11,   645,   646,   647,    10,    11,   653,   654,   655,
      10,    11,   661,   662,   663,    10,    11,   667,   668,   669,
       8,    10,    11,   673,   674,   675,    10,    11,   681,   682,
     683,   118,   106,   107,   568,   569,   570,   571,   110,     8,
     112,   114,   116,   106,   542,   544,   545,    10,    11,   499,
      41,    44,    56,    60,   498,  1098,  1119,  1120,  1121,  1122,
    1150,  1151,  1152,  1153,    84,   183,   839,   840,    33,   703,
     704,  1169,     6,     6,     6,   120,   590,   591,  1186,   122,
       6,    93,   124,   604,   605,     6,   126,   129,  1079,  1080,
     128,  1079,   134,  1079,   136,  1079,     6,   131,   142,   632,
     633,  1081,  1082,   144,   640,   641,  1081,   148,   648,   649,
    1081,   146,   656,   657,  1081,   140,  1079,   138,  1079,     6,
     150,   151,   676,   677,   106,   107,   684,   685,   686,   687,
     106,   570,   572,   573,    10,    11,   547,   546,  1098,  1119,
    1150,   108,     3,     3,   191,   948,   949,    34,   841,   842,
    1167,  1187,    10,    11,   705,   706,   707,  1187,  1187,  1187,
     120,     8,    10,   124,   605,     8,    10,   126,  1080,   128,
     134,   136,     8,   142,   633,  1083,  1084,   144,   641,   148,
     649,   146,   657,   140,   138,     8,    10,   150,   677,   106,
     686,   688,   689,    10,    11,   575,   574,  1098,  1119,  1150,
     108,  1187,     8,   199,  1057,  1058,    35,   950,   951,  1166,
    1187,    10,    11,   843,   844,   845,     6,   155,   708,   709,
     710,     4,     4,    10,    11,  1089,    21,    22,    23,  1085,
    1086,  1087,  1088,     4,    10,    11,   691,   690,  1098,  1119,
    1150,   108,    28,  1059,  1173,  1187,    10,    11,   952,   953,
     954,     6,   185,   846,   847,   848,  1187,   154,   159,   723,
     724,    37,   711,  1174,    94,   130,   132,     3,     3,     3,
     152,   108,  1187,    10,    11,  1060,  1061,  1062,     6,   193,
     955,   956,   957,  1187,   184,   189,   861,   862,    38,   849,
    1164,   161,   737,   738,   725,  1174,  1187,    10,    11,   712,
     713,   714,     8,     8,     8,     6,  1063,  1187,   192,   197,
     970,   971,    39,   958,  1158,   161,   875,   876,   863,  1164,
    1187,    10,    11,   850,   851,   852,   177,   792,   793,    10,
      11,   739,   740,   741,    10,    11,   726,   727,   728,     6,
     156,   157,   715,   716,   717,   718,  1187,   200,   201,  1064,
    1065,   161,   984,   985,   972,  1158,  1187,    10,    11,   959,
     960,   961,   930,    10,    11,   877,   878,   879,    10,    11,
     864,   865,   866,     6,   186,   187,   853,   854,   855,   856,
     179,   806,   807,   794,  1174,   163,   742,   743,   744,   157,
     160,   729,   730,   731,   732,  1187,   156,   717,   719,   720,
      24,    25,    36,    55,    57,    69,    70,  1066,  1067,  1068,
    1090,  1091,  1092,  1093,  1098,  1119,  1127,  1128,  1129,  1130,
    1134,  1135,  1136,  1137,  1150,  1162,  1039,    10,    11,   986,
     987,   988,    10,    11,   973,   974,   975,     6,   194,   195,
     962,   963,   964,   965,   107,   931,   932,   163,   880,   881,
     882,   187,   190,   867,   868,   869,   870,  1187,   186,   855,
     857,   858,   821,    29,   808,    10,    11,   795,   796,   797,
     162,   167,   750,   751,    40,   745,  1160,   160,   731,   733,
     734,    10,    11,   722,    42,   721,  1108,  1109,  1110,  1119,
    1150,     3,     3,  1187,     3,    10,    11,  1069,  1070,  1071,
    1068,   107,  1040,  1041,   163,   989,   990,   991,   195,   198,
     976,   977,   978,   979,  1187,   194,   964,   966,   967,   933,
     934,   162,   167,   888,   889,   883,  1160,   190,   869,   871,
     872,    10,    11,   860,   859,  1108,  1119,  1150,   107,   822,
     823,     8,    10,    11,   809,   810,   811,   157,   178,   798,
     799,   800,   801,   165,   757,   758,   752,  1160,  1187,    10,
      11,   746,   747,   748,    10,    11,   736,   735,  1108,  1119,
    1150,   158,  1187,  1187,     8,     6,  1187,   202,   205,   206,
     208,  1072,  1073,  1074,  1075,  1076,  1077,  1042,  1043,   162,
     167,   997,   998,   992,  1160,   198,   978,   980,   981,    10,
      11,   969,   968,  1108,  1119,  1150,    10,    11,   936,   937,
     938,    17,    49,    50,    51,    52,   935,  1090,  1098,  1102,
    1103,  1104,  1105,  1119,  1123,  1124,  1125,  1126,  1127,  1134,
    1150,  1161,  1164,   165,   895,   896,   890,  1160,    10,    11,
     884,   885,   886,    10,    11,   874,    61,    62,    63,    64,
     873,  1108,  1111,  1112,  1113,  1114,  1119,  1138,  1139,  1140,
    1141,   188,   824,   825,     6,   180,   181,   812,   813,   814,
     178,   800,   802,   803,   169,   764,   765,   759,  1160,    10,
      11,   753,   754,   755,     6,   209,   749,  1218,  1219,  1226,
     158,     6,  1187,     5,  1078,   202,  1074,    10,    11,  1045,
    1046,  1047,    47,    48,  1044,  1090,  1094,  1095,  1096,  1097,
    1098,  1102,  1119,  1127,  1134,  1150,  1158,  1161,   165,  1004,
    1005,   999,  1160,    10,    11,   993,   994,   995,    10,    11,
     983,    65,    66,    67,    68,   982,  1108,  1115,  1116,  1117,
    1118,  1119,  1142,  1143,  1144,  1145,   196,   108,   187,   203,
     939,   940,   941,   942,  1176,  1177,  1178,  1187,     3,     3,
     169,   902,   903,   897,  1160,    10,    11,   891,   892,   893,
     887,  1218,   188,     3,     3,    10,    11,   827,   828,   829,
      53,    54,   826,  1090,  1098,  1102,  1119,  1127,  1134,  1150,
    1154,  1155,  1156,  1157,  1161,  1174,     8,   180,   813,   815,
     816,    10,    11,   805,   804,  1108,  1119,  1150,   173,   771,
     772,   766,  1160,    10,    11,   760,   761,   762,   756,  1218,
    1187,   213,  1230,   164,   214,  1220,  1221,  1187,   207,   108,
     195,  1048,  1049,  1050,  1051,  1176,     3,   169,  1011,  1012,
    1006,  1160,    10,    11,  1000,  1001,  1002,   996,  1218,   196,
    1187,  1187,   108,   941,   943,   944,  1177,  1179,  1180,     6,
       8,     8,   173,   909,   910,   904,  1160,    10,    11,   898,
     899,   900,   894,  1218,   164,  1187,  1187,   108,   157,   830,
     831,   832,   833,  1176,     3,    10,    11,   818,   819,   820,
      26,    43,   817,  1106,  1107,  1131,  1132,  1133,  1174,   158,
     171,   778,   779,   773,  1160,    10,    11,   767,   768,   769,
     763,  1218,   168,     8,    10,    11,  1227,  1228,  1229,  1222,
    1223,   108,  1050,  1052,  1053,     8,   173,  1018,  1019,  1013,
    1160,    10,    11,  1007,  1008,  1009,  1003,  1218,   164,  1186,
    1186,    10,    11,   946,   947,   945,  1108,  1111,  1119,  1138,
    1150,    10,    11,  1182,  1183,  1184,  1098,  1150,  1160,  1181,
    1187,   171,   916,   917,   911,  1160,    10,    11,   905,   906,
     907,   901,  1218,   168,   108,   832,   834,   835,     8,   182,
     799,     8,  1187,   175,   785,   786,   780,  1160,    10,    11,
     774,   775,   776,   770,  1218,   166,     6,     4,   210,    10,
    1225,   211,   212,  1224,  1231,  1232,    10,    11,  1055,  1056,
    1054,  1108,  1111,  1119,  1138,  1150,   171,  1025,  1026,  1020,
    1160,    10,    11,  1014,  1015,  1016,  1010,  1218,   168,  1187,
    1187,   188,  1185,  1218,   175,   923,   924,   918,  1160,    10,
      11,   912,   913,   914,   908,  1218,   166,    10,    11,   837,
     838,   836,  1108,  1111,  1119,  1138,  1150,   182,  1186,     6,
     787,  1160,    10,    11,   781,   782,   783,   777,  1218,   170,
       8,   210,     6,     8,     8,   196,   175,  1032,  1033,  1027,
    1160,    10,    11,  1021,  1022,  1023,  1017,  1218,   166,   204,
     925,  1160,    10,    11,   919,   920,   921,   915,  1218,   170,
     158,     8,  1187,    10,    11,   788,   789,   790,   784,  1218,
     174,   215,     6,     6,  1034,  1160,    10,    11,  1028,  1029,
    1030,  1024,  1218,   170,    10,    11,   926,   927,   928,   922,
    1218,   174,   791,  1218,   172,     8,     8,    10,    11,  1035,
    1036,  1037,  1031,  1218,   174,   929,  1218,   172,   176,  1038,
    1218,   172,   176,   176
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
std::cout << "expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter << std::endl;
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
std::cout << "IntVec: expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter + osglData->osglMult << std::endl;
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
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1233:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1234:

    {    
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


