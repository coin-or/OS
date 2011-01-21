/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     ATTRIBUTETEXT = 258,
     ELEMENTTEXT = 259,
     ITEMTEXT = 260,
     INTEGER = 261,
     DOUBLE = 262,
     QUOTE = 263,
     TWOQUOTES = 264,
     GREATERTHAN = 265,
     ENDOFELEMENT = 266,
     OSRLSTART = 267,
     OSRLSTARTEMPTY = 268,
     OSRLATTRIBUTETEXT = 269,
     OSRLEND = 270,
     NUMBEROFCONATT = 271,
     NUMBEROFCONSTRAINTSATT = 272,
     NUMBEROFELATT = 273,
     NUMBEROFENUMERATIONSATT = 274,
     NUMBEROFIDXATT = 275,
     NUMBEROFITEMSATT = 276,
     NUMBEROFOBJATT = 277,
     NUMBEROFOBJECTIVESATT = 278,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 279,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 280,
     NUMBEROFOTHERRESULTSATT = 281,
     NUMBEROFOTHERSOLUTIONRESULTSATT = 282,
     NUMBEROFOTHERVARIABLERESULTSATT = 283,
     NUMBEROFSOLUTIONSATT = 284,
     NUMBEROFSOLVEROUTPUTSATT = 285,
     NUMBEROFSUBSTATUSESATT = 286,
     NUMBEROFTIMESATT = 287,
     NUMBEROFVARATT = 288,
     NUMBEROFVARIABLESATT = 289,
     NUMBEROFVARIDXATT = 290,
     TARGETOBJECTIVEIDXATT = 291,
     IDXATT = 292,
     INCRATT = 293,
     MULTATT = 294,
     SIZEOFATT = 295,
     CATEGORYATT = 296,
     EMPTYCATEGORYATT = 297,
     DESCRIPTIONATT = 298,
     EMPTYDESCRIPTIONATT = 299,
     NAMEATT = 300,
     EMPTYNAMEATT = 301,
     TYPEATT = 302,
     EMPTYTYPEATT = 303,
     UNITATT = 304,
     EMPTYUNITATT = 305,
     VALUEATT = 306,
     EMPTYVALUEATT = 307,
     WEIGHTEDOBJECTIVESATT = 308,
     EMPTYWEIGHTEDOBJECTIVESATT = 309,
     HEADERSTART = 310,
     HEADEREND = 311,
     GENERALSTART = 312,
     GENERALEND = 313,
     SYSTEMSTART = 314,
     SYSTEMEND = 315,
     SERVICESTART = 316,
     SERVICEEND = 317,
     JOBSTART = 318,
     JOBEND = 319,
     OPTIMIZATIONSTART = 320,
     OPTIMIZATIONEND = 321,
     ITEMSTART = 322,
     ITEMEND = 323,
     ITEMSTARTANDEND = 324,
     ITEMEMPTY = 325,
     FILENAMESTART = 326,
     FILENAMEEND = 327,
     FILENAMEEMPTY = 328,
     FILENAMESTARTANDEND = 329,
     FILESOURCESTART = 330,
     FILESOURCEEND = 331,
     FILESOURCEEMPTY = 332,
     FILESOURCESTARTANDEND = 333,
     FILEDESCRIPTIONSTART = 334,
     FILEDESCRIPTIONEND = 335,
     FILEDESCRIPTIONEMPTY = 336,
     FILEDESCRIPTIONSTARTANDEND = 337,
     FILECREATEDBYSTART = 338,
     FILECREATEDBYEND = 339,
     FILECREATEDBYEMPTY = 340,
     FILECREATEDBYSTARTANDEND = 341,
     FILELICENCESTART = 342,
     FILELICENCEEND = 343,
     FILELICENCEEMPTY = 344,
     FILELICENCESTARTANDEND = 345,
     ACTUALSTARTTIMESTART = 346,
     ACTUALSTARTTIMEEND = 347,
     ATLOWERSTART = 348,
     ATLOWEREND = 349,
     ATUPPERSTART = 350,
     ATUPPEREND = 351,
     AVAILABLECPUNUMBERSTART = 352,
     AVAILABLECPUNUMBEREND = 353,
     AVAILABLECPUSPEEDSTART = 354,
     AVAILABLECPUSPEEDEND = 355,
     AVAILABLEDISKSPACESTART = 356,
     AVAILABLEDISKSPACEEND = 357,
     AVAILABLEMEMORYSTART = 358,
     AVAILABLEMEMORYEND = 359,
     BASE64START = 360,
     BASE64END = 361,
     BASICSTART = 362,
     BASICEND = 363,
     BASISSTATUSSTART = 364,
     BASISSTATUSEND = 365,
     BASSTATUSSTART = 366,
     BASSTATUSEND = 367,
     CONSTART = 368,
     CONEND = 369,
     CONSTRAINTSSTART = 370,
     CONSTRAINTSEND = 371,
     CURRENTJOBCOUNTSTART = 372,
     CURRENTJOBCOUNTEND = 373,
     CURRENTSTATESTART = 374,
     CURRENTSTATEEND = 375,
     DUALVALUESSTART = 376,
     DUALVALUESEND = 377,
     ELSTART = 378,
     ELEND = 379,
     ENUMERATIONSTART = 380,
     ENUMERATIONEND = 381,
     ENDTIMESTART = 382,
     ENDTIMEEND = 383,
     GENERALSTATUSSTART = 384,
     GENERALSTATUSEND = 385,
     GENERALSUBSTATUSSTART = 386,
     GENERALSUBSTATUSEND = 387,
     IDXSTART = 388,
     IDXEND = 389,
     INSTANCENAMESTART = 390,
     INSTANCENAMEEND = 391,
     ISFREESTART = 392,
     ISFREEEND = 393,
     JOBIDSTART = 394,
     JOBIDEND = 395,
     MESSAGESTART = 396,
     MESSAGEEND = 397,
     OBJSTART = 398,
     OBJEND = 399,
     OBJECTIVESSTART = 400,
     OBJECTIVESEND = 401,
     OPTIMIZATIONSOLUTIONSTATUSSTART = 402,
     OPTIMIZATIONSOLUTIONSTATUSEND = 403,
     OPTIMIZATIONSOLUTIONSUBSTATUSSTART = 404,
     OPTIMIZATIONSOLUTIONSUBSTATUSEND = 405,
     OTHERSTART = 406,
     OTHEREND = 407,
     OTHERRESULTSSTART = 408,
     OTHERRESULTSEND = 409,
     OTHERSOLUTIONRESULTSTART = 410,
     OTHERSOLUTIONRESULTEND = 411,
     OTHERSOLUTIONRESULTSSTART = 412,
     OTHERSOLUTIONRESULTSEND = 413,
     OTHERSOLVEROUTPUTSTART = 414,
     OTHERSOLVEROUTPUTEND = 415,
     SCHEDULEDSTARTTIMESTART = 416,
     SCHEDULEDSTARTTIMEEND = 417,
     SERVICENAMESTART = 418,
     SERVICENAMEEND = 419,
     SERVICEURISTART = 420,
     SERVICEURIEND = 421,
     SERVICEUTILIZATIONSTART = 422,
     SERVICEUTILIZATIONEND = 423,
     SOLUTIONSTART = 424,
     SOLUTIONEND = 425,
     SOLVERINVOKEDSTART = 426,
     SOLVERINVOKEDEND = 427,
     SOLVEROUTPUTSTART = 428,
     SOLVEROUTPUTEND = 429,
     STATUSSTART = 430,
     STATUSEND = 431,
     SUBMITTIMESTART = 432,
     SUBMITTIMEEND = 433,
     SUBSTATUSSTART = 434,
     SUBSTATUSEND = 435,
     SUPERBASICSTART = 436,
     SUPERBASICEND = 437,
     SYSTEMINFORMATIONSTART = 438,
     SYSTEMINFORMATIONEND = 439,
     TIMESTART = 440,
     TIMEEND = 441,
     TIMESERVICESTARTEDSTART = 442,
     TIMESERVICESTARTEDEND = 443,
     TIMESTAMPSTART = 444,
     TIMESTAMPEND = 445,
     TIMINGINFORMATIONSTART = 446,
     TIMINGINFORMATIONEND = 447,
     TOTALJOBSSOFARSTART = 448,
     TOTALJOBSSOFAREND = 449,
     UNKNOWNSTART = 450,
     UNKNOWNEND = 451,
     USEDCPUNUMBERSTART = 452,
     USEDCPUNUMBEREND = 453,
     USEDCPUSPEEDSTART = 454,
     USEDCPUSPEEDEND = 455,
     USEDDISKSPACESTART = 456,
     USEDDISKSPACEEND = 457,
     USEDMEMORYSTART = 458,
     USEDMEMORYEND = 459,
     VALUESSTART = 460,
     VALUESEND = 461,
     VALUESSTRINGSTART = 462,
     VALUESSTRINGEND = 463,
     VARSTART = 464,
     VAREND = 465,
     VARIABLESSTART = 466,
     VARIABLESEND = 467,
     VARIDXSTART = 468,
     VARIDXEND = 469,
     DUMMY = 470
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
#define OSRLSTART 267
#define OSRLSTARTEMPTY 268
#define OSRLATTRIBUTETEXT 269
#define OSRLEND 270
#define NUMBEROFCONATT 271
#define NUMBEROFCONSTRAINTSATT 272
#define NUMBEROFELATT 273
#define NUMBEROFENUMERATIONSATT 274
#define NUMBEROFIDXATT 275
#define NUMBEROFITEMSATT 276
#define NUMBEROFOBJATT 277
#define NUMBEROFOBJECTIVESATT 278
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 279
#define NUMBEROFOTHEROBJECTIVERESULTSATT 280
#define NUMBEROFOTHERRESULTSATT 281
#define NUMBEROFOTHERSOLUTIONRESULTSATT 282
#define NUMBEROFOTHERVARIABLERESULTSATT 283
#define NUMBEROFSOLUTIONSATT 284
#define NUMBEROFSOLVEROUTPUTSATT 285
#define NUMBEROFSUBSTATUSESATT 286
#define NUMBEROFTIMESATT 287
#define NUMBEROFVARATT 288
#define NUMBEROFVARIABLESATT 289
#define NUMBEROFVARIDXATT 290
#define TARGETOBJECTIVEIDXATT 291
#define IDXATT 292
#define INCRATT 293
#define MULTATT 294
#define SIZEOFATT 295
#define CATEGORYATT 296
#define EMPTYCATEGORYATT 297
#define DESCRIPTIONATT 298
#define EMPTYDESCRIPTIONATT 299
#define NAMEATT 300
#define EMPTYNAMEATT 301
#define TYPEATT 302
#define EMPTYTYPEATT 303
#define UNITATT 304
#define EMPTYUNITATT 305
#define VALUEATT 306
#define EMPTYVALUEATT 307
#define WEIGHTEDOBJECTIVESATT 308
#define EMPTYWEIGHTEDOBJECTIVESATT 309
#define HEADERSTART 310
#define HEADEREND 311
#define GENERALSTART 312
#define GENERALEND 313
#define SYSTEMSTART 314
#define SYSTEMEND 315
#define SERVICESTART 316
#define SERVICEEND 317
#define JOBSTART 318
#define JOBEND 319
#define OPTIMIZATIONSTART 320
#define OPTIMIZATIONEND 321
#define ITEMSTART 322
#define ITEMEND 323
#define ITEMSTARTANDEND 324
#define ITEMEMPTY 325
#define FILENAMESTART 326
#define FILENAMEEND 327
#define FILENAMEEMPTY 328
#define FILENAMESTARTANDEND 329
#define FILESOURCESTART 330
#define FILESOURCEEND 331
#define FILESOURCEEMPTY 332
#define FILESOURCESTARTANDEND 333
#define FILEDESCRIPTIONSTART 334
#define FILEDESCRIPTIONEND 335
#define FILEDESCRIPTIONEMPTY 336
#define FILEDESCRIPTIONSTARTANDEND 337
#define FILECREATEDBYSTART 338
#define FILECREATEDBYEND 339
#define FILECREATEDBYEMPTY 340
#define FILECREATEDBYSTARTANDEND 341
#define FILELICENCESTART 342
#define FILELICENCEEND 343
#define FILELICENCEEMPTY 344
#define FILELICENCESTARTANDEND 345
#define ACTUALSTARTTIMESTART 346
#define ACTUALSTARTTIMEEND 347
#define ATLOWERSTART 348
#define ATLOWEREND 349
#define ATUPPERSTART 350
#define ATUPPEREND 351
#define AVAILABLECPUNUMBERSTART 352
#define AVAILABLECPUNUMBEREND 353
#define AVAILABLECPUSPEEDSTART 354
#define AVAILABLECPUSPEEDEND 355
#define AVAILABLEDISKSPACESTART 356
#define AVAILABLEDISKSPACEEND 357
#define AVAILABLEMEMORYSTART 358
#define AVAILABLEMEMORYEND 359
#define BASE64START 360
#define BASE64END 361
#define BASICSTART 362
#define BASICEND 363
#define BASISSTATUSSTART 364
#define BASISSTATUSEND 365
#define BASSTATUSSTART 366
#define BASSTATUSEND 367
#define CONSTART 368
#define CONEND 369
#define CONSTRAINTSSTART 370
#define CONSTRAINTSEND 371
#define CURRENTJOBCOUNTSTART 372
#define CURRENTJOBCOUNTEND 373
#define CURRENTSTATESTART 374
#define CURRENTSTATEEND 375
#define DUALVALUESSTART 376
#define DUALVALUESEND 377
#define ELSTART 378
#define ELEND 379
#define ENUMERATIONSTART 380
#define ENUMERATIONEND 381
#define ENDTIMESTART 382
#define ENDTIMEEND 383
#define GENERALSTATUSSTART 384
#define GENERALSTATUSEND 385
#define GENERALSUBSTATUSSTART 386
#define GENERALSUBSTATUSEND 387
#define IDXSTART 388
#define IDXEND 389
#define INSTANCENAMESTART 390
#define INSTANCENAMEEND 391
#define ISFREESTART 392
#define ISFREEEND 393
#define JOBIDSTART 394
#define JOBIDEND 395
#define MESSAGESTART 396
#define MESSAGEEND 397
#define OBJSTART 398
#define OBJEND 399
#define OBJECTIVESSTART 400
#define OBJECTIVESEND 401
#define OPTIMIZATIONSOLUTIONSTATUSSTART 402
#define OPTIMIZATIONSOLUTIONSTATUSEND 403
#define OPTIMIZATIONSOLUTIONSUBSTATUSSTART 404
#define OPTIMIZATIONSOLUTIONSUBSTATUSEND 405
#define OTHERSTART 406
#define OTHEREND 407
#define OTHERRESULTSSTART 408
#define OTHERRESULTSEND 409
#define OTHERSOLUTIONRESULTSTART 410
#define OTHERSOLUTIONRESULTEND 411
#define OTHERSOLUTIONRESULTSSTART 412
#define OTHERSOLUTIONRESULTSEND 413
#define OTHERSOLVEROUTPUTSTART 414
#define OTHERSOLVEROUTPUTEND 415
#define SCHEDULEDSTARTTIMESTART 416
#define SCHEDULEDSTARTTIMEEND 417
#define SERVICENAMESTART 418
#define SERVICENAMEEND 419
#define SERVICEURISTART 420
#define SERVICEURIEND 421
#define SERVICEUTILIZATIONSTART 422
#define SERVICEUTILIZATIONEND 423
#define SOLUTIONSTART 424
#define SOLUTIONEND 425
#define SOLVERINVOKEDSTART 426
#define SOLVERINVOKEDEND 427
#define SOLVEROUTPUTSTART 428
#define SOLVEROUTPUTEND 429
#define STATUSSTART 430
#define STATUSEND 431
#define SUBMITTIMESTART 432
#define SUBMITTIMEEND 433
#define SUBSTATUSSTART 434
#define SUBSTATUSEND 435
#define SUPERBASICSTART 436
#define SUPERBASICEND 437
#define SYSTEMINFORMATIONSTART 438
#define SYSTEMINFORMATIONEND 439
#define TIMESTART 440
#define TIMEEND 441
#define TIMESERVICESTARTEDSTART 442
#define TIMESERVICESTARTEDEND 443
#define TIMESTAMPSTART 444
#define TIMESTAMPEND 445
#define TIMINGINFORMATIONSTART 446
#define TIMINGINFORMATIONEND 447
#define TOTALJOBSSOFARSTART 448
#define TOTALJOBSSOFAREND 449
#define UNKNOWNSTART 450
#define UNKNOWNEND 451
#define USEDCPUNUMBERSTART 452
#define USEDCPUNUMBEREND 453
#define USEDCPUSPEEDSTART 454
#define USEDCPUSPEEDEND 455
#define USEDDISKSPACESTART 456
#define USEDDISKSPACEEND 457
#define USEDMEMORYSTART 458
#define USEDMEMORYEND 459
#define VALUESSTART 460
#define VALUESEND 461
#define VALUESSTRINGSTART 462
#define VALUESSTRINGEND 463
#define VARSTART 464
#define VAREND 465
#define VARIABLESSTART 466
#define VARIABLESEND 467
#define VARIDXSTART 468
#define VARIDXEND 469
#define DUMMY 470




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
	double dval;
	int ival;
	char* sval;
}
/* Line 1529 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
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


