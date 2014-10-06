
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     QUOTE = 258,
     ATTRIBUTETEXT = 259,
     ELEMENTTEXT = 260,
     ITEMTEXT = 261,
     INTEGER = 262,
     DOUBLE = 263,
     TWOQUOTES = 264,
     ENDOFELEMENT = 265,
     GREATERTHAN = 266,
     OSILEND = 267,
     INSTANCEDATAEND = 268,
     INSTANCEDATASTARTEND = 269,
     EMPTYIDATT = 270,
     EMPTYNAMEATT = 271,
     EMPTYTYPEATT = 272,
     IDXATT = 273,
     IDXONEATT = 274,
     IDXTWOATT = 275,
     NAMEATT = 276,
     TYPEATT = 277,
     VALUEATT = 278,
     QUADRATICCOEFFICIENTSSTART = 279,
     QUADRATICCOEFFICIENTSEND = 280,
     NUMBEROFQTERMSATT = 281,
     QTERMSTART = 282,
     QTERMEND = 283,
     MATRICESSTART = 284,
     MATRICESEND = 285,
     NUMBEROFMATRICESATT = 286,
     CONESSTART = 287,
     CONESEND = 288,
     NUMBEROFCONESATT = 289,
     NONNEGATIVECONESTART = 290,
     NONNEGATIVECONEEND = 291,
     NONPOSITIVECONESTART = 292,
     NONPOSITIVECONEEND = 293,
     ORTHANTCONESTART = 294,
     ORTHANTCONEEND = 295,
     QUADRATICCONESTART = 296,
     QUADRATICCONEEND = 297,
     ROTATEDQUADRATICCONESTART = 298,
     ROTATEDQUADRATICCONEEND = 299,
     SEMIDEFINITECONESTART = 300,
     SEMIDEFINITECONEEND = 301,
     PRODUCTCONESTART = 302,
     PRODUCTCONEEND = 303,
     INTERSECTIONCONESTART = 304,
     INTERSECTIONCONEEND = 305,
     DUALCONESTART = 306,
     DUALCONEEND = 307,
     POLARCONESTART = 308,
     POLARCONEEND = 309,
     FACTORSSTART = 310,
     FACTORSEND = 311,
     COMPONENTSSTART = 312,
     COMPONENTSEND = 313,
     NORMSCALEFACTORATT = 314,
     DISTORTIONMATRIXIDXATT = 315,
     AXISDIRECTIONATT = 316,
     FIRSTAXISDIRECTIONATT = 317,
     SECONDAXISDIRECTIONATT = 318,
     EMPTYSEMIDEFINITENESSATT = 319,
     SEMIDEFINITENESSATT = 320,
     MATRIXPROGRAMMINGSTART = 321,
     MATRIXPROGRAMMINGEND = 322,
     MATRIXVARIABLESSTART = 323,
     MATRIXVARIABLESEND = 324,
     NUMBEROFMATRIXVARATT = 325,
     MATRIXVARSTART = 326,
     MATRIXVAREND = 327,
     MATRIXOBJECTIVESSTART = 328,
     MATRIXOBJECTIVESEND = 329,
     NUMBEROFMATRIXOBJATT = 330,
     MATRIXOBJSTART = 331,
     MATRIXOBJEND = 332,
     MATRIXCONSTRAINTSSTART = 333,
     MATRIXCONSTRAINTSEND = 334,
     NUMBEROFMATRIXCONATT = 335,
     MATRIXCONSTART = 336,
     MATRIXCONEND = 337,
     NUMBEROFMATRIXTERMSATT = 338,
     MATRIXTERMSTART = 339,
     MATRIXTERMEND = 340,
     MATRIXEXPRESSIONSSTART = 341,
     MATRIXEXPRESSIONSEND = 342,
     NUMBEROFMATRIXEXPRATT = 343,
     MATRIXEXPRSTART = 344,
     MATRIXEXPREND = 345,
     MATRIXIDXATT = 346,
     LBMATRIXIDXATT = 347,
     LBCONEIDXATT = 348,
     UBMATRIXIDXATT = 349,
     UBCONEIDXATT = 350,
     PATTERNMATRIXIDXATT = 351,
     ORDERCONEIDXATT = 352,
     CONSTANTMATRIXIDXATT = 353,
     SHAPEATT = 354,
     EMPTYSHAPEATT = 355,
     TIMEDOMAINSTART = 356,
     TIMEDOMAINEND = 357,
     STAGESSTART = 358,
     STAGESEND = 359,
     STAGESTART = 360,
     STAGEEND = 361,
     NUMBEROFSTAGESATT = 362,
     HORIZONATT = 363,
     STARTATT = 364,
     VARIABLESSTART = 365,
     CONSTRAINTSSTART = 366,
     OBJECTIVESSTART = 367,
     VARIABLESEND = 368,
     CONSTRAINTSEND = 369,
     OBJECTIVESEND = 370,
     NUMBEROFVARIABLESATT = 371,
     NUMBEROFCONSTRAINTSATT = 372,
     NUMBEROFOBJECTIVESATT = 373,
     STARTIDXATT = 374,
     VARSTART = 375,
     VAREND = 376,
     CONSTART = 377,
     CONEND = 378,
     OBJSTART = 379,
     OBJEND = 380,
     INTERVALSTART = 381,
     INTERVALEND = 382,
     HEADERSTART = 383,
     HEADEREND = 384,
     FILENAMESTART = 385,
     FILENAMEEND = 386,
     FILENAMEEMPTY = 387,
     FILENAMESTARTANDEND = 388,
     FILESOURCESTART = 389,
     FILESOURCEEND = 390,
     FILESOURCEEMPTY = 391,
     FILESOURCESTARTANDEND = 392,
     FILEDESCRIPTIONSTART = 393,
     FILEDESCRIPTIONEND = 394,
     FILEDESCRIPTIONEMPTY = 395,
     FILEDESCRIPTIONSTARTANDEND = 396,
     FILECREATORSTART = 397,
     FILECREATOREND = 398,
     FILECREATOREMPTY = 399,
     FILECREATORSTARTANDEND = 400,
     FILELICENCESTART = 401,
     FILELICENCEEND = 402,
     FILELICENCEEMPTY = 403,
     FILELICENCESTARTANDEND = 404,
     ENUMERATIONSTART = 405,
     ENUMERATIONEND = 406,
     NUMBEROFELATT = 407,
     ITEMEMPTY = 408,
     ITEMSTART = 409,
     ITEMEND = 410,
     ITEMSTARTANDEND = 411,
     BASE64START = 412,
     BASE64END = 413,
     INCRATT = 414,
     MULTATT = 415,
     SIZEOFATT = 416,
     ELSTART = 417,
     ELEND = 418,
     MATRIXSTART = 419,
     MATRIXEND = 420,
     BASEMATRIXEND = 421,
     BASEMATRIXSTART = 422,
     BLOCKSTART = 423,
     BLOCKEND = 424,
     BLOCKSSTART = 425,
     BLOCKSEND = 426,
     EMPTYSYMMETRYATT = 427,
     SYMMETRYATT = 428,
     EMPTYNEGATIVEPATTERNATT = 429,
     NEGATIVEPATTERNATT = 430,
     CONSTANTATT = 431,
     NUMBEROFBLOCKSATT = 432,
     NUMBEROFCOLUMNSATT = 433,
     NUMBEROFROWSATT = 434,
     NUMBEROFVALUESATT = 435,
     NUMBEROFVARIDXATT = 436,
     BASEMATRIXIDXATT = 437,
     TARGETMATRIXFIRSTROWATT = 438,
     TARGETMATRIXFIRSTCOLATT = 439,
     BASEMATRIXSTARTROWATT = 440,
     BASEMATRIXSTARTCOLATT = 441,
     BASEMATRIXENDROWATT = 442,
     BASEMATRIXENDCOLATT = 443,
     SCALARMULTIPLIERATT = 444,
     EMPTYBASETRANSPOSEATT = 445,
     BASETRANSPOSEATT = 446,
     ELEMENTSSTART = 447,
     ELEMENTSEND = 448,
     CONSTANTELEMENTSSTART = 449,
     CONSTANTELEMENTSEND = 450,
     STARTVECTORSTART = 451,
     STARTVECTOREND = 452,
     NONZEROSSTART = 453,
     NONZEROSEND = 454,
     INDEXESSTART = 455,
     INDEXESEND = 456,
     VALUESSTART = 457,
     VALUESEND = 458,
     VARREFERENCEELEMENTSSTART = 459,
     VARREFERENCEELEMENTSEND = 460,
     LINEARELEMENTSSTART = 461,
     LINEARELEMENTSEND = 462,
     GENERALELEMENTSSTART = 463,
     GENERALELEMENTSEND = 464,
     CONREFERENCEELEMENTSSTART = 465,
     CONREFERENCEELEMENTSEND = 466,
     OBJREFERENCEELEMENTSSTART = 467,
     OBJREFERENCEELEMENTSEND = 468,
     PATTERNELEMENTSSTART = 469,
     PATTERNELEMENTSEND = 470,
     VARIDXSTART = 471,
     VARIDXEND = 472,
     TRANSFORMATIONSTART = 473,
     TRANSFORMATIONEND = 474,
     COLOFFSETSSTART = 475,
     COLOFFSETSEND = 476,
     ROWOFFSETSSTART = 477,
     ROWOFFSETSEND = 478,
     EMPTYROWMAJORATT = 479,
     ROWMAJORATT = 480,
     BLOCKROWIDXATT = 481,
     BLOCKCOLIDXATT = 482,
     DUMMY = 483,
     NONLINEAREXPRESSIONSSTART = 484,
     NONLINEAREXPRESSIONSEND = 485,
     NUMBEROFNONLINEAREXPRESSIONS = 486,
     NLSTART = 487,
     NLEND = 488,
     POWERSTART = 489,
     POWEREND = 490,
     PLUSSTART = 491,
     PLUSEND = 492,
     MINUSSTART = 493,
     MINUSEND = 494,
     DIVIDESTART = 495,
     DIVIDEEND = 496,
     LNSTART = 497,
     LNEND = 498,
     SQRTSTART = 499,
     SQRTEND = 500,
     SUMSTART = 501,
     SUMEND = 502,
     PRODUCTSTART = 503,
     PRODUCTEND = 504,
     EXPSTART = 505,
     EXPEND = 506,
     NEGATESTART = 507,
     NEGATEEND = 508,
     IFSTART = 509,
     IFEND = 510,
     SQUARESTART = 511,
     SQUAREEND = 512,
     COSSTART = 513,
     COSEND = 514,
     SINSTART = 515,
     SINEND = 516,
     VARIABLESTART = 517,
     VARIABLEEND = 518,
     ABSSTART = 519,
     ABSEND = 520,
     ERFSTART = 521,
     ERFEND = 522,
     MAXSTART = 523,
     MAXEND = 524,
     ALLDIFFSTART = 525,
     ALLDIFFEND = 526,
     MINSTART = 527,
     MINEND = 528,
     ESTART = 529,
     EEND = 530,
     PISTART = 531,
     PIEND = 532,
     TIMESSTART = 533,
     TIMESEND = 534,
     NUMBERSTART = 535,
     NUMBEREND = 536,
     MATRIXDETERMINANTSTART = 537,
     MATRIXDETERMINANTEND = 538,
     MATRIXTRACESTART = 539,
     MATRIXTRACEEND = 540,
     MATRIXTOSCALARSTART = 541,
     MATRIXTOSCALAREND = 542,
     MATRIXDIAGONALSTART = 543,
     MATRIXDIAGONALEND = 544,
     MATRIXDOTTIMESSTART = 545,
     MATRIXDOTTIMESEND = 546,
     MATRIXLOWERTRIANGLESTART = 547,
     MATRIXLOWERTRIANGLEEND = 548,
     MATRIXUPPERTRIANGLESTART = 549,
     MATRIXUPPERTRIANGLEEND = 550,
     MATRIXMERGESTART = 551,
     MATRIXMERGEEND = 552,
     MATRIXMINUSSTART = 553,
     MATRIXMINUSEND = 554,
     MATRIXPLUSSTART = 555,
     MATRIXPLUSEND = 556,
     MATRIXTIMESSTART = 557,
     MATRIXTIMESEND = 558,
     MATRIXPRODUCTSTART = 559,
     MATRIXPRODUCTEND = 560,
     MATRIXSCALARTIMESSTART = 561,
     MATRIXSCALARTIMESEND = 562,
     MATRIXSUBMATRIXATSTART = 563,
     MATRIXSUBMATRIXATEND = 564,
     MATRIXTRANSPOSESTART = 565,
     MATRIXTRANSPOSEEND = 566,
     MATRIXREFERENCESTART = 567,
     MATRIXREFERENCEEND = 568,
     IDENTITYMATRIXSTART = 569,
     IDENTITYMATRIXEND = 570,
     MATRIXINVERSESTART = 571,
     MATRIXINVERSEEND = 572,
     EMPTYINCLUDEDIAGONALATT = 573,
     INCLUDEDIAGONALATT = 574,
     IDATT = 575,
     COEFATT = 576
   };
