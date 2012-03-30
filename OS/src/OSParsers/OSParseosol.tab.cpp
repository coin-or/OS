
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
     SUPERBASICSTART = 438,
     SUPERBASICEND = 439,
     ISFREESTART = 440,
     ISFREEEND = 441,
     UNKNOWNSTART = 442,
     UNKNOWNEND = 443,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 444,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 445,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 446,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 447,
     SOSSTART = 448,
     SOSEND = 449,
     OBJECTIVESSTART = 450,
     OBJECTIVESEND = 451,
     INITIALOBJECTIVEVALUESSTART = 452,
     INITIALOBJECTIVEVALUESEND = 453,
     OBJSTART = 454,
     OBJEND = 455,
     INITIALOBJECTIVEBOUNDSSTART = 456,
     INITIALOBJECTIVEBOUNDSEND = 457,
     CONSTRAINTSSTART = 458,
     CONSTRAINTSEND = 459,
     INITIALCONSTRAINTVALUESSTART = 460,
     INITIALCONSTRAINTVALUESEND = 461,
     CONSTART = 462,
     CONEND = 463,
     INITIALDUALVALUESSTART = 464,
     INITIALDUALVALUESEND = 465,
     SOLVEROPTIONSSTART = 466,
     SOLVEROPTIONSEND = 467,
     SOLVEROPTIONSTART = 468,
     SOLVEROPTIONEND = 469,
     ENUMERATIONSTART = 470,
     ENUMERATIONEND = 471,
     ITEMEMPTY = 472,
     ITEMSTART = 473,
     ITEMEND = 474,
     ITEMSTARTANDEND = 475,
     BASE64START = 476,
     BASE64END = 477,
     INCRATT = 478,
     MULTATT = 479,
     SIZEOFATT = 480,
     ELSTART = 481,
     ELEND = 482,
     DUMMY = 483
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
#define SUPERBASICSTART 438
#define SUPERBASICEND 439
#define ISFREESTART 440
#define ISFREEEND 441
#define UNKNOWNSTART 442
#define UNKNOWNEND 443
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 444
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 445
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 446
#define SOSVARIABLEBRANCHINGWEIGHTSEND 447
#define SOSSTART 448
#define SOSEND 449
#define OBJECTIVESSTART 450
#define OBJECTIVESEND 451
#define INITIALOBJECTIVEVALUESSTART 452
#define INITIALOBJECTIVEVALUESEND 453
#define OBJSTART 454
#define OBJEND 455
#define INITIALOBJECTIVEBOUNDSSTART 456
#define INITIALOBJECTIVEBOUNDSEND 457
#define CONSTRAINTSSTART 458
#define CONSTRAINTSEND 459
#define INITIALCONSTRAINTVALUESSTART 460
#define INITIALCONSTRAINTVALUESEND 461
#define CONSTART 462
#define CONEND 463
#define INITIALDUALVALUESSTART 464
#define INITIALDUALVALUESEND 465
#define SOLVEROPTIONSSTART 466
#define SOLVEROPTIONSEND 467
#define SOLVEROPTIONSTART 468
#define SOLVEROPTIONEND 469
#define ENUMERATIONSTART 470
#define ENUMERATIONEND 471
#define ITEMEMPTY 472
#define ITEMSTART 473
#define ITEMEND 474
#define ITEMSTARTANDEND 475
#define BASE64START 476
#define BASE64END 477
#define INCRATT 478
#define MULTATT 479
#define SIZEOFATT 480
#define ELSTART 481
#define ELEND 482
#define DUMMY 483




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
#define YYLAST   1231

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  793
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1181
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1622

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   483

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   230,
     232,     2,     2,   231,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   229,     2,     2,     2,     2,     2,     2,     2,
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
     225,   226,   227,   228
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
    1346,  1348,  1350,  1352,  1354,  1358,  1365,  1366,  1370,  1372,
    1374,  1376,  1378,  1380,  1384,  1386,  1387,  1391,  1393,  1395,
    1397,  1399,  1401,  1405,  1407,  1408,  1412,  1414,  1416,  1418,
    1420,  1422,  1426,  1428,  1429,  1433,  1435,  1437,  1439,  1441,
    1443,  1447,  1449,  1450,  1454,  1456,  1458,  1460,  1462,  1464,
    1468,  1470,  1471,  1475,  1477,  1479,  1481,  1483,  1485,  1489,
    1491,  1492,  1496,  1498,  1500,  1502,  1504,  1507,  1509,  1513,
    1515,  1517,  1520,  1524,  1526,  1528,  1529,  1532,  1534,  1536,
    1538,  1541,  1543,  1544,  1548,  1550,  1555,  1557,  1559,  1562,
    1564,  1568,  1570,  1573,  1577,  1579,  1581,  1582,  1585,  1587,
    1589,  1591,  1593,  1595,  1598,  1600,  1604,  1605,  1608,  1612,
    1614,  1616,  1617,  1620,  1622,  1624,  1626,  1628,  1630,  1632,
    1634,  1636,  1638,  1640,  1643,  1645,  1649,  1651,  1653,  1655,
    1658,  1662,  1664,  1666,  1667,  1670,  1672,  1674,  1676,  1678,
    1680,  1682,  1685,  1687,  1688,  1692,  1694,  1696,  1697,  1699,
    1701,  1703,  1705,  1709,  1714,  1715,  1719,  1721,  1723,  1725,
    1727,  1730,  1732,  1736,  1738,  1740,  1743,  1747,  1749,  1751,
    1752,  1755,  1757,  1759,  1761,  1764,  1766,  1767,  1771,  1773,
    1775,  1777,  1779,  1782,  1784,  1788,  1790,  1792,  1795,  1799,
    1801,  1803,  1804,  1807,  1809,  1811,  1813,  1815,  1818,  1820,
    1821,  1824,  1826,  1828,  1830,  1832,  1836,  1843,  1844,  1848,
    1850,  1852,  1854,  1856,  1858,  1862,  1864,  1865,  1869,  1871,
    1873,  1875,  1877,  1879,  1883,  1885,  1886,  1890,  1892,  1894,
    1896,  1898,  1900,  1904,  1906,  1907,  1911,  1913,  1915,  1917,
    1919,  1921,  1925,  1927,  1928,  1932,  1934,  1936,  1938,  1940,
    1942,  1946,  1948,  1949,  1953,  1955,  1957,  1959,  1961,  1963,
    1967,  1969,  1970,  1973,  1977,  1979,  1981,  1982,  1985,  1987,
    1989,  1991,  1993,  1995,  1997,  1999,  2001,  2003,  2005,  2008,
    2010,  2014,  2016,  2018,  2020,  2023,  2027,  2029,  2031,  2032,
    2035,  2037,  2039,  2041,  2043,  2045,  2047,  2050,  2052,  2053,
    2057,  2059,  2061,  2062,  2064,  2066,  2068,  2070,  2074,  2079,
    2080,  2084,  2086,  2088,  2090,  2092,  2095,  2097,  2101,  2103,
    2105,  2108,  2112,  2114,  2116,  2117,  2120,  2122,  2124,  2126,
    2129,  2131,  2132,  2136,  2138,  2140,  2142,  2144,  2147,  2149,
    2153,  2155,  2157,  2160,  2164,  2166,  2168,  2169,  2172,  2174,
    2176,  2178,  2180,  2183,  2185,  2186,  2189,  2191,  2193,  2195,
    2197,  2201,  2208,  2209,  2213,  2215,  2217,  2219,  2221,  2223,
    2227,  2229,  2230,  2234,  2236,  2238,  2240,  2242,  2244,  2248,
    2250,  2251,  2255,  2257,  2259,  2261,  2263,  2265,  2269,  2271,
    2272,  2276,  2278,  2280,  2282,  2284,  2286,  2290,  2292,  2293,
    2297,  2299,  2301,  2303,  2305,  2307,  2311,  2313,  2314,  2318,
    2320,  2322,  2324,  2326,  2328,  2332,  2334,  2335,  2338,  2342,
    2344,  2346,  2347,  2350,  2352,  2354,  2356,  2358,  2360,  2362,
    2364,  2366,  2368,  2370,  2373,  2375,  2379,  2381,  2383,  2385,
    2388,  2392,  2394,  2396,  2397,  2400,  2402,  2404,  2406,  2408,
    2410,  2412,  2415,  2417,  2418,  2422,  2424,  2426,  2428,  2430,
    2432,  2436,  2437,  2440,  2444,  2446,  2448,  2450,  2453,  2455,
    2457,  2459,  2461,  2463,  2465,  2467,  2469,  2471,  2474,  2476,
    2480,  2482,  2484,  2487,  2489,  2491,  2493,  2495,  2497,  2501,
    2503,  2505,  2508,  2513,  2517,  2519,  2521,  2522,  2525,  2527,
    2529,  2531,  2535,  2539,  2543,  2546,  2548,  2550,  2552,  2554,
    2556,  2560,  2562,  2564,  2566,  2568,  2572,  2574,  2579,  2581,
    2583,  2588,  2590,  2592,  2594,  2596,  2600,  2602,  2604,  2606,
    2608,  2613,  2615,  2617,  2619,  2621,  2625,  2627,  2629,  2631,
    2633,  2637,  2639,  2641,  2646,  2648,  2650,  2652,  2654,  2658,
    2660,  2662,  2664,  2666,  2670,  2672,  2674,  2676,  2678,  2683,
    2685,  2687,  2689,  2691,  2695,  2697,  2699,  2701,  2703,  2707,
    2712,  2717,  2722,  2727,  2732,  2737,  2742,  2747,  2752,  2757,
    2762,  2767,  2772,  2777,  2782,  2787,  2792,  2797,  2799,  2802,
    2806,  2808,  2810,  2811,  2814,  2816,  2818,  2820,  2822,  2824,
    2826,  2830,  2832,  2834,  2836,  2837,  2840,  2844,  2846,  2848,
    2849,  2852,  2854,  2856,  2860,  2864,  2869,  2871,  2873,  2876,
    2878,  2882,  2887,  2892,  2894,  2896,  2899,  2900,  2903,  2905,
    2907,  2909
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     234,     0,    -1,   235,   243,   241,    -1,   236,   237,   238,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   239,    -1,
     240,    -1,    11,    -1,    10,   243,   241,    -1,   242,    -1,
      15,    -1,    -1,   244,   272,   358,   406,   434,   550,    -1,
      -1,   245,   246,    -1,    67,    -1,   247,    -1,   248,    -1,
      10,    68,    -1,    11,    -1,    10,   249,    68,    -1,   250,
      -1,   251,    -1,   250,   251,    -1,   252,    -1,   256,    -1,
     260,    -1,   264,    -1,   268,    -1,   253,    -1,   254,    -1,
     255,    -1,    82,    -1,    81,    -1,    79,     5,    80,    -1,
     257,    -1,   258,    -1,   259,    -1,    86,    -1,    85,    -1,
      83,     5,    84,    -1,   261,    -1,   262,    -1,   263,    -1,
      90,    -1,    89,    -1,    87,     5,    88,    -1,   265,    -1,
     266,    -1,   267,    -1,    94,    -1,    93,    -1,    91,     5,
      92,    -1,   269,    -1,   270,    -1,   271,    -1,    98,    -1,
      97,    -1,    95,     5,    96,    -1,    -1,   273,   274,    -1,
      69,    -1,   275,    -1,   276,    -1,    10,    70,    -1,    11,
      -1,    10,   277,    70,    -1,   278,    -1,   279,    -1,   278,
     279,    -1,   280,    -1,   286,    -1,   292,    -1,   298,    -1,
     306,    -1,   312,    -1,   318,    -1,   324,    -1,   330,    -1,
     336,    -1,   344,    -1,   281,   282,    -1,    99,    -1,   283,
      -1,   284,    -1,    10,   100,    -1,    11,    -1,    10,   285,
     100,    -1,     4,    -1,   287,   288,    -1,   101,    -1,   289,
      -1,   290,    -1,    10,   102,    -1,    11,    -1,    10,   291,
     102,    -1,     4,    -1,   293,   294,    -1,   103,    -1,   295,
      -1,   296,    -1,    10,   104,    -1,    11,    -1,    10,   297,
     104,    -1,     4,    -1,   299,   300,   302,    -1,   105,    -1,
      -1,   301,    -1,    66,     3,     8,    -1,   303,    -1,   304,
      -1,    10,   106,    -1,    11,    -1,    10,   305,   106,    -1,
       4,    -1,   307,   308,    -1,   107,    -1,   309,    -1,   310,
      -1,    10,   108,    -1,    11,    -1,    10,   311,   108,    -1,
       4,    -1,   313,   314,    -1,   109,    -1,   315,    -1,   316,
      -1,    10,   110,    -1,    11,    -1,    10,   317,   110,    -1,
       4,    -1,   319,   320,    -1,   111,    -1,   321,    -1,   322,
      -1,    10,   112,    -1,    11,    -1,    10,   323,   112,    -1,
       4,    -1,   325,   326,    -1,   113,    -1,   327,    -1,   328,
      -1,    10,   114,    -1,    11,    -1,    10,   329,   114,    -1,
       4,    -1,   331,   332,    -1,   115,    -1,   333,    -1,   334,
      -1,    10,   116,    -1,    11,    -1,    10,   335,   116,    -1,
       4,    -1,   337,   338,   340,    -1,   117,    -1,    -1,   339,
      -1,    65,     3,     8,    -1,   341,    -1,   342,    -1,    10,
     118,    -1,    11,    -1,    10,   343,   118,    -1,     4,    -1,
     345,   346,   347,    -1,   119,    -1,   989,    -1,   348,    -1,
     349,    -1,    10,   120,    -1,    11,    -1,    10,   350,   120,
      -1,   351,    -1,   352,    -1,   351,   352,    -1,   353,   354,
     357,    -1,   121,    -1,   355,    -1,    -1,   355,   356,    -1,
     948,    -1,   975,    -1,   931,    -1,    10,   122,    -1,    11,
      -1,    -1,   359,   360,    -1,    71,    -1,   361,    -1,   362,
      -1,    10,    72,    -1,    11,    -1,    10,   363,    72,    -1,
     364,    -1,   365,    -1,   364,   365,    -1,   366,    -1,   373,
      -1,   380,    -1,   387,    -1,   392,    -1,   367,   368,   371,
      -1,   123,    -1,   369,    -1,    -1,   369,   370,    -1,   971,
      -1,   931,    -1,    10,   372,   124,    -1,  1022,    -1,   374,
     375,   378,    -1,   125,    -1,   376,    -1,    -1,   376,   377,
      -1,   971,    -1,   931,    -1,    10,   379,   126,    -1,  1022,
      -1,   381,   382,   385,    -1,   127,    -1,   383,    -1,    -1,
     383,   384,    -1,   971,    -1,   931,    -1,    10,   386,   128,
      -1,  1022,    -1,   388,   389,   390,    -1,   129,    -1,    -1,
     931,    -1,    10,   391,   130,    -1,     6,    -1,   393,   394,
     395,    -1,   119,    -1,   989,    -1,   396,    -1,   397,    -1,
      10,   120,    -1,    11,    -1,    10,   398,   120,    -1,   399,
      -1,   400,    -1,   399,   400,    -1,   401,   402,   405,    -1,
     121,    -1,   403,    -1,    -1,   403,   404,    -1,   948,    -1,
     975,    -1,   931,    -1,    10,   122,    -1,    11,    -1,    -1,
     407,   408,    -1,    73,    -1,   409,    -1,   410,    -1,    10,
      74,    -1,    11,    -1,    10,   411,    74,    -1,   412,    -1,
     413,    -1,   412,   413,    -1,   414,    -1,   420,    -1,   415,
     416,    -1,   131,    -1,   417,    -1,   418,    -1,    10,   132,
      -1,    11,    -1,    10,   419,   132,    -1,     4,    -1,   421,
     422,   423,    -1,   119,    -1,   989,    -1,   424,    -1,   425,
      -1,    10,   120,    -1,    11,    -1,    10,   426,   120,    -1,
     427,    -1,   428,    -1,   427,   428,    -1,   429,   430,   433,
      -1,   121,    -1,   431,    -1,    -1,   431,   432,    -1,   948,
      -1,   975,    -1,   931,    -1,    10,   122,    -1,    11,    -1,
      -1,   435,   436,    -1,    75,    -1,   437,    -1,   438,    -1,
      10,    76,    -1,    11,    -1,    10,   439,    76,    -1,   440,
      -1,   441,    -1,   440,   441,    -1,   442,    -1,   450,    -1,
     456,    -1,   464,    -1,   469,    -1,   474,    -1,   479,    -1,
     484,    -1,   492,    -1,   508,    -1,   500,    -1,   516,    -1,
     522,    -1,   528,    -1,   536,    -1,   443,   444,   445,    -1,
     133,    -1,    -1,   971,    -1,   446,    -1,   447,    -1,    10,
     134,    -1,    11,    -1,    10,   448,   134,    -1,   449,    -1,
    1022,    -1,   451,   452,    -1,   135,    -1,   453,    -1,   454,
      -1,    10,   136,    -1,    11,    -1,    10,   455,   136,    -1,
       4,    -1,   457,   458,   459,    -1,   137,    -1,   984,    -1,
     460,    -1,   461,    -1,    10,   138,    -1,    11,    -1,    10,
     462,   138,    -1,   463,    -1,   462,   463,    -1,   107,    10,
       4,   108,    -1,   465,   992,   466,    -1,   139,    -1,   467,
      -1,   468,    -1,    10,   140,    -1,    11,    -1,    10,   916,
     140,    -1,   470,   992,   471,    -1,   141,    -1,   472,    -1,
     473,    -1,    10,   142,    -1,    11,    -1,    10,   916,   142,
      -1,   475,   992,   476,    -1,   147,    -1,   477,    -1,   478,
      -1,    10,   148,    -1,    11,    -1,    10,   916,   148,    -1,
     480,   992,   481,    -1,   149,    -1,   482,    -1,   483,    -1,
      10,   150,    -1,    11,    -1,    10,   916,   150,    -1,   485,
     486,   487,    -1,   155,    -1,   991,    -1,   488,    -1,   489,
      -1,    10,   156,    -1,    11,    -1,    10,   490,   156,    -1,
     491,    -1,   490,   491,    -1,   918,    -1,   493,   494,   495,
      -1,   157,    -1,   991,    -1,   496,    -1,   497,    -1,    10,
     158,    -1,    11,    -1,    10,   498,   158,    -1,   499,    -1,
     498,   499,    -1,   918,    -1,   501,   502,   503,    -1,   161,
      -1,   991,    -1,   504,    -1,   505,    -1,    10,   162,    -1,
      11,    -1,    10,   506,   162,    -1,   507,    -1,   506,   507,
      -1,   918,    -1,   509,   510,   511,    -1,   159,    -1,   991,
      -1,   512,    -1,   513,    -1,    10,   160,    -1,    11,    -1,
      10,   514,   160,    -1,   515,    -1,   514,   515,    -1,   918,
      -1,   517,   518,   519,    -1,   153,    -1,   992,    -1,   520,
      -1,   521,    -1,    10,   154,    -1,    11,    -1,    10,   916,
     154,    -1,   523,   524,   525,    -1,   151,    -1,   992,    -1,
     526,    -1,   527,    -1,    10,   152,    -1,    11,    -1,    10,
     916,   152,    -1,   529,   530,   531,    -1,   163,    -1,   993,
      -1,   532,    -1,   533,    -1,    10,   164,    -1,    11,    -1,
      10,   534,   164,    -1,   535,    -1,   534,   535,    -1,   165,
      10,     4,   166,    -1,   537,   538,   539,    -1,   119,    -1,
     989,    -1,   540,    -1,   541,    -1,    10,   120,    -1,    11,
      -1,    10,   542,   120,    -1,   543,    -1,   544,    -1,   543,
     544,    -1,   545,   546,   549,    -1,   121,    -1,   547,    -1,
      -1,   547,   548,    -1,   948,    -1,   975,    -1,   931,    -1,
      10,   122,    -1,    11,    -1,    -1,   551,   552,   555,    -1,
      77,    -1,   553,    -1,    -1,   553,   554,    -1,   996,    -1,
     980,    -1,   986,    -1,   556,    -1,   557,    -1,    11,    -1,
      10,   558,    78,    -1,   559,   690,   792,   894,    -1,    -1,
     560,   561,   563,    -1,   167,    -1,   562,    -1,    -1,   990,
      -1,   564,    -1,   565,    -1,    11,    -1,    10,   566,   168,
      -1,   567,   581,   595,   643,   657,   672,    -1,    -1,   568,
     569,   570,    -1,   169,    -1,   995,    -1,   571,    -1,   572,
      -1,    10,   170,    -1,    11,    -1,    10,   573,   170,    -1,
     574,    -1,   575,    -1,   574,   575,    -1,   576,   577,   580,
      -1,   171,    -1,   578,    -1,    -1,   578,   579,    -1,   937,
      -1,   948,    -1,   975,    -1,    10,   172,    -1,    11,    -1,
      -1,   582,   583,   584,    -1,   173,    -1,   995,    -1,   585,
      -1,   586,    -1,    10,   174,    -1,    11,    -1,    10,   587,
     174,    -1,   588,    -1,   589,    -1,   588,   589,    -1,   590,
     591,   594,    -1,   171,    -1,   592,    -1,    -1,   592,   593,
      -1,   937,    -1,   948,    -1,   975,    -1,    10,   172,    -1,
      11,    -1,    -1,   596,   597,    -1,   175,    -1,   598,    -1,
     599,    -1,    11,    -1,    10,   600,   176,    -1,   601,   608,
     615,   622,   629,   636,    -1,    -1,   602,   603,   604,    -1,
     177,    -1,   981,    -1,   605,    -1,   606,    -1,    11,    -1,
      10,   607,   178,    -1,  1007,    -1,    -1,   609,   610,   611,
      -1,   181,    -1,   981,    -1,   612,    -1,   613,    -1,    11,
      -1,    10,   614,   182,    -1,  1007,    -1,    -1,   616,   617,
     618,    -1,   179,    -1,   981,    -1,   619,    -1,   620,    -1,
      11,    -1,    10,   621,   180,    -1,  1007,    -1,    -1,   623,
     624,   625,    -1,   185,    -1,   981,    -1,   626,    -1,   627,
      -1,    11,    -1,    10,   628,   186,    -1,  1007,    -1,    -1,
     630,   631,   632,    -1,   183,    -1,   981,    -1,   633,    -1,
     634,    -1,    11,    -1,    10,   635,   184,    -1,  1007,    -1,
      -1,   637,   638,   639,    -1,   187,    -1,   981,    -1,   640,
      -1,   641,    -1,    11,    -1,    10,   642,   188,    -1,  1007,
      -1,    -1,   644,   645,   646,    -1,   189,    -1,   995,    -1,
     647,    -1,   648,    -1,    10,   190,    -1,    11,    -1,    10,
     649,   190,    -1,   650,    -1,   651,    -1,   650,   651,    -1,
     652,   653,   656,    -1,   171,    -1,   654,    -1,    -1,   654,
     655,    -1,   937,    -1,   948,    -1,   975,    -1,    10,   172,
      -1,    11,    -1,    -1,   658,   659,   660,    -1,   191,    -1,
      29,     8,     6,     8,    -1,   661,    -1,   662,    -1,    10,
     192,    -1,    11,    -1,    10,   663,   192,    -1,   664,    -1,
     663,   664,    -1,   665,   666,   669,    -1,   193,    -1,   667,
      -1,    -1,   667,   668,    -1,   956,    -1,   995,    -1,   935,
      -1,   670,    -1,   671,    -1,    10,   194,    -1,    11,    -1,
      10,   650,   194,    -1,    -1,   672,   673,    -1,   674,   675,
     678,    -1,   121,    -1,   676,    -1,    -1,   676,   677,    -1,
     995,    -1,   982,    -1,   948,    -1,   975,    -1,   952,    -1,
     927,    -1,   959,    -1,   931,    -1,   679,    -1,   680,    -1,
      10,   122,    -1,    11,    -1,    10,   681,   122,    -1,   682,
      -1,   997,    -1,   683,    -1,   682,   683,    -1,   684,   685,
     688,    -1,   171,    -1,   686,    -1,    -1,   686,   687,    -1,
     937,    -1,   948,    -1,   975,    -1,   940,    -1,   963,    -1,
     689,    -1,    10,   172,    -1,    11,    -1,    -1,   691,   692,
     694,    -1,   195,    -1,   693,    -1,    -1,   988,    -1,   695,
      -1,   696,    -1,    11,    -1,    10,   697,   196,    -1,   698,
     712,   726,   774,    -1,    -1,   699,   700,   701,    -1,   197,
      -1,   985,    -1,   702,    -1,   703,    -1,    10,   198,    -1,
      11,    -1,    10,   704,   198,    -1,   705,    -1,   706,    -1,
     705,   706,    -1,   707,   708,   711,    -1,   199,    -1,   709,
      -1,    -1,   709,   710,    -1,   937,    -1,   948,    -1,   975,
      -1,    10,   200,    -1,    11,    -1,    -1,   713,   714,   715,
      -1,   201,    -1,   985,    -1,   716,    -1,   717,    -1,    10,
     202,    -1,    11,    -1,    10,   718,   202,    -1,   719,    -1,
     720,    -1,   719,   720,    -1,   721,   722,   725,    -1,   199,
      -1,   723,    -1,    -1,   723,   724,    -1,   937,    -1,   948,
      -1,   940,    -1,   963,    -1,    10,   200,    -1,    11,    -1,
      -1,   727,   728,    -1,   175,    -1,   729,    -1,   730,    -1,
      11,    -1,    10,   731,   176,    -1,   732,   739,   746,   753,
     760,   767,    -1,    -1,   733,   734,   735,    -1,   177,    -1,
     981,    -1,   736,    -1,   737,    -1,    11,    -1,    10,   738,
     178,    -1,  1007,    -1,    -1,   740,   741,   742,    -1,   181,
      -1,   981,    -1,   743,    -1,   744,    -1,    11,    -1,    10,
     745,   182,    -1,  1007,    -1,    -1,   747,   748,   749,    -1,
     179,    -1,   981,    -1,   750,    -1,   751,    -1,    11,    -1,
      10,   752,   180,    -1,  1007,    -1,    -1,   754,   755,   756,
      -1,   185,    -1,   981,    -1,   757,    -1,   758,    -1,    11,
      -1,    10,   759,   186,    -1,  1007,    -1,    -1,   761,   762,
     763,    -1,   183,    -1,   981,    -1,   764,    -1,   765,    -1,
      11,    -1,    10,   766,   184,    -1,  1007,    -1,    -1,   768,
     769,   770,    -1,   187,    -1,   981,    -1,   771,    -1,   772,
      -1,    11,    -1,    10,   773,   188,    -1,  1007,    -1,    -1,
     774,   775,    -1,   776,   777,   780,    -1,   121,    -1,   778,
      -1,    -1,   778,   779,    -1,   985,    -1,   982,    -1,   948,
      -1,   975,    -1,   952,    -1,   927,    -1,   959,    -1,   931,
      -1,   781,    -1,   782,    -1,    10,   122,    -1,    11,    -1,
      10,   783,   122,    -1,   784,    -1,   997,    -1,   785,    -1,
     784,   785,    -1,   786,   787,   790,    -1,   199,    -1,   788,
      -1,    -1,   788,   789,    -1,   937,    -1,   948,    -1,   975,
      -1,   940,    -1,   963,    -1,   791,    -1,    10,   200,    -1,
      11,    -1,    -1,   793,   794,   796,    -1,   203,    -1,   795,
      -1,    -1,   987,    -1,   797,    -1,   798,    -1,    11,    -1,
      10,   799,   204,    -1,   800,   814,   828,   876,    -1,    -1,
     801,   802,   803,    -1,   205,    -1,   979,    -1,   804,    -1,
     805,    -1,    10,   206,    -1,    11,    -1,    10,   806,   206,
      -1,   807,    -1,   808,    -1,   807,   808,    -1,   809,   810,
     813,    -1,   207,    -1,   811,    -1,    -1,   811,   812,    -1,
     937,    -1,   948,    -1,   975,    -1,    10,   208,    -1,    11,
      -1,    -1,   815,   816,   817,    -1,   209,    -1,   979,    -1,
     818,    -1,   819,    -1,    10,   210,    -1,    11,    -1,    10,
     820,   210,    -1,   821,    -1,   822,    -1,   821,   822,    -1,
     823,   824,   827,    -1,   207,    -1,   825,    -1,    -1,   825,
     826,    -1,   937,    -1,   948,    -1,   944,    -1,   967,    -1,
      10,   208,    -1,    11,    -1,    -1,   829,   830,    -1,   175,
      -1,   831,    -1,   832,    -1,    11,    -1,    10,   833,   176,
      -1,   834,   841,   848,   855,   862,   869,    -1,    -1,   835,
     836,   837,    -1,   177,    -1,   981,    -1,   838,    -1,   839,
      -1,    11,    -1,    10,   840,   178,    -1,  1007,    -1,    -1,
     842,   843,   844,    -1,   181,    -1,   981,    -1,   845,    -1,
     846,    -1,    11,    -1,    10,   847,   182,    -1,  1007,    -1,
      -1,   849,   850,   851,    -1,   179,    -1,   981,    -1,   852,
      -1,   853,    -1,    11,    -1,    10,   854,   180,    -1,  1007,
      -1,    -1,   856,   857,   858,    -1,   185,    -1,   981,    -1,
     859,    -1,   860,    -1,    11,    -1,    10,   861,   186,    -1,
    1007,    -1,    -1,   863,   864,   865,    -1,   183,    -1,   981,
      -1,   866,    -1,   867,    -1,    11,    -1,    10,   868,   184,
      -1,  1007,    -1,    -1,   870,   871,   872,    -1,   187,    -1,
     981,    -1,   873,    -1,   874,    -1,    11,    -1,    10,   875,
     188,    -1,  1007,    -1,    -1,   876,   877,    -1,   878,   879,
     882,    -1,   121,    -1,   880,    -1,    -1,   880,   881,    -1,
     979,    -1,   982,    -1,   948,    -1,   975,    -1,   952,    -1,
     927,    -1,   959,    -1,   931,    -1,   883,    -1,   884,    -1,
      10,   122,    -1,    11,    -1,    10,   885,   122,    -1,   886,
      -1,   997,    -1,   887,    -1,   886,   887,    -1,   888,   889,
     892,    -1,   207,    -1,   890,    -1,    -1,   890,   891,    -1,
     937,    -1,   948,    -1,   975,    -1,   940,    -1,   963,    -1,
     893,    -1,    10,   208,    -1,    11,    -1,    -1,   895,   896,
     897,    -1,   211,    -1,   994,    -1,   898,    -1,   899,    -1,
      11,    -1,    10,   900,   212,    -1,    -1,   900,   901,    -1,
     902,   903,   906,    -1,   213,    -1,   904,    -1,   905,    -1,
     904,   905,    -1,   948,    -1,   975,    -1,   952,    -1,   927,
      -1,   959,    -1,   931,    -1,   983,    -1,   907,    -1,   908,
      -1,    10,   214,    -1,    11,    -1,    10,   909,   214,    -1,
     910,    -1,   911,    -1,   910,   911,    -1,   912,    -1,   913,
      -1,   914,    -1,   220,    -1,   217,    -1,   218,   915,   219,
      -1,     5,    -1,   917,    -1,   916,   917,    -1,   143,    10,
       4,   144,    -1,   919,   920,   926,    -1,   145,    -1,   921,
      -1,    -1,   921,   922,    -1,   923,    -1,   924,    -1,   925,
      -1,    21,     3,     8,    -1,    22,     3,     8,    -1,    23,
       3,     8,    -1,    10,   146,    -1,    11,    -1,   928,    -1,
     929,    -1,   930,    -1,    49,    -1,    24,     3,  1023,    -1,
     932,    -1,   933,    -1,   934,    -1,    50,    -1,    46,     3,
    1023,    -1,   936,    -1,    26,     8,  1022,     8,    -1,   938,
      -1,   939,    -1,    42,  1023,     6,  1023,    -1,   941,    -1,
     942,    -1,   943,    -1,    53,    -1,    55,     3,  1023,    -1,
     945,    -1,   946,    -1,   947,    -1,    57,    -1,    59,  1023,
    1022,  1023,    -1,   949,    -1,   950,    -1,   951,    -1,    48,
      -1,    41,     3,  1023,    -1,   953,    -1,   954,    -1,   955,
      -1,    62,    -1,    61,     3,  1023,    -1,   957,    -1,   958,
      -1,    43,  1023,     6,  1023,    -1,   960,    -1,   961,    -1,
     962,    -1,    47,    -1,    25,     3,     8,    -1,   964,    -1,
     965,    -1,   966,    -1,    54,    -1,    56,     3,  1023,    -1,
     968,    -1,   969,    -1,   970,    -1,    58,    -1,    60,  1023,
    1022,  1023,    -1,   972,    -1,   973,    -1,   974,    -1,    51,
      -1,    45,     3,     8,    -1,   976,    -1,   977,    -1,   978,
      -1,    52,    -1,    44,     3,     8,    -1,    39,  1023,     6,
    1023,    -1,    32,  1023,     6,  1023,    -1,    40,  1023,     6,
    1023,    -1,    17,  1023,     6,  1023,    -1,    36,  1023,     6,
    1023,    -1,    18,     8,     6,     8,    -1,    38,  1023,     6,
    1023,    -1,    31,  1023,     6,  1023,    -1,    35,  1023,     6,
    1023,    -1,    34,  1023,     6,  1023,    -1,    16,  1023,     6,
    1023,    -1,    33,  1023,     6,  1023,    -1,    20,     8,     6,
       8,    -1,    19,     8,     6,     8,    -1,    27,     8,     6,
       8,    -1,    28,  1023,     6,  1023,    -1,    37,  1023,     6,
    1023,    -1,    30,  1023,     6,  1023,    -1,   998,    -1,   997,
     998,    -1,   999,  1000,  1003,    -1,   215,    -1,  1001,    -1,
      -1,  1001,  1002,    -1,   981,    -1,   975,    -1,   931,    -1,
    1004,    -1,  1005,    -1,    11,    -1,    10,  1006,   216,    -1,
    1007,    -1,  1008,    -1,  1015,    -1,    -1,  1008,  1009,    -1,
    1010,  1011,  1014,    -1,   226,    -1,  1012,    -1,    -1,  1012,
    1013,    -1,  1021,    -1,  1020,    -1,    10,     6,   227,    -1,
     221,  1016,  1017,    -1,   225,  1023,     6,  1023,    -1,  1018,
      -1,  1019,    -1,    10,   222,    -1,    11,    -1,    10,     4,
     222,    -1,   223,  1023,     6,  1023,    -1,   224,  1023,     6,
    1023,    -1,     6,    -1,     7,    -1,  1024,     8,    -1,    -1,
    1024,  1025,    -1,   229,    -1,   230,    -1,   231,    -1,   232,
      -1
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
    2447,  2447,  2463,  2468,  2479,  2487,  2496,  2496,  2498,  2500,
    2506,  2506,  2508,  2513,  2529,  2535,  2535,  2538,  2550,  2555,
    2563,  2563,  2567,  2567,  2573,  2579,  2587,  2595,  2603,  2603,
    2605,  2607,  2607,  2609,  2628,  2644,  2652,  2652,  2655,  2656,
    2665,  2668,  2668,  2670,  2670,  2672,  2677,  2677,  2679,  2684,
    2711,  2729,  2729,  2732,  2736,  2740,  2741,  2742,  2743,  2744,
    2745,  2748,  2748,  2750,  2750,  2752,  2754,  2754,  2756,  2756,
    2759,  2774,  2794,  2796,  2796,  2799,  2809,  2810,  2811,  2812,
    2815,  2817,  2817,  2825,  2825,  2827,  2833,  2840,  2840,  2845,
    2845,  2847,  2849,  2851,  2860,  2860,  2876,  2882,  2894,  2902,
    2911,  2911,  2913,  2915,  2917,  2917,  2920,  2925,  2940,  2942,
    2942,  2945,  2956,  2960,  2967,  2967,  2970,  2970,  2988,  2993,
    3007,  3015,  3024,  3024,  3026,  3028,  3030,  3030,  3033,  3038,
    3056,  3058,  3058,  3061,  3072,  3076,  3082,  3089,  3089,  3093,
    3093,  3095,  3100,  3100,  3102,  3104,  3106,  3109,  3109,  3120,
    3126,  3133,  3133,  3135,  3137,  3139,  3142,  3142,  3153,  3159,
    3166,  3166,  3168,  3170,  3172,  3175,  3175,  3186,  3192,  3199,
    3199,  3201,  3203,  3205,  3208,  3208,  3219,  3225,  3232,  3232,
    3234,  3236,  3238,  3241,  3241,  3252,  3259,  3266,  3266,  3268,
    3270,  3272,  3276,  3276,  3287,  3293,  3300,  3300,  3302,  3304,
    3306,  3310,  3310,  3312,  3318,  3345,  3364,  3364,  3367,  3371,
    3375,  3376,  3377,  3378,  3379,  3380,  3383,  3383,  3385,  3385,
    3387,  3389,  3389,  3391,  3391,  3394,  3409,  3431,  3440,  3440,
    3443,  3453,  3454,  3455,  3456,  3459,  3461,  3461,  3469,  3469,
    3471,  3477,  3484,  3484,  3489,  3489,  3491,  3493,  3495,  3504,
    3504,  3520,  3525,  3536,  3544,  3553,  3553,  3555,  3557,  3559,
    3559,  3562,  3567,  3582,  3588,  3588,  3591,  3602,  3606,  3613,
    3613,  3617,  3617,  3635,  3640,  3653,  3661,  3670,  3670,  3672,
    3674,  3676,  3676,  3679,  3684,  3702,  3708,  3708,  3711,  3722,
    3726,  3730,  3736,  3736,  3740,  3740,  3742,  3747,  3747,  3749,
    3751,  3753,  3756,  3756,  3767,  3773,  3780,  3780,  3782,  3784,
    3786,  3789,  3789,  3800,  3806,  3813,  3813,  3815,  3817,  3819,
    3823,  3823,  3834,  3840,  3847,  3847,  3849,  3851,  3853,  3857,
    3857,  3868,  3874,  3881,  3881,  3883,  3885,  3887,  3891,  3891,
    3902,  3908,  3915,  3915,  3917,  3919,  3921,  3925,  3925,  3936,
    3942,  3949,  3949,  3951,  3953,  3955,  3959,  3959,  3961,  3967,
    3994,  4012,  4012,  4015,  4019,  4023,  4024,  4025,  4026,  4027,
    4028,  4031,  4031,  4033,  4033,  4035,  4037,  4037,  4039,  4039,
    4042,  4057,  4077,  4079,  4079,  4082,  4092,  4093,  4094,  4095,
    4098,  4100,  4100,  4108,  4108,  4114,  4116,  4124,  4132,  4141,
    4143,  4145,  4145,  4149,  4169,  4187,  4193,  4193,  4196,  4197,
    4198,  4199,  4200,  4201,  4202,  4209,  4217,  4226,  4226,  4228,
    4230,  4232,  4232,  4234,  4241,  4252,  4254,  4254,  4256,  4258,
    4275,  4275,  4277,  4299,  4316,  4328,  4333,  4333,  4336,  4337,
    4338,  4340,  4349,  4358,  4367,  4367,  4373,  4380,  4380,  4382,
    4387,  4394,  4401,  4401,  4403,  4406,  4413,  4420,  4427,  4434,
    4436,  4442,  4449,  4449,  4451,  4456,  4463,  4469,  4469,  4471,
    4476,  4483,  4490,  4490,  4492,  4497,  4504,  4510,  4510,  4512,
    4515,  4522,  4528,  4530,  4538,  4544,  4544,  4546,  4549,  4556,
    4563,  4563,  4565,  4570,  4577,  4583,  4583,  4585,  4588,  4595,
    4601,  4601,  4603,  4606,  4613,  4619,  4619,  4621,  4624,  4636,
    4645,  4654,  4663,  4672,  4681,  4691,  4700,  4709,  4715,  4721,
    4727,  4733,  4747,  4757,  4768,  4774,  4783,  4803,  4803,  4805,
    4823,  4839,  4847,  4847,  4850,  4857,  4858,  4862,  4862,  4864,
    4867,  4869,  4886,  4894,  4896,  4896,  4898,  4900,  4909,  4911,
    4911,  4913,  4913,  4915,  4931,  4933,  4938,  4938,  4940,  4940,
    4942,  4968,  4976,  4990,  4991,  4998,  5000,  5000,  5002,  5003,
    5004,  5005
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
  "ATUPPEREND", "ATLOWERSTART", "ATLOWEREND", "SUPERBASICSTART",
  "SUPERBASICEND", "ISFREESTART", "ISFREEEND", "UNKNOWNSTART",
  "UNKNOWNEND", "INTEGERVARIABLEBRANCHINGWEIGHTSSTART",
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
  "variablesIsFree", "variablesIsFreeStart",
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
  "objectivesAtUpperBody", "objectivesIsFree", "objectivesIsFreeStart",
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
     475,   476,   477,   478,   479,   480,   481,   482,   483,    32,
       9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   233,   234,   234,   235,   236,   237,   237,   238,   238,
     239,   240,   241,   242,   242,   243,   244,   244,   245,   246,
     246,   247,   247,   248,   249,   250,   250,   251,   251,   251,
     251,   251,   252,   253,   253,   254,   254,   255,   256,   257,
     257,   258,   258,   259,   260,   261,   261,   262,   262,   263,
     264,   265,   265,   266,   266,   267,   268,   269,   269,   270,
     270,   271,   272,   272,   273,   274,   274,   275,   275,   276,
     277,   278,   278,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   280,   281,   282,   282,   283,   283,
     284,   285,   286,   287,   288,   288,   289,   289,   290,   291,
     292,   293,   294,   294,   295,   295,   296,   297,   298,   299,
     300,   300,   301,   302,   302,   303,   303,   304,   305,   306,
     307,   308,   308,   309,   309,   310,   311,   312,   313,   314,
     314,   315,   315,   316,   317,   318,   319,   320,   320,   321,
     321,   322,   323,   324,   325,   326,   326,   327,   327,   328,
     329,   330,   331,   332,   332,   333,   333,   334,   335,   336,
     337,   338,   338,   339,   340,   340,   341,   341,   342,   343,
     344,   345,   346,   347,   347,   348,   348,   349,   350,   351,
     351,   352,   353,   354,   355,   355,   356,   356,   356,   357,
     357,   358,   358,   359,   360,   360,   361,   361,   362,   363,
     364,   364,   365,   365,   365,   365,   365,   366,   367,   368,
     369,   369,   370,   370,   371,   372,   373,   374,   375,   376,
     376,   377,   377,   378,   379,   380,   381,   382,   383,   383,
     384,   384,   385,   386,   387,   388,   389,   389,   390,   391,
     392,   393,   394,   395,   395,   396,   396,   397,   398,   399,
     399,   400,   401,   402,   403,   403,   404,   404,   404,   405,
     405,   406,   406,   407,   408,   408,   409,   409,   410,   411,
     412,   412,   413,   413,   414,   415,   416,   416,   417,   417,
     418,   419,   420,   421,   422,   423,   423,   424,   424,   425,
     426,   427,   427,   428,   429,   430,   431,   431,   432,   432,
     432,   433,   433,   434,   434,   435,   436,   436,   437,   437,
     438,   439,   440,   440,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   442,
     443,   444,   444,   445,   445,   446,   446,   447,   448,   449,
     450,   451,   452,   452,   453,   453,   454,   455,   456,   457,
     458,   459,   459,   460,   460,   461,   462,   462,   463,   464,
     465,   466,   466,   467,   467,   468,   469,   470,   471,   471,
     472,   472,   473,   474,   475,   476,   476,   477,   477,   478,
     479,   480,   481,   481,   482,   482,   483,   484,   485,   486,
     487,   487,   488,   488,   489,   490,   490,   491,   492,   493,
     494,   495,   495,   496,   496,   497,   498,   498,   499,   500,
     501,   502,   503,   503,   504,   504,   505,   506,   506,   507,
     508,   509,   510,   511,   511,   512,   512,   513,   514,   514,
     515,   516,   517,   518,   519,   519,   520,   520,   521,   522,
     523,   524,   525,   525,   526,   526,   527,   528,   529,   530,
     531,   531,   532,   532,   533,   534,   534,   535,   536,   537,
     538,   539,   539,   540,   540,   541,   542,   543,   543,   544,
     545,   546,   547,   547,   548,   548,   548,   549,   549,   550,
     550,   551,   552,   553,   553,   554,   554,   554,   555,   555,
     556,   557,   558,   559,   559,   560,   561,   562,   562,   563,
     563,   564,   565,   566,   567,   567,   568,   569,   570,   570,
     571,   571,   572,   573,   574,   574,   575,   576,   577,   578,
     578,   579,   579,   579,   580,   580,   581,   581,   582,   583,
     584,   584,   585,   585,   586,   587,   588,   588,   589,   590,
     591,   592,   592,   593,   593,   593,   594,   594,   595,   595,
     596,   597,   597,   598,   599,   600,   601,   601,   602,   603,
     604,   604,   605,   606,   607,   608,   608,   609,   610,   611,
     611,   612,   613,   614,   615,   615,   616,   617,   618,   618,
     619,   620,   621,   622,   622,   623,   624,   625,   625,   626,
     627,   628,   629,   629,   630,   631,   632,   632,   633,   634,
     635,   636,   636,   637,   638,   639,   639,   640,   641,   642,
     643,   643,   644,   645,   646,   646,   647,   647,   648,   649,
     650,   650,   651,   652,   653,   654,   654,   655,   655,   655,
     656,   656,   657,   657,   658,   659,   660,   660,   661,   661,
     662,   663,   663,   664,   665,   666,   667,   667,   668,   668,
     668,   669,   669,   670,   670,   671,   672,   672,   673,   674,
     675,   676,   676,   677,   677,   677,   677,   677,   677,   677,
     677,   678,   678,   679,   679,   680,   681,   681,   682,   682,
     683,   684,   685,   686,   686,   687,   687,   687,   687,   687,
     688,   689,   689,   690,   690,   691,   692,   693,   693,   694,
     694,   695,   696,   697,   698,   698,   699,   700,   701,   701,
     702,   702,   703,   704,   705,   705,   706,   707,   708,   709,
     709,   710,   710,   710,   711,   711,   712,   712,   713,   714,
     715,   715,   716,   716,   717,   718,   719,   719,   720,   721,
     722,   723,   723,   724,   724,   724,   724,   725,   725,   726,
     726,   727,   728,   728,   729,   730,   731,   732,   732,   733,
     734,   735,   735,   736,   737,   738,   739,   739,   740,   741,
     742,   742,   743,   744,   745,   746,   746,   747,   748,   749,
     749,   750,   751,   752,   753,   753,   754,   755,   756,   756,
     757,   758,   759,   760,   760,   761,   762,   763,   763,   764,
     765,   766,   767,   767,   768,   769,   770,   770,   771,   772,
     773,   774,   774,   775,   776,   777,   778,   778,   779,   779,
     779,   779,   779,   779,   779,   779,   780,   780,   781,   781,
     782,   783,   783,   784,   784,   785,   786,   787,   788,   788,
     789,   789,   789,   789,   789,   790,   791,   791,   792,   792,
     793,   794,   795,   795,   796,   796,   797,   798,   799,   800,
     800,   801,   802,   803,   803,   804,   804,   805,   806,   807,
     807,   808,   809,   810,   811,   811,   812,   812,   812,   813,
     813,   814,   814,   815,   816,   817,   817,   818,   818,   819,
     820,   821,   821,   822,   823,   824,   825,   825,   826,   826,
     826,   826,   827,   827,   828,   828,   829,   830,   830,   831,
     832,   833,   834,   834,   835,   836,   837,   837,   838,   839,
     840,   841,   841,   842,   843,   844,   844,   845,   846,   847,
     848,   848,   849,   850,   851,   851,   852,   853,   854,   855,
     855,   856,   857,   858,   858,   859,   860,   861,   862,   862,
     863,   864,   865,   865,   866,   867,   868,   869,   869,   870,
     871,   872,   872,   873,   874,   875,   876,   876,   877,   878,
     879,   880,   880,   881,   881,   881,   881,   881,   881,   881,
     881,   882,   882,   883,   883,   884,   885,   885,   886,   886,
     887,   888,   889,   890,   890,   891,   891,   891,   891,   891,
     892,   893,   893,   894,   894,   895,   896,   897,   897,   898,
     899,   900,   900,   901,   902,   903,   904,   904,   905,   905,
     905,   905,   905,   905,   905,   906,   906,   907,   907,   908,
     909,   910,   910,   911,   912,   912,   913,   913,   914,   915,
     916,   916,   917,   918,   919,   920,   921,   921,   922,   922,
     922,   923,   924,   925,   926,   926,   927,   928,   928,   929,
     930,   931,   932,   932,   933,   934,   935,   936,   937,   938,
     939,   940,   941,   941,   942,   943,   944,   945,   945,   946,
     947,   948,   949,   949,   950,   951,   952,   953,   953,   954,
     955,   956,   957,   958,   959,   960,   960,   961,   962,   963,
     964,   964,   965,   966,   967,   968,   968,   969,   970,   971,
     972,   972,   973,   974,   975,   976,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,   991,   992,   993,   994,   995,   996,   997,   997,   998,
     999,  1000,  1001,  1001,  1002,  1002,  1002,  1003,  1003,  1004,
    1005,  1006,  1007,  1007,  1008,  1008,  1009,  1010,  1011,  1012,
    1012,  1013,  1013,  1014,  1015,  1016,  1017,  1017,  1018,  1018,
    1019,  1020,  1021,  1022,  1022,  1023,  1024,  1024,  1025,  1025,
    1025,  1025
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
       1,     1,     1,     1,     3,     6,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       2,     1,     0,     3,     1,     4,     1,     1,     2,     1,
       3,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     2,     1,     3,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     0,     1,     1,
       1,     1,     3,     4,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     2,     1,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     2,     1,     0,
       2,     1,     1,     1,     1,     3,     6,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     0,     3,
       1,     1,     0,     1,     1,     1,     1,     3,     4,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     2,
       1,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     2,     1,     0,     2,     1,     1,     1,     1,
       3,     6,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     0,     2,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     3,     1,
       1,     2,     4,     3,     1,     1,     0,     2,     1,     1,
       1,     3,     3,     3,     2,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     4,     1,     1,
       4,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     4,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     3,     3,     4,     1,     1,     2,     1,
       3,     4,     4,     1,     1,     2,     0,     2,     1,     1,
       1,     1
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
     153,   154,     0,     0,   162,  1176,     0,   172,    37,    43,
      49,    55,    61,   481,    15,   483,     0,   309,   304,   306,
     307,   266,   283,   275,     0,   269,   270,   272,     0,   273,
       0,   198,   201,     0,   209,     0,   218,     0,   227,     0,
    1064,     0,   237,  1061,  1062,  1063,     0,   242,    91,    88,
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
     284,     0,   207,     0,  1112,   211,   213,   212,  1109,  1110,
    1111,     0,   216,   220,   222,   221,     0,   225,   229,   231,
     230,  1176,     0,   234,     0,   246,   240,   243,   244,    90,
      98,   106,   112,   118,   115,     0,   125,   133,   141,   149,
     157,   163,   169,   166,     0,  1176,  1175,  1178,  1179,  1180,
    1181,  1177,   175,   182,     0,   178,   179,   184,   493,   490,
     480,   488,   489,  1176,  1176,  1176,   484,   486,   487,   485,
     310,   313,     0,   332,     0,   345,   340,   342,   343,     0,
       0,   350,     0,     0,     0,     0,     0,     0,     0,   389,
       0,   400,     0,   411,     0,   422,     0,   433,     0,   441,
       0,     0,   449,     0,   460,   281,   278,     0,     0,   288,
     282,   285,   286,  1173,  1174,     0,   215,     0,     0,   224,
       0,   233,  1065,   239,     0,   245,   252,     0,   248,   249,
     254,   117,   168,  1129,   177,   180,     0,   183,   495,     0,
     693,   497,     0,     0,     0,     0,   336,   329,   333,   334,
     347,   344,     0,     0,     0,   354,   348,   351,   352,     0,
       0,   364,   359,   361,   362,     0,   371,   366,   368,   369,
       0,   378,   373,   375,   376,     0,   385,   380,   382,   383,
       0,     0,   393,   387,   390,   391,     0,   404,   398,   401,
     402,     0,   415,   409,   412,   413,     0,   426,   420,   423,
     424,     0,   437,   431,   434,   435,     0,   445,   439,   442,
     443,     0,     0,   453,   447,   450,   451,     0,   464,   458,
     461,   462,   280,   287,   294,     0,   290,   291,   296,   214,
    1113,   223,   232,   238,   247,   250,     0,   253,     0,   190,
     181,     0,     0,  1084,  1117,   185,   188,   186,  1081,  1082,
    1083,   187,  1114,  1115,  1116,   491,   695,   848,   697,  1176,
       0,   496,   498,  1176,  1176,  1176,   335,     0,   338,   339,
     346,     0,     0,   353,     0,   356,     0,   363,     0,     0,
    1040,   370,     0,   377,     0,   384,     0,     0,  1044,   392,
       0,   395,   397,  1046,   403,     0,   406,   408,   414,     0,
     417,   419,   425,     0,   428,   430,   436,     0,   444,     0,
       0,   452,     0,     0,   455,   463,   470,     0,   466,   467,
     472,   289,   292,     0,   295,     0,   260,   251,   255,   258,
     256,   257,   189,  1176,     0,   850,  1003,   852,  1176,     0,
     696,   698,     0,   504,   501,   494,   499,   500,  1136,  1126,
    1120,   337,  1124,     0,   355,   357,  1132,     0,   365,  1041,
     372,   379,   386,  1131,   394,   396,     0,  1045,   405,   407,
     416,   418,   427,   429,   438,   446,  1133,     0,   454,   456,
     465,   468,     0,   471,     0,   302,   293,   297,   300,   298,
     299,   259,  1085,  1118,  1005,   492,     0,  1176,     0,   851,
     853,     0,   704,   701,   694,   699,   700,  1176,   506,     0,
     526,     0,     0,     0,     0,  1055,  1043,     0,     0,     0,
    1047,  1048,  1049,  1050,     0,     0,   478,   469,   473,   476,
     474,   475,   301,  1176,     0,  1006,     0,   859,   856,   849,
     854,   855,  1176,   706,     0,   726,     0,  1130,   502,   528,
     548,     0,  1176,     0,   507,   358,  1042,  1054,     0,     0,
       0,   457,   477,     0,  1011,  1009,  1004,  1007,  1008,  1176,
     861,     0,   881,     0,  1128,   702,   728,   749,     0,  1176,
       0,   707,   550,   610,     0,     0,   529,     0,     0,   511,
     505,   508,   509,  1051,  1052,  1053,  1176,     0,  1127,   857,
     883,   904,     0,  1176,     0,   862,   751,   811,     0,     0,
     729,     0,     0,   711,   705,   708,   709,   612,   632,     0,
     556,   553,   549,   551,   552,     0,   533,   527,   530,   531,
    1176,   510,   517,     0,   513,   514,   519,  1134,  1010,  1014,
    1012,     0,   906,   966,     0,     0,   884,     0,     0,   866,
     860,   863,   864,   703,   757,   754,   750,   752,   753,     0,
     733,   727,   730,   731,  1176,   710,   717,     0,   713,   714,
     719,   634,   656,     0,     0,   613,   558,     0,   565,     0,
     539,   532,     0,   535,   536,   541,  1135,   512,   515,     0,
     518,     0,     0,  1176,  1097,  1059,     0,  1089,     0,  1015,
    1016,  1021,  1056,  1057,  1058,  1023,  1018,  1020,  1086,  1087,
    1088,  1022,  1094,  1095,  1096,  1019,  1024,   858,   912,   909,
     905,   907,   908,     0,   888,   882,   885,   886,  1176,   865,
     872,     0,   868,   869,   874,   814,   812,   816,   759,     0,
     766,     0,   739,   732,     0,   735,   736,   741,  1125,   712,
     715,     0,   718,   503,     0,     0,     0,   617,   611,   614,
     615,   554,   567,   574,     0,  1176,     0,   559,   534,   537,
       0,   540,     0,   525,   516,  1176,   520,   521,  1068,  1069,
     522,   523,  1176,     0,     0,  1176,     0,  1028,  1013,  1025,
    1026,  1017,   969,   967,   971,   914,     0,   921,     0,   894,
     887,     0,   890,   891,   896,  1119,   867,   870,     0,   873,
       0,   815,   755,   768,   775,     0,     0,   760,   734,   737,
       0,   740,     0,   725,   716,   720,   721,   722,   723,   659,
     657,   661,     0,     0,   639,   633,   636,   637,   623,   616,
       0,   619,   620,   625,   576,   583,     0,     0,   568,     0,
    1154,   562,   557,   560,   561,     0,   547,   538,   542,   543,
     544,   545,   524,     0,  1060,  1098,  1176,  1090,  1027,  1037,
       0,  1036,     0,  1030,  1031,  1033,  1034,  1035,     0,   970,
     910,   923,   930,     0,     0,   915,   889,   892,     0,   895,
       0,   880,   871,   875,   876,   877,   878,     0,   829,   813,
     826,   827,  1176,   817,   823,   825,   820,   822,   824,   821,
     819,   818,   777,   784,     0,     0,   769,  1154,   763,   758,
     761,   762,     0,   748,   738,  1074,  1102,     0,     0,   742,
     743,   745,  1071,  1072,  1073,   744,   746,  1099,  1100,  1101,
     724,     0,   660,     0,   638,   644,     0,   641,   646,   618,
     621,     0,   624,   585,   592,     0,     0,   577,  1154,   571,
     566,   569,   570,  1176,     0,     0,   564,  1152,  1153,   546,
    1176,  1123,  1039,     0,  1029,  1032,     0,   984,   968,   981,
     982,   972,   978,   980,   975,   977,   979,   976,   973,   974,
     932,   939,     0,     0,   924,  1154,   918,   913,   916,   917,
       0,   903,   893,  1079,  1107,  1176,  1176,   897,   898,   900,
    1076,  1077,  1078,   899,   901,  1104,  1105,  1106,   879,   828,
     836,  1140,     0,   831,   833,   838,   832,  1137,  1142,     0,
     786,   793,     0,     0,   778,  1154,   772,   767,   770,   771,
       0,   765,   747,  1176,  1176,     0,   674,   658,   671,   672,
     662,   668,   670,   665,   667,   669,   666,   664,   663,   635,
     640,   642,     0,   645,     0,   631,   622,   626,   627,   628,
     629,   594,   601,     0,     0,   586,  1154,   580,   575,   578,
     579,     0,   573,  1121,  1176,     0,   563,  1157,  1155,  1159,
    1070,  1038,   983,   991,     0,   986,   988,   993,   987,   941,
     948,     0,     0,   933,  1154,   927,   922,   925,   926,     0,
     920,   902,     0,     0,   830,   834,     0,   837,  1138,     0,
    1141,  1176,   795,   802,     0,     0,   787,  1154,   781,   776,
     779,   780,     0,   774,   764,  1075,  1103,   673,   681,     0,
     676,   678,   683,   677,     0,   654,   643,   651,   652,     0,
    1176,   647,   650,  1066,   648,  1091,  1092,   649,   630,   603,
     555,     0,     0,   595,  1154,   589,   584,   587,   588,     0,
     582,   572,     0,     0,  1169,  1164,  1166,  1167,     0,  1158,
     985,   989,     0,   992,   950,   957,     0,     0,   942,  1154,
     936,   931,   934,   935,     0,   929,   919,  1176,  1176,     0,
     847,   835,   845,   839,   840,   843,   841,   844,   842,  1154,
    1149,  1139,  1147,  1148,  1146,  1145,  1144,  1143,  1122,   804,
     756,     0,     0,   796,  1154,   790,   785,   788,   789,     0,
     783,   773,   675,   679,     0,   682,   653,     0,     0,     0,
       0,   604,  1154,   598,   593,   596,   597,     0,   591,   581,
    1176,     0,  1168,     0,  1156,  1176,  1176,  1160,  1162,  1161,
       0,  1002,   990,  1000,   994,   995,   998,   996,   999,   997,
     959,   911,     0,     0,   951,  1154,   945,   940,   943,   944,
       0,   938,   928,  1080,  1108,   846,     0,  1151,     0,   805,
    1154,   799,   794,   797,   798,     0,   792,   782,     0,   692,
     680,   690,   684,   685,   688,   686,   689,   687,   655,     0,
    1176,  1154,   607,   602,   605,   606,     0,   600,   590,  1165,
    1170,     0,     0,     0,  1001,     0,   960,  1154,   954,   949,
     952,   953,     0,   947,   937,  1150,  1154,   808,   803,   806,
     807,     0,   801,   791,   691,  1067,  1093,     0,   609,   599,
    1163,  1176,  1176,  1154,   963,   958,   961,   962,     0,   956,
     946,     0,   810,   800,   608,  1171,  1172,     0,   965,   955,
     809,   964
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
    1205,  1324,  1416,  1417,  1418,  1497,  1322,  1323,  1412,  1494,
    1495,  1496,  1566,  1410,  1411,  1490,  1563,  1564,  1565,  1597,
     868,   869,   924,  1008,  1009,  1010,  1090,  1091,  1092,  1093,
    1201,  1202,  1317,  1316,   922,   923,  1005,  1085,  1086,  1087,
    1196,  1197,  1198,  1312,  1313,  1401,  1396,  1397,  1398,  1003,
    1080,  1081,  1191,  1192,  1300,  1297,  1298,  1299,  1389,  1390,
    1391,  1392,  1484,  1485,  1552,  1550,  1551,   607,   608,   689,
     690,   754,   755,   756,   794,   795,   796,   830,   864,   865,
     866,   917,   918,   919,   920,  1001,  1002,  1075,  1074,   827,
     828,   859,   911,   912,   913,   994,   995,   996,   997,  1070,
    1071,  1179,  1174,   857,   858,   906,   907,   908,   989,   990,
     991,  1066,  1169,  1170,  1171,  1290,  1064,  1065,  1165,  1287,
    1288,  1289,  1382,  1163,  1164,  1283,  1379,  1380,  1381,  1479,
    1281,  1282,  1375,  1476,  1477,  1478,  1545,  1373,  1374,  1472,
    1542,  1543,  1544,  1591,  1470,  1471,  1538,  1588,  1589,  1590,
    1611,   903,   986,   987,  1060,  1061,  1153,  1149,  1150,  1151,
    1272,  1273,  1274,  1275,  1366,  1367,  1453,  1451,  1452,   686,
     687,   748,   749,   789,   790,   791,   821,   822,   823,   854,
     900,   901,   902,   981,   982,   983,   984,  1058,  1059,  1143,
    1142,   851,   852,   895,   975,   976,   977,  1051,  1052,  1053,
    1054,  1138,  1139,  1257,  1252,   893,   894,   970,   971,   972,
    1046,  1047,  1048,  1134,  1247,  1248,  1249,  1359,  1132,  1133,
    1243,  1356,  1357,  1358,  1444,  1241,  1242,  1352,  1441,  1442,
    1443,  1530,  1350,  1351,  1437,  1527,  1528,  1529,  1582,  1435,
    1436,  1523,  1579,  1580,  1581,  1608,  1521,  1522,  1575,  1605,
    1606,  1607,  1617,   967,  1043,  1044,  1128,  1129,  1231,  1228,
    1229,  1230,  1344,  1345,  1346,  1347,  1432,  1433,  1514,  1512,
    1513,   745,   746,   784,   816,   817,   818,   847,   890,   891,
     948,   949,   950,  1038,  1039,  1040,  1122,  1123,  1124,  1125,
    1126,  1127,  1223,   629,   630,   642,   643,   716,   717,   770,
     771,   772,   773,   766,   951,   952,   953,   954,   955,   243,
     244,   245,  1402,  1403,  1027,  1028,  1029,  1181,  1182,  1183,
    1184,  1259,  1260,  1261,  1262,   956,   598,   599,   600,   957,
     958,   959,   960,  1404,  1405,  1406,   961,   962,   963,   964,
    1186,  1187,  1188,  1189,  1264,  1265,  1266,  1267,   357,   358,
     359,   360,   965,   602,   603,   604,   855,   417,  1017,  1160,
     966,   431,   831,   418,   750,   691,   207,   612,   439,   433,
     452,   785,   804,   419,  1276,  1277,  1278,  1369,  1370,  1467,
    1461,  1462,  1463,  1536,  1216,  1217,  1338,  1339,  1428,  1429,
    1507,  1504,  1218,  1335,  1425,  1426,  1427,  1508,  1509,   466,
     284,   285,   401
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1342
static const yytype_int16 yypact[] =
{
     284, -1342, -1342,    73,   -20,   113, -1342, -1342,   138,   117,
     309, -1342,   339, -1342, -1342, -1342, -1342,   131,   367,   272,
   -1342, -1342, -1342, -1342,   -20, -1342, -1342, -1342, -1342, -1342,
     123,   374,   108, -1342, -1342, -1342, -1342, -1342,   195, -1342,
   -1342,   236, -1342, -1342,   266, -1342, -1342,   277, -1342, -1342,
     302, -1342, -1342,   245,   519, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342,   138, -1342,   251,   380,
      47, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342,   274,   387, -1342,
   -1342,   384, -1342,   403, -1342,   405, -1342,   294, -1342,   409,
   -1342,   417, -1342,   435, -1342,   460, -1342,   497, -1342,   282,
   -1342,   352,   299,   298,   300,   315,   313, -1342, -1342, -1342,
   -1342,   319,   500,   -23, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342,   353,   332, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342,   162, -1342,   352, -1342, -1342,    55,
   -1342, -1342, -1342, -1342,    45, -1342, -1342, -1342, -1342,    31,
   -1342, -1342, -1342, -1342,   408,   502, -1342,    33, -1342, -1342,
   -1342, -1342,    28, -1342, -1342, -1342, -1342,    27, -1342, -1342,
   -1342, -1342,    18, -1342, -1342, -1342, -1342,    26, -1342, -1342,
   -1342, -1342,   430,   505, -1342, -1342,   509, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342,   -35, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342,   373,    63, -1342, -1342,   512, -1342,
     352, -1342, -1342,   440,   264,   446,   264,   452,   264,   470,
   -1342,   467, -1342, -1342, -1342, -1342,   517, -1342, -1342, -1342,
     379, -1342, -1342,   381, -1342, -1342,   377,   477,    30, -1342,
   -1342, -1342, -1342, -1342, -1342,   383, -1342, -1342,   385, -1342,
   -1342,   375, -1342, -1342,   389, -1342, -1342,   401,   489,    11,
   -1342, -1342, -1342, -1342,   487,     1,   278, -1342, -1342, -1342,
   -1342,   520,   220, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,   423,
     399, -1342, -1342,    52, -1342,   531, -1342,   506, -1342,   482,
   -1342,   482, -1342,   482, -1342,   482, -1342,   527, -1342,   527,
   -1342,   527, -1342,   527, -1342,   482, -1342,   482, -1342,   510,
   -1342,   352, -1342, -1342,    16, -1342, -1342, -1342, -1342,   553,
   -1342,   416, -1342,   526, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342,   416, -1342, -1342, -1342, -1342,   416, -1342, -1342, -1342,
   -1342, -1342,   499, -1342,   318, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342,   427, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342,   421, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342,   429,   432, -1342, -1342,   390, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,   555, -1342,     9, -1342, -1342, -1342, -1342,   543,
     557, -1342,   547,   559,   563,   565,   567,   551,   576, -1342,
     578, -1342,   580, -1342,   582, -1342,   585, -1342,   608, -1342,
     571,   610, -1342,   612, -1342, -1342, -1342,   439,   504, -1342,
   -1342, -1342, -1342, -1342, -1342,   437, -1342,   573,   471, -1342,
     475, -1342, -1342, -1342,   469, -1342, -1342,   491,   494, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342,   616,   428, -1342,   554,
     444,   618,   770,   771,   772,    22, -1342, -1342, -1342, -1342,
   -1342, -1342,   643,   774,   -47, -1342, -1342, -1342, -1342,   776,
     118, -1342, -1342, -1342, -1342,   486, -1342, -1342, -1342, -1342,
     151, -1342, -1342, -1342, -1342,   124, -1342, -1342, -1342, -1342,
     777,   -79, -1342, -1342, -1342, -1342,   -78, -1342, -1342, -1342,
   -1342,   -93, -1342, -1342, -1342, -1342,    19, -1342, -1342, -1342,
   -1342,    85, -1342, -1342, -1342, -1342,   -22, -1342, -1342, -1342,
   -1342,   778,   466, -1342, -1342, -1342, -1342,   513, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342,   665,   542, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342,   625,   428,   664, -1342,
   -1342,   784,   785, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342,   586,   757, -1342,
     627, -1342, -1342, -1342, -1342, -1342, -1342,   656, -1342, -1342,
   -1342,   786,   782, -1342,   -45, -1342,   787, -1342,   783,   129,
   -1342, -1342,   498, -1342,   168, -1342,   150,   788, -1342, -1342,
      91, -1342, -1342, -1342, -1342,    43, -1342, -1342, -1342,   -80,
   -1342, -1342, -1342,    20, -1342, -1342, -1342,    94, -1342,    97,
     789, -1342,   790,   478, -1342, -1342, -1342,   678,   680, -1342,
   -1342, -1342, -1342,   635,   428,   682, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342,   791, -1342,   591,   768, -1342,   637,
   -1342, -1342,   799,   638, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342,   802, -1342, -1342, -1342,   804, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342,   639,   316, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342,   805, -1342, -1342,
   -1342, -1342,   645,   428,   688, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342,   792, -1342,   647, -1342,
   -1342,   806,   614, -1342, -1342, -1342, -1342, -1342, -1342,   646,
     640,   779,   710,   673,   676, -1342, -1342,   812,   816,   818,
   -1342, -1342, -1342, -1342,   658,   703, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342,   649, -1342,   817,   621, -1342, -1342,
   -1342, -1342, -1342, -1342,   631,   628,   793, -1342, -1342, -1342,
     653,   779, -1342,   655, -1342, -1342, -1342, -1342,   822,   824,
     825, -1342, -1342,   828, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342,   632,   626,   798, -1342, -1342, -1342,   663,   793, -1342,
     657, -1342, -1342,   650,   659,   661, -1342,   834,   503, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342,   463, -1342, -1342,
   -1342,   666,   798, -1342,   667, -1342, -1342, -1342,   669,   671,
   -1342,   837,   485, -1342, -1342, -1342, -1342, -1342,   654,   779,
     670, -1342, -1342, -1342, -1342,   109, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342,   674,   679, -1342, -1342, -1342, -1342, -1342,
   -1342,   356, -1342, -1342,   675,   677, -1342,   840,   483, -1342,
   -1342, -1342, -1342,   730,   684, -1342, -1342, -1342, -1342,   122,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342,   660,   668, -1342,
   -1342, -1342, -1342,   819,   681, -1342, -1342,   686,   672,   814,
   -1342, -1342,   690,   692, -1342, -1342, -1342, -1342, -1342,   683,
     304,   849,   852, -1342, -1342, -1342,   853, -1342,   685,   356,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342,   739,   694, -1342,
   -1342, -1342, -1342,   125, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342,   651,   652, -1342, -1342, -1342, -1342, -1342, -1342,   696,
     698,   814, -1342, -1342,   700,   702, -1342, -1342, -1342, -1342,
   -1342,   687,   304,   745,   857,   689,  -132, -1342, -1342, -1342,
   -1342, -1342, -1342,   704,   814, -1342,   691, -1342, -1342, -1342,
     693,   304,   705, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342,   860,   863, -1342,  -146, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342,   706,   708,   814, -1342,
   -1342,   714,   712, -1342, -1342, -1342, -1342, -1342,   695,   304,
     697,   143, -1342, -1342,   716,   814,   699, -1342, -1342, -1342,
     701,   412,   715, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,   864,   521, -1342, -1342, -1342, -1342, -1342, -1342,
     720,   721, -1342, -1342, -1342,   718,   814,   707, -1342,   867,
     722, -1342, -1342, -1342, -1342,   724, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342,   868, -1342, -1342, -1342, -1342, -1342, -1342,
     870, -1342,   662,   155, -1342, -1342, -1342, -1342,   709,   229,
   -1342, -1342,   726,   814,   711, -1342, -1342, -1342,   713,   244,
     728, -1342, -1342, -1342, -1342, -1342, -1342,   -84, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342,   732,   814,   717, -1342,   722, -1342, -1342,
   -1342, -1342,   734, -1342, -1342, -1342, -1342,   875,   877, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342,   719,   281,   873, -1342, -1342,   539, -1342, -1342, -1342,
   -1342,   723,   304, -1342,   735,   814,   725, -1342,   722, -1342,
   -1342, -1342, -1342, -1342,   737,   743, -1342,   741, -1342, -1342,
   -1342, -1342, -1342,   747, -1342, -1342,   -82, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342,   748,   814,   727, -1342,   722, -1342, -1342, -1342, -1342,
     751, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,   765,   749, -1342, -1342,   753, -1342, -1342,   880,
   -1342,   755,   814,   729, -1342,   722, -1342, -1342, -1342, -1342,
     759, -1342, -1342, -1342, -1342,   -58, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,   731,    64,   763, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,   766,   814,   733, -1342,   722, -1342, -1342, -1342,
   -1342,   767, -1342, -1342, -1342,   736, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342,   775,   773, -1342, -1342,   753, -1342,
     761,   814,   738, -1342,   722, -1342, -1342, -1342, -1342,   769,
   -1342, -1342,   416,   416, -1342, -1342,   740,   388, -1342,   742,
     170, -1342, -1342,   794,   814,   744, -1342,   722, -1342, -1342,
   -1342, -1342,   795, -1342, -1342, -1342, -1342, -1342, -1342,   803,
     780, -1342, -1342,   753,  -118, -1342, -1342, -1342, -1342,   885,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342,   814,   746, -1342,   722, -1342, -1342, -1342, -1342,   781,
   -1342, -1342,   882,    13, -1342, -1342, -1342, -1342,   888,   535,
   -1342, -1342,   750,   388, -1342,   796,   814,   752, -1342,   722,
   -1342, -1342, -1342, -1342,   797, -1342, -1342, -1342, -1342,   801,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,   722,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342,   814,   754, -1342,   722, -1342, -1342, -1342, -1342,   807,
   -1342, -1342, -1342, -1342,   756,   388, -1342,  -115,   416,   893,
     758, -1342,   722, -1342, -1342, -1342, -1342,   800, -1342, -1342,
   -1342,   808, -1342,   894, -1342, -1342, -1342, -1342, -1342, -1342,
     809, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,   814,   760, -1342,   722, -1342, -1342, -1342, -1342,
     810, -1342, -1342, -1342, -1342, -1342,   811, -1342,   762, -1342,
     722, -1342, -1342, -1342, -1342,   813, -1342, -1342,   820, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,   896,
   -1342,   722, -1342, -1342, -1342, -1342,   823, -1342, -1342, -1342,
   -1342,   815,   900,   901, -1342,   764, -1342,   722, -1342, -1342,
   -1342, -1342,   826, -1342, -1342, -1342,   722, -1342, -1342, -1342,
   -1342,   827, -1342, -1342, -1342, -1342, -1342,   830, -1342, -1342,
   -1342, -1342, -1342,   722, -1342, -1342, -1342, -1342,   829, -1342,
   -1342,   831, -1342, -1342, -1342, -1342, -1342,   832, -1342, -1342,
   -1342, -1342
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,   833, -1342,
     887, -1342, -1342, -1342, -1342, -1342, -1342, -1342,   858, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342,   841, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,   508,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,   839, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342,   436, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
     821, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342,   340, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,   617, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
     296, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,   286, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342,   283, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342,   280, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,   279, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,   267, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342,   263, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,    56, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342,     8, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342,  -452, -1086, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342,  -251, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
    -444, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342,    32, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342,   -43, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,  -319, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342,   -27, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,   -94,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342,  -385, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,    15, -1342, -1342, -1342, -1342, -1342,  -158, -1342,
   -1342, -1342, -1342,  -291,  -370,  -491, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1043, -1342, -1342, -1342,  -153, -1342,
   -1342, -1342, -1342, -1342,  -996, -1342, -1342, -1341, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342,  -477, -1342, -1342, -1342, -1042,
   -1342, -1342, -1342, -1342, -1342, -1342, -1040, -1342, -1342, -1342,
   -1334, -1342, -1342, -1342, -1342, -1342, -1342, -1342,  -190, -1342,
   -1342, -1342,  -476, -1342, -1342, -1342,  -845, -1342,  -987, -1075,
   -1342, -1342,  -816, -1342, -1342, -1342,  -142, -1342,  -170,  -152,
   -1342, -1342,  -799, -1342, -1190, -1253, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1151, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,  -358,
    -371, -1342, -1342
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     472,   242,   836,   469,  1067,  1200,  1076,   896,   471,   396,
     597,   601,   860,   500,   247,   392,  1291,  1501,  1154,  1157,
     455,  1158,   272,  1368,   483,  1109,  1455,  1098,   463,   464,
     275,   269,   266,  1457,   383,   254,  1348,   263,  1269,  1088,
    1342,   293,   492,   493,   494,   647,   365,     7,   370,   251,
     651,   221,   638,  1088,  1239,   655,  1088,  1332,  1089,   248,
     622,  1135,   622,  1144,  1387,   638,   638,   638,  1118,   648,
     925,  1119,  1120,     6,  1121,  1180,  1486,   639,  1166,  1558,
     644,   356,   720,   364,   294,   369,  1232,  1235,   350,  1236,
    1399,   623,  1516,   704,  1360,  1368,   222,   353,   295,  1518,
     296,   802,   297,   354,   298,  1393,   299,  1400,   223,  1207,
     680,   681,   300,  1388,   301,  1270,   302,  1307,   303,   138,
     304,   628,   305,   423,   306,  1343,   307,    11,   308,   393,
     658,  1271,   273,  1271,  1383,   255,   384,   619,   267,   270,
    1368,   264,   276,  1258,  1554,   501,  1244,   252,   456,  1301,
    1304,  1556,  1305,    13,   647,   249,   616,  1271,   651,   441,
    1152,   443,   655,   445,   638,   638,   139,   941,   942,   434,
     140,   435,   141,   436,   142,  1420,   143,  1284,    85,   652,
     722,   829,   222,   447,   591,   449,    16,   592,   638,   239,
     944,   593,   945,   240,   223,   594,    77,   739,   740,   454,
     122,   718,    29,  1445,   946,   947,  1318,    86,   239,    87,
    1015,    88,   240,    89,   592,    90,   239,    91,  1325,    92,
     240,    93,   594,    94,   632,    95,  1480,    96,   628,   634,
     397,   398,   399,   400,   636,  1502,   638,   628,   692,   656,
     628,   123,   698,   699,   700,  1161,  1152,   714,   724,   725,
     413,   414,   415,   941,   942,  1353,   780,   781,   627,   709,
     657,   628,   709,  1498,   709,   659,   709,   628,   853,   708,
     591,   124,   628,   592,   635,   239,   944,   593,   945,   240,
     930,   594,   125,   931,  1238,   591,  1025,   709,  1531,   709,
     946,   947,   593,   628,   628,  1376,     1,     2,  1152,   633,
     712,  1253,  1254,  1255,  1256,   941,   942,   126,  1537,   353,
     239,   628,   742,   127,   240,   354,   711,   751,   802,    19,
      20,   992,   591,  1546,   993,   592,   130,   239,   944,   593,
     945,   240,  1049,   594,   596,  1050,  1413,   767,   768,   769,
      37,  1567,   946,   947,   157,   591,  1025,   202,   592,    24,
      25,    38,   593,    39,    40,    41,   594,    42,    43,    44,
     174,    45,    46,    47,  1438,    48,    49,    50,   205,    51,
      52,  1454,  1119,  1120,  1583,  1121,   786,    32,    33,   208,
     941,   942,   209,  1466,    80,    81,   797,  1473,   210,  1592,
     133,   134,   943,  1308,   159,   160,   213,   591,   402,   403,
     592,  1200,   239,   944,   593,   945,   240,   211,   594,   212,
    1598,   257,   813,   164,   165,   169,   170,   946,   947,   177,
     178,   824,   463,   464,  1491,   231,  1609,   182,   183,   591,
    1025,   837,   592,   278,   679,  1612,   593,  1515,   475,   476,
     594,  1175,  1176,  1177,  1178,   187,   188,   342,   848,  1524,
     351,   139,  1618,   591,  1025,   140,   361,   141,   861,   142,
     593,   143,   366,  1030,  1031,  1175,  1176,  1177,  1178,   591,
     192,   193,   592,   371,   239,   887,   593,   372,   240,   379,
     594,   381,   897,   380,  1539,   382,    86,   388,    87,  1553,
      88,   386,    89,   395,    90,   387,    91,   391,    92,   420,
      93,   432,    94,   389,    95,   473,    96,   197,   198,   936,
     216,   217,   258,   259,  1407,   279,   280,   390,   294,   286,
     287,   738,   344,   345,   429,  1077,  1078,   374,   375,   467,
     408,   409,   295,   481,   296,  1576,   297,   450,   298,   482,
     299,   424,   425,   998,  1110,  1111,   300,   437,   301,   484,
     302,   503,   303,   403,   304,   509,   305,   488,   306,   530,
     307,   579,   308,   458,   459,   495,   496,   504,   505,   510,
     511,   572,  1034,   515,   516,   520,   521,   525,   526,   561,
     779,   580,  1145,  1146,  1156,  1159,   531,   532,   536,   537,
     541,   542,   546,   547,  1185,   551,   552,   581,    38,   583,
      39,    40,    41,   582,    42,    43,    44,  1055,    45,    46,
      47,   584,    48,    49,    50,   476,    51,    52,   556,   557,
     562,   563,   567,   568,   573,   574,   588,   589,   631,   628,
     661,   662,   605,   665,   666,   675,   676,   693,   694,   606,
     710,   628,   728,   662,  1099,   734,   735,   752,   753,   764,
     765,   609,  1234,  1237,  1113,   775,   776,   787,   788,   814,
     815,  1114,  1263,   574,  1117,   838,   839,   862,   863,   870,
     871,   875,   876,   881,   882,   888,   889,   898,   899,   904,
     905,   909,   910,   915,   916,   968,   969,   973,   974,   979,
     980,  1006,  1007,  1022,  1023,  1036,  1037,  1072,  1073,  1083,
    1084,  1100,  1101,  1105,  1106,  1140,  1141,  1147,  1148,  1167,
    1168,  1172,  1173,  1194,  1195,  1303,  1306,  1208,  1209,  1226,
    1227,  1245,  1246,  1250,  1251,  1319,  1320,  1285,  1286,  1295,
    1296,  1310,  1195,  1314,  1315,  1326,  1327,  1354,  1355,  1377,
    1378,  1394,  1395,  1414,  1415,  1221,  1423,  1424,  1439,  1440,
    1449,  1450,  1459,  1460,  1474,  1475,  1492,  1493,  1505,  1506,
    1510,  1511,  1525,  1526,  1540,  1541,  1548,  1549,  1561,  1562,
    1577,  1578,  1586,  1587,  1603,  1604,   613,   614,   615,   620,
     621,  1279,   626,   637,   660,   671,   682,   683,   684,   685,
     701,   688,   703,   707,   702,   706,   713,   726,   730,   743,
     727,   666,   744,   747,   741,   757,   762,   758,   763,   774,
     782,   793,   792,   799,   798,   808,   802,   806,   805,   809,
     783,   810,   807,   819,   811,   812,   820,   825,   832,   826,
     843,   829,   844,   845,   846,   850,   849,   853,   856,   867,
     880,   892,  1333,   914,   937,   921,   978,   926,  1004,  1340,
     882,   985,  1032,  1012,  1015,  1033,  1035,  1056,   999,   980,
    1042,   988,  1011,   930,  1018,  1082,  1079,   916,  1115,  1116,
    1193,  1045,  1062,  1213,  1220,  1222,  1224,  1112,  1293,  1063,
    1294,  1309,  1130,  1094,  1362,  1363,  1371,  1364,  1500,  1131,
    1456,  1458,  1088,  1488,  1465,  1162,  1219,  1430,  1503,  1560,
    1571,   992,  1068,  1203,  1595,  1240,  1601,  1602,  1155,   129,
    1199,    76,   128,   485,   585,  1190,   672,  1280,  1321,  1049,
     705,  1336,  1385,  1386,  1136,  1482,   715,   421,   719,   721,
     729,   731,   723,  1349,  1292,  1408,  1268,  1384,  1372,   158,
     938,  1019,  1487,  1214,  1434,  1311,  1483,  1446,  1270,  1421,
    1000,  1388,  1069,  1409,  1365,  1057,  1517,  1519,  1137,  1361,
    1431,  1499,  1334,  1422,  1041,  1225,  1341,  1337,  1271,     0,
       0,     0,     0,     0,     0,     0,  1233,  1481,     0,  1532,
    1343,  1469,     0,  1520,   232,     0,  1568,  1547,     0,     0,
    1584,     0,  1594,     0,     0,     0,     0,     0,     0,  1593,
    1468,  1535,     0,     0,  1447,  1448,     0,  1599,  1555,  1557,
       0,  1613,  1610,  1619,     0,     0,     0,  1574,  1614,  1620,
    1621,     0,     0,     0,     0,     0,     0,  1585,     0,  1489,
    1570,     0,     0,     0,     0,     0,     0,     0,     0,  1302,
       0,     0,  1600,     0,     0,     0,   343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1533,  1534,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1569,
    1559,     0,     0,     0,  1572,  1573,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1596,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1464,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1615,  1616
};

