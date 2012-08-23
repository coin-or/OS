
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
     EMPTYTYPEATT = 302,
     EMPTYNAMEATT = 303,
     EMPTYCATEGORYATT = 304,
     EMPTYDESCRIPTIONATT = 305,
     EMPTYUNITATT = 306,
     EMPTYVALUEATT = 307,
     EMPTYLBVALUEATT = 308,
     EMPTYUBVALUEATT = 309,
     LBVALUEATT = 310,
     UBVALUEATT = 311,
     EMPTYLBDUALVALUEATT = 312,
     EMPTYUBDUALVALUEATT = 313,
     LBDUALVALUEATT = 314,
     UBDUALVALUEATT = 315,
     SOLVERATT = 316,
     EMPTYSOLVERATT = 317,
     WEIGHTATT = 318,
     EMPTYWEIGHTATT = 319,
     TRANSPORTTYPEATT = 320,
     LOCATIONTYPEATT = 321,
     HEADERSTART = 322,
     HEADEREND = 323,
     GENERALSTART = 324,
     GENERALEND = 325,
     SYSTEMSTART = 326,
     SYSTEMEND = 327,
     SERVICESTART = 328,
     SERVICEEND = 329,
     JOBSTART = 330,
     JOBEND = 331,
     OPTIMIZATIONSTART = 332,
     OPTIMIZATIONEND = 333,
     FILENAMESTART = 334,
     FILENAMEEND = 335,
     FILENAMEEMPTY = 336,
     FILENAMESTARTANDEND = 337,
     FILESOURCESTART = 338,
     FILESOURCEEND = 339,
     FILESOURCEEMPTY = 340,
     FILESOURCESTARTANDEND = 341,
     FILEDESCRIPTIONSTART = 342,
     FILEDESCRIPTIONEND = 343,
     FILEDESCRIPTIONEMPTY = 344,
     FILEDESCRIPTIONSTARTANDEND = 345,
     FILECREATORSTART = 346,
     FILECREATOREND = 347,
     FILECREATOREMPTY = 348,
     FILECREATORSTARTANDEND = 349,
     FILELICENCESTART = 350,
     FILELICENCEEND = 351,
     FILELICENCEEMPTY = 352,
     FILELICENCESTARTANDEND = 353,
     SERVICEURISTART = 354,
     SERVICEURIEND = 355,
     SERVICENAMESTART = 356,
     SERVICENAMEEND = 357,
     INSTANCENAMESTART = 358,
     INSTANCENAMEEND = 359,
     INSTANCELOCATIONSTART = 360,
     INSTANCELOCATIONEND = 361,
     JOBIDSTART = 362,
     JOBIDEND = 363,
     SOLVERTOINVOKESTART = 364,
     SOLVERTOINVOKEEND = 365,
     LICENSESTART = 366,
     LICENSEEND = 367,
     USERNAMESTART = 368,
     USERNAMEEND = 369,
     PASSWORDSTART = 370,
     PASSWORDEND = 371,
     CONTACTSTART = 372,
     CONTACTEND = 373,
     OTHEROPTIONSSTART = 374,
     OTHEROPTIONSEND = 375,
     OTHERSTART = 376,
     OTHEREND = 377,
     MINDISKSPACESTART = 378,
     MINDISKSPACEEND = 379,
     MINMEMORYSTART = 380,
     MINMEMORYEND = 381,
     MINCPUSPEEDSTART = 382,
     MINCPUSPEEDEND = 383,
     MINCPUNUMBERSTART = 384,
     MINCPUNUMBEREND = 385,
     SERVICETYPESTART = 386,
     SERVICETYPEEND = 387,
     MAXTIMESTART = 388,
     MAXTIMEEND = 389,
     REQUESTEDSTARTTIMESTART = 390,
     REQUESTEDSTARTTIMEEND = 391,
     DEPENDENCIESSTART = 392,
     DEPENDENCIESEND = 393,
     REQUIREDDIRECTORIESSTART = 394,
     REQUIREDDIRECTORIESEND = 395,
     REQUIREDFILESSTART = 396,
     REQUIREDFILESEND = 397,
     PATHSTART = 398,
     PATHEND = 399,
     PATHPAIRSTART = 400,
     PATHPAIREND = 401,
     DIRECTORIESTOMAKESTART = 402,
     DIRECTORIESTOMAKEEND = 403,
     FILESTOMAKESTART = 404,
     FILESTOMAKEEND = 405,
     DIRECTORIESTODELETESTART = 406,
     DIRECTORIESTODELETEEND = 407,
     FILESTODELETESTART = 408,
     FILESTODELETEEND = 409,
     INPUTDIRECTORIESTOMOVESTART = 410,
     INPUTDIRECTORIESTOMOVEEND = 411,
     INPUTFILESTOMOVESTART = 412,
     INPUTFILESTOMOVEEND = 413,
     OUTPUTDIRECTORIESTOMOVESTART = 414,
     OUTPUTDIRECTORIESTOMOVEEND = 415,
     OUTPUTFILESTOMOVESTART = 416,
     OUTPUTFILESTOMOVEEND = 417,
     PROCESSESTOKILLSTART = 418,
     PROCESSESTOKILLEND = 419,
     PROCESSSTART = 420,
     PROCESSEND = 421,
     VARIABLESSTART = 422,
     VARIABLESEND = 423,
     INITIALVARIABLEVALUESSTART = 424,
     INITIALVARIABLEVALUESEND = 425,
     VARSTART = 426,
     VAREND = 427,
     INITIALVARIABLEVALUESSTRINGSTART = 428,
     INITIALVARIABLEVALUESSTRINGEND = 429,
     INITIALBASISSTATUSSTART = 430,
     INITIALBASISSTATUSEND = 431,
     BASICSTART = 432,
     BASICEND = 433,
     ATUPPERSTART = 434,
     ATUPPEREND = 435,
     ATLOWERSTART = 436,
     ATLOWEREND = 437,
     ATEQUALITYSTART = 438,
     ATEQUALITYEND = 439,
     SUPERBASICSTART = 440,
     SUPERBASICEND = 441,
     ISFREESTART = 442,
     ISFREEEND = 443,
     UNKNOWNSTART = 444,
     UNKNOWNEND = 445,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 446,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 447,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 448,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 449,
     SOSSTART = 450,
     SOSEND = 451,
     OBJECTIVESSTART = 452,
     OBJECTIVESEND = 453,
     INITIALOBJECTIVEVALUESSTART = 454,
     INITIALOBJECTIVEVALUESEND = 455,
     OBJSTART = 456,
     OBJEND = 457,
     INITIALOBJECTIVEBOUNDSSTART = 458,
     INITIALOBJECTIVEBOUNDSEND = 459,
     CONSTRAINTSSTART = 460,
     CONSTRAINTSEND = 461,
     INITIALCONSTRAINTVALUESSTART = 462,
     INITIALCONSTRAINTVALUESEND = 463,
     CONSTART = 464,
     CONEND = 465,
     INITIALDUALVALUESSTART = 466,
     INITIALDUALVALUESEND = 467,
     SOLVEROPTIONSSTART = 468,
     SOLVEROPTIONSEND = 469,
     SOLVEROPTIONSTART = 470,
     SOLVEROPTIONEND = 471,
     ENUMERATIONSTART = 472,
     ENUMERATIONEND = 473,
     ITEMEMPTY = 474,
     ITEMSTART = 475,
     ITEMEND = 476,
     ITEMSTARTANDEND = 477,
     BASE64START = 478,
     BASE64END = 479,
     INCRATT = 480,
     MULTATT = 481,
     SIZEOFATT = 482,
     ELSTART = 483,
     ELEND = 484,
     DUMMY = 485
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
#define EMPTYTYPEATT 302
#define EMPTYNAMEATT 303
#define EMPTYCATEGORYATT 304
#define EMPTYDESCRIPTIONATT 305
#define EMPTYUNITATT 306
#define EMPTYVALUEATT 307
#define EMPTYLBVALUEATT 308
#define EMPTYUBVALUEATT 309
#define LBVALUEATT 310
#define UBVALUEATT 311
#define EMPTYLBDUALVALUEATT 312
#define EMPTYUBDUALVALUEATT 313
#define LBDUALVALUEATT 314
#define UBDUALVALUEATT 315
#define SOLVERATT 316
#define EMPTYSOLVERATT 317
#define WEIGHTATT 318
#define EMPTYWEIGHTATT 319
#define TRANSPORTTYPEATT 320
#define LOCATIONTYPEATT 321
#define HEADERSTART 322
#define HEADEREND 323
#define GENERALSTART 324
#define GENERALEND 325
#define SYSTEMSTART 326
#define SYSTEMEND 327
#define SERVICESTART 328
#define SERVICEEND 329
#define JOBSTART 330
#define JOBEND 331
#define OPTIMIZATIONSTART 332
#define OPTIMIZATIONEND 333
#define FILENAMESTART 334
#define FILENAMEEND 335
#define FILENAMEEMPTY 336
#define FILENAMESTARTANDEND 337
#define FILESOURCESTART 338
#define FILESOURCEEND 339
#define FILESOURCEEMPTY 340
#define FILESOURCESTARTANDEND 341
#define FILEDESCRIPTIONSTART 342
#define FILEDESCRIPTIONEND 343
#define FILEDESCRIPTIONEMPTY 344
#define FILEDESCRIPTIONSTARTANDEND 345
#define FILECREATORSTART 346
#define FILECREATOREND 347
#define FILECREATOREMPTY 348
#define FILECREATORSTARTANDEND 349
#define FILELICENCESTART 350
#define FILELICENCEEND 351
#define FILELICENCEEMPTY 352
#define FILELICENCESTARTANDEND 353
#define SERVICEURISTART 354
#define SERVICEURIEND 355
#define SERVICENAMESTART 356
#define SERVICENAMEEND 357
#define INSTANCENAMESTART 358
#define INSTANCENAMEEND 359
#define INSTANCELOCATIONSTART 360
#define INSTANCELOCATIONEND 361
#define JOBIDSTART 362
#define JOBIDEND 363
#define SOLVERTOINVOKESTART 364
#define SOLVERTOINVOKEEND 365
#define LICENSESTART 366
#define LICENSEEND 367
#define USERNAMESTART 368
#define USERNAMEEND 369
#define PASSWORDSTART 370
#define PASSWORDEND 371
#define CONTACTSTART 372
#define CONTACTEND 373
#define OTHEROPTIONSSTART 374
#define OTHEROPTIONSEND 375
#define OTHERSTART 376
#define OTHEREND 377
#define MINDISKSPACESTART 378
#define MINDISKSPACEEND 379
#define MINMEMORYSTART 380
#define MINMEMORYEND 381
#define MINCPUSPEEDSTART 382
#define MINCPUSPEEDEND 383
#define MINCPUNUMBERSTART 384
#define MINCPUNUMBEREND 385
#define SERVICETYPESTART 386
#define SERVICETYPEEND 387
#define MAXTIMESTART 388
#define MAXTIMEEND 389
#define REQUESTEDSTARTTIMESTART 390
#define REQUESTEDSTARTTIMEEND 391
#define DEPENDENCIESSTART 392
#define DEPENDENCIESEND 393
#define REQUIREDDIRECTORIESSTART 394
#define REQUIREDDIRECTORIESEND 395
#define REQUIREDFILESSTART 396
#define REQUIREDFILESEND 397
#define PATHSTART 398
#define PATHEND 399
#define PATHPAIRSTART 400
#define PATHPAIREND 401
#define DIRECTORIESTOMAKESTART 402
#define DIRECTORIESTOMAKEEND 403
#define FILESTOMAKESTART 404
#define FILESTOMAKEEND 405
#define DIRECTORIESTODELETESTART 406
#define DIRECTORIESTODELETEEND 407
#define FILESTODELETESTART 408
#define FILESTODELETEEND 409
#define INPUTDIRECTORIESTOMOVESTART 410
#define INPUTDIRECTORIESTOMOVEEND 411
#define INPUTFILESTOMOVESTART 412
#define INPUTFILESTOMOVEEND 413
#define OUTPUTDIRECTORIESTOMOVESTART 414
#define OUTPUTDIRECTORIESTOMOVEEND 415
#define OUTPUTFILESTOMOVESTART 416
#define OUTPUTFILESTOMOVEEND 417
#define PROCESSESTOKILLSTART 418
#define PROCESSESTOKILLEND 419
#define PROCESSSTART 420
#define PROCESSEND 421
#define VARIABLESSTART 422
#define VARIABLESEND 423
#define INITIALVARIABLEVALUESSTART 424
#define INITIALVARIABLEVALUESEND 425
#define VARSTART 426
#define VAREND 427
#define INITIALVARIABLEVALUESSTRINGSTART 428
#define INITIALVARIABLEVALUESSTRINGEND 429
#define INITIALBASISSTATUSSTART 430
#define INITIALBASISSTATUSEND 431
#define BASICSTART 432
#define BASICEND 433
#define ATUPPERSTART 434
#define ATUPPEREND 435
#define ATLOWERSTART 436
#define ATLOWEREND 437
#define ATEQUALITYSTART 438
#define ATEQUALITYEND 439
#define SUPERBASICSTART 440
#define SUPERBASICEND 441
#define ISFREESTART 442
#define ISFREEEND 443
#define UNKNOWNSTART 444
#define UNKNOWNEND 445
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 446
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 447
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 448
#define SOSVARIABLEBRANCHINGWEIGHTSEND 449
#define SOSSTART 450
#define SOSEND 451
#define OBJECTIVESSTART 452
#define OBJECTIVESEND 453
#define INITIALOBJECTIVEVALUESSTART 454
#define INITIALOBJECTIVEVALUESEND 455
#define OBJSTART 456
#define OBJEND 457
#define INITIALOBJECTIVEBOUNDSSTART 458
#define INITIALOBJECTIVEBOUNDSEND 459
#define CONSTRAINTSSTART 460
#define CONSTRAINTSEND 461
#define INITIALCONSTRAINTVALUESSTART 462
#define INITIALCONSTRAINTVALUESEND 463
#define CONSTART 464
#define CONEND 465
#define INITIALDUALVALUESSTART 466
#define INITIALDUALVALUESEND 467
#define SOLVEROPTIONSSTART 468
#define SOLVEROPTIONSEND 469
#define SOLVEROPTIONSTART 470
#define SOLVEROPTIONEND 471
#define ENUMERATIONSTART 472
#define ENUMERATIONEND 473
#define ITEMEMPTY 474
#define ITEMSTART 475
#define ITEMEND 476
#define ITEMSTARTANDEND 477
#define BASE64START 478
#define BASE64END 479
#define INCRATT 480
#define MULTATT 481
#define SIZEOFATT 482
#define ELSTART 483
#define ELEND 484
#define DUMMY 485




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
#define YYLAST   1249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  814
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1208
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1661

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   485

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   232,
     234,     2,     2,   233,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   231,     2,     2,     2,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230
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
    1658,  1660,  1662,  1665,  1667,  1671,  1673,  1675,  1677,  1680,
    1684,  1686,  1688,  1689,  1692,  1694,  1696,  1698,  1700,  1702,
    1704,  1707,  1709,  1710,  1714,  1716,  1718,  1719,  1721,  1723,
    1725,  1727,  1731,  1736,  1737,  1741,  1743,  1745,  1747,  1749,
    1752,  1754,  1758,  1760,  1762,  1765,  1769,  1771,  1773,  1774,
    1777,  1779,  1781,  1783,  1786,  1788,  1789,  1793,  1795,  1797,
    1799,  1801,  1804,  1806,  1810,  1812,  1814,  1817,  1821,  1823,
    1825,  1826,  1829,  1831,  1833,  1835,  1837,  1840,  1842,  1843,
    1846,  1848,  1850,  1852,  1854,  1858,  1866,  1867,  1871,  1873,
    1875,  1877,  1879,  1881,  1885,  1887,  1888,  1892,  1894,  1896,
    1898,  1900,  1902,  1906,  1908,  1909,  1913,  1915,  1917,  1919,
    1921,  1923,  1927,  1929,  1930,  1934,  1936,  1938,  1940,  1942,
    1944,  1948,  1950,  1951,  1955,  1957,  1959,  1961,  1963,  1965,
    1969,  1971,  1972,  1976,  1978,  1980,  1982,  1984,  1986,  1990,
    1992,  1993,  1997,  1999,  2001,  2003,  2005,  2007,  2011,  2013,
    2014,  2017,  2021,  2023,  2025,  2026,  2029,  2031,  2033,  2035,
    2037,  2039,  2041,  2043,  2045,  2047,  2049,  2052,  2054,  2058,
    2060,  2062,  2064,  2067,  2071,  2073,  2075,  2076,  2079,  2081,
    2083,  2085,  2087,  2089,  2091,  2094,  2096,  2097,  2101,  2103,
    2105,  2106,  2108,  2110,  2112,  2114,  2118,  2123,  2124,  2128,
    2130,  2132,  2134,  2136,  2139,  2141,  2145,  2147,  2149,  2152,
    2156,  2158,  2160,  2161,  2164,  2166,  2168,  2170,  2173,  2175,
    2176,  2180,  2182,  2184,  2186,  2188,  2191,  2193,  2197,  2199,
    2201,  2204,  2208,  2210,  2212,  2213,  2216,  2218,  2220,  2222,
    2224,  2227,  2229,  2230,  2233,  2235,  2237,  2239,  2241,  2245,
    2253,  2254,  2258,  2260,  2262,  2264,  2266,  2268,  2272,  2274,
    2275,  2279,  2281,  2283,  2285,  2287,  2289,  2293,  2295,  2296,
    2300,  2302,  2304,  2306,  2308,  2310,  2314,  2316,  2317,  2321,
    2323,  2325,  2327,  2329,  2331,  2335,  2337,  2338,  2342,  2344,
    2346,  2348,  2350,  2352,  2356,  2358,  2359,  2363,  2365,  2367,
    2369,  2371,  2373,  2377,  2379,  2380,  2384,  2386,  2388,  2390,
    2392,  2394,  2398,  2400,  2401,  2404,  2408,  2410,  2412,  2413,
    2416,  2418,  2420,  2422,  2424,  2426,  2428,  2430,  2432,  2434,
    2436,  2439,  2441,  2445,  2447,  2449,  2451,  2454,  2458,  2460,
    2462,  2463,  2466,  2468,  2470,  2472,  2474,  2476,  2478,  2481,
    2483,  2484,  2488,  2490,  2492,  2494,  2496,  2498,  2502,  2503,
    2506,  2510,  2512,  2514,  2516,  2519,  2521,  2523,  2525,  2527,
    2529,  2531,  2533,  2535,  2537,  2540,  2542,  2546,  2548,  2550,
    2553,  2555,  2557,  2559,  2561,  2563,  2567,  2569,  2571,  2574,
    2579,  2583,  2585,  2587,  2588,  2591,  2593,  2595,  2597,  2601,
    2605,  2609,  2612,  2614,  2616,  2618,  2620,  2622,  2626,  2628,
    2630,  2632,  2634,  2638,  2640,  2645,  2647,  2649,  2654,  2656,
    2658,  2660,  2662,  2666,  2668,  2670,  2672,  2674,  2679,  2681,
    2683,  2685,  2687,  2691,  2693,  2695,  2697,  2699,  2703,  2705,
    2707,  2712,  2714,  2716,  2718,  2720,  2724,  2726,  2728,  2730,
    2732,  2736,  2738,  2740,  2742,  2744,  2749,  2751,  2753,  2755,
    2757,  2761,  2763,  2765,  2767,  2769,  2773,  2778,  2783,  2788,
    2793,  2798,  2803,  2808,  2813,  2818,  2823,  2828,  2833,  2838,
    2843,  2848,  2853,  2858,  2863,  2865,  2868,  2872,  2874,  2876,
    2877,  2880,  2882,  2884,  2886,  2888,  2890,  2892,  2896,  2898,
    2900,  2902,  2903,  2906,  2910,  2912,  2914,  2915,  2918,  2920,
    2922,  2926,  2930,  2935,  2937,  2939,  2942,  2944,  2948,  2953,
    2958,  2960,  2962,  2965,  2966,  2969,  2971,  2973,  2975
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     236,     0,    -1,   237,   245,   243,    -1,   238,   239,   240,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   241,    -1,
     242,    -1,    11,    -1,    10,   245,   243,    -1,   244,    -1,
      15,    -1,    -1,   246,   274,   360,   408,   436,   552,    -1,
      -1,   247,   248,    -1,    67,    -1,   249,    -1,   250,    -1,
      10,    68,    -1,    11,    -1,    10,   251,    68,    -1,   252,
      -1,   253,    -1,   252,   253,    -1,   254,    -1,   258,    -1,
     262,    -1,   266,    -1,   270,    -1,   255,    -1,   256,    -1,
     257,    -1,    82,    -1,    81,    -1,    79,     5,    80,    -1,
     259,    -1,   260,    -1,   261,    -1,    86,    -1,    85,    -1,
      83,     5,    84,    -1,   263,    -1,   264,    -1,   265,    -1,
      90,    -1,    89,    -1,    87,     5,    88,    -1,   267,    -1,
     268,    -1,   269,    -1,    94,    -1,    93,    -1,    91,     5,
      92,    -1,   271,    -1,   272,    -1,   273,    -1,    98,    -1,
      97,    -1,    95,     5,    96,    -1,    -1,   275,   276,    -1,
      69,    -1,   277,    -1,   278,    -1,    10,    70,    -1,    11,
      -1,    10,   279,    70,    -1,   280,    -1,   281,    -1,   280,
     281,    -1,   282,    -1,   288,    -1,   294,    -1,   300,    -1,
     308,    -1,   314,    -1,   320,    -1,   326,    -1,   332,    -1,
     338,    -1,   346,    -1,   283,   284,    -1,    99,    -1,   285,
      -1,   286,    -1,    10,   100,    -1,    11,    -1,    10,   287,
     100,    -1,     4,    -1,   289,   290,    -1,   101,    -1,   291,
      -1,   292,    -1,    10,   102,    -1,    11,    -1,    10,   293,
     102,    -1,     4,    -1,   295,   296,    -1,   103,    -1,   297,
      -1,   298,    -1,    10,   104,    -1,    11,    -1,    10,   299,
     104,    -1,     4,    -1,   301,   302,   304,    -1,   105,    -1,
      -1,   303,    -1,    66,     3,     8,    -1,   305,    -1,   306,
      -1,    10,   106,    -1,    11,    -1,    10,   307,   106,    -1,
       4,    -1,   309,   310,    -1,   107,    -1,   311,    -1,   312,
      -1,    10,   108,    -1,    11,    -1,    10,   313,   108,    -1,
       4,    -1,   315,   316,    -1,   109,    -1,   317,    -1,   318,
      -1,    10,   110,    -1,    11,    -1,    10,   319,   110,    -1,
       4,    -1,   321,   322,    -1,   111,    -1,   323,    -1,   324,
      -1,    10,   112,    -1,    11,    -1,    10,   325,   112,    -1,
       4,    -1,   327,   328,    -1,   113,    -1,   329,    -1,   330,
      -1,    10,   114,    -1,    11,    -1,    10,   331,   114,    -1,
       4,    -1,   333,   334,    -1,   115,    -1,   335,    -1,   336,
      -1,    10,   116,    -1,    11,    -1,    10,   337,   116,    -1,
       4,    -1,   339,   340,   342,    -1,   117,    -1,    -1,   341,
      -1,    65,     3,     8,    -1,   343,    -1,   344,    -1,    10,
     118,    -1,    11,    -1,    10,   345,   118,    -1,     4,    -1,
     347,   348,   349,    -1,   119,    -1,  1012,    -1,   350,    -1,
     351,    -1,    10,   120,    -1,    11,    -1,    10,   352,   120,
      -1,   353,    -1,   354,    -1,   353,   354,    -1,   355,   356,
     359,    -1,   121,    -1,   357,    -1,    -1,   357,   358,    -1,
     971,    -1,   998,    -1,   954,    -1,    10,   122,    -1,    11,
      -1,    -1,   361,   362,    -1,    71,    -1,   363,    -1,   364,
      -1,    10,    72,    -1,    11,    -1,    10,   365,    72,    -1,
     366,    -1,   367,    -1,   366,   367,    -1,   368,    -1,   375,
      -1,   382,    -1,   389,    -1,   394,    -1,   369,   370,   373,
      -1,   123,    -1,   371,    -1,    -1,   371,   372,    -1,   994,
      -1,   954,    -1,    10,   374,   124,    -1,  1045,    -1,   376,
     377,   380,    -1,   125,    -1,   378,    -1,    -1,   378,   379,
      -1,   994,    -1,   954,    -1,    10,   381,   126,    -1,  1045,
      -1,   383,   384,   387,    -1,   127,    -1,   385,    -1,    -1,
     385,   386,    -1,   994,    -1,   954,    -1,    10,   388,   128,
      -1,  1045,    -1,   390,   391,   392,    -1,   129,    -1,    -1,
     954,    -1,    10,   393,   130,    -1,     6,    -1,   395,   396,
     397,    -1,   119,    -1,  1012,    -1,   398,    -1,   399,    -1,
      10,   120,    -1,    11,    -1,    10,   400,   120,    -1,   401,
      -1,   402,    -1,   401,   402,    -1,   403,   404,   407,    -1,
     121,    -1,   405,    -1,    -1,   405,   406,    -1,   971,    -1,
     998,    -1,   954,    -1,    10,   122,    -1,    11,    -1,    -1,
     409,   410,    -1,    73,    -1,   411,    -1,   412,    -1,    10,
      74,    -1,    11,    -1,    10,   413,    74,    -1,   414,    -1,
     415,    -1,   414,   415,    -1,   416,    -1,   422,    -1,   417,
     418,    -1,   131,    -1,   419,    -1,   420,    -1,    10,   132,
      -1,    11,    -1,    10,   421,   132,    -1,     4,    -1,   423,
     424,   425,    -1,   119,    -1,  1012,    -1,   426,    -1,   427,
      -1,    10,   120,    -1,    11,    -1,    10,   428,   120,    -1,
     429,    -1,   430,    -1,   429,   430,    -1,   431,   432,   435,
      -1,   121,    -1,   433,    -1,    -1,   433,   434,    -1,   971,
      -1,   998,    -1,   954,    -1,    10,   122,    -1,    11,    -1,
      -1,   437,   438,    -1,    75,    -1,   439,    -1,   440,    -1,
      10,    76,    -1,    11,    -1,    10,   441,    76,    -1,   442,
      -1,   443,    -1,   442,   443,    -1,   444,    -1,   452,    -1,
     458,    -1,   466,    -1,   471,    -1,   476,    -1,   481,    -1,
     486,    -1,   494,    -1,   510,    -1,   502,    -1,   518,    -1,
     524,    -1,   530,    -1,   538,    -1,   445,   446,   447,    -1,
     133,    -1,    -1,   994,    -1,   448,    -1,   449,    -1,    10,
     134,    -1,    11,    -1,    10,   450,   134,    -1,   451,    -1,
    1045,    -1,   453,   454,    -1,   135,    -1,   455,    -1,   456,
      -1,    10,   136,    -1,    11,    -1,    10,   457,   136,    -1,
       4,    -1,   459,   460,   461,    -1,   137,    -1,  1007,    -1,
     462,    -1,   463,    -1,    10,   138,    -1,    11,    -1,    10,
     464,   138,    -1,   465,    -1,   464,   465,    -1,   107,    10,
       4,   108,    -1,   467,  1015,   468,    -1,   139,    -1,   469,
      -1,   470,    -1,    10,   140,    -1,    11,    -1,    10,   939,
     140,    -1,   472,  1015,   473,    -1,   141,    -1,   474,    -1,
     475,    -1,    10,   142,    -1,    11,    -1,    10,   939,   142,
      -1,   477,  1015,   478,    -1,   147,    -1,   479,    -1,   480,
      -1,    10,   148,    -1,    11,    -1,    10,   939,   148,    -1,
     482,  1015,   483,    -1,   149,    -1,   484,    -1,   485,    -1,
      10,   150,    -1,    11,    -1,    10,   939,   150,    -1,   487,
     488,   489,    -1,   155,    -1,  1014,    -1,   490,    -1,   491,
      -1,    10,   156,    -1,    11,    -1,    10,   492,   156,    -1,
     493,    -1,   492,   493,    -1,   941,    -1,   495,   496,   497,
      -1,   157,    -1,  1014,    -1,   498,    -1,   499,    -1,    10,
     158,    -1,    11,    -1,    10,   500,   158,    -1,   501,    -1,
     500,   501,    -1,   941,    -1,   503,   504,   505,    -1,   161,
      -1,  1014,    -1,   506,    -1,   507,    -1,    10,   162,    -1,
      11,    -1,    10,   508,   162,    -1,   509,    -1,   508,   509,
      -1,   941,    -1,   511,   512,   513,    -1,   159,    -1,  1014,
      -1,   514,    -1,   515,    -1,    10,   160,    -1,    11,    -1,
      10,   516,   160,    -1,   517,    -1,   516,   517,    -1,   941,
      -1,   519,   520,   521,    -1,   153,    -1,  1015,    -1,   522,
      -1,   523,    -1,    10,   154,    -1,    11,    -1,    10,   939,
     154,    -1,   525,   526,   527,    -1,   151,    -1,  1015,    -1,
     528,    -1,   529,    -1,    10,   152,    -1,    11,    -1,    10,
     939,   152,    -1,   531,   532,   533,    -1,   163,    -1,  1016,
      -1,   534,    -1,   535,    -1,    10,   164,    -1,    11,    -1,
      10,   536,   164,    -1,   537,    -1,   536,   537,    -1,   165,
      10,     4,   166,    -1,   539,   540,   541,    -1,   119,    -1,
    1012,    -1,   542,    -1,   543,    -1,    10,   120,    -1,    11,
      -1,    10,   544,   120,    -1,   545,    -1,   546,    -1,   545,
     546,    -1,   547,   548,   551,    -1,   121,    -1,   549,    -1,
      -1,   549,   550,    -1,   971,    -1,   998,    -1,   954,    -1,
      10,   122,    -1,    11,    -1,    -1,   553,   554,   557,    -1,
      77,    -1,   555,    -1,    -1,   555,   556,    -1,  1019,    -1,
    1003,    -1,  1009,    -1,   558,    -1,   559,    -1,    11,    -1,
      10,   560,    78,    -1,   561,   699,   808,   917,    -1,    -1,
     562,   563,   565,    -1,   167,    -1,   564,    -1,    -1,  1013,
      -1,   566,    -1,   567,    -1,    11,    -1,    10,   568,   168,
      -1,   569,   583,   597,   652,   666,   681,    -1,    -1,   570,
     571,   572,    -1,   169,    -1,  1018,    -1,   573,    -1,   574,
      -1,    10,   170,    -1,    11,    -1,    10,   575,   170,    -1,
     576,    -1,   577,    -1,   576,   577,    -1,   578,   579,   582,
      -1,   171,    -1,   580,    -1,    -1,   580,   581,    -1,   960,
      -1,   971,    -1,   998,    -1,    10,   172,    -1,    11,    -1,
      -1,   584,   585,   586,    -1,   173,    -1,  1018,    -1,   587,
      -1,   588,    -1,    10,   174,    -1,    11,    -1,    10,   589,
     174,    -1,   590,    -1,   591,    -1,   590,   591,    -1,   592,
     593,   596,    -1,   171,    -1,   594,    -1,    -1,   594,   595,
      -1,   960,    -1,   971,    -1,   998,    -1,    10,   172,    -1,
      11,    -1,    -1,   598,   599,    -1,   175,    -1,   600,    -1,
     601,    -1,    11,    -1,    10,   602,   176,    -1,   603,   610,
     617,   624,   631,   638,   645,    -1,    -1,   604,   605,   606,
      -1,   177,    -1,  1004,    -1,   607,    -1,   608,    -1,    11,
      -1,    10,   609,   178,    -1,  1030,    -1,    -1,   611,   612,
     613,    -1,   181,    -1,  1004,    -1,   614,    -1,   615,    -1,
      11,    -1,    10,   616,   182,    -1,  1030,    -1,    -1,   618,
     619,   620,    -1,   179,    -1,  1004,    -1,   621,    -1,   622,
      -1,    11,    -1,    10,   623,   180,    -1,  1030,    -1,    -1,
     625,   626,   627,    -1,   183,    -1,  1004,    -1,   628,    -1,
     629,    -1,    11,    -1,    10,   630,   184,    -1,  1030,    -1,
      -1,   632,   633,   634,    -1,   187,    -1,  1004,    -1,   635,
      -1,   636,    -1,    11,    -1,    10,   637,   188,    -1,  1030,
      -1,    -1,   639,   640,   641,    -1,   185,    -1,  1004,    -1,
     642,    -1,   643,    -1,    11,    -1,    10,   644,   186,    -1,
    1030,    -1,    -1,   646,   647,   648,    -1,   189,    -1,  1004,
      -1,   649,    -1,   650,    -1,    11,    -1,    10,   651,   190,
      -1,  1030,    -1,    -1,   653,   654,   655,    -1,   191,    -1,
    1018,    -1,   656,    -1,   657,    -1,    10,   192,    -1,    11,
      -1,    10,   658,   192,    -1,   659,    -1,   660,    -1,   659,
     660,    -1,   661,   662,   665,    -1,   171,    -1,   663,    -1,
      -1,   663,   664,    -1,   960,    -1,   971,    -1,   998,    -1,
      10,   172,    -1,    11,    -1,    -1,   667,   668,   669,    -1,
     193,    -1,    29,     8,     6,     8,    -1,   670,    -1,   671,
      -1,    10,   194,    -1,    11,    -1,    10,   672,   194,    -1,
     673,    -1,   672,   673,    -1,   674,   675,   678,    -1,   195,
      -1,   676,    -1,    -1,   676,   677,    -1,   979,    -1,  1018,
      -1,   958,    -1,   679,    -1,   680,    -1,    10,   196,    -1,
      11,    -1,    10,   659,   196,    -1,    -1,   681,   682,    -1,
     683,   684,   687,    -1,   121,    -1,   685,    -1,    -1,   685,
     686,    -1,  1018,    -1,  1005,    -1,   971,    -1,   998,    -1,
     975,    -1,   950,    -1,   982,    -1,   954,    -1,   688,    -1,
     689,    -1,    10,   122,    -1,    11,    -1,    10,   690,   122,
      -1,   691,    -1,  1020,    -1,   692,    -1,   691,   692,    -1,
     693,   694,   697,    -1,   171,    -1,   695,    -1,    -1,   695,
     696,    -1,   960,    -1,   971,    -1,   998,    -1,   963,    -1,
     986,    -1,   698,    -1,    10,   172,    -1,    11,    -1,    -1,
     700,   701,   703,    -1,   197,    -1,   702,    -1,    -1,  1011,
      -1,   704,    -1,   705,    -1,    11,    -1,    10,   706,   198,
      -1,   707,   721,   735,   790,    -1,    -1,   708,   709,   710,
      -1,   199,    -1,  1008,    -1,   711,    -1,   712,    -1,    10,
     200,    -1,    11,    -1,    10,   713,   200,    -1,   714,    -1,
     715,    -1,   714,   715,    -1,   716,   717,   720,    -1,   201,
      -1,   718,    -1,    -1,   718,   719,    -1,   960,    -1,   971,
      -1,   998,    -1,    10,   202,    -1,    11,    -1,    -1,   722,
     723,   724,    -1,   203,    -1,  1008,    -1,   725,    -1,   726,
      -1,    10,   204,    -1,    11,    -1,    10,   727,   204,    -1,
     728,    -1,   729,    -1,   728,   729,    -1,   730,   731,   734,
      -1,   201,    -1,   732,    -1,    -1,   732,   733,    -1,   960,
      -1,   971,    -1,   963,    -1,   986,    -1,    10,   202,    -1,
      11,    -1,    -1,   736,   737,    -1,   175,    -1,   738,    -1,
     739,    -1,    11,    -1,    10,   740,   176,    -1,   741,   748,
     755,   762,   769,   776,   783,    -1,    -1,   742,   743,   744,
      -1,   177,    -1,  1004,    -1,   745,    -1,   746,    -1,    11,
      -1,    10,   747,   178,    -1,  1030,    -1,    -1,   749,   750,
     751,    -1,   181,    -1,  1004,    -1,   752,    -1,   753,    -1,
      11,    -1,    10,   754,   182,    -1,  1030,    -1,    -1,   756,
     757,   758,    -1,   179,    -1,  1004,    -1,   759,    -1,   760,
      -1,    11,    -1,    10,   761,   180,    -1,  1030,    -1,    -1,
     763,   764,   765,    -1,   183,    -1,  1004,    -1,   766,    -1,
     767,    -1,    11,    -1,    10,   768,   184,    -1,  1030,    -1,
      -1,   770,   771,   772,    -1,   187,    -1,  1004,    -1,   773,
      -1,   774,    -1,    11,    -1,    10,   775,   188,    -1,  1030,
      -1,    -1,   777,   778,   779,    -1,   185,    -1,  1004,    -1,
     780,    -1,   781,    -1,    11,    -1,    10,   782,   186,    -1,
    1030,    -1,    -1,   784,   785,   786,    -1,   189,    -1,  1004,
      -1,   787,    -1,   788,    -1,    11,    -1,    10,   789,   190,
      -1,  1030,    -1,    -1,   790,   791,    -1,   792,   793,   796,
      -1,   121,    -1,   794,    -1,    -1,   794,   795,    -1,  1008,
      -1,  1005,    -1,   971,    -1,   998,    -1,   975,    -1,   950,
      -1,   982,    -1,   954,    -1,   797,    -1,   798,    -1,    10,
     122,    -1,    11,    -1,    10,   799,   122,    -1,   800,    -1,
    1020,    -1,   801,    -1,   800,   801,    -1,   802,   803,   806,
      -1,   201,    -1,   804,    -1,    -1,   804,   805,    -1,   960,
      -1,   971,    -1,   998,    -1,   963,    -1,   986,    -1,   807,
      -1,    10,   202,    -1,    11,    -1,    -1,   809,   810,   812,
      -1,   205,    -1,   811,    -1,    -1,  1010,    -1,   813,    -1,
     814,    -1,    11,    -1,    10,   815,   206,    -1,   816,   830,
     844,   899,    -1,    -1,   817,   818,   819,    -1,   207,    -1,
    1002,    -1,   820,    -1,   821,    -1,    10,   208,    -1,    11,
      -1,    10,   822,   208,    -1,   823,    -1,   824,    -1,   823,
     824,    -1,   825,   826,   829,    -1,   209,    -1,   827,    -1,
      -1,   827,   828,    -1,   960,    -1,   971,    -1,   998,    -1,
      10,   210,    -1,    11,    -1,    -1,   831,   832,   833,    -1,
     211,    -1,  1002,    -1,   834,    -1,   835,    -1,    10,   212,
      -1,    11,    -1,    10,   836,   212,    -1,   837,    -1,   838,
      -1,   837,   838,    -1,   839,   840,   843,    -1,   209,    -1,
     841,    -1,    -1,   841,   842,    -1,   960,    -1,   971,    -1,
     967,    -1,   990,    -1,    10,   210,    -1,    11,    -1,    -1,
     845,   846,    -1,   175,    -1,   847,    -1,   848,    -1,    11,
      -1,    10,   849,   176,    -1,   850,   857,   864,   871,   878,
     885,   892,    -1,    -1,   851,   852,   853,    -1,   177,    -1,
    1004,    -1,   854,    -1,   855,    -1,    11,    -1,    10,   856,
     178,    -1,  1030,    -1,    -1,   858,   859,   860,    -1,   181,
      -1,  1004,    -1,   861,    -1,   862,    -1,    11,    -1,    10,
     863,   182,    -1,  1030,    -1,    -1,   865,   866,   867,    -1,
     179,    -1,  1004,    -1,   868,    -1,   869,    -1,    11,    -1,
      10,   870,   180,    -1,  1030,    -1,    -1,   872,   873,   874,
      -1,   183,    -1,  1004,    -1,   875,    -1,   876,    -1,    11,
      -1,    10,   877,   184,    -1,  1030,    -1,    -1,   879,   880,
     881,    -1,   187,    -1,  1004,    -1,   882,    -1,   883,    -1,
      11,    -1,    10,   884,   188,    -1,  1030,    -1,    -1,   886,
     887,   888,    -1,   185,    -1,  1004,    -1,   889,    -1,   890,
      -1,    11,    -1,    10,   891,   186,    -1,  1030,    -1,    -1,
     893,   894,   895,    -1,   189,    -1,  1004,    -1,   896,    -1,
     897,    -1,    11,    -1,    10,   898,   190,    -1,  1030,    -1,
      -1,   899,   900,    -1,   901,   902,   905,    -1,   121,    -1,
     903,    -1,    -1,   903,   904,    -1,  1002,    -1,  1005,    -1,
     971,    -1,   998,    -1,   975,    -1,   950,    -1,   982,    -1,
     954,    -1,   906,    -1,   907,    -1,    10,   122,    -1,    11,
      -1,    10,   908,   122,    -1,   909,    -1,  1020,    -1,   910,
      -1,   909,   910,    -1,   911,   912,   915,    -1,   209,    -1,
     913,    -1,    -1,   913,   914,    -1,   960,    -1,   971,    -1,
     998,    -1,   963,    -1,   986,    -1,   916,    -1,    10,   210,
      -1,    11,    -1,    -1,   918,   919,   920,    -1,   213,    -1,
    1017,    -1,   921,    -1,   922,    -1,    11,    -1,    10,   923,
     214,    -1,    -1,   923,   924,    -1,   925,   926,   929,    -1,
     215,    -1,   927,    -1,   928,    -1,   927,   928,    -1,   971,
      -1,   998,    -1,   975,    -1,   950,    -1,   982,    -1,   954,
      -1,  1006,    -1,   930,    -1,   931,    -1,    10,   216,    -1,
      11,    -1,    10,   932,   216,    -1,   933,    -1,   934,    -1,
     933,   934,    -1,   935,    -1,   936,    -1,   937,    -1,   222,
      -1,   219,    -1,   220,   938,   221,    -1,     5,    -1,   940,
      -1,   939,   940,    -1,   143,    10,     4,   144,    -1,   942,
     943,   949,    -1,   145,    -1,   944,    -1,    -1,   944,   945,
      -1,   946,    -1,   947,    -1,   948,    -1,    21,     3,     8,
      -1,    22,     3,     8,    -1,    23,     3,     8,    -1,    10,
     146,    -1,    11,    -1,   951,    -1,   952,    -1,   953,    -1,
      49,    -1,    24,     3,  1046,    -1,   955,    -1,   956,    -1,
     957,    -1,    50,    -1,    46,     3,  1046,    -1,   959,    -1,
      26,     8,  1045,     8,    -1,   961,    -1,   962,    -1,    42,
    1046,     6,  1046,    -1,   964,    -1,   965,    -1,   966,    -1,
      53,    -1,    55,     3,  1046,    -1,   968,    -1,   969,    -1,
     970,    -1,    57,    -1,    59,  1046,  1045,  1046,    -1,   972,
      -1,   973,    -1,   974,    -1,    48,    -1,    41,     3,  1046,
      -1,   976,    -1,   977,    -1,   978,    -1,    62,    -1,    61,
       3,  1046,    -1,   980,    -1,   981,    -1,    43,  1046,     6,
    1046,    -1,   983,    -1,   984,    -1,   985,    -1,    47,    -1,
      25,     3,     8,    -1,   987,    -1,   988,    -1,   989,    -1,
      54,    -1,    56,     3,  1046,    -1,   991,    -1,   992,    -1,
     993,    -1,    58,    -1,    60,  1046,  1045,  1046,    -1,   995,
      -1,   996,    -1,   997,    -1,    51,    -1,    45,     3,     8,
      -1,   999,    -1,  1000,    -1,  1001,    -1,    52,    -1,    44,
       3,     8,    -1,    39,  1046,     6,  1046,    -1,    32,  1046,
       6,  1046,    -1,    40,  1046,     6,  1046,    -1,    17,  1046,
       6,  1046,    -1,    36,  1046,     6,  1046,    -1,    18,     8,
       6,     8,    -1,    38,  1046,     6,  1046,    -1,    31,  1046,
       6,  1046,    -1,    35,  1046,     6,  1046,    -1,    34,  1046,
       6,  1046,    -1,    16,  1046,     6,  1046,    -1,    33,  1046,
       6,  1046,    -1,    20,     8,     6,     8,    -1,    19,     8,
       6,     8,    -1,    27,     8,     6,     8,    -1,    28,  1046,
       6,  1046,    -1,    37,  1046,     6,  1046,    -1,    30,  1046,
       6,  1046,    -1,  1021,    -1,  1020,  1021,    -1,  1022,  1023,
    1026,    -1,   217,    -1,  1024,    -1,    -1,  1024,  1025,    -1,
    1004,    -1,   998,    -1,   954,    -1,  1027,    -1,  1028,    -1,
      11,    -1,    10,  1029,   218,    -1,  1030,    -1,  1031,    -1,
    1038,    -1,    -1,  1031,  1032,    -1,  1033,  1034,  1037,    -1,
     228,    -1,  1035,    -1,    -1,  1035,  1036,    -1,  1044,    -1,
    1043,    -1,    10,     6,   229,    -1,   223,  1039,  1040,    -1,
     227,  1046,     6,  1046,    -1,  1041,    -1,  1042,    -1,    10,
     224,    -1,    11,    -1,    10,     4,   224,    -1,   225,  1046,
       6,  1046,    -1,   226,  1046,     6,  1046,    -1,     6,    -1,
       7,    -1,  1047,     8,    -1,    -1,  1047,  1048,    -1,   231,
      -1,   232,    -1,   233,    -1,   234,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   169,   169,   170,   172,   179,   189,   189,   191,   191,
     193,   195,   197,   206,   207,   210,   218,   218,   225,   239,
     239,   241,   241,   243,   245,   247,   247,   250,   251,   252,
     253,   254,   256,   264,   264,   266,   266,   268,   274,   283,
     283,   285,   285,   287,   293,   301,   301,   303,   303,   305,
     311,   319,   319,   321,   321,   323,   329,   336,   336,   338,
     338,   340,   351,   351,   353,   369,   369,   371,   371,   373,
     375,   377,   377,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   394,   396,   405,   405,   407,   407,
     409,   411,   421,   423,   430,   430,   432,   432,   434,   436,
     446,   448,   454,   454,   456,   456,   458,   460,   470,   477,
     485,   486,   493,   499,   499,   501,   501,   503,   505,   513,
     515,   521,   521,   523,   523,   525,   527,   536,   538,   545,
     545,   547,   547,   549,   551,   561,   563,   570,   570,   572,
     572,   574,   576,   586,   588,   594,   594,   596,   596,   598,
     600,   610,   612,   618,   618,   620,   620,   622,   624,   634,
     641,   650,   651,   657,   664,   664,   666,   666,   668,   670,
     678,   684,   694,   702,   707,   713,   713,   715,   717,   721,
     721,   723,   731,   750,   756,   756,   759,   763,   764,   767,
     767,   776,   776,   778,   788,   788,   790,   790,   792,   794,
     796,   796,   799,   800,   801,   802,   803,   807,   809,   819,
     821,   821,   824,   825,   828,   830,   838,   840,   850,   852,
     852,   855,   856,   859,   861,   870,   872,   882,   884,   884,
     887,   888,   891,   893,   902,   904,   912,   913,   915,   917,
     928,   934,   944,   952,   956,   961,   961,   963,   965,   969,
     969,   971,   979,   998,  1003,  1003,  1006,  1011,  1012,  1015,
    1015,  1024,  1024,  1026,  1033,  1033,  1035,  1035,  1037,  1039,
    1041,  1041,  1044,  1045,  1049,  1051,  1057,  1057,  1059,  1059,
    1061,  1063,  1074,  1080,  1090,  1098,  1102,  1107,  1107,  1109,
    1111,  1115,  1115,  1117,  1125,  1144,  1149,  1149,  1152,  1157,
    1158,  1161,  1161,  1169,  1169,  1171,  1191,  1191,  1193,  1193,
    1195,  1197,  1199,  1199,  1202,  1203,  1204,  1205,  1206,  1207,
    1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1221,
    1227,  1237,  1238,  1240,  1240,  1242,  1242,  1244,  1246,  1248,
    1255,  1257,  1263,  1263,  1265,  1265,  1267,  1269,  1279,  1290,
    1300,  1302,  1302,  1304,  1304,  1306,  1315,  1315,  1317,  1338,
    1349,  1359,  1359,  1361,  1361,  1363,  1374,  1385,  1395,  1395,
    1397,  1397,  1399,  1410,  1421,  1431,  1431,  1433,  1433,  1435,
    1446,  1457,  1467,  1467,  1469,  1469,  1471,  1482,  1498,  1508,
    1510,  1510,  1512,  1512,  1514,  1523,  1523,  1525,  1529,  1545,
    1555,  1557,  1557,  1559,  1559,  1561,  1570,  1570,  1572,  1576,
    1592,  1602,  1604,  1604,  1606,  1606,  1608,  1617,  1617,  1619,
    1623,  1639,  1649,  1651,  1651,  1653,  1653,  1655,  1664,  1664,
    1666,  1670,  1681,  1691,  1693,  1693,  1695,  1695,  1697,  1708,
    1719,  1729,  1731,  1731,  1733,  1733,  1735,  1760,  1771,  1781,
    1783,  1783,  1785,  1785,  1787,  1796,  1796,  1798,  1819,  1825,
    1835,  1843,  1847,  1852,  1852,  1854,  1856,  1860,  1860,  1862,
    1870,  1889,  1895,  1895,  1898,  1903,  1904,  1907,  1907,  1915,
    1915,  1917,  1925,  1927,  1927,  1930,  1936,  1942,  1950,  1950,
    1952,  1954,  1956,  1963,  1963,  1965,  1971,  1978,  1978,  1983,
    1983,  1985,  1987,  1989,  1999,  1999,  2014,  2019,  2030,  2038,
    2047,  2047,  2049,  2051,  2053,  2053,  2056,  2061,  2075,  2081,
    2081,  2084,  2096,  2101,  2109,  2109,  2113,  2113,  2128,  2133,
    2144,  2152,  2161,  2161,  2163,  2165,  2167,  2167,  2170,  2175,
    2190,  2196,  2196,  2199,  2211,  2216,  2222,  2222,  2226,  2226,
    2228,  2233,  2233,  2235,  2237,  2239,  2242,  2242,  2253,  2259,
    2266,  2266,  2268,  2270,  2272,  2276,  2276,  2288,  2294,  2301,
    2301,  2303,  2305,  2307,  2311,  2311,  2322,  2328,  2335,  2335,
    2337,  2339,  2341,  2345,  2345,  2356,  2362,  2369,  2369,  2371,
    2373,  2375,  2379,  2379,  2390,  2396,  2403,  2403,  2405,  2407,
    2409,  2413,  2413,  2424,  2430,  2437,  2437,  2439,  2441,  2443,
    2447,  2447,  2458,  2464,  2471,  2471,  2473,  2475,  2477,  2481,
    2481,  2497,  2502,  2513,  2521,  2530,  2530,  2532,  2534,  2540,
    2540,  2542,  2547,  2563,  2569,  2569,  2572,  2584,  2589,  2597,
    2597,  2601,  2601,  2607,  2613,  2621,  2629,  2637,  2637,  2639,
    2641,  2641,  2643,  2662,  2678,  2686,  2686,  2689,  2690,  2699,
    2702,  2702,  2704,  2704,  2706,  2711,  2711,  2713,  2718,  2745,
    2763,  2763,  2766,  2770,  2774,  2775,  2776,  2777,  2778,  2779,
    2782,  2782,  2784,  2784,  2786,  2788,  2788,  2790,  2790,  2793,
    2808,  2828,  2830,  2830,  2833,  2843,  2844,  2845,  2846,  2849,
    2851,  2851,  2859,  2859,  2861,  2867,  2874,  2874,  2879,  2879,
    2881,  2883,  2885,  2894,  2894,  2910,  2916,  2928,  2936,  2945,
    2945,  2947,  2949,  2951,  2951,  2954,  2959,  2974,  2976,  2976,
    2979,  2990,  2994,  3001,  3001,  3004,  3004,  3022,  3027,  3041,
    3049,  3058,  3058,  3060,  3062,  3064,  3064,  3067,  3072,  3090,
    3092,  3092,  3095,  3106,  3110,  3116,  3123,  3123,  3127,  3127,
    3129,  3134,  3134,  3136,  3138,  3140,  3143,  3143,  3154,  3160,
    3167,  3167,  3169,  3171,  3173,  3176,  3176,  3187,  3193,  3200,
    3200,  3202,  3204,  3206,  3209,  3209,  3220,  3226,  3233,  3233,
    3235,  3237,  3239,  3242,  3242,  3253,  3259,  3266,  3266,  3268,
    3270,  3272,  3275,  3275,  3286,  3292,  3299,  3299,  3301,  3303,
    3305,  3308,  3308,  3319,  3326,  3333,  3333,  3335,  3337,  3339,
    3343,  3343,  3354,  3360,  3367,  3367,  3369,  3371,  3373,  3377,
    3377,  3379,  3385,  3412,  3431,  3431,  3434,  3438,  3442,  3443,
    3444,  3445,  3446,  3447,  3450,  3450,  3452,  3452,  3454,  3456,
    3456,  3458,  3458,  3461,  3476,  3498,  3500,  3500,  3503,  3513,
    3514,  3515,  3516,  3519,  3521,  3521,  3529,  3529,  3531,  3537,
    3544,  3544,  3549,  3549,  3551,  3553,  3555,  3564,  3564,  3580,
    3585,  3596,  3604,  3613,  3613,  3615,  3617,  3619,  3619,  3622,
    3627,  3642,  3648,  3648,  3651,  3662,  3666,  3673,  3673,  3677,
    3677,  3695,  3700,  3713,  3721,  3730,  3730,  3732,  3734,  3736,
    3736,  3739,  3744,  3762,  3768,  3768,  3771,  3782,  3786,  3790,
    3796,  3796,  3800,  3800,  3802,  3807,  3807,  3809,  3811,  3813,
    3816,  3816,  3827,  3833,  3840,  3840,  3842,  3844,  3846,  3849,
    3849,  3860,  3866,  3873,  3873,  3875,  3877,  3879,  3883,  3883,
    3894,  3900,  3907,  3907,  3909,  3911,  3913,  3917,  3917,  3928,
    3934,  3941,  3941,  3943,  3945,  3947,  3951,  3951,  3962,  3968,
    3975,  3975,  3977,  3979,  3981,  3985,  3985,  3996,  4002,  4009,
    4009,  4011,  4013,  4015,  4019,  4019,  4030,  4036,  4043,  4043,
    4045,  4047,  4049,  4053,  4053,  4055,  4061,  4088,  4106,  4106,
    4109,  4113,  4117,  4118,  4119,  4120,  4121,  4122,  4125,  4125,
    4127,  4127,  4129,  4131,  4131,  4133,  4133,  4136,  4151,  4171,
    4173,  4173,  4176,  4186,  4187,  4188,  4189,  4192,  4194,  4194,
    4202,  4202,  4208,  4210,  4218,  4226,  4235,  4237,  4239,  4239,
    4243,  4263,  4281,  4287,  4287,  4290,  4291,  4292,  4293,  4294,
    4295,  4296,  4303,  4311,  4320,  4320,  4322,  4324,  4326,  4326,
    4328,  4335,  4346,  4348,  4348,  4350,  4352,  4369,  4369,  4371,
    4393,  4410,  4422,  4427,  4427,  4430,  4431,  4432,  4434,  4443,
    4452,  4461,  4461,  4467,  4474,  4474,  4476,  4481,  4488,  4495,
    4495,  4497,  4500,  4507,  4514,  4521,  4528,  4530,  4536,  4543,
    4543,  4545,  4550,  4557,  4563,  4563,  4565,  4570,  4577,  4584,
    4584,  4586,  4591,  4598,  4604,  4604,  4606,  4609,  4616,  4622,
    4624,  4632,  4638,  4638,  4640,  4643,  4650,  4657,  4657,  4659,
    4664,  4671,  4677,  4677,  4679,  4682,  4689,  4695,  4695,  4697,
    4700,  4707,  4713,  4713,  4715,  4718,  4730,  4739,  4748,  4757,
    4766,  4775,  4785,  4794,  4803,  4809,  4815,  4821,  4827,  4841,
    4851,  4862,  4868,  4877,  4897,  4897,  4899,  4917,  4933,  4941,
    4941,  4944,  4951,  4952,  4956,  4956,  4958,  4961,  4963,  4980,
    4988,  4990,  4990,  4992,  4994,  5003,  5005,  5005,  5007,  5007,
    5009,  5025,  5027,  5032,  5032,  5034,  5034,  5036,  5062,  5070,
    5084,  5085,  5092,  5094,  5094,  5096,  5097,  5098,  5099
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
  "DESCRIPTIONATT", "EMPTYTYPEATT", "EMPTYNAMEATT", "EMPTYCATEGORYATT",
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
  "categoryAttContent", "descriptionAttribute", "descriptionAtt",
  "descriptionAttEmpty", "descriptionAttContent", "groupWeightAttribute",
  "groupWeightAtt", "idxAttribute", "idxAtt", "idxAttContent",
  "lbValueAttribute", "lbValueAtt", "lbValueAttEmpty", "lbValueAttContent",
  "lbDualValueAttribute", "lbDualValueAtt", "lbDualValueAttEmpty",
  "lbDualValueAttContent", "nameAttribute", "nameAtt", "nameAttEmpty",
  "nameAttContent", "solverAttribute", "solverAtt", "solverAttEmpty",
  "solverAttContent", "sosIdxAttribute", "sosIdxAtt", "sosIdxAttContent",
  "typeAttribute", "typeAtt", "typeAttEmpty", "typeAttContent",
  "ubValueAttribute", "ubValueAtt", "ubValueAttEmpty", "ubValueAttContent",
  "ubDualValueAttribute", "ubDualValueAtt", "ubDualValueAttEmpty",
  "ubDualValueAttContent", "unitAttribute", "unitAtt", "unitAttEmpty",
  "unitAttContent", "valueAttribute", "valueAtt", "valueAttEmpty",
  "valueAttContent", "numberOfConAttribute",
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
     485,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   235,   236,   236,   237,   238,   239,   239,   240,   240,
     241,   242,   243,   244,   244,   245,   246,   246,   247,   248,
     248,   249,   249,   250,   251,   252,   252,   253,   253,   253,
     253,   253,   254,   255,   255,   256,   256,   257,   258,   259,
     259,   260,   260,   261,   262,   263,   263,   264,   264,   265,
     266,   267,   267,   268,   268,   269,   270,   271,   271,   272,
     272,   273,   274,   274,   275,   276,   276,   277,   277,   278,
     279,   280,   280,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   282,   283,   284,   284,   285,   285,
     286,   287,   288,   289,   290,   290,   291,   291,   292,   293,
     294,   295,   296,   296,   297,   297,   298,   299,   300,   301,
     302,   302,   303,   304,   304,   305,   305,   306,   307,   308,
     309,   310,   310,   311,   311,   312,   313,   314,   315,   316,
     316,   317,   317,   318,   319,   320,   321,   322,   322,   323,
     323,   324,   325,   326,   327,   328,   328,   329,   329,   330,
     331,   332,   333,   334,   334,   335,   335,   336,   337,   338,
     339,   340,   340,   341,   342,   342,   343,   343,   344,   345,
     346,   347,   348,   349,   349,   350,   350,   351,   352,   353,
     353,   354,   355,   356,   357,   357,   358,   358,   358,   359,
     359,   360,   360,   361,   362,   362,   363,   363,   364,   365,
     366,   366,   367,   367,   367,   367,   367,   368,   369,   370,
     371,   371,   372,   372,   373,   374,   375,   376,   377,   378,
     378,   379,   379,   380,   381,   382,   383,   384,   385,   385,
     386,   386,   387,   388,   389,   390,   391,   391,   392,   393,
     394,   395,   396,   397,   397,   398,   398,   399,   400,   401,
     401,   402,   403,   404,   405,   405,   406,   406,   406,   407,
     407,   408,   408,   409,   410,   410,   411,   411,   412,   413,
     414,   414,   415,   415,   416,   417,   418,   418,   419,   419,
     420,   421,   422,   423,   424,   425,   425,   426,   426,   427,
     428,   429,   429,   430,   431,   432,   433,   433,   434,   434,
     434,   435,   435,   436,   436,   437,   438,   438,   439,   439,
     440,   441,   442,   442,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   444,
     445,   446,   446,   447,   447,   448,   448,   449,   450,   451,
     452,   453,   454,   454,   455,   455,   456,   457,   458,   459,
     460,   461,   461,   462,   462,   463,   464,   464,   465,   466,
     467,   468,   468,   469,   469,   470,   471,   472,   473,   473,
     474,   474,   475,   476,   477,   478,   478,   479,   479,   480,
     481,   482,   483,   483,   484,   484,   485,   486,   487,   488,
     489,   489,   490,   490,   491,   492,   492,   493,   494,   495,
     496,   497,   497,   498,   498,   499,   500,   500,   501,   502,
     503,   504,   505,   505,   506,   506,   507,   508,   508,   509,
     510,   511,   512,   513,   513,   514,   514,   515,   516,   516,
     517,   518,   519,   520,   521,   521,   522,   522,   523,   524,
     525,   526,   527,   527,   528,   528,   529,   530,   531,   532,
     533,   533,   534,   534,   535,   536,   536,   537,   538,   539,
     540,   541,   541,   542,   542,   543,   544,   545,   545,   546,
     547,   548,   549,   549,   550,   550,   550,   551,   551,   552,
     552,   553,   554,   555,   555,   556,   556,   556,   557,   557,
     558,   559,   560,   561,   561,   562,   563,   564,   564,   565,
     565,   566,   567,   568,   569,   569,   570,   571,   572,   572,
     573,   573,   574,   575,   576,   576,   577,   578,   579,   580,
     580,   581,   581,   581,   582,   582,   583,   583,   584,   585,
     586,   586,   587,   587,   588,   589,   590,   590,   591,   592,
     593,   594,   594,   595,   595,   595,   596,   596,   597,   597,
     598,   599,   599,   600,   601,   602,   603,   603,   604,   605,
     606,   606,   607,   608,   609,   610,   610,   611,   612,   613,
     613,   614,   615,   616,   617,   617,   618,   619,   620,   620,
     621,   622,   623,   624,   624,   625,   626,   627,   627,   628,
     629,   630,   631,   631,   632,   633,   634,   634,   635,   636,
     637,   638,   638,   639,   640,   641,   641,   642,   643,   644,
     645,   645,   646,   647,   648,   648,   649,   650,   651,   652,
     652,   653,   654,   655,   655,   656,   656,   657,   658,   659,
     659,   660,   661,   662,   663,   663,   664,   664,   664,   665,
     665,   666,   666,   667,   668,   669,   669,   670,   670,   671,
     672,   672,   673,   674,   675,   676,   676,   677,   677,   677,
     678,   678,   679,   679,   680,   681,   681,   682,   683,   684,
     685,   685,   686,   686,   686,   686,   686,   686,   686,   686,
     687,   687,   688,   688,   689,   690,   690,   691,   691,   692,
     693,   694,   695,   695,   696,   696,   696,   696,   696,   697,
     698,   698,   699,   699,   700,   701,   702,   702,   703,   703,
     704,   705,   706,   707,   707,   708,   709,   710,   710,   711,
     711,   712,   713,   714,   714,   715,   716,   717,   718,   718,
     719,   719,   719,   720,   720,   721,   721,   722,   723,   724,
     724,   725,   725,   726,   727,   728,   728,   729,   730,   731,
     732,   732,   733,   733,   733,   733,   734,   734,   735,   735,
     736,   737,   737,   738,   739,   740,   741,   741,   742,   743,
     744,   744,   745,   746,   747,   748,   748,   749,   750,   751,
     751,   752,   753,   754,   755,   755,   756,   757,   758,   758,
     759,   760,   761,   762,   762,   763,   764,   765,   765,   766,
     767,   768,   769,   769,   770,   771,   772,   772,   773,   774,
     775,   776,   776,   777,   778,   779,   779,   780,   781,   782,
     783,   783,   784,   785,   786,   786,   787,   788,   789,   790,
     790,   791,   792,   793,   794,   794,   795,   795,   795,   795,
     795,   795,   795,   795,   796,   796,   797,   797,   798,   799,
     799,   800,   800,   801,   802,   803,   804,   804,   805,   805,
     805,   805,   805,   806,   807,   807,   808,   808,   809,   810,
     811,   811,   812,   812,   813,   814,   815,   816,   816,   817,
     818,   819,   819,   820,   820,   821,   822,   823,   823,   824,
     825,   826,   827,   827,   828,   828,   828,   829,   829,   830,
     830,   831,   832,   833,   833,   834,   834,   835,   836,   837,
     837,   838,   839,   840,   841,   841,   842,   842,   842,   842,
     843,   843,   844,   844,   845,   846,   846,   847,   848,   849,
     850,   850,   851,   852,   853,   853,   854,   855,   856,   857,
     857,   858,   859,   860,   860,   861,   862,   863,   864,   864,
     865,   866,   867,   867,   868,   869,   870,   871,   871,   872,
     873,   874,   874,   875,   876,   877,   878,   878,   879,   880,
     881,   881,   882,   883,   884,   885,   885,   886,   887,   888,
     888,   889,   890,   891,   892,   892,   893,   894,   895,   895,
     896,   897,   898,   899,   899,   900,   901,   902,   903,   903,
     904,   904,   904,   904,   904,   904,   904,   904,   905,   905,
     906,   906,   907,   908,   908,   909,   909,   910,   911,   912,
     913,   913,   914,   914,   914,   914,   914,   915,   916,   916,
     917,   917,   918,   919,   920,   920,   921,   922,   923,   923,
     924,   925,   926,   927,   927,   928,   928,   928,   928,   928,
     928,   928,   929,   929,   930,   930,   931,   932,   933,   933,
     934,   935,   935,   936,   936,   937,   938,   939,   939,   940,
     941,   942,   943,   944,   944,   945,   945,   945,   946,   947,
     948,   949,   949,   950,   951,   951,   952,   953,   954,   955,
     955,   956,   957,   958,   959,   960,   961,   962,   963,   964,
     964,   965,   966,   967,   968,   968,   969,   970,   971,   972,
     972,   973,   974,   975,   976,   976,   977,   978,   979,   980,
     981,   982,   983,   983,   984,   985,   986,   987,   987,   988,
     989,   990,   991,   991,   992,   993,   994,   995,   995,   996,
     997,   998,   999,   999,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1020,  1021,  1022,  1023,  1024,
    1024,  1025,  1025,  1025,  1026,  1026,  1027,  1028,  1029,  1030,
    1030,  1031,  1031,  1032,  1033,  1034,  1035,  1035,  1036,  1036,
    1037,  1038,  1039,  1040,  1040,  1041,  1041,  1042,  1043,  1044,
    1045,  1045,  1046,  1047,  1047,  1048,  1048,  1048,  1048
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
       1,     1,     2,     1,     3,     1,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     4,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     2,     1,     0,     2,
       1,     1,     1,     1,     3,     7,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
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
       2,     1,     3,     1,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     0,     2,
       3,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     3,     1,     1,     2,     4,
       3,     1,     1,     0,     2,     1,     1,     1,     3,     3,
       3,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     4,     1,     1,     4,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       4,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       3,     3,     4,     1,     1,     2,     1,     3,     4,     4,
       1,     1,     2,     0,     2,     1,     1,     1,     1
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
     153,   154,     0,     0,   162,  1203,     0,   172,    37,    43,
      49,    55,    61,   481,    15,   483,     0,   309,   304,   306,
     307,   266,   283,   275,     0,   269,   270,   272,     0,   273,
       0,   198,   201,     0,   209,     0,   218,     0,   227,     0,
    1091,     0,   237,  1088,  1089,  1090,     0,   242,    91,    88,
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
     284,     0,   207,     0,  1139,   211,   213,   212,  1136,  1137,
    1138,     0,   216,   220,   222,   221,     0,   225,   229,   231,
     230,  1203,     0,   234,     0,   246,   240,   243,   244,    90,
      98,   106,   112,   118,   115,     0,   125,   133,   141,   149,
     157,   163,   169,   166,     0,  1203,  1202,  1205,  1206,  1207,
    1208,  1204,   175,   182,     0,   178,   179,   184,   493,   490,
     480,   488,   489,  1203,  1203,  1203,   484,   486,   487,   485,
     310,   313,     0,   332,     0,   345,   340,   342,   343,     0,
       0,   350,     0,     0,     0,     0,     0,     0,     0,   389,
       0,   400,     0,   411,     0,   422,     0,   433,     0,   441,
       0,     0,   449,     0,   460,   281,   278,     0,     0,   288,
     282,   285,   286,  1200,  1201,     0,   215,     0,     0,   224,
       0,   233,  1092,   239,     0,   245,   252,     0,   248,   249,
     254,   117,   168,  1156,   177,   180,     0,   183,   495,     0,
     702,   497,     0,     0,     0,     0,   336,   329,   333,   334,
     347,   344,     0,     0,     0,   354,   348,   351,   352,     0,
       0,   364,   359,   361,   362,     0,   371,   366,   368,   369,
       0,   378,   373,   375,   376,     0,   385,   380,   382,   383,
       0,     0,   393,   387,   390,   391,     0,   404,   398,   401,
     402,     0,   415,   409,   412,   413,     0,   426,   420,   423,
     424,     0,   437,   431,   434,   435,     0,   445,   439,   442,
     443,     0,     0,   453,   447,   450,   451,     0,   464,   458,
     461,   462,   280,   287,   294,     0,   290,   291,   296,   214,
    1140,   223,   232,   238,   247,   250,     0,   253,     0,   190,
     181,     0,     0,  1111,  1144,   185,   188,   186,  1108,  1109,
    1110,   187,  1141,  1142,  1143,   491,   704,   866,   706,  1203,
       0,   496,   498,  1203,  1203,  1203,   335,     0,   338,   339,
     346,     0,     0,   353,     0,   356,     0,   363,     0,     0,
    1067,   370,     0,   377,     0,   384,     0,     0,  1071,   392,
       0,   395,   397,  1073,   403,     0,   406,   408,   414,     0,
     417,   419,   425,     0,   428,   430,   436,     0,   444,     0,
       0,   452,     0,     0,   455,   463,   470,     0,   466,   467,
     472,   289,   292,     0,   295,     0,   260,   251,   255,   258,
     256,   257,   189,  1203,     0,   868,  1030,   870,  1203,     0,
     705,   707,     0,   504,   501,   494,   499,   500,  1163,  1153,
    1147,   337,  1151,     0,   355,   357,  1159,     0,   365,  1068,
     372,   379,   386,  1158,   394,   396,     0,  1072,   405,   407,
     416,   418,   427,   429,   438,   446,  1160,     0,   454,   456,
     465,   468,     0,   471,     0,   302,   293,   297,   300,   298,
     299,   259,  1112,  1145,  1032,   492,     0,  1203,     0,   869,
     871,     0,   713,   710,   703,   708,   709,  1203,   506,     0,
     526,     0,     0,     0,     0,  1082,  1070,     0,     0,     0,
    1074,  1075,  1076,  1077,     0,     0,   478,   469,   473,   476,
     474,   475,   301,  1203,     0,  1033,     0,   877,   874,   867,
     872,   873,  1203,   715,     0,   735,     0,  1157,   502,   528,
     548,     0,  1203,     0,   507,   358,  1069,  1081,     0,     0,
       0,   457,   477,     0,  1038,  1036,  1031,  1034,  1035,  1203,
     879,     0,   899,     0,  1155,   711,   737,   758,     0,  1203,
       0,   716,   550,   619,     0,     0,   529,     0,     0,   511,
     505,   508,   509,  1078,  1079,  1080,  1203,     0,  1154,   875,
     901,   922,     0,  1203,     0,   880,   760,   829,     0,     0,
     738,     0,     0,   720,   714,   717,   718,   621,   641,     0,
     556,   553,   549,   551,   552,     0,   533,   527,   530,   531,
    1203,   510,   517,     0,   513,   514,   519,  1161,  1037,  1041,
    1039,     0,   924,   993,     0,     0,   902,     0,     0,   884,
     878,   881,   882,   712,   766,   763,   759,   761,   762,     0,
     742,   736,   739,   740,  1203,   719,   726,     0,   722,   723,
     728,   643,   665,     0,     0,   622,   558,     0,   565,     0,
     539,   532,     0,   535,   536,   541,  1162,   512,   515,     0,
     518,     0,     0,  1203,  1124,  1086,     0,  1116,     0,  1042,
    1043,  1048,  1083,  1084,  1085,  1050,  1045,  1047,  1113,  1114,
    1115,  1049,  1121,  1122,  1123,  1046,  1051,   876,   930,   927,
     923,   925,   926,     0,   906,   900,   903,   904,  1203,   883,
     890,     0,   886,   887,   892,   832,   830,   834,   768,     0,
     775,     0,   748,   741,     0,   744,   745,   750,  1152,   721,
     724,     0,   727,   503,     0,     0,     0,   626,   620,   623,
     624,   554,   567,   574,     0,  1203,     0,   559,   534,   537,
       0,   540,     0,   525,   516,  1203,   520,   521,  1095,  1096,
     522,   523,  1203,     0,     0,  1203,     0,  1055,  1040,  1052,
    1053,  1044,   996,   994,   998,   932,     0,   939,     0,   912,
     905,     0,   908,   909,   914,  1146,   885,   888,     0,   891,
       0,   833,   764,   777,   784,     0,     0,   769,   743,   746,
       0,   749,     0,   734,   725,   729,   730,   731,   732,   668,
     666,   670,     0,     0,   648,   642,   645,   646,   632,   625,
       0,   628,   629,   634,   576,   583,     0,     0,   568,     0,
    1181,   562,   557,   560,   561,     0,   547,   538,   542,   543,
     544,   545,   524,     0,  1087,  1125,  1203,  1117,  1054,  1064,
       0,  1063,     0,  1057,  1058,  1060,  1061,  1062,     0,   997,
     928,   941,   948,     0,     0,   933,   907,   910,     0,   913,
       0,   898,   889,   893,   894,   895,   896,     0,   847,   831,
     844,   845,  1203,   835,   841,   843,   838,   840,   842,   839,
     837,   836,   786,   793,     0,     0,   778,  1181,   772,   767,
     770,   771,     0,   757,   747,  1101,  1129,     0,     0,   751,
     752,   754,  1098,  1099,  1100,   753,   755,  1126,  1127,  1128,
     733,     0,   669,     0,   647,   653,     0,   650,   655,   627,
     630,     0,   633,   585,   592,     0,     0,   577,  1181,   571,
     566,   569,   570,  1203,     0,     0,   564,  1179,  1180,   546,
    1203,  1150,  1066,     0,  1056,  1059,     0,  1011,   995,  1008,
    1009,   999,  1005,  1007,  1002,  1004,  1006,  1003,  1000,  1001,
     950,   957,     0,     0,   942,  1181,   936,   931,   934,   935,
       0,   921,   911,  1106,  1134,  1203,  1203,   915,   916,   918,
    1103,  1104,  1105,   917,   919,  1131,  1132,  1133,   897,   846,
     854,  1167,     0,   849,   851,   856,   850,  1164,  1169,     0,
     795,   802,     0,     0,   787,  1181,   781,   776,   779,   780,
       0,   774,   756,  1203,  1203,     0,   683,   667,   680,   681,
     671,   677,   679,   674,   676,   678,   675,   673,   672,   644,
     649,   651,     0,   654,     0,   640,   631,   635,   636,   637,
     638,   594,   601,     0,     0,   586,  1181,   580,   575,   578,
     579,     0,   573,  1148,  1203,     0,   563,  1184,  1182,  1186,
    1097,  1065,  1010,  1018,     0,  1013,  1015,  1020,  1014,   959,
     966,     0,     0,   951,  1181,   945,   940,   943,   944,     0,
     938,   920,     0,     0,   848,   852,     0,   855,  1165,     0,
    1168,  1203,   804,   811,     0,     0,   796,  1181,   790,   785,
     788,   789,     0,   783,   773,  1102,  1130,   682,   690,     0,
     685,   687,   692,   686,     0,   663,   652,   660,   661,     0,
    1203,   656,   659,  1093,   657,  1118,  1119,   658,   639,   603,
     610,     0,     0,   595,  1181,   589,   584,   587,   588,     0,
     582,   572,     0,     0,  1196,  1191,  1193,  1194,     0,  1185,
    1012,  1016,     0,  1019,   968,   975,     0,     0,   960,  1181,
     954,   949,   952,   953,     0,   947,   937,  1203,  1203,     0,
     865,   853,   863,   857,   858,   861,   859,   862,   860,  1181,
    1176,  1166,  1174,  1175,  1173,  1172,  1171,  1170,  1149,   813,
     820,     0,     0,   805,  1181,   799,   794,   797,   798,     0,
     792,   782,   684,   688,     0,   691,   662,     0,     0,     0,
     612,   555,     0,     0,   604,  1181,   598,   593,   596,   597,
       0,   591,   581,  1203,     0,  1195,     0,  1183,  1203,  1203,
    1187,  1189,  1188,     0,  1029,  1017,  1027,  1021,  1022,  1025,
    1023,  1026,  1024,   977,   984,     0,     0,   969,  1181,   963,
     958,   961,   962,     0,   956,   946,  1107,  1135,   864,     0,
    1178,   822,   765,     0,     0,   814,  1181,   808,   803,   806,
     807,     0,   801,   791,     0,   701,   689,   699,   693,   694,
     697,   695,   698,   696,   664,     0,  1203,     0,   613,  1181,
     607,   602,   605,   606,     0,   600,   590,  1192,  1197,     0,
       0,     0,  1028,   986,   929,     0,     0,   978,  1181,   972,
     967,   970,   971,     0,   965,   955,  1177,     0,   823,  1181,
     817,   812,   815,   816,     0,   810,   800,   700,  1094,  1120,
    1181,   616,   611,   614,   615,     0,   609,   599,  1190,  1203,
    1203,     0,   987,  1181,   981,   976,   979,   980,     0,   974,
     964,  1181,   826,   821,   824,   825,     0,   819,   809,     0,
     618,   608,  1198,  1199,  1181,   990,   985,   988,   989,     0,
     983,   973,     0,   828,   818,   617,     0,   992,   982,   827,
     991
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
    1016,  1102,  1103,  1104,  1215,  1013,  1014,  1097,  1210,  1211,
    1212,  1331,  1095,  1096,  1206,  1328,  1329,  1330,  1419,  1204,
    1205,  1324,  1416,  1417,  1418,  1500,  1322,  1323,  1412,  1497,
    1498,  1499,  1574,  1410,  1411,  1493,  1571,  1572,  1573,  1615,
    1491,  1492,  1567,  1612,  1613,  1614,  1639,   868,   869,   924,
    1008,  1009,  1010,  1090,  1091,  1092,  1093,  1201,  1202,  1317,
    1316,   922,   923,  1005,  1085,  1086,  1087,  1196,  1197,  1198,
    1312,  1313,  1401,  1396,  1397,  1398,  1003,  1080,  1081,  1191,
    1192,  1300,  1297,  1298,  1299,  1389,  1390,  1391,  1392,  1484,
    1485,  1558,  1556,  1557,   607,   608,   689,   690,   754,   755,
     756,   794,   795,   796,   830,   864,   865,   866,   917,   918,
     919,   920,  1001,  1002,  1075,  1074,   827,   828,   859,   911,
     912,   913,   994,   995,   996,   997,  1070,  1071,  1179,  1174,
     857,   858,   906,   907,   908,   989,   990,   991,  1066,  1169,
    1170,  1171,  1290,  1064,  1065,  1165,  1287,  1288,  1289,  1382,
    1163,  1164,  1283,  1379,  1380,  1381,  1479,  1281,  1282,  1375,
    1476,  1477,  1478,  1551,  1373,  1374,  1472,  1548,  1549,  1550,
    1604,  1470,  1471,  1544,  1601,  1602,  1603,  1636,  1542,  1543,
    1597,  1633,  1634,  1635,  1652,   903,   986,   987,  1060,  1061,
    1153,  1149,  1150,  1151,  1272,  1273,  1274,  1275,  1366,  1367,
    1453,  1451,  1452,   686,   687,   748,   749,   789,   790,   791,
     821,   822,   823,   854,   900,   901,   902,   981,   982,   983,
     984,  1058,  1059,  1143,  1142,   851,   852,   895,   975,   976,
     977,  1051,  1052,  1053,  1054,  1138,  1139,  1257,  1252,   893,
     894,   970,   971,   972,  1046,  1047,  1048,  1134,  1247,  1248,
    1249,  1359,  1132,  1133,  1243,  1356,  1357,  1358,  1444,  1241,
    1242,  1352,  1441,  1442,  1443,  1533,  1350,  1351,  1437,  1530,
    1531,  1532,  1593,  1435,  1436,  1526,  1590,  1591,  1592,  1628,
    1524,  1525,  1586,  1625,  1626,  1627,  1649,  1584,  1585,  1621,
    1646,  1647,  1648,  1656,   967,  1043,  1044,  1128,  1129,  1231,
    1228,  1229,  1230,  1344,  1345,  1346,  1347,  1432,  1433,  1517,
    1515,  1516,   745,   746,   784,   816,   817,   818,   847,   890,
     891,   948,   949,   950,  1038,  1039,  1040,  1122,  1123,  1124,
    1125,  1126,  1127,  1223,   629,   630,   642,   643,   716,   717,
     770,   771,   772,   773,   766,   951,   952,   953,   954,   955,
     243,   244,   245,  1402,  1403,  1027,  1028,  1029,  1181,  1182,
    1183,  1184,  1259,  1260,  1261,  1262,   956,   598,   599,   600,
     957,   958,   959,   960,  1404,  1405,  1406,   961,   962,   963,
     964,  1186,  1187,  1188,  1189,  1264,  1265,  1266,  1267,   357,
     358,   359,   360,   965,   602,   603,   604,   855,   417,  1017,
    1160,   966,   431,   831,   418,   750,   691,   207,   612,   439,
     433,   452,   785,   804,   419,  1276,  1277,  1278,  1369,  1370,
    1467,  1461,  1462,  1463,  1539,  1216,  1217,  1338,  1339,  1428,
    1429,  1510,  1507,  1218,  1335,  1425,  1426,  1427,  1511,  1512,
     466,   284,   285,   401
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1338
static const yytype_int16 yypact[] =
{
     145, -1338, -1338,    70,    31,   158, -1338, -1338,   152,   110,
     362, -1338,   374, -1338, -1338, -1338, -1338,   125,   396,   468,
   -1338, -1338, -1338, -1338,    31, -1338, -1338, -1338, -1338, -1338,
     139,   398,   104, -1338, -1338, -1338, -1338, -1338,   215, -1338,
   -1338,   232, -1338, -1338,   234, -1338, -1338,   241, -1338, -1338,
     246, -1338, -1338,   162,   584, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,   152, -1338,   192,   400,
      -4, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338,   209,   510, -1338,
   -1338,   407, -1338,   409, -1338,   412, -1338,   224, -1338,   415,
   -1338,   417, -1338,   419, -1338,   422, -1338,   428, -1338,   227,
   -1338,   265,   214,   226,   231,   239,   237, -1338, -1338, -1338,
   -1338,   271,   430,   -29, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,   251,   195, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,    74, -1338,   265, -1338, -1338,    30,
   -1338, -1338, -1338, -1338,    29, -1338, -1338, -1338, -1338,    33,
   -1338, -1338, -1338, -1338,   347,   432, -1338,    27, -1338, -1338,
   -1338, -1338,    24, -1338, -1338, -1338, -1338,    28, -1338, -1338,
   -1338, -1338,    25, -1338, -1338, -1338, -1338,    22, -1338, -1338,
   -1338, -1338,   351,   434, -1338, -1338,   440, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,   150, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,   287,   -65, -1338, -1338,   442, -1338,
     265, -1338, -1338,   359,   225,   381,   225,   385,   225,   363,
   -1338,   388, -1338, -1338, -1338, -1338,   444, -1338, -1338, -1338,
     313, -1338, -1338,   334, -1338, -1338,   343,   461,    36, -1338,
   -1338, -1338, -1338, -1338, -1338,   373, -1338, -1338,   375, -1338,
   -1338,   371, -1338, -1338,   378, -1338, -1338,   384,   486,    15,
   -1338, -1338, -1338, -1338,   498,     1,   339, -1338, -1338, -1338,
   -1338,   451,   242, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,   448,
     455, -1338, -1338,   208, -1338,   454, -1338,   490, -1338,   497,
   -1338,   497, -1338,   497, -1338,   497, -1338,   528, -1338,   528,
   -1338,   528, -1338,   528, -1338,   497, -1338,   497, -1338,   525,
   -1338,   265, -1338, -1338,    13, -1338, -1338, -1338, -1338,   457,
   -1338,   465, -1338,   557, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338,   465, -1338, -1338, -1338, -1338,   465, -1338, -1338, -1338,
   -1338, -1338,   558, -1338,   356, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338,   467, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,   453, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,   456,   460, -1338, -1338,   416, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338,   469, -1338,    11, -1338, -1338, -1338, -1338,   581,
     477, -1338,   583,   492,   496,   502,   504,   585,   509, -1338,
     512, -1338,   516, -1338,   518, -1338,   520, -1338,   522, -1338,
     587,   524, -1338,   529, -1338, -1338, -1338,   473,   421, -1338,
   -1338, -1338, -1338, -1338, -1338,   479, -1338,   593,   494, -1338,
     500, -1338, -1338, -1338,   523, -1338, -1338,   506,   476, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,   535,   252, -1338,   544,
     427,   627,   656,   662,   666,    16, -1338, -1338, -1338, -1338,
   -1338, -1338,   540,   674,   -59, -1338, -1338, -1338, -1338,   790,
      40, -1338, -1338, -1338, -1338,   425, -1338, -1338, -1338, -1338,
      51, -1338, -1338, -1338, -1338,    50, -1338, -1338, -1338, -1338,
     791,   -39, -1338, -1338, -1338, -1338,   -51, -1338, -1338, -1338,
   -1338,   -69, -1338, -1338, -1338, -1338,   -33, -1338, -1338, -1338,
   -1338,   -25, -1338, -1338, -1338, -1338,   -44, -1338, -1338, -1338,
   -1338,   792,   405, -1338, -1338, -1338, -1338,   458, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338,   624,   586, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,   575,   252,   658, -1338,
   -1338,   796,   797, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338,   596,   769, -1338,
     589, -1338, -1338, -1338, -1338, -1338, -1338,   668, -1338, -1338,
   -1338,   798,   794, -1338,   -54, -1338,   799, -1338,   795,   187,
   -1338, -1338,   488, -1338,    79, -1338,    52,   800, -1338, -1338,
      26, -1338, -1338, -1338, -1338,    20, -1338, -1338, -1338,   -40,
   -1338, -1338, -1338,   -19, -1338, -1338, -1338,    38, -1338,    32,
     801, -1338,   802,   470, -1338, -1338, -1338,   690,   692, -1338,
   -1338, -1338, -1338,   622,   252,   689, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,   806, -1338,   602,   781, -1338,   626,
   -1338, -1338,   811,   649, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338,   815, -1338, -1338, -1338,   816, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,   628,   367, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338,   817, -1338, -1338,
   -1338, -1338,   630,   252,   700, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,   803, -1338,   632, -1338,
   -1338,   818,   629, -1338, -1338, -1338, -1338, -1338, -1338,   655,
     652,   789,   719,   686,   683, -1338, -1338,   829,   830,   831,
   -1338, -1338, -1338, -1338,   669,   714, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,   636, -1338,   832,   633, -1338, -1338,
   -1338, -1338, -1338, -1338,   639,   641,   805, -1338, -1338, -1338,
     664,   789, -1338,   638, -1338, -1338, -1338, -1338,   833,   837,
     838, -1338, -1338,   841, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338,   642,   643,   812, -1338, -1338, -1338,   675,   805, -1338,
     640, -1338, -1338,   661,   646,   648, -1338,   847,   513, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338,   471, -1338, -1338,
   -1338,   680,   812, -1338,   677, -1338, -1338, -1338,   679,   681,
   -1338,   850,   493, -1338, -1338, -1338, -1338, -1338,   665,   789,
     682, -1338, -1338, -1338, -1338,   175, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338,   694,   696, -1338, -1338, -1338, -1338, -1338,
   -1338,   216, -1338, -1338,   685,   687, -1338,   851,   491, -1338,
   -1338, -1338, -1338,   739,   684, -1338, -1338, -1338, -1338,   159,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338,   663,   667, -1338,
   -1338, -1338, -1338,   836,   691, -1338, -1338,   697,   688,   822,
   -1338, -1338,   698,   704, -1338, -1338, -1338, -1338, -1338,   693,
     206,   863,   867, -1338, -1338, -1338,   868, -1338,   695,   216,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338,   753,   702, -1338,
   -1338, -1338, -1338,   153, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338,   670,   671, -1338, -1338, -1338, -1338, -1338, -1338,   705,
     707,   822, -1338, -1338,   672,   676, -1338, -1338, -1338, -1338,
   -1338,   699,   206,   761,   878,   701,  -121, -1338, -1338, -1338,
   -1338, -1338, -1338,   708,   822, -1338,   703, -1338, -1338, -1338,
     706,   206,   717, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338,   883,   886, -1338,     9, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,   718,   715,   822, -1338,
   -1338,   712,   710, -1338, -1338, -1338, -1338, -1338,   709,   206,
     711,   291, -1338, -1338,   721,   822,   713, -1338, -1338, -1338,
     716,   326,   723, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338,   889,   534, -1338, -1338, -1338, -1338, -1338, -1338,
     725,   727, -1338, -1338, -1338,   729,   822,   720, -1338,   891,
     678, -1338, -1338, -1338, -1338,   731, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338,   893, -1338, -1338, -1338, -1338, -1338, -1338,
     897, -1338,   732,   106, -1338, -1338, -1338, -1338,   722,   353,
   -1338, -1338,   734,   822,   724, -1338, -1338, -1338,   726,   128,
     733, -1338, -1338, -1338, -1338, -1338, -1338,   -73, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338,   735,   822,   728, -1338,   678, -1338, -1338,
   -1338, -1338,   737, -1338, -1338, -1338, -1338,   901,   902, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338,   730,   449,   898, -1338, -1338,   548, -1338, -1338, -1338,
   -1338,   736,   206, -1338,   741,   822,   738, -1338,   678, -1338,
   -1338, -1338, -1338, -1338,   743,   749, -1338,   745, -1338, -1338,
   -1338, -1338, -1338,   747, -1338, -1338,   -55, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338,   751,   822,   740, -1338,   678, -1338, -1338, -1338, -1338,
     755, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338,   785,   757, -1338, -1338,   760, -1338, -1338,   903,
   -1338,   759,   822,   742, -1338,   678, -1338, -1338, -1338, -1338,
     763, -1338, -1338, -1338, -1338,   -57, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338,   744,    54,   765, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338,   767,   822,   746, -1338,   678, -1338, -1338, -1338,
   -1338,   771, -1338, -1338, -1338,   748, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,   788,   770, -1338, -1338,   760, -1338,
     773,   822,   750, -1338,   678, -1338, -1338, -1338, -1338,   777,
   -1338, -1338,   465,   465, -1338, -1338,   752,   303, -1338,   754,
     164, -1338, -1338,   779,   822,   756, -1338,   678, -1338, -1338,
   -1338, -1338,   775, -1338, -1338, -1338, -1338, -1338, -1338,   793,
     783, -1338, -1338,   760,  -119, -1338, -1338, -1338, -1338,   906,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
     786,   822,   758, -1338,   678, -1338, -1338, -1338, -1338,   787,
   -1338, -1338,   905,    12, -1338, -1338, -1338, -1338,   910,   545,
   -1338, -1338,   762,   303, -1338,   804,   822,   764, -1338,   678,
   -1338, -1338, -1338, -1338,   808, -1338, -1338, -1338, -1338,   807,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,   678,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
     809,   822,   766, -1338,   678, -1338, -1338, -1338, -1338,   813,
   -1338, -1338, -1338, -1338,   768,   303, -1338,  -114,   465,   915,
   -1338, -1338,   822,   772, -1338,   678, -1338, -1338, -1338, -1338,
     810, -1338, -1338, -1338,   814, -1338,   920, -1338, -1338, -1338,
   -1338, -1338, -1338,   820, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,   821,   822,   774, -1338,   678, -1338,
   -1338, -1338, -1338,   819, -1338, -1338, -1338, -1338, -1338,   823,
   -1338, -1338, -1338,   822,   776, -1338,   678, -1338, -1338, -1338,
   -1338,   827, -1338, -1338,   824, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338,   908, -1338,   778, -1338,   678,
   -1338, -1338, -1338, -1338,   825, -1338, -1338, -1338, -1338,   826,
     923,   924, -1338, -1338, -1338,   822,   780, -1338,   678, -1338,
   -1338, -1338, -1338,   828, -1338, -1338, -1338,   782, -1338,   678,
   -1338, -1338, -1338, -1338,   834, -1338, -1338, -1338, -1338, -1338,
     678, -1338, -1338, -1338, -1338,   835, -1338, -1338, -1338, -1338,
   -1338,   784, -1338,   678, -1338, -1338, -1338, -1338,   839, -1338,
   -1338,   678, -1338, -1338, -1338, -1338,   840, -1338, -1338,   842,
   -1338, -1338, -1338, -1338,   678, -1338, -1338, -1338, -1338,   845,
   -1338, -1338,   843, -1338, -1338, -1338,   844, -1338, -1338, -1338,
   -1338
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,   855, -1338,
     909, -1338, -1338, -1338, -1338, -1338, -1338, -1338,   881, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,   846, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,   527,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338,   852, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338,   462, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
     848, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338,   360, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,   635, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
     314, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,   302, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,   305, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,   298, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338,   306, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338,   288, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338,   293, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338,    78, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,    39, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,  -428, -1083, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,  -227, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338,  -419, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
      56, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338,   -17, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,  -293, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,    -1,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338,   -70, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338,  -362, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338,    35, -1338, -1338, -1338, -1338, -1338,  -138,
   -1338, -1338, -1338, -1338,  -456,  -468,  -490, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1043, -1338, -1338, -1338,  -153,
   -1338, -1338, -1338, -1338, -1338,  -996, -1338, -1338, -1337, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338,  -484, -1338, -1338, -1338,
   -1041, -1338, -1338, -1338, -1338, -1338, -1338, -1040, -1338, -1338,
   -1338, -1332, -1338, -1338, -1338, -1338, -1338, -1338, -1338,  -200,
   -1338, -1338, -1338,  -477, -1338, -1338, -1338,  -841, -1338,  -987,
   -1088, -1338, -1338,  -816, -1338, -1338, -1338,  -143, -1338,   -49,
    -263, -1338, -1338,  -796, -1338, -1179, -1237, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1153, -1338, -1338, -1338, -1338,
   -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338, -1338,
    -359,  -371, -1338, -1338
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     472,   242,   469,   597,  1067,   836,  1076,   471,  1200,   396,
     601,   896,   860,   247,  1291,   500,  1504,   455,  1154,   392,
    1157,  1158,   463,   464,   483,  1109,   275,  1098,   266,   272,
    1455,   263,   269,   251,   248,  1457,   365,   254,   370,  1368,
     383,  1239,   492,   493,   494,   221,   647,  1348,   622,  1269,
    1088,   651,  1088,   622,   222,  1332,   655,  1088,   434,   632,
     435,  1135,   436,  1144,   634,  1387,   223,  1342,   138,   636,
       6,  1089,   447,   925,   449,  1180,   638,  1486,  1166,   623,
    1399,   356,  1564,   364,   704,   369,  1232,   350,  1235,  1236,
     222,   802,  1360,   648,   638,   657,  1519,  1400,     7,   628,
     659,  1521,   223,   680,  1307,   638,   638,   644,   658,  1207,
     681,  1368,   638,   423,  1388,   139,  1393,   639,   628,   140,
     239,   141,   720,   142,   240,   143,   638,   652,  1270,   656,
     249,   252,  1383,   393,   267,   264,   619,   255,   276,   273,
     270,   722,   384,  1258,  1271,   456,  1244,   501,  1560,  1301,
     616,  1304,  1305,  1562,  1343,   647,  1368,     1,     2,   651,
    1271,   709,  1271,   655,   709,   638,   709,    13,   709,   591,
    1025,   638,    11,  1420,    85,   628,   593,  1284,   718,    16,
     627,   628,   714,   628,   725,  1253,  1254,  1255,  1256,   709,
     739,   709,   724,   628,   628,   628,    29,   740,   454,   633,
     635,  1445,   712,    86,  1015,    87,  1318,    88,   592,    89,
     239,    90,    77,    91,   240,    92,   594,    93,  1325,    94,
     122,    95,   628,    96,  1480,  1118,   293,   711,  1119,  1120,
     127,  1121,   397,   398,   399,   400,  1505,   123,   692,   124,
     941,   942,   698,   699,   700,  1161,   125,   591,  1025,   780,
     592,   126,   943,   353,   593,  1353,   781,   591,   594,   354,
     592,  1501,   239,   944,   593,   945,   240,   130,   594,   294,
     353,   239,   413,   414,   415,   240,   354,   946,   947,   157,
     441,   205,   443,   295,   445,   296,  1534,   297,  1238,   298,
     174,   299,   202,   591,   208,  1376,   592,   300,   239,   301,
     593,   302,   240,   303,   594,   304,  1540,   305,  1152,   306,
     209,   307,   742,   308,   139,   941,   942,   751,   140,   210,
     141,  1552,   142,   231,   143,  1119,  1120,   708,  1121,   829,
     628,   211,   591,   212,   596,   592,  1413,   239,   944,   593,
     945,   240,  1575,   594,   591,  1025,   930,   592,   213,   931,
     257,   593,   946,   947,   278,   594,  1175,  1176,  1177,  1178,
     992,   342,  1049,   993,  1438,  1050,   371,   591,  1025,   351,
    1152,  1454,    19,    20,   593,  1594,   786,   941,   942,  1175,
    1176,  1177,  1178,  1466,    24,    25,   797,  1473,   767,   768,
     769,   361,   853,  1605,   591,   366,  1308,   592,   372,   239,
     944,   593,   945,   240,  1200,   594,    32,    33,    80,    81,
     133,   134,   813,   379,   946,   947,  1616,   159,   160,   164,
     165,   824,   169,   170,  1494,   177,   178,   182,   183,   187,
     188,   837,   192,   193,   679,  1629,   380,  1518,   197,   198,
     216,   217,   258,   259,   279,   280,  1637,   381,   848,  1527,
     286,   287,   344,   345,   374,   375,  1030,  1640,   861,   402,
     403,   408,   409,  1031,   424,   425,  1152,   458,   459,   382,
    1650,   463,   464,   941,   942,   887,   475,   476,  1653,   495,
     496,   386,   897,   388,  1545,   387,   802,   504,   505,  1559,
     591,  1657,   389,   592,   391,   239,   944,   593,   945,   240,
     390,   594,   510,   511,   395,  1568,   515,   516,   429,   936,
     946,   947,   520,   521,   525,   526,   432,  1407,  1077,   531,
     532,   738,   536,   537,   420,  1078,   541,   542,   546,   547,
     551,   552,   556,   557,   562,   563,    37,  1110,  1587,   567,
     568,   573,   574,   998,  1111,   588,   589,    38,   437,    39,
      40,    41,   450,    42,    43,    44,  1598,    45,    46,    47,
     467,    48,    49,    50,   473,    51,    52,   631,   628,   661,
     662,   482,  1034,   481,   294,  1145,   484,  1156,   665,   666,
     779,   403,  1146,   488,  1159,   675,   676,  1185,   295,   503,
     296,   509,   297,   530,   298,   561,   299,   476,  1622,   693,
     694,   580,   300,   579,   301,   572,   302,  1055,   303,    86,
     304,    87,   305,    88,   306,    89,   307,    90,   308,    91,
     581,    92,   605,    93,   606,    94,   584,    95,   582,    96,
     710,   628,   734,   735,   728,   662,   752,   753,   764,   765,
     775,   776,   787,   788,  1099,  1234,   814,   815,   838,   839,
     862,   863,  1237,   583,  1113,  1263,   870,   871,   875,   876,
     609,  1114,   613,    38,  1117,    39,    40,    41,   614,    42,
      43,    44,   615,    45,    46,    47,   620,    48,    49,    50,
     621,    51,    52,   881,   882,   888,   889,   898,   899,   904,
     905,   909,   910,   915,   916,   968,   969,   973,   974,   979,
     980,  1006,  1007,  1022,  1023,  1036,  1037,   574,  1303,  1072,
    1073,  1083,  1084,  1100,  1101,  1306,  1105,  1106,  1319,  1140,
    1141,  1147,  1148,  1167,  1168,  1320,  1172,  1173,  1194,  1195,
    1208,  1209,  1226,  1227,  1245,  1246,  1250,  1251,  1285,  1286,
    1295,  1296,  1310,  1195,   671,  1221,  1314,  1315,  1326,  1327,
    1354,  1355,  1377,  1378,  1394,  1395,  1414,  1415,  1423,  1424,
    1439,  1440,  1449,  1450,  1459,  1460,  1474,  1475,  1495,  1496,
    1508,  1509,  1513,  1514,  1528,  1529,  1546,  1547,  1554,  1555,
     682,  1279,  1569,  1570,  1588,  1589,  1599,  1600,  1610,  1611,
    1623,  1624,  1631,  1632,  1644,  1645,   626,   637,   660,   683,
     684,   685,   701,   688,   703,   707,   702,   706,   713,   726,
     730,   741,   727,   666,   743,   744,   747,   757,   758,   762,
     763,   774,   782,   798,   792,   799,   802,   805,   793,   807,
     806,   783,   808,   809,   810,   811,   812,   825,   819,   832,
     820,   843,  1333,   829,   826,   844,   845,   846,   849,  1340,
     856,   853,   867,   880,   850,   892,   914,   978,   921,   926,
     985,   988,  1015,   999,   937,  1004,  1032,   882,   916,  1012,
    1033,  1035,  1018,  1011,  1042,   930,  1068,   992,  1056,  1045,
     980,  1062,  1079,  1456,  1362,  1363,  1082,  1094,  1063,  1112,
    1458,  1115,  1116,  1465,  1130,  1193,  1131,  1213,  1088,  1220,
    1162,  1214,  1222,  1219,  1293,  1294,  1309,  1364,  1155,  1371,
    1430,  1503,  1203,  1240,  1488,  1482,  1608,  1199,  1280,  1049,
    1506,  1566,  1385,  1386,  1136,  1190,  1579,  1336,  1321,  1619,
    1620,   129,   485,    76,  1349,   128,   672,  1408,   705,  1292,
     585,  1384,   715,  1268,   158,   421,  1372,   721,  1224,  1520,
     719,   729,  1409,  1421,  1388,  1446,  1522,  1481,  1270,   723,
    1434,   731,   938,  1422,  1469,  1361,  1487,  1502,  1341,  1311,
    1334,  1483,  1019,  1337,  1000,  1490,  1233,  1271,  1069,  1343,
    1365,  1057,  1137,  1431,  1041,  1225,     0,     0,     0,  1523,
    1535,     0,     0,  1553,  1576,     0,  1607,   232,  1541,  1595,
    1468,  1561,     0,  1447,  1448,     0,     0,     0,  1563,  1538,
    1583,  1606,  1630,  1617,     0,     0,     0,     0,     0,     0,
       0,  1641,  1638,     0,     0,     0,  1654,  1651,     0,  1489,
    1582,  1658,  1655,  1659,  1660,     0,     0,     0,  1578,  1302,
       0,  1596,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1618,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   343,     0,     0,  1536,  1537,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1565,
       0,     0,  1577,     0,     0,     0,     0,  1580,  1581,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1609,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1464,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1642,  1643
};

