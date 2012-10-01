
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




#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSConfig.h"
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
     DUMMY = 493
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
#define DUMMY 493




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
std::string osol_errmsg;
bool suppressFurtherErrorMessages;
bool ignoreDataAfterErrors;

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
#define YYNTOKENS  243
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  830
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1234
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1695

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   493

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   240,
     242,     2,     2,   241,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   239,     2,     2,     2,     2,     2,     2,     2,
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
     235,   236,   237,   238
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    16,    18,    20,
      22,    24,    28,    30,    32,    33,    40,    41,    44,    46,
      48,    50,    53,    55,    59,    61,    63,    66,    68,    70,
      72,    74,    76,    78,    80,    82,    84,    86,    90,    92,
      94,    96,    98,   100,   104,   106,   108,   110,   112,   114,
     118,   120,   122,   124,   126,   128,   132,   134,   136,   138,
     140,   142,   146,   147,   150,   152,   154,   156,   159,   161,
     165,   167,   169,   172,   174,   176,   178,   180,   182,   184,
     186,   188,   190,   192,   194,   197,   199,   201,   203,   206,
     208,   212,   214,   217,   219,   221,   223,   226,   228,   232,
     234,   237,   239,   241,   243,   246,   248,   252,   254,   258,
     260,   261,   263,   267,   269,   271,   274,   276,   280,   282,
     285,   287,   289,   291,   294,   296,   300,   302,   305,   307,
     309,   311,   314,   316,   320,   322,   325,   327,   329,   331,
     334,   336,   340,   342,   345,   347,   349,   351,   354,   356,
     360,   362,   365,   367,   369,   371,   374,   376,   380,   382,
     386,   388,   389,   391,   395,   397,   399,   402,   404,   408,
     410,   414,   416,   418,   420,   422,   425,   427,   431,   433,
     435,   438,   442,   444,   446,   447,   450,   452,   454,   456,
     459,   461,   462,   465,   467,   469,   471,   474,   476,   480,
     482,   484,   487,   489,   491,   493,   495,   497,   501,   503,
     505,   506,   509,   511,   513,   517,   519,   523,   525,   527,
     528,   531,   533,   535,   539,   541,   545,   547,   549,   550,
     553,   555,   557,   561,   563,   567,   569,   570,   572,   576,
     578,   582,   584,   586,   588,   590,   593,   595,   599,   601,
     603,   606,   610,   612,   614,   615,   618,   620,   622,   624,
     627,   629,   630,   633,   635,   637,   639,   642,   644,   648,
     650,   652,   655,   657,   659,   662,   664,   666,   668,   671,
     673,   677,   679,   683,   685,   687,   689,   691,   694,   696,
     700,   702,   704,   707,   711,   713,   715,   716,   719,   721,
     723,   725,   728,   730,   731,   734,   736,   738,   740,   743,
     745,   749,   751,   753,   756,   758,   760,   762,   764,   766,
     768,   770,   772,   774,   776,   778,   780,   782,   784,   786,
     790,   792,   793,   795,   797,   799,   802,   804,   808,   810,
     812,   815,   817,   819,   821,   824,   826,   830,   832,   836,
     838,   840,   842,   844,   847,   849,   853,   855,   858,   863,
     867,   869,   871,   873,   876,   878,   882,   886,   888,   890,
     892,   895,   897,   901,   905,   907,   909,   911,   914,   916,
     920,   924,   926,   928,   930,   933,   935,   939,   943,   945,
     947,   949,   951,   954,   956,   960,   962,   965,   967,   971,
     973,   975,   977,   979,   982,   984,   988,   990,   993,   995,
     999,  1001,  1003,  1005,  1007,  1010,  1012,  1016,  1018,  1021,
    1023,  1027,  1029,  1031,  1033,  1035,  1038,  1040,  1044,  1046,
    1049,  1051,  1055,  1057,  1059,  1061,  1063,  1066,  1068,  1072,
    1076,  1078,  1080,  1082,  1084,  1087,  1089,  1093,  1097,  1099,
    1101,  1103,  1105,  1108,  1110,  1114,  1116,  1119,  1124,  1128,
    1130,  1132,  1134,  1136,  1139,  1141,  1145,  1147,  1149,  1152,
    1156,  1158,  1160,  1161,  1164,  1166,  1168,  1170,  1173,  1175,
    1176,  1180,  1182,  1184,  1185,  1188,  1190,  1192,  1194,  1196,
    1198,  1200,  1204,  1209,  1210,  1214,  1216,  1218,  1219,  1221,
    1223,  1225,  1227,  1231,  1238,  1239,  1243,  1245,  1247,  1249,
    1251,  1254,  1256,  1260,  1262,  1264,  1267,  1271,  1273,  1275,
    1276,  1279,  1281,  1283,  1285,  1288,  1290,  1291,  1295,  1297,
    1299,  1301,  1303,  1306,  1308,  1312,  1314,  1316,  1319,  1323,
    1325,  1327,  1328,  1331,  1333,  1335,  1337,  1340,  1342,  1343,
    1346,  1348,  1350,  1352,  1354,  1358,  1366,  1367,  1371,  1373,
    1375,  1377,  1379,  1381,  1385,  1387,  1388,  1392,  1394,  1396,
    1398,  1400,  1402,  1406,  1408,  1409,  1413,  1415,  1417,  1419,
    1421,  1423,  1427,  1429,  1430,  1434,  1436,  1438,  1440,  1442,
    1444,  1448,  1450,  1451,  1455,  1457,  1459,  1461,  1463,  1465,
    1469,  1471,  1472,  1476,  1478,  1480,  1482,  1484,  1486,  1490,
    1492,  1493,  1497,  1499,  1501,  1503,  1505,  1507,  1511,  1513,
    1514,  1518,  1520,  1522,  1524,  1526,  1529,  1531,  1535,  1537,
    1539,  1542,  1546,  1548,  1550,  1551,  1554,  1556,  1558,  1560,
    1563,  1565,  1566,  1570,  1572,  1577,  1579,  1581,  1584,  1586,
    1590,  1592,  1595,  1599,  1601,  1603,  1604,  1607,  1609,  1611,
    1613,  1615,  1617,  1620,  1622,  1626,  1627,  1630,  1634,  1636,
    1638,  1639,  1642,  1644,  1646,  1648,  1650,  1652,  1654,  1656,
    1658,  1660,  1662,  1664,  1666,  1669,  1671,  1675,  1677,  1679,
    1681,  1684,  1688,  1690,  1692,  1693,  1696,  1698,  1700,  1702,
    1704,  1706,  1708,  1711,  1713,  1714,  1718,  1720,  1722,  1723,
    1725,  1727,  1729,  1731,  1735,  1740,  1741,  1745,  1747,  1749,
    1751,  1753,  1756,  1758,  1762,  1764,  1766,  1769,  1773,  1775,
    1777,  1778,  1781,  1783,  1785,  1787,  1790,  1792,  1793,  1797,
    1799,  1801,  1803,  1805,  1808,  1810,  1814,  1816,  1818,  1821,
    1825,  1827,  1829,  1830,  1833,  1835,  1837,  1839,  1841,  1844,
    1846,  1847,  1850,  1852,  1854,  1856,  1858,  1862,  1870,  1871,
    1875,  1877,  1879,  1881,  1883,  1885,  1889,  1891,  1892,  1896,
    1898,  1900,  1902,  1904,  1906,  1910,  1912,  1913,  1917,  1919,
    1921,  1923,  1925,  1927,  1931,  1933,  1934,  1938,  1940,  1942,
    1944,  1946,  1948,  1952,  1954,  1955,  1959,  1961,  1963,  1965,
    1967,  1969,  1973,  1975,  1976,  1980,  1982,  1984,  1986,  1988,
    1990,  1994,  1996,  1997,  2001,  2003,  2005,  2007,  2009,  2011,
    2015,  2017,  2018,  2021,  2025,  2027,  2029,  2030,  2033,  2035,
    2037,  2039,  2041,  2043,  2045,  2047,  2049,  2051,  2053,  2055,
    2057,  2060,  2062,  2066,  2068,  2070,  2072,  2075,  2079,  2081,
    2083,  2084,  2087,  2089,  2091,  2093,  2095,  2097,  2099,  2102,
    2104,  2105,  2109,  2111,  2113,  2114,  2116,  2118,  2120,  2122,
    2126,  2131,  2132,  2136,  2138,  2140,  2142,  2144,  2147,  2149,
    2153,  2155,  2157,  2160,  2164,  2166,  2168,  2169,  2172,  2174,
    2176,  2178,  2181,  2183,  2184,  2188,  2190,  2192,  2194,  2196,
    2199,  2201,  2205,  2207,  2209,  2212,  2216,  2218,  2220,  2221,
    2224,  2226,  2228,  2230,  2232,  2235,  2237,  2238,  2241,  2243,
    2245,  2247,  2249,  2253,  2261,  2262,  2266,  2268,  2270,  2272,
    2274,  2276,  2280,  2282,  2283,  2287,  2289,  2291,  2293,  2295,
    2297,  2301,  2303,  2304,  2308,  2310,  2312,  2314,  2316,  2318,
    2322,  2324,  2325,  2329,  2331,  2333,  2335,  2337,  2339,  2343,
    2345,  2346,  2350,  2352,  2354,  2356,  2358,  2360,  2364,  2366,
    2367,  2371,  2373,  2375,  2377,  2379,  2381,  2385,  2387,  2388,
    2392,  2394,  2396,  2398,  2400,  2402,  2406,  2408,  2409,  2412,
    2416,  2418,  2420,  2421,  2424,  2426,  2428,  2430,  2432,  2434,
    2436,  2438,  2440,  2442,  2444,  2446,  2448,  2451,  2453,  2457,
    2459,  2461,  2463,  2466,  2470,  2472,  2474,  2475,  2478,  2480,
    2482,  2484,  2486,  2488,  2490,  2493,  2495,  2496,  2500,  2502,
    2504,  2506,  2508,  2510,  2514,  2515,  2518,  2522,  2524,  2526,
    2528,  2531,  2533,  2535,  2537,  2539,  2541,  2543,  2545,  2547,
    2549,  2552,  2554,  2558,  2560,  2562,  2565,  2567,  2569,  2571,
    2573,  2575,  2579,  2581,  2583,  2586,  2591,  2595,  2597,  2599,
    2600,  2603,  2605,  2607,  2609,  2613,  2617,  2621,  2624,  2626,
    2628,  2630,  2632,  2634,  2638,  2640,  2642,  2644,  2646,  2650,
    2652,  2654,  2656,  2658,  2662,  2664,  2666,  2668,  2670,  2674,
    2676,  2681,  2683,  2685,  2690,  2692,  2694,  2696,  2698,  2702,
    2704,  2706,  2708,  2710,  2715,  2717,  2719,  2721,  2723,  2727,
    2729,  2731,  2733,  2735,  2739,  2741,  2743,  2745,  2747,  2751,
    2753,  2755,  2760,  2762,  2764,  2766,  2768,  2772,  2774,  2776,
    2778,  2780,  2784,  2786,  2788,  2790,  2792,  2797,  2799,  2801,
    2803,  2805,  2809,  2811,  2813,  2815,  2817,  2821,  2823,  2825,
    2827,  2829,  2833,  2838,  2843,  2848,  2853,  2858,  2863,  2868,
    2873,  2878,  2883,  2888,  2893,  2898,  2903,  2908,  2913,  2918,
    2923,  2925,  2928,  2932,  2934,  2936,  2937,  2940,  2942,  2944,
    2946,  2948,  2950,  2952,  2956,  2958,  2960,  2962,  2963,  2966,
    2970,  2972,  2974,  2975,  2978,  2980,  2982,  2986,  2990,  2995,
    2997,  2999,  3002,  3004,  3008,  3013,  3018,  3020,  3022,  3025,
    3026,  3029,  3031,  3033,  3035
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     244,     0,    -1,   245,   253,   251,    -1,   246,   247,   248,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   249,    -1,
     250,    -1,    11,    -1,    10,   253,   251,    -1,   252,    -1,
      15,    -1,    -1,   254,   282,   368,   416,   444,   560,    -1,
      -1,   255,   256,    -1,    75,    -1,   257,    -1,   258,    -1,
      10,    76,    -1,    11,    -1,    10,   259,    76,    -1,   260,
      -1,   261,    -1,   260,   261,    -1,   262,    -1,   266,    -1,
     270,    -1,   274,    -1,   278,    -1,   263,    -1,   264,    -1,
     265,    -1,    90,    -1,    89,    -1,    87,     5,    88,    -1,
     267,    -1,   268,    -1,   269,    -1,    94,    -1,    93,    -1,
      91,     5,    92,    -1,   271,    -1,   272,    -1,   273,    -1,
      98,    -1,    97,    -1,    95,     5,    96,    -1,   275,    -1,
     276,    -1,   277,    -1,   102,    -1,   101,    -1,    99,     5,
     100,    -1,   279,    -1,   280,    -1,   281,    -1,   106,    -1,
     105,    -1,   103,     5,   104,    -1,    -1,   283,   284,    -1,
      77,    -1,   285,    -1,   286,    -1,    10,    78,    -1,    11,
      -1,    10,   287,    78,    -1,   288,    -1,   289,    -1,   288,
     289,    -1,   290,    -1,   296,    -1,   302,    -1,   308,    -1,
     316,    -1,   322,    -1,   328,    -1,   334,    -1,   340,    -1,
     346,    -1,   354,    -1,   291,   292,    -1,   107,    -1,   293,
      -1,   294,    -1,    10,   108,    -1,    11,    -1,    10,   295,
     108,    -1,     4,    -1,   297,   298,    -1,   109,    -1,   299,
      -1,   300,    -1,    10,   110,    -1,    11,    -1,    10,   301,
     110,    -1,     4,    -1,   303,   304,    -1,   111,    -1,   305,
      -1,   306,    -1,    10,   112,    -1,    11,    -1,    10,   307,
     112,    -1,     4,    -1,   309,   310,   312,    -1,   113,    -1,
      -1,   311,    -1,    74,     3,     8,    -1,   313,    -1,   314,
      -1,    10,   114,    -1,    11,    -1,    10,   315,   114,    -1,
       4,    -1,   317,   318,    -1,   115,    -1,   319,    -1,   320,
      -1,    10,   116,    -1,    11,    -1,    10,   321,   116,    -1,
       4,    -1,   323,   324,    -1,   117,    -1,   325,    -1,   326,
      -1,    10,   118,    -1,    11,    -1,    10,   327,   118,    -1,
       4,    -1,   329,   330,    -1,   119,    -1,   331,    -1,   332,
      -1,    10,   120,    -1,    11,    -1,    10,   333,   120,    -1,
       4,    -1,   335,   336,    -1,   121,    -1,   337,    -1,   338,
      -1,    10,   122,    -1,    11,    -1,    10,   339,   122,    -1,
       4,    -1,   341,   342,    -1,   123,    -1,   343,    -1,   344,
      -1,    10,   124,    -1,    11,    -1,    10,   345,   124,    -1,
       4,    -1,   347,   348,   350,    -1,   125,    -1,    -1,   349,
      -1,    73,     3,     8,    -1,   351,    -1,   352,    -1,    10,
     126,    -1,    11,    -1,    10,   353,   126,    -1,     4,    -1,
     355,   356,   357,    -1,   127,    -1,  1036,    -1,   358,    -1,
     359,    -1,    10,   128,    -1,    11,    -1,    10,   360,   128,
      -1,   361,    -1,   362,    -1,   361,   362,    -1,   363,   364,
     367,    -1,   129,    -1,   365,    -1,    -1,   365,   366,    -1,
     987,    -1,  1018,    -1,   966,    -1,    10,   130,    -1,    11,
      -1,    -1,   369,   370,    -1,    79,    -1,   371,    -1,   372,
      -1,    10,    80,    -1,    11,    -1,    10,   373,    80,    -1,
     374,    -1,   375,    -1,   374,   375,    -1,   376,    -1,   383,
      -1,   390,    -1,   397,    -1,   402,    -1,   377,   378,   381,
      -1,   131,    -1,   379,    -1,    -1,   379,   380,    -1,  1014,
      -1,   966,    -1,    10,   382,   132,    -1,  1069,    -1,   384,
     385,   388,    -1,   133,    -1,   386,    -1,    -1,   386,   387,
      -1,  1014,    -1,   966,    -1,    10,   389,   134,    -1,  1069,
      -1,   391,   392,   395,    -1,   135,    -1,   393,    -1,    -1,
     393,   394,    -1,  1014,    -1,   966,    -1,    10,   396,   136,
      -1,  1069,    -1,   398,   399,   400,    -1,   137,    -1,    -1,
     966,    -1,    10,   401,   138,    -1,     6,    -1,   403,   404,
     405,    -1,   127,    -1,  1036,    -1,   406,    -1,   407,    -1,
      10,   128,    -1,    11,    -1,    10,   408,   128,    -1,   409,
      -1,   410,    -1,   409,   410,    -1,   411,   412,   415,    -1,
     129,    -1,   413,    -1,    -1,   413,   414,    -1,   987,    -1,
    1018,    -1,   966,    -1,    10,   130,    -1,    11,    -1,    -1,
     417,   418,    -1,    81,    -1,   419,    -1,   420,    -1,    10,
      82,    -1,    11,    -1,    10,   421,    82,    -1,   422,    -1,
     423,    -1,   422,   423,    -1,   424,    -1,   430,    -1,   425,
     426,    -1,   139,    -1,   427,    -1,   428,    -1,    10,   140,
      -1,    11,    -1,    10,   429,   140,    -1,     4,    -1,   431,
     432,   433,    -1,   127,    -1,  1036,    -1,   434,    -1,   435,
      -1,    10,   128,    -1,    11,    -1,    10,   436,   128,    -1,
     437,    -1,   438,    -1,   437,   438,    -1,   439,   440,   443,
      -1,   129,    -1,   441,    -1,    -1,   441,   442,    -1,   987,
      -1,  1018,    -1,   966,    -1,    10,   130,    -1,    11,    -1,
      -1,   445,   446,    -1,    83,    -1,   447,    -1,   448,    -1,
      10,    84,    -1,    11,    -1,    10,   449,    84,    -1,   450,
      -1,   451,    -1,   450,   451,    -1,   452,    -1,   460,    -1,
     466,    -1,   474,    -1,   479,    -1,   484,    -1,   489,    -1,
     494,    -1,   502,    -1,   518,    -1,   510,    -1,   526,    -1,
     532,    -1,   538,    -1,   546,    -1,   453,   454,   455,    -1,
     141,    -1,    -1,  1014,    -1,   456,    -1,   457,    -1,    10,
     142,    -1,    11,    -1,    10,   458,   142,    -1,   459,    -1,
    1069,    -1,   461,   462,    -1,   143,    -1,   463,    -1,   464,
      -1,    10,   144,    -1,    11,    -1,    10,   465,   144,    -1,
       4,    -1,   467,   468,   469,    -1,   145,    -1,  1031,    -1,
     470,    -1,   471,    -1,    10,   146,    -1,    11,    -1,    10,
     472,   146,    -1,   473,    -1,   472,   473,    -1,   115,    10,
       4,   116,    -1,   475,  1039,   476,    -1,   147,    -1,   477,
      -1,   478,    -1,    10,   148,    -1,    11,    -1,    10,   947,
     148,    -1,   480,  1039,   481,    -1,   149,    -1,   482,    -1,
     483,    -1,    10,   150,    -1,    11,    -1,    10,   947,   150,
      -1,   485,  1039,   486,    -1,   155,    -1,   487,    -1,   488,
      -1,    10,   156,    -1,    11,    -1,    10,   947,   156,    -1,
     490,  1039,   491,    -1,   157,    -1,   492,    -1,   493,    -1,
      10,   158,    -1,    11,    -1,    10,   947,   158,    -1,   495,
     496,   497,    -1,   163,    -1,  1038,    -1,   498,    -1,   499,
      -1,    10,   164,    -1,    11,    -1,    10,   500,   164,    -1,
     501,    -1,   500,   501,    -1,   949,    -1,   503,   504,   505,
      -1,   165,    -1,  1038,    -1,   506,    -1,   507,    -1,    10,
     166,    -1,    11,    -1,    10,   508,   166,    -1,   509,    -1,
     508,   509,    -1,   949,    -1,   511,   512,   513,    -1,   169,
      -1,  1038,    -1,   514,    -1,   515,    -1,    10,   170,    -1,
      11,    -1,    10,   516,   170,    -1,   517,    -1,   516,   517,
      -1,   949,    -1,   519,   520,   521,    -1,   167,    -1,  1038,
      -1,   522,    -1,   523,    -1,    10,   168,    -1,    11,    -1,
      10,   524,   168,    -1,   525,    -1,   524,   525,    -1,   949,
      -1,   527,   528,   529,    -1,   161,    -1,  1039,    -1,   530,
      -1,   531,    -1,    10,   162,    -1,    11,    -1,    10,   947,
     162,    -1,   533,   534,   535,    -1,   159,    -1,  1039,    -1,
     536,    -1,   537,    -1,    10,   160,    -1,    11,    -1,    10,
     947,   160,    -1,   539,   540,   541,    -1,   171,    -1,  1040,
      -1,   542,    -1,   543,    -1,    10,   172,    -1,    11,    -1,
      10,   544,   172,    -1,   545,    -1,   544,   545,    -1,   173,
      10,     4,   174,    -1,   547,   548,   549,    -1,   127,    -1,
    1036,    -1,   550,    -1,   551,    -1,    10,   128,    -1,    11,
      -1,    10,   552,   128,    -1,   553,    -1,   554,    -1,   553,
     554,    -1,   555,   556,   559,    -1,   129,    -1,   557,    -1,
      -1,   557,   558,    -1,   987,    -1,  1018,    -1,   966,    -1,
      10,   130,    -1,    11,    -1,    -1,   561,   562,   565,    -1,
      85,    -1,   563,    -1,    -1,   563,   564,    -1,  1043,    -1,
    1027,    -1,  1033,    -1,   566,    -1,   567,    -1,    11,    -1,
      10,   568,    86,    -1,   569,   707,   816,   925,    -1,    -1,
     570,   571,   573,    -1,   175,    -1,   572,    -1,    -1,  1037,
      -1,   574,    -1,   575,    -1,    11,    -1,    10,   576,   176,
      -1,   577,   591,   605,   660,   674,   689,    -1,    -1,   578,
     579,   580,    -1,   177,    -1,  1042,    -1,   581,    -1,   582,
      -1,    10,   178,    -1,    11,    -1,    10,   583,   178,    -1,
     584,    -1,   585,    -1,   584,   585,    -1,   586,   587,   590,
      -1,   179,    -1,   588,    -1,    -1,   588,   589,    -1,   976,
      -1,   987,    -1,  1018,    -1,    10,   180,    -1,    11,    -1,
      -1,   592,   593,   594,    -1,   181,    -1,  1042,    -1,   595,
      -1,   596,    -1,    10,   182,    -1,    11,    -1,    10,   597,
     182,    -1,   598,    -1,   599,    -1,   598,   599,    -1,   600,
     601,   604,    -1,   179,    -1,   602,    -1,    -1,   602,   603,
      -1,   976,    -1,   987,    -1,  1018,    -1,    10,   180,    -1,
      11,    -1,    -1,   606,   607,    -1,   183,    -1,   608,    -1,
     609,    -1,    11,    -1,    10,   610,   184,    -1,   611,   618,
     625,   632,   639,   646,   653,    -1,    -1,   612,   613,   614,
      -1,   185,    -1,  1028,    -1,   615,    -1,   616,    -1,    11,
      -1,    10,   617,   186,    -1,  1054,    -1,    -1,   619,   620,
     621,    -1,   189,    -1,  1028,    -1,   622,    -1,   623,    -1,
      11,    -1,    10,   624,   190,    -1,  1054,    -1,    -1,   626,
     627,   628,    -1,   187,    -1,  1028,    -1,   629,    -1,   630,
      -1,    11,    -1,    10,   631,   188,    -1,  1054,    -1,    -1,
     633,   634,   635,    -1,   191,    -1,  1028,    -1,   636,    -1,
     637,    -1,    11,    -1,    10,   638,   192,    -1,  1054,    -1,
      -1,   640,   641,   642,    -1,   195,    -1,  1028,    -1,   643,
      -1,   644,    -1,    11,    -1,    10,   645,   196,    -1,  1054,
      -1,    -1,   647,   648,   649,    -1,   193,    -1,  1028,    -1,
     650,    -1,   651,    -1,    11,    -1,    10,   652,   194,    -1,
    1054,    -1,    -1,   654,   655,   656,    -1,   197,    -1,  1028,
      -1,   657,    -1,   658,    -1,    11,    -1,    10,   659,   198,
      -1,  1054,    -1,    -1,   661,   662,   663,    -1,   199,    -1,
    1042,    -1,   664,    -1,   665,    -1,    10,   200,    -1,    11,
      -1,    10,   666,   200,    -1,   667,    -1,   668,    -1,   667,
     668,    -1,   669,   670,   673,    -1,   179,    -1,   671,    -1,
      -1,   671,   672,    -1,   976,    -1,   987,    -1,  1018,    -1,
      10,   180,    -1,    11,    -1,    -1,   675,   676,   677,    -1,
     201,    -1,    29,     8,     6,     8,    -1,   678,    -1,   679,
      -1,    10,   202,    -1,    11,    -1,    10,   680,   202,    -1,
     681,    -1,   680,   681,    -1,   682,   683,   686,    -1,   203,
      -1,   684,    -1,    -1,   684,   685,    -1,   999,    -1,  1042,
      -1,   974,    -1,   687,    -1,   688,    -1,    10,   204,    -1,
      11,    -1,    10,   667,   204,    -1,    -1,   689,   690,    -1,
     691,   692,   695,    -1,   129,    -1,   693,    -1,    -1,   693,
     694,    -1,  1042,    -1,  1029,    -1,   987,    -1,  1018,    -1,
     995,    -1,   958,    -1,  1002,    -1,  1022,    -1,   970,    -1,
     966,    -1,   696,    -1,   697,    -1,    10,   130,    -1,    11,
      -1,    10,   698,   130,    -1,   699,    -1,  1044,    -1,   700,
      -1,   699,   700,    -1,   701,   702,   705,    -1,   179,    -1,
     703,    -1,    -1,   703,   704,    -1,   976,    -1,   987,    -1,
    1018,    -1,   979,    -1,  1006,    -1,   706,    -1,    10,   180,
      -1,    11,    -1,    -1,   708,   709,   711,    -1,   205,    -1,
     710,    -1,    -1,  1035,    -1,   712,    -1,   713,    -1,    11,
      -1,    10,   714,   206,    -1,   715,   729,   743,   798,    -1,
      -1,   716,   717,   718,    -1,   207,    -1,  1032,    -1,   719,
      -1,   720,    -1,    10,   208,    -1,    11,    -1,    10,   721,
     208,    -1,   722,    -1,   723,    -1,   722,   723,    -1,   724,
     725,   728,    -1,   209,    -1,   726,    -1,    -1,   726,   727,
      -1,   976,    -1,   987,    -1,  1018,    -1,    10,   210,    -1,
      11,    -1,    -1,   730,   731,   732,    -1,   211,    -1,  1032,
      -1,   733,    -1,   734,    -1,    10,   212,    -1,    11,    -1,
      10,   735,   212,    -1,   736,    -1,   737,    -1,   736,   737,
      -1,   738,   739,   742,    -1,   209,    -1,   740,    -1,    -1,
     740,   741,    -1,   976,    -1,   987,    -1,   979,    -1,  1006,
      -1,    10,   210,    -1,    11,    -1,    -1,   744,   745,    -1,
     183,    -1,   746,    -1,   747,    -1,    11,    -1,    10,   748,
     184,    -1,   749,   756,   763,   770,   777,   784,   791,    -1,
      -1,   750,   751,   752,    -1,   185,    -1,  1028,    -1,   753,
      -1,   754,    -1,    11,    -1,    10,   755,   186,    -1,  1054,
      -1,    -1,   757,   758,   759,    -1,   189,    -1,  1028,    -1,
     760,    -1,   761,    -1,    11,    -1,    10,   762,   190,    -1,
    1054,    -1,    -1,   764,   765,   766,    -1,   187,    -1,  1028,
      -1,   767,    -1,   768,    -1,    11,    -1,    10,   769,   188,
      -1,  1054,    -1,    -1,   771,   772,   773,    -1,   191,    -1,
    1028,    -1,   774,    -1,   775,    -1,    11,    -1,    10,   776,
     192,    -1,  1054,    -1,    -1,   778,   779,   780,    -1,   195,
      -1,  1028,    -1,   781,    -1,   782,    -1,    11,    -1,    10,
     783,   196,    -1,  1054,    -1,    -1,   785,   786,   787,    -1,
     193,    -1,  1028,    -1,   788,    -1,   789,    -1,    11,    -1,
      10,   790,   194,    -1,  1054,    -1,    -1,   792,   793,   794,
      -1,   197,    -1,  1028,    -1,   795,    -1,   796,    -1,    11,
      -1,    10,   797,   198,    -1,  1054,    -1,    -1,   798,   799,
      -1,   800,   801,   804,    -1,   129,    -1,   802,    -1,    -1,
     802,   803,    -1,  1032,    -1,  1029,    -1,   987,    -1,  1018,
      -1,   995,    -1,   958,    -1,  1002,    -1,   991,    -1,   970,
      -1,   966,    -1,   805,    -1,   806,    -1,    10,   130,    -1,
      11,    -1,    10,   807,   130,    -1,   808,    -1,  1044,    -1,
     809,    -1,   808,   809,    -1,   810,   811,   814,    -1,   209,
      -1,   812,    -1,    -1,   812,   813,    -1,   976,    -1,   987,
      -1,  1018,    -1,   979,    -1,  1006,    -1,   815,    -1,    10,
     210,    -1,    11,    -1,    -1,   817,   818,   820,    -1,   213,
      -1,   819,    -1,    -1,  1034,    -1,   821,    -1,   822,    -1,
      11,    -1,    10,   823,   214,    -1,   824,   838,   852,   907,
      -1,    -1,   825,   826,   827,    -1,   215,    -1,  1026,    -1,
     828,    -1,   829,    -1,    10,   216,    -1,    11,    -1,    10,
     830,   216,    -1,   831,    -1,   832,    -1,   831,   832,    -1,
     833,   834,   837,    -1,   217,    -1,   835,    -1,    -1,   835,
     836,    -1,   976,    -1,   987,    -1,  1018,    -1,    10,   218,
      -1,    11,    -1,    -1,   839,   840,   841,    -1,   219,    -1,
    1026,    -1,   842,    -1,   843,    -1,    10,   220,    -1,    11,
      -1,    10,   844,   220,    -1,   845,    -1,   846,    -1,   845,
     846,    -1,   847,   848,   851,    -1,   217,    -1,   849,    -1,
      -1,   849,   850,    -1,   976,    -1,   987,    -1,   983,    -1,
    1010,    -1,    10,   218,    -1,    11,    -1,    -1,   853,   854,
      -1,   183,    -1,   855,    -1,   856,    -1,    11,    -1,    10,
     857,   184,    -1,   858,   865,   872,   879,   886,   893,   900,
      -1,    -1,   859,   860,   861,    -1,   185,    -1,  1028,    -1,
     862,    -1,   863,    -1,    11,    -1,    10,   864,   186,    -1,
    1054,    -1,    -1,   866,   867,   868,    -1,   189,    -1,  1028,
      -1,   869,    -1,   870,    -1,    11,    -1,    10,   871,   190,
      -1,  1054,    -1,    -1,   873,   874,   875,    -1,   187,    -1,
    1028,    -1,   876,    -1,   877,    -1,    11,    -1,    10,   878,
     188,    -1,  1054,    -1,    -1,   880,   881,   882,    -1,   191,
      -1,  1028,    -1,   883,    -1,   884,    -1,    11,    -1,    10,
     885,   192,    -1,  1054,    -1,    -1,   887,   888,   889,    -1,
     195,    -1,  1028,    -1,   890,    -1,   891,    -1,    11,    -1,
      10,   892,   196,    -1,  1054,    -1,    -1,   894,   895,   896,
      -1,   193,    -1,  1028,    -1,   897,    -1,   898,    -1,    11,
      -1,    10,   899,   194,    -1,  1054,    -1,    -1,   901,   902,
     903,    -1,   197,    -1,  1028,    -1,   904,    -1,   905,    -1,
      11,    -1,    10,   906,   198,    -1,  1054,    -1,    -1,   907,
     908,    -1,   909,   910,   913,    -1,   129,    -1,   911,    -1,
      -1,   911,   912,    -1,  1026,    -1,  1029,    -1,   987,    -1,
    1018,    -1,   995,    -1,   958,    -1,  1002,    -1,   962,    -1,
     970,    -1,   966,    -1,   914,    -1,   915,    -1,    10,   130,
      -1,    11,    -1,    10,   916,   130,    -1,   917,    -1,  1044,
      -1,   918,    -1,   917,   918,    -1,   919,   920,   923,    -1,
     217,    -1,   921,    -1,    -1,   921,   922,    -1,   976,    -1,
     987,    -1,  1018,    -1,   979,    -1,  1006,    -1,   924,    -1,
      10,   218,    -1,    11,    -1,    -1,   926,   927,   928,    -1,
     221,    -1,  1041,    -1,   929,    -1,   930,    -1,    11,    -1,
      10,   931,   222,    -1,    -1,   931,   932,    -1,   933,   934,
     937,    -1,   223,    -1,   935,    -1,   936,    -1,   935,   936,
      -1,   987,    -1,  1018,    -1,   995,    -1,   958,    -1,  1002,
      -1,   966,    -1,  1030,    -1,   938,    -1,   939,    -1,    10,
     224,    -1,    11,    -1,    10,   940,   224,    -1,   941,    -1,
     942,    -1,   941,   942,    -1,   943,    -1,   944,    -1,   945,
      -1,   230,    -1,   227,    -1,   228,   946,   229,    -1,     5,
      -1,   948,    -1,   947,   948,    -1,   151,    10,     4,   152,
      -1,   950,   951,   957,    -1,   153,    -1,   952,    -1,    -1,
     952,   953,    -1,   954,    -1,   955,    -1,   956,    -1,    21,
       3,     8,    -1,    22,     3,     8,    -1,    23,     3,     8,
      -1,    10,   154,    -1,    11,    -1,   959,    -1,   960,    -1,
     961,    -1,    57,    -1,    24,     3,  1070,    -1,   963,    -1,
     964,    -1,   965,    -1,    48,    -1,    47,     3,     8,    -1,
     967,    -1,   968,    -1,   969,    -1,    58,    -1,    46,     3,
    1070,    -1,   971,    -1,   972,    -1,   973,    -1,    50,    -1,
      49,     3,     8,    -1,   975,    -1,    26,     8,  1069,     8,
      -1,   977,    -1,   978,    -1,    42,  1070,     6,  1070,    -1,
     980,    -1,   981,    -1,   982,    -1,    61,    -1,    63,     3,
    1070,    -1,   984,    -1,   985,    -1,   986,    -1,    65,    -1,
      67,  1070,  1069,  1070,    -1,   988,    -1,   989,    -1,   990,
      -1,    56,    -1,    41,     3,  1070,    -1,   992,    -1,   993,
      -1,   994,    -1,    52,    -1,    51,     3,     8,    -1,   996,
      -1,   997,    -1,   998,    -1,    70,    -1,    69,     3,  1070,
      -1,  1000,    -1,  1001,    -1,    43,  1070,     6,  1070,    -1,
    1003,    -1,  1004,    -1,  1005,    -1,    55,    -1,    25,     3,
       8,    -1,  1007,    -1,  1008,    -1,  1009,    -1,    62,    -1,
      64,     3,  1070,    -1,  1011,    -1,  1012,    -1,  1013,    -1,
      66,    -1,    68,  1070,  1069,  1070,    -1,  1015,    -1,  1016,
      -1,  1017,    -1,    59,    -1,    45,     3,     8,    -1,  1019,
      -1,  1020,    -1,  1021,    -1,    60,    -1,    44,     3,     8,
      -1,  1023,    -1,  1024,    -1,  1025,    -1,    54,    -1,    53,
       3,     8,    -1,    39,  1070,     6,  1070,    -1,    32,  1070,
       6,  1070,    -1,    40,  1070,     6,  1070,    -1,    17,  1070,
       6,  1070,    -1,    36,  1070,     6,  1070,    -1,    18,     8,
       6,     8,    -1,    38,  1070,     6,  1070,    -1,    31,  1070,
       6,  1070,    -1,    35,  1070,     6,  1070,    -1,    34,  1070,
       6,  1070,    -1,    16,  1070,     6,  1070,    -1,    33,  1070,
       6,  1070,    -1,    20,     8,     6,     8,    -1,    19,     8,
       6,     8,    -1,    27,     8,     6,     8,    -1,    28,  1070,
       6,  1070,    -1,    37,  1070,     6,  1070,    -1,    30,  1070,
       6,  1070,    -1,  1045,    -1,  1044,  1045,    -1,  1046,  1047,
    1050,    -1,   225,    -1,  1048,    -1,    -1,  1048,  1049,    -1,
    1028,    -1,  1018,    -1,   966,    -1,  1051,    -1,  1052,    -1,
      11,    -1,    10,  1053,   226,    -1,  1054,    -1,  1055,    -1,
    1062,    -1,    -1,  1055,  1056,    -1,  1057,  1058,  1061,    -1,
     236,    -1,  1059,    -1,    -1,  1059,  1060,    -1,  1068,    -1,
    1067,    -1,    10,     6,   237,    -1,   231,  1063,  1064,    -1,
     235,  1070,     6,  1070,    -1,  1065,    -1,  1066,    -1,    10,
     232,    -1,    11,    -1,    10,     4,   232,    -1,   233,  1070,
       6,  1070,    -1,   234,  1070,     6,  1070,    -1,     6,    -1,
       7,    -1,  1071,     8,    -1,    -1,  1071,  1072,    -1,   239,
      -1,   240,    -1,   241,    -1,   242,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   171,   171,   172,   174,   181,   191,   191,   193,   193,
     195,   197,   199,   208,   209,   212,   220,   220,   227,   241,
     241,   243,   243,   245,   247,   249,   249,   252,   253,   254,
     255,   256,   258,   266,   266,   268,   268,   270,   276,   285,
     285,   287,   287,   289,   295,   303,   303,   305,   305,   307,
     313,   321,   321,   323,   323,   325,   331,   338,   338,   340,
     340,   342,   353,   353,   355,   371,   371,   373,   373,   375,
     377,   379,   379,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   396,   398,   407,   407,   409,   409,
     411,   413,   423,   425,   432,   432,   434,   434,   436,   438,
     448,   450,   456,   456,   458,   458,   460,   462,   472,   479,
     487,   488,   495,   501,   501,   503,   503,   505,   507,   515,
     517,   523,   523,   525,   525,   527,   529,   538,   540,   547,
     547,   549,   549,   551,   553,   563,   565,   572,   572,   574,
     574,   576,   578,   588,   590,   596,   596,   598,   598,   600,
     602,   612,   614,   620,   620,   622,   622,   624,   626,   636,
     643,   652,   653,   659,   666,   666,   668,   668,   670,   672,
     680,   686,   696,   704,   709,   715,   715,   717,   719,   723,
     723,   725,   733,   752,   758,   758,   761,   765,   766,   769,
     769,   778,   778,   780,   790,   790,   792,   792,   794,   796,
     798,   798,   801,   802,   803,   804,   805,   809,   811,   821,
     823,   823,   826,   827,   830,   832,   840,   842,   852,   854,
     854,   857,   858,   861,   863,   872,   874,   884,   886,   886,
     889,   890,   893,   895,   904,   906,   914,   915,   917,   919,
     930,   936,   946,   954,   958,   963,   963,   965,   967,   971,
     971,   973,   981,  1000,  1005,  1005,  1008,  1013,  1014,  1017,
    1017,  1026,  1026,  1028,  1035,  1035,  1037,  1037,  1039,  1041,
    1043,  1043,  1046,  1047,  1051,  1053,  1059,  1059,  1061,  1061,
    1063,  1065,  1076,  1082,  1092,  1100,  1104,  1109,  1109,  1111,
    1113,  1117,  1117,  1119,  1127,  1146,  1151,  1151,  1154,  1159,
    1160,  1163,  1163,  1171,  1171,  1173,  1193,  1193,  1195,  1195,
    1197,  1199,  1201,  1201,  1204,  1205,  1206,  1207,  1208,  1209,
    1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1223,
    1229,  1239,  1240,  1242,  1242,  1244,  1244,  1246,  1248,  1250,
    1257,  1259,  1265,  1265,  1267,  1267,  1269,  1271,  1281,  1292,
    1302,  1304,  1304,  1306,  1306,  1308,  1317,  1317,  1319,  1340,
    1351,  1361,  1361,  1363,  1363,  1365,  1376,  1387,  1397,  1397,
    1399,  1399,  1401,  1412,  1423,  1433,  1433,  1435,  1435,  1437,
    1448,  1459,  1469,  1469,  1471,  1471,  1473,  1484,  1500,  1510,
    1512,  1512,  1514,  1514,  1516,  1525,  1525,  1527,  1531,  1547,
    1557,  1559,  1559,  1561,  1561,  1563,  1572,  1572,  1574,  1578,
    1594,  1604,  1606,  1606,  1608,  1608,  1610,  1619,  1619,  1621,
    1625,  1641,  1651,  1653,  1653,  1655,  1655,  1657,  1666,  1666,
    1668,  1672,  1683,  1693,  1695,  1695,  1697,  1697,  1699,  1710,
    1721,  1731,  1733,  1733,  1735,  1735,  1737,  1762,  1773,  1783,
    1785,  1785,  1787,  1787,  1789,  1798,  1798,  1800,  1821,  1827,
    1837,  1845,  1849,  1854,  1854,  1856,  1858,  1862,  1862,  1864,
    1872,  1891,  1897,  1897,  1900,  1905,  1906,  1909,  1909,  1917,
    1917,  1919,  1927,  1929,  1929,  1932,  1938,  1944,  1952,  1952,
    1954,  1956,  1958,  1965,  1965,  1967,  1973,  1980,  1980,  1985,
    1985,  1987,  1989,  1991,  2001,  2001,  2016,  2021,  2032,  2040,
    2049,  2049,  2051,  2053,  2055,  2055,  2058,  2063,  2077,  2083,
    2083,  2086,  2098,  2103,  2111,  2111,  2115,  2115,  2130,  2135,
    2146,  2154,  2163,  2163,  2165,  2167,  2169,  2169,  2172,  2177,
    2192,  2198,  2198,  2201,  2213,  2218,  2224,  2224,  2228,  2228,
    2230,  2235,  2235,  2237,  2239,  2241,  2244,  2244,  2255,  2261,
    2268,  2268,  2270,  2272,  2274,  2278,  2278,  2290,  2296,  2303,
    2303,  2305,  2307,  2309,  2313,  2313,  2324,  2330,  2337,  2337,
    2339,  2341,  2343,  2347,  2347,  2358,  2364,  2371,  2371,  2373,
    2375,  2377,  2381,  2381,  2392,  2398,  2405,  2405,  2407,  2409,
    2411,  2415,  2415,  2426,  2432,  2439,  2439,  2441,  2443,  2445,
    2449,  2449,  2460,  2466,  2473,  2473,  2475,  2477,  2479,  2483,
    2483,  2499,  2504,  2515,  2523,  2532,  2532,  2534,  2536,  2542,
    2542,  2544,  2549,  2565,  2571,  2571,  2574,  2586,  2591,  2599,
    2599,  2603,  2603,  2609,  2615,  2623,  2631,  2639,  2639,  2641,
    2643,  2643,  2645,  2664,  2680,  2688,  2688,  2691,  2692,  2701,
    2704,  2704,  2706,  2706,  2708,  2713,  2713,  2715,  2720,  2751,
    2771,  2771,  2774,  2778,  2782,  2783,  2784,  2785,  2786,  2787,
    2788,  2789,  2792,  2792,  2794,  2794,  2796,  2798,  2798,  2800,
    2800,  2803,  2818,  2838,  2840,  2840,  2843,  2853,  2854,  2855,
    2856,  2859,  2861,  2861,  2869,  2869,  2871,  2877,  2884,  2884,
    2889,  2889,  2891,  2893,  2895,  2904,  2904,  2920,  2926,  2938,
    2946,  2955,  2955,  2957,  2959,  2961,  2961,  2964,  2969,  2984,
    2986,  2986,  2989,  3000,  3004,  3011,  3011,  3014,  3014,  3032,
    3037,  3051,  3059,  3068,  3068,  3070,  3072,  3074,  3074,  3077,
    3082,  3100,  3102,  3102,  3105,  3116,  3120,  3126,  3133,  3133,
    3137,  3137,  3139,  3144,  3144,  3146,  3148,  3150,  3153,  3153,
    3164,  3170,  3177,  3177,  3179,  3181,  3183,  3186,  3186,  3197,
    3203,  3210,  3210,  3212,  3214,  3216,  3219,  3219,  3230,  3236,
    3243,  3243,  3245,  3247,  3249,  3252,  3252,  3263,  3269,  3276,
    3276,  3278,  3280,  3282,  3285,  3285,  3296,  3302,  3309,  3309,
    3311,  3313,  3315,  3318,  3318,  3329,  3336,  3343,  3343,  3345,
    3347,  3349,  3353,  3353,  3364,  3370,  3377,  3377,  3379,  3381,
    3383,  3387,  3387,  3389,  3395,  3426,  3447,  3447,  3450,  3454,
    3458,  3459,  3460,  3461,  3462,  3463,  3464,  3465,  3468,  3468,
    3470,  3470,  3472,  3474,  3474,  3476,  3476,  3479,  3494,  3516,
    3518,  3518,  3521,  3531,  3532,  3533,  3534,  3537,  3539,  3539,
    3547,  3547,  3549,  3555,  3562,  3562,  3567,  3567,  3569,  3571,
    3573,  3582,  3582,  3598,  3603,  3614,  3622,  3631,  3631,  3633,
    3635,  3637,  3637,  3640,  3645,  3660,  3666,  3666,  3669,  3680,
    3684,  3691,  3691,  3695,  3695,  3713,  3718,  3731,  3739,  3748,
    3748,  3750,  3752,  3754,  3754,  3757,  3762,  3780,  3786,  3786,
    3789,  3800,  3804,  3808,  3814,  3814,  3818,  3818,  3820,  3825,
    3825,  3827,  3829,  3831,  3834,  3834,  3845,  3851,  3858,  3858,
    3860,  3862,  3864,  3867,  3867,  3878,  3884,  3891,  3891,  3893,
    3895,  3897,  3901,  3901,  3912,  3918,  3925,  3925,  3927,  3929,
    3931,  3935,  3935,  3946,  3952,  3959,  3959,  3961,  3963,  3965,
    3969,  3969,  3980,  3986,  3993,  3993,  3995,  3997,  3999,  4003,
    4003,  4014,  4020,  4027,  4027,  4029,  4031,  4033,  4037,  4037,
    4048,  4054,  4061,  4061,  4063,  4065,  4067,  4071,  4071,  4073,
    4079,  4110,  4130,  4130,  4133,  4137,  4141,  4142,  4143,  4144,
    4145,  4146,  4147,  4148,  4151,  4151,  4153,  4153,  4155,  4157,
    4157,  4159,  4159,  4162,  4177,  4197,  4199,  4199,  4202,  4212,
    4213,  4214,  4215,  4218,  4220,  4220,  4228,  4228,  4234,  4236,
    4244,  4252,  4261,  4263,  4265,  4265,  4269,  4289,  4307,  4313,
    4313,  4316,  4317,  4318,  4319,  4320,  4321,  4322,  4329,  4337,
    4346,  4346,  4348,  4350,  4352,  4352,  4354,  4361,  4372,  4374,
    4374,  4376,  4378,  4395,  4395,  4397,  4419,  4436,  4448,  4453,
    4453,  4456,  4457,  4458,  4460,  4469,  4478,  4487,  4487,  4493,
    4500,  4500,  4502,  4507,  4514,  4520,  4520,  4522,  4525,  4532,
    4539,  4539,  4541,  4544,  4551,  4557,  4557,  4559,  4562,  4570,
    4577,  4584,  4591,  4593,  4599,  4606,  4606,  4608,  4613,  4620,
    4626,  4626,  4628,  4633,  4639,  4646,  4646,  4648,  4653,  4660,
    4666,  4666,  4668,  4671,  4679,  4685,  4685,  4687,  4690,  4697,
    4703,  4705,  4713,  4719,  4719,  4721,  4724,  4731,  4738,  4738,
    4740,  4745,  4752,  4758,  4758,  4760,  4763,  4770,  4776,  4776,
    4778,  4781,  4788,  4794,  4794,  4796,  4799,  4806,  4812,  4812,
    4814,  4817,  4829,  4838,  4847,  4856,  4865,  4874,  4884,  4893,
    4902,  4908,  4914,  4920,  4926,  4940,  4950,  4961,  4967,  4976,
    4996,  4996,  4998,  5016,  5032,  5040,  5040,  5043,  5050,  5051,
    5055,  5055,  5057,  5060,  5062,  5079,  5087,  5089,  5089,  5091,
    5093,  5102,  5104,  5104,  5106,  5106,  5108,  5124,  5126,  5131,
    5131,  5133,  5133,  5136,  5162,  5170,  5184,  5185,  5192,  5194,
    5194,  5196,  5197,  5198,  5199
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
  "MULTATT", "SIZEOFATT", "ELSTART", "ELEND", "DUMMY", "' '", "'\\t'",
  "'\\r'", "'\\n'", "$accept", "osoldoc", "osolStartEmpty", "osolStart",
  "osolAttributes", "osolContent", "osolEmpty", "osolLaden", "osolEnd",
  "osolEnding", "osolBody", "headerElement", "headerElementStart",
  "headerElementContent", "headerElementEmpty", "headerElementLaden",
  "headerElementBody", "headerElementList", "headerChild", "fileName",
  "fileNameContent", "fileNameEmpty", "fileNameLaden", "fileSource",
  "fileSourceContent", "fileSourceEmpty", "fileSourceLaden",
  "fileDescription", "fileDescriptionContent", "fileDescriptionEmpty",
  "fileDescriptionLaden", "fileCreator", "fileCreatorContent",
  "fileCreatorEmpty", "fileCreatorLaden", "fileLicence",
  "fileLicenceContent", "fileLicenceEmpty", "fileLicenceLaden",
  "generalElement", "generalElementStart", "generalElementContent",
  "generalElementEmpty", "generalElementLaden", "generalElementBody",
  "generalElementList", "generalChild", "serviceURI", "serviceURIStart",
  "serviceURIContent", "serviceURIEmpty", "serviceURILaden",
  "serviceURIBody", "serviceName", "serviceNameStart",
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
  "osglIntArrayData", "osglIntVectorElArray", "osglIntVectorEl",
  "osglIntVectorElStart", "osglIntVectorElAttributes",
  "osglIntVectorElAttList", "osglIntVectorElAtt", "osglIntVectorElContent",
  "osglIntVectorBase64", "Base64SizeAttribute", "Base64Content",
  "Base64Empty", "Base64Laden", "osglIncrAttribute", "osglMultAttribute",
  "aNumber", "quote", "xmlWhiteSpace", "xmlWhiteSpaceChar", 0
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
     485,   486,   487,   488,   489,   490,   491,   492,   493,    32,
       9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   243,   244,   244,   245,   246,   247,   247,   248,   248,
     249,   250,   251,   252,   252,   253,   254,   254,   255,   256,
     256,   257,   257,   258,   259,   260,   260,   261,   261,   261,
     261,   261,   262,   263,   263,   264,   264,   265,   266,   267,
     267,   268,   268,   269,   270,   271,   271,   272,   272,   273,
     274,   275,   275,   276,   276,   277,   278,   279,   279,   280,
     280,   281,   282,   282,   283,   284,   284,   285,   285,   286,
     287,   288,   288,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   290,   291,   292,   292,   293,   293,
     294,   295,   296,   297,   298,   298,   299,   299,   300,   301,
     302,   303,   304,   304,   305,   305,   306,   307,   308,   309,
     310,   310,   311,   312,   312,   313,   313,   314,   315,   316,
     317,   318,   318,   319,   319,   320,   321,   322,   323,   324,
     324,   325,   325,   326,   327,   328,   329,   330,   330,   331,
     331,   332,   333,   334,   335,   336,   336,   337,   337,   338,
     339,   340,   341,   342,   342,   343,   343,   344,   345,   346,
     347,   348,   348,   349,   350,   350,   351,   351,   352,   353,
     354,   355,   356,   357,   357,   358,   358,   359,   360,   361,
     361,   362,   363,   364,   365,   365,   366,   366,   366,   367,
     367,   368,   368,   369,   370,   370,   371,   371,   372,   373,
     374,   374,   375,   375,   375,   375,   375,   376,   377,   378,
     379,   379,   380,   380,   381,   382,   383,   384,   385,   386,
     386,   387,   387,   388,   389,   390,   391,   392,   393,   393,
     394,   394,   395,   396,   397,   398,   399,   399,   400,   401,
     402,   403,   404,   405,   405,   406,   406,   407,   408,   409,
     409,   410,   411,   412,   413,   413,   414,   414,   414,   415,
     415,   416,   416,   417,   418,   418,   419,   419,   420,   421,
     422,   422,   423,   423,   424,   425,   426,   426,   427,   427,
     428,   429,   430,   431,   432,   433,   433,   434,   434,   435,
     436,   437,   437,   438,   439,   440,   441,   441,   442,   442,
     442,   443,   443,   444,   444,   445,   446,   446,   447,   447,
     448,   449,   450,   450,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   452,
     453,   454,   454,   455,   455,   456,   456,   457,   458,   459,
     460,   461,   462,   462,   463,   463,   464,   465,   466,   467,
     468,   469,   469,   470,   470,   471,   472,   472,   473,   474,
     475,   476,   476,   477,   477,   478,   479,   480,   481,   481,
     482,   482,   483,   484,   485,   486,   486,   487,   487,   488,
     489,   490,   491,   491,   492,   492,   493,   494,   495,   496,
     497,   497,   498,   498,   499,   500,   500,   501,   502,   503,
     504,   505,   505,   506,   506,   507,   508,   508,   509,   510,
     511,   512,   513,   513,   514,   514,   515,   516,   516,   517,
     518,   519,   520,   521,   521,   522,   522,   523,   524,   524,
     525,   526,   527,   528,   529,   529,   530,   530,   531,   532,
     533,   534,   535,   535,   536,   536,   537,   538,   539,   540,
     541,   541,   542,   542,   543,   544,   544,   545,   546,   547,
     548,   549,   549,   550,   550,   551,   552,   553,   553,   554,
     555,   556,   557,   557,   558,   558,   558,   559,   559,   560,
     560,   561,   562,   563,   563,   564,   564,   564,   565,   565,
     566,   567,   568,   569,   569,   570,   571,   572,   572,   573,
     573,   574,   575,   576,   577,   577,   578,   579,   580,   580,
     581,   581,   582,   583,   584,   584,   585,   586,   587,   588,
     588,   589,   589,   589,   590,   590,   591,   591,   592,   593,
     594,   594,   595,   595,   596,   597,   598,   598,   599,   600,
     601,   602,   602,   603,   603,   603,   604,   604,   605,   605,
     606,   607,   607,   608,   609,   610,   611,   611,   612,   613,
     614,   614,   615,   616,   617,   618,   618,   619,   620,   621,
     621,   622,   623,   624,   625,   625,   626,   627,   628,   628,
     629,   630,   631,   632,   632,   633,   634,   635,   635,   636,
     637,   638,   639,   639,   640,   641,   642,   642,   643,   644,
     645,   646,   646,   647,   648,   649,   649,   650,   651,   652,
     653,   653,   654,   655,   656,   656,   657,   658,   659,   660,
     660,   661,   662,   663,   663,   664,   664,   665,   666,   667,
     667,   668,   669,   670,   671,   671,   672,   672,   672,   673,
     673,   674,   674,   675,   676,   677,   677,   678,   678,   679,
     680,   680,   681,   682,   683,   684,   684,   685,   685,   685,
     686,   686,   687,   687,   688,   689,   689,   690,   691,   692,
     693,   693,   694,   694,   694,   694,   694,   694,   694,   694,
     694,   694,   695,   695,   696,   696,   697,   698,   698,   699,
     699,   700,   701,   702,   703,   703,   704,   704,   704,   704,
     704,   705,   706,   706,   707,   707,   708,   709,   710,   710,
     711,   711,   712,   713,   714,   715,   715,   716,   717,   718,
     718,   719,   719,   720,   721,   722,   722,   723,   724,   725,
     726,   726,   727,   727,   727,   728,   728,   729,   729,   730,
     731,   732,   732,   733,   733,   734,   735,   736,   736,   737,
     738,   739,   740,   740,   741,   741,   741,   741,   742,   742,
     743,   743,   744,   745,   745,   746,   747,   748,   749,   749,
     750,   751,   752,   752,   753,   754,   755,   756,   756,   757,
     758,   759,   759,   760,   761,   762,   763,   763,   764,   765,
     766,   766,   767,   768,   769,   770,   770,   771,   772,   773,
     773,   774,   775,   776,   777,   777,   778,   779,   780,   780,
     781,   782,   783,   784,   784,   785,   786,   787,   787,   788,
     789,   790,   791,   791,   792,   793,   794,   794,   795,   796,
     797,   798,   798,   799,   800,   801,   802,   802,   803,   803,
     803,   803,   803,   803,   803,   803,   803,   803,   804,   804,
     805,   805,   806,   807,   807,   808,   808,   809,   810,   811,
     812,   812,   813,   813,   813,   813,   813,   814,   815,   815,
     816,   816,   817,   818,   819,   819,   820,   820,   821,   822,
     823,   824,   824,   825,   826,   827,   827,   828,   828,   829,
     830,   831,   831,   832,   833,   834,   835,   835,   836,   836,
     836,   837,   837,   838,   838,   839,   840,   841,   841,   842,
     842,   843,   844,   845,   845,   846,   847,   848,   849,   849,
     850,   850,   850,   850,   851,   851,   852,   852,   853,   854,
     854,   855,   856,   857,   858,   858,   859,   860,   861,   861,
     862,   863,   864,   865,   865,   866,   867,   868,   868,   869,
     870,   871,   872,   872,   873,   874,   875,   875,   876,   877,
     878,   879,   879,   880,   881,   882,   882,   883,   884,   885,
     886,   886,   887,   888,   889,   889,   890,   891,   892,   893,
     893,   894,   895,   896,   896,   897,   898,   899,   900,   900,
     901,   902,   903,   903,   904,   905,   906,   907,   907,   908,
     909,   910,   911,   911,   912,   912,   912,   912,   912,   912,
     912,   912,   912,   912,   913,   913,   914,   914,   915,   916,
     916,   917,   917,   918,   919,   920,   921,   921,   922,   922,
     922,   922,   922,   923,   924,   924,   925,   925,   926,   927,
     928,   928,   929,   930,   931,   931,   932,   933,   934,   935,
     935,   936,   936,   936,   936,   936,   936,   936,   937,   937,
     938,   938,   939,   940,   941,   941,   942,   943,   943,   944,
     944,   945,   946,   947,   947,   948,   949,   950,   951,   952,
     952,   953,   953,   953,   954,   955,   956,   957,   957,   958,
     959,   959,   960,   961,   962,   963,   963,   964,   965,   966,
     967,   967,   968,   969,   970,   971,   971,   972,   973,   974,
     975,   976,   977,   978,   979,   980,   980,   981,   982,   983,
     984,   984,   985,   986,   987,   988,   988,   989,   990,   991,
     992,   992,   993,   994,   995,   996,   996,   997,   998,   999,
    1000,  1001,  1002,  1003,  1003,  1004,  1005,  1006,  1007,  1007,
    1008,  1009,  1010,  1011,  1011,  1012,  1013,  1014,  1015,  1015,
    1016,  1017,  1018,  1019,  1019,  1020,  1021,  1022,  1023,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  1044,  1045,  1046,  1047,  1048,  1048,  1049,  1049,  1049,
    1050,  1050,  1051,  1052,  1053,  1054,  1054,  1055,  1055,  1056,
    1057,  1058,  1059,  1059,  1060,  1060,  1061,  1062,  1063,  1064,
    1064,  1065,  1065,  1066,  1067,  1068,  1069,  1069,  1070,  1071,
    1071,  1072,  1072,  1072,  1072
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     1,     0,     6,     0,     2,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     0,     2,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     3,     1,
       0,     1,     3,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       1,     0,     1,     3,     1,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     2,
       1,     0,     2,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       0,     2,     1,     1,     3,     1,     3,     1,     1,     0,
       2,     1,     1,     3,     1,     3,     1,     1,     0,     2,
       1,     1,     3,     1,     3,     1,     0,     1,     3,     1,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     2,
       1,     0,     2,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     2,     1,     0,     2,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     0,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     2,     4,     3,
       1,     1,     1,     2,     1,     3,     3,     1,     1,     1,
       2,     1,     3,     3,     1,     1,     1,     2,     1,     3,
       3,     1,     1,     1,     2,     1,     3,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     2,     1,     3,     3,
       1,     1,     1,     1,     2,     1,     3,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     2,     4,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     3,     4,     0,     3,     1,     1,     0,     1,     1,
       1,     1,     3,     6,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     2,     1,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     2,     1,     0,     2,
       1,     1,     1,     1,     3,     7,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
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
       0,     2,     1,     1,     1,     1,     3,     7,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
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
       1,     1,     1,     3,     0,     2,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     1,     2,     4,     3,     1,     1,     0,
       2,     1,     1,     1,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       4,     1,     1,     4,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     4,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     3,     3,     4,     1,
       1,     2,     1,     3,     4,     4,     1,     1,     2,     0,
       2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,    18,    14,    62,
       0,     7,     0,    13,     2,    12,    64,   191,     0,     0,
      22,    17,    19,    20,    16,    10,     3,     8,     9,   193,
     261,     0,     0,    68,    63,    65,    66,    21,     0,    36,
      35,     0,    42,    41,     0,    48,    47,     0,    54,    53,
       0,    60,    59,     0,    24,    25,    27,    32,    33,    34,
      28,    38,    39,    40,    29,    44,    45,    46,    30,    50,
      51,    52,    31,    56,    57,    58,    14,   263,   303,     0,
       0,   197,   192,   194,   195,    67,    85,    93,   101,   109,
     120,   128,   136,   144,   152,   160,   171,     0,    70,    71,
      73,     0,    74,     0,    75,     0,    76,   110,    77,     0,
      78,     0,    79,     0,    80,     0,    81,     0,    82,   161,
      83,     0,     0,     0,     0,     0,     0,    23,    26,    11,
     305,   479,     0,     0,   267,   262,   264,   265,   196,   241,
     208,   217,   226,   235,     0,   199,   200,   202,   210,   203,
     219,   204,   228,   205,   236,   206,     0,    69,    72,     0,
      89,    84,    86,    87,     0,    97,    92,    94,    95,     0,
     105,   100,   102,   103,     0,     0,   111,     0,   124,   119,
     121,   122,     0,   132,   127,   129,   130,     0,   140,   135,
     137,   138,     0,   148,   143,   145,   146,     0,   156,   151,
     153,   154,     0,     0,   162,  1229,     0,   172,    37,    43,
      49,    55,    61,   481,    15,   483,     0,   309,   304,   306,
     307,   266,   283,   275,     0,   269,   270,   272,     0,   273,
       0,   198,   201,     0,   209,     0,   218,     0,   227,     0,
    1102,     0,   237,  1099,  1100,  1101,     0,   242,    91,    88,
       0,    99,    96,     0,   107,   104,     0,     0,     0,   116,
     108,   113,   114,   126,   123,     0,   134,   131,     0,   142,
     139,     0,   150,   147,     0,   158,   155,     0,     0,     0,
     167,   159,   164,   165,     0,     0,     0,   176,   170,   173,
     174,     0,   482,   308,   459,   330,   341,   349,   360,   367,
     374,   381,   440,   432,   388,   399,   421,   410,   448,     0,
     311,   312,   314,   331,   315,     0,   316,     0,   317,     0,
     318,     0,   319,     0,   320,     0,   321,     0,   322,     0,
     324,     0,   323,     0,   325,     0,   326,     0,   327,     0,
     328,     0,   268,   271,     0,   279,   274,   276,   277,     0,
     284,     0,   207,     0,  1160,   211,   213,   212,  1157,  1158,
    1159,     0,   216,   220,   222,   221,     0,   225,   229,   231,
     230,  1229,     0,   234,     0,   246,   240,   243,   244,    90,
      98,   106,   112,   118,   115,     0,   125,   133,   141,   149,
     157,   163,   169,   166,     0,  1229,  1228,  1231,  1232,  1233,
    1234,  1230,   175,   182,     0,   178,   179,   184,   493,   490,
     480,   488,   489,  1229,  1229,  1229,   484,   486,   487,   485,
     310,   313,     0,   332,     0,   345,   340,   342,   343,     0,
       0,   350,     0,     0,     0,     0,     0,     0,     0,   389,
       0,   400,     0,   411,     0,   422,     0,   433,     0,   441,
       0,     0,   449,     0,   460,   281,   278,     0,     0,   288,
     282,   285,   286,  1226,  1227,     0,   215,     0,     0,   224,
       0,   233,  1103,   239,     0,   245,   252,     0,   248,   249,
     254,   117,   168,  1182,   177,   180,     0,   183,   495,     0,
     704,   497,     0,     0,     0,     0,   336,   329,   333,   334,
     347,   344,     0,     0,     0,   354,   348,   351,   352,     0,
       0,   364,   359,   361,   362,     0,   371,   366,   368,   369,
       0,   378,   373,   375,   376,     0,   385,   380,   382,   383,
       0,     0,   393,   387,   390,   391,     0,   404,   398,   401,
     402,     0,   415,   409,   412,   413,     0,   426,   420,   423,
     424,     0,   437,   431,   434,   435,     0,   445,   439,   442,
     443,     0,     0,   453,   447,   450,   451,     0,   464,   458,
     461,   462,   280,   287,   294,     0,   290,   291,   296,   214,
    1161,   223,   232,   238,   247,   250,     0,   253,     0,   190,
     181,     0,     0,  1127,  1165,   185,   188,   186,  1124,  1125,
    1126,   187,  1162,  1163,  1164,   491,   706,   870,   708,  1229,
       0,   496,   498,  1229,  1229,  1229,   335,     0,   338,   339,
     346,     0,     0,   353,     0,   356,     0,   363,     0,     0,
    1073,   370,     0,   377,     0,   384,     0,     0,  1077,   392,
       0,   395,   397,  1079,   403,     0,   406,   408,   414,     0,
     417,   419,   425,     0,   428,   430,   436,     0,   444,     0,
       0,   452,     0,     0,   455,   463,   470,     0,   466,   467,
     472,   289,   292,     0,   295,     0,   260,   251,   255,   258,
     256,   257,   189,  1229,     0,   872,  1036,   874,  1229,     0,
     707,   709,     0,   504,   501,   494,   499,   500,  1189,  1179,
    1173,   337,  1177,     0,   355,   357,  1185,     0,   365,  1074,
     372,   379,   386,  1184,   394,   396,     0,  1078,   405,   407,
     416,   418,   427,   429,   438,   446,  1186,     0,   454,   456,
     465,   468,     0,   471,     0,   302,   293,   297,   300,   298,
     299,   259,  1128,  1166,  1038,   492,     0,  1229,     0,   873,
     875,     0,   715,   712,   705,   710,   711,  1229,   506,     0,
     526,     0,     0,     0,     0,  1088,  1076,     0,     0,     0,
    1080,  1081,  1082,  1083,     0,     0,   478,   469,   473,   476,
     474,   475,   301,  1229,     0,  1039,     0,   881,   878,   871,
     876,   877,  1229,   717,     0,   737,     0,  1183,   502,   528,
     548,     0,  1229,     0,   507,   358,  1075,  1087,     0,     0,
       0,   457,   477,     0,  1044,  1042,  1037,  1040,  1041,  1229,
     883,     0,   903,     0,  1181,   713,   739,   760,     0,  1229,
       0,   718,   550,   619,     0,     0,   529,     0,     0,   511,
     505,   508,   509,  1084,  1085,  1086,  1229,     0,  1180,   879,
     905,   926,     0,  1229,     0,   884,   762,   831,     0,     0,
     740,     0,     0,   722,   716,   719,   720,   621,   641,     0,
     556,   553,   549,   551,   552,     0,   533,   527,   530,   531,
    1229,   510,   517,     0,   513,   514,   519,  1187,  1043,  1047,
    1045,     0,   928,   997,     0,     0,   906,     0,     0,   888,
     882,   885,   886,   714,   768,   765,   761,   763,   764,     0,
     744,   738,   741,   742,  1229,   721,   728,     0,   724,   725,
     730,   643,   665,     0,     0,   622,   558,     0,   565,     0,
     539,   532,     0,   535,   536,   541,  1188,   512,   515,     0,
     518,     0,     0,  1229,  1145,  1092,     0,  1137,     0,  1048,
    1049,  1054,  1089,  1090,  1091,  1056,  1051,  1053,  1134,  1135,
    1136,  1055,  1142,  1143,  1144,  1052,  1057,   880,   934,   931,
     927,   929,   930,     0,   910,   904,   907,   908,  1229,   887,
     894,     0,   890,   891,   896,   834,   832,   836,   770,     0,
     777,     0,   750,   743,     0,   746,   747,   752,  1178,   723,
     726,     0,   729,   503,     0,     0,     0,   626,   620,   623,
     624,   554,   567,   574,     0,  1229,     0,   559,   534,   537,
       0,   540,     0,   525,   516,  1229,   520,   521,  1111,  1112,
     522,   523,  1229,     0,     0,  1229,     0,  1061,  1046,  1058,
    1059,  1050,  1000,   998,  1002,   936,     0,   943,     0,   916,
     909,     0,   912,   913,   918,  1172,   889,   892,     0,   895,
       0,   835,   766,   779,   786,     0,     0,   771,   745,   748,
       0,   751,     0,   736,   727,   731,   732,   733,   734,   668,
     666,   670,     0,     0,   648,   642,   645,   646,   632,   625,
       0,   628,   629,   634,   576,   583,     0,     0,   568,     0,
    1207,   562,   557,   560,   561,     0,   547,   538,   542,   543,
     544,   545,   524,     0,  1093,  1146,  1229,  1138,  1060,  1070,
       0,  1069,     0,  1063,  1064,  1066,  1067,  1068,     0,  1001,
     932,   945,   952,     0,     0,   937,   911,   914,     0,   917,
       0,   902,   893,   897,   898,   899,   900,     0,   851,   833,
     848,   849,  1229,     0,  1107,     0,  1132,   837,   843,   847,
     846,  1104,  1105,  1106,   840,   845,  1129,  1130,  1131,   842,
     844,   841,   839,   838,   788,   795,     0,     0,   780,  1207,
     774,   769,   772,   773,     0,   759,   749,  1117,  1150,     0,
       0,   753,   754,   756,  1114,  1115,  1116,   755,   757,  1147,
    1148,  1149,   735,     0,   669,     0,   647,   653,     0,   650,
     655,   627,   630,     0,   633,   585,   592,     0,     0,   577,
    1207,   571,   566,   569,   570,  1229,     0,     0,   564,  1205,
    1206,   546,  1229,  1176,  1072,     0,  1062,  1065,     0,  1017,
     999,  1014,  1015,     0,  1097,  1003,  1009,  1011,  1094,  1095,
    1096,  1013,  1012,  1006,  1008,  1010,  1007,  1004,  1005,   954,
     961,     0,     0,   946,  1207,   940,   935,   938,   939,     0,
     925,   915,  1122,  1155,  1229,  1229,   919,   920,   922,  1119,
    1120,  1121,   921,   923,  1152,  1153,  1154,   901,   850,   858,
    1193,     0,   853,   855,   860,   854,  1190,  1195,     0,     0,
       0,   797,   804,     0,     0,   789,  1207,   783,   778,   781,
     782,     0,   776,   758,  1229,  1229,     0,   685,   667,   682,
     683,     0,  1170,   671,   677,   681,   680,   674,   676,   678,
     675,   679,  1167,  1168,  1169,   673,   672,   644,   649,   651,
       0,   654,     0,   640,   631,   635,   636,   637,   638,   594,
     601,     0,     0,   586,  1207,   580,   575,   578,   579,     0,
     573,  1174,  1229,     0,   563,  1210,  1208,  1212,  1113,  1071,
    1016,  1024,     0,  1019,  1021,  1026,  1020,     0,   963,   970,
       0,     0,   955,  1207,   949,   944,   947,   948,     0,   942,
     924,     0,     0,   852,   856,     0,   859,  1191,     0,  1194,
    1229,  1108,  1133,   806,   813,     0,     0,   798,  1207,   792,
     787,   790,   791,     0,   785,   775,  1118,  1151,   684,   692,
       0,   687,   689,   694,   688,     0,     0,   663,   652,   660,
     661,     0,  1229,   656,   659,  1109,   657,  1139,  1140,   658,
     639,   603,   610,     0,     0,   595,  1207,   589,   584,   587,
     588,     0,   582,   572,     0,     0,  1222,  1217,  1219,  1220,
       0,  1211,  1018,  1022,     0,  1025,  1098,   972,   979,     0,
       0,   964,  1207,   958,   953,   956,   957,     0,   951,   941,
    1229,  1229,     0,   869,   857,   867,   861,   862,   865,   863,
     866,   864,  1207,  1202,  1192,  1200,  1201,  1199,  1198,  1197,
    1196,  1175,   815,   822,     0,     0,   807,  1207,   801,   796,
     799,   800,     0,   794,   784,   686,   690,     0,   693,  1171,
     662,     0,     0,     0,   612,   555,     0,     0,   604,  1207,
     598,   593,   596,   597,     0,   591,   581,  1229,     0,  1221,
       0,  1209,  1229,  1229,  1213,  1215,  1214,     0,  1035,  1023,
    1033,  1027,  1028,  1031,  1029,  1032,  1030,   981,   988,     0,
       0,   973,  1207,   967,   962,   965,   966,     0,   960,   950,
    1123,  1156,   868,     0,  1204,   824,   767,     0,     0,   816,
    1207,   810,   805,   808,   809,     0,   803,   793,     0,   703,
     691,   701,   695,   696,   699,   697,   700,   698,   664,     0,
    1229,     0,   613,  1207,   607,   602,   605,   606,     0,   600,
     590,  1218,  1223,     0,     0,     0,  1034,   990,   933,     0,
       0,   982,  1207,   976,   971,   974,   975,     0,   969,   959,
    1203,     0,   825,  1207,   819,   814,   817,   818,     0,   812,
     802,   702,  1110,  1141,  1207,   616,   611,   614,   615,     0,
     609,   599,  1216,  1229,  1229,     0,   991,  1207,   985,   980,
     983,   984,     0,   978,   968,  1207,   828,   823,   826,   827,
       0,   821,   811,     0,   618,   608,  1224,  1225,  1207,   994,
     989,   992,   993,     0,   987,   977,     0,   830,   820,   617,
       0,   996,   986,   829,   995
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    26,    27,    28,    14,    15,
       8,     9,    10,    21,    22,    23,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    17,
      18,    34,    35,    36,    97,    98,    99,   100,   101,   161,
     162,   163,   250,   102,   103,   166,   167,   168,   253,   104,
     105,   171,   172,   173,   256,   106,   107,   175,   176,   260,
     261,   262,   385,   108,   109,   179,   180,   181,   265,   110,
     111,   184,   185,   186,   268,   112,   113,   189,   190,   191,
     271,   114,   115,   194,   195,   196,   274,   116,   117,   199,
     200,   201,   277,   118,   119,   203,   204,   281,   282,   283,
     394,   120,   121,   206,   288,   289,   290,   404,   405,   406,
     407,   486,   487,   595,   590,    30,    31,    82,    83,    84,
     144,   145,   146,   147,   148,   233,   234,   355,   352,   465,
     149,   150,   235,   236,   363,   362,   468,   151,   152,   237,
     238,   368,   367,   470,   153,   154,   241,   373,   474,   155,
     156,   246,   376,   377,   378,   477,   478,   479,   480,   586,
     587,   678,   677,    78,    79,   135,   136,   137,   224,   225,
     226,   227,   228,   346,   347,   348,   457,   229,   230,   349,
     460,   461,   462,   575,   576,   577,   578,   673,   674,   737,
     736,   131,   132,   218,   219,   220,   309,   310,   311,   312,
     313,   422,   497,   498,   499,   617,   618,   314,   315,   426,
     427,   428,   502,   316,   317,   430,   506,   507,   508,   624,
     625,   318,   319,   512,   513,   514,   320,   321,   517,   518,
     519,   322,   323,   522,   523,   524,   324,   325,   527,   528,
     529,   326,   327,   438,   533,   534,   535,   640,   641,   328,
     329,   440,   538,   539,   540,   645,   646,   330,   331,   442,
     543,   544,   545,   649,   650,   332,   333,   444,   548,   549,
     550,   653,   654,   334,   335,   446,   553,   554,   555,   336,
     337,   448,   558,   559,   560,   338,   339,   451,   564,   565,
     566,   663,   664,   340,   341,   453,   569,   570,   571,   667,
     668,   669,   670,   732,   733,   778,   777,   214,   215,   291,
     292,   416,   410,   411,   412,   489,   490,   491,   610,   611,
     695,   696,   697,   759,   760,   761,   803,   840,   841,   842,
     883,   884,   885,   886,   939,   940,  1026,  1024,   800,   801,
     835,   877,   878,   879,   932,   933,   934,   935,  1020,  1021,
    1108,  1107,   833,   834,   872,   873,   874,   927,   928,   929,
    1016,  1102,  1103,  1104,  1227,  1013,  1014,  1097,  1222,  1223,
    1224,  1359,  1095,  1096,  1218,  1356,  1357,  1358,  1451,  1216,
    1217,  1352,  1448,  1449,  1450,  1534,  1350,  1351,  1444,  1531,
    1532,  1533,  1608,  1442,  1443,  1527,  1605,  1606,  1607,  1649,
    1525,  1526,  1601,  1646,  1647,  1648,  1673,   868,   869,   924,
    1008,  1009,  1010,  1090,  1091,  1092,  1093,  1213,  1214,  1345,
    1344,   922,   923,  1005,  1085,  1086,  1087,  1208,  1209,  1210,
    1340,  1341,  1433,  1428,  1429,  1430,  1003,  1080,  1081,  1203,
    1204,  1323,  1318,  1319,  1320,  1420,  1421,  1422,  1423,  1517,
    1518,  1592,  1590,  1591,   607,   608,   689,   690,   754,   755,
     756,   794,   795,   796,   830,   864,   865,   866,   917,   918,
     919,   920,  1001,  1002,  1075,  1074,   827,   828,   859,   911,
     912,   913,   994,   995,   996,   997,  1070,  1071,  1191,  1186,
     857,   858,   906,   907,   908,   989,   990,   991,  1066,  1181,
    1182,  1183,  1311,  1064,  1065,  1177,  1308,  1309,  1310,  1413,
    1175,  1176,  1304,  1410,  1411,  1412,  1512,  1302,  1303,  1406,
    1509,  1510,  1511,  1585,  1404,  1405,  1505,  1582,  1583,  1584,
    1638,  1503,  1504,  1578,  1635,  1636,  1637,  1670,  1576,  1577,
    1631,  1667,  1668,  1669,  1686,   903,   986,   987,  1060,  1061,
    1157,  1149,  1150,  1151,  1291,  1292,  1293,  1294,  1395,  1396,
    1486,  1484,  1485,   686,   687,   748,   749,   789,   790,   791,
     821,   822,   823,   854,   900,   901,   902,   981,   982,   983,
     984,  1058,  1059,  1143,  1142,   851,   852,   895,   975,   976,
     977,  1051,  1052,  1053,  1054,  1138,  1139,  1276,  1271,   893,
     894,   970,   971,   972,  1046,  1047,  1048,  1134,  1266,  1267,
    1268,  1388,  1132,  1133,  1262,  1385,  1386,  1387,  1477,  1260,
    1261,  1381,  1474,  1475,  1476,  1567,  1379,  1380,  1470,  1564,
    1565,  1566,  1627,  1468,  1469,  1560,  1624,  1625,  1626,  1662,
    1558,  1559,  1620,  1659,  1660,  1661,  1683,  1618,  1619,  1655,
    1680,  1681,  1682,  1690,   967,  1043,  1044,  1128,  1129,  1245,
    1240,  1241,  1242,  1372,  1373,  1374,  1375,  1464,  1465,  1551,
    1549,  1550,   745,   746,   784,   816,   817,   818,   847,   890,
     891,   948,   949,   950,  1038,  1039,  1040,  1122,  1123,  1124,
    1125,  1126,  1127,  1235,   629,   630,   642,   643,   716,   717,
     770,   771,   772,   773,   766,   951,   952,   953,   954,  1247,
    1248,  1249,  1250,   955,   243,   244,   245,  1160,  1161,  1162,
    1163,  1434,  1435,  1027,  1028,  1029,  1193,  1194,  1195,  1196,
    1278,  1279,  1280,  1281,   956,   598,   599,   600,  1165,  1166,
    1167,  1168,   957,   958,   959,   960,  1436,  1437,  1438,   961,
     962,   963,   964,  1198,  1199,  1200,  1201,  1283,  1284,  1285,
    1286,   357,   358,   359,   360,   965,   602,   603,   604,  1331,
    1332,  1333,  1334,   855,   417,  1017,  1172,   966,   431,   831,
     418,   750,   691,   207,   612,   439,   433,   452,   785,   804,
     419,  1295,  1296,  1297,  1398,  1399,  1500,  1494,  1495,  1496,
    1573,  1228,  1229,  1366,  1367,  1460,  1461,  1544,  1541,  1230,
    1363,  1457,  1458,  1459,  1545,  1546,   466,   284,   285,   401
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1370
static const yytype_int16 yypact[] =
{
     165, -1370, -1370,    98,    53,   116, -1370, -1370,   179,    62,
     236, -1370,   318, -1370, -1370, -1370, -1370,   117,   352,   576,
   -1370, -1370, -1370, -1370,    53, -1370, -1370, -1370, -1370, -1370,
     135,   357,   372, -1370, -1370, -1370, -1370, -1370,   219, -1370,
   -1370,   254, -1370, -1370,   262, -1370, -1370,   284, -1370, -1370,
     286, -1370, -1370,   217,   596, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   179, -1370,   212,   359,
     -25, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   227,   444, -1370,
   -1370,   361, -1370,   368, -1370,   370, -1370,   225, -1370,   373,
   -1370,   378, -1370,   382, -1370,   384, -1370,   403, -1370,   241,
   -1370,   293,   232,   239,   263,   250,   260, -1370, -1370, -1370,
   -1370,   288,   405,   -32, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   295,   133, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   114, -1370,   293, -1370, -1370,    32,
   -1370, -1370, -1370, -1370,    31, -1370, -1370, -1370, -1370,    42,
   -1370, -1370, -1370, -1370,   387,   407, -1370,    29, -1370, -1370,
   -1370, -1370,    26, -1370, -1370, -1370, -1370,    27, -1370, -1370,
   -1370, -1370,    30, -1370, -1370, -1370, -1370,    22, -1370, -1370,
   -1370, -1370,   399,   419, -1370, -1370,   425, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   131, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   324,    43, -1370, -1370,   427, -1370,
     293, -1370, -1370,   410,   177,   439,   177,   451,   177,   471,
   -1370,   455, -1370, -1370, -1370, -1370,   430, -1370, -1370, -1370,
     325, -1370, -1370,   362, -1370, -1370,   366,   472,    28, -1370,
   -1370, -1370, -1370, -1370, -1370,   374, -1370, -1370,   380, -1370,
   -1370,   364, -1370, -1370,   386, -1370, -1370,   393,   480,    25,
   -1370, -1370, -1370, -1370,   514,    12,   314, -1370, -1370, -1370,
   -1370,   434,   322, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   412,
     385, -1370, -1370,    79, -1370,   436, -1370,   488, -1370,   506,
   -1370,   506, -1370,   506, -1370,   506, -1370,   509, -1370,   509,
   -1370,   509, -1370,   509, -1370,   506, -1370,   506, -1370,   504,
   -1370,   293, -1370, -1370,    13, -1370, -1370, -1370, -1370,   442,
   -1370,   448, -1370,   530, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   448, -1370, -1370, -1370, -1370,   448, -1370, -1370, -1370,
   -1370, -1370,   533, -1370,   331, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   433, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   415, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   432,   429, -1370, -1370,   389, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   453, -1370,    11, -1370, -1370, -1370, -1370,   554,
     457, -1370,   558,   460,   466,   490,   492,   560,   494, -1370,
     500, -1370,   503, -1370,   505, -1370,   513, -1370,   525, -1370,
     562,   563, -1370,   573, -1370, -1370, -1370,   452,   462, -1370,
   -1370, -1370, -1370, -1370, -1370,   447, -1370,   591,   470, -1370,
     473, -1370, -1370, -1370,   468, -1370, -1370,   495,   496, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   575,   173, -1370,   546,
     438,   608,   645,   647,   654,    16, -1370, -1370, -1370, -1370,
   -1370, -1370,   518,   662,   -64, -1370, -1370, -1370, -1370,   666,
      33, -1370, -1370, -1370, -1370,   443, -1370, -1370, -1370, -1370,
     -57, -1370, -1370, -1370, -1370,    90, -1370, -1370, -1370, -1370,
     670,     9, -1370, -1370, -1370, -1370,   -97, -1370, -1370, -1370,
   -1370,   -96, -1370, -1370, -1370, -1370,   -88, -1370, -1370, -1370,
   -1370,   -90, -1370, -1370, -1370, -1370,   -84, -1370, -1370, -1370,
   -1370,   674,   423, -1370, -1370, -1370, -1370,   469, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   556,   559, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   592,   173,   566, -1370,
   -1370,   689,   697, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   531,   685, -1370,
     601, -1370, -1370, -1370, -1370, -1370, -1370,   624, -1370, -1370,
   -1370,   810,   809, -1370,   -55, -1370,   812, -1370,   811,    77,
   -1370, -1370,   465, -1370,   105, -1370,   146,   814, -1370, -1370,
      40, -1370, -1370, -1370, -1370,    60, -1370, -1370, -1370,   -33,
   -1370, -1370, -1370,   -63, -1370, -1370, -1370,   -30, -1370,   -59,
     815, -1370,   816,   454, -1370, -1370, -1370,   696,   698, -1370,
   -1370, -1370, -1370,   618,   173,   695, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   820, -1370,   609,   797, -1370,   620,
   -1370, -1370,   823,   656, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   827, -1370, -1370, -1370,   830, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   625,   334, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   831, -1370, -1370,
   -1370, -1370,   627,   173,   706, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   813, -1370,   629, -1370,
   -1370,   832,   630, -1370, -1370, -1370, -1370, -1370, -1370,   663,
     659,   805,   727,   692,   691, -1370, -1370,   843,   844,   845,
   -1370, -1370, -1370, -1370,   675,   720, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   637, -1370,   846,   636, -1370, -1370,
   -1370, -1370, -1370, -1370,   649,   642,   818, -1370, -1370, -1370,
     676,   805, -1370,   639, -1370, -1370, -1370, -1370,   849,   850,
     852, -1370, -1370,   856, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   650,   644,   826, -1370, -1370, -1370,   683,   818, -1370,
     646, -1370, -1370,   668,   648,   693, -1370,   862,   527, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   485, -1370, -1370,
   -1370,   686,   826, -1370,   699, -1370, -1370, -1370,   701,   703,
   -1370,   864,   507, -1370, -1370, -1370, -1370, -1370,   671,   805,
     688, -1370, -1370, -1370, -1370,   100, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   700,   702, -1370, -1370, -1370, -1370, -1370,
   -1370,   341, -1370, -1370,   707,   712, -1370,   865,   508, -1370,
   -1370, -1370, -1370,   745,   690, -1370, -1370, -1370, -1370,    94,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   669,   667, -1370,
   -1370, -1370, -1370,   851,   716, -1370, -1370,   704,   694,   839,
   -1370, -1370,   705,   710, -1370, -1370, -1370, -1370, -1370,   718,
     221,   879,   881, -1370, -1370, -1370,   882, -1370,   722,   341,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   757,   708, -1370,
   -1370, -1370, -1370,   107, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   678,   673, -1370, -1370, -1370, -1370, -1370, -1370,   711,
     709,   839, -1370, -1370,   679,   687, -1370, -1370, -1370, -1370,
   -1370,   724,   221,   768,   884,   726,  -121, -1370, -1370, -1370,
   -1370, -1370, -1370,   713,   839, -1370,   728, -1370, -1370, -1370,
     730,   221,   719, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   893,   896, -1370,    83, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   721,   717,   839, -1370,
   -1370,   714,   715, -1370, -1370, -1370, -1370, -1370,   732,   221,
     736,   151, -1370, -1370,   723,   839,   738, -1370, -1370, -1370,
     740,   124,   725, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   901,   550, -1370, -1370, -1370, -1370, -1370, -1370,
     729,   735, -1370, -1370, -1370,   731,   839,   744, -1370,   903,
     680, -1370, -1370, -1370, -1370,   737, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   909, -1370, -1370, -1370, -1370, -1370, -1370,
     913, -1370,   733,    95, -1370, -1370, -1370, -1370,   746,   291,
   -1370, -1370,   734,   839,   748, -1370, -1370, -1370,   750,   277,
     741, -1370, -1370, -1370, -1370, -1370, -1370,   -92, -1370, -1370,
   -1370, -1370, -1370,   916, -1370,   917, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   739,   839,   752, -1370,   680,
   -1370, -1370, -1370, -1370,   742, -1370, -1370, -1370, -1370,   920,
     921, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   754,   564,   918, -1370, -1370,   565, -1370,
   -1370, -1370, -1370,   759,   221, -1370,   743,   839,   761, -1370,
     680, -1370, -1370, -1370, -1370, -1370,   749,   747, -1370,   751,
   -1370, -1370, -1370, -1370, -1370,   756, -1370, -1370,   -91, -1370,
   -1370, -1370, -1370,   922, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
     755,   839,   763, -1370,   680, -1370, -1370, -1370, -1370,   753,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   801,   758, -1370, -1370,   764, -1370, -1370,   930,   919,
     929, -1370,   760,   839,   765, -1370,   680, -1370, -1370, -1370,
   -1370,   762, -1370, -1370, -1370, -1370,   -68, -1370, -1370, -1370,
   -1370,   925, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
     767,    88,   770, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
     771,   839,   769, -1370,   680, -1370, -1370, -1370, -1370,   766,
   -1370, -1370, -1370,   772, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   817,   773, -1370, -1370,   764,   931, -1370,   775,
     839,   774, -1370,   680, -1370, -1370, -1370, -1370,   777, -1370,
   -1370,   448,   448, -1370, -1370,   776,   363, -1370,   778,    69,
   -1370, -1370, -1370, -1370,   779,   839,   780, -1370,   680, -1370,
   -1370, -1370, -1370,   783, -1370, -1370, -1370, -1370, -1370, -1370,
     819,   781, -1370, -1370,   764,   932,  -127, -1370, -1370, -1370,
   -1370,   933, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   789,   839,   782, -1370,   680, -1370, -1370, -1370,
   -1370,   787, -1370, -1370,   936,     7, -1370, -1370, -1370, -1370,
     935,   561, -1370, -1370,   786,   363, -1370, -1370,   784,   839,
     788, -1370,   680, -1370, -1370, -1370, -1370,   793, -1370, -1370,
   -1370, -1370,   785, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   680, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   791,   839,   790, -1370,   680, -1370, -1370,
   -1370, -1370,   808, -1370, -1370, -1370, -1370,   792,   363, -1370,
   -1370,  -126,   448,   945, -1370, -1370,   839,   794, -1370,   680,
   -1370, -1370, -1370, -1370,   807, -1370, -1370, -1370,   795, -1370,
     947, -1370, -1370, -1370, -1370, -1370, -1370,   799, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   803,   839,
     796, -1370,   680, -1370, -1370, -1370, -1370,   821, -1370, -1370,
   -1370, -1370, -1370,   822, -1370, -1370, -1370,   839,   798, -1370,
     680, -1370, -1370, -1370, -1370,   824, -1370, -1370,   825, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   946,
   -1370,   800, -1370,   680, -1370, -1370, -1370, -1370,   828, -1370,
   -1370, -1370, -1370,   829,   952,   955, -1370, -1370, -1370,   839,
     802, -1370,   680, -1370, -1370, -1370, -1370,   833, -1370, -1370,
   -1370,   804, -1370,   680, -1370, -1370, -1370, -1370,   834, -1370,
   -1370, -1370, -1370, -1370,   680, -1370, -1370, -1370, -1370,   837,
   -1370, -1370, -1370, -1370, -1370,   806, -1370,   680, -1370, -1370,
   -1370, -1370,   840, -1370, -1370,   680, -1370, -1370, -1370, -1370,
     847, -1370, -1370,   841, -1370, -1370, -1370, -1370,   680, -1370,
   -1370, -1370, -1370,   848, -1370, -1370,   842, -1370, -1370, -1370,
     854, -1370, -1370, -1370, -1370
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   886, -1370,
     941, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   912, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   870, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   569,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   835, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   491, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
     838, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   402, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   682, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
     355, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   353, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   349, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,   348, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   345, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   338, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   335, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,   118, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,    71, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,  -420, -1082, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,  -201, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,  -413, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
      92, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,    17, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,  -281, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,    36,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   -39, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,  -358, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,    65, -1370, -1370, -1370, -1370, -1370,  -104,
   -1370, -1370, -1370, -1370,  -346,  -402,  -482, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1045, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,  -153, -1370, -1370, -1370, -1088, -1370, -1370,
   -1370, -1370, -1370,  -996, -1370, -1370, -1369, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,  -484, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1043, -1370, -1370, -1370, -1370, -1370, -1370, -1040,
   -1370, -1370, -1370, -1368, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,  -191, -1370, -1370, -1370,  -483, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,  -842, -1370,  -977, -1081, -1370, -1370,  -816,
   -1370, -1370, -1370,  -143, -1370,  -263,   -52, -1370, -1370,  -796,
   -1370, -1198, -1276, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1171, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,  -359,  -371, -1370, -1370
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     472,   242,   469,   597,   601,   836,  1076,   471,  1312,  1212,
     896,  1538,   860,   247,  1067,   500,  1158,   455,  1169,  1397,
     396,  1170,   463,   464,   483,  1109,   275,  1488,  1490,   392,
     266,   269,   383,   263,   272,   251,   248,  1098,  1288,  1370,
    1376,  1252,   492,   493,   494,   365,   254,   370,  1258,  1360,
     221,   622,  1088,  1088,   647,   138,   638,   638,  1088,   651,
     622,   628,  1418,  1144,   655,   638,   441,   628,   443,   644,
     445,  1135,   656,   925,   648,  1192,   658,  1520,  1598,  1089,
     652,   356,   623,   364,  1246,   369,  1254,   350,  1178,  1255,
     638,   704,   628,  1389,   628,   222,  1553,  1555,     6,   633,
    1397,   725,   139,   680,   681,   722,   140,   223,   141,  1015,
     142,  1419,   143,   592,  1431,   239,  1326,  1289,  1424,  1219,
     638,   628,   423,  1335,   353,   802,  1371,   240,     7,   594,
      11,  1432,   724,  1290,  1290,  1414,   619,   720,   354,    16,
     249,   252,   384,  1277,   267,   264,   276,   270,  1397,  1594,
    1596,   393,   273,   456,   255,   501,  1263,  1290,   616,  1324,
     239,  1328,   638,   647,  1329,   591,  1025,   651,  1152,   632,
     222,   655,   240,   639,   634,   941,   942,     1,     2,   636,
     593,   627,   223,  1452,   628,  1187,  1188,  1189,  1190,   829,
     739,   740,   591,   638,    13,   592,    29,   239,   454,  1305,
    1153,  1154,  1155,  1156,   714,   657,   944,   593,   945,   240,
     659,   594,  1478,   638,   591,   293,    77,   592,  1346,   239,
     946,   947,   353,   239,   122,   708,   718,   709,   628,   593,
     709,   240,   709,   594,   709,   240,   354,  1513,   692,  1539,
    1353,   628,   698,   699,   700,  1173,    19,    20,   635,   780,
     781,   397,   398,   399,   400,   709,   628,   709,   294,   123,
     139,   711,   591,  1025,   140,   592,   141,   124,   142,   434,
     143,   435,   295,   436,   296,  1535,   297,   593,   298,   930,
     299,   594,   931,   447,  1382,   449,   300,  1257,   301,   125,
     302,   126,   303,   127,   304,   130,   305,   628,   306,   174,
     307,  1568,   308,   992,   712,   157,   993,  1118,  1152,   205,
    1119,  1120,   742,  1121,   202,   941,   942,   751,   591,  1025,
     208,  1574,  1119,  1120,  1049,  1121,  1407,  1050,    24,    25,
     853,   209,   591,   593,   596,   592,  1586,   239,  1243,  1244,
    1153,  1154,  1272,  1273,  1274,  1275,   944,   593,   945,   240,
     211,   594,   413,   414,   415,   767,   768,   769,  1609,   210,
     946,   947,    32,    33,   212,   941,   942,    80,    81,   133,
     134,   159,   160,   213,  1445,   231,   786,   943,   164,   165,
     169,   170,   591,   177,   178,   592,   797,   239,   182,   183,
     257,  1628,   187,   188,   192,   193,   944,   593,   945,   240,
    1487,   594,   278,  1471,   591,  1025,   342,   592,  1336,  1639,
     946,   947,   813,   197,   198,   216,   217,   258,   259,   593,
     351,   824,  1499,   594,  1187,  1188,  1189,  1190,  1506,   279,
     280,   837,  1650,   379,   679,   286,   287,   344,   345,  1212,
     374,   375,   402,   403,   408,   409,   424,   425,   848,   361,
      85,  1663,   458,   459,   463,   464,  1030,  1031,   861,   475,
     476,   366,  1671,   495,   496,   372,  1528,   504,   505,  1552,
     510,   511,   380,  1674,   371,   887,   515,   516,   381,    86,
     382,    87,   897,    88,   388,    89,  1684,    90,   391,    91,
     386,    92,  1561,    93,  1687,    94,   420,    95,   387,    96,
     520,   521,   525,   526,   531,   532,   429,  1691,   389,   936,
     536,   537,   294,   541,   542,   546,   547,   390,  1077,  1078,
     395,   738,  1593,   551,   552,   432,   295,  1579,   296,   437,
     297,   450,   298,   467,   299,   556,   557,  1110,  1111,   473,
     300,   482,   301,   998,   302,  1439,   303,   481,   304,  1602,
     305,    86,   306,    87,   307,    88,   308,    89,   403,    90,
     484,    91,   503,    92,   488,    93,   509,    94,   530,    95,
     561,    96,  1034,   562,   563,  1145,  1146,  1164,  1171,   579,
     779,  1152,  1621,   567,   568,   588,   589,  1197,   941,   942,
     573,   574,   572,   631,   628,   661,   662,   665,   666,   580,
    1632,   802,   675,   676,   581,   591,   583,  1055,   592,   582,
     239,   693,   694,  1153,  1154,   710,   628,  1321,  1322,   944,
     593,   945,   240,   584,   594,   476,   728,   662,   734,   735,
     752,   753,   605,   946,   947,   764,   765,   775,   776,   787,
     788,   609,  1656,   606,  1099,  1253,  1256,   814,   815,   838,
     839,   613,    37,   614,  1113,  1282,   862,   863,   870,   871,
     615,  1114,   620,    38,  1117,    39,    40,    41,   621,    42,
      43,    44,   626,    45,    46,    47,   637,    48,    49,    50,
     660,    51,    52,    38,   671,    39,    40,    41,   574,    42,
      43,    44,   683,    45,    46,    47,   682,    48,    49,    50,
     684,    51,    52,   875,   876,   881,   882,   888,   889,   898,
     899,   904,   905,   909,   910,   915,   916,   968,   969,   688,
    1327,  1330,   973,   974,   979,   980,  1006,  1007,  1022,  1023,
    1347,  1348,  1036,  1037,  1072,  1073,  1083,  1084,  1100,  1101,
    1105,  1106,  1140,  1141,   685,  1233,  1147,  1148,  1179,  1180,
    1184,  1185,  1206,  1207,  1220,  1221,  1238,  1239,  1264,  1265,
    1269,  1270,  1306,  1307,  1316,  1317,   701,  1338,  1207,  1342,
    1343,  1354,  1355,  1383,  1384,  1408,  1409,  1426,  1427,  1446,
    1447,  1298,  1455,  1456,  1472,  1473,  1482,  1483,  1492,  1493,
    1507,  1508,  1529,  1530,  1542,  1543,  1547,  1548,  1562,  1563,
    1580,  1581,  1588,  1589,  1603,  1604,  1622,  1623,  1633,  1634,
    1644,  1645,  1657,  1658,  1665,  1666,  1678,  1679,   702,   703,
     706,   707,   713,   726,   730,   741,   727,   666,   743,   757,
     744,   762,   747,   758,   763,   774,   782,   793,   792,   798,
     799,   783,   802,   805,   806,   807,   808,   809,   810,   811,
     812,   820,   819,   826,  1361,   825,   829,   843,   844,   832,
     845,  1368,   846,   850,   849,   853,   856,   867,   880,   892,
     914,   978,   921,   926,   985,   988,   916,   999,   937,  1015,
    1004,   882,  1032,  1012,  1033,  1035,  1042,  1018,  1011,   930,
     980,  1068,  1082,  1045,  1056,  1062,   992,  1079,  1063,  1112,
    1094,  1115,  1116,  1391,  1392,  1130,  1131,  1205,  1159,  1225,
    1174,  1226,  1489,  1491,  1088,  1232,  1498,  1231,  1234,  1299,
    1300,  1259,  1215,  1314,  1315,  1377,  1337,  1401,  1425,  1211,
    1301,  1393,  1049,  1364,  1136,  1202,  1400,  1402,  1349,  1466,
    1519,  1522,  1537,  1416,  1417,  1540,  1378,  1462,  1415,  1515,
    1440,  1600,  1313,  1613,  1642,  1403,  1453,  1236,  1653,  1287,
    1419,  1654,   129,  1479,  1441,    76,   128,  1289,   158,   585,
    1467,  1390,  1502,  1514,   485,  1536,  1251,  1557,   672,   705,
     232,  1554,  1556,  1569,  1362,  1369,  1524,  1365,  1575,  1290,
    1371,  1454,   421,   715,   719,  1572,  1587,   721,   723,  1610,
    1617,   729,   938,   731,  1019,  1641,  1521,  1339,  1516,  1629,
    1000,  1394,  1069,  1137,  1041,  1463,  1640,  1616,  1057,  1237,
       0,     0,     0,     0,  1651,  1664,     0,  1612,     0,  1501,
    1672,  1675,  1480,  1481,  1595,  1597,  1685,     0,     0,  1689,
    1693,  1688,  1692,     0,     0,     0,     0,     0,  1630,     0,
       0,  1325,  1694,     0,     0,     0,     0,     0,     0,     0,
       0,  1523,     0,   343,     0,     0,  1652,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1570,
    1571,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1599,     0,     0,  1611,     0,     0,     0,
       0,  1614,  1615,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1643,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1497,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1676,  1677
};

