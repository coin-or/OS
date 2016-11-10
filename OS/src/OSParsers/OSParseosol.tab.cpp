
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

#define DEBUG

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
     NUMBEROFOTHERMATRIXPROGRAMMINGOPTIONSATT = 294,
     NUMBEROFOTHERMATRIXVARIABLEOPTIONSATT = 295,
     NUMBEROFOTHERMATRIXOBJECTIVEOPTIONSATT = 296,
     NUMBEROFOTHERMATRIXCONSTRAINTOPTIONSATT = 297,
     NUMBEROFSOLVEROPTIONSATT = 298,
     NUMBEROFOTHEROPTIONSATT = 299,
     NUMBEROFSOSATT = 300,
     SOSIDXATT = 301,
     GROUPWEIGHTATT = 302,
     INSTANCELOCATIONSTART = 303,
     INSTANCELOCATIONEND = 304,
     SOLVERTOINVOKESTART = 305,
     SOLVERTOINVOKEEND = 306,
     LICENSESTART = 307,
     LICENSEEND = 308,
     USERNAMESTART = 309,
     USERNAMEEND = 310,
     PASSWORDSTART = 311,
     PASSWORDEND = 312,
     CONTACTSTART = 313,
     CONTACTEND = 314,
     MINDISKSPACESTART = 315,
     MINDISKSPACEEND = 316,
     MINMEMORYSTART = 317,
     MINMEMORYEND = 318,
     MINCPUSPEEDSTART = 319,
     MINCPUSPEEDEND = 320,
     MINCPUNUMBERSTART = 321,
     MINCPUNUMBEREND = 322,
     SERVICETYPESTART = 323,
     SERVICETYPEEND = 324,
     MAXTIMESTART = 325,
     MAXTIMEEND = 326,
     REQUESTEDSTARTTIMESTART = 327,
     REQUESTEDSTARTTIMEEND = 328,
     DEPENDENCIESSTART = 329,
     DEPENDENCIESEND = 330,
     PATHSTART = 331,
     PATHEND = 332,
     PATHPAIRSTART = 333,
     PATHPAIREND = 334,
     REQUIREDDIRECTORIESSTART = 335,
     REQUIREDDIRECTORIESEND = 336,
     REQUIREDFILESSTART = 337,
     REQUIREDFILESEND = 338,
     DIRECTORIESTOMAKESTART = 339,
     DIRECTORIESTOMAKEEND = 340,
     FILESTOMAKESTART = 341,
     FILESTOMAKEEND = 342,
     DIRECTORIESTODELETESTART = 343,
     DIRECTORIESTODELETEEND = 344,
     FILESTODELETESTART = 345,
     FILESTODELETEEND = 346,
     INPUTDIRECTORIESTOMOVESTART = 347,
     INPUTDIRECTORIESTOMOVEEND = 348,
     INPUTFILESTOMOVESTART = 349,
     INPUTFILESTOMOVEEND = 350,
     OUTPUTDIRECTORIESTOMOVESTART = 351,
     OUTPUTDIRECTORIESTOMOVEEND = 352,
     OUTPUTFILESTOMOVESTART = 353,
     OUTPUTFILESTOMOVEEND = 354,
     PROCESSESTOKILLSTART = 355,
     PROCESSESTOKILLEND = 356,
     PROCESSSTART = 357,
     PROCESSEND = 358,
     INITIALVARIABLEVALUESSTART = 359,
     INITIALVARIABLEVALUESEND = 360,
     INITIALVARIABLEVALUESSTRINGSTART = 361,
     INITIALVARIABLEVALUESSTRINGEND = 362,
     INITIALBASISSTATUSSTART = 363,
     INITIALBASISSTATUSEND = 364,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 365,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 366,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 367,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 368,
     SOSSTART = 369,
     SOSEND = 370,
     INITIALOBJECTIVEVALUESSTART = 371,
     INITIALOBJECTIVEVALUESEND = 372,
     INITIALOBJECTIVEBOUNDSSTART = 373,
     INITIALOBJECTIVEBOUNDSEND = 374,
     INITIALCONSTRAINTVALUESSTART = 375,
     INITIALCONSTRAINTVALUESEND = 376,
     INITIALDUALVALUESSTART = 377,
     INITIALDUALVALUESEND = 378,
     INITIALMATRIXVARIABLEVALUESSTART = 379,
     INITIALMATRIXVARIABLEVALUESEND = 380,
     SOLVEROPTIONSSTART = 381,
     SOLVEROPTIONSEND = 382,
     SOLVEROPTIONSTART = 383,
     SOLVEROPTIONEND = 384,
     OTHEROPTIONSSTART = 385,
     OTHEROPTIONSEND = 386,
     HEADERSTART = 387,
     HEADEREND = 388,
     FILENAMESTART = 389,
     FILENAMEEND = 390,
     FILENAMEEMPTY = 391,
     FILENAMESTARTANDEND = 392,
     FILESOURCESTART = 393,
     FILESOURCEEND = 394,
     FILESOURCEEMPTY = 395,
     FILESOURCESTARTANDEND = 396,
     FILEDESCRIPTIONSTART = 397,
     FILEDESCRIPTIONEND = 398,
     FILEDESCRIPTIONEMPTY = 399,
     FILEDESCRIPTIONSTARTANDEND = 400,
     FILECREATORSTART = 401,
     FILECREATOREND = 402,
     FILECREATOREMPTY = 403,
     FILECREATORSTARTANDEND = 404,
     FILELICENCESTART = 405,
     FILELICENCEEND = 406,
     FILELICENCEEMPTY = 407,
     FILELICENCESTARTANDEND = 408,
     INDEXESSTART = 409,
     INDEXESEND = 410,
     VALUESSTART = 411,
     VALUESEND = 412,
     NONZEROSSTART = 413,
     NONZEROSEND = 414,
     ELSTART = 415,
     ELEND = 416,
     ENUMERATIONSTART = 417,
     ENUMERATIONEND = 418,
     ITEMEMPTY = 419,
     ITEMSTART = 420,
     ITEMEND = 421,
     ITEMSTARTANDEND = 422,
     BASE64START = 423,
     BASE64END = 424,
     NUMBEROFELATT = 425,
     NUMBEROFENUMERATIONSATT = 426,
     NUMBEROFITEMSATT = 427,
     EMPTYCATEGORYATT = 428,
     CATEGORYATT = 429,
     EMPTYDESCRIPTIONATT = 430,
     DESCRIPTIONATT = 431,
     EMPTYSOLVERATT = 432,
     SOLVERATT = 433,
     EMPTYNAMEATT = 434,
     NAMEATT = 435,
     EMPTYTYPEATT = 436,
     TYPEATT = 437,
     EMPTYENUMTYPEATT = 438,
     ENUMTYPEATT = 439,
     EMPTYSHAPEATT = 440,
     SHAPEATT = 441,
     EMPTYUNITATT = 442,
     UNITATT = 443,
     EMPTYVALUEATT = 444,
     VALUEATT = 445,
     EMPTYVALUETYPEATT = 446,
     VALUETYPEATT = 447,
     EMPTYCONTYPEATT = 448,
     CONTYPEATT = 449,
     EMPTYOBJTYPEATT = 450,
     OBJTYPEATT = 451,
     EMPTYVARTYPEATT = 452,
     VARTYPEATT = 453,
     EMPTYMATRIXCONTYPEATT = 454,
     MATRIXCONTYPEATT = 455,
     EMPTYMATRIXOBJTYPEATT = 456,
     MATRIXOBJTYPEATT = 457,
     EMPTYMATRIXVARTYPEATT = 458,
     MATRIXVARTYPEATT = 459,
     EMPTYMATRIXTYPEATT = 460,
     MATRIXTYPEATT = 461,
     EMPTYSYMMETRYATT = 462,
     SYMMETRYATT = 463,
     EMPTYROWMAJORATT = 464,
     ROWMAJORATT = 465,
     EMPTYBASETRANSPOSEATT = 466,
     BASETRANSPOSEATT = 467,
     NUMBEROFBLOCKSATT = 468,
     NUMBEROFCOLUMNSATT = 469,
     NUMBEROFROWSATT = 470,
     NUMBEROFMATRICESATT = 471,
     NUMBEROFVALUESATT = 472,
     NUMBEROFCONSTRAINTSATT = 473,
     NUMBEROFCONATT = 474,
     NUMBEROFCONIDXATT = 475,
     NUMBEROFOBJECTIVESATT = 476,
     NUMBEROFOBJATT = 477,
     NUMBEROFOBJIDXATT = 478,
     NUMBEROFVARIABLESATT = 479,
     NUMBEROFVARATT = 480,
     NUMBEROFVARIDXATT = 481,
     NUMBEROFMATRIXCONATT = 482,
     NUMBEROFMATRIXOBJATT = 483,
     NUMBEROFMATRIXVARATT = 484,
     BASEMATRIXIDXATT = 485,
     TARGETMATRIXFIRSTROWATT = 486,
     TARGETMATRIXFIRSTCOLATT = 487,
     BASEMATRIXSTARTROWATT = 488,
     BASEMATRIXSTARTCOLATT = 489,
     BASEMATRIXENDROWATT = 490,
     BASEMATRIXENDCOLATT = 491,
     SCALARMULTIPLIERATT = 492,
     BLOCKROWIDXATT = 493,
     BLOCKCOLIDXATT = 494,
     REATT = 495,
     IMATT = 496,
     MATRIXVARIDXATT = 497,
     MATRIXOBJIDXATT = 498,
     MATRIXCONIDXATT = 499,
     IDXATT = 500,
     INCRATT = 501,
     MULTATT = 502,
     SIZEOFATT = 503,
     COEFATT = 504,
     CONSTANTATT = 505,
     MATRICESSTART = 506,
     MATRICESEND = 507,
     MATRIXSTART = 508,
     MATRIXEND = 509,
     BASEMATRIXEND = 510,
     BASEMATRIXSTART = 511,
     BLOCKSSTART = 512,
     BLOCKSEND = 513,
     BLOCKSTART = 514,
     BLOCKEND = 515,
     COLOFFSETSTART = 516,
     COLOFFSETEND = 517,
     ROWOFFSETSTART = 518,
     ROWOFFSETEND = 519,
     ELEMENTSSTART = 520,
     ELEMENTSEND = 521,
     CONSTANTELEMENTSSTART = 522,
     CONSTANTELEMENTSEND = 523,
     COMPLEXELEMENTSSTART = 524,
     COMPLEXELEMENTSEND = 525,
     VARREFERENCEELEMENTSSTART = 526,
     VARREFERENCEELEMENTSEND = 527,
     LINEARELEMENTSSTART = 528,
     LINEARELEMENTSEND = 529,
     CONREFERENCEELEMENTSSTART = 530,
     CONREFERENCEELEMENTSEND = 531,
     OBJREFERENCEELEMENTSSTART = 532,
     OBJREFERENCEELEMENTSEND = 533,
     REALVALUEDEXPRESSIONSSTART = 534,
     REALVALUEDEXPRESSIONSSEND = 535,
     COMPLEXVALUEDEXPRESSIONSSTART = 536,
     COMPLEXVALUEDEXPRESSIONSSEND = 537,
     STRINGVALUEDELEMENTSSTART = 538,
     STRINGVALUEDELEMENTSEND = 539,
     STARTVECTORSTART = 540,
     STARTVECTOREND = 541,
     INDEXSTART = 542,
     INDEXEND = 543,
     VALUESTART = 544,
     VALUEEND = 545,
     VARIDXSTART = 546,
     VARIDXEND = 547,
     TRANSFORMATIONSTART = 548,
     TRANSFORMATIONEND = 549,
     MATRIXPROGRAMMINGSTART = 550,
     MATRIXPROGRAMMINGEND = 551,
     MATRIXVARIABLESSTART = 552,
     MATRIXVARIABLESEND = 553,
     MATRIXVARSTART = 554,
     MATRIXVAREND = 555,
     MATRIXOBJECTIVESSTART = 556,
     MATRIXOBJECTIVESEND = 557,
     MATRIXOBJSTART = 558,
     MATRIXOBJEND = 559,
     MATRIXCONSTRAINTSSTART = 560,
     MATRIXCONSTRAINTSEND = 561,
     MATRIXCONSTART = 562,
     MATRIXCONEND = 563,
     CONSTART = 564,
     CONEND = 565,
     CONSTRAINTSSTART = 566,
     CONSTRAINTSEND = 567,
     OBJSTART = 568,
     OBJEND = 569,
     OBJECTIVESSTART = 570,
     OBJECTIVESEND = 571,
     VARSTART = 572,
     VAREND = 573,
     VARIABLESSTART = 574,
     VARIABLESEND = 575,
     GENERALSTART = 576,
     GENERALEND = 577,
     SYSTEMSTART = 578,
     SYSTEMEND = 579,
     SERVICESTART = 580,
     SERVICEEND = 581,
     JOBSTART = 582,
     JOBEND = 583,
     OPTIMIZATIONSTART = 584,
     OPTIMIZATIONEND = 585,
     ATEQUALITYSTART = 586,
     ATEQUALITYEND = 587,
     ATLOWERSTART = 588,
     ATLOWEREND = 589,
     ATUPPERSTART = 590,
     ATUPPEREND = 591,
     BASICSTART = 592,
     BASICEND = 593,
     ISFREESTART = 594,
     ISFREEEND = 595,
     SUPERBASICSTART = 596,
     SUPERBASICEND = 597,
     UNKNOWNSTART = 598,
     UNKNOWNEND = 599,
     SERVICEURISTART = 600,
     SERVICEURIEND = 601,
     SERVICENAMESTART = 602,
     SERVICENAMEEND = 603,
     INSTANCENAMESTART = 604,
     INSTANCENAMEEND = 605,
     JOBIDSTART = 606,
     JOBIDEND = 607,
     OTHERSTART = 608,
     OTHEREND = 609,
     DUMMY = 610,
     NONLINEAREXPRESSIONSSTART = 611,
     NONLINEAREXPRESSIONSEND = 612,
     NUMBEROFNONLINEAREXPRESSIONS = 613,
     NLSTART = 614,
     NLEND = 615,
     MATRIXEXPRESSIONSSTART = 616,
     MATRIXEXPRESSIONSEND = 617,
     NUMBEROFEXPR = 618,
     EXPRSTART = 619,
     EXPREND = 620,
     NUMBEROFMATRIXTERMSATT = 621,
     MATRIXTERMSTART = 622,
     MATRIXTERMEND = 623,
     POWERSTART = 624,
     POWEREND = 625,
     PLUSSTART = 626,
     PLUSEND = 627,
     MINUSSTART = 628,
     MINUSEND = 629,
     DIVIDESTART = 630,
     DIVIDEEND = 631,
     LNSTART = 632,
     LNEND = 633,
     SQRTSTART = 634,
     SQRTEND = 635,
     SUMSTART = 636,
     SUMEND = 637,
     PRODUCTSTART = 638,
     PRODUCTEND = 639,
     EXPSTART = 640,
     EXPEND = 641,
     NEGATESTART = 642,
     NEGATEEND = 643,
     IFSTART = 644,
     IFEND = 645,
     SQUARESTART = 646,
     SQUAREEND = 647,
     COSSTART = 648,
     COSEND = 649,
     SINSTART = 650,
     SINEND = 651,
     VARIABLESTART = 652,
     VARIABLEEND = 653,
     ABSSTART = 654,
     ABSEND = 655,
     ERFSTART = 656,
     ERFEND = 657,
     MAXSTART = 658,
     MAXEND = 659,
     ALLDIFFSTART = 660,
     ALLDIFFEND = 661,
     MINSTART = 662,
     MINEND = 663,
     ESTART = 664,
     EEND = 665,
     PISTART = 666,
     PIEND = 667,
     TIMESSTART = 668,
     TIMESEND = 669,
     NUMBERSTART = 670,
     NUMBEREND = 671,
     MATRIXDETERMINANTSTART = 672,
     MATRIXDETERMINANTEND = 673,
     MATRIXTRACESTART = 674,
     MATRIXTRACEEND = 675,
     MATRIXTOSCALARSTART = 676,
     MATRIXTOSCALAREND = 677,
     MATRIXDIAGONALSTART = 678,
     MATRIXDIAGONALEND = 679,
     MATRIXDOTTIMESSTART = 680,
     MATRIXDOTTIMESEND = 681,
     MATRIXLOWERTRIANGLESTART = 682,
     MATRIXLOWERTRIANGLEEND = 683,
     MATRIXUPPERTRIANGLESTART = 684,
     MATRIXUPPERTRIANGLEEND = 685,
     MATRIXMERGESTART = 686,
     MATRIXMERGEEND = 687,
     MATRIXMINUSSTART = 688,
     MATRIXMINUSEND = 689,
     MATRIXNEGATESTART = 690,
     MATRIXNEGATEEND = 691,
     MATRIXPLUSSTART = 692,
     MATRIXPLUSEND = 693,
     MATRIXTIMESSTART = 694,
     MATRIXTIMESEND = 695,
     MATRIXPRODUCTSTART = 696,
     MATRIXPRODUCTEND = 697,
     MATRIXSCALARTIMESSTART = 698,
     MATRIXSCALARTIMESEND = 699,
     MATRIXSUBMATRIXATSTART = 700,
     MATRIXSUBMATRIXATEND = 701,
     MATRIXTRANSPOSESTART = 702,
     MATRIXTRANSPOSEEND = 703,
     MATRIXREFERENCESTART = 704,
     MATRIXREFERENCEEND = 705,
     IDENTITYMATRIXSTART = 706,
     IDENTITYMATRIXEND = 707,
     MATRIXINVERSESTART = 708,
     MATRIXINVERSEEND = 709,
     COMPLEXCONJUGATESTART = 710,
     COMPLEXCONJUGATEEND = 711,
     COMPLEXMINUSSTART = 712,
     COMPLEXMINUSEND = 713,
     COMPLEXNEGATESTART = 714,
     COMPLEXNEGATEEND = 715,
     COMPLEXNUMBERSTART = 716,
     COMPLEXNUMBEREND = 717,
     COMPLEXPLUSSTART = 718,
     COMPLEXPLUSEND = 719,
     COMPLEXSQUARESTART = 720,
     COMPLEXSQUAREEND = 721,
     COMPLEXSUMSTART = 722,
     COMPLEXSUMEND = 723,
     COMPLEXTIMESSTART = 724,
     COMPLEXTIMESEND = 725,
     CREATECOMPLEXSTART = 726,
     CREATECOMPLEXEND = 727,
     EMPTYINCLUDEDIAGONALATT = 728,
     INCLUDEDIAGONALATT = 729,
     EMPTYTRANSPOSEATT = 730,
     TRANSPOSEATT = 731,
     EMPTYIDATT = 732,
     IDATT = 733
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
#define NUMBEROFOTHERMATRIXPROGRAMMINGOPTIONSATT 294
#define NUMBEROFOTHERMATRIXVARIABLEOPTIONSATT 295
#define NUMBEROFOTHERMATRIXOBJECTIVEOPTIONSATT 296
#define NUMBEROFOTHERMATRIXCONSTRAINTOPTIONSATT 297
#define NUMBEROFSOLVEROPTIONSATT 298
#define NUMBEROFOTHEROPTIONSATT 299
#define NUMBEROFSOSATT 300
#define SOSIDXATT 301
#define GROUPWEIGHTATT 302
#define INSTANCELOCATIONSTART 303
#define INSTANCELOCATIONEND 304
#define SOLVERTOINVOKESTART 305
#define SOLVERTOINVOKEEND 306
#define LICENSESTART 307
#define LICENSEEND 308
#define USERNAMESTART 309
#define USERNAMEEND 310
#define PASSWORDSTART 311
#define PASSWORDEND 312
#define CONTACTSTART 313
#define CONTACTEND 314
#define MINDISKSPACESTART 315
#define MINDISKSPACEEND 316
#define MINMEMORYSTART 317
#define MINMEMORYEND 318
#define MINCPUSPEEDSTART 319
#define MINCPUSPEEDEND 320
#define MINCPUNUMBERSTART 321
#define MINCPUNUMBEREND 322
#define SERVICETYPESTART 323
#define SERVICETYPEEND 324
#define MAXTIMESTART 325
#define MAXTIMEEND 326
#define REQUESTEDSTARTTIMESTART 327
#define REQUESTEDSTARTTIMEEND 328
#define DEPENDENCIESSTART 329
#define DEPENDENCIESEND 330
#define PATHSTART 331
#define PATHEND 332
#define PATHPAIRSTART 333
#define PATHPAIREND 334
#define REQUIREDDIRECTORIESSTART 335
#define REQUIREDDIRECTORIESEND 336
#define REQUIREDFILESSTART 337
#define REQUIREDFILESEND 338
#define DIRECTORIESTOMAKESTART 339
#define DIRECTORIESTOMAKEEND 340
#define FILESTOMAKESTART 341
#define FILESTOMAKEEND 342
#define DIRECTORIESTODELETESTART 343
#define DIRECTORIESTODELETEEND 344
#define FILESTODELETESTART 345
#define FILESTODELETEEND 346
#define INPUTDIRECTORIESTOMOVESTART 347
#define INPUTDIRECTORIESTOMOVEEND 348
#define INPUTFILESTOMOVESTART 349
#define INPUTFILESTOMOVEEND 350
#define OUTPUTDIRECTORIESTOMOVESTART 351
#define OUTPUTDIRECTORIESTOMOVEEND 352
#define OUTPUTFILESTOMOVESTART 353
#define OUTPUTFILESTOMOVEEND 354
#define PROCESSESTOKILLSTART 355
#define PROCESSESTOKILLEND 356
#define PROCESSSTART 357
#define PROCESSEND 358
#define INITIALVARIABLEVALUESSTART 359
#define INITIALVARIABLEVALUESEND 360
#define INITIALVARIABLEVALUESSTRINGSTART 361
#define INITIALVARIABLEVALUESSTRINGEND 362
#define INITIALBASISSTATUSSTART 363
#define INITIALBASISSTATUSEND 364
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 365
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 366
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 367
#define SOSVARIABLEBRANCHINGWEIGHTSEND 368
#define SOSSTART 369
#define SOSEND 370
#define INITIALOBJECTIVEVALUESSTART 371
#define INITIALOBJECTIVEVALUESEND 372
#define INITIALOBJECTIVEBOUNDSSTART 373
#define INITIALOBJECTIVEBOUNDSEND 374
#define INITIALCONSTRAINTVALUESSTART 375
#define INITIALCONSTRAINTVALUESEND 376
#define INITIALDUALVALUESSTART 377
#define INITIALDUALVALUESEND 378
#define INITIALMATRIXVARIABLEVALUESSTART 379
#define INITIALMATRIXVARIABLEVALUESEND 380
#define SOLVEROPTIONSSTART 381
#define SOLVEROPTIONSEND 382
#define SOLVEROPTIONSTART 383
#define SOLVEROPTIONEND 384
#define OTHEROPTIONSSTART 385
#define OTHEROPTIONSEND 386
#define HEADERSTART 387
#define HEADEREND 388
#define FILENAMESTART 389
#define FILENAMEEND 390
#define FILENAMEEMPTY 391
#define FILENAMESTARTANDEND 392
#define FILESOURCESTART 393
#define FILESOURCEEND 394
#define FILESOURCEEMPTY 395
#define FILESOURCESTARTANDEND 396
#define FILEDESCRIPTIONSTART 397
#define FILEDESCRIPTIONEND 398
#define FILEDESCRIPTIONEMPTY 399
#define FILEDESCRIPTIONSTARTANDEND 400
#define FILECREATORSTART 401
#define FILECREATOREND 402
#define FILECREATOREMPTY 403
#define FILECREATORSTARTANDEND 404
#define FILELICENCESTART 405
#define FILELICENCEEND 406
#define FILELICENCEEMPTY 407
#define FILELICENCESTARTANDEND 408
#define INDEXESSTART 409
#define INDEXESEND 410
#define VALUESSTART 411
#define VALUESEND 412
#define NONZEROSSTART 413
#define NONZEROSEND 414
#define ELSTART 415
#define ELEND 416
#define ENUMERATIONSTART 417
#define ENUMERATIONEND 418
#define ITEMEMPTY 419
#define ITEMSTART 420
#define ITEMEND 421
#define ITEMSTARTANDEND 422
#define BASE64START 423
#define BASE64END 424
#define NUMBEROFELATT 425
#define NUMBEROFENUMERATIONSATT 426
#define NUMBEROFITEMSATT 427
#define EMPTYCATEGORYATT 428
#define CATEGORYATT 429
#define EMPTYDESCRIPTIONATT 430
#define DESCRIPTIONATT 431
#define EMPTYSOLVERATT 432
#define SOLVERATT 433
#define EMPTYNAMEATT 434
#define NAMEATT 435
#define EMPTYTYPEATT 436
#define TYPEATT 437
#define EMPTYENUMTYPEATT 438
#define ENUMTYPEATT 439
#define EMPTYSHAPEATT 440
#define SHAPEATT 441
#define EMPTYUNITATT 442
#define UNITATT 443
#define EMPTYVALUEATT 444
#define VALUEATT 445
#define EMPTYVALUETYPEATT 446
#define VALUETYPEATT 447
#define EMPTYCONTYPEATT 448
#define CONTYPEATT 449
#define EMPTYOBJTYPEATT 450
#define OBJTYPEATT 451
#define EMPTYVARTYPEATT 452
#define VARTYPEATT 453
#define EMPTYMATRIXCONTYPEATT 454
#define MATRIXCONTYPEATT 455
#define EMPTYMATRIXOBJTYPEATT 456
#define MATRIXOBJTYPEATT 457
#define EMPTYMATRIXVARTYPEATT 458
#define MATRIXVARTYPEATT 459
#define EMPTYMATRIXTYPEATT 460
#define MATRIXTYPEATT 461
#define EMPTYSYMMETRYATT 462
#define SYMMETRYATT 463
#define EMPTYROWMAJORATT 464
#define ROWMAJORATT 465
#define EMPTYBASETRANSPOSEATT 466
#define BASETRANSPOSEATT 467
#define NUMBEROFBLOCKSATT 468
#define NUMBEROFCOLUMNSATT 469
#define NUMBEROFROWSATT 470
#define NUMBEROFMATRICESATT 471
#define NUMBEROFVALUESATT 472
#define NUMBEROFCONSTRAINTSATT 473
#define NUMBEROFCONATT 474
#define NUMBEROFCONIDXATT 475
#define NUMBEROFOBJECTIVESATT 476
#define NUMBEROFOBJATT 477
#define NUMBEROFOBJIDXATT 478
#define NUMBEROFVARIABLESATT 479
#define NUMBEROFVARATT 480
#define NUMBEROFVARIDXATT 481
#define NUMBEROFMATRIXCONATT 482
#define NUMBEROFMATRIXOBJATT 483
#define NUMBEROFMATRIXVARATT 484
#define BASEMATRIXIDXATT 485
#define TARGETMATRIXFIRSTROWATT 486
#define TARGETMATRIXFIRSTCOLATT 487
#define BASEMATRIXSTARTROWATT 488
#define BASEMATRIXSTARTCOLATT 489
#define BASEMATRIXENDROWATT 490
#define BASEMATRIXENDCOLATT 491
#define SCALARMULTIPLIERATT 492
#define BLOCKROWIDXATT 493
#define BLOCKCOLIDXATT 494
#define REATT 495
#define IMATT 496
#define MATRIXVARIDXATT 497
#define MATRIXOBJIDXATT 498
#define MATRIXCONIDXATT 499
#define IDXATT 500
#define INCRATT 501
#define MULTATT 502
#define SIZEOFATT 503
#define COEFATT 504
#define CONSTANTATT 505
#define MATRICESSTART 506
#define MATRICESEND 507
#define MATRIXSTART 508
#define MATRIXEND 509
#define BASEMATRIXEND 510
#define BASEMATRIXSTART 511
#define BLOCKSSTART 512
#define BLOCKSEND 513
#define BLOCKSTART 514
#define BLOCKEND 515
#define COLOFFSETSTART 516
#define COLOFFSETEND 517
#define ROWOFFSETSTART 518
#define ROWOFFSETEND 519
#define ELEMENTSSTART 520
#define ELEMENTSEND 521
#define CONSTANTELEMENTSSTART 522
#define CONSTANTELEMENTSEND 523
#define COMPLEXELEMENTSSTART 524
#define COMPLEXELEMENTSEND 525
#define VARREFERENCEELEMENTSSTART 526
#define VARREFERENCEELEMENTSEND 527
#define LINEARELEMENTSSTART 528
#define LINEARELEMENTSEND 529
#define CONREFERENCEELEMENTSSTART 530
#define CONREFERENCEELEMENTSEND 531
#define OBJREFERENCEELEMENTSSTART 532
#define OBJREFERENCEELEMENTSEND 533
#define REALVALUEDEXPRESSIONSSTART 534
#define REALVALUEDEXPRESSIONSSEND 535
#define COMPLEXVALUEDEXPRESSIONSSTART 536
#define COMPLEXVALUEDEXPRESSIONSSEND 537
#define STRINGVALUEDELEMENTSSTART 538
#define STRINGVALUEDELEMENTSEND 539
#define STARTVECTORSTART 540
#define STARTVECTOREND 541
#define INDEXSTART 542
#define INDEXEND 543
#define VALUESTART 544
#define VALUEEND 545
#define VARIDXSTART 546
#define VARIDXEND 547
#define TRANSFORMATIONSTART 548
#define TRANSFORMATIONEND 549
#define MATRIXPROGRAMMINGSTART 550
#define MATRIXPROGRAMMINGEND 551
#define MATRIXVARIABLESSTART 552
#define MATRIXVARIABLESEND 553
#define MATRIXVARSTART 554
#define MATRIXVAREND 555
#define MATRIXOBJECTIVESSTART 556
#define MATRIXOBJECTIVESEND 557
#define MATRIXOBJSTART 558
#define MATRIXOBJEND 559
#define MATRIXCONSTRAINTSSTART 560
#define MATRIXCONSTRAINTSEND 561
#define MATRIXCONSTART 562
#define MATRIXCONEND 563
#define CONSTART 564
#define CONEND 565
#define CONSTRAINTSSTART 566
#define CONSTRAINTSEND 567
#define OBJSTART 568
#define OBJEND 569
#define OBJECTIVESSTART 570
#define OBJECTIVESEND 571
#define VARSTART 572
#define VAREND 573
#define VARIABLESSTART 574
#define VARIABLESEND 575
#define GENERALSTART 576
#define GENERALEND 577
#define SYSTEMSTART 578
#define SYSTEMEND 579
#define SERVICESTART 580
#define SERVICEEND 581
#define JOBSTART 582
#define JOBEND 583
#define OPTIMIZATIONSTART 584
#define OPTIMIZATIONEND 585
#define ATEQUALITYSTART 586
#define ATEQUALITYEND 587
#define ATLOWERSTART 588
#define ATLOWEREND 589
#define ATUPPERSTART 590
#define ATUPPEREND 591
#define BASICSTART 592
#define BASICEND 593
#define ISFREESTART 594
#define ISFREEEND 595
#define SUPERBASICSTART 596
#define SUPERBASICEND 597
#define UNKNOWNSTART 598
#define UNKNOWNEND 599
#define SERVICEURISTART 600
#define SERVICEURIEND 601
#define SERVICENAMESTART 602
#define SERVICENAMEEND 603
#define INSTANCENAMESTART 604
#define INSTANCENAMEEND 605
#define JOBIDSTART 606
#define JOBIDEND 607
#define OTHERSTART 608
#define OTHEREND 609
#define DUMMY 610
#define NONLINEAREXPRESSIONSSTART 611
#define NONLINEAREXPRESSIONSEND 612
#define NUMBEROFNONLINEAREXPRESSIONS 613
#define NLSTART 614
#define NLEND 615
#define MATRIXEXPRESSIONSSTART 616
#define MATRIXEXPRESSIONSEND 617
#define NUMBEROFEXPR 618
#define EXPRSTART 619
#define EXPREND 620
#define NUMBEROFMATRIXTERMSATT 621
#define MATRIXTERMSTART 622
#define MATRIXTERMEND 623
#define POWERSTART 624
#define POWEREND 625
#define PLUSSTART 626
#define PLUSEND 627
#define MINUSSTART 628
#define MINUSEND 629
#define DIVIDESTART 630
#define DIVIDEEND 631
#define LNSTART 632
#define LNEND 633
#define SQRTSTART 634
#define SQRTEND 635
#define SUMSTART 636
#define SUMEND 637
#define PRODUCTSTART 638
#define PRODUCTEND 639
#define EXPSTART 640
#define EXPEND 641
#define NEGATESTART 642
#define NEGATEEND 643
#define IFSTART 644
#define IFEND 645
#define SQUARESTART 646
#define SQUAREEND 647
#define COSSTART 648
#define COSEND 649
#define SINSTART 650
#define SINEND 651
#define VARIABLESTART 652
#define VARIABLEEND 653
#define ABSSTART 654
#define ABSEND 655
#define ERFSTART 656
#define ERFEND 657
#define MAXSTART 658
#define MAXEND 659
#define ALLDIFFSTART 660
#define ALLDIFFEND 661
#define MINSTART 662
#define MINEND 663
#define ESTART 664
#define EEND 665
#define PISTART 666
#define PIEND 667
#define TIMESSTART 668
#define TIMESEND 669
#define NUMBERSTART 670
#define NUMBEREND 671
#define MATRIXDETERMINANTSTART 672
#define MATRIXDETERMINANTEND 673
#define MATRIXTRACESTART 674
#define MATRIXTRACEEND 675
#define MATRIXTOSCALARSTART 676
#define MATRIXTOSCALAREND 677
#define MATRIXDIAGONALSTART 678
#define MATRIXDIAGONALEND 679
#define MATRIXDOTTIMESSTART 680
#define MATRIXDOTTIMESEND 681
#define MATRIXLOWERTRIANGLESTART 682
#define MATRIXLOWERTRIANGLEEND 683
#define MATRIXUPPERTRIANGLESTART 684
#define MATRIXUPPERTRIANGLEEND 685
#define MATRIXMERGESTART 686
#define MATRIXMERGEEND 687
#define MATRIXMINUSSTART 688
#define MATRIXMINUSEND 689
#define MATRIXNEGATESTART 690
#define MATRIXNEGATEEND 691
#define MATRIXPLUSSTART 692
#define MATRIXPLUSEND 693
#define MATRIXTIMESSTART 694
#define MATRIXTIMESEND 695
#define MATRIXPRODUCTSTART 696
#define MATRIXPRODUCTEND 697
#define MATRIXSCALARTIMESSTART 698
#define MATRIXSCALARTIMESEND 699
#define MATRIXSUBMATRIXATSTART 700
#define MATRIXSUBMATRIXATEND 701
#define MATRIXTRANSPOSESTART 702
#define MATRIXTRANSPOSEEND 703
#define MATRIXREFERENCESTART 704
#define MATRIXREFERENCEEND 705
#define IDENTITYMATRIXSTART 706
#define IDENTITYMATRIXEND 707
#define MATRIXINVERSESTART 708
#define MATRIXINVERSEEND 709
#define COMPLEXCONJUGATESTART 710
#define COMPLEXCONJUGATEEND 711
#define COMPLEXMINUSSTART 712
#define COMPLEXMINUSEND 713
#define COMPLEXNEGATESTART 714
#define COMPLEXNEGATEEND 715
#define COMPLEXNUMBERSTART 716
#define COMPLEXNUMBEREND 717
#define COMPLEXPLUSSTART 718
#define COMPLEXPLUSEND 719
#define COMPLEXSQUARESTART 720
#define COMPLEXSQUAREEND 721
#define COMPLEXSUMSTART 722
#define COMPLEXSUMEND 723
#define COMPLEXTIMESSTART 724
#define COMPLEXTIMESEND 725
#define CREATECOMPLEXSTART 726
#define CREATECOMPLEXEND 727
#define EMPTYINCLUDEDIAGONALATT 728
#define INCLUDEDIAGONALATT 729
#define EMPTYTRANSPOSEATT 730
#define TRANSPOSEATT 731
#define EMPTYIDATT 732
#define IDATT 733




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
#define YYLAST   2161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  483
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  1188
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1765
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2526

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   733

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   480,
     482,     2,     2,   481,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   479,     2,     2,     2,     2,     2,     2,     2,
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478
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
    1040,  1044,  1050,  1051,  1055,  1057,  1059,  1060,  1062,  1064,
    1066,  1068,  1072,  1079,  1080,  1084,  1086,  1088,  1090,  1092,
    1095,  1097,  1101,  1103,  1105,  1108,  1112,  1114,  1116,  1117,
    1120,  1122,  1124,  1126,  1129,  1131,  1132,  1136,  1138,  1140,
    1142,  1144,  1147,  1149,  1153,  1155,  1157,  1160,  1164,  1166,
    1168,  1169,  1172,  1174,  1176,  1178,  1181,  1183,  1184,  1187,
    1189,  1191,  1193,  1195,  1199,  1207,  1208,  1210,  1211,  1213,
    1214,  1216,  1217,  1219,  1220,  1222,  1223,  1225,  1226,  1228,
    1229,  1233,  1235,  1237,  1239,  1241,  1244,  1246,  1250,  1252,
    1254,  1257,  1261,  1263,  1265,  1266,  1269,  1271,  1273,  1275,
    1278,  1280,  1281,  1285,  1287,  1292,  1294,  1296,  1299,  1301,
    1305,  1307,  1310,  1314,  1316,  1318,  1319,  1322,  1324,  1326,
    1328,  1330,  1332,  1335,  1337,  1341,  1342,  1345,  1349,  1351,
    1353,  1354,  1357,  1359,  1361,  1363,  1365,  1367,  1369,  1371,
    1373,  1375,  1377,  1379,  1381,  1384,  1386,  1390,  1392,  1394,
    1396,  1399,  1403,  1405,  1407,  1408,  1411,  1413,  1415,  1417,
    1419,  1421,  1423,  1426,  1428,  1429,  1433,  1435,  1437,  1438,
    1440,  1442,  1444,  1446,  1450,  1455,  1456,  1460,  1462,  1464,
    1466,  1468,  1471,  1473,  1477,  1479,  1481,  1484,  1488,  1490,
    1492,  1493,  1496,  1498,  1500,  1502,  1505,  1507,  1508,  1512,
    1514,  1516,  1518,  1520,  1523,  1525,  1529,  1531,  1533,  1536,
    1540,  1542,  1544,  1545,  1548,  1550,  1552,  1554,  1556,  1559,
    1561,  1562,  1565,  1567,  1569,  1571,  1573,  1577,  1585,  1586,
    1588,  1589,  1591,  1592,  1594,  1595,  1597,  1598,  1600,  1601,
    1603,  1604,  1606,  1607,  1610,  1614,  1616,  1618,  1619,  1622,
    1624,  1626,  1628,  1630,  1632,  1634,  1636,  1638,  1640,  1642,
    1644,  1646,  1649,  1651,  1655,  1657,  1659,  1661,  1664,  1668,
    1670,  1672,  1673,  1676,  1678,  1680,  1682,  1684,  1686,  1688,
    1691,  1693,  1694,  1698,  1700,  1702,  1703,  1705,  1707,  1709,
    1711,  1715,  1720,  1721,  1725,  1727,  1729,  1731,  1733,  1736,
    1738,  1742,  1744,  1746,  1749,  1753,  1755,  1757,  1758,  1761,
    1763,  1765,  1767,  1770,  1772,  1773,  1777,  1779,  1781,  1783,
    1785,  1788,  1790,  1794,  1796,  1798,  1801,  1805,  1807,  1809,
    1810,  1813,  1815,  1817,  1819,  1821,  1824,  1826,  1827,  1830,
    1832,  1834,  1836,  1838,  1842,  1850,  1851,  1853,  1854,  1856,
    1857,  1859,  1860,  1862,  1863,  1865,  1866,  1868,  1869,  1871,
    1872,  1875,  1879,  1881,  1883,  1884,  1887,  1889,  1891,  1893,
    1895,  1897,  1899,  1901,  1903,  1905,  1907,  1909,  1911,  1914,
    1916,  1920,  1922,  1924,  1926,  1929,  1933,  1935,  1937,  1938,
    1941,  1943,  1945,  1947,  1949,  1951,  1953,  1956,  1958,  1959,
    1963,  1965,  1967,  1968,  1970,  1972,  1974,  1976,  1983,  1984,
    1988,  1990,  1991,  1993,  1995,  1997,  1999,  2004,  2006,  2007,
    2011,  2013,  2015,  2017,  2019,  2021,  2025,  2027,  2028,  2031,
    2033,  2034,  2035,  2036,  2037,  2040,  2041,  2045,  2047,  2049,
    2051,  2053,  2055,  2059,  2060,  2063,  2067,  2069,  2071,  2073,
    2076,  2078,  2080,  2082,  2084,  2086,  2088,  2090,  2092,  2094,
    2097,  2099,  2103,  2105,  2107,  2110,  2112,  2114,  2116,  2118,
    2120,  2124,  2126,  2128,  2131,  2136,  2140,  2142,  2144,  2145,
    2148,  2150,  2152,  2154,  2158,  2162,  2166,  2169,  2171,  2173,
    2178,  2180,  2182,  2184,  2186,  2190,  2192,  2194,  2196,  2198,
    2203,  2205,  2207,  2212,  2214,  2216,  2218,  2220,  2224,  2226,
    2228,  2230,  2232,  2237,  2242,  2247,  2252,  2257,  2262,  2267,
    2272,  2277,  2282,  2287,  2292,  2294,  2297,  2301,  2303,  2305,
    2306,  2309,  2311,  2313,  2315,  2317,  2319,  2321,  2325,  2327,
    2329,  2331,  2334,  2335,  2338,  2340,  2342,  2344,  2346,  2349,
    2351,  2353,  2355,  2357,  2361,  2363,  2364,  2367,  2369,  2371,
    2373,  2375,  2377,  2379,  2381,  2383,  2385,  2387,  2391,  2393,
    2395,  2397,  2399,  2401,  2405,  2407,  2409,  2411,  2413,  2415,
    2419,  2421,  2423,  2425,  2427,  2429,  2433,  2435,  2437,  2439,
    2441,  2443,  2447,  2449,  2451,  2453,  2454,  2457,  2461,  2463,
    2465,  2466,  2469,  2471,  2473,  2477,  2481,  2483,  2485,  2488,
    2490,  2494,  2496,  2498,  2499,  2502,  2506,  2508,  2509,  2511,
    2515,  2519,  2521,  2523,  2526,  2528,  2532,  2534,  2535,  2538,
    2542,  2544,  2545,  2547,  2551,  2555,  2557,  2559,  2561,  2563,
    2567,  2569,  2573,  2575,  2577,  2579,  2581,  2585,  2587,  2591,
    2593,  2595,  2597,  2599,  2603,  2605,  2609,  2611,  2613,  2615,
    2617,  2621,  2623,  2627,  2629,  2631,  2633,  2635,  2639,  2641,
    2645,  2647,  2649,  2651,  2653,  2657,  2659,  2663,  2665,  2667,
    2669,  2671,  2675,  2677,  2679,  2683,  2685,  2687,  2688,  2691,
    2693,  2695,  2697,  2699,  2701,  2703,  2705,  2707,  2709,  2713,
    2716,  2717,  2721,  2723,  2725,  2726,  2729,  2731,  2733,  2735,
    2737,  2739,  2741,  2743,  2745,  2747,  2750,  2752,  2753,  2756,
    2758,  2760,  2762,  2764,  2766,  2768,  2770,  2772,  2774,  2776,
    2778,  2783,  2785,  2787,  2788,  2791,  2793,  2795,  2799,  2800,
    2803,  2806,  2808,  2810,  2812,  2814,  2818,  2820,  2821,  2824,
    2826,  2828,  2830,  2832,  2836,  2838,  2841,  2843,  2845,  2847,
    2849,  2853,  2855,  2860,  2862,  2864,  2865,  2868,  2870,  2872,
    2876,  2879,  2880,  2883,  2885,  2887,  2889,  2891,  2895,  2897,
    2902,  2904,  2906,  2907,  2910,  2912,  2914,  2918,  2921,  2922,
    2925,  2927,  2929,  2931,  2933,  2937,  2939,  2940,  2943,  2947,
    2949,  2951,  2952,  2955,  2957,  2959,  2961,  2963,  2965,  2969,
    2970,  2973,  2977,  2979,  2980,  2982,  2986,  2991,  2993,  2995,
    2996,  2999,  3001,  3003,  3007,  3010,  3011,  3014,  3016,  3018,
    3020,  3022,  3026,  3027,  3030,  3033,  3035,  3037,  3039,  3041,
    3045,  3050,  3052,  3054,  3055,  3058,  3060,  3062,  3066,  3069,
    3070,  3073,  3075,  3077,  3079,  3081,  3085,  3086,  3089,  3092,
    3094,  3096,  3098,  3100,  3104,  3109,  3111,  3113,  3114,  3117,
    3119,  3121,  3125,  3128,  3129,  3132,  3134,  3136,  3138,  3140,
    3144,  3146,  3151,  3153,  3155,  3156,  3159,  3161,  3163,  3167,
    3170,  3171,  3174,  3176,  3178,  3180,  3182,  3186,  3187,  3190,
    3194,  3196,  3197,  3200,  3202,  3204,  3206,  3210,  3215,  3217,
    3219,  3220,  3223,  3225,  3227,  3231,  3234,  3235,  3238,  3240,
    3242,  3244,  3246,  3250,  3251,  3254,  3258,  3260,  3261,  3264,
    3266,  3268,  3270,  3273,  3275,  3280,  3282,  3284,  3285,  3288,
    3290,  3292,  3296,  3299,  3300,  3303,  3305,  3307,  3309,  3311,
    3315,  3317,  3323,  3325,  3326,  3328,  3330,  3334,  3336,  3338,
    3344,  3346,  3350,  3352,  3354,  3356,  3358,  3360,  3364,  3366,
    3370,  3372,  3374,  3376,  3378,  3380,  3384,  3386,  3387,  3390,
    3394,  3396,  3398,  3399,  3402,  3404,  3406,  3408,  3410,  3412,
    3414,  3416,  3420,  3425,  3430,  3435,  3440,  3445,  3450,  3455,
    3460,  3465,  3470,  3475,  3480,  3485,  3490,  3495,  3500,  3505,
    3510,  3515,  3520,  3525,  3530,  3535,  3540,  3545,  3550,  3555,
    3560,  3565,  3570,  3575,  3580,  3585,  3590,  3592,  3594,  3596,
    3600,  3602,  3604,  3606,  3610,  3612,  3614,  3616,  3620,  3622,
    3624,  3626,  3630,  3632,  3634,  3636,  3640,  3642,  3644,  3646,
    3650,  3652,  3654,  3656,  3660,  3662,  3664,  3666,  3670,  3672,
    3674,  3676,  3680,  3682,  3684,  3686,  3690,  3692,  3694,  3696,
    3700,  3702,  3704,  3706,  3710,  3712,  3714,  3716,  3720,  3722,
    3724,  3726,  3730,  3732,  3734,  3736,  3740,  3742,  3744,  3746,
    3750,  3752,  3754,  3756,  3758,  3760,  3762,  3764,  3766,  3768,
    3770,  3772,  3774,  3776,  3778,  3780,  3782,  3784,  3786,  3788,
    3790,  3792,  3794,  3796,  3798,  3800,  3802,  3804,  3805,  3809,
    3811,  3814,  3815,  3819,  3821,  3824,  3825,  3831,  3832,  3838,
    3839,  3845,  3846,  3851,  3852,  3858,  3859,  3865,  3866,  3871,
    3872,  3877,  3878,  3883,  3884,  3889,  3890,  3895,  3896,  3901,
    3905,  3907,  3909,  3910,  3915,  3916,  3923,  3924,  3929,  3930,
    3935,  3936,  3941,  3945,  3947,  3949,  3952,  3953,  3956,  3958,
    3960,  3962,  3963,  3968,  3969,  3974,  3976,  3979,  3980,  3985,
    3986,  3989,  3991,  3993,  3998,  4003,  4004,  4009,  4010,  4013,
    4014,  4019,  4020,  4023,  4024,  4029,  4030,  4033,  4034,  4039,
    4040,  4043,  4044,  4049,  4050,  4053,  4055,  4057,  4059,  4061,
    4063,  4065,  4067,  4069,  4071,  4073,  4075,  4077,  4079,  4081,
    4083,  4085,  4087,  4089,  4091,  4095,  4097,  4098,  4101,  4103,
    4105,  4107,  4110,  4115,  4119,  4123,  4125,  4127,  4130,  4135,
    4139,  4141,  4143,  4146,  4151,  4155,  4157,  4159,  4162,  4167,
    4170,  4172,  4175,  4178,  4180,  4184,  4187,  4189,  4192,  4195,
    4197,  4200,  4205,  4207,  4208,  4210,  4213,  4218,  4220,  4221,
    4223,  4226,  4230,  4233,  4235,  4237,  4240,  4243,  4245,  4249,
    4252,  4254,  4257,  4260,  4262,  4266,  4269,  4271,  4275,  4276,
    4281,  4282,  4285,  4288,  4290,  4294,  4297,  4299,  4306,  4309,
    4311,  4314,  4316,  4318,  4320,  4322,  4324,  4326,  4328,  4330,
    4332,  4334,  4336,  4340,  4342,  4344,  4347,  4349,  4350,  4353,
    4355,  4357,  4361,  4363,  4367,  4371,  4373,  4377,  4378,  4384,
    4385,  4388,  4392,  4394,  4398,  4402,  4404,  4407,  4411,  4413,
    4416,  4420,  4422,  4426,  4430,  4432
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     484,     0,    -1,   485,   493,   491,    -1,   486,   487,   488,
      -1,    14,    -1,    13,    -1,    -1,    15,    -1,   489,    -1,
     490,    -1,    12,    -1,    11,   493,   491,    -1,   492,    -1,
      16,    -1,    -1,   494,   495,   581,   624,   647,   758,    -1,
      -1,  1103,    -1,    -1,   496,   497,    -1,   321,    -1,   498,
      -1,   499,    -1,    11,   322,    -1,    12,    -1,    11,   500,
     322,    -1,   501,    -1,   502,    -1,   501,   502,    -1,   503,
      -1,   509,    -1,   515,    -1,   521,    -1,   529,    -1,   535,
      -1,   541,    -1,   547,    -1,   553,    -1,   559,    -1,   567,
      -1,   504,   505,    -1,   345,    -1,   506,    -1,   507,    -1,
      11,   346,    -1,    12,    -1,    11,   508,   346,    -1,     4,
      -1,   510,   511,    -1,   347,    -1,   512,    -1,   513,    -1,
      11,   348,    -1,    12,    -1,    11,   514,   348,    -1,     4,
      -1,   516,   517,    -1,   349,    -1,   518,    -1,   519,    -1,
      11,   350,    -1,    12,    -1,    11,   520,   350,    -1,     4,
      -1,   522,   523,   525,    -1,    48,    -1,    -1,   524,    -1,
      28,     3,     8,    -1,   526,    -1,   527,    -1,    11,    49,
      -1,    12,    -1,    11,   528,    49,    -1,     4,    -1,   530,
     531,    -1,   351,    -1,   532,    -1,   533,    -1,    11,   352,
      -1,    12,    -1,    11,   534,   352,    -1,     4,    -1,   536,
     537,    -1,    50,    -1,   538,    -1,   539,    -1,    11,    51,
      -1,    12,    -1,    11,   540,    51,    -1,     4,    -1,   542,
     543,    -1,    52,    -1,   544,    -1,   545,    -1,    11,    53,
      -1,    12,    -1,    11,   546,    53,    -1,     4,    -1,   548,
     549,    -1,    54,    -1,   550,    -1,   551,    -1,    11,    55,
      -1,    12,    -1,    11,   552,    55,    -1,     4,    -1,   554,
     555,    -1,    56,    -1,   556,    -1,   557,    -1,    11,    57,
      -1,    12,    -1,    11,   558,    57,    -1,     4,    -1,   560,
     561,   563,    -1,    58,    -1,    -1,   562,    -1,    27,     3,
       8,    -1,   564,    -1,   565,    -1,    11,    59,    -1,    12,
      -1,    11,   566,    59,    -1,     4,    -1,   568,   569,   570,
      -1,   130,    -1,  1083,    -1,   571,    -1,   572,    -1,    11,
     131,    -1,    12,    -1,    11,   573,   131,    -1,   574,    -1,
     575,    -1,   574,   575,    -1,   576,   577,   580,    -1,   353,
      -1,   578,    -1,    -1,   578,   579,    -1,  1464,    -1,  1488,
      -1,  1458,    -1,    11,   354,    -1,    12,    -1,    -1,   582,
     583,    -1,   323,    -1,   584,    -1,   585,    -1,    11,   324,
      -1,    12,    -1,    11,   586,   324,    -1,   587,    -1,   588,
      -1,   587,   588,    -1,   589,    -1,   596,    -1,   603,    -1,
     610,    -1,   615,    -1,   590,   591,   594,    -1,    60,    -1,
     592,    -1,    -1,   592,   593,    -1,  1485,    -1,  1458,    -1,
      11,   595,    61,    -1,  1099,    -1,   597,   598,   601,    -1,
      62,    -1,   599,    -1,    -1,   599,   600,    -1,  1485,    -1,
    1458,    -1,    11,   602,    63,    -1,  1099,    -1,   604,   605,
     608,    -1,    64,    -1,   606,    -1,    -1,   606,   607,    -1,
    1485,    -1,  1458,    -1,    11,   609,    65,    -1,  1099,    -1,
     611,   612,   613,    -1,    66,    -1,    -1,  1458,    -1,    11,
     614,    67,    -1,     6,    -1,   616,   617,   618,    -1,   130,
      -1,  1083,    -1,   619,    -1,   620,    -1,    11,   131,    -1,
      12,    -1,    11,   621,   131,    -1,   622,    -1,   623,    -1,
     622,   623,    -1,   576,   577,   580,    -1,    -1,   625,   626,
      -1,   325,    -1,   627,    -1,   628,    -1,    11,   326,    -1,
      12,    -1,    11,   629,   326,    -1,   630,    -1,   631,    -1,
     630,   631,    -1,   632,    -1,   638,    -1,   633,   634,    -1,
      68,    -1,   635,    -1,   636,    -1,    11,    69,    -1,    12,
      -1,    11,   637,    69,    -1,     4,    -1,   639,   640,   641,
      -1,   130,    -1,  1083,    -1,   642,    -1,   643,    -1,    11,
     131,    -1,    12,    -1,    11,   644,   131,    -1,   645,    -1,
     646,    -1,   645,   646,    -1,   576,   577,   580,    -1,    -1,
     648,   649,    -1,   327,    -1,   650,    -1,   651,    -1,    11,
     328,    -1,    12,    -1,    11,   652,   328,    -1,   653,    -1,
     654,    -1,   653,   654,    -1,   655,    -1,   663,    -1,   669,
      -1,   677,    -1,   682,    -1,   687,    -1,   692,    -1,   697,
      -1,   705,    -1,   721,    -1,   713,    -1,   729,    -1,   735,
      -1,   741,    -1,   749,    -1,   656,   657,   658,    -1,    70,
      -1,    -1,  1485,    -1,   659,    -1,   660,    -1,    11,    71,
      -1,    12,    -1,    11,   661,    71,    -1,   662,    -1,  1099,
      -1,   664,   665,    -1,    72,    -1,   666,    -1,   667,    -1,
      11,    73,    -1,    12,    -1,    11,   668,    73,    -1,     4,
      -1,   670,   671,   672,    -1,    74,    -1,  1078,    -1,   673,
      -1,   674,    -1,    11,    75,    -1,    12,    -1,    11,   675,
      75,    -1,   676,    -1,   675,   676,    -1,   351,    11,     4,
     352,    -1,   678,  1086,   679,    -1,    80,    -1,   680,    -1,
     681,    -1,    11,    81,    -1,    12,    -1,    11,  1046,    81,
      -1,   683,  1086,   684,    -1,    82,    -1,   685,    -1,   686,
      -1,    11,    83,    -1,    12,    -1,    11,  1046,    83,    -1,
     688,  1086,   689,    -1,    84,    -1,   690,    -1,   691,    -1,
      11,    85,    -1,    12,    -1,    11,  1046,    85,    -1,   693,
    1086,   694,    -1,    86,    -1,   695,    -1,   696,    -1,    11,
      87,    -1,    12,    -1,    11,  1046,    87,    -1,   698,   699,
     700,    -1,    92,    -1,  1085,    -1,   701,    -1,   702,    -1,
      11,    93,    -1,    12,    -1,    11,   703,    93,    -1,   704,
      -1,   703,   704,    -1,  1048,    -1,   706,   707,   708,    -1,
      94,    -1,  1085,    -1,   709,    -1,   710,    -1,    11,    95,
      -1,    12,    -1,    11,   711,    95,    -1,   712,    -1,   711,
     712,    -1,  1048,    -1,   714,   715,   716,    -1,    98,    -1,
    1085,    -1,   717,    -1,   718,    -1,    11,    99,    -1,    12,
      -1,    11,   719,    99,    -1,   720,    -1,   719,   720,    -1,
    1048,    -1,   722,   723,   724,    -1,    96,    -1,  1085,    -1,
     725,    -1,   726,    -1,    11,    97,    -1,    12,    -1,    11,
     727,    97,    -1,   728,    -1,   727,   728,    -1,  1048,    -1,
     730,   731,   732,    -1,    90,    -1,  1086,    -1,   733,    -1,
     734,    -1,    11,    91,    -1,    12,    -1,    11,  1046,    91,
      -1,   736,   737,   738,    -1,    88,    -1,  1086,    -1,   739,
      -1,   740,    -1,    11,    89,    -1,    12,    -1,    11,  1046,
      89,    -1,   742,   743,   744,    -1,   100,    -1,  1087,    -1,
     745,    -1,   746,    -1,    11,   101,    -1,    12,    -1,    11,
     747,   101,    -1,   748,    -1,   747,   748,    -1,   102,    11,
       4,   103,    -1,   750,   751,   752,    -1,   130,    -1,  1083,
      -1,   753,    -1,   754,    -1,    11,   131,    -1,    12,    -1,
      11,   755,   131,    -1,   756,    -1,   757,    -1,   756,   757,
      -1,   576,   577,   580,    -1,    -1,   759,   760,   763,    -1,
     329,    -1,   761,    -1,    -1,   761,   762,    -1,  1429,    -1,
    1418,    -1,  1424,    -1,   764,    -1,   765,    -1,    12,    -1,
      11,   766,   330,    -1,   767,   863,   930,   997,  1024,    -1,
      -1,   768,   769,   771,    -1,   319,    -1,   770,    -1,    -1,
    1084,    -1,   772,    -1,   773,    -1,    12,    -1,    11,   774,
     320,    -1,   775,   789,   803,   816,   830,   845,    -1,    -1,
     776,   777,   778,    -1,   104,    -1,  1427,    -1,   779,    -1,
     780,    -1,    11,   105,    -1,    12,    -1,    11,   781,   105,
      -1,   782,    -1,   783,    -1,   782,   783,    -1,   784,   785,
     788,    -1,   317,    -1,   786,    -1,    -1,   786,   787,    -1,
    1438,    -1,  1464,    -1,  1488,    -1,    11,   318,    -1,    12,
      -1,    -1,   790,   791,   792,    -1,   106,    -1,  1427,    -1,
     793,    -1,   794,    -1,    11,   107,    -1,    12,    -1,    11,
     795,   107,    -1,   796,    -1,   797,    -1,   796,   797,    -1,
     798,   799,   802,    -1,   317,    -1,   800,    -1,    -1,   800,
     801,    -1,  1438,    -1,  1464,    -1,  1488,    -1,    11,   318,
      -1,    12,    -1,    -1,   804,   805,    -1,   108,    -1,   806,
      -1,   807,    -1,    12,    -1,    11,   808,   109,    -1,   809,
     810,   811,   812,   813,   814,   815,    -1,    -1,  1160,    -1,
      -1,  1166,    -1,    -1,  1172,    -1,    -1,  1178,    -1,    -1,
    1184,    -1,    -1,  1190,    -1,    -1,  1196,    -1,    -1,   817,
     818,   819,    -1,   110,    -1,  1427,    -1,   820,    -1,   821,
      -1,    11,   111,    -1,    12,    -1,    11,   822,   111,    -1,
     823,    -1,   824,    -1,   823,   824,    -1,   825,   826,   829,
      -1,   317,    -1,   827,    -1,    -1,   827,   828,    -1,  1438,
      -1,  1464,    -1,  1488,    -1,    11,   318,    -1,    12,    -1,
      -1,   831,   832,   833,    -1,   112,    -1,    45,     8,     6,
       8,    -1,   834,    -1,   835,    -1,    11,   113,    -1,    12,
      -1,    11,   836,   113,    -1,   837,    -1,   836,   837,    -1,
     838,   839,   842,    -1,   114,    -1,   840,    -1,    -1,   840,
     841,    -1,  1067,    -1,  1427,    -1,  1057,    -1,   843,    -1,
     844,    -1,    11,   115,    -1,    12,    -1,    11,   823,   115,
      -1,    -1,   845,   846,    -1,   847,   848,   851,    -1,   353,
      -1,   849,    -1,    -1,   849,   850,    -1,  1427,    -1,  1420,
      -1,  1464,    -1,  1488,    -1,  1476,    -1,  1452,    -1,  1482,
      -1,  1494,    -1,  1461,    -1,  1458,    -1,   852,    -1,   853,
      -1,    11,   354,    -1,    12,    -1,    11,   854,   354,    -1,
     855,    -1,  1089,    -1,   856,    -1,   855,   856,    -1,   857,
     858,   861,    -1,   317,    -1,   859,    -1,    -1,   859,   860,
      -1,  1438,    -1,  1464,    -1,  1488,    -1,  1059,    -1,  1070,
      -1,   862,    -1,    11,   318,    -1,    12,    -1,    -1,   864,
     865,   867,    -1,   315,    -1,   866,    -1,    -1,  1082,    -1,
     868,    -1,   869,    -1,    12,    -1,    11,   870,   316,    -1,
     871,   885,   899,   912,    -1,    -1,   872,   873,   874,    -1,
     116,    -1,  1423,    -1,   875,    -1,   876,    -1,    11,   117,
      -1,    12,    -1,    11,   877,   117,    -1,   878,    -1,   879,
      -1,   878,   879,    -1,   880,   881,   884,    -1,   313,    -1,
     882,    -1,    -1,   882,   883,    -1,  1438,    -1,  1464,    -1,
    1488,    -1,    11,   314,    -1,    12,    -1,    -1,   886,   887,
     888,    -1,   118,    -1,  1423,    -1,   889,    -1,   890,    -1,
      11,   119,    -1,    12,    -1,    11,   891,   119,    -1,   892,
      -1,   893,    -1,   892,   893,    -1,   894,   895,   898,    -1,
     313,    -1,   896,    -1,    -1,   896,   897,    -1,  1438,    -1,
    1464,    -1,  1059,    -1,  1070,    -1,    11,   314,    -1,    12,
      -1,    -1,   900,   901,    -1,   108,    -1,   902,    -1,   903,
      -1,    12,    -1,    11,   904,   109,    -1,   905,   906,   907,
     908,   909,   910,   911,    -1,    -1,  1160,    -1,    -1,  1166,
      -1,    -1,  1172,    -1,    -1,  1178,    -1,    -1,  1184,    -1,
      -1,  1190,    -1,    -1,  1196,    -1,    -1,   912,   913,    -1,
     914,   915,   918,    -1,   353,    -1,   916,    -1,    -1,   916,
     917,    -1,  1423,    -1,  1420,    -1,  1464,    -1,  1488,    -1,
    1476,    -1,  1452,    -1,  1482,    -1,  1467,    -1,  1461,    -1,
    1458,    -1,   919,    -1,   920,    -1,    11,   354,    -1,    12,
      -1,    11,   921,   354,    -1,   922,    -1,  1089,    -1,   923,
      -1,   922,   923,    -1,   924,   925,   928,    -1,   313,    -1,
     926,    -1,    -1,   926,   927,    -1,  1438,    -1,  1464,    -1,
    1488,    -1,  1059,    -1,  1070,    -1,   929,    -1,    11,   314,
      -1,    12,    -1,    -1,   931,   932,   934,    -1,   311,    -1,
     933,    -1,    -1,  1079,    -1,   935,    -1,   936,    -1,    12,
      -1,    11,   937,   312,    -1,   938,   952,   966,   979,    -1,
      -1,   939,   940,   941,    -1,   120,    -1,  1417,    -1,   942,
      -1,   943,    -1,    11,   121,    -1,    12,    -1,    11,   944,
     121,    -1,   945,    -1,   946,    -1,   945,   946,    -1,   947,
     948,   951,    -1,   309,    -1,   949,    -1,    -1,   949,   950,
      -1,  1438,    -1,  1464,    -1,  1488,    -1,    11,   310,    -1,
      12,    -1,    -1,   953,   954,   955,    -1,   122,    -1,  1417,
      -1,   956,    -1,   957,    -1,    11,   123,    -1,    12,    -1,
      11,   958,   123,    -1,   959,    -1,   960,    -1,   959,   960,
      -1,   961,   962,   965,    -1,   309,    -1,   963,    -1,    -1,
     963,   964,    -1,  1438,    -1,  1464,    -1,  1063,    -1,  1074,
      -1,    11,   310,    -1,    12,    -1,    -1,   967,   968,    -1,
     108,    -1,   969,    -1,   970,    -1,    12,    -1,    11,   971,
     109,    -1,   972,   973,   974,   975,   976,   977,   978,    -1,
      -1,  1160,    -1,    -1,  1166,    -1,    -1,  1172,    -1,    -1,
    1178,    -1,    -1,  1184,    -1,    -1,  1190,    -1,    -1,  1196,
      -1,    -1,   979,   980,    -1,   981,   982,   985,    -1,   353,
      -1,   983,    -1,    -1,   983,   984,    -1,  1417,    -1,  1420,
      -1,  1464,    -1,  1488,    -1,  1476,    -1,  1452,    -1,  1482,
      -1,  1455,    -1,  1461,    -1,  1458,    -1,   986,    -1,   987,
      -1,    11,   354,    -1,    12,    -1,    11,   988,   354,    -1,
     989,    -1,  1089,    -1,   990,    -1,   989,   990,    -1,   991,
     992,   995,    -1,   309,    -1,   993,    -1,    -1,   993,   994,
      -1,  1438,    -1,  1464,    -1,  1488,    -1,  1059,    -1,  1070,
      -1,   996,    -1,    11,   310,    -1,    12,    -1,    -1,   998,
     999,  1001,    -1,   295,    -1,  1000,    -1,    -1,  1080,    -1,
    1002,    -1,  1003,    -1,    12,    -1,    11,  1004,  1021,  1022,
    1023,   296,    -1,    -1,  1005,  1006,  1007,    -1,   297,    -1,
      -1,  1081,    -1,  1008,    -1,  1009,    -1,    12,    -1,    11,
    1011,  1020,  1010,    -1,   298,    -1,    -1,  1012,  1013,  1014,
      -1,   124,    -1,  1422,    -1,  1015,    -1,  1016,    -1,    12,
      -1,    11,  1018,  1017,    -1,   125,    -1,    -1,  1018,  1019,
      -1,  1203,    -1,    -1,    -1,    -1,    -1,  1023,  1030,    -1,
      -1,  1025,  1026,  1027,    -1,   126,    -1,  1088,    -1,  1028,
      -1,  1029,    -1,    12,    -1,    11,  1030,   127,    -1,    -1,
    1030,  1031,    -1,  1032,  1033,  1036,    -1,   128,    -1,  1034,
      -1,  1035,    -1,  1034,  1035,    -1,  1464,    -1,  1488,    -1,
    1476,    -1,  1452,    -1,  1482,    -1,  1458,    -1,  1421,    -1,
    1037,    -1,  1038,    -1,    11,   129,    -1,    12,    -1,    11,
    1039,   129,    -1,  1040,    -1,  1041,    -1,  1040,  1041,    -1,
    1042,    -1,  1043,    -1,  1044,    -1,   167,    -1,   164,    -1,
     165,  1045,   166,    -1,     5,    -1,  1047,    -1,  1046,  1047,
      -1,    76,    11,     4,    77,    -1,  1049,  1050,  1056,    -1,
      78,    -1,  1051,    -1,    -1,  1051,  1052,    -1,  1053,    -1,
    1054,    -1,  1055,    -1,    29,     3,     8,    -1,    30,     3,
       8,    -1,    31,     3,     8,    -1,    11,    79,    -1,    12,
      -1,  1058,    -1,    47,     8,  1099,     8,    -1,  1060,    -1,
    1061,    -1,  1062,    -1,    17,    -1,    19,     3,  1100,    -1,
    1064,    -1,  1065,    -1,  1066,    -1,    21,    -1,    23,  1100,
    1099,  1100,    -1,  1068,    -1,  1069,    -1,    46,  1100,     6,
    1100,    -1,  1071,    -1,  1072,    -1,  1073,    -1,    18,    -1,
      20,     3,  1100,    -1,  1075,    -1,  1076,    -1,  1077,    -1,
      22,    -1,    24,  1100,  1099,  1100,    -1,    32,     8,     6,
       8,    -1,    38,  1100,     6,  1100,    -1,    39,  1100,     6,
    1100,    -1,    40,  1100,     6,  1100,    -1,    37,  1100,     6,
    1100,    -1,    44,  1100,     6,  1100,    -1,    36,  1100,     6,
    1100,    -1,    34,     8,     6,     8,    -1,    33,     8,     6,
       8,    -1,    35,     8,     6,     8,    -1,    43,  1100,     6,
    1100,    -1,  1090,    -1,  1089,  1090,    -1,  1091,  1092,  1095,
      -1,   162,    -1,  1093,    -1,    -1,  1093,  1094,    -1,  1419,
      -1,  1488,    -1,  1458,    -1,  1096,    -1,  1097,    -1,    12,
      -1,    11,  1098,   163,    -1,  1132,    -1,     6,    -1,     7,
      -1,  1101,     8,    -1,    -1,  1101,  1102,    -1,   479,    -1,
     480,    -1,   481,    -1,   482,    -1,  1104,  1105,    -1,   132,
      -1,  1106,    -1,  1107,    -1,    12,    -1,    11,  1108,   133,
      -1,  1109,    -1,    -1,  1109,  1110,    -1,  1111,    -1,  1115,
      -1,  1119,    -1,  1123,    -1,  1127,    -1,  1112,    -1,  1113,
      -1,  1114,    -1,   137,    -1,   136,    -1,   134,     5,   135,
      -1,  1116,    -1,  1117,    -1,  1118,    -1,   141,    -1,   140,
      -1,   138,     5,   139,    -1,  1120,    -1,  1121,    -1,  1122,
      -1,   145,    -1,   144,    -1,   142,     5,   143,    -1,  1124,
      -1,  1125,    -1,  1126,    -1,   149,    -1,   148,    -1,   146,
       5,   147,    -1,  1128,    -1,  1129,    -1,  1130,    -1,   153,
      -1,   152,    -1,   150,     5,   151,    -1,  1132,    -1,  1133,
      -1,  1140,    -1,    -1,  1133,  1134,    -1,  1135,  1136,  1139,
      -1,   160,    -1,  1137,    -1,    -1,  1137,  1138,    -1,  1441,
      -1,  1439,    -1,    11,     6,   161,    -1,   168,  1430,  1141,
      -1,  1142,    -1,  1143,    -1,    11,   169,    -1,    12,    -1,
      11,     4,   169,    -1,  1145,    -1,  1150,    -1,    -1,  1145,
    1146,    -1,  1147,  1148,  1149,    -1,   160,    -1,    -1,  1441,
      -1,    11,  1099,   161,    -1,   168,  1430,  1151,    -1,  1152,
      -1,  1153,    -1,    11,   169,    -1,    12,    -1,    11,     4,
     169,    -1,  1155,    -1,    -1,  1155,  1156,    -1,  1157,  1158,
    1159,    -1,   160,    -1,    -1,  1441,    -1,    11,     4,   161,
      -1,  1161,  1202,  1162,    -1,   337,    -1,  1163,    -1,  1164,
      -1,    12,    -1,    11,  1165,   338,    -1,  1132,    -1,  1167,
    1202,  1168,    -1,   333,    -1,  1169,    -1,  1170,    -1,    12,
      -1,    11,  1171,   334,    -1,  1132,    -1,  1173,  1202,  1174,
      -1,   335,    -1,  1175,    -1,  1176,    -1,    12,    -1,    11,
    1177,   336,    -1,  1132,    -1,  1179,  1202,  1180,    -1,   331,
      -1,  1181,    -1,  1182,    -1,    12,    -1,    11,  1183,   332,
      -1,  1132,    -1,  1185,  1202,  1186,    -1,   339,    -1,  1187,
      -1,  1188,    -1,    12,    -1,    11,  1189,   340,    -1,  1132,
      -1,  1191,  1202,  1192,    -1,   341,    -1,  1193,    -1,  1194,
      -1,    12,    -1,    11,  1195,   342,    -1,  1132,    -1,  1197,
    1202,  1198,    -1,   343,    -1,  1199,    -1,  1200,    -1,    12,
      -1,    11,  1201,   344,    -1,  1132,    -1,  1419,    -1,  1204,
    1205,  1208,    -1,   299,    -1,  1206,    -1,    -1,  1206,  1207,
      -1,  1479,    -1,  1425,    -1,  1416,    -1,  1464,    -1,  1482,
      -1,  1440,    -1,  1209,    -1,  1210,    -1,    12,    -1,    11,
    1211,   300,    -1,  1212,  1218,    -1,    -1,  1213,  1214,  1217,
      -1,   256,    -1,  1215,    -1,    -1,  1215,  1216,    -1,  1431,
      -1,  1442,    -1,  1443,    -1,  1432,    -1,  1433,    -1,  1434,
      -1,  1435,    -1,  1449,    -1,  1448,    -1,    11,   255,    -1,
      12,    -1,    -1,  1218,  1219,    -1,  1220,    -1,  1352,    -1,
    1370,    -1,  1245,    -1,  1321,    -1,  1334,    -1,  1258,    -1,
    1285,    -1,  1303,    -1,  1383,    -1,  1387,    -1,  1221,  1222,
      11,  1225,    -1,   267,    -1,  1223,    -1,    -1,  1223,  1224,
      -1,  1426,    -1,  1470,    -1,  1227,  1226,   268,    -1,    -1,
    1233,  1239,    -1,  1228,  1229,    -1,   285,    -1,  1230,    -1,
    1231,    -1,    12,    -1,    11,  1232,   286,    -1,  1131,    -1,
      -1,  1234,  1235,    -1,   287,    -1,  1236,    -1,  1237,    -1,
      12,    -1,    11,  1238,   288,    -1,  1131,    -1,  1240,  1241,
      -1,   289,    -1,  1242,    -1,  1243,    -1,    12,    -1,    11,
    1244,   290,    -1,  1144,    -1,  1246,  1247,    11,  1250,    -1,
     271,    -1,  1248,    -1,    -1,  1248,  1249,    -1,  1426,    -1,
    1470,    -1,  1227,  1251,   272,    -1,  1233,  1252,    -1,    -1,
    1253,  1254,    -1,   289,    -1,  1255,    -1,  1256,    -1,    12,
      -1,    11,  1257,   290,    -1,  1131,    -1,  1259,  1260,    11,
    1263,    -1,   273,    -1,  1261,    -1,    -1,  1261,  1262,    -1,
    1426,    -1,  1470,    -1,  1227,  1264,   274,    -1,  1233,  1265,
      -1,    -1,  1266,  1267,    -1,   289,    -1,  1268,    -1,  1269,
      -1,    12,    -1,    11,  1270,   290,    -1,  1271,    -1,    -1,
    1271,  1272,    -1,  1273,  1274,  1277,    -1,   160,    -1,  1275,
      -1,    -1,  1275,  1276,    -1,  1428,    -1,  1445,    -1,  1278,
      -1,  1279,    -1,    12,    -1,    11,  1280,   161,    -1,    -1,
    1280,  1281,    -1,  1282,  1283,  1284,    -1,   291,    -1,    -1,
    1444,    -1,    11,     6,   292,    -1,  1286,  1287,    11,  1290,
      -1,   279,    -1,  1288,    -1,    -1,  1288,  1289,    -1,  1426,
      -1,  1470,    -1,  1227,  1291,   280,    -1,  1233,  1292,    -1,
      -1,  1293,  1294,    -1,   289,    -1,  1295,    -1,  1296,    -1,
      12,    -1,    11,  1297,   290,    -1,    -1,  1297,  1298,    -1,
    1299,  1300,    -1,   160,    -1,  1301,    -1,  1302,    -1,    12,
      -1,    11,  1497,   161,    -1,  1304,  1305,    11,  1308,    -1,
     281,    -1,  1306,    -1,    -1,  1306,  1307,    -1,  1426,    -1,
    1470,    -1,  1227,  1309,   282,    -1,  1233,  1310,    -1,    -1,
    1311,  1312,    -1,   289,    -1,  1313,    -1,  1314,    -1,    12,
      -1,    11,  1315,   290,    -1,    -1,  1315,  1316,    -1,  1317,
    1318,    -1,   160,    -1,  1319,    -1,  1320,    -1,    12,    -1,
      11,  1640,   161,    -1,  1322,  1323,    11,  1326,    -1,   277,
      -1,  1324,    -1,    -1,  1324,  1325,    -1,  1426,    -1,  1470,
      -1,  1227,  1327,   278,    -1,  1233,  1328,    -1,    -1,  1329,
    1330,    -1,   289,    -1,  1331,    -1,  1332,    -1,    12,    -1,
      11,  1333,   290,    -1,  1132,    -1,  1335,  1336,    11,  1339,
      -1,   275,    -1,  1337,    -1,    -1,  1337,  1338,    -1,  1426,
      -1,  1470,    -1,  1227,  1340,   276,    -1,  1233,  1341,    -1,
      -1,  1342,  1343,    -1,   289,    -1,  1344,    -1,  1345,    -1,
      12,    -1,    11,  1346,   290,    -1,    -1,  1346,  1347,    -1,
    1348,  1349,  1351,    -1,   160,    -1,    -1,  1349,  1350,    -1,
    1491,    -1,  1441,    -1,  1439,    -1,    11,     6,   161,    -1,
    1353,  1354,    11,  1357,    -1,   269,    -1,  1355,    -1,    -1,
    1355,  1356,    -1,  1426,    -1,  1470,    -1,  1227,  1358,   270,
      -1,  1233,  1359,    -1,    -1,  1360,  1361,    -1,   289,    -1,
    1362,    -1,  1363,    -1,    12,    -1,    11,  1364,   290,    -1,
      -1,  1364,  1365,    -1,  1366,  1367,  1369,    -1,   160,    -1,
      -1,  1367,  1368,    -1,  1447,    -1,  1446,    -1,  1441,    -1,
      11,   161,    -1,    12,    -1,  1371,  1372,    11,  1375,    -1,
     283,    -1,  1373,    -1,    -1,  1373,  1374,    -1,  1426,    -1,
    1470,    -1,  1227,  1376,   284,    -1,  1233,  1377,    -1,    -1,
    1378,  1379,    -1,   289,    -1,  1380,    -1,  1381,    -1,    12,
      -1,    11,  1382,   290,    -1,  1154,    -1,  1384,  1385,    11,
    1571,  1386,    -1,   293,    -1,    -1,  1473,    -1,   294,    -1,
    1388,  1389,  1390,    -1,   257,    -1,  1415,    -1,    11,  1392,
    1399,  1406,  1391,    -1,   258,    -1,  1393,  1394,  1395,    -1,
     261,    -1,  1419,    -1,  1396,    -1,  1397,    -1,    12,    -1,
      11,  1398,   262,    -1,  1132,    -1,  1400,  1401,  1402,    -1,
     263,    -1,  1419,    -1,  1403,    -1,  1404,    -1,    12,    -1,
      11,  1405,   264,    -1,  1132,    -1,    -1,  1406,  1407,    -1,
    1408,  1409,  1412,    -1,   259,    -1,  1410,    -1,    -1,  1410,
    1411,    -1,  1436,    -1,  1437,    -1,  1479,    -1,  1482,    -1,
    1413,    -1,  1414,    -1,    12,    -1,    11,  1211,   260,    -1,
     213,     8,     6,     8,    -1,   214,     8,     6,     8,    -1,
     219,     8,     6,     8,    -1,   218,     8,     6,     8,    -1,
     170,     8,     6,     8,    -1,   171,     8,     6,     8,    -1,
     172,     8,     6,     8,    -1,   229,     8,     6,     8,    -1,
     222,     8,     6,     8,    -1,   221,     8,     6,     8,    -1,
     215,     8,     6,     8,    -1,   217,     8,     6,     8,    -1,
     225,     8,     6,     8,    -1,   226,     8,     6,     8,    -1,
     224,     8,     6,     8,    -1,   248,     8,     6,     8,    -1,
     230,     8,     6,     8,    -1,   233,     8,     6,     8,    -1,
     234,     8,     6,     8,    -1,   235,     8,     6,     8,    -1,
     236,     8,     6,     8,    -1,   238,     8,     6,     8,    -1,
     239,     8,     6,     8,    -1,   245,     8,     6,     8,    -1,
     246,     8,     6,     8,    -1,   242,  1100,     6,  1100,    -1,
     247,     8,     6,     8,    -1,   231,     8,     6,     8,    -1,
     232,     8,     6,     8,    -1,   249,     8,  1099,     8,    -1,
     250,     8,  1099,     8,    -1,   241,     8,  1099,     8,    -1,
     240,     8,  1099,     8,    -1,   237,     8,  1099,     8,    -1,
    1450,    -1,  1451,    -1,   211,    -1,   212,     3,  1100,    -1,
    1453,    -1,  1454,    -1,   173,    -1,   174,     3,     8,    -1,
    1456,    -1,  1457,    -1,   193,    -1,   194,     3,     8,    -1,
    1459,    -1,  1460,    -1,   175,    -1,   176,     3,     8,    -1,
    1462,    -1,  1463,    -1,   183,    -1,   184,     3,     8,    -1,
    1465,    -1,  1466,    -1,   179,    -1,   180,     3,     8,    -1,
    1468,    -1,  1469,    -1,   195,    -1,   196,     3,     8,    -1,
    1471,    -1,  1472,    -1,   209,    -1,   210,     3,     8,    -1,
    1474,    -1,  1475,    -1,   185,    -1,   186,     3,     8,    -1,
    1477,    -1,  1478,    -1,   177,    -1,   178,     3,     8,    -1,
    1480,    -1,  1481,    -1,   207,    -1,   208,     3,     8,    -1,
    1483,    -1,  1484,    -1,   181,    -1,   182,     3,     8,    -1,
    1486,    -1,  1487,    -1,   187,    -1,   188,     3,     8,    -1,
    1489,    -1,  1490,    -1,   189,    -1,   190,     3,     8,    -1,
    1492,    -1,  1493,    -1,   191,    -1,   192,     3,     8,    -1,
    1495,    -1,  1496,    -1,   197,    -1,   198,     3,     8,    -1,
    1541,    -1,  1548,    -1,  1504,    -1,  1506,    -1,  1556,    -1,
    1508,    -1,  1510,    -1,  1512,    -1,  1514,    -1,  1568,    -1,
    1516,    -1,  1518,    -1,  1520,    -1,  1524,    -1,  1522,    -1,
    1526,    -1,  1533,    -1,  1528,    -1,  1531,    -1,  1562,    -1,
    1565,    -1,  1498,    -1,  1501,    -1,  1559,    -1,  1535,    -1,
    1537,    -1,  1539,    -1,    -1,   409,  1499,  1500,    -1,    12,
      -1,    11,   410,    -1,    -1,   411,  1502,  1503,    -1,    12,
      -1,    11,   412,    -1,    -1,   413,  1505,  1497,  1497,   414,
      -1,    -1,   371,  1507,  1497,  1497,   372,    -1,    -1,   373,
    1509,  1497,  1497,   374,    -1,    -1,   387,  1511,  1497,   388,
      -1,    -1,   375,  1513,  1497,  1497,   376,    -1,    -1,   369,
    1515,  1497,  1497,   370,    -1,    -1,   377,  1517,  1497,   378,
      -1,    -1,   379,  1519,  1497,   380,    -1,    -1,   391,  1521,
    1497,   392,    -1,    -1,   393,  1523,  1497,   394,    -1,    -1,
     395,  1525,  1497,   396,    -1,    -1,   385,  1527,  1497,   386,
      -1,  1529,  1497,  1530,    -1,   399,    -1,   400,    -1,    -1,
     401,  1532,  1497,   402,    -1,    -1,   389,  1534,  1497,  1497,
    1497,   390,    -1,    -1,   417,  1536,  1571,   418,    -1,    -1,
     419,  1538,  1571,   420,    -1,    -1,   421,  1540,  1571,   422,
      -1,  1542,  1544,  1543,    -1,   415,    -1,    12,    -1,    11,
     416,    -1,    -1,  1544,  1545,    -1,  1482,    -1,  1488,    -1,
    1546,    -1,    -1,   478,     3,  1547,     8,    -1,    -1,   397,
    1549,  1552,  1550,    -1,    12,    -1,    11,   398,    -1,    -1,
      11,  1497,  1551,   398,    -1,    -1,  1552,  1553,    -1,  1554,
      -1,  1555,    -1,   249,     8,  1099,     8,    -1,   245,     8,
       6,     8,    -1,    -1,   381,  1557,  1558,   382,    -1,    -1,
    1558,  1497,    -1,    -1,   405,  1560,  1561,   406,    -1,    -1,
    1561,  1497,    -1,    -1,   403,  1563,  1564,   404,    -1,    -1,
    1564,  1497,    -1,    -1,   407,  1566,  1567,   408,    -1,    -1,
    1567,  1497,    -1,    -1,   383,  1569,  1570,   384,    -1,    -1,
    1570,  1497,    -1,  1572,    -1,  1579,    -1,  1583,    -1,  1587,
      -1,  1591,    -1,  1594,    -1,  1600,    -1,  1603,    -1,  1607,
      -1,  1612,    -1,  1615,    -1,  1618,    -1,  1621,    -1,  1624,
      -1,  1627,    -1,  1630,    -1,  1633,    -1,  1636,    -1,  1597,
      -1,  1573,  1574,  1576,    -1,   449,    -1,    -1,  1574,  1575,
      -1,  1577,    -1,  1578,    -1,    12,    -1,    11,   450,    -1,
     245,     8,     6,     8,    -1,   476,     3,     8,    -1,  1580,
    1582,  1581,    -1,   299,    -1,    12,    -1,    11,   300,    -1,
     245,     8,     6,     8,    -1,  1584,  1586,  1585,    -1,   303,
      -1,    12,    -1,    11,   304,    -1,   245,     8,     6,     8,
      -1,  1588,  1590,  1589,    -1,   307,    -1,    12,    -1,    11,
     308,    -1,   245,     8,     6,     8,    -1,  1592,  1593,    -1,
     423,    -1,  1571,   424,    -1,  1595,  1596,    -1,   425,    -1,
    1571,  1571,   426,    -1,  1598,  1599,    -1,   451,    -1,  1497,
     452,    -1,  1601,  1602,    -1,   453,    -1,  1571,   454,    -1,
    1604,  1605,    11,  1606,    -1,   427,    -1,    -1,  1611,    -1,
    1571,   428,    -1,  1608,  1609,    11,  1610,    -1,   429,    -1,
      -1,  1611,    -1,  1571,   430,    -1,   474,     3,     8,    -1,
    1613,  1614,    -1,   431,    -1,    12,    -1,    11,   432,    -1,
    1616,  1617,    -1,   433,    -1,  1571,  1571,   434,    -1,  1619,
    1620,    -1,   435,    -1,  1571,   436,    -1,  1622,  1623,    -1,
     437,    -1,  1571,  1571,   438,    -1,  1625,  1626,    -1,   439,
      -1,  1571,  1571,   440,    -1,    -1,   441,  1628,  1629,   442,
      -1,    -1,  1629,  1571,    -1,  1631,  1632,    -1,   443,    -1,
    1571,  1639,   444,    -1,  1634,  1635,    -1,   445,    -1,  1497,
    1497,  1497,  1497,  1571,   446,    -1,  1637,  1638,    -1,   447,
      -1,  1571,   448,    -1,  1497,    -1,  1640,    -1,  1641,    -1,
    1647,    -1,  1650,    -1,  1653,    -1,  1656,    -1,  1659,    -1,
    1662,    -1,  1665,    -1,  1668,    -1,  1642,  1644,  1643,    -1,
     461,    -1,    12,    -1,    11,   462,    -1,  1645,    -1,    -1,
    1645,  1646,    -1,  1447,    -1,  1446,    -1,  1648,    11,  1649,
      -1,   471,    -1,  1497,  1497,   472,    -1,  1651,    11,  1652,
      -1,   463,    -1,  1639,  1639,   464,    -1,    -1,   467,    11,
    1654,  1655,   468,    -1,    -1,  1655,  1639,    -1,  1657,    11,
    1658,    -1,   457,    -1,  1639,  1639,   458,    -1,  1660,    11,
    1661,    -1,   459,    -1,  1639,   460,    -1,  1663,    11,  1664,
      -1,   455,    -1,  1639,   456,    -1,  1666,    11,  1667,    -1,
     469,    -1,  1639,  1639,   470,    -1,  1669,    11,  1670,    -1,
     465,    -1,  1639,   466,    -1
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
    2065,  2067,  2074,  2074,  2076,  2083,  2090,  2090,  2096,  2096,
    2098,  2100,  2102,  2112,  2112,  2127,  2132,  2143,  2151,  2160,
    2160,  2162,  2164,  2166,  2166,  2169,  2174,  2188,  2194,  2194,
    2197,  2211,  2216,  2224,  2224,  2228,  2228,  2243,  2248,  2259,
    2267,  2276,  2276,  2278,  2280,  2282,  2282,  2285,  2291,  2306,
    2312,  2312,  2315,  2327,  2332,  2338,  2338,  2342,  2342,  2344,
    2349,  2349,  2351,  2353,  2355,  2358,  2358,  2370,  2370,  2382,
    2382,  2394,  2394,  2406,  2406,  2418,  2418,  2430,  2430,  2442,
    2442,  2458,  2463,  2474,  2482,  2491,  2491,  2493,  2495,  2501,
    2501,  2503,  2508,  2524,  2530,  2530,  2533,  2545,  2550,  2558,
    2558,  2562,  2562,  2568,  2574,  2582,  2590,  2598,  2598,  2600,
    2602,  2602,  2604,  2623,  2639,  2647,  2647,  2650,  2651,  2660,
    2663,  2663,  2665,  2665,  2667,  2672,  2672,  2674,  2679,  2711,
    2731,  2731,  2734,  2738,  2742,  2743,  2744,  2745,  2746,  2747,
    2748,  2749,  2752,  2752,  2754,  2754,  2756,  2758,  2758,  2760,
    2760,  2763,  2778,  2798,  2800,  2800,  2803,  2813,  2814,  2815,
    2816,  2819,  2821,  2821,  2829,  2829,  2831,  2837,  2844,  2844,
    2849,  2849,  2851,  2853,  2855,  2864,  2864,  2880,  2886,  2898,
    2906,  2915,  2915,  2917,  2919,  2921,  2921,  2924,  2929,  2944,
    2946,  2946,  2949,  2960,  2964,  2971,  2971,  2974,  2974,  2992,
    2997,  3011,  3019,  3028,  3028,  3030,  3032,  3034,  3034,  3037,
    3042,  3060,  3062,  3062,  3065,  3076,  3080,  3086,  3093,  3093,
    3097,  3097,  3099,  3104,  3104,  3106,  3108,  3110,  3113,  3113,
    3125,  3125,  3137,  3137,  3149,  3149,  3161,  3161,  3173,  3173,
    3185,  3185,  3197,  3197,  3199,  3205,  3236,  3257,  3257,  3260,
    3264,  3268,  3269,  3270,  3271,  3272,  3273,  3274,  3275,  3278,
    3278,  3280,  3280,  3282,  3284,  3284,  3286,  3286,  3289,  3304,
    3326,  3328,  3328,  3331,  3341,  3342,  3343,  3344,  3347,  3349,
    3349,  3357,  3357,  3359,  3365,  3372,  3372,  3377,  3377,  3379,
    3381,  3383,  3392,  3392,  3408,  3413,  3424,  3432,  3441,  3441,
    3443,  3445,  3447,  3447,  3450,  3455,  3471,  3478,  3478,  3481,
    3492,  3496,  3503,  3503,  3507,  3507,  3525,  3530,  3543,  3551,
    3560,  3560,  3562,  3564,  3566,  3566,  3569,  3574,  3593,  3600,
    3600,  3603,  3614,  3618,  3622,  3628,  3628,  3632,  3632,  3634,
    3639,  3639,  3641,  3643,  3645,  3648,  3648,  3660,  3660,  3672,
    3672,  3684,  3684,  3696,  3696,  3708,  3708,  3720,  3720,  3732,
    3732,  3734,  3740,  3771,  3791,  3791,  3794,  3798,  3802,  3803,
    3804,  3805,  3806,  3807,  3808,  3809,  3812,  3812,  3814,  3814,
    3816,  3818,  3818,  3820,  3820,  3823,  3838,  3858,  3860,  3860,
    3863,  3875,  3876,  3877,  3878,  3881,  3883,  3883,  3892,  3892,
    3894,  3900,  3902,  3902,  3907,  3907,  3909,  3912,  3915,  3915,
    3923,  3928,  3928,  3933,  3933,  3935,  3937,  3940,  3944,  3944,
    3951,  3957,  3967,  3967,  3969,  3971,  3973,  3977,  3977,  3979,
    3985,  4155,  4157,  4159,  4159,  4167,  4167,  4173,  4175,  4183,
    4191,  4200,  4202,  4204,  4204,  4208,  4228,  4246,  4252,  4252,
    4255,  4256,  4257,  4258,  4259,  4260,  4261,  4268,  4276,  4285,
    4285,  4287,  4289,  4291,  4291,  4293,  4300,  4311,  4313,  4313,
    4315,  4317,  4334,  4334,  4336,  4358,  4375,  4387,  4392,  4392,
    4395,  4396,  4397,  4399,  4408,  4417,  4426,  4426,  4510,  4517,
    4539,  4546,  4546,  4548,  4553,  4560,  4566,  4566,  4568,  4573,
    4637,  4643,  4645,  4671,  4678,  4678,  4680,  4685,  4692,  4698,
    4698,  4700,  4703,  4815,  4844,  4851,  4858,  4878,  4884,  4890,
    4896,  4910,  4920,  4931,  4967,  4967,  4969,  4988,  5005,  5013,
    5013,  5016,  5024,  5025,  5029,  5029,  5031,  5034,  5036,  5040,
    5041,  5048,  5050,  5050,  5052,  5053,  5054,  5055,  5090,  5092,
    5106,  5106,  5108,  5110,  5112,  5114,  5114,  5117,  5118,  5119,
    5120,  5121,  5123,  5131,  5131,  5133,  5133,  5135,  5141,  5149,
    5149,  5151,  5151,  5153,  5159,  5167,  5167,  5169,  5169,  5171,
    5177,  5185,  5185,  5187,  5187,  5189,  5195,  5203,  5203,  5205,
    5205,  5207,  5218,  5226,  5234,  5236,  5236,  5238,  5240,  5249,
    5251,  5251,  5253,  5253,  5255,  5264,  5267,  5267,  5269,  5269,
    5272,  5303,  5311,  5313,  5313,  5315,  5317,  5325,  5325,  5327,
    5336,  5338,  5338,  5340,  5340,  5342,  5373,  5383,  5383,  5385,
    5387,  5395,  5395,  5397,  5533,  5535,  5540,  5540,  5542,  5544,
    5546,  5549,  5551,  5556,  5556,  5558,  5560,  5562,  5565,  5567,
    5572,  5572,  5574,  5576,  5578,  5581,  5583,  5588,  5588,  5590,
    5592,  5594,  5597,  5599,  5604,  5604,  5606,  5608,  5610,  5613,
    5615,  5620,  5620,  5622,  5624,  5626,  5629,  5631,  5636,  5636,
    5638,  5640,  5642,  5645,  5674,  5769,  5794,  5822,  5822,  5825,
    5826,  5827,  5828,  5829,  5830,  5973,  5973,  5975,  5977,  6006,
    6008,  6008,  6013,  6031,  6060,  6060,  6063,  6064,  6065,  6066,
    6067,  6068,  6069,  6070,  6071,  6074,  6074,  6076,  6076,  6081,
    6081,  6081,  6082,  6082,  6082,  6083,  6083,  6083,  6084,  6084,
    6086,  6088,  6097,  6103,  6103,  6106,  6110,  6116,  6118,  6118,
    6124,  6134,  6144,  6144,  6146,  6148,  6164,  6167,  6167,  6181,
    6189,  6189,  6191,  6193,  6195,  6201,  6211,  6219,  6219,  6221,
    6223,  6225,  6228,  6230,  6239,  6245,  6245,  6248,  6252,  6258,
    6260,  6262,  6262,  6272,  6280,  6280,  6282,  6284,  6286,  6289,
    6291,  6300,  6306,  6306,  6309,  6313,  6319,  6321,  6324,  6329,
    6340,  6356,  6356,  6358,  6360,  6362,  6364,  6364,  6366,  6373,
    6380,  6399,  6399,  6402,  6403,  6405,  6405,  6407,  6409,  6411,
    6411,  6414,  6416,  6424,  6424,  6429,  6436,  6438,  6447,  6453,
    6453,  6456,  6460,  6467,  6469,  6472,  6476,  6487,  6503,  6503,
    6505,  6507,  6509,  6509,  6511,  6513,  6528,  6528,  6530,  6532,
    6541,  6543,  6552,  6558,  6558,  6561,  6565,  6572,  6574,  6577,
    6581,  6592,  6609,  6609,  6611,  6613,  6615,  6615,  6617,  6619,
    6634,  6634,  6636,  6638,  6648,  6650,  6659,  6665,  6665,  6668,
    6672,  6678,  6680,  6682,  6682,  6692,  6700,  6700,  6702,  6704,
    6706,  6709,  6711,  6720,  6726,  6726,  6729,  6733,  6739,  6741,
    6744,  6748,  6759,  6775,  6775,  6777,  6779,  6781,  6781,  6783,
    6786,  6798,  6798,  6801,  6802,  6803,  6805,  6838,  6840,  6850,
    6856,  6856,  6859,  6863,  6869,  6871,  6874,  6878,  6889,  6902,
    6902,  6904,  6906,  6908,  6908,  6910,  6937,  6948,  6948,  6951,
    6952,  6953,  6955,  6955,  6958,  6960,  6969,  6975,  6975,  6978,
    6982,  6988,  6990,  6992,  6992,  7002,  7010,  7010,  7012,  7014,
    7016,  7019,  7022,  7040,  7040,  7051,  7058,  7068,  7076,  7082,
    7084,  7098,  7110,  7116,  7122,  7122,  7124,  7126,  7128,  7130,
    7140,  7146,  7152,  7152,  7154,  7156,  7158,  7160,  7160,  7165,
    7170,  7182,  7184,  7184,  7187,  7188,  7189,  7199,  7206,  7206,
    7208,  7210,  7228,  7239,  7250,  7272,  7283,  7294,  7305,  7349,
    7373,  7395,  7406,  7418,  7429,  7440,  7451,  7465,  7476,  7490,
    7505,  7520,  7532,  7544,  7564,  7584,  7594,  7624,  7634,  7645,
    7657,  7671,  7684,  7697,  7707,  7717,  7730,  7730,  7732,  7742,
    7760,  7760,  7762,  7769,  7778,  7778,  7780,  7787,  7796,  7796,
    7798,  7805,  7814,  7814,  7816,  7823,  7906,  7906,  7908,  7915,
    7924,  7924,  7926,  7933,  7942,  7942,  7944,  7953,  7969,  7969,
    7971,  7978,  7987,  7987,  7989,  7996,  8005,  8005,  8007,  8014,
    8023,  8023,  8025,  8032,  8041,  8041,  8043,  8050,  8059,  8059,
    8063,  8071,  8080,  8080,  8082,  8089,  8098,  8098,  8100,  8107,
    8258,  8259,  8260,  8261,  8262,  8263,  8264,  8265,  8266,  8267,
    8268,  8269,  8270,  8271,  8272,  8273,  8274,  8275,  8276,  8277,
    8278,  8279,  8280,  8281,  8283,  8284,  8285,  8289,  8289,  8292,
    8293,  8295,  8295,  8298,  8299,  8303,  8303,  8308,  8308,  8313,
    8313,  8318,  8318,  8323,  8323,  8328,  8328,  8333,  8333,  8338,
    8338,  8343,  8343,  8348,  8348,  8353,  8353,  8358,  8358,  8363,
    8365,  8371,  8378,  8378,  8384,  8384,  8396,  8396,  8401,  8401,
    8406,  8406,  8416,  8423,  8429,  8430,  8432,  8433,  8436,  8440,
    8444,  8448,  8447,  8468,  8467,  8474,  8475,  8477,  8476,  8483,
    8484,  8487,  8493,  8501,  8508,  8530,  8530,  8541,  8541,  8544,
    8544,  8558,  8559,  8562,  8562,  8575,  8576,  8579,  8579,  8592,
    8593,  8596,  8596,  8606,  8607,  8613,  8614,  8615,  8616,  8617,
    8618,  8619,  8620,  8621,  8622,  8623,  8624,  8625,  8626,  8627,
    8628,  8629,  8630,  8631,  8634,  8645,  8653,  8653,  8656,  8657,
    8660,  8661,  8663,  8675,  8689,  8694,  8701,  8702,  8704,  8711,
    8716,  8723,  8724,  8726,  8733,  8738,  8745,  8746,  8748,  8755,
    8757,  8763,  8765,  8767,  8773,  8775,  8777,  8783,  8785,  8787,
    8793,  8795,  8797,  8803,  8803,  8808,  8810,  8812,  8818,  8818,
    8823,  8825,  8836,  8838,  8843,  8843,  8845,  8847,  8853,  8856,
    8858,  8864,  8867,  8869,  8875,  8878,  8880,  8886,  8890,  8889,
    8901,  8901,  8908,  8910,  8916,  8918,  8920,  8926,  8929,  8931,
    8937,  9054,  9054,  9058,  9059,  9060,  9061,  9062,  9063,  9064,
    9065,  9066,  9070,  9074,  9083,  9084,  9086,  9093,  9093,  9096,
    9097,  9101,  9103,  9109,  9112,  9114,  9120,  9123,  9123,  9133,
    9134,  9140,  9142,  9148,  9151,  9153,  9159,  9162,  9164,  9170,
    9173,  9175,  9181,  9184,  9186,  9192
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
  "NUMBEROFOTHERMATRIXPROGRAMMINGOPTIONSATT",
  "NUMBEROFOTHERMATRIXVARIABLEOPTIONSATT",
  "NUMBEROFOTHERMATRIXOBJECTIVEOPTIONSATT",
  "NUMBEROFOTHERMATRIXCONSTRAINTOPTIONSATT", "NUMBEROFSOLVEROPTIONSATT",
  "NUMBEROFOTHEROPTIONSATT", "NUMBEROFSOSATT", "SOSIDXATT",
  "GROUPWEIGHTATT", "INSTANCELOCATIONSTART", "INSTANCELOCATIONEND",
  "SOLVERTOINVOKESTART", "SOLVERTOINVOKEEND", "LICENSESTART", "LICENSEEND",
  "USERNAMESTART", "USERNAMEEND", "PASSWORDSTART", "PASSWORDEND",
  "CONTACTSTART", "CONTACTEND", "MINDISKSPACESTART", "MINDISKSPACEEND",
  "MINMEMORYSTART", "MINMEMORYEND", "MINCPUSPEEDSTART", "MINCPUSPEEDEND",
  "MINCPUNUMBERSTART", "MINCPUNUMBEREND", "SERVICETYPESTART",
  "SERVICETYPEEND", "MAXTIMESTART", "MAXTIMEEND",
  "REQUESTEDSTARTTIMESTART", "REQUESTEDSTARTTIMEEND", "DEPENDENCIESSTART",
  "DEPENDENCIESEND", "PATHSTART", "PATHEND", "PATHPAIRSTART",
  "PATHPAIREND", "REQUIREDDIRECTORIESSTART", "REQUIREDDIRECTORIESEND",
  "REQUIREDFILESSTART", "REQUIREDFILESEND", "DIRECTORIESTOMAKESTART",
  "DIRECTORIESTOMAKEEND", "FILESTOMAKESTART", "FILESTOMAKEEND",
  "DIRECTORIESTODELETESTART", "DIRECTORIESTODELETEEND",
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
  "INITIALDUALVALUESSTART", "INITIALDUALVALUESEND",
  "INITIALMATRIXVARIABLEVALUESSTART", "INITIALMATRIXVARIABLEVALUESEND",
  "SOLVEROPTIONSSTART", "SOLVEROPTIONSEND", "SOLVEROPTIONSTART",
  "SOLVEROPTIONEND", "OTHEROPTIONSSTART", "OTHEROPTIONSEND", "HEADERSTART",
  "HEADEREND", "FILENAMESTART", "FILENAMEEND", "FILENAMEEMPTY",
  "FILENAMESTARTANDEND", "FILESOURCESTART", "FILESOURCEEND",
  "FILESOURCEEMPTY", "FILESOURCESTARTANDEND", "FILEDESCRIPTIONSTART",
  "FILEDESCRIPTIONEND", "FILEDESCRIPTIONEMPTY",
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
  "otherConContent", "otherConEmpty", "matrixProgramming",
  "matrixProgrammingStart", "matrixProgrammingAttributes",
  "numberOfOtherMatrixProgrammingOptions", "matrixProgrammingContent",
  "matrixProgrammingEmpty", "matrixProgrammingLaden", "matrixVariables",
  "matrixVariablesStart", "matrixVariablesAttributes",
  "matrixVariablesContent", "matrixVariablesEmpty", "matrixVariablesLaden",
  "matrixVariablesEnd", "initialMatrixVariableValues",
  "initialMatrixVariableValuesStart",
  "initialMatrixVariableValuesAttributes",
  "initialMatrixVariableValuesContent", "initialMatrixVariableValuesEmpty",
  "initialMatrixVariableValuesLaden", "initialMatrixVariableValuesEnd",
  "initialMatrixVarArray", "initialMatrixVar",
  "otherMatrixVariableOptionsArray", "matrixObjectives",
  "matrixConstraints", "otherMatrixProgrammingOptionArray",
  "solverOptions", "solverOptionsStart", "numberOfSolverOptionsATT",
  "solverOptionsContent", "solverOptionsEmpty", "solverOptionsLaden",
  "solverOptionArray", "solverOption", "solverOptionStart",
  "solverOptionAttributes", "solverOptionAttList", "solverOptionATT",
  "solverOptionContent", "solverOptionEmpty", "solverOptionLaden",
  "solverOptionBody", "solverOptionItemArray", "solverOptionItem",
  "solverOptionItemContent", "solverOptionItemEmpty",
  "solverOptionItemLaden", "solverOptionItemBody", "PathList", "Path",
  "PathPair", "PathPairStart", "PathPairAttributes", "PathPairAttList",
  "PathPairAttribute", "PathPairFromATT", "PathPairToATT",
  "PathPairMakeCopyATT", "PathPairEnd", "groupWeightAttribute",
  "groupWeightAtt", "lbValueAttribute", "lbValueAtt", "lbValueAttEmpty",
  "lbValueAttContent", "lbDualValueAttribute", "lbDualValueAtt",
  "lbDualValueAttEmpty", "lbDualValueAttContent", "sosIdxAttribute",
  "sosIdxAtt", "sosIdxAttContent", "ubValueAttribute", "ubValueAtt",
  "ubValueAttEmpty", "ubValueAttContent", "ubDualValueAttribute",
  "ubDualValueAtt", "ubDualValueAttEmpty", "ubDualValueAttContent",
  "numberOfJobIDsATT", "numberOfOtherConstraintOptionsAttribute",
  "numberOfOtherMatrixProgrammingOptionsAttribute",
  "numberOfOtherMatrixVariableOptionsAttribute",
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
  "fileLicenceEmpty", "fileLicenceLaden", "osglNonNegativeIntArrayData",
  "osglIntArrayData", "osglIntVectorElArray", "osglIntVectorEl",
  "osglIntVectorElStart", "osglIntVectorElAttributes",
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
  "enumTypeAttContent", "osglNameATT", "nameAttEmpty", "nameAttContent",
  "osglObjTypeATT", "objTypeAttEmpty", "objTypeAttContent",
  "osglRowMajorATT", "rowMajorAttEmpty", "rowMajorAttContent",
  "osglShapeATT", "shapeAttEmpty", "shape", "osglSolverATT",
  "solverAttEmpty", "solverAttContent", "osglSymmetryATT",
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
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,    32,
       9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   483,   484,   484,   485,   486,   487,   487,   488,   488,
     489,   490,   491,   492,   492,   493,   494,   494,   495,   495,
     496,   497,   497,   498,   498,   499,   500,   501,   501,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     503,   504,   505,   505,   506,   506,   507,   508,   509,   510,
     511,   511,   512,   512,   513,   514,   515,   516,   517,   517,
     518,   518,   519,   520,   521,   522,   523,   523,   524,   525,
     525,   526,   526,   527,   528,   529,   530,   531,   531,   532,
     532,   533,   534,   535,   536,   537,   537,   538,   538,   539,
     540,   541,   542,   543,   543,   544,   544,   545,   546,   547,
     548,   549,   549,   550,   550,   551,   552,   553,   554,   555,
     555,   556,   556,   557,   558,   559,   560,   561,   561,   562,
     563,   563,   564,   564,   565,   566,   567,   568,   569,   570,
     570,   571,   571,   572,   573,   574,   574,   575,   576,   577,
     578,   578,   579,   579,   579,   580,   580,   581,   581,   582,
     583,   583,   584,   584,   585,   586,   587,   587,   588,   588,
     588,   588,   588,   589,   590,   591,   592,   592,   593,   593,
     594,   595,   596,   597,   598,   599,   599,   600,   600,   601,
     602,   603,   604,   605,   606,   606,   607,   607,   608,   609,
     610,   611,   612,   612,   613,   614,   615,   616,   617,   618,
     618,   619,   619,   620,   621,   622,   622,   623,   624,   624,
     625,   626,   626,   627,   627,   628,   629,   630,   630,   631,
     631,   632,   633,   634,   634,   635,   635,   636,   637,   638,
     639,   640,   641,   641,   642,   642,   643,   644,   645,   645,
     646,   647,   647,   648,   649,   649,   650,   650,   651,   652,
     653,   653,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   655,   656,   657,
     657,   658,   658,   659,   659,   660,   661,   662,   663,   664,
     665,   665,   666,   666,   667,   668,   669,   670,   671,   672,
     672,   673,   673,   674,   675,   675,   676,   677,   678,   679,
     679,   680,   680,   681,   682,   683,   684,   684,   685,   685,
     686,   687,   688,   689,   689,   690,   690,   691,   692,   693,
     694,   694,   695,   695,   696,   697,   698,   699,   700,   700,
     701,   701,   702,   703,   703,   704,   705,   706,   707,   708,
     708,   709,   709,   710,   711,   711,   712,   713,   714,   715,
     716,   716,   717,   717,   718,   719,   719,   720,   721,   722,
     723,   724,   724,   725,   725,   726,   727,   727,   728,   729,
     730,   731,   732,   732,   733,   733,   734,   735,   736,   737,
     738,   738,   739,   739,   740,   741,   742,   743,   744,   744,
     745,   745,   746,   747,   747,   748,   749,   750,   751,   752,
     752,   753,   753,   754,   755,   756,   756,   757,   758,   758,
     759,   760,   761,   761,   762,   762,   762,   763,   763,   764,
     765,   766,   767,   767,   768,   769,   770,   770,   771,   771,
     772,   773,   774,   775,   775,   776,   777,   778,   778,   779,
     779,   780,   781,   782,   782,   783,   784,   785,   786,   786,
     787,   787,   787,   788,   788,   789,   789,   790,   791,   792,
     792,   793,   793,   794,   795,   796,   796,   797,   798,   799,
     800,   800,   801,   801,   801,   802,   802,   803,   803,   804,
     805,   805,   806,   807,   808,   809,   809,   810,   810,   811,
     811,   812,   812,   813,   813,   814,   814,   815,   815,   816,
     816,   817,   818,   819,   819,   820,   820,   821,   822,   823,
     823,   824,   825,   826,   827,   827,   828,   828,   828,   829,
     829,   830,   830,   831,   832,   833,   833,   834,   834,   835,
     836,   836,   837,   838,   839,   840,   840,   841,   841,   841,
     842,   842,   843,   843,   844,   845,   845,   846,   847,   848,
     849,   849,   850,   850,   850,   850,   850,   850,   850,   850,
     850,   850,   851,   851,   852,   852,   853,   854,   854,   855,
     855,   856,   857,   858,   859,   859,   860,   860,   860,   860,
     860,   861,   862,   862,   863,   863,   864,   865,   866,   866,
     867,   867,   868,   869,   870,   871,   871,   872,   873,   874,
     874,   875,   875,   876,   877,   878,   878,   879,   880,   881,
     882,   882,   883,   883,   883,   884,   884,   885,   885,   886,
     887,   888,   888,   889,   889,   890,   891,   892,   892,   893,
     894,   895,   896,   896,   897,   897,   897,   897,   898,   898,
     899,   899,   900,   901,   901,   902,   903,   904,   905,   905,
     906,   906,   907,   907,   908,   908,   909,   909,   910,   910,
     911,   911,   912,   912,   913,   914,   915,   916,   916,   917,
     917,   917,   917,   917,   917,   917,   917,   917,   917,   918,
     918,   919,   919,   920,   921,   921,   922,   922,   923,   924,
     925,   926,   926,   927,   927,   927,   927,   927,   928,   929,
     929,   930,   930,   931,   932,   933,   933,   934,   934,   935,
     936,   937,   938,   938,   939,   940,   941,   941,   942,   942,
     943,   944,   945,   945,   946,   947,   948,   949,   949,   950,
     950,   950,   951,   951,   952,   952,   953,   954,   955,   955,
     956,   956,   957,   958,   959,   959,   960,   961,   962,   963,
     963,   964,   964,   964,   964,   965,   965,   966,   966,   967,
     968,   968,   969,   970,   971,   972,   972,   973,   973,   974,
     974,   975,   975,   976,   976,   977,   977,   978,   978,   979,
     979,   980,   981,   982,   983,   983,   984,   984,   984,   984,
     984,   984,   984,   984,   984,   984,   985,   985,   986,   986,
     987,   988,   988,   989,   989,   990,   991,   992,   993,   993,
     994,   994,   994,   994,   994,   995,   996,   996,   997,   997,
     998,   999,  1000,  1000,  1001,  1001,  1002,  1003,  1004,  1004,
    1005,  1006,  1006,  1007,  1007,  1008,  1009,  1010,  1011,  1011,
    1012,  1013,  1014,  1014,  1015,  1016,  1017,  1018,  1018,  1019,
    1020,  1021,  1022,  1023,  1023,  1024,  1024,  1025,  1026,  1027,
    1027,  1028,  1029,  1030,  1030,  1031,  1032,  1033,  1034,  1034,
    1035,  1035,  1035,  1035,  1035,  1035,  1035,  1036,  1036,  1037,
    1037,  1038,  1039,  1040,  1040,  1041,  1042,  1042,  1043,  1043,
    1044,  1045,  1046,  1046,  1047,  1048,  1049,  1050,  1051,  1051,
    1052,  1052,  1052,  1053,  1054,  1055,  1056,  1056,  1057,  1058,
    1059,  1060,  1060,  1061,  1062,  1063,  1064,  1064,  1065,  1066,
    1067,  1068,  1069,  1070,  1071,  1071,  1072,  1073,  1074,  1075,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1089,  1090,  1091,  1092,  1093,
    1093,  1094,  1094,  1094,  1095,  1095,  1096,  1097,  1098,  1099,
    1099,  1100,  1101,  1101,  1102,  1102,  1102,  1102,  1103,  1104,
    1105,  1105,  1106,  1107,  1108,  1109,  1109,  1110,  1110,  1110,
    1110,  1110,  1111,  1112,  1112,  1113,  1113,  1114,  1115,  1116,
    1116,  1117,  1117,  1118,  1119,  1120,  1120,  1121,  1121,  1122,
    1123,  1124,  1124,  1125,  1125,  1126,  1127,  1128,  1128,  1129,
    1129,  1130,  1131,  1132,  1132,  1133,  1133,  1134,  1135,  1136,
    1137,  1137,  1138,  1138,  1139,  1140,  1141,  1141,  1142,  1142,
    1143,  1144,  1144,  1145,  1145,  1146,  1147,  1148,  1148,  1149,
    1150,  1151,  1151,  1152,  1152,  1153,  1154,  1155,  1155,  1156,
    1157,  1158,  1158,  1159,  1160,  1161,  1162,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1168,  1169,  1170,  1171,  1172,  1173,
    1174,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1186,  1187,  1188,  1189,  1190,
    1191,  1192,  1192,  1193,  1194,  1195,  1196,  1197,  1198,  1198,
    1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,  1206,  1207,
    1207,  1207,  1207,  1207,  1207,  1208,  1208,  1209,  1210,  1211,
    1212,  1212,  1213,  1214,  1215,  1215,  1216,  1216,  1216,  1216,
    1216,  1216,  1216,  1216,  1216,  1217,  1217,  1218,  1218,  1219,
    1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,
    1220,  1221,  1222,  1223,  1223,  1224,  1224,  1225,  1226,  1226,
    1227,  1228,  1229,  1229,  1230,  1231,  1232,  1233,  1233,  1234,
    1235,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1241,  1242,
    1243,  1244,  1245,  1246,  1247,  1248,  1248,  1249,  1249,  1250,
    1251,  1252,  1252,  1253,  1254,  1254,  1255,  1256,  1257,  1258,
    1259,  1260,  1261,  1261,  1262,  1262,  1263,  1264,  1265,  1265,
    1266,  1267,  1267,  1268,  1269,  1270,  1271,  1271,  1272,  1273,
    1274,  1275,  1275,  1276,  1276,  1277,  1277,  1278,  1279,  1280,
    1280,  1281,  1282,  1283,  1283,  1284,  1285,  1286,  1287,  1288,
    1288,  1289,  1289,  1290,  1291,  1292,  1292,  1293,  1294,  1294,
    1295,  1296,  1297,  1297,  1298,  1299,  1300,  1300,  1301,  1302,
    1303,  1304,  1305,  1306,  1306,  1307,  1307,  1308,  1309,  1310,
    1310,  1311,  1312,  1312,  1313,  1314,  1315,  1315,  1316,  1317,
    1318,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1324,  1325,
    1325,  1326,  1327,  1328,  1328,  1329,  1330,  1330,  1331,  1332,
    1333,  1334,  1335,  1336,  1337,  1337,  1338,  1338,  1339,  1340,
    1341,  1341,  1342,  1343,  1343,  1344,  1345,  1346,  1346,  1347,
    1348,  1349,  1349,  1350,  1350,  1350,  1351,  1352,  1353,  1354,
    1355,  1355,  1356,  1356,  1357,  1358,  1359,  1359,  1360,  1361,
    1361,  1362,  1363,  1364,  1364,  1365,  1366,  1367,  1367,  1368,
    1368,  1368,  1369,  1369,  1370,  1371,  1372,  1373,  1373,  1374,
    1374,  1375,  1376,  1377,  1377,  1378,  1379,  1379,  1380,  1381,
    1382,  1383,  1384,  1385,  1385,  1386,  1387,  1388,  1389,  1390,
    1391,  1392,  1393,  1394,  1395,  1395,  1396,  1397,  1398,  1399,
    1400,  1401,  1402,  1402,  1403,  1404,  1405,  1406,  1406,  1407,
    1408,  1409,  1410,  1410,  1411,  1411,  1411,  1411,  1412,  1412,
    1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,  1422,
    1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1447,  1448,  1449,  1449,  1450,  1451,
    1452,  1452,  1453,  1454,  1455,  1455,  1456,  1457,  1458,  1458,
    1459,  1460,  1461,  1461,  1462,  1463,  1464,  1464,  1465,  1466,
    1467,  1467,  1468,  1469,  1470,  1470,  1471,  1472,  1473,  1473,
    1474,  1475,  1476,  1476,  1477,  1478,  1479,  1479,  1480,  1481,
    1482,  1482,  1483,  1484,  1485,  1485,  1486,  1487,  1488,  1488,
    1489,  1490,  1491,  1491,  1492,  1493,  1494,  1494,  1495,  1496,
    1497,  1497,  1497,  1497,  1497,  1497,  1497,  1497,  1497,  1497,
    1497,  1497,  1497,  1497,  1497,  1497,  1497,  1497,  1497,  1497,
    1497,  1497,  1497,  1497,  1497,  1497,  1497,  1499,  1498,  1500,
    1500,  1502,  1501,  1503,  1503,  1505,  1504,  1507,  1506,  1509,
    1508,  1511,  1510,  1513,  1512,  1515,  1514,  1517,  1516,  1519,
    1518,  1521,  1520,  1523,  1522,  1525,  1524,  1527,  1526,  1528,
    1529,  1530,  1532,  1531,  1534,  1533,  1536,  1535,  1538,  1537,
    1540,  1539,  1541,  1542,  1543,  1543,  1544,  1544,  1545,  1545,
    1545,  1547,  1546,  1549,  1548,  1550,  1550,  1551,  1550,  1552,
    1552,  1553,  1553,  1554,  1555,  1557,  1556,  1558,  1558,  1560,
    1559,  1561,  1561,  1563,  1562,  1564,  1564,  1566,  1565,  1567,
    1567,  1569,  1568,  1570,  1570,  1571,  1571,  1571,  1571,  1571,
    1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,
    1571,  1571,  1571,  1571,  1572,  1573,  1574,  1574,  1575,  1575,
    1576,  1576,  1577,  1578,  1579,  1580,  1581,  1581,  1582,  1583,
    1584,  1585,  1585,  1586,  1587,  1588,  1589,  1589,  1590,  1591,
    1592,  1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,
    1602,  1603,  1604,  1605,  1605,  1606,  1607,  1608,  1609,  1609,
    1610,  1611,  1612,  1613,  1614,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1628,  1627,
    1629,  1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,
    1638,  1639,  1639,  1640,  1640,  1640,  1640,  1640,  1640,  1640,
    1640,  1640,  1641,  1642,  1643,  1643,  1644,  1645,  1645,  1646,
    1646,  1647,  1648,  1649,  1650,  1651,  1652,  1654,  1653,  1655,
    1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670
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
       3,     5,     0,     3,     1,     1,     0,     1,     1,     1,
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
       1,     1,     0,     1,     1,     1,     1,     6,     0,     3,
       1,     0,     1,     1,     1,     1,     4,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     1,
       0,     0,     0,     0,     2,     0,     3,     1,     1,     1,
       1,     1,     3,     0,     2,     3,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     1,     1,     2,     4,     3,     1,     1,     0,     2,
       1,     1,     1,     3,     3,     3,     2,     1,     1,     4,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     4,
       1,     1,     4,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     2,     0,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     3,     3,     1,     1,     2,     1,
       3,     1,     1,     0,     2,     3,     1,     0,     1,     3,
       3,     1,     1,     2,     1,     3,     1,     0,     2,     3,
       1,     0,     1,     3,     3,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       0,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     0,     2,     1,     1,     3,     0,     2,
       2,     1,     1,     1,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       3,     1,     4,     1,     1,     0,     2,     1,     1,     3,
       2,     0,     2,     1,     1,     1,     1,     3,     1,     4,
       1,     1,     0,     2,     1,     1,     3,     2,     0,     2,
       1,     1,     1,     1,     3,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     3,     0,
       2,     3,     1,     0,     1,     3,     4,     1,     1,     0,
       2,     1,     1,     3,     2,     0,     2,     1,     1,     1,
       1,     3,     0,     2,     2,     1,     1,     1,     1,     3,
       4,     1,     1,     0,     2,     1,     1,     3,     2,     0,
       2,     1,     1,     1,     1,     3,     0,     2,     2,     1,
       1,     1,     1,     3,     4,     1,     1,     0,     2,     1,
       1,     3,     2,     0,     2,     1,     1,     1,     1,     3,
       1,     4,     1,     1,     0,     2,     1,     1,     3,     2,
       0,     2,     1,     1,     1,     1,     3,     0,     2,     3,
       1,     0,     2,     1,     1,     1,     3,     4,     1,     1,
       0,     2,     1,     1,     3,     2,     0,     2,     1,     1,
       1,     1,     3,     0,     2,     3,     1,     0,     2,     1,
       1,     1,     2,     1,     4,     1,     1,     0,     2,     1,
       1,     3,     2,     0,     2,     1,     1,     1,     1,     3,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       2,     0,     3,     1,     2,     0,     5,     0,     5,     0,
       5,     0,     4,     0,     5,     0,     5,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       1,     1,     0,     4,     0,     6,     0,     4,     0,     4,
       0,     4,     3,     1,     1,     2,     0,     2,     1,     1,
       1,     0,     4,     0,     4,     1,     2,     0,     4,     0,
       2,     1,     1,     4,     4,     0,     4,     0,     2,     0,
       4,     0,     2,     0,     4,     0,     2,     0,     4,     0,
       2,     0,     4,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     1,     1,
       1,     2,     4,     3,     3,     1,     1,     2,     4,     3,
       1,     1,     2,     4,     3,     1,     1,     2,     4,     2,
       1,     2,     2,     1,     3,     2,     1,     2,     2,     1,
       2,     4,     1,     0,     1,     2,     4,     1,     0,     1,
       2,     3,     2,     1,     1,     2,     2,     1,     3,     2,
       1,     2,     2,     1,     3,     2,     1,     3,     0,     4,
       0,     2,     2,     1,     3,     2,     1,     6,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     2,     1,     0,     2,     1,
       1,     3,     1,     3,     3,     1,     3,     0,     5,     0,
       2,     3,     1,     3,     3,     1,     2,     3,     1,     2,
       3,     1,     3,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,   969,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   147,     0,
     975,   972,   968,   970,   971,    16,    10,     3,     8,     9,
     149,   208,     0,     0,    24,    19,    21,    22,     0,   974,
      14,   210,   241,     0,     0,   153,   148,   150,   151,    65,
      84,    92,   100,   108,   116,   127,    23,    41,    49,    57,
      76,     0,    26,    27,    29,     0,    30,     0,    31,     0,
      32,    66,    33,     0,    34,     0,    35,     0,    36,     0,
      37,     0,    38,   117,    39,     0,   973,     0,   986,   985,
       0,   992,   991,     0,   998,   997,     0,  1004,  1003,     0,
    1010,  1009,   976,   977,   982,   983,   984,   978,   988,   989,
     990,   979,   994,   995,   996,   980,  1000,  1001,  1002,   981,
    1006,  1007,  1008,    11,   243,   408,     0,     0,   214,   209,
     211,   212,   164,   173,   182,   191,   197,   152,     0,   155,
     156,   158,   166,   159,   175,   160,   184,   161,   192,   162,
       0,    25,    28,     0,    45,    40,    42,    43,     0,    53,
      48,    50,    51,     0,    61,    56,    58,    59,     0,     0,
      67,     0,    80,    75,    77,    78,     0,    88,    83,    85,
      86,     0,    96,    91,    93,    94,     0,   104,    99,   101,
     102,     0,   112,   107,   109,   110,     0,     0,   118,   962,
       0,   128,     0,     0,     0,     0,     0,   410,    15,   412,
       0,   247,   242,   244,   245,   222,   230,   213,     0,   216,
     217,   219,     0,   220,     0,   154,   157,     0,   165,     0,
     174,     0,   183,  1460,     0,     0,   193,  1458,  1459,     0,
     198,    47,    44,     0,    55,    52,     0,    63,    60,     0,
       0,     0,    72,    64,    69,    70,    82,    79,     0,    90,
      87,     0,    98,    95,     0,   106,   103,     0,   114,   111,
       0,     0,     0,   123,   115,   120,   121,     0,     0,     0,
     132,   126,   129,   130,   987,   993,   999,  1005,  1011,     0,
     411,   268,   279,   287,   298,   305,   312,   319,   378,   370,
     326,   337,   359,   348,   386,   397,   246,     0,   249,   250,
     252,   269,   253,     0,   254,     0,   255,     0,   256,     0,
     257,     0,   258,     0,   259,     0,   260,     0,   262,     0,
     261,     0,   263,     0,   264,     0,   265,     0,   266,     0,
     215,   218,     0,   226,   221,   223,   224,     0,   231,     0,
     163,  1496,     0,   167,   169,   168,  1494,  1495,     0,   172,
     176,   178,   177,     0,   181,   185,   187,   186,     0,     0,
     190,     0,   202,   196,   199,   200,    46,    54,    62,    68,
      74,    71,     0,    81,    89,    97,   105,   113,   119,   125,
     122,     0,   962,   961,   964,   965,   966,   967,   963,   131,
     138,     0,   134,   135,   140,   422,   419,   409,   417,   418,
       0,     0,     0,   413,   415,   416,   414,   248,   251,     0,
     270,     0,   283,   278,   280,   281,     0,     0,   288,     0,
       0,     0,     0,     0,     0,     0,   327,     0,   338,     0,
     349,     0,   360,     0,   371,     0,   379,     0,     0,   387,
       0,   398,   228,   225,     0,     0,   235,   229,   232,   233,
     959,   960,     0,   171,     0,     0,   180,     0,   189,  1461,
     195,     0,   201,   140,     0,   204,   205,    73,   124,   938,
     133,   136,     0,   139,   424,     0,   584,   426,     0,     0,
       0,     0,   274,   267,   271,   272,   285,   282,     0,     0,
       0,   292,   286,   289,   290,     0,     0,   302,   297,   299,
     300,     0,   309,   304,   306,   307,     0,   316,   311,   313,
     314,     0,   323,   318,   320,   321,     0,     0,   331,   325,
     328,   329,     0,   342,   336,   339,   340,     0,   353,   347,
     350,   351,     0,   364,   358,   361,   362,     0,   375,   369,
     372,   373,     0,   383,   377,   380,   381,     0,     0,   391,
     385,   388,   389,     0,   402,   396,   399,   400,   227,   234,
     140,     0,   237,   238,   170,  1497,   179,   188,   194,     0,
     203,   206,     0,   146,   137,  1468,     0,  1500,     0,   141,
     144,   142,  1466,  1467,   143,  1498,  1499,   420,   586,   701,
     588,   962,     0,   425,   427,     0,     0,     0,   273,     0,
     276,   277,   284,     0,   291,     0,     0,   294,     0,     0,
     301,     0,   892,   308,     0,   315,     0,   322,     0,     0,
     896,   330,     0,   333,   335,   898,   341,     0,   344,   346,
     352,     0,   355,   357,   363,     0,   366,   368,   374,     0,
     382,     0,     0,   390,     0,     0,   393,   401,   140,     0,
     404,   405,     0,   236,   239,   207,   145,     0,     0,   703,
     818,   705,   962,     0,   587,   589,     0,   433,   430,   423,
     428,   429,  1415,  1421,  1426,   275,   933,     0,   293,   295,
     941,     0,   303,   893,   310,   317,   324,   940,   332,   334,
       0,   897,   343,   345,   354,   356,   365,   367,   376,   384,
     942,     0,   392,   394,     0,   403,   406,   240,  1469,  1501,
     820,   855,   822,   962,     0,   704,   706,     0,   595,   592,
     585,   590,   591,   962,   435,     0,   455,     0,     0,     0,
       0,   907,   895,     0,     0,     0,   899,   900,   901,   902,
       0,   407,   857,   421,     0,   962,     0,   821,   823,     0,
     712,   709,   702,   707,   708,   962,   597,     0,   617,     0,
     939,   431,   457,   477,     0,     0,     0,   436,   296,   894,
     906,     0,     0,     0,   395,   962,     0,   858,     0,   828,
     826,   819,   824,   825,   962,   714,     0,   734,     0,   937,
     593,   619,   640,     0,     0,     0,   598,   479,   499,     0,
       0,   458,     0,     0,   440,   434,   437,   438,   903,   904,
     905,     0,   863,   861,   856,   859,   860,   962,   830,   851,
     831,   934,   710,   736,   757,     0,     0,     0,   715,   642,
     662,     0,     0,   620,     0,     0,   602,   596,   599,   600,
     501,   521,     0,   485,   482,   478,   480,   481,     0,   462,
     456,   459,   460,     0,   439,   446,     0,   442,   443,   448,
     962,     0,   935,   852,   962,     0,   832,   759,   779,     0,
       0,   737,     0,     0,   719,   713,   716,   717,   594,   648,
     645,   641,   643,   644,     0,   624,   618,   621,   622,     0,
     601,   608,     0,   604,   605,   610,   523,   545,     0,     0,
     502,  1055,     0,   487,   486,     0,   461,   468,     0,   464,
     465,   470,  1424,   441,   444,     0,   447,   943,   862,   866,
     864,     0,   853,     0,   838,   835,   829,   833,   834,   711,
     765,   762,   758,   760,   761,     0,   741,   735,   738,   739,
       0,   718,   725,     0,   721,   722,   727,   665,   663,   667,
       0,   650,   649,   623,   630,     0,   626,   627,   632,  1420,
     603,   606,     0,   609,   432,     0,     0,     0,   506,   500,
     503,   504,   483,  1062,   489,   488,     0,     0,     0,  1103,
     463,   466,     0,   469,     0,   454,   445,     0,   449,   450,
     451,   452,     0,  1452,     0,  1484,     0,  1492,     0,     0,
     867,   868,   876,   873,  1450,  1451,   875,   870,   872,  1482,
    1483,   874,  1490,  1491,   871,   863,   962,   840,   850,     0,
     782,   780,   784,     0,   767,   766,   740,   747,     0,   743,
     744,   749,  1414,   720,   723,     0,   726,     0,   666,   646,
     652,   651,   625,   628,     0,   631,     0,   616,   607,   611,
     612,   613,   614,   548,   546,   550,     0,     0,   528,   522,
     525,   526,   505,   512,     0,   508,   509,   514,  1069,   491,
     490,     0,     0,     0,  1015,  1058,  1054,  1056,  1057,     0,
     476,   467,   471,   472,   473,   474,   453,     0,     0,     0,
       0,     0,     0,   880,   865,   877,   878,   869,   827,   854,
     936,     0,     0,     0,   841,     0,   783,   763,   769,   768,
     742,   745,     0,   748,     0,   733,   724,   728,   729,   730,
     731,     0,   682,   664,   679,   680,     0,  1464,     0,  1472,
       0,   668,   670,   669,   674,   678,   677,  1462,  1463,   671,
     676,  1470,  1471,   673,   675,   672,   654,   653,     0,   639,
     629,   913,   926,     0,     0,   633,   636,   910,   911,   912,
     637,   923,   924,   925,   634,   635,   615,     0,   549,     0,
     527,   533,     0,   530,   535,   507,   510,     0,   513,  1076,
     493,   492,     0,     0,  1015,  1065,  1061,  1063,  1064,     0,
       0,  1060,  1013,  1014,     0,   475,     0,     0,  1453,  1485,
    1493,   879,   889,     0,   888,     0,   882,   883,   885,   886,
     887,   837,   836,     0,   847,   844,   839,   842,   843,     0,
     799,   781,   796,   797,  1456,     0,   785,   786,   787,   791,
     793,  1454,  1455,   795,   794,   788,   790,   792,   789,   771,
     770,     0,   756,   746,   918,   931,   962,   962,   750,   753,
     915,   916,   917,   754,   928,   929,   930,   751,   752,   732,
     947,   689,   681,     0,   684,   686,   691,   685,   944,   949,
       0,     0,     0,   656,   655,   638,   962,   962,     0,   565,
     547,   562,   563,  1508,     0,   551,   553,   552,   557,   561,
     560,   554,   556,   558,   555,   559,  1506,  1507,   524,   529,
     531,     0,   534,     0,   520,   511,   515,   516,   517,   518,
    1083,   495,   494,     0,     0,  1015,  1072,  1068,  1070,  1071,
    1067,     0,  1416,     0,     0,  1018,  1016,  1020,  1059,  1435,
    1418,   891,     0,   881,   884,     0,     0,   806,   798,     0,
     801,   803,   808,   802,     0,   773,   772,   755,     0,     0,
     683,   687,     0,   690,   945,     0,   948,     0,  1465,  1473,
     658,   657,   914,   927,   572,   564,     0,   567,   569,   574,
     568,     0,     0,   543,   532,   540,   541,   962,     0,   536,
     539,   908,   537,   920,   921,   538,   519,  1090,   497,   496,
       0,     0,  1015,  1079,  1075,  1077,  1078,  1074,     0,  1066,
       0,     0,  1029,  1025,  1026,  1027,     0,  1019,   890,  1419,
     846,  1105,   845,   848,   849,  1107,   800,   804,     0,   807,
    1457,   775,   774,   962,   962,     0,   700,   688,   698,   692,
     696,   697,   693,   694,   695,  1015,   956,   946,   954,   955,
     950,   951,   953,   952,  1417,   660,   659,   566,   570,     0,
     573,  1509,   542,     0,     0,     0,  1097,   484,   498,     0,
       0,  1015,  1086,  1082,  1084,  1085,  1081,     0,  1073,     0,
       0,  1028,     0,  1017,     0,     0,  1021,  1023,  1022,     0,
    1106,     0,   817,   805,   815,   809,   813,   814,   810,   811,
     812,   777,   776,   919,   932,   699,     0,   958,   647,   661,
       0,   583,   571,   581,   575,   579,   580,   576,   577,   578,
     544,   962,     0,     0,  1015,  1093,  1089,  1091,  1092,  1088,
       0,  1080,  1427,  1030,     0,     0,     0,  1120,  1117,  1104,
    1115,  1116,  1488,     0,     0,     0,   962,  1108,  1111,  1110,
    1114,  1112,  1109,  1486,  1487,  1113,   816,   764,   778,   957,
     582,   922,   909,  1015,  1100,  1096,  1098,  1099,  1095,     0,
    1087,  1024,     0,     0,  1122,     0,  1137,  1124,     0,     0,
       0,     0,  1102,     0,  1094,  1436,  1438,  1118,  1119,     0,
    1123,  1489,     0,     0,   962,  1101,  1377,  1151,  1328,  1183,
    1200,  1302,  1285,  1237,  1261,  1355,  1372,  1138,  1139,  1153,
    1142,  1185,  1145,  1202,  1146,  1239,  1147,  1263,  1143,  1287,
    1144,  1304,  1140,  1330,  1141,  1357,  1148,  1373,  1149,     0,
       0,  1136,  1121,  1448,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1125,  1126,  1129,  1130,  1131,  1132,  1127,
    1128,  1134,  1133,  1446,  1447,  1413,  1422,  1437,     0,  1152,
       0,  1184,     0,  1201,     0,  1238,     0,  1262,     0,  1286,
       0,  1303,     0,  1329,     0,  1356,  1480,     0,     0,  1374,
    1478,  1479,     0,     0,  1378,  1135,   962,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1476,     0,     0,  1154,
    1155,  1156,  1474,  1475,     0,  1186,  1187,  1188,     0,  1203,
    1204,  1205,     0,  1240,  1241,  1242,     0,  1264,  1265,  1266,
       0,  1288,  1289,  1290,     0,  1305,  1306,  1307,     0,  1331,
    1332,  1333,     0,  1358,  1359,  1360,     0,     0,     0,     0,
    1376,  1449,     0,     0,     0,     0,     0,     0,     0,     0,
    1161,  1150,  1158,     0,     0,     0,  1167,  1182,  1167,  1199,
    1167,  1236,  1167,  1260,  1167,  1284,  1167,  1301,  1167,  1327,
    1167,  1354,  1481,  1655,  1660,  1665,  1670,  1673,  1682,  1687,
    1693,  1697,  1700,  1703,  1706,  1708,  1713,  1716,  1719,  1645,
    1676,  1679,     0,  1625,  1646,  1626,     0,  1627,     0,  1628,
       0,  1629,     0,  1630,     0,  1643,     0,  1631,     0,  1632,
    1683,  1633,  1688,  1634,     0,  1635,     0,  1636,     0,  1637,
       0,  1638,     0,  1639,  1640,     0,  1641,     0,  1642,     0,
       0,  1382,     0,     0,  1428,  1439,  1440,  1429,  1430,  1431,
    1432,  1445,  1169,     0,     0,     0,  1015,  1164,  1160,  1162,
    1163,  1477,     0,  1191,     0,  1208,     0,  1245,     0,  1269,
       0,  1293,     0,  1310,     0,  1336,     0,  1363,     0,  1710,
    1375,  1371,     0,     0,     0,     0,     0,     0,     0,     0,
    1669,     0,  1672,  1555,  1547,  1549,  1553,  1557,  1559,  1605,
    1621,  1567,  1551,  1574,  1561,  1563,  1565,  1593,  1570,  1572,
    1613,  1609,  1617,  1537,  1541,  1545,  1583,  1576,  1578,  1580,
       0,  1531,  1532,  1512,  1513,  1515,  1516,  1517,  1518,  1520,
    1521,  1522,  1524,  1523,  1525,  1527,     0,  1528,  1526,  1534,
    1535,  1536,  1510,  1586,  1511,  1514,  1533,  1529,  1530,  1519,
    1675,     0,  1678,     0,     0,  1684,     0,  1689,     0,  1694,
    1692,     0,  1696,     0,  1699,     0,  1702,     0,  1705,     0,
    1712,     0,  1715,     0,  1718,  1412,  1390,  1397,     0,     0,
    1383,  1157,  1176,  1159,     0,  1015,  1172,  1168,  1170,  1171,
    1166,  1012,     0,  1423,  1193,  1190,     0,  1189,  1210,  1207,
       0,  1206,  1247,  1244,     0,  1243,  1271,  1268,     0,  1267,
    1295,  1292,     0,  1291,  1312,  1309,     0,  1308,  1338,  1335,
       0,  1334,  1365,  1362,     0,  1361,     0,     0,  1650,     0,
       0,  1647,  1644,  1648,  1649,     0,     0,  1656,  1654,     0,
       0,  1661,  1659,     0,     0,  1666,  1664,  1671,     0,     0,
       0,     0,     0,     0,     0,  1607,  1623,     0,     0,     0,
       0,     0,     0,  1599,     0,  1615,  1611,  1619,     0,     0,
       0,     0,     0,     0,  1677,     0,     0,  1680,     0,     0,
       0,  1695,     0,  1701,     0,     0,  1758,  1752,  1755,  1733,
    1745,  1764,     0,  1761,  1742,  1721,     0,  1722,  1723,  1737,
    1724,     0,  1725,     0,  1726,  1727,     0,  1728,     0,  1729,
       0,  1730,     0,  1731,     0,     0,  1720,     0,     0,  1391,
    1015,  1386,  1381,  1384,  1385,  1033,  1179,  1175,  1177,  1178,
    1174,     0,  1165,  1015,  1196,  1192,  1194,  1195,  1216,  1213,
    1209,  1211,  1212,  1252,  1250,  1246,  1248,  1249,  1276,  1274,
    1270,  1272,  1273,  1015,  1298,  1294,  1296,  1297,  1317,  1315,
    1311,  1313,  1314,  1343,  1341,  1337,  1339,  1340,  1047,  1368,
    1364,  1366,  1367,  1709,  1711,  1651,     0,     0,     0,  1657,
       0,  1662,     0,  1667,  1674,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1539,  1538,     0,  1543,  1542,
       0,     0,     0,     0,  1571,  1569,     0,  1584,     0,  1588,
    1589,  1582,  1587,  1590,  1691,     0,  1681,     0,  1686,  1698,
    1704,  1707,  1747,  1714,     0,  1736,     0,     0,     0,     0,
       0,     0,     0,     0,  1380,  1400,  1379,  1398,  1402,  1015,
    1394,  1389,  1392,  1393,  1388,     0,     0,  1181,  1031,  1032,
       0,  1173,  1198,     0,     0,  1215,     0,     0,  1300,     0,
       0,     0,  1370,  1046,     0,     0,  1653,  1658,  1663,  1668,
       0,     0,     0,     0,  1558,  1560,  1606,  1608,  1622,  1624,
    1568,  1552,     0,  1562,  1564,  1566,     0,  1595,     0,     0,
    1594,  1600,  1601,  1602,  1573,  1614,  1616,  1610,  1612,  1618,
    1620,  1540,  1544,     0,  1577,  1579,  1581,  1585,  1591,  1685,
    1690,  1749,     0,  1734,  1732,     0,     0,  1740,  1739,  1738,
       0,  1741,     0,  1744,     0,  1751,     0,  1754,     0,  1757,
       0,  1760,     0,  1763,     0,     0,  1401,  1396,     0,  1387,
       0,  1036,  1034,  1037,  1180,  1197,  1214,  1219,  1217,  1221,
    1255,  1251,  1253,     0,  1279,  1275,  1277,     0,  1299,  1320,
    1316,  1318,  1321,  1346,  1342,  1344,  1347,  1050,  1048,  1051,
    1369,  1652,  1556,  1548,  1550,  1554,     0,  1596,  1597,     0,
       0,  1546,     0,     0,  1735,     0,     0,     0,     0,     0,
    1756,  1759,     0,  1765,     0,  1120,  1410,  1399,  1408,  1409,
       0,     0,  1403,  1404,  1405,  1406,  1407,  1395,     0,  1044,
    1040,  1041,  1042,     0,  1038,     0,  1220,     0,  1258,  1254,
    1256,  1257,     0,  1282,  1278,  1280,  1281,     0,     0,     0,
    1052,  1575,     0,     0,     0,  1592,  1748,  1750,     0,     0,
    1743,  1746,  1753,  1762,  1717,     0,     0,     0,     0,  1043,
       0,  1035,  1229,  1227,  1218,  1225,  1226,     0,     0,  1222,
    1223,  1224,     0,     0,     0,  1504,     0,  1322,  1319,  1325,
    1324,  1323,  1502,  1503,     0,  1353,  1348,  1345,  1351,  1350,
    1349,     0,  1049,  1598,  1604,  1603,  1444,  1443,  1411,     0,
       0,  1045,     0,     0,     0,     0,  1259,  1283,     0,     0,
    1352,     0,  1433,  1434,  1039,  1228,  1232,  1230,  1233,     0,
       0,  1326,  1505,  1053,     0,     0,  1234,  1425,  1442,     0,
       0,  1231,     0,     0,  1441,  1235
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
     681,   735,   736,   737,   776,   815,   816,   817,   866,   867,
     868,   869,   925,   926,   998,   996,   773,   774,   810,   860,
     861,   862,   918,   919,   920,   921,   992,   993,  1092,  1091,
     808,   809,   855,   856,   857,   912,   913,   984,  1079,  1190,
    1321,  1398,  1467,   851,   852,   909,   979,   980,   981,  1074,
    1075,  1076,  1077,  1187,  1188,  1316,  1315,   907,   908,   976,
    1069,  1070,  1071,  1182,  1183,  1184,  1311,  1312,  1389,  1384,
    1385,  1386,   974,  1064,  1065,  1177,  1178,  1295,  1290,  1291,
    1292,  1376,  1377,  1378,  1379,  1459,  1460,  1514,  1512,  1513,
     599,   600,   673,   674,   730,   731,   732,   767,   768,   769,
     805,   847,   848,   849,   902,   903,   904,   905,   972,   973,
    1059,  1058,   802,   803,   842,   896,   897,   898,   965,   966,
     967,   968,  1054,  1055,  1165,  1160,   840,   841,   891,   892,
     893,   960,   961,  1050,  1156,  1283,  1370,  1455,  1508,   888,
     958,   959,  1047,  1048,  1141,  1133,  1134,  1135,  1273,  1274,
    1275,  1276,  1362,  1363,  1439,  1437,  1438,   670,   671,   724,
     725,   762,   763,   764,   796,   797,   798,   837,   885,   886,
     887,   953,   954,   955,   956,  1045,  1046,  1127,  1126,   834,
     835,   880,   947,   948,   949,  1038,  1039,  1040,  1041,  1122,
    1123,  1258,  1253,   878,   879,   942,   943,   944,  1033,  1034,
    1118,  1249,  1355,  1431,  1501,  1557,   939,  1031,  1032,  1115,
    1116,  1236,  1231,  1232,  1233,  1349,  1350,  1351,  1352,  1428,
    1429,  1495,  1493,  1494,   721,   722,   756,   757,   791,   792,
     793,   829,   830,   875,   936,   937,   938,  1222,  1028,  1029,
    1113,  1226,  1227,  1228,  1422,  1346,  1423,  1111,   873,   932,
    1025,   753,   754,   786,   824,   825,   826,   871,   930,   931,
    1009,  1010,  1011,  1104,  1105,  1106,  1215,  1216,  1217,  1218,
    1219,  1220,  1342,   621,   622,   634,   635,   700,   701,   746,
     747,   748,   749,   742,  1390,  1391,  1166,  1167,  1168,  1169,
    1259,  1260,  1261,  1262,  1392,  1393,  1394,  1170,  1171,  1172,
    1173,  1263,  1264,  1265,  1266,   428,   726,   758,   876,   675,
     201,   604,   436,   430,   449,   787,  1277,  1278,  1279,  1365,
    1366,  1450,  1447,  1448,  1449,  1506,   463,   277,   278,   398,
      10,    11,    22,    23,    24,    38,    39,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,  1980,  1981,
    1202,  1336,  1337,  1416,  1417,  1486,  1483,  1203,  1413,  1414,
    1415,  2247,  2248,  2342,  2343,  2413,  2451,  2249,  2410,  2411,
    2412,  2262,  2263,  2368,  2369,  2429,  2482,   914,   915,  1086,
    1087,  1088,  1204,   985,   986,  1196,  1197,  1198,  1331,  1080,
    1081,  1327,  1328,  1329,  1408,  1191,  1192,  1404,  1405,  1406,
    1477,  1322,  1323,  1473,  1474,  1475,  1530,  1399,  1400,  1526,
    1527,  1528,  1569,  1468,  1469,  1565,  1566,  1567,  1583,   988,
    1424,  1425,  1489,  1490,  1547,  1539,  1540,  1541,  1575,  1576,
    1577,  1589,  1590,  1643,  1632,  1588,  1607,  1608,  1609,  1658,
    1659,  1699,  1751,  1843,  1752,  1753,  1848,  1849,  1850,  1982,
    1844,  1845,  1977,  1978,  1979,  2121,  1973,  1974,  2117,  2118,
    2119,  2250,  1610,  1611,  1660,  1661,  1705,  1757,  1854,  1985,
    1986,  2125,  2126,  2127,  2253,  1612,  1613,  1662,  1663,  1709,
    1759,  1856,  1989,  1990,  2130,  2131,  2132,  2254,  2255,  2348,
    2349,  2415,  2416,  2459,  2454,  2455,  2456,  2493,  2507,  2508,
    2515,  2521,  1614,  1615,  1664,  1665,  1713,  1761,  1858,  1993,
    1994,  2135,  2136,  2137,  2256,  2352,  2353,  2419,  2420,  2421,
    1616,  1617,  1666,  1667,  1717,  1763,  1860,  1997,  1998,  2140,
    2141,  2142,  2257,  2356,  2357,  2424,  2425,  2426,  1618,  1619,
    1668,  1669,  1721,  1765,  1862,  2001,  2002,  2145,  2146,  2147,
    2259,  1620,  1621,  1670,  1671,  1725,  1767,  1864,  2005,  2006,
    2150,  2151,  2152,  2260,  2361,  2362,  2427,  2467,  2468,  1622,
    1623,  1672,  1673,  1729,  1769,  1866,  2009,  2010,  2155,  2156,
    2157,  2261,  2365,  2366,  2428,  2476,  2477,  1624,  1625,  1674,
    1675,  1733,  1771,  1868,  2013,  2014,  2160,  2161,  2162,  2264,
    1626,  1627,  1678,  1871,  1628,  1629,  1683,  1740,  2236,  1832,
    1833,  1969,  2112,  2113,  2114,  2245,  1967,  1968,  2108,  2241,
    2242,  2243,  2338,  2107,  2237,  2238,  2335,  2336,  2402,  2397,
    2398,  2399,  1684,  1548,   838,   414,   989,  1142,  1012,  1114,
     806,   415,  1549,  1700,   777,  2460,   416,  1334,  1644,  1645,
    1646,  1647,  1648,  2403,  2404,   999,  1487,  1550,  1488,  1649,
    1650,  2516,  2461,  2317,  2318,  1651,  1652,  1653,  1654,  1013,
    1014,  1015,  1240,  1241,  1242,  1016,   237,   238,  1146,  1147,
    1148,  1017,   592,   593,  1150,  1151,  1152,  1701,  1702,  1703,
    1679,  1680,  1681,  1018,  1019,  1020,  1552,  1553,  1554,  1021,
    1022,  1023,   355,   356,   357,  1024,   595,   596,  2471,  2472,
    2473,  1305,  1306,  1307,  2085,  1911,  2058,  2196,  1912,  2059,
    2199,  1913,  2060,  1914,  2040,  1915,  2041,  1916,  2048,  1917,
    2042,  1918,  2039,  1919,  2043,  1920,  2044,  1921,  2050,  1922,
    2051,  1923,  2052,  1924,  2047,  1925,  1926,  2205,  1927,  2054,
    1928,  2049,  1929,  2061,  1930,  2062,  1931,  2063,  1932,  1933,
    2211,  2066,  2212,  2213,  2382,  1934,  2053,  2290,  2432,  2189,
    2291,  2292,  2293,  1935,  2045,  2181,  1936,  2056,  2192,  1937,
    2055,  2191,  1938,  2057,  2193,  1939,  2046,  2182,  1792,  1793,
    1794,  1872,  2021,  2022,  2023,  2024,  1795,  1796,  2028,  1874,
    1797,  1798,  2032,  1876,  1799,  1800,  2036,  1878,  1801,  1802,
    1880,  1803,  1804,  1882,  1805,  1806,  1940,  1807,  1808,  1942,
    1809,  1810,  1944,  2216,  1811,  1812,  1946,  2218,  1945,  1813,
    1814,  1950,  1815,  1816,  1952,  1817,  1818,  1954,  1819,  1820,
    1956,  1821,  1822,  1958,  1823,  1869,  2016,  1824,  1825,  1960,
    1826,  1827,  1962,  1828,  1829,  1964,  2086,  2087,  2088,  2089,
    2314,  2224,  2225,  2319,  2090,  2091,  2321,  2092,  2093,  2323,
    2094,  2311,  2383,  2095,  2096,  2325,  2097,  2098,  2327,  2099,
    2100,  2329,  2101,  2102,  2331,  2103,  2104,  2333
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2227
static const yytype_int16 yypact[] =
{
     489, -2227, -2227,   100,    -5,   116, -2227, -2227,   140,   -86,
   -2227,   509, -2227,   525, -2227, -2227, -2227, -2227,    -1,   542,
   -2227, -2227, -2227, -2227, -2227,    -5, -2227, -2227, -2227, -2227,
   -2227,   -88,   546,    94, -2227, -2227, -2227, -2227,   191,   871,
     140, -2227,     7,   548,   -16, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,    41,    43, -2227, -2227,   563, -2227,   699, -2227,   778,
   -2227,   361, -2227,   780, -2227,   785, -2227,   787, -2227,   792,
   -2227,   850, -2227,   380, -2227,   398, -2227,   443, -2227, -2227,
     453, -2227, -2227,   463, -2227, -2227,   465, -2227, -2227,   467,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227,   149,   852,   -23, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,   168,    60,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,   696, -2227,
     398, -2227, -2227,    15, -2227, -2227, -2227, -2227,    14, -2227,
   -2227, -2227, -2227,    16, -2227, -2227, -2227, -2227,   491,   862,
   -2227,    12, -2227, -2227, -2227, -2227,   308, -2227, -2227, -2227,
   -2227,   305, -2227, -2227, -2227, -2227,   128, -2227, -2227, -2227,
   -2227,   300, -2227, -2227, -2227, -2227,   493,   864, -2227, -2227,
     866, -2227,   373,   376,   369,   379,   377, -2227, -2227, -2227,
      65, -2227, -2227, -2227, -2227, -2227, -2227, -2227,   204,    34,
   -2227, -2227,   874, -2227,   398, -2227, -2227,   523,   244,   527,
     244,   531,   244, -2227,   541,   535, -2227, -2227, -2227,   940,
   -2227, -2227, -2227,   209, -2227, -2227,   215, -2227, -2227,   218,
     575,   311, -2227, -2227, -2227, -2227, -2227, -2227,   219, -2227,
   -2227,   536, -2227, -2227,   538, -2227, -2227,   571, -2227, -2227,
     573,   620,   203, -2227, -2227, -2227, -2227,   626,    19,  -105,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,   958,
     292, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227,   310,   676, -2227,
   -2227,   692, -2227,   964, -2227,   617, -2227,   618, -2227,   618,
   -2227,   618, -2227,   618, -2227,   621, -2227,   621, -2227,   621,
   -2227,   621, -2227,   618, -2227,   618, -2227,   663, -2227,   398,
   -2227, -2227,   112, -2227, -2227, -2227, -2227,   970, -2227,   876,
   -2227, -2227,   697, -2227, -2227, -2227, -2227, -2227,   876, -2227,
   -2227, -2227, -2227,   876, -2227, -2227, -2227, -2227,   700,   698,
   -2227,  -100, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227,   665, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,   657, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,   587,   367, -2227, -2227,   403, -2227, -2227, -2227, -2227,
     716,   718,   721, -2227, -2227, -2227, -2227, -2227, -2227,   987,
   -2227,   121, -2227, -2227, -2227, -2227,   723,  1014, -2227,   725,
    1016,  1018,  1020,  1025,   727,  1027, -2227,  1029, -2227,  1034,
   -2227,  1175, -2227,  1177, -2227,  1179, -2227,   729,  1181, -2227,
    1183, -2227, -2227, -2227,   670,   -99, -2227, -2227, -2227, -2227,
   -2227, -2227,   691, -2227,   746,   702, -2227,   704, -2227, -2227,
   -2227,   694, -2227, -2227,   632,   367, -2227, -2227, -2227, -2227,
   -2227, -2227,  1185,   372, -2227,   437,   456,   737,   789,   794,
     799,   171, -2227, -2227, -2227, -2227, -2227, -2227,   734,   803,
     -53, -2227, -2227, -2227, -2227,   805,   390, -2227, -2227, -2227,
   -2227,   357, -2227, -2227, -2227, -2227,   301, -2227, -2227, -2227,
   -2227,   266, -2227, -2227, -2227, -2227,   807,   307, -2227, -2227,
   -2227, -2227,   251, -2227, -2227, -2227, -2227,   240, -2227, -2227,
   -2227, -2227,   144, -2227, -2227, -2227, -2227,   315, -2227, -2227,
   -2227, -2227,    47, -2227, -2227, -2227, -2227,   809,  1097, -2227,
   -2227, -2227, -2227,   -97, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,   686,   367, -2227, -2227, -2227, -2227, -2227, -2227,  1185,
   -2227, -2227,   471, -2227, -2227, -2227,   816, -2227,   824, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,   520,
     814, -2227,  1189, -2227, -2227,   845,   847,   849, -2227,   797,
   -2227, -2227, -2227,   857, -2227,   888,   -52, -2227,   893,   894,
   -2227,   409, -2227, -2227,   371, -2227,   350, -2227,   268,   899,
   -2227, -2227,   309, -2227, -2227, -2227, -2227,   278, -2227, -2227,
   -2227,   241, -2227, -2227, -2227,   248, -2227, -2227, -2227,   334,
   -2227,   132,   901, -2227,   900,  1101, -2227, -2227, -2227,   786,
     367, -2227,  1185, -2227, -2227, -2227, -2227,   907,   911, -2227,
     628,   883, -2227,  1279, -2227, -2227,   919,   823, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227,   925, -2227, -2227,
   -2227,   927, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
    1282,   494, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,   929, -2227, -2227,  1185, -2227, -2227, -2227, -2227, -2227,
   -2227,   811,   896, -2227,  1298, -2227, -2227,   933,   825, -2227,
   -2227, -2227, -2227, -2227, -2227,   623,   839,   724,   602,   879,
     898, -2227, -2227,   969,   980,   993, -2227, -2227, -2227, -2227,
     915, -2227, -2227, -2227,   961, -2227,  1300, -2227, -2227,  1004,
     914, -2227, -2227, -2227, -2227, -2227, -2227,   726,   930,   828,
   -2227, -2227, -2227,   944,   724,  1046,  1304, -2227, -2227, -2227,
   -2227,  1048,  1050,  1052, -2227, -2227,  1308, -2227,  1056,   767,
   -2227, -2227, -2227, -2227, -2227, -2227,   754,   948,   853, -2227,
   -2227, -2227,   966,   828,  1068,  1310, -2227, -2227,   968,  1312,
    1314, -2227,  1074,   -65, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,  1095, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
    1063, -2227, -2227, -2227,   997,   853,  1103,  1316, -2227, -2227,
   -2227,  1318,  1320, -2227,  1107,   -55, -2227, -2227, -2227, -2227,
   -2227,  1003,   724,   772, -2227, -2227, -2227, -2227,   -66, -2227,
   -2227, -2227, -2227,  1109, -2227, -2227,  1022,   802, -2227, -2227,
   -2227,  1206, -2227, -2227, -2227,  1326, -2227, -2227, -2227,  1328,
    1330, -2227,  1117,   -18, -2227, -2227, -2227, -2227,   776,   772,
   -2227, -2227, -2227, -2227,   -42, -2227, -2227, -2227, -2227,  1130,
   -2227, -2227,  1008,   827, -2227, -2227, -2227, -2227,  1099,  1333,
   -2227, -2227,  1033,   815, -2227,   976, -2227, -2227,  1043,   835,
   -2227, -2227, -2227, -2227, -2227,  1335,   127, -2227, -2227, -2227,
   -2227,   813, -2227,  1152,  1030, -2227, -2227, -2227, -2227,   817,
     772, -2227, -2227, -2227, -2227,   -64, -2227, -2227, -2227, -2227,
    1154, -2227, -2227,  1039,   859, -2227, -2227, -2227, -2227, -2227,
    1057,   815, -2227, -2227, -2227,  1055,   863, -2227, -2227, -2227,
   -2227, -2227,  1337,   127,   829,  1170,  1339,   -68, -2227, -2227,
   -2227, -2227, -2227, -2227,   870, -2227,   976,  1172,  1341, -2227,
   -2227, -2227,  1343,   127,   889, -2227, -2227,  1176, -2227, -2227,
   -2227, -2227,  1201, -2227,  1208, -2227,  1210, -2227,  1214,  1345,
     813, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227,   923, -2227, -2227, -2227,   986,
   -2227, -2227, -2227,  1114,   815, -2227, -2227, -2227,  1102,   918,
   -2227, -2227, -2227, -2227, -2227,  1347,   127,  1349,   784, -2227,
     870, -2227, -2227, -2227,  1351,   152,   917, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227,  1227,  1251, -2227, -2227,
   -2227, -2227, -2227, -2227,  1118,   943, -2227, -2227, -2227,   931,
   -2227,   976,  1355,  1258,  1098, -2227, -2227, -2227, -2227,   950,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1264,  1266,  1268,
    1270,  1272,   184, -2227, -2227, -2227, -2227, -2227, -2227,  1146,
   -2227,   984,  1276,  1357, -2227,  1359,  1124, -2227,   870, -2227,
   -2227, -2227,  1361,    52,   978, -2227, -2227, -2227, -2227, -2227,
   -2227,  -110, -2227, -2227, -2227, -2227,  1278, -2227,  1332, -2227,
    1461, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227,   931, -2227,  1151, -2227,
   -2227, -2227, -2227,  1463,  1464, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1363,   604,  1460,
   -2227, -2227,  1263, -2227, -2227, -2227, -2227,  1367,   127, -2227,
    1131, -2227,   976,  1369,  1098, -2227, -2227, -2227, -2227,  1465,
    1221, -2227,  1311, -2227,  1134, -2227,  1466,  1467, -2227, -2227,
   -2227, -2227, -2227,  1471, -2227,  1348,   322, -2227, -2227, -2227,
   -2227, -2227, -2227,  1472, -2227, -2227, -2227, -2227, -2227,   -84,
   -2227, -2227, -2227, -2227, -2227,  1476, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,   931,
   -2227,  1171, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227,  1126,  1169, -2227, -2227,  1321, -2227, -2227,
    1478,  1477,  1479,  1131, -2227, -2227, -2227, -2227,   -49, -2227,
   -2227, -2227, -2227, -2227,  1483, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,  1371,    64,  1173, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,  1147, -2227,   976,  1373,  1098, -2227, -2227, -2227, -2227,
   -2227,  1155, -2227,  1482,  1375, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227,  1327, -2227, -2227,  1484,   -61, -2227, -2227,  1140,
    1186, -2227, -2227,  1321,  1488,  1131, -2227, -2227,   876,   876,
   -2227, -2227,  1377,    50, -2227,  1379,   233,  1489, -2227, -2227,
    1147, -2227, -2227, -2227, -2227, -2227,  1144,  1182, -2227, -2227,
    1321,  1492,   -60, -2227, -2227, -2227, -2227, -2227,  1493, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1159, -2227,
     976,  1381,  1098, -2227, -2227, -2227, -2227, -2227,  1167, -2227,
    1498,    67, -2227, -2227, -2227, -2227,  1494,  1148, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1385,    50,
   -2227,  1147, -2227, -2227, -2227,  1192, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227,  1098, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227,  1159, -2227, -2227, -2227,  1387,
      50, -2227, -2227,   -58,  1501,   876, -2227, -2227, -2227,   976,
    1389,  1098, -2227, -2227, -2227, -2227, -2227,  1178, -2227,  1500,
    1340, -2227,  1505, -2227,  1504,  1506, -2227, -2227, -2227,  1391,
     325,  1203, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,  1159, -2227, -2227, -2227, -2227,  1352, -2227, -2227, -2227,
    1198, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227,  1509,  1393,  1098, -2227, -2227, -2227, -2227, -2227,
    1180, -2227, -2227, -2227,  1358,  1512,  1515,  1267, -2227, -2227,
   -2227, -2227, -2227,  1519,  1516,  1517, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227,  1098, -2227, -2227, -2227, -2227, -2227,  1184,
   -2227, -2227,  1520,  1521, -2227,  1230, -2227, -2227,  1523,  1526,
    1527,  1528, -2227,  1191, -2227, -2227, -2227, -2227,   566,  1395,
     658, -2227,  1529,  1530, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1223, -2227,  1323,
    1284, -2227, -2227, -2227,  1524,  1532,  1533,  1534,  1535,  1536,
    1537,  1538,  1539, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1540,   111,
    1541,   111,  1542,   111,  1543,   111,  1544,   111,  1545,   111,
    1546,   111,  1547,   111,  1548,   111, -2227,  1557,  1550, -2227,
   -2227, -2227,  1554,  1552, -2227, -2227, -2227,  1558,  1559,  1560,
    1561,  1562,  1563,  1564,   876,  1265, -2227,  1568,  1565, -2227,
   -2227, -2227, -2227, -2227,  1265, -2227, -2227, -2227,  1265, -2227,
   -2227, -2227,  1265, -2227, -2227, -2227,  1265, -2227, -2227, -2227,
    1265, -2227, -2227, -2227,  1265, -2227, -2227, -2227,  1265, -2227,
   -2227, -2227,  1265, -2227, -2227, -2227,  1566,   176,  1569,  1287,
   -2227, -2227,  1570,  1571,  1572,  1573,  1574,  1575,  1577,  1578,
   -2227, -2227,   -74,  1399,  1579,  1582,  1262, -2227,  1262, -2227,
    1262, -2227,  1262, -2227,  1262, -2227,  1262, -2227,  1262, -2227,
    1262, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227,  1283, -2227, -2227, -2227,  1331, -2227,  1344, -2227,
    1346, -2227,   176, -2227,   176, -2227,   868, -2227,   176, -2227,
    1116, -2227,  1116, -2227,  1401, -2227,   176, -2227,   176, -2227,
     176, -2227,   176, -2227, -2227,   176, -2227,   868, -2227,   176,
    1584, -2227,  1309,   976, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227,  1325,  1305,  1403,  1098, -2227, -2227, -2227,
   -2227, -2227,  1587,  1307,  1329,  1313,  1324,  1315,  1317,  1319,
    1334,  1322,  1336,  1338,  1342,  1350,  1353,  1354,  1356, -2227,
   -2227, -2227,     1,  1591,  1405,  1592,  1407,  1595,  1409,  1193,
   -2227,   176, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
    1153, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227,   868, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,  1156, -2227,  1603,  1596, -2227,  1598, -2227,  1187, -2227,
   -2227,   176, -2227,  1190, -2227,   176, -2227,   176, -2227,   288,
   -2227,   868, -2227,  1164, -2227, -2227, -2227, -2227,   976,  1411,
   -2227, -2227, -2227, -2227,  1413,  1098, -2227, -2227, -2227, -2227,
   -2227, -2227,  1360, -2227, -2227, -2227,  1415, -2227, -2227, -2227,
    1417, -2227, -2227, -2227,  1419, -2227, -2227, -2227,  1421, -2227,
   -2227, -2227,  1423, -2227, -2227, -2227,  1425, -2227, -2227, -2227,
    1427, -2227, -2227, -2227,  1429, -2227,   153,  1163, -2227,  1607,
    1617, -2227, -2227, -2227, -2227,  1615,  1362, -2227, -2227,  1616,
    1364, -2227, -2227,  1618,  1365, -2227, -2227, -2227,  1199,   868,
     868,   868,   868,   868,   868, -2227, -2227,   868,   868,   868,
     868,   868,   868, -2227,   868, -2227, -2227, -2227,  1431,  1433,
     868,   176,   176,   176, -2227,  1228,     3, -2227,  1621,   176,
     176, -2227,  1196, -2227,  1194,  1195, -2227, -2227, -2227, -2227,
   -2227, -2227,  1620, -2227, -2227, -2227,  1197, -2227, -2227, -2227,
   -2227,  1622, -2227,  1623, -2227, -2227,  1625, -2227,  1626, -2227,
    1627, -2227,  1631, -2227,  1633,   868, -2227,  1188,  1437, -2227,
    1098, -2227, -2227, -2227, -2227,  1480, -2227, -2227, -2227, -2227,
   -2227,  1366, -2227,  1098, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227,  1098, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227,  1639,  1641,  1642, -2227,
    1643, -2227,  1644, -2227, -2227,   868,   868,   868,   868,  1269,
    1273,   439,   529,  1271,  1275,   868,  1274,  1261,  1260,    18,
    1256,   678,   715,   764,  1249, -2227, -2227,  1248, -2227, -2227,
     868,  1243,  1244,  1245, -2227, -2227,  1253, -2227,  1662, -2227,
   -2227, -2227, -2227, -2227, -2227,  1242, -2227,  1241, -2227, -2227,
   -2227, -2227, -2227, -2227,  1439,  1212,   868,   288,   288,   288,
     288,   288,   288,   868, -2227, -2227, -2227, -2227, -2227,  1098,
   -2227, -2227, -2227, -2227, -2227,  1410,  1221, -2227,  1514, -2227,
    1386, -2227, -2227,  1388,  1390,  1522,   -94,   -80, -2227,  1394,
     -78,   -76, -2227,  1525,  1396,  1667, -2227, -2227, -2227, -2227,
    1368,  1370,  1303,  1372, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227,   868, -2227, -2227, -2227,   837, -2227,  1671,  1673,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227,  1277, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227,  1225, -2227, -2227,  1675,  1680, -2227, -2227, -2227,
     868, -2227,   288, -2227,   288, -2227,  1229, -2227,  1234, -2227,
     288, -2227,  1226, -2227,   176,  1443,   129, -2227,  1430, -2227,
    1445, -2227, -2227,  1446, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227,  1447, -2227, -2227, -2227,  1449, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1446,
   -2227, -2227, -2227, -2227, -2227, -2227,  1306, -2227, -2227,  1689,
     876, -2227,  1690,   273, -2227,   876,   876,  1231,  1233,  1246,
   -2227, -2227,  1232, -2227,  1254,  1267, -2227, -2227, -2227, -2227,
    1691,  1693, -2227, -2227, -2227, -2227, -2227, -2227,    92, -2227,
   -2227, -2227, -2227,  1694, -2227,  1451,   -17,   868, -2227, -2227,
   -2227, -2227,    -4, -2227, -2227, -2227, -2227,    27,    25,  1695,
   -2227, -2227,  1374,  1699,  1700, -2227, -2227, -2227,  1701,  1702,
   -2227, -2227, -2227, -2227, -2227,  1452,  1705,  1707,  1549, -2227,
     876, -2227, -2227, -2227, -2227, -2227, -2227,  1706,  1708, -2227,
   -2227, -2227,  1556,  1567,  1709, -2227,  1716, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227,  1576, -2227, -2227, -2227, -2227, -2227,
   -2227,  1717, -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1712,
    1714, -2227,  1580,   -57,  1718,   876, -2227, -2227,  1583,  1715,
   -2227,  1585, -2227, -2227, -2227, -2227, -2227, -2227,  1481,  1719,
    1721, -2227, -2227, -2227,  1723,  1722, -2227, -2227, -2227,   876,
    1720, -2227,  1724,  1442, -2227, -2227
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1685, -2227,
    1710, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1674,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227,  1376,  -346,  -394, -2227, -2227,  -487, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227,  1600, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
    1280, -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1531, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227,  1168, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,  1435, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227,  1129, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227,  1115, -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1112,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227,  1110, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227,  1108, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227,  1104, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227,  1092, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
     887, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227,   838, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
     374, -1058, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227,   576, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227,   383, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227,   858, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
     796, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
     490, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227,   812, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227,   728, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227,   413, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227,   740, -2227, -2227,
   -2227, -2227,   758, -2227, -2227, -2227, -2227, -2227,   553, -2227,
   -2227, -2227, -2227,    -2,  -250,  -207, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -1269, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -1255, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
     -96, -2227,    23,   208, -2227, -2227, -1089, -1212, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227,  -358,  -390, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -1917, -1075,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227,  -685, -2227, -2227,
   -2227, -2227, -2227,  -855, -2227, -2227, -2227, -2227, -2227,  -929,
   -2227, -2227, -2227, -2227, -2227, -1095, -2227, -2227, -2227, -2227,
   -2227, -1168, -2227, -2227, -2227, -2227, -2227, -1150, -2227, -2227,
   -2227, -2227, -2227, -1132, -2227, -2227, -2227, -2227, -2227,  -976,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,  -625, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -1135, -2227, -2227, -2227, -2227, -2227,
   -1146, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227,  -814, -2227, -1360,  -998, -2227, -2227,
    -779, -2227, -2227, -1030,  -763, -2227, -2227,  -475, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227,  -965,  -654, -2227, -2226, -2227,
   -2227, -2227, -2227,  -653,  -652, -2227, -2227, -2227, -2227,  -950,
   -2227, -2227, -2227, -2227, -2227,  -145, -2227, -2227,  -978, -2227,
   -2227,  -476, -2227, -2227, -2227, -2227, -2227,  -948, -2227, -2227,
   -2227, -2227, -2227,  -918, -2227, -2227,  -562, -2227, -2227, -1044,
   -2227, -2227,  -144, -2227, -2227,  -482, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -1764, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -1769, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,   -35, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -1848,  -643, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227,
   -2227, -2227, -2227, -2227, -2227, -2227, -2227, -2227
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1168
static const yytype_int16 yytable[] =
{
     466,   594,   479,   236,  1154,   468,  1451,   591,  1060,  1201,
    1082,   811,  2017,  2018,  2206,  2207,   256,  1186,   244,   241,
     247,   881,   614,   688,   843,   473,   399,   393,  1093,  2286,
    2287,   472,   569,  1879,   657,  1881,  2474,  2475,  2464,  1941,
     864,   916,  1910,  1072,   132,   215,   133,  1951,   134,  1953,
     135,  1955,  1270,  1957,   240,  1462,  1959,  1520,  2120,  1036,
    1963,  1284,   900,  1961,  1420,  1364,  2350,  1161,  1162,  1163,
    1164,  1480,  1247,  1254,  1255,  1256,  1257,   963,  1270,   579,
    2354,  1128,  2359,   354,  2363,   361,   362,   366,   367,   910,
    1174,    49,   665,    50,  1440,    51,  2448,    52,  1144,    53,
       6,    54,   215,   951,  2505,  1193,  1051,   216,  1441,   570,
    1387,  1388,  2038,  1270,   136,  1371,   452,  2414,  1238,  1330,
     132,  1157,   133,   619,   134,   496,   135,     7,   348,   473,
    1153,    12,   265,   611,  1303,   291,   650,   292,  1244,   293,
    1353,  1364,    49,  2430,    50,   294,    51,   295,    52,   296,
      53,   297,    54,   298,  1356,   299,    14,   300,  1267,   301,
    1496,   302,  2065,   303,   216,   304,  1239,   420,  1364,  1161,
    1162,  1163,  1164,    55,  1497,   717,   662,   460,   461,  1119,
    1296,   453,  2072,   266,  1007,  1008,  2074,  1432,  2075,  1250,
     136,  1515,   587,   588,   497,   305,  2351,  2105,  1246,  1380,
    1300,  2470,  2478,  1271,   962,  1516,  2252,   389,   619,  2457,
    2355,   676,  2360,  1842,  2364, -1167,  1324,   658,  2465,  2466,
    1456,   709,   630,  1317,    55,  1347,   570,   751,  1298,   585,
     586,   585,   586,  2458,  2506,    17,  1481,    41,  1421,   587,
     588,   644,   608,   451,  1272,  1037,  2019,  2164,   400,  1073,
    1407,   917,   865,   400,   400,  1035,   400,  1073,   901,  1073,
    1302,  2449,   390,  2288,   714,  2315,  2316,  2289,  1374,  1143,
    1348,   964,  1485,  1484,  1485,  2175,  2176,  2177,  2178,  2179,
    2180,  1502,   727,  2183,  2184,  2185,  2186,  2187,  2188,   775,
    2190,   952,  2201,  2202,  2203,   997,  2200,   997,   615,   615,
    2215,  2217,  1237,   217,   268,  1375,   585,   586,   137,   262,
    1007,  1008,   259,  1211,   658,   380,   587,   588,   630,   630,
    1696,  1697,    30,  1509,    86,   639,   630,  1476,  1698,   630,
     643,   585,   586,   759,   124,   647,  1542,  1543,   590,   640,
     704,  2233,   619,   770,   619,   706,   636,  1401,  1212,  1213,
     438,  1214,   440,   627,   442,   696,   630,   269,   263,   260,
     381,   242,   245,   151,   257,   788,   248,  2400,  2401,  1558,
    1507,   693,   997,   702,   693,   799,   693,   619,   693,  2322,
    2324,  2326,  2328,  2330,  2332,   630,   625,   630,    57,   168,
      58,   619,    59,   306,    60,   821,  1529,   997,  1442,   693,
     631,   693,   698,   987,   831,  1186,   648,   196,   233,   234,
     619,  2270,  2271,  2272,  2273,  1297,    56,  2277,  2279,   233,
     234,  2282,   587,   588,  1470,   708,   619,  2296,  2298,  2300,
     639,   351,   352,   619,   643,   695,  2303,   872,   647,    57,
     623,    58,   199,    59,  1001,    60,  1555,   619,   202,  1568,
    1000,  2076,  1773,  2077,   694,  2078,  1774,  2079,   203,  2080,
    1775,  2081,  2320,  2082,  1498,  2083,   619,  2084,   204,  2334,
     205,   620,   206,  1970,  2388,  1773,  2389,  2020,   207,  1774,
     927,  2208,  2392,  1775,   933,   619,  1212,  1213,  1582,  1214,
     692,  1062,   225,  1523,   250,  1517,   271,  1061,   394,   395,
     396,   397,     1,     2,   585,   586,  1007,  1008,   284,   624,
     410,  1095,   286,   411,   626,   285,   412,  1094,  2376,   628,
      20,    21,  2378,   743,   744,   745,   287,   431,   288,   432,
     340,   433,  1542,  1543,   349,  2437,    25,    26,   358,  1544,
    1545,   444,   363,   446,   368,   649,   369,   233,   234,  1395,
     651,   585,   586,    33,    34,   376,  2387,    44,    45,   127,
     128,   587,   588,   377,  1130,  2394,  1155,  1546,   378,  1756,
    1129,   383,  1149,  1758,   153,   154,  1776,  1760,  1777,  1175,
    1778,  1762,  1779,   379,  1780,  1764,  1781,   384,  1782,  1766,
    1783,   385,  1784,  1768,  1785,  2163,  1786,  1770,  1787,  1776,
    1788,  1777,  1789,  1778,  1790,  1779,  1791,  1780,  2109,  1781,
    1853,  1782,  1855,  1783,  1857,  1784,  1859,  1785,  1861,  1786,
    1863,  1787,  1865,  1788,  1867,  1789,   386,  1790,   388,  1791,
     387,  1706,   392,  1710,  1248,  1714,  1110,  1718,   417,  1722,
    1245,  1726,  1883,  1730,  1884,  1734,  1885,  1268,  1886,   426,
    1887,   429,  1888,  2462,  1889,   434,  1890,  1883,  1891,  1884,
    1892,  1885,  1893,  1886,  1894,  1887,  1895,  1888,  1896,  1889,
    1897,  1890,  1898,  1891,  1899,  1892,  1900,  1893,  1901,  1894,
    1902,  1895,  1903,  1896,  1904,  1897,  1905,  1898,  1906,  1899,
    1907,  1900,  1908,  1901,  1909,  1902,  1304,  1903,   447,  1904,
     464,  1905,  1301,  1906,   470,  1907,  1319,  1908,   469,  1909,
     158,   159,  1318,  1707,   477,  1711,   478,  1715,   480,  1719,
     400,  1723,   484,  1727,   488,  1731,   489,  1735,  2076,   490,
    2077,   499,  2078,   505,  2079,   526,  2080,   557,  2081,   568,
    2082,  2436,  2083,  2076,  2084,  2077,   291,  2078,   292,  2079,
     293,  2080,   574,  2081,   575,  2082,   294,  2083,   295,  2084,
     296,   578,   297,   580,   298,   576,   299,   597,   300,   577,
     301,   598,   302,   601,   303,  1136,   304,  1003,  1004,   233,
     234,  1005,  1006,   585,   586,  1007,  1008,  1137,  1138,   163,
     164,   171,   172,   587,   588,   605,   176,   177,   181,   182,
     606,  1293,  1294,   186,   187,   607,   305,   612,  1883,   613,
    1884,   618,  1885,   629,  1886,   652,  1887,   663,  1888,   667,
    1889,  2276,  1890,  1596,  1891,   666,  1892,   668,  1893,   775,
    1894,   669,  1895,  1597,  1896,  1598,  1897,  1599,  1898,  1600,
    1899,  1601,  1900,  1602,  1901,  1603,  1902,  1604,  1903,  1605,
    1904,   672,  1905,   682,  1906,   683,  1907,   684,  1908,  1606,
    1909,   191,   192,   210,   211,   686,  1358,  1359,   685,  1633,
    1634,   233,   234,   251,   252,   272,   273,   279,   280,   351,
     352,  1444,   460,   461,  1453,   342,   343,  1443,  1635,  1636,
    1637,  1638,  1639,  1640,  1641,  1642,  1372,  1373,  1883,   687,
    1884,   690,  1885,  1145,  1886,   691,  1887,   697,  1888,   710,
    1889,   711,  1890,  2278,  1891,   718,  1892,   715,  1893,   719,
    1894,   723,  1895,   720,  1896,   733,  1897,   734,  1898,   738,
    1899,   739,  1900,   750,  1901,   755,  1902,   752,  1903,   765,
    1904,   766,  1905,   771,  1906,   772,  1907,  1500,  1908,   775,
    1909,   371,   372,  1499,   778,  1136,   779,  1003,  1004,   233,
     234,  1005,  1006,   585,   586,  1007,  1008,  1137,  1138,   405,
     406,  1243,   781,   587,   588,   421,   422,   780,  1519,  1139,
    1140,   455,   456,   782,  1518,  1002,  1003,  1004,   233,   234,
    1005,  1006,   585,   586,  1007,  1008,   783,  1464,   491,   492,
    1433,  1434,   587,   588,   785,    87,   804,    88,    89,    90,
     794,    91,    92,    93,  1551,    94,    95,    96,   784,    97,
      98,    99,  2209,   100,   101,   500,   501,   506,   507,   511,
     512,   516,   517,  1299,   795,  2244,   521,   522,   527,   528,
     532,   533,   800,  1503,  1504,   537,   538,  1883,   801,  1884,
     804,  1885,   807,  1886,   812,  1887,   818,  1888,   819,  1889,
     820,  1890,   827,  1891,   828,  1892,   832,  1893,  2258,  1894,
     833,  1895,   836,  1896,   839,  1897,   844,  1898,   850,  1899,
     863,  1900,  2295,  1901,  1883,  1902,  1884,  1903,  1885,  1904,
    1886,  1905,  1887,  1906,  1888,  1907,  1889,  1908,  1890,  1909,
    1891,   870,  1892,   874,  1893,   877,  1894,  1522,  1895,   911,
    1896,   882,  1897,   899,  1898,   906,  1899,   922,  1900,   865,
    1901,  2297,  1902,   950,  1903,   970,  1904,   923,  1905,   957,
    1906,  1561,  1907,  1883,  1908,  1884,  1909,  1885,   969,  1886,
     901,  1887,   982,  1888,   975,  1889,   987,  1890,   983,  1891,
     990,  1892,   917,  1893,  1027,  1894,  1581,  1895,  1026,  1896,
    1043,  1897,  1042,  1898,  2337,  1899,  1049,  1900,   952,  1901,
    1030,  1902,  2299,  1903,  1052,  1904,   964,  1905,  1066,  1906,
    1083,  1907,  1063,  1908,  1097,  1909,   542,   543,   547,   548,
     552,   553,   558,   559,   563,   564,   582,   583,   653,   654,
     677,   678,   712,   654,  1657,  1078,  1883,  1096,  1884,  1098,
    1885,  1099,  1886,  1100,  1887,  1112,  1888,  1101,  1889,  1108,
    1890,  1452,  1891,  1117,  1892,  1120,  1893,  1037,  1894,  1185,
    1895,  1176,  1896,  1179,  1897,  2377,  1898,  1883,  1899,  1884,
    1900,  1885,  1901,  1886,  1902,  1887,  1903,  1888,  1904,  1889,
    1905,  1890,  1906,  1891,  1907,  1892,  1908,  1893,  1909,  1894,
    1073,  1895,  1189,  1896,  1199,  1897,  1200,  1898,  1205,  1899,
    1206,  1900,  1207,  1901,   929,  1902,  1208,  1903,  1209,  1904,
    1210,  1905,  1221,  1906,  1223,  1907,  1280,  1908,  1269,  1909,
     728,   729,  2406,   740,   741,  1136,  1741,  1003,  1004,   233,
     234,  1005,  1006,   585,   586,  1007,  1008,  1137,  1138,   760,
     761,   789,   790,   587,   588,   813,   814,  1234,  1235,   822,
     823,   845,   846,   853,   854,   858,   859,   883,   884,   889,
     890,   894,   895,   928,   929,  1281,  1749,   934,   935,   940,
     941,   945,   946,   836,   977,   978,   994,   995,  1056,  1057,
    1067,  1068,  1084,  1085,  1089,  1090,  1102,  1103,  1124,  1125,
    1131,  1132,  1158,  1159,  1180,  1181,  1194,  1195,  1224,  1225,
    1229,  1230,  1251,  1252,  1288,  1289,  1309,  1181,  1313,  1314,
    1325,  1326,  1382,  1383,  1402,  1403,  1411,  1412,  1435,  1436,
    1445,  1446,  1471,  1472,  1484,  1485,  1491,  1492,  1510,  1511,
    1524,  1525,  1537,  1538,  1563,  1564,  1630,  1631,  1676,  1677,
    1846,  1847,  1948,  1949,  1975,  1976,  2026,  2027,  2030,  2031,
    2034,  2035,  2110,  2111,  2115,  2116,  2123,  2124,  2128,  2129,
    2133,  2134,  2138,  2139,  2143,  2144,  2148,  2149,  2153,  2154,
    2158,  2159,  2194,  2195,  2197,  2198,  2234,  2235,  2239,  2240,
    2312,  2313,  2315,  2316,  2395,  2396,  2408,  2409,  2417,  2418,
    2422,  2423,  2452,  2453,  1282,  1285,  1286,  1287,  1308,  1333,
    1320,  1335,  1338,  1332,  1339,  1340,  1341,  1343,  1345,  1354,
    1360,  1357,  1271,  1270,  1367,  1368,  1381,  1369,  1397,  1409,
    1410,  1396,  1419,  1418,  1426,  1347,  1430,  1454,  1457,  1374,
    1461,  1465,  1466,  1478,  1479,  1482,  1505,  1521,  1532,  1533,
    1531,  1534,  1535,  1556,  1536,  1559,  1560,  1562,  1572,  1571,
    1570,  1573,  1578,  1574,  1579,  1580,  1584,  1686,  1585,  1586,
    1587,  1591,  1592,  1593,  1594,  1595,  1682,  1655,  1656,  1685,
    1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,  1831,  1842,
    1750,  1695,  1704,  1708,  1712,  1716,  1720,  1724,  1728,  1732,
    1736,  1737,  1738,  1739,  1742,  1743,  1744,  1745,  1746,  1747,
    1748,  1754,  1966,  1755,  1772,  1830,  1873,  1870,  1834,  1835,
    1836,  1837,  1838,  1839,  2210,  1840,  1841,  1851,  1852,  1875,
    1943,  1877,  1965,  1971,  1972,  1983,  1984,  1995,  1991,  2025,
    2029,  1987,  1988,  2033,  1992,  2064,  2068,  2069,  1996,  2070,
    2067,  2000,  2106,  2165,  2003,  2166,  1999,  2037,  2007,  2071,
    2167,  2168,  2170,  2011,  2172,  2174,  2073,  2004,  2204,  2214,
    2219,  2222,  2220,  2226,  2227,  2221,  2228,  2229,  2230,  2008,
    2015,  2223,  2231,  2012,  2232,  2265,  2122,  2274,  2246,  2266,
    2267,  2268,  2269,  2275,  2251,  2284,  2285,  2280,  2294,  2301,
    2302,  2304,  2169,  2281,  2305,  2308,  2283,  2306,  2171,  2307,
    2309,  2310,  2339,  2173,  2341,  2371,  2344,  2374,  2345,  2379,
    2346,  2380,  2347,  2385,  2358,  2367,  2370,  2384,  2386,  2390,
    2391,  2381,  2393,  1485,  2407,  2433,  2431,  2441,  2435,  2446,
    2444,  2447,  2443,  2440,  2442,  2450,  2481,  2484,  2485,  2486,
    2487,  2489,  2488,  2490,  2494,  2498,  2495,  2496,  2491,  2499,
    2502,  2501,  2503,  2512,  2509,   123,  2523,  2517,  2497,  2518,
    2514,  2519,  2524,  2520,  2525,    40,   152,  2500,  2372,   226,
     664,  2504,  2373,   418,  2511,   689,  2513,   699,  2375,   703,
     341,   705,   716,   707,   924,   581,  1463,   991,  1310,   713,
    1458,   971,  1053,  1427,  1361,  1109,  1044,  1121,  1107,  1344,
    2445,  2340,  2483,  2469,  2405,  2479,  2480,  1947,   481,  2463,
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
       0,     0,  2434,     0,     0,     0,     0,  2438,  2439,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2492,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2510,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2522
};

static const yytype_int16 yycheck[] =
{
     358,   483,   392,   148,  1048,   363,  1366,   483,   973,  1084,
     986,   774,    11,    12,    11,    12,     4,  1075,     4,     4,
       4,   835,    75,    75,   803,   371,   131,     8,   993,    11,
      12,   131,   131,  1802,   131,  1804,    11,    12,    11,  1808,
     105,   107,  1806,   111,    60,    68,    62,  1816,    64,  1818,
      66,  1820,   162,  1822,   150,   115,  1825,   115,  1975,   123,
    1829,  1156,   117,  1827,   125,  1277,   160,    17,    18,    19,
      20,     4,  1116,    21,    22,    23,    24,   119,   162,   473,
     160,  1046,   160,   228,   160,   230,   230,   232,   232,   852,
    1055,    48,   579,    50,  1363,    52,     4,    54,  1048,    56,
       0,    58,    68,   121,   161,  1081,   961,   130,  1363,   455,
      46,    47,  1881,   162,   130,  1283,     4,  2343,  1116,  1194,
      60,  1050,    62,    76,    64,     4,    66,   132,   224,   475,
    1048,    15,     4,   491,  1178,    70,    89,    72,  1116,    74,
    1229,  1353,    48,  2369,    50,    80,    52,    82,    54,    84,
      56,    86,    58,    88,  1249,    90,    16,    92,  1123,    94,
    1429,    96,  1926,    98,   130,   100,  1116,   311,  1380,    17,
      18,    19,    20,   130,  1429,   662,   570,     6,     7,  1034,
    1178,    69,  1951,    55,   181,   182,  1955,  1355,  1957,  1118,
     130,  1460,   189,   190,    73,   130,   290,  1961,  1116,  1288,
    1178,  2427,  2428,   313,   889,  1460,  2123,     4,    76,   226,
     290,   601,   290,   287,   290,   289,  1192,   563,   191,   192,
    1370,    89,    78,  1188,   130,   309,   572,   714,  1178,   179,
     180,   179,   180,   250,   291,   321,   169,   325,   299,   189,
     190,    97,    71,   339,   354,   309,   245,  2016,   353,   317,
    1325,   317,   317,   353,   353,   940,   353,   317,   313,   317,
    1178,   169,    59,   245,   658,   240,   241,   249,   317,  1048,
     354,   313,   247,   246,   247,  2039,  2040,  2041,  2042,  2043,
    2044,  1431,   672,  2047,  2048,  2049,  2050,  2051,  2052,   225,
    2054,   309,  2061,  2062,  2063,   245,  2060,   245,   351,   351,
    2069,  2070,  1116,   326,     4,   354,   179,   180,   324,     4,
     181,   182,     4,   129,   660,     4,   189,   190,    78,    78,
     209,   210,   323,  1455,   133,   532,    78,  1402,   217,    78,
     537,   179,   180,   723,   327,   542,   207,   208,   483,    99,
      99,  2105,    76,   733,    76,    97,    95,  1323,   164,   165,
     327,   167,   329,    87,   331,    87,    78,    57,    53,    51,
      49,   346,   348,   322,   352,   755,   350,   238,   239,  1501,
    1445,   621,   245,    95,   624,   765,   626,    76,   628,  2227,
    2228,  2229,  2230,  2231,  2232,    78,    85,    78,   345,    28,
     347,    76,   349,   328,   351,   785,  1471,   245,  1363,   649,
      93,   651,    93,   170,   794,  1463,    91,    27,   175,   176,
      76,  2175,  2176,  2177,  2178,  1178,   322,  2181,  2182,   175,
     176,  2185,   189,   190,  1400,    91,    76,  2191,  2192,  2193,
     637,   187,   188,    76,   641,    85,  2200,   827,   645,   345,
      83,   347,    44,   349,   926,   351,  1490,    76,     5,  1524,
     926,   455,   299,   457,    83,   459,   303,   461,     5,   463,
     307,   465,  2226,   467,  1429,   469,    76,   471,     5,  2233,
       5,    81,     5,  1833,  2322,   299,  2324,   476,   329,   303,
     870,   478,  2330,   307,   874,    76,   164,   165,  1563,   167,
      81,   973,   324,  1469,     3,  1460,     3,   973,   479,   480,
     481,   482,    13,    14,   179,   180,   181,   182,   135,   511,
     218,   993,   143,   221,   516,   139,   224,   993,  2282,   521,
      11,    12,  2286,    29,    30,    31,   147,   319,   151,   321,
     326,   323,   207,   208,    11,  2383,    11,    12,    11,   214,
     215,   333,    11,   335,     3,   547,    11,   175,   176,  1312,
     552,   179,   180,    11,    12,   346,  2320,    11,    12,    11,
      12,   189,   190,   348,  1046,  2334,  1048,   242,   350,  1704,
    1046,   352,  1048,  1708,    11,    12,   423,  1712,   425,  1055,
     427,  1716,   429,     8,   431,  1720,   433,    51,   435,  1724,
     437,    53,   439,  1728,   441,   442,   443,  1732,   445,   423,
     447,   425,   449,   427,   451,   429,   453,   431,  1968,   433,
    1756,   435,  1758,   437,  1760,   439,  1762,   441,  1764,   443,
    1766,   445,  1768,   447,  1770,   449,    55,   451,     8,   453,
      57,  1661,     6,  1663,  1116,  1665,  1026,  1667,   328,  1669,
    1116,  1671,   369,  1673,   371,  1675,   373,  1123,   375,    32,
     377,    33,   379,  2417,   381,    34,   383,   369,   385,   371,
     387,   373,   389,   375,   391,   377,   393,   379,   395,   381,
     397,   383,   399,   385,   401,   387,   403,   389,   405,   391,
     407,   393,   409,   395,   411,   397,   413,   399,   415,   401,
     417,   403,   419,   405,   421,   407,  1178,   409,    35,   411,
       3,   413,  1178,   415,     6,   417,  1188,   419,     8,   421,
      11,    12,  1188,  1661,    49,  1663,    59,  1665,   131,  1667,
     353,  1669,   319,  1671,     8,  1673,     8,  1675,   455,     8,
     457,     8,   459,     8,   461,     8,   463,     8,   465,    69,
     467,   468,   469,   455,   471,   457,    70,   459,    72,   461,
      74,   463,    61,   465,     8,   467,    80,   469,    82,   471,
      84,    67,    86,   131,    88,    63,    90,   330,    92,    65,
      94,   315,    96,    36,    98,   171,   100,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,    11,
      12,    11,    12,   189,   190,     6,    11,    12,    11,    12,
       6,   197,   198,    11,    12,     6,   130,    73,   369,     6,
     371,     6,   373,     6,   375,     6,   377,   131,   379,     3,
     381,   382,   383,   257,   385,   354,   387,     3,   389,   225,
     391,   311,   393,   267,   395,   269,   397,   271,   399,   273,
     401,   275,   403,   277,   405,   279,   407,   281,   409,   283,
     411,    37,   413,     8,   415,     8,   417,     8,   419,   293,
     421,    11,    12,    11,    12,     8,  1256,  1257,    71,   211,
     212,   175,   176,    11,    12,    11,    12,    11,    12,   187,
     188,  1363,     6,     7,  1366,    11,    12,  1363,   230,   231,
     232,   233,   234,   235,   236,   237,  1286,  1287,   369,    11,
     371,     8,   373,  1048,   375,    11,   377,     8,   379,     8,
     381,    11,   383,   384,   385,     8,   387,   131,   389,     8,
     391,    38,   393,   295,   395,     6,   397,   104,   399,     4,
     401,     4,   403,     4,   405,    39,   407,   126,   409,     6,
     411,   116,   413,   320,   415,   106,   417,  1429,   419,   225,
     421,    11,    12,  1429,   352,   171,    77,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,    11,
      12,  1116,     3,   189,   190,    11,    12,    79,  1460,   195,
     196,    11,    12,     3,  1460,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,     3,  1387,    11,    12,
    1358,  1359,   189,   190,    43,   134,   222,   136,   137,   138,
       6,   140,   141,   142,  1490,   144,   145,   146,   103,   148,
     149,   150,  2066,   152,   153,    11,    12,    11,    12,    11,
      12,    11,    12,  1178,   120,  2110,    11,    12,    11,    12,
      11,    12,   316,  1433,  1434,    11,    12,   369,   118,   371,
     222,   373,   108,   375,     8,   377,     8,   379,     8,   381,
       8,   383,     6,   385,   297,   387,   312,   389,  2143,   391,
     122,   393,   219,   395,   108,   397,     8,   399,   110,   401,
       6,   403,   404,   405,   369,   407,   371,   409,   373,   411,
     375,   413,   377,   415,   379,   417,   381,   419,   383,   421,
     385,     6,   387,    40,   389,   108,   391,  1465,   393,   337,
     395,     8,   397,     6,   399,   112,   401,     8,   403,   317,
     405,   406,   407,     6,   409,   117,   411,   105,   413,   353,
     415,  1521,   417,   369,   419,   371,   421,   373,     8,   375,
     313,   377,   109,   379,    45,   381,   170,   383,   333,   385,
     107,   387,   317,   389,   124,   391,  1546,   393,     6,   395,
     121,   397,     8,   399,  2239,   401,   109,   403,   309,   405,
     353,   407,   408,   409,   119,   411,   313,   413,     8,   415,
       8,   417,   353,   419,     8,   421,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,   101,   102,
      11,    12,   101,   102,  1594,   335,   369,   318,   371,     8,
     373,     3,   375,     3,   377,   229,   379,     3,   381,   296,
     383,  1366,   385,   109,   387,   123,   389,   309,   391,   111,
     393,   314,   395,     6,   397,   398,   399,   369,   401,   371,
     403,   373,   405,   375,   407,   377,   409,   379,   411,   381,
     413,   383,   415,   385,   417,   387,   419,   389,   421,   391,
     317,   393,   331,   395,     6,   397,   168,   399,   318,   401,
       6,   403,     6,   405,   128,   407,     8,   409,     8,   411,
       8,   413,   298,   415,     8,   417,     8,   419,   310,   421,
      11,    12,  2336,    11,    12,   171,  1686,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,    11,
      12,    11,    12,   189,   190,    11,    12,   193,   194,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,   127,   128,     3,  1694,    11,    12,    11,
      12,    11,    12,   219,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,   113,   114,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,   113,   114,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,   246,   247,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,   185,   186,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,    11,    12,   258,   259,    11,    12,
      11,    12,   240,   241,    11,    12,    11,    12,    11,    12,
      11,    12,    11,    12,     3,   314,     3,     3,     8,   248,
     339,   160,   338,     8,     8,     8,     5,   129,     6,     3,
     354,   310,   313,   162,     6,     8,     3,     8,   341,   334,
       8,   318,     8,   166,   354,   309,     8,     8,   354,   317,
       8,     8,   343,   336,     6,    11,   314,     6,     8,   169,
     332,     6,     8,   310,     8,   163,   318,     8,     6,   161,
     340,     6,     3,   256,     8,     8,   342,     3,     8,     8,
     300,     8,     6,     6,     6,   344,   213,     8,     8,   255,
       8,     8,     8,     8,     8,     8,     8,     8,   261,   287,
     285,    11,    11,    11,    11,    11,    11,    11,    11,    11,
       3,    11,     8,    11,     6,     6,     6,     6,     6,     6,
       6,     3,   263,     8,     8,     6,   245,   294,     8,     8,
       8,     8,     8,     8,  2066,     8,     8,     8,     6,   245,
     474,   245,     8,   268,   289,     8,   289,   280,   274,     8,
       8,   272,   289,     8,   289,   452,     3,    11,   289,    11,
     454,   289,   448,   450,   278,     8,   282,   424,   276,   432,
       3,     6,     6,   270,     6,   426,   436,   289,   400,     8,
     434,    11,   438,    11,    11,   440,    11,    11,    11,   289,
     284,   444,    11,   289,    11,     6,   286,   378,   168,     8,
       8,     8,     8,   380,   288,   394,   396,   386,   402,   410,
     412,   418,   300,   388,   420,     3,   392,   422,   304,   416,
     428,   430,   262,   308,   160,     8,   290,   374,   290,     8,
     290,     8,   160,     8,   290,   160,   290,   462,     8,   460,
     456,   414,   466,   247,   264,     6,   390,   464,     8,     8,
     446,     8,   470,   472,   458,    11,    11,     8,     8,     8,
       8,     6,   260,     6,     8,     6,     8,   161,   169,     3,
       8,     4,     8,     8,     6,    40,     6,     8,   161,     8,
     249,     8,     8,    11,   292,    25,    62,   161,   370,   139,
     572,   161,   372,   308,   161,   616,   161,   632,   376,   637,
     219,   641,   660,   645,   867,   475,  1382,   919,  1182,   655,
    1377,   903,   966,  1350,  1274,  1025,   954,  1039,  1010,  1216,
    2395,  2246,   398,  2427,  2336,  2428,  2428,  1812,   402,  2422,
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
      -1,    -1,  2380,    -1,    -1,    -1,    -1,  2385,  2386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2495,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2519
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    13,    14,   484,   485,   486,     0,   132,   493,   494,
    1103,  1104,    15,   487,    16,   491,   492,   321,   495,   496,
      11,    12,  1105,  1106,  1107,    11,    12,   488,   489,   490,
     323,   581,   582,    11,    12,   497,   498,   499,  1108,  1109,
     493,   325,   624,   625,    11,    12,   583,   584,   585,    48,
      50,    52,    54,    56,    58,   130,   322,   345,   347,   349,
     351,   500,   501,   502,   503,   504,   509,   510,   515,   516,
     521,   522,   529,   530,   535,   536,   541,   542,   547,   548,
     553,   554,   559,   560,   567,   568,   133,   134,   136,   137,
     138,   140,   141,   142,   144,   145,   146,   148,   149,   150,
     152,   153,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,
    1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,
    1128,  1129,  1130,   491,   327,   647,   648,    11,    12,   626,
     627,   628,    60,    62,    64,    66,   130,   324,   586,   587,
     588,   589,   590,   596,   597,   603,   604,   610,   611,   615,
     616,   322,   502,    11,    12,   505,   506,   507,    11,    12,
     511,   512,   513,    11,    12,   517,   518,   519,    28,   523,
     524,    11,    12,   531,   532,   533,    11,    12,   537,   538,
     539,    11,    12,   543,   544,   545,    11,    12,   549,   550,
     551,    11,    12,   555,   556,   557,    27,   561,   562,    44,
     569,  1083,     5,     5,     5,     5,     5,   329,   758,   759,
      11,    12,   649,   650,   651,    68,   130,   326,   629,   630,
     631,   632,   633,   638,   639,   324,   588,   591,   592,   598,
     599,   605,   606,   175,   176,   612,  1458,  1459,  1460,   617,
    1083,     4,   346,   508,     4,   348,   514,     4,   350,   520,
       3,    11,    12,   525,   526,   527,     4,   352,   534,     4,
      51,   540,     4,    53,   546,     4,    55,   552,     4,    57,
     558,     3,    11,    12,   563,   564,   565,  1100,  1101,    11,
      12,   570,   571,   572,   135,   139,   143,   147,   151,   760,
     761,    70,    72,    74,    80,    82,    84,    86,    88,    90,
      92,    94,    96,    98,   100,   130,   328,   652,   653,   654,
     655,   656,   663,   664,   669,   670,   677,   678,   682,   683,
     687,   688,   692,   693,   697,   698,   705,   706,   713,   714,
     721,   722,   729,   730,   735,   736,   741,   742,   749,   750,
     326,   631,    11,    12,   634,   635,   636,   640,  1083,    11,
     594,   187,   188,   593,  1458,  1485,  1486,  1487,    11,   601,
     600,  1458,  1485,    11,   608,   607,  1458,  1485,     3,    11,
     613,    11,    12,   618,   619,   620,   346,   348,   350,     8,
       4,    49,   528,   352,    51,    53,    55,    57,     8,     4,
      59,   566,     6,     8,   479,   480,   481,   482,  1102,   131,
     353,   573,   574,   575,   576,    11,    12,   763,   764,   765,
     218,   221,   224,   762,  1418,  1424,  1429,   328,   654,   657,
    1485,    11,    12,   665,   666,   667,    32,   671,  1078,    33,
    1086,  1086,  1086,  1086,    34,   699,  1085,   707,  1085,   715,
    1085,   723,  1085,   731,  1086,   737,  1086,    35,   743,  1087,
     751,  1083,     4,    69,   637,    11,    12,   641,   642,   643,
       6,     7,   595,  1099,     3,   602,  1099,   609,  1099,     8,
       6,   614,   131,   576,   621,   622,   623,    49,    59,  1100,
     131,   575,   577,   578,   319,   766,   767,   768,     8,     8,
       8,    11,    12,   658,   659,   660,     4,    73,   668,     8,
      11,    12,   672,   673,   674,     8,    11,    12,   679,   680,
     681,    11,    12,   684,   685,   686,    11,    12,   689,   690,
     691,    11,    12,   694,   695,   696,     8,    11,    12,   700,
     701,   702,    11,    12,   708,   709,   710,    11,    12,   716,
     717,   718,    11,    12,   724,   725,   726,    11,    12,   732,
     733,   734,    11,    12,   738,   739,   740,     8,    11,    12,
     744,   745,   746,    11,    12,   752,   753,   754,    69,   131,
     576,   644,   645,   646,    61,     8,    63,    65,    67,   577,
     131,   623,    11,    12,   580,   179,   180,   189,   190,   579,
    1458,  1464,  1465,  1466,  1488,  1489,  1490,   330,   315,   863,
     864,    36,   769,   770,  1084,     6,     6,     6,    71,   661,
     662,  1099,    73,     6,    75,   351,   675,   676,     6,    76,
      81,  1046,  1047,    83,  1046,    85,  1046,    87,  1046,     6,
      78,    93,   703,   704,  1048,  1049,    95,   711,   712,  1048,
      99,   719,   720,  1048,    97,   727,   728,  1048,    91,  1046,
      89,  1046,     6,   101,   102,   747,   748,   131,   576,   755,
     756,   757,   577,   131,   646,   580,   354,     3,     3,   311,
     930,   931,    37,   865,   866,  1082,  1100,    11,    12,   771,
     772,   773,     8,     8,     8,    71,     8,    11,    75,   676,
       8,    11,    81,  1047,    83,    85,    87,     8,    93,   704,
    1050,  1051,    95,   712,    99,   720,    97,   728,    91,    89,
       8,    11,   101,   748,   577,   131,   757,   580,     8,     8,
     295,   997,   998,    38,   932,   933,  1079,  1100,    11,    12,
     867,   868,   869,     6,   104,   774,   775,   776,     4,     4,
      11,    12,  1056,    29,    30,    31,  1052,  1053,  1054,  1055,
       4,   580,   126,  1024,  1025,    39,   999,  1000,  1080,  1100,
      11,    12,   934,   935,   936,     6,   116,   870,   871,   872,
    1100,   320,   106,   789,   790,   225,   777,  1427,   352,    77,
      79,     3,     3,     3,   103,    43,  1026,  1088,  1100,    11,
      12,  1001,  1002,  1003,     6,   120,   937,   938,   939,  1100,
     316,   118,   885,   886,   222,   873,  1423,   108,   803,   804,
     791,  1427,     8,    11,    12,   778,   779,   780,     8,     8,
       8,  1100,    11,    12,  1027,  1028,  1029,     6,   297,  1004,
    1005,  1100,   312,   122,   952,   953,   219,   940,  1417,   108,
     899,   900,   887,  1423,     8,    11,    12,   874,   875,   876,
     110,   816,   817,    11,    12,   805,   806,   807,    11,    12,
     792,   793,   794,     6,   105,   317,   781,   782,   783,   784,
       6,  1030,  1100,  1021,    40,  1006,  1081,   108,   966,   967,
     954,  1417,     8,    11,    12,   941,   942,   943,   912,    11,
      12,   901,   902,   903,    11,    12,   888,   889,   890,     6,
     117,   313,   877,   878,   879,   880,   112,   830,   831,   818,
    1427,   337,   808,   809,  1160,  1161,   107,   317,   795,   796,
     797,   798,     8,   105,   783,   785,   786,  1100,   127,   128,
    1031,  1032,  1022,  1100,    11,    12,  1007,  1008,  1009,   979,
      11,    12,   968,   969,   970,    11,    12,   955,   956,   957,
       6,   121,   309,   944,   945,   946,   947,   353,   913,   914,
     904,   905,  1160,   119,   313,   891,   892,   893,   894,     8,
     117,   879,   881,   882,   845,    45,   832,    11,    12,   819,
     820,   821,   109,   333,   810,  1166,  1167,   170,  1202,  1419,
     107,   797,   799,   800,    11,    12,   788,   245,   787,  1438,
    1464,  1488,   172,   173,   174,   177,   178,   181,   182,  1033,
    1034,  1035,  1421,  1452,  1453,  1454,  1458,  1464,  1476,  1477,
    1478,  1482,  1483,  1484,  1488,  1023,     6,   124,  1011,  1012,
     353,   980,   981,   971,   972,  1160,   123,   309,   958,   959,
     960,   961,     8,   121,   946,   948,   949,   915,   916,   109,
     906,  1166,   119,   893,   895,   896,    11,    12,   884,   883,
    1438,  1464,  1488,   353,   846,   847,     8,    11,    12,   833,
     834,   835,   111,   317,   822,   823,   824,   825,   335,   811,
    1172,  1173,  1202,     8,    11,    12,  1162,  1163,  1164,    11,
      12,   802,   801,  1438,  1464,  1488,   318,     8,     8,     3,
       3,     3,    11,    12,  1036,  1037,  1038,  1035,   296,  1030,
    1100,  1020,   229,  1013,  1422,   982,   983,   109,   973,  1166,
     123,   960,   962,   963,    11,    12,   951,   950,  1438,  1464,
    1488,    11,    12,   918,   919,   920,   171,   183,   184,   195,
     196,   917,  1420,  1423,  1452,  1458,  1461,  1462,  1463,  1464,
    1467,  1468,  1469,  1476,  1482,  1488,   907,  1172,    11,    12,
     898,    17,    18,    19,    20,   897,  1059,  1060,  1061,  1062,
    1070,  1071,  1072,  1073,  1438,  1464,   314,   848,   849,     6,
     113,   114,   836,   837,   838,   111,   824,   826,   827,   331,
     812,  1178,  1179,  1202,    11,    12,  1168,  1169,  1170,     6,
     168,  1132,  1133,  1140,  1165,   318,     6,     6,     8,     8,
       8,   129,   164,   165,   167,  1039,  1040,  1041,  1042,  1043,
    1044,   298,  1010,     8,    11,    12,  1014,  1015,  1016,    11,
      12,   985,   986,   987,   193,   194,   984,  1417,  1420,  1452,
    1455,  1456,  1457,  1458,  1461,  1464,  1476,  1482,  1488,   974,
    1172,    11,    12,   965,    21,    22,    23,    24,   964,  1063,
    1064,  1065,  1066,  1074,  1075,  1076,  1077,  1438,  1464,   310,
     162,   313,   354,   921,   922,   923,   924,  1089,  1090,  1091,
       8,     3,     3,   908,  1178,   314,     3,     3,    11,    12,
     851,   852,   853,   197,   198,   850,  1420,  1427,  1452,  1458,
    1461,  1464,  1476,  1482,  1488,  1494,  1495,  1496,     8,   113,
     837,   839,   840,    11,    12,   829,   828,  1438,  1464,  1488,
     339,   813,  1184,  1185,  1202,    11,    12,  1174,  1175,  1176,
    1132,  1171,     8,   248,  1430,   160,  1134,  1135,   338,     8,
       8,     5,  1045,   129,  1041,     6,  1018,   309,   354,   988,
     989,   990,   991,  1089,     3,   975,  1178,   310,  1100,  1100,
     354,   923,   925,   926,  1090,  1092,  1093,     6,     8,     8,
     909,  1184,  1100,  1100,   317,   354,   854,   855,   856,   857,
    1089,     3,    11,    12,   842,   843,   844,    46,    47,   841,
    1057,  1058,  1067,  1068,  1069,  1427,   318,   341,   814,  1190,
    1191,  1202,    11,    12,  1180,  1181,  1182,  1132,  1177,   334,
       8,    11,    12,  1141,  1142,  1143,  1136,  1137,   166,     8,
     125,   299,  1017,  1019,  1203,  1204,   354,   990,   992,   993,
       8,   976,  1184,  1099,  1099,    11,    12,   928,   929,   927,
    1059,  1070,  1438,  1464,  1488,    11,    12,  1095,  1096,  1097,
    1094,  1419,  1458,  1488,     8,   910,  1190,   354,   856,   858,
     859,     8,   115,   823,  1100,     8,   343,   815,  1196,  1197,
    1202,    11,    12,  1186,  1187,  1188,  1132,  1183,   336,     6,
       4,   169,    11,  1139,   246,   247,  1138,  1439,  1441,  1205,
    1206,    11,    12,   995,   996,   994,  1059,  1070,  1438,  1464,
    1488,   977,  1190,  1100,  1100,   314,  1098,  1132,   911,  1196,
      11,    12,   861,   862,   860,  1059,  1070,  1438,  1464,  1488,
     115,     6,  1099,  1202,    11,    12,  1192,  1193,  1194,  1132,
    1189,   332,     8,   169,     6,     8,     8,    11,    12,  1208,
    1209,  1210,   207,   208,   214,   215,   242,  1207,  1416,  1425,
    1440,  1464,  1479,  1480,  1481,  1482,   310,   978,  1196,   163,
     318,  1100,     8,    11,    12,  1198,  1199,  1200,  1132,  1195,
     340,   161,     6,     6,   256,  1211,  1212,  1213,     3,     8,
       8,  1100,  1132,  1201,   342,     8,     8,   300,  1218,  1214,
    1215,     8,     6,     6,     6,   344,   257,   267,   269,   271,
     273,   275,   277,   279,   281,   283,   293,  1219,  1220,  1221,
    1245,  1246,  1258,  1259,  1285,  1286,  1303,  1304,  1321,  1322,
    1334,  1335,  1352,  1353,  1370,  1371,  1383,  1384,  1387,  1388,
      11,    12,  1217,   211,   212,   230,   231,   232,   233,   234,
     235,   236,   237,  1216,  1431,  1432,  1433,  1434,  1435,  1442,
    1443,  1448,  1449,  1450,  1451,     8,     8,  1100,  1222,  1223,
    1247,  1248,  1260,  1261,  1287,  1288,  1305,  1306,  1323,  1324,
    1336,  1337,  1354,  1355,  1372,  1373,   185,   186,  1385,  1473,
    1474,  1475,   213,  1389,  1415,   255,     3,     8,     8,     8,
       8,     8,     8,     8,     8,    11,   209,   210,   217,  1224,
    1426,  1470,  1471,  1472,    11,  1249,  1426,  1470,    11,  1262,
    1426,  1470,    11,  1289,  1426,  1470,    11,  1307,  1426,  1470,
      11,  1325,  1426,  1470,    11,  1338,  1426,  1470,    11,  1356,
    1426,  1470,    11,  1374,  1426,  1470,     3,    11,     8,    11,
    1390,  1100,     6,     6,     6,     6,     6,     6,     6,  1099,
     285,  1225,  1227,  1228,     3,     8,  1227,  1250,  1227,  1263,
    1227,  1290,  1227,  1308,  1227,  1326,  1227,  1339,  1227,  1357,
    1227,  1375,     8,   299,   303,   307,   423,   425,   427,   429,
     431,   433,   435,   437,   439,   441,   443,   445,   447,   449,
     451,   453,  1571,  1572,  1573,  1579,  1580,  1583,  1584,  1587,
    1588,  1591,  1592,  1594,  1595,  1597,  1598,  1600,  1601,  1603,
    1604,  1607,  1608,  1612,  1613,  1615,  1616,  1618,  1619,  1621,
    1622,  1624,  1625,  1627,  1630,  1631,  1633,  1634,  1636,  1637,
       6,   261,  1392,  1393,     8,     8,     8,     8,     8,     8,
       8,     8,   287,  1226,  1233,  1234,    11,    12,  1229,  1230,
    1231,     8,     6,  1233,  1251,  1233,  1264,  1233,  1291,  1233,
    1309,  1233,  1327,  1233,  1340,  1233,  1358,  1233,  1376,  1628,
     294,  1386,  1574,   245,  1582,   245,  1586,   245,  1590,  1571,
    1593,  1571,  1596,   369,   371,   373,   375,   377,   379,   381,
     383,   385,   387,   389,   391,   393,   395,   397,   399,   401,
     403,   405,   407,   409,   411,   413,   415,   417,   419,   421,
    1497,  1498,  1501,  1504,  1506,  1508,  1510,  1512,  1514,  1516,
    1518,  1520,  1522,  1524,  1526,  1528,  1529,  1531,  1533,  1535,
    1537,  1539,  1541,  1542,  1548,  1556,  1559,  1562,  1565,  1568,
    1599,  1571,  1602,   474,  1605,  1611,  1609,  1611,    11,    12,
    1614,  1571,  1617,  1571,  1620,  1571,  1623,  1571,  1626,  1571,
    1632,  1497,  1635,  1571,  1638,     8,   263,  1399,  1400,  1394,
    1419,   268,   289,  1239,  1240,    11,    12,  1235,  1236,  1237,
    1131,  1132,  1232,     8,   289,  1252,  1253,   272,   289,  1265,
    1266,   274,   289,  1292,  1293,   280,   289,  1310,  1311,   282,
     289,  1328,  1329,   278,   289,  1341,  1342,   276,   289,  1359,
    1360,   270,   289,  1377,  1378,   284,  1629,    11,    12,   245,
     476,  1575,  1576,  1577,  1578,     8,    11,    12,  1581,     8,
      11,    12,  1585,     8,    11,    12,  1589,   424,  1571,  1515,
    1507,  1509,  1513,  1517,  1519,  1557,  1569,  1527,  1511,  1534,
    1521,  1523,  1525,  1549,  1532,  1563,  1560,  1566,  1499,  1502,
    1505,  1536,  1538,  1540,   452,  1497,  1544,   454,     3,    11,
      11,   432,  1571,   436,  1571,  1571,   455,   457,   459,   461,
     463,   465,   467,   469,   471,  1497,  1639,  1640,  1641,  1642,
    1647,  1648,  1650,  1651,  1653,  1656,  1657,  1659,  1660,  1662,
    1663,  1665,  1666,  1668,  1669,  1497,   448,  1406,  1401,  1419,
      11,    12,  1395,  1396,  1397,    11,    12,  1241,  1242,  1243,
    1131,  1238,   286,    11,    12,  1254,  1255,  1256,    11,    12,
    1267,  1268,  1269,    11,    12,  1294,  1295,  1296,    11,    12,
    1312,  1313,  1314,    11,    12,  1330,  1331,  1332,    11,    12,
    1343,  1344,  1345,    11,    12,  1361,  1362,  1363,    11,    12,
    1379,  1380,  1381,   442,  1571,   450,     8,     3,     6,   300,
       6,   304,     6,   308,   426,  1497,  1497,  1497,  1497,  1497,
    1497,  1558,  1570,  1497,  1497,  1497,  1497,  1497,  1497,  1552,
    1497,  1564,  1561,  1567,    11,    12,  1500,    11,    12,  1503,
    1497,  1571,  1571,  1571,   400,  1530,    11,    12,   478,  1482,
    1488,  1543,  1545,  1546,     8,  1571,  1606,  1571,  1610,   434,
     438,   440,    11,   444,  1644,  1645,    11,    11,    11,    11,
      11,    11,    11,  1497,   258,   259,  1391,  1407,  1408,    11,
      12,  1402,  1403,  1404,  1132,  1398,   168,  1144,  1145,  1150,
    1244,   288,  1131,  1257,  1270,  1271,  1297,  1315,  1132,  1333,
    1346,  1364,  1154,  1155,  1382,     6,     8,     8,     8,     8,
    1497,  1497,  1497,  1497,   378,   380,   382,  1497,   384,  1497,
     386,   388,  1497,   392,   394,   396,    11,    12,   245,   249,
    1550,  1553,  1554,  1555,   402,   404,  1497,   406,  1497,   408,
    1497,   410,   412,  1497,   418,   420,   422,   416,     3,   428,
     430,  1654,    11,    12,  1643,   240,   241,  1446,  1447,  1646,
    1497,  1649,  1639,  1652,  1639,  1658,  1639,  1661,  1639,  1664,
    1639,  1667,  1639,  1670,  1497,  1409,  1410,  1132,  1405,   262,
    1430,   160,  1146,  1147,   290,   290,   290,   160,  1272,  1273,
     160,   290,  1298,  1299,   160,   290,  1316,  1317,   290,   160,
     290,  1347,  1348,   160,   290,  1365,  1366,   160,  1156,  1157,
     290,     8,   370,   372,   374,   376,  1497,   398,  1497,     8,
       8,   414,  1547,  1655,   462,     8,     8,  1497,  1639,  1639,
     460,   456,  1639,   466,  1571,    11,    12,  1412,  1413,  1414,
     238,   239,  1411,  1436,  1437,  1479,  1482,   264,    11,    12,
    1151,  1152,  1153,  1148,  1441,  1274,  1275,    11,    12,  1300,
    1301,  1302,    11,    12,  1318,  1319,  1320,  1349,  1367,  1158,
    1441,   390,  1551,     6,  1099,     8,   468,  1639,  1099,  1099,
     472,   464,   458,   470,   446,  1211,     8,     8,     4,   169,
      11,  1149,    11,    12,  1277,  1278,  1279,   226,   250,  1276,
    1428,  1445,  1497,  1640,    11,   191,   192,  1350,  1351,  1439,
    1441,  1491,  1492,  1493,    11,    12,  1368,  1369,  1441,  1446,
    1447,    11,  1159,   398,     8,     8,     8,     8,   260,     6,
       6,   169,  1099,  1280,     8,     8,   161,   161,     6,     3,
     161,     4,     8,     8,   161,   161,   291,  1281,  1282,     6,
    1099,   161,     8,   161,   249,  1283,  1444,     8,     8,     8,
      11,  1284,  1099,     6,     8,   292
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
    parserData->iOther = 0;
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

  case 820:

    {
//    osoption->optimization->matrixProgramming = new MatrixProgrammingOption();
}
    break;

  case 823:

    {    
    parserData->numberOfOtherMatrixProgrammingOptions = parserData->tempInt;
}
    break;

  case 829:

    {  
        if (parserData->kounter < parserData->numberOfMatrixVar)  
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
                "actual number of matrixVar elements less than number attribute");   
    }
    break;

  case 830:

    {
    osoption->optimization->matrixProgramming->matrixVariables = new MatrixVariableOption(); 
}
    break;

  case 832:

    {    
    parserData->numberOfOtherMatrixVariableOptions = parserData->tempInt;
}
    break;

  case 839:

    {  
        if (parserData->kounter < parserData->numberOfMatrixVar)  
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "actual number of matrixVar less than number attribute");   
    }
    break;

  case 840:

    {
    osoption->optimization->matrixProgramming->matrixVariables->initialMatrixVariableValues
        = new InitMatrixVariableValues(); 
}
    break;

  case 841:

    {    
    parserData->numberOfOtherMatrixVariableOptions = parserData->tempInt;
    osoption->optimization->matrixProgramming->matrixVariables->initialMatrixVariableValues->matrixVar
        = new OSMatrixWithMatrixVarIdx*[parserData->tempInt]; 
    for (int k=0; k < parserData->tempInt; k++)
        osoption->optimization->matrixProgramming->matrixVariables
            ->initialMatrixVariableValues->matrixVar[k] = new OSMatrixWithMatrixVarIdx();
}
    break;

  case 849:

    {
    parserData->kounter += osglData->mult;
}
    break;

  case 856:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 858:

    {
    if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfSolverOptions failed");
    parserData->iOption = 0;
}
    break;

  case 859:

    {
        if (parserData->numberOfSolverOptions > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <solverOption> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 860:

    {
        if (parserData->iOption != parserData->numberOfSolverOptions)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <solverOption> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 865:

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

  case 866:

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

  case 867:

    {
    if (!osglData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "name attribute must be present");
}
    break;

  case 876:

    {
            parserData->itemList = new std::string[osglData->numberOfItems];
    }
    break;

  case 877:

    {
        if (osglData->numberOfItems > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <item> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 878:

    {
        if (parserData->kounter < osglData->numberOfItems)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <item> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 885:

    {    
    parserData->itemList[parserData->kounter] = parserData->itemContent;
    parserData->kounter++;
}
    break;

  case 886:

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

  case 891:

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

  case 894:

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

  case 895:

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

  case 896:

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

  case 897:

    {
//    parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 903:

    {
    if (parserData->pathPairFromPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"from\" attribute allowed");
    parserData->pathPairFromPresent = true;
    parserData->pathPairFrom = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 904:

    {
    if (parserData->pathPairToPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"to\" attribute allowed");
    parserData->pathPairToPresent = true;
    parserData->pathPairTo = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 905:

    {
    if (parserData->pathPairMakeCopyPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"makeCopy\" attribute allowed");
    parserData->pathPairMakeCopyPresent = true;
    parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0 || strcmp((yyvsp[(2) - (3)].sval),"1") == 0);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 908:

    {
    if (parserData->groupWeightAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one groupWeight attribute allowed for this element");
    parserData->groupWeightAttributePresent = true;
}
    break;

  case 909:

    {
    parserData->groupWeight = parserData->tempVal;
}
    break;

  case 910:

    {   
    if (parserData->lbValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
    parserData->lbValueAttributePresent = true;
}
    break;

  case 913:

    { 
    parserData->lbValueAttribute = ""; 
}
    break;

  case 914:

    { 
    parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 915:

    {   if (parserData->lbValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
            parserData->lbValueAttributePresent = true;
        }
    break;

  case 918:

    { 
    parserData->lbDualValue = 0.0; 
}
    break;

  case 919:

    {
    parserData->lbDualValue = parserData->tempVal;
}
    break;

  case 920:

    {   if (parserData->sosIdxAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one sosIdx attribute allowed for this element");
        parserData->sosIdxAttributePresent = true;
    }
    break;

  case 922:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index must be nonnegative");
    parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 923:

    {
   if (parserData->ubValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
    parserData->ubValueAttributePresent = true;
}
    break;

  case 926:

    { 
    parserData->ubValueAttribute = ""; 
}
    break;

  case 927:

    { 
    parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 928:

    {   if (parserData->ubValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
            parserData->ubValueAttributePresent = true;
        }
    break;

  case 931:

    { parserData->ubDualValue = 0.0; }
    break;

  case 932:

    { 
    parserData->ubDualValue = parserData->tempVal;
}
    break;

  case 933:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 934:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other constraint options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 935:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other matrixProgramming options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 936:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other matrixVariable options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 937:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other objective options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 938:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 939:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other variable options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 940:

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

  case 941:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of paths cannot be negative");
    else
        parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 942:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 943:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of solver options cannot be negative");
    parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 946:

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

  case 947:

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

  case 948:

    {
        if(!osglData->numberOfElPresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires numberOfEl attribute"); 
        if(!osglData->valuePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires value attribute"); 
    }
    break;

  case 951:

    {
        osglData->osglCounter = 0;
//        osglData->numberOfElPresent = true;
//        osglData->numberOfEl = parserData->numberOf;
        if (osglData->numberOfEl > 0)
            osglData->osglIntArray = new int[osglData->numberOfEl];
    }
    break;

  case 959:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 960:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 969:

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

  case 982:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 987:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 988:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 993:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 994:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 999:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1000:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 1005:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1006:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 1011:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1012:

    {
    for (int i=0; i<osglData->numberOfEl; i++)
        if (osglData->osglIntArray < 0)
            throw ErrorClass("negative entry detected in nonnegativeIntVector");
}
    break;

  case 1013:

    {
         if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1018:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
    osglData->incr = 0;
}
    break;

  case 1024:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL IntVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->incr;    
}
    break;

  case 1030:

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

  case 1031:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1036:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}
    break;

  case 1039:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL DblVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
}
    break;

  case 1045:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->base64Size != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    double *dblvec = NULL;
    if ( osglData->numberOfEl != (base64decodeddatalength/osglData->base64Size) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
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

  case 1046:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1050:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}
    break;

  case 1053:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL StrVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglStrArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));    
}
    break;

  case 1055:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1062:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1069:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1076:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1083:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1090:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1097:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1103:

    {
    osglData->osglCounter = 0;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1104:

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

  case 1105:

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

  case 1106:

    {
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->matrixVarIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute matrixVarIdx is missing");    
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

  case 1118:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1121:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 1122:

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

  case 1123:

    {
    if (osglData->baseMatrixIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute baseMatrixIdx is missing");
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

  case 1138:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++;
}
    break;

  case 1151:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1152:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 1155:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1156:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1160:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1161:

    {
    if (osglData->rowMajor == false)
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1165:

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

  case 1168:

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

  case 1169:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1175:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1176:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1183:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1184:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1187:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1188:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1192:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1193:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1200:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1201:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 1204:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1205:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1208:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1209:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many <el> elements");
        ((LinearMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1210:

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

  case 1218:

    {
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}
    break;

  case 1219:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
}
    break;

  case 1220:

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
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    }
    osglData->osglCounter = 0;
}
    break;

  case 1232:

    {
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 1234:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}
    break;

  case 1235:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[(2) - (3)].ival);
    osglData->osglCounter++;
}
    break;

  case 1237:

    {
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1238:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 1241:

    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1242:

    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1245:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1246:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many <el> elements");        
        ((RealValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1247:

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

  case 1255:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> terms greater than expected");
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

  case 1259:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 1261:

    {
    osglData->tempC = new ComplexValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1262:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<complexValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 1265:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1266:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1269:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1270:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many <el> elements");        
        ((ComplexValuedExpressions*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1271:

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

  case 1279:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> terms greater than expected");
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

  case 1283:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osglData->nonzeroCounter < osglData->numberOfValues) 
            ((ComplexValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
                ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 1285:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1286:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1289:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1290:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1294:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1295:

    {
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1302:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1303:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1306:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1307:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1310:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1311:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many <el> elements");        
        ((ConReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1312:

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

  case 1320:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        osglData->valueTypePresent = false;
        osglData->multPresent = false;
        osglData->incrPresent = false;
        osglData->mult = 1;
        osglData->incr = 0;
        osglData->valueType = "";
    }
    break;

  case 1326:

    {
    if (osglData->nonzeroCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        if (osglData->valueType == "")
            osglData->valueType = "value";
        if (returnConReferenceValueType(osglData->valueType) <= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
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

  case 1328:

    {
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1329:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
}
    break;

  case 1332:

    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1333:

    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1336:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1337:

    {
        if (osglData->numberOfValues > osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->numberOfValues < osglData->nonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many <el> elements");
        ((ComplexMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 1338:

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

  case 1345:

    {
    if (!osglData->realPartPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "real part missing");
    if (!osglData->imagPartPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "imaginary part missing");

    if (osglData->nonzeroCounter + osglData->mult > osglData->numberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more data elements than specified");
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

  case 1346:

    {
        if (osglData->nonzeroCounter >= osglData->numberOfValues) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
                "number of <el> terms greater than expected");
        osglData->realPartPresent = false;
        osglData->imagPartPresent = false;
        osglData->multPresent = false;
        osglData->mult = 1;
    }
    break;

  case 1355:

    {
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1356:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
}
    break;

  case 1359:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1360:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1364:

    {
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1365:

    {
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1372:

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

  case 1374:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}
    break;

  case 1375:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 1376:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 1377:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}
    break;

  case 1378:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}
    break;

  case 1380:

    {
    if ( ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren != 
                           osglData->nBlocksVec.back())
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "Number of blocks does not agree with attribute value numberOfBlocks");

    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->m_mChildren
        = new MatrixNode*[((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren];
    osglData->mtxBlocksVec.pop_back();
    osglData->nBlocksVec.pop_back();
}
    break;

  case 1381:

    {
    if (osglData->osglCounter != osglData->numberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of colOffsets does not match numberOfEl");
    ((MatrixBlocks*)osglData->tempC)->colOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->colOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->colOffset->el = osglData->osglIntArray;
    osglData->colOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1382:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 1383:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1389:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1390:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 1391:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1398:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}
    break;

  case 1399:

    {
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1400:

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

  case 1406:

    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
        if (osglData->symmetry == "none")
            osglData->symmetry =  "default";
        ((MatrixBlock*)osglData->tempC)->symmetry
            = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    }
    break;

  case 1407:

    {
        ((MatrixBlock*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
    break;

  case 1411:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 1412:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksPresent = true;        
    osglData->numberOfBlocks = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1413:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsPresent = true;        
    osglData->numberOfColumns = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1414:

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

  case 1415:

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

  case 1416:

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

  case 1417:

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

  case 1418:

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

  case 1419:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfMatrixVarPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfMatrixVar attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <matrixVar> cannot be negative");
    osglData->numberOfMatrixVarPresent = true;        
    osglData->numberOfMatrixVar = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1420:

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

  case 1421:

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

  case 1422:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <rows> cannot be negative");
std::cout << "Number of rows present" << std::endl;
    osglData->numberOfRowsPresent = true;        
    osglData->numberOfRows = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1423:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesPresent = true;        
    osglData->numberOfValues = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1424:

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

  case 1425:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxPresent = true;        
    osglData->numberOfVarIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1426:

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

  case 1427:

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

  case 1428:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    if ((yyvsp[(3) - (4)].ival) > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1429:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
                                         "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1430:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
                                         "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
                                         "baseMatrix first column cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1431:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix end row cannot be negative");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1432:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix end col cannot be negative");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1433:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockRowIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
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

  case 1434:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->blockColIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockColIdx cannot be negative");
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

  case 1435:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1436:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1437:

    {
    if (osglData->matrixVarIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one matrixVarIdx attribute in <matrixVar> element");
    osglData->matrixVarIdxPresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<matrixVarIdx> cannot be negative");
    osglData->matrixVarIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1438:

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

  case 1439:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowPresent = true;   
    osglData->targetMatrixFirstRow = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1440:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColPresent = true;   
    osglData->targetMatrixFirstCol = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1441:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->coefPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "linear matrix elements: duplicate coef");    
    else
    {
        osglData->coef = parserData->tempVal;
        osglData->coefPresent = true;
    }
}
    break;

  case 1442:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->constantPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "linear matrix elements: duplicate constant");    
    else
    {
        osglData->constant = parserData->tempVal;
        osglData->constantPresent = true;
    }
}
    break;

  case 1443:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
}
    break;

  case 1444:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
}
    break;

  case 1445:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}
    break;

  case 1448:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}
    break;

  case 1449:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
    {
        if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->baseTranspose = false;
        else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osglData->baseTranspose = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osglData->baseTranspose = false;
        else parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    }
    osglData->baseTransposePresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1452:

    {
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;
}
    break;

  case 1453:

    { 
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;   
    osglData->category = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1456:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;  
}
    break;

  case 1457:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;   
    osglData->conType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1460:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;
}
    break;

  case 1461:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;   
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1464:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
}
    break;

  case 1465:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
    osglData->enumType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1468:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}
    break;

  case 1469:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1472:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
}
    break;

  case 1473:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
    osglData->objType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1476:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}
    break;

  case 1477:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osglData->rowMajor = false;
        else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osglData->rowMajor = true;
        else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osglData->rowMajor = false;
        else parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1480:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}
    break;

  case 1481:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1484:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
}
    break;

  case 1485:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
    osglData->solver = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1488:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}
    break;

  case 1489:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1492:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}
    break;

  case 1493:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1496:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
}
    break;

  case 1497:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
    osglData->unit = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1500:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}
    break;

  case 1501:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1504:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}
    break;

  case 1505:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1508:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}
    break;

  case 1509:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1537:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1541:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1545:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1547:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1549:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1551:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1553:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1555:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1557:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1559:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1561:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1563:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1565:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1567:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1570:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1571:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1572:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1573:

    {
}
    break;

  case 1574:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1575:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1576:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1578:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1580:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1582:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}
    break;

  case 1583:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 1588:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }
    break;

  case 1589:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }
    break;

  case 1591:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 1593:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 1594:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 1597:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }
    break;

  case 1601:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 1602:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 1603:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 1604:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += 
            addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += 
            addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index cannot be negative");
    osnlData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1605:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1606:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 1608:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 1609:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1610:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1612:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 1613:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1614:

    {
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1616:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 1617:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1618:

    {
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1620:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 1621:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1622:

    {
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 1624:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 1644:

    {
    osnlData->matrixidxattON = false;
    if (osnlData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory idx attribute missing");
    if (osnlData->transposeAttributePresent == true)
        osnlData->nlMNodeMatrixRef->transpose = osnlData->matrixTransposeAttribute;
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}
    break;

  case 1645:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}
    break;

  case 1652:

    {
    if (osnlData->idxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "idx attribute repeated");
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if ((yyvsp[(3) - (4)].ival) < 0)
        throw ErrorClass("Matrix reference must be nonnegative");
    osnlData->nlMNodeMatrixRef->idx = (yyvsp[(3) - (4)].ival);
    osnlData->idxAttributePresent = true;
}
    break;

  case 1653:

    {
    if (osnlData->transposeAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "transpose attribute repeated");
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->matrixTransposeAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osnlData->matrixTransposeAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osnlData->matrixTransposeAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
    osnlData->transposeAttributePresent = true;
}
    break;

  case 1654:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1655:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 1658:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1659:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1660:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 1663:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1664:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1665:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 1668:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1670:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1673:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1676:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1679:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1682:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1684:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1687:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1689:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1691:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osnlData->includeDiagonalAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1693:

    {
     parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 1697:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1700:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1703:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1706:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1708:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1709:

    {
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 1711:

    { 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
}
    break;

  case 1713:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1716:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1719:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1732:

    {
}
    break;

  case 1733:

    {
    osglData->realPartPresent = false;
    osglData->imagPartPresent = false;
    osnlData->nlNodePoint = new OSnLCNodeNumber();
    osnlData->nlNodeVec.push_back(osnlData->nlNodePoint);
}
    break;

  case 1736:

    {
    ((OSnLCNodeNumber*)osnlData->nlNodePoint)->setValue(osglData->realPart, osglData->imagPart);
std::cout << "just to verify: value = " 
          << ((OSnLCNodeNumber*)osnlData->nlNodePoint)->getValue() << std::endl;
}
    break;

  case 1742:

    {
    osnlData->nlNodePoint = new OSnLCNodeCreate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1745:

    {
    osnlData->nlNodePoint = new OSnLCNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1747:

    {
    osnlData->nlNodePoint = new OSnLCNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->cSumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1748:

    {
    osnlData->cSumVec.back()->m_mChildren = new ExprNode*[ osnlData->cSumVec.back()->inumberOfChildren];
    osnlData->cSumVec.pop_back();
}
    break;

  case 1750:

    { 
    osnlData->cSumVec.back()->inumberOfChildren++; 
}
    break;

  case 1752:

    {
    osnlData->nlNodePoint = new OSnLCNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1755:

    {
    osnlData->nlNodePoint = new OSnLCNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1758:

    {
    osnlData->nlNodePoint = new OSnLCNodeConjugate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1761:

    {
    osnlData->nlNodePoint = new OSnLCNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1764:

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


