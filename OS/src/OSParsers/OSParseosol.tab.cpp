
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
#define YYLAST   1279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  805
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1197
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1652

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
      48,    50,    52,    56,    62,    63,    65,    67,    69,    71,
      73,    77,    78,    80,    82,    84,    86,    88,    92,    93,
      95,    97,    99,   101,   103,   107,   108,   110,   112,   114,
     116,   118,   122,   123,   125,   127,   129,   131,   133,   137,
     138,   141,   143,   145,   147,   150,   152,   156,   158,   160,
     163,   165,   167,   169,   171,   173,   175,   177,   179,   181,
     183,   185,   188,   190,   192,   194,   197,   199,   203,   205,
     208,   210,   212,   214,   217,   219,   223,   225,   228,   230,
     232,   234,   237,   239,   243,   245,   249,   251,   252,   254,
     258,   260,   262,   265,   267,   271,   273,   276,   278,   280,
     282,   285,   287,   291,   293,   296,   298,   300,   302,   305,
     307,   311,   313,   316,   318,   320,   322,   325,   327,   331,
     333,   336,   338,   340,   342,   345,   347,   351,   353,   356,
     358,   360,   362,   365,   367,   371,   373,   377,   379,   380,
     382,   386,   388,   390,   393,   395,   399,   401,   405,   407,
     409,   411,   413,   416,   418,   422,   424,   426,   429,   433,
     435,   437,   438,   441,   443,   445,   447,   450,   452,   453,
     456,   458,   460,   462,   465,   467,   471,   473,   475,   478,
     480,   482,   484,   486,   488,   492,   494,   496,   497,   500,
     502,   504,   508,   510,   514,   516,   518,   519,   522,   524,
     526,   530,   532,   536,   538,   540,   541,   544,   546,   548,
     552,   554,   558,   560,   561,   563,   567,   569,   573,   575,
     577,   579,   581,   584,   586,   590,   592,   594,   597,   601,
     603,   605,   606,   609,   611,   613,   615,   618,   620,   621,
     624,   626,   628,   630,   633,   635,   639,   641,   643,   646,
     648,   650,   653,   655,   657,   659,   662,   664,   668,   670,
     674,   676,   678,   680,   682,   685,   687,   691,   693,   695,
     698,   702,   704,   706,   707,   710,   712,   714,   716,   719,
     721,   722,   725,   727,   729,   731,   734,   736,   740,   742,
     744,   747,   749,   751,   753,   755,   757,   759,   761,   763,
     765,   767,   769,   771,   773,   775,   777,   781,   783,   784,
     786,   788,   790,   793,   795,   799,   801,   803,   806,   808,
     810,   812,   815,   817,   821,   823,   827,   829,   831,   833,
     835,   838,   840,   844,   846,   849,   854,   858,   860,   862,
     864,   866,   869,   871,   875,   877,   880,   885,   889,   891,
     893,   895,   897,   900,   902,   906,   908,   911,   916,   920,
     922,   924,   926,   928,   931,   933,   937,   939,   942,   947,
     951,   953,   955,   957,   959,   962,   964,   968,   970,   973,
     978,   982,   984,   986,   988,   990,   993,   995,   999,  1001,
    1004,  1006,  1010,  1012,  1014,  1016,  1018,  1021,  1023,  1027,
    1029,  1032,  1034,  1038,  1040,  1042,  1044,  1046,  1049,  1051,
    1055,  1057,  1060,  1062,  1066,  1068,  1070,  1072,  1074,  1077,
    1079,  1083,  1085,  1088,  1090,  1094,  1096,  1098,  1100,  1102,
    1105,  1107,  1111,  1113,  1116,  1121,  1125,  1127,  1129,  1131,
    1133,  1136,  1138,  1142,  1144,  1147,  1152,  1156,  1158,  1160,
    1162,  1164,  1167,  1169,  1173,  1175,  1178,  1183,  1187,  1189,
    1191,  1193,  1195,  1198,  1200,  1204,  1206,  1208,  1211,  1215,
    1217,  1219,  1220,  1223,  1225,  1227,  1229,  1232,  1234,  1235,
    1239,  1241,  1243,  1244,  1247,  1249,  1251,  1253,  1255,  1257,
    1259,  1263,  1268,  1269,  1273,  1275,  1277,  1278,  1280,  1282,
    1284,  1286,  1290,  1297,  1298,  1302,  1304,  1306,  1308,  1310,
    1313,  1315,  1319,  1321,  1323,  1326,  1330,  1332,  1334,  1335,
    1338,  1340,  1342,  1344,  1347,  1349,  1350,  1354,  1356,  1358,
    1360,  1362,  1365,  1367,  1371,  1373,  1375,  1378,  1382,  1384,
    1386,  1387,  1390,  1392,  1394,  1396,  1399,  1401,  1402,  1405,
    1407,  1409,  1411,  1413,  1417,  1424,  1425,  1429,  1431,  1433,
    1435,  1437,  1439,  1443,  1445,  1446,  1450,  1452,  1454,  1456,
    1458,  1460,  1464,  1466,  1467,  1471,  1473,  1475,  1477,  1479,
    1481,  1485,  1487,  1488,  1492,  1494,  1496,  1498,  1500,  1502,
    1506,  1508,  1509,  1513,  1515,  1517,  1519,  1521,  1523,  1527,
    1529,  1530,  1534,  1536,  1538,  1540,  1542,  1544,  1548,  1550,
    1551,  1555,  1557,  1559,  1561,  1563,  1566,  1568,  1572,  1574,
    1576,  1579,  1583,  1585,  1587,  1588,  1591,  1593,  1595,  1597,
    1600,  1602,  1603,  1607,  1609,  1614,  1616,  1618,  1621,  1623,
    1627,  1629,  1632,  1636,  1638,  1640,  1641,  1644,  1646,  1648,
    1650,  1652,  1654,  1657,  1659,  1663,  1664,  1667,  1671,  1673,
    1675,  1676,  1679,  1681,  1683,  1685,  1687,  1689,  1691,  1693,
    1695,  1697,  1699,  1702,  1704,  1708,  1710,  1712,  1714,  1717,
    1721,  1723,  1725,  1726,  1729,  1731,  1733,  1735,  1737,  1739,
    1741,  1744,  1746,  1747,  1751,  1753,  1755,  1756,  1758,  1760,
    1762,  1764,  1768,  1773,  1774,  1778,  1780,  1782,  1784,  1786,
    1789,  1791,  1795,  1797,  1799,  1802,  1806,  1808,  1810,  1811,
    1814,  1816,  1818,  1820,  1823,  1825,  1826,  1830,  1832,  1834,
    1836,  1838,  1841,  1843,  1847,  1849,  1851,  1854,  1858,  1860,
    1862,  1863,  1866,  1868,  1870,  1872,  1874,  1877,  1879,  1880,
    1883,  1885,  1887,  1889,  1891,  1895,  1902,  1903,  1907,  1909,
    1911,  1913,  1915,  1917,  1921,  1923,  1924,  1928,  1930,  1932,
    1934,  1936,  1938,  1942,  1944,  1945,  1949,  1951,  1953,  1955,
    1957,  1959,  1963,  1965,  1966,  1970,  1972,  1974,  1976,  1978,
    1980,  1984,  1986,  1987,  1991,  1993,  1995,  1997,  1999,  2001,
    2005,  2007,  2008,  2012,  2014,  2016,  2018,  2020,  2022,  2026,
    2028,  2029,  2032,  2036,  2038,  2040,  2041,  2044,  2046,  2048,
    2050,  2052,  2054,  2056,  2058,  2060,  2062,  2064,  2067,  2069,
    2073,  2075,  2077,  2079,  2082,  2086,  2088,  2090,  2091,  2094,
    2096,  2098,  2100,  2102,  2104,  2106,  2109,  2111,  2112,  2116,
    2118,  2120,  2121,  2123,  2125,  2127,  2129,  2133,  2138,  2139,
    2143,  2145,  2147,  2149,  2151,  2154,  2156,  2160,  2162,  2164,
    2167,  2171,  2173,  2175,  2176,  2179,  2181,  2183,  2185,  2188,
    2190,  2191,  2195,  2197,  2199,  2201,  2203,  2206,  2208,  2212,
    2214,  2216,  2219,  2223,  2225,  2227,  2228,  2231,  2233,  2235,
    2237,  2239,  2242,  2244,  2245,  2248,  2250,  2252,  2254,  2256,
    2260,  2267,  2268,  2272,  2274,  2276,  2278,  2280,  2282,  2286,
    2288,  2289,  2293,  2295,  2297,  2299,  2301,  2303,  2307,  2309,
    2310,  2314,  2316,  2318,  2320,  2322,  2324,  2328,  2330,  2331,
    2335,  2337,  2339,  2341,  2343,  2345,  2349,  2351,  2352,  2356,
    2358,  2360,  2362,  2364,  2366,  2370,  2372,  2373,  2377,  2379,
    2381,  2383,  2385,  2387,  2391,  2393,  2394,  2397,  2401,  2403,
    2405,  2406,  2409,  2411,  2413,  2415,  2417,  2419,  2421,  2423,
    2425,  2427,  2429,  2432,  2434,  2438,  2440,  2442,  2444,  2447,
    2451,  2453,  2455,  2456,  2459,  2461,  2463,  2465,  2467,  2469,
    2471,  2474,  2476,  2477,  2481,  2483,  2485,  2487,  2489,  2491,
    2495,  2496,  2499,  2503,  2505,  2507,  2509,  2512,  2514,  2516,
    2518,  2520,  2522,  2524,  2526,  2528,  2530,  2533,  2535,  2539,
    2541,  2543,  2546,  2548,  2550,  2552,  2554,  2556,  2560,  2562,
    2566,  2568,  2570,  2571,  2574,  2576,  2578,  2580,  2584,  2588,
    2592,  2595,  2597,  2599,  2601,  2603,  2605,  2609,  2611,  2613,
    2615,  2617,  2621,  2623,  2628,  2630,  2632,  2637,  2639,  2641,
    2643,  2645,  2649,  2651,  2653,  2655,  2657,  2662,  2664,  2666,
    2668,  2670,  2674,  2676,  2678,  2680,  2682,  2686,  2688,  2690,
    2695,  2697,  2699,  2701,  2703,  2707,  2709,  2711,  2713,  2715,
    2719,  2721,  2723,  2725,  2727,  2732,  2734,  2736,  2738,  2740,
    2744,  2746,  2748,  2750,  2752,  2756,  2761,  2766,  2771,  2776,
    2781,  2786,  2791,  2796,  2801,  2806,  2811,  2816,  2821,  2826,
    2831,  2836,  2841,  2846,  2848,  2851,  2855,  2857,  2859,  2860,
    2863,  2865,  2867,  2869,  2871,  2873,  2875,  2879,  2881,  2883,
    2885,  2886,  2889,  2893,  2895,  2897,  2898,  2901,  2903,  2905,
    2909,  2913,  2918,  2920,  2922,  2925,  2927,  2931,  2936,  2941,
    2943,  2945,  2948,  2949,  2952,  2954,  2956,  2958
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     234,     0,    -1,   235,   243,   241,    -1,   236,   237,   238,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   239,    -1,
     240,    -1,    11,    -1,    10,   243,   241,    -1,   242,    -1,
      15,    -1,    -1,   244,   270,   356,   404,   432,   564,    -1,
      -1,   245,   246,    -1,    67,    -1,   247,    -1,   248,    -1,
      11,    -1,    10,   249,    68,    -1,   250,   254,   258,   262,
     266,    -1,    -1,   251,    -1,   252,    -1,   253,    -1,    82,
      -1,    81,    -1,    79,     5,    80,    -1,    -1,   255,    -1,
     256,    -1,   257,    -1,    86,    -1,    85,    -1,    83,     5,
      84,    -1,    -1,   259,    -1,   260,    -1,   261,    -1,    90,
      -1,    89,    -1,    87,     5,    88,    -1,    -1,   263,    -1,
     264,    -1,   265,    -1,    94,    -1,    93,    -1,    91,     5,
      92,    -1,    -1,   267,    -1,   268,    -1,   269,    -1,    98,
      -1,    97,    -1,    95,     5,    96,    -1,    -1,   271,   272,
      -1,    69,    -1,   273,    -1,   274,    -1,    10,    70,    -1,
      11,    -1,    10,   275,    70,    -1,   276,    -1,   277,    -1,
     276,   277,    -1,   278,    -1,   284,    -1,   290,    -1,   296,
      -1,   304,    -1,   310,    -1,   316,    -1,   322,    -1,   328,
      -1,   334,    -1,   342,    -1,   279,   280,    -1,    99,    -1,
     281,    -1,   282,    -1,    10,   100,    -1,    11,    -1,    10,
     283,   100,    -1,     4,    -1,   285,   286,    -1,   101,    -1,
     287,    -1,   288,    -1,    10,   102,    -1,    11,    -1,    10,
     289,   102,    -1,     4,    -1,   291,   292,    -1,   103,    -1,
     293,    -1,   294,    -1,    10,   104,    -1,    11,    -1,    10,
     295,   104,    -1,     4,    -1,   297,   298,   300,    -1,   105,
      -1,    -1,   299,    -1,    66,     3,     8,    -1,   301,    -1,
     302,    -1,    10,   106,    -1,    11,    -1,    10,   303,   106,
      -1,     4,    -1,   305,   306,    -1,   107,    -1,   307,    -1,
     308,    -1,    10,   108,    -1,    11,    -1,    10,   309,   108,
      -1,     4,    -1,   311,   312,    -1,   109,    -1,   313,    -1,
     314,    -1,    10,   110,    -1,    11,    -1,    10,   315,   110,
      -1,     4,    -1,   317,   318,    -1,   111,    -1,   319,    -1,
     320,    -1,    10,   112,    -1,    11,    -1,    10,   321,   112,
      -1,     4,    -1,   323,   324,    -1,   113,    -1,   325,    -1,
     326,    -1,    10,   114,    -1,    11,    -1,    10,   327,   114,
      -1,     4,    -1,   329,   330,    -1,   115,    -1,   331,    -1,
     332,    -1,    10,   116,    -1,    11,    -1,    10,   333,   116,
      -1,     4,    -1,   335,   336,   338,    -1,   117,    -1,    -1,
     337,    -1,    65,     3,     8,    -1,   339,    -1,   340,    -1,
      10,   118,    -1,    11,    -1,    10,   341,   118,    -1,     4,
      -1,   343,   344,   345,    -1,   119,    -1,  1001,    -1,   346,
      -1,   347,    -1,    10,   120,    -1,    11,    -1,    10,   348,
     120,    -1,   349,    -1,   350,    -1,   349,   350,    -1,   351,
     352,   355,    -1,   121,    -1,   353,    -1,    -1,   353,   354,
      -1,   960,    -1,   987,    -1,   943,    -1,    10,   122,    -1,
      11,    -1,    -1,   357,   358,    -1,    71,    -1,   359,    -1,
     360,    -1,    10,    72,    -1,    11,    -1,    10,   361,    72,
      -1,   362,    -1,   363,    -1,   362,   363,    -1,   364,    -1,
     371,    -1,   378,    -1,   385,    -1,   390,    -1,   365,   366,
     369,    -1,   123,    -1,   367,    -1,    -1,   367,   368,    -1,
     983,    -1,   943,    -1,    10,   370,   124,    -1,  1034,    -1,
     372,   373,   376,    -1,   125,    -1,   374,    -1,    -1,   374,
     375,    -1,   983,    -1,   943,    -1,    10,   377,   126,    -1,
    1034,    -1,   379,   380,   383,    -1,   127,    -1,   381,    -1,
      -1,   381,   382,    -1,   983,    -1,   943,    -1,    10,   384,
     128,    -1,  1034,    -1,   386,   387,   388,    -1,   129,    -1,
      -1,   943,    -1,    10,   389,   130,    -1,     6,    -1,   391,
     392,   393,    -1,   119,    -1,  1001,    -1,   394,    -1,   395,
      -1,    10,   120,    -1,    11,    -1,    10,   396,   120,    -1,
     397,    -1,   398,    -1,   397,   398,    -1,   399,   400,   403,
      -1,   121,    -1,   401,    -1,    -1,   401,   402,    -1,   960,
      -1,   987,    -1,   943,    -1,    10,   122,    -1,    11,    -1,
      -1,   405,   406,    -1,    73,    -1,   407,    -1,   408,    -1,
      10,    74,    -1,    11,    -1,    10,   409,    74,    -1,   410,
      -1,   411,    -1,   410,   411,    -1,   412,    -1,   418,    -1,
     413,   414,    -1,   131,    -1,   415,    -1,   416,    -1,    10,
     132,    -1,    11,    -1,    10,   417,   132,    -1,     4,    -1,
     419,   420,   421,    -1,   119,    -1,  1001,    -1,   422,    -1,
     423,    -1,    10,   120,    -1,    11,    -1,    10,   424,   120,
      -1,   425,    -1,   426,    -1,   425,   426,    -1,   427,   428,
     431,    -1,   121,    -1,   429,    -1,    -1,   429,   430,    -1,
     960,    -1,   987,    -1,   943,    -1,    10,   122,    -1,    11,
      -1,    -1,   433,   434,    -1,    75,    -1,   435,    -1,   436,
      -1,    10,    76,    -1,    11,    -1,    10,   437,    76,    -1,
     438,    -1,   439,    -1,   438,   439,    -1,   440,    -1,   448,
      -1,   454,    -1,   462,    -1,   470,    -1,   478,    -1,   486,
      -1,   494,    -1,   502,    -1,   518,    -1,   510,    -1,   526,
      -1,   534,    -1,   542,    -1,   550,    -1,   441,   442,   443,
      -1,   133,    -1,    -1,   983,    -1,   444,    -1,   445,    -1,
      10,   134,    -1,    11,    -1,    10,   446,   134,    -1,   447,
      -1,  1034,    -1,   449,   450,    -1,   135,    -1,   451,    -1,
     452,    -1,    10,   136,    -1,    11,    -1,    10,   453,   136,
      -1,     4,    -1,   455,   456,   457,    -1,   137,    -1,   996,
      -1,   458,    -1,   459,    -1,    10,   138,    -1,    11,    -1,
      10,   460,   138,    -1,   461,    -1,   460,   461,    -1,   107,
      10,     4,   108,    -1,   463,   464,   465,    -1,   139,    -1,
    1004,    -1,   466,    -1,   467,    -1,    10,   140,    -1,    11,
      -1,    10,   468,   140,    -1,   469,    -1,   468,   469,    -1,
     143,    10,     4,   144,    -1,   471,   472,   473,    -1,   141,
      -1,  1004,    -1,   474,    -1,   475,    -1,    10,   142,    -1,
      11,    -1,    10,   476,   142,    -1,   477,    -1,   476,   477,
      -1,   143,    10,     4,   144,    -1,   479,   480,   481,    -1,
     147,    -1,  1004,    -1,   482,    -1,   483,    -1,    10,   148,
      -1,    11,    -1,    10,   484,   148,    -1,   485,    -1,   484,
     485,    -1,   143,    10,     4,   144,    -1,   487,   488,   489,
      -1,   149,    -1,  1004,    -1,   490,    -1,   491,    -1,    10,
     150,    -1,    11,    -1,    10,   492,   150,    -1,   493,    -1,
     492,   493,    -1,   143,    10,     4,   144,    -1,   495,   496,
     497,    -1,   155,    -1,  1003,    -1,   498,    -1,   499,    -1,
      10,   156,    -1,    11,    -1,    10,   500,   156,    -1,   501,
      -1,   500,   501,    -1,   930,    -1,   503,   504,   505,    -1,
     157,    -1,  1003,    -1,   506,    -1,   507,    -1,    10,   158,
      -1,    11,    -1,    10,   508,   158,    -1,   509,    -1,   508,
     509,    -1,   930,    -1,   511,   512,   513,    -1,   161,    -1,
    1003,    -1,   514,    -1,   515,    -1,    10,   162,    -1,    11,
      -1,    10,   516,   162,    -1,   517,    -1,   516,   517,    -1,
     930,    -1,   519,   520,   521,    -1,   159,    -1,  1003,    -1,
     522,    -1,   523,    -1,    10,   160,    -1,    11,    -1,    10,
     524,   160,    -1,   525,    -1,   524,   525,    -1,   930,    -1,
     527,   528,   529,    -1,   153,    -1,  1004,    -1,   530,    -1,
     531,    -1,    10,   154,    -1,    11,    -1,    10,   532,   154,
      -1,   533,    -1,   532,   533,    -1,   143,    10,     4,   144,
      -1,   535,   536,   537,    -1,   151,    -1,  1004,    -1,   538,
      -1,   539,    -1,    10,   152,    -1,    11,    -1,    10,   540,
     152,    -1,   541,    -1,   540,   541,    -1,   143,    10,     4,
     144,    -1,   543,   544,   545,    -1,   163,    -1,  1005,    -1,
     546,    -1,   547,    -1,    10,   164,    -1,    11,    -1,    10,
     548,   164,    -1,   549,    -1,   548,   549,    -1,   165,    10,
       4,   166,    -1,   551,   552,   553,    -1,   119,    -1,  1001,
      -1,   554,    -1,   555,    -1,    10,   120,    -1,    11,    -1,
      10,   556,   120,    -1,   557,    -1,   558,    -1,   557,   558,
      -1,   559,   560,   563,    -1,   121,    -1,   561,    -1,    -1,
     561,   562,    -1,   960,    -1,   987,    -1,   943,    -1,    10,
     122,    -1,    11,    -1,    -1,   565,   566,   569,    -1,    77,
      -1,   567,    -1,    -1,   567,   568,    -1,  1008,    -1,   992,
      -1,   998,    -1,   570,    -1,   571,    -1,    11,    -1,    10,
     572,    78,    -1,   573,   704,   806,   908,    -1,    -1,   574,
     575,   577,    -1,   167,    -1,   576,    -1,    -1,  1002,    -1,
     578,    -1,   579,    -1,    11,    -1,    10,   580,   168,    -1,
     581,   595,   609,   657,   671,   686,    -1,    -1,   582,   583,
     584,    -1,   169,    -1,  1007,    -1,   585,    -1,   586,    -1,
      10,   170,    -1,    11,    -1,    10,   587,   170,    -1,   588,
      -1,   589,    -1,   588,   589,    -1,   590,   591,   594,    -1,
     171,    -1,   592,    -1,    -1,   592,   593,    -1,   949,    -1,
     960,    -1,   987,    -1,    10,   172,    -1,    11,    -1,    -1,
     596,   597,   598,    -1,   173,    -1,  1007,    -1,   599,    -1,
     600,    -1,    10,   174,    -1,    11,    -1,    10,   601,   174,
      -1,   602,    -1,   603,    -1,   602,   603,    -1,   604,   605,
     608,    -1,   171,    -1,   606,    -1,    -1,   606,   607,    -1,
     949,    -1,   960,    -1,   987,    -1,    10,   172,    -1,    11,
      -1,    -1,   610,   611,    -1,   175,    -1,   612,    -1,   613,
      -1,    11,    -1,    10,   614,   176,    -1,   615,   622,   629,
     636,   643,   650,    -1,    -1,   616,   617,   618,    -1,   177,
      -1,   993,    -1,   619,    -1,   620,    -1,    11,    -1,    10,
     621,   178,    -1,  1019,    -1,    -1,   623,   624,   625,    -1,
     181,    -1,   993,    -1,   626,    -1,   627,    -1,    11,    -1,
      10,   628,   182,    -1,  1019,    -1,    -1,   630,   631,   632,
      -1,   179,    -1,   993,    -1,   633,    -1,   634,    -1,    11,
      -1,    10,   635,   180,    -1,  1019,    -1,    -1,   637,   638,
     639,    -1,   185,    -1,   993,    -1,   640,    -1,   641,    -1,
      11,    -1,    10,   642,   186,    -1,  1019,    -1,    -1,   644,
     645,   646,    -1,   183,    -1,   993,    -1,   647,    -1,   648,
      -1,    11,    -1,    10,   649,   184,    -1,  1019,    -1,    -1,
     651,   652,   653,    -1,   187,    -1,   993,    -1,   654,    -1,
     655,    -1,    11,    -1,    10,   656,   188,    -1,  1019,    -1,
      -1,   658,   659,   660,    -1,   189,    -1,  1007,    -1,   661,
      -1,   662,    -1,    10,   190,    -1,    11,    -1,    10,   663,
     190,    -1,   664,    -1,   665,    -1,   664,   665,    -1,   666,
     667,   670,    -1,   171,    -1,   668,    -1,    -1,   668,   669,
      -1,   949,    -1,   960,    -1,   987,    -1,    10,   172,    -1,
      11,    -1,    -1,   672,   673,   674,    -1,   191,    -1,    29,
       8,     6,     8,    -1,   675,    -1,   676,    -1,    10,   192,
      -1,    11,    -1,    10,   677,   192,    -1,   678,    -1,   677,
     678,    -1,   679,   680,   683,    -1,   193,    -1,   681,    -1,
      -1,   681,   682,    -1,   968,    -1,  1007,    -1,   947,    -1,
     684,    -1,   685,    -1,    10,   194,    -1,    11,    -1,    10,
     664,   194,    -1,    -1,   686,   687,    -1,   688,   689,   692,
      -1,   121,    -1,   690,    -1,    -1,   690,   691,    -1,  1007,
      -1,   994,    -1,   960,    -1,   987,    -1,   964,    -1,   939,
      -1,   971,    -1,   943,    -1,   693,    -1,   694,    -1,    10,
     122,    -1,    11,    -1,    10,   695,   122,    -1,   696,    -1,
    1009,    -1,   697,    -1,   696,   697,    -1,   698,   699,   702,
      -1,   171,    -1,   700,    -1,    -1,   700,   701,    -1,   949,
      -1,   960,    -1,   987,    -1,   952,    -1,   975,    -1,   703,
      -1,    10,   172,    -1,    11,    -1,    -1,   705,   706,   708,
      -1,   195,    -1,   707,    -1,    -1,  1000,    -1,   709,    -1,
     710,    -1,    11,    -1,    10,   711,   196,    -1,   712,   726,
     740,   788,    -1,    -1,   713,   714,   715,    -1,   197,    -1,
     997,    -1,   716,    -1,   717,    -1,    10,   198,    -1,    11,
      -1,    10,   718,   198,    -1,   719,    -1,   720,    -1,   719,
     720,    -1,   721,   722,   725,    -1,   199,    -1,   723,    -1,
      -1,   723,   724,    -1,   949,    -1,   960,    -1,   987,    -1,
      10,   200,    -1,    11,    -1,    -1,   727,   728,   729,    -1,
     201,    -1,   997,    -1,   730,    -1,   731,    -1,    10,   202,
      -1,    11,    -1,    10,   732,   202,    -1,   733,    -1,   734,
      -1,   733,   734,    -1,   735,   736,   739,    -1,   199,    -1,
     737,    -1,    -1,   737,   738,    -1,   949,    -1,   960,    -1,
     952,    -1,   975,    -1,    10,   200,    -1,    11,    -1,    -1,
     741,   742,    -1,   175,    -1,   743,    -1,   744,    -1,    11,
      -1,    10,   745,   176,    -1,   746,   753,   760,   767,   774,
     781,    -1,    -1,   747,   748,   749,    -1,   177,    -1,   993,
      -1,   750,    -1,   751,    -1,    11,    -1,    10,   752,   178,
      -1,  1019,    -1,    -1,   754,   755,   756,    -1,   181,    -1,
     993,    -1,   757,    -1,   758,    -1,    11,    -1,    10,   759,
     182,    -1,  1019,    -1,    -1,   761,   762,   763,    -1,   179,
      -1,   993,    -1,   764,    -1,   765,    -1,    11,    -1,    10,
     766,   180,    -1,  1019,    -1,    -1,   768,   769,   770,    -1,
     185,    -1,   993,    -1,   771,    -1,   772,    -1,    11,    -1,
      10,   773,   186,    -1,  1019,    -1,    -1,   775,   776,   777,
      -1,   183,    -1,   993,    -1,   778,    -1,   779,    -1,    11,
      -1,    10,   780,   184,    -1,  1019,    -1,    -1,   782,   783,
     784,    -1,   187,    -1,   993,    -1,   785,    -1,   786,    -1,
      11,    -1,    10,   787,   188,    -1,  1019,    -1,    -1,   788,
     789,    -1,   790,   791,   794,    -1,   121,    -1,   792,    -1,
      -1,   792,   793,    -1,   997,    -1,   994,    -1,   960,    -1,
     987,    -1,   964,    -1,   939,    -1,   971,    -1,   943,    -1,
     795,    -1,   796,    -1,    10,   122,    -1,    11,    -1,    10,
     797,   122,    -1,   798,    -1,  1009,    -1,   799,    -1,   798,
     799,    -1,   800,   801,   804,    -1,   199,    -1,   802,    -1,
      -1,   802,   803,    -1,   949,    -1,   960,    -1,   987,    -1,
     952,    -1,   975,    -1,   805,    -1,    10,   200,    -1,    11,
      -1,    -1,   807,   808,   810,    -1,   203,    -1,   809,    -1,
      -1,   999,    -1,   811,    -1,   812,    -1,    11,    -1,    10,
     813,   204,    -1,   814,   828,   842,   890,    -1,    -1,   815,
     816,   817,    -1,   205,    -1,   991,    -1,   818,    -1,   819,
      -1,    10,   206,    -1,    11,    -1,    10,   820,   206,    -1,
     821,    -1,   822,    -1,   821,   822,    -1,   823,   824,   827,
      -1,   207,    -1,   825,    -1,    -1,   825,   826,    -1,   949,
      -1,   960,    -1,   987,    -1,    10,   208,    -1,    11,    -1,
      -1,   829,   830,   831,    -1,   209,    -1,   991,    -1,   832,
      -1,   833,    -1,    10,   210,    -1,    11,    -1,    10,   834,
     210,    -1,   835,    -1,   836,    -1,   835,   836,    -1,   837,
     838,   841,    -1,   207,    -1,   839,    -1,    -1,   839,   840,
      -1,   949,    -1,   960,    -1,   956,    -1,   979,    -1,    10,
     208,    -1,    11,    -1,    -1,   843,   844,    -1,   175,    -1,
     845,    -1,   846,    -1,    11,    -1,    10,   847,   176,    -1,
     848,   855,   862,   869,   876,   883,    -1,    -1,   849,   850,
     851,    -1,   177,    -1,   993,    -1,   852,    -1,   853,    -1,
      11,    -1,    10,   854,   178,    -1,  1019,    -1,    -1,   856,
     857,   858,    -1,   181,    -1,   993,    -1,   859,    -1,   860,
      -1,    11,    -1,    10,   861,   182,    -1,  1019,    -1,    -1,
     863,   864,   865,    -1,   179,    -1,   993,    -1,   866,    -1,
     867,    -1,    11,    -1,    10,   868,   180,    -1,  1019,    -1,
      -1,   870,   871,   872,    -1,   185,    -1,   993,    -1,   873,
      -1,   874,    -1,    11,    -1,    10,   875,   186,    -1,  1019,
      -1,    -1,   877,   878,   879,    -1,   183,    -1,   993,    -1,
     880,    -1,   881,    -1,    11,    -1,    10,   882,   184,    -1,
    1019,    -1,    -1,   884,   885,   886,    -1,   187,    -1,   993,
      -1,   887,    -1,   888,    -1,    11,    -1,    10,   889,   188,
      -1,  1019,    -1,    -1,   890,   891,    -1,   892,   893,   896,
      -1,   121,    -1,   894,    -1,    -1,   894,   895,    -1,   991,
      -1,   994,    -1,   960,    -1,   987,    -1,   964,    -1,   939,
      -1,   971,    -1,   943,    -1,   897,    -1,   898,    -1,    10,
     122,    -1,    11,    -1,    10,   899,   122,    -1,   900,    -1,
    1009,    -1,   901,    -1,   900,   901,    -1,   902,   903,   906,
      -1,   207,    -1,   904,    -1,    -1,   904,   905,    -1,   949,
      -1,   960,    -1,   987,    -1,   952,    -1,   975,    -1,   907,
      -1,    10,   208,    -1,    11,    -1,    -1,   909,   910,   911,
      -1,   211,    -1,  1006,    -1,   912,    -1,   913,    -1,    11,
      -1,    10,   914,   212,    -1,    -1,   914,   915,    -1,   916,
     917,   920,    -1,   213,    -1,   918,    -1,   919,    -1,   918,
     919,    -1,   960,    -1,   987,    -1,   964,    -1,   939,    -1,
     971,    -1,   943,    -1,   995,    -1,   921,    -1,   922,    -1,
      10,   214,    -1,    11,    -1,    10,   923,   214,    -1,   924,
      -1,   925,    -1,   924,   925,    -1,   926,    -1,   927,    -1,
     928,    -1,   220,    -1,   217,    -1,   218,   929,   219,    -1,
       5,    -1,   931,   932,   938,    -1,   145,    -1,   933,    -1,
      -1,   933,   934,    -1,   935,    -1,   936,    -1,   937,    -1,
      21,     3,     8,    -1,    22,     3,     8,    -1,    23,     3,
       8,    -1,    10,   146,    -1,    11,    -1,   940,    -1,   941,
      -1,   942,    -1,    49,    -1,    24,     3,  1035,    -1,   944,
      -1,   945,    -1,   946,    -1,    50,    -1,    46,     3,  1035,
      -1,   948,    -1,    26,     8,  1034,     8,    -1,   950,    -1,
     951,    -1,    42,  1035,     6,  1035,    -1,   953,    -1,   954,
      -1,   955,    -1,    53,    -1,    55,     3,  1035,    -1,   957,
      -1,   958,    -1,   959,    -1,    57,    -1,    59,  1035,  1034,
    1035,    -1,   961,    -1,   962,    -1,   963,    -1,    48,    -1,
      41,     3,  1035,    -1,   965,    -1,   966,    -1,   967,    -1,
      62,    -1,    61,     3,  1035,    -1,   969,    -1,   970,    -1,
      43,  1035,     6,  1035,    -1,   972,    -1,   973,    -1,   974,
      -1,    47,    -1,    25,     3,     8,    -1,   976,    -1,   977,
      -1,   978,    -1,    54,    -1,    56,     3,  1035,    -1,   980,
      -1,   981,    -1,   982,    -1,    58,    -1,    60,  1035,  1034,
    1035,    -1,   984,    -1,   985,    -1,   986,    -1,    51,    -1,
      45,     3,     8,    -1,   988,    -1,   989,    -1,   990,    -1,
      52,    -1,    44,     3,     8,    -1,    39,  1035,     6,  1035,
      -1,    32,  1035,     6,  1035,    -1,    40,  1035,     6,  1035,
      -1,    17,  1035,     6,  1035,    -1,    36,  1035,     6,  1035,
      -1,    18,     8,     6,     8,    -1,    38,  1035,     6,  1035,
      -1,    31,  1035,     6,  1035,    -1,    35,  1035,     6,  1035,
      -1,    34,  1035,     6,  1035,    -1,    16,  1035,     6,  1035,
      -1,    33,  1035,     6,  1035,    -1,    20,     8,     6,     8,
      -1,    19,     8,     6,     8,    -1,    27,     8,     6,     8,
      -1,    28,  1035,     6,  1035,    -1,    37,  1035,     6,  1035,
      -1,    30,  1035,     6,  1035,    -1,  1010,    -1,  1009,  1010,
      -1,  1011,  1012,  1015,    -1,   215,    -1,  1013,    -1,    -1,
    1013,  1014,    -1,   993,    -1,   987,    -1,   943,    -1,  1016,
      -1,  1017,    -1,    11,    -1,    10,  1018,   216,    -1,  1019,
      -1,  1020,    -1,  1027,    -1,    -1,  1020,  1021,    -1,  1022,
    1023,  1026,    -1,   226,    -1,  1024,    -1,    -1,  1024,  1025,
      -1,  1033,    -1,  1032,    -1,    10,     6,   227,    -1,   221,
    1028,  1029,    -1,   225,  1035,     6,  1035,    -1,  1030,    -1,
    1031,    -1,    10,   222,    -1,    11,    -1,    10,     4,   222,
      -1,   223,  1035,     6,  1035,    -1,   224,  1035,     6,  1035,
      -1,     6,    -1,     7,    -1,  1036,     8,    -1,    -1,  1036,
    1037,    -1,   229,    -1,   230,    -1,   231,    -1,   232,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   167,   167,   168,   170,   177,   184,   184,   186,   186,
     188,   190,   192,   201,   202,   205,   213,   213,   220,   229,
     229,   231,   233,   235,   237,   237,   239,   239,   241,   241,
     243,   249,   249,   251,   251,   253,   253,   255,   261,   261,
     263,   263,   265,   265,   267,   273,   273,   275,   275,   277,
     277,   279,   285,   285,   287,   287,   289,   289,   291,   302,
     302,   304,   320,   320,   322,   322,   324,   326,   328,   328,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   345,   347,   355,   355,   357,   357,   359,   361,   371,
     373,   379,   379,   381,   381,   383,   385,   394,   396,   402,
     402,   404,   404,   406,   408,   418,   425,   433,   434,   441,
     447,   447,   449,   449,   451,   453,   461,   463,   469,   469,
     471,   471,   473,   475,   484,   486,   493,   493,   495,   495,
     497,   499,   509,   511,   518,   518,   520,   520,   522,   524,
     534,   536,   542,   542,   544,   544,   546,   548,   558,   560,
     566,   566,   568,   568,   570,   572,   582,   589,   598,   599,
     605,   612,   612,   614,   614,   616,   618,   626,   628,   634,
     642,   646,   651,   651,   653,   655,   659,   659,   661,   668,
     679,   685,   685,   688,   692,   693,   696,   696,   705,   705,
     707,   717,   717,   719,   719,   721,   723,   725,   725,   728,
     729,   730,   731,   732,   736,   738,   748,   750,   750,   753,
     754,   757,   759,   767,   769,   779,   781,   781,   784,   785,
     788,   790,   799,   801,   811,   813,   813,   816,   817,   820,
     822,   831,   833,   841,   842,   844,   846,   857,   859,   866,
     874,   878,   883,   883,   885,   887,   891,   891,   893,   900,
     911,   916,   916,   919,   924,   925,   928,   928,   937,   937,
     939,   946,   946,   948,   948,   950,   952,   954,   954,   957,
     958,   962,   964,   970,   970,   972,   972,   974,   976,   987,
     989,   996,  1004,  1008,  1013,  1013,  1015,  1017,  1021,  1021,
    1023,  1030,  1041,  1046,  1046,  1049,  1054,  1055,  1058,  1058,
    1066,  1066,  1068,  1088,  1088,  1090,  1090,  1092,  1094,  1096,
    1096,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1118,  1124,  1134,  1135,
    1137,  1137,  1139,  1139,  1141,  1143,  1145,  1152,  1154,  1160,
    1160,  1162,  1162,  1164,  1166,  1176,  1184,  1191,  1193,  1193,
    1195,  1195,  1197,  1203,  1203,  1205,  1216,  1224,  1230,  1232,
    1232,  1234,  1234,  1236,  1242,  1242,  1244,  1255,  1263,  1269,
    1271,  1271,  1273,  1273,  1275,  1281,  1281,  1283,  1293,  1301,
    1307,  1309,  1309,  1311,  1311,  1313,  1319,  1319,  1321,  1331,
    1339,  1345,  1347,  1347,  1349,  1349,  1351,  1357,  1357,  1359,
    1370,  1383,  1389,  1391,  1391,  1393,  1393,  1395,  1401,  1401,
    1403,  1407,  1420,  1426,  1428,  1428,  1430,  1430,  1432,  1438,
    1438,  1440,  1444,  1457,  1463,  1465,  1465,  1467,  1467,  1469,
    1475,  1475,  1477,  1481,  1494,  1500,  1502,  1502,  1504,  1504,
    1506,  1512,  1512,  1514,  1518,  1526,  1532,  1534,  1534,  1536,
    1536,  1538,  1544,  1544,  1546,  1557,  1565,  1571,  1573,  1573,
    1575,  1575,  1577,  1583,  1583,  1585,  1596,  1604,  1611,  1613,
    1613,  1615,  1615,  1617,  1623,  1623,  1625,  1637,  1639,  1645,
    1653,  1657,  1662,  1662,  1664,  1666,  1670,  1670,  1672,  1679,
    1690,  1695,  1695,  1698,  1703,  1704,  1707,  1707,  1715,  1715,
    1717,  1725,  1727,  1727,  1730,  1736,  1742,  1750,  1750,  1752,
    1754,  1756,  1763,  1763,  1765,  1771,  1778,  1778,  1783,  1783,
    1785,  1787,  1789,  1794,  1794,  1806,  1811,  1822,  1827,  1833,
    1833,  1835,  1837,  1839,  1839,  1842,  1847,  1856,  1862,  1862,
    1865,  1876,  1880,  1887,  1887,  1891,  1891,  1903,  1908,  1919,
    1924,  1930,  1930,  1932,  1934,  1936,  1936,  1939,  1944,  1954,
    1960,  1960,  1963,  1974,  1978,  1983,  1983,  1987,  1987,  1989,
    1994,  1994,  1996,  1998,  2000,  2003,  2003,  2011,  2017,  2024,
    2024,  2026,  2028,  2030,  2034,  2034,  2043,  2049,  2056,  2056,
    2058,  2060,  2062,  2066,  2066,  2074,  2080,  2087,  2087,  2089,
    2091,  2093,  2097,  2097,  2105,  2111,  2118,  2118,  2120,  2122,
    2124,  2128,  2128,  2136,  2142,  2149,  2149,  2151,  2153,  2155,
    2159,  2159,  2167,  2173,  2180,  2180,  2182,  2184,  2186,  2190,
    2190,  2203,  2208,  2219,  2224,  2230,  2230,  2232,  2234,  2240,
    2240,  2242,  2247,  2258,  2267,  2267,  2270,  2281,  2285,  2292,
    2292,  2296,  2296,  2298,  2304,  2312,  2316,  2321,  2321,  2323,
    2325,  2325,  2327,  2343,  2353,  2361,  2361,  2364,  2365,  2374,
    2377,  2377,  2379,  2379,  2381,  2386,  2386,  2388,  2393,  2415,
    2432,  2432,  2435,  2439,  2443,  2444,  2445,  2446,  2447,  2448,
    2451,  2451,  2453,  2453,  2455,  2457,  2457,  2459,  2459,  2462,
    2476,  2491,  2493,  2493,  2496,  2506,  2507,  2508,  2509,  2512,
    2514,  2514,  2522,  2522,  2524,  2530,  2537,  2537,  2542,  2542,
    2544,  2546,  2548,  2552,  2552,  2565,  2571,  2583,  2588,  2594,
    2594,  2596,  2598,  2600,  2600,  2603,  2608,  2618,  2620,  2620,
    2623,  2634,  2638,  2645,  2645,  2648,  2648,  2663,  2668,  2682,
    2687,  2693,  2693,  2695,  2697,  2699,  2699,  2702,  2707,  2720,
    2722,  2722,  2725,  2736,  2740,  2746,  2753,  2753,  2757,  2757,
    2759,  2764,  2764,  2766,  2768,  2770,  2773,  2773,  2781,  2787,
    2794,  2794,  2796,  2798,  2800,  2803,  2803,  2811,  2817,  2824,
    2824,  2826,  2828,  2830,  2833,  2833,  2841,  2847,  2854,  2854,
    2856,  2858,  2860,  2863,  2863,  2871,  2877,  2884,  2884,  2886,
    2888,  2890,  2893,  2893,  2901,  2908,  2915,  2915,  2917,  2919,
    2921,  2925,  2925,  2933,  2939,  2946,  2946,  2948,  2950,  2952,
    2956,  2956,  2958,  2964,  2986,  3004,  3004,  3007,  3011,  3015,
    3016,  3017,  3018,  3019,  3020,  3023,  3023,  3025,  3025,  3027,
    3029,  3029,  3031,  3031,  3034,  3048,  3064,  3073,  3073,  3076,
    3086,  3087,  3088,  3089,  3092,  3094,  3094,  3102,  3102,  3104,
    3110,  3117,  3117,  3122,  3122,  3124,  3126,  3128,  3132,  3132,
    3145,  3150,  3161,  3166,  3172,  3172,  3174,  3176,  3178,  3178,
    3181,  3186,  3196,  3202,  3202,  3205,  3216,  3220,  3227,  3227,
    3231,  3231,  3246,  3251,  3264,  3269,  3275,  3275,  3277,  3279,
    3281,  3281,  3284,  3289,  3302,  3308,  3308,  3311,  3322,  3326,
    3330,  3336,  3336,  3340,  3340,  3342,  3347,  3347,  3349,  3351,
    3353,  3356,  3356,  3364,  3370,  3377,  3377,  3379,  3381,  3383,
    3386,  3386,  3394,  3400,  3407,  3407,  3409,  3411,  3413,  3417,
    3417,  3425,  3431,  3438,  3438,  3440,  3442,  3444,  3448,  3448,
    3456,  3462,  3469,  3469,  3471,  3473,  3475,  3479,  3479,  3487,
    3493,  3500,  3500,  3502,  3504,  3506,  3510,  3510,  3518,  3524,
    3531,  3531,  3533,  3535,  3537,  3541,  3541,  3543,  3549,  3571,
    3588,  3588,  3591,  3595,  3599,  3600,  3601,  3602,  3603,  3604,
    3607,  3607,  3609,  3609,  3611,  3613,  3613,  3615,  3615,  3618,
    3632,  3647,  3649,  3649,  3652,  3662,  3663,  3664,  3665,  3668,
    3670,  3670,  3678,  3678,  3680,  3682,  3690,  3695,  3701,  3703,
    3705,  3705,  3709,  3728,  3746,  3752,  3752,  3755,  3756,  3757,
    3758,  3759,  3760,  3761,  3768,  3772,  3777,  3777,  3779,  3781,
    3783,  3783,  3785,  3792,  3798,  3800,  3800,  3802,  3804,  3816,
    3825,  3835,  3840,  3840,  3843,  3844,  3845,  3847,  3856,  3865,
    3874,  3874,  3880,  3887,  3887,  3889,  3894,  3901,  3908,  3908,
    3910,  3913,  3920,  3927,  3934,  3941,  3943,  3949,  3956,  3956,
    3958,  3963,  3970,  3976,  3976,  3978,  3981,  3986,  3992,  3992,
    3994,  3997,  4004,  4010,  4010,  4012,  4015,  4022,  4028,  4030,
    4038,  4044,  4044,  4046,  4049,  4056,  4063,  4063,  4065,  4070,
    4077,  4083,  4083,  4085,  4088,  4095,  4101,  4101,  4103,  4106,
    4113,  4119,  4119,  4121,  4124,  4136,  4145,  4154,  4163,  4172,
    4181,  4190,  4199,  4207,  4213,  4219,  4225,  4231,  4242,  4251,
    4261,  4267,  4276,  4296,  4296,  4298,  4315,  4326,  4333,  4333,
    4336,  4343,  4344,  4348,  4348,  4350,  4352,  4354,  4371,  4376,
    4378,  4378,  4380,  4382,  4391,  4393,  4393,  4395,  4395,  4397,
    4405,  4407,  4412,  4412,  4414,  4414,  4416,  4439,  4447,  4461,
    4462,  4469,  4471,  4471,  4473,  4474,  4475,  4476
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
  "headerElementBody", "fileName", "fileNameContent", "fileNameEmpty",
  "fileNameLaden", "fileSource", "fileSourceContent", "fileSourceEmpty",
  "fileSourceLaden", "fileDescription", "fileDescriptionContent",
  "fileDescriptionEmpty", "fileDescriptionLaden", "fileCreator",
  "fileCreatorContent", "fileCreatorEmpty", "fileCreatorLaden",
  "fileLicence", "fileLicenceContent", "fileLicenceEmpty",
  "fileLicenceLaden", "generalElement", "generalElementStart",
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
  "requiredDirectoriesAttributes", "requiredDirectoriesContent",
  "requiredDirectoriesEmpty", "requiredDirectoriesLaden",
  "requiredDirectoriesList", "requiredDirectory", "requiredFiles",
  "requiredFilesStart", "requiredFilesAttributes", "requiredFilesContent",
  "requiredFilesEmpty", "requiredFilesLaden", "requiredFilesList",
  "requiredFile", "directoriesToMake", "directoriesToMakeStart",
  "directoriesToMakeAttributes", "directoriesToMakeContent",
  "directoriesToMakeEmpty", "directoriesToMakeLaden",
  "directoriesToMakeList", "directoryToMake", "filesToMake",
  "filesToMakeStart", "filesToMakeAttributes", "filesToMakeContent",
  "filesToMakeEmpty", "filesToMakeLaden", "filesToMakeList", "fileToMake",
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
  "filesToDeleteLaden", "filesToDeleteList", "fileToDelete",
  "directoriesToDelete", "directoriesToDeleteStart",
  "directoriesToDeleteAttributes", "directoriesToDeleteContent",
  "directoriesToDeleteEmpty", "directoriesToDeleteLaden",
  "directoriesToDeleteList", "directoryToDelete", "processesToKill",
  "processesToKillStart", "processesToKillAttributes",
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
  "PathPair", "PathPairStart", "PathPairAttributes", "PathPairAttList",
  "PathPairAttribute", "PathPairFromATT", "PathPairToATT",
  "PathPairMakeCopyATT", "PathPairEnd", "categoryAttribute", "categoryAtt",
  "categoryAttEmpty", "categoryAttContent", "descriptionAttribute",
  "descriptionAtt", "descriptionAttEmpty", "descriptionAttContent",
  "groupWeightAttribute", "groupWeightAtt", "idxAttribute", "idxAtt",
  "idxAttContent", "lbValueAttribute", "lbValueAtt", "lbValueAttEmpty",
  "lbValueAttContent", "lbDualValueAttribute", "lbDualValueAtt",
  "lbDualValueAttEmpty", "lbDualValueAttContent", "nameAttribute",
  "nameAtt", "nameAttEmpty", "nameAttContent", "solverAttribute",
  "solverAtt", "solverAttEmpty", "solverAttContent", "sosIdxAttribute",
  "sosIdxAtt", "sosIdxAttContent", "typeAttribute", "typeAtt",
  "typeAttEmpty", "typeAttContent", "ubValueAttribute", "ubValueAtt",
  "ubValueAttEmpty", "ubValueAttContent", "ubDualValueAttribute",
  "ubDualValueAtt", "ubDualValueAttEmpty", "ubDualValueAttContent",
  "unitAttribute", "unitAtt", "unitAttEmpty", "unitAttContent",
  "valueAttribute", "valueAtt", "valueAttEmpty", "valueAttContent",
  "numberOfConAttribute", "numberOfConstraintsAttribute",
  "numberOfElAttribute", "numberOfEnumerationsAttribute",
  "numberOfItemsAttribute", "numberOfJobIDsATT", "numberOfObjAttribute",
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
     246,   247,   248,   249,   250,   250,   251,   251,   252,   252,
     253,   254,   254,   255,   255,   256,   256,   257,   258,   258,
     259,   259,   260,   260,   261,   262,   262,   263,   263,   264,
     264,   265,   266,   266,   267,   267,   268,   268,   269,   270,
     270,   271,   272,   272,   273,   273,   274,   275,   276,   276,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   278,   279,   280,   280,   281,   281,   282,   283,   284,
     285,   286,   286,   287,   287,   288,   289,   290,   291,   292,
     292,   293,   293,   294,   295,   296,   297,   298,   298,   299,
     300,   300,   301,   301,   302,   303,   304,   305,   306,   306,
     307,   307,   308,   309,   310,   311,   312,   312,   313,   313,
     314,   315,   316,   317,   318,   318,   319,   319,   320,   321,
     322,   323,   324,   324,   325,   325,   326,   327,   328,   329,
     330,   330,   331,   331,   332,   333,   334,   335,   336,   336,
     337,   338,   338,   339,   339,   340,   341,   342,   343,   344,
     345,   345,   346,   346,   347,   348,   349,   349,   350,   351,
     352,   353,   353,   354,   354,   354,   355,   355,   356,   356,
     357,   358,   358,   359,   359,   360,   361,   362,   362,   363,
     363,   363,   363,   363,   364,   365,   366,   367,   367,   368,
     368,   369,   370,   371,   372,   373,   374,   374,   375,   375,
     376,   377,   378,   379,   380,   381,   381,   382,   382,   383,
     384,   385,   386,   387,   387,   388,   389,   390,   391,   392,
     393,   393,   394,   394,   395,   396,   397,   397,   398,   399,
     400,   401,   401,   402,   402,   402,   403,   403,   404,   404,
     405,   406,   406,   407,   407,   408,   409,   410,   410,   411,
     411,   412,   413,   414,   414,   415,   415,   416,   417,   418,
     419,   420,   421,   421,   422,   422,   423,   424,   425,   425,
     426,   427,   428,   429,   429,   430,   430,   430,   431,   431,
     432,   432,   433,   434,   434,   435,   435,   436,   437,   438,
     438,   439,   439,   439,   439,   439,   439,   439,   439,   439,
     439,   439,   439,   439,   439,   439,   440,   441,   442,   442,
     443,   443,   444,   444,   445,   446,   447,   448,   449,   450,
     450,   451,   451,   452,   453,   454,   455,   456,   457,   457,
     458,   458,   459,   460,   460,   461,   462,   463,   464,   465,
     465,   466,   466,   467,   468,   468,   469,   470,   471,   472,
     473,   473,   474,   474,   475,   476,   476,   477,   478,   479,
     480,   481,   481,   482,   482,   483,   484,   484,   485,   486,
     487,   488,   489,   489,   490,   490,   491,   492,   492,   493,
     494,   495,   496,   497,   497,   498,   498,   499,   500,   500,
     501,   502,   503,   504,   505,   505,   506,   506,   507,   508,
     508,   509,   510,   511,   512,   513,   513,   514,   514,   515,
     516,   516,   517,   518,   519,   520,   521,   521,   522,   522,
     523,   524,   524,   525,   526,   527,   528,   529,   529,   530,
     530,   531,   532,   532,   533,   534,   535,   536,   537,   537,
     538,   538,   539,   540,   540,   541,   542,   543,   544,   545,
     545,   546,   546,   547,   548,   548,   549,   550,   551,   552,
     553,   553,   554,   554,   555,   556,   557,   557,   558,   559,
     560,   561,   561,   562,   562,   562,   563,   563,   564,   564,
     565,   566,   567,   567,   568,   568,   568,   569,   569,   570,
     571,   572,   573,   573,   574,   575,   576,   576,   577,   577,
     578,   579,   580,   581,   581,   582,   583,   584,   584,   585,
     585,   586,   587,   588,   588,   589,   590,   591,   592,   592,
     593,   593,   593,   594,   594,   595,   595,   596,   597,   598,
     598,   599,   599,   600,   601,   602,   602,   603,   604,   605,
     606,   606,   607,   607,   607,   608,   608,   609,   609,   610,
     611,   611,   612,   613,   614,   615,   615,   616,   617,   618,
     618,   619,   620,   621,   622,   622,   623,   624,   625,   625,
     626,   627,   628,   629,   629,   630,   631,   632,   632,   633,
     634,   635,   636,   636,   637,   638,   639,   639,   640,   641,
     642,   643,   643,   644,   645,   646,   646,   647,   648,   649,
     650,   650,   651,   652,   653,   653,   654,   655,   656,   657,
     657,   658,   659,   660,   660,   661,   661,   662,   663,   664,
     664,   665,   666,   667,   668,   668,   669,   669,   669,   670,
     670,   671,   671,   672,   673,   674,   674,   675,   675,   676,
     677,   677,   678,   679,   680,   681,   681,   682,   682,   682,
     683,   683,   684,   684,   685,   686,   686,   687,   688,   689,
     690,   690,   691,   691,   691,   691,   691,   691,   691,   691,
     692,   692,   693,   693,   694,   695,   695,   696,   696,   697,
     698,   699,   700,   700,   701,   701,   701,   701,   701,   702,
     703,   703,   704,   704,   705,   706,   707,   707,   708,   708,
     709,   710,   711,   712,   712,   713,   714,   715,   715,   716,
     716,   717,   718,   719,   719,   720,   721,   722,   723,   723,
     724,   724,   724,   725,   725,   726,   726,   727,   728,   729,
     729,   730,   730,   731,   732,   733,   733,   734,   735,   736,
     737,   737,   738,   738,   738,   738,   739,   739,   740,   740,
     741,   742,   742,   743,   744,   745,   746,   746,   747,   748,
     749,   749,   750,   751,   752,   753,   753,   754,   755,   756,
     756,   757,   758,   759,   760,   760,   761,   762,   763,   763,
     764,   765,   766,   767,   767,   768,   769,   770,   770,   771,
     772,   773,   774,   774,   775,   776,   777,   777,   778,   779,
     780,   781,   781,   782,   783,   784,   784,   785,   786,   787,
     788,   788,   789,   790,   791,   792,   792,   793,   793,   793,
     793,   793,   793,   793,   793,   794,   794,   795,   795,   796,
     797,   797,   798,   798,   799,   800,   801,   802,   802,   803,
     803,   803,   803,   803,   804,   805,   805,   806,   806,   807,
     808,   809,   809,   810,   810,   811,   812,   813,   814,   814,
     815,   816,   817,   817,   818,   818,   819,   820,   821,   821,
     822,   823,   824,   825,   825,   826,   826,   826,   827,   827,
     828,   828,   829,   830,   831,   831,   832,   832,   833,   834,
     835,   835,   836,   837,   838,   839,   839,   840,   840,   840,
     840,   841,   841,   842,   842,   843,   844,   844,   845,   846,
     847,   848,   848,   849,   850,   851,   851,   852,   853,   854,
     855,   855,   856,   857,   858,   858,   859,   860,   861,   862,
     862,   863,   864,   865,   865,   866,   867,   868,   869,   869,
     870,   871,   872,   872,   873,   874,   875,   876,   876,   877,
     878,   879,   879,   880,   881,   882,   883,   883,   884,   885,
     886,   886,   887,   888,   889,   890,   890,   891,   892,   893,
     894,   894,   895,   895,   895,   895,   895,   895,   895,   895,
     896,   896,   897,   897,   898,   899,   899,   900,   900,   901,
     902,   903,   904,   904,   905,   905,   905,   905,   905,   906,
     907,   907,   908,   908,   909,   910,   911,   911,   912,   913,
     914,   914,   915,   916,   917,   918,   918,   919,   919,   919,
     919,   919,   919,   919,   920,   920,   921,   921,   922,   923,
     924,   924,   925,   926,   926,   927,   927,   928,   929,   930,
     931,   932,   933,   933,   934,   934,   934,   935,   936,   937,
     938,   938,   939,   940,   940,   941,   942,   943,   944,   944,
     945,   946,   947,   948,   949,   950,   951,   952,   953,   953,
     954,   955,   956,   957,   957,   958,   959,   960,   961,   961,
     962,   963,   964,   965,   965,   966,   967,   968,   969,   970,
     971,   972,   972,   973,   974,   975,   976,   976,   977,   978,
     979,   980,   980,   981,   982,   983,   984,   984,   985,   986,
     987,   988,   988,   989,   990,   991,   992,   993,   994,   995,
     996,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1009,  1010,  1011,  1012,  1013,  1013,
    1014,  1014,  1014,  1015,  1015,  1016,  1017,  1018,  1019,  1019,
    1020,  1020,  1021,  1022,  1023,  1024,  1024,  1025,  1025,  1026,
    1027,  1028,  1029,  1029,  1030,  1030,  1031,  1032,  1033,  1034,
    1034,  1035,  1036,  1036,  1037,  1037,  1037,  1037
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     1,     0,     6,     0,     2,     1,     1,
       1,     1,     3,     5,     0,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     1,     1,     1,     3,     0,
       2,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     3,     1,     0,     1,     3,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     3,     1,     0,     1,
       3,     1,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     2,     1,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     3,     1,     1,     0,     2,     1,
       1,     3,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     1,     0,     2,     1,     1,     3,
       1,     3,     1,     0,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     2,     1,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       0,     2,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     0,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     4,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     4,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     2,     4,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     2,     4,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     2,     4,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     4,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     4,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     4,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     2,     1,     0,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     0,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     6,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     1,     3,     6,     0,     3,     1,     1,     1,
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
       1,     1,     1,     1,     3,     6,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     0,     3,     1,
       1,     0,     1,     1,     1,     1,     3,     4,     0,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     2,     1,     0,     2,     1,     1,     1,     1,     3,
       6,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       0,     2,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     0,     2,     1,     1,     1,     3,     3,     3,
       2,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     4,     1,     1,     4,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     4,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     3,
       3,     4,     1,     1,     2,     1,     3,     4,     4,     1,
       1,     2,     0,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,    18,    14,    59,
       0,     7,     0,    13,     2,    12,    61,   188,     0,    24,
      21,    17,    19,    20,    16,    10,     3,     8,     9,   190,
     258,     0,     0,    65,    60,    62,    63,     0,    29,    28,
       0,    31,    25,    26,    27,    14,   260,   300,     0,     0,
     194,   189,   191,   192,    64,    82,    90,    98,   106,   117,
     125,   133,   141,   149,   157,   168,     0,    67,    68,    70,
       0,    71,     0,    72,     0,    73,   107,    74,     0,    75,
       0,    76,     0,    77,     0,    78,     0,    79,   158,    80,
       0,     0,    22,     0,    36,    35,    38,    32,    33,    34,
      11,   302,   498,     0,     0,   264,   259,   261,   262,   193,
     238,   205,   214,   223,   232,     0,   196,   197,   199,   207,
     200,   216,   201,   225,   202,   233,   203,     0,    66,    69,
       0,    86,    81,    83,    84,     0,    94,    89,    91,    92,
       0,   102,    97,    99,   100,     0,     0,   108,     0,   121,
     116,   118,   119,     0,   129,   124,   126,   127,     0,   137,
     132,   134,   135,     0,   145,   140,   142,   143,     0,   153,
     148,   150,   151,     0,     0,   159,  1192,     0,   169,    30,
       0,     0,    43,    42,    45,    39,    40,    41,   500,    15,
     502,     0,   306,   301,   303,   304,   263,   280,   272,     0,
     266,   267,   269,     0,   270,     0,   195,   198,     0,   206,
       0,   215,     0,   224,     0,  1080,     0,   234,  1077,  1078,
    1079,     0,   239,    88,    85,     0,    96,    93,     0,   104,
     101,     0,     0,     0,   113,   105,   110,   111,   123,   120,
       0,   131,   128,     0,   139,   136,     0,   147,   144,     0,
     155,   152,     0,     0,     0,   164,   156,   161,   162,     0,
       0,     0,   173,   167,   170,   171,    37,     0,     0,    50,
      49,    52,    46,    47,    48,     0,   501,   305,   478,   327,
     338,   346,   357,   368,   379,   390,   456,   445,   401,   412,
     434,   423,   467,     0,   308,   309,   311,   328,   312,     0,
     313,     0,   314,     0,   315,     0,   316,     0,   317,     0,
     318,     0,   319,     0,   321,     0,   320,     0,   322,     0,
     323,     0,   324,     0,   325,     0,   265,   268,     0,   276,
     271,   273,   274,     0,   281,     0,   204,     0,  1128,   208,
     210,   209,  1125,  1126,  1127,     0,   213,   217,   219,   218,
       0,   222,   226,   228,   227,  1192,     0,   231,     0,   243,
     237,   240,   241,    87,    95,   103,   109,   115,   112,     0,
     122,   130,   138,   146,   154,   160,   166,   163,     0,  1192,
    1191,  1194,  1195,  1196,  1197,  1193,   172,   179,     0,   175,
     176,   181,    44,     0,     0,    57,    56,    23,    53,    54,
      55,   512,   509,   499,   507,   508,  1192,  1192,  1192,   503,
     505,   506,   504,   307,   310,     0,   329,     0,   342,   337,
     339,   340,     0,     0,   347,     0,     0,   358,     0,   369,
       0,   380,     0,   391,     0,     0,   402,     0,   413,     0,
     424,     0,   435,     0,   446,     0,   457,     0,     0,   468,
       0,   479,   278,   275,     0,     0,   285,   279,   282,   283,
    1189,  1190,     0,   212,     0,     0,   221,     0,   230,  1081,
     236,     0,   242,   249,     0,   245,   246,   251,   114,   165,
    1145,   174,   177,     0,   180,    51,     0,   514,     0,   712,
     516,     0,     0,     0,     0,   333,   326,   330,   331,   344,
     341,     0,     0,     0,   351,   345,   348,   349,     0,     0,
     362,   356,   359,   360,     0,   373,   367,   370,   371,     0,
     384,   378,   381,   382,     0,   395,   389,   392,   393,     0,
       0,   406,   400,   403,   404,     0,   417,   411,   414,   415,
       0,   428,   422,   425,   426,     0,   439,   433,   436,   437,
       0,   450,   444,   447,   448,     0,   461,   455,   458,   459,
       0,     0,   472,   466,   469,   470,     0,   483,   477,   480,
     481,   277,   284,   291,     0,   287,   288,   293,   211,  1129,
     220,   229,   235,   244,   247,     0,   250,     0,   187,   178,
       0,     0,  1100,  1133,   182,   185,   183,  1097,  1098,  1099,
     184,  1130,  1131,  1132,    58,   510,   714,   867,   716,  1192,
       0,   515,   517,  1192,  1192,  1192,   332,     0,   335,   336,
     343,     0,     0,   350,     0,   353,     0,   361,     0,     0,
     364,   372,     0,     0,   375,     0,   383,     0,   386,     0,
     394,     0,   397,     0,  1060,   405,     0,   408,   410,  1062,
     416,     0,   419,   421,   427,     0,   430,   432,   438,     0,
     441,   443,     0,   449,     0,   452,     0,   460,     0,   463,
       0,   471,     0,     0,   474,   482,   489,     0,   485,   486,
     491,   286,   289,     0,   292,     0,   257,   248,   252,   255,
     253,   254,   186,  1192,     0,   869,  1022,   871,  1192,     0,
     715,   717,     0,   523,   520,   513,   518,   519,  1152,  1142,
    1136,   334,  1140,     0,   352,   354,  1148,     0,   363,   365,
       0,   374,   376,     0,   385,   387,     0,   396,   398,  1147,
     407,   409,     0,  1061,   418,   420,   429,   431,   440,   442,
       0,   451,   453,     0,   462,   464,  1149,     0,   473,   475,
     484,   487,     0,   490,     0,   299,   290,   294,   297,   295,
     296,   256,  1101,  1134,  1024,   511,     0,  1192,     0,   870,
     872,     0,   723,   720,   713,   718,   719,  1192,   525,     0,
     545,     0,     0,     0,     0,     0,     0,     0,  1071,  1059,
       0,     0,     0,  1063,  1064,  1065,  1066,     0,     0,     0,
       0,   497,   488,   492,   495,   493,   494,   298,  1192,     0,
    1025,     0,   878,   875,   868,   873,   874,  1192,   725,     0,
     745,     0,  1146,   521,   547,   567,     0,  1192,     0,   526,
     355,   366,   377,   388,   399,  1070,     0,     0,     0,   454,
     465,   476,   496,     0,  1030,  1028,  1023,  1026,  1027,  1192,
     880,     0,   900,     0,  1144,   721,   747,   768,     0,  1192,
       0,   726,   569,   629,     0,     0,   548,     0,     0,   530,
     524,   527,   528,  1067,  1068,  1069,  1192,     0,  1143,   876,
     902,   923,     0,  1192,     0,   881,   770,   830,     0,     0,
     748,     0,     0,   730,   724,   727,   728,   631,   651,     0,
     575,   572,   568,   570,   571,     0,   552,   546,   549,   550,
    1192,   529,   536,     0,   532,   533,   538,  1150,  1029,  1033,
    1031,     0,   925,   985,     0,     0,   903,     0,     0,   885,
     879,   882,   883,   722,   776,   773,   769,   771,   772,     0,
     752,   746,   749,   750,  1192,   729,   736,     0,   732,   733,
     738,   653,   675,     0,     0,   632,   577,     0,   584,     0,
     558,   551,     0,   554,   555,   560,  1151,   531,   534,     0,
     537,     0,     0,  1192,  1113,  1075,     0,  1105,     0,  1034,
    1035,  1040,  1072,  1073,  1074,  1042,  1037,  1039,  1102,  1103,
    1104,  1041,  1110,  1111,  1112,  1038,  1043,   877,   931,   928,
     924,   926,   927,     0,   907,   901,   904,   905,  1192,   884,
     891,     0,   887,   888,   893,   833,   831,   835,   778,     0,
     785,     0,   758,   751,     0,   754,   755,   760,  1141,   731,
     734,     0,   737,   522,     0,     0,     0,   636,   630,   633,
     634,   573,   586,   593,     0,  1192,     0,   578,   553,   556,
       0,   559,     0,   544,   535,  1192,   539,   540,  1084,  1085,
     541,   542,  1192,     0,     0,  1192,     0,  1047,  1032,  1044,
    1045,  1036,   988,   986,   990,   933,     0,   940,     0,   913,
     906,     0,   909,   910,   915,  1135,   886,   889,     0,   892,
       0,   834,   774,   787,   794,     0,     0,   779,   753,   756,
       0,   759,     0,   744,   735,   739,   740,   741,   742,   678,
     676,   680,     0,     0,   658,   652,   655,   656,   642,   635,
       0,   638,   639,   644,   595,   602,     0,     0,   587,     0,
    1170,   581,   576,   579,   580,     0,   566,   557,   561,   562,
     563,   564,   543,     0,  1076,  1114,  1192,  1106,  1046,  1056,
       0,  1055,     0,  1049,  1050,  1052,  1053,  1054,     0,   989,
     929,   942,   949,     0,     0,   934,   908,   911,     0,   914,
       0,   899,   890,   894,   895,   896,   897,     0,   848,   832,
     845,   846,  1192,   836,   842,   844,   839,   841,   843,   840,
     838,   837,   796,   803,     0,     0,   788,  1170,   782,   777,
     780,   781,     0,   767,   757,  1090,  1118,     0,     0,   761,
     762,   764,  1087,  1088,  1089,   763,   765,  1115,  1116,  1117,
     743,     0,   679,     0,   657,   663,     0,   660,   665,   637,
     640,     0,   643,   604,   611,     0,     0,   596,  1170,   590,
     585,   588,   589,  1192,     0,     0,   583,  1168,  1169,   565,
    1192,  1139,  1058,     0,  1048,  1051,     0,  1003,   987,  1000,
    1001,   991,   997,   999,   994,   996,   998,   995,   992,   993,
     951,   958,     0,     0,   943,  1170,   937,   932,   935,   936,
       0,   922,   912,  1095,  1123,  1192,  1192,   916,   917,   919,
    1092,  1093,  1094,   918,   920,  1120,  1121,  1122,   898,   847,
     855,  1156,     0,   850,   852,   857,   851,  1153,  1158,     0,
     805,   812,     0,     0,   797,  1170,   791,   786,   789,   790,
       0,   784,   766,  1192,  1192,     0,   693,   677,   690,   691,
     681,   687,   689,   684,   686,   688,   685,   683,   682,   654,
     659,   661,     0,   664,     0,   650,   641,   645,   646,   647,
     648,   613,   620,     0,     0,   605,  1170,   599,   594,   597,
     598,     0,   592,  1137,  1192,     0,   582,  1173,  1171,  1175,
    1086,  1057,  1002,  1010,     0,  1005,  1007,  1012,  1006,   960,
     967,     0,     0,   952,  1170,   946,   941,   944,   945,     0,
     939,   921,     0,     0,   849,   853,     0,   856,  1154,     0,
    1157,  1192,   814,   821,     0,     0,   806,  1170,   800,   795,
     798,   799,     0,   793,   783,  1091,  1119,   692,   700,     0,
     695,   697,   702,   696,     0,   673,   662,   670,   671,     0,
    1192,   666,   669,  1082,   667,  1107,  1108,   668,   649,   622,
     574,     0,     0,   614,  1170,   608,   603,   606,   607,     0,
     601,   591,     0,     0,  1185,  1180,  1182,  1183,     0,  1174,
    1004,  1008,     0,  1011,   969,   976,     0,     0,   961,  1170,
     955,   950,   953,   954,     0,   948,   938,  1192,  1192,     0,
     866,   854,   864,   858,   859,   862,   860,   863,   861,  1170,
    1165,  1155,  1163,  1164,  1162,  1161,  1160,  1159,  1138,   823,
     775,     0,     0,   815,  1170,   809,   804,   807,   808,     0,
     802,   792,   694,   698,     0,   701,   672,     0,     0,     0,
       0,   623,  1170,   617,   612,   615,   616,     0,   610,   600,
    1192,     0,  1184,     0,  1172,  1192,  1192,  1176,  1178,  1177,
       0,  1021,  1009,  1019,  1013,  1014,  1017,  1015,  1018,  1016,
     978,   930,     0,     0,   970,  1170,   964,   959,   962,   963,
       0,   957,   947,  1096,  1124,   865,     0,  1167,     0,   824,
    1170,   818,   813,   816,   817,     0,   811,   801,     0,   711,
     699,   709,   703,   704,   707,   705,   708,   706,   674,     0,
    1192,  1170,   626,   621,   624,   625,     0,   619,   609,  1181,
    1186,     0,     0,     0,  1020,     0,   979,  1170,   973,   968,
     971,   972,     0,   966,   956,  1166,  1170,   827,   822,   825,
     826,     0,   820,   810,   710,  1083,  1109,     0,   628,   618,
    1179,  1192,  1192,  1170,   982,   977,   980,   981,     0,   975,
     965,     0,   829,   819,   627,  1187,  1188,     0,   984,   974,
     828,   983
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    26,    27,    28,    14,    15,
       8,     9,    10,    21,    22,    23,    40,    41,    42,    43,
      44,    96,    97,    98,    99,   184,   185,   186,   187,   271,
     272,   273,   274,   397,   398,   399,   400,    17,    18,    34,
      35,    36,    66,    67,    68,    69,    70,   132,   133,   134,
     225,    71,    72,   137,   138,   139,   228,    73,    74,   142,
     143,   144,   231,    75,    76,   146,   147,   235,   236,   237,
     369,    77,    78,   150,   151,   152,   240,    79,    80,   155,
     156,   157,   243,    81,    82,   160,   161,   162,   246,    83,
      84,   165,   166,   167,   249,    85,    86,   170,   171,   172,
     252,    87,    88,   174,   175,   256,   257,   258,   378,    89,
      90,   177,   263,   264,   265,   388,   389,   390,   391,   483,
     484,   594,   589,    30,    31,    51,    52,    53,   115,   116,
     117,   118,   119,   208,   209,   339,   336,   462,   120,   121,
     210,   211,   347,   346,   465,   122,   123,   212,   213,   352,
     351,   467,   124,   125,   216,   357,   471,   126,   127,   221,
     360,   361,   362,   474,   475,   476,   477,   585,   586,   688,
     687,    47,    48,   106,   107,   108,   199,   200,   201,   202,
     203,   330,   331,   332,   454,   204,   205,   333,   457,   458,
     459,   574,   575,   576,   577,   683,   684,   757,   756,   102,
     103,   193,   194,   195,   293,   294,   295,   296,   297,   415,
     496,   497,   498,   617,   618,   298,   299,   419,   420,   421,
     501,   300,   301,   423,   505,   506,   507,   624,   625,   302,
     303,   426,   511,   512,   513,   629,   630,   304,   305,   428,
     516,   517,   518,   633,   634,   306,   307,   430,   521,   522,
     523,   637,   638,   308,   309,   432,   526,   527,   528,   641,
     642,   310,   311,   435,   532,   533,   534,   646,   647,   312,
     313,   437,   537,   538,   539,   651,   652,   314,   315,   439,
     542,   543,   544,   655,   656,   316,   317,   441,   547,   548,
     549,   659,   660,   318,   319,   443,   552,   553,   554,   664,
     665,   320,   321,   445,   557,   558,   559,   668,   669,   322,
     323,   448,   563,   564,   565,   673,   674,   324,   325,   450,
     568,   569,   570,   677,   678,   679,   680,   752,   753,   803,
     802,   189,   190,   275,   276,   409,   403,   404,   405,   488,
     489,   490,   610,   611,   705,   706,   707,   779,   780,   781,
     828,   870,   871,   872,   913,   914,   915,   916,   969,   970,
    1056,  1054,   825,   826,   865,   907,   908,   909,   962,   963,
     964,   965,  1050,  1051,  1138,  1137,   863,   864,   902,   903,
     904,   957,   958,   959,  1046,  1132,  1133,  1134,  1245,  1043,
    1044,  1127,  1240,  1241,  1242,  1361,  1125,  1126,  1236,  1358,
    1359,  1360,  1449,  1234,  1235,  1354,  1446,  1447,  1448,  1527,
    1352,  1353,  1442,  1524,  1525,  1526,  1596,  1440,  1441,  1520,
    1593,  1594,  1595,  1627,   898,   899,   954,  1038,  1039,  1040,
    1120,  1121,  1122,  1123,  1231,  1232,  1347,  1346,   952,   953,
    1035,  1115,  1116,  1117,  1226,  1227,  1228,  1342,  1343,  1431,
    1426,  1427,  1428,  1033,  1110,  1111,  1221,  1222,  1330,  1327,
    1328,  1329,  1419,  1420,  1421,  1422,  1514,  1515,  1582,  1580,
    1581,   607,   608,   699,   700,   774,   775,   776,   819,   820,
     821,   860,   894,   895,   896,   947,   948,   949,   950,  1031,
    1032,  1105,  1104,   857,   858,   889,   941,   942,   943,  1024,
    1025,  1026,  1027,  1100,  1101,  1209,  1204,   887,   888,   936,
     937,   938,  1019,  1020,  1021,  1096,  1199,  1200,  1201,  1320,
    1094,  1095,  1195,  1317,  1318,  1319,  1412,  1193,  1194,  1313,
    1409,  1410,  1411,  1509,  1311,  1312,  1405,  1506,  1507,  1508,
    1575,  1403,  1404,  1502,  1572,  1573,  1574,  1621,  1500,  1501,
    1568,  1618,  1619,  1620,  1641,   933,  1016,  1017,  1090,  1091,
    1183,  1179,  1180,  1181,  1302,  1303,  1304,  1305,  1396,  1397,
    1483,  1481,  1482,   696,   697,   768,   769,   814,   815,   816,
     851,   852,   853,   884,   930,   931,   932,  1011,  1012,  1013,
    1014,  1088,  1089,  1173,  1172,   881,   882,   925,  1005,  1006,
    1007,  1081,  1082,  1083,  1084,  1168,  1169,  1287,  1282,   923,
     924,  1000,  1001,  1002,  1076,  1077,  1078,  1164,  1277,  1278,
    1279,  1389,  1162,  1163,  1273,  1386,  1387,  1388,  1474,  1271,
    1272,  1382,  1471,  1472,  1473,  1560,  1380,  1381,  1467,  1557,
    1558,  1559,  1612,  1465,  1466,  1553,  1609,  1610,  1611,  1638,
    1551,  1552,  1605,  1635,  1636,  1637,  1647,   997,  1073,  1074,
    1158,  1159,  1261,  1258,  1259,  1260,  1374,  1375,  1376,  1377,
    1462,  1463,  1544,  1542,  1543,   765,   766,   809,   846,   847,
     848,   877,   920,   921,   978,   979,   980,  1068,  1069,  1070,
    1152,  1153,  1154,  1155,  1156,  1157,  1253,   648,   649,   732,
     733,   793,   794,   795,   796,   789,   981,   982,   983,   984,
     985,   218,   219,   220,  1432,  1433,  1057,  1058,  1059,  1211,
    1212,  1213,  1214,  1289,  1290,  1291,  1292,   986,   597,   598,
     599,   987,   988,   989,   990,  1434,  1435,  1436,   991,   992,
     993,   994,  1216,  1217,  1218,  1219,  1294,  1295,  1296,  1297,
     341,   342,   343,   344,   995,   601,   602,   603,   885,   410,
    1047,  1190,   996,   424,   861,   411,   770,   701,   178,   612,
     436,   427,   449,   810,   829,   412,  1306,  1307,  1308,  1399,
    1400,  1497,  1491,  1492,  1493,  1566,  1246,  1247,  1368,  1369,
    1458,  1459,  1537,  1534,  1248,  1365,  1455,  1456,  1457,  1538,
    1539,   463,   259,   260,   385
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1362
static const yytype_int16 yypact[] =
{
     332, -1362, -1362,   101,   -44,    89, -1362, -1362,   111,   115,
     360, -1362,   376, -1362, -1362, -1362, -1362,   119,   432,   117,
   -1362, -1362, -1362, -1362,   -44, -1362, -1362, -1362, -1362, -1362,
     148,   434,   204, -1362, -1362, -1362, -1362,   183, -1362, -1362,
     172,   144, -1362, -1362, -1362,   111, -1362,   180,   436,    -5,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   203,   291, -1362, -1362,
     438, -1362,   441, -1362,   444, -1362,   209, -1362,   446, -1362,
     450, -1362,   453, -1362,   457, -1362,   459, -1362,   214, -1362,
     261,   201, -1362,   278, -1362, -1362,   163, -1362, -1362, -1362,
   -1362, -1362,   216,   465,   -25, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362,   213,   138, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362,   118, -1362,   261, -1362, -1362,
      33, -1362, -1362, -1362, -1362,    30, -1362, -1362, -1362, -1362,
      52, -1362, -1362, -1362, -1362,   288,   467, -1362,    35, -1362,
   -1362, -1362, -1362,    27, -1362, -1362, -1362, -1362,    26, -1362,
   -1362, -1362, -1362,    28, -1362, -1362, -1362, -1362,    25, -1362,
   -1362, -1362, -1362,   294,   469, -1362, -1362,   471, -1362, -1362,
     205,   296, -1362, -1362,   242, -1362, -1362, -1362, -1362, -1362,
   -1362,   129, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   225,
     -12, -1362, -1362,   473, -1362,   261, -1362, -1362,   298,   196,
     300,   196,   302,   196,   313, -1362,   308, -1362, -1362, -1362,
   -1362,   492, -1362, -1362, -1362,   220, -1362, -1362,   224, -1362,
   -1362,   226,   350,    29, -1362, -1362, -1362, -1362, -1362, -1362,
     256, -1362, -1362,   252, -1362, -1362,   269, -1362, -1362,   283,
   -1362, -1362,   250,   383,    16, -1362, -1362, -1362, -1362,   393,
       4,   385, -1362, -1362, -1362, -1362, -1362,   321,   396, -1362,
   -1362,   277, -1362, -1362, -1362,   497,   389, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362,   331,   425, -1362, -1362,    78, -1362,   502,
   -1362,   395, -1362,   412, -1362,   412, -1362,   412, -1362,   412,
   -1362,   397, -1362,   397, -1362,   397, -1362,   397, -1362,   412,
   -1362,   412, -1362,   413, -1362,   261, -1362, -1362,    12, -1362,
   -1362, -1362, -1362,   504, -1362,   510, -1362,   430, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362,   510, -1362, -1362, -1362, -1362,
     510, -1362, -1362, -1362, -1362, -1362,   486, -1362,   398, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   353,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   369, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   351,   379,
   -1362, -1362, -1362,   417,   522, -1362, -1362, -1362, -1362, -1362,
   -1362,   368, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362,   512, -1362,    10, -1362, -1362,
   -1362, -1362,   541,   515, -1362,   551,   519, -1362,   521, -1362,
     523, -1362,   527, -1362,   553,   529, -1362,   531, -1362,   535,
   -1362,   537, -1362,   542, -1362,   546, -1362,   563,   557, -1362,
     580, -1362, -1362, -1362,   388,   472, -1362, -1362, -1362, -1362,
   -1362, -1362,   419, -1362,   565,   428, -1362,   437, -1362, -1362,
   -1362,   445, -1362, -1362,   461,   458, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362,   584,   254, -1362,   487, -1362,   499,   390,
     554,   592,   605,   608,    19, -1362, -1362, -1362, -1362, -1362,
   -1362,   507,   611,   -60, -1362, -1362, -1362, -1362,   654,   -74,
   -1362, -1362, -1362, -1362,   454, -1362, -1362, -1362, -1362,    24,
   -1362, -1362, -1362, -1362,   -79, -1362, -1362, -1362, -1362,   727,
     -58, -1362, -1362, -1362, -1362,   -49, -1362, -1362, -1362, -1362,
     -87, -1362, -1362, -1362, -1362,   -90, -1362, -1362, -1362, -1362,
     -26, -1362, -1362, -1362, -1362,   -27, -1362, -1362, -1362, -1362,
     750,   435, -1362, -1362, -1362, -1362,   481, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362,   532,   578, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362,   593,   254,   635, -1362, -1362,
     755,   756, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362,   558,   729, -1362,
     595, -1362, -1362, -1362, -1362, -1362, -1362,   626, -1362, -1362,
   -1362,   754,   757, -1362,   -57, -1362,   758, -1362,   759,   182,
   -1362, -1362,   760,   470, -1362,   761, -1362,    67, -1362,   762,
   -1362,    61, -1362,   765, -1362, -1362,    18, -1362, -1362, -1362,
   -1362,   -46, -1362, -1362, -1362,   -86, -1362, -1362, -1362,   -63,
   -1362, -1362,   764, -1362,    23, -1362,   766, -1362,   -22, -1362,
     767, -1362,   768,   451, -1362, -1362, -1362,   644,   647, -1362,
   -1362, -1362, -1362,   610,   254,   643, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362,   769, -1362,   568,   745, -1362,   612,
   -1362, -1362,   775,   613, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362,   779, -1362, -1362, -1362,   780, -1362, -1362,
     781, -1362, -1362,   782, -1362, -1362,   783, -1362, -1362, -1362,
   -1362, -1362,   614,   406, -1362, -1362, -1362, -1362, -1362, -1362,
     784, -1362, -1362,   785, -1362, -1362, -1362,   786, -1362, -1362,
   -1362, -1362,   616,   254,   670, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   770, -1362,   618, -1362,
   -1362,   787,   597, -1362, -1362, -1362, -1362, -1362, -1362,   628,
     622,   763,   689,   658,   660,   662,   664,   666, -1362, -1362,
     796,   798,   800, -1362, -1362, -1362, -1362,   667,   672,   639,
     688, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   620,
   -1362,   801,   604, -1362, -1362, -1362, -1362, -1362, -1362,   617,
     619,   776, -1362, -1362, -1362,   642,   763, -1362,   623, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   807,   810,   811, -1362,
   -1362, -1362, -1362,   815, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362,   621,   615,   789, -1362, -1362, -1362,   651,   776, -1362,
     625, -1362, -1362,   633,   627,   629, -1362,   817,   474, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362,   429, -1362, -1362,
   -1362,   656,   789, -1362,   636, -1362, -1362, -1362,   638,   640,
   -1362,   823,   456, -1362, -1362, -1362, -1362, -1362,   641,   763,
     668, -1362, -1362, -1362, -1362,   -13, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362,   674,   676, -1362, -1362, -1362, -1362, -1362,
   -1362,   176, -1362, -1362,   646,   648, -1362,   824,   455, -1362,
   -1362, -1362, -1362,   712,   677, -1362, -1362, -1362, -1362,   212,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362,   637,   649, -1362,
   -1362, -1362, -1362,   805,   653, -1362, -1362,   679,   678,   797,
   -1362, -1362,   682,   680, -1362, -1362, -1362, -1362, -1362,   655,
     341,   833,   835, -1362, -1362, -1362,   836, -1362,   657,   176,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362,   720,   684, -1362,
   -1362, -1362, -1362,   208, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362,   634,   645, -1362, -1362, -1362, -1362, -1362, -1362,   686,
     690,   797, -1362, -1362,   692,   650, -1362, -1362, -1362, -1362,
   -1362,   659,   341,   722,   834,   661,  -117, -1362, -1362, -1362,
   -1362, -1362, -1362,   694,   797, -1362,   663, -1362, -1362, -1362,
     665,   341,   695, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362,   838,   844, -1362,   -38, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   696,   697,   797, -1362,
   -1362,   699,   700, -1362, -1362, -1362, -1362, -1362,   669,   341,
     671,   145, -1362, -1362,   702,   797,   673, -1362, -1362, -1362,
     675,   286,   704, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362,   847,   496, -1362, -1362, -1362, -1362, -1362, -1362,
     706,   708, -1362, -1362, -1362,   714,   797,   681, -1362,   851,
     716, -1362, -1362, -1362, -1362,   710, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362,   852, -1362, -1362, -1362, -1362, -1362, -1362,
     855, -1362,   652,   132, -1362, -1362, -1362, -1362,   683,   307,
   -1362, -1362,   718,   797,   685, -1362, -1362, -1362,   687,   319,
     724, -1362, -1362, -1362, -1362, -1362, -1362,   -84, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362,   723,   797,   691, -1362,   716, -1362, -1362,
   -1362, -1362,   725, -1362, -1362, -1362, -1362,   860,   861, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362,   693,   449,   857, -1362, -1362,   513, -1362, -1362, -1362,
   -1362,   698,   341, -1362,   730,   797,   701, -1362,   716, -1362,
   -1362, -1362, -1362, -1362,   731,   733, -1362,   735, -1362, -1362,
   -1362, -1362, -1362,   739, -1362, -1362,   -50, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362,   737,   797,   703, -1362,   716, -1362, -1362, -1362, -1362,
     740, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362,   746,   741, -1362, -1362,   747, -1362, -1362,   863,
   -1362,   743,   797,   705, -1362,   716, -1362, -1362, -1362, -1362,
     749, -1362, -1362, -1362, -1362,   -76, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362,   707,    31,   748, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362,   751,   797,   709, -1362,   716, -1362, -1362, -1362,
   -1362,   752, -1362, -1362, -1362,   711, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362,   753,   771, -1362, -1362,   747, -1362,
     772,   797,   713, -1362,   716, -1362, -1362, -1362, -1362,   773,
   -1362, -1362,   510,   510, -1362, -1362,   715,   382, -1362,   717,
     199, -1362, -1362,   777,   797,   719, -1362,   716, -1362, -1362,
   -1362, -1362,   778, -1362, -1362, -1362, -1362, -1362, -1362,   788,
     774, -1362, -1362,   747,  -111, -1362, -1362, -1362, -1362,   862,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362,   797,   721, -1362,   716, -1362, -1362, -1362, -1362,   791,
   -1362, -1362,   868,     9, -1362, -1362, -1362, -1362,   866,   511,
   -1362, -1362,   726,   382, -1362,   790,   797,   728, -1362,   716,
   -1362, -1362, -1362, -1362,   792, -1362, -1362, -1362, -1362,   793,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   716,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362,   797,   732, -1362,   716, -1362, -1362, -1362, -1362,   795,
   -1362, -1362, -1362, -1362,   734,   382, -1362,  -110,   510,   871,
     736, -1362,   716, -1362, -1362, -1362, -1362,   794, -1362, -1362,
   -1362,   799, -1362,   874, -1362, -1362, -1362, -1362, -1362, -1362,
     802, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362,   797,   738, -1362,   716, -1362, -1362, -1362, -1362,
     803, -1362, -1362, -1362, -1362, -1362,   804, -1362,   742, -1362,
     716, -1362, -1362, -1362, -1362,   806, -1362, -1362,   812, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   875,
   -1362,   716, -1362, -1362, -1362, -1362,   813, -1362, -1362, -1362,
   -1362,   808,   878,   879, -1362,   744, -1362,   716, -1362, -1362,
   -1362, -1362,   809, -1362, -1362, -1362,   716, -1362, -1362, -1362,
   -1362,   814, -1362, -1362, -1362, -1362, -1362,   816, -1362, -1362,
   -1362, -1362, -1362,   716, -1362, -1362, -1362, -1362,   818, -1362,
   -1362,   819, -1362, -1362, -1362, -1362, -1362,   820, -1362, -1362,
   -1362, -1362
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   841, -1362,
     865, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362,   825, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362,   498, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
     826, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362,   415, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   822, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362,   316, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   599, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   274, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   271, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362,   268, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362,   265, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
     262, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   259, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   255, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362,   257, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362,   258, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
     260, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   246, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   245, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362,   243, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,    14, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
     -40, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362,  -495, -1112, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362,  -293, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362,  -485, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362,    -9, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362,   -89, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,  -362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,   -69,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362,  -138, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,  -429, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362,   -32, -1362, -1362, -1362,
   -1362, -1362,  -204, -1362, -1362, -1362, -1362,  -500, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1074, -1362, -1362, -1362,
    -121, -1362, -1362, -1362, -1362, -1362, -1024, -1362, -1362, -1361,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362,  -482, -1362, -1362,
   -1362, -1073, -1362, -1362, -1362, -1362, -1362, -1362, -1070, -1362,
   -1362, -1362, -1355, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
    -170, -1362, -1362, -1362,  -481, -1362, -1362, -1362,  -872, -1362,
   -1016, -1111, -1362, -1362,  -847, -1362, -1362, -1362,  -112, -1362,
     -99,  -134, -1362, -1362,  -819, -1362, -1212, -1287, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1175, -1362, -1362, -1362,
   -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362, -1362,
   -1362,  -344,  -355, -1362, -1362
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     469,   466,   596,   600,   217,  1097,   468,   866,  1106,  1230,
     926,   890,   380,  1531,   499,   222,   452,  1184,  1187,  1398,
     376,  1188,  1321,     7,   480,   460,   461,  1139,  1128,   250,
     244,   241,   247,   367,   226,   653,  1485,   223,  1299,   238,
     657,   349,  1487,   354,  1378,   661,  1417,   622,  1269,   196,
     622,   491,   492,   493,  1118,   644,   229,  1429,   644,   644,
    1118,  1118,  1165,  1362,   639,  1174,   627,   109,   827,   628,
     658,   640,  1372,  1119,  1430,   654,   736,  1210,   623,  1196,
     955,   714,   644,  1516,  1588,  1262,  1265,   644,   340,  1266,
     348,  1398,   353,   334,   197,  1418,   644,   738,   645,   644,
    1390,     6,  1546,    11,   690,   691,   198,   197,  1548,   650,
    1237,  1337,   734,  1423,   110,  1300,   666,   662,   111,   198,
     112,   666,   113,   337,   114,   667,    13,   416,   663,   338,
     744,  1301,   227,   224,   377,   368,  1398,   242,   245,  1301,
    1413,   251,   248,   239,   453,  1288,   500,  1274,  1331,  1334,
     619,   653,  1335,   616,  1584,   657,   230,  1373,   960,   661,
    1586,   961,  1182,   644,   214,  1301,   662,   635,   215,   971,
     972,   429,   636,   431,   730,   433,  1148,   741,  1314,  1149,
    1150,  1450,  1151,   859,    16,   444,   590,   446,    91,   591,
      29,   214,   974,   592,   975,   215,    37,   593,    38,    39,
     971,   972,   759,   760,   639,   277,   976,   977,  1348,  1475,
     635,   727,   973,   451,   438,   724,   440,   590,   442,  1355,
     591,    46,   214,   974,   592,   975,   215,    93,   593,    94,
      95,  1532,  1510,   381,   382,   383,   384,   976,   977,  1045,
      92,   337,   214,   591,  1191,   214,   215,   338,   278,   215,
     181,   593,   182,   183,   702,   101,  1383,   110,   708,   709,
     710,   111,   279,   112,   280,   113,   281,   114,   282,  1528,
     283,   805,   806,   128,    54,   145,   284,   176,   285,   173,
     286,   179,   287,   180,   288,   206,   289,  1268,   290,   266,
     291,   232,   292,   188,  1561,   590,  1406,   253,   591,   326,
     214,   267,   592,    55,   215,    56,   593,    57,   335,    58,
     345,    59,   350,    60,  1567,    61,   355,    62,   356,    63,
     363,    64,   718,    65,  1182,   628,   364,   590,  1055,  1576,
     365,   971,   972,   268,   592,   269,   270,  1443,   762,  1205,
    1206,  1207,  1208,   771,     1,     2,   883,  1597,   590,  1149,
    1150,   591,  1151,   214,   974,   592,   975,   215,   366,   593,
     590,  1055,   371,   595,   370,  1468,   374,   592,   976,   977,
      19,    20,   394,  1484,   395,   396,  1283,  1284,  1285,  1286,
    1613,   372,   590,  1055,  1496,   591,    24,    25,  1503,   592,
      55,   375,    56,   593,    57,  1622,    58,   373,    59,   379,
      60,   393,    61,  1338,    62,  1230,    63,   413,    64,   392,
      65,  1022,   811,   422,  1023,  1079,  1628,   434,  1080,   406,
     407,   408,   822,   590,  1055,  1521,   591,   790,   791,   792,
     592,   425,  1639,   464,   593,  1205,  1206,  1207,  1208,  1545,
     447,  1642,    32,    33,    49,    50,   104,   105,   130,   131,
    1554,   135,   136,   843,   140,   141,   148,   149,  1648,   478,
     153,   154,   854,   158,   159,   689,  1182,   163,   164,   168,
     169,   481,   867,   971,   972,   191,   192,   233,   234,   254,
     255,   261,   262,   328,   329,  1569,   827,   479,  1060,  1061,
     590,  1583,   470,   591,   878,   214,   974,   592,   975,   215,
     387,   593,   358,   359,   891,   386,   387,   401,   402,   485,
     976,   977,   417,   418,   455,   456,   460,   461,   472,   473,
     571,   917,   494,   495,  1437,   503,   504,   486,   927,   509,
     510,   514,   515,   519,   520,   487,  1606,   524,   525,   530,
     531,   535,   536,   578,   278,   540,   541,   545,   546,   502,
    1107,  1108,   550,   551,   580,   966,   555,   556,   279,   508,
     280,   529,   281,   758,   282,   581,   283,   561,   562,  1140,
    1141,   560,   284,   579,   285,   582,   286,   605,   287,   473,
     288,   583,   289,   604,   290,   606,   291,   609,   292,  1028,
     566,   567,   572,   573,   587,   588,   631,   632,   613,   671,
     672,   675,   676,   685,   686,   703,   704,  1175,  1176,  1186,
    1189,   614,   721,   632,   615,   748,   672,   621,  1064,  1215,
     754,   755,   772,   773,   787,   788,   800,   801,   812,   813,
     844,   845,   804,   868,   869,   892,   893,   900,   901,   905,
     906,   918,   919,   620,   911,   912,   928,   929,   934,   935,
     939,   940,   681,  1085,   945,   946,   998,   999,  1003,  1004,
     626,  1009,  1010,  1036,  1037,  1052,  1053,  1066,  1067,  1102,
    1103,  1113,  1114,  1130,  1131,  1135,  1136,  1264,  1267,  1170,
    1171,  1177,  1178,  1197,  1198,  1202,  1203,  1293,  1224,  1225,
    1129,  1238,  1239,  1256,  1257,  1275,  1276,  1280,  1281,   573,
    1143,  1315,  1316,  1325,  1326,  1340,  1225,  1144,  1344,  1345,
    1147,  1356,  1357,  1384,  1385,  1407,  1408,  1424,  1425,  1444,
    1445,  1453,  1454,  1469,  1470,  1479,  1480,  1489,  1490,  1504,
    1505,  1522,  1523,   643,  1535,  1536,  1540,  1541,  1555,  1556,
    1333,  1336,  1570,  1571,  1578,  1579,  1591,  1592,  1607,  1608,
    1349,  1350,  1616,  1617,  1633,  1634,   670,   692,   693,   694,
     711,   695,   712,   698,   750,   761,   716,   713,   676,   717,
     720,   723,   726,   729,   740,   746,   743,   763,   747,   764,
     767,   777,   778,   782,   783,   784,   785,   786,   797,   798,
     799,  1251,   807,   817,   818,   824,   823,   830,   808,   836,
     827,   837,   831,   838,   832,   841,   833,   849,   834,   850,
     842,   839,   835,   855,   859,   873,   840,   862,   874,   875,
     856,   876,   897,   910,   880,   879,   886,  1309,   883,   944,
    1008,   922,   951,  1015,  1034,  1029,  1062,  1045,  1063,  1065,
    1086,  1072,  1112,  1109,   967,   956,  1145,   912,   946,  1022,
    1146,   960,  1010,  1223,  1018,  1041,  1048,  1243,  1250,  1042,
    1252,  1075,  1092,  1323,  1324,  1339,  1254,  1142,  1394,  1401,
    1518,  1093,  1160,  1124,  1530,  1460,  1533,  1590,  1161,  1118,
    1601,  1192,  1249,  1625,  1631,  1632,   100,   482,  1363,    45,
     584,   682,   129,   414,  1098,  1370,  1229,  1270,   715,  1233,
     719,   722,   725,   728,  1220,   731,   735,  1079,  1310,  1166,
    1512,  1366,   737,  1351,   745,  1486,  1488,   739,   749,  1495,
    1438,   751,  1379,  1049,   742,  1322,  1402,  1414,   968,  1517,
    1392,  1393,  1298,  1341,  1451,  1513,  1099,  1244,  1439,  1030,
    1300,  1395,   207,  1087,  1167,  1418,  1461,  1071,  1391,  1255,
       0,  1476,     0,     0,     0,  1464,  1364,     0,  1371,     0,
    1511,  1367,  1301,     0,  1499,     0,     0,     0,  1415,  1416,
    1185,  1529,     0,     0,  1562,  1577,     0,  1550,  1373,     0,
    1598,  1547,  1549,  1614,  1624,     0,     0,     0,     0,     0,
       0,     0,  1623,  1565,     0,  1640,     0,  1629,  1643,     0,
       0,     0,  1649,     0,  1644,     0,     0,  1650,  1651,  1452,
    1604,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1615,  1600,   327,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1585,  1587,  1630,     0,     0,  1263,     0,
       0,     0,     0,     0,     0,     0,  1498,     0,  1477,  1478,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1519,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1332,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1563,  1564,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1589,  1599,     0,     0,     0,     0,
    1602,  1603,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1645,  1646,     0,  1494
};