static const yytype_int16 yycheck[] =
{
     371,   154,   361,   487,   487,   801,  1002,   366,  1179,  1091,
     852,     4,   828,   156,   991,     4,  1061,     4,  1061,  1295,
       8,  1061,     6,     7,   395,  1021,     4,  1396,  1396,     4,
       4,     4,     4,     4,     4,     4,     4,  1014,   130,   130,
    1238,  1129,   413,   414,   415,   236,     4,   238,  1129,  1220,
      82,   115,   179,   179,   536,    80,   153,   153,   179,   541,
     115,   151,   130,  1059,   546,   153,   329,   151,   331,   166,
     333,  1048,   162,   869,   170,  1071,   160,   204,   204,   200,
     168,   234,   146,   236,  1129,   238,  1129,   230,  1065,  1129,
     153,   146,   151,  1264,   151,   127,  1465,  1465,     0,   156,
    1376,   160,   127,   587,   587,   168,   131,   139,   133,    40,
     135,   179,   137,    44,    26,    46,  1204,   209,  1316,  1096,
     153,   151,   313,  1204,    45,    37,   217,    58,    75,    60,
      14,    43,   162,   225,   225,  1306,   495,   170,    59,    77,
     108,   110,   114,  1139,   118,   116,   124,   120,  1424,  1518,
    1518,   126,   122,   140,   112,   144,  1133,   225,   142,  1204,
      46,  1204,   153,   645,  1204,    41,    42,   649,    17,   515,
     127,   653,    58,   164,   520,    24,    25,    12,    13,   525,
      56,   148,   139,  1354,   151,    61,    62,    63,    64,    38,
     674,   674,    41,   153,    15,    44,    79,    46,   341,  1176,
      49,    50,    51,    52,   164,   551,    55,    56,    57,    58,
     556,    60,  1383,   153,    41,    84,    81,    44,  1214,    46,
      69,    70,    45,    46,     5,   148,   166,   629,   151,    56,
     632,    58,   634,    60,   636,    58,    59,  1408,   609,   232,
    1217,   151,   613,   614,   615,  1061,    10,    11,   158,   733,
     733,   239,   240,   241,   242,   657,   151,   659,   127,     5,
     127,   156,    41,    42,   131,    44,   133,     5,   135,   321,
     137,   323,   141,   325,   143,  1446,   145,    56,   147,   179,
     149,    60,   182,   335,  1261,   337,   155,  1129,   157,     5,
     159,     5,   161,    76,   163,    83,   165,   151,   167,    74,
     169,  1472,   171,   209,   158,    78,   212,   224,    17,    16,
     227,   228,   683,   230,    73,    24,    25,   688,    41,    42,
      88,  1492,   227,   228,   217,   230,  1303,   220,    10,    11,
      39,    92,    41,    56,   487,    44,  1507,    46,    47,    48,
      49,    50,    65,    66,    67,    68,    55,    56,    57,    58,
     100,    60,    30,    31,    32,    21,    22,    23,  1529,    96,
      69,    70,    10,    11,   104,    24,    25,    10,    11,    10,
      11,    10,    11,    85,  1351,    80,   747,    36,    10,    11,
      10,    11,    41,    10,    11,    44,   757,    46,    10,    11,
       3,  1562,    10,    11,    10,    11,    55,    56,    57,    58,
    1396,    60,     3,  1380,    41,    42,    82,    44,  1204,  1580,
      69,    70,   783,    10,    11,    10,    11,    10,    11,    56,
      10,   792,  1399,    60,    61,    62,    63,    64,  1405,    10,
      11,   802,  1603,   108,   587,    10,    11,    10,    11,  1521,
      10,    11,   128,   129,    10,    11,    10,    11,   819,    10,
      78,  1622,    10,    11,     6,     7,   940,   940,   829,   128,
     129,    10,  1633,    10,    11,    10,  1443,    10,    11,  1465,
      10,    11,   110,  1644,     3,   846,    10,    11,   112,   107,
       8,   109,   853,   111,   120,   113,  1657,   115,     8,   117,
     116,   119,  1469,   121,  1665,   123,    84,   125,   118,   127,
      10,    11,    10,    11,    10,    11,    18,  1678,   122,   880,
      10,    11,   127,    10,    11,    10,    11,   124,  1002,  1002,
       6,   674,  1518,    10,    11,    19,   141,  1504,   143,    20,
     145,    27,   147,     3,   149,    10,    11,  1021,  1021,     6,
     155,   126,   157,   914,   159,  1341,   161,   114,   163,  1526,
     165,   107,   167,   109,   169,   111,   171,   113,   129,   115,
     128,   117,     8,   119,   175,   121,     8,   123,     8,   125,
       8,   127,   943,    10,    11,  1059,  1059,  1061,  1061,   132,
     733,    17,  1559,    10,    11,    10,    11,  1071,    24,    25,
     128,   129,   140,   150,   151,   172,   173,   128,   129,     8,
    1577,    37,    10,    11,   134,    41,   138,   978,    44,   136,
      46,    10,    11,    49,    50,   150,   151,    53,    54,    55,
      56,    57,    58,   128,    60,   129,   172,   173,    10,    11,
      10,    11,    86,    69,    70,    10,    11,    10,    11,    10,
      11,    33,  1619,   205,  1015,  1129,  1129,    10,    11,    10,
      11,     6,    76,     6,  1025,  1139,    10,    11,    10,    11,
       6,  1032,   144,    87,  1035,    89,    90,    91,     6,    93,
      94,    95,     6,    97,    98,    99,     6,   101,   102,   103,
       6,   105,   106,    87,   128,    89,    90,    91,   129,    93,
      94,    95,     3,    97,    98,    99,   130,   101,   102,   103,
       3,   105,   106,    10,    11,   178,   179,   222,   223,    10,
      11,    10,    11,    10,    11,   208,   209,    10,    11,    34,
    1204,  1204,    10,    11,   216,   217,    10,    11,    10,    11,
    1214,  1214,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   213,  1116,    10,    11,    10,    11,
      10,    11,   202,   203,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,   142,   202,   203,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,  1152,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   233,   234,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,     8,    10,
       8,    10,     8,     8,   128,   130,    10,   129,     8,     6,
     221,     4,    35,   177,     4,     4,   130,   207,     6,   176,
     181,    28,    37,   116,   152,   154,     3,     3,     3,   174,
     130,   215,     6,   211,  1225,   206,    38,     8,     8,   183,
       8,  1232,     6,   219,   214,    39,   183,   199,     6,   183,
       6,     6,   201,   185,   129,   185,   209,   208,   178,    40,
      29,   179,     3,   189,     3,     3,   129,   182,   184,   179,
     217,   212,     8,   185,   216,   184,   209,   129,   189,   180,
     187,     8,     6,  1274,  1275,   184,   189,     6,  1061,     6,
     187,   231,  1396,  1396,   179,     6,  1399,   180,     5,     3,
       3,   187,   191,     3,     3,     3,     8,     8,     3,   200,
     191,   130,   217,   186,   220,   210,     6,     8,   195,     8,
       8,     8,     6,  1314,  1315,    10,   191,   130,   186,   130,
     180,     6,   210,     6,     8,   195,   190,   224,     6,   218,
     179,     6,    76,   186,   193,    24,    54,   209,    98,   478,
     195,   218,   193,   190,   405,   188,  1129,   193,   576,   624,
     145,  1465,  1465,   190,   235,   229,   197,   236,   197,   225,
     217,  1362,   310,   640,   645,   210,   188,   649,   653,   192,
     197,   663,   884,   668,   933,   180,  1426,  1208,  1421,   188,
     918,  1292,   995,  1052,   949,  1373,   192,   218,   982,  1123,
      -1,    -1,    -1,    -1,   196,   192,    -1,   232,    -1,  1400,
     196,   194,  1391,  1392,  1518,  1518,   196,    -1,    -1,   198,
     198,   194,   194,    -1,    -1,    -1,    -1,    -1,   226,    -1,
      -1,  1204,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1432,    -1,   225,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1480,
    1481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1522,    -1,    -1,  1537,    -1,    -1,    -1,
      -1,  1542,  1543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1600,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1399,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1653,  1654
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   244,   245,   246,     0,    75,   253,   254,
     255,    14,   247,    15,   251,   252,    77,   282,   283,    10,
      11,   256,   257,   258,    10,    11,   248,   249,   250,    79,
     368,   369,    10,    11,   284,   285,   286,    76,    87,    89,
      90,    91,    93,    94,    95,    97,    98,    99,   101,   102,
     103,   105,   106,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   253,    81,   416,   417,
      10,    11,   370,   371,   372,    78,   107,   109,   111,   113,
     115,   117,   119,   121,   123,   125,   127,   287,   288,   289,
     290,   291,   296,   297,   302,   303,   308,   309,   316,   317,
     322,   323,   328,   329,   334,   335,   340,   341,   346,   347,
     354,   355,     5,     5,     5,     5,     5,    76,   261,   251,
      83,   444,   445,    10,    11,   418,   419,   420,    80,   127,
     131,   133,   135,   137,   373,   374,   375,   376,   377,   383,
     384,   390,   391,   397,   398,   402,   403,    78,   289,    10,
      11,   292,   293,   294,    10,    11,   298,   299,   300,    10,
      11,   304,   305,   306,    74,   310,   311,    10,    11,   318,
     319,   320,    10,    11,   324,   325,   326,    10,    11,   330,
     331,   332,    10,    11,   336,   337,   338,    10,    11,   342,
     343,   344,    73,   348,   349,    16,   356,  1036,    88,    92,
      96,   100,   104,    85,   560,   561,    10,    11,   446,   447,
     448,    82,   127,   139,   421,   422,   423,   424,   425,   430,
     431,    80,   375,   378,   379,   385,   386,   392,   393,    46,
      58,   399,   966,   967,   968,   969,   404,  1036,     4,   108,
     295,     4,   110,   301,     4,   112,   307,     3,    10,    11,
     312,   313,   314,     4,   116,   321,     4,   118,   327,     4,
     120,   333,     4,   122,   339,     4,   124,   345,     3,    10,
      11,   350,   351,   352,  1070,  1071,    10,    11,   357,   358,
     359,   562,   563,    84,   127,   141,   143,   145,   147,   149,
     155,   157,   159,   161,   163,   165,   167,   169,   171,   449,
     450,   451,   452,   453,   460,   461,   466,   467,   474,   475,
     479,   480,   484,   485,   489,   490,   494,   495,   502,   503,
     510,   511,   518,   519,   526,   527,   532,   533,   538,   539,
     546,   547,    82,   423,    10,    11,   426,   427,   428,   432,
    1036,    10,   381,    45,    59,   380,   966,  1014,  1015,  1016,
    1017,    10,   388,   387,   966,  1014,    10,   395,   394,   966,
    1014,     3,    10,   400,    10,    11,   405,   406,   407,   108,
     110,   112,     8,     4,   114,   315,   116,   118,   120,   122,
     124,     8,     4,   126,   353,     6,     8,   239,   240,   241,
     242,  1072,   128,   129,   360,   361,   362,   363,    10,    11,
     565,   566,   567,    30,    31,    32,   564,  1027,  1033,  1043,
      84,   451,   454,  1014,    10,    11,   462,   463,   464,    18,
     468,  1031,    19,  1039,  1039,  1039,  1039,    20,   496,  1038,
     504,  1038,   512,  1038,   520,  1038,   528,  1039,   534,  1039,
      27,   540,  1040,   548,  1036,     4,   140,   429,    10,    11,
     433,   434,   435,     6,     7,   382,  1069,     3,   389,  1069,
     396,  1069,  1070,     6,   401,   128,   129,   408,   409,   410,
     411,   114,   126,  1070,   128,   362,   364,   365,   175,   568,
     569,   570,  1070,  1070,  1070,    10,    11,   455,   456,   457,
       4,   144,   465,     8,    10,    11,   469,   470,   471,     8,
      10,    11,   476,   477,   478,    10,    11,   481,   482,   483,
      10,    11,   486,   487,   488,    10,    11,   491,   492,   493,
       8,    10,    11,   497,   498,   499,    10,    11,   505,   506,
     507,    10,    11,   513,   514,   515,    10,    11,   521,   522,
     523,    10,    11,   529,   530,   531,    10,    11,   535,   536,
     537,     8,    10,    11,   541,   542,   543,    10,    11,   549,
     550,   551,   140,   128,   129,   436,   437,   438,   439,   132,
       8,   134,   136,   138,   128,   410,   412,   413,    10,    11,
     367,    41,    44,    56,    60,   366,   966,   987,   988,   989,
     990,  1018,  1019,  1020,  1021,    86,   205,   707,   708,    33,
     571,   572,  1037,     6,     6,     6,   142,   458,   459,  1069,
     144,     6,   115,   146,   472,   473,     6,   148,   151,   947,
     948,   150,   947,   156,   947,   158,   947,     6,   153,   164,
     500,   501,   949,   950,   166,   508,   509,   949,   170,   516,
     517,   949,   168,   524,   525,   949,   162,   947,   160,   947,
       6,   172,   173,   544,   545,   128,   129,   552,   553,   554,
     555,   128,   438,   440,   441,    10,    11,   415,   414,   966,
     987,  1018,   130,     3,     3,   213,   816,   817,    34,   709,
     710,  1035,  1070,    10,    11,   573,   574,   575,  1070,  1070,
    1070,   142,     8,    10,   146,   473,     8,    10,   148,   948,
     150,   156,   158,     8,   164,   501,   951,   952,   166,   509,
     170,   517,   168,   525,   162,   160,     8,    10,   172,   545,
     128,   554,   556,   557,    10,    11,   443,   442,   966,   987,
    1018,   130,  1070,     8,   221,   925,   926,    35,   818,   819,
    1034,  1070,    10,    11,   711,   712,   713,     6,   177,   576,
     577,   578,     4,     4,    10,    11,   957,    21,    22,    23,
     953,   954,   955,   956,     4,    10,    11,   559,   558,   966,
     987,  1018,   130,    28,   927,  1041,  1070,    10,    11,   820,
     821,   822,     6,   207,   714,   715,   716,  1070,   176,   181,
     591,   592,    37,   579,  1042,   116,   152,   154,     3,     3,
       3,   174,   130,  1070,    10,    11,   928,   929,   930,     6,
     215,   823,   824,   825,  1070,   206,   211,   729,   730,    38,
     717,  1032,   183,   605,   606,   593,  1042,  1070,    10,    11,
     580,   581,   582,     8,     8,     8,     6,   931,  1070,   214,
     219,   838,   839,    39,   826,  1026,   183,   743,   744,   731,
    1032,  1070,    10,    11,   718,   719,   720,   199,   660,   661,
      10,    11,   607,   608,   609,    10,    11,   594,   595,   596,
       6,   178,   179,   583,   584,   585,   586,  1070,   222,   223,
     932,   933,   183,   852,   853,   840,  1026,  1070,    10,    11,
     827,   828,   829,   798,    10,    11,   745,   746,   747,    10,
      11,   732,   733,   734,     6,   208,   209,   721,   722,   723,
     724,   201,   674,   675,   662,  1042,   185,   610,   611,   612,
     179,   182,   597,   598,   599,   600,  1070,   178,   585,   587,
     588,    24,    25,    36,    55,    57,    69,    70,   934,   935,
     936,   958,   959,   960,   961,   966,   987,   995,   996,   997,
     998,  1002,  1003,  1004,  1005,  1018,  1030,   907,    10,    11,
     854,   855,   856,    10,    11,   841,   842,   843,     6,   216,
     217,   830,   831,   832,   833,   129,   799,   800,   185,   748,
     749,   750,   209,   212,   735,   736,   737,   738,  1070,   208,
     723,   725,   726,   689,    29,   676,    10,    11,   663,   664,
     665,   184,   189,   618,   619,    40,   613,  1028,   182,   599,
     601,   602,    10,    11,   590,    42,   589,   976,   977,   978,
     987,  1018,     3,     3,  1070,     3,    10,    11,   937,   938,
     939,   936,   129,   908,   909,   185,   857,   858,   859,   217,
     220,   844,   845,   846,   847,  1070,   216,   832,   834,   835,
     801,   802,   184,   189,   756,   757,   751,  1028,   212,   737,
     739,   740,    10,    11,   728,   727,   976,   987,  1018,   129,
     690,   691,     8,    10,    11,   677,   678,   679,   179,   200,
     666,   667,   668,   669,   187,   625,   626,   620,  1028,  1070,
      10,    11,   614,   615,   616,    10,    11,   604,   603,   976,
     987,  1018,   180,  1070,  1070,     8,     6,  1070,   224,   227,
     228,   230,   940,   941,   942,   943,   944,   945,   910,   911,
     184,   189,   865,   866,   860,  1028,   220,   846,   848,   849,
      10,    11,   837,   836,   976,   987,  1018,    10,    11,   804,
     805,   806,    17,    49,    50,    51,    52,   803,   958,   966,
     970,   971,   972,   973,   987,   991,   992,   993,   994,   995,
    1002,  1018,  1029,  1032,   187,   763,   764,   758,  1028,    10,
      11,   752,   753,   754,    10,    11,   742,    61,    62,    63,
      64,   741,   976,   979,   980,   981,   982,   987,  1006,  1007,
    1008,  1009,   210,   692,   693,     6,   202,   203,   680,   681,
     682,   200,   668,   670,   671,   191,   632,   633,   627,  1028,
      10,    11,   621,   622,   623,     6,   231,   617,  1054,  1055,
    1062,   180,     6,  1070,     5,   946,   224,   942,    10,    11,
     913,   914,   915,    47,    48,   912,   958,   962,   963,   964,
     965,   966,   970,   987,   995,  1002,  1018,  1026,  1029,   187,
     872,   873,   867,  1028,    10,    11,   861,   862,   863,    10,
      11,   851,    65,    66,    67,    68,   850,   976,   983,   984,
     985,   986,   987,  1010,  1011,  1012,  1013,   218,   130,   209,
     225,   807,   808,   809,   810,  1044,  1045,  1046,  1070,     3,
       3,   191,   770,   771,   765,  1028,    10,    11,   759,   760,
     761,   755,  1054,   210,     3,     3,    10,    11,   695,   696,
     697,    53,    54,   694,   958,   966,   970,   987,   995,  1002,
    1018,  1022,  1023,  1024,  1025,  1029,  1042,     8,   202,   681,
     683,   684,    10,    11,   673,   672,   976,   987,  1018,   195,
     639,   640,   634,  1028,    10,    11,   628,   629,   630,   624,
    1054,  1070,   235,  1063,   186,   236,  1056,  1057,  1070,   229,
     130,   217,   916,   917,   918,   919,  1044,     3,   191,   879,
     880,   874,  1028,    10,    11,   868,   869,   870,   864,  1054,
     218,  1070,  1070,   130,   809,   811,   812,  1045,  1047,  1048,
       6,     8,     8,   195,   777,   778,   772,  1028,    10,    11,
     766,   767,   768,   762,  1054,   186,  1070,  1070,   130,   179,
     698,   699,   700,   701,  1044,     3,    10,    11,   686,   687,
     688,    26,    43,   685,   974,   975,   999,  1000,  1001,  1042,
     180,   193,   646,   647,   641,  1028,    10,    11,   635,   636,
     637,   631,  1054,   190,  1070,    10,    11,  1064,  1065,  1066,
    1058,  1059,   130,   918,   920,   921,     8,   195,   886,   887,
     881,  1028,    10,    11,   875,   876,   877,   871,  1054,   186,
    1069,  1069,    10,    11,   814,   815,   813,   976,   979,   987,
    1006,  1018,    10,    11,  1050,  1051,  1052,   966,  1018,  1028,
    1049,  1070,   193,   784,   785,   779,  1028,    10,    11,   773,
     774,   775,   769,  1054,   190,   130,   700,   702,   703,     8,
     204,   667,     8,  1070,   197,   653,   654,   648,  1028,    10,
      11,   642,   643,   644,   638,  1054,   188,     6,     4,   232,
      10,  1061,   233,   234,  1060,  1067,  1068,    10,    11,   923,
     924,   922,   976,   979,   987,  1006,  1018,   193,   893,   894,
     888,  1028,    10,    11,   882,   883,   884,   878,  1054,   190,
    1070,  1070,   210,  1053,  1054,   197,   791,   792,   786,  1028,
      10,    11,   780,   781,   782,   776,  1054,   188,    10,    11,
     705,   706,   704,   976,   979,   987,  1006,  1018,   204,  1069,
       6,   655,  1028,    10,    11,   649,   650,   651,   645,  1054,
     192,  1070,   232,     6,  1070,  1070,   218,   197,   900,   901,
     895,  1028,    10,    11,   889,   890,   891,   885,  1054,   188,
     226,   793,  1028,    10,    11,   787,   788,   789,   783,  1054,
     192,   180,     8,  1070,    10,    11,   656,   657,   658,   652,
    1054,   196,   237,     6,     6,   902,  1028,    10,    11,   896,
     897,   898,   892,  1054,   192,    10,    11,   794,   795,   796,
     790,  1054,   196,   659,  1054,   194,  1070,  1070,    10,    11,
     903,   904,   905,   899,  1054,   196,   797,  1054,   194,   198,
     906,  1054,   194,   198,   198
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
    osol_errmsg = "";
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;
}
    break;

  case 12:

    {
		if (osol_errmsg != "")
		{
		    osol_errmsg += ("\n\nOSoL input is either not valid or well formed.\n"); 
		    osolerror( NULL, osoption, parserData, osglData, osol_errmsg);
		}
    }
    break;

  case 14:

    { osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "unexpected end of file, expecting </osol>");}
    break;

  case 17:

    {
	if (!osoption->setOptionHeader(osglData->fileName, osglData->source,
			osglData->description, osglData->fileCreator, osglData->licence) ) 	
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setHeader failed");
}
    break;

  case 18:

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

  case 32:

    {
    if (osglData->fileNamePresent == true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: file name");
	else
		osglData->fileNamePresent = true;
}
    break;

  case 37:

    {
	osglData->fileName = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 38:

    {
    if (osglData->sourcePresent == true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: source");
	else
		osglData->sourcePresent = true;
}
    break;

  case 43:

    {
	osglData->source = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 44:

    {
    if (osglData->descriptionPresent == true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: description");
	else
		osglData->descriptionPresent = true;
}
    break;

  case 49:

    {
	osglData->description = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 50:

    {
    if (osglData->fileCreatorPresent == true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: file creator");
	else
		osglData->fileCreatorPresent = true;
}
    break;

  case 55:

    {
	osglData->fileCreator = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 56:

    {
    if (osglData->licencePresent == true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated header information: licence");
	else
		osglData->licencePresent = true;
}
    break;

  case 61:

    {
	osglData->licence = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 64:

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

  case 85:

    {
	if (parserData->serviceURIPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <serviceURI>");
	else
		parserData->serviceURIPresent = true;
	
}
    break;

  case 91:

    {
		if (osoption->setServiceURI((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceURI failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 93:

    {
    	if (parserData->serviceNamePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <serviceName>");
		parserData->serviceNamePresent = true;
	}
    break;

  case 99:

    {
		if (osoption->setServiceName((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceName failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 101:

    {	if (parserData->instanceNamePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <instanceName>");
		parserData->instanceNamePresent = true;
	}
    break;

  case 107:

    {
		if (osoption->setInstanceName((yyvsp[(1) - (1)].sval)) == false) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setInstanceName failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 108:

    {
	if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setInstanceLocation failed");
	parserData->errorText = NULL;
}
    break;

  case 109:

    {
		if (parserData->instanceLocationPresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <instanceLocation>");
		parserData->instanceLocationPresent = true;
		parserData->typeAttribute = "local";
	}
    break;

  case 111:

    {   
		if (verifyLocationType(parserData->typeAttribute) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "instance location type not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 112:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 118:

    {	
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
		free((yyvsp[(1) - (1)].sval)); 
	}
    break;

  case 120:

    {	if (parserData->jobIDPresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <jobID>");
		parserData->jobIDPresent = true;
	}
    break;

  case 126:

    {
		if (osoption->setJobID((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setJobID failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 128:

    {
		if (parserData->solverToInvokePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <solverToInvoke>");
		parserData->solverToInvokePresent = true;
	}
    break;

  case 134:

    {
		if (osoption->setSolverToInvoke((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setSolverToInvoke failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 136:

    {
	if (parserData->licensePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <license>");
	parserData->licensePresent = true;	
}
    break;

  case 142:

    {
		if (osoption->setLicense((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setLicense failed");
		free((yyvsp[(1) - (1)].sval));
		parserData->errorText = NULL;
	}
    break;

  case 144:

    {	if (parserData->usernamePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <username>");
	parserData->usernamePresent = true;	
}
    break;

  case 150:

    {
		if (osoption->setUserName((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setUsername failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 152:

    {	if (parserData->passwordPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <password>");
	parserData->passwordPresent = true;	
}
    break;

  case 158:

    {
		if (osoption->setPassword((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setPassword failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 159:

    {
	if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setContact failed");
	parserData->errorText = NULL;
}
    break;

  case 160:

    {
	if (parserData->contactPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <contact>");
	parserData->contactPresent = true;
	parserData->typeAttribute = "osp";
	parserData->tempStr = "";
}
    break;

  case 162:

    {   
		if (verifyTransportType(parserData->typeAttribute) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "transport type not recognized");
	}
    break;

  case 163:

    { 
    	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
    	free((yyvsp[(2) - (3)].sval));
    }
    break;

  case 169:

    {
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
		free((yyvsp[(1) - (1)].sval));
	}
    break;

  case 170:

    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    }
    break;

  case 171:

    {
    	if (parserData->otherGeneralOptionsPresent)
        {
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <general> <otherOptions>");
            ignoreDataAfterErrors = true;            
        }
    	parserData->otherGeneralOptionsPresent = true;
    }
    break;

  case 172:

    {
    	if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other general options cannot be negative");
    	parserData->numberOf = parserData->tempInt;
    	parserData->kounter = 0;
    }
    break;

  case 173:

    {
    	if (parserData->numberOf > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 174:

    {
    	if (parserData->kounter < parserData->numberOf - 1)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 181:

    {	
	    parserData->kounter++;
        if (!ignoreDataAfterErrors)
    	    if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
	        	osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherGeneralOption failed");
    }
    break;

  case 182:

    {
	if (parserData->kounter >= parserData->numberOf)
    {
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 183:

    {
	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 186:

    {	if (parserData->nameAttribute.length() == 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 193:

    {
	parserData->minDiskSpacePresent = false;	
	parserData->minMemoryPresent = false;
	parserData->minCPUSpeedPresent = false;
	parserData->minCPUNumberPresent = false;
	parserData->otherSystemOptionsPresent = false;
	osoption->system = new SystemOption();
}
    break;

  case 208:

    {	if (parserData->minDiskSpacePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minDiskSpace element allowed");
		parserData->minDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 215:

    {
	if (osoption->setMinDiskSpace(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinDiskSpace failed");
	parserData->errorText = NULL;
}
    break;

  case 217:

    {	if (parserData->minMemoryPresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minMemory element allowed");
		parserData->minMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 224:

    {
	if (osoption->setMinMemorySize(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinMemorySize failed");
    parserData->errorText = NULL;
}
    break;

  case 226:

    {	if (parserData->minCPUSpeedPresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minCPUSpeed element allowed");
		parserData->minCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "hertz";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 233:

    {	
	if (osoption->setMinCPUSpeed(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
}
    break;

  case 235:

    {	if (parserData->minCPUNumberPresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minCPUNumber element allowed");
		parserData->minCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	}
    break;

  case 239:

    {
	if (osoption->setMinCPUNumber((yyvsp[(1) - (1)].ival), parserData->descriptionAttribute) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinCPUNumber failed");
	//free($1); 
	parserData->errorText = NULL; 
}
    break;

  case 240:

    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    }
    break;

  case 241:

    {
	if (parserData->otherSystemOptionsPresent)
        {
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <system> <otherOptions>");
            ignoreDataAfterErrors = true;
        }
	parserData->otherSystemOptionsPresent = true;
}
    break;

  case 242:

    {
	if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other system options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 243:

    {	if (parserData->numberOf > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 244:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 251:

    {
	    parserData->kounter++;
        if (!ignoreDataAfterErrors)
            if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherSystemOption failed");
    }
    break;

  case 252:

    {
	if (parserData->kounter >= parserData->numberOf)
    {
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 253:

    {	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 256:

    {
		if (parserData->nameAttribute.length() == 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 263:

    {
	parserData->serviceTypePresent = false;	
	parserData->otherServiceOptionsPresent = false;
	osoption->service = new ServiceOption();
}
    break;

  case 275:

    {	if (parserData->serviceTypePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one currentState element allowed");
		parserData->serviceTypePresent = true;
	}
    break;

  case 281:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); 
		free((yyvsp[(1) - (1)].sval));
		if (osoption->setServiceType(parserData->tempStr) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceType failed; current system state not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 282:

    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    }
    break;

  case 283:

    {
	if (parserData->otherServiceOptionsPresent)
        {
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <service> <otherOptions>");
            ignoreDataAfterErrors = true;            
        }
	parserData->otherServiceOptionsPresent = true;
}
    break;

  case 284:

    {
	if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other service options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 285:

    {	if (parserData->numberOf > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 286:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 293:

    {	
	    parserData->kounter++;
        if (!ignoreDataAfterErrors)
		    if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherServiceOption failed");
    }
    break;

  case 294:

    {
	if (parserData->kounter >= parserData->numberOf)
	{
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 295:

    {	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 298:

    {
		if (parserData->nameAttribute.length() == 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 305:

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

  case 329:

    {	
	if (osoption->setMaxTime(parserData->maxTimeValue, parserData->unitAttribute) == false)       
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "max time request could not be honored");
}
    break;

  case 330:

    {	
	if (parserData->maxTimePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <maxTime> element allowed");
	parserData->maxTimePresent = true;
	parserData->unitAttributePresent = false;	
	parserData->unitAttribute = "second"; 
	parserData->maxTimeValue = OSDBL_MAX;
}
    break;

  case 339:

    {
	parserData->maxTimeValue = parserData->tempVal;
}
    break;

  case 341:

    {	if (parserData->requestedStartTimePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one requestedStartTime element allowed");
		parserData->requestedStartTimePresent = true;
	}
    break;

  case 347:

    {
		if (osoption->setRequestedStartTime((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setRequestedStartTime failed");	
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
		}
    break;

  case 348:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <job> <dependencies> failed");
	delete[] parserData->jobDependencies;
	parserData->jobDependencies = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 349:

    {
	if (parserData->dependenciesPresent)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <dependencies> element allowed");
        ignoreDataAfterErrors = true;
	}
	parserData->dependenciesPresent = true;
}
    break;

  case 355:

    {
	if (parserData->kounter < parserData->numberOf)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few job IDs in <dependencies> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 358:

    {
	if (parserData->kounter >= parserData->numberOf)
    {
		if (!suppressFurtherErrorMessages)
		{
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many job IDs in <dependencies> element");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 359:

    {
	if (!ignoreDataAfterErrors)
	    if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
		    osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <requiredDirectories> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 360:

    {
	if (parserData->requiredDirectoriesPresent)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <requiredDirectories> element allowed");
        ignoreDataAfterErrors = true;
	}
	parserData->requiredDirectoriesPresent = true;
}
    break;

  case 365:

    {
	if (parserData->kounter < parserData->numberOf)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <requiredDirectories> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 366:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <requiredFiles> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 367:

    {
	if (parserData->requiredFilesPresent)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <requiredFiles> element allowed");
        ignoreDataAfterErrors = true;
	}
	parserData->requiredFilesPresent = true;
}
    break;

  case 372:

    {
	if (parserData->kounter < parserData->numberOf)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <requiredFiles> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 373:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <directoriesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 374:

    {
	if (parserData->directoriesToMakePresent)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <directoriesToMake> element allowed");
        ignoreDataAfterErrors = true;
	}
	parserData->directoriesToMakePresent = true;
}
    break;

  case 379:

    {
	if (parserData->kounter < parserData->numberOf)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <directoriesToMake> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 380:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <filesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 381:

    {
	if (parserData->filesToMakePresent)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <filesToMake> element allowed");
        ignoreDataAfterErrors = true;
	}
	parserData->filesToMakePresent = true;
}
    break;

  case 386:

    {
	if (parserData->kounter < parserData->numberOf)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <filesToMake> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 387:

    {
	if (!ignoreDataAfterErrors)
    	if (osoption->setPathPairs(ENUM_PATHPAIR_input_dir, parserData->fromPaths, 
    			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMove> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;
}
    break;

  case 388:

    {
	if (parserData->inputDirectoriesToMovePresent)
    {
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <inputDirectoriesToMove> element allowed");
        ignoreDataAfterErrors = true;
	}
	parserData->inputDirectoriesToMovePresent = true;
}
    break;

  case 394:

    {
	if (parserData->kounter < parserData->numberOfPathPairs)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <inputDirectoriesToMove> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 398:

    {
	if (!ignoreDataAfterErrors)
    	if (osoption->setPathPairs(ENUM_PATHPAIR_input_file, parserData->fromPaths, 
    			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputFilesToMove> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 399:

    {
	if (parserData->inputFilesToMovePresent)
    {
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <inputFilesToMove> element allowed");
        ignoreDataAfterErrors = true;
    }
	parserData->inputFilesToMovePresent = true;
}
    break;

  case 405:

    {
	if (parserData->kounter < parserData->numberOfPathPairs)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <inputFilesToMove> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 409:

    {
	if (!ignoreDataAfterErrors)
    	if (osoption->setPathPairs(ENUM_PATHPAIR_output_file, parserData->fromPaths, 
    			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 410:

    {
	if (parserData->outputFilesToMovePresent)
    {
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <outputFilesToMove> element allowed");
        ignoreDataAfterErrors = true;
	}
	parserData->outputFilesToMovePresent = true;
}
    break;

  case 416:

    {
	if (parserData->kounter < parserData->numberOfPathPairs)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <outputFilesToMake> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 420:

    {
	if (!ignoreDataAfterErrors)
    	if (osoption->setPathPairs(ENUM_PATHPAIR_output_dir, parserData->fromPaths, 
    			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 421:

    {
	if (parserData->outputDirectoriesToMovePresent)
    {
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <outputDirectoriesToMove> element allowed");
        ignoreDataAfterErrors = true;
	}
	parserData->outputDirectoriesToMovePresent = true;
}
    break;

  case 427:

    {
	if (parserData->kounter < parserData->numberOfPathPairs)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <outputDirectoriesToMake> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 431:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <filesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 432:

    {
	if (parserData->filesToDeletePresent)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <filesToDelete> element allowed");
        ignoreDataAfterErrors = true;
	}
	parserData->filesToDeletePresent = true;
}
    break;

  case 438:

    {
	if (parserData->kounter < parserData->numberOf)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <filesToDelete> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 439:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <directoriesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 440:

    {
	if (parserData->directoriesToDeletePresent)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <directoriesToDelete> element allowed");
        ignoreDataAfterErrors = true;
	}
	parserData->directoriesToDeletePresent = true;
}
    break;

  case 446:

    {
	if (parserData->kounter < parserData->numberOf)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <directoriesToDelete> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 447:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <processesToKill> failed");
	delete[] parserData->processesToKill;
	parserData->processesToKill = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 448:

    {
	if (parserData->processesToKillPresent)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <processesToKill> element allowed");
        ignoreDataAfterErrors = true;
	}
	parserData->processesToKillPresent = true;
}
    break;

  case 454:

    {
	if (parserData->kounter < parserData->numberOf)
	{
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few process IDs in <processesToKill> element");
		ignoreDataAfterErrors = true;        
	}
}
    break;

  case 457:

    {
	if (parserData->kounter >= parserData->numberOf)
	{
	if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many process IDs in <processesToKill> element");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 458:

    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    }
    break;

  case 459:

    {
	if (parserData->otherJobOptionsPresent)
        {
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Repeated element: <job> <otherOptions>");
            ignoreDataAfterErrors = true;            
        }
	parserData->otherJobOptionsPresent = true;
}
    break;

  case 460:

    {
	if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other job options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 461:

    {	if (parserData->numberOf > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 462:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 469:

    {
	    parserData->kounter++;
        if (!ignoreDataAfterErrors)
	        if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
	        	osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherJobOption failed");
    }
    break;

  case 470:

    {
	if (parserData->kounter >= parserData->numberOf)
	{
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 471:

    {
	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 474:

    {
		if (parserData->nameAttribute.length() == 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 481:

    {
	osoption->optimization = new OptimizationOption();
	parserData->numberOfVariablesPresent = false;
	parserData->numberOfObjectivesPresent = false;
	parserData->numberOfConstraintsPresent = false;
}
    break;

  case 485:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osoption->setNumberOfVariables(parserData->tempInt) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfVariables failed");
	}
    break;

  case 486:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfConstraints failed");
	}
    break;

  case 487:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfObjectives failed");
	}
    break;

  case 495:

    {
	parserData->numberOfOtherVariableOptions = 0;
	osoption->optimization->variables = new VariableOption();
}
    break;

  case 496:

    {	
	if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
}
    break;

  case 498:

    {	
	parserData->numberOfOtherVariableOptions = parserData->tempInt;
}
    break;

  case 503:

    {
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        

}
    break;

  case 505:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitVarValues(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 506:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 507:

    {
	parserData->kounter = 0;
	parserData->idxArray = new         int[parserData->numberOfVar];
	parserData->namArray = new std::string[parserData->numberOfVar];
	parserData->valArray = new      double[parserData->numberOfVar];
	for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 508:

    {
		if (parserData->numberOfVar > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValues>: expected at least one <var> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 509:

    {
		if (parserData->kounter < parserData->numberOfVar)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValues>: fewer <var> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 516:

    {
	parserData->kounter++;
}
    break;

  case 517:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
		}
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
}
    break;

  case 518:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 521:

    {
		if (parserData->idxAttribute < 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
		if (!ignoreDataAfterErrors)
			parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 522:

    {
		if (!ignoreDataAfterErrors)
			parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 523:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		if (!ignoreDataAfterErrors)
			parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 527:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString, parserData->namArray) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValuesString> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valueString;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valueString = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 528:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 529:

    {
	parserData->kounter = 0;
	parserData->idxArray    = new         int[parserData->numberOfVar];
	parserData->namArray    = new std::string[parserData->numberOfVar];
	parserData->valueString = new std::string[parserData->numberOfVar];
	for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfVar; i++) parserData->valueString[i] = "";
}
    break;

  case 530:

    {
		if (parserData->numberOfVar > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValuesString>: expected at least one <var> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 531:

    {
		if (parserData->kounter < parserData->numberOfVar)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few initial values in <initialVariableValuesString> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 538:

    {
	parserData->kounter++;
}
    break;

  case 539:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
		}
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "48r 87e WY EUV e7 df"; //random string...
}
    break;

  case 540:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 543:

    {
		if (parserData->idxAttribute < 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
		if (!ignoreDataAfterErrors)
			parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 544:

    {
		if (!ignoreDataAfterErrors)
			parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 545:

    {
		if (!ignoreDataAfterErrors)
			parserData->valueString[parserData->kounter] = parserData->valueAttribute;
	}
    break;

  case 550:

    {
	osoption->optimization->variables->initialBasisStatus = new BasisStatus();
}
    break;

  case 557:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 558:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 559:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 566:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 567:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 568:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 575:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 576:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 577:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 584:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atEquality failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 585:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 586:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 593:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 594:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 595:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 602:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 603:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 604:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 611:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 612:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 613:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 620:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 621:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 622:

    {
	parserData->kounter = 0;
	parserData->idxArray = new         int[parserData->numberOfVar];
	parserData->namArray = new std::string[parserData->numberOfVar];
	parserData->valArray = new      double[parserData->numberOfVar];
	for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 623:

    {
		if (parserData->numberOfVar > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <var> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 624:

    {
		if (parserData->kounter < parserData->numberOfVar)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <var> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 631:

    {
	parserData->kounter++;
}
    break;

  case 632:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
		}
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "1.0";
}
    break;

  case 633:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 636:

    {
		if (parserData->idxAttribute < 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
		if (!ignoreDataAfterErrors)
			parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 637:

    {
		if (!ignoreDataAfterErrors)
			parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 638:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		if (!ignoreDataAfterErrors)
			parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 642:

    {
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 643:

    {
	parserData->sosIdxAttributePresent = false;	
	parserData->currentSOS = 0;
}
    break;

  case 644:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <sos> elements must be nonnegative");
	parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
}
    break;

  case 645:

    {
		if (parserData->numberOfSOS > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <sos> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 646:

    {	if (parserData->currentSOS != parserData->numberOfSOS)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <sos> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 652:

    {
	if (!ignoreDataAfterErrors)
		if (!osoption->setAnotherSOSVariableBranchingWeight(parserData->sosIdx, 
					parserData->numberOfVar, parserData->groupWeight,
					parserData->idxArray,	 parserData->valArray, parserData->namArray) )
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "error processing SOS branching weights");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
	parserData->currentSOS++;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 653:

    {
	if (parserData->currentSOS >= parserData->numberOfSOS)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many SOS branching weights");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
		}
	parserData->sosIdxAttributePresent = false;
	parserData->groupWeightAttributePresent = false;
	parserData->numberOfVarAttributePresent = false;
	parserData->groupWeight = 1.0;
	parserData->numberOfSOSVar = 0;
}
    break;

  case 654:

    {
	if (!parserData->sosIdxAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index required");
	if (!parserData->numberOfVarAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar required");
}
    break;

  case 658:

    {
		parserData->kounter = 0;
		parserData->idxArray = new         int[parserData->numberOfVar];
		parserData->namArray = new std::string[parserData->numberOfVar];
		parserData->valArray = new      double[parserData->numberOfVar];
		for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
		parserData->numberOfVarAttributePresent = true;
	}
    break;

  case 667:

    { 	 
		parserData->iOther++;
	}
    break;

  case 668:

    {
	if (parserData->iOther >= parserData->numberOfOtherVariableOptions)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherVariableOptions> than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 669:

    {
		if (!parserData->nameAttributePresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
		if (!ignoreDataAfterErrors)
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
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
	}
    break;

  case 672:

    {
		parserData->kounter = 0;
	}
    break;

  case 673:

    {
		parserData->kounter = 0;
	}
    break;

  case 691:

    { 	
	if (!ignoreDataAfterErrors)
		if (!osoption->setOtherVariableOptionVar(
				parserData->iOther, 
				parserData->kounter,
				parserData->idxAttribute, 
				parserData->nameAttribute,
				parserData->valueAttribute,
				parserData->lbValueAttribute, 
				parserData->ubValueAttribute) )
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set other variable option <var> element failed");
	parserData->kounter++;
}
    break;

  case 692:

    {
	if (parserData->kounter >= parserData->numberOfVar)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 696:

    {
		if (parserData->idxAttribute < 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
	}
    break;

  case 706:

    {
	parserData->numberOfOtherObjectiveOptions = 0; 
	osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 707:

    {	
	if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
}
    break;

  case 709:

    {	
	parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
}
    break;

  case 714:

    {
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        

}
    break;

  case 716:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitObjValues(parserData->numberOfObj, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialObjectiveValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 717:

    {
	parserData->numberOfObjAttributePresent = false;
}
    break;

  case 718:

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

  case 719:

    {	
		if (parserData->numberOfObj > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: expected at least one <obj> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 720:

    {
		if (parserData->kounter < parserData->numberOfObj)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: fewer <obj> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 727:

    {
	parserData->kounter++;
}
    break;

  case 728:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <obj> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
		}
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->idxAttribute = -1;
}
    break;

  case 732:

    {
		if (parserData->idxAttribute >= 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be negative");
		if (osoption->optimization->numberOfObjectives >= 0)
		{
			if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 733:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 734:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 738:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitObjBounds(parserData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialObjectiveBounds> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->lbValArray;
	delete[] parserData->ubValArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->lbValArray = NULL;
	parserData->ubValArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 739:

    {
	parserData->numberOfObjAttributePresent = false;
}
    break;

  case 740:

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

  case 741:

    {
		if (parserData->numberOfObj > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: expected at least one <obj> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 742:

    {
		if (parserData->kounter < parserData->numberOfObj)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 749:

    {
	parserData->kounter++;
}
    break;

  case 750:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 754:

    {
		if (parserData->idxAttribute >= 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be nonnegative");
		if (osoption->optimization->numberOfObjectives >= 0)
		{
			if (parserData->idxAttribute < -osoption->optimization->numberOfVariables)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 755:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 756:

    {
		if (parserData->lbValueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
	}
    break;

  case 757:

    {
		if (parserData->ubValueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
	}
    break;

  case 762:

    {
	osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
}
    break;

  case 769:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 770:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 771:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 778:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 779:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 780:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 787:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 788:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 789:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 796:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atEquality failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 797:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 798:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 805:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 806:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 807:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 814:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 815:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 816:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 823:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 824:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 825:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 833:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 834:

    {
	if (parserData->iOther >= parserData->numberOfOtherObjectiveOptions)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherObjectiveOptions> than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 835:

    {
		if (!parserData->nameAttributePresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
		if (!ignoreDataAfterErrors)
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
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
	}
    break;

  case 838:

    {
		parserData->kounter = 0;
	}
    break;

  case 839:

    {
		parserData->kounter = 0;
	}
    break;

  case 857:

    {  
	if (!ignoreDataAfterErrors)
		if (!osoption->setOtherObjectiveOptionObj(
				parserData->iOther, 
				parserData->kounter,
				parserData->idxAttribute, 
				parserData->nameAttribute,
				parserData->valueAttribute,
				parserData->lbValueAttribute, 
				parserData->ubValueAttribute) )
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set other objective option <obj> element failed");
	parserData->kounter++;
}
    break;

  case 858:

    {

	if (parserData->kounter >= parserData->numberOfObj)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <obj> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 862:

    {
		if (parserData->idxAttribute >= 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index must be negative");
		if (osoption->optimization->numberOfObjectives >= 0)
		{
			if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "objective index exceeds limit");
		};
	}
    break;

  case 872:

    {
	parserData->numberOfOtherConstraintOptions = 0; 
	osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 873:

    {	
	if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherConstraintOptions failed");
	parserData->iOther = 0;
}
    break;

  case 875:

    {	
	parserData->numberOfOtherConstraintOptions = parserData->tempInt;
}
    break;

  case 880:

    {
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        

}
    break;

  case 882:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitConValues(parserData->numberOfCon, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 883:

    {
	parserData->numberOfConAttributePresent = false;
}
    break;

  case 884:

    {
	parserData->kounter = 0;
	parserData->idxArray = new         int[parserData->numberOfCon];
	parserData->namArray = new std::string[parserData->numberOfCon];
	parserData->valArray = new      double[parserData->numberOfCon];
	for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfCon; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 885:

    {
		if (parserData->numberOfCon > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: expected at least one <con element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 886:

    {
		if (parserData->kounter < parserData->numberOfCon)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: fewer <con> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 893:

    {
	parserData->kounter++;
}
    break;

  case 894:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
		}
	parserData->idxAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
}
    break;

  case 895:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 898:

    {
		if (parserData->idxAttribute < 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
		if (osoption->optimization->numberOfConstraints >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 899:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 900:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 904:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitDualValues(parserData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->lbValArray;
	delete[] parserData->ubValArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->lbValArray = NULL;
	parserData->ubValArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 905:

    {
	parserData->numberOfConAttributePresent = false;
}
    break;

  case 906:

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

  case 907:

    {
		if (parserData->numberOfCon > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: expected at least one <con> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 908:

    {
		if (parserData->kounter < parserData->numberOfCon)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: fewer <con> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 915:

    {	
	parserData->kounter++;
}
    break;

  case 916:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 917:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 920:

    {
		if (parserData->idxAttribute < 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
		if (osoption->optimization->numberOfConstraints >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 921:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 922:

    {
		parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
	}
    break;

  case 923:

    {
		parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
	}
    break;

  case 928:

    {
	osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
}
    break;

  case 935:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 936:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 937:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 944:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 945:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 946:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 953:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 954:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 955:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 962:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atEquality failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 963:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 964:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 971:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 972:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 973:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 980:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 981:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 982:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 989:

    {
	if (!ignoreDataAfterErrors)
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 990:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 991:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 999:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 1000:

    {
	if (parserData->iOther >= parserData->numberOfOtherConstraintOptions)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherConstraintOptions> than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 1001:

    {
		if(!parserData->nameAttributePresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
		if (!ignoreDataAfterErrors)
			if (!osoption->setOtherConstraintOptionAttributes(
					parserData->iOther,
					parserData->numberOfCon,
					parserData->numberOfEnumerations,
					parserData->nameAttribute,
					parserData->valueAttribute,
					parserData->solverAttribute,
					parserData->categoryAttribute,
					parserData->typeAttribute,
					parserData->objTypeAttribute,
					parserData->enumTypeAttribute,
					parserData->descriptionAttribute) )
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
	}
    break;

  case 1004:

    {
		parserData->kounter = 0;
	}
    break;

  case 1005:

    {
		parserData->kounter = 0;
	}
    break;

  case 1023:

    { 	
	if (!ignoreDataAfterErrors)
		if (!osoption->setOtherConstraintOptionCon(
				parserData->iOther, 
				parserData->kounter,
				parserData->idxAttribute, 
				parserData->nameAttribute,
				parserData->valueAttribute,
				parserData->lbValueAttribute, 
				parserData->ubValueAttribute) )
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set other constraint option <con> element failed");
	parserData->kounter++;
}
    break;

  case 1024:

    {
	if (parserData->kounter >= parserData->numberOfCon)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 1028:

    {
		if (parserData->idxAttribute < 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
		if (osoption->optimization->numberOfConstraints >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
		};
	}
    break;

  case 1037:

    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    }
    break;

  case 1039:

    {
	if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfSolverOptions failed");
	parserData->iOption = 0;
}
    break;

  case 1040:

    {
		if (parserData->numberOfSolverOptions > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <solverOption> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1041:

    {
		if (parserData->iOption != parserData->numberOfSolverOptions)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <solverOption> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1046:

    {
    if (!ignoreDataAfterErrors)
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
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setSolverOptionContent failed");
	if (parserData->numberOfItems > 0)
		delete[] parserData->itemList;
	parserData->itemList = NULL;
	parserData->iOption++;
}
    break;

  case 1047:

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

  case 1048:

    {
	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "name attribute must be present");
}
    break;

  case 1057:

    {
			parserData->itemList = new std::string[parserData->numberOfItems];
    }
    break;

  case 1058:

    {
		if (parserData->numberOfItems > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <item> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1059:

    {
		if (parserData->kounter < parserData->numberOfItems)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <item> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1066:

    {	
	parserData->itemList[parserData->kounter] = parserData->itemContent;
	parserData->kounter++;
}
    break;

  case 1067:

    {
		if (parserData->kounter >= parserData->numberOfItems)
			if (!suppressFurtherErrorMessages)
			{
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <item> elements than specified");
				suppressFurtherErrorMessages = true;
				ignoreDataAfterErrors = true;
			}
		parserData->itemContent = "";			
	}
    break;

  case 1072:

    {
	if (parserData->kounter >= parserData->numberOf)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <item> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
		}
	parserData->itemContent = (yyvsp[(1) - (1)].sval); 
	free((yyvsp[(1) - (1)].sval));
}
    break;

  case 1075:

    {
	if (parserData->kounter >= parserData->numberOf)
    {
		if (!suppressFurtherErrorMessages)
		{
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many paths in <requiredDirectories> element");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
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

  case 1076:

    {	
	if (parserData->kounter >= parserData->numberOfPathPairs)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many path pairs");
    else
    {
    	if (!parserData->pathPairFromPresent)
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "\"from\" attribute must be present");
    	if (!parserData->pathPairToPresent)
    		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "\"to\" attribute must be present");
       	parserData->fromPaths[parserData->kounter] = parserData->pathPairFrom;
       	parserData->toPaths[parserData->kounter] = parserData->pathPairTo;
	    parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
     	parserData->kounter++;
    }
}
    break;

  case 1077:

    {
//	if (parserData->kounter >= parserData->numberOfPathPairs)
//		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many path pairs");
	parserData->pathPairFrom = "";
	parserData->pathPairTo = "";
	parserData->pathPairFromPresent = false;
	parserData->pathPairToPresent = false;
	parserData->pathPairMakeCopyPresent = false;
	parserData->pathPairMakeCopy = false;
}
    break;

  case 1078:

    {
//	parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 1084:

    {
	if (parserData->pathPairFromPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"from\" attribute allowed");
	parserData->pathPairFromPresent = true;
	parserData->pathPairFrom = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1085:

    {
	if (parserData->pathPairToPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"to\" attribute allowed");
	parserData->pathPairToPresent = true;
	parserData->pathPairTo = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1086:

    {
	if (parserData->pathPairMakeCopyPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"makeCopy\" attribute allowed");
	parserData->pathPairMakeCopyPresent = true;
	parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1089:

    {   
	if (parserData->categoryAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one category attribute allowed for this element");
	parserData->categoryAttributePresent = true;
}
    break;

  case 1092:

    { 
	parserData->categoryAttribute = "";
}
    break;

  case 1093:

    { 
	parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1094:

    {   if (parserData->conTypeAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one conType attribute allowed for this element");
			parserData->conTypeAttributePresent = true;
		}
    break;

  case 1097:

    { parserData->conTypeAttribute = ""; }
    break;

  case 1098:

    { 
	parserData->conTypeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1099:

    {
	if (parserData->descriptionAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one description attribute allowed for this element");
	parserData->descriptionAttributePresent = true;
}
    break;

  case 1102:

    { parserData->descriptionAttribute = ""; }
    break;

  case 1103:

    { 
	parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1104:

    {   if (parserData->enumTypeAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one enumType attribute allowed for this element");
			parserData->enumTypeAttributePresent = true;
		}
    break;

  case 1107:

    { parserData->enumTypeAttribute = ""; }
    break;

  case 1108:

    { 
	parserData->enumTypeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1109:

    {
	if (parserData->groupWeightAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one groupWeight attribute allowed for this element");
	parserData->groupWeightAttributePresent = true;
}
    break;

  case 1110:

    {
	parserData->groupWeight = parserData->tempVal;
}
    break;

  case 1111:

    {   
	if (parserData->idxAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one idx attribute allowed for this element");
	parserData->idxAttributePresent = true;
}
    break;

  case 1113:

    { 
	parserData->idxAttribute = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1114:

    {   
	if (parserData->lbValueAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
	parserData->lbValueAttributePresent = true;
}
    break;

  case 1117:

    { 
	parserData->lbValueAttribute = ""; 
}
    break;

  case 1118:

    { 
	parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1119:

    {   if (parserData->lbValueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
			parserData->lbValueAttributePresent = true;
		}
    break;

  case 1122:

    { 
    parserData->lbDualValue = 0.0; 
}
    break;

  case 1123:

    {
    parserData->lbDualValue = parserData->tempVal;
}
    break;

  case 1124:

    {
        if (parserData->nameAttributePresent ) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one name attribute allowed for this element");
		parserData->nameAttributePresent = true;
	}
    break;

  case 1127:

    { 
        parserData->nameAttribute = ""; 
    }
    break;

  case 1128:

    { 
	    parserData->nameAttribute = (yyvsp[(2) - (3)].sval); 
    	free((yyvsp[(2) - (3)].sval));
    }
    break;

  case 1129:

    {   if (parserData->objTypeAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one objType attribute allowed for this element");
			parserData->objTypeAttributePresent = true;
		}
    break;

  case 1132:

    { parserData->objTypeAttribute = ""; }
    break;

  case 1133:

    { 
	parserData->objTypeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1134:

    {   if (parserData->solverAttributePresent ) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one solver attribute allowed for this element");
		parserData->solverAttributePresent = true;
	}
    break;

  case 1137:

    { parserData->solverAttribute = ""; }
    break;

  case 1138:

    { 
	parserData->solverAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1139:

    {   if (parserData->sosIdxAttributePresent ) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one sosIdx attribute allowed for this element");
		parserData->sosIdxAttributePresent = true;
	}
    break;

  case 1141:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index must be nonnegative");
	parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1142:

    {   if (parserData->typeAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		}
    break;

  case 1145:

    { parserData->typeAttribute = ""; }
    break;

  case 1146:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1147:

    {
   if (parserData->ubValueAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
	parserData->ubValueAttributePresent = true;
}
    break;

  case 1150:

    { 
	parserData->ubValueAttribute = ""; 
}
    break;

  case 1151:

    { 
	parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1152:

    {   if (parserData->ubValueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
			parserData->ubValueAttributePresent = true;
		}
    break;

  case 1155:

    { parserData->ubDualValue = 0.0; }
    break;

  case 1156:

    { 
	parserData->ubDualValue = parserData->tempVal;
}
    break;

  case 1157:

    {   if (parserData->unitAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		}
    break;

  case 1160:

    { parserData->unitAttribute = ""; }
    break;

  case 1161:

    { 
	parserData->unitAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1162:

    {   if (parserData->valueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		}
    break;

  case 1165:

    { parserData->valueAttribute = ""; }
    break;

  case 1166:

    {
	parserData->valueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1167:

    {   if (parserData->varTypeAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one varType attribute allowed for this element");
			parserData->varTypeAttributePresent = true;
		}
    break;

  case 1170:

    { parserData->varTypeAttribute = ""; }
    break;

  case 1171:

    { 
	parserData->varTypeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1172:

    {
	if (parserData->numberOfConAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfConAttributePresent = true;		
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1173:

    {
	if (parserData->numberOfConstraintsPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of constraints cannot be negative");
	parserData->numberOfConstraintsPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1174:

    {
	if (osglData->osglNumberOfElPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEl attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <el> cannot be negative");
	osglData->osglNumberOfElPresent = true;
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1175:

    {
	if (parserData->numberOfEnumerationsAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEnumerations attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerationsAttributePresent = true;		
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1176:

    {	
   if (parserData->numberOfItemsPresent ) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1177:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
    	parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
}
    break;

  case 1178:

    {
	if (parserData->numberOfObjAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObjAttributePresent = true;		
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1179:

    {
	if (parserData->numberOfObjectivesPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of objectives cannot be negative");
	parserData->numberOfObjectivesPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1180:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other constraint options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1181:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other objective options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1182:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1183:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other variable options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1184:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of path pairs cannot be negative");
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

  case 1185:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of paths cannot be negative");
	else
		parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
}
    break;

  case 1186:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
    	parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
}
    break;

  case 1187:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of solver options cannot be negative");
	parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1188:

    {
	if (parserData->numberOfVarAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVarAttributePresent = true;		
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1189:

    {	if (parserData->numberOfVariablesPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of variables cannot be negative");
	parserData->numberOfVariablesPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1192:

    { 	
	if (!ignoreDataAfterErrors)
		if (!osoption->setOtherOptionEnumeration(parserData->otherOptionType, 
				parserData->iOther,
				parserData->kounter,
				osglData->osglNumberOfEl, 
				parserData->valueAttribute, 
				parserData->descriptionAttribute, 
				osglData->osglIntArray) )
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <other> option enumeration failed");

	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
}
    break;

  case 1193:

    {
	if (parserData->kounter >= parserData->numberOfEnumerations)
		if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <enumeration> elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
		}
	osglData->osglNumberOfElPresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 1194:

    {
		if(!osglData->osglNumberOfElPresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires numberOfEl attribute"); 
		if(!parserData->valueAttributePresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires value attribute"); 
	}
    break;

  case 1197:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfElPresent = true;
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 1205:

    {
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer data elements than specified");
			ignoreDataAfterErrors = true;
		}
	}
    break;

  case 1210:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
}
    break;

  case 1216:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
	{
    	if (!suppressFurtherErrorMessages)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more data elements than specified");
			suppressFurtherErrorMessages = true;
			ignoreDataAfterErrors = true;
		}
    }
	else
		for (int i=0; i<osglData->osglMult; i++)
			osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
}
    break;

  case 1218:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1223:

    {
	char* b64string = (yyvsp[(2) - (3)].sval);
	if( b64string == NULL) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 data expected"); 
	if (osglData->osglSize != sizeof(int))
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

	std::string base64decodeddata = Base64::decodeb64( b64string );
	int base64decodeddatalength = base64decodeddata.length();
	int *intvec = NULL;
	if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "base 64 data length does not match numberOfEl"); 
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

  case 1224:

    {	
	if (osglData->osglIncrPresent) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1225:

    {	
	if (osglData->osglMultPresent) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1226:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1227:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
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