#endif
/* Tokens.  */
#define QUOTE 258
#define ATTRIBUTETEXT 259
#define ELEMENTTEXT 260
#define ITEMTEXT 261
#define INTEGER 262
#define DOUBLE 263
#define TWOQUOTES 264
#define ENDOFELEMENT 265
#define GREATERTHAN 266
#define OSILEND 267
#define INSTANCEDATAEND 268
#define INSTANCEDATASTARTEND 269
#define EMPTYIDATT 270
#define EMPTYNAMEATT 271
#define EMPTYTYPEATT 272
#define IDXATT 273
#define IDXONEATT 274
#define IDXTWOATT 275
#define NAMEATT 276
#define TYPEATT 277
#define VALUEATT 278
#define QUADRATICCOEFFICIENTSSTART 279
#define QUADRATICCOEFFICIENTSEND 280
#define NUMBEROFQTERMSATT 281
#define QTERMSTART 282
#define QTERMEND 283
#define MATRICESSTART 284
#define MATRICESEND 285
#define NUMBEROFMATRICESATT 286
#define CONESSTART 287
#define CONESEND 288
#define NUMBEROFCONESATT 289
#define NONNEGATIVECONESTART 290
#define NONNEGATIVECONEEND 291
#define NONPOSITIVECONESTART 292
#define NONPOSITIVECONEEND 293
#define ORTHANTCONESTART 294
#define ORTHANTCONEEND 295
#define QUADRATICCONESTART 296
#define QUADRATICCONEEND 297
#define ROTATEDQUADRATICCONESTART 298
#define ROTATEDQUADRATICCONEEND 299
#define SEMIDEFINITECONESTART 300
#define SEMIDEFINITECONEEND 301
#define PRODUCTCONESTART 302
#define PRODUCTCONEEND 303
#define INTERSECTIONCONESTART 304
#define INTERSECTIONCONEEND 305
#define DUALCONESTART 306
#define DUALCONEEND 307
#define POLARCONESTART 308
#define POLARCONEEND 309
#define FACTORSSTART 310
#define FACTORSEND 311
#define COMPONENTSSTART 312
#define COMPONENTSEND 313
#define NORMSCALEFACTORATT 314
#define DISTORTIONMATRIXIDXATT 315
#define AXISDIRECTIONATT 316
#define FIRSTAXISDIRECTIONATT 317
#define SECONDAXISDIRECTIONATT 318
#define EMPTYSEMIDEFINITENESSATT 319
#define SEMIDEFINITENESSATT 320
#define MATRIXPROGRAMMINGSTART 321
#define MATRIXPROGRAMMINGEND 322
#define MATRIXVARIABLESSTART 323
#define MATRIXVARIABLESEND 324
#define NUMBEROFMATRIXVARATT 325
#define MATRIXVARSTART 326
#define MATRIXVAREND 327
#define MATRIXOBJECTIVESSTART 328
#define MATRIXOBJECTIVESEND 329
#define NUMBEROFMATRIXOBJATT 330
#define MATRIXOBJSTART 331
#define MATRIXOBJEND 332
#define MATRIXCONSTRAINTSSTART 333
#define MATRIXCONSTRAINTSEND 334
#define NUMBEROFMATRIXCONATT 335
#define MATRIXCONSTART 336
#define MATRIXCONEND 337
#define NUMBEROFMATRIXTERMSATT 338
#define MATRIXTERMSTART 339
#define MATRIXTERMEND 340
#define MATRIXEXPRESSIONSSTART 341
#define MATRIXEXPRESSIONSEND 342
#define NUMBEROFMATRIXEXPRATT 343
#define MATRIXEXPRSTART 344
#define MATRIXEXPREND 345
#define MATRIXIDXATT 346
#define LBMATRIXIDXATT 347
#define LBCONEIDXATT 348
#define UBMATRIXIDXATT 349
#define UBCONEIDXATT 350
#define PATTERNMATRIXIDXATT 351
#define ORDERCONEIDXATT 352
#define CONSTANTMATRIXIDXATT 353
#define SHAPEATT 354
#define EMPTYSHAPEATT 355
#define TIMEDOMAINSTART 356
#define TIMEDOMAINEND 357
#define STAGESSTART 358
#define STAGESEND 359
#define STAGESTART 360
#define STAGEEND 361
#define NUMBEROFSTAGESATT 362
#define HORIZONATT 363
#define STARTATT 364
#define VARIABLESSTART 365
#define CONSTRAINTSSTART 366
#define OBJECTIVESSTART 367
#define VARIABLESEND 368
#define CONSTRAINTSEND 369
#define OBJECTIVESEND 370
#define NUMBEROFVARIABLESATT 371
#define NUMBEROFCONSTRAINTSATT 372
#define NUMBEROFOBJECTIVESATT 373
#define STARTIDXATT 374
#define VARSTART 375
#define VAREND 376
#define CONSTART 377
#define CONEND 378
#define OBJSTART 379
#define OBJEND 380
#define INTERVALSTART 381
#define INTERVALEND 382
#define HEADERSTART 383
#define HEADEREND 384
#define FILENAMESTART 385
#define FILENAMEEND 386
#define FILENAMEEMPTY 387
#define FILENAMESTARTANDEND 388
#define FILESOURCESTART 389
#define FILESOURCEEND 390
#define FILESOURCEEMPTY 391
#define FILESOURCESTARTANDEND 392
#define FILEDESCRIPTIONSTART 393
#define FILEDESCRIPTIONEND 394
#define FILEDESCRIPTIONEMPTY 395
#define FILEDESCRIPTIONSTARTANDEND 396
#define FILECREATORSTART 397
#define FILECREATOREND 398
#define FILECREATOREMPTY 399
#define FILECREATORSTARTANDEND 400
#define FILELICENCESTART 401
#define FILELICENCEEND 402
#define FILELICENCEEMPTY 403
#define FILELICENCESTARTANDEND 404
#define ENUMERATIONSTART 405
#define ENUMERATIONEND 406
#define NUMBEROFELATT 407
#define ITEMEMPTY 408
#define ITEMSTART 409
#define ITEMEND 410
#define ITEMSTARTANDEND 411
#define BASE64START 412
#define BASE64END 413
#define INCRATT 414
#define MULTATT 415
#define SIZEOFATT 416
#define ELSTART 417
#define ELEND 418
#define MATRIXSTART 419
#define MATRIXEND 420
#define BASEMATRIXEND 421
#define BASEMATRIXSTART 422
#define BLOCKSTART 423
#define BLOCKEND 424
#define BLOCKSSTART 425
#define BLOCKSEND 426
#define EMPTYSYMMETRYATT 427
#define SYMMETRYATT 428
#define EMPTYNEGATIVEPATTERNATT 429
#define NEGATIVEPATTERNATT 430
#define CONSTANTATT 431
#define NUMBEROFBLOCKSATT 432
#define NUMBEROFCOLUMNSATT 433
#define NUMBEROFROWSATT 434
#define NUMBEROFVALUESATT 435
#define NUMBEROFVARIDXATT 436
#define BASEMATRIXIDXATT 437
#define TARGETMATRIXFIRSTROWATT 438
#define TARGETMATRIXFIRSTCOLATT 439
#define BASEMATRIXSTARTROWATT 440
#define BASEMATRIXSTARTCOLATT 441
#define BASEMATRIXENDROWATT 442
#define BASEMATRIXENDCOLATT 443
#define SCALARMULTIPLIERATT 444
#define EMPTYBASETRANSPOSEATT 445
#define BASETRANSPOSEATT 446
#define ELEMENTSSTART 447
#define ELEMENTSEND 448
#define CONSTANTELEMENTSSTART 449
#define CONSTANTELEMENTSEND 450
#define STARTVECTORSTART 451
#define STARTVECTOREND 452
#define NONZEROSSTART 453
#define NONZEROSEND 454
#define INDEXESSTART 455
#define INDEXESEND 456
#define VALUESSTART 457
#define VALUESEND 458
#define VARREFERENCEELEMENTSSTART 459
#define VARREFERENCEELEMENTSEND 460
#define LINEARELEMENTSSTART 461
#define LINEARELEMENTSEND 462
#define GENERALELEMENTSSTART 463
#define GENERALELEMENTSEND 464
#define CONREFERENCEELEMENTSSTART 465
#define CONREFERENCEELEMENTSEND 466
#define OBJREFERENCEELEMENTSSTART 467
#define OBJREFERENCEELEMENTSEND 468
#define PATTERNELEMENTSSTART 469
#define PATTERNELEMENTSEND 470
#define VARIDXSTART 471
#define VARIDXEND 472
#define TRANSFORMATIONSTART 473
#define TRANSFORMATIONEND 474
#define COLOFFSETSSTART 475
#define COLOFFSETSEND 476
#define ROWOFFSETSSTART 477
#define ROWOFFSETSEND 478
#define EMPTYROWMAJORATT 479
#define ROWMAJORATT 480
#define BLOCKROWIDXATT 481
#define BLOCKCOLIDXATT 482
#define DUMMY 483
#define NONLINEAREXPRESSIONSSTART 484
#define NONLINEAREXPRESSIONSEND 485
#define NUMBEROFNONLINEAREXPRESSIONS 486
#define NLSTART 487
#define NLEND 488
#define POWERSTART 489
#define POWEREND 490
#define PLUSSTART 491
#define PLUSEND 492
#define MINUSSTART 493
#define MINUSEND 494
#define DIVIDESTART 495
#define DIVIDEEND 496
#define LNSTART 497
#define LNEND 498
#define SQRTSTART 499
#define SQRTEND 500
#define SUMSTART 501
#define SUMEND 502
#define PRODUCTSTART 503
#define PRODUCTEND 504
#define EXPSTART 505
#define EXPEND 506
#define NEGATESTART 507
#define NEGATEEND 508
#define IFSTART 509
#define IFEND 510
#define SQUARESTART 511
#define SQUAREEND 512
#define COSSTART 513
#define COSEND 514
#define SINSTART 515
#define SINEND 516
#define VARIABLESTART 517
#define VARIABLEEND 518
#define ABSSTART 519
#define ABSEND 520
#define ERFSTART 521
#define ERFEND 522
#define MAXSTART 523
#define MAXEND 524
#define ALLDIFFSTART 525
#define ALLDIFFEND 526
#define MINSTART 527
#define MINEND 528
#define ESTART 529
#define EEND 530
#define PISTART 531
#define PIEND 532
#define TIMESSTART 533
#define TIMESEND 534
#define NUMBERSTART 535
#define NUMBEREND 536
#define MATRIXDETERMINANTSTART 537
#define MATRIXDETERMINANTEND 538
#define MATRIXTRACESTART 539
#define MATRIXTRACEEND 540
#define MATRIXTOSCALARSTART 541
#define MATRIXTOSCALAREND 542
#define MATRIXDIAGONALSTART 543
#define MATRIXDIAGONALEND 544
#define MATRIXDOTTIMESSTART 545
#define MATRIXDOTTIMESEND 546
#define MATRIXLOWERTRIANGLESTART 547
#define MATRIXLOWERTRIANGLEEND 548
#define MATRIXUPPERTRIANGLESTART 549
#define MATRIXUPPERTRIANGLEEND 550
#define MATRIXMERGESTART 551
#define MATRIXMERGEEND 552
#define MATRIXMINUSSTART 553
#define MATRIXMINUSEND 554
#define MATRIXPLUSSTART 555
#define MATRIXPLUSEND 556
#define MATRIXTIMESSTART 557
#define MATRIXTIMESEND 558
#define MATRIXPRODUCTSTART 559
#define MATRIXPRODUCTEND 560
#define MATRIXSCALARTIMESSTART 561
#define MATRIXSCALARTIMESEND 562
#define MATRIXSUBMATRIXATSTART 563
#define MATRIXSUBMATRIXATEND 564
#define MATRIXTRANSPOSESTART 565
#define MATRIXTRANSPOSEEND 566
#define MATRIXREFERENCESTART 567
#define MATRIXREFERENCEEND 568
#define IDENTITYMATRIXSTART 569
#define IDENTITYMATRIXEND 570
#define MATRIXINVERSESTART 571
#define MATRIXINVERSEEND 572
#define EMPTYINCLUDEDIAGONALATT 573
#define INCLUDEDIAGONALATT 574
#define IDATT 575
#define COEFATT 576




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



