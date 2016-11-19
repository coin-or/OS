
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
#define YYLAST   2191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  483
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  1201
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1788
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2556

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
    2033,  2034,  2035,  2036,  2037,  2040,  2044,  2050,  2052,  2054,
    2057,  2059,  2060,  2064,  2066,  2068,  2070,  2072,  2074,  2078,
    2079,  2082,  2086,  2092,  2094,  2096,  2099,  2101,  2103,  2106,
    2111,  2115,  2117,  2119,  2120,  2123,  2125,  2127,  2129,  2133,
    2137,  2141,  2144,  2146,  2148,  2153,  2155,  2157,  2159,  2161,
    2165,  2167,  2169,  2171,  2173,  2178,  2180,  2182,  2187,  2189,
    2191,  2193,  2195,  2199,  2201,  2203,  2205,  2207,  2212,  2217,
    2222,  2227,  2232,  2237,  2242,  2247,  2252,  2257,  2262,  2267,
    2269,  2272,  2276,  2278,  2280,  2281,  2284,  2286,  2288,  2290,
    2292,  2294,  2296,  2300,  2302,  2304,  2306,  2309,  2310,  2313,
    2315,  2317,  2319,  2321,  2324,  2326,  2328,  2330,  2332,  2336,
    2338,  2339,  2342,  2344,  2346,  2348,  2350,  2352,  2354,  2356,
    2358,  2360,  2362,  2366,  2368,  2370,  2372,  2374,  2376,  2380,
    2382,  2384,  2386,  2388,  2390,  2394,  2396,  2398,  2400,  2402,
    2404,  2408,  2410,  2412,  2414,  2416,  2418,  2422,  2424,  2426,
    2428,  2429,  2432,  2436,  2438,  2440,  2441,  2444,  2446,  2448,
    2452,  2456,  2458,  2460,  2463,  2465,  2469,  2471,  2473,  2474,
    2477,  2481,  2483,  2484,  2486,  2490,  2494,  2496,  2498,  2501,
    2503,  2507,  2509,  2510,  2513,  2517,  2519,  2520,  2522,  2526,
    2530,  2532,  2534,  2536,  2538,  2542,  2544,  2548,  2550,  2552,
    2554,  2556,  2560,  2562,  2566,  2568,  2570,  2572,  2574,  2578,
    2580,  2584,  2586,  2588,  2590,  2592,  2596,  2598,  2602,  2604,
    2606,  2608,  2610,  2614,  2616,  2620,  2622,  2624,  2626,  2628,
    2632,  2634,  2638,  2640,  2642,  2644,  2646,  2650,  2652,  2654,
    2656,  2658,  2661,  2663,  2665,  2667,  2669,  2671,  2673,  2675,
    2677,  2679,  2681,  2684,  2686,  2688,  2691,  2693,  2695,  2697,
    2699,  2701,  2705,  2707,  2711,  2715,  2717,  2719,  2720,  2723,
    2725,  2727,  2729,  2731,  2733,  2735,  2737,  2738,  2741,  2743,
    2745,  2747,  2749,  2751,  2753,  2755,  2757,  2759,  2763,  2765,
    2767,  2769,  2773,  2776,  2777,  2781,  2783,  2785,  2786,  2789,
    2791,  2793,  2795,  2797,  2799,  2801,  2803,  2805,  2807,  2810,
    2812,  2813,  2816,  2818,  2820,  2822,  2824,  2826,  2828,  2830,
    2832,  2834,  2836,  2838,  2843,  2845,  2847,  2848,  2851,  2853,
    2855,  2859,  2860,  2863,  2866,  2868,  2870,  2872,  2874,  2878,
    2880,  2881,  2884,  2886,  2888,  2890,  2892,  2896,  2898,  2901,
    2903,  2905,  2907,  2909,  2913,  2915,  2920,  2922,  2924,  2925,
    2928,  2930,  2932,  2936,  2939,  2940,  2943,  2945,  2947,  2949,
    2951,  2955,  2957,  2962,  2964,  2966,  2967,  2970,  2972,  2974,
    2978,  2981,  2982,  2985,  2987,  2989,  2991,  2993,  2997,  2999,
    3000,  3003,  3007,  3009,  3011,  3012,  3015,  3017,  3019,  3021,
    3023,  3025,  3029,  3030,  3033,  3037,  3039,  3040,  3042,  3046,
    3051,  3053,  3055,  3056,  3059,  3061,  3063,  3067,  3070,  3071,
    3074,  3076,  3078,  3080,  3082,  3086,  3087,  3090,  3093,  3095,
    3097,  3099,  3101,  3105,  3110,  3112,  3114,  3115,  3118,  3120,
    3122,  3126,  3129,  3130,  3133,  3135,  3137,  3139,  3141,  3145,
    3146,  3149,  3152,  3154,  3156,  3158,  3160,  3164,  3169,  3171,
    3173,  3174,  3177,  3179,  3181,  3185,  3188,  3189,  3192,  3194,
    3196,  3198,  3200,  3204,  3206,  3211,  3213,  3215,  3216,  3219,
    3221,  3223,  3227,  3230,  3231,  3234,  3236,  3238,  3240,  3242,
    3246,  3247,  3250,  3254,  3256,  3257,  3260,  3262,  3264,  3266,
    3270,  3275,  3277,  3279,  3280,  3283,  3285,  3287,  3291,  3294,
    3295,  3298,  3300,  3302,  3304,  3306,  3310,  3311,  3314,  3318,
    3320,  3321,  3324,  3326,  3328,  3330,  3333,  3335,  3340,  3342,
    3344,  3345,  3348,  3350,  3352,  3356,  3359,  3360,  3363,  3365,
    3367,  3369,  3371,  3375,  3377,  3383,  3385,  3386,  3388,  3390,
    3394,  3396,  3398,  3404,  3406,  3410,  3412,  3414,  3416,  3418,
    3420,  3424,  3426,  3430,  3432,  3434,  3436,  3438,  3440,  3444,
    3446,  3447,  3450,  3454,  3456,  3458,  3459,  3462,  3464,  3466,
    3468,  3470,  3472,  3474,  3476,  3480,  3485,  3490,  3495,  3500,
    3505,  3510,  3515,  3520,  3525,  3530,  3535,  3540,  3545,  3550,
    3555,  3560,  3565,  3570,  3575,  3580,  3585,  3590,  3595,  3600,
    3605,  3610,  3615,  3620,  3625,  3630,  3635,  3640,  3645,  3650,
    3652,  3654,  3656,  3660,  3662,  3664,  3666,  3670,  3672,  3674,
    3676,  3680,  3682,  3684,  3686,  3690,  3692,  3694,  3696,  3700,
    3702,  3704,  3706,  3710,  3712,  3714,  3716,  3720,  3722,  3724,
    3726,  3730,  3732,  3734,  3736,  3740,  3742,  3744,  3746,  3750,
    3752,  3754,  3756,  3760,  3762,  3764,  3766,  3770,  3772,  3774,
    3776,  3780,  3782,  3784,  3786,  3790,  3792,  3794,  3796,  3800,
    3802,  3804,  3806,  3810,  3812,  3814,  3816,  3818,  3820,  3822,
    3824,  3826,  3828,  3830,  3832,  3834,  3836,  3838,  3840,  3842,
    3844,  3846,  3848,  3850,  3852,  3854,  3856,  3858,  3860,  3862,
    3864,  3865,  3869,  3871,  3874,  3875,  3879,  3881,  3884,  3885,
    3891,  3892,  3898,  3899,  3905,  3906,  3911,  3912,  3918,  3919,
    3925,  3926,  3931,  3932,  3937,  3938,  3943,  3944,  3949,  3950,
    3955,  3956,  3961,  3965,  3967,  3969,  3970,  3975,  3976,  3983,
    3984,  3989,  3990,  3995,  3996,  4001,  4005,  4007,  4009,  4012,
    4013,  4016,  4018,  4020,  4022,  4023,  4028,  4029,  4034,  4036,
    4039,  4040,  4045,  4046,  4049,  4051,  4053,  4058,  4063,  4064,
    4069,  4070,  4073,  4074,  4079,  4080,  4083,  4084,  4089,  4090,
    4093,  4094,  4099,  4100,  4103,  4104,  4109,  4110,  4113,  4115,
    4117,  4119,  4121,  4123,  4125,  4127,  4129,  4131,  4133,  4135,
    4137,  4139,  4141,  4143,  4145,  4147,  4149,  4151,  4155,  4157,
    4158,  4161,  4163,  4165,  4167,  4170,  4175,  4179,  4183,  4185,
    4187,  4190,  4195,  4199,  4201,  4203,  4206,  4211,  4215,  4217,
    4219,  4222,  4227,  4230,  4232,  4235,  4238,  4240,  4244,  4247,
    4249,  4252,  4255,  4257,  4260,  4265,  4267,  4268,  4270,  4273,
    4278,  4280,  4281,  4283,  4286,  4290,  4293,  4295,  4297,  4300,
    4303,  4305,  4309,  4312,  4314,  4317,  4320,  4322,  4326,  4329,
    4331,  4335,  4336,  4341,  4342,  4345,  4348,  4350,  4354,  4357,
    4359,  4366,  4369,  4371,  4374,  4376,  4378,  4380,  4382,  4384,
    4386,  4388,  4390,  4392,  4394,  4396,  4400,  4402,  4404,  4407,
    4409,  4410,  4413,  4415,  4417,  4421,  4423,  4427,  4431,  4433,
    4437,  4438,  4444,  4445,  4448,  4452,  4454,  4458,  4462,  4464,
    4467,  4471,  4473,  4476,  4480,  4482,  4486,  4490,  4492
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     484,     0,    -1,   485,   493,   491,    -1,   486,   487,   488,
      -1,    14,    -1,    13,    -1,    -1,    15,    -1,   489,    -1,
     490,    -1,    12,    -1,    11,   493,   491,    -1,   492,    -1,
      16,    -1,    -1,   494,   495,   581,   624,   647,   758,    -1,
      -1,  1096,    -1,    -1,   496,   497,    -1,   321,    -1,   498,
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
      -1,   130,    -1,  1076,    -1,   571,    -1,   572,    -1,    11,
     131,    -1,    12,    -1,    11,   573,   131,    -1,   574,    -1,
     575,    -1,   574,   575,    -1,   576,   577,   580,    -1,   353,
      -1,   578,    -1,    -1,   578,   579,    -1,  1477,    -1,  1501,
      -1,  1471,    -1,    11,   354,    -1,    12,    -1,    -1,   582,
     583,    -1,   323,    -1,   584,    -1,   585,    -1,    11,   324,
      -1,    12,    -1,    11,   586,   324,    -1,   587,    -1,   588,
      -1,   587,   588,    -1,   589,    -1,   596,    -1,   603,    -1,
     610,    -1,   615,    -1,   590,   591,   594,    -1,    60,    -1,
     592,    -1,    -1,   592,   593,    -1,  1498,    -1,  1471,    -1,
      11,   595,    61,    -1,  1092,    -1,   597,   598,   601,    -1,
      62,    -1,   599,    -1,    -1,   599,   600,    -1,  1498,    -1,
    1471,    -1,    11,   602,    63,    -1,  1092,    -1,   604,   605,
     608,    -1,    64,    -1,   606,    -1,    -1,   606,   607,    -1,
    1498,    -1,  1471,    -1,    11,   609,    65,    -1,  1092,    -1,
     611,   612,   613,    -1,    66,    -1,    -1,  1471,    -1,    11,
     614,    67,    -1,     6,    -1,   616,   617,   618,    -1,   130,
      -1,  1076,    -1,   619,    -1,   620,    -1,    11,   131,    -1,
      12,    -1,    11,   621,   131,    -1,   622,    -1,   623,    -1,
     622,   623,    -1,   576,   577,   580,    -1,    -1,   625,   626,
      -1,   325,    -1,   627,    -1,   628,    -1,    11,   326,    -1,
      12,    -1,    11,   629,   326,    -1,   630,    -1,   631,    -1,
     630,   631,    -1,   632,    -1,   638,    -1,   633,   634,    -1,
      68,    -1,   635,    -1,   636,    -1,    11,    69,    -1,    12,
      -1,    11,   637,    69,    -1,     4,    -1,   639,   640,   641,
      -1,   130,    -1,  1076,    -1,   642,    -1,   643,    -1,    11,
     131,    -1,    12,    -1,    11,   644,   131,    -1,   645,    -1,
     646,    -1,   645,   646,    -1,   576,   577,   580,    -1,    -1,
     648,   649,    -1,   327,    -1,   650,    -1,   651,    -1,    11,
     328,    -1,    12,    -1,    11,   652,   328,    -1,   653,    -1,
     654,    -1,   653,   654,    -1,   655,    -1,   663,    -1,   669,
      -1,   677,    -1,   682,    -1,   687,    -1,   692,    -1,   697,
      -1,   705,    -1,   721,    -1,   713,    -1,   729,    -1,   735,
      -1,   741,    -1,   749,    -1,   656,   657,   658,    -1,    70,
      -1,    -1,  1498,    -1,   659,    -1,   660,    -1,    11,    71,
      -1,    12,    -1,    11,   661,    71,    -1,   662,    -1,  1092,
      -1,   664,   665,    -1,    72,    -1,   666,    -1,   667,    -1,
      11,    73,    -1,    12,    -1,    11,   668,    73,    -1,     4,
      -1,   670,   671,   672,    -1,    74,    -1,  1071,    -1,   673,
      -1,   674,    -1,    11,    75,    -1,    12,    -1,    11,   675,
      75,    -1,   676,    -1,   675,   676,    -1,   351,    11,     4,
     352,    -1,   678,  1079,   679,    -1,    80,    -1,   680,    -1,
     681,    -1,    11,    81,    -1,    12,    -1,    11,  1039,    81,
      -1,   683,  1079,   684,    -1,    82,    -1,   685,    -1,   686,
      -1,    11,    83,    -1,    12,    -1,    11,  1039,    83,    -1,
     688,  1079,   689,    -1,    84,    -1,   690,    -1,   691,    -1,
      11,    85,    -1,    12,    -1,    11,  1039,    85,    -1,   693,
    1079,   694,    -1,    86,    -1,   695,    -1,   696,    -1,    11,
      87,    -1,    12,    -1,    11,  1039,    87,    -1,   698,   699,
     700,    -1,    92,    -1,  1078,    -1,   701,    -1,   702,    -1,
      11,    93,    -1,    12,    -1,    11,   703,    93,    -1,   704,
      -1,   703,   704,    -1,  1041,    -1,   706,   707,   708,    -1,
      94,    -1,  1078,    -1,   709,    -1,   710,    -1,    11,    95,
      -1,    12,    -1,    11,   711,    95,    -1,   712,    -1,   711,
     712,    -1,  1041,    -1,   714,   715,   716,    -1,    98,    -1,
    1078,    -1,   717,    -1,   718,    -1,    11,    99,    -1,    12,
      -1,    11,   719,    99,    -1,   720,    -1,   719,   720,    -1,
    1041,    -1,   722,   723,   724,    -1,    96,    -1,  1078,    -1,
     725,    -1,   726,    -1,    11,    97,    -1,    12,    -1,    11,
     727,    97,    -1,   728,    -1,   727,   728,    -1,  1041,    -1,
     730,   731,   732,    -1,    90,    -1,  1079,    -1,   733,    -1,
     734,    -1,    11,    91,    -1,    12,    -1,    11,  1039,    91,
      -1,   736,   737,   738,    -1,    88,    -1,  1079,    -1,   739,
      -1,   740,    -1,    11,    89,    -1,    12,    -1,    11,  1039,
      89,    -1,   742,   743,   744,    -1,   100,    -1,  1080,    -1,
     745,    -1,   746,    -1,    11,   101,    -1,    12,    -1,    11,
     747,   101,    -1,   748,    -1,   747,   748,    -1,   102,    11,
       4,   103,    -1,   750,   751,   752,    -1,   130,    -1,  1076,
      -1,   753,    -1,   754,    -1,    11,   131,    -1,    12,    -1,
      11,   755,   131,    -1,   756,    -1,   757,    -1,   756,   757,
      -1,   576,   577,   580,    -1,    -1,   759,   760,   763,    -1,
     329,    -1,   761,    -1,    -1,   761,   762,    -1,  1442,    -1,
    1431,    -1,  1437,    -1,   764,    -1,   765,    -1,    12,    -1,
      11,   766,   330,    -1,   767,   863,   930,   997,  1028,    -1,
      -1,   768,   769,   771,    -1,   319,    -1,   770,    -1,    -1,
    1077,    -1,   772,    -1,   773,    -1,    12,    -1,    11,   774,
     320,    -1,   775,   789,   803,   816,   830,   845,    -1,    -1,
     776,   777,   778,    -1,   104,    -1,  1440,    -1,   779,    -1,
     780,    -1,    11,   105,    -1,    12,    -1,    11,   781,   105,
      -1,   782,    -1,   783,    -1,   782,   783,    -1,   784,   785,
     788,    -1,   317,    -1,   786,    -1,    -1,   786,   787,    -1,
    1451,    -1,  1477,    -1,  1501,    -1,    11,   318,    -1,    12,
      -1,    -1,   790,   791,   792,    -1,   106,    -1,  1440,    -1,
     793,    -1,   794,    -1,    11,   107,    -1,    12,    -1,    11,
     795,   107,    -1,   796,    -1,   797,    -1,   796,   797,    -1,
     798,   799,   802,    -1,   317,    -1,   800,    -1,    -1,   800,
     801,    -1,  1451,    -1,  1477,    -1,  1501,    -1,    11,   318,
      -1,    12,    -1,    -1,   804,   805,    -1,   108,    -1,   806,
      -1,   807,    -1,    12,    -1,    11,   808,   109,    -1,   809,
     810,   811,   812,   813,   814,   815,    -1,    -1,  1153,    -1,
      -1,  1159,    -1,    -1,  1165,    -1,    -1,  1171,    -1,    -1,
    1177,    -1,    -1,  1183,    -1,    -1,  1189,    -1,    -1,   817,
     818,   819,    -1,   110,    -1,  1440,    -1,   820,    -1,   821,
      -1,    11,   111,    -1,    12,    -1,    11,   822,   111,    -1,
     823,    -1,   824,    -1,   823,   824,    -1,   825,   826,   829,
      -1,   317,    -1,   827,    -1,    -1,   827,   828,    -1,  1451,
      -1,  1477,    -1,  1501,    -1,    11,   318,    -1,    12,    -1,
      -1,   831,   832,   833,    -1,   112,    -1,    45,     8,     6,
       8,    -1,   834,    -1,   835,    -1,    11,   113,    -1,    12,
      -1,    11,   836,   113,    -1,   837,    -1,   836,   837,    -1,
     838,   839,   842,    -1,   114,    -1,   840,    -1,    -1,   840,
     841,    -1,  1060,    -1,  1440,    -1,  1050,    -1,   843,    -1,
     844,    -1,    11,   115,    -1,    12,    -1,    11,   823,   115,
      -1,    -1,   845,   846,    -1,   847,   848,   851,    -1,   353,
      -1,   849,    -1,    -1,   849,   850,    -1,  1440,    -1,  1433,
      -1,  1477,    -1,  1501,    -1,  1489,    -1,  1465,    -1,  1495,
      -1,  1507,    -1,  1474,    -1,  1471,    -1,   852,    -1,   853,
      -1,    11,   354,    -1,    12,    -1,    11,   854,   354,    -1,
     855,    -1,  1082,    -1,   856,    -1,   855,   856,    -1,   857,
     858,   861,    -1,   317,    -1,   859,    -1,    -1,   859,   860,
      -1,  1451,    -1,  1477,    -1,  1501,    -1,  1052,    -1,  1063,
      -1,   862,    -1,    11,   318,    -1,    12,    -1,    -1,   864,
     865,   867,    -1,   315,    -1,   866,    -1,    -1,  1075,    -1,
     868,    -1,   869,    -1,    12,    -1,    11,   870,   316,    -1,
     871,   885,   899,   912,    -1,    -1,   872,   873,   874,    -1,
     116,    -1,  1436,    -1,   875,    -1,   876,    -1,    11,   117,
      -1,    12,    -1,    11,   877,   117,    -1,   878,    -1,   879,
      -1,   878,   879,    -1,   880,   881,   884,    -1,   313,    -1,
     882,    -1,    -1,   882,   883,    -1,  1451,    -1,  1477,    -1,
    1501,    -1,    11,   314,    -1,    12,    -1,    -1,   886,   887,
     888,    -1,   118,    -1,  1436,    -1,   889,    -1,   890,    -1,
      11,   119,    -1,    12,    -1,    11,   891,   119,    -1,   892,
      -1,   893,    -1,   892,   893,    -1,   894,   895,   898,    -1,
     313,    -1,   896,    -1,    -1,   896,   897,    -1,  1451,    -1,
    1477,    -1,  1052,    -1,  1063,    -1,    11,   314,    -1,    12,
      -1,    -1,   900,   901,    -1,   108,    -1,   902,    -1,   903,
      -1,    12,    -1,    11,   904,   109,    -1,   905,   906,   907,
     908,   909,   910,   911,    -1,    -1,  1153,    -1,    -1,  1159,
      -1,    -1,  1165,    -1,    -1,  1171,    -1,    -1,  1177,    -1,
      -1,  1183,    -1,    -1,  1189,    -1,    -1,   912,   913,    -1,
     914,   915,   918,    -1,   353,    -1,   916,    -1,    -1,   916,
     917,    -1,  1436,    -1,  1433,    -1,  1477,    -1,  1501,    -1,
    1489,    -1,  1465,    -1,  1495,    -1,  1480,    -1,  1474,    -1,
    1471,    -1,   919,    -1,   920,    -1,    11,   354,    -1,    12,
      -1,    11,   921,   354,    -1,   922,    -1,  1082,    -1,   923,
      -1,   922,   923,    -1,   924,   925,   928,    -1,   313,    -1,
     926,    -1,    -1,   926,   927,    -1,  1451,    -1,  1477,    -1,
    1501,    -1,  1052,    -1,  1063,    -1,   929,    -1,    11,   314,
      -1,    12,    -1,    -1,   931,   932,   934,    -1,   311,    -1,
     933,    -1,    -1,  1072,    -1,   935,    -1,   936,    -1,    12,
      -1,    11,   937,   312,    -1,   938,   952,   966,   979,    -1,
      -1,   939,   940,   941,    -1,   120,    -1,  1430,    -1,   942,
      -1,   943,    -1,    11,   121,    -1,    12,    -1,    11,   944,
     121,    -1,   945,    -1,   946,    -1,   945,   946,    -1,   947,
     948,   951,    -1,   309,    -1,   949,    -1,    -1,   949,   950,
      -1,  1451,    -1,  1477,    -1,  1501,    -1,    11,   310,    -1,
      12,    -1,    -1,   953,   954,   955,    -1,   122,    -1,  1430,
      -1,   956,    -1,   957,    -1,    11,   123,    -1,    12,    -1,
      11,   958,   123,    -1,   959,    -1,   960,    -1,   959,   960,
      -1,   961,   962,   965,    -1,   309,    -1,   963,    -1,    -1,
     963,   964,    -1,  1451,    -1,  1477,    -1,  1056,    -1,  1067,
      -1,    11,   310,    -1,    12,    -1,    -1,   967,   968,    -1,
     108,    -1,   969,    -1,   970,    -1,    12,    -1,    11,   971,
     109,    -1,   972,   973,   974,   975,   976,   977,   978,    -1,
      -1,  1153,    -1,    -1,  1159,    -1,    -1,  1165,    -1,    -1,
    1171,    -1,    -1,  1177,    -1,    -1,  1183,    -1,    -1,  1189,
      -1,    -1,   979,   980,    -1,   981,   982,   985,    -1,   353,
      -1,   983,    -1,    -1,   983,   984,    -1,  1430,    -1,  1433,
      -1,  1477,    -1,  1501,    -1,  1489,    -1,  1465,    -1,  1495,
      -1,  1468,    -1,  1474,    -1,  1471,    -1,   986,    -1,   987,
      -1,    11,   354,    -1,    12,    -1,    11,   988,   354,    -1,
     989,    -1,  1082,    -1,   990,    -1,   989,   990,    -1,   991,
     992,   995,    -1,   309,    -1,   993,    -1,    -1,   993,   994,
      -1,  1451,    -1,  1477,    -1,  1501,    -1,  1052,    -1,  1063,
      -1,   996,    -1,    11,   310,    -1,    12,    -1,    -1,   998,
     999,  1001,    -1,   295,    -1,  1000,    -1,    -1,  1073,    -1,
    1002,    -1,  1003,    -1,    12,    -1,    11,  1004,  1021,  1022,
    1023,   296,    -1,    -1,  1005,  1006,  1007,    -1,   297,    -1,
      -1,  1074,    -1,  1008,    -1,  1009,    -1,    12,    -1,    11,
    1011,  1020,  1010,    -1,   298,    -1,    -1,  1012,  1013,  1014,
      -1,   124,    -1,  1435,    -1,  1015,    -1,  1016,    -1,    12,
      -1,    11,  1018,  1017,    -1,   125,    -1,    -1,  1018,  1019,
      -1,  1209,    -1,    -1,    -1,    -1,    -1,  1023,  1024,    -1,
    1025,  1196,  1026,    -1,  1025,  1196,    11,  1199,  1027,    -1,
     353,    -1,    12,    -1,    11,  1027,    -1,   354,    -1,    -1,
    1029,  1030,  1031,    -1,   126,    -1,  1081,    -1,  1032,    -1,
    1033,    -1,    12,    -1,    11,  1034,   127,    -1,    -1,  1034,
    1035,    -1,  1036,  1196,  1037,    -1,  1036,  1196,    11,  1199,
    1038,    -1,   128,    -1,    12,    -1,    11,  1038,    -1,   129,
      -1,  1040,    -1,  1039,  1040,    -1,    76,    11,     4,    77,
      -1,  1042,  1043,  1049,    -1,    78,    -1,  1044,    -1,    -1,
    1044,  1045,    -1,  1046,    -1,  1047,    -1,  1048,    -1,    29,
       3,     8,    -1,    30,     3,     8,    -1,    31,     3,     8,
      -1,    11,    79,    -1,    12,    -1,  1051,    -1,    47,     8,
    1092,     8,    -1,  1053,    -1,  1054,    -1,  1055,    -1,    17,
      -1,    19,     3,  1093,    -1,  1057,    -1,  1058,    -1,  1059,
      -1,    21,    -1,    23,  1093,  1092,  1093,    -1,  1061,    -1,
    1062,    -1,    46,  1093,     6,  1093,    -1,  1064,    -1,  1065,
      -1,  1066,    -1,    18,    -1,    20,     3,  1093,    -1,  1068,
      -1,  1069,    -1,  1070,    -1,    22,    -1,    24,  1093,  1092,
    1093,    -1,    32,     8,     6,     8,    -1,    38,  1093,     6,
    1093,    -1,    39,  1093,     6,  1093,    -1,    40,  1093,     6,
    1093,    -1,    37,  1093,     6,  1093,    -1,    44,  1093,     6,
    1093,    -1,    36,  1093,     6,  1093,    -1,    34,     8,     6,
       8,    -1,    33,     8,     6,     8,    -1,    35,     8,     6,
       8,    -1,    43,  1093,     6,  1093,    -1,  1083,    -1,  1082,
    1083,    -1,  1084,  1085,  1088,    -1,   162,    -1,  1086,    -1,
      -1,  1086,  1087,    -1,  1432,    -1,  1501,    -1,  1471,    -1,
    1089,    -1,  1090,    -1,    12,    -1,    11,  1091,   163,    -1,
    1125,    -1,     6,    -1,     7,    -1,  1094,     8,    -1,    -1,
    1094,  1095,    -1,   479,    -1,   480,    -1,   481,    -1,   482,
      -1,  1097,  1098,    -1,   132,    -1,  1099,    -1,  1100,    -1,
      12,    -1,    11,  1101,   133,    -1,  1102,    -1,    -1,  1102,
    1103,    -1,  1104,    -1,  1108,    -1,  1112,    -1,  1116,    -1,
    1120,    -1,  1105,    -1,  1106,    -1,  1107,    -1,   137,    -1,
     136,    -1,   134,     5,   135,    -1,  1109,    -1,  1110,    -1,
    1111,    -1,   141,    -1,   140,    -1,   138,     5,   139,    -1,
    1113,    -1,  1114,    -1,  1115,    -1,   145,    -1,   144,    -1,
     142,     5,   143,    -1,  1117,    -1,  1118,    -1,  1119,    -1,
     149,    -1,   148,    -1,   146,     5,   147,    -1,  1121,    -1,
    1122,    -1,  1123,    -1,   153,    -1,   152,    -1,   150,     5,
     151,    -1,  1125,    -1,  1126,    -1,  1133,    -1,    -1,  1126,
    1127,    -1,  1128,  1129,  1132,    -1,   160,    -1,  1130,    -1,
      -1,  1130,  1131,    -1,  1454,    -1,  1452,    -1,    11,     6,
     161,    -1,   168,  1443,  1134,    -1,  1135,    -1,  1136,    -1,
      11,   169,    -1,    12,    -1,    11,     4,   169,    -1,  1138,
      -1,  1143,    -1,    -1,  1138,  1139,    -1,  1140,  1141,  1142,
      -1,   160,    -1,    -1,  1454,    -1,    11,  1092,   161,    -1,
     168,  1443,  1144,    -1,  1145,    -1,  1146,    -1,    11,   169,
      -1,    12,    -1,    11,     4,   169,    -1,  1148,    -1,    -1,
    1148,  1149,    -1,  1150,  1151,  1152,    -1,   160,    -1,    -1,
    1454,    -1,    11,     4,   161,    -1,  1154,  1195,  1155,    -1,
     337,    -1,  1156,    -1,  1157,    -1,    12,    -1,    11,  1158,
     338,    -1,  1125,    -1,  1160,  1195,  1161,    -1,   333,    -1,
    1162,    -1,  1163,    -1,    12,    -1,    11,  1164,   334,    -1,
    1125,    -1,  1166,  1195,  1167,    -1,   335,    -1,  1168,    -1,
    1169,    -1,    12,    -1,    11,  1170,   336,    -1,  1125,    -1,
    1172,  1195,  1173,    -1,   331,    -1,  1174,    -1,  1175,    -1,
      12,    -1,    11,  1176,   332,    -1,  1125,    -1,  1178,  1195,
    1179,    -1,   339,    -1,  1180,    -1,  1181,    -1,    12,    -1,
      11,  1182,   340,    -1,  1125,    -1,  1184,  1195,  1185,    -1,
     341,    -1,  1186,    -1,  1187,    -1,    12,    -1,    11,  1188,
     342,    -1,  1125,    -1,  1190,  1195,  1191,    -1,   343,    -1,
    1192,    -1,  1193,    -1,    12,    -1,    11,  1194,   344,    -1,
    1125,    -1,  1432,    -1,  1197,    -1,  1198,    -1,  1197,  1198,
      -1,  1477,    -1,  1501,    -1,  1489,    -1,  1465,    -1,  1495,
      -1,  1471,    -1,  1434,    -1,  1200,    -1,  1202,    -1,  1201,
      -1,  1200,  1201,    -1,  1208,    -1,  1203,    -1,  1202,  1203,
      -1,  1204,    -1,  1205,    -1,  1206,    -1,   167,    -1,   164,
      -1,   165,  1207,   166,    -1,     5,    -1,  1210,  1211,  1218,
      -1,  1214,  1215,  1221,    -1,   253,    -1,  1212,    -1,    -1,
    1212,  1213,    -1,  1492,    -1,  1438,    -1,  1429,    -1,  1477,
      -1,  1495,    -1,   299,    -1,  1216,    -1,    -1,  1216,  1217,
      -1,  1492,    -1,  1438,    -1,  1429,    -1,  1477,    -1,  1495,
      -1,  1453,    -1,  1219,    -1,  1220,    -1,    12,    -1,    11,
    1224,   254,    -1,  1222,    -1,  1223,    -1,    12,    -1,    11,
    1224,   300,    -1,  1225,  1231,    -1,    -1,  1226,  1227,  1230,
      -1,   256,    -1,  1228,    -1,    -1,  1228,  1229,    -1,  1444,
      -1,  1455,    -1,  1456,    -1,  1445,    -1,  1446,    -1,  1447,
      -1,  1448,    -1,  1462,    -1,  1461,    -1,    11,   255,    -1,
      12,    -1,    -1,  1231,  1232,    -1,  1233,    -1,  1365,    -1,
    1383,    -1,  1258,    -1,  1334,    -1,  1347,    -1,  1271,    -1,
    1298,    -1,  1316,    -1,  1396,    -1,  1400,    -1,  1234,  1235,
      11,  1238,    -1,   267,    -1,  1236,    -1,    -1,  1236,  1237,
      -1,  1439,    -1,  1483,    -1,  1240,  1239,   268,    -1,    -1,
    1246,  1252,    -1,  1241,  1242,    -1,   285,    -1,  1243,    -1,
    1244,    -1,    12,    -1,    11,  1245,   286,    -1,  1124,    -1,
      -1,  1247,  1248,    -1,   287,    -1,  1249,    -1,  1250,    -1,
      12,    -1,    11,  1251,   288,    -1,  1124,    -1,  1253,  1254,
      -1,   289,    -1,  1255,    -1,  1256,    -1,    12,    -1,    11,
    1257,   290,    -1,  1137,    -1,  1259,  1260,    11,  1263,    -1,
     271,    -1,  1261,    -1,    -1,  1261,  1262,    -1,  1439,    -1,
    1483,    -1,  1240,  1264,   272,    -1,  1246,  1265,    -1,    -1,
    1266,  1267,    -1,   289,    -1,  1268,    -1,  1269,    -1,    12,
      -1,    11,  1270,   290,    -1,  1124,    -1,  1272,  1273,    11,
    1276,    -1,   273,    -1,  1274,    -1,    -1,  1274,  1275,    -1,
    1439,    -1,  1483,    -1,  1240,  1277,   274,    -1,  1246,  1278,
      -1,    -1,  1279,  1280,    -1,   289,    -1,  1281,    -1,  1282,
      -1,    12,    -1,    11,  1283,   290,    -1,  1284,    -1,    -1,
    1284,  1285,    -1,  1286,  1287,  1290,    -1,   160,    -1,  1288,
      -1,    -1,  1288,  1289,    -1,  1441,    -1,  1458,    -1,  1291,
      -1,  1292,    -1,    12,    -1,    11,  1293,   161,    -1,    -1,
    1293,  1294,    -1,  1295,  1296,  1297,    -1,   291,    -1,    -1,
    1457,    -1,    11,     6,   292,    -1,  1299,  1300,    11,  1303,
      -1,   279,    -1,  1301,    -1,    -1,  1301,  1302,    -1,  1439,
      -1,  1483,    -1,  1240,  1304,   280,    -1,  1246,  1305,    -1,
      -1,  1306,  1307,    -1,   289,    -1,  1308,    -1,  1309,    -1,
      12,    -1,    11,  1310,   290,    -1,    -1,  1310,  1311,    -1,
    1312,  1313,    -1,   160,    -1,  1314,    -1,  1315,    -1,    12,
      -1,    11,  1510,   161,    -1,  1317,  1318,    11,  1321,    -1,
     281,    -1,  1319,    -1,    -1,  1319,  1320,    -1,  1439,    -1,
    1483,    -1,  1240,  1322,   282,    -1,  1246,  1323,    -1,    -1,
    1324,  1325,    -1,   289,    -1,  1326,    -1,  1327,    -1,    12,
      -1,    11,  1328,   290,    -1,    -1,  1328,  1329,    -1,  1330,
    1331,    -1,   160,    -1,  1332,    -1,  1333,    -1,    12,    -1,
      11,  1653,   161,    -1,  1335,  1336,    11,  1339,    -1,   277,
      -1,  1337,    -1,    -1,  1337,  1338,    -1,  1439,    -1,  1483,
      -1,  1240,  1340,   278,    -1,  1246,  1341,    -1,    -1,  1342,
    1343,    -1,   289,    -1,  1344,    -1,  1345,    -1,    12,    -1,
      11,  1346,   290,    -1,  1125,    -1,  1348,  1349,    11,  1352,
      -1,   275,    -1,  1350,    -1,    -1,  1350,  1351,    -1,  1439,
      -1,  1483,    -1,  1240,  1353,   276,    -1,  1246,  1354,    -1,
      -1,  1355,  1356,    -1,   289,    -1,  1357,    -1,  1358,    -1,
      12,    -1,    11,  1359,   290,    -1,    -1,  1359,  1360,    -1,
    1361,  1362,  1364,    -1,   160,    -1,    -1,  1362,  1363,    -1,
    1504,    -1,  1454,    -1,  1452,    -1,    11,     6,   161,    -1,
    1366,  1367,    11,  1370,    -1,   269,    -1,  1368,    -1,    -1,
    1368,  1369,    -1,  1439,    -1,  1483,    -1,  1240,  1371,   270,
      -1,  1246,  1372,    -1,    -1,  1373,  1374,    -1,   289,    -1,
    1375,    -1,  1376,    -1,    12,    -1,    11,  1377,   290,    -1,
      -1,  1377,  1378,    -1,  1379,  1380,  1382,    -1,   160,    -1,
      -1,  1380,  1381,    -1,  1460,    -1,  1459,    -1,  1454,    -1,
      11,   161,    -1,    12,    -1,  1384,  1385,    11,  1388,    -1,
     283,    -1,  1386,    -1,    -1,  1386,  1387,    -1,  1439,    -1,
    1483,    -1,  1240,  1389,   284,    -1,  1246,  1390,    -1,    -1,
    1391,  1392,    -1,   289,    -1,  1393,    -1,  1394,    -1,    12,
      -1,    11,  1395,   290,    -1,  1147,    -1,  1397,  1398,    11,
    1584,  1399,    -1,   293,    -1,    -1,  1486,    -1,   294,    -1,
    1401,  1402,  1403,    -1,   257,    -1,  1428,    -1,    11,  1405,
    1412,  1419,  1404,    -1,   258,    -1,  1406,  1407,  1408,    -1,
     261,    -1,  1432,    -1,  1409,    -1,  1410,    -1,    12,    -1,
      11,  1411,   262,    -1,  1125,    -1,  1413,  1414,  1415,    -1,
     263,    -1,  1432,    -1,  1416,    -1,  1417,    -1,    12,    -1,
      11,  1418,   264,    -1,  1125,    -1,    -1,  1419,  1420,    -1,
    1421,  1422,  1425,    -1,   259,    -1,  1423,    -1,    -1,  1423,
    1424,    -1,  1449,    -1,  1450,    -1,  1492,    -1,  1495,    -1,
    1426,    -1,  1427,    -1,    12,    -1,    11,  1224,   260,    -1,
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
     246,     8,     6,     8,    -1,   242,  1093,     6,  1093,    -1,
     247,     8,     6,     8,    -1,   231,     8,     6,     8,    -1,
     232,     8,     6,     8,    -1,   249,     8,  1092,     8,    -1,
     250,     8,  1092,     8,    -1,   241,     8,  1092,     8,    -1,
     240,     8,  1092,     8,    -1,   237,     8,  1092,     8,    -1,
    1463,    -1,  1464,    -1,   211,    -1,   212,     3,  1093,    -1,
    1466,    -1,  1467,    -1,   173,    -1,   174,     3,     8,    -1,
    1469,    -1,  1470,    -1,   193,    -1,   194,     3,     8,    -1,
    1472,    -1,  1473,    -1,   175,    -1,   176,     3,     8,    -1,
    1475,    -1,  1476,    -1,   183,    -1,   184,     3,     8,    -1,
    1478,    -1,  1479,    -1,   179,    -1,   180,     3,     8,    -1,
    1481,    -1,  1482,    -1,   195,    -1,   196,     3,     8,    -1,
    1484,    -1,  1485,    -1,   209,    -1,   210,     3,     8,    -1,
    1487,    -1,  1488,    -1,   185,    -1,   186,     3,     8,    -1,
    1490,    -1,  1491,    -1,   177,    -1,   178,     3,     8,    -1,
    1493,    -1,  1494,    -1,   207,    -1,   208,     3,     8,    -1,
    1496,    -1,  1497,    -1,   181,    -1,   182,     3,     8,    -1,
    1499,    -1,  1500,    -1,   187,    -1,   188,     3,     8,    -1,
    1502,    -1,  1503,    -1,   189,    -1,   190,     3,     8,    -1,
    1505,    -1,  1506,    -1,   191,    -1,   192,     3,     8,    -1,
    1508,    -1,  1509,    -1,   197,    -1,   198,     3,     8,    -1,
    1554,    -1,  1561,    -1,  1517,    -1,  1519,    -1,  1569,    -1,
    1521,    -1,  1523,    -1,  1525,    -1,  1527,    -1,  1581,    -1,
    1529,    -1,  1531,    -1,  1533,    -1,  1537,    -1,  1535,    -1,
    1539,    -1,  1546,    -1,  1541,    -1,  1544,    -1,  1575,    -1,
    1578,    -1,  1511,    -1,  1514,    -1,  1572,    -1,  1548,    -1,
    1550,    -1,  1552,    -1,    -1,   409,  1512,  1513,    -1,    12,
      -1,    11,   410,    -1,    -1,   411,  1515,  1516,    -1,    12,
      -1,    11,   412,    -1,    -1,   413,  1518,  1510,  1510,   414,
      -1,    -1,   371,  1520,  1510,  1510,   372,    -1,    -1,   373,
    1522,  1510,  1510,   374,    -1,    -1,   387,  1524,  1510,   388,
      -1,    -1,   375,  1526,  1510,  1510,   376,    -1,    -1,   369,
    1528,  1510,  1510,   370,    -1,    -1,   377,  1530,  1510,   378,
      -1,    -1,   379,  1532,  1510,   380,    -1,    -1,   391,  1534,
    1510,   392,    -1,    -1,   393,  1536,  1510,   394,    -1,    -1,
     395,  1538,  1510,   396,    -1,    -1,   385,  1540,  1510,   386,
      -1,  1542,  1510,  1543,    -1,   399,    -1,   400,    -1,    -1,
     401,  1545,  1510,   402,    -1,    -1,   389,  1547,  1510,  1510,
    1510,   390,    -1,    -1,   417,  1549,  1584,   418,    -1,    -1,
     419,  1551,  1584,   420,    -1,    -1,   421,  1553,  1584,   422,
      -1,  1555,  1557,  1556,    -1,   415,    -1,    12,    -1,    11,
     416,    -1,    -1,  1557,  1558,    -1,  1495,    -1,  1501,    -1,
    1559,    -1,    -1,   478,     3,  1560,     8,    -1,    -1,   397,
    1562,  1565,  1563,    -1,    12,    -1,    11,   398,    -1,    -1,
      11,  1510,  1564,   398,    -1,    -1,  1565,  1566,    -1,  1567,
      -1,  1568,    -1,   249,     8,  1092,     8,    -1,   245,     8,
       6,     8,    -1,    -1,   381,  1570,  1571,   382,    -1,    -1,
    1571,  1510,    -1,    -1,   405,  1573,  1574,   406,    -1,    -1,
    1574,  1510,    -1,    -1,   403,  1576,  1577,   404,    -1,    -1,
    1577,  1510,    -1,    -1,   407,  1579,  1580,   408,    -1,    -1,
    1580,  1510,    -1,    -1,   383,  1582,  1583,   384,    -1,    -1,
    1583,  1510,    -1,  1585,    -1,  1592,    -1,  1596,    -1,  1600,
      -1,  1604,    -1,  1607,    -1,  1613,    -1,  1616,    -1,  1620,
      -1,  1625,    -1,  1628,    -1,  1631,    -1,  1634,    -1,  1637,
      -1,  1640,    -1,  1643,    -1,  1646,    -1,  1649,    -1,  1610,
      -1,  1586,  1587,  1589,    -1,   449,    -1,    -1,  1587,  1588,
      -1,  1590,    -1,  1591,    -1,    12,    -1,    11,   450,    -1,
     245,     8,     6,     8,    -1,   476,     3,     8,    -1,  1593,
    1595,  1594,    -1,   299,    -1,    12,    -1,    11,   300,    -1,
     245,     8,     6,     8,    -1,  1597,  1599,  1598,    -1,   303,
      -1,    12,    -1,    11,   304,    -1,   245,     8,     6,     8,
      -1,  1601,  1603,  1602,    -1,   307,    -1,    12,    -1,    11,
     308,    -1,   245,     8,     6,     8,    -1,  1605,  1606,    -1,
     423,    -1,  1584,   424,    -1,  1608,  1609,    -1,   425,    -1,
    1584,  1584,   426,    -1,  1611,  1612,    -1,   451,    -1,  1510,
     452,    -1,  1614,  1615,    -1,   453,    -1,  1584,   454,    -1,
    1617,  1618,    11,  1619,    -1,   427,    -1,    -1,  1624,    -1,
    1584,   428,    -1,  1621,  1622,    11,  1623,    -1,   429,    -1,
      -1,  1624,    -1,  1584,   430,    -1,   474,     3,     8,    -1,
    1626,  1627,    -1,   431,    -1,    12,    -1,    11,   432,    -1,
    1629,  1630,    -1,   433,    -1,  1584,  1584,   434,    -1,  1632,
    1633,    -1,   435,    -1,  1584,   436,    -1,  1635,  1636,    -1,
     437,    -1,  1584,  1584,   438,    -1,  1638,  1639,    -1,   439,
      -1,  1584,  1584,   440,    -1,    -1,   441,  1641,  1642,   442,
      -1,    -1,  1642,  1584,    -1,  1644,  1645,    -1,   443,    -1,
    1584,  1652,   444,    -1,  1647,  1648,    -1,   445,    -1,  1510,
    1510,  1510,  1510,  1584,   446,    -1,  1650,  1651,    -1,   447,
      -1,  1584,   448,    -1,  1510,    -1,  1653,    -1,  1654,    -1,
    1660,    -1,  1663,    -1,  1666,    -1,  1669,    -1,  1672,    -1,
    1675,    -1,  1678,    -1,  1681,    -1,  1655,  1657,  1656,    -1,
     461,    -1,    12,    -1,    11,   462,    -1,  1658,    -1,    -1,
    1658,  1659,    -1,  1460,    -1,  1459,    -1,  1661,    11,  1662,
      -1,   471,    -1,  1510,  1510,   472,    -1,  1664,    11,  1665,
      -1,   463,    -1,  1652,  1652,   464,    -1,    -1,   467,    11,
    1667,  1668,   468,    -1,    -1,  1668,  1652,    -1,  1670,    11,
    1671,    -1,   457,    -1,  1652,  1652,   458,    -1,  1673,    11,
    1674,    -1,   459,    -1,  1652,   460,    -1,  1676,    11,  1677,
      -1,   455,    -1,  1652,   456,    -1,  1679,    11,  1680,    -1,
     469,    -1,  1652,  1652,   470,    -1,  1682,    11,  1683,    -1,
     465,    -1,  1652,   466,    -1
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
    3985,  4154,  4156,  4158,  4158,  4187,  4196,  4206,  4226,  4226,
    4228,  4236,  4236,  4242,  4244,  4252,  4262,  4273,  4275,  4277,
    4277,  4304,  4315,  4327,  4347,  4347,  4349,  4480,  4480,  4482,
    4504,  4521,  4533,  4538,  4538,  4541,  4542,  4543,  4545,  4554,
    4563,  4572,  4572,  4656,  4663,  4685,  4692,  4692,  4694,  4699,
    4706,  4712,  4712,  4714,  4719,  4783,  4789,  4791,  4817,  4824,
    4824,  4826,  4831,  4838,  4844,  4844,  4846,  4849,  4961,  4990,
    4997,  5004,  5024,  5030,  5036,  5042,  5056,  5066,  5077,  5113,
    5113,  5115,  5134,  5151,  5159,  5159,  5162,  5170,  5171,  5175,
    5175,  5177,  5180,  5182,  5186,  5187,  5194,  5196,  5196,  5198,
    5199,  5200,  5201,  5236,  5238,  5252,  5252,  5254,  5256,  5258,
    5260,  5260,  5263,  5264,  5265,  5266,  5267,  5269,  5277,  5277,
    5279,  5279,  5281,  5287,  5295,  5295,  5297,  5297,  5299,  5305,
    5313,  5313,  5315,  5315,  5317,  5323,  5331,  5331,  5333,  5333,
    5335,  5341,  5349,  5349,  5351,  5351,  5353,  5364,  5372,  5380,
    5382,  5382,  5384,  5386,  5395,  5397,  5397,  5399,  5399,  5401,
    5410,  5413,  5413,  5415,  5415,  5418,  5449,  5457,  5459,  5459,
    5461,  5463,  5471,  5471,  5473,  5482,  5484,  5484,  5486,  5486,
    5488,  5519,  5529,  5529,  5531,  5533,  5541,  5541,  5543,  5679,
    5681,  5686,  5686,  5688,  5690,  5692,  5695,  5697,  5702,  5702,
    5704,  5706,  5708,  5711,  5713,  5718,  5718,  5720,  5722,  5724,
    5727,  5729,  5734,  5734,  5736,  5738,  5740,  5743,  5745,  5750,
    5750,  5752,  5754,  5756,  5759,  5761,  5766,  5766,  5768,  5770,
    5772,  5775,  5777,  5782,  5782,  5784,  5786,  5788,  5791,  5802,
    5809,  5810,  5813,  5814,  5815,  5816,  5817,  5818,  5819,  5826,
    5826,  5829,  5830,  5832,  5837,  5838,  5840,  5848,  5861,  5863,
    5863,  5865,  5867,  5890,  5905,  5942,  5965,  5989,  5989,  5992,
    5993,  5994,  5995,  5996,  6000,  6025,  6053,  6053,  6056,  6057,
    6058,  6059,  6060,  6061,  6193,  6193,  6195,  6197,  6204,  6204,
    6206,  6208,  6237,  6239,  6239,  6244,  6262,  6291,  6291,  6294,
    6295,  6296,  6297,  6298,  6299,  6300,  6301,  6302,  6305,  6305,
    6307,  6307,  6312,  6312,  6312,  6313,  6313,  6313,  6314,  6314,
    6314,  6315,  6315,  6317,  6319,  6328,  6334,  6334,  6337,  6341,
    6347,  6349,  6349,  6355,  6365,  6375,  6375,  6377,  6379,  6395,
    6398,  6398,  6412,  6420,  6420,  6422,  6424,  6426,  6432,  6442,
    6450,  6450,  6452,  6454,  6456,  6459,  6461,  6470,  6476,  6476,
    6479,  6483,  6489,  6491,  6493,  6493,  6503,  6511,  6511,  6513,
    6515,  6517,  6520,  6522,  6531,  6537,  6537,  6540,  6544,  6550,
    6552,  6555,  6560,  6571,  6587,  6587,  6589,  6591,  6593,  6595,
    6595,  6597,  6604,  6611,  6630,  6630,  6633,  6634,  6636,  6636,
    6638,  6640,  6642,  6642,  6645,  6647,  6655,  6655,  6660,  6667,
    6669,  6678,  6684,  6684,  6687,  6691,  6698,  6700,  6703,  6707,
    6718,  6734,  6734,  6736,  6738,  6740,  6740,  6742,  6744,  6759,
    6759,  6761,  6763,  6772,  6774,  6783,  6789,  6789,  6792,  6796,
    6803,  6805,  6808,  6812,  6823,  6840,  6840,  6842,  6844,  6846,
    6846,  6848,  6850,  6865,  6865,  6867,  6869,  6879,  6881,  6890,
    6896,  6896,  6899,  6903,  6909,  6911,  6913,  6913,  6923,  6931,
    6931,  6933,  6935,  6937,  6940,  6942,  6951,  6957,  6957,  6960,
    6964,  6970,  6972,  6975,  6979,  6990,  7006,  7006,  7008,  7010,
    7012,  7012,  7014,  7017,  7029,  7029,  7032,  7033,  7034,  7036,
    7069,  7071,  7081,  7087,  7087,  7090,  7094,  7100,  7102,  7105,
    7109,  7120,  7133,  7133,  7135,  7137,  7139,  7139,  7141,  7168,
    7179,  7179,  7182,  7183,  7184,  7186,  7186,  7189,  7191,  7200,
    7206,  7206,  7209,  7213,  7219,  7221,  7223,  7223,  7233,  7241,
    7241,  7243,  7245,  7247,  7250,  7253,  7271,  7271,  7282,  7289,
    7299,  7307,  7313,  7315,  7329,  7341,  7347,  7353,  7353,  7355,
    7357,  7359,  7361,  7371,  7377,  7383,  7383,  7385,  7387,  7389,
    7391,  7391,  7396,  7401,  7413,  7415,  7415,  7418,  7419,  7420,
    7430,  7437,  7437,  7439,  7441,  7459,  7470,  7481,  7503,  7514,
    7525,  7536,  7580,  7604,  7626,  7637,  7649,  7660,  7671,  7682,
    7696,  7707,  7721,  7736,  7751,  7763,  7775,  7795,  7815,  7825,
    7855,  7865,  7876,  7888,  7902,  7915,  7928,  7938,  7948,  7961,
    7961,  7963,  7973,  7991,  7991,  7993,  8000,  8009,  8009,  8011,
    8018,  8027,  8027,  8029,  8036,  8045,  8045,  8047,  8054,  8137,
    8137,  8139,  8146,  8155,  8155,  8157,  8164,  8173,  8173,  8175,
    8184,  8200,  8200,  8202,  8209,  8218,  8218,  8220,  8227,  8236,
    8236,  8238,  8245,  8254,  8254,  8256,  8263,  8272,  8272,  8274,
    8281,  8290,  8290,  8294,  8302,  8311,  8311,  8313,  8320,  8329,
    8329,  8331,  8338,  8489,  8490,  8491,  8492,  8493,  8494,  8495,
    8496,  8497,  8498,  8499,  8500,  8501,  8502,  8503,  8504,  8505,
    8506,  8507,  8508,  8509,  8510,  8511,  8512,  8514,  8515,  8516,
    8520,  8520,  8523,  8524,  8526,  8526,  8529,  8530,  8534,  8534,
    8539,  8539,  8544,  8544,  8549,  8549,  8554,  8554,  8559,  8559,
    8564,  8564,  8569,  8569,  8574,  8574,  8579,  8579,  8584,  8584,
    8589,  8589,  8594,  8596,  8602,  8609,  8609,  8615,  8615,  8627,
    8627,  8632,  8632,  8637,  8637,  8647,  8654,  8660,  8661,  8663,
    8664,  8667,  8671,  8675,  8679,  8678,  8699,  8698,  8705,  8706,
    8708,  8707,  8714,  8715,  8718,  8724,  8732,  8739,  8761,  8761,
    8772,  8772,  8775,  8775,  8789,  8790,  8793,  8793,  8806,  8807,
    8810,  8810,  8823,  8824,  8827,  8827,  8837,  8838,  8844,  8845,
    8846,  8847,  8848,  8849,  8850,  8851,  8852,  8853,  8854,  8855,
    8856,  8857,  8858,  8859,  8860,  8861,  8862,  8865,  8876,  8884,
    8884,  8887,  8888,  8891,  8892,  8894,  8906,  8920,  8925,  8932,
    8933,  8935,  8942,  8947,  8954,  8955,  8957,  8964,  8969,  8976,
    8977,  8979,  8986,  8988,  8994,  8996,  8998,  9004,  9006,  9008,
    9014,  9016,  9018,  9024,  9026,  9028,  9034,  9034,  9039,  9041,
    9043,  9049,  9049,  9054,  9056,  9067,  9069,  9074,  9074,  9076,
    9078,  9084,  9087,  9089,  9095,  9098,  9100,  9106,  9109,  9111,
    9117,  9121,  9120,  9132,  9132,  9139,  9141,  9147,  9149,  9151,
    9157,  9160,  9162,  9168,  9285,  9285,  9289,  9290,  9291,  9292,
    9293,  9294,  9295,  9296,  9297,  9301,  9305,  9314,  9315,  9317,
    9324,  9324,  9327,  9328,  9332,  9334,  9340,  9343,  9345,  9351,
    9354,  9354,  9364,  9365,  9371,  9373,  9379,  9382,  9384,  9390,
    9393,  9395,  9401,  9404,  9406,  9412,  9415,  9417,  9423
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
  "otherMatrixProgrammingOption", "otherMatrixProgrammingStart",
  "emptyOtherMatrixProgrammingEnd", "otherMatrixProgrammingEnd",
  "solverOptions", "solverOptionsStart", "numberOfSolverOptionsATT",
  "solverOptionsContent", "solverOptionsEmpty", "solverOptionsLaden",
  "solverOptionArray", "solverOption", "solverOptionStart",
  "emptySolverOptionEnd", "solverOptionEnd", "PathList", "Path",
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
  "osglSolverOptionOrResultAttributes", "osglSolverOptionOrResultAttList",
  "osglSolverOptionOrResultATT", "osglSolverOptionOrResultBody",
  "osglSolverOptionOrResultMatrixArray", "osglSolverOptionOrResultMatrix",
  "osglSolverOptionOrResultItemArray", "osglSolverOptionOrResultItem",
  "osglSolverOptionOrResultItemContent",
  "osglSolverOptionOrResultItemEmpty", "osglSolverOptionOrResultItemLaden",
  "osglSolverOptionOrResultItemBody", "osglMatrix",
  "osglMatrixWithMatrixVarIdx", "matrixStart", "matrixAttributes",
  "matrixAttributeList", "matrixAttribute", "matrixVarStart",
  "matrixWithMatrixVarIdxAttributes", "matrixWithMatrixVarIdxATTList",
  "matrixWithMatrixVarIdxATT", "matrixContent", "matrixEmpty",
  "matrixLaden", "matrixVarContent", "matrixVarEmpty", "matrixVarLaden",
  "matrixOrBlockBody", "baseMatrix", "baseMatrixStart",
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
    1020,  1021,  1022,  1023,  1023,  1024,  1024,  1025,  1026,  1026,
    1027,  1028,  1028,  1029,  1030,  1031,  1031,  1032,  1033,  1034,
    1034,  1035,  1035,  1036,  1037,  1037,  1038,  1039,  1039,  1040,
    1041,  1042,  1043,  1044,  1044,  1045,  1045,  1045,  1046,  1047,
    1048,  1049,  1049,  1050,  1051,  1052,  1053,  1053,  1054,  1055,
    1056,  1057,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1064,  1065,  1066,  1067,  1068,  1068,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1082,  1083,  1084,  1085,  1086,  1086,  1087,  1087,  1087,  1088,
    1088,  1089,  1090,  1091,  1092,  1092,  1093,  1094,  1094,  1095,
    1095,  1095,  1095,  1096,  1097,  1098,  1098,  1099,  1100,  1101,
    1102,  1102,  1103,  1103,  1103,  1103,  1103,  1104,  1105,  1105,
    1106,  1106,  1107,  1108,  1109,  1109,  1110,  1110,  1111,  1112,
    1113,  1113,  1114,  1114,  1115,  1116,  1117,  1117,  1118,  1118,
    1119,  1120,  1121,  1121,  1122,  1122,  1123,  1124,  1125,  1125,
    1126,  1126,  1127,  1128,  1129,  1130,  1130,  1131,  1131,  1132,
    1133,  1134,  1134,  1135,  1135,  1136,  1137,  1137,  1138,  1138,
    1139,  1140,  1141,  1141,  1142,  1143,  1144,  1144,  1145,  1145,
    1146,  1147,  1148,  1148,  1149,  1150,  1151,  1151,  1152,  1153,
    1154,  1155,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1161,
    1162,  1163,  1164,  1165,  1166,  1167,  1167,  1168,  1169,  1170,
    1171,  1172,  1173,  1173,  1174,  1175,  1176,  1177,  1178,  1179,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1191,  1192,  1193,  1194,  1195,  1196,
    1197,  1197,  1198,  1198,  1198,  1198,  1198,  1198,  1198,  1199,
    1199,  1200,  1200,  1201,  1202,  1202,  1203,  1204,  1204,  1205,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1212,  1213,
    1213,  1213,  1213,  1213,  1214,  1215,  1216,  1216,  1217,  1217,
    1217,  1217,  1217,  1217,  1218,  1218,  1219,  1220,  1221,  1221,
    1222,  1223,  1224,  1225,  1225,  1226,  1227,  1228,  1228,  1229,
    1229,  1229,  1229,  1229,  1229,  1229,  1229,  1229,  1230,  1230,
    1231,  1231,  1232,  1232,  1232,  1232,  1232,  1232,  1232,  1232,
    1232,  1232,  1232,  1233,  1234,  1235,  1236,  1236,  1237,  1237,
    1238,  1239,  1239,  1240,  1241,  1242,  1242,  1243,  1244,  1245,
    1246,  1246,  1247,  1248,  1248,  1249,  1250,  1251,  1252,  1253,
    1254,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1261,
    1262,  1262,  1263,  1264,  1265,  1265,  1266,  1267,  1267,  1268,
    1269,  1270,  1271,  1272,  1273,  1274,  1274,  1275,  1275,  1276,
    1277,  1278,  1278,  1279,  1280,  1280,  1281,  1282,  1283,  1284,
    1284,  1285,  1286,  1287,  1288,  1288,  1289,  1289,  1290,  1290,
    1291,  1292,  1293,  1293,  1294,  1295,  1296,  1296,  1297,  1298,
    1299,  1300,  1301,  1301,  1302,  1302,  1303,  1304,  1305,  1305,
    1306,  1307,  1307,  1308,  1309,  1310,  1310,  1311,  1312,  1313,
    1313,  1314,  1315,  1316,  1317,  1318,  1319,  1319,  1320,  1320,
    1321,  1322,  1323,  1323,  1324,  1325,  1325,  1326,  1327,  1328,
    1328,  1329,  1330,  1331,  1331,  1332,  1333,  1334,  1335,  1336,
    1337,  1337,  1338,  1338,  1339,  1340,  1341,  1341,  1342,  1343,
    1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1350,  1351,
    1351,  1352,  1353,  1354,  1354,  1355,  1356,  1356,  1357,  1358,
    1359,  1359,  1360,  1361,  1362,  1362,  1363,  1363,  1363,  1364,
    1365,  1366,  1367,  1368,  1368,  1369,  1369,  1370,  1371,  1372,
    1372,  1373,  1374,  1374,  1375,  1376,  1377,  1377,  1378,  1379,
    1380,  1380,  1381,  1381,  1381,  1382,  1382,  1383,  1384,  1385,
    1386,  1386,  1387,  1387,  1388,  1389,  1390,  1390,  1391,  1392,
    1392,  1393,  1394,  1395,  1396,  1397,  1398,  1398,  1399,  1400,
    1401,  1402,  1403,  1404,  1405,  1406,  1407,  1408,  1408,  1409,
    1410,  1411,  1412,  1413,  1414,  1415,  1415,  1416,  1417,  1418,
    1419,  1419,  1420,  1421,  1422,  1423,  1423,  1424,  1424,  1424,
    1424,  1425,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,  1462,
    1462,  1463,  1464,  1465,  1465,  1466,  1467,  1468,  1468,  1469,
    1470,  1471,  1471,  1472,  1473,  1474,  1474,  1475,  1476,  1477,
    1477,  1478,  1479,  1480,  1480,  1481,  1482,  1483,  1483,  1484,
    1485,  1486,  1486,  1487,  1488,  1489,  1489,  1490,  1491,  1492,
    1492,  1493,  1494,  1495,  1495,  1496,  1497,  1498,  1498,  1499,
    1500,  1501,  1501,  1502,  1503,  1504,  1504,  1505,  1506,  1507,
    1507,  1508,  1509,  1510,  1510,  1510,  1510,  1510,  1510,  1510,
    1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,
    1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,
    1512,  1511,  1513,  1513,  1515,  1514,  1516,  1516,  1518,  1517,
    1520,  1519,  1522,  1521,  1524,  1523,  1526,  1525,  1528,  1527,
    1530,  1529,  1532,  1531,  1534,  1533,  1536,  1535,  1538,  1537,
    1540,  1539,  1541,  1542,  1543,  1545,  1544,  1547,  1546,  1549,
    1548,  1551,  1550,  1553,  1552,  1554,  1555,  1556,  1556,  1557,
    1557,  1558,  1558,  1558,  1560,  1559,  1562,  1561,  1563,  1563,
    1564,  1563,  1565,  1565,  1566,  1566,  1567,  1568,  1570,  1569,
    1571,  1571,  1573,  1572,  1574,  1574,  1576,  1575,  1577,  1577,
    1579,  1578,  1580,  1580,  1582,  1581,  1583,  1583,  1584,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1585,  1586,  1587,
    1587,  1588,  1588,  1589,  1589,  1590,  1591,  1592,  1593,  1594,
    1594,  1595,  1596,  1597,  1598,  1598,  1599,  1600,  1601,  1602,
    1602,  1603,  1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,
    1612,  1613,  1614,  1615,  1616,  1617,  1618,  1618,  1619,  1620,
    1621,  1622,  1622,  1623,  1624,  1625,  1626,  1627,  1627,  1628,
    1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,
    1639,  1641,  1640,  1642,  1642,  1643,  1644,  1645,  1646,  1647,
    1648,  1649,  1650,  1651,  1652,  1652,  1653,  1653,  1653,  1653,
    1653,  1653,  1653,  1653,  1653,  1654,  1655,  1656,  1656,  1657,
    1658,  1658,  1659,  1659,  1660,  1661,  1662,  1663,  1664,  1665,
    1667,  1666,  1668,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683
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
       0,     0,     0,     0,     2,     3,     5,     1,     1,     2,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     0,
       2,     3,     5,     1,     1,     2,     1,     1,     2,     4,
       3,     1,     1,     0,     2,     1,     1,     1,     3,     3,
       3,     2,     1,     1,     4,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     4,     1,     1,     4,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     2,     0,     2,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     3,
       3,     1,     1,     2,     1,     3,     1,     1,     0,     2,
       3,     1,     0,     1,     3,     3,     1,     1,     2,     1,
       3,     1,     0,     2,     3,     1,     0,     1,     3,     3,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     3,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     2,     0,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     0,     2,     1,     1,
       3,     0,     2,     2,     1,     1,     1,     1,     3,     1,
       0,     2,     1,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     3,     1,     4,     1,     1,     0,     2,
       1,     1,     3,     2,     0,     2,     1,     1,     1,     1,
       3,     1,     4,     1,     1,     0,     2,     1,     1,     3,
       2,     0,     2,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     3,     0,     2,     3,     1,     0,     1,     3,     4,
       1,     1,     0,     2,     1,     1,     3,     2,     0,     2,
       1,     1,     1,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     3,     4,     1,     1,     0,     2,     1,     1,
       3,     2,     0,     2,     1,     1,     1,     1,     3,     0,
       2,     2,     1,     1,     1,     1,     3,     4,     1,     1,
       0,     2,     1,     1,     3,     2,     0,     2,     1,     1,
       1,     1,     3,     1,     4,     1,     1,     0,     2,     1,
       1,     3,     2,     0,     2,     1,     1,     1,     1,     3,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     3,
       4,     1,     1,     0,     2,     1,     1,     3,     2,     0,
       2,     1,     1,     1,     1,     3,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     2,     1,     4,     1,     1,
       0,     2,     1,     1,     3,     2,     0,     2,     1,     1,
       1,     1,     3,     1,     5,     1,     0,     1,     1,     3,
       1,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     1,     2,     0,     3,     1,     2,     0,     5,
       0,     5,     0,     5,     0,     4,     0,     5,     0,     5,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     3,     1,     1,     0,     4,     0,     6,     0,
       4,     0,     4,     0,     4,     3,     1,     1,     2,     0,
       2,     1,     1,     1,     0,     4,     0,     4,     1,     2,
       0,     4,     0,     2,     1,     1,     4,     4,     0,     4,
       0,     2,     0,     4,     0,     2,     0,     4,     0,     2,
       0,     4,     0,     2,     0,     4,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     1,     1,     1,     2,     4,     3,     3,     1,     1,
       2,     4,     3,     1,     1,     2,     4,     3,     1,     1,
       2,     4,     2,     1,     2,     2,     1,     3,     2,     1,
       2,     2,     1,     2,     4,     1,     0,     1,     2,     4,
       1,     0,     1,     2,     3,     2,     1,     1,     2,     2,
       1,     3,     2,     1,     2,     2,     1,     3,     2,     1,
       3,     0,     4,     0,     2,     2,     1,     3,     2,     1,
       6,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     2,     1,
       0,     2,     1,     1,     3,     1,     3,     3,     1,     3,
       0,     5,     0,     2,     3,     1,     3,     3,     1,     2,
       3,     1,     2,     3,     1,     3,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,   954,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   147,     0,
     960,   957,   953,   955,   956,    16,    10,     3,     8,     9,
     149,   208,     0,     0,    24,    19,    21,    22,     0,   959,
      14,   210,   241,     0,     0,   153,   148,   150,   151,    65,
      84,    92,   100,   108,   116,   127,    23,    41,    49,    57,
      76,     0,    26,    27,    29,     0,    30,     0,    31,     0,
      32,    66,    33,     0,    34,     0,    35,     0,    36,     0,
      37,     0,    38,   117,    39,     0,   958,     0,   971,   970,
       0,   977,   976,     0,   983,   982,     0,   989,   988,     0,
     995,   994,   961,   962,   967,   968,   969,   963,   973,   974,
     975,   964,   979,   980,   981,   965,   985,   986,   987,   966,
     991,   992,   993,    11,   243,   408,     0,     0,   214,   209,
     211,   212,   164,   173,   182,   191,   197,   152,     0,   155,
     156,   158,   166,   159,   175,   160,   184,   161,   192,   162,
       0,    25,    28,     0,    45,    40,    42,    43,     0,    53,
      48,    50,    51,     0,    61,    56,    58,    59,     0,     0,
      67,     0,    80,    75,    77,    78,     0,    88,    83,    85,
      86,     0,    96,    91,    93,    94,     0,   104,    99,   101,
     102,     0,   112,   107,   109,   110,     0,     0,   118,   947,
       0,   128,     0,     0,     0,     0,     0,   410,    15,   412,
       0,   247,   242,   244,   245,   222,   230,   213,     0,   216,
     217,   219,     0,   220,     0,   154,   157,     0,   165,     0,
     174,     0,   183,  1483,     0,     0,   193,  1481,  1482,     0,
     198,    47,    44,     0,    55,    52,     0,    63,    60,     0,
       0,     0,    72,    64,    69,    70,    82,    79,     0,    90,
      87,     0,    98,    95,     0,   106,   103,     0,   114,   111,
       0,     0,     0,   123,   115,   120,   121,     0,     0,     0,
     132,   126,   129,   130,   972,   978,   984,   990,   996,     0,
     411,   268,   279,   287,   298,   305,   312,   319,   378,   370,
     326,   337,   359,   348,   386,   397,   246,     0,   249,   250,
     252,   269,   253,     0,   254,     0,   255,     0,   256,     0,
     257,     0,   258,     0,   259,     0,   260,     0,   262,     0,
     261,     0,   263,     0,   264,     0,   265,     0,   266,     0,
     215,   218,     0,   226,   221,   223,   224,     0,   231,     0,
     163,  1519,     0,   167,   169,   168,  1517,  1518,     0,   172,
     176,   178,   177,     0,   181,   185,   187,   186,     0,     0,
     190,     0,   202,   196,   199,   200,    46,    54,    62,    68,
      74,    71,     0,    81,    89,    97,   105,   113,   119,   125,
     122,     0,   947,   946,   949,   950,   951,   952,   948,   131,
     138,     0,   134,   135,   140,   422,   419,   409,   417,   418,
       0,     0,     0,   413,   415,   416,   414,   248,   251,     0,
     270,     0,   283,   278,   280,   281,     0,     0,   288,     0,
       0,     0,     0,     0,     0,     0,   327,     0,   338,     0,
     349,     0,   360,     0,   371,     0,   379,     0,     0,   387,
       0,   398,   228,   225,     0,     0,   235,   229,   232,   233,
     944,   945,     0,   171,     0,     0,   180,     0,   189,  1484,
     195,     0,   201,   140,     0,   204,   205,    73,   124,   923,
     133,   136,     0,   139,   424,     0,   584,   426,     0,     0,
       0,     0,   274,   267,   271,   272,   285,   282,     0,     0,
       0,   292,   286,   289,   290,     0,     0,   302,   297,   299,
     300,     0,   309,   304,   306,   307,     0,   316,   311,   313,
     314,     0,   323,   318,   320,   321,     0,     0,   331,   325,
     328,   329,     0,   342,   336,   339,   340,     0,   353,   347,
     350,   351,     0,   364,   358,   361,   362,     0,   375,   369,
     372,   373,     0,   383,   377,   380,   381,     0,     0,   391,
     385,   388,   389,     0,   402,   396,   399,   400,   227,   234,
     140,     0,   237,   238,   170,  1520,   179,   188,   194,     0,
     203,   206,     0,   146,   137,  1491,     0,  1523,     0,   141,
     144,   142,  1489,  1490,   143,  1521,  1522,   420,   586,   701,
     588,   947,     0,   425,   427,     0,     0,     0,   273,     0,
     276,   277,   284,     0,   291,     0,     0,   294,     0,     0,
     301,     0,   877,   308,     0,   315,     0,   322,     0,     0,
     881,   330,     0,   333,   335,   883,   341,     0,   344,   346,
     352,     0,   355,   357,   363,     0,   366,   368,   374,     0,
     382,     0,     0,   390,     0,     0,   393,   401,   140,     0,
     404,   405,     0,   236,   239,   207,   145,     0,     0,   703,
     818,   705,   947,     0,   587,   589,     0,   433,   430,   423,
     428,   429,  1438,  1444,  1449,   275,   918,     0,   293,   295,
     926,     0,   303,   878,   310,   317,   324,   925,   332,   334,
       0,   882,   343,   345,   354,   356,   365,   367,   376,   384,
     927,     0,   392,   394,     0,   403,   406,   240,  1492,  1524,
     820,   861,   822,   947,     0,   704,   706,     0,   595,   592,
     585,   590,   591,   947,   435,     0,   455,     0,     0,     0,
       0,   892,   880,     0,     0,     0,   884,   885,   886,   887,
       0,   407,   863,   421,     0,   947,     0,   821,   823,     0,
     712,   709,   702,   707,   708,   947,   597,     0,   617,     0,
     924,   431,   457,   477,     0,     0,     0,   436,   296,   879,
     891,     0,     0,     0,   395,   947,     0,   864,     0,   828,
     826,   819,   824,   825,   947,   714,     0,   734,     0,   922,
     593,   619,   640,     0,     0,     0,   598,   479,   499,     0,
       0,   458,     0,     0,   440,   434,   437,   438,   888,   889,
     890,     0,   869,   867,   862,   865,   866,   947,   830,   851,
     831,   919,   710,   736,   757,     0,     0,     0,   715,   642,
     662,     0,     0,   620,     0,     0,   602,   596,   599,   600,
     501,   521,     0,   485,   482,   478,   480,   481,     0,   462,
     456,   459,   460,     0,   439,   446,     0,   442,   443,   448,
     947,     0,   920,   852,   947,     0,   832,   759,   779,     0,
       0,   737,     0,     0,   719,   713,   716,   717,   594,   648,
     645,   641,   643,   644,     0,   624,   618,   621,   622,     0,
     601,   608,     0,   604,   605,   610,   523,   545,     0,     0,
     502,  1040,     0,   487,   486,     0,   461,   468,     0,   464,
     465,   470,  1447,   441,   444,     0,   447,   928,   868,   873,
     870,     0,   853,     0,   838,   835,   829,   833,   834,   711,
     765,   762,   758,   760,   761,     0,   741,   735,   738,   739,
       0,   718,   725,     0,   721,   722,   727,   665,   663,   667,
       0,   650,   649,   623,   630,     0,   626,   627,   632,  1443,
     603,   606,     0,   609,   432,     0,     0,     0,   506,   500,
     503,   504,   483,  1047,   489,   488,     0,     0,     0,  1088,
     463,   466,     0,   469,     0,   454,   445,     0,   449,   450,
     451,   452,     0,  1475,     0,  1507,     0,  1515,     0,     0,
    1089,  1090,  1098,  1095,  1473,  1474,  1097,  1092,  1094,  1505,
    1506,  1096,  1513,  1514,  1093,     0,   947,   840,   850,     0,
     782,   780,   784,     0,   767,   766,   740,   747,     0,   743,
     744,   749,  1437,   720,   723,     0,   726,     0,   666,   646,
     652,   651,   625,   628,     0,   631,     0,   616,   607,   611,
     612,   613,   614,   548,   546,   550,     0,     0,   528,   522,
     525,   526,   505,   512,     0,   508,   509,   514,  1054,   491,
     490,     0,     0,     0,  1000,  1043,  1039,  1041,  1042,     0,
     476,   467,   471,   472,   473,   474,   453,     0,     0,     0,
       0,     0,     0,   874,   871,  1091,   827,   857,   854,     0,
     921,     0,     0,     0,   841,     0,   783,   763,   769,   768,
     742,   745,     0,   748,     0,   733,   724,   728,   729,   730,
     731,     0,   682,   664,   679,   680,     0,  1487,     0,  1495,
       0,   668,   670,   669,   674,   678,   677,  1485,  1486,   671,
     676,  1493,  1494,   673,   675,   672,   654,   653,     0,   639,
     629,   898,   911,     0,     0,   633,   636,   895,   896,   897,
     637,   908,   909,   910,   634,   635,   615,     0,   549,     0,
     527,   533,     0,   530,   535,   507,   510,     0,   513,  1061,
     493,   492,     0,     0,  1000,  1050,  1046,  1048,  1049,     0,
       0,  1045,   998,   999,     0,   475,     0,     0,  1476,  1508,
    1516,   876,  1110,     0,  1109,  1115,   875,     0,  1099,  1101,
    1100,  1104,  1106,  1107,  1108,  1103,  1117,     0,   837,   836,
       0,   847,   844,   839,   842,   843,     0,   799,   781,   796,
     797,  1479,     0,   785,   786,   787,   791,   793,  1477,  1478,
     795,   794,   788,   790,   792,   789,   771,   770,     0,   756,
     746,   903,   916,   947,   947,   750,   753,   900,   901,   902,
     754,   913,   914,   915,   751,   752,   732,   932,   689,   681,
       0,   684,   686,   691,   685,   929,   934,     0,     0,     0,
     656,   655,   638,   947,   947,     0,   565,   547,   562,   563,
    1531,     0,   551,   553,   552,   557,   561,   560,   554,   556,
     558,   555,   559,  1529,  1530,   524,   529,   531,     0,   534,
       0,   520,   511,   515,   516,   517,   518,  1068,   495,   494,
       0,     0,  1000,  1057,  1053,  1055,  1056,  1052,     0,  1439,
       0,     0,  1003,  1001,  1005,  1044,  1458,  1441,  1112,     0,
     872,  1102,  1105,     0,  1116,     0,   858,   855,     0,     0,
     806,   798,     0,   801,   803,   808,   802,     0,   773,   772,
     755,     0,     0,   683,   687,     0,   690,   930,     0,   933,
       0,  1488,  1496,   658,   657,   899,   912,   572,   564,     0,
     567,   569,   574,   568,     0,     0,   543,   532,   540,   541,
     947,     0,   536,   539,   893,   537,   905,   906,   538,   519,
    1075,   497,   496,     0,     0,  1000,  1064,  1060,  1062,  1063,
    1059,     0,  1051,     0,     0,  1014,  1010,  1011,  1012,     0,
    1004,  1111,  1143,  1136,  1113,  1134,  1135,  1511,     0,     0,
       0,  1118,  1121,  1120,  1122,  1119,  1509,  1510,  1123,   860,
     859,     0,  1442,   846,  1124,   845,   848,   849,  1126,   800,
     804,     0,   807,  1480,   775,   774,   947,   947,     0,   700,
     688,   698,   692,   696,   697,   693,   694,   695,  1000,   941,
     931,   939,   940,   935,   936,   938,   937,  1440,   660,   659,
     566,   570,     0,   573,  1532,   542,     0,     0,     0,  1082,
     484,   498,     0,     0,  1000,  1071,  1067,  1069,  1070,  1066,
       0,  1058,     0,     0,  1013,     0,  1002,     0,     0,  1006,
    1008,  1007,  1145,     0,  1160,  1147,     0,     0,     0,   856,
       0,  1125,     0,   817,   805,   815,   809,   813,   814,   810,
     811,   812,   777,   776,   904,   917,   699,     0,   943,   647,
     661,     0,   583,   571,   581,   575,   579,   580,   576,   577,
     578,   544,   947,     0,     0,  1000,  1078,  1074,  1076,  1077,
    1073,     0,  1065,  1450,  1015,     0,     0,     0,  1137,  1142,
       0,  1146,  1512,     0,     0,  1143,  1140,  1114,  1138,  1139,
     947,  1127,  1130,  1129,  1133,  1131,  1128,  1132,   816,   764,
     778,   942,   582,   907,   894,  1000,  1085,  1081,  1083,  1084,
    1080,     0,  1072,  1009,     0,     0,  1400,  1174,  1351,  1206,
    1223,  1325,  1308,  1260,  1284,  1378,  1395,  1161,  1162,  1176,
    1165,  1208,  1168,  1225,  1169,  1262,  1170,  1286,  1166,  1310,
    1167,  1327,  1163,  1353,  1164,  1380,  1171,  1396,  1172,     0,
       0,  1159,  1144,  1471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1148,  1149,  1152,  1153,  1154,  1155,  1150,
    1151,  1157,  1156,  1469,  1470,  1436,  1445,     0,     0,  1087,
       0,  1079,  1459,  1461,     0,  1175,     0,  1207,     0,  1224,
       0,  1261,     0,  1285,     0,  1309,     0,  1326,     0,  1352,
       0,  1379,  1503,     0,     0,  1397,  1501,  1502,     0,     0,
    1401,  1158,   947,     0,     0,     0,     0,     0,     0,     0,
       0,  1141,   947,  1086,     0,  1499,     0,     0,  1177,  1178,
    1179,  1497,  1498,     0,  1209,  1210,  1211,     0,  1226,  1227,
    1228,     0,  1263,  1264,  1265,     0,  1287,  1288,  1289,     0,
    1311,  1312,  1313,     0,  1328,  1329,  1330,     0,  1354,  1355,
    1356,     0,  1381,  1382,  1383,     0,     0,     0,     0,  1399,
    1472,     0,     0,     0,     0,     0,     0,     0,     0,  1460,
    1184,  1173,  1181,     0,     0,     0,  1190,  1205,  1190,  1222,
    1190,  1259,  1190,  1283,  1190,  1307,  1190,  1324,  1190,  1350,
    1190,  1377,  1504,  1678,  1683,  1688,  1693,  1696,  1705,  1710,
    1716,  1720,  1723,  1726,  1729,  1731,  1736,  1739,  1742,  1668,
    1699,  1702,     0,  1648,  1669,  1649,     0,  1650,     0,  1651,
       0,  1652,     0,  1653,     0,  1666,     0,  1654,     0,  1655,
    1706,  1656,  1711,  1657,     0,  1658,     0,  1659,     0,  1660,
       0,  1661,     0,  1662,  1663,     0,  1664,     0,  1665,     0,
       0,  1405,     0,     0,  1451,  1462,  1463,  1452,  1453,  1454,
    1455,  1468,  1192,     0,     0,     0,  1000,  1187,  1183,  1185,
    1186,  1500,     0,  1214,     0,  1231,     0,  1268,     0,  1292,
       0,  1316,     0,  1333,     0,  1359,     0,  1386,     0,  1733,
    1398,  1394,     0,     0,     0,     0,     0,     0,     0,     0,
    1692,     0,  1695,  1578,  1570,  1572,  1576,  1580,  1582,  1628,
    1644,  1590,  1574,  1597,  1584,  1586,  1588,  1616,  1593,  1595,
    1636,  1632,  1640,  1560,  1564,  1568,  1606,  1599,  1601,  1603,
       0,  1554,  1555,  1535,  1536,  1538,  1539,  1540,  1541,  1543,
    1544,  1545,  1547,  1546,  1548,  1550,     0,  1551,  1549,  1557,
    1558,  1559,  1533,  1609,  1534,  1537,  1556,  1552,  1553,  1542,
    1698,     0,  1701,     0,     0,  1707,     0,  1712,     0,  1717,
    1715,     0,  1719,     0,  1722,     0,  1725,     0,  1728,     0,
    1735,     0,  1738,     0,  1741,  1435,  1413,  1420,     0,     0,
    1406,  1180,  1199,  1182,     0,  1000,  1195,  1191,  1193,  1194,
    1189,   997,     0,  1446,  1216,  1213,     0,  1212,  1233,  1230,
       0,  1229,  1270,  1267,     0,  1266,  1294,  1291,     0,  1290,
    1318,  1315,     0,  1314,  1335,  1332,     0,  1331,  1361,  1358,
       0,  1357,  1388,  1385,     0,  1384,     0,     0,  1673,     0,
       0,  1670,  1667,  1671,  1672,     0,     0,  1679,  1677,     0,
       0,  1684,  1682,     0,     0,  1689,  1687,  1694,     0,     0,
       0,     0,     0,     0,     0,  1630,  1646,     0,     0,     0,
       0,     0,     0,  1622,     0,  1638,  1634,  1642,     0,     0,
       0,     0,     0,     0,  1700,     0,     0,  1703,     0,     0,
       0,  1718,     0,  1724,     0,     0,  1781,  1775,  1778,  1756,
    1768,  1787,     0,  1784,  1765,  1744,     0,  1745,  1746,  1760,
    1747,     0,  1748,     0,  1749,  1750,     0,  1751,     0,  1752,
       0,  1753,     0,  1754,     0,     0,  1743,     0,     0,  1414,
    1000,  1409,  1404,  1407,  1408,  1018,  1202,  1198,  1200,  1201,
    1197,     0,  1188,  1000,  1219,  1215,  1217,  1218,  1239,  1236,
    1232,  1234,  1235,  1275,  1273,  1269,  1271,  1272,  1299,  1297,
    1293,  1295,  1296,  1000,  1321,  1317,  1319,  1320,  1340,  1338,
    1334,  1336,  1337,  1366,  1364,  1360,  1362,  1363,  1032,  1391,
    1387,  1389,  1390,  1732,  1734,  1674,     0,     0,     0,  1680,
       0,  1685,     0,  1690,  1697,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1562,  1561,     0,  1566,  1565,
       0,     0,     0,     0,  1594,  1592,     0,  1607,     0,  1611,
    1612,  1605,  1610,  1613,  1714,     0,  1704,     0,  1709,  1721,
    1727,  1730,  1770,  1737,     0,  1759,     0,     0,     0,     0,
       0,     0,     0,     0,  1403,  1423,  1402,  1421,  1425,  1000,
    1417,  1412,  1415,  1416,  1411,     0,     0,  1204,  1016,  1017,
       0,  1196,  1221,     0,     0,  1238,     0,     0,  1323,     0,
       0,     0,  1393,  1031,     0,     0,  1676,  1681,  1686,  1691,
       0,     0,     0,     0,  1581,  1583,  1629,  1631,  1645,  1647,
    1591,  1575,     0,  1585,  1587,  1589,     0,  1618,     0,     0,
    1617,  1623,  1624,  1625,  1596,  1637,  1639,  1633,  1635,  1641,
    1643,  1563,  1567,     0,  1600,  1602,  1604,  1608,  1614,  1708,
    1713,  1772,     0,  1757,  1755,     0,     0,  1763,  1762,  1761,
       0,  1764,     0,  1767,     0,  1774,     0,  1777,     0,  1780,
       0,  1783,     0,  1786,     0,     0,  1424,  1419,     0,  1410,
       0,  1021,  1019,  1022,  1203,  1220,  1237,  1242,  1240,  1244,
    1278,  1274,  1276,     0,  1302,  1298,  1300,     0,  1322,  1343,
    1339,  1341,  1344,  1369,  1365,  1367,  1370,  1035,  1033,  1036,
    1392,  1675,  1579,  1571,  1573,  1577,     0,  1619,  1620,     0,
       0,  1569,     0,     0,  1758,     0,     0,     0,     0,     0,
    1779,  1782,     0,  1788,     0,  1143,  1433,  1422,  1431,  1432,
       0,     0,  1426,  1427,  1428,  1429,  1430,  1418,     0,  1029,
    1025,  1026,  1027,     0,  1023,     0,  1243,     0,  1281,  1277,
    1279,  1280,     0,  1305,  1301,  1303,  1304,     0,     0,     0,
    1037,  1598,     0,     0,     0,  1615,  1771,  1773,     0,     0,
    1766,  1769,  1776,  1785,  1740,     0,     0,     0,     0,  1028,
       0,  1020,  1252,  1250,  1241,  1248,  1249,     0,     0,  1245,
    1246,  1247,     0,     0,     0,  1527,     0,  1345,  1342,  1348,
    1347,  1346,  1525,  1526,     0,  1376,  1371,  1368,  1374,  1373,
    1372,     0,  1034,  1621,  1627,  1626,  1467,  1466,  1434,     0,
       0,  1030,     0,     0,     0,     0,  1282,  1306,     0,     0,
    1375,     0,  1456,  1457,  1024,  1251,  1255,  1253,  1256,     0,
       0,  1349,  1528,  1038,     0,     0,  1257,  1448,  1465,     0,
       0,  1254,     0,     0,  1464,  1258
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
    1328,  1411,  1500,   851,   852,   909,   979,   980,   981,  1074,
    1075,  1076,  1077,  1187,  1188,  1323,  1322,   907,   908,   976,
    1069,  1070,  1071,  1182,  1183,  1184,  1318,  1319,  1402,  1397,
    1398,  1399,   974,  1064,  1065,  1177,  1178,  1302,  1297,  1298,
    1299,  1389,  1390,  1391,  1392,  1492,  1493,  1555,  1553,  1554,
     599,   600,   673,   674,   730,   731,   732,   767,   768,   769,
     805,   847,   848,   849,   902,   903,   904,   905,   972,   973,
    1059,  1058,   802,   803,   842,   896,   897,   898,   965,   966,
     967,   968,  1054,  1055,  1165,  1160,   840,   841,   891,   892,
     893,   960,   961,  1050,  1156,  1290,  1383,  1488,  1549,   888,
     958,   959,  1047,  1048,  1141,  1133,  1134,  1135,  1280,  1281,
    1282,  1283,  1375,  1376,  1472,  1470,  1471,   670,   671,   724,
     725,   762,   763,   764,   796,   797,   798,   837,   885,   886,
     887,   953,   954,   955,   956,  1045,  1046,  1127,  1126,   834,
     835,   880,   947,   948,   949,  1038,  1039,  1040,  1041,  1122,
    1123,  1265,  1260,   878,   879,   942,   943,   944,  1033,  1034,
    1118,  1256,  1368,  1464,  1542,  1599,   939,  1031,  1032,  1115,
    1116,  1243,  1238,  1239,  1240,  1362,  1363,  1364,  1365,  1461,
    1462,  1536,  1534,  1535,   721,   722,   756,   757,   791,   792,
     793,   829,   830,   875,   936,   937,   938,  1229,  1028,  1029,
    1113,  1233,  1234,  1235,  1455,  1359,  1456,  1111,   873,   932,
    1025,  1108,  1109,  1357,  1450,   753,   754,   786,   824,   825,
     826,   871,   930,   931,  1104,  1216,   621,   622,   634,   635,
     700,   701,   746,   747,   748,   749,   742,  1403,  1404,  1166,
    1167,  1168,  1169,  1266,  1267,  1268,  1269,  1405,  1406,  1407,
    1170,  1171,  1172,  1173,  1270,  1271,  1272,  1273,   428,   726,
     758,   876,   675,   201,   604,   436,   430,   449,   787,  1284,
    1285,  1286,  1378,  1379,  1483,  1480,  1481,  1482,  1547,   463,
     277,   278,   398,    10,    11,    22,    23,    24,    38,    39,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,  2010,  2011,  1202,  1343,  1344,  1429,  1430,  1519,  1516,
    1203,  1426,  1427,  1428,  2277,  2278,  2372,  2373,  2443,  2481,
    2279,  2440,  2441,  2442,  2292,  2293,  2398,  2399,  2459,  2512,
     914,   915,  1086,  1087,  1088,  1204,   985,   986,  1196,  1197,
    1198,  1338,  1080,  1081,  1334,  1335,  1336,  1421,  1191,  1192,
    1417,  1418,  1419,  1510,  1329,  1330,  1506,  1507,  1508,  1571,
    1412,  1413,  1567,  1568,  1569,  1611,  1501,  1502,  1607,  1608,
    1609,  1680,   988,  1009,  1010,  1011,  1217,  1218,  1219,  1220,
    1221,  1222,  1223,  1224,  1349,  1225,  1457,  1226,  1353,  1354,
    1441,  1458,  1530,  1531,  1591,  1434,  1435,  1436,  1587,  1588,
    1589,  1523,  1524,  1525,  1580,  1581,  1663,  1652,  1579,  1627,
    1628,  1629,  1684,  1685,  1728,  1781,  1873,  1782,  1783,  1878,
    1879,  1880,  2012,  1874,  1875,  2007,  2008,  2009,  2151,  2003,
    2004,  2147,  2148,  2149,  2280,  1630,  1631,  1686,  1687,  1734,
    1787,  1884,  2015,  2016,  2155,  2156,  2157,  2283,  1632,  1633,
    1688,  1689,  1738,  1789,  1886,  2019,  2020,  2160,  2161,  2162,
    2284,  2285,  2378,  2379,  2445,  2446,  2489,  2484,  2485,  2486,
    2523,  2537,  2538,  2545,  2551,  1634,  1635,  1690,  1691,  1742,
    1791,  1888,  2023,  2024,  2165,  2166,  2167,  2286,  2382,  2383,
    2449,  2450,  2451,  1636,  1637,  1692,  1693,  1746,  1793,  1890,
    2027,  2028,  2170,  2171,  2172,  2287,  2386,  2387,  2454,  2455,
    2456,  1638,  1639,  1694,  1695,  1750,  1795,  1892,  2031,  2032,
    2175,  2176,  2177,  2289,  1640,  1641,  1696,  1697,  1754,  1797,
    1894,  2035,  2036,  2180,  2181,  2182,  2290,  2391,  2392,  2457,
    2497,  2498,  1642,  1643,  1698,  1699,  1758,  1799,  1896,  2039,
    2040,  2185,  2186,  2187,  2291,  2395,  2396,  2458,  2506,  2507,
    1644,  1645,  1700,  1701,  1762,  1801,  1898,  2043,  2044,  2190,
    2191,  2192,  2294,  1646,  1647,  1704,  1901,  1648,  1649,  1709,
    1769,  2266,  1862,  1863,  1999,  2142,  2143,  2144,  2275,  1997,
    1998,  2138,  2271,  2272,  2273,  2368,  2137,  2267,  2268,  2365,
    2366,  2432,  2427,  2428,  2429,  1710,  1442,   838,   414,   989,
    1142,  1012,  1114,   806,   415,  1443,  1729,   777,  2490,   416,
    1341,  1664,  1665,  1666,  1667,  1668,  2433,  2434,   999,  1520,
    1594,  1521,  1669,  1670,  2546,  2491,  2347,  2348,  1671,  1672,
    1673,  1674,  1013,  1014,  1015,  1247,  1248,  1249,  1016,   237,
     238,  1146,  1147,  1148,  1017,   592,   593,  1150,  1151,  1152,
    1730,  1731,  1732,  1705,  1706,  1707,  1018,  1019,  1020,  1445,
    1446,  1447,  1021,  1022,  1023,   355,   356,   357,  1024,   595,
     596,  2501,  2502,  2503,  1312,  1313,  1314,  2115,  1941,  2088,
    2226,  1942,  2089,  2229,  1943,  2090,  1944,  2070,  1945,  2071,
    1946,  2078,  1947,  2072,  1948,  2069,  1949,  2073,  1950,  2074,
    1951,  2080,  1952,  2081,  1953,  2082,  1954,  2077,  1955,  1956,
    2235,  1957,  2084,  1958,  2079,  1959,  2091,  1960,  2092,  1961,
    2093,  1962,  1963,  2241,  2096,  2242,  2243,  2412,  1964,  2083,
    2320,  2462,  2219,  2321,  2322,  2323,  1965,  2075,  2211,  1966,
    2086,  2222,  1967,  2085,  2221,  1968,  2087,  2223,  1969,  2076,
    2212,  1822,  1823,  1824,  1902,  2051,  2052,  2053,  2054,  1825,
    1826,  2058,  1904,  1827,  1828,  2062,  1906,  1829,  1830,  2066,
    1908,  1831,  1832,  1910,  1833,  1834,  1912,  1835,  1836,  1970,
    1837,  1838,  1972,  1839,  1840,  1974,  2246,  1841,  1842,  1976,
    2248,  1975,  1843,  1844,  1980,  1845,  1846,  1982,  1847,  1848,
    1984,  1849,  1850,  1986,  1851,  1852,  1988,  1853,  1899,  2046,
    1854,  1855,  1990,  1856,  1857,  1992,  1858,  1859,  1994,  2116,
    2117,  2118,  2119,  2344,  2254,  2255,  2349,  2120,  2121,  2351,
    2122,  2123,  2353,  2124,  2341,  2413,  2125,  2126,  2355,  2127,
    2128,  2357,  2129,  2130,  2359,  2131,  2132,  2361,  2133,  2134,
    2363
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2288
static const yytype_int16 yypact[] =
{
     548, -2288, -2288,   183,    90,   165, -2288, -2288,   174,    -4,
   -2288,   556, -2288,   558, -2288, -2288, -2288, -2288,    -9,   563,
   -2288, -2288, -2288, -2288, -2288,    90, -2288, -2288, -2288, -2288,
   -2288,    56,   626,    -1, -2288, -2288, -2288, -2288,   230,   921,
     174, -2288,    82,   688,     1, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,    81,     0, -2288, -2288,   690, -2288,   693, -2288,   696,
   -2288,   392, -2288,   698, -2288,   700, -2288,   703, -2288,   813,
   -2288,   815, -2288,   413, -2288,   416, -2288,   470, -2288, -2288,
     476, -2288, -2288,   482, -2288, -2288,   491, -2288, -2288,   502,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288,   185,   819,   -31, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,   197,   264,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,   657, -2288,
     416, -2288, -2288,    21, -2288, -2288, -2288, -2288,    16, -2288,
   -2288, -2288, -2288,    18, -2288, -2288, -2288, -2288,   528,   823,
   -2288,    14, -2288, -2288, -2288, -2288,   156, -2288, -2288, -2288,
   -2288,   153, -2288, -2288, -2288, -2288,   323, -2288, -2288, -2288,
   -2288,   266, -2288, -2288, -2288, -2288,   530,   827, -2288, -2288,
     829, -2288,   412,   410,   408,   418,   404, -2288, -2288, -2288,
     149, -2288, -2288, -2288, -2288, -2288, -2288, -2288,   237,    49,
   -2288, -2288,   851, -2288,   416, -2288, -2288,   561,   279,   565,
     279,   567,   279, -2288,   581,   575, -2288, -2288, -2288,   854,
   -2288, -2288, -2288,   242, -2288, -2288,   244, -2288, -2288,   240,
     586,   155, -2288, -2288, -2288, -2288, -2288, -2288,   257, -2288,
   -2288,   562, -2288, -2288,   564, -2288, -2288,   566, -2288, -2288,
     568,   622,   139, -2288, -2288, -2288, -2288,   627,    24,   -69,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,   856,
     255, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288,   314,   452, -2288,
   -2288,   682, -2288,   860, -2288,   612, -2288,   613, -2288,   613,
   -2288,   613, -2288,   613, -2288,   634, -2288,   634, -2288,   634,
   -2288,   634, -2288,   613, -2288,   613, -2288,   635, -2288,   416,
   -2288, -2288,   128, -2288, -2288, -2288, -2288,   864, -2288,   874,
   -2288, -2288,   669, -2288, -2288, -2288, -2288, -2288,   874, -2288,
   -2288, -2288, -2288,   874, -2288, -2288, -2288, -2288,   666,   719,
   -2288,   -65, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288,   678, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,   681, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,   616,   396, -2288, -2288,   434, -2288, -2288, -2288, -2288,
     743,   747,   790, -2288, -2288, -2288, -2288, -2288, -2288,   866,
   -2288,   115, -2288, -2288, -2288, -2288,   792,   884, -2288,   794,
     962,   972,   974,   977,   796,   979, -2288,   981, -2288,   983,
   -2288,   985, -2288,   987, -2288,   989, -2288,   798,   997, -2288,
    1004, -2288, -2288, -2288,   739,   -63, -2288, -2288, -2288, -2288,
   -2288, -2288,   781, -2288,   885,   835, -2288,   837, -2288, -2288,
   -2288,   838, -2288, -2288,   778,   396, -2288, -2288, -2288, -2288,
   -2288, -2288,  1022,   340, -2288,   583,   596,   879,   911,   913,
     933,   114, -2288, -2288, -2288, -2288, -2288, -2288,   868,   937,
     -47, -2288, -2288, -2288, -2288,   939,   432, -2288, -2288, -2288,
   -2288,   386, -2288, -2288, -2288, -2288,   345, -2288, -2288, -2288,
   -2288,   325, -2288, -2288, -2288, -2288,   941,   293, -2288, -2288,
   -2288, -2288,   278, -2288, -2288, -2288, -2288,    66, -2288, -2288,
   -2288, -2288,    80, -2288, -2288, -2288, -2288,   296, -2288, -2288,
   -2288, -2288,   360, -2288, -2288, -2288, -2288,   943,   942, -2288,
   -2288, -2288, -2288,   -59, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,   820,   396, -2288, -2288, -2288, -2288, -2288, -2288,  1022,
   -2288, -2288,   599, -2288, -2288, -2288,   952, -2288,   954, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,   649,
     965, -2288,  1034, -2288, -2288,   968,   971,  1032, -2288,   982,
   -2288, -2288, -2288,  1056, -2288,  1001,   -45, -2288,  1064,  1068,
   -2288,   447, -2288, -2288,   388, -2288,   371, -2288,   326,  1067,
   -2288, -2288,   321, -2288, -2288, -2288, -2288,   284, -2288, -2288,
   -2288,    85, -2288, -2288, -2288,   283, -2288, -2288, -2288,   343,
   -2288,   370,  1073, -2288,  1072,   946, -2288, -2288, -2288,   956,
     396, -2288,  1022, -2288, -2288, -2288, -2288,  1077,  1081, -2288,
     800,  1053, -2288,  1038, -2288, -2288,  1091,   995, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1097, -2288, -2288,
   -2288,  1099, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
    1040,   529, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,  1101, -2288, -2288,  1022, -2288, -2288, -2288, -2288, -2288,
   -2288,  1006,  1070, -2288,  1157, -2288, -2288,  1105,   991, -2288,
   -2288, -2288, -2288, -2288, -2288,   814,  1030,   917,   786,  1069,
    1065, -2288, -2288,  1147,  1151,  1153, -2288, -2288, -2288, -2288,
    1045, -2288, -2288, -2288,  1115, -2288,  1159, -2288, -2288,  1154,
    1042, -2288, -2288, -2288, -2288, -2288, -2288,   848,  1048,   970,
   -2288, -2288, -2288,  1082,   917,  1186,  1162, -2288, -2288, -2288,
   -2288,  1188,  1190,  1194, -2288, -2288,  1164, -2288,  1200,   907,
   -2288, -2288, -2288, -2288, -2288, -2288,   896,  1088,   993, -2288,
   -2288, -2288,  1106,   970,  1208,  1166, -2288, -2288,  1108,  1168,
    1170, -2288,  1214,   -66, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,  1216, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
    1184, -2288, -2288, -2288,  1118,   993,  1224,  1172, -2288, -2288,
   -2288,  1174,  1176, -2288,  1222,   -71, -2288, -2288, -2288, -2288,
   -2288,  1122,   917,   899, -2288, -2288, -2288, -2288,   -32, -2288,
   -2288, -2288, -2288,  1237, -2288, -2288,  1142,   932, -2288, -2288,
   -2288,  1198, -2288, -2288, -2288,  1316, -2288, -2288, -2288,  1318,
    1322, -2288,  1245,   -33, -2288, -2288, -2288, -2288,   900,   899,
   -2288, -2288, -2288, -2288,   -42, -2288, -2288, -2288, -2288,  1247,
   -2288, -2288,  1140,   948, -2288, -2288, -2288, -2288,  1218,  1324,
   -2288, -2288,  1150,   934, -2288,  1095, -2288, -2288,  1187,   999,
   -2288, -2288, -2288, -2288, -2288,  1326,   180, -2288, -2288, -2288,
   -2288,   710, -2288,  1290,  1178, -2288, -2288, -2288, -2288,   945,
     899, -2288, -2288, -2288, -2288,    -7, -2288, -2288, -2288, -2288,
    1292, -2288, -2288,  1183,  1003, -2288, -2288, -2288, -2288, -2288,
    1197,   934, -2288, -2288, -2288,  1189,  1005, -2288, -2288, -2288,
   -2288, -2288,  1328,   180,   957,  1306,  1330,   -67, -2288, -2288,
   -2288, -2288, -2288, -2288,   996, -2288,  1095,  1312,  1332, -2288,
   -2288, -2288,  1334,   180,  1043, -2288, -2288,  1453, -2288, -2288,
   -2288, -2288,  1454, -2288,  1460, -2288,  1461, -2288,  1462,  1336,
     710, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288,  -135, -2288, -2288, -2288,  1238,
   -2288, -2288, -2288,  1357,   934, -2288, -2288, -2288,  1345,  1160,
   -2288, -2288, -2288, -2288, -2288,  1338,   180,  1340,   846, -2288,
     996, -2288, -2288, -2288,  1342,   107,  1156, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288,  1465,  1242, -2288, -2288,
   -2288, -2288, -2288, -2288,  1361,  1158, -2288, -2288, -2288,  1143,
   -2288,  1095,  1346,  1467,  1308, -2288, -2288, -2288, -2288,  1161,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1471,  1472,  1473,
    1474,  1475,    38, -2288, -2288, -2288, -2288, -2288, -2288,   710,
   -2288,  1182,  1476,  1348, -2288,  1352,   788, -2288,   996, -2288,
   -2288, -2288,  1354,   131,  1175, -2288, -2288, -2288, -2288, -2288,
   -2288,   -77, -2288, -2288, -2288, -2288,  1478, -2288,  1484, -2288,
    1485, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288,  1143, -2288,  1177, -2288,
   -2288, -2288, -2288,  1486,  1487, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1356,   639,  1488,
   -2288, -2288,  1256, -2288, -2288, -2288, -2288,  1360,   180, -2288,
    1155, -2288,  1095,  1362,  1308, -2288, -2288, -2288, -2288,  1489,
    1244, -2288,  1333, -2288,  1163, -2288,  1490,  1491, -2288, -2288,
   -2288, -2288, -2288,  1495, -2288, -2288, -2288,  1373,  1250, -2288,
     389, -2288, -2288, -2288, -2288, -2288, -2288,  1364, -2288, -2288,
    1498, -2288, -2288, -2288, -2288, -2288,   -20, -2288, -2288, -2288,
   -2288, -2288,  1492, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288,  1143, -2288,  1195, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
    1152,  1196, -2288, -2288,  1349, -2288, -2288,  1501,  1500,  1502,
    1155, -2288, -2288, -2288, -2288,   -25, -2288, -2288, -2288, -2288,
   -2288,  1509, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1366,    76,
    1199, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1173, -2288,
    1095,  1368,  1308, -2288, -2288, -2288, -2288, -2288,  1179, -2288,
    1507,  1370, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1350,
   -2288, -2288, -2288,  1372,   824,   -54, -2288, -2288,  1510,   -46,
   -2288, -2288,  1165,  1211, -2288, -2288,  1349,  1513,  1155, -2288,
   -2288,   874,   874, -2288, -2288,  1374,   129, -2288,  1376,   253,
    1514, -2288, -2288,  1173, -2288, -2288, -2288, -2288, -2288,  1169,
    1207, -2288, -2288,  1349,  1517,   -39, -2288, -2288, -2288, -2288,
   -2288,  1518, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,  1191, -2288,  1095,  1378,  1308, -2288, -2288, -2288, -2288,
   -2288,  1192, -2288,  1521,    41, -2288, -2288, -2288, -2288,  1519,
    1145, -2288,  1273, -2288, -2288, -2288, -2288, -2288,  1528,  1524,
    1525, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,  1181, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,  1382,   129, -2288,  1173, -2288, -2288, -2288,  1223, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1308, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1191, -2288,
   -2288, -2288,  1384,   129, -2288, -2288,   -21,  1530,   874, -2288,
   -2288, -2288,  1095,  1386,  1308, -2288, -2288, -2288, -2288, -2288,
    1206, -2288,  1531,  1371, -2288,  1535, -2288,  1534,  1536, -2288,
   -2288, -2288, -2288,  1289, -2288, -2288,  1537,  1540,  1541, -2288,
    1388,   203,  1239, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288,  1191, -2288, -2288, -2288, -2288,  1385, -2288, -2288,
   -2288,  1232, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288,  1543,  1390,  1308, -2288, -2288, -2288, -2288,
   -2288,  1212, -2288, -2288, -2288,  1393,  1547,  1549, -2288,   383,
    1392,   486, -2288,  1548,  1550,  1273, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288,  1308, -2288, -2288, -2288, -2288,
   -2288,  1215, -2288, -2288,  1551,  1552, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1220, -2288,  1351,
    1307, -2288, -2288, -2288,  1558,  1555,  1557,  1559,  1560,  1561,
    1562,  1563,  1564, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1266,  1567, -2288,
    1230, -2288, -2288, -2288,  1565,   300,  1566,   300,  1568,   300,
    1569,   300,  1570,   300,  1571,   300,  1572,   300,  1573,   300,
    1574,   300, -2288,  1575,  1576, -2288, -2288, -2288,  1578,  1577,
   -2288, -2288, -2288,  1583,  1584,  1585,  1586,  1587,  1588,  1589,
     874, -2288, -2288, -2288,  1311, -2288,  1594,  1590, -2288, -2288,
   -2288, -2288, -2288,  1311, -2288, -2288, -2288,  1311, -2288, -2288,
   -2288,  1311, -2288, -2288, -2288,  1311, -2288, -2288, -2288,  1311,
   -2288, -2288, -2288,  1311, -2288, -2288, -2288,  1311, -2288, -2288,
   -2288,  1311, -2288, -2288, -2288,  1591,   175,  1595,  1314, -2288,
   -2288,  1592,  1596,  1597,  1598,  1599,  1600,  1601,  1602, -2288,
   -2288, -2288,   163,  1396,  1603,  1606,  1315, -2288,  1315, -2288,
    1315, -2288,  1315, -2288,  1315, -2288,  1315, -2288,  1315, -2288,
    1315, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288,  1309, -2288, -2288, -2288,  1375, -2288,  1377, -2288,
    1379, -2288,   175, -2288,   175, -2288,   902, -2288,   175, -2288,
    1139, -2288,  1139, -2288,  1398, -2288,   175, -2288,   175, -2288,
     175, -2288,   175, -2288, -2288,   175, -2288,   902, -2288,   175,
    1607, -2288,  1353,  1095, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288,  1355,  1329,  1400,  1308, -2288, -2288, -2288,
   -2288, -2288,  1609,  1337,  1347,  1339,  1358,  1341,  1359,  1344,
    1343,  1363,  1365,  1367,  1369,  1380,  1381,  1383,  1387, -2288,
   -2288, -2288,    23,  1613,  1402,  1619,  1404,  1621,  1406,  1210,
   -2288,   175, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
    1201, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288,   902, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,  1193, -2288,  1628,  1624, -2288,  1625, -2288,  1205, -2288,
   -2288,   175, -2288,  1202, -2288,   175, -2288,   175, -2288,   390,
   -2288,   902, -2288,  1213, -2288, -2288, -2288, -2288,  1095,  1408,
   -2288, -2288, -2288, -2288,  1410,  1308, -2288, -2288, -2288, -2288,
   -2288, -2288,  1389, -2288, -2288, -2288,  1412, -2288, -2288, -2288,
    1414, -2288, -2288, -2288,  1416, -2288, -2288, -2288,  1418, -2288,
   -2288, -2288,  1420, -2288, -2288, -2288,  1422, -2288, -2288, -2288,
    1424, -2288, -2288, -2288,  1426, -2288,   154,  1204, -2288,  1632,
    1638, -2288, -2288, -2288, -2288,  1636,  1391, -2288, -2288,  1640,
    1394, -2288, -2288,  1642,  1395, -2288, -2288, -2288,  1229,   902,
     902,   902,   902,   902,   902, -2288, -2288,   902,   902,   902,
     902,   902,   902, -2288,   902, -2288, -2288, -2288,  1428,  1430,
     902,   175,   175,   175, -2288,  1249,     5, -2288,  1649,   175,
     175, -2288,  1225, -2288,  1226,  1227, -2288, -2288, -2288, -2288,
   -2288, -2288,  1633, -2288, -2288, -2288,  1219, -2288, -2288, -2288,
   -2288,  1639, -2288,  1647, -2288, -2288,  1651, -2288,  1654, -2288,
    1655, -2288,  1657, -2288,  1659,   902, -2288,  1185,  1434, -2288,
    1308, -2288, -2288, -2288, -2288,  1505, -2288, -2288, -2288, -2288,
   -2288,  1397, -2288,  1308, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288,  1308, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288,  1668,  1652,  1669, -2288,
    1670, -2288,  1671, -2288, -2288,   902,   902,   902,   902,  1298,
    1300,   375,   537,  1295,  1294,   902,  1291,  1293,  1288,    48,
    1284,   709,   746,   822,  1278, -2288, -2288,  1277, -2288, -2288,
     902,  1272,  1274,  1270, -2288, -2288,  1279, -2288,  1690, -2288,
   -2288, -2288, -2288, -2288, -2288,  1268, -2288,  1267, -2288, -2288,
   -2288, -2288, -2288, -2288,  1436,  1209,   902,   390,   390,   390,
     390,   390,   390,   902, -2288, -2288, -2288, -2288, -2288,  1308,
   -2288, -2288, -2288, -2288, -2288,  1437,  1244, -2288,  1542, -2288,
    1411, -2288, -2288,  1415,  1417,  1544,   -76,   -62, -2288,  1419,
     -58,   -56, -2288,  1546,  1421,  1692, -2288, -2288, -2288, -2288,
    1399,  1401,  1403,  1405, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288,   902, -2288, -2288, -2288,   871, -2288,  1700,  1702,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288,  1299, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288,  1252, -2288, -2288,  1704,  1707, -2288, -2288, -2288,
     902, -2288,   390, -2288,   390, -2288,  1257, -2288,  1260, -2288,
     390, -2288,  1253, -2288,   175,  1440,   150, -2288,  1456, -2288,
    1442, -2288, -2288,  1477, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288,  1444, -2288, -2288, -2288,  1446, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1477,
   -2288, -2288, -2288, -2288, -2288, -2288,  1331, -2288, -2288,  1712,
     874, -2288,  1714,   274, -2288,   874,   874,  1251,  1261,  1269,
   -2288, -2288,  1258, -2288,  1280,  1273, -2288, -2288, -2288, -2288,
    1721,  1722, -2288, -2288, -2288, -2288, -2288, -2288,    77, -2288,
   -2288, -2288, -2288,  1720, -2288,  1448,   127,   902, -2288, -2288,
   -2288, -2288,   223, -2288, -2288, -2288, -2288,    69,    58,  1723,
   -2288, -2288,  1335,  1724,  1727, -2288, -2288, -2288,  1728,  1729,
   -2288, -2288, -2288, -2288, -2288,  1479,  1732,  1734,  1579, -2288,
     874, -2288, -2288, -2288, -2288, -2288, -2288,  1733,  1735, -2288,
   -2288, -2288,  1581,  1593,  1738, -2288,  1742, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288,  1604, -2288, -2288, -2288, -2288, -2288,
   -2288,  1743, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1741,
    1744, -2288,  1605,    31,  1740,   874, -2288, -2288,  1610,  1745,
   -2288,  1611, -2288, -2288, -2288, -2288, -2288, -2288,  1506,  1748,
    1749, -2288, -2288, -2288,  1750,  1739, -2288, -2288, -2288,   874,
    1753, -2288,  1752,  1459, -2288, -2288
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1730, -2288,
    1736, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1701,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288,  1407,  -347,  -355, -2288, -2288,  -506, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288,  1623, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
    1301, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1545, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288,  1203, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,  1466, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288,  1167, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,  1135, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1131,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288,  1137, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288,  1134, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288,  1125, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288,  1124, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
     915, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288,   867, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
     393, -1061, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288,   603, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288,   397, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288,   886, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
     825, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
     509, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288,   839, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288,   753, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288,   431, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288,   344, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288,   579,   -89,  -156,  -397, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -1273,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -1269, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288,  -109, -2288,   210,   167, -2288, -2288, -1086,
   -1202, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  -358,
    -390, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -1941, -1080, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
    -535, -2288, -2288, -2288, -2288, -2288,  -852, -2288, -2288, -2288,
   -2288, -2288,  -949, -2288, -2288, -2288, -2288, -2288, -1078, -2288,
   -2288, -2288, -2288, -2288, -1193, -2288, -2288, -2288, -2288, -2288,
   -1283, -2288, -2288, -2288, -2288, -2288, -1316, -2288, -2288, -2288,
   -2288, -2288,  -975,   689, -2288,   787,   444, -2288,   582, -2288,
     584, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -1582, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -1122, -2288, -2288,
   -2288, -2288, -2288, -1062, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288,   270,  -809, -2288, -1369,
    -982, -2288, -2288,  -765, -2288,   271,  -841,  -762, -2288, -2288,
    -473, -2288, -2288, -2288, -2288, -2288, -2288, -2288,  -950,  -652,
   -2288, -2287, -2288, -2288, -2288, -2288,  -651,  -650, -2288, -2288,
   -2288, -2288,  -977, -2288, -2288, -2288, -2288, -2288,  -141, -2288,
   -2288,  -978, -2288, -2288,  -475, -2288, -2288, -2288, -2288, -2288,
    -764, -2288, -2288, -2288, -2288, -2288,  -965, -2288, -2288, -1522,
   -2288, -2288, -1042, -2288, -2288,  -137, -2288, -2288,  -482, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -1815, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -1819, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288,   -36, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -1921,
    -642, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288, -2288,
   -2288
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1191
static const yytype_int16 yytable[] =
{
     466,   594,   479,  1677,  1201,   468,  1154,   236,   591,  1596,
    1484,  1082,   811,  1909,  1186,  1911,  2236,  2237,   256,  1971,
     244,  1940,   247,  1060,   473,   241,   881,  1981,   614,  1983,
     688,  1985,   393,  1987,  2047,  2048,  1989,   215,   843,   864,
    1993,   240,  1991,  1093,  1072,  1513,   900,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    54,  2316,
    2317,   132,   399,   133,  2150,   134,   472,   135,   569,  2504,
    2505,  1144,   657,   665,  1254,   916,  1495,   963,  1291,  1453,
    2494,  2478,  1377,  1153,  2380,  1277,  2444,   354,   951,   361,
     910,   366,  2068,   362,  1561,   367,  1128,  1384,  2384,   216,
    1489,  1157,  2389,  1473,  2393,  1174,  1193,  1474,   570,  1051,
    1212,  1213,  2460,  1214,  1337,   348,  1036,   215,   579,   496,
     460,   461,  1400,  1401,  1161,  1162,  1163,  1164,   473,    55,
      55,   136,   452,   611,  1245,   639,  1310,  1277,  1251,  1246,
     643,  2095,  1277,   389,   630,   647,  1161,  1162,  1163,  1164,
    1366,  1253,  1261,  1262,  1263,  1264,   717,   262,   630,   380,
     259,  1106,  2102,   630,  1377,   640,  2104,  1211,  2105,  1257,
    2500,  2508,  1550,  1274,   420,  1465,  2135,   644,  1369,   216,
      12,  1543,  1119,     6,   704,   608,  1007,  1008,   497,  1537,
      14,  1377,  2535,  1538,   587,   588,  1303,   453,   390,  1215,
    1307,  1305,  1212,  1213,   381,  1214,   263,   260,   751,  1393,
    1514,   676,  2282,  1309,  2381,   662,   658,  1331,  1107,   291,
    1556,   292,     7,   293,  1557,   570,  1600,  2194,  2385,   294,
     451,   295,  2390,   296,  2394,   297,  1278,   298,  1324,   299,
     639,   300,   901,   301,   643,   302,  2479,   303,   647,   304,
    1073,   865,  1420,  1454,  2205,  2206,  2207,  2208,  2209,  2210,
    2495,  2496,  2213,  2214,  2215,  2216,  2217,  2218,  2049,  2220,
     268,   964,  2231,  2232,  2233,  2230,   952,  1279,  1073,   305,
    2245,  2247,   727,  1143,   400,   917,   585,   586,   400,  1360,
     400,  1215,  1387,  2318,   400,   217,  1073,  2319,  2345,  2346,
    1449,   775,  1037,   714,   615,  1518,   615,  1244,   585,   586,
     585,   586,  1448,   658,    30,  1517,  1518,    17,   587,   588,
    2263,    56,  2536,   269,   132,   137,   133,   265,   134,  1388,
     135,  1007,  1008,   759,  1361,  1509,  2352,  2354,  2356,  2358,
    2360,  2362,   590,   770,    57,    57,    58,    58,    59,    59,
      60,    60,   997,  2487,   962,  1414,   630,  1437,  1438,   585,
     586,   630,   630,    86,   245,   788,   257,   242,   248,   587,
     588,   630,   619,   636,   997,   799,   997,  2488,   266,   702,
     706,    41,   585,   586,  1007,  1008,   631,   648,  2430,  2431,
    2300,  2301,  2302,  2303,   136,   821,  2307,  2309,  1548,   630,
    2312,   619,   619,   151,   831,  1035,  2326,  2328,  2330,   124,
    1437,  1438,   627,   696,   698,  2333,  1304,  1439,  1440,   619,
     168,   619,   624,   987,  1570,   997,  1475,   626,   233,   234,
     625,  2418,   628,  2419,   708,  1186,   619,   872,  1503,  2422,
     196,  2350,   587,   588,  1001,  1590,   619,   619,  2364,   650,
    1872,  1000, -1190,  1803,   233,   234,   695,  1804,   649,   709,
     199,  1805,   619,   651,   619,   693,   351,   352,   693,   623,
     693,   694,   693,   410,  1803,   202,   411,   306,  1804,   412,
     927,   203,  1805,  2238,   933,  1610,   431,   204,   432,  1597,
     433,  1062,  2467,   693,  2000,   693,   205,  2406,  1061,  2050,
     444,  2408,   446,   394,   395,   396,   397,   206,   619,  1725,
    1726,  1095,  1539,   620,   207,   233,   234,  1727,  1094,   585,
     586,   225,   291,   619,   292,  1679,   293,  1564,   692,   587,
     588,   250,   294,   271,   295,  2417,   296,   438,   297,   440,
     298,   442,   299,  1558,   300,  2424,   301,   284,   302,   285,
     303,   286,   304,  1212,  1213,   288,  1214,  1408,   743,   744,
     745,     1,     2,   340,  1130,   287,  1155,    20,    21,    25,
      26,  1129,   349,  1149,    33,    34,   358,  1806,   363,  1807,
    1175,  1808,   305,  1809,   368,  1810,   369,  1811,   376,  1812,
     378,  1813,   377,  1814,   379,  1815,  2193,  1816,  1806,  1817,
    1807,  1818,  1808,  1819,  1809,  1820,  1810,  1821,  1811,   383,
    1812,  1786,  1813,   384,  1814,  1788,  1815,   385,  1816,  1790,
    1817,   386,  1818,  1792,  1819,   387,  1820,  1794,  1821,  2139,
     388,  1796,  2492,   392,  1255,  1798,  1110,    44,    45,  1800,
    1616,  1252,   417,  1913,   426,  1914,   429,  1915,  1275,  1916,
    1617,  1917,  1618,  1918,  1619,  1919,  1620,  1920,  1621,  1921,
    1622,  1922,  1623,  1923,  1624,  1924,  1625,  1925,   434,  1926,
     447,  1927,   464,  1928,   469,  1929,  1626,  1930,  2106,  1931,
    2107,  1932,  2108,  1933,  2109,  1934,  2110,  1935,  2111,  1936,
    2112,  1937,  2113,  1938,  2114,  1939,  1311,  1653,  1654,   127,
     128,   153,   154,  1308,   158,   159,  1326,   163,   164,   171,
     172,   176,   177,  1325,   181,   182,  1655,  1656,  1657,  1658,
    1659,  1660,  1661,  1662,  1883,   470,  1885,   477,  1887,  2106,
    1889,  2107,  1891,  2108,  1893,  2109,  1895,  2110,  1897,  2111,
     478,  2112,  2466,  2113,  1913,  2114,  1914,   480,  1915,   400,
    1916,   488,  1917,   484,  1918,   489,  1919,  2306,  1920,  1913,
    1921,  1914,  1922,  1915,  1923,  1916,  1924,  1917,  1925,  1918,
    1926,  1919,  1927,  1920,  1928,  1921,  1929,  1922,  1930,  1923,
    1931,  1924,  1932,  1925,  1933,  1926,  1934,  1927,  1935,  1928,
    1936,  1929,  1937,  1930,  1938,  1931,  1939,  1932,   490,  1933,
     499,  1934,   505,  1935,   526,  1936,   557,  1937,   568,  1938,
    1136,  1939,  1003,  1004,   233,   234,  1005,  1006,   585,   586,
    1007,  1008,  1137,  1138,   186,   187,   191,   192,   587,   588,
     210,   211,   233,   234,   251,   252,  1300,  1301,   272,   273,
     279,   280,   574,  2475,  2435,  2106,  1735,  2107,  1739,  2108,
    1743,  2109,  1747,  2110,  1751,  2111,  1755,  2112,  1759,  2113,
    1763,  2114,   342,   343,   775,   371,   372,   405,   406,   351,
     352,   421,   422,  1371,  1372,   455,   456,   491,   492,  1444,
     460,   461,  1002,  1003,  1004,   233,   234,  1005,  1006,   585,
     586,  1007,  1008,   575,  1477,   500,   501,  1486,   576,   587,
     588,  1476,   577,  1385,  1386,   578,  1913,  1145,  1914,   580,
    1915,   598,  1916,   597,  1917,   601,  1918,   605,  1919,   606,
    1920,  2308,  1921,  1736,  1922,  1740,  1923,  1744,  1924,  1748,
    1925,  1752,  1926,  1756,  1927,  1760,  1928,  1764,  1929,   607,
    1930,   612,  1931,   613,  1932,   618,  1933,   629,  1934,   652,
    1935,   663,  1936,   666,  1937,   667,  1938,   668,  1939,  1136,
     669,  1003,  1004,   233,   234,  1005,  1006,   585,   586,  1007,
    1008,  1137,  1138,   506,   507,  1250,   682,   587,   588,   683,
    1541,  1241,  1242,   511,   512,   516,   517,  1540,   521,   522,
     527,   528,   532,   533,   537,   538,   542,   543,   547,   548,
     552,   553,   672,   585,   586,  1007,  1008,   836,   558,   559,
    1497,  1560,   687,  1466,  1467,   563,   564,  1136,  1559,  1003,
    1004,   233,   234,  1005,  1006,   585,   586,  1007,  1008,  1137,
    1138,  1437,  1438,   582,   583,   587,   588,  1306,  1439,  1440,
     684,  1139,  1140,   653,   654,   677,   678,   712,   654,   728,
     729,   740,   741,   685,  2239,    87,  1595,    88,    89,    90,
    2274,    91,    92,    93,   686,    94,    95,    96,   804,    97,
      98,    99,   690,   100,   101,   697,  1544,  1545,  1913,   691,
    1914,   710,  1915,   711,  1916,   718,  1917,   715,  1918,   719,
    1919,   723,  1920,  2288,  1921,   720,  1922,   733,  1923,   734,
    1924,   738,  1925,   739,  1926,   750,  1927,   766,  1928,   755,
    1929,   765,  1930,  2325,  1931,  1913,  1932,  1914,  1933,  1915,
    1934,  1916,  1935,  1917,  1936,  1918,  1937,  1919,  1938,  1920,
    1939,  1921,   752,  1922,   771,  1923,   772,  1924,   778,  1925,
    1563,  1926,   775,  1927,   780,  1928,   779,  1929,   784,  1930,
     781,  1931,  2327,  1932,   782,  1933,   783,  1934,   785,  1935,
     794,  1936,   795,  1937,   800,  1938,   801,  1939,   760,   761,
     789,   790,  1603,   813,   814,   822,   823,   845,   846,   853,
     854,   858,   859,   883,   884,   889,   890,   894,   895,  2367,
     807,  1913,   804,  1914,   812,  1915,   818,  1916,   819,  1917,
    1678,  1918,   820,  1919,   828,  1920,   827,  1921,   832,  1922,
     833,  1923,   836,  1924,   839,  1925,   844,  1926,   850,  1927,
     863,  1928,   870,  1929,   874,  1930,   877,  1931,   899,  1932,
    2329,  1933,   882,  1934,   906,  1935,   911,  1936,  1485,  1937,
    1913,  1938,  1914,  1939,  1915,   922,  1916,   923,  1917,   865,
    1918,   950,  1919,   957,  1920,   969,  1921,   970,  1922,   982,
    1923,   901,  1924,   975,  1925,   987,  1926,   983,  1927,  2407,
    1928,  1913,  1929,  1914,  1930,  1915,  1931,  1916,  1932,  1917,
    1933,  1918,  1934,  1919,  1935,  1920,  1936,  1921,  1937,  1922,
    1938,  1923,  1939,  1924,   990,  1925,  1026,  1926,  1030,  1927,
    1042,  1928,  1027,  1929,  1043,  1930,  1049,  1931,  1052,  1932,
    1063,  1933,   952,  1934,  1066,  1935,   917,  1936,   964,  1937,
    1083,  1938,  1770,  1939,  2436,   928,   929,   934,   935,   940,
     941,  1078,  1779,   945,   946,   977,   978,   994,   995,  1056,
    1057,  1067,  1068,  1084,  1085,  1089,  1090,  1102,  1103,  1124,
    1125,  1131,  1132,  1158,  1159,  1180,  1181,  1194,  1195,  1231,
    1232,  1096,  1778,  1236,  1237,  1258,  1259,  1295,  1296,  1316,
    1181,  1320,  1321,  1332,  1333,  1355,  1356,  1395,  1396,  1415,
    1416,  1424,  1425,  1432,  1433,  1468,  1469,  1478,  1479,  1504,
    1505,  1517,  1518,  1532,  1533,  1551,  1552,  1565,  1566,  1585,
    1586,  1605,  1606,  1650,  1651,  1702,  1703,  1876,  1877,  1978,
    1979,  2005,  2006,  2056,  2057,  2060,  2061,  2064,  2065,  2140,
    2141,  2145,  2146,  2153,  2154,  2158,  2159,  2163,  2164,  2168,
    2169,  2173,  2174,  2178,  2179,  2183,  2184,  2188,  2189,  2224,
    2225,  2227,  2228,  2264,  2265,  2269,  2270,  2342,  2343,  2345,
    2346,  2425,  2426,  2438,  2439,  2447,  2448,  2452,  2453,  2482,
    2483,  1097,  1098,  1099,  1100,  1101,  1117,  1112,  1120,  1037,
    1176,  1179,  1185,  1199,  1189,  1073,  1200,  1206,  1207,  1205,
    1228,  1208,  1209,  1210,  1230,  1276,  1287,  1288,  1289,  1293,
    1294,  1292,  1340,  1342,  1327,  1367,  1315,  1339,  1346,  1347,
    1348,  1345,  1211,  1215,  1358,  1370,  1373,  1380,  1381,  1278,
    1382,  1277,  1394,  1422,  1410,  1423,  1431,  1409,  1452,  1459,
    1360,  1463,  1487,  1490,  1387,  1494,  1498,  1512,  1511,  1522,
    1515,  1526,  1527,  1528,  1499,  1449,  1562,  1546,  1572,  1573,
    1574,  1575,  1576,  1578,  1577,  1582,  1583,  1584,  1601,  1598,
    1602,  1604,  1612,  1614,  1613,  1615,  1675,  1681,  1676,  1682,
    1683,  1712,  1711,  1713,  1708,  1714,  1721,  1715,  1716,  1717,
    1718,  1719,  1720,  1722,  1723,  1861,  1724,  1733,  1765,  1737,
    1741,  1745,  1749,  1753,  1757,  1761,  1767,  1766,  1768,  1771,
    1772,  1773,  1774,  1775,  1776,  1777,  1780,  1784,  1785,  1802,
    1864,  1860,  1872,  1900,  1865,  1866,  1867,  1868,  1869,  1870,
    1871,  1881,  1882,  1973,  2240,  1995,  1996,  2013,  2002,  2017,
    1903,  2055,  1905,  2001,  1907,  2029,  2014,  2059,  2018,  2063,
    2022,  2098,  2021,  2026,  2067,  2099,  2100,  2101,  2103,  2025,
    2196,  2197,  2198,  2033,  2252,  2037,  2200,  2097,  2202,  2234,
    2256,  2041,  2030,  2094,  2195,  2204,  2034,  2244,  2257,  2249,
    2296,  2136,  2258,  2253,  2250,  2259,  2260,  2251,  2261,  2038,
    2262,  2045,  2042,  2276,  2295,  2152,  2304,  2297,  2298,  2299,
    2305,  2310,  2311,  2313,  2315,  2281,  2324,  2314,  2331,  2332,
    2334,  2199,  2336,  2338,  2335,  2337,  2339,  2340,  2201,  2369,
    2401,  2374,  2371,  2203,  2377,  2375,  2397,  2376,  2409,  2388,
    2410,  2400,  2415,  2411,  2414,  2416,  2421,  2420,  2463,  2423,
    2437,  2461,  2465,  2470,  1518,  2471,  2474,  2472,  2473,  2476,
    2477,  2480,  2514,  2513,  2511,  2515,  2516,  2517,  2519,  2518,
    2520,  2524,  2526,  2525,  2528,  2529,  2539,  2531,  2521,  2532,
    2550,  2555,  2533,  2542,  2527,  2544,  2547,  2548,  2549,  2553,
    2554,    40,   226,   152,   341,  2530,  2534,   699,   703,  2402,
     123,  2541,  2543,  2403,   418,   664,   581,  2404,   705,   707,
     713,  2405,   924,   689,   716,  1317,   991,  1491,  1496,   971,
    1374,  1053,  1121,  1044,  1460,  1529,  1350,  1105,  1227,  1451,
    1351,  1592,  1593,  2370,  1352,  2499,  1977,  2509,  2510,   481,
    2493,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,  2464,     0,     0,     0,     0,  2468,  2469,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2522,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2552
};

static const yytype_int16 yycheck[] =
{
     358,   483,   392,  1585,  1084,   363,  1048,   148,   483,  1531,
    1379,   986,   774,  1832,  1075,  1834,    11,    12,     4,  1838,
       4,  1836,     4,   973,   371,     4,   835,  1846,    75,  1848,
      75,  1850,     8,  1852,    11,    12,  1855,    68,   803,   105,
    1859,   150,  1857,   993,   111,     4,   117,    48,    48,    50,
      50,    52,    52,    54,    54,    56,    56,    58,    58,    11,
      12,    60,   131,    62,  2005,    64,   131,    66,   131,    11,
      12,  1048,   131,   579,  1116,   107,   115,   119,  1156,   125,
      11,     4,  1284,  1048,   160,   162,  2373,   228,   121,   230,
     852,   232,  1911,   230,   115,   232,  1046,  1290,   160,   130,
    1383,  1050,   160,  1376,   160,  1055,  1081,  1376,   455,   961,
     164,   165,  2399,   167,  1194,   224,   123,    68,   473,     4,
       6,     7,    46,    47,    17,    18,    19,    20,   475,   130,
     130,   130,     4,   491,  1116,   532,  1178,   162,  1116,  1116,
     537,  1956,   162,     4,    78,   542,    17,    18,    19,    20,
    1236,  1116,    21,    22,    23,    24,   662,     4,    78,     4,
       4,   296,  1981,    78,  1366,    99,  1985,   129,  1987,  1118,
    2457,  2458,  1488,  1123,   311,  1368,  1991,    97,  1256,   130,
      15,  1464,  1034,     0,    99,    71,   181,   182,    73,  1462,
      16,  1393,   161,  1462,   189,   190,  1178,    69,    59,   253,
    1178,  1178,   164,   165,    49,   167,    53,    51,   714,  1295,
     169,   601,  2153,  1178,   290,   570,   563,  1192,   353,    70,
    1493,    72,   132,    74,  1493,   572,  1542,  2046,   290,    80,
     339,    82,   290,    84,   290,    86,   313,    88,  1188,    90,
     637,    92,   313,    94,   641,    96,   169,    98,   645,   100,
     317,   317,  1332,   299,  2069,  2070,  2071,  2072,  2073,  2074,
     191,   192,  2077,  2078,  2079,  2080,  2081,  2082,   245,  2084,
       4,   313,  2091,  2092,  2093,  2090,   309,   354,   317,   130,
    2099,  2100,   672,  1048,   353,   317,   179,   180,   353,   309,
     353,   253,   317,   245,   353,   326,   317,   249,   240,   241,
     354,   225,   309,   658,   351,   247,   351,  1116,   179,   180,
     179,   180,  1354,   660,   323,   246,   247,   321,   189,   190,
    2135,   322,   291,    57,    60,   324,    62,     4,    64,   354,
      66,   181,   182,   723,   354,  1415,  2257,  2258,  2259,  2260,
    2261,  2262,   483,   733,   345,   345,   347,   347,   349,   349,
     351,   351,   245,   226,   889,  1330,    78,   207,   208,   179,
     180,    78,    78,   133,   348,   755,   352,   346,   350,   189,
     190,    78,    76,    95,   245,   765,   245,   250,    55,    95,
      97,   325,   179,   180,   181,   182,    93,    91,   238,   239,
    2205,  2206,  2207,  2208,   130,   785,  2211,  2212,  1478,    78,
    2215,    76,    76,   322,   794,   940,  2221,  2222,  2223,   327,
     207,   208,    87,    87,    93,  2230,  1178,   214,   215,    76,
      28,    76,   511,   170,  1504,   245,  1376,   516,   175,   176,
      85,  2352,   521,  2354,    91,  1496,    76,   827,  1413,  2360,
      27,  2256,   189,   190,   926,   242,    76,    76,  2263,    89,
     287,   926,   289,   299,   175,   176,    85,   303,   547,    89,
      44,   307,    76,   552,    76,   621,   187,   188,   624,    83,
     626,    83,   628,   218,   299,     5,   221,   328,   303,   224,
     870,     5,   307,   478,   874,  1565,   319,     5,   321,  1531,
     323,   973,  2413,   649,  1863,   651,     5,  2312,   973,   476,
     333,  2316,   335,   479,   480,   481,   482,     5,    76,   209,
     210,   993,  1462,    81,   329,   175,   176,   217,   993,   179,
     180,   324,    70,    76,    72,  1605,    74,  1502,    81,   189,
     190,     3,    80,     3,    82,  2350,    84,   327,    86,   329,
      88,   331,    90,  1493,    92,  2364,    94,   135,    96,   139,
      98,   143,   100,   164,   165,   151,   167,  1319,    29,    30,
      31,    13,    14,   326,  1046,   147,  1048,    11,    12,    11,
      12,  1046,    11,  1048,    11,    12,    11,   423,    11,   425,
    1055,   427,   130,   429,     3,   431,    11,   433,   346,   435,
     350,   437,   348,   439,     8,   441,   442,   443,   423,   445,
     425,   447,   427,   449,   429,   451,   431,   453,   433,   352,
     435,  1733,   437,    51,   439,  1737,   441,    53,   443,  1741,
     445,    55,   447,  1745,   449,    57,   451,  1749,   453,  1998,
       8,  1753,  2447,     6,  1116,  1757,  1026,    11,    12,  1761,
     257,  1116,   328,   369,    32,   371,    33,   373,  1123,   375,
     267,   377,   269,   379,   271,   381,   273,   383,   275,   385,
     277,   387,   279,   389,   281,   391,   283,   393,    34,   395,
      35,   397,     3,   399,     8,   401,   293,   403,   455,   405,
     457,   407,   459,   409,   461,   411,   463,   413,   465,   415,
     467,   417,   469,   419,   471,   421,  1178,   211,   212,    11,
      12,    11,    12,  1178,    11,    12,  1188,    11,    12,    11,
      12,    11,    12,  1188,    11,    12,   230,   231,   232,   233,
     234,   235,   236,   237,  1786,     6,  1788,    49,  1790,   455,
    1792,   457,  1794,   459,  1796,   461,  1798,   463,  1800,   465,
      59,   467,   468,   469,   369,   471,   371,   131,   373,   353,
     375,     8,   377,   319,   379,     8,   381,   382,   383,   369,
     385,   371,   387,   373,   389,   375,   391,   377,   393,   379,
     395,   381,   397,   383,   399,   385,   401,   387,   403,   389,
     405,   391,   407,   393,   409,   395,   411,   397,   413,   399,
     415,   401,   417,   403,   419,   405,   421,   407,     8,   409,
       8,   411,     8,   413,     8,   415,     8,   417,    69,   419,
     171,   421,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,    11,    12,    11,    12,   189,   190,
      11,    12,   175,   176,    11,    12,   197,   198,    11,    12,
      11,    12,    61,  2425,  2366,   455,  1687,   457,  1689,   459,
    1691,   461,  1693,   463,  1695,   465,  1697,   467,  1699,   469,
    1701,   471,    11,    12,   225,    11,    12,    11,    12,   187,
     188,    11,    12,  1263,  1264,    11,    12,    11,    12,  1354,
       6,     7,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,     8,  1376,    11,    12,  1379,    63,   189,
     190,  1376,    65,  1293,  1294,    67,   369,  1048,   371,   131,
     373,   315,   375,   330,   377,    36,   379,     6,   381,     6,
     383,   384,   385,  1687,   387,  1689,   389,  1691,   391,  1693,
     393,  1695,   395,  1697,   397,  1699,   399,  1701,   401,     6,
     403,    73,   405,     6,   407,     6,   409,     6,   411,     6,
     413,   131,   415,   354,   417,     3,   419,     3,   421,   171,
     311,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,    11,    12,  1116,     8,   189,   190,     8,
    1462,   193,   194,    11,    12,    11,    12,  1462,    11,    12,
      11,    12,    11,    12,    11,    12,    11,    12,    11,    12,
      11,    12,    37,   179,   180,   181,   182,   219,    11,    12,
    1400,  1493,    11,  1371,  1372,    11,    12,   171,  1493,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   207,   208,    11,    12,   189,   190,  1178,   214,   215,
       8,   195,   196,   101,   102,    11,    12,   101,   102,    11,
      12,    11,    12,    71,  2096,   134,  1531,   136,   137,   138,
    2140,   140,   141,   142,     8,   144,   145,   146,   222,   148,
     149,   150,     8,   152,   153,     8,  1466,  1467,   369,    11,
     371,     8,   373,    11,   375,     8,   377,   131,   379,     8,
     381,    38,   383,  2173,   385,   295,   387,     6,   389,   104,
     391,     4,   393,     4,   395,     4,   397,   116,   399,    39,
     401,     6,   403,   404,   405,   369,   407,   371,   409,   373,
     411,   375,   413,   377,   415,   379,   417,   381,   419,   383,
     421,   385,   126,   387,   320,   389,   106,   391,   352,   393,
    1498,   395,   225,   397,    79,   399,    77,   401,   103,   403,
       3,   405,   406,   407,     3,   409,     3,   411,    43,   413,
       6,   415,   120,   417,   316,   419,   118,   421,    11,    12,
      11,    12,  1562,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,  2269,
     108,   369,   222,   371,     8,   373,     8,   375,     8,   377,
    1590,   379,     8,   381,   297,   383,     6,   385,   312,   387,
     122,   389,   219,   391,   108,   393,     8,   395,   110,   397,
       6,   399,     6,   401,    40,   403,   108,   405,     6,   407,
     408,   409,     8,   411,   112,   413,   337,   415,  1379,   417,
     369,   419,   371,   421,   373,     8,   375,   105,   377,   317,
     379,     6,   381,   353,   383,     8,   385,   117,   387,   109,
     389,   313,   391,    45,   393,   170,   395,   333,   397,   398,
     399,   369,   401,   371,   403,   373,   405,   375,   407,   377,
     409,   379,   411,   381,   413,   383,   415,   385,   417,   387,
     419,   389,   421,   391,   107,   393,     6,   395,   353,   397,
       8,   399,   124,   401,   121,   403,   109,   405,   119,   407,
     353,   409,   309,   411,     8,   413,   317,   415,   313,   417,
       8,   419,  1712,   421,  2366,   127,   128,    11,    12,    11,
      12,   335,  1722,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,   113,   114,    11,    12,    11,
      12,   318,  1720,    11,    12,    11,    12,    11,    12,   113,
     114,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,   246,   247,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,   185,   186,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,    11,    12,   258,   259,    11,    12,    11,    12,   240,
     241,    11,    12,    11,    12,    11,    12,    11,    12,    11,
      12,     8,     8,     3,     3,     3,   109,   229,   123,   309,
     314,     6,   111,     6,   331,   317,   168,     6,     6,   318,
     298,     8,     8,     8,     8,   310,     8,     3,     3,     3,
       3,   314,   248,   160,   339,     3,     8,     8,     8,     8,
       5,   338,   129,   253,     6,   310,   354,     6,     8,   313,
       8,   162,     3,   334,   341,     8,   166,   318,     8,   354,
     309,     8,     8,   354,   317,     8,     8,     6,   336,   256,
      11,     3,     8,     8,   343,   354,     6,   314,   332,     8,
     169,     6,     8,   254,     8,     8,     6,     6,   163,   310,
     318,     8,   340,     6,   161,     6,     8,   342,     8,     8,
       8,     3,   255,     8,   213,     8,   300,     8,     8,     8,
       8,     8,     8,     6,   344,   261,    11,    11,     3,    11,
      11,    11,    11,    11,    11,    11,     8,    11,    11,     6,
       6,     6,     6,     6,     6,     6,   285,     3,     8,     8,
       8,     6,   287,   294,     8,     8,     8,     8,     8,     8,
       8,     8,     6,   474,  2096,     8,   263,     8,   289,   272,
     245,     8,   245,   268,   245,   282,   289,     8,   289,     8,
     289,     3,   274,   289,   424,    11,    11,   432,   436,   280,
       8,     3,     6,   278,    11,   276,     6,   454,     6,   400,
      11,   270,   289,   452,   450,   426,   289,     8,    11,   434,
       8,   448,    11,   444,   438,    11,    11,   440,    11,   289,
      11,   284,   289,   168,     6,   286,   378,     8,     8,     8,
     380,   386,   388,   392,   396,   288,   402,   394,   410,   412,
     418,   300,   422,     3,   420,   416,   428,   430,   304,   262,
       8,   290,   160,   308,   160,   290,   160,   290,     8,   290,
       8,   290,     8,   414,   462,     8,   456,   460,     6,   466,
     264,   390,     8,   472,   247,   464,   446,   458,   470,     8,
       8,    11,     8,   398,    11,     8,     8,     8,     6,   260,
       6,     8,   161,     8,     6,     3,     6,     4,   169,     8,
      11,   292,     8,     8,   161,   249,     8,     8,     8,     6,
       8,    25,   139,    62,   219,   161,   161,   632,   637,   370,
      40,   161,   161,   372,   308,   572,   475,   374,   641,   645,
     655,   376,   867,   616,   660,  1182,   919,  1390,  1395,   903,
    1281,   966,  1039,   954,  1363,  1451,  1217,  1010,  1109,  1355,
    1218,  1531,  1531,  2276,  1220,  2457,  1842,  2458,  2458,   402,
    2452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,  2410,    -1,    -1,    -1,    -1,  2415,  2416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2525,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2549
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    13,    14,   484,   485,   486,     0,   132,   493,   494,
    1096,  1097,    15,   487,    16,   491,   492,   321,   495,   496,
      11,    12,  1098,  1099,  1100,    11,    12,   488,   489,   490,
     323,   581,   582,    11,    12,   497,   498,   499,  1101,  1102,
     493,   325,   624,   625,    11,    12,   583,   584,   585,    48,
      50,    52,    54,    56,    58,   130,   322,   345,   347,   349,
     351,   500,   501,   502,   503,   504,   509,   510,   515,   516,
     521,   522,   529,   530,   535,   536,   541,   542,   547,   548,
     553,   554,   559,   560,   567,   568,   133,   134,   136,   137,
     138,   140,   141,   142,   144,   145,   146,   148,   149,   150,
     152,   153,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,
    1121,  1122,  1123,   491,   327,   647,   648,    11,    12,   626,
     627,   628,    60,    62,    64,    66,   130,   324,   586,   587,
     588,   589,   590,   596,   597,   603,   604,   610,   611,   615,
     616,   322,   502,    11,    12,   505,   506,   507,    11,    12,
     511,   512,   513,    11,    12,   517,   518,   519,    28,   523,
     524,    11,    12,   531,   532,   533,    11,    12,   537,   538,
     539,    11,    12,   543,   544,   545,    11,    12,   549,   550,
     551,    11,    12,   555,   556,   557,    27,   561,   562,    44,
     569,  1076,     5,     5,     5,     5,     5,   329,   758,   759,
      11,    12,   649,   650,   651,    68,   130,   326,   629,   630,
     631,   632,   633,   638,   639,   324,   588,   591,   592,   598,
     599,   605,   606,   175,   176,   612,  1471,  1472,  1473,   617,
    1076,     4,   346,   508,     4,   348,   514,     4,   350,   520,
       3,    11,    12,   525,   526,   527,     4,   352,   534,     4,
      51,   540,     4,    53,   546,     4,    55,   552,     4,    57,
     558,     3,    11,    12,   563,   564,   565,  1093,  1094,    11,
      12,   570,   571,   572,   135,   139,   143,   147,   151,   760,
     761,    70,    72,    74,    80,    82,    84,    86,    88,    90,
      92,    94,    96,    98,   100,   130,   328,   652,   653,   654,
     655,   656,   663,   664,   669,   670,   677,   678,   682,   683,
     687,   688,   692,   693,   697,   698,   705,   706,   713,   714,
     721,   722,   729,   730,   735,   736,   741,   742,   749,   750,
     326,   631,    11,    12,   634,   635,   636,   640,  1076,    11,
     594,   187,   188,   593,  1471,  1498,  1499,  1500,    11,   601,
     600,  1471,  1498,    11,   608,   607,  1471,  1498,     3,    11,
     613,    11,    12,   618,   619,   620,   346,   348,   350,     8,
       4,    49,   528,   352,    51,    53,    55,    57,     8,     4,
      59,   566,     6,     8,   479,   480,   481,   482,  1095,   131,
     353,   573,   574,   575,   576,    11,    12,   763,   764,   765,
     218,   221,   224,   762,  1431,  1437,  1442,   328,   654,   657,
    1498,    11,    12,   665,   666,   667,    32,   671,  1071,    33,
    1079,  1079,  1079,  1079,    34,   699,  1078,   707,  1078,   715,
    1078,   723,  1078,   731,  1079,   737,  1079,    35,   743,  1080,
     751,  1076,     4,    69,   637,    11,    12,   641,   642,   643,
       6,     7,   595,  1092,     3,   602,  1092,   609,  1092,     8,
       6,   614,   131,   576,   621,   622,   623,    49,    59,  1093,
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
    1471,  1477,  1478,  1479,  1501,  1502,  1503,   330,   315,   863,
     864,    36,   769,   770,  1077,     6,     6,     6,    71,   661,
     662,  1092,    73,     6,    75,   351,   675,   676,     6,    76,
      81,  1039,  1040,    83,  1039,    85,  1039,    87,  1039,     6,
      78,    93,   703,   704,  1041,  1042,    95,   711,   712,  1041,
      99,   719,   720,  1041,    97,   727,   728,  1041,    91,  1039,
      89,  1039,     6,   101,   102,   747,   748,   131,   576,   755,
     756,   757,   577,   131,   646,   580,   354,     3,     3,   311,
     930,   931,    37,   865,   866,  1075,  1093,    11,    12,   771,
     772,   773,     8,     8,     8,    71,     8,    11,    75,   676,
       8,    11,    81,  1040,    83,    85,    87,     8,    93,   704,
    1043,  1044,    95,   712,    99,   720,    97,   728,    91,    89,
       8,    11,   101,   748,   577,   131,   757,   580,     8,     8,
     295,   997,   998,    38,   932,   933,  1072,  1093,    11,    12,
     867,   868,   869,     6,   104,   774,   775,   776,     4,     4,
      11,    12,  1049,    29,    30,    31,  1045,  1046,  1047,  1048,
       4,   580,   126,  1028,  1029,    39,   999,  1000,  1073,  1093,
      11,    12,   934,   935,   936,     6,   116,   870,   871,   872,
    1093,   320,   106,   789,   790,   225,   777,  1440,   352,    77,
      79,     3,     3,     3,   103,    43,  1030,  1081,  1093,    11,
      12,  1001,  1002,  1003,     6,   120,   937,   938,   939,  1093,
     316,   118,   885,   886,   222,   873,  1436,   108,   803,   804,
     791,  1440,     8,    11,    12,   778,   779,   780,     8,     8,
       8,  1093,    11,    12,  1031,  1032,  1033,     6,   297,  1004,
    1005,  1093,   312,   122,   952,   953,   219,   940,  1430,   108,
     899,   900,   887,  1436,     8,    11,    12,   874,   875,   876,
     110,   816,   817,    11,    12,   805,   806,   807,    11,    12,
     792,   793,   794,     6,   105,   317,   781,   782,   783,   784,
       6,  1034,  1093,  1021,    40,  1006,  1074,   108,   966,   967,
     954,  1430,     8,    11,    12,   941,   942,   943,   912,    11,
      12,   901,   902,   903,    11,    12,   888,   889,   890,     6,
     117,   313,   877,   878,   879,   880,   112,   830,   831,   818,
    1440,   337,   808,   809,  1153,  1154,   107,   317,   795,   796,
     797,   798,     8,   105,   783,   785,   786,  1093,   127,   128,
    1035,  1036,  1022,  1093,    11,    12,  1007,  1008,  1009,   979,
      11,    12,   968,   969,   970,    11,    12,   955,   956,   957,
       6,   121,   309,   944,   945,   946,   947,   353,   913,   914,
     904,   905,  1153,   119,   313,   891,   892,   893,   894,     8,
     117,   879,   881,   882,   845,    45,   832,    11,    12,   819,
     820,   821,   109,   333,   810,  1159,  1160,   170,  1195,  1432,
     107,   797,   799,   800,    11,    12,   788,   245,   787,  1451,
    1477,  1501,   172,   173,   174,   177,   178,   181,   182,  1196,
    1197,  1198,  1434,  1465,  1466,  1467,  1471,  1477,  1489,  1490,
    1491,  1495,  1496,  1497,  1501,  1023,     6,   124,  1011,  1012,
     353,   980,   981,   971,   972,  1153,   123,   309,   958,   959,
     960,   961,     8,   121,   946,   948,   949,   915,   916,   109,
     906,  1159,   119,   893,   895,   896,    11,    12,   884,   883,
    1451,  1477,  1501,   353,   846,   847,     8,    11,    12,   833,
     834,   835,   111,   317,   822,   823,   824,   825,   335,   811,
    1165,  1166,  1195,     8,    11,    12,  1155,  1156,  1157,    11,
      12,   802,   801,  1451,  1477,  1501,   318,     8,     8,     3,
       3,     3,    11,    12,  1037,  1198,   296,   353,  1024,  1025,
    1093,  1020,   229,  1013,  1435,   982,   983,   109,   973,  1159,
     123,   960,   962,   963,    11,    12,   951,   950,  1451,  1477,
    1501,    11,    12,   918,   919,   920,   171,   183,   184,   195,
     196,   917,  1433,  1436,  1465,  1471,  1474,  1475,  1476,  1477,
    1480,  1481,  1482,  1489,  1495,  1501,   907,  1165,    11,    12,
     898,    17,    18,    19,    20,   897,  1052,  1053,  1054,  1055,
    1063,  1064,  1065,  1066,  1451,  1477,   314,   848,   849,     6,
     113,   114,   836,   837,   838,   111,   824,   826,   827,   331,
     812,  1171,  1172,  1195,    11,    12,  1161,  1162,  1163,     6,
     168,  1125,  1126,  1133,  1158,   318,     6,     6,     8,     8,
       8,   129,   164,   165,   167,   253,  1038,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,  1206,  1208,  1210,  1196,   298,  1010,
       8,    11,    12,  1014,  1015,  1016,    11,    12,   985,   986,
     987,   193,   194,   984,  1430,  1433,  1465,  1468,  1469,  1470,
    1471,  1474,  1477,  1489,  1495,  1501,   974,  1165,    11,    12,
     965,    21,    22,    23,    24,   964,  1056,  1057,  1058,  1059,
    1067,  1068,  1069,  1070,  1451,  1477,   310,   162,   313,   354,
     921,   922,   923,   924,  1082,  1083,  1084,     8,     3,     3,
     908,  1171,   314,     3,     3,    11,    12,   851,   852,   853,
     197,   198,   850,  1433,  1440,  1465,  1471,  1474,  1477,  1489,
    1495,  1501,  1507,  1508,  1509,     8,   113,   837,   839,   840,
      11,    12,   829,   828,  1451,  1477,  1501,   339,   813,  1177,
    1178,  1195,    11,    12,  1167,  1168,  1169,  1125,  1164,     8,
     248,  1443,   160,  1127,  1128,   338,     8,     8,     5,  1207,
    1038,  1201,  1203,  1211,  1212,    11,    12,  1026,     6,  1018,
     309,   354,   988,   989,   990,   991,  1082,     3,   975,  1171,
     310,  1093,  1093,   354,   923,   925,   926,  1083,  1085,  1086,
       6,     8,     8,   909,  1177,  1093,  1093,   317,   354,   854,
     855,   856,   857,  1082,     3,    11,    12,   842,   843,   844,
      46,    47,   841,  1050,  1051,  1060,  1061,  1062,  1440,   318,
     341,   814,  1183,  1184,  1195,    11,    12,  1173,  1174,  1175,
    1125,  1170,   334,     8,    11,    12,  1134,  1135,  1136,  1129,
    1130,   166,    11,    12,  1218,  1219,  1220,   207,   208,   214,
     215,  1213,  1429,  1438,  1477,  1492,  1493,  1494,  1495,   354,
    1027,  1199,     8,   125,   299,  1017,  1019,  1209,  1214,   354,
     990,   992,   993,     8,   976,  1177,  1092,  1092,    11,    12,
     928,   929,   927,  1052,  1063,  1451,  1477,  1501,    11,    12,
    1088,  1089,  1090,  1087,  1432,  1471,  1501,     8,   910,  1183,
     354,   856,   858,   859,     8,   115,   823,  1093,     8,   343,
     815,  1189,  1190,  1195,    11,    12,  1179,  1180,  1181,  1125,
    1176,   336,     6,     4,   169,    11,  1132,   246,   247,  1131,
    1452,  1454,   256,  1224,  1225,  1226,     3,     8,     8,  1027,
    1215,  1216,    11,    12,   995,   996,   994,  1052,  1063,  1451,
    1477,  1501,   977,  1183,  1093,  1093,   314,  1091,  1125,   911,
    1189,    11,    12,   861,   862,   860,  1052,  1063,  1451,  1477,
    1501,   115,     6,  1092,  1195,    11,    12,  1185,  1186,  1187,
    1125,  1182,   332,     8,   169,     6,     8,     8,   254,  1231,
    1227,  1228,     8,     6,     6,    11,    12,  1221,  1222,  1223,
     242,  1217,  1429,  1438,  1453,  1477,  1492,  1495,   310,   978,
    1189,   163,   318,  1093,     8,    11,    12,  1191,  1192,  1193,
    1125,  1188,   340,   161,     6,     6,   257,   267,   269,   271,
     273,   275,   277,   279,   281,   283,   293,  1232,  1233,  1234,
    1258,  1259,  1271,  1272,  1298,  1299,  1316,  1317,  1334,  1335,
    1347,  1348,  1365,  1366,  1383,  1384,  1396,  1397,  1400,  1401,
      11,    12,  1230,   211,   212,   230,   231,   232,   233,   234,
     235,   236,   237,  1229,  1444,  1445,  1446,  1447,  1448,  1455,
    1456,  1461,  1462,  1463,  1464,     8,     8,  1224,  1093,  1125,
    1194,   342,     8,     8,  1235,  1236,  1260,  1261,  1273,  1274,
    1300,  1301,  1318,  1319,  1336,  1337,  1349,  1350,  1367,  1368,
    1385,  1386,   185,   186,  1398,  1486,  1487,  1488,   213,  1402,
    1428,   255,     3,     8,     8,     8,     8,     8,     8,     8,
       8,   300,     6,   344,    11,   209,   210,   217,  1237,  1439,
    1483,  1484,  1485,    11,  1262,  1439,  1483,    11,  1275,  1439,
    1483,    11,  1302,  1439,  1483,    11,  1320,  1439,  1483,    11,
    1338,  1439,  1483,    11,  1351,  1439,  1483,    11,  1369,  1439,
    1483,    11,  1387,  1439,  1483,     3,    11,     8,    11,  1403,
    1093,     6,     6,     6,     6,     6,     6,     6,  1092,  1093,
     285,  1238,  1240,  1241,     3,     8,  1240,  1263,  1240,  1276,
    1240,  1303,  1240,  1321,  1240,  1339,  1240,  1352,  1240,  1370,
    1240,  1388,     8,   299,   303,   307,   423,   425,   427,   429,
     431,   433,   435,   437,   439,   441,   443,   445,   447,   449,
     451,   453,  1584,  1585,  1586,  1592,  1593,  1596,  1597,  1600,
    1601,  1604,  1605,  1607,  1608,  1610,  1611,  1613,  1614,  1616,
    1617,  1620,  1621,  1625,  1626,  1628,  1629,  1631,  1632,  1634,
    1635,  1637,  1638,  1640,  1643,  1644,  1646,  1647,  1649,  1650,
       6,   261,  1405,  1406,     8,     8,     8,     8,     8,     8,
       8,     8,   287,  1239,  1246,  1247,    11,    12,  1242,  1243,
    1244,     8,     6,  1246,  1264,  1246,  1277,  1246,  1304,  1246,
    1322,  1246,  1340,  1246,  1353,  1246,  1371,  1246,  1389,  1641,
     294,  1399,  1587,   245,  1595,   245,  1599,   245,  1603,  1584,
    1606,  1584,  1609,   369,   371,   373,   375,   377,   379,   381,
     383,   385,   387,   389,   391,   393,   395,   397,   399,   401,
     403,   405,   407,   409,   411,   413,   415,   417,   419,   421,
    1510,  1511,  1514,  1517,  1519,  1521,  1523,  1525,  1527,  1529,
    1531,  1533,  1535,  1537,  1539,  1541,  1542,  1544,  1546,  1548,
    1550,  1552,  1554,  1555,  1561,  1569,  1572,  1575,  1578,  1581,
    1612,  1584,  1615,   474,  1618,  1624,  1622,  1624,    11,    12,
    1627,  1584,  1630,  1584,  1633,  1584,  1636,  1584,  1639,  1584,
    1645,  1510,  1648,  1584,  1651,     8,   263,  1412,  1413,  1407,
    1432,   268,   289,  1252,  1253,    11,    12,  1248,  1249,  1250,
    1124,  1125,  1245,     8,   289,  1265,  1266,   272,   289,  1278,
    1279,   274,   289,  1305,  1306,   280,   289,  1323,  1324,   282,
     289,  1341,  1342,   278,   289,  1354,  1355,   276,   289,  1372,
    1373,   270,   289,  1390,  1391,   284,  1642,    11,    12,   245,
     476,  1588,  1589,  1590,  1591,     8,    11,    12,  1594,     8,
      11,    12,  1598,     8,    11,    12,  1602,   424,  1584,  1528,
    1520,  1522,  1526,  1530,  1532,  1570,  1582,  1540,  1524,  1547,
    1534,  1536,  1538,  1562,  1545,  1576,  1573,  1579,  1512,  1515,
    1518,  1549,  1551,  1553,   452,  1510,  1557,   454,     3,    11,
      11,   432,  1584,   436,  1584,  1584,   455,   457,   459,   461,
     463,   465,   467,   469,   471,  1510,  1652,  1653,  1654,  1655,
    1660,  1661,  1663,  1664,  1666,  1669,  1670,  1672,  1673,  1675,
    1676,  1678,  1679,  1681,  1682,  1510,   448,  1419,  1414,  1432,
      11,    12,  1408,  1409,  1410,    11,    12,  1254,  1255,  1256,
    1124,  1251,   286,    11,    12,  1267,  1268,  1269,    11,    12,
    1280,  1281,  1282,    11,    12,  1307,  1308,  1309,    11,    12,
    1325,  1326,  1327,    11,    12,  1343,  1344,  1345,    11,    12,
    1356,  1357,  1358,    11,    12,  1374,  1375,  1376,    11,    12,
    1392,  1393,  1394,   442,  1584,   450,     8,     3,     6,   300,
       6,   304,     6,   308,   426,  1510,  1510,  1510,  1510,  1510,
    1510,  1571,  1583,  1510,  1510,  1510,  1510,  1510,  1510,  1565,
    1510,  1577,  1574,  1580,    11,    12,  1513,    11,    12,  1516,
    1510,  1584,  1584,  1584,   400,  1543,    11,    12,   478,  1495,
    1501,  1556,  1558,  1559,     8,  1584,  1619,  1584,  1623,   434,
     438,   440,    11,   444,  1657,  1658,    11,    11,    11,    11,
      11,    11,    11,  1510,   258,   259,  1404,  1420,  1421,    11,
      12,  1415,  1416,  1417,  1125,  1411,   168,  1137,  1138,  1143,
    1257,   288,  1124,  1270,  1283,  1284,  1310,  1328,  1125,  1346,
    1359,  1377,  1147,  1148,  1395,     6,     8,     8,     8,     8,
    1510,  1510,  1510,  1510,   378,   380,   382,  1510,   384,  1510,
     386,   388,  1510,   392,   394,   396,    11,    12,   245,   249,
    1563,  1566,  1567,  1568,   402,   404,  1510,   406,  1510,   408,
    1510,   410,   412,  1510,   418,   420,   422,   416,     3,   428,
     430,  1667,    11,    12,  1656,   240,   241,  1459,  1460,  1659,
    1510,  1662,  1652,  1665,  1652,  1671,  1652,  1674,  1652,  1677,
    1652,  1680,  1652,  1683,  1510,  1422,  1423,  1125,  1418,   262,
    1443,   160,  1139,  1140,   290,   290,   290,   160,  1285,  1286,
     160,   290,  1311,  1312,   160,   290,  1329,  1330,   290,   160,
     290,  1360,  1361,   160,   290,  1378,  1379,   160,  1149,  1150,
     290,     8,   370,   372,   374,   376,  1510,   398,  1510,     8,
       8,   414,  1560,  1668,   462,     8,     8,  1510,  1652,  1652,
     460,   456,  1652,   466,  1584,    11,    12,  1425,  1426,  1427,
     238,   239,  1424,  1449,  1450,  1492,  1495,   264,    11,    12,
    1144,  1145,  1146,  1141,  1454,  1287,  1288,    11,    12,  1313,
    1314,  1315,    11,    12,  1331,  1332,  1333,  1362,  1380,  1151,
    1454,   390,  1564,     6,  1092,     8,   468,  1652,  1092,  1092,
     472,   464,   458,   470,   446,  1224,     8,     8,     4,   169,
      11,  1142,    11,    12,  1290,  1291,  1292,   226,   250,  1289,
    1441,  1458,  1510,  1653,    11,   191,   192,  1363,  1364,  1452,
    1454,  1504,  1505,  1506,    11,    12,  1381,  1382,  1454,  1459,
    1460,    11,  1152,   398,     8,     8,     8,     8,   260,     6,
       6,   169,  1092,  1293,     8,     8,   161,   161,     6,     3,
     161,     4,     8,     8,   161,   161,   291,  1294,  1295,     6,
    1092,   161,     8,   161,   249,  1296,  1457,     8,     8,     8,
      11,  1297,  1092,     6,     8,   292
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

  case 854:

    {
/*
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setSolverOptionContent(
                    parserData->iOption,
                    osglData->numberOfMatrices,
                    osglData->numberOfItems,
                    osglData->name,
                    osglData->value,
                    osglData->solver,
                    osglData->category,
                    osglData->type,
                    osglData->description,
                    osglData->matrix,
                    osglData->itemList) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setSolverOptionContent failed");
*/
    if (osglData->numberOfMatrices > 0)
        delete[] osglData->matrix;
    osglData->matrix = NULL;
    if (osglData->numberOfItems > 0)
        delete[] osglData->itemList;
    osglData->itemList = NULL;
    parserData->iOption++;
}
    break;

  case 855:

    {
        if (osglData->numberOfItems > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <item> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 856:

    {
        if (parserData->kounter < osglData->numberOfItems)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <item> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 857:

    {
    osglData->namePresent = false;
    osglData->descriptionPresent = false;
    osglData->valuePresent = false;
    osglData->typePresent = false;
    osglData->solverPresent = false;
    osglData->categoryPresent = false;
    osglData->numberOfMatricesPresent = false;
    osglData->numberOfItemsPresent = false;
    osglData->description = "";
    osglData->value = "";
    osglData->type = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->numberOfMatrices = 0;
    osglData->numberOfItems = 0;
    osglData->kounter = 0;
}
    break;

  case 862:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 864:

    {
    if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfSolverOptions failed");
    parserData->iOption = 0;
}
    break;

  case 865:

    {
std::cout << "number of solver options: " << parserData->numberOfSolverOptions;
std::cout << " why is solverOptions element empty?" << std::endl; 
        if (parserData->numberOfSolverOptions > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <solverOption> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 866:

    {
std::cout << "number of solver options specified: " << parserData->numberOfSolverOptions << std::endl;
std::cout << " number seen: " << parserData->iOption  << std::endl; 
        if (parserData->iOption != parserData->numberOfSolverOptions)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <solverOption> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 870:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setSolverOptionContent(
                    parserData->iOption,
                    osglData->numberOfMatrices,
                    osglData->numberOfItems,
                    osglData->name,
                    osglData->value,
                    osglData->solver,
                    osglData->category,
                    osglData->type,
                    osglData->description,
                    osglData->matrix,
                    osglData->itemList) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setSolverOptionContent failed");
    if (osglData->numberOfMatrices > 0)
        delete[] osglData->matrix;
    osglData->matrix = NULL;
    if (osglData->numberOfItems > 0)
        delete[] osglData->itemList;
    osglData->itemList = NULL;
    parserData->iOption++;
}
    break;

  case 871:

    {
std::cout << "number of items specified: " << osglData->numberOfItems << std::endl;
std::cout << " number of items seen: " << osglData->kounter << std::endl; 
        if (osglData->numberOfItems > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <item> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 872:

    {
std::cout << "number of items specified: " << osglData->numberOfItems << std::endl;
std::cout << " number of items seen: " << osglData->kounter << std::endl; 
        if (osglData->kounter < osglData->numberOfItems)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <item> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 873:

    {
    osglData->namePresent = false;
    osglData->descriptionPresent = false;
    osglData->valuePresent = false;
    osglData->typePresent = false;
    osglData->solverPresent = false;
    osglData->categoryPresent = false;
    osglData->numberOfMatricesPresent = false;
    osglData->numberOfItemsPresent = false;
    osglData->description = "";
    osglData->value = "";
    osglData->type = "";
    osglData->solver = "";
    osglData->category = "";
    osglData->numberOfMatrices = 0;
    osglData->numberOfItems = 0;
    osglData->kounter = 0;
}
    break;

  case 879:

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

  case 880:

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

  case 881:

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

  case 882:

    {
//    parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 888:

    {
    if (parserData->pathPairFromPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"from\" attribute allowed");
    parserData->pathPairFromPresent = true;
    parserData->pathPairFrom = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 889:

    {
    if (parserData->pathPairToPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"to\" attribute allowed");
    parserData->pathPairToPresent = true;
    parserData->pathPairTo = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 890:

    {
    if (parserData->pathPairMakeCopyPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"makeCopy\" attribute allowed");
    parserData->pathPairMakeCopyPresent = true;
    parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0 || strcmp((yyvsp[(2) - (3)].sval),"1") == 0);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 893:

    {
    if (parserData->groupWeightAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one groupWeight attribute allowed for this element");
    parserData->groupWeightAttributePresent = true;
}
    break;

  case 894:

    {
    parserData->groupWeight = parserData->tempVal;
}
    break;

  case 895:

    {   
    if (parserData->lbValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
    parserData->lbValueAttributePresent = true;
}
    break;

  case 898:

    { 
    parserData->lbValueAttribute = ""; 
}
    break;

  case 899:

    { 
    parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 900:

    {   if (parserData->lbValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
            parserData->lbValueAttributePresent = true;
        }
    break;

  case 903:

    { 
    parserData->lbDualValue = 0.0; 
}
    break;

  case 904:

    {
    parserData->lbDualValue = parserData->tempVal;
}
    break;

  case 905:

    {   if (parserData->sosIdxAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one sosIdx attribute allowed for this element");
        parserData->sosIdxAttributePresent = true;
    }
    break;

  case 907:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index must be nonnegative");
    parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 908:

    {
   if (parserData->ubValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
    parserData->ubValueAttributePresent = true;
}
    break;

  case 911:

    { 
    parserData->ubValueAttribute = ""; 
}
    break;

  case 912:

    { 
    parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 913:

    {   if (parserData->ubValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
            parserData->ubValueAttributePresent = true;
        }
    break;

  case 916:

    { parserData->ubDualValue = 0.0; }
    break;

  case 917:

    { 
    parserData->ubDualValue = parserData->tempVal;
}
    break;

  case 918:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 919:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other constraint options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 920:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other matrixProgramming options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 921:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other matrixVariable options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 922:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other objective options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 923:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 924:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other variable options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 925:

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

  case 926:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of paths cannot be negative");
    else
        parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 927:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 928:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of solver options cannot be negative");
    parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 931:

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

  case 932:

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

  case 933:

    {
        if(!osglData->numberOfElPresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires numberOfEl attribute"); 
        if(!osglData->valuePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires value attribute"); 
    }
    break;

  case 936:

    {
        osglData->osglCounter = 0;
//        osglData->numberOfElPresent = true;
//        osglData->numberOfEl = parserData->numberOf;
        if (osglData->numberOfEl > 0)
            osglData->osglIntArray = new int[osglData->numberOfEl];
    }
    break;

  case 944:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 945:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 954:

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

  case 967:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 972:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 973:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 978:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 979:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 984:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 985:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 990:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 991:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 996:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 997:

    {
    for (int i=0; i<osglData->numberOfEl; i++)
        if (osglData->osglIntArray < 0)
            throw ErrorClass("negative entry detected in nonnegativeIntVector");
}
    break;

  case 998:

    {
         if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1003:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
    osglData->incr = 0;
}
    break;

  case 1009:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL IntVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->incr;    
}
    break;

  case 1015:

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

  case 1016:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1021:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}
    break;

  case 1024:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL DblVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
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

  case 1031:

    {
        if (osglData->osglCounter < osglData->numberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1035:

    {    
    osglData->multPresent = false;
    osglData->incrPresent = false;
    osglData->mult = 1;
}
    break;

  case 1038:

    {
    if (osglData->osglCounter + osglData->mult > osglData->numberOfEl)
        throw ErrorClass("OSgL StrVector: more data elements than specified");
    else
        for (int i=0; i<osglData->mult; i++)
            osglData->osglStrArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));    
}
    break;

  case 1040:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1047:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1054:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1061:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1068:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1075:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1082:

    {
    osglData->numberOfElPresent = false;
}
    break;

  case 1088:

    {
    osglData->osglCounter = 0;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1089:

    {
    if (!osglData->namePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "name attribute must be present");
}
    break;

  case 1098:

    {
        osglData->itemList = new std::string[osglData->numberOfItems];
    }
    break;

  case 1106:

    {    
    osglData->itemList[osglData->kounter] = osglData->itemContent;
std::cout << " number of items seen so far: " << osglData->kounter << std::endl; 
    osglData->kounter++;
}
    break;

  case 1107:

    {
std::cout << "number of items specified: " << osglData->numberOfItems << std::endl;
std::cout << " number of items seen: " << osglData->kounter << std::endl; 
        if (osglData->kounter >= osglData->numberOfItems)
            if (!parserData->suppressFurtherErrorMessages)
            {
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
                parserData->suppressFurtherErrorMessages = true;
                parserData->ignoreDataAfterErrors = true;
            }
        osglData->itemContent = "";            
    }
    break;

  case 1112:

    {
std::cout << "number of items specified: " << osglData->numberOfItems << std::endl;
std::cout << " number of items seen: " << osglData->kounter << std::endl; 
    if (osglData->kounter >= osglData->numberOfItems)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->itemContent = (yyvsp[(1) - (1)].sval); 
    free((yyvsp[(1) - (1)].sval));
}
    break;

  case 1113:

    {
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixCounter++;
}
    break;

  case 1114:

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

  case 1115:

    {
    if (osglData->matrixCounter >= osglData->numberOfMatrices)
        throw ErrorClass("more matrices than specified");
    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->mtxConstructorVec.clear();
    osglData->mtxBlocksVec.clear();
    osglData->mtxBlkVec.clear();
    osglData->nBlocksVec.clear();

    /**
     *  The <matrix> tag combines the functions of the <nl> tag and the top OSnLNode,
     *  so we also initial the storage vectors here
     */
    osglData->tempC = new OSMatrix();
    osglData->mtxConstructorVec.push_back((OSMatrix*)osglData->tempC);
    osglData->mtxBlkVec.push_back((OSMatrix*)osglData->tempC);
}
    break;

  case 1116:

    {
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
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

  case 1124:

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

  case 1125:

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

  case 1137:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1141:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1144:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
}
    break;

  case 1145:

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

  case 1146:

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

  case 1161:

    {
    osglData->mtxBlkVec.back()->inumberOfChildren++;
}
    break;

  case 1174:

    {
    osglData->tempC = new ConstantMatrixElements(); 
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1175:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
}
    break;

  case 1178:

    {
        ((ConstantMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1179:

    {
        ((ConstantMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1183:

    {
    ((MatrixElements*)osglData->tempC)->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->start->numberOfEl = osglData->numberOfEl;
    ((MatrixElements*)osglData->tempC)->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1184:

    {
    if (osglData->rowMajor == false)
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->numberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1188:

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

  case 1191:

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

  case 1192:

    {
    osglData->numberOfEl = ((MatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1198:

    {
    ((ConstantMatrixElements*)osglData->tempC)->value = new ConstantMatrixValues();
    ((ConstantMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ConstantMatrixElements*)osglData->tempC)->value->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1199:

    {
    osglData->numberOfEl = ((ConstantMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglDblArray = new double[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1206:

    {
    osglData->tempC = new VarReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1207:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1210:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1211:

    {
        ((VarReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1215:

    {
    ((VarReferenceMatrixElements*)osglData->tempC)->value = new VarReferenceMatrixValues();
    ((VarReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((VarReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1216:

    {
    osglData->numberOfEl = ((VarReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1223:

    {
    osglData->tempC = new LinearMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1224:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
}
    break;

  case 1227:

    {
        ((LinearMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1228:

    {
        ((LinearMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1231:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1232:

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

  case 1233:

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

  case 1241:

    {
    osglData->nonzeroCounter++;
    if (osglData->nonzeroCounter > osglData->numberOfValues)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
}
    break;

  case 1242:

    {
    osglData->numberOfVarIdxPresent = false;
    osglData->constantPresent = false;
    osglData->constant = 0.0;
}
    break;

  case 1243:

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

  case 1255:

    {
    osglData->coefPresent = false;
    osglData->coef = 1.0;
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
}
    break;

  case 1257:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->coef = osglData->coef;
}
    break;

  case 1258:

    {
    ((LinearMatrixElements*)osglData->tempC)->value->el[osglData->nonzeroCounter]->varIdx[osglData->osglCounter]->idx = (yyvsp[(2) - (3)].ival);
    osglData->osglCounter++;
}
    break;

  case 1260:

    {
    osglData->tempC = new RealValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1261:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<realValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 1264:

    {
        ((RealValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1265:

    {
        ((RealValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1268:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1269:

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

  case 1270:

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

  case 1278:

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

  case 1282:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        ((RealValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 1284:

    {
    osglData->tempC = new ComplexValuedExpressions();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1285:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<complexValuedExpressions>: numberOfValues attribute missing");    
}
    break;

  case 1288:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1289:

    {
        ((ComplexValuedExpressions*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1292:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1293:

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

  case 1294:

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

  case 1302:

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

  case 1306:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        if (osglData->nonzeroCounter < osglData->numberOfValues) 
            ((ComplexValuedExpressions*)osglData->tempC)->value->el[osglData->nonzeroCounter]->m_treeRoot = 
                ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->nonzeroCounter++;
    }
    break;

  case 1308:

    {
    osglData->tempC = new ObjReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1309:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1312:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1313:

    {
        ((ObjReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1317:

    {
    ((ObjReferenceMatrixElements*)osglData->tempC)->value = new ObjReferenceMatrixValues();
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((ObjReferenceMatrixElements*)osglData->tempC)->value->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1318:

    {
    osglData->numberOfEl = ((ObjReferenceMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglIntArray = new int[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1325:

    {
    osglData->tempC = new ConReferenceMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1326:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
}
    break;

  case 1329:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1330:

    {
        ((ConReferenceMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1333:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1334:

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

  case 1335:

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

  case 1343:

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

  case 1349:

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

  case 1351:

    {
    osglData->tempC = new ComplexMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;  
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1352:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<complexElements>: numberOfValues attribute missing");    
}
    break;

  case 1355:

    {
        ((ComplexMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1356:

    {
        ((ComplexMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1359:

    {
        if (osglData->numberOfValues > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <value> element");
    }
    break;

  case 1360:

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

  case 1361:

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

  case 1368:

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

  case 1369:

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

  case 1378:

    {
    osglData->tempC = new StringValuedMatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
}
    break;

  case 1379:

    {
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<stringValuedElements>: numberOfValues attribute missing");    
}
    break;

  case 1382:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues = osglData->numberOfValues;
    }
    break;

  case 1383:

    {
        ((StringValuedMatrixElements*)osglData->tempC)->rowMajor = osglData->rowMajor;
    }
    break;

  case 1387:

    {
    ((StringValuedMatrixElements*)osglData->tempC)->value = new StringValuedMatrixValues();
    ((StringValuedMatrixElements*)osglData->tempC)->value->numberOfEl = osglData->numberOfEl;
    ((StringValuedMatrixElements*)osglData->tempC)->value->el = osglData->osglStrArray;
    osglData->osglStrArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1388:

    {
    osglData->numberOfEl = ((StringValuedMatrixElements*)osglData->tempC)->numberOfValues;
    if (osglData->numberOfEl > 0)
        osglData->osglStrArray = new std::string[osglData->numberOfEl];
    osglData->osglCounter = 0;
}
    break;

  case 1395:

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

  case 1397:

    {
    if (returnNlExprShape(osglData->shape) > 0)
        ((MatrixTransformation*)osglData->tempC)->shape 
            = (ENUM_NL_EXPR_SHAPE)returnNlExprShape(osglData->shape);
    else
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData,
            "unknown shape specified in matrix transformation");
}
    break;

  case 1398:

    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
}
    break;

  case 1399:

    {
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;  
    osglData->colOffsets.back() = NULL;
    osglData->osglIntArray = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
}
    break;

  case 1400:

    {
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->mtxBlocksVec.push_back((MatrixBlocks*)osglData->tempC);
    osglData->numberOfBlocksPresent = false;
}
    break;

  case 1401:

    {
    osglData->nBlocksVec.push_back(osglData->numberOfBlocks);
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = 0;
}
    break;

  case 1403:

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

  case 1404:

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

  case 1405:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 1406:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1412:

    {
    ((MatrixBlocks*)osglData->tempC)->rowOffset = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffset->numberOfEl = osglData->numberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffset->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 1413:

    {
    osglData->numberOfEl = 0;
    osglData->numberOfElPresent = false;
}
    break;

  case 1414:

    {
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->numberOfEl];
}
    break;

  case 1421:

    {
    ((MatrixBlocks*)osglData->mtxBlocksVec.back())->inumberOfChildren++;
}
    break;

  case 1422:

    {
    osglData->mtxBlkVec.pop_back();
}
    break;

  case 1423:

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

  case 1429:

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

  case 1430:

    {
        ((MatrixBlock*)osglData->tempC)->declaredMatrixType
            = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
    }
    break;

  case 1434:

    {
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}
    break;

  case 1435:

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

  case 1436:

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

  case 1437:

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

  case 1438:

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

  case 1439:

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

  case 1440:

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

  case 1441:

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

  case 1442:

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

  case 1443:

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

  case 1444:

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

  case 1445:

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

  case 1446:

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

  case 1447:

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

  case 1448:

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

  case 1449:

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

  case 1450:

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

  case 1451:

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

  case 1452:

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

  case 1453:

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

  case 1454:

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

  case 1455:

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

  case 1456:

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

  case 1457:

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

  case 1458:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->idxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one idx attribute");
    osglData->idxPresent = true;
    osglData->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1459:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->incrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->incrPresent = true;
    osglData->incr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1460:

    {
    if (osglData->matrixVarIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one matrixVarIdx attribute in <matrixVar> element");
    osglData->matrixVarIdxPresent = true;
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<matrixVarIdx> cannot be negative");
    osglData->matrixVarIdx = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1461:

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

  case 1462:

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

  case 1463:

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

  case 1464:

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

  case 1465:

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

  case 1466:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->imagPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one imaginary part in <complexElement> element");
    osglData->imagPartPresent = true;   
    osglData->imagPart = parserData->tempVal;
}
    break;

  case 1467:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->realPartPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one real part in <complexElement> element");
    osglData->realPartPresent = true;   
    osglData->realPart = parserData->tempVal;
}
    break;

  case 1468:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
}
    break;

  case 1471:

    {
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, 
            "more than one baseTranspose attribute in <baseMatrix> element");
    else
        osglData->baseTranspose    = true;
    osglData->baseTransposePresent = true;   
}
    break;

  case 1472:

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

  case 1475:

    {
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;
}
    break;

  case 1476:

    { 
    if (osglData->categoryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one category attribute");
    osglData->categoryPresent = true;   
    osglData->category = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1479:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;  
}
    break;

  case 1480:

    { 
    if (osglData->conTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one conType attribute");
    osglData->conTypePresent = true;   
    osglData->conType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1483:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;
}
    break;

  case 1484:

    { 
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one description attribute");
    osglData->descriptionPresent = true;   
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1487:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
}
    break;

  case 1488:

    { 
    if (osglData->enumTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one enumType attribute");
    osglData->enumTypePresent = true;   
    osglData->enumType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1491:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
}
    break;

  case 1492:

    { 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1495:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
}
    break;

  case 1496:

    {
    if (osglData->objTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one objType attribute");
    osglData->objTypePresent = true;   
    osglData->objType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1499:

    {
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
}
    break;

  case 1500:

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

  case 1503:

    {
   if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
}
    break;

  case 1504:

    {
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1507:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
}
    break;

  case 1508:

    {
    if (osglData->solverPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one solver attribute");
    osglData->solverPresent = true;   
    osglData->solver = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1511:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
}
    break;

  case 1512:

    { 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1515:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
}
    break;

  case 1516:

    {
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1519:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
}
    break;

  case 1520:

    { 
    if (osglData->unitPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one unit attribute");
    osglData->unitPresent = true;   
    osglData->unit = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1523:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = "";   
}
    break;

  case 1524:

    { 
    if (osglData->valuePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one value attribute");
    osglData->valuePresent = true;   
    osglData->value = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1527:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
}
    break;

  case 1528:

    {
    if (osglData->valueTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one valueType attribute");
    osglData->valueTypePresent = true;   
    osglData->valueType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1531:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
}
    break;

  case 1532:

    {
    if (osglData->varTypePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one varType attribute");
    osglData->varTypePresent = true;   
    osglData->varType = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1560:

    {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1564:

    {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);}
    break;

  case 1568:

    {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1570:

    {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1572:

    {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1574:

    {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1576:

    { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1578:

    {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1580:

    {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1582:

    {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1584:

    {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1586:

    {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1588:

    {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1590:

    {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1593:

    {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1594:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1595:

    {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1596:

    {
}
    break;

  case 1597:

    {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1598:

    {
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1599:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1601:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1603:

    {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1605:

    {
    osglData->valuePresent = false; 
    osglData->typePresent  = false; 
    osnlData->numberidattON = false;
}
    break;

  case 1606:

    {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
}
    break;

  case 1611:

    {
        osnlData->nlNodeNumberPoint->type = osglData->type;
    }
    break;

  case 1612:

    {
        osnlData->nlNodeNumberPoint->value = atof(osglData->value.c_str());
    }
    break;

  case 1614:

    {
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
    free((yyvsp[(2) - (2)].sval));
}
    break;

  case 1616:

    {
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
}
    break;

  case 1617:

    {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;}
    break;

  case 1620:

    {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new ExprNode*[ 1];
        }
    break;

  case 1624:

    {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    break;

  case 1625:

    {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
    break;

  case 1626:

    { 
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
}
    break;

  case 1627:

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

  case 1628:

    {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1629:

    {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
}
    break;

  case 1631:

    { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; }
    break;

  case 1632:

    {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1633:

    {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new ExprNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1635:

    { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; }
    break;

  case 1636:

    {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1637:

    {
    osnlData->maxVec.back()->m_mChildren = new ExprNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1639:

    { osnlData->maxVec.back()->inumberOfChildren++; }
    break;

  case 1640:

    {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1641:

    {
    osnlData->minVec.back()->m_mChildren = new ExprNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
#ifdef OSINSTANCE_AVAILABLE
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
#endif
}
    break;

  case 1643:

    { osnlData->minVec.back()->inumberOfChildren++; }
    break;

  case 1644:

    {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1645:

    {
    osnlData->productVec.back()->m_mChildren = new ExprNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
}
    break;

  case 1647:

    { osnlData->productVec.back()->inumberOfChildren++; }
    break;

  case 1667:

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

  case 1668:

    {
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
    osnlData->idxAttributePresent = false;
    osnlData->transposeAttributePresent = false;
}
    break;

  case 1675:

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

  case 1676:

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

  case 1677:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1678:

    {
    osnlData->nlMNodeMatrixVar = new OSnLMNodeMatrixVar();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixVar);
}
    break;

  case 1681:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixVar->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1682:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1683:

    {
    osnlData->nlMNodeMatrixObj = new OSnLMNodeMatrixObj();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixObj);
}
    break;

  case 1686:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixObj->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1687:

    {
    osnlData->matrixidxattON = false;
}
    break;

  case 1688:

    {
    osnlData->nlMNodeMatrixCon = new OSnLMNodeMatrixCon();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixCon);
}
    break;

  case 1691:

    {
    if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixCon->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1693:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1696:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1699:

    {
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1702:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1705:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1707:

    {
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1710:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1712:

    {
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
}
    break;

  case 1714:

    {
    if      (strcmp((yyvsp[(2) - (3)].sval),"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp((yyvsp[(2) - (3)].sval),"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"1"    ) == 0) osnlData->includeDiagonalAttribute = true;
    else if (strcmp((yyvsp[(2) - (3)].sval),"0"    ) == 0) osnlData->includeDiagonalAttribute = false;
    else parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1716:

    {
     parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "matrix merge not yet implemented");
}
    break;

  case 1720:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1723:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1726:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1729:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1731:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1732:

    {
    osnlData->matrixProductVec.back()->m_mChildren = new ExprNode*[ osnlData->matrixProductVec.back()->inumberOfChildren];
    osnlData->matrixProductVec.pop_back();
}
    break;

  case 1734:

    { 
    osnlData->matrixProductVec.back()->inumberOfChildren++; 
}
    break;

  case 1736:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1739:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1742:

    {
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1755:

    {
}
    break;

  case 1756:

    {
    osglData->realPartPresent = false;
    osglData->imagPartPresent = false;
    osnlData->nlNodePoint = new OSnLCNodeNumber();
    osnlData->nlNodeVec.push_back(osnlData->nlNodePoint);
}
    break;

  case 1759:

    {
    ((OSnLCNodeNumber*)osnlData->nlNodePoint)->setValue(osglData->realPart, osglData->imagPart);
std::cout << "just to verify: value = " 
          << ((OSnLCNodeNumber*)osnlData->nlNodePoint)->getValue() << std::endl;
}
    break;

  case 1765:

    {
    osnlData->nlNodePoint = new OSnLCNodeCreate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1768:

    {
    osnlData->nlNodePoint = new OSnLCNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1770:

    {
    osnlData->nlNodePoint = new OSnLCNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->cSumVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1771:

    {
    osnlData->cSumVec.back()->m_mChildren = new ExprNode*[ osnlData->cSumVec.back()->inumberOfChildren];
    osnlData->cSumVec.pop_back();
}
    break;

  case 1773:

    { 
    osnlData->cSumVec.back()->inumberOfChildren++; 
}
    break;

  case 1775:

    {
    osnlData->nlNodePoint = new OSnLCNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1778:

    {
    osnlData->nlNodePoint = new OSnLCNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1781:

    {
    osnlData->nlNodePoint = new OSnLCNodeConjugate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1784:

    {
    osnlData->nlNodePoint = new OSnLCNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
}
    break;

  case 1787:

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