static const yytype_int16 yycheck[] =
{
     355,   345,   484,   484,   125,  1021,   350,   826,  1032,  1121,
     882,   858,     8,     4,     4,   127,     4,  1091,  1091,  1306,
       4,  1091,  1197,    67,   379,     6,     7,  1051,  1044,     4,
       4,     4,     4,     4,     4,   535,  1397,     4,   122,     4,
     540,   211,  1397,   213,  1256,   545,   122,   107,  1159,    74,
     107,   406,   407,   408,   171,   145,     4,    26,   145,   145,
     171,   171,  1078,  1238,   143,  1089,   140,    72,    37,   143,
     160,   150,   122,   190,    43,   162,   162,  1101,   138,  1095,
     899,   138,   145,   194,   194,  1159,  1159,   145,   209,  1159,
     211,  1378,   213,   205,   119,   171,   145,   160,   156,   145,
    1275,     0,  1463,    14,   586,   586,   131,   119,  1463,   158,
    1126,  1222,   158,  1325,   119,   199,   143,   143,   123,   131,
     125,   143,   127,    45,   129,   152,    15,   297,   154,    51,
     152,   215,   102,   100,   118,   106,  1423,   110,   112,   215,
    1315,   116,   114,   108,   132,  1169,   136,  1163,  1222,  1222,
     494,   651,  1222,   134,  1515,   655,   104,   207,   171,   659,
    1515,   174,    17,   145,    46,   215,   143,   143,    50,    24,
      25,   305,   148,   307,   156,   309,   214,   154,  1194,   217,
     218,  1356,   220,    38,    69,   319,    41,   321,     5,    44,
      71,    46,    47,    48,    49,    50,    79,    52,    81,    82,
      24,    25,   684,   684,   143,    76,    61,    62,  1232,  1384,
     143,   150,    36,   325,   313,   148,   315,    41,   317,  1235,
      44,    73,    46,    47,    48,    49,    50,    83,    52,    85,
      86,   222,  1407,   229,   230,   231,   232,    61,    62,    40,
      68,    45,    46,    44,  1091,    46,    50,    51,   119,    50,
      87,    52,    89,    90,   609,    75,  1272,   119,   613,   614,
     615,   123,   133,   125,   135,   127,   137,   129,   139,  1444,
     141,   753,   753,    70,    70,    66,   147,    16,   149,    65,
     151,    80,   153,     5,   155,    72,   157,  1159,   159,    84,
     161,     3,   163,    77,  1469,    41,  1312,     3,    44,    74,
      46,     5,    48,    99,    50,   101,    52,   103,    10,   105,
      10,   107,    10,   109,  1489,   111,     3,   113,    10,   115,
     100,   117,   140,   119,    17,   143,   102,    41,    42,  1504,
     104,    24,    25,    91,    48,    93,    94,  1353,   693,    53,
      54,    55,    56,   698,    12,    13,    39,  1522,    41,   217,
     218,    44,   220,    46,    47,    48,    49,    50,     8,    52,
      41,    42,   110,   484,   108,  1381,   116,    48,    61,    62,
      10,    11,    95,  1397,    97,    98,    57,    58,    59,    60,
    1555,   112,    41,    42,  1400,    44,    10,    11,  1404,    48,
      99,     8,   101,    52,   103,  1570,   105,   114,   107,     6,
     109,     5,   111,  1222,   113,  1517,   115,    76,   117,    88,
     119,   199,   767,    18,   202,   207,  1591,    20,   210,    30,
      31,    32,   777,    41,    42,  1441,    44,    21,    22,    23,
      48,    19,  1607,     3,    52,    53,    54,    55,    56,  1463,
      27,  1616,    10,    11,    10,    11,    10,    11,    10,    11,
    1466,    10,    11,   808,    10,    11,    10,    11,  1633,   106,
      10,    11,   817,    10,    11,   586,    17,    10,    11,    10,
      11,   120,   827,    24,    25,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,  1501,    37,   118,   970,   970,
      41,  1515,     6,    44,   849,    46,    47,    48,    49,    50,
     121,    52,    10,    11,   859,   120,   121,    10,    11,    92,
      61,    62,    10,    11,    10,    11,     6,     7,   120,   121,
     132,   876,    10,    11,  1343,    10,    11,     5,   883,    10,
      11,    10,    11,    10,    11,   167,  1552,    10,    11,    10,
      11,    10,    11,   124,   119,    10,    11,    10,    11,     8,
    1032,  1032,    10,    11,   126,   910,    10,    11,   133,     8,
     135,     8,   137,   684,   139,   128,   141,    10,    11,  1051,
    1051,     8,   147,     8,   149,   130,   151,    78,   153,   121,
     155,   120,   157,    96,   159,   195,   161,    33,   163,   944,
      10,    11,   120,   121,    10,    11,   142,   143,     6,   164,
     165,   120,   121,    10,    11,    10,    11,  1089,  1089,  1091,
    1091,     6,   142,   143,     6,   164,   165,     6,   973,  1101,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,   753,    10,    11,    10,    11,    10,    11,    10,
      11,   212,   213,   136,   170,   171,    10,    11,    10,    11,
      10,    11,   120,  1008,   198,   199,    10,    11,    10,    11,
       6,   206,   207,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,  1159,  1159,    10,
      11,    10,    11,    10,    11,    10,    11,  1169,   192,   193,
    1045,    10,    11,    10,    11,    10,    11,    10,    11,   121,
    1055,    10,    11,    10,    11,   192,   193,  1062,    10,    11,
    1065,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,     6,   223,   224,    10,    11,    10,    11,
    1222,  1222,    10,    11,    10,    11,    10,    11,    10,    11,
    1232,  1232,    10,    11,    10,    11,     6,   122,     3,     3,
     134,   203,     8,    34,   120,   122,     8,    10,   121,    10,
      10,    10,    10,     8,    10,     8,    10,     8,    10,   211,
      35,     6,   169,     4,     4,     4,     4,     4,     4,     4,
       4,  1146,   122,     6,   197,   173,   168,   108,    28,     3,
      37,     3,   144,     3,   144,   166,   144,     6,   144,   205,
     122,   144,   146,   196,    38,     8,   144,   175,     8,     8,
     201,     6,   189,     6,   209,   204,   175,  1182,    39,     6,
       6,   175,   191,   121,    29,   198,     3,    40,     3,     3,
     206,   121,     8,   121,   170,   177,     8,   171,   199,   199,
       6,   171,   207,     6,   177,   176,   174,     6,     6,   181,
       5,   177,   176,     3,     3,     8,   214,   172,   122,     6,
       8,   181,   176,   179,     6,   122,    10,     6,   181,   171,
       6,   179,   172,     8,     6,     6,    45,   389,  1243,    24,
     475,   575,    67,   294,   202,  1250,   190,   179,   624,   185,
     629,   633,   637,   641,   200,   646,   651,   207,   185,   210,
     122,   178,   655,   183,   668,  1397,  1397,   659,   673,  1400,
     172,   678,   185,   963,   664,   200,   183,   178,   914,  1424,
    1285,  1286,   208,  1226,   182,  1420,  1025,   221,   187,   948,
     199,  1303,   116,  1012,  1082,   171,  1375,   979,   208,  1153,
      -1,   178,    -1,    -1,    -1,   183,   225,    -1,   219,    -1,
     182,   226,   215,    -1,   187,    -1,    -1,    -1,  1323,  1324,
    1091,   180,    -1,    -1,   182,   180,    -1,   187,   207,    -1,
     186,  1463,  1463,   180,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   200,    -1,   186,    -1,   184,   184,    -1,
      -1,    -1,   184,    -1,   188,    -1,    -1,   188,   188,  1364,
     208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     216,   222,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1515,  1515,   227,    -1,    -1,  1159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1401,    -1,  1392,  1393,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1430,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1477,  1478,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1518,  1530,    -1,    -1,    -1,    -1,
    1535,  1536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1590,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1631,  1632,    -1,  1400
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   234,   235,   236,     0,    67,   243,   244,
     245,    14,   237,    15,   241,   242,    69,   270,   271,    10,
      11,   246,   247,   248,    10,    11,   238,   239,   240,    71,
     356,   357,    10,    11,   272,   273,   274,    79,    81,    82,
     249,   250,   251,   252,   253,   243,    73,   404,   405,    10,
      11,   358,   359,   360,    70,    99,   101,   103,   105,   107,
     109,   111,   113,   115,   117,   119,   275,   276,   277,   278,
     279,   284,   285,   290,   291,   296,   297,   304,   305,   310,
     311,   316,   317,   322,   323,   328,   329,   334,   335,   342,
     343,     5,    68,    83,    85,    86,   254,   255,   256,   257,
     241,    75,   432,   433,    10,    11,   406,   407,   408,    72,
     119,   123,   125,   127,   129,   361,   362,   363,   364,   365,
     371,   372,   378,   379,   385,   386,   390,   391,    70,   277,
      10,    11,   280,   281,   282,    10,    11,   286,   287,   288,
      10,    11,   292,   293,   294,    66,   298,   299,    10,    11,
     306,   307,   308,    10,    11,   312,   313,   314,    10,    11,
     318,   319,   320,    10,    11,   324,   325,   326,    10,    11,
     330,   331,   332,    65,   336,   337,    16,   344,  1001,    80,
       5,    87,    89,    90,   258,   259,   260,   261,    77,   564,
     565,    10,    11,   434,   435,   436,    74,   119,   131,   409,
     410,   411,   412,   413,   418,   419,    72,   363,   366,   367,
     373,   374,   380,   381,    46,    50,   387,   943,   944,   945,
     946,   392,  1001,     4,   100,   283,     4,   102,   289,     4,
     104,   295,     3,    10,    11,   300,   301,   302,     4,   108,
     309,     4,   110,   315,     4,   112,   321,     4,   114,   327,
       4,   116,   333,     3,    10,    11,   338,   339,   340,  1035,
    1036,    10,    11,   345,   346,   347,    84,     5,    91,    93,
      94,   262,   263,   264,   265,   566,   567,    76,   119,   133,
     135,   137,   139,   141,   147,   149,   151,   153,   155,   157,
     159,   161,   163,   437,   438,   439,   440,   441,   448,   449,
     454,   455,   462,   463,   470,   471,   478,   479,   486,   487,
     494,   495,   502,   503,   510,   511,   518,   519,   526,   527,
     534,   535,   542,   543,   550,   551,    74,   411,    10,    11,
     414,   415,   416,   420,  1001,    10,   369,    45,    51,   368,
     943,   983,   984,   985,   986,    10,   376,   375,   943,   983,
      10,   383,   382,   943,   983,     3,    10,   388,    10,    11,
     393,   394,   395,   100,   102,   104,     8,     4,   106,   303,
     108,   110,   112,   114,   116,     8,     4,   118,   341,     6,
       8,   229,   230,   231,   232,  1037,   120,   121,   348,   349,
     350,   351,    88,     5,    95,    97,    98,   266,   267,   268,
     269,    10,    11,   569,   570,   571,    30,    31,    32,   568,
     992,   998,  1008,    76,   439,   442,   983,    10,    11,   450,
     451,   452,    18,   456,   996,    19,   464,  1004,   472,  1004,
     480,  1004,   488,  1004,    20,   496,  1003,   504,  1003,   512,
    1003,   520,  1003,   528,  1004,   536,  1004,    27,   544,  1005,
     552,  1001,     4,   132,   417,    10,    11,   421,   422,   423,
       6,     7,   370,  1034,     3,   377,  1034,   384,  1034,  1035,
       6,   389,   120,   121,   396,   397,   398,   399,   106,   118,
    1035,   120,   350,   352,   353,    92,     5,   167,   572,   573,
     574,  1035,  1035,  1035,    10,    11,   443,   444,   445,     4,
     136,   453,     8,    10,    11,   457,   458,   459,     8,    10,
      11,   465,   466,   467,    10,    11,   473,   474,   475,    10,
      11,   481,   482,   483,    10,    11,   489,   490,   491,     8,
      10,    11,   497,   498,   499,    10,    11,   505,   506,   507,
      10,    11,   513,   514,   515,    10,    11,   521,   522,   523,
      10,    11,   529,   530,   531,    10,    11,   537,   538,   539,
       8,    10,    11,   545,   546,   547,    10,    11,   553,   554,
     555,   132,   120,   121,   424,   425,   426,   427,   124,     8,
     126,   128,   130,   120,   398,   400,   401,    10,    11,   355,
      41,    44,    48,    52,   354,   943,   960,   961,   962,   963,
     987,   988,   989,   990,    96,    78,   195,   704,   705,    33,
     575,   576,  1002,     6,     6,     6,   134,   446,   447,  1034,
     136,     6,   107,   138,   460,   461,     6,   140,   143,   468,
     469,   142,   143,   476,   477,   143,   148,   484,   485,   143,
     150,   492,   493,     6,   145,   156,   500,   501,   930,   931,
     158,   508,   509,   930,   162,   516,   517,   930,   160,   524,
     525,   930,   143,   154,   532,   533,   143,   152,   540,   541,
       6,   164,   165,   548,   549,   120,   121,   556,   557,   558,
     559,   120,   426,   428,   429,    10,    11,   403,   402,   943,
     960,   987,   122,     3,     3,   203,   806,   807,    34,   706,
     707,  1000,  1035,    10,    11,   577,   578,   579,  1035,  1035,
    1035,   134,     8,    10,   138,   461,     8,    10,   140,   469,
      10,   142,   477,    10,   148,   485,    10,   150,   493,     8,
     156,   501,   932,   933,   158,   509,   162,   517,   160,   525,
      10,   154,   533,    10,   152,   541,     8,    10,   164,   549,
     120,   558,   560,   561,    10,    11,   431,   430,   943,   960,
     987,   122,  1035,     8,   211,   908,   909,    35,   808,   809,
     999,  1035,    10,    11,   708,   709,   710,     6,   169,   580,
     581,   582,     4,     4,     4,     4,     4,    10,    11,   938,
      21,    22,    23,   934,   935,   936,   937,     4,     4,     4,
      10,    11,   563,   562,   943,   960,   987,   122,    28,   910,
    1006,  1035,    10,    11,   810,   811,   812,     6,   197,   711,
     712,   713,  1035,   168,   173,   595,   596,    37,   583,  1007,
     108,   144,   144,   144,   144,   146,     3,     3,     3,   144,
     144,   166,   122,  1035,    10,    11,   911,   912,   913,     6,
     205,   813,   814,   815,  1035,   196,   201,   726,   727,    38,
     714,   997,   175,   609,   610,   597,  1007,  1035,    10,    11,
     584,   585,   586,     8,     8,     8,     6,   914,  1035,   204,
     209,   828,   829,    39,   816,   991,   175,   740,   741,   728,
     997,  1035,    10,    11,   715,   716,   717,   189,   657,   658,
      10,    11,   611,   612,   613,    10,    11,   598,   599,   600,
       6,   170,   171,   587,   588,   589,   590,  1035,   212,   213,
     915,   916,   175,   842,   843,   830,   991,  1035,    10,    11,
     817,   818,   819,   788,    10,    11,   742,   743,   744,    10,
      11,   729,   730,   731,     6,   198,   199,   718,   719,   720,
     721,   191,   671,   672,   659,  1007,   177,   614,   615,   616,
     171,   174,   601,   602,   603,   604,  1035,   170,   589,   591,
     592,    24,    25,    36,    47,    49,    61,    62,   917,   918,
     919,   939,   940,   941,   942,   943,   960,   964,   965,   966,
     967,   971,   972,   973,   974,   987,   995,   890,    10,    11,
     844,   845,   846,    10,    11,   831,   832,   833,     6,   206,
     207,   820,   821,   822,   823,   121,   789,   790,   177,   745,
     746,   747,   199,   202,   732,   733,   734,   735,  1035,   198,
     720,   722,   723,   686,    29,   673,    10,    11,   660,   661,
     662,   176,   181,   622,   623,    40,   617,   993,   174,   603,
     605,   606,    10,    11,   594,    42,   593,   949,   950,   951,
     960,   987,     3,     3,  1035,     3,    10,    11,   920,   921,
     922,   919,   121,   891,   892,   177,   847,   848,   849,   207,
     210,   834,   835,   836,   837,  1035,   206,   822,   824,   825,
     791,   792,   176,   181,   753,   754,   748,   993,   202,   734,
     736,   737,    10,    11,   725,   724,   949,   960,   987,   121,
     687,   688,     8,    10,    11,   674,   675,   676,   171,   190,
     663,   664,   665,   666,   179,   629,   630,   624,   993,  1035,
      10,    11,   618,   619,   620,    10,    11,   608,   607,   949,
     960,   987,   172,  1035,  1035,     8,     6,  1035,   214,   217,
     218,   220,   923,   924,   925,   926,   927,   928,   893,   894,
     176,   181,   855,   856,   850,   993,   210,   836,   838,   839,
      10,    11,   827,   826,   949,   960,   987,    10,    11,   794,
     795,   796,    17,   793,   939,   943,   960,   964,   971,   987,
     994,   997,   179,   760,   761,   755,   993,    10,    11,   749,
     750,   751,    10,    11,   739,    53,    54,    55,    56,   738,
     949,   952,   953,   954,   955,   960,   975,   976,   977,   978,
     200,   689,   690,     6,   192,   193,   677,   678,   679,   190,
     665,   667,   668,   185,   636,   637,   631,   993,    10,    11,
     625,   626,   627,     6,   221,   621,  1019,  1020,  1027,   172,
       6,  1035,     5,   929,   214,   925,    10,    11,   896,   897,
     898,   895,   939,   943,   960,   964,   971,   987,   991,   994,
     179,   862,   863,   857,   993,    10,    11,   851,   852,   853,
      10,    11,   841,    57,    58,    59,    60,   840,   949,   956,
     957,   958,   959,   960,   979,   980,   981,   982,   208,   122,
     199,   215,   797,   798,   799,   800,  1009,  1010,  1011,  1035,
     185,   767,   768,   762,   993,    10,    11,   756,   757,   758,
     752,  1019,   200,     3,     3,    10,    11,   692,   693,   694,
     691,   939,   943,   960,   964,   971,   987,   994,  1007,     8,
     192,   678,   680,   681,    10,    11,   670,   669,   949,   960,
     987,   183,   643,   644,   638,   993,    10,    11,   632,   633,
     634,   628,  1019,  1035,   225,  1028,   178,   226,  1021,  1022,
    1035,   219,   122,   207,   899,   900,   901,   902,  1009,   185,
     869,   870,   864,   993,    10,    11,   858,   859,   860,   854,
    1019,   208,  1035,  1035,   122,   799,   801,   802,  1010,  1012,
    1013,     6,   183,   774,   775,   769,   993,    10,    11,   763,
     764,   765,   759,  1019,   178,  1035,  1035,   122,   171,   695,
     696,   697,   698,  1009,    10,    11,   683,   684,   685,    26,
      43,   682,   947,   948,   968,   969,   970,  1007,   172,   187,
     650,   651,   645,   993,    10,    11,   639,   640,   641,   635,
    1019,   182,  1035,    10,    11,  1029,  1030,  1031,  1023,  1024,
     122,   901,   903,   904,   183,   876,   877,   871,   993,    10,
      11,   865,   866,   867,   861,  1019,   178,  1034,  1034,    10,
      11,   804,   805,   803,   949,   952,   960,   975,   987,    10,
      11,  1015,  1016,  1017,   943,   987,   993,  1014,  1035,   187,
     781,   782,   776,   993,    10,    11,   770,   771,   772,   766,
    1019,   182,   122,   697,   699,   700,   194,   664,     8,  1035,
     652,   993,    10,    11,   646,   647,   648,   642,  1019,   180,
       6,     4,   222,    10,  1026,   223,   224,  1025,  1032,  1033,
      10,    11,   906,   907,   905,   949,   952,   960,   975,   987,
     187,   883,   884,   878,   993,    10,    11,   872,   873,   874,
     868,  1019,   182,  1035,  1035,   200,  1018,  1019,   783,   993,
      10,    11,   777,   778,   779,   773,  1019,   180,    10,    11,
     702,   703,   701,   949,   952,   960,   975,   987,   194,  1034,
       6,    10,    11,   653,   654,   655,   649,  1019,   186,  1035,
     222,     6,  1035,  1035,   208,   885,   993,    10,    11,   879,
     880,   881,   875,  1019,   180,   216,    10,    11,   784,   785,
     786,   780,  1019,   186,   172,     8,  1035,   656,  1019,   184,
     227,     6,     6,    10,    11,   886,   887,   888,   882,  1019,
     186,   787,  1019,   184,   188,  1035,  1035,   889,  1019,   184,
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
}
    break;

  case 30:

    {
	osglData->fileName = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 37:

    {
	osglData->source = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 44:

    {
	osglData->description = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 51:

    {
	osglData->fileCreator = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 58:

    {
	osglData->licence = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 61:

    {
	parserData->serviceURIPresent = false;	
	parserData->serviceNamePresent = false;
	parserData->instanceNamePresent = false;
	parserData->instanceLocationPresent = false;
	parserData->jobIDPresent = false;
	parserData->solverToInvokePresent = false;
	parserData->licensePresent = false;
	parserData->usernamePresent = false;
	parserData->passwordPresent = false;
	parserData->contactPresent = false;
	parserData->otherGeneralOptionsPresent = false;
	osoption->general = new GeneralOption();
}
    break;

  case 82:

    {	if (parserData->serviceURIPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <serviceURI> element allowed");
	else
		parserData->serviceURIPresent = true;
	
}
    break;

  case 88:

    {
		if (osoption->setServiceURI((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceURI failed");
			free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 90:

    {	if (parserData->serviceNamePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one serviceName element allowed");
		parserData->serviceNamePresent = true;
	}
    break;

  case 96:

    {
			osoption->setServiceName((yyvsp[(1) - (1)].sval)); 
			free((yyvsp[(1) - (1)].sval)); 
			parserData->errorText = NULL;
		}
    break;

  case 98:

    {	if (parserData->instanceNamePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one instanceName element allowed");
		parserData->instanceNamePresent = true;
	}
    break;

  case 104:

    {
		if (osoption->setInstanceName((yyvsp[(1) - (1)].sval)) == false) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setInstanceName failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 105:

    {
	if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setInstanceLocation failed");
	parserData->errorText = NULL;
}
    break;

  case 106:

    {
		if (parserData->instanceLocationPresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one instanceLocation element allowed");
		parserData->instanceLocationPresent = true;
		parserData->typeAttribute = "local";
	}
    break;

  case 108:

    {   
		if (verifyLocationType(parserData->typeAttribute) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "instance location type not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 109:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 115:

    {	
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
		free((yyvsp[(1) - (1)].sval)); 
	}
    break;

  case 117:

    {	if (parserData->jobIDPresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one jobID element allowed");
		parserData->jobIDPresent = true;
	}
    break;

  case 123:

    {
		if (osoption->setJobID((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setJobID failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 125:

    {
		if (parserData->solverToInvokePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one solverToInvoke element allowed");
		parserData->solverToInvokePresent = true;
	}
    break;

  case 131:

    {
		if (osoption->setSolverToInvoke((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setSolverToInvoke failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 133:

    {
	if (parserData->licensePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <license> element allowed");
	parserData->licensePresent = true;	
}
    break;

  case 139:

    {
		if (osoption->setLicense((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setLicense failed");
		free((yyvsp[(1) - (1)].sval));
		parserData->errorText = NULL;
	}
    break;

  case 141:

    {	if (parserData->usernamePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <username> element allowed");
	parserData->usernamePresent = true;	
}
    break;

  case 147:

    {
		if (osoption->setUserName((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setUsername failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 149:

    {	if (parserData->passwordPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <password> element allowed");
	parserData->passwordPresent = true;	
}
    break;

  case 155:

    {
		if (osoption->setPassword((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setPassword failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 156:

    {
	if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setContact failed");
	parserData->errorText = NULL;
}
    break;

  case 157:

    {
	if (parserData->contactPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <contact> element allowed");
	parserData->contactPresent = true;
	parserData->typeAttribute = "osp";
	parserData->tempStr = "";
}
    break;

  case 159:

    {   
		if (verifyTransportType(parserData->typeAttribute) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "transport type not recognized");
	}
    break;

  case 160:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 166:

    {
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
		free((yyvsp[(1) - (1)].sval));
	}
    break;

  case 168:

    {	if (parserData->otherGeneralOptionsPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <general> <other> element allowed");
	parserData->otherGeneralOptionsPresent = true;
}
    break;

  case 169:

    {
	if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other general options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 170:

    {	if (parserData->numberOf > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 171:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 178:

    {	
	parserData->kounter++;
	if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherGeneralOption failed");
}
    break;

  case 179:

    {	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 180:

    {
	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 183:

    {	if (parserData->nameAttribute.length() == 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 190:

    {
	parserData->minDiskSpacePresent = false;	
	parserData->minMemoryPresent = false;
	parserData->minCPUSpeedPresent = false;
	parserData->minCPUNumberPresent = false;
	parserData->otherSystemOptionsPresent = false;
	osoption->system = new SystemOption();
}
    break;

  case 205:

    {	if (parserData->minDiskSpacePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minDiskSpace element allowed");
		parserData->minDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 212:

    {
	if (osoption->setMinDiskSpace(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinDiskSpace failed");
	parserData->errorText = NULL;
}
    break;

  case 214:

    {	if (parserData->minMemoryPresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minMemory element allowed");
		parserData->minMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 221:

    {
	if (osoption->setMinMemorySize(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinMemorySize failed");
    parserData->errorText = NULL;
}
    break;

  case 223:

    {	if (parserData->minCPUSpeedPresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minCPUSpeed element allowed");
		parserData->minCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "hertz";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 230:

    {	
	if (osoption->setMinCPUSpeed(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
}
    break;

  case 232:

    {	if (parserData->minCPUNumberPresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one minCPUNumber element allowed");
		parserData->minCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	}
    break;

  case 236:

    {
	if (osoption->setMinCPUNumber((yyvsp[(1) - (1)].ival), parserData->descriptionAttribute) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setMinCPUNumber failed");
	//free($1); 
	parserData->errorText = NULL; 
}
    break;

  case 238:

    {
	if (parserData->otherSystemOptionsPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <system> <other> element allowed");
	parserData->otherSystemOptionsPresent = true;
}
    break;

  case 239:

    {
	if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other system options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 240:

    {	if (parserData->numberOf > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 241:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 248:

    {
	parserData->kounter++;
	if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherSystemOption failed");
}
    break;

  case 249:

    {	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 250:

    {	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 253:

    {
		if (parserData->nameAttribute.length() == 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 260:

    {
	parserData->serviceTypePresent = false;	
	parserData->otherServiceOptionsPresent = false;
	osoption->service = new ServiceOption();
}
    break;

  case 272:

    {	if (parserData->serviceTypePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one currentState element allowed");
		parserData->serviceTypePresent = true;
	}
    break;

  case 278:

    {
       parserData->tempStr = (yyvsp[(1) - (1)].sval); 
		free((yyvsp[(1) - (1)].sval));
		if (osoption->setServiceType(parserData->tempStr) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setServiceType failed; current system state not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 280:

    {
	if (parserData->otherServiceOptionsPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <service> <other> element allowed");
	parserData->otherServiceOptionsPresent = true;
}
    break;

  case 281:

    {
	if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other service options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 282:

    {	if (parserData->numberOf > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 283:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 290:

    {	
	parserData->kounter++;
	if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherServiceOption failed");
}
    break;

  case 291:

    {	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 292:

    {	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 295:

    {
		if (parserData->nameAttribute.length() == 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 302:

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

  case 326:

    {	
	if (osoption->setMaxTime(parserData->maxTimeValue, parserData->unitAttribute) == false)       
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "max time request could not be honored");
}
    break;

  case 327:

    {	
	if (parserData->maxTimePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <maxTime> element allowed");
	parserData->maxTimePresent = true;
	parserData->unitAttributePresent = false;	
	parserData->unitAttribute = "second"; 
	parserData->maxTimeValue = OSDBL_MAX;
}
    break;

  case 336:

    {
	parserData->maxTimeValue = parserData->tempVal;
}
    break;

  case 338:

    {	if (parserData->requestedStartTimePresent)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one requestedStartTime element allowed");
		parserData->requestedStartTimePresent = true;
	}
    break;

  case 344:

    {
		if (osoption->setRequestedStartTime((yyvsp[(1) - (1)].sval)) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setRequestedStartTime failed");	
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
		}
    break;

  case 345:

    {
	if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <job> <dependencies> failed");
	delete[] parserData->jobDependencies;
	parserData->jobDependencies = NULL;
}
    break;

  case 346:

    {
	if (parserData->dependenciesPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <dependencies> element allowed");
	parserData->dependenciesPresent = true;
}
    break;

  case 352:

    {
	if (parserData->kounter > parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few job IDs in <dependencies> element");
}
    break;

  case 355:

    {
	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many job IDs in <dependencies> element");
	parserData->jobDependencies[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 356:

    {
	if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <requiredDirectories> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 357:

    {	if (parserData->requiredDirectoriesPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <requiredDirectories> element allowed");
	parserData->requiredDirectoriesPresent = true;
}
    break;

  case 363:

    {
	if (parserData->kounter > parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <requiredDirectories> element");
}
    break;

  case 366:

    {
	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many paths in <requiredDirectories> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 367:

    {
	if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <requiredFiles> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 368:

    {	if (parserData->requiredFilesPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <requiredFiles> element allowed");
	parserData->requiredFilesPresent = true;
}
    break;

  case 374:

    {
	if (parserData->kounter > parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <requiredFiles> element");
}
    break;

  case 377:

    {
	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many paths in <requiredFiles> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval));
	parserData->kounter++;
}
    break;

  case 378:

    {
	if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <directoriesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 379:

    {	if (parserData->directoriesToMakePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <directoriesToMake> element allowed");
	parserData->directoriesToMakePresent = true;
}
    break;

  case 385:

    {
	if (parserData->kounter > parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <directoriesToMake> element");
}
    break;

  case 388:

    {
	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many paths in <directoriesToMake> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 389:

    {
	if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <filesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 390:

    {	if (parserData->filesToMakePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <filesToMake> element allowed");
	parserData->filesToMakePresent = true;
}
    break;

  case 396:

    {
	if (parserData->kounter > parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <filesToMake> element");
}
    break;

  case 399:

    {
	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many paths in <filesToMake> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 400:

    {
	if (osoption->setPathPairs(ENUM_PATHPAIR_input_dir, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMove> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
}
    break;

  case 401:

    {	if (parserData->inputDirectoriesToMovePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <inputDirectoriesToMove> element allowed");
		parserData->inputDirectoriesToMovePresent = true;
}
    break;

  case 407:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <inputDirectoriesToMove> element");
}
    break;

  case 411:

    {
	if (osoption->setPathPairs(ENUM_PATHPAIR_input_file, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputFilesToMove> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
}
    break;

  case 412:

    {	if (parserData->inputFilesToMovePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <inputFilesToMove> element allowed");
		parserData->inputFilesToMovePresent = true;
}
    break;

  case 418:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <inputFilesToMove> element");
}
    break;

  case 422:

    {
	if (osoption->setPathPairs(ENUM_PATHPAIR_output_file, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
}
    break;

  case 423:

    {	if (parserData->outputFilesToMovePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <outputFilesToMove> element allowed");
		parserData->outputFilesToMovePresent = true;
}
    break;

  case 429:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <outputFilesToMake> element");
}
    break;

  case 433:

    {
	if (osoption->setPathPairs(ENUM_PATHPAIR_output_dir, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
}
    break;

  case 434:

    {	if (parserData->outputDirectoriesToMovePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <outputDirectoriesToMove> element allowed");
		parserData->outputDirectoriesToMovePresent = true;
}
    break;

  case 440:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few path pairs in <outputDirectoriesToMake> element");
}
    break;

  case 444:

    {
	if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <filesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 445:

    {	if (parserData->filesToDeletePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <filesToDelete> element allowed");
	parserData->filesToDeletePresent = true;
}
    break;

  case 451:

    {
	if (parserData->kounter > parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <filesToDelete> element");
}
    break;

  case 454:

    {
	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many paths in <filesToDelete> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 455:

    {
	if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <directoriesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 456:

    {	if (parserData->directoriesToDeletePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <directoriesToDelete> element allowed");
	parserData->directoriesToDeletePresent = true;
}
    break;

  case 462:

    {
	if (parserData->kounter > parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few paths in <directoriesToDelete> element");
}
    break;

  case 465:

    {
	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many paths in <directoriesToDelete> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 466:

    {
	if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <processesToKill> failed");
	delete[] parserData->processesToKill;
	parserData->processesToKill = NULL;
}
    break;

  case 467:

    {
	if (parserData->processesToKillPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <processesToKill> element allowed");
	parserData->processesToKillPresent = true;
}
    break;

  case 473:

    {
	if (parserData->kounter > parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few process IDs in <processesToKill> element");
}
    break;

  case 476:

    {
	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many process IDs in <processesToKill> element");
	parserData->processesToKill[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 478:

    {	if (parserData->otherJobOptionsPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one <job> <other> element allowed");
	parserData->otherJobOptionsPresent = true;
}
    break;

  case 479:

    {
	if (parserData->tempInt < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other job options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 480:

    {	if (parserData->numberOf > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 481:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 488:

    {
	parserData->kounter++;
	if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setOtherJobOption failed");
}
    break;

  case 489:

    {	if (parserData->kounter >= parserData->numberOf)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 490:

    {	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 493:

    {
		if (parserData->nameAttribute.length() == 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 500:

    {
	osoption->optimization = new OptimizationOption();
	parserData->numberOfVariablesPresent = false;
	parserData->numberOfObjectivesPresent = false;
	parserData->numberOfConstraintsPresent = false;
}
    break;

  case 504:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osoption->setNumberOfVariables(parserData->tempInt) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfVariables failed");
	}
    break;

  case 505:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfConstraints failed");
	}
    break;

  case 506:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfObjectives failed");
	}
    break;

  case 514:

    {
	parserData->numberOfOtherVariableOptions = 0;
	osoption->optimization->variables = new VariableOption();
}
    break;

  case 515:

    {	
	if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
}
    break;

  case 517:

    {	
	parserData->numberOfOtherVariableOptions = parserData->tempInt;
}
    break;

  case 524:

    {
	if (osoption->setInitVarValues(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
}
    break;

  case 525:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 526:

    {
	parserData->kounter = 0;
	parserData->idxArray = new         int[parserData->numberOfVar];
	parserData->namArray = new std::string[parserData->numberOfVar];
	parserData->valArray = new      double[parserData->numberOfVar];
	for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 527:

    {
		if (parserData->numberOfVar > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValues>: expected at least one <var> element");
	}
    break;

  case 528:

    {
		if (parserData->kounter > parserData->numberOfVar)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialVariableValues>: fewer <var> elements than specified");
	}
    break;

  case 535:

    {
	parserData->kounter++;
}
    break;

  case 536:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
}
    break;

  case 537:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 540:

    {
		if (parserData->idxAttribute < 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 541:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 542:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 546:

    {
	if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString, parserData->namArray) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValuesString> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valueString = NULL;
}
    break;

  case 547:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 548:

    {
	parserData->kounter = 0;
	parserData->idxArray    = new         int[parserData->numberOfVar];
	parserData->namArray    = new std::string[parserData->numberOfVar];
	parserData->valueString = new std::string[parserData->numberOfVar];
	for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfVar; i++) parserData->valueString[i] = "";
}
    break;

  case 549:

    {
		if (parserData->numberOfVar > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <var> element");
	}
    break;

  case 550:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too few initial values in <initialVariableValuesString> element");
	}
    break;

  case 557:

    {
	parserData->kounter++;
}
    break;

  case 558:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "48r 87e WY EUV e7 df"; //random string...
}
    break;

  case 559:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 562:

    {
		if (parserData->idxAttribute < 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 563:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 564:

    {
		parserData->valueString[parserData->kounter] = parserData->valueAttribute;
	}
    break;

  case 569:

    {
	osoption->optimization->variables->initialBasisStatus = new BasisStatus();
}
    break;

  case 576:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 577:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 578:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 585:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 586:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 587:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 594:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 595:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 596:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 603:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 604:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 605:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 612:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 613:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 614:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 621:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 622:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 623:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 630:

    {
	if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
}
    break;

  case 631:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 632:

    {
	parserData->kounter = 0;
	parserData->idxArray = new         int[parserData->numberOfVar];
	parserData->namArray = new std::string[parserData->numberOfVar];
	parserData->valArray = new      double[parserData->numberOfVar];
	for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 633:

    {
		if (parserData->numberOfVar > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <var> element");
	}
    break;

  case 634:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <var> elements than specified");
	}
    break;

  case 641:

    {
	parserData->kounter++;
}
    break;

  case 642:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "1.0";
}
    break;

  case 643:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<var> element must have idx attribute");
//	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
//	parserData->namArray[parserData->kounter] = parserData->nameAttribute;
//	parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
}
    break;

  case 646:

    {
		if (parserData->idxAttribute < 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 647:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 648:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 653:

    {
	parserData->sosIdxAttributePresent = false;	
	parserData->currentSOS = 0;
}
    break;

  case 654:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <sos> elements must be nonnegative");
	parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
}
    break;

  case 655:

    {	if (parserData->numberOfSOS > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <sos> element");
	}
    break;

  case 656:

    {	if (parserData->currentSOS != parserData->numberOfSOS)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <sos> elements than specified");
	}
    break;

  case 662:

    {
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
}
    break;

  case 663:

    {	if (parserData->currentSOS >= parserData->numberOfSOS)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many SOS branching weights");
	parserData->sosIdxAttributePresent = false;
	parserData->groupWeightAttributePresent = false;
	parserData->numberOfVarAttributePresent = false;
	parserData->groupWeight = 1.0;
	parserData->numberOfSOSVar = 0;
}
    break;

  case 664:

    {
	if (!parserData->sosIdxAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index required");
	if (!parserData->numberOfVarAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar required");
}
    break;

  case 668:

    {
		parserData->kounter = 0;
		parserData->idxArray = new         int[parserData->numberOfVar];
		parserData->namArray = new std::string[parserData->numberOfVar];
		parserData->valArray = new      double[parserData->numberOfVar];
		for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
		parserData->numberOfVarAttributePresent = true;
	}
    break;

  case 677:

    { 	 
		parserData->iOther++;
	}
    break;

  case 678:

    {
	if (parserData->iOther >= parserData->numberOfOtherVariableOptions)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherVariableOptions> than specified");
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

  case 679:

    {
		if (!parserData->nameAttributePresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
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

  case 682:

    {
		parserData->kounter = 0;
	}
    break;

  case 683:

    {
		parserData->kounter = 0;
	}
    break;

  case 699:

    { 	
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

  case 700:

    {
	if (parserData->kounter >= parserData->numberOfVar)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <var> elements than specified");
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

  case 704:

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

  case 714:

    {
	parserData->numberOfOtherObjectiveOptions = 0; 
	osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 715:

    {	
	if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
}
    break;

  case 717:

    {	
	parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
}
    break;

  case 724:

    {
	if (osoption->setInitObjValues(parserData->numberOfObj, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialObjectiveValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
}
    break;

  case 725:

    {
	parserData->numberOfObjAttributePresent = false;
}
    break;

  case 726:

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

  case 727:

    {	
		if (parserData->numberOfObj > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: expected at least one <obj> element");
	}
    break;

  case 728:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveValues>: fewer <obj> elements than specified");
	}
    break;

  case 735:

    {
	parserData->kounter++;
}
    break;

  case 736:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->idxAttribute = -1;
}
    break;

  case 740:

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

  case 741:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 742:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 746:

    {
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
}
    break;

  case 747:

    {
	parserData->numberOfObjAttributePresent = false;
}
    break;

  case 748:

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

  case 749:

    {
		if (parserData->numberOfObj > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: expected at least one <obj> element");
	}
    break;

  case 750:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
	}
    break;

  case 757:

    {
	parserData->kounter++;
}
    break;

  case 758:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->lbValueAttributePresent = false;
	parserData->ubValueAttributePresent = false;
	parserData->idxAttribute = -1;
	parserData->lbValueAttribute = "-INF";
	parserData->ubValueAttribute = "INF";
}
    break;

  case 762:

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

  case 763:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 764:

    {
		if (parserData->lbValueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
	}
    break;

  case 765:

    {
		if (parserData->ubValueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
	}
    break;

  case 770:

    {
	osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
}
    break;

  case 777:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 778:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 779:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 786:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 787:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 788:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 795:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 796:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 797:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 804:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 805:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 806:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 813:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 814:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 815:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 822:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 823:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 824:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 832:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 833:

    {
	if (parserData->iOther >= parserData->numberOfOtherObjectiveOptions)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherObjectiveOptions> than specified");
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

  case 834:

    {
		if (!parserData->nameAttributePresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
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

  case 837:

    {
		parserData->kounter = 0;
	}
    break;

  case 838:

    {
		parserData->kounter = 0;
	}
    break;

  case 854:

    {  
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

  case 855:

    {
	if (parserData->kounter >= parserData->numberOfObj)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <obj> elements than specified");
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

  case 856:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	parserData->valueString[parserData->kounter] = parserData->valueAttribute;
	parserData->lbValueString[parserData->kounter] = parserData->lbValueAttribute;
	parserData->ubValueString[parserData->kounter] = parserData->ubValueAttribute;
}
    break;

  case 859:

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

  case 869:

    {
	parserData->numberOfOtherConstraintOptions = 0; 
	osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 870:

    {	
	if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfOtherConstraintOptions failed");
	parserData->iOther = 0;
}
    break;

  case 872:

    {	
	parserData->numberOfOtherConstraintOptions = parserData->tempInt;
}
    break;

  case 879:

    {
	if (osoption->setInitConValues(parserData->numberOfCon, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
}
    break;

  case 880:

    {
	parserData->numberOfConAttributePresent = false;
}
    break;

  case 881:

    {
	parserData->kounter = 0;
	parserData->idxArray = new         int[parserData->numberOfCon];
	parserData->namArray = new std::string[parserData->numberOfCon];
	parserData->valArray = new      double[parserData->numberOfCon];
	for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfCon; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 882:

    {
		if (parserData->numberOfCon > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: expected at least one <con element");
	}
    break;

  case 883:

    {
		if (parserData->kounter > parserData->numberOfCon)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialConstraintValues>: fewer <con> elements than specified");
	}
    break;

  case 890:

    {
	parserData->kounter++;
}
    break;

  case 891:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
}
    break;

  case 892:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 895:

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

  case 896:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 897:

    {
		if (parserData->valueAttribute == "")
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 901:

    {
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
}
    break;

  case 902:

    {
	parserData->numberOfConAttributePresent = false;
}
    break;

  case 903:

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

  case 904:

    {
		if (parserData->numberOfCon > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: expected at least one <con> element");
	}
    break;

  case 905:

    {
		if (parserData->kounter != parserData->numberOfCon)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<initialDualValues>: fewer <con> elements than specified");
	}
    break;

  case 912:

    {	
	parserData->kounter++;
}
    break;

  case 913:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->lbValueAttributePresent = false;
	parserData->ubValueAttributePresent = false;
	parserData->lbDualValue = OSNaN();
	parserData->ubDualValue = OSNaN();
}
    break;

  case 914:

    {
	if (parserData->idxAttributePresent == false)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 917:

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

  case 918:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 919:

    {
		parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
	}
    break;

  case 920:

    {
		parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
	}
    break;

  case 925:

    {
	osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
}
    break;

  case 932:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 933:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 934:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 941:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 942:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 943:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 950:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 951:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 952:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 959:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 960:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 961:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 968:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 969:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 970:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 977:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 978:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 979:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 987:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 988:

    {
	if (parserData->iOther >= parserData->numberOfOtherConstraintOptions)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <otherConstraintOptions> than specified");
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

  case 989:

    {
		if(!parserData->nameAttributePresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element requires name attribute"); 
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

  case 992:

    {
		parserData->kounter = 0;
	}
    break;

  case 993:

    {
		parserData->kounter = 0;
	}
    break;

  case 1009:

    { 	
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

  case 1010:

    {
	if (parserData->kounter >= parserData->numberOfCon)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <con> elements than specified");
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

  case 1014:

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

  case 1025:

    {
	if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "setNumberOfSolverOptions failed");
	parserData->iOption = 0;
}
    break;

  case 1026:

    {
		if (parserData->numberOfSolverOptions > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <solverOption> element");
	}
    break;

  case 1027:

    {
		if (parserData->iOption != parserData->numberOfSolverOptions)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <solverOption> elements than specified");
	}
    break;

  case 1032:

    {
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

  case 1033:

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

  case 1034:

    {
	if (!parserData->nameAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "name attribute must be present");
}
    break;

  case 1043:

    {
			parserData->itemList = new std::string[parserData->numberOfItems];
    }
    break;

  case 1044:

    {	if (parserData->numberOfItems > 0)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "expected at least one <item> element");
	}
    break;

  case 1045:

    {	if (parserData->kounter != parserData->numberOfItems)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer <item> elements than specified");
	}
    break;

  case 1052:

    {	
	parserData->itemList[parserData->kounter] = parserData->itemContent;
	parserData->kounter++;
}
    break;

  case 1053:

    {
		if (parserData->kounter >= parserData->numberOfItems)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <item> elements than specified");
		parserData->itemContent = "";			
	}
    break;

  case 1058:

    {
	if (parserData->kounter >= parserData->numberOfItems)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); 
	free((yyvsp[(1) - (1)].sval));
}
    break;

  case 1059:

    {	
	if (!parserData->pathPairFromPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "\"to\" attribute must be present");
	parserData->kounter++;
}
    break;

  case 1060:

    {
	if (parserData->kounter >= parserData->numberOfPathPairs)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "too many path pairs");
	parserData->pathPairFromPresent = false;
	parserData->pathPairToPresent = false;
	parserData->pathPairMakeCopyPresent = false;
	parserData->pathPairMakeCopy = false;
}
    break;

  case 1061:

    {
	parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 1067:

    {
	if (parserData->pathPairFromPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"from\" attribute allowed");
	parserData->pathPairFromPresent = true;
	parserData->fromPaths[parserData->kounter] = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1068:

    {
	if (parserData->pathPairToPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"to\" attribute allowed");
	parserData->pathPairToPresent = true;
	parserData->toPaths[parserData->kounter] = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1069:

    {
	if (parserData->pathPairMakeCopyPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one \"makeCopy\" attribute allowed");
	parserData->pathPairMakeCopyPresent = true;
	parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1072:

    {   
	if (parserData->categoryAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one category attribute allowed for this element");
	parserData->categoryAttributePresent = true;
}
    break;

  case 1075:

    { 
	parserData->categoryAttribute = "";
}
    break;

  case 1076:

    { 
	parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1077:

    {
	if (parserData->descriptionAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one description attribute allowed for this element");
	parserData->descriptionAttributePresent = true;
}
    break;

  case 1080:

    { parserData->descriptionAttribute = ""; }
    break;

  case 1081:

    { 
	parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1082:

    {
	if (parserData->groupWeightAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one groupWeight attribute allowed for this element");
	parserData->groupWeightAttributePresent = true;
}
    break;

  case 1083:

    {
	parserData->groupWeight = parserData->tempVal;
}
    break;

  case 1084:

    {   
	if (parserData->idxAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one idx attribute allowed for this element");
	parserData->idxAttributePresent = true;
}
    break;

  case 1086:

    { 
	parserData->idxAttribute = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1087:

    {   
	if (parserData->lbValueAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
	parserData->lbValueAttributePresent = true;
}
    break;

  case 1090:

    { 
	parserData->lbValueAttribute = ""; 
}
    break;

  case 1091:

    { 
	parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1092:

    {   if (parserData->lbValueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one lb attribute allowed for this element");
			parserData->lbValueAttributePresent = true;
		}
    break;

  case 1095:

    { parserData->lbDualValue = 0.0; }
    break;

  case 1096:

    { parserData->lbDualValue = parserData->tempVal;}
    break;

  case 1097:

    {   if (parserData->nameAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		}
    break;

  case 1100:

    { parserData->nameAttribute = ""; }
    break;

  case 1101:

    { 
	parserData->nameAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1102:

    {   if (parserData->solverAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one solver attribute allowed for this element");
			parserData->solverAttributePresent = true;
		}
    break;

  case 1105:

    { parserData->solverAttribute = ""; }
    break;

  case 1106:

    { 
	parserData->solverAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1107:

    {   if (parserData->sosIdxAttributePresent ) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one sosIdx attribute allowed for this element");
		parserData->sosIdxAttributePresent = true;
	}
    break;

  case 1109:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "SOS index must be nonnegative");
	parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1110:

    {   if (parserData->typeAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		}
    break;

  case 1113:

    { parserData->typeAttribute = ""; }
    break;

  case 1114:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1115:

    {
   if (parserData->ubValueAttributePresent ) 
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
	parserData->ubValueAttributePresent = true;
}
    break;

  case 1118:

    { 
	parserData->ubValueAttribute = ""; 
}
    break;

  case 1119:

    { 
	parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1120:

    {   if (parserData->ubValueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one ub attribute allowed for this element");
			parserData->ubValueAttributePresent = true;
		}
    break;

  case 1123:

    { parserData->ubDualValue = 0.0; }
    break;

  case 1124:

    { 
	parserData->ubDualValue = parserData->tempVal;
}
    break;

  case 1125:

    {   if (parserData->unitAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		}
    break;

  case 1128:

    { parserData->unitAttribute = ""; }
    break;

  case 1129:

    { 
	parserData->unitAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1130:

    {   if (parserData->valueAttributePresent ) 
				osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		}
    break;

  case 1133:

    { parserData->valueAttribute = ""; }
    break;

  case 1134:

    {
	parserData->valueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1135:

    {
	if (parserData->numberOfConAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfConAttributePresent = true;		
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1136:

    {
	if (parserData->numberOfConstraintsPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of constraints cannot be negative");
	parserData->numberOfConstraintsPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1137:

    {
	if (osglData->osglNumberOfElPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEl attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <el> cannot be negative");
	osglData->osglNumberOfElPresent = true;
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1138:

    {
	if (parserData->numberOfEnumerationsAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfEnumerations attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerationsAttributePresent = true;		
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1139:

    {	
   if (parserData->numberOfItemsPresent ) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1140:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 1141:

    {
	if (parserData->numberOfObjAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObjAttributePresent = true;		
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1142:

    {	if (parserData->numberOfObjectivesPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of objectives cannot be negative");
	parserData->numberOfObjectivesPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1143:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other constraint options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1144:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other objective options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1145:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1146:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of other variable options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1147:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of path pairs cannot be negative");
	parserData->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->fromPaths = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->toPaths   = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->makeCopy  = new bool[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 1148:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of paths cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 1149:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 1150:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of solver options cannot be negative");
	parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1151:

    {
	if (parserData->numberOfVarAttributePresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVarAttributePresent = true;		
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1152:

    {	if (parserData->numberOfVariablesPresent)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "number of variables cannot be negative");
	parserData->numberOfVariablesPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1155:

    { 	
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

  case 1156:

    {
	if (parserData->kounter >= parserData->numberOfEnumerations)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more <enumeration> elements than specified");
	osglData->osglNumberOfElPresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 1157:

    {	if(!osglData->osglNumberOfElPresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires numberOfEl attribute"); 
		if(!parserData->valueAttributePresent) 
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "<other> element enumeration requires value attribute"); 
	}
    break;

  case 1160:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfElPresent = true;
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 1168:

    {
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
			osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "fewer data elements than specified");
	}
    break;

  case 1173:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
}
    break;

  case 1179:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
}
    break;

  case 1181:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1186:

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
	intvec = (int*)&base64decodeddata[0];
	for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
	{
		osglData->osglIntArray[i] = *(intvec++);
	}
	//delete[] b64string;
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1187:

    {	
	if (osglData->osglIncrPresent) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1188:

    {	
	if (osglData->osglMultPresent) 
        osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osol_errmsg += addErrorMsg( NULL, osoption, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1189:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1190:

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

	throw ErrorClass( error);
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