static const yytype_int16 yycheck[] =
{
     371,   154,   801,   361,   991,  1091,  1002,   852,   366,     8,
     487,   487,   828,     4,   156,     4,  1167,     4,  1061,  1061,
       4,  1061,     4,  1276,   395,  1021,  1367,  1014,     6,     7,
       4,     4,     4,  1367,     4,     4,  1226,     4,   122,   171,
     122,    76,   413,   414,   415,   536,   236,    67,   238,     4,
     541,    74,   145,   171,  1129,   546,   171,  1208,   190,     4,
     107,  1048,   107,  1059,   122,   145,   145,   145,   214,   162,
     869,   217,   218,     0,   220,  1071,   194,   156,  1065,   194,
     158,   234,   162,   236,   119,   238,  1129,  1129,   230,  1129,
      26,   138,  1433,   138,  1245,  1348,   119,    45,   133,  1433,
     135,    37,   137,    51,   139,  1295,   141,    43,   131,  1096,
     587,   587,   147,   171,   149,   199,   151,  1192,   153,    72,
     155,   143,   157,   313,   159,   207,   161,    14,   163,   118,
     152,   215,   114,   215,  1285,   104,   106,   495,   110,   112,
    1393,   108,   116,  1139,  1485,   136,  1133,   102,   132,  1192,
    1192,  1485,  1192,    15,   645,   100,   134,   215,   649,   329,
      17,   331,   653,   333,   145,   145,   119,    24,    25,   321,
     123,   323,   125,   325,   127,  1326,   129,  1164,    70,   160,
     160,    38,   119,   335,    41,   337,    69,    44,   145,    46,
      47,    48,    49,    50,   131,    52,    73,   674,   674,   341,
       5,   158,    71,  1354,    61,    62,  1202,    99,    46,   101,
      40,   103,    50,   105,    44,   107,    46,   109,  1205,   111,
      50,   113,    52,   115,   515,   117,  1377,   119,   143,   520,
     229,   230,   231,   232,   525,   222,   145,   143,   609,   154,
     143,     5,   613,   614,   615,  1061,    17,   156,   154,   152,
      30,    31,    32,    24,    25,  1242,   733,   733,   140,   629,
     551,   143,   632,  1414,   634,   556,   636,   143,    39,   140,
      41,     5,   143,    44,   150,    46,    47,    48,    49,    50,
     171,    52,     5,   174,  1129,    41,    42,   657,  1439,   659,
      61,    62,    48,   143,   143,  1282,    12,    13,    17,   148,
     150,    57,    58,    59,    60,    24,    25,     5,  1459,    45,
      46,   143,   683,    68,    50,    51,   148,   688,    37,    10,
      11,   199,    41,  1474,   202,    44,    75,    46,    47,    48,
      49,    50,   207,    52,   487,   210,  1323,    21,    22,    23,
      68,  1492,    61,    62,    70,    41,    42,    65,    44,    10,
      11,    79,    48,    81,    82,    83,    52,    85,    86,    87,
      66,    89,    90,    91,  1351,    93,    94,    95,    16,    97,
      98,  1367,   217,   218,  1525,   220,   747,    10,    11,    80,
      24,    25,    84,  1370,    10,    11,   757,  1374,    88,  1540,
      10,    11,    36,  1192,    10,    11,    77,    41,   120,   121,
      44,  1487,    46,    47,    48,    49,    50,    92,    52,    96,
    1561,     3,   783,    10,    11,    10,    11,    61,    62,    10,
      11,   792,     6,     7,  1411,    72,  1577,    10,    11,    41,
      42,   802,    44,     3,   587,  1586,    48,  1433,   120,   121,
      52,    53,    54,    55,    56,    10,    11,    74,   819,  1436,
      10,   119,  1603,    41,    42,   123,    10,   125,   829,   127,
      48,   129,    10,   940,   940,    53,    54,    55,    56,    41,
      10,    11,    44,     3,    46,   846,    48,    10,    50,   100,
      52,   104,   853,   102,  1471,     8,    99,   112,   101,  1485,
     103,   108,   105,     6,   107,   110,   109,     8,   111,    76,
     113,    19,   115,   114,   117,     6,   119,    10,    11,   880,
      10,    11,    10,    11,  1313,    10,    11,   116,   119,    10,
      11,   674,    10,    11,    18,  1002,  1002,    10,    11,     3,
      10,    11,   133,   106,   135,  1522,   137,    27,   139,   118,
     141,    10,    11,   914,  1021,  1021,   147,    20,   149,   120,
     151,     8,   153,   121,   155,     8,   157,   167,   159,     8,
     161,   124,   163,    10,    11,    10,    11,    10,    11,    10,
      11,   132,   943,    10,    11,    10,    11,    10,    11,     8,
     733,     8,  1059,  1059,  1061,  1061,    10,    11,    10,    11,
      10,    11,    10,    11,  1071,    10,    11,   126,    79,   130,
      81,    82,    83,   128,    85,    86,    87,   978,    89,    90,
      91,   120,    93,    94,    95,   121,    97,    98,    10,    11,
      10,    11,    10,    11,   120,   121,    10,    11,   142,   143,
     164,   165,    78,   120,   121,    10,    11,    10,    11,   195,
     142,   143,   164,   165,  1015,    10,    11,    10,    11,    10,
      11,    33,  1129,  1129,  1025,    10,    11,    10,    11,    10,
      11,  1032,  1139,   121,  1035,    10,    11,    10,    11,    10,
      11,    10,    11,   170,   171,   212,   213,    10,    11,    10,
      11,    10,    11,   198,   199,    10,    11,    10,    11,   206,
     207,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   192,   193,  1192,  1192,    10,    11,    10,
      11,    10,    11,    10,    11,  1202,  1202,    10,    11,    10,
      11,   192,   193,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,  1116,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,   223,   224,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,     6,     6,     6,   136,
       6,  1152,     6,     6,     6,   120,   122,     3,     3,   203,
     134,    34,    10,    10,     8,     8,     8,     8,   120,     8,
      10,   121,   211,    35,   122,     6,     4,   169,     4,     4,
     122,   197,     6,   173,   168,     3,    37,   144,   108,     3,
      28,     3,   146,     6,   166,   122,   205,   196,   175,   201,
       8,    38,     8,     8,     6,   209,   204,    39,   175,   189,
       6,   175,  1213,     6,   170,   191,     6,   177,    29,  1220,
     171,   121,     3,   181,    40,     3,     3,   206,   198,   207,
     121,   177,   176,   171,   174,     8,   121,   199,     8,     6,
       6,   177,   176,     6,     6,     5,   214,   172,     3,   181,
       3,     8,   176,   179,  1255,  1256,     6,   122,     6,   181,
    1367,  1367,   171,     8,  1370,   179,   172,   122,    10,     6,
       6,   199,   202,   185,     8,   179,     6,     6,  1061,    76,
     190,    24,    54,   405,   478,   200,   576,   185,   183,   207,
     624,   178,  1293,  1294,   210,   122,   640,   310,   645,   649,
     663,   668,   653,   185,   200,   172,   208,   178,   183,    98,
     884,   933,  1394,   221,   183,  1196,  1390,   178,   199,   182,
     918,   171,   995,   187,  1273,   982,  1433,  1433,  1052,   208,
    1345,   180,   225,  1334,   949,  1123,   219,   226,   215,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1129,   182,    -1,   182,
     207,   187,    -1,   187,   145,    -1,   186,   180,    -1,    -1,
     180,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,   186,
    1371,   200,    -1,    -1,  1362,  1363,    -1,   184,  1485,  1485,
      -1,   184,   186,   184,    -1,    -1,    -1,   208,   188,   188,
     188,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,  1400,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1192,
      -1,    -1,   227,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1447,  1448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1500,
    1488,    -1,    -1,    -1,  1505,  1506,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1560,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1601,  1602
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   234,   235,   236,     0,    67,   243,   244,
     245,    14,   237,    15,   241,   242,    69,   272,   273,    10,
      11,   246,   247,   248,    10,    11,   238,   239,   240,    71,
     358,   359,    10,    11,   274,   275,   276,    68,    79,    81,
      82,    83,    85,    86,    87,    89,    90,    91,    93,    94,
      95,    97,    98,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   243,    73,   406,   407,
      10,    11,   360,   361,   362,    70,    99,   101,   103,   105,
     107,   109,   111,   113,   115,   117,   119,   277,   278,   279,
     280,   281,   286,   287,   292,   293,   298,   299,   306,   307,
     312,   313,   318,   319,   324,   325,   330,   331,   336,   337,
     344,   345,     5,     5,     5,     5,     5,    68,   251,   241,
      75,   434,   435,    10,    11,   408,   409,   410,    72,   119,
     123,   125,   127,   129,   363,   364,   365,   366,   367,   373,
     374,   380,   381,   387,   388,   392,   393,    70,   279,    10,
      11,   282,   283,   284,    10,    11,   288,   289,   290,    10,
      11,   294,   295,   296,    66,   300,   301,    10,    11,   308,
     309,   310,    10,    11,   314,   315,   316,    10,    11,   320,
     321,   322,    10,    11,   326,   327,   328,    10,    11,   332,
     333,   334,    65,   338,   339,    16,   346,   989,    80,    84,
      88,    92,    96,    77,   550,   551,    10,    11,   436,   437,
     438,    74,   119,   131,   411,   412,   413,   414,   415,   420,
     421,    72,   365,   368,   369,   375,   376,   382,   383,    46,
      50,   389,   931,   932,   933,   934,   394,   989,     4,   100,
     285,     4,   102,   291,     4,   104,   297,     3,    10,    11,
     302,   303,   304,     4,   108,   311,     4,   110,   317,     4,
     112,   323,     4,   114,   329,     4,   116,   335,     3,    10,
      11,   340,   341,   342,  1023,  1024,    10,    11,   347,   348,
     349,   552,   553,    76,   119,   133,   135,   137,   139,   141,
     147,   149,   151,   153,   155,   157,   159,   161,   163,   439,
     440,   441,   442,   443,   450,   451,   456,   457,   464,   465,
     469,   470,   474,   475,   479,   480,   484,   485,   492,   493,
     500,   501,   508,   509,   516,   517,   522,   523,   528,   529,
     536,   537,    74,   413,    10,    11,   416,   417,   418,   422,
     989,    10,   371,    45,    51,   370,   931,   971,   972,   973,
     974,    10,   378,   377,   931,   971,    10,   385,   384,   931,
     971,     3,    10,   390,    10,    11,   395,   396,   397,   100,
     102,   104,     8,     4,   106,   305,   108,   110,   112,   114,
     116,     8,     4,   118,   343,     6,     8,   229,   230,   231,
     232,  1025,   120,   121,   350,   351,   352,   353,    10,    11,
     555,   556,   557,    30,    31,    32,   554,   980,   986,   996,
      76,   441,   444,   971,    10,    11,   452,   453,   454,    18,
     458,   984,    19,   992,   992,   992,   992,    20,   486,   991,
     494,   991,   502,   991,   510,   991,   518,   992,   524,   992,
      27,   530,   993,   538,   989,     4,   132,   419,    10,    11,
     423,   424,   425,     6,     7,   372,  1022,     3,   379,  1022,
     386,  1022,  1023,     6,   391,   120,   121,   398,   399,   400,
     401,   106,   118,  1023,   120,   352,   354,   355,   167,   558,
     559,   560,  1023,  1023,  1023,    10,    11,   445,   446,   447,
       4,   136,   455,     8,    10,    11,   459,   460,   461,     8,
      10,    11,   466,   467,   468,    10,    11,   471,   472,   473,
      10,    11,   476,   477,   478,    10,    11,   481,   482,   483,
       8,    10,    11,   487,   488,   489,    10,    11,   495,   496,
     497,    10,    11,   503,   504,   505,    10,    11,   511,   512,
     513,    10,    11,   519,   520,   521,    10,    11,   525,   526,
     527,     8,    10,    11,   531,   532,   533,    10,    11,   539,
     540,   541,   132,   120,   121,   426,   427,   428,   429,   124,
       8,   126,   128,   130,   120,   400,   402,   403,    10,    11,
     357,    41,    44,    48,    52,   356,   931,   948,   949,   950,
     951,   975,   976,   977,   978,    78,   195,   690,   691,    33,
     561,   562,   990,     6,     6,     6,   134,   448,   449,  1022,
     136,     6,   107,   138,   462,   463,     6,   140,   143,   916,
     917,   142,   916,   148,   916,   150,   916,     6,   145,   156,
     490,   491,   918,   919,   158,   498,   499,   918,   162,   506,
     507,   918,   160,   514,   515,   918,   154,   916,   152,   916,
       6,   164,   165,   534,   535,   120,   121,   542,   543,   544,
     545,   120,   428,   430,   431,    10,    11,   405,   404,   931,
     948,   975,   122,     3,     3,   203,   792,   793,    34,   692,
     693,   988,  1023,    10,    11,   563,   564,   565,  1023,  1023,
    1023,   134,     8,    10,   138,   463,     8,    10,   140,   917,
     142,   148,   150,     8,   156,   491,   920,   921,   158,   499,
     162,   507,   160,   515,   154,   152,     8,    10,   164,   535,
     120,   544,   546,   547,    10,    11,   433,   432,   931,   948,
     975,   122,  1023,     8,   211,   894,   895,    35,   794,   795,
     987,  1023,    10,    11,   694,   695,   696,     6,   169,   566,
     567,   568,     4,     4,    10,    11,   926,    21,    22,    23,
     922,   923,   924,   925,     4,    10,    11,   549,   548,   931,
     948,   975,   122,    28,   896,   994,  1023,    10,    11,   796,
     797,   798,     6,   197,   697,   698,   699,  1023,   168,   173,
     581,   582,    37,   569,   995,   108,   144,   146,     3,     3,
       3,   166,   122,  1023,    10,    11,   897,   898,   899,     6,
     205,   799,   800,   801,  1023,   196,   201,   712,   713,    38,
     700,   985,   175,   595,   596,   583,   995,  1023,    10,    11,
     570,   571,   572,     8,     8,     8,     6,   900,  1023,   204,
     209,   814,   815,    39,   802,   979,   175,   726,   727,   714,
     985,  1023,    10,    11,   701,   702,   703,   189,   643,   644,
      10,    11,   597,   598,   599,    10,    11,   584,   585,   586,
       6,   170,   171,   573,   574,   575,   576,  1023,   212,   213,
     901,   902,   175,   828,   829,   816,   979,  1023,    10,    11,
     803,   804,   805,   774,    10,    11,   728,   729,   730,    10,
      11,   715,   716,   717,     6,   198,   199,   704,   705,   706,
     707,   191,   657,   658,   645,   995,   177,   600,   601,   602,
     171,   174,   587,   588,   589,   590,  1023,   170,   575,   577,
     578,    24,    25,    36,    47,    49,    61,    62,   903,   904,
     905,   927,   928,   929,   930,   931,   948,   952,   953,   954,
     955,   959,   960,   961,   962,   975,   983,   876,    10,    11,
     830,   831,   832,    10,    11,   817,   818,   819,     6,   206,
     207,   806,   807,   808,   809,   121,   775,   776,   177,   731,
     732,   733,   199,   202,   718,   719,   720,   721,  1023,   198,
     706,   708,   709,   672,    29,   659,    10,    11,   646,   647,
     648,   176,   181,   608,   609,    40,   603,   981,   174,   589,
     591,   592,    10,    11,   580,    42,   579,   937,   938,   939,
     948,   975,     3,     3,  1023,     3,    10,    11,   906,   907,
     908,   905,   121,   877,   878,   177,   833,   834,   835,   207,
     210,   820,   821,   822,   823,  1023,   206,   808,   810,   811,
     777,   778,   176,   181,   739,   740,   734,   981,   202,   720,
     722,   723,    10,    11,   711,   710,   937,   948,   975,   121,
     673,   674,     8,    10,    11,   660,   661,   662,   171,   190,
     649,   650,   651,   652,   179,   615,   616,   610,   981,  1023,
      10,    11,   604,   605,   606,    10,    11,   594,   593,   937,
     948,   975,   172,  1023,  1023,     8,     6,  1023,   214,   217,
     218,   220,   909,   910,   911,   912,   913,   914,   879,   880,
     176,   181,   841,   842,   836,   981,   210,   822,   824,   825,
      10,    11,   813,   812,   937,   948,   975,    10,    11,   780,
     781,   782,    17,   779,   927,   931,   948,   952,   959,   975,
     982,   985,   179,   746,   747,   741,   981,    10,    11,   735,
     736,   737,    10,    11,   725,    53,    54,    55,    56,   724,
     937,   940,   941,   942,   943,   948,   963,   964,   965,   966,
     200,   675,   676,     6,   192,   193,   663,   664,   665,   190,
     651,   653,   654,   185,   622,   623,   617,   981,    10,    11,
     611,   612,   613,     6,   221,   607,  1007,  1008,  1015,   172,
       6,  1023,     5,   915,   214,   911,    10,    11,   882,   883,
     884,   881,   927,   931,   948,   952,   959,   975,   979,   982,
     179,   848,   849,   843,   981,    10,    11,   837,   838,   839,
      10,    11,   827,    57,    58,    59,    60,   826,   937,   944,
     945,   946,   947,   948,   967,   968,   969,   970,   208,   122,
     199,   215,   783,   784,   785,   786,   997,   998,   999,  1023,
     185,   753,   754,   748,   981,    10,    11,   742,   743,   744,
     738,  1007,   200,     3,     3,    10,    11,   678,   679,   680,
     677,   927,   931,   948,   952,   959,   975,   982,   995,     8,
     192,   664,   666,   667,    10,    11,   656,   655,   937,   948,
     975,   183,   629,   630,   624,   981,    10,    11,   618,   619,
     620,   614,  1007,  1023,   225,  1016,   178,   226,  1009,  1010,
    1023,   219,   122,   207,   885,   886,   887,   888,   997,   185,
     855,   856,   850,   981,    10,    11,   844,   845,   846,   840,
    1007,   208,  1023,  1023,   122,   785,   787,   788,   998,  1000,
    1001,     6,   183,   760,   761,   755,   981,    10,    11,   749,
     750,   751,   745,  1007,   178,  1023,  1023,   122,   171,   681,
     682,   683,   684,   997,    10,    11,   669,   670,   671,    26,
      43,   668,   935,   936,   956,   957,   958,   995,   172,   187,
     636,   637,   631,   981,    10,    11,   625,   626,   627,   621,
    1007,   182,  1023,    10,    11,  1017,  1018,  1019,  1011,  1012,
     122,   887,   889,   890,   183,   862,   863,   857,   981,    10,
      11,   851,   852,   853,   847,  1007,   178,  1022,  1022,    10,
      11,   790,   791,   789,   937,   940,   948,   963,   975,    10,
      11,  1003,  1004,  1005,   931,   975,   981,  1002,  1023,   187,
     767,   768,   762,   981,    10,    11,   756,   757,   758,   752,
    1007,   182,   122,   683,   685,   686,   194,   650,     8,  1023,
     638,   981,    10,    11,   632,   633,   634,   628,  1007,   180,
       6,     4,   222,    10,  1014,   223,   224,  1013,  1020,  1021,
      10,    11,   892,   893,   891,   937,   940,   948,   963,   975,
     187,   869,   870,   864,   981,    10,    11,   858,   859,   860,
     854,  1007,   182,  1023,  1023,   200,  1006,  1007,   769,   981,
      10,    11,   763,   764,   765,   759,  1007,   180,    10,    11,
     688,   689,   687,   937,   940,   948,   963,   975,   194,  1022,
       6,    10,    11,   639,   640,   641,   635,  1007,   186,  1023,
     222,     6,  1023,  1023,   208,   871,   981,    10,    11,   865,
     866,   867,   861,  1007,   180,   216,    10,    11,   770,   771,
     772,   766,  1007,   186,   172,     8,  1023,   642,  1007,   184,
     227,     6,     6,    10,    11,   872,   873,   874,   868,  1007,
     186,   773,  1007,   184,   188,  1023,  1023,   875,  1007,   184,
     188,   188
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
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables isFree failed");	
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
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");	
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
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables unknown failed");	
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

  case 612:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 613:

    {
	parserData->kounter = 0;
	parserData->idxArray = new         int[parserData->numberOfVar];
	parserData->namArray = new std::string[parserData->numberOfVar];
	parserData->valArray = new      double[parserData->numberOfVar];
	for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 614:

    {
		if (parserData->numberOfVar > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <var> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 615:

    {
		if (parserData->kounter < parserData->numberOfVar)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <var> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 622:

    {
	parserData->kounter++;
}
    break;

  case 623:

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

  case 624:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 627:

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

  case 628:

    {
		if (!ignoreDataAfterErrors)
			parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 629:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		if (!ignoreDataAfterErrors)
			parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 633:

    {
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        
}
    break;

  case 634:

    {
	parserData->sosIdxAttributePresent = false;	
	parserData->currentSOS = 0;
}
    break;

  case 635:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <sos> elements must be nonnegative");
	parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
}
    break;

  case 636:

    {
		if (parserData->numberOfSOS > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <sos> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 637:

    {	if (parserData->currentSOS != parserData->numberOfSOS)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <sos> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 643:

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

  case 644:

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

  case 645:

    {
	if (!parserData->sosIdxAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index required");
	if (!parserData->numberOfVarAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar required");
}
    break;

  case 649:

    {
		parserData->kounter = 0;
		parserData->idxArray = new         int[parserData->numberOfVar];
		parserData->namArray = new std::string[parserData->numberOfVar];
		parserData->valArray = new      double[parserData->numberOfVar];
		for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
		parserData->numberOfVarAttributePresent = true;
	}
    break;

  case 658:

    { 	 
		parserData->iOther++;
	}
    break;

  case 659:

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

  case 660:

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

  case 663:

    {
		parserData->kounter = 0;
	}
    break;

  case 664:

    {
		parserData->kounter = 0;
	}
    break;

  case 680:

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

  case 681:

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

  case 685:

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

  case 695:

    {
	parserData->numberOfOtherObjectiveOptions = 0; 
	osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 696:

    {	
	if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
}
    break;

  case 698:

    {	
	parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
}
    break;

  case 703:

    {
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        

}
    break;

  case 705:

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

  case 706:

    {
	parserData->numberOfObjAttributePresent = false;
}
    break;

  case 707:

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

  case 708:

    {	
		if (parserData->numberOfObj > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: expected at least one <obj> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 709:

    {
		if (parserData->kounter < parserData->numberOfObj)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: fewer <obj> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 716:

    {
	parserData->kounter++;
}
    break;

  case 717:

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

  case 721:

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

  case 722:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 723:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 727:

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

  case 728:

    {
	parserData->numberOfObjAttributePresent = false;
}
    break;

  case 729:

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

  case 730:

    {
		if (parserData->numberOfObj > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: expected at least one <obj> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 731:

    {
		if (parserData->kounter < parserData->numberOfObj)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 738:

    {
	parserData->kounter++;
}
    break;

  case 739:

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

  case 743:

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

  case 744:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 745:

    {
		if (parserData->lbValueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
	}
    break;

  case 746:

    {
		if (parserData->ubValueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
	}
    break;

  case 751:

    {
	osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
}
    break;

  case 758:

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

  case 759:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 760:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 767:

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
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atUpper failed");	
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
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives isFree failed");	
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
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives superbasic failed");	
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
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives unknown failed");	
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

  case 813:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 814:

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

  case 815:

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

  case 818:

    {
		parserData->kounter = 0;
	}
    break;

  case 819:

    {
		parserData->kounter = 0;
	}
    break;

  case 835:

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

  case 836:

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

  case 837:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	parserData->valueString[parserData->kounter] = parserData->valueAttribute;
	parserData->lbValueString[parserData->kounter] = parserData->lbValueAttribute;
	parserData->ubValueString[parserData->kounter] = parserData->ubValueAttribute;
}
    break;

  case 840:

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

  case 850:

    {
	parserData->numberOfOtherConstraintOptions = 0; 
	osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 851:

    {	
	if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherConstraintOptions failed");
	parserData->iOther = 0;
}
    break;

  case 853:

    {	
	parserData->numberOfOtherConstraintOptions = parserData->tempInt;
}
    break;

  case 858:

    {
    suppressFurtherErrorMessages = false;
    ignoreDataAfterErrors = false;        

}
    break;

  case 860:

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

  case 861:

    {
	parserData->numberOfConAttributePresent = false;
}
    break;

  case 862:

    {
	parserData->kounter = 0;
	parserData->idxArray = new         int[parserData->numberOfCon];
	parserData->namArray = new std::string[parserData->numberOfCon];
	parserData->valArray = new      double[parserData->numberOfCon];
	for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfCon; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 863:

    {
		if (parserData->numberOfCon > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: expected at least one <con element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 864:

    {
		if (parserData->kounter < parserData->numberOfCon)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: fewer <con> elements than specified");
			ignoreDataAfterErrors = true;        
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

  case 873:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 876:

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

  case 877:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 878:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 882:

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

  case 883:

    {
	parserData->numberOfConAttributePresent = false;
}
    break;

  case 884:

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

  case 885:

    {
		if (parserData->numberOfCon > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: expected at least one <con> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 886:

    {
		if (parserData->kounter < parserData->numberOfCon)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: fewer <con> elements than specified");
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
	parserData->nameAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->lbValueAttributePresent = false;
	parserData->ubValueAttributePresent = false;
	parserData->lbDualValue = OSNaN();
	parserData->ubDualValue = OSNaN();
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
		parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
	}
    break;

  case 901:

    {
		parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
	}
    break;

  case 906:

    {
	osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
}
    break;

  case 913:

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

  case 914:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 915:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 922:

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

  case 923:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 924:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 931:

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
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks isFree failed");	
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
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");	
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
		if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks unknown failed");	
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

  case 968:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 969:

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

  case 970:

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

  case 973:

    {
		parserData->kounter = 0;
	}
    break;

  case 974:

    {
		parserData->kounter = 0;
	}
    break;

  case 990:

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

  case 991:

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

  case 995:

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

  case 1004:

    {
        suppressFurtherErrorMessages = false;
        ignoreDataAfterErrors = false;        
    }
    break;

  case 1006:

    {
	if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfSolverOptions failed");
	parserData->iOption = 0;
}
    break;

  case 1007:

    {
		if (parserData->numberOfSolverOptions > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <solverOption> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1008:

    {
		if (parserData->iOption != parserData->numberOfSolverOptions)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <solverOption> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1013:

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

  case 1014:

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

  case 1015:

    {
	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "name attribute must be present");
}
    break;

  case 1024:

    {
			parserData->itemList = new std::string[parserData->numberOfItems];
    }
    break;

  case 1025:

    {
		if (parserData->numberOfItems > 0)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <item> element");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1026:

    {
		if (parserData->kounter < parserData->numberOfItems)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <item> elements than specified");
			ignoreDataAfterErrors = true;        
		}
	}
    break;

  case 1033:

    {	
	parserData->itemList[parserData->kounter] = parserData->itemContent;
	parserData->kounter++;
}
    break;

  case 1034:

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

  case 1039:

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

  case 1042:

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

  case 1043:

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

  case 1044:

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

  case 1045:

    {
//	parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 1051:

    {
	if (parserData->pathPairFromPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"from\" attribute allowed");
	parserData->pathPairFromPresent = true;
	parserData->pathPairFrom = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1052:

    {
	if (parserData->pathPairToPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"to\" attribute allowed");
	parserData->pathPairToPresent = true;
	parserData->pathPairTo = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1053:

    {
	if (parserData->pathPairMakeCopyPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"makeCopy\" attribute allowed");
	parserData->pathPairMakeCopyPresent = true;
	parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1056:

    {   
	if (parserData->categoryAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one category attribute allowed for this element");
	parserData->categoryAttributePresent = true;
}
    break;

  case 1059:

    { 
	parserData->categoryAttribute = "";
}
    break;

  case 1060:

    { 
	parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1061:

    {
	if (parserData->descriptionAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one description attribute allowed for this element");
	parserData->descriptionAttributePresent = true;
}
    break;

  case 1064:

    { parserData->descriptionAttribute = ""; }
    break;

  case 1065:

    { 
	parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1066:

    {
	if (parserData->groupWeightAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one groupWeight attribute allowed for this element");
	parserData->groupWeightAttributePresent = true;
}
    break;

  case 1067:

    {
	parserData->groupWeight = parserData->tempVal;
}
    break;

  case 1068:

    {   
	if (parserData->idxAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one idx attribute allowed for this element");
	parserData->idxAttributePresent = true;
}
    break;

  case 1070:

    { 
	parserData->idxAttribute = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1071:

    {   
	if (parserData->lbValueAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
	parserData->lbValueAttributePresent = true;
}
    break;

  case 1074:

    { 
	parserData->lbValueAttribute = ""; 
}
    break;

  case 1075:

    { 
	parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1076:

    {   if (parserData->lbValueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
			parserData->lbValueAttributePresent = true;
		}
    break;

  case 1079:

    { 
    parserData->lbDualValue = 0.0; 
}
    break;

  case 1080:

    {
    parserData->lbDualValue = parserData->tempVal;
}
    break;

  case 1081:

    {
        if (parserData->nameAttributePresent ) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one name attribute allowed for this element");
		parserData->nameAttributePresent = true;
	}
    break;

  case 1084:

    { 
        parserData->nameAttribute = ""; 
    }
    break;

  case 1085:

    { 
	    parserData->nameAttribute = (yyvsp[(2) - (3)].sval); 
    	free((yyvsp[(2) - (3)].sval));
    }
    break;

  case 1086:

    {   if (parserData->solverAttributePresent ) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one solver attribute allowed for this element");
		parserData->solverAttributePresent = true;
	}
    break;

  case 1089:

    { parserData->solverAttribute = ""; }
    break;

  case 1090:

    { 
	parserData->solverAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1091:

    {   if (parserData->sosIdxAttributePresent ) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one sosIdx attribute allowed for this element");
		parserData->sosIdxAttributePresent = true;
	}
    break;

  case 1093:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index must be nonnegative");
	parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1094:

    {   if (parserData->typeAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		}
    break;

  case 1097:

    { parserData->typeAttribute = ""; }
    break;

  case 1098:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1099:

    {
   if (parserData->ubValueAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
	parserData->ubValueAttributePresent = true;
}
    break;

  case 1102:

    { 
	parserData->ubValueAttribute = ""; 
}
    break;

  case 1103:

    { 
	parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1104:

    {   if (parserData->ubValueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
			parserData->ubValueAttributePresent = true;
		}
    break;

  case 1107:

    { parserData->ubDualValue = 0.0; }
    break;

  case 1108:

    { 
	parserData->ubDualValue = parserData->tempVal;
}
    break;

  case 1109:

    {   if (parserData->unitAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		}
    break;

  case 1112:

    { parserData->unitAttribute = ""; }
    break;

  case 1113:

    { 
	parserData->unitAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1114:

    {   if (parserData->valueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		}
    break;

  case 1117:

    { parserData->valueAttribute = ""; }
    break;

  case 1118:

    {
	parserData->valueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1119:

    {
	if (parserData->numberOfConAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfConAttributePresent = true;		
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1120:

    {
	if (parserData->numberOfConstraintsPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of constraints cannot be negative");
	parserData->numberOfConstraintsPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1121:

    {
	if (osglData->osglNumberOfElPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEl attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <el> cannot be negative");
	osglData->osglNumberOfElPresent = true;
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1122:

    {
	if (parserData->numberOfEnumerationsAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEnumerations attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerationsAttributePresent = true;		
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1123:

    {	
   if (parserData->numberOfItemsPresent ) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1124:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
    	parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
}
    break;

  case 1125:

    {
	if (parserData->numberOfObjAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObjAttributePresent = true;		
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1126:

    {
	if (parserData->numberOfObjectivesPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of objectives cannot be negative");
	parserData->numberOfObjectivesPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1127:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other constraint options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1128:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other objective options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1129:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1130:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other variable options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1131:

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

  case 1132:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of paths cannot be negative");
	else
		parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
}
    break;

  case 1133:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
    else
    	parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
}
    break;

  case 1134:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of solver options cannot be negative");
	parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1135:

    {
	if (parserData->numberOfVarAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVarAttributePresent = true;		
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1136:

    {	if (parserData->numberOfVariablesPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of variables cannot be negative");
	parserData->numberOfVariablesPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1139:

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

  case 1140:

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

  case 1141:

    {
		if(!osglData->osglNumberOfElPresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires numberOfEl attribute"); 
		if(!parserData->valueAttributePresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires value attribute"); 
	}
    break;

  case 1144:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfElPresent = true;
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 1152:

    {
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
		{
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer data elements than specified");
			ignoreDataAfterErrors = true;
		}
	}
    break;

  case 1157:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
}
    break;

  case 1163:

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

  case 1165:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1170:

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

  case 1171:

    {	
	if (osglData->osglIncrPresent) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1172:

    {	
	if (osglData->osglMultPresent) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1173:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1174:

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