static const yytype_int16 yycheck[] =
{
     371,   154,   361,   487,   991,   801,  1002,   366,  1091,     8,
     487,   852,   828,   156,  1167,     4,     4,     4,  1061,     4,
    1061,  1061,     6,     7,   395,  1021,     4,  1014,     4,     4,
    1367,     4,     4,     4,     4,  1367,   236,     4,   238,  1276,
       4,  1129,   413,   414,   415,    74,   536,  1226,   107,   122,
     171,   541,   171,   107,   119,  1208,   546,   171,   321,   515,
     323,  1048,   325,  1059,   520,   122,   131,   122,    72,   525,
       0,   192,   335,   869,   337,  1071,   145,   196,  1065,   138,
      26,   234,   196,   236,   138,   238,  1129,   230,  1129,  1129,
     119,    37,  1245,   162,   145,   551,  1433,    43,    67,   143,
     556,  1433,   131,   587,  1192,   145,   145,   158,   152,  1096,
     587,  1348,   145,   313,   171,   119,  1295,   156,   143,   123,
      46,   125,   162,   127,    50,   129,   145,   160,   201,   154,
     100,   102,  1285,   118,   110,   108,   495,   104,   116,   114,
     112,   160,   106,  1139,   217,   132,  1133,   136,  1485,  1192,
     134,  1192,  1192,  1485,   209,   645,  1393,    12,    13,   649,
     217,   629,   217,   653,   632,   145,   634,    15,   636,    41,
      42,   145,    14,  1326,    70,   143,    48,  1164,   158,    69,
     140,   143,   156,   143,   152,    57,    58,    59,    60,   657,
     674,   659,   154,   143,   143,   143,    71,   674,   341,   148,
     150,  1354,   150,    99,    40,   101,  1202,   103,    44,   105,
      46,   107,    73,   109,    50,   111,    52,   113,  1205,   115,
       5,   117,   143,   119,  1377,   216,    76,   148,   219,   220,
      68,   222,   231,   232,   233,   234,   224,     5,   609,     5,
      24,    25,   613,   614,   615,  1061,     5,    41,    42,   733,
      44,     5,    36,    45,    48,  1242,   733,    41,    52,    51,
      44,  1414,    46,    47,    48,    49,    50,    75,    52,   119,
      45,    46,    30,    31,    32,    50,    51,    61,    62,    70,
     329,    16,   331,   133,   333,   135,  1439,   137,  1129,   139,
      66,   141,    65,    41,    80,  1282,    44,   147,    46,   149,
      48,   151,    50,   153,    52,   155,  1459,   157,    17,   159,
      84,   161,   683,   163,   119,    24,    25,   688,   123,    88,
     125,  1474,   127,    72,   129,   219,   220,   140,   222,    38,
     143,    92,    41,    96,   487,    44,  1323,    46,    47,    48,
      49,    50,  1495,    52,    41,    42,   171,    44,    77,   174,
       3,    48,    61,    62,     3,    52,    53,    54,    55,    56,
     201,    74,   209,   204,  1351,   212,     3,    41,    42,    10,
      17,  1367,    10,    11,    48,  1528,   747,    24,    25,    53,
      54,    55,    56,  1370,    10,    11,   757,  1374,    21,    22,
      23,    10,    39,  1546,    41,    10,  1192,    44,    10,    46,
      47,    48,    49,    50,  1487,    52,    10,    11,    10,    11,
      10,    11,   783,   100,    61,    62,  1569,    10,    11,    10,
      11,   792,    10,    11,  1411,    10,    11,    10,    11,    10,
      11,   802,    10,    11,   587,  1588,   102,  1433,    10,    11,
      10,    11,    10,    11,    10,    11,  1599,   104,   819,  1436,
      10,    11,    10,    11,    10,    11,   940,  1610,   829,   120,
     121,    10,    11,   940,    10,    11,    17,    10,    11,     8,
    1623,     6,     7,    24,    25,   846,   120,   121,  1631,    10,
      11,   108,   853,   112,  1471,   110,    37,    10,    11,  1485,
      41,  1644,   114,    44,     8,    46,    47,    48,    49,    50,
     116,    52,    10,    11,     6,  1492,    10,    11,    18,   880,
      61,    62,    10,    11,    10,    11,    19,  1313,  1002,    10,
      11,   674,    10,    11,    76,  1002,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    68,  1021,  1525,    10,
      11,   120,   121,   914,  1021,    10,    11,    79,    20,    81,
      82,    83,    27,    85,    86,    87,  1543,    89,    90,    91,
       3,    93,    94,    95,     6,    97,    98,   142,   143,   164,
     165,   118,   943,   106,   119,  1059,   120,  1061,   120,   121,
     733,   121,  1059,   167,  1061,    10,    11,  1071,   133,     8,
     135,     8,   137,     8,   139,     8,   141,   121,  1585,    10,
      11,     8,   147,   124,   149,   132,   151,   978,   153,    99,
     155,   101,   157,   103,   159,   105,   161,   107,   163,   109,
     126,   111,    78,   113,   197,   115,   120,   117,   128,   119,
     142,   143,    10,    11,   164,   165,    10,    11,    10,    11,
      10,    11,    10,    11,  1015,  1129,    10,    11,    10,    11,
      10,    11,  1129,   130,  1025,  1139,    10,    11,    10,    11,
      33,  1032,     6,    79,  1035,    81,    82,    83,     6,    85,
      86,    87,     6,    89,    90,    91,   136,    93,    94,    95,
       6,    97,    98,   170,   171,   214,   215,    10,    11,    10,
      11,    10,    11,   200,   201,    10,    11,    10,    11,   208,
     209,    10,    11,    10,    11,    10,    11,   121,  1192,    10,
      11,    10,    11,    10,    11,  1192,    10,    11,  1202,    10,
      11,    10,    11,    10,    11,  1202,    10,    11,   194,   195,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,   194,   195,   120,  1116,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     225,   226,    10,    11,    10,    11,    10,    11,    10,    11,
     122,  1152,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,     6,     6,     6,     3,
       3,   205,   134,    34,    10,    10,     8,     8,     8,     8,
     120,   122,    10,   121,     8,   213,    35,     6,   169,     4,
       4,     4,   122,   168,     6,   173,    37,   108,   199,   146,
     144,    28,     3,     3,     3,   166,   122,   198,     6,   175,
     207,     8,  1213,    38,   203,     8,     8,     6,   206,  1220,
     175,    39,   191,     6,   211,   175,     6,     6,   193,   177,
     121,   177,    40,   200,   170,    29,     3,   171,   201,   181,
       3,     3,   174,   176,   121,   171,   204,   201,   208,   177,
     209,   176,   121,  1367,  1255,  1256,     8,   179,   181,   172,
    1367,     8,     6,  1370,   176,     6,   181,     6,   171,     6,
     179,   223,     5,   172,     3,     3,     8,   122,  1061,     6,
     122,     6,   183,   179,     8,   122,     8,   192,   183,   209,
      10,     6,  1293,  1294,   212,   202,     6,   178,   187,     6,
       6,    76,   405,    24,   183,    54,   576,   172,   624,   202,
     478,   178,   640,   210,    98,   310,   187,   649,   216,  1433,
     645,   663,   185,   182,   171,   178,  1433,   182,   201,   653,
     187,   668,   884,  1334,   185,   210,  1394,   180,   221,  1196,
     227,  1390,   933,   228,   918,   189,  1129,   217,   995,   209,
    1273,   982,  1052,  1345,   949,  1123,    -1,    -1,    -1,   185,
     182,    -1,    -1,   180,   184,    -1,   172,   145,   189,   180,
    1371,  1485,    -1,  1362,  1363,    -1,    -1,    -1,  1485,   202,
     189,   184,   184,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   188,    -1,    -1,    -1,   186,   188,    -1,  1400,
     210,   186,   190,   190,   190,    -1,    -1,    -1,   224,  1192,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,    -1,  1447,  1448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1488,
      -1,    -1,  1503,    -1,    -1,    -1,    -1,  1508,  1509,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1566,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1619,  1620
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   236,   237,   238,     0,    67,   245,   246,
     247,    14,   239,    15,   243,   244,    69,   274,   275,    10,
      11,   248,   249,   250,    10,    11,   240,   241,   242,    71,
     360,   361,    10,    11,   276,   277,   278,    68,    79,    81,
      82,    83,    85,    86,    87,    89,    90,    91,    93,    94,
      95,    97,    98,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   245,    73,   408,   409,
      10,    11,   362,   363,   364,    70,    99,   101,   103,   105,
     107,   109,   111,   113,   115,   117,   119,   279,   280,   281,
     282,   283,   288,   289,   294,   295,   300,   301,   308,   309,
     314,   315,   320,   321,   326,   327,   332,   333,   338,   339,
     346,   347,     5,     5,     5,     5,     5,    68,   253,   243,
      75,   436,   437,    10,    11,   410,   411,   412,    72,   119,
     123,   125,   127,   129,   365,   366,   367,   368,   369,   375,
     376,   382,   383,   389,   390,   394,   395,    70,   281,    10,
      11,   284,   285,   286,    10,    11,   290,   291,   292,    10,
      11,   296,   297,   298,    66,   302,   303,    10,    11,   310,
     311,   312,    10,    11,   316,   317,   318,    10,    11,   322,
     323,   324,    10,    11,   328,   329,   330,    10,    11,   334,
     335,   336,    65,   340,   341,    16,   348,  1012,    80,    84,
      88,    92,    96,    77,   552,   553,    10,    11,   438,   439,
     440,    74,   119,   131,   413,   414,   415,   416,   417,   422,
     423,    72,   367,   370,   371,   377,   378,   384,   385,    46,
      50,   391,   954,   955,   956,   957,   396,  1012,     4,   100,
     287,     4,   102,   293,     4,   104,   299,     3,    10,    11,
     304,   305,   306,     4,   108,   313,     4,   110,   319,     4,
     112,   325,     4,   114,   331,     4,   116,   337,     3,    10,
      11,   342,   343,   344,  1046,  1047,    10,    11,   349,   350,
     351,   554,   555,    76,   119,   133,   135,   137,   139,   141,
     147,   149,   151,   153,   155,   157,   159,   161,   163,   441,
     442,   443,   444,   445,   452,   453,   458,   459,   466,   467,
     471,   472,   476,   477,   481,   482,   486,   487,   494,   495,
     502,   503,   510,   511,   518,   519,   524,   525,   530,   531,
     538,   539,    74,   415,    10,    11,   418,   419,   420,   424,
    1012,    10,   373,    45,    51,   372,   954,   994,   995,   996,
     997,    10,   380,   379,   954,   994,    10,   387,   386,   954,
     994,     3,    10,   392,    10,    11,   397,   398,   399,   100,
     102,   104,     8,     4,   106,   307,   108,   110,   112,   114,
     116,     8,     4,   118,   345,     6,     8,   231,   232,   233,
     234,  1048,   120,   121,   352,   353,   354,   355,    10,    11,
     557,   558,   559,    30,    31,    32,   556,  1003,  1009,  1019,
      76,   443,   446,   994,    10,    11,   454,   455,   456,    18,
     460,  1007,    19,  1015,  1015,  1015,  1015,    20,   488,  1014,
     496,  1014,   504,  1014,   512,  1014,   520,  1015,   526,  1015,
      27,   532,  1016,   540,  1012,     4,   132,   421,    10,    11,
     425,   426,   427,     6,     7,   374,  1045,     3,   381,  1045,
     388,  1045,  1046,     6,   393,   120,   121,   400,   401,   402,
     403,   106,   118,  1046,   120,   354,   356,   357,   167,   560,
     561,   562,  1046,  1046,  1046,    10,    11,   447,   448,   449,
       4,   136,   457,     8,    10,    11,   461,   462,   463,     8,
      10,    11,   468,   469,   470,    10,    11,   473,   474,   475,
      10,    11,   478,   479,   480,    10,    11,   483,   484,   485,
       8,    10,    11,   489,   490,   491,    10,    11,   497,   498,
     499,    10,    11,   505,   506,   507,    10,    11,   513,   514,
     515,    10,    11,   521,   522,   523,    10,    11,   527,   528,
     529,     8,    10,    11,   533,   534,   535,    10,    11,   541,
     542,   543,   132,   120,   121,   428,   429,   430,   431,   124,
       8,   126,   128,   130,   120,   402,   404,   405,    10,    11,
     359,    41,    44,    48,    52,   358,   954,   971,   972,   973,
     974,   998,   999,  1000,  1001,    78,   197,   699,   700,    33,
     563,   564,  1013,     6,     6,     6,   134,   450,   451,  1045,
     136,     6,   107,   138,   464,   465,     6,   140,   143,   939,
     940,   142,   939,   148,   939,   150,   939,     6,   145,   156,
     492,   493,   941,   942,   158,   500,   501,   941,   162,   508,
     509,   941,   160,   516,   517,   941,   154,   939,   152,   939,
       6,   164,   165,   536,   537,   120,   121,   544,   545,   546,
     547,   120,   430,   432,   433,    10,    11,   407,   406,   954,
     971,   998,   122,     3,     3,   205,   808,   809,    34,   701,
     702,  1011,  1046,    10,    11,   565,   566,   567,  1046,  1046,
    1046,   134,     8,    10,   138,   465,     8,    10,   140,   940,
     142,   148,   150,     8,   156,   493,   943,   944,   158,   501,
     162,   509,   160,   517,   154,   152,     8,    10,   164,   537,
     120,   546,   548,   549,    10,    11,   435,   434,   954,   971,
     998,   122,  1046,     8,   213,   917,   918,    35,   810,   811,
    1010,  1046,    10,    11,   703,   704,   705,     6,   169,   568,
     569,   570,     4,     4,    10,    11,   949,    21,    22,    23,
     945,   946,   947,   948,     4,    10,    11,   551,   550,   954,
     971,   998,   122,    28,   919,  1017,  1046,    10,    11,   812,
     813,   814,     6,   199,   706,   707,   708,  1046,   168,   173,
     583,   584,    37,   571,  1018,   108,   144,   146,     3,     3,
       3,   166,   122,  1046,    10,    11,   920,   921,   922,     6,
     207,   815,   816,   817,  1046,   198,   203,   721,   722,    38,
     709,  1008,   175,   597,   598,   585,  1018,  1046,    10,    11,
     572,   573,   574,     8,     8,     8,     6,   923,  1046,   206,
     211,   830,   831,    39,   818,  1002,   175,   735,   736,   723,
    1008,  1046,    10,    11,   710,   711,   712,   191,   652,   653,
      10,    11,   599,   600,   601,    10,    11,   586,   587,   588,
       6,   170,   171,   575,   576,   577,   578,  1046,   214,   215,
     924,   925,   175,   844,   845,   832,  1002,  1046,    10,    11,
     819,   820,   821,   790,    10,    11,   737,   738,   739,    10,
      11,   724,   725,   726,     6,   200,   201,   713,   714,   715,
     716,   193,   666,   667,   654,  1018,   177,   602,   603,   604,
     171,   174,   589,   590,   591,   592,  1046,   170,   577,   579,
     580,    24,    25,    36,    47,    49,    61,    62,   926,   927,
     928,   950,   951,   952,   953,   954,   971,   975,   976,   977,
     978,   982,   983,   984,   985,   998,  1006,   899,    10,    11,
     846,   847,   848,    10,    11,   833,   834,   835,     6,   208,
     209,   822,   823,   824,   825,   121,   791,   792,   177,   740,
     741,   742,   201,   204,   727,   728,   729,   730,  1046,   200,
     715,   717,   718,   681,    29,   668,    10,    11,   655,   656,
     657,   176,   181,   610,   611,    40,   605,  1004,   174,   591,
     593,   594,    10,    11,   582,    42,   581,   960,   961,   962,
     971,   998,     3,     3,  1046,     3,    10,    11,   929,   930,
     931,   928,   121,   900,   901,   177,   849,   850,   851,   209,
     212,   836,   837,   838,   839,  1046,   208,   824,   826,   827,
     793,   794,   176,   181,   748,   749,   743,  1004,   204,   729,
     731,   732,    10,    11,   720,   719,   960,   971,   998,   121,
     682,   683,     8,    10,    11,   669,   670,   671,   171,   192,
     658,   659,   660,   661,   179,   617,   618,   612,  1004,  1046,
      10,    11,   606,   607,   608,    10,    11,   596,   595,   960,
     971,   998,   172,  1046,  1046,     8,     6,  1046,   216,   219,
     220,   222,   932,   933,   934,   935,   936,   937,   902,   903,
     176,   181,   857,   858,   852,  1004,   212,   838,   840,   841,
      10,    11,   829,   828,   960,   971,   998,    10,    11,   796,
     797,   798,    17,   795,   950,   954,   971,   975,   982,   998,
    1005,  1008,   179,   755,   756,   750,  1004,    10,    11,   744,
     745,   746,    10,    11,   734,    53,    54,    55,    56,   733,
     960,   963,   964,   965,   966,   971,   986,   987,   988,   989,
     202,   684,   685,     6,   194,   195,   672,   673,   674,   192,
     660,   662,   663,   183,   624,   625,   619,  1004,    10,    11,
     613,   614,   615,     6,   223,   609,  1030,  1031,  1038,   172,
       6,  1046,     5,   938,   216,   934,    10,    11,   905,   906,
     907,   904,   950,   954,   971,   975,   982,   998,  1002,  1005,
     179,   864,   865,   859,  1004,    10,    11,   853,   854,   855,
      10,    11,   843,    57,    58,    59,    60,   842,   960,   967,
     968,   969,   970,   971,   990,   991,   992,   993,   210,   122,
     201,   217,   799,   800,   801,   802,  1020,  1021,  1022,  1046,
     183,   762,   763,   757,  1004,    10,    11,   751,   752,   753,
     747,  1030,   202,     3,     3,    10,    11,   687,   688,   689,
     686,   950,   954,   971,   975,   982,   998,  1005,  1018,     8,
     194,   673,   675,   676,    10,    11,   665,   664,   960,   971,
     998,   187,   631,   632,   626,  1004,    10,    11,   620,   621,
     622,   616,  1030,  1046,   227,  1039,   178,   228,  1032,  1033,
    1046,   221,   122,   209,   908,   909,   910,   911,  1020,   183,
     871,   872,   866,  1004,    10,    11,   860,   861,   862,   856,
    1030,   210,  1046,  1046,   122,   801,   803,   804,  1021,  1023,
    1024,     6,   187,   769,   770,   764,  1004,    10,    11,   758,
     759,   760,   754,  1030,   178,  1046,  1046,   122,   171,   690,
     691,   692,   693,  1020,    10,    11,   678,   679,   680,    26,
      43,   677,   958,   959,   979,   980,   981,  1018,   172,   185,
     638,   639,   633,  1004,    10,    11,   627,   628,   629,   623,
    1030,   182,  1046,    10,    11,  1040,  1041,  1042,  1034,  1035,
     122,   910,   912,   913,   187,   878,   879,   873,  1004,    10,
      11,   867,   868,   869,   863,  1030,   178,  1045,  1045,    10,
      11,   806,   807,   805,   960,   963,   971,   986,   998,    10,
      11,  1026,  1027,  1028,   954,   998,  1004,  1025,  1046,   185,
     776,   777,   771,  1004,    10,    11,   765,   766,   767,   761,
    1030,   182,   122,   692,   694,   695,   196,   659,     8,  1046,
     189,   645,   646,   640,  1004,    10,    11,   634,   635,   636,
     630,  1030,   180,     6,     4,   224,    10,  1037,   225,   226,
    1036,  1043,  1044,    10,    11,   915,   916,   914,   960,   963,
     971,   986,   998,   185,   885,   886,   880,  1004,    10,    11,
     874,   875,   876,   870,  1030,   182,  1046,  1046,   202,  1029,
    1030,   189,   783,   784,   778,  1004,    10,    11,   772,   773,
     774,   768,  1030,   180,    10,    11,   697,   698,   696,   960,
     963,   971,   986,   998,   196,  1045,     6,   647,  1004,    10,
      11,   641,   642,   643,   637,  1030,   184,  1046,   224,     6,
    1046,  1046,   210,   189,   892,   893,   887,  1004,    10,    11,
     881,   882,   883,   877,  1030,   180,   218,   785,  1004,    10,
      11,   779,   780,   781,   775,  1030,   184,   172,     8,  1046,
      10,    11,   648,   649,   650,   644,  1030,   188,   229,     6,
       6,   894,  1004,    10,    11,   888,   889,   890,   884,  1030,
     184,    10,    11,   786,   787,   788,   782,  1030,   188,   651,
    1030,   186,  1046,  1046,    10,    11,   895,   896,   897,   891,
    1030,   188,   789,  1030,   186,   190,   898,  1030,   186,   190,
     190
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

  case 689:

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

  case 690:

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

  case 694:

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

  case 704:

    {
	parserData->numberOfOtherObjectiveOptions = 0; 
	osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 705:

    {	
	if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
}
    break;

  case 707:

    {	
	parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
}
    break;

  case 712:

    {
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        

}
    break;

  case 714:

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

  case 715:

    {
	parserData->numberOfObjAttributePresent = false;
}
    break;

  case 716:

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

  case 717:

    {	
		if (parserData->numberOfObj > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: expected at least one <obj> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 718:

    {
		if (parserData->kounter < parserData->numberOfObj)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: fewer <obj> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 725:

    {
	parserData->kounter++;
}
    break;

  case 726:

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

  case 730:

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

  case 731:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 732:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 736:

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

  case 737:

    {
	parserData->numberOfObjAttributePresent = false;
}
    break;

  case 738:

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

  case 739:

    {
		if (parserData->numberOfObj > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: expected at least one <obj> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 740:

    {
		if (parserData->kounter < parserData->numberOfObj)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 747:

    {
	parserData->kounter++;
}
    break;

  case 748:

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

  case 752:

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

  case 753:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 754:

    {
		if (parserData->lbValueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
	}
    break;

  case 755:

    {
		if (parserData->ubValueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
	}
    break;

  case 760:

    {
	osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
}
    break;

  case 767:

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

  case 768:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 769:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 776:

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

  case 777:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 778:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 785:

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

  case 786:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 787:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 794:

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

  case 795:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 796:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 803:

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

  case 804:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 805:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 812:

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

  case 813:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 814:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 821:

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

  case 822:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 823:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 831:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 832:

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
	parserData->descriptionAttributePresent = false;	
	parserData->descriptionAttribute = "";	
	parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_objectives;
}
    break;

  case 833:

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
					parserData->descriptionAttribute) )
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
	}
    break;

  case 836:

    {
		parserData->kounter = 0;
	}
    break;

  case 837:

    {
		parserData->kounter = 0;
	}
    break;

  case 853:

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

  case 854:

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

  case 858:

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

  case 868:

    {
	parserData->numberOfOtherConstraintOptions = 0; 
	osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 869:

    {	
	if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherConstraintOptions failed");
	parserData->iOther = 0;
}
    break;

  case 871:

    {	
	parserData->numberOfOtherConstraintOptions = parserData->tempInt;
}
    break;

  case 876:

    {
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        

}
    break;

  case 878:

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

  case 879:

    {
	parserData->numberOfConAttributePresent = false;
}
    break;

  case 880:

    {
	parserData->kounter = 0;
	parserData->idxArray = new         int[parserData->numberOfCon];
	parserData->namArray = new std::string[parserData->numberOfCon];
	parserData->valArray = new      double[parserData->numberOfCon];
	for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfCon; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 881:

    {
		if (parserData->numberOfCon > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: expected at least one <con element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 882:

    {
		if (parserData->kounter < parserData->numberOfCon)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: fewer <con> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 889:

    {
	parserData->kounter++;
}
    break;

  case 890:

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

  case 891:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 894:

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

  case 895:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 896:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 900:

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

  case 901:

    {
	parserData->numberOfConAttributePresent = false;
}
    break;

  case 902:

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

  case 903:

    {
		if (parserData->numberOfCon > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: expected at least one <con> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 904:

    {
		if (parserData->kounter < parserData->numberOfCon)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: fewer <con> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 911:

    {	
	parserData->kounter++;
}
    break;

  case 912:

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

  case 913:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 916:

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

  case 917:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 918:

    {
		parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
	}
    break;

  case 919:

    {
		parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
	}
    break;

  case 924:

    {
	osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
}
    break;

  case 931:

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

  case 932:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 933:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 940:

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

  case 941:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 942:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 949:

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

  case 950:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 951:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 958:

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

  case 959:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 960:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 967:

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

  case 968:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 969:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 976:

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

  case 977:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 978:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 985:

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

  case 986:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 987:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 995:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 996:

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
	parserData->descriptionAttributePresent = false;	
	parserData->descriptionAttribute = "";	
	parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_constraints;
}
    break;

  case 997:

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
					parserData->descriptionAttribute) )
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element could not be initialed"); 
	}
    break;

  case 1000:

    {
		parserData->kounter = 0;
	}
    break;

  case 1001:

    {
		parserData->kounter = 0;
	}
    break;

  case 1017:

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

  case 1018:

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

  case 1022:

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

  case 1031:

    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    }
    break;

  case 1033:

    {
	if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfSolverOptions failed");
	parserData->iOption = 0;
}
    break;

  case 1034:

    {
		if (parserData->numberOfSolverOptions > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <solverOption> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1035:

    {
		if (parserData->iOption != parserData->numberOfSolverOptions)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <solverOption> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1040:

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

  case 1041:

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

  case 1042:

    {
	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "name attribute must be present");
}
    break;

  case 1051:

    {
			parserData->itemList = new std::string[parserData->numberOfItems];
    }
    break;

  case 1052:

    {
		if (parserData->numberOfItems > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <item> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1053:

    {
		if (parserData->kounter < parserData->numberOfItems)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <item> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1060:

    {	
	parserData->itemList[parserData->kounter] = parserData->itemContent;
	parserData->kounter++;
}
    break;

  case 1061:

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

  case 1066:

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

  case 1069:

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

  case 1070:

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

  case 1071:

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

  case 1072:

    {
//	parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 1078:

    {
	if (parserData->pathPairFromPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"from\" attribute allowed");
	parserData->pathPairFromPresent = true;
	parserData->pathPairFrom = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1079:

    {
	if (parserData->pathPairToPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"to\" attribute allowed");
	parserData->pathPairToPresent = true;
	parserData->pathPairTo = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1080:

    {
	if (parserData->pathPairMakeCopyPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"makeCopy\" attribute allowed");
	parserData->pathPairMakeCopyPresent = true;
	parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1083:

    {   
	if (parserData->categoryAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one category attribute allowed for this element");
	parserData->categoryAttributePresent = true;
}
    break;

  case 1086:

    { 
	parserData->categoryAttribute = "";
}
    break;

  case 1087:

    { 
	parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1088:

    {
	if (parserData->descriptionAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one description attribute allowed for this element");
	parserData->descriptionAttributePresent = true;
}
    break;

  case 1091:

    { parserData->descriptionAttribute = ""; }
    break;

  case 1092:

    { 
	parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1093:

    {
	if (parserData->groupWeightAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one groupWeight attribute allowed for this element");
	parserData->groupWeightAttributePresent = true;
}
    break;

  case 1094:

    {
	parserData->groupWeight = parserData->tempVal;
}
    break;

  case 1095:

    {   
	if (parserData->idxAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one idx attribute allowed for this element");
	parserData->idxAttributePresent = true;
}
    break;

  case 1097:

    { 
	parserData->idxAttribute = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1098:

    {   
	if (parserData->lbValueAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
	parserData->lbValueAttributePresent = true;
}
    break;

  case 1101:

    { 
	parserData->lbValueAttribute = ""; 
}
    break;

  case 1102:

    { 
	parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1103:

    {   if (parserData->lbValueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
			parserData->lbValueAttributePresent = true;
		}
    break;

  case 1106:

    { 
    parserData->lbDualValue = 0.0; 
}
    break;

  case 1107:

    {
    parserData->lbDualValue = parserData->tempVal;
}
    break;

  case 1108:

    {
        if (parserData->nameAttributePresent ) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one name attribute allowed for this element");
		parserData->nameAttributePresent = true;
	}
    break;

  case 1111:

    { 
        parserData->nameAttribute = ""; 
    }
    break;

  case 1112:

    { 
	    parserData->nameAttribute = (yyvsp[(2) - (3)].sval); 
    	free((yyvsp[(2) - (3)].sval));
    }
    break;

  case 1113:

    {   if (parserData->solverAttributePresent ) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one solver attribute allowed for this element");
		parserData->solverAttributePresent = true;
	}
    break;

  case 1116:

    { parserData->solverAttribute = ""; }
    break;

  case 1117:

    { 
	parserData->solverAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1118:

    {   if (parserData->sosIdxAttributePresent ) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one sosIdx attribute allowed for this element");
		parserData->sosIdxAttributePresent = true;
	}
    break;

  case 1120:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index must be nonnegative");
	parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1121:

    {   if (parserData->typeAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		}
    break;

  case 1124:

    { parserData->typeAttribute = ""; }
    break;

  case 1125:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1126:

    {
   if (parserData->ubValueAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
	parserData->ubValueAttributePresent = true;
}
    break;

  case 1129:

    { 
	parserData->ubValueAttribute = ""; 
}
    break;

  case 1130:

    { 
	parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1131:

    {   if (parserData->ubValueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
			parserData->ubValueAttributePresent = true;
		}
    break;

  case 1134:

    { parserData->ubDualValue = 0.0; }
    break;

  case 1135:

    { 
	parserData->ubDualValue = parserData->tempVal;
}
    break;

  case 1136:

    {   if (parserData->unitAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		}
    break;

  case 1139:

    { parserData->unitAttribute = ""; }
    break;

  case 1140:

    { 
	parserData->unitAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1141:

    {   if (parserData->valueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		}
    break;

  case 1144:

    { parserData->valueAttribute = ""; }
    break;

  case 1145:

    {
	parserData->valueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1146:

    {
	if (parserData->numberOfConAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfConAttributePresent = true;		
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1147:

    {
	if (parserData->numberOfConstraintsPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of constraints cannot be negative");
	parserData->numberOfConstraintsPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1148:

    {
	if (osglData->osglNumberOfElPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEl attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <el> cannot be negative");
	osglData->osglNumberOfElPresent = true;
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1149:

    {
	if (parserData->numberOfEnumerationsAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEnumerations attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerationsAttributePresent = true;		
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1150:

    {	
   if (parserData->numberOfItemsPresent ) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1151:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
    	parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
}
    break;

  case 1152:

    {
	if (parserData->numberOfObjAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObjAttributePresent = true;		
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1153:

    {
	if (parserData->numberOfObjectivesPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of objectives cannot be negative");
	parserData->numberOfObjectivesPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1154:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other constraint options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1155:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other objective options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1156:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1157:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other variable options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1158:

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

  case 1159:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of paths cannot be negative");
	else
		parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
}
    break;

  case 1160:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
    	parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
}
    break;

  case 1161:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of solver options cannot be negative");
	parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1162:

    {
	if (parserData->numberOfVarAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVarAttributePresent = true;		
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1163:

    {	if (parserData->numberOfVariablesPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of variables cannot be negative");
	parserData->numberOfVariablesPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1166:

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

  case 1167:

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

  case 1168:

    {
		if(!osglData->osglNumberOfElPresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires numberOfEl attribute"); 
		if(!parserData->valueAttributePresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires value attribute"); 
	}
    break;

  case 1171:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfElPresent = true;
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 1179:

    {
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer data elements than specified");
			ignoreDataAfterErrors = true;
		}
	}
    break;

  case 1184:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
}
    break;

  case 1190:

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

  case 1192:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1197:

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

  case 1198:

    {	
	if (osglData->osglIncrPresent) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1199:

    {	
	if (osglData->osglMultPresent) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1200:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1201:

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


